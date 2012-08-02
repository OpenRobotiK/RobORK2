/** \addtogroup robORK
 *
 * @{
 *
 *
 *
 * \defgroup PWM PWM
 * @{
 *
 * \file PWM.h
 * \brief PWM
 * \date Created: 13/07/2012
 * \author Lyphout Florent et Maël Gaudy
 *
 */


#ifndef __TIMER_H
#define __TIMER_H

/* The test is either MAT_OUT or CAP_IN. Default is MAT_OUT. */
/* If running DMA test, External match is not needed to trigger DMA, but still
set timer as MATx instead of CAPx. */
#define TIMER_MATCH		1

/* TIME_INTERVALmS is a value to load the timer match register with
   to get a 1 mS delay */
#define TIME_INTERVALmS	1000

#define TIME_INTERVAL	(9000000/100 - 1)

extern void delayMs(uint8_t timer_num, uint32_t delayInMs);
extern uint32_t init_timer( uint8_t timer_num, uint32_t timerInterval );
extern void enable_timer( uint8_t timer_num );
extern void disable_timer( uint8_t timer_num );
extern void reset_timer( uint8_t timer_num );
extern void TIMER0_IRQHandler (void);
extern void TIMER1_IRQHandler (void);
extern void TIMER2_IRQHandler (void);
extern void TIMER3_IRQHandler (void);

#endif /* end __TIMER_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/



/**
 * @}
 * @}
 */
