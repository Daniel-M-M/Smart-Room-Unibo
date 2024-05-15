#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\Led.h"
#ifndef __LED__
#define __LED__

#include "Light.h"

class Led : public Light {
    public:
        Led(int pin);
        void switchOn();
        void switchOff();
        void halfBrightness();

        private:
        int pin;
};

#endif