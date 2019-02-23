#ifndef CHECKLIGHTSENSOR_H //if CheckLightSensor.h is not defined
#define CHECKLIGHTSENSOR_H //then define CheckLightSensor.h

/**
* @Function CheckLightSensor(void)
* @param none
* @return 0 if roach is in the darkness, 1 if the roach is in the light.
* @brief This function reads the light level and updates the LED bar on the
* roach to show a bar graph of this reading. It also returns a 0 or 1 to
* indicate whether the roach is in light or shadow.
* @author YOUR NAMES */
char CheckLightSensor(void);

#endif