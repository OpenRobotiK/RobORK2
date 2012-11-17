/*
===============================================================================
 Name        : main.c
 Author      : Maël, for the Open RobotiK association
 Version     : 1.0
 Copyright   : Copyright (C) 
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "main.h"
#include "motors.h"
#include "uart.h"


int main(void) {

	MOTOR_Init(MOTOR_RIGHT);
	MOTOR_Init(MOTOR_LEFT);

	MOTOR_Start(MOTOR_RIGHT, 30);
	MOTOR_Start(MOTOR_LEFT, 100 - 20);

	//init_uart3(9600);
	//send_uart3("Coucou\n", 8);

	// Enter an infinite loop, just incrementing a counter
	volatile static int i = 0 ;
	while(1) {
		i++ ;
	}
	return 0 ;
}
