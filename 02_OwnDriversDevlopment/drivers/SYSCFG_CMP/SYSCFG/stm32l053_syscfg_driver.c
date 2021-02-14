/**
  ******************************************************************************
  * @file    stm32l053_syscfg_driver.c
  * @author  Efren Del Real
  * @Date    January 8th 2021
  * @version V1.0
  * @brief   System configuration controller driver.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information 
  *       related.
  ******************************************************************************
*/



/*Include header files____________________________________________________________*/
#include "stm32l053_syscfg_driver.h"

/*Macro definition_________________________________________________________________*/


/*Global function declaration______________________________________________________*/


/****************************************************************
 * @fn          - syscfg_EXTIx_Cfg
 *
 * @brief		- Managing external interrupts line multiplexing
 *                to the internal edge detector.
 *
 * @param[in]   -
 *
 * @param[in]   -
 *
 * @return      - none.
 *
 * @Note        -
 */
FUNC(void,AUTO) syscfg_EXTIx_Cfg( CONST(syscfg_extix_t,AUTO) srcEXTIx,CONST(gpio_pinnum_t,AUTO) pinNum)
{
	uint8_t tmpEXTIx = 0u;
	uint8_t tmpCfgr = 0u;

	// 2.- Selects the EXTIx bits filed.
	tmpEXTIx = (pinNum & 0x03u);

	// 3.- Selects the external interrupt configuration register from 0 to 3
	tmpCfgr = (pinNum >> 0x02u) & 0x03;

	// 4.- Cleans the EXTIx bits field.
	SYSCFG_REGMAP->EXTICR[tmpCfgr] &= ~ ( CLEAN_4B << (4u * tmpEXTIx) );

	// 5.- Sets the source input into EXTIx bits field.
	SYSCFG_REGMAP->EXTICR[tmpCfgr] |= ( srcEXTIx << (4u * tmpEXTIx) );

}
