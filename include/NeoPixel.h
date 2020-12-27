#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include <Arduino.h>
#include <FastLED.h>

class NeoPixel {
  public:
    NeoPixel(int numPixel, byte pin);

    void setStripColor(CRGB color);

  private:
    byte pin;

    int numPixel;
    CRGB leds[];
};

#endif
