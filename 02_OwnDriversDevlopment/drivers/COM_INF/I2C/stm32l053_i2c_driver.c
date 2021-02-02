/**
  ******************************************************************************
  * @file    stm32l053_i2c_driver.c
  * @author  Efren Del Real
  * @Date    February 1st 2021
  * @version V1.0
  * @brief   Inter-integrated circuit interface - Definition driver APIs
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/

/*Include header files____________________________________________________________*/
#include "stm32l053_i2c_driver.h"

void i2c_Init(i2c_handle_t * pI2Chandle)
{
	i2c_regMap_t * const     tmpI2cReg = pI2Chandle->pI2Cx;
	i2c_cfg_t  const * const tmpI2cCfg = &pI2Chandle->I2Ccfg;

	(void)tmpI2cCfg;

	// .- Clear PE bit in I2C_CR1
	MEMMAP_CLEAN_BIT(tmpI2cReg->CR1 , I2C_CR1_PE_B);

	//.- Wait until PE bit is clean.
	while( (tmpI2cReg->CR1 & (1u << I2C_CR1_PE_B)) != MEMMAP_BIT_CLEAN)
	{/* Avoid Misra */}

	// .-Set PE bit in I2C_CR1
	MEMMAP_SET_BIT(tmpI2cReg->CR1 , I2C_CR1_PE_B);



}
