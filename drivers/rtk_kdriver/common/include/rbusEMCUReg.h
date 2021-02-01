/**
* @file rbusEMCUReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/7/29
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_EMCU_REG_H_
#define _RBUS_EMCU_REG_H_

#include "rbusTypes.h"



//  EMCU Register Address



#define  EMCU_WRAPPER_8051_VADDR                            	(0xb8060400)
#define  EMCU_EMCU_DEBUG_8051_VADDR                         	(0xb8060410)
#define  EMCU_MCU_MEM_RME_VADDR                             	(0xb8060414)
#define  EMCU_MCU_MEM_RM_VADDR                              	(0xb8060420)
#define  EMCU_MCU_MEM_LIGHT_SLEEP_VADDR                     	(0xb8060424)
#define  EMCU_EMCU_DEBUG_8051_4_VADDR                       	(0xb8060428)
#define  EMCU_SYSTEM_CPU_PROGRAM_ENABLE_VADDR               	(0xb8060430)
#define  EMCU_IMEM_CONTROL_VADDR                            	(0xb8060434)
#define  EMCU_IMEM_DATA_VADDR                               	(0xb8060438)
#define  EMCU_DMEM_CONTROL_VADDR                            	(0xb806043c)
#define  EMCU_DMEM_DATA_VADDR                               	(0xb8060440)
#define  EMCU_ST_IP_VADDR                                   	(0xb8060450)
#define  EMCU_ST_IE_VADDR                                   	(0xb8060454)
#define  EMCU_MCU_BIST_MODE_VADDR                           	(0xb8060460)
#define  EMCU_MCU_BIST_DONE_VADDR                           	(0xb8060464)
#define  EMCU_MCU_BIST_FAIL_GROUP_VADDR                     	(0xb8060468)
#define  EMCU_MCU_BIST_MCU_DMEM_FAIL_VADDR                  	(0xb806046c)
#define  EMCU_MCU_BIST_MCU_IRAM_FAIL_VADDR                  	(0xb8060474)
#define  EMCU_MCU_BIST_MCU_ALWAYS_ON_FAIL_VADDR             	(0xb8060478)
#define  EMCU_MCU_DRF_MODE_VADDR                            	(0xb806047c)
#define  EMCU_MCU_DRF_RESUME_VADDR                          	(0xb8060480)
#define  EMCU_MCU_DRF_DONE_VADDR                            	(0xb8060484)
#define  EMCU_MCU_DRF_PAUSE_VADDR                           	(0xb8060488)
#define  EMCU_MCU_DRF_FAIL_GROUP_VADDR                      	(0xb806048c)
#define  EMCU_MCU_DRF_MCU_DMEM_FAIL_VADDR                   	(0xb8060490)
#define  EMCU_MCU_DRF_MCU_IRAM_FAIL_VADDR                   	(0xb8060498)
#define  EMCU_MCU_DRF_MCU_ALWAYS_ON_FAIL_VADDR              	(0xb806049c)
#define  EMCU_MCU_BIST_MCU_IMEM_FAIL_VADDR                  	(0xb80604a0)
#define  EMCU_MCU_DRF_MCU_IMEM_FAIL_VADDR                   	(0xb80604a4)
#define  EMCU_MT_RBUS_CONTROL_VADDR                         	(0xb80604c0)
#define  EMCU_MT_RBUS_ADDR_VADDR                            	(0xb80604c4)
#define  EMCU_MT_RBUS_DATA_VADDR                            	(0xb80604c8)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======EMCU register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  emcu_top_dbg_sel:3;
        RBus_UInt32  dmem_dbg_sel:1;
        RBus_UInt32  imem_dbg_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rbus_timeout_cycle:2;
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
        RBus_UInt32  res1:8;
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
        RBus_UInt32  res1:22;
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
        RBus_UInt32  res1:22;
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
        RBus_UInt32  mcu_bist_mode_mcu_imem:1;
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
        RBus_UInt32  mcu_bist_done_mcu_imem:1;
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
        RBus_UInt32  mcu_bist_fail_group_mcu_imem:1;
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
        RBus_UInt32  mcu_drf_mode_mcu_imem:1;
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
        RBus_UInt32  mcu_drf_resume_mcu_imem:1;
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
        RBus_UInt32  mcu_drf_done_mcu_imem:1;
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
        RBus_UInt32  mcu_drf_pause_mcu_imem:1;
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
        RBus_UInt32  mcu_drf_fail_group_mcu_imem:1;
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
        RBus_UInt32  res1:31;
        RBus_UInt32  mcu_bist_mcu_imem_fail_0:1;
    };
}emcu_mcu_bist_mcu_imem_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mcu_drf_mcu_imem_fail_0:1;
    };
}emcu_mcu_drf_mcu_imem_fail_RBUS;

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
        RBus_UInt32  mt_rbus_addr:32;
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
        RBus_UInt32  rbus_timeout_cycle:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  imem_dbg_sel:1;
        RBus_UInt32  dmem_dbg_sel:1;
        RBus_UInt32  emcu_top_dbg_sel:3;
        RBus_UInt32  res2:19;
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
        RBus_UInt32  res1:8;
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
        RBus_UInt32  res1:22;
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
        RBus_UInt32  res1:22;
    };
}emcu_st_ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_bist_mode_mcu_dmem:1;
        RBus_UInt32  mcu_bist_mode_mcu_iram:1;
        RBus_UInt32  mcu_bist_mode_mcu_imem:1;
        RBus_UInt32  mcu_bist_mode_mcu_always_on:1;
        RBus_UInt32  res1:28;
    };
}emcu_mcu_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_bist_done_mcu_dmem:1;
        RBus_UInt32  mcu_bist_done_mcu_iram:1;
        RBus_UInt32  mcu_bist_done_mcu_imem:1;
        RBus_UInt32  mcu_bist_done_mcu_always_on:1;
        RBus_UInt32  res1:28;
    };
}emcu_mcu_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_bist_fail_group_mcu_dmem:1;
        RBus_UInt32  mcu_bist_fail_group_mcu_iram:1;
        RBus_UInt32  mcu_bist_fail_group_mcu_imem:1;
        RBus_UInt32  mcu_bist_fail_group_mcu_always_on:1;
        RBus_UInt32  res1:28;
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
        RBus_UInt32  mcu_drf_mode_mcu_imem:1;
        RBus_UInt32  mcu_drf_mode_mcu_always_on:1;
        RBus_UInt32  res1:28;
    };
}emcu_mcu_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_drf_resume_mcu_dmem:1;
        RBus_UInt32  mcu_drf_resume_mcu_iram:1;
        RBus_UInt32  mcu_drf_resume_mcu_imem:1;
        RBus_UInt32  mcu_drf_resume_mcu_always_on:1;
        RBus_UInt32  res1:28;
    };
}emcu_mcu_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_drf_done_mcu_dmem:1;
        RBus_UInt32  mcu_drf_done_mcu_iram:1;
        RBus_UInt32  mcu_drf_done_mcu_imem:1;
        RBus_UInt32  mcu_drf_done_mcu_always_on:1;
        RBus_UInt32  res1:28;
    };
}emcu_mcu_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_drf_pause_mcu_dmem:1;
        RBus_UInt32  mcu_drf_pause_mcu_iram:1;
        RBus_UInt32  mcu_drf_pause_mcu_imem:1;
        RBus_UInt32  mcu_drf_pause_mcu_always_on:1;
        RBus_UInt32  res1:28;
    };
}emcu_mcu_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_drf_fail_group_mcu_dmem:1;
        RBus_UInt32  mcu_drf_fail_group_mcu_iram:1;
        RBus_UInt32  mcu_drf_fail_group_mcu_imem:1;
        RBus_UInt32  mcu_drf_fail_group_mcu_always_on:1;
        RBus_UInt32  res1:28;
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
        RBus_UInt32  mcu_bist_mcu_imem_fail_0:1;
        RBus_UInt32  res1:31;
    };
}emcu_mcu_bist_mcu_imem_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcu_drf_mcu_imem_fail_0:1;
        RBus_UInt32  res1:31;
    };
}emcu_mcu_drf_mcu_imem_fail_RBUS;

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
        RBus_UInt32  mt_rbus_addr:32;
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
