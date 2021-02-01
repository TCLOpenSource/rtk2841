/**
* @file rbusOD_DMAReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/6/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_OD_DMA_REG_H_
#define _RBUS_OD_DMA_REG_H_

#include "rbusTypes.h"



//  OD_DMA Register Address



#define  OD_DMA_ODDMA_CMP_RESOLUTION_VADDR                  	(0xb802cd00)
#define  OD_DMA_ODDMA_COMP_SETTING_VADDR                    	(0xb802cd04)
#define  OD_DMA_ODDMA_THRESHOLD_VADDR                       	(0xb802cd08)
#define  OD_DMA_ODDMA_COMPRESS_IRQ_EN_VADDR                 	(0xb802cd0c)
#define  OD_DMA_ODDMA_COMPRESS_STATUS_VADDR                 	(0xb802cd10)
#define  OD_DMA_ODDMA_DECMP_RESOLUTION_VADDR                	(0xb802cd14)
#define  OD_DMA_ODDMA_DECOMP_SETTING_VADDR                  	(0xb802cd18)
#define  OD_DMA_ODDMA_TRUNC_MARK_VADDR                      	(0xb802cd1c)
#define  OD_DMA_ODDMA_TRUNC_COLOR_0_VADDR                   	(0xb802cd20)
#define  OD_DMA_ODDMA_TRUNC_COLOR_1_VADDR                   	(0xb802cd24)
#define  OD_DMA_ODDMA_TRUNC_COLOR_2_VADDR                   	(0xb802cd28)
#define  OD_DMA_ODDMA_TRUNC_COLOR_3_VADDR                   	(0xb802cd2c)
#define  OD_DMA_ODDMA_TRUNC_COLOR_4_VADDR                   	(0xb802cd30)
#define  OD_DMA_ODDMA_FRAME_INST_VADDR                      	(0xb802cd34)
#define  OD_DMA_ODDMA_DECOMP_IRQ_EN_VADDR                   	(0xb802cd38)
#define  OD_DMA_ODDMA_DECOMP_STATUS_VADDR                   	(0xb802cd3c)
#define  OD_DMA_ODDMA_DBG_MUX_VADDR                         	(0xb802cd40)
#define  OD_DMA_DECOMP_COMPENSATION_VADDR                   	(0xb802cd44)
#define  OD_DMA_OD_DMA_CTRL4_VADDR                          	(0xb802cdb0)
#define  OD_DMA_ODDMA_LR_SEPARATE_CTRL1_VADDR               	(0xb802cdb4)
#define  OD_DMA_ODDMA_LR_SEPARATE_CTRL2_VADDR               	(0xb802cdb8)
#define  OD_DMA_ODDMA_CAP_CTL0_VADDR                        	(0xb802cdbc)
#define  OD_DMA_ODDMA_CAP_CTL1_VADDR                        	(0xb802cdc0)
#define  OD_DMA_ODDMA_CAP_CTL2_VADDR                        	(0xb802cdc4)
#define  OD_DMA_ODDMA_CAP_BOUNDARYADDR1_VADDR               	(0xb802cdd0)
#define  OD_DMA_ODDMA_CAP_BOUNDARYADDR2_VADDR               	(0xb802cdd4)
#define  OD_DMA_ODDMA_CAP_LINESTEP_VADDR                    	(0xb802cdd8)
#define  OD_DMA_ODDMA_CAP_DEMO_MODE_BLOCKSTEP_VADDR         	(0xb802cddc)
#define  OD_DMA_ODDMA_CAP_L1_START_VADDR                    	(0xb802cde0)
#define  OD_DMA_ODDMA_CAP_L2_START_VADDR                    	(0xb802cde4)
#define  OD_DMA_ODDMA_CAP_L3_START_VADDR                    	(0xb802cde8)
#define  OD_DMA_ODDMA_CAP_L4_START_VADDR                    	(0xb802cdec)
#define  OD_DMA_ODDMA_CAP_L1_START_DB_VADDR                 	(0xb802ce00)
#define  OD_DMA_ODDMA_CAP_STATUS_VADDR                      	(0xb802ce08)
#define  OD_DMA_ODDMA_FRC_CTRL_VADDR                        	(0xb802ce0c)
#define  OD_DMA_ODDMA_CAP_DVS_2_VADDR                       	(0xb802ce1c)
#define  OD_DMA_ODDMA_CAP_DVSE_2_VADDR                      	(0xb802ce20)
#define  OD_DMA_ODDMA_CAP_LS_2_VADDR                        	(0xb802ce24)
#define  OD_DMA_ODDMA_CAP_FAIL_VADDR                        	(0xb802ce28)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_VADDR                    	(0xb802ce2c)
#define  OD_DMA_ODDMA_CRC_CTRL_VADDR                        	(0xb802ce30)
#define  OD_DMA_ODDMA_CRC_MASK_VADDR                        	(0xb802ce34)
#define  OD_DMA_ODDMA_CAP_L_CRC_RESULT_VADDR                	(0xb802ce38)
#define  OD_DMA_ODDMA_CAP_R_CRC_RESULT_VADDR                	(0xb802ce40)
#define  OD_DMA_ODDMA_DISP11_L_CRC_RESULT_VADDR             	(0xb802ce48)
#define  OD_DMA_ODDMA_DISPLAY11_R_CRC_RESULT_VADDR          	(0xb802ce4c)
#define  OD_DMA_ODDMA_DMA_RATE_CTRL_VADDR                   	(0xb802ce68)
#define  OD_DMA_ODDMA_CAPTURE_RATE_VADDR                    	(0xb802ce6c)
#define  OD_DMA_ODDMA_DISPLAY11_RATE_VADDR                  	(0xb802ce70)
#define  OD_DMA_ODDMA_DISPLAY_CTRL_VADDR                    	(0xb802ce80)
#define  OD_DMA_ODDMA_DISPLAY1_PREVSTART_VADDR              	(0xb802ce84)
#define  OD_DMA_ODDMA_DISPLAY11_NUMWTL_VADDR                	(0xb802ce8c)
#define  OD_DMA_ODDMA_DISPLAY11_RDNUMLENREM_VADDR           	(0xb802ce9c)
#define  OD_DMA_ODDMA_DISP11_LINESTEP_VADDR                 	(0xb802ceac)
#define  OD_DMA_ODDMA_DISPLAY11_LINENUM_VADDR               	(0xb802cebc)
#define  OD_DMA_ODDMA_DISPLAY_STATUS1_VADDR                 	(0xb802cecc)
#define  OD_DMA_ODDMA_DISPLAY_STATUS2_VADDR                 	(0xb802ced0)
#define  OD_DMA_ODDMA_DISP11_START_ADDR_L1_VADDR            	(0xb802ced4)
#define  OD_DMA_ODDMA_DISP11_START_ADDR_L2_VADDR            	(0xb802ced8)
#define  OD_DMA_ODDMA_DISP11_START_ADDR_L3_VADDR            	(0xb802cedc)
#define  OD_DMA_ODDMA_DISP11_START_ADDR_L4_VADDR            	(0xb802cee0)
#define  OD_DMA_ODDMA_INTERRUPT_ENABLE_VADDR                	(0xb802cf54)
#define  OD_DMA_ODDMA_COMP_DECOMP_CLK_GATED_VADDR           	(0xb802cf58)
#define  OD_DMA_DFRC_DEBUG_VADDR                            	(0xb802cf5c)
#define  OD_DMA_ODDMA_BYTE_CHANNEL_SWAP_VADDR               	(0xb802cf60)
#define  OD_DMA_ODDMA_DISP_DVS_VADDR                        	(0xb802cfe0)
#define  OD_DMA_ODDMA_DISP_DVSE_VADDR                       	(0xb802cfe4)
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_VADDR                  	(0xb802cfe8)
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_VADDR                   	(0xb802cfec)
#define  OD_DMA_ODDMA_DISP_LS_VADDR                         	(0xb802cff0)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======OD_DMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  cmp_segment:2;
        RBus_UInt32  cmp_width:8;
        RBus_UInt32  cmp_height:16;
    };
}od_dma_oddma_cmp_resolution_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_a_ch_mark:1;
        RBus_UInt32  cmp_444to422_en:1;
        RBus_UInt32  cmp_rgb_yc_sel:1;
        RBus_UInt32  cmp_channel_bits:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  max_pixel_bits:6;
        RBus_UInt32  short_term_bits:6;
        RBus_UInt32  frame_bits:6;
    };
}od_dma_oddma_comp_setting_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  delta_down:8;
        RBus_UInt32  delta_up:8;
    };
}od_dma_oddma_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  not_segement_status_clr:1;
        RBus_UInt32  pixel_num_status_clr:1;
        RBus_UInt32  over_bits_status_clr:1;
        RBus_UInt32  comp_irq_en:3;
    };
}od_dma_oddma_compress_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  comp_irq:1;
        RBus_UInt32  comp_status:3;
    };
}od_dma_oddma_compress_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  decmp_segment:2;
        RBus_UInt32  decmp_width:8;
        RBus_UInt32  decmp_height:16;
    };
}od_dma_oddma_decmp_resolution_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  a_sat_en:1;
        RBus_UInt32  b_cb_sat_en:1;
        RBus_UInt32  g_y_sat_en:1;
        RBus_UInt32  r_cr_sat_en:1;
        RBus_UInt32  decmp_frame_bits:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  decmp_a_ch_mark:1;
        RBus_UInt32  decmp_444to422_en:1;
        RBus_UInt32  decmp_rgb_yc_sel:1;
        RBus_UInt32  decmp_channel_bits:1;
        RBus_UInt32  decmp_cbcr_recov:1;
        RBus_UInt32  decmp_fl_mode:1;
    };
}od_dma_oddma_decomp_setting_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  mark_en_9:1;
        RBus_UInt32  mark_en_8:1;
        RBus_UInt32  mark_en_7:1;
        RBus_UInt32  mark_en_6:1;
        RBus_UInt32  mark_en_5:1;
        RBus_UInt32  mark_en_4:1;
        RBus_UInt32  mark_en_3:1;
        RBus_UInt32  mark_en_2:1;
        RBus_UInt32  mark_en_1:1;
        RBus_UInt32  mark_en_0:1;
    };
}od_dma_oddma_trunc_mark_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_0:16;
        RBus_UInt32  mark_color_1:16;
    };
}od_dma_oddma_trunc_color_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_2:16;
        RBus_UInt32  mark_color_3:16;
    };
}od_dma_oddma_trunc_color_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_4:16;
        RBus_UInt32  mark_color_5:16;
    };
}od_dma_oddma_trunc_color_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_6:16;
        RBus_UInt32  mark_color_7:16;
    };
}od_dma_oddma_trunc_color_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_8:16;
        RBus_UInt32  mark_color_9:16;
    };
}od_dma_oddma_trunc_color_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  frm_cnt_0:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  max_truncation_0:4;
    };
}od_dma_oddma_frame_inst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802cd38_31_10:22;
        RBus_UInt32  head_error_clr:1;
        RBus_UInt32  pix_fifo_underflow_clr:1;
        RBus_UInt32  head_error_irq_en:4;
        RBus_UInt32  underflow_irq_en:4;
    };
}od_dma_oddma_decomp_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802cd3c_31_9:23;
        RBus_UInt32  decomp_irq:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  head_error:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  pix_fifo_underflow:1;
    };
}od_dma_oddma_decomp_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802cd40_31_16:16;
        RBus_UInt32  decomp_debug_mux:8;
        RBus_UInt32  comp_debug_mux:8;
    };
}od_dma_oddma_dbg_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  tr_en:1;
    };
}od_dma_decomp_compensation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  smooth_tog_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  disp_db_apply:1;
        RBus_UInt32  disp_db_rd_sel:1;
        RBus_UInt32  disp_db_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  cap_db_apply:1;
        RBus_UInt32  cap_db_rd_sel:1;
        RBus_UInt32  cap_db_en:1;
    };
}od_dma_od_dma_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  vs_inv:1;
        RBus_UInt32  hs_inv:1;
        RBus_UInt32  lr_separate_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hdmi_3d_structure:4;
        RBus_UInt32  fp_vact_space1:8;
        RBus_UInt32  res3:8;
    };
}od_dma_oddma_lr_separate_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact:16;
        RBus_UInt32  res1:1;
        RBus_UInt32  hact:15;
    };
}od_dma_oddma_lr_separate_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  triple_buf_en:1;
        RBus_UInt32  cap_block_fw:2;
        RBus_UInt32  set_block_sel:1;
        RBus_UInt32  quad_buf_en:1;
        RBus_UInt32  dispi_wd_freeze_en:1;
        RBus_UInt32  comp_de_comp_bypass:1;
        RBus_UInt32  freeze_en:1;
        RBus_UInt32  vs_fall_rst_en:1;
        RBus_UInt32  auto_block_sel_en:1;
        RBus_UInt32  half_wr_en:1;
        RBus_UInt32  half_wr_sel:1;
        RBus_UInt32  cap_en:1;
        RBus_UInt32  res1:19;
    };
}od_dma_oddma_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  bit_sel:2;
        RBus_UInt32  pixel_encoding:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cap_write_len:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  cap_write_rem:7;
    };
}od_dma_oddma_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  cap_water_lv:9;
        RBus_UInt32  cap_write_num:16;
    };
}od_dma_oddma_cap_ctl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_mem_up_limit:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_mem_low_limit:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_line_step:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_dm_step:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_demo_mode_blockstep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l1_start:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l2_start:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l3_start:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_l3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l4_start:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_l4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l1_start_db:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_l1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  cap_over_size:1;
        RBus_UInt32  cap_under_size:1;
        RBus_UInt32  freeze_ok:1;
        RBus_UInt32  vs_rising_occur:1;
        RBus_UInt32  cap_block:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_ddr_over_range:1;
    };
}od_dma_oddma_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  disp_frc_llrr_mode:1;
        RBus_UInt32  disp_frc_llrr_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  frc_style:1;
        RBus_UInt32  frc_en:1;
    };
}od_dma_oddma_frc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oddma_comp_seg_dvs:4;
        RBus_UInt32  cap_dvs:4;
    };
}od_dma_oddma_cap_dvs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  oddma_comp_seg_dvse:1;
        RBus_UInt32  cap_dvse:1;
    };
}od_dma_oddma_cap_dvse_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  oddma_comp_seg_ls:1;
        RBus_UInt32  cap_ls:1;
    };
}od_dma_oddma_cap_ls_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  cap_bist_fail:1;
    };
}od_dma_oddma_cap_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  cap_drf_fail:1;
    };
}od_dma_oddma_cap_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  match_buffer:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  crc_comp_error_int:1;
        RBus_UInt32  dynamic_crc_cmp_en:1;
        RBus_UInt32  crc_comp_error_flag:1;
        RBus_UInt32  crc_bit_sel:3;
        RBus_UInt32  crc_pixel_encoding:1;
        RBus_UInt32  res3:13;
        RBus_UInt32  disp11_crc_3d_en:1;
        RBus_UInt32  disp11_crc_conti:1;
        RBus_UInt32  disp11_crc_start:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  cap_crc_3d_en:1;
        RBus_UInt32  cap_crc_conti:1;
        RBus_UInt32  cap_crc_start:1;
    };
}od_dma_oddma_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  crc_mask:30;
    };
}od_dma_oddma_crc_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l_crc_result:32;
    };
}od_dma_oddma_cap_l_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r_crc_result:32;
    };
}od_dma_oddma_cap_r_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_l_crc_result:32;
    };
}od_dma_oddma_disp11_l_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_r_crc_result:32;
    };
}od_dma_oddma_display11_r_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  disp11_rate_en:1;
        RBus_UInt32  cap_rate_en:1;
    };
}od_dma_oddma_dma_rate_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_rate:32;
    };
}od_dma_oddma_capture_rate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_rate:32;
    };
}od_dma_oddma_display11_rate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  l_flag_hs_dly:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  disp11_vs_fall_rst_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  disp11_3ddma_en:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  stop_burst_en:1;
        RBus_UInt32  l_flag_inv:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:2;
    };
}od_dma_oddma_display_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  disp11_pre_rd_v_start:11;
    };
}od_dma_oddma_display1_prevstart_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  disp11_pixel_num:13;
        RBus_UInt32  res2:7;
        RBus_UInt32  disp11_wtlvl:9;
    };
}od_dma_oddma_display11_numwtl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_read_num:16;
        RBus_UInt32  res1:1;
        RBus_UInt32  disp11_read_len:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  disp11_read_remain:7;
    };
}od_dma_oddma_display11_rdnumlenrem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_line_step:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_disp11_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  disp11_line_number:13;
    };
}od_dma_oddma_display11_linenum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  disp11_clr_over_range:1;
        RBus_UInt32  disp11_fifo_clr:1;
        RBus_UInt32  disp11_fifo_full:1;
        RBus_UInt32  disp11_fifo_empty:1;
        RBus_UInt32  disp11_fifo_overflow:1;
        RBus_UInt32  disp11_fifo_underflow:1;
        RBus_UInt32  disp11_adr_down_over_range:1;
        RBus_UInt32  disp11_adr_up_over_range:1;
    };
}od_dma_oddma_display_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  disp_repeat_flag:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  disp1_read_block:2;
        RBus_UInt32  disp1_read_l_flag:1;
    };
}od_dma_oddma_display_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_start_addr_l1:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_disp11_start_addr_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_start_addr_l2:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_disp11_start_addr_l2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_start_addr_l3:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_disp11_start_addr_l3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_start_addr_l4:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_disp11_start_addr_l4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  disp11_mem_err_ie:1;
        RBus_UInt32  disp11_fifo_err_ie:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  cap_mem_err_ie:1;
        RBus_UInt32  cap_fifo_err_ie:1;
        RBus_UInt32  vs_rising_ie:1;
    };
}od_dma_oddma_interrupt_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  comp_decomp_clk_en:1;
    };
}od_dma_oddma_comp_decomp_clk_gated_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  dispm_debug_sel:4;
    };
}od_dma_dfrc_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  disp_channel_swap:3;
        RBus_UInt32  disp_8byte_swap:1;
        RBus_UInt32  disp_4byte_swap:1;
        RBus_UInt32  disp_2byte_swap:1;
        RBus_UInt32  disp_1byte_swap:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  cap_channel_swap:3;
        RBus_UInt32  cap_8byte_swap:1;
        RBus_UInt32  cap_4byte_swap:1;
        RBus_UInt32  cap_2byte_swap:1;
        RBus_UInt32  cap_1byte_swap:1;
    };
}od_dma_oddma_byte_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  oddma_decomp11_dvs:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  disp11_dvs:4;
    };
}od_dma_oddma_disp_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  oddma_decomp11_dvse:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  disp11_dvse:1;
    };
}od_dma_oddma_disp_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  oddma_decomp_bist_fail_0:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  disp_bist_fail_0:1;
    };
}od_dma_oddma_disp_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  oddma_decomp_drf_fail_0:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  disp_drf_fail_0:1;
    };
}od_dma_oddma_disp_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  decomp11_ls:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  disp11_ls:1;
    };
}od_dma_oddma_disp_ls_RBUS;

#else //apply LITTLE_ENDIAN

//======OD_DMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_height:16;
        RBus_UInt32  cmp_width:8;
        RBus_UInt32  cmp_segment:2;
        RBus_UInt32  res1:6;
    };
}od_dma_oddma_cmp_resolution_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_bits:6;
        RBus_UInt32  short_term_bits:6;
        RBus_UInt32  max_pixel_bits:6;
        RBus_UInt32  res1:10;
        RBus_UInt32  cmp_channel_bits:1;
        RBus_UInt32  cmp_rgb_yc_sel:1;
        RBus_UInt32  cmp_444to422_en:1;
        RBus_UInt32  cmp_a_ch_mark:1;
    };
}od_dma_oddma_comp_setting_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delta_up:8;
        RBus_UInt32  delta_down:8;
        RBus_UInt32  res1:16;
    };
}od_dma_oddma_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_irq_en:3;
        RBus_UInt32  over_bits_status_clr:1;
        RBus_UInt32  pixel_num_status_clr:1;
        RBus_UInt32  not_segement_status_clr:1;
        RBus_UInt32  res1:26;
    };
}od_dma_oddma_compress_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_status:3;
        RBus_UInt32  comp_irq:1;
        RBus_UInt32  res1:28;
    };
}od_dma_oddma_compress_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_height:16;
        RBus_UInt32  decmp_width:8;
        RBus_UInt32  decmp_segment:2;
        RBus_UInt32  res1:6;
    };
}od_dma_oddma_decmp_resolution_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_fl_mode:1;
        RBus_UInt32  decmp_cbcr_recov:1;
        RBus_UInt32  decmp_channel_bits:1;
        RBus_UInt32  decmp_rgb_yc_sel:1;
        RBus_UInt32  decmp_444to422_en:1;
        RBus_UInt32  decmp_a_ch_mark:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  decmp_frame_bits:6;
        RBus_UInt32  r_cr_sat_en:1;
        RBus_UInt32  g_y_sat_en:1;
        RBus_UInt32  b_cb_sat_en:1;
        RBus_UInt32  a_sat_en:1;
        RBus_UInt32  res2:14;
    };
}od_dma_oddma_decomp_setting_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_en_0:1;
        RBus_UInt32  mark_en_1:1;
        RBus_UInt32  mark_en_2:1;
        RBus_UInt32  mark_en_3:1;
        RBus_UInt32  mark_en_4:1;
        RBus_UInt32  mark_en_5:1;
        RBus_UInt32  mark_en_6:1;
        RBus_UInt32  mark_en_7:1;
        RBus_UInt32  mark_en_8:1;
        RBus_UInt32  mark_en_9:1;
        RBus_UInt32  res1:22;
    };
}od_dma_oddma_trunc_mark_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_1:16;
        RBus_UInt32  mark_color_0:16;
    };
}od_dma_oddma_trunc_color_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_3:16;
        RBus_UInt32  mark_color_2:16;
    };
}od_dma_oddma_trunc_color_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_5:16;
        RBus_UInt32  mark_color_4:16;
    };
}od_dma_oddma_trunc_color_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_7:16;
        RBus_UInt32  mark_color_6:16;
    };
}od_dma_oddma_trunc_color_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_9:16;
        RBus_UInt32  mark_color_8:16;
    };
}od_dma_oddma_trunc_color_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_truncation_0:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  frm_cnt_0:4;
        RBus_UInt32  res2:12;
    };
}od_dma_oddma_frame_inst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  underflow_irq_en:4;
        RBus_UInt32  head_error_irq_en:4;
        RBus_UInt32  pix_fifo_underflow_clr:1;
        RBus_UInt32  head_error_clr:1;
        RBus_UInt32  dummy1802cd38_31_10:22;
    };
}od_dma_oddma_decomp_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pix_fifo_underflow:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  head_error:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  decomp_irq:1;
        RBus_UInt32  dummy1802cd3c_31:23;
    };
}od_dma_oddma_decomp_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_debug_mux:8;
        RBus_UInt32  decomp_debug_mux:8;
        RBus_UInt32  dummy1802cd40_31_16:16;
    };
}od_dma_oddma_dbg_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tr_en:1;
        RBus_UInt32  res1:31;
    };
}od_dma_decomp_compensation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_db_en:1;
        RBus_UInt32  cap_db_rd_sel:1;
        RBus_UInt32  cap_db_apply:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  disp_db_en:1;
        RBus_UInt32  disp_db_rd_sel:1;
        RBus_UInt32  disp_db_apply:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  smooth_tog_en:1;
        RBus_UInt32  res3:23;
    };
}od_dma_od_dma_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  fp_vact_space1:8;
        RBus_UInt32  hdmi_3d_structure:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  lr_separate_en:1;
        RBus_UInt32  hs_inv:1;
        RBus_UInt32  vs_inv:1;
        RBus_UInt32  res3:8;
    };
}od_dma_oddma_lr_separate_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hact:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  vact:16;
    };
}od_dma_oddma_lr_separate_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  cap_en:1;
        RBus_UInt32  half_wr_sel:1;
        RBus_UInt32  half_wr_en:1;
        RBus_UInt32  auto_block_sel_en:1;
        RBus_UInt32  vs_fall_rst_en:1;
        RBus_UInt32  freeze_en:1;
        RBus_UInt32  comp_de_comp_bypass:1;
        RBus_UInt32  dispi_wd_freeze_en:1;
        RBus_UInt32  quad_buf_en:1;
        RBus_UInt32  set_block_sel:1;
        RBus_UInt32  cap_block_fw:2;
        RBus_UInt32  triple_buf_en:1;
    };
}od_dma_oddma_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_rem:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_write_len:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pixel_encoding:1;
        RBus_UInt32  bit_sel:2;
        RBus_UInt32  res3:13;
    };
}od_dma_oddma_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_num:16;
        RBus_UInt32  cap_water_lv:9;
        RBus_UInt32  res1:7;
    };
}od_dma_oddma_cap_ctl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_mem_up_limit:29;
    };
}od_dma_oddma_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_mem_low_limit:29;
    };
}od_dma_oddma_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_line_step:29;
    };
}od_dma_oddma_cap_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_dm_step:29;
    };
}od_dma_oddma_cap_demo_mode_blockstep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l1_start:29;
    };
}od_dma_oddma_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l2_start:29;
    };
}od_dma_oddma_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l3_start:29;
    };
}od_dma_oddma_cap_l3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l4_start:29;
    };
}od_dma_oddma_cap_l4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l1_start_db:29;
    };
}od_dma_oddma_cap_l1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_ddr_over_range:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_block:2;
        RBus_UInt32  vs_rising_occur:1;
        RBus_UInt32  freeze_ok:1;
        RBus_UInt32  cap_under_size:1;
        RBus_UInt32  cap_over_size:1;
        RBus_UInt32  res2:20;
    };
}od_dma_oddma_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frc_en:1;
        RBus_UInt32  frc_style:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  disp_frc_llrr_en:1;
        RBus_UInt32  disp_frc_llrr_mode:1;
        RBus_UInt32  res2:27;
    };
}od_dma_oddma_frc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_dvs:4;
        RBus_UInt32  oddma_comp_seg_dvs:4;
        RBus_UInt32  res1:24;
    };
}od_dma_oddma_cap_dvs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_dvse:1;
        RBus_UInt32  oddma_comp_seg_dvse:1;
        RBus_UInt32  res1:30;
    };
}od_dma_oddma_cap_dvse_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_ls:1;
        RBus_UInt32  oddma_comp_seg_ls:1;
        RBus_UInt32  res1:30;
    };
}od_dma_oddma_cap_ls_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_bist_fail:1;
        RBus_UInt32  res1:31;
    };
}od_dma_oddma_cap_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_drf_fail:1;
        RBus_UInt32  res1:31;
    };
}od_dma_oddma_cap_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_crc_start:1;
        RBus_UInt32  cap_crc_conti:1;
        RBus_UInt32  cap_crc_3d_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  disp11_crc_start:1;
        RBus_UInt32  disp11_crc_conti:1;
        RBus_UInt32  disp11_crc_3d_en:1;
        RBus_UInt32  res2:13;
        RBus_UInt32  crc_pixel_encoding:1;
        RBus_UInt32  crc_bit_sel:3;
        RBus_UInt32  crc_comp_error_flag:1;
        RBus_UInt32  dynamic_crc_cmp_en:1;
        RBus_UInt32  crc_comp_error_int:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  match_buffer:2;
        RBus_UInt32  res4:2;
    };
}od_dma_oddma_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_mask:30;
        RBus_UInt32  res1:2;
    };
}od_dma_oddma_crc_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l_crc_result:32;
    };
}od_dma_oddma_cap_l_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r_crc_result:32;
    };
}od_dma_oddma_cap_r_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_l_crc_result:32;
    };
}od_dma_oddma_disp11_l_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_r_crc_result:32;
    };
}od_dma_oddma_display11_r_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_rate_en:1;
        RBus_UInt32  disp11_rate_en:1;
        RBus_UInt32  res1:30;
    };
}od_dma_oddma_dma_rate_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_rate:32;
    };
}od_dma_oddma_capture_rate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_rate:32;
    };
}od_dma_oddma_display11_rate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  l_flag_inv:1;
        RBus_UInt32  stop_burst_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  disp11_3ddma_en:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  disp11_vs_fall_rst_en:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  l_flag_hs_dly:12;
        RBus_UInt32  res6:4;
    };
}od_dma_oddma_display_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_pre_rd_v_start:11;
        RBus_UInt32  res1:21;
    };
}od_dma_oddma_display1_prevstart_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_wtlvl:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  disp11_pixel_num:13;
        RBus_UInt32  res2:3;
    };
}od_dma_oddma_display11_numwtl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_read_remain:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  disp11_read_len:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  disp11_read_num:16;
    };
}od_dma_oddma_display11_rdnumlenrem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  disp11_line_step:29;
    };
}od_dma_oddma_disp11_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_line_number:13;
        RBus_UInt32  res1:19;
    };
}od_dma_oddma_display11_linenum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_adr_up_over_range:1;
        RBus_UInt32  disp11_adr_down_over_range:1;
        RBus_UInt32  disp11_fifo_underflow:1;
        RBus_UInt32  disp11_fifo_overflow:1;
        RBus_UInt32  disp11_fifo_empty:1;
        RBus_UInt32  disp11_fifo_full:1;
        RBus_UInt32  disp11_fifo_clr:1;
        RBus_UInt32  disp11_clr_over_range:1;
        RBus_UInt32  res1:24;
    };
}od_dma_oddma_display_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp1_read_l_flag:1;
        RBus_UInt32  disp1_read_block:2;
        RBus_UInt32  res1:5;
        RBus_UInt32  disp_repeat_flag:1;
        RBus_UInt32  res2:23;
    };
}od_dma_oddma_display_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  disp11_start_addr_l1:29;
    };
}od_dma_oddma_disp11_start_addr_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  disp11_start_addr_l2:29;
    };
}od_dma_oddma_disp11_start_addr_l2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  disp11_start_addr_l3:29;
    };
}od_dma_oddma_disp11_start_addr_l3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  disp11_start_addr_l4:29;
    };
}od_dma_oddma_disp11_start_addr_l4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vs_rising_ie:1;
        RBus_UInt32  cap_fifo_err_ie:1;
        RBus_UInt32  cap_mem_err_ie:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  disp11_fifo_err_ie:1;
        RBus_UInt32  disp11_mem_err_ie:1;
        RBus_UInt32  res2:22;
    };
}od_dma_oddma_interrupt_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_decomp_clk_en:1;
        RBus_UInt32  res1:31;
    };
}od_dma_oddma_comp_decomp_clk_gated_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dispm_debug_sel:4;
        RBus_UInt32  res1:28;
    };
}od_dma_dfrc_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_1byte_swap:1;
        RBus_UInt32  cap_2byte_swap:1;
        RBus_UInt32  cap_4byte_swap:1;
        RBus_UInt32  cap_8byte_swap:1;
        RBus_UInt32  cap_channel_swap:3;
        RBus_UInt32  res1:9;
        RBus_UInt32  disp_1byte_swap:1;
        RBus_UInt32  disp_2byte_swap:1;
        RBus_UInt32  disp_4byte_swap:1;
        RBus_UInt32  disp_8byte_swap:1;
        RBus_UInt32  disp_channel_swap:3;
        RBus_UInt32  res2:9;
    };
}od_dma_oddma_byte_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_dvs:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  oddma_decomp11_dvs:4;
        RBus_UInt32  res2:12;
    };
}od_dma_oddma_disp_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_dvse:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  oddma_decomp11_dvse:1;
        RBus_UInt32  res2:27;
    };
}od_dma_oddma_disp_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_bist_fail_0:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  oddma_decomp_bist_fail_0:1;
        RBus_UInt32  res2:27;
    };
}od_dma_oddma_disp_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_drf_fail_0:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  oddma_decomp_drf_fail_0:1;
        RBus_UInt32  res2:27;
    };
}od_dma_oddma_disp_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp11_ls:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  decomp11_ls:1;
        RBus_UInt32  res2:27;
    };
}od_dma_oddma_disp_ls_RBUS;




#endif 


#endif 
