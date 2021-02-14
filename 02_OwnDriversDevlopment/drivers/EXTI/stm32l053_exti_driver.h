/**
  ******************************************************************************
  * @file    stm32l053_exti_driver.h
  * @author  Efren Del Real
  * @Date    January 8th 2021
  * @version V1.0
  * @brief   Extended interrupts and events controller driver.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************
*/

#ifndef EXTI_STM32L053_EXTI_DRIVER_H_
#define EXTI_STM32L053_EXTI_DRIVER_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_exti_regMap.h"
#include "stm32l053_exti_types.h"
/*typedef definition______________________________________________________________*/

/*Macro definition______________________________________________________________*/

/*Global function definition____________________________________________________*/

/*=================================================================
 * APIs supported by EXTI driver.
 *=================================================================*/

/*
 *
 */
extern void exti_triggerSel_Cfg(uint8_t line_x, exti_rtsr_t triggerSel);
extern uint8_t exti_GetPendingSrcLine(uint8_t line_x);

#endif /* EXTI_STM32L053_EXTI_DRIVER_H_ */
