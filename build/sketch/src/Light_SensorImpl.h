#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\Light_SensorImpl.h"
#include "Light_Sensor.h"

class LightSensorImpl : public Light_Sensor {
    public:
        LightSensorImpl(int pin);
        int getLightIntensity();

    private:
        int pin;
        double analogValueToLux(int value);
};
