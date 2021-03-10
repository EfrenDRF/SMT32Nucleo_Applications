/**
  ******************************************************************************
  * @file    stm32l053_usart_types.h
  * @author  Efren Del Real
  * @Date    March 9th 2021
  * @version V1.0
  * @brief   Universal synchronous asynchronous receiver transmitter (USART) - data types.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/
#ifndef COM_INF_USART_STM32L053_USART_TYPES_H_
#define COM_INF_USART_STM32L053_USART_TYPES_H_

/*=================================================================
 * Data types related to Control register 1 (USART_CR1).
 *=================================================================*/
/*
 * Bit 28 M1: Word length
 */
typedef enum
{
	USART_8_DATA_BIT  /*00: 1 Start bit, 8 data bits, n stop bits*/,
	USART_9_DATA_BIT  /*01: 1 Start bit, 9 data bits, n stop bits*/,
	USART_7_DATA_BIT  /*10: 1 Start bit, 7 data bits, n stop bits*/
}usart_cr1M1_t;

#endif /* COM_INF_USART_STM32L053_USART_TYPES_H_ */
