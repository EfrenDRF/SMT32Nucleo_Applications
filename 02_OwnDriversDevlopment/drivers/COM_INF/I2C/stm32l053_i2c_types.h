/**
  ******************************************************************************
  * @file    stm32l053_i2c_types.h
  * @author  Efren Del Real
  * @Date    February 1st 2021
  * @version V1.0
  * @brief   Inter-integrated circuit interface - data types.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/

#ifndef COM_INF_I2C_STM32L053_I2C_TYPES_H_
#define COM_INF_I2C_STM32L053_I2C_TYPES_H_


/*
 *
 */
typedef enum
{
	SLAVE_TX,
	SLAVE_RX,
	MASTER_TX,
	MASTER_Rx
}i2c_modeSel_t;

#endif /* COM_INF_I2C_STM32L053_I2C_TYPES_H_ */
