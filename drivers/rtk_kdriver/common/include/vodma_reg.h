/**
* @file rbusVODMAReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/12/21
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VODMA_REG_H_
#define _RBUS_VODMA_REG_H_

#include "rbusTypes.h"



//  VODMA Register Address
#define  VODMA_VODMA_V1_DCFG                                                     0x18005000
#define  VODMA_VODMA_V1_DCFG_reg_addr                                            "0xB8005000"
#define  VODMA_VODMA_V1_DCFG_reg                                                 0xB8005000
#define  VODMA_VODMA_V1_DCFG_inst_addr                                           "0x0000"
#define  set_VODMA_VODMA_V1_DCFG_reg(data)                                       (*((volatile unsigned int*)VODMA_VODMA_V1_DCFG_reg)=data)
#define  get_VODMA_VODMA_V1_DCFG_reg                                             (*((volatile unsigned int*)VODMA_VODMA_V1_DCFG_reg))
#define  VODMA_VODMA_V1_DCFG_merge_forward_shift                                 (31)
#define  VODMA_VODMA_V1_DCFG_merge_backward_shift                                (30)
#define  VODMA_VODMA_V1_DCFG_pd_switch_shift                                     (29)
#define  VODMA_VODMA_V1_DCFG_pd_seq_shift                                        (24)
#define  VODMA_VODMA_V1_DCFG_film_condition_shift                                (23)
#define  VODMA_VODMA_V1_DCFG_field_mode_shift                                    (20)
#define  VODMA_VODMA_V1_DCFG_field_fw_shift                                      (19)
#define  VODMA_VODMA_V1_DCFG_l_flag_fw_shift                                     (18)
#define  VODMA_VODMA_V1_DCFG_force_2d_en_shift                                   (17)
#define  VODMA_VODMA_V1_DCFG_force_2d_sel_shift                                  (16)
#define  VODMA_VODMA_V1_DCFG_dma_auto_mode_shift                                 (15)
#define  VODMA_VODMA_V1_DCFG_seq_data_pack_type_shift                            (14)
#define  VODMA_VODMA_V1_DCFG_seq_data_width_shift                                (13)
#define  VODMA_VODMA_V1_DCFG_double_chroma_shift                                 (12)
#define  VODMA_VODMA_V1_DCFG_uv_off_shift                                        (11)
#define  VODMA_VODMA_V1_DCFG_pxl_swap_sel_shift                                  (7)
#define  VODMA_VODMA_V1_DCFG_keep_go_en_shift                                    (6)
#define  VODMA_VODMA_V1_DCFG_dma_state_reset_en_shift                            (5)
#define  VODMA_VODMA_V1_DCFG_v_flip_en_shift                                     (4)
#define  VODMA_VODMA_V1_DCFG_chroma_swap_en_shift                                (3)
#define  VODMA_VODMA_V1_DCFG_double_pixel_mode_shift                             (2)
#define  VODMA_VODMA_V1_DCFG_dma_mode_shift                                      (1)
#define  VODMA_VODMA_V1_DCFG_vodma_go_shift                                      (0)
#define  VODMA_VODMA_V1_DCFG_merge_forward_mask                                  (0x80000000)
#define  VODMA_VODMA_V1_DCFG_merge_backward_mask                                 (0x40000000)
#define  VODMA_VODMA_V1_DCFG_pd_switch_mask                                      (0x20000000)
#define  VODMA_VODMA_V1_DCFG_pd_seq_mask                                         (0x1F000000)
#define  VODMA_VODMA_V1_DCFG_film_condition_mask                                 (0x00800000)
#define  VODMA_VODMA_V1_DCFG_field_mode_mask                                     (0x00100000)
#define  VODMA_VODMA_V1_DCFG_field_fw_mask                                       (0x00080000)
#define  VODMA_VODMA_V1_DCFG_l_flag_fw_mask                                      (0x00040000)
#define  VODMA_VODMA_V1_DCFG_force_2d_en_mask                                    (0x00020000)
#define  VODMA_VODMA_V1_DCFG_force_2d_sel_mask                                   (0x00010000)
#define  VODMA_VODMA_V1_DCFG_dma_auto_mode_mask                                  (0x00008000)
#define  VODMA_VODMA_V1_DCFG_seq_data_pack_type_mask                             (0x00004000)
#define  VODMA_VODMA_V1_DCFG_seq_data_width_mask                                 (0x00002000)
#define  VODMA_VODMA_V1_DCFG_double_chroma_mask                                  (0x00001000)
#define  VODMA_VODMA_V1_DCFG_uv_off_mask                                         (0x00000800)
#define  VODMA_VODMA_V1_DCFG_pxl_swap_sel_mask                                   (0x00000780)
#define  VODMA_VODMA_V1_DCFG_keep_go_en_mask                                     (0x00000040)
#define  VODMA_VODMA_V1_DCFG_dma_state_reset_en_mask                             (0x00000020)
#define  VODMA_VODMA_V1_DCFG_v_flip_en_mask                                      (0x00000010)
#define  VODMA_VODMA_V1_DCFG_chroma_swap_en_mask                                 (0x00000008)
#define  VODMA_VODMA_V1_DCFG_double_pixel_mode_mask                              (0x00000004)
#define  VODMA_VODMA_V1_DCFG_dma_mode_mask                                       (0x00000002)
#define  VODMA_VODMA_V1_DCFG_vodma_go_mask                                       (0x00000001)
#define  VODMA_VODMA_V1_DCFG_merge_forward(data)                                 (0x80000000&((data)<<31))
#define  VODMA_VODMA_V1_DCFG_merge_backward(data)                                (0x40000000&((data)<<30))
#define  VODMA_VODMA_V1_DCFG_pd_switch(data)                                     (0x20000000&((data)<<29))
#define  VODMA_VODMA_V1_DCFG_pd_seq(data)                                        (0x1F000000&((data)<<24))
#define  VODMA_VODMA_V1_DCFG_film_condition(data)                                (0x00800000&((data)<<23))
#define  VODMA_VODMA_V1_DCFG_field_mode(data)                                    (0x00100000&((data)<<20))
#define  VODMA_VODMA_V1_DCFG_field_fw(data)                                      (0x00080000&((data)<<19))
#define  VODMA_VODMA_V1_DCFG_l_flag_fw(data)                                     (0x00040000&((data)<<18))
#define  VODMA_VODMA_V1_DCFG_force_2d_en(data)                                   (0x00020000&((data)<<17))
#define  VODMA_VODMA_V1_DCFG_force_2d_sel(data)                                  (0x00010000&((data)<<16))
#define  VODMA_VODMA_V1_DCFG_dma_auto_mode(data)                                 (0x00008000&((data)<<15))
#define  VODMA_VODMA_V1_DCFG_seq_data_pack_type(data)                            (0x00004000&((data)<<14))
#define  VODMA_VODMA_V1_DCFG_seq_data_width(data)                                (0x00002000&((data)<<13))
#define  VODMA_VODMA_V1_DCFG_double_chroma(data)                                 (0x00001000&((data)<<12))
#define  VODMA_VODMA_V1_DCFG_uv_off(data)                                        (0x00000800&((data)<<11))
#define  VODMA_VODMA_V1_DCFG_pxl_swap_sel(data)                                  (0x00000780&((data)<<7))
#define  VODMA_VODMA_V1_DCFG_keep_go_en(data)                                    (0x00000040&((data)<<6))
#define  VODMA_VODMA_V1_DCFG_dma_state_reset_en(data)                            (0x00000020&((data)<<5))
#define  VODMA_VODMA_V1_DCFG_v_flip_en(data)                                     (0x00000010&((data)<<4))
#define  VODMA_VODMA_V1_DCFG_chroma_swap_en(data)                                (0x00000008&((data)<<3))
#define  VODMA_VODMA_V1_DCFG_double_pixel_mode(data)                             (0x00000004&((data)<<2))
#define  VODMA_VODMA_V1_DCFG_dma_mode(data)                                      (0x00000002&((data)<<1))
#define  VODMA_VODMA_V1_DCFG_vodma_go(data)                                      (0x00000001&(data))
#define  VODMA_VODMA_V1_DCFG_get_merge_forward(data)                             ((0x80000000&(data))>>31)
#define  VODMA_VODMA_V1_DCFG_get_merge_backward(data)                            ((0x40000000&(data))>>30)
#define  VODMA_VODMA_V1_DCFG_get_pd_switch(data)                                 ((0x20000000&(data))>>29)
#define  VODMA_VODMA_V1_DCFG_get_pd_seq(data)                                    ((0x1F000000&(data))>>24)
#define  VODMA_VODMA_V1_DCFG_get_film_condition(data)                            ((0x00800000&(data))>>23)
#define  VODMA_VODMA_V1_DCFG_get_field_mode(data)                                ((0x00100000&(data))>>20)
#define  VODMA_VODMA_V1_DCFG_get_field_fw(data)                                  ((0x00080000&(data))>>19)
#define  VODMA_VODMA_V1_DCFG_get_l_flag_fw(data)                                 ((0x00040000&(data))>>18)
#define  VODMA_VODMA_V1_DCFG_get_force_2d_en(data)                               ((0x00020000&(data))>>17)
#define  VODMA_VODMA_V1_DCFG_get_force_2d_sel(data)                              ((0x00010000&(data))>>16)
#define  VODMA_VODMA_V1_DCFG_get_dma_auto_mode(data)                             ((0x00008000&(data))>>15)
#define  VODMA_VODMA_V1_DCFG_get_seq_data_pack_type(data)                        ((0x00004000&(data))>>14)
#define  VODMA_VODMA_V1_DCFG_get_seq_data_width(data)                            ((0x00002000&(data))>>13)
#define  VODMA_VODMA_V1_DCFG_get_double_chroma(data)                             ((0x00001000&(data))>>12)
#define  VODMA_VODMA_V1_DCFG_get_uv_off(data)                                    ((0x00000800&(data))>>11)
#define  VODMA_VODMA_V1_DCFG_get_pxl_swap_sel(data)                              ((0x00000780&(data))>>7)
#define  VODMA_VODMA_V1_DCFG_get_keep_go_en(data)                                ((0x00000040&(data))>>6)
#define  VODMA_VODMA_V1_DCFG_get_dma_state_reset_en(data)                        ((0x00000020&(data))>>5)
#define  VODMA_VODMA_V1_DCFG_get_v_flip_en(data)                                 ((0x00000010&(data))>>4)
#define  VODMA_VODMA_V1_DCFG_get_chroma_swap_en(data)                            ((0x00000008&(data))>>3)
#define  VODMA_VODMA_V1_DCFG_get_double_pixel_mode(data)                         ((0x00000004&(data))>>2)
#define  VODMA_VODMA_V1_DCFG_get_dma_mode(data)                                  ((0x00000002&(data))>>1)
#define  VODMA_VODMA_V1_DCFG_get_vodma_go(data)                                  (0x00000001&(data))

#define  VODMA_VODMA_CRC_CTRL                                                    0x180051B8
#define  VODMA_VODMA_CRC_CTRL_reg_addr                                           "0xB80051B8"
#define  VODMA_VODMA_CRC_CTRL_reg                                                0xB80051B8
#define  VODMA_VODMA_CRC_CTRL_inst_addr                                          "0x0001"
#define  set_VODMA_VODMA_CRC_CTRL_reg(data)                                      (*((volatile unsigned int*)VODMA_VODMA_CRC_CTRL_reg)=data)
#define  get_VODMA_VODMA_CRC_CTRL_reg                                            (*((volatile unsigned int*)VODMA_VODMA_CRC_CTRL_reg))
#define  VODMA_VODMA_CRC_CTRL_crc_continuous_shift                               (1)
#define  VODMA_VODMA_CRC_CTRL_crc_start_shift                                    (0)
#define  VODMA_VODMA_CRC_CTRL_crc_continuous_mask                                (0x00000002)
#define  VODMA_VODMA_CRC_CTRL_crc_start_mask                                     (0x00000001)
#define  VODMA_VODMA_CRC_CTRL_crc_continuous(data)                               (0x00000002&((data)<<1))
#define  VODMA_VODMA_CRC_CTRL_crc_start(data)                                    (0x00000001&(data))
#define  VODMA_VODMA_CRC_CTRL_get_crc_continuous(data)                           ((0x00000002&(data))>>1)
#define  VODMA_VODMA_CRC_CTRL_get_crc_start(data)                                (0x00000001&(data))

#define  VODMA_VODMA_CRC_RESULT                                                  0x180051BC
#define  VODMA_VODMA_CRC_RESULT_reg_addr                                         "0xB80051BC"
#define  VODMA_VODMA_CRC_RESULT_reg                                              0xB80051BC
#define  VODMA_VODMA_CRC_RESULT_inst_addr                                        "0x0002"
#define  set_VODMA_VODMA_CRC_RESULT_reg(data)                                    (*((volatile unsigned int*)VODMA_VODMA_CRC_RESULT_reg)=data)
#define  get_VODMA_VODMA_CRC_RESULT_reg                                          (*((volatile unsigned int*)VODMA_VODMA_CRC_RESULT_reg))
#define  VODMA_VODMA_CRC_RESULT_crc_result_shift                                 (0)
#define  VODMA_VODMA_CRC_RESULT_crc_result_mask                                  (0xFFFFFFFF)
#define  VODMA_VODMA_CRC_RESULT_crc_result(data)                                 (0xFFFFFFFF&(data))
#define  VODMA_VODMA_CRC_RESULT_get_crc_result(data)                             (0xFFFFFFFF&(data))

#define  VODMA_VODMA_RTL_IMPROVE                                                 0x18005058
#define  VODMA_VODMA_RTL_IMPROVE_reg_addr                                        "0xB8005058"
#define  VODMA_VODMA_RTL_IMPROVE_reg                                             0xB8005058
#define  VODMA_VODMA_RTL_IMPROVE_inst_addr                                       "0x0003"
#define  set_VODMA_VODMA_RTL_IMPROVE_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_RTL_IMPROVE_reg)=data)
#define  get_VODMA_VODMA_RTL_IMPROVE_reg                                         (*((volatile unsigned int*)VODMA_VODMA_RTL_IMPROVE_reg))
#define  VODMA_VODMA_RTL_IMPROVE_afifo_almost_empty_level_shift                  (4)
#define  VODMA_VODMA_RTL_IMPROVE_chroma_lb_underflow_debug_cancel_shift          (3)
#define  VODMA_VODMA_RTL_IMPROVE_chroma_lb_early_req_off_shift                   (2)
#define  VODMA_VODMA_RTL_IMPROVE_gating_off_shift                                (1)
#define  VODMA_VODMA_RTL_IMPROVE_debug_pin_src_shift                             (0)
#define  VODMA_VODMA_RTL_IMPROVE_afifo_almost_empty_level_mask                   (0x00003FF0)
#define  VODMA_VODMA_RTL_IMPROVE_chroma_lb_underflow_debug_cancel_mask           (0x00000008)
#define  VODMA_VODMA_RTL_IMPROVE_chroma_lb_early_req_off_mask                    (0x00000004)
#define  VODMA_VODMA_RTL_IMPROVE_gating_off_mask                                 (0x00000002)
#define  VODMA_VODMA_RTL_IMPROVE_debug_pin_src_mask                              (0x00000001)
#define  VODMA_VODMA_RTL_IMPROVE_afifo_almost_empty_level(data)                  (0x00003FF0&((data)<<4))
#define  VODMA_VODMA_RTL_IMPROVE_chroma_lb_underflow_debug_cancel(data)          (0x00000008&((data)<<3))
#define  VODMA_VODMA_RTL_IMPROVE_chroma_lb_early_req_off(data)                   (0x00000004&((data)<<2))
#define  VODMA_VODMA_RTL_IMPROVE_gating_off(data)                                (0x00000002&((data)<<1))
#define  VODMA_VODMA_RTL_IMPROVE_debug_pin_src(data)                             (0x00000001&(data))
#define  VODMA_VODMA_RTL_IMPROVE_get_afifo_almost_empty_level(data)              ((0x00003FF0&(data))>>4)
#define  VODMA_VODMA_RTL_IMPROVE_get_chroma_lb_underflow_debug_cancel(data)      ((0x00000008&(data))>>3)
#define  VODMA_VODMA_RTL_IMPROVE_get_chroma_lb_early_req_off(data)               ((0x00000004&(data))>>2)
#define  VODMA_VODMA_RTL_IMPROVE_get_gating_off(data)                            ((0x00000002&(data))>>1)
#define  VODMA_VODMA_RTL_IMPROVE_get_debug_pin_src(data)                         (0x00000001&(data))

#define  VODMA_VODMA_V1_DSIZE                                                    0x18005004
#define  VODMA_VODMA_V1_DSIZE_reg_addr                                           "0xB8005004"
#define  VODMA_VODMA_V1_DSIZE_reg                                                0xB8005004
#define  VODMA_VODMA_V1_DSIZE_inst_addr                                          "0x0004"
#define  set_VODMA_VODMA_V1_DSIZE_reg(data)                                      (*((volatile unsigned int*)VODMA_VODMA_V1_DSIZE_reg)=data)
#define  get_VODMA_VODMA_V1_DSIZE_reg                                            (*((volatile unsigned int*)VODMA_VODMA_V1_DSIZE_reg))
#define  VODMA_VODMA_V1_DSIZE_vs_toggle_reset_shift                              (31)
#define  VODMA_VODMA_V1_DSIZE_p_y_len_shift                                      (16)
#define  VODMA_VODMA_V1_DSIZE_p_y_nline_shift                                    (0)
#define  VODMA_VODMA_V1_DSIZE_vs_toggle_reset_mask                               (0x80000000)
#define  VODMA_VODMA_V1_DSIZE_p_y_len_mask                                       (0x1FFF0000)
#define  VODMA_VODMA_V1_DSIZE_p_y_nline_mask                                     (0x00000FFF)
#define  VODMA_VODMA_V1_DSIZE_vs_toggle_reset(data)                              (0x80000000&((data)<<31))
#define  VODMA_VODMA_V1_DSIZE_p_y_len(data)                                      (0x1FFF0000&((data)<<16))
#define  VODMA_VODMA_V1_DSIZE_p_y_nline(data)                                    (0x00000FFF&(data))
#define  VODMA_VODMA_V1_DSIZE_get_vs_toggle_reset(data)                          ((0x80000000&(data))>>31)
#define  VODMA_VODMA_V1_DSIZE_get_p_y_len(data)                                  ((0x1FFF0000&(data))>>16)
#define  VODMA_VODMA_V1_DSIZE_get_p_y_nline(data)                                (0x00000FFF&(data))

#define  VODMA_VODMA_VD1_ADS                                                     0x18005008
#define  VODMA_VODMA_VD1_ADS_reg_addr                                            "0xB8005008"
#define  VODMA_VODMA_VD1_ADS_reg                                                 0xB8005008
#define  VODMA_VODMA_VD1_ADS_inst_addr                                           "0x0005"
#define  set_VODMA_VODMA_VD1_ADS_reg(data)                                       (*((volatile unsigned int*)VODMA_VODMA_VD1_ADS_reg)=data)
#define  get_VODMA_VODMA_VD1_ADS_reg                                             (*((volatile unsigned int*)VODMA_VODMA_VD1_ADS_reg))
#define  VODMA_VODMA_VD1_ADS_p_v_ads_shift                                       (16)
#define  VODMA_VODMA_VD1_ADS_p_u_ads_shift                                       (8)
#define  VODMA_VODMA_VD1_ADS_p_y_ads_shift                                       (0)
#define  VODMA_VODMA_VD1_ADS_p_v_ads_mask                                        (0x007F0000)
#define  VODMA_VODMA_VD1_ADS_p_u_ads_mask                                        (0x00007F00)
#define  VODMA_VODMA_VD1_ADS_p_y_ads_mask                                        (0x0000007F)
#define  VODMA_VODMA_VD1_ADS_p_v_ads(data)                                       (0x007F0000&((data)<<16))
#define  VODMA_VODMA_VD1_ADS_p_u_ads(data)                                       (0x00007F00&((data)<<8))
#define  VODMA_VODMA_VD1_ADS_p_y_ads(data)                                       (0x0000007F&(data))
#define  VODMA_VODMA_VD1_ADS_get_p_v_ads(data)                                   ((0x007F0000&(data))>>16)
#define  VODMA_VODMA_VD1_ADS_get_p_u_ads(data)                                   ((0x00007F00&(data))>>8)
#define  VODMA_VODMA_VD1_ADS_get_p_y_ads(data)                                   (0x0000007F&(data))

#define  VODMA_VODMA_V1_SEQ                                                      0x1800500C
#define  VODMA_VODMA_V1_SEQ_reg_addr                                             "0xB800500C"
#define  VODMA_VODMA_V1_SEQ_reg                                                  0xB800500C
#define  VODMA_VODMA_V1_SEQ_inst_addr                                            "0x0006"
#define  set_VODMA_VODMA_V1_SEQ_reg(data)                                        (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_reg)=data)
#define  get_VODMA_VODMA_V1_SEQ_reg                                              (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_reg))
#define  VODMA_VODMA_V1_SEQ_st_adr_shift                                         (3)
#define  VODMA_VODMA_V1_SEQ_st_adr_mask                                          (0xFFFFFFF8)
#define  VODMA_VODMA_V1_SEQ_st_adr(data)                                         (0xFFFFFFF8&((data)<<3))
#define  VODMA_VODMA_V1_SEQ_get_st_adr(data)                                     ((0xFFFFFFF8&(data))>>3)

#define  VODMA_VODMA_V1_BLK1                                                     0x18005010
#define  VODMA_VODMA_V1_BLK1_reg_addr                                            "0xB8005010"
#define  VODMA_VODMA_V1_BLK1_reg                                                 0xB8005010
#define  VODMA_VODMA_V1_BLK1_inst_addr                                           "0x0007"
#define  set_VODMA_VODMA_V1_BLK1_reg(data)                                       (*((volatile unsigned int*)VODMA_VODMA_V1_BLK1_reg)=data)
#define  get_VODMA_VODMA_V1_BLK1_reg                                             (*((volatile unsigned int*)VODMA_VODMA_V1_BLK1_reg))
#define  VODMA_VODMA_V1_BLK1_y_ha_shift_shift                                    (8)
#define  VODMA_VODMA_V1_BLK1_y_ha_shift_mask                                     (0x00000700)
#define  VODMA_VODMA_V1_BLK1_y_ha_shift(data)                                    (0x00000700&((data)<<8))
#define  VODMA_VODMA_V1_BLK1_get_y_ha_shift(data)                                ((0x00000700&(data))>>8)

#define  VODMA_VODMA_V1_BLK2                                                     0x18005014
#define  VODMA_VODMA_V1_BLK2_reg_addr                                            "0xB8005014"
#define  VODMA_VODMA_V1_BLK2_reg                                                 0xB8005014
#define  VODMA_VODMA_V1_BLK2_inst_addr                                           "0x0008"
#define  set_VODMA_VODMA_V1_BLK2_reg(data)                                       (*((volatile unsigned int*)VODMA_VODMA_V1_BLK2_reg)=data)
#define  get_VODMA_VODMA_V1_BLK2_reg                                             (*((volatile unsigned int*)VODMA_VODMA_V1_BLK2_reg))
#define  VODMA_VODMA_V1_BLK2_p_u_offset_shift                                    (16)
#define  VODMA_VODMA_V1_BLK2_p_y_offset_shift                                    (0)
#define  VODMA_VODMA_V1_BLK2_p_u_offset_mask                                     (0x0FFF0000)
#define  VODMA_VODMA_V1_BLK2_p_y_offset_mask                                     (0x00000FFF)
#define  VODMA_VODMA_V1_BLK2_p_u_offset(data)                                    (0x0FFF0000&((data)<<16))
#define  VODMA_VODMA_V1_BLK2_p_y_offset(data)                                    (0x00000FFF&(data))
#define  VODMA_VODMA_V1_BLK2_get_p_u_offset(data)                                ((0x0FFF0000&(data))>>16)
#define  VODMA_VODMA_V1_BLK2_get_p_y_offset(data)                                (0x00000FFF&(data))

#define  VODMA_VODMA_V1_BLK3                                                     0x18005018
#define  VODMA_VODMA_V1_BLK3_reg_addr                                            "0xB8005018"
#define  VODMA_VODMA_V1_BLK3_reg                                                 0xB8005018
#define  VODMA_VODMA_V1_BLK3_inst_addr                                           "0x0009"
#define  set_VODMA_VODMA_V1_BLK3_reg(data)                                       (*((volatile unsigned int*)VODMA_VODMA_V1_BLK3_reg)=data)
#define  get_VODMA_VODMA_V1_BLK3_reg                                             (*((volatile unsigned int*)VODMA_VODMA_V1_BLK3_reg))
#define  VODMA_VODMA_V1_BLK3_p_v_offset_shift                                    (0)
#define  VODMA_VODMA_V1_BLK3_p_v_offset_mask                                     (0x00000FFF)
#define  VODMA_VODMA_V1_BLK3_p_v_offset(data)                                    (0x00000FFF&(data))
#define  VODMA_VODMA_V1_BLK3_get_p_v_offset(data)                                (0x00000FFF&(data))

#define  VODMA_VODMA_V1_BLK4                                                     0x18005044
#define  VODMA_VODMA_V1_BLK4_reg_addr                                            "0xB8005044"
#define  VODMA_VODMA_V1_BLK4_reg                                                 0xB8005044
#define  VODMA_VODMA_V1_BLK4_inst_addr                                           "0x000A"
#define  set_VODMA_VODMA_V1_BLK4_reg(data)                                       (*((volatile unsigned int*)VODMA_VODMA_V1_BLK4_reg)=data)
#define  get_VODMA_VODMA_V1_BLK4_reg                                             (*((volatile unsigned int*)VODMA_VODMA_V1_BLK4_reg))
#define  VODMA_VODMA_V1_BLK4_y_h_offset_shift                                    (0)
#define  VODMA_VODMA_V1_BLK4_y_h_offset_mask                                     (0x000003FF)
#define  VODMA_VODMA_V1_BLK4_y_h_offset(data)                                    (0x000003FF&(data))
#define  VODMA_VODMA_V1_BLK4_get_y_h_offset(data)                                (0x000003FF&(data))

#define  VODMA_VODMA_V1_BLK5                                                     0x18005048
#define  VODMA_VODMA_V1_BLK5_reg_addr                                            "0xB8005048"
#define  VODMA_VODMA_V1_BLK5_reg                                                 0xB8005048
#define  VODMA_VODMA_V1_BLK5_inst_addr                                           "0x000B"
#define  set_VODMA_VODMA_V1_BLK5_reg(data)                                       (*((volatile unsigned int*)VODMA_VODMA_V1_BLK5_reg)=data)
#define  get_VODMA_VODMA_V1_BLK5_reg                                             (*((volatile unsigned int*)VODMA_VODMA_V1_BLK5_reg))
#define  VODMA_VODMA_V1_BLK5_v_h_offset_shift                                    (16)
#define  VODMA_VODMA_V1_BLK5_u_h_offset_shift                                    (0)
#define  VODMA_VODMA_V1_BLK5_v_h_offset_mask                                     (0x03FF0000)
#define  VODMA_VODMA_V1_BLK5_u_h_offset_mask                                     (0x000003FF)
#define  VODMA_VODMA_V1_BLK5_v_h_offset(data)                                    (0x03FF0000&((data)<<16))
#define  VODMA_VODMA_V1_BLK5_u_h_offset(data)                                    (0x000003FF&(data))
#define  VODMA_VODMA_V1_BLK5_get_v_h_offset(data)                                ((0x03FF0000&(data))>>16)
#define  VODMA_VODMA_V1_BLK5_get_u_h_offset(data)                                (0x000003FF&(data))

#define  VODMA_VODMA_V1_SEQ_3D_L1                                                0x1800501C
#define  VODMA_VODMA_V1_SEQ_3D_L1_reg_addr                                       "0xB800501C"
#define  VODMA_VODMA_V1_SEQ_3D_L1_reg                                            0xB800501C
#define  VODMA_VODMA_V1_SEQ_3D_L1_inst_addr                                      "0x000C"
#define  set_VODMA_VODMA_V1_SEQ_3D_L1_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_L1_reg)=data)
#define  get_VODMA_VODMA_V1_SEQ_3D_L1_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_L1_reg))
#define  VODMA_VODMA_V1_SEQ_3D_L1_st_adr_shift                                   (3)
#define  VODMA_VODMA_V1_SEQ_3D_L1_st_adr_mask                                    (0xFFFFFFF8)
#define  VODMA_VODMA_V1_SEQ_3D_L1_st_adr(data)                                   (0xFFFFFFF8&((data)<<3))
#define  VODMA_VODMA_V1_SEQ_3D_L1_get_st_adr(data)                               ((0xFFFFFFF8&(data))>>3)

#define  VODMA_VODMA_V1_SEQ_3D_R1                                                0x18005020
#define  VODMA_VODMA_V1_SEQ_3D_R1_reg_addr                                       "0xB8005020"
#define  VODMA_VODMA_V1_SEQ_3D_R1_reg                                            0xB8005020
#define  VODMA_VODMA_V1_SEQ_3D_R1_inst_addr                                      "0x000D"
#define  set_VODMA_VODMA_V1_SEQ_3D_R1_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_R1_reg)=data)
#define  get_VODMA_VODMA_V1_SEQ_3D_R1_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_R1_reg))
#define  VODMA_VODMA_V1_SEQ_3D_R1_st_adr_shift                                   (3)
#define  VODMA_VODMA_V1_SEQ_3D_R1_st_adr_mask                                    (0xFFFFFFF8)
#define  VODMA_VODMA_V1_SEQ_3D_R1_st_adr(data)                                   (0xFFFFFFF8&((data)<<3))
#define  VODMA_VODMA_V1_SEQ_3D_R1_get_st_adr(data)                               ((0xFFFFFFF8&(data))>>3)

#define  VODMA_VODMA_V1_SEQ_3D_L2                                                0x18005024
#define  VODMA_VODMA_V1_SEQ_3D_L2_reg_addr                                       "0xB8005024"
#define  VODMA_VODMA_V1_SEQ_3D_L2_reg                                            0xB8005024
#define  VODMA_VODMA_V1_SEQ_3D_L2_inst_addr                                      "0x000E"
#define  set_VODMA_VODMA_V1_SEQ_3D_L2_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_L2_reg)=data)
#define  get_VODMA_VODMA_V1_SEQ_3D_L2_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_L2_reg))
#define  VODMA_VODMA_V1_SEQ_3D_L2_st_adr_shift                                   (3)
#define  VODMA_VODMA_V1_SEQ_3D_L2_st_adr_mask                                    (0xFFFFFFF8)
#define  VODMA_VODMA_V1_SEQ_3D_L2_st_adr(data)                                   (0xFFFFFFF8&((data)<<3))
#define  VODMA_VODMA_V1_SEQ_3D_L2_get_st_adr(data)                               ((0xFFFFFFF8&(data))>>3)

#define  VODMA_VODMA_V1_SEQ_3D_R2                                                0x18005028
#define  VODMA_VODMA_V1_SEQ_3D_R2_reg_addr                                       "0xB8005028"
#define  VODMA_VODMA_V1_SEQ_3D_R2_reg                                            0xB8005028
#define  VODMA_VODMA_V1_SEQ_3D_R2_inst_addr                                      "0x000F"
#define  set_VODMA_VODMA_V1_SEQ_3D_R2_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_R2_reg)=data)
#define  get_VODMA_VODMA_V1_SEQ_3D_R2_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_R2_reg))
#define  VODMA_VODMA_V1_SEQ_3D_R2_st_adr_shift                                   (3)
#define  VODMA_VODMA_V1_SEQ_3D_R2_st_adr_mask                                    (0xFFFFFFF8)
#define  VODMA_VODMA_V1_SEQ_3D_R2_st_adr(data)                                   (0xFFFFFFF8&((data)<<3))
#define  VODMA_VODMA_V1_SEQ_3D_R2_get_st_adr(data)                               ((0xFFFFFFF8&(data))>>3)

#define  VODMA_VODMA_V1_V_FLIP                                                   0x1800502C
#define  VODMA_VODMA_V1_V_FLIP_reg_addr                                          "0xB800502C"
#define  VODMA_VODMA_V1_V_FLIP_reg                                               0xB800502C
#define  VODMA_VODMA_V1_V_FLIP_inst_addr                                         "0x0010"
#define  set_VODMA_VODMA_V1_V_FLIP_reg(data)                                     (*((volatile unsigned int*)VODMA_VODMA_V1_V_FLIP_reg)=data)
#define  get_VODMA_VODMA_V1_V_FLIP_reg                                           (*((volatile unsigned int*)VODMA_VODMA_V1_V_FLIP_reg))
#define  VODMA_VODMA_V1_V_FLIP_line_step_shift                                   (0)
#define  VODMA_VODMA_V1_V_FLIP_line_step_mask                                    (0x00001FFF)
#define  VODMA_VODMA_V1_V_FLIP_line_step(data)                                   (0x00001FFF&(data))
#define  VODMA_VODMA_V1_V_FLIP_get_line_step(data)                               (0x00001FFF&(data))

#define  VODMA_VODMA_V1_SEQ_3D_L3                                                0x180051C0
#define  VODMA_VODMA_V1_SEQ_3D_L3_reg_addr                                       "0xB80051C0"
#define  VODMA_VODMA_V1_SEQ_3D_L3_reg                                            0xB80051C0
#define  VODMA_VODMA_V1_SEQ_3D_L3_inst_addr                                      "0x0011"
#define  set_VODMA_VODMA_V1_SEQ_3D_L3_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_L3_reg)=data)
#define  get_VODMA_VODMA_V1_SEQ_3D_L3_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_L3_reg))
#define  VODMA_VODMA_V1_SEQ_3D_L3_st_adr_shift                                   (3)
#define  VODMA_VODMA_V1_SEQ_3D_L3_st_adr_mask                                    (0xFFFFFFF8)
#define  VODMA_VODMA_V1_SEQ_3D_L3_st_adr(data)                                   (0xFFFFFFF8&((data)<<3))
#define  VODMA_VODMA_V1_SEQ_3D_L3_get_st_adr(data)                               ((0xFFFFFFF8&(data))>>3)

#define  VODMA_VODMA_V1_SEQ_3D_R3                                                0x180051C4
#define  VODMA_VODMA_V1_SEQ_3D_R3_reg_addr                                       "0xB80051C4"
#define  VODMA_VODMA_V1_SEQ_3D_R3_reg                                            0xB80051C4
#define  VODMA_VODMA_V1_SEQ_3D_R3_inst_addr                                      "0x0012"
#define  set_VODMA_VODMA_V1_SEQ_3D_R3_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_R3_reg)=data)
#define  get_VODMA_VODMA_V1_SEQ_3D_R3_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_R3_reg))
#define  VODMA_VODMA_V1_SEQ_3D_R3_st_adr_shift                                   (3)
#define  VODMA_VODMA_V1_SEQ_3D_R3_st_adr_mask                                    (0xFFFFFFF8)
#define  VODMA_VODMA_V1_SEQ_3D_R3_st_adr(data)                                   (0xFFFFFFF8&((data)<<3))
#define  VODMA_VODMA_V1_SEQ_3D_R3_get_st_adr(data)                               ((0xFFFFFFF8&(data))>>3)

#define  VODMA_VODMA_V1_SEQ_3D_L4                                                0x180051C8
#define  VODMA_VODMA_V1_SEQ_3D_L4_reg_addr                                       "0xB80051C8"
#define  VODMA_VODMA_V1_SEQ_3D_L4_reg                                            0xB80051C8
#define  VODMA_VODMA_V1_SEQ_3D_L4_inst_addr                                      "0x0013"
#define  set_VODMA_VODMA_V1_SEQ_3D_L4_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_L4_reg)=data)
#define  get_VODMA_VODMA_V1_SEQ_3D_L4_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_L4_reg))
#define  VODMA_VODMA_V1_SEQ_3D_L4_st_adr_shift                                   (3)
#define  VODMA_VODMA_V1_SEQ_3D_L4_st_adr_mask                                    (0xFFFFFFF8)
#define  VODMA_VODMA_V1_SEQ_3D_L4_st_adr(data)                                   (0xFFFFFFF8&((data)<<3))
#define  VODMA_VODMA_V1_SEQ_3D_L4_get_st_adr(data)                               ((0xFFFFFFF8&(data))>>3)

#define  VODMA_VODMA_V1_SEQ_3D_R4                                                0x180051CC
#define  VODMA_VODMA_V1_SEQ_3D_R4_reg_addr                                       "0xB80051CC"
#define  VODMA_VODMA_V1_SEQ_3D_R4_reg                                            0xB80051CC
#define  VODMA_VODMA_V1_SEQ_3D_R4_inst_addr                                      "0x0014"
#define  set_VODMA_VODMA_V1_SEQ_3D_R4_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_R4_reg)=data)
#define  get_VODMA_VODMA_V1_SEQ_3D_R4_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1_SEQ_3D_R4_reg))
#define  VODMA_VODMA_V1_SEQ_3D_R4_st_adr_shift                                   (3)
#define  VODMA_VODMA_V1_SEQ_3D_R4_st_adr_mask                                    (0xFFFFFFF8)
#define  VODMA_VODMA_V1_SEQ_3D_R4_st_adr(data)                                   (0xFFFFFFF8&((data)<<3))
#define  VODMA_VODMA_V1_SEQ_3D_R4_get_st_adr(data)                               ((0xFFFFFFF8&(data))>>3)

#define  VODMA_VODMA_TaBSbS_merge                                                0x180050E0
#define  VODMA_VODMA_TaBSbS_merge_reg_addr                                       "0xB80050E0"
#define  VODMA_VODMA_TaBSbS_merge_reg                                            0xB80050E0
#define  VODMA_VODMA_TaBSbS_merge_inst_addr                                      "0x0015"
#define  set_VODMA_VODMA_TaBSbS_merge_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_TaBSbS_merge_reg)=data)
#define  get_VODMA_VODMA_TaBSbS_merge_reg                                        (*((volatile unsigned int*)VODMA_VODMA_TaBSbS_merge_reg))
#define  VODMA_VODMA_TaBSbS_merge_p_y_len_shift                                  (16)
#define  VODMA_VODMA_TaBSbS_merge_p_y_nline_shift                                (4)
#define  VODMA_VODMA_TaBSbS_merge_tabsbs_mode_shift                              (1)
#define  VODMA_VODMA_TaBSbS_merge_tabsbs_merge_shift                             (0)
#define  VODMA_VODMA_TaBSbS_merge_p_y_len_mask                                   (0x0FFF0000)
#define  VODMA_VODMA_TaBSbS_merge_p_y_nline_mask                                 (0x00007FF0)
#define  VODMA_VODMA_TaBSbS_merge_tabsbs_mode_mask                               (0x00000002)
#define  VODMA_VODMA_TaBSbS_merge_tabsbs_merge_mask                              (0x00000001)
#define  VODMA_VODMA_TaBSbS_merge_p_y_len(data)                                  (0x0FFF0000&((data)<<16))
#define  VODMA_VODMA_TaBSbS_merge_p_y_nline(data)                                (0x00007FF0&((data)<<4))
#define  VODMA_VODMA_TaBSbS_merge_tabsbs_mode(data)                              (0x00000002&((data)<<1))
#define  VODMA_VODMA_TaBSbS_merge_tabsbs_merge(data)                             (0x00000001&(data))
#define  VODMA_VODMA_TaBSbS_merge_get_p_y_len(data)                              ((0x0FFF0000&(data))>>16)
#define  VODMA_VODMA_TaBSbS_merge_get_p_y_nline(data)                            ((0x00007FF0&(data))>>4)
#define  VODMA_VODMA_TaBSbS_merge_get_tabsbs_mode(data)                          ((0x00000002&(data))>>1)
#define  VODMA_VODMA_TaBSbS_merge_get_tabsbs_merge(data)                         (0x00000001&(data))

#define  VODMA_VODMA_TaBSbS_SEQ                                                  0x180050E4
#define  VODMA_VODMA_TaBSbS_SEQ_reg_addr                                         "0xB80050E4"
#define  VODMA_VODMA_TaBSbS_SEQ_reg                                              0xB80050E4
#define  VODMA_VODMA_TaBSbS_SEQ_inst_addr                                        "0x0016"
#define  set_VODMA_VODMA_TaBSbS_SEQ_reg(data)                                    (*((volatile unsigned int*)VODMA_VODMA_TaBSbS_SEQ_reg)=data)
#define  get_VODMA_VODMA_TaBSbS_SEQ_reg                                          (*((volatile unsigned int*)VODMA_VODMA_TaBSbS_SEQ_reg))
#define  VODMA_VODMA_TaBSbS_SEQ_st_adr_shift                                     (3)
#define  VODMA_VODMA_TaBSbS_SEQ_st_adr_mask                                      (0xFFFFFFF8)
#define  VODMA_VODMA_TaBSbS_SEQ_st_adr(data)                                     (0xFFFFFFF8&((data)<<3))
#define  VODMA_VODMA_TaBSbS_SEQ_get_st_adr(data)                                 ((0xFFFFFFF8&(data))>>3)

#define  VODMA_VODMA_TabSbS_ADS                                                  0x180050E8
#define  VODMA_VODMA_TabSbS_ADS_reg_addr                                         "0xB80050E8"
#define  VODMA_VODMA_TabSbS_ADS_reg                                              0xB80050E8
#define  VODMA_VODMA_TabSbS_ADS_inst_addr                                        "0x0017"
#define  set_VODMA_VODMA_TabSbS_ADS_reg(data)                                    (*((volatile unsigned int*)VODMA_VODMA_TabSbS_ADS_reg)=data)
#define  get_VODMA_VODMA_TabSbS_ADS_reg                                          (*((volatile unsigned int*)VODMA_VODMA_TabSbS_ADS_reg))
#define  VODMA_VODMA_TabSbS_ADS_p_v_ads_shift                                    (16)
#define  VODMA_VODMA_TabSbS_ADS_p_u_ads_shift                                    (8)
#define  VODMA_VODMA_TabSbS_ADS_p_y_ads_shift                                    (0)
#define  VODMA_VODMA_TabSbS_ADS_p_v_ads_mask                                     (0x007F0000)
#define  VODMA_VODMA_TabSbS_ADS_p_u_ads_mask                                     (0x00007F00)
#define  VODMA_VODMA_TabSbS_ADS_p_y_ads_mask                                     (0x0000007F)
#define  VODMA_VODMA_TabSbS_ADS_p_v_ads(data)                                    (0x007F0000&((data)<<16))
#define  VODMA_VODMA_TabSbS_ADS_p_u_ads(data)                                    (0x00007F00&((data)<<8))
#define  VODMA_VODMA_TabSbS_ADS_p_y_ads(data)                                    (0x0000007F&(data))
#define  VODMA_VODMA_TabSbS_ADS_get_p_v_ads(data)                                ((0x007F0000&(data))>>16)
#define  VODMA_VODMA_TabSbS_ADS_get_p_u_ads(data)                                ((0x00007F00&(data))>>8)
#define  VODMA_VODMA_TabSbS_ADS_get_p_y_ads(data)                                (0x0000007F&(data))

#define  VODMA_VODMA_TabSbS_BLK1                                                 0x180050EC
#define  VODMA_VODMA_TabSbS_BLK1_reg_addr                                        "0xB80050EC"
#define  VODMA_VODMA_TabSbS_BLK1_reg                                             0xB80050EC
#define  VODMA_VODMA_TabSbS_BLK1_inst_addr                                       "0x0018"
#define  set_VODMA_VODMA_TabSbS_BLK1_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_TabSbS_BLK1_reg)=data)
#define  get_VODMA_VODMA_TabSbS_BLK1_reg                                         (*((volatile unsigned int*)VODMA_VODMA_TabSbS_BLK1_reg))
#define  VODMA_VODMA_TabSbS_BLK1_y_ha_shift_shift                                (8)
#define  VODMA_VODMA_TabSbS_BLK1_y_ha_shift_mask                                 (0x00000700)
#define  VODMA_VODMA_TabSbS_BLK1_y_ha_shift(data)                                (0x00000700&((data)<<8))
#define  VODMA_VODMA_TabSbS_BLK1_get_y_ha_shift(data)                            ((0x00000700&(data))>>8)

#define  VODMA_VODMA_TabSbS_BLK2                                                 0x180050F0
#define  VODMA_VODMA_TabSbS_BLK2_reg_addr                                        "0xB80050F0"
#define  VODMA_VODMA_TabSbS_BLK2_reg                                             0xB80050F0
#define  VODMA_VODMA_TabSbS_BLK2_inst_addr                                       "0x0019"
#define  set_VODMA_VODMA_TabSbS_BLK2_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_TabSbS_BLK2_reg)=data)
#define  get_VODMA_VODMA_TabSbS_BLK2_reg                                         (*((volatile unsigned int*)VODMA_VODMA_TabSbS_BLK2_reg))
#define  VODMA_VODMA_TabSbS_BLK2_p_u_offset_shift                                (16)
#define  VODMA_VODMA_TabSbS_BLK2_p_y_offset_shift                                (0)
#define  VODMA_VODMA_TabSbS_BLK2_p_u_offset_mask                                 (0x0FFF0000)
#define  VODMA_VODMA_TabSbS_BLK2_p_y_offset_mask                                 (0x00000FFF)
#define  VODMA_VODMA_TabSbS_BLK2_p_u_offset(data)                                (0x0FFF0000&((data)<<16))
#define  VODMA_VODMA_TabSbS_BLK2_p_y_offset(data)                                (0x00000FFF&(data))
#define  VODMA_VODMA_TabSbS_BLK2_get_p_u_offset(data)                            ((0x0FFF0000&(data))>>16)
#define  VODMA_VODMA_TabSbS_BLK2_get_p_y_offset(data)                            (0x00000FFF&(data))

#define  VODMA_VODMA_TabSbS_BLK3                                                 0x180050F4
#define  VODMA_VODMA_TabSbS_BLK3_reg_addr                                        "0xB80050F4"
#define  VODMA_VODMA_TabSbS_BLK3_reg                                             0xB80050F4
#define  VODMA_VODMA_TabSbS_BLK3_inst_addr                                       "0x001A"
#define  set_VODMA_VODMA_TabSbS_BLK3_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_TabSbS_BLK3_reg)=data)
#define  get_VODMA_VODMA_TabSbS_BLK3_reg                                         (*((volatile unsigned int*)VODMA_VODMA_TabSbS_BLK3_reg))
#define  VODMA_VODMA_TabSbS_BLK3_p_v_offset_shift                                (0)
#define  VODMA_VODMA_TabSbS_BLK3_p_v_offset_mask                                 (0x00000FFF)
#define  VODMA_VODMA_TabSbS_BLK3_p_v_offset(data)                                (0x00000FFF&(data))
#define  VODMA_VODMA_TabSbS_BLK3_get_p_v_offset(data)                            (0x00000FFF&(data))

#define  VODMA_VODMA_TabSbS_BLK4                                                 0x1800504C
#define  VODMA_VODMA_TabSbS_BLK4_reg_addr                                        "0xB800504C"
#define  VODMA_VODMA_TabSbS_BLK4_reg                                             0xB800504C
#define  VODMA_VODMA_TabSbS_BLK4_inst_addr                                       "0x001B"
#define  set_VODMA_VODMA_TabSbS_BLK4_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_TabSbS_BLK4_reg)=data)
#define  get_VODMA_VODMA_TabSbS_BLK4_reg                                         (*((volatile unsigned int*)VODMA_VODMA_TabSbS_BLK4_reg))
#define  VODMA_VODMA_TabSbS_BLK4_y_h_offset_shift                                (0)
#define  VODMA_VODMA_TabSbS_BLK4_y_h_offset_mask                                 (0x000003FF)
#define  VODMA_VODMA_TabSbS_BLK4_y_h_offset(data)                                (0x000003FF&(data))
#define  VODMA_VODMA_TabSbS_BLK4_get_y_h_offset(data)                            (0x000003FF&(data))

#define  VODMA_VODMA_TabSbS_BLK5                                                 0x18005050
#define  VODMA_VODMA_TabSbS_BLK5_reg_addr                                        "0xB8005050"
#define  VODMA_VODMA_TabSbS_BLK5_reg                                             0xB8005050
#define  VODMA_VODMA_TabSbS_BLK5_inst_addr                                       "0x001C"
#define  set_VODMA_VODMA_TabSbS_BLK5_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_TabSbS_BLK5_reg)=data)
#define  get_VODMA_VODMA_TabSbS_BLK5_reg                                         (*((volatile unsigned int*)VODMA_VODMA_TabSbS_BLK5_reg))
#define  VODMA_VODMA_TabSbS_BLK5_v_h_offset_shift                                (16)
#define  VODMA_VODMA_TabSbS_BLK5_u_h_offset_shift                                (0)
#define  VODMA_VODMA_TabSbS_BLK5_v_h_offset_mask                                 (0x03FF0000)
#define  VODMA_VODMA_TabSbS_BLK5_u_h_offset_mask                                 (0x000003FF)
#define  VODMA_VODMA_TabSbS_BLK5_v_h_offset(data)                                (0x03FF0000&((data)<<16))
#define  VODMA_VODMA_TabSbS_BLK5_u_h_offset(data)                                (0x000003FF&(data))
#define  VODMA_VODMA_TabSbS_BLK5_get_v_h_offset(data)                            ((0x03FF0000&(data))>>16)
#define  VODMA_VODMA_TabSbS_BLK5_get_u_h_offset(data)                            (0x000003FF&(data))

#define  VODMA_VODMA_REG_DB_CTRL                                                 0x18005054
#define  VODMA_VODMA_REG_DB_CTRL_reg_addr                                        "0xB8005054"
#define  VODMA_VODMA_REG_DB_CTRL_reg                                             0xB8005054
#define  VODMA_VODMA_REG_DB_CTRL_inst_addr                                       "0x001D"
#define  set_VODMA_VODMA_REG_DB_CTRL_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_REG_DB_CTRL_reg)=data)
#define  get_VODMA_VODMA_REG_DB_CTRL_reg                                         (*((volatile unsigned int*)VODMA_VODMA_REG_DB_CTRL_reg))
#define  VODMA_VODMA_REG_DB_CTRL_vodmavsg_dbrdy_keep_shift                       (28)
#define  VODMA_VODMA_REG_DB_CTRL_vodmavsg_db_sel_shift                           (18)
#define  VODMA_VODMA_REG_DB_CTRL_vodmavsg_db_en_shift                            (17)
#define  VODMA_VODMA_REG_DB_CTRL_vodmavsg_db_rdy_shift                           (16)
#define  VODMA_VODMA_REG_DB_CTRL_i2rnd_db_sel_shift                              (10)
#define  VODMA_VODMA_REG_DB_CTRL_i2rnd_db_en_shift                               (9)
#define  VODMA_VODMA_REG_DB_CTRL_i2rnd_db_rdy_shift                              (8)
#define  VODMA_VODMA_REG_DB_CTRL_vodma_db_sel_shift                              (2)
#define  VODMA_VODMA_REG_DB_CTRL_vodma_db_en_shift                               (1)
#define  VODMA_VODMA_REG_DB_CTRL_vodma_db_rdy_shift                              (0)
#define  VODMA_VODMA_REG_DB_CTRL_vodmavsg_dbrdy_keep_mask                        (0x10000000)
#define  VODMA_VODMA_REG_DB_CTRL_vodmavsg_db_sel_mask                            (0x00040000)
#define  VODMA_VODMA_REG_DB_CTRL_vodmavsg_db_en_mask                             (0x00020000)
#define  VODMA_VODMA_REG_DB_CTRL_vodmavsg_db_rdy_mask                            (0x00010000)
#define  VODMA_VODMA_REG_DB_CTRL_i2rnd_db_sel_mask                               (0x00000400)
#define  VODMA_VODMA_REG_DB_CTRL_i2rnd_db_en_mask                                (0x00000200)
#define  VODMA_VODMA_REG_DB_CTRL_i2rnd_db_rdy_mask                               (0x00000100)
#define  VODMA_VODMA_REG_DB_CTRL_vodma_db_sel_mask                               (0x00000004)
#define  VODMA_VODMA_REG_DB_CTRL_vodma_db_en_mask                                (0x00000002)
#define  VODMA_VODMA_REG_DB_CTRL_vodma_db_rdy_mask                               (0x00000001)
#define  VODMA_VODMA_REG_DB_CTRL_vodmavsg_dbrdy_keep(data)                       (0x10000000&((data)<<28))
#define  VODMA_VODMA_REG_DB_CTRL_vodmavsg_db_sel(data)                           (0x00040000&((data)<<18))
#define  VODMA_VODMA_REG_DB_CTRL_vodmavsg_db_en(data)                            (0x00020000&((data)<<17))
#define  VODMA_VODMA_REG_DB_CTRL_vodmavsg_db_rdy(data)                           (0x00010000&((data)<<16))
#define  VODMA_VODMA_REG_DB_CTRL_i2rnd_db_sel(data)                              (0x00000400&((data)<<10))
#define  VODMA_VODMA_REG_DB_CTRL_i2rnd_db_en(data)                               (0x00000200&((data)<<9))
#define  VODMA_VODMA_REG_DB_CTRL_i2rnd_db_rdy(data)                              (0x00000100&((data)<<8))
#define  VODMA_VODMA_REG_DB_CTRL_vodma_db_sel(data)                              (0x00000004&((data)<<2))
#define  VODMA_VODMA_REG_DB_CTRL_vodma_db_en(data)                               (0x00000002&((data)<<1))
#define  VODMA_VODMA_REG_DB_CTRL_vodma_db_rdy(data)                              (0x00000001&(data))
#define  VODMA_VODMA_REG_DB_CTRL_get_vodmavsg_dbrdy_keep(data)                   ((0x10000000&(data))>>28)
#define  VODMA_VODMA_REG_DB_CTRL_get_vodmavsg_db_sel(data)                       ((0x00040000&(data))>>18)
#define  VODMA_VODMA_REG_DB_CTRL_get_vodmavsg_db_en(data)                        ((0x00020000&(data))>>17)
#define  VODMA_VODMA_REG_DB_CTRL_get_vodmavsg_db_rdy(data)                       ((0x00010000&(data))>>16)
#define  VODMA_VODMA_REG_DB_CTRL_get_i2rnd_db_sel(data)                          ((0x00000400&(data))>>10)
#define  VODMA_VODMA_REG_DB_CTRL_get_i2rnd_db_en(data)                           ((0x00000200&(data))>>9)
#define  VODMA_VODMA_REG_DB_CTRL_get_i2rnd_db_rdy(data)                          ((0x00000100&(data))>>8)
#define  VODMA_VODMA_REG_DB_CTRL_get_vodma_db_sel(data)                          ((0x00000004&(data))>>2)
#define  VODMA_VODMA_REG_DB_CTRL_get_vodma_db_en(data)                           ((0x00000002&(data))>>1)
#define  VODMA_VODMA_REG_DB_CTRL_get_vodma_db_rdy(data)                          (0x00000001&(data))

#define  VODMA_VODMA_V1CHROMA_FMT                                                0x18005030
#define  VODMA_VODMA_V1CHROMA_FMT_reg_addr                                       "0xB8005030"
#define  VODMA_VODMA_V1CHROMA_FMT_reg                                            0xB8005030
#define  VODMA_VODMA_V1CHROMA_FMT_inst_addr                                      "0x001E"
#define  set_VODMA_VODMA_V1CHROMA_FMT_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1CHROMA_FMT_reg)=data)
#define  get_VODMA_VODMA_V1CHROMA_FMT_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1CHROMA_FMT_reg))
#define  VODMA_VODMA_V1CHROMA_FMT_g_position_shift                               (8)
#define  VODMA_VODMA_V1CHROMA_FMT_seq_color_swap_shift                           (5)
#define  VODMA_VODMA_V1CHROMA_FMT_alpha_position_shift                           (4)
#define  VODMA_VODMA_V1CHROMA_FMT_encfmt_shift                                   (0)
#define  VODMA_VODMA_V1CHROMA_FMT_g_position_mask                                (0x00000300)
#define  VODMA_VODMA_V1CHROMA_FMT_seq_color_swap_mask                            (0x000000E0)
#define  VODMA_VODMA_V1CHROMA_FMT_alpha_position_mask                            (0x00000010)
#define  VODMA_VODMA_V1CHROMA_FMT_encfmt_mask                                    (0x0000000F)
#define  VODMA_VODMA_V1CHROMA_FMT_g_position(data)                               (0x00000300&((data)<<8))
#define  VODMA_VODMA_V1CHROMA_FMT_seq_color_swap(data)                           (0x000000E0&((data)<<5))
#define  VODMA_VODMA_V1CHROMA_FMT_alpha_position(data)                           (0x00000010&((data)<<4))
#define  VODMA_VODMA_V1CHROMA_FMT_encfmt(data)                                   (0x0000000F&(data))
#define  VODMA_VODMA_V1CHROMA_FMT_get_g_position(data)                           ((0x00000300&(data))>>8)
#define  VODMA_VODMA_V1CHROMA_FMT_get_seq_color_swap(data)                       ((0x000000E0&(data))>>5)
#define  VODMA_VODMA_V1CHROMA_FMT_get_alpha_position(data)                       ((0x00000010&(data))>>4)
#define  VODMA_VODMA_V1CHROMA_FMT_get_encfmt(data)                               (0x0000000F&(data))

#define  VODMA_VODMA_V1_CU                                                       0x18005034
#define  VODMA_VODMA_V1_CU_reg_addr                                              "0xB8005034"
#define  VODMA_VODMA_V1_CU_reg                                                   0xB8005034
#define  VODMA_VODMA_V1_CU_inst_addr                                             "0x001F"
#define  set_VODMA_VODMA_V1_CU_reg(data)                                         (*((volatile unsigned int*)VODMA_VODMA_V1_CU_reg)=data)
#define  get_VODMA_VODMA_V1_CU_reg                                               (*((volatile unsigned int*)VODMA_VODMA_V1_CU_reg))
#define  VODMA_VODMA_V1_CU_mode_shift                                            (0)
#define  VODMA_VODMA_V1_CU_mode_mask                                             (0x00000007)
#define  VODMA_VODMA_V1_CU_mode(data)                                            (0x00000007&(data))
#define  VODMA_VODMA_V1_CU_get_mode(data)                                        (0x00000007&(data))

#define  VODMA_VODMA_V1422_TO_444                                                0x18005038
#define  VODMA_VODMA_V1422_TO_444_reg_addr                                       "0xB8005038"
#define  VODMA_VODMA_V1422_TO_444_reg                                            0xB8005038
#define  VODMA_VODMA_V1422_TO_444_inst_addr                                      "0x0020"
#define  set_VODMA_VODMA_V1422_TO_444_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1422_TO_444_reg)=data)
#define  get_VODMA_VODMA_V1422_TO_444_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1422_TO_444_reg))
#define  VODMA_VODMA_V1422_TO_444_fir422_sel_shift                               (0)
#define  VODMA_VODMA_V1422_TO_444_fir422_sel_mask                                (0x00000003)
#define  VODMA_VODMA_V1422_TO_444_fir422_sel(data)                               (0x00000003&(data))
#define  VODMA_VODMA_V1422_TO_444_get_fir422_sel(data)                           (0x00000003&(data))

#define  VODMA_VODMA_LINE_SELECT                                                 0x18005040
#define  VODMA_VODMA_LINE_SELECT_reg_addr                                        "0xB8005040"
#define  VODMA_VODMA_LINE_SELECT_reg                                             0xB8005040
#define  VODMA_VODMA_LINE_SELECT_inst_addr                                       "0x0021"
#define  set_VODMA_VODMA_LINE_SELECT_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_LINE_SELECT_reg)=data)
#define  get_VODMA_VODMA_LINE_SELECT_reg                                         (*((volatile unsigned int*)VODMA_VODMA_LINE_SELECT_reg))
#define  VODMA_VODMA_LINE_SELECT_y1_line_select_shift                            (1)
#define  VODMA_VODMA_LINE_SELECT_c1_line_select_shift                            (0)
#define  VODMA_VODMA_LINE_SELECT_y1_line_select_mask                             (0x00000002)
#define  VODMA_VODMA_LINE_SELECT_c1_line_select_mask                             (0x00000001)
#define  VODMA_VODMA_LINE_SELECT_y1_line_select(data)                            (0x00000002&((data)<<1))
#define  VODMA_VODMA_LINE_SELECT_c1_line_select(data)                            (0x00000001&(data))
#define  VODMA_VODMA_LINE_SELECT_get_y1_line_select(data)                        ((0x00000002&(data))>>1)
#define  VODMA_VODMA_LINE_SELECT_get_c1_line_select(data)                        (0x00000001&(data))

#define  VODMA_VODMA_V1SGEN                                                      0x18005070
#define  VODMA_VODMA_V1SGEN_reg_addr                                             "0xB8005070"
#define  VODMA_VODMA_V1SGEN_reg                                                  0xB8005070
#define  VODMA_VODMA_V1SGEN_inst_addr                                            "0x0022"
#define  set_VODMA_VODMA_V1SGEN_reg(data)                                        (*((volatile unsigned int*)VODMA_VODMA_V1SGEN_reg)=data)
#define  get_VODMA_VODMA_V1SGEN_reg                                              (*((volatile unsigned int*)VODMA_VODMA_V1SGEN_reg))
#define  VODMA_VODMA_V1SGEN_vthr_rst1_shift                                      (30)
#define  VODMA_VODMA_V1SGEN_v_thr_shift                                          (16)
#define  VODMA_VODMA_V1SGEN_h_thr_shift                                          (0)
#define  VODMA_VODMA_V1SGEN_vthr_rst1_mask                                       (0x40000000)
#define  VODMA_VODMA_V1SGEN_v_thr_mask                                           (0x0FFF0000)
#define  VODMA_VODMA_V1SGEN_h_thr_mask                                           (0x00001FFF)
#define  VODMA_VODMA_V1SGEN_vthr_rst1(data)                                      (0x40000000&((data)<<30))
#define  VODMA_VODMA_V1SGEN_v_thr(data)                                          (0x0FFF0000&((data)<<16))
#define  VODMA_VODMA_V1SGEN_h_thr(data)                                          (0x00001FFF&(data))
#define  VODMA_VODMA_V1SGEN_get_vthr_rst1(data)                                  ((0x40000000&(data))>>30)
#define  VODMA_VODMA_V1SGEN_get_v_thr(data)                                      ((0x0FFF0000&(data))>>16)
#define  VODMA_VODMA_V1SGEN_get_h_thr(data)                                      (0x00001FFF&(data))

#define  VODMA_VODMA_V1INT                                                       0x18005074
#define  VODMA_VODMA_V1INT_reg_addr                                              "0xB8005074"
#define  VODMA_VODMA_V1INT_reg                                                   0xB8005074
#define  VODMA_VODMA_V1INT_inst_addr                                             "0x0023"
#define  set_VODMA_VODMA_V1INT_reg(data)                                         (*((volatile unsigned int*)VODMA_VODMA_V1INT_reg)=data)
#define  get_VODMA_VODMA_V1INT_reg                                               (*((volatile unsigned int*)VODMA_VODMA_V1INT_reg))
#define  VODMA_VODMA_V1INT_den_src_shift                                         (19)
#define  VODMA_VODMA_V1INT_vgip_en_shift                                         (18)
#define  VODMA_VODMA_V1INT_interlace_shift                                       (17)
#define  VODMA_VODMA_V1INT_top_fld_indc_shift                                    (16)
#define  VODMA_VODMA_V1INT_v_thr_shift                                           (0)
#define  VODMA_VODMA_V1INT_den_src_mask                                          (0x00080000)
#define  VODMA_VODMA_V1INT_vgip_en_mask                                          (0x00040000)
#define  VODMA_VODMA_V1INT_interlace_mask                                        (0x00020000)
#define  VODMA_VODMA_V1INT_top_fld_indc_mask                                     (0x00010000)
#define  VODMA_VODMA_V1INT_v_thr_mask                                            (0x00000FFF)
#define  VODMA_VODMA_V1INT_den_src(data)                                         (0x00080000&((data)<<19))
#define  VODMA_VODMA_V1INT_vgip_en(data)                                         (0x00040000&((data)<<18))
#define  VODMA_VODMA_V1INT_interlace(data)                                       (0x00020000&((data)<<17))
#define  VODMA_VODMA_V1INT_top_fld_indc(data)                                    (0x00010000&((data)<<16))
#define  VODMA_VODMA_V1INT_v_thr(data)                                           (0x00000FFF&(data))
#define  VODMA_VODMA_V1INT_get_den_src(data)                                     ((0x00080000&(data))>>19)
#define  VODMA_VODMA_V1INT_get_vgip_en(data)                                     ((0x00040000&(data))>>18)
#define  VODMA_VODMA_V1INT_get_interlace(data)                                   ((0x00020000&(data))>>17)
#define  VODMA_VODMA_V1INT_get_top_fld_indc(data)                                ((0x00010000&(data))>>16)
#define  VODMA_VODMA_V1INT_get_v_thr(data)                                       (0x00000FFF&(data))

#define  VODMA_VODMA_V1VGIP_IVS1                                                 0x18005078
#define  VODMA_VODMA_V1VGIP_IVS1_reg_addr                                        "0xB8005078"
#define  VODMA_VODMA_V1VGIP_IVS1_reg                                             0xB8005078
#define  VODMA_VODMA_V1VGIP_IVS1_inst_addr                                       "0x0024"
#define  set_VODMA_VODMA_V1VGIP_IVS1_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_IVS1_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_IVS1_reg                                         (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_IVS1_reg))
#define  VODMA_VODMA_V1VGIP_IVS1_v_end_shift                                     (16)
#define  VODMA_VODMA_V1VGIP_IVS1_v_st_shift                                      (0)
#define  VODMA_VODMA_V1VGIP_IVS1_v_end_mask                                      (0x0FFF0000)
#define  VODMA_VODMA_V1VGIP_IVS1_v_st_mask                                       (0x00000FFF)
#define  VODMA_VODMA_V1VGIP_IVS1_v_end(data)                                     (0x0FFF0000&((data)<<16))
#define  VODMA_VODMA_V1VGIP_IVS1_v_st(data)                                      (0x00000FFF&(data))
#define  VODMA_VODMA_V1VGIP_IVS1_get_v_end(data)                                 ((0x0FFF0000&(data))>>16)
#define  VODMA_VODMA_V1VGIP_IVS1_get_v_st(data)                                  (0x00000FFF&(data))

#define  VODMA_VODMA_V1VGIP_IVS2                                                 0x1800507C
#define  VODMA_VODMA_V1VGIP_IVS2_reg_addr                                        "0xB800507C"
#define  VODMA_VODMA_V1VGIP_IVS2_reg                                             0xB800507C
#define  VODMA_VODMA_V1VGIP_IVS2_inst_addr                                       "0x0025"
#define  set_VODMA_VODMA_V1VGIP_IVS2_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_IVS2_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_IVS2_reg                                         (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_IVS2_reg))
#define  VODMA_VODMA_V1VGIP_IVS2_v_end_shift                                     (16)
#define  VODMA_VODMA_V1VGIP_IVS2_v_st_shift                                      (0)
#define  VODMA_VODMA_V1VGIP_IVS2_v_end_mask                                      (0x0FFF0000)
#define  VODMA_VODMA_V1VGIP_IVS2_v_st_mask                                       (0x00000FFF)
#define  VODMA_VODMA_V1VGIP_IVS2_v_end(data)                                     (0x0FFF0000&((data)<<16))
#define  VODMA_VODMA_V1VGIP_IVS2_v_st(data)                                      (0x00000FFF&(data))
#define  VODMA_VODMA_V1VGIP_IVS2_get_v_end(data)                                 ((0x0FFF0000&(data))>>16)
#define  VODMA_VODMA_V1VGIP_IVS2_get_v_st(data)                                  (0x00000FFF&(data))

#define  VODMA_VODMA_V1VGIP_IHS                                                  0x18005080
#define  VODMA_VODMA_V1VGIP_IHS_reg_addr                                         "0xB8005080"
#define  VODMA_VODMA_V1VGIP_IHS_reg                                              0xB8005080
#define  VODMA_VODMA_V1VGIP_IHS_inst_addr                                        "0x0026"
#define  set_VODMA_VODMA_V1VGIP_IHS_reg(data)                                    (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_IHS_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_IHS_reg                                          (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_IHS_reg))
#define  VODMA_VODMA_V1VGIP_IHS_h_st_shift                                       (0)
#define  VODMA_VODMA_V1VGIP_IHS_h_st_mask                                        (0x00001FFF)
#define  VODMA_VODMA_V1VGIP_IHS_h_st(data)                                       (0x00001FFF&(data))
#define  VODMA_VODMA_V1VGIP_IHS_get_h_st(data)                                   (0x00001FFF&(data))

#define  VODMA_VODMA_V1VGIP_FD                                                   0x18005084
#define  VODMA_VODMA_V1VGIP_FD_reg_addr                                          "0xB8005084"
#define  VODMA_VODMA_V1VGIP_FD_reg                                               0xB8005084
#define  VODMA_VODMA_V1VGIP_FD_inst_addr                                         "0x0027"
#define  set_VODMA_VODMA_V1VGIP_FD_reg(data)                                     (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_FD_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_FD_reg                                           (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_FD_reg))
#define  VODMA_VODMA_V1VGIP_FD_v_end_shift                                       (16)
#define  VODMA_VODMA_V1VGIP_FD_v_st_shift                                        (0)
#define  VODMA_VODMA_V1VGIP_FD_v_end_mask                                        (0x0FFF0000)
#define  VODMA_VODMA_V1VGIP_FD_v_st_mask                                         (0x00000FFF)
#define  VODMA_VODMA_V1VGIP_FD_v_end(data)                                       (0x0FFF0000&((data)<<16))
#define  VODMA_VODMA_V1VGIP_FD_v_st(data)                                        (0x00000FFF&(data))
#define  VODMA_VODMA_V1VGIP_FD_get_v_end(data)                                   ((0x0FFF0000&(data))>>16)
#define  VODMA_VODMA_V1VGIP_FD_get_v_st(data)                                    (0x00000FFF&(data))

#define  VODMA_VODMA_V1VGIP_FD2                                                  0x18005088
#define  VODMA_VODMA_V1VGIP_FD2_reg_addr                                         "0xB8005088"
#define  VODMA_VODMA_V1VGIP_FD2_reg                                              0xB8005088
#define  VODMA_VODMA_V1VGIP_FD2_inst_addr                                        "0x0028"
#define  set_VODMA_VODMA_V1VGIP_FD2_reg(data)                                    (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_FD2_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_FD2_reg                                          (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_FD2_reg))
#define  VODMA_VODMA_V1VGIP_FD2_v_end_shift                                      (16)
#define  VODMA_VODMA_V1VGIP_FD2_v_st_shift                                       (0)
#define  VODMA_VODMA_V1VGIP_FD2_v_end_mask                                       (0x0FFF0000)
#define  VODMA_VODMA_V1VGIP_FD2_v_st_mask                                        (0x00000FFF)
#define  VODMA_VODMA_V1VGIP_FD2_v_end(data)                                      (0x0FFF0000&((data)<<16))
#define  VODMA_VODMA_V1VGIP_FD2_v_st(data)                                       (0x00000FFF&(data))
#define  VODMA_VODMA_V1VGIP_FD2_get_v_end(data)                                  ((0x0FFF0000&(data))>>16)
#define  VODMA_VODMA_V1VGIP_FD2_get_v_st(data)                                   (0x00000FFF&(data))

#define  VODMA_VODMA_V1VGIP_HACT                                                 0x1800508C
#define  VODMA_VODMA_V1VGIP_HACT_reg_addr                                        "0xB800508C"
#define  VODMA_VODMA_V1VGIP_HACT_reg                                             0xB800508C
#define  VODMA_VODMA_V1VGIP_HACT_inst_addr                                       "0x0029"
#define  set_VODMA_VODMA_V1VGIP_HACT_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_HACT_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_HACT_reg                                         (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_HACT_reg))
#define  VODMA_VODMA_V1VGIP_HACT_h_end_shift                                     (16)
#define  VODMA_VODMA_V1VGIP_HACT_h_st_shift                                      (0)
#define  VODMA_VODMA_V1VGIP_HACT_h_end_mask                                      (0x1FFF0000)
#define  VODMA_VODMA_V1VGIP_HACT_h_st_mask                                       (0x00001FFF)
#define  VODMA_VODMA_V1VGIP_HACT_h_end(data)                                     (0x1FFF0000&((data)<<16))
#define  VODMA_VODMA_V1VGIP_HACT_h_st(data)                                      (0x00001FFF&(data))
#define  VODMA_VODMA_V1VGIP_HACT_get_h_end(data)                                 ((0x1FFF0000&(data))>>16)
#define  VODMA_VODMA_V1VGIP_HACT_get_h_st(data)                                  (0x00001FFF&(data))

#define  VODMA_VODMA_V1VGIP_VACT1                                                0x18005090
#define  VODMA_VODMA_V1VGIP_VACT1_reg_addr                                       "0xB8005090"
#define  VODMA_VODMA_V1VGIP_VACT1_reg                                            0xB8005090
#define  VODMA_VODMA_V1VGIP_VACT1_inst_addr                                      "0x002A"
#define  set_VODMA_VODMA_V1VGIP_VACT1_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_VACT1_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_VACT1_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_VACT1_reg))
#define  VODMA_VODMA_V1VGIP_VACT1_v_end_shift                                    (16)
#define  VODMA_VODMA_V1VGIP_VACT1_v_st_shift                                     (0)
#define  VODMA_VODMA_V1VGIP_VACT1_v_end_mask                                     (0x0FFF0000)
#define  VODMA_VODMA_V1VGIP_VACT1_v_st_mask                                      (0x00000FFF)
#define  VODMA_VODMA_V1VGIP_VACT1_v_end(data)                                    (0x0FFF0000&((data)<<16))
#define  VODMA_VODMA_V1VGIP_VACT1_v_st(data)                                     (0x00000FFF&(data))
#define  VODMA_VODMA_V1VGIP_VACT1_get_v_end(data)                                ((0x0FFF0000&(data))>>16)
#define  VODMA_VODMA_V1VGIP_VACT1_get_v_st(data)                                 (0x00000FFF&(data))

#define  VODMA_VODMA_V1VGIP_VACT2                                                0x18005094
#define  VODMA_VODMA_V1VGIP_VACT2_reg_addr                                       "0xB8005094"
#define  VODMA_VODMA_V1VGIP_VACT2_reg                                            0xB8005094
#define  VODMA_VODMA_V1VGIP_VACT2_inst_addr                                      "0x002B"
#define  set_VODMA_VODMA_V1VGIP_VACT2_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_VACT2_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_VACT2_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_VACT2_reg))
#define  VODMA_VODMA_V1VGIP_VACT2_v_end_shift                                    (16)
#define  VODMA_VODMA_V1VGIP_VACT2_v_st_shift                                     (0)
#define  VODMA_VODMA_V1VGIP_VACT2_v_end_mask                                     (0x0FFF0000)
#define  VODMA_VODMA_V1VGIP_VACT2_v_st_mask                                      (0x00000FFF)
#define  VODMA_VODMA_V1VGIP_VACT2_v_end(data)                                    (0x0FFF0000&((data)<<16))
#define  VODMA_VODMA_V1VGIP_VACT2_v_st(data)                                     (0x00000FFF&(data))
#define  VODMA_VODMA_V1VGIP_VACT2_get_v_end(data)                                ((0x0FFF0000&(data))>>16)
#define  VODMA_VODMA_V1VGIP_VACT2_get_v_st(data)                                 (0x00000FFF&(data))

#define  VODMA_VODMA_V1VGIP_HBG                                                  0x18005098
#define  VODMA_VODMA_V1VGIP_HBG_reg_addr                                         "0xB8005098"
#define  VODMA_VODMA_V1VGIP_HBG_reg                                              0xB8005098
#define  VODMA_VODMA_V1VGIP_HBG_inst_addr                                        "0x002C"
#define  set_VODMA_VODMA_V1VGIP_HBG_reg(data)                                    (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_HBG_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_HBG_reg                                          (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_HBG_reg))
#define  VODMA_VODMA_V1VGIP_HBG_h_end_shift                                      (16)
#define  VODMA_VODMA_V1VGIP_HBG_h_st_shift                                       (0)
#define  VODMA_VODMA_V1VGIP_HBG_h_end_mask                                       (0x1FFF0000)
#define  VODMA_VODMA_V1VGIP_HBG_h_st_mask                                        (0x00001FFF)
#define  VODMA_VODMA_V1VGIP_HBG_h_end(data)                                      (0x1FFF0000&((data)<<16))
#define  VODMA_VODMA_V1VGIP_HBG_h_st(data)                                       (0x00001FFF&(data))
#define  VODMA_VODMA_V1VGIP_HBG_get_h_end(data)                                  ((0x1FFF0000&(data))>>16)
#define  VODMA_VODMA_V1VGIP_HBG_get_h_st(data)                                   (0x00001FFF&(data))

#define  VODMA_VODMA_V1VGIP_VBG1                                                 0x1800509C
#define  VODMA_VODMA_V1VGIP_VBG1_reg_addr                                        "0xB800509C"
#define  VODMA_VODMA_V1VGIP_VBG1_reg                                             0xB800509C
#define  VODMA_VODMA_V1VGIP_VBG1_inst_addr                                       "0x002D"
#define  set_VODMA_VODMA_V1VGIP_VBG1_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_VBG1_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_VBG1_reg                                         (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_VBG1_reg))
#define  VODMA_VODMA_V1VGIP_VBG1_v_end_shift                                     (16)
#define  VODMA_VODMA_V1VGIP_VBG1_v_st_shift                                      (0)
#define  VODMA_VODMA_V1VGIP_VBG1_v_end_mask                                      (0x0FFF0000)
#define  VODMA_VODMA_V1VGIP_VBG1_v_st_mask                                       (0x00000FFF)
#define  VODMA_VODMA_V1VGIP_VBG1_v_end(data)                                     (0x0FFF0000&((data)<<16))
#define  VODMA_VODMA_V1VGIP_VBG1_v_st(data)                                      (0x00000FFF&(data))
#define  VODMA_VODMA_V1VGIP_VBG1_get_v_end(data)                                 ((0x0FFF0000&(data))>>16)
#define  VODMA_VODMA_V1VGIP_VBG1_get_v_st(data)                                  (0x00000FFF&(data))

#define  VODMA_VODMA_V1VGIP_VBG2                                                 0x180050A0
#define  VODMA_VODMA_V1VGIP_VBG2_reg_addr                                        "0xB80050A0"
#define  VODMA_VODMA_V1VGIP_VBG2_reg                                             0xB80050A0
#define  VODMA_VODMA_V1VGIP_VBG2_inst_addr                                       "0x002E"
#define  set_VODMA_VODMA_V1VGIP_VBG2_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_VBG2_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_VBG2_reg                                         (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_VBG2_reg))
#define  VODMA_VODMA_V1VGIP_VBG2_v_end_shift                                     (16)
#define  VODMA_VODMA_V1VGIP_VBG2_v_st_shift                                      (0)
#define  VODMA_VODMA_V1VGIP_VBG2_v_end_mask                                      (0x0FFF0000)
#define  VODMA_VODMA_V1VGIP_VBG2_v_st_mask                                       (0x00000FFF)
#define  VODMA_VODMA_V1VGIP_VBG2_v_end(data)                                     (0x0FFF0000&((data)<<16))
#define  VODMA_VODMA_V1VGIP_VBG2_v_st(data)                                      (0x00000FFF&(data))
#define  VODMA_VODMA_V1VGIP_VBG2_get_v_end(data)                                 ((0x0FFF0000&(data))>>16)
#define  VODMA_VODMA_V1VGIP_VBG2_get_v_st(data)                                  (0x00000FFF&(data))

#define  VODMA_VODMA_V1VGIP_BG_CLR                                               0x180050A4
#define  VODMA_VODMA_V1VGIP_BG_CLR_reg_addr                                      "0xB80050A4"
#define  VODMA_VODMA_V1VGIP_BG_CLR_reg                                           0xB80050A4
#define  VODMA_VODMA_V1VGIP_BG_CLR_inst_addr                                     "0x002F"
#define  set_VODMA_VODMA_V1VGIP_BG_CLR_reg(data)                                 (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_BG_CLR_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_BG_CLR_reg                                       (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_BG_CLR_reg))
#define  VODMA_VODMA_V1VGIP_BG_CLR_bg_v_shift                                    (20)
#define  VODMA_VODMA_V1VGIP_BG_CLR_bg_u_shift                                    (10)
#define  VODMA_VODMA_V1VGIP_BG_CLR_bg_y_shift                                    (0)
#define  VODMA_VODMA_V1VGIP_BG_CLR_bg_v_mask                                     (0x3FF00000)
#define  VODMA_VODMA_V1VGIP_BG_CLR_bg_u_mask                                     (0x000FFC00)
#define  VODMA_VODMA_V1VGIP_BG_CLR_bg_y_mask                                     (0x000003FF)
#define  VODMA_VODMA_V1VGIP_BG_CLR_bg_v(data)                                    (0x3FF00000&((data)<<20))
#define  VODMA_VODMA_V1VGIP_BG_CLR_bg_u(data)                                    (0x000FFC00&((data)<<10))
#define  VODMA_VODMA_V1VGIP_BG_CLR_bg_y(data)                                    (0x000003FF&(data))
#define  VODMA_VODMA_V1VGIP_BG_CLR_get_bg_v(data)                                ((0x3FF00000&(data))>>20)
#define  VODMA_VODMA_V1VGIP_BG_CLR_get_bg_u(data)                                ((0x000FFC00&(data))>>10)
#define  VODMA_VODMA_V1VGIP_BG_CLR_get_bg_y(data)                                (0x000003FF&(data))

#define  VODMA_VODMA_V1VGIP_MASK_CTRL                                            0x1800505C
#define  VODMA_VODMA_V1VGIP_MASK_CTRL_reg_addr                                   "0xB800505C"
#define  VODMA_VODMA_V1VGIP_MASK_CTRL_reg                                        0xB800505C
#define  VODMA_VODMA_V1VGIP_MASK_CTRL_inst_addr                                  "0x0030"
#define  set_VODMA_VODMA_V1VGIP_MASK_CTRL_reg(data)                              (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_MASK_CTRL_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_MASK_CTRL_reg                                    (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_MASK_CTRL_reg))
#define  VODMA_VODMA_V1VGIP_MASK_CTRL_mask_den_en_shift                          (2)
#define  VODMA_VODMA_V1VGIP_MASK_CTRL_mask_data_en_shift                         (0)
#define  VODMA_VODMA_V1VGIP_MASK_CTRL_mask_den_en_mask                           (0x00000004)
#define  VODMA_VODMA_V1VGIP_MASK_CTRL_mask_data_en_mask                          (0x00000003)
#define  VODMA_VODMA_V1VGIP_MASK_CTRL_mask_den_en(data)                          (0x00000004&((data)<<2))
#define  VODMA_VODMA_V1VGIP_MASK_CTRL_mask_data_en(data)                         (0x00000003&(data))
#define  VODMA_VODMA_V1VGIP_MASK_CTRL_get_mask_den_en(data)                      ((0x00000004&(data))>>2)
#define  VODMA_VODMA_V1VGIP_MASK_CTRL_get_mask_data_en(data)                     (0x00000003&(data))

#define  VODMA_VODMA_V1VGIP_HMASK                                                0x18005060
#define  VODMA_VODMA_V1VGIP_HMASK_reg_addr                                       "0xB8005060"
#define  VODMA_VODMA_V1VGIP_HMASK_reg                                            0xB8005060
#define  VODMA_VODMA_V1VGIP_HMASK_inst_addr                                      "0x0031"
#define  set_VODMA_VODMA_V1VGIP_HMASK_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_HMASK_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_HMASK_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_HMASK_reg))
#define  VODMA_VODMA_V1VGIP_HMASK_h_end_shift                                    (16)
#define  VODMA_VODMA_V1VGIP_HMASK_h_st_shift                                     (0)
#define  VODMA_VODMA_V1VGIP_HMASK_h_end_mask                                     (0xFFFF0000)
#define  VODMA_VODMA_V1VGIP_HMASK_h_st_mask                                      (0x0000FFFF)
#define  VODMA_VODMA_V1VGIP_HMASK_h_end(data)                                    (0xFFFF0000&((data)<<16))
#define  VODMA_VODMA_V1VGIP_HMASK_h_st(data)                                     (0x0000FFFF&(data))
#define  VODMA_VODMA_V1VGIP_HMASK_get_h_end(data)                                ((0xFFFF0000&(data))>>16)
#define  VODMA_VODMA_V1VGIP_HMASK_get_h_st(data)                                 (0x0000FFFF&(data))

#define  VODMA_VODMA_V1VGIP_VMASK                                                0x18005064
#define  VODMA_VODMA_V1VGIP_VMASK_reg_addr                                       "0xB8005064"
#define  VODMA_VODMA_V1VGIP_VMASK_reg                                            0xB8005064
#define  VODMA_VODMA_V1VGIP_VMASK_inst_addr                                      "0x0032"
#define  set_VODMA_VODMA_V1VGIP_VMASK_reg(data)                                  (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_VMASK_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_VMASK_reg                                        (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_VMASK_reg))
#define  VODMA_VODMA_V1VGIP_VMASK_v_end_shift                                    (16)
#define  VODMA_VODMA_V1VGIP_VMASK_v_st_shift                                     (0)
#define  VODMA_VODMA_V1VGIP_VMASK_v_end_mask                                     (0xFFFF0000)
#define  VODMA_VODMA_V1VGIP_VMASK_v_st_mask                                      (0x0000FFFF)
#define  VODMA_VODMA_V1VGIP_VMASK_v_end(data)                                    (0xFFFF0000&((data)<<16))
#define  VODMA_VODMA_V1VGIP_VMASK_v_st(data)                                     (0x0000FFFF&(data))
#define  VODMA_VODMA_V1VGIP_VMASK_get_v_end(data)                                ((0xFFFF0000&(data))>>16)
#define  VODMA_VODMA_V1VGIP_VMASK_get_v_st(data)                                 (0x0000FFFF&(data))

#define  VODMA_VODMA_ACCESSDATA_CTRL                                             0x1800503C
#define  VODMA_VODMA_ACCESSDATA_CTRL_reg_addr                                    "0xB800503C"
#define  VODMA_VODMA_ACCESSDATA_CTRL_reg                                         0xB800503C
#define  VODMA_VODMA_ACCESSDATA_CTRL_inst_addr                                   "0x0033"
#define  set_VODMA_VODMA_ACCESSDATA_CTRL_reg(data)                               (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_CTRL_reg)=data)
#define  get_VODMA_VODMA_ACCESSDATA_CTRL_reg                                     (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_CTRL_reg))
#define  VODMA_VODMA_ACCESSDATA_CTRL_write_en_shift                              (31)
#define  VODMA_VODMA_ACCESSDATA_CTRL_read_en_shift                               (30)
#define  VODMA_VODMA_ACCESSDATA_CTRL_starty_shift                                (16)
#define  VODMA_VODMA_ACCESSDATA_CTRL_block_shape_shift                           (15)
#define  VODMA_VODMA_ACCESSDATA_CTRL_startx_shift                                (0)
#define  VODMA_VODMA_ACCESSDATA_CTRL_write_en_mask                               (0x80000000)
#define  VODMA_VODMA_ACCESSDATA_CTRL_read_en_mask                                (0x40000000)
#define  VODMA_VODMA_ACCESSDATA_CTRL_starty_mask                                 (0x3FFF0000)
#define  VODMA_VODMA_ACCESSDATA_CTRL_block_shape_mask                            (0x00008000)
#define  VODMA_VODMA_ACCESSDATA_CTRL_startx_mask                                 (0x00003FFF)
#define  VODMA_VODMA_ACCESSDATA_CTRL_write_en(data)                              (0x80000000&((data)<<31))
#define  VODMA_VODMA_ACCESSDATA_CTRL_read_en(data)                               (0x40000000&((data)<<30))
#define  VODMA_VODMA_ACCESSDATA_CTRL_starty(data)                                (0x3FFF0000&((data)<<16))
#define  VODMA_VODMA_ACCESSDATA_CTRL_block_shape(data)                           (0x00008000&((data)<<15))
#define  VODMA_VODMA_ACCESSDATA_CTRL_startx(data)                                (0x00003FFF&(data))
#define  VODMA_VODMA_ACCESSDATA_CTRL_get_write_en(data)                          ((0x80000000&(data))>>31)
#define  VODMA_VODMA_ACCESSDATA_CTRL_get_read_en(data)                           ((0x40000000&(data))>>30)
#define  VODMA_VODMA_ACCESSDATA_CTRL_get_starty(data)                            ((0x3FFF0000&(data))>>16)
#define  VODMA_VODMA_ACCESSDATA_CTRL_get_block_shape(data)                       ((0x00008000&(data))>>15)
#define  VODMA_VODMA_ACCESSDATA_CTRL_get_startx(data)                            (0x00003FFF&(data))

#define  VODMA_VODMA_ACCESSDATA_Y1                                               0x18005068
#define  VODMA_VODMA_ACCESSDATA_Y1_reg_addr                                      "0xB8005068"
#define  VODMA_VODMA_ACCESSDATA_Y1_reg                                           0xB8005068
#define  VODMA_VODMA_ACCESSDATA_Y1_inst_addr                                     "0x0034"
#define  set_VODMA_VODMA_ACCESSDATA_Y1_reg(data)                                 (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_Y1_reg)=data)
#define  get_VODMA_VODMA_ACCESSDATA_Y1_reg                                       (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_Y1_reg))
#define  VODMA_VODMA_ACCESSDATA_Y1_y10_shift                                     (16)
#define  VODMA_VODMA_ACCESSDATA_Y1_y00_shift                                     (0)
#define  VODMA_VODMA_ACCESSDATA_Y1_y10_mask                                      (0x03FF0000)
#define  VODMA_VODMA_ACCESSDATA_Y1_y00_mask                                      (0x000003FF)
#define  VODMA_VODMA_ACCESSDATA_Y1_y10(data)                                     (0x03FF0000&((data)<<16))
#define  VODMA_VODMA_ACCESSDATA_Y1_y00(data)                                     (0x000003FF&(data))
#define  VODMA_VODMA_ACCESSDATA_Y1_get_y10(data)                                 ((0x03FF0000&(data))>>16)
#define  VODMA_VODMA_ACCESSDATA_Y1_get_y00(data)                                 (0x000003FF&(data))

#define  VODMA_VODMA_ACCESSDATA_Y2                                               0x1800506C
#define  VODMA_VODMA_ACCESSDATA_Y2_reg_addr                                      "0xB800506C"
#define  VODMA_VODMA_ACCESSDATA_Y2_reg                                           0xB800506C
#define  VODMA_VODMA_ACCESSDATA_Y2_inst_addr                                     "0x0035"
#define  set_VODMA_VODMA_ACCESSDATA_Y2_reg(data)                                 (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_Y2_reg)=data)
#define  get_VODMA_VODMA_ACCESSDATA_Y2_reg                                       (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_Y2_reg))
#define  VODMA_VODMA_ACCESSDATA_Y2_y11_shift                                     (16)
#define  VODMA_VODMA_ACCESSDATA_Y2_y01_shift                                     (0)
#define  VODMA_VODMA_ACCESSDATA_Y2_y11_mask                                      (0x03FF0000)
#define  VODMA_VODMA_ACCESSDATA_Y2_y01_mask                                      (0x000003FF)
#define  VODMA_VODMA_ACCESSDATA_Y2_y11(data)                                     (0x03FF0000&((data)<<16))
#define  VODMA_VODMA_ACCESSDATA_Y2_y01(data)                                     (0x000003FF&(data))
#define  VODMA_VODMA_ACCESSDATA_Y2_get_y11(data)                                 ((0x03FF0000&(data))>>16)
#define  VODMA_VODMA_ACCESSDATA_Y2_get_y01(data)                                 (0x000003FF&(data))

#define  VODMA_VODMA_ACCESSDATA_C1                                               0x180050AC
#define  VODMA_VODMA_ACCESSDATA_C1_reg_addr                                      "0xB80050AC"
#define  VODMA_VODMA_ACCESSDATA_C1_reg                                           0xB80050AC
#define  VODMA_VODMA_ACCESSDATA_C1_inst_addr                                     "0x0036"
#define  set_VODMA_VODMA_ACCESSDATA_C1_reg(data)                                 (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_C1_reg)=data)
#define  get_VODMA_VODMA_ACCESSDATA_C1_reg                                       (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_C1_reg))
#define  VODMA_VODMA_ACCESSDATA_C1_v00_shift                                     (16)
#define  VODMA_VODMA_ACCESSDATA_C1_u00_shift                                     (0)
#define  VODMA_VODMA_ACCESSDATA_C1_v00_mask                                      (0x03FF0000)
#define  VODMA_VODMA_ACCESSDATA_C1_u00_mask                                      (0x000003FF)
#define  VODMA_VODMA_ACCESSDATA_C1_v00(data)                                     (0x03FF0000&((data)<<16))
#define  VODMA_VODMA_ACCESSDATA_C1_u00(data)                                     (0x000003FF&(data))
#define  VODMA_VODMA_ACCESSDATA_C1_get_v00(data)                                 ((0x03FF0000&(data))>>16)
#define  VODMA_VODMA_ACCESSDATA_C1_get_u00(data)                                 (0x000003FF&(data))

#define  VODMA_VODMA_ACCESSDATA_C2                                               0x180050C0
#define  VODMA_VODMA_ACCESSDATA_C2_reg_addr                                      "0xB80050C0"
#define  VODMA_VODMA_ACCESSDATA_C2_reg                                           0xB80050C0
#define  VODMA_VODMA_ACCESSDATA_C2_inst_addr                                     "0x0037"
#define  set_VODMA_VODMA_ACCESSDATA_C2_reg(data)                                 (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_C2_reg)=data)
#define  get_VODMA_VODMA_ACCESSDATA_C2_reg                                       (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_C2_reg))
#define  VODMA_VODMA_ACCESSDATA_C2_v10_shift                                     (16)
#define  VODMA_VODMA_ACCESSDATA_C2_u10_shift                                     (0)
#define  VODMA_VODMA_ACCESSDATA_C2_v10_mask                                      (0x03FF0000)
#define  VODMA_VODMA_ACCESSDATA_C2_u10_mask                                      (0x000003FF)
#define  VODMA_VODMA_ACCESSDATA_C2_v10(data)                                     (0x03FF0000&((data)<<16))
#define  VODMA_VODMA_ACCESSDATA_C2_u10(data)                                     (0x000003FF&(data))
#define  VODMA_VODMA_ACCESSDATA_C2_get_v10(data)                                 ((0x03FF0000&(data))>>16)
#define  VODMA_VODMA_ACCESSDATA_C2_get_u10(data)                                 (0x000003FF&(data))

#define  VODMA_VODMA_ACCESSDATA_C3                                               0x180050CC
#define  VODMA_VODMA_ACCESSDATA_C3_reg_addr                                      "0xB80050CC"
#define  VODMA_VODMA_ACCESSDATA_C3_reg                                           0xB80050CC
#define  VODMA_VODMA_ACCESSDATA_C3_inst_addr                                     "0x0038"
#define  set_VODMA_VODMA_ACCESSDATA_C3_reg(data)                                 (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_C3_reg)=data)
#define  get_VODMA_VODMA_ACCESSDATA_C3_reg                                       (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_C3_reg))
#define  VODMA_VODMA_ACCESSDATA_C3_v01_shift                                     (16)
#define  VODMA_VODMA_ACCESSDATA_C3_u01_shift                                     (0)
#define  VODMA_VODMA_ACCESSDATA_C3_v01_mask                                      (0x03FF0000)
#define  VODMA_VODMA_ACCESSDATA_C3_u01_mask                                      (0x000003FF)
#define  VODMA_VODMA_ACCESSDATA_C3_v01(data)                                     (0x03FF0000&((data)<<16))
#define  VODMA_VODMA_ACCESSDATA_C3_u01(data)                                     (0x000003FF&(data))
#define  VODMA_VODMA_ACCESSDATA_C3_get_v01(data)                                 ((0x03FF0000&(data))>>16)
#define  VODMA_VODMA_ACCESSDATA_C3_get_u01(data)                                 (0x000003FF&(data))

#define  VODMA_VODMA_ACCESSDATA_C4                                               0x180050F8
#define  VODMA_VODMA_ACCESSDATA_C4_reg_addr                                      "0xB80050F8"
#define  VODMA_VODMA_ACCESSDATA_C4_reg                                           0xB80050F8
#define  VODMA_VODMA_ACCESSDATA_C4_inst_addr                                     "0x0039"
#define  set_VODMA_VODMA_ACCESSDATA_C4_reg(data)                                 (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_C4_reg)=data)
#define  get_VODMA_VODMA_ACCESSDATA_C4_reg                                       (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_C4_reg))
#define  VODMA_VODMA_ACCESSDATA_C4_v11_shift                                     (16)
#define  VODMA_VODMA_ACCESSDATA_C4_u11_shift                                     (0)
#define  VODMA_VODMA_ACCESSDATA_C4_v11_mask                                      (0x03FF0000)
#define  VODMA_VODMA_ACCESSDATA_C4_u11_mask                                      (0x000003FF)
#define  VODMA_VODMA_ACCESSDATA_C4_v11(data)                                     (0x03FF0000&((data)<<16))
#define  VODMA_VODMA_ACCESSDATA_C4_u11(data)                                     (0x000003FF&(data))
#define  VODMA_VODMA_ACCESSDATA_C4_get_v11(data)                                 ((0x03FF0000&(data))>>16)
#define  VODMA_VODMA_ACCESSDATA_C4_get_u11(data)                                 (0x000003FF&(data))

#define  VODMA_VODMA_ACCESSDATA_CLR                                              0x180050FC
#define  VODMA_VODMA_ACCESSDATA_CLR_reg_addr                                     "0xB80050FC"
#define  VODMA_VODMA_ACCESSDATA_CLR_reg                                          0xB80050FC
#define  VODMA_VODMA_ACCESSDATA_CLR_inst_addr                                    "0x003A"
#define  set_VODMA_VODMA_ACCESSDATA_CLR_reg(data)                                (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_CLR_reg)=data)
#define  get_VODMA_VODMA_ACCESSDATA_CLR_reg                                      (*((volatile unsigned int*)VODMA_VODMA_ACCESSDATA_CLR_reg))
#define  VODMA_VODMA_ACCESSDATA_CLR_access_v_shift                               (20)
#define  VODMA_VODMA_ACCESSDATA_CLR_access_u_shift                               (10)
#define  VODMA_VODMA_ACCESSDATA_CLR_access_y_shift                               (0)
#define  VODMA_VODMA_ACCESSDATA_CLR_access_v_mask                                (0x3FF00000)
#define  VODMA_VODMA_ACCESSDATA_CLR_access_u_mask                                (0x000FFC00)
#define  VODMA_VODMA_ACCESSDATA_CLR_access_y_mask                                (0x000003FF)
#define  VODMA_VODMA_ACCESSDATA_CLR_access_v(data)                               (0x3FF00000&((data)<<20))
#define  VODMA_VODMA_ACCESSDATA_CLR_access_u(data)                               (0x000FFC00&((data)<<10))
#define  VODMA_VODMA_ACCESSDATA_CLR_access_y(data)                               (0x000003FF&(data))
#define  VODMA_VODMA_ACCESSDATA_CLR_get_access_v(data)                           ((0x3FF00000&(data))>>20)
#define  VODMA_VODMA_ACCESSDATA_CLR_get_access_u(data)                           ((0x000FFC00&(data))>>10)
#define  VODMA_VODMA_ACCESSDATA_CLR_get_access_y(data)                           (0x000003FF&(data))

#define  VODMA_VODMA_V1VGIP_INTPOS                                               0x180050A8
#define  VODMA_VODMA_V1VGIP_INTPOS_reg_addr                                      "0xB80050A8"
#define  VODMA_VODMA_V1VGIP_INTPOS_reg                                           0xB80050A8
#define  VODMA_VODMA_V1VGIP_INTPOS_inst_addr                                     "0x003B"
#define  set_VODMA_VODMA_V1VGIP_INTPOS_reg(data)                                 (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_INTPOS_reg)=data)
#define  get_VODMA_VODMA_V1VGIP_INTPOS_reg                                       (*((volatile unsigned int*)VODMA_VODMA_V1VGIP_INTPOS_reg))
#define  VODMA_VODMA_V1VGIP_INTPOS_v2_shift                                      (16)
#define  VODMA_VODMA_V1VGIP_INTPOS_v1_shift                                      (0)
#define  VODMA_VODMA_V1VGIP_INTPOS_v2_mask                                       (0x0FFF0000)
#define  VODMA_VODMA_V1VGIP_INTPOS_v1_mask                                       (0x00000FFF)
#define  VODMA_VODMA_V1VGIP_INTPOS_v2(data)                                      (0x0FFF0000&((data)<<16))
#define  VODMA_VODMA_V1VGIP_INTPOS_v1(data)                                      (0x00000FFF&(data))
#define  VODMA_VODMA_V1VGIP_INTPOS_get_v2(data)                                  ((0x0FFF0000&(data))>>16)
#define  VODMA_VODMA_V1VGIP_INTPOS_get_v1(data)                                  (0x00000FFF&(data))

#define  VODMA_VODMA_VGIP_INTPOS                                                 0x180050B0
#define  VODMA_VODMA_VGIP_INTPOS_reg_addr                                        "0xB80050B0"
#define  VODMA_VODMA_VGIP_INTPOS_reg                                             0xB80050B0
#define  VODMA_VODMA_VGIP_INTPOS_inst_addr                                       "0x003C"
#define  set_VODMA_VODMA_VGIP_INTPOS_reg(data)                                   (*((volatile unsigned int*)VODMA_VODMA_VGIP_INTPOS_reg)=data)
#define  get_VODMA_VODMA_VGIP_INTPOS_reg                                         (*((volatile unsigned int*)VODMA_VODMA_VGIP_INTPOS_reg))
#define  VODMA_VODMA_VGIP_INTPOS_vodma_irq_ie_shift                              (31)
#define  VODMA_VODMA_VGIP_INTPOS_vpos_inte1_shift                                (2)
#define  VODMA_VODMA_VGIP_INTPOS_finish_inte1_shift                              (1)
#define  VODMA_VODMA_VGIP_INTPOS_buf_underflow_inte1_shift                       (0)
#define  VODMA_VODMA_VGIP_INTPOS_vodma_irq_ie_mask                               (0x80000000)
#define  VODMA_VODMA_VGIP_INTPOS_vpos_inte1_mask                                 (0x00000004)
#define  VODMA_VODMA_VGIP_INTPOS_finish_inte1_mask                               (0x00000002)
#define  VODMA_VODMA_VGIP_INTPOS_buf_underflow_inte1_mask                        (0x00000001)
#define  VODMA_VODMA_VGIP_INTPOS_vodma_irq_ie(data)                              (0x80000000&((data)<<31))
#define  VODMA_VODMA_VGIP_INTPOS_vpos_inte1(data)                                (0x00000004&((data)<<2))
#define  VODMA_VODMA_VGIP_INTPOS_finish_inte1(data)                              (0x00000002&((data)<<1))
#define  VODMA_VODMA_VGIP_INTPOS_buf_underflow_inte1(data)                       (0x00000001&(data))
#define  VODMA_VODMA_VGIP_INTPOS_get_vodma_irq_ie(data)                          ((0x80000000&(data))>>31)
#define  VODMA_VODMA_VGIP_INTPOS_get_vpos_inte1(data)                            ((0x00000004&(data))>>2)
#define  VODMA_VODMA_VGIP_INTPOS_get_finish_inte1(data)                          ((0x00000002&(data))>>1)
#define  VODMA_VODMA_VGIP_INTPOS_get_buf_underflow_inte1(data)                   (0x00000001&(data))

#define  VODMA_VODMA_VGIP_INTST                                                  0x180050B4
#define  VODMA_VODMA_VGIP_INTST_reg_addr                                         "0xB80050B4"
#define  VODMA_VODMA_VGIP_INTST_reg                                              0xB80050B4
#define  VODMA_VODMA_VGIP_INTST_inst_addr                                        "0x003D"
#define  set_VODMA_VODMA_VGIP_INTST_reg(data)                                    (*((volatile unsigned int*)VODMA_VODMA_VGIP_INTST_reg)=data)
#define  get_VODMA_VODMA_VGIP_INTST_reg                                          (*((volatile unsigned int*)VODMA_VODMA_VGIP_INTST_reg))
#define  VODMA_VODMA_VGIP_INTST_hist_irq_record_ro_shift                         (31)
#define  VODMA_VODMA_VGIP_INTST_i2rnd_irq_record_ro_shift                        (30)
#define  VODMA_VODMA_VGIP_INTST_decomp_irq_record_ro_shift                       (29)
#define  VODMA_VODMA_VGIP_INTST_vodma_irq_record_ro_shift                        (28)
#define  VODMA_VODMA_VGIP_INTST_vpos_ints1_shift                                 (2)
#define  VODMA_VODMA_VGIP_INTST_finish_ints1_shift                               (1)
#define  VODMA_VODMA_VGIP_INTST_buf_underflow_ints1_shift                        (0)
#define  VODMA_VODMA_VGIP_INTST_hist_irq_record_ro_mask                          (0x80000000)
#define  VODMA_VODMA_VGIP_INTST_i2rnd_irq_record_ro_mask                         (0x40000000)
#define  VODMA_VODMA_VGIP_INTST_decomp_irq_record_ro_mask                        (0x20000000)
#define  VODMA_VODMA_VGIP_INTST_vodma_irq_record_ro_mask                         (0x10000000)
#define  VODMA_VODMA_VGIP_INTST_vpos_ints1_mask                                  (0x00000004)
#define  VODMA_VODMA_VGIP_INTST_finish_ints1_mask                                (0x00000002)
#define  VODMA_VODMA_VGIP_INTST_buf_underflow_ints1_mask                         (0x00000001)
#define  VODMA_VODMA_VGIP_INTST_hist_irq_record_ro(data)                         (0x80000000&((data)<<31))
#define  VODMA_VODMA_VGIP_INTST_i2rnd_irq_record_ro(data)                        (0x40000000&((data)<<30))
#define  VODMA_VODMA_VGIP_INTST_decomp_irq_record_ro(data)                       (0x20000000&((data)<<29))
#define  VODMA_VODMA_VGIP_INTST_vodma_irq_record_ro(data)                        (0x10000000&((data)<<28))
#define  VODMA_VODMA_VGIP_INTST_vpos_ints1(data)                                 (0x00000004&((data)<<2))
#define  VODMA_VODMA_VGIP_INTST_finish_ints1(data)                               (0x00000002&((data)<<1))
#define  VODMA_VODMA_VGIP_INTST_buf_underflow_ints1(data)                        (0x00000001&(data))
#define  VODMA_VODMA_VGIP_INTST_get_hist_irq_record_ro(data)                     ((0x80000000&(data))>>31)
#define  VODMA_VODMA_VGIP_INTST_get_i2rnd_irq_record_ro(data)                    ((0x40000000&(data))>>30)
#define  VODMA_VODMA_VGIP_INTST_get_decomp_irq_record_ro(data)                   ((0x20000000&(data))>>29)
#define  VODMA_VODMA_VGIP_INTST_get_vodma_irq_record_ro(data)                    ((0x10000000&(data))>>28)
#define  VODMA_VODMA_VGIP_INTST_get_vpos_ints1(data)                             ((0x00000004&(data))>>2)
#define  VODMA_VODMA_VGIP_INTST_get_finish_ints1(data)                           ((0x00000002&(data))>>1)
#define  VODMA_VODMA_VGIP_INTST_get_buf_underflow_ints1(data)                    (0x00000001&(data))

#define  VODMA_VODMA_VGIP_ST                                                     0x180050B8
#define  VODMA_VODMA_VGIP_ST_reg_addr                                            "0xB80050B8"
#define  VODMA_VODMA_VGIP_ST_reg                                                 0xB80050B8
#define  VODMA_VODMA_VGIP_ST_inst_addr                                           "0x003E"
#define  set_VODMA_VODMA_VGIP_ST_reg(data)                                       (*((volatile unsigned int*)VODMA_VODMA_VGIP_ST_reg)=data)
#define  get_VODMA_VODMA_VGIP_ST_reg                                             (*((volatile unsigned int*)VODMA_VODMA_VGIP_ST_reg))
#define  VODMA_VODMA_VGIP_ST_l_flag_status_shift                                 (3)
#define  VODMA_VODMA_VGIP_ST_vsync_status_shift                                  (2)
#define  VODMA_VODMA_VGIP_ST_v_active_shift                                      (1)
#define  VODMA_VODMA_VGIP_ST_field_status_shift                                  (0)
#define  VODMA_VODMA_VGIP_ST_l_flag_status_mask                                  (0x00000008)
#define  VODMA_VODMA_VGIP_ST_vsync_status_mask                                   (0x00000004)
#define  VODMA_VODMA_VGIP_ST_v_active_mask                                       (0x00000002)
#define  VODMA_VODMA_VGIP_ST_field_status_mask                                   (0x00000001)
#define  VODMA_VODMA_VGIP_ST_l_flag_status(data)                                 (0x00000008&((data)<<3))
#define  VODMA_VODMA_VGIP_ST_vsync_status(data)                                  (0x00000004&((data)<<2))
#define  VODMA_VODMA_VGIP_ST_v_active(data)                                      (0x00000002&((data)<<1))
#define  VODMA_VODMA_VGIP_ST_field_status(data)                                  (0x00000001&(data))
#define  VODMA_VODMA_VGIP_ST_get_l_flag_status(data)                             ((0x00000008&(data))>>3)
#define  VODMA_VODMA_VGIP_ST_get_vsync_status(data)                              ((0x00000004&(data))>>2)
#define  VODMA_VODMA_VGIP_ST_get_v_active(data)                                  ((0x00000002&(data))>>1)
#define  VODMA_VODMA_VGIP_ST_get_field_status(data)                              (0x00000001&(data))

#define  VODMA_VODMA_LINE_ST                                                     0x180050BC
#define  VODMA_VODMA_LINE_ST_reg_addr                                            "0xB80050BC"
#define  VODMA_VODMA_LINE_ST_reg                                                 0xB80050BC
#define  VODMA_VODMA_LINE_ST_inst_addr                                           "0x003F"
#define  set_VODMA_VODMA_LINE_ST_reg(data)                                       (*((volatile unsigned int*)VODMA_VODMA_LINE_ST_reg)=data)
#define  get_VODMA_VODMA_LINE_ST_reg                                             (*((volatile unsigned int*)VODMA_VODMA_LINE_ST_reg))
#define  VODMA_VODMA_LINE_ST_line_cnt_shift                                      (0)
#define  VODMA_VODMA_LINE_ST_line_cnt_mask                                       (0x00000FFF)
#define  VODMA_VODMA_LINE_ST_line_cnt(data)                                      (0x00000FFF&(data))
#define  VODMA_VODMA_LINE_ST_get_line_cnt(data)                                  (0x00000FFF&(data))

#define  VODMA_VODMA_BIST_MODE                                                   0x180051D0
#define  VODMA_VODMA_BIST_MODE_reg_addr                                          "0xB80051D0"
#define  VODMA_VODMA_BIST_MODE_reg                                               0xB80051D0
#define  VODMA_VODMA_BIST_MODE_inst_addr                                         "0x0040"
#define  set_VODMA_VODMA_BIST_MODE_reg(data)                                     (*((volatile unsigned int*)VODMA_VODMA_BIST_MODE_reg)=data)
#define  get_VODMA_VODMA_BIST_MODE_reg                                           (*((volatile unsigned int*)VODMA_VODMA_BIST_MODE_reg))
#define  VODMA_VODMA_BIST_MODE_vodma_bist_mode_2_shift                           (2)
#define  VODMA_VODMA_BIST_MODE_vodma_bist_mode_1_shift                           (1)
#define  VODMA_VODMA_BIST_MODE_vodma_bist_mode_0_shift                           (0)
#define  VODMA_VODMA_BIST_MODE_vodma_bist_mode_2_mask                            (0x00000004)
#define  VODMA_VODMA_BIST_MODE_vodma_bist_mode_1_mask                            (0x00000002)
#define  VODMA_VODMA_BIST_MODE_vodma_bist_mode_0_mask                            (0x00000001)
#define  VODMA_VODMA_BIST_MODE_vodma_bist_mode_2(data)                           (0x00000004&((data)<<2))
#define  VODMA_VODMA_BIST_MODE_vodma_bist_mode_1(data)                           (0x00000002&((data)<<1))
#define  VODMA_VODMA_BIST_MODE_vodma_bist_mode_0(data)                           (0x00000001&(data))
#define  VODMA_VODMA_BIST_MODE_get_vodma_bist_mode_2(data)                       ((0x00000004&(data))>>2)
#define  VODMA_VODMA_BIST_MODE_get_vodma_bist_mode_1(data)                       ((0x00000002&(data))>>1)
#define  VODMA_VODMA_BIST_MODE_get_vodma_bist_mode_0(data)                       (0x00000001&(data))

#define  VODMA_VODMA_BIST_DONE                                                   0x180051D4
#define  VODMA_VODMA_BIST_DONE_reg_addr                                          "0xB80051D4"
#define  VODMA_VODMA_BIST_DONE_reg                                               0xB80051D4
#define  VODMA_VODMA_BIST_DONE_inst_addr                                         "0x0041"
#define  set_VODMA_VODMA_BIST_DONE_reg(data)                                     (*((volatile unsigned int*)VODMA_VODMA_BIST_DONE_reg)=data)
#define  get_VODMA_VODMA_BIST_DONE_reg                                           (*((volatile unsigned int*)VODMA_VODMA_BIST_DONE_reg))
#define  VODMA_VODMA_BIST_DONE_vodma_bist_done_2_shift                           (2)
#define  VODMA_VODMA_BIST_DONE_vodma_bist_done_1_shift                           (1)
#define  VODMA_VODMA_BIST_DONE_vodma_bist_done_0_shift                           (0)
#define  VODMA_VODMA_BIST_DONE_vodma_bist_done_2_mask                            (0x00000004)
#define  VODMA_VODMA_BIST_DONE_vodma_bist_done_1_mask                            (0x00000002)
#define  VODMA_VODMA_BIST_DONE_vodma_bist_done_0_mask                            (0x00000001)
#define  VODMA_VODMA_BIST_DONE_vodma_bist_done_2(data)                           (0x00000004&((data)<<2))
#define  VODMA_VODMA_BIST_DONE_vodma_bist_done_1(data)                           (0x00000002&((data)<<1))
#define  VODMA_VODMA_BIST_DONE_vodma_bist_done_0(data)                           (0x00000001&(data))
#define  VODMA_VODMA_BIST_DONE_get_vodma_bist_done_2(data)                       ((0x00000004&(data))>>2)
#define  VODMA_VODMA_BIST_DONE_get_vodma_bist_done_1(data)                       ((0x00000002&(data))>>1)
#define  VODMA_VODMA_BIST_DONE_get_vodma_bist_done_0(data)                       (0x00000001&(data))

#define  VODMA_VODMA_BIST_FAIL_GROUP                                             0x180051D8
#define  VODMA_VODMA_BIST_FAIL_GROUP_reg_addr                                    "0xB80051D8"
#define  VODMA_VODMA_BIST_FAIL_GROUP_reg                                         0xB80051D8
#define  VODMA_VODMA_BIST_FAIL_GROUP_inst_addr                                   "0x0042"
#define  set_VODMA_VODMA_BIST_FAIL_GROUP_reg(data)                               (*((volatile unsigned int*)VODMA_VODMA_BIST_FAIL_GROUP_reg)=data)
#define  get_VODMA_VODMA_BIST_FAIL_GROUP_reg                                     (*((volatile unsigned int*)VODMA_VODMA_BIST_FAIL_GROUP_reg))
#define  VODMA_VODMA_BIST_FAIL_GROUP_vodma_bist_fail_group_shift                 (0)
#define  VODMA_VODMA_BIST_FAIL_GROUP_vodma_bist_fail_group_mask                  (0x00000001)
#define  VODMA_VODMA_BIST_FAIL_GROUP_vodma_bist_fail_group(data)                 (0x00000001&(data))
#define  VODMA_VODMA_BIST_FAIL_GROUP_get_vodma_bist_fail_group(data)             (0x00000001&(data))

#define  VODMA_VODMA_BIST_FAIL                                                   0x180051DC
#define  VODMA_VODMA_BIST_FAIL_reg_addr                                          "0xB80051DC"
#define  VODMA_VODMA_BIST_FAIL_reg                                               0xB80051DC
#define  VODMA_VODMA_BIST_FAIL_inst_addr                                         "0x0043"
#define  set_VODMA_VODMA_BIST_FAIL_reg(data)                                     (*((volatile unsigned int*)VODMA_VODMA_BIST_FAIL_reg)=data)
#define  get_VODMA_VODMA_BIST_FAIL_reg                                           (*((volatile unsigned int*)VODMA_VODMA_BIST_FAIL_reg))
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_5_shift                           (5)
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_4_shift                           (4)
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_3_shift                           (3)
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_2_shift                           (2)
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_1_shift                           (1)
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_0_shift                           (0)
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_5_mask                            (0x00000020)
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_4_mask                            (0x00000010)
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_3_mask                            (0x00000008)
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_2_mask                            (0x00000004)
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_1_mask                            (0x00000002)
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_0_mask                            (0x00000001)
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_5(data)                           (0x00000020&((data)<<5))
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_4(data)                           (0x00000010&((data)<<4))
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_3(data)                           (0x00000008&((data)<<3))
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_2(data)                           (0x00000004&((data)<<2))
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_1(data)                           (0x00000002&((data)<<1))
#define  VODMA_VODMA_BIST_FAIL_vodma_bist_fail_0(data)                           (0x00000001&(data))
#define  VODMA_VODMA_BIST_FAIL_get_vodma_bist_fail_5(data)                       ((0x00000020&(data))>>5)
#define  VODMA_VODMA_BIST_FAIL_get_vodma_bist_fail_4(data)                       ((0x00000010&(data))>>4)
#define  VODMA_VODMA_BIST_FAIL_get_vodma_bist_fail_3(data)                       ((0x00000008&(data))>>3)
#define  VODMA_VODMA_BIST_FAIL_get_vodma_bist_fail_2(data)                       ((0x00000004&(data))>>2)
#define  VODMA_VODMA_BIST_FAIL_get_vodma_bist_fail_1(data)                       ((0x00000002&(data))>>1)
#define  VODMA_VODMA_BIST_FAIL_get_vodma_bist_fail_0(data)                       (0x00000001&(data))

#define  VODMA_VODMA_DRF_MODE                                                    0x180051E0
#define  VODMA_VODMA_DRF_MODE_reg_addr                                           "0xB80051E0"
#define  VODMA_VODMA_DRF_MODE_reg                                                0xB80051E0
#define  VODMA_VODMA_DRF_MODE_inst_addr                                          "0x0044"
#define  set_VODMA_VODMA_DRF_MODE_reg(data)                                      (*((volatile unsigned int*)VODMA_VODMA_DRF_MODE_reg)=data)
#define  get_VODMA_VODMA_DRF_MODE_reg                                            (*((volatile unsigned int*)VODMA_VODMA_DRF_MODE_reg))
#define  VODMA_VODMA_DRF_MODE_vodma_drf_mode_2_shift                             (2)
#define  VODMA_VODMA_DRF_MODE_vodma_drf_mode_1_shift                             (1)
#define  VODMA_VODMA_DRF_MODE_vodma_drf_mode_0_shift                             (0)
#define  VODMA_VODMA_DRF_MODE_vodma_drf_mode_2_mask                              (0x00000004)
#define  VODMA_VODMA_DRF_MODE_vodma_drf_mode_1_mask                              (0x00000002)
#define  VODMA_VODMA_DRF_MODE_vodma_drf_mode_0_mask                              (0x00000001)
#define  VODMA_VODMA_DRF_MODE_vodma_drf_mode_2(data)                             (0x00000004&((data)<<2))
#define  VODMA_VODMA_DRF_MODE_vodma_drf_mode_1(data)                             (0x00000002&((data)<<1))
#define  VODMA_VODMA_DRF_MODE_vodma_drf_mode_0(data)                             (0x00000001&(data))
#define  VODMA_VODMA_DRF_MODE_get_vodma_drf_mode_2(data)                         ((0x00000004&(data))>>2)
#define  VODMA_VODMA_DRF_MODE_get_vodma_drf_mode_1(data)                         ((0x00000002&(data))>>1)
#define  VODMA_VODMA_DRF_MODE_get_vodma_drf_mode_0(data)                         (0x00000001&(data))

#define  VODMA_VODMA_DRF_RESUME                                                  0x180051E4
#define  VODMA_VODMA_DRF_RESUME_reg_addr                                         "0xB80051E4"
#define  VODMA_VODMA_DRF_RESUME_reg                                              0xB80051E4
#define  VODMA_VODMA_DRF_RESUME_inst_addr                                        "0x0045"
#define  set_VODMA_VODMA_DRF_RESUME_reg(data)                                    (*((volatile unsigned int*)VODMA_VODMA_DRF_RESUME_reg)=data)
#define  get_VODMA_VODMA_DRF_RESUME_reg                                          (*((volatile unsigned int*)VODMA_VODMA_DRF_RESUME_reg))
#define  VODMA_VODMA_DRF_RESUME_vodma_drf_resume_2_shift                         (2)
#define  VODMA_VODMA_DRF_RESUME_vodma_drf_resume_1_shift                         (1)
#define  VODMA_VODMA_DRF_RESUME_vodma_drf_resume_0_shift                         (0)
#define  VODMA_VODMA_DRF_RESUME_vodma_drf_resume_2_mask                          (0x00000004)
#define  VODMA_VODMA_DRF_RESUME_vodma_drf_resume_1_mask                          (0x00000002)
#define  VODMA_VODMA_DRF_RESUME_vodma_drf_resume_0_mask                          (0x00000001)
#define  VODMA_VODMA_DRF_RESUME_vodma_drf_resume_2(data)                         (0x00000004&((data)<<2))
#define  VODMA_VODMA_DRF_RESUME_vodma_drf_resume_1(data)                         (0x00000002&((data)<<1))
#define  VODMA_VODMA_DRF_RESUME_vodma_drf_resume_0(data)                         (0x00000001&(data))
#define  VODMA_VODMA_DRF_RESUME_get_vodma_drf_resume_2(data)                     ((0x00000004&(data))>>2)
#define  VODMA_VODMA_DRF_RESUME_get_vodma_drf_resume_1(data)                     ((0x00000002&(data))>>1)
#define  VODMA_VODMA_DRF_RESUME_get_vodma_drf_resume_0(data)                     (0x00000001&(data))

#define  VODMA_VODMA_DRF_DONE                                                    0x180051E8
#define  VODMA_VODMA_DRF_DONE_reg_addr                                           "0xB80051E8"
#define  VODMA_VODMA_DRF_DONE_reg                                                0xB80051E8
#define  VODMA_VODMA_DRF_DONE_inst_addr                                          "0x0046"
#define  set_VODMA_VODMA_DRF_DONE_reg(data)                                      (*((volatile unsigned int*)VODMA_VODMA_DRF_DONE_reg)=data)
#define  get_VODMA_VODMA_DRF_DONE_reg                                            (*((volatile unsigned int*)VODMA_VODMA_DRF_DONE_reg))
#define  VODMA_VODMA_DRF_DONE_vodma_drf_done_2_shift                             (2)
#define  VODMA_VODMA_DRF_DONE_vodma_drf_done_1_shift                             (1)
#define  VODMA_VODMA_DRF_DONE_vodma_drf_done_0_shift                             (0)
#define  VODMA_VODMA_DRF_DONE_vodma_drf_done_2_mask                              (0x00000004)
#define  VODMA_VODMA_DRF_DONE_vodma_drf_done_1_mask                              (0x00000002)
#define  VODMA_VODMA_DRF_DONE_vodma_drf_done_0_mask                              (0x00000001)
#define  VODMA_VODMA_DRF_DONE_vodma_drf_done_2(data)                             (0x00000004&((data)<<2))
#define  VODMA_VODMA_DRF_DONE_vodma_drf_done_1(data)                             (0x00000002&((data)<<1))
#define  VODMA_VODMA_DRF_DONE_vodma_drf_done_0(data)                             (0x00000001&(data))
#define  VODMA_VODMA_DRF_DONE_get_vodma_drf_done_2(data)                         ((0x00000004&(data))>>2)
#define  VODMA_VODMA_DRF_DONE_get_vodma_drf_done_1(data)                         ((0x00000002&(data))>>1)
#define  VODMA_VODMA_DRF_DONE_get_vodma_drf_done_0(data)                         (0x00000001&(data))

#define  VODMA_VODMA_DRF_PAUSE                                                   0x180051EC
#define  VODMA_VODMA_DRF_PAUSE_reg_addr                                          "0xB80051EC"
#define  VODMA_VODMA_DRF_PAUSE_reg                                               0xB80051EC
#define  VODMA_VODMA_DRF_PAUSE_inst_addr                                         "0x0047"
#define  set_VODMA_VODMA_DRF_PAUSE_reg(data)                                     (*((volatile unsigned int*)VODMA_VODMA_DRF_PAUSE_reg)=data)
#define  get_VODMA_VODMA_DRF_PAUSE_reg                                           (*((volatile unsigned int*)VODMA_VODMA_DRF_PAUSE_reg))
#define  VODMA_VODMA_DRF_PAUSE_vodma_drf_pause_2_shift                           (2)
#define  VODMA_VODMA_DRF_PAUSE_vodma_drf_pause_1_shift                           (1)
#define  VODMA_VODMA_DRF_PAUSE_vodma_drf_pause_0_shift                           (0)
#define  VODMA_VODMA_DRF_PAUSE_vodma_drf_pause_2_mask                            (0x00000004)
#define  VODMA_VODMA_DRF_PAUSE_vodma_drf_pause_1_mask                            (0x00000002)
#define  VODMA_VODMA_DRF_PAUSE_vodma_drf_pause_0_mask                            (0x00000001)
#define  VODMA_VODMA_DRF_PAUSE_vodma_drf_pause_2(data)                           (0x00000004&((data)<<2))
#define  VODMA_VODMA_DRF_PAUSE_vodma_drf_pause_1(data)                           (0x00000002&((data)<<1))
#define  VODMA_VODMA_DRF_PAUSE_vodma_drf_pause_0(data)                           (0x00000001&(data))
#define  VODMA_VODMA_DRF_PAUSE_get_vodma_drf_pause_2(data)                       ((0x00000004&(data))>>2)
#define  VODMA_VODMA_DRF_PAUSE_get_vodma_drf_pause_1(data)                       ((0x00000002&(data))>>1)
#define  VODMA_VODMA_DRF_PAUSE_get_vodma_drf_pause_0(data)                       (0x00000001&(data))

#define  VODMA_VODMA_DRF_FAIL_GROUP                                              0x180051F0
#define  VODMA_VODMA_DRF_FAIL_GROUP_reg_addr                                     "0xB80051F0"
#define  VODMA_VODMA_DRF_FAIL_GROUP_reg                                          0xB80051F0
#define  VODMA_VODMA_DRF_FAIL_GROUP_inst_addr                                    "0x0048"
#define  set_VODMA_VODMA_DRF_FAIL_GROUP_reg(data)                                (*((volatile unsigned int*)VODMA_VODMA_DRF_FAIL_GROUP_reg)=data)
#define  get_VODMA_VODMA_DRF_FAIL_GROUP_reg                                      (*((volatile unsigned int*)VODMA_VODMA_DRF_FAIL_GROUP_reg))
#define  VODMA_VODMA_DRF_FAIL_GROUP_vodma_drf_fail_group_shift                   (0)
#define  VODMA_VODMA_DRF_FAIL_GROUP_vodma_drf_fail_group_mask                    (0x00000001)
#define  VODMA_VODMA_DRF_FAIL_GROUP_vodma_drf_fail_group(data)                   (0x00000001&(data))
#define  VODMA_VODMA_DRF_FAIL_GROUP_get_vodma_drf_fail_group(data)               (0x00000001&(data))

#define  VODMA_VODMA_DRF_FAIL                                                    0x180051F4
#define  VODMA_VODMA_DRF_FAIL_reg_addr                                           "0xB80051F4"
#define  VODMA_VODMA_DRF_FAIL_reg                                                0xB80051F4
#define  VODMA_VODMA_DRF_FAIL_inst_addr                                          "0x0049"
#define  set_VODMA_VODMA_DRF_FAIL_reg(data)                                      (*((volatile unsigned int*)VODMA_VODMA_DRF_FAIL_reg)=data)
#define  get_VODMA_VODMA_DRF_FAIL_reg                                            (*((volatile unsigned int*)VODMA_VODMA_DRF_FAIL_reg))
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_5_shift                             (5)
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_4_shift                             (4)
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_3_shift                             (3)
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_2_shift                             (2)
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_1_shift                             (1)
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_0_shift                             (0)
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_5_mask                              (0x00000020)
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_4_mask                              (0x00000010)
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_3_mask                              (0x00000008)
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_2_mask                              (0x00000004)
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_1_mask                              (0x00000002)
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_0_mask                              (0x00000001)
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_5(data)                             (0x00000020&((data)<<5))
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_4(data)                             (0x00000010&((data)<<4))
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_3(data)                             (0x00000008&((data)<<3))
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_2(data)                             (0x00000004&((data)<<2))
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_1(data)                             (0x00000002&((data)<<1))
#define  VODMA_VODMA_DRF_FAIL_vodma_drf_fail_0(data)                             (0x00000001&(data))
#define  VODMA_VODMA_DRF_FAIL_get_vodma_drf_fail_5(data)                         ((0x00000020&(data))>>5)
#define  VODMA_VODMA_DRF_FAIL_get_vodma_drf_fail_4(data)                         ((0x00000010&(data))>>4)
#define  VODMA_VODMA_DRF_FAIL_get_vodma_drf_fail_3(data)                         ((0x00000008&(data))>>3)
#define  VODMA_VODMA_DRF_FAIL_get_vodma_drf_fail_2(data)                         ((0x00000004&(data))>>2)
#define  VODMA_VODMA_DRF_FAIL_get_vodma_drf_fail_1(data)                         ((0x00000002&(data))>>1)
#define  VODMA_VODMA_DRF_FAIL_get_vodma_drf_fail_0(data)                         (0x00000001&(data))

#define  VODMA_VODMA_BIST_OTHER                                                  0x180051F8
#define  VODMA_VODMA_BIST_OTHER_reg_addr                                         "0xB80051F8"
#define  VODMA_VODMA_BIST_OTHER_reg                                              0xB80051F8
#define  VODMA_VODMA_BIST_OTHER_inst_addr                                        "0x004A"
#define  set_VODMA_VODMA_BIST_OTHER_reg(data)                                    (*((volatile unsigned int*)VODMA_VODMA_BIST_OTHER_reg)=data)
#define  get_VODMA_VODMA_BIST_OTHER_reg                                          (*((volatile unsigned int*)VODMA_VODMA_BIST_OTHER_reg))
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_ls_2_shift                            (22)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rm_2_shift                            (18)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rme_2_shift                           (17)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rst_n_2_shift                         (16)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_ls_1_shift                            (14)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rm_1_shift                            (10)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rme_1_shift                           (9)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rst_n_1_shift                         (8)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_ls_0_shift                            (6)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rm_0_shift                            (2)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rme_0_shift                           (1)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rst_n_0_shift                         (0)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_ls_2_mask                             (0x00400000)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rm_2_mask                             (0x003C0000)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rme_2_mask                            (0x00020000)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rst_n_2_mask                          (0x00010000)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_ls_1_mask                             (0x00004000)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rm_1_mask                             (0x00003C00)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rme_1_mask                            (0x00000200)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rst_n_1_mask                          (0x00000100)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_ls_0_mask                             (0x00000040)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rm_0_mask                             (0x0000003C)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rme_0_mask                            (0x00000002)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rst_n_0_mask                          (0x00000001)
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_ls_2(data)                            (0x00400000&((data)<<22))
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rm_2(data)                            (0x003C0000&((data)<<18))
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rme_2(data)                           (0x00020000&((data)<<17))
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rst_n_2(data)                         (0x00010000&((data)<<16))
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_ls_1(data)                            (0x00004000&((data)<<14))
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rm_1(data)                            (0x00003C00&((data)<<10))
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rme_1(data)                           (0x00000200&((data)<<9))
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rst_n_1(data)                         (0x00000100&((data)<<8))
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_ls_0(data)                            (0x00000040&((data)<<6))
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rm_0(data)                            (0x0000003C&((data)<<2))
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rme_0(data)                           (0x00000002&((data)<<1))
#define  VODMA_VODMA_BIST_OTHER_vodma_bist_rst_n_0(data)                         (0x00000001&(data))
#define  VODMA_VODMA_BIST_OTHER_get_vodma_bist_ls_2(data)                        ((0x00400000&(data))>>22)
#define  VODMA_VODMA_BIST_OTHER_get_vodma_bist_rm_2(data)                        ((0x003C0000&(data))>>18)
#define  VODMA_VODMA_BIST_OTHER_get_vodma_bist_rme_2(data)                       ((0x00020000&(data))>>17)
#define  VODMA_VODMA_BIST_OTHER_get_vodma_bist_rst_n_2(data)                     ((0x00010000&(data))>>16)
#define  VODMA_VODMA_BIST_OTHER_get_vodma_bist_ls_1(data)                        ((0x00004000&(data))>>14)
#define  VODMA_VODMA_BIST_OTHER_get_vodma_bist_rm_1(data)                        ((0x00003C00&(data))>>10)
#define  VODMA_VODMA_BIST_OTHER_get_vodma_bist_rme_1(data)                       ((0x00000200&(data))>>9)
#define  VODMA_VODMA_BIST_OTHER_get_vodma_bist_rst_n_1(data)                     ((0x00000100&(data))>>8)
#define  VODMA_VODMA_BIST_OTHER_get_vodma_bist_ls_0(data)                        ((0x00000040&(data))>>6)
#define  VODMA_VODMA_BIST_OTHER_get_vodma_bist_rm_0(data)                        ((0x0000003C&(data))>>2)
#define  VODMA_VODMA_BIST_OTHER_get_vodma_bist_rme_0(data)                       ((0x00000002&(data))>>1)
#define  VODMA_VODMA_BIST_OTHER_get_vodma_bist_rst_n_0(data)                     (0x00000001&(data))

#define  VODMA_VODMA_DBG                                                         0x180051FC
#define  VODMA_VODMA_DBG_reg_addr                                                "0xB80051FC"
#define  VODMA_VODMA_DBG_reg                                                     0xB80051FC
#define  VODMA_VODMA_DBG_inst_addr                                               "0x004B"
#define  set_VODMA_VODMA_DBG_reg(data)                                           (*((volatile unsigned int*)VODMA_VODMA_DBG_reg)=data)
#define  get_VODMA_VODMA_DBG_reg                                                 (*((volatile unsigned int*)VODMA_VODMA_DBG_reg))
#define  VODMA_VODMA_DBG_sel_shift                                               (0)
#define  VODMA_VODMA_DBG_sel_mask                                                (0x0000001F)
#define  VODMA_VODMA_DBG_sel(data)                                               (0x0000001F&(data))
#define  VODMA_VODMA_DBG_get_sel(data)                                           (0x0000001F&(data))

#define  VODMA_VODMA_3D_CS_1                                                     0x180050C4
#define  VODMA_VODMA_3D_CS_1_reg_addr                                            "0xB80050C4"
#define  VODMA_VODMA_3D_CS_1_reg                                                 0xB80050C4
#define  VODMA_VODMA_3D_CS_1_inst_addr                                           "0x004C"
#define  set_VODMA_VODMA_3D_CS_1_reg(data)                                       (*((volatile unsigned int*)VODMA_VODMA_3D_CS_1_reg)=data)
#define  get_VODMA_VODMA_3D_CS_1_reg                                             (*((volatile unsigned int*)VODMA_VODMA_3D_CS_1_reg))
#define  VODMA_VODMA_3D_CS_1_vodma_actv_shift                                    (4)
#define  VODMA_VODMA_3D_CS_1_cur_block_sel_shift                                 (0)
#define  VODMA_VODMA_3D_CS_1_vodma_actv_mask                                     (0x00000010)
#define  VODMA_VODMA_3D_CS_1_cur_block_sel_mask                                  (0x00000003)
#define  VODMA_VODMA_3D_CS_1_vodma_actv(data)                                    (0x00000010&((data)<<4))
#define  VODMA_VODMA_3D_CS_1_cur_block_sel(data)                                 (0x00000003&(data))
#define  VODMA_VODMA_3D_CS_1_get_vodma_actv(data)                                ((0x00000010&(data))>>4)
#define  VODMA_VODMA_3D_CS_1_get_cur_block_sel(data)                             (0x00000003&(data))

#define  VODMA_VODMA_3D_CS_2                                                     0x180050C8
#define  VODMA_VODMA_3D_CS_2_reg_addr                                            "0xB80050C8"
#define  VODMA_VODMA_3D_CS_2_reg                                                 0xB80050C8
#define  VODMA_VODMA_3D_CS_2_inst_addr                                           "0x004D"
#define  set_VODMA_VODMA_3D_CS_2_reg(data)                                       (*((volatile unsigned int*)VODMA_VODMA_3D_CS_2_reg)=data)
#define  get_VODMA_VODMA_3D_CS_2_reg                                             (*((volatile unsigned int*)VODMA_VODMA_3D_CS_2_reg))
#define  VODMA_VODMA_3D_CS_2_cur_st_adr_shift                                    (3)
#define  VODMA_VODMA_3D_CS_2_cur_st_adr_mask                                     (0xFFFFFFF8)
#define  VODMA_VODMA_3D_CS_2_cur_st_adr(data)                                    (0xFFFFFFF8&((data)<<3))
#define  VODMA_VODMA_3D_CS_2_get_cur_st_adr(data)                                ((0xFFFFFFF8&(data))>>3)

#define  VODMA_VODMA_quincunx_setting                                            0x180050D0
#define  VODMA_VODMA_quincunx_setting_reg_addr                                   "0xB80050D0"
#define  VODMA_VODMA_quincunx_setting_reg                                        0xB80050D0
#define  VODMA_VODMA_quincunx_setting_inst_addr                                  "0x004E"
#define  set_VODMA_VODMA_quincunx_setting_reg(data)                              (*((volatile unsigned int*)VODMA_VODMA_quincunx_setting_reg)=data)
#define  get_VODMA_VODMA_quincunx_setting_reg                                    (*((volatile unsigned int*)VODMA_VODMA_quincunx_setting_reg))
#define  VODMA_VODMA_quincunx_setting_dummy_31_11_shift                          (11)
#define  VODMA_VODMA_quincunx_setting_dummy_10_shift                             (10)
#define  VODMA_VODMA_quincunx_setting_hori_drop_mode_shift                       (9)
#define  VODMA_VODMA_quincunx_setting_hori_drop_en_shift                         (8)
#define  VODMA_VODMA_quincunx_setting_quincunx_mode_src_sel_shift                (7)
#define  VODMA_VODMA_quincunx_setting_quincunx_int_mode_shift                    (5)
#define  VODMA_VODMA_quincunx_setting_quincunx_int_en_shift                      (4)
#define  VODMA_VODMA_quincunx_setting_quincunx_mode_fw_shift                     (0)
#define  VODMA_VODMA_quincunx_setting_dummy_31_11_mask                           (0xFFFFF800)
#define  VODMA_VODMA_quincunx_setting_dummy_10_mask                              (0x00000400)
#define  VODMA_VODMA_quincunx_setting_hori_drop_mode_mask                        (0x00000200)
#define  VODMA_VODMA_quincunx_setting_hori_drop_en_mask                          (0x00000100)
#define  VODMA_VODMA_quincunx_setting_quincunx_mode_src_sel_mask                 (0x00000080)
#define  VODMA_VODMA_quincunx_setting_quincunx_int_mode_mask                     (0x00000060)
#define  VODMA_VODMA_quincunx_setting_quincunx_int_en_mask                       (0x00000010)
#define  VODMA_VODMA_quincunx_setting_quincunx_mode_fw_mask                      (0x0000000F)
#define  VODMA_VODMA_quincunx_setting_dummy_31_11(data)                          (0xFFFFF800&((data)<<11))
#define  VODMA_VODMA_quincunx_setting_dummy_10(data)                             (0x00000400&((data)<<10))
#define  VODMA_VODMA_quincunx_setting_hori_drop_mode(data)                       (0x00000200&((data)<<9))
#define  VODMA_VODMA_quincunx_setting_hori_drop_en(data)                         (0x00000100&((data)<<8))
#define  VODMA_VODMA_quincunx_setting_quincunx_mode_src_sel(data)                (0x00000080&((data)<<7))
#define  VODMA_VODMA_quincunx_setting_quincunx_int_mode(data)                    (0x00000060&((data)<<5))
#define  VODMA_VODMA_quincunx_setting_quincunx_int_en(data)                      (0x00000010&((data)<<4))
#define  VODMA_VODMA_quincunx_setting_quincunx_mode_fw(data)                     (0x0000000F&(data))
#define  VODMA_VODMA_quincunx_setting_get_dummy_31_11(data)                      ((0xFFFFF800&(data))>>11)
#define  VODMA_VODMA_quincunx_setting_get_dummy_10(data)                         ((0x00000400&(data))>>10)
#define  VODMA_VODMA_quincunx_setting_get_hori_drop_mode(data)                   ((0x00000200&(data))>>9)
#define  VODMA_VODMA_quincunx_setting_get_hori_drop_en(data)                     ((0x00000100&(data))>>8)
#define  VODMA_VODMA_quincunx_setting_get_quincunx_mode_src_sel(data)            ((0x00000080&(data))>>7)
#define  VODMA_VODMA_quincunx_setting_get_quincunx_int_mode(data)                ((0x00000060&(data))>>5)
#define  VODMA_VODMA_quincunx_setting_get_quincunx_int_en(data)                  ((0x00000010&(data))>>4)
#define  VODMA_VODMA_quincunx_setting_get_quincunx_mode_fw(data)                 (0x0000000F&(data))

#define  VODMA_VODMA_quincunx_status                                             0x180050D4
#define  VODMA_VODMA_quincunx_status_reg_addr                                    "0xB80050D4"
#define  VODMA_VODMA_quincunx_status_reg                                         0xB80050D4
#define  VODMA_VODMA_quincunx_status_inst_addr                                   "0x004F"
#define  set_VODMA_VODMA_quincunx_status_reg(data)                               (*((volatile unsigned int*)VODMA_VODMA_quincunx_status_reg)=data)
#define  get_VODMA_VODMA_quincunx_status_reg                                     (*((volatile unsigned int*)VODMA_VODMA_quincunx_status_reg))
#define  VODMA_VODMA_quincunx_status_quincunx_mode_b0_shift                      (4)
#define  VODMA_VODMA_quincunx_status_quincunx_mode_b1_shift                      (0)
#define  VODMA_VODMA_quincunx_status_quincunx_mode_b0_mask                       (0x000000F0)
#define  VODMA_VODMA_quincunx_status_quincunx_mode_b1_mask                       (0x0000000F)
#define  VODMA_VODMA_quincunx_status_quincunx_mode_b0(data)                      (0x000000F0&((data)<<4))
#define  VODMA_VODMA_quincunx_status_quincunx_mode_b1(data)                      (0x0000000F&(data))
#define  VODMA_VODMA_quincunx_status_get_quincunx_mode_b0(data)                  ((0x000000F0&(data))>>4)
#define  VODMA_VODMA_quincunx_status_get_quincunx_mode_b1(data)                  (0x0000000F&(data))

#define  VODMA_VODMA_SMOOTH_TOGGLE_1                                             0x180050D8
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_reg_addr                                    "0xB80050D8"
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_reg                                         0xB80050D8
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_inst_addr                                   "0x0050"
#define  set_VODMA_VODMA_SMOOTH_TOGGLE_1_reg(data)                               (*((volatile unsigned int*)VODMA_VODMA_SMOOTH_TOGGLE_1_reg)=data)
#define  get_VODMA_VODMA_SMOOTH_TOGGLE_1_reg                                     (*((volatile unsigned int*)VODMA_VODMA_SMOOTH_TOGGLE_1_reg))
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_gate_period_shift                           (29)
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_smooth_en_shift                             (28)
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_vcnt_pre_num_shift                          (0)
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_gate_period_mask                            (0xE0000000)
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_smooth_en_mask                              (0x10000000)
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_vcnt_pre_num_mask                           (0x0FFFFFFF)
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_gate_period(data)                           (0xE0000000&((data)<<29))
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_smooth_en(data)                             (0x10000000&((data)<<28))
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_vcnt_pre_num(data)                          (0x0FFFFFFF&(data))
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_get_gate_period(data)                       ((0xE0000000&(data))>>29)
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_get_smooth_en(data)                         ((0x10000000&(data))>>28)
#define  VODMA_VODMA_SMOOTH_TOGGLE_1_get_vcnt_pre_num(data)                      (0x0FFFFFFF&(data))

#define  VODMA_VODMA_dma_option                                                  0x180050DC
#define  VODMA_VODMA_dma_option_reg_addr                                         "0xB80050DC"
#define  VODMA_VODMA_dma_option_reg                                              0xB80050DC
#define  VODMA_VODMA_dma_option_inst_addr                                        "0x0051"
#define  set_VODMA_VODMA_dma_option_reg(data)                                    (*((volatile unsigned int*)VODMA_VODMA_dma_option_reg)=data)
#define  get_VODMA_VODMA_dma_option_reg                                          (*((volatile unsigned int*)VODMA_VODMA_dma_option_reg))
#define  VODMA_VODMA_dma_option_mrs_mode_shift                                   (31)
#define  VODMA_VODMA_dma_option_max_mrs_num_shift                                (28)
#define  VODMA_VODMA_dma_option_blockmode_sel_c_shift                            (5)
#define  VODMA_VODMA_dma_option_burst_len_shift                                  (4)
#define  VODMA_VODMA_dma_option_block_burst_len_shift                            (3)
#define  VODMA_VODMA_dma_option_blockmode_sel_y_shift                            (1)
#define  VODMA_VODMA_dma_option_cmd_trans_en_shift                               (0)
#define  VODMA_VODMA_dma_option_mrs_mode_mask                                    (0x80000000)
#define  VODMA_VODMA_dma_option_max_mrs_num_mask                                 (0x70000000)
#define  VODMA_VODMA_dma_option_blockmode_sel_c_mask                             (0x00000060)
#define  VODMA_VODMA_dma_option_burst_len_mask                                   (0x00000010)
#define  VODMA_VODMA_dma_option_block_burst_len_mask                             (0x00000008)
#define  VODMA_VODMA_dma_option_blockmode_sel_y_mask                             (0x00000006)
#define  VODMA_VODMA_dma_option_cmd_trans_en_mask                                (0x00000001)
#define  VODMA_VODMA_dma_option_mrs_mode(data)                                   (0x80000000&((data)<<31))
#define  VODMA_VODMA_dma_option_max_mrs_num(data)                                (0x70000000&((data)<<28))
#define  VODMA_VODMA_dma_option_blockmode_sel_c(data)                            (0x00000060&((data)<<5))
#define  VODMA_VODMA_dma_option_burst_len(data)                                  (0x00000010&((data)<<4))
#define  VODMA_VODMA_dma_option_block_burst_len(data)                            (0x00000008&((data)<<3))
#define  VODMA_VODMA_dma_option_blockmode_sel_y(data)                            (0x00000006&((data)<<1))
#define  VODMA_VODMA_dma_option_cmd_trans_en(data)                               (0x00000001&(data))
#define  VODMA_VODMA_dma_option_get_mrs_mode(data)                               ((0x80000000&(data))>>31)
#define  VODMA_VODMA_dma_option_get_max_mrs_num(data)                            ((0x70000000&(data))>>28)
#define  VODMA_VODMA_dma_option_get_blockmode_sel_c(data)                        ((0x00000060&(data))>>5)
#define  VODMA_VODMA_dma_option_get_burst_len(data)                              ((0x00000010&(data))>>4)
#define  VODMA_VODMA_dma_option_get_block_burst_len(data)                        ((0x00000008&(data))>>3)
#define  VODMA_VODMA_dma_option_get_blockmode_sel_y(data)                        ((0x00000006&(data))>>1)
#define  VODMA_VODMA_dma_option_get_cmd_trans_en(data)                           (0x00000001&(data))

#define  VODMA_VODMA_PVS0_Gen                                                    0x18005300
#define  VODMA_VODMA_PVS0_Gen_reg_addr                                           "0xB8005300"
#define  VODMA_VODMA_PVS0_Gen_reg                                                0xB8005300
#define  VODMA_VODMA_PVS0_Gen_inst_addr                                          "0x0052"
#define  set_VODMA_VODMA_PVS0_Gen_reg(data)                                      (*((volatile unsigned int*)VODMA_VODMA_PVS0_Gen_reg)=data)
#define  get_VODMA_VODMA_PVS0_Gen_reg                                            (*((volatile unsigned int*)VODMA_VODMA_PVS0_Gen_reg))
#define  VODMA_VODMA_PVS0_Gen_en_pvgen_shift                                     (31)
#define  VODMA_VODMA_PVS0_Gen_en_pfgen_shift                                     (30)
#define  VODMA_VODMA_PVS0_Gen_pfgen_inv_shift                                    (29)
#define  VODMA_VODMA_PVS0_Gen_iv_inv_en_shift                                    (27)
#define  VODMA_VODMA_PVS0_Gen_iv_src_sel_shift                                   (24)
#define  VODMA_VODMA_PVS0_Gen_iv2pv_dly_shift                                    (0)
#define  VODMA_VODMA_PVS0_Gen_en_pvgen_mask                                      (0x80000000)
#define  VODMA_VODMA_PVS0_Gen_en_pfgen_mask                                      (0x40000000)
#define  VODMA_VODMA_PVS0_Gen_pfgen_inv_mask                                     (0x20000000)
#define  VODMA_VODMA_PVS0_Gen_iv_inv_en_mask                                     (0x08000000)
#define  VODMA_VODMA_PVS0_Gen_iv_src_sel_mask                                    (0x07000000)
#define  VODMA_VODMA_PVS0_Gen_iv2pv_dly_mask                                     (0x00FFFFFF)
#define  VODMA_VODMA_PVS0_Gen_en_pvgen(data)                                     (0x80000000&((data)<<31))
#define  VODMA_VODMA_PVS0_Gen_en_pfgen(data)                                     (0x40000000&((data)<<30))
#define  VODMA_VODMA_PVS0_Gen_pfgen_inv(data)                                    (0x20000000&((data)<<29))
#define  VODMA_VODMA_PVS0_Gen_iv_inv_en(data)                                    (0x08000000&((data)<<27))
#define  VODMA_VODMA_PVS0_Gen_iv_src_sel(data)                                   (0x07000000&((data)<<24))
#define  VODMA_VODMA_PVS0_Gen_iv2pv_dly(data)                                    (0x00FFFFFF&(data))
#define  VODMA_VODMA_PVS0_Gen_get_en_pvgen(data)                                 ((0x80000000&(data))>>31)
#define  VODMA_VODMA_PVS0_Gen_get_en_pfgen(data)                                 ((0x40000000&(data))>>30)
#define  VODMA_VODMA_PVS0_Gen_get_pfgen_inv(data)                                ((0x20000000&(data))>>29)
#define  VODMA_VODMA_PVS0_Gen_get_iv_inv_en(data)                                ((0x08000000&(data))>>27)
#define  VODMA_VODMA_PVS0_Gen_get_iv_src_sel(data)                               ((0x07000000&(data))>>24)
#define  VODMA_VODMA_PVS0_Gen_get_iv2pv_dly(data)                                (0x00FFFFFF&(data))

#define  VODMA_VODMA_PVS_Free                                                    0x18005304
#define  VODMA_VODMA_PVS_Free_reg_addr                                           "0xB8005304"
#define  VODMA_VODMA_PVS_Free_reg                                                0xB8005304
#define  VODMA_VODMA_PVS_Free_inst_addr                                          "0x0053"
#define  set_VODMA_VODMA_PVS_Free_reg(data)                                      (*((volatile unsigned int*)VODMA_VODMA_PVS_Free_reg)=data)
#define  get_VODMA_VODMA_PVS_Free_reg                                            (*((volatile unsigned int*)VODMA_VODMA_PVS_Free_reg))
#define  VODMA_VODMA_PVS_Free_pvs0_free_en_shift                                 (31)
#define  VODMA_VODMA_PVS_Free_pvs0_free_vs_reset_en_shift                        (29)
#define  VODMA_VODMA_PVS_Free_pvs0_free_period_update_shift                      (28)
#define  VODMA_VODMA_PVS_Free_pvs0_free_period_shift                             (0)
#define  VODMA_VODMA_PVS_Free_pvs0_free_en_mask                                  (0x80000000)
#define  VODMA_VODMA_PVS_Free_pvs0_free_vs_reset_en_mask                         (0x20000000)
#define  VODMA_VODMA_PVS_Free_pvs0_free_period_update_mask                       (0x10000000)
#define  VODMA_VODMA_PVS_Free_pvs0_free_period_mask                              (0x0FFFFFFF)
#define  VODMA_VODMA_PVS_Free_pvs0_free_en(data)                                 (0x80000000&((data)<<31))
#define  VODMA_VODMA_PVS_Free_pvs0_free_vs_reset_en(data)                        (0x20000000&((data)<<29))
#define  VODMA_VODMA_PVS_Free_pvs0_free_period_update(data)                      (0x10000000&((data)<<28))
#define  VODMA_VODMA_PVS_Free_pvs0_free_period(data)                             (0x0FFFFFFF&(data))
#define  VODMA_VODMA_PVS_Free_get_pvs0_free_en(data)                             ((0x80000000&(data))>>31)
#define  VODMA_VODMA_PVS_Free_get_pvs0_free_vs_reset_en(data)                    ((0x20000000&(data))>>29)
#define  VODMA_VODMA_PVS_Free_get_pvs0_free_period_update(data)                  ((0x10000000&(data))>>28)
#define  VODMA_VODMA_PVS_Free_get_pvs0_free_period(data)                         (0x0FFFFFFF&(data))

#define  VODMA_VODMA_PVS_CTRL                                                    0x18005308
#define  VODMA_VODMA_PVS_CTRL_reg_addr                                           "0xB8005308"
#define  VODMA_VODMA_PVS_CTRL_reg                                                0xB8005308
#define  VODMA_VODMA_PVS_CTRL_inst_addr                                          "0x0054"
#define  set_VODMA_VODMA_PVS_CTRL_reg(data)                                      (*((volatile unsigned int*)VODMA_VODMA_PVS_CTRL_reg)=data)
#define  get_VODMA_VODMA_PVS_CTRL_reg                                            (*((volatile unsigned int*)VODMA_VODMA_PVS_CTRL_reg))
#define  VODMA_VODMA_PVS_CTRL_pvs0_free_clk_sel_shift                            (30)
#define  VODMA_VODMA_PVS_CTRL_dummy_29_11_shift                                  (11)
#define  VODMA_VODMA_PVS_CTRL_pvs0_free_vs_sel_shift                             (8)
#define  VODMA_VODMA_PVS_CTRL_pvs0_free_l_flag_en_shift                          (4)
#define  VODMA_VODMA_PVS_CTRL_pvs0_free_vs_inv_en_shift                          (3)
#define  VODMA_VODMA_PVS_CTRL_mask_one_vs_shift                                  (0)
#define  VODMA_VODMA_PVS_CTRL_pvs0_free_clk_sel_mask                             (0xC0000000)
#define  VODMA_VODMA_PVS_CTRL_dummy_29_11_mask                                   (0x3FFFF800)
#define  VODMA_VODMA_PVS_CTRL_pvs0_free_vs_sel_mask                              (0x00000700)
#define  VODMA_VODMA_PVS_CTRL_pvs0_free_l_flag_en_mask                           (0x00000010)
#define  VODMA_VODMA_PVS_CTRL_pvs0_free_vs_inv_en_mask                           (0x00000008)
#define  VODMA_VODMA_PVS_CTRL_mask_one_vs_mask                                   (0x00000001)
#define  VODMA_VODMA_PVS_CTRL_pvs0_free_clk_sel(data)                            (0xC0000000&((data)<<30))
#define  VODMA_VODMA_PVS_CTRL_dummy_29_11(data)                                  (0x3FFFF800&((data)<<11))
#define  VODMA_VODMA_PVS_CTRL_pvs0_free_vs_sel(data)                             (0x00000700&((data)<<8))
#define  VODMA_VODMA_PVS_CTRL_pvs0_free_l_flag_en(data)                          (0x00000010&((data)<<4))
#define  VODMA_VODMA_PVS_CTRL_pvs0_free_vs_inv_en(data)                          (0x00000008&((data)<<3))
#define  VODMA_VODMA_PVS_CTRL_mask_one_vs(data)                                  (0x00000001&(data))
#define  VODMA_VODMA_PVS_CTRL_get_pvs0_free_clk_sel(data)                        ((0xC0000000&(data))>>30)
#define  VODMA_VODMA_PVS_CTRL_get_dummy_29_11(data)                              ((0x3FFFF800&(data))>>11)
#define  VODMA_VODMA_PVS_CTRL_get_pvs0_free_vs_sel(data)                         ((0x00000700&(data))>>8)
#define  VODMA_VODMA_PVS_CTRL_get_pvs0_free_l_flag_en(data)                      ((0x00000010&(data))>>4)
#define  VODMA_VODMA_PVS_CTRL_get_pvs0_free_vs_inv_en(data)                      ((0x00000008&(data))>>3)
#define  VODMA_VODMA_PVS_CTRL_get_mask_one_vs(data)                              (0x00000001&(data))

#define  VODMA_VODMA_CLKGEN                                                      0x18005310
#define  VODMA_VODMA_CLKGEN_reg_addr                                             "0xB8005310"
#define  VODMA_VODMA_CLKGEN_reg                                                  0xB8005310
#define  VODMA_VODMA_CLKGEN_inst_addr                                            "0x0055"
#define  set_VODMA_VODMA_CLKGEN_reg(data)                                        (*((volatile unsigned int*)VODMA_VODMA_CLKGEN_reg)=data)
#define  get_VODMA_VODMA_CLKGEN_reg                                              (*((volatile unsigned int*)VODMA_VODMA_CLKGEN_reg))
#define  VODMA_VODMA_CLKGEN_vodma_enclk_shift                                    (31)
#define  VODMA_VODMA_CLKGEN_vodma_clk_div2_en_src_sel_shift                      (29)
#define  VODMA_VODMA_CLKGEN_vodma_clk_div2_en_shift                              (28)
#define  VODMA_VODMA_CLKGEN_vodma_clk_div_n_shift                                (23)
#define  VODMA_VODMA_CLKGEN_vodma_clk_ratio_n_off_shift                          (16)
#define  VODMA_VODMA_CLKGEN_dummy_15_7_shift                                     (7)
#define  VODMA_VODMA_CLKGEN_vodma_clk_sel_shift                                  (4)
#define  VODMA_VODMA_CLKGEN_en_fifo_empty_gate_shift                             (3)
#define  VODMA_VODMA_CLKGEN_gating_src_sel_shift                                 (1)
#define  VODMA_VODMA_CLKGEN_en_fifo_full_gate_shift                              (0)
#define  VODMA_VODMA_CLKGEN_vodma_enclk_mask                                     (0x80000000)
#define  VODMA_VODMA_CLKGEN_vodma_clk_div2_en_src_sel_mask                       (0x20000000)
#define  VODMA_VODMA_CLKGEN_vodma_clk_div2_en_mask                               (0x10000000)
#define  VODMA_VODMA_CLKGEN_vodma_clk_div_n_mask                                 (0x0F800000)
#define  VODMA_VODMA_CLKGEN_vodma_clk_ratio_n_off_mask                           (0x001F0000)
#define  VODMA_VODMA_CLKGEN_dummy_15_7_mask                                      (0x0000FF80)
#define  VODMA_VODMA_CLKGEN_vodma_clk_sel_mask                                   (0x00000070)
#define  VODMA_VODMA_CLKGEN_en_fifo_empty_gate_mask                              (0x00000008)
#define  VODMA_VODMA_CLKGEN_gating_src_sel_mask                                  (0x00000006)
#define  VODMA_VODMA_CLKGEN_en_fifo_full_gate_mask                               (0x00000001)
#define  VODMA_VODMA_CLKGEN_vodma_enclk(data)                                    (0x80000000&((data)<<31))
#define  VODMA_VODMA_CLKGEN_vodma_clk_div2_en_src_sel(data)                      (0x20000000&((data)<<29))
#define  VODMA_VODMA_CLKGEN_vodma_clk_div2_en(data)                              (0x10000000&((data)<<28))
#define  VODMA_VODMA_CLKGEN_vodma_clk_div_n(data)                                (0x0F800000&((data)<<23))
#define  VODMA_VODMA_CLKGEN_vodma_clk_ratio_n_off(data)                          (0x001F0000&((data)<<16))
#define  VODMA_VODMA_CLKGEN_dummy_15_7(data)                                     (0x0000FF80&((data)<<7))
#define  VODMA_VODMA_CLKGEN_vodma_clk_sel(data)                                  (0x00000070&((data)<<4))
#define  VODMA_VODMA_CLKGEN_en_fifo_empty_gate(data)                             (0x00000008&((data)<<3))
#define  VODMA_VODMA_CLKGEN_gating_src_sel(data)                                 (0x00000006&((data)<<1))
#define  VODMA_VODMA_CLKGEN_en_fifo_full_gate(data)                              (0x00000001&(data))
#define  VODMA_VODMA_CLKGEN_get_vodma_enclk(data)                                ((0x80000000&(data))>>31)
#define  VODMA_VODMA_CLKGEN_get_vodma_clk_div2_en_src_sel(data)                  ((0x20000000&(data))>>29)
#define  VODMA_VODMA_CLKGEN_get_vodma_clk_div2_en(data)                          ((0x10000000&(data))>>28)
#define  VODMA_VODMA_CLKGEN_get_vodma_clk_div_n(data)                            ((0x0F800000&(data))>>23)
#define  VODMA_VODMA_CLKGEN_get_vodma_clk_ratio_n_off(data)                      ((0x001F0000&(data))>>16)
#define  VODMA_VODMA_CLKGEN_get_dummy_15_7(data)                                 ((0x0000FF80&(data))>>7)
#define  VODMA_VODMA_CLKGEN_get_vodma_clk_sel(data)                              ((0x00000070&(data))>>4)
#define  VODMA_VODMA_CLKGEN_get_en_fifo_empty_gate(data)                         ((0x00000008&(data))>>3)
#define  VODMA_VODMA_CLKGEN_get_gating_src_sel(data)                             ((0x00000006&(data))>>1)
#define  VODMA_VODMA_CLKGEN_get_en_fifo_full_gate(data)                          (0x00000001&(data))

#define  VODMA_VODMA_PVS_WIDTH_CTRL                                              0x18005314
#define  VODMA_VODMA_PVS_WIDTH_CTRL_reg_addr                                     "0xB8005314"
#define  VODMA_VODMA_PVS_WIDTH_CTRL_reg                                          0xB8005314
#define  VODMA_VODMA_PVS_WIDTH_CTRL_inst_addr                                    "0x0056"
#define  set_VODMA_VODMA_PVS_WIDTH_CTRL_reg(data)                                (*((volatile unsigned int*)VODMA_VODMA_PVS_WIDTH_CTRL_reg)=data)
#define  get_VODMA_VODMA_PVS_WIDTH_CTRL_reg                                      (*((volatile unsigned int*)VODMA_VODMA_PVS_WIDTH_CTRL_reg))
#define  VODMA_VODMA_PVS_WIDTH_CTRL_dummy_31_28_shift                            (28)
#define  VODMA_VODMA_PVS_WIDTH_CTRL_pvs0_vs_width_shift                          (0)
#define  VODMA_VODMA_PVS_WIDTH_CTRL_dummy_31_28_mask                             (0xF0000000)
#define  VODMA_VODMA_PVS_WIDTH_CTRL_pvs0_vs_width_mask                           (0x0FFFFFFF)
#define  VODMA_VODMA_PVS_WIDTH_CTRL_dummy_31_28(data)                            (0xF0000000&((data)<<28))
#define  VODMA_VODMA_PVS_WIDTH_CTRL_pvs0_vs_width(data)                          (0x0FFFFFFF&(data))
#define  VODMA_VODMA_PVS_WIDTH_CTRL_get_dummy_31_28(data)                        ((0xF0000000&(data))>>28)
#define  VODMA_VODMA_PVS_WIDTH_CTRL_get_pvs0_vs_width(data)                      (0x0FFFFFFF&(data))

#define  VODMA_VODMA_Phase_error_for_2vs                                         0x18005340
#define  VODMA_VODMA_Phase_error_for_2vs_reg_addr                                "0xB8005340"
#define  VODMA_VODMA_Phase_error_for_2vs_reg                                     0xB8005340
#define  VODMA_VODMA_Phase_error_for_2vs_inst_addr                               "0x0057"
#define  set_VODMA_VODMA_Phase_error_for_2vs_reg(data)                           (*((volatile unsigned int*)VODMA_VODMA_Phase_error_for_2vs_reg)=data)
#define  get_VODMA_VODMA_Phase_error_for_2vs_reg                                 (*((volatile unsigned int*)VODMA_VODMA_Phase_error_for_2vs_reg))
#define  VODMA_VODMA_Phase_error_for_2vs_phase_err_measure_start_shift           (31)
#define  VODMA_VODMA_Phase_error_for_2vs_pe_number_shift                         (0)
#define  VODMA_VODMA_Phase_error_for_2vs_phase_err_measure_start_mask            (0x80000000)
#define  VODMA_VODMA_Phase_error_for_2vs_pe_number_mask                          (0x0FFFFFFF)
#define  VODMA_VODMA_Phase_error_for_2vs_phase_err_measure_start(data)           (0x80000000&((data)<<31))
#define  VODMA_VODMA_Phase_error_for_2vs_pe_number(data)                         (0x0FFFFFFF&(data))
#define  VODMA_VODMA_Phase_error_for_2vs_get_phase_err_measure_start(data)       ((0x80000000&(data))>>31)
#define  VODMA_VODMA_Phase_error_for_2vs_get_pe_number(data)                     (0x0FFFFFFF&(data))

#define  VODMA_VODMA_manual_vs                                                   0x18005344
#define  VODMA_VODMA_manual_vs_reg_addr                                          "0xB8005344"
#define  VODMA_VODMA_manual_vs_reg                                               0xB8005344
#define  VODMA_VODMA_manual_vs_inst_addr                                         "0x0058"
#define  set_VODMA_VODMA_manual_vs_reg(data)                                     (*((volatile unsigned int*)VODMA_VODMA_manual_vs_reg)=data)
#define  get_VODMA_VODMA_manual_vs_reg                                           (*((volatile unsigned int*)VODMA_VODMA_manual_vs_reg))
#define  VODMA_VODMA_manual_vs_manual_vs_shift                                   (31)
#define  VODMA_VODMA_manual_vs_manual_vs_mask                                    (0x80000000)
#define  VODMA_VODMA_manual_vs_manual_vs(data)                                   (0x80000000&((data)<<31))
#define  VODMA_VODMA_manual_vs_get_manual_vs(data)                               ((0x80000000&(data))>>31)

#define  VODMA_VODMA_REG_DB_VSYNC_CTRL                                           0x18005348
#define  VODMA_VODMA_REG_DB_VSYNC_CTRL_reg_addr                                  "0xB8005348"
#define  VODMA_VODMA_REG_DB_VSYNC_CTRL_reg                                       0xB8005348
#define  VODMA_VODMA_REG_DB_VSYNC_CTRL_inst_addr                                 "0x0059"
#define  set_VODMA_VODMA_REG_DB_VSYNC_CTRL_reg(data)                             (*((volatile unsigned int*)VODMA_VODMA_REG_DB_VSYNC_CTRL_reg)=data)
#define  get_VODMA_VODMA_REG_DB_VSYNC_CTRL_reg                                   (*((volatile unsigned int*)VODMA_VODMA_REG_DB_VSYNC_CTRL_reg))
#define  VODMA_VODMA_REG_DB_VSYNC_CTRL_db_vs_sel_rwd1_shift                      (30)
#define  VODMA_VODMA_REG_DB_VSYNC_CTRL_db_vs_sel_rwd1_mask                       (0xC0000000)
#define  VODMA_VODMA_REG_DB_VSYNC_CTRL_db_vs_sel_rwd1(data)                      (0xC0000000&((data)<<30))
#define  VODMA_VODMA_REG_DB_VSYNC_CTRL_get_db_vs_sel_rwd1(data)                  ((0xC0000000&(data))>>30)

#define  VODMA_DECOMP_CTRL0                                                      0x18005100
#define  VODMA_DECOMP_CTRL0_reg_addr                                             "0xB8005100"
#define  VODMA_DECOMP_CTRL0_reg                                                  0xB8005100
#define  VODMA_DECOMP_CTRL0_inst_addr                                            "0x005A"
#define  set_VODMA_DECOMP_CTRL0_reg(data)                                        (*((volatile unsigned int*)VODMA_DECOMP_CTRL0_reg)=data)
#define  get_VODMA_DECOMP_CTRL0_reg                                              (*((volatile unsigned int*)VODMA_DECOMP_CTRL0_reg))
#define  VODMA_DECOMP_CTRL0_wrap_line_num_sys_shift                              (20)
#define  VODMA_DECOMP_CTRL0_wrap_v_div2_en_shift                                 (17)
#define  VODMA_DECOMP_CTRL0_wrap_v_flip_en_shift                                 (16)
#define  VODMA_DECOMP_CTRL0_decomp_bpp_sys_shift                                 (12)
#define  VODMA_DECOMP_CTRL0_header_num_4line_sys_shift                           (4)
#define  VODMA_DECOMP_CTRL0_decomp_bypass_en_shift                               (2)
#define  VODMA_DECOMP_CTRL0_lossy_en_shift                                       (1)
#define  VODMA_DECOMP_CTRL0_decomp_wrap_en_shift                                 (0)
#define  VODMA_DECOMP_CTRL0_wrap_line_num_sys_mask                               (0xFFF00000)
#define  VODMA_DECOMP_CTRL0_wrap_v_div2_en_mask                                  (0x00020000)
#define  VODMA_DECOMP_CTRL0_wrap_v_flip_en_mask                                  (0x00010000)
#define  VODMA_DECOMP_CTRL0_decomp_bpp_sys_mask                                  (0x0000F000)
#define  VODMA_DECOMP_CTRL0_header_num_4line_sys_mask                            (0x00000FF0)
#define  VODMA_DECOMP_CTRL0_decomp_bypass_en_mask                                (0x00000004)
#define  VODMA_DECOMP_CTRL0_lossy_en_mask                                        (0x00000002)
#define  VODMA_DECOMP_CTRL0_decomp_wrap_en_mask                                  (0x00000001)
#define  VODMA_DECOMP_CTRL0_wrap_line_num_sys(data)                              (0xFFF00000&((data)<<20))
#define  VODMA_DECOMP_CTRL0_wrap_v_div2_en(data)                                 (0x00020000&((data)<<17))
#define  VODMA_DECOMP_CTRL0_wrap_v_flip_en(data)                                 (0x00010000&((data)<<16))
#define  VODMA_DECOMP_CTRL0_decomp_bpp_sys(data)                                 (0x0000F000&((data)<<12))
#define  VODMA_DECOMP_CTRL0_header_num_4line_sys(data)                           (0x00000FF0&((data)<<4))
#define  VODMA_DECOMP_CTRL0_decomp_bypass_en(data)                               (0x00000004&((data)<<2))
#define  VODMA_DECOMP_CTRL0_lossy_en(data)                                       (0x00000002&((data)<<1))
#define  VODMA_DECOMP_CTRL0_decomp_wrap_en(data)                                 (0x00000001&(data))
#define  VODMA_DECOMP_CTRL0_get_wrap_line_num_sys(data)                          ((0xFFF00000&(data))>>20)
#define  VODMA_DECOMP_CTRL0_get_wrap_v_div2_en(data)                             ((0x00020000&(data))>>17)
#define  VODMA_DECOMP_CTRL0_get_wrap_v_flip_en(data)                             ((0x00010000&(data))>>16)
#define  VODMA_DECOMP_CTRL0_get_decomp_bpp_sys(data)                             ((0x0000F000&(data))>>12)
#define  VODMA_DECOMP_CTRL0_get_header_num_4line_sys(data)                       ((0x00000FF0&(data))>>4)
#define  VODMA_DECOMP_CTRL0_get_decomp_bypass_en(data)                           ((0x00000004&(data))>>2)
#define  VODMA_DECOMP_CTRL0_get_lossy_en(data)                                   ((0x00000002&(data))>>1)
#define  VODMA_DECOMP_CTRL0_get_decomp_wrap_en(data)                             (0x00000001&(data))

#define  VODMA_DECOMP_CTRL1                                                      0x18005108
#define  VODMA_DECOMP_CTRL1_reg_addr                                             "0xB8005108"
#define  VODMA_DECOMP_CTRL1_reg                                                  0xB8005108
#define  VODMA_DECOMP_CTRL1_inst_addr                                            "0x005B"
#define  set_VODMA_DECOMP_CTRL1_reg(data)                                        (*((volatile unsigned int*)VODMA_DECOMP_CTRL1_reg)=data)
#define  get_VODMA_DECOMP_CTRL1_reg                                              (*((volatile unsigned int*)VODMA_DECOMP_CTRL1_reg))
#define  VODMA_DECOMP_CTRL1_wrap_line_num_vodma_shift                            (20)
#define  VODMA_DECOMP_CTRL1_decomp_bpp_vodma_shift                               (12)
#define  VODMA_DECOMP_CTRL1_header_num_4line_vodma_shift                         (4)
#define  VODMA_DECOMP_CTRL1_wrap_line_num_vodma_mask                             (0xFFF00000)
#define  VODMA_DECOMP_CTRL1_decomp_bpp_vodma_mask                                (0x0000F000)
#define  VODMA_DECOMP_CTRL1_header_num_4line_vodma_mask                          (0x00000FF0)
#define  VODMA_DECOMP_CTRL1_wrap_line_num_vodma(data)                            (0xFFF00000&((data)<<20))
#define  VODMA_DECOMP_CTRL1_decomp_bpp_vodma(data)                               (0x0000F000&((data)<<12))
#define  VODMA_DECOMP_CTRL1_header_num_4line_vodma(data)                         (0x00000FF0&((data)<<4))
#define  VODMA_DECOMP_CTRL1_get_wrap_line_num_vodma(data)                        ((0xFFF00000&(data))>>20)
#define  VODMA_DECOMP_CTRL1_get_decomp_bpp_vodma(data)                           ((0x0000F000&(data))>>12)
#define  VODMA_DECOMP_CTRL1_get_header_num_4line_vodma(data)                     ((0x00000FF0&(data))>>4)

#define  VODMA_DECOMP_YDMA                                                       0x18005110
#define  VODMA_DECOMP_YDMA_reg_addr                                              "0xB8005110"
#define  VODMA_DECOMP_YDMA_reg                                                   0xB8005110
#define  VODMA_DECOMP_YDMA_inst_addr                                             "0x005C"
#define  set_VODMA_DECOMP_YDMA_reg(data)                                         (*((volatile unsigned int*)VODMA_DECOMP_YDMA_reg)=data)
#define  get_VODMA_DECOMP_YDMA_reg                                               (*((volatile unsigned int*)VODMA_DECOMP_YDMA_reg))
#define  VODMA_DECOMP_YDMA_warp_y_data_wtlvl_shift                               (16)
#define  VODMA_DECOMP_YDMA_wrap_y_data_read_len_shift                            (0)
#define  VODMA_DECOMP_YDMA_warp_y_data_wtlvl_mask                                (0x01FF0000)
#define  VODMA_DECOMP_YDMA_wrap_y_data_read_len_mask                             (0x000000FF)
#define  VODMA_DECOMP_YDMA_warp_y_data_wtlvl(data)                               (0x01FF0000&((data)<<16))
#define  VODMA_DECOMP_YDMA_wrap_y_data_read_len(data)                            (0x000000FF&(data))
#define  VODMA_DECOMP_YDMA_get_warp_y_data_wtlvl(data)                           ((0x01FF0000&(data))>>16)
#define  VODMA_DECOMP_YDMA_get_wrap_y_data_read_len(data)                        (0x000000FF&(data))

#define  VODMA_DECOMP_CDMA                                                       0x18005114
#define  VODMA_DECOMP_CDMA_reg_addr                                              "0xB8005114"
#define  VODMA_DECOMP_CDMA_reg                                                   0xB8005114
#define  VODMA_DECOMP_CDMA_inst_addr                                             "0x005D"
#define  set_VODMA_DECOMP_CDMA_reg(data)                                         (*((volatile unsigned int*)VODMA_DECOMP_CDMA_reg)=data)
#define  get_VODMA_DECOMP_CDMA_reg                                               (*((volatile unsigned int*)VODMA_DECOMP_CDMA_reg))
#define  VODMA_DECOMP_CDMA_wrap_c_data_wtlvl_shift                               (16)
#define  VODMA_DECOMP_CDMA_wrap_c_data_read_len_shift                            (0)
#define  VODMA_DECOMP_CDMA_wrap_c_data_wtlvl_mask                                (0x01FF0000)
#define  VODMA_DECOMP_CDMA_wrap_c_data_read_len_mask                             (0x000000FF)
#define  VODMA_DECOMP_CDMA_wrap_c_data_wtlvl(data)                               (0x01FF0000&((data)<<16))
#define  VODMA_DECOMP_CDMA_wrap_c_data_read_len(data)                            (0x000000FF&(data))
#define  VODMA_DECOMP_CDMA_get_wrap_c_data_wtlvl(data)                           ((0x01FF0000&(data))>>16)
#define  VODMA_DECOMP_CDMA_get_wrap_c_data_read_len(data)                        (0x000000FF&(data))

#define  VODMA_DECOMP_PIC_SET                                                    0x18005118
#define  VODMA_DECOMP_PIC_SET_reg_addr                                           "0xB8005118"
#define  VODMA_DECOMP_PIC_SET_reg                                                0xB8005118
#define  VODMA_DECOMP_PIC_SET_inst_addr                                          "0x005E"
#define  set_VODMA_DECOMP_PIC_SET_reg(data)                                      (*((volatile unsigned int*)VODMA_DECOMP_PIC_SET_reg)=data)
#define  get_VODMA_DECOMP_PIC_SET_reg                                            (*((volatile unsigned int*)VODMA_DECOMP_PIC_SET_reg))
#define  VODMA_DECOMP_PIC_SET_wapp_c_data_pic_set_shift                          (16)
#define  VODMA_DECOMP_PIC_SET_wapp_y_data_pic_set_shift                          (0)
#define  VODMA_DECOMP_PIC_SET_wapp_c_data_pic_set_mask                           (0x00FF0000)
#define  VODMA_DECOMP_PIC_SET_wapp_y_data_pic_set_mask                           (0x000000FF)
#define  VODMA_DECOMP_PIC_SET_wapp_c_data_pic_set(data)                          (0x00FF0000&((data)<<16))
#define  VODMA_DECOMP_PIC_SET_wapp_y_data_pic_set(data)                          (0x000000FF&(data))
#define  VODMA_DECOMP_PIC_SET_get_wapp_c_data_pic_set(data)                      ((0x00FF0000&(data))>>16)
#define  VODMA_DECOMP_PIC_SET_get_wapp_y_data_pic_set(data)                      (0x000000FF&(data))

#define  VODMA_DECOMP_READ_Y                                                     0x1800511C
#define  VODMA_DECOMP_READ_Y_reg_addr                                            "0xB800511C"
#define  VODMA_DECOMP_READ_Y_reg                                                 0xB800511C
#define  VODMA_DECOMP_READ_Y_inst_addr                                           "0x005F"
#define  set_VODMA_DECOMP_READ_Y_reg(data)                                       (*((volatile unsigned int*)VODMA_DECOMP_READ_Y_reg)=data)
#define  get_VODMA_DECOMP_READ_Y_reg                                             (*((volatile unsigned int*)VODMA_DECOMP_READ_Y_reg))
#define  VODMA_DECOMP_READ_Y_wapp_y_header_read_addr_shift                       (3)
#define  VODMA_DECOMP_READ_Y_wapp_y_header_read_addr_mask                        (0xFFFFFFF8)
#define  VODMA_DECOMP_READ_Y_wapp_y_header_read_addr(data)                       (0xFFFFFFF8&((data)<<3))
#define  VODMA_DECOMP_READ_Y_get_wapp_y_header_read_addr(data)                   ((0xFFFFFFF8&(data))>>3)

#define  VODMA_DECOMP_READ_C                                                     0x18005120
#define  VODMA_DECOMP_READ_C_reg_addr                                            "0xB8005120"
#define  VODMA_DECOMP_READ_C_reg                                                 0xB8005120
#define  VODMA_DECOMP_READ_C_inst_addr                                           "0x0060"
#define  set_VODMA_DECOMP_READ_C_reg(data)                                       (*((volatile unsigned int*)VODMA_DECOMP_READ_C_reg)=data)
#define  get_VODMA_DECOMP_READ_C_reg                                             (*((volatile unsigned int*)VODMA_DECOMP_READ_C_reg))
#define  VODMA_DECOMP_READ_C_wapp_c_header_read_addr_shift                       (3)
#define  VODMA_DECOMP_READ_C_wapp_c_header_read_addr_mask                        (0xFFFFFFF8)
#define  VODMA_DECOMP_READ_C_wapp_c_header_read_addr(data)                       (0xFFFFFFF8&((data)<<3))
#define  VODMA_DECOMP_READ_C_get_wapp_c_header_read_addr(data)                   ((0xFFFFFFF8&(data))>>3)

#define  VODMA_DECOMP_X_WID_Y                                                    0x18005124
#define  VODMA_DECOMP_X_WID_Y_reg_addr                                           "0xB8005124"
#define  VODMA_DECOMP_X_WID_Y_reg                                                0xB8005124
#define  VODMA_DECOMP_X_WID_Y_inst_addr                                          "0x0061"
#define  set_VODMA_DECOMP_X_WID_Y_reg(data)                                      (*((volatile unsigned int*)VODMA_DECOMP_X_WID_Y_reg)=data)
#define  get_VODMA_DECOMP_X_WID_Y_reg                                            (*((volatile unsigned int*)VODMA_DECOMP_X_WID_Y_reg))
#define  VODMA_DECOMP_X_WID_Y_wrap_data_wid_y_shift                              (0)
#define  VODMA_DECOMP_X_WID_Y_wrap_data_wid_y_mask                               (0x000003FF)
#define  VODMA_DECOMP_X_WID_Y_wrap_data_wid_y(data)                              (0x000003FF&(data))
#define  VODMA_DECOMP_X_WID_Y_get_wrap_data_wid_y(data)                          (0x000003FF&(data))

#define  VODMA_DECOMP_X_WID_C                                                    0x18005128
#define  VODMA_DECOMP_X_WID_C_reg_addr                                           "0xB8005128"
#define  VODMA_DECOMP_X_WID_C_reg                                                0xB8005128
#define  VODMA_DECOMP_X_WID_C_inst_addr                                          "0x0062"
#define  set_VODMA_DECOMP_X_WID_C_reg(data)                                      (*((volatile unsigned int*)VODMA_DECOMP_X_WID_C_reg)=data)
#define  get_VODMA_DECOMP_X_WID_C_reg                                            (*((volatile unsigned int*)VODMA_DECOMP_X_WID_C_reg))
#define  VODMA_DECOMP_X_WID_C_wrap_data_wid_c_shift                              (0)
#define  VODMA_DECOMP_X_WID_C_wrap_data_wid_c_mask                               (0x000003FF)
#define  VODMA_DECOMP_X_WID_C_wrap_data_wid_c(data)                              (0x000003FF&(data))
#define  VODMA_DECOMP_X_WID_C_get_wrap_data_wid_c(data)                          (0x000003FF&(data))

#define  VODMA_DECOMP_DMA_READ_HD_Y                                              0x1800512C
#define  VODMA_DECOMP_DMA_READ_HD_Y_reg_addr                                     "0xB800512C"
#define  VODMA_DECOMP_DMA_READ_HD_Y_reg                                          0xB800512C
#define  VODMA_DECOMP_DMA_READ_HD_Y_inst_addr                                    "0x0063"
#define  set_VODMA_DECOMP_DMA_READ_HD_Y_reg(data)                                (*((volatile unsigned int*)VODMA_DECOMP_DMA_READ_HD_Y_reg)=data)
#define  get_VODMA_DECOMP_DMA_READ_HD_Y_reg                                      (*((volatile unsigned int*)VODMA_DECOMP_DMA_READ_HD_Y_reg))
#define  VODMA_DECOMP_DMA_READ_HD_Y_dma_y_hd_4line_step_shift                    (3)
#define  VODMA_DECOMP_DMA_READ_HD_Y_dma_y_hd_4line_step_mask                     (0xFFFFFFF8)
#define  VODMA_DECOMP_DMA_READ_HD_Y_dma_y_hd_4line_step(data)                    (0xFFFFFFF8&((data)<<3))
#define  VODMA_DECOMP_DMA_READ_HD_Y_get_dma_y_hd_4line_step(data)                ((0xFFFFFFF8&(data))>>3)

#define  VODMA_DECOMP_DMA_READ_HD_C                                              0x18005130
#define  VODMA_DECOMP_DMA_READ_HD_C_reg_addr                                     "0xB8005130"
#define  VODMA_DECOMP_DMA_READ_HD_C_reg                                          0xB8005130
#define  VODMA_DECOMP_DMA_READ_HD_C_inst_addr                                    "0x0064"
#define  set_VODMA_DECOMP_DMA_READ_HD_C_reg(data)                                (*((volatile unsigned int*)VODMA_DECOMP_DMA_READ_HD_C_reg)=data)
#define  get_VODMA_DECOMP_DMA_READ_HD_C_reg                                      (*((volatile unsigned int*)VODMA_DECOMP_DMA_READ_HD_C_reg))
#define  VODMA_DECOMP_DMA_READ_HD_C_dma_c_hd_4line_step_shift                    (3)
#define  VODMA_DECOMP_DMA_READ_HD_C_dma_c_hd_4line_step_mask                     (0xFFFFFFF8)
#define  VODMA_DECOMP_DMA_READ_HD_C_dma_c_hd_4line_step(data)                    (0xFFFFFFF8&((data)<<3))
#define  VODMA_DECOMP_DMA_READ_HD_C_get_dma_c_hd_4line_step(data)                ((0xFFFFFFF8&(data))>>3)

#define  VODMA_DECOMP_HD_CTRL1                                                   0x18005134
#define  VODMA_DECOMP_HD_CTRL1_reg_addr                                          "0xB8005134"
#define  VODMA_DECOMP_HD_CTRL1_reg                                               0xB8005134
#define  VODMA_DECOMP_HD_CTRL1_inst_addr                                         "0x0065"
#define  set_VODMA_DECOMP_HD_CTRL1_reg(data)                                     (*((volatile unsigned int*)VODMA_DECOMP_HD_CTRL1_reg)=data)
#define  get_VODMA_DECOMP_HD_CTRL1_reg                                           (*((volatile unsigned int*)VODMA_DECOMP_HD_CTRL1_reg))
#define  VODMA_DECOMP_HD_CTRL1_dma_c_hd_mode_shift                               (31)
#define  VODMA_DECOMP_HD_CTRL1_dma_y_hd_mode_shift                               (30)
#define  VODMA_DECOMP_HD_CTRL1_dma_c_hd_blk_len_shift                            (8)
#define  VODMA_DECOMP_HD_CTRL1_dma_y_hd_blk_len_shift                            (0)
#define  VODMA_DECOMP_HD_CTRL1_dma_c_hd_mode_mask                                (0x80000000)
#define  VODMA_DECOMP_HD_CTRL1_dma_y_hd_mode_mask                                (0x40000000)
#define  VODMA_DECOMP_HD_CTRL1_dma_c_hd_blk_len_mask                             (0x0000FF00)
#define  VODMA_DECOMP_HD_CTRL1_dma_y_hd_blk_len_mask                             (0x000000FF)
#define  VODMA_DECOMP_HD_CTRL1_dma_c_hd_mode(data)                               (0x80000000&((data)<<31))
#define  VODMA_DECOMP_HD_CTRL1_dma_y_hd_mode(data)                               (0x40000000&((data)<<30))
#define  VODMA_DECOMP_HD_CTRL1_dma_c_hd_blk_len(data)                            (0x0000FF00&((data)<<8))
#define  VODMA_DECOMP_HD_CTRL1_dma_y_hd_blk_len(data)                            (0x000000FF&(data))
#define  VODMA_DECOMP_HD_CTRL1_get_dma_c_hd_mode(data)                           ((0x80000000&(data))>>31)
#define  VODMA_DECOMP_HD_CTRL1_get_dma_y_hd_mode(data)                           ((0x40000000&(data))>>30)
#define  VODMA_DECOMP_HD_CTRL1_get_dma_c_hd_blk_len(data)                        ((0x0000FF00&(data))>>8)
#define  VODMA_DECOMP_HD_CTRL1_get_dma_y_hd_blk_len(data)                        (0x000000FF&(data))

#define  VODMA_DECOMP_DMA_STSTUS                                                 0x18005150
#define  VODMA_DECOMP_DMA_STSTUS_reg_addr                                        "0xB8005150"
#define  VODMA_DECOMP_DMA_STSTUS_reg                                             0xB8005150
#define  VODMA_DECOMP_DMA_STSTUS_inst_addr                                       "0x0066"
#define  set_VODMA_DECOMP_DMA_STSTUS_reg(data)                                   (*((volatile unsigned int*)VODMA_DECOMP_DMA_STSTUS_reg)=data)
#define  get_VODMA_DECOMP_DMA_STSTUS_reg                                         (*((volatile unsigned int*)VODMA_DECOMP_DMA_STSTUS_reg))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_data_fifoof_shift                        (27)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_data_fifouf_shift                        (26)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_data_fifofull_shift                      (25)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_data_fifoempty_shift                     (24)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_head_fifoof_shift                        (23)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_head_fifofull_shift                      (21)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_head_fifoempty_shift                     (20)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_dma_fifoof_shift                         (19)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_dma_req_error_shift                      (18)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_dma_fifofull_shift                       (17)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_dma_fifoempty_shift                      (16)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_data_fifoof_shift                        (11)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_data_fifouf_shift                        (10)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_data_fifofull_shift                      (9)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_data_fifoempty_shift                     (8)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_head_fifoof_shift                        (7)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_head_fifofull_shift                      (5)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_head_fifoempty_shift                     (4)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_dma_fifoof_shift                         (3)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_dma_req_error_shift                      (2)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_dma_fifofull_shift                       (1)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_dma_fifoempty_shift                      (0)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_data_fifoof_mask                         (0x08000000)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_data_fifouf_mask                         (0x04000000)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_data_fifofull_mask                       (0x02000000)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_data_fifoempty_mask                      (0x01000000)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_head_fifoof_mask                         (0x00800000)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_head_fifofull_mask                       (0x00200000)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_head_fifoempty_mask                      (0x00100000)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_dma_fifoof_mask                          (0x00080000)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_dma_req_error_mask                       (0x00040000)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_dma_fifofull_mask                        (0x00020000)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_dma_fifoempty_mask                       (0x00010000)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_data_fifoof_mask                         (0x00000800)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_data_fifouf_mask                         (0x00000400)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_data_fifofull_mask                       (0x00000200)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_data_fifoempty_mask                      (0x00000100)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_head_fifoof_mask                         (0x00000080)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_head_fifofull_mask                       (0x00000020)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_head_fifoempty_mask                      (0x00000010)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_dma_fifoof_mask                          (0x00000008)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_dma_req_error_mask                       (0x00000004)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_dma_fifofull_mask                        (0x00000002)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_dma_fifoempty_mask                       (0x00000001)
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_data_fifoof(data)                        (0x08000000&((data)<<27))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_data_fifouf(data)                        (0x04000000&((data)<<26))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_data_fifofull(data)                      (0x02000000&((data)<<25))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_data_fifoempty(data)                     (0x01000000&((data)<<24))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_head_fifoof(data)                        (0x00800000&((data)<<23))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_head_fifofull(data)                      (0x00200000&((data)<<21))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_head_fifoempty(data)                     (0x00100000&((data)<<20))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_dma_fifoof(data)                         (0x00080000&((data)<<19))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_dma_req_error(data)                      (0x00040000&((data)<<18))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_dma_fifofull(data)                       (0x00020000&((data)<<17))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_c_dma_fifoempty(data)                      (0x00010000&((data)<<16))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_data_fifoof(data)                        (0x00000800&((data)<<11))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_data_fifouf(data)                        (0x00000400&((data)<<10))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_data_fifofull(data)                      (0x00000200&((data)<<9))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_data_fifoempty(data)                     (0x00000100&((data)<<8))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_head_fifoof(data)                        (0x00000080&((data)<<7))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_head_fifofull(data)                      (0x00000020&((data)<<5))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_head_fifoempty(data)                     (0x00000010&((data)<<4))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_dma_fifoof(data)                         (0x00000008&((data)<<3))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_dma_req_error(data)                      (0x00000004&((data)<<2))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_dma_fifofull(data)                       (0x00000002&((data)<<1))
#define  VODMA_DECOMP_DMA_STSTUS_wrap_y_dma_fifoempty(data)                      (0x00000001&(data))
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_c_data_fifoof(data)                    ((0x08000000&(data))>>27)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_c_data_fifouf(data)                    ((0x04000000&(data))>>26)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_c_data_fifofull(data)                  ((0x02000000&(data))>>25)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_c_data_fifoempty(data)                 ((0x01000000&(data))>>24)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_c_head_fifoof(data)                    ((0x00800000&(data))>>23)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_c_head_fifofull(data)                  ((0x00200000&(data))>>21)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_c_head_fifoempty(data)                 ((0x00100000&(data))>>20)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_c_dma_fifoof(data)                     ((0x00080000&(data))>>19)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_c_dma_req_error(data)                  ((0x00040000&(data))>>18)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_c_dma_fifofull(data)                   ((0x00020000&(data))>>17)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_c_dma_fifoempty(data)                  ((0x00010000&(data))>>16)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_y_data_fifoof(data)                    ((0x00000800&(data))>>11)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_y_data_fifouf(data)                    ((0x00000400&(data))>>10)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_y_data_fifofull(data)                  ((0x00000200&(data))>>9)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_y_data_fifoempty(data)                 ((0x00000100&(data))>>8)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_y_head_fifoof(data)                    ((0x00000080&(data))>>7)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_y_head_fifofull(data)                  ((0x00000020&(data))>>5)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_y_head_fifoempty(data)                 ((0x00000010&(data))>>4)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_y_dma_fifoof(data)                     ((0x00000008&(data))>>3)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_y_dma_req_error(data)                  ((0x00000004&(data))>>2)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_y_dma_fifofull(data)                   ((0x00000002&(data))>>1)
#define  VODMA_DECOMP_DMA_STSTUS_get_wrap_y_dma_fifoempty(data)                  (0x00000001&(data))

#define  VODMA_DECOMP_DMA_IE                                                     0x18005158
#define  VODMA_DECOMP_DMA_IE_reg_addr                                            "0xB8005158"
#define  VODMA_DECOMP_DMA_IE_reg                                                 0xB8005158
#define  VODMA_DECOMP_DMA_IE_inst_addr                                           "0x0067"
#define  set_VODMA_DECOMP_DMA_IE_reg(data)                                       (*((volatile unsigned int*)VODMA_DECOMP_DMA_IE_reg)=data)
#define  get_VODMA_DECOMP_DMA_IE_reg                                             (*((volatile unsigned int*)VODMA_DECOMP_DMA_IE_reg))
#define  VODMA_DECOMP_DMA_IE_wrap_c_data_fifoof_ie_shift                         (27)
#define  VODMA_DECOMP_DMA_IE_wrap_c_data_fifouf_ie_shift                         (26)
#define  VODMA_DECOMP_DMA_IE_wrap_c_head_fifoof_ie_shift                         (23)
#define  VODMA_DECOMP_DMA_IE_wrap_c_dma_fifoof_ie_shift                          (19)
#define  VODMA_DECOMP_DMA_IE_wrap_y_data_fifoof_ie_shift                         (11)
#define  VODMA_DECOMP_DMA_IE_wrap_y_data_fifouf_ie_shift                         (10)
#define  VODMA_DECOMP_DMA_IE_wrap_y_head_fifoof_ie_shift                         (7)
#define  VODMA_DECOMP_DMA_IE_wrap_y_dma_fifoof_ie_shift                          (3)
#define  VODMA_DECOMP_DMA_IE_wrap_c_data_fifoof_ie_mask                          (0x08000000)
#define  VODMA_DECOMP_DMA_IE_wrap_c_data_fifouf_ie_mask                          (0x04000000)
#define  VODMA_DECOMP_DMA_IE_wrap_c_head_fifoof_ie_mask                          (0x00800000)
#define  VODMA_DECOMP_DMA_IE_wrap_c_dma_fifoof_ie_mask                           (0x00080000)
#define  VODMA_DECOMP_DMA_IE_wrap_y_data_fifoof_ie_mask                          (0x00000800)
#define  VODMA_DECOMP_DMA_IE_wrap_y_data_fifouf_ie_mask                          (0x00000400)
#define  VODMA_DECOMP_DMA_IE_wrap_y_head_fifoof_ie_mask                          (0x00000080)
#define  VODMA_DECOMP_DMA_IE_wrap_y_dma_fifoof_ie_mask                           (0x00000008)
#define  VODMA_DECOMP_DMA_IE_wrap_c_data_fifoof_ie(data)                         (0x08000000&((data)<<27))
#define  VODMA_DECOMP_DMA_IE_wrap_c_data_fifouf_ie(data)                         (0x04000000&((data)<<26))
#define  VODMA_DECOMP_DMA_IE_wrap_c_head_fifoof_ie(data)                         (0x00800000&((data)<<23))
#define  VODMA_DECOMP_DMA_IE_wrap_c_dma_fifoof_ie(data)                          (0x00080000&((data)<<19))
#define  VODMA_DECOMP_DMA_IE_wrap_y_data_fifoof_ie(data)                         (0x00000800&((data)<<11))
#define  VODMA_DECOMP_DMA_IE_wrap_y_data_fifouf_ie(data)                         (0x00000400&((data)<<10))
#define  VODMA_DECOMP_DMA_IE_wrap_y_head_fifoof_ie(data)                         (0x00000080&((data)<<7))
#define  VODMA_DECOMP_DMA_IE_wrap_y_dma_fifoof_ie(data)                          (0x00000008&((data)<<3))
#define  VODMA_DECOMP_DMA_IE_get_wrap_c_data_fifoof_ie(data)                     ((0x08000000&(data))>>27)
#define  VODMA_DECOMP_DMA_IE_get_wrap_c_data_fifouf_ie(data)                     ((0x04000000&(data))>>26)
#define  VODMA_DECOMP_DMA_IE_get_wrap_c_head_fifoof_ie(data)                     ((0x00800000&(data))>>23)
#define  VODMA_DECOMP_DMA_IE_get_wrap_c_dma_fifoof_ie(data)                      ((0x00080000&(data))>>19)
#define  VODMA_DECOMP_DMA_IE_get_wrap_y_data_fifoof_ie(data)                     ((0x00000800&(data))>>11)
#define  VODMA_DECOMP_DMA_IE_get_wrap_y_data_fifouf_ie(data)                     ((0x00000400&(data))>>10)
#define  VODMA_DECOMP_DMA_IE_get_wrap_y_head_fifoof_ie(data)                     ((0x00000080&(data))>>7)
#define  VODMA_DECOMP_DMA_IE_get_wrap_y_dma_fifoof_ie(data)                      ((0x00000008&(data))>>3)

#define  VODMA_decomp_core_status_0                                              0x18005160
#define  VODMA_decomp_core_status_0_reg_addr                                     "0xB8005160"
#define  VODMA_decomp_core_status_0_reg                                          0xB8005160
#define  VODMA_decomp_core_status_0_inst_addr                                    "0x0068"
#define  set_VODMA_decomp_core_status_0_reg(data)                                (*((volatile unsigned int*)VODMA_decomp_core_status_0_reg)=data)
#define  get_VODMA_decomp_core_status_0_reg                                      (*((volatile unsigned int*)VODMA_decomp_core_status_0_reg))
#define  VODMA_decomp_core_status_0_decomp_core_irq_shift                        (31)
#define  VODMA_decomp_core_status_0_decomp_core2_irq_shift                       (15)
#define  VODMA_decomp_core_status_0_decomp_core_irq_mask                         (0x80000000)
#define  VODMA_decomp_core_status_0_decomp_core2_irq_mask                        (0x00008000)
#define  VODMA_decomp_core_status_0_decomp_core_irq(data)                        (0x80000000&((data)<<31))
#define  VODMA_decomp_core_status_0_decomp_core2_irq(data)                       (0x00008000&((data)<<15))
#define  VODMA_decomp_core_status_0_get_decomp_core_irq(data)                    ((0x80000000&(data))>>31)
#define  VODMA_decomp_core_status_0_get_decomp_core2_irq(data)                   ((0x00008000&(data))>>15)

#define  VODMA_decomp_core_status_1                                              0x18005164
#define  VODMA_decomp_core_status_1_reg_addr                                     "0xB8005164"
#define  VODMA_decomp_core_status_1_reg                                          0xB8005164
#define  VODMA_decomp_core_status_1_inst_addr                                    "0x0069"
#define  set_VODMA_decomp_core_status_1_reg(data)                                (*((volatile unsigned int*)VODMA_decomp_core_status_1_reg)=data)
#define  get_VODMA_decomp_core_status_1_reg                                      (*((volatile unsigned int*)VODMA_decomp_core_status_1_reg))
#define  VODMA_decomp_core_status_1_decomp_core2_errflag_shift                   (16)
#define  VODMA_decomp_core_status_1_decomp_core_errflag_shift                    (0)
#define  VODMA_decomp_core_status_1_decomp_core2_errflag_mask                    (0x00FF0000)
#define  VODMA_decomp_core_status_1_decomp_core_errflag_mask                     (0x000000FF)
#define  VODMA_decomp_core_status_1_decomp_core2_errflag(data)                   (0x00FF0000&((data)<<16))
#define  VODMA_decomp_core_status_1_decomp_core_errflag(data)                    (0x000000FF&(data))
#define  VODMA_decomp_core_status_1_get_decomp_core2_errflag(data)               ((0x00FF0000&(data))>>16)
#define  VODMA_decomp_core_status_1_get_decomp_core_errflag(data)                (0x000000FF&(data))

#define  VODMA_decomp_core_status_2                                              0x18005168
#define  VODMA_decomp_core_status_2_reg_addr                                     "0xB8005168"
#define  VODMA_decomp_core_status_2_reg                                          0xB8005168
#define  VODMA_decomp_core_status_2_inst_addr                                    "0x006A"
#define  set_VODMA_decomp_core_status_2_reg(data)                                (*((volatile unsigned int*)VODMA_decomp_core_status_2_reg)=data)
#define  get_VODMA_decomp_core_status_2_reg                                      (*((volatile unsigned int*)VODMA_decomp_core_status_2_reg))
#define  VODMA_decomp_core_status_2_decomp_core2_errflag_clr_shift               (16)
#define  VODMA_decomp_core_status_2_decomp_core_errflag_clr_shift                (0)
#define  VODMA_decomp_core_status_2_decomp_core2_errflag_clr_mask                (0x00FF0000)
#define  VODMA_decomp_core_status_2_decomp_core_errflag_clr_mask                 (0x000000FF)
#define  VODMA_decomp_core_status_2_decomp_core2_errflag_clr(data)               (0x00FF0000&((data)<<16))
#define  VODMA_decomp_core_status_2_decomp_core_errflag_clr(data)                (0x000000FF&(data))
#define  VODMA_decomp_core_status_2_get_decomp_core2_errflag_clr(data)           ((0x00FF0000&(data))>>16)
#define  VODMA_decomp_core_status_2_get_decomp_core_errflag_clr(data)            (0x000000FF&(data))

#define  VODMA_decomp_core_status_3                                              0x1800516C
#define  VODMA_decomp_core_status_3_reg_addr                                     "0xB800516C"
#define  VODMA_decomp_core_status_3_reg                                          0xB800516C
#define  VODMA_decomp_core_status_3_inst_addr                                    "0x006B"
#define  set_VODMA_decomp_core_status_3_reg(data)                                (*((volatile unsigned int*)VODMA_decomp_core_status_3_reg)=data)
#define  get_VODMA_decomp_core_status_3_reg                                      (*((volatile unsigned int*)VODMA_decomp_core_status_3_reg))
#define  VODMA_decomp_core_status_3_decomp_core2_flag2irq_en_shift               (16)
#define  VODMA_decomp_core_status_3_decomp_core_flag2irq_en_shift                (0)
#define  VODMA_decomp_core_status_3_decomp_core2_flag2irq_en_mask                (0x00FF0000)
#define  VODMA_decomp_core_status_3_decomp_core_flag2irq_en_mask                 (0x000000FF)
#define  VODMA_decomp_core_status_3_decomp_core2_flag2irq_en(data)               (0x00FF0000&((data)<<16))
#define  VODMA_decomp_core_status_3_decomp_core_flag2irq_en(data)                (0x000000FF&(data))
#define  VODMA_decomp_core_status_3_get_decomp_core2_flag2irq_en(data)           ((0x00FF0000&(data))>>16)
#define  VODMA_decomp_core_status_3_get_decomp_core_flag2irq_en(data)            (0x000000FF&(data))

#define  VODMA_vodma_i2rnd                                                       0x18005200
#define  VODMA_vodma_i2rnd_reg_addr                                              "0xB8005200"
#define  VODMA_vodma_i2rnd_reg                                                   0xB8005200
#define  VODMA_vodma_i2rnd_inst_addr                                             "0x006C"
#define  set_VODMA_vodma_i2rnd_reg(data)                                         (*((volatile unsigned int*)VODMA_vodma_i2rnd_reg)=data)
#define  get_VODMA_vodma_i2rnd_reg                                               (*((volatile unsigned int*)VODMA_vodma_i2rnd_reg))
#define  VODMA_vodma_i2rnd_i2rnd_flag_fifo_mode_shift                            (9)
#define  VODMA_vodma_i2rnd_i2rnd_flag_fifo_en_shift                              (8)
#define  VODMA_vodma_i2rnd_debug_mask_main_shift                                 (7)
#define  VODMA_vodma_i2rnd_debug_mask_sub1_shift                                 (6)
#define  VODMA_vodma_i2rnd_debug_mask_sub2_shift                                 (5)
#define  VODMA_vodma_i2rnd_debug_mask_repeat_sub_old_en_shift                    (4)
#define  VODMA_vodma_i2rnd_i2rnd_src_flag_inv_shift                              (3)
#define  VODMA_vodma_i2rnd_i2rnd_timing_mode_shift                               (1)
#define  VODMA_vodma_i2rnd_i2rnd_timing_en_shift                                 (0)
#define  VODMA_vodma_i2rnd_i2rnd_flag_fifo_mode_mask                             (0x00000200)
#define  VODMA_vodma_i2rnd_i2rnd_flag_fifo_en_mask                               (0x00000100)
#define  VODMA_vodma_i2rnd_debug_mask_main_mask                                  (0x00000080)
#define  VODMA_vodma_i2rnd_debug_mask_sub1_mask                                  (0x00000040)
#define  VODMA_vodma_i2rnd_debug_mask_sub2_mask                                  (0x00000020)
#define  VODMA_vodma_i2rnd_debug_mask_repeat_sub_old_en_mask                     (0x00000010)
#define  VODMA_vodma_i2rnd_i2rnd_src_flag_inv_mask                               (0x00000008)
#define  VODMA_vodma_i2rnd_i2rnd_timing_mode_mask                                (0x00000006)
#define  VODMA_vodma_i2rnd_i2rnd_timing_en_mask                                  (0x00000001)
#define  VODMA_vodma_i2rnd_i2rnd_flag_fifo_mode(data)                            (0x00000200&((data)<<9))
#define  VODMA_vodma_i2rnd_i2rnd_flag_fifo_en(data)                              (0x00000100&((data)<<8))
#define  VODMA_vodma_i2rnd_debug_mask_main(data)                                 (0x00000080&((data)<<7))
#define  VODMA_vodma_i2rnd_debug_mask_sub1(data)                                 (0x00000040&((data)<<6))
#define  VODMA_vodma_i2rnd_debug_mask_sub2(data)                                 (0x00000020&((data)<<5))
#define  VODMA_vodma_i2rnd_debug_mask_repeat_sub_old_en(data)                    (0x00000010&((data)<<4))
#define  VODMA_vodma_i2rnd_i2rnd_src_flag_inv(data)                              (0x00000008&((data)<<3))
#define  VODMA_vodma_i2rnd_i2rnd_timing_mode(data)                               (0x00000006&((data)<<1))
#define  VODMA_vodma_i2rnd_i2rnd_timing_en(data)                                 (0x00000001&(data))
#define  VODMA_vodma_i2rnd_get_i2rnd_flag_fifo_mode(data)                        ((0x00000200&(data))>>9)
#define  VODMA_vodma_i2rnd_get_i2rnd_flag_fifo_en(data)                          ((0x00000100&(data))>>8)
#define  VODMA_vodma_i2rnd_get_debug_mask_main(data)                             ((0x00000080&(data))>>7)
#define  VODMA_vodma_i2rnd_get_debug_mask_sub1(data)                             ((0x00000040&(data))>>6)
#define  VODMA_vodma_i2rnd_get_debug_mask_sub2(data)                             ((0x00000020&(data))>>5)
#define  VODMA_vodma_i2rnd_get_debug_mask_repeat_sub_old_en(data)                ((0x00000010&(data))>>4)
#define  VODMA_vodma_i2rnd_get_i2rnd_src_flag_inv(data)                          ((0x00000008&(data))>>3)
#define  VODMA_vodma_i2rnd_get_i2rnd_timing_mode(data)                           ((0x00000006&(data))>>1)
#define  VODMA_vodma_i2rnd_get_i2rnd_timing_en(data)                             (0x00000001&(data))

#define  VODMA_vodma_i2rnd_m_flag                                                0x18005204
#define  VODMA_vodma_i2rnd_m_flag_reg_addr                                       "0xB8005204"
#define  VODMA_vodma_i2rnd_m_flag_reg                                            0xB8005204
#define  VODMA_vodma_i2rnd_m_flag_inst_addr                                      "0x006D"
#define  set_VODMA_vodma_i2rnd_m_flag_reg(data)                                  (*((volatile unsigned int*)VODMA_vodma_i2rnd_m_flag_reg)=data)
#define  get_VODMA_vodma_i2rnd_m_flag_reg                                        (*((volatile unsigned int*)VODMA_vodma_i2rnd_m_flag_reg))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_hw_mask_repeat_frame_m_en_shift          (31)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_hw_nxt_rpt_flag_m_en_shift               (30)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_quincunx_sel_shift                     (28)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_quincunx_fw_shift                      (24)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_nxt_rpt_flag_fw_shift                  (23)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_nxt_rpt_flag_sel_shift                 (22)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_block_fw_shift                         (20)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_block_free_run_shift                   (19)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_block_sel_shift                        (16)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_field_fw_shift                         (12)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_field_free_run_shift                   (11)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_field_sel_shift                        (8)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_lflag_fw_shift                         (4)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_lflag_free_run_shift                   (3)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_lflag_sel_shift                        (0)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_hw_mask_repeat_frame_m_en_mask           (0x80000000)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_hw_nxt_rpt_flag_m_en_mask                (0x40000000)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_quincunx_sel_mask                      (0x10000000)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_quincunx_fw_mask                       (0x0F000000)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_nxt_rpt_flag_fw_mask                   (0x00800000)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_nxt_rpt_flag_sel_mask                  (0x00400000)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_block_fw_mask                          (0x00300000)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_block_free_run_mask                    (0x00080000)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_block_sel_mask                         (0x00070000)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_field_fw_mask                          (0x00001000)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_field_free_run_mask                    (0x00000800)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_field_sel_mask                         (0x00000700)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_lflag_fw_mask                          (0x00000010)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_lflag_free_run_mask                    (0x00000008)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_lflag_sel_mask                         (0x00000007)
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_hw_mask_repeat_frame_m_en(data)          (0x80000000&((data)<<31))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_hw_nxt_rpt_flag_m_en(data)               (0x40000000&((data)<<30))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_quincunx_sel(data)                     (0x10000000&((data)<<28))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_quincunx_fw(data)                      (0x0F000000&((data)<<24))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_nxt_rpt_flag_fw(data)                  (0x00800000&((data)<<23))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_nxt_rpt_flag_sel(data)                 (0x00400000&((data)<<22))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_block_fw(data)                         (0x00300000&((data)<<20))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_block_free_run(data)                   (0x00080000&((data)<<19))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_block_sel(data)                        (0x00070000&((data)<<16))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_field_fw(data)                         (0x00001000&((data)<<12))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_field_free_run(data)                   (0x00000800&((data)<<11))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_field_sel(data)                        (0x00000700&((data)<<8))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_lflag_fw(data)                         (0x00000010&((data)<<4))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_lflag_free_run(data)                   (0x00000008&((data)<<3))
#define  VODMA_vodma_i2rnd_m_flag_i2rnd_m_lflag_sel(data)                        (0x00000007&(data))
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_hw_mask_repeat_frame_m_en(data)      ((0x80000000&(data))>>31)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_hw_nxt_rpt_flag_m_en(data)           ((0x40000000&(data))>>30)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_m_quincunx_sel(data)                 ((0x10000000&(data))>>28)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_m_quincunx_fw(data)                  ((0x0F000000&(data))>>24)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_m_nxt_rpt_flag_fw(data)              ((0x00800000&(data))>>23)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_m_nxt_rpt_flag_sel(data)             ((0x00400000&(data))>>22)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_m_block_fw(data)                     ((0x00300000&(data))>>20)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_m_block_free_run(data)               ((0x00080000&(data))>>19)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_m_block_sel(data)                    ((0x00070000&(data))>>16)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_m_field_fw(data)                     ((0x00001000&(data))>>12)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_m_field_free_run(data)               ((0x00000800&(data))>>11)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_m_field_sel(data)                    ((0x00000700&(data))>>8)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_m_lflag_fw(data)                     ((0x00000010&(data))>>4)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_m_lflag_free_run(data)               ((0x00000008&(data))>>3)
#define  VODMA_vodma_i2rnd_m_flag_get_i2rnd_m_lflag_sel(data)                    (0x00000007&(data))

#define  VODMA_vodma_i2rnd_s_flag                                                0x18005208
#define  VODMA_vodma_i2rnd_s_flag_reg_addr                                       "0xB8005208"
#define  VODMA_vodma_i2rnd_s_flag_reg                                            0xB8005208
#define  VODMA_vodma_i2rnd_s_flag_inst_addr                                      "0x006E"
#define  set_VODMA_vodma_i2rnd_s_flag_reg(data)                                  (*((volatile unsigned int*)VODMA_vodma_i2rnd_s_flag_reg)=data)
#define  get_VODMA_vodma_i2rnd_s_flag_reg                                        (*((volatile unsigned int*)VODMA_vodma_i2rnd_s_flag_reg))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_hw_mask_repeat_frame_s_en_shift          (31)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_hw_nxt_rpt_flag_s_en_shift               (30)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_quincunx_sel_shift                     (28)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_quincunx_fw_shift                      (24)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_nxt_rpt_flag_fw_shift                  (23)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_nxt_rpt_flag_sel_shift                 (22)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_block_fw_shift                         (20)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_block_free_run_shift                   (19)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_block_sel_shift                        (16)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_field_fw_shift                         (12)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_field_free_run_shift                   (11)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_field_sel_shift                        (8)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_lflag_fw_shift                         (4)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_lflag_free_run_shift                   (3)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_lflag_sel_shift                        (0)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_hw_mask_repeat_frame_s_en_mask           (0x80000000)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_hw_nxt_rpt_flag_s_en_mask                (0x40000000)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_quincunx_sel_mask                      (0x10000000)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_quincunx_fw_mask                       (0x0F000000)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_nxt_rpt_flag_fw_mask                   (0x00800000)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_nxt_rpt_flag_sel_mask                  (0x00400000)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_block_fw_mask                          (0x00300000)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_block_free_run_mask                    (0x00080000)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_block_sel_mask                         (0x00070000)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_field_fw_mask                          (0x00001000)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_field_free_run_mask                    (0x00000800)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_field_sel_mask                         (0x00000700)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_lflag_fw_mask                          (0x00000010)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_lflag_free_run_mask                    (0x00000008)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_lflag_sel_mask                         (0x00000007)
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_hw_mask_repeat_frame_s_en(data)          (0x80000000&((data)<<31))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_hw_nxt_rpt_flag_s_en(data)               (0x40000000&((data)<<30))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_quincunx_sel(data)                     (0x10000000&((data)<<28))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_quincunx_fw(data)                      (0x0F000000&((data)<<24))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_nxt_rpt_flag_fw(data)                  (0x00800000&((data)<<23))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_nxt_rpt_flag_sel(data)                 (0x00400000&((data)<<22))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_block_fw(data)                         (0x00300000&((data)<<20))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_block_free_run(data)                   (0x00080000&((data)<<19))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_block_sel(data)                        (0x00070000&((data)<<16))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_field_fw(data)                         (0x00001000&((data)<<12))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_field_free_run(data)                   (0x00000800&((data)<<11))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_field_sel(data)                        (0x00000700&((data)<<8))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_lflag_fw(data)                         (0x00000010&((data)<<4))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_lflag_free_run(data)                   (0x00000008&((data)<<3))
#define  VODMA_vodma_i2rnd_s_flag_i2rnd_s_lflag_sel(data)                        (0x00000007&(data))
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_hw_mask_repeat_frame_s_en(data)      ((0x80000000&(data))>>31)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_hw_nxt_rpt_flag_s_en(data)           ((0x40000000&(data))>>30)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_s_quincunx_sel(data)                 ((0x10000000&(data))>>28)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_s_quincunx_fw(data)                  ((0x0F000000&(data))>>24)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_s_nxt_rpt_flag_fw(data)              ((0x00800000&(data))>>23)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_s_nxt_rpt_flag_sel(data)             ((0x00400000&(data))>>22)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_s_block_fw(data)                     ((0x00300000&(data))>>20)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_s_block_free_run(data)               ((0x00080000&(data))>>19)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_s_block_sel(data)                    ((0x00070000&(data))>>16)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_s_field_fw(data)                     ((0x00001000&(data))>>12)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_s_field_free_run(data)               ((0x00000800&(data))>>11)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_s_field_sel(data)                    ((0x00000700&(data))>>8)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_s_lflag_fw(data)                     ((0x00000010&(data))>>4)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_s_lflag_free_run(data)               ((0x00000008&(data))>>3)
#define  VODMA_vodma_i2rnd_s_flag_get_i2rnd_s_lflag_sel(data)                    (0x00000007&(data))

#define  VODMA_vodma_i2rnd_irq_en                                                0x1800520C
#define  VODMA_vodma_i2rnd_irq_en_reg_addr                                       "0xB800520C"
#define  VODMA_vodma_i2rnd_irq_en_reg                                            0xB800520C
#define  VODMA_vodma_i2rnd_irq_en_inst_addr                                      "0x006F"
#define  set_VODMA_vodma_i2rnd_irq_en_reg(data)                                  (*((volatile unsigned int*)VODMA_vodma_i2rnd_irq_en_reg)=data)
#define  get_VODMA_vodma_i2rnd_irq_en_reg                                        (*((volatile unsigned int*)VODMA_vodma_i2rnd_irq_en_reg))
#define  VODMA_vodma_i2rnd_irq_en_i2rnd_load_hit_den_irq_en_shift                (3)
#define  VODMA_vodma_i2rnd_irq_en_i2rnd_s_load_over_max_irq_en_shift             (2)
#define  VODMA_vodma_i2rnd_irq_en_i2rnd_m_load_over_max_irq_en_shift             (1)
#define  VODMA_vodma_i2rnd_irq_en_i2rnd_not_finish_irq_en_shift                  (0)
#define  VODMA_vodma_i2rnd_irq_en_i2rnd_load_hit_den_irq_en_mask                 (0x00000008)
#define  VODMA_vodma_i2rnd_irq_en_i2rnd_s_load_over_max_irq_en_mask              (0x00000004)
#define  VODMA_vodma_i2rnd_irq_en_i2rnd_m_load_over_max_irq_en_mask              (0x00000002)
#define  VODMA_vodma_i2rnd_irq_en_i2rnd_not_finish_irq_en_mask                   (0x00000001)
#define  VODMA_vodma_i2rnd_irq_en_i2rnd_load_hit_den_irq_en(data)                (0x00000008&((data)<<3))
#define  VODMA_vodma_i2rnd_irq_en_i2rnd_s_load_over_max_irq_en(data)             (0x00000004&((data)<<2))
#define  VODMA_vodma_i2rnd_irq_en_i2rnd_m_load_over_max_irq_en(data)             (0x00000002&((data)<<1))
#define  VODMA_vodma_i2rnd_irq_en_i2rnd_not_finish_irq_en(data)                  (0x00000001&(data))
#define  VODMA_vodma_i2rnd_irq_en_get_i2rnd_load_hit_den_irq_en(data)            ((0x00000008&(data))>>3)
#define  VODMA_vodma_i2rnd_irq_en_get_i2rnd_s_load_over_max_irq_en(data)         ((0x00000004&(data))>>2)
#define  VODMA_vodma_i2rnd_irq_en_get_i2rnd_m_load_over_max_irq_en(data)         ((0x00000002&(data))>>1)
#define  VODMA_vodma_i2rnd_irq_en_get_i2rnd_not_finish_irq_en(data)              (0x00000001&(data))

#define  VODMA_vodma_i2rnd_irq_st                                                0x18005210
#define  VODMA_vodma_i2rnd_irq_st_reg_addr                                       "0xB8005210"
#define  VODMA_vodma_i2rnd_irq_st_reg                                            0xB8005210
#define  VODMA_vodma_i2rnd_irq_st_inst_addr                                      "0x0070"
#define  set_VODMA_vodma_i2rnd_irq_st_reg(data)                                  (*((volatile unsigned int*)VODMA_vodma_i2rnd_irq_st_reg)=data)
#define  get_VODMA_vodma_i2rnd_irq_st_reg                                        (*((volatile unsigned int*)VODMA_vodma_i2rnd_irq_st_reg))
#define  VODMA_vodma_i2rnd_irq_st_i2rnd_load_hit_den_irq_st_shift                (3)
#define  VODMA_vodma_i2rnd_irq_st_i2rnd_s_load_over_max_irq_st_shift             (2)
#define  VODMA_vodma_i2rnd_irq_st_i2rnd_m_load_over_max_irq_st_shift             (1)
#define  VODMA_vodma_i2rnd_irq_st_i2rnd_not_finish_irq_st_shift                  (0)
#define  VODMA_vodma_i2rnd_irq_st_i2rnd_load_hit_den_irq_st_mask                 (0x00000008)
#define  VODMA_vodma_i2rnd_irq_st_i2rnd_s_load_over_max_irq_st_mask              (0x00000004)
#define  VODMA_vodma_i2rnd_irq_st_i2rnd_m_load_over_max_irq_st_mask              (0x00000002)
#define  VODMA_vodma_i2rnd_irq_st_i2rnd_not_finish_irq_st_mask                   (0x00000001)
#define  VODMA_vodma_i2rnd_irq_st_i2rnd_load_hit_den_irq_st(data)                (0x00000008&((data)<<3))
#define  VODMA_vodma_i2rnd_irq_st_i2rnd_s_load_over_max_irq_st(data)             (0x00000004&((data)<<2))
#define  VODMA_vodma_i2rnd_irq_st_i2rnd_m_load_over_max_irq_st(data)             (0x00000002&((data)<<1))
#define  VODMA_vodma_i2rnd_irq_st_i2rnd_not_finish_irq_st(data)                  (0x00000001&(data))
#define  VODMA_vodma_i2rnd_irq_st_get_i2rnd_load_hit_den_irq_st(data)            ((0x00000008&(data))>>3)
#define  VODMA_vodma_i2rnd_irq_st_get_i2rnd_s_load_over_max_irq_st(data)         ((0x00000004&(data))>>2)
#define  VODMA_vodma_i2rnd_irq_st_get_i2rnd_m_load_over_max_irq_st(data)         ((0x00000002&(data))>>1)
#define  VODMA_vodma_i2rnd_irq_st_get_i2rnd_not_finish_irq_st(data)              (0x00000001&(data))

#define  VODMA_vodma_i2rnd_measure_frame                                         0x18005214
#define  VODMA_vodma_i2rnd_measure_frame_reg_addr                                "0xB8005214"
#define  VODMA_vodma_i2rnd_measure_frame_reg                                     0xB8005214
#define  VODMA_vodma_i2rnd_measure_frame_inst_addr                               "0x0071"
#define  set_VODMA_vodma_i2rnd_measure_frame_reg(data)                           (*((volatile unsigned int*)VODMA_vodma_i2rnd_measure_frame_reg)=data)
#define  get_VODMA_vodma_i2rnd_measure_frame_reg                                 (*((volatile unsigned int*)VODMA_vodma_i2rnd_measure_frame_reg))
#define  VODMA_vodma_i2rnd_measure_frame_i2rnd_frame_measure_shift               (31)
#define  VODMA_vodma_i2rnd_measure_frame_i2rnd_ori_frame_cnt_shift               (16)
#define  VODMA_vodma_i2rnd_measure_frame_i2rnd_s_mask_frame_cnt_shift            (8)
#define  VODMA_vodma_i2rnd_measure_frame_i2rnd_m_mask_frame_cnt_shift            (0)
#define  VODMA_vodma_i2rnd_measure_frame_i2rnd_frame_measure_mask                (0x80000000)
#define  VODMA_vodma_i2rnd_measure_frame_i2rnd_ori_frame_cnt_mask                (0x0FFF0000)
#define  VODMA_vodma_i2rnd_measure_frame_i2rnd_s_mask_frame_cnt_mask             (0x0000FF00)
#define  VODMA_vodma_i2rnd_measure_frame_i2rnd_m_mask_frame_cnt_mask             (0x000000FF)
#define  VODMA_vodma_i2rnd_measure_frame_i2rnd_frame_measure(data)               (0x80000000&((data)<<31))
#define  VODMA_vodma_i2rnd_measure_frame_i2rnd_ori_frame_cnt(data)               (0x0FFF0000&((data)<<16))
#define  VODMA_vodma_i2rnd_measure_frame_i2rnd_s_mask_frame_cnt(data)            (0x0000FF00&((data)<<8))
#define  VODMA_vodma_i2rnd_measure_frame_i2rnd_m_mask_frame_cnt(data)            (0x000000FF&(data))
#define  VODMA_vodma_i2rnd_measure_frame_get_i2rnd_frame_measure(data)           ((0x80000000&(data))>>31)
#define  VODMA_vodma_i2rnd_measure_frame_get_i2rnd_ori_frame_cnt(data)           ((0x0FFF0000&(data))>>16)
#define  VODMA_vodma_i2rnd_measure_frame_get_i2rnd_s_mask_frame_cnt(data)        ((0x0000FF00&(data))>>8)
#define  VODMA_vodma_i2rnd_measure_frame_get_i2rnd_m_mask_frame_cnt(data)        (0x000000FF&(data))

#define  VODMA_vodma_i2rnd_fifo_st                                               0x18005218
#define  VODMA_vodma_i2rnd_fifo_st_reg_addr                                      "0xB8005218"
#define  VODMA_vodma_i2rnd_fifo_st_reg                                           0xB8005218
#define  VODMA_vodma_i2rnd_fifo_st_inst_addr                                     "0x0072"
#define  set_VODMA_vodma_i2rnd_fifo_st_reg(data)                                 (*((volatile unsigned int*)VODMA_vodma_i2rnd_fifo_st_reg)=data)
#define  get_VODMA_vodma_i2rnd_fifo_st_reg                                       (*((volatile unsigned int*)VODMA_vodma_i2rnd_fifo_st_reg))
#define  VODMA_vodma_i2rnd_fifo_st_info_i3ddma_overflow_shift                    (31)
#define  VODMA_vodma_i2rnd_fifo_st_info_dispm_overflow_shift                     (30)
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_water_i3ddma_shift                   (20)
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_water_dispm_shift                    (16)
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_wptr_i3ddma_shift                    (12)
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_rptr_i3ddma_shift                    (8)
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_wptr_dispm_shift                     (4)
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_rptr_dispm_shift                     (0)
#define  VODMA_vodma_i2rnd_fifo_st_info_i3ddma_overflow_mask                     (0x80000000)
#define  VODMA_vodma_i2rnd_fifo_st_info_dispm_overflow_mask                      (0x40000000)
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_water_i3ddma_mask                    (0x00F00000)
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_water_dispm_mask                     (0x000F0000)
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_wptr_i3ddma_mask                     (0x0000F000)
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_rptr_i3ddma_mask                     (0x00000F00)
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_wptr_dispm_mask                      (0x000000F0)
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_rptr_dispm_mask                      (0x0000000F)
#define  VODMA_vodma_i2rnd_fifo_st_info_i3ddma_overflow(data)                    (0x80000000&((data)<<31))
#define  VODMA_vodma_i2rnd_fifo_st_info_dispm_overflow(data)                     (0x40000000&((data)<<30))
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_water_i3ddma(data)                   (0x00F00000&((data)<<20))
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_water_dispm(data)                    (0x000F0000&((data)<<16))
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_wptr_i3ddma(data)                    (0x0000F000&((data)<<12))
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_rptr_i3ddma(data)                    (0x00000F00&((data)<<8))
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_wptr_dispm(data)                     (0x000000F0&((data)<<4))
#define  VODMA_vodma_i2rnd_fifo_st_dma_info_rptr_dispm(data)                     (0x0000000F&(data))
#define  VODMA_vodma_i2rnd_fifo_st_get_info_i3ddma_overflow(data)                ((0x80000000&(data))>>31)
#define  VODMA_vodma_i2rnd_fifo_st_get_info_dispm_overflow(data)                 ((0x40000000&(data))>>30)
#define  VODMA_vodma_i2rnd_fifo_st_get_dma_info_water_i3ddma(data)               ((0x00F00000&(data))>>20)
#define  VODMA_vodma_i2rnd_fifo_st_get_dma_info_water_dispm(data)                ((0x000F0000&(data))>>16)
#define  VODMA_vodma_i2rnd_fifo_st_get_dma_info_wptr_i3ddma(data)                ((0x0000F000&(data))>>12)
#define  VODMA_vodma_i2rnd_fifo_st_get_dma_info_rptr_i3ddma(data)                ((0x00000F00&(data))>>8)
#define  VODMA_vodma_i2rnd_fifo_st_get_dma_info_wptr_dispm(data)                 ((0x000000F0&(data))>>4)
#define  VODMA_vodma_i2rnd_fifo_st_get_dma_info_rptr_dispm(data)                 (0x0000000F&(data))

#define  VODMA_vodma_i2rnd_st                                                    0x1800521C
#define  VODMA_vodma_i2rnd_st_reg_addr                                           "0xB800521C"
#define  VODMA_vodma_i2rnd_st_reg                                                0xB800521C
#define  VODMA_vodma_i2rnd_st_inst_addr                                          "0x0073"
#define  set_VODMA_vodma_i2rnd_st_reg(data)                                      (*((volatile unsigned int*)VODMA_vodma_i2rnd_st_reg)=data)
#define  get_VODMA_vodma_i2rnd_st_reg                                            (*((volatile unsigned int*)VODMA_vodma_i2rnd_st_reg))
#define  VODMA_vodma_i2rnd_st_i2rnd_s_nxt_rpt_flag_shift                         (30)
#define  VODMA_vodma_i2rnd_st_i2rnd_m_nxt_rpt_flag_shift                         (29)
#define  VODMA_vodma_i2rnd_st_i2rnd_nxt_rpt_flag_shift                           (28)
#define  VODMA_vodma_i2rnd_st_i2rnd_s_quincunx_shift                             (24)
#define  VODMA_vodma_i2rnd_st_i2rnd_m_quincunx_shift                             (20)
#define  VODMA_vodma_i2rnd_st_i2rnd_quincunx_shift                               (16)
#define  VODMA_vodma_i2rnd_st_i2rnd_s_block_shift                                (14)
#define  VODMA_vodma_i2rnd_st_i2rnd_s_field_shift                                (13)
#define  VODMA_vodma_i2rnd_st_i2rnd_s_lflag_shift                                (12)
#define  VODMA_vodma_i2rnd_st_i2rnd_m_block_shift                                (10)
#define  VODMA_vodma_i2rnd_st_i2rnd_m_field_shift                                (9)
#define  VODMA_vodma_i2rnd_st_i2rnd_m_lflag_shift                                (8)
#define  VODMA_vodma_i2rnd_st_i2rnd_block_shift                                  (6)
#define  VODMA_vodma_i2rnd_st_i2rnd_field_shift                                  (5)
#define  VODMA_vodma_i2rnd_st_i2rnd_lflag_shift                                  (4)
#define  VODMA_vodma_i2rnd_st_i2rnd_src_flag_shift                               (3)
#define  VODMA_vodma_i2rnd_st_i2rnd_st_shift                                     (0)
#define  VODMA_vodma_i2rnd_st_i2rnd_s_nxt_rpt_flag_mask                          (0x40000000)
#define  VODMA_vodma_i2rnd_st_i2rnd_m_nxt_rpt_flag_mask                          (0x20000000)
#define  VODMA_vodma_i2rnd_st_i2rnd_nxt_rpt_flag_mask                            (0x10000000)
#define  VODMA_vodma_i2rnd_st_i2rnd_s_quincunx_mask                              (0x0F000000)
#define  VODMA_vodma_i2rnd_st_i2rnd_m_quincunx_mask                              (0x00F00000)
#define  VODMA_vodma_i2rnd_st_i2rnd_quincunx_mask                                (0x000F0000)
#define  VODMA_vodma_i2rnd_st_i2rnd_s_block_mask                                 (0x0000C000)
#define  VODMA_vodma_i2rnd_st_i2rnd_s_field_mask                                 (0x00002000)
#define  VODMA_vodma_i2rnd_st_i2rnd_s_lflag_mask                                 (0x00001000)
#define  VODMA_vodma_i2rnd_st_i2rnd_m_block_mask                                 (0x00000C00)
#define  VODMA_vodma_i2rnd_st_i2rnd_m_field_mask                                 (0x00000200)
#define  VODMA_vodma_i2rnd_st_i2rnd_m_lflag_mask                                 (0x00000100)
#define  VODMA_vodma_i2rnd_st_i2rnd_block_mask                                   (0x000000C0)
#define  VODMA_vodma_i2rnd_st_i2rnd_field_mask                                   (0x00000020)
#define  VODMA_vodma_i2rnd_st_i2rnd_lflag_mask                                   (0x00000010)
#define  VODMA_vodma_i2rnd_st_i2rnd_src_flag_mask                                (0x00000008)
#define  VODMA_vodma_i2rnd_st_i2rnd_st_mask                                      (0x00000007)
#define  VODMA_vodma_i2rnd_st_i2rnd_s_nxt_rpt_flag(data)                         (0x40000000&((data)<<30))
#define  VODMA_vodma_i2rnd_st_i2rnd_m_nxt_rpt_flag(data)                         (0x20000000&((data)<<29))
#define  VODMA_vodma_i2rnd_st_i2rnd_nxt_rpt_flag(data)                           (0x10000000&((data)<<28))
#define  VODMA_vodma_i2rnd_st_i2rnd_s_quincunx(data)                             (0x0F000000&((data)<<24))
#define  VODMA_vodma_i2rnd_st_i2rnd_m_quincunx(data)                             (0x00F00000&((data)<<20))
#define  VODMA_vodma_i2rnd_st_i2rnd_quincunx(data)                               (0x000F0000&((data)<<16))
#define  VODMA_vodma_i2rnd_st_i2rnd_s_block(data)                                (0x0000C000&((data)<<14))
#define  VODMA_vodma_i2rnd_st_i2rnd_s_field(data)                                (0x00002000&((data)<<13))
#define  VODMA_vodma_i2rnd_st_i2rnd_s_lflag(data)                                (0x00001000&((data)<<12))
#define  VODMA_vodma_i2rnd_st_i2rnd_m_block(data)                                (0x00000C00&((data)<<10))
#define  VODMA_vodma_i2rnd_st_i2rnd_m_field(data)                                (0x00000200&((data)<<9))
#define  VODMA_vodma_i2rnd_st_i2rnd_m_lflag(data)                                (0x00000100&((data)<<8))
#define  VODMA_vodma_i2rnd_st_i2rnd_block(data)                                  (0x000000C0&((data)<<6))
#define  VODMA_vodma_i2rnd_st_i2rnd_field(data)                                  (0x00000020&((data)<<5))
#define  VODMA_vodma_i2rnd_st_i2rnd_lflag(data)                                  (0x00000010&((data)<<4))
#define  VODMA_vodma_i2rnd_st_i2rnd_src_flag(data)                               (0x00000008&((data)<<3))
#define  VODMA_vodma_i2rnd_st_i2rnd_st(data)                                     (0x00000007&(data))
#define  VODMA_vodma_i2rnd_st_get_i2rnd_s_nxt_rpt_flag(data)                     ((0x40000000&(data))>>30)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_m_nxt_rpt_flag(data)                     ((0x20000000&(data))>>29)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_nxt_rpt_flag(data)                       ((0x10000000&(data))>>28)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_s_quincunx(data)                         ((0x0F000000&(data))>>24)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_m_quincunx(data)                         ((0x00F00000&(data))>>20)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_quincunx(data)                           ((0x000F0000&(data))>>16)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_s_block(data)                            ((0x0000C000&(data))>>14)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_s_field(data)                            ((0x00002000&(data))>>13)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_s_lflag(data)                            ((0x00001000&(data))>>12)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_m_block(data)                            ((0x00000C00&(data))>>10)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_m_field(data)                            ((0x00000200&(data))>>9)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_m_lflag(data)                            ((0x00000100&(data))>>8)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_block(data)                              ((0x000000C0&(data))>>6)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_field(data)                              ((0x00000020&(data))>>5)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_lflag(data)                              ((0x00000010&(data))>>4)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_src_flag(data)                           ((0x00000008&(data))>>3)
#define  VODMA_vodma_i2rnd_st_get_i2rnd_st(data)                                 (0x00000007&(data))

#define  VODMA_vodma_i2rnd_fifo_th                                               0x18005220
#define  VODMA_vodma_i2rnd_fifo_th_reg_addr                                      "0xB8005220"
#define  VODMA_vodma_i2rnd_fifo_th_reg                                           0xB8005220
#define  VODMA_vodma_i2rnd_fifo_th_inst_addr                                     "0x0074"
#define  set_VODMA_vodma_i2rnd_fifo_th_reg(data)                                 (*((volatile unsigned int*)VODMA_vodma_i2rnd_fifo_th_reg)=data)
#define  get_VODMA_vodma_i2rnd_fifo_th_reg                                       (*((volatile unsigned int*)VODMA_vodma_i2rnd_fifo_th_reg))
#define  VODMA_vodma_i2rnd_fifo_th_flag_fifo_style_i3ddma_shift                  (31)
#define  VODMA_vodma_i2rnd_fifo_th_flag_fifo_style_dispm_shift                   (30)
#define  VODMA_vodma_i2rnd_fifo_th_dram_buf_num_i3ddma_shift                     (12)
#define  VODMA_vodma_i2rnd_fifo_th_dram_buf_num_dispm_shift                      (8)
#define  VODMA_vodma_i2rnd_fifo_th_dma_info_th_i3ddma_shift                      (4)
#define  VODMA_vodma_i2rnd_fifo_th_dma_info_th_dispm_shift                       (0)
#define  VODMA_vodma_i2rnd_fifo_th_flag_fifo_style_i3ddma_mask                   (0x80000000)
#define  VODMA_vodma_i2rnd_fifo_th_flag_fifo_style_dispm_mask                    (0x40000000)
#define  VODMA_vodma_i2rnd_fifo_th_dram_buf_num_i3ddma_mask                      (0x0000F000)
#define  VODMA_vodma_i2rnd_fifo_th_dram_buf_num_dispm_mask                       (0x00000F00)
#define  VODMA_vodma_i2rnd_fifo_th_dma_info_th_i3ddma_mask                       (0x000000F0)
#define  VODMA_vodma_i2rnd_fifo_th_dma_info_th_dispm_mask                        (0x0000000F)
#define  VODMA_vodma_i2rnd_fifo_th_flag_fifo_style_i3ddma(data)                  (0x80000000&((data)<<31))
#define  VODMA_vodma_i2rnd_fifo_th_flag_fifo_style_dispm(data)                   (0x40000000&((data)<<30))
#define  VODMA_vodma_i2rnd_fifo_th_dram_buf_num_i3ddma(data)                     (0x0000F000&((data)<<12))
#define  VODMA_vodma_i2rnd_fifo_th_dram_buf_num_dispm(data)                      (0x00000F00&((data)<<8))
#define  VODMA_vodma_i2rnd_fifo_th_dma_info_th_i3ddma(data)                      (0x000000F0&((data)<<4))
#define  VODMA_vodma_i2rnd_fifo_th_dma_info_th_dispm(data)                       (0x0000000F&(data))
#define  VODMA_vodma_i2rnd_fifo_th_get_flag_fifo_style_i3ddma(data)              ((0x80000000&(data))>>31)
#define  VODMA_vodma_i2rnd_fifo_th_get_flag_fifo_style_dispm(data)               ((0x40000000&(data))>>30)
#define  VODMA_vodma_i2rnd_fifo_th_get_dram_buf_num_i3ddma(data)                 ((0x0000F000&(data))>>12)
#define  VODMA_vodma_i2rnd_fifo_th_get_dram_buf_num_dispm(data)                  ((0x00000F00&(data))>>8)
#define  VODMA_vodma_i2rnd_fifo_th_get_dma_info_th_i3ddma(data)                  ((0x000000F0&(data))>>4)
#define  VODMA_vodma_i2rnd_fifo_th_get_dma_info_th_dispm(data)                   (0x0000000F&(data))

#define  VODMA_vodma_i2rnd_dma_info                                              0x18005230
#define  VODMA_vodma_i2rnd_dma_info_reg_addr                                     "0xB8005230"
#define  VODMA_vodma_i2rnd_dma_info_reg                                          0xB8005230
#define  VODMA_vodma_i2rnd_dma_info_inst_addr                                    "0x0075"
#define  set_VODMA_vodma_i2rnd_dma_info_reg(data)                                (*((volatile unsigned int*)VODMA_vodma_i2rnd_dma_info_reg)=data)
#define  get_VODMA_vodma_i2rnd_dma_info_reg                                      (*((volatile unsigned int*)VODMA_vodma_i2rnd_dma_info_reg))
#define  VODMA_vodma_i2rnd_dma_info_dma_info_wptr_fw_set_dispm_shift             (28)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_wptr_fw_dispm_shift                 (24)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_wptr_fw_set_i3ddma_shift            (20)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_wptr_fw_i3ddma_shift                (16)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_rptr_fw_set_dispm_shift             (12)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_rptr_fw_dispm_shift                 (8)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_rptr_fw_set_i3ddma_shift            (4)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_rptr_fw_i3ddma_shift                (0)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_wptr_fw_set_dispm_mask              (0x10000000)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_wptr_fw_dispm_mask                  (0x0F000000)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_wptr_fw_set_i3ddma_mask             (0x00100000)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_wptr_fw_i3ddma_mask                 (0x000F0000)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_rptr_fw_set_dispm_mask              (0x00001000)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_rptr_fw_dispm_mask                  (0x00000F00)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_rptr_fw_set_i3ddma_mask             (0x00000010)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_rptr_fw_i3ddma_mask                 (0x0000000F)
#define  VODMA_vodma_i2rnd_dma_info_dma_info_wptr_fw_set_dispm(data)             (0x10000000&((data)<<28))
#define  VODMA_vodma_i2rnd_dma_info_dma_info_wptr_fw_dispm(data)                 (0x0F000000&((data)<<24))
#define  VODMA_vodma_i2rnd_dma_info_dma_info_wptr_fw_set_i3ddma(data)            (0x00100000&((data)<<20))
#define  VODMA_vodma_i2rnd_dma_info_dma_info_wptr_fw_i3ddma(data)                (0x000F0000&((data)<<16))
#define  VODMA_vodma_i2rnd_dma_info_dma_info_rptr_fw_set_dispm(data)             (0x00001000&((data)<<12))
#define  VODMA_vodma_i2rnd_dma_info_dma_info_rptr_fw_dispm(data)                 (0x00000F00&((data)<<8))
#define  VODMA_vodma_i2rnd_dma_info_dma_info_rptr_fw_set_i3ddma(data)            (0x00000010&((data)<<4))
#define  VODMA_vodma_i2rnd_dma_info_dma_info_rptr_fw_i3ddma(data)                (0x0000000F&(data))
#define  VODMA_vodma_i2rnd_dma_info_get_dma_info_wptr_fw_set_dispm(data)         ((0x10000000&(data))>>28)
#define  VODMA_vodma_i2rnd_dma_info_get_dma_info_wptr_fw_dispm(data)             ((0x0F000000&(data))>>24)
#define  VODMA_vodma_i2rnd_dma_info_get_dma_info_wptr_fw_set_i3ddma(data)        ((0x00100000&(data))>>20)
#define  VODMA_vodma_i2rnd_dma_info_get_dma_info_wptr_fw_i3ddma(data)            ((0x000F0000&(data))>>16)
#define  VODMA_vodma_i2rnd_dma_info_get_dma_info_rptr_fw_set_dispm(data)         ((0x00001000&(data))>>12)
#define  VODMA_vodma_i2rnd_dma_info_get_dma_info_rptr_fw_dispm(data)             ((0x00000F00&(data))>>8)
#define  VODMA_vodma_i2rnd_dma_info_get_dma_info_rptr_fw_set_i3ddma(data)        ((0x00000010&(data))>>4)
#define  VODMA_vodma_i2rnd_dma_info_get_dma_info_rptr_fw_i3ddma(data)            (0x0000000F&(data))

#define  VODMA_vodma_i2rnd_m_period_load                                         0x18005240
#define  VODMA_vodma_i2rnd_m_period_load_reg_addr                                "0xB8005240"
#define  VODMA_vodma_i2rnd_m_period_load_reg                                     0xB8005240
#define  VODMA_vodma_i2rnd_m_period_load_inst_addr                               "0x0076"
#define  set_VODMA_vodma_i2rnd_m_period_load_reg(data)                           (*((volatile unsigned int*)VODMA_vodma_i2rnd_m_period_load_reg)=data)
#define  get_VODMA_vodma_i2rnd_m_period_load_reg                                 (*((volatile unsigned int*)VODMA_vodma_i2rnd_m_period_load_reg))
#define  VODMA_vodma_i2rnd_m_period_load_i2rnd_period_clk_src_shift              (31)
#define  VODMA_vodma_i2rnd_m_period_load_i2rnd_m_period_load_shift               (0)
#define  VODMA_vodma_i2rnd_m_period_load_i2rnd_period_clk_src_mask               (0x80000000)
#define  VODMA_vodma_i2rnd_m_period_load_i2rnd_m_period_load_mask                (0x0FFFFFFF)
#define  VODMA_vodma_i2rnd_m_period_load_i2rnd_period_clk_src(data)              (0x80000000&((data)<<31))
#define  VODMA_vodma_i2rnd_m_period_load_i2rnd_m_period_load(data)               (0x0FFFFFFF&(data))
#define  VODMA_vodma_i2rnd_m_period_load_get_i2rnd_period_clk_src(data)          ((0x80000000&(data))>>31)
#define  VODMA_vodma_i2rnd_m_period_load_get_i2rnd_m_period_load(data)           (0x0FFFFFFF&(data))

#define  VODMA_vodma_i2rnd_m_period                                              0x18005244
#define  VODMA_vodma_i2rnd_m_period_reg_addr                                     "0xB8005244"
#define  VODMA_vodma_i2rnd_m_period_reg                                          0xB8005244
#define  VODMA_vodma_i2rnd_m_period_inst_addr                                    "0x0077"
#define  set_VODMA_vodma_i2rnd_m_period_reg(data)                                (*((volatile unsigned int*)VODMA_vodma_i2rnd_m_period_reg)=data)
#define  get_VODMA_vodma_i2rnd_m_period_reg                                      (*((volatile unsigned int*)VODMA_vodma_i2rnd_m_period_reg))
#define  VODMA_vodma_i2rnd_m_period_i2rnd_m_period_shift                         (0)
#define  VODMA_vodma_i2rnd_m_period_i2rnd_m_period_mask                          (0x0FFFFFFF)
#define  VODMA_vodma_i2rnd_m_period_i2rnd_m_period(data)                         (0x0FFFFFFF&(data))
#define  VODMA_vodma_i2rnd_m_period_get_i2rnd_m_period(data)                     (0x0FFFFFFF&(data))

#define  VODMA_vodma_i2rnd_s_period_load                                         0x18005248
#define  VODMA_vodma_i2rnd_s_period_load_reg_addr                                "0xB8005248"
#define  VODMA_vodma_i2rnd_s_period_load_reg                                     0xB8005248
#define  VODMA_vodma_i2rnd_s_period_load_inst_addr                               "0x0078"
#define  set_VODMA_vodma_i2rnd_s_period_load_reg(data)                           (*((volatile unsigned int*)VODMA_vodma_i2rnd_s_period_load_reg)=data)
#define  get_VODMA_vodma_i2rnd_s_period_load_reg                                 (*((volatile unsigned int*)VODMA_vodma_i2rnd_s_period_load_reg))
#define  VODMA_vodma_i2rnd_s_period_load_i2rnd_s_period_load_shift               (0)
#define  VODMA_vodma_i2rnd_s_period_load_i2rnd_s_period_load_mask                (0x0FFFFFFF)
#define  VODMA_vodma_i2rnd_s_period_load_i2rnd_s_period_load(data)               (0x0FFFFFFF&(data))
#define  VODMA_vodma_i2rnd_s_period_load_get_i2rnd_s_period_load(data)           (0x0FFFFFFF&(data))

#define  VODMA_vodma_i2rnd_s_period                                              0x1800524C
#define  VODMA_vodma_i2rnd_s_period_reg_addr                                     "0xB800524C"
#define  VODMA_vodma_i2rnd_s_period_reg                                          0xB800524C
#define  VODMA_vodma_i2rnd_s_period_inst_addr                                    "0x0079"
#define  set_VODMA_vodma_i2rnd_s_period_reg(data)                                (*((volatile unsigned int*)VODMA_vodma_i2rnd_s_period_reg)=data)
#define  get_VODMA_vodma_i2rnd_s_period_reg                                      (*((volatile unsigned int*)VODMA_vodma_i2rnd_s_period_reg))
#define  VODMA_vodma_i2rnd_s_period_i2rnd_s_period_shift                         (0)
#define  VODMA_vodma_i2rnd_s_period_i2rnd_s_period_mask                          (0x0FFFFFFF)
#define  VODMA_vodma_i2rnd_s_period_i2rnd_s_period(data)                         (0x0FFFFFFF&(data))
#define  VODMA_vodma_i2rnd_s_period_get_i2rnd_s_period(data)                     (0x0FFFFFFF&(data))

#define  VODMA_vodma_i2rnd_m_measure                                             0x18005250
#define  VODMA_vodma_i2rnd_m_measure_reg_addr                                    "0xB8005250"
#define  VODMA_vodma_i2rnd_m_measure_reg                                         0xB8005250
#define  VODMA_vodma_i2rnd_m_measure_inst_addr                                   "0x007A"
#define  set_VODMA_vodma_i2rnd_m_measure_reg(data)                               (*((volatile unsigned int*)VODMA_vodma_i2rnd_m_measure_reg)=data)
#define  get_VODMA_vodma_i2rnd_m_measure_reg                                     (*((volatile unsigned int*)VODMA_vodma_i2rnd_m_measure_reg))
#define  VODMA_vodma_i2rnd_m_measure_i2rnd_load_time_measure_shift               (31)
#define  VODMA_vodma_i2rnd_m_measure_i2rnd_load_time_measure_long_term_shift     (30)
#define  VODMA_vodma_i2rnd_m_measure_i2rnd_m_load_time_shift                     (0)
#define  VODMA_vodma_i2rnd_m_measure_i2rnd_load_time_measure_mask                (0x80000000)
#define  VODMA_vodma_i2rnd_m_measure_i2rnd_load_time_measure_long_term_mask      (0x40000000)
#define  VODMA_vodma_i2rnd_m_measure_i2rnd_m_load_time_mask                      (0x0FFFFFFF)
#define  VODMA_vodma_i2rnd_m_measure_i2rnd_load_time_measure(data)               (0x80000000&((data)<<31))
#define  VODMA_vodma_i2rnd_m_measure_i2rnd_load_time_measure_long_term(data)     (0x40000000&((data)<<30))
#define  VODMA_vodma_i2rnd_m_measure_i2rnd_m_load_time(data)                     (0x0FFFFFFF&(data))
#define  VODMA_vodma_i2rnd_m_measure_get_i2rnd_load_time_measure(data)           ((0x80000000&(data))>>31)
#define  VODMA_vodma_i2rnd_m_measure_get_i2rnd_load_time_measure_long_term(data) ((0x40000000&(data))>>30)
#define  VODMA_vodma_i2rnd_m_measure_get_i2rnd_m_load_time(data)                 (0x0FFFFFFF&(data))

#define  VODMA_vodma_i2rnd_s_measure                                             0x18005254
#define  VODMA_vodma_i2rnd_s_measure_reg_addr                                    "0xB8005254"
#define  VODMA_vodma_i2rnd_s_measure_reg                                         0xB8005254
#define  VODMA_vodma_i2rnd_s_measure_inst_addr                                   "0x007B"
#define  set_VODMA_vodma_i2rnd_s_measure_reg(data)                               (*((volatile unsigned int*)VODMA_vodma_i2rnd_s_measure_reg)=data)
#define  get_VODMA_vodma_i2rnd_s_measure_reg                                     (*((volatile unsigned int*)VODMA_vodma_i2rnd_s_measure_reg))
#define  VODMA_vodma_i2rnd_s_measure_i2rnd_s_load_time_shift                     (0)
#define  VODMA_vodma_i2rnd_s_measure_i2rnd_s_load_time_mask                      (0x0FFFFFFF)
#define  VODMA_vodma_i2rnd_s_measure_i2rnd_s_load_time(data)                     (0x0FFFFFFF&(data))
#define  VODMA_vodma_i2rnd_s_measure_get_i2rnd_s_load_time(data)                 (0x0FFFFFFF&(data))

#define  VODMA_vodma_i2rnd_m_period_load_dbg                                     0x18005258
#define  VODMA_vodma_i2rnd_m_period_load_dbg_reg_addr                            "0xB8005258"
#define  VODMA_vodma_i2rnd_m_period_load_dbg_reg                                 0xB8005258
#define  VODMA_vodma_i2rnd_m_period_load_dbg_inst_addr                           "0x007C"
#define  set_VODMA_vodma_i2rnd_m_period_load_dbg_reg(data)                       (*((volatile unsigned int*)VODMA_vodma_i2rnd_m_period_load_dbg_reg)=data)
#define  get_VODMA_vodma_i2rnd_m_period_load_dbg_reg                             (*((volatile unsigned int*)VODMA_vodma_i2rnd_m_period_load_dbg_reg))
#define  VODMA_vodma_i2rnd_m_period_load_dbg_i2rnd_period_load_max_measure_en_shift (31)
#define  VODMA_vodma_i2rnd_m_period_load_dbg_i2rnd_period_load_max_dbg_en_shift  (30)
#define  VODMA_vodma_i2rnd_m_period_load_dbg_i2rnd_m_period_load_max_shift       (0)
#define  VODMA_vodma_i2rnd_m_period_load_dbg_i2rnd_period_load_max_measure_en_mask (0x80000000)
#define  VODMA_vodma_i2rnd_m_period_load_dbg_i2rnd_period_load_max_dbg_en_mask   (0x40000000)
#define  VODMA_vodma_i2rnd_m_period_load_dbg_i2rnd_m_period_load_max_mask        (0x0FFFFFFF)
#define  VODMA_vodma_i2rnd_m_period_load_dbg_i2rnd_period_load_max_measure_en(data) (0x80000000&((data)<<31))
#define  VODMA_vodma_i2rnd_m_period_load_dbg_i2rnd_period_load_max_dbg_en(data)  (0x40000000&((data)<<30))
#define  VODMA_vodma_i2rnd_m_period_load_dbg_i2rnd_m_period_load_max(data)       (0x0FFFFFFF&(data))
#define  VODMA_vodma_i2rnd_m_period_load_dbg_get_i2rnd_period_load_max_measure_en(data) ((0x80000000&(data))>>31)
#define  VODMA_vodma_i2rnd_m_period_load_dbg_get_i2rnd_period_load_max_dbg_en(data) ((0x40000000&(data))>>30)
#define  VODMA_vodma_i2rnd_m_period_load_dbg_get_i2rnd_m_period_load_max(data)   (0x0FFFFFFF&(data))

#define  VODMA_vodma_i2rnd_s_period_load_dbg                                     0x1800525C
#define  VODMA_vodma_i2rnd_s_period_load_dbg_reg_addr                            "0xB800525C"
#define  VODMA_vodma_i2rnd_s_period_load_dbg_reg                                 0xB800525C
#define  VODMA_vodma_i2rnd_s_period_load_dbg_inst_addr                           "0x007D"
#define  set_VODMA_vodma_i2rnd_s_period_load_dbg_reg(data)                       (*((volatile unsigned int*)VODMA_vodma_i2rnd_s_period_load_dbg_reg)=data)
#define  get_VODMA_vodma_i2rnd_s_period_load_dbg_reg                             (*((volatile unsigned int*)VODMA_vodma_i2rnd_s_period_load_dbg_reg))
#define  VODMA_vodma_i2rnd_s_period_load_dbg_i2rnd_s_period_load_max_shift       (0)
#define  VODMA_vodma_i2rnd_s_period_load_dbg_i2rnd_s_period_load_max_mask        (0x0FFFFFFF)
#define  VODMA_vodma_i2rnd_s_period_load_dbg_i2rnd_s_period_load_max(data)       (0x0FFFFFFF&(data))
#define  VODMA_vodma_i2rnd_s_period_load_dbg_get_i2rnd_s_period_load_max(data)   (0x0FFFFFFF&(data))

#define  VODMA_vodma_timing_monitor_ctrl                                         0x18005260
#define  VODMA_vodma_timing_monitor_ctrl_reg_addr                                "0xB8005260"
#define  VODMA_vodma_timing_monitor_ctrl_reg                                     0xB8005260
#define  VODMA_vodma_timing_monitor_ctrl_inst_addr                               "0x007E"
#define  set_VODMA_vodma_timing_monitor_ctrl_reg(data)                           (*((volatile unsigned int*)VODMA_vodma_timing_monitor_ctrl_reg)=data)
#define  get_VODMA_vodma_timing_monitor_ctrl_reg                                 (*((volatile unsigned int*)VODMA_vodma_timing_monitor_ctrl_reg))
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_en_shift                 (31)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_i2rnd_mode_shift         (29)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_src_shift                (28)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_unit_shift               (27)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_multi_mode_shift         (26)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_compare_shift            (24)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_sta0_shift               (12)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_end0_shift               (8)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_sta1_shift               (4)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_end1_shift               (0)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_en_mask                  (0x80000000)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_i2rnd_mode_mask          (0x60000000)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_src_mask                 (0x10000000)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_unit_mask                (0x08000000)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_multi_mode_mask          (0x04000000)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_compare_mask             (0x03000000)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_sta0_mask                (0x0000F000)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_end0_mask                (0x00000F00)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_sta1_mask                (0x000000F0)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_end1_mask                (0x0000000F)
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_en(data)                 (0x80000000&((data)<<31))
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_i2rnd_mode(data)         (0x60000000&((data)<<29))
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_src(data)                (0x10000000&((data)<<28))
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_unit(data)               (0x08000000&((data)<<27))
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_multi_mode(data)         (0x04000000&((data)<<26))
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_compare(data)            (0x03000000&((data)<<24))
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_sta0(data)               (0x0000F000&((data)<<12))
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_end0(data)               (0x00000F00&((data)<<8))
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_sta1(data)               (0x000000F0&((data)<<4))
#define  VODMA_vodma_timing_monitor_ctrl_timing_monitor_end1(data)               (0x0000000F&(data))
#define  VODMA_vodma_timing_monitor_ctrl_get_timing_monitor_en(data)             ((0x80000000&(data))>>31)
#define  VODMA_vodma_timing_monitor_ctrl_get_timing_monitor_i2rnd_mode(data)     ((0x60000000&(data))>>29)
#define  VODMA_vodma_timing_monitor_ctrl_get_timing_monitor_src(data)            ((0x10000000&(data))>>28)
#define  VODMA_vodma_timing_monitor_ctrl_get_timing_monitor_unit(data)           ((0x08000000&(data))>>27)
#define  VODMA_vodma_timing_monitor_ctrl_get_timing_monitor_multi_mode(data)     ((0x04000000&(data))>>26)
#define  VODMA_vodma_timing_monitor_ctrl_get_timing_monitor_compare(data)        ((0x03000000&(data))>>24)
#define  VODMA_vodma_timing_monitor_ctrl_get_timing_monitor_sta0(data)           ((0x0000F000&(data))>>12)
#define  VODMA_vodma_timing_monitor_ctrl_get_timing_monitor_end0(data)           ((0x00000F00&(data))>>8)
#define  VODMA_vodma_timing_monitor_ctrl_get_timing_monitor_sta1(data)           ((0x000000F0&(data))>>4)
#define  VODMA_vodma_timing_monitor_ctrl_get_timing_monitor_end1(data)           (0x0000000F&(data))

#define  VODMA_vodma_timing_monitor_multi                                        0x18005264
#define  VODMA_vodma_timing_monitor_multi_reg_addr                               "0xB8005264"
#define  VODMA_vodma_timing_monitor_multi_reg                                    0xB8005264
#define  VODMA_vodma_timing_monitor_multi_inst_addr                              "0x007F"
#define  set_VODMA_vodma_timing_monitor_multi_reg(data)                          (*((volatile unsigned int*)VODMA_vodma_timing_monitor_multi_reg)=data)
#define  get_VODMA_vodma_timing_monitor_multi_reg                                (*((volatile unsigned int*)VODMA_vodma_timing_monitor_multi_reg))
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_sta2_shift              (28)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_end2_shift              (24)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_sta3_shift              (20)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_end3_shift              (16)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_sta4_shift              (12)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_end4_shift              (8)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_sta5_shift              (4)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_end5_shift              (0)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_sta2_mask               (0xF0000000)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_end2_mask               (0x0F000000)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_sta3_mask               (0x00F00000)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_end3_mask               (0x000F0000)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_sta4_mask               (0x0000F000)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_end4_mask               (0x00000F00)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_sta5_mask               (0x000000F0)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_end5_mask               (0x0000000F)
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_sta2(data)              (0xF0000000&((data)<<28))
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_end2(data)              (0x0F000000&((data)<<24))
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_sta3(data)              (0x00F00000&((data)<<20))
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_end3(data)              (0x000F0000&((data)<<16))
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_sta4(data)              (0x0000F000&((data)<<12))
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_end4(data)              (0x00000F00&((data)<<8))
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_sta5(data)              (0x000000F0&((data)<<4))
#define  VODMA_vodma_timing_monitor_multi_timing_monitor_end5(data)              (0x0000000F&(data))
#define  VODMA_vodma_timing_monitor_multi_get_timing_monitor_sta2(data)          ((0xF0000000&(data))>>28)
#define  VODMA_vodma_timing_monitor_multi_get_timing_monitor_end2(data)          ((0x0F000000&(data))>>24)
#define  VODMA_vodma_timing_monitor_multi_get_timing_monitor_sta3(data)          ((0x00F00000&(data))>>20)
#define  VODMA_vodma_timing_monitor_multi_get_timing_monitor_end3(data)          ((0x000F0000&(data))>>16)
#define  VODMA_vodma_timing_monitor_multi_get_timing_monitor_sta4(data)          ((0x0000F000&(data))>>12)
#define  VODMA_vodma_timing_monitor_multi_get_timing_monitor_end4(data)          ((0x00000F00&(data))>>8)
#define  VODMA_vodma_timing_monitor_multi_get_timing_monitor_sta5(data)          ((0x000000F0&(data))>>4)
#define  VODMA_vodma_timing_monitor_multi_get_timing_monitor_end5(data)          (0x0000000F&(data))

#define  VODMA_vodma_timing_monitor_compare_th                                   0x18005268
#define  VODMA_vodma_timing_monitor_compare_th_reg_addr                          "0xB8005268"
#define  VODMA_vodma_timing_monitor_compare_th_reg                               0xB8005268
#define  VODMA_vodma_timing_monitor_compare_th_inst_addr                         "0x0080"
#define  set_VODMA_vodma_timing_monitor_compare_th_reg(data)                     (*((volatile unsigned int*)VODMA_vodma_timing_monitor_compare_th_reg)=data)
#define  get_VODMA_vodma_timing_monitor_compare_th_reg                           (*((volatile unsigned int*)VODMA_vodma_timing_monitor_compare_th_reg))
#define  VODMA_vodma_timing_monitor_compare_th_t_m_compare_th_shift              (0)
#define  VODMA_vodma_timing_monitor_compare_th_t_m_compare_th_mask               (0x0FFFFFFF)
#define  VODMA_vodma_timing_monitor_compare_th_t_m_compare_th(data)              (0x0FFFFFFF&(data))
#define  VODMA_vodma_timing_monitor_compare_th_get_t_m_compare_th(data)          (0x0FFFFFFF&(data))

#define  VODMA_vodma_timing_monitor_golden                                       0x1800526C
#define  VODMA_vodma_timing_monitor_golden_reg_addr                              "0xB800526C"
#define  VODMA_vodma_timing_monitor_golden_reg                                   0xB800526C
#define  VODMA_vodma_timing_monitor_golden_inst_addr                             "0x0081"
#define  set_VODMA_vodma_timing_monitor_golden_reg(data)                         (*((volatile unsigned int*)VODMA_vodma_timing_monitor_golden_reg)=data)
#define  get_VODMA_vodma_timing_monitor_golden_reg                               (*((volatile unsigned int*)VODMA_vodma_timing_monitor_golden_reg))
#define  VODMA_vodma_timing_monitor_golden_t_m_golden_shift                      (0)
#define  VODMA_vodma_timing_monitor_golden_t_m_golden_mask                       (0x0FFFFFFF)
#define  VODMA_vodma_timing_monitor_golden_t_m_golden(data)                      (0x0FFFFFFF&(data))
#define  VODMA_vodma_timing_monitor_golden_get_t_m_golden(data)                  (0x0FFFFFFF&(data))

#define  VODMA_vodma_timing_monitor_result1                                      0x18005270
#define  VODMA_vodma_timing_monitor_result1_reg_addr                             "0xB8005270"
#define  VODMA_vodma_timing_monitor_result1_reg                                  0xB8005270
#define  VODMA_vodma_timing_monitor_result1_inst_addr                            "0x0082"
#define  set_VODMA_vodma_timing_monitor_result1_reg(data)                        (*((volatile unsigned int*)VODMA_vodma_timing_monitor_result1_reg)=data)
#define  get_VODMA_vodma_timing_monitor_result1_reg                              (*((volatile unsigned int*)VODMA_vodma_timing_monitor_result1_reg))
#define  VODMA_vodma_timing_monitor_result1_t_m_result_previous1_shift           (0)
#define  VODMA_vodma_timing_monitor_result1_t_m_result_previous1_mask            (0x0FFFFFFF)
#define  VODMA_vodma_timing_monitor_result1_t_m_result_previous1(data)           (0x0FFFFFFF&(data))
#define  VODMA_vodma_timing_monitor_result1_get_t_m_result_previous1(data)       (0x0FFFFFFF&(data))

#define  VODMA_vodma_timing_monitor_result2                                      0x18005274
#define  VODMA_vodma_timing_monitor_result2_reg_addr                             "0xB8005274"
#define  VODMA_vodma_timing_monitor_result2_reg                                  0xB8005274
#define  VODMA_vodma_timing_monitor_result2_inst_addr                            "0x0083"
#define  set_VODMA_vodma_timing_monitor_result2_reg(data)                        (*((volatile unsigned int*)VODMA_vodma_timing_monitor_result2_reg)=data)
#define  get_VODMA_vodma_timing_monitor_result2_reg                              (*((volatile unsigned int*)VODMA_vodma_timing_monitor_result2_reg))
#define  VODMA_vodma_timing_monitor_result2_t_m_result_previous2_shift           (0)
#define  VODMA_vodma_timing_monitor_result2_t_m_result_previous2_mask            (0x0FFFFFFF)
#define  VODMA_vodma_timing_monitor_result2_t_m_result_previous2(data)           (0x0FFFFFFF&(data))
#define  VODMA_vodma_timing_monitor_result2_get_t_m_result_previous2(data)       (0x0FFFFFFF&(data))

#define  VODMA_vodma_timing_monitor_result3                                      0x18005278
#define  VODMA_vodma_timing_monitor_result3_reg_addr                             "0xB8005278"
#define  VODMA_vodma_timing_monitor_result3_reg                                  0xB8005278
#define  VODMA_vodma_timing_monitor_result3_inst_addr                            "0x0084"
#define  set_VODMA_vodma_timing_monitor_result3_reg(data)                        (*((volatile unsigned int*)VODMA_vodma_timing_monitor_result3_reg)=data)
#define  get_VODMA_vodma_timing_monitor_result3_reg                              (*((volatile unsigned int*)VODMA_vodma_timing_monitor_result3_reg))
#define  VODMA_vodma_timing_monitor_result3_t_m_result_previous3_shift           (0)
#define  VODMA_vodma_timing_monitor_result3_t_m_result_previous3_mask            (0x0FFFFFFF)
#define  VODMA_vodma_timing_monitor_result3_t_m_result_previous3(data)           (0x0FFFFFFF&(data))
#define  VODMA_vodma_timing_monitor_result3_get_t_m_result_previous3(data)       (0x0FFFFFFF&(data))

#define  VODMA_vodma_timing_monitor_result4                                      0x1800527C
#define  VODMA_vodma_timing_monitor_result4_reg_addr                             "0xB800527C"
#define  VODMA_vodma_timing_monitor_result4_reg                                  0xB800527C
#define  VODMA_vodma_timing_monitor_result4_inst_addr                            "0x0085"
#define  set_VODMA_vodma_timing_monitor_result4_reg(data)                        (*((volatile unsigned int*)VODMA_vodma_timing_monitor_result4_reg)=data)
#define  get_VODMA_vodma_timing_monitor_result4_reg                              (*((volatile unsigned int*)VODMA_vodma_timing_monitor_result4_reg))
#define  VODMA_vodma_timing_monitor_result4_t_m_result_previous4_shift           (0)
#define  VODMA_vodma_timing_monitor_result4_t_m_result_previous4_mask            (0x0FFFFFFF)
#define  VODMA_vodma_timing_monitor_result4_t_m_result_previous4(data)           (0x0FFFFFFF&(data))
#define  VODMA_vodma_timing_monitor_result4_get_t_m_result_previous4(data)       (0x0FFFFFFF&(data))

#define  VODMA_vodma_timing_monitor_max                                          0x18005280
#define  VODMA_vodma_timing_monitor_max_reg_addr                                 "0xB8005280"
#define  VODMA_vodma_timing_monitor_max_reg                                      0xB8005280
#define  VODMA_vodma_timing_monitor_max_inst_addr                                "0x0086"
#define  set_VODMA_vodma_timing_monitor_max_reg(data)                            (*((volatile unsigned int*)VODMA_vodma_timing_monitor_max_reg)=data)
#define  get_VODMA_vodma_timing_monitor_max_reg                                  (*((volatile unsigned int*)VODMA_vodma_timing_monitor_max_reg))
#define  VODMA_vodma_timing_monitor_max_t_m_result_max_shift                     (0)
#define  VODMA_vodma_timing_monitor_max_t_m_result_max_mask                      (0x0FFFFFFF)
#define  VODMA_vodma_timing_monitor_max_t_m_result_max(data)                     (0x0FFFFFFF&(data))
#define  VODMA_vodma_timing_monitor_max_get_t_m_result_max(data)                 (0x0FFFFFFF&(data))

#define  VODMA_vodma_timing_monitor_min                                          0x18005284
#define  VODMA_vodma_timing_monitor_min_reg_addr                                 "0xB8005284"
#define  VODMA_vodma_timing_monitor_min_reg                                      0xB8005284
#define  VODMA_vodma_timing_monitor_min_inst_addr                                "0x0087"
#define  set_VODMA_vodma_timing_monitor_min_reg(data)                            (*((volatile unsigned int*)VODMA_vodma_timing_monitor_min_reg)=data)
#define  get_VODMA_vodma_timing_monitor_min_reg                                  (*((volatile unsigned int*)VODMA_vodma_timing_monitor_min_reg))
#define  VODMA_vodma_timing_monitor_min_t_m_result_min_shift                     (0)
#define  VODMA_vodma_timing_monitor_min_t_m_result_min_mask                      (0x0FFFFFFF)
#define  VODMA_vodma_timing_monitor_min_t_m_result_min(data)                     (0x0FFFFFFF&(data))
#define  VODMA_vodma_timing_monitor_min_get_t_m_result_min(data)                 (0x0FFFFFFF&(data))

#define  VODMA_vodma_timing_monitor_st                                           0x18005288
#define  VODMA_vodma_timing_monitor_st_reg_addr                                  "0xB8005288"
#define  VODMA_vodma_timing_monitor_st_reg                                       0xB8005288
#define  VODMA_vodma_timing_monitor_st_inst_addr                                 "0x0088"
#define  set_VODMA_vodma_timing_monitor_st_reg(data)                             (*((volatile unsigned int*)VODMA_vodma_timing_monitor_st_reg)=data)
#define  get_VODMA_vodma_timing_monitor_st_reg                                   (*((volatile unsigned int*)VODMA_vodma_timing_monitor_st_reg))
#define  VODMA_vodma_timing_monitor_st_compare_hit_shift                         (2)
#define  VODMA_vodma_timing_monitor_st_hsync_hit_den_error_shift                 (1)
#define  VODMA_vodma_timing_monitor_st_vsync_hit_den_error_shift                 (0)
#define  VODMA_vodma_timing_monitor_st_compare_hit_mask                          (0x00000004)
#define  VODMA_vodma_timing_monitor_st_hsync_hit_den_error_mask                  (0x00000002)
#define  VODMA_vodma_timing_monitor_st_vsync_hit_den_error_mask                  (0x00000001)
#define  VODMA_vodma_timing_monitor_st_compare_hit(data)                         (0x00000004&((data)<<2))
#define  VODMA_vodma_timing_monitor_st_hsync_hit_den_error(data)                 (0x00000002&((data)<<1))
#define  VODMA_vodma_timing_monitor_st_vsync_hit_den_error(data)                 (0x00000001&(data))
#define  VODMA_vodma_timing_monitor_st_get_compare_hit(data)                     ((0x00000004&(data))>>2)
#define  VODMA_vodma_timing_monitor_st_get_hsync_hit_den_error(data)             ((0x00000002&(data))>>1)
#define  VODMA_vodma_timing_monitor_st_get_vsync_hit_den_error(data)             (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======VODMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  merge_forward:1;
        RBus_UInt32  merge_backward:1;
        RBus_UInt32  pd_switch:1;
        RBus_UInt32  pd_seq:5;
        RBus_UInt32  film_condition:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  field_mode:1;
        RBus_UInt32  field_fw:1;
        RBus_UInt32  l_flag_fw:1;
        RBus_UInt32  force_2d_en:1;
        RBus_UInt32  force_2d_sel:1;
        RBus_UInt32  dma_auto_mode:1;
        RBus_UInt32  seq_data_pack_type:1;
        RBus_UInt32  seq_data_width:1;
        RBus_UInt32  double_chroma:1;
        RBus_UInt32  uv_off:1;
        RBus_UInt32  pxl_swap_sel:4;
        RBus_UInt32  keep_go_en:1;
        RBus_UInt32  dma_state_reset_en:1;
        RBus_UInt32  v_flip_en:1;
        RBus_UInt32  chroma_swap_en:1;
        RBus_UInt32  double_pixel_mode:1;
        RBus_UInt32  dma_mode:1;
        RBus_UInt32  vodma_go:1;
    };
}vodma_vodma_v1_dcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  crc_continuous:1;
        RBus_UInt32  crc_start:1;
    };
}vodma_vodma_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}vodma_vodma_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  afifo_almost_empty_level:10;
        RBus_UInt32  chroma_lb_underflow_debug_cancel:1;
        RBus_UInt32  chroma_lb_early_req_off:1;
        RBus_UInt32  gating_off:1;
        RBus_UInt32  debug_pin_src:1;
    };
}vodma_vodma_rtl_improve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vs_toggle_reset:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  p_y_len:13;
        RBus_UInt32  res2:4;
        RBus_UInt32  p_y_nline:12;
    };
}vodma_vodma_v1_dsize_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  p_v_ads:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  p_u_ads:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  p_y_ads:7;
    };
}vodma_vodma_vd1_ads_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_adr:29;
        RBus_UInt32  res1:3;
    };
}vodma_vodma_v1_seq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  y_ha_shift:3;
        RBus_UInt32  res2:8;
    };
}vodma_vodma_v1_blk1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  p_u_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  p_y_offset:12;
    };
}vodma_vodma_v1_blk2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  p_v_offset:12;
    };
}vodma_vodma_v1_blk3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  y_h_offset:10;
    };
}vodma_vodma_v1_blk4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v_h_offset:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u_h_offset:10;
    };
}vodma_vodma_v1_blk5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_adr:29;
        RBus_UInt32  res1:3;
    };
}vodma_vodma_v1_seq_3d_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_adr:29;
        RBus_UInt32  res1:3;
    };
}vodma_vodma_v1_seq_3d_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_adr:29;
        RBus_UInt32  res1:3;
    };
}vodma_vodma_v1_seq_3d_l2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_adr:29;
        RBus_UInt32  res1:3;
    };
}vodma_vodma_v1_seq_3d_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  line_step:13;
    };
}vodma_vodma_v1_v_flip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_adr:29;
        RBus_UInt32  res1:3;
    };
}vodma_vodma_v1_seq_3d_l3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_adr:29;
        RBus_UInt32  res1:3;
    };
}vodma_vodma_v1_seq_3d_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_adr:29;
        RBus_UInt32  res1:3;
    };
}vodma_vodma_v1_seq_3d_l4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_adr:29;
        RBus_UInt32  res1:3;
    };
}vodma_vodma_v1_seq_3d_r4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  p_y_len:12;
        RBus_UInt32  res2:1;
        RBus_UInt32  p_y_nline:11;
        RBus_UInt32  res3:2;
        RBus_UInt32  tabsbs_mode:1;
        RBus_UInt32  tabsbs_merge:1;
    };
}vodma_vodma_tabsbs_merge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_adr:29;
        RBus_UInt32  res1:3;
    };
}vodma_vodma_tabsbs_seq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  p_v_ads:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  p_u_ads:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  p_y_ads:7;
    };
}vodma_vodma_tabsbs_ads_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  y_ha_shift:3;
        RBus_UInt32  res2:8;
    };
}vodma_vodma_tabsbs_blk1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  p_u_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  p_y_offset:12;
    };
}vodma_vodma_tabsbs_blk2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  p_v_offset:12;
    };
}vodma_vodma_tabsbs_blk3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  y_h_offset:10;
    };
}vodma_vodma_tabsbs_blk4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v_h_offset:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u_h_offset:10;
    };
}vodma_vodma_tabsbs_blk5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vodmavsg_dbrdy_keep:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  vodmavsg_db_sel:1;
        RBus_UInt32  vodmavsg_db_en:1;
        RBus_UInt32  vodmavsg_db_rdy:1;
        RBus_UInt32  res3:5;
        RBus_UInt32  i2rnd_db_sel:1;
        RBus_UInt32  i2rnd_db_en:1;
        RBus_UInt32  i2rnd_db_rdy:1;
        RBus_UInt32  res4:5;
        RBus_UInt32  vodma_db_sel:1;
        RBus_UInt32  vodma_db_en:1;
        RBus_UInt32  vodma_db_rdy:1;
    };
}vodma_vodma_reg_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  g_position:2;
        RBus_UInt32  seq_color_swap:3;
        RBus_UInt32  alpha_position:1;
        RBus_UInt32  encfmt:4;
    };
}vodma_vodma_v1chroma_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  mode:3;
    };
}vodma_vodma_v1_cu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  fir422_sel:2;
    };
}vodma_vodma_v1422_to_444_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  y1_line_select:1;
        RBus_UInt32  c1_line_select:1;
    };
}vodma_vodma_line_select_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  vthr_rst1:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  v_thr:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  h_thr:13;
    };
}vodma_vodma_v1sgen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  den_src:1;
        RBus_UInt32  vgip_en:1;
        RBus_UInt32  interlace:1;
        RBus_UInt32  top_fld_indc:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  v_thr:12;
    };
}vodma_vodma_v1int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v_st:12;
    };
}vodma_vodma_v1vgip_ivs1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v_st:12;
    };
}vodma_vodma_v1vgip_ivs2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  h_st:13;
    };
}vodma_vodma_v1vgip_ihs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v_st:12;
    };
}vodma_vodma_v1vgip_fd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v_st:12;
    };
}vodma_vodma_v1vgip_fd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  h_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  h_st:13;
    };
}vodma_vodma_v1vgip_hact_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v_st:12;
    };
}vodma_vodma_v1vgip_vact1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v_st:12;
    };
}vodma_vodma_v1vgip_vact2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  h_end:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  h_st:13;
    };
}vodma_vodma_v1vgip_hbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v_st:12;
    };
}vodma_vodma_v1vgip_vbg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v_st:12;
    };
}vodma_vodma_v1vgip_vbg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  bg_v:10;
        RBus_UInt32  bg_u:10;
        RBus_UInt32  bg_y:10;
    };
}vodma_vodma_v1vgip_bg_clr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  mask_den_en:1;
        RBus_UInt32  mask_data_en:2;
    };
}vodma_vodma_v1vgip_mask_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_end:16;
        RBus_UInt32  h_st:16;
    };
}vodma_vodma_v1vgip_hmask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_end:16;
        RBus_UInt32  v_st:16;
    };
}vodma_vodma_v1vgip_vmask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
        RBus_UInt32  starty:14;
        RBus_UInt32  block_shape:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  startx:14;
    };
}vodma_vodma_accessdata_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y00:10;
    };
}vodma_vodma_accessdata_y1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y01:10;
    };
}vodma_vodma_accessdata_y2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u00:10;
    };
}vodma_vodma_accessdata_c1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u10:10;
    };
}vodma_vodma_accessdata_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u01:10;
    };
}vodma_vodma_accessdata_c3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u11:10;
    };
}vodma_vodma_accessdata_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v:10;
        RBus_UInt32  access_u:10;
        RBus_UInt32  access_y:10;
    };
}vodma_vodma_accessdata_clr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v1:12;
    };
}vodma_vodma_v1vgip_intpos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_irq_ie:1;
        RBus_UInt32  res1:28;
        RBus_UInt32  vpos_inte1:1;
        RBus_UInt32  finish_inte1:1;
        RBus_UInt32  buf_underflow_inte1:1;
    };
}vodma_vodma_vgip_intpos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist_irq_record_ro:1;
        RBus_UInt32  i2rnd_irq_record_ro:1;
        RBus_UInt32  decomp_irq_record_ro:1;
        RBus_UInt32  vodma_irq_record_ro:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  vpos_ints1:1;
        RBus_UInt32  finish_ints1:1;
        RBus_UInt32  buf_underflow_ints1:1;
    };
}vodma_vodma_vgip_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  l_flag_status:1;
        RBus_UInt32  vsync_status:1;
        RBus_UInt32  v_active:1;
        RBus_UInt32  field_status:1;
    };
}vodma_vodma_vgip_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  line_cnt:12;
    };
}vodma_vodma_line_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  vodma_bist_mode_2:1;
        RBus_UInt32  vodma_bist_mode_1:1;
        RBus_UInt32  vodma_bist_mode_0:1;
    };
}vodma_vodma_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  vodma_bist_done_2:1;
        RBus_UInt32  vodma_bist_done_1:1;
        RBus_UInt32  vodma_bist_done_0:1;
    };
}vodma_vodma_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vodma_bist_fail_group:1;
    };
}vodma_vodma_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  vodma_bist_fail_5:1;
        RBus_UInt32  vodma_bist_fail_4:1;
        RBus_UInt32  vodma_bist_fail_3:1;
        RBus_UInt32  vodma_bist_fail_2:1;
        RBus_UInt32  vodma_bist_fail_1:1;
        RBus_UInt32  vodma_bist_fail_0:1;
    };
}vodma_vodma_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  vodma_drf_mode_2:1;
        RBus_UInt32  vodma_drf_mode_1:1;
        RBus_UInt32  vodma_drf_mode_0:1;
    };
}vodma_vodma_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  vodma_drf_resume_2:1;
        RBus_UInt32  vodma_drf_resume_1:1;
        RBus_UInt32  vodma_drf_resume_0:1;
    };
}vodma_vodma_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  vodma_drf_done_2:1;
        RBus_UInt32  vodma_drf_done_1:1;
        RBus_UInt32  vodma_drf_done_0:1;
    };
}vodma_vodma_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  vodma_drf_pause_2:1;
        RBus_UInt32  vodma_drf_pause_1:1;
        RBus_UInt32  vodma_drf_pause_0:1;
    };
}vodma_vodma_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vodma_drf_fail_group:1;
    };
}vodma_vodma_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  vodma_drf_fail_5:1;
        RBus_UInt32  vodma_drf_fail_4:1;
        RBus_UInt32  vodma_drf_fail_3:1;
        RBus_UInt32  vodma_drf_fail_2:1;
        RBus_UInt32  vodma_drf_fail_1:1;
        RBus_UInt32  vodma_drf_fail_0:1;
    };
}vodma_vodma_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  vodma_bist_ls_2:1;
        RBus_UInt32  vodma_bist_rm_2:4;
        RBus_UInt32  vodma_bist_rme_2:1;
        RBus_UInt32  vodma_bist_rst_n_2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vodma_bist_ls_1:1;
        RBus_UInt32  vodma_bist_rm_1:4;
        RBus_UInt32  vodma_bist_rme_1:1;
        RBus_UInt32  vodma_bist_rst_n_1:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  vodma_bist_ls_0:1;
        RBus_UInt32  vodma_bist_rm_0:4;
        RBus_UInt32  vodma_bist_rme_0:1;
        RBus_UInt32  vodma_bist_rst_n_0:1;
    };
}vodma_vodma_bist_other_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  sel:5;
    };
}vodma_vodma_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  vodma_actv:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_block_sel:2;
    };
}vodma_vodma_3d_cs_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_st_adr:29;
        RBus_UInt32  res1:3;
    };
}vodma_vodma_3d_cs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180050d0_31_11:21;
        RBus_UInt32  dummy180050d0_10:1;
        RBus_UInt32  hori_drop_mode:1;
        RBus_UInt32  hori_drop_en:1;
        RBus_UInt32  quincunx_mode_src_sel:1;
        RBus_UInt32  quincunx_int_mode:2;
        RBus_UInt32  quincunx_int_en:1;
        RBus_UInt32  quincunx_mode_fw:4;
    };
}vodma_vodma_quincunx_setting_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  quincunx_mode_b0:4;
        RBus_UInt32  quincunx_mode_b1:4;
    };
}vodma_vodma_quincunx_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gate_period:3;
        RBus_UInt32  smooth_en:1;
        RBus_UInt32  vcnt_pre_num:28;
    };
}vodma_vodma_smooth_toggle_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mrs_mode:1;
        RBus_UInt32  max_mrs_num:3;
        RBus_UInt32  res1:21;
        RBus_UInt32  blockmode_sel_c:2;
        RBus_UInt32  burst_len:1;
        RBus_UInt32  block_burst_len:1;
        RBus_UInt32  blockmode_sel_y:2;
        RBus_UInt32  cmd_trans_en:1;
    };
}vodma_vodma_dma_option_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_pvgen:1;
        RBus_UInt32  en_pfgen:1;
        RBus_UInt32  pfgen_inv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  iv_inv_en:1;
        RBus_UInt32  iv_src_sel:3;
        RBus_UInt32  iv2pv_dly:24;
    };
}vodma_vodma_pvs0_gen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pvs0_free_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pvs0_free_vs_reset_en:1;
        RBus_UInt32  pvs0_free_period_update:1;
        RBus_UInt32  pvs0_free_period:28;
    };
}vodma_vodma_pvs_free_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pvs0_free_clk_sel:2;
        RBus_UInt32  dummy18005308_29_11:19;
        RBus_UInt32  pvs0_free_vs_sel:3;
        RBus_UInt32  res1:3;
        RBus_UInt32  pvs0_free_l_flag_en:1;
        RBus_UInt32  pvs0_free_vs_inv_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mask_one_vs:1;
    };
}vodma_vodma_pvs_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_enclk:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vodma_clk_div2_en_src_sel:1;
        RBus_UInt32  vodma_clk_div2_en:1;
        RBus_UInt32  vodma_clk_div_n:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  vodma_clk_ratio_n_off:5;
        RBus_UInt32  dummy18005310_15_7:9;
        RBus_UInt32  vodma_clk_sel:3;
        RBus_UInt32  en_fifo_empty_gate:1;
        RBus_UInt32  gating_src_sel:2;
        RBus_UInt32  en_fifo_full_gate:1;
    };
}vodma_vodma_clkgen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18005314_31_28:4;
        RBus_UInt32  pvs0_vs_width:28;
    };
}vodma_vodma_pvs_width_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  phase_err_measure_start:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pe_number:28;
    };
}vodma_vodma_phase_error_for_2vs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  manual_vs:1;
        RBus_UInt32  res1:31;
    };
}vodma_vodma_manual_vs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_vs_sel_rwd1:2;
        RBus_UInt32  res1:30;
    };
}vodma_vodma_reg_db_vsync_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrap_line_num_sys:12;
        RBus_UInt32  res1:2;
        RBus_UInt32  wrap_v_div2_en:1;
        RBus_UInt32  wrap_v_flip_en:1;
        RBus_UInt32  decomp_bpp_sys:4;
        RBus_UInt32  header_num_4line_sys:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  decomp_bypass_en:1;
        RBus_UInt32  lossy_en:1;
        RBus_UInt32  decomp_wrap_en:1;
    };
}vodma_decomp_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrap_line_num_vodma:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  decomp_bpp_vodma:4;
        RBus_UInt32  header_num_4line_vodma:8;
        RBus_UInt32  res2:4;
    };
}vodma_decomp_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  warp_y_data_wtlvl:9;
        RBus_UInt32  res2:8;
        RBus_UInt32  wrap_y_data_read_len:8;
    };
}vodma_decomp_ydma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  wrap_c_data_wtlvl:9;
        RBus_UInt32  res2:8;
        RBus_UInt32  wrap_c_data_read_len:8;
    };
}vodma_decomp_cdma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  wapp_c_data_pic_set:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  wapp_y_data_pic_set:8;
    };
}vodma_decomp_pic_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wapp_y_header_read_addr:29;
        RBus_UInt32  res1:3;
    };
}vodma_decomp_read_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wapp_c_header_read_addr:29;
        RBus_UInt32  res1:3;
    };
}vodma_decomp_read_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  wrap_data_wid_y:10;
    };
}vodma_decomp_x_wid_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  wrap_data_wid_c:10;
    };
}vodma_decomp_x_wid_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_y_hd_4line_step:29;
        RBus_UInt32  res1:3;
    };
}vodma_decomp_dma_read_hd_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_c_hd_4line_step:29;
        RBus_UInt32  res1:3;
    };
}vodma_decomp_dma_read_hd_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_c_hd_mode:1;
        RBus_UInt32  dma_y_hd_mode:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  dma_c_hd_blk_len:8;
        RBus_UInt32  dma_y_hd_blk_len:8;
    };
}vodma_decomp_hd_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  wrap_c_data_fifoof:1;
        RBus_UInt32  wrap_c_data_fifouf:1;
        RBus_UInt32  wrap_c_data_fifofull:1;
        RBus_UInt32  wrap_c_data_fifoempty:1;
        RBus_UInt32  wrap_c_head_fifoof:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  wrap_c_head_fifofull:1;
        RBus_UInt32  wrap_c_head_fifoempty:1;
        RBus_UInt32  wrap_c_dma_fifoof:1;
        RBus_UInt32  wrap_c_dma_req_error:1;
        RBus_UInt32  wrap_c_dma_fifofull:1;
        RBus_UInt32  wrap_c_dma_fifoempty:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  wrap_y_data_fifoof:1;
        RBus_UInt32  wrap_y_data_fifouf:1;
        RBus_UInt32  wrap_y_data_fifofull:1;
        RBus_UInt32  wrap_y_data_fifoempty:1;
        RBus_UInt32  wrap_y_head_fifoof:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  wrap_y_head_fifofull:1;
        RBus_UInt32  wrap_y_head_fifoempty:1;
        RBus_UInt32  wrap_y_dma_fifoof:1;
        RBus_UInt32  wrap_y_dma_req_error:1;
        RBus_UInt32  wrap_y_dma_fifofull:1;
        RBus_UInt32  wrap_y_dma_fifoempty:1;
    };
}vodma_decomp_dma_ststus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  wrap_c_data_fifoof_ie:1;
        RBus_UInt32  wrap_c_data_fifouf_ie:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  wrap_c_head_fifoof_ie:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  wrap_c_dma_fifoof_ie:1;
        RBus_UInt32  res4:7;
        RBus_UInt32  wrap_y_data_fifoof_ie:1;
        RBus_UInt32  wrap_y_data_fifouf_ie:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  wrap_y_head_fifoof_ie:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  wrap_y_dma_fifoof_ie:1;
        RBus_UInt32  res7:3;
    };
}vodma_decomp_dma_ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decomp_core_irq:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  decomp_core2_irq:1;
        RBus_UInt32  res2:15;
    };
}vodma_decomp_core_status_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  decomp_core2_errflag:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  decomp_core_errflag:8;
    };
}vodma_decomp_core_status_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  decomp_core2_errflag_clr:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  decomp_core_errflag_clr:8;
    };
}vodma_decomp_core_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  decomp_core2_flag2irq_en:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  decomp_core_flag2irq_en:8;
    };
}vodma_decomp_core_status_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  i2rnd_flag_fifo_mode:1;
        RBus_UInt32  i2rnd_flag_fifo_en:1;
        RBus_UInt32  debug_mask_main:1;
        RBus_UInt32  debug_mask_sub1:1;
        RBus_UInt32  debug_mask_sub2:1;
        RBus_UInt32  debug_mask_repeat_sub_old_en:1;
        RBus_UInt32  i2rnd_src_flag_inv:1;
        RBus_UInt32  i2rnd_timing_mode:2;
        RBus_UInt32  i2rnd_timing_en:1;
    };
}vodma_vodma_i2rnd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_hw_mask_repeat_frame_m_en:1;
        RBus_UInt32  i2rnd_hw_nxt_rpt_flag_m_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  i2rnd_m_quincunx_sel:1;
        RBus_UInt32  i2rnd_m_quincunx_fw:4;
        RBus_UInt32  i2rnd_m_nxt_rpt_flag_fw:1;
        RBus_UInt32  i2rnd_m_nxt_rpt_flag_sel:1;
        RBus_UInt32  i2rnd_m_block_fw:2;
        RBus_UInt32  i2rnd_m_block_free_run:1;
        RBus_UInt32  i2rnd_m_block_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  i2rnd_m_field_fw:1;
        RBus_UInt32  i2rnd_m_field_free_run:1;
        RBus_UInt32  i2rnd_m_field_sel:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  i2rnd_m_lflag_fw:1;
        RBus_UInt32  i2rnd_m_lflag_free_run:1;
        RBus_UInt32  i2rnd_m_lflag_sel:3;
    };
}vodma_vodma_i2rnd_m_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_hw_mask_repeat_frame_s_en:1;
        RBus_UInt32  i2rnd_hw_nxt_rpt_flag_s_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  i2rnd_s_quincunx_sel:1;
        RBus_UInt32  i2rnd_s_quincunx_fw:4;
        RBus_UInt32  i2rnd_s_nxt_rpt_flag_fw:1;
        RBus_UInt32  i2rnd_s_nxt_rpt_flag_sel:1;
        RBus_UInt32  i2rnd_s_block_fw:2;
        RBus_UInt32  i2rnd_s_block_free_run:1;
        RBus_UInt32  i2rnd_s_block_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  i2rnd_s_field_fw:1;
        RBus_UInt32  i2rnd_s_field_free_run:1;
        RBus_UInt32  i2rnd_s_field_sel:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  i2rnd_s_lflag_fw:1;
        RBus_UInt32  i2rnd_s_lflag_free_run:1;
        RBus_UInt32  i2rnd_s_lflag_sel:3;
    };
}vodma_vodma_i2rnd_s_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  i2rnd_load_hit_den_irq_en:1;
        RBus_UInt32  i2rnd_s_load_over_max_irq_en:1;
        RBus_UInt32  i2rnd_m_load_over_max_irq_en:1;
        RBus_UInt32  i2rnd_not_finish_irq_en:1;
    };
}vodma_vodma_i2rnd_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  i2rnd_load_hit_den_irq_st:1;
        RBus_UInt32  i2rnd_s_load_over_max_irq_st:1;
        RBus_UInt32  i2rnd_m_load_over_max_irq_st:1;
        RBus_UInt32  i2rnd_not_finish_irq_st:1;
    };
}vodma_vodma_i2rnd_irq_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_frame_measure:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  i2rnd_ori_frame_cnt:12;
        RBus_UInt32  i2rnd_s_mask_frame_cnt:8;
        RBus_UInt32  i2rnd_m_mask_frame_cnt:8;
    };
}vodma_vodma_i2rnd_measure_frame_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  info_i3ddma_overflow:1;
        RBus_UInt32  info_dispm_overflow:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  dma_info_water_i3ddma:4;
        RBus_UInt32  dma_info_water_dispm:4;
        RBus_UInt32  dma_info_wptr_i3ddma:4;
        RBus_UInt32  dma_info_rptr_i3ddma:4;
        RBus_UInt32  dma_info_wptr_dispm:4;
        RBus_UInt32  dma_info_rptr_dispm:4;
    };
}vodma_vodma_i2rnd_fifo_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  i2rnd_s_nxt_rpt_flag:1;
        RBus_UInt32  i2rnd_m_nxt_rpt_flag:1;
        RBus_UInt32  i2rnd_nxt_rpt_flag:1;
        RBus_UInt32  i2rnd_s_quincunx:4;
        RBus_UInt32  i2rnd_m_quincunx:4;
        RBus_UInt32  i2rnd_quincunx:4;
        RBus_UInt32  i2rnd_s_block:2;
        RBus_UInt32  i2rnd_s_field:1;
        RBus_UInt32  i2rnd_s_lflag:1;
        RBus_UInt32  i2rnd_m_block:2;
        RBus_UInt32  i2rnd_m_field:1;
        RBus_UInt32  i2rnd_m_lflag:1;
        RBus_UInt32  i2rnd_block:2;
        RBus_UInt32  i2rnd_field:1;
        RBus_UInt32  i2rnd_lflag:1;
        RBus_UInt32  i2rnd_src_flag:1;
        RBus_UInt32  i2rnd_st:3;
    };
}vodma_vodma_i2rnd_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag_fifo_style_i3ddma:1;
        RBus_UInt32  flag_fifo_style_dispm:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  dram_buf_num_i3ddma:4;
        RBus_UInt32  dram_buf_num_dispm:4;
        RBus_UInt32  dma_info_th_i3ddma:4;
        RBus_UInt32  dma_info_th_dispm:4;
    };
}vodma_vodma_i2rnd_fifo_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_info_wptr_fw_set_dispm:1;
        RBus_UInt32  dma_info_wptr_fw_dispm:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  dma_info_wptr_fw_set_i3ddma:1;
        RBus_UInt32  dma_info_wptr_fw_i3ddma:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  dma_info_rptr_fw_set_dispm:1;
        RBus_UInt32  dma_info_rptr_fw_dispm:4;
        RBus_UInt32  res4:3;
        RBus_UInt32  dma_info_rptr_fw_set_i3ddma:1;
        RBus_UInt32  dma_info_rptr_fw_i3ddma:4;
    };
}vodma_vodma_i2rnd_dma_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_period_clk_src:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  i2rnd_m_period_load:28;
    };
}vodma_vodma_i2rnd_m_period_load_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  i2rnd_m_period:28;
    };
}vodma_vodma_i2rnd_m_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  i2rnd_s_period_load:28;
    };
}vodma_vodma_i2rnd_s_period_load_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  i2rnd_s_period:28;
    };
}vodma_vodma_i2rnd_s_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_load_time_measure:1;
        RBus_UInt32  i2rnd_load_time_measure_long_term:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  i2rnd_m_load_time:28;
    };
}vodma_vodma_i2rnd_m_measure_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  i2rnd_s_load_time:28;
    };
}vodma_vodma_i2rnd_s_measure_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_period_load_max_measure_en:1;
        RBus_UInt32  i2rnd_period_load_max_dbg_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  i2rnd_m_period_load_max:28;
    };
}vodma_vodma_i2rnd_m_period_load_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  i2rnd_s_period_load_max:28;
    };
}vodma_vodma_i2rnd_s_period_load_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timing_monitor_en:1;
        RBus_UInt32  timing_monitor_i2rnd_mode:2;
        RBus_UInt32  timing_monitor_src:1;
        RBus_UInt32  timing_monitor_unit:1;
        RBus_UInt32  timing_monitor_multi_mode:1;
        RBus_UInt32  timing_monitor_compare:2;
        RBus_UInt32  res1:8;
        RBus_UInt32  timing_monitor_sta0:4;
        RBus_UInt32  timing_monitor_end0:4;
        RBus_UInt32  timing_monitor_sta1:4;
        RBus_UInt32  timing_monitor_end1:4;
    };
}vodma_vodma_timing_monitor_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timing_monitor_sta2:4;
        RBus_UInt32  timing_monitor_end2:4;
        RBus_UInt32  timing_monitor_sta3:4;
        RBus_UInt32  timing_monitor_end3:4;
        RBus_UInt32  timing_monitor_sta4:4;
        RBus_UInt32  timing_monitor_end4:4;
        RBus_UInt32  timing_monitor_sta5:4;
        RBus_UInt32  timing_monitor_end5:4;
    };
}vodma_vodma_timing_monitor_multi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_compare_th:28;
    };
}vodma_vodma_timing_monitor_compare_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_golden:28;
    };
}vodma_vodma_timing_monitor_golden_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_result_previous1:28;
    };
}vodma_vodma_timing_monitor_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_result_previous2:28;
    };
}vodma_vodma_timing_monitor_result2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_result_previous3:28;
    };
}vodma_vodma_timing_monitor_result3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_result_previous4:28;
    };
}vodma_vodma_timing_monitor_result4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_result_max:28;
    };
}vodma_vodma_timing_monitor_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_result_min:28;
    };
}vodma_vodma_timing_monitor_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  compare_hit:1;
        RBus_UInt32  hsync_hit_den_error:1;
        RBus_UInt32  vsync_hit_den_error:1;
    };
}vodma_vodma_timing_monitor_st_RBUS;

#else //apply LITTLE_ENDIAN

//======VODMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_go:1;
        RBus_UInt32  dma_mode:1;
        RBus_UInt32  double_pixel_mode:1;
        RBus_UInt32  chroma_swap_en:1;
        RBus_UInt32  v_flip_en:1;
        RBus_UInt32  dma_state_reset_en:1;
        RBus_UInt32  keep_go_en:1;
        RBus_UInt32  pxl_swap_sel:4;
        RBus_UInt32  uv_off:1;
        RBus_UInt32  double_chroma:1;
        RBus_UInt32  seq_data_width:1;
        RBus_UInt32  seq_data_pack_type:1;
        RBus_UInt32  dma_auto_mode:1;
        RBus_UInt32  force_2d_sel:1;
        RBus_UInt32  force_2d_en:1;
        RBus_UInt32  l_flag_fw:1;
        RBus_UInt32  field_fw:1;
        RBus_UInt32  field_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  film_condition:1;
        RBus_UInt32  pd_seq:5;
        RBus_UInt32  pd_switch:1;
        RBus_UInt32  merge_backward:1;
        RBus_UInt32  merge_forward:1;
    };
}vodma_vodma_v1_dcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_start:1;
        RBus_UInt32  crc_continuous:1;
        RBus_UInt32  res1:30;
    };
}vodma_vodma_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}vodma_vodma_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_pin_src:1;
        RBus_UInt32  gating_off:1;
        RBus_UInt32  chroma_lb_early_req_off:1;
        RBus_UInt32  chroma_lb_underflow_debug_cancel:1;
        RBus_UInt32  afifo_almost_empty_level:10;
        RBus_UInt32  res1:18;
    };
}vodma_vodma_rtl_improve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_y_nline:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  p_y_len:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  vs_toggle_reset:1;
    };
}vodma_vodma_v1_dsize_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_y_ads:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  p_u_ads:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  p_v_ads:7;
        RBus_UInt32  res3:9;
    };
}vodma_vodma_vd1_ads_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  st_adr:29;
    };
}vodma_vodma_v1_seq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  y_ha_shift:3;
        RBus_UInt32  res2:21;
    };
}vodma_vodma_v1_blk1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_y_offset:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  p_u_offset:12;
        RBus_UInt32  res2:4;
    };
}vodma_vodma_v1_blk2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_v_offset:12;
        RBus_UInt32  res1:20;
    };
}vodma_vodma_v1_blk3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_h_offset:10;
        RBus_UInt32  res1:22;
    };
}vodma_vodma_v1_blk4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u_h_offset:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v_h_offset:10;
        RBus_UInt32  res2:6;
    };
}vodma_vodma_v1_blk5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  st_adr:29;
    };
}vodma_vodma_v1_seq_3d_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  st_adr:29;
    };
}vodma_vodma_v1_seq_3d_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  st_adr:29;
    };
}vodma_vodma_v1_seq_3d_l2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  st_adr:29;
    };
}vodma_vodma_v1_seq_3d_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line_step:13;
        RBus_UInt32  res1:19;
    };
}vodma_vodma_v1_v_flip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  st_adr:29;
    };
}vodma_vodma_v1_seq_3d_l3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  st_adr:29;
    };
}vodma_vodma_v1_seq_3d_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  st_adr:29;
    };
}vodma_vodma_v1_seq_3d_l4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  st_adr:29;
    };
}vodma_vodma_v1_seq_3d_r4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tabsbs_merge:1;
        RBus_UInt32  tabsbs_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  p_y_nline:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  p_y_len:12;
        RBus_UInt32  res3:4;
    };
}vodma_vodma_tabsbs_merge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  st_adr:29;
    };
}vodma_vodma_tabsbs_seq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_y_ads:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  p_u_ads:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  p_v_ads:7;
        RBus_UInt32  res3:9;
    };
}vodma_vodma_tabsbs_ads_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  y_ha_shift:3;
        RBus_UInt32  res2:21;
    };
}vodma_vodma_tabsbs_blk1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_y_offset:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  p_u_offset:12;
        RBus_UInt32  res2:4;
    };
}vodma_vodma_tabsbs_blk2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_v_offset:12;
        RBus_UInt32  res1:20;
    };
}vodma_vodma_tabsbs_blk3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_h_offset:10;
        RBus_UInt32  res1:22;
    };
}vodma_vodma_tabsbs_blk4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u_h_offset:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v_h_offset:10;
        RBus_UInt32  res2:6;
    };
}vodma_vodma_tabsbs_blk5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_db_rdy:1;
        RBus_UInt32  vodma_db_en:1;
        RBus_UInt32  vodma_db_sel:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  i2rnd_db_rdy:1;
        RBus_UInt32  i2rnd_db_en:1;
        RBus_UInt32  i2rnd_db_sel:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  vodmavsg_db_rdy:1;
        RBus_UInt32  vodmavsg_db_en:1;
        RBus_UInt32  vodmavsg_db_sel:1;
        RBus_UInt32  res3:9;
        RBus_UInt32  vodmavsg_dbrdy_keep:1;
        RBus_UInt32  res4:3;
    };
}vodma_vodma_reg_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  encfmt:4;
        RBus_UInt32  alpha_position:1;
        RBus_UInt32  seq_color_swap:3;
        RBus_UInt32  g_position:2;
        RBus_UInt32  res1:22;
    };
}vodma_vodma_v1chroma_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode:3;
        RBus_UInt32  res1:29;
    };
}vodma_vodma_v1_cu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fir422_sel:2;
        RBus_UInt32  res1:30;
    };
}vodma_vodma_v1422_to_444_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c1_line_select:1;
        RBus_UInt32  y1_line_select:1;
        RBus_UInt32  res1:30;
    };
}vodma_vodma_line_select_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_thr:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  v_thr:12;
        RBus_UInt32  res2:2;
        RBus_UInt32  vthr_rst1:1;
        RBus_UInt32  res3:1;
    };
}vodma_vodma_v1sgen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_thr:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  top_fld_indc:1;
        RBus_UInt32  interlace:1;
        RBus_UInt32  vgip_en:1;
        RBus_UInt32  den_src:1;
        RBus_UInt32  res2:12;
    };
}vodma_vodma_v1int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_st:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
    };
}vodma_vodma_v1vgip_ivs1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_st:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
    };
}vodma_vodma_v1vgip_ivs2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_st:13;
        RBus_UInt32  res1:19;
    };
}vodma_vodma_v1vgip_ihs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_st:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
    };
}vodma_vodma_v1vgip_fd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_st:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
    };
}vodma_vodma_v1vgip_fd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_st:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  h_end:13;
        RBus_UInt32  res2:3;
    };
}vodma_vodma_v1vgip_hact_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_st:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
    };
}vodma_vodma_v1vgip_vact1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_st:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
    };
}vodma_vodma_v1vgip_vact2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_st:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  h_end:13;
        RBus_UInt32  res2:3;
    };
}vodma_vodma_v1vgip_hbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_st:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
    };
}vodma_vodma_v1vgip_vbg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_st:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v_end:12;
        RBus_UInt32  res2:4;
    };
}vodma_vodma_v1vgip_vbg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bg_y:10;
        RBus_UInt32  bg_u:10;
        RBus_UInt32  bg_v:10;
        RBus_UInt32  res1:2;
    };
}vodma_vodma_v1vgip_bg_clr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_data_en:2;
        RBus_UInt32  mask_den_en:1;
        RBus_UInt32  res1:29;
    };
}vodma_vodma_v1vgip_mask_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_st:16;
        RBus_UInt32  h_end:16;
    };
}vodma_vodma_v1vgip_hmask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_st:16;
        RBus_UInt32  v_end:16;
    };
}vodma_vodma_v1vgip_vmask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startx:14;
        RBus_UInt32  res1:1;
        RBus_UInt32  block_shape:1;
        RBus_UInt32  starty:14;
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
    };
}vodma_vodma_accessdata_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y10:10;
        RBus_UInt32  res2:6;
    };
}vodma_vodma_accessdata_y1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y01:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
    };
}vodma_vodma_accessdata_y2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
    };
}vodma_vodma_accessdata_c1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
    };
}vodma_vodma_accessdata_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u01:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
    };
}vodma_vodma_accessdata_c3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
    };
}vodma_vodma_accessdata_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y:10;
        RBus_UInt32  access_u:10;
        RBus_UInt32  access_v:10;
        RBus_UInt32  res1:2;
    };
}vodma_vodma_accessdata_clr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v2:12;
        RBus_UInt32  res2:4;
    };
}vodma_vodma_v1vgip_intpos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf_underflow_inte1:1;
        RBus_UInt32  finish_inte1:1;
        RBus_UInt32  vpos_inte1:1;
        RBus_UInt32  res1:28;
        RBus_UInt32  vodma_irq_ie:1;
    };
}vodma_vodma_vgip_intpos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf_underflow_ints1:1;
        RBus_UInt32  finish_ints1:1;
        RBus_UInt32  vpos_ints1:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  vodma_irq_record_ro:1;
        RBus_UInt32  decomp_irq_record_ro:1;
        RBus_UInt32  i2rnd_irq_record_ro:1;
        RBus_UInt32  hist_irq_record_ro:1;
    };
}vodma_vodma_vgip_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  field_status:1;
        RBus_UInt32  v_active:1;
        RBus_UInt32  vsync_status:1;
        RBus_UInt32  l_flag_status:1;
        RBus_UInt32  res1:28;
    };
}vodma_vodma_vgip_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line_cnt:12;
        RBus_UInt32  res1:20;
    };
}vodma_vodma_line_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_bist_mode_0:1;
        RBus_UInt32  vodma_bist_mode_1:1;
        RBus_UInt32  vodma_bist_mode_2:1;
        RBus_UInt32  res1:29;
    };
}vodma_vodma_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_bist_done_0:1;
        RBus_UInt32  vodma_bist_done_1:1;
        RBus_UInt32  vodma_bist_done_2:1;
        RBus_UInt32  res1:29;
    };
}vodma_vodma_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_bist_fail_group:1;
        RBus_UInt32  res1:31;
    };
}vodma_vodma_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_bist_fail_0:1;
        RBus_UInt32  vodma_bist_fail_1:1;
        RBus_UInt32  vodma_bist_fail_2:1;
        RBus_UInt32  vodma_bist_fail_3:1;
        RBus_UInt32  vodma_bist_fail_4:1;
        RBus_UInt32  vodma_bist_fail_5:1;
        RBus_UInt32  res1:26;
    };
}vodma_vodma_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_drf_mode_0:1;
        RBus_UInt32  vodma_drf_mode_1:1;
        RBus_UInt32  vodma_drf_mode_2:1;
        RBus_UInt32  res1:29;
    };
}vodma_vodma_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_drf_resume_0:1;
        RBus_UInt32  vodma_drf_resume_1:1;
        RBus_UInt32  vodma_drf_resume_2:1;
        RBus_UInt32  res1:29;
    };
}vodma_vodma_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_drf_done_0:1;
        RBus_UInt32  vodma_drf_done_1:1;
        RBus_UInt32  vodma_drf_done_2:1;
        RBus_UInt32  res1:29;
    };
}vodma_vodma_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_drf_pause_0:1;
        RBus_UInt32  vodma_drf_pause_1:1;
        RBus_UInt32  vodma_drf_pause_2:1;
        RBus_UInt32  res1:29;
    };
}vodma_vodma_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_drf_fail_group:1;
        RBus_UInt32  res1:31;
    };
}vodma_vodma_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_drf_fail_0:1;
        RBus_UInt32  vodma_drf_fail_1:1;
        RBus_UInt32  vodma_drf_fail_2:1;
        RBus_UInt32  vodma_drf_fail_3:1;
        RBus_UInt32  vodma_drf_fail_4:1;
        RBus_UInt32  vodma_drf_fail_5:1;
        RBus_UInt32  res1:26;
    };
}vodma_vodma_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodma_bist_rst_n_0:1;
        RBus_UInt32  vodma_bist_rme_0:1;
        RBus_UInt32  vodma_bist_rm_0:4;
        RBus_UInt32  vodma_bist_ls_0:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vodma_bist_rst_n_1:1;
        RBus_UInt32  vodma_bist_rme_1:1;
        RBus_UInt32  vodma_bist_rm_1:4;
        RBus_UInt32  vodma_bist_ls_1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vodma_bist_rst_n_2:1;
        RBus_UInt32  vodma_bist_rme_2:1;
        RBus_UInt32  vodma_bist_rm_2:4;
        RBus_UInt32  vodma_bist_ls_2:1;
        RBus_UInt32  res3:9;
    };
}vodma_vodma_bist_other_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel:5;
        RBus_UInt32  res1:27;
    };
}vodma_vodma_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_block_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  vodma_actv:1;
        RBus_UInt32  res2:27;
    };
}vodma_vodma_3d_cs_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cur_st_adr:29;
    };
}vodma_vodma_3d_cs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  quincunx_mode_fw:4;
        RBus_UInt32  quincunx_int_en:1;
        RBus_UInt32  quincunx_int_mode:2;
        RBus_UInt32  quincunx_mode_src_sel:1;
        RBus_UInt32  hori_drop_en:1;
        RBus_UInt32  hori_drop_mode:1;
        RBus_UInt32  dummy180050d0_10:1;
        RBus_UInt32  dummy180050d0_31_11:21;
    };
}vodma_vodma_quincunx_setting_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  quincunx_mode_b1:4;
        RBus_UInt32  quincunx_mode_b0:4;
        RBus_UInt32  res1:24;
    };
}vodma_vodma_quincunx_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcnt_pre_num:28;
        RBus_UInt32  smooth_en:1;
        RBus_UInt32  gate_period:3;
    };
}vodma_vodma_smooth_toggle_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_trans_en:1;
        RBus_UInt32  blockmode_sel_y:2;
        RBus_UInt32  block_burst_len:1;
        RBus_UInt32  burst_len:1;
        RBus_UInt32  blockmode_sel_c:2;
        RBus_UInt32  res1:21;
        RBus_UInt32  max_mrs_num:3;
        RBus_UInt32  mrs_mode:1;
    };
}vodma_vodma_dma_option_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iv2pv_dly:24;
        RBus_UInt32  iv_src_sel:3;
        RBus_UInt32  iv_inv_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pfgen_inv:1;
        RBus_UInt32  en_pfgen:1;
        RBus_UInt32  en_pvgen:1;
    };
}vodma_vodma_pvs0_gen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pvs0_free_period:28;
        RBus_UInt32  pvs0_free_period_update:1;
        RBus_UInt32  pvs0_free_vs_reset_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pvs0_free_en:1;
    };
}vodma_vodma_pvs_free_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_one_vs:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pvs0_free_vs_inv_en:1;
        RBus_UInt32  pvs0_free_l_flag_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  pvs0_free_vs_sel:3;
        RBus_UInt32  dummy18005308_29_11:19;
        RBus_UInt32  pvs0_free_clk_sel:2;
    };
}vodma_vodma_pvs_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_fifo_full_gate:1;
        RBus_UInt32  gating_src_sel:2;
        RBus_UInt32  en_fifo_empty_gate:1;
        RBus_UInt32  vodma_clk_sel:3;
        RBus_UInt32  dummy18005310_15_7:9;
        RBus_UInt32  vodma_clk_ratio_n_off:5;
        RBus_UInt32  res1:2;
        RBus_UInt32  vodma_clk_div_n:5;
        RBus_UInt32  vodma_clk_div2_en:1;
        RBus_UInt32  vodma_clk_div2_en_src_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vodma_enclk:1;
    };
}vodma_vodma_clkgen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pvs0_vs_width:28;
        RBus_UInt32  dummy18005314_31_28:4;
    };
}vodma_vodma_pvs_width_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pe_number:28;
        RBus_UInt32  res1:3;
        RBus_UInt32  phase_err_measure_start:1;
    };
}vodma_vodma_phase_error_for_2vs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  manual_vs:1;
    };
}vodma_vodma_manual_vs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  db_vs_sel_rwd1:2;
    };
}vodma_vodma_reg_db_vsync_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decomp_wrap_en:1;
        RBus_UInt32  lossy_en:1;
        RBus_UInt32  decomp_bypass_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  header_num_4line_sys:8;
        RBus_UInt32  decomp_bpp_sys:4;
        RBus_UInt32  wrap_v_flip_en:1;
        RBus_UInt32  wrap_v_div2_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  wrap_line_num_sys:12;
    };
}vodma_decomp_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  header_num_4line_vodma:8;
        RBus_UInt32  decomp_bpp_vodma:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  wrap_line_num_vodma:12;
    };
}vodma_decomp_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrap_y_data_read_len:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  warp_y_data_wtlvl:9;
        RBus_UInt32  res2:7;
    };
}vodma_decomp_ydma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrap_c_data_read_len:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  wrap_c_data_wtlvl:9;
        RBus_UInt32  res2:7;
    };
}vodma_decomp_cdma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wapp_y_data_pic_set:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  wapp_c_data_pic_set:8;
        RBus_UInt32  res2:8;
    };
}vodma_decomp_pic_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  wapp_y_header_read_addr:29;
    };
}vodma_decomp_read_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  wapp_c_header_read_addr:29;
    };
}vodma_decomp_read_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrap_data_wid_y:10;
        RBus_UInt32  res1:22;
    };
}vodma_decomp_x_wid_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrap_data_wid_c:10;
        RBus_UInt32  res1:22;
    };
}vodma_decomp_x_wid_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_y_hd_4line_step:29;
    };
}vodma_decomp_dma_read_hd_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_c_hd_4line_step:29;
    };
}vodma_decomp_dma_read_hd_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_y_hd_blk_len:8;
        RBus_UInt32  dma_c_hd_blk_len:8;
        RBus_UInt32  res1:14;
        RBus_UInt32  dma_y_hd_mode:1;
        RBus_UInt32  dma_c_hd_mode:1;
    };
}vodma_decomp_hd_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrap_y_dma_fifoempty:1;
        RBus_UInt32  wrap_y_dma_fifofull:1;
        RBus_UInt32  wrap_y_dma_req_error:1;
        RBus_UInt32  wrap_y_dma_fifoof:1;
        RBus_UInt32  wrap_y_head_fifoempty:1;
        RBus_UInt32  wrap_y_head_fifofull:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  wrap_y_head_fifoof:1;
        RBus_UInt32  wrap_y_data_fifoempty:1;
        RBus_UInt32  wrap_y_data_fifofull:1;
        RBus_UInt32  wrap_y_data_fifouf:1;
        RBus_UInt32  wrap_y_data_fifoof:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  wrap_c_dma_fifoempty:1;
        RBus_UInt32  wrap_c_dma_fifofull:1;
        RBus_UInt32  wrap_c_dma_req_error:1;
        RBus_UInt32  wrap_c_dma_fifoof:1;
        RBus_UInt32  wrap_c_head_fifoempty:1;
        RBus_UInt32  wrap_c_head_fifofull:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  wrap_c_head_fifoof:1;
        RBus_UInt32  wrap_c_data_fifoempty:1;
        RBus_UInt32  wrap_c_data_fifofull:1;
        RBus_UInt32  wrap_c_data_fifouf:1;
        RBus_UInt32  wrap_c_data_fifoof:1;
        RBus_UInt32  res4:4;
    };
}vodma_decomp_dma_ststus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  wrap_y_dma_fifoof_ie:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  wrap_y_head_fifoof_ie:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  wrap_y_data_fifouf_ie:1;
        RBus_UInt32  wrap_y_data_fifoof_ie:1;
        RBus_UInt32  res4:7;
        RBus_UInt32  wrap_c_dma_fifoof_ie:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  wrap_c_head_fifoof_ie:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  wrap_c_data_fifouf_ie:1;
        RBus_UInt32  wrap_c_data_fifoof_ie:1;
        RBus_UInt32  res7:4;
    };
}vodma_decomp_dma_ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  decomp_core2_irq:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  decomp_core_irq:1;
    };
}vodma_decomp_core_status_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decomp_core_errflag:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  decomp_core2_errflag:8;
        RBus_UInt32  res2:8;
    };
}vodma_decomp_core_status_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decomp_core_errflag_clr:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  decomp_core2_errflag_clr:8;
        RBus_UInt32  res2:8;
    };
}vodma_decomp_core_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decomp_core_flag2irq_en:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  decomp_core2_flag2irq_en:8;
        RBus_UInt32  res2:8;
    };
}vodma_decomp_core_status_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_timing_en:1;
        RBus_UInt32  i2rnd_timing_mode:2;
        RBus_UInt32  i2rnd_src_flag_inv:1;
        RBus_UInt32  debug_mask_repeat_sub_old_en:1;
        RBus_UInt32  debug_mask_sub2:1;
        RBus_UInt32  debug_mask_sub1:1;
        RBus_UInt32  debug_mask_main:1;
        RBus_UInt32  i2rnd_flag_fifo_en:1;
        RBus_UInt32  i2rnd_flag_fifo_mode:1;
        RBus_UInt32  res1:22;
    };
}vodma_vodma_i2rnd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_m_lflag_sel:3;
        RBus_UInt32  i2rnd_m_lflag_free_run:1;
        RBus_UInt32  i2rnd_m_lflag_fw:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  i2rnd_m_field_sel:3;
        RBus_UInt32  i2rnd_m_field_free_run:1;
        RBus_UInt32  i2rnd_m_field_fw:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  i2rnd_m_block_sel:3;
        RBus_UInt32  i2rnd_m_block_free_run:1;
        RBus_UInt32  i2rnd_m_block_fw:2;
        RBus_UInt32  i2rnd_m_nxt_rpt_flag_sel:1;
        RBus_UInt32  i2rnd_m_nxt_rpt_flag_fw:1;
        RBus_UInt32  i2rnd_m_quincunx_fw:4;
        RBus_UInt32  i2rnd_m_quincunx_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  i2rnd_hw_nxt_rpt_flag_m_en:1;
        RBus_UInt32  i2rnd_hw_mask_repeat_frame_m_en:1;
    };
}vodma_vodma_i2rnd_m_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_s_lflag_sel:3;
        RBus_UInt32  i2rnd_s_lflag_free_run:1;
        RBus_UInt32  i2rnd_s_lflag_fw:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  i2rnd_s_field_sel:3;
        RBus_UInt32  i2rnd_s_field_free_run:1;
        RBus_UInt32  i2rnd_s_field_fw:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  i2rnd_s_block_sel:3;
        RBus_UInt32  i2rnd_s_block_free_run:1;
        RBus_UInt32  i2rnd_s_block_fw:2;
        RBus_UInt32  i2rnd_s_nxt_rpt_flag_sel:1;
        RBus_UInt32  i2rnd_s_nxt_rpt_flag_fw:1;
        RBus_UInt32  i2rnd_s_quincunx_fw:4;
        RBus_UInt32  i2rnd_s_quincunx_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  i2rnd_hw_nxt_rpt_flag_s_en:1;
        RBus_UInt32  i2rnd_hw_mask_repeat_frame_s_en:1;
    };
}vodma_vodma_i2rnd_s_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_not_finish_irq_en:1;
        RBus_UInt32  i2rnd_m_load_over_max_irq_en:1;
        RBus_UInt32  i2rnd_s_load_over_max_irq_en:1;
        RBus_UInt32  i2rnd_load_hit_den_irq_en:1;
        RBus_UInt32  res1:28;
    };
}vodma_vodma_i2rnd_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_not_finish_irq_st:1;
        RBus_UInt32  i2rnd_m_load_over_max_irq_st:1;
        RBus_UInt32  i2rnd_s_load_over_max_irq_st:1;
        RBus_UInt32  i2rnd_load_hit_den_irq_st:1;
        RBus_UInt32  res1:28;
    };
}vodma_vodma_i2rnd_irq_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_m_mask_frame_cnt:8;
        RBus_UInt32  i2rnd_s_mask_frame_cnt:8;
        RBus_UInt32  i2rnd_ori_frame_cnt:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  i2rnd_frame_measure:1;
    };
}vodma_vodma_i2rnd_measure_frame_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_info_rptr_dispm:4;
        RBus_UInt32  dma_info_wptr_dispm:4;
        RBus_UInt32  dma_info_rptr_i3ddma:4;
        RBus_UInt32  dma_info_wptr_i3ddma:4;
        RBus_UInt32  dma_info_water_dispm:4;
        RBus_UInt32  dma_info_water_i3ddma:4;
        RBus_UInt32  res1:6;
        RBus_UInt32  info_dispm_overflow:1;
        RBus_UInt32  info_i3ddma_overflow:1;
    };
}vodma_vodma_i2rnd_fifo_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_st:3;
        RBus_UInt32  i2rnd_src_flag:1;
        RBus_UInt32  i2rnd_lflag:1;
        RBus_UInt32  i2rnd_field:1;
        RBus_UInt32  i2rnd_block:2;
        RBus_UInt32  i2rnd_m_lflag:1;
        RBus_UInt32  i2rnd_m_field:1;
        RBus_UInt32  i2rnd_m_block:2;
        RBus_UInt32  i2rnd_s_lflag:1;
        RBus_UInt32  i2rnd_s_field:1;
        RBus_UInt32  i2rnd_s_block:2;
        RBus_UInt32  i2rnd_quincunx:4;
        RBus_UInt32  i2rnd_m_quincunx:4;
        RBus_UInt32  i2rnd_s_quincunx:4;
        RBus_UInt32  i2rnd_nxt_rpt_flag:1;
        RBus_UInt32  i2rnd_m_nxt_rpt_flag:1;
        RBus_UInt32  i2rnd_s_nxt_rpt_flag:1;
        RBus_UInt32  res1:1;
    };
}vodma_vodma_i2rnd_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_info_th_dispm:4;
        RBus_UInt32  dma_info_th_i3ddma:4;
        RBus_UInt32  dram_buf_num_dispm:4;
        RBus_UInt32  dram_buf_num_i3ddma:4;
        RBus_UInt32  res1:14;
        RBus_UInt32  flag_fifo_style_dispm:1;
        RBus_UInt32  flag_fifo_style_i3ddma:1;
    };
}vodma_vodma_i2rnd_fifo_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_info_rptr_fw_i3ddma:4;
        RBus_UInt32  dma_info_rptr_fw_set_i3ddma:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_info_rptr_fw_dispm:4;
        RBus_UInt32  dma_info_rptr_fw_set_dispm:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dma_info_wptr_fw_i3ddma:4;
        RBus_UInt32  dma_info_wptr_fw_set_i3ddma:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  dma_info_wptr_fw_dispm:4;
        RBus_UInt32  dma_info_wptr_fw_set_dispm:1;
        RBus_UInt32  res4:3;
    };
}vodma_vodma_i2rnd_dma_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_m_period_load:28;
        RBus_UInt32  res1:3;
        RBus_UInt32  i2rnd_period_clk_src:1;
    };
}vodma_vodma_i2rnd_m_period_load_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_m_period:28;
        RBus_UInt32  res1:4;
    };
}vodma_vodma_i2rnd_m_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_s_period_load:28;
        RBus_UInt32  res1:4;
    };
}vodma_vodma_i2rnd_s_period_load_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_s_period:28;
        RBus_UInt32  res1:4;
    };
}vodma_vodma_i2rnd_s_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_m_load_time:28;
        RBus_UInt32  res1:2;
        RBus_UInt32  i2rnd_load_time_measure_long_term:1;
        RBus_UInt32  i2rnd_load_time_measure:1;
    };
}vodma_vodma_i2rnd_m_measure_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_s_load_time:28;
        RBus_UInt32  res1:4;
    };
}vodma_vodma_i2rnd_s_measure_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_m_period_load_max:28;
        RBus_UInt32  res1:2;
        RBus_UInt32  i2rnd_period_load_max_dbg_en:1;
        RBus_UInt32  i2rnd_period_load_max_measure_en:1;
    };
}vodma_vodma_i2rnd_m_period_load_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_s_period_load_max:28;
        RBus_UInt32  res1:4;
    };
}vodma_vodma_i2rnd_s_period_load_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timing_monitor_end1:4;
        RBus_UInt32  timing_monitor_sta1:4;
        RBus_UInt32  timing_monitor_end0:4;
        RBus_UInt32  timing_monitor_sta0:4;
        RBus_UInt32  res1:8;
        RBus_UInt32  timing_monitor_compare:2;
        RBus_UInt32  timing_monitor_multi_mode:1;
        RBus_UInt32  timing_monitor_unit:1;
        RBus_UInt32  timing_monitor_src:1;
        RBus_UInt32  timing_monitor_i2rnd_mode:2;
        RBus_UInt32  timing_monitor_en:1;
    };
}vodma_vodma_timing_monitor_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timing_monitor_end5:4;
        RBus_UInt32  timing_monitor_sta5:4;
        RBus_UInt32  timing_monitor_end4:4;
        RBus_UInt32  timing_monitor_sta4:4;
        RBus_UInt32  timing_monitor_end3:4;
        RBus_UInt32  timing_monitor_sta3:4;
        RBus_UInt32  timing_monitor_end2:4;
        RBus_UInt32  timing_monitor_sta2:4;
    };
}vodma_vodma_timing_monitor_multi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_compare_th:28;
        RBus_UInt32  res1:4;
    };
}vodma_vodma_timing_monitor_compare_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_golden:28;
        RBus_UInt32  res1:4;
    };
}vodma_vodma_timing_monitor_golden_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_result_previous1:28;
        RBus_UInt32  res1:4;
    };
}vodma_vodma_timing_monitor_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_result_previous2:28;
        RBus_UInt32  res1:4;
    };
}vodma_vodma_timing_monitor_result2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_result_previous3:28;
        RBus_UInt32  res1:4;
    };
}vodma_vodma_timing_monitor_result3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_result_previous4:28;
        RBus_UInt32  res1:4;
    };
}vodma_vodma_timing_monitor_result4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_result_max:28;
        RBus_UInt32  res1:4;
    };
}vodma_vodma_timing_monitor_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_result_min:28;
        RBus_UInt32  res1:4;
    };
}vodma_vodma_timing_monitor_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_hit_den_error:1;
        RBus_UInt32  hsync_hit_den_error:1;
        RBus_UInt32  compare_hit:1;
        RBus_UInt32  res1:29;
    };
}vodma_vodma_timing_monitor_st_RBUS;




#endif


#endif
