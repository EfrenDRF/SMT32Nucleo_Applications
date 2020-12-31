/**
  ******************************************************************************
  * @file    main.c
  * @author  Efren Del Real
  * @Date	 December 28th 2020
  * @version V1.0
  * @brief   Application - MSI clock configured in order to get a clock out
  * 		 measurement around 8.192kHz.
  *
  *
  * 		 NOTE: Below code was ran it at SMT32L053R8. Please check reference
  * 		 manual in order to perform any change.
  *
  ******************************************************************************
*/

/* Include section __________________________________________________________________*/
#include <stdint.h>

/* Definition section _______________________________________________________________*/
/** Bus base address-----------------------------------------------------*/
#define AHB_BASE_ADDRESS		0x40020000UL
#define IOPORT_BASE_ADDRESS		0x50000000UL

/** Peripheral base address ---------------------------------------------*/
/*** -AHB */
#define RCC_BASE_ADDRESS		(AHB_BASE_ADDRESS + 0x00001000UL)

/*** -IOPORT */
#define GIPOA_BASE_ADDRESS		(IOPORT_BASE_ADDRESS)


/** Register base address -------------------------------------------------*/
/**** -RCC */
#define RCC_CR_REG_ADDR			(RCC_BASE_ADDRESS + 0x00u)
#define RCC_ICSCR_REG_ADDR		(RCC_BASE_ADDRESS + 0x04u)
#define RCC_CFGR_REG_ADDR		(RCC_BASE_ADDRESS + 0x0Cu)
#define RCC_IOPENR_REG_ADDR		(RCC_BASE_ADDRESS + 0x2Cu)

/**** -GPIO */
/**** -GPIOA */
#define GPIOA_MODER_REG_ADDR	(GIPOA_BASE_ADDRESS + 0x00u)
#define GPIOA_AFRH_REG_ADDR		(GIPOA_BASE_ADDRESS + 0x24u)


int main(void)
{
	uint32_t *pREG_ADDR;

	/* 1) Internal clock sources calibration register ==========================================
	 * Reset value: 0x00XX B0XX where X is undefined.
	 * */
	pREG_ADDR = (uint32_t*)RCC_ICSCR_REG_ADDR;

	/* 1.1) Bits 15:13  MSIRANGE - MSI clock ranges*/
	*pREG_ADDR &= ~(0x07UL << 13UL); /* Clean MSIRANGE bits field*/
	*pREG_ADDR |= (0x01 << 13UL); /* range 1 around 131.072 kHz*/


	/* 2) Clock control register ==============================================================
	 * System Reset value: 0b0000 0000 00XX 0X00 0000 0011 0000 0000 where X is undefined
	 * Power-on reset value: 0x0000 0300
	 * */
	pREG_ADDR = (uint32_t*)RCC_CR_REG_ADDR;

	/* 2.1) Bit 8 MSION - clock enable bit */
	*pREG_ADDR |= (0x01u <<  0x08u); /* MSI oscillator ON*/

	/* 2.2) Bit 9 MSIRDY - MSI clock ready flag */
	while(((*pREG_ADDR) & 0x0200UL) == 0x00UL);  /* Wait until MSI oscillator is ready*/




	/* 3) Clock configuration register =========================================================
	 * Reset value: 0x0000 0000
	 * */
	pREG_ADDR = (uint32_t*)RCC_CFGR_REG_ADDR;

	/* 3.1) Bits 1:0 SW - System clock switch */
	*pREG_ADDR &= ~(0x03UL);  /* 00 - MSI Oscillator used as system clock (default after reset)*/

	/* 3.2) Bits 27:24 MCOSEL- Microcontroller clock output*/
	*pREG_ADDR |= (0x01UL <<  24UL); /* SYSCLK clock selected*/

	/* 3.3) Bits 30:28 MCOPRE- Microcontroller clock output prescaler */
	*pREG_ADDR |= (0x04UL << 28UL);  /* MCO is divided by 16 */


	/* 4) GPIO clock enable register ==========================================================
	 * Reset value: 0x0000 0000
	 * */
	pREG_ADDR = (uint32_t *) RCC_IOPENR_REG_ADDR;

	/* 4.1) Bit 0 IOPAEN - IO port A clock enable bit */
	*pREG_ADDR |= 0x01UL; /* port A enabled*/


	/* 5) GPIO port mode register =============================================================
	 * Reset value: 0xEBFF FCFF for port A
	 * */
	pREG_ADDR = (uint32_t*)GPIOA_MODER_REG_ADDR;

	/* 5.1) Bits 17:16 MODE8 - Port A configuration bits*/
	*pREG_ADDR &= ~(0x03UL << 16UL); /* Cleans MODE8 bits field */
	*pREG_ADDR |= (0x02UL << 16UL); /* Set MODE8 as Alternate function*/


	/* 6) GPIO alternate function high register ==============================================
	 * Reset value: 0x0000 0000
	 * */
	pREG_ADDR = (uint32_t*)GPIOA_AFRH_REG_ADDR;

	/* 6.1) Bits 3: 0 AFSEL8 - Alternate function selection for port A pin 8 */
	*pREG_ADDR &= ~ 0x0FUL; /* Clean bits field (by default). AF0 selected */

	for(;;);
}
