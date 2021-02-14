/**
  ******************************************************************************
  * @file    stm32l053_gpio_types.h
  * @author  Efren Del Real
  * @Date    February 7th 2021
  * @version V1.0
  * @brief   General-purpose I/Os - Data types
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/

#ifndef GPIO_STM32L053_GPIO_TYPES_H_
#define GPIO_STM32L053_GPIO_TYPES_H_

/*typedef definition______________________________________________________________*/

/*=====================================================================
 * GPIO port mode register (GPIOx_MODER) (x =A..E and H) - Data types.
 * Address: 0x00
 *=====================================================================*/
typedef enum
{
	IN_MODE,        /* 00: Input mode */
	OUT_MODE,       /* 01: General purpose output mode */
	ALTFN_MODE,     /* 10: Alternate function mode */
	ANALOG_MODE,    /* 11: Analog mode (reset state) */
	IN_IMR_MODE     /* Input Interrupt Mask Request mode */
}gpio_mode_t;


/*=====================================================================
 * GPIO port output type register (GPIOx_OTYPER) - Data types.
 * (x = A..E and H)
 * Address: 0x04
 *=====================================================================*/
typedef enum
{
	OUT_PUSH_PULL,      /* 0: Output push-pull (reset state) */
	OUT_OPEN_DRAIN      /* 1: Output open-drain */
}gpio_otype_t;

/*=====================================================================
 * GPIO port output speed register (GPIOx_OSPEEDR) - Data types.
 * (x = A..E and H)
 * Address: 0x08
 *=====================================================================*/
typedef enum
{
	LOW_SPD,          /* 00: Low speed */
	MEDIUM_SPD,       /* 01: Medium speed */
	HIGH_SPD,         /* 10: High speed */
	VERY_HIGH_SPD     /* 11: Very high speed */
}gpio_ospeed_t;

/*=====================================================================
 * GPIO port pull-up/pull-down register (GPIOx_PUPDR) - Data types.
 * (x = A..E and H)
 * Address: 0x08
 *=====================================================================*/

typedef enum
{
	NO_PULL_UP_PULL_DOWN,		/* 00: No pull-up, pull-down */
	PULL_UP,				/* 01: Pull-up */
	PULL_DOWN				/* 10: Pull-down */
}gpio_pupd_t;

/*=================================================================
 *
 *=================================================================*/

/*
 *
 */
typedef enum
{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15
}gpio_pinnum_t;

/*
 *
 */
typedef enum
{
	ALT_FUN_0,
	ALT_FUN_1,
	ALT_FUN_2,
	ALT_FUN_3,
	ALT_FUN_4,
	ALT_FUN_5,
	ALT_FUN_6,
	ALT_FUN_7
}gpio_altfun_t;


/*
 *
 */
typedef enum
{
	PIN_LOW,
	PIN_HIGH
}gpio_pinst_t;

/*Macro definition______________________________________________________________*/
#define GPIOA_INDEX   0u
#define GPIOB_INDEX   1u
#define GPIOC_INDEX   2u
#define GPIOD_INDEX   3u
#define GPIOE_INDEX   4u
#define GPIOH_INDEX   5u
#define GPIOMAX_INDEX 6u

#endif /* GPIO_STM32L053_GPIO_TYPES_H_ */
