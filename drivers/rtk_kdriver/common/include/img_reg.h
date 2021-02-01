/**
* @file rbusImgReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/8/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IMG_REG_H_
#define _RBUS_IMG_REG_H_

#include "rbusTypes.h"



//  IMG Register Address
#define  IMG_DBG_CNTL                                                            0x1800FA00
#define  IMG_DBG_CNTL_reg_addr                                                   "0xB800FA00"
#define  IMG_DBG_CNTL_reg                                                        0xB800FA00
#define  IMG_DBG_CNTL_inst_addr                                                  "0x0000"
#define  IMG_DBG_CNTL_inst_adr                                                   "0x0080"
#define  IMG_DBG_CNTL_inst                                                       0x0080
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
#define  IMG_DBG_CNTL_dering_dbg_sel_src(data)                                   ((0x00700000&(data))>>20)
#define  IMG_DBG_CNTL_dbg_group2_sel_src(data)                                   ((0x0007C000&(data))>>14)
#define  IMG_DBG_CNTL_dbg_group1_sel_src(data)                                   ((0x00003E00&(data))>>9)
#define  IMG_DBG_CNTL_dbg_out_en_src(data)                                       ((0x00000100&(data))>>8)

#define  IMG_DERING_CNTL                                                         0x1800FA04
#define  IMG_DERING_CNTL_reg_addr                                                "0xB800FA04"
#define  IMG_DERING_CNTL_reg                                                     0xB800FA04
#define  IMG_DERING_CNTL_inst_addr                                               "0x0001"
#define  IMG_DERING_CNTL_inst_adr                                                "0x0081"
#define  IMG_DERING_CNTL_inst                                                    0x0081
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
#define  IMG_DERING_CNTL_chroma_enable_src(data)                                 ((0x00000002&(data))>>1)
#define  IMG_DERING_CNTL_luma_enable_src(data)                                   (0x00000001&(data))

#define  IMG_FILT_CNTL                                                           0x1800FA08
#define  IMG_FILT_CNTL_reg_addr                                                  "0xB800FA08"
#define  IMG_FILT_CNTL_reg                                                       0xB800FA08
#define  IMG_FILT_CNTL_inst_addr                                                 "0x0002"
#define  IMG_FILT_CNTL_inst_adr                                                  "0x0082"
#define  IMG_FILT_CNTL_inst                                                      0x0082
#define  set_IMG_FILT_CNTL_reg(data)                                             (*((volatile unsigned int*)IMG_FILT_CNTL_reg)=data)
#define  get_IMG_FILT_CNTL_reg                                                   (*((volatile unsigned int*)IMG_FILT_CNTL_reg))
#define  IMG_FILT_CNTL_filt_prec_shift                                           (0)
#define  IMG_FILT_CNTL_filt_prec_mask                                            (0x00000003)
#define  IMG_FILT_CNTL_filt_prec(data)                                           (0x00000003&(data))
#define  IMG_FILT_CNTL_get_filt_prec(data)                                       (0x00000003&(data))
#define  IMG_FILT_CNTL_filt_prec_src(data)                                       (0x00000003&(data))

#define  IMG_FILT_INIT                                                           0x1800FA0C
#define  IMG_FILT_INIT_reg_addr                                                  "0xB800FA0C"
#define  IMG_FILT_INIT_reg                                                       0xB800FA0C
#define  IMG_FILT_INIT_inst_addr                                                 "0x0003"
#define  IMG_FILT_INIT_inst_adr                                                  "0x0083"
#define  IMG_FILT_INIT_inst                                                      0x0083
#define  set_IMG_FILT_INIT_reg(data)                                             (*((volatile unsigned int*)IMG_FILT_INIT_reg)=data)
#define  get_IMG_FILT_INIT_reg                                                   (*((volatile unsigned int*)IMG_FILT_INIT_reg))
#define  IMG_FILT_INIT_init_value_shift                                          (0)
#define  IMG_FILT_INIT_init_value_mask                                           (0x000003FF)
#define  IMG_FILT_INIT_init_value(data)                                          (0x000003FF&(data))
#define  IMG_FILT_INIT_get_init_value(data)                                      (0x000003FF&(data))
#define  IMG_FILT_INIT_init_value_src(data)                                      (0x000003FF&(data))

#define  IMG_RMRPR_CNTL                                                          0x1800FA10
#define  IMG_RMRPR_CNTL_reg_addr                                                 "0xB800FA10"
#define  IMG_RMRPR_CNTL_reg                                                      0xB800FA10
#define  IMG_RMRPR_CNTL_inst_addr                                                "0x0004"
#define  IMG_RMRPR_CNTL_inst_adr                                                 "0x0084"
#define  IMG_RMRPR_CNTL_inst                                                     0x0084
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
#define  IMG_RMRPR_CNTL_rcrpr_src(data)                                          ((0x04000000&(data))>>26)
#define  IMG_RMRPR_CNTL_color_cr_src(data)                                       ((0x03FC0000&(data))>>18)
#define  IMG_RMRPR_CNTL_color_cb_src(data)                                       ((0x0003FC00&(data))>>10)
#define  IMG_RMRPR_CNTL_color_y_src(data)                                        ((0x000003FC&(data))>>2)
#define  IMG_RMRPR_CNTL_fill_mode_src(data)                                      (0x00000003&(data))

#define  IMG_RMRPR_PAR                                                           0x1800FA14
#define  IMG_RMRPR_PAR_reg_addr                                                  "0xB800FA14"
#define  IMG_RMRPR_PAR_reg                                                       0xB800FA14
#define  IMG_RMRPR_PAR_inst_addr                                                 "0x0005"
#define  IMG_RMRPR_PAR_inst_adr                                                  "0x0085"
#define  IMG_RMRPR_PAR_inst                                                      0x0085
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
#define  IMG_RMRPR_PAR_m_src(data)                                               ((0x0001E000&(data))>>13)
#define  IMG_RMRPR_PAR_pixel_offset_src(data)                                    (0x00001FFF&(data))

#define  IMG_RMRPR_AX                                                            0x1800FA18
#define  IMG_RMRPR_AX_reg_addr                                                   "0xB800FA18"
#define  IMG_RMRPR_AX_reg                                                        0xB800FA18
#define  IMG_RMRPR_AX_inst_addr                                                  "0x0006"
#define  IMG_RMRPR_AX_inst_adr                                                   "0x0086"
#define  IMG_RMRPR_AX_inst                                                       0x0086
#define  set_IMG_RMRPR_AX_reg(data)                                              (*((volatile unsigned int*)IMG_RMRPR_AX_reg)=data)
#define  get_IMG_RMRPR_AX_reg                                                    (*((volatile unsigned int*)IMG_RMRPR_AX_reg))
#define  IMG_RMRPR_AX_ax_shift                                                   (0)
#define  IMG_RMRPR_AX_ax_mask                                                    (0xFFFFFFFF)
#define  IMG_RMRPR_AX_ax(data)                                                   (0xFFFFFFFF&(data))
#define  IMG_RMRPR_AX_get_ax(data)                                               (0xFFFFFFFF&(data))
#define  IMG_RMRPR_AX_ax_src(data)                                               (0xFFFFFFFF&(data))

#define  IMG_RMRPR_AY                                                            0x1800FA1C
#define  IMG_RMRPR_AY_reg_addr                                                   "0xB800FA1C"
#define  IMG_RMRPR_AY_reg                                                        0xB800FA1C
#define  IMG_RMRPR_AY_inst_addr                                                  "0x0007"
#define  IMG_RMRPR_AY_inst_adr                                                   "0x0087"
#define  IMG_RMRPR_AY_inst                                                       0x0087
#define  set_IMG_RMRPR_AY_reg(data)                                              (*((volatile unsigned int*)IMG_RMRPR_AY_reg)=data)
#define  get_IMG_RMRPR_AY_reg                                                    (*((volatile unsigned int*)IMG_RMRPR_AY_reg))
#define  IMG_RMRPR_AY_ay_shift                                                   (0)
#define  IMG_RMRPR_AY_ay_mask                                                    (0xFFFFFFFF)
#define  IMG_RMRPR_AY_ay(data)                                                   (0xFFFFFFFF&(data))
#define  IMG_RMRPR_AY_get_ay(data)                                               (0xFFFFFFFF&(data))
#define  IMG_RMRPR_AY_ay_src(data)                                               (0xFFFFFFFF&(data))

#define  IMG_RMRPR_AXINC                                                         0x1800FA20
#define  IMG_RMRPR_AXINC_reg_addr                                                "0xB800FA20"
#define  IMG_RMRPR_AXINC_reg                                                     0xB800FA20
#define  IMG_RMRPR_AXINC_inst_addr                                               "0x0008"
#define  IMG_RMRPR_AXINC_inst_adr                                                "0x0088"
#define  IMG_RMRPR_AXINC_inst                                                    0x0088
#define  set_IMG_RMRPR_AXINC_reg(data)                                           (*((volatile unsigned int*)IMG_RMRPR_AXINC_reg)=data)
#define  get_IMG_RMRPR_AXINC_reg                                                 (*((volatile unsigned int*)IMG_RMRPR_AXINC_reg))
#define  IMG_RMRPR_AXINC_ax_inc_shift                                            (0)
#define  IMG_RMRPR_AXINC_ax_inc_mask                                             (0xFFFFFFFF)
#define  IMG_RMRPR_AXINC_ax_inc(data)                                            (0xFFFFFFFF&(data))
#define  IMG_RMRPR_AXINC_get_ax_inc(data)                                        (0xFFFFFFFF&(data))
#define  IMG_RMRPR_AXINC_ax_inc_src(data)                                        (0xFFFFFFFF&(data))

#define  IMG_RMRPR_PICINFO                                                       0x1800FA24
#define  IMG_RMRPR_PICINFO_reg_addr                                              "0xB800FA24"
#define  IMG_RMRPR_PICINFO_reg                                                   0xB800FA24
#define  IMG_RMRPR_PICINFO_inst_addr                                             "0x0009"
#define  IMG_RMRPR_PICINFO_inst_adr                                              "0x0089"
#define  IMG_RMRPR_PICINFO_inst                                                  0x0089
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
#define  IMG_RMRPR_PICINFO_picmb_h_src(data)                                     ((0x0001FE00&(data))>>9)
#define  IMG_RMRPR_PICINFO_picmb_w_src(data)                                     (0x000001FF&(data))

#define  IMG_BASEA_0                                                             0x1800FA28
#define  IMG_BASEA_0_reg_addr                                                    "0xB800FA28"
#define  IMG_BASEA_0_reg                                                         0xB800FA28
#define  IMG_BASEA_0_inst_addr                                                   "0x000A"
#define  IMG_BASEA_0_inst_adr                                                    "0x008A"
#define  IMG_BASEA_0_inst                                                        0x008A
#define  set_IMG_BASEA_0_reg(data)                                               (*((volatile unsigned int*)IMG_BASEA_0_reg)=data)
#define  get_IMG_BASEA_0_reg                                                     (*((volatile unsigned int*)IMG_BASEA_0_reg))
#define  IMG_BASEA_basea_shift                                                   (0)
#define  IMG_BASEA_basea_mask                                                    (0x000003FF)
#define  IMG_BASEA_basea(data)                                                   (0x000003FF&(data))
#define  IMG_BASEA_get_basea(data)                                               (0x000003FF&(data))
#define  IMG_BASEA_basea_src(data)                                               (0x000003FF&(data))

#define  IMG_BASEA_1                                                             0x1800FA2C
#define  IMG_BASEA_1_reg_addr                                                    "0xB800FA2C"
#define  IMG_BASEA_1_reg                                                         0xB800FA2C
#define  IMG_BASEA_1_inst_addr                                                   "0x000B"
#define  IMG_BASEA_1_inst_adr                                                    "0x008B"
#define  IMG_BASEA_1_inst                                                        0x008B
#define  set_IMG_BASEA_1_reg(data)                                               (*((volatile unsigned int*)IMG_BASEA_1_reg)=data)
#define  get_IMG_BASEA_1_reg                                                     (*((volatile unsigned int*)IMG_BASEA_1_reg))

#define  IMG_BASEA_2                                                             0x1800FA30
#define  IMG_BASEA_2_reg_addr                                                    "0xB800FA30"
#define  IMG_BASEA_2_reg                                                         0xB800FA30
#define  IMG_BASEA_2_inst_addr                                                   "0x000C"
#define  IMG_BASEA_2_inst_adr                                                    "0x008C"
#define  IMG_BASEA_2_inst                                                        0x008C
#define  set_IMG_BASEA_2_reg(data)                                               (*((volatile unsigned int*)IMG_BASEA_2_reg)=data)
#define  get_IMG_BASEA_2_reg                                                     (*((volatile unsigned int*)IMG_BASEA_2_reg))

#define  IMG_BASEA_3                                                             0x1800FA34
#define  IMG_BASEA_3_reg_addr                                                    "0xB800FA34"
#define  IMG_BASEA_3_reg                                                         0xB800FA34
#define  IMG_BASEA_3_inst_addr                                                   "0x000D"
#define  IMG_BASEA_3_inst_adr                                                    "0x008D"
#define  IMG_BASEA_3_inst                                                        0x008D
#define  set_IMG_BASEA_3_reg(data)                                               (*((volatile unsigned int*)IMG_BASEA_3_reg)=data)
#define  get_IMG_BASEA_3_reg                                                     (*((volatile unsigned int*)IMG_BASEA_3_reg))

#define  IMG_OFFSETA_0                                                           0x1800FA38
#define  IMG_OFFSETA_0_reg_addr                                                  "0xB800FA38"
#define  IMG_OFFSETA_0_reg                                                       0xB800FA38
#define  IMG_OFFSETA_0_inst_addr                                                 "0x000E"
#define  IMG_OFFSETA_0_inst_adr                                                  "0x008E"
#define  IMG_OFFSETA_0_inst                                                      0x008E
#define  set_IMG_OFFSETA_0_reg(data)                                             (*((volatile unsigned int*)IMG_OFFSETA_0_reg)=data)
#define  get_IMG_OFFSETA_0_reg                                                   (*((volatile unsigned int*)IMG_OFFSETA_0_reg))
#define  IMG_OFFSETA_offseta_shift                                               (0)
#define  IMG_OFFSETA_offseta_mask                                                (0x000001FF)
#define  IMG_OFFSETA_offseta(data)                                               (0x000001FF&(data))
#define  IMG_OFFSETA_get_offseta(data)                                           (0x000001FF&(data))
#define  IMG_OFFSETA_offseta_src(data)                                           (0x000001FF&(data))

#define  IMG_OFFSETA_1                                                           0x1800FA3C
#define  IMG_OFFSETA_1_reg_addr                                                  "0xB800FA3C"
#define  IMG_OFFSETA_1_reg                                                       0xB800FA3C
#define  IMG_OFFSETA_1_inst_addr                                                 "0x000F"
#define  IMG_OFFSETA_1_inst_adr                                                  "0x008F"
#define  IMG_OFFSETA_1_inst                                                      0x008F
#define  set_IMG_OFFSETA_1_reg(data)                                             (*((volatile unsigned int*)IMG_OFFSETA_1_reg)=data)
#define  get_IMG_OFFSETA_1_reg                                                   (*((volatile unsigned int*)IMG_OFFSETA_1_reg))

#define  IMG_OFFSETA_2                                                           0x1800FA40
#define  IMG_OFFSETA_2_reg_addr                                                  "0xB800FA40"
#define  IMG_OFFSETA_2_reg                                                       0xB800FA40
#define  IMG_OFFSETA_2_inst_addr                                                 "0x0010"
#define  IMG_OFFSETA_2_inst_adr                                                  "0x0090"
#define  IMG_OFFSETA_2_inst                                                      0x0090
#define  set_IMG_OFFSETA_2_reg(data)                                             (*((volatile unsigned int*)IMG_OFFSETA_2_reg)=data)
#define  get_IMG_OFFSETA_2_reg                                                   (*((volatile unsigned int*)IMG_OFFSETA_2_reg))

#define  IMG_OFFSETA_3                                                           0x1800FA44
#define  IMG_OFFSETA_3_reg_addr                                                  "0xB800FA44"
#define  IMG_OFFSETA_3_reg                                                       0xB800FA44
#define  IMG_OFFSETA_3_inst_addr                                                 "0x0011"
#define  IMG_OFFSETA_3_inst_adr                                                  "0x0091"
#define  IMG_OFFSETA_3_inst                                                      0x0091
#define  set_IMG_OFFSETA_3_reg(data)                                             (*((volatile unsigned int*)IMG_OFFSETA_3_reg)=data)
#define  get_IMG_OFFSETA_3_reg                                                   (*((volatile unsigned int*)IMG_OFFSETA_3_reg))

#define  IMG_PHASE_INIT_0                                                        0x1800FA48
#define  IMG_PHASE_INIT_0_reg_addr                                               "0xB800FA48"
#define  IMG_PHASE_INIT_0_reg                                                    0xB800FA48
#define  IMG_PHASE_INIT_0_inst_addr                                              "0x0012"
#define  IMG_PHASE_INIT_0_inst_adr                                               "0x0092"
#define  IMG_PHASE_INIT_0_inst                                                   0x0092
#define  set_IMG_PHASE_INIT_0_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_0_reg)=data)
#define  get_IMG_PHASE_INIT_0_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_0_reg))
#define  IMG_PHASE_INIT_init_phase_shift                                         (0)
#define  IMG_PHASE_INIT_init_phase_mask                                          (0x000FFFFF)
#define  IMG_PHASE_INIT_init_phase(data)                                         (0x000FFFFF&(data))
#define  IMG_PHASE_INIT_get_init_phase(data)                                     (0x000FFFFF&(data))
#define  IMG_PHASE_INIT_init_phase_src(data)                                     (0x000FFFFF&(data))

#define  IMG_PHASE_INIT_1                                                        0x1800FA4C
#define  IMG_PHASE_INIT_1_reg_addr                                               "0xB800FA4C"
#define  IMG_PHASE_INIT_1_reg                                                    0xB800FA4C
#define  IMG_PHASE_INIT_1_inst_addr                                              "0x0013"
#define  IMG_PHASE_INIT_1_inst_adr                                               "0x0093"
#define  IMG_PHASE_INIT_1_inst                                                   0x0093
#define  set_IMG_PHASE_INIT_1_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_1_reg)=data)
#define  get_IMG_PHASE_INIT_1_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_1_reg))

#define  IMG_PHASE_INIT_2                                                        0x1800FA50
#define  IMG_PHASE_INIT_2_reg_addr                                               "0xB800FA50"
#define  IMG_PHASE_INIT_2_reg                                                    0xB800FA50
#define  IMG_PHASE_INIT_2_inst_addr                                              "0x0014"
#define  IMG_PHASE_INIT_2_inst_adr                                               "0x0094"
#define  IMG_PHASE_INIT_2_inst                                                   0x0094
#define  set_IMG_PHASE_INIT_2_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_2_reg)=data)
#define  get_IMG_PHASE_INIT_2_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_2_reg))

#define  IMG_PHASE_INIT_3                                                        0x1800FA54
#define  IMG_PHASE_INIT_3_reg_addr                                               "0xB800FA54"
#define  IMG_PHASE_INIT_3_reg                                                    0xB800FA54
#define  IMG_PHASE_INIT_3_inst_addr                                              "0x0015"
#define  IMG_PHASE_INIT_3_inst_adr                                               "0x0095"
#define  IMG_PHASE_INIT_3_inst                                                   0x0095
#define  set_IMG_PHASE_INIT_3_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_3_reg)=data)
#define  get_IMG_PHASE_INIT_3_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_3_reg))

#define  IMG_PHASE_INIT_4                                                        0x1800FA58
#define  IMG_PHASE_INIT_4_reg_addr                                               "0xB800FA58"
#define  IMG_PHASE_INIT_4_reg                                                    0xB800FA58
#define  IMG_PHASE_INIT_4_inst_addr                                              "0x0016"
#define  IMG_PHASE_INIT_4_inst_adr                                               "0x0096"
#define  IMG_PHASE_INIT_4_inst                                                   0x0096
#define  set_IMG_PHASE_INIT_4_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_4_reg)=data)
#define  get_IMG_PHASE_INIT_4_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_4_reg))

#define  IMG_PHASE_INIT_5                                                        0x1800FA5C
#define  IMG_PHASE_INIT_5_reg_addr                                               "0xB800FA5C"
#define  IMG_PHASE_INIT_5_reg                                                    0xB800FA5C
#define  IMG_PHASE_INIT_5_inst_addr                                              "0x0017"
#define  IMG_PHASE_INIT_5_inst_adr                                               "0x0097"
#define  IMG_PHASE_INIT_5_inst                                                   0x0097
#define  set_IMG_PHASE_INIT_5_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_5_reg)=data)
#define  get_IMG_PHASE_INIT_5_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_5_reg))

#define  IMG_PHASE_INIT_6                                                        0x1800FA60
#define  IMG_PHASE_INIT_6_reg_addr                                               "0xB800FA60"
#define  IMG_PHASE_INIT_6_reg                                                    0xB800FA60
#define  IMG_PHASE_INIT_6_inst_addr                                              "0x0018"
#define  IMG_PHASE_INIT_6_inst_adr                                               "0x0098"
#define  IMG_PHASE_INIT_6_inst                                                   0x0098
#define  set_IMG_PHASE_INIT_6_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_6_reg)=data)
#define  get_IMG_PHASE_INIT_6_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_6_reg))

#define  IMG_PHASE_INIT_7                                                        0x1800FA64
#define  IMG_PHASE_INIT_7_reg_addr                                               "0xB800FA64"
#define  IMG_PHASE_INIT_7_reg                                                    0xB800FA64
#define  IMG_PHASE_INIT_7_inst_addr                                              "0x0019"
#define  IMG_PHASE_INIT_7_inst_adr                                               "0x0099"
#define  IMG_PHASE_INIT_7_inst                                                   0x0099
#define  set_IMG_PHASE_INIT_7_reg(data)                                          (*((volatile unsigned int*)IMG_PHASE_INIT_7_reg)=data)
#define  get_IMG_PHASE_INIT_7_reg                                                (*((volatile unsigned int*)IMG_PHASE_INIT_7_reg))

#define  IMG_PHASE_INC_0                                                         0x1800FA68
#define  IMG_PHASE_INC_0_reg_addr                                                "0xB800FA68"
#define  IMG_PHASE_INC_0_reg                                                     0xB800FA68
#define  IMG_PHASE_INC_0_inst_addr                                               "0x001A"
#define  IMG_PHASE_INC_0_inst_adr                                                "0x009A"
#define  IMG_PHASE_INC_0_inst                                                    0x009A
#define  set_IMG_PHASE_INC_0_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_0_reg)=data)
#define  get_IMG_PHASE_INC_0_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_0_reg))
#define  IMG_PHASE_INC_phase_inc_shift                                           (0)
#define  IMG_PHASE_INC_phase_inc_mask                                            (0x00FFFFFF)
#define  IMG_PHASE_INC_phase_inc(data)                                           (0x00FFFFFF&(data))
#define  IMG_PHASE_INC_get_phase_inc(data)                                       (0x00FFFFFF&(data))
#define  IMG_PHASE_INC_phase_inc_src(data)                                       (0x00FFFFFF&(data))

#define  IMG_PHASE_INC_1                                                         0x1800FA6C
#define  IMG_PHASE_INC_1_reg_addr                                                "0xB800FA6C"
#define  IMG_PHASE_INC_1_reg                                                     0xB800FA6C
#define  IMG_PHASE_INC_1_inst_addr                                               "0x001B"
#define  IMG_PHASE_INC_1_inst_adr                                                "0x009B"
#define  IMG_PHASE_INC_1_inst                                                    0x009B
#define  set_IMG_PHASE_INC_1_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_1_reg)=data)
#define  get_IMG_PHASE_INC_1_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_1_reg))

#define  IMG_PHASE_INC_2                                                         0x1800FA70
#define  IMG_PHASE_INC_2_reg_addr                                                "0xB800FA70"
#define  IMG_PHASE_INC_2_reg                                                     0xB800FA70
#define  IMG_PHASE_INC_2_inst_addr                                               "0x001C"
#define  IMG_PHASE_INC_2_inst_adr                                                "0x009C"
#define  IMG_PHASE_INC_2_inst                                                    0x009C
#define  set_IMG_PHASE_INC_2_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_2_reg)=data)
#define  get_IMG_PHASE_INC_2_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_2_reg))

#define  IMG_PHASE_INC_3                                                         0x1800FA74
#define  IMG_PHASE_INC_3_reg_addr                                                "0xB800FA74"
#define  IMG_PHASE_INC_3_reg                                                     0xB800FA74
#define  IMG_PHASE_INC_3_inst_addr                                               "0x001D"
#define  IMG_PHASE_INC_3_inst_adr                                                "0x009D"
#define  IMG_PHASE_INC_3_inst                                                    0x009D
#define  set_IMG_PHASE_INC_3_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_3_reg)=data)
#define  get_IMG_PHASE_INC_3_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_3_reg))

#define  IMG_PHASE_INC_4                                                         0x1800FA78
#define  IMG_PHASE_INC_4_reg_addr                                                "0xB800FA78"
#define  IMG_PHASE_INC_4_reg                                                     0xB800FA78
#define  IMG_PHASE_INC_4_inst_addr                                               "0x001E"
#define  IMG_PHASE_INC_4_inst_adr                                                "0x009E"
#define  IMG_PHASE_INC_4_inst                                                    0x009E
#define  set_IMG_PHASE_INC_4_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_4_reg)=data)
#define  get_IMG_PHASE_INC_4_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_4_reg))

#define  IMG_PHASE_INC_5                                                         0x1800FA7C
#define  IMG_PHASE_INC_5_reg_addr                                                "0xB800FA7C"
#define  IMG_PHASE_INC_5_reg                                                     0xB800FA7C
#define  IMG_PHASE_INC_5_inst_addr                                               "0x001F"
#define  IMG_PHASE_INC_5_inst_adr                                                "0x009F"
#define  IMG_PHASE_INC_5_inst                                                    0x009F
#define  set_IMG_PHASE_INC_5_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_5_reg)=data)
#define  get_IMG_PHASE_INC_5_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_5_reg))

#define  IMG_PHASE_INC_6                                                         0x1800FA80
#define  IMG_PHASE_INC_6_reg_addr                                                "0xB800FA80"
#define  IMG_PHASE_INC_6_reg                                                     0xB800FA80
#define  IMG_PHASE_INC_6_inst_addr                                               "0x0020"
#define  IMG_PHASE_INC_6_inst_adr                                                "0x00A0"
#define  IMG_PHASE_INC_6_inst                                                    0x00A0
#define  set_IMG_PHASE_INC_6_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_6_reg)=data)
#define  get_IMG_PHASE_INC_6_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_6_reg))

#define  IMG_PHASE_INC_7                                                         0x1800FA84
#define  IMG_PHASE_INC_7_reg_addr                                                "0xB800FA84"
#define  IMG_PHASE_INC_7_reg                                                     0xB800FA84
#define  IMG_PHASE_INC_7_inst_addr                                               "0x0021"
#define  IMG_PHASE_INC_7_inst_adr                                                "0x00A1"
#define  IMG_PHASE_INC_7_inst                                                    0x00A1
#define  set_IMG_PHASE_INC_7_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_INC_7_reg)=data)
#define  get_IMG_PHASE_INC_7_reg                                                 (*((volatile unsigned int*)IMG_PHASE_INC_7_reg))

#define  IMG_PHASE_OUT_0                                                         0x1800FA88
#define  IMG_PHASE_OUT_0_reg_addr                                                "0xB800FA88"
#define  IMG_PHASE_OUT_0_reg                                                     0xB800FA88
#define  IMG_PHASE_OUT_0_inst_addr                                               "0x0022"
#define  IMG_PHASE_OUT_0_inst_adr                                                "0x00A2"
#define  IMG_PHASE_OUT_0_inst                                                    0x00A2
#define  set_IMG_PHASE_OUT_0_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_0_reg)=data)
#define  get_IMG_PHASE_OUT_0_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_0_reg))
#define  IMG_PHASE_OUT_final_phase_shift                                         (0)
#define  IMG_PHASE_OUT_final_phase_mask                                          (0x07FFFFFF)
#define  IMG_PHASE_OUT_final_phase(data)                                         (0x07FFFFFF&(data))
#define  IMG_PHASE_OUT_get_final_phase(data)                                     (0x07FFFFFF&(data))
#define  IMG_PHASE_OUT_final_phase_src(data)                                     (0x07FFFFFF&(data))

#define  IMG_PHASE_OUT_1                                                         0x1800FA8C
#define  IMG_PHASE_OUT_1_reg_addr                                                "0xB800FA8C"
#define  IMG_PHASE_OUT_1_reg                                                     0xB800FA8C
#define  IMG_PHASE_OUT_1_inst_addr                                               "0x0023"
#define  IMG_PHASE_OUT_1_inst_adr                                                "0x00A3"
#define  IMG_PHASE_OUT_1_inst                                                    0x00A3
#define  set_IMG_PHASE_OUT_1_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_1_reg)=data)
#define  get_IMG_PHASE_OUT_1_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_1_reg))

#define  IMG_PHASE_OUT_2                                                         0x1800FA90
#define  IMG_PHASE_OUT_2_reg_addr                                                "0xB800FA90"
#define  IMG_PHASE_OUT_2_reg                                                     0xB800FA90
#define  IMG_PHASE_OUT_2_inst_addr                                               "0x0024"
#define  IMG_PHASE_OUT_2_inst_adr                                                "0x00A4"
#define  IMG_PHASE_OUT_2_inst                                                    0x00A4
#define  set_IMG_PHASE_OUT_2_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_2_reg)=data)
#define  get_IMG_PHASE_OUT_2_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_2_reg))

#define  IMG_PHASE_OUT_3                                                         0x1800FA94
#define  IMG_PHASE_OUT_3_reg_addr                                                "0xB800FA94"
#define  IMG_PHASE_OUT_3_reg                                                     0xB800FA94
#define  IMG_PHASE_OUT_3_inst_addr                                               "0x0025"
#define  IMG_PHASE_OUT_3_inst_adr                                                "0x00A5"
#define  IMG_PHASE_OUT_3_inst                                                    0x00A5
#define  set_IMG_PHASE_OUT_3_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_3_reg)=data)
#define  get_IMG_PHASE_OUT_3_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_3_reg))

#define  IMG_PHASE_OUT_4                                                         0x1800FA98
#define  IMG_PHASE_OUT_4_reg_addr                                                "0xB800FA98"
#define  IMG_PHASE_OUT_4_reg                                                     0xB800FA98
#define  IMG_PHASE_OUT_4_inst_addr                                               "0x0026"
#define  IMG_PHASE_OUT_4_inst_adr                                                "0x00A6"
#define  IMG_PHASE_OUT_4_inst                                                    0x00A6
#define  set_IMG_PHASE_OUT_4_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_4_reg)=data)
#define  get_IMG_PHASE_OUT_4_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_4_reg))

#define  IMG_PHASE_OUT_5                                                         0x1800FA9C
#define  IMG_PHASE_OUT_5_reg_addr                                                "0xB800FA9C"
#define  IMG_PHASE_OUT_5_reg                                                     0xB800FA9C
#define  IMG_PHASE_OUT_5_inst_addr                                               "0x0027"
#define  IMG_PHASE_OUT_5_inst_adr                                                "0x00A7"
#define  IMG_PHASE_OUT_5_inst                                                    0x00A7
#define  set_IMG_PHASE_OUT_5_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_5_reg)=data)
#define  get_IMG_PHASE_OUT_5_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_5_reg))

#define  IMG_PHASE_OUT_6                                                         0x1800FAA0
#define  IMG_PHASE_OUT_6_reg_addr                                                "0xB800FAA0"
#define  IMG_PHASE_OUT_6_reg                                                     0xB800FAA0
#define  IMG_PHASE_OUT_6_inst_addr                                               "0x0028"
#define  IMG_PHASE_OUT_6_inst_adr                                                "0x00A8"
#define  IMG_PHASE_OUT_6_inst                                                    0x00A8
#define  set_IMG_PHASE_OUT_6_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_6_reg)=data)
#define  get_IMG_PHASE_OUT_6_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_6_reg))

#define  IMG_PHASE_OUT_7                                                         0x1800FAA4
#define  IMG_PHASE_OUT_7_reg_addr                                                "0xB800FAA4"
#define  IMG_PHASE_OUT_7_reg                                                     0xB800FAA4
#define  IMG_PHASE_OUT_7_inst_addr                                               "0x0029"
#define  IMG_PHASE_OUT_7_inst_adr                                                "0x00A9"
#define  IMG_PHASE_OUT_7_inst                                                    0x00A9
#define  set_IMG_PHASE_OUT_7_reg(data)                                           (*((volatile unsigned int*)IMG_PHASE_OUT_7_reg)=data)
#define  get_IMG_PHASE_OUT_7_reg                                                 (*((volatile unsigned int*)IMG_PHASE_OUT_7_reg))

#define  IMG_TAPCOEFF0_0                                                         0x1800FAA8
#define  IMG_TAPCOEFF0_0_reg_addr                                                "0xB800FAA8"
#define  IMG_TAPCOEFF0_0_reg                                                     0xB800FAA8
#define  IMG_TAPCOEFF0_0_inst_addr                                               "0x002A"
#define  IMG_TAPCOEFF0_0_inst_adr                                                "0x00AA"
#define  IMG_TAPCOEFF0_0_inst                                                    0x00AA
#define  set_IMG_TAPCOEFF0_0_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_0_reg)=data)
#define  get_IMG_TAPCOEFF0_0_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_0_reg))
#define  IMG_TAPCOEFF0_coeff0_n1_shift                                           (16)
#define  IMG_TAPCOEFF0_coeff0_n_shift                                            (0)
#define  IMG_TAPCOEFF0_coeff0_n1_mask                                            (0x0FFF0000)
#define  IMG_TAPCOEFF0_coeff0_n_mask                                             (0x00000FFF)
#define  IMG_TAPCOEFF0_coeff0_n1(data)                                           (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF0_coeff0_n(data)                                            (0x00000FFF&(data))
#define  IMG_TAPCOEFF0_get_coeff0_n1(data)                                       ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF0_get_coeff0_n(data)                                        (0x00000FFF&(data))
#define  IMG_TAPCOEFF0_coeff0_n1_src(data)                                       ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF0_coeff0_n_src(data)                                        (0x00000FFF&(data))

#define  IMG_TAPCOEFF0_1                                                         0x1800FAAC
#define  IMG_TAPCOEFF0_1_reg_addr                                                "0xB800FAAC"
#define  IMG_TAPCOEFF0_1_reg                                                     0xB800FAAC
#define  IMG_TAPCOEFF0_1_inst_addr                                               "0x002B"
#define  IMG_TAPCOEFF0_1_inst_adr                                                "0x00AB"
#define  IMG_TAPCOEFF0_1_inst                                                    0x00AB
#define  set_IMG_TAPCOEFF0_1_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_1_reg)=data)
#define  get_IMG_TAPCOEFF0_1_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_1_reg))

#define  IMG_TAPCOEFF0_2                                                         0x1800FAB0
#define  IMG_TAPCOEFF0_2_reg_addr                                                "0xB800FAB0"
#define  IMG_TAPCOEFF0_2_reg                                                     0xB800FAB0
#define  IMG_TAPCOEFF0_2_inst_addr                                               "0x002C"
#define  IMG_TAPCOEFF0_2_inst_adr                                                "0x00AC"
#define  IMG_TAPCOEFF0_2_inst                                                    0x00AC
#define  set_IMG_TAPCOEFF0_2_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_2_reg)=data)
#define  get_IMG_TAPCOEFF0_2_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_2_reg))

#define  IMG_TAPCOEFF0_3                                                         0x1800FAB4
#define  IMG_TAPCOEFF0_3_reg_addr                                                "0xB800FAB4"
#define  IMG_TAPCOEFF0_3_reg                                                     0xB800FAB4
#define  IMG_TAPCOEFF0_3_inst_addr                                               "0x002D"
#define  IMG_TAPCOEFF0_3_inst_adr                                                "0x00AD"
#define  IMG_TAPCOEFF0_3_inst                                                    0x00AD
#define  set_IMG_TAPCOEFF0_3_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_3_reg)=data)
#define  get_IMG_TAPCOEFF0_3_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_3_reg))

#define  IMG_TAPCOEFF0_4                                                         0x1800FAB8
#define  IMG_TAPCOEFF0_4_reg_addr                                                "0xB800FAB8"
#define  IMG_TAPCOEFF0_4_reg                                                     0xB800FAB8
#define  IMG_TAPCOEFF0_4_inst_addr                                               "0x002E"
#define  IMG_TAPCOEFF0_4_inst_adr                                                "0x00AE"
#define  IMG_TAPCOEFF0_4_inst                                                    0x00AE
#define  set_IMG_TAPCOEFF0_4_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_4_reg)=data)
#define  get_IMG_TAPCOEFF0_4_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_4_reg))

#define  IMG_TAPCOEFF0_5                                                         0x1800FABC
#define  IMG_TAPCOEFF0_5_reg_addr                                                "0xB800FABC"
#define  IMG_TAPCOEFF0_5_reg                                                     0xB800FABC
#define  IMG_TAPCOEFF0_5_inst_addr                                               "0x002F"
#define  IMG_TAPCOEFF0_5_inst_adr                                                "0x00AF"
#define  IMG_TAPCOEFF0_5_inst                                                    0x00AF
#define  set_IMG_TAPCOEFF0_5_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_5_reg)=data)
#define  get_IMG_TAPCOEFF0_5_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_5_reg))

#define  IMG_TAPCOEFF0_6                                                         0x1800FAC0
#define  IMG_TAPCOEFF0_6_reg_addr                                                "0xB800FAC0"
#define  IMG_TAPCOEFF0_6_reg                                                     0xB800FAC0
#define  IMG_TAPCOEFF0_6_inst_addr                                               "0x0030"
#define  IMG_TAPCOEFF0_6_inst_adr                                                "0x00B0"
#define  IMG_TAPCOEFF0_6_inst                                                    0x00B0
#define  set_IMG_TAPCOEFF0_6_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_6_reg)=data)
#define  get_IMG_TAPCOEFF0_6_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_6_reg))

#define  IMG_TAPCOEFF0_7                                                         0x1800FAC4
#define  IMG_TAPCOEFF0_7_reg_addr                                                "0xB800FAC4"
#define  IMG_TAPCOEFF0_7_reg                                                     0xB800FAC4
#define  IMG_TAPCOEFF0_7_inst_addr                                               "0x0031"
#define  IMG_TAPCOEFF0_7_inst_adr                                                "0x00B1"
#define  IMG_TAPCOEFF0_7_inst                                                    0x00B1
#define  set_IMG_TAPCOEFF0_7_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF0_7_reg)=data)
#define  get_IMG_TAPCOEFF0_7_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF0_7_reg))

#define  IMG_TAPCOEFF1_0                                                         0x1800FAC8
#define  IMG_TAPCOEFF1_0_reg_addr                                                "0xB800FAC8"
#define  IMG_TAPCOEFF1_0_reg                                                     0xB800FAC8
#define  IMG_TAPCOEFF1_0_inst_addr                                               "0x0032"
#define  IMG_TAPCOEFF1_0_inst_adr                                                "0x00B2"
#define  IMG_TAPCOEFF1_0_inst                                                    0x00B2
#define  set_IMG_TAPCOEFF1_0_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_0_reg)=data)
#define  get_IMG_TAPCOEFF1_0_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_0_reg))
#define  IMG_TAPCOEFF1_coeff1_n1_shift                                           (16)
#define  IMG_TAPCOEFF1_coeff1_n_shift                                            (0)
#define  IMG_TAPCOEFF1_coeff1_n1_mask                                            (0x0FFF0000)
#define  IMG_TAPCOEFF1_coeff1_n_mask                                             (0x00000FFF)
#define  IMG_TAPCOEFF1_coeff1_n1(data)                                           (0x0FFF0000&((data)<<16))
#define  IMG_TAPCOEFF1_coeff1_n(data)                                            (0x00000FFF&(data))
#define  IMG_TAPCOEFF1_get_coeff1_n1(data)                                       ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF1_get_coeff1_n(data)                                        (0x00000FFF&(data))
#define  IMG_TAPCOEFF1_coeff1_n1_src(data)                                       ((0x0FFF0000&(data))>>16)
#define  IMG_TAPCOEFF1_coeff1_n_src(data)                                        (0x00000FFF&(data))

#define  IMG_TAPCOEFF1_1                                                         0x1800FACC
#define  IMG_TAPCOEFF1_1_reg_addr                                                "0xB800FACC"
#define  IMG_TAPCOEFF1_1_reg                                                     0xB800FACC
#define  IMG_TAPCOEFF1_1_inst_addr                                               "0x0033"
#define  IMG_TAPCOEFF1_1_inst_adr                                                "0x00B3"
#define  IMG_TAPCOEFF1_1_inst                                                    0x00B3
#define  set_IMG_TAPCOEFF1_1_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_1_reg)=data)
#define  get_IMG_TAPCOEFF1_1_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_1_reg))

#define  IMG_TAPCOEFF1_2                                                         0x1800FAD0
#define  IMG_TAPCOEFF1_2_reg_addr                                                "0xB800FAD0"
#define  IMG_TAPCOEFF1_2_reg                                                     0xB800FAD0
#define  IMG_TAPCOEFF1_2_inst_addr                                               "0x0034"
#define  IMG_TAPCOEFF1_2_inst_adr                                                "0x00B4"
#define  IMG_TAPCOEFF1_2_inst                                                    0x00B4
#define  set_IMG_TAPCOEFF1_2_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_2_reg)=data)
#define  get_IMG_TAPCOEFF1_2_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_2_reg))

#define  IMG_TAPCOEFF1_3                                                         0x1800FAD4
#define  IMG_TAPCOEFF1_3_reg_addr                                                "0xB800FAD4"
#define  IMG_TAPCOEFF1_3_reg                                                     0xB800FAD4
#define  IMG_TAPCOEFF1_3_inst_addr                                               "0x0035"
#define  IMG_TAPCOEFF1_3_inst_adr                                                "0x00B5"
#define  IMG_TAPCOEFF1_3_inst                                                    0x00B5
#define  set_IMG_TAPCOEFF1_3_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_3_reg)=data)
#define  get_IMG_TAPCOEFF1_3_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_3_reg))

#define  IMG_TAPCOEFF1_4                                                         0x1800FAD8
#define  IMG_TAPCOEFF1_4_reg_addr                                                "0xB800FAD8"
#define  IMG_TAPCOEFF1_4_reg                                                     0xB800FAD8
#define  IMG_TAPCOEFF1_4_inst_addr                                               "0x0036"
#define  IMG_TAPCOEFF1_4_inst_adr                                                "0x00B6"
#define  IMG_TAPCOEFF1_4_inst                                                    0x00B6
#define  set_IMG_TAPCOEFF1_4_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_4_reg)=data)
#define  get_IMG_TAPCOEFF1_4_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_4_reg))

#define  IMG_TAPCOEFF1_5                                                         0x1800FADC
#define  IMG_TAPCOEFF1_5_reg_addr                                                "0xB800FADC"
#define  IMG_TAPCOEFF1_5_reg                                                     0xB800FADC
#define  IMG_TAPCOEFF1_5_inst_addr                                               "0x0037"
#define  IMG_TAPCOEFF1_5_inst_adr                                                "0x00B7"
#define  IMG_TAPCOEFF1_5_inst                                                    0x00B7
#define  set_IMG_TAPCOEFF1_5_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_5_reg)=data)
#define  get_IMG_TAPCOEFF1_5_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_5_reg))

#define  IMG_TAPCOEFF1_6                                                         0x1800FAE0
#define  IMG_TAPCOEFF1_6_reg_addr                                                "0xB800FAE0"
#define  IMG_TAPCOEFF1_6_reg                                                     0xB800FAE0
#define  IMG_TAPCOEFF1_6_inst_addr                                               "0x0038"
#define  IMG_TAPCOEFF1_6_inst_adr                                                "0x00B8"
#define  IMG_TAPCOEFF1_6_inst                                                    0x00B8
#define  set_IMG_TAPCOEFF1_6_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_6_reg)=data)
#define  get_IMG_TAPCOEFF1_6_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_6_reg))

#define  IMG_TAPCOEFF1_7                                                         0x1800FAE4
#define  IMG_TAPCOEFF1_7_reg_addr                                                "0xB800FAE4"
#define  IMG_TAPCOEFF1_7_reg                                                     0xB800FAE4
#define  IMG_TAPCOEFF1_7_inst_addr                                               "0x0039"
#define  IMG_TAPCOEFF1_7_inst_adr                                                "0x00B9"
#define  IMG_TAPCOEFF1_7_inst                                                    0x00B9
#define  set_IMG_TAPCOEFF1_7_reg(data)                                           (*((volatile unsigned int*)IMG_TAPCOEFF1_7_reg)=data)
#define  get_IMG_TAPCOEFF1_7_reg                                                 (*((volatile unsigned int*)IMG_TAPCOEFF1_7_reg))

#define  IMG_PPNR_SADY                                                           0x1800FAE8
#define  IMG_PPNR_SADY_reg_addr                                                  "0xB800FAE8"
#define  IMG_PPNR_SADY_reg                                                       0xB800FAE8
#define  IMG_PPNR_SADY_inst_addr                                                 "0x003A"
#define  IMG_PPNR_SADY_inst_adr                                                  "0x00BA"
#define  IMG_PPNR_SADY_inst                                                      0x00BA
#define  set_IMG_PPNR_SADY_reg(data)                                             (*((volatile unsigned int*)IMG_PPNR_SADY_reg)=data)
#define  get_IMG_PPNR_SADY_reg                                                   (*((volatile unsigned int*)IMG_PPNR_SADY_reg))
#define  IMG_PPNR_SADY_maxValue_shift                                            (24)
#define  IMG_PPNR_SADY_minValue_shift                                            (16)
#define  IMG_PPNR_SADY_minSAD_shift                                              (0)
#define  IMG_PPNR_SADY_maxValue_mask                                             (0xFF000000)
#define  IMG_PPNR_SADY_minValue_mask                                             (0x00FF0000)
#define  IMG_PPNR_SADY_minSAD_mask                                               (0x0000FFFF)
#define  IMG_PPNR_SADY_maxValue(data)                                            (0xFF000000&((data)<<24))
#define  IMG_PPNR_SADY_minValue(data)                                            (0x00FF0000&((data)<<16))
#define  IMG_PPNR_SADY_minSAD(data)                                              (0x0000FFFF&(data))
#define  IMG_PPNR_SADY_get_maxValue(data)                                        ((0xFF000000&(data))>>24)
#define  IMG_PPNR_SADY_get_minValue(data)                                        ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_SADY_get_minSAD(data)                                          (0x0000FFFF&(data))
#define  IMG_PPNR_SADY_maxValue_src(data)                                        ((0xFF000000&(data))>>24)
#define  IMG_PPNR_SADY_minValue_src(data)                                        ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_SADY_minSAD_src(data)                                          (0x0000FFFF&(data))

#define  IMG_PPNR_SADCB                                                          0x1800FAEC
#define  IMG_PPNR_SADCB_reg_addr                                                 "0xB800FAEC"
#define  IMG_PPNR_SADCB_reg                                                      0xB800FAEC
#define  IMG_PPNR_SADCB_inst_addr                                                "0x003B"
#define  IMG_PPNR_SADCB_inst_adr                                                 "0x00BB"
#define  IMG_PPNR_SADCB_inst                                                     0x00BB
#define  set_IMG_PPNR_SADCB_reg(data)                                            (*((volatile unsigned int*)IMG_PPNR_SADCB_reg)=data)
#define  get_IMG_PPNR_SADCB_reg                                                  (*((volatile unsigned int*)IMG_PPNR_SADCB_reg))
#define  IMG_PPNR_SADCB_maxValue_shift                                           (24)
#define  IMG_PPNR_SADCB_minValue_shift                                           (16)
#define  IMG_PPNR_SADCB_minSAD_shift                                             (0)
#define  IMG_PPNR_SADCB_maxValue_mask                                            (0xFF000000)
#define  IMG_PPNR_SADCB_minValue_mask                                            (0x00FF0000)
#define  IMG_PPNR_SADCB_minSAD_mask                                              (0x0000FFFF)
#define  IMG_PPNR_SADCB_maxValue(data)                                           (0xFF000000&((data)<<24))
#define  IMG_PPNR_SADCB_minValue(data)                                           (0x00FF0000&((data)<<16))
#define  IMG_PPNR_SADCB_minSAD(data)                                             (0x0000FFFF&(data))
#define  IMG_PPNR_SADCB_get_maxValue(data)                                       ((0xFF000000&(data))>>24)
#define  IMG_PPNR_SADCB_get_minValue(data)                                       ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_SADCB_get_minSAD(data)                                         (0x0000FFFF&(data))
#define  IMG_PPNR_SADCB_maxValue_src(data)                                       ((0xFF000000&(data))>>24)
#define  IMG_PPNR_SADCB_minValue_src(data)                                       ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_SADCB_minSAD_src(data)                                         (0x0000FFFF&(data))

#define  IMG_PPNR_SADCR                                                          0x1800FAF0
#define  IMG_PPNR_SADCR_reg_addr                                                 "0xB800FAF0"
#define  IMG_PPNR_SADCR_reg                                                      0xB800FAF0
#define  IMG_PPNR_SADCR_inst_addr                                                "0x003C"
#define  IMG_PPNR_SADCR_inst_adr                                                 "0x00BC"
#define  IMG_PPNR_SADCR_inst                                                     0x00BC
#define  set_IMG_PPNR_SADCR_reg(data)                                            (*((volatile unsigned int*)IMG_PPNR_SADCR_reg)=data)
#define  get_IMG_PPNR_SADCR_reg                                                  (*((volatile unsigned int*)IMG_PPNR_SADCR_reg))
#define  IMG_PPNR_SADCR_maxValue_shift                                           (24)
#define  IMG_PPNR_SADCR_minValue_shift                                           (16)
#define  IMG_PPNR_SADCR_minSAD_shift                                             (0)
#define  IMG_PPNR_SADCR_maxValue_mask                                            (0xFF000000)
#define  IMG_PPNR_SADCR_minValue_mask                                            (0x00FF0000)
#define  IMG_PPNR_SADCR_minSAD_mask                                              (0x0000FFFF)
#define  IMG_PPNR_SADCR_maxValue(data)                                           (0xFF000000&((data)<<24))
#define  IMG_PPNR_SADCR_minValue(data)                                           (0x00FF0000&((data)<<16))
#define  IMG_PPNR_SADCR_minSAD(data)                                             (0x0000FFFF&(data))
#define  IMG_PPNR_SADCR_get_maxValue(data)                                       ((0xFF000000&(data))>>24)
#define  IMG_PPNR_SADCR_get_minValue(data)                                       ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_SADCR_get_minSAD(data)                                         (0x0000FFFF&(data))
#define  IMG_PPNR_SADCR_maxValue_src(data)                                       ((0xFF000000&(data))>>24)
#define  IMG_PPNR_SADCR_minValue_src(data)                                       ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_SADCR_minSAD_src(data)                                         (0x0000FFFF&(data))

#define  IMG_PPNR_THR_LUMA                                                       0x1800FAF4
#define  IMG_PPNR_THR_LUMA_reg_addr                                              "0xB800FAF4"
#define  IMG_PPNR_THR_LUMA_reg                                                   0xB800FAF4
#define  IMG_PPNR_THR_LUMA_inst_addr                                             "0x003D"
#define  IMG_PPNR_THR_LUMA_inst_adr                                              "0x00BD"
#define  IMG_PPNR_THR_LUMA_inst                                                  0x00BD
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
#define  IMG_PPNR_THR_LUMA_y_maxthr_src(data)                                    ((0x0000FF00&(data))>>8)
#define  IMG_PPNR_THR_LUMA_y_minthr_src(data)                                    (0x000000FF&(data))

#define  IMG_PPNR_THR_CHROMA                                                     0x1800FAF8
#define  IMG_PPNR_THR_CHROMA_reg_addr                                            "0xB800FAF8"
#define  IMG_PPNR_THR_CHROMA_reg                                                 0xB800FAF8
#define  IMG_PPNR_THR_CHROMA_inst_addr                                           "0x003E"
#define  IMG_PPNR_THR_CHROMA_inst_adr                                            "0x00BE"
#define  IMG_PPNR_THR_CHROMA_inst                                                0x00BE
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
#define  IMG_PPNR_THR_CHROMA_cb_maxthr_src(data)                                 ((0xFF000000&(data))>>24)
#define  IMG_PPNR_THR_CHROMA_cb_minthr_src(data)                                 ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_THR_CHROMA_cr_maxthr_src(data)                                 ((0x0000FF00&(data))>>8)
#define  IMG_PPNR_THR_CHROMA_cr_minthr_src(data)                                 (0x000000FF&(data))

#define  IMG_PPNR_SPATIAL_DIFF                                                   0x1800FAFC
#define  IMG_PPNR_SPATIAL_DIFF_reg_addr                                          "0xB800FAFC"
#define  IMG_PPNR_SPATIAL_DIFF_reg                                               0xB800FAFC
#define  IMG_PPNR_SPATIAL_DIFF_inst_addr                                         "0x003F"
#define  IMG_PPNR_SPATIAL_DIFF_inst_adr                                          "0x00BF"
#define  IMG_PPNR_SPATIAL_DIFF_inst                                              0x00BF
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
#define  IMG_PPNR_SPATIAL_DIFF_t3_src(data)                                      ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_SPATIAL_DIFF_t2_src(data)                                      ((0x0000FF00&(data))>>8)
#define  IMG_PPNR_SPATIAL_DIFF_t1_src(data)                                      (0x000000FF&(data))

#define  IMG_PPNR_TEMPORAL_DIFF                                                  0x1800FB00
#define  IMG_PPNR_TEMPORAL_DIFF_reg_addr                                         "0xB800FB00"
#define  IMG_PPNR_TEMPORAL_DIFF_reg                                              0xB800FB00
#define  IMG_PPNR_TEMPORAL_DIFF_inst_addr                                        "0x0040"
#define  IMG_PPNR_TEMPORAL_DIFF_inst_adr                                         "0x00C0"
#define  IMG_PPNR_TEMPORAL_DIFF_inst                                             0x00C0
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
#define  IMG_PPNR_TEMPORAL_DIFF_t3_src(data)                                     ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_TEMPORAL_DIFF_t2_src(data)                                     ((0x0000FF00&(data))>>8)
#define  IMG_PPNR_TEMPORAL_DIFF_t1_src(data)                                     (0x000000FF&(data))

#define  IMG_PPNR_BLEND_LEVEL                                                    0x1800FB04
#define  IMG_PPNR_BLEND_LEVEL_reg_addr                                           "0xB800FB04"
#define  IMG_PPNR_BLEND_LEVEL_reg                                                0xB800FB04
#define  IMG_PPNR_BLEND_LEVEL_inst_addr                                          "0x0041"
#define  IMG_PPNR_BLEND_LEVEL_inst_adr                                           "0x00C1"
#define  IMG_PPNR_BLEND_LEVEL_inst                                               0x00C1
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
#define  IMG_PPNR_BLEND_LEVEL_temporal_k2_src(data)                              ((0xFF000000&(data))>>24)
#define  IMG_PPNR_BLEND_LEVEL_temporal_k1_src(data)                              ((0x00FF0000&(data))>>16)
#define  IMG_PPNR_BLEND_LEVEL_spatial_k2_src(data)                               ((0x0000FF00&(data))>>8)
#define  IMG_PPNR_BLEND_LEVEL_spatial_k1_src(data)                               (0x000000FF&(data))

#define  IMG_PPNR_SPATIAL_SLOP                                                   0x1800FB08
#define  IMG_PPNR_SPATIAL_SLOP_reg_addr                                          "0xB800FB08"
#define  IMG_PPNR_SPATIAL_SLOP_reg                                               0xB800FB08
#define  IMG_PPNR_SPATIAL_SLOP_inst_addr                                         "0x0042"
#define  IMG_PPNR_SPATIAL_SLOP_inst_adr                                          "0x00C2"
#define  IMG_PPNR_SPATIAL_SLOP_inst                                              0x00C2
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
#define  IMG_PPNR_SPATIAL_SLOP_s2_src(data)                                      ((0xFFFF0000&(data))>>16)
#define  IMG_PPNR_SPATIAL_SLOP_s1_src(data)                                      (0x0000FFFF&(data))

#define  IMG_PPNR_TEMPORAL_SLOP                                                  0x1800FB0C
#define  IMG_PPNR_TEMPORAL_SLOP_reg_addr                                         "0xB800FB0C"
#define  IMG_PPNR_TEMPORAL_SLOP_reg                                              0xB800FB0C
#define  IMG_PPNR_TEMPORAL_SLOP_inst_addr                                        "0x0043"
#define  IMG_PPNR_TEMPORAL_SLOP_inst_adr                                         "0x00C3"
#define  IMG_PPNR_TEMPORAL_SLOP_inst                                             0x00C3
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
#define  IMG_PPNR_TEMPORAL_SLOP_s2_src(data)                                     ((0xFFFF0000&(data))>>16)
#define  IMG_PPNR_TEMPORAL_SLOP_s1_src(data)                                     (0x0000FFFF&(data))

#define  IMG_HCOEF_0                                                             0x1800FB10
#define  IMG_HCOEF_0_reg_addr                                                    "0xB800FB10"
#define  IMG_HCOEF_0_reg                                                         0xB800FB10
#define  IMG_HCOEF_0_inst_addr                                                   "0x0044"
#define  IMG_HCOEF_0_inst_adr                                                    "0x00C4"
#define  IMG_HCOEF_0_inst                                                        0x00C4
#define  set_IMG_HCOEF_0_reg(data)                                               (*((volatile unsigned int*)IMG_HCOEF_0_reg)=data)
#define  get_IMG_HCOEF_0_reg                                                     (*((volatile unsigned int*)IMG_HCOEF_0_reg))
#define  IMG_HCOEF_hcoef_1_shift                                                 (14)
#define  IMG_HCOEF_hcoef_0_shift                                                 (0)
#define  IMG_HCOEF_hcoef_1_mask                                                  (0x0FFFC000)
#define  IMG_HCOEF_hcoef_0_mask                                                  (0x00003FFF)
#define  IMG_HCOEF_hcoef_1(data)                                                 (0x0FFFC000&((data)<<14))
#define  IMG_HCOEF_hcoef_0(data)                                                 (0x00003FFF&(data))
#define  IMG_HCOEF_get_hcoef_1(data)                                             ((0x0FFFC000&(data))>>14)
#define  IMG_HCOEF_get_hcoef_0(data)                                             (0x00003FFF&(data))
#define  IMG_HCOEF_hcoef_1_src(data)                                             ((0x0FFFC000&(data))>>14)
#define  IMG_HCOEF_hcoef_0_src(data)                                             (0x00003FFF&(data))

#define  IMG_HCOEF_1                                                             0x1800FB14
#define  IMG_HCOEF_1_reg_addr                                                    "0xB800FB14"
#define  IMG_HCOEF_1_reg                                                         0xB800FB14
#define  IMG_HCOEF_1_inst_addr                                                   "0x0045"
#define  IMG_HCOEF_1_inst_adr                                                    "0x00C5"
#define  IMG_HCOEF_1_inst                                                        0x00C5
#define  set_IMG_HCOEF_1_reg(data)                                               (*((volatile unsigned int*)IMG_HCOEF_1_reg)=data)
#define  get_IMG_HCOEF_1_reg                                                     (*((volatile unsigned int*)IMG_HCOEF_1_reg))

#define  IMG_HCOEF_2                                                             0x1800FB18
#define  IMG_HCOEF_2_reg_addr                                                    "0xB800FB18"
#define  IMG_HCOEF_2_reg                                                         0xB800FB18
#define  IMG_HCOEF_2_inst_addr                                                   "0x0046"
#define  IMG_HCOEF_2_inst_adr                                                    "0x00C6"
#define  IMG_HCOEF_2_inst                                                        0x00C6
#define  set_IMG_HCOEF_2_reg(data)                                               (*((volatile unsigned int*)IMG_HCOEF_2_reg)=data)
#define  get_IMG_HCOEF_2_reg                                                     (*((volatile unsigned int*)IMG_HCOEF_2_reg))

#define  IMG_HCOEF_3                                                             0x1800FB1C
#define  IMG_HCOEF_3_reg_addr                                                    "0xB800FB1C"
#define  IMG_HCOEF_3_reg                                                         0xB800FB1C
#define  IMG_HCOEF_3_inst_addr                                                   "0x0047"
#define  IMG_HCOEF_3_inst_adr                                                    "0x00C7"
#define  IMG_HCOEF_3_inst                                                        0x00C7
#define  set_IMG_HCOEF_3_reg(data)                                               (*((volatile unsigned int*)IMG_HCOEF_3_reg)=data)
#define  get_IMG_HCOEF_3_reg                                                     (*((volatile unsigned int*)IMG_HCOEF_3_reg))

#define  IMG_VCOEF_0                                                             0x1800FB20
#define  IMG_VCOEF_0_reg_addr                                                    "0xB800FB20"
#define  IMG_VCOEF_0_reg                                                         0xB800FB20
#define  IMG_VCOEF_0_inst_addr                                                   "0x0048"
#define  IMG_VCOEF_0_inst_adr                                                    "0x00C8"
#define  IMG_VCOEF_0_inst                                                        0x00C8
#define  set_IMG_VCOEF_0_reg(data)                                               (*((volatile unsigned int*)IMG_VCOEF_0_reg)=data)
#define  get_IMG_VCOEF_0_reg                                                     (*((volatile unsigned int*)IMG_VCOEF_0_reg))
#define  IMG_VCOEF_vcoef_1_shift                                                 (14)
#define  IMG_VCOEF_vcoef_0_shift                                                 (0)
#define  IMG_VCOEF_vcoef_1_mask                                                  (0x0FFFC000)
#define  IMG_VCOEF_vcoef_0_mask                                                  (0x00003FFF)
#define  IMG_VCOEF_vcoef_1(data)                                                 (0x0FFFC000&((data)<<14))
#define  IMG_VCOEF_vcoef_0(data)                                                 (0x00003FFF&(data))
#define  IMG_VCOEF_get_vcoef_1(data)                                             ((0x0FFFC000&(data))>>14)
#define  IMG_VCOEF_get_vcoef_0(data)                                             (0x00003FFF&(data))
#define  IMG_VCOEF_vcoef_1_src(data)                                             ((0x0FFFC000&(data))>>14)
#define  IMG_VCOEF_vcoef_0_src(data)                                             (0x00003FFF&(data))

#define  IMG_VCOEF_1                                                             0x1800FB24
#define  IMG_VCOEF_1_reg_addr                                                    "0xB800FB24"
#define  IMG_VCOEF_1_reg                                                         0xB800FB24
#define  IMG_VCOEF_1_inst_addr                                                   "0x0049"
#define  IMG_VCOEF_1_inst_adr                                                    "0x00C9"
#define  IMG_VCOEF_1_inst                                                        0x00C9
#define  set_IMG_VCOEF_1_reg(data)                                               (*((volatile unsigned int*)IMG_VCOEF_1_reg)=data)
#define  get_IMG_VCOEF_1_reg                                                     (*((volatile unsigned int*)IMG_VCOEF_1_reg))

#define  IMG_MBV                                                                 0x1800FB28
#define  IMG_MBV_reg_addr                                                        "0xB800FB28"
#define  IMG_MBV_reg                                                             0xB800FB28
#define  IMG_MBV_inst_addr                                                       "0x004A"
#define  IMG_MBV_inst_adr                                                        "0x00CA"
#define  IMG_MBV_inst                                                            0x00CA
#define  set_IMG_MBV_reg(data)                                                   (*((volatile unsigned int*)IMG_MBV_reg)=data)
#define  get_IMG_MBV_reg                                                         (*((volatile unsigned int*)IMG_MBV_reg))
#define  IMG_MBV_MBVariance_shift                                                (0)
#define  IMG_MBV_MBVariance_mask                                                 (0x003FFFFF)
#define  IMG_MBV_MBVariance(data)                                                (0x003FFFFF&(data))
#define  IMG_MBV_get_MBVariance(data)                                            (0x003FFFFF&(data))
#define  IMG_MBV_MBVariance_src(data)                                            (0x003FFFFF&(data))

#ifdef _IMG_USE_STRUCT
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
}IMG_DBG_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  chroma_enable:1;
        RBus_UInt32  luma_enable:1;
    };
}IMG_DERING_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  filt_prec:2;
    };
}IMG_FILT_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  init_value:10;
    };
}IMG_FILT_INIT_RBUS;

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
}IMG_RMRPR_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  m:4;
        RBus_UInt32  pixel_offset:13;
    };
}IMG_RMRPR_PAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ax:32;
    };
}IMG_RMRPR_AX_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ay:32;
    };
}IMG_RMRPR_AY_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ax_inc:32;
    };
}IMG_RMRPR_AXINC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  picmb_h:8;
        RBus_UInt32  picmb_w:9;
    };
}IMG_RMRPR_PICINFO_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  basea:10;
    };
}IMG_BASEA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  offseta:9;
    };
}IMG_OFFSETA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  init_phase:20;
    };
}IMG_PHASE_INIT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  phase_inc:24;
    };
}IMG_PHASE_INC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  final_phase:27;
    };
}IMG_PHASE_OUT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coeff0_n1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  coeff0_n:12;
    };
}IMG_TAPCOEFF0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coeff1_n1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  coeff1_n:12;
    };
}IMG_TAPCOEFF1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxValue:8;
        RBus_UInt32  minValue:8;
        RBus_UInt32  minSAD:16;
    };
}IMG_PPNR_SADY_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxValue:8;
        RBus_UInt32  minValue:8;
        RBus_UInt32  minSAD:16;
    };
}IMG_PPNR_SADCB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxValue:8;
        RBus_UInt32  minValue:8;
        RBus_UInt32  minSAD:16;
    };
}IMG_PPNR_SADCR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  y_maxthr:8;
        RBus_UInt32  y_minthr:8;
    };
}IMG_PPNR_THR_LUMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cb_maxthr:8;
        RBus_UInt32  cb_minthr:8;
        RBus_UInt32  cr_maxthr:8;
        RBus_UInt32  cr_minthr:8;
    };
}IMG_PPNR_THR_CHROMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  t3:8;
        RBus_UInt32  t2:8;
        RBus_UInt32  t1:8;
    };
}IMG_PPNR_SPATIAL_DIFF_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  t3:8;
        RBus_UInt32  t2:8;
        RBus_UInt32  t1:8;
    };
}IMG_PPNR_TEMPORAL_DIFF_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  temporal_k2:8;
        RBus_UInt32  temporal_k1:8;
        RBus_UInt32  spatial_k2:8;
        RBus_UInt32  spatial_k1:8;
    };
}IMG_PPNR_BLEND_LEVEL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2:16;
        RBus_UInt32  s1:16;
    };
}IMG_PPNR_SPATIAL_SLOP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2:16;
        RBus_UInt32  s1:16;
    };
}IMG_PPNR_TEMPORAL_SLOP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hcoef_1:14;
        RBus_UInt32  hcoef_0:14;
    };
}IMG_HCOEF_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vcoef_1:14;
        RBus_UInt32  vcoef_0:14;
    };
}IMG_VCOEF_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  MBVariance:22;
    };
}IMG_MBV_RBUS;

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
}IMG_DBG_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  luma_enable:1;
        RBus_UInt32  chroma_enable:1;
        RBus_UInt32  res1:30;
    };
}IMG_DERING_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filt_prec:2;
        RBus_UInt32  res1:30;
    };
}IMG_FILT_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  init_value:10;
        RBus_UInt32  res1:22;
    };
}IMG_FILT_INIT_RBUS;

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
}IMG_RMRPR_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pixel_offset:13;
        RBus_UInt32  m:4;
        RBus_UInt32  res1:15;
    };
}IMG_RMRPR_PAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ax:32;
    };
}IMG_RMRPR_AX_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ay:32;
    };
}IMG_RMRPR_AY_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ax_inc:32;
    };
}IMG_RMRPR_AXINC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  picmb_w:9;
        RBus_UInt32  picmb_h:8;
        RBus_UInt32  res1:15;
    };
}IMG_RMRPR_PICINFO_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  basea:10;
        RBus_UInt32  res1:22;
    };
}IMG_BASEA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  offseta:9;
        RBus_UInt32  res1:23;
    };
}IMG_OFFSETA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  init_phase:20;
        RBus_UInt32  res1:12;
    };
}IMG_PHASE_INIT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  phase_inc:24;
        RBus_UInt32  res1:8;
    };
}IMG_PHASE_INC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  final_phase:27;
        RBus_UInt32  res1:5;
    };
}IMG_PHASE_OUT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coeff0_n:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  coeff0_n1:12;
        RBus_UInt32  res2:4;
    };
}IMG_TAPCOEFF0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coeff1_n:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  coeff1_n1:12;
        RBus_UInt32  res2:4;
    };
}IMG_TAPCOEFF1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  minSAD:16;
        RBus_UInt32  minValue:8;
        RBus_UInt32  maxValue:8;
    };
}IMG_PPNR_SADY_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  minSAD:16;
        RBus_UInt32  minValue:8;
        RBus_UInt32  maxValue:8;
    };
}IMG_PPNR_SADCB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  minSAD:16;
        RBus_UInt32  minValue:8;
        RBus_UInt32  maxValue:8;
    };
}IMG_PPNR_SADCR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_minthr:8;
        RBus_UInt32  y_maxthr:8;
        RBus_UInt32  res1:16;
    };
}IMG_PPNR_THR_LUMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_minthr:8;
        RBus_UInt32  cr_maxthr:8;
        RBus_UInt32  cb_minthr:8;
        RBus_UInt32  cb_maxthr:8;
    };
}IMG_PPNR_THR_CHROMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t1:8;
        RBus_UInt32  t2:8;
        RBus_UInt32  t3:8;
        RBus_UInt32  res1:8;
    };
}IMG_PPNR_SPATIAL_DIFF_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t1:8;
        RBus_UInt32  t2:8;
        RBus_UInt32  t3:8;
        RBus_UInt32  res1:8;
    };
}IMG_PPNR_TEMPORAL_DIFF_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spatial_k1:8;
        RBus_UInt32  spatial_k2:8;
        RBus_UInt32  temporal_k1:8;
        RBus_UInt32  temporal_k2:8;
    };
}IMG_PPNR_BLEND_LEVEL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:16;
        RBus_UInt32  s2:16;
    };
}IMG_PPNR_SPATIAL_SLOP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:16;
        RBus_UInt32  s2:16;
    };
}IMG_PPNR_TEMPORAL_SLOP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcoef_0:14;
        RBus_UInt32  hcoef_1:14;
        RBus_UInt32  res1:4;
    };
}IMG_HCOEF_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcoef_0:14;
        RBus_UInt32  vcoef_1:14;
        RBus_UInt32  res1:4;
    };
}IMG_VCOEF_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  MBVariance:22;
        RBus_UInt32  res1:10;
    };
}IMG_MBV_RBUS;




#endif 


#endif 
#endif 
