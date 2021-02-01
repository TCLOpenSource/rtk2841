/**
* @file Mac5-DesignSpec-EMMC
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
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
#define  EMMC_WRAP_emmc_int_status_scpu_interrupt_shift                          (3)
#define  EMMC_WRAP_emmc_int_status_dma_rd_done_scpu_shift                        (2)
#define  EMMC_WRAP_emmc_int_status_dma_wr_done_scpu_shift                        (1)
#define  EMMC_WRAP_emmc_int_status_stop_by_kcpu_force_scpu_shift                 (0)
#define  EMMC_WRAP_emmc_int_status_scpu_interrupt_mask                           (0x00000008)
#define  EMMC_WRAP_emmc_int_status_dma_rd_done_scpu_mask                         (0x00000004)
#define  EMMC_WRAP_emmc_int_status_dma_wr_done_scpu_mask                         (0x00000002)
#define  EMMC_WRAP_emmc_int_status_stop_by_kcpu_force_scpu_mask                  (0x00000001)
#define  EMMC_WRAP_emmc_int_status_scpu_interrupt(data)                          (0x00000008&((data)<<3))
#define  EMMC_WRAP_emmc_int_status_dma_rd_done_scpu(data)                        (0x00000004&((data)<<2))
#define  EMMC_WRAP_emmc_int_status_dma_wr_done_scpu(data)                        (0x00000002&((data)<<1))
#define  EMMC_WRAP_emmc_int_status_stop_by_kcpu_force_scpu(data)                 (0x00000001&(data))
#define  EMMC_WRAP_emmc_int_status_get_scpu_interrupt(data)                      ((0x00000008&(data))>>3)
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

#define  EMMC_WRAP_emmc_int_dummy0                                               0x1801080C
#define  EMMC_WRAP_emmc_int_dummy0_reg_addr                                      "0xB801080C"
#define  EMMC_WRAP_emmc_int_dummy0_reg                                           0xB801080C
#define  EMMC_WRAP_emmc_int_dummy0_inst_addr                                     "0x0003"
#define  set_EMMC_WRAP_emmc_int_dummy0_reg(data)                                 (*((volatile unsigned int*)EMMC_WRAP_emmc_int_dummy0_reg)=data)
#define  get_EMMC_WRAP_emmc_int_dummy0_reg                                       (*((volatile unsigned int*)EMMC_WRAP_emmc_int_dummy0_reg))
#define  EMMC_WRAP_emmc_int_dummy0_real_dummy1_shift                             (0)
#define  EMMC_WRAP_emmc_int_dummy0_real_dummy1_mask                              (0xFFFFFFFF)
#define  EMMC_WRAP_emmc_int_dummy0_real_dummy1(data)                             (0xFFFFFFFF&(data))
#define  EMMC_WRAP_emmc_int_dummy0_get_real_dummy1(data)                         (0xFFFFFFFF&(data))

#define  EMMC_WRAP_emmc_kcpu_sel                                                 0x18010810
#define  EMMC_WRAP_emmc_kcpu_sel_reg_addr                                        "0xB8010810"
#define  EMMC_WRAP_emmc_kcpu_sel_reg                                             0xB8010810
#define  EMMC_WRAP_emmc_kcpu_sel_inst_addr                                       "0x0004"
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
#define  EMMC_WRAP_emmc_start_protect_addr_inst_addr                             "0x0005"
#define  set_EMMC_WRAP_emmc_start_protect_addr_reg(data)                         (*((volatile unsigned int*)EMMC_WRAP_emmc_start_protect_addr_reg)=data)
#define  get_EMMC_WRAP_emmc_start_protect_addr_reg                               (*((volatile unsigned int*)EMMC_WRAP_emmc_start_protect_addr_reg))
#define  EMMC_WRAP_emmc_start_protect_addr_start_proct_addr_shift                (0)
#define  EMMC_WRAP_emmc_start_protect_addr_start_proct_addr_mask                 (0xFFFFFFFF)
#define  EMMC_WRAP_emmc_start_protect_addr_start_proct_addr(data)                (0xFFFFFFFF&(data))
#define  EMMC_WRAP_emmc_start_protect_addr_get_start_proct_addr(data)            (0xFFFFFFFF&(data))

#define  EMMC_WRAP_emmc_end_protect_addr                                         0x18010818
#define  EMMC_WRAP_emmc_end_protect_addr_reg_addr                                "0xB8010818"
#define  EMMC_WRAP_emmc_end_protect_addr_reg                                     0xB8010818
#define  EMMC_WRAP_emmc_end_protect_addr_inst_addr                               "0x0006"
#define  set_EMMC_WRAP_emmc_end_protect_addr_reg(data)                           (*((volatile unsigned int*)EMMC_WRAP_emmc_end_protect_addr_reg)=data)
#define  get_EMMC_WRAP_emmc_end_protect_addr_reg                                 (*((volatile unsigned int*)EMMC_WRAP_emmc_end_protect_addr_reg))
#define  EMMC_WRAP_emmc_end_protect_addr_end_proct_addr_shift                    (0)
#define  EMMC_WRAP_emmc_end_protect_addr_end_proct_addr_mask                     (0xFFFFFFFF)
#define  EMMC_WRAP_emmc_end_protect_addr_end_proct_addr(data)                    (0xFFFFFFFF&(data))
#define  EMMC_WRAP_emmc_end_protect_addr_get_end_proct_addr(data)                (0xFFFFFFFF&(data))

#define  EMMC_WRAP_emmc_int_status_kcpu                                          0x1801081C
#define  EMMC_WRAP_emmc_int_status_kcpu_reg_addr                                 "0xB801081C"
#define  EMMC_WRAP_emmc_int_status_kcpu_reg                                      0xB801081C
#define  EMMC_WRAP_emmc_int_status_kcpu_inst_addr                                "0x0007"
#define  set_EMMC_WRAP_emmc_int_status_kcpu_reg(data)                            (*((volatile unsigned int*)EMMC_WRAP_emmc_int_status_kcpu_reg)=data)
#define  get_EMMC_WRAP_emmc_int_status_kcpu_reg                                  (*((volatile unsigned int*)EMMC_WRAP_emmc_int_status_kcpu_reg))
#define  EMMC_WRAP_emmc_int_status_kcpu_kcpu_interrupt_shift                     (3)
#define  EMMC_WRAP_emmc_int_status_kcpu_dma_rd_done_kcpu_shift                   (2)
#define  EMMC_WRAP_emmc_int_status_kcpu_dma_wr_done_kcpu_shift                   (1)
#define  EMMC_WRAP_emmc_int_status_kcpu_protect_hit_kcpu_shift                   (0)
#define  EMMC_WRAP_emmc_int_status_kcpu_kcpu_interrupt_mask                      (0x00000008)
#define  EMMC_WRAP_emmc_int_status_kcpu_dma_rd_done_kcpu_mask                    (0x00000004)
#define  EMMC_WRAP_emmc_int_status_kcpu_dma_wr_done_kcpu_mask                    (0x00000002)
#define  EMMC_WRAP_emmc_int_status_kcpu_protect_hit_kcpu_mask                    (0x00000001)
#define  EMMC_WRAP_emmc_int_status_kcpu_kcpu_interrupt(data)                     (0x00000008&((data)<<3))
#define  EMMC_WRAP_emmc_int_status_kcpu_dma_rd_done_kcpu(data)                   (0x00000004&((data)<<2))
#define  EMMC_WRAP_emmc_int_status_kcpu_dma_wr_done_kcpu(data)                   (0x00000002&((data)<<1))
#define  EMMC_WRAP_emmc_int_status_kcpu_protect_hit_kcpu(data)                   (0x00000001&(data))
#define  EMMC_WRAP_emmc_int_status_kcpu_get_kcpu_interrupt(data)                 ((0x00000008&(data))>>3)
#define  EMMC_WRAP_emmc_int_status_kcpu_get_dma_rd_done_kcpu(data)               ((0x00000004&(data))>>2)
#define  EMMC_WRAP_emmc_int_status_kcpu_get_dma_wr_done_kcpu(data)               ((0x00000002&(data))>>1)
#define  EMMC_WRAP_emmc_int_status_kcpu_get_protect_hit_kcpu(data)               (0x00000001&(data))

#define  EMMC_WRAP_emmc_int_mask_kcpu                                            0x18010820
#define  EMMC_WRAP_emmc_int_mask_kcpu_reg_addr                                   "0xB8010820"
#define  EMMC_WRAP_emmc_int_mask_kcpu_reg                                        0xB8010820
#define  EMMC_WRAP_emmc_int_mask_kcpu_inst_addr                                  "0x0008"
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
#define  EMMC_WRAP_emmc_wrap_ctrl_inst_addr                                      "0x0009"
#define  set_EMMC_WRAP_emmc_wrap_ctrl_reg(data)                                  (*((volatile unsigned int*)EMMC_WRAP_emmc_wrap_ctrl_reg)=data)
#define  get_EMMC_WRAP_emmc_wrap_ctrl_reg                                        (*((volatile unsigned int*)EMMC_WRAP_emmc_wrap_ctrl_reg))
#define  EMMC_WRAP_emmc_wrap_ctrl_wrap_sram_rd_option_shift                      (31)
#define  EMMC_WRAP_emmc_wrap_ctrl_cp_blk_len_shift                               (16)
#define  EMMC_WRAP_emmc_wrap_ctrl_cp_mode_en_shift                               (15)
#define  EMMC_WRAP_emmc_wrap_ctrl_m_hbigendian_shift                             (10)
#define  EMMC_WRAP_emmc_wrap_ctrl_s_hbigendian_shift                             (9)
#define  EMMC_WRAP_emmc_wrap_ctrl_cclk_out_src_sel_shift                         (8)
#define  EMMC_WRAP_emmc_wrap_ctrl_debug_mux_shift                                (1)
#define  EMMC_WRAP_emmc_wrap_ctrl_debug_ctrl_shift                               (0)
#define  EMMC_WRAP_emmc_wrap_ctrl_wrap_sram_rd_option_mask                       (0x80000000)
#define  EMMC_WRAP_emmc_wrap_ctrl_cp_blk_len_mask                                (0x7FFF0000)
#define  EMMC_WRAP_emmc_wrap_ctrl_cp_mode_en_mask                                (0x00008000)
#define  EMMC_WRAP_emmc_wrap_ctrl_m_hbigendian_mask                              (0x00000400)
#define  EMMC_WRAP_emmc_wrap_ctrl_s_hbigendian_mask                              (0x00000200)
#define  EMMC_WRAP_emmc_wrap_ctrl_cclk_out_src_sel_mask                          (0x00000100)
#define  EMMC_WRAP_emmc_wrap_ctrl_debug_mux_mask                                 (0x0000007E)
#define  EMMC_WRAP_emmc_wrap_ctrl_debug_ctrl_mask                                (0x00000001)
#define  EMMC_WRAP_emmc_wrap_ctrl_wrap_sram_rd_option(data)                      (0x80000000&((data)<<31))
#define  EMMC_WRAP_emmc_wrap_ctrl_cp_blk_len(data)                               (0x7FFF0000&((data)<<16))
#define  EMMC_WRAP_emmc_wrap_ctrl_cp_mode_en(data)                               (0x00008000&((data)<<15))
#define  EMMC_WRAP_emmc_wrap_ctrl_m_hbigendian(data)                             (0x00000400&((data)<<10))
#define  EMMC_WRAP_emmc_wrap_ctrl_s_hbigendian(data)                             (0x00000200&((data)<<9))
#define  EMMC_WRAP_emmc_wrap_ctrl_cclk_out_src_sel(data)                         (0x00000100&((data)<<8))
#define  EMMC_WRAP_emmc_wrap_ctrl_debug_mux(data)                                (0x0000007E&((data)<<1))
#define  EMMC_WRAP_emmc_wrap_ctrl_debug_ctrl(data)                               (0x00000001&(data))
#define  EMMC_WRAP_emmc_wrap_ctrl_get_wrap_sram_rd_option(data)                  ((0x80000000&(data))>>31)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_cp_blk_len(data)                           ((0x7FFF0000&(data))>>16)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_cp_mode_en(data)                           ((0x00008000&(data))>>15)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_m_hbigendian(data)                         ((0x00000400&(data))>>10)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_s_hbigendian(data)                         ((0x00000200&(data))>>9)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_cclk_out_src_sel(data)                     ((0x00000100&(data))>>8)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_debug_mux(data)                            ((0x0000007E&(data))>>1)
#define  EMMC_WRAP_emmc_wrap_ctrl_get_debug_ctrl(data)                           (0x00000001&(data))

#define  EMMC_WRAP_emmc_wrap_status0                                             0x18010834
#define  EMMC_WRAP_emmc_wrap_status0_reg_addr                                    "0xB8010834"
#define  EMMC_WRAP_emmc_wrap_status0_reg                                         0xB8010834
#define  EMMC_WRAP_emmc_wrap_status0_inst_addr                                   "0x000A"
#define  set_EMMC_WRAP_emmc_wrap_status0_reg(data)                               (*((volatile unsigned int*)EMMC_WRAP_emmc_wrap_status0_reg)=data)
#define  get_EMMC_WRAP_emmc_wrap_status0_reg                                     (*((volatile unsigned int*)EMMC_WRAP_emmc_wrap_status0_reg))
#define  EMMC_WRAP_emmc_wrap_status0_dsfifo_emptymux_shift                       (18)
#define  EMMC_WRAP_emmc_wrap_status0_use_synopsys_shift                          (17)
#define  EMMC_WRAP_emmc_wrap_status0_hs400_use_drv_shift                         (16)
#define  EMMC_WRAP_emmc_wrap_status0_ddr_bit_7_4_tie_shift                       (3)
#define  EMMC_WRAP_emmc_wrap_status0_rbus_err_shift                              (2)
#define  EMMC_WRAP_emmc_wrap_status0_dbus_dma_busy_shift                         (1)
#define  EMMC_WRAP_emmc_wrap_status0_dbus_write_flag_shift                       (0)
#define  EMMC_WRAP_emmc_wrap_status0_dsfifo_emptymux_mask                        (0x00040000)
#define  EMMC_WRAP_emmc_wrap_status0_use_synopsys_mask                           (0x00020000)
#define  EMMC_WRAP_emmc_wrap_status0_hs400_use_drv_mask                          (0x00010000)
#define  EMMC_WRAP_emmc_wrap_status0_ddr_bit_7_4_tie_mask                        (0x00000008)
#define  EMMC_WRAP_emmc_wrap_status0_rbus_err_mask                               (0x00000004)
#define  EMMC_WRAP_emmc_wrap_status0_dbus_dma_busy_mask                          (0x00000002)
#define  EMMC_WRAP_emmc_wrap_status0_dbus_write_flag_mask                        (0x00000001)
#define  EMMC_WRAP_emmc_wrap_status0_dsfifo_emptymux(data)                       (0x00040000&((data)<<18))
#define  EMMC_WRAP_emmc_wrap_status0_use_synopsys(data)                          (0x00020000&((data)<<17))
#define  EMMC_WRAP_emmc_wrap_status0_hs400_use_drv(data)                         (0x00010000&((data)<<16))
#define  EMMC_WRAP_emmc_wrap_status0_ddr_bit_7_4_tie(data)                       (0x00000008&((data)<<3))
#define  EMMC_WRAP_emmc_wrap_status0_rbus_err(data)                              (0x00000004&((data)<<2))
#define  EMMC_WRAP_emmc_wrap_status0_dbus_dma_busy(data)                         (0x00000002&((data)<<1))
#define  EMMC_WRAP_emmc_wrap_status0_dbus_write_flag(data)                       (0x00000001&(data))
#define  EMMC_WRAP_emmc_wrap_status0_get_dsfifo_emptymux(data)                   ((0x00040000&(data))>>18)
#define  EMMC_WRAP_emmc_wrap_status0_get_use_synopsys(data)                      ((0x00020000&(data))>>17)
#define  EMMC_WRAP_emmc_wrap_status0_get_hs400_use_drv(data)                     ((0x00010000&(data))>>16)
#define  EMMC_WRAP_emmc_wrap_status0_get_ddr_bit_7_4_tie(data)                   ((0x00000008&(data))>>3)
#define  EMMC_WRAP_emmc_wrap_status0_get_rbus_err(data)                          ((0x00000004&(data))>>2)
#define  EMMC_WRAP_emmc_wrap_status0_get_dbus_dma_busy(data)                     ((0x00000002&(data))>>1)
#define  EMMC_WRAP_emmc_wrap_status0_get_dbus_write_flag(data)                   (0x00000001&(data))

#define  EMMC_WRAP_emmc_wrap_status1                                             0x18010838
#define  EMMC_WRAP_emmc_wrap_status1_reg_addr                                    "0xB8010838"
#define  EMMC_WRAP_emmc_wrap_status1_reg                                         0xB8010838
#define  EMMC_WRAP_emmc_wrap_status1_inst_addr                                   "0x000B"
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

#define  EMMC_WRAP_debug_reg                                                     0x1801083C
#define  EMMC_WRAP_debug_reg_reg_addr                                            "0xB801083C"
#define  EMMC_WRAP_debug_reg_reg                                                 0xB801083C
#define  EMMC_WRAP_debug_reg_inst_addr                                           "0x000C"
#define  set_EMMC_WRAP_debug_reg_reg(data)                                       (*((volatile unsigned int*)EMMC_WRAP_debug_reg_reg)=data)
#define  get_EMMC_WRAP_debug_reg_reg                                             (*((volatile unsigned int*)EMMC_WRAP_debug_reg_reg))
#define  EMMC_WRAP_debug_reg_debug_data_shift                                    (0)
#define  EMMC_WRAP_debug_reg_debug_data_mask                                     (0xFFFFFFFF)
#define  EMMC_WRAP_debug_reg_debug_data(data)                                    (0xFFFFFFFF&(data))
#define  EMMC_WRAP_debug_reg_get_debug_data(data)                                (0xFFFFFFFF&(data))

#define  EMMC_WRAP_emmc_ip_bist                                                  0x18010840
#define  EMMC_WRAP_emmc_ip_bist_reg_addr                                         "0xB8010840"
#define  EMMC_WRAP_emmc_ip_bist_reg                                              0xB8010840
#define  EMMC_WRAP_emmc_ip_bist_inst_addr                                        "0x000D"
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
#define  EMMC_WRAP_emmc_wrap_bist_inst_addr                                      "0x000E"
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

#define  EMMC_WRAP_self_test                                                     0x1801084C
#define  EMMC_WRAP_self_test_reg_addr                                            "0xB801084C"
#define  EMMC_WRAP_self_test_reg                                                 0xB801084C
#define  EMMC_WRAP_self_test_inst_addr                                           "0x000F"
#define  set_EMMC_WRAP_self_test_reg(data)                                       (*((volatile unsigned int*)EMMC_WRAP_self_test_reg)=data)
#define  get_EMMC_WRAP_self_test_reg                                             (*((volatile unsigned int*)EMMC_WRAP_self_test_reg))
#define  EMMC_WRAP_self_test_sf_tx_mode_shift                                    (7)
#define  EMMC_WRAP_self_test_sf_tx_start_shift                                   (6)
#define  EMMC_WRAP_self_test_sf_tx_work_shift                                    (5)
#define  EMMC_WRAP_self_test_sf_rx_mode_shift                                    (4)
#define  EMMC_WRAP_self_test_sf_rx_start_shift                                   (3)
#define  EMMC_WRAP_self_test_sf_rx_gated_shift                                   (2)
#define  EMMC_WRAP_self_test_sf_rx_done_shift                                    (1)
#define  EMMC_WRAP_self_test_sf_rx_err_shift                                     (0)
#define  EMMC_WRAP_self_test_sf_tx_mode_mask                                     (0x00000080)
#define  EMMC_WRAP_self_test_sf_tx_start_mask                                    (0x00000040)
#define  EMMC_WRAP_self_test_sf_tx_work_mask                                     (0x00000020)
#define  EMMC_WRAP_self_test_sf_rx_mode_mask                                     (0x00000010)
#define  EMMC_WRAP_self_test_sf_rx_start_mask                                    (0x00000008)
#define  EMMC_WRAP_self_test_sf_rx_gated_mask                                    (0x00000004)
#define  EMMC_WRAP_self_test_sf_rx_done_mask                                     (0x00000002)
#define  EMMC_WRAP_self_test_sf_rx_err_mask                                      (0x00000001)
#define  EMMC_WRAP_self_test_sf_tx_mode(data)                                    (0x00000080&((data)<<7))
#define  EMMC_WRAP_self_test_sf_tx_start(data)                                   (0x00000040&((data)<<6))
#define  EMMC_WRAP_self_test_sf_tx_work(data)                                    (0x00000020&((data)<<5))
#define  EMMC_WRAP_self_test_sf_rx_mode(data)                                    (0x00000010&((data)<<4))
#define  EMMC_WRAP_self_test_sf_rx_start(data)                                   (0x00000008&((data)<<3))
#define  EMMC_WRAP_self_test_sf_rx_gated(data)                                   (0x00000004&((data)<<2))
#define  EMMC_WRAP_self_test_sf_rx_done(data)                                    (0x00000002&((data)<<1))
#define  EMMC_WRAP_self_test_sf_rx_err(data)                                     (0x00000001&(data))
#define  EMMC_WRAP_self_test_get_sf_tx_mode(data)                                ((0x00000080&(data))>>7)
#define  EMMC_WRAP_self_test_get_sf_tx_start(data)                               ((0x00000040&(data))>>6)
#define  EMMC_WRAP_self_test_get_sf_tx_work(data)                                ((0x00000020&(data))>>5)
#define  EMMC_WRAP_self_test_get_sf_rx_mode(data)                                ((0x00000010&(data))>>4)
#define  EMMC_WRAP_self_test_get_sf_rx_start(data)                               ((0x00000008&(data))>>3)
#define  EMMC_WRAP_self_test_get_sf_rx_gated(data)                               ((0x00000004&(data))>>2)
#define  EMMC_WRAP_self_test_get_sf_rx_done(data)                                ((0x00000002&(data))>>1)
#define  EMMC_WRAP_self_test_get_sf_rx_err(data)                                 (0x00000001&(data))

#define  EMMC_WRAP_ds_tune_ctrl                                                  0x18010850
#define  EMMC_WRAP_ds_tune_ctrl_reg_addr                                         "0xB8010850"
#define  EMMC_WRAP_ds_tune_ctrl_reg                                              0xB8010850
#define  EMMC_WRAP_ds_tune_ctrl_inst_addr                                        "0x0010"
#define  set_EMMC_WRAP_ds_tune_ctrl_reg(data)                                    (*((volatile unsigned int*)EMMC_WRAP_ds_tune_ctrl_reg)=data)
#define  get_EMMC_WRAP_ds_tune_ctrl_reg                                          (*((volatile unsigned int*)EMMC_WRAP_ds_tune_ctrl_reg))
#define  EMMC_WRAP_ds_tune_ctrl_bypass_ds_ph_sel_shift                           (15)
#define  EMMC_WRAP_ds_tune_ctrl_bypass_ds_ph_sel_mask                            (0x000F8000)
#define  EMMC_WRAP_ds_tune_ctrl_bypass_ds_ph_sel(data)                           (0x000F8000&((data)<<15))
#define  EMMC_WRAP_ds_tune_ctrl_get_bypass_ds_ph_sel(data)                       ((0x000F8000&(data))>>15)

#define  EMMC_WRAP_crc_15_14                                                     0x18010854
#define  EMMC_WRAP_crc_15_14_reg_addr                                            "0xB8010854"
#define  EMMC_WRAP_crc_15_14_reg                                                 0xB8010854
#define  EMMC_WRAP_crc_15_14_inst_addr                                           "0x0011"
#define  set_EMMC_WRAP_crc_15_14_reg(data)                                       (*((volatile unsigned int*)EMMC_WRAP_crc_15_14_reg)=data)
#define  get_EMMC_WRAP_crc_15_14_reg                                             (*((volatile unsigned int*)EMMC_WRAP_crc_15_14_reg))
#define  EMMC_WRAP_crc_15_14_odd_15_shift                                        (24)
#define  EMMC_WRAP_crc_15_14_even_15_shift                                       (16)
#define  EMMC_WRAP_crc_15_14_odd_14_shift                                        (8)
#define  EMMC_WRAP_crc_15_14_even_14_shift                                       (0)
#define  EMMC_WRAP_crc_15_14_odd_15_mask                                         (0xFF000000)
#define  EMMC_WRAP_crc_15_14_even_15_mask                                        (0x00FF0000)
#define  EMMC_WRAP_crc_15_14_odd_14_mask                                         (0x0000FF00)
#define  EMMC_WRAP_crc_15_14_even_14_mask                                        (0x000000FF)
#define  EMMC_WRAP_crc_15_14_odd_15(data)                                        (0xFF000000&((data)<<24))
#define  EMMC_WRAP_crc_15_14_even_15(data)                                       (0x00FF0000&((data)<<16))
#define  EMMC_WRAP_crc_15_14_odd_14(data)                                        (0x0000FF00&((data)<<8))
#define  EMMC_WRAP_crc_15_14_even_14(data)                                       (0x000000FF&(data))
#define  EMMC_WRAP_crc_15_14_get_odd_15(data)                                    ((0xFF000000&(data))>>24)
#define  EMMC_WRAP_crc_15_14_get_even_15(data)                                   ((0x00FF0000&(data))>>16)
#define  EMMC_WRAP_crc_15_14_get_odd_14(data)                                    ((0x0000FF00&(data))>>8)
#define  EMMC_WRAP_crc_15_14_get_even_14(data)                                   (0x000000FF&(data))

#define  EMMC_WRAP_crc_13_12                                                     0x18010858
#define  EMMC_WRAP_crc_13_12_reg_addr                                            "0xB8010858"
#define  EMMC_WRAP_crc_13_12_reg                                                 0xB8010858
#define  EMMC_WRAP_crc_13_12_inst_addr                                           "0x0012"
#define  set_EMMC_WRAP_crc_13_12_reg(data)                                       (*((volatile unsigned int*)EMMC_WRAP_crc_13_12_reg)=data)
#define  get_EMMC_WRAP_crc_13_12_reg                                             (*((volatile unsigned int*)EMMC_WRAP_crc_13_12_reg))
#define  EMMC_WRAP_crc_13_12_odd_13_shift                                        (24)
#define  EMMC_WRAP_crc_13_12_even_13_shift                                       (16)
#define  EMMC_WRAP_crc_13_12_odd_12_shift                                        (8)
#define  EMMC_WRAP_crc_13_12_even_12_shift                                       (0)
#define  EMMC_WRAP_crc_13_12_odd_13_mask                                         (0xFF000000)
#define  EMMC_WRAP_crc_13_12_even_13_mask                                        (0x00FF0000)
#define  EMMC_WRAP_crc_13_12_odd_12_mask                                         (0x0000FF00)
#define  EMMC_WRAP_crc_13_12_even_12_mask                                        (0x000000FF)
#define  EMMC_WRAP_crc_13_12_odd_13(data)                                        (0xFF000000&((data)<<24))
#define  EMMC_WRAP_crc_13_12_even_13(data)                                       (0x00FF0000&((data)<<16))
#define  EMMC_WRAP_crc_13_12_odd_12(data)                                        (0x0000FF00&((data)<<8))
#define  EMMC_WRAP_crc_13_12_even_12(data)                                       (0x000000FF&(data))
#define  EMMC_WRAP_crc_13_12_get_odd_13(data)                                    ((0xFF000000&(data))>>24)
#define  EMMC_WRAP_crc_13_12_get_even_13(data)                                   ((0x00FF0000&(data))>>16)
#define  EMMC_WRAP_crc_13_12_get_odd_12(data)                                    ((0x0000FF00&(data))>>8)
#define  EMMC_WRAP_crc_13_12_get_even_12(data)                                   (0x000000FF&(data))

#define  EMMC_WRAP_crc_11_10                                                     0x1801085C
#define  EMMC_WRAP_crc_11_10_reg_addr                                            "0xB801085C"
#define  EMMC_WRAP_crc_11_10_reg                                                 0xB801085C
#define  EMMC_WRAP_crc_11_10_inst_addr                                           "0x0013"
#define  set_EMMC_WRAP_crc_11_10_reg(data)                                       (*((volatile unsigned int*)EMMC_WRAP_crc_11_10_reg)=data)
#define  get_EMMC_WRAP_crc_11_10_reg                                             (*((volatile unsigned int*)EMMC_WRAP_crc_11_10_reg))
#define  EMMC_WRAP_crc_11_10_odd_11_shift                                        (24)
#define  EMMC_WRAP_crc_11_10_even_11_shift                                       (16)
#define  EMMC_WRAP_crc_11_10_odd_10_shift                                        (8)
#define  EMMC_WRAP_crc_11_10_even_10_shift                                       (0)
#define  EMMC_WRAP_crc_11_10_odd_11_mask                                         (0xFF000000)
#define  EMMC_WRAP_crc_11_10_even_11_mask                                        (0x00FF0000)
#define  EMMC_WRAP_crc_11_10_odd_10_mask                                         (0x0000FF00)
#define  EMMC_WRAP_crc_11_10_even_10_mask                                        (0x000000FF)
#define  EMMC_WRAP_crc_11_10_odd_11(data)                                        (0xFF000000&((data)<<24))
#define  EMMC_WRAP_crc_11_10_even_11(data)                                       (0x00FF0000&((data)<<16))
#define  EMMC_WRAP_crc_11_10_odd_10(data)                                        (0x0000FF00&((data)<<8))
#define  EMMC_WRAP_crc_11_10_even_10(data)                                       (0x000000FF&(data))
#define  EMMC_WRAP_crc_11_10_get_odd_11(data)                                    ((0xFF000000&(data))>>24)
#define  EMMC_WRAP_crc_11_10_get_even_11(data)                                   ((0x00FF0000&(data))>>16)
#define  EMMC_WRAP_crc_11_10_get_odd_10(data)                                    ((0x0000FF00&(data))>>8)
#define  EMMC_WRAP_crc_11_10_get_even_10(data)                                   (0x000000FF&(data))

#define  EMMC_WRAP_crc_9_8                                                       0x18010860
#define  EMMC_WRAP_crc_9_8_reg_addr                                              "0xB8010860"
#define  EMMC_WRAP_crc_9_8_reg                                                   0xB8010860
#define  EMMC_WRAP_crc_9_8_inst_addr                                             "0x0014"
#define  set_EMMC_WRAP_crc_9_8_reg(data)                                         (*((volatile unsigned int*)EMMC_WRAP_crc_9_8_reg)=data)
#define  get_EMMC_WRAP_crc_9_8_reg                                               (*((volatile unsigned int*)EMMC_WRAP_crc_9_8_reg))
#define  EMMC_WRAP_crc_9_8_odd_9_shift                                           (24)
#define  EMMC_WRAP_crc_9_8_even_9_shift                                          (16)
#define  EMMC_WRAP_crc_9_8_odd_8_shift                                           (8)
#define  EMMC_WRAP_crc_9_8_even_8_shift                                          (0)
#define  EMMC_WRAP_crc_9_8_odd_9_mask                                            (0xFF000000)
#define  EMMC_WRAP_crc_9_8_even_9_mask                                           (0x00FF0000)
#define  EMMC_WRAP_crc_9_8_odd_8_mask                                            (0x0000FF00)
#define  EMMC_WRAP_crc_9_8_even_8_mask                                           (0x000000FF)
#define  EMMC_WRAP_crc_9_8_odd_9(data)                                           (0xFF000000&((data)<<24))
#define  EMMC_WRAP_crc_9_8_even_9(data)                                          (0x00FF0000&((data)<<16))
#define  EMMC_WRAP_crc_9_8_odd_8(data)                                           (0x0000FF00&((data)<<8))
#define  EMMC_WRAP_crc_9_8_even_8(data)                                          (0x000000FF&(data))
#define  EMMC_WRAP_crc_9_8_get_odd_9(data)                                       ((0xFF000000&(data))>>24)
#define  EMMC_WRAP_crc_9_8_get_even_9(data)                                      ((0x00FF0000&(data))>>16)
#define  EMMC_WRAP_crc_9_8_get_odd_8(data)                                       ((0x0000FF00&(data))>>8)
#define  EMMC_WRAP_crc_9_8_get_even_8(data)                                      (0x000000FF&(data))

#define  EMMC_WRAP_crc_7_6                                                       0x18010864
#define  EMMC_WRAP_crc_7_6_reg_addr                                              "0xB8010864"
#define  EMMC_WRAP_crc_7_6_reg                                                   0xB8010864
#define  EMMC_WRAP_crc_7_6_inst_addr                                             "0x0015"
#define  set_EMMC_WRAP_crc_7_6_reg(data)                                         (*((volatile unsigned int*)EMMC_WRAP_crc_7_6_reg)=data)
#define  get_EMMC_WRAP_crc_7_6_reg                                               (*((volatile unsigned int*)EMMC_WRAP_crc_7_6_reg))
#define  EMMC_WRAP_crc_7_6_odd_7_shift                                           (24)
#define  EMMC_WRAP_crc_7_6_even_7_shift                                          (16)
#define  EMMC_WRAP_crc_7_6_odd_6_shift                                           (8)
#define  EMMC_WRAP_crc_7_6_even_6_shift                                          (0)
#define  EMMC_WRAP_crc_7_6_odd_7_mask                                            (0xFF000000)
#define  EMMC_WRAP_crc_7_6_even_7_mask                                           (0x00FF0000)
#define  EMMC_WRAP_crc_7_6_odd_6_mask                                            (0x0000FF00)
#define  EMMC_WRAP_crc_7_6_even_6_mask                                           (0x000000FF)
#define  EMMC_WRAP_crc_7_6_odd_7(data)                                           (0xFF000000&((data)<<24))
#define  EMMC_WRAP_crc_7_6_even_7(data)                                          (0x00FF0000&((data)<<16))
#define  EMMC_WRAP_crc_7_6_odd_6(data)                                           (0x0000FF00&((data)<<8))
#define  EMMC_WRAP_crc_7_6_even_6(data)                                          (0x000000FF&(data))
#define  EMMC_WRAP_crc_7_6_get_odd_7(data)                                       ((0xFF000000&(data))>>24)
#define  EMMC_WRAP_crc_7_6_get_even_7(data)                                      ((0x00FF0000&(data))>>16)
#define  EMMC_WRAP_crc_7_6_get_odd_6(data)                                       ((0x0000FF00&(data))>>8)
#define  EMMC_WRAP_crc_7_6_get_even_6(data)                                      (0x000000FF&(data))

#define  EMMC_WRAP_crc_5_4                                                       0x18010868
#define  EMMC_WRAP_crc_5_4_reg_addr                                              "0xB8010868"
#define  EMMC_WRAP_crc_5_4_reg                                                   0xB8010868
#define  EMMC_WRAP_crc_5_4_inst_addr                                             "0x0016"
#define  set_EMMC_WRAP_crc_5_4_reg(data)                                         (*((volatile unsigned int*)EMMC_WRAP_crc_5_4_reg)=data)
#define  get_EMMC_WRAP_crc_5_4_reg                                               (*((volatile unsigned int*)EMMC_WRAP_crc_5_4_reg))
#define  EMMC_WRAP_crc_5_4_odd_5_shift                                           (24)
#define  EMMC_WRAP_crc_5_4_even_5_shift                                          (16)
#define  EMMC_WRAP_crc_5_4_odd_4_shift                                           (8)
#define  EMMC_WRAP_crc_5_4_even_4_shift                                          (0)
#define  EMMC_WRAP_crc_5_4_odd_5_mask                                            (0xFF000000)
#define  EMMC_WRAP_crc_5_4_even_5_mask                                           (0x00FF0000)
#define  EMMC_WRAP_crc_5_4_odd_4_mask                                            (0x0000FF00)
#define  EMMC_WRAP_crc_5_4_even_4_mask                                           (0x000000FF)
#define  EMMC_WRAP_crc_5_4_odd_5(data)                                           (0xFF000000&((data)<<24))
#define  EMMC_WRAP_crc_5_4_even_5(data)                                          (0x00FF0000&((data)<<16))
#define  EMMC_WRAP_crc_5_4_odd_4(data)                                           (0x0000FF00&((data)<<8))
#define  EMMC_WRAP_crc_5_4_even_4(data)                                          (0x000000FF&(data))
#define  EMMC_WRAP_crc_5_4_get_odd_5(data)                                       ((0xFF000000&(data))>>24)
#define  EMMC_WRAP_crc_5_4_get_even_5(data)                                      ((0x00FF0000&(data))>>16)
#define  EMMC_WRAP_crc_5_4_get_odd_4(data)                                       ((0x0000FF00&(data))>>8)
#define  EMMC_WRAP_crc_5_4_get_even_4(data)                                      (0x000000FF&(data))

#define  EMMC_WRAP_crc_3_2                                                       0x1801086C
#define  EMMC_WRAP_crc_3_2_reg_addr                                              "0xB801086C"
#define  EMMC_WRAP_crc_3_2_reg                                                   0xB801086C
#define  EMMC_WRAP_crc_3_2_inst_addr                                             "0x0017"
#define  set_EMMC_WRAP_crc_3_2_reg(data)                                         (*((volatile unsigned int*)EMMC_WRAP_crc_3_2_reg)=data)
#define  get_EMMC_WRAP_crc_3_2_reg                                               (*((volatile unsigned int*)EMMC_WRAP_crc_3_2_reg))
#define  EMMC_WRAP_crc_3_2_odd_3_shift                                           (24)
#define  EMMC_WRAP_crc_3_2_even_3_shift                                          (16)
#define  EMMC_WRAP_crc_3_2_odd_2_shift                                           (8)
#define  EMMC_WRAP_crc_3_2_even_2_shift                                          (0)
#define  EMMC_WRAP_crc_3_2_odd_3_mask                                            (0xFF000000)
#define  EMMC_WRAP_crc_3_2_even_3_mask                                           (0x00FF0000)
#define  EMMC_WRAP_crc_3_2_odd_2_mask                                            (0x0000FF00)
#define  EMMC_WRAP_crc_3_2_even_2_mask                                           (0x000000FF)
#define  EMMC_WRAP_crc_3_2_odd_3(data)                                           (0xFF000000&((data)<<24))
#define  EMMC_WRAP_crc_3_2_even_3(data)                                          (0x00FF0000&((data)<<16))
#define  EMMC_WRAP_crc_3_2_odd_2(data)                                           (0x0000FF00&((data)<<8))
#define  EMMC_WRAP_crc_3_2_even_2(data)                                          (0x000000FF&(data))
#define  EMMC_WRAP_crc_3_2_get_odd_3(data)                                       ((0xFF000000&(data))>>24)
#define  EMMC_WRAP_crc_3_2_get_even_3(data)                                      ((0x00FF0000&(data))>>16)
#define  EMMC_WRAP_crc_3_2_get_odd_2(data)                                       ((0x0000FF00&(data))>>8)
#define  EMMC_WRAP_crc_3_2_get_even_2(data)                                      (0x000000FF&(data))

#define  EMMC_WRAP_crc_1_0                                                       0x18010870
#define  EMMC_WRAP_crc_1_0_reg_addr                                              "0xB8010870"
#define  EMMC_WRAP_crc_1_0_reg                                                   0xB8010870
#define  EMMC_WRAP_crc_1_0_inst_addr                                             "0x0018"
#define  set_EMMC_WRAP_crc_1_0_reg(data)                                         (*((volatile unsigned int*)EMMC_WRAP_crc_1_0_reg)=data)
#define  get_EMMC_WRAP_crc_1_0_reg                                               (*((volatile unsigned int*)EMMC_WRAP_crc_1_0_reg))
#define  EMMC_WRAP_crc_1_0_odd_1_shift                                           (24)
#define  EMMC_WRAP_crc_1_0_even_1_shift                                          (16)
#define  EMMC_WRAP_crc_1_0_odd_0_shift                                           (8)
#define  EMMC_WRAP_crc_1_0_even_0_shift                                          (0)
#define  EMMC_WRAP_crc_1_0_odd_1_mask                                            (0xFF000000)
#define  EMMC_WRAP_crc_1_0_even_1_mask                                           (0x00FF0000)
#define  EMMC_WRAP_crc_1_0_odd_0_mask                                            (0x0000FF00)
#define  EMMC_WRAP_crc_1_0_even_0_mask                                           (0x000000FF)
#define  EMMC_WRAP_crc_1_0_odd_1(data)                                           (0xFF000000&((data)<<24))
#define  EMMC_WRAP_crc_1_0_even_1(data)                                          (0x00FF0000&((data)<<16))
#define  EMMC_WRAP_crc_1_0_odd_0(data)                                           (0x0000FF00&((data)<<8))
#define  EMMC_WRAP_crc_1_0_even_0(data)                                          (0x000000FF&(data))
#define  EMMC_WRAP_crc_1_0_get_odd_1(data)                                       ((0xFF000000&(data))>>24)
#define  EMMC_WRAP_crc_1_0_get_even_1(data)                                      ((0x00FF0000&(data))>>16)
#define  EMMC_WRAP_crc_1_0_get_odd_0(data)                                       ((0x0000FF00&(data))>>8)
#define  EMMC_WRAP_crc_1_0_get_even_0(data)                                      (0x000000FF&(data))

#define  EMMC_WRAP_emmc_cpmask_0                                                 0x18010880
#define  EMMC_WRAP_emmc_cpmask_0_reg_addr                                        "0xB8010880"
#define  EMMC_WRAP_emmc_cpmask_0_reg                                             0xB8010880
#define  EMMC_WRAP_emmc_cpmask_0_inst_addr                                       "0x0019"
#define  set_EMMC_WRAP_emmc_cpmask_0_reg(data)                                   (*((volatile unsigned int*)EMMC_WRAP_emmc_cpmask_0_reg)=data)
#define  get_EMMC_WRAP_emmc_cpmask_0_reg                                         (*((volatile unsigned int*)EMMC_WRAP_emmc_cpmask_0_reg))
#define  EMMC_WRAP_emmc_cpmask_0_cpmask_sel_shift                                (0)
#define  EMMC_WRAP_emmc_cpmask_0_cpmask_sel_mask                                 (0x00000001)
#define  EMMC_WRAP_emmc_cpmask_0_cpmask_sel(data)                                (0x00000001&(data))
#define  EMMC_WRAP_emmc_cpmask_0_get_cpmask_sel(data)                            (0x00000001&(data))

#define  EMMC_WRAP_emmc_cpmask_1                                                 0x18010884
#define  EMMC_WRAP_emmc_cpmask_1_reg_addr                                        "0xB8010884"
#define  EMMC_WRAP_emmc_cpmask_1_reg                                             0xB8010884
#define  EMMC_WRAP_emmc_cpmask_1_inst_addr                                       "0x001A"
#define  set_EMMC_WRAP_emmc_cpmask_1_reg(data)                                   (*((volatile unsigned int*)EMMC_WRAP_emmc_cpmask_1_reg)=data)
#define  get_EMMC_WRAP_emmc_cpmask_1_reg                                         (*((volatile unsigned int*)EMMC_WRAP_emmc_cpmask_1_reg))
#define  EMMC_WRAP_emmc_cpmask_1_cpmask_begin_shift                              (0)
#define  EMMC_WRAP_emmc_cpmask_1_cpmask_begin_mask                               (0xFFFFFFFF)
#define  EMMC_WRAP_emmc_cpmask_1_cpmask_begin(data)                              (0xFFFFFFFF&(data))
#define  EMMC_WRAP_emmc_cpmask_1_get_cpmask_begin(data)                          (0xFFFFFFFF&(data))

#define  EMMC_WRAP_emmc_cpmask_2                                                 0x18010888
#define  EMMC_WRAP_emmc_cpmask_2_reg_addr                                        "0xB8010888"
#define  EMMC_WRAP_emmc_cpmask_2_reg                                             0xB8010888
#define  EMMC_WRAP_emmc_cpmask_2_inst_addr                                       "0x001B"
#define  set_EMMC_WRAP_emmc_cpmask_2_reg(data)                                   (*((volatile unsigned int*)EMMC_WRAP_emmc_cpmask_2_reg)=data)
#define  get_EMMC_WRAP_emmc_cpmask_2_reg                                         (*((volatile unsigned int*)EMMC_WRAP_emmc_cpmask_2_reg))
#define  EMMC_WRAP_emmc_cpmask_2_cpmask_end_shift                                (0)
#define  EMMC_WRAP_emmc_cpmask_2_cpmask_end_mask                                 (0xFFFFFFFF)
#define  EMMC_WRAP_emmc_cpmask_2_cpmask_end(data)                                (0xFFFFFFFF&(data))
#define  EMMC_WRAP_emmc_cpmask_2_get_cpmask_end(data)                            (0xFFFFFFFF&(data))

#define  EMMC_WRAP_half_cycle_cal_en                                             0x1801088C
#define  EMMC_WRAP_half_cycle_cal_en_reg_addr                                    "0xB801088C"
#define  EMMC_WRAP_half_cycle_cal_en_reg                                         0xB801088C
#define  EMMC_WRAP_half_cycle_cal_en_inst_addr                                   "0x001C"
#define  set_EMMC_WRAP_half_cycle_cal_en_reg(data)                               (*((volatile unsigned int*)EMMC_WRAP_half_cycle_cal_en_reg)=data)
#define  get_EMMC_WRAP_half_cycle_cal_en_reg                                     (*((volatile unsigned int*)EMMC_WRAP_half_cycle_cal_en_reg))
#define  EMMC_WRAP_half_cycle_cal_en_fw_mode_shift                               (18)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_ref_thr_shift                    (9)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_res_thr_shift                    (3)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_res_mod_shift                    (1)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_cal_en_shift                     (0)
#define  EMMC_WRAP_half_cycle_cal_en_fw_mode_mask                                (0x00040000)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_ref_thr_mask                     (0x0000FE00)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_res_thr_mask                     (0x000000F8)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_res_mod_mask                     (0x00000006)
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_cal_en_mask                      (0x00000001)
#define  EMMC_WRAP_half_cycle_cal_en_fw_mode(data)                               (0x00040000&((data)<<18))
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_ref_thr(data)                    (0x0000FE00&((data)<<9))
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_res_thr(data)                    (0x000000F8&((data)<<3))
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_res_mod(data)                    (0x00000006&((data)<<1))
#define  EMMC_WRAP_half_cycle_cal_en_half_cycle_cal_en(data)                     (0x00000001&(data))
#define  EMMC_WRAP_half_cycle_cal_en_get_fw_mode(data)                           ((0x00040000&(data))>>18)
#define  EMMC_WRAP_half_cycle_cal_en_get_half_cycle_ref_thr(data)                ((0x0000FE00&(data))>>9)
#define  EMMC_WRAP_half_cycle_cal_en_get_half_cycle_res_thr(data)                ((0x000000F8&(data))>>3)
#define  EMMC_WRAP_half_cycle_cal_en_get_half_cycle_res_mod(data)                ((0x00000006&(data))>>1)
#define  EMMC_WRAP_half_cycle_cal_en_get_half_cycle_cal_en(data)                 (0x00000001&(data))

#define  EMMC_WRAP_half_cycle_cal_result                                         0x18010890
#define  EMMC_WRAP_half_cycle_cal_result_reg_addr                                "0xB8010890"
#define  EMMC_WRAP_half_cycle_cal_result_reg                                     0xB8010890
#define  EMMC_WRAP_half_cycle_cal_result_inst_addr                               "0x001D"
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
        RBus_UInt32  res1:28;
        RBus_UInt32  scpu_interrupt:1;
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
        RBus_UInt32  real_dummy1:32;
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
        RBus_UInt32  res1:28;
        RBus_UInt32  kcpu_interrupt:1;
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
        RBus_UInt32  wrap_sram_rd_option:1;
        RBus_UInt32  cp_blk_len:15;
        RBus_UInt32  cp_mode_en:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  m_hbigendian:1;
        RBus_UInt32  s_hbigendian:1;
        RBus_UInt32  cclk_out_src_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  debug_mux:6;
        RBus_UInt32  debug_ctrl:1;
    };
}emmc_wrap_emmc_wrap_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  dsfifo_emptymux:1;
        RBus_UInt32  use_synopsys:1;
        RBus_UInt32  hs400_use_drv:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  ddr_bit_7_4_tie:1;
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
        RBus_UInt32  debug_data:32;
    };
}emmc_wrap_debug_reg_RBUS;

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
        RBus_UInt32  res1:24;
        RBus_UInt32  sf_tx_mode:1;
        RBus_UInt32  sf_tx_start:1;
        RBus_UInt32  sf_tx_work:1;
        RBus_UInt32  sf_rx_mode:1;
        RBus_UInt32  sf_rx_start:1;
        RBus_UInt32  sf_rx_gated:1;
        RBus_UInt32  sf_rx_done:1;
        RBus_UInt32  sf_rx_err:1;
    };
}emmc_wrap_self_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  bypass_ds_ph_sel:5;
        RBus_UInt32  res2:15;
    };
}emmc_wrap_ds_tune_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  odd_15:8;
        RBus_UInt32  even_15:8;
        RBus_UInt32  odd_14:8;
        RBus_UInt32  even_14:8;
    };
}emmc_wrap_crc_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  odd_13:8;
        RBus_UInt32  even_13:8;
        RBus_UInt32  odd_12:8;
        RBus_UInt32  even_12:8;
    };
}emmc_wrap_crc_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  odd_11:8;
        RBus_UInt32  even_11:8;
        RBus_UInt32  odd_10:8;
        RBus_UInt32  even_10:8;
    };
}emmc_wrap_crc_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  odd_9:8;
        RBus_UInt32  even_9:8;
        RBus_UInt32  odd_8:8;
        RBus_UInt32  even_8:8;
    };
}emmc_wrap_crc_9_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  odd_7:8;
        RBus_UInt32  even_7:8;
        RBus_UInt32  odd_6:8;
        RBus_UInt32  even_6:8;
    };
}emmc_wrap_crc_7_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  odd_5:8;
        RBus_UInt32  even_5:8;
        RBus_UInt32  odd_4:8;
        RBus_UInt32  even_4:8;
    };
}emmc_wrap_crc_5_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  odd_3:8;
        RBus_UInt32  even_3:8;
        RBus_UInt32  odd_2:8;
        RBus_UInt32  even_2:8;
    };
}emmc_wrap_crc_3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  odd_1:8;
        RBus_UInt32  even_1:8;
        RBus_UInt32  odd_0:8;
        RBus_UInt32  even_0:8;
    };
}emmc_wrap_crc_1_0_RBUS;

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
        RBus_UInt32  res2:2;
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
        RBus_UInt32  scpu_interrupt:1;
        RBus_UInt32  res1:28;
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
        RBus_UInt32  real_dummy1:32;
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
        RBus_UInt32  kcpu_interrupt:1;
        RBus_UInt32  res1:28;
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
        RBus_UInt32  res1:1;
        RBus_UInt32  cclk_out_src_sel:1;
        RBus_UInt32  s_hbigendian:1;
        RBus_UInt32  m_hbigendian:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  cp_mode_en:1;
        RBus_UInt32  cp_blk_len:15;
        RBus_UInt32  wrap_sram_rd_option:1;
    };
}emmc_wrap_emmc_wrap_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbus_write_flag:1;
        RBus_UInt32  dbus_dma_busy:1;
        RBus_UInt32  rbus_err:1;
        RBus_UInt32  ddr_bit_7_4_tie:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  hs400_use_drv:1;
        RBus_UInt32  use_synopsys:1;
        RBus_UInt32  dsfifo_emptymux:1;
        RBus_UInt32  res2:13;
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
        RBus_UInt32  debug_data:32;
    };
}emmc_wrap_debug_reg_RBUS;

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
        RBus_UInt32  sf_rx_err:1;
        RBus_UInt32  sf_rx_done:1;
        RBus_UInt32  sf_rx_gated:1;
        RBus_UInt32  sf_rx_start:1;
        RBus_UInt32  sf_rx_mode:1;
        RBus_UInt32  sf_tx_work:1;
        RBus_UInt32  sf_tx_start:1;
        RBus_UInt32  sf_tx_mode:1;
        RBus_UInt32  res1:24;
    };
}emmc_wrap_self_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  bypass_ds_ph_sel:5;
        RBus_UInt32  res2:12;
    };
}emmc_wrap_ds_tune_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  even_14:8;
        RBus_UInt32  odd_14:8;
        RBus_UInt32  even_15:8;
        RBus_UInt32  odd_15:8;
    };
}emmc_wrap_crc_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  even_12:8;
        RBus_UInt32  odd_12:8;
        RBus_UInt32  even_13:8;
        RBus_UInt32  odd_13:8;
    };
}emmc_wrap_crc_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  even_10:8;
        RBus_UInt32  odd_10:8;
        RBus_UInt32  even_11:8;
        RBus_UInt32  odd_11:8;
    };
}emmc_wrap_crc_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  even_8:8;
        RBus_UInt32  odd_8:8;
        RBus_UInt32  even_9:8;
        RBus_UInt32  odd_9:8;
    };
}emmc_wrap_crc_9_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  even_6:8;
        RBus_UInt32  odd_6:8;
        RBus_UInt32  even_7:8;
        RBus_UInt32  odd_7:8;
    };
}emmc_wrap_crc_7_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  even_4:8;
        RBus_UInt32  odd_4:8;
        RBus_UInt32  even_5:8;
        RBus_UInt32  odd_5:8;
    };
}emmc_wrap_crc_5_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  even_2:8;
        RBus_UInt32  odd_2:8;
        RBus_UInt32  even_3:8;
        RBus_UInt32  odd_3:8;
    };
}emmc_wrap_crc_3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  even_0:8;
        RBus_UInt32  odd_0:8;
        RBus_UInt32  even_1:8;
        RBus_UInt32  odd_1:8;
    };
}emmc_wrap_crc_1_0_RBUS;

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
        RBus_UInt32  res2:2;
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
