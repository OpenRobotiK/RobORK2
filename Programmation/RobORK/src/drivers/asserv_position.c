#include "asserv_position.h"

const float taille_roue = 50; // en mm
const float correcteur_angle = 1.4;  // a affiner avec plusieurs tours
const float correcteur_distance = 3; // a affiner avec une longue distance
const float angle_initial = 0;


volatile float angle = 0;
volatile float distance = 0;
volatile float distance_precedent = 0;
volatile float X = 0;
volatile float Y = 0;

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
	float angle_voulu = 60;
	float delta = 1;

	if ((angle > (angle_voulu + delta)) && (angle <= (180 + angle_voulu)))
	{
		tourne_gauche(0.25);
	}
	else if ((angle < angle_voulu - delta) || (angle > (180 + angle_voulu)))
	{
		tourne_droite(0.25);
	}
	else
	{
		arret_moteur();
	}
}
