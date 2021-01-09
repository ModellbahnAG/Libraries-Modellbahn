#include <NeoPixel.h>
#include <LightEffects.h>

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
  this->leds(start, end) = color;
  FastLED.show();
}

void NeoPixel::fill(int r, int g, int b, int start, int end) {
  if (end < 0 || end > this->numPixel) { end = this->numPixel; }
  this->leds(start, end) = CRGB(r, g, b);
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

void NeoPixel::setBrightness(int brightness, int pixel) {
  // brightness in das erlaubte Intervall [0, 255] bringen
  brightness = min(brightness, 255);
  brightness = max(brightness, 0);

  if (pixel < 0) {
    FastLED.setBrightness(255);
    this->leds(0, this->numPixel).nscale8(brightness);
  } else {
    this->leds[pixel].maximizeBrightness();
    this->leds[pixel].nscale8(brightness);
  }
  FastLED.show();
}

void NeoPixel::off() {
  this->fill(CRGB::Black);
}

int NeoPixel::getNumberOfPixels() {
  return this->numPixel;
}

void NeoPixel::flash(int duration) {
  LightEffects::flash(this, duration);
}

void NeoPixel::torch(int duration) {
  LightEffects::torch(this, duration);
}

void NeoPixel::fire(int duration) {
  LightEffects::fire(this, duration);
}
