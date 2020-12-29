/**
* @file Button.h
* @author Dennis Moschina, Aaron Sami Abassi
* @date 28 Dec 2020
* @copyright 2020 Dennis Moschina, © 2020 Aaron Sami Abassi
* @brief Erstelle einen Button, der für eine bestimmte Zeit nachdem er gedrückt
* wurde deaktiviert wird
*/

#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"
#include <Wire.h>


/*
 * This portion is derived from:
 * https://github.com/ASA1976/RAP-BTL/blob/master/rap-btl/invocation.hpp#L1
 *
 * © 2020 Aaron Sami Abassi
 * Licensed under the Academic Free License version 3.0
 */
template <typename Resultant, typename... Parametric>
struct Invocative {
	using Interfacial = Resultant(const void* const, Parametric...);
	Interfacial* interface;
	const void* locality;
	Resultant operator()(Parametric... arguments) const {
		return interface(locality, arguments...);
	}
};
template <typename Procedural, typename Resultant, typename... Parametric>
Resultant
InvokeProcedure(const void* locality, Parametric... arguments) {
	using Classificatory = Procedural* const*;
	const Classificatory objective = static_cast<Classificatory>(locality);
	return (**objective)(arguments...);
}
template <typename Procedural, typename Resultant, typename... Parametric>
static inline Invocative<Resultant, Parametric...>
AssignInvokeProcedure(Procedural* const& locality) {
	using Specific = Invocative<Resultant, Parametric...>;
	static auto& Invoke = InvokeProcedure<Procedural, Resultant, Parametric...>;
	const Specific invocation = { &Invoke, &locality };
	return invocation;
}
/*
 * Only the above source code is subject to copyright notice as a derived work.
 * It can be further modified but the copyright notice must remain.
 * This derivative only contains portions relating to invoking lambdas.
 */
// -----------------------------------------------------------------------------
/*
 * SUPPORT CODE FOR THE LIBRARY AUTHOR (should only need to modify the macro)
 */
#define CALLBACK_TYPE_LIST int
/*
 * Format for CALLBACK_TYPE_LIST (must contain at least a return type):
 *
 * RETURN_TYPE, ARGUMENT1_TYPE, ARGUMENT2_TYPE, ...
 */

struct lambda_callback_t {
	using invoke_t = Invocative<CALLBACK_TYPE_LIST>;
	using remover_t = void(void*);
	invoke_t invoke;
	void* lambda;
	remover_t* remove;
	lambda_callback_t() {
		invoke.interface = 0;
		invoke.locality = 0;
		lambda = 0;
		remove = 0;
	}
	lambda_callback_t(const lambda_callback_t& copy) {
		invoke.interface = copy.invoke.interface;
		invoke.locality = &lambda;
		lambda = copy.lambda;
		remove = copy.remove;
	}
	void replace(const lambda_callback_t& with)	{
		if (lambda)
			remove(lambda);
		invoke.interface = with.invoke.interface;
		invoke.locality = &lambda;
		lambda = with.lambda;
		remove = with.remove;
	}
	void cleanup() {
    if (lambda)
  			remove(lambda);
  		invoke.interface = 0;
  		invoke.locality = 0;
  		lambda = 0;
  		remove = 0;
  	}
  };
  template <typename LambdaTypical>
  static inline lambda_callback_t
  CallLambda(const LambdaTypical& lambda) {
  	static auto RemoveLambda = [](void* pointer) {
  		delete static_cast<LambdaTypical*>(pointer);
  	};
  	static auto& Assign = AssignInvokeProcedure<LambdaTypical, CALLBACK_TYPE_LIST>;
  	lambda_callback_t callback;
  	callback.lambda = new LambdaTypical(lambda);
  	callback.invoke = Assign(*reinterpret_cast<LambdaTypical**>(&callback.lambda));
  	callback.remove = RemoveLambda;
  	return callback; // Not intended for direct invocation, copying only
  }
  // CALLBACK_TYPE_LIST is no longer needed
  #undef CALLBACK_TYPE_LIST
//
// ALL OF THE ABOVE MUST BE INCLUDED IN LIBRARY USER HEADERS
//
// -----------------------------------------------------------------------------



/**
* @class Button
* @brief Erstelle einen Button, der für eine bestimmte Zeit nachdem er
* gedrückt wurde deaktiviert wird. Während der Button deaktiviert ist, ist sein
* Licht ausgeschaltet und er reagiert nicht wenn er nochmals gedrückt wird.

* @details Alle Instanzen müssen vor oder im setup erzeugt werden. In der loop
* muss handleButton() ausgeführt werden. Bei der Verwendung von mehreren Buttons
* wird die verwendung von ButtonManager empfohlen.
*/
class Button {
  public:
		/**
		* @brief Erstelle eine Instanz der Klasse Button
		*
		* @param inputPin Pin, an den der Button angeschlossen ist
		* @param lightPin Pin, an den das Licht des Buttons angeschlossen ist
		* @param delayTime Zeit in Sekunden, die der Button nachdem er gedrückt
		* wurde deaktiviert ist. Während dieser Zeit wird auch das Licht des Buttons
		* deaktiviert. Der Standardwert ist 60
		*
		* @return Referenz zur Instanz von Button
		*/
    Button(byte inputPin, byte lightPin, int delayTime = 60);
    ~Button() {
      callback.cleanup();
    }

		/**
		* @brief Definiere eine Funktion, die ausgeführt wird, sobald der Button
		* gedrückt wurde
		* @param action Lampdafunktion die ausgeführt wird, sobald der Button gedrückt wurde
		*/
		void setCallback(const lambda_callback_t& action) {
      this->callback.replace(action);
    }

		/**
		* @brief Überprüfe, ob der Button gedrückt wurde oder ob er wieder aktiviert
		* werden kann. Diese Methode muss in der loop() aufgerufen werden
		* @details Wurde ein aktiver Button gedrückt, wird die durch setCallback
		* festgelegte Funktion ausgeführt.
		*/
    void handleButton();

	private:
		byte inputPin;    // Pin des Buttons
		byte lightPin;    // Pin des Lichts
		int delayTime;    // Zeit, die der Button deaktiviert ist (in Sekunden)

		unsigned long lastPress = 0;   // Zeit, zu der der Button zum letzten Mal gedrückt wurde
		bool activated = true;

		lambda_callback_t callback;

		void init();

		int buttonPressed();
		void checkForTime();
};

#endif
