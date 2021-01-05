/**
  ******************************************************************************
  * @file    stm32l053_gpio_regMap.h
  * @author  Efren Del Real
  * @Date    January 1st 2021
  * @version V1.0
  * @brief   General-purpose I/Os registers
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************
*/

#ifndef GPIO_STM32L053_GPIO_REGMAP_H_
#define GPIO_STM32L053_GPIO_REGMAP_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_MemMap.h"


/*typedef definition______________________________________________________________*/

/*
 * GPIO register map data type.
 */
typedef struct
{
	uint32_t MODER;		/* offset: 0x00 GPIO port mode register*/
	uint32_t OTYPER;	/* offset: 0x04 GPIO port output type register*/
	uint32_t OSPEEDR;	/* offset: 0x08 GPIO port output speed register*/
	uint32_t PUPDR;		/* offset: 0x0C GPIO port pull-up/pull-down register*/
	vuint32_t IDR;		/* offset: 0x10 GPIO port input data register*/
	uint32_t ODR;		/* offset: 0x14 GPIO port output data register*/
	uint32_t BSRR;		/* offset: 0x18 GPIO port bit set/reset register*/
	uint32_t LCKR;		/* offset: 0x1C GPIO port configuration lock register*/
	uint32_t AFR[2];	/* offset: 0x20 GPIO alternate function low register*/
						/* offset: 0x24 GPIO alternate function high register*/
	uint32_t BBR;		/* offset: 0x28 GPIO port bit reset register*/
}gpio_regMap_t;

/*Macro definition_______________________________________________________________*/

/*
 * GPIOx peripheral base address.
 */
#define GPIOA_REGMAP		((gpio_regMap_t*)MEMMAP_GPIOA_PERIPH_BASEADDR)
#define GPIOB_REGMAP		((gpio_regMap_t*)MEMMAP_GPIOB_PERIPH_BASEADDR)
#define GPIOC_REGMAP		((gpio_regMap_t*)MEMMAP_GPIOC_PERIPH_BASEADDR)
#define GPIOD_REGMAP		((gpio_regMap_t*)MEMMAP_GPIOD_PERIPH_BASEADDR)
#define GPIOE_REGMAP		((gpio_regMap_t*)MEMMAP_GPIOE_PERIPH_BASEADDR)
#define GPIOH_REGMAP		((gpio_regMap_t*)MEMMAP_GPIOH_PERIPH_BASEADDR)

#endif /* GPIO_STM32L053_GPIO_REGMAP_H_ */
