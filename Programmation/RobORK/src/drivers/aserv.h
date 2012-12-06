#ifndef ASERV_H_
#define ASERV_H_

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include "uart.h"
#include "timer.h"
#include "pwm.h"
#include "motors.h"
#include "codeur.h"

extern volatile int timer_ms;
extern volatile int tick_codeuse_gauche;
extern volatile int tick_codeuse_droit;

extern void asservisement_vitesse_gauche(void);
extern void asservisement_vitesse_droit(void);

#endif /* ASERV_H_ */
