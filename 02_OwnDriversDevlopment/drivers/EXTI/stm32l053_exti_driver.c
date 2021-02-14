/**
  ******************************************************************************
  * @file    stm32l053_exti_driver.c
  * @author  Efren Del Real
  * @Date    January 8th 2021
  * @version V1.0
  * @brief   Extended interrupts and events controller driver.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************
*/


/*Include header files____________________________________________________________*/
#include "stm32l053_exti_driver.h"

/*Macro definition_________________________________________________________________*/

/*Global function declaration______________________________________________________*/


/****************************************************************
 * @fn			- exti_triggerSel_Cfg.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @param[in]
 *
 * @return		- none.
 *
 * @Note		-
 */

void exti_triggerSel_Cfg(uint8_t line_x, exti_rtsr_t triggerSel)
{

	switch(triggerSel)
	{
	case RISING_TRG_EN:
		/* Rising trigger enabled (for Event and Interrupt) for input line x */
		CLEAN_BIT(EXTI_REGMAP->FTSR, line_x);
		SET_BIT(EXTI_REGMAP->RTSR, line_x);
		break;
	case FALLING_TRG_EN:
		/* Falling trigger enabled (for Event and Interrupt) for input line x */
		CLEAN_BIT(EXTI_REGMAP->RTSR, line_x);
		SET_BIT(EXTI_REGMAP->FTSR, line_x);
		break;
	case RISING_FALLING_TRG_EN:
		/* Rising and falling edge triggers for input line x */
		SET_BIT(EXTI_REGMAP->RTSR, line_x);
		SET_BIT(EXTI_REGMAP->FTSR, line_x);
		break;
	default:
			/* No action required - avoid MISRA */
		break;

	}
}


/****************************************************************
 * @fn			- exti_GetPendingSrcLine.
 *
 * @brief		- Reads pending interrupt flag on source line x.
 *
 * @param[in]	- line_x -trigger source line (22 .. 19 and
 *                17 .. 0 are the available src lines)
 *
 *
 * @return		- return non zero value whether the trigger request
 *                ocurred.
 *
 * @Note		- This bit is set when the selected edge event
 *                arrives on the interrupt line. This bit is cleared
 *                by writing it to 1 (use EXTI_PR_CLEAN_LINEx()) or
 *                by changing the sensitivity of the edge detector.
 */

uint8_t exti_GetPendingSrcLine(uint8_t line_x)
{
	uint8_t retValue =0u;

	retValue =(uint8_t)((EXTI_REGMAP->PR >> line_x) & 1u);

	return retValue;
}


/****************************END OF FILE *******************************************/
