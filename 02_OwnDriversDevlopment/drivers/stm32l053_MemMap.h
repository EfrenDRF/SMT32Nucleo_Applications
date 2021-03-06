/**
  ******************************************************************************
  * @file    stm32l053_MemMap.h
  * @author  Efren Del Real
  * @Date    December 31th 2020
  * @version V1.0
  * @brief   STM32L063R8 memory mapping organization.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************
*/

#ifndef STM32L053_MEMMAP_H_
#define STM32L053_MEMMAP_H_

/*Include header files____________________________________________________________*/
#include "stm32xxxx_utility.h"

/*typedef definition______________________________________________________________*/

/*Macro definition________________________________________________________________*/

/*<=====================================================>
 *
 * MEMORY ORGANIZATION
 * Program memory, data memory, registers and I/O ports
 * are organized within the same linear 4Gbyte address
 * space.
 * 7) Device                        - 0xE010_0000 _ 0xFFFF_FFFF
 * 6) Private peripheral bus        - 0xE000_0000 _ 0xE00F_FFFF
 * 5) External device               - 0xA000_0000 _ 0xDFFF_FFFF
 * 4) External RAM                  - 0x6000_0000 _ 0x9FFF_FFFF
 * 3) Peripheral                    - 0x4000_0000 _ 0x5FFF_FFFF
 * 2) SRAM                          - 0x2000_0000 _ 0x3FFF_FFFF
 * 1) Code                          - 0x0000_0000 _ 0x1FFF_FFFF
 */

/**Cortex-M0+ Peripherals=========================================================*/
#define MEMAP_CORTEX_M0_P_BASEADDR           0xE0000000UL

/**Peripherals====================================================================*/
#define MEMMAP_IOPORT_BUS_BASEADDR           0x50000000UL
#define MEMMAP_AHB_BUS_BASEADDR              0x40020000UL
#define MEMMAP_APB2_BUS_BASEADDR             0x40010000UL
#define MEMMAP_APB1_BUS_BASEADDR             0x40000000UL

/*
 * Peripherals base address connected to IOPORT bus
 */
#define MEMMAP_GPIOH_PERIPH_BASEADDR        (MEMMAP_IOPORT_BUS_BASEADDR + 0x1C00UL)	/* General-purpose I/Os port H */
#define MEMMAP_GPIOE_PERIPH_BASEADDR        (MEMMAP_IOPORT_BUS_BASEADDR + 0x1000UL) /* General-purpose I/Os port E */
#define MEMMAP_GPIOD_PERIPH_BASEADDR        (MEMMAP_IOPORT_BUS_BASEADDR + 0x0C00UL)	/* General-purpose I/Os port D */
#define MEMMAP_GPIOC_PERIPH_BASEADDR        (MEMMAP_IOPORT_BUS_BASEADDR + 0x0800UL) /* General-purpose I/Os port C */
#define MEMMAP_GPIOB_PERIPH_BASEADDR        (MEMMAP_IOPORT_BUS_BASEADDR + 0x0400UL) /* General-purpose I/Os port B */
#define MEMMAP_GPIOA_PERIPH_BASEADDR        (MEMMAP_IOPORT_BUS_BASEADDR + 0x0000UL) /* General-purpose I/Os port A */

/*
 * Peripherals base address connected to AHB bus
 */
#define MEMAP_AES_PERIPH_BASEADDR           (MEMMAP_AHB_BUS_BASEADDR + 0x6000UL)
#define MEMAP_RGN_PERIPH_BASEADDR           (MEMMAP_AHB_BUS_BASEADDR + 0x5000UL)
#define MEMAP_TSC_PERIPH_BASEADDR           (MEMMAP_AHB_BUS_BASEADDR + 0x4000UL)
#define MEMAP_CRC_PERIPH_BASEADDR           (MEMMAP_AHB_BUS_BASEADDR + 0x3000UL)
#define MEMAP_FLASH_PERIPH_BASEADDR         (MEMMAP_AHB_BUS_BASEADDR + 0x2000UL)
#define MEMAP_RCC_PERIPH_BASEADDR           (MEMMAP_AHB_BUS_BASEADDR + 0x1000UL)	/* Reset and clock control */
#define MEMAP_DMA1_PERIPH_BASEADDR          (MEMMAP_AHB_BUS_BASEADDR + 0x0000UL)

/*
 * Peripherals base address connected to APB2 bus
 */
#define MEMAP_DBG_PERIPH_BASEADDR           (MEMMAP_APB2_BUS_BASEADDR + 0x5800UL)
#define MEMAP_USART1_PERIPH_BASEADDR        (MEMMAP_APB2_BUS_BASEADDR + 0x3800UL)
#define MEMAP_SPI1_PERIPH_BASEADDR          (MEMMAP_APB2_BUS_BASEADDR + 0x3000UL)
#define MEMAP_ADC1_PERIPH_BASEADDR          (MEMMAP_APB2_BUS_BASEADDR + 0x2400UL)
#define MEMAP_FIREWALL_PERIPH_BASEADDR      (MEMMAP_APB2_BUS_BASEADDR + 0x1C00UL)
#define MEMAP_TIM22_PERIPH_BASEADDR         (MEMMAP_APB2_BUS_BASEADDR + 0x1400UL)
#define MEMAP_TIM21_PERIPH_BASEADDR         (MEMMAP_APB2_BUS_BASEADDR + 0x0800UL)
#define MEMAP_EXTI_PERIPH_BASEADDR          (MEMMAP_APB2_BUS_BASEADDR + 0x0400UL)
#define MEMAP_SYSCFG_COMP_PERIPH_BASEADDR   (MEMMAP_APB2_BUS_BASEADDR + 0x0000UL)

/*
 * Peripherals base address connected to APB1 bus
 */
#define MEMAP_LPTIM1_PERIPH_BASEADDR        (MEMMAP_APB1_BUS_BASEADDR + 0x7C00UL)
#define MEMAP_I2C3_PERIPH_BASEADDR          (MEMMAP_APB1_BUS_BASEADDR + 0x7800UL)
#define MEMAP_DAC1_2_PERIPH_BASEADDR        (MEMMAP_APB1_BUS_BASEADDR + 0x7400UL)
#define MEMAP_PWR_PERIPH_BASEADDR           (MEMMAP_APB1_BUS_BASEADDR + 0x7000UL)
#define MEMAP_CRS_PERIPH_BASEADDR           (MEMMAP_APB1_BUS_BASEADDR + 0x6C00UL)
#define MEMAP_USB_PERIPH_BASEADDR           (MEMMAP_APB1_BUS_BASEADDR + 0x6000UL)
#define MEMAP_USB_FS_PERIPH_BASEADDR        (MEMMAP_APB1_BUS_BASEADDR + 0x5C00UL)
#define MEMAP_I2C2_PERIPH_BASEADDR          (MEMMAP_APB1_BUS_BASEADDR + 0x5800UL)
#define MEMAP_I2C1_PERIPH_BASEADDR          (MEMMAP_APB1_BUS_BASEADDR + 0x5400UL)
#define MEMAP_USART5_PERIPH_BASEADDR        (MEMMAP_APB1_BUS_BASEADDR + 0x5000UL)
#define MEMAP_USART4_PERIPH_BASEADDR        (MEMMAP_APB1_BUS_BASEADDR + 0x4C00UL)
#define MEMAP_LPUSART1_PERIPH_BASEADDR      (MEMMAP_APB1_BUS_BASEADDR + 0x4800UL)
#define MEMAP_USART2_PERIPH_BASEADDR        (MEMMAP_APB1_BUS_BASEADDR + 0x4400UL)
#define MEMAP_SPI2_PERIPH_BASEADDR          (MEMMAP_APB1_BUS_BASEADDR + 0x3800UL)
#define MEMAP_IWDG_PERIPH_BASEADDR          (MEMMAP_APB1_BUS_BASEADDR + 0x3000UL)
#define MEMAP_WWDG_PERIPH_BASEADDR          (MEMMAP_APB1_BUS_BASEADDR + 0x2C00UL)
#define MEMAP_RTC_PERIPH_BASEADDR           (MEMMAP_APB1_BUS_BASEADDR + 0x2800UL)
#define MEMAP_LCD_PERIPH_BASEADDR           (MEMMAP_APB1_BUS_BASEADDR + 0x2400UL)
#define MEMAP_TIMER7_PERIPH_BASEADDR        (MEMMAP_APB1_BUS_BASEADDR + 0x1400UL)
#define MEMAP_TIMER6_PERIPH_BASEADDR        (MEMMAP_APB1_BUS_BASEADDR + 0x1000UL)
#define MEMAP_TIMER3_PERIPH_BASEADDR        (MEMMAP_APB1_BUS_BASEADDR + 0x0400UL)
#define MEMAP_TIMER2_PERIPH_BASEADDR        (MEMMAP_APB1_BUS_BASEADDR + 0x0000UL)

/**SRAM============================================================================*/
/* @TODO */

 /**code============================================================================*/
 /* @TODO */


#endif /* STM32L053_MEMMAP_H_ */
