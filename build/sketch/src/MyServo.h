#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\MyServo.h"
#ifndef __MYSERVO__
#define __MYSERVO__

class MyServo {
    public:
        virtual void setAngle(int newPos) = 0;
        virtual void forward() = 0;
        virtual void backward() = 0;
        virtual int getAngle() = 0;
};
#endif
