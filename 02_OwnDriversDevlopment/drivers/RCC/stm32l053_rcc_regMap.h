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
#define RCC_CR_PLLRDY_B                      25u
#define RCC_CR_PLLON_B                       24u
#define RCC_CR_RTCPRE_B                      20u
#define RCC_CR_CSSHSEON_B                    19u
#define RCC_CR_HSEBYP_B                      18u
#define RCC_CR_HSERDY_B                      17u
#define RCC_CR_HSEON_B                       16u
#define RCC_CR_MSIRDY_B                       9u
#define RCC_CR_MSION_B                        8u
#define RCC_CR_HSI16OUTEN_B                   5u
#define RCC_CR_HSI16DIVF_B                    4u
#define RCC_CR_HSI16DIVEN_B                   3u
#define RCC_CR_HSI16RDYF_B                    2u
#define RCC_CR_HSI16KERON_B                   1u
#define RCC_CR_HSI16ON_B                      0u

/*=====================================================================
 * Internal clock sources calibration register (RCC_ICSCR)
 * Address: 0x04
 * Reset value: 0x00XX B0XX where X is undefined
 *=====================================================================*/

/** bit field position*/
#define RCC_ICSCR_MSITRIM_B                  24u
#define RCC_ICSCR_MSICAL_B                   16u
#define RCC_ICSCR_MSIRANGE_B                 13u
#define RCC_ICSCR_HSI16TRIM_B                 8u
#define RCC_ICSCR_HSI16CA_B                   0u

/*=====================================================================
 * Clock configuration register (RCC_CFGR)
 * Address offset: 0x0C
 * Reset value: 0x0000 0000
 *=====================================================================*/

/** bit field position*/
#define RCC_CFGR_MCOPRE_B                    28u
#define RCC_CFGR_MCOSEL_B                    24u
#define RCC_CFGR_PLLDIV_B                    22u
#define RCC_CFGR_PLLMUL_B                    18u
#define RCC_CFGR_PLLSRC_B                    16u
#define RCC_CFGR_STOPWUCK_B                  15u
#define RCC_CFGR_PPRE2_B                     11u
#define RCC_CFGR_PPRE1_B                      8u
#define RCC_CFGR_HPRE_B                       4u
#define RCC_CFGR_SWS_B                        2u
#define RCC_CFGR_SW_B                         0u

/*=====================================================================
 * GPIO clock enable register (RCC_IOPENR)
 * Address: 0x2C
 * Reset value: 0x0000 0000
 *=====================================================================*/

/** bit field position*/
#define RCC_IOPENR_IOPHEN_B                   7u
#define RCC_IOPENR_IOPEEN_B                   4u
#define RCC_IOPENR_IOPDEN_B                   3u
#define RCC_IOPENR_IOPCEN_B                   2u
#define RCC_IOPENR_IOPBEN_B                   1u
#define RCC_IOPENR_IOPAEN_B                   0u

/*=====================================================================
 * AHB peripheral clock enable register (RCC_AHBENR)
 * Address: 0x30
 * Reset value: 0x0000 0100
 *=====================================================================*/

/** bit field position*/
#define RCC_AHBENR_CRYPEN_B                  24u
#define RCC_AHBENR_RNGEN_B                   20u
#define RCC_AHBENR_TSCEN_B                   16u
#define RCC_AHBENR_CRCEN_B                   12u
#define RCC_AHBENR_MIFEN_B                    8u
#define RCC_AHBENR_DMAEN_B                    0u

/*=====================================================================
 * APB2 peripheral clock enable register (RCC_APB2ENR)
 * Address: 0x34
 * Reset value: 0x0000 0000
 *=====================================================================*/

/** bit field position*/
#define RCC_APB2ENR_DBGEN_B                  22u
#define RCC_APB2ENR_USART1EN_B               14u
#define RCC_APB2ENR_SPI1EN_B                 12u
#define RCC_APB2ENR_ADCEN_B                   9u
#define RCC_APB2ENR_FWEN_B                    7u
#define RCC_APB2ENR_TIM22EN_B                 5u
#define RCC_APB2ENR_TIM21EN_B                 2u
#define RCC_APB2ENR_SYSCFGEN_B                0u

/*=====================================================================
 * APB1 peripheral clock enable register (RCC_APB1ENR)
 * Address: 0x38
 * Reset value: 0x0000 0000
 *=====================================================================*/

/** bit field position*/
#define RCC_APB1ENR_LPTIM1EN_B               31u
#define RCC_APB1ENR_I2C3EN_B                 30u
#define RCC_APB1ENR_DACEN_B                  29u
#define RCC_APB1ENR_PWREN_B                  28u
#define RCC_APB1ENR_CRSEN_B                  27u
#define RCC_APB1ENR_USBEN_B                  23u
#define RCC_APB1ENR_I2C2EN_B                 22u
#define RCC_APB1ENR_I2C1EN_B                 21u
#define RCC_APB1ENR_USART5EN_B               20u
#define RCC_APB1ENR_USART4EN_B               19u
#define RCC_APB1ENR_LPUART1EN_B              18u
#define RCC_APB1ENR_USART2EN_B               17u
#define RCC_APB1ENR_SPI2EN_B                 14u
#define RCC_APB1ENR_WWDGEN_B                 11u
#define RCC_APB1ENR_LCDEN_B                   9u
#define RCC_APB1ENR_TIM7EN_B                  5u
#define RCC_APB1ENR_TIM6EN_B                  4u
#define RCC_APB1ENR_TIM3EN_B                  1u
#define RCC_APB1ENR_TIM2EN_B                  0u

/*=====================================================================
 * Clock configuration register (RCC_CCIPR)
 * Address offset: 0x4C
 * Reset value: 0x0000 0000
 *=====================================================================*/

/** bit field position*/
#define RCC_CCIPR_HSI48SEL_B                 26u
#define RCC_CCIPR_LPTIM1SEL_B                18u
#define RCC_CCIPR_I2C3SEL_B                  16u
#define RCC_CCIPR_I2C2SEL_B                  12u
#define RCC_CCIPR_I2C1SEL_B                  10u
#define RCC_CCIPR_USART2SEL_B                 2u
#define RCC_CCIPR_USART1SEL_B                 0u




#endif /* RCC_STM32L053_RCC_REGMAP_H_ */
