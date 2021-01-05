/**
  ******************************************************************************
  * @file    stm32l053_rcc_driver.h
  * @author  Efren Del Real
  * @Date    January 3rd 2021
  * @version V1.0
  * @brief   Reset and clock control driver
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************/

#ifndef RCC_STM32L053_RCC_DRIVER_H_
#define RCC_STM32L053_RCC_DRIVER_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_rcc_regMap.h"

/*typedef definition______________________________________________________________*/

/*
 * MSI frequency ranges available
 */
typedef enum
{
	RG0_65kHz,		/* 000: range 0 around 65.536 kHz */
	RG1_131kHz,		/* 001: range 1 around 131.072 kHz */
	RG2_262kHz,		/* 010: range 2 around 262.144 kHz */
	RG3_524kHz,		/* 011: range 3 around 524.288 kHz */
	RG4_1MHz,		/* 100: range 4 around 1.048 MHz */
	RG5_2MHz,		/* 101: range 5 around 2.097 MHz (reset value) */
	RG6_4MHz		/* 110: range 6 around 4.194 MHz */
}rcc_msirange_t;


/*
 *  Microcontroller clock output prescaler
 */
typedef enum
{
	MCO_DIV_1,	/* 000: MCO is divided by 1 */
	MCO_DIV_2,	/* 001: MCO is divided by 2 */
	MCO_DIV_4,	/* 010: MCO is divided by 4 */
	MCO_DIV_8,	/* 011: MCO is divided by 8 */
	MCO_DIV_16	/* 100: MCO is divided by 16 */
}rcc_mcopre_t;

/*
 *  Microcontroller clock output selection
 */
typedef enum
{
	MCO_OUT_DSBL,		/* 0000: MCO output disabled, no clock on MCO*/
	MCO_OUT_SYSCLK,		/* 0001: SYSCLK clock selected*/
	MCO_OUT_HSI16,		/* 0010: HSI16 oscillator clock selected*/
	MCO_OUT_HSE,		/* 0011: MSI oscillator clock selected*/
	MCO_OUT_PLL,		/* 0100: HSE oscillator clock selected*/
	MCO_OUT_LSI,		/* 0101: PLL clock selected*/
	MCO_OUT_LSE,		/* 0110: LSI oscillator clock selected*/
	MCO_OUT_HSI48		/* 0111: LSE oscillator clock selected*/
}rcc_mcosel_t;



/*Macro definition_________________________________________________________________*/

#endif /* RCC_STM32L053_RCC_DRIVER_H_ */
