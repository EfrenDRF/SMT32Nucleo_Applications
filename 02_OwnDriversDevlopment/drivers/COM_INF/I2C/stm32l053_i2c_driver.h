/**
  ******************************************************************************
  * @file    stm32l053_i2c_driver.h
  * @author  Efren Del Real
  * @Date    February 1st 2021
  * @version V1.0
  * @brief   Inter-integrated circuit interface - Declaration driver APIs
  *
  * NOTE: Below code was written using RM0367 reference manual. Please check your
  *       correct reference manual to modify the code or get more information
  *       related.
  ******************************************************************************
*/

#ifndef COM_INF_I2C_STM32L053_I2C_DRIVER_H_
#define COM_INF_I2C_STM32L053_I2C_DRIVER_H_

/*Include header files____________________________________________________________*/
#include "stm32l053_i2c_regMap.h"
#include "stm32l053_i2c_types.h"
#include "stm32l053_rcc_types.h"

/*typedef definition______________________________________________________________*/

/*=================================================================
 *
 *=================================================================*/

/*
 *
 */
typedef struct
{
	i2c_oaen_t      ACKcontrol:1;
	uint16_t        u16Address;
}i2c_oa1cfg_t;

/*
 *
 */
typedef struct
{
	i2c_oaen_t        ACKcontrol:1;
	uint8_t           u8Address;
	i2c_oar2oa2msk_t  mask:3;
}i2c_oa2cfg_t;

/*
 *
 */
typedef struct
{
	i2c_oa1cfg_t       i2cOA1cfg;
	i2c_oa2cfg_t       i2cOA2cfg;
	i2c_cr1gcen_t      i2cGenAddr:1;
	i2c_cr1sbc_t       i2cSlaveByteCtrl:1;
	i2c_cr1nostretch_t i2cStretchClock:1;
}i2c_slavecfg_t;
/*=================================================================
 *
 *=================================================================*/

/*=================================================================
 *
 *=================================================================*/
/*
 * I2C peripheral configuration type.
 */
typedef struct
{
	i2c_intfmode_t       i2cIntfMode:1;         /*I2C interface mode */
	i2c_spdmode_t        i2cSCLspeedMode:2;     /*I2C SCL speed mode*/
	i2c_addrmode         i2cAddrMode:1;         /*I2C addressing mode*/

	i2c_slavecfg_t       i2cSlaveCfg;
	rcc_ccipri2cxsel_t   rccClockSource:2;      /*RCC clock source selection*/
}i2c_cfg_t;

/*
 * I2C structure handle type.
 */
typedef struct
{
	i2c_regMap_t * i2cRegPtr;
	i2c_cfg_t      i2cCfg;
}i2c_handle_t;

/*Global function declaration_____________________________________________________*/

/*=================================================================
 * APIs supported by I2C driver.
 *=================================================================*/
FUNC(void,EXTERN) i2c_Init(CONSTPTR2_VAR(i2c_handle_t,AUTO) i2cHandlePtr);
FUNC(void,EXTERN) i2c_DeInit(CONSTPTR2_VAR(i2c_regMap_t,AUTO) i2cRegPtr);

FUNC(void,EXTERN) i2c_SlaveTx(void);
FUNC(void,EXTERN) i2c_SlaveRx(void);


FUNC(void,EXTERN) i2c_MasterTx(void);
FUNC(void,EXTERN) i2c_MasterRx(void);

#endif /* COM_INF_I2C_STM32L053_I2C_DRIVER_H_ */
