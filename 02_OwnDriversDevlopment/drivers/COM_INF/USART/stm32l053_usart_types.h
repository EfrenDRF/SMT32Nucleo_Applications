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
 * Bit 12 M0: Word length
 */
typedef enum
{
	USART_8_DATA_BIT  /*00: 1 Start bit, 8 data bits, n stop bits*/,
	USART_9_DATA_BIT  /*01: 1 Start bit, 9 data bits, n stop bits*/,
	USART_7_DATA_BIT  /*10: 1 Start bit, 7 data bits, n stop bits*/
}usart_cr1m10_t;

/*
 * Bit 10 PCE: Parity control enable
 * Bit 9 PS: Parity selection
 */
typedef enum
{
	USART_NONE_PARITY      /* 00: Parity control disabled*/,
	USART_EVEN_PARITY = 2  /* 10: Parity control enabled _ Even parity*/,
	USART_ODD_PARITY       /* 11: Parity control enabled _ Odd parity */
}usart_cr1pceps_t;

/*
 * Bit 15 OVER8: Oversampling mode
 */
typedef enum
{
  USART_OVERSAMPLING_BY_16  /*0: Oversampling by 16*/,
  USART_OVERSAMPLING_BY_8   /*1: Oversampling by 8*/
}usart_cr1over8_t;

/*=================================================================
 * Data types related to Control register 2 (USART_CR2).
 *=================================================================*/
/*
 * Bits 13:12 STOP[1:0]: STOP bits
 */
typedef enum
{
  USART_1_STOP_BIT     /*00: 1 stop bit*/,
  USART_0_5_STOP_BIT   /*01: 0.5 stop bit*/,
  USART_2_STOP_BIT     /*10: 2 stop bits*/,
  USART_1_5_STOP_BIT   /*11: 1.5 stop bits*/
}usart_cr2stop_t;

/*=================================================================
 *
 *=================================================================*/
/*
 *
 */
typedef enum
{
	USART_STD_2_4_KBPS        = 2400,
	USART_STD_9_6_KBPS        = 9600,
	USART_STD_115_2_KBPS      = 115200
}usart_stdbaudrate_t;

/*Macro definition______________________________________________________________*/
#define USART1_INDEX       0u
#define USART2_INDEX       1u
#define USART4_INDEX       2u
#define USART5_INDEX       3u
#define USARTMAX_INDEX     4u


#endif /* COM_INF_USART_STM32L053_USART_TYPES_H_ */
