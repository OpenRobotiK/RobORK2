/*
 * timer.h
 *
 *  Created on: 25 nov. 2012
 *      Author: mael
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "defines.h"
#include "asserv_vitesse.h"
#include "asserv_position.h"

typedef enum timerNum timerNum;
enum timerNum{TIMER0, TIMER1, TIMER2, TIMER3};

extern volatile int timer0;
extern volatile int timer_ms;
extern volatile bool timer_active;

void TIMER_Init(timerNum timerNb);
void TIMER_Start(timerNum timerNb);
void TIMER0_IRQHandler(void);
void TIMER1_IRQHandler(void);

#endif /* TIMER_H_ */



