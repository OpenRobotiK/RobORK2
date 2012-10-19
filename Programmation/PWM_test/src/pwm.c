/*
 * pwm.c
 *
 *  Created on: 18 oct. 2012
 *      Author: mael
 */

#include "pwm.h"

void PWM_Init(uint32_t pwmNum) {

	if(pwmConfigured == FALSE) {

		LPC_SC->PCONP |= 1 << 6; // Set bit PCPWM1.
		LPC_SC->PCLKSEL0 |= 3 << 12; // Select the peripheral clock. Here PCLK_PWM1 = CCLK/8.

		LPC_PINCON->PINSEL4 |= 1 << 0; // PWM1 on P2.0 pin.
		//LPC_PINCON->PINSEL4 |= 1 << 2; // PWM2 on P2.1 pin.

		LPC_PWM1->PCR = 0x00000000; // Initialize PCR, every pwm are single edge.
		LPC_PWM1->CTCR=0x00000000; // TC is incremented when Prescale Counter matches the prescale
																	 // register.

		LPC_PWM1->TCR |= TCR_RESET;	// Reset the counter.
		LPC_PWM1->PR = 124; // The TC is incremented every PR+1 (125) cycles of PCLK_PWM.
		LPC_PWM1->MCR |= 3 << 0; // Interrupt and reset when PWMTC matches PWMMR0.

		LPC_PWM1->MR0 = 10; //

		pwmConfigured = TRUE;
	}

	if(pwmNum == 1) { // The user wants to activate the first pwm.

		LPC_PWM1->MR1 = 5; // Duty cycle of 1/2.

		LPC_PWM1->LER = (1 << 0) | (1 << 1); // Enable new values for MR0 and MR1.
		LPC_PWM1->TCR = (1 << 3) | (1 << 0);

	} else if(pwmNum ==2) {


	} else {

	}

	NVIC_EnableIRQ(PWM1_IRQn);
}


void PWM_Start(uint32_t pwmNum) {

	if(pwmNum == 1) {

		LPC_PWM1->PCR |= 1 << 9; // The pwm1 output is enabled.

	} else if(pwmNum == 2) {


	} else {

	}
}


void PWM_Stop(uint32_t pwmNum) {

	if(pwmNum == 1) {

			LPC_PWM1->PCR &= 0 << 9; // the pwm1output is disabled.

	} else if(pwmNum == 2) {


	} else {

	}
}
