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
#include "timer.h"

int main(void) {
	
	int i =0;

	init_uart3(9600);

	send_message("\n\rStart\n\r");

	MOTOR_Init(RIGHT_MOTOR);
	MOTOR_Init(LEFT_MOTOR);
	TIMER_Init(TIMER0);
	TIMER_Start(TIMER0);


	while(1)
	{
		while(demo_mode==true)
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
			else if (regle_vitesse==true)
			{
				validation = false;
				send_message("\n\r\n\r");
				send_message("tape la vistesse en %\n\r");
				for (i=0;i==strlen(commande);i++)
				{
					commande[i]='\0';
				}
				while (validation==false){}

				PWM_SetDutyCycle(PWM2,atoi(commande)); // refaire la fonction atoi pour virer stdlib.h
				PWM_SetDutyCycle(PWM1,atoi(commande));
				send_message(commande);
				send_message("\n\r\n\r");
				for (i=0;i==strlen(commande);i++)
				{
					commande[i]='\0';
				}
				regle_vitesse=false;
			}
			if (validation==true)
			{
				if(strcmp(commande,"exit")==0 )
				{
					demo_mode=false;
					send_message("\n\rtu es sortie du mode demo\n\r");
				}
			}
		}

		/*reprise de test ADC*/
		if (validation==true)
		{
			if(strcmp(commande,"test")==0 )
			{
				send_message("\n\rOK c'est bon\n\r");
				validation = false;
			}
			else if(strcmp(commande,"demo")==0 )
			{
				demo_mode=true;
				send_message("\n\rtu es dans le mode demo\n\rutilise :\n\r\t"
						"z pour avancer\n\r\t"
						"s pour reculer\n\r\t"
						"q pour tourner a gauche\n\r\t"
						"d pour tourner a droite\n\r\t"
						"a pour stoper\n\r\t"
						"v pour regler la vitesse\n\r");
				validation = false;
			}
			else
			{
				send_message("\n\rRien du tout\n\r");
				validation = false;
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
