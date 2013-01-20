#include "asserv_position.h"

const float taille_roue = 50; // en mm
const float correcteur_angle = 1.4;  // a affiner avec plusieurs tours
const float correcteur_distance = 3; // a affiner avec une longue distance
const float angle_initial = 0;

const float vitesse_angle_max = 0.5;
const float kp_angle = 0.01;
const float ki_angle = 0.001;//0.00001;
const float kd_angle = 0;//0.01;
const float vitesse_distance_max = 1.5;
const float kp_distance = 0.01;
const float ki_distance = 0;//.001;
const float kd_distance = 0;

volatile float angle = 0;
volatile float distance = 0;
volatile float distance_precedent = 0;
volatile float X = 0;
volatile float Y = 0;

volatile float consigne_X = 0;
volatile float consigne_Y = 0;
volatile float consigne_distance = 0;
volatile float consigne_angle = 0;
volatile float somme_erreur_angle = 0;
volatile float erreur_angle_precedente = 0;
volatile float somme_erreur_distance = 0;
volatile float erreur_distance_precedente = 0;
volatile float erreur_angle_absolue = 0;

volatile float erreur_angle = 0;
volatile float erreur_distance = 0;

void mesure_distance(void)
{
	float position_roue_D = taille_roue * (float)tick_position_droit / ((float)rapport_reducteur * (float)tick_par_tour_codeuse);
	float position_roue_G = taille_roue * (float)tick_position_gauche / ((float)rapport_reducteur * (float)tick_par_tour_codeuse);
	distance = correcteur_distance * (position_roue_D + position_roue_G) / 2;
}

void mesure_angle(void)
{
	float position_roue_D = taille_roue * (float)tick_position_droit / ((float)rapport_reducteur * (float)tick_par_tour_codeuse);
	float position_roue_G = taille_roue * (float)tick_position_gauche / ((float)rapport_reducteur * (float)tick_par_tour_codeuse);
	angle = angle_initial + correcteur_angle * (position_roue_D - position_roue_G);
	angle = ((angle + 180) / 360. - (int)((angle + 180) / 360.)) * 360. - 180;
}

void mesure_position(void)
{
	float vitesse = distance - distance_precedent;
	distance_precedent = distance;
	float delta_X = vitesse * cos(angle * 2 * 3.141592654 / 360);
	float delta_Y = vitesse * sin(angle * 2 * 3.141592654 / 360);
	X = X + delta_X;
	Y = Y + delta_Y;


	//consigne_angle += 180;
}

float changement_de_consigne_d_angle (void)
{
	float delta_X = consigne_X - X;
	float delta_Y = consigne_Y - Y;

	float a = atan2(delta_Y,delta_X) * 180 / PI;
	float b = (a + 180) / 360;
	int c = (int)b;
	a = (b - c) * 360 - 180;
	return a;
}

void test_asserv(void)
{
	/*float commande = 0;
	float erreur = reste_en_angle(consigne_angle);
	somme_erreur_angle += erreur;
	float delta_erreur_angle = erreur - erreur_angle_precedente;
	erreur_angle_precedente = erreur;
	commande = kp_angle * erreur + ki_angle * somme_erreur_angle + kd_angle * delta_erreur_angle;
	if (commande > 2)
	{
		commande = 2;
	}
	if(commande < -2)
	{
		commande = -2;
	}
	changement_de_vitesse_des_roues((-commande),commande);*/
}

float asservisement_angle(void)
{
	float commande = 0;
	erreur_angle_absolue = reste_en_angle(consigne_angle);
	erreur_angle = calcul_angle_relative(erreur_angle_absolue);
	somme_erreur_angle += erreur_angle;
	float delta_erreur_angle = erreur_angle - erreur_angle_precedente;
	erreur_angle_precedente = erreur_angle;
	/* il faudra borner ki * somme_erreur_angle pour ne pas diverger ou le viré mais attention l'erreur statique n'est plus nulle */
	if (ki_angle * somme_erreur_angle > vitesse_angle_max / 4)
	{
		if (somme_erreur_angle >= 0)
		{
			commande = kp_angle * erreur_angle + vitesse_angle_max / 4 + kd_angle * delta_erreur_angle;
		}
		else
		{
			commande = kp_angle * erreur_angle - vitesse_angle_max / 4 + kd_angle * delta_erreur_angle;
		}
		somme_erreur_angle=vitesse_angle_max / 4;
	}
	else
	{
		commande = kp_angle * erreur_angle + ki_angle * somme_erreur_angle + kd_angle * delta_erreur_angle;
	}
	//commande = kp_angle * erreur_angle + ki_angle * somme_erreur_angle + kd_angle * delta_erreur_angle;
	if (commande > vitesse_angle_max)
	{
		commande = vitesse_angle_max;
	}
	if((-commande) > (vitesse_angle_max))
	{
		commande = (-vitesse_angle_max);
	}

	//changement_de_vitesse_des_roues((-commande),(commande));
	return commande;
}

float reste_a_parcourir(float X_voulu,float Y_voulu)
{
	float resultat = sqrtf((X - X_voulu) * (X - X_voulu) + (Y - Y_voulu) * (Y - Y_voulu)) * cos(erreur_angle_absolue);
	return resultat;
}

float reste_en_angle(float angle_voulu)
{
	float a = angle_voulu - angle;
	float b = (a + 180) / 360;
	int c = (int)b;
	a = (b - c) * 360 - 180;
	return a;
}

float asservisement_distance(void)
{
	float commande_distance = 0;
	erreur_distance = reste_a_parcourir(consigne_X,consigne_Y);
	somme_erreur_distance += erreur_distance;
	float delta_erreur_distance = erreur_distance - erreur_distance_precedente;
	erreur_distance_precedente = erreur_distance;
	/* il faudra borner ki * somme_erreur_angle pour ne pas diverger ou le viré mais attention l'erreur statique n'est plus nulle */
	//commande_distance = kp_distance * erreur_distance + ki_distance * somme_erreur_distance + kd_distance * delta_erreur_distance;
	if (ki_distance * somme_erreur_distance > vitesse_distance_max / 4)
	{
		if (somme_erreur_distance >= 0)
		{
			commande_distance = kp_distance * erreur_distance + vitesse_distance_max / 4 + kd_distance * delta_erreur_distance;
		}
		else
		{
			commande_distance = kp_distance * erreur_distance - vitesse_distance_max / 4 + kd_distance * delta_erreur_distance;
		}
		//somme_erreur_angle=0;
	}
	else
	{
		commande_distance = kp_distance * erreur_distance + ki_distance * somme_erreur_distance + kd_distance * delta_erreur_distance;
	}
	if (commande_distance > vitesse_distance_max)
	{
		commande_distance = vitesse_distance_max;
	}
	if(commande_distance < (-vitesse_distance_max))
	{
		commande_distance = (-vitesse_distance_max);
	}

	//return commande_distance;
	//changement_de_vitesse_des_roues((commande_distance),(commande_distance));
	return commande_distance;
}

void asservi(float commande_distance, float commande_angle)
{
	float consigne_moteur_droit, consigne_moteur_gauche;
	consigne_moteur_droit = commande_distance + commande_angle;
	consigne_moteur_gauche = commande_distance - commande_angle;
	consigne_moteur_nombre_tours_par_seconde_droit = consigne_moteur_droit;
	consigne_moteur_nombre_tours_par_seconde_gauche = consigne_moteur_gauche;
	//changement_de_vitesse_des_roues((commande_distance + commande_angle),(commande_distance - commande_angle));
}

void calcul_de_consigne_PID(void)
{
	consigne_angle = changement_de_consigne_d_angle();
	/*if (consigne_angle>90 && consigne_angle<270)
	{
		consigne_distance = reste_a_parcourir(consigne_X,consigne_Y) ;	// le *cos donne un importance plus faible a la distance si l'angle est pas bon
	}
	else
	{
		consigne_distance = reste_a_parcourir(consigne_X,consigne_Y);
	}*/
	consigne_distance = reste_a_parcourir(consigne_X,consigne_Y);
}

void normalise_angle(float* angle)
{
	float a = (*angle + 180) / 360;
	int b = (int)b;
	*angle = (a - b) * 360 - 180;
}

float calcul_angle_relative(float erreur_absolue)
{
	if (-90 < erreur_absolue && erreur_absolue <= 90)
	{
		return erreur_absolue;
	}
	else if (erreur_absolue > 90)
	{
		return erreur_absolue - 180;
	}
	else if (erreur_absolue <= -90)
	{
		return erreur_absolue + 180;
	}
	return 1000;		//erreur si 1000
}



