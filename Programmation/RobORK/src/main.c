/*
===============================================================================
Name : main.c
Author :
Version :
Copyright : Copyright (C)
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
#include "codeur.h"



int main(void)
{

	int i =0;
	EINT2Init();
	EINT3Init();
	init_uart3(9600);

	send_message("\n\rStart\n\r");

	MOTOR_Init(RIGHT_MOTOR);
	MOTOR_Init(LEFT_MOTOR);
	TIMER_Init(TIMER0);
	TIMER_Start(TIMER0);
	char buf[10];
	int_to_char(91234,buf);
	send_message(buf);




	//init_interrupt_codeur(codeur_droit);
	while(1)
	{
		if (test==true)
		{
			send_message("est passe dans l'interruption\r\n");

			test=false;
			//int_to_char(tick_codeuse,buf);
			//send_message(buf);
		}
		while(demo_mode==true)
		{
			if (asserv==true)
			{
				int_to_char(nombre_a_regarder,buf);
				send_message(buf);
				asserv=false;
			}
			if (avance==true)
			{
				LPC_GPIO0->FIOSET |= (1<<22);//|= (1<<7); //p0.22 INa
				LPC_GPIO0->FIOCLR |=(1<<21);//|= (1<<4); //p0.27 INb
				LPC_GPIO0->FIOSET |= (1<<3); //p0.28 DIAG

				LPC_GPIO2->FIOCLR0 |= (1<<6) ; // P2.6 is set to 1. InA
				LPC_GPIO2->FIOSET0 |= (1<<7 ); //P2.7 is set to 0. InB
				LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1. Diag

				avance=false;
			}
			else if (recule==true)
			{
				LPC_GPIO0->FIOCLR |= (1<<22);//|= (1<<7); //p0.22 INa
				LPC_GPIO0->FIOSET |=(1<<21);//|= (1<<4); //p0.27 INb
				LPC_GPIO0->FIOSET |= (1<<3); //p0.28 DIAG

				LPC_GPIO2->FIOSET0 |= (1<<6) ; // P2.6 is set to 1. InA
				LPC_GPIO2->FIOCLR0 |= (1<<7 ); //P2.7 is set to 0. InB
				LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1. Diag

				recule=false;
			}
			else if (gauche==true)
			{
				LPC_GPIO0->FIOSET |= (1<<22);//|= (1<<7); //p0.22 INa
				LPC_GPIO0->FIOCLR |=(1<<21);//|= (1<<4); //p0.27 INb
				LPC_GPIO0->FIOSET |= (1<<3); //p0.28 DIAG

				LPC_GPIO2->FIOSET0 |= (1<<6) ; // P2.6 is set to 1. InA
				LPC_GPIO2->FIOCLR0 |= (1<<7 ); //P2.7 is set to 0. InB
				LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1. Diag

				gauche=false;
			}
			else if (droite==true)
			{
				LPC_GPIO0->FIOCLR |= (1<<22);//|= (1<<7); //p0.22 INa
				LPC_GPIO0->FIOSET |=(1<<21);//|= (1<<4); //p0.27 INb
				LPC_GPIO0->FIOSET |= (1<<3); //p0.28 DIAG

				LPC_GPIO2->FIOCLR0 |= (1<<6) ; // P2.6 is set to 1. InA
				LPC_GPIO2->FIOSET0 |= (1<<7 ); //P2.7 is set to 0. InB
				LPC_GPIO2->FIOSET1 |= (1<< 0); //P2.8 is set to 1. Diag

				droite=false;
			}
			else if (stop==true)
			{
				/* stop les moteur au demarage*/
				LPC_GPIO2->FIOCLR1 |= (1<< 0); //P2.8 is set to 1. Diag

				LPC_GPIO0->FIOCLR |= (1<<3); //p0.28 DIAG
				//LPC_GPIO0->FIOCLR3 |= (1<<5); //p0.28 DIAG

				erreur_precedente_gauche = 0;
				somme_erreur_gauche = 0;
				erreur_precedente_droit = 0;
				somme_erreur_droit = 0;
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
				consigne_moteur_nombre_tours_par_seconde_gauche=atoi(commande);
				//PWM_SetDutyCycle(PWM2,atoi(commande)); // refaire la fonction atoi pour virer stdlib.h
				//PWM_SetDutyCycle(PWM1,atoi(commande));
				send_message(commande);
				send_message("\n\r\n\r");
				for (i=0;i==strlen(commande);i++)
				{
					commande[i]='\0';
				}
				erreur_precedente_gauche = 0;
				asomme_erreur_gauche = 0;
				erreur_precedente_droit = 0;
				somme_erreur_droit = 0;
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
