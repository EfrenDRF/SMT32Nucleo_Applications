/**
  ******************************************************************************
  * @file    stm32l053_i2c_regMap.h
  * @author  Efren Del Real
  * @Date    February 1st 2021
  * @version V1.0
  * @brief   Inter-integrated circuit interface - Register map.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/


#ifndef COM_INF_I2C_STM32L053_I2C_REGMAP_H_
#define COM_INF_I2C_STM32L053_I2C_REGMAP_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_MemMap.h"

/*typedef definition______________________________________________________________*/

/*
 * I2C register map data type.
 */
typedef struct
{
	uint32_t CR1;		/* offset: 0x00 Control register 1 (I2C_CR1)*/
	uint32_t CR2;		/* offset: 0x04 Control register 2 (I2C_CR2)*/
	uint32_t OAR1;		/* offset: 0x08 Own address 1 register (I2C_OAR1)*/
	uint32_t OAR2;		/* offset: 0x0C Own address 2 register (I2C_OAR2)*/
	uint32_t TIMINGR;   /* offset: 0x10 Timing register (I2C_TIMINGR)*/
	uint32_t TIMEOUTR;	/* offset: 0x14 Timeout register (I2C_TIMEOUTR)*/
	uint32_t ISR;	    /* offset: 0x18 Interrupt and status register (I2C_ISR)*/
	uint32_t ICR;	    /* offset: 0x1C Interrupt clear register (I2C_ICR)*/
	uint32_t PECR;		/* offset: 0x20 PEC register (I2C_PECR)*/
	uint32_t RXDR;      /* offset: 0x24 Receive data register (I2C_RXDR)*/
	uint32_t TXDR;      /* offset: 0x20 Transmit data register (I2C_TXDR)*/
}i2c_regMap_t;

/*Macro definition_______________________________________________________________*/
/*
 * I2C1, I2C2, and I2C3 peripherals base address.
 *
 * NOTE: I2C1 is handle by APB1 bus.
 *       I2C2 is handle by APB1 bus.
 *       I2C3 is handle by APB1 bus.
 *
 *       +-------------------+----------+----------+----------+
 *       | I2C Features      |   I2C1   |   I2C2   |   I2C3   |
 *       +-------------------+----------+----------+----------+
 *       | 7bit addressing   |    X     |    X     |    X     |
 *       +-------------------+----------+----------+----------+
 *       | 10bit addressing  |    X     |    X     |    X     |
 *       +-------------------+----------+----------+----------+
 *       | Standard mode     |          |          |          |
 *       | (up to 100kbit/s) |    X     |    X     |    X     |
 *       +-------------------+----------+----------+----------+
 *       | Fast mode         |          |          |          |
 *       | (up to 400kbit/s) |          |          |          |
 *       +-------------------+----------+----------+----------+
 *       | Fast mode plus    |          |          |          |
 *       | (up to 1Mit/s)    |    X     |    X     |    X     |
 *       +-------------------+----------+----------+----------+
 *       | Independent clock |    X     |    -     |    X     |
 *       +-------------------+----------+----------+----------+
 *       | Wakeup from stop  |    X     |    -     |    X     |
 *       +-------------------+----------+----------+----------+
 *       | SMBus/PMBus       |    X     |    -     |    X     |
 *       +-------------------+----------+----------+----------+
 *
 *       X = supported.
 */
#define I2C3_REGMAP		((i2c_regMap_t*)MEMAP_I2C3_PERIPH_BASEADDR)
#define I2C2_REGMAP		((i2c_regMap_t*)MEMAP_I2C2_PERIPH_BASEADDR)
#define I2C1_REGMAP		((i2c_regMap_t*)MEMAP_I2C1_PERIPH_BASEADDR)

/*=====================================================================
 * Control register 1 (I2C_CR1)
 * Address: 0x00
 * Reset value: 0x0000
 *=====================================================================*/

/** bit field position*/
#define I2C_CR1_PECEN_B         23u
#define I2C_CR1_ALERTEN_B       22u
#define I2C_CR1_SMBDEN_B        21u
#define I2C_CR1_SMBHEN_B        20u
#define I2C_CR1_GCEN_B          119u
#define I2C_CR1_WUPEN_B         18u
#define I2C_CR1_NOSTRETCH_B     17u
#define I2C_CR1_SBC_B           16u
#define I2C_CR1_RXDMAEN_B       15u
#define I2C_CR1_TXDMAEN_B       14u
#define I2C_CR1_ANFOFF_B        12u
#define I2C_CR1_DNF_B           8u
#define I2C_CR1_ERRIE_B         7u
#define I2C_CR1_TCIE_B          6u
#define I2C_CR1_STOPIE_B        5u
#define I2C_CR1_NACKIE_B        4u
#define I2C_CR1_ADDRIE_B        3u
#define I2C_CR1_RXIE_B          2u
#define I2C_CR1_TXIE_B          1u
#define I2C_CR1_PE_B            0u


#endif /* COM_INF_I2C_STM32L053_I2C_REGMAP_H_ */
