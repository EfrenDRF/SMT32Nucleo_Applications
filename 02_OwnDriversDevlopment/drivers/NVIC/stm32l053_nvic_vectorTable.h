/**
  ******************************************************************************
  * @file    stm32l053_nvic_vectorTable.h
  * @author  Efren Del Real
  * @Date    January 9th 2021
  * @version V1.0
  * @brief   Nested Vecoted Interrupt Controller (NVIC) Vector Table.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  * correct reference manual to modify the code or get more information related.
  ******************************************************************************
*/

#ifndef NVIC_STM32L053_NVIC_VECTORTABLE_H_
#define NVIC_STM32L053_NVIC_VECTORTABLE_H_


/*typedef definition______________________________________________________________*/

typedef enum
{
    /* Cortex M0+ interrups******************************************************/
    //IRQn_Reset              = -3,  /*Address 0x0000_0004*/
    //IRQn_NMI_Handler        = -2,  /*Address 0x0000_0008*/
    //IRQn_HardFault_Handler  = -1,  /*Address 0x0000_000C*/
    //IRQn_SVC_Handle         = 3,   /*Address 0x0000_002C*/
    //IRQn_PendSV_Handler     = 5,   /*Address 0x0000_0038*/
    //IRQn_SysTick_Handler    = 6,   /*Address 0x0000_003C*/


    /* Vector table interrups **************************************************/
    IRQn_WWDG                  = 0,    /*, Address 0x0000_0040*/
    IRQn_PVD                   = 1,    /*, Address 0x0000_0044*/
    IRQn_RTC                   = 2,    /*, Address 0x0000_0048*/
    IRQn_FLASH                 = 3,    /*, Address 0x0000_004C*/
    IRQn_RCC_CRS               = 4,    /*, Address 0x0000_0050*/
    IRQn_EXTI0_1               = 5,    /*, Address 0x0000_0054*/
    IRQn_EXTI2_3               = 6,    /*, Address 0x0000_0058*/
    IRQn_EXTI4_15              = 7,    /*, Address 0x0000_005C*/
    IRQn_TSC                   = 8,    /*, Address 0x0000_0060*/
    IRQn_DMA1_Channel1         = 9,    /*, Address 0x0000_0064*/
    IRQn_DMA1_Channel2_3       = 10,   /*, Address 0x0000_0068*/
    IRQn_DMA1_Channel4_7       = 11,   /*, Address 0x0000_006C*/
    IRQn_ADC_COMP              = 12,   /*, Address 0x0000_0070*/
    IRQn_LPTIM1                = 13,   /*, Address 0x0000_0074*/
    IRQn_USART4_5              = 14,   /*, Address 0x0000_0078*/
    IRQn_TIM2                  = 15,   /*, Address 0x0000_007C*/
    IRQn_TIM3                  = 16,   /*, Address 0x0000_0080*/
    IRQn_TIM6_DAC              = 17,   /*, Address 0x0000_0084*/
    IRQn_TIM7                  = 18,   /*, Address 0x0000_0088*/
    /*reserved                 = 19,       Address 0x0000_008C*/
    IRQn_TIM21                 = 20,   /*, Address 0x0000_0090*/
    IRQn_I2C3                  = 21,   /*, Address 0x0000_0094*/
    IRQn_TIM22                 = 22,   /*, Address 0x0000_0098*/
    IRQn_I2C1                  = 23,   /*, Address 0x0000_009C*/
    IRQn_I2C2                  = 24,   /*, Address 0x0000_00A0*/
    IRQn_SPI1                  = 25,   /*, Address 0x0000_00A4*/
    IRQn_SPI2                  = 26,   /*, Address 0x0000_00A8*/
    IRQn_USART1                = 27,   /*, Address 0x0000_00AC*/
    IRQn_USART2                = 28,   /*, Address 0x0000_00B0*/
    IRQn_LPUART1               = 29,   /*, Address 0x0000_00B4*/
    IRQn_LCD                   = 30,   /*, Address 0x0000_00B8*/
    IRQn_USB                   = 31    /*, Address 0x0000_00BC*/

}nvic_IRQn_t;


#endif /* NVIC_STM32L053_NVIC_VECTORTABLE_H_ */
