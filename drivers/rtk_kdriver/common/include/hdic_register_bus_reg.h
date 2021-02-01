/**
* @file rbusHDIC_REGISTER_BUSReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_HDIC_REGISTER_BUS_REG_H_
#define _RBUS_HDIC_REGISTER_BUS_REG_H_

#include "rbus_types.h"



//  HDIC_REGISTER_BUS Register Address
#define  HDIC_REGISTER_BUS_hdic_bus_soft_reset                                   0x1814E000
#define  HDIC_REGISTER_BUS_hdic_bus_soft_reset_reg_addr                          "0xB814E000"
#define  HDIC_REGISTER_BUS_hdic_bus_soft_reset_reg                               0xB814E000
#define  HDIC_REGISTER_BUS_hdic_bus_soft_reset_inst_addr                         "0x0000"
#define  set_HDIC_REGISTER_BUS_hdic_bus_soft_reset_reg(data)                     (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_bus_soft_reset_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_bus_soft_reset_reg                           (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_bus_soft_reset_reg))
#define  HDIC_REGISTER_BUS_hdic_bus_soft_reset_remain_dc_cnt_shift               (16)
#define  HDIC_REGISTER_BUS_hdic_bus_soft_reset_hdic_wrapper_soft_reset_shift     (0)
#define  HDIC_REGISTER_BUS_hdic_bus_soft_reset_remain_dc_cnt_mask                (0x001F0000)
#define  HDIC_REGISTER_BUS_hdic_bus_soft_reset_hdic_wrapper_soft_reset_mask      (0x00000001)
#define  HDIC_REGISTER_BUS_hdic_bus_soft_reset_remain_dc_cnt(data)               (0x001F0000&((data)<<16))
#define  HDIC_REGISTER_BUS_hdic_bus_soft_reset_hdic_wrapper_soft_reset(data)     (0x00000001&(data))
#define  HDIC_REGISTER_BUS_hdic_bus_soft_reset_get_remain_dc_cnt(data)           ((0x001F0000&(data))>>16)
#define  HDIC_REGISTER_BUS_hdic_bus_soft_reset_get_hdic_wrapper_soft_reset(data) (0x00000001&(data))

#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1                                    0x1814E004
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_reg_addr                           "0xB814E004"
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_reg                                0xB814E004
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_inst_addr                          "0x0001"
#define  set_HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_reg(data)                      (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_reg                            (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_reg))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_hdic_wrapper_endian_swap_shift     (4)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_hdic_wrapper_force_write_bufferable_shift (3)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_hdic_wrapper_in_order_mode_shift   (2)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_hdic_wrapper_rw_arbitration_shift  (0)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_hdic_wrapper_endian_swap_mask      (0x00000010)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_hdic_wrapper_force_write_bufferable_mask (0x00000008)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_hdic_wrapper_in_order_mode_mask    (0x00000004)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_hdic_wrapper_rw_arbitration_mask   (0x00000003)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_hdic_wrapper_endian_swap(data)     (0x00000010&((data)<<4))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_hdic_wrapper_force_write_bufferable(data) (0x00000008&((data)<<3))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_hdic_wrapper_in_order_mode(data)   (0x00000004&((data)<<2))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_hdic_wrapper_rw_arbitration(data)  (0x00000003&(data))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_get_hdic_wrapper_endian_swap(data) ((0x00000010&(data))>>4)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_get_hdic_wrapper_force_write_bufferable(data) ((0x00000008&(data))>>3)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_get_hdic_wrapper_in_order_mode(data) ((0x00000004&(data))>>2)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl1_get_hdic_wrapper_rw_arbitration(data) (0x00000003&(data))

#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3                                    0x1814E00C
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_reg_addr                           "0xB814E00C"
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_reg                                0xB814E00C
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_inst_addr                          "0x0002"
#define  set_HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_reg(data)                      (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_reg                            (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_reg))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_hdic_wrapper_rd_outstand_num_shift (16)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_hdic_wrapper_wr_outstand_num_shift (0)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_hdic_wrapper_rd_outstand_num_mask  (0x001F0000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_hdic_wrapper_wr_outstand_num_mask  (0x0000001F)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_hdic_wrapper_rd_outstand_num(data) (0x001F0000&((data)<<16))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_hdic_wrapper_wr_outstand_num(data) (0x0000001F&(data))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_get_hdic_wrapper_rd_outstand_num(data) ((0x001F0000&(data))>>16)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl3_get_hdic_wrapper_wr_outstand_num(data) (0x0000001F&(data))

#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl4                                    0x1814E010
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl4_reg_addr                           "0xB814E010"
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl4_reg                                0xB814E010
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl4_inst_addr                          "0x0003"
#define  set_HDIC_REGISTER_BUS_hdic_mem_bus_ctrl4_reg(data)                      (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_bus_ctrl4_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_mem_bus_ctrl4_reg                            (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_bus_ctrl4_reg))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl4_hdic_wrapper_addr_base_shift       (0)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl4_hdic_wrapper_addr_base_mask        (0xFFFFFFFF)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl4_hdic_wrapper_addr_base(data)       (0xFFFFFFFF&(data))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_ctrl4_get_hdic_wrapper_addr_base(data)   (0xFFFFFFFF&(data))

#define  HDIC_REGISTER_BUS_hdic_mem_bus_status1                                  0x1814E014
#define  HDIC_REGISTER_BUS_hdic_mem_bus_status1_reg_addr                         "0xB814E014"
#define  HDIC_REGISTER_BUS_hdic_mem_bus_status1_reg                              0xB814E014
#define  HDIC_REGISTER_BUS_hdic_mem_bus_status1_inst_addr                        "0x0004"
#define  set_HDIC_REGISTER_BUS_hdic_mem_bus_status1_reg(data)                    (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_bus_status1_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_mem_bus_status1_reg                          (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_bus_status1_reg))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_status1_hdic_wrapper_rd_outstand_cnt_shift (16)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_status1_hdic_wrapper_wr_outstand_cnt_shift (0)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_status1_hdic_wrapper_rd_outstand_cnt_mask (0x001F0000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_status1_hdic_wrapper_wr_outstand_cnt_mask (0x0000001F)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_status1_hdic_wrapper_rd_outstand_cnt(data) (0x001F0000&((data)<<16))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_status1_hdic_wrapper_wr_outstand_cnt(data) (0x0000001F&(data))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_status1_get_hdic_wrapper_rd_outstand_cnt(data) ((0x001F0000&(data))>>16)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_status1_get_hdic_wrapper_wr_outstand_cnt(data) (0x0000001F&(data))

#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist                                 0x1814E050
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_reg_addr                        "0xB814E050"
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_reg                             0xB814E050
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_inst_addr                       "0x0005"
#define  set_HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_reg(data)                   (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_reg                         (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_reg))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_hdic_wrapper_bist_mode_shift    (3)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_hdic_wrapper_bist_done_shift    (2)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_hdic_wrapper_bist_fail_0_shift  (1)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_hdic_wrapper_bist_fail_1_shift  (0)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_hdic_wrapper_bist_mode_mask     (0x00000008)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_hdic_wrapper_bist_done_mask     (0x00000004)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_hdic_wrapper_bist_fail_0_mask   (0x00000002)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_hdic_wrapper_bist_fail_1_mask   (0x00000001)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_hdic_wrapper_bist_mode(data)    (0x00000008&((data)<<3))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_hdic_wrapper_bist_done(data)    (0x00000004&((data)<<2))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_hdic_wrapper_bist_fail_0(data)  (0x00000002&((data)<<1))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_hdic_wrapper_bist_fail_1(data)  (0x00000001&(data))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_get_hdic_wrapper_bist_mode(data) ((0x00000008&(data))>>3)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_get_hdic_wrapper_bist_done(data) ((0x00000004&(data))>>2)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_get_hdic_wrapper_bist_fail_0(data) ((0x00000002&(data))>>1)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_bist_get_hdic_wrapper_bist_fail_1(data) (0x00000001&(data))

#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf                                  0x1814E054
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_reg_addr                         "0xB814E054"
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_reg                              0xB814E054
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_inst_addr                        "0x0006"
#define  set_HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_reg(data)                    (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_reg                          (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_reg))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_bist_mode_shift (5)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_test_resume_shift (4)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_start_pause_shift (3)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_bist_done_shift (2)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_bist_fail_0_shift (1)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_bist_fail_1_shift (0)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_bist_mode_mask  (0x00000020)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_test_resume_mask (0x00000010)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_start_pause_mask (0x00000008)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_bist_done_mask  (0x00000004)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_bist_fail_0_mask (0x00000002)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_bist_fail_1_mask (0x00000001)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_bist_mode(data) (0x00000020&((data)<<5))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_test_resume(data) (0x00000010&((data)<<4))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_start_pause(data) (0x00000008&((data)<<3))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_bist_done(data) (0x00000004&((data)<<2))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_bist_fail_0(data) (0x00000002&((data)<<1))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_hdic_wrapper_drf_bist_fail_1(data) (0x00000001&(data))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_get_hdic_wrapper_drf_bist_mode(data) ((0x00000020&(data))>>5)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_get_hdic_wrapper_drf_test_resume(data) ((0x00000010&(data))>>4)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_get_hdic_wrapper_drf_start_pause(data) ((0x00000008&(data))>>3)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_get_hdic_wrapper_drf_bist_done(data) ((0x00000004&(data))>>2)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_get_hdic_wrapper_drf_bist_fail_0(data) ((0x00000002&(data))>>1)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_drf_get_hdic_wrapper_drf_bist_fail_1(data) (0x00000001&(data))

#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl                            0x1814E058
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_reg_addr                   "0xB814E058"
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_reg                        0xB814E058
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_inst_addr                  "0x0007"
#define  set_HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_reg(data)              (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_reg                    (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_reg))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rma_0_shift                (28)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmb_0_shift                (24)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rma_1_shift                (20)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmb_1_shift                (16)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_ls_0_shift                 (5)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_ls_1_shift                 (4)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmea_0_shift               (3)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmeb_0_shift               (2)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmea_1_shift               (1)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmeb_1_shift               (0)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rma_0_mask                 (0xF0000000)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmb_0_mask                 (0x0F000000)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rma_1_mask                 (0x00F00000)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmb_1_mask                 (0x000F0000)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_ls_0_mask                  (0x00000020)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_ls_1_mask                  (0x00000010)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmea_0_mask                (0x00000008)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmeb_0_mask                (0x00000004)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmea_1_mask                (0x00000002)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmeb_1_mask                (0x00000001)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rma_0(data)                (0xF0000000&((data)<<28))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmb_0(data)                (0x0F000000&((data)<<24))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rma_1(data)                (0x00F00000&((data)<<20))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmb_1(data)                (0x000F0000&((data)<<16))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_ls_0(data)                 (0x00000020&((data)<<5))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_ls_1(data)                 (0x00000010&((data)<<4))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmea_0(data)               (0x00000008&((data)<<3))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmeb_0(data)               (0x00000004&((data)<<2))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmea_1(data)               (0x00000002&((data)<<1))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_rmeb_1(data)               (0x00000001&(data))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_get_rma_0(data)            ((0xF0000000&(data))>>28)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_get_rmb_0(data)            ((0x0F000000&(data))>>24)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_get_rma_1(data)            ((0x00F00000&(data))>>20)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_get_rmb_1(data)            ((0x000F0000&(data))>>16)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_get_ls_0(data)             ((0x00000020&(data))>>5)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_get_ls_1(data)             ((0x00000010&(data))>>4)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_get_rmea_0(data)           ((0x00000008&(data))>>3)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_get_rmeb_0(data)           ((0x00000004&(data))>>2)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_get_rmea_1(data)           ((0x00000002&(data))>>1)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_sram_ctrl_get_rmeb_1(data)           (0x00000001&(data))

#define  HDIC_REGISTER_BUS_hdic_sram_ctrl                                        0x1814E05C
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_reg_addr                               "0xB814E05C"
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_reg                                    0xB814E05C
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_inst_addr                              "0x0008"
#define  set_HDIC_REGISTER_BUS_hdic_sram_ctrl_reg(data)                          (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_sram_ctrl_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_sram_ctrl_reg                                (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_sram_ctrl_reg))
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_mbist_hdic_dvs_shift                   (28)
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_mbist_hdic_ls_shift                    (1)
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_mbist_hdic_dvse_shift                  (0)
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_mbist_hdic_dvs_mask                    (0xF0000000)
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_mbist_hdic_ls_mask                     (0x00000002)
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_mbist_hdic_dvse_mask                   (0x00000001)
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_mbist_hdic_dvs(data)                   (0xF0000000&((data)<<28))
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_mbist_hdic_ls(data)                    (0x00000002&((data)<<1))
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_mbist_hdic_dvse(data)                  (0x00000001&(data))
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_get_mbist_hdic_dvs(data)               ((0xF0000000&(data))>>28)
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_get_mbist_hdic_ls(data)                ((0x00000002&(data))>>1)
#define  HDIC_REGISTER_BUS_hdic_sram_ctrl_get_mbist_hdic_dvse(data)              (0x00000001&(data))

#define  HDIC_REGISTER_BUS_hdic_ip_config                                        0x1814E090
#define  HDIC_REGISTER_BUS_hdic_ip_config_reg_addr                               "0xB814E090"
#define  HDIC_REGISTER_BUS_hdic_ip_config_reg                                    0xB814E090
#define  HDIC_REGISTER_BUS_hdic_ip_config_inst_addr                              "0x0009"
#define  set_HDIC_REGISTER_BUS_hdic_ip_config_reg(data)                          (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_ip_config_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_ip_config_reg                                (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_ip_config_reg))
#define  HDIC_REGISTER_BUS_hdic_ip_config_hdic_dtmb_dbg_sw_shift                 (0)
#define  HDIC_REGISTER_BUS_hdic_ip_config_hdic_dtmb_dbg_sw_mask                  (0x00000003)
#define  HDIC_REGISTER_BUS_hdic_ip_config_hdic_dtmb_dbg_sw(data)                 (0x00000003&(data))
#define  HDIC_REGISTER_BUS_hdic_ip_config_get_hdic_dtmb_dbg_sw(data)             (0x00000003&(data))

#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status                              0x1814E060
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_reg_addr                     "0xB814E060"
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_reg                          0xB814E060
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_inst_addr                    "0x000A"
#define  set_HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_reg(data)                (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_reg                      (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_reg))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_rdata_buf_full_shift         (27)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_rdata_buf_empty_shift        (26)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_wdata_buf_full_shift         (25)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_wdata_buf_empty_shift        (24)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_bid_fifo_full_shift      (23)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_bid_fifo_empty_shift     (22)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wcmd_fifo_full_shift     (21)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wcmd_fifo_empty_shift    (20)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wdata_fifo_full_shift    (19)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wdata_fifo_empty_shift   (18)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wdata_phase_queue_full_shift (17)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wdata_phase_queue_empty_shift (16)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wcmd_async_fifo_full_shift (15)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wcmd_async_fifo_empty_shift (14)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wdata_async_fifo_full_shift (13)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wdata_async_fifo_empty_shift (12)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wlast_async_fifo_full_shift (11)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wlast_async_fifo_empty_shift (10)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rcmd_fifo_full_shift     (9)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rcmd_fifo_empty_shift    (8)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rdata_phase_queue_full_shift (7)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rdata_phase_queue_empty_shift (6)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rdata_fifo_full_shift    (5)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rdata_fifo_empty_shift   (4)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_rcmd_async_fifo_full_shift (3)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_rcmd_async_fifo_empty_shift (2)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_rdata_async_fifo_full_shift (1)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_rdata_async_fifo_empty_shift (0)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_rdata_buf_full_mask          (0x08000000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_rdata_buf_empty_mask         (0x04000000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_wdata_buf_full_mask          (0x02000000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_wdata_buf_empty_mask         (0x01000000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_bid_fifo_full_mask       (0x00800000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_bid_fifo_empty_mask      (0x00400000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wcmd_fifo_full_mask      (0x00200000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wcmd_fifo_empty_mask     (0x00100000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wdata_fifo_full_mask     (0x00080000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wdata_fifo_empty_mask    (0x00040000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wdata_phase_queue_full_mask (0x00020000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wdata_phase_queue_empty_mask (0x00010000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wcmd_async_fifo_full_mask (0x00008000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wcmd_async_fifo_empty_mask (0x00004000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wdata_async_fifo_full_mask (0x00002000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wdata_async_fifo_empty_mask (0x00001000)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wlast_async_fifo_full_mask (0x00000800)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wlast_async_fifo_empty_mask (0x00000400)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rcmd_fifo_full_mask      (0x00000200)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rcmd_fifo_empty_mask     (0x00000100)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rdata_phase_queue_full_mask (0x00000080)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rdata_phase_queue_empty_mask (0x00000040)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rdata_fifo_full_mask     (0x00000020)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rdata_fifo_empty_mask    (0x00000010)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_rcmd_async_fifo_full_mask (0x00000008)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_rcmd_async_fifo_empty_mask (0x00000004)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_rdata_async_fifo_full_mask (0x00000002)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_rdata_async_fifo_empty_mask (0x00000001)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_rdata_buf_full(data)         (0x08000000&((data)<<27))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_rdata_buf_empty(data)        (0x04000000&((data)<<26))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_wdata_buf_full(data)         (0x02000000&((data)<<25))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_wdata_buf_empty(data)        (0x01000000&((data)<<24))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_bid_fifo_full(data)      (0x00800000&((data)<<23))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_bid_fifo_empty(data)     (0x00400000&((data)<<22))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wcmd_fifo_full(data)     (0x00200000&((data)<<21))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wcmd_fifo_empty(data)    (0x00100000&((data)<<20))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wdata_fifo_full(data)    (0x00080000&((data)<<19))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wdata_fifo_empty(data)   (0x00040000&((data)<<18))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wdata_phase_queue_full(data) (0x00020000&((data)<<17))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_wdata_phase_queue_empty(data) (0x00010000&((data)<<16))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wcmd_async_fifo_full(data) (0x00008000&((data)<<15))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wcmd_async_fifo_empty(data) (0x00004000&((data)<<14))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wdata_async_fifo_full(data) (0x00002000&((data)<<13))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wdata_async_fifo_empty(data) (0x00001000&((data)<<12))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wlast_async_fifo_full(data) (0x00000800&((data)<<11))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_wlast_async_fifo_empty(data) (0x00000400&((data)<<10))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rcmd_fifo_full(data)     (0x00000200&((data)<<9))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rcmd_fifo_empty(data)    (0x00000100&((data)<<8))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rdata_phase_queue_full(data) (0x00000080&((data)<<7))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rdata_phase_queue_empty(data) (0x00000040&((data)<<6))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rdata_fifo_full(data)    (0x00000020&((data)<<5))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_axi_rdata_fifo_empty(data)   (0x00000010&((data)<<4))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_rcmd_async_fifo_full(data) (0x00000008&((data)<<3))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_rcmd_async_fifo_empty(data) (0x00000004&((data)<<2))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_rdata_async_fifo_full(data) (0x00000002&((data)<<1))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_dc_rdata_async_fifo_empty(data) (0x00000001&(data))
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_rdata_buf_full(data)     ((0x08000000&(data))>>27)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_rdata_buf_empty(data)    ((0x04000000&(data))>>26)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_wdata_buf_full(data)     ((0x02000000&(data))>>25)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_wdata_buf_empty(data)    ((0x01000000&(data))>>24)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_bid_fifo_full(data)  ((0x00800000&(data))>>23)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_bid_fifo_empty(data) ((0x00400000&(data))>>22)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_wcmd_fifo_full(data) ((0x00200000&(data))>>21)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_wcmd_fifo_empty(data) ((0x00100000&(data))>>20)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_wdata_fifo_full(data) ((0x00080000&(data))>>19)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_wdata_fifo_empty(data) ((0x00040000&(data))>>18)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_wdata_phase_queue_full(data) ((0x00020000&(data))>>17)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_wdata_phase_queue_empty(data) ((0x00010000&(data))>>16)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_dc_wcmd_async_fifo_full(data) ((0x00008000&(data))>>15)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_dc_wcmd_async_fifo_empty(data) ((0x00004000&(data))>>14)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_dc_wdata_async_fifo_full(data) ((0x00002000&(data))>>13)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_dc_wdata_async_fifo_empty(data) ((0x00001000&(data))>>12)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_dc_wlast_async_fifo_full(data) ((0x00000800&(data))>>11)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_dc_wlast_async_fifo_empty(data) ((0x00000400&(data))>>10)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_rcmd_fifo_full(data) ((0x00000200&(data))>>9)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_rcmd_fifo_empty(data) ((0x00000100&(data))>>8)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_rdata_phase_queue_full(data) ((0x00000080&(data))>>7)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_rdata_phase_queue_empty(data) ((0x00000040&(data))>>6)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_rdata_fifo_full(data) ((0x00000020&(data))>>5)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_axi_rdata_fifo_empty(data) ((0x00000010&(data))>>4)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_dc_rcmd_async_fifo_full(data) ((0x00000008&(data))>>3)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_dc_rcmd_async_fifo_empty(data) ((0x00000004&(data))>>2)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_dc_rdata_async_fifo_full(data) ((0x00000002&(data))>>1)
#define  HDIC_REGISTER_BUS_hdic_mem_bus_fifo_status_get_dc_rdata_async_fifo_empty(data) (0x00000001&(data))

#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1                             0x1814E070
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_reg_addr                    "0xB814E070"
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_reg                         0xB814E070
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_inst_addr                   "0x000B"
#define  set_HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_reg(data)               (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_reg                     (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_reg))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_stop_dbg_read_shift         (1)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_fetch_dbg_entry_read_shift  (0)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_stop_dbg_read_mask          (0x00000002)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_fetch_dbg_entry_read_mask   (0x00000001)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_stop_dbg_read(data)         (0x00000002&((data)<<1))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_fetch_dbg_entry_read(data)  (0x00000001&(data))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_get_stop_dbg_read(data)     ((0x00000002&(data))>>1)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_ctrl1_get_fetch_dbg_entry_read(data) (0x00000001&(data))

#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status1                           0x1814E074
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status1_reg_addr                  "0xB814E074"
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status1_reg                       0xB814E074
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status1_inst_addr                 "0x000C"
#define  set_HDIC_REGISTER_BUS_hdic_mem_debug_read_status1_reg(data)             (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_debug_read_status1_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_mem_debug_read_status1_reg                   (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_debug_read_status1_reg))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status1_valid_entry_cnt_read_shift (0)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status1_valid_entry_cnt_read_mask (0x0000001F)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status1_valid_entry_cnt_read(data) (0x0000001F&(data))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status1_get_valid_entry_cnt_read(data) (0x0000001F&(data))

#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status2                           0x1814E078
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_reg_addr                  "0xB814E078"
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_reg                       0xB814E078
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_inst_addr                 "0x000D"
#define  set_HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_reg(data)             (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_reg                   (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_reg))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_dbg_entry_axi_id_read_shift (26)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_dbg_entry_axi_addr_read_shift (0)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_dbg_entry_axi_id_read_mask (0x3C000000)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_dbg_entry_axi_addr_read_mask (0x03FFFFFF)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_dbg_entry_axi_id_read(data) (0x3C000000&((data)<<26))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_dbg_entry_axi_addr_read(data) (0x03FFFFFF&(data))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_get_dbg_entry_axi_id_read(data) ((0x3C000000&(data))>>26)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_read_status2_get_dbg_entry_axi_addr_read(data) (0x03FFFFFF&(data))

#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1                            0x1814E07C
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_reg_addr                   "0xB814E07C"
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_reg                        0xB814E07C
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_inst_addr                  "0x000E"
#define  set_HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_reg(data)              (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_reg                    (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_reg))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_stop_dbg_write_shift       (1)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_fetch_dbg_entry_write_shift (0)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_stop_dbg_write_mask        (0x00000002)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_fetch_dbg_entry_write_mask (0x00000001)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_stop_dbg_write(data)       (0x00000002&((data)<<1))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_fetch_dbg_entry_write(data) (0x00000001&(data))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_get_stop_dbg_write(data)   ((0x00000002&(data))>>1)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_ctrl1_get_fetch_dbg_entry_write(data) (0x00000001&(data))

#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status1                          0x1814E080
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status1_reg_addr                 "0xB814E080"
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status1_reg                      0xB814E080
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status1_inst_addr                "0x000F"
#define  set_HDIC_REGISTER_BUS_hdic_mem_debug_write_status1_reg(data)            (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_debug_write_status1_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_mem_debug_write_status1_reg                  (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_debug_write_status1_reg))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status1_valid_entry_cnt_write_shift (0)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status1_valid_entry_cnt_write_mask (0x0000001F)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status1_valid_entry_cnt_write(data) (0x0000001F&(data))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status1_get_valid_entry_cnt_write(data) (0x0000001F&(data))

#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status2                          0x1814E084
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_reg_addr                 "0xB814E084"
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_reg                      0xB814E084
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_inst_addr                "0x0010"
#define  set_HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_reg(data)            (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_reg                  (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_reg))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_dbg_entry_axi_id_write_shift (26)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_dbg_entry_axi_addr_write_shift (0)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_dbg_entry_axi_id_write_mask (0x3C000000)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_dbg_entry_axi_addr_write_mask (0x03FFFFFF)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_dbg_entry_axi_id_write(data) (0x3C000000&((data)<<26))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_dbg_entry_axi_addr_write(data) (0x03FFFFFF&(data))
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_get_dbg_entry_axi_id_write(data) ((0x3C000000&(data))>>26)
#define  HDIC_REGISTER_BUS_hdic_mem_debug_write_status2_get_dbg_entry_axi_addr_write(data) (0x03FFFFFF&(data))

#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup                               0x1814E100
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup_reg_addr                      "0xB814E100"
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup_reg                           0xB814E100
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup_inst_addr                     "0x0011"
#define  set_HDIC_REGISTER_BUS_hdic_bus_wrapper_backup_reg(data)                 (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_bus_wrapper_backup_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_bus_wrapper_backup_reg                       (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_bus_wrapper_backup_reg))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup_eco_rw_shift                  (0)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup_eco_rw_mask                   (0xFFFFFFFF)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup_eco_rw(data)                  (0xFFFFFFFF&(data))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup_get_eco_rw(data)              (0xFFFFFFFF&(data))

#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup2                              0x1814E104
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup2_reg_addr                     "0xB814E104"
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup2_reg                          0xB814E104
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup2_inst_addr                    "0x0012"
#define  set_HDIC_REGISTER_BUS_hdic_bus_wrapper_backup2_reg(data)                (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_bus_wrapper_backup2_reg)=data)
#define  get_HDIC_REGISTER_BUS_hdic_bus_wrapper_backup2_reg                      (*((volatile unsigned int*)HDIC_REGISTER_BUS_hdic_bus_wrapper_backup2_reg))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup2_eco_rw_2_shift               (0)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup2_eco_rw_2_mask                (0xFFFFFFFF)
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup2_eco_rw_2(data)               (0xFFFFFFFF&(data))
#define  HDIC_REGISTER_BUS_hdic_bus_wrapper_backup2_get_eco_rw_2(data)           (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======HDIC_REGISTER_BUS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  remain_dc_cnt:5;
        RBus_UInt32  res2:15;
        RBus_UInt32  hdic_wrapper_soft_reset:1;
    };
}hdic_register_bus_hdic_bus_soft_reset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  res3:11;
        RBus_UInt32  hdic_wrapper_endian_swap:1;
        RBus_UInt32  hdic_wrapper_force_write_bufferable:1;
        RBus_UInt32  hdic_wrapper_in_order_mode:1;
        RBus_UInt32  hdic_wrapper_rw_arbitration:2;
    };
}hdic_register_bus_hdic_mem_bus_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  hdic_wrapper_rd_outstand_num:5;
        RBus_UInt32  res2:11;
        RBus_UInt32  hdic_wrapper_wr_outstand_num:5;
    };
}hdic_register_bus_hdic_mem_bus_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdic_wrapper_addr_base:32;
    };
}hdic_register_bus_hdic_mem_bus_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  hdic_wrapper_rd_outstand_cnt:5;
        RBus_UInt32  res2:11;
        RBus_UInt32  hdic_wrapper_wr_outstand_cnt:5;
    };
}hdic_register_bus_hdic_mem_bus_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  hdic_wrapper_bist_mode:1;
        RBus_UInt32  hdic_wrapper_bist_done:1;
        RBus_UInt32  hdic_wrapper_bist_fail_0:1;
        RBus_UInt32  hdic_wrapper_bist_fail_1:1;
    };
}hdic_register_bus_hdic_bus_wrapper_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  hdic_wrapper_drf_bist_mode:1;
        RBus_UInt32  hdic_wrapper_drf_test_resume:1;
        RBus_UInt32  hdic_wrapper_drf_start_pause:1;
        RBus_UInt32  hdic_wrapper_drf_bist_done:1;
        RBus_UInt32  hdic_wrapper_drf_bist_fail_0:1;
        RBus_UInt32  hdic_wrapper_drf_bist_fail_1:1;
    };
}hdic_register_bus_hdic_bus_wrapper_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rma_0:4;
        RBus_UInt32  rmb_0:4;
        RBus_UInt32  rma_1:4;
        RBus_UInt32  rmb_1:4;
        RBus_UInt32  res1:10;
        RBus_UInt32  ls_0:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  rmea_0:1;
        RBus_UInt32  rmeb_0:1;
        RBus_UInt32  rmea_1:1;
        RBus_UInt32  rmeb_1:1;
    };
}hdic_register_bus_hdic_bus_wrapper_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_hdic_dvs:4;
        RBus_UInt32  res1:26;
        RBus_UInt32  mbist_hdic_ls:1;
        RBus_UInt32  mbist_hdic_dvse:1;
    };
}hdic_register_bus_hdic_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  hdic_dtmb_dbg_sw:2;
    };
}hdic_register_bus_hdic_ip_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  rdata_buf_full:1;
        RBus_UInt32  rdata_buf_empty:1;
        RBus_UInt32  wdata_buf_full:1;
        RBus_UInt32  wdata_buf_empty:1;
        RBus_UInt32  axi_bid_fifo_full:1;
        RBus_UInt32  axi_bid_fifo_empty:1;
        RBus_UInt32  axi_wcmd_fifo_full:1;
        RBus_UInt32  axi_wcmd_fifo_empty:1;
        RBus_UInt32  axi_wdata_fifo_full:1;
        RBus_UInt32  axi_wdata_fifo_empty:1;
        RBus_UInt32  axi_wdata_phase_queue_full:1;
        RBus_UInt32  axi_wdata_phase_queue_empty:1;
        RBus_UInt32  dc_wcmd_async_fifo_full:1;
        RBus_UInt32  dc_wcmd_async_fifo_empty:1;
        RBus_UInt32  dc_wdata_async_fifo_full:1;
        RBus_UInt32  dc_wdata_async_fifo_empty:1;
        RBus_UInt32  dc_wlast_async_fifo_full:1;
        RBus_UInt32  dc_wlast_async_fifo_empty:1;
        RBus_UInt32  axi_rcmd_fifo_full:1;
        RBus_UInt32  axi_rcmd_fifo_empty:1;
        RBus_UInt32  axi_rdata_phase_queue_full:1;
        RBus_UInt32  axi_rdata_phase_queue_empty:1;
        RBus_UInt32  axi_rdata_fifo_full:1;
        RBus_UInt32  axi_rdata_fifo_empty:1;
        RBus_UInt32  dc_rcmd_async_fifo_full:1;
        RBus_UInt32  dc_rcmd_async_fifo_empty:1;
        RBus_UInt32  dc_rdata_async_fifo_full:1;
        RBus_UInt32  dc_rdata_async_fifo_empty:1;
    };
}hdic_register_bus_hdic_mem_bus_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  stop_dbg_read:1;
        RBus_UInt32  fetch_dbg_entry_read:1;
    };
}hdic_register_bus_hdic_mem_debug_read_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  valid_entry_cnt_read:5;
    };
}hdic_register_bus_hdic_mem_debug_read_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dbg_entry_axi_id_read:4;
        RBus_UInt32  dbg_entry_axi_addr_read:26;
    };
}hdic_register_bus_hdic_mem_debug_read_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  stop_dbg_write:1;
        RBus_UInt32  fetch_dbg_entry_write:1;
    };
}hdic_register_bus_hdic_mem_debug_write_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  valid_entry_cnt_write:5;
    };
}hdic_register_bus_hdic_mem_debug_write_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dbg_entry_axi_id_write:4;
        RBus_UInt32  dbg_entry_axi_addr_write:26;
    };
}hdic_register_bus_hdic_mem_debug_write_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_rw:32;
    };
}hdic_register_bus_hdic_bus_wrapper_backup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_rw_2:32;
    };
}hdic_register_bus_hdic_bus_wrapper_backup2_RBUS;

#else //apply LITTLE_ENDIAN

//======HDIC_REGISTER_BUS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdic_wrapper_soft_reset:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  remain_dc_cnt:5;
        RBus_UInt32  res2:11;
    };
}hdic_register_bus_hdic_bus_soft_reset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdic_wrapper_rw_arbitration:2;
        RBus_UInt32  hdic_wrapper_in_order_mode:1;
        RBus_UInt32  hdic_wrapper_force_write_bufferable:1;
        RBus_UInt32  hdic_wrapper_endian_swap:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  res2:6;
        RBus_UInt32  res3:10;
    };
}hdic_register_bus_hdic_mem_bus_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdic_wrapper_wr_outstand_num:5;
        RBus_UInt32  res1:11;
        RBus_UInt32  hdic_wrapper_rd_outstand_num:5;
        RBus_UInt32  res2:11;
    };
}hdic_register_bus_hdic_mem_bus_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdic_wrapper_addr_base:32;
    };
}hdic_register_bus_hdic_mem_bus_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdic_wrapper_wr_outstand_cnt:5;
        RBus_UInt32  res1:11;
        RBus_UInt32  hdic_wrapper_rd_outstand_cnt:5;
        RBus_UInt32  res2:11;
    };
}hdic_register_bus_hdic_mem_bus_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdic_wrapper_bist_fail_1:1;
        RBus_UInt32  hdic_wrapper_bist_fail_0:1;
        RBus_UInt32  hdic_wrapper_bist_done:1;
        RBus_UInt32  hdic_wrapper_bist_mode:1;
        RBus_UInt32  res1:28;
    };
}hdic_register_bus_hdic_bus_wrapper_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdic_wrapper_drf_bist_fail_1:1;
        RBus_UInt32  hdic_wrapper_drf_bist_fail_0:1;
        RBus_UInt32  hdic_wrapper_drf_bist_done:1;
        RBus_UInt32  hdic_wrapper_drf_start_pause:1;
        RBus_UInt32  hdic_wrapper_drf_test_resume:1;
        RBus_UInt32  hdic_wrapper_drf_bist_mode:1;
        RBus_UInt32  res1:26;
    };
}hdic_register_bus_hdic_bus_wrapper_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rmeb_1:1;
        RBus_UInt32  rmea_1:1;
        RBus_UInt32  rmeb_0:1;
        RBus_UInt32  rmea_0:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  ls_0:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  rmb_1:4;
        RBus_UInt32  rma_1:4;
        RBus_UInt32  rmb_0:4;
        RBus_UInt32  rma_0:4;
    };
}hdic_register_bus_hdic_bus_wrapper_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_hdic_dvse:1;
        RBus_UInt32  mbist_hdic_ls:1;
        RBus_UInt32  res1:26;
        RBus_UInt32  mbist_hdic_dvs:4;
    };
}hdic_register_bus_hdic_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdic_dtmb_dbg_sw:2;
        RBus_UInt32  res1:30;
    };
}hdic_register_bus_hdic_ip_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_rdata_async_fifo_empty:1;
        RBus_UInt32  dc_rdata_async_fifo_full:1;
        RBus_UInt32  dc_rcmd_async_fifo_empty:1;
        RBus_UInt32  dc_rcmd_async_fifo_full:1;
        RBus_UInt32  axi_rdata_fifo_empty:1;
        RBus_UInt32  axi_rdata_fifo_full:1;
        RBus_UInt32  axi_rdata_phase_queue_empty:1;
        RBus_UInt32  axi_rdata_phase_queue_full:1;
        RBus_UInt32  axi_rcmd_fifo_empty:1;
        RBus_UInt32  axi_rcmd_fifo_full:1;
        RBus_UInt32  dc_wlast_async_fifo_empty:1;
        RBus_UInt32  dc_wlast_async_fifo_full:1;
        RBus_UInt32  dc_wdata_async_fifo_empty:1;
        RBus_UInt32  dc_wdata_async_fifo_full:1;
        RBus_UInt32  dc_wcmd_async_fifo_empty:1;
        RBus_UInt32  dc_wcmd_async_fifo_full:1;
        RBus_UInt32  axi_wdata_phase_queue_empty:1;
        RBus_UInt32  axi_wdata_phase_queue_full:1;
        RBus_UInt32  axi_wdata_fifo_empty:1;
        RBus_UInt32  axi_wdata_fifo_full:1;
        RBus_UInt32  axi_wcmd_fifo_empty:1;
        RBus_UInt32  axi_wcmd_fifo_full:1;
        RBus_UInt32  axi_bid_fifo_empty:1;
        RBus_UInt32  axi_bid_fifo_full:1;
        RBus_UInt32  wdata_buf_empty:1;
        RBus_UInt32  wdata_buf_full:1;
        RBus_UInt32  rdata_buf_empty:1;
        RBus_UInt32  rdata_buf_full:1;
        RBus_UInt32  res1:4;
    };
}hdic_register_bus_hdic_mem_bus_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fetch_dbg_entry_read:1;
        RBus_UInt32  stop_dbg_read:1;
        RBus_UInt32  res1:30;
    };
}hdic_register_bus_hdic_mem_debug_read_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  valid_entry_cnt_read:5;
        RBus_UInt32  res1:27;
    };
}hdic_register_bus_hdic_mem_debug_read_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_entry_axi_addr_read:26;
        RBus_UInt32  dbg_entry_axi_id_read:4;
        RBus_UInt32  res1:2;
    };
}hdic_register_bus_hdic_mem_debug_read_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fetch_dbg_entry_write:1;
        RBus_UInt32  stop_dbg_write:1;
        RBus_UInt32  res1:30;
    };
}hdic_register_bus_hdic_mem_debug_write_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  valid_entry_cnt_write:5;
        RBus_UInt32  res1:27;
    };
}hdic_register_bus_hdic_mem_debug_write_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_entry_axi_addr_write:26;
        RBus_UInt32  dbg_entry_axi_id_write:4;
        RBus_UInt32  res1:2;
    };
}hdic_register_bus_hdic_mem_debug_write_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_rw:32;
    };
}hdic_register_bus_hdic_bus_wrapper_backup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_rw_2:32;
    };
}hdic_register_bus_hdic_bus_wrapper_backup2_RBUS;




#endif 


#endif 
