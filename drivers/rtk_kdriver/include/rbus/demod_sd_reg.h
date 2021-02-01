/**
* @file Mac5-DesignSpec-demod_sd
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DEMOD_SD_REG_H_
#define _RBUS_DEMOD_SD_REG_H_

#include "rbus_types.h"



//  DEMOD_SD Register Address
#define  DEMOD_SD_SIGMA_DELTA_CTL                                                0x18071000
#define  DEMOD_SD_SIGMA_DELTA_CTL_reg_addr                                       "0xB8071000"
#define  DEMOD_SD_SIGMA_DELTA_CTL_reg                                            0xB8071000
#define  DEMOD_SD_SIGMA_DELTA_CTL_inst_addr                                      "0x0000"
#define  set_DEMOD_SD_SIGMA_DELTA_CTL_reg(data)                                  (*((volatile unsigned int*)DEMOD_SD_SIGMA_DELTA_CTL_reg)=data)
#define  get_DEMOD_SD_SIGMA_DELTA_CTL_reg                                        (*((volatile unsigned int*)DEMOD_SD_SIGMA_DELTA_CTL_reg))
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_polarity_shift                        (20)
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_input_sel_shift                       (16)
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_dn_sel_shift                          (12)
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_polarity_s_shift                      (8)
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_input_sel_s_shift                     (4)
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_dn_sel_s_shift                        (0)
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_polarity_mask                         (0x00100000)
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_input_sel_mask                        (0x00030000)
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_dn_sel_mask                           (0x0000F000)
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_polarity_s_mask                       (0x00000100)
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_input_sel_s_mask                      (0x00000030)
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_dn_sel_s_mask                         (0x0000000F)
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_polarity(data)                        (0x00100000&((data)<<20))
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_input_sel(data)                       (0x00030000&((data)<<16))
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_dn_sel(data)                          (0x0000F000&((data)<<12))
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_polarity_s(data)                      (0x00000100&((data)<<8))
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_input_sel_s(data)                     (0x00000030&((data)<<4))
#define  DEMOD_SD_SIGMA_DELTA_CTL_demod_sd_dn_sel_s(data)                        (0x0000000F&(data))
#define  DEMOD_SD_SIGMA_DELTA_CTL_get_demod_sd_polarity(data)                    ((0x00100000&(data))>>20)
#define  DEMOD_SD_SIGMA_DELTA_CTL_get_demod_sd_input_sel(data)                   ((0x00030000&(data))>>16)
#define  DEMOD_SD_SIGMA_DELTA_CTL_get_demod_sd_dn_sel(data)                      ((0x0000F000&(data))>>12)
#define  DEMOD_SD_SIGMA_DELTA_CTL_get_demod_sd_polarity_s(data)                  ((0x00000100&(data))>>8)
#define  DEMOD_SD_SIGMA_DELTA_CTL_get_demod_sd_input_sel_s(data)                 ((0x00000030&(data))>>4)
#define  DEMOD_SD_SIGMA_DELTA_CTL_get_demod_sd_dn_sel_s(data)                    (0x0000000F&(data))

#define  DEMOD_SD_SIGMA_DELTA_FIX                                                0x18071004
#define  DEMOD_SD_SIGMA_DELTA_FIX_reg_addr                                       "0xB8071004"
#define  DEMOD_SD_SIGMA_DELTA_FIX_reg                                            0xB8071004
#define  DEMOD_SD_SIGMA_DELTA_FIX_inst_addr                                      "0x0001"
#define  set_DEMOD_SD_SIGMA_DELTA_FIX_reg(data)                                  (*((volatile unsigned int*)DEMOD_SD_SIGMA_DELTA_FIX_reg)=data)
#define  get_DEMOD_SD_SIGMA_DELTA_FIX_reg                                        (*((volatile unsigned int*)DEMOD_SD_SIGMA_DELTA_FIX_reg))
#define  DEMOD_SD_SIGMA_DELTA_FIX_demod_sd_fix_val_shift                         (20)
#define  DEMOD_SD_SIGMA_DELTA_FIX_demod_sd_fix_shift                             (16)
#define  DEMOD_SD_SIGMA_DELTA_FIX_demod_sd_fix_val_s_shift                       (4)
#define  DEMOD_SD_SIGMA_DELTA_FIX_demod_sd_fix_s_shift                           (0)
#define  DEMOD_SD_SIGMA_DELTA_FIX_demod_sd_fix_val_mask                          (0xFFF00000)
#define  DEMOD_SD_SIGMA_DELTA_FIX_demod_sd_fix_mask                              (0x00010000)
#define  DEMOD_SD_SIGMA_DELTA_FIX_demod_sd_fix_val_s_mask                        (0x0000FFF0)
#define  DEMOD_SD_SIGMA_DELTA_FIX_demod_sd_fix_s_mask                            (0x00000001)
#define  DEMOD_SD_SIGMA_DELTA_FIX_demod_sd_fix_val(data)                         (0xFFF00000&((data)<<20))
#define  DEMOD_SD_SIGMA_DELTA_FIX_demod_sd_fix(data)                             (0x00010000&((data)<<16))
#define  DEMOD_SD_SIGMA_DELTA_FIX_demod_sd_fix_val_s(data)                       (0x0000FFF0&((data)<<4))
#define  DEMOD_SD_SIGMA_DELTA_FIX_demod_sd_fix_s(data)                           (0x00000001&(data))
#define  DEMOD_SD_SIGMA_DELTA_FIX_get_demod_sd_fix_val(data)                     ((0xFFF00000&(data))>>20)
#define  DEMOD_SD_SIGMA_DELTA_FIX_get_demod_sd_fix(data)                         ((0x00010000&(data))>>16)
#define  DEMOD_SD_SIGMA_DELTA_FIX_get_demod_sd_fix_val_s(data)                   ((0x0000FFF0&(data))>>4)
#define  DEMOD_SD_SIGMA_DELTA_FIX_get_demod_sd_fix_s(data)                       (0x00000001&(data))

#define  DEMOD_SD_SIGMA_DELTA_INPUT                                              0x18071008
#define  DEMOD_SD_SIGMA_DELTA_INPUT_reg_addr                                     "0xB8071008"
#define  DEMOD_SD_SIGMA_DELTA_INPUT_reg                                          0xB8071008
#define  DEMOD_SD_SIGMA_DELTA_INPUT_inst_addr                                    "0x0002"
#define  set_DEMOD_SD_SIGMA_DELTA_INPUT_reg(data)                                (*((volatile unsigned int*)DEMOD_SD_SIGMA_DELTA_INPUT_reg)=data)
#define  get_DEMOD_SD_SIGMA_DELTA_INPUT_reg                                      (*((volatile unsigned int*)DEMOD_SD_SIGMA_DELTA_INPUT_reg))
#define  DEMOD_SD_SIGMA_DELTA_INPUT_demod_sd_input_shift                         (12)
#define  DEMOD_SD_SIGMA_DELTA_INPUT_demod_sd_input_s_shift                       (0)
#define  DEMOD_SD_SIGMA_DELTA_INPUT_demod_sd_input_mask                          (0x00FFF000)
#define  DEMOD_SD_SIGMA_DELTA_INPUT_demod_sd_input_s_mask                        (0x00000FFF)
#define  DEMOD_SD_SIGMA_DELTA_INPUT_demod_sd_input(data)                         (0x00FFF000&((data)<<12))
#define  DEMOD_SD_SIGMA_DELTA_INPUT_demod_sd_input_s(data)                       (0x00000FFF&(data))
#define  DEMOD_SD_SIGMA_DELTA_INPUT_get_demod_sd_input(data)                     ((0x00FFF000&(data))>>12)
#define  DEMOD_SD_SIGMA_DELTA_INPUT_get_demod_sd_input_s(data)                   (0x00000FFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DEMOD_SD register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  demod_sd_polarity:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  demod_sd_input_sel:2;
        RBus_UInt32  demod_sd_dn_sel:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  demod_sd_polarity_s:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  demod_sd_input_sel_s:2;
        RBus_UInt32  demod_sd_dn_sel_s:4;
    };
}demod_sd_sigma_delta_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  demod_sd_fix_val:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  demod_sd_fix:1;
        RBus_UInt32  demod_sd_fix_val_s:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  demod_sd_fix_s:1;
    };
}demod_sd_sigma_delta_fix_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  demod_sd_input:12;
        RBus_UInt32  demod_sd_input_s:12;
    };
}demod_sd_sigma_delta_input_RBUS;

#else //apply LITTLE_ENDIAN

//======DEMOD_SD register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  demod_sd_dn_sel_s:4;
        RBus_UInt32  demod_sd_input_sel_s:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  demod_sd_polarity_s:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  demod_sd_dn_sel:4;
        RBus_UInt32  demod_sd_input_sel:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  demod_sd_polarity:1;
        RBus_UInt32  res4:11;
    };
}demod_sd_sigma_delta_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  demod_sd_fix_s:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  demod_sd_fix_val_s:12;
        RBus_UInt32  demod_sd_fix:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  demod_sd_fix_val:12;
    };
}demod_sd_sigma_delta_fix_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  demod_sd_input_s:12;
        RBus_UInt32  demod_sd_input:12;
        RBus_UInt32  res1:8;
    };
}demod_sd_sigma_delta_input_RBUS;




#endif 


#endif 
