/** \addtogroup robORK
 *
 * @{
 *
 *
 *
 * \defgroup PWM PWM
 * @{
 *
 * \file pwm.c
 * \brief pwm
 * \date Created: 18/10/2012
 * \author Lyphout Florent et Maël Gaudy
 *
 */

#include "pwm.h"


bool pwmConfigured = false;
int pwm1DutyCycle = 0;
int pwm2DutyCycle = 0;


void PWM_Init(pwmNum pwmNb, int dutyCycle) {

	if(pwmConfigured == false) {

		LPC_SC->PCONP |= 1 << 6; // Set bit PCPWM1.
		LPC_SC->PCLKSEL0 |= 0 << 12; // Select the peripheral clock. Here PCLK_PWM1 = CCLK/4.

		LPC_PINCON->PINSEL4 |= 1 << 0; // PWM1 on P2.0 pin.
		LPC_PINCON->PINSEL4 |= 1 << 2; // PWM2 on P2.1 pin.

		LPC_PWM1->PCR = 0x00000000; // Initialize PCR, every pwm are single edge.
		LPC_PWM1->CTCR=0x00000000; // TC is incremented when Prescale Counter matches the prescale
																	 // register.

		LPC_PWM1->TCR |= 0x00000002; // Reset the counter.
		LPC_PWM1->PR = 24; // The TC is incremented every PR+1 (25) cycles of PCLK_PWM.
		LPC_PWM1->MCR = 0x00000002; // No interrupt and reset when PWMTC matches PWMMR0.

		LPC_PWM1->MR0 = 100; // We can control the pwm threw 100 steps

		pwmConfigured = true;
	}

	if(dutyCycle > 100) {

		dutyCycle = 100;
	}

	if(pwmNb == PWM1) { // The user wants to activate the first pwm.

		LPC_PWM1->MR1 = dutyCycle; // Duty cycle
		pwm1DutyCycle = dutyCycle;

		LPC_PWM1->LER = (1 << 0) | (1 << 1); // Enable new values for MR0 and MR1.

	} else if(pwmNb == PWM2) {

		LPC_PWM1->MR2 = dutyCycle; // Duty cycle
		pwm2DutyCycle = dutyCycle;

		LPC_PWM1->LER = (1 << 0) | (1 << 2); // Enable new values for MR0 and MR2.

	} else {

	}
}


void PWM_Start(pwmNum pwmNb) {

	if(pwmNb == PWM1) {

		LPC_PWM1->PCR |= 1 << 9; // The pwm1 output is enabled.
		LPC_PWM1->TCR = (1<<3) | (1<<0); // PWM mode is enabled, clear reset.

	} else if(pwmNb == PWM2) {

		LPC_PWM1->PCR |= 1 << 10; // The pwm2 output is enabled.
		LPC_PWM1->TCR = (1<<3) | (1<<0);// PWM mode is enabled, clear reset.

	} else {

	}
}


void PWM_Stop(pwmNum pwmNb) {

	if(pwmNb == PWM1) {

		LPC_PWM1->PCR &= 0 << 9; // the pwm1output is disabled.

	} else if(pwmNb == PWM2) {

		LPC_PWM1->PCR &= 0 << 10; // the pwm10 output is disabled.

	} else {

	}
}


void PWM_SetDutyCycle(pwmNum pwmNb, int newDutyCycle) {

	if(newDutyCycle > 100) {

		newDutyCycle = 100;
	}

	if(pwmNb == PWM1) {

		LPC_PWM1->MR1 = newDutyCycle; // Duty cycle desired by the user
		pwm1DutyCycle = newDutyCycle;

		LPC_PWM1->LER |= 1 << 1; // Enable new values for MR1.

	} else if(pwmNb == PWM2) {

		LPC_PWM1->MR2 = newDutyCycle; // Duty cycle desired by the user
		pwm2DutyCycle = newDutyCycle;

		LPC_PWM1->LER |= 1 << 2; // Enable new values for MR2.

	} else {

	}
}


bool PWM_GetDutyCycle(pwmNum pwmNb){

	if(pwmNb == PWM1) {

		return pwm1DutyCycle;

	} else if(pwmNb == PWM2) {

		return pwm2DutyCycle;
	}

	return false;
}


/**
 * @}
 * @}
 */
