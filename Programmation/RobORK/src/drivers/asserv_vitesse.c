
#include "asserv_vitesse.h"

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

volatile int consigne_vitesse_droit_n_1 = 0;
volatile int consigne_vitesse_gauche_n_1 = 0;


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

	if(pwm < -100)
	{
		pwm = -100;
	}
	else if(pwm > 100)
	{
		pwm = 100;
	}
	nombre_a_regarder = (int)tick;
	asserv = true;
	modifie_pwm_gauche(filtre_passe_bas_PID_vitesse_gauche(pwm));
	//PWM_SetDutyCycle(PWM2,(int)pwm );
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

	if(pwm < -100)
	{
		pwm = -100;
	}
	else if(pwm > 100)
	{
		pwm = 100;
	}
	modifie_pwm_droit(filtre_passe_bas_PID_vitesse_droit(pwm));
	//PWM_SetDutyCycle(PWM1,(int)pwm );
}


void modifie_pwm_gauche(int pwm)
{
	if (pwm >= 0)
	{
		LPC_GPIO0->FIOSET |= (1 << 22);//|= (1<<7); //p0.22 INa
		LPC_GPIO0->FIOCLR |= (1 << 21);//|= (1<<4); //p0.27 INb
		LPC_GPIO0->FIOSET |= (1 << 3); //p0.28 DIAG
		roue_gauche_avant = true;
		PWM_SetDutyCycle(PWM2,abs(pwm));
	}
	else
	{
		LPC_GPIO0->FIOCLR |= (1 << 22);//|= (1<<7); //p0.22 INa
		LPC_GPIO0->FIOSET |= (1 << 21);//|= (1<<4); //p0.27 INb
		LPC_GPIO0->FIOSET |= (1 << 3); //p0.28 DIAG
		roue_gauche_avant = false;
		PWM_SetDutyCycle(PWM2,abs(pwm));
	}
}

void modifie_pwm_droit(int pwm)
{
	if (pwm >= 0)
	{
		LPC_GPIO2->FIOCLR0 |= (1 << 6) ; // P2.6 is set to 1. InA
		LPC_GPIO2->FIOSET0 |= (1 << 7 ); //P2.7 is set to 0. InB
		LPC_GPIO2->FIOSET1 |= (1 << 0); //P2.8 is set to 1. Diag
		roue_droite_avant = true;
		PWM_SetDutyCycle(PWM1,abs(pwm));
	}
	else
	{
		LPC_GPIO2->FIOSET0 |= (1 << 6) ; // P2.6 is set to 1. InA
		LPC_GPIO2->FIOCLR0 |= (1 << 7 ); //P2.7 is set to 0. InB
		LPC_GPIO2->FIOSET1 |= (1 << 0); //P2.8 is set to 1. Diag
		roue_droite_avant = false;
		PWM_SetDutyCycle(PWM1,abs(pwm));
	}
}


int filtre_passe_bas_PID_vitesse_droit(float consigne)
{
	int delta_pwm = consigne - consigne_vitesse_droit_n_1;
	if (delta_pwm >= PENTE_PWM)
	{
		consigne += PENTE_PWM;
		consigne_vitesse_droit_n_1 = consigne;
		return consigne;
	}
	else if (delta_pwm <= -PENTE_PWM)
	{
		consigne -= PENTE_PWM;
		consigne_vitesse_droit_n_1 = consigne;
		return consigne;
	}
	else
	{
		consigne_vitesse_droit_n_1 = consigne;
		return consigne;
	}
}

int filtre_passe_bas_PID_vitesse_gauche(float consigne)
{
	int delta_pwm = consigne - consigne_vitesse_gauche_n_1;
	if (delta_pwm >= PENTE_PWM)
	{
		consigne += PENTE_PWM;
		consigne_vitesse_gauche_n_1 = consigne;
		return consigne;
	}
	else if (delta_pwm <= -PENTE_PWM)
	{
		consigne -= PENTE_PWM;
		consigne_vitesse_gauche_n_1 = consigne;
		return consigne;
	}
	else
	{
		consigne_vitesse_gauche_n_1 = consigne;
		return consigne;
	}
}
