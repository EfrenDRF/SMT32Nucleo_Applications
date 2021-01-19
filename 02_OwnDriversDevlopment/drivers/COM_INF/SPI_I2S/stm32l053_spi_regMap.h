/**
  ******************************************************************************
  * @file    stm32l053_spi_regMap..h
  * @author  Efren Del Real
  * @Date    January 17th 2021
  * @version V1.0
  * @brief   Serial peripheral interface/ inter-IC sound (SPI/IS2) register map.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/

#ifndef COM_INF_SPI_I2S_STM32L053_SPI_REGMAP_H_
#define COM_INF_SPI_I2S_STM32L053_SPI_REGMAP_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_MemMap.h"

/*typedef definition______________________________________________________________*/

/*
 * SPI register map data type.
 */
typedef struct
{
	uint32_t CR1;		/* offset: 0x00 SPI control register 1 (not used in I2S mode)*/
	uint32_t CR2;		/* offset: 0x04 SPI control register 2*/
	uint32_t SR;		/* offset: 0x08 SPI status register*/
	uint32_t DR;		/* offset: 0x0C SPI data register*/
	uint32_t CRCPR;		/* offset: 0x10 SPI CRC polynomial register (not used in I2S mode)*/
	uint32_t RXCRCR;	/* offset: 0x14 SPI RX CRC register (not used in I2S mode)*/
	uint32_t TXCRCR;	/* offset: 0x18 SPI TX CRC register (not used in I2S mode)*/
	uint32_t I2SCFGR;	/* offset: 0x1C SPI_I2S configuration register*/
	uint32_t I2SPR;		/* offset: 0x20 SPI_I2S prescaler register*/

}spi_regMap_t;

/*Macro definition_______________________________________________________________*/
/*
 * SPI1 and SPI2 peripherals base address.
 *
 * NOTE: SPI1 is handle by APB2 bus.
 *       SPI2 is handle by APB1 bus.
 *       +--------------+----------+----------+
 *       | SPI Feaures  |   SPI1   |   SPI2   |
 *       +--------------+----------+----------+
 *       | Hardware CRC |          |          |
 *       | calculation  |    X     |    X     |
 *       +--------------+----------+----------+
 *       | I2S module   |    -     |    X     |
 *       +--------------+----------+----------+
 *       | TI module    |    X     |    X     |
 *       +--------------+----------+----------+
 *       X = supported.
 */
#define SPI1_REGMAP		((spi_regMap_t*)MEMAP_SPI1_PERIPH_BASEADDR)
#define SPI2_REGMAP		((spi_regMap_t*)MEMAP_SPI2_PERIPH_BASEADDR)





#endif /* COM_INF_SPI_I2S_STM32L053_SPI_REGMAP_H_ */
