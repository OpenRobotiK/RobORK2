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

#include "LPC17xx.h"
#include "type.h"
#include "UART.h"

volatile uint32_t UART3Status;
volatile uint8_t UART3TxEmpty = 1;
volatile uint8_t UART3Buffer[BUFSIZE];
volatile uint32_t UART3Count = 0;


/*****************************************************************************
** Function name:		UART0_IRQHandler
**
** Descriptions:		UART0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
*****************************************************************************/
void UART3_IRQHandler (void)
{
  uint8_t IIRValue;
  uint8_t Dummy = Dummy;

  IIRValue = LPC_UART3->IIR;

  IIRValue >>= 1;			/* skip pending bit in IIR */
  IIRValue &= 0x07;			/* check bit 1~3, interrupt identification */
  if ( IIRValue == IIR_RDA )	/* Receive Data Available */
  {
	/* Receive Data Available */
	UART3Buffer[UART3Count] = LPC_UART3->RBR;
	UART3Count++;

	/***	echo uart ***********************************/
	uint8_t buf[1]={UART3Buffer[UART3Count-1]};
	send_uart3(buf, 1 );
	/***	fin echo uart********************************/

	if ( UART3Count == BUFSIZE )
	{
	  UART3Count = 0;		/* buffer overflow */
	}
  }
}


/*****************************************************************************
** Function name:		UARTInit
**
** Descriptions:		Initialize UART port, setup pin select,
**						clock, parity, stop bits, FIFO, etc.
**
** parameters:			portNum(0 or 1) and UART baudrate
** Returned value:		true or false, return false only if the
**						interrupt handler can't be installed to the
**						VIC table
**
*****************************************************************************/
uint32_t init_uart3(uint32_t baudrate )
{
  uint32_t Fdiv;
  uint32_t pclkdiv, pclk;

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
	  return (TRUE);
}

/*****************************************************************************
** Function name:		UARTSend
**
** Descriptions:		Send a block of data to the UART 0 port based
**						on the data length
**
** parameters:			portNum, buffer pointer, and data length
** Returned value:		None
**
*****************************************************************************/
void send_uart3(uint8_t *BufferPtr, uint32_t Length )
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

/******************************************************************************
**                            End Of File
******************************************************************************/

/**
 * @}
 * @}
 */
