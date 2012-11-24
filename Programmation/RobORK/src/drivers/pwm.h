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
#include "defines.h"


typedef enum pwmNum pwmNum;
enum pwmNum{ PWM1, PWM2, PWM3, PWM4, PWM5, PWM6};


extern bool pwmConfigured;
extern int pwm1DutyCycle;
extern int pwm2DutyCycle;


void PWM_Init(pwmNum pwmNb, int dutyCycle);
void PWM_Start(pwmNum pwmNb);
void PWM_Stop(pwmNum pwmNb);
void PWM_SetDutyCycle(pwmNum pwmNb, int newDutyCycle);
bool PWM_GetDutyCycle(pwmNum pwmNb);

#endif /* PWM_H_ */

/**
 * @}
 * @}
 */
