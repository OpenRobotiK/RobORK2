/*
 * motors.c
 *
 *  Created on: 31 oct. 2012
 *      Author: mael
 */

#include "motors.h"


Direction rmcd = FORWARD; // Right Motor Current Direction
Direction lmcd = FORWARD; // Left Motor Current Direction


void MOTOR_Init(Motor motor) {

	if(motor == RIGHT_MOTOR) {

		PWM_Init(PWM1, 10);
		PWM_Start(PWM1);

		LPC_PINCON->PINSEL4 &= 0xFFFC0FFF; //  P2.6/7/8 are configured as GPIO.
		LPC_GPIO2->FIODIR0 |= (1<<6) | (1<<7) ; // P2.6/7 are configured as output.
		LPC_GPIO2->FIODIR1 |= (1<<0); // P2.8 is configured as output.

		LPC_GPIO2->FIOCLR0 |= (1<<6) ; // P2.6 is set to 0.		InA
		LPC_GPIO2->FIOSET0 |= (1<<7 ); //P2.7 is set to 1.		InB
		LPC_GPIO2->FIOCLR1 |= (1<< 0); //P2.8 is set to 1.		Diag

	} else if(motor == LEFT_MOTOR) {

		PWM_Init(PWM2, 10);
		PWM_Start(PWM2);

		LPC_PINCON->PINSEL4 &= 0xFC0FFFFF;
		LPC_GPIO2->FIODIR1 |= (1<<2) | (1<<3) | (1<<4); // P2.10/11/12 are configured as output.

		LPC_GPIO2->FIOSET1 |= (1<<2); // P2.10 is set to 1.INa
		LPC_GPIO2->FIOCLR1 |= (1 << 3 ); //P2.11 is set to 0. INb
		LPC_GPIO2->FIOCLR1 |= (1<< 4); //P2.12 is set to 1.DIAG
	}
}


void MOTOR_Start(Motor motor, int speed) {

	int j = 0;

	if(motor == RIGHT_MOTOR) {

		PWM_Start(PWM1);
		for(j = 0 ; j < 1000 ; j++) {	}
		PWM_SetDutyCycle(PWM1, speed);

	} else if(motor == LEFT_MOTOR) {

		PWM_Start(PWM2);
		for(j = 0 ; j < 1000 ; j++) {	}
		PWM_SetDutyCycle(PWM2, speed);
	}
}


void MOTOR_SetSpeed(Motor motor, Direction direction, int speed) {

	if(motor == RIGHT_MOTOR) {

		if(direction == rmcd) {



		} else {

			// Break, stop, then accelerate to the desire speed
			rmcd = direction;
		}

	} else if(motor == LEFT_MOTOR) {

		if(direction == lmcd) {



		} else {

			// Break, stop, then accelerate to the desire speed
			lmcd = direction;
		}
	}
}
