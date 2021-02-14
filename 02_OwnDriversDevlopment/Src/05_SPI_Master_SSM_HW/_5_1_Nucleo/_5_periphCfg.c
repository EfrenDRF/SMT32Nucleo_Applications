/**
  ******************************************************************************
  * @file    _5_periphCfg.c
  * @author  Efren Del Real
  * @Date    January 24th 2021
  * @version V1.0
  * @brief   Configuration - Sets the GPIO and SPI handles in order to enable
  *                          the SPI peripheral as Master mode and Simplex Tx
  *                          communication mode.
  ******************************************************************************
*/

/*Include header files-------------------------*/
#include <string.h>
#include "stm32l053_rcc_driver.h"
#include "stm32l053_gpio_driver.h"
#include "stm32l053_spi_driver.h"


/*
 *
 */
void myGPIO_Init(void)
{
	gpio_handle_t userB1;

	struct {
		gpio_handle_t NSS;   /*Arduino: A2  _ Nucleo: PA4*/
		gpio_handle_t SCK;   /*Arduino: D13 _ Nucleo: PA5*/
		gpio_handle_t MOSI;  /*Arduino: D11 _ Nucleo: PA7*/
	}SPI1pin;

	memset(&userB1,0,sizeof(userB1));
	memset(&SPI1pin, 0u, sizeof(SPI1pin));

    // .- Chip Select pin config.
	SPI1pin.NSS.gpioRegPtr = GPIOA_REGMAP;
	SPI1pin.NSS.gpioPinCfg.gpioPinNum = PIN_4;
	SPI1pin.NSS.gpioPinCfg.gpioPinMode      = ALTFN_MODE;
	SPI1pin.NSS.gpioPinCfg.gpioPinOutType     = OUT_PUSH_PULL;
	SPI1pin.NSS.gpioPinCfg.gpioPinPuPd      = NO_PULL_UP_PULL_DOWN;
	SPI1pin.NSS.gpioPinCfg.gpioPinAltFun    = ALT_FUN_0;

	// .- Clock pin config
	SPI1pin.SCK.gpioRegPtr = GPIOA_REGMAP;
	SPI1pin.SCK.gpioPinCfg.gpioPinNum = PIN_5;
	SPI1pin.SCK.gpioPinCfg.gpioPinMode      = ALTFN_MODE;
	SPI1pin.SCK.gpioPinCfg.gpioPinOutType     = OUT_PUSH_PULL;
	SPI1pin.SCK.gpioPinCfg.gpioPinPuPd      = NO_PULL_UP_PULL_DOWN;
	SPI1pin.SCK.gpioPinCfg.gpioPinAltFun    = ALT_FUN_0;

	// .- MOSI pin config
	SPI1pin.MOSI.gpioRegPtr = GPIOA_REGMAP;
	SPI1pin.MOSI.gpioPinCfg.gpioPinNum = PIN_7;
	SPI1pin.MOSI.gpioPinCfg.gpioPinMode      = ALTFN_MODE;
	SPI1pin.MOSI.gpioPinCfg.gpioPinOutType     = OUT_PUSH_PULL;
	SPI1pin.MOSI.gpioPinCfg.gpioPinPuPd      = NO_PULL_UP_PULL_DOWN;
	SPI1pin.MOSI.gpioPinCfg.gpioPinAltFun    = ALT_FUN_0;


	// .- Set up the SPI GPIO pins as alternate function mode.
	RCC_IOPA_CLK_EN();
	gpio_PinInit(&SPI1pin.NSS);
	gpio_PinInit(&SPI1pin.SCK);
	gpio_PinInit(&SPI1pin.MOSI);


	// .- Configures pin 13 from port C as input in order to use the user button.
	userB1.gpioRegPtr = GPIOC_REGMAP;
	userB1.gpioPinCfg.gpioPinNum   = PIN_13;
	userB1.gpioPinCfg.gpioPinMode        = IN_MODE;
	userB1.gpioPinCfg.gpioPinPuPd        = NO_PULL_UP_PULL_DOWN;

	RCC_IOPC_CLK_EN();
	gpio_PinInit(&userB1);

}

/*
 *
 */
void mySPI1_Init(void)
{
	spi_handle_t SPI1Handle;

	SPI1Handle.pSPIx = SPI1_REGMAP;
	SPI1Handle.SPIcfg.devMode = MASTER_MODE;
	SPI1Handle.SPIcfg.comMode = SIMPLEX_TX_ONLY;
	SPI1Handle.SPIcfg.cbr     = FPCLK_DIV_128;
	SPI1Handle.SPIcfg.cpol    = LOW_IDLE_CLK;
	SPI1Handle.SPIcfg.cpha    = FALLING_EDGE_CLK;
	SPI1Handle.SPIcfg.ssm     = HW_NSS_MODE;
	SPI1Handle.SPIcfg.ff      = MSB_FIRST;
	SPI1Handle.SPIcfg.dff     = _8BIT_DFF;


	RCC_SPI1_CLK_EN();
	spi_Init(&SPI1Handle);
}
