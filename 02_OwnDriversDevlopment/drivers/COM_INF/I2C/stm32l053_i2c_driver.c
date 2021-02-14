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
static inline void    i2c_PeripheClkCtrl   (const i2c_regMap_t * const i2cRegPtr, uint8_t rccClkCtrl);
static inline uint8_t i2c_GetClkSrcSelBits (const i2c_regMap_t * const i2cRegPtr);



/*=====================================================================
 * Local function definition
 *=====================================================================*/
/****************************************************************
 * @fn			- i2c_PeripheClkCtrl.
 *
 * @brief		-
 *
 * @param[in]	- I2Cx register map base address.
 * @param[in]	- Clock control(Enable/Disable).
 *
 * @return		- none
 *
 * @Note		- none
 */
static inline void i2c_PeripheClkCtrl(const i2c_regMap_t * const i2cRegPtr, uint8_t rccClkCtrl)
{

	if(i2cRegPtr == I2C3_REGMAP)
	{
		if(rccClkCtrl == RCC_CLK_EN) { RCC_I2C3_CLK_EN();}
		else { RCC_I2C3_CLK_DSBL();}
	}
	else if(i2cRegPtr == I2C2_REGMAP)
	{
		if(rccClkCtrl == RCC_CLK_EN) { RCC_I2C2_CLK_EN();}
		else { RCC_I2C2_CLK_DSBL();}
	}
	else if(i2cRegPtr == I2C1_REGMAP)
	{
		if(rccClkCtrl == RCC_CLK_EN) { RCC_I2C1_CLK_EN();}
		else { RCC_I2C1_CLK_DSBL();}
	}
	else{ /* Avoid Misra */ }

}

/****************************************************************
 * @fn			- i2c_GetClkSrcSelBits.
 *
 * @brief		- Gets I2CxSEL's bit position of RCC_CCIPR
 *                register.
 *
 * @param[in]	- I2Cx register map base address.
 *
 * @return		- Non zero value whether i2c reg map matches
 *                with whathever of three i2c base address
 *                availables.
 *
 * @Note		- none
 */
static inline uint8_t i2c_GetClkSrcSelBits(const i2c_regMap_t * const i2cRegPtr)
{
	uint8_t retVal = 0u;

	if(i2cRegPtr == I2C3_REGMAP) {retVal = RCC_CCIPR_I2C3SEL_B;}
	else if(i2cRegPtr == I2C2_REGMAP){retVal = RCC_CCIPR_I2C2SEL_B;}
	else if(i2cRegPtr == I2C1_REGMAP){retVal = RCC_CCIPR_I2C1SEL_B;}
	else{ /* Avoid Misra */ }

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
void i2c_Init(i2c_handle_t * i2cHandlePtr)
{
	i2c_regMap_t * const     tmpI2cReg = i2cHandlePtr->i2cRegPtr;
	i2c_cfg_t  const * const tmpI2cCfg = &i2cHandlePtr->i2cCfg;
	uint8_t u8Tmp = 0u;

	// .-
	i2c_PeripheClkCtrl(tmpI2cReg, RCC_CLK_EN);

	// .- Clear PE bit in I2C_CR1
	CLEAN_BIT(tmpI2cReg->CR1 , I2C_CR1_PE_B);

	//.- Wait until PE bit is clean.
	while( (tmpI2cReg->CR1 & (1u << I2C_CR1_PE_B)) != BIT_CLEAN)
	{/* Avoid Misra */}

	// .-Set PE bit in I2C_CR1
	SET_BIT(tmpI2cReg->CR1 , I2C_CR1_PE_B);

	// .-
	u8Tmp = i2c_GetClkSrcSelBits(tmpI2cReg);
	(void)rcc_I2CxClkSrc(tmpI2cCfg->rccI2CclkSrc, u8Tmp);

}



