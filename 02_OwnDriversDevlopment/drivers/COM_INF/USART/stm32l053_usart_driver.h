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
#include "stm32l053_rcc_types.h"

/*typedef definition______________________________________________________________*/

/*=================================================================
 *
 *=================================================================*/

/*
 * USART peripheral configuration type.
 */
typedef struct
{
  usart_cr1m10_t         usartWordLen:2;
  usart_stdbaudrate_t    usartBaudRate;
  usart_cr2stop_t        usartStopBits:2;
  usart_cr1over8_t       usartOverSamp:1;
  usart_cr1pceps_t       usartParityControl:2;
  rcc_cciprusartxsel_t   rccClockSource:2;
}usart_cfg_t;

/*
 * USART structure handle type.
 */
typedef struct
{
	usart_regMap_t * usartRegPtr;
	usart_cfg_t      usartCfg;
}usart_handle_t;

/*Macro definition_______________________________________________________________*/
#define USART_EN   0u
#define USART_DSBL 1u

/*Global function declaration_____________________________________________________*/

/*=================================================================
 * APIs supported by USART driver.
 *=================================================================*/


FUNC(void,EXTERN) usart_Init(CONSTPTR2_VAR(usart_handle_t,AUTO) usartHandlePtr);
FUNC(void,EXTERN) usart_DeInit(CONSTPTR2_VAR(usart_regMap_t,AUTO) usartRegPtr);


FUNC(void,EXTERN) usart_SendData(CONSTPTR2_VAR(usart_regMap_t,AUTO) usartRegPtr, PTR2_VAR(void,AUTO)dataPrt, VAR(uint8_t,AUTO) dataLength, VAR(uint16_t,AUTO) u16TimeOut);
FUNC(void,EXTERN) usart_ReceiveData(CONSTPTR2_CONST(usart_regMap_t,AUTO) usartRegPtr, PTR2_VAR(void,AUTO)dataPrt, VAR(uint8_t,AUTO) dataLength, VAR(uint16_t,AUTO) u16TimeOut);

#endif /* COM_INF_USART_STM32L053_USART_DRIVER_H_ */
