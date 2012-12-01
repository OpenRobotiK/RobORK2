#include "codeur.h"



volatile uint32_t eint0_counter;
volatile bool test = false;



void EINT3_IRQHandler (void)
{
	test=true;

	/* clear interrupt */
	LPC_SC->EXTINT |= EINT3;			//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT3;	//clear l'interruption sur pin
	/* fin de clear interrupt */
}

bool EINT3Init( void )
{
	LPC_PINCON->PINSEL4 |= SELECT_EINT3;		//active la pin
	//LPC_SC->EXTMODE |= EINT3_EDGE;
	LPC_SC->EXTMODE |= EINT3_EDGE;				//choix sur niveau ou sur front
	LPC_SC->EXTPOLAR |= 0;				//choix sur quel niveau (haut ou bas)


	/* clear interrupt */
	LPC_SC->EXTINT |= EINT3;			//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT3;	//clear l'interruption sur pin
	/* fin de clear interrupt */
	NVIC_EnableIRQ(EINT3_IRQn);			//active l'interruption
	//EINT3_IRQHandler();
	return( true );
}



void EINT2_IRQHandler (void)
{
	test=true;

	/* clear interrupt */
	LPC_SC->EXTINT |= EINT2;			//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT2;	//clear l'interruption sur pin
	/* fin de clear interrupt */
}

bool EINT2Init( void )
{
	LPC_PINCON->PINSEL4 |= SELECT_EINT2;		//active la pin
	//LPC_SC->EXTMODE |= EINT3_EDGE;
	LPC_SC->EXTMODE = 0;				//choix sur niveau ou sur front
	LPC_SC->EXTPOLAR |= EINT2_RISING;	//choix sur quel niveau (haut ou bas)


	/* clear interrupt */
	LPC_SC->EXTINT |= EINT2;			//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT2;	//clear l'interruption sur pin
	/* fin de clear interrupt */
	NVIC_EnableIRQ(EINT2_IRQn);			//active l'interruption
	//EINT3_IRQHandler();
	return( true );
}



void EINT1_IRQHandler (void)
{
	test=true;

	/* clear interrupt */
	LPC_SC->EXTINT |= EINT1;			//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT1;	//clear l'interruption sur pin
	/* fin de clear interrupt */
}

bool EINT1Init( void )
{
	LPC_PINCON->PINSEL4 |= SELECT_EINT1;		//active la pin
	//LPC_SC->EXTMODE |= EINT3_EDGE;
	LPC_SC->EXTMODE = 0;				//choix sur niveau ou sur front
	LPC_SC->EXTPOLAR |= EINT1_RISING;	//choix sur quel niveau (haut ou bas)


	/* clear interrupt */
	LPC_SC->EXTINT |= EINT1;			//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT1;	//clear l'interruption sur pin
	/* fin de clear interrupt */
	NVIC_EnableIRQ(EINT1_IRQn);			//active l'interruption
	//EINT3_IRQHandler();
	return( true );
}



void EINT0_IRQHandler (void)
{
	test=true;

	/* clear interrupt */
	LPC_SC->EXTINT |= EINT0;			//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT0;	//clear l'interruption sur pin
	/* fin de clear interrupt */
}

bool EINT0Init( void )
{
	LPC_PINCON->PINSEL4 |= SELECT_EINT0;		//active la pin
	//LPC_SC->EXTMODE |= EINT3_EDGE;
	LPC_SC->EXTMODE = 0;				//choix sur niveau ou sur front
	LPC_SC->EXTPOLAR |= EINT0_RISING;	//choix sur quel niveau (haut ou bas)


	/* clear interrupt */
	LPC_SC->EXTINT |= EINT0;			//clear l'interruption
	LPC_GPIOINT->IO2IntClr |= CLEAR_EINT0;	//clear l'interruption sur pin
	/* fin de clear interrupt */
	NVIC_EnableIRQ(EINT0_IRQn);			//active l'interruption
	//EINT3_IRQHandler();
	return( true );
}



bool init_interrupt_codeur(void)
{
	bool interrupt0 = false,interrupt1 = false,interrupt2 = false,interrupt3 = false;

	interrupt0 = EINT0Init();
	interrupt1 = EINT1Init();
	interrupt2 = EINT2Init();
	interrupt3 = EINT3Init();

	if (interrupt0 == true && interrupt1 == true && interrupt2 == true && interrupt3 == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
