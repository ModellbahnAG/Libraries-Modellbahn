#include <NeoPixel.h>

NeoPixel::NeoPixel(int numPixel, byte pin) {
  this->numPixel = numPixel;
  this->leds = new CRGB[numPixel];
  this->pin = pin;

  FastLED.addLeds<NEOPIXEL, pin>(this->leds, numPixel);
}

void NeoPixel::fill(CRGB color, int start, int end) {
  for (int i = start; i < end; i++) {
    this->leds[i] = color;
  }
  FastLED.show();
}

void NeoPixel::fill(int r, int g, int b, int start, int end) {
  for (int i = start; i < end; i++) {
    this->leds[i].setRGB(r, g, b);
  }
  FastLED.show();
}

void NeoPixel::setColor(int pixel, CRGB color) {
  this->leds[pixel] = color;
  FastLED.show();
}

void NeoPixel::setColor(int pixel, int r, int g, int b) {
  this->leds[pixel].setRGB(r, g, b);
  FastLED.show();
}

void NeoPixel::off() {
  this->fill(CRGB::BLACK);
}
