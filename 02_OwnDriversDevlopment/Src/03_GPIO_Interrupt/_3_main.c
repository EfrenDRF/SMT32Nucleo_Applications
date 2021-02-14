/**
  ******************************************************************************
  * @file    _3_main.c
  * @author  Efren Del Real
  * @Date    January 13th 2021
  * @version V1.0
  * @brief   Application - Configures a GPIO pin as an INPUT in order to configure
  *                        the external interrupt.
  *                        Due to User push button from Nucleo Board is already
  *                        hardware configured with pull up resistor. The interrupt
  *                        is configured as RISING TRIGGER EDGE to run whether the
  *                        user released the push button.
  ******************************************************************************
*/
/*Include header files-------------------------*/
#include <string.h>
#include "stm32l053_gpio_driver.h"
#include "stm32l053_rcc_driver.h"
#include "cordexM0p_nvic_driver.h"


/*Local macro def ----------------------------*/


/*Global variable declaration-----------------*/
gpio_handle_t pinGreenLED;
gpio_handle_t pinUserButton;

/*Local function declaration------------------*/
static void myGPIO_Init(void);



/*---------------------------------------------
 * Local function definition
 *--------------------------------------------*/

int main(void)
{
	// .- GPIO peripheral initialization.
	myGPIO_Init();

	// .- Infinity loop.
	for(;;);

	return 0;
}


static void myGPIO_Init(void)
{
	extern gpio_handle_t pinGreenLED;
	extern gpio_handle_t pinUserButton;

	// .- Cleans the GPIO handles
	memset(&pinGreenLED, 0u, sizeof(pinGreenLED));
	memset(&pinUserButton, 0u, sizeof(pinUserButton));

	// .- Configures the PORTA_5 to handle the green LED.
	pinGreenLED.gpioRegPtr = GPIOA_REGMAP;
	pinGreenLED.gpioPinCfg.gpioPinNum = PIN_5;
	pinGreenLED.gpioPinCfg.gpioPinMode = OUT_MODE;
	pinGreenLED.gpioPinCfg.gpioPinOutType = OUT_PUSH_PULL;
	pinGreenLED.gpioPinCfg.gpioPinOutSpeed = LOW_SPD;
	pinGreenLED.gpioPinCfg.gpioPinPuPd = NO_PULL_UP_PULL_DOWN;


	// .- Configures the PORTC_13 to handle the user push button.
	pinUserButton.gpioRegPtr = GPIOC_REGMAP;
	pinUserButton.gpioPinCfg.gpioPinNum = PIN_13;
	pinUserButton.gpioPinCfg.gpioPinMode = IN_IMR_MODE;
	pinUserButton.gpioPinCfg.gpioPinPuPd = NO_PULL_UP_PULL_DOWN;
	pinUserButton.gpioPinCfg.extiPinTriggerSel = RISING_TRG_EN;

	// .- Enables PORTA and PORTC clocks.
	RCC_IOPA_CLK_EN();
	RCC_IOPC_CLK_EN();

	// .- Configures the GPIO pin
	gpio_PinInit(&pinGreenLED);
	gpio_PinInit(&pinUserButton);


	// .- Enable the external interrupt.
	nvic_EnableIRQ(IRQn_EXTI4_15);

	// .- Set the priority of the external interrupt.
	nvic_SetPriority(IRQn_EXTI4_15, IRQn_PRI_1);

}


