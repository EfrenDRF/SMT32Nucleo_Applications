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
		gpio_Toggle_Pin(GPIOA_REGMAP, LD2_GREEN);
		__tr_DELAYms(500u); /* do nothing around 0.5ms */
	}

	return 0;
}

static void mySystemClok_Init(void)
{
	rcc_regMap_t  *const pRCC = RCC_REGMAP;

	// 1.- Configures MSI clock around 131kHz.
	pRCC->ICSCR &= ~(MEMMAP_3B_CLEAN << RCC_BITFP_MSIRANGE);
	pRCC->ICSCR |= ( RG1_131kHz << RCC_BITFP_MSIRANGE);

	// 2.- MSI oscillator clock is default selected at System clock.
	/* No action need it */

#if(EN_MCO_CLKOUT == TRUE)
	// 3.- Configures SYSCLK as Microcontroller clock output.
	pRCC->CFGR |= (MCO_OUT_SYSCLK << RCC_BITFP_MCOSEL);

	// 4.- Configures Microcontroller clock output prescaler divided by 16.
	pRCC->CFGR |= (MCO_DIV_16 << RCC_BITFP_MCOPRE);
#endif
}

static void myGPIO_Init(void)
{
	gpio_handle_t myGPIOPort;

	// 1.- Enables IOPORTA bus clock.
	RCC_IOPA_CLK_EN();

	// 2.- Holds GPIOA base address
	myGPIOPort.pGPIOx = GPIOA_REGMAP;

	// 3.- Configures PIN_5(LED green at Nucleo64 Board) as OUTPUT mode
	// NOTE: Please check your Board datasheet to modify the config pin.
	myGPIOPort.GPIOx_pinCfg.pinNumber = LD2_GREEN;
	myGPIOPort.GPIOx_pinCfg.mode = OUT_MODE;
	myGPIOPort.GPIOx_pinCfg.oType = OUT_PUSH_PULL;
	myGPIOPort.GPIOx_pinCfg.oSpeed = LS;
	myGPIOPort.GPIOx_pinCfg.pupd = NO_PUP_PDOWN;
	gpio_pinInit(&myGPIOPort);

#if(EN_MCO_CLKOUT == TRUE)
	// 4.- Configures PIN_8 ad Clock-out capability.
	myGPIOPort.GPIOx_pinCfg.pinNumber = PIN_8;
	myGPIOPort.GPIOx_pinCfg.mode = ALTFN_MODE;
	myGPIOPort.GPIOx_pinCfg.oType = OUT_PUSH_PULL;
	myGPIOPort.GPIOx_pinCfg.oSpeed = LS;
	myGPIOPort.GPIOx_pinCfg.pupd = PDOWN;
	myGPIOPort.GPIOx_pinCfg.altFun = AFSEL_8;
	gpio_pinInit(&myGPIOPort);
#endif
}
