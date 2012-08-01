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
volatile int validation = 1;

int main(void) {
	


	/********** mettre des leds a un **************/
	LPC_PINCON->PINSEL0 = 0x00000000;
	LPC_GPIO0->FIODIR = 0xFFFFFFFF;
	LPC_GPIO0->FIOMASK = 0x00000000; // The mask^^
	LPC_GPIO0->FIOSET |= (1<<8);//|(1<<8);


	/* test uart*/

	uint8_t buff[3]={'a','b','\0'};
	init_uart3(9600);		//fonctionne
	send_uart3(buff, 3 );	// fonctionne
	//uart3 U3IER=1;
	NVIC_EnableIRQ(UART3_IRQn);
	UART3_IRQHandler();
	//int i=0;
	/*fin test uart*/

	/* test adc*/
	int test = 0;
	int millier,centaine,dixaine;
	uint8_t buf[255];
	ADCInit(ADC_CLK);
	test = ADC0Read(0);
	millier=test/1000;
	test=test%1000;
	centaine=test/100;
	test=test%100;
	dixaine=test/10;
	test=test%10;

	buf[0]=(uint8_t)millier+0x30;
	buf[1]=(uint8_t)centaine+0x30;
	buf[2]=(uint8_t)dixaine+0x30;
	buf[3]=(uint8_t)test+0x30;
	send_uart3(buf,4);

	/* pause de ADC*/


	// Enter an infinite loop, just incrementing a counter
	//volatile static int i = 0 ;
	while(1) {


		/*reprise de test ADC*/
		if(strcmp(commande,"ADC")==0 && validation==1)
		{
			buf[0] = '\n';
			send_uart3(buf,1);
			test = ADC0Read(0);
			millier=test/1000;
			test=test%1000;
			centaine=test/100;
			test=test%100;
			dixaine=test/10;
			test=test%10;
			buf[0]=(uint8_t)millier+0x30;
			buf[1]=(uint8_t)centaine+0x30;
			buf[2]=(uint8_t)dixaine+0x30;
			buf[3]=(uint8_t)test+0x30;
			send_uart3(buf,4);
			validation = 0;
		}
		if(strcmp(commande,"test")==0 && validation==1)
		{
			buf[0] = '\n';
			send_uart3(buf,1);
			buf[0]='O';
			buf[1]='k';
			buf[2]=' ';
			buf[3]='c';
			buf[4]='\'';
			buf[5]='e';
			buf[6]='s';
			buf[7]='t';
			buf[8]=' ';
			buf[9]='b';
			buf[10]='o';
			buf[11]='n';
			send_uart3(buf,12);
			validation = 0;
		}

		/*fin test adc*/

	}
	return 0 ;
}



/**
 * @}
 * @}
 */
