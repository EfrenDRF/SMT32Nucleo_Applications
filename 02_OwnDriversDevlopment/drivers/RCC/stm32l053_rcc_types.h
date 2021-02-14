/**
  ******************************************************************************
  * @file    stm32l053_rcc_types.h
  * @author  Efren Del Real
  * @Date    February 7th 2021
  * @version V1.0
  * @brief   Reset and clock control - data types.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************/

#ifndef RCC_STM32L053_RCC_TYPES_H_
#define RCC_STM32L053_RCC_TYPES_H_

/*typedef definition______________________________________________________________*/

/*=====================================================================
 * Clock control register (RCC_CR) - Data types.
 * Address: 0x00
 *=====================================================================*/

/*=====================================================================
 * Internal clock sources calibration register (RCC_ICSCR) - Data types.
 * Address: 0x04
 *=====================================================================*/

/*
 * MSI frequency ranges available
 */
typedef enum
{
	RG0_65kHz,		/* 000: range 0 around 65.536 kHz */
	RG1_131kHz,		/* 001: range 1 around 131.072 kHz */
	RG2_262kHz,		/* 010: range 2 around 262.144 kHz */
	RG3_524kHz,		/* 011: range 3 around 524.288 kHz */
	RG4_1MHz,		/* 100: range 4 around 1.048 MHz */
	RG5_2MHz,		/* 101: range 5 around 2.097 MHz (reset value) */
	RG6_4MHz		/* 110: range 6 around 4.194 MHz */
}rcc_msirange_t;

/*=====================================================================
 * Clock configuration register (RCC_CFGR) - Data types.
 * Address: 0x0C
 *=====================================================================*/

/*
 *  Microcontroller clock output prescaler
 */
typedef enum
{
	MCO_DIV_1,	/* 000: MCO is divided by 1 */
	MCO_DIV_2,	/* 001: MCO is divided by 2 */
	MCO_DIV_4,	/* 010: MCO is divided by 4 */
	MCO_DIV_8,	/* 011: MCO is divided by 8 */
	MCO_DIV_16	/* 100: MCO is divided by 16 */
}rcc_mcopre_t;

/*
 *  Microcontroller clock output selection
 */
typedef enum
{
	MCO_OUT_DSBL,		/* 0000: MCO output disabled, no clock on MCO*/
	MCO_OUT_SYSCLK,		/* 0001: SYSCLK clock selected*/
	MCO_OUT_HSI16,		/* 0010: HSI16 oscillator clock selected*/
	MCO_OUT_HSE,		/* 0011: MSI oscillator clock selected*/
	MCO_OUT_PLL,		/* 0100: HSE oscillator clock selected*/
	MCO_OUT_LSI,		/* 0101: PLL clock selected*/
	MCO_OUT_LSE,		/* 0110: LSI oscillator clock selected*/
	MCO_OUT_HSI48		/* 0111: LSE oscillator clock selected*/
}rcc_mcosel_t;


/*=====================================================================
 * Clock configuration register (RCC_CCIPR) - Data types.
 * Address: 0x4C
 *=====================================================================*/

/*
 *  I2C clock source selection
 */
typedef enum{
	APB_AS_I2C_CLK,      /* 00: APB clock selected as I2C1 clock*/
	SYSTEM_AS_I2C_CLK,   /* 01: System clock selected as I2C1 clock*/
	HSI16_AS_I2C_CLK     /* 10: HSI16 clock selected as I2C1 clock*/
}rcc_i2cxsel_t;

/*=====================================================================
 *
 *=====================================================================*/

/*
 *
 */
typedef struct{
	uint8_t rccIOPxRST:3;   /* RCC_IOPRSTR    - I/O port x reset bit*/
	uint8_t rccIOPxEN:3;    /* RCC_IOPENR     - I/O port x enable bit*/
	uint8_t rccIOPxSMEN:3;  /* RCC_IOPSMENR   - I/O port x clock enable during sleep mode bit*/
}rcc_iopbit_t;

/*
 *
 */
typedef struct{
	uint8_t rccI2CxRST:5;   /* RCC_APB1RSTR    - I2Cx Reset bit*/
	uint8_t rccI2CxEN:5;    /* RCC_APB1ENR     - I2Cx Enable bit*/
	uint8_t rccI2CxSMEN:5;  /* RCC_APB1SMENR   - I2Cx Clock enable during sleep mode bit*/
	uint8_t rccI2CxSEL:5;   /* RCC_CCIPR       - I2Cx Clock source selection bits*/
}rcc_i2cbit_t;


#endif /* RCC_STM32L053_RCC_TYPES_H_ */
