#include <NeoPixel.h>

NeoPixel::NeoPixel(int numPixel, byte pin) {
  this->numPixel = numPixel;
  this->leds = new CRGB[numPixel];
  this->pin = pin;
}

void NeoPixel::setStripColor(CRGB color) {
  for (int i = 0; i < this->numPixel; i++) {
    this->leds[i] = color;
  }
}
