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
#include "autre.h"
#include "moove.h"


int main(void)
{
	int i =0;

	init_uart3(115200);

	//EINT2Init();
	//EINT3Init();
	init_jack();
	init_codeur();
	send_message("\n\rStart\n\r");

	MOOVE_Init();
	TIMER_Init(TIMER0);
	TIMER_Start(TIMER0);
	char buf[10];




		while (attendre_jack() == false) //a inverser quand on aura le support jack
		{
		/******************************************************/
		/************** debut du mode "demo" ******************/
		/******************************************************/
			if (test == true)  /* fonction de test*/
				{
					test = false;//soit a mettre a true dans une interruption, soit tous les x temps dans l'interruption du timer0
					if (sens_droit == true)
					{
						send_message("sens1\t");
					}
					else
					{
						send_message("sens2\t");
					}
					if (sens_gauche == true)
					{
						send_message("sens1\n\r");
					}
					else
					{
						send_message("sens2\n\r");
					}
					//int_to_char(une constant globale,buf);
					//send_message(buf);
				}//*/

		while(demo_mode == true)
		{
			if (asserv == true)
			{
				int_to_char(nombre_a_regarder,buf);
				send_message(buf);
				asserv = false;
			}
			if (avance == true)
			{
				LPC_GPIO0->FIOSET |= (1 << 22);//|= (1<<7); //p0.22 INa
				LPC_GPIO0->FIOCLR |= (1 << 21);//|= (1<<4); //p0.27 INb
				LPC_GPIO0->FIOSET |= (1 << 3); //p0.28 DIAG

				LPC_GPIO2->FIOCLR0 |= (1 << 6) ; // P2.6 is set to 1. InA
				LPC_GPIO2->FIOSET0 |= (1 << 7 ); //P2.7 is set to 0. InB
				LPC_GPIO2->FIOSET1 |= (1 << 0); //P2.8 is set to 1. Diag

				avance = false;
			}
			else if (recule == true)
			{
				LPC_GPIO0->FIOCLR |= (1 << 22);//|= (1<<7); //p0.22 INa
				LPC_GPIO0->FIOSET |=(1 << 21);//|= (1<<4); //p0.27 INb
				LPC_GPIO0->FIOSET |= (1 << 3); //p0.28 DIAG

				LPC_GPIO2->FIOSET0 |= (1 << 6) ; // P2.6 is set to 1. InA
				LPC_GPIO2->FIOCLR0 |= (1 << 7 ); //P2.7 is set to 0. InB
				LPC_GPIO2->FIOSET1 |= (1 << 0); //P2.8 is set to 1. Diag

				recule = false;
			}
			else if (gauche == true)
			{
				LPC_GPIO0->FIOSET |= (1 << 22);//|= (1<<7); //p0.22 INa
				LPC_GPIO0->FIOCLR |= (1 << 21);//|= (1<<4); //p0.27 INb
				LPC_GPIO0->FIOSET |= (1 << 3); //p0.28 DIAG

				LPC_GPIO2->FIOSET0 |= (1 << 6) ; // P2.6 is set to 1. InA
				LPC_GPIO2->FIOCLR0 |= (1 << 7 ); //P2.7 is set to 0. InB
				LPC_GPIO2->FIOSET1 |= (1 << 0); //P2.8 is set to 1. Diag

				gauche = false;
			}
			else if (droite == true)
			{
				LPC_GPIO0->FIOCLR |= (1 << 22);//|= (1<<7); //p0.22 INa
				LPC_GPIO0->FIOSET |= (1 << 21);//|= (1<<4); //p0.27 INb
				LPC_GPIO0->FIOSET |= (1 << 3); //p0.28 DIAG

				LPC_GPIO2->FIOCLR0 |= (1 << 6) ; // P2.6 is set to 1. InA
				LPC_GPIO2->FIOSET0 |= (1 << 7 ); //P2.7 is set to 0. InB
				LPC_GPIO2->FIOSET1 |= (1 << 0); //P2.8 is set to 1. Diag

				droite = false;
			}
			else if (stop == true)
			{
				LPC_GPIO2->FIOCLR1 |= (1 << 0); //P2.8 is set to 1. Diag
				LPC_GPIO0->FIOCLR |= (1 << 3); //p0.28 DIAG

				erreur_precedente_gauche = 0;
				somme_erreur_gauche = 0;
				erreur_precedente_droit = 0;
				somme_erreur_droit = 0;

				stop = false;
			}
			else if (regle_vitesse == true)
			{
				validation = false;
				send_message("\n\r\n\r");
				send_message("tape la vistesse en %\n\r");
				for (i = 0 ; i == strlen(commande) ; i++)
				{
					commande[i] = '\0';
				}
				while (validation == false) {}
				consigne_moteur_nombre_tours_par_seconde_gauche = atoi(commande);
				consigne_moteur_nombre_tours_par_seconde_droit = atoi(commande);
				send_message(commande);
				send_message("\n\r\n\r");
				for (i = 0 ; i == strlen(commande) ; i++)
				{
					commande[i] = '\0';
				}
				erreur_precedente_gauche = 0;
				somme_erreur_gauche = 0;
				erreur_precedente_droit = 0;
				somme_erreur_droit = 0;
				regle_vitesse = false;

		}
			if (validation == true)
			{
				if(strcmp(commande,"exit") == 0 )
				{
					demo_mode = false;
					send_message("\n\rtu es sortie du mode demo\n\r");
				}
			}
		}
		/******************************************************/
		/**************** fin du mode "demo" ******************/
		/******************************************************/

		/******************************************************/
		/************* debut de la gestion uart ***************/
		/******************************************************/
		if (validation == true)
		{
			if(strcmp(commande,"test") == 0 )
			{
				send_message("\n\rOK c'est bon\n\r");
				validation = false;
			}
			else if(strcmp(commande,"demo") == 0 )
			{
				demo_mode = true;
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
			for (i = 0 ; i == strlen(commande) ; i++)
			{
				commande[i] = '\0';
			}
		}
		/******************************************************/
		/*************** fin de la gestion uart ***************/
		/******************************************************/
	}

	/******************************************************/
	/**************** debut de la strategie ***************/
	/******************************************************/
	timer0 = 0; //remise a zero du timer pour que le match puisse commencer
	while (1)
	{
	    if (asserv == true)  // fonction de test
            {
                asserv = false;//soit a mettre a true dans une interruption, soit tous les x temps dans l'interruption du timer0

                int_to_char(nombre_a_regarder,buf);
                send_message(buf);
            }//*/
		if (timer_active == true)
		{

			timer_active = false;
			if (timer0 == 300)
			{
				erreur_precedente_gauche = 0;
				somme_erreur_gauche = 0;
				erreur_precedente_droit = 0;
				somme_erreur_droit = 0;



				consigne_moteur_nombre_tours_par_seconde_gauche = 2;
				consigne_moteur_nombre_tours_par_seconde_droit = 2;

				LPC_GPIO0->FIOSET |= (1 << 22);//|= (1<<7); //p0.22 INa
				LPC_GPIO0->FIOCLR |= (1 << 21);//|= (1<<4); //p0.27 INb
				LPC_GPIO0->FIOSET |= (1 << 3); //p0.28 DIAG

				LPC_GPIO2->FIOCLR0 |= (1 << 6) ; // P2.6 is set to 1. InA
				LPC_GPIO2->FIOSET0 |= (1 << 7 ); //P2.7 is set to 0. InB
				LPC_GPIO2->FIOSET1 |= (1 << 0); //P2.8 is set to 1. Diag
				send_message("ok");

			}
			else if (timer0 == 5*1000)
                        {
                                erreur_precedente_gauche = 0;
                                somme_erreur_gauche = 0;
                                erreur_precedente_droit = 0;
                                somme_erreur_droit = 0;

                                consigne_moteur_nombre_tours_par_seconde_gauche = 0;
                                consigne_moteur_nombre_tours_par_seconde_droit = 0;

                                LPC_GPIO0->FIOSET |= (1 << 22);//|= (1<<7); //p0.22 INa
                                LPC_GPIO0->FIOCLR |= (1 << 21);//|= (1<<4); //p0.27 INb
                                LPC_GPIO0->FIOSET |= (1 << 3); //p0.28 DIAG

                                LPC_GPIO2->FIOCLR0 |= (1 << 6) ; // P2.6 is set to 1. InA
                                LPC_GPIO2->FIOSET0 |= (1 << 7 ); //P2.7 is set to 0. InB
                                LPC_GPIO2->FIOSET1 |= (1 << 0); //P2.8 is set to 1. Diag

                        }
			else if (timer0 == 15*1000)
			{
				LPC_GPIO2->FIOCLR1 |= (1 << 0); //P2.8 is set to 1. Diag
				LPC_GPIO0->FIOCLR |= (1 << 3); //p0.28 DIAG

				erreur_precedente_gauche = 0;
				somme_erreur_gauche = 0;
				erreur_precedente_droit = 0;
				somme_erreur_droit = 0;
			}
		}
	}
	/******************************************************/
	/**************** fin de la strategie ***************/
	/******************************************************/

	return 0 ;
}
