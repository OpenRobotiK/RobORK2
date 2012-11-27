/*
 * moove.c
 *
 *  Created on: 27 nov. 2012
 *      Author: mael
 */


#include "moove.h"


void MOOVE_Init(void) {

	MOTOR_Init(RIGHT_MOTOR);
	MOTOR_Init(LEFT_MOTOR);
}
