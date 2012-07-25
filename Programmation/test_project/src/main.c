/** \addtogroup robORK
 *
 * @{
 *
 *
 *
 * \defgroup main main
 * @{
 *
 * \file main.c
 * \brief main
 * \date Created: 13/07/2012
 * \author Lyphout Florent et Maël Gaudy
 *
 */



#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>
#include "UART.h"


#define Board_led_port LPC_GPIO0->FIOPIN
#define Board_led_DIR LPC_GPIO0->FIODIR
#define Board_led_bit 11



// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {
	


	/********** mettre des leds a un **************/
	LPC_PINCON->PINSEL0 = 0x00000000;
	LPC_GPIO0->FIODIR = 0xFFFFFFFF;
	LPC_GPIO0->FIOMASK = 0x00000000; // The mask^^
	LPC_GPIO0->FIOSET |= (1<<8);//|(1<<8);


	/* test uart*/
	char buf[3]={'a','b','\0'};

	UARTInit( 3, 9600 );	//fonctionne
	UARTSend( 3, buf, 3 );	// fonctionne
	//uart3 U3IER=1;
	UART3_IRQHandler();		// ne sais pas trop ce que c'est je pense que
	//c'est pour validé l'interruption mais je ne sais pas comment declarer cette
	// interruption.



	/*fin test uart*/

	// Enter an infinite loop, just incrementing a counter
	volatile static int i = 0 ;
	while(1) {
		i++ ;
	}
	return 0 ;
}



/**
 * @}
 * @}
 */
