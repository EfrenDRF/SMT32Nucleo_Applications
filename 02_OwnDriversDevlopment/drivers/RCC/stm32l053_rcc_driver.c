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
#include "stm32l053_spi_types.h"
#include "stm32l053_usart_types.h"


/*Macro definition_________________________________________________________________*/

/*Local function declaration_______________________________________________________*/

/*=====================================================================
 * Local constant definition
 *=====================================================================*/
CONST(rcc_iopbit_t,STATIC) rcc_constIOPxBITs[GPIOMAX_INDEX]=
{
	{.rccIOPxRST=0u, .rccIOPxEN=RCC_IOPENR_IOPAEN_B, .rccIOPxSMEN=0u},
	{.rccIOPxRST=0u, .rccIOPxEN=RCC_IOPENR_IOPBEN_B, .rccIOPxSMEN=0u},
	{.rccIOPxRST=0u, .rccIOPxEN=RCC_IOPENR_IOPCEN_B, .rccIOPxSMEN=0u},
	{.rccIOPxRST=0u, .rccIOPxEN=RCC_IOPENR_IOPDEN_B, .rccIOPxSMEN=0u},
	{.rccIOPxRST=0u, .rccIOPxEN=RCC_IOPENR_IOPEEN_B, .rccIOPxSMEN=0u},
	{.rccIOPxRST=0u, .rccIOPxEN=RCC_IOPENR_IOPHEN_B, .rccIOPxSMEN=0u},
};

CONST(rcc_i2cbit_t,STATIC) rcc_constI2CxBITs[I2CMAX_INDEX] =
{
	{.rccI2CxRST =0u, .rccI2CxEN=RCC_APB1ENR_I2C1EN_B, .rccI2CxSMEN=0u, .rccI2CxSEL=RCC_CCIPR_I2C1SEL_B},
	{.rccI2CxRST =0u, .rccI2CxEN=RCC_APB1ENR_I2C1EN_B, .rccI2CxSMEN=0u, .rccI2CxSEL=RCC_CCIPR_I2C1SEL_B},
	{.rccI2CxRST =0u, .rccI2CxEN=RCC_APB1ENR_I2C1EN_B, .rccI2CxSMEN=0u, .rccI2CxSEL=RCC_CCIPR_I2C1SEL_B},
};

CONST(rcc_usartbit_t,STATIC) rcc_constUSARTxBITs[USARTMAX_INDEX] =
{
	{.rccUSARTxRST = 0u, .rccUSARTxEN = RCC_APB2ENR_USART1EN_B, .rccUSARTxSMEN = 0u, .rccUSARTxSEL = RCC_CCIPR_USART1SEL_B},
	{.rccUSARTxRST = 0u, .rccUSARTxEN = RCC_APB1ENR_USART2EN_B, .rccUSARTxSMEN = 0u, .rccUSARTxSEL = RCC_CCIPR_USART2SEL_B},
	{.rccUSARTxRST = 0u, .rccUSARTxEN = RCC_APB1ENR_USART4EN_B, .rccUSARTxSMEN = 0u, .rccUSARTxSEL = 0u},
	{.rccUSARTxRST = 0u, .rccUSARTxEN = RCC_APB1ENR_USART5EN_B, .rccUSARTxSMEN = 0u, .rccUSARTxSEL = 0u}
};

/*=====================================================================
 * Local function definition
 *=====================================================================*/

/*=====================================================================
 * Global function definition
 *=====================================================================*/

/****************************************************************
 * @fn			- rcc_IOPxClockControl.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		- none
 */
FUNC(void, AUTO) rcc_IOPxClockControl(CONST(uint8_t,AUTO)iopxIndex, VAR(uint8_t,AUTO) control)
{
	VAR(uint8_t,AUTO) tmpBit = rcc_constIOPxBITs[iopxIndex].rccIOPxEN;

	if(control == RCC_CLK_EN){SET_BIT( RCC_REGMAP->IOPENR, tmpBit);}
	else{CLEAN_BIT(RCC_REGMAP->IOPENR, tmpBit);}
}

/****************************************************************
 * @fn			- rcc_I2CxClockControl.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		- none
 */
FUNC(void, AUTO) rcc_I2CxClockControl(CONST(uint8_t,AUTO)i2cxIndex, VAR(uint8_t,AUTO) control)
{
	VAR(uint8_t,AUTO) tmpBit = rcc_constI2CxBITs[i2cxIndex].rccI2CxEN;
	
	if(control == RCC_CLK_EN){SET_BIT( RCC_REGMAP->APB1ENR, tmpBit);}
	else{CLEAN_BIT(RCC_REGMAP->APB1ENR, tmpBit);}
}

/****************************************************************
 * @fn			- rcc_SPIxClockControl.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		- none
 */
FUNC(void, AUTO) rcc_SPIxClockControl(CONST(uint8_t,AUTO)spiIndex, VAR(uint8_t,AUTO) control)
{
	if(control == RCC_CLK_EN)
	{
		if(spiIndex == SPI1_INDEX){RCC_SPI1_CLK_EN();}
		else{RCC_SPI2_CLK_EN();}
	}
	else
	{
		if(spiIndex == SPI1_INDEX){RCC_SPI1_CLK_DSBL();}
		else{RCC_SPI2_CLK_DSBL();}
	}
}
/****************************************************************
 * @fn			- rcc_I2CxClockSource.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		- none
 */
FUNC(void, AUTO) rcc_I2CxClockSource(CONST(uint8_t,AUTO)i2cxIndex, CONST(rcc_ccipri2cxsel_t,AUTO) clockSource)
{
	VAR(uint8_t,AUTO) tmpBit = rcc_constI2CxBITs[i2cxIndex].rccI2CxSEL;
	
	CLEAN_BITFIELD( RCC_REGMAP->CCIPR, ( CLEAN_2B << tmpBit) );
	SET_BITFIELD( RCC_REGMAP->CCIPR, (clockSource << tmpBit) );
}

/****************************************************************
 * @fn			- rcc_USARTxClockControl.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		- none
 */
FUNC(void, AUTO) rcc_USARTxClockControl(CONST(uint8_t,AUTO)usartxIndex, VAR(uint8_t,AUTO) control)
{
	VAR(uint8_t,AUTO) tmpBit;
	PTR2_VAR(uint32_t, AUTO) tmpRegPtr;

	tmpBit = rcc_constUSARTxBITs[usartxIndex].rccUSARTxEN;
	tmpRegPtr = (tmpBit == USART1_INDEX)?((uint32_t*)&RCC_REGMAP->APB2ENR):((uint32_t*)&RCC_REGMAP->APB1ENR);
	
	if(control == RCC_CLK_EN)
	{
		SET_BIT( tmpRegPtr[0], tmpBit);
	}
	else
	{
		CLEAN_BIT(tmpRegPtr[0], tmpBit);
	}
}

/****************************************************************
 * @fn			- rcc_USARTxClockSource.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		- none
 */
FUNC(void, AUTO) rcc_USARTxClockSource(CONST(uint8_t,AUTO)usartxIndex, CONST(rcc_cciprusartxsel_t,AUTO) clockSource)
{
	VAR(uint8_t,AUTO) tmpBit = rcc_constUSARTxBITs[usartxIndex].rccUSARTxSEL;
	
	CLEAN_BITFIELD( RCC_REGMAP->CCIPR, ( CLEAN_2B << tmpBit) );
	SET_BITFIELD( RCC_REGMAP->CCIPR, (clockSource << tmpBit) );
}

/****************************END OF FILE *******************************************/
