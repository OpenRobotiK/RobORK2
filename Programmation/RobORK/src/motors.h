/*
 * motors.h
 *
 *  Created on: 31 oct. 2012
 *      Author: mael
 */

#ifndef MOTORS_H_
#define MOTORS_H_


#include "defines.h"
#include "pwm.h"


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
void MOTOR_Start(Motor motor, int speed);
void MOTOR_SetSpeed(Motor motor, Direction direction, int speed);



#endif /* MOTORS_H_ */
