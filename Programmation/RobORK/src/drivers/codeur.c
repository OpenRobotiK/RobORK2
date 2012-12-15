#include "codeur.h"



volatile uint32_t eint0_counter;
volatile bool test = false;
volatile int tick_codeuse_gauche = 0;
volatile int tick_codeuse_droit = 0;
volatile bool sens_droit = false;
volatile bool sens_gauche = false;

void EINT3_IRQHandler (void)
{
	//LPC_GPIO0->FIOMASK0  = 0x00;
	if ((LPC_GPIO0->FIOPIN0 & 0x20) == 0x20)
	{
		sens_droit = true;
	}
	else
	{
		sens_droit = false;
	}

	if ((LPC_SC->EXTPOLAR & EINT3_RISING) == EINT3_RISING)
	{
		LPC_SC->EXTPOLAR &= ~EINT3_RISING;
	}
	else
	{
		LPC_SC->EXTPOLAR |= EINT3_RISING;
	}

	//test=true;
	tick_codeuse_gauche++;
	/* clear interrupt */
	LPC_SC->EXTINT |= EINT3;	//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT3;	//clear l'interruption sur pin
	/* fin de clear interrupt */
}

bool EINT3Init( void )
{
	LPC_PINCON->PINSEL4 |= SELECT_EINT3;	//active la pin
	//LPC_SC->EXTMODE |= EINT3_EDGE;
	LPC_SC->EXTMODE |= EINT3_EDGE;	//choix sur niveau ou sur front
	LPC_SC->EXTPOLAR |= EINT3_RISING;	//choix sur quel niveau (haut ou bas)


	/* clear interrupt */
	LPC_SC->EXTINT |= EINT3;	//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT3;	//clear l'interruption sur pin
	/* fin de clear interrupt */
	NVIC_EnableIRQ(EINT3_IRQn);	//active l'interruption
	//EINT3_IRQHandler();
	return( true );
}



void EINT2_IRQHandler (void)
{
	if ((LPC_GPIO0->FIOPIN0 & 0x10) == 0x10)
		{
			sens_gauche = true;
		}
		else
		{
			sens_gauche = false;
		}

	if ((LPC_SC->EXTPOLAR & EINT2_RISING) == EINT2_RISING)
		{
			LPC_SC->EXTPOLAR &= ~EINT2_RISING;
		}
		else
		{
			LPC_SC->EXTPOLAR |= EINT2_RISING;
		}

	tick_codeuse_droit++;
	/* clear interrupt */
	LPC_SC->EXTINT |= EINT2;	//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT2;	//clear l'interruption sur pin
	/* fin de clear interrupt */
}

bool EINT2Init( void )
{
	LPC_PINCON->PINSEL4 |= SELECT_EINT2;	//active la pin
	//LPC_SC->EXTMODE |= EINT3_EDGE;
	LPC_SC->EXTMODE |= EINT2_EDGE;;	//choix sur niveau ou sur front
	LPC_SC->EXTPOLAR |= EINT2_RISING;	//choix sur quel niveau (haut ou bas)


	/* clear interrupt */
	LPC_SC->EXTINT |= EINT2;	//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT2;	//clear l'interruption sur pin
	/* fin de clear interrupt */
	NVIC_EnableIRQ(EINT2_IRQn);	//active l'interruption
	//EINT3_IRQHandler();
	return( true );
}



void EINT1_IRQHandler (void)
{
	test=true;

	/* clear interrupt */
	LPC_SC->EXTINT |= EINT1;	//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT1;	//clear l'interruption sur pin
	/* fin de clear interrupt */
}

bool EINT1Init( void )
{
	LPC_PINCON->PINSEL4 |= SELECT_EINT1;	//active la pin
	//LPC_SC->EXTMODE |= EINT3_EDGE;
	LPC_SC->EXTMODE |= EINT1_EDGE;	//choix sur niveau ou sur front
	LPC_SC->EXTPOLAR |= EINT1_RISING;	//choix sur quel niveau (haut ou bas)


	/* clear interrupt */
	LPC_SC->EXTINT |= EINT1;	//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT1;	//clear l'interruption sur pin
	/* fin de clear interrupt */
	NVIC_EnableIRQ(EINT1_IRQn);	//active l'interruption
	//EINT3_IRQHandler();
	return( true );
}



void EINT0_IRQHandler (void)
{
	test=true;

	/* clear interrupt */
	LPC_SC->EXTINT |= EINT0;	//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT0;	//clear l'interruption sur pin
	/* fin de clear interrupt */
}

bool EINT0Init( void )
{
	LPC_PINCON->PINSEL4 |= SELECT_EINT0;	//active la pin
	//LPC_SC->EXTMODE |= EINT3_EDGE;
	LPC_SC->EXTMODE |= EINT0_EDGE;	//choix sur niveau ou sur front
	LPC_SC->EXTPOLAR |= EINT0_RISING;	//choix sur quel niveau (haut ou bas)


	/* clear interrupt */
	LPC_SC->EXTINT |= EINT0;	//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT0;	//clear l'interruption sur pin
	/* fin de clear interrupt */
	NVIC_EnableIRQ(EINT0_IRQn);	//active l'interruption
	//EINT3_IRQHandler();
	return( true );
}



bool init_interrupt_codeur(void)
{
	bool interrupt2 = false, interrupt3 = false;


	interrupt2 = EINT2Init();
	interrupt3 = EINT3Init();
	//EINT0Init();


	if (interrupt2 == true && interrupt3 == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool init_codeur(void)
{
	init_interrupt_codeur();
	LPC_GPIO0->FIOMASK0  = 0x00;
	LPC_PINCON->PINSEL0 &= 0xFFFFF0FF;
	LPC_GPIO0->FIODIR0 &= 0xCF;
	return true;
}
