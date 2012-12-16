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

    RIGHT_MOTOR, LEFT_MOTOR, BOTH_MOTOR
};

typedef enum Direction Direction;
enum Direction {

	FORWARD, BACKWARD, STOPPED
};

typedef struct MotorInfos MotorInfos;
struct MotorInfos{

	Direction	direction;
	int				orderedSpeed;
	int				mesuredSpeed;
};

extern MotorInfos rightMotor;
extern MotorInfos leftMotor;


void MOTOR_Init(Motor motor);
void MOTOR_Start(Motor motor);
void MOTOR_Stop(Motor motor);
void MOTOR_SetSpeed(Motor motor, Direction direction, int consigne);



#endif /* MOTORS_H_ */
