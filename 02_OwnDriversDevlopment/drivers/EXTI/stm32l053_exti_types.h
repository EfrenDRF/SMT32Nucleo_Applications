/**
  ******************************************************************************
  * @file    stm32l053_exti_types.h
  * @author  Efren Del Real
  * @Date    January 13th 2021
  * @version V1.0
  * @brief   Extended interrupts and events controller - Data types.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/
#ifndef EXTI_STM32L053_EXTI_TYPES_H_
#define EXTI_STM32L053_EXTI_TYPES_H_

/*typedef definition______________________________________________________________*/

/*
 *
 */
typedef enum
{
	IMR_MASKED,     /* 0: Interrupt request from Line x is masked */
	IMR_NOT_MASKED  /* 1: Interrupt request from Line x is not masked */
}exti_imr_t;


/*
 * Values written by software to configure the trigger selection bits
 */
typedef enum
{
	RISING_TRG_EN,          /* Rising trigger enabled (for Event and Interrupt) for input line x */
	FALLING_TRG_EN,         /* Falling trigger enabled (for Event and Interrupt) for input line x */
	RISING_FALLING_TRG_EN   /* Rising and falling trigger enabled (for Event and Interrupt) for input line x*/
}exti_rtsr_t;


/*
 * Hardware interrupt selection type
 */
typedef struct
{
	exti_imr_t	maskInt;        /* Configure the mask bits of the Interrupt lines */
	exti_rtsr_t triggerSel;     /* Configure the Trigger Selection bits of the Interrupt lines */
}exti_hwintsel_t;


#endif /* EXTI_STM32L053_EXTI_TYPES_H_ */
