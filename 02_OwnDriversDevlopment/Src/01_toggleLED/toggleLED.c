/**
  ******************************************************************************
  * @file    toggleLED.c
  * @author  Efren Del Real
  * @Date    January 2nd 2021
  * @version V1.0
  * @brief   Application - handle the green LED that is at Nucleo board to toggle
  *          the output state around 0.5s using the gpio own dev driver.
  *          Also it is configured the MCO at 131 kHz to develop a time delay routine
  *          in milliseconds.
  ******************************************************************************
*/
/*Include header files-------------------------*/
#include "stm32l053_gpio_driver.h"
#include "stm32l053_rcc_driver.h"

#define TRUE	1u
#define FALSE	0u

#define EN_MCO_CLKOUT	FALSE  /* must change to TRUE whether you have to measure the MCO at PinA8 */
#define LD2_GREEN		PIN_5


/*Global function def----------------------------*/
extern void __tr_DELAYms(uint16_t u16Millisec);

/*Local function def-----------------------------*/
static void mySystemClok_Init(void);
static void myGPIO_Init(void);


int main(void)
{
	/* Peripheral initialization */
	mySystemClok_Init();
	myGPIO_Init();

	for(;;)
	{
		gpio_TogglePin(GPIOA_REGMAP, LD2_GREEN);
		__tr_DELAYms(500u); /* do nothing around 0.5ms */
	}

	return 0;
}

static void mySystemClok_Init(void)
{
	rcc_regMap_t  *const pRCC = RCC_REGMAP;

	// 1.- Configures MSI clock around 131kHz.
	pRCC->ICSCR &= ~(CLEAN_3B << RCC_ICSCR_MSIRANGE_B);
	pRCC->ICSCR |= ( RG1_131kHz << RCC_ICSCR_MSIRANGE_B);

	// 2.- MSI oscillator clock is default selected at System clock.
	/* No action need it */

#if(EN_MCO_CLKOUT == TRUE)
	// 3.- Configures SYSCLK as Microcontroller clock output.
	pRCC->CFGR |= (MCO_OUT_SYSCLK << RCC_CFGR_MCOSEL_B);

	// 4.- Configures Microcontroller clock output prescaler divided by 16.
	pRCC->CFGR |= (MCO_DIV_16 << RCC_CFGR_MCOPRE_B);
#endif
}

static void myGPIO_Init(void)
{
	gpio_handle_t myGPIOPort;

	// 1.- Holds GPIOA base address
	myGPIOPort.gpioRegPtr = GPIOA_REGMAP;

	// 2.- Configures PIN_5(LED green at Nucleo64 Board) as OUTPUT mode
	// NOTE: Please check your Board datasheet to modify the config pin.
	myGPIOPort.gpioPinCfg.gpioPinNum = LD2_GREEN;
	myGPIOPort.gpioPinCfg.gpioPinMode = OUT_MODE;
	myGPIOPort.gpioPinCfg.gpioPinOutType = OUT_PUSH_PULL;
	myGPIOPort.gpioPinCfg.gpioPinOutSpeed = LOW_SPD;
	myGPIOPort.gpioPinCfg.gpioPinPuPd = NO_PULL_UP_PULL_DOWN;
	gpio_PinInit(&myGPIOPort);

#if(EN_MCO_CLKOUT == TRUE)
	// 3.- Configures PIN_8 ad Clock-out capability.
	myGPIOPort.gpioPinCfg.gpioPinNum = PIN_8;
	myGPIOPort.gpioPinCfg.gpioPinMode = ALTFN_MODE;
	myGPIOPort.gpioPinCfg.gpioPinOutType = OUT_PUSH_PULL;
	myGPIOPort.gpioPinCfg.gpioPinOutSpeed = LOW_SPD;
	myGPIOPort.gpioPinCfg.gpioPinPuPd = PULL_DOWN;
	myGPIOPort.gpioPinCfg.gpioPinAltFun = AFSEL_8;
	gpio_PinInit(&myGPIOPort);
#endif
}
