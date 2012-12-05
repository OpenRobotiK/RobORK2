
#include "aserv.h"

volatile float frequence_echantillonnage = 10;  // Fréquence du pid 10ms
volatile int rapport_reducteur = 35;          // Rapport entre le nombre de tours de l'arbre moteur et de la roue
volatile int tick_par_tour_codeuse = 7;      // Nombre de tick codeuse par tour de l'arbre moteur

volatile float consigne_moteur_nombre_tours_par_seconde = 5;  //  Nombre de tours de roue par seconde

volatile float erreur_precedente = 0; // doit etre egale au nombre de tours de roue par seconde
volatile float somme_erreur = 0;   // Somme des erreurs pour l'intégrateur
volatile int cmd_max = 10; //consigne max a mesurer
volatile float kp = 40;           // Coefficient proportionnel
volatile float ki = 75;           // Coefficient intégrateur
volatile float kd = 50;           // Coefficient dérivateur

volatile bool asserv=false;
volatile int nombre_a_regarder=0;

void asservisement_vitesse_gauche(void)
{
	int cmd = 0, pwm = 0; //commande
	// Réinitialisation du nombre de tick de la codeuse
	int tick = tick_codeuse;
	tick_codeuse=0;

	// Calcul des erreurs
	float frequence_codeuse = frequence_echantillonnage*tick; //pas par tour
	float nb_tour_par_sec = (float)frequence_codeuse / 245;//(float)tick_par_tour_codeuse / (float)rapport_reducteur;
	float erreur = consigne_moteur_nombre_tours_par_seconde - nb_tour_par_sec;
	somme_erreur += erreur;
	float delta_erreur = erreur - erreur_precedente;
	erreur_precedente = erreur;

	// PID : calcul de la commande
	cmd = kp*erreur + ki*somme_erreur + kd*delta_erreur;
	//cmd=-cmd;
	// Normalisation et contrôle du moteur
	pwm = cmd / cmd_max;
	nombre_a_regarder=(int)tick;
	if(pwm < 0)
		{
			pwm=0;
		}
	else if(pwm > 100)
		{
			pwm = 100;
		}
	//nombre_a_regarder=(int)frequence_codeuse/10;
	asserv=true;
	PWM_SetDutyCycle(PWM2,(int)pwm );
}

