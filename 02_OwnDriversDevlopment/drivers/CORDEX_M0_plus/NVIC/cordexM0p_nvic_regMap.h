/**
  ******************************************************************************
  * @file    cordexM0p_nvic_regMap.h
  * @author  Efren Del Real
  * @Date    January 9th 2021
  * @version V1.0
  * @brief
  *
  * NOTE:
  ******************************************************************************
*/

#ifndef CORDEX_M0_PLUS_NVIC_CORDEXM0P_NVIC_REGMAP_H_
#define CORDEX_M0_PLUS_NVIC_CORDEXM0P_NVIC_REGMAP_H_

/*Include header files____________________________________________________________*/
#include "cordexM0p_periph_MemMap.h"

/*typedef definition______________________________________________________________*/

/*
 * NVIC register map data type.
 */
typedef struct
{
    vuint32_t ISER;             /* Offset 0x0000 - Interrupt Set-Enable Register*/
    uint32_t reserved1[31];
    vuint32_t ICER;             /* Offset 0x0080 - Interrupt Clear-Enable Register*/
    uint32_t reserved2[31];
    vuint32_t ISPR;             /* Offset 0x0100 - Interrupt Set-Pending Register*/
    uint32_t reserved3[31];
    vuint32_t ICPR;             /* Offset 0x0180 - Interrupt Clear-Pending Register*/
    uint32_t reserved4[95];
    vuint32_t IPR[8];           /* Offset 0x0300 - Interrupt Priority Registers*/
}nvic_regMap_t;

/*Macro definition_______________________________________________________________*/
/*
 * NVIC peripheral base address.
 */
#define NVIC_REGMAP		((nvic_regMap_t*)MEMMAP_M0P_NVIC_BASEADDR)


#endif /* CORDEX_M0_PLUS_NVIC_CORDEXM0P_NVIC_REGMAP_H_ */
