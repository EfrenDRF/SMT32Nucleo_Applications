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
	spi_mstr_t    devMode:2;     /*Device mode*/
	spi_commode_t comMode:2;     /*Communication mode*/
	spi_br_t      cbr:3;         /*Clock baud rate*/
	spi_cpol_t    cpol:1;        /*Clock polarity*/
	spi_cpha_t    cpha:1;        /*Clock phase*/
	spi_ssm_t     ssm:1;         /*Software slave management*/
	spi_ff_t      ff:1;          /*Frame format*/
	spi_dff_t     dff:1;         /*Data frame format*/
}spi_cfg_t;


/*
 * SPI handle data type.
 */
typedef struct
{
	spi_regMap_t  *spiRegPtr;
	spi_cfg_t      spiCfg;
}spi_handle_t;

/*Macro definition________________________________________________________________*/

/*Global function declaration_____________________________________________________*/

/*=================================================================
 * APIs supported by SPI driver.
 *=================================================================*/
FUNC(void,EXTERN) spi_Init(CONSTPTR2_VAR(spi_handle_t, AUTO)spiHandlePtr);
FUNC(void,EXTERN) spi_PeriphCtrl(CONSTPTR2_VAR(spi_regMap_t,AUTO) spiRegPtr, VAR(uint8_t,AUTO) control);

FUNC(void,EXTERN) spi_SendData(CONSTPTR2_VAR(spi_regMap_t,AUTO) spiRegPtr, CONSTPTR2_CONST(uint8_t,AUTO)u8DataPrt, VAR(uint8_t,AUTO) u8Length);
FUNC(void,EXTERN) spi_ReceiveData(CONSTPTR2_VAR(spi_regMap_t,AUTO) spiRegPtr, CONSTPTR2_VAR(uint8_t,AUTO)u8DataPrt, VAR(uint8_t,AUTO) u8Length);


#endif /* COM_INF_SPI_I2S_SPI_STM32L053_SPI_DRIVER_H_ */
