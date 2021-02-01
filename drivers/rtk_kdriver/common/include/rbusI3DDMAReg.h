/**
* @file rbusI3DDMAReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/8/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_I3DDMA_REG_H_
#define _RBUS_I3DDMA_REG_H_

#include "rbusTypes.h"



//  I3DDMA Register Address



#define  I3DDMA_LR_SEPARATE_CTRL1_VADDR                     	(0xb8025800)
#define  I3DDMA_LR_SEPARATE_CTRL2_VADDR                     	(0xb8025804)
#define  I3DDMA_LR_SEPARATE_INSERT_VS_START_VADDR           	(0xb8025808)
#define  I3DDMA_LR_SEPARATE_INSERT_VS_END_VADDR             	(0xb802580c)
#define  I3DDMA_CAP_CTL0_VADDR                              	(0xb8025810)
#define  I3DDMA_CAP_CTL1_VADDR                              	(0xb8025814)
#define  I3DDMA_CAP_BOUNDARYADDR1_VADDR                     	(0xb8025818)
#define  I3DDMA_CAP_BOUNDARYADDR2_VADDR                     	(0xb802581c)
#define  I3DDMA_CAP_L1_START_VADDR                          	(0xb8025820)
#define  I3DDMA_CAP_L2_START_VADDR                          	(0xb8025824)
#define  I3DDMA_CAP_R1_START_VADDR                          	(0xb8025828)
#define  I3DDMA_CAP_R2_START_VADDR                          	(0xb802582c)
#define  I3DDMA_CAP_L1_START_DB_VADDR                       	(0xb8025830)
#define  I3DDMA_CAP_R1_START_DB_VADDR                       	(0xb8025834)
#define  I3DDMA_CAP_STATUS_VADDR                            	(0xb8025838)
#define  I3DDMA_TG_V1_END_VADDR                             	(0xb802583c)
#define  I3DDMA_TG_V2_START_VADDR                           	(0xb8025840)
#define  I3DDMA_TG_V2_END_VADDR                             	(0xb8025844)
#define  I3DDMA_TG_V3_START_VADDR                           	(0xb8025848)
#define  I3DDMA_TG_V3_END_VADDR                             	(0xb802584c)
#define  I3DDMA_TG_V4_START_VADDR                           	(0xb8025850)
#define  I3DDMA_TG_V4_END_VADDR                             	(0xb8025854)
#define  I3DDMA_CTS_FIFO_CTRL_VADDR                         	(0xb802585c)
#define  I3DDMA_LR_CRC_CTRL_VADDR                           	(0xb8025860)
#define  I3DDMA_CRC_L_RESULT_VADDR                          	(0xb8025864)
#define  I3DDMA_CRC_R_RESULT_VADDR                          	(0xb8025868)
#define  I3DDMA_INTERRUPT_ENABLE_VADDR                      	(0xb802586c)
#define  I3DDMA_I3DDMA_ENABLE_VADDR                         	(0xb8025870)
#define  I3DDMA_I3DDMA_BYTE_CHANNEL_SWAP_VADDR              	(0xb8025874)
#define  I3DDMA_CAP_L1_START_DB_2_VADDR                     	(0xb8025878)
#define  I3DDMA_CAP_R1_START_DB_2_VADDR                     	(0xb802587c)
#define  I3DDMA_CAP_STATUS_2_VADDR                          	(0xb8025880)
#define  I3DDMA_CAP_L3_START_VADDR                          	(0xb8025884)
#define  I3DDMA_CAP_R3_START_VADDR                          	(0xb8025888)
#define  I3DDMA_CAP_L4_START_VADDR                          	(0xb802588c)
#define  I3DDMA_CAP_R4_START_VADDR                          	(0xb8025890)
#define  I3DDMA_I3DDMA_BIST_CAP_FAIL_VADDR                  	(0xb80258d8)
#define  I3DDMA_I3DDMA_DRF_CAP_FAIL_VADDR                   	(0xb80258ec)
#define  I3DDMA_I3DDMA_DVS_VADDR                            	(0xb80258f0)
#define  I3DDMA_I3DDMA_DVSE_VADDR                           	(0xb80258f4)
#define  I3DDMA_I3DDMA_LS_VADDR                             	(0xb80258f8)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======I3DDMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_lr_ctrl1:5;
        RBus_UInt32  hdmi420_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  hdmi_3d_sel:1;
        RBus_UInt32  vs_inv:1;
        RBus_UInt32  hs_inv:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  progressive:1;
        RBus_UInt32  hdmi_3d_structure:4;
        RBus_UInt32  fp_vact_space1:8;
        RBus_UInt32  fp_vact_space2:8;
    };
}i3ddma_lr_separate_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact:16;
        RBus_UInt32  res1:1;
        RBus_UInt32  hact:15;
    };
}i3ddma_lr_separate_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  hstart:13;
        RBus_UInt32  vstart:8;
    };
}i3ddma_lr_separate_insert_vs_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  hend:13;
        RBus_UInt32  vend:8;
    };
}i3ddma_lr_separate_insert_vs_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  triple_buf_en:1;
        RBus_UInt32  cap_block_fw:2;
        RBus_UInt32  set_block_sel:1;
        RBus_UInt32  quad_buf_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  freeze_en:1;
        RBus_UInt32  vs_fall_rst_en:1;
        RBus_UInt32  auto_block_sel_en:1;
        RBus_UInt32  half_wr_en:1;
        RBus_UInt32  half_wr_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  bit_sel:1;
        RBus_UInt32  pixel_encoding:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  cap_write_len:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cap_write_rem:6;
    };
}i3ddma_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_cap_ctl1:17;
        RBus_UInt32  cap_water_lv:7;
        RBus_UInt32  cap_write_num:8;
    };
}i3ddma_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_mem_up_limit:29;
        RBus_UInt32  res1:3;
    };
}i3ddma_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_mem_low_limit:29;
        RBus_UInt32  res1:3;
    };
}i3ddma_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l1_start:29;
        RBus_UInt32  res1:3;
    };
}i3ddma_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l2_start:29;
        RBus_UInt32  res1:3;
    };
}i3ddma_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r1_start:29;
        RBus_UInt32  res1:3;
    };
}i3ddma_cap_r1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r2_start:29;
        RBus_UInt32  res1:3;
    };
}i3ddma_cap_r2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l1_start_db:29;
        RBus_UInt32  res1:3;
    };
}i3ddma_cap_l1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r1_start_db:29;
        RBus_UInt32  res1:3;
    };
}i3ddma_cap_r1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_cap_st:18;
        RBus_UInt32  cap_block_2:2;
        RBus_UInt32  cap_over_size:1;
        RBus_UInt32  cap_under_size:1;
        RBus_UInt32  freeze_ok:1;
        RBus_UInt32  vs_rising_occur:1;
        RBus_UInt32  tg_l_flag:1;
        RBus_UInt32  cap_block:1;
        RBus_UInt32  cap_field:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_ddr_over_range:1;
    };
}i3ddma_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pullup_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  tg_hend1:13;
        RBus_UInt32  tg_vend1:8;
    };
}i3ddma_tg_v1_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hstart2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tg_vstart2:13;
    };
}i3ddma_tg_v2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hend2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tg_vend2:13;
    };
}i3ddma_tg_v2_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hstart3:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tg_vstart3:13;
    };
}i3ddma_tg_v3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hend3:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tg_vend3:13;
    };
}i3ddma_tg_v3_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hstart4:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tg_vstart4:13;
    };
}i3ddma_tg_v4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hend4:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tg_vend4:13;
    };
}i3ddma_tg_v4_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_cts_fifo:24;
        RBus_UInt32  res1:5;
        RBus_UInt32  force_ctsfifo_rstn:1;
        RBus_UInt32  en_ctsfifo_vsrst:1;
        RBus_UInt32  en_ctsfifo_bypass:1;
    };
}i3ddma_cts_fifo_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  r_crc_conti:1;
        RBus_UInt32  r_crc_start:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  l_crc_conti:1;
        RBus_UInt32  l_crc_start:1;
    };
}i3ddma_lr_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}i3ddma_crc_l_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}i3ddma_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  mem_err_ie:1;
        RBus_UInt32  fifo_err_ie:1;
        RBus_UInt32  vs_rising_ie:1;
    };
}i3ddma_interrupt_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  frc_style:1;
        RBus_UInt32  frc_en:1;
        RBus_UInt32  tg_en:1;
        RBus_UInt32  lr_separate_en:1;
        RBus_UInt32  cap_en:1;
    };
}i3ddma_i3ddma_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dma_channel_swap:3;
        RBus_UInt32  dma_8byte_swap:1;
        RBus_UInt32  dma_4byte_swap:1;
        RBus_UInt32  dma_2byte_swap:1;
        RBus_UInt32  dma_1byte_swap:1;
    };
}i3ddma_i3ddma_byte_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  res2:3;
    };
}i3ddma_cap_l1_start_db_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  res2:3;
    };
}i3ddma_cap_r1_start_db_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
    };
}i3ddma_cap_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l3_start:29;
        RBus_UInt32  res1:3;
    };
}i3ddma_cap_l3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r3_start:29;
        RBus_UInt32  res1:3;
    };
}i3ddma_cap_r3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l4_start:29;
        RBus_UInt32  res1:3;
    };
}i3ddma_cap_l4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r4_start:29;
        RBus_UInt32  res1:3;
    };
}i3ddma_cap_r4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  res2:1;
        RBus_UInt32  i3ddma_bist_cap_fail:1;
    };
}i3ddma_i3ddma_bist_cap_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  res2:1;
        RBus_UInt32  i3ddma_drf_cap_fail:1;
    };
}i3ddma_i3ddma_drf_cap_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:4;
        RBus_UInt32  cap_dvsb:4;
        RBus_UInt32  cap_dvsa:4;
    };
}i3ddma_i3ddma_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  cap_dvseb:1;
        RBus_UInt32  cap_dvsea:1;
    };
}i3ddma_i3ddma_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  res2:1;
        RBus_UInt32  cap_ls:1;
    };
}i3ddma_i3ddma_ls_RBUS;

#else //apply LITTLE_ENDIAN

//======I3DDMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fp_vact_space2:8;
        RBus_UInt32  fp_vact_space1:8;
        RBus_UInt32  hdmi_3d_structure:4;
        RBus_UInt32  progressive:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  hs_inv:1;
        RBus_UInt32  vs_inv:1;
        RBus_UInt32  hdmi_3d_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hdmi420_en:1;
        RBus_UInt32  dummy_lr_ctrl1:5;
    };
}i3ddma_lr_separate_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hact:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  vact:16;
    };
}i3ddma_lr_separate_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstart:8;
        RBus_UInt32  hstart:13;
        RBus_UInt32  res1:11;
    };
}i3ddma_lr_separate_insert_vs_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vend:8;
        RBus_UInt32  hend:13;
        RBus_UInt32  res1:11;
    };
}i3ddma_lr_separate_insert_vs_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_rem:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cap_write_len:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pixel_encoding:2;
        RBus_UInt32  bit_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  half_wr_sel:1;
        RBus_UInt32  half_wr_en:1;
        RBus_UInt32  auto_block_sel_en:1;
        RBus_UInt32  vs_fall_rst_en:1;
        RBus_UInt32  freeze_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  quad_buf_en:1;
        RBus_UInt32  set_block_sel:1;
        RBus_UInt32  cap_block_fw:2;
        RBus_UInt32  triple_buf_en:1;
    };
}i3ddma_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_num:8;
        RBus_UInt32  cap_water_lv:7;
        RBus_UInt32  dummy_cap_ctl1:17;
    };
}i3ddma_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_mem_up_limit:29;
    };
}i3ddma_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_mem_low_limit:29;
    };
}i3ddma_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l1_start:29;
    };
}i3ddma_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l2_start:29;
    };
}i3ddma_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_r1_start:29;
    };
}i3ddma_cap_r1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_r2_start:29;
    };
}i3ddma_cap_r2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l1_start_db:29;
    };
}i3ddma_cap_l1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_r1_start_db:29;
    };
}i3ddma_cap_r1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_ddr_over_range:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  cap_field:1;
        RBus_UInt32  cap_block:1;
        RBus_UInt32  tg_l_flag:1;
        RBus_UInt32  vs_rising_occur:1;
        RBus_UInt32  freeze_ok:1;
        RBus_UInt32  cap_under_size:1;
        RBus_UInt32  cap_over_size:1;
        RBus_UInt32  cap_block_2:2;
        RBus_UInt32  dummy_cap_st:18;
    };
}i3ddma_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vend1:8;
        RBus_UInt32  tg_hend1:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pullup_en:1;
        RBus_UInt32  res3:6;
    };
}i3ddma_tg_v1_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vstart2:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hstart2:13;
        RBus_UInt32  res2:3;
    };
}i3ddma_tg_v2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vend2:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hend2:13;
        RBus_UInt32  res2:3;
    };
}i3ddma_tg_v2_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vstart3:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hstart3:13;
        RBus_UInt32  res2:3;
    };
}i3ddma_tg_v3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vend3:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hend3:13;
        RBus_UInt32  res2:3;
    };
}i3ddma_tg_v3_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vstart4:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hstart4:13;
        RBus_UInt32  res2:3;
    };
}i3ddma_tg_v4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vend4:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hend4:13;
        RBus_UInt32  res2:3;
    };
}i3ddma_tg_v4_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_ctsfifo_bypass:1;
        RBus_UInt32  en_ctsfifo_vsrst:1;
        RBus_UInt32  force_ctsfifo_rstn:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  dummy_cts_fifo:24;
    };
}i3ddma_cts_fifo_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_start:1;
        RBus_UInt32  l_crc_conti:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  r_crc_start:1;
        RBus_UInt32  r_crc_conti:1;
        RBus_UInt32  res2:22;
    };
}i3ddma_lr_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}i3ddma_crc_l_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}i3ddma_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vs_rising_ie:1;
        RBus_UInt32  fifo_err_ie:1;
        RBus_UInt32  mem_err_ie:1;
        RBus_UInt32  res1:29;
    };
}i3ddma_interrupt_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_en:1;
        RBus_UInt32  lr_separate_en:1;
        RBus_UInt32  tg_en:1;
        RBus_UInt32  frc_en:1;
        RBus_UInt32  frc_style:1;
        RBus_UInt32  res1:27;
    };
}i3ddma_i3ddma_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_1byte_swap:1;
        RBus_UInt32  dma_2byte_swap:1;
        RBus_UInt32  dma_4byte_swap:1;
        RBus_UInt32  dma_8byte_swap:1;
        RBus_UInt32  dma_channel_swap:3;
        RBus_UInt32  res1:25;
    };
}i3ddma_i3ddma_byte_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  res2:29;
    };
}i3ddma_cap_l1_start_db_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  res2:29;
    };
}i3ddma_cap_r1_start_db_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:25;
    };
}i3ddma_cap_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l3_start:29;
    };
}i3ddma_cap_l3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_r3_start:29;
    };
}i3ddma_cap_r3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l4_start:29;
    };
}i3ddma_cap_l4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_r4_start:29;
    };
}i3ddma_cap_r4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_bist_cap_fail:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:30;
    };
}i3ddma_i3ddma_bist_cap_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_drf_cap_fail:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:30;
    };
}i3ddma_i3ddma_drf_cap_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_dvsa:4;
        RBus_UInt32  cap_dvsb:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:16;
    };
}i3ddma_i3ddma_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_dvsea:1;
        RBus_UInt32  cap_dvseb:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:28;
    };
}i3ddma_i3ddma_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_ls:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:30;
    };
}i3ddma_i3ddma_ls_RBUS;




#endif

#define I3DDMA_LR_SEPARATE_CTRL1                                             0x18025800
#define I3DDMA_LR_SEPARATE_CTRL1_reg_addr                                    "0xb8025800"
#define I3DDMA_LR_SEPARATE_CTRL1_reg                                         0xb8025800
#define I3DDMA_LR_SEPARATE_CTRL1_inst_addr                                   "0x0200"
#define I3DDMA_LR_SEPARATE_CTRL1_inst                                        0x0200
#define I3DDMA_LR_SEPARATE_CTRL1_dummy_lr_ctrl1_shift                        (26)
#define I3DDMA_LR_SEPARATE_CTRL1_chess_board_format_shift                    (25)
#define I3DDMA_LR_SEPARATE_CTRL1_hdmi_3d_sel_shift                           (24)
#define I3DDMA_LR_SEPARATE_CTRL1_vs_inv_shift                                (23)
#define I3DDMA_LR_SEPARATE_CTRL1_hs_inv_shift                                (22)
#define I3DDMA_LR_SEPARATE_CTRL1_progressive_shift                           (20)
#define I3DDMA_LR_SEPARATE_CTRL1_hdmi_3d_structure_shift                     (16)
#define I3DDMA_LR_SEPARATE_CTRL1_fp_vact_space1_shift                        (8)
#define I3DDMA_LR_SEPARATE_CTRL1_fp_vact_space2_shift                        (0)
#define I3DDMA_LR_SEPARATE_CTRL1_dummy_lr_ctrl1_mask                         (0xFC000000)
#define I3DDMA_LR_SEPARATE_CTRL1_chess_board_format_mask                     (0x02000000)
#define I3DDMA_LR_SEPARATE_CTRL1_hdmi_3d_sel_mask                            (0x01000000)
#define I3DDMA_LR_SEPARATE_CTRL1_vs_inv_mask                                 (0x00800000)
#define I3DDMA_LR_SEPARATE_CTRL1_hs_inv_mask                                 (0x00400000)
#define I3DDMA_LR_SEPARATE_CTRL1_progressive_mask                            (0x00100000)
#define I3DDMA_LR_SEPARATE_CTRL1_hdmi_3d_structure_mask                      (0x000F0000)
#define I3DDMA_LR_SEPARATE_CTRL1_fp_vact_space1_mask                         (0x0000FF00)
#define I3DDMA_LR_SEPARATE_CTRL1_fp_vact_space2_mask                         (0x000000FF)
#define I3DDMA_LR_SEPARATE_CTRL1_dummy_lr_ctrl1(data)                        (0xFC000000&((data)<<26))
#define I3DDMA_LR_SEPARATE_CTRL1_chess_board_format(data)                    (0x02000000&((data)<<25))
#define I3DDMA_LR_SEPARATE_CTRL1_hdmi_3d_sel(data)                           (0x01000000&((data)<<24))
#define I3DDMA_LR_SEPARATE_CTRL1_vs_inv(data)                                (0x00800000&((data)<<23))
#define I3DDMA_LR_SEPARATE_CTRL1_hs_inv(data)                                (0x00400000&((data)<<22))
#define I3DDMA_LR_SEPARATE_CTRL1_progressive(data)                           (0x00100000&((data)<<20))
#define I3DDMA_LR_SEPARATE_CTRL1_hdmi_3d_structure(data)                     (0x000F0000&((data)<<16))
#define I3DDMA_LR_SEPARATE_CTRL1_fp_vact_space1(data)                        (0x0000FF00&((data)<<8))
#define I3DDMA_LR_SEPARATE_CTRL1_fp_vact_space2(data)                        (0x000000FF&(data))
#define I3DDMA_LR_SEPARATE_CTRL1_get_dummy_lr_ctrl1(data)                    ((0xFC000000&(data))>>26)
#define I3DDMA_LR_SEPARATE_CTRL1_get_chess_board_format(data)                ((0x02000000&(data))>>25)
#define I3DDMA_LR_SEPARATE_CTRL1_get_hdmi_3d_sel(data)                       ((0x01000000&(data))>>24)
#define I3DDMA_LR_SEPARATE_CTRL1_get_vs_inv(data)                            ((0x00800000&(data))>>23)
#define I3DDMA_LR_SEPARATE_CTRL1_get_hs_inv(data)                            ((0x00400000&(data))>>22)
#define I3DDMA_LR_SEPARATE_CTRL1_get_progressive(data)                       ((0x00100000&(data))>>20)
#define I3DDMA_LR_SEPARATE_CTRL1_get_hdmi_3d_structure(data)                 ((0x000F0000&(data))>>16)
#define I3DDMA_LR_SEPARATE_CTRL1_get_fp_vact_space1(data)                    ((0x0000FF00&(data))>>8)
#define I3DDMA_LR_SEPARATE_CTRL1_get_fp_vact_space2(data)                    (0x000000FF&(data))


#define I3DDMA_LR_SEPARATE_CTRL2                                             0x18025804
#define I3DDMA_LR_SEPARATE_CTRL2_reg_addr                                    "0xb8025804"
#define I3DDMA_LR_SEPARATE_CTRL2_reg                                         0xb8025804
#define I3DDMA_LR_SEPARATE_CTRL2_inst_addr                                   "0x0201"
#define I3DDMA_LR_SEPARATE_CTRL2_inst                                        0x0201
#define I3DDMA_LR_SEPARATE_CTRL2_vact_shift                                  (16)
#define I3DDMA_LR_SEPARATE_CTRL2_hact_shift                                  (0)
#define I3DDMA_LR_SEPARATE_CTRL2_vact_mask                                   (0xFFFF0000)
#define I3DDMA_LR_SEPARATE_CTRL2_hact_mask                                   (0x00007FFF)
#define I3DDMA_LR_SEPARATE_CTRL2_vact(data)                                  (0xFFFF0000&((data)<<16))
#define I3DDMA_LR_SEPARATE_CTRL2_hact(data)                                  (0x00007FFF&(data))
#define I3DDMA_LR_SEPARATE_CTRL2_get_vact(data)                              ((0xFFFF0000&(data))>>16)
#define I3DDMA_LR_SEPARATE_CTRL2_get_hact(data)                              (0x00007FFF&(data))


#define I3DDMA_LR_SEPARATE_INSERT_VS_START                                   0x18025808
#define I3DDMA_LR_SEPARATE_INSERT_VS_START_reg_addr                          "0xb8025808"
#define I3DDMA_LR_SEPARATE_INSERT_VS_START_reg                               0xb8025808
#define I3DDMA_LR_SEPARATE_INSERT_VS_START_inst_addr                         "0x0202"
#define I3DDMA_LR_SEPARATE_INSERT_VS_START_inst                              0x0202
#define I3DDMA_LR_SEPARATE_INSERT_VS_START_hstart_shift                      (8)
#define I3DDMA_LR_SEPARATE_INSERT_VS_START_vstart_shift                      (0)
#define I3DDMA_LR_SEPARATE_INSERT_VS_START_hstart_mask                       (0x001FFF00)
#define I3DDMA_LR_SEPARATE_INSERT_VS_START_vstart_mask                       (0x000000FF)
#define I3DDMA_LR_SEPARATE_INSERT_VS_START_hstart(data)                      (0x001FFF00&((data)<<8))
#define I3DDMA_LR_SEPARATE_INSERT_VS_START_vstart(data)                      (0x000000FF&(data))
#define I3DDMA_LR_SEPARATE_INSERT_VS_START_get_hstart(data)                  ((0x001FFF00&(data))>>8)
#define I3DDMA_LR_SEPARATE_INSERT_VS_START_get_vstart(data)                  (0x000000FF&(data))


#define I3DDMA_LR_SEPARATE_INSERT_VS_END                                     0x1802580c
#define I3DDMA_LR_SEPARATE_INSERT_VS_END_reg_addr                            "0xb802580c"
#define I3DDMA_LR_SEPARATE_INSERT_VS_END_reg                                 0xb802580c
#define I3DDMA_LR_SEPARATE_INSERT_VS_END_inst_addr                           "0x0203"
#define I3DDMA_LR_SEPARATE_INSERT_VS_END_inst                                0x0203
#define I3DDMA_LR_SEPARATE_INSERT_VS_END_hend_shift                          (8)
#define I3DDMA_LR_SEPARATE_INSERT_VS_END_vend_shift                          (0)
#define I3DDMA_LR_SEPARATE_INSERT_VS_END_hend_mask                           (0x001FFF00)
#define I3DDMA_LR_SEPARATE_INSERT_VS_END_vend_mask                           (0x000000FF)
#define I3DDMA_LR_SEPARATE_INSERT_VS_END_hend(data)                          (0x001FFF00&((data)<<8))
#define I3DDMA_LR_SEPARATE_INSERT_VS_END_vend(data)                          (0x000000FF&(data))
#define I3DDMA_LR_SEPARATE_INSERT_VS_END_get_hend(data)                      ((0x001FFF00&(data))>>8)
#define I3DDMA_LR_SEPARATE_INSERT_VS_END_get_vend(data)                      (0x000000FF&(data))


#define I3DDMA_CAP_CTL0                                                      0x18025810
#define I3DDMA_CAP_CTL0_reg_addr                                             "0xb8025810"
#define I3DDMA_CAP_CTL0_reg                                                  0xb8025810
#define I3DDMA_CAP_CTL0_inst_addr                                            "0x0204"
#define I3DDMA_CAP_CTL0_inst                                                 0x0204
#define I3DDMA_CAP_CTL0_triple_buf_en_shift                                  (31)
#define I3DDMA_CAP_CTL0_cap_block_fw_shift                                   (29)
#define I3DDMA_CAP_CTL0_set_block_sel_shift                                  (28)
#define I3DDMA_CAP_CTL0_quad_buf_en_shift                                    (27)
#define I3DDMA_CAP_CTL0_freeze_en_shift                                      (24)
#define I3DDMA_CAP_CTL0_vs_fall_rst_en_shift                                 (23)
#define I3DDMA_CAP_CTL0_auto_block_sel_en_shift                              (22)
#define I3DDMA_CAP_CTL0_half_wr_en_shift                                     (21)
#define I3DDMA_CAP_CTL0_half_wr_sel_shift                                    (20)
#define I3DDMA_CAP_CTL0_bit_sel_shift                                        (18)
#define I3DDMA_CAP_CTL0_pixel_encoding_shift                                 (16)
#define I3DDMA_CAP_CTL0_cap_write_len_shift                                  (8)
#define I3DDMA_CAP_CTL0_cap_write_rem_shift                                  (0)
#define I3DDMA_CAP_CTL0_triple_buf_en_mask                                   (0x80000000)
#define I3DDMA_CAP_CTL0_cap_block_fw_mask                                    (0x60000000)
#define I3DDMA_CAP_CTL0_set_block_sel_mask                                   (0x10000000)
#define I3DDMA_CAP_CTL0_quad_buf_en_mask                                     (0x08000000)
#define I3DDMA_CAP_CTL0_freeze_en_mask                                       (0x01000000)
#define I3DDMA_CAP_CTL0_vs_fall_rst_en_mask                                  (0x00800000)
#define I3DDMA_CAP_CTL0_auto_block_sel_en_mask                               (0x00400000)
#define I3DDMA_CAP_CTL0_half_wr_en_mask                                      (0x00200000)
#define I3DDMA_CAP_CTL0_half_wr_sel_mask                                     (0x00100000)
#define I3DDMA_CAP_CTL0_bit_sel_mask                                         (0x00040000)
#define I3DDMA_CAP_CTL0_pixel_encoding_mask                                  (0x00030000)
#define I3DDMA_CAP_CTL0_cap_write_len_mask                                   (0x00003F00)
#define I3DDMA_CAP_CTL0_cap_write_rem_mask                                   (0x0000003F)
#define I3DDMA_CAP_CTL0_triple_buf_en(data)                                  (0x80000000&((data)<<31))
#define I3DDMA_CAP_CTL0_cap_block_fw(data)                                   (0x60000000&((data)<<29))
#define I3DDMA_CAP_CTL0_set_block_sel(data)                                  (0x10000000&((data)<<28))
#define I3DDMA_CAP_CTL0_quad_buf_en(data)                                    (0x08000000&((data)<<27))
#define I3DDMA_CAP_CTL0_freeze_en(data)                                      (0x01000000&((data)<<24))
#define I3DDMA_CAP_CTL0_vs_fall_rst_en(data)                                 (0x00800000&((data)<<23))
#define I3DDMA_CAP_CTL0_auto_block_sel_en(data)                              (0x00400000&((data)<<22))
#define I3DDMA_CAP_CTL0_half_wr_en(data)                                     (0x00200000&((data)<<21))
#define I3DDMA_CAP_CTL0_half_wr_sel(data)                                    (0x00100000&((data)<<20))
#define I3DDMA_CAP_CTL0_bit_sel(data)                                        (0x00040000&((data)<<18))
#define I3DDMA_CAP_CTL0_pixel_encoding(data)                                 (0x00030000&((data)<<16))
#define I3DDMA_CAP_CTL0_cap_write_len(data)                                  (0x00003F00&((data)<<8))
#define I3DDMA_CAP_CTL0_cap_write_rem(data)                                  (0x0000003F&(data))
#define I3DDMA_CAP_CTL0_get_triple_buf_en(data)                              ((0x80000000&(data))>>31)
#define I3DDMA_CAP_CTL0_get_cap_block_fw(data)                               ((0x60000000&(data))>>29)
#define I3DDMA_CAP_CTL0_get_set_block_sel(data)                              ((0x10000000&(data))>>28)
#define I3DDMA_CAP_CTL0_get_quad_buf_en(data)                                ((0x08000000&(data))>>27)
#define I3DDMA_CAP_CTL0_get_freeze_en(data)                                  ((0x01000000&(data))>>24)
#define I3DDMA_CAP_CTL0_get_vs_fall_rst_en(data)                             ((0x00800000&(data))>>23)
#define I3DDMA_CAP_CTL0_get_auto_block_sel_en(data)                          ((0x00400000&(data))>>22)
#define I3DDMA_CAP_CTL0_get_half_wr_en(data)                                 ((0x00200000&(data))>>21)
#define I3DDMA_CAP_CTL0_get_half_wr_sel(data)                                ((0x00100000&(data))>>20)
#define I3DDMA_CAP_CTL0_get_bit_sel(data)                                    ((0x00040000&(data))>>18)
#define I3DDMA_CAP_CTL0_get_pixel_encoding(data)                             ((0x00030000&(data))>>16)
#define I3DDMA_CAP_CTL0_get_cap_write_len(data)                              ((0x00003F00&(data))>>8)
#define I3DDMA_CAP_CTL0_get_cap_write_rem(data)                              (0x0000003F&(data))


#define I3DDMA_CAP_CTL1                                                      0x18025814
#define I3DDMA_CAP_CTL1_reg_addr                                             "0xb8025814"
#define I3DDMA_CAP_CTL1_reg                                                  0xb8025814
#define I3DDMA_CAP_CTL1_inst_addr                                            "0x0205"
#define I3DDMA_CAP_CTL1_inst                                                 0x0205
#define I3DDMA_CAP_CTL1_dummy_cap_ctl1_shift                                 (15)
#define I3DDMA_CAP_CTL1_cap_water_lv_shift                                   (8)
#define I3DDMA_CAP_CTL1_cap_write_num_shift                                  (0)
#define I3DDMA_CAP_CTL1_dummy_cap_ctl1_mask                                  (0xFFFF8000)
#define I3DDMA_CAP_CTL1_cap_water_lv_mask                                    (0x00007F00)
#define I3DDMA_CAP_CTL1_cap_write_num_mask                                   (0x000000FF)
#define I3DDMA_CAP_CTL1_dummy_cap_ctl1(data)                                 (0xFFFF8000&((data)<<15))
#define I3DDMA_CAP_CTL1_cap_water_lv(data)                                   (0x00007F00&((data)<<8))
#define I3DDMA_CAP_CTL1_cap_write_num(data)                                  (0x000000FF&(data))
#define I3DDMA_CAP_CTL1_get_dummy_cap_ctl1(data)                             ((0xFFFF8000&(data))>>15)
#define I3DDMA_CAP_CTL1_get_cap_water_lv(data)                               ((0x00007F00&(data))>>8)
#define I3DDMA_CAP_CTL1_get_cap_write_num(data)                              (0x000000FF&(data))


#define I3DDMA_CAP_BOUNDARYADDR1                                             0x18025818
#define I3DDMA_CAP_BOUNDARYADDR1_reg_addr                                    "0xb8025818"
#define I3DDMA_CAP_BOUNDARYADDR1_reg                                         0xb8025818
#define I3DDMA_CAP_BOUNDARYADDR1_inst_addr                                   "0x0206"
#define I3DDMA_CAP_BOUNDARYADDR1_inst                                        0x0206
#define I3DDMA_CAP_BOUNDARYADDR1_cap_mem_up_limit_shift                      (3)
#define I3DDMA_CAP_BOUNDARYADDR1_cap_mem_up_limit_mask                       (0x7FFFFFF8)
#define I3DDMA_CAP_BOUNDARYADDR1_cap_mem_up_limit(data)                      (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_BOUNDARYADDR1_get_cap_mem_up_limit(data)                  ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_CAP_BOUNDARYADDR2                                             0x1802581c
#define I3DDMA_CAP_BOUNDARYADDR2_reg_addr                                    "0xb802581c"
#define I3DDMA_CAP_BOUNDARYADDR2_reg                                         0xb802581c
#define I3DDMA_CAP_BOUNDARYADDR2_inst_addr                                   "0x0207"
#define I3DDMA_CAP_BOUNDARYADDR2_inst                                        0x0207
#define I3DDMA_CAP_BOUNDARYADDR2_cap_mem_low_limit_shift                     (3)
#define I3DDMA_CAP_BOUNDARYADDR2_cap_mem_low_limit_mask                      (0x7FFFFFF8)
#define I3DDMA_CAP_BOUNDARYADDR2_cap_mem_low_limit(data)                     (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_BOUNDARYADDR2_get_cap_mem_low_limit(data)                 ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_CAP_L1_START                                                  0x18025820
#define I3DDMA_CAP_L1_START_reg_addr                                         "0xb8025820"
#define I3DDMA_CAP_L1_START_reg                                              0xb8025820
#define I3DDMA_CAP_L1_START_inst_addr                                        "0x0208"
#define I3DDMA_CAP_L1_START_inst                                             0x0208
#define I3DDMA_CAP_L1_START_cap_l1_start_shift                               (3)
#define I3DDMA_CAP_L1_START_cap_l1_start_mask                                (0x7FFFFFF8)
#define I3DDMA_CAP_L1_START_cap_l1_start(data)                               (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_L1_START_get_cap_l1_start(data)                           ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_CAP_L2_START                                                  0x18025824
#define I3DDMA_CAP_L2_START_reg_addr                                         "0xb8025824"
#define I3DDMA_CAP_L2_START_reg                                              0xb8025824
#define I3DDMA_CAP_L2_START_inst_addr                                        "0x0209"
#define I3DDMA_CAP_L2_START_inst                                             0x0209
#define I3DDMA_CAP_L2_START_cap_l2_start_shift                               (3)
#define I3DDMA_CAP_L2_START_cap_l2_start_mask                                (0x7FFFFFF8)
#define I3DDMA_CAP_L2_START_cap_l2_start(data)                               (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_L2_START_get_cap_l2_start(data)                           ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_CAP_R1_START                                                  0x18025828
#define I3DDMA_CAP_R1_START_reg_addr                                         "0xb8025828"
#define I3DDMA_CAP_R1_START_reg                                              0xb8025828
#define I3DDMA_CAP_R1_START_inst_addr                                        "0x020A"
#define I3DDMA_CAP_R1_START_inst                                             0x020A
#define I3DDMA_CAP_R1_START_cap_r1_start_shift                               (3)
#define I3DDMA_CAP_R1_START_cap_r1_start_mask                                (0x7FFFFFF8)
#define I3DDMA_CAP_R1_START_cap_r1_start(data)                               (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_R1_START_get_cap_r1_start(data)                           ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_CAP_R2_START                                                  0x1802582c
#define I3DDMA_CAP_R2_START_reg_addr                                         "0xb802582c"
#define I3DDMA_CAP_R2_START_reg                                              0xb802582c
#define I3DDMA_CAP_R2_START_inst_addr                                        "0x020B"
#define I3DDMA_CAP_R2_START_inst                                             0x020B
#define I3DDMA_CAP_R2_START_cap_r2_start_shift                               (3)
#define I3DDMA_CAP_R2_START_cap_r2_start_mask                                (0x7FFFFFF8)
#define I3DDMA_CAP_R2_START_cap_r2_start(data)                               (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_R2_START_get_cap_r2_start(data)                           ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_CAP_L1_START_DB                                               0x18025830
#define I3DDMA_CAP_L1_START_DB_reg_addr                                      "0xb8025830"
#define I3DDMA_CAP_L1_START_DB_reg                                           0xb8025830
#define I3DDMA_CAP_L1_START_DB_inst_addr                                     "0x020C"
#define I3DDMA_CAP_L1_START_DB_inst                                          0x020C
#define I3DDMA_CAP_L1_START_DB_cap_l1_start_db_shift                         (3)
#define I3DDMA_CAP_L1_START_DB_cap_l1_start_db_mask                          (0x7FFFFFF8)
#define I3DDMA_CAP_L1_START_DB_cap_l1_start_db(data)                         (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_L1_START_DB_get_cap_l1_start_db(data)                     ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_CAP_R1_START_DB                                               0x18025834
#define I3DDMA_CAP_R1_START_DB_reg_addr                                      "0xb8025834"
#define I3DDMA_CAP_R1_START_DB_reg                                           0xb8025834
#define I3DDMA_CAP_R1_START_DB_inst_addr                                     "0x020D"
#define I3DDMA_CAP_R1_START_DB_inst                                          0x020D
#define I3DDMA_CAP_R1_START_DB_cap_r1_start_db_shift                         (3)
#define I3DDMA_CAP_R1_START_DB_cap_r1_start_db_mask                          (0x7FFFFFF8)
#define I3DDMA_CAP_R1_START_DB_cap_r1_start_db(data)                         (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_R1_START_DB_get_cap_r1_start_db(data)                     ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_CAP_STATUS                                                    0x18025838
#define I3DDMA_CAP_STATUS_reg_addr                                           "0xb8025838"
#define I3DDMA_CAP_STATUS_reg                                                0xb8025838
#define I3DDMA_CAP_STATUS_inst_addr                                          "0x020E"
#define I3DDMA_CAP_STATUS_inst                                               0x020E
#define I3DDMA_CAP_STATUS_dummy_cap_st_shift                                 (12)
#define I3DDMA_CAP_STATUS_cap_over_size_shift                                (11)
#define I3DDMA_CAP_STATUS_cap_under_size_shift                               (10)
#define I3DDMA_CAP_STATUS_freeze_ok_shift                                    (9)
#define I3DDMA_CAP_STATUS_vs_rising_occur_shift                              (8)
#define I3DDMA_CAP_STATUS_tg_l_flag_shift                                    (7)
#define I3DDMA_CAP_STATUS_cap_block_shift                                    (6)
#define I3DDMA_CAP_STATUS_cap_field_shift                                    (5)
#define I3DDMA_CAP_STATUS_cap_fifo_full_shift                                (4)
#define I3DDMA_CAP_STATUS_cap_fifo_empty_shift                               (3)
#define I3DDMA_CAP_STATUS_cap_fifo_overflow_shift                            (2)
#define I3DDMA_CAP_STATUS_cap_fifo_underflow_shift                           (1)
#define I3DDMA_CAP_STATUS_cap_ddr_over_range_shift                           (0)
#define I3DDMA_CAP_STATUS_dummy_cap_st_mask                                  (0xFFFFF000)
#define I3DDMA_CAP_STATUS_cap_over_size_mask                                 (0x00000800)
#define I3DDMA_CAP_STATUS_cap_under_size_mask                                (0x00000400)
#define I3DDMA_CAP_STATUS_freeze_ok_mask                                     (0x00000200)
#define I3DDMA_CAP_STATUS_vs_rising_occur_mask                               (0x00000100)
#define I3DDMA_CAP_STATUS_tg_l_flag_mask                                     (0x00000080)
#define I3DDMA_CAP_STATUS_cap_block_mask                                     (0x00000040)
#define I3DDMA_CAP_STATUS_cap_field_mask                                     (0x00000020)
#define I3DDMA_CAP_STATUS_cap_fifo_full_mask                                 (0x00000010)
#define I3DDMA_CAP_STATUS_cap_fifo_empty_mask                                (0x00000008)
#define I3DDMA_CAP_STATUS_cap_fifo_overflow_mask                             (0x00000004)
#define I3DDMA_CAP_STATUS_cap_fifo_underflow_mask                            (0x00000002)
#define I3DDMA_CAP_STATUS_cap_ddr_over_range_mask                            (0x00000001)
#define I3DDMA_CAP_STATUS_dummy_cap_st(data)                                 (0xFFFFF000&((data)<<12))
#define I3DDMA_CAP_STATUS_cap_over_size(data)                                (0x00000800&((data)<<11))
#define I3DDMA_CAP_STATUS_cap_under_size(data)                               (0x00000400&((data)<<10))
#define I3DDMA_CAP_STATUS_freeze_ok(data)                                    (0x00000200&((data)<<9))
#define I3DDMA_CAP_STATUS_vs_rising_occur(data)                              (0x00000100&((data)<<8))
#define I3DDMA_CAP_STATUS_tg_l_flag(data)                                    (0x00000080&((data)<<7))
#define I3DDMA_CAP_STATUS_cap_block(data)                                    (0x00000040&((data)<<6))
#define I3DDMA_CAP_STATUS_cap_field(data)                                    (0x00000020&((data)<<5))
#define I3DDMA_CAP_STATUS_cap_fifo_full(data)                                (0x00000010&((data)<<4))
#define I3DDMA_CAP_STATUS_cap_fifo_empty(data)                               (0x00000008&((data)<<3))
#define I3DDMA_CAP_STATUS_cap_fifo_overflow(data)                            (0x00000004&((data)<<2))
#define I3DDMA_CAP_STATUS_cap_fifo_underflow(data)                           (0x00000002&((data)<<1))
#define I3DDMA_CAP_STATUS_cap_ddr_over_range(data)                           (0x00000001&(data))
#define I3DDMA_CAP_STATUS_get_dummy_cap_st(data)                             ((0xFFFFF000&(data))>>12)
#define I3DDMA_CAP_STATUS_get_cap_over_size(data)                            ((0x00000800&(data))>>11)
#define I3DDMA_CAP_STATUS_get_cap_under_size(data)                           ((0x00000400&(data))>>10)
#define I3DDMA_CAP_STATUS_get_freeze_ok(data)                                ((0x00000200&(data))>>9)
#define I3DDMA_CAP_STATUS_get_vs_rising_occur(data)                          ((0x00000100&(data))>>8)
#define I3DDMA_CAP_STATUS_get_tg_l_flag(data)                                ((0x00000080&(data))>>7)
#define I3DDMA_CAP_STATUS_get_cap_block(data)                                ((0x00000040&(data))>>6)
#define I3DDMA_CAP_STATUS_get_cap_field(data)                                ((0x00000020&(data))>>5)
#define I3DDMA_CAP_STATUS_get_cap_fifo_full(data)                            ((0x00000010&(data))>>4)
#define I3DDMA_CAP_STATUS_get_cap_fifo_empty(data)                           ((0x00000008&(data))>>3)
#define I3DDMA_CAP_STATUS_get_cap_fifo_overflow(data)                        ((0x00000004&(data))>>2)
#define I3DDMA_CAP_STATUS_get_cap_fifo_underflow(data)                       ((0x00000002&(data))>>1)
#define I3DDMA_CAP_STATUS_get_cap_ddr_over_range(data)                       (0x00000001&(data))


#define I3DDMA_TG_V1_END                                                     0x1802583c
#define I3DDMA_TG_V1_END_reg_addr                                            "0xb802583c"
#define I3DDMA_TG_V1_END_reg                                                 0xb802583c
#define I3DDMA_TG_V1_END_inst_addr                                           "0x020F"
#define I3DDMA_TG_V1_END_inst                                                0x020F
#define I3DDMA_TG_V1_END_pullup_en_shift                                     (25)
#define I3DDMA_TG_V1_END_tg_hend1_shift                                      (8)
#define I3DDMA_TG_V1_END_tg_vend1_shift                                      (0)
#define I3DDMA_TG_V1_END_pullup_en_mask                                      (0x02000000)
#define I3DDMA_TG_V1_END_tg_hend1_mask                                       (0x001FFF00)
#define I3DDMA_TG_V1_END_tg_vend1_mask                                       (0x000000FF)
#define I3DDMA_TG_V1_END_pullup_en(data)                                     (0x02000000&((data)<<25))
#define I3DDMA_TG_V1_END_tg_hend1(data)                                      (0x001FFF00&((data)<<8))
#define I3DDMA_TG_V1_END_tg_vend1(data)                                      (0x000000FF&(data))
#define I3DDMA_TG_V1_END_get_pullup_en(data)                                 ((0x02000000&(data))>>25)
#define I3DDMA_TG_V1_END_get_tg_hend1(data)                                  ((0x001FFF00&(data))>>8)
#define I3DDMA_TG_V1_END_get_tg_vend1(data)                                  (0x000000FF&(data))


#define I3DDMA_TG_V2_START                                                   0x18025840
#define I3DDMA_TG_V2_START_reg_addr                                          "0xb8025840"
#define I3DDMA_TG_V2_START_reg                                               0xb8025840
#define I3DDMA_TG_V2_START_inst_addr                                         "0x0210"
#define I3DDMA_TG_V2_START_inst                                              0x0210
#define I3DDMA_TG_V2_START_tg_hstart2_shift                                  (16)
#define I3DDMA_TG_V2_START_tg_vstart2_shift                                  (0)
#define I3DDMA_TG_V2_START_tg_hstart2_mask                                   (0x1FFF0000)
#define I3DDMA_TG_V2_START_tg_vstart2_mask                                   (0x00001FFF)
#define I3DDMA_TG_V2_START_tg_hstart2(data)                                  (0x1FFF0000&((data)<<16))
#define I3DDMA_TG_V2_START_tg_vstart2(data)                                  (0x00001FFF&(data))
#define I3DDMA_TG_V2_START_get_tg_hstart2(data)                              ((0x1FFF0000&(data))>>16)
#define I3DDMA_TG_V2_START_get_tg_vstart2(data)                              (0x00001FFF&(data))


#define I3DDMA_TG_V2_END                                                     0x18025844
#define I3DDMA_TG_V2_END_reg_addr                                            "0xb8025844"
#define I3DDMA_TG_V2_END_reg                                                 0xb8025844
#define I3DDMA_TG_V2_END_inst_addr                                           "0x0211"
#define I3DDMA_TG_V2_END_inst                                                0x0211
#define I3DDMA_TG_V2_END_tg_hend2_shift                                      (16)
#define I3DDMA_TG_V2_END_tg_vend2_shift                                      (0)
#define I3DDMA_TG_V2_END_tg_hend2_mask                                       (0x1FFF0000)
#define I3DDMA_TG_V2_END_tg_vend2_mask                                       (0x00001FFF)
#define I3DDMA_TG_V2_END_tg_hend2(data)                                      (0x1FFF0000&((data)<<16))
#define I3DDMA_TG_V2_END_tg_vend2(data)                                      (0x00001FFF&(data))
#define I3DDMA_TG_V2_END_get_tg_hend2(data)                                  ((0x1FFF0000&(data))>>16)
#define I3DDMA_TG_V2_END_get_tg_vend2(data)                                  (0x00001FFF&(data))


#define I3DDMA_TG_V3_START                                                   0x18025848
#define I3DDMA_TG_V3_START_reg_addr                                          "0xb8025848"
#define I3DDMA_TG_V3_START_reg                                               0xb8025848
#define I3DDMA_TG_V3_START_inst_addr                                         "0x0212"
#define I3DDMA_TG_V3_START_inst                                              0x0212
#define I3DDMA_TG_V3_START_tg_hstart3_shift                                  (16)
#define I3DDMA_TG_V3_START_tg_vstart3_shift                                  (0)
#define I3DDMA_TG_V3_START_tg_hstart3_mask                                   (0x1FFF0000)
#define I3DDMA_TG_V3_START_tg_vstart3_mask                                   (0x00001FFF)
#define I3DDMA_TG_V3_START_tg_hstart3(data)                                  (0x1FFF0000&((data)<<16))
#define I3DDMA_TG_V3_START_tg_vstart3(data)                                  (0x00001FFF&(data))
#define I3DDMA_TG_V3_START_get_tg_hstart3(data)                              ((0x1FFF0000&(data))>>16)
#define I3DDMA_TG_V3_START_get_tg_vstart3(data)                              (0x00001FFF&(data))


#define I3DDMA_TG_V3_END                                                     0x1802584c
#define I3DDMA_TG_V3_END_reg_addr                                            "0xb802584c"
#define I3DDMA_TG_V3_END_reg                                                 0xb802584c
#define I3DDMA_TG_V3_END_inst_addr                                           "0x0213"
#define I3DDMA_TG_V3_END_inst                                                0x0213
#define I3DDMA_TG_V3_END_tg_hend3_shift                                      (16)
#define I3DDMA_TG_V3_END_tg_vend3_shift                                      (0)
#define I3DDMA_TG_V3_END_tg_hend3_mask                                       (0x1FFF0000)
#define I3DDMA_TG_V3_END_tg_vend3_mask                                       (0x00001FFF)
#define I3DDMA_TG_V3_END_tg_hend3(data)                                      (0x1FFF0000&((data)<<16))
#define I3DDMA_TG_V3_END_tg_vend3(data)                                      (0x00001FFF&(data))
#define I3DDMA_TG_V3_END_get_tg_hend3(data)                                  ((0x1FFF0000&(data))>>16)
#define I3DDMA_TG_V3_END_get_tg_vend3(data)                                  (0x00001FFF&(data))


#define I3DDMA_TG_V4_START                                                   0x18025850
#define I3DDMA_TG_V4_START_reg_addr                                          "0xb8025850"
#define I3DDMA_TG_V4_START_reg                                               0xb8025850
#define I3DDMA_TG_V4_START_inst_addr                                         "0x0214"
#define I3DDMA_TG_V4_START_inst                                              0x0214
#define I3DDMA_TG_V4_START_tg_hstart4_shift                                  (16)
#define I3DDMA_TG_V4_START_tg_vstart4_shift                                  (0)
#define I3DDMA_TG_V4_START_tg_hstart4_mask                                   (0x1FFF0000)
#define I3DDMA_TG_V4_START_tg_vstart4_mask                                   (0x00001FFF)
#define I3DDMA_TG_V4_START_tg_hstart4(data)                                  (0x1FFF0000&((data)<<16))
#define I3DDMA_TG_V4_START_tg_vstart4(data)                                  (0x00001FFF&(data))
#define I3DDMA_TG_V4_START_get_tg_hstart4(data)                              ((0x1FFF0000&(data))>>16)
#define I3DDMA_TG_V4_START_get_tg_vstart4(data)                              (0x00001FFF&(data))


#define I3DDMA_TG_V4_END                                                     0x18025854
#define I3DDMA_TG_V4_END_reg_addr                                            "0xb8025854"
#define I3DDMA_TG_V4_END_reg                                                 0xb8025854
#define I3DDMA_TG_V4_END_inst_addr                                           "0x0215"
#define I3DDMA_TG_V4_END_inst                                                0x0215
#define I3DDMA_TG_V4_END_tg_hend4_shift                                      (16)
#define I3DDMA_TG_V4_END_tg_vend4_shift                                      (0)
#define I3DDMA_TG_V4_END_tg_hend4_mask                                       (0x1FFF0000)
#define I3DDMA_TG_V4_END_tg_vend4_mask                                       (0x00001FFF)
#define I3DDMA_TG_V4_END_tg_hend4(data)                                      (0x1FFF0000&((data)<<16))
#define I3DDMA_TG_V4_END_tg_vend4(data)                                      (0x00001FFF&(data))
#define I3DDMA_TG_V4_END_get_tg_hend4(data)                                  ((0x1FFF0000&(data))>>16)
#define I3DDMA_TG_V4_END_get_tg_vend4(data)                                  (0x00001FFF&(data))


#define I3DDMA_CTS_FIFO_CTRL                                                 0x1802585c
#define I3DDMA_CTS_FIFO_CTRL_reg_addr                                        "0xb802585c"
#define I3DDMA_CTS_FIFO_CTRL_reg                                             0xb802585c
#define I3DDMA_CTS_FIFO_CTRL_inst_addr                                       "0x0217"
#define I3DDMA_CTS_FIFO_CTRL_inst                                            0x0217
#define I3DDMA_CTS_FIFO_CTRL_dummy_cts_fifo_shift                            (8)
#define I3DDMA_CTS_FIFO_CTRL_force_ctsfifo_rstn_shift                        (2)
#define I3DDMA_CTS_FIFO_CTRL_en_ctsfifo_vsrst_shift                          (1)
#define I3DDMA_CTS_FIFO_CTRL_en_ctsfifo_bypass_shift                         (0)
#define I3DDMA_CTS_FIFO_CTRL_dummy_cts_fifo_mask                             (0xFFFFFF00)
#define I3DDMA_CTS_FIFO_CTRL_force_ctsfifo_rstn_mask                         (0x00000004)
#define I3DDMA_CTS_FIFO_CTRL_en_ctsfifo_vsrst_mask                           (0x00000002)
#define I3DDMA_CTS_FIFO_CTRL_en_ctsfifo_bypass_mask                          (0x00000001)
#define I3DDMA_CTS_FIFO_CTRL_dummy_cts_fifo(data)                            (0xFFFFFF00&((data)<<8))
#define I3DDMA_CTS_FIFO_CTRL_force_ctsfifo_rstn(data)                        (0x00000004&((data)<<2))
#define I3DDMA_CTS_FIFO_CTRL_en_ctsfifo_vsrst(data)                          (0x00000002&((data)<<1))
#define I3DDMA_CTS_FIFO_CTRL_en_ctsfifo_bypass(data)                         (0x00000001&(data))
#define I3DDMA_CTS_FIFO_CTRL_get_dummy_cts_fifo(data)                        ((0xFFFFFF00&(data))>>8)
#define I3DDMA_CTS_FIFO_CTRL_get_force_ctsfifo_rstn(data)                    ((0x00000004&(data))>>2)
#define I3DDMA_CTS_FIFO_CTRL_get_en_ctsfifo_vsrst(data)                      ((0x00000002&(data))>>1)
#define I3DDMA_CTS_FIFO_CTRL_get_en_ctsfifo_bypass(data)                     (0x00000001&(data))


#define I3DDMA_LR_CRC_CTRL                                                   0x18025860
#define I3DDMA_LR_CRC_CTRL_reg_addr                                          "0xb8025860"
#define I3DDMA_LR_CRC_CTRL_reg                                               0xb8025860
#define I3DDMA_LR_CRC_CTRL_inst_addr                                         "0x0218"
#define I3DDMA_LR_CRC_CTRL_inst                                              0x0218
#define I3DDMA_LR_CRC_CTRL_r_crc_conti_shift                                 (9)
#define I3DDMA_LR_CRC_CTRL_r_crc_start_shift                                 (8)
#define I3DDMA_LR_CRC_CTRL_l_crc_conti_shift                                 (1)
#define I3DDMA_LR_CRC_CTRL_l_crc_start_shift                                 (0)
#define I3DDMA_LR_CRC_CTRL_r_crc_conti_mask                                  (0x00000200)
#define I3DDMA_LR_CRC_CTRL_r_crc_start_mask                                  (0x00000100)
#define I3DDMA_LR_CRC_CTRL_l_crc_conti_mask                                  (0x00000002)
#define I3DDMA_LR_CRC_CTRL_l_crc_start_mask                                  (0x00000001)
#define I3DDMA_LR_CRC_CTRL_r_crc_conti(data)                                 (0x00000200&((data)<<9))
#define I3DDMA_LR_CRC_CTRL_r_crc_start(data)                                 (0x00000100&((data)<<8))
#define I3DDMA_LR_CRC_CTRL_l_crc_conti(data)                                 (0x00000002&((data)<<1))
#define I3DDMA_LR_CRC_CTRL_l_crc_start(data)                                 (0x00000001&(data))
#define I3DDMA_LR_CRC_CTRL_get_r_crc_conti(data)                             ((0x00000200&(data))>>9)
#define I3DDMA_LR_CRC_CTRL_get_r_crc_start(data)                             ((0x00000100&(data))>>8)
#define I3DDMA_LR_CRC_CTRL_get_l_crc_conti(data)                             ((0x00000002&(data))>>1)
#define I3DDMA_LR_CRC_CTRL_get_l_crc_start(data)                             (0x00000001&(data))


#define I3DDMA_CRC_L_RESULT                                                  0x18025864
#define I3DDMA_CRC_L_RESULT_reg_addr                                         "0xb8025864"
#define I3DDMA_CRC_L_RESULT_reg                                              0xb8025864
#define I3DDMA_CRC_L_RESULT_inst_addr                                        "0x0219"
#define I3DDMA_CRC_L_RESULT_inst                                             0x0219
#define I3DDMA_CRC_L_RESULT_crc_l_result_shift                               (0)
#define I3DDMA_CRC_L_RESULT_crc_l_result_mask                                (0xFFFFFFFF)
#define I3DDMA_CRC_L_RESULT_crc_l_result(data)                               (0xFFFFFFFF&(data))
#define I3DDMA_CRC_L_RESULT_get_crc_l_result(data)                           (0xFFFFFFFF&(data))


#define I3DDMA_CRC_R_RESULT                                                  0x18025868
#define I3DDMA_CRC_R_RESULT_reg_addr                                         "0xb8025868"
#define I3DDMA_CRC_R_RESULT_reg                                              0xb8025868
#define I3DDMA_CRC_R_RESULT_inst_addr                                        "0x021A"
#define I3DDMA_CRC_R_RESULT_inst                                             0x021A
#define I3DDMA_CRC_R_RESULT_crc_r_result_shift                               (0)
#define I3DDMA_CRC_R_RESULT_crc_r_result_mask                                (0xFFFFFFFF)
#define I3DDMA_CRC_R_RESULT_crc_r_result(data)                               (0xFFFFFFFF&(data))
#define I3DDMA_CRC_R_RESULT_get_crc_r_result(data)                           (0xFFFFFFFF&(data))


#define I3DDMA_INTERRUPT_ENABLE                                              0x1802586c
#define I3DDMA_INTERRUPT_ENABLE_reg_addr                                     "0xb802586c"
#define I3DDMA_INTERRUPT_ENABLE_reg                                          0xb802586c
#define I3DDMA_INTERRUPT_ENABLE_inst_addr                                    "0x021B"
#define I3DDMA_INTERRUPT_ENABLE_inst                                         0x021B
#define I3DDMA_INTERRUPT_ENABLE_mem_err_ie_shift                             (2)
#define I3DDMA_INTERRUPT_ENABLE_fifo_err_ie_shift                            (1)
#define I3DDMA_INTERRUPT_ENABLE_vs_rising_ie_shift                           (0)
#define I3DDMA_INTERRUPT_ENABLE_mem_err_ie_mask                              (0x00000004)
#define I3DDMA_INTERRUPT_ENABLE_fifo_err_ie_mask                             (0x00000002)
#define I3DDMA_INTERRUPT_ENABLE_vs_rising_ie_mask                            (0x00000001)
#define I3DDMA_INTERRUPT_ENABLE_mem_err_ie(data)                             (0x00000004&((data)<<2))
#define I3DDMA_INTERRUPT_ENABLE_fifo_err_ie(data)                            (0x00000002&((data)<<1))
#define I3DDMA_INTERRUPT_ENABLE_vs_rising_ie(data)                           (0x00000001&(data))
#define I3DDMA_INTERRUPT_ENABLE_get_mem_err_ie(data)                         ((0x00000004&(data))>>2)
#define I3DDMA_INTERRUPT_ENABLE_get_fifo_err_ie(data)                        ((0x00000002&(data))>>1)
#define I3DDMA_INTERRUPT_ENABLE_get_vs_rising_ie(data)                       (0x00000001&(data))


#define I3DDMA_ENABLE                                                 0x18025870
#define I3DDMA_ENABLE_reg_addr                                        "0xb8025870"
#define I3DDMA_ENABLE_reg                                             0xb8025870
#define I3DDMA_ENABLE_inst_addr                                       "0x021C"
#define I3DDMA_ENABLE_inst                                            0x021C
#define I3DDMA_ENABLE_frc_style_shift                                 (4)
#define I3DDMA_ENABLE_frc_en_shift                                    (3)
#define I3DDMA_ENABLE_tg_en_shift                                     (2)
#define I3DDMA_ENABLE_lr_separate_en_shift                            (1)
#define I3DDMA_ENABLE_cap_en_shift                                    (0)
#define I3DDMA_ENABLE_frc_style_mask                                  (0x00000010)
#define I3DDMA_ENABLE_frc_en_mask                                     (0x00000008)
#define I3DDMA_ENABLE_tg_en_mask                                      (0x00000004)
#define I3DDMA_ENABLE_lr_separate_en_mask                             (0x00000002)
#define I3DDMA_ENABLE_cap_en_mask                                     (0x00000001)
#define I3DDMA_ENABLE_frc_style(data)                                 (0x00000010&((data)<<4))
#define I3DDMA_ENABLE_frc_en(data)                                    (0x00000008&((data)<<3))
#define I3DDMA_ENABLE_tg_en(data)                                     (0x00000004&((data)<<2))
#define I3DDMA_ENABLE_lr_separate_en(data)                            (0x00000002&((data)<<1))
#define I3DDMA_ENABLE_cap_en(data)                                    (0x00000001&(data))
#define I3DDMA_ENABLE_get_frc_style(data)                             ((0x00000010&(data))>>4)
#define I3DDMA_ENABLE_get_frc_en(data)                                ((0x00000008&(data))>>3)
#define I3DDMA_ENABLE_get_tg_en(data)                                 ((0x00000004&(data))>>2)
#define I3DDMA_ENABLE_get_lr_separate_en(data)                        ((0x00000002&(data))>>1)
#define I3DDMA_ENABLE_get_cap_en(data)                                (0x00000001&(data))


#define I3DDMA_BYTE_CHANNEL_SWAP                                      0x18025874
#define I3DDMA_BYTE_CHANNEL_SWAP_reg_addr                             "0xb8025874"
#define I3DDMA_BYTE_CHANNEL_SWAP_reg                                  0xb8025874
#define I3DDMA_BYTE_CHANNEL_SWAP_inst_addr                            "0x021D"
#define I3DDMA_BYTE_CHANNEL_SWAP_inst                                 0x021D
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_channel_swap_shift               (4)
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_8byte_swap_shift                 (3)
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_4byte_swap_shift                 (2)
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_2byte_swap_shift                 (1)
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_1byte_swap_shift                 (0)
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_channel_swap_mask                (0x00000070)
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_8byte_swap_mask                  (0x00000008)
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_4byte_swap_mask                  (0x00000004)
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_2byte_swap_mask                  (0x00000002)
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_1byte_swap_mask                  (0x00000001)
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_channel_swap(data)               (0x00000070&((data)<<4))
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_8byte_swap(data)                 (0x00000008&((data)<<3))
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_4byte_swap(data)                 (0x00000004&((data)<<2))
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_2byte_swap(data)                 (0x00000002&((data)<<1))
#define I3DDMA_BYTE_CHANNEL_SWAP_dma_1byte_swap(data)                 (0x00000001&(data))
#define I3DDMA_BYTE_CHANNEL_SWAP_get_dma_channel_swap(data)           ((0x00000070&(data))>>4)
#define I3DDMA_BYTE_CHANNEL_SWAP_get_dma_8byte_swap(data)             ((0x00000008&(data))>>3)
#define I3DDMA_BYTE_CHANNEL_SWAP_get_dma_4byte_swap(data)             ((0x00000004&(data))>>2)
#define I3DDMA_BYTE_CHANNEL_SWAP_get_dma_2byte_swap(data)             ((0x00000002&(data))>>1)
#define I3DDMA_BYTE_CHANNEL_SWAP_get_dma_1byte_swap(data)             (0x00000001&(data))


#define I3DDMA_CAP_L1_START_DB_2                                             0x18025878
#define I3DDMA_CAP_L1_START_DB_2_reg_addr                                    "0xb8025878"
#define I3DDMA_CAP_L1_START_DB_2_reg                                         0xb8025878
#define I3DDMA_CAP_L1_START_DB_2_inst_addr                                   "0x021E"
#define I3DDMA_CAP_L1_START_DB_2_inst                                        0x021E
#define I3DDMA_CAP_L1_START_DB_2_cap2_l1_start_db_shift                      (3)
#define I3DDMA_CAP_L1_START_DB_2_cap2_l1_start_db_mask                       (0x7FFFFFF8)
#define I3DDMA_CAP_L1_START_DB_2_cap2_l1_start_db(data)                      (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_L1_START_DB_2_get_cap2_l1_start_db(data)                  ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_CAP_R1_START_DB_2                                             0x1802587c
#define I3DDMA_CAP_R1_START_DB_2_reg_addr                                    "0xb802587c"
#define I3DDMA_CAP_R1_START_DB_2_reg                                         0xb802587c
#define I3DDMA_CAP_R1_START_DB_2_inst_addr                                   "0x021F"
#define I3DDMA_CAP_R1_START_DB_2_inst                                        0x021F
#define I3DDMA_CAP_R1_START_DB_2_cap2_r1_start_db_shift                      (3)
#define I3DDMA_CAP_R1_START_DB_2_cap2_r1_start_db_mask                       (0x7FFFFFF8)
#define I3DDMA_CAP_R1_START_DB_2_cap2_r1_start_db(data)                      (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_R1_START_DB_2_get_cap2_r1_start_db(data)                  ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_CAP_STATUS_2                                                  0x18025880
#define I3DDMA_CAP_STATUS_2_reg_addr                                         "0xb8025880"
#define I3DDMA_CAP_STATUS_2_reg                                              0xb8025880
#define I3DDMA_CAP_STATUS_2_inst_addr                                        "0x0220"
#define I3DDMA_CAP_STATUS_2_inst                                             0x0220
#define I3DDMA_CAP_STATUS_2_cap2_block_shift                                 (6)
#define I3DDMA_CAP_STATUS_2_cap2_fifo_full_shift                             (4)
#define I3DDMA_CAP_STATUS_2_cap2_fifo_empty_shift                            (3)
#define I3DDMA_CAP_STATUS_2_cap2_fifo_overflow_shift                         (2)
#define I3DDMA_CAP_STATUS_2_cap2_fifo_underflow_shift                        (1)
#define I3DDMA_CAP_STATUS_2_cap2_ddr_over_range_shift                        (0)
#define I3DDMA_CAP_STATUS_2_cap2_block_mask                                  (0x00000040)
#define I3DDMA_CAP_STATUS_2_cap2_fifo_full_mask                              (0x00000010)
#define I3DDMA_CAP_STATUS_2_cap2_fifo_empty_mask                             (0x00000008)
#define I3DDMA_CAP_STATUS_2_cap2_fifo_overflow_mask                          (0x00000004)
#define I3DDMA_CAP_STATUS_2_cap2_fifo_underflow_mask                         (0x00000002)
#define I3DDMA_CAP_STATUS_2_cap2_ddr_over_range_mask                         (0x00000001)
#define I3DDMA_CAP_STATUS_2_cap2_block(data)                                 (0x00000040&((data)<<6))
#define I3DDMA_CAP_STATUS_2_cap2_fifo_full(data)                             (0x00000010&((data)<<4))
#define I3DDMA_CAP_STATUS_2_cap2_fifo_empty(data)                            (0x00000008&((data)<<3))
#define I3DDMA_CAP_STATUS_2_cap2_fifo_overflow(data)                         (0x00000004&((data)<<2))
#define I3DDMA_CAP_STATUS_2_cap2_fifo_underflow(data)                        (0x00000002&((data)<<1))
#define I3DDMA_CAP_STATUS_2_cap2_ddr_over_range(data)                        (0x00000001&(data))
#define I3DDMA_CAP_STATUS_2_get_cap2_block(data)                             ((0x00000040&(data))>>6)
#define I3DDMA_CAP_STATUS_2_get_cap2_fifo_full(data)                         ((0x00000010&(data))>>4)
#define I3DDMA_CAP_STATUS_2_get_cap2_fifo_empty(data)                        ((0x00000008&(data))>>3)
#define I3DDMA_CAP_STATUS_2_get_cap2_fifo_overflow(data)                     ((0x00000004&(data))>>2)
#define I3DDMA_CAP_STATUS_2_get_cap2_fifo_underflow(data)                    ((0x00000002&(data))>>1)
#define I3DDMA_CAP_STATUS_2_get_cap2_ddr_over_range(data)                    (0x00000001&(data))


#define I3DDMA_CAP_L3_START                                                  0x18025884
#define I3DDMA_CAP_L3_START_reg_addr                                         "0xb8025884"
#define I3DDMA_CAP_L3_START_reg                                              0xb8025884
#define I3DDMA_CAP_L3_START_inst_addr                                        "0x0221"
#define I3DDMA_CAP_L3_START_inst                                             0x0221
#define I3DDMA_CAP_L3_START_cap_l3_start_shift                               (3)
#define I3DDMA_CAP_L3_START_cap_l3_start_mask                                (0x7FFFFFF8)
#define I3DDMA_CAP_L3_START_cap_l3_start(data)                               (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_L3_START_get_cap_l3_start(data)                           ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_CAP_R3_START                                                  0x18025888
#define I3DDMA_CAP_R3_START_reg_addr                                         "0xb8025888"
#define I3DDMA_CAP_R3_START_reg                                              0xb8025888
#define I3DDMA_CAP_R3_START_inst_addr                                        "0x0222"
#define I3DDMA_CAP_R3_START_inst                                             0x0222
#define I3DDMA_CAP_R3_START_cap_r3_start_shift                               (3)
#define I3DDMA_CAP_R3_START_cap_r3_start_mask                                (0x7FFFFFF8)
#define I3DDMA_CAP_R3_START_cap_r3_start(data)                               (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_R3_START_get_cap_r3_start(data)                           ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_CAP_L4_START                                                  0x1802588c
#define I3DDMA_CAP_L4_START_reg_addr                                         "0xb802588c"
#define I3DDMA_CAP_L4_START_reg                                              0xb802588c
#define I3DDMA_CAP_L4_START_inst_addr                                        "0x0223"
#define I3DDMA_CAP_L4_START_inst                                             0x0223
#define I3DDMA_CAP_L4_START_cap_l4_start_shift                               (3)
#define I3DDMA_CAP_L4_START_cap_l4_start_mask                                (0x7FFFFFF8)
#define I3DDMA_CAP_L4_START_cap_l4_start(data)                               (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_L4_START_get_cap_l4_start(data)                           ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_CAP_R4_START                                                  0x18025890
#define I3DDMA_CAP_R4_START_reg_addr                                         "0xb8025890"
#define I3DDMA_CAP_R4_START_reg                                              0xb8025890
#define I3DDMA_CAP_R4_START_inst_addr                                        "0x0224"
#define I3DDMA_CAP_R4_START_inst                                             0x0224
#define I3DDMA_CAP_R4_START_cap_r4_start_shift                               (3)
#define I3DDMA_CAP_R4_START_cap_r4_start_mask                                (0x7FFFFFF8)
#define I3DDMA_CAP_R4_START_cap_r4_start(data)                               (0x7FFFFFF8&((data)<<3))
#define I3DDMA_CAP_R4_START_get_cap_r4_start(data)                           ((0x7FFFFFF8&(data))>>3)


#define I3DDMA_BIST_CAP_FAIL                                          0x180258d8
#define I3DDMA_BIST_CAP_FAIL_reg_addr                                 "0xb80258d8"
#define I3DDMA_BIST_CAP_FAIL_reg                                      0xb80258d8
#define I3DDMA_BIST_CAP_FAIL_inst_addr                                "0x0236"
#define I3DDMA_BIST_CAP_FAIL_inst                                     0x0236
#define I3DDMA_BIST_CAP_FAIL_i3ddma_bist_cap2_fail_shift              (1)
#define I3DDMA_BIST_CAP_FAIL_i3ddma_bist_cap_fail_shift               (0)
#define I3DDMA_BIST_CAP_FAIL_i3ddma_bist_cap2_fail_mask               (0x00000002)
#define I3DDMA_BIST_CAP_FAIL_i3ddma_bist_cap_fail_mask                (0x00000001)
#define I3DDMA_BIST_CAP_FAIL_i3ddma_bist_cap2_fail(data)              (0x00000002&((data)<<1))
#define I3DDMA_BIST_CAP_FAIL_i3ddma_bist_cap_fail(data)               (0x00000001&(data))
#define I3DDMA_BIST_CAP_FAIL_get_i3ddma_bist_cap2_fail(data)          ((0x00000002&(data))>>1)
#define I3DDMA_BIST_CAP_FAIL_get_i3ddma_bist_cap_fail(data)           (0x00000001&(data))


#define I3DDMA_DRF_CAP_FAIL                                           0x180258ec
#define I3DDMA_DRF_CAP_FAIL_reg_addr                                  "0xb80258ec"
#define I3DDMA_DRF_CAP_FAIL_reg                                       0xb80258ec
#define I3DDMA_DRF_CAP_FAIL_inst_addr                                 "0x023B"
#define I3DDMA_DRF_CAP_FAIL_inst                                      0x023B
#define I3DDMA_DRF_CAP_FAIL_i3ddma_drf_cap2_fail_shift                (1)
#define I3DDMA_DRF_CAP_FAIL_i3ddma_drf_cap_fail_shift                 (0)
#define I3DDMA_DRF_CAP_FAIL_i3ddma_drf_cap2_fail_mask                 (0x00000002)
#define I3DDMA_DRF_CAP_FAIL_i3ddma_drf_cap_fail_mask                  (0x00000001)
#define I3DDMA_DRF_CAP_FAIL_i3ddma_drf_cap2_fail(data)                (0x00000002&((data)<<1))
#define I3DDMA_DRF_CAP_FAIL_i3ddma_drf_cap_fail(data)                 (0x00000001&(data))
#define I3DDMA_DRF_CAP_FAIL_get_i3ddma_drf_cap2_fail(data)            ((0x00000002&(data))>>1)
#define I3DDMA_DRF_CAP_FAIL_get_i3ddma_drf_cap_fail(data)             (0x00000001&(data))


#define I3DDMA_DVS                                                    0x180258f0
#define I3DDMA_DVS_reg_addr                                           "0xb80258f0"
#define I3DDMA_DVS_reg                                                0xb80258f0
#define I3DDMA_DVS_inst_addr                                          "0x023C"
#define I3DDMA_DVS_inst                                               0x023C
#define I3DDMA_DVS_cap2_dvsb_shift                                    (12)
#define I3DDMA_DVS_cap2_dvsa_shift                                    (8)
#define I3DDMA_DVS_cap_dvsb_shift                                     (4)
#define I3DDMA_DVS_cap_dvsa_shift                                     (0)
#define I3DDMA_DVS_cap2_dvsb_mask                                     (0x0000F000)
#define I3DDMA_DVS_cap2_dvsa_mask                                     (0x00000F00)
#define I3DDMA_DVS_cap_dvsb_mask                                      (0x000000F0)
#define I3DDMA_DVS_cap_dvsa_mask                                      (0x0000000F)
#define I3DDMA_DVS_cap2_dvsb(data)                                    (0x0000F000&((data)<<12))
#define I3DDMA_DVS_cap2_dvsa(data)                                    (0x00000F00&((data)<<8))
#define I3DDMA_DVS_cap_dvsb(data)                                     (0x000000F0&((data)<<4))
#define I3DDMA_DVS_cap_dvsa(data)                                     (0x0000000F&(data))
#define I3DDMA_DVS_get_cap2_dvsb(data)                                ((0x0000F000&(data))>>12)
#define I3DDMA_DVS_get_cap2_dvsa(data)                                ((0x00000F00&(data))>>8)
#define I3DDMA_DVS_get_cap_dvsb(data)                                 ((0x000000F0&(data))>>4)
#define I3DDMA_DVS_get_cap_dvsa(data)                                 (0x0000000F&(data))


#define I3DDMA_DVSE                                                   0x180258f4
#define I3DDMA_DVSE_reg_addr                                          "0xb80258f4"
#define I3DDMA_DVSE_reg                                               0xb80258f4
#define I3DDMA_DVSE_inst_addr                                         "0x023D"
#define I3DDMA_DVSE_inst                                              0x023D
#define I3DDMA_DVSE_cap2_dvseb_shift                                  (3)
#define I3DDMA_DVSE_cap2_dvsea_shift                                  (2)
#define I3DDMA_DVSE_cap_dvseb_shift                                   (1)
#define I3DDMA_DVSE_cap_dvsea_shift                                   (0)
#define I3DDMA_DVSE_cap2_dvseb_mask                                   (0x00000008)
#define I3DDMA_DVSE_cap2_dvsea_mask                                   (0x00000004)
#define I3DDMA_DVSE_cap_dvseb_mask                                    (0x00000002)
#define I3DDMA_DVSE_cap_dvsea_mask                                    (0x00000001)
#define I3DDMA_DVSE_cap2_dvseb(data)                                  (0x00000008&((data)<<3))
#define I3DDMA_DVSE_cap2_dvsea(data)                                  (0x00000004&((data)<<2))
#define I3DDMA_DVSE_cap_dvseb(data)                                   (0x00000002&((data)<<1))
#define I3DDMA_DVSE_cap_dvsea(data)                                   (0x00000001&(data))
#define I3DDMA_DVSE_get_cap2_dvseb(data)                              ((0x00000008&(data))>>3)
#define I3DDMA_DVSE_get_cap2_dvsea(data)                              ((0x00000004&(data))>>2)
#define I3DDMA_DVSE_get_cap_dvseb(data)                               ((0x00000002&(data))>>1)
#define I3DDMA_DVSE_get_cap_dvsea(data)                               (0x00000001&(data))


#define I3DDMA_LS                                                     0x180258f8
#define I3DDMA_LS_reg_addr                                            "0xb80258f8"
#define I3DDMA_LS_reg                                                 0xb80258f8
#define I3DDMA_LS_inst_addr                                           "0x023E"
#define I3DDMA_LS_inst                                                0x023E
#define I3DDMA_LS_cap2_ls_shift                                       (1)
#define I3DDMA_LS_cap_ls_shift                                        (0)
#define I3DDMA_LS_cap2_ls_mask                                        (0x00000002)
#define I3DDMA_LS_cap_ls_mask                                         (0x00000001)
#define I3DDMA_LS_cap2_ls(data)                                       (0x00000002&((data)<<1))
#define I3DDMA_LS_cap_ls(data)                                        (0x00000001&(data))
#define I3DDMA_LS_get_cap2_ls(data)                                   ((0x00000002&(data))>>1)
#define I3DDMA_LS_get_cap_ls(data)                                    (0x00000001&(data))
#endif
