/**
* @file MacArthur5-DesignSpec-I-Domain_dfilter
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DFILTER_REG_H_
#define _RBUS_DFILTER_REG_H_

#include "rbus_types.h"



//  DFILTER Register Address
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING                                       0x18023500
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_reg_addr                              "0xB8023500"
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_reg                                   0xB8023500
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_inst_addr                             "0x0000"
#define  set_DFILTER_ICH1_DFILTER_PH_SMR_PRING_reg(data)                         (*((volatile unsigned int*)DFILTER_ICH1_DFILTER_PH_SMR_PRING_reg)=data)
#define  get_DFILTER_ICH1_DFILTER_PH_SMR_PRING_reg                               (*((volatile unsigned int*)DFILTER_ICH1_DFILTER_PH_SMR_PRING_reg))
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_pring_div_shift                   (28)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_thd_pring_shift                   (25)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_pring_en_shift                    (24)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_nsmr_div_shift                    (20)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_thd_nsmr_shift                    (17)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_nsmr_en_shift                     (16)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_psmr_div_shift                    (12)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_thd_psmr_shift                    (9)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_psmr_en_shift                     (8)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_ph_div_shift                      (4)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_thd_ph_shift                      (1)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_ph_en_shift                       (0)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_pring_div_mask                    (0x30000000)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_thd_pring_mask                    (0x0E000000)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_pring_en_mask                     (0x01000000)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_nsmr_div_mask                     (0x00300000)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_thd_nsmr_mask                     (0x000E0000)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_nsmr_en_mask                      (0x00010000)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_psmr_div_mask                     (0x00003000)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_thd_psmr_mask                     (0x00000E00)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_psmr_en_mask                      (0x00000100)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_ph_div_mask                       (0x00000030)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_thd_ph_mask                       (0x0000000E)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_ph_en_mask                        (0x00000001)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_pring_div(data)                   (0x30000000&((data)<<28))
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_thd_pring(data)                   (0x0E000000&((data)<<25))
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_pring_en(data)                    (0x01000000&((data)<<24))
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_nsmr_div(data)                    (0x00300000&((data)<<20))
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_thd_nsmr(data)                    (0x000E0000&((data)<<17))
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_nsmr_en(data)                     (0x00010000&((data)<<16))
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_psmr_div(data)                    (0x00003000&((data)<<12))
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_thd_psmr(data)                    (0x00000E00&((data)<<9))
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_psmr_en(data)                     (0x00000100&((data)<<8))
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_ph_div(data)                      (0x00000030&((data)<<4))
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_thd_ph(data)                      (0x0000000E&((data)<<1))
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_ch1_ph_en(data)                       (0x00000001&(data))
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_get_ch1_pring_div(data)               ((0x30000000&(data))>>28)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_get_ch1_thd_pring(data)               ((0x0E000000&(data))>>25)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_get_ch1_pring_en(data)                ((0x01000000&(data))>>24)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_get_ch1_nsmr_div(data)                ((0x00300000&(data))>>20)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_get_ch1_thd_nsmr(data)                ((0x000E0000&(data))>>17)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_get_ch1_nsmr_en(data)                 ((0x00010000&(data))>>16)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_get_ch1_psmr_div(data)                ((0x00003000&(data))>>12)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_get_ch1_thd_psmr(data)                ((0x00000E00&(data))>>9)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_get_ch1_psmr_en(data)                 ((0x00000100&(data))>>8)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_get_ch1_ph_div(data)                  ((0x00000030&(data))>>4)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_get_ch1_thd_ph(data)                  ((0x0000000E&(data))>>1)
#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_get_ch1_ph_en(data)                   (0x00000001&(data))

#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR                                0x18023504
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_reg_addr                       "0xB8023504"
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_reg                            0xB8023504
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_inst_addr                      "0x0001"
#define  set_DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_reg(data)                  (*((volatile unsigned int*)DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_reg)=data)
#define  get_DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_reg                        (*((volatile unsigned int*)DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_reg))
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_fight_sel_shift            (21)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_nos_sel_shift              (20)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_pr_en_shift                (18)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_pb_en_shift                (17)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_y_en_shift                 (16)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_thd_nos_shift              (13)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_nos_en_shift               (12)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_thd_mis_shift              (9)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_mis_en_shift               (8)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_nring_div_shift            (4)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_thd_nring_shift            (1)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_nring_en_shift             (0)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_fight_sel_mask             (0x00600000)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_nos_sel_mask               (0x00100000)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_pr_en_mask                 (0x00040000)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_pb_en_mask                 (0x00020000)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_y_en_mask                  (0x00010000)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_thd_nos_mask               (0x0000E000)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_nos_en_mask                (0x00001000)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_thd_mis_mask               (0x00000200)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_mis_en_mask                (0x00000100)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_nring_div_mask             (0x00000030)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_thd_nring_mask             (0x0000000E)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_nring_en_mask              (0x00000001)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_fight_sel(data)            (0x00600000&((data)<<21))
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_nos_sel(data)              (0x00100000&((data)<<20))
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_pr_en(data)                (0x00040000&((data)<<18))
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_pb_en(data)                (0x00020000&((data)<<17))
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_y_en(data)                 (0x00010000&((data)<<16))
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_thd_nos(data)              (0x0000E000&((data)<<13))
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_nos_en(data)               (0x00001000&((data)<<12))
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_thd_mis(data)              (0x00000200&((data)<<9))
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_mis_en(data)               (0x00000100&((data)<<8))
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_nring_div(data)            (0x00000030&((data)<<4))
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_thd_nring(data)            (0x0000000E&((data)<<1))
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_ch1_nring_en(data)             (0x00000001&(data))
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_get_ch1_fight_sel(data)        ((0x00600000&(data))>>21)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_get_ch1_nos_sel(data)          ((0x00100000&(data))>>20)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_get_ch1_pr_en(data)            ((0x00040000&(data))>>18)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_get_ch1_pb_en(data)            ((0x00020000&(data))>>17)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_get_ch1_y_en(data)             ((0x00010000&(data))>>16)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_get_ch1_thd_nos(data)          ((0x0000E000&(data))>>13)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_get_ch1_nos_en(data)           ((0x00001000&(data))>>12)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_get_ch1_thd_mis(data)          ((0x00000200&(data))>>9)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_get_ch1_mis_en(data)           ((0x00000100&(data))>>8)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_get_ch1_nring_div(data)        ((0x00000030&(data))>>4)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_get_ch1_thd_nring(data)        ((0x0000000E&(data))>>1)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_get_ch1_nring_en(data)         (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DFILTER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_pring_div:2;
        RBus_UInt32  ch1_thd_pring:3;
        RBus_UInt32  ch1_pring_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch1_nsmr_div:2;
        RBus_UInt32  ch1_thd_nsmr:3;
        RBus_UInt32  ch1_nsmr_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch1_psmr_div:2;
        RBus_UInt32  ch1_thd_psmr:3;
        RBus_UInt32  ch1_psmr_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch1_ph_div:2;
        RBus_UInt32  ch1_thd_ph:3;
        RBus_UInt32  ch1_ph_en:1;
    };
}dfilter_ich1_dfilter_ph_smr_pring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  ch1_fight_sel:2;
        RBus_UInt32  ch1_nos_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch1_pr_en:1;
        RBus_UInt32  ch1_pb_en:1;
        RBus_UInt32  ch1_y_en:1;
        RBus_UInt32  ch1_thd_nos:3;
        RBus_UInt32  ch1_nos_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch1_thd_mis:1;
        RBus_UInt32  ch1_mis_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch1_nring_div:2;
        RBus_UInt32  ch1_thd_nring:3;
        RBus_UInt32  ch1_nring_en:1;
    };
}dfilter_ich1_dfilter_nring_mis_nos_ypbpr_RBUS;

#else //apply LITTLE_ENDIAN

//======DFILTER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_ph_en:1;
        RBus_UInt32  ch1_thd_ph:3;
        RBus_UInt32  ch1_ph_div:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_psmr_en:1;
        RBus_UInt32  ch1_thd_psmr:3;
        RBus_UInt32  ch1_psmr_div:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch1_nsmr_en:1;
        RBus_UInt32  ch1_thd_nsmr:3;
        RBus_UInt32  ch1_nsmr_div:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch1_pring_en:1;
        RBus_UInt32  ch1_thd_pring:3;
        RBus_UInt32  ch1_pring_div:2;
        RBus_UInt32  res4:2;
    };
}dfilter_ich1_dfilter_ph_smr_pring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_nring_en:1;
        RBus_UInt32  ch1_thd_nring:3;
        RBus_UInt32  ch1_nring_div:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_mis_en:1;
        RBus_UInt32  ch1_thd_mis:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch1_nos_en:1;
        RBus_UInt32  ch1_thd_nos:3;
        RBus_UInt32  ch1_y_en:1;
        RBus_UInt32  ch1_pb_en:1;
        RBus_UInt32  ch1_pr_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  ch1_nos_sel:1;
        RBus_UInt32  ch1_fight_sel:2;
        RBus_UInt32  res4:9;
    };
}dfilter_ich1_dfilter_nring_mis_nos_ypbpr_RBUS;




#endif 


#endif 
