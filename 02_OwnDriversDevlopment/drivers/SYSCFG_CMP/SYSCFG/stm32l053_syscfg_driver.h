/**
  ******************************************************************************
  * @file    stm32l053_syscfg_driver.h
  * @author  Efren Del Real
  * @Date    January 8th 2021
  * @version V1.0
  * @brief   System configuration controller driver.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************
*/

#ifndef SYSCFG_CMP_STM32L053_SYSCFG_DRIVER_H_
#define SYSCFG_CMP_STM32L053_SYSCFG_DRIVER_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_syscfg_regMap.h"
#include "stm32l053_gpio_driver.h"
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
}syscfg_exti_t;

/*Macro definition______________________________________________________________*/


/*Global function definition____________________________________________________*/
extern void syscfg_EXTI_Cfg(const gpio_regMap_t * const pGPIOx, gpio_pinNum_t pinNum);

#endif /* SYSCFG_CMP_STM32L053_SYSCFG_DRIVER_H_ */
