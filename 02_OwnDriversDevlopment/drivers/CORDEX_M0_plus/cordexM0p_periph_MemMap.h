/**
  ******************************************************************************
  * @file    cordexM0p_periph_MemMap.h
  * @author  Efren Del Real
  * @Date    January 9th 2021
  * @version V1.0
  * @brief
  *
  * NOTE:
  ******************************************************************************
*/

#ifndef CORDEX_M0_PLUS_CORDEXM0P_PERIPH_MEMMAP_H_
#define CORDEX_M0_PLUS_CORDEXM0P_PERIPH_MEMMAP_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_MemMap.h"


/*Macro definition________________________________________________________________*/

/*========================================================================
 * **************** Cortex - M0+ core peripherals *******************
 *
 * NVIC - Embedded interrupt controller that supports low latency
 *        interrupt processing.
 *
 * SCB  - The system control block is the programmers model interface
 *        to the processor. it provies system implementation information
 *        and system control, including configuration, control, and
 *        reporting of system exceptions.
 *
 * SysTick - The system timer is a 24 bit count-down timer. Use this
 *           as a RTOS tick timer or as a simple counter.
 *
 * MPU - The memory protection unit improves system reliability by
 *       defining the memory attributes for different memory regions.
 *
 */
#define MEMMAP_M0P_MPU_BASEADDR					(MEMAP_CORTEX_M0_P_BASEADDR + 0xED90UL)	/* Memory Protection Unit */
#define MEMMAP_M0P_SCB_BASEADDR					(MEMAP_CORTEX_M0_P_BASEADDR + 0xED00UL) /* System Control Block */
#define MEMMAP_M0P_NVIC_BASEADDR				(MEMAP_CORTEX_M0_P_BASEADDR + 0xE100UL) /* Nested Vectored Interrupt Controller */
#define MEMMAP_M0P_SYSTICK_BASEADDR				(MEMAP_CORTEX_M0_P_BASEADDR + 0xE010UL) /* System timer */

#endif /* CORDEX_M0_PLUS_CORDEXM0P_PERIPH_MEMMAP_H_ */
