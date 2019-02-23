/*
 * File:   events.h
 * Author: maxL
 *
 * Created on July 28, 2016, 12:36 PM
 */

#include <stdio.h>
#include "events.h"
#include "roach.h"
#include "timers.h"


// Check for all events:

event_t CheckForEvents(void)
{
    event_t thisEvent = NO_EVENT;

    thisEvent = CheckForENTERED_LIGHT();
    if (thisEvent != NO_EVENT) {
        return thisEvent;
    }

    thisEvent = CheckForENTERED_DARK();

    if (thisEvent != NO_EVENT) {
        return thisEvent;
    }
    
    thisEvent = CheckForFRONT_BUMP();
    if (thisEvent != NO_EVENT) {
        return thisEvent;
    } 
    
    thisEvent = CheckForBACK_BUMP();
    if (thisEvent != NO_EVENT) {
        return thisEvent;
    } 
    
    /*thisEvent = CheckForTIME_OUT();
    if (thisEvent != NO_EVENT) {
        return thisEvent;
    }*/
    
    return NO_EVENT;
}

// define each event checker

event_t CheckForENTERED_LIGHT(void)
{
    // all event checkers remember their previous Event:
    static event_t previousEvent;
    int LightLevel = Roach_LightLevel();
    
    // all event checkers update their event:
    event_t currentEvent = NO_EVENT;
    
    if(LightLevel <= 800){
        currentEvent = ENTERED_LIGHT;
    }

    // if there has been an important change, return an event:
    if (previousEvent != currentEvent) {
        previousEvent = currentEvent;
        return currentEvent;
    }

    //and if there has not been an important change,
    return NO_EVENT;
}

event_t CheckForENTERED_DARK(void)
{
    // all event checkers remember their previous Event:
    static int previousEvent;
    int LightLevel = Roach_LightLevel();
    
    // all event checkers update their event:
    event_t currentEvent = NO_EVENT;
    
    if(LightLevel >= 800){
        currentEvent = ENTERED_DARK;
    }

    // if there has been an important change, return an event:
    if (previousEvent != currentEvent) {
        previousEvent = currentEvent;
        return currentEvent;
    }

    //and if there has not been an important change,
    return NO_EVENT;
}

event_t CheckForFRONT_BUMP(void) {
    static event_t previousEvent;
    
    //?
    event_t currentEvent = NO_EVENT;
    
    int readBumps = Roach_ReadBumpers();
    if (readBumps == 1 || readBumps == 2) {
        currentEvent = FRONT_BUMP;
    }
    
    if (previousEvent != currentEvent) {
        previousEvent = currentEvent;
        return currentEvent;
    }
    
    return NO_EVENT;
}

event_t CheckForBACK_BUMP(void) {
    static event_t previousEvent;
    
    event_t currentEvent = NO_EVENT;
    
    int readBumps = Roach_ReadBumpers();
    if (readBumps == 4 || readBumps == 8) {
        currentEvent = BACK_BUMP;
    }
    
    if (previousEvent != currentEvent) {
        previousEvent = currentEvent;
        return currentEvent;
    }
    
    return NO_EVENT;
}

/*event_t CheckForTIME_OUT(void) {
    static event_t previousEvent;
    event_t currentEvent = NO_EVENT;
    
    if (TIMERS_IsTimerExpired(0)) {
        currentEvent = TIME_OUT;
    }
    
    if (previousEvent != currentEvent) {
        previousEvent = currentEvent;
        return currentEvent;
    }
    
    return NO_EVENT;
}*/

