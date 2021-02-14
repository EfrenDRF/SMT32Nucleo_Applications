/**
  ******************************************************************************
  * @file    stm32l053_gpio_driver.h
  * @author  Efren Del Real
  * @Date    January 1st 2021
  * @version V1.0
  * @brief   General-purpose I/Os driver
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/

#ifndef GPIO_STM32L053_GPIO_DRIVER_H_
#define GPIO_STM32L053_GPIO_DRIVER_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_gpio_regMap.h"
#include "stm32l053_gpio_types.h"
#include "stm32l053_exti_types.h"

/*typedef definition______________________________________________________________*/

/*=================================================================
 *
 *=================================================================*/
typedef struct
{
	gpio_pinnum_t gpioPinNum:4;          /* pin number 0 ... 15*/
	gpio_mode_t   gpioPinMode:3;         /* pin mode*/
	gpio_otype_t  gpioPinOutType:1;      /* pin output type*/
	gpio_ospeed_t gpioPinOutSpeed:2;     /* pin output speed*/
	gpio_pupd_t   gpioPinPuPd:2;         /* pin pull-up/pull-down cfg*/
	gpio_altfun_t gpioPinAltFun:3;       /* pin alternate function selection 0 ..15 */
	exti_rtsr_t   extiPinTriggerSel:2;   /* Pin trigger selection bits for the interrupt lines */
}gpio_pinCfg_t;


/*=================================================================
 *
 *=================================================================*/
typedef struct
{
	gpio_regMap_t *gpioRegPtr;			/* Pointer to GPIO port x base address. */
	gpio_pinCfg_t  gpioPinCfg;		/* GPIO pin configuration settings.*/
}gpio_handle_t;


/*Macro definition______________________________________________________________*/


/*Global function declaration___________________________________________________*/

/*=================================================================
 * APIs supported by GPIO driver.
 *=================================================================*/

/*
 *
 */
FUNC(void,EXTERN) gpio_PinInit(CONSTPTR2_VAR(gpio_handle_t, AUTO) gpioHandlePtr);
FUNC(void,EXTERN) gpio_DeInit(void);

/*
 *
 */
FUNC(gpio_pinst_t,EXTERN) gpio_ReadPin (CONSTPTR2_CONST(gpio_regMap_t,AUTO) gpioRegPtr, VAR(gpio_pinnum_t,AUTO) gpioPinNum);
FUNC(uint16_t,EXTERN)     gpio_ReadPort(CONSTPTR2_CONST(gpio_regMap_t,AUTO) gpioRegPtr);


/*
 *
 */
FUNC(void,EXTERN) gpio_WritePin (CONSTPTR2_VAR(gpio_regMap_t,AUTO) gpioRegPtr, VAR(gpio_pinnum_t,AUTO) pinNum, VAR(gpio_pinst_t,AUTO) pinState);
FUNC(void,EXTERN) gpio_WritePort(CONSTPTR2_VAR(gpio_regMap_t,AUTO) gpioRegPtr, VAR(uint16_t,AUTO) portValue);
FUNC(void,EXTERN) gpio_TogglePin(CONSTPTR2_VAR(gpio_regMap_t,AUTO) gpioRegPtr, VAR(gpio_pinnum_t,AUTO) pinNum);



#endif /* GPIO_STM32L053_GPIO_DRIVER_H_ */
