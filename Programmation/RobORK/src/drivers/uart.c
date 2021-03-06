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
#include "asserv_position.h"

volatile int UART3Status;
volatile char UART3TxEmpty = 1;
volatile char UART3Buffer[BUFSIZE]  = {0};
volatile int UART3Count = 0;

char commande[255] = {0};
volatile bool validation = false;
volatile bool demo_mode = false;

volatile bool avance=false, recule=false, gauche=false, droite=false, stop=false, regle_vitesse=false;



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
	if (demo_mode==true)
	{
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
		else if (UART3Buffer[UART3Count-1] == 'v')
		{
			regle_vitesse=true;
			UART3Count=0;
		}

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
		/*int i;
		for(i = 0; i == strlen(UART3Buffer); i++)
		{
			UART3Buffer[i] = 0x00;
		}*/
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
	  UART3TxEmpty = 1;
	}
	else
	{
	  UART3TxEmpty = 0;
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
	  UART3_IRQHandler();
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

bool int_to_char(int nombre, char* resultat)
{
	if (nombre < 0)
	{
		resultat[0] = '-';
		nombre = -nombre;
	}
	else
	{
		resultat[0] = '+';
	}
	if (nombre > 100000)return false;
	int dixmille, mille, centaine, dixaine, unite;
	int buffer = nombre;

	dixmille = buffer / 10000;
	buffer = buffer % 10000;

	mille = buffer / 1000;
	buffer = buffer % 1000;

	centaine = buffer / 100;
	buffer = buffer % 100;

	dixaine = buffer / 10;
	unite = buffer % 10;


	resultat[1] = dixmille + 0x30;
	resultat[2] = mille + 0x30;
	resultat[3] = centaine + 0x30;
	resultat[4] = dixaine + 0x30;
	resultat[5] = unite + 0x30;
	resultat[6] = '\0';
	/*resultat[6] = '\n';
	resultat[7] = '\r';
	resultat[8] = '\0';//*/
	return true;
}

void affiche_position(void)
{
	char buf[100];
	char chaine[100] = "X = ";
	int_to_char((int)X,buf);
	strcat(chaine, buf);
	strcat(chaine, "\tY = ");
	int_to_char((int)Y,buf);
	strcat(chaine, buf);
	strcat(chaine, "\tangle = ");
	int_to_char((int)angle,buf);
	strcat(chaine, buf);
	strcat(chaine, "\n\r");
	send_message(chaine);
}

/**
 * @}
 * @}
 */
