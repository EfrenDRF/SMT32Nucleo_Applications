/**
  ******************************************************************************
  * @file    stm32l053_usart_types.h
  * @author  Efren Del Real
  * @Date    March 9th 2021
  * @version V1.0
  * @brief   Universal synchronous asynchronous receiver transmitter (USART) - Declaration driver APIs.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/

#ifndef COM_INF_USART_STM32L053_USART_DRIVER_H_
#define COM_INF_USART_STM32L053_USART_DRIVER_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_usart_regMap.h"
#include "stm32l053_usart_types.h"

/*typedef definition______________________________________________________________*/

/*=================================================================
 *
 *=================================================================*/

/*
 * USART peripheral configuration type.
 */
typedef struct
{
	usart_cr1M1_t      usartWordLen:2;

}usart_cfg_t;

/*
 * USART structure handle type.
 */
typedef struct
{
	usart_regMap_t * usartRegPtr;
	usart_cfg_t      usartCfg;
}usart_handle_t;

/*Global function declaration_____________________________________________________*/

/*=================================================================
 * APIs supported by USART driver.
 *=================================================================*/

/****************************************************************
 * @fn			- usart_Init.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		- none
 */
FUNC(void,EXTERN) usart_Init(CONSTPTR2_VAR(usart_handle_t,AUTO) usartHandlePtr);

/****************************************************************
 * @fn			- usart_DeInit.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		- none
 */
FUNC(void,EXTERN) usart_DeInit(CONSTPTR2_VAR(usart_regMap_t,AUTO) usartRegPtr);


#endif /* COM_INF_USART_STM32L053_USART_DRIVER_H_ */
