/**
  ******************************************************************************
  * @file    stm32l053_gpio_driver.h
  * @author  Efren Del Real
  * @Date    January 1st 2021
  * @version V1.0
  * @brief   General-purpose I/Os driver
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************
*/

#ifndef GPIO_STM32L053_GPIO_DRIVER_H_
#define GPIO_STM32L053_GPIO_DRIVER_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_gpio_regMap.h"
#include "stm32l053_exti_driver.h"

/*typedef definition______________________________________________________________*/

/*=================================================================
 * Values to modify the configuration registers:
 * MODER, OTYPER, OSPEEDR, PUPDR
 *=================================================================*/

/*
 * Values written by software to configure the I/O mode
 */
typedef enum
{
	IN_MODE,		/* 00: Input mode */
	OUT_MODE,		/* 01: General purpose output mode */
	ALTFN_MODE,		/* 10: Alternate function mode */
	ANALOG_MODE,	/* 11: Analog mode (reset state) */
	IN_IMR_MODE		/* Input Interrupt Mask Request mode */
}gpio_mode_t;

/*
 * Values written by software to configure the I/O output type.
 */
typedef enum
{
	OUT_PUSH_PULL,		/* 0: Output push-pull (reset state) */
	OUT_OPEN_DRAIN		/* 1: Output open-drain */
}gpio_otype_t;

/*
 * Values written by software to configure the I/O output speed.
 */
typedef enum
{
	LS,					/* 00: Low speed */
	MS,					/* 01: Medium speed */
	HS,					/* 10: High speed */
	VHS					/* 11: Very high speed */
}gpio_ospeed_t;

/*
 * Values written by software to configure the I/O pull-up or pull-down.
 */
typedef enum
{
	NO_PUP_PDOWN,		/* 00: No pull-up, pull-down */
	PUP,				/* 01: Pull-up */
	PDOWN				/* 10: Pull-down */
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
}gpio_pinNum_t;

/*
 *
 */
typedef enum
{
	AFSEL_0,
	AFSEL_1,
	AFSEL_2,
	AFSEL_3,
	AFSEL_4,
	AFSEL_5,
	AFSEL_6,
	AFSEL_7,
	AFSEL_8,
	AFSEL_9,
	AFSEL_10,
	AFSEL_11,
	AFSEL_12,
	AFSEL_13,
	AFSEL_14,
	AFSEL_15
}gpio_altfun_t;

/*
 *
 */
typedef enum
{
	PIN_LOW,
	PIN_HIGH
}gpio_pinst_t;

/*
 *
 */
typedef struct
{
	gpio_pinNum_t pinNumber; 	/* pin number 0 ... 15 */
	gpio_mode_t mode;			/* mode */
	gpio_otype_t oType;			/* output type cfg */
	gpio_ospeed_t oSpeed;		/* output speed cfg */
	gpio_pupd_t pupd;			/* pull-up/pull-down cfg */
	gpio_altfun_t altFun;		/* Alternate function selection 0 ..15 */
	exti_rtsr_t triggerSel;		/* Configure the trigger selection bits of the interrupt lines */
								/* Note: mode must be IN_IMR_MODE to config the hardware int*/
}gpio_pinCfg_t;


/*=================================================================
 *
 *=================================================================*/
typedef struct
{
	gpio_regMap_t *pGPIOx;			/* Pointer to GPIO port x base address. */
	gpio_pinCfg_t GPIOx_pinCfg;		/* GPIO pin configuration settings.*/
}gpio_handle_t;


/*Macro definition______________________________________________________________*/


/*Global function declaration___________________________________________________*/

/*=================================================================
 * APIs supported by GPIO driver.
 *=================================================================*/

/*
 *
 */
extern void gpio_pinInit(gpio_handle_t const *pGPIOHandle);
extern void gpio_DeInit(void);

/*
 *
 */
extern gpio_pinst_t gpio_Read_Pin(gpio_regMap_t *pGPIOx, gpio_pinNum_t pinNumber);
extern uint16_t gpio_Read_Port(gpio_regMap_t *pGPIOx);

/*
 *
 */
extern void gpio_Write_Pin(gpio_regMap_t *pGPIOx, gpio_pinNum_t pinNumber, gpio_pinst_t state);
extern void gpio_Write_Port(gpio_regMap_t *pGPIOx, uint16_t u16Value);
extern void gpio_Toggle_Pin(gpio_regMap_t *pGPIOx, gpio_pinNum_t pinNumber);



#endif /* GPIO_STM32L053_GPIO_DRIVER_H_ */
