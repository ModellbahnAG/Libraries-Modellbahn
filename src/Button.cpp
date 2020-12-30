#include <Button.h>



Button::Button(byte inputPin, byte lightPin, unsigned long delayTime) {
  this->inputPin = inputPin;
  this->lightPin = lightPin;
  this->delayTime = delayTime;

  init();
}

void Button::init() {
  pinMode(this->inputPin, INPUT_PULLUP);
  pinMode(this->lightPin, OUTPUT);

  digitalWrite(this->lightPin, HIGH);
}

int Button::buttonPressed() {
  if (this->activated) {
    this->lastPress = millis();

    this->activated = false;
    digitalWrite(lightPin, LOW);

    return this->callback.invoke();
  }
}

void Button::checkForTime() {
  if (millis() >= this->lastPress + (this->delayTime * 1000)) {
    this->activated = true;
    digitalWrite(this->lightPin, HIGH);
  }
}

void Button::handleButton() {
  checkForTime();
  if (!digitalRead(this->inputPin)) {
    buttonPressed();
  }
}
