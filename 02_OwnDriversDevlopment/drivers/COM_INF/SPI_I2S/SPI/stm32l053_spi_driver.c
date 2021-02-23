/**
  ******************************************************************************
  * @file    stm32l053_spi_driver.c
  * @author  Efren Del Real
  * @Date    January 19th 2021
  * @version V1.0
  * @brief   Serial peripheral interface driver.
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/
/*Include header files____________________________________________________________*/
#include "stm32l053_spi_driver.h"
#include "stm32l053_spii2s_driver.h"
#include "stm32l053_rcc_driver.h"

/*=====================================================================
 * Local function definition
 *=====================================================================*/

/****************************************************************
 * @fn			- gpio_GetSPIIndex.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		-
 *
 * @Note		-
 */
FUNC(uint8_t, STATIC) gpio_GetSPIIndex(CONSTPTR2_CONST(spi_regMap_t, AUTO) spiRegPtr)
{
	VAR(uint8_t,AUTO) retVal = 0u;

	if (spiRegPtr == SPI1_REGMAP){retVal = SPI1_INDEX;}
	else if (spiRegPtr == SPI2_REGMAP){retVal = SPI2_INDEX;}
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
 * @fn			- spi_Init.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		- none
 */
FUNC(void,AUTO) spi_Init(CONSTPTR2_VAR(spi_handle_t, AUTO)spiHandlePtr)
{
	CONSTPTR2_VAR(spi_regMap_t,AUTO) spiRegPtr = spiHandlePtr->spiRegPtr;
	CONSTPTR2_CONST(spi_cfg_t,AUTO)  spiCfgPtr = &spiHandlePtr->spiCfg;
	CONST(uint8_t,AUTO)              spiIndex = gpio_GetSPIIndex(spiRegPtr);

	// a) Turns on SPI peripheral clock.
	rcc_SPIxClockControl(spiIndex, RCC_CLK_EN);

	// b) Configures serial clock baud rate
	if(spiCfgPtr->devMode != SLAVE_MODE)
	{
		spiRegPtr->CR1 |= (spiCfgPtr->cbr << SPI_CR1_BR_B);
	}

	// c) Configures CPOL  and CPHA bits combination to define one of the for
	//    relationships between the data transfer and the serial clock.
	spiRegPtr->CR1 |= (spiCfgPtr->cpha << SPI_CR1_CPHA_B);

	spiRegPtr->CR1 |= (spiCfgPtr->cpol << SPI_CR1_CPOL_B);

	// d) Configures LSBFIST bit to define the frame format.
	spiRegPtr->CR1 |= (spiCfgPtr->ff << SPI_CR1_LSBFIRST_B);

	// e) Configures SSM and SSI
	spiRegPtr->CR1 |= (spiCfgPtr->ssm << SPI_CR1_SSM_B);

	if(spiCfgPtr->ssm == SW_NSS_MODE)
	{
		spiRegPtr->CR1 |= (BIT_SET << SPI_CR1_SSI_B);
	}
	else
	{
		if(spiCfgPtr->devMode == MASTER_MODE)
		{
			/* 1 : SS output is enabled in master mode and when the cell
			 * is enabled. The cell cannot work in a multimaster environment
             */
			spiRegPtr->CR2 |= (1u << SPI_CR2_SSOE_B);
		}
		else if(spiCfgPtr->devMode == MULTIMASTER_MODE)
		{
			/* 0: SS output is disabled in master mode and the cell can work
			 *  in multimaster configuration
			 */
			spiRegPtr->CR2 &= ~(1u << SPI_CR2_SSOE_B);
		}
		else
		{
			/* No action required */
		}
	}

	// f) Configures device mode
	spiRegPtr->CR1 |= ((spiCfgPtr->devMode & 0x01u) << SPI_CR1_MSTR_B);

	// g) Configures data frame format
	spiRegPtr->CR1 |= (spiCfgPtr->dff << SPI_CR1_DDF_B);

	// h) Configures communication mode.
	switch(spiCfgPtr->comMode)
	{
		case FULL_DUPLEX:
		case SIMPLEX_TX_ONLY:
			spiRegPtr->CR1 &= ~(1u << SPI_CR1_BIDIMODE_B);
			break;
		case SIMPLEX_RX_ONLY:
			spiRegPtr->CR1 &= ~(1u << SPI_CR1_BIDIMODE_B);
			spiRegPtr->CR1 |= (1u << SPI_CR1_RXONLY_B);
			break;
		case HALF_DUPLEX:
			spiRegPtr->CR1 &= ~(1u << SPI_CR1_RXONLY_B);
			spiRegPtr->CR1 |= (1u << SPI_CR1_BIDIMODE_B);
			break;
		default:
			break;
	};

}

/****************************************************************
 * @fn			- spi_PeriphCtrl.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		- none
 */
FUNC(void,AUTO) spi_PeriphCtrl(CONSTPTR2_VAR(spi_regMap_t,AUTO) spiRegPtr, VAR(uint8_t,AUTO) control)
{
	if(control == BIT_SET)
	{
		// .- Enables SPI peripheral.
		spiRegPtr->CR1 |= (1u << SPI_CR1_SPE_B);
	}
	else
	{
		// .- Waits until SPI is not busy.
		while( spii2s_GetStatusFlag(spiRegPtr, SPI_SR_BSY_B) == BIT_SET);

		// .- Disables SPI peripheral.
		spiRegPtr->CR1 &= ~(1u << SPI_CR1_SPE_B);
	}
}


/****************************************************************
 * @fn			- spi_SendData.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		- none
 */
FUNC(void,AUTO) spi_SendData(CONSTPTR2_VAR(spi_regMap_t,AUTO) spiRegPtr, CONSTPTR2_CONST(uint8_t,AUTO)u8DataPrt, VAR(uint8_t,AUTO) u8Length)
{
	VAR(uint8_t,AUTO) tmpU8Length = u8Length;

	while(tmpU8Length > 0u)
	{
		// .- Wait until TXE flag (Tx buffer empty) is set.
		while( spii2s_GetStatusFlag(spiRegPtr, SPI_SR_TXE_B) == BIT_CLEAN);

		/*
		 * It indicates that the internal Tx buffer is ready to be loaded
		 * with the next data.
		 *
		 * Clearing the TXE flag is performed by writing to the SPI_DR register.
		 */
		if( (spiRegPtr->CR1 & (1u << SPI_CR1_DDF_B)) == 0u )
		{
			// .- 8 bits Data Frame Format.
			spiRegPtr->DR = u8DataPrt[u8Length-tmpU8Length];
			tmpU8Length--;
		}
		else
		{
			// .- 16 bits Data Frame Format.
			spiRegPtr->DR = (uint16_t)(*(uint16_t*)&u8DataPrt[u8Length-tmpU8Length]);
			tmpU8Length-= 2;
		}

	}

}

/****************************************************************
 * @fn			- spi_ReceiveData.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		- none
 */
FUNC(void,AUTO) spi_ReceiveData(CONSTPTR2_VAR(spi_regMap_t,AUTO) spiRegPtr, CONSTPTR2_VAR(uint8_t,AUTO)u8DataPrt, VAR(uint8_t,AUTO) u8Length)
{
	VAR(uint8_t,AUTO) tmpU8Length = u8Length;

	while(tmpU8Length > 0u)
	{
		// .- Wait until RXNE flag (Rx buffer not empty) is set.
		while( spii2s_GetStatusFlag(spiRegPtr, SPI_SR_RXE_B) == BIT_CLEAN);


		/*
		 * Data are ready to read from the SPI_DR register.
		 *
		 * Clearing the RXNE bit is performed by reading
		 * SPI_DR register.
		 */

		if( (spiRegPtr->CR1 & (1u << SPI_CR1_DDF_B)) == 0u )
		{
			// .- 8 bits Data Frame Format.
			u8DataPrt[u8Length-tmpU8Length] = *(uint8_t*)&(spiRegPtr->DR);
			tmpU8Length--;
		}
		else
		{
			// .- 16 bits Data Frame Format.
			*(uint16_t*)&u8DataPrt[u8Length-tmpU8Length] = *(uint16_t*)&(spiRegPtr->DR);
			tmpU8Length-= 2;
		}

	}

}


/****************************END OF FILE *******************************************/
