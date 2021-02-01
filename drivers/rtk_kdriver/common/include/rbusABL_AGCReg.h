/**
* @file rbusAblReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2013/2/25
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_ABL_REG_H_
#define _RBUS_ABL_REG_H_

#include "rbusTypes.h"




// ABL Register Address

#define ABL_AGC_ABL_CTRL_VADDR                         (0xb8020200)
#define ABL_AGC_ABL_WINDOW_VADDR                       (0xb8020204)
#define ABL_AGC_ABL_STATUS_VADDR                       (0xb8020208)
#define ABL_AGC_RESERVED_VADDR                         (0xb802020c)
#define ABL_AGC_ABL_RSLT0_VADDR                        (0xb8020210)
#define ABL_AGC_ABL_RSLT1_VADDR                        (0xb8020214)
#define ABL_AGC_AUTO_OFST_RD0_ABL_NOISE_VAL0_VADDR     (0xb8020218)
#define ABL_AGC_AUTO_OFST_RD1_ABL_NOISE_VAL1_VADDR     (0xb802021c)
#define ABL_AGC_ABL_MGN_RG_VADDR                       (0xb8020220)
#define ABL_AGC_ABL_MGN_B_VADDR                        (0xb8020224)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======ABL register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_en:1;
        RBus_UInt32  abl_red_en:1;
        RBus_UInt32  abl_grn_en:1;
        RBus_UInt32  abl_blu_en:1;
        RBus_UInt32  dummy18000200_27:1;
        RBus_UInt32  abl_software_mode:1;
        RBus_UInt32  abl_min_measure:1;
        RBus_UInt32  abl_ypbpr_en:1;
        RBus_UInt32  abl_online_mode:1;
        RBus_UInt32  dummy18000200_22:1;
        RBus_UInt32  abl_max_frame:2;
        RBus_UInt32  abl_rgb_dir_inv:3;
        RBus_UInt32  abl_href_sel:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  abl_target_value:4;
        RBus_UInt32  dummy18000200_7_6:2;
        RBus_UInt32  res2:6;
    };
}abl_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18000204_31_30:2;
        RBus_UInt32  abl_vend:10;
        RBus_UInt32  abl_wait_line:3;
        RBus_UInt32  abl_vsta:5;
        RBus_UInt32  abl_line:2;
        RBus_UInt32  abl_h_width:2;
        RBus_UInt32  abl_start_pos:8;
    };
}abl_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_meas_err_flag_rst:1;
        RBus_UInt32  abl_meas_err_flag:1;
        RBus_UInt32  res1:18;
        RBus_UInt32  abl_state:4;
        RBus_UInt32  res2:5;
        RBus_UInt32  abl_red_equal:1;
        RBus_UInt32  abl_grn_equal:1;
        RBus_UInt32  abl_blu_equal:1;
    };
}abl_status_RBUS;

/*
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy0c_31_0:32;
    };
}abl_Reserved_RBUS;
*/

typedef union
{
    RBus_UInt32 regValue;
    struct{
        //RBus_UInt32  dummy1802020c_31_0:32;
        RBus_UInt32  AGC_Peak_en:1;
        RBus_UInt32  Test_Mode_en:1;
        RBus_UInt32  Self_AWB_code_diff_G:10;
        RBus_UInt32  Self_AWB_code_diff_R:10;
        RBus_UInt32  Self_AWB_code_diff_B:10;
    };
}abl_Reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  abl_r_l_avg_min:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  abl_g_l_avg_min:10;
    };
}abl_rslt0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  abl_b_l_avg_min:10;
    };
}abl_rslt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  abl_red_diff2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  abl_grn_diff2:10;
    };
}auto_ofst_rd0_abl_noise_val0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  abl_blu_diff2:10;
    };
}auto_ofst_rd1_abl_noise_val1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  abl_eq_mgn_red:5;
        RBus_UInt32  abl_l_mgn_red:5;
        RBus_UInt32  abl_lock_mgn_red:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  abl_eq_mgn_grn:5;
        RBus_UInt32  abl_l_mgn_grn:5;
        RBus_UInt32  abl_lock_mgn_grn:5;
    };
}abl_mgn_rg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  coarse_tune_en:1;
        RBus_UInt32  adj_method:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  adj_ratio:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  abl_eq_mgn_blu:5;
        RBus_UInt32  abl_l_mgn_blu:5;
        RBus_UInt32  abl_lock_mgn_blu:5;
    };
}abl_mgn_b_RBUS;





#else //apply LITTLE_ENDIAN


//======ABL register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:6;
        RBus_UInt32  dummy18000200_7_6:2;
        RBus_UInt32  abl_target_value:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  abl_href_sel:1;
        RBus_UInt32  abl_rgb_dir_inv:3;
        RBus_UInt32  abl_max_frame:2;
        RBus_UInt32  dummy18000200_22:1;
        RBus_UInt32  abl_online_mode:1;
        RBus_UInt32  abl_ypbpr_en:1;
        RBus_UInt32  abl_min_measure:1;
        RBus_UInt32  abl_software_mode:1;
        RBus_UInt32  dummy18000200_27:1;
        RBus_UInt32  abl_blu_en:1;
        RBus_UInt32  abl_grn_en:1;
        RBus_UInt32  abl_red_en:1;
        RBus_UInt32  abl_en:1;
    };
}abl_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_start_pos:8;
        RBus_UInt32  abl_h_width:2;
        RBus_UInt32  abl_line:2;
        RBus_UInt32  abl_vsta:5;
        RBus_UInt32  abl_wait_line:3;
        RBus_UInt32  abl_vend:10;
        RBus_UInt32  dummy18000204_31_30:2;
    };
}abl_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_blu_equal:1;
        RBus_UInt32  abl_grn_equal:1;
        RBus_UInt32  abl_red_equal:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  abl_state:4;
        RBus_UInt32  res1:18;
        RBus_UInt32  abl_meas_err_flag:1;
        RBus_UInt32  abl_meas_err_flag_rst:1;
    };
}abl_status_RBUS;

/*
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy0c_31_0:32;
    };
}abl_Reserved_RBUS;
*/

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Self_AWB_code_diff_B:10;
        RBus_UInt32  Self_AWB_code_diff_R:10;
        RBus_UInt32  Self_AWB_code_diff_G:10;
        RBus_UInt32  Test_Mode_en:1;
        RBus_UInt32  AGC_Peak_en:1;
        //RBus_UInt32  dummy1802020c_31_0:32;
    };
}abl_Reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_g_l_avg_min:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  abl_r_l_avg_min:10;
        RBus_UInt32  res1:6;
    };
}abl_rslt0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_b_l_avg_min:10;
        RBus_UInt32  res1:22;
    };
}abl_rslt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_grn_diff2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  abl_red_diff2:10;
        RBus_UInt32  res1:6;
    };
}auto_ofst_rd0_abl_noise_val0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_blu_diff2:10;
        RBus_UInt32  res1:22;
    };
}auto_ofst_rd1_abl_noise_val1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_lock_mgn_grn:5;
        RBus_UInt32  abl_l_mgn_grn:5;
        RBus_UInt32  abl_eq_mgn_grn:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  abl_lock_mgn_red:5;
        RBus_UInt32  abl_l_mgn_red:5;
        RBus_UInt32  abl_eq_mgn_red:5;
        RBus_UInt32  res1:1;
    };
}abl_mgn_rg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_lock_mgn_blu:5;
        RBus_UInt32  abl_l_mgn_blu:5;
        RBus_UInt32  abl_eq_mgn_blu:5;
        RBus_UInt32  res3:1;
        RBus_UInt32  adj_ratio:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  adj_method:1;
        RBus_UInt32  coarse_tune_en:1;
        RBus_UInt32  res1:6;
    };
}abl_mgn_b_RBUS;


#endif







#endif //_RBUS_ABL_REG_H_

