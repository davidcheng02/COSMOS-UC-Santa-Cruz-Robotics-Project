/* 
 * File:   LightsMain.c
 * Author: COSMOS
 *
 * Created on July 17, 2018, 10:12 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "serial.h"
#include "BOARD.h"
#include "roach.h"
#include "timers.h"

#define TIMER_A 0

/*
 * 
 */
int main(void) {
    
    SERIAL_Init();
    BOARD_Init();
    Roach_Init();
    TIMERS_Init();

    /*while (1)
    {
        Roach_LEDSSet(0b000000000001);
        TIMERS_InitTimer(0,1000);
        while(TIMERS_IsTimerActive(0));
        Roach_LEDSSet(0b100000000000);
        TIMERS_InitTimer(0,1000);
        while(TIMERS_IsTimerActive(0));

    }*/
    
    int LightLevel;
    
    
    while(1){
        //read, display light level:
        LightLevel = Roach_LightLevel();
        
        if (LightLevel >= 370 && LightLevel < 425)
        {
            Roach_LEDSSet(0b111111111111);
        }
        else if (LightLevel >= 425 && LightLevel < 480)
        {
            Roach_LEDSSet(0b111111111110);
        }
        else if (LightLevel >= 480 && LightLevel < 535)
        {
            Roach_LEDSSet(0b111111111100);
        }
        else if (LightLevel >= 535 && LightLevel < 590)
        {
            Roach_LEDSSet(0b111111111000);
        }
        else if (LightLevel >= 590 && LightLevel < 645)
        {
            Roach_LEDSSet(0b111111110000);
        }
        else if (LightLevel >= 645 && LightLevel < 700)
        {
            Roach_LEDSSet(0b111111100000);
        }
        else if (LightLevel >= 700 && LightLevel < 755)
        {
            Roach_LEDSSet(0b111111000000);
        }
        else if (LightLevel >= 755 && LightLevel < 810)
        {
            Roach_LEDSSet(0b111110000000);
        }
        else if (LightLevel >= 810 && LightLevel < 865)
        {
            Roach_LEDSSet(0b111100000000);
        }
        else if (LightLevel >= 865 && LightLevel < 920)
        {
            Roach_LEDSSet(0b111000000000);
        }
        else if (LightLevel >= 920 && LightLevel < 975)
        {
            Roach_LEDSSet(0b110000000000);
        }
        else if (LightLevel >= 975 && LightLevel < 1000)
        {
            Roach_LEDSSet(0b100000000000);
        }
        else if (LightLevel >= 1000 && LightLevel <= 1023)
        {
            Roach_LEDSSet(0b000000000000);
        }
        
        
        printf("Light Level = %d\n",LightLevel);

        //wait 0.1 second:
        TIMERS_InitTimer(0,100);
        while(TIMERS_IsTimerActive(0));
    }
    
    
    return (EXIT_SUCCESS);
    
}

