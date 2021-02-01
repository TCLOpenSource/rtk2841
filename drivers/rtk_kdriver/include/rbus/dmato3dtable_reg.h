/**
* @file Mac5-DesignSpec-DMAto3DTable
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DMATO3DTABLE_REG_H_
#define _RBUS_DMATO3DTABLE_REG_H_

#include "rbus_types.h"



//  DMATO3DTABLE Register Address
#define  DMATO3DTABLE_DMAto3DTable_db_ctl                                        0x1806BD00
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_reg_addr                               "0xB806BD00"
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_reg                                    0xB806BD00
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_inst_addr                              "0x0000"
#define  set_DMATO3DTABLE_DMAto3DTable_db_ctl_reg(data)                          (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_db_ctl_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_db_ctl_reg                                (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_db_ctl_reg))
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_dummy_18_3_shift                       (3)
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_db_read_shift                          (2)
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_db_en_shift                            (1)
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_wtable_apply_shift                     (0)
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_dummy_18_3_mask                        (0x0007FFF8)
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_db_read_mask                           (0x00000004)
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_db_en_mask                             (0x00000002)
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_wtable_apply_mask                      (0x00000001)
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_dummy_18_3(data)                       (0x0007FFF8&((data)<<3))
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_db_read(data)                          (0x00000004&((data)<<2))
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_db_en(data)                            (0x00000002&((data)<<1))
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_wtable_apply(data)                     (0x00000001&(data))
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_get_dummy_18_3(data)                   ((0x0007FFF8&(data))>>3)
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_get_db_read(data)                      ((0x00000004&(data))>>2)
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_get_db_en(data)                        ((0x00000002&(data))>>1)
#define  DMATO3DTABLE_DMAto3DTable_db_ctl_get_wtable_apply(data)                 (0x00000001&(data))

#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_up                                   0x1806BD04
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_up_reg_addr                          "0xB806BD04"
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_up_reg                               0xB806BD04
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_up_inst_addr                         "0x0001"
#define  set_DMATO3DTABLE_CTI_DMA_RD_Rule_check_up_reg(data)                     (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_Rule_check_up_reg)=data)
#define  get_DMATO3DTABLE_CTI_DMA_RD_Rule_check_up_reg                           (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_Rule_check_up_reg))
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_up_dma_up_limint_shift               (4)
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_up_dma_up_limint_mask                (0xFFFFFFF0)
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_up_dma_up_limint(data)               (0xFFFFFFF0&((data)<<4))
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_up_get_dma_up_limint(data)           ((0xFFFFFFF0&(data))>>4)

#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_low                                  0x1806BD08
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_low_reg_addr                         "0xB806BD08"
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_low_reg                              0xB806BD08
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_low_inst_addr                        "0x0002"
#define  set_DMATO3DTABLE_CTI_DMA_RD_Rule_check_low_reg(data)                    (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_Rule_check_low_reg)=data)
#define  get_DMATO3DTABLE_CTI_DMA_RD_Rule_check_low_reg                          (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_Rule_check_low_reg))
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_low_dma_low_limint_shift             (4)
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_low_dma_low_limint_mask              (0xFFFFFFF0)
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_low_dma_low_limint(data)             (0xFFFFFFF0&((data)<<4))
#define  DMATO3DTABLE_CTI_DMA_RD_Rule_check_low_get_dma_low_limint(data)         ((0xFFFFFFF0&(data))>>4)

#define  DMATO3DTABLE_CTI_DMA_RD_Ctrl                                            0x1806BD0C
#define  DMATO3DTABLE_CTI_DMA_RD_Ctrl_reg_addr                                   "0xB806BD0C"
#define  DMATO3DTABLE_CTI_DMA_RD_Ctrl_reg                                        0xB806BD0C
#define  DMATO3DTABLE_CTI_DMA_RD_Ctrl_inst_addr                                  "0x0003"
#define  set_DMATO3DTABLE_CTI_DMA_RD_Ctrl_reg(data)                              (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_Ctrl_reg)=data)
#define  get_DMATO3DTABLE_CTI_DMA_RD_Ctrl_reg                                    (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_Ctrl_reg))
#define  DMATO3DTABLE_CTI_DMA_RD_Ctrl_max_outstanding_shift                      (8)
#define  DMATO3DTABLE_CTI_DMA_RD_Ctrl_force_all_rst_shift                        (1)
#define  DMATO3DTABLE_CTI_DMA_RD_Ctrl_max_outstanding_mask                       (0x00000300)
#define  DMATO3DTABLE_CTI_DMA_RD_Ctrl_force_all_rst_mask                         (0x00000002)
#define  DMATO3DTABLE_CTI_DMA_RD_Ctrl_max_outstanding(data)                      (0x00000300&((data)<<8))
#define  DMATO3DTABLE_CTI_DMA_RD_Ctrl_force_all_rst(data)                        (0x00000002&((data)<<1))
#define  DMATO3DTABLE_CTI_DMA_RD_Ctrl_get_max_outstanding(data)                  ((0x00000300&(data))>>8)
#define  DMATO3DTABLE_CTI_DMA_RD_Ctrl_get_force_all_rst(data)                    ((0x00000002&(data))>>1)

#define  DMATO3DTABLE_CTI_DMA_RD_status                                          0x1806BD10
#define  DMATO3DTABLE_CTI_DMA_RD_status_reg_addr                                 "0xB806BD10"
#define  DMATO3DTABLE_CTI_DMA_RD_status_reg                                      0xB806BD10
#define  DMATO3DTABLE_CTI_DMA_RD_status_inst_addr                                "0x0004"
#define  set_DMATO3DTABLE_CTI_DMA_RD_status_reg(data)                            (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_status_reg)=data)
#define  get_DMATO3DTABLE_CTI_DMA_RD_status_reg                                  (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_status_reg))
#define  DMATO3DTABLE_CTI_DMA_RD_status_dma_cmd_water_shift                      (28)
#define  DMATO3DTABLE_CTI_DMA_RD_status_dma_data_water_shift                     (16)
#define  DMATO3DTABLE_CTI_DMA_RD_status_cur_outstanding_shift                    (8)
#define  DMATO3DTABLE_CTI_DMA_RD_status_soft_rst_before_cmd_finish_shift         (4)
#define  DMATO3DTABLE_CTI_DMA_RD_status_soft_rst_with_data_left_shift            (3)
#define  DMATO3DTABLE_CTI_DMA_RD_status_data_fifo_overflow_err_shift             (2)
#define  DMATO3DTABLE_CTI_DMA_RD_status_exceed_range_err_shift                   (1)
#define  DMATO3DTABLE_CTI_DMA_RD_status_zero_length_err_shift                    (0)
#define  DMATO3DTABLE_CTI_DMA_RD_status_dma_cmd_water_mask                       (0x70000000)
#define  DMATO3DTABLE_CTI_DMA_RD_status_dma_data_water_mask                      (0x003F0000)
#define  DMATO3DTABLE_CTI_DMA_RD_status_cur_outstanding_mask                     (0x00000700)
#define  DMATO3DTABLE_CTI_DMA_RD_status_soft_rst_before_cmd_finish_mask          (0x00000010)
#define  DMATO3DTABLE_CTI_DMA_RD_status_soft_rst_with_data_left_mask             (0x00000008)
#define  DMATO3DTABLE_CTI_DMA_RD_status_data_fifo_overflow_err_mask              (0x00000004)
#define  DMATO3DTABLE_CTI_DMA_RD_status_exceed_range_err_mask                    (0x00000002)
#define  DMATO3DTABLE_CTI_DMA_RD_status_zero_length_err_mask                     (0x00000001)
#define  DMATO3DTABLE_CTI_DMA_RD_status_dma_cmd_water(data)                      (0x70000000&((data)<<28))
#define  DMATO3DTABLE_CTI_DMA_RD_status_dma_data_water(data)                     (0x003F0000&((data)<<16))
#define  DMATO3DTABLE_CTI_DMA_RD_status_cur_outstanding(data)                    (0x00000700&((data)<<8))
#define  DMATO3DTABLE_CTI_DMA_RD_status_soft_rst_before_cmd_finish(data)         (0x00000010&((data)<<4))
#define  DMATO3DTABLE_CTI_DMA_RD_status_soft_rst_with_data_left(data)            (0x00000008&((data)<<3))
#define  DMATO3DTABLE_CTI_DMA_RD_status_data_fifo_overflow_err(data)             (0x00000004&((data)<<2))
#define  DMATO3DTABLE_CTI_DMA_RD_status_exceed_range_err(data)                   (0x00000002&((data)<<1))
#define  DMATO3DTABLE_CTI_DMA_RD_status_zero_length_err(data)                    (0x00000001&(data))
#define  DMATO3DTABLE_CTI_DMA_RD_status_get_dma_cmd_water(data)                  ((0x70000000&(data))>>28)
#define  DMATO3DTABLE_CTI_DMA_RD_status_get_dma_data_water(data)                 ((0x003F0000&(data))>>16)
#define  DMATO3DTABLE_CTI_DMA_RD_status_get_cur_outstanding(data)                ((0x00000700&(data))>>8)
#define  DMATO3DTABLE_CTI_DMA_RD_status_get_soft_rst_before_cmd_finish(data)     ((0x00000010&(data))>>4)
#define  DMATO3DTABLE_CTI_DMA_RD_status_get_soft_rst_with_data_left(data)        ((0x00000008&(data))>>3)
#define  DMATO3DTABLE_CTI_DMA_RD_status_get_data_fifo_overflow_err(data)         ((0x00000004&(data))>>2)
#define  DMATO3DTABLE_CTI_DMA_RD_status_get_exceed_range_err(data)               ((0x00000002&(data))>>1)
#define  DMATO3DTABLE_CTI_DMA_RD_status_get_zero_length_err(data)                (0x00000001&(data))

#define  DMATO3DTABLE_CTI_DMA_RD_status1                                         0x1806BD14
#define  DMATO3DTABLE_CTI_DMA_RD_status1_reg_addr                                "0xB806BD14"
#define  DMATO3DTABLE_CTI_DMA_RD_status1_reg                                     0xB806BD14
#define  DMATO3DTABLE_CTI_DMA_RD_status1_inst_addr                               "0x0005"
#define  set_DMATO3DTABLE_CTI_DMA_RD_status1_reg(data)                           (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_status1_reg)=data)
#define  get_DMATO3DTABLE_CTI_DMA_RD_status1_reg                                 (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_status1_reg))
#define  DMATO3DTABLE_CTI_DMA_RD_status1_ack_num_error_shift                     (31)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_last_no_ack_error_shift                 (30)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_target_ack_num_shift                    (16)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_last_ack_num_shift                      (8)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_selected_bl_shift                       (0)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_ack_num_error_mask                      (0x80000000)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_last_no_ack_error_mask                  (0x40000000)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_target_ack_num_mask                     (0x007F0000)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_last_ack_num_mask                       (0x00007F00)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_selected_bl_mask                        (0x0000007F)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_ack_num_error(data)                     (0x80000000&((data)<<31))
#define  DMATO3DTABLE_CTI_DMA_RD_status1_last_no_ack_error(data)                 (0x40000000&((data)<<30))
#define  DMATO3DTABLE_CTI_DMA_RD_status1_target_ack_num(data)                    (0x007F0000&((data)<<16))
#define  DMATO3DTABLE_CTI_DMA_RD_status1_last_ack_num(data)                      (0x00007F00&((data)<<8))
#define  DMATO3DTABLE_CTI_DMA_RD_status1_selected_bl(data)                       (0x0000007F&(data))
#define  DMATO3DTABLE_CTI_DMA_RD_status1_get_ack_num_error(data)                 ((0x80000000&(data))>>31)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_get_last_no_ack_error(data)             ((0x40000000&(data))>>30)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_get_target_ack_num(data)                ((0x007F0000&(data))>>16)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_get_last_ack_num(data)                  ((0x00007F00&(data))>>8)
#define  DMATO3DTABLE_CTI_DMA_RD_status1_get_selected_bl(data)                   (0x0000007F&(data))

#define  DMATO3DTABLE_CTI_DMA_RD_status2                                         0x1806BD18
#define  DMATO3DTABLE_CTI_DMA_RD_status2_reg_addr                                "0xB806BD18"
#define  DMATO3DTABLE_CTI_DMA_RD_status2_reg                                     0xB806BD18
#define  DMATO3DTABLE_CTI_DMA_RD_status2_inst_addr                               "0x0006"
#define  set_DMATO3DTABLE_CTI_DMA_RD_status2_reg(data)                           (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_status2_reg)=data)
#define  get_DMATO3DTABLE_CTI_DMA_RD_status2_reg                                 (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_status2_reg))
#define  DMATO3DTABLE_CTI_DMA_RD_status2_selected_addr_shift                     (4)
#define  DMATO3DTABLE_CTI_DMA_RD_status2_addr_bl_sel_shift                       (0)
#define  DMATO3DTABLE_CTI_DMA_RD_status2_selected_addr_mask                      (0xFFFFFFF0)
#define  DMATO3DTABLE_CTI_DMA_RD_status2_addr_bl_sel_mask                        (0x00000003)
#define  DMATO3DTABLE_CTI_DMA_RD_status2_selected_addr(data)                     (0xFFFFFFF0&((data)<<4))
#define  DMATO3DTABLE_CTI_DMA_RD_status2_addr_bl_sel(data)                       (0x00000003&(data))
#define  DMATO3DTABLE_CTI_DMA_RD_status2_get_selected_addr(data)                 ((0xFFFFFFF0&(data))>>4)
#define  DMATO3DTABLE_CTI_DMA_RD_status2_get_addr_bl_sel(data)                   (0x00000003&(data))

#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor                                   0x1806BD1C
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_reg_addr                          "0xB806BD1C"
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_reg                               0xB806BD1C
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_inst_addr                         "0x0007"
#define  set_DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_reg(data)                     (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_reg)=data)
#define  get_DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_reg                           (*((volatile unsigned int*)DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_reg))
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_monitor_en_shift                  (31)
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_reach_thd_shift                   (22)
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_monitor_thd_shift                 (16)
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_lowest_water_level_shift          (0)
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_monitor_en_mask                   (0x80000000)
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_reach_thd_mask                    (0x00400000)
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_monitor_thd_mask                  (0x003F0000)
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_lowest_water_level_mask           (0x0000003F)
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_monitor_en(data)                  (0x80000000&((data)<<31))
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_reach_thd(data)                   (0x00400000&((data)<<22))
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_monitor_thd(data)                 (0x003F0000&((data)<<16))
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_lowest_water_level(data)          (0x0000003F&(data))
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_get_monitor_en(data)              ((0x80000000&(data))>>31)
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_get_reach_thd(data)               ((0x00400000&(data))>>22)
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_get_monitor_thd(data)             ((0x003F0000&(data))>>16)
#define  DMATO3DTABLE_CTI_DMA_RD_Water_Monitor_get_lowest_water_level(data)      (0x0000003F&(data))

#define  DMATO3DTABLE_dmato3dtable_MBIST                                         0x1806BD20
#define  DMATO3DTABLE_dmato3dtable_MBIST_reg_addr                                "0xB806BD20"
#define  DMATO3DTABLE_dmato3dtable_MBIST_reg                                     0xB806BD20
#define  DMATO3DTABLE_dmato3dtable_MBIST_inst_addr                               "0x0008"
#define  set_DMATO3DTABLE_dmato3dtable_MBIST_reg(data)                           (*((volatile unsigned int*)DMATO3DTABLE_dmato3dtable_MBIST_reg)=data)
#define  get_DMATO3DTABLE_dmato3dtable_MBIST_reg                                 (*((volatile unsigned int*)DMATO3DTABLE_dmato3dtable_MBIST_reg))
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_ls_shift                   (31)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_rmea_shift                 (30)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_rmeb_shift                 (29)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_rma_shift                  (25)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_rmb_shift                  (21)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_testrwm_0_shift            (17)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_bist_fail_0_shift          (9)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_drf_bist_fail_0_shift      (0)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_ls_mask                    (0x80000000)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_rmea_mask                  (0x40000000)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_rmeb_mask                  (0x20000000)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_rma_mask                   (0x1E000000)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_rmb_mask                   (0x01E00000)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_testrwm_0_mask             (0x00020000)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_bist_fail_0_mask           (0x00000200)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_drf_bist_fail_0_mask       (0x00000001)
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_ls(data)                   (0x80000000&((data)<<31))
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_rmea(data)                 (0x40000000&((data)<<30))
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_rmeb(data)                 (0x20000000&((data)<<29))
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_rma(data)                  (0x1E000000&((data)<<25))
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_rmb(data)                  (0x01E00000&((data)<<21))
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_testrwm_0(data)            (0x00020000&((data)<<17))
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_bist_fail_0(data)          (0x00000200&((data)<<9))
#define  DMATO3DTABLE_dmato3dtable_MBIST_dmato3dtable_drf_bist_fail_0(data)      (0x00000001&(data))
#define  DMATO3DTABLE_dmato3dtable_MBIST_get_dmato3dtable_ls(data)               ((0x80000000&(data))>>31)
#define  DMATO3DTABLE_dmato3dtable_MBIST_get_dmato3dtable_rmea(data)             ((0x40000000&(data))>>30)
#define  DMATO3DTABLE_dmato3dtable_MBIST_get_dmato3dtable_rmeb(data)             ((0x20000000&(data))>>29)
#define  DMATO3DTABLE_dmato3dtable_MBIST_get_dmato3dtable_rma(data)              ((0x1E000000&(data))>>25)
#define  DMATO3DTABLE_dmato3dtable_MBIST_get_dmato3dtable_rmb(data)              ((0x01E00000&(data))>>21)
#define  DMATO3DTABLE_dmato3dtable_MBIST_get_dmato3dtable_testrwm_0(data)        ((0x00020000&(data))>>17)
#define  DMATO3DTABLE_dmato3dtable_MBIST_get_dmato3dtable_bist_fail_0(data)      ((0x00000200&(data))>>9)
#define  DMATO3DTABLE_dmato3dtable_MBIST_get_dmato3dtable_drf_bist_fail_0(data)  (0x00000001&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0                                0x1806BD24
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_reg_addr                       "0xB806BD24"
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_reg                            0xB806BD24
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_inst_addr                      "0x0009"
#define  set_DMATO3DTABLE_DMAto3DTable_Table0_Format0_reg(data)                  (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_Format0_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table0_Format0_reg                        (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_Format0_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_table0_dma_en_shift            (31)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_table0_bitwidth_shift          (24)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_table0_num_y_shift             (16)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_table0_num_x_shift             (0)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_table0_dma_en_mask             (0x80000000)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_table0_bitwidth_mask           (0x7F000000)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_table0_num_y_mask              (0x00FF0000)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_table0_num_x_mask              (0x0000FFFF)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_table0_dma_en(data)            (0x80000000&((data)<<31))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_table0_bitwidth(data)          (0x7F000000&((data)<<24))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_table0_num_y(data)             (0x00FF0000&((data)<<16))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_table0_num_x(data)             (0x0000FFFF&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_get_table0_dma_en(data)        ((0x80000000&(data))>>31)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_get_table0_bitwidth(data)      ((0x7F000000&(data))>>24)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_get_table0_num_y(data)         ((0x00FF0000&(data))>>16)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format0_get_table0_num_x(data)         (0x0000FFFF&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1                                0x1806BD28
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_reg_addr                       "0xB806BD28"
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_reg                            0xB806BD28
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_inst_addr                      "0x000A"
#define  set_DMATO3DTABLE_DMAto3DTable_Table0_Format1_reg(data)                  (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_Format1_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table0_Format1_reg                        (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_Format1_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_table0_id_shift                (16)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_table0_burst_len_shift         (8)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_table0_num_z_shift             (0)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_table0_id_mask                 (0x000F0000)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_table0_burst_len_mask          (0x00007F00)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_table0_num_z_mask              (0x000000FF)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_table0_id(data)                (0x000F0000&((data)<<16))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_table0_burst_len(data)         (0x00007F00&((data)<<8))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_table0_num_z(data)             (0x000000FF&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_get_table0_id(data)            ((0x000F0000&(data))>>16)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_get_table0_burst_len(data)     ((0x00007F00&(data))>>8)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Format1_get_table0_num_z(data)         (0x000000FF&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table0_Burst                                  0x1806BD2C
#define  DMATO3DTABLE_DMAto3DTable_Table0_Burst_reg_addr                         "0xB806BD2C"
#define  DMATO3DTABLE_DMAto3DTable_Table0_Burst_reg                              0xB806BD2C
#define  DMATO3DTABLE_DMAto3DTable_Table0_Burst_inst_addr                        "0x000B"
#define  set_DMATO3DTABLE_DMAto3DTable_Table0_Burst_reg(data)                    (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_Burst_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table0_Burst_reg                          (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_Burst_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Burst_table0_burst_num_shift           (0)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Burst_table0_burst_num_mask            (0xFFFFFFFF)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Burst_table0_burst_num(data)           (0xFFFFFFFF&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Burst_get_table0_burst_num(data)       (0xFFFFFFFF&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table0_Addr                                   0x1806BD30
#define  DMATO3DTABLE_DMAto3DTable_Table0_Addr_reg_addr                          "0xB806BD30"
#define  DMATO3DTABLE_DMAto3DTable_Table0_Addr_reg                               0xB806BD30
#define  DMATO3DTABLE_DMAto3DTable_Table0_Addr_inst_addr                         "0x000C"
#define  set_DMATO3DTABLE_DMAto3DTable_Table0_Addr_reg(data)                     (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_Addr_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table0_Addr_reg                           (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_Addr_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Addr_table0_mstart_shift               (4)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Addr_table0_mstart_mask                (0xFFFFFFF0)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Addr_table0_mstart(data)               (0xFFFFFFF0&((data)<<4))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Addr_get_table0_mstart(data)           ((0xFFFFFFF0&(data))>>4)

#define  DMATO3DTABLE_DMAto3DTable_Table0_DMA                                    0x1806BD34
#define  DMATO3DTABLE_DMAto3DTable_Table0_DMA_reg_addr                           "0xB806BD34"
#define  DMATO3DTABLE_DMAto3DTable_Table0_DMA_reg                                0xB806BD34
#define  DMATO3DTABLE_DMAto3DTable_Table0_DMA_inst_addr                          "0x000D"
#define  set_DMATO3DTABLE_DMAto3DTable_Table0_DMA_reg(data)                      (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_DMA_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table0_DMA_reg                            (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_DMA_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table0_DMA_table0_remain_shift                (0)
#define  DMATO3DTABLE_DMAto3DTable_Table0_DMA_table0_remain_mask                 (0x0000007F)
#define  DMATO3DTABLE_DMAto3DTable_Table0_DMA_table0_remain(data)                (0x0000007F&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table0_DMA_get_table0_remain(data)            (0x0000007F&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table0_Status                                 0x1806BD38
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_reg_addr                        "0xB806BD38"
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_reg                             0xB806BD38
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_inst_addr                       "0x000E"
#define  set_DMATO3DTABLE_DMAto3DTable_Table0_Status_reg(data)                   (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_Status_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table0_Status_reg                         (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_Status_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_wtable_frame_cnt_shift          (24)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_frame_act_shift                 (23)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_table0_wdone_shift              (0)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_wtable_frame_cnt_mask           (0xFF000000)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_frame_act_mask                  (0x00800000)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_table0_wdone_mask               (0x00000001)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_wtable_frame_cnt(data)          (0xFF000000&((data)<<24))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_frame_act(data)                 (0x00800000&((data)<<23))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_table0_wdone(data)              (0x00000001&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_get_wtable_frame_cnt(data)      ((0xFF000000&(data))>>24)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_get_frame_act(data)             ((0x00800000&(data))>>23)
#define  DMATO3DTABLE_DMAto3DTable_Table0_Status_get_table0_wdone(data)          (0x00000001&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq                          0x1806BD3C
#define  DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_reg_addr                 "0xB806BD3C"
#define  DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_reg                      0xB806BD3C
#define  DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_inst_addr                "0x000F"
#define  set_DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_reg(data)            (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_reg                  (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_table0_status2irq_en_shift (16)
#define  DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_table0_err_status_shift  (0)
#define  DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_table0_status2irq_en_mask (0x007F0000)
#define  DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_table0_err_status_mask   (0x0000007F)
#define  DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_table0_status2irq_en(data) (0x007F0000&((data)<<16))
#define  DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_table0_err_status(data)  (0x0000007F&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_get_table0_status2irq_en(data) ((0x007F0000&(data))>>16)
#define  DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_get_table0_err_status(data) (0x0000007F&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0                                0x1806BD40
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_reg_addr                       "0xB806BD40"
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_reg                            0xB806BD40
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_inst_addr                      "0x0010"
#define  set_DMATO3DTABLE_DMAto3DTable_Table1_Format0_reg(data)                  (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_Format0_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table1_Format0_reg                        (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_Format0_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_table1_dma_en_shift            (31)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_table1_bitwidth_shift          (24)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_table1_num_y_shift             (16)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_table1_num_x_shift             (0)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_table1_dma_en_mask             (0x80000000)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_table1_bitwidth_mask           (0x7F000000)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_table1_num_y_mask              (0x00FF0000)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_table1_num_x_mask              (0x0000FFFF)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_table1_dma_en(data)            (0x80000000&((data)<<31))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_table1_bitwidth(data)          (0x7F000000&((data)<<24))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_table1_num_y(data)             (0x00FF0000&((data)<<16))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_table1_num_x(data)             (0x0000FFFF&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_get_table1_dma_en(data)        ((0x80000000&(data))>>31)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_get_table1_bitwidth(data)      ((0x7F000000&(data))>>24)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_get_table1_num_y(data)         ((0x00FF0000&(data))>>16)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format0_get_table1_num_x(data)         (0x0000FFFF&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1                                0x1806BD44
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_reg_addr                       "0xB806BD44"
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_reg                            0xB806BD44
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_inst_addr                      "0x0011"
#define  set_DMATO3DTABLE_DMAto3DTable_Table1_Format1_reg(data)                  (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_Format1_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table1_Format1_reg                        (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_Format1_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_table1_id_shift                (16)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_table1_burst_len_shift         (8)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_table1_num_z_shift             (0)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_table1_id_mask                 (0x000F0000)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_table1_burst_len_mask          (0x00007F00)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_table1_num_z_mask              (0x000000FF)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_table1_id(data)                (0x000F0000&((data)<<16))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_table1_burst_len(data)         (0x00007F00&((data)<<8))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_table1_num_z(data)             (0x000000FF&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_get_table1_id(data)            ((0x000F0000&(data))>>16)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_get_table1_burst_len(data)     ((0x00007F00&(data))>>8)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Format1_get_table1_num_z(data)         (0x000000FF&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table1_Burst                                  0x1806BD48
#define  DMATO3DTABLE_DMAto3DTable_Table1_Burst_reg_addr                         "0xB806BD48"
#define  DMATO3DTABLE_DMAto3DTable_Table1_Burst_reg                              0xB806BD48
#define  DMATO3DTABLE_DMAto3DTable_Table1_Burst_inst_addr                        "0x0012"
#define  set_DMATO3DTABLE_DMAto3DTable_Table1_Burst_reg(data)                    (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_Burst_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table1_Burst_reg                          (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_Burst_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Burst_table1_burst_num_shift           (0)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Burst_table1_burst_num_mask            (0xFFFFFFFF)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Burst_table1_burst_num(data)           (0xFFFFFFFF&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Burst_get_table1_burst_num(data)       (0xFFFFFFFF&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table1_Addr                                   0x1806BD4C
#define  DMATO3DTABLE_DMAto3DTable_Table1_Addr_reg_addr                          "0xB806BD4C"
#define  DMATO3DTABLE_DMAto3DTable_Table1_Addr_reg                               0xB806BD4C
#define  DMATO3DTABLE_DMAto3DTable_Table1_Addr_inst_addr                         "0x0013"
#define  set_DMATO3DTABLE_DMAto3DTable_Table1_Addr_reg(data)                     (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_Addr_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table1_Addr_reg                           (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_Addr_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Addr_table1_mstart_shift               (4)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Addr_table1_mstart_mask                (0xFFFFFFF0)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Addr_table1_mstart(data)               (0xFFFFFFF0&((data)<<4))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Addr_get_table1_mstart(data)           ((0xFFFFFFF0&(data))>>4)

#define  DMATO3DTABLE_DMAto3DTable_Table1_DMA                                    0x1806BD50
#define  DMATO3DTABLE_DMAto3DTable_Table1_DMA_reg_addr                           "0xB806BD50"
#define  DMATO3DTABLE_DMAto3DTable_Table1_DMA_reg                                0xB806BD50
#define  DMATO3DTABLE_DMAto3DTable_Table1_DMA_inst_addr                          "0x0014"
#define  set_DMATO3DTABLE_DMAto3DTable_Table1_DMA_reg(data)                      (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_DMA_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table1_DMA_reg                            (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_DMA_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table1_DMA_table1_remain_shift                (0)
#define  DMATO3DTABLE_DMAto3DTable_Table1_DMA_table1_remain_mask                 (0x0000007F)
#define  DMATO3DTABLE_DMAto3DTable_Table1_DMA_table1_remain(data)                (0x0000007F&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table1_DMA_get_table1_remain(data)            (0x0000007F&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table1_Status                                 0x1806BD54
#define  DMATO3DTABLE_DMAto3DTable_Table1_Status_reg_addr                        "0xB806BD54"
#define  DMATO3DTABLE_DMAto3DTable_Table1_Status_reg                             0xB806BD54
#define  DMATO3DTABLE_DMAto3DTable_Table1_Status_inst_addr                       "0x0015"
#define  set_DMATO3DTABLE_DMAto3DTable_Table1_Status_reg(data)                   (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_Status_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table1_Status_reg                         (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_Status_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Status_table1_wdone_shift              (0)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Status_table1_wdone_mask               (0x00000001)
#define  DMATO3DTABLE_DMAto3DTable_Table1_Status_table1_wdone(data)              (0x00000001&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table1_Status_get_table1_wdone(data)          (0x00000001&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq                          0x1806BD58
#define  DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_reg_addr                 "0xB806BD58"
#define  DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_reg                      0xB806BD58
#define  DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_inst_addr                "0x0016"
#define  set_DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_reg(data)            (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_reg                  (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_table1_status2irq_en_shift (16)
#define  DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_table1_err_status_shift  (0)
#define  DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_table1_status2irq_en_mask (0x007F0000)
#define  DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_table1_err_status_mask   (0x0000007F)
#define  DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_table1_status2irq_en(data) (0x007F0000&((data)<<16))
#define  DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_table1_err_status(data)  (0x0000007F&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_get_table1_status2irq_en(data) ((0x007F0000&(data))>>16)
#define  DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_get_table1_err_status(data) (0x0000007F&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0                                0x1806BD5C
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_reg_addr                       "0xB806BD5C"
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_reg                            0xB806BD5C
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_inst_addr                      "0x0017"
#define  set_DMATO3DTABLE_DMAto3DTable_Table2_Format0_reg(data)                  (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_Format0_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table2_Format0_reg                        (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_Format0_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_table2_dma_en_shift            (31)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_table2_bitwidth_shift          (24)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_table2_num_y_shift             (16)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_table2_num_x_shift             (0)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_table2_dma_en_mask             (0x80000000)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_table2_bitwidth_mask           (0x7F000000)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_table2_num_y_mask              (0x00FF0000)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_table2_num_x_mask              (0x0000FFFF)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_table2_dma_en(data)            (0x80000000&((data)<<31))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_table2_bitwidth(data)          (0x7F000000&((data)<<24))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_table2_num_y(data)             (0x00FF0000&((data)<<16))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_table2_num_x(data)             (0x0000FFFF&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_get_table2_dma_en(data)        ((0x80000000&(data))>>31)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_get_table2_bitwidth(data)      ((0x7F000000&(data))>>24)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_get_table2_num_y(data)         ((0x00FF0000&(data))>>16)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format0_get_table2_num_x(data)         (0x0000FFFF&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1                                0x1806BD60
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_reg_addr                       "0xB806BD60"
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_reg                            0xB806BD60
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_inst_addr                      "0x0018"
#define  set_DMATO3DTABLE_DMAto3DTable_Table2_Format1_reg(data)                  (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_Format1_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table2_Format1_reg                        (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_Format1_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_table2_id_shift                (16)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_table2_burst_len_shift         (8)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_table2_num_z_shift             (0)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_table2_id_mask                 (0x000F0000)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_table2_burst_len_mask          (0x00007F00)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_table2_num_z_mask              (0x000000FF)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_table2_id(data)                (0x000F0000&((data)<<16))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_table2_burst_len(data)         (0x00007F00&((data)<<8))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_table2_num_z(data)             (0x000000FF&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_get_table2_id(data)            ((0x000F0000&(data))>>16)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_get_table2_burst_len(data)     ((0x00007F00&(data))>>8)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Format1_get_table2_num_z(data)         (0x000000FF&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table2_Burst                                  0x1806BD64
#define  DMATO3DTABLE_DMAto3DTable_Table2_Burst_reg_addr                         "0xB806BD64"
#define  DMATO3DTABLE_DMAto3DTable_Table2_Burst_reg                              0xB806BD64
#define  DMATO3DTABLE_DMAto3DTable_Table2_Burst_inst_addr                        "0x0019"
#define  set_DMATO3DTABLE_DMAto3DTable_Table2_Burst_reg(data)                    (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_Burst_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table2_Burst_reg                          (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_Burst_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Burst_table2_burst_num_shift           (0)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Burst_table2_burst_num_mask            (0xFFFFFFFF)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Burst_table2_burst_num(data)           (0xFFFFFFFF&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Burst_get_table2_burst_num(data)       (0xFFFFFFFF&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table2_Addr                                   0x1806BD68
#define  DMATO3DTABLE_DMAto3DTable_Table2_Addr_reg_addr                          "0xB806BD68"
#define  DMATO3DTABLE_DMAto3DTable_Table2_Addr_reg                               0xB806BD68
#define  DMATO3DTABLE_DMAto3DTable_Table2_Addr_inst_addr                         "0x001A"
#define  set_DMATO3DTABLE_DMAto3DTable_Table2_Addr_reg(data)                     (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_Addr_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table2_Addr_reg                           (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_Addr_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Addr_table2_mstart_shift               (4)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Addr_table2_mstart_mask                (0xFFFFFFF0)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Addr_table2_mstart(data)               (0xFFFFFFF0&((data)<<4))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Addr_get_table2_mstart(data)           ((0xFFFFFFF0&(data))>>4)

#define  DMATO3DTABLE_DMAto3DTable_Table2_DMA                                    0x1806BD6C
#define  DMATO3DTABLE_DMAto3DTable_Table2_DMA_reg_addr                           "0xB806BD6C"
#define  DMATO3DTABLE_DMAto3DTable_Table2_DMA_reg                                0xB806BD6C
#define  DMATO3DTABLE_DMAto3DTable_Table2_DMA_inst_addr                          "0x001B"
#define  set_DMATO3DTABLE_DMAto3DTable_Table2_DMA_reg(data)                      (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_DMA_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table2_DMA_reg                            (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_DMA_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table2_DMA_table2_remain_shift                (0)
#define  DMATO3DTABLE_DMAto3DTable_Table2_DMA_table2_remain_mask                 (0x0000007F)
#define  DMATO3DTABLE_DMAto3DTable_Table2_DMA_table2_remain(data)                (0x0000007F&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table2_DMA_get_table2_remain(data)            (0x0000007F&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table2_Status                                 0x1806BD70
#define  DMATO3DTABLE_DMAto3DTable_Table2_Status_reg_addr                        "0xB806BD70"
#define  DMATO3DTABLE_DMAto3DTable_Table2_Status_reg                             0xB806BD70
#define  DMATO3DTABLE_DMAto3DTable_Table2_Status_inst_addr                       "0x001C"
#define  set_DMATO3DTABLE_DMAto3DTable_Table2_Status_reg(data)                   (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_Status_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table2_Status_reg                         (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_Status_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Status_table2_wdone_shift              (0)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Status_table2_wdone_mask               (0x00000001)
#define  DMATO3DTABLE_DMAto3DTable_Table2_Status_table2_wdone(data)              (0x00000001&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table2_Status_get_table2_wdone(data)          (0x00000001&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq                          0x1806BD74
#define  DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_reg_addr                 "0xB806BD74"
#define  DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_reg                      0xB806BD74
#define  DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_inst_addr                "0x001D"
#define  set_DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_reg(data)            (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_reg                  (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_table2_status2irq_en_shift (16)
#define  DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_table2_err_status_shift  (0)
#define  DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_table2_status2irq_en_mask (0x007F0000)
#define  DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_table2_err_status_mask   (0x0000007F)
#define  DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_table2_status2irq_en(data) (0x007F0000&((data)<<16))
#define  DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_table2_err_status(data)  (0x0000007F&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_get_table2_status2irq_en(data) ((0x007F0000&(data))>>16)
#define  DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_get_table2_err_status(data) (0x0000007F&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0                                0x1806BD78
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_reg_addr                       "0xB806BD78"
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_reg                            0xB806BD78
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_inst_addr                      "0x001E"
#define  set_DMATO3DTABLE_DMAto3DTable_Table3_Format0_reg(data)                  (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_Format0_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table3_Format0_reg                        (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_Format0_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_table3_dma_en_shift            (31)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_table3_bitwidth_shift          (24)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_table3_num_y_shift             (16)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_table3_num_x_shift             (0)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_table3_dma_en_mask             (0x80000000)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_table3_bitwidth_mask           (0x7F000000)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_table3_num_y_mask              (0x00FF0000)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_table3_num_x_mask              (0x0000FFFF)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_table3_dma_en(data)            (0x80000000&((data)<<31))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_table3_bitwidth(data)          (0x7F000000&((data)<<24))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_table3_num_y(data)             (0x00FF0000&((data)<<16))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_table3_num_x(data)             (0x0000FFFF&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_get_table3_dma_en(data)        ((0x80000000&(data))>>31)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_get_table3_bitwidth(data)      ((0x7F000000&(data))>>24)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_get_table3_num_y(data)         ((0x00FF0000&(data))>>16)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format0_get_table3_num_x(data)         (0x0000FFFF&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1                                0x1806BD7C
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_reg_addr                       "0xB806BD7C"
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_reg                            0xB806BD7C
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_inst_addr                      "0x001F"
#define  set_DMATO3DTABLE_DMAto3DTable_Table3_Format1_reg(data)                  (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_Format1_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table3_Format1_reg                        (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_Format1_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_table3_id_shift                (16)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_table3_burst_len_shift         (8)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_table3_num_z_shift             (0)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_table3_id_mask                 (0x000F0000)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_table3_burst_len_mask          (0x00007F00)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_table3_num_z_mask              (0x000000FF)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_table3_id(data)                (0x000F0000&((data)<<16))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_table3_burst_len(data)         (0x00007F00&((data)<<8))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_table3_num_z(data)             (0x000000FF&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_get_table3_id(data)            ((0x000F0000&(data))>>16)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_get_table3_burst_len(data)     ((0x00007F00&(data))>>8)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Format1_get_table3_num_z(data)         (0x000000FF&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table3_Burst                                  0x1806BD80
#define  DMATO3DTABLE_DMAto3DTable_Table3_Burst_reg_addr                         "0xB806BD80"
#define  DMATO3DTABLE_DMAto3DTable_Table3_Burst_reg                              0xB806BD80
#define  DMATO3DTABLE_DMAto3DTable_Table3_Burst_inst_addr                        "0x0020"
#define  set_DMATO3DTABLE_DMAto3DTable_Table3_Burst_reg(data)                    (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_Burst_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table3_Burst_reg                          (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_Burst_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Burst_table3_burst_num_shift           (0)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Burst_table3_burst_num_mask            (0xFFFFFFFF)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Burst_table3_burst_num(data)           (0xFFFFFFFF&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Burst_get_table3_burst_num(data)       (0xFFFFFFFF&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table3_Addr                                   0x1806BD84
#define  DMATO3DTABLE_DMAto3DTable_Table3_Addr_reg_addr                          "0xB806BD84"
#define  DMATO3DTABLE_DMAto3DTable_Table3_Addr_reg                               0xB806BD84
#define  DMATO3DTABLE_DMAto3DTable_Table3_Addr_inst_addr                         "0x0021"
#define  set_DMATO3DTABLE_DMAto3DTable_Table3_Addr_reg(data)                     (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_Addr_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table3_Addr_reg                           (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_Addr_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Addr_table3_mstart_shift               (4)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Addr_table3_mstart_mask                (0xFFFFFFF0)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Addr_table3_mstart(data)               (0xFFFFFFF0&((data)<<4))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Addr_get_table3_mstart(data)           ((0xFFFFFFF0&(data))>>4)

#define  DMATO3DTABLE_DMAto3DTable_Table3_DMA                                    0x1806BD88
#define  DMATO3DTABLE_DMAto3DTable_Table3_DMA_reg_addr                           "0xB806BD88"
#define  DMATO3DTABLE_DMAto3DTable_Table3_DMA_reg                                0xB806BD88
#define  DMATO3DTABLE_DMAto3DTable_Table3_DMA_inst_addr                          "0x0022"
#define  set_DMATO3DTABLE_DMAto3DTable_Table3_DMA_reg(data)                      (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_DMA_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table3_DMA_reg                            (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_DMA_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table3_DMA_table3_remain_shift                (0)
#define  DMATO3DTABLE_DMAto3DTable_Table3_DMA_table3_remain_mask                 (0x0000007F)
#define  DMATO3DTABLE_DMAto3DTable_Table3_DMA_table3_remain(data)                (0x0000007F&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table3_DMA_get_table3_remain(data)            (0x0000007F&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table3_Status                                 0x1806BD8C
#define  DMATO3DTABLE_DMAto3DTable_Table3_Status_reg_addr                        "0xB806BD8C"
#define  DMATO3DTABLE_DMAto3DTable_Table3_Status_reg                             0xB806BD8C
#define  DMATO3DTABLE_DMAto3DTable_Table3_Status_inst_addr                       "0x0023"
#define  set_DMATO3DTABLE_DMAto3DTable_Table3_Status_reg(data)                   (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_Status_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table3_Status_reg                         (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_Status_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Status_table3_wdone_shift              (0)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Status_table3_wdone_mask               (0x00000001)
#define  DMATO3DTABLE_DMAto3DTable_Table3_Status_table3_wdone(data)              (0x00000001&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table3_Status_get_table3_wdone(data)          (0x00000001&(data))

#define  DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq                          0x1806BD90
#define  DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_reg_addr                 "0xB806BD90"
#define  DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_reg                      0xB806BD90
#define  DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_inst_addr                "0x0024"
#define  set_DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_reg(data)            (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_reg)=data)
#define  get_DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_reg                  (*((volatile unsigned int*)DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_reg))
#define  DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_table3_status2irq_en_shift (16)
#define  DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_table3_err_status_shift  (0)
#define  DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_table3_status2irq_en_mask (0x007F0000)
#define  DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_table3_err_status_mask   (0x0000007F)
#define  DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_table3_status2irq_en(data) (0x007F0000&((data)<<16))
#define  DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_table3_err_status(data)  (0x0000007F&(data))
#define  DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_get_table3_status2irq_en(data) ((0x007F0000&(data))>>16)
#define  DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_get_table3_err_status(data) (0x0000007F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DMATO3DTABLE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  dummy1806bd00_18_3:16;
        RBus_UInt32  db_read:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  wtable_apply:1;
    };
}dmato3dtable_dmato3dtable_db_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_up_limint:28;
        RBus_UInt32  res1:4;
    };
}dmato3dtable_cti_dma_rd_rule_check_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_low_limint:28;
        RBus_UInt32  res1:4;
    };
}dmato3dtable_cti_dma_rd_rule_check_low_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  max_outstanding:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  force_all_rst:1;
        RBus_UInt32  res3:1;
    };
}dmato3dtable_cti_dma_rd_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dma_cmd_water:3;
        RBus_UInt32  res2:6;
        RBus_UInt32  dma_data_water:6;
        RBus_UInt32  res3:5;
        RBus_UInt32  cur_outstanding:3;
        RBus_UInt32  res4:3;
        RBus_UInt32  soft_rst_before_cmd_finish:1;
        RBus_UInt32  soft_rst_with_data_left:1;
        RBus_UInt32  data_fifo_overflow_err:1;
        RBus_UInt32  exceed_range_err:1;
        RBus_UInt32  zero_length_err:1;
    };
}dmato3dtable_cti_dma_rd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ack_num_error:1;
        RBus_UInt32  last_no_ack_error:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  target_ack_num:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  last_ack_num:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  selected_bl:7;
    };
}dmato3dtable_cti_dma_rd_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  selected_addr:28;
        RBus_UInt32  res1:2;
        RBus_UInt32  addr_bl_sel:2;
    };
}dmato3dtable_cti_dma_rd_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  monitor_en:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  reach_thd:1;
        RBus_UInt32  monitor_thd:6;
        RBus_UInt32  res2:10;
        RBus_UInt32  lowest_water_level:6;
    };
}dmato3dtable_cti_dma_rd_water_monitor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmato3dtable_ls:1;
        RBus_UInt32  dmato3dtable_rmea:1;
        RBus_UInt32  dmato3dtable_rmeb:1;
        RBus_UInt32  dmato3dtable_rma:4;
        RBus_UInt32  dmato3dtable_rmb:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  dmato3dtable_testrwm_0:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  dmato3dtable_bist_fail_0:1;
        RBus_UInt32  res3:8;
        RBus_UInt32  dmato3dtable_drf_bist_fail_0:1;
    };
}dmato3dtable_dmato3dtable_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_dma_en:1;
        RBus_UInt32  table0_bitwidth:7;
        RBus_UInt32  table0_num_y:8;
        RBus_UInt32  table0_num_x:16;
    };
}dmato3dtable_dmato3dtable_table0_format0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  table0_id:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  table0_burst_len:7;
        RBus_UInt32  table0_num_z:8;
    };
}dmato3dtable_dmato3dtable_table0_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_burst_num:32;
    };
}dmato3dtable_dmato3dtable_table0_burst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_mstart:28;
        RBus_UInt32  res1:4;
    };
}dmato3dtable_dmato3dtable_table0_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  table0_remain:7;
    };
}dmato3dtable_dmato3dtable_table0_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wtable_frame_cnt:8;
        RBus_UInt32  frame_act:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  table0_wdone:1;
    };
}dmato3dtable_dmato3dtable_table0_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  table0_status2irq_en:7;
        RBus_UInt32  res2:9;
        RBus_UInt32  table0_err_status:7;
    };
}dmato3dtable_dmato3dtable_table0_errstatus2irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_dma_en:1;
        RBus_UInt32  table1_bitwidth:7;
        RBus_UInt32  table1_num_y:8;
        RBus_UInt32  table1_num_x:16;
    };
}dmato3dtable_dmato3dtable_table1_format0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  table1_id:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  table1_burst_len:7;
        RBus_UInt32  table1_num_z:8;
    };
}dmato3dtable_dmato3dtable_table1_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_burst_num:32;
    };
}dmato3dtable_dmato3dtable_table1_burst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_mstart:28;
        RBus_UInt32  res1:4;
    };
}dmato3dtable_dmato3dtable_table1_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  table1_remain:7;
    };
}dmato3dtable_dmato3dtable_table1_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  table1_wdone:1;
    };
}dmato3dtable_dmato3dtable_table1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  table1_status2irq_en:7;
        RBus_UInt32  res2:9;
        RBus_UInt32  table1_err_status:7;
    };
}dmato3dtable_dmato3dtable_table1_errstatus2irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table2_dma_en:1;
        RBus_UInt32  table2_bitwidth:7;
        RBus_UInt32  table2_num_y:8;
        RBus_UInt32  table2_num_x:16;
    };
}dmato3dtable_dmato3dtable_table2_format0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  table2_id:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  table2_burst_len:7;
        RBus_UInt32  table2_num_z:8;
    };
}dmato3dtable_dmato3dtable_table2_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table2_burst_num:32;
    };
}dmato3dtable_dmato3dtable_table2_burst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table2_mstart:28;
        RBus_UInt32  res1:4;
    };
}dmato3dtable_dmato3dtable_table2_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  table2_remain:7;
    };
}dmato3dtable_dmato3dtable_table2_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  table2_wdone:1;
    };
}dmato3dtable_dmato3dtable_table2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  table2_status2irq_en:7;
        RBus_UInt32  res2:9;
        RBus_UInt32  table2_err_status:7;
    };
}dmato3dtable_dmato3dtable_table2_errstatus2irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table3_dma_en:1;
        RBus_UInt32  table3_bitwidth:7;
        RBus_UInt32  table3_num_y:8;
        RBus_UInt32  table3_num_x:16;
    };
}dmato3dtable_dmato3dtable_table3_format0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  table3_id:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  table3_burst_len:7;
        RBus_UInt32  table3_num_z:8;
    };
}dmato3dtable_dmato3dtable_table3_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table3_burst_num:32;
    };
}dmato3dtable_dmato3dtable_table3_burst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table3_mstart:28;
        RBus_UInt32  res1:4;
    };
}dmato3dtable_dmato3dtable_table3_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  table3_remain:7;
    };
}dmato3dtable_dmato3dtable_table3_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  table3_wdone:1;
    };
}dmato3dtable_dmato3dtable_table3_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  table3_status2irq_en:7;
        RBus_UInt32  res2:9;
        RBus_UInt32  table3_err_status:7;
    };
}dmato3dtable_dmato3dtable_table3_errstatus2irq_RBUS;

#else //apply LITTLE_ENDIAN

//======DMATO3DTABLE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wtable_apply:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read:1;
        RBus_UInt32  dummy1806bd00_18_3:16;
        RBus_UInt32  res1:13;
    };
}dmato3dtable_dmato3dtable_db_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_up_limint:28;
    };
}dmato3dtable_cti_dma_rd_rule_check_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_low_limint:28;
    };
}dmato3dtable_cti_dma_rd_rule_check_low_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  force_all_rst:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  max_outstanding:2;
        RBus_UInt32  res3:22;
    };
}dmato3dtable_cti_dma_rd_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zero_length_err:1;
        RBus_UInt32  exceed_range_err:1;
        RBus_UInt32  data_fifo_overflow_err:1;
        RBus_UInt32  soft_rst_with_data_left:1;
        RBus_UInt32  soft_rst_before_cmd_finish:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cur_outstanding:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  dma_data_water:6;
        RBus_UInt32  res3:6;
        RBus_UInt32  dma_cmd_water:3;
        RBus_UInt32  res4:1;
    };
}dmato3dtable_cti_dma_rd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  selected_bl:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  last_ack_num:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  target_ack_num:7;
        RBus_UInt32  res3:7;
        RBus_UInt32  last_no_ack_error:1;
        RBus_UInt32  ack_num_error:1;
    };
}dmato3dtable_cti_dma_rd_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr_bl_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  selected_addr:28;
    };
}dmato3dtable_cti_dma_rd_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lowest_water_level:6;
        RBus_UInt32  res1:10;
        RBus_UInt32  monitor_thd:6;
        RBus_UInt32  reach_thd:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  monitor_en:1;
    };
}dmato3dtable_cti_dma_rd_water_monitor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmato3dtable_drf_bist_fail_0:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  dmato3dtable_bist_fail_0:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  dmato3dtable_testrwm_0:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  dmato3dtable_rmb:4;
        RBus_UInt32  dmato3dtable_rma:4;
        RBus_UInt32  dmato3dtable_rmeb:1;
        RBus_UInt32  dmato3dtable_rmea:1;
        RBus_UInt32  dmato3dtable_ls:1;
    };
}dmato3dtable_dmato3dtable_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_num_x:16;
        RBus_UInt32  table0_num_y:8;
        RBus_UInt32  table0_bitwidth:7;
        RBus_UInt32  table0_dma_en:1;
    };
}dmato3dtable_dmato3dtable_table0_format0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_num_z:8;
        RBus_UInt32  table0_burst_len:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  table0_id:4;
        RBus_UInt32  res2:12;
    };
}dmato3dtable_dmato3dtable_table0_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_burst_num:32;
    };
}dmato3dtable_dmato3dtable_table0_burst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  table0_mstart:28;
    };
}dmato3dtable_dmato3dtable_table0_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_remain:7;
        RBus_UInt32  res1:25;
    };
}dmato3dtable_dmato3dtable_table0_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_wdone:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  frame_act:1;
        RBus_UInt32  wtable_frame_cnt:8;
    };
}dmato3dtable_dmato3dtable_table0_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_err_status:7;
        RBus_UInt32  res1:9;
        RBus_UInt32  table0_status2irq_en:7;
        RBus_UInt32  res2:9;
    };
}dmato3dtable_dmato3dtable_table0_errstatus2irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_num_x:16;
        RBus_UInt32  table1_num_y:8;
        RBus_UInt32  table1_bitwidth:7;
        RBus_UInt32  table1_dma_en:1;
    };
}dmato3dtable_dmato3dtable_table1_format0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_num_z:8;
        RBus_UInt32  table1_burst_len:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  table1_id:4;
        RBus_UInt32  res2:12;
    };
}dmato3dtable_dmato3dtable_table1_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_burst_num:32;
    };
}dmato3dtable_dmato3dtable_table1_burst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  table1_mstart:28;
    };
}dmato3dtable_dmato3dtable_table1_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_remain:7;
        RBus_UInt32  res1:25;
    };
}dmato3dtable_dmato3dtable_table1_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_wdone:1;
        RBus_UInt32  res1:31;
    };
}dmato3dtable_dmato3dtable_table1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_err_status:7;
        RBus_UInt32  res1:9;
        RBus_UInt32  table1_status2irq_en:7;
        RBus_UInt32  res2:9;
    };
}dmato3dtable_dmato3dtable_table1_errstatus2irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table2_num_x:16;
        RBus_UInt32  table2_num_y:8;
        RBus_UInt32  table2_bitwidth:7;
        RBus_UInt32  table2_dma_en:1;
    };
}dmato3dtable_dmato3dtable_table2_format0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table2_num_z:8;
        RBus_UInt32  table2_burst_len:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  table2_id:4;
        RBus_UInt32  res2:12;
    };
}dmato3dtable_dmato3dtable_table2_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table2_burst_num:32;
    };
}dmato3dtable_dmato3dtable_table2_burst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  table2_mstart:28;
    };
}dmato3dtable_dmato3dtable_table2_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table2_remain:7;
        RBus_UInt32  res1:25;
    };
}dmato3dtable_dmato3dtable_table2_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table2_wdone:1;
        RBus_UInt32  res1:31;
    };
}dmato3dtable_dmato3dtable_table2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table2_err_status:7;
        RBus_UInt32  res1:9;
        RBus_UInt32  table2_status2irq_en:7;
        RBus_UInt32  res2:9;
    };
}dmato3dtable_dmato3dtable_table2_errstatus2irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table3_num_x:16;
        RBus_UInt32  table3_num_y:8;
        RBus_UInt32  table3_bitwidth:7;
        RBus_UInt32  table3_dma_en:1;
    };
}dmato3dtable_dmato3dtable_table3_format0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table3_num_z:8;
        RBus_UInt32  table3_burst_len:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  table3_id:4;
        RBus_UInt32  res2:12;
    };
}dmato3dtable_dmato3dtable_table3_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table3_burst_num:32;
    };
}dmato3dtable_dmato3dtable_table3_burst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  table3_mstart:28;
    };
}dmato3dtable_dmato3dtable_table3_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table3_remain:7;
        RBus_UInt32  res1:25;
    };
}dmato3dtable_dmato3dtable_table3_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table3_wdone:1;
        RBus_UInt32  res1:31;
    };
}dmato3dtable_dmato3dtable_table3_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table3_err_status:7;
        RBus_UInt32  res1:9;
        RBus_UInt32  table3_status2irq_en:7;
        RBus_UInt32  res2:9;
    };
}dmato3dtable_dmato3dtable_table3_errstatus2irq_RBUS;




#endif 


#endif 
