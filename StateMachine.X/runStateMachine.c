/*
 * File:   runStateMachine.c
 * Author: max
 *
 * Created on July 28, 2016, 12:43 PM
 */

#include "runStateMachine.h"
#include <stdio.h>
#include "ArcBumpReaction.h"
#include "timers.h"

void RunStateMachine(event_t currentEvent) {
    static state_t currentState = FORWARD;
    //which state are we in? 
    printf("\nState: %d\tEvent: %d \r\n", currentState, currentEvent);
    switch (currentState) {
        case FORWARD:
        {
            switch (currentEvent) {
                    // take actions here dependent on the event
                    // and change the state if needed
                case FRONT_BUMP:
                    //?
                    ArcBackRight(-80);
                    //TIMERS_SetTimer(0,2000);
                    currentState = EVADING;                    
                    break;
                case ENTERED_DARK:
                    Stop();
                    currentState = HIDING;
                    break;
            }
            break;
        }
        case EVADING:
        {
            switch (currentEvent) {
                case BACK_BUMP:
                    Forward(100);
                    currentState = FORWARD;
                    break;
                case ENTERED_DARK:
                    currentState = HIDING;
                    break;
                //case TIME_OUT:
                    //currentState = FORWARD;
                    //break;
            }
            break;
        }
        case HIDING:
        {

            //?
            switch (currentEvent) {
                case ENTERED_LIGHT:
                    Forward(100);
                    currentState = FORWARD;
                    break;
            }
            break;
        }
    }
}