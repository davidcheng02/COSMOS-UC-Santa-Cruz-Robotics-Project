/* 
 * File:   BumpersMain.c
 * Author: COSMOS
 *
 * Created on July 17, 2018, 10:54 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "serial.h"
#include "BOARD.h"
#include "roach.h"
#include "timers.h"

#define BUMPER_TRIPPED 1
#define BUMPER_NOT_TRIPPED 0
#define TIMER_A 0
#define TIMER_B 1
#define TIMER_C 2
#define TIMER_D 3

/*
 * 
 */
int main(void) {

    SERIAL_Init();
    BOARD_Init();
    Roach_Init();
    TIMERS_Init();
    
    char array[3];
    char count = 0;

    TIMERS_InitTimer(TIMER_A, 10);
    TIMERS_InitTimer(TIMER_B, 10);
    TIMERS_InitTimer(TIMER_C, 10);
    TIMERS_InitTimer(TIMER_D, 10);
    while (1) {
        int i;
        if (TIMERS_IsTimerExpired(TIMER_A)) {
            TIMERS_InitTimer(TIMER_A, 10);
            array[count] = Roach_ReadFrontRightBumper();
            count++;
            count %= 3;

            if (array[1] && array[2] && array[3]) {
                printf("Front right bumper is down!\r\n");
                for (i = 0; i < 3; i++) {
                    array[i] = 0;
                }
            }
        }
    }
}
/*  char frontRightBumpCounter = 0;

   char lastFrontRightBump = BUMPER_NOT_TRIPPED;
   char thisFrontRightBump;
   char lastLastFrontRightBump;

   char lastFrontLeftBump;
   char thisFrontLeftBump;
   char lastLastFrontLeftBump;

   char lastRearLeftBump;
   char thisRearLeftBump;
   char lastLastRearLeftBump;

   char lastRearRightBump;
   char thisRearRightBump;
   char lastLastRearRightBump;


   //    TIMERS_InitTimer(TIMER_A, 10);
   TIMERS_InitTimer(TIMER_B, 10);
   TIMERS_InitTimer(TIMER_C, 10);
   TIMERS_InitTimer(TIMER_D, 10);

   lastLastRearRightBump = lastRearRightBump;
   lastRearRightBump = thisRearRightBump;
   lastLastRearLeftBump = lastRearLeftBump;
   lastRearLeftBump = thisRearLeftBump;
   lastLastFrontLeftBump = lastFrontLeftBump;
   lastFrontLeftBump = thisFrontLeftBump;
   lastLastFrontRightBump = lastFrontRightBump;
   lastFrontRightBump = thisFrontRightBump;

   char thisBump;
   char lastBump;

   while (1) {

       thisFrontRightBump = Roach_ReadFrontRightBumper();
       thisFrontLeftBump = Roach_ReadFrontLeftBumper();
       thisRearLeftBump = Roach_ReadRearLeftBumper();
       thisRearRightBump = Roach_ReadRearRightBumper();

       if (thisFrontRightBump != lastFrontRightBump) {
           frontRightBumpCounter = 0;
           TIMERS_InitTimer(TIMER_A, 10);
       }

       if (TIMERS_IsTimerExpired(TIMER_A)) {
           frontRightBumpCounter++;
           TIMERS_InitTimer(TIMER_A, 10);
           lastLastFrontRightBump = lastFrontRightBump;
           lastFrontRightBump = thisFrontRightBump;
           thisFrontRightBump = Roach_ReadFrontRightBumper();
           printf("%d", frontRightBumpCounter);
       }
       if (frontRightBumpCounter > 3) {
           frontRightBumpCounter = 0;
           if ((thisFrontRightBump == BUMPER_TRIPPED)&&(lastFrontRightBump == BUMPER_TRIPPED)&&(lastLastFrontRightBump == BUMPER_TRIPPED)) {
               printf("Front right bumper pressed!\r\n");
           }
       }


 */
//        if (thisFrontLeftBump != lastFrontLeftBump) {
//            int i;
//            for (i = 0; i < 5; i++) {
//                lastLastFrontLeftBump = lastFrontLeftBump;
//                lastFrontLeftBump = thisFrontLeftBump;
//                thisFrontLeftBump = Roach_ReadFrontLeftBumper();
//                TIMERS_InitTimer(TIMER_B, 10);
//                while (!TIMERS_IsTimerExpired(TIMER_B));
//            }
//            if ((thisFrontLeftBump == BUMPER_TRIPPED)&&(lastFrontLeftBump == BUMPER_TRIPPED)&&(lastLastFrontLeftBump == BUMPER_TRIPPED)) {
//                printf("Front left bumper pressed!\r\n");
//            }
//        }
//        if (thisRearLeftBump != lastRearLeftBump) {
//            int i;
//            for (i = 0; i < 5; i++) {
//                lastLastRearLeftBump = lastRearLeftBump;
//                lastRearLeftBump = thisRearLeftBump;
//                thisRearLeftBump = Roach_ReadRearLeftBumper();
//                TIMERS_InitTimer(TIMER_C, 10);
//                while (!TIMERS_IsTimerExpired(TIMER_C));
//            }
//            if ((thisRearLeftBump == BUMPER_TRIPPED)&&(lastRearLeftBump == BUMPER_TRIPPED)&&(lastLastRearLeftBump == BUMPER_TRIPPED)) {
//                printf("Rear left bumper pressed!\r\n");
//            }
//        }
//        if (thisRearRightBump != lastRearRightBump) {
//            int i;
//            for (i = 0; i < 5; i++) {
//                lastLastRearRightBump = lastRearRightBump;
//                lastRearRightBump = thisRearRightBump;
//                thisRearRightBump = Roach_ReadRearRightBumper();
//                TIMERS_InitTimer(TIMER_D, 10);
//                while (!TIMERS_IsTimerExpired(TIMER_D));
//            }
//            if ((thisRearRightBump == BUMPER_TRIPPED)&&(lastRearRightBump == BUMPER_TRIPPED)&&(lastLastRearRightBump == BUMPER_TRIPPED)) {
//                printf("Rear right bumper pressed!\r\n");
//            }
//        }
//check bumpers
/*thisBump = Roach_ReadBumpers();
if (thisBump != lastBump) {
    printf("Bump=%X\n", thisBump);
}
lastBump = thisBump;

//wait for 0.1 second:
TIMERS_InitTimer(0, 100);
while (TIMERS_IsTimerActive(0));*/








/*if (Roach_ReadRearRightBumper() == BUMPER_TRIPPED) {

        printf("Rear right bumper pressed");
}
if (Roach_ReadFrontLeftBumper() == BUMPER_TRIPPED) {
        printf("Front left bumper pressed");
}
if (Roach_ReadRearLeftBumper() == BUMPER_TRIPPED) {
        printf("Rear left bumper pressed");           
}*/

//check bumpers





