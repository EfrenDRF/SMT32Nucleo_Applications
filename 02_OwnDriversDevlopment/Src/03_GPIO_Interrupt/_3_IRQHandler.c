/**
  ******************************************************************************
  * @file    _3_IRQHandler.c
  * @author  Efren Del Real
  * @Date    January 13th 2021
  * @version V1.0
  * @brief   Application - Defines the IRQ handler to handle an external interrupt
  *                        at source line 13. The corresponding handler must be
  *                        taken from startup_stm32l053r8tx.s already provided by ST
  *                        in order to get the function address vector table
  *                        configured properly.
  ******************************************************************************
*/
/*Include header files-------------------------*/
#include <string.h>
#include "stm32l053_gpio_driver.h"
#include "stm32l053_exti_driver.h"

/*Local macro def ----------------------------*/

#define PIN_IN_EXTI	pinUserButton
#define PIN_OUT		pinGreenLED

#define	TOGGLE_LED_GREEN()		gpio_TogglePin(PIN_OUT.gpioRegPtr, PIN_OUT.gpioPinCfg.gpioPinNum)
#define LINE_SRC				PIN_IN_EXTI.gpioPinCfg.gpioPinNum


/*Global variable declaration ----------------*/
extern gpio_handle_t PIN_IN_EXTI;
extern gpio_handle_t PIN_OUT;


void EXTI4_15_IRQHandler(void)
{
	// .- Read the source interrupt flag
	if(exti_GetPendingSrcLine(LINE_SRC) == 1u)
	{
		// .- Change the output pin value.
		TOGGLE_LED_GREEN();

		// .- Cleans the source interrupt flag
		//    in order to be able to use it again.
		EXTI_PR_CLEAN_LINEx(LINE_SRC);
	}

}
