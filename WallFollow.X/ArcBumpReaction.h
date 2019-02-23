#ifndef ARCBUMPREACTION_H    
#define ARCBUMPREACTION_H

/**
* @Function ArcBumpReaction(void)
* @param speed
* @return void
* @brief Arcs forward-right until it ups into 
* something with its front bumpers. Arcs backward-left until it bumps
* into something with its back bumpers
* @author YOUR NAMES */
void ArcBumpReaction(int speed);

/**
* @Function ArcLeft(speed)
* @param speed
* @return void
* @brief Arcs left
* @author YOUR NAMES */
void ArcLeft(int speed);

/**
* @Function ArcRight(speed)
* @param speed
* @return void
* @brief Arcs right
* @author YOUR NAMES */
void ArcRight(int speed);

void Reverse(int speed);

void Stop(void);

void RotateRight(int speed);

void RotateLeft(int speed);

void PivotLeft(int speed);

void PivotRight(int speed);

void Forward(int speed);

#endif