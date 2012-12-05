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
extern volatile bool avance, recule, gauche, droite, stop, regle_vitesse,propo, inte, dervi;
extern volatile bool demo_mode;
extern volatile int timer0;
extern volatile bool test ;
extern volatile int tick_codeuse;
extern volatile int timer_ms;
extern volatile float consigne_moteur_nombre_tours_par_seconde;
extern volatile bool asserv;
extern volatile int nombre_a_regarder;
extern volatile float kp ;           // Coefficient proportionnel
extern volatile float ki ;           // Coefficient intégrateur
extern volatile float kd ;           // Coefficient dérivateur

#endif /* DEFINES_H_ */
