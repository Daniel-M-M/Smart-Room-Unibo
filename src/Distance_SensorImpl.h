#include "Distance_Sensor.h"

class UltrasonicSensor: public DistanceSensor {
    public:
        UltrasonicSensor(int triggerPin, int echoPin);
        float getDistance();

    private:
        int triggerPin;
        int echoPin;

};