/** \addtogroup robORK
 *
 * @{
 *
 *
 *
 * \defgroup PWM PWM
 * @{
 *
 * \file pwm.h
 * \brief pwm
 * \date Created: 18/10/2012
 * \author Lyphout Florent et Maël Gaudy
 *
 */

#ifndef PWM_H_
#define PWM_H_

#include "LPC17xx.h"
#include "main.h"


#define PWM1		1
#define PWM2		2
#define PWM3		3
#define PWM4		4
#define	PWM5		5
#define PWM6		6
//#define TCR_RESET	0x00000002


extern uint32_t pwmConfigured;
extern uint32_t pwm1DutyCycle;
extern uint32_t pwm2DutyCycle;


void PWM_Init(uint32_t pwmNum, uint32_t dutyCycle);
void PWM_Start(uint32_t pwmNum );
void PWM_Stop(uint32_t pwmNum );
void PWM_SetDutyCycle(uint32_t pwmNum, uint32_t newDutyCycle);
uint32_t PWM_GetDutyCycle(uint32_t pwmNum);

#endif /* PWM_H_ */

/**
 * @}
 * @}
 */
