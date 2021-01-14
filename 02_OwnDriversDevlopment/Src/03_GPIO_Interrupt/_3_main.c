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
	pinGreenLED.pGPIOx = GPIOA_REGMAP;
	pinGreenLED.GPIOx_pinCfg.pinNumber = PIN_5;
	pinGreenLED.GPIOx_pinCfg.mode = OUT_MODE;
	pinGreenLED.GPIOx_pinCfg.oType = OUT_PUSH_PULL;
	pinGreenLED.GPIOx_pinCfg.oSpeed = LS;
	pinGreenLED.GPIOx_pinCfg.pupd = NO_PUP_PDOWN;


	// .- Configures the PORTC_13 to handle the user push button.
	pinUserButton.pGPIOx = GPIOC_REGMAP;
	pinUserButton.GPIOx_pinCfg.pinNumber = PIN_13;
	pinUserButton.GPIOx_pinCfg.mode = IN_IMR_MODE;
	pinUserButton.GPIOx_pinCfg.pupd = NO_PUP_PDOWN;
	pinUserButton.GPIOx_pinCfg.triggerSel = RISING_TRG_EN;

	// .- Enables PORTA and PORTC clocks.
	RCC_IOPA_CLK_EN();
	RCC_IOPC_CLK_EN();

	// .- Configures the GPIO pin
	gpio_pinInit(&pinGreenLED);
	gpio_pinInit(&pinUserButton);


	// .- Enable the external interrupt.
	nvic_EnableIRQ(IRQn_EXTI4_15);

	// .- Set the priority of the external interrupt.
	nvic_SetPriority(IRQn_EXTI4_15, IRQn_PRI_1);

}


