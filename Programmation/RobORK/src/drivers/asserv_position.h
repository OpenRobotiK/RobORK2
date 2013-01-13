
#ifndef ASSERV_POSITION_H_
#define ASSERV_POSITION_H_

#include "asserv_vitesse.h"
#include "defines.h"
#include "codeur.h"
#include "math.h"
#include "moove.h"

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
extern volatile float consigne_X;
extern volatile float consigne_Y;

extern volatile float consigne_distance;
extern volatile float consigne_angle;
extern volatile float somme_erreur_angle;
extern volatile float erreur_angle_precedente;
extern volatile float somme_erreur_distance;
extern volatile float erreur_distance_precedente;

extern void mesure_distance(void);
extern void mesure_angle(void);
extern void mesure_position(void);
extern void test_asserv(void);
extern float asservisement_angle(void);
extern float reste_a_parcourir(float X_voulu,float Y_voulu);
extern float reste_en_angle(float angle_voulu);
extern float asservisement_distance(void);
extern void asservi(float commande_distance, float commande_angle);
extern float changement_de_consigne_d_angle (void);
extern void calcul_de_consigne_PID(void);

#endif /* ASSERV_POSITION_H_ */


