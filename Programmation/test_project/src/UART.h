/** \addtogroup robORK
 *
 * @{
 *
 *
 *
 * \defgroup UART UART
 * @{
 *
 * \file UART.h
 * \brief uart
 * \date Created: 13/07/2012
 * \author Lyphout Florent et Maël Gaudy
 *
 */

#ifndef __UART_H
#define __UART_H



#define IER_RBR		0x01
#define IER_THRE	0x02
#define IER_RLS		0x04

#define IIR_PEND	0x01
#define IIR_RLS		0x03
#define IIR_RDA		0x02
#define IIR_CTI		0x06
#define IIR_THRE	0x01

#define LSR_RDR		0x01
#define LSR_OE		0x02
#define LSR_PE		0x04
#define LSR_FE		0x08
#define LSR_BI		0x10
#define LSR_THRE	0x20
#define LSR_TEMT	0x40
#define LSR_RXFE	0x80

///\brief Size of the reception buffer
#define BUFSIZE		0x40

uint32_t init_uart3(uint32_t baudrate );
void send_uart3(uint8_t *BufferPtr, uint32_t Length );
void UART3_IRQHandler (void);


#endif /* end __UART_H */


/**
 * @}
 * @}
 */
