/**
  ******************************************************************************
  * @file    cordexM0p_nvic_driver.c
  * @author  Efren Del Real
  * @Date    January 9th 2021
  * @version V1.0
  * @brief   Nested Vectored Interrupt Controller (NVIC) driver.
  *
  * NOTE:    The code was wrote using below documentation.
  *          - PM0223 programming manual by ST
  *          - Cortex-M0+ Devices (Generic User Guide) by ARM
  *          - r0p0 Cortex-M0 (Technical Reference Manual) by ARM
  *          Please verify your correct documentation in order to modify the code
  *          or get more information.
*/


/*Include header files____________________________________________________________*/
#include "cordexM0p_nvic_driver.h"

/*Macro definition________________________________________________________________*/

#define NVIC_MAX_IRQn(irq_x)	((irq_x) & 0x1FUL)


/*Global function definition______________________________________________________*/



/****************************************************************
 * @fn			- nvic_EnableIRQ.
 *
 * @brief		- Enable an interrupt or exception.
 *
 * @param[in]	- IRQn enum type from the availables exceptions
 *                and interrupts.
 *
 * @return		- none.
 *
 * @Note		- The Interrupt Set Enable Register enables
 *                interrupts, and show which interrupts are enable.
 *                WRITE: 0 - No effect.
 *                       1 - Enable interrupt.
 *
 *                READ:  0 - Interrupt disabled.
 *                       1 - Interrupt enabled.
 */
void nvic_EnableIRQ(nvic_IRQn_t IRQn)
{
	SET_BIT(NVIC_REGMAP->ISER ,NVIC_MAX_IRQn(IRQn));
}

/****************************************************************
 * @fn			- nvic_DisableIRQ.
 *
 * @brief		- Disables an interrupt or exception.
 *
 * @param[in]	- IRQn enum type from the availables exceptions
 *                and interrupts.
 *
 * @return		- none.
 *
 * @Note		- The Interrupt Clear Enable Register disables
 *                interrupts, and show interrupts are enabled.
 *                WRITE: 0 - No effect.
 *                       1 - Disable interrupt.
 *
 *                READ:  0 - Interrupt disabled.
 *                       1 - Interrupt enabled.
 *
 */
void nvic_DisableIRQ(nvic_IRQn_t IRQn)
{
	SET_BIT(NVIC_REGMAP->ICER ,NVIC_MAX_IRQn(IRQn));
}

/****************************************************************
 * @fn			- nvic_GetPendingIRQ.
 *
 * @brief		- Reads the pending status of interrupt or
 *                exeption.
 *
 * @param[in]   - IRQn enum type from the availables exceptions
 *                and interrupts.
 *
 * @return		- Returns non-zero value whether the pending
 *                status is set to 1.
 *
 * @Note		- none
 */
uint8_t nvic_GetPendingIRQ (nvic_IRQn_t IRQn)
{
	uint8_t retVal = 0u;

	retVal = (uint8_t) (NVIC_REGMAP->ISPR >> NVIC_MAX_IRQn(IRQn) )& 0x01u;

	return retVal;
}

/****************************************************************
 * @fn			- nvic_SetPendingIRQ.
 *
 * @brief		- Sets the pending status of interrupt or
 *                exception to 1.
 *
 * @param[in]   - IRQn enum type from the availables exceptions
 *                and interrupts.
 *
 * @return		- none.
 *
 * @Note		- The Interrupt Set Pending Register forces
 *                interrupts into the pending state, and shows
 *                which interrupts are pending.
 *                WRITE: 0 - No effect.
 *                       1 - Change interrupt state to pending.
 *
 *                READ:  0 - Interrupt is not pending.
 *                       1 - Interrupt is pending.
 */
void nvic_SetPendingIRQ (nvic_IRQn_t IRQn)
{
	SET_BIT(NVIC_REGMAP->ISPR ,NVIC_MAX_IRQn(IRQn));
}

/****************************************************************
 * @fn			- nvic_ClearPendingIRQ.
 *
 * @brief		- Clears the pending status of interrupt or
 *                exception to 0.
 *
 * @param[in]	- IRQn enum type from the availables exceptions
 *                and interrupts.
 *
 * @return		- none.
 *
 * @Note		- Interrupt Clear Pending Register removes the
 *                pending state from interrupts, and shows which
 *                interrupts are pending.
 *                WRITE: 0 - No effect.
 *                       1 - Removes pending state and interrupt.
 *
 *                READ:  0 - Interrupt is not pending.
 *                       1 - Interrupt is pending.
 */
void nvic_ClearPendingIRQ (nvic_IRQn_t IRQn)
{
	SET_BIT(NVIC_REGMAP->ICPR ,NVIC_MAX_IRQn(IRQn));
}

/****************************************************************
 * @fn			- nvic_SetPriority.
 *
 * @brief		- Sets the priority of an interrupt or exception
 *                with configurable priority level to 1.
 *
 * @param[in]	- IRQn enum type from the availables exceptions
 *                and interrupts.
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		-
 */
void nvic_SetPriority (nvic_IRQn_t IRQn, nvic_pri_t priority)
{
	uint8_t tmpIPRn= 0u;
	uint8_t tmpPRI_x = 0u;

	tmpIPRn = (IRQn >> 0x2u) & 0x7u;  /* holds the Interrupt Priority Register n (0 ... 8). */
	tmpPRI_x = (IRQn & 0x3u);         /* Selects priority field.*/

	/*Cleans the PRIx field.*/
	NVIC_REGMAP->IPR[tmpIPRn] &= ~(CLEAN_8B << (8u*tmpPRI_x));

	/* Sets bits [7:6] to the corresponding Priority field and register.*/
	NVIC_REGMAP->IPR[tmpIPRn] |= ((priority &0xFFu) << (8u*tmpPRI_x));

}

/****************************************************************
 * @fn			- nvic_GetPriority.
 *
 * @brief		- Reads the priority of an interrupt or exception
 *                with configurable priority level.
 *
 * @param[in]	- IRQn enum type from the availables exceptions
 *                and interrupts.
 *
 * @return		- none.
 *
 * @Note		- Returns the current priority level.
 */
nvic_pri_t nvic_GetPriority (nvic_IRQn_t IRQn)
{
	uint8_t tmpIPRn= 0u;
	uint8_t tmpPRI_x = 0u;
	nvic_pri_t retPri = IRQn_PRI_0;

	tmpIPRn = (IRQn >> 0x2u) & 0x7u;  /* holds the Interrupt Priority Register n (0 ... 8). */
	tmpPRI_x = (IRQn & 0x3u);         /* Selects priority field.*/

	/* Gets the field priority level value. */
	retPri = (NVIC_REGMAP->IPR[tmpIPRn] >> (8u*tmpPRI_x)) & 0xFFu;

	return retPri;
}

