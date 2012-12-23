
#include "aserv.h"

const float frequence_echantillonnage = 50;  // Fréquence du pid 10ms
const int rapport_reducteur = 35;          // Rapport entre le nombre de tours de l'arbre moteur et de la roue
const int tick_par_tour_codeuse = 14;      // Nombre de tick codeuse par tour de l'arbre moteur

volatile float consigne_moteur_nombre_tours_par_seconde_gauche = 0;  //  Nombre de tours de roue par seconde
volatile float consigne_moteur_nombre_tours_par_seconde_droit = 0;  //  Nombre de tours de roue par seconde

volatile float erreur_precedente_gauche = 0; // doit etre egale au nombre de tours de roue par seconde
volatile float somme_erreur_gauche = 0;   // Somme des erreurs pour l'intégrateur

volatile float erreur_precedente_droit = 0; // doit etre egale au nombre de tours de roue par seconde
volatile float somme_erreur_droit = 0;   // Somme des erreurs pour l'intégrateur

const float kp = 50;          // Coefficient proportionnel
const float ki = 15;           // Coefficient intégrateur
const float kd = 30;           // Coefficient dérivateur

volatile bool asserv=false;
volatile int nombre_a_regarder=0;

void asservisement_vitesse_gauche(void)
{
	int cmd = 0, pwm = 0; //commande
	// Réinitialisation du nombre de tick de la codeuse
	int tick = tick_codeuse_gauche;
	tick_codeuse_gauche = 0;

	// Calcul des erreurs
	float frequence_codeuse = frequence_echantillonnage*tick; //pas par tour
	float nb_tour_par_sec = (float)frequence_codeuse / ((float)tick_par_tour_codeuse * (float)rapport_reducteur);
	float erreur = consigne_moteur_nombre_tours_par_seconde_gauche - nb_tour_par_sec;
	somme_erreur_gauche += erreur;
	float delta_erreur = erreur - erreur_precedente_gauche;
	erreur_precedente_gauche = erreur;

	// PID : calcul de la commande
	cmd = kp*erreur + ki*somme_erreur_gauche + kd*delta_erreur;
	//cmd=-cmd;
	// Normalisation et contrôle du moteur
	pwm = cmd;

	if(pwm < 0)
	{
		pwm=0;
	}
	else if(pwm > 100)
	{
		pwm = 100;
	}
	nombre_a_regarder = (int)tick;
	asserv = true;
	PWM_SetDutyCycle(PWM2,(int)pwm );
}


void asservisement_vitesse_droit(void)
{
	int cmd = 0, pwm = 0; //commande
	// Réinitialisation du nombre de tick de la codeuse
	int tick = tick_codeuse_droit;
	tick_codeuse_droit = 0;

	// Calcul des erreurs
	float frequence_codeuse = frequence_echantillonnage * tick; //pas par tour
	float nb_tour_par_sec = (float)frequence_codeuse / ((float)tick_par_tour_codeuse * (float)rapport_reducteur);
	float erreur = consigne_moteur_nombre_tours_par_seconde_droit - nb_tour_par_sec;
	somme_erreur_droit += erreur;
	float delta_erreur = erreur - erreur_precedente_droit;
	erreur_precedente_droit = erreur;

	// PID : calcul de la commande
	cmd = kp*erreur + ki*somme_erreur_droit + kd*delta_erreur;
	//cmd=-cmd;
	// Normalisation et contrôle du moteur
	pwm = cmd;

	if(pwm < 0)
	{
		pwm=0;
	}
	else if(pwm > 100)
	{
		pwm = 100;
	}

	PWM_SetDutyCycle(PWM1,(int)pwm );
}
