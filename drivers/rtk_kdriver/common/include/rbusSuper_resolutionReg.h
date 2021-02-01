/**
* @file rbusSuper_resolutionReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2013/2/1
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_SUPER_RESOLUTION_REG_H_
#define _RBUS_SUPER_RESOLUTION_REG_H_

#include "rbusTypes.h"




// SUPER_RESOLUTION Register Address

#define SUPER_RESOLUTION_SR_CTRL_VADDR             (0xb802ab00)
#define SUPER_RESOLUTION_SR_HCOEFF0_VADDR          (0xb802ab04)
#define SUPER_RESOLUTION_SR_HCOEFF1_VADDR          (0xb802ab08)
#define SUPER_RESOLUTION_SR_VCOEFF0_VADDR          (0xb802ab0c)
#define SUPER_RESOLUTION_SR_VCOEFF1_VADDR          (0xb802ab10)
#define SUPER_RESOLUTION_SR_VCOEFF_EVEN0_VADDR     (0xb802ab60)
#define SUPER_RESOLUTION_SR_VCOEFF_EVEN1_VADDR     (0xb802ab64)
#define SUPER_RESOLUTION_SR_FILTER_CTRL0_VADDR     (0xb802ab14)
#define SUPER_RESOLUTION_SR_FILTER_CTRL1_VADDR     (0xb802ab18)
#define SUPER_RESOLUTION_SR_FILTER_CTRL2_VADDR     (0xb802ab1c)
#define SUPER_RESOLUTION_SR_GAINY_CTRL0_VADDR      (0xb802ab20)
#define SUPER_RESOLUTION_SR_GAINY_CTRL1_VADDR      (0xb802ab24)
#define SUPER_RESOLUTION_SR_GAINY_CTRL2_VADDR      (0xb802ab28)
#define SUPER_RESOLUTION_SR_GAINY_CTRL3_VADDR      (0xb802ab2c)
#define SUPER_RESOLUTION_SR_GAINY_CTRL4_VADDR      (0xb802ab30)
#define SUPER_RESOLUTION_SR_GAINMAP_CTRL0_VADDR    (0xb802ab34)
#define SUPER_RESOLUTION_SR_GAINMAP_CTRL1_VADDR    (0xb802ab38)
#define SUPER_RESOLUTION_SR_GAINMAP_CTRL2_VADDR    (0xb802ab3c)
#define SUPER_RESOLUTION_SR_DEBUG0_VADDR           (0xb802ab40)
#define SUPER_RESOLUTION_SR_DEBUG1_VADDR           (0xb802ab44)
#define SUPER_RESOLUTION_SR_DEBUG2_VADDR           (0xb802ab48)
#define SUPER_RESOLUTION_SR_CRC_CTRL1_VADDR        (0xb802ab4c)
#define SUPER_RESOLUTION_SR_CRC_RESULT1_VADDR      (0xb802ab50)
#define SUPER_RESOLUTION_SR_DB_CTRL_VADDR          (0xb802ab54)
#define SUPER_RESOLUTION_SR_CTRL_1_VADDR           (0xb802ab58)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======SUPER_RESOLUTION register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_maxmin_shift:8;
        RBus_UInt32  sr_var_thd:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  sr_intp_hphase:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  sr_intp_vphase:2;
        RBus_UInt32  sr_intp_vtoggle_en:1;
        RBus_UInt32  sr_intp_vphase_even:2;
        RBus_UInt32  sr_ver_mode:1;
        RBus_UInt32  sr_maxmin_limit_en:1;
        RBus_UInt32  res3:3;
    };
}sr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_hor_c0_0:8;
        RBus_UInt32  sr_hor_c0_1:8;
        RBus_UInt32  sr_hor_c0_2:8;
        RBus_UInt32  sr_hor_c0_3:8;
    };
}sr_hcoeff0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_hor_c1_0:8;
        RBus_UInt32  sr_hor_c1_1:8;
        RBus_UInt32  sr_hor_c1_2:8;
        RBus_UInt32  sr_hor_c1_3:8;
    };
}sr_hcoeff1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_ver_c0_0:8;
        RBus_UInt32  sr_ver_c0_1:8;
        RBus_UInt32  sr_ver_c0_2:8;
        RBus_UInt32  sr_ver_c0_3:8;
    };
}sr_vcoeff0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_ver_c1_0:8;
        RBus_UInt32  sr_ver_c1_1:8;
        RBus_UInt32  sr_ver_c1_2:8;
        RBus_UInt32  sr_ver_c1_3:8;
    };
}sr_vcoeff1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_ver_c0_even_0:8;
        RBus_UInt32  sr_ver_c0_even_1:8;
        RBus_UInt32  sr_ver_c0_even_2:8;
        RBus_UInt32  sr_ver_c0_even_3:8;
    };
}sr_vcoeff_even0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_ver_c1_even_0:8;
        RBus_UInt32  sr_ver_c1_even_1:8;
        RBus_UInt32  sr_ver_c1_even_2:8;
        RBus_UInt32  sr_ver_c1_even_3:8;
    };
}sr_vcoeff_even1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sr_maxmin_thd:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  sr_maxmin_mode:1;
        RBus_UInt32  sr_maxmin_range:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sr_delta_gain:2;
        RBus_UInt32  sr_edge_range:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  sr_lpf_range:1;
    };
}sr_filter_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_thd0:8;
        RBus_UInt32  sr_bif_thd1:8;
        RBus_UInt32  sr_bif_thd2:8;
        RBus_UInt32  sr_bif_thd3:8;
    };
}sr_filter_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_thd4:8;
        RBus_UInt32  sr_bif_thd5:8;
        RBus_UInt32  sr_bif_thd6:8;
        RBus_UInt32  sr_bif_thd7:8;
    };
}sr_filter_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_pgain0:8;
        RBus_UInt32  sr_by_ngain0:8;
        RBus_UInt32  sr_lpf_gain:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  sr_bif_gain:6;
        RBus_UInt32  sr_diffdir_cond_en:1;
        RBus_UInt32  sr_by_gain_en:1;
    };
}sr_gainy_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_pgain1:8;
        RBus_UInt32  sr_by_pgain2:8;
        RBus_UInt32  sr_by_pgain3:8;
        RBus_UInt32  sr_by_pgain4:8;
    };
}sr_gainy_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_pgain5:8;
        RBus_UInt32  sr_by_pgain6:8;
        RBus_UInt32  sr_by_pgain7:8;
        RBus_UInt32  sr_by_pgain8:8;
    };
}sr_gainy_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_ngain1:8;
        RBus_UInt32  sr_by_ngain2:8;
        RBus_UInt32  sr_by_ngain3:8;
        RBus_UInt32  sr_by_ngain4:8;
    };
}sr_gainy_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_ngain5:8;
        RBus_UInt32  sr_by_ngain6:8;
        RBus_UInt32  sr_by_ngain7:8;
        RBus_UInt32  sr_by_ngain8:8;
    };
}sr_gainy_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_lpf_range_thd:8;
        RBus_UInt32  sr_lpf_range_gain:5;
        RBus_UInt32  sr_lpf_range_step:2;
        RBus_UInt32  sr_lpf_range_en:1;
        RBus_UInt32  sr_lpf_edge_thd:8;
        RBus_UInt32  sr_lpf_edge_gain:5;
        RBus_UInt32  sr_lpf_edge_step:2;
        RBus_UInt32  sr_lpf_edge_en:1;
    };
}sr_gainmap_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_range_thd0:8;
        RBus_UInt32  sr_bif_range_thd1:8;
        RBus_UInt32  sr_bif_range_gain0:5;
        RBus_UInt32  sr_bif_range_step0:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  sr_bif_range_gain1:5;
        RBus_UInt32  sr_bif_range_step1:2;
        RBus_UInt32  sr_bif_range_en:1;
    };
}sr_gainmap_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sr_bif_edge_thd:8;
        RBus_UInt32  sr_bif_edge_gain:5;
        RBus_UInt32  sr_bif_edge_step:2;
        RBus_UInt32  sr_bif_edge_en:1;
    };
}sr_gainmap_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  sr_dbg_mode:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  sr_dbg_inv:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sr_dbg_en:1;
    };
}sr_debug0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  sr_dbg_h_sta:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  sr_dbg_h_end:12;
    };
}sr_debug1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  sr_dbg_v_sta:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  sr_dbg_v_end:12;
    };
}sr_debug2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802ab4c_31_2:30;
        RBus_UInt32  sr_crc_conti:1;
        RBus_UInt32  sr_crc_start:1;
    };
}sr_crc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_crc_cur_result:32;
    };
}sr_crc_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_apply:1;
    };
}sr_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lr_black_en:1;
        RBus_UInt32  lr_black_sel:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  in_black_en:1;
        RBus_UInt32  in_even_black:1;
        RBus_UInt32  res3:6;
        RBus_UInt32  out_black_en:1;
        RBus_UInt32  out_even_black:1;
    };
}sr_ctrl_1_RBUS;





#else //apply LITTLE_ENDIAN


//======SUPER_RESOLUTION register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res3:3;
        RBus_UInt32  sr_maxmin_limit_en:1;
        RBus_UInt32  sr_ver_mode:1;
        RBus_UInt32  sr_intp_vphase_even:2;
        RBus_UInt32  sr_intp_vtoggle_en:1;
        RBus_UInt32  sr_intp_vphase:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  sr_intp_hphase:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  sr_var_thd:8;
        RBus_UInt32  sr_maxmin_shift:8;
    };
}sr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_hor_c0_3:8;
        RBus_UInt32  sr_hor_c0_2:8;
        RBus_UInt32  sr_hor_c0_1:8;
        RBus_UInt32  sr_hor_c0_0:8;
    };
}sr_hcoeff0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_hor_c1_3:8;
        RBus_UInt32  sr_hor_c1_2:8;
        RBus_UInt32  sr_hor_c1_1:8;
        RBus_UInt32  sr_hor_c1_0:8;
    };
}sr_hcoeff1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_ver_c0_3:8;
        RBus_UInt32  sr_ver_c0_2:8;
        RBus_UInt32  sr_ver_c0_1:8;
        RBus_UInt32  sr_ver_c0_0:8;
    };
}sr_vcoeff0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_ver_c1_3:8;
        RBus_UInt32  sr_ver_c1_2:8;
        RBus_UInt32  sr_ver_c1_1:8;
        RBus_UInt32  sr_ver_c1_0:8;
    };
}sr_vcoeff1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_ver_c0_even_3:8;
        RBus_UInt32  sr_ver_c0_even_2:8;
        RBus_UInt32  sr_ver_c0_even_1:8;
        RBus_UInt32  sr_ver_c0_even_0:8;
    };
}sr_vcoeff_even0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_ver_c1_even_3:8;
        RBus_UInt32  sr_ver_c1_even_2:8;
        RBus_UInt32  sr_ver_c1_even_1:8;
        RBus_UInt32  sr_ver_c1_even_0:8;
    };
}sr_vcoeff_even1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_lpf_range:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  sr_edge_range:1;
        RBus_UInt32  sr_delta_gain:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  sr_maxmin_range:1;
        RBus_UInt32  sr_maxmin_mode:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  sr_maxmin_thd:8;
        RBus_UInt32  res1:8;
    };
}sr_filter_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_thd3:8;
        RBus_UInt32  sr_bif_thd2:8;
        RBus_UInt32  sr_bif_thd1:8;
        RBus_UInt32  sr_bif_thd0:8;
    };
}sr_filter_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_thd7:8;
        RBus_UInt32  sr_bif_thd6:8;
        RBus_UInt32  sr_bif_thd5:8;
        RBus_UInt32  sr_bif_thd4:8;
    };
}sr_filter_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_gain_en:1;
        RBus_UInt32  sr_diffdir_cond_en:1;
        RBus_UInt32  sr_bif_gain:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  sr_lpf_gain:6;
        RBus_UInt32  sr_by_ngain0:8;
        RBus_UInt32  sr_by_pgain0:8;
    };
}sr_gainy_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_pgain4:8;
        RBus_UInt32  sr_by_pgain3:8;
        RBus_UInt32  sr_by_pgain2:8;
        RBus_UInt32  sr_by_pgain1:8;
    };
}sr_gainy_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_pgain8:8;
        RBus_UInt32  sr_by_pgain7:8;
        RBus_UInt32  sr_by_pgain6:8;
        RBus_UInt32  sr_by_pgain5:8;
    };
}sr_gainy_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_ngain4:8;
        RBus_UInt32  sr_by_ngain3:8;
        RBus_UInt32  sr_by_ngain2:8;
        RBus_UInt32  sr_by_ngain1:8;
    };
}sr_gainy_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_ngain8:8;
        RBus_UInt32  sr_by_ngain7:8;
        RBus_UInt32  sr_by_ngain6:8;
        RBus_UInt32  sr_by_ngain5:8;
    };
}sr_gainy_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_lpf_edge_en:1;
        RBus_UInt32  sr_lpf_edge_step:2;
        RBus_UInt32  sr_lpf_edge_gain:5;
        RBus_UInt32  sr_lpf_edge_thd:8;
        RBus_UInt32  sr_lpf_range_en:1;
        RBus_UInt32  sr_lpf_range_step:2;
        RBus_UInt32  sr_lpf_range_gain:5;
        RBus_UInt32  sr_lpf_range_thd:8;
    };
}sr_gainmap_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_range_en:1;
        RBus_UInt32  sr_bif_range_step1:2;
        RBus_UInt32  sr_bif_range_gain1:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  sr_bif_range_step0:2;
        RBus_UInt32  sr_bif_range_gain0:5;
        RBus_UInt32  sr_bif_range_thd1:8;
        RBus_UInt32  sr_bif_range_thd0:8;
    };
}sr_gainmap_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_edge_en:1;
        RBus_UInt32  sr_bif_edge_step:2;
        RBus_UInt32  sr_bif_edge_gain:5;
        RBus_UInt32  sr_bif_edge_thd:8;
        RBus_UInt32  res1:16;
    };
}sr_gainmap_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_dbg_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sr_dbg_inv:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sr_dbg_mode:4;
        RBus_UInt32  res1:20;
    };
}sr_debug0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_dbg_h_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  sr_dbg_h_sta:12;
        RBus_UInt32  res1:4;
    };
}sr_debug1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_dbg_v_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  sr_dbg_v_sta:12;
        RBus_UInt32  res1:4;
    };
}sr_debug2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_crc_start:1;
        RBus_UInt32  sr_crc_conti:1;
        RBus_UInt32  dummy1802ab4c_31_2:30;
    };
}sr_crc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_crc_cur_result:32;
    };
}sr_crc_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  res1:29;
    };
}sr_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  out_even_black:1;
        RBus_UInt32  out_black_en:1;
        RBus_UInt32  res3:6;
        RBus_UInt32  in_even_black:1;
        RBus_UInt32  in_black_en:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  lr_black_sel:1;
        RBus_UInt32  lr_black_en:1;
        RBus_UInt32  res1:14;
    };
}sr_ctrl_1_RBUS;


#endif







#endif //_RBUS_SUPER_RESOLUTION_REG_H_

