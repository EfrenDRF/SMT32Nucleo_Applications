/**
  ******************************************************************************
  * @file    stm32l053_usart_regMap.h
  * @author  Efren Del Real
  * @Date    March 9th 2021
  * @version V1.0
  * @brief   Universal synchronous asynchronous receiver transmitter (USART) - Register map.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/


#ifndef COM_INF_USART_STM32L053_USART_REGMAP_H_
#define COM_INF_USART_STM32L053_USART_REGMAP_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_MemMap.h"

/*typedef definition______________________________________________________________*/

/*
 * USAR register map data type.
 */

typedef struct
{
	uint32_t  CR1;       /* offset: 0x00 Control register 1 (USART_CR1)*/
	uint32_t  CR2;       /* offset: 0x04 Control register 2 (USART_CR2)*/
	uint32_t  CR3;       /* offset: 0x08 Control register 3 (USART_CR3)*/
	vuint32_t BRR;       /* offset: 0x0C Baud rate register (USART_BRR)*/
	uint32_t  GTPR;      /* offset: 0x10 Guard time and prescaler register (USART_GTPR)*/
	uint32_t  RTOR;      /* offset: 0x14 Receiver timeout register (USART_RTOR)*/
	uint32_t  PRQ;       /* offset: 0x18 Request register (USART_RQR)*/
	vuint32_t ISR;       /* offset: 0x1C Interrupt and status register (USART_ISR)*/
	vuint32_t RDR;       /* offset: 0x20 Receive data register (USART_RDR)*/
	vuint32_t TDR;       /* offset: 0x24 Transmit data register (USART_TDR)*/
}usart_regMap_t;

/*Macro definition_______________________________________________________________*/
#define USART1_REGMAP      ((usart_regMap_t*)MEMAP_USART1_PERIPH_BASEADDR)
#define USART2_REGMAP      ((usart_regMap_t*)MEMAP_USART2_PERIPH_BASEADDR)
#define USART4_REGMAP      ((usart_regMap_t*)MEMAP_USART4_PERIPH_BASEADDR)
#define USART5_REGMAP      ((usart_regMap_t*)MEMAP_USART5_PERIPH_BASEADDR)


/*=====================================================================
 * Control register 1 (USART_CR1)
 * Address: 0x00
 * Reset value: 0x0000
 *=====================================================================*/

/** bit field position*/
#define USART_CR1_M1_B            28u
#define USART_CR1_EOBIE_B         27u
#define USART_CR1_M0_B            12u
#define USART_CR1_UE_B             0u

#endif /* COM_INF_USART_STM32L053_USART_REGMAP_H_ */
