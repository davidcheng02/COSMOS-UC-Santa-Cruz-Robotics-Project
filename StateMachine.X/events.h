/* 
 * File:   events.h
 * Author: maxL
 *
 * Created on July 28, 2016, 12:36 PM
 */

#ifndef EVENTS_H
#define EVENTS_H

// A list of your events goes here:

typedef enum {
    NO_EVENT,
    FRONT_BUMP,
    BACK_BUMP,
    ENTERED_LIGHT,
    ENTERED_DARK,
    //TIME_OUT
} event_t;

// A prototype for the function that handles all the event checkers:
event_t CheckForEvents(void);

// prototypes for your event checkers go here:
event_t CheckForENTERED_LIGHT(void);
event_t CheckForENTERED_DARK(void);
event_t CheckForFRONT_BUMP(void);
event_t CheckForBACK_BUMP(void);
//event_t CheckForTIME_OUT(void);
// etc...

#endif