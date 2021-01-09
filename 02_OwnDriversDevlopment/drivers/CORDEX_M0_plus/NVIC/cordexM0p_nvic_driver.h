/**
  ******************************************************************************
  * @file    cordexM0p_nvic_driver.h
  * @author  Efren Del Real
  * @Date    January 9th 2021
  * @version V1.0
  * @brief
  *
  * NOTE:
  ******************************************************************************
*/

#ifndef CORDEX_M0_PLUS_NVIC_CORDEXM0P_NVIC_DRIVER_H_
#define CORDEX_M0_PLUS_NVIC_CORDEXM0P_NVIC_DRIVER_H_
/*Include header files____________________________________________________________*/
#include "cordexM0p_nvic_regMap.h"
#include "stm32l053_nvic_vectorTable.h"

/*typedef definition______________________________________________________________*/


/*Macro definition________________________________________________________________*/

/*Global function declaration_____________________________________________________*/

/*=================================================================
 * APIs supported by NVIC driver.
 *=================================================================*/
void nvic_EnableIRQ(nvic_IRQn_t IRQn);
void nvic_DisableIRQ(nvic_IRQn_t IRQn);
uint32_t nvic_GetPendingIRQ (nvic_IRQn_t IRQn);
void nvic_SetPendingIRQ (nvic_IRQn_t IRQn);
void nvic_ClearPendingIRQ (nvic_IRQn_t IRQn);
void nvic_SetPriority (nvic_IRQn_t IRQn, uint32_t priority);
uint32_t nvic_GetPriority (nvic_IRQn_t IRQn);
void nvic_SystemReset (void);


#endif /* CORDEX_M0_PLUS_NVIC_CORDEXM0P_NVIC_DRIVER_H_ */

