#include <stdio.h>
#include <stdlib.h>
#include "Bumpers.h"
#include "roach.h"
#include "timers.h"

int CheckForBumps(void) {
    static int prevBump;
    static int bumps;
    int returnBumps = 0;
    
    if (TIMERS_IsTimerExpired(TIMER_A)) {
        TIMERS_InitTimer(TIMER_A, 10);
        
        bumps = bumps << 4;
        bumps = bumps | Roach_ReadBumpers();
        //01 = RELEASED -> PRESSED
        //10 = PRESSED -> RELEASED
        //8 bit order from least significant to most: FL, FR, RL, RR
        //front left
        if (((bumps & 0x111) == 0x111) && ((prevBump & 0x1) == 0))  {
            //printf("Front left bumper pressed\r\n");
            returnBumps |= 0b100000001;          
        }//RELEASED -> PRESSED
        else if(((bumps & 0x111) == 0x0) && ((prevBump & 0x1) == 1)) {
            //printf("Front left bumper released\r\n");
            returnBumps |= 0b100000010;
        }//PRESSED -> RELEASED
        
         //front right
        if (((bumps & 0x222) == 0x222) && ((prevBump & 0x2) == 0))  {
            //printf("Front right bumper pressed\r\n");
            returnBumps |= 0b100000100;
        }//RELEASED -> PRESSED
        else if(((bumps & 0x222) == 0x0) && ((prevBump & 0x2) == 2)) {
            //printf("Front right bumper released\r\n");
            returnBumps |= 0b100001000;
        }//PRESSED -> RELEASED
        
         //rear left
        if (((bumps & 0x444) == 0x444) && ((prevBump & 0x4) == 0))  {
            //printf("Rear left bumper pressed\r\n");
            returnBumps |= 0b100010000;
        }//RELEASED -> PRESSED
        else if(((bumps & 0x444) == 0x0) && ((prevBump & 0x4) == 4)) {
            //printf("Rear left bumper released\r\n");
            returnBumps |= 0b100100000;
        }//PRESSED -> RELEASED
        
         //rear right
        if (((bumps & 0x888) == 0x888) && ((prevBump & 0x8) == 0))  {
            //printf("Rear right bumper pressed\r\n");
            returnBumps |= 0b101000000;
        }//RELEASED -> PRESSED
        else if(((bumps & 0x888) == 0x0) && ((prevBump & 0x8) == 8)) {
            //printf("Rear right bumper released\r\n");
            returnBumps |= 0b110000000;
        }//PRESSED -> RELEASED
        
        prevBump = bumps >> 8;
    }
    return returnBumps;
}