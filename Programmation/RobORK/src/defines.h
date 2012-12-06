/*
 * defines.h
 *
 *  Created on: 24 nov. 2012
 *      Author: mael
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <stdlib.h>

typedef enum bool bool;
enum bool{ true, false};

extern char commande[255];
extern volatile bool validation;
extern volatile bool avance, recule, gauche, droite, stop, regle_vitesse;
extern volatile bool demo_mode;
extern volatile int timer0;
extern volatile bool test ;

extern volatile int timer_ms;
extern volatile float consigne_moteur_nombre_tours_par_seconde_gauche;
extern volatile bool asserv;
extern volatile int nombre_a_regarder;

extern volatile float erreur_precedente_gauche; // doit etre egale au nombre de tours de roue par seconde
extern volatile float somme_erreur_gauche;
extern volatile float erreur_precedente_droit; // doit etre egale au nombre de tours de roue par seconde
extern volatile float somme_erreur_droit;

#endif /* DEFINES_H_ */
