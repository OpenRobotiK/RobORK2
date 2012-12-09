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


void changement_de_vitesse (Motor moteur,int vitesse)
{
  /*float i = consigne_moteur_nombre_tours_par_seconde_droit;

  if (consigne_moteur_nombre_tours_par_seconde_droit <= vitesse)
    {
      for (i = consigne_moteur_nombre_tours_par_seconde_droit ; i<= vitesse; i=i+0.0005)
      {
        consigne_moteur_nombre_tours_par_seconde_droit = i;
        consigne_moteur_nombre_tours_par_seconde_gauche = i;
      }
    }
  else
    {
      for (i = consigne_moteur_nombre_tours_par_seconde_droit ; i>=vitesse ; i=i-0.0005)
      {
        consigne_moteur_nombre_tours_par_seconde_droit = i;
        consigne_moteur_nombre_tours_par_seconde_gauche = i;
      }
    }*/
}
