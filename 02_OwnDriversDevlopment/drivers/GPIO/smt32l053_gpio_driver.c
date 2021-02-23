/**
  ******************************************************************************
  * @file    stm32l053_gpio_driver.c
  * @author  Efren Del Real
  * @Date    January 2nd 2021
  * @version V1.0
  * @brief   General-purpose I/Os driver
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/


/*Include header files____________________________________________________________*/
#include "stm32l053_gpio_driver.h"
#include "stm32l053_rcc_driver.h"
#include "stm32l053_syscfg_driver.h"
#include "stm32l053_exti_driver.h"

/*Macro definition_________________________________________________________________*/


/*=====================================================================
 * Local function definition
 *=====================================================================*/

/****************************************************************
 * @fn			- gpio_GetGPIOIndex.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		-
 */
FUNC(uint8_t, STATIC) gpio_GetGPIOIndex(CONSTPTR2_CONST(gpio_regMap_t, AUTO) gpioRegPtr)
{
	VAR(uint8_t,AUTO) retVal = 0u;

	if (gpioRegPtr == GPIOA_REGMAP){retVal = GPIOA_INDEX;}
	else if (gpioRegPtr == GPIOB_REGMAP){retVal = GPIOB_INDEX;}
	else if (gpioRegPtr == GPIOC_REGMAP){retVal = GPIOC_INDEX;}
	else if (gpioRegPtr == GPIOD_REGMAP){retVal = GPIOD_INDEX;}
	else if (gpioRegPtr == GPIOE_REGMAP){retVal = GPIOE_INDEX;}
	else if (gpioRegPtr == GPIOH_REGMAP){retVal = GPIOH_INDEX;}
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
 * @fn			- gpio_Init.
 *
 * @brief		- Configures a specific Port x pin as INPUT, OUTPUT,
 * 				  ANALOG and ALTERNATE I/O.
 *
 * @param[in]	- gpioHandlePtr,Holds the user configuration pin.
 *
 * @return		- none.
 *
 */
FUNC(void, AUTO) gpio_PinInit(CONSTPTR2_VAR(gpio_handle_t, AUTO) gpioHandlePtr)
{
  CONSTPTR2_VAR  (gpio_regMap_t,AUTO)  gpioRegPtr = gpioHandlePtr->gpioRegPtr;
  CONSTPTR2_CONST(gpio_pinCfg_t,AUTO)  gpioPinCfgPtr = &gpioHandlePtr->gpioPinCfg;
  CONST(uint8_t,AUTO) pinNum = (uint8_t)gpioPinCfgPtr->gpioPinNum;
  CONST(uint8_t,AUTO) bitFieldPos = (pinNum << 1u);
  CONST(uint8_t,AUTO) gpioIndex = gpio_GetGPIOIndex(gpioRegPtr);
  VAR  (uint8_t,AUTO) tmpAFRx = 0u;
  VAR  (uint8_t,AUTO) tmpAFSELy = 0u;


  // .- Enables RCC IOPORTx bus clock.
  rcc_IOPxClockControl(gpioIndex, RCC_CLK_EN);

  // 0.- PUPDR bits field must be reset to analog purposes.
  //     <!-- 00: Neither pull-up nor pull-down -->
  CLEAN_BITFIELD(gpioRegPtr->PUPDR, CLEAN_2B << bitFieldPos);

  // 1.- Configures pin mode
  CLEAN_BITFIELD(gpioRegPtr->MODER, CLEAN_2B << bitFieldPos);
  gpioRegPtr->MODER |= ((0x03u & gpioPinCfgPtr->gpioPinMode) << bitFieldPos);

  if(gpioPinCfgPtr->gpioPinMode != ANALOG_MODE)
  {
	   if( (gpioPinCfgPtr->gpioPinMode == OUT_MODE) || (gpioPinCfgPtr->gpioPinMode == ALTFN_MODE) )
	   {
	  	  // 2.- Configures pin output type.
		  //     <!-- Either push-pull or open-drain -->
		  CLEAN_BITFIELD(gpioRegPtr->OTYPER, CLEAN_1B << pinNum);
		  gpioRegPtr->OTYPER |= (gpioPinCfgPtr->gpioPinOutType << pinNum);

	  	  //3.- Configures pin speed
	  	  CLEAN_BITFIELD(gpioRegPtr->OSPEEDR, CLEAN_2B << bitFieldPos);
	  	  gpioRegPtr->OSPEEDR |= (gpioPinCfgPtr->gpioPinOutSpeed << bitFieldPos);

	  	  if(gpioPinCfgPtr->gpioPinMode == ALTFN_MODE)
	  	  {
			  // 4.- Alternate function selection
			  //     <!-- AFRx Alternate function register x -->
			  //     <!-- Holds MSB bit which means whether use 1:HIGH AFR or 0:LOW AFR -->
			  tmpAFRx = (pinNum >> 0x3u) & 0x01u;
			  //     <!-- AFSELy Alternate function selection for port x pin y -->
			  tmpAFSELy = (4u * (pinNum&0x07u));

			  CLEAN_BITFIELD( gpioRegPtr->AFR[tmpAFRx], CLEAN_4B << tmpAFSELy );
			  gpioRegPtr->AFR[tmpAFRx] |= (gpioPinCfgPtr->gpioPinAltFun << tmpAFSELy);
	  	  };
	    }
	   /* External interrupt/ wakeup lines. */
	   else if ( gpioPinCfgPtr->gpioPinMode == IN_IMR_MODE)
	   {
		   // - Enable the system configuration clock.
		   RCC_SYSCF_CLK_EN();

		   // - Selects the source input for the EXTIx external interrupt.
		   syscfg_EXTIx_Cfg((syscfg_extix_t)gpioIndex, pinNum);

		   // - Configures the trigger selection.
		   exti_triggerSel_Cfg((uint8_t)pinNum, gpioPinCfgPtr->extiPinTriggerSel);

		   // - Configures the interrupt request from line x as masked.
		   EXTI_IMR_EN(pinNum);
	   }
	   else
	   {
		   /* Avoid Misra Rule 15.7 */
	   }

	    // 5.- Configure pin pull-up or pull-down.
	    if( (gpioPinCfgPtr->gpioPinPuPd == PULL_UP) || (gpioPinCfgPtr->gpioPinPuPd == PULL_DOWN) )
	    {
	    	gpioRegPtr->PUPDR |= (gpioPinCfgPtr->gpioPinPuPd << bitFieldPos);
	    };
  };
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
FUNC(void,AUTO) gpio_DeInit(void)
{
 /*@TODO*/
}


/****************************************************************
 * @fn			- gpio_ReadPin
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		-
 */
FUNC(gpio_pinst_t,AUTO) gpio_ReadPin(CONSTPTR2_CONST(gpio_regMap_t,AUTO) gpioRegPtr, VAR(gpio_pinnum_t,AUTO) gpioPinNum)
{
	VAR(gpio_pinst_t,AUTO) retVal = 0u;

	retVal = (gpio_pinst_t) ((gpioRegPtr->IDR >> gpioPinNum) & 0x01u);

	return retVal;
}

/****************************************************************
 * @fn			- gpio_ReadPort
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		-
 */
FUNC(uint16_t,AUTO) gpio_ReadPort(CONSTPTR2_CONST(gpio_regMap_t,AUTO) gpioRegPtr)
{
	VAR(uint16_t,AUTO) retVal = 0u;

	retVal = (uint16_t)gpioRegPtr->IDR;

	return retVal;
}


/****************************************************************
 * @fn			- gpio_WritePin
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		-
 */
FUNC(void,AUTO) gpio_WritePin (CONSTPTR2_VAR(gpio_regMap_t,AUTO) gpioRegPtr, VAR(gpio_pinnum_t,AUTO) pinNum, VAR(gpio_pinst_t,AUTO) pinState)
{

	if( pinState == BIT_CLEAN)
	{
		gpioRegPtr->ODR &= ~(BIT_SET << pinNum);
	}
	else
	{
		gpioRegPtr->ODR |= (BIT_SET << pinNum);
	}

}


/****************************************************************
 * @fn			- gpio_WritePort
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		-
 */
FUNC(void,AUTO) gpio_WritePort(CONSTPTR2_VAR(gpio_regMap_t,AUTO) gpioRegPtr, VAR(uint16_t,AUTO) portValue)
{
	gpioRegPtr->ODR &= 0x0000UL;
	gpioRegPtr->ODR |= portValue;
}

/****************************************************************
 * @fn			- gpio_TogglePin
 *
 * @brief		-
 *
 * @param[in]	- gpioRegPtr, holds GPIO port register map.
 * @param[in]	- gpioPinNum, holds pin number from 0 to 15.
 *
 * @return		- None
 *
 * @Note		- gpio_PinInit must be called before change the data output.
 */
FUNC(void,AUTO) gpio_TogglePin(CONSTPTR2_VAR(gpio_regMap_t,AUTO) gpioRegPtr, VAR(gpio_pinnum_t,AUTO) pinNum)
{
	gpioRegPtr->ODR ^= (BIT_SET << pinNum);
}

/****************************END OF FILE *******************************************/
