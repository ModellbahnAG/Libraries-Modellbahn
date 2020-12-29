/**
* @file LightEffects.cpp
* @author Dennis Moschina
* @date 28 Dec 2020
* @copyright 2020 Dennis Moschina
* @brief Eine Sammlung von Lichteffekten, die immer mal wieder gebraucht werden
* können.
*/

#include "LightEffects.h"

void LightEffects::flash(NeoPixel* led) {
  unsigned long startTime = millis();

  while(millis() < startTime + 1000) {
    int pixel = random(0, led->getNumberOfPixels());

    led->setColor(255,200,255, pixel);

    int delayTime = random(10, 100);
    Serial.println(delayTime);
    delay(delayTime);

    led->off();
  }
}

void LightEffects::torch(NeoPixel *led) {
  led->fill(255, 50, 0);
  int pixel = random(0, led->getNumberOfPixels());
  led->setBrightness(100, pixel);
  delay(random(10, 100));
  led->setBrightness(255, pixel);
}
