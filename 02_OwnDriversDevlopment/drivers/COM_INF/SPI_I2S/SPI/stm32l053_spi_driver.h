/**
  ******************************************************************************
  * @file    stm32l053_spi_driver.h
  * @author  Efren Del Real
  * @Date    January 18th 2021
  * @version V1.0
  * @brief   Serial peripheral interface driver.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/
#ifndef COM_INF_SPI_I2S_SPI_STM32L053_SPI_DRIVER_H_
#define COM_INF_SPI_I2S_SPI_STM32L053_SPI_DRIVER_H_


/*Include header files____________________________________________________________*/
#include "stm32l053_spi_regMap.h"
#include "stm32l053_spi_types.h"

/*typedef definition______________________________________________________________*/

/*
 * SPI configuration data type.
 */
typedef struct
{
	spi_ddf_t famelength;
	spi_br_t baudrate;
	spi_cpol_t cpol;
	spi_cpha_t cpha;
}spi_Cfg_t;


/*
 * SPI handle data type.
 */
typedef struct
{
	spi_regMap_t * pSPIx;
	spi_Cfg_t infCfg;
}spi_handle_t;

/*Macro definition________________________________________________________________*/

/*Global function declaration_____________________________________________________*/

/*=================================================================
 * APIs supported by SPI driver.
 *=================================================================*/
void spi_Init(void);



void spi_sendData(void);
void spi_receiveData(void);


#endif /* COM_INF_SPI_I2S_SPI_STM32L053_SPI_DRIVER_H_ */
