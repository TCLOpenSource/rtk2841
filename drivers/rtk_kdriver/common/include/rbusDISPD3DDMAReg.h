/**
* @file rbusDISPD3DDMAReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2010/7/7
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_DISPD3DDMA_REG_H_
#define _RBUS_DISPD3DDMA_REG_H_

#include "rbus/rbusTypes.h"




// DISPD3DDMA Register Address

#define DISPD3DDMA_CAP_CTL0_VADDR                  (0xb802c710)
#define DISPD3DDMA_CAP_CTL1_VADDR                  (0xb802c714)
#define DISPD3DDMA_CAP_BOUNDARYADDR1_VADDR         (0xb802c718)
#define DISPD3DDMA_CAP_BOUNDARYADDR2_VADDR         (0xb802c71c)
#define DISPD3DDMA_CAP_L1_START_VADDR              (0xb802c720)
#define DISPD3DDMA_CAP_L2_START_VADDR              (0xb802c724)
#define DISPD3DDMA_CAP_R1_START_VADDR              (0xb802c728)
#define DISPD3DDMA_CAP_R2_START_VADDR              (0xb802c72c)
#define DISPD3DDMA_CAP_LINESTEP_VADDR              (0xb802c730)
#define DISPD3DDMA_CAP_STATUS_VADDR                (0xb802c734)
#define DISPD3DDMA_DISPLAY_OUTPUT_VADDR            (0xb802c780)
#define DISPD3DDMA_DISPLAY_PREVSTART_VADDR         (0xb802c784)
#define DISPD3DDMA_DISPLAY_NUMWTL_VADDR            (0xb802c788)
#define DISPD3DDMA_DISPLAY_RDNUMLENREM_VADDR       (0xb802c78c)
#define DISPD3DDMA_DISPLAY_LINENUM_VADDR           (0xb802c790)
#define DISPD3DDMA_DISPLAY_ACTIVESPACE_VALUE_VADDR (0xb802c794)
#define DISPD3DDMA_DISPLAY_STATUS_VADDR            (0xb802c798)
#define DISPD3DDMA_MBIST_VADDR                     (0xb802c79c)
#define DISPD3DDMA_CAP_CRC_CTRL_VADDR              (0xb802c7a0)
#define DISPD3DDMA_CAP_CRC_L_RESULT_VADDR          (0xb802c7a4)
#define DISPD3DDMA_CAP_CRC_R_RESULT_VADDR          (0xb802c7a8)
#define DISPD3DDMA_CAP_L_DES_CRC_VADDR             (0xb802c7ac)
#define DISPD3DDMA_CAP_R_DES_CRC_VADDR             (0xb802c7b0)
#define DISPD3DDMA_CAP_CRC_ERR_CNT_VADDR           (0xb802c7b4)
#define DISPD3DDMA_DISP1_START_ADDR1_VADDR         (0xb802c7b8)
#define DISPD3DDMA_DISP1_START_ADDR2_VADDR         (0xb802c7bc)
#define DISPD3DDMA_DISP2_START_ADDR1_VADDR         (0xb802c7c0)
#define DISPD3DDMA_DISP2_START_ADDR2_VADDR         (0xb802c7c4)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======DISPD3DDMA register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  freeze_en:1;
        RBus_UInt32  cap_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  frame_mode:1;
        RBus_UInt32  cap_vs_fall_rst_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  bit_sel:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  cap_write_len:6;
        RBus_UInt32  res5:2;
        RBus_UInt32  cap_write_rem:6;
    };
}DISPD3DDMA_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_cap_ctl1:9;
        RBus_UInt32  cap_water_lv:7;
        RBus_UInt32  cap_write_num:16;
    };
}DISPD3DDMA_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_mem_up_limit:28;
        RBus_UInt32  res2:3;
    };
}DISPD3DDMA_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_mem_low_limit:28;
        RBus_UInt32  res2:3;
    };
}DISPD3DDMA_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_l1_start:28;
        RBus_UInt32  res2:3;
    };
}DISPD3DDMA_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_l2_start:28;
        RBus_UInt32  res2:3;
    };
}DISPD3DDMA_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_r1_start:28;
        RBus_UInt32  res2:3;
    };
}DISPD3DDMA_cap_r1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_r2_start:28;
        RBus_UInt32  res2:3;
    };
}DISPD3DDMA_cap_r2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  line_step:28;
        RBus_UInt32  res2:3;
    };
}DISPD3DDMA_cap_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_cap_st:26;
        RBus_UInt32  cap_block:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_ddr_over_range:1;
    };
}DISPD3DDMA_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  disp2_3ddma_en:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  disp_vs_fall_rst_en:1;
        RBus_UInt32  disp_3ddma_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  active_space_den_en:1;
        RBus_UInt32  rm_r_vs:1;
        RBus_UInt32  stop_burst_en:1;
        RBus_UInt32  l_flag_inv:1;
        RBus_UInt32  side_by_side_en:1;
        RBus_UInt32  output_format:2;
    };
}DISPD3DDMA_display_output_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  disp2_pre_rd_v_start:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  pre_rd_v_start:11;
    };
}DISPD3DDMA_display_prevstart_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  pixel_num:12;
        RBus_UInt32  res2:1;
        RBus_UInt32  wtlvl:7;
    };
}DISPD3DDMA_display_numwtl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_num:16;
        RBus_UInt32  res1:2;
        RBus_UInt32  read_len:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  read_remain:6;
    };
}DISPD3DDMA_display_rdnumlenrem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  line_number:12;
    };
}DISPD3DDMA_display_linenum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  blank_r:10;
        RBus_UInt32  blank_g:10;
        RBus_UInt32  blank_b:10;
    };
}DISPD3DDMA_display_activespace_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  disp2_clr_over_range:1;
        RBus_UInt32  disp2_fifo_clr:1;
        RBus_UInt32  disp2_fifo_full:1;
        RBus_UInt32  disp2_fifo_empty:1;
        RBus_UInt32  disp2_fifo_overflow:1;
        RBus_UInt32  disp2_fifo_underflow:1;
        RBus_UInt32  disp2_adr_down_over_range:1;
        RBus_UInt32  disp2_adr_up_over_range:1;
        RBus_UInt32  disp_clr_over_range:1;
        RBus_UInt32  disp_fifo_clr:1;
        RBus_UInt32  disp_fifo_full:1;
        RBus_UInt32  disp_fifo_empty:1;
        RBus_UInt32  disp_fifo_overflow:1;
        RBus_UInt32  disp_fifo_underflow:1;
        RBus_UInt32  disp_adr_down_over_range:1;
        RBus_UInt32  disp_adr_up_over_range:1;
    };
}DISPD3DDMA_display_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  cap_dvs_0:3;
        RBus_UInt32  cap_dvse_0:1;
        RBus_UInt32  disp1_dvs_0:3;
        RBus_UInt32  disp1_dvse_0:1;
        RBus_UInt32  disp2_dvs_0:3;
        RBus_UInt32  disp2_dvse_0:1;
        RBus_UInt32  drf_test_resume:1;
        RBus_UInt32  drf_start_pause:1;
        RBus_UInt32  drf_bist_done:1;
        RBus_UInt32  cap_drf_bist_fail:1;
        RBus_UInt32  disp1_drf_bist_fail:1;
        RBus_UInt32  disp2_drf_bist_fail:1;
        RBus_UInt32  drf_bist_mode:1;
        RBus_UInt32  bist_done:1;
        RBus_UInt32  cap_bist_ok:1;
        RBus_UInt32  disp1_bist_ok:1;
        RBus_UInt32  disp2_bist_ok:1;
        RBus_UInt32  bist_rst:1;
        RBus_UInt32  bist_en:1;
    };
}DISPD3DDMA_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  crc_3d_en:1;
        RBus_UInt32  crc_conti:1;
        RBus_UInt32  crc_start:1;
    };
}DISPD3DDMA_cap_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}DISPD3DDMA_cap_crc_l_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}DISPD3DDMA_cap_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}DISPD3DDMA_cap_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}DISPD3DDMA_cap_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_err_cnt:16;
        RBus_UInt32  l_crc_err_cnt:16;
    };
}DISPD3DDMA_cap_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  disp1_start_addr1:28;
        RBus_UInt32  res2:3;
    };
}DISPD3DDMA_disp1_start_addr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  disp1_start_addr2:28;
        RBus_UInt32  res2:3;
    };
}DISPD3DDMA_disp1_start_addr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  disp2_start_addr1:28;
        RBus_UInt32  res2:3;
    };
}DISPD3DDMA_disp2_start_addr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  disp2_start_addr2:28;
        RBus_UInt32  res2:3;
    };
}DISPD3DDMA_disp2_start_addr2_RBUS;





#else //apply LITTLE_ENDIAN


//======DISPD3DDMA register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_rem:6;
        RBus_UInt32  res5:2;
        RBus_UInt32  cap_write_len:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  bit_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  cap_vs_fall_rst_en:1;
        RBus_UInt32  frame_mode:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cap_en:1;
        RBus_UInt32  freeze_en:1;
        RBus_UInt32  res1:6;
    };
}DISPD3DDMA_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_num:16;
        RBus_UInt32  cap_water_lv:7;
        RBus_UInt32  dummy_cap_ctl1:9;
    };
}DISPD3DDMA_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:3;
        RBus_UInt32  cap_mem_up_limit:28;
        RBus_UInt32  res1:1;
    };
}DISPD3DDMA_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:3;
        RBus_UInt32  cap_mem_low_limit:28;
        RBus_UInt32  res1:1;
    };
}DISPD3DDMA_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:3;
        RBus_UInt32  cap_l1_start:28;
        RBus_UInt32  res1:1;
    };
}DISPD3DDMA_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:3;
        RBus_UInt32  cap_l2_start:28;
        RBus_UInt32  res1:1;
    };
}DISPD3DDMA_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:3;
        RBus_UInt32  cap_r1_start:28;
        RBus_UInt32  res1:1;
    };
}DISPD3DDMA_cap_r1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:3;
        RBus_UInt32  cap_r2_start:28;
        RBus_UInt32  res1:1;
    };
}DISPD3DDMA_cap_r2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:3;
        RBus_UInt32  line_step:28;
        RBus_UInt32  res1:1;
    };
}DISPD3DDMA_cap_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_ddr_over_range:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  cap_block:1;
        RBus_UInt32  dummy_cap_st:26;
    };
}DISPD3DDMA_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  output_format:2;
        RBus_UInt32  side_by_side_en:1;
        RBus_UInt32  l_flag_inv:1;
        RBus_UInt32  stop_burst_en:1;
        RBus_UInt32  rm_r_vs:1;
        RBus_UInt32  active_space_den_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  disp_3ddma_en:1;
        RBus_UInt32  disp_vs_fall_rst_en:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  disp2_3ddma_en:1;
        RBus_UInt32  res1:15;
    };
}DISPD3DDMA_display_output_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_rd_v_start:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  disp2_pre_rd_v_start:11;
        RBus_UInt32  res1:5;
    };
}DISPD3DDMA_display_prevstart_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wtlvl:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pixel_num:12;
        RBus_UInt32  res1:12;
    };
}DISPD3DDMA_display_numwtl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_remain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  read_len:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  read_num:16;
    };
}DISPD3DDMA_display_rdnumlenrem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line_number:12;
        RBus_UInt32  res1:20;
    };
}DISPD3DDMA_display_linenum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blank_b:10;
        RBus_UInt32  blank_g:10;
        RBus_UInt32  blank_r:10;
        RBus_UInt32  res1:2;
    };
}DISPD3DDMA_display_activespace_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_adr_up_over_range:1;
        RBus_UInt32  disp_adr_down_over_range:1;
        RBus_UInt32  disp_fifo_underflow:1;
        RBus_UInt32  disp_fifo_overflow:1;
        RBus_UInt32  disp_fifo_empty:1;
        RBus_UInt32  disp_fifo_full:1;
        RBus_UInt32  disp_fifo_clr:1;
        RBus_UInt32  disp_clr_over_range:1;
        RBus_UInt32  disp2_adr_up_over_range:1;
        RBus_UInt32  disp2_adr_down_over_range:1;
        RBus_UInt32  disp2_fifo_underflow:1;
        RBus_UInt32  disp2_fifo_overflow:1;
        RBus_UInt32  disp2_fifo_empty:1;
        RBus_UInt32  disp2_fifo_full:1;
        RBus_UInt32  disp2_fifo_clr:1;
        RBus_UInt32  disp2_clr_over_range:1;
        RBus_UInt32  res1:16;
    };
}DISPD3DDMA_display_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_en:1;
        RBus_UInt32  bist_rst:1;
        RBus_UInt32  disp2_bist_ok:1;
        RBus_UInt32  disp1_bist_ok:1;
        RBus_UInt32  cap_bist_ok:1;
        RBus_UInt32  bist_done:1;
        RBus_UInt32  drf_bist_mode:1;
        RBus_UInt32  disp2_drf_bist_fail:1;
        RBus_UInt32  disp1_drf_bist_fail:1;
        RBus_UInt32  cap_drf_bist_fail:1;
        RBus_UInt32  drf_bist_done:1;
        RBus_UInt32  drf_start_pause:1;
        RBus_UInt32  drf_test_resume:1;
        RBus_UInt32  disp2_dvse_0:1;
        RBus_UInt32  disp2_dvs_0:3;
        RBus_UInt32  disp1_dvse_0:1;
        RBus_UInt32  disp1_dvs_0:3;
        RBus_UInt32  cap_dvse_0:1;
        RBus_UInt32  cap_dvs_0:3;
        RBus_UInt32  res1:7;
    };
}DISPD3DDMA_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_start:1;
        RBus_UInt32  crc_conti:1;
        RBus_UInt32  crc_3d_en:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  res1:22;
    };
}DISPD3DDMA_cap_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}DISPD3DDMA_cap_crc_l_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}DISPD3DDMA_cap_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}DISPD3DDMA_cap_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}DISPD3DDMA_cap_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_err_cnt:16;
        RBus_UInt32  r_crc_err_cnt:16;
    };
}DISPD3DDMA_cap_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:3;
        RBus_UInt32  disp1_start_addr1:28;
        RBus_UInt32  res1:1;
    };
}DISPD3DDMA_disp1_start_addr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:3;
        RBus_UInt32  disp1_start_addr2:28;
        RBus_UInt32  res1:1;
    };
}DISPD3DDMA_disp1_start_addr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:3;
        RBus_UInt32  disp2_start_addr1:28;
        RBus_UInt32  res1:1;
    };
}DISPD3DDMA_disp2_start_addr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:3;
        RBus_UInt32  disp2_start_addr2:28;
        RBus_UInt32  res1:1;
    };
}DISPD3DDMA_disp2_start_addr2_RBUS;


#endif







#endif //_RBUS_DISPD3DDMA_REG_H_

