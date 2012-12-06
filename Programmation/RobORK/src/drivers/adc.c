/*
 * adc.c
 *
 *  Created on: 6 déc. 2012
 *      Author: mael
 */

#include "adc.h"

void ADC_Init(void) {

	LPC_SC->PCONP |= 1 << 12;
	LPC_SC->PCLKSEL0 |= 1 << 24; // PCLK =CCLK

	// Je dois initialiser P0.23/24/25/26 P1.30/31
}
