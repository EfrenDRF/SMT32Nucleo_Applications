/**
  ******************************************************************************
  * @file    stm32l053_syscfg_driver.h
  * @author  Efren Del Real
  * @Date    January 8th 2021
  * @version V1.0
  * @brief   System configuration controller driver.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************
*/

#ifndef SYSCFG_CMP_STM32L053_SYSCFG_DRIVER_H_
#define SYSCFG_CMP_STM32L053_SYSCFG_DRIVER_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_syscfg_regMap.h"
#include "stm32l053_syscfg_types.h"
#include "stm32l053_gpio_types.h"
/*typedef definition______________________________________________________________*/


/*Macro definition______________________________________________________________*/


/*Global function definition____________________________________________________*/
FUNC(void,EXTERN) syscfg_EXTIx_Cfg(CONST(syscfg_extix_t,AUTO) srcEXTIx,CONST(gpio_pinnum_t,AUTO) pinNum);

#endif /* SYSCFG_CMP_STM32L053_SYSCFG_DRIVER_H_ */
