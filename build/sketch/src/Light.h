#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\Light.h"
#ifndef __LIGHT__
#define __LIGHT__

class Light {
    public:
        virtual void switchOn() = 0;
        virtual void switchOff() = 0;
        virtual void halfBrightness() = 0;
};

#endif