/*
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 * pwm.h
 *
 *  Created on: 18 oct. 2012
 *      Author: mael
 */

#ifndef PWM_H_
#define PWM_H_

#include "LPC17xx.h"
#include "main.h"


#define TCR_RESET	0x00000002


extern uint32_t pwmConfigured;
extern uint32_t pwm1DutyCycle;


void PWM_Init(uint32_t pwmNum, uint32_t dutyCycle);
void PWM_Start(uint32_t pwmNum );
void PWM_Stop(uint32_t pwmNum );
void PWM_SetDutyCycle(uint32_t pwmNum, uint32_t newDutyCycle);
uint32_t PWM_GetDutyCycle(uint32_t pwmNum);

#endif /* PWM_H_ */
