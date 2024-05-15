#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\DoorTask.h"
#ifndef __DOORTASK__
#define __DOORTASK__

//vediamo come aggiungere in servo non si puo cosi
#include "MyServo.h"
#include "Task.h"
#include "Distance_Sensor.h"

class DoorTask : public Task {
    public:
        DoorTask(DistanceSensor *doorSensor, MyServo *servo);
        void init(int period);
        void tick();
    
    private:
        DistanceSensor *doorSensor;
        MyServo *servo;
        enum { OPEN, OPENING, OPENED, CLOSE } state;
        int count;

        void open();
        void opening();
        void opened();
        void close();

};

#endif