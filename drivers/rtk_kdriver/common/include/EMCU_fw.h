/*=============================================================
* Copyright C        Realtek Semiconductor Corporation, 2004 *
* All rights reserved.                                       *
* Build by tools[RS_MM2_SD] For FW                           *
*============================================================*/
/*======================= Description =======================*/
/*
 * @date 2014/7/30
 * @version { 1.0 }
*/

#ifndef _EMCU_REG_H_INCLUDED_
#define _EMCU_REG_H_INCLUDED_

//#define _EMCU_USE_STRUCT
#ifdef _EMCU_USE_STRUCT

typedef struct
{
        unsigned int  reserved_0:19;
        unsigned int  emcu_top_dbg_sel:3;
        unsigned int  dmem_dbg_sel:1;
        unsigned int  imem_dbg_sel:1;
        unsigned int  reserved_1:1;
        unsigned int  rbus_timeout_cycle:2;
        unsigned int  rbus_timeout_int:1;
        unsigned int  rbus_timeout_int_en:1;
        unsigned int  rbus_timeout_enable:1;
        unsigned int  endian_swap:1;
        unsigned int  sleep_mode:1;
}wrapper_8051;

typedef struct
{
        unsigned int  dummy18060410_31_0:32;
}emcu_debug_8051;

typedef struct
{
        unsigned int  reserved_0:26;
        unsigned int  mcu_always_on_dmem_rme:1;
        unsigned int  mcu_always_on_imem_rme:1;
        unsigned int  mcu_shmem_rme:1;
        unsigned int  mcu_iram_rme:1;
        unsigned int  mcu_imem_rme:1;
        unsigned int  mcu_dmem_rme:1;
}MCU_MEM_RME;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  mcu_always_on_dmem_rm:4;
        unsigned int  mcu_always_on_imem_rm:4;
        unsigned int  mcu_shmem_rm:4;
        unsigned int  mcu_iram_rm:4;
        unsigned int  mcu_imem_rm:4;
        unsigned int  mcu_dmem_rm:4;
}MCU_MEM_RM;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  mcu_mem_ls:1;
}MCU_MEM_LIGHT_SLEEP;

typedef struct
{
        unsigned int  dummy18060428_31_0:32;
}emcu_debug_8051_4;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  sys_prog_en:1;
}system_CPU_program_enable;

typedef struct
{
        unsigned int  reserved_0:2;
        unsigned int  cur_imem_addr:14;
        unsigned int  imem_reload:1;
        unsigned int  imem_auto:1;
        unsigned int  imem_addr:14;
}IMEM_control;

typedef struct
{
        unsigned int  imem_data:32;
}IMEM_data;

typedef struct
{
        unsigned int  reserved_0:11;
        unsigned int  cur_dmem_addr:9;
        unsigned int  dmem_reload:1;
        unsigned int  dmem_auto:1;
        unsigned int  reserved_1:1;
        unsigned int  dmem_addr:9;
}DMEM_control;

typedef struct
{
        unsigned int  dmem_data:32;
}DMEM_data;

typedef struct
{
        unsigned int  reserved_0:22;
        unsigned int  stip_wol:1;
        unsigned int  stip_self_wakeup:1;
        unsigned int  stip_rbus:1;
        unsigned int  stip_hdmi_clk_det:1;
        unsigned int  stip_st_syncp:1;
        unsigned int  stip_cec:1;
        unsigned int  stip_isomisc:1;
        unsigned int  stip_isomisc_off:1;
        unsigned int  stip_rtc:1;
        unsigned int  stip_cbus_det:1;
}ST_IP;

typedef struct
{
        unsigned int  reserved_0:22;
        unsigned int  stie_wol:1;
        unsigned int  stie_self_wakeup:1;
        unsigned int  stie_rbus:1;
        unsigned int  stie_hdmi_clk_det:1;
        unsigned int  stie_st_syncp:1;
        unsigned int  stie_cec:1;
        unsigned int  stie_isomisc:1;
        unsigned int  stie_isomisc_off:1;
        unsigned int  stie_rtc:1;
        unsigned int  stie_cbus_det:1;
}ST_IE;

typedef struct
{
        unsigned int  reserved_0:28;
        unsigned int  mcu_bist_mode_mcu_always_on:1;
        unsigned int  mcu_bist_mode_mcu_imem:1;
        unsigned int  mcu_bist_mode_mcu_iram:1;
        unsigned int  mcu_bist_mode_mcu_dmem:1;
}MCU_BIST_MODE;

typedef struct
{
        unsigned int  reserved_0:28;
        unsigned int  mcu_bist_done_mcu_always_on:1;
        unsigned int  mcu_bist_done_mcu_imem:1;
        unsigned int  mcu_bist_done_mcu_iram:1;
        unsigned int  mcu_bist_done_mcu_dmem:1;
}MCU_BIST_DONE;

typedef struct
{
        unsigned int  reserved_0:28;
        unsigned int  mcu_bist_fail_group_mcu_always_on:1;
        unsigned int  mcu_bist_fail_group_mcu_imem:1;
        unsigned int  mcu_bist_fail_group_mcu_iram:1;
        unsigned int  mcu_bist_fail_group_mcu_dmem:1;
}MCU_BIST_FAIL_GROUP;

typedef struct
{
        unsigned int  reserved_0:30;
        unsigned int  mcu_bist_mcu_dmem_fail_1:1;
        unsigned int  mcu_bist_mcu_dmem_fail_0:1;
}MCU_BIST_MCU_DMEM_FAIL;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  mcu_bist_mcu_iram_fail_0:1;
}MCU_BIST_MCU_IRAM_FAIL;

typedef struct
{
        unsigned int  reserved_0:30;
        unsigned int  mcu_bist_mcu_always_on_fail_1:1;
        unsigned int  mcu_bist_mcu_always_on_fail_0:1;
}MCU_BIST_MCU_ALWAYS_ON_FAIL;

typedef struct
{
        unsigned int  reserved_0:28;
        unsigned int  mcu_drf_mode_mcu_always_on:1;
        unsigned int  mcu_drf_mode_mcu_imem:1;
        unsigned int  mcu_drf_mode_mcu_iram:1;
        unsigned int  mcu_drf_mode_mcu_dmem:1;
}MCU_DRF_MODE;

typedef struct
{
        unsigned int  reserved_0:28;
        unsigned int  mcu_drf_resume_mcu_always_on:1;
        unsigned int  mcu_drf_resume_mcu_imem:1;
        unsigned int  mcu_drf_resume_mcu_iram:1;
        unsigned int  mcu_drf_resume_mcu_dmem:1;
}MCU_DRF_RESUME;

typedef struct
{
        unsigned int  reserved_0:28;
        unsigned int  mcu_drf_done_mcu_always_on:1;
        unsigned int  mcu_drf_done_mcu_imem:1;
        unsigned int  mcu_drf_done_mcu_iram:1;
        unsigned int  mcu_drf_done_mcu_dmem:1;
}MCU_DRF_DONE;

typedef struct
{
        unsigned int  reserved_0:28;
        unsigned int  mcu_drf_pause_mcu_always_on:1;
        unsigned int  mcu_drf_pause_mcu_imem:1;
        unsigned int  mcu_drf_pause_mcu_iram:1;
        unsigned int  mcu_drf_pause_mcu_dmem:1;
}MCU_DRF_PAUSE;

typedef struct
{
        unsigned int  reserved_0:28;
        unsigned int  mcu_drf_fail_group_mcu_always_on:1;
        unsigned int  mcu_drf_fail_group_mcu_imem:1;
        unsigned int  mcu_drf_fail_group_mcu_iram:1;
        unsigned int  mcu_drf_fail_group_mcu_dmem:1;
}MCU_DRF_FAIL_GROUP;

typedef struct
{
        unsigned int  reserved_0:30;
        unsigned int  mcu_drf_mcu_dmem_fail_1:1;
        unsigned int  mcu_drf_mcu_dmem_fail_0:1;
}MCU_DRF_MCU_DMEM_FAIL;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  mcu_drf_mcu_iram_fail_0:1;
}MCU_DRF_MCU_IRAM_FAIL;

typedef struct
{
        unsigned int  reserved_0:30;
        unsigned int  mcu_drf_mcu_always_on_fail_1:1;
        unsigned int  mcu_drf_mcu_always_on_fail_0:1;
}MCU_DRF_MCU_ALWAYS_ON_FAIL;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  mcu_bist_mcu_imem_fail_0:1;
}MCU_BIST_MCU_IMEM_FAIL;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  mcu_drf_mcu_imem_fail_0:1;
}MCU_DRF_MCU_IMEM_FAIL;

typedef struct
{
        unsigned int  reserved_0:29;
        unsigned int  mt_rbus_err:1;
        unsigned int  mt_rbus_rw:1;
        unsigned int  mt_rbus_req:1;
}MT_rbus_control;

typedef struct
{
        unsigned int  mt_rbus_addr:32;
}MT_rbus_addr;

typedef struct
{
        unsigned int  mt_rbus_data:32;
}MT_rbus_data;

#define  wrapper_8051                                                           0x18060400
#define  wrapper_8051_reg_addr                                                  "0xB8060400"
#define  wrapper_8051_reg                                                       0xB8060400
#define  wrapper_8051_inst_addr                                                 "0x0000"
#define  wrapper_8051_inst                                                      0x0000
#define  wrapper_8051_emcu_top_dbg_sel_shift                                    (10)
#define  wrapper_8051_dmem_dbg_sel_shift                                        (9)
#define  wrapper_8051_imem_dbg_sel_shift                                        (8)
#define  wrapper_8051_rbus_timeout_cycle_shift                                  (5)
#define  wrapper_8051_rbus_timeout_int_shift                                    (4)
#define  wrapper_8051_rbus_timeout_int_en_shift                                 (3)
#define  wrapper_8051_rbus_timeout_enable_shift                                 (2)
#define  wrapper_8051_endian_swap_shift                                         (1)
#define  wrapper_8051_sleep_mode_shift                                          (0)
#define  wrapper_8051_emcu_top_dbg_sel_mask                                     (0x00001C00)
#define  wrapper_8051_dmem_dbg_sel_mask                                         (0x00000200)
#define  wrapper_8051_imem_dbg_sel_mask                                         (0x00000100)
#define  wrapper_8051_rbus_timeout_cycle_mask                                   (0x00000060)
#define  wrapper_8051_rbus_timeout_int_mask                                     (0x00000010)
#define  wrapper_8051_rbus_timeout_int_en_mask                                  (0x00000008)
#define  wrapper_8051_rbus_timeout_enable_mask                                  (0x00000004)
#define  wrapper_8051_endian_swap_mask                                          (0x00000002)
#define  wrapper_8051_sleep_mode_mask                                           (0x00000001)
#define  wrapper_8051_emcu_top_dbg_sel(data)                                    (0x00001C00&((data)<<10))
#define  wrapper_8051_dmem_dbg_sel(data)                                        (0x00000200&((data)<<9))
#define  wrapper_8051_imem_dbg_sel(data)                                        (0x00000100&((data)<<8))
#define  wrapper_8051_rbus_timeout_cycle(data)                                  (0x00000060&((data)<<5))
#define  wrapper_8051_rbus_timeout_int(data)                                    (0x00000010&((data)<<4))
#define  wrapper_8051_rbus_timeout_int_en(data)                                 (0x00000008&((data)<<3))
#define  wrapper_8051_rbus_timeout_enable(data)                                 (0x00000004&((data)<<2))
#define  wrapper_8051_endian_swap(data)                                         (0x00000002&((data)<<1))
#define  wrapper_8051_sleep_mode(data)                                          (0x00000001&(data))
#define  wrapper_8051_get_emcu_top_dbg_sel(data)                                ((0x00001C00&(data))>>10)
#define  wrapper_8051_get_dmem_dbg_sel(data)                                    ((0x00000200&(data))>>9)
#define  wrapper_8051_get_imem_dbg_sel(data)                                    ((0x00000100&(data))>>8)
#define  wrapper_8051_get_rbus_timeout_cycle(data)                              ((0x00000060&(data))>>5)
#define  wrapper_8051_get_rbus_timeout_int(data)                                ((0x00000010&(data))>>4)
#define  wrapper_8051_get_rbus_timeout_int_en(data)                             ((0x00000008&(data))>>3)
#define  wrapper_8051_get_rbus_timeout_enable(data)                             ((0x00000004&(data))>>2)
#define  wrapper_8051_get_endian_swap(data)                                     ((0x00000002&(data))>>1)
#define  wrapper_8051_get_sleep_mode(data)                                      (0x00000001&(data))

#define  emcu_debug_8051                                                        0x18060410
#define  emcu_debug_8051_reg_addr                                               "0xB8060410"
#define  emcu_debug_8051_reg                                                    0xB8060410
#define  emcu_debug_8051_inst_addr                                              "0x0001"
#define  emcu_debug_8051_inst                                                   0x0001
#define  emcu_debug_8051_dummy_shift                                            (0)
#define  emcu_debug_8051_dummy_mask                                             (0xFFFFFFFF)
#define  emcu_debug_8051_dummy(data)                                            (0xFFFFFFFF&(data))
#define  emcu_debug_8051_get_dummy(data)                                        (0xFFFFFFFF&(data))

#define  MCU_MEM_RME                                                            0x18060414
#define  MCU_MEM_RME_reg_addr                                                   "0xB8060414"
#define  MCU_MEM_RME_reg                                                        0xB8060414
#define  MCU_MEM_RME_inst_addr                                                  "0x0002"
#define  MCU_MEM_RME_inst                                                       0x0002
#define  MCU_MEM_RME_mcu_always_on_dmem_rme_shift                               (5)
#define  MCU_MEM_RME_mcu_always_on_imem_rme_shift                               (4)
#define  MCU_MEM_RME_mcu_shmem_rme_shift                                        (3)
#define  MCU_MEM_RME_mcu_iram_rme_shift                                         (2)
#define  MCU_MEM_RME_mcu_imem_rme_shift                                         (1)
#define  MCU_MEM_RME_mcu_dmem_rme_shift                                         (0)
#define  MCU_MEM_RME_mcu_always_on_dmem_rme_mask                                (0x00000020)
#define  MCU_MEM_RME_mcu_always_on_imem_rme_mask                                (0x00000010)
#define  MCU_MEM_RME_mcu_shmem_rme_mask                                         (0x00000008)
#define  MCU_MEM_RME_mcu_iram_rme_mask                                          (0x00000004)
#define  MCU_MEM_RME_mcu_imem_rme_mask                                          (0x00000002)
#define  MCU_MEM_RME_mcu_dmem_rme_mask                                          (0x00000001)
#define  MCU_MEM_RME_mcu_always_on_dmem_rme(data)                               (0x00000020&((data)<<5))
#define  MCU_MEM_RME_mcu_always_on_imem_rme(data)                               (0x00000010&((data)<<4))
#define  MCU_MEM_RME_mcu_shmem_rme(data)                                        (0x00000008&((data)<<3))
#define  MCU_MEM_RME_mcu_iram_rme(data)                                         (0x00000004&((data)<<2))
#define  MCU_MEM_RME_mcu_imem_rme(data)                                         (0x00000002&((data)<<1))
#define  MCU_MEM_RME_mcu_dmem_rme(data)                                         (0x00000001&(data))
#define  MCU_MEM_RME_get_mcu_always_on_dmem_rme(data)                           ((0x00000020&(data))>>5)
#define  MCU_MEM_RME_get_mcu_always_on_imem_rme(data)                           ((0x00000010&(data))>>4)
#define  MCU_MEM_RME_get_mcu_shmem_rme(data)                                    ((0x00000008&(data))>>3)
#define  MCU_MEM_RME_get_mcu_iram_rme(data)                                     ((0x00000004&(data))>>2)
#define  MCU_MEM_RME_get_mcu_imem_rme(data)                                     ((0x00000002&(data))>>1)
#define  MCU_MEM_RME_get_mcu_dmem_rme(data)                                     (0x00000001&(data))

#define  MCU_MEM_RM                                                             0x18060420
#define  MCU_MEM_RM_reg_addr                                                    "0xB8060420"
#define  MCU_MEM_RM_reg                                                         0xB8060420
#define  MCU_MEM_RM_inst_addr                                                   "0x0003"
#define  MCU_MEM_RM_inst                                                        0x0003
#define  MCU_MEM_RM_mcu_always_on_dmem_rm_shift                                 (20)
#define  MCU_MEM_RM_mcu_always_on_imem_rm_shift                                 (16)
#define  MCU_MEM_RM_mcu_shmem_rm_shift                                          (12)
#define  MCU_MEM_RM_mcu_iram_rm_shift                                           (8)
#define  MCU_MEM_RM_mcu_imem_rm_shift                                           (4)
#define  MCU_MEM_RM_mcu_dmem_rm_shift                                           (0)
#define  MCU_MEM_RM_mcu_always_on_dmem_rm_mask                                  (0x00F00000)
#define  MCU_MEM_RM_mcu_always_on_imem_rm_mask                                  (0x000F0000)
#define  MCU_MEM_RM_mcu_shmem_rm_mask                                           (0x0000F000)
#define  MCU_MEM_RM_mcu_iram_rm_mask                                            (0x00000F00)
#define  MCU_MEM_RM_mcu_imem_rm_mask                                            (0x000000F0)
#define  MCU_MEM_RM_mcu_dmem_rm_mask                                            (0x0000000F)
#define  MCU_MEM_RM_mcu_always_on_dmem_rm(data)                                 (0x00F00000&((data)<<20))
#define  MCU_MEM_RM_mcu_always_on_imem_rm(data)                                 (0x000F0000&((data)<<16))
#define  MCU_MEM_RM_mcu_shmem_rm(data)                                          (0x0000F000&((data)<<12))
#define  MCU_MEM_RM_mcu_iram_rm(data)                                           (0x00000F00&((data)<<8))
#define  MCU_MEM_RM_mcu_imem_rm(data)                                           (0x000000F0&((data)<<4))
#define  MCU_MEM_RM_mcu_dmem_rm(data)                                           (0x0000000F&(data))
#define  MCU_MEM_RM_get_mcu_always_on_dmem_rm(data)                             ((0x00F00000&(data))>>20)
#define  MCU_MEM_RM_get_mcu_always_on_imem_rm(data)                             ((0x000F0000&(data))>>16)
#define  MCU_MEM_RM_get_mcu_shmem_rm(data)                                      ((0x0000F000&(data))>>12)
#define  MCU_MEM_RM_get_mcu_iram_rm(data)                                       ((0x00000F00&(data))>>8)
#define  MCU_MEM_RM_get_mcu_imem_rm(data)                                       ((0x000000F0&(data))>>4)
#define  MCU_MEM_RM_get_mcu_dmem_rm(data)                                       (0x0000000F&(data))

#define  MCU_MEM_LIGHT_SLEEP                                                    0x18060424
#define  MCU_MEM_LIGHT_SLEEP_reg_addr                                           "0xB8060424"
#define  MCU_MEM_LIGHT_SLEEP_reg                                                0xB8060424
#define  MCU_MEM_LIGHT_SLEEP_inst_addr                                          "0x0004"
#define  MCU_MEM_LIGHT_SLEEP_inst                                               0x0004
#define  MCU_MEM_LIGHT_SLEEP_mcu_mem_ls_shift                                   (0)
#define  MCU_MEM_LIGHT_SLEEP_mcu_mem_ls_mask                                    (0x00000001)
#define  MCU_MEM_LIGHT_SLEEP_mcu_mem_ls(data)                                   (0x00000001&(data))
#define  MCU_MEM_LIGHT_SLEEP_get_mcu_mem_ls(data)                               (0x00000001&(data))

#define  emcu_debug_8051_4                                                      0x18060428
#define  emcu_debug_8051_4_reg_addr                                             "0xB8060428"
#define  emcu_debug_8051_4_reg                                                  0xB8060428
#define  emcu_debug_8051_4_inst_addr                                            "0x0005"
#define  emcu_debug_8051_4_inst                                                 0x0005
#define  emcu_debug_8051_4_dummy_shift                                          (0)
#define  emcu_debug_8051_4_dummy_mask                                           (0xFFFFFFFF)
#define  emcu_debug_8051_4_dummy(data)                                          (0xFFFFFFFF&(data))
#define  emcu_debug_8051_4_get_dummy(data)                                      (0xFFFFFFFF&(data))

#define  system_CPU_program_enable                                              0x18060430
#define  system_CPU_program_enable_reg_addr                                     "0xB8060430"
#define  system_CPU_program_enable_reg                                          0xB8060430
#define  system_CPU_program_enable_inst_addr                                    "0x0006"
#define  system_CPU_program_enable_inst                                         0x0006
#define  system_CPU_program_enable_sys_prog_en_shift                            (0)
#define  system_CPU_program_enable_sys_prog_en_mask                             (0x00000001)
#define  system_CPU_program_enable_sys_prog_en(data)                            (0x00000001&(data))
#define  system_CPU_program_enable_get_sys_prog_en(data)                        (0x00000001&(data))

#define  IMEM_control                                                           0x18060434
#define  IMEM_control_reg_addr                                                  "0xB8060434"
#define  IMEM_control_reg                                                       0xB8060434
#define  IMEM_control_inst_addr                                                 "0x0007"
#define  IMEM_control_inst                                                      0x0007
#define  IMEM_control_cur_imem_addr_shift                                       (16)
#define  IMEM_control_imem_reload_shift                                         (15)
#define  IMEM_control_imem_auto_shift                                           (14)
#define  IMEM_control_imem_addr_shift                                           (0)
#define  IMEM_control_cur_imem_addr_mask                                        (0x3FFF0000)
#define  IMEM_control_imem_reload_mask                                          (0x00008000)
#define  IMEM_control_imem_auto_mask                                            (0x00004000)
#define  IMEM_control_imem_addr_mask                                            (0x00003FFF)
#define  IMEM_control_cur_imem_addr(data)                                       (0x3FFF0000&((data)<<16))
#define  IMEM_control_imem_reload(data)                                         (0x00008000&((data)<<15))
#define  IMEM_control_imem_auto(data)                                           (0x00004000&((data)<<14))
#define  IMEM_control_imem_addr(data)                                           (0x00003FFF&(data))
#define  IMEM_control_get_cur_imem_addr(data)                                   ((0x3FFF0000&(data))>>16)
#define  IMEM_control_get_imem_reload(data)                                     ((0x00008000&(data))>>15)
#define  IMEM_control_get_imem_auto(data)                                       ((0x00004000&(data))>>14)
#define  IMEM_control_get_imem_addr(data)                                       (0x00003FFF&(data))

#define  IMEM_data                                                              0x18060438
#define  IMEM_data_reg_addr                                                     "0xB8060438"
#define  IMEM_data_reg                                                          0xB8060438
#define  IMEM_data_inst_addr                                                    "0x0008"
#define  IMEM_data_inst                                                         0x0008
#define  IMEM_data_imem_data_shift                                              (0)
#define  IMEM_data_imem_data_mask                                               (0xFFFFFFFF)
#define  IMEM_data_imem_data(data)                                              (0xFFFFFFFF&(data))
#define  IMEM_data_get_imem_data(data)                                          (0xFFFFFFFF&(data))

#define  DMEM_control                                                           0x1806043C
#define  DMEM_control_reg_addr                                                  "0xB806043C"
#define  DMEM_control_reg                                                       0xB806043C
#define  DMEM_control_inst_addr                                                 "0x0009"
#define  DMEM_control_inst                                                      0x0009
#define  DMEM_control_cur_dmem_addr_shift                                       (12)
#define  DMEM_control_dmem_reload_shift                                         (11)
#define  DMEM_control_dmem_auto_shift                                           (10)
#define  DMEM_control_dmem_addr_shift                                           (0)
#define  DMEM_control_cur_dmem_addr_mask                                        (0x001FF000)
#define  DMEM_control_dmem_reload_mask                                          (0x00000800)
#define  DMEM_control_dmem_auto_mask                                            (0x00000400)
#define  DMEM_control_dmem_addr_mask                                            (0x000001FF)
#define  DMEM_control_cur_dmem_addr(data)                                       (0x001FF000&((data)<<12))
#define  DMEM_control_dmem_reload(data)                                         (0x00000800&((data)<<11))
#define  DMEM_control_dmem_auto(data)                                           (0x00000400&((data)<<10))
#define  DMEM_control_dmem_addr(data)                                           (0x000001FF&(data))
#define  DMEM_control_get_cur_dmem_addr(data)                                   ((0x001FF000&(data))>>12)
#define  DMEM_control_get_dmem_reload(data)                                     ((0x00000800&(data))>>11)
#define  DMEM_control_get_dmem_auto(data)                                       ((0x00000400&(data))>>10)
#define  DMEM_control_get_dmem_addr(data)                                       (0x000001FF&(data))

#define  DMEM_data                                                              0x18060440
#define  DMEM_data_reg_addr                                                     "0xB8060440"
#define  DMEM_data_reg                                                          0xB8060440
#define  DMEM_data_inst_addr                                                    "0x000A"
#define  DMEM_data_inst                                                         0x000A
#define  DMEM_data_dmem_data_shift                                              (0)
#define  DMEM_data_dmem_data_mask                                               (0xFFFFFFFF)
#define  DMEM_data_dmem_data(data)                                              (0xFFFFFFFF&(data))
#define  DMEM_data_get_dmem_data(data)                                          (0xFFFFFFFF&(data))

#define  ST_IP                                                                  0x18060450
#define  ST_IP_reg_addr                                                         "0xB8060450"
#define  ST_IP_reg                                                              0xB8060450
#define  ST_IP_inst_addr                                                        "0x000B"
#define  ST_IP_inst                                                             0x000B
#define  ST_IP_stip_wol_shift                                                   (9)
#define  ST_IP_stip_self_wakeup_shift                                           (8)
#define  ST_IP_stip_rbus_shift                                                  (7)
#define  ST_IP_stip_hdmi_clk_det_shift                                          (6)
#define  ST_IP_stip_st_syncp_shift                                              (5)
#define  ST_IP_stip_cec_shift                                                   (4)
#define  ST_IP_stip_isomisc_shift                                               (3)
#define  ST_IP_stip_isomisc_off_shift                                           (2)
#define  ST_IP_stip_rtc_shift                                                   (1)
#define  ST_IP_stip_cbus_det_shift                                              (0)
#define  ST_IP_stip_wol_mask                                                    (0x00000200)
#define  ST_IP_stip_self_wakeup_mask                                            (0x00000100)
#define  ST_IP_stip_rbus_mask                                                   (0x00000080)
#define  ST_IP_stip_hdmi_clk_det_mask                                           (0x00000040)
#define  ST_IP_stip_st_syncp_mask                                               (0x00000020)
#define  ST_IP_stip_cec_mask                                                    (0x00000010)
#define  ST_IP_stip_isomisc_mask                                                (0x00000008)
#define  ST_IP_stip_isomisc_off_mask                                            (0x00000004)
#define  ST_IP_stip_rtc_mask                                                    (0x00000002)
#define  ST_IP_stip_cbus_det_mask                                               (0x00000001)
#define  ST_IP_stip_wol(data)                                                   (0x00000200&((data)<<9))
#define  ST_IP_stip_self_wakeup(data)                                           (0x00000100&((data)<<8))
#define  ST_IP_stip_rbus(data)                                                  (0x00000080&((data)<<7))
#define  ST_IP_stip_hdmi_clk_det(data)                                          (0x00000040&((data)<<6))
#define  ST_IP_stip_st_syncp(data)                                              (0x00000020&((data)<<5))
#define  ST_IP_stip_cec(data)                                                   (0x00000010&((data)<<4))
#define  ST_IP_stip_isomisc(data)                                               (0x00000008&((data)<<3))
#define  ST_IP_stip_isomisc_off(data)                                           (0x00000004&((data)<<2))
#define  ST_IP_stip_rtc(data)                                                   (0x00000002&((data)<<1))
#define  ST_IP_stip_cbus_det(data)                                              (0x00000001&(data))
#define  ST_IP_get_stip_wol(data)                                               ((0x00000200&(data))>>9)
#define  ST_IP_get_stip_self_wakeup(data)                                       ((0x00000100&(data))>>8)
#define  ST_IP_get_stip_rbus(data)                                              ((0x00000080&(data))>>7)
#define  ST_IP_get_stip_hdmi_clk_det(data)                                      ((0x00000040&(data))>>6)
#define  ST_IP_get_stip_st_syncp(data)                                          ((0x00000020&(data))>>5)
#define  ST_IP_get_stip_cec(data)                                               ((0x00000010&(data))>>4)
#define  ST_IP_get_stip_isomisc(data)                                           ((0x00000008&(data))>>3)
#define  ST_IP_get_stip_isomisc_off(data)                                       ((0x00000004&(data))>>2)
#define  ST_IP_get_stip_rtc(data)                                               ((0x00000002&(data))>>1)
#define  ST_IP_get_stip_cbus_det(data)                                          (0x00000001&(data))

#define  ST_IE                                                                  0x18060454
#define  ST_IE_reg_addr                                                         "0xB8060454"
#define  ST_IE_reg                                                              0xB8060454
#define  ST_IE_inst_addr                                                        "0x000C"
#define  ST_IE_inst                                                             0x000C
#define  ST_IE_stie_wol_shift                                                   (9)
#define  ST_IE_stie_self_wakeup_shift                                           (8)
#define  ST_IE_stie_rbus_shift                                                  (7)
#define  ST_IE_stie_hdmi_clk_det_shift                                          (6)
#define  ST_IE_stie_st_syncp_shift                                              (5)
#define  ST_IE_stie_cec_shift                                                   (4)
#define  ST_IE_stie_isomisc_shift                                               (3)
#define  ST_IE_stie_isomisc_off_shift                                           (2)
#define  ST_IE_stie_rtc_shift                                                   (1)
#define  ST_IE_stie_cbus_det_shift                                              (0)
#define  ST_IE_stie_wol_mask                                                    (0x00000200)
#define  ST_IE_stie_self_wakeup_mask                                            (0x00000100)
#define  ST_IE_stie_rbus_mask                                                   (0x00000080)
#define  ST_IE_stie_hdmi_clk_det_mask                                           (0x00000040)
#define  ST_IE_stie_st_syncp_mask                                               (0x00000020)
#define  ST_IE_stie_cec_mask                                                    (0x00000010)
#define  ST_IE_stie_isomisc_mask                                                (0x00000008)
#define  ST_IE_stie_isomisc_off_mask                                            (0x00000004)
#define  ST_IE_stie_rtc_mask                                                    (0x00000002)
#define  ST_IE_stie_cbus_det_mask                                               (0x00000001)
#define  ST_IE_stie_wol(data)                                                   (0x00000200&((data)<<9))
#define  ST_IE_stie_self_wakeup(data)                                           (0x00000100&((data)<<8))
#define  ST_IE_stie_rbus(data)                                                  (0x00000080&((data)<<7))
#define  ST_IE_stie_hdmi_clk_det(data)                                          (0x00000040&((data)<<6))
#define  ST_IE_stie_st_syncp(data)                                              (0x00000020&((data)<<5))
#define  ST_IE_stie_cec(data)                                                   (0x00000010&((data)<<4))
#define  ST_IE_stie_isomisc(data)                                               (0x00000008&((data)<<3))
#define  ST_IE_stie_isomisc_off(data)                                           (0x00000004&((data)<<2))
#define  ST_IE_stie_rtc(data)                                                   (0x00000002&((data)<<1))
#define  ST_IE_stie_cbus_det(data)                                              (0x00000001&(data))
#define  ST_IE_get_stie_wol(data)                                               ((0x00000200&(data))>>9)
#define  ST_IE_get_stie_self_wakeup(data)                                       ((0x00000100&(data))>>8)
#define  ST_IE_get_stie_rbus(data)                                              ((0x00000080&(data))>>7)
#define  ST_IE_get_stie_hdmi_clk_det(data)                                      ((0x00000040&(data))>>6)
#define  ST_IE_get_stie_st_syncp(data)                                          ((0x00000020&(data))>>5)
#define  ST_IE_get_stie_cec(data)                                               ((0x00000010&(data))>>4)
#define  ST_IE_get_stie_isomisc(data)                                           ((0x00000008&(data))>>3)
#define  ST_IE_get_stie_isomisc_off(data)                                       ((0x00000004&(data))>>2)
#define  ST_IE_get_stie_rtc(data)                                               ((0x00000002&(data))>>1)
#define  ST_IE_get_stie_cbus_det(data)                                          (0x00000001&(data))

#define  MCU_BIST_MODE                                                          0x18060460
#define  MCU_BIST_MODE_reg_addr                                                 "0xB8060460"
#define  MCU_BIST_MODE_reg                                                      0xB8060460
#define  MCU_BIST_MODE_inst_addr                                                "0x000D"
#define  MCU_BIST_MODE_inst                                                     0x000D
#define  MCU_BIST_MODE_mcu_bist_mode_mcu_always_on_shift                        (3)
#define  MCU_BIST_MODE_mcu_bist_mode_mcu_imem_shift                             (2)
#define  MCU_BIST_MODE_mcu_bist_mode_mcu_iram_shift                             (1)
#define  MCU_BIST_MODE_mcu_bist_mode_mcu_dmem_shift                             (0)
#define  MCU_BIST_MODE_mcu_bist_mode_mcu_always_on_mask                         (0x00000008)
#define  MCU_BIST_MODE_mcu_bist_mode_mcu_imem_mask                              (0x00000004)
#define  MCU_BIST_MODE_mcu_bist_mode_mcu_iram_mask                              (0x00000002)
#define  MCU_BIST_MODE_mcu_bist_mode_mcu_dmem_mask                              (0x00000001)
#define  MCU_BIST_MODE_mcu_bist_mode_mcu_always_on(data)                        (0x00000008&((data)<<3))
#define  MCU_BIST_MODE_mcu_bist_mode_mcu_imem(data)                             (0x00000004&((data)<<2))
#define  MCU_BIST_MODE_mcu_bist_mode_mcu_iram(data)                             (0x00000002&((data)<<1))
#define  MCU_BIST_MODE_mcu_bist_mode_mcu_dmem(data)                             (0x00000001&(data))
#define  MCU_BIST_MODE_get_mcu_bist_mode_mcu_always_on(data)                    ((0x00000008&(data))>>3)
#define  MCU_BIST_MODE_get_mcu_bist_mode_mcu_imem(data)                         ((0x00000004&(data))>>2)
#define  MCU_BIST_MODE_get_mcu_bist_mode_mcu_iram(data)                         ((0x00000002&(data))>>1)
#define  MCU_BIST_MODE_get_mcu_bist_mode_mcu_dmem(data)                         (0x00000001&(data))

#define  MCU_BIST_DONE                                                          0x18060464
#define  MCU_BIST_DONE_reg_addr                                                 "0xB8060464"
#define  MCU_BIST_DONE_reg                                                      0xB8060464
#define  MCU_BIST_DONE_inst_addr                                                "0x000E"
#define  MCU_BIST_DONE_inst                                                     0x000E
#define  MCU_BIST_DONE_mcu_bist_done_mcu_always_on_shift                        (3)
#define  MCU_BIST_DONE_mcu_bist_done_mcu_imem_shift                             (2)
#define  MCU_BIST_DONE_mcu_bist_done_mcu_iram_shift                             (1)
#define  MCU_BIST_DONE_mcu_bist_done_mcu_dmem_shift                             (0)
#define  MCU_BIST_DONE_mcu_bist_done_mcu_always_on_mask                         (0x00000008)
#define  MCU_BIST_DONE_mcu_bist_done_mcu_imem_mask                              (0x00000004)
#define  MCU_BIST_DONE_mcu_bist_done_mcu_iram_mask                              (0x00000002)
#define  MCU_BIST_DONE_mcu_bist_done_mcu_dmem_mask                              (0x00000001)
#define  MCU_BIST_DONE_mcu_bist_done_mcu_always_on(data)                        (0x00000008&((data)<<3))
#define  MCU_BIST_DONE_mcu_bist_done_mcu_imem(data)                             (0x00000004&((data)<<2))
#define  MCU_BIST_DONE_mcu_bist_done_mcu_iram(data)                             (0x00000002&((data)<<1))
#define  MCU_BIST_DONE_mcu_bist_done_mcu_dmem(data)                             (0x00000001&(data))
#define  MCU_BIST_DONE_get_mcu_bist_done_mcu_always_on(data)                    ((0x00000008&(data))>>3)
#define  MCU_BIST_DONE_get_mcu_bist_done_mcu_imem(data)                         ((0x00000004&(data))>>2)
#define  MCU_BIST_DONE_get_mcu_bist_done_mcu_iram(data)                         ((0x00000002&(data))>>1)
#define  MCU_BIST_DONE_get_mcu_bist_done_mcu_dmem(data)                         (0x00000001&(data))

#define  MCU_BIST_FAIL_GROUP                                                    0x18060468
#define  MCU_BIST_FAIL_GROUP_reg_addr                                           "0xB8060468"
#define  MCU_BIST_FAIL_GROUP_reg                                                0xB8060468
#define  MCU_BIST_FAIL_GROUP_inst_addr                                          "0x000F"
#define  MCU_BIST_FAIL_GROUP_inst                                               0x000F
#define  MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_always_on_shift            (3)
#define  MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_imem_shift                 (2)
#define  MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_iram_shift                 (1)
#define  MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_dmem_shift                 (0)
#define  MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_always_on_mask             (0x00000008)
#define  MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_imem_mask                  (0x00000004)
#define  MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_iram_mask                  (0x00000002)
#define  MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_dmem_mask                  (0x00000001)
#define  MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_always_on(data)            (0x00000008&((data)<<3))
#define  MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_imem(data)                 (0x00000004&((data)<<2))
#define  MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_iram(data)                 (0x00000002&((data)<<1))
#define  MCU_BIST_FAIL_GROUP_mcu_bist_fail_group_mcu_dmem(data)                 (0x00000001&(data))
#define  MCU_BIST_FAIL_GROUP_get_mcu_bist_fail_group_mcu_always_on(data)        ((0x00000008&(data))>>3)
#define  MCU_BIST_FAIL_GROUP_get_mcu_bist_fail_group_mcu_imem(data)             ((0x00000004&(data))>>2)
#define  MCU_BIST_FAIL_GROUP_get_mcu_bist_fail_group_mcu_iram(data)             ((0x00000002&(data))>>1)
#define  MCU_BIST_FAIL_GROUP_get_mcu_bist_fail_group_mcu_dmem(data)             (0x00000001&(data))

#define  MCU_BIST_MCU_DMEM_FAIL                                                 0x1806046C
#define  MCU_BIST_MCU_DMEM_FAIL_reg_addr                                        "0xB806046C"
#define  MCU_BIST_MCU_DMEM_FAIL_reg                                             0xB806046C
#define  MCU_BIST_MCU_DMEM_FAIL_inst_addr                                       "0x0010"
#define  MCU_BIST_MCU_DMEM_FAIL_inst                                            0x0010
#define  MCU_BIST_MCU_DMEM_FAIL_mcu_bist_mcu_dmem_fail_1_shift                  (1)
#define  MCU_BIST_MCU_DMEM_FAIL_mcu_bist_mcu_dmem_fail_0_shift                  (0)
#define  MCU_BIST_MCU_DMEM_FAIL_mcu_bist_mcu_dmem_fail_1_mask                   (0x00000002)
#define  MCU_BIST_MCU_DMEM_FAIL_mcu_bist_mcu_dmem_fail_0_mask                   (0x00000001)
#define  MCU_BIST_MCU_DMEM_FAIL_mcu_bist_mcu_dmem_fail_1(data)                  (0x00000002&((data)<<1))
#define  MCU_BIST_MCU_DMEM_FAIL_mcu_bist_mcu_dmem_fail_0(data)                  (0x00000001&(data))
#define  MCU_BIST_MCU_DMEM_FAIL_get_mcu_bist_mcu_dmem_fail_1(data)              ((0x00000002&(data))>>1)
#define  MCU_BIST_MCU_DMEM_FAIL_get_mcu_bist_mcu_dmem_fail_0(data)              (0x00000001&(data))

#define  MCU_BIST_MCU_IRAM_FAIL                                                 0x18060474
#define  MCU_BIST_MCU_IRAM_FAIL_reg_addr                                        "0xB8060474"
#define  MCU_BIST_MCU_IRAM_FAIL_reg                                             0xB8060474
#define  MCU_BIST_MCU_IRAM_FAIL_inst_addr                                       "0x0011"
#define  MCU_BIST_MCU_IRAM_FAIL_inst                                            0x0011
#define  MCU_BIST_MCU_IRAM_FAIL_mcu_bist_mcu_iram_fail_0_shift                  (0)
#define  MCU_BIST_MCU_IRAM_FAIL_mcu_bist_mcu_iram_fail_0_mask                   (0x00000001)
#define  MCU_BIST_MCU_IRAM_FAIL_mcu_bist_mcu_iram_fail_0(data)                  (0x00000001&(data))
#define  MCU_BIST_MCU_IRAM_FAIL_get_mcu_bist_mcu_iram_fail_0(data)              (0x00000001&(data))

#define  MCU_BIST_MCU_ALWAYS_ON_FAIL                                            0x18060478
#define  MCU_BIST_MCU_ALWAYS_ON_FAIL_reg_addr                                   "0xB8060478"
#define  MCU_BIST_MCU_ALWAYS_ON_FAIL_reg                                        0xB8060478
#define  MCU_BIST_MCU_ALWAYS_ON_FAIL_inst_addr                                  "0x0012"
#define  MCU_BIST_MCU_ALWAYS_ON_FAIL_inst                                       0x0012
#define  MCU_BIST_MCU_ALWAYS_ON_FAIL_mcu_bist_mcu_always_on_fail_1_shift        (1)
#define  MCU_BIST_MCU_ALWAYS_ON_FAIL_mcu_bist_mcu_always_on_fail_0_shift        (0)
#define  MCU_BIST_MCU_ALWAYS_ON_FAIL_mcu_bist_mcu_always_on_fail_1_mask         (0x00000002)
#define  MCU_BIST_MCU_ALWAYS_ON_FAIL_mcu_bist_mcu_always_on_fail_0_mask         (0x00000001)
#define  MCU_BIST_MCU_ALWAYS_ON_FAIL_mcu_bist_mcu_always_on_fail_1(data)        (0x00000002&((data)<<1))
#define  MCU_BIST_MCU_ALWAYS_ON_FAIL_mcu_bist_mcu_always_on_fail_0(data)        (0x00000001&(data))
#define  MCU_BIST_MCU_ALWAYS_ON_FAIL_get_mcu_bist_mcu_always_on_fail_1(data)    ((0x00000002&(data))>>1)
#define  MCU_BIST_MCU_ALWAYS_ON_FAIL_get_mcu_bist_mcu_always_on_fail_0(data)    (0x00000001&(data))

#define  MCU_DRF_MODE                                                           0x1806047C
#define  MCU_DRF_MODE_reg_addr                                                  "0xB806047C"
#define  MCU_DRF_MODE_reg                                                       0xB806047C
#define  MCU_DRF_MODE_inst_addr                                                 "0x0013"
#define  MCU_DRF_MODE_inst                                                      0x0013
#define  MCU_DRF_MODE_mcu_drf_mode_mcu_always_on_shift                          (3)
#define  MCU_DRF_MODE_mcu_drf_mode_mcu_imem_shift                               (2)
#define  MCU_DRF_MODE_mcu_drf_mode_mcu_iram_shift                               (1)
#define  MCU_DRF_MODE_mcu_drf_mode_mcu_dmem_shift                               (0)
#define  MCU_DRF_MODE_mcu_drf_mode_mcu_always_on_mask                           (0x00000008)
#define  MCU_DRF_MODE_mcu_drf_mode_mcu_imem_mask                                (0x00000004)
#define  MCU_DRF_MODE_mcu_drf_mode_mcu_iram_mask                                (0x00000002)
#define  MCU_DRF_MODE_mcu_drf_mode_mcu_dmem_mask                                (0x00000001)
#define  MCU_DRF_MODE_mcu_drf_mode_mcu_always_on(data)                          (0x00000008&((data)<<3))
#define  MCU_DRF_MODE_mcu_drf_mode_mcu_imem(data)                               (0x00000004&((data)<<2))
#define  MCU_DRF_MODE_mcu_drf_mode_mcu_iram(data)                               (0x00000002&((data)<<1))
#define  MCU_DRF_MODE_mcu_drf_mode_mcu_dmem(data)                               (0x00000001&(data))
#define  MCU_DRF_MODE_get_mcu_drf_mode_mcu_always_on(data)                      ((0x00000008&(data))>>3)
#define  MCU_DRF_MODE_get_mcu_drf_mode_mcu_imem(data)                           ((0x00000004&(data))>>2)
#define  MCU_DRF_MODE_get_mcu_drf_mode_mcu_iram(data)                           ((0x00000002&(data))>>1)
#define  MCU_DRF_MODE_get_mcu_drf_mode_mcu_dmem(data)                           (0x00000001&(data))

#define  MCU_DRF_RESUME                                                         0x18060480
#define  MCU_DRF_RESUME_reg_addr                                                "0xB8060480"
#define  MCU_DRF_RESUME_reg                                                     0xB8060480
#define  MCU_DRF_RESUME_inst_addr                                               "0x0014"
#define  MCU_DRF_RESUME_inst                                                    0x0014
#define  MCU_DRF_RESUME_mcu_drf_resume_mcu_always_on_shift                      (3)
#define  MCU_DRF_RESUME_mcu_drf_resume_mcu_imem_shift                           (2)
#define  MCU_DRF_RESUME_mcu_drf_resume_mcu_iram_shift                           (1)
#define  MCU_DRF_RESUME_mcu_drf_resume_mcu_dmem_shift                           (0)
#define  MCU_DRF_RESUME_mcu_drf_resume_mcu_always_on_mask                       (0x00000008)
#define  MCU_DRF_RESUME_mcu_drf_resume_mcu_imem_mask                            (0x00000004)
#define  MCU_DRF_RESUME_mcu_drf_resume_mcu_iram_mask                            (0x00000002)
#define  MCU_DRF_RESUME_mcu_drf_resume_mcu_dmem_mask                            (0x00000001)
#define  MCU_DRF_RESUME_mcu_drf_resume_mcu_always_on(data)                      (0x00000008&((data)<<3))
#define  MCU_DRF_RESUME_mcu_drf_resume_mcu_imem(data)                           (0x00000004&((data)<<2))
#define  MCU_DRF_RESUME_mcu_drf_resume_mcu_iram(data)                           (0x00000002&((data)<<1))
#define  MCU_DRF_RESUME_mcu_drf_resume_mcu_dmem(data)                           (0x00000001&(data))
#define  MCU_DRF_RESUME_get_mcu_drf_resume_mcu_always_on(data)                  ((0x00000008&(data))>>3)
#define  MCU_DRF_RESUME_get_mcu_drf_resume_mcu_imem(data)                       ((0x00000004&(data))>>2)
#define  MCU_DRF_RESUME_get_mcu_drf_resume_mcu_iram(data)                       ((0x00000002&(data))>>1)
#define  MCU_DRF_RESUME_get_mcu_drf_resume_mcu_dmem(data)                       (0x00000001&(data))

#define  MCU_DRF_DONE                                                           0x18060484
#define  MCU_DRF_DONE_reg_addr                                                  "0xB8060484"
#define  MCU_DRF_DONE_reg                                                       0xB8060484
#define  MCU_DRF_DONE_inst_addr                                                 "0x0015"
#define  MCU_DRF_DONE_inst                                                      0x0015
#define  MCU_DRF_DONE_mcu_drf_done_mcu_always_on_shift                          (3)
#define  MCU_DRF_DONE_mcu_drf_done_mcu_imem_shift                               (2)
#define  MCU_DRF_DONE_mcu_drf_done_mcu_iram_shift                               (1)
#define  MCU_DRF_DONE_mcu_drf_done_mcu_dmem_shift                               (0)
#define  MCU_DRF_DONE_mcu_drf_done_mcu_always_on_mask                           (0x00000008)
#define  MCU_DRF_DONE_mcu_drf_done_mcu_imem_mask                                (0x00000004)
#define  MCU_DRF_DONE_mcu_drf_done_mcu_iram_mask                                (0x00000002)
#define  MCU_DRF_DONE_mcu_drf_done_mcu_dmem_mask                                (0x00000001)
#define  MCU_DRF_DONE_mcu_drf_done_mcu_always_on(data)                          (0x00000008&((data)<<3))
#define  MCU_DRF_DONE_mcu_drf_done_mcu_imem(data)                               (0x00000004&((data)<<2))
#define  MCU_DRF_DONE_mcu_drf_done_mcu_iram(data)                               (0x00000002&((data)<<1))
#define  MCU_DRF_DONE_mcu_drf_done_mcu_dmem(data)                               (0x00000001&(data))
#define  MCU_DRF_DONE_get_mcu_drf_done_mcu_always_on(data)                      ((0x00000008&(data))>>3)
#define  MCU_DRF_DONE_get_mcu_drf_done_mcu_imem(data)                           ((0x00000004&(data))>>2)
#define  MCU_DRF_DONE_get_mcu_drf_done_mcu_iram(data)                           ((0x00000002&(data))>>1)
#define  MCU_DRF_DONE_get_mcu_drf_done_mcu_dmem(data)                           (0x00000001&(data))

#define  MCU_DRF_PAUSE                                                          0x18060488
#define  MCU_DRF_PAUSE_reg_addr                                                 "0xB8060488"
#define  MCU_DRF_PAUSE_reg                                                      0xB8060488
#define  MCU_DRF_PAUSE_inst_addr                                                "0x0016"
#define  MCU_DRF_PAUSE_inst                                                     0x0016
#define  MCU_DRF_PAUSE_mcu_drf_pause_mcu_always_on_shift                        (3)
#define  MCU_DRF_PAUSE_mcu_drf_pause_mcu_imem_shift                             (2)
#define  MCU_DRF_PAUSE_mcu_drf_pause_mcu_iram_shift                             (1)
#define  MCU_DRF_PAUSE_mcu_drf_pause_mcu_dmem_shift                             (0)
#define  MCU_DRF_PAUSE_mcu_drf_pause_mcu_always_on_mask                         (0x00000008)
#define  MCU_DRF_PAUSE_mcu_drf_pause_mcu_imem_mask                              (0x00000004)
#define  MCU_DRF_PAUSE_mcu_drf_pause_mcu_iram_mask                              (0x00000002)
#define  MCU_DRF_PAUSE_mcu_drf_pause_mcu_dmem_mask                              (0x00000001)
#define  MCU_DRF_PAUSE_mcu_drf_pause_mcu_always_on(data)                        (0x00000008&((data)<<3))
#define  MCU_DRF_PAUSE_mcu_drf_pause_mcu_imem(data)                             (0x00000004&((data)<<2))
#define  MCU_DRF_PAUSE_mcu_drf_pause_mcu_iram(data)                             (0x00000002&((data)<<1))
#define  MCU_DRF_PAUSE_mcu_drf_pause_mcu_dmem(data)                             (0x00000001&(data))
#define  MCU_DRF_PAUSE_get_mcu_drf_pause_mcu_always_on(data)                    ((0x00000008&(data))>>3)
#define  MCU_DRF_PAUSE_get_mcu_drf_pause_mcu_imem(data)                         ((0x00000004&(data))>>2)
#define  MCU_DRF_PAUSE_get_mcu_drf_pause_mcu_iram(data)                         ((0x00000002&(data))>>1)
#define  MCU_DRF_PAUSE_get_mcu_drf_pause_mcu_dmem(data)                         (0x00000001&(data))

#define  MCU_DRF_FAIL_GROUP                                                     0x1806048C
#define  MCU_DRF_FAIL_GROUP_reg_addr                                            "0xB806048C"
#define  MCU_DRF_FAIL_GROUP_reg                                                 0xB806048C
#define  MCU_DRF_FAIL_GROUP_inst_addr                                           "0x0017"
#define  MCU_DRF_FAIL_GROUP_inst                                                0x0017
#define  MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_always_on_shift              (3)
#define  MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_imem_shift                   (2)
#define  MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_iram_shift                   (1)
#define  MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_dmem_shift                   (0)
#define  MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_always_on_mask               (0x00000008)
#define  MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_imem_mask                    (0x00000004)
#define  MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_iram_mask                    (0x00000002)
#define  MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_dmem_mask                    (0x00000001)
#define  MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_always_on(data)              (0x00000008&((data)<<3))
#define  MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_imem(data)                   (0x00000004&((data)<<2))
#define  MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_iram(data)                   (0x00000002&((data)<<1))
#define  MCU_DRF_FAIL_GROUP_mcu_drf_fail_group_mcu_dmem(data)                   (0x00000001&(data))
#define  MCU_DRF_FAIL_GROUP_get_mcu_drf_fail_group_mcu_always_on(data)          ((0x00000008&(data))>>3)
#define  MCU_DRF_FAIL_GROUP_get_mcu_drf_fail_group_mcu_imem(data)               ((0x00000004&(data))>>2)
#define  MCU_DRF_FAIL_GROUP_get_mcu_drf_fail_group_mcu_iram(data)               ((0x00000002&(data))>>1)
#define  MCU_DRF_FAIL_GROUP_get_mcu_drf_fail_group_mcu_dmem(data)               (0x00000001&(data))

#define  MCU_DRF_MCU_DMEM_FAIL                                                  0x18060490
#define  MCU_DRF_MCU_DMEM_FAIL_reg_addr                                         "0xB8060490"
#define  MCU_DRF_MCU_DMEM_FAIL_reg                                              0xB8060490
#define  MCU_DRF_MCU_DMEM_FAIL_inst_addr                                        "0x0018"
#define  MCU_DRF_MCU_DMEM_FAIL_inst                                             0x0018
#define  MCU_DRF_MCU_DMEM_FAIL_mcu_drf_mcu_dmem_fail_1_shift                    (1)
#define  MCU_DRF_MCU_DMEM_FAIL_mcu_drf_mcu_dmem_fail_0_shift                    (0)
#define  MCU_DRF_MCU_DMEM_FAIL_mcu_drf_mcu_dmem_fail_1_mask                     (0x00000002)
#define  MCU_DRF_MCU_DMEM_FAIL_mcu_drf_mcu_dmem_fail_0_mask                     (0x00000001)
#define  MCU_DRF_MCU_DMEM_FAIL_mcu_drf_mcu_dmem_fail_1(data)                    (0x00000002&((data)<<1))
#define  MCU_DRF_MCU_DMEM_FAIL_mcu_drf_mcu_dmem_fail_0(data)                    (0x00000001&(data))
#define  MCU_DRF_MCU_DMEM_FAIL_get_mcu_drf_mcu_dmem_fail_1(data)                ((0x00000002&(data))>>1)
#define  MCU_DRF_MCU_DMEM_FAIL_get_mcu_drf_mcu_dmem_fail_0(data)                (0x00000001&(data))

#define  MCU_DRF_MCU_IRAM_FAIL                                                  0x18060498
#define  MCU_DRF_MCU_IRAM_FAIL_reg_addr                                         "0xB8060498"
#define  MCU_DRF_MCU_IRAM_FAIL_reg                                              0xB8060498
#define  MCU_DRF_MCU_IRAM_FAIL_inst_addr                                        "0x0019"
#define  MCU_DRF_MCU_IRAM_FAIL_inst                                             0x0019
#define  MCU_DRF_MCU_IRAM_FAIL_mcu_drf_mcu_iram_fail_0_shift                    (0)
#define  MCU_DRF_MCU_IRAM_FAIL_mcu_drf_mcu_iram_fail_0_mask                     (0x00000001)
#define  MCU_DRF_MCU_IRAM_FAIL_mcu_drf_mcu_iram_fail_0(data)                    (0x00000001&(data))
#define  MCU_DRF_MCU_IRAM_FAIL_get_mcu_drf_mcu_iram_fail_0(data)                (0x00000001&(data))

#define  MCU_DRF_MCU_ALWAYS_ON_FAIL                                             0x1806049C
#define  MCU_DRF_MCU_ALWAYS_ON_FAIL_reg_addr                                    "0xB806049C"
#define  MCU_DRF_MCU_ALWAYS_ON_FAIL_reg                                         0xB806049C
#define  MCU_DRF_MCU_ALWAYS_ON_FAIL_inst_addr                                   "0x001A"
#define  MCU_DRF_MCU_ALWAYS_ON_FAIL_inst                                        0x001A
#define  MCU_DRF_MCU_ALWAYS_ON_FAIL_mcu_drf_mcu_always_on_fail_1_shift          (1)
#define  MCU_DRF_MCU_ALWAYS_ON_FAIL_mcu_drf_mcu_always_on_fail_0_shift          (0)
#define  MCU_DRF_MCU_ALWAYS_ON_FAIL_mcu_drf_mcu_always_on_fail_1_mask           (0x00000002)
#define  MCU_DRF_MCU_ALWAYS_ON_FAIL_mcu_drf_mcu_always_on_fail_0_mask           (0x00000001)
#define  MCU_DRF_MCU_ALWAYS_ON_FAIL_mcu_drf_mcu_always_on_fail_1(data)          (0x00000002&((data)<<1))
#define  MCU_DRF_MCU_ALWAYS_ON_FAIL_mcu_drf_mcu_always_on_fail_0(data)          (0x00000001&(data))
#define  MCU_DRF_MCU_ALWAYS_ON_FAIL_get_mcu_drf_mcu_always_on_fail_1(data)      ((0x00000002&(data))>>1)
#define  MCU_DRF_MCU_ALWAYS_ON_FAIL_get_mcu_drf_mcu_always_on_fail_0(data)      (0x00000001&(data))

#define  MCU_BIST_MCU_IMEM_FAIL                                                 0x180604A0
#define  MCU_BIST_MCU_IMEM_FAIL_reg_addr                                        "0xB80604A0"
#define  MCU_BIST_MCU_IMEM_FAIL_reg                                             0xB80604A0
#define  MCU_BIST_MCU_IMEM_FAIL_inst_addr                                       "0x001B"
#define  MCU_BIST_MCU_IMEM_FAIL_inst                                            0x001B
#define  MCU_BIST_MCU_IMEM_FAIL_mcu_bist_mcu_imem_fail_0_shift                  (0)
#define  MCU_BIST_MCU_IMEM_FAIL_mcu_bist_mcu_imem_fail_0_mask                   (0x00000001)
#define  MCU_BIST_MCU_IMEM_FAIL_mcu_bist_mcu_imem_fail_0(data)                  (0x00000001&(data))
#define  MCU_BIST_MCU_IMEM_FAIL_get_mcu_bist_mcu_imem_fail_0(data)              (0x00000001&(data))

#define  MCU_DRF_MCU_IMEM_FAIL                                                  0x180604A4
#define  MCU_DRF_MCU_IMEM_FAIL_reg_addr                                         "0xB80604A4"
#define  MCU_DRF_MCU_IMEM_FAIL_reg                                              0xB80604A4
#define  MCU_DRF_MCU_IMEM_FAIL_inst_addr                                        "0x001C"
#define  MCU_DRF_MCU_IMEM_FAIL_inst                                             0x001C
#define  MCU_DRF_MCU_IMEM_FAIL_mcu_drf_mcu_imem_fail_0_shift                    (0)
#define  MCU_DRF_MCU_IMEM_FAIL_mcu_drf_mcu_imem_fail_0_mask                     (0x00000001)
#define  MCU_DRF_MCU_IMEM_FAIL_mcu_drf_mcu_imem_fail_0(data)                    (0x00000001&(data))
#define  MCU_DRF_MCU_IMEM_FAIL_get_mcu_drf_mcu_imem_fail_0(data)                (0x00000001&(data))

#define  MT_rbus_control                                                        0x180604C0
#define  MT_rbus_control_reg_addr                                               "0xB80604C0"
#define  MT_rbus_control_reg                                                    0xB80604C0
#define  MT_rbus_control_inst_addr                                              "0x001D"
#define  MT_rbus_control_inst                                                   0x001D
#define  MT_rbus_control_mt_rbus_err_shift                                      (2)
#define  MT_rbus_control_mt_rbus_rw_shift                                       (1)
#define  MT_rbus_control_mt_rbus_req_shift                                      (0)
#define  MT_rbus_control_mt_rbus_err_mask                                       (0x00000004)
#define  MT_rbus_control_mt_rbus_rw_mask                                        (0x00000002)
#define  MT_rbus_control_mt_rbus_req_mask                                       (0x00000001)
#define  MT_rbus_control_mt_rbus_err(data)                                      (0x00000004&((data)<<2))
#define  MT_rbus_control_mt_rbus_rw(data)                                       (0x00000002&((data)<<1))
#define  MT_rbus_control_mt_rbus_req(data)                                      (0x00000001&(data))
#define  MT_rbus_control_get_mt_rbus_err(data)                                  ((0x00000004&(data))>>2)
#define  MT_rbus_control_get_mt_rbus_rw(data)                                   ((0x00000002&(data))>>1)
#define  MT_rbus_control_get_mt_rbus_req(data)                                  (0x00000001&(data))

#define  MT_rbus_addr                                                           0x180604C4
#define  MT_rbus_addr_reg_addr                                                  "0xB80604C4"
#define  MT_rbus_addr_reg                                                       0xB80604C4
#define  MT_rbus_addr_inst_addr                                                 "0x001E"
#define  MT_rbus_addr_inst                                                      0x001E
#define  MT_rbus_addr_mt_rbus_addr_shift                                        (0)
#define  MT_rbus_addr_mt_rbus_addr_mask                                         (0xFFFFFFFF)
#define  MT_rbus_addr_mt_rbus_addr(data)                                        (0xFFFFFFFF&(data))
#define  MT_rbus_addr_get_mt_rbus_addr(data)                                    (0xFFFFFFFF&(data))

#define  MT_rbus_data                                                           0x180604C8
#define  MT_rbus_data_reg_addr                                                  "0xB80604C8"
#define  MT_rbus_data_reg                                                       0xB80604C8
#define  MT_rbus_data_inst_addr                                                 "0x001F"
#define  MT_rbus_data_inst                                                      0x001F
#define  MT_rbus_data_mt_rbus_data_shift                                        (0)
#define  MT_rbus_data_mt_rbus_data_mask                                         (0xFFFFFFFF)
#define  MT_rbus_data_mt_rbus_data(data)                                        (0xFFFFFFFF&(data))
#define  MT_rbus_data_get_mt_rbus_data(data)                                    (0xFFFFFFFF&(data))

#endif 
