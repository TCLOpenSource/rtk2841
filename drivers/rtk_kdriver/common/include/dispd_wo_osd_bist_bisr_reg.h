/**
* @file rbusDISPD_WO_OSD_BIST_BISRReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DISPD_WO_OSD_BIST_BISR_REG_H_
#define _RBUS_DISPD_WO_OSD_BIST_BISR_REG_H_

#include "rbus_types.h"



//  DISPD_WO_OSD_BIST_BISR Register Address
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE                                  0x18029F00
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_reg_addr                         "0xB8029F00"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_reg                              0xB8029F00
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_inst_addr                        "0x0000"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_reg(data)                    (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_reg                          (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_two_step_uzu_bist_mode_shift     (19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_ch2_mbist_d_hist_1p_bist_mode_shift (18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_ch2_mbist_d_hist_2p_bist_mode_shift (17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_lc_con_bist_mode_shift           (16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_d3d_lut_bist_mode_shift          (15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_shpnr_bist_mode_shift            (14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_icm_3d_table_bist_mode_shift     (13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_icm_hist_1p_bist_mode_shift      (12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_icm_hist_2p_bist_mode_shift      (11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_render_2p_bist_mode_shift        (10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_render_1p_bist_mode_shift        (9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_gamma_bist_mode_shift            (8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_inv_gamma_bist_mode_shift        (7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_su_main_0_bist_mode_shift        (6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_su_main_1_bist_mode_shift        (5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_su_main_2_bist_mode_shift        (4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_su_sub_bist_mode_shift           (3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_dcc_bist_mode_shift              (2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_ch1_mbist_d_hist_1p_bist_mode_shift (1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_ch1_mbist_d_hist_2p_bist_mode_shift (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_two_step_uzu_bist_mode_mask      (0x00080000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_ch2_mbist_d_hist_1p_bist_mode_mask (0x00040000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_ch2_mbist_d_hist_2p_bist_mode_mask (0x00020000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_lc_con_bist_mode_mask            (0x00010000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_d3d_lut_bist_mode_mask           (0x00008000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_shpnr_bist_mode_mask             (0x00004000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_icm_3d_table_bist_mode_mask      (0x00002000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_icm_hist_1p_bist_mode_mask       (0x00001000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_icm_hist_2p_bist_mode_mask       (0x00000800)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_render_2p_bist_mode_mask         (0x00000400)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_render_1p_bist_mode_mask         (0x00000200)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_gamma_bist_mode_mask             (0x00000100)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_inv_gamma_bist_mode_mask         (0x00000080)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_su_main_0_bist_mode_mask         (0x00000040)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_su_main_1_bist_mode_mask         (0x00000020)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_su_main_2_bist_mode_mask         (0x00000010)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_su_sub_bist_mode_mask            (0x00000008)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_dcc_bist_mode_mask               (0x00000004)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_ch1_mbist_d_hist_1p_bist_mode_mask (0x00000002)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_ch1_mbist_d_hist_2p_bist_mode_mask (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_two_step_uzu_bist_mode(data)     (0x00080000&((data)<<19))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_ch2_mbist_d_hist_1p_bist_mode(data) (0x00040000&((data)<<18))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_ch2_mbist_d_hist_2p_bist_mode(data) (0x00020000&((data)<<17))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_lc_con_bist_mode(data)           (0x00010000&((data)<<16))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_d3d_lut_bist_mode(data)          (0x00008000&((data)<<15))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_shpnr_bist_mode(data)            (0x00004000&((data)<<14))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_icm_3d_table_bist_mode(data)     (0x00002000&((data)<<13))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_icm_hist_1p_bist_mode(data)      (0x00001000&((data)<<12))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_icm_hist_2p_bist_mode(data)      (0x00000800&((data)<<11))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_render_2p_bist_mode(data)        (0x00000400&((data)<<10))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_render_1p_bist_mode(data)        (0x00000200&((data)<<9))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_gamma_bist_mode(data)            (0x00000100&((data)<<8))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_inv_gamma_bist_mode(data)        (0x00000080&((data)<<7))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_su_main_0_bist_mode(data)        (0x00000040&((data)<<6))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_su_main_1_bist_mode(data)        (0x00000020&((data)<<5))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_su_main_2_bist_mode(data)        (0x00000010&((data)<<4))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_su_sub_bist_mode(data)           (0x00000008&((data)<<3))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_dcc_bist_mode(data)              (0x00000004&((data)<<2))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_ch1_mbist_d_hist_1p_bist_mode(data) (0x00000002&((data)<<1))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_ch1_mbist_d_hist_2p_bist_mode(data) (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_two_step_uzu_bist_mode(data) ((0x00080000&(data))>>19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_ch2_mbist_d_hist_1p_bist_mode(data) ((0x00040000&(data))>>18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_ch2_mbist_d_hist_2p_bist_mode(data) ((0x00020000&(data))>>17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_lc_con_bist_mode(data)       ((0x00010000&(data))>>16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_d3d_lut_bist_mode(data)      ((0x00008000&(data))>>15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_shpnr_bist_mode(data)        ((0x00004000&(data))>>14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_icm_3d_table_bist_mode(data) ((0x00002000&(data))>>13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_icm_hist_1p_bist_mode(data)  ((0x00001000&(data))>>12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_icm_hist_2p_bist_mode(data)  ((0x00000800&(data))>>11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_render_2p_bist_mode(data)    ((0x00000400&(data))>>10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_render_1p_bist_mode(data)    ((0x00000200&(data))>>9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_gamma_bist_mode(data)        ((0x00000100&(data))>>8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_inv_gamma_bist_mode(data)    ((0x00000080&(data))>>7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_su_main_0_bist_mode(data)    ((0x00000040&(data))>>6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_su_main_1_bist_mode(data)    ((0x00000020&(data))>>5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_su_main_2_bist_mode(data)    ((0x00000010&(data))>>4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_su_sub_bist_mode(data)       ((0x00000008&(data))>>3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_dcc_bist_mode(data)          ((0x00000004&(data))>>2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_ch1_mbist_d_hist_1p_bist_mode(data) ((0x00000002&(data))>>1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_MODE_get_ch1_mbist_d_hist_2p_bist_mode(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE                                  0x18029F04
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_reg_addr                         "0xB8029F04"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_reg                              0xB8029F04
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_inst_addr                        "0x0001"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_reg(data)                    (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_reg                          (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_two_step_uzu_bist_done_shift     (19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_ch2_mbist_d_hist_1p_bist_done_shift (18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_ch2_mbist_d_hist_2p_bist_done_shift (17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_lc_con_bist_done_shift           (16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_d3d_lut_bist_done_shift          (15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_shpnr_bist_done_shift            (14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_icm_3d_table_bist_done_shift     (13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_icm_hist_1p_bist_done_shift      (12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_icm_hist_2p_bist_done_shift      (11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_render_2p_bist_done_shift        (10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_render_1p_bist_done_shift        (9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_gamma_bist_done_shift            (8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_inv_gamma_bist_done_shift        (7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_su_main_0_bist_done_shift        (6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_su_main_1_bist_done_shift        (5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_su_main_2_bist_done_shift        (4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_su_sub_bist_done_shift           (3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_dcc_bist_done_shift              (2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_ch1_mbist_d_hist_1p_bist_done_shift (1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_ch1_mbist_d_hist_2p_bist_done_shift (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_two_step_uzu_bist_done_mask      (0x00080000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_ch2_mbist_d_hist_1p_bist_done_mask (0x00040000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_ch2_mbist_d_hist_2p_bist_done_mask (0x00020000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_lc_con_bist_done_mask            (0x00010000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_d3d_lut_bist_done_mask           (0x00008000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_shpnr_bist_done_mask             (0x00004000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_icm_3d_table_bist_done_mask      (0x00002000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_icm_hist_1p_bist_done_mask       (0x00001000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_icm_hist_2p_bist_done_mask       (0x00000800)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_render_2p_bist_done_mask         (0x00000400)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_render_1p_bist_done_mask         (0x00000200)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_gamma_bist_done_mask             (0x00000100)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_inv_gamma_bist_done_mask         (0x00000080)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_su_main_0_bist_done_mask         (0x00000040)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_su_main_1_bist_done_mask         (0x00000020)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_su_main_2_bist_done_mask         (0x00000010)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_su_sub_bist_done_mask            (0x00000008)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_dcc_bist_done_mask               (0x00000004)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_ch1_mbist_d_hist_1p_bist_done_mask (0x00000002)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_ch1_mbist_d_hist_2p_bist_done_mask (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_two_step_uzu_bist_done(data)     (0x00080000&((data)<<19))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_ch2_mbist_d_hist_1p_bist_done(data) (0x00040000&((data)<<18))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_ch2_mbist_d_hist_2p_bist_done(data) (0x00020000&((data)<<17))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_lc_con_bist_done(data)           (0x00010000&((data)<<16))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_d3d_lut_bist_done(data)          (0x00008000&((data)<<15))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_shpnr_bist_done(data)            (0x00004000&((data)<<14))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_icm_3d_table_bist_done(data)     (0x00002000&((data)<<13))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_icm_hist_1p_bist_done(data)      (0x00001000&((data)<<12))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_icm_hist_2p_bist_done(data)      (0x00000800&((data)<<11))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_render_2p_bist_done(data)        (0x00000400&((data)<<10))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_render_1p_bist_done(data)        (0x00000200&((data)<<9))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_gamma_bist_done(data)            (0x00000100&((data)<<8))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_inv_gamma_bist_done(data)        (0x00000080&((data)<<7))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_su_main_0_bist_done(data)        (0x00000040&((data)<<6))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_su_main_1_bist_done(data)        (0x00000020&((data)<<5))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_su_main_2_bist_done(data)        (0x00000010&((data)<<4))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_su_sub_bist_done(data)           (0x00000008&((data)<<3))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_dcc_bist_done(data)              (0x00000004&((data)<<2))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_ch1_mbist_d_hist_1p_bist_done(data) (0x00000002&((data)<<1))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_ch1_mbist_d_hist_2p_bist_done(data) (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_two_step_uzu_bist_done(data) ((0x00080000&(data))>>19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_ch2_mbist_d_hist_1p_bist_done(data) ((0x00040000&(data))>>18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_ch2_mbist_d_hist_2p_bist_done(data) ((0x00020000&(data))>>17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_lc_con_bist_done(data)       ((0x00010000&(data))>>16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_d3d_lut_bist_done(data)      ((0x00008000&(data))>>15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_shpnr_bist_done(data)        ((0x00004000&(data))>>14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_icm_3d_table_bist_done(data) ((0x00002000&(data))>>13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_icm_hist_1p_bist_done(data)  ((0x00001000&(data))>>12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_icm_hist_2p_bist_done(data)  ((0x00000800&(data))>>11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_render_2p_bist_done(data)    ((0x00000400&(data))>>10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_render_1p_bist_done(data)    ((0x00000200&(data))>>9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_gamma_bist_done(data)        ((0x00000100&(data))>>8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_inv_gamma_bist_done(data)    ((0x00000080&(data))>>7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_su_main_0_bist_done(data)    ((0x00000040&(data))>>6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_su_main_1_bist_done(data)    ((0x00000020&(data))>>5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_su_main_2_bist_done(data)    ((0x00000010&(data))>>4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_su_sub_bist_done(data)       ((0x00000008&(data))>>3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_dcc_bist_done(data)          ((0x00000004&(data))>>2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_ch1_mbist_d_hist_1p_bist_done(data) ((0x00000002&(data))>>1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_DONE_get_ch1_mbist_d_hist_2p_bist_done(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP                            0x18029F08
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_reg_addr                   "0xB8029F08"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_reg                        0xB8029F08
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_inst_addr                  "0x0002"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_reg(data)              (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_reg                    (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_two_step_uzu_bist_fail_group_shift (19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ch2_mbist_d_hist_1p_bist_fail_group_shift (18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ch2_mbist_d_hist_2p_bist_fail_group_shift (17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_lc_con_bist_fail_group_shift (16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_d3d_lut_bist_fail_group_shift (15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_shpnr_bist_fail_group_shift (14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_icm_3d_table_bist_fail_group_shift (13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_icm_hist_1p_bist_fail_group_shift (12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_icm_hist_2p_bist_fail_group_shift (11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_render_2p_bist_fail_group_shift (10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_render_1p_bist_fail_group_shift (9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gamma_bist_fail_group_shift (8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_inv_gamma_bist_fail_group_shift (7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_su_main_0_bist_fail_group_shift (6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_su_main_1_bist_fail_group_shift (5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_su_main_2_bist_fail_group_shift (4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_su_sub_bist_fail_group_shift (3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_dcc_bist_fail_group_shift  (2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ch1_mbist_d_hist_1p_bist_fail_group_shift (1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ch1_mbist_d_hist_2p_bist_fail_group_shift (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_two_step_uzu_bist_fail_group_mask (0x00080000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ch2_mbist_d_hist_1p_bist_fail_group_mask (0x00040000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ch2_mbist_d_hist_2p_bist_fail_group_mask (0x00020000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_lc_con_bist_fail_group_mask (0x00010000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_d3d_lut_bist_fail_group_mask (0x00008000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_shpnr_bist_fail_group_mask (0x00004000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_icm_3d_table_bist_fail_group_mask (0x00002000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_icm_hist_1p_bist_fail_group_mask (0x00001000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_icm_hist_2p_bist_fail_group_mask (0x00000800)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_render_2p_bist_fail_group_mask (0x00000400)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_render_1p_bist_fail_group_mask (0x00000200)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gamma_bist_fail_group_mask (0x00000100)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_inv_gamma_bist_fail_group_mask (0x00000080)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_su_main_0_bist_fail_group_mask (0x00000040)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_su_main_1_bist_fail_group_mask (0x00000020)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_su_main_2_bist_fail_group_mask (0x00000010)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_su_sub_bist_fail_group_mask (0x00000008)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_dcc_bist_fail_group_mask   (0x00000004)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ch1_mbist_d_hist_1p_bist_fail_group_mask (0x00000002)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ch1_mbist_d_hist_2p_bist_fail_group_mask (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_two_step_uzu_bist_fail_group(data) (0x00080000&((data)<<19))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ch2_mbist_d_hist_1p_bist_fail_group(data) (0x00040000&((data)<<18))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ch2_mbist_d_hist_2p_bist_fail_group(data) (0x00020000&((data)<<17))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_lc_con_bist_fail_group(data) (0x00010000&((data)<<16))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_d3d_lut_bist_fail_group(data) (0x00008000&((data)<<15))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_shpnr_bist_fail_group(data) (0x00004000&((data)<<14))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_icm_3d_table_bist_fail_group(data) (0x00002000&((data)<<13))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_icm_hist_1p_bist_fail_group(data) (0x00001000&((data)<<12))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_icm_hist_2p_bist_fail_group(data) (0x00000800&((data)<<11))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_render_2p_bist_fail_group(data) (0x00000400&((data)<<10))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_render_1p_bist_fail_group(data) (0x00000200&((data)<<9))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gamma_bist_fail_group(data) (0x00000100&((data)<<8))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_inv_gamma_bist_fail_group(data) (0x00000080&((data)<<7))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_su_main_0_bist_fail_group(data) (0x00000040&((data)<<6))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_su_main_1_bist_fail_group(data) (0x00000020&((data)<<5))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_su_main_2_bist_fail_group(data) (0x00000010&((data)<<4))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_su_sub_bist_fail_group(data) (0x00000008&((data)<<3))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_dcc_bist_fail_group(data)  (0x00000004&((data)<<2))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ch1_mbist_d_hist_1p_bist_fail_group(data) (0x00000002&((data)<<1))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ch1_mbist_d_hist_2p_bist_fail_group(data) (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_two_step_uzu_bist_fail_group(data) ((0x00080000&(data))>>19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_ch2_mbist_d_hist_1p_bist_fail_group(data) ((0x00040000&(data))>>18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_ch2_mbist_d_hist_2p_bist_fail_group(data) ((0x00020000&(data))>>17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_lc_con_bist_fail_group(data) ((0x00010000&(data))>>16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_d3d_lut_bist_fail_group(data) ((0x00008000&(data))>>15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_shpnr_bist_fail_group(data) ((0x00004000&(data))>>14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_icm_3d_table_bist_fail_group(data) ((0x00002000&(data))>>13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_icm_hist_1p_bist_fail_group(data) ((0x00001000&(data))>>12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_icm_hist_2p_bist_fail_group(data) ((0x00000800&(data))>>11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_render_2p_bist_fail_group(data) ((0x00000400&(data))>>10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_render_1p_bist_fail_group(data) ((0x00000200&(data))>>9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_gamma_bist_fail_group(data) ((0x00000100&(data))>>8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_inv_gamma_bist_fail_group(data) ((0x00000080&(data))>>7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_su_main_0_bist_fail_group(data) ((0x00000040&(data))>>6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_su_main_1_bist_fail_group(data) ((0x00000020&(data))>>5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_su_main_2_bist_fail_group(data) ((0x00000010&(data))>>4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_su_sub_bist_fail_group(data) ((0x00000008&(data))>>3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_dcc_bist_fail_group(data) ((0x00000004&(data))>>2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_ch1_mbist_d_hist_1p_bist_fail_group(data) ((0x00000002&(data))>>1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_ch1_mbist_d_hist_2p_bist_fail_group(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE                                   0x18029F0C
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_reg_addr                          "0xB8029F0C"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_reg                               0xB8029F0C
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_inst_addr                         "0x0003"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_reg(data)                     (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_reg                           (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_two_step_uzu_drf_bist_mode_shift  (19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_ch2_mbist_d_hist_1p_drf_mode_shift (18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_ch2_mbist_d_hist_2p_drf_mode_shift (17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_lc_con_drf_mode_shift             (16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_d3d_lut_drf_mode_shift            (15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_shpnr_drf_mode_shift              (14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_icm_3d_table_drf_mode_shift       (13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_icm_hist_1p_drf_mode_shift        (12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_icm_hist_2p_drf_mode_shift        (11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_render_2p_drf_mode_shift          (10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_render_1p_drf_mode_shift          (9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_gamma_drf_mode_shift              (8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_inv_gamma_drf_mode_shift          (7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_su_main_0_drf_mode_shift          (6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_su_main_1_drf_mode_shift          (5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_su_main_2_drf_mode_shift          (4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_su_sub_drf_mode_shift             (3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_dcc_drf_mode_shift                (2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_ch1_mbist_d_hist_1p_drf_mode_shift (1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_ch1_mbist_d_hist_2p_drf_mode_shift (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_two_step_uzu_drf_bist_mode_mask   (0x00080000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_ch2_mbist_d_hist_1p_drf_mode_mask (0x00040000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_ch2_mbist_d_hist_2p_drf_mode_mask (0x00020000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_lc_con_drf_mode_mask              (0x00010000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_d3d_lut_drf_mode_mask             (0x00008000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_shpnr_drf_mode_mask               (0x00004000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_icm_3d_table_drf_mode_mask        (0x00002000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_icm_hist_1p_drf_mode_mask         (0x00001000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_icm_hist_2p_drf_mode_mask         (0x00000800)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_render_2p_drf_mode_mask           (0x00000400)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_render_1p_drf_mode_mask           (0x00000200)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_gamma_drf_mode_mask               (0x00000100)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_inv_gamma_drf_mode_mask           (0x00000080)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_su_main_0_drf_mode_mask           (0x00000040)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_su_main_1_drf_mode_mask           (0x00000020)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_su_main_2_drf_mode_mask           (0x00000010)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_su_sub_drf_mode_mask              (0x00000008)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_dcc_drf_mode_mask                 (0x00000004)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_ch1_mbist_d_hist_1p_drf_mode_mask (0x00000002)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_ch1_mbist_d_hist_2p_drf_mode_mask (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_two_step_uzu_drf_bist_mode(data)  (0x00080000&((data)<<19))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_ch2_mbist_d_hist_1p_drf_mode(data) (0x00040000&((data)<<18))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_ch2_mbist_d_hist_2p_drf_mode(data) (0x00020000&((data)<<17))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_lc_con_drf_mode(data)             (0x00010000&((data)<<16))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_d3d_lut_drf_mode(data)            (0x00008000&((data)<<15))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_shpnr_drf_mode(data)              (0x00004000&((data)<<14))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_icm_3d_table_drf_mode(data)       (0x00002000&((data)<<13))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_icm_hist_1p_drf_mode(data)        (0x00001000&((data)<<12))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_icm_hist_2p_drf_mode(data)        (0x00000800&((data)<<11))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_render_2p_drf_mode(data)          (0x00000400&((data)<<10))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_render_1p_drf_mode(data)          (0x00000200&((data)<<9))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_gamma_drf_mode(data)              (0x00000100&((data)<<8))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_inv_gamma_drf_mode(data)          (0x00000080&((data)<<7))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_su_main_0_drf_mode(data)          (0x00000040&((data)<<6))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_su_main_1_drf_mode(data)          (0x00000020&((data)<<5))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_su_main_2_drf_mode(data)          (0x00000010&((data)<<4))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_su_sub_drf_mode(data)             (0x00000008&((data)<<3))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_dcc_drf_mode(data)                (0x00000004&((data)<<2))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_ch1_mbist_d_hist_1p_drf_mode(data) (0x00000002&((data)<<1))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_ch1_mbist_d_hist_2p_drf_mode(data) (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_two_step_uzu_drf_bist_mode(data) ((0x00080000&(data))>>19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_ch2_mbist_d_hist_1p_drf_mode(data) ((0x00040000&(data))>>18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_ch2_mbist_d_hist_2p_drf_mode(data) ((0x00020000&(data))>>17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_lc_con_drf_mode(data)         ((0x00010000&(data))>>16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_d3d_lut_drf_mode(data)        ((0x00008000&(data))>>15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_shpnr_drf_mode(data)          ((0x00004000&(data))>>14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_icm_3d_table_drf_mode(data)   ((0x00002000&(data))>>13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_icm_hist_1p_drf_mode(data)    ((0x00001000&(data))>>12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_icm_hist_2p_drf_mode(data)    ((0x00000800&(data))>>11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_render_2p_drf_mode(data)      ((0x00000400&(data))>>10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_render_1p_drf_mode(data)      ((0x00000200&(data))>>9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_gamma_drf_mode(data)          ((0x00000100&(data))>>8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_inv_gamma_drf_mode(data)      ((0x00000080&(data))>>7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_su_main_0_drf_mode(data)      ((0x00000040&(data))>>6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_su_main_1_drf_mode(data)      ((0x00000020&(data))>>5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_su_main_2_drf_mode(data)      ((0x00000010&(data))>>4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_su_sub_drf_mode(data)         ((0x00000008&(data))>>3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_dcc_drf_mode(data)            ((0x00000004&(data))>>2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_ch1_mbist_d_hist_1p_drf_mode(data) ((0x00000002&(data))>>1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_MODE_get_ch1_mbist_d_hist_2p_drf_mode(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME                                 0x18029F10
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_reg_addr                        "0xB8029F10"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_reg                             0xB8029F10
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_inst_addr                       "0x0004"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_reg(data)                   (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_reg                         (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_two_step_uzu_drf_bist_resume_shift (19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_ch2_mbist_d_hist_1p_drf_resume_shift (18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_ch2_mbist_d_hist_2p_drf_resume_shift (17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_lc_con_drf_resume_shift         (16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_d3d_lut_drf_resume_shift        (15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_shpnr_drf_resume_shift          (14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_icm_3d_table_drf_resume_shift   (13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_icm_hist_1p_drf_resume_shift    (12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_icm_hist_2p_drf_resume_shift    (11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_render_2p_drf_resume_shift      (10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_render_1p_drf_resume_shift      (9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_gamma_drf_resume_shift          (8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_inv_gamma_drf_resume_shift      (7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_su_main_0_drf_resume_shift      (6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_su_main_1_drf_resume_shift      (5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_su_main_2_drf_resume_shift      (4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_su_sub_drf_resume_shift         (3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_dcc_drf_resume_shift            (2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_ch1_mbist_d_hist_1p_drf_resume_shift (1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_ch1_mbist_d_hist_2p_drf_resume_shift (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_two_step_uzu_drf_bist_resume_mask (0x00080000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_ch2_mbist_d_hist_1p_drf_resume_mask (0x00040000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_ch2_mbist_d_hist_2p_drf_resume_mask (0x00020000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_lc_con_drf_resume_mask          (0x00010000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_d3d_lut_drf_resume_mask         (0x00008000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_shpnr_drf_resume_mask           (0x00004000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_icm_3d_table_drf_resume_mask    (0x00002000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_icm_hist_1p_drf_resume_mask     (0x00001000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_icm_hist_2p_drf_resume_mask     (0x00000800)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_render_2p_drf_resume_mask       (0x00000400)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_render_1p_drf_resume_mask       (0x00000200)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_gamma_drf_resume_mask           (0x00000100)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_inv_gamma_drf_resume_mask       (0x00000080)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_su_main_0_drf_resume_mask       (0x00000040)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_su_main_1_drf_resume_mask       (0x00000020)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_su_main_2_drf_resume_mask       (0x00000010)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_su_sub_drf_resume_mask          (0x00000008)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_dcc_drf_resume_mask             (0x00000004)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_ch1_mbist_d_hist_1p_drf_resume_mask (0x00000002)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_ch1_mbist_d_hist_2p_drf_resume_mask (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_two_step_uzu_drf_bist_resume(data) (0x00080000&((data)<<19))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_ch2_mbist_d_hist_1p_drf_resume(data) (0x00040000&((data)<<18))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_ch2_mbist_d_hist_2p_drf_resume(data) (0x00020000&((data)<<17))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_lc_con_drf_resume(data)         (0x00010000&((data)<<16))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_d3d_lut_drf_resume(data)        (0x00008000&((data)<<15))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_shpnr_drf_resume(data)          (0x00004000&((data)<<14))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_icm_3d_table_drf_resume(data)   (0x00002000&((data)<<13))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_icm_hist_1p_drf_resume(data)    (0x00001000&((data)<<12))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_icm_hist_2p_drf_resume(data)    (0x00000800&((data)<<11))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_render_2p_drf_resume(data)      (0x00000400&((data)<<10))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_render_1p_drf_resume(data)      (0x00000200&((data)<<9))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_gamma_drf_resume(data)          (0x00000100&((data)<<8))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_inv_gamma_drf_resume(data)      (0x00000080&((data)<<7))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_su_main_0_drf_resume(data)      (0x00000040&((data)<<6))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_su_main_1_drf_resume(data)      (0x00000020&((data)<<5))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_su_main_2_drf_resume(data)      (0x00000010&((data)<<4))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_su_sub_drf_resume(data)         (0x00000008&((data)<<3))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_dcc_drf_resume(data)            (0x00000004&((data)<<2))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_ch1_mbist_d_hist_1p_drf_resume(data) (0x00000002&((data)<<1))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_ch1_mbist_d_hist_2p_drf_resume(data) (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_two_step_uzu_drf_bist_resume(data) ((0x00080000&(data))>>19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_ch2_mbist_d_hist_1p_drf_resume(data) ((0x00040000&(data))>>18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_ch2_mbist_d_hist_2p_drf_resume(data) ((0x00020000&(data))>>17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_lc_con_drf_resume(data)     ((0x00010000&(data))>>16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_d3d_lut_drf_resume(data)    ((0x00008000&(data))>>15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_shpnr_drf_resume(data)      ((0x00004000&(data))>>14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_icm_3d_table_drf_resume(data) ((0x00002000&(data))>>13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_icm_hist_1p_drf_resume(data) ((0x00001000&(data))>>12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_icm_hist_2p_drf_resume(data) ((0x00000800&(data))>>11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_render_2p_drf_resume(data)  ((0x00000400&(data))>>10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_render_1p_drf_resume(data)  ((0x00000200&(data))>>9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_gamma_drf_resume(data)      ((0x00000100&(data))>>8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_inv_gamma_drf_resume(data)  ((0x00000080&(data))>>7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_su_main_0_drf_resume(data)  ((0x00000040&(data))>>6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_su_main_1_drf_resume(data)  ((0x00000020&(data))>>5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_su_main_2_drf_resume(data)  ((0x00000010&(data))>>4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_su_sub_drf_resume(data)     ((0x00000008&(data))>>3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_dcc_drf_resume(data)        ((0x00000004&(data))>>2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_ch1_mbist_d_hist_1p_drf_resume(data) ((0x00000002&(data))>>1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_RESUME_get_ch1_mbist_d_hist_2p_drf_resume(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE                                   0x18029F14
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_reg_addr                          "0xB8029F14"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_reg                               0xB8029F14
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_inst_addr                         "0x0005"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_reg(data)                     (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_reg                           (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_two_step_uzu_drf_bist_done_shift  (19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_ch2_mbist_d_hist_1p_drf_done_shift (18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_ch2_mbist_d_hist_2p_drf_done_shift (17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_lc_con_drf_done_shift             (16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_d3d_lut_drf_done_shift            (15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_shpnr_drf_done_shift              (14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_icm_3d_table_drf_done_shift       (13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_icm_hist_1p_drf_done_shift        (12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_icm_hist_2p_drf_done_shift        (11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_render_2p_drf_done_shift          (10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_render_1p_drf_done_shift          (9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_gamma_drf_done_shift              (8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_inv_gamma_drf_done_shift          (7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_su_main_0_drf_done_shift          (6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_su_main_1_drf_done_shift          (5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_su_main_2_drf_done_shift          (4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_su_sub_drf_done_shift             (3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_dcc_drf_done_shift                (2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_ch1_mbist_d_hist_1p_drf_done_shift (1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_ch1_mbist_d_hist_2p_drf_done_shift (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_two_step_uzu_drf_bist_done_mask   (0x00080000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_ch2_mbist_d_hist_1p_drf_done_mask (0x00040000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_ch2_mbist_d_hist_2p_drf_done_mask (0x00020000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_lc_con_drf_done_mask              (0x00010000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_d3d_lut_drf_done_mask             (0x00008000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_shpnr_drf_done_mask               (0x00004000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_icm_3d_table_drf_done_mask        (0x00002000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_icm_hist_1p_drf_done_mask         (0x00001000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_icm_hist_2p_drf_done_mask         (0x00000800)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_render_2p_drf_done_mask           (0x00000400)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_render_1p_drf_done_mask           (0x00000200)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_gamma_drf_done_mask               (0x00000100)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_inv_gamma_drf_done_mask           (0x00000080)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_su_main_0_drf_done_mask           (0x00000040)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_su_main_1_drf_done_mask           (0x00000020)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_su_main_2_drf_done_mask           (0x00000010)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_su_sub_drf_done_mask              (0x00000008)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_dcc_drf_done_mask                 (0x00000004)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_ch1_mbist_d_hist_1p_drf_done_mask (0x00000002)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_ch1_mbist_d_hist_2p_drf_done_mask (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_two_step_uzu_drf_bist_done(data)  (0x00080000&((data)<<19))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_ch2_mbist_d_hist_1p_drf_done(data) (0x00040000&((data)<<18))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_ch2_mbist_d_hist_2p_drf_done(data) (0x00020000&((data)<<17))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_lc_con_drf_done(data)             (0x00010000&((data)<<16))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_d3d_lut_drf_done(data)            (0x00008000&((data)<<15))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_shpnr_drf_done(data)              (0x00004000&((data)<<14))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_icm_3d_table_drf_done(data)       (0x00002000&((data)<<13))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_icm_hist_1p_drf_done(data)        (0x00001000&((data)<<12))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_icm_hist_2p_drf_done(data)        (0x00000800&((data)<<11))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_render_2p_drf_done(data)          (0x00000400&((data)<<10))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_render_1p_drf_done(data)          (0x00000200&((data)<<9))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_gamma_drf_done(data)              (0x00000100&((data)<<8))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_inv_gamma_drf_done(data)          (0x00000080&((data)<<7))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_su_main_0_drf_done(data)          (0x00000040&((data)<<6))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_su_main_1_drf_done(data)          (0x00000020&((data)<<5))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_su_main_2_drf_done(data)          (0x00000010&((data)<<4))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_su_sub_drf_done(data)             (0x00000008&((data)<<3))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_dcc_drf_done(data)                (0x00000004&((data)<<2))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_ch1_mbist_d_hist_1p_drf_done(data) (0x00000002&((data)<<1))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_ch1_mbist_d_hist_2p_drf_done(data) (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_two_step_uzu_drf_bist_done(data) ((0x00080000&(data))>>19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_ch2_mbist_d_hist_1p_drf_done(data) ((0x00040000&(data))>>18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_ch2_mbist_d_hist_2p_drf_done(data) ((0x00020000&(data))>>17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_lc_con_drf_done(data)         ((0x00010000&(data))>>16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_d3d_lut_drf_done(data)        ((0x00008000&(data))>>15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_shpnr_drf_done(data)          ((0x00004000&(data))>>14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_icm_3d_table_drf_done(data)   ((0x00002000&(data))>>13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_icm_hist_1p_drf_done(data)    ((0x00001000&(data))>>12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_icm_hist_2p_drf_done(data)    ((0x00000800&(data))>>11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_render_2p_drf_done(data)      ((0x00000400&(data))>>10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_render_1p_drf_done(data)      ((0x00000200&(data))>>9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_gamma_drf_done(data)          ((0x00000100&(data))>>8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_inv_gamma_drf_done(data)      ((0x00000080&(data))>>7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_su_main_0_drf_done(data)      ((0x00000040&(data))>>6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_su_main_1_drf_done(data)      ((0x00000020&(data))>>5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_su_main_2_drf_done(data)      ((0x00000010&(data))>>4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_su_sub_drf_done(data)         ((0x00000008&(data))>>3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_dcc_drf_done(data)            ((0x00000004&(data))>>2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_ch1_mbist_d_hist_1p_drf_done(data) ((0x00000002&(data))>>1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_DONE_get_ch1_mbist_d_hist_2p_drf_done(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE                                  0x18029F18
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_reg_addr                         "0xB8029F18"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_reg                              0xB8029F18
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_inst_addr                        "0x0006"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_reg(data)                    (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_reg                          (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_two_step_uzu_drf_start_pause_shift (19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_ch2_mbist_d_hist_1p_drf_pause_shift (18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_ch2_mbist_d_hist_2p_drf_pause_shift (17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_lc_con_drf_pause_shift           (16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_d3d_lut_drf_pause_shift          (15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_shpnr_drf_pause_shift            (14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_icm_3d_table_drf_pause_shift     (13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_icm_hist_1p_drf_pause_shift      (12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_icm_hist_2p_drf_pause_shift      (11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_render_2p_drf_pause_shift        (10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_render_1p_drf_pause_shift        (9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_gamma_drf_pause_shift            (8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_inv_gamma_drf_pause_shift        (7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_su_main_0_drf_pause_shift        (6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_su_main_1_drf_pause_shift        (5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_su_main_2_drf_pause_shift        (4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_su_sub_drf_pause_shift           (3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_dcc_drf_pause_shift              (2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_ch1_mbist_d_hist_1p_drf_pause_shift (1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_ch1_mbist_d_hist_2p_drf_pause_shift (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_two_step_uzu_drf_start_pause_mask (0x00080000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_ch2_mbist_d_hist_1p_drf_pause_mask (0x00040000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_ch2_mbist_d_hist_2p_drf_pause_mask (0x00020000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_lc_con_drf_pause_mask            (0x00010000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_d3d_lut_drf_pause_mask           (0x00008000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_shpnr_drf_pause_mask             (0x00004000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_icm_3d_table_drf_pause_mask      (0x00002000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_icm_hist_1p_drf_pause_mask       (0x00001000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_icm_hist_2p_drf_pause_mask       (0x00000800)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_render_2p_drf_pause_mask         (0x00000400)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_render_1p_drf_pause_mask         (0x00000200)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_gamma_drf_pause_mask             (0x00000100)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_inv_gamma_drf_pause_mask         (0x00000080)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_su_main_0_drf_pause_mask         (0x00000040)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_su_main_1_drf_pause_mask         (0x00000020)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_su_main_2_drf_pause_mask         (0x00000010)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_su_sub_drf_pause_mask            (0x00000008)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_dcc_drf_pause_mask               (0x00000004)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_ch1_mbist_d_hist_1p_drf_pause_mask (0x00000002)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_ch1_mbist_d_hist_2p_drf_pause_mask (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_two_step_uzu_drf_start_pause(data) (0x00080000&((data)<<19))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_ch2_mbist_d_hist_1p_drf_pause(data) (0x00040000&((data)<<18))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_ch2_mbist_d_hist_2p_drf_pause(data) (0x00020000&((data)<<17))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_lc_con_drf_pause(data)           (0x00010000&((data)<<16))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_d3d_lut_drf_pause(data)          (0x00008000&((data)<<15))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_shpnr_drf_pause(data)            (0x00004000&((data)<<14))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_icm_3d_table_drf_pause(data)     (0x00002000&((data)<<13))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_icm_hist_1p_drf_pause(data)      (0x00001000&((data)<<12))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_icm_hist_2p_drf_pause(data)      (0x00000800&((data)<<11))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_render_2p_drf_pause(data)        (0x00000400&((data)<<10))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_render_1p_drf_pause(data)        (0x00000200&((data)<<9))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_gamma_drf_pause(data)            (0x00000100&((data)<<8))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_inv_gamma_drf_pause(data)        (0x00000080&((data)<<7))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_su_main_0_drf_pause(data)        (0x00000040&((data)<<6))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_su_main_1_drf_pause(data)        (0x00000020&((data)<<5))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_su_main_2_drf_pause(data)        (0x00000010&((data)<<4))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_su_sub_drf_pause(data)           (0x00000008&((data)<<3))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_dcc_drf_pause(data)              (0x00000004&((data)<<2))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_ch1_mbist_d_hist_1p_drf_pause(data) (0x00000002&((data)<<1))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_ch1_mbist_d_hist_2p_drf_pause(data) (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_two_step_uzu_drf_start_pause(data) ((0x00080000&(data))>>19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_ch2_mbist_d_hist_1p_drf_pause(data) ((0x00040000&(data))>>18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_ch2_mbist_d_hist_2p_drf_pause(data) ((0x00020000&(data))>>17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_lc_con_drf_pause(data)       ((0x00010000&(data))>>16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_d3d_lut_drf_pause(data)      ((0x00008000&(data))>>15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_shpnr_drf_pause(data)        ((0x00004000&(data))>>14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_icm_3d_table_drf_pause(data) ((0x00002000&(data))>>13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_icm_hist_1p_drf_pause(data)  ((0x00001000&(data))>>12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_icm_hist_2p_drf_pause(data)  ((0x00000800&(data))>>11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_render_2p_drf_pause(data)    ((0x00000400&(data))>>10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_render_1p_drf_pause(data)    ((0x00000200&(data))>>9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_gamma_drf_pause(data)        ((0x00000100&(data))>>8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_inv_gamma_drf_pause(data)    ((0x00000080&(data))>>7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_su_main_0_drf_pause(data)    ((0x00000040&(data))>>6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_su_main_1_drf_pause(data)    ((0x00000020&(data))>>5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_su_main_2_drf_pause(data)    ((0x00000010&(data))>>4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_su_sub_drf_pause(data)       ((0x00000008&(data))>>3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_dcc_drf_pause(data)          ((0x00000004&(data))>>2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_ch1_mbist_d_hist_1p_drf_pause(data) ((0x00000002&(data))>>1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_ch1_mbist_d_hist_2p_drf_pause(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP                             0x18029F1C
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_reg_addr                    "0xB8029F1C"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_reg                         0xB8029F1C
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_inst_addr                   "0x0007"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_reg(data)               (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_reg                     (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_two_step_uzu_drf_bist_fail_group_shift (19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ch2_mbist_d_hist_1p_drf_fail_group_shift (18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ch2_mbist_d_hist_2p_drf_fail_group_shift (17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_lc_con_drf_fail_group_shift (16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_d3d_lut_drf_fail_group_shift (15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_shpnr_drf_fail_group_shift  (14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_icm_3d_table_drf_fail_group_shift (13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_icm_hist_1p_drf_fail_group_shift (12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_icm_hist_2p_drf_fail_group_shift (11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_render_2p_drf_fail_group_shift (10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_render_1p_drf_fail_group_shift (9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gamma_drf_fail_group_shift  (8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_inv_gamma_drf_fail_group_shift (7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_su_main_0_drf_fail_group_shift (6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_su_main_1_drf_fail_group_shift (5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_su_main_2_drf_fail_group_shift (4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_su_sub_drf_fail_group_shift (3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_dcc_drf_fail_group_shift    (2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ch1_mbist_d_hist_1p_drf_fail_group_shift (1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ch1_mbist_d_hist_2p_drf_fail_group_shift (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_two_step_uzu_drf_bist_fail_group_mask (0x00080000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ch2_mbist_d_hist_1p_drf_fail_group_mask (0x00040000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ch2_mbist_d_hist_2p_drf_fail_group_mask (0x00020000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_lc_con_drf_fail_group_mask  (0x00010000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_d3d_lut_drf_fail_group_mask (0x00008000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_shpnr_drf_fail_group_mask   (0x00004000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_icm_3d_table_drf_fail_group_mask (0x00002000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_icm_hist_1p_drf_fail_group_mask (0x00001000)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_icm_hist_2p_drf_fail_group_mask (0x00000800)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_render_2p_drf_fail_group_mask (0x00000400)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_render_1p_drf_fail_group_mask (0x00000200)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gamma_drf_fail_group_mask   (0x00000100)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_inv_gamma_drf_fail_group_mask (0x00000080)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_su_main_0_drf_fail_group_mask (0x00000040)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_su_main_1_drf_fail_group_mask (0x00000020)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_su_main_2_drf_fail_group_mask (0x00000010)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_su_sub_drf_fail_group_mask  (0x00000008)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_dcc_drf_fail_group_mask     (0x00000004)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ch1_mbist_d_hist_1p_drf_fail_group_mask (0x00000002)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ch1_mbist_d_hist_2p_drf_fail_group_mask (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_two_step_uzu_drf_bist_fail_group(data) (0x00080000&((data)<<19))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ch2_mbist_d_hist_1p_drf_fail_group(data) (0x00040000&((data)<<18))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ch2_mbist_d_hist_2p_drf_fail_group(data) (0x00020000&((data)<<17))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_lc_con_drf_fail_group(data) (0x00010000&((data)<<16))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_d3d_lut_drf_fail_group(data) (0x00008000&((data)<<15))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_shpnr_drf_fail_group(data)  (0x00004000&((data)<<14))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_icm_3d_table_drf_fail_group(data) (0x00002000&((data)<<13))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_icm_hist_1p_drf_fail_group(data) (0x00001000&((data)<<12))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_icm_hist_2p_drf_fail_group(data) (0x00000800&((data)<<11))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_render_2p_drf_fail_group(data) (0x00000400&((data)<<10))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_render_1p_drf_fail_group(data) (0x00000200&((data)<<9))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gamma_drf_fail_group(data)  (0x00000100&((data)<<8))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_inv_gamma_drf_fail_group(data) (0x00000080&((data)<<7))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_su_main_0_drf_fail_group(data) (0x00000040&((data)<<6))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_su_main_1_drf_fail_group(data) (0x00000020&((data)<<5))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_su_main_2_drf_fail_group(data) (0x00000010&((data)<<4))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_su_sub_drf_fail_group(data) (0x00000008&((data)<<3))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_dcc_drf_fail_group(data)    (0x00000004&((data)<<2))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ch1_mbist_d_hist_1p_drf_fail_group(data) (0x00000002&((data)<<1))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ch1_mbist_d_hist_2p_drf_fail_group(data) (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_two_step_uzu_drf_bist_fail_group(data) ((0x00080000&(data))>>19)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_ch2_mbist_d_hist_1p_drf_fail_group(data) ((0x00040000&(data))>>18)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_ch2_mbist_d_hist_2p_drf_fail_group(data) ((0x00020000&(data))>>17)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_lc_con_drf_fail_group(data) ((0x00010000&(data))>>16)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_d3d_lut_drf_fail_group(data) ((0x00008000&(data))>>15)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_shpnr_drf_fail_group(data) ((0x00004000&(data))>>14)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_icm_3d_table_drf_fail_group(data) ((0x00002000&(data))>>13)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_icm_hist_1p_drf_fail_group(data) ((0x00001000&(data))>>12)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_icm_hist_2p_drf_fail_group(data) ((0x00000800&(data))>>11)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_render_2p_drf_fail_group(data) ((0x00000400&(data))>>10)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_render_1p_drf_fail_group(data) ((0x00000200&(data))>>9)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_gamma_drf_fail_group(data) ((0x00000100&(data))>>8)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_inv_gamma_drf_fail_group(data) ((0x00000080&(data))>>7)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_su_main_0_drf_fail_group(data) ((0x00000040&(data))>>6)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_su_main_1_drf_fail_group(data) ((0x00000020&(data))>>5)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_su_main_2_drf_fail_group(data) ((0x00000010&(data))>>4)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_su_sub_drf_fail_group(data) ((0x00000008&(data))>>3)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_dcc_drf_fail_group(data) ((0x00000004&(data))>>2)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_ch1_mbist_d_hist_1p_drf_fail_group(data) ((0x00000002&(data))>>1)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_ch1_mbist_d_hist_2p_drf_fail_group(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_SECOND_RUN_EN                         0x18029F40
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_SECOND_RUN_EN_reg_addr                "0xB8029F40"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_SECOND_RUN_EN_reg                     0xB8029F40
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_SECOND_RUN_EN_inst_addr               "0x0008"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_SECOND_RUN_EN_reg(data)           (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_SECOND_RUN_EN_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_SECOND_RUN_EN_reg                 (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_SECOND_RUN_EN_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_SECOND_RUN_EN_shpnr_bisr_second_run_en_shift (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_SECOND_RUN_EN_shpnr_bisr_second_run_en_mask (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_SECOND_RUN_EN_shpnr_bisr_second_run_en(data) (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_SECOND_RUN_EN_get_shpnr_bisr_second_run_en(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_FAIL_GROUP                            0x18029F44
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_FAIL_GROUP_reg_addr                   "0xB8029F44"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_FAIL_GROUP_reg                        0xB8029F44
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_FAIL_GROUP_inst_addr                  "0x0009"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_FAIL_GROUP_reg(data)              (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_FAIL_GROUP_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_FAIL_GROUP_reg                    (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_FAIL_GROUP_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_FAIL_GROUP_shpnr_bisr_fail_group_shift (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_FAIL_GROUP_shpnr_bisr_fail_group_mask (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_FAIL_GROUP_shpnr_bisr_fail_group(data) (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_FAIL_GROUP_get_shpnr_bisr_fail_group(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_MODE                              0x18029F48
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_MODE_reg_addr                     "0xB8029F48"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_MODE_reg                          0xB8029F48
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_MODE_inst_addr                    "0x000A"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_MODE_reg(data)                (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_MODE_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_MODE_reg                      (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_MODE_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_MODE_shpnr_bisr_drf_mode_shift    (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_MODE_shpnr_bisr_drf_mode_mask     (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_MODE_shpnr_bisr_drf_mode(data)    (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_MODE_get_shpnr_bisr_drf_mode(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_RESUME                            0x18029F4C
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_RESUME_reg_addr                   "0xB8029F4C"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_RESUME_reg                        0xB8029F4C
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_RESUME_inst_addr                  "0x000B"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_RESUME_reg(data)              (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_RESUME_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_RESUME_reg                    (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_RESUME_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_RESUME_shpnr_bisr_drf_resume_shift (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_RESUME_shpnr_bisr_drf_resume_mask (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_RESUME_shpnr_bisr_drf_resume(data) (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_RESUME_get_shpnr_bisr_drf_resume(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_DONE                              0x18029F50
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_DONE_reg_addr                     "0xB8029F50"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_DONE_reg                          0xB8029F50
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_DONE_inst_addr                    "0x000C"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_DONE_reg(data)                (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_DONE_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_DONE_reg                      (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_DONE_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_DONE_shpnr_bisr_drf_done_shift    (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_DONE_shpnr_bisr_drf_done_mask     (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_DONE_shpnr_bisr_drf_done(data)    (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_DONE_get_shpnr_bisr_drf_done(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_PAUSE                             0x18029F54
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_PAUSE_reg_addr                    "0xB8029F54"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_PAUSE_reg                         0xB8029F54
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_PAUSE_inst_addr                   "0x000D"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_PAUSE_reg(data)               (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_PAUSE_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_PAUSE_reg                     (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_PAUSE_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_PAUSE_shpnr_bisr_drf_pause_shift  (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_PAUSE_shpnr_bisr_drf_pause_mask   (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_PAUSE_shpnr_bisr_drf_pause(data)  (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_PAUSE_get_shpnr_bisr_drf_pause(data) (0x00000001&(data))

#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_FAIL_GROUP                        0x18029F58
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_FAIL_GROUP_reg_addr               "0xB8029F58"
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_FAIL_GROUP_reg                    0xB8029F58
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_FAIL_GROUP_inst_addr              "0x000E"
#define  set_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_FAIL_GROUP_reg(data)          (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_FAIL_GROUP_reg)=data)
#define  get_DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_FAIL_GROUP_reg                (*((volatile unsigned int*)DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_FAIL_GROUP_reg))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_FAIL_GROUP_shpnr_bisr_drf_fail_group_shift (0)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_FAIL_GROUP_shpnr_bisr_drf_fail_group_mask (0x00000001)
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_FAIL_GROUP_shpnr_bisr_drf_fail_group(data) (0x00000001&(data))
#define  DISPD_WO_OSD_BIST_BISR_DISPD_BISR_DRF_FAIL_GROUP_get_shpnr_bisr_drf_fail_group(data) (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DISPD_WO_OSD_BIST_BISR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  two_step_uzu_bist_mode:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_bist_mode:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_bist_mode:1;
        RBus_UInt32  lc_con_bist_mode:1;
        RBus_UInt32  d3d_lut_bist_mode:1;
        RBus_UInt32  shpnr_bist_mode:1;
        RBus_UInt32  icm_3d_table_bist_mode:1;
        RBus_UInt32  icm_hist_1p_bist_mode:1;
        RBus_UInt32  icm_hist_2p_bist_mode:1;
        RBus_UInt32  render_2p_bist_mode:1;
        RBus_UInt32  render_1p_bist_mode:1;
        RBus_UInt32  gamma_bist_mode:1;
        RBus_UInt32  inv_gamma_bist_mode:1;
        RBus_UInt32  su_main_0_bist_mode:1;
        RBus_UInt32  su_main_1_bist_mode:1;
        RBus_UInt32  su_main_2_bist_mode:1;
        RBus_UInt32  su_sub_bist_mode:1;
        RBus_UInt32  dcc_bist_mode:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_bist_mode:1;
        RBus_UInt32  ch1_mbist_d_hist_2p_bist_mode:1;
    };
}dispd_wo_osd_bist_bisr_dispd_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  two_step_uzu_bist_done:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_bist_done:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_bist_done:1;
        RBus_UInt32  lc_con_bist_done:1;
        RBus_UInt32  d3d_lut_bist_done:1;
        RBus_UInt32  shpnr_bist_done:1;
        RBus_UInt32  icm_3d_table_bist_done:1;
        RBus_UInt32  icm_hist_1p_bist_done:1;
        RBus_UInt32  icm_hist_2p_bist_done:1;
        RBus_UInt32  render_2p_bist_done:1;
        RBus_UInt32  render_1p_bist_done:1;
        RBus_UInt32  gamma_bist_done:1;
        RBus_UInt32  inv_gamma_bist_done:1;
        RBus_UInt32  su_main_0_bist_done:1;
        RBus_UInt32  su_main_1_bist_done:1;
        RBus_UInt32  su_main_2_bist_done:1;
        RBus_UInt32  su_sub_bist_done:1;
        RBus_UInt32  dcc_bist_done:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_bist_done:1;
        RBus_UInt32  ch1_mbist_d_hist_2p_bist_done:1;
    };
}dispd_wo_osd_bist_bisr_dispd_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  two_step_uzu_bist_fail_group:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_bist_fail_group:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_bist_fail_group:1;
        RBus_UInt32  lc_con_bist_fail_group:1;
        RBus_UInt32  d3d_lut_bist_fail_group:1;
        RBus_UInt32  shpnr_bist_fail_group:1;
        RBus_UInt32  icm_3d_table_bist_fail_group:1;
        RBus_UInt32  icm_hist_1p_bist_fail_group:1;
        RBus_UInt32  icm_hist_2p_bist_fail_group:1;
        RBus_UInt32  render_2p_bist_fail_group:1;
        RBus_UInt32  render_1p_bist_fail_group:1;
        RBus_UInt32  gamma_bist_fail_group:1;
        RBus_UInt32  inv_gamma_bist_fail_group:1;
        RBus_UInt32  su_main_0_bist_fail_group:1;
        RBus_UInt32  su_main_1_bist_fail_group:1;
        RBus_UInt32  su_main_2_bist_fail_group:1;
        RBus_UInt32  su_sub_bist_fail_group:1;
        RBus_UInt32  dcc_bist_fail_group:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_bist_fail_group:1;
        RBus_UInt32  ch1_mbist_d_hist_2p_bist_fail_group:1;
    };
}dispd_wo_osd_bist_bisr_dispd_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  two_step_uzu_drf_bist_mode:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_drf_mode:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_drf_mode:1;
        RBus_UInt32  lc_con_drf_mode:1;
        RBus_UInt32  d3d_lut_drf_mode:1;
        RBus_UInt32  shpnr_drf_mode:1;
        RBus_UInt32  icm_3d_table_drf_mode:1;
        RBus_UInt32  icm_hist_1p_drf_mode:1;
        RBus_UInt32  icm_hist_2p_drf_mode:1;
        RBus_UInt32  render_2p_drf_mode:1;
        RBus_UInt32  render_1p_drf_mode:1;
        RBus_UInt32  gamma_drf_mode:1;
        RBus_UInt32  inv_gamma_drf_mode:1;
        RBus_UInt32  su_main_0_drf_mode:1;
        RBus_UInt32  su_main_1_drf_mode:1;
        RBus_UInt32  su_main_2_drf_mode:1;
        RBus_UInt32  su_sub_drf_mode:1;
        RBus_UInt32  dcc_drf_mode:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_drf_mode:1;
        RBus_UInt32  ch1_mbist_d_hist_2p_drf_mode:1;
    };
}dispd_wo_osd_bist_bisr_dispd_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  two_step_uzu_drf_bist_resume:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_drf_resume:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_drf_resume:1;
        RBus_UInt32  lc_con_drf_resume:1;
        RBus_UInt32  d3d_lut_drf_resume:1;
        RBus_UInt32  shpnr_drf_resume:1;
        RBus_UInt32  icm_3d_table_drf_resume:1;
        RBus_UInt32  icm_hist_1p_drf_resume:1;
        RBus_UInt32  icm_hist_2p_drf_resume:1;
        RBus_UInt32  render_2p_drf_resume:1;
        RBus_UInt32  render_1p_drf_resume:1;
        RBus_UInt32  gamma_drf_resume:1;
        RBus_UInt32  inv_gamma_drf_resume:1;
        RBus_UInt32  su_main_0_drf_resume:1;
        RBus_UInt32  su_main_1_drf_resume:1;
        RBus_UInt32  su_main_2_drf_resume:1;
        RBus_UInt32  su_sub_drf_resume:1;
        RBus_UInt32  dcc_drf_resume:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_drf_resume:1;
        RBus_UInt32  ch1_mbist_d_hist_2p_drf_resume:1;
    };
}dispd_wo_osd_bist_bisr_dispd_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  two_step_uzu_drf_bist_done:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_drf_done:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_drf_done:1;
        RBus_UInt32  lc_con_drf_done:1;
        RBus_UInt32  d3d_lut_drf_done:1;
        RBus_UInt32  shpnr_drf_done:1;
        RBus_UInt32  icm_3d_table_drf_done:1;
        RBus_UInt32  icm_hist_1p_drf_done:1;
        RBus_UInt32  icm_hist_2p_drf_done:1;
        RBus_UInt32  render_2p_drf_done:1;
        RBus_UInt32  render_1p_drf_done:1;
        RBus_UInt32  gamma_drf_done:1;
        RBus_UInt32  inv_gamma_drf_done:1;
        RBus_UInt32  su_main_0_drf_done:1;
        RBus_UInt32  su_main_1_drf_done:1;
        RBus_UInt32  su_main_2_drf_done:1;
        RBus_UInt32  su_sub_drf_done:1;
        RBus_UInt32  dcc_drf_done:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_drf_done:1;
        RBus_UInt32  ch1_mbist_d_hist_2p_drf_done:1;
    };
}dispd_wo_osd_bist_bisr_dispd_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  two_step_uzu_drf_start_pause:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_drf_pause:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_drf_pause:1;
        RBus_UInt32  lc_con_drf_pause:1;
        RBus_UInt32  d3d_lut_drf_pause:1;
        RBus_UInt32  shpnr_drf_pause:1;
        RBus_UInt32  icm_3d_table_drf_pause:1;
        RBus_UInt32  icm_hist_1p_drf_pause:1;
        RBus_UInt32  icm_hist_2p_drf_pause:1;
        RBus_UInt32  render_2p_drf_pause:1;
        RBus_UInt32  render_1p_drf_pause:1;
        RBus_UInt32  gamma_drf_pause:1;
        RBus_UInt32  inv_gamma_drf_pause:1;
        RBus_UInt32  su_main_0_drf_pause:1;
        RBus_UInt32  su_main_1_drf_pause:1;
        RBus_UInt32  su_main_2_drf_pause:1;
        RBus_UInt32  su_sub_drf_pause:1;
        RBus_UInt32  dcc_drf_pause:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_drf_pause:1;
        RBus_UInt32  ch1_mbist_d_hist_2p_drf_pause:1;
    };
}dispd_wo_osd_bist_bisr_dispd_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  two_step_uzu_drf_bist_fail_group:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_drf_fail_group:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_drf_fail_group:1;
        RBus_UInt32  lc_con_drf_fail_group:1;
        RBus_UInt32  d3d_lut_drf_fail_group:1;
        RBus_UInt32  shpnr_drf_fail_group:1;
        RBus_UInt32  icm_3d_table_drf_fail_group:1;
        RBus_UInt32  icm_hist_1p_drf_fail_group:1;
        RBus_UInt32  icm_hist_2p_drf_fail_group:1;
        RBus_UInt32  render_2p_drf_fail_group:1;
        RBus_UInt32  render_1p_drf_fail_group:1;
        RBus_UInt32  gamma_drf_fail_group:1;
        RBus_UInt32  inv_gamma_drf_fail_group:1;
        RBus_UInt32  su_main_0_drf_fail_group:1;
        RBus_UInt32  su_main_1_drf_fail_group:1;
        RBus_UInt32  su_main_2_drf_fail_group:1;
        RBus_UInt32  su_sub_drf_fail_group:1;
        RBus_UInt32  dcc_drf_fail_group:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_drf_fail_group:1;
        RBus_UInt32  ch1_mbist_d_hist_2p_drf_fail_group:1;
    };
}dispd_wo_osd_bist_bisr_dispd_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  shpnr_bisr_second_run_en:1;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_second_run_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  shpnr_bisr_fail_group:1;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  shpnr_bisr_drf_mode:1;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  shpnr_bisr_drf_resume:1;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  shpnr_bisr_drf_done:1;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  shpnr_bisr_drf_pause:1;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  shpnr_bisr_drf_fail_group:1;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_drf_fail_group_RBUS;

#else //apply LITTLE_ENDIAN

//======DISPD_WO_OSD_BIST_BISR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_mbist_d_hist_2p_bist_mode:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_bist_mode:1;
        RBus_UInt32  dcc_bist_mode:1;
        RBus_UInt32  su_sub_bist_mode:1;
        RBus_UInt32  su_main_2_bist_mode:1;
        RBus_UInt32  su_main_1_bist_mode:1;
        RBus_UInt32  su_main_0_bist_mode:1;
        RBus_UInt32  inv_gamma_bist_mode:1;
        RBus_UInt32  gamma_bist_mode:1;
        RBus_UInt32  render_1p_bist_mode:1;
        RBus_UInt32  render_2p_bist_mode:1;
        RBus_UInt32  icm_hist_2p_bist_mode:1;
        RBus_UInt32  icm_hist_1p_bist_mode:1;
        RBus_UInt32  icm_3d_table_bist_mode:1;
        RBus_UInt32  shpnr_bist_mode:1;
        RBus_UInt32  d3d_lut_bist_mode:1;
        RBus_UInt32  lc_con_bist_mode:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_bist_mode:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_bist_mode:1;
        RBus_UInt32  two_step_uzu_bist_mode:1;
        RBus_UInt32  res1:12;
    };
}dispd_wo_osd_bist_bisr_dispd_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_mbist_d_hist_2p_bist_done:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_bist_done:1;
        RBus_UInt32  dcc_bist_done:1;
        RBus_UInt32  su_sub_bist_done:1;
        RBus_UInt32  su_main_2_bist_done:1;
        RBus_UInt32  su_main_1_bist_done:1;
        RBus_UInt32  su_main_0_bist_done:1;
        RBus_UInt32  inv_gamma_bist_done:1;
        RBus_UInt32  gamma_bist_done:1;
        RBus_UInt32  render_1p_bist_done:1;
        RBus_UInt32  render_2p_bist_done:1;
        RBus_UInt32  icm_hist_2p_bist_done:1;
        RBus_UInt32  icm_hist_1p_bist_done:1;
        RBus_UInt32  icm_3d_table_bist_done:1;
        RBus_UInt32  shpnr_bist_done:1;
        RBus_UInt32  d3d_lut_bist_done:1;
        RBus_UInt32  lc_con_bist_done:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_bist_done:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_bist_done:1;
        RBus_UInt32  two_step_uzu_bist_done:1;
        RBus_UInt32  res1:12;
    };
}dispd_wo_osd_bist_bisr_dispd_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_mbist_d_hist_2p_bist_fail_group:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_bist_fail_group:1;
        RBus_UInt32  dcc_bist_fail_group:1;
        RBus_UInt32  su_sub_bist_fail_group:1;
        RBus_UInt32  su_main_2_bist_fail_group:1;
        RBus_UInt32  su_main_1_bist_fail_group:1;
        RBus_UInt32  su_main_0_bist_fail_group:1;
        RBus_UInt32  inv_gamma_bist_fail_group:1;
        RBus_UInt32  gamma_bist_fail_group:1;
        RBus_UInt32  render_1p_bist_fail_group:1;
        RBus_UInt32  render_2p_bist_fail_group:1;
        RBus_UInt32  icm_hist_2p_bist_fail_group:1;
        RBus_UInt32  icm_hist_1p_bist_fail_group:1;
        RBus_UInt32  icm_3d_table_bist_fail_group:1;
        RBus_UInt32  shpnr_bist_fail_group:1;
        RBus_UInt32  d3d_lut_bist_fail_group:1;
        RBus_UInt32  lc_con_bist_fail_group:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_bist_fail_group:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_bist_fail_group:1;
        RBus_UInt32  two_step_uzu_bist_fail_group:1;
        RBus_UInt32  res1:12;
    };
}dispd_wo_osd_bist_bisr_dispd_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_mbist_d_hist_2p_drf_mode:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_drf_mode:1;
        RBus_UInt32  dcc_drf_mode:1;
        RBus_UInt32  su_sub_drf_mode:1;
        RBus_UInt32  su_main_2_drf_mode:1;
        RBus_UInt32  su_main_1_drf_mode:1;
        RBus_UInt32  su_main_0_drf_mode:1;
        RBus_UInt32  inv_gamma_drf_mode:1;
        RBus_UInt32  gamma_drf_mode:1;
        RBus_UInt32  render_1p_drf_mode:1;
        RBus_UInt32  render_2p_drf_mode:1;
        RBus_UInt32  icm_hist_2p_drf_mode:1;
        RBus_UInt32  icm_hist_1p_drf_mode:1;
        RBus_UInt32  icm_3d_table_drf_mode:1;
        RBus_UInt32  shpnr_drf_mode:1;
        RBus_UInt32  d3d_lut_drf_mode:1;
        RBus_UInt32  lc_con_drf_mode:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_drf_mode:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_drf_mode:1;
        RBus_UInt32  two_step_uzu_drf_bist_mode:1;
        RBus_UInt32  res1:12;
    };
}dispd_wo_osd_bist_bisr_dispd_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_mbist_d_hist_2p_drf_resume:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_drf_resume:1;
        RBus_UInt32  dcc_drf_resume:1;
        RBus_UInt32  su_sub_drf_resume:1;
        RBus_UInt32  su_main_2_drf_resume:1;
        RBus_UInt32  su_main_1_drf_resume:1;
        RBus_UInt32  su_main_0_drf_resume:1;
        RBus_UInt32  inv_gamma_drf_resume:1;
        RBus_UInt32  gamma_drf_resume:1;
        RBus_UInt32  render_1p_drf_resume:1;
        RBus_UInt32  render_2p_drf_resume:1;
        RBus_UInt32  icm_hist_2p_drf_resume:1;
        RBus_UInt32  icm_hist_1p_drf_resume:1;
        RBus_UInt32  icm_3d_table_drf_resume:1;
        RBus_UInt32  shpnr_drf_resume:1;
        RBus_UInt32  d3d_lut_drf_resume:1;
        RBus_UInt32  lc_con_drf_resume:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_drf_resume:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_drf_resume:1;
        RBus_UInt32  two_step_uzu_drf_bist_resume:1;
        RBus_UInt32  res1:12;
    };
}dispd_wo_osd_bist_bisr_dispd_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_mbist_d_hist_2p_drf_done:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_drf_done:1;
        RBus_UInt32  dcc_drf_done:1;
        RBus_UInt32  su_sub_drf_done:1;
        RBus_UInt32  su_main_2_drf_done:1;
        RBus_UInt32  su_main_1_drf_done:1;
        RBus_UInt32  su_main_0_drf_done:1;
        RBus_UInt32  inv_gamma_drf_done:1;
        RBus_UInt32  gamma_drf_done:1;
        RBus_UInt32  render_1p_drf_done:1;
        RBus_UInt32  render_2p_drf_done:1;
        RBus_UInt32  icm_hist_2p_drf_done:1;
        RBus_UInt32  icm_hist_1p_drf_done:1;
        RBus_UInt32  icm_3d_table_drf_done:1;
        RBus_UInt32  shpnr_drf_done:1;
        RBus_UInt32  d3d_lut_drf_done:1;
        RBus_UInt32  lc_con_drf_done:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_drf_done:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_drf_done:1;
        RBus_UInt32  two_step_uzu_drf_bist_done:1;
        RBus_UInt32  res1:12;
    };
}dispd_wo_osd_bist_bisr_dispd_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_mbist_d_hist_2p_drf_pause:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_drf_pause:1;
        RBus_UInt32  dcc_drf_pause:1;
        RBus_UInt32  su_sub_drf_pause:1;
        RBus_UInt32  su_main_2_drf_pause:1;
        RBus_UInt32  su_main_1_drf_pause:1;
        RBus_UInt32  su_main_0_drf_pause:1;
        RBus_UInt32  inv_gamma_drf_pause:1;
        RBus_UInt32  gamma_drf_pause:1;
        RBus_UInt32  render_1p_drf_pause:1;
        RBus_UInt32  render_2p_drf_pause:1;
        RBus_UInt32  icm_hist_2p_drf_pause:1;
        RBus_UInt32  icm_hist_1p_drf_pause:1;
        RBus_UInt32  icm_3d_table_drf_pause:1;
        RBus_UInt32  shpnr_drf_pause:1;
        RBus_UInt32  d3d_lut_drf_pause:1;
        RBus_UInt32  lc_con_drf_pause:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_drf_pause:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_drf_pause:1;
        RBus_UInt32  two_step_uzu_drf_start_pause:1;
        RBus_UInt32  res1:12;
    };
}dispd_wo_osd_bist_bisr_dispd_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_mbist_d_hist_2p_drf_fail_group:1;
        RBus_UInt32  ch1_mbist_d_hist_1p_drf_fail_group:1;
        RBus_UInt32  dcc_drf_fail_group:1;
        RBus_UInt32  su_sub_drf_fail_group:1;
        RBus_UInt32  su_main_2_drf_fail_group:1;
        RBus_UInt32  su_main_1_drf_fail_group:1;
        RBus_UInt32  su_main_0_drf_fail_group:1;
        RBus_UInt32  inv_gamma_drf_fail_group:1;
        RBus_UInt32  gamma_drf_fail_group:1;
        RBus_UInt32  render_1p_drf_fail_group:1;
        RBus_UInt32  render_2p_drf_fail_group:1;
        RBus_UInt32  icm_hist_2p_drf_fail_group:1;
        RBus_UInt32  icm_hist_1p_drf_fail_group:1;
        RBus_UInt32  icm_3d_table_drf_fail_group:1;
        RBus_UInt32  shpnr_drf_fail_group:1;
        RBus_UInt32  d3d_lut_drf_fail_group:1;
        RBus_UInt32  lc_con_drf_fail_group:1;
        RBus_UInt32  ch2_mbist_d_hist_2p_drf_fail_group:1;
        RBus_UInt32  ch2_mbist_d_hist_1p_drf_fail_group:1;
        RBus_UInt32  two_step_uzu_drf_bist_fail_group:1;
        RBus_UInt32  res1:12;
    };
}dispd_wo_osd_bist_bisr_dispd_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shpnr_bisr_second_run_en:1;
        RBus_UInt32  res1:31;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_second_run_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shpnr_bisr_fail_group:1;
        RBus_UInt32  res1:31;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shpnr_bisr_drf_mode:1;
        RBus_UInt32  res1:31;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shpnr_bisr_drf_resume:1;
        RBus_UInt32  res1:31;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shpnr_bisr_drf_done:1;
        RBus_UInt32  res1:31;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shpnr_bisr_drf_pause:1;
        RBus_UInt32  res1:31;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shpnr_bisr_drf_fail_group:1;
        RBus_UInt32  res1:31;
    };
}dispd_wo_osd_bist_bisr_dispd_bisr_drf_fail_group_RBUS;




#endif 


#endif 
