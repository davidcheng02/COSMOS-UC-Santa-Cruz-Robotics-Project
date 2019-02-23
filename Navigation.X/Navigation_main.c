/* 
 * File:   Navigation_main.c
 * Author: COSMOS
 *
 * Created on July 24, 2018, 11:01 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "serial.h"
#include "timers.h"
#include "BOARD.h"
#include "roach.h"

#include "Navigation.h"

#define INTERVAL 1000 

//Make Roach go Forward at speed, speed between -100 and 100

void Forward(int speed) {
    Roach_LeftMtrSpeed(-speed);
    Roach_RightMtrSpeed(-speed);
}

void Reverse(int speed) {
    Roach_LeftMtrSpeed(-speed);
    Roach_RightMtrSpeed(-speed);
}

void Stop(void) {
    Roach_LeftMtrSpeed(0);
    Roach_RightMtrSpeed(0);
}

void RotateRight(int speed) {
    Roach_LeftMtrSpeed(speed);
    Roach_RightMtrSpeed(-speed);
}

void RotateLeft(int speed) {
    Roach_LeftMtrSpeed(-speed);
    Roach_RightMtrSpeed(speed);
}

void PivotLeft(int speed) {
    Roach_LeftMtrSpeed(0);
    Roach_RightMtrSpeed(speed);
}

void PivotRight(int speed) {
    Roach_LeftMtrSpeed(speed);
    Roach_RightMtrSpeed(0);
}

void ArcLeft(int speed) {
    if (speed <= 80) {
        Roach_LeftMtrSpeed(speed);
        Roach_RightMtrSpeed(speed * 5 / 4);
    } else {
        Roach_LeftMtrSpeed(speed);
        Roach_RightMtrSpeed(100);
    }

}

void ArcRight(int speed) {
    if (speed <= 80) {
        Roach_LeftMtrSpeed(speed * 5 / 4);
        Roach_RightMtrSpeed(speed);
    } else {
        Roach_LeftMtrSpeed(100);
        Roach_RightMtrSpeed(speed);
    }
}

void main(void) {
    SERIAL_Init();
    BOARD_Init();
    TIMERS_Init();
    Roach_Init();

    //Init functions here
    printf("Forward() test...\n");
    int current_speed = 100;
    TIMERS_InitTimer(0, 1);
    while (1) {
        if (TIMERS_IsTimerExpired(0)) {
            TIMERS_InitTimer(0, INTERVAL);
            printf("Forward(%d)\n", current_speed);
            Forward(current_speed);
            current_speed -= 10;
        }
    }
}

