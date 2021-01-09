/**
  ******************************************************************************
  * @file    cordexM0p_nvic_driver.c
  * @author  Efren Del Real
  * @Date    January 9th 2021
  * @version V1.0
  * @brief
  *
  * NOTE:
  ******************************************************************************
*/
#include "cordexM0p_nvic_driver.h"





/****************************************************************
 * @fn			- .
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		-
 */
void nvic_EnableIRQ(nvic_IRQn_t IRQn)
{
	MEMMAP_SET_BIT(NVIC_REGMAP->ISER ,(IRQn & 0x1FUL));
}

/****************************************************************
 * @fn			- .
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		-
 */
void nvic_DisableIRQ(nvic_IRQn_t IRQn)
{
	MEMMAP_SET_BIT(NVIC_REGMAP->ICER ,(IRQn & 0x1FUL));
}

/****************************************************************
 * @fn			- .
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		-
 */
uint32_t nvic_GetPendingIRQ (nvic_IRQn_t IRQn)
{
	/* @TODO */
	return 0;
}

/****************************************************************
 * @fn			- .
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		-
 */
void nvic_SetPendingIRQ (nvic_IRQn_t IRQn)
{

}

/****************************************************************
 * @fn			- .
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		-
 */
void nvic_ClearPendingIRQ (nvic_IRQn_t IRQn)
{

}

/****************************************************************
 * @fn			- .
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		-
 */
void nvic_SetPriority (nvic_IRQn_t IRQn, uint32_t priority)
{

}

/****************************************************************
 * @fn			- .
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		-
 */
uint32_t nvic_GetPriority (nvic_IRQn_t IRQn)
{
	return 0;
}

/****************************************************************
 * @fn			- .
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		-
 */
void nvic_SystemReset (void)
{

}
