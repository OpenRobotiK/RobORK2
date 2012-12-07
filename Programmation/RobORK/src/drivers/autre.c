#include "autre.h"

void init_jack(void)
{
	LPC_GPIO0->FIOMASK0  = (0<<2);
	//LPC_GPIO0->FIODIR0 &=0x04;
	//LPC_PINCON->PINSEL0 &= 0xFFFFFFCF;
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
