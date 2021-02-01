/**
* @file rbusGammaReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/6/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_GAMMA_REG_H_
#define _RBUS_GAMMA_REG_H_

#include "rbusTypes.h"



//  GAMMA Register Address



#define  GAMMA_GAMMA_PORT_VADDR                             	(0xb802c100)
#define  GAMMA_GAMMA_CTRL_1_VADDR                           	(0xb802c104)
#define  GAMMA_GAMMA_CTRL_2_VADDR                           	(0xb802c108)
#define  GAMMA_GAMMA_CTRL_3_VADDR                           	(0xb802c10c)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_VADDR                 	(0xb802c110)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_VADDR                 	(0xb802c114)
#define  GAMMA_ADAPT_GAMMA_VADDR                            	(0xb802c120)
#define  GAMMA_GAMMA_BS_CONTROL_VADDR                       	(0xb802c130)
#define  GAMMA_GAMMA_BS_Y_INDEX_1_VADDR                     	(0xb802c134)
#define  GAMMA_GAMMA_BS_Y_INDEX_2_VADDR                     	(0xb802c138)
#define  GAMMA_GAMMA_BS_R_OFFSET_1_VADDR                    	(0xb802c13c)
#define  GAMMA_GAMMA_BS_R_OFFSET_2_VADDR                    	(0xb802c140)
#define  GAMMA_GAMMA_BS_R_OFFSET_3_VADDR                    	(0xb802c144)
#define  GAMMA_GAMMA_BS_G_OFFSET_1_VADDR                    	(0xb802c148)
#define  GAMMA_GAMMA_BS_G_OFFSET_2_VADDR                    	(0xb802c14c)
#define  GAMMA_GAMMA_BS_G_OFFSET_3_VADDR                    	(0xb802c150)
#define  GAMMA_GAMMA_BS_B_OFFSET_1_VADDR                    	(0xb802c154)
#define  GAMMA_GAMMA_BS_B_OFFSET_2_VADDR                    	(0xb802c158)
#define  GAMMA_GAMMA_BS_B_OFFSET_3_VADDR                    	(0xb802c15c)
#define  GAMMA_GAMMA_BS_R_STEP_1_VADDR                      	(0xb802c160)
#define  GAMMA_GAMMA_BS_R_STEP_2_VADDR                      	(0xb802c164)
#define  GAMMA_GAMMA_BS_G_STEP_1_VADDR                      	(0xb802c168)
#define  GAMMA_GAMMA_BS_G_STEP_2_VADDR                      	(0xb802c16c)
#define  GAMMA_GAMMA_BS_B_STEP_1_VADDR                      	(0xb802c170)
#define  GAMMA_GAMMA_BS_B_STEP_2_VADDR                      	(0xb802c174)
#define  GAMMA_DSTAT_CTRL_R_VADDR                           	(0xb802c180)
#define  GAMMA_DSTAT_CTRL_G_VADDR                           	(0xb802c184)
#define  GAMMA_DSTAT_CTRL_B_VADDR                           	(0xb802c188)
#define  GAMMA_DSTAT_O_R1_VADDR                             	(0xb802c18c)
#define  GAMMA_DSTAT_O_R2_VADDR                             	(0xb802c190)
#define  GAMMA_DSTAT_O_G1_VADDR                             	(0xb802c194)
#define  GAMMA_DSTAT_O_G2_VADDR                             	(0xb802c198)
#define  GAMMA_DSTAT_O_B1_VADDR                             	(0xb802c19c)
#define  GAMMA_DSTAT_O_B2_VADDR                             	(0xb802c1a0)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======GAMMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gamma_tab_index:12;
        RBus_UInt32  gamma_tab_d0:8;
        RBus_UInt32  gamma_tab_d1:8;
    };
}gamma_gamma_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  gamma_tab_addr:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  gamma_ax_rw_sel:2;
        RBus_UInt32  gamma_ax_tab_sel:1;
        RBus_UInt32  gamma_ax_ch_sel:2;
        RBus_UInt32  gamma_fifo_empty:1;
        RBus_UInt32  gamma_fifo_full:1;
        RBus_UInt32  gamma_wr_error:1;
        RBus_UInt32  dummy1802c104_0:1;
    };
}gamma_gamma_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  gamma_tab_size_sel:1;
        RBus_UInt32  gamma_m_tab_sel:2;
        RBus_UInt32  gamma_s_tab_sel:2;
        RBus_UInt32  gamma_overlap:1;
        RBus_UInt32  dummy1802c108_2_0:3;
    };
}gamma_gamma_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  gamma_msb_d0_r:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  gamma_msb_d0_g:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  gamma_msb_d0_b:3;
    };
}gamma_gamma_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ls:1;
        RBus_UInt32  rme:1;
        RBus_UInt32  rm:4;
    };
}gamma_gamma_srgb_bist_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  inv_gamma_r_drf_bist_fail:1;
        RBus_UInt32  inv_gamma_g_drf_bist_fail:1;
        RBus_UInt32  inv_gamma_b_drf_bist_fail:1;
        RBus_UInt32  srgb_r_drf_bist_fail:1;
        RBus_UInt32  srgb_g_drf_bist_fail:1;
        RBus_UInt32  srgb_b_drf_bist_fail:1;
        RBus_UInt32  gamma_r_drf_bist_fail:1;
        RBus_UInt32  gamma_g_drf_bist_fail:1;
        RBus_UInt32  gamma_b_drf_bist_fail:1;
        RBus_UInt32  inv_gamma_r_bist_fail:1;
        RBus_UInt32  inv_gamma_g_bist_fail:1;
        RBus_UInt32  inv_gamma_b_bist_fail:1;
        RBus_UInt32  srgb_r_bist_fail:1;
        RBus_UInt32  srgb_g_bist_fail:1;
        RBus_UInt32  srgb_b_bist_fail:1;
        RBus_UInt32  gamma_r_bist_fail:1;
        RBus_UInt32  gamma_g_bist_fail:1;
        RBus_UInt32  gamma_b_bist_fail:1;
    };
}gamma_gamma_srgb_bist_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_adapt_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sat_thl:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  sat_thl_mul:12;
    };
}gamma_adapt_gamma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c130_31_22:10;
        RBus_UInt32  gamma_bs_r_gain:2;
        RBus_UInt32  gamma_bs_g_gain:2;
        RBus_UInt32  gamma_bs_b_gain:2;
        RBus_UInt32  gamma_bs_sat_thd:8;
        RBus_UInt32  res1:6;
        RBus_UInt32  gamma_m_bs_en:1;
        RBus_UInt32  gamma_s_bs_en:1;
    };
}gamma_gamma_bs_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_y3:8;
        RBus_UInt32  gamma_bs_y2:8;
        RBus_UInt32  gamma_bs_y1:8;
        RBus_UInt32  gamma_bs_y0:8;
    };
}gamma_gamma_bs_y_index_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_y7:8;
        RBus_UInt32  gamma_bs_y6:8;
        RBus_UInt32  gamma_bs_y5:8;
        RBus_UInt32  gamma_bs_y4:8;
    };
}gamma_gamma_bs_y_index_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_bs_r_ofst_2:9;
        RBus_UInt32  gamma_bs_r_ofst_1:9;
        RBus_UInt32  gamma_bs_r_ofst_0:9;
    };
}gamma_gamma_bs_r_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_bs_r_ofst_5:9;
        RBus_UInt32  gamma_bs_r_ofst_4:9;
        RBus_UInt32  gamma_bs_r_ofst_3:9;
    };
}gamma_gamma_bs_r_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  gamma_bs_r_ofst_7:9;
        RBus_UInt32  gamma_bs_r_ofst_6:9;
    };
}gamma_gamma_bs_r_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_bs_g_ofst_2:9;
        RBus_UInt32  gamma_bs_g_ofst_1:9;
        RBus_UInt32  gamma_bs_g_ofst_0:9;
    };
}gamma_gamma_bs_g_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_bs_g_ofst_5:9;
        RBus_UInt32  gamma_bs_g_ofst_4:9;
        RBus_UInt32  gamma_bs_g_ofst_3:9;
    };
}gamma_gamma_bs_g_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  gamma_bs_g_ofst_7:9;
        RBus_UInt32  gamma_bs_g_ofst_6:9;
    };
}gamma_gamma_bs_g_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_bs_b_ofst_2:9;
        RBus_UInt32  gamma_bs_b_ofst_1:9;
        RBus_UInt32  gamma_bs_b_ofst_0:9;
    };
}gamma_gamma_bs_b_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_bs_b_ofst_5:9;
        RBus_UInt32  gamma_bs_b_ofst_4:9;
        RBus_UInt32  gamma_bs_b_ofst_3:9;
    };
}gamma_gamma_bs_b_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  gamma_bs_b_ofst_7:9;
        RBus_UInt32  gamma_bs_b_ofst_6:9;
    };
}gamma_gamma_bs_b_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_r_step_3:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_r_step_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_r_step_1:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  gamma_bs_r_step_0:7;
    };
}gamma_gamma_bs_r_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_r_step_7:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_r_step_6:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_r_step_5:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  gamma_bs_r_step_4:7;
    };
}gamma_gamma_bs_r_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_g_step_3:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_g_step_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_g_step_1:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  gamma_bs_g_step_0:7;
    };
}gamma_gamma_bs_g_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_g_step_7:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_g_step_6:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_g_step_5:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  gamma_bs_g_step_4:7;
    };
}gamma_gamma_bs_g_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_b_step_3:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_b_step_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_b_step_1:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  gamma_bs_b_step_0:7;
    };
}gamma_gamma_bs_b_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_b_step_7:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_b_step_6:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_b_step_5:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  gamma_bs_b_step_4:7;
    };
}gamma_gamma_bs_b_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_stat_enable:1;
        RBus_UInt32  d_stat_srcsel:1;
        RBus_UInt32  r_low:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  r_high:14;
    };
}gamma_dstat_ctrl_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  g_low:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  g_high:14;
    };
}gamma_dstat_ctrl_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  b_low:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  b_high:14;
    };
}gamma_dstat_ctrl_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  r_cnt:24;
    };
}gamma_dstat_o_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  r_min:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  r_max:14;
    };
}gamma_dstat_o_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  g_cnt:24;
    };
}gamma_dstat_o_g1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  g_min:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  g_max:14;
    };
}gamma_dstat_o_g2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  b_cnt:24;
    };
}gamma_dstat_o_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  b_min:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  b_max:14;
    };
}gamma_dstat_o_b2_RBUS;

#else //apply LITTLE_ENDIAN

//======GAMMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_tab_d1:8;
        RBus_UInt32  gamma_tab_d0:8;
        RBus_UInt32  gamma_tab_index:12;
        RBus_UInt32  res1:4;
    };
}gamma_gamma_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c104_0:1;
        RBus_UInt32  gamma_wr_error:1;
        RBus_UInt32  gamma_fifo_full:1;
        RBus_UInt32  gamma_fifo_empty:1;
        RBus_UInt32  gamma_ax_ch_sel:2;
        RBus_UInt32  gamma_ax_tab_sel:1;
        RBus_UInt32  gamma_ax_rw_sel:2;
        RBus_UInt32  res1:7;
        RBus_UInt32  gamma_tab_addr:9;
        RBus_UInt32  res2:7;
    };
}gamma_gamma_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c108_2_0:3;
        RBus_UInt32  gamma_overlap:1;
        RBus_UInt32  gamma_s_tab_sel:2;
        RBus_UInt32  gamma_m_tab_sel:2;
        RBus_UInt32  gamma_tab_size_sel:1;
        RBus_UInt32  res1:23;
    };
}gamma_gamma_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_msb_d0_b:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_msb_d0_g:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  gamma_msb_d0_r:3;
        RBus_UInt32  res3:13;
    };
}gamma_gamma_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm:4;
        RBus_UInt32  rme:1;
        RBus_UInt32  ls:1;
        RBus_UInt32  res1:26;
    };
}gamma_gamma_srgb_bist_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_b_bist_fail:1;
        RBus_UInt32  gamma_g_bist_fail:1;
        RBus_UInt32  gamma_r_bist_fail:1;
        RBus_UInt32  srgb_b_bist_fail:1;
        RBus_UInt32  srgb_g_bist_fail:1;
        RBus_UInt32  srgb_r_bist_fail:1;
        RBus_UInt32  inv_gamma_b_bist_fail:1;
        RBus_UInt32  inv_gamma_g_bist_fail:1;
        RBus_UInt32  inv_gamma_r_bist_fail:1;
        RBus_UInt32  gamma_b_drf_bist_fail:1;
        RBus_UInt32  gamma_g_drf_bist_fail:1;
        RBus_UInt32  gamma_r_drf_bist_fail:1;
        RBus_UInt32  srgb_b_drf_bist_fail:1;
        RBus_UInt32  srgb_g_drf_bist_fail:1;
        RBus_UInt32  srgb_r_drf_bist_fail:1;
        RBus_UInt32  inv_gamma_b_drf_bist_fail:1;
        RBus_UInt32  inv_gamma_g_drf_bist_fail:1;
        RBus_UInt32  inv_gamma_r_drf_bist_fail:1;
        RBus_UInt32  res1:14;
    };
}gamma_gamma_srgb_bist_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_thl_mul:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  sat_thl:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  gamma_adapt_en:1;
    };
}gamma_adapt_gamma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_s_bs_en:1;
        RBus_UInt32  gamma_m_bs_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  gamma_bs_sat_thd:8;
        RBus_UInt32  gamma_bs_b_gain:2;
        RBus_UInt32  gamma_bs_g_gain:2;
        RBus_UInt32  gamma_bs_r_gain:2;
        RBus_UInt32  dummy1802c130_31:10;
    };
}gamma_gamma_bs_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_y0:8;
        RBus_UInt32  gamma_bs_y1:8;
        RBus_UInt32  gamma_bs_y2:8;
        RBus_UInt32  gamma_bs_y3:8;
    };
}gamma_gamma_bs_y_index_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_y4:8;
        RBus_UInt32  gamma_bs_y5:8;
        RBus_UInt32  gamma_bs_y6:8;
        RBus_UInt32  gamma_bs_y7:8;
    };
}gamma_gamma_bs_y_index_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_r_ofst_0:9;
        RBus_UInt32  gamma_bs_r_ofst_1:9;
        RBus_UInt32  gamma_bs_r_ofst_2:9;
        RBus_UInt32  res1:5;
    };
}gamma_gamma_bs_r_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_r_ofst_3:9;
        RBus_UInt32  gamma_bs_r_ofst_4:9;
        RBus_UInt32  gamma_bs_r_ofst_5:9;
        RBus_UInt32  res1:5;
    };
}gamma_gamma_bs_r_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_r_ofst_6:9;
        RBus_UInt32  gamma_bs_r_ofst_7:9;
        RBus_UInt32  res1:14;
    };
}gamma_gamma_bs_r_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_g_ofst_0:9;
        RBus_UInt32  gamma_bs_g_ofst_1:9;
        RBus_UInt32  gamma_bs_g_ofst_2:9;
        RBus_UInt32  res1:5;
    };
}gamma_gamma_bs_g_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_g_ofst_3:9;
        RBus_UInt32  gamma_bs_g_ofst_4:9;
        RBus_UInt32  gamma_bs_g_ofst_5:9;
        RBus_UInt32  res1:5;
    };
}gamma_gamma_bs_g_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_g_ofst_6:9;
        RBus_UInt32  gamma_bs_g_ofst_7:9;
        RBus_UInt32  res1:14;
    };
}gamma_gamma_bs_g_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_b_ofst_0:9;
        RBus_UInt32  gamma_bs_b_ofst_1:9;
        RBus_UInt32  gamma_bs_b_ofst_2:9;
        RBus_UInt32  res1:5;
    };
}gamma_gamma_bs_b_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_b_ofst_3:9;
        RBus_UInt32  gamma_bs_b_ofst_4:9;
        RBus_UInt32  gamma_bs_b_ofst_5:9;
        RBus_UInt32  res1:5;
    };
}gamma_gamma_bs_b_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_b_ofst_6:9;
        RBus_UInt32  gamma_bs_b_ofst_7:9;
        RBus_UInt32  res1:14;
    };
}gamma_gamma_bs_b_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_r_step_0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_r_step_1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_r_step_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_r_step_3:7;
        RBus_UInt32  res4:1;
    };
}gamma_gamma_bs_r_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_r_step_4:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_r_step_5:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_r_step_6:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_r_step_7:7;
        RBus_UInt32  res4:1;
    };
}gamma_gamma_bs_r_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_g_step_0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_g_step_1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_g_step_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_g_step_3:7;
        RBus_UInt32  res4:1;
    };
}gamma_gamma_bs_g_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_g_step_4:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_g_step_5:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_g_step_6:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_g_step_7:7;
        RBus_UInt32  res4:1;
    };
}gamma_gamma_bs_g_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_b_step_0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_b_step_1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_b_step_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_b_step_3:7;
        RBus_UInt32  res4:1;
    };
}gamma_gamma_bs_b_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_b_step_4:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_b_step_5:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_b_step_6:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_b_step_7:7;
        RBus_UInt32  res4:1;
    };
}gamma_gamma_bs_b_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_high:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  r_low:14;
        RBus_UInt32  d_stat_srcsel:1;
        RBus_UInt32  d_stat_enable:1;
    };
}gamma_dstat_ctrl_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  g_high:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  g_low:14;
        RBus_UInt32  res2:2;
    };
}gamma_dstat_ctrl_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b_high:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  b_low:14;
        RBus_UInt32  res2:2;
    };
}gamma_dstat_ctrl_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_cnt:24;
        RBus_UInt32  res1:8;
    };
}gamma_dstat_o_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_max:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  r_min:14;
        RBus_UInt32  res2:2;
    };
}gamma_dstat_o_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  g_cnt:24;
        RBus_UInt32  res1:8;
    };
}gamma_dstat_o_g1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  g_max:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  g_min:14;
        RBus_UInt32  res2:2;
    };
}gamma_dstat_o_g2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b_cnt:24;
        RBus_UInt32  res1:8;
    };
}gamma_dstat_o_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b_max:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  b_min:14;
        RBus_UInt32  res2:2;
    };
}gamma_dstat_o_b2_RBUS;




#endif 


#endif 
