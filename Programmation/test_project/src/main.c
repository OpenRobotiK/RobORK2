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
#include "motors.h"

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



//uint32_t pwmConfigured=FALSE;
//uint32_t pwm1DutyCycle=0;


int main(void) {
	
	int i=0;



	//PWM_Init(PWM1,90);
	init_uart3(9600);		//fonctionne

	//PWM_Start(PWM1);

	init_uart3(9600);		//fonctionne

	UART3_IRQHandler();


	char buf[255];
	//int millier,centaine,dixaine;
	int test = 0;



	buf[3]=(uint8_t)test+0x30;
	buf[0]= 'S';
	buf[1]= 'a';
	buf[2]= 'l';
	buf[3]= 'u';
	send_uart3(buf,4);

	MOTOR_Init(MOTOR_RIGHT);
	MOTOR_Init(MOTOR_LEFT);
	MOTOR_Start(MOTOR_RIGHT, 10);
	MOTOR_Start(MOTOR_LEFT,  10);

	LPC_GPIO2->FIOCLR1 |= (1<<4 ); //P2.11 is set to 0.DIAG


	LPC_GPIO2->FIOCLR1 |= (1<< 0); //P2.8 is set to 1.		Diag


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
				PWM_SetDutyCycle(PWM2,atoi(commande));
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
			else if(strcmp(commande,"sens2")==0 )
			{
				//PWM_Init(PWM2, 80);
				LPC_GPIO2->FIOSET1 |= (1<<2); // P2.10 is set to 1.INa
				LPC_GPIO2->FIOCLR1 |= (1 << 3 ); //P2.11 is set to 0. INb
				LPC_GPIO2->FIOSET1 |= (1<< 4); //P2.12 is set to 1.DIAG

				LPC_GPIO2->FIOCLR0 |= (1<<6) ; // P2.6 is set to 1.		InA
				LPC_GPIO2->FIOSET0 |= (1<<7 ); //P2.7 is set to 0.		InB
				LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1.		Diag
				send_message("\n\rOK c'est bon\n\r");
				validation = 0;
			}
			else if(strcmp(commande,"sens1")==0 )
			{
				//PWM_Init(PWM2, 80);
				LPC_GPIO2->FIOCLR1 |= (1<<2 ); //P2.11 is set to 0.INa
				LPC_GPIO2->FIOSET1 |= (1<<3); // P2.10 is set to 1.INb
				LPC_GPIO2->FIOSET1 |= (1<< 4); //P2.12 is set to 1.DIAG

				LPC_GPIO2->FIOSET0 |= (1<<6) ; // P2.6 is set to 1.		InA
				LPC_GPIO2->FIOCLR0 |= (1<<7 ); //P2.7 is set to 0.		InB
				LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1.		Diag
				send_message("\n\rOK c'est bon\n\r");
				validation = 0;
			}
			else if(strcmp(commande,"stop")==0 )
			{

				LPC_GPIO2->FIOCLR1 |= (1<<4 ); //P2.11 is set to 0.DIAG


				LPC_GPIO2->FIOCLR1 |= (1<< 0); //P2.8 is set to 1.		Diag
				send_message("\n\rOK c'est bon\n\r");
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
