/* 
 * File:   BumpersMain.c
 * Author: COSMOS
 *
 * Created on July 25, 2018, 11:11 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "serial.h"
#include "timers.h"
#include "BOARD.h"
#include "roach.h"
#include "Bumpers.h"

#define INTERVAL 100

//ask about defining TIMER_A in main and .c file


void main(void) {
    //Initializations here
    SERIAL_Init();
    BOARD_Init();
    TIMERS_Init();
    Roach_Init();
    int bumpReturn;
    TIMERS_InitTimer(TIMER_A, 1);
    while (1) {
        /*if (CheckForBumps()) {
            //front left
            if (Roach_ReadBumpers() & 0b1)
            {
                printf("Front left bumper down\r\n");
            }
            else
            {
                printf("Front left bumper up\r\n");
            }
            
            //front right
            if (Roach_ReadBumpers() & 0b0010)
            {
                printf("Front right bumper down\r\n");
            }
            else
            {
                printf("Front right bumper up\r\n");
            }
            if (Roach_ReadBumpers() & 0b100)
            {
                printf("Rear left bumper down\r\n");
            }
            else
            {
                printf("Rear left bumper up\r\n");
            }
            if (Roach_ReadBumpers() & 0b1000)
            {
                printf("Rear right bumper down\r\n");
            }
            else
            {
                printf("Rear right bumper up\r\n");
         }*/
        bumpReturn = CheckForBumps();
        if (bumpReturn & 0b100000000)
        {
            printf("%X\r\n", bumpReturn);
        }
    }
}
