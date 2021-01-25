/**
  ******************************************************************************
  * @file    stm32l053_spii2s_regMap.h
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

#ifndef COM_INF_SPI_I2S_STM32L053_SPII2S_REGMAP_H_
#define COM_INF_SPI_I2S_STM32L053_SPII2S_REGMAP_H_

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
 *       | SPI Features |   SPI1   |   SPI2   |
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



/*=====================================================================
 * SPI control register 1 (SPI_CR1) (not used in I2S mode)
 * Address: 0x00
 * Reset value: 0x0000
 *=====================================================================*/

/** bit field position*/
#define SPI_CR1_BIDIMODE_B   15u
#define SPI_CR1_BIDIOE_B     14u
#define SPI_CR1_CRCEN_B      13u
#define SPI_CR1_CRCNEXT_B    12u
#define SPI_CR1_DDF_B        11u
#define SPI_CR1_RXONLY_B     10u
#define SPI_CR1_SSM_B        9u
#define SPI_CR1_SSI_B        8u
#define SPI_CR1_LSBFIRST_B   7u
#define SPI_CR1_SPE_B        6u
#define SPI_CR1_BR_B         3u
#define SPI_CR1_MSTR_B       2u
#define SPI_CR1_CPOL_B       1u
#define SPI_CR1_CPHA_B       0u

/*=====================================================================
 * SPI control register 2 (SPI_CR2)
 * Address: 0x04
 * Reset value: 0x0000
 *=====================================================================*/
#define SPI_CR2_TXEIE_B      7u
#define SPI_CR2_RXNEIE_B     6u
#define SPI_CR2_ERRIE_B      5u
#define SPI_CR2_FRF_B        4u
#define SPI_CR2_SSOE_B       2u
#define SPI_CR2_TXDMAEN_B    1u
#define SPI_CR2_RXDMAEN_B    0u


/*=====================================================================
 * SPI status register (SPI_SR)
 * Address: 0x08
 * Reset value: 0x0000
 *=====================================================================*/
#define SPI_SR_FRE_B         8u
#define SPI_SR_BSY_B         7U
#define SPI_SR_OVR_B         6u
#define SPI_SR_MODF_B        5u
#define SPI_SR_CRCERR_B      4u
#define SPI_SR_UDR_B         3u
#define SPI_SR_CHSIDE_B      2u
#define SPI_SR_TXE_B         1u
#define SPI_SR_RXE_B         0u

/** bit field position*/


#endif /* COM_INF_SPI_I2S_STM32L053_SPII2S_REGMAP_H_ */
