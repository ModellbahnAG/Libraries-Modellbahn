/**
* @file NeoPixelExample.cpp
* @author Emilie Moschina
* @date 31 Dec 2020
* @copyright 2020 Emilie Moschina
* @brief Dieses Beispiel setzt zuerst alle LEDs auf grün und ändert direkt ihre
* Helligkeit auf eine niedrige Helligkeit. Nach einer Sekunde werden alle LEDs
* für eine halbe Sekunde ausgeschaltet. Dann wird die erste LED für eine Sekunde
* rot mit voller Helligkeit und das Programm startet vonn vorne.
* @example NeoPixelExample.cpp
*/

#include <Arduino.h>

#include "Modellbahn.h"

#define NUM_PIXEL 12
#define LED_PIN 8

NeoPixel pixels = NeoPixel(NUM_PIXEL, LED_PIN);

void setup() {}

void loop() {
  pixels.fill(0,255,0);         //alle Pixel werden mit voller Helligkeit auf grün gesetzt
  pixels.setBrightness(50);     //die Helligkeit der Pixel wird von 255 auf 50 gesetzt
  delay(1000);                  //der Arduino wartet 1000 Millisekunden
  pixels.off();                 //alle Pixel werden ausgeschalten

  delay(500);

  pixels.setColor(255,0,0,0);   //der Pixel Nummer null wird mit voller Helligkeit auf rot gesetzt
  delay(1000);                  //der Arduino wartet 1000 Millisekunden
}
