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
	
	// TODO: insert code here


	//Bit 0, 9, 10 used. Bit 11 LED

	// LPC_GPIO0->FIOMASK
	LPC_PINCON->PINSEL0 = 0x00000000;
	LPC_GPIO0->FIODIR = 0xFFFFFFFF;
	LPC_GPIO0->FIOMASK = 0x00000000; // The mask^^
	LPC_GPIO0->FIOSET |= (1<<8);//|(1<<8);


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
