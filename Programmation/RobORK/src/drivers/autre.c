#include "autre.h"

void init_jack(void)
{
	LPC_GPIO0->FIOMASK0  = 0x00;
	PC_PINCON->PINSEL0 &= 0xFFFFFFCF;
	LPC_GPIO0->FIODIR0 &= 0xFB;

}

bool attendre_jack(void)
{
	LPC_GPIO0->FIOMASK0  = 0x00;
	if ((LPC_GPIO0->FIOPIN0 & 0x04) == 0x04)
	{
		return true;
	}
	else
	{
		return false;
	}

}
