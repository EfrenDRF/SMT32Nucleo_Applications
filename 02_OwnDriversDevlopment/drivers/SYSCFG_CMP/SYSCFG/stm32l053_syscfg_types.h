/**
  ******************************************************************************
  * @file    stm32l053_syscfg_types.h
  * @author  Efren Del Real
  * @Date    February 13th 2021
  * @version V1.0
  * @brief   System configuration controller - Data types
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/

#ifndef SYSCFG_CMP_SYSCFG_STM32L053_SYSCFG_TYPES_H_
#define SYSCFG_CMP_SYSCFG_STM32L053_SYSCFG_TYPES_H_

/*typedef definition______________________________________________________________*/

/*
 * Values written by sofrtware to select the source input for the EXTIx
 * external interrupt.
 */
typedef enum
{
	EXTI_PA,	/* 0000: PA[x] pin */
	EXTI_PB,	/* 0001: PB[x] pin */
	EXTI_PC,	/* 0010: PC[x] pin */
	EXTI_PD,	/* 0011: PD[x] pin */
	EXTI_PE,	/* 0100: PE[x] pin */
	EXTI_PH		/* 0101: PH[x] pin */
}syscfg_extix_t;

#endif /* SYSCFG_CMP_SYSCFG_STM32L053_SYSCFG_TYPES_H_ */
