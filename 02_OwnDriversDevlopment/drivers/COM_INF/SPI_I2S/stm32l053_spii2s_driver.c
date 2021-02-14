/*
 * stm32l053_spii2s_driver.c
 *
 *  Created on: Jan 23, 2021
 *      Author: efren
 */


/*Include header files____________________________________________________________*/
#include "stm32l053_spii2s_driver.h"



/****************************************************************
 * @fn			- spii2s_GetStatusFlag.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		- none
 */

uint8_t spii2s_GetStatusFlag(const spi_regMap_t *const spiRegPtr, const uint8_t flag)
{
	uint8_t retVal = 0u;
	retVal = ((spiRegPtr->SR >> flag) & BIT_SET)?BIT_SET:BIT_CLEAN;

	return retVal;
}
