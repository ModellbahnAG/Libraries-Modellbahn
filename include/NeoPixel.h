#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include <Arduino.h>
#include <FastLED.h>

class NeoPixel {
  public:
    NeoPixel(int numPixel, int pin);

    void fill(CRGB color, int start = 0, int end = -1);
    void fill(int r, int g, int b, int start = 0, int end = -1);

    void setColor(int pixel, CRGB color);
    void setColor(int pixel, int r, int g, int b);

    void off();

  private:
    int pin;
    int numPixel;
    CRGBSet leds = CRGBSet(new CRGB[0], 0);
};

#endif
