
#ifndef ASSERV_POSITION_H_
#define ASSERV_POSITION_H_

#include "asserv_vitesse.h"
#include "defines.h"
#include "codeur.h"
#include "math.h"

extern const int rapport_reducteur;          // Rapport entre le nombre de tours de l'arbre moteur et de la roue
extern const int tick_par_tour_codeuse;      // Nombre de tick codeuse par tour de l'arbre moteur
extern volatile int tick_position_gauche;
extern volatile int tick_position_droit;

extern const float taille_roue; // en mm
extern const float correcteur_angle;  // a affiner avec plusieurs tours
extern const float correcteur_distance; // a affiner avec une longue distance
extern const float angle_initial;


extern volatile float angle;
extern volatile float distance;
extern volatile float distance_precedent;
extern volatile float X;
extern volatile float Y;

extern void mesure_distance(void);
extern void mesure_angle(void);
extern void mesure_position(void);

#endif /* ASSERV_POSITION_H_ */


