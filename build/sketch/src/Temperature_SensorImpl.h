#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\Temperature_SensorImpl.h"
#include "Temperature_Sensor.h"

class TemperatureSensorImpl : public TemperatureSensor {
    public:
        TemperatureSensorImpl(int pin);
        float getTemperature();

    private:
        int pin;
};