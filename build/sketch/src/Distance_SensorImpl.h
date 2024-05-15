#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\Distance_SensorImpl.h"
#include "Distance_Sensor.h"

class UltrasonicSensor: public DistanceSensor {
    public:
        UltrasonicSensor(int triggerPin, int echoPin);
        float getDistance();

    private:
        int triggerPin;
        int echoPin;

};