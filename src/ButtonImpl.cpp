#include "ButtonImpl.h"
#include "Arduino.h"

ButtonImpl::ButtonImpl(int buttonPin) {
    this->buttonPin = buttonPin;
    pinMode(buttonPin, INPUT);
}

bool ButtonImpl::isPressed() {
    return digitalRead(buttonPin) == HIGH;
}

