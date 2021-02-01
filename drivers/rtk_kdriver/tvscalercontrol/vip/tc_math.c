/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2014
  * All rights reserved.
  * ========================================================================*/
  /*================= File Description =======================================*/
  /**
   * @file
   *  This file is for HDR TC related functions.
   *
   * @author  $Author$
   * @date	  $Date$
   * @version	  $Revision$
   */
/*============================ Module dependency	===========================*/
#if CONFIG_FIRMWARE_IN_KERNEL
#include <linux/string.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <linux/kernel.h>
//juwen, 0303
//#include "tvscalercontrol/vip/tc_hdr.h"
//#include <tvscalercontrol/vip/tc_hdr.h>
#include <tvscalercontrol/scaler/vipinclude.h> // for typedef that used in VIP_reg_def.h
#include <tvscalercontrol/vip/vip_reg_def.h>
//#include <rbus/rbusTCReg.h>
#include <rbus/tc_reg.h>

#else
#include <unistd.h>		// 'close()'
#include <fcntl.h>			// 'open()'
#include <stdio.h>
#include <sys/ioctl.h>

#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>
#include <Platform_Lib/TVScalerControl/vip/tc_hdr.h>
#include <Platform_Lib/TVScalerControl/vip/VIP_reg_def.h>

//juwen, 170216, TCv1.3.0_computeMetaData
//#include "SL_math.h"
#include <Platform_Lib/TVScalerControl/vip/tc_math.h>
#endif

#if CONFIG_FIRMWARE_IN_KERNEL
#define VIPprintf(fmt, args...)	pr_debug(fmt, ##args)//printk(KERN_DEBUG fmt, ##args)
#else
#define VIPprintf(fmt, args...)	printf(fmt, ##args)
#endif

//#define TC_HDR_Debug 0
#define INT32_MIN -2147483648
#define INT32_MAX 2147483647








/******************************************************************************
 * Find the most significant bit position
 ******************************************************************************/

int msb32(unsigned int argx)
{
  int val[16] = { 0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4 };
  unsigned int x = argx;
  int r = 0;


  if (x & 0xFFFF0000) {
    r += 16 / 1;
    x >>= 16 / 1;
  }
  if (x & 0x0000FF00) {
    r += 16 / 2;
    x >>= 16 / 2;
  }
  if (x & 0x000000F0) {
    r += 16 / 4;
    x >>= 16 / 4;
  }

  return r + val[x];
}

/******************************************************************************
 * Integer square root
 ******************************************************************************/

unsigned int sqrt16(unsigned int argx)
{
  unsigned short op  = 1<<15;
  unsigned int res = 1<<15;

  for (;;) {
    if ((res*res) > argx)
      res = res ^ op;

    op >>= 1;

    if (op == 0)
      return res + ((argx - res * res) > res ? 1 : 0);

    res = res | op;
  }

  return res;
}

/******************************************************************************
 * Signed Fixed-point Integer (SFI) math implementation
 * with width W=32 bit and fraction F=15 bit both fixed
 ******************************************************************************/

enum { FIXED_RESOLUTION_SHIFT = 15 };
enum { BIT_DEPTH = 32 };
enum { HALF_BIT_DEPTH = (BIT_DEPTH >> 1) };
enum { HALF_BIT_DEPTH_MASK = (1L << HALF_BIT_DEPTH) - 1 };
enum { MAX_POWER = BIT_DEPTH - 1 - FIXED_RESOLUTION_SHIFT };

/* Multiplication */
int sfi_w32f15_mult(int lhs_arg, int rhs_arg)
{
  int lhs_negative = (lhs_arg < 0);
  unsigned int lhs = lhs_negative ? (-lhs_arg) : lhs_arg;
  unsigned int lhs_upper = lhs >> HALF_BIT_DEPTH;
  unsigned int lhs_lower = lhs & HALF_BIT_DEPTH_MASK;
  int rhs_negative = (rhs_arg < 0);
  unsigned int rhs = rhs_negative ? (-rhs_arg) : rhs_arg;
  unsigned int rhs_upper = rhs >> HALF_BIT_DEPTH;
  unsigned int rhs_lower = rhs & HALF_BIT_DEPTH_MASK;
  unsigned int lower_lhs_upper_rhs_res = lhs_lower * rhs_upper;
  unsigned int lower_lhs_lower_rhs_res = lhs_lower * rhs_lower;
  int negative = (rhs_negative ^ lhs_negative);
  int res = 0;

  if (lhs_upper)
    res = (lhs_upper * rhs) << (HALF_BIT_DEPTH - FIXED_RESOLUTION_SHIFT);

  if (lhs_lower)
    res += (lower_lhs_upper_rhs_res << (HALF_BIT_DEPTH - FIXED_RESOLUTION_SHIFT)) + (lower_lhs_lower_rhs_res >> FIXED_RESOLUTION_SHIFT);

  if (negative)
    res = -res;

  return res;
}

/* Division */
int sfi_w32f15_div(int lhs_arg, int rhs_arg)
{
  if (!rhs_arg) {
    if (!lhs_arg)
      return 1 << FIXED_RESOLUTION_SHIFT;
    else
      return lhs_arg > 0 ? INT32_MAX : INT32_MIN + 1;
  }
  else  {
    int lhs_negative = (lhs_arg < 0);
    unsigned int lhs = lhs_negative ? (-lhs_arg) : lhs_arg;
    unsigned int half_lhs = (lhs >> 1);
    int rhs_negative = (rhs_arg < 0);
    unsigned int rhs = rhs_negative ? (-rhs_arg) : rhs_arg;
    unsigned int temp_rhs = rhs;
    int negative = (lhs_negative ^ rhs_negative);
    unsigned short shift = FIXED_RESOLUTION_SHIFT, right_shift;
    unsigned int d;
    unsigned int res = 0;

    if (lhs > rhs) {
      while (temp_rhs < half_lhs) {
        temp_rhs <<= 1;
        ++shift;
      }
    }

    d = 1 << shift;

    if (lhs > rhs) {
      lhs -= temp_rhs;
      res += d;
    }

    while (lhs && temp_rhs && shift) {
      right_shift = 0;
      while (right_shift < shift && (temp_rhs > lhs)) {
        temp_rhs >>= 1;
        ++right_shift;
      }

      d >>= right_shift;
      shift -= right_shift;
      lhs -= temp_rhs;
      res += d;
    }

    return negative ? -((int)res) : ((int)res);
  }
}

static int log_two_power_n_reversed_[MAX_POWER] = { 363409, 340696, 317983, 295270, 272557, 249844, 227130, 204417, 181704, 158991, 136278, 113565, 90852, 68139, 45426, 22713 };
static int log_one_plus_two_power_minus_n_[FIXED_RESOLUTION_SHIFT] = { 13286, 7312, 3860, 1987, 1008, 508, 255, 128, 64, 32, 16, 8, 4, 2, 1 };
static int log_one_over_one_minus_two_power_minus_n_[FIXED_RESOLUTION_SHIFT] = { 22713, 9427, 4376, 2115, 1040, 516, 257, 128, 64, 32, 16, 8, 4, 2, 1 };

/* Exponential function */
int sfi_w32f15_exp (int argx)
{
  int x = argx;
  short power;
  int *log_entry;
  int res = 1L << FIXED_RESOLUTION_SHIFT;

  if (x >= log_two_power_n_reversed_[0])
    return INT32_MAX;

  if (x < -log_two_power_n_reversed_[BIT_DEPTH - 1 - 2 * FIXED_RESOLUTION_SHIFT])
    return 0;

  if (!x)
    return res;

  if (x > 0) {
    power = MAX_POWER;
    log_entry = log_two_power_n_reversed_;

    while (x && power > (-(short)FIXED_RESOLUTION_SHIFT)) {
      while (!power || (x < *log_entry)) {
        if (!power)
          log_entry = log_one_plus_two_power_minus_n_;
        else
          ++log_entry;
        --power;
      }

      x -= *log_entry;

      if (power < 0)
        res += (res >> (-power));
      else
        res <<= power;
    }
  }
  else {
    power = FIXED_RESOLUTION_SHIFT;
    log_entry = log_two_power_n_reversed_ + (MAX_POWER - power);

    while (x && power > -FIXED_RESOLUTION_SHIFT) {
      while(!power || (x > (-*log_entry))) {
        if (!power)
          log_entry = log_one_over_one_minus_two_power_minus_n_;
        else
          ++log_entry;
        --power;
      }

      x += *log_entry;

      if (power < 0)
        res -= (res >> (-power));
      else
        res >>= power;
    }
  }

  return res;
}

/* Natural logarithm function */
int sfi_w32f15_log (int argx)
{
  unsigned int x = argx;
  unsigned int shift_x;
  unsigned int scale_position = 0x80000000;
  short left_shift = 0;
  unsigned int right_shift = 1;
  int res;

  if (x <= 0)
    return (INT32_MIN+1);

  if (x == 1L << FIXED_RESOLUTION_SHIFT)
    return 0;

  while (x < scale_position) {
    ++left_shift;
    x <<= 1;
  }

  shift_x = x >> 1;

  if (left_shift < MAX_POWER)
    res = log_two_power_n_reversed_[left_shift];
  else if (left_shift > MAX_POWER)
    res = -log_two_power_n_reversed_[2 * MAX_POWER - left_shift];
  else
    res = 0;

  while (x && (right_shift < FIXED_RESOLUTION_SHIFT)) {
    while ((right_shift < FIXED_RESOLUTION_SHIFT) && (x < (shift_x + scale_position))) {
      shift_x >>= 1;
      ++right_shift;
    }

    x -= shift_x;
    shift_x = x >> right_shift;
    res += log_one_over_one_minus_two_power_minus_n_[right_shift - 1];
  }

  return res;
}
