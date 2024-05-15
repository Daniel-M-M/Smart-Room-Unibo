#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\Distance_Sensor.h"
#ifndef __DISTANCE_SENSOR__
#define __DISTANCE_SENSOR__

class DistanceSensor {
    public:
        virtual float getDistance() = 0;
};

#endif