/*
 * moove.h
 *
 *  Created on: 27 nov. 2012
 *      Author: mael
 */

#ifndef MOOVE_H_
#define MOOVE_H_


#include "motors.h"

#define pente 0.10 //0.15

extern volatile bool roue_gauche_avant;
extern volatile bool roue_droire_avant;


extern void MOOVE_Init(void);
extern void MOOVE_Direction(Direction direction, int speed);
extern void changement_de_vitesse(Motor moteur, float speed);
extern void marche_avant(float vitesse);
extern void arret_moteur(void);
extern void marche_arriere(float vitesse);
extern void tourne_gauche(float vitesse);
extern void tourne_droite(float vitesse);
extern void virage(float roue_droite, float roue_gauche);
extern void changement_de_vitesse_des_roues(float roue_droite, float roue_gauche);


#endif /* MOOVE_H_ */
