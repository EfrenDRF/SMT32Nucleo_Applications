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


/*typedef definition_______________________________________________________________*/
/*
 *
 */
typedef void (*i2cFunInitPtr)(CONSTPTR2_VAR(i2c_handle_t,AUTO) i2cHandlePtr);


/*Local function declaration_______________________________________________________*/
FUNC(uint8_t,STATIC) i2c_GetI2CIndex(CONSTPTR2_CONST(i2c_regMap_t,AUTO)i2cRegPtr);
FUNC(void,STATIC) i2c_SlaveInit(CONSTPTR2_VAR(i2c_handle_t,AUTO) i2cHandlePtr);
FUNC(void,STATIC) i2c_MasterInit(CONSTPTR2_VAR(i2c_handle_t,AUTO) i2cHandlePtr);

FUNC(void,STATIC) i2c_PeriphControl(CONSTPTR2_VAR(i2c_regMap_t,AUTO)i2cRegPtr, VAR(uint8_t,AUTO)control);
FUNC(void,STATIC) i2c_StretchControl(CONSTPTR2_VAR(i2c_regMap_t,AUTO)i2cRegPtr, VAR(i2c_cr1nostretch_t,AUTO)control);




/*=====================================================================
 * Local const definition
 *=====================================================================*/

CONST(i2cFunInitPtr,STATIC) i2c_constFunInitPtr[2] =
{
		i2c_SlaveInit,
		i2c_MasterInit
};

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

/****************************************************************
 * @fn			- i2c_SlaveInit
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
FUNC(void,STATIC) i2c_SlaveInit(CONSTPTR2_VAR(i2c_handle_t,AUTO) i2cHandlePtr)
{
	CONSTPTR2_VAR(i2c_regMap_t,AUTO)     i2cRegPtr = i2cHandlePtr->i2cRegPtr;
	CONSTPTR2_CONST(i2c_cfg_t,AUTO)      i2cCfgPtr = &i2cHandlePtr->i2cCfg;
	CONSTPTR2_CONST(i2c_slavecfg_t,AUTO) i2cSlavePtr = &i2cCfgPtr->i2cSlaveCfg;
	CONSTPTR2_CONST(i2c_oa1cfg_t,AUTO)   i2cOA1Ptr = &i2cSlavePtr->i2cOA1cfg;
	CONSTPTR2_CONST(i2c_oa2cfg_t,AUTO)   i2cOA2Ptr = &i2cSlavePtr->i2cOA2cfg;
	VAR(uint8_t, AUTO) tmpU8 = 0u;

	/* Clear {OA1EN, OA2EN} in I2C_OAR1 and I2C_OAR2 */
	CLEAN_BIT(i2cRegPtr->OAR1,I2C_OAR1_OA1EN_B);
	CLEAN_BIT(i2cRegPtr->OAR2,I2C_OAR2_OA2EN_B);

	/*
	 * Configure {OA1[9:0], OA1MODE, OA1EN, OA2[6:0], OA2MSK[2:0], OA2EN, GCEN}
	 */

	// .- Own address cfg
	if( (i2cRegPtr->OAR1 & (1u << I2C_OAR1_OA1EN_B)) == 0)
	{
		//.- Configures either in 7-bit mode (by default) or in 10-bit addressing mode.
		i2cRegPtr->OAR1 |= (i2cCfgPtr->i2cAddressingMode << I2C_OAR1_OA1MODE_B);

		//.- Interface address
		if(i2cCfgPtr->i2cAddressingMode == DEVICE_7BIT_ADDRESS)
		{
			/* 7-bit addressing mode */
			i2cRegPtr->OAR1 &= ~(0x7Fu << I2C_OAR1_OA1_7_1_B);
			i2cRegPtr->OAR1 |=  (i2cOA1Ptr->u16Address << I2C_OAR1_OA1_7_1_B);
		}
		else
		{
			/* 10-bit addressing mode */
			i2cRegPtr->OAR1 &= ~(0x2FFUL << I2C_OAR1_OA1_0_B);
			i2cRegPtr->OAR1 |=  (i2cOA1Ptr->u16Address  << I2C_OAR1_OA1_0_B);
		}
	}

	i2cRegPtr->OAR1 |= (i2cOA1Ptr->ACKcontrol << I2C_OAR1_OA1EN_B);


	//.- Own address 2 cfg.
	if( (i2cRegPtr->OAR2 & (1u << I2C_OAR2_OA2EN_B)) == 0u)
	{
		/* Interface address - 7-bit address */
		i2cRegPtr->OAR2 &= ~(0x7Fu << I2C_OAR2_OA2_7_1_B);
		i2cRegPtr->OAR2 |=  (i2cOA2Ptr->u8Address << I2C_OAR2_OA2_7_1_B);

		/* Own Address 2 mask */
		i2cRegPtr->OAR2 |=  (i2cOA2Ptr->mask << I2C_OAR2_OA2MSK_B);
	}
	i2cRegPtr->OAR2 |= (i2cOA2Ptr->ACKcontrol << I2C_OAR2_OA2EN_B);


	//.- General call enable cfg.
	tmpU8 = i2cCfgPtr->i2cSlaveCfg.i2cGenAddr;
	i2cRegPtr->CR1 |= ( tmpU8 << I2C_CR1_GCEN_B);

	// .-
	if( (i2cRegPtr->CR1 & (1u << I2C_CR1_NOSTRETCH_B)) == 0u)
	{
		tmpU8 = i2cSlavePtr->i2cSlaveByteCtrl;
		i2cRegPtr->CR1 |= ( tmpU8 << I2C_CR1_SBC_B);
	}

}

/****************************************************************
 * @fn			-
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
FUNC(void,STATIC) i2c_MasterInit(CONSTPTR2_VAR(i2c_handle_t,AUTO) i2cHandlePtr)
{
	CONSTPTR2_VAR(i2c_regMap_t,AUTO) i2cRegPtr = i2cHandlePtr->i2cRegPtr;
	CONSTPTR2_CONST(i2c_cfg_t,AUTO)  i2cCfgPrt = &i2cHandlePtr->i2cCfg;

	(void)i2cRegPtr;
	(void)i2cCfgPrt;
}

/****************************************************************
 * @fn			- i2c_PeriphControl
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
FUNC(void,STATIC) i2c_PeriphControl(CONSTPTR2_VAR(i2c_regMap_t,AUTO)i2cRegPtr, VAR(uint8_t,AUTO)control)
{
	if(control == I2C_EN)
	{
		SET_BIT(i2cRegPtr->CR1 , I2C_CR1_PE_B);
	}
	else
	{
		CLEAN_BIT(i2cRegPtr->CR1 , I2C_CR1_PE_B);
		//.- Waits until PE bit is clean.
		while( (i2cRegPtr->CR1 & (1u << I2C_CR1_PE_B)) != BIT_CLEAN)
		{/* Avoid Misra */}
	}

}

/****************************************************************
 * @fn			- i2c_StretchControl
 *
 * @brief		- This function is used to control clock stretching
 *                in slave mode.
 *                It must be kept cleared in master mode.
 *
 * @param[in]	-
 *
 * @return		- none
 */

FUNC(void,STATIC) i2c_StretchControl(CONSTPTR2_VAR(i2c_regMap_t,AUTO)i2cRegPtr, \
		VAR(i2c_cr1nostretch_t,AUTO)control)
{

	if( (i2cRegPtr->CR1 & (1u << I2C_CR1_PE_B)) == 0u)
	{
		if(control == CLK_STRETCHING_EN)
		{
			CLEAN_BIT(i2cRegPtr->CR1 , I2C_CR1_NOSTRETCH_B);
		}
		else
		{
			SET_BIT(i2cRegPtr->CR1 , I2C_CR1_NOSTRETCH_B);
		}
	}

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
	VAR(uint8_t,AUTO) tmpU8 = 0u;

	(void)tmpU8;


	//.- Configures I2C peripheral clock controller.
	rcc_I2CxClockControl(i2cIndex,RCC_CLK_EN);
	rcc_I2CxClockSource (i2cIndex, i2cCfgPrt->rccClockSource);

	//.- Clear PE bit in I2C_CR1 -I2C is disable
	i2c_PeriphControl(i2cRegPtr,I2C_DSBL);

	//.- Configure ANFOFF and DNF[3:0] in I2C_CR1
	//@TODO

	/*
	 * Configure PRESC[3:0], SDADEL[3:0], SCLDEL[3:0], SCLH[7:0],
	 * SCLL[7:0] in I2C_TIMINGR
	 */
	//@TODO

	// .- Configure NOSTRETCH in I2C_CR1
	if( i2cCfgPrt->i2cIntfMode == I2C_SLAVE_MODE)
	{
		i2c_StretchControl(i2cRegPtr, i2cCfgPrt->i2cSlaveCfg.i2cStretchClock);
	}
	else
	{
		i2c_StretchControl(i2cRegPtr, CLK_STRETCHING_DSBL);
	}

	//.- Set PE bit in I2C_CR1  - I2C is enable
	i2c_PeriphControl(i2cRegPtr,I2C_EN);




	//.- Initialize interface mode.
	i2c_constFunInitPtr[i2cCfgPrt->i2cIntfMode](i2cHandlePtr);

}


/****************************END OF FILE *******************************************/
