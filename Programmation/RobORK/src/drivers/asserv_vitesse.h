#ifndef ASSERV_VITESSE_H_
#define ASSERV_VITESSE_H_

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include "uart.h"
#include "timer.h"
#include "pwm.h"
#include "motors.h"
#include "codeur.h"

extern const float frequence_echantillonnage;  // Fréquence du pid 10ms
extern const int rapport_reducteur;          // Rapport entre le nombre de tours de l'arbre moteur et de la roue
extern const int tick_par_tour_codeuse;      // Nombre de tick codeuse par tour de l'arbre moteur

extern volatile float consigne_moteur_nombre_tours_par_seconde_gauche;  //  Nombre de tours de roue par seconde
extern volatile float consigne_moteur_nombre_tours_par_seconde_droit;  //  Nombre de tours de roue par seconde

extern volatile float erreur_precedente_gauche; // doit etre egale au nombre de tours de roue par seconde
extern volatile float somme_erreur_gauche;   // Somme des erreurs pour l'intégrateur

extern volatile float erreur_precedente_droit; // doit etre egale au nombre de tours de roue par seconde
extern volatile float somme_erreur_droit;   // Somme des erreurs pour l'intégrateur

extern const float kp;          // Coefficient proportionnel
extern const float ki;           // Coefficient intégrateur
extern const float kd;           // Coefficient dérivateur

extern volatile bool asserv;
extern volatile int nombre_a_regarder;


extern void asservisement_vitesse_gauche(void);
extern void asservisement_vitesse_droit(void);

#endif /* ASSERV_VITESSE_H_ */
