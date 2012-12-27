
#ifndef ASSERV_POSITION_H_
#define ASSERV_POSITION_H_

#include "asserv_vitesse.h"
#include "defines.h"
#include "codeur.h"

extern const int rapport_reducteur;          // Rapport entre le nombre de tours de l'arbre moteur et de la roue
extern const int tick_par_tour_codeuse;      // Nombre de tick codeuse par tour de l'arbre moteur
extern volatile int tick_position_gauche;
extern volatile int tick_position_droit;
extern volatile float angle;
extern volatile float distance;

extern void mesure_position(void);
extern void mesure_angle(void);


#endif /* ASSERV_POSITION_H_ */


