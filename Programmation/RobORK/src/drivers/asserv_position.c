#include "asserv_position.h"

const float taille_roue = 50; // en mm
const float correcteur_angle = 1.4;  // a affiner avec plusieurs tours
const float correcteur_distance = 3; // a affiner avec une longue distance
const float angle_initial = 0;


volatile float angle = 0;
volatile float distance = 0;



void mesure_position(void)
{
	float position_roue_D = taille_roue * (float)tick_position_droit / ((float)rapport_reducteur * (float)tick_par_tour_codeuse);
	float position_roue_G = taille_roue * (float)tick_position_gauche / ((float)rapport_reducteur * (float)tick_par_tour_codeuse);
	distance = correcteur_distance * (position_roue_D + position_roue_G) / 2.;

}


void mesure_angle(void)
{
	float position_roue_D = taille_roue * (float)tick_position_droit / ((float)rapport_reducteur * (float)tick_par_tour_codeuse);
	float position_roue_G = taille_roue * (float)tick_position_gauche / ((float)rapport_reducteur * (float)tick_par_tour_codeuse);
	angle = angle_initial + correcteur_angle * (position_roue_D - position_roue_G);
}
