/*
 * adc.h
 *
 *  Created on: 6 déc. 2012
 *      Author: mael
 */

#ifndef ADC_H_
#define ADC_H_

#include "defines.h"


extern int adcValue[6];


void ADC_Init(void);
void ADC_Disable(void);
void ADC_StartAutoSampling(void);
void ADC_IRQHandler(void);

int getAdcValue(int adcNb);

#endif /* ADC_H_ */
