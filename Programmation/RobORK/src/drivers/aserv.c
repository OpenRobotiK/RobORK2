
#include "aserv.h"

volatile float frequence_echantillonnage = 0.01;  // Fréquence du pid 10ms
volatile int rapport_reducteur = 35;          // Rapport entre le nombre de tours de l'arbre moteur et de la roue
volatile int tick_par_tour_codeuse = 7;      // Nombre de tick codeuse par tour de l'arbre moteur

volatile float consigne_moteur_nombre_tours_par_seconde = 5.;  //  Nombre de tours de roue par seconde

volatile float erreur_precedente = 5.; // doit etre egale au nombre de tours de roue par seconde
volatile float somme_erreur = 0;   // Somme des erreurs pour l'intégrateur
volatile int cmd_max ; //consigne max a mesurer
volatile float kp = 300;           // Coefficient proportionnel
volatile float ki = 5.5;           // Coefficient intégrateur
volatile float kd = 100;           // Coefficient dérivateur

void asservisement_vitesse_gauche(void)
{
	int cmd = 0, pwm = 0; //commande
	// Réinitialisation du nombre de tick de la codeuse
	int tick = tick_codeuse;
	tick_codeuse=0;

	// Calcul des erreurs
	float frequence_codeuse = frequence_echantillonnage*tick;
	float nb_tour_par_sec = (float)frequence_codeuse / (float)tick_par_tour_codeuse / (float)rapport_reducteur;
	float erreur = consigne_moteur_nombre_tours_par_seconde - nb_tour_par_sec;
	somme_erreur += erreur;
	float delta_erreur = erreur - erreur_precedente;
	erreur_precedente = erreur;

	// PID : calcul de la commande
	cmd = kp*erreur + ki*somme_erreur + kd*delta_erreur;

	// Normalisation et contrôle du moteur
	pwm = cmd / cmd_max * 100;
	if(pwm < 0)
		{
			pwm=0;
		}
	else if(pwm > 100)
		{
			pwm = 100;
		}

}

