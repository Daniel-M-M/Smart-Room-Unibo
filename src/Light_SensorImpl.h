#include "Light_Sensor.h"

class LightSensorImpl : public Light_Sensor {
    public:
        LightSensorImpl(int pin);
        int getLightIntensity();

    private:
        int pin;
        double analogValueToLux(int value);
};
