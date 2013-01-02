#include "asserv_position.h"

const float taille_roue = 50; // en mm
const float correcteur_angle = 1.4;  // a affiner avec plusieurs tours
const float correcteur_distance = 3; // a affiner avec une longue distance
const float angle_initial = 0;

const float vitesse_angle_max = 0.5;
const float kp_angle = 0.01;
const float ki_angle = 0.001;//0.00001;
const float kd_angle = 0;//0.01;
const float vitesse_distance_max = 0.5;
const float kp_distance = 0.01;
const float ki_distance = 0.001;
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
	angle = (angle / 360 - (int)(angle / 360)) * 360;
	if (angle < 0)
	{
		angle = 360 + angle;
	}
	if (angle >= 360)
	{
		angle = angle - 360;
	}
}

void mesure_position(void)
{
	float vitesse = distance - distance_precedent;
	distance_precedent = distance;
	float delta_X = vitesse * sin(angle * 2 * 3.141592654 / 360);
	float delta_Y = vitesse * cos(angle * 2 * 3.141592654 / 360);
	X = X + delta_X;
	Y = Y + delta_Y;

	if (distance < 5 && -5 < distance)
	{
		//arret_moteur();
	}
	else
	{
		if ((Y-consigne_Y) >= 0)
		{
			consigne_angle = atanf((X-consigne_X)/(Y-consigne_Y)) * 360 / (2 * 3.141592654);
			if (-180 <= consigne_angle && consigne_angle < 0)
			{
				consigne_angle = 360 + consigne_angle;
			}
		}
		else
		{
			consigne_angle = atanf((X-consigne_X)/(Y-consigne_Y)) * 360 / (2 * 3.141592654) + 180;
			if (-180 <= consigne_angle && consigne_angle < 0)
			{
				consigne_angle = 360 + consigne_angle;
			}
		}
	}
	//consigne_angle += 180;
}

void test_asserv(void)
{
	/*if (Y > 200)
	{
		marche_arriere(0.25);
	}
	else if (Y < 195)
	{
		marche_avant(0.25);
	}
	else
	{
		arret_moteur();
	}*/
	//float angle_voulu = 0;
	//float delta = 2;
	float commande = 0;
	float erreur = reste_en_angle(consigne_angle);
	somme_erreur_angle += erreur;
	float delta_erreur_angle = erreur - erreur_angle_precedente;
	erreur_angle_precedente = erreur;
	/* il faudra borner ki * somme_erreur_angle pour ne pas diverger ou le viré mais attention l'erreur statique n'est plus nulle */
	commande = kp_angle * erreur + ki_angle * somme_erreur_angle + kd_angle * delta_erreur_angle;

	/*if ((angle > (consigne_angle + delta)) && (angle <= (180 + consigne_angle)))
	{
		//tourne_gauche(0.25);
		changement_de_vitesse_des_roues(commande,-commande);

	}
	else if ((angle < consigne_angle- delta) || (angle > (180 + consigne_angle)))
	{
		//tourne_droite(0.25);
		changement_de_vitesse_des_roues(commande,-commande);
	}
	else
	{
		arret_moteur();
	}*/
	if (commande > 2)
	{
		commande = 2;
	}
	if(commande < -2)
	{
		commande = -2;
	}
	changement_de_vitesse_des_roues((-commande),commande);
}

float asservisement_angle(void)
{
	float commande = 0;
	erreur_angle = reste_en_angle(consigne_angle);
	somme_erreur_angle += erreur_angle;
	float delta_erreur_angle = erreur_angle - erreur_angle_precedente;
	erreur_angle_precedente = erreur_angle;
	/* il faudra borner ki * somme_erreur_angle pour ne pas diverger ou le viré mais attention l'erreur statique n'est plus nulle */
	commande = kp_angle * erreur_angle + ki_angle * somme_erreur_angle + kd_angle * delta_erreur_angle;

	if (commande > vitesse_angle_max)
	{
		commande = vitesse_angle_max;
	}
	if(commande < (-vitesse_angle_max))
	{
		commande = (-vitesse_angle_max);
	}
	return commande;
	//changement_de_vitesse_des_roues((-commande),commande);
}

float reste_a_parcourir(float X_voulu,float Y_voulu)
{
	float resultat = fabs(sqrtf((X - X_voulu) * (X - X_voulu) + (Y - Y_voulu) * (Y - Y_voulu)));
	/*if (resultat < 30)
	{
		return 0;
	}
	else
	{//*/
		return resultat;
	//}
}

float reste_en_angle(float angle_voulu)
{
	if (angle_voulu < angle && angle < 180 + angle_voulu)
	{
		return angle - angle_voulu;
	}
	else if (0 < angle && angle < angle_voulu)
	{
		return angle - angle_voulu;
	}
	else if (angle_voulu + 180 < angle && angle < 360)
	{
		return angle - 360 - angle_voulu;
	}
	else
	{
		return 0;
	}
}

float asservisement_distance(void)
{
	float commande_distance = 0;
	erreur_distance = reste_a_parcourir(consigne_X,consigne_Y);
	somme_erreur_distance += erreur_distance;
	float delta_erreur_distance = erreur_distance - erreur_distance_precedente;
	erreur_distance_precedente = erreur_distance;
	/* il faudra borner ki * somme_erreur_angle pour ne pas diverger ou le viré mais attention l'erreur statique n'est plus nulle */
	commande_distance = kp_distance * erreur_distance + ki_distance * somme_erreur_distance + kd_distance * delta_erreur_distance;

	if (commande_distance > vitesse_distance_max)
	{
		commande_distance = vitesse_distance_max;
	}
	if(commande_distance < (-vitesse_distance_max))
	{
		commande_distance = (-vitesse_distance_max);
	}
	if (delta_erreur_distance < 0)
	{
		return commande_distance;
	}
	else
	{
		return (commande_distance);
	}
		//changement_de_vitesse_des_roues((-commande_distance),(-commande_distance));
}


void asservi(float commande_distance, float commande_angle)
{
	if (erreur_angle < 15 && -15 < erreur_angle)
	{
		if (erreur_distance < 5 && -5 < erreur_distance)
		{
			arret_moteur();
		}
		else
		{
			changement_de_vitesse_des_roues((-commande_distance),(-commande_distance));
		}
	}
	else
	{
		if (erreur_distance < 5 && -5 < erreur_distance)
		{
			arret_moteur();
		}
		else
		{
			changement_de_vitesse_des_roues((-commande_angle),commande_angle);
		}

	}

	//changement_de_vitesse_des_roues((-commande_distance-commande_angle),(-commande_distance+commande_angle));
}
