/**
* @file Mac5_VE_IMGBLK_Arch_Spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IMG_REG_H_
#define _RBUS_IMG_REG_H_

#include "rbus_types.h"



//  IMG Register Address
#define  IMG_DBG_CNTL                                                            0x1800FA00
#define  IMG_DBG_CNTL_reg_addr                                                   "0xB800FA00"
#define  IMG_DBG_CNTL_reg                                                        0xB800FA00
#define  IMG_DBG_CNTL_inst_addr                                                  "0x0000"
#define  set_IMG_DBG_CNTL_reg(data)                                              (*((volatile unsigned int*)IMG_DBG_CNTL_reg)=data)
#define  get_IMG_DBG_CNTL_reg                                                    (*((volatile unsigned int*)IMG_DBG_CNTL_reg))
#define  IMG_DBG_CNTL_dering_dbg_sel_shift                                       (20)
#define  IMG_DBG_CNTL_dbg_group2_sel_shift                                       (14)
#define  IMG_DBG_CNTL_dbg_group1_sel_shift                                       (9)
#define  IMG_DBG_CNTL_dbg_out_en_shift                                           (8)
#define  IMG_DBG_CNTL_dering_dbg_sel_mask                                        (0x00700000)
#define  IMG_DBG_CNTL_dbg_group2_sel_mask                                        (0x0007C000)
#define  IMG_DBG_CNTL_dbg_group1_sel_mask                                        (0x00003E00)
#define  IMG_DBG_CNTL_dbg_out_en_mask                                            (0x00000100)
#define  IMG_DBG_CNTL_dering_dbg_sel(data)                                       (0x00700000&((data)<<20))
#define  IMG_DBG_CNTL_dbg_group2_sel(data)                                       (0x0007C000&((data)<<14))
#define  IMG_DBG_CNTL_dbg_group1_sel(data)                                       (0x00003E00&((data)<<9))
#define  IMG_DBG_CNTL_dbg_out_en(data)                                           (0x00000100&((data)<<8))
#define  IMG_DBG_CNTL_get_dering_dbg_sel(data)                                   ((0x00700000&(data))>>20)
#define  IMG_DBG_CNTL_get_dbg_group2_sel(data)                                   ((0x0007C000&(data))>>14)
#define  IMG_DBG_CNTL_get_dbg_group1_sel(data)                                   ((0x00003E00&(data))>>9)
#define  IMG_DBG_CNTL_get_dbg_out_en(data)                                       ((0x00000100&(data))>>8)

#define  IMG_DERING_CNTL                                                         0x1800FA04
#define  IMG_DERING_CNTL_reg_addr                                                "0xB800FA04"
#define  IMG_DERING_CNTL_reg                                                     0xB800FA04
#define  IMG_DERING_CNTL_inst_addr                                               "0x0001"
#define  set_IMG_DERING_CNTL_reg(data)                                           (*((volatile unsigned int*)IMG_DERING_CNTL_reg)=data)
#define  get_IMG_DERING_CNTL_reg                                                 (*((volatile unsigned int*)IMG_DERING_CNTL_reg))
#define  IMG_DERING_CNTL_chroma_enable_shift                                     (1)
#define  IMG_DERING_CNTL_luma_enable_shift                                       (0)
#define  IMG_DERING_CNTL_chroma_enable_mask                                      (0x00000002)
#define  IMG_DERING_CNTL_luma_enable_mask                                        (0x00000001)
#define  IMG_DERING_CNTL_chroma_enable(data)                                     (0x00000002&((data)<<1))
#define  IMG_DERING_CNTL_luma_enable(data)                                       (0x00000001&(data))
#define  IMG_DERING_CNTL_get_chroma_enable(data)                                 ((0x00000002&(data))>>1)
#define  IMG_DERING_CNTL_get_luma_enable(data)                                   (0x00000001&(data))

#define  IMG_FILT_CNTL                                                           0x1800FA08
#define  IMG_FILT_CNTL_reg_addr                                                  "0xB800FA08"
#define  IMG_FILT_CNTL_reg                                                       0xB800FA08
#define  IMG_FILT_CNTL_inst_addr                                                 "0x0002"
#define  set_IMG_FILT_CNTL_reg(data)                                             (*((volatile unsigned int*)IMG_FILT_CNTL_reg)=data)
#define  get_IMG_FILT_CNTL_reg                                                   (*((volatile unsigned int*)IMG_FILT_CNTL_reg))
#define  IMG_FILT_CNTL_filt_prec_shift                                           (0)
#define  IMG_FILT_CNTL_filt_prec_mask                                            (0x00000003)
#define  IMG_FILT_CNTL_filt_prec(data)                                           (0x00000003&(data))
#define  IMG_FILT_CNTL_get_filt_prec(data)                                       (0x00000003&(data))

#define  IMG_FILT_INIT                                                           0x1800FA0C
#define  IMG_FILT_INIT_reg_addr                                                  "0xB800FA0C"
#define  IMG_FILT_INIT_reg                                                       0xB800FA0C
#define  IMG_FILT_INIT_inst_addr                                                 "0x0003"
#define  set_IMG_FILT_INIT_reg(data)                                             (*((volatile unsigned int*)IMG_FILT_INIT_reg)=data)
#define  get_IMG_FILT_INIT_reg                                                   (*((volatile unsigned int*)IMG_FILT_INIT_reg))
#define  IMG_FILT_INIT_init_value_shift                                          (0)
#define  IMG_FILT_INIT_init_value_mask                                           (0x000003FF)
#define  IMG_FILT_INIT_init_value(data)                                          (0x000003FF&(data))
#define  IMG_FILT_INIT_get_init_value(data)                                      (0x000003FF&(data))

#define  IMG_RMRPR_CNTL                                                          0x1800FA10
#define  IMG_RMRPR_CNTL_reg_addr                                                 "0xB800FA10"
#define  IMG_RMRPR_CNTL_reg                                                      0xB800FA10
#define  IMG_RMRPR_CNTL_inst_addr                                                "0x0004"
#define  set_IMG_RMRPR_CNTL_reg(data)                                            (*((volatile unsigned int*)IMG_RMRPR_CNTL_reg)=data)
#define  get_IMG_RMRPR_CNTL_reg                                                  (*((volatile unsigned int*)IMG_RMRPR_CNTL_reg))
#define  IMG_RMRPR_CNTL_rcrpr_shift                                              (26)
#define  IMG_RMRPR_CNTL_color_cr_shift                                           (18)
#define  IMG_RMRPR_CNTL_color_cb_shift                                           (10)
#define  IMG_RMRPR_CNTL_color_y_shift                                            (2)
#define  IMG_RMRPR_CNTL_fill_mode_shift                                          (0)
#define  IMG_RMRPR_CNTL_rcrpr_mask                                               (0x04000000)
#define  IMG_RMRPR_CNTL_color_cr_mask                                            (0x03FC0000)
#define  IMG_RMRPR_CNTL_color_cb_mask                                            (0x0003FC00)
#define  IMG_RMRPR_CNTL_color_y_mask                                             (0x000003FC)
#define  IMG_RMRPR_CNTL_fill_mode_mask                                           (0x00000003)
#define  IMG_RMRPR_CNTL_rcrpr(data)                                              (0x04000000&((data)<<26))
#define  IMG_RMRPR_CNTL_color_cr(data)                                           (0x03FC0000&((data)<<18))
#define  IMG_RMRPR_CNTL_color_cb(data)                                           (0x0003FC00&((data)<<10))
#define  IMG_RMRPR_CNTL_color_y(data)                                            (0x000003FC&((data)<<2))
#define  IMG_RMRPR_CNTL_fill_mode(data)                                          (0x00000003&(data))
#define  IMG_RMRPR_CNTL_get_rcrpr(data)                                          ((0x04000000&(data))>>26)
#define  IMG_RMRPR_CNTL_get_color_cr(data)                                       ((0x03FC0000&(data))>>18)
#define  IMG_RMRPR_CNTL_get_color_cb(data)                                       ((0x0003FC00&(data))>>10)
#define  IMG_RMRPR_CNTL_get_color_y(data)                                        ((0x000003FC&(data))>>2)
#define  IMG_RMRPR_CNTL_get_fill_mode(data)                                      (0x00000003&(data))

#define  IMG_RMRPR_PAR                                                           0x1800FA14
#define  IMG_RMRPR_PAR_reg_addr                                                  "0xB800FA14"
#define  IMG_RMRPR_PAR_reg                                                       0xB800FA14
#define  IMG_RMRPR_PAR_inst_addr                                                 "0x0005"
#define  set_IMG_RMRPR_PAR_reg(data)                                             (*((volatile unsigned int*)IMG_RMRPR_PAR_reg)=data)
#define  get_IMG_RMRPR_PAR_reg                                                   (*((volatile unsigned int*)IMG_RMRPR_PAR_reg))
#define  IMG_RMRPR_PAR_m_shift                                                   (13)
#define  IMG_RMRPR_PAR_pixel_offset_shift                                        (0)
#define  IMG_RMRPR_PAR_m_mask                                                    (0x0001E000)
#define  IMG_RMRPR_PAR_pixel_offset_mask                                         (0x00001FFF)
#define  IMG_RMRPR_PAR_m(data)                                                   (0x0001E000&((data)<<13))
#define  IMG_RMRPR_PAR_pixel_offset(data)                                        (0x00001FFF&(data))
#define  IMG_RMRPR_PAR_get_m(data)                                               ((0x0001E000&(data))>>13)
#define  IMG_RMRPR_PAR_get_pixel_offset(data)                                    (0x00001FFF&(data))

#define  IMG_RMRPR_AX                                                            0x1800FA18
#define  IMG_RMRPR_AX_reg_addr                                                   "0xB800FA18"
#define  IMG_RMRPR_AX_reg                                                        0xB800FA18
#define  IMG_RMRPR_AX_inst_addr                                                  "0x0006"
#define  set_IMG_RMRPR_AX_reg(data)                                              (*((volatile unsigned int*)IMG_RMRPR_AX_reg)=data)
#define  get_IMG_RMRPR_AX_reg                                                    (*((volatile unsigned int*)IMG_RMRPR_AX_reg))
#define  IMG_RMRPR_AX_ax_shift                                                   (0)
#define  IMG_RMRPR_AX_ax_mask                                                    (0xFFFFFFFF)
#define  IMG_RMRPR_AX_ax(data)                                                   (0xFFFFFFFF&(data))
#define  IMG_RMRPR_AX_get_ax(data)                                               (0xFFFFFFFF&(data))

#define  IMG_RMRPR_AY                                                            0x1800FA1C
#define  IMG_RMRPR_AY_reg_addr                                                   "0xB800FA1C"
#define  IMG_RMRPR_AY_reg                                                        0xB800FA1C
#define  IMG_RMRPR_AY_inst_addr                                                  "0x0007"
#define  set_IMG_RMRPR_AY_reg(data)                                              (*((volatile unsigned int*)IMG_RMRPR_AY_reg)=data)
#define  get_IMG_RMRPR_AY_reg                                                    (*((volatile unsigned int*)IMG_RMRPR_AY_reg))
#define  IMG_RMRPR_AY_ay_shift                                                   (0)
#define  IMG_RMRPR_AY_ay_mask                                                    (0xFFFFFFFF)
#define  IMG_RMRPR_AY_ay(data)                                                   (0xFFFFFFFF&(data))
#define  IMG_RMRPR_AY_get_ay(data)                                               (0xFFFFFFFF&(data))

#define  IMG_RMRPR_AXINC                                                         0x1800FA20
#define  IMG_RMRPR_AXINC_reg_addr                                                "0xB800FA20"
#define  IMG_RMRPR_AXINC_reg                                                     0xB800FA20
#define  IMG_RMRPR_AXINC_inst_addr                                               "0x0008"
#define  set_IMG_RMRPR_AXINC_reg(data)                                           (*((volatile unsigned int*)IMG_RMRPR_AXINC_reg)=data)
#define  get_IMG_RMRPR_AXINC_reg                                                 (*((volatile unsigned int*)IMG_RMRPR_AXINC_reg))
#define  IMG_RMRPR_AXINC_ax_inc_shift                                            (0)
#define  IMG_RMRPR_AXINC_ax_inc_mask                                             (0xFFFFFFFF)
#define  IMG_RMRPR_AXINC_ax_inc(data)                                            (0xFFFFFFFF&(data))
#define  IMG_RMRPR_AXINC_get_ax_inc(data)                                        (0xFFFFFFFF&(data))

#define  IMG_RMRPR_PICINFO                                                       0x1800FA24
#define  IMG_RMRPR_PICINFO_reg_addr                                              "0xB800FA24"
#define  IMG_RMRPR_PICINFO_reg                                                   0xB800FA24
#define  IMG_RMRPR_PICINFO_inst_addr                                             "0x0009"
#define  set_IMG_RMRPR_PICINFO_reg(data)                                         (*((volatile unsigned int*)IMG_RMRPR_PICINFO_reg)=data)
#define  get_IMG_RMRPR_PICINFO_reg                                               (*((volatile unsigned int*)IMG_RMRPR_PICINFO_reg))
#define  IMG_RMRPR_PICINFO_picmb_h_shift                                         (9)
#define  IMG_RMRPR_PICINFO_picmb_w_shift                                         (0)
#define  IMG_RMRPR_PICINFO_picmb_h_mask                                          (0x0001FE00)
#define  IMG_RMRPR_PICINFO_picmb_w_mask                                          (0x000001FF)
#define  IMG_RMRPR_PICINFO_picmb_h(data)                                         (0x0001FE00&((data)<<9))
#define  IMG_RMRPR_PICINFO_picmb_w(data)                                         (0x000001FF&(data))
#define  IMG_RMRPR_PICINFO_get_picmb_h(data)                                     ((0x0001FE00&(data))>>9)
#define  IMG_RMRPR_PICINFO_get_picmb_w(data)                                     (0x000001FF&(data))

#define  IMG_BASEA_0                                                             0x1800FA28
#define  IMG_BASEA_0_reg_addr                                                    "0xB800FA28"
#define  IMG_BASEA_0_reg                                                         0xB800FA28
#define  IMG_BASEA_0_inst_addr                                                   "0x000A"
#define  set_IMG_BASEA_0_reg(data)                                               (*((volatile unsigned int*)IMG_BASEA_0_reg)=data)
#define  get_IMG_BASEA_0_reg                                                     (*((volatile unsigned int*)IMG_BASEA_0_reg))
#define  IMG_BASEA_0_basea_shift                                                 (0)
#define  IMG_BASEA_0_basea_mask                                                  (0x000003FF)
#define  IMG_BASEA_0_basea(data)                                                 (0x000003FF&(data))
#define  IMG_BASEA_0_get_basea(data)                                             (0x000003FF&(data))

#define  IMG_BASEA_1                                                             0x1800FA2C
#define  IMG_BASEA_1_reg_addr                                                    "0xB800FA2C"
#define  IMG_BASEA_1_reg                                                         0xB800FA2C
#define  IMG_BASEA_1_inst_addr                                                   "0x000B"
#define  set_IMG_BASEA_1_reg(data)                                               (*((volatile unsigned int*)IMG_BASEA_1_reg)=data)
#define  get_IMG_BASEA_1_reg                                                     (*((volatile unsigned int*)IMG_BASEA_1_reg))
#define  IMG_BASEA_1_basea_shift                                                 (0)
#define  IMG_BASEA_1_basea_mask                                                  (0x000003FF)
#define  IMG_BASEA_1_basea(data)                                                 (0x000003FF&(data))
#define  IMG_BASEA_1_get_basea(data)                                             (0x000003FF&(data))

#define  IMG_BASEA_2                                                             0x1800FA30
#define  IMG_BASEA_2_reg_addr                                                    "0xB800FA30"
#define  IMG_BASEA_2_reg                                                         0xB800FA30
#define  IMG_BASEA_2_inst_addr                                                   "0x000C"
#define  set_IMG_BASEA_2_reg(data)                                               (*((volatile unsigned int*)IMG_BASEA_2_reg)=data)
#define  get_IMG_BASEA_2_reg                                                     (*((volatile unsigned int*)IMG_BASEA_2_reg))
#define  IMG_BASEA_2_basea_shift                                                 (0)
#define  IMG_BASEA_2_basea_mask                                                  (0x000003FF)
#define  IMG_BASEA_2_basea(data)                                                 (0x000003FF&(data))
#define  IMG_BASEA_2_get_basea(data)                                             (0x000003FF&(data))

#define  IMG_BASEA_3                                                             0x1800FA34
#define  IMG_BASEA_3_reg_addr                                                    "0xB800FA34"
#define  IMG_BASEA_3_reg                                                         0xB800FA34
#define  IMG_BASEA_3_inst_addr                                                   "0x000D"
#define  set_IMG_BASEA_3_reg(data)                                               (*((volatile unsigned int*)IMG_BASEA_3_reg)=data)
#define  get_IMG_BASEA_3_reg                                                     (*((volatile unsigned int*)IMG_BASEA_3_reg))
#define  IMG_BASEA_3_basea_shift                                                 (0)
#define  IMG_BASEA_3_basea_mask                                                  (0x000003FF)
#define  IMG_BASEA_3_basea(data)                                                 (0x000003FF&(data))
#define  IMG_BASEA_3_get_basea(data)                                             (0x000003FF&(data))

#define  IMG_OFFSETA_0                                                           0x1800FA38
#define  IMG_OFFSETA_0_reg_addr                                                  "0xB800FA38"
#define  IMG_OFFSETA_0_reg                                                       0xB800FA38
#define  IMG_OFFSETA_0_inst_addr                                                 "0x000E"
#define  set_IMG_OFFSETA_0_reg(data)                                             (*((volatile unsigned int*)IMG_OFFSETA_0_reg)=data)
#define  get_IMG_OFFSETA_0_reg                                                   (*((volatile unsigned int*)IMG_OFFSETA_0_reg))
#define  IMG_OFFSETA_0_offseta_shift                                             (0)
#define  IMG_OFFSETA_0_offseta_mask                                              (0x000001FF)
#define  IMG_OFFSETA_0_offseta(data)                                             (0x000001FF&(data))
#define  IMG_OFFSETA_0_get_offseta(data)                                         (0x000001FF&(data))

#define  IMG_OFFSETA_1                                                           0x1800FA3C
#define  IMG_OFFSETA_1_reg_addr                                                  "0xB800FA3C"
#define  IMG_OFFSETA_1_reg                                                       0xB800FA3C
#define  IMG_OFFSETA_1_inst_addr                                                 "0x000F"
#define  set_IMG_OFFSETA_1_reg(data)                                             (*((volatile unsigned int*)IMG_OFFSETA_1_reg)=data)
#define  get_IMG_OFFSETA_1_reg                                                   (*((volatile unsigned int*)IMG_OFFSETA_1_reg))
#define  IMG_OFFSETA_1_offseta_shift                                             (0)
#define  IMG_OFFSETA_1_offseta_mask                                              (0x000001FF)
#define  IMG_OFFSETA_1_offseta(data)                                             (0x000001FF&(data))
#define  IMG_OFFSETA_1_get_offseta(data)                                         (0x000001FF&(data))

#define  IMG_OFFSETA_2                                                           0x1800FA40
#define  IMG_OFFSETA_2_reg_addr                                                  "0xB800FA40"
#define  IMG_OFFSETA_2_reg                                                       0xB800FA40
#define  IMG_OFFSETA_2_inst_addr                                                 "0x0010"
#define  set_IMG_OFFSETA_2_reg(data)                                             (*((volatile unsigned int*)IMG_OFFSETA_2_reg)=data)
#define  get_IMG_OFFSETA_2_reg                                                   (*((volatile unsigned int*)IMG_OFFSETA_2_reg))
#define  IMG_OFFSETA_2_offseta_shift                                             (0)
#define  IMG_OFFSETA_2_offseta_mask                                              (0x000001FF)
#define  IMG_OFFSETA_2_offseta(data)                                             (0x000001FF&(data))
#define  IMG_OFFSETA_2_get_offseta(data)                                         (0x000001FF&(data))

#define  IMG_OFFSETA_3                                                           0x1800FA44
#define  IMG_OFFSETA_3_reg_addr                                                  "0xB800FA44"
#define  IMG_OFFSETA_3_reg                                                       0xB800FA44
#define  IMG_OFFSETA_3_inst_addr                                                 "0x0011"
#define  set_IMG_OFFSETA_3_reg(data)                                             (*((volatile unsigned int*)IMG_OFFSETA_3_reg)=data)
#define  get_IMG_OFFSETA_3_reg                                                   (*((volatile unsigned int*)IMG_OFFSETA_3_reg))
#define  IMG_OFFSETA_3_offseta_shift                                             (0)
#define  IMG_OFFSETA_3_offseta_mask                                              (0x000001FF)
#define  IMG_OFFSETA_3_offseta(data)                                             (0x000001FF&(data))
#define  IMG_OFFSETA_3_get_offseta(data)                                         (0x000001FF&(data))

#define  IMG_PHASE_INIT_0                                                        0x1800FA48
#define  IMG_PHASE_INIT_0_reg_addr                                               "0xB800FA48"
#define  IMG_PHASE_INIT_0_reg                                                    0xB800FA48
#define  IMG_PHASE_INIT_0_inst_addr                                              "0x0012"
#define  set_IMG_PHASE_INIT_0_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_0_reg)=data)
#define  get_IMG_PHASE_INIT_0_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_0_reg))
#define  IMG_PHASE_INIT_0_init_phase_shift                                       (0)
#define  IMG_PHASE_INIT_0_init_phase_mask                                        (0x000FFFFF)
#define  IMG_PHASE_INIT_0_init_phase(data)                                       (0x000FFFFF&(data))
#define  IMG_PHASE_INIT_0_get_init_phase(data)                                   (0x000FFFFF&(data))

#define  IMG_PHASE_INIT_1                                                        0x1800FA4C
#define  IMG_PHASE_INIT_1_reg_addr                                               "0xB800FA4C"
#define  IMG_PHASE_INIT_1_reg                                                    0xB800FA4C
#define  IMG_PHASE_INIT_1_inst_addr                                              "0x0013"
#define  set_IMG_PHASE_INIT_1_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_1_reg)=data)
#define  get_IMG_PHASE_INIT_1_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_1_reg))
#define  IMG_PHASE_INIT_1_init_phase_shift                                       (0)
#define  IMG_PHASE_INIT_1_init_phase_mask                                        (0x000FFFFF)
#define  IMG_PHASE_INIT_1_init_phase(data)                                       (0x000FFFFF&(data))
#define  IMG_PHASE_INIT_1_get_init_phase(data)                                   (0x000FFFFF&(data))

#define  IMG_PHASE_INIT_2                                                        0x1800FA50
#define  IMG_PHASE_INIT_2_reg_addr                                               "0xB800FA50"
#define  IMG_PHASE_INIT_2_reg                                                    0xB800FA50
#define  IMG_PHASE_INIT_2_inst_addr                                              "0x0014"
#define  set_IMG_PHASE_INIT_2_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_2_reg)=data)
#define  get_IMG_PHASE_INIT_2_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_2_reg))
#define  IMG_PHASE_INIT_2_init_phase_shift                                       (0)
#define  IMG_PHASE_INIT_2_init_phase_mask                                        (0x000FFFFF)
#define  IMG_PHASE_INIT_2_init_phase(data)                                       (0x000FFFFF&(data))
#define  IMG_PHASE_INIT_2_get_init_phase(data)                                   (0x000FFFFF&(data))

#define  IMG_PHASE_INIT_3                                                        0x1800FA54
#define  IMG_PHASE_INIT_3_reg_addr                                               "0xB800FA54"
#define  IMG_PHASE_INIT_3_reg                                                    0xB800FA54
#define  IMG_PHASE_INIT_3_inst_addr                                              "0x0015"
#define  set_IMG_PHASE_INIT_3_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_3_reg)=data)
#define  get_IMG_PHASE_INIT_3_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_3_reg))
#define  IMG_PHASE_INIT_3_init_phase_shift                                       (0)
#define  IMG_PHASE_INIT_3_init_phase_mask                                        (0x000FFFFF)
#define  IMG_PHASE_INIT_3_init_phase(data)                                       (0x000FFFFF&(data))
#define  IMG_PHASE_INIT_3_get_init_phase(data)                                   (0x000FFFFF&(data))

#define  IMG_PHASE_INIT_4                                                        0x1800FA58
#define  IMG_PHASE_INIT_4_reg_addr                                               "0xB800FA58"
#define  IMG_PHASE_INIT_4_reg                                                    0xB800FA58
#define  IMG_PHASE_INIT_4_inst_addr                                              "0x0016"
#define  set_IMG_PHASE_INIT_4_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_4_reg)=data)
#define  get_IMG_PHASE_INIT_4_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_4_reg))
#define  IMG_PHASE_INIT_4_init_phase_shift                                       (0)
#define  IMG_PHASE_INIT_4_init_phase_mask                                        (0x000FFFFF)
#define  IMG_PHASE_INIT_4_init_phase(data)                                       (0x000FFFFF&(data))
#define  IMG_PHASE_INIT_4_get_init_phase(data)                                   (0x000FFFFF&(data))

#define  IMG_PHASE_INIT_5                                                        0x1800FA5C
#define  IMG_PHASE_INIT_5_reg_addr                                               "0xB800FA5C"
#define  IMG_PHASE_INIT_5_reg                                                    0xB800FA5C
#define  IMG_PHASE_INIT_5_inst_addr                                              "0x0017"
#define  set_IMG_PHASE_INIT_5_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_5_reg)=data)
#define  get_IMG_PHASE_INIT_5_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_5_reg))
#define  IMG_PHASE_INIT_5_init_phase_shift                                       (0)
#define  IMG_PHASE_INIT_5_init_phase_mask                                        (0x000FFFFF)
#define  IMG_PHASE_INIT_5_init_phase(data)                                       (0x000FFFFF&(data))
#define  IMG_PHASE_INIT_5_get_init_phase(data)                                   (0x000FFFFF&(data))

#define  IMG_PHASE_INIT_6                                                        0x1800FA60
#define  IMG_PHASE_INIT_6_reg_addr                                               "0xB800FA60"
#define  IMG_PHASE_INIT_6_reg                                                    0xB800FA60
#define  IMG_PHASE_INIT_6_inst_addr                                              "0x0018"
#define  set_IMG_PHASE_INIT_6_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_6_reg)=data)
#define  get_IMG_PHASE_INIT_6_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_6_reg))
#define  IMG_PHASE_INIT_6_init_phase_shift                                       (0)
#define  IMG_PHASE_INIT_6_init_phase_mask                                        (0x000FFFFF)
#define  IMG_PHASE_INIT_6_init_phase(data)                                       (0x000FFFFF&(data))
#define  IMG_PHASE_INIT_6_get_init_phase(data)                                   (0x000FFFFF&(data))

#define  IMG_PHASE_INIT_7                                                        0x1800FA64
#define  IMG_PHASE_INIT_7_reg_addr                                               "0xB800FA64"
#define  IMG_PHASE_INIT_7_reg                                                    0xB800FA64
#define  IMG_PHASE_INIT_7_inst_addr                                              "0x0019"
#define  set_IMG_PHASE_INIT_7_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_7_reg)=data)
#define  get_IMG_PHASE_INIT_7_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_7_reg))
#define  IMG_PHASE_INIT_7_init_phase_shift                                       (0)
#define  IMG_PHASE_INIT_7_init_phase_mask                                        (0x000FFFFF)
#define  IMG_PHASE_INIT_7_init_phase(data)                                       (0x000FFFFF&(data))
#define  IMG_PHASE_INIT_7_get_init_phase(data)                                   (0x000FFFFF&(data))

#define  IMG_PHASE_INC_0                                                         0x1800FA68
#define  IMG_PHASE_INC_0_reg_addr                                                "0xB800FA68"
#define  IMG_PHASE_INC_0_reg                                                     0xB800FA68
#define  IMG_PHASE_INC_0_inst_addr                                               "0x001A"
#define  set_IMG_PHASE_INC_0_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_0_reg)=data)
#define  get_IMG_PHASE_INC_0_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_0_reg))
#define  IMG_PHASE_INC_0_phase_inc_shift                                         (0)
#define  IMG_PHASE_INC_0_phase_inc_mask                                          (0x00FFFFFF)
#define  IMG_PHASE_INC_0_phase_inc(data)                                         (0x00FFFFFF&(data))
#define  IMG_PHASE_INC_0_get_phase_inc(data)                                     (0x00FFFFFF&(data))

#define  IMG_PHASE_INC_1                                                         0x1800FA6C
#define  IMG_PHASE_INC_1_reg_addr                                                "0xB800FA6C"
#define  IMG_PHASE_INC_1_reg                                                     0xB800FA6C
#define  IMG_PHASE_INC_1_inst_addr                                               "0x001B"
#define  set_IMG_PHASE_INC_1_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_1_reg)=data)
#define  get_IMG_PHASE_INC_1_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_1_reg))
#define  IMG_PHASE_INC_1_phase_inc_shift                                         (0)
#define  IMG_PHASE_INC_1_phase_inc_mask                                          (0x00FFFFFF)
#define  IMG_PHASE_INC_1_phase_inc(data)                                         (0x00FFFFFF&(data))
#define  IMG_PHASE_INC_1_get_phase_inc(data)                                     (0x00FFFFFF&(data))

#define  IMG_PHASE_INC_2                                                         0x1800FA70
#define  IMG_PHASE_INC_2_reg_addr                                                "0xB800FA70"
#define  IMG_PHASE_INC_2_reg                                                     0xB800FA70
#define  IMG_PHASE_INC_2_inst_addr                                               "0x001C"
#define  set_IMG_PHASE_INC_2_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_2_reg)=data)
#define  get_IMG_PHASE_INC_2_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_2_reg))
#define  IMG_PHASE_INC_2_phase_inc_shift                                         (0)
#define  IMG_PHASE_INC_2_phase_inc_mask                                          (0x00FFFFFF)
#define  IMG_PHASE_INC_2_phase_inc(data)                                         (0x00FFFFFF&(data))
#define  IMG_PHASE_INC_2_get_phase_inc(data)                                     (0x00FFFFFF&(data))

#define  IMG_PHASE_INC_3                                                         0x1800FA74
#define  IMG_PHASE_INC_3_reg_addr                                                "0xB800FA74"
#define  IMG_PHASE_INC_3_reg                                                     0xB800FA74
#define  IMG_PHASE_INC_3_inst_addr                                               "0x001D"
#define  set_IMG_PHASE_INC_3_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_3_reg)=data)
#define  get_IMG_PHASE_INC_3_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_3_reg))
#define  IMG_PHASE_INC_3_phase_inc_shift                                         (0)
#define  IMG_PHASE_INC_3_phase_inc_mask                                          (0x00FFFFFF)
#define  IMG_PHASE_INC_3_phase_inc(data)                                         (0x00FFFFFF&(data))
#define  IMG_PHASE_INC_3_get_phase_inc(data)                                     (0x00FFFFFF&(data))

#define  IMG_PHASE_INC_4                                                         0x1800FA78
#define  IMG_PHASE_INC_4_reg_addr                                                "0xB800FA78"
#define  IMG_PHASE_INC_4_reg                                                     0xB800FA78
#define  IMG_PHASE_INC_4_inst_addr                                               "0x001E"
#define  set_IMG_PHASE_INC_4_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_4_reg)=data)
#define  get_IMG_PHASE_INC_4_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_4_reg))
#define  IMG_PHASE_INC_4_phase_inc_shift                                         (0)
#define  IMG_PHASE_INC_4_phase_inc_mask                                          (0x00FFFFFF)
#define  IMG_PHASE_INC_4_phase_inc(data)                                         (0x00FFFFFF&(data))
#define  IMG_PHASE_INC_4_get_phase_inc(data)                                     (0x00FFFFFF&(data))

#define  IMG_PHASE_INC_5                                                         0x1800FA7C
#define  IMG_PHASE_INC_5_reg_addr                                                "0xB800FA7C"
#define  IMG_PHASE_INC_5_reg                                                     0xB800FA7C
#define  IMG_PHASE_INC_5_inst_addr                                               "0x001F"
#define  set_IMG_PHASE_INC_5_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_5_reg)=data)
#define  get_IMG_PHASE_INC_5_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_5_reg))
#define  IMG_PHASE_INC_5_phase_inc_shift                                         (0)
#define  IMG_PHASE_INC_5_phase_inc_mask                                          (0x00FFFFFF)
#define  IMG_PHASE_INC_5_phase_inc(data)                                         (0x00FFFFFF&(data))
#define  IMG_PHASE_INC_5_get_phase_inc(data)                                     (0x00FFFFFF&(data))

#define  IMG_PHASE_INC_6                                                         0x1800FA80
#define  IMG_PHASE_INC_6_reg_addr                                                "0xB800FA80"
#define  IMG_PHASE_INC_6_reg                                                     0xB800FA80
#define  IMG_PHASE_INC_6_inst_addr                                               "0x0020"
#define  set_IMG_PHASE_INC_6_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_6_reg)=data)
#define  get_IMG_PHASE_INC_6_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_6_reg))
#define  IMG_PHASE_INC_6_phase_inc_shift                                         (0)
#define  IMG_PHASE_INC_6_phase_inc_mask                                          (0x00FFFFFF)
#define  IMG_PHASE_INC_6_phase_inc(data)                                         (0x00FFFFFF&(data))
#define  IMG_PHASE_INC_6_get_phase_inc(data)                                     (0x00FFFFFF&(data))

#define  IMG_PHASE_INC_7                                                         0x1800FA84
#define  IMG_PHASE_INC_7_reg_addr                                                "0xB800FA84"
#define  IMG_PHASE_INC_7_reg                                                     0xB800FA84
#define  IMG_PHASE_INC_7_inst_addr                                               "0x0021"
#define  set_IMG_PHASE_INC_7_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_7_reg)=data)
#define  get_IMG_PHASE_INC_7_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_7_reg))
#define  IMG_PHASE_INC_7_phase_inc_shift                                         (0)
#define  IMG_PHASE_INC_7_phase_inc_mask                                          (0x00FFFFFF)
#define  IMG_PHASE_INC_7_phase_inc(data)                                         (0x00FFFFFF&(data))
#define  IMG_PHASE_INC_7_get_phase_inc(data)                                     (0x00FFFFFF&(data))

#define  IMG_PHASE_OUT_0                                                         0x1800FA88
#define  IMG_PHASE_OUT_0_reg_addr                                                "0xB800FA88"
#define  IMG_PHASE_OUT_0_reg                                                     0xB800FA88
#define  IMG_PHASE_OUT_0_inst_addr                                               "0x0022"
#define  set_IMG_PHASE_OUT_0_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_0_reg)=data)
#define  get_IMG_PHASE_OUT_0_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_0_reg))
#define  IMG_PHASE_OUT_0_final_phase_shift                                       (0)
#define  IMG_PHASE_OUT_0_final_phase_mask                                        (0x07FFFFFF)
#define  IMG_PHASE_OUT_0_final_phase(data)                                       (0x07FFFFFF&(data))
#define  IMG_PHASE_OUT_0_get_final_phase(data)                                   (0x07FFFFFF&(data))

#define  IMG_PHASE_OUT_1                                                         0x1800FA8C
#define  IMG_PHASE_OUT_1_reg_addr                                                "0xB800FA8C"
#define  IMG_PHASE_OUT_1_reg                                                     0xB800FA8C
#define  IMG_PHASE_OUT_1_inst_addr                                               "0x0023"
#define  set_IMG_PHASE_OUT_1_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_1_reg)=data)
#define  get_IMG_PHASE_OUT_1_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_1_reg))
#define  IMG_PHASE_OUT_1_final_phase_shift                                       (0)
#define  IMG_PHASE_OUT_1_final_phase_mask                                        (0x07FFFFFF)
#define  IMG_PHASE_OUT_1_final_phase(data)                                       (0x07FFFFFF&(data))
#define  IMG_PHASE_OUT_1_get_final_phase(data)                                   (0x07FFFFFF&(data))

#define  IMG_PHASE_OUT_2                                                         0x1800FA90
#define  IMG_PHASE_OUT_2_reg_addr                                                "0xB800FA90"
#define  IMG_PHASE_OUT_2_reg                                                     0xB800FA90
#define  IMG_PHASE_OUT_2_inst_addr                                               "0x0024"
#define  set_IMG_PHASE_OUT_2_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_2_reg)=data)
#define  get_IMG_PHASE_OUT_2_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_2_reg))
#define  IMG_PHASE_OUT_2_final_phase_shift                                       (0)
#define  IMG_PHASE_OUT_2_final_phase_mask                                        (0x07FFFFFF)
#define  IMG_PHASE_OUT_2_final_phase(data)                                       (0x07FFFFFF&(data))
#define  IMG_PHASE_OUT_2_get_final_phase(data)                                   (0x07FFFFFF&(data))

#define  IMG_PHASE_OUT_3                                                         0x1800FA94
#define  IMG_PHASE_OUT_3_reg_addr                                                "0xB800FA94"
#define  IMG_PHASE_OUT_3_reg                                                     0xB800FA94
#define  IMG_PHASE_OUT_3_inst_addr                                               "0x0025"
#define  set_IMG_PHASE_OUT_3_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_3_reg)=data)
#define  get_IMG_PHASE_OUT_3_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_3_reg))
#define  IMG_PHASE_OUT_3_final_phase_shift                                       (0)
#define  IMG_PHASE_OUT_3_final_phase_mask                                        (0x07FFFFFF)
#define  IMG_PHASE_OUT_3_final_phase(data)                                       (0x07FFFFFF&(data))
#define  IMG_PHASE_OUT_3_get_final_phase(data)                                   (0x07FFFFFF&(data))

#define  IMG_PHASE_OUT_4                                                         0x1800FA98
#define  IMG_PHASE_OUT_4_reg_addr                                                "0xB800FA98"
#define  IMG_PHASE_OUT_4_reg                                                     0xB800FA98
#define  IMG_PHASE_OUT_4_inst_addr                                               "0x0026"
#define  set_IMG_PHASE_OUT_4_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_4_reg)=data)
#define  get_IMG_PHASE_OUT_4_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_4_reg))
#define  IMG_PHASE_OUT_4_final_phase_shift                                       (0)
#define  IMG_PHASE_OUT_4_final_phase_mask                                        (0x07FFFFFF)
#define  IMG_PHASE_OUT_4_final_phase(data)                                       (0x07FFFFFF&(data))
#define  IMG_PHASE_OUT_4_get_final_phase(data)                                   (0x07FFFFFF&(data))

#define  IMG_PHASE_OUT_5                                                         0x1800FA9C
#define  IMG_PHASE_OUT_5_reg_addr                                                "0xB800FA9C"
#define  IMG_PHASE_OUT_5_reg                                                     0xB800FA9C
#define  IMG_PHASE_OUT_5_inst_addr                                               "0x0027"
#define  set_IMG_PHASE_OUT_5_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_5_reg)=data)
#define  get_IMG_PHASE_OUT_5_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_5_reg))
#define  IMG_PHASE_OUT_5_final_phase_shift                                       (0)
#define  IMG_PHASE_OUT_5_final_phase_mask                                        (0x07FFFFFF)
#define  IMG_PHASE_OUT_5_final_phase(data)                                       (0x07FFFFFF&(data))
#define  IMG_PHASE_OUT_5_get_final_phase(data)                                   (0x07FFFFFF&(data))

#define  IMG_PHASE_OUT_6                                                         0x1800FAA0
#define  IMG_PHASE_OUT_6_reg_addr                                                "0xB800FAA0"
#define  IMG_PHASE_OUT_6_reg                                                     0xB800FAA0
#define  IMG_PHASE_OUT_6_inst_addr                                               "0x0028"
#define  set_IMG_PHASE_OUT_6_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_6_reg)=data)
#define  get_IMG_PHASE_OUT_6_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_6_reg))
#define  IMG_PHASE_OUT_6_final_phase_shift                                       (0)
#define  IMG_PHASE_OUT_6_final_phase_mask                                        (0x07FFFFFF)
#define  IMG_PHASE_OUT_6_final_phase(data)                                       (0x07FFFFFF&(data))
#define  IMG_PHASE_OUT_6_get_final_phase(data)                                   (0x07FFFFFF&(data))

#define  IMG_PHASE_OUT_7                                                         0x1800FAA4
#define  IMG_PHASE_OUT_7_reg_addr                                                "0xB800FAA4"
#define  IMG_PHASE_OUT_7_reg                                                     0xB800FAA4
#define  IMG_PHASE_OUT_7_inst_addr                                               "0x0029"
#define  set_IMG_PHASE_OUT_7_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_7_reg)=data)
#define  get_IMG_PHASE_OUT_7_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_7_reg))
#define  IMG_PHASE_OUT_7_final_phase_shift                                       (0)
#define  IMG_PHASE_OUT_7_final_phase_mask                                        (0x07FFFFFF)
#define  IMG_PHASE_OUT_7_final_phase(data)                                       (0x07FFFFFF&(data))
#define  IMG_PHASE_OUT_7_get_final_phase(data)                                   (0x07FFFFFF&(data))

#define  IMG_TAPCOEFF0_0                                                         0x1800FAA8
#define  IMG_TAPCOEFF0_0_reg_addr                                                "0xB800FAA8"
#define  IMG_TAPCOEFF0_0_reg                                                     0xB800FAA8
#define  IMG_TAPCOEFF0_0_inst_addr                                               "0x002A"
#define  set_IMG_TAPCOEFF0_0_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_0_reg)=data)
#define  get_IMG_TAPCOEFF0_0_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_0_reg))
#define  IMG_TAPCOEFF0_0_coeff0_n1_shift                                         (16)
#define  IMG_TAPCOEFF0_0_coeff0_n_shift                                          (0)
#define  IMG_TAPCOEFF0_0_coeff0_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF0_0_coeff0_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF0_0_coeff0_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF0_0_coeff0_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF0_0_get_coeff0_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF0_0_get_coeff0_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF0_1                                                         0x1800FAAC
#define  IMG_TAPCOEFF0_1_reg_addr                                                "0xB800FAAC"
#define  IMG_TAPCOEFF0_1_reg                                                     0xB800FAAC
#define  IMG_TAPCOEFF0_1_inst_addr                                               "0x002B"
#define  set_IMG_TAPCOEFF0_1_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_1_reg)=data)
#define  get_IMG_TAPCOEFF0_1_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_1_reg))
#define  IMG_TAPCOEFF0_1_coeff0_n1_shift                                         (16)
#define  IMG_TAPCOEFF0_1_coeff0_n_shift                                          (0)
#define  IMG_TAPCOEFF0_1_coeff0_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF0_1_coeff0_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF0_1_coeff0_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF0_1_coeff0_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF0_1_get_coeff0_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF0_1_get_coeff0_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF0_2                                                         0x1800FAB0
#define  IMG_TAPCOEFF0_2_reg_addr                                                "0xB800FAB0"
#define  IMG_TAPCOEFF0_2_reg                                                     0xB800FAB0
#define  IMG_TAPCOEFF0_2_inst_addr                                               "0x002C"
#define  set_IMG_TAPCOEFF0_2_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_2_reg)=data)
#define  get_IMG_TAPCOEFF0_2_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_2_reg))
#define  IMG_TAPCOEFF0_2_coeff0_n1_shift                                         (16)
#define  IMG_TAPCOEFF0_2_coeff0_n_shift                                          (0)
#define  IMG_TAPCOEFF0_2_coeff0_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF0_2_coeff0_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF0_2_coeff0_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF0_2_coeff0_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF0_2_get_coeff0_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF0_2_get_coeff0_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF0_3                                                         0x1800FAB4
#define  IMG_TAPCOEFF0_3_reg_addr                                                "0xB800FAB4"
#define  IMG_TAPCOEFF0_3_reg                                                     0xB800FAB4
#define  IMG_TAPCOEFF0_3_inst_addr                                               "0x002D"
#define  set_IMG_TAPCOEFF0_3_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_3_reg)=data)
#define  get_IMG_TAPCOEFF0_3_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_3_reg))
#define  IMG_TAPCOEFF0_3_coeff0_n1_shift                                         (16)
#define  IMG_TAPCOEFF0_3_coeff0_n_shift                                          (0)
#define  IMG_TAPCOEFF0_3_coeff0_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF0_3_coeff0_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF0_3_coeff0_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF0_3_coeff0_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF0_3_get_coeff0_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF0_3_get_coeff0_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF0_4                                                         0x1800FAB8
#define  IMG_TAPCOEFF0_4_reg_addr                                                "0xB800FAB8"
#define  IMG_TAPCOEFF0_4_reg                                                     0xB800FAB8
#define  IMG_TAPCOEFF0_4_inst_addr                                               "0x002E"
#define  set_IMG_TAPCOEFF0_4_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_4_reg)=data)
#define  get_IMG_TAPCOEFF0_4_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_4_reg))
#define  IMG_TAPCOEFF0_4_coeff0_n1_shift                                         (16)
#define  IMG_TAPCOEFF0_4_coeff0_n_shift                                          (0)
#define  IMG_TAPCOEFF0_4_coeff0_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF0_4_coeff0_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF0_4_coeff0_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF0_4_coeff0_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF0_4_get_coeff0_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF0_4_get_coeff0_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF0_5                                                         0x1800FABC
#define  IMG_TAPCOEFF0_5_reg_addr                                                "0xB800FABC"
#define  IMG_TAPCOEFF0_5_reg                                                     0xB800FABC
#define  IMG_TAPCOEFF0_5_inst_addr                                               "0x002F"
#define  set_IMG_TAPCOEFF0_5_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_5_reg)=data)
#define  get_IMG_TAPCOEFF0_5_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_5_reg))
#define  IMG_TAPCOEFF0_5_coeff0_n1_shift                                         (16)
#define  IMG_TAPCOEFF0_5_coeff0_n_shift                                          (0)
#define  IMG_TAPCOEFF0_5_coeff0_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF0_5_coeff0_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF0_5_coeff0_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF0_5_coeff0_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF0_5_get_coeff0_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF0_5_get_coeff0_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF0_6                                                         0x1800FAC0
#define  IMG_TAPCOEFF0_6_reg_addr                                                "0xB800FAC0"
#define  IMG_TAPCOEFF0_6_reg                                                     0xB800FAC0
#define  IMG_TAPCOEFF0_6_inst_addr                                               "0x0030"
#define  set_IMG_TAPCOEFF0_6_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_6_reg)=data)
#define  get_IMG_TAPCOEFF0_6_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_6_reg))
#define  IMG_TAPCOEFF0_6_coeff0_n1_shift                                         (16)
#define  IMG_TAPCOEFF0_6_coeff0_n_shift                                          (0)
#define  IMG_TAPCOEFF0_6_coeff0_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF0_6_coeff0_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF0_6_coeff0_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF0_6_coeff0_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF0_6_get_coeff0_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF0_6_get_coeff0_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF0_7                                                         0x1800FAC4
#define  IMG_TAPCOEFF0_7_reg_addr                                                "0xB800FAC4"
#define  IMG_TAPCOEFF0_7_reg                                                     0xB800FAC4
#define  IMG_TAPCOEFF0_7_inst_addr                                               "0x0031"
#define  set_IMG_TAPCOEFF0_7_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_7_reg)=data)
#define  get_IMG_TAPCOEFF0_7_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_7_reg))
#define  IMG_TAPCOEFF0_7_coeff0_n1_shift                                         (16)
#define  IMG_TAPCOEFF0_7_coeff0_n_shift                                          (0)
#define  IMG_TAPCOEFF0_7_coeff0_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF0_7_coeff0_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF0_7_coeff0_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF0_7_coeff0_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF0_7_get_coeff0_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF0_7_get_coeff0_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF1_0                                                         0x1800FAC8
#define  IMG_TAPCOEFF1_0_reg_addr                                                "0xB800FAC8"
#define  IMG_TAPCOEFF1_0_reg                                                     0xB800FAC8
#define  IMG_TAPCOEFF1_0_inst_addr                                               "0x0032"
#define  set_IMG_TAPCOEFF1_0_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_0_reg)=data)
#define  get_IMG_TAPCOEFF1_0_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_0_reg))
#define  IMG_TAPCOEFF1_0_coeff1_n1_shift                                         (16)
#define  IMG_TAPCOEFF1_0_coeff1_n_shift                                          (0)
#define  IMG_TAPCOEFF1_0_coeff1_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF1_0_coeff1_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF1_0_coeff1_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF1_0_coeff1_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF1_0_get_coeff1_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF1_0_get_coeff1_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF1_1                                                         0x1800FACC
#define  IMG_TAPCOEFF1_1_reg_addr                                                "0xB800FACC"
#define  IMG_TAPCOEFF1_1_reg                                                     0xB800FACC
#define  IMG_TAPCOEFF1_1_inst_addr                                               "0x0033"
#define  set_IMG_TAPCOEFF1_1_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_1_reg)=data)
#define  get_IMG_TAPCOEFF1_1_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_1_reg))
#define  IMG_TAPCOEFF1_1_coeff1_n1_shift                                         (16)
#define  IMG_TAPCOEFF1_1_coeff1_n_shift                                          (0)
#define  IMG_TAPCOEFF1_1_coeff1_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF1_1_coeff1_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF1_1_coeff1_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF1_1_coeff1_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF1_1_get_coeff1_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF1_1_get_coeff1_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF1_2                                                         0x1800FAD0
#define  IMG_TAPCOEFF1_2_reg_addr                                                "0xB800FAD0"
#define  IMG_TAPCOEFF1_2_reg                                                     0xB800FAD0
#define  IMG_TAPCOEFF1_2_inst_addr                                               "0x0034"
#define  set_IMG_TAPCOEFF1_2_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_2_reg)=data)
#define  get_IMG_TAPCOEFF1_2_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_2_reg))
#define  IMG_TAPCOEFF1_2_coeff1_n1_shift                                         (16)
#define  IMG_TAPCOEFF1_2_coeff1_n_shift                                          (0)
#define  IMG_TAPCOEFF1_2_coeff1_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF1_2_coeff1_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF1_2_coeff1_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF1_2_coeff1_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF1_2_get_coeff1_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF1_2_get_coeff1_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF1_3                                                         0x1800FAD4
#define  IMG_TAPCOEFF1_3_reg_addr                                                "0xB800FAD4"
#define  IMG_TAPCOEFF1_3_reg                                                     0xB800FAD4
#define  IMG_TAPCOEFF1_3_inst_addr                                               "0x0035"
#define  set_IMG_TAPCOEFF1_3_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_3_reg)=data)
#define  get_IMG_TAPCOEFF1_3_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_3_reg))
#define  IMG_TAPCOEFF1_3_coeff1_n1_shift                                         (16)
#define  IMG_TAPCOEFF1_3_coeff1_n_shift                                          (0)
#define  IMG_TAPCOEFF1_3_coeff1_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF1_3_coeff1_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF1_3_coeff1_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF1_3_coeff1_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF1_3_get_coeff1_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF1_3_get_coeff1_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF1_4                                                         0x1800FAD8
#define  IMG_TAPCOEFF1_4_reg_addr                                                "0xB800FAD8"
#define  IMG_TAPCOEFF1_4_reg                                                     0xB800FAD8
#define  IMG_TAPCOEFF1_4_inst_addr                                               "0x0036"
#define  set_IMG_TAPCOEFF1_4_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_4_reg)=data)
#define  get_IMG_TAPCOEFF1_4_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_4_reg))
#define  IMG_TAPCOEFF1_4_coeff1_n1_shift                                         (16)
#define  IMG_TAPCOEFF1_4_coeff1_n_shift                                          (0)
#define  IMG_TAPCOEFF1_4_coeff1_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF1_4_coeff1_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF1_4_coeff1_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF1_4_coeff1_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF1_4_get_coeff1_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF1_4_get_coeff1_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF1_5                                                         0x1800FADC
#define  IMG_TAPCOEFF1_5_reg_addr                                                "0xB800FADC"
#define  IMG_TAPCOEFF1_5_reg                                                     0xB800FADC
#define  IMG_TAPCOEFF1_5_inst_addr                                               "0x0037"
#define  set_IMG_TAPCOEFF1_5_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_5_reg)=data)
#define  get_IMG_TAPCOEFF1_5_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_5_reg))
#define  IMG_TAPCOEFF1_5_coeff1_n1_shift                                         (16)
#define  IMG_TAPCOEFF1_5_coeff1_n_shift                                          (0)
#define  IMG_TAPCOEFF1_5_coeff1_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF1_5_coeff1_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF1_5_coeff1_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF1_5_coeff1_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF1_5_get_coeff1_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF1_5_get_coeff1_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF1_6                                                         0x1800FAE0
#define  IMG_TAPCOEFF1_6_reg_addr                                                "0xB800FAE0"
#define  IMG_TAPCOEFF1_6_reg                                                     0xB800FAE0
#define  IMG_TAPCOEFF1_6_inst_addr                                               "0x0038"
#define  set_IMG_TAPCOEFF1_6_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_6_reg)=data)
#define  get_IMG_TAPCOEFF1_6_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_6_reg))
#define  IMG_TAPCOEFF1_6_coeff1_n1_shift                                         (16)
#define  IMG_TAPCOEFF1_6_coeff1_n_shift                                          (0)
#define  IMG_TAPCOEFF1_6_coeff1_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF1_6_coeff1_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF1_6_coeff1_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF1_6_coeff1_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF1_6_get_coeff1_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF1_6_get_coeff1_n(data)                                      (0x00000FFF&(data))

#define  IMG_TAPCOEFF1_7                                                         0x1800FAE4
#define  IMG_TAPCOEFF1_7_reg_addr                                                "0xB800FAE4"
#define  IMG_TAPCOEFF1_7_reg                                                     0xB800FAE4
#define  IMG_TAPCOEFF1_7_inst_addr                                               "0x0039"
#define  set_IMG_TAPCOEFF1_7_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_7_reg)=data)
#define  get_IMG_TAPCOEFF1_7_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_7_reg))
#define  IMG_TAPCOEFF1_7_coeff1_n1_shift                                         (16)
#define  IMG_TAPCOEFF1_7_coeff1_n_shift                                          (0)
#define  IMG_TAPCOEFF1_7_coeff1_n1_mask                                          (0x0FFF0000)
#define  IMG_TAPCOEFF1_7_coeff1_n_mask                                           (0x00000FFF)
#define  IMG_TAPCOEFF1_7_coeff1_n1(data)                                         (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF1_7_coeff1_n(data)                                          (0x00000FFF&(data))
#define  IMG_TAPCOEFF1_7_get_coeff1_n1(data)                                     ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF1_7_get_coeff1_n(data)                                      (0x00000FFF&(data))

#define  IMG_PPNR_SADY                                                           0x1800FAE8
#define  IMG_PPNR_SADY_reg_addr                                                  "0xB800FAE8"
#define  IMG_PPNR_SADY_reg                                                       0xB800FAE8
#define  IMG_PPNR_SADY_inst_addr                                                 "0x003A"
#define  set_IMG_PPNR_SADY_reg(data)                                             (*((volatile unsigned int*)IMG_PPNR_SADY_reg)=data)
#define  get_IMG_PPNR_SADY_reg                                                   (*((volatile unsigned int*)IMG_PPNR_SADY_reg))
#define  IMG_PPNR_SADY_maxvalue_shift                                            (24)
#define  IMG_PPNR_SADY_minvalue_shift                                            (16)
#define  IMG_PPNR_SADY_minsad_shift                                              (0)
#define  IMG_PPNR_SADY_maxvalue_mask                                             (0xFF000000)
#define  IMG_PPNR_SADY_minvalue_mask                                             (0x00FF0000)
#define  IMG_PPNR_SADY_minsad_mask                                               (0x0000FFFF)
#define  IMG_PPNR_SADY_maxvalue(data)                                            (0xFF000000&((data)<<24))
#define  IMG_PPNR_SADY_minvalue(data)                                            (0x00FF0000&((data)<<16))
#define  IMG_PPNR_SADY_minsad(data)                                              (0x0000FFFF&(data))
#define  IMG_PPNR_SADY_get_maxvalue(data)                                        ((0xFF000000&(data))>>24)
#define  IMG_PPNR_SADY_get_minvalue(data)                                        ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_SADY_get_minsad(data)                                          (0x0000FFFF&(data))

#define  IMG_PPNR_SADCb                                                          0x1800FAEC
#define  IMG_PPNR_SADCb_reg_addr                                                 "0xB800FAEC"
#define  IMG_PPNR_SADCb_reg                                                      0xB800FAEC
#define  IMG_PPNR_SADCb_inst_addr                                                "0x003B"
#define  set_IMG_PPNR_SADCb_reg(data)                                            (*((volatile unsigned int*)IMG_PPNR_SADCb_reg)=data)
#define  get_IMG_PPNR_SADCb_reg                                                  (*((volatile unsigned int*)IMG_PPNR_SADCb_reg))
#define  IMG_PPNR_SADCb_maxvalue_shift                                           (24)
#define  IMG_PPNR_SADCb_minvalue_shift                                           (16)
#define  IMG_PPNR_SADCb_minsad_shift                                             (0)
#define  IMG_PPNR_SADCb_maxvalue_mask                                            (0xFF000000)
#define  IMG_PPNR_SADCb_minvalue_mask                                            (0x00FF0000)
#define  IMG_PPNR_SADCb_minsad_mask                                              (0x0000FFFF)
#define  IMG_PPNR_SADCb_maxvalue(data)                                           (0xFF000000&((data)<<24))
#define  IMG_PPNR_SADCb_minvalue(data)                                           (0x00FF0000&((data)<<16))
#define  IMG_PPNR_SADCb_minsad(data)                                             (0x0000FFFF&(data))
#define  IMG_PPNR_SADCb_get_maxvalue(data)                                       ((0xFF000000&(data))>>24)
#define  IMG_PPNR_SADCb_get_minvalue(data)                                       ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_SADCb_get_minsad(data)                                         (0x0000FFFF&(data))

#define  IMG_PPNR_SADCr                                                          0x1800FAF0
#define  IMG_PPNR_SADCr_reg_addr                                                 "0xB800FAF0"
#define  IMG_PPNR_SADCr_reg                                                      0xB800FAF0
#define  IMG_PPNR_SADCr_inst_addr                                                "0x003C"
#define  set_IMG_PPNR_SADCr_reg(data)                                            (*((volatile unsigned int*)IMG_PPNR_SADCr_reg)=data)
#define  get_IMG_PPNR_SADCr_reg                                                  (*((volatile unsigned int*)IMG_PPNR_SADCr_reg))
#define  IMG_PPNR_SADCr_maxvalue_shift                                           (24)
#define  IMG_PPNR_SADCr_minvalue_shift                                           (16)
#define  IMG_PPNR_SADCr_minsad_shift                                             (0)
#define  IMG_PPNR_SADCr_maxvalue_mask                                            (0xFF000000)
#define  IMG_PPNR_SADCr_minvalue_mask                                            (0x00FF0000)
#define  IMG_PPNR_SADCr_minsad_mask                                              (0x0000FFFF)
#define  IMG_PPNR_SADCr_maxvalue(data)                                           (0xFF000000&((data)<<24))
#define  IMG_PPNR_SADCr_minvalue(data)                                           (0x00FF0000&((data)<<16))
#define  IMG_PPNR_SADCr_minsad(data)                                             (0x0000FFFF&(data))
#define  IMG_PPNR_SADCr_get_maxvalue(data)                                       ((0xFF000000&(data))>>24)
#define  IMG_PPNR_SADCr_get_minvalue(data)                                       ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_SADCr_get_minsad(data)                                         (0x0000FFFF&(data))

#define  IMG_PPNR_THR_LUMA                                                       0x1800FAF4
#define  IMG_PPNR_THR_LUMA_reg_addr                                              "0xB800FAF4"
#define  IMG_PPNR_THR_LUMA_reg                                                   0xB800FAF4
#define  IMG_PPNR_THR_LUMA_inst_addr                                             "0x003D"
#define  set_IMG_PPNR_THR_LUMA_reg(data)                                         (*((volatile unsigned int*)IMG_PPNR_THR_LUMA_reg)=data)
#define  get_IMG_PPNR_THR_LUMA_reg                                               (*((volatile unsigned int*)IMG_PPNR_THR_LUMA_reg))
#define  IMG_PPNR_THR_LUMA_y_maxthr_shift                                        (8)
#define  IMG_PPNR_THR_LUMA_y_minthr_shift                                        (0)
#define  IMG_PPNR_THR_LUMA_y_maxthr_mask                                         (0x0000FF00)
#define  IMG_PPNR_THR_LUMA_y_minthr_mask                                         (0x000000FF)
#define  IMG_PPNR_THR_LUMA_y_maxthr(data)                                        (0x0000FF00&((data)<<8))
#define  IMG_PPNR_THR_LUMA_y_minthr(data)                                        (0x000000FF&(data))
#define  IMG_PPNR_THR_LUMA_get_y_maxthr(data)                                    ((0x0000FF00&(data))>>8)
#define  IMG_PPNR_THR_LUMA_get_y_minthr(data)                                    (0x000000FF&(data))

#define  IMG_PPNR_THR_CHROMA                                                     0x1800FAF8
#define  IMG_PPNR_THR_CHROMA_reg_addr                                            "0xB800FAF8"
#define  IMG_PPNR_THR_CHROMA_reg                                                 0xB800FAF8
#define  IMG_PPNR_THR_CHROMA_inst_addr                                           "0x003E"
#define  set_IMG_PPNR_THR_CHROMA_reg(data)                                       (*((volatile unsigned int*)IMG_PPNR_THR_CHROMA_reg)=data)
#define  get_IMG_PPNR_THR_CHROMA_reg                                             (*((volatile unsigned int*)IMG_PPNR_THR_CHROMA_reg))
#define  IMG_PPNR_THR_CHROMA_cb_maxthr_shift                                     (24)
#define  IMG_PPNR_THR_CHROMA_cb_minthr_shift                                     (16)
#define  IMG_PPNR_THR_CHROMA_cr_maxthr_shift                                     (8)
#define  IMG_PPNR_THR_CHROMA_cr_minthr_shift                                     (0)
#define  IMG_PPNR_THR_CHROMA_cb_maxthr_mask                                      (0xFF000000)
#define  IMG_PPNR_THR_CHROMA_cb_minthr_mask                                      (0x00FF0000)
#define  IMG_PPNR_THR_CHROMA_cr_maxthr_mask                                      (0x0000FF00)
#define  IMG_PPNR_THR_CHROMA_cr_minthr_mask                                      (0x000000FF)
#define  IMG_PPNR_THR_CHROMA_cb_maxthr(data)                                     (0xFF000000&((data)<<24))
#define  IMG_PPNR_THR_CHROMA_cb_minthr(data)                                     (0x00FF0000&((data)<<16))
#define  IMG_PPNR_THR_CHROMA_cr_maxthr(data)                                     (0x0000FF00&((data)<<8))
#define  IMG_PPNR_THR_CHROMA_cr_minthr(data)                                     (0x000000FF&(data))
#define  IMG_PPNR_THR_CHROMA_get_cb_maxthr(data)                                 ((0xFF000000&(data))>>24)
#define  IMG_PPNR_THR_CHROMA_get_cb_minthr(data)                                 ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_THR_CHROMA_get_cr_maxthr(data)                                 ((0x0000FF00&(data))>>8)
#define  IMG_PPNR_THR_CHROMA_get_cr_minthr(data)                                 (0x000000FF&(data))

#define  IMG_PPNR_SPATIAL_DIFF                                                   0x1800FAFC
#define  IMG_PPNR_SPATIAL_DIFF_reg_addr                                          "0xB800FAFC"
#define  IMG_PPNR_SPATIAL_DIFF_reg                                               0xB800FAFC
#define  IMG_PPNR_SPATIAL_DIFF_inst_addr                                         "0x003F"
#define  set_IMG_PPNR_SPATIAL_DIFF_reg(data)                                     (*((volatile unsigned int*)IMG_PPNR_SPATIAL_DIFF_reg)=data)
#define  get_IMG_PPNR_SPATIAL_DIFF_reg                                           (*((volatile unsigned int*)IMG_PPNR_SPATIAL_DIFF_reg))
#define  IMG_PPNR_SPATIAL_DIFF_t3_shift                                          (16)
#define  IMG_PPNR_SPATIAL_DIFF_t2_shift                                          (8)
#define  IMG_PPNR_SPATIAL_DIFF_t1_shift                                          (0)
#define  IMG_PPNR_SPATIAL_DIFF_t3_mask                                           (0x00FF0000)
#define  IMG_PPNR_SPATIAL_DIFF_t2_mask                                           (0x0000FF00)
#define  IMG_PPNR_SPATIAL_DIFF_t1_mask                                           (0x000000FF)
#define  IMG_PPNR_SPATIAL_DIFF_t3(data)                                          (0x00FF0000&((data)<<16))
#define  IMG_PPNR_SPATIAL_DIFF_t2(data)                                          (0x0000FF00&((data)<<8))
#define  IMG_PPNR_SPATIAL_DIFF_t1(data)                                          (0x000000FF&(data))
#define  IMG_PPNR_SPATIAL_DIFF_get_t3(data)                                      ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_SPATIAL_DIFF_get_t2(data)                                      ((0x0000FF00&(data))>>8)
#define  IMG_PPNR_SPATIAL_DIFF_get_t1(data)                                      (0x000000FF&(data))

#define  IMG_PPNR_TEMPORAL_DIFF                                                  0x1800FB00
#define  IMG_PPNR_TEMPORAL_DIFF_reg_addr                                         "0xB800FB00"
#define  IMG_PPNR_TEMPORAL_DIFF_reg                                              0xB800FB00
#define  IMG_PPNR_TEMPORAL_DIFF_inst_addr                                        "0x0040"
#define  set_IMG_PPNR_TEMPORAL_DIFF_reg(data)                                    (*((volatile unsigned int*)IMG_PPNR_TEMPORAL_DIFF_reg)=data)
#define  get_IMG_PPNR_TEMPORAL_DIFF_reg                                          (*((volatile unsigned int*)IMG_PPNR_TEMPORAL_DIFF_reg))
#define  IMG_PPNR_TEMPORAL_DIFF_t3_shift                                         (16)
#define  IMG_PPNR_TEMPORAL_DIFF_t2_shift                                         (8)
#define  IMG_PPNR_TEMPORAL_DIFF_t1_shift                                         (0)
#define  IMG_PPNR_TEMPORAL_DIFF_t3_mask                                          (0x00FF0000)
#define  IMG_PPNR_TEMPORAL_DIFF_t2_mask                                          (0x0000FF00)
#define  IMG_PPNR_TEMPORAL_DIFF_t1_mask                                          (0x000000FF)
#define  IMG_PPNR_TEMPORAL_DIFF_t3(data)                                         (0x00FF0000&((data)<<16))
#define  IMG_PPNR_TEMPORAL_DIFF_t2(data)                                         (0x0000FF00&((data)<<8))
#define  IMG_PPNR_TEMPORAL_DIFF_t1(data)                                         (0x000000FF&(data))
#define  IMG_PPNR_TEMPORAL_DIFF_get_t3(data)                                     ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_TEMPORAL_DIFF_get_t2(data)                                     ((0x0000FF00&(data))>>8)
#define  IMG_PPNR_TEMPORAL_DIFF_get_t1(data)                                     (0x000000FF&(data))

#define  IMG_PPNR_BLEND_LEVEL                                                    0x1800FB04
#define  IMG_PPNR_BLEND_LEVEL_reg_addr                                           "0xB800FB04"
#define  IMG_PPNR_BLEND_LEVEL_reg                                                0xB800FB04
#define  IMG_PPNR_BLEND_LEVEL_inst_addr                                          "0x0041"
#define  set_IMG_PPNR_BLEND_LEVEL_reg(data)                                      (*((volatile unsigned int*)IMG_PPNR_BLEND_LEVEL_reg)=data)
#define  get_IMG_PPNR_BLEND_LEVEL_reg                                            (*((volatile unsigned int*)IMG_PPNR_BLEND_LEVEL_reg))
#define  IMG_PPNR_BLEND_LEVEL_temporal_k2_shift                                  (24)
#define  IMG_PPNR_BLEND_LEVEL_temporal_k1_shift                                  (16)
#define  IMG_PPNR_BLEND_LEVEL_spatial_k2_shift                                   (8)
#define  IMG_PPNR_BLEND_LEVEL_spatial_k1_shift                                   (0)
#define  IMG_PPNR_BLEND_LEVEL_temporal_k2_mask                                   (0xFF000000)
#define  IMG_PPNR_BLEND_LEVEL_temporal_k1_mask                                   (0x00FF0000)
#define  IMG_PPNR_BLEND_LEVEL_spatial_k2_mask                                    (0x0000FF00)
#define  IMG_PPNR_BLEND_LEVEL_spatial_k1_mask                                    (0x000000FF)
#define  IMG_PPNR_BLEND_LEVEL_temporal_k2(data)                                  (0xFF000000&((data)<<24))
#define  IMG_PPNR_BLEND_LEVEL_temporal_k1(data)                                  (0x00FF0000&((data)<<16))
#define  IMG_PPNR_BLEND_LEVEL_spatial_k2(data)                                   (0x0000FF00&((data)<<8))
#define  IMG_PPNR_BLEND_LEVEL_spatial_k1(data)                                   (0x000000FF&(data))
#define  IMG_PPNR_BLEND_LEVEL_get_temporal_k2(data)                              ((0xFF000000&(data))>>24)
#define  IMG_PPNR_BLEND_LEVEL_get_temporal_k1(data)                              ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_BLEND_LEVEL_get_spatial_k2(data)                               ((0x0000FF00&(data))>>8)
#define  IMG_PPNR_BLEND_LEVEL_get_spatial_k1(data)                               (0x000000FF&(data))

#define  IMG_PPNR_SPATIAL_SLOP                                                   0x1800FB08
#define  IMG_PPNR_SPATIAL_SLOP_reg_addr                                          "0xB800FB08"
#define  IMG_PPNR_SPATIAL_SLOP_reg                                               0xB800FB08
#define  IMG_PPNR_SPATIAL_SLOP_inst_addr                                         "0x0042"
#define  set_IMG_PPNR_SPATIAL_SLOP_reg(data)                                     (*((volatile unsigned int*)IMG_PPNR_SPATIAL_SLOP_reg)=data)
#define  get_IMG_PPNR_SPATIAL_SLOP_reg                                           (*((volatile unsigned int*)IMG_PPNR_SPATIAL_SLOP_reg))
#define  IMG_PPNR_SPATIAL_SLOP_s2_shift                                          (16)
#define  IMG_PPNR_SPATIAL_SLOP_s1_shift                                          (0)
#define  IMG_PPNR_SPATIAL_SLOP_s2_mask                                           (0xFFFF0000)
#define  IMG_PPNR_SPATIAL_SLOP_s1_mask                                           (0x0000FFFF)
#define  IMG_PPNR_SPATIAL_SLOP_s2(data)                                          (0xFFFF0000&((data)<<16))
#define  IMG_PPNR_SPATIAL_SLOP_s1(data)                                          (0x0000FFFF&(data))
#define  IMG_PPNR_SPATIAL_SLOP_get_s2(data)                                      ((0xFFFF0000&(data))>>16)
#define  IMG_PPNR_SPATIAL_SLOP_get_s1(data)                                      (0x0000FFFF&(data))

#define  IMG_PPNR_TEMPORAL_SLOP                                                  0x1800FB0C
#define  IMG_PPNR_TEMPORAL_SLOP_reg_addr                                         "0xB800FB0C"
#define  IMG_PPNR_TEMPORAL_SLOP_reg                                              0xB800FB0C
#define  IMG_PPNR_TEMPORAL_SLOP_inst_addr                                        "0x0043"
#define  set_IMG_PPNR_TEMPORAL_SLOP_reg(data)                                    (*((volatile unsigned int*)IMG_PPNR_TEMPORAL_SLOP_reg)=data)
#define  get_IMG_PPNR_TEMPORAL_SLOP_reg                                          (*((volatile unsigned int*)IMG_PPNR_TEMPORAL_SLOP_reg))
#define  IMG_PPNR_TEMPORAL_SLOP_s2_shift                                         (16)
#define  IMG_PPNR_TEMPORAL_SLOP_s1_shift                                         (0)
#define  IMG_PPNR_TEMPORAL_SLOP_s2_mask                                          (0xFFFF0000)
#define  IMG_PPNR_TEMPORAL_SLOP_s1_mask                                          (0x0000FFFF)
#define  IMG_PPNR_TEMPORAL_SLOP_s2(data)                                         (0xFFFF0000&((data)<<16))
#define  IMG_PPNR_TEMPORAL_SLOP_s1(data)                                         (0x0000FFFF&(data))
#define  IMG_PPNR_TEMPORAL_SLOP_get_s2(data)                                     ((0xFFFF0000&(data))>>16)
#define  IMG_PPNR_TEMPORAL_SLOP_get_s1(data)                                     (0x0000FFFF&(data))

#define  IMG_HCOEF_0                                                             0x1800FB10
#define  IMG_HCOEF_0_reg_addr                                                    "0xB800FB10"
#define  IMG_HCOEF_0_reg                                                         0xB800FB10
#define  IMG_HCOEF_0_inst_addr                                                   "0x0044"
#define  set_IMG_HCOEF_0_reg(data)                                               (*((volatile unsigned int*)IMG_HCOEF_0_reg)=data)
#define  get_IMG_HCOEF_0_reg                                                     (*((volatile unsigned int*)IMG_HCOEF_0_reg))
#define  IMG_HCOEF_0_hcoef_1_shift                                               (14)
#define  IMG_HCOEF_0_hcoef_0_shift                                               (0)
#define  IMG_HCOEF_0_hcoef_1_mask                                                (0x0FFFC000)
#define  IMG_HCOEF_0_hcoef_0_mask                                                (0x00003FFF)
#define  IMG_HCOEF_0_hcoef_1(data)                                               (0x0FFFC000&((data)<<14))
#define  IMG_HCOEF_0_hcoef_0(data)                                               (0x00003FFF&(data))
#define  IMG_HCOEF_0_get_hcoef_1(data)                                           ((0x0FFFC000&(data))>>14)
#define  IMG_HCOEF_0_get_hcoef_0(data)                                           (0x00003FFF&(data))

#define  IMG_HCOEF_1                                                             0x1800FB14
#define  IMG_HCOEF_1_reg_addr                                                    "0xB800FB14"
#define  IMG_HCOEF_1_reg                                                         0xB800FB14
#define  IMG_HCOEF_1_inst_addr                                                   "0x0045"
#define  set_IMG_HCOEF_1_reg(data)                                               (*((volatile unsigned int*)IMG_HCOEF_1_reg)=data)
#define  get_IMG_HCOEF_1_reg                                                     (*((volatile unsigned int*)IMG_HCOEF_1_reg))
#define  IMG_HCOEF_1_hcoef_1_shift                                               (14)
#define  IMG_HCOEF_1_hcoef_0_shift                                               (0)
#define  IMG_HCOEF_1_hcoef_1_mask                                                (0x0FFFC000)
#define  IMG_HCOEF_1_hcoef_0_mask                                                (0x00003FFF)
#define  IMG_HCOEF_1_hcoef_1(data)                                               (0x0FFFC000&((data)<<14))
#define  IMG_HCOEF_1_hcoef_0(data)                                               (0x00003FFF&(data))
#define  IMG_HCOEF_1_get_hcoef_1(data)                                           ((0x0FFFC000&(data))>>14)
#define  IMG_HCOEF_1_get_hcoef_0(data)                                           (0x00003FFF&(data))

#define  IMG_HCOEF_2                                                             0x1800FB18
#define  IMG_HCOEF_2_reg_addr                                                    "0xB800FB18"
#define  IMG_HCOEF_2_reg                                                         0xB800FB18
#define  IMG_HCOEF_2_inst_addr                                                   "0x0046"
#define  set_IMG_HCOEF_2_reg(data)                                               (*((volatile unsigned int*)IMG_HCOEF_2_reg)=data)
#define  get_IMG_HCOEF_2_reg                                                     (*((volatile unsigned int*)IMG_HCOEF_2_reg))
#define  IMG_HCOEF_2_hcoef_1_shift                                               (14)
#define  IMG_HCOEF_2_hcoef_0_shift                                               (0)
#define  IMG_HCOEF_2_hcoef_1_mask                                                (0x0FFFC000)
#define  IMG_HCOEF_2_hcoef_0_mask                                                (0x00003FFF)
#define  IMG_HCOEF_2_hcoef_1(data)                                               (0x0FFFC000&((data)<<14))
#define  IMG_HCOEF_2_hcoef_0(data)                                               (0x00003FFF&(data))
#define  IMG_HCOEF_2_get_hcoef_1(data)                                           ((0x0FFFC000&(data))>>14)
#define  IMG_HCOEF_2_get_hcoef_0(data)                                           (0x00003FFF&(data))

#define  IMG_HCOEF_3                                                             0x1800FB1C
#define  IMG_HCOEF_3_reg_addr                                                    "0xB800FB1C"
#define  IMG_HCOEF_3_reg                                                         0xB800FB1C
#define  IMG_HCOEF_3_inst_addr                                                   "0x0047"
#define  set_IMG_HCOEF_3_reg(data)                                               (*((volatile unsigned int*)IMG_HCOEF_3_reg)=data)
#define  get_IMG_HCOEF_3_reg                                                     (*((volatile unsigned int*)IMG_HCOEF_3_reg))
#define  IMG_HCOEF_3_hcoef_1_shift                                               (14)
#define  IMG_HCOEF_3_hcoef_0_shift                                               (0)
#define  IMG_HCOEF_3_hcoef_1_mask                                                (0x0FFFC000)
#define  IMG_HCOEF_3_hcoef_0_mask                                                (0x00003FFF)
#define  IMG_HCOEF_3_hcoef_1(data)                                               (0x0FFFC000&((data)<<14))
#define  IMG_HCOEF_3_hcoef_0(data)                                               (0x00003FFF&(data))
#define  IMG_HCOEF_3_get_hcoef_1(data)                                           ((0x0FFFC000&(data))>>14)
#define  IMG_HCOEF_3_get_hcoef_0(data)                                           (0x00003FFF&(data))

#define  IMG_VCOEF_0                                                             0x1800FB20
#define  IMG_VCOEF_0_reg_addr                                                    "0xB800FB20"
#define  IMG_VCOEF_0_reg                                                         0xB800FB20
#define  IMG_VCOEF_0_inst_addr                                                   "0x0048"
#define  set_IMG_VCOEF_0_reg(data)                                               (*((volatile unsigned int*)IMG_VCOEF_0_reg)=data)
#define  get_IMG_VCOEF_0_reg                                                     (*((volatile unsigned int*)IMG_VCOEF_0_reg))
#define  IMG_VCOEF_0_vcoef_1_shift                                               (14)
#define  IMG_VCOEF_0_vcoef_0_shift                                               (0)
#define  IMG_VCOEF_0_vcoef_1_mask                                                (0x0FFFC000)
#define  IMG_VCOEF_0_vcoef_0_mask                                                (0x00003FFF)
#define  IMG_VCOEF_0_vcoef_1(data)                                               (0x0FFFC000&((data)<<14))
#define  IMG_VCOEF_0_vcoef_0(data)                                               (0x00003FFF&(data))
#define  IMG_VCOEF_0_get_vcoef_1(data)                                           ((0x0FFFC000&(data))>>14)
#define  IMG_VCOEF_0_get_vcoef_0(data)                                           (0x00003FFF&(data))

#define  IMG_VCOEF_1                                                             0x1800FB24
#define  IMG_VCOEF_1_reg_addr                                                    "0xB800FB24"
#define  IMG_VCOEF_1_reg                                                         0xB800FB24
#define  IMG_VCOEF_1_inst_addr                                                   "0x0049"
#define  set_IMG_VCOEF_1_reg(data)                                               (*((volatile unsigned int*)IMG_VCOEF_1_reg)=data)
#define  get_IMG_VCOEF_1_reg                                                     (*((volatile unsigned int*)IMG_VCOEF_1_reg))
#define  IMG_VCOEF_1_vcoef_1_shift                                               (14)
#define  IMG_VCOEF_1_vcoef_0_shift                                               (0)
#define  IMG_VCOEF_1_vcoef_1_mask                                                (0x0FFFC000)
#define  IMG_VCOEF_1_vcoef_0_mask                                                (0x00003FFF)
#define  IMG_VCOEF_1_vcoef_1(data)                                               (0x0FFFC000&((data)<<14))
#define  IMG_VCOEF_1_vcoef_0(data)                                               (0x00003FFF&(data))
#define  IMG_VCOEF_1_get_vcoef_1(data)                                           ((0x0FFFC000&(data))>>14)
#define  IMG_VCOEF_1_get_vcoef_0(data)                                           (0x00003FFF&(data))

#define  IMG_MBV                                                                 0x1800FB28
#define  IMG_MBV_reg_addr                                                        "0xB800FB28"
#define  IMG_MBV_reg                                                             0xB800FB28
#define  IMG_MBV_inst_addr                                                       "0x004A"
#define  set_IMG_MBV_reg(data)                                                   (*((volatile unsigned int*)IMG_MBV_reg)=data)
#define  get_IMG_MBV_reg                                                         (*((volatile unsigned int*)IMG_MBV_reg))
#define  IMG_MBV_mbvariance_shift                                                (0)
#define  IMG_MBV_mbvariance_mask                                                 (0x003FFFFF)
#define  IMG_MBV_mbvariance(data)                                                (0x003FFFFF&(data))
#define  IMG_MBV_get_mbvariance(data)                                            (0x003FFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IMG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  dering_dbg_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  dbg_group2_sel:5;
        RBus_UInt32  dbg_group1_sel:5;
        RBus_UInt32  dbg_out_en:1;
        RBus_UInt32  res3:8;
    };
}img_dbg_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  chroma_enable:1;
        RBus_UInt32  luma_enable:1;
    };
}img_dering_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  filt_prec:2;
    };
}img_filt_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  init_value:10;
    };
}img_filt_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  rcrpr:1;
        RBus_UInt32  color_cr:8;
        RBus_UInt32  color_cb:8;
        RBus_UInt32  color_y:8;
        RBus_UInt32  fill_mode:2;
    };
}img_rmrpr_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  m:4;
        RBus_UInt32  pixel_offset:13;
    };
}img_rmrpr_par_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ax:32;
    };
}img_rmrpr_ax_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ay:32;
    };
}img_rmrpr_ay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ax_inc:32;
    };
}img_rmrpr_axinc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  picmb_h:8;
        RBus_UInt32  picmb_w:9;
    };
}img_rmrpr_picinfo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  basea:10;
    };
}img_basea_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  offseta:9;
    };
}img_offseta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  init_phase:20;
    };
}img_phase_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  phase_inc:24;
    };
}img_phase_inc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  final_phase:27;
    };
}img_phase_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coeff0_n1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  coeff0_n:12;
    };
}img_tapcoeff0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coeff1_n1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  coeff1_n:12;
    };
}img_tapcoeff1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxvalue:8;
        RBus_UInt32  minvalue:8;
        RBus_UInt32  minsad:16;
    };
}img_ppnr_sady_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxvalue:8;
        RBus_UInt32  minvalue:8;
        RBus_UInt32  minsad:16;
    };
}img_ppnr_sadcb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxvalue:8;
        RBus_UInt32  minvalue:8;
        RBus_UInt32  minsad:16;
    };
}img_ppnr_sadcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  y_maxthr:8;
        RBus_UInt32  y_minthr:8;
    };
}img_ppnr_thr_luma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cb_maxthr:8;
        RBus_UInt32  cb_minthr:8;
        RBus_UInt32  cr_maxthr:8;
        RBus_UInt32  cr_minthr:8;
    };
}img_ppnr_thr_chroma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  t3:8;
        RBus_UInt32  t2:8;
        RBus_UInt32  t1:8;
    };
}img_ppnr_spatial_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  t3:8;
        RBus_UInt32  t2:8;
        RBus_UInt32  t1:8;
    };
}img_ppnr_temporal_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  temporal_k2:8;
        RBus_UInt32  temporal_k1:8;
        RBus_UInt32  spatial_k2:8;
        RBus_UInt32  spatial_k1:8;
    };
}img_ppnr_blend_level_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2:16;
        RBus_UInt32  s1:16;
    };
}img_ppnr_spatial_slop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2:16;
        RBus_UInt32  s1:16;
    };
}img_ppnr_temporal_slop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hcoef_1:14;
        RBus_UInt32  hcoef_0:14;
    };
}img_hcoef_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vcoef_1:14;
        RBus_UInt32  vcoef_0:14;
    };
}img_vcoef_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  mbvariance:22;
    };
}img_mbv_RBUS;

#else //apply LITTLE_ENDIAN

//======IMG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  dbg_out_en:1;
        RBus_UInt32  dbg_group1_sel:5;
        RBus_UInt32  dbg_group2_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  dering_dbg_sel:3;
        RBus_UInt32  res3:9;
    };
}img_dbg_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  luma_enable:1;
        RBus_UInt32  chroma_enable:1;
        RBus_UInt32  res1:30;
    };
}img_dering_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filt_prec:2;
        RBus_UInt32  res1:30;
    };
}img_filt_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  init_value:10;
        RBus_UInt32  res1:22;
    };
}img_filt_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fill_mode:2;
        RBus_UInt32  color_y:8;
        RBus_UInt32  color_cb:8;
        RBus_UInt32  color_cr:8;
        RBus_UInt32  rcrpr:1;
        RBus_UInt32  res1:5;
    };
}img_rmrpr_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pixel_offset:13;
        RBus_UInt32  m:4;
        RBus_UInt32  res1:15;
    };
}img_rmrpr_par_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ax:32;
    };
}img_rmrpr_ax_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ay:32;
    };
}img_rmrpr_ay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ax_inc:32;
    };
}img_rmrpr_axinc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  picmb_w:9;
        RBus_UInt32  picmb_h:8;
        RBus_UInt32  res1:15;
    };
}img_rmrpr_picinfo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  basea:10;
        RBus_UInt32  res1:22;
    };
}img_basea_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  offseta:9;
        RBus_UInt32  res1:23;
    };
}img_offseta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  init_phase:20;
        RBus_UInt32  res1:12;
    };
}img_phase_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  phase_inc:24;
        RBus_UInt32  res1:8;
    };
}img_phase_inc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  final_phase:27;
        RBus_UInt32  res1:5;
    };
}img_phase_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coeff0_n:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  coeff0_n1:12;
        RBus_UInt32  res2:4;
    };
}img_tapcoeff0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coeff1_n:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  coeff1_n1:12;
        RBus_UInt32  res2:4;
    };
}img_tapcoeff1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  minsad:16;
        RBus_UInt32  minvalue:8;
        RBus_UInt32  maxvalue:8;
    };
}img_ppnr_sady_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  minsad:16;
        RBus_UInt32  minvalue:8;
        RBus_UInt32  maxvalue:8;
    };
}img_ppnr_sadcb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  minsad:16;
        RBus_UInt32  minvalue:8;
        RBus_UInt32  maxvalue:8;
    };
}img_ppnr_sadcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_minthr:8;
        RBus_UInt32  y_maxthr:8;
        RBus_UInt32  res1:16;
    };
}img_ppnr_thr_luma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_minthr:8;
        RBus_UInt32  cr_maxthr:8;
        RBus_UInt32  cb_minthr:8;
        RBus_UInt32  cb_maxthr:8;
    };
}img_ppnr_thr_chroma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t1:8;
        RBus_UInt32  t2:8;
        RBus_UInt32  t3:8;
        RBus_UInt32  res1:8;
    };
}img_ppnr_spatial_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t1:8;
        RBus_UInt32  t2:8;
        RBus_UInt32  t3:8;
        RBus_UInt32  res1:8;
    };
}img_ppnr_temporal_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spatial_k1:8;
        RBus_UInt32  spatial_k2:8;
        RBus_UInt32  temporal_k1:8;
        RBus_UInt32  temporal_k2:8;
    };
}img_ppnr_blend_level_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:16;
        RBus_UInt32  s2:16;
    };
}img_ppnr_spatial_slop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:16;
        RBus_UInt32  s2:16;
    };
}img_ppnr_temporal_slop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcoef_0:14;
        RBus_UInt32  hcoef_1:14;
        RBus_UInt32  res1:4;
    };
}img_hcoef_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcoef_0:14;
        RBus_UInt32  vcoef_1:14;
        RBus_UInt32  res1:4;
    };
}img_vcoef_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbvariance:22;
        RBus_UInt32  res1:10;
    };
}img_mbv_RBUS;




#endif 


#endif 
