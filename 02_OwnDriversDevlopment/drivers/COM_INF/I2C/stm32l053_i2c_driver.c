/**
  ******************************************************************************
  * @file    stm32l053_i2c_driver.c
  * @author  Efren Del Real
  * @Date    February 1st 2021
  * @version V1.0
  * @brief   Inter-integrated circuit interface - Definition driver APIs
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/

/*Include header files____________________________________________________________*/
#include "stm32l053_i2c_driver.h"
#include "stm32l053_rcc_driver.h"

/*Macro definition_________________________________________________________________*/


/*Local function declaration_______________________________________________________*/


/*=====================================================================
 * Local function definition
 *=====================================================================*/

/****************************************************************
 * @fn			- i2c_GetI2CIndex.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
FUNC(uint8_t, STATIC) i2c_GetI2CIndex(CONSTPTR2_CONST(i2c_regMap_t,AUTO)i2cRegPtr)
{
	VAR(uint8_t,AUTO) retVal = 0u;

	if (i2cRegPtr == I2C1_REGMAP){retVal = I2C1_INDEX;}
	else if (i2cRegPtr == I2C2_REGMAP){retVal = I2C2_INDEX;}
	else if (i2cRegPtr == I2C3_REGMAP){retVal = I2C3_INDEX;}
	else
	{
		/* Avoid Misra rule 15.7 */
	}

	return retVal;
}



/*=====================================================================
 * Global function definition
 *=====================================================================*/

/****************************************************************
 * @fn			- rcc_I2C_clockSrc.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		- none
 */
FUNC(void,AUTO) i2c_Init(CONSTPTR2_VAR(i2c_handle_t,AUTO) i2cHandlePtr)
{
	CONSTPTR2_VAR(i2c_regMap_t,AUTO) i2cRegPtr = i2cHandlePtr->i2cRegPtr;
	CONSTPTR2_CONST(i2c_cfg_t,AUTO)  i2cCfgPrt = &i2cHandlePtr->i2cCfg;
	CONST(uint8_t,AUTO) i2cIndex = i2c_GetI2CIndex(i2cRegPtr);


	rcc_I2CxClkCtrl(i2cIndex,RCC_CLK_EN);


	// .- Clear PE bit in I2C_CR1
	CLEAN_BIT(i2cRegPtr->CR1 , I2C_CR1_PE_B);

	//.- Wait until PE bit is clean.
	while( (i2cRegPtr->CR1 & (1u << I2C_CR1_PE_B)) != BIT_CLEAN)
	{/* Avoid Misra */}

	// .-Set PE bit in I2C_CR1
	SET_BIT(i2cRegPtr->CR1 , I2C_CR1_PE_B);

	// .-
	rcc_I2CxClkSrc(i2cIndex, i2cCfgPrt->rccI2CclkSrc);

}


/****************************END OF FILE *******************************************/
