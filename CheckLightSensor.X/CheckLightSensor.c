#include "roach.h"
#include "CheckLightSensor.h"

char CheckLightSensor(void) {
    if (Roach_LightLevel() > 512)
    {
        return 0;
        //dark
    }
    else
    {
        return 1; 
        //light
    }
}