/*
 * motors.c
 *
 *  Created on: 31 oct. 2012
 *      Author: mael
 */

#include "motors.h"


MotorInfos rightMotor = {STOPPED, 0, 0};
MotorInfos leftMotor = {STOPPED, 0, 0};


void MOTOR_Init(Motor motor) {

	if(motor == RIGHT_MOTOR) {

		PWM_Init(PWM1, 10);
		PWM_Start(PWM1);

		LPC_PINCON->PINSEL4 &= 0xFFFC0FFF; //  P2.6/7/8 are configured as GPIO.
		LPC_GPIO2->FIODIR0 |= (1<<6) | (1<<7) ; // P2.6/7 are configured as output.
		LPC_GPIO2->FIODIR1 |= (1<<0); // P2.8 is configured as output.

		LPC_GPIO2->FIOCLR0 |= (1<<6) ; // P2.6 is set to 0.		InA
		LPC_GPIO2->FIOSET0 |= (1<<7 ); //P2.7 is set to 1.		InB
		LPC_GPIO2->FIOCLR1 |= (1<< 0); //P2.8 is set to 0.		Diag

	} else if(motor == LEFT_MOTOR) {

		PWM_Init(PWM2, 10);
		PWM_Start(PWM2);

		LPC_PINCON->PINSEL4 &= 0xFC0FFFFF;
		LPC_GPIO2->FIODIR1 |= (1<<2) | (1<<3) | (1<<4); // P2.10/11/12 are configured as output.

		LPC_GPIO2->FIOSET1 |= (1<<2); // P2.10 is set to 1.INa
		LPC_GPIO2->FIOCLR1 |= (1 << 3 ); //P2.11 is set to 0. INb
		LPC_GPIO2->FIOCLR1 |= (1<< 4); //P2.12 is set to 0.DIAG
	}
}


void MOTOR_Start(Motor motor) {

	if(motor == RIGHT_MOTOR) {

		LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1. DIAG

	} else if(motor == LEFT_MOTOR) {

		LPC_GPIO2->FIOSET1 |= (1<< 4); //P2.12 is set to 1. DIAG
	}
}


void MOTOR_Stop(Motor motor) {

	if(motor == RIGHT_MOTOR) {

		LPC_GPIO2->FIOCLR1 |= (1<< 0); //P2.8 is set to 0. DIAG
		PWM_SetDutyCycle(PWM1, 0);
		rightMotor.direction = STOPPED;
		rightMotor.orderedSpeed = 0;

	} else if(motor == LEFT_MOTOR) {

		LPC_GPIO2->FIOCLR1 |= (1<< 4); //P2.12 is set to 0. DIAG
		PWM_SetDutyCycle(PWM1, 0);
		leftMotor.direction = STOPPED;
		leftMotor.orderedSpeed = 0;
	}
}


void MOTOR_SetSpeed(Motor motor, Direction direction, int speed) {

	if(motor == RIGHT_MOTOR) {

		if(direction == FORWARD) {

			LPC_GPIO2->FIOCLR0 |= (1<<6) ; // P2.6 is set to 0.		InA
			LPC_GPIO2->FIOSET0 |= (1<<7 ); //P2.7 is set to 1.		InB

			PWM_SetDutyCycle(PWM1, speed);

		} else if(direction == BACKWARD) {

			LPC_GPIO2->FIOSET0 |= (1<<6) ; // P2.6 is set to 0.		InA
			LPC_GPIO2->FIOCLR0 |= (1<<7 ); //P2.7 is set to 1.		InB

			PWM_SetDutyCycle(PWM1, speed);


		} else {

			MOTOR_Stop(RIGHT_MOTOR);
		}

	} else if(motor == LEFT_MOTOR) {

		if(direction == FORWARD) {

			LPC_GPIO2->FIOSET1 |= (1<<2); // P2.10 is set to 1.INa
			LPC_GPIO2->FIOCLR1 |= (1 << 3 ); //P2.11 is set to 0. INb

			PWM_SetDutyCycle(PWM2, speed);

		} else if(direction == BACKWARD) {

			LPC_GPIO2->FIOCLR1 |= (1<<2); // P2.10 is set to 0.INa
			LPC_GPIO2->FIOSET1 |= (1 << 3 ); //P2.11 is set to 1. INb

			PWM_SetDutyCycle(PWM2, speed);

		} else {

			MOTOR_Stop(LEFT_MOTOR);
		}
	}
}
