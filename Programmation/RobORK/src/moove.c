/*
 * moove.c
 *
 *  Created on: 27 nov. 2012
 *      Author: mael
 */


#include "moove.h"


void MOOVE_Init(void) {

	MOTOR_Init(RIGHT_MOTOR);
	MOTOR_Init(LEFT_MOTOR);
}


void MOOVE_Direction(Direction direction, int speed)
{

}

void changement_de_vitesse(Motor moteur,Direction direction, float consigne)
{
	int compteur = 5;
	int temps = timer0;
	if(moteur == RIGHT_MOTOR)
	{
		if (/*sens_gauche == true &&*/ direction == FORWARD)
		{
			if (consigne_moteur_nombre_tours_par_seconde_droit < consigne)
			{
				temps = timer0;
				while (consigne_moteur_nombre_tours_par_seconde_droit < consigne)
				{
					compteur+=20;
					while (timer0 != (temps + compteur)){}
					consigne_moteur_nombre_tours_par_seconde_droit += 0.05;
					consigne_moteur_nombre_tours_par_seconde_gauche += 0.05;
				}
			}


			else if (consigne_moteur_nombre_tours_par_seconde_droit > consigne)
			{
				temps = timer0;
				while (consigne_moteur_nombre_tours_par_seconde_droit > consigne)
				{
					compteur+=20;
					while (timer0 != (temps + compteur)){}
					consigne_moteur_nombre_tours_par_seconde_droit -= 0.05;
					consigne_moteur_nombre_tours_par_seconde_gauche -= 0.05;
					if (consigne_moteur_nombre_tours_par_seconde_droit < 0)
					{
						consigne_moteur_nombre_tours_par_seconde_droit = 0;
					}
					if (consigne_moteur_nombre_tours_par_seconde_gauche < 0)
					{
						consigne_moteur_nombre_tours_par_seconde_gauche = 0;
					}
				}
			}
		}
	}
}
