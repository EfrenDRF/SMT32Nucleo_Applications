/**
  ******************************************************************************
  * @file    stm32l053_syscfg_regMap.h
  * @author  Efren Del Real
  * @Date    January 8th 2021
  * @version V1.0
  * @brief   System configuration controller register.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************
*/

#ifndef SYSCFG_CMP_STM32L053_SYSCFG_REGMAP_H_
#define SYSCFG_CMP_STM32L053_SYSCFG_REGMAP_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_MemMap.h"


/*typedef definition______________________________________________________________*/

/*
 * EXTI register map data type.
 */
typedef struct
{
	uint32_t CFGR1;				/* offset: 0x00 SYSCFG memory remap register*/
	uint32_t CFGR2;				/* offset: 0x04 SYSCFG peripheral mode configuration register*/
	uint32_t EXTICR[4];			/* offset: 0x08 SYSCFG external interrupt configuration register*/
								/* offset: 0x0C SYSCFG external interrupt configuration register*/
								/* offset: 0x10 SYSCFG external interrupt configuration register*/
								/* offset: 0x14 SYSCFG external interrupt configuration register*/
	uint32_t COMP1_CSR;			/* offset: 0x18 Comparator 1 control and status register*/
	uint32_t COMP2_CSR;			/* offset: 0x1C Comparator 2 control and status register*/
	uint32_t CFGR3;				/* offset: 0x20 SYSCFG reference control and status register*/

}syscfg_regMap_t;

/*Macro definition_______________________________________________________________*/
/*
 * SYSCFG peripheral base address.
 */
#define SYSCFG_REGMAP		((syscfg_regMap_t*)MEMAP_SYSCFG_COMP_PERIPH_BASEADDR)



#endif /* SYSCFG_CMP_STM32L053_SYSCFG_REGMAP_H_ */
