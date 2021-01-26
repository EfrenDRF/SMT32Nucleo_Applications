/**
  ******************************************************************************
  * @file    _5_main.c
  * @author  Efren Del Real
  * @Date    January 23th 2021
  * @version V1.0
  * @brief   Application - Nucleo Board is configured as a master mode.
  *                        The user button is configured to send a SPI message
  *                        whether the button was pushed and then released.
  ******************************************************************************
*/

/*Include header files-------------------------*/
#include <string.h>
#include "stm32l053_rcc_driver.h"
#include "stm32l053_gpio_driver.h"
#include "stm32l053_spi_driver.h"

/*Local macro def ----------------------------*/
#define READ_BUTTON_STATE()		gpio_Read_Pin(GPIOC_REGMAP, PIN_13)

/*Global function declaration------------------*/
extern void myGPIO_Init(void);
extern void mySPI1_Init(void);

/*Local function declaration------------------*/
static void myDelay(void);

/*Global variable declaration-----------------*/


/*---------------------------------------------
 * Local function definition
 *--------------------------------------------*/

int main(void)
{
	gpio_pinst_t tmpPinst = PIN_LOW;
	uint8_t myData[] = "viva Mexico!";
	uint8_t myDataLen = strlen((char*)myData);

	// .- GPIO peripheral initialization.
	myGPIO_Init();

	// .- SPI peripheral initialization.
	mySPI1_Init();


	// .- Infinity loop.
	for(;;)
	{
		// .- Reads the user button status.
		tmpPinst = READ_BUTTON_STATE();
		myDelay();

		// .- Verifies that the Button goes from free to push.
		if ( (tmpPinst == PIN_HIGH) & (READ_BUTTON_STATE() == PIN_LOW))
		{
			// .- Do nothing until Button has been released.
			do
			{
				myDelay();
			}
			while(READ_BUTTON_STATE() == PIN_LOW);

			// .- The button is already released.

			spi_PeriphCtrl(SPI1_REGMAP, MEMMAP_BIT_SET);

			myDataLen |= 0xC0u;
			spi_SendData(SPI1_REGMAP, &myDataLen, strlen((char*)&myDataLen));
		    spi_SendData(SPI1_REGMAP, myData, strlen((char*)myData));

		    spi_PeriphCtrl(SPI1_REGMAP, MEMMAP_BIT_CLEAN);
		}
	}



	return 0;
}


/*
 *
 */
static void myDelay(void)
{
	uint16_t u16Index = 0u;

	for(u16Index =0u; (u16Index< 5000); u16Index++)
	{
		/* Not action required */
	}

}



