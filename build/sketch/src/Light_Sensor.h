#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\Light_Sensor.h"
#ifndef __LIGHT_SENSOR__
#define __LIGHT_SENSOR__

class Light_Sensor {
    public:
        virtual int getLightIntensity() = 0;
};

#endif