/*
 * moove.h
 *
 *  Created on: 27 nov. 2012
 *      Author: mael
 */

#ifndef MOOVE_H_
#define MOOVE_H_


#include "motors.h"
#include "defines.h"
#include "aserv.h"

extern void MOOVE_Init(void);
extern void MOOVE_Direction(Direction direction, int speed);
extern void changement_de_vitesse (Motor moteur,int vitesse);

#endif /* MOOVE_H_ */
