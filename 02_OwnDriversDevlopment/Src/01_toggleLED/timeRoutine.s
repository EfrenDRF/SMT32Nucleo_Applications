/**
  ******************************************************************************
  * @file      timeRoutine.s
  * @author    Efren Del Real
  * @date      January 4th 2021
  * @version   V1.0.0
  * @brief     Time routine to delay a specific time in milliseconds.
  * @Note      This routine is not 100% exactly and must be have a clock around
  *            131kHz in order to work PROPERLY.
  ******************************************************************************
  */
.syntax unified
.cpu cortex-m0plus
.fpu softvfp
.thumb

  .section .text
  .global __tr_DELAYms


__tr_DELAYms:
    MOVS R1, R0   /* R1 = u16Millisec                            - 1 cycle */
    CMP R1, #0    /* R1 == 0?                                    - 1 cycle */
    BEQ EXIT      /* ->TRUE  (R1 ==0) go to EXIT                 - 3 cycles*/
                  /* ->FALSE (R1!=0) continue below instructions - 1 cycle */

LOOP:

	MOVS R2, 12   /* R2 =  - 1 cycle*/
	/*---------------------------------------------------------> Delta1 */
NOP_LOOP:
    /* No Operation - 1 cycle per instruction =  7 cycles*/
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    SUBS R2, R2, #1  /*            1 cycle */
    BNE NOP_LOOP     /* -> TRUE  - 3 cycles */
                     /* -> FALSE - 1 cycle */
    /*----------------------------------------------------------> Delta2 */

	/* (Delta2 -Delta1) = 11 cycles. (Delta2-Delta1)*12 = 131 cycles aprox */
	/* 1 Cycle = 1/131kHz. So, 131 cycles = 1ms aprox */

    SUBS R1, R1, #1   /* R1-= 1 (Also update flags)                       - 1 cycle  */
    BNE LOOP          /* ->TRUE  (Z flag == 0) go to EXIT                 - 3 cycles */
                      /* ->FALSE (Z flag !=0) continue below instructions - 1 cycle */

EXIT:
    BX LR    /* Return from function call                                 - 3 cycles*/

  .end
/***********************************END OF FILE*********************************/
