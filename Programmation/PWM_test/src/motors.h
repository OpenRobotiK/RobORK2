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
#define FORWARD				1
#define BACKWARD			2


extern uint32_t rmcd; // Right Motor Current Direction
extern uint32_t lmcd; // Left Motor Current Direction


void MOTOR_Init(uint32_t motor);
void MOTOR_Start(uint32_t motor, uint32_t speed);
void MOTOR_SetSpeed(uint32_t motor, uint32_t direction, uint32_t speed);



#endif /* MOTORS_H_ */
