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
/****************************************************************
 * @fn			- usart_GetStateBit.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
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
 * @fn			- usart_TxControl.
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
		// Set the TE bit in USART_CR1 to send an idle frame as first transmission
		SET_BIT(usartRegPtr->CR1, USART_CR1_TE_B);
	}
	else
	{
		// Waits until transmission is complete (Bit 6 TC : 1)
		// This indicates that the transmission of the last frame is complete
		while(usart_GetStateBit(&usartRegPtr->ISR, USART_ISR_TC_B) != BIT_SET){};

		// 0: Transmitter is disabled
		CLEAN_BIT(usartRegPtr->CR1, USART_CR1_TE_B);
	}
};

/****************************************************************
 * @fn			- usart_RxControl.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
FUNC(void,STATIC) usart_RxControl(CONSTPTR2_VAR(usart_regMap_t,AUTO)usartRegPtr, VAR(uint8_t,AUTO)control)
{
	if(control == USART_EN)
	{
		// 1: Receiver is enabled and begins searching for a start bit
		SET_BIT(usartRegPtr->CR1, USART_CR1_RE_B);
	}
	else
	{
		// 0: Receiver is disabled
		CLEAN_BIT(usartRegPtr->CR1, USART_CR1_RE_B);
	}
};

/****************************************************************
 * @fn			- usart_GetDataFieldMask.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
FUNC(uint16_t,STATIC) usart_GetDataFieldMask(CONSTPTR2_CONST(usart_regMap_t,AUTO)usartRegPtr)
{
	VAR(uint16_t,AUTO)retMask = 0u;
	VAR(uint8_t, AUTO)Mbits = 0u;
	VAR(uint8_t, AUTO)parityBitPos = 0u;

	Mbits |= (usart_GetStateBit(&usartRegPtr->CR1, USART_CR1_M1_B) << 1u);
	Mbits |= usart_GetStateBit(&usartRegPtr->CR1, USART_CR1_M0_B);

	switch(Mbits)
	{
		case USART_8_DATA_BIT: {parityBitPos = 8u; retMask = 0x00FFU;}break;
		case USART_9_DATA_BIT: {parityBitPos = 9u; retMask = 0x01FFU; }break;
		case USART_7_DATA_BIT: {parityBitPos = 7u; retMask = 0x007FU; }break;
		default:
		{
			/* Avoid Misra*/
		}break;
	};

	if(usart_GetStateBit(&usartRegPtr->CR1, USART_CR1_PCE_B) == USART_EN)
	{
		CLEAN_BIT(retMask, (parityBitPos - 1u));
	}

	return retMask;
};

/****************************************************************
 * @fn			- usart_GetDataFieldMask.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
FUNC(void,STATIC) usart_GenBaudRate(CONSTPTR2_VAR(usart_handle_t,AUTO) usartHandlePtr)
{
	CONSTPTR2_VAR(usart_regMap_t,AUTO) usartRegPtr = usartHandlePtr->usartRegPtr;
	CONSTPTR2_CONST(usart_cfg_t,AUTO)  usartCfgPtr = &usartHandlePtr->usartCfg;
	VAR(uint32_t,AUTO)usartDiv = 0U;
	VAR(uint8_t, AUTO)over8St = 0u;
	VAR(uint32_t,AUTO)tmpFclk = 0UL;

	over8St = usart_GetStateBit(&usartRegPtr->CR1, USART_CR1_OVER8_B);

	/**@TODO read/get clock frequency */
	tmpFclk = 2000000UL;

	if(over8St == USART_OVERSAMPLING_BY_16)
	{
		usartDiv = (tmpFclk / usartCfgPtr->usartBaudRate);
	}
	else
	{
		usartDiv = ((2U * tmpFclk) / usartCfgPtr->usartBaudRate);

	}

	usartRegPtr->BRR = (uint16_t)usartDiv;

	if(over8St == USART_OVERSAMPLING_BY_8)
	{
		usartRegPtr->BRR |= ( (0x0Fu & usartDiv) << 1u);
		CLEAN_BIT(usartRegPtr->BRR, 3u);
	}
}

/*=====================================================================
 * Global function definition
 *=====================================================================*/

/****************************************************************
 * @fn			- usart_Init.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none
 */
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
	{

	  // Program he M bits in USART_CR1 to define the word length.
		usartRegPtr->CR1 |= ( (usartCfgPtr->usartWordLen & 2u) << (USART_CR1_M1_B - 1u));
		usartRegPtr->CR1 |= ( (usartCfgPtr->usartWordLen & 1u) << USART_CR1_M0_B);

	  // Select the desired baud rate using the USART_BRR register.
		usartRegPtr->CR1 |= (usartCfgPtr->usartOverSamp << USART_CR1_OVER8_B);
		usart_GenBaudRate(usartHandlePtr);

	  // Program the number of stop bits in USART_CR2
		usartRegPtr->CR2 |= (usartCfgPtr->usartStopBits << USART_CR2_STOP_B);

	  //
		if(usartCfgPtr->usartParityControl != USART_NONE_PARITY)
		{
			usartRegPtr->CR1 |= (usartCfgPtr->usartParityControl << USART_CR1_PS_B);
		}
	};
	usart_PeriphControl(usartRegPtr, USART_EN);

  // Select DMA enable 


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
		PTR2_VAR(void,AUTO)dataPrt, VAR(uint8_t,AUTO) dataLength, VAR(uint16_t,AUTO) u16TimeOut)
{
	VAR(uint8_t, AUTO) tmpIndex = 0u;
	VAR(uint16_t,AUTO) dataMask = usart_GetDataFieldMask(usartRegPtr);

	(void)u16TimeOut;

	usart_TxControl(usartRegPtr, USART_EN);
	{
		for(tmpIndex = 0u; tmpIndex < dataLength; tmpIndex++)
		{
			// Waits until data is transferred to the shift register
			// or the USART_TDR register is empty.
			while(usart_GetStateBit(&usartRegPtr->ISR, USART_ISR_TXE_B) != BIT_SET){};

			// Write the data to send in the USART_TDR register (this clears the TXE bit).
			if(dataMask == 0x01FFU)
			{
				usartRegPtr->TDR = (uint16_t)(dataMask & ((uint16_t*)dataPrt)[tmpIndex]);
			}
			else
			{
				usartRegPtr->TDR = (uint8_t)(dataMask & ((uint8_t*)dataPrt)[tmpIndex]);
			}
		}
	};
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
FUNC(void,AUTO) usart_ReceiveData(CONSTPTR2_CONST(usart_regMap_t,AUTO) usartRegPtr,
		PTR2_VAR(void,AUTO)dataPrt, VAR(uint8_t,AUTO) dataLength, VAR(uint16_t,AUTO) u16TimeOut)
{
	VAR(uint8_t, AUTO) tmpIndex = 0u;
	VAR(uint16_t,AUTO) dataMask = usart_GetDataFieldMask(usartRegPtr);

	(void)u16TimeOut;

	// Set the RE bit USART_CR1. This enables the receiver which begins searching for a start bit.
	usart_RxControl(usartRegPtr, USART_EN);
	{
		for(tmpIndex = 0u; tmpIndex < dataLength; tmpIndex++)
		{
			// 0: data is not received
			while(usart_GetStateBit(&usartRegPtr->ISR, USART_ISR_RXNE_B) != BIT_SET){};

			//
			if(dataMask == 0x01FFU)
			{
				((uint16_t*)dataPrt)[tmpIndex] = (uint16_t)(dataMask & usartRegPtr->RDR);

			}
			else
			{
				((uint8_t*)dataPrt)[tmpIndex] = (uint8_t)(dataMask & usartRegPtr->RDR);
			}
		}
	};
	usart_RxControl(usartRegPtr, USART_DSBL);
};
/****************************END OF FILE *******************************************/
