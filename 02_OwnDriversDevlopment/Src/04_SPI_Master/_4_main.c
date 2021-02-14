/**
  ******************************************************************************
  * @file    _4_main.c
  * @author  Efren Del Real
  * @Date    January 23th 2021
  * @version V1.0
  * @brief   Test - The code below was written to test the currently available
  *                 SPI APIs (spi_Init and spi_SendData) using the emulator to
  *                 to verify the SFR configuration and the logic analyzer to be
  *                 able to watch the SPI frame message.
  ******************************************************************************
*/
/*Include header files-------------------------*/
#include <string.h>
#include "stm32l053_rcc_driver.h"
#include "stm32l053_gpio_driver.h"
#include "stm32l053_spi_driver.h"


/*Local macro def ----------------------------*/

/*Local function declaration------------------*/
static void mySPI1_GPIO_Init(void);
static void mySPI1_Init(void);

/*Global variable declaration-----------------*/
uint8_t myData[] = "SPI APIs test";

/*---------------------------------------------
 * Local function definition
 *--------------------------------------------*/

int main(void)
{
	// .- GPIO peripheral initialization.
	mySPI1_GPIO_Init();

	// .-
	mySPI1_Init();

	spi_PeriphCtrl(SPI1_REGMAP, BIT_SET);

	spi_SendData(SPI1_REGMAP, myData, strlen((char*)myData));

	// .- Infinity loop.
	for(;;);



	return 0;
}

/*
 *
 */
static void mySPI1_GPIO_Init(void)
{
	struct {
		/* NOTE: Chip select pin (NSS) is not configured due to
		 *       is configured in Software mode that means that
		 *       SPI_CR1_SSI_B bit is set to 1.
		 *
		 */
		gpio_handle_t SCK;   /*Arduino: D13 _ STM32: PA5*/
		gpio_handle_t MOSI;  /*Arduino: D11 _ STM32: PA7*/
	}SPI1pin;

	memset(&SPI1pin, 0u, sizeof(SPI1pin));

	SPI1pin.SCK.gpioRegPtr = GPIOA_REGMAP;
	SPI1pin.SCK.gpioPinCfg.gpioPinNum = PIN_5;
	SPI1pin.SCK.gpioPinCfg.gpioPinMode      = ALTFN_MODE;
	SPI1pin.SCK.gpioPinCfg.gpioPinAltFun    = ALT_FUN_0;

	SPI1pin.MOSI.gpioRegPtr = GPIOA_REGMAP;
	SPI1pin.MOSI.gpioPinCfg.gpioPinNum = PIN_7;
	SPI1pin.MOSI.gpioPinCfg.gpioPinMode      = ALTFN_MODE;
	SPI1pin.MOSI.gpioPinCfg.gpioPinAltFun    = ALT_FUN_0;


	// .- Configures the GPIO pin
	gpio_PinInit(&SPI1pin.SCK);
	gpio_PinInit(&SPI1pin.MOSI);

}

/*
 *
 */
static void mySPI1_Init(void)
{
	spi_handle_t SPI1Handle;

	SPI1Handle.spiRegPtr = SPI1_REGMAP;
	SPI1Handle.spiCfg.devMode = MASTER_MODE;
	SPI1Handle.spiCfg.comMode = SIMPLEX_TX_ONLY;
	SPI1Handle.spiCfg.cbr     = FPCLK_DIV_8;
	SPI1Handle.spiCfg.cpol    = HIGH_IDLE_CLK;
	SPI1Handle.spiCfg.cpha    = RISING_EDGE_CLK;
	SPI1Handle.spiCfg.ssm     = SW_NSS_MODE;
	SPI1Handle.spiCfg.ff      = MSB_FIRST;
	SPI1Handle.spiCfg.dff     = _8BIT_DFF;
	
	spi_Init(&SPI1Handle);
}


