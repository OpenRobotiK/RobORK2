/*
 * adc.c
 *
 *  Created on: 6 déc. 2012
 *      Author: mael
 */

#include "adc.h"

int adcValue[6] = {0};

void ADC_Init(void) {

	/*int i = 0;
	for(i = 0 ; i < 6 ; i++) {

		adcValue[i] = 0;
	}*/

	LPC_SC->PCONP |= 1 << 12;
	LPC_SC->PCLKSEL0 |= 1 << 24; // PCLK =CCLK

	LPC_ADC->ADCR |= 1 << 21;

	// Je dois initialiser P0.23/24/25/26 P1.30/31
	LPC_PINCON->PINSEL1 |= 1 << 14; // AD0.0
	LPC_PINCON->PINSEL1 |= 1 << 16; // AD0.1
	LPC_PINCON->PINSEL1 |= 1 << 18; // AD0.2
	LPC_PINCON->PINSEL1 |= 1 << 20; // AD0.3
	LPC_PINCON->PINSEL3 |= 3 << 28; // AD0.4
	LPC_PINCON->PINSEL3 |= 3 << 30; // AD0.5

	NVIC_EnableIRQ(ADC_IRQn);
	LPC_ADC->ADINTEN |= 0x3F;// AD0.0~5 creates an interrupt.
}


void ADC_Disable(void) {

	LPC_ADC->ADCR &= 0 << 21;
	LPC_SC->PCONP &= 0 << 12;
}


void ADC_StartAutoSampling(void) {

	LPC_ADC->ADCR |= 0x3F; // AD0.0~5 are set to be sampled
	LPC_ADC->ADCR &= 0xF8FFFFFF; // START is set to 000
	LPC_ADC->ADCR |= 1 << 16; // BURST is set.
}


void ADC_IRQHandler(void) {

	uint32_t status;
	status = LPC_ADC->ADSTAT;

	if(status & 0x01) {

		adcValue[0] = (LPC_ADC->ADDR0 >> 4) & 0xFFF;

	} else if(status & 0x02) {

		adcValue[1] = (LPC_ADC->ADDR1 >> 4) & 0xFFF;

	} else if(status & 0x04) {

		adcValue[2] = (LPC_ADC->ADDR2 >> 4) & 0xFFF;

	} else if(status & 0x08) {

		adcValue[3] = (LPC_ADC->ADDR3 >> 4) & 0xFFF;

	} else if(status & 0x10) {

		adcValue[4] = (LPC_ADC->ADDR4 >> 4) & 0xFFF;

	} else if(status & 0x20) {

		adcValue[5] = (LPC_ADC->ADDR5 >> 4) & 0xFFF;

	}
}


int getAdcValue(int adcNb) {

	return adcValue[adcNb];
}
