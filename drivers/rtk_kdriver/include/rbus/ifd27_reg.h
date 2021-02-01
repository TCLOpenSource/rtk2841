/**
* @file Mac5_DesignSpec_IFDemod_27M
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IFD27_REG_H_
#define _RBUS_IFD27_REG_H_

#include "rbus_types.h"



//  IFD27 Register Address
#define  IFD27_modulation_level                                                  0x18032420
#define  IFD27_modulation_level_reg_addr                                         "0xB8032420"
#define  IFD27_modulation_level_reg                                              0xB8032420
#define  IFD27_modulation_level_inst_addr                                        "0x0000"
#define  set_IFD27_modulation_level_reg(data)                                    (*((volatile unsigned int*)IFD27_modulation_level_reg)=data)
#define  get_IFD27_modulation_level_reg                                          (*((volatile unsigned int*)IFD27_modulation_level_reg))
#define  IFD27_modulation_level_positive_level_shift                             (16)
#define  IFD27_modulation_level_negative_level_shift                             (0)
#define  IFD27_modulation_level_positive_level_mask                              (0x1FFF0000)
#define  IFD27_modulation_level_negative_level_mask                              (0x00001FFF)
#define  IFD27_modulation_level_positive_level(data)                             (0x1FFF0000&((data)<<16))
#define  IFD27_modulation_level_negative_level(data)                             (0x00001FFF&(data))
#define  IFD27_modulation_level_get_positive_level(data)                         ((0x1FFF0000&(data))>>16)
#define  IFD27_modulation_level_get_negative_level(data)                         (0x00001FFF&(data))

#define  IFD27_vclamp_in_max_sat                                                 0x18032424
#define  IFD27_vclamp_in_max_sat_reg_addr                                        "0xB8032424"
#define  IFD27_vclamp_in_max_sat_reg                                             0xB8032424
#define  IFD27_vclamp_in_max_sat_inst_addr                                       "0x0001"
#define  set_IFD27_vclamp_in_max_sat_reg(data)                                   (*((volatile unsigned int*)IFD27_vclamp_in_max_sat_reg)=data)
#define  get_IFD27_vclamp_in_max_sat_reg                                         (*((volatile unsigned int*)IFD27_vclamp_in_max_sat_reg))
#define  IFD27_vclamp_in_max_sat_vclamp_in_max_sat_shift                         (0)
#define  IFD27_vclamp_in_max_sat_vclamp_in_max_sat_mask                          (0x00001FFF)
#define  IFD27_vclamp_in_max_sat_vclamp_in_max_sat(data)                         (0x00001FFF&(data))
#define  IFD27_vclamp_in_max_sat_get_vclamp_in_max_sat(data)                     (0x00001FFF&(data))

#define  IFD27_vclamp_in_min_sat                                                 0x18032428
#define  IFD27_vclamp_in_min_sat_reg_addr                                        "0xB8032428"
#define  IFD27_vclamp_in_min_sat_reg                                             0xB8032428
#define  IFD27_vclamp_in_min_sat_inst_addr                                       "0x0002"
#define  set_IFD27_vclamp_in_min_sat_reg(data)                                   (*((volatile unsigned int*)IFD27_vclamp_in_min_sat_reg)=data)
#define  get_IFD27_vclamp_in_min_sat_reg                                         (*((volatile unsigned int*)IFD27_vclamp_in_min_sat_reg))
#define  IFD27_vclamp_in_min_sat_vclamp_in_min_sat_shift                         (0)
#define  IFD27_vclamp_in_min_sat_vclamp_in_min_sat_mask                          (0x00001FFF)
#define  IFD27_vclamp_in_min_sat_vclamp_in_min_sat(data)                         (0x00001FFF&(data))
#define  IFD27_vclamp_in_min_sat_get_vclamp_in_min_sat(data)                     (0x00001FFF&(data))

#define  IFD27_interrupt_mask_en_twenty_seven                                    0x1803242C
#define  IFD27_interrupt_mask_en_twenty_seven_reg_addr                           "0xB803242C"
#define  IFD27_interrupt_mask_en_twenty_seven_reg                                0xB803242C
#define  IFD27_interrupt_mask_en_twenty_seven_inst_addr                          "0x0003"
#define  set_IFD27_interrupt_mask_en_twenty_seven_reg(data)                      (*((volatile unsigned int*)IFD27_interrupt_mask_en_twenty_seven_reg)=data)
#define  get_IFD27_interrupt_mask_en_twenty_seven_reg                            (*((volatile unsigned int*)IFD27_interrupt_mask_en_twenty_seven_reg))
#define  IFD27_interrupt_mask_en_twenty_seven_vclamp_in_sat_int_shift            (4)
#define  IFD27_interrupt_mask_en_twenty_seven_mask_vclamp_in_sat_en_shift        (0)
#define  IFD27_interrupt_mask_en_twenty_seven_vclamp_in_sat_int_mask             (0x00000010)
#define  IFD27_interrupt_mask_en_twenty_seven_mask_vclamp_in_sat_en_mask         (0x00000001)
#define  IFD27_interrupt_mask_en_twenty_seven_vclamp_in_sat_int(data)            (0x00000010&((data)<<4))
#define  IFD27_interrupt_mask_en_twenty_seven_mask_vclamp_in_sat_en(data)        (0x00000001&(data))
#define  IFD27_interrupt_mask_en_twenty_seven_get_vclamp_in_sat_int(data)        ((0x00000010&(data))>>4)
#define  IFD27_interrupt_mask_en_twenty_seven_get_mask_vclamp_in_sat_en(data)    (0x00000001&(data))

#define  IFD27_simple_h_cntl                                                     0x18032430
#define  IFD27_simple_h_cntl_reg_addr                                            "0xB8032430"
#define  IFD27_simple_h_cntl_reg                                                 0xB8032430
#define  IFD27_simple_h_cntl_inst_addr                                           "0x0004"
#define  set_IFD27_simple_h_cntl_reg(data)                                       (*((volatile unsigned int*)IFD27_simple_h_cntl_reg)=data)
#define  get_IFD27_simple_h_cntl_reg                                             (*((volatile unsigned int*)IFD27_simple_h_cntl_reg))
#define  IFD27_simple_h_cntl_simple_h_deb_shift                                  (16)
#define  IFD27_simple_h_cntl_simple_h_thd_shift                                  (0)
#define  IFD27_simple_h_cntl_simple_h_deb_mask                                   (0x001F0000)
#define  IFD27_simple_h_cntl_simple_h_thd_mask                                   (0x00001FFF)
#define  IFD27_simple_h_cntl_simple_h_deb(data)                                  (0x001F0000&((data)<<16))
#define  IFD27_simple_h_cntl_simple_h_thd(data)                                  (0x00001FFF&(data))
#define  IFD27_simple_h_cntl_get_simple_h_deb(data)                              ((0x001F0000&(data))>>16)
#define  IFD27_simple_h_cntl_get_simple_h_thd(data)                              (0x00001FFF&(data))

#define  IFD27_simple_h_status                                                   0x18032434
#define  IFD27_simple_h_status_reg_addr                                          "0xB8032434"
#define  IFD27_simple_h_status_reg                                               0xB8032434
#define  IFD27_simple_h_status_inst_addr                                         "0x0005"
#define  set_IFD27_simple_h_status_reg(data)                                     (*((volatile unsigned int*)IFD27_simple_h_status_reg)=data)
#define  get_IFD27_simple_h_status_reg                                           (*((volatile unsigned int*)IFD27_simple_h_status_reg))
#define  IFD27_simple_h_status_simple_h_len_iir_shift                            (12)
#define  IFD27_simple_h_status_simple_h_len_shift                                (0)
#define  IFD27_simple_h_status_simple_h_len_iir_mask                             (0x007FF000)
#define  IFD27_simple_h_status_simple_h_len_mask                                 (0x000007FF)
#define  IFD27_simple_h_status_simple_h_len_iir(data)                            (0x007FF000&((data)<<12))
#define  IFD27_simple_h_status_simple_h_len(data)                                (0x000007FF&(data))
#define  IFD27_simple_h_status_get_simple_h_len_iir(data)                        ((0x007FF000&(data))>>12)
#define  IFD27_simple_h_status_get_simple_h_len(data)                            (0x000007FF&(data))

#define  IFD27_FIFO_CRC27_result                                                 0x18032440
#define  IFD27_FIFO_CRC27_result_reg_addr                                        "0xB8032440"
#define  IFD27_FIFO_CRC27_result_reg                                             0xB8032440
#define  IFD27_FIFO_CRC27_result_inst_addr                                       "0x0006"
#define  set_IFD27_FIFO_CRC27_result_reg(data)                                   (*((volatile unsigned int*)IFD27_FIFO_CRC27_result_reg)=data)
#define  get_IFD27_FIFO_CRC27_result_reg                                         (*((volatile unsigned int*)IFD27_FIFO_CRC27_result_reg))
#define  IFD27_FIFO_CRC27_result_fifo_crc27_result_shift                         (0)
#define  IFD27_FIFO_CRC27_result_fifo_crc27_result_mask                          (0x0000FFFF)
#define  IFD27_FIFO_CRC27_result_fifo_crc27_result(data)                         (0x0000FFFF&(data))
#define  IFD27_FIFO_CRC27_result_get_fifo_crc27_result(data)                     (0x0000FFFF&(data))

#define  IFD27_dma_data_sel                                                      0x1803244C
#define  IFD27_dma_data_sel_reg_addr                                             "0xB803244C"
#define  IFD27_dma_data_sel_reg                                                  0xB803244C
#define  IFD27_dma_data_sel_inst_addr                                            "0x0007"
#define  set_IFD27_dma_data_sel_reg(data)                                        (*((volatile unsigned int*)IFD27_dma_data_sel_reg)=data)
#define  get_IFD27_dma_data_sel_reg                                              (*((volatile unsigned int*)IFD27_dma_data_sel_reg))
#define  IFD27_dma_data_sel_dma_data_sel_shift                                   (8)
#define  IFD27_dma_data_sel_dma_data_sel_mask                                    (0x00000300)
#define  IFD27_dma_data_sel_dma_data_sel(data)                                   (0x00000300&((data)<<8))
#define  IFD27_dma_data_sel_get_dma_data_sel(data)                               ((0x00000300&(data))>>8)

#define  IFD27_mod_sel                                                           0x18032480
#define  IFD27_mod_sel_reg_addr                                                  "0xB8032480"
#define  IFD27_mod_sel_reg                                                       0xB8032480
#define  IFD27_mod_sel_inst_addr                                                 "0x0008"
#define  set_IFD27_mod_sel_reg(data)                                             (*((volatile unsigned int*)IFD27_mod_sel_reg)=data)
#define  get_IFD27_mod_sel_reg                                                   (*((volatile unsigned int*)IFD27_mod_sel_reg))
#define  IFD27_mod_sel_mod_sel_shift                                             (16)
#define  IFD27_mod_sel_mod_sel_mask                                              (0x00010000)
#define  IFD27_mod_sel_mod_sel(data)                                             (0x00010000&((data)<<16))
#define  IFD27_mod_sel_get_mod_sel(data)                                         ((0x00010000&(data))>>16)

#define  IFD27_clamping_scale                                                    0x1803248C
#define  IFD27_clamping_scale_reg_addr                                           "0xB803248C"
#define  IFD27_clamping_scale_reg                                                0xB803248C
#define  IFD27_clamping_scale_inst_addr                                          "0x0009"
#define  set_IFD27_clamping_scale_reg(data)                                      (*((volatile unsigned int*)IFD27_clamping_scale_reg)=data)
#define  get_IFD27_clamping_scale_reg                                            (*((volatile unsigned int*)IFD27_clamping_scale_reg))
#define  IFD27_clamping_scale_clamp_offset_hold_shift                            (8)
#define  IFD27_clamping_scale_clamping_reset_shift                               (4)
#define  IFD27_clamping_scale_clamping_scale_shift                               (0)
#define  IFD27_clamping_scale_clamp_offset_hold_mask                             (0x00000100)
#define  IFD27_clamping_scale_clamping_reset_mask                                (0x00000010)
#define  IFD27_clamping_scale_clamping_scale_mask                                (0x0000000F)
#define  IFD27_clamping_scale_clamp_offset_hold(data)                            (0x00000100&((data)<<8))
#define  IFD27_clamping_scale_clamping_reset(data)                               (0x00000010&((data)<<4))
#define  IFD27_clamping_scale_clamping_scale(data)                               (0x0000000F&(data))
#define  IFD27_clamping_scale_get_clamp_offset_hold(data)                        ((0x00000100&(data))>>8)
#define  IFD27_clamping_scale_get_clamping_reset(data)                           ((0x00000010&(data))>>4)
#define  IFD27_clamping_scale_get_clamping_scale(data)                           (0x0000000F&(data))

#define  IFD27_clamping_thr_max                                                  0x18032490
#define  IFD27_clamping_thr_max_reg_addr                                         "0xB8032490"
#define  IFD27_clamping_thr_max_reg                                              0xB8032490
#define  IFD27_clamping_thr_max_inst_addr                                        "0x000A"
#define  set_IFD27_clamping_thr_max_reg(data)                                    (*((volatile unsigned int*)IFD27_clamping_thr_max_reg)=data)
#define  get_IFD27_clamping_thr_max_reg                                          (*((volatile unsigned int*)IFD27_clamping_thr_max_reg))
#define  IFD27_clamping_thr_max_clamping_thr_max_shift                           (0)
#define  IFD27_clamping_thr_max_clamping_thr_max_mask                            (0x00003FFF)
#define  IFD27_clamping_thr_max_clamping_thr_max(data)                           (0x00003FFF&(data))
#define  IFD27_clamping_thr_max_get_clamping_thr_max(data)                       (0x00003FFF&(data))

#define  IFD27_clamping_thr_min                                                  0x18032494
#define  IFD27_clamping_thr_min_reg_addr                                         "0xB8032494"
#define  IFD27_clamping_thr_min_reg                                              0xB8032494
#define  IFD27_clamping_thr_min_inst_addr                                        "0x000B"
#define  set_IFD27_clamping_thr_min_reg(data)                                    (*((volatile unsigned int*)IFD27_clamping_thr_min_reg)=data)
#define  get_IFD27_clamping_thr_min_reg                                          (*((volatile unsigned int*)IFD27_clamping_thr_min_reg))
#define  IFD27_clamping_thr_min_clamping_thr_min_auto_shift                      (16)
#define  IFD27_clamping_thr_min_clamping_thr_min_shift                           (0)
#define  IFD27_clamping_thr_min_clamping_thr_min_auto_mask                       (0x3FFF0000)
#define  IFD27_clamping_thr_min_clamping_thr_min_mask                            (0x00003FFF)
#define  IFD27_clamping_thr_min_clamping_thr_min_auto(data)                      (0x3FFF0000&((data)<<16))
#define  IFD27_clamping_thr_min_clamping_thr_min(data)                           (0x00003FFF&(data))
#define  IFD27_clamping_thr_min_get_clamping_thr_min_auto(data)                  ((0x3FFF0000&(data))>>16)
#define  IFD27_clamping_thr_min_get_clamping_thr_min(data)                       (0x00003FFF&(data))

#define  IFD27_offset                                                            0x18032498
#define  IFD27_offset_reg_addr                                                   "0xB8032498"
#define  IFD27_offset_reg                                                        0xB8032498
#define  IFD27_offset_inst_addr                                                  "0x000C"
#define  set_IFD27_offset_reg(data)                                              (*((volatile unsigned int*)IFD27_offset_reg)=data)
#define  get_IFD27_offset_reg                                                    (*((volatile unsigned int*)IFD27_offset_reg))
#define  IFD27_offset_offset_status_shift                                        (0)
#define  IFD27_offset_offset_status_mask                                         (0x00003FFF)
#define  IFD27_offset_offset_status(data)                                        (0x00003FFF&(data))
#define  IFD27_offset_get_offset_status(data)                                    (0x00003FFF&(data))

#define  IFD27_clamping_thr_min_limit                                            0x1803249C
#define  IFD27_clamping_thr_min_limit_reg_addr                                   "0xB803249C"
#define  IFD27_clamping_thr_min_limit_reg                                        0xB803249C
#define  IFD27_clamping_thr_min_limit_inst_addr                                  "0x000D"
#define  set_IFD27_clamping_thr_min_limit_reg(data)                              (*((volatile unsigned int*)IFD27_clamping_thr_min_limit_reg)=data)
#define  get_IFD27_clamping_thr_min_limit_reg                                    (*((volatile unsigned int*)IFD27_clamping_thr_min_limit_reg))
#define  IFD27_clamping_thr_min_limit_clamp_offset_min_limit_gap_shift           (8)
#define  IFD27_clamping_thr_min_limit_clamp_offset_min_limit_cnt_shift           (4)
#define  IFD27_clamping_thr_min_limit_clamp_offset_min_limit_en_shift            (0)
#define  IFD27_clamping_thr_min_limit_clamp_offset_min_limit_gap_mask            (0x003FFF00)
#define  IFD27_clamping_thr_min_limit_clamp_offset_min_limit_cnt_mask            (0x000000F0)
#define  IFD27_clamping_thr_min_limit_clamp_offset_min_limit_en_mask             (0x00000001)
#define  IFD27_clamping_thr_min_limit_clamp_offset_min_limit_gap(data)           (0x003FFF00&((data)<<8))
#define  IFD27_clamping_thr_min_limit_clamp_offset_min_limit_cnt(data)           (0x000000F0&((data)<<4))
#define  IFD27_clamping_thr_min_limit_clamp_offset_min_limit_en(data)            (0x00000001&(data))
#define  IFD27_clamping_thr_min_limit_get_clamp_offset_min_limit_gap(data)       ((0x003FFF00&(data))>>8)
#define  IFD27_clamping_thr_min_limit_get_clamp_offset_min_limit_cnt(data)       ((0x000000F0&(data))>>4)
#define  IFD27_clamping_thr_min_limit_get_clamp_offset_min_limit_en(data)        (0x00000001&(data))

#define  IFD27_wrong_pc                                                          0x180324A0
#define  IFD27_wrong_pc_reg_addr                                                 "0xB80324A0"
#define  IFD27_wrong_pc_reg                                                      0xB80324A0
#define  IFD27_wrong_pc_inst_addr                                                "0x000E"
#define  set_IFD27_wrong_pc_reg(data)                                            (*((volatile unsigned int*)IFD27_wrong_pc_reg)=data)
#define  get_IFD27_wrong_pc_reg                                                  (*((volatile unsigned int*)IFD27_wrong_pc_reg))
#define  IFD27_wrong_pc_wrong_pc_th_shift                                        (20)
#define  IFD27_wrong_pc_wrong_pc_under_th_shift                                  (4)
#define  IFD27_wrong_pc_wrong_if_pc_detect_shift                                 (0)
#define  IFD27_wrong_pc_wrong_pc_th_mask                                         (0x0FF00000)
#define  IFD27_wrong_pc_wrong_pc_under_th_mask                                   (0x0001FFF0)
#define  IFD27_wrong_pc_wrong_if_pc_detect_mask                                  (0x00000001)
#define  IFD27_wrong_pc_wrong_pc_th(data)                                        (0x0FF00000&((data)<<20))
#define  IFD27_wrong_pc_wrong_pc_under_th(data)                                  (0x0001FFF0&((data)<<4))
#define  IFD27_wrong_pc_wrong_if_pc_detect(data)                                 (0x00000001&(data))
#define  IFD27_wrong_pc_get_wrong_pc_th(data)                                    ((0x0FF00000&(data))>>20)
#define  IFD27_wrong_pc_get_wrong_pc_under_th(data)                              ((0x0001FFF0&(data))>>4)
#define  IFD27_wrong_pc_get_wrong_if_pc_detect(data)                             (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IFD27 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  positive_level:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  negative_level:13;
    };
}ifd27_modulation_level_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  vclamp_in_max_sat:13;
    };
}ifd27_vclamp_in_max_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  vclamp_in_min_sat:13;
    };
}ifd27_vclamp_in_min_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  vclamp_in_sat_int:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mask_vclamp_in_sat_en:1;
    };
}ifd27_interrupt_mask_en_twenty_seven_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  simple_h_deb:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  simple_h_thd:13;
    };
}ifd27_simple_h_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  simple_h_len_iir:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  simple_h_len:11;
    };
}ifd27_simple_h_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fifo_crc27_result:16;
    };
}ifd27_fifo_crc27_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  dma_data_sel:2;
        RBus_UInt32  res2:8;
    };
}ifd27_dma_data_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mod_sel:1;
        RBus_UInt32  res2:16;
    };
}ifd27_mod_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  clamp_offset_hold:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  clamping_reset:1;
        RBus_UInt32  clamping_scale:4;
    };
}ifd27_clamping_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  clamping_thr_max:14;
    };
}ifd27_clamping_thr_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  clamping_thr_min_auto:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  clamping_thr_min:14;
    };
}ifd27_clamping_thr_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  offset_status:14;
    };
}ifd27_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  clamp_offset_min_limit_gap:14;
        RBus_UInt32  clamp_offset_min_limit_cnt:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  clamp_offset_min_limit_en:1;
    };
}ifd27_clamping_thr_min_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  wrong_pc_th:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  wrong_pc_under_th:13;
        RBus_UInt32  res3:3;
        RBus_UInt32  wrong_if_pc_detect:1;
    };
}ifd27_wrong_pc_RBUS;

#else //apply LITTLE_ENDIAN

//======IFD27 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  negative_level:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  positive_level:13;
        RBus_UInt32  res2:3;
    };
}ifd27_modulation_level_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vclamp_in_max_sat:13;
        RBus_UInt32  res1:19;
    };
}ifd27_vclamp_in_max_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vclamp_in_min_sat:13;
        RBus_UInt32  res1:19;
    };
}ifd27_vclamp_in_min_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_vclamp_in_sat_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  vclamp_in_sat_int:1;
        RBus_UInt32  res2:27;
    };
}ifd27_interrupt_mask_en_twenty_seven_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  simple_h_thd:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  simple_h_deb:5;
        RBus_UInt32  res2:11;
    };
}ifd27_simple_h_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  simple_h_len:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  simple_h_len_iir:11;
        RBus_UInt32  res2:9;
    };
}ifd27_simple_h_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_crc27_result:16;
        RBus_UInt32  res1:16;
    };
}ifd27_fifo_crc27_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  dma_data_sel:2;
        RBus_UInt32  res2:22;
    };
}ifd27_dma_data_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  mod_sel:1;
        RBus_UInt32  res2:15;
    };
}ifd27_mod_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clamping_scale:4;
        RBus_UInt32  clamping_reset:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  clamp_offset_hold:1;
        RBus_UInt32  res2:23;
    };
}ifd27_clamping_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clamping_thr_max:14;
        RBus_UInt32  res1:18;
    };
}ifd27_clamping_thr_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clamping_thr_min:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  clamping_thr_min_auto:14;
        RBus_UInt32  res2:2;
    };
}ifd27_clamping_thr_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  offset_status:14;
        RBus_UInt32  res1:18;
    };
}ifd27_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clamp_offset_min_limit_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  clamp_offset_min_limit_cnt:4;
        RBus_UInt32  clamp_offset_min_limit_gap:14;
        RBus_UInt32  res2:10;
    };
}ifd27_clamping_thr_min_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrong_if_pc_detect:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  wrong_pc_under_th:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  wrong_pc_th:8;
        RBus_UInt32  res3:4;
    };
}ifd27_wrong_pc_RBUS;




#endif 


#endif 
