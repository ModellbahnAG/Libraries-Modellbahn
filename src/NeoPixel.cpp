#include <NeoPixel.h>

NeoPixel::NeoPixel(int numPixel, int pin) {
  this->numPixel = numPixel;
  this->leds = CRGBSet(new CRGB[numPixel], numPixel);
  this->pin = pin;

  switch (pin) {
    case 2: FastLED.addLeds<NEOPIXEL, 2>(this->leds, numPixel); break;
    case 3: FastLED.addLeds<NEOPIXEL, 3>(this->leds, numPixel); break;
    case 4: FastLED.addLeds<NEOPIXEL, 4>(this->leds, numPixel); break;
    case 5: FastLED.addLeds<NEOPIXEL, 5>(this->leds, numPixel); break;
    case 6: FastLED.addLeds<NEOPIXEL, 6>(this->leds, numPixel); break;
    case 7: FastLED.addLeds<NEOPIXEL, 7>(this->leds, numPixel); break;
    case 8: FastLED.addLeds<NEOPIXEL, 8>(this->leds, numPixel); break;
    case 9: FastLED.addLeds<NEOPIXEL, 9>(this->leds, numPixel); break;
    case 10: FastLED.addLeds<NEOPIXEL, 10>(this->leds, numPixel); break;
    case 11: FastLED.addLeds<NEOPIXEL, 11>(this->leds, numPixel); break;
    case 12: FastLED.addLeds<NEOPIXEL, 12>(this->leds, numPixel); break;
    case 13: FastLED.addLeds<NEOPIXEL, 13>(this->leds, numPixel); break;
  }
}

void NeoPixel::fill(CRGB color, int start, int end) {
  if (end < 0 || end > this->numPixel) { end = this->numPixel; }
  for (int i = start; i < end; i++) {
    this->leds[i] = color;
  }
  FastLED.show();
}

void NeoPixel::fill(int r, int g, int b, int start, int end) {
  if (end < 0 || end > this->numPixel) { end = this->numPixel; }
  for (int i = start; i < end; i++) {
    this->leds[i].setRGB(r, g, b);
  }
  FastLED.show();
}

void NeoPixel::setColor(CRGB color, int pixel) {
  this->leds[pixel] = color;
  FastLED.show();
}

void NeoPixel::setColor(int r, int g, int b, int pixel) {
  this->leds[pixel].setRGB(r, g, b);
  FastLED.show();
}

void NeoPixel::off() {
  this->fill(CRGB::Black);
}

int NeoPixel::getNumberOfPixel() {
  return this->numPixel;
}
