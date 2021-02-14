/**
  ******************************************************************************
  * @file    stm32l053_exti_regMap.h
  * @author  Efren Del Real
  * @Date    January 8th 2021
  * @version V1.0
  * @brief   Extended interrupts and events controller register.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************
*/

#ifndef EXTI_STM32L053_EXTI_REGMAP_H_
#define EXTI_STM32L053_EXTI_REGMAP_H_
/*Include header files____________________________________________________________*/
#include "stm32l053_MemMap.h"


/*typedef definition______________________________________________________________*/

/*
 * EXTI register map data type.
 */
typedef struct
{
	uint32_t IMR;	/* offset: 0x00 EXTI interrupt mask register*/
	uint32_t EMR;	/* offset: 0x04 EXTI event mask register*/
	uint32_t RTSR;	/* offset: 0x08 EXTI rising edge trigger selection register*/
	uint32_t FTSR;	/* offset: 0x0C EXTI falling edge trigger selection register*/
	uint32_t SWIER;	/* offset: 0x10 EXTI software interrupt event register*/
	uint32_t PR;	/* offset: 0x14 EXTI pending register*/

}exti_regMap_t;

/*Macro definition_______________________________________________________________*/
/*
 * EXTI peripheral base address.
 */
#define EXTI_REGMAP		((exti_regMap_t*)MEMAP_EXTI_PERIPH_BASEADDR)

/*=====================================================================
 * EXTI interrupt mask register (EXTI_IMR)
 * Address: 0x00
 * Reset value: 0x3F84 0000
 *=====================================================================*/
#define EXTI_IMR_EN(line_x)			SET_BIT(EXTI_REGMAP->IMR, line_x)
#define EXTI_IMR_DSBL(line_x)		CLEAN_BIT(EXTI_REGMAP->IMR, line_x)

/*=====================================================================
 * EXTI event mask register (EXTI_EMR)
 * Address: 0x04
 * Reset value: 0x0000 0000
 *=====================================================================*/
#define EXTI_EMR_EN(line_x)			SET_BIT(EXTI_REGMAP->EMR, line_x)
#define EXTI_EMR_DSBL(line_x)		CLEAN_BIT(EXTI_REGMAP->EMR, line_x)

/*=====================================================================
 * EXTI rising edge trigger selection register (EXTI_RTSR)
 * Address: 0x08
 * Reset value: 0x0000 0000
 *=====================================================================*/


/*=====================================================================
 * EXTI falling edge trigger selection register (EXTI_FTSR)
 * Address: 0x0C
 * Reset value: 0x0000 0000
 *=====================================================================*/


/*=====================================================================
 * EXTI software interrupt event register (EXTI_SWIER)
 * Address: 0x10
 * Reset value: 0x0000 0000
 *=====================================================================*/


/*=====================================================================
 * EXTI pending register (EXTI_PR)
 * Address: 0x15
 * Reset value: undefined
 *=====================================================================*/
#define EXTI_PR_CLEAN_LINEx(line_x)		SET_BIT(EXTI_REGMAP->PR, line_x)


#endif /* EXTI_STM32L053_EXTI_REGMAP_H_ */
