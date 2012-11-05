/*
 * motors.c
 *
 *  Created on: 31 oct. 2012
 *      Author: mael
 */

#include "motors.h"


void MOTOR_Init(uint32_t motor) {

	if(motor == MOTOR_RIGHT) {

		PWM_Init(PWM1, 50);


	} else if(motor == MOTOR_LEFT) {

		PWM_Init(PWM2, 50);

	}
}
