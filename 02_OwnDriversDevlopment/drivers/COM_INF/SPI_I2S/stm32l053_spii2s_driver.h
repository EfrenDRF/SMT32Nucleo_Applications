/**
  ******************************************************************************
  * @file    stm32l053_spii2s_driver.h
  * @author  Efren Del Real
  * @Date    January 23th 2021
  * @version V1.0
  * @brief   Serial peripheral interface/ inter-IC sound (SPI/IS2).
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/

#ifndef COM_INF_SPI_I2S_STM32L053_SPII2S_DRIVER_H_
#define COM_INF_SPI_I2S_STM32L053_SPII2S_DRIVER_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_spii2s_regMap.h"

/*Macro definition________________________________________________________________*/

/*Global function declaration_____________________________________________________*/

/*=================================================================
 * APIs supported by SPI and I2S driver.
 *=================================================================*/
uint8_t spii2s_GetStatusFlag(const spi_regMap_t *const pSPIx, const uint8_t flag);

#endif /* COM_INF_SPI_I2S_STM32L053_SPII2S_DRIVER_H_ */
