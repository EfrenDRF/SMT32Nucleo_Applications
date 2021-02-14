/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/



#include "stm32l053_MemMap.h"
#include "stm32l053_gpio_driver.h"
#include "stm32l053_rcc_driver.h"
#include "stm32l053_exti_driver.h"
#include "stm32l053_syscfg_driver.h"
#include "cordexM0p_nvic_driver.h"
#include "stm32l053_spi_driver.h"
#include "stm32l053_i2c_driver.h"


int main(void)
{
	uint8_t value = 0u;
	value = sizeof(gpio_pinCfg_t);
	value = sizeof(spi_cfg_t);
	value = sizeof(i2c_cfg_t);
	(void) value;




	for(;;);
	return 0;
}
