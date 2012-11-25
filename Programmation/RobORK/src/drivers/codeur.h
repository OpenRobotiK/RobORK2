#ifndef CODEUR_H_
#define CODEUR_H_

#include "defines.h"

typedef enum codeur codeur;
enum codeur
{ codeur_droit, codeur_gauche};

void init_interrupt_codeur(codeur nom_codeur);
void EINT0_IRQHandler(void);

#endif /* CODEUR_H_ */
