/**
  ******************************************************************************
  * @file    stm32l053_syscfg_driver.c
  * @author  Efren Del Real
  * @Date    January 8th 2021
  * @version V1.0
  * @brief   System configuration controller driver.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************
*/



/*Include header files____________________________________________________________*/
#include "stm32l053_syscfg_driver.h"

/*Macro definition_________________________________________________________________*/


/*Global function declaration______________________________________________________*/


/****************************************************************
 * @fn          - syscfg_EXTI_Cfg
 *
 * @brief		- Managing external interrupts line multiplexing
 *                to the internal edge detector.
 *
 * @param[in]   -
 *
 * @param[in]   -
 *
 * @return      - none.
 *
 * @Note        -
 */
void syscfg_EXTI_Cfg(const gpio_regMap_t * const pGPIOx, gpio_pinNum_t pinNum)
{
	syscfg_exti_t tmpSrcEXTIx = EXTI_PA;
	uint8_t tmpEXTIx;
	uint8_t tmpCfgr;

	// 1.- Selects the source input for the EXTIx external interrupt.
	if (pGPIOx == GPIOA_REGMAP){tmpSrcEXTIx = EXTI_PA;}
	else if (pGPIOx == GPIOB_REGMAP){tmpSrcEXTIx = EXTI_PB;}
	else if (pGPIOx == GPIOC_REGMAP){tmpSrcEXTIx = EXTI_PC;}
	else if (pGPIOx == GPIOD_REGMAP){tmpSrcEXTIx = EXTI_PD;}
	else if (pGPIOx == GPIOE_REGMAP){tmpSrcEXTIx = EXTI_PE;}
	else if (pGPIOx == GPIOH_REGMAP){tmpSrcEXTIx = EXTI_PH;}
	else
	{
		/* No action required - Avoid MISRA*/
	}

	// 2.- Selects the EXTIx bits filed.
	tmpEXTIx = (pinNum & 0x02u);

	// 3.- Selects the external interrupt configuration register from 0 to 3
	tmpCfgr = (pinNum >> 0x02u) & 0x02;

	// 4.- Cleans the EXTIx bits field.
	SYSCFG_REGMAP->EXTICR[tmpCfgr] &= ~ ( MEMMAP_4B_CLEAN << (4u * tmpEXTIx) );

	// 5.- Sets the source input into EXTIx bits field.
	SYSCFG_REGMAP->EXTICR[tmpCfgr] |= ( tmpSrcEXTIx << (4u * tmpEXTIx) );

}
