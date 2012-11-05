/*
 * motors.h
 *
 *  Created on: 31 oct. 2012
 *      Author: mael
 */

#ifndef MOTORS_H_
#define MOTORS_H_

#include "LPC17xx.h"
#include "main.h"
#include "pwm.h"


#define MOTOR_RIGHT		1
#define MOTOR_LEFT		2


void MOTOR_Init(uint32_t motor);
void MOTOR_SetSpeed(uint32_t motor);



#endif /* MOTORS_H_ */
