/**
  ******************************************************************************
  * @file    stm3xxxx_utility.h
  * @author  Efren Del Real
  * @Date    February 13th 2021
  * @version V1.0
  * @brief   Macros and datatypes for abstraction of STM32xxxx dev drivers
  *
  ******************************************************************************
*/
#ifndef STM32XXXX_UTILITY_H_
#define STM32XXXX_UTILITY_H_
/*Include header files____________________________________________________________*/
#include <stdint.h>

/*typedef definition______________________________________________________________*/
typedef volatile uint32_t vuint32_t;


/*Macro definition________________________________________________________________*/


#define BIT_SET		(0x01u)
#define BIT_CLEAN	(0x00u)

#define CLEAN_1B (0x01u)
#define CLEAN_2B (0x03u)
#define CLEAN_3B (0x07u)
#define CLEAN_4B (0x0Fu)
#define CLEAN_8B (0xFFu)

#define SET_BIT(reg,bitPos)    ( (reg) |=  ( BIT_SET  << (bitPos)) )
#define CLEAN_BIT(reg,bitPos)  ( (reg) &= ~( CLEAN_1B << (bitPos)) )

#define SET_BITFIELD(reg,value)      ( (reg) |=  (value))
#define CLEAN_BITFIELD(reg,value)    ( (reg) &= ~(value))


/*=====================================================================
 * Macros for clasification of the object instance (memClass)
 *=====================================================================*/
#define AUTO
#define EXTERN           extern
#define STATIC           static
#define INLINE           STATIC inline

/*=====================================================================
 * Macros for variables
 *=====================================================================*/
#define VAR(dataType, memClass)                  memClass dataType

/*=====================================================================
 * Macros for constant
 *=====================================================================*/
#define CONST(dataType, memClass)                const memClass dataType

/*=====================================================================
 * Macros for pointers
 *=====================================================================*/
#define NULL_PTR                                ((void*)0)
#define PTR2_VAR(ptrDataType, memClass)         memClass ptrDataType *
#define PTR2_CONST(ptrDataType, memClass)       const memClass ptrDataType *
#define CONSTPTR2_VAR(ptrDataType, memClass)    memClass ptrDataType * const
#define CONSTPTR2_CONST(ptrDataType, memClass)  const memClass ptrDataType * const

/*=====================================================================
 * Macros for functions
 *=====================================================================*/
#define FUNC(retDataType, memClass) memClass retDataType

#endif /* STM32XXXX_UTILITY_H_ */
