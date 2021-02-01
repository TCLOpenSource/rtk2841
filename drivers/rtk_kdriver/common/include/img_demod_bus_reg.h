/**
* @file rbusIMG_DEMOD_BUSReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IMG_DEMOD_BUS_REG_H_
#define _RBUS_IMG_DEMOD_BUS_REG_H_

#include "rbus_types.h"



//  IMG_DEMOD_BUS Register Address
#define  IMG_DEMOD_BUS_img_bus_soft_reset                                        0x18072000
#define  IMG_DEMOD_BUS_img_bus_soft_reset_reg_addr                               "0xB8072000"
#define  IMG_DEMOD_BUS_img_bus_soft_reset_reg                                    0xB8072000
#define  IMG_DEMOD_BUS_img_bus_soft_reset_inst_addr                              "0x0000"
#define  set_IMG_DEMOD_BUS_img_bus_soft_reset_reg(data)                          (*((volatile unsigned int*)IMG_DEMOD_BUS_img_bus_soft_reset_reg)=data)
#define  get_IMG_DEMOD_BUS_img_bus_soft_reset_reg                                (*((volatile unsigned int*)IMG_DEMOD_BUS_img_bus_soft_reset_reg))
#define  IMG_DEMOD_BUS_img_bus_soft_reset_remain_dc_cnt_shift                    (16)
#define  IMG_DEMOD_BUS_img_bus_soft_reset_dw_soft_reset_shift                    (0)
#define  IMG_DEMOD_BUS_img_bus_soft_reset_remain_dc_cnt_mask                     (0x001F0000)
#define  IMG_DEMOD_BUS_img_bus_soft_reset_dw_soft_reset_mask                     (0x00000001)
#define  IMG_DEMOD_BUS_img_bus_soft_reset_remain_dc_cnt(data)                    (0x001F0000&((data)<<16))
#define  IMG_DEMOD_BUS_img_bus_soft_reset_dw_soft_reset(data)                    (0x00000001&(data))
#define  IMG_DEMOD_BUS_img_bus_soft_reset_get_remain_dc_cnt(data)                ((0x001F0000&(data))>>16)
#define  IMG_DEMOD_BUS_img_bus_soft_reset_get_dw_soft_reset(data)                (0x00000001&(data))

#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1                                         0x18072004
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_reg_addr                                "0xB8072004"
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_reg                                     0xB8072004
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_inst_addr                               "0x0001"
#define  set_IMG_DEMOD_BUS_img_mem_bus_ctrl1_reg(data)                           (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_bus_ctrl1_reg)=data)
#define  get_IMG_DEMOD_BUS_img_mem_bus_ctrl1_reg                                 (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_bus_ctrl1_reg))
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_dw_endian_swap_shift                    (4)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_dw_force_write_bufferable_shift         (3)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_dw_in_order_mode_shift                  (2)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_dw_rw_arbitration_shift                 (0)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_dw_endian_swap_mask                     (0x00000010)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_dw_force_write_bufferable_mask          (0x00000008)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_dw_in_order_mode_mask                   (0x00000004)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_dw_rw_arbitration_mask                  (0x00000003)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_dw_endian_swap(data)                    (0x00000010&((data)<<4))
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_dw_force_write_bufferable(data)         (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_dw_in_order_mode(data)                  (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_dw_rw_arbitration(data)                 (0x00000003&(data))
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_get_dw_endian_swap(data)                ((0x00000010&(data))>>4)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_get_dw_force_write_bufferable(data)     ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_get_dw_in_order_mode(data)              ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl1_get_dw_rw_arbitration(data)             (0x00000003&(data))

#define  IMG_DEMOD_BUS_img_mem_bus_ctrl3                                         0x1807200C
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl3_reg_addr                                "0xB807200C"
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl3_reg                                     0xB807200C
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl3_inst_addr                               "0x0002"
#define  set_IMG_DEMOD_BUS_img_mem_bus_ctrl3_reg(data)                           (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_bus_ctrl3_reg)=data)
#define  get_IMG_DEMOD_BUS_img_mem_bus_ctrl3_reg                                 (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_bus_ctrl3_reg))
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl3_dw_rd_outstand_num_shift                (16)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl3_dw_wr_outstand_num_shift                (0)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl3_dw_rd_outstand_num_mask                 (0x001F0000)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl3_dw_wr_outstand_num_mask                 (0x0000001F)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl3_dw_rd_outstand_num(data)                (0x001F0000&((data)<<16))
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl3_dw_wr_outstand_num(data)                (0x0000001F&(data))
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl3_get_dw_rd_outstand_num(data)            ((0x001F0000&(data))>>16)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl3_get_dw_wr_outstand_num(data)            (0x0000001F&(data))

#define  IMG_DEMOD_BUS_img_mem_bus_ctrl4                                         0x18072010
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl4_reg_addr                                "0xB8072010"
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl4_reg                                     0xB8072010
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl4_inst_addr                               "0x0003"
#define  set_IMG_DEMOD_BUS_img_mem_bus_ctrl4_reg(data)                           (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_bus_ctrl4_reg)=data)
#define  get_IMG_DEMOD_BUS_img_mem_bus_ctrl4_reg                                 (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_bus_ctrl4_reg))
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl4_mem_addr_base_shift                     (0)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl4_mem_addr_base_mask                      (0xFFFFFFFF)
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl4_mem_addr_base(data)                     (0xFFFFFFFF&(data))
#define  IMG_DEMOD_BUS_img_mem_bus_ctrl4_get_mem_addr_base(data)                 (0xFFFFFFFF&(data))

#define  IMG_DEMOD_BUS_img_mem_bus_status1                                       0x18072014
#define  IMG_DEMOD_BUS_img_mem_bus_status1_reg_addr                              "0xB8072014"
#define  IMG_DEMOD_BUS_img_mem_bus_status1_reg                                   0xB8072014
#define  IMG_DEMOD_BUS_img_mem_bus_status1_inst_addr                             "0x0004"
#define  set_IMG_DEMOD_BUS_img_mem_bus_status1_reg(data)                         (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_bus_status1_reg)=data)
#define  get_IMG_DEMOD_BUS_img_mem_bus_status1_reg                               (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_bus_status1_reg))
#define  IMG_DEMOD_BUS_img_mem_bus_status1_dw_rd_outstand_cnt_shift              (16)
#define  IMG_DEMOD_BUS_img_mem_bus_status1_dw_wr_outstand_cnt_shift              (0)
#define  IMG_DEMOD_BUS_img_mem_bus_status1_dw_rd_outstand_cnt_mask               (0x001F0000)
#define  IMG_DEMOD_BUS_img_mem_bus_status1_dw_wr_outstand_cnt_mask               (0x0000001F)
#define  IMG_DEMOD_BUS_img_mem_bus_status1_dw_rd_outstand_cnt(data)              (0x001F0000&((data)<<16))
#define  IMG_DEMOD_BUS_img_mem_bus_status1_dw_wr_outstand_cnt(data)              (0x0000001F&(data))
#define  IMG_DEMOD_BUS_img_mem_bus_status1_get_dw_rd_outstand_cnt(data)          ((0x001F0000&(data))>>16)
#define  IMG_DEMOD_BUS_img_mem_bus_status1_get_dw_wr_outstand_cnt(data)          (0x0000001F&(data))

#define  IMG_DEMOD_BUS_img_host_sys_bus_ctrl1                                    0x18072020
#define  IMG_DEMOD_BUS_img_host_sys_bus_ctrl1_reg_addr                           "0xB8072020"
#define  IMG_DEMOD_BUS_img_host_sys_bus_ctrl1_reg                                0xB8072020
#define  IMG_DEMOD_BUS_img_host_sys_bus_ctrl1_inst_addr                          "0x0005"
#define  set_IMG_DEMOD_BUS_img_host_sys_bus_ctrl1_reg(data)                      (*((volatile unsigned int*)IMG_DEMOD_BUS_img_host_sys_bus_ctrl1_reg)=data)
#define  get_IMG_DEMOD_BUS_img_host_sys_bus_ctrl1_reg                            (*((volatile unsigned int*)IMG_DEMOD_BUS_img_host_sys_bus_ctrl1_reg))
#define  IMG_DEMOD_BUS_img_host_sys_bus_ctrl1_host_sys_bus_addr_31_18_shift      (18)
#define  IMG_DEMOD_BUS_img_host_sys_bus_ctrl1_host_sys_bus_addr_31_18_mask       (0xFFFC0000)
#define  IMG_DEMOD_BUS_img_host_sys_bus_ctrl1_host_sys_bus_addr_31_18(data)      (0xFFFC0000&((data)<<18))
#define  IMG_DEMOD_BUS_img_host_sys_bus_ctrl1_get_host_sys_bus_addr_31_18(data)  ((0xFFFC0000&(data))>>18)

#define  IMG_DEMOD_BUS_img_ext_sys_bus_ctrl1                                     0x18072040
#define  IMG_DEMOD_BUS_img_ext_sys_bus_ctrl1_reg_addr                            "0xB8072040"
#define  IMG_DEMOD_BUS_img_ext_sys_bus_ctrl1_reg                                 0xB8072040
#define  IMG_DEMOD_BUS_img_ext_sys_bus_ctrl1_inst_addr                           "0x0006"
#define  set_IMG_DEMOD_BUS_img_ext_sys_bus_ctrl1_reg(data)                       (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ext_sys_bus_ctrl1_reg)=data)
#define  get_IMG_DEMOD_BUS_img_ext_sys_bus_ctrl1_reg                             (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ext_sys_bus_ctrl1_reg))
#define  IMG_DEMOD_BUS_img_ext_sys_bus_ctrl1_ext_sys_addr_31_12_shift            (12)
#define  IMG_DEMOD_BUS_img_ext_sys_bus_ctrl1_ext_sys_addr_31_12_mask             (0xFFFFF000)
#define  IMG_DEMOD_BUS_img_ext_sys_bus_ctrl1_ext_sys_addr_31_12(data)            (0xFFFFF000&((data)<<12))
#define  IMG_DEMOD_BUS_img_ext_sys_bus_ctrl1_get_ext_sys_addr_31_12(data)        ((0xFFFFF000&(data))>>12)

#define  IMG_DEMOD_BUS_img_bus_wrapper_bist                                      0x18072050
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_reg_addr                             "0xB8072050"
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_reg                                  0xB8072050
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_inst_addr                            "0x0007"
#define  set_IMG_DEMOD_BUS_img_bus_wrapper_bist_reg(data)                        (*((volatile unsigned int*)IMG_DEMOD_BUS_img_bus_wrapper_bist_reg)=data)
#define  get_IMG_DEMOD_BUS_img_bus_wrapper_bist_reg                              (*((volatile unsigned int*)IMG_DEMOD_BUS_img_bus_wrapper_bist_reg))
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_demod_wrapper_bist_mode_shift        (3)
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_demod_wrapper_bist_done_shift        (2)
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_demod_wrapper_bist_fail_0_shift      (1)
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_demod_wrapper_bist_fail_1_shift      (0)
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_demod_wrapper_bist_mode_mask         (0x00000008)
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_demod_wrapper_bist_done_mask         (0x00000004)
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_demod_wrapper_bist_fail_0_mask       (0x00000002)
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_demod_wrapper_bist_fail_1_mask       (0x00000001)
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_demod_wrapper_bist_mode(data)        (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_demod_wrapper_bist_done(data)        (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_demod_wrapper_bist_fail_0(data)      (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_demod_wrapper_bist_fail_1(data)      (0x00000001&(data))
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_get_demod_wrapper_bist_mode(data)    ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_get_demod_wrapper_bist_done(data)    ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_get_demod_wrapper_bist_fail_0(data)  ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_img_bus_wrapper_bist_get_demod_wrapper_bist_fail_1(data)  (0x00000001&(data))

#define  IMG_DEMOD_BUS_img_bus_wrapper_drf                                       0x18072054
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_reg_addr                              "0xB8072054"
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_reg                                   0xB8072054
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_inst_addr                             "0x0008"
#define  set_IMG_DEMOD_BUS_img_bus_wrapper_drf_reg(data)                         (*((volatile unsigned int*)IMG_DEMOD_BUS_img_bus_wrapper_drf_reg)=data)
#define  get_IMG_DEMOD_BUS_img_bus_wrapper_drf_reg                               (*((volatile unsigned int*)IMG_DEMOD_BUS_img_bus_wrapper_drf_reg))
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_bist_mode_shift     (5)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_test_resume_shift   (4)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_start_pause_shift   (3)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_bist_done_shift     (2)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_bist_fail_0_shift   (1)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_bist_fail_1_shift   (0)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_bist_mode_mask      (0x00000020)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_test_resume_mask    (0x00000010)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_start_pause_mask    (0x00000008)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_bist_done_mask      (0x00000004)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_bist_fail_0_mask    (0x00000002)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_bist_fail_1_mask    (0x00000001)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_bist_mode(data)     (0x00000020&((data)<<5))
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_test_resume(data)   (0x00000010&((data)<<4))
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_start_pause(data)   (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_bist_done(data)     (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_bist_fail_0(data)   (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_demod_wrapper_drf_bist_fail_1(data)   (0x00000001&(data))
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_get_demod_wrapper_drf_bist_mode(data) ((0x00000020&(data))>>5)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_get_demod_wrapper_drf_test_resume(data) ((0x00000010&(data))>>4)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_get_demod_wrapper_drf_start_pause(data) ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_get_demod_wrapper_drf_bist_done(data) ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_get_demod_wrapper_drf_bist_fail_0(data) ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_img_bus_wrapper_drf_get_demod_wrapper_drf_bist_fail_1(data) (0x00000001&(data))

#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl                                 0x18072058
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_reg_addr                        "0xB8072058"
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_reg                             0xB8072058
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_inst_addr                       "0x0009"
#define  set_IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_reg(data)                   (*((volatile unsigned int*)IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_reg)=data)
#define  get_IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_reg                         (*((volatile unsigned int*)IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_reg))
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rma_0_shift                     (28)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmb_0_shift                     (24)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rma_1_shift                     (20)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmb_1_shift                     (16)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_ls_0_shift                      (5)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_ls_1_shift                      (4)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmea_0_shift                    (3)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmeb_0_shift                    (2)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmea_1_shift                    (1)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmeb_1_shift                    (0)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rma_0_mask                      (0xF0000000)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmb_0_mask                      (0x0F000000)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rma_1_mask                      (0x00F00000)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmb_1_mask                      (0x000F0000)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_ls_0_mask                       (0x00000020)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_ls_1_mask                       (0x00000010)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmea_0_mask                     (0x00000008)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmeb_0_mask                     (0x00000004)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmea_1_mask                     (0x00000002)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmeb_1_mask                     (0x00000001)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rma_0(data)                     (0xF0000000&((data)<<28))
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmb_0(data)                     (0x0F000000&((data)<<24))
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rma_1(data)                     (0x00F00000&((data)<<20))
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmb_1(data)                     (0x000F0000&((data)<<16))
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_ls_0(data)                      (0x00000020&((data)<<5))
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_ls_1(data)                      (0x00000010&((data)<<4))
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmea_0(data)                    (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmeb_0(data)                    (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmea_1(data)                    (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_rmeb_1(data)                    (0x00000001&(data))
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_get_rma_0(data)                 ((0xF0000000&(data))>>28)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_get_rmb_0(data)                 ((0x0F000000&(data))>>24)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_get_rma_1(data)                 ((0x00F00000&(data))>>20)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_get_rmb_1(data)                 ((0x000F0000&(data))>>16)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_get_ls_0(data)                  ((0x00000020&(data))>>5)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_get_ls_1(data)                  ((0x00000010&(data))>>4)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_get_rmea_0(data)                ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_get_rmeb_0(data)                ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_get_rmea_1(data)                ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_img_bus_wrapper_sram_ctrl_get_rmeb_1(data)                (0x00000001&(data))

#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status                                   0x18072060
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_reg_addr                          "0xB8072060"
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_reg                               0xB8072060
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_inst_addr                         "0x000A"
#define  set_IMG_DEMOD_BUS_img_mem_bus_fifo_status_reg(data)                     (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_bus_fifo_status_reg)=data)
#define  get_IMG_DEMOD_BUS_img_mem_bus_fifo_status_reg                           (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_bus_fifo_status_reg))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_rdata_buf_full_shift              (27)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_rdata_buf_empty_shift             (26)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_wdata_buf_full_shift              (25)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_wdata_buf_empty_shift             (24)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_bid_fifo_full_shift           (23)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_bid_fifo_empty_shift          (22)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wcmd_fifo_full_shift          (21)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wcmd_fifo_empty_shift         (20)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wdata_fifo_full_shift         (19)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wdata_fifo_empty_shift        (18)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wdata_phase_queue_full_shift  (17)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wdata_phase_queue_empty_shift (16)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wcmd_async_fifo_full_shift     (15)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wcmd_async_fifo_empty_shift    (14)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wdata_async_fifo_full_shift    (13)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wdata_async_fifo_empty_shift   (12)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wlast_async_fifo_full_shift    (11)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wlast_async_fifo_empty_shift   (10)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rcmd_fifo_full_shift          (9)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rcmd_fifo_empty_shift         (8)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rdata_phase_queue_full_shift  (7)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rdata_phase_queue_empty_shift (6)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rdata_fifo_full_shift         (5)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rdata_fifo_empty_shift        (4)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_rcmd_async_fifo_full_shift     (3)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_rcmd_async_fifo_empty_shift    (2)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_rdata_async_fifo_full_shift    (1)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_rdata_async_fifo_empty_shift   (0)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_rdata_buf_full_mask               (0x08000000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_rdata_buf_empty_mask              (0x04000000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_wdata_buf_full_mask               (0x02000000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_wdata_buf_empty_mask              (0x01000000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_bid_fifo_full_mask            (0x00800000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_bid_fifo_empty_mask           (0x00400000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wcmd_fifo_full_mask           (0x00200000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wcmd_fifo_empty_mask          (0x00100000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wdata_fifo_full_mask          (0x00080000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wdata_fifo_empty_mask         (0x00040000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wdata_phase_queue_full_mask   (0x00020000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wdata_phase_queue_empty_mask  (0x00010000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wcmd_async_fifo_full_mask      (0x00008000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wcmd_async_fifo_empty_mask     (0x00004000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wdata_async_fifo_full_mask     (0x00002000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wdata_async_fifo_empty_mask    (0x00001000)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wlast_async_fifo_full_mask     (0x00000800)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wlast_async_fifo_empty_mask    (0x00000400)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rcmd_fifo_full_mask           (0x00000200)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rcmd_fifo_empty_mask          (0x00000100)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rdata_phase_queue_full_mask   (0x00000080)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rdata_phase_queue_empty_mask  (0x00000040)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rdata_fifo_full_mask          (0x00000020)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rdata_fifo_empty_mask         (0x00000010)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_rcmd_async_fifo_full_mask      (0x00000008)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_rcmd_async_fifo_empty_mask     (0x00000004)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_rdata_async_fifo_full_mask     (0x00000002)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_rdata_async_fifo_empty_mask    (0x00000001)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_rdata_buf_full(data)              (0x08000000&((data)<<27))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_rdata_buf_empty(data)             (0x04000000&((data)<<26))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_wdata_buf_full(data)              (0x02000000&((data)<<25))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_wdata_buf_empty(data)             (0x01000000&((data)<<24))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_bid_fifo_full(data)           (0x00800000&((data)<<23))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_bid_fifo_empty(data)          (0x00400000&((data)<<22))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wcmd_fifo_full(data)          (0x00200000&((data)<<21))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wcmd_fifo_empty(data)         (0x00100000&((data)<<20))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wdata_fifo_full(data)         (0x00080000&((data)<<19))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wdata_fifo_empty(data)        (0x00040000&((data)<<18))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wdata_phase_queue_full(data)  (0x00020000&((data)<<17))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_wdata_phase_queue_empty(data) (0x00010000&((data)<<16))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wcmd_async_fifo_full(data)     (0x00008000&((data)<<15))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wcmd_async_fifo_empty(data)    (0x00004000&((data)<<14))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wdata_async_fifo_full(data)    (0x00002000&((data)<<13))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wdata_async_fifo_empty(data)   (0x00001000&((data)<<12))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wlast_async_fifo_full(data)    (0x00000800&((data)<<11))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_wlast_async_fifo_empty(data)   (0x00000400&((data)<<10))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rcmd_fifo_full(data)          (0x00000200&((data)<<9))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rcmd_fifo_empty(data)         (0x00000100&((data)<<8))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rdata_phase_queue_full(data)  (0x00000080&((data)<<7))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rdata_phase_queue_empty(data) (0x00000040&((data)<<6))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rdata_fifo_full(data)         (0x00000020&((data)<<5))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_axi_rdata_fifo_empty(data)        (0x00000010&((data)<<4))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_rcmd_async_fifo_full(data)     (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_rcmd_async_fifo_empty(data)    (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_rdata_async_fifo_full(data)    (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_dc_rdata_async_fifo_empty(data)   (0x00000001&(data))
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_rdata_buf_full(data)          ((0x08000000&(data))>>27)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_rdata_buf_empty(data)         ((0x04000000&(data))>>26)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_wdata_buf_full(data)          ((0x02000000&(data))>>25)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_wdata_buf_empty(data)         ((0x01000000&(data))>>24)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_bid_fifo_full(data)       ((0x00800000&(data))>>23)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_bid_fifo_empty(data)      ((0x00400000&(data))>>22)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_wcmd_fifo_full(data)      ((0x00200000&(data))>>21)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_wcmd_fifo_empty(data)     ((0x00100000&(data))>>20)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_wdata_fifo_full(data)     ((0x00080000&(data))>>19)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_wdata_fifo_empty(data)    ((0x00040000&(data))>>18)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_wdata_phase_queue_full(data) ((0x00020000&(data))>>17)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_wdata_phase_queue_empty(data) ((0x00010000&(data))>>16)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_dc_wcmd_async_fifo_full(data) ((0x00008000&(data))>>15)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_dc_wcmd_async_fifo_empty(data) ((0x00004000&(data))>>14)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_dc_wdata_async_fifo_full(data) ((0x00002000&(data))>>13)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_dc_wdata_async_fifo_empty(data) ((0x00001000&(data))>>12)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_dc_wlast_async_fifo_full(data) ((0x00000800&(data))>>11)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_dc_wlast_async_fifo_empty(data) ((0x00000400&(data))>>10)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_rcmd_fifo_full(data)      ((0x00000200&(data))>>9)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_rcmd_fifo_empty(data)     ((0x00000100&(data))>>8)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_rdata_phase_queue_full(data) ((0x00000080&(data))>>7)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_rdata_phase_queue_empty(data) ((0x00000040&(data))>>6)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_rdata_fifo_full(data)     ((0x00000020&(data))>>5)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_axi_rdata_fifo_empty(data)    ((0x00000010&(data))>>4)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_dc_rcmd_async_fifo_full(data) ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_dc_rcmd_async_fifo_empty(data) ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_dc_rdata_async_fifo_full(data) ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_img_mem_bus_fifo_status_get_dc_rdata_async_fifo_empty(data) (0x00000001&(data))

#define  IMG_DEMOD_BUS_img_mem_debug_read_ctrl1                                  0x18072070
#define  IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_reg_addr                         "0xB8072070"
#define  IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_reg                              0xB8072070
#define  IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_inst_addr                        "0x000B"
#define  set_IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_reg(data)                    (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_reg)=data)
#define  get_IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_reg                          (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_reg))
#define  IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_stop_dbg_read_shift              (1)
#define  IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_fetch_dbg_entry_read_shift       (0)
#define  IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_stop_dbg_read_mask               (0x00000002)
#define  IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_fetch_dbg_entry_read_mask        (0x00000001)
#define  IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_stop_dbg_read(data)              (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_fetch_dbg_entry_read(data)       (0x00000001&(data))
#define  IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_get_stop_dbg_read(data)          ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_img_mem_debug_read_ctrl1_get_fetch_dbg_entry_read(data)   (0x00000001&(data))

#define  IMG_DEMOD_BUS_img_mem_debug_read_status1                                0x18072074
#define  IMG_DEMOD_BUS_img_mem_debug_read_status1_reg_addr                       "0xB8072074"
#define  IMG_DEMOD_BUS_img_mem_debug_read_status1_reg                            0xB8072074
#define  IMG_DEMOD_BUS_img_mem_debug_read_status1_inst_addr                      "0x000C"
#define  set_IMG_DEMOD_BUS_img_mem_debug_read_status1_reg(data)                  (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_debug_read_status1_reg)=data)
#define  get_IMG_DEMOD_BUS_img_mem_debug_read_status1_reg                        (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_debug_read_status1_reg))
#define  IMG_DEMOD_BUS_img_mem_debug_read_status1_valid_entry_cnt_read_shift     (0)
#define  IMG_DEMOD_BUS_img_mem_debug_read_status1_valid_entry_cnt_read_mask      (0x0000001F)
#define  IMG_DEMOD_BUS_img_mem_debug_read_status1_valid_entry_cnt_read(data)     (0x0000001F&(data))
#define  IMG_DEMOD_BUS_img_mem_debug_read_status1_get_valid_entry_cnt_read(data) (0x0000001F&(data))

#define  IMG_DEMOD_BUS_img_mem_debug_read_status2                                0x18072078
#define  IMG_DEMOD_BUS_img_mem_debug_read_status2_reg_addr                       "0xB8072078"
#define  IMG_DEMOD_BUS_img_mem_debug_read_status2_reg                            0xB8072078
#define  IMG_DEMOD_BUS_img_mem_debug_read_status2_inst_addr                      "0x000D"
#define  set_IMG_DEMOD_BUS_img_mem_debug_read_status2_reg(data)                  (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_debug_read_status2_reg)=data)
#define  get_IMG_DEMOD_BUS_img_mem_debug_read_status2_reg                        (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_debug_read_status2_reg))
#define  IMG_DEMOD_BUS_img_mem_debug_read_status2_dbg_entry_axi_id_read_shift    (26)
#define  IMG_DEMOD_BUS_img_mem_debug_read_status2_dbg_entry_axi_addr_read_shift  (0)
#define  IMG_DEMOD_BUS_img_mem_debug_read_status2_dbg_entry_axi_id_read_mask     (0x04000000)
#define  IMG_DEMOD_BUS_img_mem_debug_read_status2_dbg_entry_axi_addr_read_mask   (0x03FFFFFF)
#define  IMG_DEMOD_BUS_img_mem_debug_read_status2_dbg_entry_axi_id_read(data)    (0x04000000&((data)<<26))
#define  IMG_DEMOD_BUS_img_mem_debug_read_status2_dbg_entry_axi_addr_read(data)  (0x03FFFFFF&(data))
#define  IMG_DEMOD_BUS_img_mem_debug_read_status2_get_dbg_entry_axi_id_read(data) ((0x04000000&(data))>>26)
#define  IMG_DEMOD_BUS_img_mem_debug_read_status2_get_dbg_entry_axi_addr_read(data) (0x03FFFFFF&(data))

#define  IMG_DEMOD_BUS_img_mem_debug_write_ctrl1                                 0x1807207C
#define  IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_reg_addr                        "0xB807207C"
#define  IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_reg                             0xB807207C
#define  IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_inst_addr                       "0x000E"
#define  set_IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_reg(data)                   (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_reg)=data)
#define  get_IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_reg                         (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_reg))
#define  IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_stop_dbg_write_shift            (1)
#define  IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_fetch_dbg_entry_write_shift     (0)
#define  IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_stop_dbg_write_mask             (0x00000002)
#define  IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_fetch_dbg_entry_write_mask      (0x00000001)
#define  IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_stop_dbg_write(data)            (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_fetch_dbg_entry_write(data)     (0x00000001&(data))
#define  IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_get_stop_dbg_write(data)        ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_img_mem_debug_write_ctrl1_get_fetch_dbg_entry_write(data) (0x00000001&(data))

#define  IMG_DEMOD_BUS_img_mem_debug_write_status1                               0x18072080
#define  IMG_DEMOD_BUS_img_mem_debug_write_status1_reg_addr                      "0xB8072080"
#define  IMG_DEMOD_BUS_img_mem_debug_write_status1_reg                           0xB8072080
#define  IMG_DEMOD_BUS_img_mem_debug_write_status1_inst_addr                     "0x000F"
#define  set_IMG_DEMOD_BUS_img_mem_debug_write_status1_reg(data)                 (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_debug_write_status1_reg)=data)
#define  get_IMG_DEMOD_BUS_img_mem_debug_write_status1_reg                       (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_debug_write_status1_reg))
#define  IMG_DEMOD_BUS_img_mem_debug_write_status1_valid_entry_cnt_write_shift   (0)
#define  IMG_DEMOD_BUS_img_mem_debug_write_status1_valid_entry_cnt_write_mask    (0x0000001F)
#define  IMG_DEMOD_BUS_img_mem_debug_write_status1_valid_entry_cnt_write(data)   (0x0000001F&(data))
#define  IMG_DEMOD_BUS_img_mem_debug_write_status1_get_valid_entry_cnt_write(data) (0x0000001F&(data))

#define  IMG_DEMOD_BUS_img_mem_debug_write_status2                               0x18072084
#define  IMG_DEMOD_BUS_img_mem_debug_write_status2_reg_addr                      "0xB8072084"
#define  IMG_DEMOD_BUS_img_mem_debug_write_status2_reg                           0xB8072084
#define  IMG_DEMOD_BUS_img_mem_debug_write_status2_inst_addr                     "0x0010"
#define  set_IMG_DEMOD_BUS_img_mem_debug_write_status2_reg(data)                 (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_debug_write_status2_reg)=data)
#define  get_IMG_DEMOD_BUS_img_mem_debug_write_status2_reg                       (*((volatile unsigned int*)IMG_DEMOD_BUS_img_mem_debug_write_status2_reg))
#define  IMG_DEMOD_BUS_img_mem_debug_write_status2_dbg_entry_axi_id_write_shift  (26)
#define  IMG_DEMOD_BUS_img_mem_debug_write_status2_dbg_entry_axi_addr_write_shift (0)
#define  IMG_DEMOD_BUS_img_mem_debug_write_status2_dbg_entry_axi_id_write_mask   (0x04000000)
#define  IMG_DEMOD_BUS_img_mem_debug_write_status2_dbg_entry_axi_addr_write_mask (0x03FFFFFF)
#define  IMG_DEMOD_BUS_img_mem_debug_write_status2_dbg_entry_axi_id_write(data)  (0x04000000&((data)<<26))
#define  IMG_DEMOD_BUS_img_mem_debug_write_status2_dbg_entry_axi_addr_write(data) (0x03FFFFFF&(data))
#define  IMG_DEMOD_BUS_img_mem_debug_write_status2_get_dbg_entry_axi_id_write(data) ((0x04000000&(data))>>26)
#define  IMG_DEMOD_BUS_img_mem_debug_write_status2_get_dbg_entry_axi_addr_write(data) (0x03FFFFFF&(data))

#define  IMG_DEMOD_BUS_img_bus_wrapper_backup                                    0x18072100
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup_reg_addr                           "0xB8072100"
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup_reg                                0xB8072100
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup_inst_addr                          "0x0011"
#define  set_IMG_DEMOD_BUS_img_bus_wrapper_backup_reg(data)                      (*((volatile unsigned int*)IMG_DEMOD_BUS_img_bus_wrapper_backup_reg)=data)
#define  get_IMG_DEMOD_BUS_img_bus_wrapper_backup_reg                            (*((volatile unsigned int*)IMG_DEMOD_BUS_img_bus_wrapper_backup_reg))
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup_eco_rw_shift                       (0)
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup_eco_rw_mask                        (0xFFFFFFFF)
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup_eco_rw(data)                       (0xFFFFFFFF&(data))
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup_get_eco_rw(data)                   (0xFFFFFFFF&(data))

#define  IMG_DEMOD_BUS_img_bus_wrapper_backup2                                   0x18072104
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup2_reg_addr                          "0xB8072104"
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup2_reg                               0xB8072104
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup2_inst_addr                         "0x0012"
#define  set_IMG_DEMOD_BUS_img_bus_wrapper_backup2_reg(data)                     (*((volatile unsigned int*)IMG_DEMOD_BUS_img_bus_wrapper_backup2_reg)=data)
#define  get_IMG_DEMOD_BUS_img_bus_wrapper_backup2_reg                           (*((volatile unsigned int*)IMG_DEMOD_BUS_img_bus_wrapper_backup2_reg))
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup2_eco_rw_2_shift                    (0)
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup2_eco_rw_2_mask                     (0xFFFFFFFF)
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup2_eco_rw_2(data)                    (0xFFFFFFFF&(data))
#define  IMG_DEMOD_BUS_img_bus_wrapper_backup2_get_eco_rw_2(data)                (0xFFFFFFFF&(data))

#define  IMG_DEMOD_BUS_img_ipcore_revision                                       0x18072108
#define  IMG_DEMOD_BUS_img_ipcore_revision_reg_addr                              "0xB8072108"
#define  IMG_DEMOD_BUS_img_ipcore_revision_reg                                   0xB8072108
#define  IMG_DEMOD_BUS_img_ipcore_revision_inst_addr                             "0x0013"
#define  set_IMG_DEMOD_BUS_img_ipcore_revision_reg(data)                         (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_revision_reg)=data)
#define  get_IMG_DEMOD_BUS_img_ipcore_revision_reg                               (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_revision_reg))
#define  IMG_DEMOD_BUS_img_ipcore_revision_designer_rev_shift                    (0)
#define  IMG_DEMOD_BUS_img_ipcore_revision_designer_rev_mask                     (0x000000FF)
#define  IMG_DEMOD_BUS_img_ipcore_revision_designer_rev(data)                    (0x000000FF&(data))
#define  IMG_DEMOD_BUS_img_ipcore_revision_get_designer_rev(data)                (0x000000FF&(data))

#define  IMG_DEMOD_BUS_img_ipcore_reset_cken                                     0x1807210C
#define  IMG_DEMOD_BUS_img_ipcore_reset_cken_reg_addr                            "0xB807210C"
#define  IMG_DEMOD_BUS_img_ipcore_reset_cken_reg                                 0xB807210C
#define  IMG_DEMOD_BUS_img_ipcore_reset_cken_inst_addr                           "0x0014"
#define  set_IMG_DEMOD_BUS_img_ipcore_reset_cken_reg(data)                       (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_reset_cken_reg)=data)
#define  get_IMG_DEMOD_BUS_img_ipcore_reset_cken_reg                             (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_reset_cken_reg))
#define  IMG_DEMOD_BUS_img_ipcore_reset_cken_sys_clk_enable_shift                (5)
#define  IMG_DEMOD_BUS_img_ipcore_reset_cken_sys_clk_enable_mask                 (0x00000020)
#define  IMG_DEMOD_BUS_img_ipcore_reset_cken_sys_clk_enable(data)                (0x00000020&((data)<<5))
#define  IMG_DEMOD_BUS_img_ipcore_reset_cken_get_sys_clk_enable(data)            ((0x00000020&(data))>>5)

#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1                                     0x18072110
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_reg_addr                            "0xB8072110"
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_reg                                 0xB8072110
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_inst_addr                           "0x0015"
#define  set_IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_reg(data)                       (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_reg)=data)
#define  get_IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_reg                             (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_reg))
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_jtag_sel_shift                      (4)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_trstn_shift                         (3)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_tms_shift                           (2)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_tdi_shift                           (1)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_tck_shift                           (0)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_jtag_sel_mask                       (0x00000030)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_trstn_mask                          (0x00000008)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_tms_mask                            (0x00000004)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_tdi_mask                            (0x00000002)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_tck_mask                            (0x00000001)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_jtag_sel(data)                      (0x00000030&((data)<<4))
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_trstn(data)                         (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_tms(data)                           (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_tdi(data)                           (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_tck(data)                           (0x00000001&(data))
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_get_jtag_sel(data)                  ((0x00000030&(data))>>4)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_get_trstn(data)                     ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_get_tms(data)                       ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_get_tdi(data)                       ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_ctrl1_get_tck(data)                       (0x00000001&(data))

#define  IMG_DEMOD_BUS_img_ipcore_jtag_status1                                   0x18072114
#define  IMG_DEMOD_BUS_img_ipcore_jtag_status1_reg_addr                          "0xB8072114"
#define  IMG_DEMOD_BUS_img_ipcore_jtag_status1_reg                               0xB8072114
#define  IMG_DEMOD_BUS_img_ipcore_jtag_status1_inst_addr                         "0x0016"
#define  set_IMG_DEMOD_BUS_img_ipcore_jtag_status1_reg(data)                     (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_jtag_status1_reg)=data)
#define  get_IMG_DEMOD_BUS_img_ipcore_jtag_status1_reg                           (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_jtag_status1_reg))
#define  IMG_DEMOD_BUS_img_ipcore_jtag_status1_tdo_shift                         (0)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_status1_tdo_mask                          (0x00000001)
#define  IMG_DEMOD_BUS_img_ipcore_jtag_status1_tdo(data)                         (0x00000001&(data))
#define  IMG_DEMOD_BUS_img_ipcore_jtag_status1_get_tdo(data)                     (0x00000001&(data))

#define  IMG_DEMOD_BUS_img_ipcore_irq_in_63_32                                   0x18072118
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_63_32_reg_addr                          "0xB8072118"
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_63_32_reg                               0xB8072118
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_63_32_inst_addr                         "0x0017"
#define  set_IMG_DEMOD_BUS_img_ipcore_irq_in_63_32_reg(data)                     (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_irq_in_63_32_reg)=data)
#define  get_IMG_DEMOD_BUS_img_ipcore_irq_in_63_32_reg                           (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_irq_in_63_32_reg))
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_63_32_ext_irq_i_63_32_shift             (0)
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_63_32_ext_irq_i_63_32_mask              (0xFFFFFFFF)
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_63_32_ext_irq_i_63_32(data)             (0xFFFFFFFF&(data))
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_63_32_get_ext_irq_i_63_32(data)         (0xFFFFFFFF&(data))

#define  IMG_DEMOD_BUS_img_ipcore_irq_in_31_0                                    0x1807211C
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_31_0_reg_addr                           "0xB807211C"
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_31_0_reg                                0xB807211C
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_31_0_inst_addr                          "0x0018"
#define  set_IMG_DEMOD_BUS_img_ipcore_irq_in_31_0_reg(data)                      (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_irq_in_31_0_reg)=data)
#define  get_IMG_DEMOD_BUS_img_ipcore_irq_in_31_0_reg                            (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_irq_in_31_0_reg))
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_31_0_ext_irq_i_31_0_shift               (0)
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_31_0_ext_irq_i_31_0_mask                (0xFFFFFFFF)
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_31_0_ext_irq_i_31_0(data)               (0xFFFFFFFF&(data))
#define  IMG_DEMOD_BUS_img_ipcore_irq_in_31_0_get_ext_irq_i_31_0(data)           (0xFFFFFFFF&(data))

#define  IMG_DEMOD_BUS_img_ipcore_metx_boot                                      0x18072120
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_reg_addr                             "0xB8072120"
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_reg                                  0xB8072120
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_inst_addr                            "0x0019"
#define  set_IMG_DEMOD_BUS_img_ipcore_metx_boot_reg(data)                        (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_metx_boot_reg)=data)
#define  get_IMG_DEMOD_BUS_img_ipcore_metx_boot_reg                              (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_metx_boot_reg))
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_boot_in_shift                   (7)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_boot_ready_shift                (6)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_boot_addr_shift                 (2)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_boot_minim_shift                (1)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_debug_reset_shift               (0)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_boot_in_mask                    (0x00000080)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_boot_ready_mask                 (0x00000040)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_boot_addr_mask                  (0x0000003C)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_boot_minim_mask                 (0x00000002)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_debug_reset_mask                (0x00000001)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_boot_in(data)                   (0x00000080&((data)<<7))
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_boot_ready(data)                (0x00000040&((data)<<6))
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_boot_addr(data)                 (0x0000003C&((data)<<2))
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_boot_minim(data)                (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_metx_debug_reset(data)               (0x00000001&(data))
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_get_metx_boot_in(data)               ((0x00000080&(data))>>7)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_get_metx_boot_ready(data)            ((0x00000040&(data))>>6)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_get_metx_boot_addr(data)             ((0x0000003C&(data))>>2)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_get_metx_boot_minim(data)            ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_img_ipcore_metx_boot_get_metx_debug_reset(data)           (0x00000001&(data))

#define  IMG_DEMOD_BUS_img_ipcore_gpio_in                                        0x18072124
#define  IMG_DEMOD_BUS_img_ipcore_gpio_in_reg_addr                               "0xB8072124"
#define  IMG_DEMOD_BUS_img_ipcore_gpio_in_reg                                    0xB8072124
#define  IMG_DEMOD_BUS_img_ipcore_gpio_in_inst_addr                              "0x001A"
#define  set_IMG_DEMOD_BUS_img_ipcore_gpio_in_reg(data)                          (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_gpio_in_reg)=data)
#define  get_IMG_DEMOD_BUS_img_ipcore_gpio_in_reg                                (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_gpio_in_reg))
#define  IMG_DEMOD_BUS_img_ipcore_gpio_in_gpio_in_shift                          (0)
#define  IMG_DEMOD_BUS_img_ipcore_gpio_in_gpio_in_mask                           (0xFFFFFFFF)
#define  IMG_DEMOD_BUS_img_ipcore_gpio_in_gpio_in(data)                          (0xFFFFFFFF&(data))
#define  IMG_DEMOD_BUS_img_ipcore_gpio_in_get_gpio_in(data)                      (0xFFFFFFFF&(data))

#define  IMG_DEMOD_BUS_img_ipcore_gpio_out                                       0x18072128
#define  IMG_DEMOD_BUS_img_ipcore_gpio_out_reg_addr                              "0xB8072128"
#define  IMG_DEMOD_BUS_img_ipcore_gpio_out_reg                                   0xB8072128
#define  IMG_DEMOD_BUS_img_ipcore_gpio_out_inst_addr                             "0x001B"
#define  set_IMG_DEMOD_BUS_img_ipcore_gpio_out_reg(data)                         (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_gpio_out_reg)=data)
#define  get_IMG_DEMOD_BUS_img_ipcore_gpio_out_reg                               (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_gpio_out_reg))
#define  IMG_DEMOD_BUS_img_ipcore_gpio_out_gpio_out_shift                        (0)
#define  IMG_DEMOD_BUS_img_ipcore_gpio_out_gpio_out_mask                         (0xFFFFFFFF)
#define  IMG_DEMOD_BUS_img_ipcore_gpio_out_gpio_out(data)                        (0xFFFFFFFF&(data))
#define  IMG_DEMOD_BUS_img_ipcore_gpio_out_get_gpio_out(data)                    (0xFFFFFFFF&(data))

#define  IMG_DEMOD_BUS_img_ipcore_dbg_is_slave                                   0x1807212C
#define  IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_reg_addr                          "0xB807212C"
#define  IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_reg                               0xB807212C
#define  IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_inst_addr                         "0x001C"
#define  set_IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_reg(data)                     (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_reg)=data)
#define  get_IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_reg                           (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_reg))
#define  IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_dbg_ucc_is_slave_shift            (1)
#define  IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_dbg_metx_is_slave_shift           (0)
#define  IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_dbg_ucc_is_slave_mask             (0x00000002)
#define  IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_dbg_metx_is_slave_mask            (0x00000001)
#define  IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_dbg_ucc_is_slave(data)            (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_dbg_metx_is_slave(data)           (0x00000001&(data))
#define  IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_get_dbg_ucc_is_slave(data)        ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_img_ipcore_dbg_is_slave_get_dbg_metx_is_slave(data)       (0x00000001&(data))

#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status                              0x18072138
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_reg_addr                     "0xB8072138"
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_reg                          0xB8072138
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_inst_addr                    "0x001D"
#define  set_IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_reg(data)                (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_reg)=data)
#define  get_IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_reg                      (*((volatile unsigned int*)IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_reg))
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_img_demod_irq_shift          (5)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_img_demod_irq_en_shift       (4)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_host_irq_shift               (3)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_host_irq_en_shift            (2)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_ext_opt_req_idle_shift       (1)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_ext_opt_mem_idle_shift       (0)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_img_demod_irq_mask           (0x00000020)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_img_demod_irq_en_mask        (0x00000010)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_host_irq_mask                (0x00000008)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_host_irq_en_mask             (0x00000004)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_ext_opt_req_idle_mask        (0x00000002)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_ext_opt_mem_idle_mask        (0x00000001)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_img_demod_irq(data)          (0x00000020&((data)<<5))
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_img_demod_irq_en(data)       (0x00000010&((data)<<4))
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_host_irq(data)               (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_host_irq_en(data)            (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_ext_opt_req_idle(data)       (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_ext_opt_mem_idle(data)       (0x00000001&(data))
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_get_img_demod_irq(data)      ((0x00000020&(data))>>5)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_get_img_demod_irq_en(data)   ((0x00000010&(data))>>4)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_get_host_irq(data)           ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_get_host_irq_en(data)        ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_get_ext_opt_req_idle(data)   ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_img_ipcore_ucc_irq_ip_status_get_ext_opt_mem_idle(data)   (0x00000001&(data))

#define  IMG_DEMOD_BUS_img_clkgen_reg                                            0x18072180
#define  IMG_DEMOD_BUS_img_clkgen_reg_reg_addr                                   "0xB8072180"
#define  IMG_DEMOD_BUS_img_clkgen_reg_reg                                        0xB8072180
#define  IMG_DEMOD_BUS_img_clkgen_reg_inst_addr                                  "0x001E"
#define  set_IMG_DEMOD_BUS_img_clkgen_reg_reg(data)                              (*((volatile unsigned int*)IMG_DEMOD_BUS_img_clkgen_reg_reg)=data)
#define  get_IMG_DEMOD_BUS_img_clkgen_reg_reg                                    (*((volatile unsigned int*)IMG_DEMOD_BUS_img_clkgen_reg_reg))
#define  IMG_DEMOD_BUS_img_clkgen_reg_demod_sel_shift                            (2)
#define  IMG_DEMOD_BUS_img_clkgen_reg_ifadc_sel_shift                            (1)
#define  IMG_DEMOD_BUS_img_clkgen_reg_oversample_sel_shift                       (0)
#define  IMG_DEMOD_BUS_img_clkgen_reg_demod_sel_mask                             (0x0000003C)
#define  IMG_DEMOD_BUS_img_clkgen_reg_ifadc_sel_mask                             (0x00000002)
#define  IMG_DEMOD_BUS_img_clkgen_reg_oversample_sel_mask                        (0x00000001)
#define  IMG_DEMOD_BUS_img_clkgen_reg_demod_sel(data)                            (0x0000003C&((data)<<2))
#define  IMG_DEMOD_BUS_img_clkgen_reg_ifadc_sel(data)                            (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_img_clkgen_reg_oversample_sel(data)                       (0x00000001&(data))
#define  IMG_DEMOD_BUS_img_clkgen_reg_get_demod_sel(data)                        ((0x0000003C&(data))>>2)
#define  IMG_DEMOD_BUS_img_clkgen_reg_get_ifadc_sel(data)                        ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_img_clkgen_reg_get_oversample_sel(data)                   (0x00000001&(data))

#define  IMG_DEMOD_BUS_debug                                                     0x18072200
#define  IMG_DEMOD_BUS_debug_reg_addr                                            "0xB8072200"
#define  IMG_DEMOD_BUS_debug_reg                                                 0xB8072200
#define  IMG_DEMOD_BUS_debug_inst_addr                                           "0x001F"
#define  set_IMG_DEMOD_BUS_debug_reg(data)                                       (*((volatile unsigned int*)IMG_DEMOD_BUS_debug_reg)=data)
#define  get_IMG_DEMOD_BUS_debug_reg                                             (*((volatile unsigned int*)IMG_DEMOD_BUS_debug_reg))
#define  IMG_DEMOD_BUS_debug_debug_sel_shift                                     (0)
#define  IMG_DEMOD_BUS_debug_debug_sel_mask                                      (0x0000000F)
#define  IMG_DEMOD_BUS_debug_debug_sel(data)                                     (0x0000000F&(data))
#define  IMG_DEMOD_BUS_debug_get_debug_sel(data)                                 (0x0000000F&(data))

#define  IMG_DEMOD_BUS_bisr_second_run_en                                        0x18072204
#define  IMG_DEMOD_BUS_bisr_second_run_en_reg_addr                               "0xB8072204"
#define  IMG_DEMOD_BUS_bisr_second_run_en_reg                                    0xB8072204
#define  IMG_DEMOD_BUS_bisr_second_run_en_inst_addr                              "0x0020"
#define  set_IMG_DEMOD_BUS_bisr_second_run_en_reg(data)                          (*((volatile unsigned int*)IMG_DEMOD_BUS_bisr_second_run_en_reg)=data)
#define  get_IMG_DEMOD_BUS_bisr_second_run_en_reg                                (*((volatile unsigned int*)IMG_DEMOD_BUS_bisr_second_run_en_reg))
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_5_second_run_en_shift   (5)
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_4_second_run_en_shift   (4)
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_3_second_run_en_shift   (3)
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_2_second_run_en_shift   (2)
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_1_second_run_en_shift   (1)
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_0_second_run_en_shift   (0)
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_5_second_run_en_mask    (0x00000020)
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_4_second_run_en_mask    (0x00000010)
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_3_second_run_en_mask    (0x00000008)
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_2_second_run_en_mask    (0x00000004)
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_1_second_run_en_mask    (0x00000002)
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_0_second_run_en_mask    (0x00000001)
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_5_second_run_en(data)   (0x00000020&((data)<<5))
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_4_second_run_en(data)   (0x00000010&((data)<<4))
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_3_second_run_en(data)   (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_2_second_run_en(data)   (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_1_second_run_en(data)   (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_bisr_second_run_en_img_demod_bisr_0_second_run_en(data)   (0x00000001&(data))
#define  IMG_DEMOD_BUS_bisr_second_run_en_get_img_demod_bisr_5_second_run_en(data) ((0x00000020&(data))>>5)
#define  IMG_DEMOD_BUS_bisr_second_run_en_get_img_demod_bisr_4_second_run_en(data) ((0x00000010&(data))>>4)
#define  IMG_DEMOD_BUS_bisr_second_run_en_get_img_demod_bisr_3_second_run_en(data) ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_bisr_second_run_en_get_img_demod_bisr_2_second_run_en(data) ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_bisr_second_run_en_get_img_demod_bisr_1_second_run_en(data) ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_bisr_second_run_en_get_img_demod_bisr_0_second_run_en(data) (0x00000001&(data))

#define  IMG_DEMOD_BUS_bisr_fail                                                 0x18072208
#define  IMG_DEMOD_BUS_bisr_fail_reg_addr                                        "0xB8072208"
#define  IMG_DEMOD_BUS_bisr_fail_reg                                             0xB8072208
#define  IMG_DEMOD_BUS_bisr_fail_inst_addr                                       "0x0021"
#define  set_IMG_DEMOD_BUS_bisr_fail_reg(data)                                   (*((volatile unsigned int*)IMG_DEMOD_BUS_bisr_fail_reg)=data)
#define  get_IMG_DEMOD_BUS_bisr_fail_reg                                         (*((volatile unsigned int*)IMG_DEMOD_BUS_bisr_fail_reg))
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_5_fail_shift                     (5)
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_4_fail_shift                     (4)
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_3_fail_shift                     (3)
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_2_fail_shift                     (2)
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_1_fail_shift                     (1)
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_0_fail_shift                     (0)
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_5_fail_mask                      (0x00000020)
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_4_fail_mask                      (0x00000010)
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_3_fail_mask                      (0x00000008)
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_2_fail_mask                      (0x00000004)
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_1_fail_mask                      (0x00000002)
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_0_fail_mask                      (0x00000001)
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_5_fail(data)                     (0x00000020&((data)<<5))
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_4_fail(data)                     (0x00000010&((data)<<4))
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_3_fail(data)                     (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_2_fail(data)                     (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_1_fail(data)                     (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_bisr_fail_img_demod_bisr_0_fail(data)                     (0x00000001&(data))
#define  IMG_DEMOD_BUS_bisr_fail_get_img_demod_bisr_5_fail(data)                 ((0x00000020&(data))>>5)
#define  IMG_DEMOD_BUS_bisr_fail_get_img_demod_bisr_4_fail(data)                 ((0x00000010&(data))>>4)
#define  IMG_DEMOD_BUS_bisr_fail_get_img_demod_bisr_3_fail(data)                 ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_bisr_fail_get_img_demod_bisr_2_fail(data)                 ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_bisr_fail_get_img_demod_bisr_1_fail(data)                 ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_bisr_fail_get_img_demod_bisr_0_fail(data)                 (0x00000001&(data))

#define  IMG_DEMOD_BUS_bisr_repaired                                             0x1807220C
#define  IMG_DEMOD_BUS_bisr_repaired_reg_addr                                    "0xB807220C"
#define  IMG_DEMOD_BUS_bisr_repaired_reg                                         0xB807220C
#define  IMG_DEMOD_BUS_bisr_repaired_inst_addr                                   "0x0022"
#define  set_IMG_DEMOD_BUS_bisr_repaired_reg(data)                               (*((volatile unsigned int*)IMG_DEMOD_BUS_bisr_repaired_reg)=data)
#define  get_IMG_DEMOD_BUS_bisr_repaired_reg                                     (*((volatile unsigned int*)IMG_DEMOD_BUS_bisr_repaired_reg))
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_5_repaired_shift             (5)
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_4_repaired_shift             (4)
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_3_repaired_shift             (3)
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_2_repaired_shift             (2)
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_1_repaired_shift             (1)
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_0_repaired_shift             (0)
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_5_repaired_mask              (0x00000020)
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_4_repaired_mask              (0x00000010)
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_3_repaired_mask              (0x00000008)
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_2_repaired_mask              (0x00000004)
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_1_repaired_mask              (0x00000002)
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_0_repaired_mask              (0x00000001)
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_5_repaired(data)             (0x00000020&((data)<<5))
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_4_repaired(data)             (0x00000010&((data)<<4))
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_3_repaired(data)             (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_2_repaired(data)             (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_1_repaired(data)             (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_bisr_repaired_img_demod_bisr_0_repaired(data)             (0x00000001&(data))
#define  IMG_DEMOD_BUS_bisr_repaired_get_img_demod_bisr_5_repaired(data)         ((0x00000020&(data))>>5)
#define  IMG_DEMOD_BUS_bisr_repaired_get_img_demod_bisr_4_repaired(data)         ((0x00000010&(data))>>4)
#define  IMG_DEMOD_BUS_bisr_repaired_get_img_demod_bisr_3_repaired(data)         ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_bisr_repaired_get_img_demod_bisr_2_repaired(data)         ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_bisr_repaired_get_img_demod_bisr_1_repaired(data)         ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_bisr_repaired_get_img_demod_bisr_0_repaired(data)         (0x00000001&(data))

#define  IMG_DEMOD_BUS_bisr_out                                                  0x18072210
#define  IMG_DEMOD_BUS_bisr_out_reg_addr                                         "0xB8072210"
#define  IMG_DEMOD_BUS_bisr_out_reg                                              0xB8072210
#define  IMG_DEMOD_BUS_bisr_out_inst_addr                                        "0x0023"
#define  set_IMG_DEMOD_BUS_bisr_out_reg(data)                                    (*((volatile unsigned int*)IMG_DEMOD_BUS_bisr_out_reg)=data)
#define  get_IMG_DEMOD_BUS_bisr_out_reg                                          (*((volatile unsigned int*)IMG_DEMOD_BUS_bisr_out_reg))
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_5_out_shift                       (25)
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_4_out_shift                       (20)
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_3_out_shift                       (15)
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_2_out_shift                       (10)
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_1_out_shift                       (5)
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_0_out_shift                       (0)
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_5_out_mask                        (0x3E000000)
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_4_out_mask                        (0x01F00000)
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_3_out_mask                        (0x000F8000)
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_2_out_mask                        (0x00007C00)
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_1_out_mask                        (0x000003E0)
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_0_out_mask                        (0x0000001F)
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_5_out(data)                       (0x3E000000&((data)<<25))
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_4_out(data)                       (0x01F00000&((data)<<20))
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_3_out(data)                       (0x000F8000&((data)<<15))
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_2_out(data)                       (0x00007C00&((data)<<10))
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_1_out(data)                       (0x000003E0&((data)<<5))
#define  IMG_DEMOD_BUS_bisr_out_img_demod_bisr_0_out(data)                       (0x0000001F&(data))
#define  IMG_DEMOD_BUS_bisr_out_get_img_demod_bisr_5_out(data)                   ((0x3E000000&(data))>>25)
#define  IMG_DEMOD_BUS_bisr_out_get_img_demod_bisr_4_out(data)                   ((0x01F00000&(data))>>20)
#define  IMG_DEMOD_BUS_bisr_out_get_img_demod_bisr_3_out(data)                   ((0x000F8000&(data))>>15)
#define  IMG_DEMOD_BUS_bisr_out_get_img_demod_bisr_2_out(data)                   ((0x00007C00&(data))>>10)
#define  IMG_DEMOD_BUS_bisr_out_get_img_demod_bisr_1_out(data)                   ((0x000003E0&(data))>>5)
#define  IMG_DEMOD_BUS_bisr_out_get_img_demod_bisr_0_out(data)                   (0x0000001F&(data))

#define  IMG_DEMOD_BUS_drf_bisr_mode                                             0x18072214
#define  IMG_DEMOD_BUS_drf_bisr_mode_reg_addr                                    "0xB8072214"
#define  IMG_DEMOD_BUS_drf_bisr_mode_reg                                         0xB8072214
#define  IMG_DEMOD_BUS_drf_bisr_mode_inst_addr                                   "0x0024"
#define  set_IMG_DEMOD_BUS_drf_bisr_mode_reg(data)                               (*((volatile unsigned int*)IMG_DEMOD_BUS_drf_bisr_mode_reg)=data)
#define  get_IMG_DEMOD_BUS_drf_bisr_mode_reg                                     (*((volatile unsigned int*)IMG_DEMOD_BUS_drf_bisr_mode_reg))
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_5_mode_shift             (5)
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_4_mode_shift             (4)
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_3_mode_shift             (3)
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_2_mode_shift             (2)
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_1_mode_shift             (1)
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_0_mode_shift             (0)
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_5_mode_mask              (0x00000020)
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_4_mode_mask              (0x00000010)
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_3_mode_mask              (0x00000008)
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_2_mode_mask              (0x00000004)
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_1_mode_mask              (0x00000002)
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_0_mode_mask              (0x00000001)
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_5_mode(data)             (0x00000020&((data)<<5))
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_4_mode(data)             (0x00000010&((data)<<4))
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_3_mode(data)             (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_2_mode(data)             (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_1_mode(data)             (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_drf_bisr_mode_img_demod_drf_bisr_0_mode(data)             (0x00000001&(data))
#define  IMG_DEMOD_BUS_drf_bisr_mode_get_img_demod_drf_bisr_5_mode(data)         ((0x00000020&(data))>>5)
#define  IMG_DEMOD_BUS_drf_bisr_mode_get_img_demod_drf_bisr_4_mode(data)         ((0x00000010&(data))>>4)
#define  IMG_DEMOD_BUS_drf_bisr_mode_get_img_demod_drf_bisr_3_mode(data)         ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_drf_bisr_mode_get_img_demod_drf_bisr_2_mode(data)         ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_drf_bisr_mode_get_img_demod_drf_bisr_1_mode(data)         ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_drf_bisr_mode_get_img_demod_drf_bisr_0_mode(data)         (0x00000001&(data))

#define  IMG_DEMOD_BUS_drf_bisr_test_resume                                      0x18072218
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_reg_addr                             "0xB8072218"
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_reg                                  0xB8072218
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_inst_addr                            "0x0025"
#define  set_IMG_DEMOD_BUS_drf_bisr_test_resume_reg(data)                        (*((volatile unsigned int*)IMG_DEMOD_BUS_drf_bisr_test_resume_reg)=data)
#define  get_IMG_DEMOD_BUS_drf_bisr_test_resume_reg                              (*((volatile unsigned int*)IMG_DEMOD_BUS_drf_bisr_test_resume_reg))
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_5_test_resume_shift (5)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_4_test_resume_shift (4)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_3_test_resume_shift (3)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_2_test_resume_shift (2)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_1_test_resume_shift (1)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_0_test_resume_shift (0)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_5_test_resume_mask (0x00000020)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_4_test_resume_mask (0x00000010)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_3_test_resume_mask (0x00000008)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_2_test_resume_mask (0x00000004)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_1_test_resume_mask (0x00000002)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_0_test_resume_mask (0x00000001)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_5_test_resume(data) (0x00000020&((data)<<5))
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_4_test_resume(data) (0x00000010&((data)<<4))
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_3_test_resume(data) (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_2_test_resume(data) (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_1_test_resume(data) (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_img_demod_drf_bisr_0_test_resume(data) (0x00000001&(data))
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_get_img_demod_drf_bisr_5_test_resume(data) ((0x00000020&(data))>>5)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_get_img_demod_drf_bisr_4_test_resume(data) ((0x00000010&(data))>>4)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_get_img_demod_drf_bisr_3_test_resume(data) ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_get_img_demod_drf_bisr_2_test_resume(data) ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_get_img_demod_drf_bisr_1_test_resume(data) ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_drf_bisr_test_resume_get_img_demod_drf_bisr_0_test_resume(data) (0x00000001&(data))

#define  IMG_DEMOD_BUS_drf_bisr_start_pause                                      0x1807221C
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_reg_addr                             "0xB807221C"
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_reg                                  0xB807221C
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_inst_addr                            "0x0026"
#define  set_IMG_DEMOD_BUS_drf_bisr_start_pause_reg(data)                        (*((volatile unsigned int*)IMG_DEMOD_BUS_drf_bisr_start_pause_reg)=data)
#define  get_IMG_DEMOD_BUS_drf_bisr_start_pause_reg                              (*((volatile unsigned int*)IMG_DEMOD_BUS_drf_bisr_start_pause_reg))
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_5_start_pause_shift (5)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_4_start_pause_shift (4)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_3_start_pause_shift (3)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_2_start_pause_shift (2)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_1_start_pause_shift (1)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_0_start_pause_shift (0)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_5_start_pause_mask (0x00000020)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_4_start_pause_mask (0x00000010)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_3_start_pause_mask (0x00000008)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_2_start_pause_mask (0x00000004)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_1_start_pause_mask (0x00000002)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_0_start_pause_mask (0x00000001)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_5_start_pause(data) (0x00000020&((data)<<5))
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_4_start_pause(data) (0x00000010&((data)<<4))
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_3_start_pause(data) (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_2_start_pause(data) (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_1_start_pause(data) (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_img_demod_drf_bisr_0_start_pause(data) (0x00000001&(data))
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_get_img_demod_drf_bisr_5_start_pause(data) ((0x00000020&(data))>>5)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_get_img_demod_drf_bisr_4_start_pause(data) ((0x00000010&(data))>>4)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_get_img_demod_drf_bisr_3_start_pause(data) ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_get_img_demod_drf_bisr_2_start_pause(data) ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_get_img_demod_drf_bisr_1_start_pause(data) ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_drf_bisr_start_pause_get_img_demod_drf_bisr_0_start_pause(data) (0x00000001&(data))

#define  IMG_DEMOD_BUS_drf_bisr_done                                             0x18072220
#define  IMG_DEMOD_BUS_drf_bisr_done_reg_addr                                    "0xB8072220"
#define  IMG_DEMOD_BUS_drf_bisr_done_reg                                         0xB8072220
#define  IMG_DEMOD_BUS_drf_bisr_done_inst_addr                                   "0x0027"
#define  set_IMG_DEMOD_BUS_drf_bisr_done_reg(data)                               (*((volatile unsigned int*)IMG_DEMOD_BUS_drf_bisr_done_reg)=data)
#define  get_IMG_DEMOD_BUS_drf_bisr_done_reg                                     (*((volatile unsigned int*)IMG_DEMOD_BUS_drf_bisr_done_reg))
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_5_done_shift             (5)
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_4_done_shift             (4)
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_3_done_shift             (3)
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_2_done_shift             (2)
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_1_done_shift             (1)
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_0_done_shift             (0)
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_5_done_mask              (0x00000020)
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_4_done_mask              (0x00000010)
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_3_done_mask              (0x00000008)
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_2_done_mask              (0x00000004)
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_1_done_mask              (0x00000002)
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_0_done_mask              (0x00000001)
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_5_done(data)             (0x00000020&((data)<<5))
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_4_done(data)             (0x00000010&((data)<<4))
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_3_done(data)             (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_2_done(data)             (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_1_done(data)             (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_drf_bisr_done_img_demod_drf_bisr_0_done(data)             (0x00000001&(data))
#define  IMG_DEMOD_BUS_drf_bisr_done_get_img_demod_drf_bisr_5_done(data)         ((0x00000020&(data))>>5)
#define  IMG_DEMOD_BUS_drf_bisr_done_get_img_demod_drf_bisr_4_done(data)         ((0x00000010&(data))>>4)
#define  IMG_DEMOD_BUS_drf_bisr_done_get_img_demod_drf_bisr_3_done(data)         ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_drf_bisr_done_get_img_demod_drf_bisr_2_done(data)         ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_drf_bisr_done_get_img_demod_drf_bisr_1_done(data)         ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_drf_bisr_done_get_img_demod_drf_bisr_0_done(data)         (0x00000001&(data))

#define  IMG_DEMOD_BUS_drf_bisr_fail                                             0x18072224
#define  IMG_DEMOD_BUS_drf_bisr_fail_reg_addr                                    "0xB8072224"
#define  IMG_DEMOD_BUS_drf_bisr_fail_reg                                         0xB8072224
#define  IMG_DEMOD_BUS_drf_bisr_fail_inst_addr                                   "0x0028"
#define  set_IMG_DEMOD_BUS_drf_bisr_fail_reg(data)                               (*((volatile unsigned int*)IMG_DEMOD_BUS_drf_bisr_fail_reg)=data)
#define  get_IMG_DEMOD_BUS_drf_bisr_fail_reg                                     (*((volatile unsigned int*)IMG_DEMOD_BUS_drf_bisr_fail_reg))
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_5_fail_shift             (5)
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_4_fail_shift             (4)
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_3_fail_shift             (3)
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_2_fail_shift             (2)
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_1_fail_shift             (1)
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_0_fail_shift             (0)
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_5_fail_mask              (0x00000020)
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_4_fail_mask              (0x00000010)
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_3_fail_mask              (0x00000008)
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_2_fail_mask              (0x00000004)
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_1_fail_mask              (0x00000002)
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_0_fail_mask              (0x00000001)
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_5_fail(data)             (0x00000020&((data)<<5))
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_4_fail(data)             (0x00000010&((data)<<4))
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_3_fail(data)             (0x00000008&((data)<<3))
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_2_fail(data)             (0x00000004&((data)<<2))
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_1_fail(data)             (0x00000002&((data)<<1))
#define  IMG_DEMOD_BUS_drf_bisr_fail_img_demod_drf_bisr_0_fail(data)             (0x00000001&(data))
#define  IMG_DEMOD_BUS_drf_bisr_fail_get_img_demod_drf_bisr_5_fail(data)         ((0x00000020&(data))>>5)
#define  IMG_DEMOD_BUS_drf_bisr_fail_get_img_demod_drf_bisr_4_fail(data)         ((0x00000010&(data))>>4)
#define  IMG_DEMOD_BUS_drf_bisr_fail_get_img_demod_drf_bisr_3_fail(data)         ((0x00000008&(data))>>3)
#define  IMG_DEMOD_BUS_drf_bisr_fail_get_img_demod_drf_bisr_2_fail(data)         ((0x00000004&(data))>>2)
#define  IMG_DEMOD_BUS_drf_bisr_fail_get_img_demod_drf_bisr_1_fail(data)         ((0x00000002&(data))>>1)
#define  IMG_DEMOD_BUS_drf_bisr_fail_get_img_demod_drf_bisr_0_fail(data)         (0x00000001&(data))

#define  IMG_DEMOD_BUS_DEMOD_SEL                                                 0x18072230
#define  IMG_DEMOD_BUS_DEMOD_SEL_reg_addr                                        "0xB8072230"
#define  IMG_DEMOD_BUS_DEMOD_SEL_reg                                             0xB8072230
#define  IMG_DEMOD_BUS_DEMOD_SEL_inst_addr                                       "0x0029"
#define  set_IMG_DEMOD_BUS_DEMOD_SEL_reg(data)                                   (*((volatile unsigned int*)IMG_DEMOD_BUS_DEMOD_SEL_reg)=data)
#define  get_IMG_DEMOD_BUS_DEMOD_SEL_reg                                         (*((volatile unsigned int*)IMG_DEMOD_BUS_DEMOD_SEL_reg))
#define  IMG_DEMOD_BUS_DEMOD_SEL_dtv_demod_sel_shift                             (0)
#define  IMG_DEMOD_BUS_DEMOD_SEL_dtv_demod_sel_mask                              (0x00000001)
#define  IMG_DEMOD_BUS_DEMOD_SEL_dtv_demod_sel(data)                             (0x00000001&(data))
#define  IMG_DEMOD_BUS_DEMOD_SEL_get_dtv_demod_sel(data)                         (0x00000001&(data))

#define  IMG_DEMOD_BUS_DEMOD_DEBUG                                               0x18072234
#define  IMG_DEMOD_BUS_DEMOD_DEBUG_reg_addr                                      "0xB8072234"
#define  IMG_DEMOD_BUS_DEMOD_DEBUG_reg                                           0xB8072234
#define  IMG_DEMOD_BUS_DEMOD_DEBUG_inst_addr                                     "0x002A"
#define  set_IMG_DEMOD_BUS_DEMOD_DEBUG_reg(data)                                 (*((volatile unsigned int*)IMG_DEMOD_BUS_DEMOD_DEBUG_reg)=data)
#define  get_IMG_DEMOD_BUS_DEMOD_DEBUG_reg                                       (*((volatile unsigned int*)IMG_DEMOD_BUS_DEMOD_DEBUG_reg))
#define  IMG_DEMOD_BUS_DEMOD_DEBUG_demod_debug_out_shift                         (0)
#define  IMG_DEMOD_BUS_DEMOD_DEBUG_demod_debug_out_mask                          (0xFFFFFFFF)
#define  IMG_DEMOD_BUS_DEMOD_DEBUG_demod_debug_out(data)                         (0xFFFFFFFF&(data))
#define  IMG_DEMOD_BUS_DEMOD_DEBUG_get_demod_debug_out(data)                     (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IMG_DEMOD_BUS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  remain_dc_cnt:5;
        RBus_UInt32  res2:15;
        RBus_UInt32  dw_soft_reset:1;
    };
}img_demod_bus_img_bus_soft_reset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  res3:11;
        RBus_UInt32  dw_endian_swap:1;
        RBus_UInt32  dw_force_write_bufferable:1;
        RBus_UInt32  dw_in_order_mode:1;
        RBus_UInt32  dw_rw_arbitration:2;
    };
}img_demod_bus_img_mem_bus_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  dw_rd_outstand_num:5;
        RBus_UInt32  res2:11;
        RBus_UInt32  dw_wr_outstand_num:5;
    };
}img_demod_bus_img_mem_bus_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_addr_base:32;
    };
}img_demod_bus_img_mem_bus_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  dw_rd_outstand_cnt:5;
        RBus_UInt32  res2:11;
        RBus_UInt32  dw_wr_outstand_cnt:5;
    };
}img_demod_bus_img_mem_bus_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  host_sys_bus_addr_31_18:14;
        RBus_UInt32  res1:18;
    };
}img_demod_bus_img_host_sys_bus_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_sys_addr_31_12:20;
        RBus_UInt32  res1:12;
    };
}img_demod_bus_img_ext_sys_bus_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  demod_wrapper_bist_mode:1;
        RBus_UInt32  demod_wrapper_bist_done:1;
        RBus_UInt32  demod_wrapper_bist_fail_0:1;
        RBus_UInt32  demod_wrapper_bist_fail_1:1;
    };
}img_demod_bus_img_bus_wrapper_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  demod_wrapper_drf_bist_mode:1;
        RBus_UInt32  demod_wrapper_drf_test_resume:1;
        RBus_UInt32  demod_wrapper_drf_start_pause:1;
        RBus_UInt32  demod_wrapper_drf_bist_done:1;
        RBus_UInt32  demod_wrapper_drf_bist_fail_0:1;
        RBus_UInt32  demod_wrapper_drf_bist_fail_1:1;
    };
}img_demod_bus_img_bus_wrapper_drf_RBUS;

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
}img_demod_bus_img_bus_wrapper_sram_ctrl_RBUS;

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
}img_demod_bus_img_mem_bus_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  stop_dbg_read:1;
        RBus_UInt32  fetch_dbg_entry_read:1;
    };
}img_demod_bus_img_mem_debug_read_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  valid_entry_cnt_read:5;
    };
}img_demod_bus_img_mem_debug_read_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  dbg_entry_axi_id_read:1;
        RBus_UInt32  dbg_entry_axi_addr_read:26;
    };
}img_demod_bus_img_mem_debug_read_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  stop_dbg_write:1;
        RBus_UInt32  fetch_dbg_entry_write:1;
    };
}img_demod_bus_img_mem_debug_write_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  valid_entry_cnt_write:5;
    };
}img_demod_bus_img_mem_debug_write_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  dbg_entry_axi_id_write:1;
        RBus_UInt32  dbg_entry_axi_addr_write:26;
    };
}img_demod_bus_img_mem_debug_write_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_rw:32;
    };
}img_demod_bus_img_bus_wrapper_backup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_rw_2:32;
    };
}img_demod_bus_img_bus_wrapper_backup2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  designer_rev:8;
    };
}img_demod_bus_img_ipcore_revision_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  sys_clk_enable:1;
        RBus_UInt32  res2:5;
    };
}img_demod_bus_img_ipcore_reset_cken_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  jtag_sel:2;
        RBus_UInt32  trstn:1;
        RBus_UInt32  tms:1;
        RBus_UInt32  tdi:1;
        RBus_UInt32  tck:1;
    };
}img_demod_bus_img_ipcore_jtag_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  tdo:1;
    };
}img_demod_bus_img_ipcore_jtag_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_irq_i_63_32:32;
    };
}img_demod_bus_img_ipcore_irq_in_63_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_irq_i_31_0:32;
    };
}img_demod_bus_img_ipcore_irq_in_31_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  metx_boot_in:1;
        RBus_UInt32  metx_boot_ready:1;
        RBus_UInt32  metx_boot_addr:4;
        RBus_UInt32  metx_boot_minim:1;
        RBus_UInt32  metx_debug_reset:1;
    };
}img_demod_bus_img_ipcore_metx_boot_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_in:32;
    };
}img_demod_bus_img_ipcore_gpio_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_out:32;
    };
}img_demod_bus_img_ipcore_gpio_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dbg_ucc_is_slave:1;
        RBus_UInt32  dbg_metx_is_slave:1;
    };
}img_demod_bus_img_ipcore_dbg_is_slave_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  img_demod_irq:1;
        RBus_UInt32  img_demod_irq_en:1;
        RBus_UInt32  host_irq:1;
        RBus_UInt32  host_irq_en:1;
        RBus_UInt32  ext_opt_req_idle:1;
        RBus_UInt32  ext_opt_mem_idle:1;
    };
}img_demod_bus_img_ipcore_ucc_irq_ip_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  demod_sel:4;
        RBus_UInt32  ifadc_sel:1;
        RBus_UInt32  oversample_sel:1;
    };
}img_demod_bus_img_clkgen_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  debug_sel:4;
    };
}img_demod_bus_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  img_demod_bisr_5_second_run_en:1;
        RBus_UInt32  img_demod_bisr_4_second_run_en:1;
        RBus_UInt32  img_demod_bisr_3_second_run_en:1;
        RBus_UInt32  img_demod_bisr_2_second_run_en:1;
        RBus_UInt32  img_demod_bisr_1_second_run_en:1;
        RBus_UInt32  img_demod_bisr_0_second_run_en:1;
    };
}img_demod_bus_bisr_second_run_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  img_demod_bisr_5_fail:1;
        RBus_UInt32  img_demod_bisr_4_fail:1;
        RBus_UInt32  img_demod_bisr_3_fail:1;
        RBus_UInt32  img_demod_bisr_2_fail:1;
        RBus_UInt32  img_demod_bisr_1_fail:1;
        RBus_UInt32  img_demod_bisr_0_fail:1;
    };
}img_demod_bus_bisr_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  img_demod_bisr_5_repaired:1;
        RBus_UInt32  img_demod_bisr_4_repaired:1;
        RBus_UInt32  img_demod_bisr_3_repaired:1;
        RBus_UInt32  img_demod_bisr_2_repaired:1;
        RBus_UInt32  img_demod_bisr_1_repaired:1;
        RBus_UInt32  img_demod_bisr_0_repaired:1;
    };
}img_demod_bus_bisr_repaired_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  img_demod_bisr_5_out:5;
        RBus_UInt32  img_demod_bisr_4_out:5;
        RBus_UInt32  img_demod_bisr_3_out:5;
        RBus_UInt32  img_demod_bisr_2_out:5;
        RBus_UInt32  img_demod_bisr_1_out:5;
        RBus_UInt32  img_demod_bisr_0_out:5;
    };
}img_demod_bus_bisr_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  img_demod_drf_bisr_5_mode:1;
        RBus_UInt32  img_demod_drf_bisr_4_mode:1;
        RBus_UInt32  img_demod_drf_bisr_3_mode:1;
        RBus_UInt32  img_demod_drf_bisr_2_mode:1;
        RBus_UInt32  img_demod_drf_bisr_1_mode:1;
        RBus_UInt32  img_demod_drf_bisr_0_mode:1;
    };
}img_demod_bus_drf_bisr_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  img_demod_drf_bisr_5_test_resume:1;
        RBus_UInt32  img_demod_drf_bisr_4_test_resume:1;
        RBus_UInt32  img_demod_drf_bisr_3_test_resume:1;
        RBus_UInt32  img_demod_drf_bisr_2_test_resume:1;
        RBus_UInt32  img_demod_drf_bisr_1_test_resume:1;
        RBus_UInt32  img_demod_drf_bisr_0_test_resume:1;
    };
}img_demod_bus_drf_bisr_test_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  img_demod_drf_bisr_5_start_pause:1;
        RBus_UInt32  img_demod_drf_bisr_4_start_pause:1;
        RBus_UInt32  img_demod_drf_bisr_3_start_pause:1;
        RBus_UInt32  img_demod_drf_bisr_2_start_pause:1;
        RBus_UInt32  img_demod_drf_bisr_1_start_pause:1;
        RBus_UInt32  img_demod_drf_bisr_0_start_pause:1;
    };
}img_demod_bus_drf_bisr_start_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  img_demod_drf_bisr_5_done:1;
        RBus_UInt32  img_demod_drf_bisr_4_done:1;
        RBus_UInt32  img_demod_drf_bisr_3_done:1;
        RBus_UInt32  img_demod_drf_bisr_2_done:1;
        RBus_UInt32  img_demod_drf_bisr_1_done:1;
        RBus_UInt32  img_demod_drf_bisr_0_done:1;
    };
}img_demod_bus_drf_bisr_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  img_demod_drf_bisr_5_fail:1;
        RBus_UInt32  img_demod_drf_bisr_4_fail:1;
        RBus_UInt32  img_demod_drf_bisr_3_fail:1;
        RBus_UInt32  img_demod_drf_bisr_2_fail:1;
        RBus_UInt32  img_demod_drf_bisr_1_fail:1;
        RBus_UInt32  img_demod_drf_bisr_0_fail:1;
    };
}img_demod_bus_drf_bisr_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  dtv_demod_sel:1;
    };
}img_demod_bus_demod_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  demod_debug_out:32;
    };
}img_demod_bus_demod_debug_RBUS;

#else //apply LITTLE_ENDIAN

//======IMG_DEMOD_BUS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dw_soft_reset:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  remain_dc_cnt:5;
        RBus_UInt32  res2:11;
    };
}img_demod_bus_img_bus_soft_reset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dw_rw_arbitration:2;
        RBus_UInt32  dw_in_order_mode:1;
        RBus_UInt32  dw_force_write_bufferable:1;
        RBus_UInt32  dw_endian_swap:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  res2:6;
        RBus_UInt32  res3:10;
    };
}img_demod_bus_img_mem_bus_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dw_wr_outstand_num:5;
        RBus_UInt32  res1:11;
        RBus_UInt32  dw_rd_outstand_num:5;
        RBus_UInt32  res2:11;
    };
}img_demod_bus_img_mem_bus_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_addr_base:32;
    };
}img_demod_bus_img_mem_bus_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dw_wr_outstand_cnt:5;
        RBus_UInt32  res1:11;
        RBus_UInt32  dw_rd_outstand_cnt:5;
        RBus_UInt32  res2:11;
    };
}img_demod_bus_img_mem_bus_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  host_sys_bus_addr_31_18:14;
    };
}img_demod_bus_img_host_sys_bus_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ext_sys_addr_31_12:20;
    };
}img_demod_bus_img_ext_sys_bus_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  demod_wrapper_bist_fail_1:1;
        RBus_UInt32  demod_wrapper_bist_fail_0:1;
        RBus_UInt32  demod_wrapper_bist_done:1;
        RBus_UInt32  demod_wrapper_bist_mode:1;
        RBus_UInt32  res1:28;
    };
}img_demod_bus_img_bus_wrapper_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  demod_wrapper_drf_bist_fail_1:1;
        RBus_UInt32  demod_wrapper_drf_bist_fail_0:1;
        RBus_UInt32  demod_wrapper_drf_bist_done:1;
        RBus_UInt32  demod_wrapper_drf_start_pause:1;
        RBus_UInt32  demod_wrapper_drf_test_resume:1;
        RBus_UInt32  demod_wrapper_drf_bist_mode:1;
        RBus_UInt32  res1:26;
    };
}img_demod_bus_img_bus_wrapper_drf_RBUS;

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
}img_demod_bus_img_bus_wrapper_sram_ctrl_RBUS;

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
}img_demod_bus_img_mem_bus_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fetch_dbg_entry_read:1;
        RBus_UInt32  stop_dbg_read:1;
        RBus_UInt32  res1:30;
    };
}img_demod_bus_img_mem_debug_read_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  valid_entry_cnt_read:5;
        RBus_UInt32  res1:27;
    };
}img_demod_bus_img_mem_debug_read_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_entry_axi_addr_read:26;
        RBus_UInt32  dbg_entry_axi_id_read:1;
        RBus_UInt32  res1:5;
    };
}img_demod_bus_img_mem_debug_read_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fetch_dbg_entry_write:1;
        RBus_UInt32  stop_dbg_write:1;
        RBus_UInt32  res1:30;
    };
}img_demod_bus_img_mem_debug_write_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  valid_entry_cnt_write:5;
        RBus_UInt32  res1:27;
    };
}img_demod_bus_img_mem_debug_write_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_entry_axi_addr_write:26;
        RBus_UInt32  dbg_entry_axi_id_write:1;
        RBus_UInt32  res1:5;
    };
}img_demod_bus_img_mem_debug_write_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_rw:32;
    };
}img_demod_bus_img_bus_wrapper_backup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_rw_2:32;
    };
}img_demod_bus_img_bus_wrapper_backup2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  designer_rev:8;
        RBus_UInt32  res1:24;
    };
}img_demod_bus_img_ipcore_revision_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  sys_clk_enable:1;
        RBus_UInt32  res2:26;
    };
}img_demod_bus_img_ipcore_reset_cken_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tck:1;
        RBus_UInt32  tdi:1;
        RBus_UInt32  tms:1;
        RBus_UInt32  trstn:1;
        RBus_UInt32  jtag_sel:2;
        RBus_UInt32  res1:26;
    };
}img_demod_bus_img_ipcore_jtag_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tdo:1;
        RBus_UInt32  res1:31;
    };
}img_demod_bus_img_ipcore_jtag_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_irq_i_63_32:32;
    };
}img_demod_bus_img_ipcore_irq_in_63_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_irq_i_31_0:32;
    };
}img_demod_bus_img_ipcore_irq_in_31_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  metx_debug_reset:1;
        RBus_UInt32  metx_boot_minim:1;
        RBus_UInt32  metx_boot_addr:4;
        RBus_UInt32  metx_boot_ready:1;
        RBus_UInt32  metx_boot_in:1;
        RBus_UInt32  res1:24;
    };
}img_demod_bus_img_ipcore_metx_boot_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_in:32;
    };
}img_demod_bus_img_ipcore_gpio_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_out:32;
    };
}img_demod_bus_img_ipcore_gpio_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_metx_is_slave:1;
        RBus_UInt32  dbg_ucc_is_slave:1;
        RBus_UInt32  res1:30;
    };
}img_demod_bus_img_ipcore_dbg_is_slave_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_opt_mem_idle:1;
        RBus_UInt32  ext_opt_req_idle:1;
        RBus_UInt32  host_irq_en:1;
        RBus_UInt32  host_irq:1;
        RBus_UInt32  img_demod_irq_en:1;
        RBus_UInt32  img_demod_irq:1;
        RBus_UInt32  res1:26;
    };
}img_demod_bus_img_ipcore_ucc_irq_ip_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oversample_sel:1;
        RBus_UInt32  ifadc_sel:1;
        RBus_UInt32  demod_sel:4;
        RBus_UInt32  res1:26;
    };
}img_demod_bus_img_clkgen_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_sel:4;
        RBus_UInt32  res1:28;
    };
}img_demod_bus_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  img_demod_bisr_0_second_run_en:1;
        RBus_UInt32  img_demod_bisr_1_second_run_en:1;
        RBus_UInt32  img_demod_bisr_2_second_run_en:1;
        RBus_UInt32  img_demod_bisr_3_second_run_en:1;
        RBus_UInt32  img_demod_bisr_4_second_run_en:1;
        RBus_UInt32  img_demod_bisr_5_second_run_en:1;
        RBus_UInt32  res1:26;
    };
}img_demod_bus_bisr_second_run_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  img_demod_bisr_0_fail:1;
        RBus_UInt32  img_demod_bisr_1_fail:1;
        RBus_UInt32  img_demod_bisr_2_fail:1;
        RBus_UInt32  img_demod_bisr_3_fail:1;
        RBus_UInt32  img_demod_bisr_4_fail:1;
        RBus_UInt32  img_demod_bisr_5_fail:1;
        RBus_UInt32  res1:26;
    };
}img_demod_bus_bisr_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  img_demod_bisr_0_repaired:1;
        RBus_UInt32  img_demod_bisr_1_repaired:1;
        RBus_UInt32  img_demod_bisr_2_repaired:1;
        RBus_UInt32  img_demod_bisr_3_repaired:1;
        RBus_UInt32  img_demod_bisr_4_repaired:1;
        RBus_UInt32  img_demod_bisr_5_repaired:1;
        RBus_UInt32  res1:26;
    };
}img_demod_bus_bisr_repaired_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  img_demod_bisr_0_out:5;
        RBus_UInt32  img_demod_bisr_1_out:5;
        RBus_UInt32  img_demod_bisr_2_out:5;
        RBus_UInt32  img_demod_bisr_3_out:5;
        RBus_UInt32  img_demod_bisr_4_out:5;
        RBus_UInt32  img_demod_bisr_5_out:5;
        RBus_UInt32  res1:2;
    };
}img_demod_bus_bisr_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  img_demod_drf_bisr_0_mode:1;
        RBus_UInt32  img_demod_drf_bisr_1_mode:1;
        RBus_UInt32  img_demod_drf_bisr_2_mode:1;
        RBus_UInt32  img_demod_drf_bisr_3_mode:1;
        RBus_UInt32  img_demod_drf_bisr_4_mode:1;
        RBus_UInt32  img_demod_drf_bisr_5_mode:1;
        RBus_UInt32  res1:26;
    };
}img_demod_bus_drf_bisr_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  img_demod_drf_bisr_0_test_resume:1;
        RBus_UInt32  img_demod_drf_bisr_1_test_resume:1;
        RBus_UInt32  img_demod_drf_bisr_2_test_resume:1;
        RBus_UInt32  img_demod_drf_bisr_3_test_resume:1;
        RBus_UInt32  img_demod_drf_bisr_4_test_resume:1;
        RBus_UInt32  img_demod_drf_bisr_5_test_resume:1;
        RBus_UInt32  res1:26;
    };
}img_demod_bus_drf_bisr_test_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  img_demod_drf_bisr_0_start_pause:1;
        RBus_UInt32  img_demod_drf_bisr_1_start_pause:1;
        RBus_UInt32  img_demod_drf_bisr_2_start_pause:1;
        RBus_UInt32  img_demod_drf_bisr_3_start_pause:1;
        RBus_UInt32  img_demod_drf_bisr_4_start_pause:1;
        RBus_UInt32  img_demod_drf_bisr_5_start_pause:1;
        RBus_UInt32  res1:26;
    };
}img_demod_bus_drf_bisr_start_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  img_demod_drf_bisr_0_done:1;
        RBus_UInt32  img_demod_drf_bisr_1_done:1;
        RBus_UInt32  img_demod_drf_bisr_2_done:1;
        RBus_UInt32  img_demod_drf_bisr_3_done:1;
        RBus_UInt32  img_demod_drf_bisr_4_done:1;
        RBus_UInt32  img_demod_drf_bisr_5_done:1;
        RBus_UInt32  res1:26;
    };
}img_demod_bus_drf_bisr_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  img_demod_drf_bisr_0_fail:1;
        RBus_UInt32  img_demod_drf_bisr_1_fail:1;
        RBus_UInt32  img_demod_drf_bisr_2_fail:1;
        RBus_UInt32  img_demod_drf_bisr_3_fail:1;
        RBus_UInt32  img_demod_drf_bisr_4_fail:1;
        RBus_UInt32  img_demod_drf_bisr_5_fail:1;
        RBus_UInt32  res1:26;
    };
}img_demod_bus_drf_bisr_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_demod_sel:1;
        RBus_UInt32  res1:31;
    };
}img_demod_bus_demod_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  demod_debug_out:32;
    };
}img_demod_bus_demod_debug_RBUS;




#endif 


#endif 
