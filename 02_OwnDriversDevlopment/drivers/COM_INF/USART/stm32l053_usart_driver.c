/**
  ******************************************************************************
  * @file    stm32l053_usart_types.h
  * @author  Efren Del Real
  * @Date    March 9th 2021
  * @version V1.0
  * @brief   Universal synchronous asynchronous receiver transmitter (USART) - Definition driver APIs.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/


/*Include header files____________________________________________________________*/
#include "stm32l053_usart_driver.h"
#include "stm32l053_rcc_driver.h"

/*=====================================================================
 * Local function definition
 *=====================================================================*/

/****************************************************************
 * @fn			- usart_GetUSARTIndex.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
FUNC(uint8_t, STATIC) usart_GetUSARTIndex(CONSTPTR2_CONST(usart_regMap_t,AUTO)usartRegPtr)
{
	VAR(uint8_t,AUTO) retVal = 0u;

	if (usartRegPtr == USART1_REGMAP){retVal = USART1_INDEX;}
	else if (usartRegPtr == USART2_REGMAP){retVal = USART2_INDEX;}
	else if (usartRegPtr == USART4_REGMAP){retVal = USART4_INDEX;}
	else if (usartRegPtr == USART5_REGMAP){retVal = USART5_INDEX;}
	else
	{
		/* Avoid Misra rule 15.7 */
	}

	return retVal;
}

FUNC(uint8_t, STATIC) usart_GetStateBit(CONSTPTR2_CONST(uint32_t, AUTO) regPtr, VAR(uint8_t,AUTO) usartBit)
{
	uint8_t retVal = 0u;
	retVal = ((regPtr[0] >> usartBit) & BIT_SET)?BIT_SET:BIT_CLEAN;

	return retVal;
}

/****************************************************************
 * @fn			- usart_PeriphControl.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
FUNC(void,STATIC) usart_PeriphControl(CONSTPTR2_VAR(usart_regMap_t,AUTO)usartRegPtr, VAR(uint8_t,AUTO)control)
{
	if(control == USART_EN)
	{
		// 1: USART enabled
		SET_BIT(usartRegPtr->CR1 , USART_CR1_UE_B);
	}
	else
	{
		//@TODO - The DMA channel must be disable before reseting the UE bit.

		// 0: USART prescaler and outputs disabled, low-power mode
		CLEAN_BIT(usartRegPtr->CR1 , USART_CR1_UE_B);
	}
}

/****************************************************************
 * @fn			- usart_PeriphControl.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
FUNC(void,STATIC) usart_TxControl(CONSTPTR2_VAR(usart_regMap_t,AUTO)usartRegPtr, VAR(uint8_t,AUTO)control)
{
	if(control == USART_EN)
	{
		// 1: Transmitter is enabled
		SET_BIT(usartRegPtr->CR1, USART_CR1_TE_B);

	}
	else
	{

		// Waits until transmission is complete (Bit 6 TC : 1)
		while(usart_GetStateBit(&usartRegPtr->ISR, USART_ISR_TC_B) != BIT_SET){};

		// 0: Transmitter is disabled
		CLEAN_BIT(usartRegPtr->CR1, USART_CR1_TE_B);
	}

};
/*=====================================================================
 * Global function definition
 *=====================================================================*/

FUNC(void,AUTO) usart_Init(CONSTPTR2_VAR(usart_handle_t,AUTO) usartHandlePtr)
{
	CONSTPTR2_VAR(usart_regMap_t,AUTO) usartRegPtr = usartHandlePtr->usartRegPtr;
	CONSTPTR2_CONST(usart_cfg_t,AUTO)  usartCfgPtr = &usartHandlePtr->usartCfg;
	VAR(uint8_t,AUTO) tmpIndex = 0;


	tmpIndex = usart_GetUSARTIndex(usartHandlePtr->usartRegPtr);

	rcc_USARTxClockControl(tmpIndex, RCC_CLK_EN);

	if((tmpIndex == USART1_INDEX) || (tmpIndex == USART2_INDEX))
	{
		rcc_USARTxClockSource(tmpIndex,usartCfgPtr->rccClockSource);
	}

	usart_PeriphControl(usartRegPtr, USART_DSBL);

  // Program he M bits in USART_CR1 to define the word length.
	usartRegPtr->CR1 |= ( (usartCfgPtr->usartWordLen & 2u) << (USART_CR1_M1_B - 1u));
	usartRegPtr->CR1 |= ( (usartCfgPtr->usartWordLen & 1u) << USART_CR1_M0_B);

  // Select the desired baud rate using the USART_BRR register.
	usartRegPtr->CR1 |= (usartCfgPtr->usartOverSamp << USART_CR1_OVER8_B);

  // Program the number of stop bits in USART_CR2
	usartRegPtr->CR2 |= (usartCfgPtr->usartStopBits << USART_CR2_STOP_B);

  // ENable the USART by writing the UE bit USART_CR1 register to 1.
	usart_PeriphControl(usartRegPtr, USART_EN);

  // Select DMA enable 


  // Set the TE bit 



}

/****************************************************************
 * @fn			- usart_DeInit.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
FUNC(void,AUTO) usart_DeInit(CONSTPTR2_VAR(usart_regMap_t,AUTO) usartRegPtr)
{
	(void) usartRegPtr;
};


/****************************************************************
 * @fn			- usart_SendData.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
FUNC(void,AUTO) usart_SendData(CONSTPTR2_VAR(usart_regMap_t,AUTO) usartRegPtr,
		CONSTPTR2_CONST(uint8_t,AUTO)u8DataPrt, VAR(uint8_t,AUTO) u8Length, VAR(uint16_t,AUTO) u16TimeOut)
{
	VAR(uint8_t, AUTO) tmpIndex;

	(void)u16TimeOut;

	usart_TxControl(usartRegPtr, USART_EN);

	for(tmpIndex = 0u; tmpIndex < u8Length; tmpIndex++)
	{
		// Waits until data is transferred to the shift register
		while(usart_GetStateBit(usartRegPtr->ISR, USART_ISR_TXE_B) != BIT_SET){};

		//
		usartRegPtr->TDR = (uint8_t)u8DataPrt[tmpIndex];
	}


	usart_TxControl(usartRegPtr, USART_DSBL);

};

/****************************************************************
 * @fn			- usart_SendData.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
FUNC(void,AUTO) usart_ReceiveData(CONSTPTR2_VAR(usart_regMap_t,AUTO) usartRegPtr,
		CONSTPTR2_VAR(uint8_t,AUTO)u8DataPrt, VAR(uint8_t,AUTO) u8Length, VAR(uint16_t,AUTO) u16TimeOut)
{

	(void)u8DataPrt;
	(void)u8Length;
	(void)u16TimeOut;

	// 1: Receiver is enabled and begins searching for a start bit
	SET_BIT(usartRegPtr->CR1, USART_CR1_RE_B);

	// 0: Receiver is disabled
	CLEAN_BIT(usartRegPtr->CR1, USART_CR1_RE_B);
};
/****************************END OF FILE *******************************************/
