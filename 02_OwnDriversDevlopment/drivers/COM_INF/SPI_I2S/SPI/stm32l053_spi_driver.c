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
void spi_Init(spi_handle_t * pSPIhandle)
{
	uint8_t u8Tmp =0u;

	// a) Configure the serial clock baud rate
	if(pSPIhandle->SPIcfg.devMode != SLAVE_MODE)
	{
		u8Tmp = pSPIhandle->SPIcfg.cbr;
		pSPIhandle->pSPIx->CR1 |= (u8Tmp << SPI_CR1_BR_B);
	}

	// b) Configure CPOL  and CPHA bits combination to define one of the for
	//    relationships between the data transfer and the serial clock.
	u8Tmp = pSPIhandle->SPIcfg.cpha;
	pSPIhandle->pSPIx->CR1 |= (u8Tmp << SPI_CR1_CPHA_B);

	u8Tmp = pSPIhandle->SPIcfg.cpol;
	pSPIhandle->pSPIx->CR1 |= (u8Tmp << SPI_CR1_CPOL_B);

	// c) Configure the LSBFIST bit to define the frame format.
	u8Tmp = pSPIhandle->SPIcfg.ff;
	pSPIhandle->pSPIx->CR1 |= (u8Tmp << SPI_CR1_LSBFIRST_B);

	// d) Configure SSM and SSI
	u8Tmp = pSPIhandle->SPIcfg.ssm;
	pSPIhandle->pSPIx->CR1 |= (u8Tmp << SPI_CR1_SSM_B);

	if(pSPIhandle->SPIcfg.ssm == SW_NSS_MODE)
	{
		pSPIhandle->pSPIx->CR1 |= (1u << SPI_CR1_SSI_B);
	}
	else
	{
		if(pSPIhandle->SPIcfg.devMode == MASTER_MODE)
		{
			/* 1 : SS output is enabled in master mode and when the cell
			 * is enabled. The cell cannot work in a multimaster environment
             */
			pSPIhandle->pSPIx->CR2 |= (1u << SPI_CR2_SSOE_B);
		}
		else if(pSPIhandle->SPIcfg.devMode == MULTIMASTER_MODE)
		{
			/* 0: SS output is disabled in master mode and the cell can work
			 *  in multimaster configuration
			 */
			pSPIhandle->pSPIx->CR2 &= ~(1u << SPI_CR2_SSOE_B);
		}
		else
		{
			/* No action required */
		}
	}

	// e) Configure the device mode
	u8Tmp = (pSPIhandle->SPIcfg.devMode & 1u);
	pSPIhandle->pSPIx->CR1 |= (u8Tmp << SPI_CR1_MSTR_B);

	// f) Configure the data frame format
	u8Tmp = pSPIhandle->SPIcfg.dff;
	pSPIhandle->pSPIx->CR1 |= (u8Tmp << SPI_CR1_DDF_B);

	// g) Configure the communication mode.
	switch(pSPIhandle->SPIcfg.comMode)
	{
	case FULL_DUPLEX:
	case SIMPLEX_TX_ONLY:
		pSPIhandle->pSPIx->CR1 &= ~(1u << SPI_CR1_BIDIMODE_B);
		break;
	case SIMPLEX_RX_ONLY:
		pSPIhandle->pSPIx->CR1 &= ~(1u << SPI_CR1_BIDIMODE_B);
		pSPIhandle->pSPIx->CR1 |= (1u << SPI_CR1_RXONLY_B);
		break;
	case HALF_DUPLEX:
		pSPIhandle->pSPIx->CR1 &= ~(1u << SPI_CR1_RXONLY_B);
		pSPIhandle->pSPIx->CR1 |= (1u << SPI_CR1_BIDIMODE_B);
		break;
	default:
		break;
	};

}

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
void spi_PeriphCtrl(spi_regMap_t * const pSPIx, uint8_t control)
{
	if(control == MEMMAP_BIT_SET)
	{
		// .- Enables SPI peripheral.
		pSPIx->CR1 |= (1u << SPI_CR1_SPE_B);
	}
	else
	{
		// .- Waits until SPI is not busy.
		while( spii2s_GetStatusFlag(pSPIx, SPI_SR_BSY_B) == MEMMAP_BIT_SET);

		// .- Disables SPI peripheral.
		pSPIx->CR1 &= ~(1u << SPI_CR1_SPE_B);
	}
}

/****************************************************************
 * @fn			- spi_SSICtrl.
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @return		- none.
 *
 * @Note		- none
 */
void spi_SSICtrl(spi_regMap_t * const pSPIx, uint8_t control)
{

	if( (pSPIx->CR1 & (1u << SPI_CR1_SSM_B)) != 0u)
	{
		if(control == MEMMAP_BIT_SET)
		{
			pSPIx->CR1 |= (1u << SPI_CR1_SSI_B);
		}
		else
		{
			pSPIx->CR1 &= ~(1u << SPI_CR1_SSI_B);
		}
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
void spi_SendData(spi_regMap_t * const pSPIx, uint8_t *pData, uint8_t uLen)
{
	uint8_t u8TmpLen = uLen;

	while(u8TmpLen > 0u)
	{

		// Wait until Tx buffer flag is set
		while( spii2s_GetStatusFlag(pSPIx, SPI_SR_TXE_B) == MEMMAP_BIT_CLEAN);


		// Data Frame Format
		if( (pSPIx->CR1 & (1u << SPI_CR1_DDF_B)) == 0u )
		{
			// 8 bits Data Frame Format.
			pSPIx->DR = pData[uLen-u8TmpLen];
			u8TmpLen--;
		}
		else
		{
			// 16 bits Data Frame Format.
			pSPIx->DR = (uint16_t)(*(uint16_t*)&pData[uLen-u8TmpLen]);
			u8TmpLen-= 2;
		}

	}

}
