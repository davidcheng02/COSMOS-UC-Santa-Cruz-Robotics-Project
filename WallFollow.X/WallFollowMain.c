/* 
 * File:   WallFollowMain.c
 * Author: COSMOS
 *
 * Created on August 1, 2018, 9:35 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "serial.h"
#include "timers.h"
#include "BOARD.h"
#include "roach.h"
#include "ArcBumpReaction.h"

#define SPEED 100

/*
 * 
 */
int main(void) {
    BOARD_Init();
    Roach_Init();
    TIMERS_Init();

    Forward(SPEED);

    TIMERS_InitTimer(0, 1);
    static int prevBump = 0;
    //printf("%d", Roach_BatteryVoltage());

    while (1) {
        if (TIMERS_IsTimerExpired(0)) { //When roach is in corner
            if (Roach_ReadBumpers() == 3) {
                //                if (prevBump == 1) {
                //                RotateRight(100);
                //                prevBump = 1;
                //                }      
                //else if (prevBump == 2) {
                RotateLeft(100);
                //prevBump = 2;
                //}
                TIMERS_InitTimer(0, 500);
            }
        }
        if (Roach_ReadBumpers() == 1 || Roach_ReadBumpers() == 2) {
            prevBump = Roach_ReadBumpers();
            Forward(SPEED);
        }

        if (Roach_ReadBumpers() == 4 || Roach_ReadBumpers() == 8 || Roach_ReadBumpers() == 0XC) {
            prevBump = Roach_ReadBumpers();
            Forward(SPEED);
        }

        if (TIMERS_IsTimerExpired(0)) { //when there's no walls (roach does u-turn)
            if (Roach_ReadBumpers() == 0) {
                if (prevBump != 0) {
                //                    if (prevBump == 1) {                  
                //                        ArcLeft(50);
                //                        prevBump == Roach_ReadBumpers();
                //                    }
                //                    else if (prevBump == 2) {               
                    PivotRight(100);
                //                        prevBump == Roach_ReadBumpers();
                    TIMERS_InitTimer(0, 500);
                }  
                    
            }
        }
        
        if (Roach_LightLevel() >= 800) {
            Stop();
        }   
    }
    return (EXIT_SUCCESS);
}

