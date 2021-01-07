/**
* @file LightEffects.cpp
* @author Dennis Moschina
* @date 28 Dec 2020
* @copyright 2020 Dennis Moschina
* @brief Eine Sammlung von Lichteffekten, die immer mal wieder gebraucht werden
* können.
*/

#include "LightEffects.h"

void LightEffects::flash(NeoPixel* led, int duration) {
  unsigned long startTime = millis();

  while(millis() < startTime + (duration * 1000)) {
    int pixel = random(0, led->getNumberOfPixels());

    led->setColor(255,200,255, pixel);

    int delayTime = random(10, 100);
    delay(delayTime);

    led->off();
  }
}

void LightEffects::torch(NeoPixel *led, int duration) {
  unsigned long startTime = millis();

  while(millis() < startTime + (duration * 1000)) {
    led->fill(255, 50, 0);
    int pixel = random(0, led->getNumberOfPixels());
    led->setBrightness(100, pixel);
    delay(random(10, 100));
    led->setBrightness(255, pixel);
  }
  led->off();
}
