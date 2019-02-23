/* 
 * File:   runStateMachine.h
 * Author: max
 *
 * Created on July 28, 2016, 12:43 PM
 */

#ifndef RUNSTATEMACHINE_H
#define RUNSTATEMACHINE_H


#include "events.h"

// A list of your states goes here:

typedef enum {
    FORWARD,
    EVADING,
    HIDING
} state_t;

// A prototype for the function that handles the whole state machine:
void RunStateMachine(event_t this_event);



#endif