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

  pixels.setColor(255,0,0,0);   //der Pixel Nummer null wird mit voller Helligkeit auf rot gesetzt
  delay(1000);                  //der Arduino wartet 1000 Millisekunden
}
