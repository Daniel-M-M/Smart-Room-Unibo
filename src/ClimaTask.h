#ifndef __CLIMATASK__
#define __CLIMATASK__

#include "Task.h"
#include "Temperature_Sensor.h"
#include "Light.h"

class ClimaTask : public Task {
    public:
        ClimaTask(TemperatureSensor *tempSensor, Light *hotLed, Light *coldLed);
        void init(int period);
        void tick();
    
    private:
        TemperatureSensor *tempSensor;
        Light *hotLed;
        Light *coldLed;
        enum { HOT, HALFHOT, IDLE, HALFCOLD, COLD } state;

        void hot();
        void halfHot();
        void idle();
        void halfCold();
        void cold();

};

#endif