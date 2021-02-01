#ifndef  __SL_MATH_H__
#define  __SL_MATH_H__

#ifdef __cplusplus
extern "C" {
#endif
/* some include about scaler*/
#if CONFIG_FIRMWARE_IN_KERNEL
#include <scalercommon/vipCommon.h>
#else
#include <scaler/vipCommon.h>
#endif


//juwen, 0308, compile error
//#include <stdint.h>

//juwen, 0308, compile error
//#define ABS(x) ((x >= 0) ? x : -(x))

/******************************************************************************
 * Find the most significant bit position
 ******************************************************************************/

int msb32(unsigned int argx);

/******************************************************************************
 * Integer square root
 ******************************************************************************/

unsigned int sqrt16(unsigned int argx);

/******************************************************************************
 * Signed Fixed-point Integer (SFI) math implementation
 * with width W=32 bit and fraction F=15 bit both fixed
 ******************************************************************************/

/* Multiplication */
int sfi_w32f15_mult(int lhs_arg, int rhs_arg);

/* Division */
int sfi_w32f15_div(int lhs_arg, int rhs_arg);

/* Exponential function */
int sfi_w32f15_exp(int argx);

/* Natural logarithm function */
int sfi_w32f15_log(int argx);

#endif // SL_MATH_H
