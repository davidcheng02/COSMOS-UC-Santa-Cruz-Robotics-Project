/* 
 * File:   StateMachineWithEvents_main.c
 * Author: max
 *
 * Created on July 28, 2016, 12:46 PM
 */

//other includes go here
#include "BOARD.h"
#include "events.h"
#include "runStateMachine.h"
#include "roach.h"
#include "timers.h"
#include "ArcBumpReaction.h"
//#include <xc.h>

//standard event-handling main function:

void main(void)
{
    //Init code (BOARD, Roach, Timers)
    BOARD_Init();
    Roach_Init();
    TIMERS_Init();
    
    TIMERS_InitTimer(0, 2000);
    Forward(100);
    event_t currentEvent = NO_EVENT;
    RunStateMachine(NO_EVENT);
    while (1) {
        //if an event happens run the state machine
        currentEvent = CheckForEvents();
        if (currentEvent != NO_EVENT)
            RunStateMachine(currentEvent);
    }
}
