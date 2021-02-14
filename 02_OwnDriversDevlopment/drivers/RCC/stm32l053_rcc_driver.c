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

/*Global variable definition_______________________________________________________*/
CONST(uint8_t, AUTO) rcc_constIOPXENBIT[GPIOMAX_INDEX] =
{
		RCC_IOPENR_IOPAEN_B,
		RCC_IOPENR_IOPBEN_B,
		RCC_IOPENR_IOPCEN_B,
		RCC_IOPENR_IOPDEN_B,
		RCC_IOPENR_IOPEEN_B,
		RCC_IOPENR_IOPHEN_B
};
/*=====================================================================
 * Local function definition
 *=====================================================================*/

/*=====================================================================
 * Global function definition
 *=====================================================================*/

/****************************************************************
 * @fn			- rcc_GPIOxClkCtrl.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		- none
 */
FUNC(void, AUTO) rcc_GPIOxClkCtrl(CONST(uint8_t,AUTO)port_x, VAR(uint8_t,AUTO) control)
{
	if(control == RCC_CLK_EN)
	{
		SET_BIT( RCC_REGMAP->IOPENR, port_x);
	}
	else
	{
		CLEAN_BIT(RCC_REGMAP->IOPENR, port_x);
	}

}
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
FUNC(uint8_t, AUTO)rcc_I2CxClkSrc(VAR(rcc_i2cxsel_t,AUTO) clkSrc, VAR(uint8_t,AUTO) i2cxBit)
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
			RCC_REGMAP->CCIPR &= ~( CLEAN_2B << i2cxBit);
			RCC_REGMAP->CCIPR |= ( clkSrc << i2cxBit);
		}
	}

	return retVal;

}
