/* 
 * File:   DebouncingMain.c
 * Author: COSMOS
 *
 * Created on July 20, 2018, 11:12 AM
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
    

    
    while(1) {
        if (Roach_ReadFrontRightBumper()){
            printf("Front right bumper is down!\r\n")
        }
    }

    return (EXIT_SUCCESS);
}

