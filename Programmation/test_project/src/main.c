/** \addtogroup robORK
 *
 * @{
 *
 *
 *
 * \defgroup main main
 * @{
 *
 * \file main.c
 * \brief main
 * \date Created: 13/07/2012
 * \author Lyphout Florent et Maël Gaudy
 *
 */



#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>
#include "UART.h"
#include <string.h>
#include "ADC.h"
#include <stdio.h>

#define Board_led_port LPC_GPIO0->FIOPIN
#define Board_led_DIR LPC_GPIO0->FIODIR
#define Board_led_bit 11




// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

/// \brief à ajouter
char commande[255];


int main(void) {
	


	/********** mettre des leds a un **************/
	LPC_PINCON->PINSEL0 = 0x00000000;
	LPC_GPIO0->FIODIR = 0xFFFFFFFF;
	LPC_GPIO0->FIOMASK = 0x00000000; // The mask^^
	LPC_GPIO0->FIOSET |= (1<<8);//|(1<<8);


	/* test uart*/

	uint8_t buf[3]={'a','b','\0'};
	init_uart3(9600);		//fonctionne
	send_uart3(buf, 3 );	// fonctionne
	//uart3 U3IER=1;
	NVIC_EnableIRQ(UART3_IRQn);
	UART3_IRQHandler();

	/*fin test uart*/

	/* test adc*/
	int test = 0;
	int millier,centaine,dixaine;
	uint8_t buff[255];
	ADCInit(ADC_CLK);
	test = ADC0Read(0);
	millier=test/1000;
	test=test%1000;
	centaine=test/100;
	test=test%100;
	dixaine=test/10;
	test=test%10;

	buff[0]=(uint8_t)millier+0x30;
	buff[1]=(uint8_t)centaine+0x30;
	buff[2]=(uint8_t)dixaine+0x30;
	buff[3]=(uint8_t)test+0x30;
	send_uart3(buff,4);

	/* pause de ADC*/


	// Enter an infinite loop, just incrementing a counter
	volatile static int i = 0 ;
	while(1) {
		i++ ;
		/*reprise de test ADC*/
		/*test = ADC0Read(0);
			millier=test/1000;
			test=test%1000;
			centaine=test/100;
			test=test%100;
			dixaine=test/10;
			test=test%10;

			buff[0]=(uint8_t)millier+0x30;
			buff[1]=(uint8_t)centaine+0x30;
			buff[2]=(uint8_t)dixaine+0x30;
			buff[3]=(uint8_t)test+0x30;
			send_uart3(buff,4);*/
		/*fin test adc*/

	}
	return 0 ;
}



/**
 * @}
 * @}
 */
