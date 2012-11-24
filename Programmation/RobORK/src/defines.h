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
extern bool avance, recule, gauche, droite, stop;

#endif /* DEFINES_H_ */
