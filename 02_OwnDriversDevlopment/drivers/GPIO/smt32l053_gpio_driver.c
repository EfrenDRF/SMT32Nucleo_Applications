/**
  ******************************************************************************
  * @file    stm32l053_gpio_driver.c
  * @author  Efren Del Real
  * @Date    January 2nd 2021
  * @version V1.0
  * @brief   General-purpose I/Os driver
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************
*/


/*Include header files____________________________________________________________*/
#include "stm32l053_gpio_driver.h"

/*Macro definition_________________________________________________________________*/

/*Global function declaration______________________________________________________*/


/****************************************************************
 * @fn			- gpio_Init.
 *
 * @brief		- Configures a specific Port x pin as INPUT, OUTPUT,
 * 				  ANALOG and ALTERNATE I/O.
 *
 * @param[in]	- pGPIOHandle,Holds the user configuration pin.
 *
 * @return		- none.
 *
 * @Note		- As precondition RCC_IOPx_CLK_EN must be called.
 */
void gpio_pinInit(gpio_handle_t const *pGPIOHandle)
{
  uint8_t u8Tmp = 0u;
  uint8_t pinNumTmp = pGPIOHandle->GPIOx_pinCfg.pinNumber;	/* Holds user GPIO pin number.*/
  uint8_t afTmp = 0;

  // 0.- Clean bit field from PUPDR(must be reset to Analog purposes) cfg register.
  MEMMAP_CLEAN_BITFIELD(pGPIOHandle->pGPIOx->PUPDR, MEMMAP_2B_CLEAN << (2u * pinNumTmp)); /* 00: No pull-up, pull-down */

  // 1.- Configure the pin mode
  MEMMAP_CLEAN_BITFIELD(pGPIOHandle->pGPIOx->MODER, MEMMAP_2B_CLEAN << (2u * pinNumTmp));
  u8Tmp = pGPIOHandle->GPIOx_pinCfg.mode;
  pGPIOHandle->pGPIOx->MODER |= (u8Tmp << (2u*pinNumTmp));

  if(u8Tmp != ANALOG_MODE)
  {
	   if( (u8Tmp == OUT_MODE) || (u8Tmp == ALTFN_MODE) )
	   {
	  	  // 2.- Configure the pin output type push-pull or open-drain.
	  	  MEMMAP_CLEAN_BITFIELD(pGPIOHandle->pGPIOx->OTYPER, MEMMAP_1B_CLEAN << pinNumTmp); /* 0: Output push-pull */
	  	  u8Tmp = pGPIOHandle->GPIOx_pinCfg.oType;
	  	  pGPIOHandle->pGPIOx->OTYPER |= (u8Tmp << pinNumTmp);

	  	  //3.- Configure pin speed
	  	  MEMMAP_CLEAN_BITFIELD(pGPIOHandle->pGPIOx->OSPEEDR, MEMMAP_2B_CLEAN << (2u * pinNumTmp));
	  	  u8Tmp = pGPIOHandle->GPIOx_pinCfg.oSpeed;
	  	  pGPIOHandle->pGPIOx->OSPEEDR |= (u8Tmp << (2u*pinNumTmp));

	  	  if( pGPIOHandle->GPIOx_pinCfg.mode == ALTFN_MODE)
	  	  {
			  // 4.- Alternate function selection
			  u8Tmp = pGPIOHandle->GPIOx_pinCfg.altFun;	/* Holds the AF selection value*/
			  afTmp = (u8Tmp >> 0x3u) & 0x01; /* Holds MSB bit that means whether use 1:HIGH reg or 0:LOW reg */

			  MEMMAP_CLEAN_BITFIELD( pGPIOHandle->pGPIOx->AFR[afTmp], MEMMAP_4B_CLEAN << (4u * (pinNumTmp&0x07u)));
			  u8Tmp &= 0x07u; /* AFSEL from 0000 to 0111 otherwise are reserved*/
			  pGPIOHandle->pGPIOx->AFR[afTmp] |= (u8Tmp << (4u* (pinNumTmp & 0x07u)));
	  	  }

	    }

	    // 5.- Configure pin pull-up or pull-down.
	    u8Tmp = pGPIOHandle->GPIOx_pinCfg.pupd;

	    if( (u8Tmp == PUP) || (u8Tmp == PDOWN ))
	    {
	  	  pGPIOHandle->pGPIOx->PUPDR |= (u8Tmp << (2u*pinNumTmp));	
	    };
  }
}


/****************************************************************
 * @fn			-
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		-
 */


/****************************************************************
 * @fn			- gpio_Read_Pin
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		-
 */
gpio_pinst_t gpio_Read_Pin(gpio_regMap_t *pGPIOx, gpio_pinNum_t pinNumber)
{
	gpio_pinst_t retValue = 0u;

	retValue = (gpio_pinst_t)(pGPIOx->IDR >> pinNumber) & 0x0001UL;

	return retValue;
}

/****************************************************************
 * @fn			- gpio_Read_Port
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		-
 */
uint16_t gpio_Read_Port(gpio_regMap_t *pGPIOx)
{
	uint16_t retValue = 0u;

	retValue = (uint16_t)(pGPIOx->IDR & 0xFFFFUL);

	return retValue;
}


/****************************************************************
 * @fn			- gpio_Write_Pin
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		-
 */
void gpio_Write_Pin(gpio_regMap_t *pGPIOx, gpio_pinNum_t pinNumber, gpio_pinst_t state)
{

	if( state == MEMMAP_BIT_CLEAN)
	{
		pGPIOx->ODR &= ~(MEMMAP_BIT_SET << pinNumber);
	}
	else
	{
		pGPIOx->ODR |= (MEMMAP_BIT_SET << pinNumber);
	}

}


/****************************************************************
 * @fn			- gpio_Write_Port
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		-
 */
void gpio_Write_Port(gpio_regMap_t *pGPIOx, uint16_t u16Value)
{
	pGPIOx->ODR &= 0x0000UL;
	pGPIOx->ODR |= u16Value;
}

/****************************************************************
 * @fn			- gpio_Toggle_Pin
 *
 * @brief		-
 *
 * @param[in]	- pGPIOx, holds GPIO port register map.
 * @param[in]	- pinNumber, holds pin number from 0 to 15.
 *
 * @return		- None
 *
 * @Note		- gpio_pinInit must be called before change the data output.
 */

void gpio_Toggle_Pin(gpio_regMap_t *pGPIOx, gpio_pinNum_t pinNumber)
{
	pGPIOx->ODR ^= (MEMMAP_BIT_SET << pinNumber);
}


