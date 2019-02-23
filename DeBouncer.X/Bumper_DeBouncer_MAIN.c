/* 
 * File:   Bumper_DeBouncer.c
 * Author: Aswin and Raghav 
 *
 * gotta sweep sweep sweep
 * 
 * Created on July 19, 2018, 10:40 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "serial.h"
#include "BOARD.h"
#include "roach.h"
#include "timers.h"
#define SIZE 5
#define TIMER_A 0
#define TIME 15

/*
 * 
 */



int bounce(int recentHits[], int press) {
    int a, b, i;

    a = press;
    for (i = 1; i < SIZE; i++) {
        b = recentHits[i];
        recentHits[i] = a;
        a = b;
    }

    for (i = 0; i < SIZE; i++) {
        if (recentHits[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {

    SERIAL_Init();
    BOARD_Init();
    Roach_Init();
    TIMERS_Init();


    TIMERS_InitTimer(TIMER_A, TIME);
    int frontLeft[SIZE];
    int frontRight[SIZE];
    int backLeft[SIZE];
    int backRight[SIZE];

    int resFL, resFR, resBL, resBR;
    int lastFL, lastFR, lastBL, lastBR;

    while (1) {
        //esketit
        if (TIMERS_IsTimerExpired(TIMER_A)) {

            resFL = bounce(frontLeft, Roach_ReadFrontLeftBumper());
            resFR = bounce(frontRight, Roach_ReadFrontRightBumper());
            resBL = bounce(backLeft, Roach_ReadRearLeftBumper());
            resBR = bounce(backRight, Roach_ReadRearRightBumper());

            if (resFL == 1 && lastFL == 0) {
                printf("FRONT LEFT BOUNCE RECORDED\r\n");
            }
            if (resFR == 1 && lastFR == 0) {
                printf("FRONT RIGHT BOUNCE RECORDED\r\n");
            }
            if (resBL == 1 && lastBL == 0) {
                printf("REAR LEFT BOUNCE RECORDED\r\n");
            }
            if (resBR == 1 && lastBR == 0) {
                printf("REAR RIGHT BOUNCE RECORDED\r\n");
            }

            lastFL = resFL;
            lastFR = resFR;
            lastBL = resBL;
            lastBR = resBR;
            TIMERS_InitTimer(TIMER_A, TIME);
        }
    }
}