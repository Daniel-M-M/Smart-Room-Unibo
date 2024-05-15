#include "Temperature_Sensor.h"

class TemperatureSensorImpl : public TemperatureSensor {
    public:
        TemperatureSensorImpl(int pin);
        float getTemperature();

    private:
        int pin;
};