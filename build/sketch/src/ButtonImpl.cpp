#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\ButtonImpl.cpp"
#include "ButtonImpl.h"
#include "Arduino.h"

ButtonImpl::ButtonImpl(int buttonPin) {
    this->buttonPin = buttonPin;
    pinMode(buttonPin, INPUT);
}

bool ButtonImpl::isPressed() {
    return digitalRead(buttonPin) == HIGH;
}

