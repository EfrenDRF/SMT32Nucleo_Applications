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

void exti_triggerSel_Cfg(uint8_t line_x, exti_rtsr_t trgSel)
{

	switch(trgSel)
	{
	case RTS:
		/* Rising trigger enabled (for Event and Interrupt) for input line x */
		MEMMAP_CLEAN_BIT(EXTI_REGMAP->RTSR, line_x);
		MEMMAP_SET_BIT(EXTI_REGMAP->RTSR, line_x);
		break;
	case FTS:
		/* Falling trigger enabled (for Event and Interrupt) for input line x */
		MEMMAP_CLEAN_BIT(EXTI_REGMAP->FTSR, line_x);
		MEMMAP_SET_BIT(EXTI_REGMAP->FTSR, line_x);
		break;
	case RFTS:
		/* Rising and falling edge triggers for input line x */
		MEMMAP_SET_BIT(EXTI_REGMAP->RTSR, line_x);
		MEMMAP_SET_BIT(EXTI_REGMAP->FTSR, line_x);
		break;
	default:
			/* No action required - avoid MISRA */
		break;

	}
}
