/**
  ******************************************************************************
  * @file    stm32l053_spi_types.h
  * @author  Efren Del Real
  * @Date    January 18th 2021
  * @version V1.0
  * @brief   Serial peripheral interface data types.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/

#ifndef COM_INF_SPI_I2S_SPI_STM32L053_SPI_TYPES_H_
#define COM_INF_SPI_I2S_SPI_STM32L053_SPI_TYPES_H_

/*typedef definition______________________________________________________________*/


/*=================================================================
 * Data types related to SPI_CR1 register.
 *=================================================================*/

/*
 * Data frame format data type.
 */
typedef enum
{
	_8BIT_DFF,    /*0: 8-bit data frame format is selected for transmission/reception*/
	_16BIT_DFF    /*1: 16-bit data frame format is selected for transmission/reception*/
}spi_dff_t;

/*
 * Software slave management data type.
 */
typedef enum
{
	HW_NSS_MODE, /*0: Software slave management disabled - Hardware configured*/
	SW_NSS_MODE  /*1: Software slave management enabled  - Software configured*/
}spi_ssm_t;

/*
 * Frame format data type.
 */
typedef enum
{
	MSB_FIRST, /*0: MSB transmitted first*/
	LSB_FIRST  /*1: LSB transmitted first*/
}spi_ff_t;

/*
 * Baud rate control data type.
 */
typedef enum
{
	FPCLK_DIV_2,    /*000: fPCLK/2*/
	FPCLK_DIV_4,    /*001: fPCLK/4*/
	FPCLK_DIV_8,    /*010: fPCLK/8*/
	FPCLK_DIV_16,   /*011: fPCLK/16*/
	FPCLK_DIV_32,   /*100: fPCLK/32*/
	FPCLK_DIV_64,   /*101: fPCLK/64*/
	FPCLK_DIV_128,  /*110: fPCLK/128*/
	FPCLK_DIV_256,  /*111: fPCLK/256*/
}spi_br_t;

/*
 * Master selection data type.
 */
typedef enum
{
	SLAVE_MODE,           /* 0: Slave configuration*/
	MASTER_MODE,          /* 1: Master configuration*/
	MULTIMASTER_MODE = 3  /*    Multimaster capability */
}spi_mstr_t;

/*
 * Clock polarity data type
 */
typedef enum
{
	LOW_IDLE_CLK,  /*0: CK to 0 when idle*/
	HIGH_IDLE_CLK, /*1: CK to 1 when idle*/
}spi_cpol_t;

/*
 * Clock phase data type.
 */
typedef enum
{
	FALLING_EDGE_CLK,  /*0: The first clock transition is the first data capture edge*/
	RISING_EDGE_CLK,   /*1: The second clock transition is the first data capture edge*/
}spi_cpha_t;


/*
 *
 */
typedef enum
{
	FULL_DUPLEX,       /*Full dupplex communication*/
	HALF_DUPLEX,       /*Half dupplex communication*/
	SIMPLEX_TX_ONLY,   /*Simplex Tx communication */
	SIMPLEX_RX_ONLY    /*Simplex Rx communication*/
}spi_commode_t;

/*Macro definition______________________________________________________________*/
#define SPI1_INDEX   0u
#define SPI2_INDEX   1u
#define SPIMAX_INDEX 2u

#endif /* COM_INF_SPI_I2S_SPI_STM32L053_SPI_TYPES_H_ */
