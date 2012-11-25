/*
===============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Copyright (C) 
 Description : main definition
===============================================================================
*/

/*#include <cr_section_macros.h>
#include <NXP/crp.h>*/

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
//__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "defines.h"
#include "motors.h"
#include "uart.h"

int main(void) {
	
	int i =0;

	init_uart3(9600);
<<<<<<< HEAD
	init_uart3(9600);
	UART3_IRQHandler();
=======

>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce
	send_message("\n\rStart\n\r");

	MOTOR_Init(RIGHT_MOTOR);
	MOTOR_Init(LEFT_MOTOR);


	while(1)
	{
		if (recule==true)
		{
			LPC_GPIO2->FIOSET1 |= (1<<2); // P2.10 is set to 1.INa
			LPC_GPIO2->FIOCLR1 |= (1 << 3 ); //P2.11 is set to 0. INb
			LPC_GPIO2->FIOSET1 |= (1<< 4); //P2.12 is set to 1.DIAG

			LPC_GPIO2->FIOCLR0 |= (1<<6) ; // P2.6 is set to 1.		InA
			LPC_GPIO2->FIOSET0 |= (1<<7 ); //P2.7 is set to 0.		InB
			LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1.		Diag

			recule=false;
		}
		else if (avance==true)
		{

			LPC_GPIO2->FIOCLR1 |= (1<<2 ); //P2.11 is set to 0.INa
			LPC_GPIO2->FIOSET1 |= (1<<3); // P2.10 is set to 1.INb
			LPC_GPIO2->FIOSET1 |= (1<< 4); //P2.12 is set to 1.DIAG

			LPC_GPIO2->FIOSET0 |= (1<<6) ; // P2.6 is set to 1.		InA
			LPC_GPIO2->FIOCLR0 |= (1<<7 ); //P2.7 is set to 0.		InB
			LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1.		Diag

			avance=false;
		}
		else if (gauche==true)
		{

			LPC_GPIO2->FIOSET1 |= (1<<2); // P2.10 is set to 1.INa
			LPC_GPIO2->FIOCLR1 |= (1 << 3 ); //P2.11 is set to 0. INb
			LPC_GPIO2->FIOSET1 |= (1<< 4); //P2.12 is set to 1.DIAG

			LPC_GPIO2->FIOSET0 |= (1<<6) ; // P2.6 is set to 1.		InA
			LPC_GPIO2->FIOCLR0 |= (1<<7 ); //P2.7 is set to 0.		InB
			LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1.		Diag

			gauche=false;
		}
		else if (droite==true)
		{

			LPC_GPIO2->FIOCLR1 |= (1<<2 ); //P2.11 is set to 0.INa
			LPC_GPIO2->FIOSET1 |= (1<<3); // P2.10 is set to 1.INb
			LPC_GPIO2->FIOSET1 |= (1<< 4); //P2.12 is set to 1.DIAG

			LPC_GPIO2->FIOCLR0 |= (1<<6) ; // P2.6 is set to 1.		InA
			LPC_GPIO2->FIOSET0 |= (1<<7 ); //P2.7 is set to 0.		InB
			LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1.		Diag

			droite=false;
		}
		else if (stop==true)
		{
			/* stop les moteur au demarage*/
			LPC_GPIO2->FIOCLR1 |= (1<<4 ); //P2.11 is set to 0.DIAG
			LPC_GPIO2->FIOCLR1 |= (1<< 0); //P2.8 is set to 1.		Diag
			stop=false;
		}

		/*reprise de test ADC*/
		if (validation==true)
		{
			if(strcmp(commande,"test")==0 )
			{
				send_message("\n\rOK c'est bon\n\r");

<<<<<<< HEAD
				validation = 0;
=======
				validation = false;
>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce

			}
			if(strcmp(commande,"v")==0 )
			{
<<<<<<< HEAD
				validation = 0;
=======
				validation = false;
>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce
				send_message("\n\r\n\r");
				send_message("tape la vistesse en %\n\r");
				for (i=0;i==strlen(commande);i++)
				{
					commande[i]='\0';
				}
<<<<<<< HEAD
				while (validation==0){}
=======
				while (validation==false){}
>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce

				PWM_SetDutyCycle(PWM2,atoi(commande)); // refaire la fonction atoi pour virer stdlib.h
				PWM_SetDutyCycle(PWM1,atoi(commande));
				send_message(commande);
				send_message("\n\r\n\r");
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
<<<<<<< HEAD
				validation = 0;
=======
				validation = false;
>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce
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
<<<<<<< HEAD
				validation = 0;
=======
				validation = false;
>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce
			}
			else if(strcmp(commande,"tourne2")==0 )
			{
				//PWM_Init(PWM2, 80);
				LPC_GPIO2->FIOSET1 |= (1<<2); // P2.10 is set to 1.INa
				LPC_GPIO2->FIOCLR1 |= (1 << 3 ); //P2.11 is set to 0. INb
				LPC_GPIO2->FIOSET1 |= (1<< 4); //P2.12 is set to 1.DIAG

				LPC_GPIO2->FIOSET0 |= (1<<6) ; // P2.6 is set to 1.		InA
				LPC_GPIO2->FIOCLR0 |= (1<<7 ); //P2.7 is set to 0.		InB
				LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1.		Diag

				send_message("\n\rOK c'est bon\n\r");
<<<<<<< HEAD
				validation = 0;
=======
				validation = false;
>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce
			}
			else if(strcmp(commande,"tourne1")==0 )
			{
				//PWM_Init(PWM2, 80);
				LPC_GPIO2->FIOCLR1 |= (1<<2 ); //P2.11 is set to 0.INa
				LPC_GPIO2->FIOSET1 |= (1<<3); // P2.10 is set to 1.INb
				LPC_GPIO2->FIOSET1 |= (1<< 4); //P2.12 is set to 1.DIAG

				LPC_GPIO2->FIOCLR0 |= (1<<6) ; // P2.6 is set to 1.		InA
				LPC_GPIO2->FIOSET0 |= (1<<7 ); //P2.7 is set to 0.		InB
				LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1.		Diag


				send_message("\n\rOK c'est bon\n\r");
<<<<<<< HEAD
				validation = 0;
=======
				validation = false;
>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce
			}
			else if(strcmp(commande,"stop")==0 )
			{

				LPC_GPIO2->FIOCLR1 |= (1<<4 ); //P2.11 is set to 0.DIAG


				LPC_GPIO2->FIOCLR1 |= (1<< 0); //P2.8 is set to 1.		Diag
				send_message("\n\rOK c'est bon\n\r");
<<<<<<< HEAD
				validation = 0;
=======
				validation = false;
>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce
			}
			else
			{
				send_message("\n\rRien du tout\n\r");
<<<<<<< HEAD
				validation = 0;
=======
				validation = false;
>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce
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
