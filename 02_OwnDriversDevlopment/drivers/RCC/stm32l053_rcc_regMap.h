/**
  ******************************************************************************
  * @file    stm32l053_rcc_regMap.h
  * @author  Efren Del Real
  * @Date    January 1st 2021
  * @version V1.0
  * @brief   Reset and clock control registers
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************
*/

#ifndef RCC_STM32L053_RCC_REGMAP_H_
#define RCC_STM32L053_RCC_REGMAP_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_MemMap.h"


/*typedef definition______________________________________________________________*/

/*
 * RCC register map data type.
 */
typedef struct
{
	vuint32_t CR;			/* offset: 0x00 Clock control register*/
	vuint32_t ICSCR;		/* offset: 0x04 Internal clock sources calibration register*/
	vuint32_t CRRCR;		/* offset: 0x08 Clock recovery RC register*/
	vuint32_t CFGR;			/* offset: 0x0C Clock configuration register*/
	vuint32_t CIER;			/* offset: 0x10 Clock interrupt enable register*/
	uint32_t CIFR;			/* offset: 0x14 Clock interrupt flag register*/
	uint32_t CICR;			/* offset: 0x18 Clock interrupt clear register*/
	uint32_t IOPRSTR;		/* offset: 0x1C GPIO reset register*/
	uint32_t AHBRSTR;		/* offset: 0x20 AHB peripheral reset register*/
	uint32_t APB2RSTR;		/* offset: 0x24 APB2 peripheral reset register*/
	uint32_t APB1RSTR;		/* offset: 0x28 APB1 peripheral reset register*/
	uint32_t IOPENR;		/* offset: 0x2C GPIO clock enable register*/
	uint32_t AHBENR;		/* offset: 0x30 AHB peripheral clock enable register*/
	uint32_t APB2ENR;		/* offset: 0x34 APB2 peripheral clock enable register*/
	uint32_t APB1ENR;		/* offset: 0x38 APB1 peripheral clock enable register*/
	uint32_t IOPSMEN;		/* offset: 0x3C GPIO clock enable in Sleep mode register*/
	uint32_t AHBSMENR;		/* offset: 0x40 AHB peripheral clock enable in Sleep mode register*/
	uint32_t APB2SMENR;		/* offset: 0x44 APB2 peripheral clock enable in Sleep mode register*/
	uint32_t APB1SMENR;		/* offset: 0x48 APB1 peripheral clock enable in Sleep mode register*/
	uint32_t CCIPR;			/* offset: 0x4C Clock configuration register*/
	uint32_t CSR;			/* offset: 0x50 Control/status register*/
}rcc_regMap_t;

/*Macro definition_______________________________________________________________*/

/*
 * RCC peripheral base address.
 */
#define RCC_REGMAP			((rcc_regMap_t*)MEMAP_RCC_PERIPH_BASEADDR)



/*=====================================================================
 * Clock control register (RCC_CR)
 * Address: 0x00
 * System Reset value: 0b0000 0000 00XX 0X00 0000 0011 0000 0000 where X
 * is undefined
 * Power-on reset value: 0x0000 0300
 *=====================================================================*/

/** bit field position*/
#define RCC_BITFP_PLLRDY		25u
#define RCC_BITFP_PLLON			24u
#define RCC_BITFP_RTCPRE		20u
#define RCC_BITFP_CSSHSEON		19u
#define RCC_BITFP_HSEBYP		18u
#define RCC_BITFP_HSERDY		17u
#define RCC_BITFP_HSEON			16u
#define RCC_BITFP_MSIRDY		9u
#define RCC_BITFP_MSION			8u
#define RCC_BITFP_HSI16OUTEN	5u
#define RCC_BITFP_HSI16DIVF		4u
#define RCC_BITFP_HSI16DIVEN	3u
#define RCC_BITFP_HSI16RDYF		2u
#define RCC_BITFP_HSI16KERON	1u
#define RCC_BITFP_HSI16ON		0u

/*=====================================================================
 * Internal clock sources calibration register (RCC_ICSCR)
 * Address: 0x04
 * Reset value: 0x00XX B0XX where X is undefined
 *=====================================================================*/

/** bit field position*/
#define RCC_BITFP_MSITRIM		24u
#define RCC_BITFP_MSICAL		16u
#define RCC_BITFP_MSIRANGE		13u
#define RCC_BITFP_HSI16TRIM		8u
#define RCC_BITFP_HSI16CAL		0u


/*=====================================================================
 * Clock configuration register (RCC_CFGR)
 * Address offset: 0x0C
 * Reset value: 0x0000 0000
 *=====================================================================*/
#define RCC_BITFP_MCOPRE		28u
#define RCC_BITFP_MCOSEL		24u
#define RCC_BITFP_PLLDIV		22u
#define RCC_BITFP_PLLMUL		18u
#define RCC_BITFP_PLLSRC		16u
#define RCC_BITFP_STOPWUCK		15u
#define RCC_BITFP_PPRE2			11u
#define RCC_BITFP_PPRE1			8u
#define RCC_BITFP_HPRE			4u
#define RCC_BITFP_SWS			2u
#define RCC_BITFP_SW			0u

/*=====================================================================
 * GPIO clock enable register (RCC_IOPENR)
 * Address: 0x2C
 * Reset value: 0x0000 0000
 *=====================================================================*/

/** GPIO port x clock enabled macros*/
#define RCC_IOPH_CLK_EN()		MEMMAP_SET_BIT( RCC_REGMAP->IOPENR, 7u)
#define RCC_IOPE_CLK_EN()		MEMMAP_SET_BIT( RCC_REGMAP->IOPENR, 4u)
#define RCC_IOPD_CLK_EN()		MEMMAP_SET_BIT( RCC_REGMAP->IOPENR, 3u)
#define RCC_IOPC_CLK_EN()		MEMMAP_SET_BIT( RCC_REGMAP->IOPENR, 2u)
#define RCC_IOPB_CLK_EN()		MEMMAP_SET_BIT( RCC_REGMAP->IOPENR, 1u)
#define RCC_IOPA_CLK_EN()		MEMMAP_SET_BIT( RCC_REGMAP->IOPENR, 0u)

/** GPIO port x clock disabled macros */
#define RCC_IOPH_CLK_DSBL()	MEMMAP_CLEAN_BIT(RCC_REGMAP->IOPENR, 7u)
#define RCC_IOPE_CLK_DSBL()	MEMMAP_CLEAN_BIT(RCC_REGMAP->IOPENR, 4u)
#define RCC_IOPD_CLK_DSBL()	MEMMAP_CLEAN_BIT(RCC_REGMAP->IOPENR, 3u)
#define RCC_IOPC_CLK_DSBL()	MEMMAP_CLEAN_BIT(RCC_REGMAP->IOPENR, 2u)
#define RCC_IOPB_CLK_DSBL()	MEMMAP_CLEAN_BIT(RCC_REGMAP->IOPENR, 1u)
#define RCC_IOPA_CLK_DSBL()	MEMMAP_CLEAN_BIT(RCC_REGMAP->IOPENR, 0u)


/*=====================================================================
 * AHB peripheral clock enable register (RCC_AHBENR)
 * Address: 0x30
 * Reset value: 0x0000 0100
 *=====================================================================*/
/** AHB's peripherals clock enabled macros */
#define RCC_CRYP_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->AHBENR, 24u)
#define RCC_RGN_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->AHBENR, 20u)
#define RCC_TSC_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->AHBENR, 16u)
#define RCC_CRC_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->AHBENR, 12u)
#define RCC_MIF_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->AHBENR, 8u)
#define RCC_DMA_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->AHBENR, 0u)

/** AHB's peripherals clock disabled macros */
#define RCC_CRYP_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->AHBENR, 24u)
#define RCC_RGN_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->AHBENR, 20u)
#define RCC_TSC_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->AHBENR, 16u)
#define RCC_CRC_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->AHBENR, 12u)
#define RCC_MIF_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->AHBENR, 8u)
#define RCC_DMA_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->AHBENR, 0u)


/*=====================================================================
 * APB2 peripheral clock enable register (RCC_APB2ENR)
 * Address: 0x34
 * Reset value: 0x0000 0000
 *=====================================================================*/
/** APB2's peripherals clock enabled macros */
#define RCC_DBG_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB2ENR, 22u)
#define RCC_USART1_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB2ENR, 14u)
#define RCC_SPI1_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB2ENR, 12u)
#define RCC_ADC_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB2ENR, 9u)
#define RCC_FW_CLK_EN()			MEMMAP_SET_BIT(RCC_REGMAP->APB2ENR, 7u)
#define RCC_TIM22_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB2ENR, 5u)
#define RCC_TIM21_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB2ENR, 2u)
#define RCC_SYSCF_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB2ENR, 0u)


/** APB2's peripherals clock disabled macros */
#define RCC_DBG_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->APB2ENR, 22u)
#define RCC_USART1_CLK_DSBL()	MEMMAP_CLEAN_BIT(RCC_REGMAP->APB2ENR, 14u)
#define RCC_SPI1_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->APB2ENR, 12u)
#define RCC_ADC_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->APB2ENR, 9u)
#define RCC_FW_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->APB2ENR, 7u)
#define RCC_TIM22_CLK_DSBL()	MEMMAP_CLEAN_BIT(RCC_REGMAP->APB2ENR, 5u)
#define RCC_TIM21_CLK_DSBL()	MEMMAP_CLEAN_BIT(RCC_REGMAP->APB2ENR, 2u)
#define RCC_SYSCF_CLK_DSBL()	MEMMAP_CLEAN_BIT(RCC_REGMAP->APB2ENR, 0u)

/*=====================================================================
 * APB1 peripheral clock enable register (RCC_APB1ENR)
 * Address: 0x38
 * Reset value: 0x0000 0000
 *=====================================================================*/
/** APB1's peripherals clock enabled macros */
#define RCC_LPTIM1_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 31u)
#define RCC_I2C3_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 30u)
#define RCC_DAC_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 29u)
#define RCC_PWR_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 28u)
#define RCC_CRS_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 27u)
#define RCC_USB_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 23u)
#define RCC_I2C2_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 22u)
#define RCC_I2C1_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 21u)
#define RCC_USART5_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 20u)
#define RCC_USART4_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 19u)
#define RCC_LPUART1_CLK_EN()	MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 18u)
#define RCC_USART2_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 17u)
#define RCC_SPI2_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 14u)
#define RCC_WWDG_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 11u)
#define RCC_LCD_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 9u)
#define RCC_TIM7_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 5u)
#define RCC_TIM6_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 4u)
#define RCC_TIM3_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 1u)
#define RCC_TIM2_CLK_EN()		MEMMAP_SET_BIT(RCC_REGMAP->APB1ENR, 0u)

/** APB1's peripherals clock disabled macros */
#define RCC_LPTIM1_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 31u)
#define RCC_I2C3_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 30u)
#define RCC_DAC_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 29u)
#define RCC_PWR_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 28u)
#define RCC_CRS_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 27u)
#define RCC_USB_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 23u)
#define RCC_I2C2_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 22u)
#define RCC_I2C1_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 21u)
#define RCC_USART5_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 20u)
#define RCC_USART4_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 19u)
#define RCC_LPUART1_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 18u)
#define RCC_USART2_CLK_DSBL()		MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 17u)
#define RCC_SPI2_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 14u)
#define RCC_WWDG_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 11u)
#define RCC_LCD_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 9u)
#define RCC_TIM7_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 5u)
#define RCC_TIM6_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 4u)
#define RCC_TIM3_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 1u)
#define RCC_TIM2_CLK_DSBL()			MEMMAP_CLEAN_BIT(RCC_REGMAP->APB1ENR, 0u)



#endif /* RCC_STM32L053_RCC_REGMAP_H_ */
