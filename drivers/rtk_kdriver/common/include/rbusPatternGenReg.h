/**
* @file rbusMacArthur3-DesignSpec-I-Domain-PatternGenReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014-7-11
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MACARTHUR3_DESIGNSPEC_I_DOMAIN_PATTERNGEN_REG_H_
#define _RBUS_MACARTHUR3_DESIGNSPEC_I_DOMAIN_PATTERNGEN_REG_H_

#include "rbusTypes.h"



//  MACARTHUR3-DESIGNSPEC-I-DOMAIN-PATTERNGEN Register Address



#define  PATTERNGEN_PTG_TOTALHV_VADDR                       	(0xb8022100)
#define  PATTERNGEN_PTG_ACT_H_START_WIDTH_VADDR             	(0xb8022104)
#define  PATTERNGEN_PTG_ACT_V_START_LENGTH_VADDR            	(0xb8022108)
#define  PATTERNGEN_PTG_TG_VADDR                            	(0xb802210c)
#define  PATTERNGEN_PTG_TG_LINE_VADDR                       	(0xb8022110)
#define  PATTERNGEN_PTG_L_PAT_HSTA_WIDTH_VADDR              	(0xb8022114)
#define  PATTERNGEN_PTG_L_PAT_VSTA_LENGTH_VADDR             	(0xb8022118)
#define  PATTERNGEN_PTG_L_CTRL_VADDR                        	(0xb802211c)
#define  PATTERNGEN_PTG_L_BARW_VADDR                        	(0xb8022120)
#define  PATTERNGEN_PTG_L_C0Y_CB_CR_VADDR                   	(0xb8022124)
#define  PATTERNGEN_PTG_L_C1Y_CB_CR_VADDR                   	(0xb8022128)
#define  PATTERNGEN_PTG_L_C2Y_CB_CR_VADDR                   	(0xb802212c)
#define  PATTERNGEN_PTG_L_C3Y_CB_CR_VADDR                   	(0xb8022130)
#define  PATTERNGEN_PTG_L_C4Y_CB_CR_VADDR                   	(0xb8022134)
#define  PATTERNGEN_PTG_L_C5Y_CR_CB_VADDR                   	(0xb8022138)
#define  PATTERNGEN_PTG_L_C6Y_CB_CR_VADDR                   	(0xb802213c)
#define  PATTERNGEN_PTG_L_C7Y_CB_CR_VADDR                   	(0xb8022140)
#define  PATTERNGEN_PTG_L_MAX_COLOR_CTRL_VADDR              	(0xb8022144)
#define  PATTERNGEN_PTG_R_PAT_HSTA_WIDTH_VADDR              	(0xb8022148)
#define  PATTERNGEN_PTG_R_PAT_VSTA_LENGTH_VADDR             	(0xb802214c)
#define  PATTERNGEN_PTG_R_CTRL_VADDR                        	(0xb8022150)
#define  PATTERNGEN_PTG_R_BARW_VADDR                        	(0xb8022154)
#define  PATTERNGEN_PTG_R_C0Y_CB_CR_VADDR                   	(0xb8022158)
#define  PATTERNGEN_PTG_R_C1Y_CB_CR_VADDR                   	(0xb802215c)
#define  PATTERNGEN_PTG_R_C2Y_CB_CR_VADDR                   	(0xb8022160)
#define  PATTERNGEN_PTG_R_C3Y_CB_CR_VADDR                   	(0xb8022164)
#define  PATTERNGEN_PTG_R_C4Y_CB_CR_VADDR                   	(0xb8022168)
#define  PATTERNGEN_PTG_R_C5Y_CR_CB_VADDR                   	(0xb802216c)
#define  PATTERNGEN_PTG_R_C6Y_CB_CR_VADDR                   	(0xb8022170)
#define  PATTERNGEN_PTG_R_C7Y_CB_CR_VADDR                   	(0xb8022174)
#define  PATTERNGEN_PTG_R_MAX_COLOR_CTRL_VADDR              	(0xb8022178)
#define  PATTERNGEN_PTG_CMI_CTRL1_VADDR                     	(0xb802217c)
#define  PATTERNGEN_PTG_CMI_CTRL2_VADDR                     	(0xb8022180)
#define  PATTERNGEN_PTG_CMI_CTRL3_VADDR                     	(0xb8022184)
#define  PATTERNGEN_PTG_COLOR_EXTEND1_VADDR                 	(0xb8022188)
#define  PATTERNGEN_PTG_COLOR_EXTEND2_VADDR                 	(0xb802218c)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MACARTHUR3-DESIGNSPEC-I-DOMAIN-PATTERNGEN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  totalh_pixel:13;
        RBus_UInt32  dummy18022100_15_13:3;
        RBus_UInt32  totalv_line:13;
    };
}patterngen_ptg_totalhv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  act_h_sta:13;
        RBus_UInt32  dummy18022104_15_13:3;
        RBus_UInt32  act_wid:13;
    };
}patterngen_ptg_act_h_start_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  act_v_sta:13;
        RBus_UInt32  dummy18022108_15_13:3;
        RBus_UInt32  act_len:13;
    };
}patterngen_ptg_act_v_start_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_sel:4;
        RBus_UInt32  res1:14;
        RBus_UInt32  demo_4k2k_en:1;
        RBus_UInt32  sync_timing_sel:1;
        RBus_UInt32  pat_cover_en:1;
        RBus_UInt32  pat_cover:1;
        RBus_UInt32  hs_highpulse_wid:2;
        RBus_UInt32  dummy1802210c_7:1;
        RBus_UInt32  fix_l_flag:1;
        RBus_UInt32  fix_l_flag_en:1;
        RBus_UInt32  active_space_fix_en:1;
        RBus_UInt32  tg_mode_sel:2;
        RBus_UInt32  tg_en_field:1;
        RBus_UInt32  tg_enable:1;
    };
}patterngen_ptg_tg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  popup_linecnt:1;
        RBus_UInt32  cur_l_flag_out:1;
        RBus_UInt32  cur_field_out:1;
        RBus_UInt32  cur_linecnt_out:13;
    };
}patterngen_ptg_tg_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pat_h_sta_l:13;
        RBus_UInt32  dummy18022114_15_13:3;
        RBus_UInt32  pat_wid_l:13;
    };
}patterngen_ptg_l_pat_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pat_v_sta_l:13;
        RBus_UInt32  dummy18022118_15_13:3;
        RBus_UInt32  pat_len_l:13;
    };
}patterngen_ptg_l_pat_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  ptg_db_rdy:1;
        RBus_UInt32  ptg_db_en:1;
        RBus_UInt32  en_rdm_bkg_l:1;
        RBus_UInt32  xc_seq_l:3;
        RBus_UInt32  en_xc_l:1;
        RBus_UInt32  pat_mode_l:4;
    };
}patterngen_ptg_l_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  auto_state_l:2;
        RBus_UInt32  hold_state_l:2;
        RBus_UInt32  hold_state_rdy_l:1;
        RBus_UInt32  barw_l:11;
    };
}patterngen_ptg_l_barw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c0y_92b_l:8;
        RBus_UInt32  i_c0cr_92b_l:8;
        RBus_UInt32  i_c0cb_92b_l:8;
    };
}patterngen_ptg_l_c0y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c1y_92b_l:8;
        RBus_UInt32  i_c1cr_92b_l:8;
        RBus_UInt32  i_c1cb_92b_l:8;
    };
}patterngen_ptg_l_c1y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c2y_92b_l:8;
        RBus_UInt32  i_c2cr_92b_l:8;
        RBus_UInt32  i_c2cb_92b_l:8;
    };
}patterngen_ptg_l_c2y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c3y_98b_l:2;
        RBus_UInt32  i_c3y_72b_grady_l:6;
        RBus_UInt32  i_c3cr_98b_l:2;
        RBus_UInt32  i_c3cr_72b_gradcr_l:6;
        RBus_UInt32  i_c3cb_98b_l:2;
        RBus_UInt32  i_c3cb_72b_gradcb_l:6;
        RBus_UInt32  dummy18022130_7_0:8;
    };
}patterngen_ptg_l_c3y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c4y_96b_l:4;
        RBus_UInt32  i_c4y_52b_step_hv_l:4;
        RBus_UInt32  i_c4cr_92b_l:8;
        RBus_UInt32  i_c4cb_9b_l:1;
        RBus_UInt32  i_c4cb_86b_bmp_w_l:3;
        RBus_UInt32  i_c4cb_5b_l:1;
        RBus_UInt32  i_c4cb_42b_bmp_h_l:3;
        RBus_UInt32  res1:8;
    };
}patterngen_ptg_l_c4y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c5y_92b_bmptp_l:8;
        RBus_UInt32  i_c5cr_92b_bmp0_l:8;
        RBus_UInt32  i_c5cb_92b_bmp1_l:8;
        RBus_UInt32  dummy18022138_7_0:8;
    };
}patterngen_ptg_l_c5y_cr_cb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c6y_92b_bmp2_l:8;
        RBus_UInt32  i_c6cr_92b_bmp3_l:8;
        RBus_UInt32  i_c6cb_92b_bmp4_l:8;
        RBus_UInt32  nonactive_color_def_l:8;
    };
}patterngen_ptg_l_c6y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c7y_92b_bmp5_l:8;
        RBus_UInt32  i_c7cr_92b_bmp6_l:8;
        RBus_UInt32  i_c7cb_92b_bmp7_l:8;
        RBus_UInt32  dummy18022140_7_3:5;
        RBus_UInt32  max_color_l:3;
    };
}patterngen_ptg_l_c7y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_h_l:8;
        RBus_UInt32  mv_v_l:8;
        RBus_UInt32  mv_seq_type_l:1;
        RBus_UInt32  rdm_period_l:3;
        RBus_UInt32  mv_vs_num_l:4;
        RBus_UInt32  mp_adj_num_l:8;
    };
}patterngen_ptg_l_max_color_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pat_h_sta_r:13;
        RBus_UInt32  dummy18022148_15_13:3;
        RBus_UInt32  pat_wid_r:13;
    };
}patterngen_ptg_r_pat_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pat_v_sta_r:13;
        RBus_UInt32  dummy1802214c_15_13:3;
        RBus_UInt32  pat_len_r:13;
    };
}patterngen_ptg_r_pat_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  en_rdm_bkg_r:1;
        RBus_UInt32  xc_seq_r:3;
        RBus_UInt32  en_xc_r:1;
        RBus_UInt32  pat_mode_r:4;
    };
}patterngen_ptg_r_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  auto_state_r:2;
        RBus_UInt32  hold_state_r:2;
        RBus_UInt32  hold_state_rdy_r:1;
        RBus_UInt32  barw_r:11;
    };
}patterngen_ptg_r_barw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c0y_92b_r:8;
        RBus_UInt32  i_c0cr_92b_r:8;
        RBus_UInt32  i_c0cb_92b_r:8;
    };
}patterngen_ptg_r_c0y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c1y_92b_r:8;
        RBus_UInt32  i_c1cr_92b_r:8;
        RBus_UInt32  i_c1cb_92b_r:8;
    };
}patterngen_ptg_r_c1y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c2y_92b_r:8;
        RBus_UInt32  i_c2cr_92b_r:8;
        RBus_UInt32  i_c2cb_92b_r:8;
    };
}patterngen_ptg_r_c2y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c3y_98b_r:2;
        RBus_UInt32  i_c3y_72b_grady_r:6;
        RBus_UInt32  i_c3cr_98b_r:2;
        RBus_UInt32  i_c3cr_72b_gradcr_r:6;
        RBus_UInt32  i_c3cb_98b_r:2;
        RBus_UInt32  i_c3cb_72b_gradcb_r:6;
        RBus_UInt32  dummy18022164_7_0:8;
    };
}patterngen_ptg_r_c3y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c4y_96b_r:4;
        RBus_UInt32  i_c4y_52b_step_hv_r:4;
        RBus_UInt32  i_c4cr_92b_r:8;
        RBus_UInt32  i_c4cb_9b_r:1;
        RBus_UInt32  i_c4cb_86b_bmp_w_r:3;
        RBus_UInt32  i_c4cb_5b_r:1;
        RBus_UInt32  i_c4cb_42b_bmp_h_r:3;
        RBus_UInt32  res1:8;
    };
}patterngen_ptg_r_c4y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c5y_92b_bmptp_r:8;
        RBus_UInt32  i_c5cr_92b_bmp0_r:8;
        RBus_UInt32  i_c5cb_92b_bmp1_r:8;
        RBus_UInt32  dummy1802216c_7_0:8;
    };
}patterngen_ptg_r_c5y_cr_cb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c6y_92b_bmp2_r:8;
        RBus_UInt32  i_c6cr_92b_bmp3_r:8;
        RBus_UInt32  i_c6cb_92b_bmp4_r:8;
        RBus_UInt32  nonactive_color_def_r:8;
    };
}patterngen_ptg_r_c6y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c7y_92b_bmp5_r:8;
        RBus_UInt32  i_c7cr_92b_bmp6_r:8;
        RBus_UInt32  i_c7cb_92b_bmp7_r:8;
        RBus_UInt32  dummy18022174_7_3:5;
        RBus_UInt32  max_color_r:3;
    };
}patterngen_ptg_r_c7y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_h_r:8;
        RBus_UInt32  mv_v_r:8;
        RBus_UInt32  mv_seq_type_r:1;
        RBus_UInt32  rdm_period_r:3;
        RBus_UInt32  mv_vs_num_r:4;
        RBus_UInt32  mp_adj_num_r:8;
    };
}patterngen_ptg_r_max_color_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  chess_v_size:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  grad_sub_pix_en:1;
        RBus_UInt32  grad_cbar_en:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  grad_cbar_pos:1;
        RBus_UInt32  grad_sub_pix_on_mask:3;
        RBus_UInt32  grad_cbar_step_hv:4;
    };
}patterngen_ptg_cmi_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  y_bright_en:8;
        RBus_UInt32  cb_bright_en:8;
        RBus_UInt32  cr_bright_en:8;
    };
}patterngen_ptg_cmi_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  bmp_sub_pix_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  bright:10;
    };
}patterngen_ptg_cmi_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  color_ext_en:1;
        RBus_UInt32  i_c3y_ext:2;
        RBus_UInt32  i_c3cb_ext:2;
        RBus_UInt32  i_c3cr_ext:2;
        RBus_UInt32  i_c2y_ext:2;
        RBus_UInt32  i_c2cr_ext:2;
        RBus_UInt32  i_c2cb_ext:2;
        RBus_UInt32  i_c1y_ext:2;
        RBus_UInt32  i_c1cr_ext:2;
        RBus_UInt32  i_c1cb_ext:2;
        RBus_UInt32  i_c0y_ext:2;
        RBus_UInt32  i_c0cr_ext:2;
        RBus_UInt32  i_c0cb_ext:2;
    };
}patterngen_ptg_color_extend1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c7y_ext:2;
        RBus_UInt32  i_c7cb_ext:2;
        RBus_UInt32  i_c7cr_ext:2;
        RBus_UInt32  i_c6y_ext:2;
        RBus_UInt32  i_c6cr_ext:2;
        RBus_UInt32  i_c6cb_ext:2;
        RBus_UInt32  i_c5y_ext:2;
        RBus_UInt32  i_c5cr_ext:2;
        RBus_UInt32  i_c5cb_ext:2;
        RBus_UInt32  i_c4y_ext:2;
        RBus_UInt32  i_c4cr_ext:2;
        RBus_UInt32  i_c4cb_ext:2;
    };
}patterngen_ptg_color_extend2_RBUS;

#else //apply LITTLE_ENDIAN

//======MACARTHUR3-DESIGNSPEC-I-DOMAIN-PATTERNGEN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  totalv_line:13;
        RBus_UInt32  dummy18022100_15_13:3;
        RBus_UInt32  totalh_pixel:13;
        RBus_UInt32  res1:3;
    };
}patterngen_ptg_totalhv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  act_wid:13;
        RBus_UInt32  dummy18022104_15_13:3;
        RBus_UInt32  act_h_sta:13;
        RBus_UInt32  res1:3;
    };
}patterngen_ptg_act_h_start_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  act_len:13;
        RBus_UInt32  dummy18022108_15_13:3;
        RBus_UInt32  act_v_sta:13;
        RBus_UInt32  res1:3;
    };
}patterngen_ptg_act_v_start_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_enable:1;
        RBus_UInt32  tg_en_field:1;
        RBus_UInt32  tg_mode_sel:2;
        RBus_UInt32  active_space_fix_en:1;
        RBus_UInt32  fix_l_flag_en:1;
        RBus_UInt32  fix_l_flag:1;
        RBus_UInt32  dummy1802210c_7:1;
        RBus_UInt32  hs_highpulse_wid:2;
        RBus_UInt32  pat_cover:1;
        RBus_UInt32  pat_cover_en:1;
        RBus_UInt32  sync_timing_sel:1;
        RBus_UInt32  demo_4k2k_en:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  cs_sel:4;
    };
}patterngen_ptg_tg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_linecnt_out:13;
        RBus_UInt32  cur_field_out:1;
        RBus_UInt32  cur_l_flag_out:1;
        RBus_UInt32  popup_linecnt:1;
        RBus_UInt32  res1:16;
    };
}patterngen_ptg_tg_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_wid_l:13;
        RBus_UInt32  dummy18022114_15_13:3;
        RBus_UInt32  pat_h_sta_l:13;
        RBus_UInt32  res1:3;
    };
}patterngen_ptg_l_pat_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_len_l:13;
        RBus_UInt32  dummy18022118_15_13:3;
        RBus_UInt32  pat_v_sta_l:13;
        RBus_UInt32  res1:3;
    };
}patterngen_ptg_l_pat_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_mode_l:4;
        RBus_UInt32  en_xc_l:1;
        RBus_UInt32  xc_seq_l:3;
        RBus_UInt32  en_rdm_bkg_l:1;
        RBus_UInt32  ptg_db_en:1;
        RBus_UInt32  ptg_db_rdy:1;
        RBus_UInt32  res1:21;
    };
}patterngen_ptg_l_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  barw_l:11;
        RBus_UInt32  hold_state_rdy_l:1;
        RBus_UInt32  hold_state_l:2;
        RBus_UInt32  auto_state_l:2;
        RBus_UInt32  res1:16;
    };
}patterngen_ptg_l_barw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c0cb_92b_l:8;
        RBus_UInt32  i_c0cr_92b_l:8;
        RBus_UInt32  i_c0y_92b_l:8;
        RBus_UInt32  res1:8;
    };
}patterngen_ptg_l_c0y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c1cb_92b_l:8;
        RBus_UInt32  i_c1cr_92b_l:8;
        RBus_UInt32  i_c1y_92b_l:8;
        RBus_UInt32  res1:8;
    };
}patterngen_ptg_l_c1y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c2cb_92b_l:8;
        RBus_UInt32  i_c2cr_92b_l:8;
        RBus_UInt32  i_c2y_92b_l:8;
        RBus_UInt32  res1:8;
    };
}patterngen_ptg_l_c2y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18022130_7_0:8;
        RBus_UInt32  i_c3cb_72b_gradcb_l:6;
        RBus_UInt32  i_c3cb_98b_l:2;
        RBus_UInt32  i_c3cr_72b_gradcr_l:6;
        RBus_UInt32  i_c3cr_98b_l:2;
        RBus_UInt32  i_c3y_72b_grady_l:6;
        RBus_UInt32  i_c3y_98b_l:2;
    };
}patterngen_ptg_l_c3y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c4cb_42b_bmp_h_l:3;
        RBus_UInt32  i_c4cb_5b_l:1;
        RBus_UInt32  i_c4cb_86b_bmp_w_l:3;
        RBus_UInt32  i_c4cb_9b_l:1;
        RBus_UInt32  i_c4cr_92b_l:8;
        RBus_UInt32  i_c4y_52b_step_hv_l:4;
        RBus_UInt32  i_c4y_96b_l:4;
    };
}patterngen_ptg_l_c4y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18022138_7_0:8;
        RBus_UInt32  i_c5cb_92b_bmp1_l:8;
        RBus_UInt32  i_c5cr_92b_bmp0_l:8;
        RBus_UInt32  i_c5y_92b_bmptp_l:8;
    };
}patterngen_ptg_l_c5y_cr_cb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nonactive_color_def_l:8;
        RBus_UInt32  i_c6cb_92b_bmp4_l:8;
        RBus_UInt32  i_c6cr_92b_bmp3_l:8;
        RBus_UInt32  i_c6y_92b_bmp2_l:8;
    };
}patterngen_ptg_l_c6y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_color_l:3;
        RBus_UInt32  dummy18022140_7_3:5;
        RBus_UInt32  i_c7cb_92b_bmp7_l:8;
        RBus_UInt32  i_c7cr_92b_bmp6_l:8;
        RBus_UInt32  i_c7y_92b_bmp5_l:8;
    };
}patterngen_ptg_l_c7y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mp_adj_num_l:8;
        RBus_UInt32  mv_vs_num_l:4;
        RBus_UInt32  rdm_period_l:3;
        RBus_UInt32  mv_seq_type_l:1;
        RBus_UInt32  mv_v_l:8;
        RBus_UInt32  mv_h_l:8;
    };
}patterngen_ptg_l_max_color_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_wid_r:13;
        RBus_UInt32  dummy18022148_15_13:3;
        RBus_UInt32  pat_h_sta_r:13;
        RBus_UInt32  res1:3;
    };
}patterngen_ptg_r_pat_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_len_r:13;
        RBus_UInt32  dummy1802214c_15_13:3;
        RBus_UInt32  pat_v_sta_r:13;
        RBus_UInt32  res1:3;
    };
}patterngen_ptg_r_pat_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_mode_r:4;
        RBus_UInt32  en_xc_r:1;
        RBus_UInt32  xc_seq_r:3;
        RBus_UInt32  en_rdm_bkg_r:1;
        RBus_UInt32  res1:23;
    };
}patterngen_ptg_r_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  barw_r:11;
        RBus_UInt32  hold_state_rdy_r:1;
        RBus_UInt32  hold_state_r:2;
        RBus_UInt32  auto_state_r:2;
        RBus_UInt32  res1:16;
    };
}patterngen_ptg_r_barw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c0cb_92b_r:8;
        RBus_UInt32  i_c0cr_92b_r:8;
        RBus_UInt32  i_c0y_92b_r:8;
        RBus_UInt32  res1:8;
    };
}patterngen_ptg_r_c0y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c1cb_92b_r:8;
        RBus_UInt32  i_c1cr_92b_r:8;
        RBus_UInt32  i_c1y_92b_r:8;
        RBus_UInt32  res1:8;
    };
}patterngen_ptg_r_c1y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c2cb_92b_r:8;
        RBus_UInt32  i_c2cr_92b_r:8;
        RBus_UInt32  i_c2y_92b_r:8;
        RBus_UInt32  res1:8;
    };
}patterngen_ptg_r_c2y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18022164_7_0:8;
        RBus_UInt32  i_c3cb_72b_gradcb_r:6;
        RBus_UInt32  i_c3cb_98b_r:2;
        RBus_UInt32  i_c3cr_72b_gradcr_r:6;
        RBus_UInt32  i_c3cr_98b_r:2;
        RBus_UInt32  i_c3y_72b_grady_r:6;
        RBus_UInt32  i_c3y_98b_r:2;
    };
}patterngen_ptg_r_c3y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c4cb_42b_bmp_h_r:3;
        RBus_UInt32  i_c4cb_5b_r:1;
        RBus_UInt32  i_c4cb_86b_bmp_w_r:3;
        RBus_UInt32  i_c4cb_9b_r:1;
        RBus_UInt32  i_c4cr_92b_r:8;
        RBus_UInt32  i_c4y_52b_step_hv_r:4;
        RBus_UInt32  i_c4y_96b_r:4;
    };
}patterngen_ptg_r_c4y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802216c_7_0:8;
        RBus_UInt32  i_c5cb_92b_bmp1_r:8;
        RBus_UInt32  i_c5cr_92b_bmp0_r:8;
        RBus_UInt32  i_c5y_92b_bmptp_r:8;
    };
}patterngen_ptg_r_c5y_cr_cb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nonactive_color_def_r:8;
        RBus_UInt32  i_c6cb_92b_bmp4_r:8;
        RBus_UInt32  i_c6cr_92b_bmp3_r:8;
        RBus_UInt32  i_c6y_92b_bmp2_r:8;
    };
}patterngen_ptg_r_c6y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_color_r:3;
        RBus_UInt32  dummy18022174_7_3:5;
        RBus_UInt32  i_c7cb_92b_bmp7_r:8;
        RBus_UInt32  i_c7cr_92b_bmp6_r:8;
        RBus_UInt32  i_c7y_92b_bmp5_r:8;
    };
}patterngen_ptg_r_c7y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mp_adj_num_r:8;
        RBus_UInt32  mv_vs_num_r:4;
        RBus_UInt32  rdm_period_r:3;
        RBus_UInt32  mv_seq_type_r:1;
        RBus_UInt32  mv_v_r:8;
        RBus_UInt32  mv_h_r:8;
    };
}patterngen_ptg_r_max_color_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grad_cbar_step_hv:4;
        RBus_UInt32  grad_sub_pix_on_mask:3;
        RBus_UInt32  grad_cbar_pos:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  grad_cbar_en:1;
        RBus_UInt32  grad_sub_pix_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  chess_v_size:11;
        RBus_UInt32  res3:5;
    };
}patterngen_ptg_cmi_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_bright_en:8;
        RBus_UInt32  cb_bright_en:8;
        RBus_UInt32  y_bright_en:8;
        RBus_UInt32  res1:8;
    };
}patterngen_ptg_cmi_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bright:10;
        RBus_UInt32  res1:1;
        RBus_UInt32  bmp_sub_pix_en:1;
        RBus_UInt32  res2:20;
    };
}patterngen_ptg_cmi_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c0cb_ext:2;
        RBus_UInt32  i_c0cr_ext:2;
        RBus_UInt32  i_c0y_ext:2;
        RBus_UInt32  i_c1cb_ext:2;
        RBus_UInt32  i_c1cr_ext:2;
        RBus_UInt32  i_c1y_ext:2;
        RBus_UInt32  i_c2cb_ext:2;
        RBus_UInt32  i_c2cr_ext:2;
        RBus_UInt32  i_c2y_ext:2;
        RBus_UInt32  i_c3cr_ext:2;
        RBus_UInt32  i_c3cb_ext:2;
        RBus_UInt32  i_c3y_ext:2;
        RBus_UInt32  color_ext_en:1;
        RBus_UInt32  res1:7;
    };
}patterngen_ptg_color_extend1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c4cb_ext:2;
        RBus_UInt32  i_c4cr_ext:2;
        RBus_UInt32  i_c4y_ext:2;
        RBus_UInt32  i_c5cb_ext:2;
        RBus_UInt32  i_c5cr_ext:2;
        RBus_UInt32  i_c5y_ext:2;
        RBus_UInt32  i_c6cb_ext:2;
        RBus_UInt32  i_c6cr_ext:2;
        RBus_UInt32  i_c6y_ext:2;
        RBus_UInt32  i_c7cr_ext:2;
        RBus_UInt32  i_c7cb_ext:2;
        RBus_UInt32  i_c7y_ext:2;
        RBus_UInt32  res1:8;
    };
}patterngen_ptg_color_extend2_RBUS;




#endif 


#endif 
