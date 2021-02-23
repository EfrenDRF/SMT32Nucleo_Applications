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


/*=================================================================
 * Data types related to Control register 1 (I2C_CR1).
 *=================================================================*/

/*
 *
 */
typedef enum
{
	DEVICE_DEFAULT_ADDR_DBSL,  /*0: Device default address disabled. Address 0b1100001x is NACKed.*/
	DEVICE_DEFAULt_ADDR_EN     /*1: Device default address enabled. Address 0b1100001x is ACKed*/
}i2c_cr1smbden_t;

/*
 *
 */
typedef enum
{
	GENERAL_CALL_DBSL, /*0: General call disabled. Address 0b00000000 is NACKed.*/
	GENERAL_CALL_EN    /*1: General call enabled. Address 0b00000000 is ACKed.*/
}i2c_cr1gcen_t;

/*
 * Clock stretching
 */
typedef enum
{
	CLK_STRETCHING_EN,    /* 0: Clock stretching enabled*/
	CLK_STRETCHING_DSBL,  /* 1: Clock stretching disabled*/
}i2c_cr1nostretch_t;

/*
 *
 */
typedef enum
{
	SLAVE_BYTE_CONTROL_DSBL, /*0: Slave byte control disabled*/
	SLAVE_BYTE_CONTROL_EN    /*1: Slave byte control enabled*/
}i2c_cr1sbc_t;
/*=================================================================
 * Data types related to Control register 2 (I2C_CR2).
 *=================================================================*/

/*=================================================================
 * Data types related to Own address 1 register (I2C_OAR1).
 *=================================================================*/

/*=================================================================
 * Data types related to Own address 2 register (I2C_OAR2).
 *=================================================================*/

/*
 *
 */
typedef enum
{
	I2C_OA2_NO_MASK,
	I2C_OA2_1_MASK,
	I2C_OA2_2_1_MASK,
	I2C_OA2_3_1_MASK,
	I2C_OA2_4_1_MASK,
	I2C_OA2_5_1_MASK,
	I2C_OA2_6_1_MASK,
	I2C_OA2_7_1_MASK
}i2c_oar2oa2msk_t;

/*=================================================================
 *
 *=================================================================*/

/*
 *
 */
typedef enum
{
	DEVICE_7BIT_ADDRESS,        /*0: The master operates in 7-bit addressing mode*/
	DEVICE_10BIT_ADDRESS        /*1: The master operates in 10-bit addressing mode*/
}i2c_addrmode;

/*
 * Interface mode
 */
typedef enum
{
	I2C_SLAVE_MODE,     /**/
	I2C_MASTER_MODE     /**/
}i2c_intfmode_t;

/*
 *
 */
typedef enum
{
	I2C_SCL_STANDARD_MODE,    /* Standard-mode (up to 100 kbit/s) */
	I2C_SCL_FAST_MODE,        /* Fast-mode (up to 400 kbit/s) */
	I2C_SCL_FAST_MODE_PLUS    /* Fast-mode Plus with 20mA output drive I/Os (up to 1 Mbit/s)*/
}i2c_spdmode_t;


/*
 *
 */
typedef enum
{
	OWN_ADDRESS_NACK,     /*0: Own address x disabled. The received slave address OAx is NACKed.*/
	OWN_ADDRESS_ACK       /*1: Own address x enabled.  The received slave address OAx is ACKed.*/
}i2c_oaen_t;

/*
 *
 */
typedef enum
{
	I2C_ACK_EN,       /* Acknowledge enable */
	I2C_ACK_DSBL,     /* Acknowledge disable */
}i2c_ackcontrol;



/*Macro definition______________________________________________________________*/
#define I2C1_INDEX   0u
#define I2C2_INDEX   1u
#define I2C3_INDEX   2u
#define I2CMAX_INDEX 3u

#endif /* COM_INF_I2C_STM32L053_I2C_TYPES_H_ */
