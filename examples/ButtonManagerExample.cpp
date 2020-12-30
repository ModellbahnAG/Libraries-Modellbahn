/**
* @file ButtonManagerExample.cpp
* @author Dennis Moschina
* @date 29 Dec 2020
* @copyright 2020 Dennis Moschina
* @brief Dieses Beispiel verwendet einen Button der die LED einschält und einen,
* der die LED wieder ausschält
* @example ButtonManagerExample.cpp
*/

#include <Arduino.h>
#include "Modellbahn.h"

#define ON_BUTTON_PIN 9        // Pin an den der Button angeschlossen ist
#define ON_BUTTON_LIGHT_PIN 10 // Pin an den das Licht des Buttons angeschlossen ist
#define OFF_BUTTON_PIN 11
#define OFF_BUTTON_LIGHT_PIN 12

int led = 13;   // Pin der LED in unserem Beispiel

// Es werden neue Buttons erzeugt
Button onButton = Button(ON_BUTTON_PIN, ON_BUTTON_LIGHT_PIN, 0);
Button offButton = Button(OFF_BUTTON_PIN, OFF_BUTTON_LIGHT_PIN, 0);


void setup() {
  pinMode(led, OUTPUT);

  /*
   * Sobald der Button gedrückt wird, wird der hier angegebene Code ausgeführt.
   */
  onButton.setCallback(CallLambda([] () {
    digitalWrite(led, HIGH);
    return 0;
  }));
  offButton.setCallback(CallLambda([] () {
    digitalWrite(led, LOW);
    return 0;
  }));
}

void loop() {
  /*
   * Der ButtonManager überprüft, ob ein deaktivierter Button wieder aktiviert
   * werden kann.
   */
  ButtonManager::handleButtons();
}
