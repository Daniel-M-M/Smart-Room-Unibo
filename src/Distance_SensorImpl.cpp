#include "Arduino.h"
#include "Distance_SensorImpl.h"

long duration;
float distance;

UltrasonicSensor::UltrasonicSensor(int triggerPin, int echoPin){
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float UltrasonicSensor::getDistance(){
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2; // Calcola la distanza in base al tempo trascorso
    return distance;
};