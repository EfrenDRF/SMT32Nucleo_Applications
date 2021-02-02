/**
  ******************************************************************************
  * @file    stm32l053_i2c_driver.h
  * @author  Efren Del Real
  * @Date    February 1st 2021
  * @version V1.0
  * @brief   Inter-integrated circuit interface - Declaration driver APIs
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/

#ifndef COM_INF_I2C_STM32L053_I2C_DRIVER_H_
#define COM_INF_I2C_STM32L053_I2C_DRIVER_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_i2c_regMap.h"
#include "stm32l053_i2c_types.h"

/*typedef definition______________________________________________________________*/

/*
 *
 */
typedef struct
{
	uint8_t noUsed;

}i2c_cfg_t;

/*
 *
 */
typedef struct
{
	i2c_regMap_t * pI2Cx;
	i2c_cfg_t      I2Ccfg;
}i2c_handle_t;

void i2c_Init(i2c_handle_t * pI2Chandle);


#endif /* COM_INF_I2C_STM32L053_I2C_DRIVER_H_ */
