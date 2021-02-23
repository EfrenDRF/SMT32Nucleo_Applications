/**
  ******************************************************************************
  * @file    stm32l053_rcc_driver.h
  * @author  Efren Del Real
  * @Date    January 3rd 2021
  * @version V1.0
  * @Date    February 7th 2021
  *          V1.1 - Data types moved to stm32l053_rxx_types.h file.
  *
  * @brief   Reset and clock control - driver
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************/

#ifndef RCC_STM32L053_RCC_DRIVER_H_
#define RCC_STM32L053_RCC_DRIVER_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_rcc_regMap.h"
#include "stm32l053_rcc_types.h"
#include "stm32l053_gpio_types.h"
#include "stm32l053_i2c_types.h"

/*typedef definition______________________________________________________________*/

/*Macro definition_________________________________________________________________*/
#define RCC_OK      0u
#define RCC_NOTOK   1u

#define RCC_CLK_EN   0u
#define RCC_CLK_DSBL 1u

/*=====================================================================
 * GPIO clock enable register (RCC_IOPENR) - Macros
 * Address: 0x2C
 *=====================================================================*/
/** GPIO port x clock enabled macros*/
#define RCC_IOPH_CLK_EN()       SET_BIT( RCC_REGMAP->IOPENR, RCC_IOPENR_IOPHEN_B)
#define RCC_IOPE_CLK_EN()       SET_BIT( RCC_REGMAP->IOPENR, RCC_IOPENR_IOPEEN_B)
#define RCC_IOPD_CLK_EN()       SET_BIT( RCC_REGMAP->IOPENR, RCC_IOPENR_IOPDEN_B)
#define RCC_IOPC_CLK_EN()       SET_BIT( RCC_REGMAP->IOPENR, RCC_IOPENR_IOPCEN_B)
#define RCC_IOPB_CLK_EN()       SET_BIT( RCC_REGMAP->IOPENR, RCC_IOPENR_IOPBEN_B)
#define RCC_IOPA_CLK_EN()       SET_BIT( RCC_REGMAP->IOPENR, RCC_IOPENR_IOPAEN_B)

/** GPIO port x clock disabled macros */
#define RCC_IOPH_CLK_DSBL()     CLEAN_BIT(RCC_REGMAP->IOPENR, RCC_IOPENR_IOPHEN_B)
#define RCC_IOPE_CLK_DSBL()     CLEAN_BIT(RCC_REGMAP->IOPENR, RCC_IOPENR_IOPEEN_B)
#define RCC_IOPD_CLK_DSBL()     CLEAN_BIT(RCC_REGMAP->IOPENR, RCC_IOPENR_IOPDEN_B)
#define RCC_IOPC_CLK_DSBL()     CLEAN_BIT(RCC_REGMAP->IOPENR, RCC_IOPENR_IOPCEN_B)
#define RCC_IOPB_CLK_DSBL()     CLEAN_BIT(RCC_REGMAP->IOPENR, RCC_IOPENR_IOPBEN_B)
#define RCC_IOPA_CLK_DSBL()     CLEAN_BIT(RCC_REGMAP->IOPENR, RCC_IOPENR_IOPAEN_B)


/*=====================================================================
 * AHB peripheral clock enable register (RCC_AHBENR) - Macros
 * Address: 0x30
 *=====================================================================*/
/** AHB's peripherals clock enabled macros */
#define RCC_CRYP_CLK_EN()       SET_BIT(RCC_REGMAP->AHBENR, RCC_AHBENR_CRYPEN_B)
#define RCC_RGN_CLK_EN()        SET_BIT(RCC_REGMAP->AHBENR, RCC_AHBENR_RNGEN_B)
#define RCC_TSC_CLK_EN()        SET_BIT(RCC_REGMAP->AHBENR, RCC_AHBENR_TSCEN_B)
#define RCC_CRC_CLK_EN()        SET_BIT(RCC_REGMAP->AHBENR, RCC_AHBENR_CRCEN_B)
#define RCC_MIF_CLK_EN()        SET_BIT(RCC_REGMAP->AHBENR, RCC_AHBENR_MIFEN_B)
#define RCC_DMA_CLK_EN()        SET_BIT(RCC_REGMAP->AHBENR, RCC_AHBENR_DMAEN_B)

/** AHB's peripherals clock disabled macros */
#define RCC_CRYP_CLK_DSBL()     CLEAN_BIT(RCC_REGMAP->AHBENR, RCC_AHBENR_CRYPEN_B)
#define RCC_RGN_CLK_DSBL()      CLEAN_BIT(RCC_REGMAP->AHBENR, RCC_AHBENR_RNGEN_B)
#define RCC_TSC_CLK_DSBL()      CLEAN_BIT(RCC_REGMAP->AHBENR, RCC_AHBENR_TSCEN_B)
#define RCC_CRC_CLK_DSBL()      CLEAN_BIT(RCC_REGMAP->AHBENR, RCC_AHBENR_CRCEN_B)
#define RCC_MIF_CLK_DSBL()      CLEAN_BIT(RCC_REGMAP->AHBENR, RCC_AHBENR_MIFEN_B)
#define RCC_DMA_CLK_DSBL()      CLEAN_BIT(RCC_REGMAP->AHBENR, RCC_AHBENR_DMAEN_B)


/*=====================================================================
 * APB2 peripheral clock enable register (RCC_APB2ENR) -Macros
 * Address: 0x34
 *=====================================================================*/
/** APB2's peripherals clock enabled macros */
#define RCC_DBG_CLK_EN()        SET_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_DBGEN_B)
#define RCC_USART1_CLK_EN()     SET_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_USART1EN_B)
#define RCC_SPI1_CLK_EN()       SET_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_SPI1EN_B)
#define RCC_ADC_CLK_EN()        SET_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_ADCEN_B)
#define RCC_FW_CLK_EN()         SET_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_FWEN_B)
#define RCC_TIM22_CLK_EN()      SET_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_TIM22EN_B)
#define RCC_TIM21_CLK_EN()      SET_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_TIM21EN_B)
#define RCC_SYSCF_CLK_EN()      SET_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_SYSCFGEN_B)


/** APB2's peripherals clock disabled macros */
#define RCC_DBG_CLK_DSBL()      CLEAN_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_DBGEN_B)
#define RCC_USART1_CLK_DSBL()   CLEAN_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_USART1EN_B)
#define RCC_SPI1_CLK_DSBL()     CLEAN_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_SPI1EN_B)
#define RCC_ADC_CLK_DSBL()      CLEAN_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_ADCEN_B)
#define RCC_FW_CLK_DSBL()       CLEAN_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_FWEN_B)
#define RCC_TIM22_CLK_DSBL()    CLEAN_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_TIM22EN_B)
#define RCC_TIM21_CLK_DSBL()    CLEAN_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_TIM21EN_B)
#define RCC_SYSCF_CLK_DSBL()    CLEAN_BIT(RCC_REGMAP->APB2ENR, RCC_APB2ENR_SYSCFGEN_B)

/*=====================================================================
 * APB1 peripheral clock enable register (RCC_APB1ENR) - Macros
 * Address: 0x38
 *=====================================================================*/
/** APB1's peripherals clock enabled macros */
#define RCC_LPTIM1_CLK_EN()     SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_LPTIM1EN_B)
#define RCC_I2C3_CLK_EN()       SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_I2C3EN_B)
#define RCC_DAC_CLK_EN()        SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_DACEN_B)
#define RCC_PWR_CLK_EN()        SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_PWREN_B)
#define RCC_CRS_CLK_EN()        SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_CRSEN_B)
#define RCC_USB_CLK_EN()        SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_USBEN_B)
#define RCC_I2C2_CLK_EN()       SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_I2C2EN_B)
#define RCC_I2C1_CLK_EN()       SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_I2C1EN_B)
#define RCC_USART5_CLK_EN()     SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_USART5EN_B)
#define RCC_USART4_CLK_EN()     SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_USART4EN_B)
#define RCC_LPUART1_CLK_EN()    SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_LPUART1EN_B)
#define RCC_USART2_CLK_EN()     SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_USART2EN_B)
#define RCC_SPI2_CLK_EN()       SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_SPI2EN_B)
#define RCC_WWDG_CLK_EN()       SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_WWDGEN_B)
#define RCC_LCD_CLK_EN()        SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_LCDEN_B)
#define RCC_TIM7_CLK_EN()       SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_TIM7EN_B)
#define RCC_TIM6_CLK_EN()       SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_TIM6EN_B)
#define RCC_TIM3_CLK_EN()       SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_TIM3EN_B)
#define RCC_TIM2_CLK_EN()       SET_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_TIM2EN_B)

/** APB1's peripherals clock disabled macros */
#define RCC_LPTIM1_CLK_DSBL()       CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_LPTIM1EN_B)
#define RCC_I2C3_CLK_DSBL()         CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_I2C3EN_B)
#define RCC_DAC_CLK_DSBL()          CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_DACEN_B)
#define RCC_PWR_CLK_DSBL()          CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_PWREN_B)
#define RCC_CRS_CLK_DSBL()          CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_CRSEN_B)
#define RCC_USB_CLK_DSBL()          CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_USBEN_B)
#define RCC_I2C2_CLK_DSBL()         CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_I2C2EN_B)
#define RCC_I2C1_CLK_DSBL()         CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_I2C1EN_B)
#define RCC_USART5_CLK_DSBL()       CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_USART5EN_B)
#define RCC_USART4_CLK_DSBL()       CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_USART4EN_B)
#define RCC_LPUART1_CLK_DSBL()      CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_LPUART1EN_B)
#define RCC_USART2_CLK_DSBL()       CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_USART2EN_B)
#define RCC_SPI2_CLK_DSBL()         CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_SPI2EN_B)
#define RCC_WWDG_CLK_DSBL()         CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_WWDGEN_B)
#define RCC_LCD_CLK_DSBL()          CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_LCDEN_B)
#define RCC_TIM7_CLK_DSBL()         CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_TIM7EN_B)
#define RCC_TIM6_CLK_DSBL()         CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_TIM6EN_B)
#define RCC_TIM3_CLK_DSBL()         CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_TIM3EN_B)
#define RCC_TIM2_CLK_DSBL()         CLEAN_BIT(RCC_REGMAP->APB1ENR, RCC_APB1ENR_TIM2EN_B)

/*Global variables declaration_____________________________________________________*/


/*Global function declaration______________________________________________________*/

/*
 *
 */
FUNC(void, EXTERN) rcc_IOPxClockControl(CONST(uint8_t,AUTO)iopxIndex, VAR(uint8_t,AUTO) control);
FUNC(void, EXTERN) rcc_I2CxClockControl(CONST(uint8_t,AUTO)i2cxIndex, VAR(uint8_t,AUTO) control);
FUNC(void, EXTERN) rcc_SPIxClockControl(CONST(uint8_t,AUTO)spiIndex,VAR(uint8_t,AUTO) control);

/*
 *
 */
FUNC(void, EXTERN) rcc_I2CxClockSource(CONST(uint8_t,AUTO)i2cxIndex, CONST(rcc_i2cxsel_t,AUTO) clockSource);

#endif /* RCC_STM32L053_RCC_DRIVER_H_ */
