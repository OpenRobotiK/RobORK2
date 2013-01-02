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

#include "string.h"



int main(void)
{
	int i =0;
	int tache1 = -1, tache2 = -1, tache3 = -1, tache4 = -1, tache5 = -1, tache6 = -1, tache7 = -1, tache8 = -1, tache9 = -1;
	init_uart3(115200);

	init_jack();
	init_codeur();

	send_message("\n\rStart\n\r");

	MOTOR_Init(RIGHT_MOTOR);
	MOTOR_Init(LEFT_MOTOR);
	TIMER_Init(TIMER0);
	TIMER_Start(TIMER0);
	char buf[10];

	//marche_avant(0.25);
	//consigne_angle = 0;
	//marche_avant(1);
	changement_de_vitesse_des_roues(1,1);
	float asservis;
	float asservis1;
	while (attendre_jack() == false) //a inverser quand on aura le support jack
	{
		/******************************************************/
		/************** debut du mode "demo" ******************/
		/******************************************************/
		if (test == true)  // fonction de test
		{
			test = false;//soit a mettre a true dans une interruption, soit tous les x temps dans l'interruption du timer0
			affiche_position();
			//int_to_char((int)consigne_angle,buf);
			//send_message(buf);
		}//*/

		if (timer_ms % 101 && timer_ms >= 1000)
		{
			//changement_de_vitesse_des_roues(0.5,0.5);
			//asservisement_angle();
			//asservisement_distance();
			asservis1 = asservisement_angle();
			asservis = asservisement_distance();

			//asservi(asservisement_distance(),asservisement_distance());
			//test_asserv();
		}
		if ((timer_ms + 50) % 101 && timer_ms >= 1000)
		{
			//changement_de_vitesse_des_roues(-0.5,-0.5);
			//asservis = -asservis;
			//send_message("asserv\n\r");
			if (erreur_angle < 25 && -25 < erreur_angle)
			{
				if (erreur_distance < 5 && -5 < erreur_distance)
				{
					arret_moteur();
				}
				else
				{
					changement_de_vitesse_des_roues((-asservis),-asservis);
				}
			}
			else
			{
				if (erreur_distance < 5 && -5 < erreur_distance)
				{
					arret_moteur();
				}
				else
				{
					changement_de_vitesse_des_roues((-asservis1),asservis1);
				}

			}

			//changement_de_vitesse_des_roues((asservis+asservis1),(asservis-asservis1));
			//changement_de_vitesse_des_roues((-asservis),asservis);
			//asservisement_distance();
			//test_asserv();
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
					send_message("\n\r\n\r\t\tTu es sortie du mode demo\n\r\n\r");
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
		/*if (asserv == true)  // fonction de test
		{
				asserv = false;//soit a mettre a true dans une interruption, soit tous les x temps dans l'interruption du timer0
				affiche_position();
		}//*/
		if (test == true)  // fonction de test
		{
				test = false;//soit a mettre a true dans une interruption, soit tous les x temps dans l'interruption du timer0
				affiche_position();
		}//*/
		if (timer_active == true)
		{
			timer_active = false;

			if (timer0 == 5)
			{
				erreur_precedente_gauche = 0;
				somme_erreur_gauche = 0;
				erreur_precedente_droit = 0;
				somme_erreur_droit = 0;
				LPC_GPIO0->FIOSET |= (1 << 22);//|= (1<<7); //p0.22 INa
				LPC_GPIO0->FIOCLR |= (1 << 21);//|= (1<<4); //p0.27 INb
				LPC_GPIO0->FIOSET |= (1 << 3); //p0.28 DIAG

				LPC_GPIO2->FIOCLR0 |= (1 << 6) ; // P2.6 is set to 1. InA
				LPC_GPIO2->FIOSET0 |= (1 << 7 ); //P2.7 is set to 0. InB
				LPC_GPIO2->FIOSET1 |= (1 << 0); //P2.8 is set to 1. Diag
				virage(1.1,2.2);
				tache1 = 2000;
			}
			else if (timer0 == tache1)
			{
				virage(3,2.2);
				tache2 = tache1 + 2000;
			}
			else if (timer0 == tache2)
			{
				marche_avant(3);
				tache3 = tache2 + 2000;
			}
			else if (timer0 == tache3)
			{
				arret_moteur();
				tache4 = tache3 + 1000;
			}//*/
			/*if (timer0 == 0)
			{
				erreur_precedente_gauche = 0;
				somme_erreur_gauche = 0;
				erreur_precedente_droit = 0;
				marche_avant(3); //pendant 2.1s
				tache1 = 1700;
			}
			else if (timer0 == tache1)
			{
				arret_moteur();
				tache2 = tache1 + 1000;
			}
			else if (timer0 == tache2)
			{
				//marche_arriere(3);
				erreur_precedente_gauche = 0;
				somme_erreur_gauche = 0;
				erreur_precedente_droit = 0;
				somme_erreur_droit = 0;
				tourne_droite(1);
				tache3 = tache2 + 810;
			}
			else if (timer0 == tache3)
			{
				arret_moteur();
				tache4 = tache3 + 1000;
			}
			else if (timer0 == tache4)
			{
				erreur_precedente_gauche = 0;
				somme_erreur_gauche = 0;
				erreur_precedente_droit = 0;
				somme_erreur_droit = 0;
				marche_avant(3);
				tache5 = tache4 + 2800;
			}
			else if (timer0 == tache5)
			{
				arret_moteur();
				tache6 = tache5 + 1000;
			}
			else if (timer0 == tache6)
			{
				erreur_precedente_gauche = 0;
				somme_erreur_gauche = 0;
				erreur_precedente_droit = 0;
				somme_erreur_droit = 0;
				tourne_droite(1);
				tache7 = tache6 + 790;
			}
			else if (timer0 == tache7)
			{
				arret_moteur();
				tache8 = tache7 + 1000;
			}
			else if (timer0 == tache8)
			{
				erreur_precedente_gauche = 0;
				somme_erreur_gauche = 0;
				erreur_precedente_droit = 0;
				somme_erreur_droit = 0;
				marche_avant(2);
				tache9 = tache8 + 2000;
			}
			else if (timer0 == tache9)
			{
				arret_moteur();

			}
			/*else if (timer0 == 33*1000)
			{
				marche_arriere(3);
			}
			else if (timer0 == 36*1000)
			{
				arret_moteur();
			}*/
		}
	}
	/******************************************************/
	/**************** fin de la strategie ***************/
	/******************************************************/

	return 0 ;
}
