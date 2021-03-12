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

/*=====================================================================
 * Global function definition
 *=====================================================================*/

FUNC(void,AUTO) usart_Init(CONSTPTR2_VAR(usart_handle_t,AUTO) usartHandlePtr)
{
	CONSTPTR2_VAR(usart_regMap_t,AUTO) usartRegPtr = usartHandlePtr->usartRegPtr;
	CONSTPTR2_CONST(usart_cfg_t,AUTO)  usartCfgPtr = &usartHandlePtr->usartCfg;


  // Program he M bits in USART_CR1 to define the word length.
	usartRegPtr->CR1 |= ( (usartCfgPtr->usartWordLen & 2u) << (USART_CR1_M1_B - 1u));
	usartRegPtr->CR1 |= ( (usartCfgPtr->usartWordLen & 1u) << USART_CR1_M0_B);

  // Select the desired baud rate using the USART_BRR register.
  usartRegPtr->CR1 |= (usartCfgPtr->usartOverSamp << USART_CR1_OVER8_B);

  // Program the number of stop bits in USART_CR2
  usartRegPtr->CR2 |= (usartCfgPtr->usartStopBits << USART_CR2_STOP_B);

  // ENable the USART by writing the UE bit USART_CR1 register to 1.

  // Select DMA enable 


  // Set the TE bit 



}

FUNC(void,AUTO) usart_DeInit(CONSTPTR2_VAR(usart_regMap_t,AUTO) usartRegPtr)
{
	(void) usartRegPtr;
}

/****************************END OF FILE *******************************************/
