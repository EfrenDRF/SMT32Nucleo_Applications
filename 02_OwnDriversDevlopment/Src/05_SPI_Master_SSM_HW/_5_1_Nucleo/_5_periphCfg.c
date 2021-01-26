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
	SPI1pin.NSS.pGPIOx = GPIOA_REGMAP;
	SPI1pin.NSS.GPIOx_pinCfg.pinNumber = PIN_4;
	SPI1pin.NSS.GPIOx_pinCfg.mode      = ALTFN_MODE;
	SPI1pin.NSS.GPIOx_pinCfg.oType     = OUT_PUSH_PULL;
	SPI1pin.NSS.GPIOx_pinCfg.pupd      = NO_PUP_PDOWN;
	SPI1pin.NSS.GPIOx_pinCfg.altFun    = AFSEL_0;

	// .- Clock pin config
	SPI1pin.SCK.pGPIOx = GPIOA_REGMAP;
	SPI1pin.SCK.GPIOx_pinCfg.pinNumber = PIN_5;
	SPI1pin.SCK.GPIOx_pinCfg.mode      = ALTFN_MODE;
	SPI1pin.SCK.GPIOx_pinCfg.oType     = OUT_PUSH_PULL;
	SPI1pin.SCK.GPIOx_pinCfg.pupd      = NO_PUP_PDOWN;
	SPI1pin.SCK.GPIOx_pinCfg.altFun    = AFSEL_0;

	// .- MOSI pin config
	SPI1pin.MOSI.pGPIOx = GPIOA_REGMAP;
	SPI1pin.MOSI.GPIOx_pinCfg.pinNumber = PIN_7;
	SPI1pin.MOSI.GPIOx_pinCfg.mode      = ALTFN_MODE;
	SPI1pin.MOSI.GPIOx_pinCfg.oType     = OUT_PUSH_PULL;
	SPI1pin.MOSI.GPIOx_pinCfg.pupd      = NO_PUP_PDOWN;
	SPI1pin.MOSI.GPIOx_pinCfg.altFun    = AFSEL_0;


	// .- Set up the SPI GPIO pins as alternate function mode.
	RCC_IOPA_CLK_EN();
	gpio_pinInit(&SPI1pin.NSS);
	gpio_pinInit(&SPI1pin.SCK);
	gpio_pinInit(&SPI1pin.MOSI);


	// .- Configures pin 13 from port C as input in order to use the user button.
	userB1.pGPIOx = GPIOC_REGMAP;
	userB1.GPIOx_pinCfg.pinNumber   = PIN_13;
	userB1.GPIOx_pinCfg.mode        = IN_MODE;
	userB1.GPIOx_pinCfg.pupd        = NO_PUP_PDOWN;

	RCC_IOPC_CLK_EN();
	gpio_pinInit(&userB1);

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
