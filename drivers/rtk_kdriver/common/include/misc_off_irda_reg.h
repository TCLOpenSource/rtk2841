/**
* @file rbusMISC_OFF_IRDAReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MISC_OFF_IRDA_REG_H_
#define _RBUS_MISC_OFF_IRDA_REG_H_

#include "rbus_types.h"



//  MISC_OFF_IRDA Register Address
#define  MISC_OFF_IRDA_IR_SF                                                     0x18062408
#define  MISC_OFF_IRDA_IR_SF_reg_addr                                            "0xB8062408"
#define  MISC_OFF_IRDA_IR_SF_reg                                                 0xB8062408
#define  MISC_OFF_IRDA_IR_SF_inst_addr                                           "0x0000"
#define  set_MISC_OFF_IRDA_IR_SF_reg(data)                                       (*((volatile unsigned int*)MISC_OFF_IRDA_IR_SF_reg)=data)
#define  get_MISC_OFF_IRDA_IR_SF_reg                                             (*((volatile unsigned int*)MISC_OFF_IRDA_IR_SF_reg))
#define  MISC_OFF_IRDA_IR_SF_irfd_shift                                          (0)
#define  MISC_OFF_IRDA_IR_SF_irfd_mask                                           (0x0000FFFF)
#define  MISC_OFF_IRDA_IR_SF_irfd(data)                                          (0x0000FFFF&(data))
#define  MISC_OFF_IRDA_IR_SF_get_irfd(data)                                      (0x0000FFFF&(data))

#define  MISC_OFF_IRDA_IR_CR                                                     0x18062410
#define  MISC_OFF_IRDA_IR_CR_reg_addr                                            "0xB8062410"
#define  MISC_OFF_IRDA_IR_CR_reg                                                 0xB8062410
#define  MISC_OFF_IRDA_IR_CR_inst_addr                                           "0x0001"
#define  set_MISC_OFF_IRDA_IR_CR_reg(data)                                       (*((volatile unsigned int*)MISC_OFF_IRDA_IR_CR_reg)=data)
#define  get_MISC_OFF_IRDA_IR_CR_reg                                             (*((volatile unsigned int*)MISC_OFF_IRDA_IR_CR_reg))
#define  MISC_OFF_IRDA_IR_CR_raw_fifo_ov_en_shift                                (14)
#define  MISC_OFF_IRDA_IR_CR_raw_fifo_val_en_shift                               (13)
#define  MISC_OFF_IRDA_IR_CR_raw_en_shift                                        (12)
#define  MISC_OFF_IRDA_IR_CR_raw_fifo_ov_en_mask                                 (0x00004000)
#define  MISC_OFF_IRDA_IR_CR_raw_fifo_val_en_mask                                (0x00002000)
#define  MISC_OFF_IRDA_IR_CR_raw_en_mask                                         (0x00001000)
#define  MISC_OFF_IRDA_IR_CR_raw_fifo_ov_en(data)                                (0x00004000&((data)<<14))
#define  MISC_OFF_IRDA_IR_CR_raw_fifo_val_en(data)                               (0x00002000&((data)<<13))
#define  MISC_OFF_IRDA_IR_CR_raw_en(data)                                        (0x00001000&((data)<<12))
#define  MISC_OFF_IRDA_IR_CR_get_raw_fifo_ov_en(data)                            ((0x00004000&(data))>>14)
#define  MISC_OFF_IRDA_IR_CR_get_raw_fifo_val_en(data)                           ((0x00002000&(data))>>13)
#define  MISC_OFF_IRDA_IR_CR_get_raw_en(data)                                    ((0x00001000&(data))>>12)

#define  MISC_OFF_IRDA_IR_SR                                                     0x18062418
#define  MISC_OFF_IRDA_IR_SR_reg_addr                                            "0xB8062418"
#define  MISC_OFF_IRDA_IR_SR_reg                                                 0xB8062418
#define  MISC_OFF_IRDA_IR_SR_inst_addr                                           "0x0002"
#define  set_MISC_OFF_IRDA_IR_SR_reg(data)                                       (*((volatile unsigned int*)MISC_OFF_IRDA_IR_SR_reg)=data)
#define  get_MISC_OFF_IRDA_IR_SR_reg                                             (*((volatile unsigned int*)MISC_OFF_IRDA_IR_SR_reg))
#define  MISC_OFF_IRDA_IR_SR_raw_fifo_ov_shift                                   (3)
#define  MISC_OFF_IRDA_IR_SR_raw_fifo_val_shift                                  (2)
#define  MISC_OFF_IRDA_IR_SR_raw_fifo_ov_mask                                    (0x00000008)
#define  MISC_OFF_IRDA_IR_SR_raw_fifo_val_mask                                   (0x00000004)
#define  MISC_OFF_IRDA_IR_SR_raw_fifo_ov(data)                                   (0x00000008&((data)<<3))
#define  MISC_OFF_IRDA_IR_SR_raw_fifo_val(data)                                  (0x00000004&((data)<<2))
#define  MISC_OFF_IRDA_IR_SR_get_raw_fifo_ov(data)                               ((0x00000008&(data))>>3)
#define  MISC_OFF_IRDA_IR_SR_get_raw_fifo_val(data)                              ((0x00000004&(data))>>2)

#define  MISC_OFF_IRDA_IR_RAW_CTRL                                               0x1806241C
#define  MISC_OFF_IRDA_IR_RAW_CTRL_reg_addr                                      "0xB806241C"
#define  MISC_OFF_IRDA_IR_RAW_CTRL_reg                                           0xB806241C
#define  MISC_OFF_IRDA_IR_RAW_CTRL_inst_addr                                     "0x0003"
#define  set_MISC_OFF_IRDA_IR_RAW_CTRL_reg(data)                                 (*((volatile unsigned int*)MISC_OFF_IRDA_IR_RAW_CTRL_reg)=data)
#define  get_MISC_OFF_IRDA_IR_RAW_CTRL_reg                                       (*((volatile unsigned int*)MISC_OFF_IRDA_IR_RAW_CTRL_reg))
#define  MISC_OFF_IRDA_IR_RAW_CTRL_stop_sample_shift                             (24)
#define  MISC_OFF_IRDA_IR_RAW_CTRL_stop_time_shift                               (8)
#define  MISC_OFF_IRDA_IR_RAW_CTRL_fifo_thr_shift                                (0)
#define  MISC_OFF_IRDA_IR_RAW_CTRL_stop_sample_mask                              (0x01000000)
#define  MISC_OFF_IRDA_IR_RAW_CTRL_stop_time_mask                                (0x00FFFF00)
#define  MISC_OFF_IRDA_IR_RAW_CTRL_fifo_thr_mask                                 (0x000000FF)
#define  MISC_OFF_IRDA_IR_RAW_CTRL_stop_sample(data)                             (0x01000000&((data)<<24))
#define  MISC_OFF_IRDA_IR_RAW_CTRL_stop_time(data)                               (0x00FFFF00&((data)<<8))
#define  MISC_OFF_IRDA_IR_RAW_CTRL_fifo_thr(data)                                (0x000000FF&(data))
#define  MISC_OFF_IRDA_IR_RAW_CTRL_get_stop_sample(data)                         ((0x01000000&(data))>>24)
#define  MISC_OFF_IRDA_IR_RAW_CTRL_get_stop_time(data)                           ((0x00FFFF00&(data))>>8)
#define  MISC_OFF_IRDA_IR_RAW_CTRL_get_fifo_thr(data)                            (0x000000FF&(data))

#define  MISC_OFF_IRDA_IR_RAW_FF                                                 0x18062420
#define  MISC_OFF_IRDA_IR_RAW_FF_reg_addr                                        "0xB8062420"
#define  MISC_OFF_IRDA_IR_RAW_FF_reg                                             0xB8062420
#define  MISC_OFF_IRDA_IR_RAW_FF_inst_addr                                       "0x0004"
#define  set_MISC_OFF_IRDA_IR_RAW_FF_reg(data)                                   (*((volatile unsigned int*)MISC_OFF_IRDA_IR_RAW_FF_reg)=data)
#define  get_MISC_OFF_IRDA_IR_RAW_FF_reg                                         (*((volatile unsigned int*)MISC_OFF_IRDA_IR_RAW_FF_reg))
#define  MISC_OFF_IRDA_IR_RAW_FF_raw_fifo_rdata_shift                            (0)
#define  MISC_OFF_IRDA_IR_RAW_FF_raw_fifo_rdata_mask                             (0xFFFFFFFF)
#define  MISC_OFF_IRDA_IR_RAW_FF_raw_fifo_rdata(data)                            (0xFFFFFFFF&(data))
#define  MISC_OFF_IRDA_IR_RAW_FF_get_raw_fifo_rdata(data)                        (0xFFFFFFFF&(data))

#define  MISC_OFF_IRDA_IR_RAW_SAMPLE_TIME                                        0x18062424
#define  MISC_OFF_IRDA_IR_RAW_SAMPLE_TIME_reg_addr                               "0xB8062424"
#define  MISC_OFF_IRDA_IR_RAW_SAMPLE_TIME_reg                                    0xB8062424
#define  MISC_OFF_IRDA_IR_RAW_SAMPLE_TIME_inst_addr                              "0x0005"
#define  set_MISC_OFF_IRDA_IR_RAW_SAMPLE_TIME_reg(data)                          (*((volatile unsigned int*)MISC_OFF_IRDA_IR_RAW_SAMPLE_TIME_reg)=data)
#define  get_MISC_OFF_IRDA_IR_RAW_SAMPLE_TIME_reg                                (*((volatile unsigned int*)MISC_OFF_IRDA_IR_RAW_SAMPLE_TIME_reg))
#define  MISC_OFF_IRDA_IR_RAW_SAMPLE_TIME_sample_time_cnt_shift                  (0)
#define  MISC_OFF_IRDA_IR_RAW_SAMPLE_TIME_sample_time_cnt_mask                   (0x0000FFFF)
#define  MISC_OFF_IRDA_IR_RAW_SAMPLE_TIME_sample_time_cnt(data)                  (0x0000FFFF&(data))
#define  MISC_OFF_IRDA_IR_RAW_SAMPLE_TIME_get_sample_time_cnt(data)              (0x0000FFFF&(data))

#define  MISC_OFF_IRDA_IR_RAW_WL                                                 0x18062428
#define  MISC_OFF_IRDA_IR_RAW_WL_reg_addr                                        "0xB8062428"
#define  MISC_OFF_IRDA_IR_RAW_WL_reg                                             0xB8062428
#define  MISC_OFF_IRDA_IR_RAW_WL_inst_addr                                       "0x0006"
#define  set_MISC_OFF_IRDA_IR_RAW_WL_reg(data)                                   (*((volatile unsigned int*)MISC_OFF_IRDA_IR_RAW_WL_reg)=data)
#define  get_MISC_OFF_IRDA_IR_RAW_WL_reg                                         (*((volatile unsigned int*)MISC_OFF_IRDA_IR_RAW_WL_reg))
#define  MISC_OFF_IRDA_IR_RAW_WL_raw_fifo_wl_shift                               (0)
#define  MISC_OFF_IRDA_IR_RAW_WL_raw_fifo_wl_mask                                (0x000000FF)
#define  MISC_OFF_IRDA_IR_RAW_WL_raw_fifo_wl(data)                               (0x000000FF&(data))
#define  MISC_OFF_IRDA_IR_RAW_WL_get_raw_fifo_wl(data)                           (0x000000FF&(data))

#define  MISC_OFF_IRDA_IR_RAW_DEB                                                0x1806242C
#define  MISC_OFF_IRDA_IR_RAW_DEB_reg_addr                                       "0xB806242C"
#define  MISC_OFF_IRDA_IR_RAW_DEB_reg                                            0xB806242C
#define  MISC_OFF_IRDA_IR_RAW_DEB_inst_addr                                      "0x0007"
#define  set_MISC_OFF_IRDA_IR_RAW_DEB_reg(data)                                  (*((volatile unsigned int*)MISC_OFF_IRDA_IR_RAW_DEB_reg)=data)
#define  get_MISC_OFF_IRDA_IR_RAW_DEB_reg                                        (*((volatile unsigned int*)MISC_OFF_IRDA_IR_RAW_DEB_reg))
#define  MISC_OFF_IRDA_IR_RAW_DEB_irraw_deb_len_shift                            (16)
#define  MISC_OFF_IRDA_IR_RAW_DEB_irraw_deb_clk_shift                            (0)
#define  MISC_OFF_IRDA_IR_RAW_DEB_irraw_deb_len_mask                             (0x00FF0000)
#define  MISC_OFF_IRDA_IR_RAW_DEB_irraw_deb_clk_mask                             (0x0000FFFF)
#define  MISC_OFF_IRDA_IR_RAW_DEB_irraw_deb_len(data)                            (0x00FF0000&((data)<<16))
#define  MISC_OFF_IRDA_IR_RAW_DEB_irraw_deb_clk(data)                            (0x0000FFFF&(data))
#define  MISC_OFF_IRDA_IR_RAW_DEB_get_irraw_deb_len(data)                        ((0x00FF0000&(data))>>16)
#define  MISC_OFF_IRDA_IR_RAW_DEB_get_irraw_deb_clk(data)                        (0x0000FFFF&(data))

#define  MISC_OFF_IRDA_IR_RAW_SF                                                 0x18062440
#define  MISC_OFF_IRDA_IR_RAW_SF_reg_addr                                        "0xB8062440"
#define  MISC_OFF_IRDA_IR_RAW_SF_reg                                             0xB8062440
#define  MISC_OFF_IRDA_IR_RAW_SF_inst_addr                                       "0x0008"
#define  set_MISC_OFF_IRDA_IR_RAW_SF_reg(data)                                   (*((volatile unsigned int*)MISC_OFF_IRDA_IR_RAW_SF_reg)=data)
#define  get_MISC_OFF_IRDA_IR_RAW_SF_reg                                         (*((volatile unsigned int*)MISC_OFF_IRDA_IR_RAW_SF_reg))
#define  MISC_OFF_IRDA_IR_RAW_SF_irrawfd_shift                                   (0)
#define  MISC_OFF_IRDA_IR_RAW_SF_irrawfd_mask                                    (0x0000FFFF)
#define  MISC_OFF_IRDA_IR_RAW_SF_irrawfd(data)                                   (0x0000FFFF&(data))
#define  MISC_OFF_IRDA_IR_RAW_SF_get_irrawfd(data)                               (0x0000FFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MISC_OFF_IRDA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  irfd:16;
    };
}misc_off_irda_ir_sf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  raw_fifo_ov_en:1;
        RBus_UInt32  raw_fifo_val_en:1;
        RBus_UInt32  raw_en:1;
        RBus_UInt32  res2:12;
    };
}misc_off_irda_ir_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  raw_fifo_ov:1;
        RBus_UInt32  raw_fifo_val:1;
        RBus_UInt32  res2:2;
    };
}misc_off_irda_ir_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  stop_sample:1;
        RBus_UInt32  stop_time:16;
        RBus_UInt32  fifo_thr:8;
    };
}misc_off_irda_ir_raw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  raw_fifo_rdata:32;
    };
}misc_off_irda_ir_raw_ff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sample_time_cnt:16;
    };
}misc_off_irda_ir_raw_sample_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  raw_fifo_wl:8;
    };
}misc_off_irda_ir_raw_wl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  irraw_deb_len:8;
        RBus_UInt32  irraw_deb_clk:16;
    };
}misc_off_irda_ir_raw_deb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  irrawfd:16;
    };
}misc_off_irda_ir_raw_sf_RBUS;

#else //apply LITTLE_ENDIAN

//======MISC_OFF_IRDA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irfd:16;
        RBus_UInt32  res1:16;
    };
}misc_off_irda_ir_sf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  raw_en:1;
        RBus_UInt32  raw_fifo_val_en:1;
        RBus_UInt32  raw_fifo_ov_en:1;
        RBus_UInt32  res2:17;
    };
}misc_off_irda_ir_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  raw_fifo_val:1;
        RBus_UInt32  raw_fifo_ov:1;
        RBus_UInt32  res2:28;
    };
}misc_off_irda_ir_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_thr:8;
        RBus_UInt32  stop_time:16;
        RBus_UInt32  stop_sample:1;
        RBus_UInt32  res1:7;
    };
}misc_off_irda_ir_raw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  raw_fifo_rdata:32;
    };
}misc_off_irda_ir_raw_ff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sample_time_cnt:16;
        RBus_UInt32  res1:16;
    };
}misc_off_irda_ir_raw_sample_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  raw_fifo_wl:8;
        RBus_UInt32  res1:24;
    };
}misc_off_irda_ir_raw_wl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irraw_deb_clk:16;
        RBus_UInt32  irraw_deb_len:8;
        RBus_UInt32  res1:8;
    };
}misc_off_irda_ir_raw_deb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irrawfd:16;
        RBus_UInt32  res1:16;
    };
}misc_off_irda_ir_raw_sf_RBUS;




#endif 


#endif 
