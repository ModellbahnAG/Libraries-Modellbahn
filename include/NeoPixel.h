#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include <Arduino.h>
#include <FastLED.h>

class NeoPixel {
  public:
    NeoPixel(int numPixel, byte pin);

    void fill(CRGB color, int start = 0, int end = numPixel - 1);
    void fill(int r, int g, int b, int start = 0, int end = numPixel - 1);

    void setColor(int pixel, CRGB color);
    void setColor(int pixel, int r, int g, int b);

    void off();

  private:
    const byte pin;
    const int numPixel;
    CRGB leds[];
};

#endif
