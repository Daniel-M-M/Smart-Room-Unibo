#ifndef __LIGHTTASK__
#define __LIGHTTASK__

#include "Task.h"
#include "Light_Sensor.h"
#include "Light.h"
#include "Button.h"

class LightTask : public Task {
    public:
        LightTask(Light_Sensor *lightSensor, Light *lightLed, Button *btn);
        void init(int period);
        void tick();
    
    private:
        Light_Sensor *lightSensor;
        Light *lightLed;
        Button *btn;
        enum { NIGHT, DAY, TURNED_ON, TURNED_OFF } state;
        int on_off;
        int count;

        void night();
        void day();
        void turnedOn();
        void turnedOff();

};

#endif