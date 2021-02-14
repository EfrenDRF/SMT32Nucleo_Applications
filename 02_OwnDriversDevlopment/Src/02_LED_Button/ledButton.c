/**
  ******************************************************************************
  * @file    ledButton.c
  * @author  Efren Del Real
  * @Date    January 5th 2021
  * @version V1.0
  * @brief   Application - The pin connected to user button has been configured
  *          an input to read when is present or not. The button has to execute
  *          a process until the user release the button. that means whether is
  *          present the button must not perform an action.
  *          Pin connected to green LED is configure as an output in order to
  *          perform the action after release the button.
  ******************************************************************************
*/
/*Include header files-------------------------*/
#include "stm32l053_gpio_driver.h"
#include "stm32l053_rcc_driver.h"

/* Local macro def ----------------------------*/
#define LD2_GREEN				PIN_5
#define B1_USER					PIN_13

#define	TOGGLE_LED_GREEN()		gpio_TogglePin(GPIOA_REGMAP, LD2_GREEN)
#define READ_BUTTON_STATE()		gpio_ReadPin(GPIOC_REGMAP, B1_USER)


/*Local function def-----------------------------*/
static void myGPIO_Init(void);
static void myDelay(void);

int main(void)
{

	gpio_pinst_t tmpPinst = PIN_LOW;


	/* Peripheral initialization */
	myGPIO_Init();

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

			// .- The button is already released. So, It changes the output state.
			TOGGLE_LED_GREEN();
		}
	}

	return 0;
}


static void myGPIO_Init(void)
{
	gpio_handle_t myGPIOPort;

	/* Pin 5 configured as Output to manage the green led.*/
	myGPIOPort.gpioRegPtr = GPIOA_REGMAP;
	myGPIOPort.gpioPinCfg.gpioPinNum = LD2_GREEN;
	myGPIOPort.gpioPinCfg.gpioPinMode = OUT_MODE;
	myGPIOPort.gpioPinCfg.gpioPinOutType = OUT_PUSH_PULL;
	myGPIOPort.gpioPinCfg.gpioPinOutSpeed = LOW_SPD;
	myGPIOPort.gpioPinCfg.gpioPinPuPd = NO_PULL_UP_PULL_DOWN;

	RCC_IOPA_CLK_EN();
	gpio_PinInit(&myGPIOPort);

	/*Pin 13 configured as Input to read the User Button status*/
	myGPIOPort.gpioRegPtr = GPIOC_REGMAP;
	myGPIOPort.gpioPinCfg.gpioPinNum = B1_USER;
	myGPIOPort.gpioPinCfg.gpioPinMode = IN_MODE;
	myGPIOPort.gpioPinCfg.gpioPinPuPd = NO_PULL_UP_PULL_DOWN;

	RCC_IOPC_CLK_EN();
	gpio_PinInit(&myGPIOPort);

}

static void myDelay(void)
{
	uint16_t u16Index = 0u;

	for(u16Index =0u; (u16Index< 5000); u16Index++)
	{
		/* Not action required */
	}

}


