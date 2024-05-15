#ifndef __LIGHT_SENSOR__
#define __LIGHT_SENSOR__

class Light_Sensor {
    public:
        virtual int getLightIntensity() = 0;
};

#endif