/*
 * main.h
 *
 *  Created on: 19 oct. 2012
 *      Author: mael
 */

#ifndef MAIN_H_
#define MAIN_H_



#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif


#include <stdlib.h>
#include "motors.h"
#include <cr_section_macros.h>
#include <NXP/crp.h>
#include "UART.h"
#include <string.h>
#include "ADC.h"
#include <stdio.h>

typedef enum Booleen Booleen;
enum Booleen
{False, True};

#define TRUE 1
#define FALSE 0


volatile extern Booleen validation;

#define VITESSE 20

/*#define TRUE		1
#define FALSE		0*/



#define Board_led_port LPC_GPIO0->FIOPIN
#define Board_led_DIR LPC_GPIO0->FIODIR
#define Board_led_bit 11


char commande[255];







extern int avance,recule,gauche,droite,stop;

#endif /* MAIN_H_ */
