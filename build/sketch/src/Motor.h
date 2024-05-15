#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\Motor.h"
#ifndef __MOTOR__
#define __MOTOR__

#include "MyServo.h"
#include "ServoTimer2.h"

class Motor : public MyServo {
    public:
        Motor(int pin);
        void setAngle(int newPos);
        void forward();
        void backward();
        int getAngle();

    private:
        int pin;
        int pos;
        ServoTimer2 servo;
        int mapPos(int pos);
};

#endif
