/**
  ******************************************************************************
  * @file    cordexM0p_nvic_driver.h
  * @author  Efren Del Real
  * @Date    January 9th 2021
  * @version V1.0
  * @brief   Nested Vectored Interrupt Controller (NVIC) driver.
  *
  * NOTE:    The code was wrote using below documentation.
  *          - PM0223 programming manual by ST
  *          - Cortex-M0+ Devices (Generic User Guide) by ARM
  *          - r0p0 Cortex-M0 (Technical Reference Manual) by ARM
  *          Please verify your correct documentation in order to modify the code
  *          or get more information.
  ******************************************************************************
*/

#ifndef CORDEX_M0_PLUS_NVIC_CORDEXM0P_NVIC_DRIVER_H_
#define CORDEX_M0_PLUS_NVIC_CORDEXM0P_NVIC_DRIVER_H_

/*Include header files____________________________________________________________*/
#include "cordexM0p_nvic_regMap.h"
#include "stm32l053_nvic_vectorTable.h"

/*typedef definition______________________________________________________________*/

/*
 * Priority data type.
 *
 * Available values written by software in each priority field.
 *
 * The processor implements only bits [7:6] of each field bits [5:0] read as zero
 * and ignore writes.
 *
 * NOTE: The lower the value, the higher the priority of the corresponding interrupt.
 */
typedef enum
{
	IRQn_PRI_0 = 0u,   /* 0000_0000 Priority 0 */
	IRQn_PRI_1 = 64u,  /* 0100_0000 Priority 1 */
	IRQn_PRI_2 = 128u, /* 1000_0000 Priority 2 */
	IRQn_PRI_3 = 192u  /* 1100_0000 Priority 3 */
}nvic_pri_t;

/*Macro definition________________________________________________________________*/


/*Global function declaration_____________________________________________________*/

/*=================================================================
 * APIs supported by NVIC driver.
 *=================================================================*/
void nvic_EnableIRQ(nvic_IRQn_t IRQn);
void nvic_DisableIRQ(nvic_IRQn_t IRQn);
uint8_t nvic_GetPendingIRQ (nvic_IRQn_t IRQn);
void nvic_SetPendingIRQ (nvic_IRQn_t IRQn);
void nvic_ClearPendingIRQ (nvic_IRQn_t IRQn);
void nvic_SetPriority (nvic_IRQn_t IRQn, nvic_pri_t priority);
nvic_pri_t nvic_GetPriority (nvic_IRQn_t IRQn);



#endif /* CORDEX_M0_PLUS_NVIC_CORDEXM0P_NVIC_DRIVER_H_ */

