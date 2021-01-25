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
#include "stm32l053_spii2s_regMap.h"
#include "stm32l053_spi_types.h"

/*typedef definition______________________________________________________________*/

/*
 * SPI configuration data type.
 */
typedef struct
{
	spi_mstr_t    devMode;     /*Device mode*/
	spi_commode_t comMode;     /*Communication mode*/
	spi_br_t      cbr;         /*Clock baud rate*/
	spi_cpol_t    cpol;        /*Clock polarity*/
	spi_cpha_t    cpha;        /*Clock phase*/
	spi_ssm_t     ssm;         /*Software slave management*/
	spi_ff_t      ff;          /*Frame format*/
	spi_dff_t     dff;         /*Data frame format*/
}spi_cfg_t;


/*
 * SPI handle data type.
 */
typedef struct
{
	spi_regMap_t * pSPIx;
	spi_cfg_t SPIcfg;
}spi_handle_t;

/*Macro definition________________________________________________________________*/

/*Global function declaration_____________________________________________________*/

/*=================================================================
 * APIs supported by SPI driver.
 *=================================================================*/
void spi_Init(spi_handle_t * pSPIhandle);
void spi_PeriphCtrl(spi_regMap_t * const pSPIx, uint8_t control);
void spi_SSICtrl(spi_regMap_t * const pSPIx, uint8_t control);

void spi_SendData(spi_regMap_t * const pSPIx, uint8_t *pData, uint8_t uLen);
void spi_ReceiveData(void);


#endif /* COM_INF_SPI_I2S_SPI_STM32L053_SPI_DRIVER_H_ */
