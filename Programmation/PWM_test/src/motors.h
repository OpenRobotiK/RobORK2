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


//#define MOTOR_RIGHT		1
//#define MOTOR_LEFT		2
//#define FORWARD				1
//#define BACKWARD			2


typedef enum Motor Motor;
enum Motor {

    RIGHT_MOTOR, LEFT_MOTOR
};

typedef enum Direction Direction;
enum Direction {

	FORWARD, BACKWARD
};


extern Direction rmcd; // Right Motor Current Direction
extern Direction lmcd; // Left Motor Current Direction


void MOTOR_Init(Motor motor);
void MOTOR_Start(Motor motor, uint32_t speed);
void MOTOR_SetSpeed(Motor motor, Direction direction, uint32_t speed);



#endif /* MOTORS_H_ */
