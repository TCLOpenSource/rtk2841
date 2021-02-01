/**
* @file Mac5-DesignSpec-D-Domain_DMAto3DLUT
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DMATO3DLUT_REG_H_
#define _RBUS_DMATO3DLUT_REG_H_

#include "rbus_types.h"



//  DMATO3DLUT Register Address
#define  DMATO3DLUT_DMAto3DLUT_db_ctl                                            0x18028900
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_reg_addr                                   "0xB8028900"
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_reg                                        0xB8028900
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_inst_addr                                  "0x0000"
#define  set_DMATO3DLUT_DMAto3DLUT_db_ctl_reg(data)                              (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_db_ctl_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_db_ctl_reg                                    (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_db_ctl_reg))
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_dummy_18_3_shift                           (3)
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_db_read_shift                              (2)
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_db_en_shift                                (1)
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_wtable_apply_shift                         (0)
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_dummy_18_3_mask                            (0x0007FFF8)
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_db_read_mask                               (0x00000004)
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_db_en_mask                                 (0x00000002)
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_wtable_apply_mask                          (0x00000001)
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_dummy_18_3(data)                           (0x0007FFF8&((data)<<3))
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_db_read(data)                              (0x00000004&((data)<<2))
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_db_en(data)                                (0x00000002&((data)<<1))
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_wtable_apply(data)                         (0x00000001&(data))
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_get_dummy_18_3(data)                       ((0x0007FFF8&(data))>>3)
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_get_db_read(data)                          ((0x00000004&(data))>>2)
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_get_db_en(data)                            ((0x00000002&(data))>>1)
#define  DMATO3DLUT_DMAto3DLUT_db_ctl_get_wtable_apply(data)                     (0x00000001&(data))

#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_up_d_domain                            0x18028904
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_up_d_domain_reg_addr                   "0xB8028904"
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_up_d_domain_reg                        0xB8028904
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_up_d_domain_inst_addr                  "0x0001"
#define  set_DMATO3DLUT_CTI_DMA_RD_Rule_check_up_d_domain_reg(data)              (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_Rule_check_up_d_domain_reg)=data)
#define  get_DMATO3DLUT_CTI_DMA_RD_Rule_check_up_d_domain_reg                    (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_Rule_check_up_d_domain_reg))
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_up_d_domain_dma_up_limit_shift         (4)
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_up_d_domain_dma_up_limit_mask          (0xFFFFFFF0)
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_up_d_domain_dma_up_limit(data)         (0xFFFFFFF0&((data)<<4))
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_up_d_domain_get_dma_up_limit(data)     ((0xFFFFFFF0&(data))>>4)

#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_low_d_domain                           0x18028908
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_low_d_domain_reg_addr                  "0xB8028908"
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_low_d_domain_reg                       0xB8028908
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_low_d_domain_inst_addr                 "0x0002"
#define  set_DMATO3DLUT_CTI_DMA_RD_Rule_check_low_d_domain_reg(data)             (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_Rule_check_low_d_domain_reg)=data)
#define  get_DMATO3DLUT_CTI_DMA_RD_Rule_check_low_d_domain_reg                   (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_Rule_check_low_d_domain_reg))
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_low_d_domain_dma_low_limit_shift       (4)
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_low_d_domain_dma_low_limit_mask        (0xFFFFFFF0)
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_low_d_domain_dma_low_limit(data)       (0xFFFFFFF0&((data)<<4))
#define  DMATO3DLUT_CTI_DMA_RD_Rule_check_low_d_domain_get_dma_low_limit(data)   ((0xFFFFFFF0&(data))>>4)

#define  DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain                                     0x1802890C
#define  DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_reg_addr                            "0xB802890C"
#define  DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_reg                                 0xB802890C
#define  DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_inst_addr                           "0x0003"
#define  set_DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_reg(data)                       (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_reg)=data)
#define  get_DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_reg                             (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_reg))
#define  DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_max_outstanding_shift               (8)
#define  DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_force_all_rst_shift                 (1)
#define  DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_max_outstanding_mask                (0x00000300)
#define  DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_force_all_rst_mask                  (0x00000002)
#define  DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_max_outstanding(data)               (0x00000300&((data)<<8))
#define  DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_force_all_rst(data)                 (0x00000002&((data)<<1))
#define  DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_get_max_outstanding(data)           ((0x00000300&(data))>>8)
#define  DMATO3DLUT_CTI_DMA_RD_Ctrl_d_domain_get_force_all_rst(data)             ((0x00000002&(data))>>1)

#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain                                   0x18028910
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_reg_addr                          "0xB8028910"
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_reg                               0xB8028910
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_inst_addr                         "0x0004"
#define  set_DMATO3DLUT_CTI_DMA_RD_status_d_domain_reg(data)                     (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_status_d_domain_reg)=data)
#define  get_DMATO3DLUT_CTI_DMA_RD_status_d_domain_reg                           (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_status_d_domain_reg))
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_dma_cmd_water_shift               (28)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_dma_data_water_shift              (16)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_cur_outstanding_shift             (8)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_soft_rst_before_cmd_finish_shift  (4)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_soft_rst_with_data_left_shift     (3)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_data_fifo_overflow_err_shift      (2)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_exceed_range_err_shift            (1)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_zero_length_err_shift             (0)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_dma_cmd_water_mask                (0x70000000)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_dma_data_water_mask               (0x003F0000)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_cur_outstanding_mask              (0x00000700)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_soft_rst_before_cmd_finish_mask   (0x00000010)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_soft_rst_with_data_left_mask      (0x00000008)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_data_fifo_overflow_err_mask       (0x00000004)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_exceed_range_err_mask             (0x00000002)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_zero_length_err_mask              (0x00000001)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_dma_cmd_water(data)               (0x70000000&((data)<<28))
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_dma_data_water(data)              (0x003F0000&((data)<<16))
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_cur_outstanding(data)             (0x00000700&((data)<<8))
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_soft_rst_before_cmd_finish(data)  (0x00000010&((data)<<4))
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_soft_rst_with_data_left(data)     (0x00000008&((data)<<3))
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_data_fifo_overflow_err(data)      (0x00000004&((data)<<2))
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_exceed_range_err(data)            (0x00000002&((data)<<1))
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_zero_length_err(data)             (0x00000001&(data))
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_get_dma_cmd_water(data)           ((0x70000000&(data))>>28)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_get_dma_data_water(data)          ((0x003F0000&(data))>>16)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_get_cur_outstanding(data)         ((0x00000700&(data))>>8)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_get_soft_rst_before_cmd_finish(data) ((0x00000010&(data))>>4)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_get_soft_rst_with_data_left(data) ((0x00000008&(data))>>3)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_get_data_fifo_overflow_err(data)  ((0x00000004&(data))>>2)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_get_exceed_range_err(data)        ((0x00000002&(data))>>1)
#define  DMATO3DLUT_CTI_DMA_RD_status_d_domain_get_zero_length_err(data)         (0x00000001&(data))

#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain                                  0x18028914
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_reg_addr                         "0xB8028914"
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_reg                              0xB8028914
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_inst_addr                        "0x0005"
#define  set_DMATO3DLUT_CTI_DMA_RD_status1_d_domain_reg(data)                    (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_status1_d_domain_reg)=data)
#define  get_DMATO3DLUT_CTI_DMA_RD_status1_d_domain_reg                          (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_status1_d_domain_reg))
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_ack_num_error_shift              (31)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_last_no_ack_error_shift          (30)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_target_ack_num_shift             (16)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_last_ack_num_shift               (8)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_selected_bl_shift                (0)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_ack_num_error_mask               (0x80000000)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_last_no_ack_error_mask           (0x40000000)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_target_ack_num_mask              (0x007F0000)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_last_ack_num_mask                (0x00007F00)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_selected_bl_mask                 (0x0000007F)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_ack_num_error(data)              (0x80000000&((data)<<31))
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_last_no_ack_error(data)          (0x40000000&((data)<<30))
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_target_ack_num(data)             (0x007F0000&((data)<<16))
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_last_ack_num(data)               (0x00007F00&((data)<<8))
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_selected_bl(data)                (0x0000007F&(data))
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_get_ack_num_error(data)          ((0x80000000&(data))>>31)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_get_last_no_ack_error(data)      ((0x40000000&(data))>>30)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_get_target_ack_num(data)         ((0x007F0000&(data))>>16)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_get_last_ack_num(data)           ((0x00007F00&(data))>>8)
#define  DMATO3DLUT_CTI_DMA_RD_status1_d_domain_get_selected_bl(data)            (0x0000007F&(data))

#define  DMATO3DLUT_CTI_DMA_RD_status2_d_domain                                  0x18028918
#define  DMATO3DLUT_CTI_DMA_RD_status2_d_domain_reg_addr                         "0xB8028918"
#define  DMATO3DLUT_CTI_DMA_RD_status2_d_domain_reg                              0xB8028918
#define  DMATO3DLUT_CTI_DMA_RD_status2_d_domain_inst_addr                        "0x0006"
#define  set_DMATO3DLUT_CTI_DMA_RD_status2_d_domain_reg(data)                    (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_status2_d_domain_reg)=data)
#define  get_DMATO3DLUT_CTI_DMA_RD_status2_d_domain_reg                          (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_status2_d_domain_reg))
#define  DMATO3DLUT_CTI_DMA_RD_status2_d_domain_selected_addr_shift              (4)
#define  DMATO3DLUT_CTI_DMA_RD_status2_d_domain_addr_bl_sel_shift                (0)
#define  DMATO3DLUT_CTI_DMA_RD_status2_d_domain_selected_addr_mask               (0xFFFFFFF0)
#define  DMATO3DLUT_CTI_DMA_RD_status2_d_domain_addr_bl_sel_mask                 (0x00000003)
#define  DMATO3DLUT_CTI_DMA_RD_status2_d_domain_selected_addr(data)              (0xFFFFFFF0&((data)<<4))
#define  DMATO3DLUT_CTI_DMA_RD_status2_d_domain_addr_bl_sel(data)                (0x00000003&(data))
#define  DMATO3DLUT_CTI_DMA_RD_status2_d_domain_get_selected_addr(data)          ((0xFFFFFFF0&(data))>>4)
#define  DMATO3DLUT_CTI_DMA_RD_status2_d_domain_get_addr_bl_sel(data)            (0x00000003&(data))

#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain                            0x1802891C
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_reg_addr                   "0xB802891C"
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_reg                        0xB802891C
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_inst_addr                  "0x0007"
#define  set_DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_reg(data)              (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_reg)=data)
#define  get_DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_reg                    (*((volatile unsigned int*)DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_reg))
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_monitor_en_shift           (31)
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_reach_thd_shift            (22)
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_monitor_thd_shift          (16)
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_lowest_water_level_shift   (0)
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_monitor_en_mask            (0x80000000)
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_reach_thd_mask             (0x00400000)
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_monitor_thd_mask           (0x003F0000)
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_lowest_water_level_mask    (0x0000003F)
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_monitor_en(data)           (0x80000000&((data)<<31))
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_reach_thd(data)            (0x00400000&((data)<<22))
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_monitor_thd(data)          (0x003F0000&((data)<<16))
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_lowest_water_level(data)   (0x0000003F&(data))
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_get_monitor_en(data)       ((0x80000000&(data))>>31)
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_get_reach_thd(data)        ((0x00400000&(data))>>22)
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_get_monitor_thd(data)      ((0x003F0000&(data))>>16)
#define  DMATO3DLUT_CTI_DMA_RD_Water_Monitor_d_domain_get_lowest_water_level(data) (0x0000003F&(data))

#define  DMATO3DLUT_dmato3dlut_MBIST                                             0x18028920
#define  DMATO3DLUT_dmato3dlut_MBIST_reg_addr                                    "0xB8028920"
#define  DMATO3DLUT_dmato3dlut_MBIST_reg                                         0xB8028920
#define  DMATO3DLUT_dmato3dlut_MBIST_inst_addr                                   "0x0008"
#define  set_DMATO3DLUT_dmato3dlut_MBIST_reg(data)                               (*((volatile unsigned int*)DMATO3DLUT_dmato3dlut_MBIST_reg)=data)
#define  get_DMATO3DLUT_dmato3dlut_MBIST_reg                                     (*((volatile unsigned int*)DMATO3DLUT_dmato3dlut_MBIST_reg))
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_ls_shift                         (31)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_rmea_shift                       (30)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_rmeb_shift                       (29)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_rma_shift                        (25)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_rmb_shift                        (21)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_testrwm_0_shift                  (17)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_bist_fail_0_shift                (9)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_drf_bist_fail_0_shift            (0)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_ls_mask                          (0x80000000)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_rmea_mask                        (0x40000000)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_rmeb_mask                        (0x20000000)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_rma_mask                         (0x1E000000)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_rmb_mask                         (0x01E00000)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_testrwm_0_mask                   (0x00020000)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_bist_fail_0_mask                 (0x00000200)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_drf_bist_fail_0_mask             (0x00000001)
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_ls(data)                         (0x80000000&((data)<<31))
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_rmea(data)                       (0x40000000&((data)<<30))
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_rmeb(data)                       (0x20000000&((data)<<29))
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_rma(data)                        (0x1E000000&((data)<<25))
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_rmb(data)                        (0x01E00000&((data)<<21))
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_testrwm_0(data)                  (0x00020000&((data)<<17))
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_bist_fail_0(data)                (0x00000200&((data)<<9))
#define  DMATO3DLUT_dmato3dlut_MBIST_dmato3dlut_drf_bist_fail_0(data)            (0x00000001&(data))
#define  DMATO3DLUT_dmato3dlut_MBIST_get_dmato3dlut_ls(data)                     ((0x80000000&(data))>>31)
#define  DMATO3DLUT_dmato3dlut_MBIST_get_dmato3dlut_rmea(data)                   ((0x40000000&(data))>>30)
#define  DMATO3DLUT_dmato3dlut_MBIST_get_dmato3dlut_rmeb(data)                   ((0x20000000&(data))>>29)
#define  DMATO3DLUT_dmato3dlut_MBIST_get_dmato3dlut_rma(data)                    ((0x1E000000&(data))>>25)
#define  DMATO3DLUT_dmato3dlut_MBIST_get_dmato3dlut_rmb(data)                    ((0x01E00000&(data))>>21)
#define  DMATO3DLUT_dmato3dlut_MBIST_get_dmato3dlut_testrwm_0(data)              ((0x00020000&(data))>>17)
#define  DMATO3DLUT_dmato3dlut_MBIST_get_dmato3dlut_bist_fail_0(data)            ((0x00000200&(data))>>9)
#define  DMATO3DLUT_dmato3dlut_MBIST_get_dmato3dlut_drf_bist_fail_0(data)        (0x00000001&(data))

#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0                                    0x18028924
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_reg_addr                           "0xB8028924"
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_reg                                0xB8028924
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_inst_addr                          "0x0009"
#define  set_DMATO3DLUT_DMAto3DLUT_Table0_Format0_reg(data)                      (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_Format0_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table0_Format0_reg                            (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_Format0_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_table0_dma_en_shift                (31)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_table0_bitwidth_shift              (24)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_table0_num_y_shift                 (16)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_table0_num_x_shift                 (0)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_table0_dma_en_mask                 (0x80000000)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_table0_bitwidth_mask               (0x7F000000)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_table0_num_y_mask                  (0x00FF0000)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_table0_num_x_mask                  (0x0000FFFF)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_table0_dma_en(data)                (0x80000000&((data)<<31))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_table0_bitwidth(data)              (0x7F000000&((data)<<24))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_table0_num_y(data)                 (0x00FF0000&((data)<<16))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_table0_num_x(data)                 (0x0000FFFF&(data))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_get_table0_dma_en(data)            ((0x80000000&(data))>>31)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_get_table0_bitwidth(data)          ((0x7F000000&(data))>>24)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_get_table0_num_y(data)             ((0x00FF0000&(data))>>16)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format0_get_table0_num_x(data)             (0x0000FFFF&(data))

#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1                                    0x18028928
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_reg_addr                           "0xB8028928"
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_reg                                0xB8028928
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_inst_addr                          "0x000A"
#define  set_DMATO3DLUT_DMAto3DLUT_Table0_Format1_reg(data)                      (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_Format1_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table0_Format1_reg                            (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_Format1_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_table0_id_shift                    (16)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_table0_burst_len_shift             (8)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_table0_num_z_shift                 (0)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_table0_id_mask                     (0x000F0000)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_table0_burst_len_mask              (0x00007F00)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_table0_num_z_mask                  (0x000000FF)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_table0_id(data)                    (0x000F0000&((data)<<16))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_table0_burst_len(data)             (0x00007F00&((data)<<8))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_table0_num_z(data)                 (0x000000FF&(data))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_get_table0_id(data)                ((0x000F0000&(data))>>16)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_get_table0_burst_len(data)         ((0x00007F00&(data))>>8)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Format1_get_table0_num_z(data)             (0x000000FF&(data))

#define  DMATO3DLUT_DMAto3DLUT_Table0_Burst                                      0x1802892C
#define  DMATO3DLUT_DMAto3DLUT_Table0_Burst_reg_addr                             "0xB802892C"
#define  DMATO3DLUT_DMAto3DLUT_Table0_Burst_reg                                  0xB802892C
#define  DMATO3DLUT_DMAto3DLUT_Table0_Burst_inst_addr                            "0x000B"
#define  set_DMATO3DLUT_DMAto3DLUT_Table0_Burst_reg(data)                        (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_Burst_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table0_Burst_reg                              (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_Burst_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Burst_table0_burst_num_shift               (0)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Burst_table0_burst_num_mask                (0xFFFFFFFF)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Burst_table0_burst_num(data)               (0xFFFFFFFF&(data))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Burst_get_table0_burst_num(data)           (0xFFFFFFFF&(data))

#define  DMATO3DLUT_DMAto3DLUT_Table0_Addr                                       0x18028930
#define  DMATO3DLUT_DMAto3DLUT_Table0_Addr_reg_addr                              "0xB8028930"
#define  DMATO3DLUT_DMAto3DLUT_Table0_Addr_reg                                   0xB8028930
#define  DMATO3DLUT_DMAto3DLUT_Table0_Addr_inst_addr                             "0x000C"
#define  set_DMATO3DLUT_DMAto3DLUT_Table0_Addr_reg(data)                         (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_Addr_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table0_Addr_reg                               (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_Addr_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Addr_table0_mstart_shift                   (4)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Addr_table0_mstart_mask                    (0xFFFFFFF0)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Addr_table0_mstart(data)                   (0xFFFFFFF0&((data)<<4))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Addr_get_table0_mstart(data)               ((0xFFFFFFF0&(data))>>4)

#define  DMATO3DLUT_DMAto3DLUT_Table0_DMA                                        0x18028934
#define  DMATO3DLUT_DMAto3DLUT_Table0_DMA_reg_addr                               "0xB8028934"
#define  DMATO3DLUT_DMAto3DLUT_Table0_DMA_reg                                    0xB8028934
#define  DMATO3DLUT_DMAto3DLUT_Table0_DMA_inst_addr                              "0x000D"
#define  set_DMATO3DLUT_DMAto3DLUT_Table0_DMA_reg(data)                          (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_DMA_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table0_DMA_reg                                (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_DMA_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table0_DMA_table0_remain_shift                    (0)
#define  DMATO3DLUT_DMAto3DLUT_Table0_DMA_table0_remain_mask                     (0x0000007F)
#define  DMATO3DLUT_DMAto3DLUT_Table0_DMA_table0_remain(data)                    (0x0000007F&(data))
#define  DMATO3DLUT_DMAto3DLUT_Table0_DMA_get_table0_remain(data)                (0x0000007F&(data))

#define  DMATO3DLUT_DMAto3DLUT_Table0_Status                                     0x18028938
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_reg_addr                            "0xB8028938"
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_reg                                 0xB8028938
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_inst_addr                           "0x000E"
#define  set_DMATO3DLUT_DMAto3DLUT_Table0_Status_reg(data)                       (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_Status_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table0_Status_reg                             (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_Status_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_wtable_frame_cnt_shift              (24)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_frame_act_shift                     (23)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_table0_wdone_shift                  (0)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_wtable_frame_cnt_mask               (0xFF000000)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_frame_act_mask                      (0x00800000)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_table0_wdone_mask                   (0x00000001)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_wtable_frame_cnt(data)              (0xFF000000&((data)<<24))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_frame_act(data)                     (0x00800000&((data)<<23))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_table0_wdone(data)                  (0x00000001&(data))
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_get_wtable_frame_cnt(data)          ((0xFF000000&(data))>>24)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_get_frame_act(data)                 ((0x00800000&(data))>>23)
#define  DMATO3DLUT_DMAto3DLUT_Table0_Status_get_table0_wdone(data)              (0x00000001&(data))

#define  DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq                              0x1802893C
#define  DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_reg_addr                     "0xB802893C"
#define  DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_reg                          0xB802893C
#define  DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_inst_addr                    "0x000F"
#define  set_DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_reg(data)                (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_reg                      (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_table0_status2irq_en_shift   (8)
#define  DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_table0_err_status_shift      (0)
#define  DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_table0_status2irq_en_mask    (0x00007F00)
#define  DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_table0_err_status_mask       (0x0000007F)
#define  DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_table0_status2irq_en(data)   (0x00007F00&((data)<<8))
#define  DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_table0_err_status(data)      (0x0000007F&(data))
#define  DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_get_table0_status2irq_en(data) ((0x00007F00&(data))>>8)
#define  DMATO3DLUT_DMAto3DLUT_Table0_ErrStatus2Irq_get_table0_err_status(data)  (0x0000007F&(data))

#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0                                    0x18028940
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_reg_addr                           "0xB8028940"
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_reg                                0xB8028940
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_inst_addr                          "0x0010"
#define  set_DMATO3DLUT_DMAto3DLUT_Table1_Format0_reg(data)                      (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_Format0_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table1_Format0_reg                            (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_Format0_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_table1_dma_en_shift                (31)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_table1_bitwidth_shift              (24)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_table1_num_y_shift                 (16)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_table1_num_x_shift                 (0)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_table1_dma_en_mask                 (0x80000000)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_table1_bitwidth_mask               (0x7F000000)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_table1_num_y_mask                  (0x00FF0000)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_table1_num_x_mask                  (0x0000FFFF)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_table1_dma_en(data)                (0x80000000&((data)<<31))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_table1_bitwidth(data)              (0x7F000000&((data)<<24))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_table1_num_y(data)                 (0x00FF0000&((data)<<16))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_table1_num_x(data)                 (0x0000FFFF&(data))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_get_table1_dma_en(data)            ((0x80000000&(data))>>31)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_get_table1_bitwidth(data)          ((0x7F000000&(data))>>24)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_get_table1_num_y(data)             ((0x00FF0000&(data))>>16)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format0_get_table1_num_x(data)             (0x0000FFFF&(data))

#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1                                    0x18028944
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_reg_addr                           "0xB8028944"
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_reg                                0xB8028944
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_inst_addr                          "0x0011"
#define  set_DMATO3DLUT_DMAto3DLUT_Table1_Format1_reg(data)                      (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_Format1_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table1_Format1_reg                            (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_Format1_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_table1_id_shift                    (16)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_table1_burst_len_shift             (8)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_table1_num_z_shift                 (0)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_table1_id_mask                     (0x000F0000)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_table1_burst_len_mask              (0x00007F00)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_table1_num_z_mask                  (0x000000FF)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_table1_id(data)                    (0x000F0000&((data)<<16))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_table1_burst_len(data)             (0x00007F00&((data)<<8))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_table1_num_z(data)                 (0x000000FF&(data))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_get_table1_id(data)                ((0x000F0000&(data))>>16)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_get_table1_burst_len(data)         ((0x00007F00&(data))>>8)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Format1_get_table1_num_z(data)             (0x000000FF&(data))

#define  DMATO3DLUT_DMAto3DLUT_Table1_Burst                                      0x18028948
#define  DMATO3DLUT_DMAto3DLUT_Table1_Burst_reg_addr                             "0xB8028948"
#define  DMATO3DLUT_DMAto3DLUT_Table1_Burst_reg                                  0xB8028948
#define  DMATO3DLUT_DMAto3DLUT_Table1_Burst_inst_addr                            "0x0012"
#define  set_DMATO3DLUT_DMAto3DLUT_Table1_Burst_reg(data)                        (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_Burst_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table1_Burst_reg                              (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_Burst_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Burst_table1_burst_num_shift               (0)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Burst_table1_burst_num_mask                (0xFFFFFFFF)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Burst_table1_burst_num(data)               (0xFFFFFFFF&(data))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Burst_get_table1_burst_num(data)           (0xFFFFFFFF&(data))

#define  DMATO3DLUT_DMAto3DLUT_Table1_Addr                                       0x1802894C
#define  DMATO3DLUT_DMAto3DLUT_Table1_Addr_reg_addr                              "0xB802894C"
#define  DMATO3DLUT_DMAto3DLUT_Table1_Addr_reg                                   0xB802894C
#define  DMATO3DLUT_DMAto3DLUT_Table1_Addr_inst_addr                             "0x0013"
#define  set_DMATO3DLUT_DMAto3DLUT_Table1_Addr_reg(data)                         (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_Addr_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table1_Addr_reg                               (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_Addr_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Addr_table1_mstart_shift                   (4)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Addr_table1_mstart_mask                    (0xFFFFFFF0)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Addr_table1_mstart(data)                   (0xFFFFFFF0&((data)<<4))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Addr_get_table1_mstart(data)               ((0xFFFFFFF0&(data))>>4)

#define  DMATO3DLUT_DMAto3DLUT_Table1_DMA                                        0x18028950
#define  DMATO3DLUT_DMAto3DLUT_Table1_DMA_reg_addr                               "0xB8028950"
#define  DMATO3DLUT_DMAto3DLUT_Table1_DMA_reg                                    0xB8028950
#define  DMATO3DLUT_DMAto3DLUT_Table1_DMA_inst_addr                              "0x0014"
#define  set_DMATO3DLUT_DMAto3DLUT_Table1_DMA_reg(data)                          (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_DMA_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table1_DMA_reg                                (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_DMA_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table1_DMA_table1_remain_shift                    (0)
#define  DMATO3DLUT_DMAto3DLUT_Table1_DMA_table1_remain_mask                     (0x0000007F)
#define  DMATO3DLUT_DMAto3DLUT_Table1_DMA_table1_remain(data)                    (0x0000007F&(data))
#define  DMATO3DLUT_DMAto3DLUT_Table1_DMA_get_table1_remain(data)                (0x0000007F&(data))

#define  DMATO3DLUT_DMAto3DLUT_Table1_Status                                     0x18028954
#define  DMATO3DLUT_DMAto3DLUT_Table1_Status_reg_addr                            "0xB8028954"
#define  DMATO3DLUT_DMAto3DLUT_Table1_Status_reg                                 0xB8028954
#define  DMATO3DLUT_DMAto3DLUT_Table1_Status_inst_addr                           "0x0015"
#define  set_DMATO3DLUT_DMAto3DLUT_Table1_Status_reg(data)                       (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_Status_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table1_Status_reg                             (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_Status_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Status_table1_wdone_shift                  (0)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Status_table1_wdone_mask                   (0x00000001)
#define  DMATO3DLUT_DMAto3DLUT_Table1_Status_table1_wdone(data)                  (0x00000001&(data))
#define  DMATO3DLUT_DMAto3DLUT_Table1_Status_get_table1_wdone(data)              (0x00000001&(data))

#define  DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq                              0x18028958
#define  DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_reg_addr                     "0xB8028958"
#define  DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_reg                          0xB8028958
#define  DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_inst_addr                    "0x0016"
#define  set_DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_reg(data)                (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_reg)=data)
#define  get_DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_reg                      (*((volatile unsigned int*)DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_reg))
#define  DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_table1_status2irq_en_shift   (8)
#define  DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_table1_err_status_shift      (0)
#define  DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_table1_status2irq_en_mask    (0x00007F00)
#define  DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_table1_err_status_mask       (0x0000007F)
#define  DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_table1_status2irq_en(data)   (0x00007F00&((data)<<8))
#define  DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_table1_err_status(data)      (0x0000007F&(data))
#define  DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_get_table1_status2irq_en(data) ((0x00007F00&(data))>>8)
#define  DMATO3DLUT_DMAto3DLUT_Table1_ErrStatus2Irq_get_table1_err_status(data)  (0x0000007F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DMATO3DLUT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  dummy18028900_18_3:16;
        RBus_UInt32  db_read:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  wtable_apply:1;
    };
}dmato3dlut_dmato3dlut_db_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_up_limit:28;
        RBus_UInt32  res1:4;
    };
}dmato3dlut_cti_dma_rd_rule_check_up_d_domain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_low_limit:28;
        RBus_UInt32  res1:4;
    };
}dmato3dlut_cti_dma_rd_rule_check_low_d_domain_RBUS;

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
}dmato3dlut_cti_dma_rd_ctrl_d_domain_RBUS;

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
}dmato3dlut_cti_dma_rd_status_d_domain_RBUS;

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
}dmato3dlut_cti_dma_rd_status1_d_domain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  selected_addr:28;
        RBus_UInt32  res1:2;
        RBus_UInt32  addr_bl_sel:2;
    };
}dmato3dlut_cti_dma_rd_status2_d_domain_RBUS;

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
}dmato3dlut_cti_dma_rd_water_monitor_d_domain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmato3dlut_ls:1;
        RBus_UInt32  dmato3dlut_rmea:1;
        RBus_UInt32  dmato3dlut_rmeb:1;
        RBus_UInt32  dmato3dlut_rma:4;
        RBus_UInt32  dmato3dlut_rmb:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  dmato3dlut_testrwm_0:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  dmato3dlut_bist_fail_0:1;
        RBus_UInt32  res3:8;
        RBus_UInt32  dmato3dlut_drf_bist_fail_0:1;
    };
}dmato3dlut_dmato3dlut_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_dma_en:1;
        RBus_UInt32  table0_bitwidth:7;
        RBus_UInt32  table0_num_y:8;
        RBus_UInt32  table0_num_x:16;
    };
}dmato3dlut_dmato3dlut_table0_format0_RBUS;

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
}dmato3dlut_dmato3dlut_table0_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_burst_num:32;
    };
}dmato3dlut_dmato3dlut_table0_burst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_mstart:28;
        RBus_UInt32  res1:4;
    };
}dmato3dlut_dmato3dlut_table0_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  table0_remain:7;
    };
}dmato3dlut_dmato3dlut_table0_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wtable_frame_cnt:8;
        RBus_UInt32  frame_act:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  table0_wdone:1;
    };
}dmato3dlut_dmato3dlut_table0_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  table0_status2irq_en:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  table0_err_status:7;
    };
}dmato3dlut_dmato3dlut_table0_errstatus2irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_dma_en:1;
        RBus_UInt32  table1_bitwidth:7;
        RBus_UInt32  table1_num_y:8;
        RBus_UInt32  table1_num_x:16;
    };
}dmato3dlut_dmato3dlut_table1_format0_RBUS;

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
}dmato3dlut_dmato3dlut_table1_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_burst_num:32;
    };
}dmato3dlut_dmato3dlut_table1_burst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_mstart:28;
        RBus_UInt32  res1:4;
    };
}dmato3dlut_dmato3dlut_table1_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  table1_remain:7;
    };
}dmato3dlut_dmato3dlut_table1_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  table1_wdone:1;
    };
}dmato3dlut_dmato3dlut_table1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  table1_status2irq_en:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  table1_err_status:7;
    };
}dmato3dlut_dmato3dlut_table1_errstatus2irq_RBUS;

#else //apply LITTLE_ENDIAN

//======DMATO3DLUT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wtable_apply:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read:1;
        RBus_UInt32  dummy18028900_18_3:16;
        RBus_UInt32  res1:13;
    };
}dmato3dlut_dmato3dlut_db_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_up_limit:28;
    };
}dmato3dlut_cti_dma_rd_rule_check_up_d_domain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_low_limit:28;
    };
}dmato3dlut_cti_dma_rd_rule_check_low_d_domain_RBUS;

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
}dmato3dlut_cti_dma_rd_ctrl_d_domain_RBUS;

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
}dmato3dlut_cti_dma_rd_status_d_domain_RBUS;

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
}dmato3dlut_cti_dma_rd_status1_d_domain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr_bl_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  selected_addr:28;
    };
}dmato3dlut_cti_dma_rd_status2_d_domain_RBUS;

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
}dmato3dlut_cti_dma_rd_water_monitor_d_domain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmato3dlut_drf_bist_fail_0:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  dmato3dlut_bist_fail_0:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  dmato3dlut_testrwm_0:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  dmato3dlut_rmb:4;
        RBus_UInt32  dmato3dlut_rma:4;
        RBus_UInt32  dmato3dlut_rmeb:1;
        RBus_UInt32  dmato3dlut_rmea:1;
        RBus_UInt32  dmato3dlut_ls:1;
    };
}dmato3dlut_dmato3dlut_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_num_x:16;
        RBus_UInt32  table0_num_y:8;
        RBus_UInt32  table0_bitwidth:7;
        RBus_UInt32  table0_dma_en:1;
    };
}dmato3dlut_dmato3dlut_table0_format0_RBUS;

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
}dmato3dlut_dmato3dlut_table0_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_burst_num:32;
    };
}dmato3dlut_dmato3dlut_table0_burst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  table0_mstart:28;
    };
}dmato3dlut_dmato3dlut_table0_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_remain:7;
        RBus_UInt32  res1:25;
    };
}dmato3dlut_dmato3dlut_table0_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_wdone:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  frame_act:1;
        RBus_UInt32  wtable_frame_cnt:8;
    };
}dmato3dlut_dmato3dlut_table0_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table0_err_status:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  table0_status2irq_en:7;
        RBus_UInt32  res2:17;
    };
}dmato3dlut_dmato3dlut_table0_errstatus2irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_num_x:16;
        RBus_UInt32  table1_num_y:8;
        RBus_UInt32  table1_bitwidth:7;
        RBus_UInt32  table1_dma_en:1;
    };
}dmato3dlut_dmato3dlut_table1_format0_RBUS;

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
}dmato3dlut_dmato3dlut_table1_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_burst_num:32;
    };
}dmato3dlut_dmato3dlut_table1_burst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  table1_mstart:28;
    };
}dmato3dlut_dmato3dlut_table1_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_remain:7;
        RBus_UInt32  res1:25;
    };
}dmato3dlut_dmato3dlut_table1_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_wdone:1;
        RBus_UInt32  res1:31;
    };
}dmato3dlut_dmato3dlut_table1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table1_err_status:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  table1_status2irq_en:7;
        RBus_UInt32  res2:17;
    };
}dmato3dlut_dmato3dlut_table1_errstatus2irq_RBUS;




#endif 


#endif 
