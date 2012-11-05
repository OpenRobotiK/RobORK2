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
//#include "pwm.h"
#include "main.h"
#include <stdlib.h>

#define Board_led_port LPC_GPIO0->FIOPIN
#define Board_led_DIR LPC_GPIO0->FIODIR
#define Board_led_bit 11




// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

/// \brief à ajouter
char commande[255];
volatile int validation = 0;

uint32_t pwmConfigured = FALSE;
uint32_t pwm1DutyCycle = 0;

//uint32_t pwmConfigured=FALSE;
//uint32_t pwm1DutyCycle=0;


int main(void) {
	
	int i=0;


	/********** mettre des leds a un **************/
	/*LPC_PINCON->PINSEL0 = 0x00000000;
	LPC_GPIO0->FIODIR = 0xFFFFFFFF;
	LPC_GPIO0->FIOMASK = 0x00000000; // The mask^^
	LPC_GPIO0->FIOSET |= (1<<8);//|(1<<8);*/


	/* test uart*/

	//char buff[3]={'a','b','\0'};



	PWM_Init(PWM1,90);
	init_uart3(9600);		//fonctionne
	//PWM_Init(PWM1,90);
	//PWM_Start(PWM1);

	//PWM_SetDutyCycle(PWM1,30);
	PWM_Start(PWM1);
	//PWM_SetDutyCycle(PWM1,30);
	//PWM_Start(PWM1);
	init_uart3(9600);		//fonctionne
	//send_uart3(buff, 3 );	// fonctionne
	//uart3 U3IER=1;
	//NVIC_EnableIRQ(UART3_IRQn); Already present in init_uart3
	UART3_IRQHandler();
	//int i=0;
	/*fin test uart*/

	/* test adc*/

	char buf[255];
	int millier,centaine,dixaine;
	int test = 0;


	/*ADCInit(ADC_CLK);
	test = ADC0Read(0);
	millier=test/1000;
=======
	int test = 0;
	//int millier,centaine,dixaine;
	char buf[255];
	/*ADCInit(ADC_CLK);
	test = ADC0Read(0);*/
	/*millier=test/1000;
>>>>>>> Programmation
	test=test%1000;
	centaine=test/100;
	test=test%100;
	dixaine=test/10;
	test=test%10;*/

	/*buf[0]=(uint8_t)millier+0x30;
	buf[1]=(uint8_t)centaine+0x30;
	buf[2]=(uint8_t)dixaine+0x30;
<<<<<<< HEAD
	buf[3]=(uint8_t)test+0x30;
	send_uart3(buf,4);*/
	buf[3]=(uint8_t)test+0x30;
	buf[0]= 'S';
	buf[1]= 'a';
	buf[2]= 'l';
	buf[3]= 'u';
	send_uart3(buf,4);

	/* pause de ADC*/


	// Enter an infinite loop, just incrementing a counter
	//volatile static int i = 0 ;
	while(1)
	{


		/*reprise de test ADC*/
		if (validation==1)
		{
			/*if(strcmp(commande,"ADC")==0 )
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
			else*/ if(strcmp(commande,"test")==0 )
			{
				send_message("\n\rOK c'est bon\n\r");

				validation = 0;
				for (i=0;i==strlen(commande);i++)
				{
					commande[i]='\0';
				}
				while (validation==0){}
				send_message("\n\r\n\r\t\t");
				PWM_SetDutyCycle(PWM1,atoi(commande));
				send_message(commande);
				send_message("\n\r\n\r");
				send_uart3("\n\r\n\r\t\t",strlen("\n\r\n\r\t\t"));
				//PWM_SetDutyCycle(PWM1,atoi(commande));
				send_uart3(commande,strlen(commande));
				send_uart3("\n\r\n\r",strlen("\n\r\n\r"));
				for (i=0;i==strlen(commande);i++)
				{
					commande[i]='\0';
				}
			}
			else if(strcmp(commande,"aa")==0 )
			{

				send_message("\n\rca marche bien\n\r");
				validation = 0;
			}
			else
			{
				send_message("\n\rRien du tout\n\r");
				validation = 0;
			}

			/*fin test adc*/
			for (i=0;i==strlen(commande);i++)
			{
				commande[i]='\0';
			}
		}
	}
	return 0 ;
}



/**
 * @}
 * @}
 */
