/**
  ******************************************************************************
  * @file    stm32l053_rcc_driver.h
  * @author  Efren Del Real
  * @Date    February 7th 2021
  * @version V1.0
  * @brief   Reset and clock control - driver
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
**/

/*Include header files____________________________________________________________*/
#include "stm32l053_rcc_driver.h"

/*Macro definition_________________________________________________________________*/

/*Local function declaration_______________________________________________________*/

/*=====================================================================
 * Local function definition
 *=====================================================================*/

/*=====================================================================
 * Global function definition
 *=====================================================================*/

/****************************************************************
 * @fn			- rcc_I2CxClkSrc.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		- none
 */
uint8_t rcc_I2CxClkSrc(rcc_i2cxsel_t clkSrc, uint8_t i2cxBit)
{
	uint8_t retVal = RCC_NOTOK;

	if( (i2cxBit == RCC_CCIPR_I2C3SEL_B) || \
		(i2cxBit == RCC_CCIPR_I2C2SEL_B) || \
		(i2cxBit == RCC_CCIPR_I2C1SEL_B) )
	{
		if( (clkSrc == APB_AS_I2C_CLK) || \
			(clkSrc == SYSTEM_AS_I2C_CLK) || \
			(clkSrc == HSI16_AS_I2C_CLK) )
		{
			retVal = RCC_OK;
			RCC_REGMAP->CCIPR &= ~( MEMMAP_2B_CLEAN << i2cxBit);
			RCC_REGMAP->CCIPR |= ( clkSrc << i2cxBit);
		}
	}

	return retVal;

}
