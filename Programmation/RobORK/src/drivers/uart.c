/** \addtogroup robORK
 *
 * @{
 *
 *
 *
 * \defgroup UART UART
 * @{
 *
 * \file UART.c
 * \brief uart
 * \date Created: 13/07/2012
 * \author Lyphout Florent et Maël Gaudy
 *
 */

#include "uart.h"


volatile int UART3Status;
<<<<<<< HEAD
volatile bool UART3TxEmpty = true;
=======
volatile char UART3TxEmpty = 1;
>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce
volatile char UART3Buffer[BUFSIZE]  = {0};
volatile int UART3Count = 0;

char commande[255] = {0};
volatile bool validation = false;


bool avance=false,recule=false,gauche=false,droite=false,stop=false;



/**
 * \fn void UART3_IRQHandler (void)
 * \brief UART3 interrupt handler
 *
 * \param void None
 * \return None
 */
void UART3_IRQHandler (void)
{
  char IIRValue, LSRValue;
  char Dummy = Dummy;

  IIRValue = LPC_UART3->IIR;

  IIRValue >>= 1;			/* skip pending bit in IIR */
  IIRValue &= 0x07;			/* check bit 1~3, interrupt identification */

  if ( IIRValue == IIR_RDA )	/* Receive Data Available */
  {
	/* Receive Data Available */
	UART3Buffer[UART3Count] = LPC_UART3->RBR;
	UART3Count++;
	if (UART3Buffer[UART3Count-1] == 'z')
	{
		avance=true;
	}
	else if (UART3Buffer[UART3Count-1] == 's')
	{
		recule=true;
	}
	else if (UART3Buffer[UART3Count-1] == 'q')
	{
		gauche=true;
	}
	else if (UART3Buffer[UART3Count-1] == 'd')
	{
		droite=true;
	}
	else if (UART3Buffer[UART3Count-1] == 'a')
	{
		stop=true;
	}

	/***	echo uart ***********************************/
		char buf[1]={UART3Buffer[UART3Count-1]};
		send_uart3(buf, 1 );
	/***	fin echo uart********************************/


	if( UART3Buffer[UART3Count-1] == '\n' || UART3Buffer[UART3Count-1] == '\r' )
	{
		UART3Buffer[UART3Count-1] = '\0';	// ajoute le caratere de fin de chaine
		validation=true;
		strcpy(commande,(char*)UART3Buffer);
<<<<<<< HEAD
		int i;
		for(i = 0; i == strlen((char*)UART3Buffer); i++)
		{
			UART3Buffer[i] = 0x00;
		}
=======
		/*int i;
		for(i = 0; i == strlen(UART3Buffer); i++)
		{
			UART3Buffer[i] = 0x00;
		}*/
>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce
		UART3Count = 0;		/* buffer overflow */
	}

	if ( UART3Count == BUFSIZE )
	{
	  UART3Count = 0;		/* buffer overflow */
	}

  }


  else if ( IIRValue == IIR_THRE )	/* THRE, transmit holding register empty */
  {
	/* THRE interrupt */
	LSRValue = LPC_UART3->LSR;		/* Check status in the LSR to see if
									valid data in U0THR or not */
	if ( LSRValue & LSR_THRE )
	{
<<<<<<< HEAD
	  UART3TxEmpty = true;
	}
	else
	{
	  UART3TxEmpty = false;
=======
	  UART3TxEmpty = 1;
	}
	else
	{
	  UART3TxEmpty = 0;
>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce
	}
  }
}



/**
 * \fn uint32_t init_uart3(uint32_t baudrate )
 * \brief initialisation of UART 3
 *
 * \param baudrate of UART 3
 * \return return 1 if everything it's ok
 */
bool init_uart3(int baudrate)
{
  int Fdiv;
  int pclkdiv, pclk;

	  LPC_PINCON->PINSEL0 &= ~0x0000000F;
	  LPC_PINCON->PINSEL0 |=  0x0000000A;  /* RxD3 is P0.1 and TxD3 is P0.0 */
	  LPC_SC->PCONP |= 1<<4 | 1<<25; //Enable PCUART1
	  /* By default, the PCLKSELx value is zero, thus, the PCLK for
		all the peripherals is 1/4 of the SystemFrequency. */
	  /* Bit 6~7 is for UART3 */
	  pclkdiv = (LPC_SC->PCLKSEL1 >> 18) & 0x03;
	  switch ( pclkdiv )
	  {
	  case 0x00:
	  default:
		  pclk = SystemCoreClock/4;
		  break;
	  case 0x01:
		  pclk = SystemCoreClock;
		  break;
	  case 0x02:
		  pclk = SystemCoreClock/2;
		  break;
	  case 0x03:
		  pclk = SystemCoreClock/8;
		  break;
	  }
	  LPC_UART3->LCR = 0x83;		/* 8 bits, no Parity, 1 Stop bit */
	  Fdiv = ( pclk / 16 ) / baudrate ;	/*baud rate */
	  LPC_UART3->DLM = Fdiv / 256;
	  LPC_UART3->DLL = Fdiv % 256;
	  LPC_UART3->LCR = 0x03;		/* DLAB = 0 */
	  LPC_UART3->FCR = 0x07;		/* Enable and reset TX and RX FIFO. */

	  NVIC_EnableIRQ(UART3_IRQn);

	  LPC_UART3->IER = IER_RBR | IER_THRE | IER_RLS;	/* Enable UART3 interrupt */
<<<<<<< HEAD
=======
	  UART3_IRQHandler();
>>>>>>> a0f85c9a823230f427bb5b9c5ed647300e6c77ce
	  return true;
}


/**
 * \fn void send_uart3(char *BufferPtr, uint32_t Length )
 * \brief Send BufferPtr of UART 3
 *
 * \param BufferPtr is the word to send
 * \param Length is the length of BufferPtr
 * \return None
 */
void send_uart3(char *BufferPtr, int Length )
{
    while ( Length != 0 )
    {
	  /* THRE status, contain valid data */
	  while ( !(UART3TxEmpty & 0x01) );
	  LPC_UART3->THR = *BufferPtr;
	  UART3TxEmpty = 0;	/* not empty in the THR until it shifts out */
	  BufferPtr++;
	  Length--;
	}
    return;
}

/**
 * \fn void send_uart3(char *message)
 * \brief Send message on UART 3
 *
 * \param message is the word to send
 * \return None
 */
void send_message(char *message)
{
	send_uart3(message,strlen(message));
}

/**
 * @}
 * @}
 */
