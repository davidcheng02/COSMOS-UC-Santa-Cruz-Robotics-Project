#include "roach.h"
#include "Navigation.h" //.h file has prototype of Forward method

void Forward(int speed) {
    Roach_LeftMtrSpeed(speed);
    Roach_RightMtrSpeed(speed);
}