/*
 * timer.c
 *
 *  Created on: 25 nov. 2012
 *      Author: mael
 */

#include "timer.h"

volatile int timer0 = 0;

void TIMER_Init(timerNum timerNb) {

	if(timerNb == TIMER0) {

		LPC_SC->PCONP |= 1<<1;
		LPC_SC->PCLKSEL0 |= 2<<2; // Peripheral clock : CCLK/2

		LPC_TIM0->CTCR = 0;
		LPC_TIM0->MCR |= 3<<0;// Interrupt and reset on match MR0
		LPC_TIM0->PR = 99; // With MR0 it should gives a 1000Hz interrupt.
		LPC_TIM0->MR0 = 500;

		NVIC_EnableIRQ(TIMER0_IRQn);

	} else if(timerNb == TIMER1) {

		LPC_SC->PCONP |= 1<<1;
		LPC_SC->PCLKSEL0 |= 2<<4; // Peripheral clock : CCLK/2

		NVIC_EnableIRQ(TIMER1_IRQn);
	}
}


void TIMER_Start(timerNum timerNb) {

	if(timerNb == TIMER0) {

		LPC_TIM0->TCR = 1; // Counter enable

	} else if(timerNb == TIMER1) {

		LPC_TIM1->TCR = 1; // Counter enable

	}
}


void TIMER0_IRQHandler(void) {

	int irRegister = LPC_TIM0->IR;

	if((irRegister & 0x01) == 0x01) {

		timer0 ++;
		LPC_TIM0->IR |= 1<<0; // Reset the Timer.
	}

}


void TIMER1_IRQHandler(void) {


}
