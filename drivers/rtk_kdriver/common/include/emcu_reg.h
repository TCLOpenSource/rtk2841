/**
* @file rbusEMCUReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_EMCU_REG_H_
#define _RBUS_EMCU_REG_H_

#include "rbus_types.h"



//  EMCU Register Address
#define  EMCU_wrapper_8051                                                       0x18060400
#define  EMCU_wrapper_8051_reg_addr                                              "0xB8060400"
#define  EMCU_wrapper_8051_reg                                                   0xB8060400
#define  EMCU_wrapper_8051_inst_addr                                             "0x0000"
#define  set_EMCU_wrapper_8051_reg(data)                                         (*((volatile unsigned int*)EMCU_wrapper_8051_reg)=data)
#define  get_EMCU_wrapper_8051_reg                                               (*((volatile unsigned int*)EMCU_wrapper_8051_reg))
#define  EMCU_wrapper_8051_rbus_timeout_ip_shift                                 (28)
#define  EMCU_wrapper_8051_emcu_top_dbg_sel_shift                                (10)
#define  EMCU_wrapper_8051_dmem_dbg_sel_shift                                    (9)
#define  EMCU_wrapper_8051_imem_dbg_sel_shift                                    (8)
#define  EMCU_wrapper_8051_rbus_timeout_cycle_shift                              (5)
#define  EMCU_wrapper_8051_rbus_timeout_int_shift                                (4)
#define  EMCU_wrapper_8051_rbus_timeout_int_en_shift                             (3)
#define  EMCU_wrapper_8051_rbus_timeout_enable_shift                             (2)
#define  EMCU_wrapper_8051_endian_swap_shift                                     (1)
#define  EMCU_wrapper_8051_sleep_mode_shift                                      (0)
#define  EMCU_wrapper_8051_rbus_timeout_ip_mask                                  (0xF0000000)
#define  EMCU_wrapper_8051_emcu_top_dbg_sel_mask                                 (0x00001C00)
#define  EMCU_wrapper_8051_dmem_dbg_sel_mask                                     (0x00000200)
#define  EMCU_wrapper_8051_imem_dbg_sel_mask                                     (0x00000100)
#define  EMCU_wrapper_8051_rbus_timeout_cycle_mask                               (0x000000E0)
#define  EMCU_wrapper_8051_rbus_timeout_int_mask                                 (0x00000010)
#define  EMCU_wrapper_8051_rbus_timeout_int_en_mask                              (0x00000008)
#define  EMCU_wrapper_8051_rbus_timeout_enable_mask                              (0x00000004)
#define  EMCU_wrapper_8051_endian_swap_mask                                      (0x00000002)
#define  EMCU_wrapper_8051_sleep_mode_mask                                       (0x00000001)
#define  EMCU_wrapper_8051_rbus_timeout_ip(data)                                 (0xF0000000&((data)<<28))
#define  EMCU_wrapper_8051_emcu_top_dbg_sel(data)                                (0x00001C00&((data)<<10))
#define  EMCU_wrapper_8051_dmem_dbg_sel(data)                                    (0x00000200&((data)<<9))
#define  EMCU_wrapper_8051_imem_dbg_sel(data)                                    (0x00000100&((data)<<8))
#define  EMCU_wrapper_8051_rbus_timeout_cycle(data)                              (0x000000E0&((data)<<5))
#define  EMCU_wrapper_8051_rbus_timeout_int(data)                                (0x00000010&((data)<<4))
#define  EMCU_wrapper_8051_rbus_timeout_int_en(data)                             (0x00000008&((data)<<3))
#define  EMCU_wrapper_8051_rbus_timeout_enable(data)                             (0x00000004&((data)<<2))
#define  EMCU_wrapper_8051_endian_swap(data)                                     (0x00000002&((data)<<1))
#define  EMCU_wrapper_8051_sleep_mode(data)                                      (0x00000001&(data))
#define  EMCU_wrapper_8051_get_rbus_timeout_ip(data)                             ((0xF0000000&(data))>>28)
#define  EMCU_wrapper_8051_get_emcu_top_dbg_sel(data)                            ((0x00001C00&(data))>>10)
#define  EMCU_wrapper_8051_get_dmem_dbg_sel(data)                                ((0x00000200&(data))>>9)
#define  EMCU_wrapper_8051_get_imem_dbg_sel(data)                                ((0x00000100&(data))>>8)
#define  EMCU_wrapper_8051_get_rbus_timeout_cycle(data)                          ((0x000000E0&(data))>>5)
#define  EMCU_wrapper_8051_get_rbus_timeout_int(data)                            ((0x00000010&(data))>>4)
#define  EMCU_wrapper_8051_get_rbus_timeout_int_en(data)                         ((0x00000008&(data))>>3)
#define  EMCU_wrapper_8051_get_rbus_timeout_enable(data)                         ((0x00000004&(data))>>2)
#define  EMCU_wrapper_8051_get_endian_swap(data)                                 ((0x00000002&(data))>>1)
#define  EMCU_wrapper_8051_get_sleep_mode(data)                                  (0x00000001&(data))

#define  EMCU_emcu_debug_8051                                                    0x18060410
#define  EMCU_emcu_debug_8051_reg_addr                                           "0xB8060410"
#define  EMCU_emcu_debug_8051_reg                                                0xB8060410
#define  EMCU_emcu_debug_8051_inst_addr                                          "0x0001"
#define  set_EMCU_emcu_debug_8051_reg(data)                                      (*((volatile unsigned int*)EMCU_emcu_debug_8051_reg)=data)
#define  get_EMCU_emcu_debug_8051_reg                                            (*((volatile unsigned int*)EMCU_emcu_debug_8051_reg))
#define  EMCU_emcu_debug_8051_dummy_31_0_shift                                   (0)
#define  EMCU_emcu_debug_8051_dummy_31_0_mask                                    (0xFFFFFFFF)
#define  EMCU_emcu_debug_8051_dummy_31_0(data)                                   (0xFFFFFFFF&(data))
#define  EMCU_emcu_debug_8051_get_dummy_31_0(data)                               (0xFFFFFFFF&(data))

#define  EMCU_MCU_MEM_RME                                                        0x18060414
#define  EMCU_MCU_MEM_RME_reg_addr                                               "0xB8060414"
#define  EMCU_MCU_MEM_RME_reg                                                    0xB8060414
#define  EMCU_MCU_MEM_RME_inst_addr                                              "0x0002"
#define  set_EMCU_MCU_MEM_RME_reg(data)                                          (*((volatile unsigned int*)EMCU_MCU_MEM_RME_reg)=data)
#define  get_EMCU_MCU_MEM_RME_reg                                                (*((volatile unsigned int*)EMCU_MCU_MEM_RME_reg))
#define  EMCU_MCU_MEM_RME_mcu_always_on_dmem_rme_shift                           (5)
#define  EMCU_MCU_MEM_RME_mcu_always_on_imem_rme_shift                           (4)
#define  EMCU_MCU_MEM_RME_mcu_shmem_rme_shift                                    (3)
#define  EMCU_MCU_MEM_RME_mcu_iram_rme_shift                                     (2)
#define  EMCU_MCU_MEM_RME_mcu_imem_rme_shift                                     (1)
#define  EMCU_MCU_MEM_RME_mcu_dmem_rme_shift                                     (0)
#define  EMCU_MCU_MEM_RME_mcu_always_on_dmem_rme_mask                            (0x00000020)
#define  EMCU_MCU_MEM_RME_mcu_always_on_imem_rme_mask                            (0x00000010)
#define  EMCU_MCU_MEM_RME_mcu_shmem_rme_mask                                     (0x00000008)
#define  EMCU_MCU_MEM_RME_mcu_iram_rme_mask                                      (0x00000004)
#define  EMCU_MCU_MEM_RME_mcu_imem_rme_mask                                      (0x00000002)
#define  EMCU_MCU_MEM_RME_mcu_dmem_rme_mask                                      (0x00000001)
#define  EMCU_MCU_MEM_RME_mcu_always_on_dmem_rme(data)                           (0x00000020&((data)<<5))
#define  EMCU_MCU_MEM_RME_mcu_always_on_imem_rme(data)                           (0x00000010&((data)<<4))
#define  EMCU_MCU_MEM_RME_mcu_shmem_rme(data)                                    (0x00000008&((data)<<3))
#define  EMCU_MCU_MEM_RME_mcu_iram_rme(data)                                     (0x00000004&((data)<<2))
#define  EMCU_MCU_MEM_RME_mcu_imem_rme(data)                                     (0x00000002&((data)<<1))
#define  EMCU_MCU_MEM_RME_mcu_dmem_rme(data)                                     (0x00000001&(data))
#define  EMCU_MCU_MEM_RME_get_mcu_always_on_dmem_rme(data)                       ((0x00000020&(data))>>5)
#define  EMCU_MCU_MEM_RME_get_mcu_always_on_imem_rme(data)                       ((0x00000010&(data))>>4)
#define  EMCU_MCU_MEM_RME_get_mcu_shmem_rme(data)                                ((0x00000008&(data))>>3)
#define  EMCU_MCU_MEM_RME_get_mcu_iram_rme(data)                                 ((0x00000004&(data))>>2)
#define  EMCU_MCU_MEM_RME_get_mcu_imem_rme(data)                                 ((0x00000002&(data))>>1)
#define  EMCU_MCU_MEM_RME_get_mcu_dmem_rme(data)                                 (0x00000001&(data))

#define  EMCU_MCU_MEM_RM                                                         0x18060420
#define  EMCU_MCU_MEM_RM_reg_addr                                                "0xB8060420"
#define  EMCU_MCU_MEM_RM_reg                                                     0xB8060420
#define  EMCU_MCU_MEM_RM_inst_addr                                               "0x0003"
#define  set_EMCU_MCU_MEM_RM_reg(data)                                           (*((volatile unsigned int*)EMCU_MCU_MEM_RM_reg)=data)
#define  get_EMCU_MCU_MEM_RM_reg                                                 (*((volatile unsigned int*)EMCU_MCU_MEM_RM_reg))
#define  EMCU_MCU_MEM_RM_mcu_off_ram_rm_3_shift                                  (24)
#define  EMCU_MCU_MEM_RM_mcu_always_on_dmem_rm_shift                             (20)
#define  EMCU_MCU_MEM_RM_mcu_always_on_imem_rm_shift                             (16)
#define  EMCU_MCU_MEM_RM_mcu_shmem_rm_shift                                      (12)
#define  EMCU_MCU_MEM_RM_mcu_iram_rm_shift                                       (8)
#define  EMCU_MCU_MEM_RM_mcu_imem_rm_shift                                       (4)
#define  EMCU_MCU_MEM_RM_mcu_dmem_rm_shift                                       (0)
#define  EMCU_MCU_MEM_RM_mcu_off_ram_rm_3_mask                                   (0x01000000)
#define  EMCU_MCU_MEM_RM_mcu_always_on_dmem_rm_mask                              (0x00F00000)
#define  EMCU_MCU_MEM_RM_mcu_always_on_imem_rm_mask                              (0x000F0000)
#define  EMCU_MCU_MEM_RM_mcu_shmem_rm_mask                                       (0x0000F000)
#define  EMCU_MCU_MEM_RM_mcu_iram_rm_mask                                        (0x00000F00)
#define  EMCU_MCU_MEM_RM_mcu_imem_rm_mask                                        (0x000000F0)
#define  EMCU_MCU_MEM_RM_mcu_dmem_rm_mask                                        (0x0000000F)
#define  EMCU_MCU_MEM_RM_mcu_off_ram_rm_3(data)                                  (0x01000000&((data)<<24))
#define  EMCU_MCU_MEM_RM_mcu_always_on_dmem_rm(data)                             (0x00F00000&((data)<<20))
#define  EMCU_MCU_MEM_RM_mcu_always_on_imem_rm(data)                             (0x000F0000&((data)<<16))
#define  EMCU_MCU_MEM_RM_mcu_shmem_rm(data)                                      (0x0000F000&((data)<<12))
#define  EMCU_MCU_MEM_RM_mcu_iram_rm(data)                                       (0x00000F00&((data)<<8))
#define  EMCU_MCU_MEM_RM_mcu_imem_rm(data)                                       (0x000000F0&((data)<<4))
#define  EMCU_MCU_MEM_RM_mcu_dmem_rm(data)                                       (0x0000000F&(data))
#define  EMCU_MCU_MEM_RM_get_mcu_off_ram_rm_3(data)                              ((0x01000000&(data))>>24)
#define  EMCU_MCU_MEM_RM_get_mcu_always_on_dmem_rm(data)                         ((0x00F00000&(data))>>20)
#define  EMCU_MCU_MEM_RM_get_mcu_always_on_imem_rm(data)                         ((0x000F0000&(data))>>16)
#define  EMCU_MCU_MEM_RM_get_mcu_shmem_rm(data)                                  ((0x0000F000&(data))>>12)
#define  EMCU_MCU_MEM_RM_get_mcu_iram_rm(data)                                   ((0x00000F00&(data))>>8)
#define  EMCU_MCU_MEM_RM_get_mcu_imem_rm(data)                                   ((0x000000F0&(data))>>4)
#define  EMCU_MCU_MEM_RM_get_mcu_dmem_rm(data)                                   (0x0000000F&(data))

#define  EMCU_MCU_MEM_LIGHT_SLEEP                                                0x18060424
#define  EMCU_MCU_MEM_LIGHT_SLEEP_reg_addr                                       "0xB8060424"
#define  EMCU_MCU_MEM_LIGHT_SLEEP_reg                                            0xB8060424
#define  EMCU_MCU_MEM_LIGHT_SLEEP_inst_addr                                      "0x0004"
#define  set_EMCU_MCU_MEM_LIGHT_SLEEP_reg(data)                                  (*((volatile unsigned int*)EMCU_MCU_MEM_LIGHT_SLEEP_reg)=data)
#define  get_EMCU_MCU_MEM_LIGHT_SLEEP_reg                                        (*((volatile unsigned int*)EMCU_MCU_MEM_LIGHT_SLEEP_reg))
#define  EMCU_MCU_MEM_LIGHT_SLEEP_mcu_mem_ls_shift                               (0)
#define  EMCU_MCU_MEM_LIGHT_SLEEP_mcu_mem_ls_mask                                (0x00000001)
#define  EMCU_MCU_MEM_LIGHT_SLEEP_mcu_mem_ls(data)                               (0x00000001&(data))
#define  EMCU_MCU_MEM_LIGHT_SLEEP_get_mcu_mem_ls(data)                           (0x00000001&(data))

#define  EMCU_emcu_debug_8051_4                                                  0x18060428
#define  EMCU_emcu_debug_8051_4_reg_addr                                         "0xB8060428"
#define  EMCU_emcu_debug_8051_4_reg                                              0xB8060428
#define  EMCU_emcu_debug_8051_4_inst_addr                                        "0x0005"
#define  set_EMCU_emcu_debug_8051_4_reg(data)                                    (*((volatile unsigned int*)EMCU_emcu_debug_8051_4_reg)=data)
#define  get_EMCU_emcu_debug_8051_4_reg                                          (*((volatile unsigned int*)EMCU_emcu_debug_8051_4_reg))
#define  EMCU_emcu_debug_8051_4_dummy_31_0_shift                                 (0)
#define  EMCU_emcu_debug_8051_4_dummy_31_0_mask                                  (0xFFFFFFFF)
#define  EMCU_emcu_debug_8051_4_dummy_31_0(data)                                 (0xFFFFFFFF&(data))
#define  EMCU_emcu_debug_8051_4_get_dummy_31_0(data)                             (0xFFFFFFFF&(data))

#define  EMCU_system_CPU_program_enable                                          0x18060430
#define  EMCU_system_CPU_program_enable_reg_addr                                 "0xB8060430"
#define  EMCU_system_CPU_program_enable_reg                                      0xB8060430
#define  EMCU_system_CPU_program_enable_inst_addr                                "0x0006"
#define  set_EMCU_system_CPU_program_enable_reg(data)                            (*((volatile unsigned int*)EMCU_system_CPU_program_enable_reg)=data)
#define  get_EMCU_system_CPU_program_enable_reg                                  (*((volatile unsigned int*)EMCU_system_CPU_program_enable_reg))
#define  EMCU_system_CPU_program_enable_sys_prog_en_shift                        (0)
#define  EMCU_system_CPU_program_enable_sys_prog_en_mask                         (0x00000001)
#define  EMCU_system_CPU_program_enable_sys_prog_en(data)                        (0x00000001&(data))
#define  EMCU_system_CPU_program_enable_get_sys_prog_en(data)                    (0x00000001&(data))

#define  EMCU_IMEM_control                                                       0x18060434
#define  EMCU_IMEM_control_reg_addr                                              "0xB8060434"
#define  EMCU_IMEM_control_reg                                                   0xB8060434
#define  EMCU_IMEM_control_inst_addr                                             "0x0007"
#define  set_EMCU_IMEM_control_reg(data)                                         (*((volatile unsigned int*)EMCU_IMEM_control_reg)=data)
#define  get_EMCU_IMEM_control_reg                                               (*((volatile unsigned int*)EMCU_IMEM_control_reg))
#define  EMCU_IMEM_control_cur_imem_addr_shift                                   (16)
#define  EMCU_IMEM_control_imem_reload_shift                                     (15)
#define  EMCU_IMEM_control_imem_auto_shift                                       (14)
#define  EMCU_IMEM_control_imem_addr_shift                                       (0)
#define  EMCU_IMEM_control_cur_imem_addr_mask                                    (0x3FFF0000)
#define  EMCU_IMEM_control_imem_reload_mask                                      (0x00008000)
#define  EMCU_IMEM_control_imem_auto_mask                                        (0x00004000)
#define  EMCU_IMEM_control_imem_addr_mask                                        (0x00003FFF)
#define  EMCU_IMEM_control_cur_imem_addr(data)                                   (0x3FFF0000&((data)<<16))
#define  EMCU_IMEM_control_imem_reload(data)                                     (0x00008000&((data)<<15))
#define  EMCU_IMEM_control_imem_auto(data)                                       (0x00004000&((data)<<14))
#define  EMCU_IMEM_control_imem_addr(data)                                       (0x00003FFF&(data))
#define  EMCU_IMEM_control_get_cur_imem_addr(data)                               ((0x3FFF0000&(data))>>16)
#define  EMCU_IMEM_control_get_imem_reload(data)                                 ((0x00008000&(data))>>15)
#define  EMCU_IMEM_control_get_imem_auto(data)                                   ((0x00004000&(data))>>14)
#define  EMCU_IMEM_control_get_imem_addr(data)                                   (0x00003FFF&(data))

#define  EMCU_IMEM_data                                                          0x18060438
#define  EMCU_IMEM_data_reg_addr                                                 "0xB8060438"
#define  EMCU_IMEM_data_reg                                                      0xB8060438
#define  EMCU_IMEM_data_inst_addr                                                "0x0008"
#define  set_EMCU_IMEM_data_reg(data)                                            (*((volatile unsigned int*)EMCU_IMEM_data_reg)=data)
#define  get_EMCU_IMEM_data_reg                                                  (*((volatile unsigned int*)EMCU_IMEM_data_reg))
#define  EMCU_IMEM_data_imem_data_shift                                          (0)
#define  EMCU_IMEM_data_imem_data_mask                                           (0xFFFFFFFF)
#define  EMCU_IMEM_data_imem_data(data)                                          (0xFFFFFFFF&(data))
#define  EMCU_IMEM_data_get_imem_data(data)                                      (0xFFFFFFFF&(data))

#define  EMCU_DMEM_control                                                       0x1806043C
#define  EMCU_DMEM_control_reg_addr                                              "0xB806043C"
#define  EMCU_DMEM_control_reg                                                   0xB806043C
#define  EMCU_DMEM_control_inst_addr                                             "0x0009"
#define  set_EMCU_DMEM_control_reg(data)                                         (*((volatile unsigned int*)EMCU_DMEM_control_reg)=data)
#define  get_EMCU_DMEM_control_reg                                               (*((volatile unsigned int*)EMCU_DMEM_control_reg))
#define  EMCU_DMEM_control_cur_dmem_addr_shift                                   (12)
#define  EMCU_DMEM_control_dmem_reload_shift                                     (11)
#define  EMCU_DMEM_control_dmem_auto_shift                                       (10)
#define  EMCU_DMEM_control_dmem_addr_shift                                       (0)
#define  EMCU_DMEM_control_cur_dmem_addr_mask                                    (0x001FF000)
#define  EMCU_DMEM_control_dmem_reload_mask                                      (0x00000800)
#define  EMCU_DMEM_control_dmem_auto_mask                                        (0x00000400)
#define  EMCU_DMEM_control_dmem_addr_mask                                        (0x000001FF)
#define  EMCU_DMEM_control_cur_dmem_addr(data)                                   (0x001FF000&((data)<<12))
#define  EMCU_DMEM_control_dmem_reload(data)                                     (0x00000800&((data)<<11))
#define  EMCU_DMEM_control_dmem_auto(data)                                       (0x00000400&((data)<<10))
#define  EMCU_DMEM_control_dmem_addr(data)                                       (0x000001FF&(data))
#define  EMCU_DMEM_control_get_cur_dmem_addr(data)                               ((0x001FF000&(data))>>12)
#define  EMCU_DMEM_control_get_dmem_reload(data)                                 ((0x00000800&(data))>>11)
#define  EMCU_DMEM_control_get_dmem_auto(data)                                   ((0x00000400&(data))>>10)
#define  EMCU_DMEM_control_get_dmem_addr(data)                                   (0x000001FF&(data))

#define  EMCU_DMEM_data                                                          0x18060440
#define  EMCU_DMEM_data_reg_addr                                                 "0xB8060440"
#define  EMCU_DMEM_data_reg                                                      0xB8060440
#define  EMCU_DMEM_data_inst_addr                                                "0x000A"
#define  set_EMCU_DMEM_data_reg(data)                                            (*((volatile unsigned int*)EMCU_DMEM_data_reg)=data)
#define  get_EMCU_DMEM_data_reg                                                  (*((volatile unsigned int*)EMCU_DMEM_data_reg))
#define  EMCU_DMEM_data_dmem_data_shift                                          (0)
#define  EMCU_DMEM_data_dmem_data_mask                                           (0xFFFFFFFF)
#define  EMCU_DMEM_data_dmem_data(data)                                          (0xFFFFFFFF&(data))
#define  EMCU_DMEM_data_get_dmem_data(data)                                      (0xFFFFFFFF&(data))

#define  EMCU_ST_IP                                                              0x18060450
#define  EMCU_ST_IP_reg_addr                                                     "0xB8060450"
#define  EMCU_ST_IP_reg                                                          0xB8060450
#define  EMCU_ST_IP_inst_addr                                                    "0x000B"
#define  set_EMCU_ST_IP_reg(data)                                                (*((volatile unsigned int*)EMCU_ST_IP_reg)=data)
#define  get_EMCU_ST_IP_reg                                                      (*((volatile unsigned int*)EMCU_ST_IP_reg))
#define  EMCU_ST_IP_stip_cbus_tx_shift                                           (10)
#define  EMCU_ST_IP_stip_wol_shift                                               (9)
#define  EMCU_ST_IP_stip_self_wakeup_shift                                       (8)
#define  EMCU_ST_IP_stip_rbus_shift                                              (7)
#define  EMCU_ST_IP_stip_hdmi_clk_det_shift                                      (6)
#define  EMCU_ST_IP_stip_st_syncp_shift                                          (5)
#define  EMCU_ST_IP_stip_cec_shift                                               (4)
#define  EMCU_ST_IP_stip_isomisc_shift                                           (3)
#define  EMCU_ST_IP_stip_isomisc_off_shift                                       (2)
#define  EMCU_ST_IP_stip_rtc_shift                                               (1)
#define  EMCU_ST_IP_stip_cbus_det_shift                                          (0)
#define  EMCU_ST_IP_stip_cbus_tx_mask                                            (0x00000400)
#define  EMCU_ST_IP_stip_wol_mask                                                (0x00000200)
#define  EMCU_ST_IP_stip_self_wakeup_mask                                        (0x00000100)
#define  EMCU_ST_IP_stip_rbus_mask                                               (0x00000080)
#define  EMCU_ST_IP_stip_hdmi_clk_det_mask                                       (0x00000040)
#define  EMCU_ST_IP_stip_st_syncp_mask                                           (0x00000020)
#define  EMCU_ST_IP_stip_cec_mask                                                (0x00000010)
#define  EMCU_ST_IP_stip_isomisc_mask                                            (0x00000008)
#define  EMCU_ST_IP_stip_isomisc_off_mask                                        (0x00000004)
#define  EMCU_ST_IP_stip_rtc_mask                                                (0x00000002)
#define  EMCU_ST_IP_stip_cbus_det_mask                                           (0x00000001)
#define  EMCU_ST_IP_stip_cbus_tx(data)                                           (0x00000400&((data)<<10))
#define  EMCU_ST_IP_stip_wol(data)                                               (0x00000200&((data)<<9))
#define  EMCU_ST_IP_stip_self_wakeup(data)                                       (0x00000100&((data)<<8))
#define  EMCU_ST_IP_stip_rbus(data)                                              (0x00000080&((data)<<7))
#define  EMCU_ST_IP_stip_hdmi_clk_det(data)                                      (0x00000040&((data)<<6))
#define  EMCU_ST_IP_stip_st_syncp(data)                                          (0x00000020&((data)<<5))
#define  EMCU_ST_IP_stip_cec(data)                                               (0x00000010&((data)<<4))
#define  EMCU_ST_IP_stip_isomisc(data)                                           (0x00000008&((data)<<3))
#define  EMCU_ST_IP_stip_isomisc_off(data)                                       (0x00000004&((data)<<2))
#define  EMCU_ST_IP_stip_rtc(data)                                               (0x00000002&((data)<<1))
#define  EMCU_ST_IP_stip_cbus_det(data)                                          (0x00000001&(data))
#define  EMCU_ST_IP_get_stip_cbus_tx(data)                                       ((0x00000400&(data))>>10)
#define  EMCU_ST_IP_get_stip_wol(data)                                           ((0x00000200&(data))>>9)
#define  EMCU_ST_IP_get_stip_self_wakeup(data)                                   ((0x00000100&(data))>>8)
#define  EMCU_ST_IP_get_stip_rbus(data)                                          ((0x00000080&(data))>>7)
#define  EMCU_ST_IP_get_stip_hdmi_clk_det(data)                                  ((0x00000040&(data))>>6)
#define  EMCU_ST_IP_get_stip_st_syncp(data)                                      ((0x00000020&(data))>>5)
#define  EMCU_ST_IP_get_stip_cec(data)                                           ((0x00000010&(data))>>4)
#define  EMCU_ST_IP_get_stip_isomisc(data)                                       ((0x00000008&(data))>>3)
#define  EMCU_ST_IP_get_stip_isomisc_off(data)                                   ((0x00000004&(data))>>2)
#define  EMCU_ST_IP_get_stip_rtc(data)                                           ((0x00000002&(data))>>1)
#define  EMCU_ST_IP_get_stip_cbus_det(data)                                      (0x00000001&(data))

#define  EMCU_ST_IE                                                              0x18060454
#define  EMCU_ST_IE_reg_addr                                                     "0xB8060454"
#define  EMCU_ST_IE_reg                                                          0xB8060454
#define  EMCU_ST_IE_inst_addr                                                    "0x000C"
#define  set_EMCU_ST_IE_reg(data)                                                (*((volatile unsigned int*)EMCU_ST_IE_reg)=data)
#define  get_EMCU_ST_IE_reg                                                      (*((volatile unsigned int*)EMCU_ST_IE_reg))
#define  EMCU_ST_IE_stie_cbus_tx_shift                                           (10)
#define  EMCU_ST_IE_stie_wol_shift                                               (9)
#define  EMCU_ST_IE_stie_self_wakeup_shift                                       (8)
#define  EMCU_ST_IE_stie_rbus_shift                                              (7)
#define  EMCU_ST_IE_stie_hdmi_clk_det_shift                                      (6)
#define  EMCU_ST_IE_stie_st_syncp_shift                                          (5)
#define  EMCU_ST_IE_stie_cec_shift                                               (4)
#define  EMCU_ST_IE_stie_isomisc_shift                                           (3)
#define  EMCU_ST_IE_stie_isomisc_off_shift                                       (2)
#define  EMCU_ST_IE_stie_rtc_shift                                               (1)
#define  EMCU_ST_IE_stie_cbus_det_shift                                          (0)
#define  EMCU_ST_IE_stie_cbus_tx_mask                                            (0x00000400)
#define  EMCU_ST_IE_stie_wol_mask                                                (0x00000200)
#define  EMCU_ST_IE_stie_self_wakeup_mask                                        (0x00000100)
#define  EMCU_ST_IE_stie_rbus_mask                                               (0x00000080)
#define  EMCU_ST_IE_stie_hdmi_clk_det_mask                                       (0x00000040)
#define  EMCU_ST_IE_stie_st_syncp_mask                                           (0x00000020)
#define  EMCU_ST_IE_stie_cec_mask                                                (0x00000010)
#define  EMCU_ST_IE_stie_isomisc_mask                                            (0x00000008)
#define  EMCU_ST_IE_stie_isomisc_off_mask                                        (0x00000004)
#define  EMCU_ST_IE_stie_rtc_mask                                                (0x00000002)
#define  EMCU_ST_IE_stie_cbus_det_mask                                           (0x00000001)
#define  EMCU_ST_IE_stie_cbus_tx(data)                                           (0x00000400&((data)<<10))
#define  EMCU_ST_IE_stie_wol(data)                                               (0x00000200&((data)<<9))
#define  EMCU_ST_IE_stie_self_wakeup(data)                                       (0x00000100&((data)<<8))
#define  EMCU_ST_IE_stie_rbus(data)                                              (0x00000080&((data)<<7))
#define  EMCU_ST_IE_stie_hdmi_clk_det(data)                                      (0x00000040&((data)<<6))
#define  EMCU_ST_IE_stie_st_syncp(data)                                          (0x00000020&((data)<<5))
#define  EMCU_ST_IE_stie_cec(data)                                               (0x00000010&((data)<<4))
#define  EMCU_ST_IE_stie_isomisc(data)                                           (0x00000008&((data)<<3))
#define  EMCU_ST_IE_stie_isomisc_off(data)                                       (0x00000004&((data)<<2))
#define  EMCU_ST_IE_stie_rtc(data)                                               (0x00000002&((data)<<1))
#define  EMCU_ST_IE_stie_cbus_det(data)                                          (0x00000001&(data))
#define  EMCU_ST_IE_get_stie_cbus_tx(data)                                       ((0x00000400&(data))>>10)
#define  EMCU_ST_IE_get_stie_wol(data)                                           ((0x00000200&(data))>>9)
#define  EMCU_ST_IE_get_stie_self_wakeup(data)                                   ((0x00000100&(data))>>8)
#define  EMCU_ST_IE_get_stie_rbus(data)                                          ((0x00000080&(data))>>7)
#define  EMCU_ST_IE_get_stie_hdmi_clk_det(data)                                  ((0x00000040&(data))>>6)
#define  EMCU_ST_IE_get_stie_st_syncp(data)                                      ((0x00000020&(data))>>5)
#define  EMCU_ST_IE_get_stie_cec(data)                                           ((0x00000010&(data))>>4)
#define  EMCU_ST_IE_get_stie_isomisc(data)                                       ((0x00000008&(data))>>3)
#define  EMCU_ST_IE_get_stie_isomisc_off(data)                                   ((0x00000004&(data))>>2)
#define  EMCU_ST_IE_get_stie_rtc(data)                                           ((0x00000002&(data))>>1)
#define  EMCU_ST_IE_get_stie_cbus_det(data)                                      (0x00000001&(data))

#define  EMCU_MCU_BIST_MODE                                                      0x18060460
#define  EMCU_MCU_BIST_MODE_reg_addr                                             "0xB8060460"
#define  EMCU_MCU_BIST_MODE_reg                                                  0xB8060460
#define  EMCU_MCU_BIST_MODE_inst_addr                                            "0x000D"
#define  set_EMCU_MCU_BIST_MODE_reg(data)                                        (*((volatile unsigned int*)EMCU_MCU_BIST_MODE_reg)=data)
#define  get_EMCU_MCU_BIST_MODE_reg                                              (*((volatile unsigned int*)EMCU_MCU_BIST_MODE_reg))
#define  EMCU_MCU_BIST_MODE_mcu_bist_mode_mcu_always_on_shift                    (3)
#define  EMCU_MCU_BIST_MODE_mcu_bist_mode_mcu_iram_shift                         (1)
#define  EMCU_MCU_BIST_MODE_mcu_bist_mode_mcu_dmem_shift                         (0)
#define  EMCU_MCU_BIST_MODE_mcu_bist_mode_mcu_always_on_mask                     (0x00000008)
#define  EMCU_MCU_BIST_MODE_mcu_bist_mode_mcu_iram_mask                          (0x00000002)
#define  EMCU_MCU_BIST_MODE_mcu_bist_mode_mcu_dmem_mask                          (0x00000001)
#define  EMCU_MCU_BIST_MODE_mcu_bist_mode_mcu_always_on(data)                    (0x00000008&((data)<<3))
#define  EMCU_MCU_BIST_MODE_mcu_bist_mode_mcu_iram(data)                         (0x00000002&((data)<<1))
#define  EMCU_MCU_BIST_MODE_mcu_bist_mode_mcu_dmem(data)                         (0x00000001&(data))
#define  EMCU_MCU_BIST_MODE_get_mcu_bist_mode_mcu_always_on(data)                ((0x00000008&(data))>>3)
#define  EMCU_MCU_BIST_MODE_get_mcu_bist_mode_mcu_iram(data)                     ((0x00000002&(data))>>1)
#define  EMCU_MCU_BIST_MODE_get_mcu_bist_mode_mcu_dmem(data)                     (0x00000001&(data))

#define  EMCU_MCU_BIST_DONE                                                      0x18060464
#define  EMCU_MCU_BIST_DONE_reg_addr                                             "0xB8060464"
#define  EMCU_MCU_BIST_DONE_reg                                                  0xB8060464
#define  EMCU_MCU_BIST_DONE_inst_addr                                            "0x000E"
#define  set_EMCU_MCU_BIST_DONE_reg(data)                                        (*((volatile unsigned int*)EMCU_MCU_BIST_DONE_reg)=data)
#define  get_EMCU_MCU_BIST_DONE_reg                                              (*((volatile unsigned int*)EMCU_MCU_BIST_DONE_reg))
#define  EMCU_MCU_BIST_DONE_mcu_bist_done_mcu_always_on_shift                    (3)
#define  EMCU_MCU_BIST_DONE_mcu_bist_done_mcu_iram_shift                         (1)
#define  EMCU_MCU_BIST_DONE_mcu_bist_done_mcu_dmem_shift                         (0)
#define  EMCU_MCU_BIST_DONE_mcu_bist_done_mcu_always_on_mask                     (0x00000008)
#define  EMCU_MCU_BIST_DONE_mcu_bist_done_mcu_iram_mask                          (0x00000002)
#define  EMCU_MCU_BIST_DONE_mcu_bist_done_mcu_dmem_mask                          (0x00000001)
#define  EMCU_MCU_BIST_DONE_mcu_bist_done_mcu_always_on(data)                    (0x00000008&((data)<<3))
#define  EMCU_MCU_BIST_DONE_mcu_bist_done_mcu_iram(data)                         (0x00000002&((data)<<1))
#define  EMCU_MCU_BIST_DONE_mcu_bist_done_mcu_dmem(data)                         (0x00000001&(data))
#define  EMCU_MCU_BIST_DONE_get_mcu_bist_done_mcu_always_on(data)                ((0x00000008&(data))>>3)
#define  EMCU_MCU_BIST_DONE_get_mcu_bist_done_mcu_iram(data)                     ((0x00000002&(data))>>1)
#define  EMCU_MCU_BIST_DONE_get_mcu_bist_done_mcu_dmem(data)                     (0x00000001&(data))

#define  EMCU_MCU_BIST_FAIL_GROUP                                                0x18060468
#define  EMCU_MCU_BIST_FAIL_GROUP_reg_addr                                       "0xB8060468"
#define  EMCU_MCU_BIST_FAIL_GROUP_reg                                            0xB8060468
#define  EMCU_MCU_BIST_FAIL_GROUP_inst_addr                                      "0x000F"
#define  set_EMCU_MCU_BIST_FAIL_GROUP_reg(data)                                  (*((volatile unsigned int*)EMCU_MCU_BIST_FAIL_GROUP_reg)=data)
#define  get_EMCU_MCU_BIST_FAIL_GROUP_reg                                        (*((volatile unsigned int*)EMCU_MCU_BIST_FAIL_GROUP_reg))
#define  EMCU_MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_always_on_shift        (3)
#define  EMCU_MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_iram_shift             (1)
#define  EMCU_MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_dmem_shift             (0)
#define  EMCU_MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_always_on_mask         (0x00000008)
#define  EMCU_MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_iram_mask              (0x00000002)
#define  EMCU_MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_dmem_mask              (0x00000001)
#define  EMCU_MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_always_on(data)        (0x00000008&((data)<<3))
#define  EMCU_MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_iram(data)             (0x00000002&((data)<<1))
#define  EMCU_MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_dmem(data)             (0x00000001&(data))
#define  EMCU_MCU_BIST_FAIL_GROUP_get_mcu_bist_fail_group_mcu_always_on(data)    ((0x00000008&(data))>>3)
#define  EMCU_MCU_BIST_FAIL_GROUP_get_mcu_bist_fail_group_mcu_iram(data)         ((0x00000002&(data))>>1)
#define  EMCU_MCU_BIST_FAIL_GROUP_get_mcu_bist_fail_group_mcu_dmem(data)         (0x00000001&(data))

#define  EMCU_MCU_BIST_MCU_DMEM_FAIL                                             0x1806046C
#define  EMCU_MCU_BIST_MCU_DMEM_FAIL_reg_addr                                    "0xB806046C"
#define  EMCU_MCU_BIST_MCU_DMEM_FAIL_reg                                         0xB806046C
#define  EMCU_MCU_BIST_MCU_DMEM_FAIL_inst_addr                                   "0x0010"
#define  set_EMCU_MCU_BIST_MCU_DMEM_FAIL_reg(data)                               (*((volatile unsigned int*)EMCU_MCU_BIST_MCU_DMEM_FAIL_reg)=data)
#define  get_EMCU_MCU_BIST_MCU_DMEM_FAIL_reg                                     (*((volatile unsigned int*)EMCU_MCU_BIST_MCU_DMEM_FAIL_reg))
#define  EMCU_MCU_BIST_MCU_DMEM_FAIL_mcu_bist_mcu_dmem_fail_1_shift              (1)
#define  EMCU_MCU_BIST_MCU_DMEM_FAIL_mcu_bist_mcu_dmem_fail_0_shift              (0)
#define  EMCU_MCU_BIST_MCU_DMEM_FAIL_mcu_bist_mcu_dmem_fail_1_mask               (0x00000002)
#define  EMCU_MCU_BIST_MCU_DMEM_FAIL_mcu_bist_mcu_dmem_fail_0_mask               (0x00000001)
#define  EMCU_MCU_BIST_MCU_DMEM_FAIL_mcu_bist_mcu_dmem_fail_1(data)              (0x00000002&((data)<<1))
#define  EMCU_MCU_BIST_MCU_DMEM_FAIL_mcu_bist_mcu_dmem_fail_0(data)              (0x00000001&(data))
#define  EMCU_MCU_BIST_MCU_DMEM_FAIL_get_mcu_bist_mcu_dmem_fail_1(data)          ((0x00000002&(data))>>1)
#define  EMCU_MCU_BIST_MCU_DMEM_FAIL_get_mcu_bist_mcu_dmem_fail_0(data)          (0x00000001&(data))

#define  EMCU_MCU_BIST_MCU_IRAM_FAIL                                             0x18060474
#define  EMCU_MCU_BIST_MCU_IRAM_FAIL_reg_addr                                    "0xB8060474"
#define  EMCU_MCU_BIST_MCU_IRAM_FAIL_reg                                         0xB8060474
#define  EMCU_MCU_BIST_MCU_IRAM_FAIL_inst_addr                                   "0x0011"
#define  set_EMCU_MCU_BIST_MCU_IRAM_FAIL_reg(data)                               (*((volatile unsigned int*)EMCU_MCU_BIST_MCU_IRAM_FAIL_reg)=data)
#define  get_EMCU_MCU_BIST_MCU_IRAM_FAIL_reg                                     (*((volatile unsigned int*)EMCU_MCU_BIST_MCU_IRAM_FAIL_reg))
#define  EMCU_MCU_BIST_MCU_IRAM_FAIL_mcu_bist_mcu_iram_fail_0_shift              (0)
#define  EMCU_MCU_BIST_MCU_IRAM_FAIL_mcu_bist_mcu_iram_fail_0_mask               (0x00000001)
#define  EMCU_MCU_BIST_MCU_IRAM_FAIL_mcu_bist_mcu_iram_fail_0(data)              (0x00000001&(data))
#define  EMCU_MCU_BIST_MCU_IRAM_FAIL_get_mcu_bist_mcu_iram_fail_0(data)          (0x00000001&(data))

#define  EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL                                        0x18060478
#define  EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_reg_addr                               "0xB8060478"
#define  EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_reg                                    0xB8060478
#define  EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_inst_addr                              "0x0012"
#define  set_EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_reg(data)                          (*((volatile unsigned int*)EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_reg)=data)
#define  get_EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_reg                                (*((volatile unsigned int*)EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_reg))
#define  EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_mcu_bist_mcu_always_on_fail_1_shift    (1)
#define  EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_mcu_bist_mcu_always_on_fail_0_shift    (0)
#define  EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_mcu_bist_mcu_always_on_fail_1_mask     (0x00000002)
#define  EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_mcu_bist_mcu_always_on_fail_0_mask     (0x00000001)
#define  EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_mcu_bist_mcu_always_on_fail_1(data)    (0x00000002&((data)<<1))
#define  EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_mcu_bist_mcu_always_on_fail_0(data)    (0x00000001&(data))
#define  EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_get_mcu_bist_mcu_always_on_fail_1(data) ((0x00000002&(data))>>1)
#define  EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_get_mcu_bist_mcu_always_on_fail_0(data) (0x00000001&(data))

#define  EMCU_MCU_DRF_MODE                                                       0x1806047C
#define  EMCU_MCU_DRF_MODE_reg_addr                                              "0xB806047C"
#define  EMCU_MCU_DRF_MODE_reg                                                   0xB806047C
#define  EMCU_MCU_DRF_MODE_inst_addr                                             "0x0013"
#define  set_EMCU_MCU_DRF_MODE_reg(data)                                         (*((volatile unsigned int*)EMCU_MCU_DRF_MODE_reg)=data)
#define  get_EMCU_MCU_DRF_MODE_reg                                               (*((volatile unsigned int*)EMCU_MCU_DRF_MODE_reg))
#define  EMCU_MCU_DRF_MODE_mcu_drf_mode_mcu_always_on_shift                      (3)
#define  EMCU_MCU_DRF_MODE_mcu_drf_mode_mcu_iram_shift                           (1)
#define  EMCU_MCU_DRF_MODE_mcu_drf_mode_mcu_dmem_shift                           (0)
#define  EMCU_MCU_DRF_MODE_mcu_drf_mode_mcu_always_on_mask                       (0x00000008)
#define  EMCU_MCU_DRF_MODE_mcu_drf_mode_mcu_iram_mask                            (0x00000002)
#define  EMCU_MCU_DRF_MODE_mcu_drf_mode_mcu_dmem_mask                            (0x00000001)
#define  EMCU_MCU_DRF_MODE_mcu_drf_mode_mcu_always_on(data)                      (0x00000008&((data)<<3))
#define  EMCU_MCU_DRF_MODE_mcu_drf_mode_mcu_iram(data)                           (0x00000002&((data)<<1))
#define  EMCU_MCU_DRF_MODE_mcu_drf_mode_mcu_dmem(data)                           (0x00000001&(data))
#define  EMCU_MCU_DRF_MODE_get_mcu_drf_mode_mcu_always_on(data)                  ((0x00000008&(data))>>3)
#define  EMCU_MCU_DRF_MODE_get_mcu_drf_mode_mcu_iram(data)                       ((0x00000002&(data))>>1)
#define  EMCU_MCU_DRF_MODE_get_mcu_drf_mode_mcu_dmem(data)                       (0x00000001&(data))

#define  EMCU_MCU_DRF_RESUME                                                     0x18060480
#define  EMCU_MCU_DRF_RESUME_reg_addr                                            "0xB8060480"
#define  EMCU_MCU_DRF_RESUME_reg                                                 0xB8060480
#define  EMCU_MCU_DRF_RESUME_inst_addr                                           "0x0014"
#define  set_EMCU_MCU_DRF_RESUME_reg(data)                                       (*((volatile unsigned int*)EMCU_MCU_DRF_RESUME_reg)=data)
#define  get_EMCU_MCU_DRF_RESUME_reg                                             (*((volatile unsigned int*)EMCU_MCU_DRF_RESUME_reg))
#define  EMCU_MCU_DRF_RESUME_mcu_drf_resume_mcu_always_on_shift                  (3)
#define  EMCU_MCU_DRF_RESUME_mcu_drf_resume_mcu_iram_shift                       (1)
#define  EMCU_MCU_DRF_RESUME_mcu_drf_resume_mcu_dmem_shift                       (0)
#define  EMCU_MCU_DRF_RESUME_mcu_drf_resume_mcu_always_on_mask                   (0x00000008)
#define  EMCU_MCU_DRF_RESUME_mcu_drf_resume_mcu_iram_mask                        (0x00000002)
#define  EMCU_MCU_DRF_RESUME_mcu_drf_resume_mcu_dmem_mask                        (0x00000001)
#define  EMCU_MCU_DRF_RESUME_mcu_drf_resume_mcu_always_on(data)                  (0x00000008&((data)<<3))
#define  EMCU_MCU_DRF_RESUME_mcu_drf_resume_mcu_iram(data)                       (0x00000002&((data)<<1))
#define  EMCU_MCU_DRF_RESUME_mcu_drf_resume_mcu_dmem(data)                       (0x00000001&(data))
#define  EMCU_MCU_DRF_RESUME_get_mcu_drf_resume_mcu_always_on(data)              ((0x00000008&(data))>>3)
#define  EMCU_MCU_DRF_RESUME_get_mcu_drf_resume_mcu_iram(data)                   ((0x00000002&(data))>>1)
#define  EMCU_MCU_DRF_RESUME_get_mcu_drf_resume_mcu_dmem(data)                   (0x00000001&(data))

#define  EMCU_MCU_DRF_DONE                                                       0x18060484
#define  EMCU_MCU_DRF_DONE_reg_addr                                              "0xB8060484"
#define  EMCU_MCU_DRF_DONE_reg                                                   0xB8060484
#define  EMCU_MCU_DRF_DONE_inst_addr                                             "0x0015"
#define  set_EMCU_MCU_DRF_DONE_reg(data)                                         (*((volatile unsigned int*)EMCU_MCU_DRF_DONE_reg)=data)
#define  get_EMCU_MCU_DRF_DONE_reg                                               (*((volatile unsigned int*)EMCU_MCU_DRF_DONE_reg))
#define  EMCU_MCU_DRF_DONE_mcu_drf_done_mcu_always_on_shift                      (3)
#define  EMCU_MCU_DRF_DONE_mcu_drf_done_mcu_iram_shift                           (1)
#define  EMCU_MCU_DRF_DONE_mcu_drf_done_mcu_dmem_shift                           (0)
#define  EMCU_MCU_DRF_DONE_mcu_drf_done_mcu_always_on_mask                       (0x00000008)
#define  EMCU_MCU_DRF_DONE_mcu_drf_done_mcu_iram_mask                            (0x00000002)
#define  EMCU_MCU_DRF_DONE_mcu_drf_done_mcu_dmem_mask                            (0x00000001)
#define  EMCU_MCU_DRF_DONE_mcu_drf_done_mcu_always_on(data)                      (0x00000008&((data)<<3))
#define  EMCU_MCU_DRF_DONE_mcu_drf_done_mcu_iram(data)                           (0x00000002&((data)<<1))
#define  EMCU_MCU_DRF_DONE_mcu_drf_done_mcu_dmem(data)                           (0x00000001&(data))
#define  EMCU_MCU_DRF_DONE_get_mcu_drf_done_mcu_always_on(data)                  ((0x00000008&(data))>>3)
#define  EMCU_MCU_DRF_DONE_get_mcu_drf_done_mcu_iram(data)                       ((0x00000002&(data))>>1)
#define  EMCU_MCU_DRF_DONE_get_mcu_drf_done_mcu_dmem(data)                       (0x00000001&(data))

#define  EMCU_MCU_DRF_PAUSE                                                      0x18060488
#define  EMCU_MCU_DRF_PAUSE_reg_addr                                             "0xB8060488"
#define  EMCU_MCU_DRF_PAUSE_reg                                                  0xB8060488
#define  EMCU_MCU_DRF_PAUSE_inst_addr                                            "0x0016"
#define  set_EMCU_MCU_DRF_PAUSE_reg(data)                                        (*((volatile unsigned int*)EMCU_MCU_DRF_PAUSE_reg)=data)
#define  get_EMCU_MCU_DRF_PAUSE_reg                                              (*((volatile unsigned int*)EMCU_MCU_DRF_PAUSE_reg))
#define  EMCU_MCU_DRF_PAUSE_mcu_drf_pause_mcu_always_on_shift                    (3)
#define  EMCU_MCU_DRF_PAUSE_mcu_drf_pause_mcu_iram_shift                         (1)
#define  EMCU_MCU_DRF_PAUSE_mcu_drf_pause_mcu_dmem_shift                         (0)
#define  EMCU_MCU_DRF_PAUSE_mcu_drf_pause_mcu_always_on_mask                     (0x00000008)
#define  EMCU_MCU_DRF_PAUSE_mcu_drf_pause_mcu_iram_mask                          (0x00000002)
#define  EMCU_MCU_DRF_PAUSE_mcu_drf_pause_mcu_dmem_mask                          (0x00000001)
#define  EMCU_MCU_DRF_PAUSE_mcu_drf_pause_mcu_always_on(data)                    (0x00000008&((data)<<3))
#define  EMCU_MCU_DRF_PAUSE_mcu_drf_pause_mcu_iram(data)                         (0x00000002&((data)<<1))
#define  EMCU_MCU_DRF_PAUSE_mcu_drf_pause_mcu_dmem(data)                         (0x00000001&(data))
#define  EMCU_MCU_DRF_PAUSE_get_mcu_drf_pause_mcu_always_on(data)                ((0x00000008&(data))>>3)
#define  EMCU_MCU_DRF_PAUSE_get_mcu_drf_pause_mcu_iram(data)                     ((0x00000002&(data))>>1)
#define  EMCU_MCU_DRF_PAUSE_get_mcu_drf_pause_mcu_dmem(data)                     (0x00000001&(data))

#define  EMCU_MCU_DRF_FAIL_GROUP                                                 0x1806048C
#define  EMCU_MCU_DRF_FAIL_GROUP_reg_addr                                        "0xB806048C"
#define  EMCU_MCU_DRF_FAIL_GROUP_reg                                             0xB806048C
#define  EMCU_MCU_DRF_FAIL_GROUP_inst_addr                                       "0x0017"
#define  set_EMCU_MCU_DRF_FAIL_GROUP_reg(data)                                   (*((volatile unsigned int*)EMCU_MCU_DRF_FAIL_GROUP_reg)=data)
#define  get_EMCU_MCU_DRF_FAIL_GROUP_reg                                         (*((volatile unsigned int*)EMCU_MCU_DRF_FAIL_GROUP_reg))
#define  EMCU_MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_always_on_shift          (3)
#define  EMCU_MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_iram_shift               (1)
#define  EMCU_MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_dmem_shift               (0)
#define  EMCU_MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_always_on_mask           (0x00000008)
#define  EMCU_MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_iram_mask                (0x00000002)
#define  EMCU_MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_dmem_mask                (0x00000001)
#define  EMCU_MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_always_on(data)          (0x00000008&((data)<<3))
#define  EMCU_MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_iram(data)               (0x00000002&((data)<<1))
#define  EMCU_MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_dmem(data)               (0x00000001&(data))
#define  EMCU_MCU_DRF_FAIL_GROUP_get_mcu_drf_fail_group_mcu_always_on(data)      ((0x00000008&(data))>>3)
#define  EMCU_MCU_DRF_FAIL_GROUP_get_mcu_drf_fail_group_mcu_iram(data)           ((0x00000002&(data))>>1)
#define  EMCU_MCU_DRF_FAIL_GROUP_get_mcu_drf_fail_group_mcu_dmem(data)           (0x00000001&(data))

#define  EMCU_MCU_DRF_MCU_DMEM_FAIL                                              0x18060490
#define  EMCU_MCU_DRF_MCU_DMEM_FAIL_reg_addr                                     "0xB8060490"
#define  EMCU_MCU_DRF_MCU_DMEM_FAIL_reg                                          0xB8060490
#define  EMCU_MCU_DRF_MCU_DMEM_FAIL_inst_addr                                    "0x0018"
#define  set_EMCU_MCU_DRF_MCU_DMEM_FAIL_reg(data)                                (*((volatile unsigned int*)EMCU_MCU_DRF_MCU_DMEM_FAIL_reg)=data)
#define  get_EMCU_MCU_DRF_MCU_DMEM_FAIL_reg                                      (*((volatile unsigned int*)EMCU_MCU_DRF_MCU_DMEM_FAIL_reg))
#define  EMCU_MCU_DRF_MCU_DMEM_FAIL_mcu_drf_mcu_dmem_fail_1_shift                (1)
#define  EMCU_MCU_DRF_MCU_DMEM_FAIL_mcu_drf_mcu_dmem_fail_0_shift                (0)
#define  EMCU_MCU_DRF_MCU_DMEM_FAIL_mcu_drf_mcu_dmem_fail_1_mask                 (0x00000002)
#define  EMCU_MCU_DRF_MCU_DMEM_FAIL_mcu_drf_mcu_dmem_fail_0_mask                 (0x00000001)
#define  EMCU_MCU_DRF_MCU_DMEM_FAIL_mcu_drf_mcu_dmem_fail_1(data)                (0x00000002&((data)<<1))
#define  EMCU_MCU_DRF_MCU_DMEM_FAIL_mcu_drf_mcu_dmem_fail_0(data)                (0x00000001&(data))
#define  EMCU_MCU_DRF_MCU_DMEM_FAIL_get_mcu_drf_mcu_dmem_fail_1(data)            ((0x00000002&(data))>>1)
#define  EMCU_MCU_DRF_MCU_DMEM_FAIL_get_mcu_drf_mcu_dmem_fail_0(data)            (0x00000001&(data))

#define  EMCU_MCU_DRF_MCU_IRAM_FAIL                                              0x18060498
#define  EMCU_MCU_DRF_MCU_IRAM_FAIL_reg_addr                                     "0xB8060498"
#define  EMCU_MCU_DRF_MCU_IRAM_FAIL_reg                                          0xB8060498
#define  EMCU_MCU_DRF_MCU_IRAM_FAIL_inst_addr                                    "0x0019"
#define  set_EMCU_MCU_DRF_MCU_IRAM_FAIL_reg(data)                                (*((volatile unsigned int*)EMCU_MCU_DRF_MCU_IRAM_FAIL_reg)=data)
#define  get_EMCU_MCU_DRF_MCU_IRAM_FAIL_reg                                      (*((volatile unsigned int*)EMCU_MCU_DRF_MCU_IRAM_FAIL_reg))
#define  EMCU_MCU_DRF_MCU_IRAM_FAIL_mcu_drf_mcu_iram_fail_0_shift                (0)
#define  EMCU_MCU_DRF_MCU_IRAM_FAIL_mcu_drf_mcu_iram_fail_0_mask                 (0x00000001)
#define  EMCU_MCU_DRF_MCU_IRAM_FAIL_mcu_drf_mcu_iram_fail_0(data)                (0x00000001&(data))
#define  EMCU_MCU_DRF_MCU_IRAM_FAIL_get_mcu_drf_mcu_iram_fail_0(data)            (0x00000001&(data))

#define  EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL                                         0x1806049C
#define  EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_reg_addr                                "0xB806049C"
#define  EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_reg                                     0xB806049C
#define  EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_inst_addr                               "0x001A"
#define  set_EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_reg(data)                           (*((volatile unsigned int*)EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_reg)=data)
#define  get_EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_reg                                 (*((volatile unsigned int*)EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_reg))
#define  EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_mcu_drf_mcu_always_on_fail_1_shift      (1)
#define  EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_mcu_drf_mcu_always_on_fail_0_shift      (0)
#define  EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_mcu_drf_mcu_always_on_fail_1_mask       (0x00000002)
#define  EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_mcu_drf_mcu_always_on_fail_0_mask       (0x00000001)
#define  EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_mcu_drf_mcu_always_on_fail_1(data)      (0x00000002&((data)<<1))
#define  EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_mcu_drf_mcu_always_on_fail_0(data)      (0x00000001&(data))
#define  EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_get_mcu_drf_mcu_always_on_fail_1(data)  ((0x00000002&(data))>>1)
#define  EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_get_mcu_drf_mcu_always_on_fail_0(data)  (0x00000001&(data))

#define  EMCU_MCU_BISR_MCU_IMEM                                                  0x180604A0
#define  EMCU_MCU_BISR_MCU_IMEM_reg_addr                                         "0xB80604A0"
#define  EMCU_MCU_BISR_MCU_IMEM_reg                                              0xB80604A0
#define  EMCU_MCU_BISR_MCU_IMEM_inst_addr                                        "0x001B"
#define  set_EMCU_MCU_BISR_MCU_IMEM_reg(data)                                    (*((volatile unsigned int*)EMCU_MCU_BISR_MCU_IMEM_reg)=data)
#define  get_EMCU_MCU_BISR_MCU_IMEM_reg                                          (*((volatile unsigned int*)EMCU_MCU_BISR_MCU_IMEM_reg))
#define  EMCU_MCU_BISR_MCU_IMEM_mcu_always_on_imem_bisr_out_shift                (2)
#define  EMCU_MCU_BISR_MCU_IMEM_mcu_always_on_imem_bisr_fail_shift               (1)
#define  EMCU_MCU_BISR_MCU_IMEM_mcu_always_on_imem_bisr_repaired_shift           (0)
#define  EMCU_MCU_BISR_MCU_IMEM_mcu_always_on_imem_bisr_out_mask                 (0x000000FC)
#define  EMCU_MCU_BISR_MCU_IMEM_mcu_always_on_imem_bisr_fail_mask                (0x00000002)
#define  EMCU_MCU_BISR_MCU_IMEM_mcu_always_on_imem_bisr_repaired_mask            (0x00000001)
#define  EMCU_MCU_BISR_MCU_IMEM_mcu_always_on_imem_bisr_out(data)                (0x000000FC&((data)<<2))
#define  EMCU_MCU_BISR_MCU_IMEM_mcu_always_on_imem_bisr_fail(data)               (0x00000002&((data)<<1))
#define  EMCU_MCU_BISR_MCU_IMEM_mcu_always_on_imem_bisr_repaired(data)           (0x00000001&(data))
#define  EMCU_MCU_BISR_MCU_IMEM_get_mcu_always_on_imem_bisr_out(data)            ((0x000000FC&(data))>>2)
#define  EMCU_MCU_BISR_MCU_IMEM_get_mcu_always_on_imem_bisr_fail(data)           ((0x00000002&(data))>>1)
#define  EMCU_MCU_BISR_MCU_IMEM_get_mcu_always_on_imem_bisr_repaired(data)       (0x00000001&(data))

#define  EMCU_MCU_DRF_MCU_IMEM                                                   0x180604A4
#define  EMCU_MCU_DRF_MCU_IMEM_reg_addr                                          "0xB80604A4"
#define  EMCU_MCU_DRF_MCU_IMEM_reg                                               0xB80604A4
#define  EMCU_MCU_DRF_MCU_IMEM_inst_addr                                         "0x001C"
#define  set_EMCU_MCU_DRF_MCU_IMEM_reg(data)                                     (*((volatile unsigned int*)EMCU_MCU_DRF_MCU_IMEM_reg)=data)
#define  get_EMCU_MCU_DRF_MCU_IMEM_reg                                           (*((volatile unsigned int*)EMCU_MCU_DRF_MCU_IMEM_reg))
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_second_run_en_shift            (5)
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_mode_shift            (4)
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_test_resume_shift     (3)
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_done_shift            (2)
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_start_pause_shift     (1)
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_fail_shift            (0)
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_second_run_en_mask             (0x00000020)
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_mode_mask             (0x00000010)
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_test_resume_mask      (0x00000008)
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_done_mask             (0x00000004)
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_start_pause_mask      (0x00000002)
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_fail_mask             (0x00000001)
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_second_run_en(data)            (0x00000020&((data)<<5))
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_mode(data)            (0x00000010&((data)<<4))
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_test_resume(data)     (0x00000008&((data)<<3))
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_done(data)            (0x00000004&((data)<<2))
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_start_pause(data)     (0x00000002&((data)<<1))
#define  EMCU_MCU_DRF_MCU_IMEM_mcu_always_on_imem_drf_bisr_fail(data)            (0x00000001&(data))
#define  EMCU_MCU_DRF_MCU_IMEM_get_mcu_always_on_imem_second_run_en(data)        ((0x00000020&(data))>>5)
#define  EMCU_MCU_DRF_MCU_IMEM_get_mcu_always_on_imem_drf_bisr_mode(data)        ((0x00000010&(data))>>4)
#define  EMCU_MCU_DRF_MCU_IMEM_get_mcu_always_on_imem_drf_bisr_test_resume(data) ((0x00000008&(data))>>3)
#define  EMCU_MCU_DRF_MCU_IMEM_get_mcu_always_on_imem_drf_bisr_done(data)        ((0x00000004&(data))>>2)
#define  EMCU_MCU_DRF_MCU_IMEM_get_mcu_always_on_imem_drf_bisr_start_pause(data) ((0x00000002&(data))>>1)
#define  EMCU_MCU_DRF_MCU_IMEM_get_mcu_always_on_imem_drf_bisr_fail(data)        (0x00000001&(data))

#define  EMCU_MT_rbus_control                                                    0x180604C0
#define  EMCU_MT_rbus_control_reg_addr                                           "0xB80604C0"
#define  EMCU_MT_rbus_control_reg                                                0xB80604C0
#define  EMCU_MT_rbus_control_inst_addr                                          "0x001D"
#define  set_EMCU_MT_rbus_control_reg(data)                                      (*((volatile unsigned int*)EMCU_MT_rbus_control_reg)=data)
#define  get_EMCU_MT_rbus_control_reg                                            (*((volatile unsigned int*)EMCU_MT_rbus_control_reg))
#define  EMCU_MT_rbus_control_mt_rbus_err_shift                                  (2)
#define  EMCU_MT_rbus_control_mt_rbus_rw_shift                                   (1)
#define  EMCU_MT_rbus_control_mt_rbus_req_shift                                  (0)
#define  EMCU_MT_rbus_control_mt_rbus_err_mask                                   (0x00000004)
#define  EMCU_MT_rbus_control_mt_rbus_rw_mask                                    (0x00000002)
#define  EMCU_MT_rbus_control_mt_rbus_req_mask                                   (0x00000001)
#define  EMCU_MT_rbus_control_mt_rbus_err(data)                                  (0x00000004&((data)<<2))
#define  EMCU_MT_rbus_control_mt_rbus_rw(data)                                   (0x00000002&((data)<<1))
#define  EMCU_MT_rbus_control_mt_rbus_req(data)                                  (0x00000001&(data))
#define  EMCU_MT_rbus_control_get_mt_rbus_err(data)                              ((0x00000004&(data))>>2)
#define  EMCU_MT_rbus_control_get_mt_rbus_rw(data)                               ((0x00000002&(data))>>1)
#define  EMCU_MT_rbus_control_get_mt_rbus_req(data)                              (0x00000001&(data))

#define  EMCU_MT_rbus_addr                                                       0x180604C4
#define  EMCU_MT_rbus_addr_reg_addr                                              "0xB80604C4"
#define  EMCU_MT_rbus_addr_reg                                                   0xB80604C4
#define  EMCU_MT_rbus_addr_inst_addr                                             "0x001E"
#define  set_EMCU_MT_rbus_addr_reg(data)                                         (*((volatile unsigned int*)EMCU_MT_rbus_addr_reg)=data)
#define  get_EMCU_MT_rbus_addr_reg                                               (*((volatile unsigned int*)EMCU_MT_rbus_addr_reg))
#define  EMCU_MT_rbus_addr_mt_rbus_addr_rev_shift                                (20)
#define  EMCU_MT_rbus_addr_mt_rbus_addr_shift                                    (0)
#define  EMCU_MT_rbus_addr_mt_rbus_addr_rev_mask                                 (0xFFF00000)
#define  EMCU_MT_rbus_addr_mt_rbus_addr_mask                                     (0x000FFFFF)
#define  EMCU_MT_rbus_addr_mt_rbus_addr_rev(data)                                (0xFFF00000&((data)<<20))
#define  EMCU_MT_rbus_addr_mt_rbus_addr(data)                                    (0x000FFFFF&(data))
#define  EMCU_MT_rbus_addr_get_mt_rbus_addr_rev(data)                            ((0xFFF00000&(data))>>20)
#define  EMCU_MT_rbus_addr_get_mt_rbus_addr(data)                                (0x000FFFFF&(data))

#define  EMCU_MT_rbus_data                                                       0x180604C8
#define  EMCU_MT_rbus_data_reg_addr                                              "0xB80604C8"
#define  EMCU_MT_rbus_data_reg                                                   0xB80604C8
#define  EMCU_MT_rbus_data_inst_addr                                             "0x001F"
#define  set_EMCU_MT_rbus_data_reg(data)                                         (*((volatile unsigned int*)EMCU_MT_rbus_data_reg)=data)
#define  get_EMCU_MT_rbus_data_reg                                               (*((volatile unsigned int*)EMCU_MT_rbus_data_reg))
#define  EMCU_MT_rbus_data_mt_rbus_data_shift                                    (0)
#define  EMCU_MT_rbus_data_mt_rbus_data_mask                                     (0xFFFFFFFF)
#define  EMCU_MT_rbus_data_mt_rbus_data(data)                                    (0xFFFFFFFF&(data))
#define  EMCU_MT_rbus_data_get_mt_rbus_data(data)                                (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======EMCU register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rbus_timeout_ip:4;
        RBus_UInt32  res1:15;
        RBus_UInt32  emcu_top_dbg_sel:3;
        RBus_UInt32  dmem_dbg_sel:1;
        RBus_UInt32  imem_dbg_sel:1;
        RBus_UInt32  rbus_timeout_cycle:3;
        RBus_UInt32  rbus_timeout_int:1;
        RBus_UInt32  rbus_timeout_int_en:1;
        RBus_UInt32  rbus_timeout_enable:1;
        RBus_UInt32  endian_swap:1;
        RBus_UInt32  sleep_mode:1;
    };
}emcu_wrapper_8051_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18060410_31_0:32;
    };
}emcu_emcu_debug_8051_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  mcu_always_on_dmem_rme:1;
        RBus_UInt32  mcu_always_on_imem_rme:1;
        RBus_UInt32  mcu_shmem_rme:1;
        RBus_UInt32  mcu_iram_rme:1;
        RBus_UInt32  mcu_imem_rme:1;
        RBus_UInt32  mcu_dmem_rme:1;
    };
}emcu_mcu_mem_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  mcu_off_ram_rm_3:1;
        RBus_UInt32  mcu_always_on_dmem_rm:4;
        RBus_UInt32  mcu_always_on_imem_rm:4;
        RBus_UInt32  mcu_shmem_rm:4;
        RBus_UInt32  mcu_iram_rm:4;
        RBus_UInt32  mcu_imem_rm:4;
        RBus_UInt32  mcu_dmem_rm:4;
    };
}emcu_mcu_mem_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mcu_mem_ls:1;
    };
}emcu_mcu_mem_light_sleep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18060428_31_0:32;
    };
}emcu_emcu_debug_8051_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  sys_prog_en:1;
    };
}emcu_system_cpu_program_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_imem_addr:14;
        RBus_UInt32  imem_reload:1;
        RBus_UInt32  imem_auto:1;
        RBus_UInt32  imem_addr:14;
    };
}emcu_imem_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  imem_data:32;
    };
}emcu_imem_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cur_dmem_addr:9;
        RBus_UInt32  dmem_reload:1;
        RBus_UInt32  dmem_auto:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dmem_addr:9;
    };
}emcu_dmem_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmem_data:32;
    };
}emcu_dmem_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  stip_cbus_tx:1;
        RBus_UInt32  stip_wol:1;
        RBus_UInt32  stip_self_wakeup:1;
        RBus_UInt32  stip_rbus:1;
        RBus_UInt32  stip_hdmi_clk_det:1;
        RBus_UInt32  stip_st_syncp:1;
        RBus_UInt32  stip_cec:1;
        RBus_UInt32  stip_isomisc:1;
        RBus_UInt32  stip_isomisc_off:1;
        RBus_UInt32  stip_rtc:1;
        RBus_UInt32  stip_cbus_det:1;
    };
}emcu_st_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  stie_cbus_tx:1;
        RBus_UInt32  stie_wol:1;
        RBus_UInt32  stie_self_wakeup:1;
        RBus_UInt32  stie_rbus:1;
        RBus_UInt32  stie_hdmi_clk_det:1;
        RBus_UInt32  stie_st_syncp:1;
        RBus_UInt32  stie_cec:1;
        RBus_UInt32  stie_isomisc:1;
        RBus_UInt32  stie_isomisc_off:1;
        RBus_UInt32  stie_rtc:1;
        RBus_UInt32  stie_cbus_det:1;
    };
}emcu_st_ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mcu_bist_mode_mcu_always_on:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mcu_bist_mode_mcu_iram:1;
        RBus_UInt32  mcu_bist_mode_mcu_dmem:1;
    };
}emcu_mcu_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mcu_bist_done_mcu_always_on:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mcu_bist_done_mcu_iram:1;
        RBus_UInt32  mcu_bist_done_mcu_dmem:1;
    };
}emcu_mcu_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mcu_bist_fail_group_mcu_always_on:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mcu_bist_fail_group_mcu_iram:1;
        RBus_UInt32  mcu_bist_fail_group_mcu_dmem:1;
    };
}emcu_mcu_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  mcu_bist_mcu_dmem_fail_1:1;
        RBus_UInt32  mcu_bist_mcu_dmem_fail_0:1;
    };
}emcu_mcu_bist_mcu_dmem_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mcu_bist_mcu_iram_fail_0:1;
    };
}emcu_mcu_bist_mcu_iram_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  mcu_bist_mcu_always_on_fail_1:1;
        RBus_UInt32  mcu_bist_mcu_always_on_fail_0:1;
    };
}emcu_mcu_bist_mcu_always_on_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mcu_drf_mode_mcu_always_on:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mcu_drf_mode_mcu_iram:1;
        RBus_UInt32  mcu_drf_mode_mcu_dmem:1;
    };
}emcu_mcu_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mcu_drf_resume_mcu_always_on:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mcu_drf_resume_mcu_iram:1;
        RBus_UInt32  mcu_drf_resume_mcu_dmem:1;
    };
}emcu_mcu_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mcu_drf_done_mcu_always_on:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mcu_drf_done_mcu_iram:1;
        RBus_UInt32  mcu_drf_done_mcu_dmem:1;
    };
}emcu_mcu_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mcu_drf_pause_mcu_always_on:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mcu_drf_pause_mcu_iram:1;
        RBus_UInt32  mcu_drf_pause_mcu_dmem:1;
    };
}emcu_mcu_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mcu_drf_fail_group_mcu_always_on:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mcu_drf_fail_group_mcu_iram:1;
        RBus_UInt32  mcu_drf_fail_group_mcu_dmem:1;
    };
}emcu_mcu_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  mcu_drf_mcu_dmem_fail_1:1;
        RBus_UInt32  mcu_drf_mcu_dmem_fail_0:1;
    };
}emcu_mcu_drf_mcu_dmem_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mcu_drf_mcu_iram_fail_0:1;
    };
}emcu_mcu_drf_mcu_iram_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  mcu_drf_mcu_always_on_fail_1:1;
        RBus_UInt32  mcu_drf_mcu_always_on_fail_0:1;
    };
}emcu_mcu_drf_mcu_always_on_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mcu_always_on_imem_bisr_out:6;
        RBus_UInt32  mcu_always_on_imem_bisr_fail:1;
        RBus_UInt32  mcu_always_on_imem_bisr_repaired:1;
    };
}emcu_mcu_bisr_mcu_imem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  mcu_always_on_imem_second_run_en:1;
        RBus_UInt32  mcu_always_on_imem_drf_bisr_mode:1;
        RBus_UInt32  mcu_always_on_imem_drf_bisr_test_resume:1;
        RBus_UInt32  mcu_always_on_imem_drf_bisr_done:1;
        RBus_UInt32  mcu_always_on_imem_drf_bisr_start_pause:1;
        RBus_UInt32  mcu_always_on_imem_drf_bisr_fail:1;
    };
}emcu_mcu_drf_mcu_imem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  mt_rbus_err:1;
        RBus_UInt32  mt_rbus_rw:1;
        RBus_UInt32  mt_rbus_req:1;
    };
}emcu_mt_rbus_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mt_rbus_addr_rev:12;
        RBus_UInt32  mt_rbus_addr:20;
    };
}emcu_mt_rbus_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mt_rbus_data:32;
    };
}emcu_mt_rbus_data_RBUS;

#else //apply LITTLE_ENDIAN

//======EMCU register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sleep_mode:1;
        RBus_UInt32  endian_swap:1;
        RBus_UInt32  rbus_timeout_enable:1;
        RBus_UInt32  rbus_timeout_int_en:1;
        RBus_UInt32  rbus_timeout_int:1;
        RBus_UInt32  rbus_timeout_cycle:3;
        RBus_UInt32  imem_dbg_sel:1;
        RBus_UInt32  dmem_dbg_sel:1;
        RBus_UInt32  emcu_top_dbg_sel:3;
        RBus_UInt32  res1:15;
        RBus_UInt32  rbus_timeout_ip:4;
    };
}emcu_wrapper_8051_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18060410_31_0:32;
    };
}emcu_emcu_debug_8051_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_dmem_rme:1;
        RBus_UInt32  mcu_imem_rme:1;
        RBus_UInt32  mcu_iram_rme:1;
        RBus_UInt32  mcu_shmem_rme:1;
        RBus_UInt32  mcu_always_on_imem_rme:1;
        RBus_UInt32  mcu_always_on_dmem_rme:1;
        RBus_UInt32  res1:26;
    };
}emcu_mcu_mem_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_dmem_rm:4;
        RBus_UInt32  mcu_imem_rm:4;
        RBus_UInt32  mcu_iram_rm:4;
        RBus_UInt32  mcu_shmem_rm:4;
        RBus_UInt32  mcu_always_on_imem_rm:4;
        RBus_UInt32  mcu_always_on_dmem_rm:4;
        RBus_UInt32  mcu_off_ram_rm_3:1;
        RBus_UInt32  res1:7;
    };
}emcu_mcu_mem_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_mem_ls:1;
        RBus_UInt32  res1:31;
    };
}emcu_mcu_mem_light_sleep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18060428_31_0:32;
    };
}emcu_emcu_debug_8051_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog_en:1;
        RBus_UInt32  res1:31;
    };
}emcu_system_cpu_program_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  imem_addr:14;
        RBus_UInt32  imem_auto:1;
        RBus_UInt32  imem_reload:1;
        RBus_UInt32  cur_imem_addr:14;
        RBus_UInt32  res1:2;
    };
}emcu_imem_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  imem_data:32;
    };
}emcu_imem_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmem_addr:9;
        RBus_UInt32  res1:1;
        RBus_UInt32  dmem_auto:1;
        RBus_UInt32  dmem_reload:1;
        RBus_UInt32  cur_dmem_addr:9;
        RBus_UInt32  res2:11;
    };
}emcu_dmem_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmem_data:32;
    };
}emcu_dmem_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stip_cbus_det:1;
        RBus_UInt32  stip_rtc:1;
        RBus_UInt32  stip_isomisc_off:1;
        RBus_UInt32  stip_isomisc:1;
        RBus_UInt32  stip_cec:1;
        RBus_UInt32  stip_st_syncp:1;
        RBus_UInt32  stip_hdmi_clk_det:1;
        RBus_UInt32  stip_rbus:1;
        RBus_UInt32  stip_self_wakeup:1;
        RBus_UInt32  stip_wol:1;
        RBus_UInt32  stip_cbus_tx:1;
        RBus_UInt32  res1:21;
    };
}emcu_st_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stie_cbus_det:1;
        RBus_UInt32  stie_rtc:1;
        RBus_UInt32  stie_isomisc_off:1;
        RBus_UInt32  stie_isomisc:1;
        RBus_UInt32  stie_cec:1;
        RBus_UInt32  stie_st_syncp:1;
        RBus_UInt32  stie_hdmi_clk_det:1;
        RBus_UInt32  stie_rbus:1;
        RBus_UInt32  stie_self_wakeup:1;
        RBus_UInt32  stie_wol:1;
        RBus_UInt32  stie_cbus_tx:1;
        RBus_UInt32  res1:21;
    };
}emcu_st_ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_bist_mode_mcu_dmem:1;
        RBus_UInt32  mcu_bist_mode_mcu_iram:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mcu_bist_mode_mcu_always_on:1;
        RBus_UInt32  res2:28;
    };
}emcu_mcu_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_bist_done_mcu_dmem:1;
        RBus_UInt32  mcu_bist_done_mcu_iram:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mcu_bist_done_mcu_always_on:1;
        RBus_UInt32  res2:28;
    };
}emcu_mcu_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_bist_fail_group_mcu_dmem:1;
        RBus_UInt32  mcu_bist_fail_group_mcu_iram:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mcu_bist_fail_group_mcu_always_on:1;
        RBus_UInt32  res2:28;
    };
}emcu_mcu_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_bist_mcu_dmem_fail_0:1;
        RBus_UInt32  mcu_bist_mcu_dmem_fail_1:1;
        RBus_UInt32  res1:30;
    };
}emcu_mcu_bist_mcu_dmem_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_bist_mcu_iram_fail_0:1;
        RBus_UInt32  res1:31;
    };
}emcu_mcu_bist_mcu_iram_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_bist_mcu_always_on_fail_0:1;
        RBus_UInt32  mcu_bist_mcu_always_on_fail_1:1;
        RBus_UInt32  res1:30;
    };
}emcu_mcu_bist_mcu_always_on_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_drf_mode_mcu_dmem:1;
        RBus_UInt32  mcu_drf_mode_mcu_iram:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mcu_drf_mode_mcu_always_on:1;
        RBus_UInt32  res2:28;
    };
}emcu_mcu_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_drf_resume_mcu_dmem:1;
        RBus_UInt32  mcu_drf_resume_mcu_iram:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mcu_drf_resume_mcu_always_on:1;
        RBus_UInt32  res2:28;
    };
}emcu_mcu_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_drf_done_mcu_dmem:1;
        RBus_UInt32  mcu_drf_done_mcu_iram:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mcu_drf_done_mcu_always_on:1;
        RBus_UInt32  res2:28;
    };
}emcu_mcu_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_drf_pause_mcu_dmem:1;
        RBus_UInt32  mcu_drf_pause_mcu_iram:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mcu_drf_pause_mcu_always_on:1;
        RBus_UInt32  res2:28;
    };
}emcu_mcu_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_drf_fail_group_mcu_dmem:1;
        RBus_UInt32  mcu_drf_fail_group_mcu_iram:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mcu_drf_fail_group_mcu_always_on:1;
        RBus_UInt32  res2:28;
    };
}emcu_mcu_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_drf_mcu_dmem_fail_0:1;
        RBus_UInt32  mcu_drf_mcu_dmem_fail_1:1;
        RBus_UInt32  res1:30;
    };
}emcu_mcu_drf_mcu_dmem_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_drf_mcu_iram_fail_0:1;
        RBus_UInt32  res1:31;
    };
}emcu_mcu_drf_mcu_iram_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_drf_mcu_always_on_fail_0:1;
        RBus_UInt32  mcu_drf_mcu_always_on_fail_1:1;
        RBus_UInt32  res1:30;
    };
}emcu_mcu_drf_mcu_always_on_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_always_on_imem_bisr_repaired:1;
        RBus_UInt32  mcu_always_on_imem_bisr_fail:1;
        RBus_UInt32  mcu_always_on_imem_bisr_out:6;
        RBus_UInt32  res1:24;
    };
}emcu_mcu_bisr_mcu_imem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_always_on_imem_drf_bisr_fail:1;
        RBus_UInt32  mcu_always_on_imem_drf_bisr_start_pause:1;
        RBus_UInt32  mcu_always_on_imem_drf_bisr_done:1;
        RBus_UInt32  mcu_always_on_imem_drf_bisr_test_resume:1;
        RBus_UInt32  mcu_always_on_imem_drf_bisr_mode:1;
        RBus_UInt32  mcu_always_on_imem_second_run_en:1;
        RBus_UInt32  res1:26;
    };
}emcu_mcu_drf_mcu_imem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mt_rbus_req:1;
        RBus_UInt32  mt_rbus_rw:1;
        RBus_UInt32  mt_rbus_err:1;
        RBus_UInt32  res1:29;
    };
}emcu_mt_rbus_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mt_rbus_addr:20;
        RBus_UInt32  mt_rbus_addr_rev:12;
    };
}emcu_mt_rbus_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mt_rbus_data:32;
    };
}emcu_mt_rbus_data_RBUS;




#endif 


#endif 
