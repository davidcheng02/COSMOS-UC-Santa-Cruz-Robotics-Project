 /* 
 * File:   LEDdim_main.c
 * Author: COSMOS
 *
 * Created on July 19, 2018, 11:53 AM
 */

#include <stdio.h>
#include <stdlib.h>
#define PATTERN 0b11111111
#define THRESHOLD 15

int main(int argc, char** argv) {
    SERIAL_Init();
    BOARD_Init();
    TIMERS_Init();
    Roach_Init();
   
    while(1);
}

