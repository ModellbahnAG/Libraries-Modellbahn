/**
* @file ButtonExample.cpp
* @author Dennis Moschina
* @date 29 Dec 2020
* @copyright 2020 Dennis Moschina
* @brief Dieses Beispiel zeigt wie die Button Klasse verwendet wird. Hier wird
* die LED an Pin 13 für eine Sekunde eingeschaltet sobald der Button gedrückt
* wurde. Danach kann das Licht für 60 Sekunden nicht mehr eingeschaltet werden.
* @example ButtonExample.cpp
*/

#include <Arduino.h>
#include "Modellbahn.h"

#define BUTTON_PIN 9        // Pin an den der Button angeschlossen ist
#define BUTTON_LIGHT_PIN 10 // Pin an den das Licht des Buttons angeschlossen ist

int led = 13;   // Pin der LED in unserem Beispiel

// Es wird ein neuer Button erzeugt
Button myButton = Button(BUTTON_PIN, BUTTON_LIGHT_PIN, 60);

void setup() {
  pinMode(led, OUTPUT);

  // [setCallback]
  /*
   * Sobald der Button gedrückt wird, wird der hier angegebene Code ausgeführt.
   */
  myButton.setCallback(CallLambda([] () {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    return 0;
  }));
  // [setCallback]
}

void loop() {
  /*
   * Der Button überprüft, ob er gedrückt wurde und er wieder aktiviert werden
   * kann falls er deaktiviert war.
   */
  myButton.handleButton();
}
