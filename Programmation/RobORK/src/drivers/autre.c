#include "autre.h"

void init_jack(void)
{
	LPC_GPIO0->FIOMASK=0xFFFFFFfb;
	LPC_GPIO0->FIODIR0 &=0xfb;
	LPC_PINCON->PINSEL0 &= 0xFFFFFF3F;
}

bool attendre_jack(void)
{


	if (LPC_GPIO0->FIOPIN0 || 0x4 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}
