/*
 * timer.c
 *
 *  Created on: 25 nov. 2012
 *      Author: mael
 */

#include "timer.h"

void TIMER_Init(timerNum timerNb) {

	if(timerNb == TIMER0) {

		LPC_SC->PCONP |= 1<<1;
		LPC_SC->PCLKSEL0 |= 2<<2; // Peripheral clock : CCLK/2

		//LPC_TIM1->TCR = ;

		NVIC_EnableIRQ(TIMER0_IRQn);

	} else if(timerNb == TIMER1) {

		LPC_SC->PCONP |= 1<<1;
		LPC_SC->PCLKSEL0 |= 2<<4; // Peripheral clock : CCLK/2

		NVIC_EnableIRQ(TIMER1_IRQn);
	}
}


void TIMER0_IRQHandler(void) {


}


void TIMER1_IRQHandler(void) {


}
