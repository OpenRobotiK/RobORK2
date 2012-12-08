#ifndef CODEUR_H_
#define CODEUR_H_

#include "LPC17xx.h"
#include "defines.h"
#include "uart.h"


typedef enum codeur codeur;
enum codeur
{ codeur_droit, codeur_gauche};

#define EINT0			0x00000001
#define EINT1			0x00000002
#define EINT2			0x00000004
#define EINT3			0x00000008

#define EINT0_EDGE		0x00000001
#define EINT1_EDGE		0x00000002
#define EINT2_EDGE		0x00000004
#define EINT3_EDGE		0x00000008

#define EINT0_RISING	0x00000001
#define EINT1_RISING	0x00000002
#define EINT2_RISING	0x00000004
#define EINT3_RISING	0x00000008

#define SELECT_EINT0	0x00100000
#define SELECT_EINT1	0x00400000
#define SELECT_EINT2	0x01000000
#define SELECT_EINT3	0x04000000

#define CLEAR_EINT0		0x00000400
#define CLEAR_EINT1		0x00000800
#define CLEAR_EINT2		0x00001000
#define CLEAR_EINT3		0x00002000

extern void EINT3_IRQHandler(void);
extern bool EINT3Init( void );
extern void EINT2_IRQHandler(void);
extern bool EINT2Init( void );
extern void EINT1_IRQHandler(void);
extern bool EINT1Init( void );
extern void EINT0_IRQHandler(void);
extern bool EINT0Init( void );
extern bool init_interrupt_codeur(void);
extern bool init_codeur(void);

#endif /* CODEUR_H_ */
