/**
* @file rbusEmmc_wrapReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_EMMC_WRAP_REG_H_
#define _RBUS_EMMC_WRAP_REG_H_

#include "rbus_types.h"



//  EMMC_WRAP Register Address
#define  EMMC_WRAP_emmc_scpu_sel                                                 0x18010800
#define  EMMC_WRAP_emmc_scpu_sel_reg_addr                                        "0xB8010800"
#define  EMMC_WRAP_emmc_scpu_sel_reg                                             0xB8010800
#define  EMMC_WRAP_emmc_scpu_sel_inst_addr                                       "0x0000"
#define  set_EMMC_WRAP_emmc_scpu_sel_reg(data)                                   (*((volatile unsigned int*)EMMC_WRAP_emmc_scpu_sel_reg)=data)
#define  get_EMMC_WRAP_emmc_scpu_sel_reg                                         (*((volatile unsigned int*)EMMC_WRAP_emmc_scpu_sel_reg))
#define  EMMC_WRAP_emmc_scpu_sel_scpu_stop_shift                                 (2)
#define  EMMC_WRAP_emmc_scpu_sel_scpu_status_shift                               (1)
#define  EMMC_WRAP_emmc_scpu_sel_scpu_sel_shift                                  (0)
#define  EMMC_WRAP_emmc_scpu_sel_scpu_stop_mask                                  (0x00000004)
#define  EMMC_WRAP_emmc_scpu_sel_scpu_status_mask                                (0x00000002)
#define  EMMC_WRAP_emmc_scpu_sel_scpu_sel_mask                                   (0x00000001)
#define  EMMC_WRAP_emmc_scpu_sel_scpu_stop(data)                                 (0x00000004&((data)<<2))
#define  EMMC_WRAP_emmc_scpu_sel_scpu_status(data)                               (0x00000002&((data)<<1))
#define  EMMC_WRAP_emmc_scpu_sel_scpu_sel(data)                                  (0x00000001&(data))
#define  EMMC_WRAP_emmc_scpu_sel_get_scpu_stop(data)                             ((0x00000004&(data))>>2)
#define  EMMC_WRAP_emmc_scpu_sel_get_scpu_status(data)                           ((0x00000002&(data))>>1)
#define  EMMC_WRAP_emmc_scpu_sel_get_scpu_sel(data)                              (0x00000001&(data))

#define  EMMC_WRAP_emmc_int_status                                               0x18010804
#define  EMMC_WRAP_emmc_int_status_reg_addr                                      "0xB8010804"
#define  EMMC_WRAP_emmc_int_status_reg                                           0xB8010804
#define  EMMC_WRAP_emmc_int_status_inst_addr                                     "0x0001"
#define  set_EMMC_WRAP_emmc_int_status_reg(data)                                 (*((volatile unsigned int*)EMMC_WRAP_emmc_int_status_reg)=data)
#define  get_EMMC_WRAP_emmc_int_status_reg                                       (*((volatile unsigned int*)EMMC_WRAP_emmc_int_status_reg))
#define  EMMC_WRAP_emmc_int_status_dma_rd_done_scpu_shift                        (2)
#define  EMMC_WRAP_emmc_int_status_dma_wr_done_scpu_shift                        (1)
#define  EMMC_WRAP_emmc_int_status_stop_by_kcpu_force_scpu_shift                 (0)
#define  EMMC_WRAP_emmc_int_status_dma_rd_done_scpu_mask                         (0x00000004)
#define  EMMC_WRAP_emmc_int_status_dma_wr_done_scpu_mask                         (0x00000002)
#define  EMMC_WRAP_emmc_int_status_stop_by_kcpu_force_scpu_mask                  (0x00000001)
#define  EMMC_WRAP_emmc_int_status_dma_rd_done_scpu(data)                        (0x00000004&((data)<<2))
#define  EMMC_WRAP_emmc_int_status_dma_wr_done_scpu(data)                        (0x00000002&((data)<<1))
#define  EMMC_WRAP_emmc_int_status_stop_by_kcpu_force_scpu(data)                 (0x00000001&(data))
#define  EMMC_WRAP_emmc_int_status_get_dma_rd_done_scpu(data)                    ((0x00000004&(data))>>2)
#define  EMMC_WRAP_emmc_int_status_get_dma_wr_done_scpu(data)                    ((0x00000002&(data))>>1)
#define  EMMC_WRAP_emmc_int_status_get_stop_by_kcpu_force_scpu(data)             (0x00000001&(data))

#define  EMMC_WRAP_emmc_int_mask                                                 0x18010808
#define  EMMC_WRAP_emmc_int_mask_reg_addr                                        "0xB8010808"
#define  EMMC_WRAP_emmc_int_mask_reg                                             0xB8010808
#define  EMMC_WRAP_emmc_int_mask_inst_addr                                       "0x0002"
#define  set_EMMC_WRAP_emmc_int_mask_reg(data)                                   (*((volatile unsigned int*)EMMC_WRAP_emmc_int_mask_reg)=data)
#define  get_EMMC_WRAP_emmc_int_mask_reg                                         (*((volatile unsigned int*)EMMC_WRAP_emmc_int_mask_reg))
#define  EMMC_WRAP_emmc_int_mask_dma_rd_done_mask_scpu_shift                     (2)
#define  EMMC_WRAP_emmc_int_mask_dma_wr_done_mask_scpu_shift                     (1)
#define  EMMC_WRAP_emmc_int_mask_stop_by_kcpu_force_mask_scpu_shift              (0)
#define  EMMC_WRAP_emmc_int_mask_dma_rd_done_mask_scpu_mask                      (0x00000004)
#define  EMMC_WRAP_emmc_int_mask_dma_wr_done_mask_scpu_mask                      (0x00000002)
#define  EMMC_WRAP_emmc_int_mask_stop_by_kcpu_force_mask_scpu_mask               (0x00000001)
#define  EMMC_WRAP_emmc_int_mask_dma_rd_done_mask_scpu(data)                     (0x00000004&((data)<<2))
#define  EMMC_WRAP_emmc_int_mask_dma_wr_done_mask_scpu(data)                     (0x00000002&((data)<<1))
#define  EMMC_WRAP_emmc_int_mask_stop_by_kcpu_force_mask_scpu(data)              (0x00000001&(data))
#define  EMMC_WRAP_emmc_int_mask_get_dma_rd_done_mask_scpu(data)                 ((0x00000004&(data))>>2)
#define  EMMC_WRAP_emmc_int_mask_get_dma_wr_done_mask_scpu(data)                 ((0x00000002&(data))>>1)
#define  EMMC_WRAP_emmc_int_mask_get_stop_by_kcpu_force_mask_scpu(data)          (0x00000001&(data))

#define  EMMC_WRAP_emmc_kcpu_sel                                                 0x18010810
#define  EMMC_WRAP_emmc_kcpu_sel_reg_addr                                        "0xB8010810"
#define  EMMC_WRAP_emmc_kcpu_sel_reg                                             0xB8010810
#define  EMMC_WRAP_emmc_kcpu_sel_inst_addr                                       "0x0003"
#define  set_EMMC_WRAP_emmc_kcpu_sel_reg(data)                                   (*((volatile unsigned int*)EMMC_WRAP_emmc_kcpu_sel_reg)=data)
#define  get_EMMC_WRAP_emmc_kcpu_sel_reg                                         (*((volatile unsigned int*)EMMC_WRAP_emmc_kcpu_sel_reg))
#define  EMMC_WRAP_emmc_kcpu_sel_kcpu_force_en_shift                             (3)
#define  EMMC_WRAP_emmc_kcpu_sel_protect_addr_en_shift                           (2)
#define  EMMC_WRAP_emmc_kcpu_sel_kcpu_status_shift                               (1)
#define  EMMC_WRAP_emmc_kcpu_sel_kcpu_sel_shift                                  (0)
#define  EMMC_WRAP_emmc_kcpu_sel_kcpu_force_en_mask                              (0x00000008)
#define  EMMC_WRAP_emmc_kcpu_sel_protect_addr_en_mask                            (0x00000004)
#define  EMMC_WRAP_emmc_kcpu_sel_kcpu_status_mask                                (0x00000002)
#define  EMMC_WRAP_emmc_kcpu_sel_kcpu_sel_mask                                   (0x00000001)
#define  EMMC_WRAP_emmc_kcpu_sel_kcpu_force_en(data)                             (0x00000008&((data)<<3))
#define  EMMC_WRAP_emmc_kcpu_sel_protect_addr_en(data)                           (0x00000004&((data)<<2))
#define  EMMC_WRAP_emmc_kcpu_sel_kcpu_status(data)                               (0x00000002&((data)<<1))
#define  EMMC_WRAP_emmc_kcpu_sel_kcpu_sel(data)                                  (0x00000001&(data))
#define  EMMC_WRAP_emmc_kcpu_sel_get_kcpu_force_en(data)                         ((0x00000008&(data))>>3)
#define  EMMC_WRAP_emmc_kcpu_sel_get_protect_addr_en(data)                       ((0x00000004&(data))>>2)
#define  EMMC_WRAP_emmc_kcpu_sel_get_kcpu_status(data)                           ((0x00000002&(data))>>1)
#define  EMMC_WRAP_emmc_kcpu_sel_get_kcpu_sel(data)                              (0x00000001&(data))

#define  EMMC_WRAP_emmc_start_protect_addr                                       0x18010814
#define  EMMC_WRAP_emmc_start_protect_addr_reg_addr                              "0xB8010814"
#define  EMMC_WRAP_emmc_start_protect_addr_reg                                   0xB8010814
#define  EMMC_WRAP_emmc_start_protect_addr_inst_addr                             "0x0004"
#define  set_EMMC_WRAP_emmc_start_protect_addr_reg(data)                         (*((volatile unsigned int*)EMMC_WRAP_emmc_start_protect_addr_reg)=data)
#define  get_EMMC_WRAP_emmc_start_protect_addr_reg                               (*((volatile unsigned int*)EMMC_WRAP_emmc_start_protect_addr_reg))
#define  EMMC_WRAP_emmc_start_protect_addr_start_proct_addr_shift                (0)
#define  EMMC_WRAP_emmc_start_protect_addr_start_proct_addr_mask                 (0xFFFFFFFF)
#define  EMMC_WRAP_emmc_start_protect_addr_start_proct_addr(data)                (0xFFFFFFFF&(data))
#define  EMMC_WRAP_emmc_start_protect_addr_get_start_proct_addr(data)            (0xFFFFFFFF&(data))

#define  EMMC_WRAP_emmc_end_protect_addr                                         0x18010818
#define  EMMC_WRAP_emmc_end_protect_addr_reg_addr                                "0xB8010818"
#define  EMMC_WRAP_emmc_end_protect_addr_reg                                     0xB8010818
#define  EMMC_WRAP_emmc_end_protect_addr_inst_addr                               "0x0005"
#define  set_EMMC_WRAP_emmc_end_protect_addr_reg(data)                           (*((volatile unsigned int*)EMMC_WRAP_emmc_end_protect_addr_reg)=data)
#define  get_EMMC_WRAP_emmc_end_protect_addr_reg                                 (*((volatile unsigned int*)EMMC_WRAP_emmc_end_protect_addr_reg))
#define  EMMC_WRAP_emmc_end_protect_addr_end_proct_addr_shift                    (0)
#define  EMMC_WRAP_emmc_end_protect_addr_end_proct_addr_mask                     (0xFFFFFFFF)
#define  EMMC_WRAP_emmc_end_protect_addr_end_proct_addr(data)                    (0xFFFFFFFF&(data))
#define  EMMC_WRAP_emmc_end_protect_addr_get_end_proct_addr(data)                (0xFFFFFFFF&(data))

#define  EMMC_WRAP_emmc_int_status_kcpu                                          0x1801081C
#define  EMMC_WRAP_emmc_int_status_kcpu_reg_addr                                 "0xB801081C"
#define  EMMC_WRAP_emmc_int_status_kcpu_reg                                      0xB801081C
#define  EMMC_WRAP_emmc_int_status_kcpu_inst_addr                                "0x0006"
#define  set_EMMC_WRAP_emmc_int_status_kcpu_reg(data)                            (*((volatile unsigned int*)EMMC_WRAP_emmc_int_status_kcpu_reg)=data)
#define  get_EMMC_WRAP_emmc_int_status_kcpu_reg                                  (*((volatile unsigned int*)EMMC_WRAP_emmc_int_status_kcpu_reg))
#define  EMMC_WRAP_emmc_int_status_kcpu_dma_rd_done_kcpu_shift                   (2)
#define  EMMC_WRAP_emmc_int_status_kcpu_dma_wr_done_kcpu_shift                   (1)
#define  EMMC_WRAP_emmc_int_status_kcpu_protect_hit_kcpu_shift                   (0)
#define  EMMC_WRAP_emmc_int_status_kcpu_dma_rd_done_kcpu_mask                    (0x00000004)
#define  EMMC_WRAP_emmc_int_status_kcpu_dma_wr_done_kcpu_mask                    (0x00000002)
#define  EMMC_WRAP_emmc_int_status_kcpu_protect_hit_kcpu_mask                    (0x00000001)
#define  EMMC_WRAP_emmc_int_status_kcpu_dma_rd_done_kcpu(data)                   (0x00000004&((data)<<2))
#define  EMMC_WRAP_emmc_int_status_kcpu_dma_wr_done_kcpu(data)                   (0x00000002&((data)<<1))
#define  EMMC_WRAP_emmc_int_status_kcpu_protect_hit_kcpu(data)                   (0x00000001&(data))
#define  EMMC_WRAP_emmc_int_status_kcpu_get_dma_rd_done_kcpu(data)               ((0x00000004&(data))>>2)
#define  EMMC_WRAP_emmc_int_status_kcpu_get_dma_wr_done_kcpu(data)               ((0x00000002&(data))>>1)
#define  EMMC_WRAP_emmc_int_status_kcpu_get_protect_hit_kcpu(data)               (0x00000001&(data))

#define  EMMC_WRAP_emmc_int_mask_kcpu                                            0x18010820
#define  EMMC_WRAP_emmc_int_mask_kcpu_reg_addr                                   "0xB8010820"
#define  EMMC_WRAP_emmc_int_mask_kcpu_reg                                        0xB8010820
#define  EMMC_WRAP_emmc_int_mask_kcpu_inst_addr                                  "0x0007"
#define  set_EMMC_WRAP_emmc_int_mask_kcpu_reg(data)                              (*((volatile unsigned int*)EMMC_WRAP_emmc_int_mask_kcpu_reg)=data)
#define  get_EMMC_WRAP_emmc_int_mask_kcpu_reg                                    (*((volatile unsigned int*)EMMC_WRAP_emmc_int_mask_kcpu_reg))
#define  EMMC_WRAP_emmc_int_mask_kcpu_dma_rd_done_mask_kcpu_shift                (2)
#define  EMMC_WRAP_emmc_int_mask_kcpu_dma_wr_done_mask_kcpu_shift                (1)
#define  EMMC_WRAP_emmc_int_mask_kcpu_protect_hit_mask_kcpu_shift                (0)
#define  EMMC_WRAP_emmc_int_mask_kcpu_dma_rd_done_mask_kcpu_mask                 (0x00000004)
#define  EMMC_WRAP_emmc_int_mask_kcpu_dma_wr_done_mask_kcpu_mask                 (0x00000002)
#define  EMMC_WRAP_emmc_int_mask_kcpu_protect_hit_mask_kcpu_mask                 (0x00000001)
#define  EMMC_WRAP_emmc_int_mask_kcpu_dma_rd_done_mask_kcpu(data)                (0x00000004&((data)<<2))
#define  EMMC_WRAP_emmc_int_mask_kcpu_dma_wr_done_mask_kcpu(data)                (0x00000002&((data)<<1))
#define  EMMC_WRAP_emmc_int_mask_kcpu_protect_hit_mask_kcpu(data)                (0x00000001&(data))
#define  EMMC_WRAP_emmc_int_mask_kcpu_get_dma_rd_done_mask_kcpu(data)            ((0x00000004&(data))>>2)
#define  EMMC_WRAP_emmc_int_mask_kcpu_get_dma_wr_done_mask_kcpu(data)            ((0x00000002&(data))>>1)
#define  EMMC_WRAP_emmc_int_mask_kcpu_get_protect_hit_mask_kcpu(data)            (0x00000001&(data))

#define  EMMC_WRAP_emmc_wrap_ctrl                                                0x18010830
#define  EMMC_WRAP_emmc_wrap_ctrl_reg_addr                                       "0xB8010830"
#define  EMMC_WRAP_emmc_wrap_ctrl_reg                                            0xB8010830
#define  EMMC_WRAP_emmc_wrap_ctrl_inst_addr                                      "0x0008"
#define  set_EMMC_WRAP_emmc_wrap_ctrl_reg(data)                                  (*((volatile unsigned int*)EMMC_WRAP_emmc_wrap_ctrl_reg)=data)
#define  get_EMMC_WRAP_emmc_wrap_ctrl_reg                                        (*((volatile unsigned int*)EMMC_WRAP_emmc_wrap_ctrl_reg))
#define  EMMC_WRAP_emmc_wrap_ctrl_cp_blk_len_shift                               (16)
#define  EMMC_WRAP_emmc_wrap_ctrl_cp_mode_en_shift                               (15)
#define  EMMC_WRAP_emmc_wrap_ctrl_dummy_reg_shift                                (13)
#define  EMMC_WRAP_emmc_wrap_ctrl_cclk_in_sample_ext_en_shift                    (12)
#define  EMMC_WRAP_emmc_wrap_ctrl_eco_option0_dis_shift                          (11)
#define  EMMC_WRAP_emmc_wrap_ctrl_m_hbigendian_shift                             (10)
#define  EMMC_WRAP_emmc_wrap_ctrl_s_hbigendian_shift                             (9)
#define  EMMC_WRAP_emmc_wrap_ctrl_cclk_out_src_sel_shift                         (8)
#define  EMMC_WRAP_emmc_wrap_ctrl_wrap_version_shift                             (7)
#define  EMMC_WRAP_emmc_wrap_ctrl_debug_mux_shift                                (1)
#define  EMMC_WRAP_emmc_wrap_ctrl_debug_ctrl_shift                               (0)
#define  EMMC_WRAP_emmc_wrap_ctrl_cp_blk_len_mask                                (0x7FFF0000)
#define  EMMC_WRAP_emmc_wrap_ctrl_cp_mode_en_mask                                (0x00008000)
#define  EMMC_WRAP_emmc_wrap_ctrl_dummy_reg_mask                                 (0x00002000)
#define  EMMC_WRAP_emmc_wrap_ctrl_cclk_in_sample_ext_en_mask                     (0x00001000)
#define  EMMC_WRAP_emmc_wrap_ctrl_eco_option0_dis_mask                           (0x00000800)
#define  EMMC_WRAP_emmc_wrap_ctrl_m_hbigendian_mask                              (0x00000400)
#define  EMMC_WRAP_emmc_wrap_ctrl_s_hbigendian_mask                              (0x00000200)
#define  EMMC_WRAP_emmc_wrap_ctrl_cclk_out_src_sel_mask                          (0x00000100)
#define  EMMC_WRAP_emmc_wrap_ctrl_wrap_version_mask                              (0x00000080)
#define  EMMC_WRAP_emmc_wrap_ctrl_debug_mux_mask                                 (0x0000007E)
#define  EMMC_WRAP_emmc_wrap_ctrl_debug_ctrl_mask                                (0x00000001)
#define  EMMC_WRAP_emmc_wrap_ctrl_cp_blk_len(data)                               (0x7FFF0000&((data)<<16))
#define  EMMC_WRAP_emmc_wrap_ctrl_cp_mode_en(data)                               (0x00008000&((data)<<15))
#define  EMMC_WRAP_emmc_wrap_ctrl_dummy_reg(data)                                (0x00002000&((data)<<13))
#define  EMMC_WRAP_emmc_wrap_ctrl_cclk_in_sample_ext_en(data)                    (0x00001000&((data)<<12))
#define  EMMC_WRAP_emmc_wrap_ctrl_eco_option0_dis(data)                          (0x00000800&((data)<<11))
#define  EMMC_WRAP_emmc_wrap_ctrl_m_hbigendian(data)                             (0x00000400&((data)<<10))
#define  EMMC_WRAP_emmc_wrap_ctrl_s_hbigendian(data)                             (0x00000200&((data)<<9))
#define  EMMC_WRAP_emmc_wrap_ctrl_cclk_out_src_sel(data)                         (0x00000100&((data)<<8))
#define  EMMC_WRAP_emmc_wrap_ctrl_wrap_version(data)                             (0x00000080&((data)<<7))
#define  EMMC_WRAP_emmc_wrap_ctrl_debug_mux(data)                                (0x0000007E&((data)<<1))
#define  EMMC_WRAP_emmc_wrap_ctrl_debug_ctrl(data)                               (0x00000001&(data))
#define  EMMC_WRAP_emmc_wrap_ctrl_get_cp_blk_len(data)                           ((0x7FFF0000&(data))>>16)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_cp_mode_en(data)                           ((0x00008000&(data))>>15)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_dummy_reg(data)                            ((0x00002000&(data))>>13)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_cclk_in_sample_ext_en(data)                ((0x00001000&(data))>>12)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_eco_option0_dis(data)                      ((0x00000800&(data))>>11)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_m_hbigendian(data)                         ((0x00000400&(data))>>10)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_s_hbigendian(data)                         ((0x00000200&(data))>>9)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_cclk_out_src_sel(data)                     ((0x00000100&(data))>>8)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_wrap_version(data)                         ((0x00000080&(data))>>7)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_debug_mux(data)                            ((0x0000007E&(data))>>1)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_debug_ctrl(data)                           (0x00000001&(data))

#define  EMMC_WRAP_emmc_wrap_status0                                             0x18010834
#define  EMMC_WRAP_emmc_wrap_status0_reg_addr                                    "0xB8010834"
#define  EMMC_WRAP_emmc_wrap_status0_reg                                         0xB8010834
#define  EMMC_WRAP_emmc_wrap_status0_inst_addr                                   "0x0009"
#define  set_EMMC_WRAP_emmc_wrap_status0_reg(data)                               (*((volatile unsigned int*)EMMC_WRAP_emmc_wrap_status0_reg)=data)
#define  get_EMMC_WRAP_emmc_wrap_status0_reg                                     (*((volatile unsigned int*)EMMC_WRAP_emmc_wrap_status0_reg))
#define  EMMC_WRAP_emmc_wrap_status0_real_dummy0_shift                           (19)
#define  EMMC_WRAP_emmc_wrap_status0_eco_option0_shift                           (18)
#define  EMMC_WRAP_emmc_wrap_status0_use_synopsys_shift                          (17)
#define  EMMC_WRAP_emmc_wrap_status0_hs400_use_drv_shift                         (16)
#define  EMMC_WRAP_emmc_wrap_status0_rbus_err_shift                              (2)
#define  EMMC_WRAP_emmc_wrap_status0_dbus_dma_busy_shift                         (1)
#define  EMMC_WRAP_emmc_wrap_status0_dbus_write_flag_shift                       (0)
#define  EMMC_WRAP_emmc_wrap_status0_real_dummy0_mask                            (0xFFF80000)
#define  EMMC_WRAP_emmc_wrap_status0_eco_option0_mask                            (0x00040000)
#define  EMMC_WRAP_emmc_wrap_status0_use_synopsys_mask                           (0x00020000)
#define  EMMC_WRAP_emmc_wrap_status0_hs400_use_drv_mask                          (0x00010000)
#define  EMMC_WRAP_emmc_wrap_status0_rbus_err_mask                               (0x00000004)
#define  EMMC_WRAP_emmc_wrap_status0_dbus_dma_busy_mask                          (0x00000002)
#define  EMMC_WRAP_emmc_wrap_status0_dbus_write_flag_mask                        (0x00000001)
#define  EMMC_WRAP_emmc_wrap_status0_real_dummy0(data)                           (0xFFF80000&((data)<<19))
#define  EMMC_WRAP_emmc_wrap_status0_eco_option0(data)                           (0x00040000&((data)<<18))
#define  EMMC_WRAP_emmc_wrap_status0_use_synopsys(data)                          (0x00020000&((data)<<17))
#define  EMMC_WRAP_emmc_wrap_status0_hs400_use_drv(data)                         (0x00010000&((data)<<16))
#define  EMMC_WRAP_emmc_wrap_status0_rbus_err(data)                              (0x00000004&((data)<<2))
#define  EMMC_WRAP_emmc_wrap_status0_dbus_dma_busy(data)                         (0x00000002&((data)<<1))
#define  EMMC_WRAP_emmc_wrap_status0_dbus_write_flag(data)                       (0x00000001&(data))
#define  EMMC_WRAP_emmc_wrap_status0_get_real_dummy0(data)                       ((0xFFF80000&(data))>>19)
#define  EMMC_WRAP_emmc_wrap_status0_get_eco_option0(data)                       ((0x00040000&(data))>>18)
#define  EMMC_WRAP_emmc_wrap_status0_get_use_synopsys(data)                      ((0x00020000&(data))>>17)
#define  EMMC_WRAP_emmc_wrap_status0_get_hs400_use_drv(data)                     ((0x00010000&(data))>>16)
#define  EMMC_WRAP_emmc_wrap_status0_get_rbus_err(data)                          ((0x00000004&(data))>>2)
#define  EMMC_WRAP_emmc_wrap_status0_get_dbus_dma_busy(data)                     ((0x00000002&(data))>>1)
#define  EMMC_WRAP_emmc_wrap_status0_get_dbus_write_flag(data)                   (0x00000001&(data))

#define  EMMC_WRAP_emmc_wrap_status1                                             0x18010838
#define  EMMC_WRAP_emmc_wrap_status1_reg_addr                                    "0xB8010838"
#define  EMMC_WRAP_emmc_wrap_status1_reg                                         0xB8010838
#define  EMMC_WRAP_emmc_wrap_status1_inst_addr                                   "0x000A"
#define  set_EMMC_WRAP_emmc_wrap_status1_reg(data)                               (*((volatile unsigned int*)EMMC_WRAP_emmc_wrap_status1_reg)=data)
#define  get_EMMC_WRAP_emmc_wrap_status1_reg                                     (*((volatile unsigned int*)EMMC_WRAP_emmc_wrap_status1_reg))
#define  EMMC_WRAP_emmc_wrap_status1_ictrl_state_shift                           (16)
#define  EMMC_WRAP_emmc_wrap_status1_top_sm_shift                                (0)
#define  EMMC_WRAP_emmc_wrap_status1_ictrl_state_mask                            (0x00070000)
#define  EMMC_WRAP_emmc_wrap_status1_top_sm_mask                                 (0x00007FFF)
#define  EMMC_WRAP_emmc_wrap_status1_ictrl_state(data)                           (0x00070000&((data)<<16))
#define  EMMC_WRAP_emmc_wrap_status1_top_sm(data)                                (0x00007FFF&(data))
#define  EMMC_WRAP_emmc_wrap_status1_get_ictrl_state(data)                       ((0x00070000&(data))>>16)
#define  EMMC_WRAP_emmc_wrap_status1_get_top_sm(data)                            (0x00007FFF&(data))

#define  EMMC_WRAP_emmc_ip_bist                                                  0x18010840
#define  EMMC_WRAP_emmc_ip_bist_reg_addr                                         "0xB8010840"
#define  EMMC_WRAP_emmc_ip_bist_reg                                              0xB8010840
#define  EMMC_WRAP_emmc_ip_bist_inst_addr                                        "0x000B"
#define  set_EMMC_WRAP_emmc_ip_bist_reg(data)                                    (*((volatile unsigned int*)EMMC_WRAP_emmc_ip_bist_reg)=data)
#define  get_EMMC_WRAP_emmc_ip_bist_reg                                          (*((volatile unsigned int*)EMMC_WRAP_emmc_ip_bist_reg))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_ls_1_shift                               (23)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_rm_1_shift                               (19)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_rme_1_shift                              (18)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_ls_0_shift                               (17)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_rm_0_shift                               (13)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_rme_0_shift                              (12)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_bist_fail_1_shift                    (9)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_bist_fail_0_shift                    (8)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_bist_done_shift                      (7)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_pause_shift                          (6)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_resume_shift                         (5)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_bist_mode_shift                      (4)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_bist_fail_1_shift                        (3)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_bist_fail_0_shift                        (2)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_bist_done_shift                          (1)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_bist_mode_shift                          (0)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_ls_1_mask                                (0x00800000)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_rm_1_mask                                (0x00780000)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_rme_1_mask                               (0x00040000)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_ls_0_mask                                (0x00020000)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_rm_0_mask                                (0x0001E000)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_rme_0_mask                               (0x00001000)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_bist_fail_1_mask                     (0x00000200)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_bist_fail_0_mask                     (0x00000100)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_bist_done_mask                       (0x00000080)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_pause_mask                           (0x00000040)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_resume_mask                          (0x00000020)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_bist_mode_mask                       (0x00000010)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_bist_fail_1_mask                         (0x00000008)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_bist_fail_0_mask                         (0x00000004)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_bist_done_mask                           (0x00000002)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_bist_mode_mask                           (0x00000001)
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_ls_1(data)                               (0x00800000&((data)<<23))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_rm_1(data)                               (0x00780000&((data)<<19))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_rme_1(data)                              (0x00040000&((data)<<18))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_ls_0(data)                               (0x00020000&((data)<<17))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_rm_0(data)                               (0x0001E000&((data)<<13))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_rme_0(data)                              (0x00001000&((data)<<12))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_bist_fail_1(data)                    (0x00000200&((data)<<9))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_bist_fail_0(data)                    (0x00000100&((data)<<8))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_bist_done(data)                      (0x00000080&((data)<<7))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_pause(data)                          (0x00000040&((data)<<6))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_resume(data)                         (0x00000020&((data)<<5))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_drf_bist_mode(data)                      (0x00000010&((data)<<4))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_bist_fail_1(data)                        (0x00000008&((data)<<3))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_bist_fail_0(data)                        (0x00000004&((data)<<2))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_bist_done(data)                          (0x00000002&((data)<<1))
#define  EMMC_WRAP_emmc_ip_bist_emmc_ip_bist_mode(data)                          (0x00000001&(data))
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_ls_1(data)                           ((0x00800000&(data))>>23)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_rm_1(data)                           ((0x00780000&(data))>>19)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_rme_1(data)                          ((0x00040000&(data))>>18)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_ls_0(data)                           ((0x00020000&(data))>>17)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_rm_0(data)                           ((0x0001E000&(data))>>13)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_rme_0(data)                          ((0x00001000&(data))>>12)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_drf_bist_fail_1(data)                ((0x00000200&(data))>>9)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_drf_bist_fail_0(data)                ((0x00000100&(data))>>8)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_drf_bist_done(data)                  ((0x00000080&(data))>>7)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_drf_pause(data)                      ((0x00000040&(data))>>6)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_drf_resume(data)                     ((0x00000020&(data))>>5)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_drf_bist_mode(data)                  ((0x00000010&(data))>>4)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_bist_fail_1(data)                    ((0x00000008&(data))>>3)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_bist_fail_0(data)                    ((0x00000004&(data))>>2)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_bist_done(data)                      ((0x00000002&(data))>>1)
#define  EMMC_WRAP_emmc_ip_bist_get_emmc_ip_bist_mode(data)                      (0x00000001&(data))

#define  EMMC_WRAP_emmc_wrap_bist                                                0x18010844
#define  EMMC_WRAP_emmc_wrap_bist_reg_addr                                       "0xB8010844"
#define  EMMC_WRAP_emmc_wrap_bist_reg                                            0xB8010844
#define  EMMC_WRAP_emmc_wrap_bist_inst_addr                                      "0x000C"
#define  set_EMMC_WRAP_emmc_wrap_bist_reg(data)                                  (*((volatile unsigned int*)EMMC_WRAP_emmc_wrap_bist_reg)=data)
#define  get_EMMC_WRAP_emmc_wrap_bist_reg                                        (*((volatile unsigned int*)EMMC_WRAP_emmc_wrap_bist_reg))
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_ls_shift                             (17)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_rm_shift                             (13)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_rme_shift                            (12)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_bist_fail_shift                  (8)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_bist_done_shift                  (7)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_pause_shift                      (6)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_resume_shift                     (5)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_bist_mode_shift                  (4)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_bist_fail_shift                      (2)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_bist_done_shift                      (1)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_bist_mode_shift                      (0)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_ls_mask                              (0x00020000)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_rm_mask                              (0x0001E000)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_rme_mask                             (0x00001000)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_bist_fail_mask                   (0x00000100)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_bist_done_mask                   (0x00000080)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_pause_mask                       (0x00000040)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_resume_mask                      (0x00000020)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_bist_mode_mask                   (0x00000010)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_bist_fail_mask                       (0x00000004)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_bist_done_mask                       (0x00000002)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_bist_mode_mask                       (0x00000001)
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_ls(data)                             (0x00020000&((data)<<17))
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_rm(data)                             (0x0001E000&((data)<<13))
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_rme(data)                            (0x00001000&((data)<<12))
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_bist_fail(data)                  (0x00000100&((data)<<8))
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_bist_done(data)                  (0x00000080&((data)<<7))
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_pause(data)                      (0x00000040&((data)<<6))
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_resume(data)                     (0x00000020&((data)<<5))
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_drf_bist_mode(data)                  (0x00000010&((data)<<4))
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_bist_fail(data)                      (0x00000004&((data)<<2))
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_bist_done(data)                      (0x00000002&((data)<<1))
#define  EMMC_WRAP_emmc_wrap_bist_emmc_wrap_bist_mode(data)                      (0x00000001&(data))
#define  EMMC_WRAP_emmc_wrap_bist_get_emmc_wrap_ls(data)                         ((0x00020000&(data))>>17)
#define  EMMC_WRAP_emmc_wrap_bist_get_emmc_wrap_rm(data)                         ((0x0001E000&(data))>>13)
#define  EMMC_WRAP_emmc_wrap_bist_get_emmc_wrap_rme(data)                        ((0x00001000&(data))>>12)
#define  EMMC_WRAP_emmc_wrap_bist_get_emmc_wrap_drf_bist_fail(data)              ((0x00000100&(data))>>8)
#define  EMMC_WRAP_emmc_wrap_bist_get_emmc_wrap_drf_bist_done(data)              ((0x00000080&(data))>>7)
#define  EMMC_WRAP_emmc_wrap_bist_get_emmc_wrap_drf_pause(data)                  ((0x00000040&(data))>>6)
#define  EMMC_WRAP_emmc_wrap_bist_get_emmc_wrap_drf_resume(data)                 ((0x00000020&(data))>>5)
#define  EMMC_WRAP_emmc_wrap_bist_get_emmc_wrap_drf_bist_mode(data)              ((0x00000010&(data))>>4)
#define  EMMC_WRAP_emmc_wrap_bist_get_emmc_wrap_bist_fail(data)                  ((0x00000004&(data))>>2)
#define  EMMC_WRAP_emmc_wrap_bist_get_emmc_wrap_bist_done(data)                  ((0x00000002&(data))>>1)
#define  EMMC_WRAP_emmc_wrap_bist_get_emmc_wrap_bist_mode(data)                  (0x00000001&(data))

#define  EMMC_WRAP_clk_phase_sel                                                 0x18010848
#define  EMMC_WRAP_clk_phase_sel_reg_addr                                        "0xB8010848"
#define  EMMC_WRAP_clk_phase_sel_reg                                             0xB8010848
#define  EMMC_WRAP_clk_phase_sel_inst_addr                                       "0x000D"
#define  set_EMMC_WRAP_clk_phase_sel_reg(data)                                   (*((volatile unsigned int*)EMMC_WRAP_clk_phase_sel_reg)=data)
#define  get_EMMC_WRAP_clk_phase_sel_reg                                         (*((volatile unsigned int*)EMMC_WRAP_clk_phase_sel_reg))
#define  EMMC_WRAP_clk_phase_sel_cclk_out_sel_shift                              (12)
#define  EMMC_WRAP_clk_phase_sel_cclk_in_sample_sel_shift                        (6)
#define  EMMC_WRAP_clk_phase_sel_cclk_in_drv_sel_shift                           (0)
#define  EMMC_WRAP_clk_phase_sel_cclk_out_sel_mask                               (0x0003F000)
#define  EMMC_WRAP_clk_phase_sel_cclk_in_sample_sel_mask                         (0x00000FC0)
#define  EMMC_WRAP_clk_phase_sel_cclk_in_drv_sel_mask                            (0x0000003F)
#define  EMMC_WRAP_clk_phase_sel_cclk_out_sel(data)                              (0x0003F000&((data)<<12))
#define  EMMC_WRAP_clk_phase_sel_cclk_in_sample_sel(data)                        (0x00000FC0&((data)<<6))
#define  EMMC_WRAP_clk_phase_sel_cclk_in_drv_sel(data)                           (0x0000003F&(data))
#define  EMMC_WRAP_clk_phase_sel_get_cclk_out_sel(data)                          ((0x0003F000&(data))>>12)
#define  EMMC_WRAP_clk_phase_sel_get_cclk_in_sample_sel(data)                    ((0x00000FC0&(data))>>6)
#define  EMMC_WRAP_clk_phase_sel_get_cclk_in_drv_sel(data)                       (0x0000003F&(data))

#define  EMMC_WRAP_ds_tune_ctrl                                                  0x18010850
#define  EMMC_WRAP_ds_tune_ctrl_reg_addr                                         "0xB8010850"
#define  EMMC_WRAP_ds_tune_ctrl_reg                                              0xB8010850
#define  EMMC_WRAP_ds_tune_ctrl_inst_addr                                        "0x000E"
#define  set_EMMC_WRAP_ds_tune_ctrl_reg(data)                                    (*((volatile unsigned int*)EMMC_WRAP_ds_tune_ctrl_reg)=data)
#define  get_EMMC_WRAP_ds_tune_ctrl_reg                                          (*((volatile unsigned int*)EMMC_WRAP_ds_tune_ctrl_reg))
#define  EMMC_WRAP_ds_tune_ctrl_rd_dbg_mod_shift                                 (28)
#define  EMMC_WRAP_ds_tune_ctrl_rtk_hs200_pos_shift                              (22)
#define  EMMC_WRAP_ds_tune_ctrl_rtk_hs200_shift                                  (21)
#define  EMMC_WRAP_ds_tune_ctrl_bypass_ds_tune_shift                             (20)
#define  EMMC_WRAP_ds_tune_ctrl_bypass_ds_ph_sel_shift                           (15)
#define  EMMC_WRAP_ds_tune_ctrl_rw_cnt_reset_shift                               (14)
#define  EMMC_WRAP_ds_tune_ctrl_wr_adr_p_0_tran_sel_shift                        (13)
#define  EMMC_WRAP_ds_tune_ctrl_rw_cnt_ref_align_en_shift                        (12)
#define  EMMC_WRAP_ds_tune_ctrl_fw_set_pulse_shift                               (9)
#define  EMMC_WRAP_ds_tune_ctrl_dqsf_dlyn_shift                                  (7)
#define  EMMC_WRAP_ds_tune_ctrl_pos_trig_sel_shift                               (5)
#define  EMMC_WRAP_ds_tune_ctrl_pre_trig_sel_shift                               (3)
#define  EMMC_WRAP_ds_tune_ctrl_sync_cal_dlyn_shift                              (2)
#define  EMMC_WRAP_ds_tune_ctrl_auto_cal_shift                                   (1)
#define  EMMC_WRAP_ds_tune_ctrl_dqs_del_offset_en_shift                          (0)
#define  EMMC_WRAP_ds_tune_ctrl_rd_dbg_mod_mask                                  (0xF0000000)
#define  EMMC_WRAP_ds_tune_ctrl_rtk_hs200_pos_mask                               (0x00400000)
#define  EMMC_WRAP_ds_tune_ctrl_rtk_hs200_mask                                   (0x00200000)
#define  EMMC_WRAP_ds_tune_ctrl_bypass_ds_tune_mask                              (0x00100000)
#define  EMMC_WRAP_ds_tune_ctrl_bypass_ds_ph_sel_mask                            (0x000F8000)
#define  EMMC_WRAP_ds_tune_ctrl_rw_cnt_reset_mask                                (0x00004000)
#define  EMMC_WRAP_ds_tune_ctrl_wr_adr_p_0_tran_sel_mask                         (0x00002000)
#define  EMMC_WRAP_ds_tune_ctrl_rw_cnt_ref_align_en_mask                         (0x00001000)
#define  EMMC_WRAP_ds_tune_ctrl_fw_set_pulse_mask                                (0x00000200)
#define  EMMC_WRAP_ds_tune_ctrl_dqsf_dlyn_mask                                   (0x00000180)
#define  EMMC_WRAP_ds_tune_ctrl_pos_trig_sel_mask                                (0x00000060)
#define  EMMC_WRAP_ds_tune_ctrl_pre_trig_sel_mask                                (0x00000018)
#define  EMMC_WRAP_ds_tune_ctrl_sync_cal_dlyn_mask                               (0x00000004)
#define  EMMC_WRAP_ds_tune_ctrl_auto_cal_mask                                    (0x00000002)
#define  EMMC_WRAP_ds_tune_ctrl_dqs_del_offset_en_mask                           (0x00000001)
#define  EMMC_WRAP_ds_tune_ctrl_rd_dbg_mod(data)                                 (0xF0000000&((data)<<28))
#define  EMMC_WRAP_ds_tune_ctrl_rtk_hs200_pos(data)                              (0x00400000&((data)<<22))
#define  EMMC_WRAP_ds_tune_ctrl_rtk_hs200(data)                                  (0x00200000&((data)<<21))
#define  EMMC_WRAP_ds_tune_ctrl_bypass_ds_tune(data)                             (0x00100000&((data)<<20))
#define  EMMC_WRAP_ds_tune_ctrl_bypass_ds_ph_sel(data)                           (0x000F8000&((data)<<15))
#define  EMMC_WRAP_ds_tune_ctrl_rw_cnt_reset(data)                               (0x00004000&((data)<<14))
#define  EMMC_WRAP_ds_tune_ctrl_wr_adr_p_0_tran_sel(data)                        (0x00002000&((data)<<13))
#define  EMMC_WRAP_ds_tune_ctrl_rw_cnt_ref_align_en(data)                        (0x00001000&((data)<<12))
#define  EMMC_WRAP_ds_tune_ctrl_fw_set_pulse(data)                               (0x00000200&((data)<<9))
#define  EMMC_WRAP_ds_tune_ctrl_dqsf_dlyn(data)                                  (0x00000180&((data)<<7))
#define  EMMC_WRAP_ds_tune_ctrl_pos_trig_sel(data)                               (0x00000060&((data)<<5))
#define  EMMC_WRAP_ds_tune_ctrl_pre_trig_sel(data)                               (0x00000018&((data)<<3))
#define  EMMC_WRAP_ds_tune_ctrl_sync_cal_dlyn(data)                              (0x00000004&((data)<<2))
#define  EMMC_WRAP_ds_tune_ctrl_auto_cal(data)                                   (0x00000002&((data)<<1))
#define  EMMC_WRAP_ds_tune_ctrl_dqs_del_offset_en(data)                          (0x00000001&(data))
#define  EMMC_WRAP_ds_tune_ctrl_get_rd_dbg_mod(data)                             ((0xF0000000&(data))>>28)
#define  EMMC_WRAP_ds_tune_ctrl_get_rtk_hs200_pos(data)                          ((0x00400000&(data))>>22)
#define  EMMC_WRAP_ds_tune_ctrl_get_rtk_hs200(data)                              ((0x00200000&(data))>>21)
#define  EMMC_WRAP_ds_tune_ctrl_get_bypass_ds_tune(data)                         ((0x00100000&(data))>>20)
#define  EMMC_WRAP_ds_tune_ctrl_get_bypass_ds_ph_sel(data)                       ((0x000F8000&(data))>>15)
#define  EMMC_WRAP_ds_tune_ctrl_get_rw_cnt_reset(data)                           ((0x00004000&(data))>>14)
#define  EMMC_WRAP_ds_tune_ctrl_get_wr_adr_p_0_tran_sel(data)                    ((0x00002000&(data))>>13)
#define  EMMC_WRAP_ds_tune_ctrl_get_rw_cnt_ref_align_en(data)                    ((0x00001000&(data))>>12)
#define  EMMC_WRAP_ds_tune_ctrl_get_fw_set_pulse(data)                           ((0x00000200&(data))>>9)
#define  EMMC_WRAP_ds_tune_ctrl_get_dqsf_dlyn(data)                              ((0x00000180&(data))>>7)
#define  EMMC_WRAP_ds_tune_ctrl_get_pos_trig_sel(data)                           ((0x00000060&(data))>>5)
#define  EMMC_WRAP_ds_tune_ctrl_get_pre_trig_sel(data)                           ((0x00000018&(data))>>3)
#define  EMMC_WRAP_ds_tune_ctrl_get_sync_cal_dlyn(data)                          ((0x00000004&(data))>>2)
#define  EMMC_WRAP_ds_tune_ctrl_get_auto_cal(data)                               ((0x00000002&(data))>>1)
#define  EMMC_WRAP_ds_tune_ctrl_get_dqs_del_offset_en(data)                      (0x00000001&(data))

#define  EMMC_WRAP_ds_tune_cal_dq0_1                                             0x18010854
#define  EMMC_WRAP_ds_tune_cal_dq0_1_reg_addr                                    "0xB8010854"
#define  EMMC_WRAP_ds_tune_cal_dq0_1_reg                                         0xB8010854
#define  EMMC_WRAP_ds_tune_cal_dq0_1_inst_addr                                   "0x000F"
#define  set_EMMC_WRAP_ds_tune_cal_dq0_1_reg(data)                               (*((volatile unsigned int*)EMMC_WRAP_ds_tune_cal_dq0_1_reg)=data)
#define  get_EMMC_WRAP_ds_tune_cal_dq0_1_reg                                     (*((volatile unsigned int*)EMMC_WRAP_ds_tune_cal_dq0_1_reg))
#define  EMMC_WRAP_ds_tune_cal_dq0_1_cal_dq1_neg_dlyn_shift                      (24)
#define  EMMC_WRAP_ds_tune_cal_dq0_1_cal_dq1_pos_dlyn_shift                      (16)
#define  EMMC_WRAP_ds_tune_cal_dq0_1_cal_dq0_neg_dlyn_shift                      (8)
#define  EMMC_WRAP_ds_tune_cal_dq0_1_cal_dq0_pos_dlyn_shift                      (0)
#define  EMMC_WRAP_ds_tune_cal_dq0_1_cal_dq1_neg_dlyn_mask                       (0x3F000000)
#define  EMMC_WRAP_ds_tune_cal_dq0_1_cal_dq1_pos_dlyn_mask                       (0x003F0000)
#define  EMMC_WRAP_ds_tune_cal_dq0_1_cal_dq0_neg_dlyn_mask                       (0x00003F00)
#define  EMMC_WRAP_ds_tune_cal_dq0_1_cal_dq0_pos_dlyn_mask                       (0x0000003F)
#define  EMMC_WRAP_ds_tune_cal_dq0_1_cal_dq1_neg_dlyn(data)                      (0x3F000000&((data)<<24))
#define  EMMC_WRAP_ds_tune_cal_dq0_1_cal_dq1_pos_dlyn(data)                      (0x003F0000&((data)<<16))
#define  EMMC_WRAP_ds_tune_cal_dq0_1_cal_dq0_neg_dlyn(data)                      (0x00003F00&((data)<<8))
#define  EMMC_WRAP_ds_tune_cal_dq0_1_cal_dq0_pos_dlyn(data)                      (0x0000003F&(data))
#define  EMMC_WRAP_ds_tune_cal_dq0_1_get_cal_dq1_neg_dlyn(data)                  ((0x3F000000&(data))>>24)
#define  EMMC_WRAP_ds_tune_cal_dq0_1_get_cal_dq1_pos_dlyn(data)                  ((0x003F0000&(data))>>16)
#define  EMMC_WRAP_ds_tune_cal_dq0_1_get_cal_dq0_neg_dlyn(data)                  ((0x00003F00&(data))>>8)
#define  EMMC_WRAP_ds_tune_cal_dq0_1_get_cal_dq0_pos_dlyn(data)                  (0x0000003F&(data))

#define  EMMC_WRAP_ds_tune_cal_dq2_3                                             0x18010858
#define  EMMC_WRAP_ds_tune_cal_dq2_3_reg_addr                                    "0xB8010858"
#define  EMMC_WRAP_ds_tune_cal_dq2_3_reg                                         0xB8010858
#define  EMMC_WRAP_ds_tune_cal_dq2_3_inst_addr                                   "0x0010"
#define  set_EMMC_WRAP_ds_tune_cal_dq2_3_reg(data)                               (*((volatile unsigned int*)EMMC_WRAP_ds_tune_cal_dq2_3_reg)=data)
#define  get_EMMC_WRAP_ds_tune_cal_dq2_3_reg                                     (*((volatile unsigned int*)EMMC_WRAP_ds_tune_cal_dq2_3_reg))
#define  EMMC_WRAP_ds_tune_cal_dq2_3_cal_dq3_neg_dlyn_shift                      (24)
#define  EMMC_WRAP_ds_tune_cal_dq2_3_cal_dq3_pos_dlyn_shift                      (16)
#define  EMMC_WRAP_ds_tune_cal_dq2_3_cal_dq2_neg_dlyn_shift                      (8)
#define  EMMC_WRAP_ds_tune_cal_dq2_3_cal_dq2_pos_dlyn_shift                      (0)
#define  EMMC_WRAP_ds_tune_cal_dq2_3_cal_dq3_neg_dlyn_mask                       (0x3F000000)
#define  EMMC_WRAP_ds_tune_cal_dq2_3_cal_dq3_pos_dlyn_mask                       (0x003F0000)
#define  EMMC_WRAP_ds_tune_cal_dq2_3_cal_dq2_neg_dlyn_mask                       (0x00003F00)
#define  EMMC_WRAP_ds_tune_cal_dq2_3_cal_dq2_pos_dlyn_mask                       (0x0000003F)
#define  EMMC_WRAP_ds_tune_cal_dq2_3_cal_dq3_neg_dlyn(data)                      (0x3F000000&((data)<<24))
#define  EMMC_WRAP_ds_tune_cal_dq2_3_cal_dq3_pos_dlyn(data)                      (0x003F0000&((data)<<16))
#define  EMMC_WRAP_ds_tune_cal_dq2_3_cal_dq2_neg_dlyn(data)                      (0x00003F00&((data)<<8))
#define  EMMC_WRAP_ds_tune_cal_dq2_3_cal_dq2_pos_dlyn(data)                      (0x0000003F&(data))
#define  EMMC_WRAP_ds_tune_cal_dq2_3_get_cal_dq3_neg_dlyn(data)                  ((0x3F000000&(data))>>24)
#define  EMMC_WRAP_ds_tune_cal_dq2_3_get_cal_dq3_pos_dlyn(data)                  ((0x003F0000&(data))>>16)
#define  EMMC_WRAP_ds_tune_cal_dq2_3_get_cal_dq2_neg_dlyn(data)                  ((0x00003F00&(data))>>8)
#define  EMMC_WRAP_ds_tune_cal_dq2_3_get_cal_dq2_pos_dlyn(data)                  (0x0000003F&(data))

#define  EMMC_WRAP_ds_tune_cal_dq4_5                                             0x1801085C
#define  EMMC_WRAP_ds_tune_cal_dq4_5_reg_addr                                    "0xB801085C"
#define  EMMC_WRAP_ds_tune_cal_dq4_5_reg                                         0xB801085C
#define  EMMC_WRAP_ds_tune_cal_dq4_5_inst_addr                                   "0x0011"
#define  set_EMMC_WRAP_ds_tune_cal_dq4_5_reg(data)                               (*((volatile unsigned int*)EMMC_WRAP_ds_tune_cal_dq4_5_reg)=data)
#define  get_EMMC_WRAP_ds_tune_cal_dq4_5_reg                                     (*((volatile unsigned int*)EMMC_WRAP_ds_tune_cal_dq4_5_reg))
#define  EMMC_WRAP_ds_tune_cal_dq4_5_cal_dq5_neg_dlyn_shift                      (24)
#define  EMMC_WRAP_ds_tune_cal_dq4_5_cal_dq5_pos_dlyn_shift                      (16)
#define  EMMC_WRAP_ds_tune_cal_dq4_5_cal_dq4_neg_dlyn_shift                      (8)
#define  EMMC_WRAP_ds_tune_cal_dq4_5_cal_dq4_pos_dlyn_shift                      (0)
#define  EMMC_WRAP_ds_tune_cal_dq4_5_cal_dq5_neg_dlyn_mask                       (0x3F000000)
#define  EMMC_WRAP_ds_tune_cal_dq4_5_cal_dq5_pos_dlyn_mask                       (0x003F0000)
#define  EMMC_WRAP_ds_tune_cal_dq4_5_cal_dq4_neg_dlyn_mask                       (0x00003F00)
#define  EMMC_WRAP_ds_tune_cal_dq4_5_cal_dq4_pos_dlyn_mask                       (0x0000003F)
#define  EMMC_WRAP_ds_tune_cal_dq4_5_cal_dq5_neg_dlyn(data)                      (0x3F000000&((data)<<24))
#define  EMMC_WRAP_ds_tune_cal_dq4_5_cal_dq5_pos_dlyn(data)                      (0x003F0000&((data)<<16))
#define  EMMC_WRAP_ds_tune_cal_dq4_5_cal_dq4_neg_dlyn(data)                      (0x00003F00&((data)<<8))
#define  EMMC_WRAP_ds_tune_cal_dq4_5_cal_dq4_pos_dlyn(data)                      (0x0000003F&(data))
#define  EMMC_WRAP_ds_tune_cal_dq4_5_get_cal_dq5_neg_dlyn(data)                  ((0x3F000000&(data))>>24)
#define  EMMC_WRAP_ds_tune_cal_dq4_5_get_cal_dq5_pos_dlyn(data)                  ((0x003F0000&(data))>>16)
#define  EMMC_WRAP_ds_tune_cal_dq4_5_get_cal_dq4_neg_dlyn(data)                  ((0x00003F00&(data))>>8)
#define  EMMC_WRAP_ds_tune_cal_dq4_5_get_cal_dq4_pos_dlyn(data)                  (0x0000003F&(data))

#define  EMMC_WRAP_ds_tune_cal_dq6_7                                             0x18010860
#define  EMMC_WRAP_ds_tune_cal_dq6_7_reg_addr                                    "0xB8010860"
#define  EMMC_WRAP_ds_tune_cal_dq6_7_reg                                         0xB8010860
#define  EMMC_WRAP_ds_tune_cal_dq6_7_inst_addr                                   "0x0012"
#define  set_EMMC_WRAP_ds_tune_cal_dq6_7_reg(data)                               (*((volatile unsigned int*)EMMC_WRAP_ds_tune_cal_dq6_7_reg)=data)
#define  get_EMMC_WRAP_ds_tune_cal_dq6_7_reg                                     (*((volatile unsigned int*)EMMC_WRAP_ds_tune_cal_dq6_7_reg))
#define  EMMC_WRAP_ds_tune_cal_dq6_7_cal_dq7_neg_dlyn_shift                      (24)
#define  EMMC_WRAP_ds_tune_cal_dq6_7_cal_dq7_pos_dlyn_shift                      (16)
#define  EMMC_WRAP_ds_tune_cal_dq6_7_cal_dq6_neg_dlyn_shift                      (8)
#define  EMMC_WRAP_ds_tune_cal_dq6_7_cal_dq6_pos_dlyn_shift                      (0)
#define  EMMC_WRAP_ds_tune_cal_dq6_7_cal_dq7_neg_dlyn_mask                       (0x3F000000)
#define  EMMC_WRAP_ds_tune_cal_dq6_7_cal_dq7_pos_dlyn_mask                       (0x003F0000)
#define  EMMC_WRAP_ds_tune_cal_dq6_7_cal_dq6_neg_dlyn_mask                       (0x00003F00)
#define  EMMC_WRAP_ds_tune_cal_dq6_7_cal_dq6_pos_dlyn_mask                       (0x0000003F)
#define  EMMC_WRAP_ds_tune_cal_dq6_7_cal_dq7_neg_dlyn(data)                      (0x3F000000&((data)<<24))
#define  EMMC_WRAP_ds_tune_cal_dq6_7_cal_dq7_pos_dlyn(data)                      (0x003F0000&((data)<<16))
#define  EMMC_WRAP_ds_tune_cal_dq6_7_cal_dq6_neg_dlyn(data)                      (0x00003F00&((data)<<8))
#define  EMMC_WRAP_ds_tune_cal_dq6_7_cal_dq6_pos_dlyn(data)                      (0x0000003F&(data))
#define  EMMC_WRAP_ds_tune_cal_dq6_7_get_cal_dq7_neg_dlyn(data)                  ((0x3F000000&(data))>>24)
#define  EMMC_WRAP_ds_tune_cal_dq6_7_get_cal_dq7_pos_dlyn(data)                  ((0x003F0000&(data))>>16)
#define  EMMC_WRAP_ds_tune_cal_dq6_7_get_cal_dq6_neg_dlyn(data)                  ((0x00003F00&(data))>>8)
#define  EMMC_WRAP_ds_tune_cal_dq6_7_get_cal_dq6_pos_dlyn(data)                  (0x0000003F&(data))

#define  EMMC_WRAP_ds_tune_ph_sel_0_1                                            0x18010864
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_reg_addr                                   "0xB8010864"
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_reg                                        0xB8010864
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_inst_addr                                  "0x0013"
#define  set_EMMC_WRAP_ds_tune_ph_sel_0_1_reg(data)                              (*((volatile unsigned int*)EMMC_WRAP_ds_tune_ph_sel_0_1_reg)=data)
#define  get_EMMC_WRAP_ds_tune_ph_sel_0_1_reg                                    (*((volatile unsigned int*)EMMC_WRAP_ds_tune_ph_sel_0_1_reg))
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_ph_sel_dq_neg_1_shift                      (24)
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_ph_sel_dq_pos_1_shift                      (16)
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_ph_sel_dq_neg_0_shift                      (8)
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_ph_sel_dq_pos_0_shift                      (0)
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_ph_sel_dq_neg_1_mask                       (0x3F000000)
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_ph_sel_dq_pos_1_mask                       (0x003F0000)
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_ph_sel_dq_neg_0_mask                       (0x00003F00)
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_ph_sel_dq_pos_0_mask                       (0x0000003F)
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_ph_sel_dq_neg_1(data)                      (0x3F000000&((data)<<24))
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_ph_sel_dq_pos_1(data)                      (0x003F0000&((data)<<16))
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_ph_sel_dq_neg_0(data)                      (0x00003F00&((data)<<8))
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_ph_sel_dq_pos_0(data)                      (0x0000003F&(data))
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_get_ph_sel_dq_neg_1(data)                  ((0x3F000000&(data))>>24)
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_get_ph_sel_dq_pos_1(data)                  ((0x003F0000&(data))>>16)
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_get_ph_sel_dq_neg_0(data)                  ((0x00003F00&(data))>>8)
#define  EMMC_WRAP_ds_tune_ph_sel_0_1_get_ph_sel_dq_pos_0(data)                  (0x0000003F&(data))

#define  EMMC_WRAP_ds_tune_ph_sel_2_3                                            0x18010868
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_reg_addr                                   "0xB8010868"
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_reg                                        0xB8010868
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_inst_addr                                  "0x0014"
#define  set_EMMC_WRAP_ds_tune_ph_sel_2_3_reg(data)                              (*((volatile unsigned int*)EMMC_WRAP_ds_tune_ph_sel_2_3_reg)=data)
#define  get_EMMC_WRAP_ds_tune_ph_sel_2_3_reg                                    (*((volatile unsigned int*)EMMC_WRAP_ds_tune_ph_sel_2_3_reg))
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_ph_sel_dq_neg_3_shift                      (24)
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_ph_sel_dq_pos_3_shift                      (16)
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_ph_sel_dq_neg_2_shift                      (8)
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_ph_sel_dq_pos_2_shift                      (0)
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_ph_sel_dq_neg_3_mask                       (0x3F000000)
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_ph_sel_dq_pos_3_mask                       (0x003F0000)
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_ph_sel_dq_neg_2_mask                       (0x00003F00)
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_ph_sel_dq_pos_2_mask                       (0x0000003F)
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_ph_sel_dq_neg_3(data)                      (0x3F000000&((data)<<24))
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_ph_sel_dq_pos_3(data)                      (0x003F0000&((data)<<16))
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_ph_sel_dq_neg_2(data)                      (0x00003F00&((data)<<8))
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_ph_sel_dq_pos_2(data)                      (0x0000003F&(data))
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_get_ph_sel_dq_neg_3(data)                  ((0x3F000000&(data))>>24)
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_get_ph_sel_dq_pos_3(data)                  ((0x003F0000&(data))>>16)
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_get_ph_sel_dq_neg_2(data)                  ((0x00003F00&(data))>>8)
#define  EMMC_WRAP_ds_tune_ph_sel_2_3_get_ph_sel_dq_pos_2(data)                  (0x0000003F&(data))

#define  EMMC_WRAP_ds_tune_ph_sel_4_5                                            0x1801086C
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_reg_addr                                   "0xB801086C"
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_reg                                        0xB801086C
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_inst_addr                                  "0x0015"
#define  set_EMMC_WRAP_ds_tune_ph_sel_4_5_reg(data)                              (*((volatile unsigned int*)EMMC_WRAP_ds_tune_ph_sel_4_5_reg)=data)
#define  get_EMMC_WRAP_ds_tune_ph_sel_4_5_reg                                    (*((volatile unsigned int*)EMMC_WRAP_ds_tune_ph_sel_4_5_reg))
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_ph_sel_dq_neg_5_shift                      (24)
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_ph_sel_dq_pos_5_shift                      (16)
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_ph_sel_dq_neg_4_shift                      (8)
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_ph_sel_dq_pos_4_shift                      (0)
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_ph_sel_dq_neg_5_mask                       (0x3F000000)
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_ph_sel_dq_pos_5_mask                       (0x003F0000)
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_ph_sel_dq_neg_4_mask                       (0x00003F00)
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_ph_sel_dq_pos_4_mask                       (0x0000003F)
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_ph_sel_dq_neg_5(data)                      (0x3F000000&((data)<<24))
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_ph_sel_dq_pos_5(data)                      (0x003F0000&((data)<<16))
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_ph_sel_dq_neg_4(data)                      (0x00003F00&((data)<<8))
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_ph_sel_dq_pos_4(data)                      (0x0000003F&(data))
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_get_ph_sel_dq_neg_5(data)                  ((0x3F000000&(data))>>24)
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_get_ph_sel_dq_pos_5(data)                  ((0x003F0000&(data))>>16)
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_get_ph_sel_dq_neg_4(data)                  ((0x00003F00&(data))>>8)
#define  EMMC_WRAP_ds_tune_ph_sel_4_5_get_ph_sel_dq_pos_4(data)                  (0x0000003F&(data))

#define  EMMC_WRAP_ds_tune_ph_sel_6_7                                            0x18010870
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_reg_addr                                   "0xB8010870"
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_reg                                        0xB8010870
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_inst_addr                                  "0x0016"
#define  set_EMMC_WRAP_ds_tune_ph_sel_6_7_reg(data)                              (*((volatile unsigned int*)EMMC_WRAP_ds_tune_ph_sel_6_7_reg)=data)
#define  get_EMMC_WRAP_ds_tune_ph_sel_6_7_reg                                    (*((volatile unsigned int*)EMMC_WRAP_ds_tune_ph_sel_6_7_reg))
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_ph_sel_dq_neg_7_shift                      (24)
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_ph_sel_dq_pos_7_shift                      (16)
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_ph_sel_dq_neg_6_shift                      (8)
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_ph_sel_dq_pos_6_shift                      (0)
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_ph_sel_dq_neg_7_mask                       (0x3F000000)
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_ph_sel_dq_pos_7_mask                       (0x003F0000)
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_ph_sel_dq_neg_6_mask                       (0x00003F00)
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_ph_sel_dq_pos_6_mask                       (0x0000003F)
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_ph_sel_dq_neg_7(data)                      (0x3F000000&((data)<<24))
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_ph_sel_dq_pos_7(data)                      (0x003F0000&((data)<<16))
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_ph_sel_dq_neg_6(data)                      (0x00003F00&((data)<<8))
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_ph_sel_dq_pos_6(data)                      (0x0000003F&(data))
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_get_ph_sel_dq_neg_7(data)                  ((0x3F000000&(data))>>24)
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_get_ph_sel_dq_pos_7(data)                  ((0x003F0000&(data))>>16)
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_get_ph_sel_dq_neg_6(data)                  ((0x00003F00&(data))>>8)
#define  EMMC_WRAP_ds_tune_ph_sel_6_7_get_ph_sel_dq_pos_6(data)                  (0x0000003F&(data))

#define  EMMC_WRAP_ds_tune_rcv_1st                                               0x18010874
#define  EMMC_WRAP_ds_tune_rcv_1st_reg_addr                                      "0xB8010874"
#define  EMMC_WRAP_ds_tune_rcv_1st_reg                                           0xB8010874
#define  EMMC_WRAP_ds_tune_rcv_1st_inst_addr                                     "0x0017"
#define  set_EMMC_WRAP_ds_tune_rcv_1st_reg(data)                                 (*((volatile unsigned int*)EMMC_WRAP_ds_tune_rcv_1st_reg)=data)
#define  get_EMMC_WRAP_ds_tune_rcv_1st_reg                                       (*((volatile unsigned int*)EMMC_WRAP_ds_tune_rcv_1st_reg))
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_7_shift                     (28)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_6_shift                     (24)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_5_shift                     (20)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_4_shift                     (16)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_3_shift                     (12)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_2_shift                     (8)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_1_shift                     (4)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_0_shift                     (0)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_7_mask                      (0xF0000000)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_6_mask                      (0x0F000000)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_5_mask                      (0x00F00000)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_4_mask                      (0x000F0000)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_3_mask                      (0x0000F000)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_2_mask                      (0x00000F00)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_1_mask                      (0x000000F0)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_0_mask                      (0x0000000F)
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_7(data)                     (0xF0000000&((data)<<28))
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_6(data)                     (0x0F000000&((data)<<24))
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_5(data)                     (0x00F00000&((data)<<20))
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_4(data)                     (0x000F0000&((data)<<16))
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_3(data)                     (0x0000F000&((data)<<12))
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_2(data)                     (0x00000F00&((data)<<8))
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_1(data)                     (0x000000F0&((data)<<4))
#define  EMMC_WRAP_ds_tune_rcv_1st_rcv_1st_dq_ph_sel_0(data)                     (0x0000000F&(data))
#define  EMMC_WRAP_ds_tune_rcv_1st_get_rcv_1st_dq_ph_sel_7(data)                 ((0xF0000000&(data))>>28)
#define  EMMC_WRAP_ds_tune_rcv_1st_get_rcv_1st_dq_ph_sel_6(data)                 ((0x0F000000&(data))>>24)
#define  EMMC_WRAP_ds_tune_rcv_1st_get_rcv_1st_dq_ph_sel_5(data)                 ((0x00F00000&(data))>>20)
#define  EMMC_WRAP_ds_tune_rcv_1st_get_rcv_1st_dq_ph_sel_4(data)                 ((0x000F0000&(data))>>16)
#define  EMMC_WRAP_ds_tune_rcv_1st_get_rcv_1st_dq_ph_sel_3(data)                 ((0x0000F000&(data))>>12)
#define  EMMC_WRAP_ds_tune_rcv_1st_get_rcv_1st_dq_ph_sel_2(data)                 ((0x00000F00&(data))>>8)
#define  EMMC_WRAP_ds_tune_rcv_1st_get_rcv_1st_dq_ph_sel_1(data)                 ((0x000000F0&(data))>>4)
#define  EMMC_WRAP_ds_tune_rcv_1st_get_rcv_1st_dq_ph_sel_0(data)                 (0x0000000F&(data))

#define  EMMC_WRAP_emmc_cpmask_0                                                 0x18010880
#define  EMMC_WRAP_emmc_cpmask_0_reg_addr                                        "0xB8010880"
#define  EMMC_WRAP_emmc_cpmask_0_reg                                             0xB8010880
#define  EMMC_WRAP_emmc_cpmask_0_inst_addr                                       "0x0018"
#define  set_EMMC_WRAP_emmc_cpmask_0_reg(data)                                   (*((volatile unsigned int*)EMMC_WRAP_emmc_cpmask_0_reg)=data)
#define  get_EMMC_WRAP_emmc_cpmask_0_reg                                         (*((volatile unsigned int*)EMMC_WRAP_emmc_cpmask_0_reg))
#define  EMMC_WRAP_emmc_cpmask_0_cpmask_sel_shift                                (0)
#define  EMMC_WRAP_emmc_cpmask_0_cpmask_sel_mask                                 (0x00000001)
#define  EMMC_WRAP_emmc_cpmask_0_cpmask_sel(data)                                (0x00000001&(data))
#define  EMMC_WRAP_emmc_cpmask_0_get_cpmask_sel(data)                            (0x00000001&(data))

#define  EMMC_WRAP_emmc_cpmask_1                                                 0x18010884
#define  EMMC_WRAP_emmc_cpmask_1_reg_addr                                        "0xB8010884"
#define  EMMC_WRAP_emmc_cpmask_1_reg                                             0xB8010884
#define  EMMC_WRAP_emmc_cpmask_1_inst_addr                                       "0x0019"
#define  set_EMMC_WRAP_emmc_cpmask_1_reg(data)                                   (*((volatile unsigned int*)EMMC_WRAP_emmc_cpmask_1_reg)=data)
#define  get_EMMC_WRAP_emmc_cpmask_1_reg                                         (*((volatile unsigned int*)EMMC_WRAP_emmc_cpmask_1_reg))
#define  EMMC_WRAP_emmc_cpmask_1_cpmask_begin_shift                              (0)
#define  EMMC_WRAP_emmc_cpmask_1_cpmask_begin_mask                               (0xFFFFFFFF)
#define  EMMC_WRAP_emmc_cpmask_1_cpmask_begin(data)                              (0xFFFFFFFF&(data))
#define  EMMC_WRAP_emmc_cpmask_1_get_cpmask_begin(data)                          (0xFFFFFFFF&(data))

#define  EMMC_WRAP_emmc_cpmask_2                                                 0x18010888
#define  EMMC_WRAP_emmc_cpmask_2_reg_addr                                        "0xB8010888"
#define  EMMC_WRAP_emmc_cpmask_2_reg                                             0xB8010888
#define  EMMC_WRAP_emmc_cpmask_2_inst_addr                                       "0x001A"
#define  set_EMMC_WRAP_emmc_cpmask_2_reg(data)                                   (*((volatile unsigned int*)EMMC_WRAP_emmc_cpmask_2_reg)=data)
#define  get_EMMC_WRAP_emmc_cpmask_2_reg                                         (*((volatile unsigned int*)EMMC_WRAP_emmc_cpmask_2_reg))
#define  EMMC_WRAP_emmc_cpmask_2_cpmask_end_shift                                (0)
#define  EMMC_WRAP_emmc_cpmask_2_cpmask_end_mask                                 (0xFFFFFFFF)
#define  EMMC_WRAP_emmc_cpmask_2_cpmask_end(data)                                (0xFFFFFFFF&(data))
#define  EMMC_WRAP_emmc_cpmask_2_get_cpmask_end(data)                            (0xFFFFFFFF&(data))

#define  EMMC_WRAP_half_cycle_cal_en                                             0x1801088C
#define  EMMC_WRAP_half_cycle_cal_en_reg_addr                                    "0xB801088C"
#define  EMMC_WRAP_half_cycle_cal_en_reg                                         0xB801088C
#define  EMMC_WRAP_half_cycle_cal_en_inst_addr                                   "0x001B"
#define  set_EMMC_WRAP_half_cycle_cal_en_reg(data)                               (*((volatile unsigned int*)EMMC_WRAP_half_cycle_cal_en_reg)=data)
#define  get_EMMC_WRAP_half_cycle_cal_en_reg                                     (*((volatile unsigned int*)EMMC_WRAP_half_cycle_cal_en_reg))
#define  EMMC_WRAP_half_cycle_cal_en_fw_mode_shift                               (18)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_cal_sel_shift                    (17)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_ref_thr_shift                    (9)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_res_thr_shift                    (3)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_res_mod_shift                    (1)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_cal_en_shift                     (0)
#define  EMMC_WRAP_half_cycle_cal_en_fw_mode_mask                                (0x00040000)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_cal_sel_mask                     (0x00020000)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_ref_thr_mask                     (0x0000FE00)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_res_thr_mask                     (0x000000F8)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_res_mod_mask                     (0x00000006)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_cal_en_mask                      (0x00000001)
#define  EMMC_WRAP_half_cycle_cal_en_fw_mode(data)                               (0x00040000&((data)<<18))
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_cal_sel(data)                    (0x00020000&((data)<<17))
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_ref_thr(data)                    (0x0000FE00&((data)<<9))
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_res_thr(data)                    (0x000000F8&((data)<<3))
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_res_mod(data)                    (0x00000006&((data)<<1))
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_cal_en(data)                     (0x00000001&(data))
#define  EMMC_WRAP_half_cycle_cal_en_get_fw_mode(data)                           ((0x00040000&(data))>>18)
#define  EMMC_WRAP_half_cycle_cal_en_get_half_cycle_cal_sel(data)                ((0x00020000&(data))>>17)
#define  EMMC_WRAP_half_cycle_cal_en_get_half_cycle_ref_thr(data)                ((0x0000FE00&(data))>>9)
#define  EMMC_WRAP_half_cycle_cal_en_get_half_cycle_res_thr(data)                ((0x000000F8&(data))>>3)
#define  EMMC_WRAP_half_cycle_cal_en_get_half_cycle_res_mod(data)                ((0x00000006&(data))>>1)
#define  EMMC_WRAP_half_cycle_cal_en_get_half_cycle_cal_en(data)                 (0x00000001&(data))

#define  EMMC_WRAP_half_cycle_cal_result                                         0x18010890
#define  EMMC_WRAP_half_cycle_cal_result_reg_addr                                "0xB8010890"
#define  EMMC_WRAP_half_cycle_cal_result_reg                                     0xB8010890
#define  EMMC_WRAP_half_cycle_cal_result_inst_addr                               "0x001C"
#define  set_EMMC_WRAP_half_cycle_cal_result_reg(data)                           (*((volatile unsigned int*)EMMC_WRAP_half_cycle_cal_result_reg)=data)
#define  get_EMMC_WRAP_half_cycle_cal_result_reg                                 (*((volatile unsigned int*)EMMC_WRAP_half_cycle_cal_result_reg))
#define  EMMC_WRAP_half_cycle_cal_result_half_cycle_cal_result_shift             (0)
#define  EMMC_WRAP_half_cycle_cal_result_half_cycle_cal_result_mask              (0x0000001F)
#define  EMMC_WRAP_half_cycle_cal_result_half_cycle_cal_result(data)             (0x0000001F&(data))
#define  EMMC_WRAP_half_cycle_cal_result_get_half_cycle_cal_result(data)         (0x0000001F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======EMMC_WRAP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  scpu_stop:1;
        RBus_UInt32  scpu_status:1;
        RBus_UInt32  scpu_sel:1;
    };
}emmc_wrap_emmc_scpu_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dma_rd_done_scpu:1;
        RBus_UInt32  dma_wr_done_scpu:1;
        RBus_UInt32  stop_by_kcpu_force_scpu:1;
    };
}emmc_wrap_emmc_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dma_rd_done_mask_scpu:1;
        RBus_UInt32  dma_wr_done_mask_scpu:1;
        RBus_UInt32  stop_by_kcpu_force_mask_scpu:1;
    };
}emmc_wrap_emmc_int_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}emmc_wrap_emmc_int_dummy0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  kcpu_force_en:1;
        RBus_UInt32  protect_addr_en:1;
        RBus_UInt32  kcpu_status:1;
        RBus_UInt32  kcpu_sel:1;
    };
}emmc_wrap_emmc_kcpu_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_proct_addr:32;
    };
}emmc_wrap_emmc_start_protect_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  end_proct_addr:32;
    };
}emmc_wrap_emmc_end_protect_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dma_rd_done_kcpu:1;
        RBus_UInt32  dma_wr_done_kcpu:1;
        RBus_UInt32  protect_hit_kcpu:1;
    };
}emmc_wrap_emmc_int_status_kcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dma_rd_done_mask_kcpu:1;
        RBus_UInt32  dma_wr_done_mask_kcpu:1;
        RBus_UInt32  protect_hit_mask_kcpu:1;
    };
}emmc_wrap_emmc_int_mask_kcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}emmc_wrap_dummy0_kcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}emmc_wrap_dummy1_kcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}emmc_wrap_dummy2_kcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_blk_len:15;
        RBus_UInt32  cp_mode_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dummy_reg:1;
        RBus_UInt32  cclk_in_sample_ext_en:1;
        RBus_UInt32  eco_option0_dis:1;
        RBus_UInt32  m_hbigendian:1;
        RBus_UInt32  s_hbigendian:1;
        RBus_UInt32  cclk_out_src_sel:1;
        RBus_UInt32  wrap_version:1;
        RBus_UInt32  debug_mux:6;
        RBus_UInt32  debug_ctrl:1;
    };
}emmc_wrap_emmc_wrap_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  real_dummy0:13;
        RBus_UInt32  eco_option0:1;
        RBus_UInt32  use_synopsys:1;
        RBus_UInt32  hs400_use_drv:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  rbus_err:1;
        RBus_UInt32  dbus_dma_busy:1;
        RBus_UInt32  dbus_write_flag:1;
    };
}emmc_wrap_emmc_wrap_status0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  ictrl_state:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  top_sm:15;
    };
}emmc_wrap_emmc_wrap_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}emmc_wrap_emmc_wrap_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  emmc_ip_ls_1:1;
        RBus_UInt32  emmc_ip_rm_1:4;
        RBus_UInt32  emmc_ip_rme_1:1;
        RBus_UInt32  emmc_ip_ls_0:1;
        RBus_UInt32  emmc_ip_rm_0:4;
        RBus_UInt32  emmc_ip_rme_0:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  emmc_ip_drf_bist_fail_1:1;
        RBus_UInt32  emmc_ip_drf_bist_fail_0:1;
        RBus_UInt32  emmc_ip_drf_bist_done:1;
        RBus_UInt32  emmc_ip_drf_pause:1;
        RBus_UInt32  emmc_ip_drf_resume:1;
        RBus_UInt32  emmc_ip_drf_bist_mode:1;
        RBus_UInt32  emmc_ip_bist_fail_1:1;
        RBus_UInt32  emmc_ip_bist_fail_0:1;
        RBus_UInt32  emmc_ip_bist_done:1;
        RBus_UInt32  emmc_ip_bist_mode:1;
    };
}emmc_wrap_emmc_ip_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  emmc_wrap_ls:1;
        RBus_UInt32  emmc_wrap_rm:4;
        RBus_UInt32  emmc_wrap_rme:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  emmc_wrap_drf_bist_fail:1;
        RBus_UInt32  emmc_wrap_drf_bist_done:1;
        RBus_UInt32  emmc_wrap_drf_pause:1;
        RBus_UInt32  emmc_wrap_drf_resume:1;
        RBus_UInt32  emmc_wrap_drf_bist_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  emmc_wrap_bist_fail:1;
        RBus_UInt32  emmc_wrap_bist_done:1;
        RBus_UInt32  emmc_wrap_bist_mode:1;
    };
}emmc_wrap_emmc_wrap_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  cclk_out_sel:6;
        RBus_UInt32  cclk_in_sample_sel:6;
        RBus_UInt32  cclk_in_drv_sel:6;
    };
}emmc_wrap_clk_phase_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_dbg_mod:4;
        RBus_UInt32  res1:5;
        RBus_UInt32  rtk_hs200_pos:1;
        RBus_UInt32  rtk_hs200:1;
        RBus_UInt32  bypass_ds_tune:1;
        RBus_UInt32  bypass_ds_ph_sel:5;
        RBus_UInt32  rw_cnt_reset:1;
        RBus_UInt32  wr_adr_p_0_tran_sel:1;
        RBus_UInt32  rw_cnt_ref_align_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  fw_set_pulse:1;
        RBus_UInt32  dqsf_dlyn:2;
        RBus_UInt32  pos_trig_sel:2;
        RBus_UInt32  pre_trig_sel:2;
        RBus_UInt32  sync_cal_dlyn:1;
        RBus_UInt32  auto_cal:1;
        RBus_UInt32  dqs_del_offset_en:1;
    };
}emmc_wrap_ds_tune_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cal_dq1_neg_dlyn:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cal_dq1_pos_dlyn:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cal_dq0_neg_dlyn:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cal_dq0_pos_dlyn:6;
    };
}emmc_wrap_ds_tune_cal_dq0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cal_dq3_neg_dlyn:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cal_dq3_pos_dlyn:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cal_dq2_neg_dlyn:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cal_dq2_pos_dlyn:6;
    };
}emmc_wrap_ds_tune_cal_dq2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cal_dq5_neg_dlyn:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cal_dq5_pos_dlyn:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cal_dq4_neg_dlyn:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cal_dq4_pos_dlyn:6;
    };
}emmc_wrap_ds_tune_cal_dq4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cal_dq7_neg_dlyn:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cal_dq7_pos_dlyn:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cal_dq6_neg_dlyn:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cal_dq6_pos_dlyn:6;
    };
}emmc_wrap_ds_tune_cal_dq6_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ph_sel_dq_neg_1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ph_sel_dq_pos_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ph_sel_dq_neg_0:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ph_sel_dq_pos_0:6;
    };
}emmc_wrap_ds_tune_ph_sel_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ph_sel_dq_neg_3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ph_sel_dq_pos_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ph_sel_dq_neg_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ph_sel_dq_pos_2:6;
    };
}emmc_wrap_ds_tune_ph_sel_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ph_sel_dq_neg_5:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ph_sel_dq_pos_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ph_sel_dq_neg_4:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ph_sel_dq_pos_4:6;
    };
}emmc_wrap_ds_tune_ph_sel_4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ph_sel_dq_neg_7:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ph_sel_dq_pos_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ph_sel_dq_neg_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ph_sel_dq_pos_6:6;
    };
}emmc_wrap_ds_tune_ph_sel_6_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rcv_1st_dq_ph_sel_7:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_6:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_5:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_4:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_3:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_2:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_1:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_0:4;
    };
}emmc_wrap_ds_tune_rcv_1st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  cpmask_sel:1;
    };
}emmc_wrap_emmc_cpmask_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cpmask_begin:32;
    };
}emmc_wrap_emmc_cpmask_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cpmask_end:32;
    };
}emmc_wrap_emmc_cpmask_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  fw_mode:1;
        RBus_UInt32  half_cycle_cal_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  half_cycle_ref_thr:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  half_cycle_res_thr:5;
        RBus_UInt32  half_cycle_res_mod:2;
        RBus_UInt32  half_cycle_cal_en:1;
    };
}emmc_wrap_half_cycle_cal_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  half_cycle_cal_result:5;
    };
}emmc_wrap_half_cycle_cal_result_RBUS;

#else //apply LITTLE_ENDIAN

//======EMMC_WRAP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_sel:1;
        RBus_UInt32  scpu_status:1;
        RBus_UInt32  scpu_stop:1;
        RBus_UInt32  res1:29;
    };
}emmc_wrap_emmc_scpu_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stop_by_kcpu_force_scpu:1;
        RBus_UInt32  dma_wr_done_scpu:1;
        RBus_UInt32  dma_rd_done_scpu:1;
        RBus_UInt32  res1:29;
    };
}emmc_wrap_emmc_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stop_by_kcpu_force_mask_scpu:1;
        RBus_UInt32  dma_wr_done_mask_scpu:1;
        RBus_UInt32  dma_rd_done_mask_scpu:1;
        RBus_UInt32  res1:29;
    };
}emmc_wrap_emmc_int_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}emmc_wrap_emmc_int_dummy0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_sel:1;
        RBus_UInt32  kcpu_status:1;
        RBus_UInt32  protect_addr_en:1;
        RBus_UInt32  kcpu_force_en:1;
        RBus_UInt32  res1:28;
    };
}emmc_wrap_emmc_kcpu_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_proct_addr:32;
    };
}emmc_wrap_emmc_start_protect_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  end_proct_addr:32;
    };
}emmc_wrap_emmc_end_protect_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  protect_hit_kcpu:1;
        RBus_UInt32  dma_wr_done_kcpu:1;
        RBus_UInt32  dma_rd_done_kcpu:1;
        RBus_UInt32  res1:29;
    };
}emmc_wrap_emmc_int_status_kcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  protect_hit_mask_kcpu:1;
        RBus_UInt32  dma_wr_done_mask_kcpu:1;
        RBus_UInt32  dma_rd_done_mask_kcpu:1;
        RBus_UInt32  res1:29;
    };
}emmc_wrap_emmc_int_mask_kcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}emmc_wrap_dummy0_kcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}emmc_wrap_dummy1_kcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}emmc_wrap_dummy2_kcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_ctrl:1;
        RBus_UInt32  debug_mux:6;
        RBus_UInt32  wrap_version:1;
        RBus_UInt32  cclk_out_src_sel:1;
        RBus_UInt32  s_hbigendian:1;
        RBus_UInt32  m_hbigendian:1;
        RBus_UInt32  eco_option0_dis:1;
        RBus_UInt32  cclk_in_sample_ext_en:1;
        RBus_UInt32  dummy_reg:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_mode_en:1;
        RBus_UInt32  cp_blk_len:15;
        RBus_UInt32  res2:1;
    };
}emmc_wrap_emmc_wrap_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbus_write_flag:1;
        RBus_UInt32  dbus_dma_busy:1;
        RBus_UInt32  rbus_err:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  hs400_use_drv:1;
        RBus_UInt32  use_synopsys:1;
        RBus_UInt32  eco_option0:1;
        RBus_UInt32  real_dummy0:13;
    };
}emmc_wrap_emmc_wrap_status0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  top_sm:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  ictrl_state:3;
        RBus_UInt32  res2:13;
    };
}emmc_wrap_emmc_wrap_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}emmc_wrap_emmc_wrap_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_ip_bist_mode:1;
        RBus_UInt32  emmc_ip_bist_done:1;
        RBus_UInt32  emmc_ip_bist_fail_0:1;
        RBus_UInt32  emmc_ip_bist_fail_1:1;
        RBus_UInt32  emmc_ip_drf_bist_mode:1;
        RBus_UInt32  emmc_ip_drf_resume:1;
        RBus_UInt32  emmc_ip_drf_pause:1;
        RBus_UInt32  emmc_ip_drf_bist_done:1;
        RBus_UInt32  emmc_ip_drf_bist_fail_0:1;
        RBus_UInt32  emmc_ip_drf_bist_fail_1:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  emmc_ip_rme_0:1;
        RBus_UInt32  emmc_ip_rm_0:4;
        RBus_UInt32  emmc_ip_ls_0:1;
        RBus_UInt32  emmc_ip_rme_1:1;
        RBus_UInt32  emmc_ip_rm_1:4;
        RBus_UInt32  emmc_ip_ls_1:1;
        RBus_UInt32  res2:8;
    };
}emmc_wrap_emmc_ip_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_wrap_bist_mode:1;
        RBus_UInt32  emmc_wrap_bist_done:1;
        RBus_UInt32  emmc_wrap_bist_fail:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  emmc_wrap_drf_bist_mode:1;
        RBus_UInt32  emmc_wrap_drf_resume:1;
        RBus_UInt32  emmc_wrap_drf_pause:1;
        RBus_UInt32  emmc_wrap_drf_bist_done:1;
        RBus_UInt32  emmc_wrap_drf_bist_fail:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  emmc_wrap_rme:1;
        RBus_UInt32  emmc_wrap_rm:4;
        RBus_UInt32  emmc_wrap_ls:1;
        RBus_UInt32  res3:14;
    };
}emmc_wrap_emmc_wrap_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cclk_in_drv_sel:6;
        RBus_UInt32  cclk_in_sample_sel:6;
        RBus_UInt32  cclk_out_sel:6;
        RBus_UInt32  res1:14;
    };
}emmc_wrap_clk_phase_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dqs_del_offset_en:1;
        RBus_UInt32  auto_cal:1;
        RBus_UInt32  sync_cal_dlyn:1;
        RBus_UInt32  pre_trig_sel:2;
        RBus_UInt32  pos_trig_sel:2;
        RBus_UInt32  dqsf_dlyn:2;
        RBus_UInt32  fw_set_pulse:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  rw_cnt_ref_align_en:1;
        RBus_UInt32  wr_adr_p_0_tran_sel:1;
        RBus_UInt32  rw_cnt_reset:1;
        RBus_UInt32  bypass_ds_ph_sel:5;
        RBus_UInt32  bypass_ds_tune:1;
        RBus_UInt32  rtk_hs200:1;
        RBus_UInt32  rtk_hs200_pos:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  rd_dbg_mod:4;
    };
}emmc_wrap_ds_tune_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cal_dq0_pos_dlyn:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cal_dq0_neg_dlyn:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cal_dq1_pos_dlyn:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cal_dq1_neg_dlyn:6;
        RBus_UInt32  res4:2;
    };
}emmc_wrap_ds_tune_cal_dq0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cal_dq2_pos_dlyn:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cal_dq2_neg_dlyn:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cal_dq3_pos_dlyn:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cal_dq3_neg_dlyn:6;
        RBus_UInt32  res4:2;
    };
}emmc_wrap_ds_tune_cal_dq2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cal_dq4_pos_dlyn:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cal_dq4_neg_dlyn:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cal_dq5_pos_dlyn:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cal_dq5_neg_dlyn:6;
        RBus_UInt32  res4:2;
    };
}emmc_wrap_ds_tune_cal_dq4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cal_dq6_pos_dlyn:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cal_dq6_neg_dlyn:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cal_dq7_pos_dlyn:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cal_dq7_neg_dlyn:6;
        RBus_UInt32  res4:2;
    };
}emmc_wrap_ds_tune_cal_dq6_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ph_sel_dq_pos_0:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ph_sel_dq_neg_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ph_sel_dq_pos_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ph_sel_dq_neg_1:6;
        RBus_UInt32  res4:2;
    };
}emmc_wrap_ds_tune_ph_sel_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ph_sel_dq_pos_2:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ph_sel_dq_neg_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ph_sel_dq_pos_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ph_sel_dq_neg_3:6;
        RBus_UInt32  res4:2;
    };
}emmc_wrap_ds_tune_ph_sel_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ph_sel_dq_pos_4:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ph_sel_dq_neg_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ph_sel_dq_pos_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ph_sel_dq_neg_5:6;
        RBus_UInt32  res4:2;
    };
}emmc_wrap_ds_tune_ph_sel_4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ph_sel_dq_pos_6:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ph_sel_dq_neg_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ph_sel_dq_pos_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ph_sel_dq_neg_7:6;
        RBus_UInt32  res4:2;
    };
}emmc_wrap_ds_tune_ph_sel_6_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rcv_1st_dq_ph_sel_0:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_1:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_2:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_3:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_4:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_5:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_6:4;
        RBus_UInt32  rcv_1st_dq_ph_sel_7:4;
    };
}emmc_wrap_ds_tune_rcv_1st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cpmask_sel:1;
        RBus_UInt32  res1:31;
    };
}emmc_wrap_emmc_cpmask_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cpmask_begin:32;
    };
}emmc_wrap_emmc_cpmask_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cpmask_end:32;
    };
}emmc_wrap_emmc_cpmask_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  half_cycle_cal_en:1;
        RBus_UInt32  half_cycle_res_mod:2;
        RBus_UInt32  half_cycle_res_thr:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  half_cycle_ref_thr:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  half_cycle_cal_sel:1;
        RBus_UInt32  fw_mode:1;
        RBus_UInt32  res3:13;
    };
}emmc_wrap_half_cycle_cal_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  half_cycle_cal_result:5;
        RBus_UInt32  res1:27;
    };
}emmc_wrap_half_cycle_cal_result_RBUS;




#endif 


#endif 
