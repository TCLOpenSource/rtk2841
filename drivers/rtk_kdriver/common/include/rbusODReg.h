/**
* @file rbusODReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/6/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_OD_REG_H_
#define _RBUS_OD_REG_H_

#include "rbusTypes.h"



//  OD Register Address



#define  OD_OD_CTRL_VADDR                                   	(0xb802ca00)
#define  OD_OD_CTRL1_VADDR                                  	(0xb802ca04)
#define  OD_OD_LUT_ADDR_VADDR                               	(0xb802ca08)
#define  OD_OD_LUT_DATA_VADDR                               	(0xb802ca0c)
#define  OD_REGIONAL_OD_CTRL1_VADDR                         	(0xb802ca10)
#define  OD_REGIONAL_OD_CTRL2_VADDR                         	(0xb802ca14)
#define  OD_REGIONAL_OD_CTRL3_VADDR                         	(0xb802ca18)
#define  OD_REGIONAL_OD_CTRL4_VADDR                         	(0xb802ca1c)
#define  OD_REGIONAL_OD_CTRL5_VADDR                         	(0xb802ca20)
#define  OD_OD_NOISE_REDUCTION_CTRL_VADDR                   	(0xb802ca30)
#define  OD_FRAME_RPT_CTL_VADDR                             	(0xb802ca38)
#define  OD_TABLE_MOVE_DMA_ADDR1_VADDR                      	(0xb802ca40)
#define  OD_TABLE_MOVE_DMA_ADDR2_VADDR                      	(0xb802ca44)
#define  OD_TABLE_MOVE_DMA_ADDR3_VADDR                      	(0xb802ca48)
#define  OD_TABLE_MOVE_DMA_ADDR4_VADDR                      	(0xb802ca4c)
#define  OD_TABLE_MOVE_DMA_ADDR5_VADDR                      	(0xb802ca50)
#define  OD_TABLE_MOVE_DMA_ADDR6_VADDR                      	(0xb802ca54)
#define  OD_TABLE_MOVE_DMA_ADDR1_DELTA_VADDR                	(0xb802ca58)
#define  OD_TABLE_MOVE_DMA_ADDR2_DELTA_VADDR                	(0xb802ca5c)
#define  OD_TABLE_MOVE_DMA_ADDR3_DELTA_VADDR                	(0xb802ca60)
#define  OD_TABLE_MOVE_DMA_ADDR4_DELTA_VADDR                	(0xb802ca64)
#define  OD_TABLE_MOVE_DMA_ADDR5_DELTA_VADDR                	(0xb802ca68)
#define  OD_TABLE_MOVE_DMA_ADDR6_DELTA_VADDR                	(0xb802ca6c)
#define  OD_TABLE_MOVE_DMA_CTL_VADDR                        	(0xb802ca70)
#define  OD_TABLE_MOVE_DMA_STATUS_VADDR                     	(0xb802ca74)
#define  OD_CUR_R_TAB_IDX_1_VADDR                           	(0xb802ca80)
#define  OD_CUR_R_TAB_IDX_2_VADDR                           	(0xb802ca84)
#define  OD_CUR_R_TAB_IDX_3_VADDR                           	(0xb802ca88)
#define  OD_CUR_R_TAB_IDX_4_VADDR                           	(0xb802ca8c)
#define  OD_CUR_R_TAB_IDX_5_VADDR                           	(0xb802ca90)
#define  OD_CUR_R_TAB_IDX_6_VADDR                           	(0xb802ca94)
#define  OD_CUR_R_TAB_IDX_7_VADDR                           	(0xb802ca98)
#define  OD_CUR_R_TAB_IDX_8_VADDR                           	(0xb802ca9c)
#define  OD_PRE_R_TAB_IDX_1_VADDR                           	(0xb802caa0)
#define  OD_PRE_R_TAB_IDX_2_VADDR                           	(0xb802caa4)
#define  OD_PRE_R_TAB_IDX_3_VADDR                           	(0xb802caa8)
#define  OD_PRE_R_TAB_IDX_4_VADDR                           	(0xb802caac)
#define  OD_PRE_R_TAB_IDX_5_VADDR                           	(0xb802cab0)
#define  OD_PRE_R_TAB_IDX_6_VADDR                           	(0xb802cab4)
#define  OD_PRE_R_TAB_IDX_7_VADDR                           	(0xb802cab8)
#define  OD_PRE_R_TAB_IDX_8_VADDR                           	(0xb802cabc)
#define  OD_CUR_G_TAB_IDX_1_VADDR                           	(0xb802cac0)
#define  OD_CUR_G_TAB_IDX_2_VADDR                           	(0xb802cac4)
#define  OD_CUR_G_TAB_IDX_3_VADDR                           	(0xb802cac8)
#define  OD_CUR_G_TAB_IDX_4_VADDR                           	(0xb802cacc)
#define  OD_CUR_G_TAB_IDX_5_VADDR                           	(0xb802cad0)
#define  OD_CUR_G_TAB_IDX_6_VADDR                           	(0xb802cad4)
#define  OD_CUR_G_TAB_IDX_7_VADDR                           	(0xb802cad8)
#define  OD_CUR_G_TAB_IDX_8_VADDR                           	(0xb802cadc)
#define  OD_PRE_G_TAB_IDX_1_VADDR                           	(0xb802cae0)
#define  OD_PRE_G_TAB_IDX_2_VADDR                           	(0xb802cae4)
#define  OD_PRE_G_TAB_IDX_3_VADDR                           	(0xb802cae8)
#define  OD_PRE_G_TAB_IDX_4_VADDR                           	(0xb802caec)
#define  OD_PRE_G_TAB_IDX_5_VADDR                           	(0xb802caf0)
#define  OD_PRE_G_TAB_IDX_6_VADDR                           	(0xb802caf4)
#define  OD_PRE_G_TAB_IDX_7_VADDR                           	(0xb802caf8)
#define  OD_PRE_G_TAB_IDX_8_VADDR                           	(0xb802cafc)
#define  OD_CUR_B_TAB_IDX_1_VADDR                           	(0xb802cb00)
#define  OD_CUR_B_TAB_IDX_2_VADDR                           	(0xb802cb04)
#define  OD_CUR_B_TAB_IDX_3_VADDR                           	(0xb802cb08)
#define  OD_CUR_B_TAB_IDX_4_VADDR                           	(0xb802cb0c)
#define  OD_CUR_B_TAB_IDX_5_VADDR                           	(0xb802cb10)
#define  OD_CUR_B_TAB_IDX_6_VADDR                           	(0xb802cb14)
#define  OD_CUR_B_TAB_IDX_7_VADDR                           	(0xb802cb18)
#define  OD_CUR_B_TAB_IDX_8_VADDR                           	(0xb802cb1c)
#define  OD_PRE_B_TAB_IDX_1_VADDR                           	(0xb802cb20)
#define  OD_PRE_B_TAB_IDX_2_VADDR                           	(0xb802cb24)
#define  OD_PRE_B_TAB_IDX_3_VADDR                           	(0xb802cb28)
#define  OD_PRE_B_TAB_IDX_4_VADDR                           	(0xb802cb2c)
#define  OD_PRE_B_TAB_IDX_5_VADDR                           	(0xb802cb30)
#define  OD_PRE_B_TAB_IDX_6_VADDR                           	(0xb802cb34)
#define  OD_PRE_B_TAB_IDX_7_VADDR                           	(0xb802cb38)
#define  OD_PRE_B_TAB_IDX_8_VADDR                           	(0xb802cb3c)
#define  OD_NONLINEAR_CTL_VADDR                             	(0xb802cb40)
#define  OD_D_CRC_CTRL1_VADDR                               	(0xb802cb44)
#define  OD_CRC_RESULT1_VADDR                               	(0xb802cb48)
#define  OD_ACCESSDATA_CTRL_PC_VADDR                        	(0xb802cb54)
#define  OD_ACCESSDATA_POSCTRL_PC_VADDR                     	(0xb802cb58)
#define  OD_WRITEDATA_DATA_PC_VADDR                         	(0xb802cb5c)
#define  OD_WRITEDATA_DATA_1_PC_VADDR                       	(0xb802cb60)
#define  OD_WRITEDATA_DATA_2_PC_VADDR                       	(0xb802cb64)
#define  OD_WRITEDATA_DATA_3_PC_VADDR                       	(0xb802cb68)
#define  OD_WRITEDATA_DATA_4_PC_VADDR                       	(0xb802cb6c)
#define  OD_WRITEDATA_DATA_5_PC_VADDR                       	(0xb802cb70)
#define  OD_WRITEDATA_DATA_6_PC_VADDR                       	(0xb802cb74)
#define  OD_WRITEDATA_DATA_7_PC_VADDR                       	(0xb802cb78)
#define  OD_READDATA_DATA_Y1_PC_VADDR                       	(0xb802cb94)
#define  OD_READDATA_DATA_Y2_PC_VADDR                       	(0xb802cb98)
#define  OD_READDATA_DATA_C1_PC_VADDR                       	(0xb802cb9c)
#define  OD_READDATA_DATA_C2_PC_VADDR                       	(0xb802cba0)
#define  OD_READDATA_DATA_C3_PC_VADDR                       	(0xb802cba4)
#define  OD_READDATA_DATA_C4_PC_VADDR                       	(0xb802cba8)
#define  OD_OD_BIST_VADDR                                   	(0xb802cbb0)
#define  OD_OD_BIST_1_VADDR                                 	(0xb802cbb4)
#define  OD_OD_BIST_2_VADDR                                 	(0xb802cbb8)
#define  OD_PCID_CTRL_VADDR                                 	(0xb802cbc0)
#define  OD_PCID_CTRL_1_VADDR                               	(0xb802cbc4)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======OD register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  od_fun_sel:1;
        RBus_UInt32  od_en:1;
    };
}od_od_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  od_en_dbf_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  gibi_en:1;
        RBus_UInt32  od_freeze:1;
        RBus_UInt32  force_pre_out:1;
        RBus_UInt32  compress_ctrl:1;
        RBus_UInt32  ori_cur_sel:1;
        RBus_UInt32  od_cur_src_sel:1;
        RBus_UInt32  rounding_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  od_delta_gain:7;
        RBus_UInt32  res4:2;
        RBus_UInt32  od_disp_res:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  od_pdest_en:2;
    };
}od_od_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  table_type:1;
        RBus_UInt32  od_lut_index:1;
        RBus_UInt32  od_lut_ax_en:1;
        RBus_UInt32  od_lut_ax_mode:1;
        RBus_UInt32  od_lut_adr_mode:1;
        RBus_UInt32  od_lut_sel:2;
        RBus_UInt32  od_lut_row_addr:6;
        RBus_UInt32  od_lut_column_addr:6;
    };
}od_od_lut_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_lut_data:32;
    };
}od_od_lut_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  regional_od_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  od_region_1_step_ratio:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  od_region_1_step:7;
        RBus_UInt32  res4:4;
        RBus_UInt32  od_region_1_toplinenumber:12;
    };
}od_regional_od_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  od_region_2_step_ratio:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  od_region_2_step:7;
        RBus_UInt32  res3:4;
        RBus_UInt32  od_region_2_toplinenumber:12;
    };
}od_regional_od_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  od_region_3_step_ratio:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  od_region_3_step:7;
        RBus_UInt32  res3:4;
        RBus_UInt32  od_region_3_toplinenumber:12;
    };
}od_regional_od_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  od_region_4_step_ratio:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  od_region_4_step:7;
        RBus_UInt32  res3:4;
        RBus_UInt32  od_region_4_toplinenumber:12;
    };
}od_regional_od_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  od_region_5_step_ratio:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  od_region_5_step:7;
        RBus_UInt32  res3:4;
        RBus_UInt32  od_region_5_toplinenumber:12;
    };
}od_regional_od_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  od_nr_mode:1;
        RBus_UInt32  od_b_nr_en:1;
        RBus_UInt32  od_g_nr_en:1;
        RBus_UInt32  od_r_nr_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  od_b_nr_thd:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  od_g_nr_thd:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  od_r_nr_thd:6;
    };
}od_od_noise_reduction_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  repeat_frame_od_mode:2;
    };
}od_frame_rpt_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ddr_read_address_1:28;
    };
}od_table_move_dma_addr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ddr_read_address_2:28;
    };
}od_table_move_dma_addr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ddr_read_address_3:28;
    };
}od_table_move_dma_addr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ddr_read_address_4:28;
    };
}od_table_move_dma_addr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ddr_read_address_5:28;
    };
}od_table_move_dma_addr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ddr_read_address_6:28;
    };
}od_table_move_dma_addr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ddr_read_address_delta_1:28;
    };
}od_table_move_dma_addr1_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ddr_read_address_delta_2:28;
    };
}od_table_move_dma_addr2_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ddr_read_address_delta_3:28;
    };
}od_table_move_dma_addr3_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ddr_read_address_delta_4:28;
    };
}od_table_move_dma_addr4_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ddr_read_address_delta_5:28;
    };
}od_table_move_dma_addr5_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ddr_read_address_delta_6:28;
    };
}od_table_move_dma_addr6_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tab_move_en:1;
        RBus_UInt32  table_src_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  reload_tab2:1;
        RBus_UInt32  reload_tab1:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  table_request_wait_cnt:10;
        RBus_UInt32  table_burst_length:3;
    };
}od_table_move_dma_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  reload_err_flag:1;
        RBus_UInt32  dma_not_ready_flag:1;
    };
}od_table_move_dma_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_r_tab_1:6;
    };
}od_cur_r_tab_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_8:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_r_tab_5:6;
    };
}od_cur_r_tab_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_12:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_11:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_10:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_r_tab_9:6;
    };
}od_cur_r_tab_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_16:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_15:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_14:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_r_tab_13:6;
    };
}od_cur_r_tab_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_19:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_18:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_r_tab_17:6;
    };
}od_cur_r_tab_idx_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_24:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_23:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_22:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_r_tab_21:6;
    };
}od_cur_r_tab_idx_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_28:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_27:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_26:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_r_tab_25:6;
    };
}od_cur_r_tab_idx_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cur_r_tab_32:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_31:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_30:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_r_tab_29:6;
    };
}od_cur_r_tab_idx_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_r_tab_1:6;
    };
}od_pre_r_tab_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_8:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_r_tab_5:6;
    };
}od_pre_r_tab_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_12:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_11:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_10:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_r_tab_9:6;
    };
}od_pre_r_tab_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_16:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_15:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_14:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_r_tab_13:6;
    };
}od_pre_r_tab_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_19:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_18:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_r_tab_17:6;
    };
}od_pre_r_tab_idx_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_24:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_23:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_22:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_r_tab_21:6;
    };
}od_pre_r_tab_idx_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_28:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_27:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_26:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_r_tab_25:6;
    };
}od_pre_r_tab_idx_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pre_r_tab_32:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_31:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_30:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_r_tab_29:6;
    };
}od_pre_r_tab_idx_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_g_tab_1:6;
    };
}od_cur_g_tab_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_8:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_g_tab_5:6;
    };
}od_cur_g_tab_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_12:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_11:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_10:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_g_tab_9:6;
    };
}od_cur_g_tab_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_16:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_15:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_14:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_g_tab_13:6;
    };
}od_cur_g_tab_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_19:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_18:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_g_tab_17:6;
    };
}od_cur_g_tab_idx_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_24:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_23:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_22:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_g_tab_21:6;
    };
}od_cur_g_tab_idx_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_28:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_27:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_26:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_g_tab_25:6;
    };
}od_cur_g_tab_idx_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cur_g_tab_32:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_31:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_30:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_g_tab_29:6;
    };
}od_cur_g_tab_idx_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_g_tab_1:6;
    };
}od_pre_g_tab_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_8:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_g_tab_5:6;
    };
}od_pre_g_tab_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_12:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_11:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_10:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_g_tab_9:6;
    };
}od_pre_g_tab_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_16:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_15:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_14:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_g_tab_13:6;
    };
}od_pre_g_tab_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_19:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_18:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_g_tab_17:6;
    };
}od_pre_g_tab_idx_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_24:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_23:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_22:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_g_tab_21:6;
    };
}od_pre_g_tab_idx_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_28:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_27:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_26:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_g_tab_25:6;
    };
}od_pre_g_tab_idx_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pre_g_tab_32:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_31:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_30:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_g_tab_29:6;
    };
}od_pre_g_tab_idx_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_b_tab_1:6;
    };
}od_cur_b_tab_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_8:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_b_tab_5:6;
    };
}od_cur_b_tab_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_12:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_11:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_10:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_b_tab_9:6;
    };
}od_cur_b_tab_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_16:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_15:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_14:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_b_tab_13:6;
    };
}od_cur_b_tab_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_19:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_18:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_b_tab_17:6;
    };
}od_cur_b_tab_idx_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_24:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_23:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_22:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_b_tab_21:6;
    };
}od_cur_b_tab_idx_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_28:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_27:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_26:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_b_tab_25:6;
    };
}od_cur_b_tab_idx_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cur_b_tab_32:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_31:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_30:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cur_b_tab_29:6;
    };
}od_cur_b_tab_idx_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_b_tab_1:6;
    };
}od_pre_b_tab_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_8:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_b_tab_5:6;
    };
}od_pre_b_tab_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_12:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_11:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_10:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_b_tab_9:6;
    };
}od_pre_b_tab_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_16:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_15:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_14:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_b_tab_13:6;
    };
}od_pre_b_tab_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_19:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_18:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_b_tab_17:6;
    };
}od_pre_b_tab_idx_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_24:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_23:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_22:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_b_tab_21:6;
    };
}od_pre_b_tab_idx_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_28:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_27:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_26:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_b_tab_25:6;
    };
}od_pre_b_tab_idx_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pre_b_tab_32:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_31:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_30:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pre_b_tab_29:6;
    };
}od_pre_b_tab_idx_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  pre_b_nonlinear_en:1;
        RBus_UInt32  cur_b_nonlinear_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_nonlinear_en:1;
        RBus_UInt32  cur_g_nonlinear_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_nonlinear_en:1;
        RBus_UInt32  cur_r_nonlinear_en:1;
    };
}od_nonlinear_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  crc_1_conti:1;
        RBus_UInt32  crc_1_start:1;
    };
}od_d_crc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_1_result:32;
    };
}od_crc_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  l_flag_enable:1;
        RBus_UInt32  w_en_ctrl:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  access_write_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  access_read_en:1;
    };
}od_accessdata_ctrl_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  access_starty:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  access_startx:12;
    };
}od_accessdata_posctrl_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v_wdat:10;
        RBus_UInt32  access_u_wdat:10;
        RBus_UInt32  access_y_wdat:10;
    };
}od_writedata_data_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v1_wdat:10;
        RBus_UInt32  access_u1_wdat:10;
        RBus_UInt32  access_y1_wdat:10;
    };
}od_writedata_data_1_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v2_wdat:10;
        RBus_UInt32  access_u2_wdat:10;
        RBus_UInt32  access_y2_wdat:10;
    };
}od_writedata_data_2_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v3_wdat:10;
        RBus_UInt32  access_u3_wdat:10;
        RBus_UInt32  access_y3_wdat:10;
    };
}od_writedata_data_3_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v4_wdat:10;
        RBus_UInt32  access_u4_wdat:10;
        RBus_UInt32  access_y4_wdat:10;
    };
}od_writedata_data_4_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v5_wdat:10;
        RBus_UInt32  access_u5_wdat:10;
        RBus_UInt32  access_y5_wdat:10;
    };
}od_writedata_data_5_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v6_wdat:10;
        RBus_UInt32  access_u6_wdat:10;
        RBus_UInt32  access_y6_wdat:10;
    };
}od_writedata_data_6_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v7_wdat:10;
        RBus_UInt32  access_u7_wdat:10;
        RBus_UInt32  access_y7_wdat:10;
    };
}od_writedata_data_7_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  access_y01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  access_y00:10;
    };
}od_readdata_data_y1_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  access_y11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  access_y10:10;
    };
}od_readdata_data_y2_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  access_u00:10;
    };
}od_readdata_data_c1_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  access_u01:10;
    };
}od_readdata_data_c2_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  access_u10:10;
    };
}od_readdata_data_c3_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  access_u11:10;
    };
}od_readdata_data_c4_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  od_tab_ls:1;
        RBus_UInt32  od_tab_dvse:1;
        RBus_UInt32  od_tab_dvs:4;
        RBus_UInt32  dvs_3:4;
        RBus_UInt32  dvs_2:4;
        RBus_UInt32  dvs_1:4;
        RBus_UInt32  dvs_0:4;
        RBus_UInt32  dvse_3:1;
        RBus_UInt32  dvse_2:1;
        RBus_UInt32  dvse_1:1;
        RBus_UInt32  dvse_0:1;
        RBus_UInt32  ls_3:1;
        RBus_UInt32  ls_2:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  ls_0:1;
    };
}od_od_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  od_drf_fail_3:1;
        RBus_UInt32  od_bist_fail_3:1;
        RBus_UInt32  od_drf_fail_2:1;
        RBus_UInt32  od_bist_fail_2:1;
        RBus_UInt32  od_drf_fail_1:1;
        RBus_UInt32  od_bist_fail_1:1;
        RBus_UInt32  od_drf_fail:1;
        RBus_UInt32  od_bist_fail:1;
    };
}od_od_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  od_line_buf_rm_1:4;
        RBus_UInt32  od_line_buf_rm_0:4;
        RBus_UInt32  od_line_buf_rme_1:1;
        RBus_UInt32  od_line_buf_rme_0:1;
        RBus_UInt32  od_line_buf_ls_1:1;
        RBus_UInt32  od_line_buf_ls_0:1;
    };
}od_od_bist_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  boundary_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  even_b_color_select:2;
        RBus_UInt32  even_g_color_select:2;
        RBus_UInt32  even_r_color_select:2;
        RBus_UInt32  even_b_point_select:2;
        RBus_UInt32  even_g_point_select:2;
        RBus_UInt32  even_r_point_select:2;
        RBus_UInt32  even_b_line_select:2;
        RBus_UInt32  even_g_line_select:2;
        RBus_UInt32  even_r_line_select:2;
    };
}od_pcid_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  odd_b_color_select:2;
        RBus_UInt32  odd_g_color_select:2;
        RBus_UInt32  odd_r_color_select:2;
        RBus_UInt32  odd_b_point_select:2;
        RBus_UInt32  odd_g_point_select:2;
        RBus_UInt32  odd_r_point_select:2;
        RBus_UInt32  odd_b_line_select:2;
        RBus_UInt32  odd_g_line_select:2;
        RBus_UInt32  odd_r_line_select:2;
    };
}od_pcid_ctrl_1_RBUS;

#else //apply LITTLE_ENDIAN

//======OD register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_en:1;
        RBus_UInt32  od_fun_sel:1;
        RBus_UInt32  res1:30;
    };
}od_od_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_pdest_en:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  od_disp_res:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  od_delta_gain:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  rounding_en:1;
        RBus_UInt32  od_cur_src_sel:1;
        RBus_UInt32  ori_cur_sel:1;
        RBus_UInt32  compress_ctrl:1;
        RBus_UInt32  force_pre_out:1;
        RBus_UInt32  od_freeze:1;
        RBus_UInt32  gibi_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  od_en_dbf_en:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_apply:1;
        RBus_UInt32  res5:5;
    };
}od_od_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_lut_column_addr:6;
        RBus_UInt32  od_lut_row_addr:6;
        RBus_UInt32  od_lut_sel:2;
        RBus_UInt32  od_lut_adr_mode:1;
        RBus_UInt32  od_lut_ax_mode:1;
        RBus_UInt32  od_lut_ax_en:1;
        RBus_UInt32  od_lut_index:1;
        RBus_UInt32  table_type:1;
        RBus_UInt32  res1:13;
    };
}od_od_lut_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_lut_data:32;
    };
}od_od_lut_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_region_1_toplinenumber:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  od_region_1_step:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  od_region_1_step_ratio:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  regional_od_en:1;
        RBus_UInt32  res4:4;
    };
}od_regional_od_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_region_2_toplinenumber:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  od_region_2_step:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  od_region_2_step_ratio:1;
        RBus_UInt32  res3:7;
    };
}od_regional_od_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_region_3_toplinenumber:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  od_region_3_step:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  od_region_3_step_ratio:1;
        RBus_UInt32  res3:7;
    };
}od_regional_od_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_region_4_toplinenumber:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  od_region_4_step:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  od_region_4_step_ratio:1;
        RBus_UInt32  res3:7;
    };
}od_regional_od_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_region_5_toplinenumber:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  od_region_5_step:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  od_region_5_step_ratio:1;
        RBus_UInt32  res3:7;
    };
}od_regional_od_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_r_nr_thd:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  od_g_nr_thd:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  od_b_nr_thd:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  od_r_nr_en:1;
        RBus_UInt32  od_g_nr_en:1;
        RBus_UInt32  od_b_nr_en:1;
        RBus_UInt32  od_nr_mode:1;
        RBus_UInt32  res4:4;
    };
}od_od_noise_reduction_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  repeat_frame_od_mode:2;
        RBus_UInt32  res1:30;
    };
}od_frame_rpt_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_read_address_1:28;
        RBus_UInt32  res1:4;
    };
}od_table_move_dma_addr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_read_address_2:28;
        RBus_UInt32  res1:4;
    };
}od_table_move_dma_addr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_read_address_3:28;
        RBus_UInt32  res1:4;
    };
}od_table_move_dma_addr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_read_address_4:28;
        RBus_UInt32  res1:4;
    };
}od_table_move_dma_addr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_read_address_5:28;
        RBus_UInt32  res1:4;
    };
}od_table_move_dma_addr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_read_address_6:28;
        RBus_UInt32  res1:4;
    };
}od_table_move_dma_addr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_read_address_delta_1:28;
        RBus_UInt32  res1:4;
    };
}od_table_move_dma_addr1_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_read_address_delta_2:28;
        RBus_UInt32  res1:4;
    };
}od_table_move_dma_addr2_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_read_address_delta_3:28;
        RBus_UInt32  res1:4;
    };
}od_table_move_dma_addr3_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_read_address_delta_4:28;
        RBus_UInt32  res1:4;
    };
}od_table_move_dma_addr4_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_read_address_delta_5:28;
        RBus_UInt32  res1:4;
    };
}od_table_move_dma_addr5_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_read_address_delta_6:28;
        RBus_UInt32  res1:4;
    };
}od_table_move_dma_addr6_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table_burst_length:3;
        RBus_UInt32  table_request_wait_cnt:10;
        RBus_UInt32  res1:1;
        RBus_UInt32  reload_tab1:1;
        RBus_UInt32  reload_tab2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  table_src_sel:1;
        RBus_UInt32  tab_move_en:1;
        RBus_UInt32  res3:13;
    };
}od_table_move_dma_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_not_ready_flag:1;
        RBus_UInt32  reload_err_flag:1;
        RBus_UInt32  res1:30;
    };
}od_table_move_dma_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_r_tab_1:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_4:6;
        RBus_UInt32  res4:2;
    };
}od_cur_r_tab_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_r_tab_5:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_8:6;
        RBus_UInt32  res4:2;
    };
}od_cur_r_tab_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_r_tab_9:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_10:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_11:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_12:6;
        RBus_UInt32  res4:2;
    };
}od_cur_r_tab_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_r_tab_13:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_14:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_15:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_16:6;
        RBus_UInt32  res4:2;
    };
}od_cur_r_tab_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_r_tab_17:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_18:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_19:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_20:6;
        RBus_UInt32  res4:2;
    };
}od_cur_r_tab_idx_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_r_tab_21:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_22:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_23:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_24:6;
        RBus_UInt32  res4:2;
    };
}od_cur_r_tab_idx_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_r_tab_25:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_26:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_27:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_28:6;
        RBus_UInt32  res4:2;
    };
}od_cur_r_tab_idx_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_r_tab_29:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_r_tab_30:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_r_tab_31:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_r_tab_32:7;
        RBus_UInt32  res4:1;
    };
}od_cur_r_tab_idx_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_r_tab_1:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_4:6;
        RBus_UInt32  res4:2;
    };
}od_pre_r_tab_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_r_tab_5:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_8:6;
        RBus_UInt32  res4:2;
    };
}od_pre_r_tab_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_r_tab_9:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_10:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_11:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_12:6;
        RBus_UInt32  res4:2;
    };
}od_pre_r_tab_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_r_tab_13:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_14:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_15:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_16:6;
        RBus_UInt32  res4:2;
    };
}od_pre_r_tab_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_r_tab_17:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_18:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_19:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_20:6;
        RBus_UInt32  res4:2;
    };
}od_pre_r_tab_idx_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_r_tab_21:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_22:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_23:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_24:6;
        RBus_UInt32  res4:2;
    };
}od_pre_r_tab_idx_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_r_tab_25:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_26:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_27:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_28:6;
        RBus_UInt32  res4:2;
    };
}od_pre_r_tab_idx_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_r_tab_29:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_r_tab_30:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_r_tab_31:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_r_tab_32:7;
        RBus_UInt32  res4:1;
    };
}od_pre_r_tab_idx_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_g_tab_1:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_4:6;
        RBus_UInt32  res4:2;
    };
}od_cur_g_tab_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_g_tab_5:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_8:6;
        RBus_UInt32  res4:2;
    };
}od_cur_g_tab_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_g_tab_9:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_10:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_11:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_12:6;
        RBus_UInt32  res4:2;
    };
}od_cur_g_tab_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_g_tab_13:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_14:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_15:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_16:6;
        RBus_UInt32  res4:2;
    };
}od_cur_g_tab_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_g_tab_17:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_18:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_19:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_20:6;
        RBus_UInt32  res4:2;
    };
}od_cur_g_tab_idx_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_g_tab_21:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_22:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_23:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_24:6;
        RBus_UInt32  res4:2;
    };
}od_cur_g_tab_idx_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_g_tab_25:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_26:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_27:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_28:6;
        RBus_UInt32  res4:2;
    };
}od_cur_g_tab_idx_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_g_tab_29:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_tab_30:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_g_tab_31:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_g_tab_32:7;
        RBus_UInt32  res4:1;
    };
}od_cur_g_tab_idx_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_g_tab_1:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_4:6;
        RBus_UInt32  res4:2;
    };
}od_pre_g_tab_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_g_tab_5:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_8:6;
        RBus_UInt32  res4:2;
    };
}od_pre_g_tab_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_g_tab_9:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_10:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_11:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_12:6;
        RBus_UInt32  res4:2;
    };
}od_pre_g_tab_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_g_tab_13:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_14:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_15:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_16:6;
        RBus_UInt32  res4:2;
    };
}od_pre_g_tab_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_g_tab_17:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_18:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_19:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_20:6;
        RBus_UInt32  res4:2;
    };
}od_pre_g_tab_idx_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_g_tab_21:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_22:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_23:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_24:6;
        RBus_UInt32  res4:2;
    };
}od_pre_g_tab_idx_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_g_tab_25:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_26:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_27:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_28:6;
        RBus_UInt32  res4:2;
    };
}od_pre_g_tab_idx_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_g_tab_29:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_g_tab_30:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_g_tab_31:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_g_tab_32:7;
        RBus_UInt32  res4:1;
    };
}od_pre_g_tab_idx_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_b_tab_1:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_4:6;
        RBus_UInt32  res4:2;
    };
}od_cur_b_tab_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_b_tab_5:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_8:6;
        RBus_UInt32  res4:2;
    };
}od_cur_b_tab_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_b_tab_9:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_10:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_11:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_12:6;
        RBus_UInt32  res4:2;
    };
}od_cur_b_tab_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_b_tab_13:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_14:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_15:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_16:6;
        RBus_UInt32  res4:2;
    };
}od_cur_b_tab_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_b_tab_17:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_18:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_19:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_20:6;
        RBus_UInt32  res4:2;
    };
}od_cur_b_tab_idx_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_b_tab_21:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_22:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_23:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_24:6;
        RBus_UInt32  res4:2;
    };
}od_cur_b_tab_idx_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_b_tab_25:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_26:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_27:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_28:6;
        RBus_UInt32  res4:2;
    };
}od_cur_b_tab_idx_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_b_tab_29:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_b_tab_30:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_tab_31:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cur_b_tab_32:7;
        RBus_UInt32  res4:1;
    };
}od_cur_b_tab_idx_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_b_tab_1:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_4:6;
        RBus_UInt32  res4:2;
    };
}od_pre_b_tab_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_b_tab_5:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_8:6;
        RBus_UInt32  res4:2;
    };
}od_pre_b_tab_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_b_tab_9:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_10:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_11:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_12:6;
        RBus_UInt32  res4:2;
    };
}od_pre_b_tab_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_b_tab_13:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_14:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_15:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_16:6;
        RBus_UInt32  res4:2;
    };
}od_pre_b_tab_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_b_tab_17:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_18:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_19:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_20:6;
        RBus_UInt32  res4:2;
    };
}od_pre_b_tab_idx_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_b_tab_21:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_22:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_23:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_24:6;
        RBus_UInt32  res4:2;
    };
}od_pre_b_tab_idx_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_b_tab_25:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_26:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_27:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_28:6;
        RBus_UInt32  res4:2;
    };
}od_pre_b_tab_idx_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_b_tab_29:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_b_tab_30:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_b_tab_31:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pre_b_tab_32:7;
        RBus_UInt32  res4:1;
    };
}od_pre_b_tab_idx_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_r_nonlinear_en:1;
        RBus_UInt32  pre_r_nonlinear_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  cur_g_nonlinear_en:1;
        RBus_UInt32  pre_g_nonlinear_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cur_b_nonlinear_en:1;
        RBus_UInt32  pre_b_nonlinear_en:1;
        RBus_UInt32  res3:22;
    };
}od_nonlinear_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_1_start:1;
        RBus_UInt32  crc_1_conti:1;
        RBus_UInt32  res1:30;
    };
}od_d_crc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_1_result:32;
    };
}od_crc_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_read_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  access_write_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  w_en_ctrl:4;
        RBus_UInt32  l_flag_enable:1;
        RBus_UInt32  res3:23;
    };
}od_accessdata_ctrl_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_startx:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  access_starty:12;
        RBus_UInt32  res2:4;
    };
}od_accessdata_posctrl_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y_wdat:10;
        RBus_UInt32  access_u_wdat:10;
        RBus_UInt32  access_v_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y1_wdat:10;
        RBus_UInt32  access_u1_wdat:10;
        RBus_UInt32  access_v1_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_1_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y2_wdat:10;
        RBus_UInt32  access_u2_wdat:10;
        RBus_UInt32  access_v2_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_2_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y3_wdat:10;
        RBus_UInt32  access_u3_wdat:10;
        RBus_UInt32  access_v3_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_3_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y4_wdat:10;
        RBus_UInt32  access_u4_wdat:10;
        RBus_UInt32  access_v4_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_4_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y5_wdat:10;
        RBus_UInt32  access_u5_wdat:10;
        RBus_UInt32  access_v5_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_5_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y6_wdat:10;
        RBus_UInt32  access_u6_wdat:10;
        RBus_UInt32  access_v6_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_6_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y7_wdat:10;
        RBus_UInt32  access_u7_wdat:10;
        RBus_UInt32  access_v7_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_7_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  access_y01:10;
        RBus_UInt32  res2:6;
    };
}od_readdata_data_y1_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  access_y11:10;
        RBus_UInt32  res2:6;
    };
}od_readdata_data_y2_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_u00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v00:10;
        RBus_UInt32  res2:6;
    };
}od_readdata_data_c1_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_u01:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v01:10;
        RBus_UInt32  res2:6;
    };
}od_readdata_data_c2_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_u10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v10:10;
        RBus_UInt32  res2:6;
    };
}od_readdata_data_c3_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_u11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v11:10;
        RBus_UInt32  res2:6;
    };
}od_readdata_data_c4_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_0:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  ls_2:1;
        RBus_UInt32  ls_3:1;
        RBus_UInt32  dvse_0:1;
        RBus_UInt32  dvse_1:1;
        RBus_UInt32  dvse_2:1;
        RBus_UInt32  dvse_3:1;
        RBus_UInt32  dvs_0:4;
        RBus_UInt32  dvs_1:4;
        RBus_UInt32  dvs_2:4;
        RBus_UInt32  dvs_3:4;
        RBus_UInt32  od_tab_dvs:4;
        RBus_UInt32  od_tab_dvse:1;
        RBus_UInt32  od_tab_ls:1;
        RBus_UInt32  res1:2;
    };
}od_od_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_bist_fail:1;
        RBus_UInt32  od_drf_fail:1;
        RBus_UInt32  od_bist_fail_1:1;
        RBus_UInt32  od_drf_fail_1:1;
        RBus_UInt32  od_bist_fail_2:1;
        RBus_UInt32  od_drf_fail_2:1;
        RBus_UInt32  od_bist_fail_3:1;
        RBus_UInt32  od_drf_fail_3:1;
        RBus_UInt32  res1:24;
    };
}od_od_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_line_buf_ls_0:1;
        RBus_UInt32  od_line_buf_ls_1:1;
        RBus_UInt32  od_line_buf_rme_0:1;
        RBus_UInt32  od_line_buf_rme_1:1;
        RBus_UInt32  od_line_buf_rm_0:4;
        RBus_UInt32  od_line_buf_rm_1:4;
        RBus_UInt32  res1:20;
    };
}od_od_bist_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  even_r_line_select:2;
        RBus_UInt32  even_g_line_select:2;
        RBus_UInt32  even_b_line_select:2;
        RBus_UInt32  even_r_point_select:2;
        RBus_UInt32  even_g_point_select:2;
        RBus_UInt32  even_b_point_select:2;
        RBus_UInt32  even_r_color_select:2;
        RBus_UInt32  even_g_color_select:2;
        RBus_UInt32  even_b_color_select:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  boundary_mode:1;
        RBus_UInt32  res2:11;
    };
}od_pcid_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  odd_r_line_select:2;
        RBus_UInt32  odd_g_line_select:2;
        RBus_UInt32  odd_b_line_select:2;
        RBus_UInt32  odd_r_point_select:2;
        RBus_UInt32  odd_g_point_select:2;
        RBus_UInt32  odd_b_point_select:2;
        RBus_UInt32  odd_r_color_select:2;
        RBus_UInt32  odd_g_color_select:2;
        RBus_UInt32  odd_b_color_select:2;
        RBus_UInt32  res1:14;
    };
}od_pcid_ctrl_1_RBUS;




#endif 


#endif 
