/*
 * motors.c
 *
 *  Created on: 31 oct. 2012
 *      Author: mael
 */

#include "motors.h"


void MOTOR_Init(uint32_t motor) {

	if(motor == MOTOR_RIGHT) {

		PWM_Init(PWM1, 20);

		LPC_PINCON->PINSEL4 &= 0xFFFC0FFF; //  P2.6/7/8 are configured as GPIO.
		LPC_GPIO2->FIODIR0 |= (1<<6) | (1<<7) ; // P2.6/7 are configured as output.
		LPC_GPIO2->FIODIR1 |= (1<<0); // P2.8 is configured as output.

		LPC_GPIO2->FIOSET0 &= (0<<6) ; // P2.6 is set to 1.		InA
		LPC_GPIO2->FIOSET0 |= (1<<7 ); //P2.7 is set to 0.		InB
		LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1.		Diag


	} else if(motor == MOTOR_LEFT) {

		PWM_Init(PWM2, 20);

		LPC_PINCON->PINSEL4 &= 0xFC0FFFFF;

		LPC_GPIO2->FIODIR1 |= (1<<2) | (1<<3) | (1<<4); // P2.10/11/12 are configured as output.

		LPC_GPIO2->FIOSET1 |= (1<<2); // P2.10 is set to 1.
		LPC_GPIO2->FIOSET1 |= (1<<3 ); //P2.11 is set to 0. DIAG
		LPC_GPIO2->FIOSET1 |= (1<< 4); //P2.12 is set to 1.INb
		int i=0;
		for ( i = 0 ;i==10000;i++)
		{asm("nop");}
		//LPC_GPIO2->FIOSET1 &= (0<<2); // P2.10 is set to 1.
		LPC_GPIO2->FIOCLR1 |= (1<<3 ); //P2.11 is set to 0.DIAG
		//LPC_GPIO2->FIOSET1 &= (0<< 4); //P2.12 is set to 1. INb
	}
}


void MOTOR_Start(uint32_t motor, uint32_t speed) {

	int j = 0;

	if(motor == MOTOR_RIGHT) {

		PWM_Start(PWM1);
		for(j = 0 ; j < 1000 ; j++) {	}
		PWM_SetDutyCycle(PWM1, speed);

	} else if(motor == MOTOR_LEFT) {

		PWM_Start(PWM2);
		for(j = 0 ; j < 1000 ; j++) {	}
		PWM_SetDutyCycle(PWM2, speed);
	}
}


/*void MOTOR_SetSpeed(uint32_t motor, uint32_t direction, uint32_t speed) {

	if(motor == MOTOR_RIGHT) {

		if(direction == rmcd) {



		} else {

			// Break, stop, then accelerate to the desire speed
			rmcd = direction;
		}

	} else if(motor == MOTOR_LEFT) {

		if(direction ==lrmcd) {



		} else {

			// Break, stop, then accelerate to the desire speed
			lmcd = direction;
		}
	}
}*/
