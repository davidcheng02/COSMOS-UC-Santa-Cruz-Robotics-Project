#ifndef BUMPERS_H    
#define BUMPERS_H
#define TIMER_A 0

/**
* @Function CheckForBumps(void)
* @param none
* @return 0 if no change in bumpers, 1 if change in bumpers
* @brief This function compares the previous bump to the current bump to detect
* for changes. It also returns a 0 or 1 to indicate whether the bumper position
* changed.
* @author YOUR NAMES */
int CheckForBumps(void);

#endif