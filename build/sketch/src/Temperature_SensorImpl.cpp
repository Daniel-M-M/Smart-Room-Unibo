#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\Temperature_SensorImpl.cpp"
#include "Arduino.h"
#include "Temperature_SensorImpl.h"


// should match the Beta Coefficient of the thermistor
const float BETA = 3950;

TemperatureSensorImpl::TemperatureSensorImpl(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

float TemperatureSensorImpl::getTemperature() {
    int value = analogRead(this->pin);
    float celsius = 1 / (log(1 / (1023. / value - 1)) / BETA + 1.0 / 298.15) - 273.15;
    return celsius;
}