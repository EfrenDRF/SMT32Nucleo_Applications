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

/*=====================================================================
 * Local function definition
 *=====================================================================*/


/*=====================================================================
 * Global function definition
 *=====================================================================*/

FUNC(void,AUTO) usart_Init(CONSTPTR2_VAR(usart_handle_t,AUTO) usartHandlePtr)
{

}

FUNC(void,AUTO) usart_DeInit(CONSTPTR2_VAR(usart_regMap_t,AUTO) usartRegPtr)
{
	(void) usartRegPtr;
}

/****************************END OF FILE *******************************************/
