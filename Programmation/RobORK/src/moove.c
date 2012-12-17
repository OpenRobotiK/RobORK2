/*
 * moove.c
 *
 *  Created on: 27 nov. 2012
 *      Author: mael
 */


#include "moove.h"
#include "uart.h"

void MOOVE_Init(void) {

	MOTOR_Init(RIGHT_MOTOR);
	MOTOR_Init(LEFT_MOTOR);
}


void MOOVE_Direction(Direction direction, int speed)
{

}

void changement_de_vitesse(Motor moteur, float consigne)
{
	int compteur = 5;
	int temps = timer0;
	if(moteur == RIGHT_MOTOR)
	{
		if (consigne_moteur_nombre_tours_par_seconde_droit < consigne)
		{
			temps = timer0;
			while (consigne_moteur_nombre_tours_par_seconde_droit < consigne)
			{
				compteur+=20;
				while (timer0 != (temps + compteur)){}
				consigne_moteur_nombre_tours_par_seconde_droit += pente;
				//consigne_moteur_nombre_tours_par_seconde_gauche += 0.05;
			}
		}
		else if (consigne_moteur_nombre_tours_par_seconde_droit > consigne)
		{
			temps = timer0;
			while (consigne_moteur_nombre_tours_par_seconde_droit > consigne)
			{
				compteur+=20;
				while (timer0 != (temps + compteur)){}
				consigne_moteur_nombre_tours_par_seconde_droit -= pente;
				//consigne_moteur_nombre_tours_par_seconde_gauche -= 0.05;
				if (consigne_moteur_nombre_tours_par_seconde_droit < 0)
				{
					consigne_moteur_nombre_tours_par_seconde_droit = 0;
				}
			}
		}
	}
	else if (moteur == LEFT_MOTOR)
	{
		if (consigne_moteur_nombre_tours_par_seconde_gauche < consigne)
		{
			temps = timer0;
			while (consigne_moteur_nombre_tours_par_seconde_gauche < consigne)
			{
				compteur+=20;
				while (timer0 != (temps + compteur)){}
				consigne_moteur_nombre_tours_par_seconde_gauche += pente;
			}
		}
		else if (consigne_moteur_nombre_tours_par_seconde_gauche > consigne)
		{
			temps = timer0;
			while (consigne_moteur_nombre_tours_par_seconde_gauche > consigne)
			{
				compteur+=20;
				while (timer0 != (temps + compteur)){}
				consigne_moteur_nombre_tours_par_seconde_gauche -= pente;
				//consigne_moteur_nombre_tours_par_seconde_gauche -= 0.05;
				if (consigne_moteur_nombre_tours_par_seconde_gauche < 0)
				{
					consigne_moteur_nombre_tours_par_seconde_gauche = 0;
				}
			}
		}
	}
	else if(moteur == BOTH_MOTOR)
	{
		if (consigne_moteur_nombre_tours_par_seconde_droit < consigne && consigne_moteur_nombre_tours_par_seconde_gauche < consigne)
		{
			char buf[10];
			temps = timer0;
			int_to_char(nombre_a_regarder,buf);
			send_message(buf);
			while (consigne_moteur_nombre_tours_par_seconde_droit <= consigne && consigne_moteur_nombre_tours_par_seconde_gauche <= consigne)
			{
				compteur+=20;

				while (timer0 != (temps + compteur)){}
				consigne_moteur_nombre_tours_par_seconde_droit += pente;
				consigne_moteur_nombre_tours_par_seconde_gauche += pente;
				int_to_char(nombre_a_regarder,buf);
				send_message(buf);
				/*if (consigne_moteur_nombre_tours_par_seconde_gauche > consigne)
				{
					consigne_moteur_nombre_tours_par_seconde_gauche = consigne;
				}
				if (consigne_moteur_nombre_tours_par_seconde_droit > consigne)
				{
					consigne_moteur_nombre_tours_par_seconde_droit = consigne;
				}*/
			}
		}
		else if (consigne_moteur_nombre_tours_par_seconde_droit > consigne && consigne_moteur_nombre_tours_par_seconde_gauche > consigne)
		{
			char buf[10];
			temps = timer0;
			int_to_char(nombre_a_regarder,buf);
			send_message(buf);
			while (consigne_moteur_nombre_tours_par_seconde_droit >= consigne && consigne_moteur_nombre_tours_par_seconde_gauche >= consigne)
			{
				compteur+=20;
				while (timer0 != (temps + compteur)){}
				consigne_moteur_nombre_tours_par_seconde_droit -= pente;
				consigne_moteur_nombre_tours_par_seconde_gauche -= pente;
				int_to_char(nombre_a_regarder,buf);
				send_message(buf);
				/*if (consigne_moteur_nombre_tours_par_seconde_droit < 0)
				{
					consigne_moteur_nombre_tours_par_seconde_droit = 0;
				}
				if (consigne_moteur_nombre_tours_par_seconde_gauche < 0)
				{
					consigne_moteur_nombre_tours_par_seconde_gauche = 0;
				}
				if (consigne_moteur_nombre_tours_par_seconde_droit < consigne)
				{
					consigne_moteur_nombre_tours_par_seconde_droit = consigne;
				}
				if (consigne_moteur_nombre_tours_par_seconde_gauche < consigne)
				{
					consigne_moteur_nombre_tours_par_seconde_gauche = consigne;
				}*/
			}
		}
		else if (consigne_moteur_nombre_tours_par_seconde_droit > consigne && consigne_moteur_nombre_tours_par_seconde_gauche < consigne)
		{
			temps = timer0;
			while (consigne_moteur_nombre_tours_par_seconde_droit >= consigne && consigne_moteur_nombre_tours_par_seconde_gauche <= consigne)
			{
				compteur+=20;
				while (timer0 != (temps + compteur)){}
				consigne_moteur_nombre_tours_par_seconde_droit -= pente;
				consigne_moteur_nombre_tours_par_seconde_gauche += pente;
				/*if (consigne_moteur_nombre_tours_par_seconde_droit < 0)
				{
					consigne_moteur_nombre_tours_par_seconde_droit = 0;
				}
				if (consigne_moteur_nombre_tours_par_seconde_droit < consigne)
				{
					consigne_moteur_nombre_tours_par_seconde_droit = consigne;
				}
				if (consigne_moteur_nombre_tours_par_seconde_gauche > consigne)
				{
					consigne_moteur_nombre_tours_par_seconde_gauche = consigne;
				}*/
			}
		}
		else if (consigne_moteur_nombre_tours_par_seconde_gauche > consigne && consigne_moteur_nombre_tours_par_seconde_droit < consigne)
		{
			temps = timer0;
			while (consigne_moteur_nombre_tours_par_seconde_gauche >= consigne && consigne_moteur_nombre_tours_par_seconde_droit <= consigne)
			{
				compteur+=20;
				while (timer0 != (temps + compteur)){}
				consigne_moteur_nombre_tours_par_seconde_gauche -= pente;
				consigne_moteur_nombre_tours_par_seconde_droit += pente;
				/*if (consigne_moteur_nombre_tours_par_seconde_gauche < 0)
				{
					consigne_moteur_nombre_tours_par_seconde_gauche = 0;
				}
				if (consigne_moteur_nombre_tours_par_seconde_gauche < consigne)
				{
					consigne_moteur_nombre_tours_par_seconde_gauche = consigne;
				}
				if (consigne_moteur_nombre_tours_par_seconde_droit > consigne)
				{
					consigne_moteur_nombre_tours_par_seconde_droit = consigne;
				}*/
			}
		}
	}
}

void marche_avant(float vitesse)
{
	LPC_GPIO0->FIOSET |= (1 << 22);//|= (1<<7); //p0.22 INa
	LPC_GPIO0->FIOCLR |= (1 << 21);//|= (1<<4); //p0.27 INb
	LPC_GPIO0->FIOSET |= (1 << 3); //p0.28 DIAG

	LPC_GPIO2->FIOCLR0 |= (1 << 6) ; // P2.6 is set to 1. InA
	LPC_GPIO2->FIOSET0 |= (1 << 7 ); //P2.7 is set to 0. InB
	LPC_GPIO2->FIOSET1 |= (1 << 0); //P2.8 is set to 1. Diag
	changement_de_vitesse(BOTH_MOTOR, vitesse);
}

void arret_moteur (void)
{
	changement_de_vitesse(BOTH_MOTOR, 0.0);
	LPC_GPIO2->FIOCLR1 |= (1 << 0); //P2.8 is set to 1. Diag
	LPC_GPIO0->FIOCLR |= (1 << 3); //p0.28 DIAG
	erreur_precedente_gauche = 0;
	somme_erreur_gauche = 0;
	erreur_precedente_droit = 0;
	somme_erreur_droit = 0;
}

void marche_arriere(float vitesse)
{
	LPC_GPIO0->FIOCLR |= (1 << 22);//|= (1<<7); //p0.22 INa
	LPC_GPIO0->FIOSET |=(1 << 21);//|= (1<<4); //p0.27 INb
	LPC_GPIO0->FIOSET |= (1 << 3); //p0.28 DIAG

	LPC_GPIO2->FIOSET0 |= (1 << 6) ; // P2.6 is set to 1. InA
	LPC_GPIO2->FIOCLR0 |= (1 << 7 ); //P2.7 is set to 0. InB
	LPC_GPIO2->FIOSET1 |= (1 << 0); //P2.8 is set to 1. Diag
	changement_de_vitesse(BOTH_MOTOR, vitesse);
}

void tourne_gauche(float vitesse)
{
	LPC_GPIO0->FIOSET |= (1 << 22);//|= (1<<7); //p0.22 INa
	LPC_GPIO0->FIOCLR |= (1 << 21);//|= (1<<4); //p0.27 INb
	LPC_GPIO0->FIOSET |= (1 << 3); //p0.28 DIAG

	LPC_GPIO2->FIOSET0 |= (1 << 6) ; // P2.6 is set to 1. InA
	LPC_GPIO2->FIOCLR0 |= (1 << 7 ); //P2.7 is set to 0. InB
	LPC_GPIO2->FIOSET1 |= (1 << 0); //P2.8 is set to 1. Diag

	changement_de_vitesse(BOTH_MOTOR, vitesse);
}

void tourne_droite(float vitesse)
{
	LPC_GPIO0->FIOCLR |= (1 << 22);//|= (1<<7); //p0.22 INa
	LPC_GPIO0->FIOSET |= (1 << 21);//|= (1<<4); //p0.27 INb
	LPC_GPIO0->FIOSET |= (1 << 3); //p0.28 DIAG

	LPC_GPIO2->FIOCLR0 |= (1 << 6) ; // P2.6 is set to 1. InA
	LPC_GPIO2->FIOSET0 |= (1 << 7 ); //P2.7 is set to 0. InB
	LPC_GPIO2->FIOSET1 |= (1 << 0); //P2.8 is set to 1. Diag

	changement_de_vitesse(BOTH_MOTOR, vitesse);
}


