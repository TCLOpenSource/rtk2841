/**
* @file rbusPeakingReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2012-11-7
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_PEAKING_REG_H_
#define _RBUS_PEAKING_REG_H_

#include "rbus/rbusTypes.h"




// PEAKING Register Address
#define PEAKING_ICH1_PEAKING_FILTER_ADDR           (0x18023100)
#define PEAKING_ICH1_PEAKING_GAIN_ADDR             (0x18023104)
#define PEAKING_ICH1_PEAKING_BOUND_ADDR            (0x18023108)
#define PEAKING_ICH1_DCTI_OPTIONS_ADDR             (0x18023118)
#define PEAKING_ICH1_DCTI_1ST_VALUE_ADDR           (0x1802311c)
#define PEAKING_ICH1_DCTI_2ND_VALUE_ADDR           (0x18023120)
#define PEAKING_ICH1_MPEGNR1_ADDR                  (0x18023124)
#define PEAKING_ICH1_MPEGNR2_ADDR                  (0x18023128)
#define PEAKING_ICH1_HIST_BLKING_HOR_RANGE_ADDR    (0x1802312c)
#define PEAKING_ICH1_HIST_BLKING_VER_RANGE_ADDR    (0x18023130)
#define PEAKING_ICH1_MPEGSTART_ADDR                (0x18023134)
#define PEAKING_ICH1_CNTHOR0_ADDR                  (0x18023138)
#define PEAKING_ICH1_CNTHOR2_ADDR                  (0x1802313c)
#define PEAKING_ICH1_CNTHOR4_ADDR                  (0x18023140)
#define PEAKING_ICH1_CNTHOR6_ADDR                  (0x18023144)
#define PEAKING_I_DLTI_CTRL_ADDR                   (0x18023170)
#define PEAKING_ICH1_DLTI_TH_ADDR                  (0x18023174)
#define PEAKING_ICH1_DLTI_C0_ADDR                  (0x18023178)
#define PEAKING_ICH1_DLTI_C2_ADDR                  (0x1802317c)
#define PEAKING_ICH1_DLTI_C4_ADDR                  (0x18023180)
#define PEAKING_FSYNC_GENERAL_CTRL1_ADDR           (0x180231a0)
#define PEAKING_FSYNC_GENERAL_CTRL2_ADDR           (0x180231a4)
#define PEAKING_FSYNC_GENERAL_CTRL3_ADDR           (0x180231a8)
#define PEAKING_FSYNC_GENERAL_CTRL4_ADDR           (0x180231ac)
#define PEAKING_ICH1_ACCESSDATA_CTRL_PK_ADDR       (0x180231b0)
#define PEAKING_ICH1_ACCESSDATA_POSCTRL_PK_ADDR    (0x180231b4)
#define PEAKING_ICH1_READDATA_DATA_Y1_PK_ADDR      (0x180231b8)
#define PEAKING_ICH1_READDATA_DATA_Y2_PK_ADDR      (0x180231bc)
#define PEAKING_ICH1_READDATA_DATA_C1_PK_ADDR      (0x180231c0)
#define PEAKING_ICH1_READDATA_DATA_C2_PK_ADDR      (0x180231c4)
#define PEAKING_ICH1_READDATA_DATA_C3_PK_ADDR      (0x180231c8)
#define PEAKING_ICH1_READDATA_DATA_C4_PK_ADDR      (0x180231cc)
#define PEAKING_ICH1_WRITEDATA_DATA_PK_ADDR        (0x180231d0)
#define PEAKING_I_DCTI_CTRL_1_ADDR                 (0x180231f8)
#define PEAKING_ICH1_GENERAL_DB_CTRL_ADDR          (0x180231fc)

#define PEAKING_ICH1_PEAKING_FILTER_VADDR          (0xb8023100)
#define PEAKING_ICH1_PEAKING_GAIN_VADDR            (0xb8023104)
#define PEAKING_ICH1_PEAKING_BOUND_VADDR           (0xb8023108)
#define PEAKING_ICH1_DCTI_OPTIONS_VADDR            (0xb8023118)
#define PEAKING_ICH1_DCTI_1ST_VALUE_VADDR          (0xb802311c)
#define PEAKING_ICH1_DCTI_2ND_VALUE_VADDR          (0xb8023120)
#define PEAKING_ICH1_MPEGNR1_VADDR                 (0xb8023124)
#define PEAKING_ICH1_MPEGNR2_VADDR                 (0xb8023128)
#define PEAKING_ICH1_HIST_BLKING_HOR_RANGE_VADDR   (0xb802312c)
#define PEAKING_ICH1_HIST_BLKING_VER_RANGE_VADDR   (0xb8023130)
#define PEAKING_ICH1_MPEGSTART_VADDR               (0xb8023134)
#define PEAKING_ICH1_CNTHOR0_VADDR                 (0xb8023138)
#define PEAKING_ICH1_CNTHOR2_VADDR                 (0xb802313c)
#define PEAKING_ICH1_CNTHOR4_VADDR                 (0xb8023140)
#define PEAKING_ICH1_CNTHOR6_VADDR                 (0xb8023144)
#define PEAKING_I_DLTI_CTRL_VADDR                  (0xb8023170)
#define PEAKING_ICH1_DLTI_TH_VADDR                 (0xb8023174)
#define PEAKING_ICH1_DLTI_C0_VADDR                 (0xb8023178)
#define PEAKING_ICH1_DLTI_C2_VADDR                 (0xb802317c)
#define PEAKING_ICH1_DLTI_C4_VADDR                 (0xb8023180)
#define PEAKING_FSYNC_GENERAL_CTRL1_VADDR          (0xb80231a0)
#define PEAKING_FSYNC_GENERAL_CTRL2_VADDR          (0xb80231a4)
#define PEAKING_FSYNC_GENERAL_CTRL3_VADDR          (0xb80231a8)
#define PEAKING_FSYNC_GENERAL_CTRL4_VADDR          (0xb80231ac)
#define PEAKING_ICH1_ACCESSDATA_CTRL_PK_VADDR      (0xb80231b0)
#define PEAKING_ICH1_ACCESSDATA_POSCTRL_PK_VADDR   (0xb80231b4)
#define PEAKING_ICH1_READDATA_DATA_Y1_PK_VADDR     (0xb80231b8)
#define PEAKING_ICH1_READDATA_DATA_Y2_PK_VADDR     (0xb80231bc)
#define PEAKING_ICH1_READDATA_DATA_C1_PK_VADDR     (0xb80231c0)
#define PEAKING_ICH1_READDATA_DATA_C2_PK_VADDR     (0xb80231c4)
#define PEAKING_ICH1_READDATA_DATA_C3_PK_VADDR     (0xb80231c8)
#define PEAKING_ICH1_READDATA_DATA_C4_PK_VADDR     (0xb80231cc)
#define PEAKING_ICH1_WRITEDATA_DATA_PK_VADDR       (0xb80231d0)
#define PEAKING_I_DCTI_CTRL_1_VADDR                (0xb80231f8)
#define PEAKING_ICH1_GENERAL_DB_CTRL_VADDR         (0xb80231fc)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======PEAKING register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  peaking_enable:1;
        RBus_UInt32  pxlsel:2;
        RBus_UInt32  c0:8;
        RBus_UInt32  c1:8;
        RBus_UInt32  c2:8;
    };
}ich1_peaking_filter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  gain_blr:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}ich1_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  lv:8;
    };
}ich1_peaking_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_enable:1;
        RBus_UInt32  res1:29;
        RBus_UInt32  prevent_pe:1;
        RBus_UInt32  enabled:1;
    };
}ich1_dcti_options_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  th_value:6;
        RBus_UInt32  gain_value:5;
    };
}ich1_dcti_1st_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  th_value:6;
        RBus_UInt32  gain_value:5;
    };
}ich1_dcti_2nd_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dummy18023124_27_24:4;
        RBus_UInt32  cp_mpgupperbound_x:8;
        RBus_UInt32  res2:16;
    };
}ich1_mpegnr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpgdcgain:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_mpgdcqp:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  cp_mpgfiltersel1:1;
        RBus_UInt32  cp_mpgfiltersel2:1;
        RBus_UInt32  cp_mpgidxmode_x:1;
        RBus_UInt32  cp_mpgidx_x:3;
        RBus_UInt32  cp_mpegresultweight_x:3;
        RBus_UInt32  cp_mpegenable_x:1;
    };
}ich1_mpegnr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_histhorend:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_histhorstart:14;
    };
}ich1_hist_blking_hor_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_histverend:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_histverstart:14;
    };
}ich1_hist_blking_ver_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  cp_histhoren:1;
    };
}ich1_mpegstart_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_cnthor1:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_cnthor0:14;
    };
}ich1_cnthor0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_cnthor3:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_cnthor2:14;
    };
}ich1_cnthor2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_cnthor5:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_cnthor4:14;
    };
}ich1_cnthor4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_cnthor7:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_cnthor6:14;
    };
}ich1_cnthor6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dummy18023170_29_26:4;
        RBus_UInt32  new_function_blend:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  undo_pixel:2;
        RBus_UInt32  res3:5;
        RBus_UInt32  ch1_dlti_gain:6;
        RBus_UInt32  ch1_lope_search_range_left:2;
        RBus_UInt32  ch1_lope_search_range_right:2;
        RBus_UInt32  ch1_mean_search_range:2;
        RBus_UInt32  ch1_lope_det_en:1;
        RBus_UInt32  ch1_filter_det_en:1;
        RBus_UInt32  ch1_dlti_en:1;
    };
}i_dlti_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_upper_th:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_lower_th:10;
    };
}ich1_dlti_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ch1_filter_c1:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  ch1_filter_c0:9;
    };
}ich1_dlti_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ch1_filter_c3:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  ch1_filter_c2:9;
    };
}ich1_dlti_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  ch1_filter_c4:9;
    };
}ich1_dlti_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  fsync_general_standard_num:17;
        RBus_UInt32  res2:6;
        RBus_UInt32  fsync_general_en:1;
        RBus_UInt32  fsync_general_line_num:5;
    };
}fsync_general_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsync_debug_en:1;
        RBus_UInt32  res1:18;
        RBus_UInt32  fsync_general_delta_ratio:13;
    };
}fsync_general_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measure_result_tmp:17;
        RBus_UInt32  delta_trunc:15;
    };
}fsync_general_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measult_result:32;
    };
}fsync_general_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}ich1_accessdata_ctrl_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  starty:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  startx:14;
    };
}ich1_accessdata_posctrl_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y00:10;
    };
}ich1_readdata_data_y1_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y10:10;
    };
}ich1_readdata_data_y2_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u00:10;
    };
}ich1_readdata_data_c1_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u01:10;
    };
}ich1_readdata_data_c2_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u10:10;
    };
}ich1_readdata_data_c3_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u11:10;
    };
}ich1_readdata_data_c4_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  v:4;
        RBus_UInt32  u:4;
        RBus_UInt32  y:4;
    };
}ich1_writedata_data_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  maxlen:3;
        RBus_UInt32  psmth:10;
        RBus_UInt32  lpmode:2;
        RBus_UInt32  engdiv:2;
        RBus_UInt32  offdiv:2;
        RBus_UInt32  uvgain:6;
        RBus_UInt32  dcti_mode:1;
        RBus_UInt32  dummy180231f8_2:1;
        RBus_UInt32  cur_sel:1;
        RBus_UInt32  dcti_en:1;
    };
}i_dcti_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  general_db_apply:1;
        RBus_UInt32  general_db_rd_sel:1;
        RBus_UInt32  general_db_en:1;
    };
}ich1_general_db_ctrl_RBUS;





#else //apply LITTLE_ENDIAN


//======PEAKING register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c2:8;
        RBus_UInt32  c1:8;
        RBus_UInt32  c0:8;
        RBus_UInt32  pxlsel:2;
        RBus_UInt32  peaking_enable:1;
        RBus_UInt32  res1:5;
    };
}ich1_peaking_filter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_blr:8;
        RBus_UInt32  res1:8;
    };
}ich1_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv:8;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  res1:4;
    };
}ich1_peaking_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enabled:1;
        RBus_UInt32  prevent_pe:1;
        RBus_UInt32  res1:29;
        RBus_UInt32  dcti_enable:1;
    };
}ich1_dcti_options_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_value:5;
        RBus_UInt32  th_value:6;
        RBus_UInt32  res1:21;
    };
}ich1_dcti_1st_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_value:5;
        RBus_UInt32  th_value:6;
        RBus_UInt32  res1:21;
    };
}ich1_dcti_2nd_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:16;
        RBus_UInt32  cp_mpgupperbound_x:8;
        RBus_UInt32  dummy18023124_27_24:4;
        RBus_UInt32  res1:4;
    };
}ich1_mpegnr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpegenable_x:1;
        RBus_UInt32  cp_mpegresultweight_x:3;
        RBus_UInt32  cp_mpgidx_x:3;
        RBus_UInt32  cp_mpgidxmode_x:1;
        RBus_UInt32  cp_mpgfiltersel2:1;
        RBus_UInt32  cp_mpgfiltersel1:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  cp_mpgdcqp:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_mpgdcgain:4;
    };
}ich1_mpegnr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histhorstart:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_histhorend:14;
        RBus_UInt32  res1:2;
    };
}ich1_hist_blking_hor_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histverstart:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_histverend:14;
        RBus_UInt32  res1:2;
    };
}ich1_hist_blking_ver_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histhoren:1;
        RBus_UInt32  res1:31;
    };
}ich1_mpegstart_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor0:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_cnthor1:14;
        RBus_UInt32  res1:2;
    };
}ich1_cnthor0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor2:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_cnthor3:14;
        RBus_UInt32  res1:2;
    };
}ich1_cnthor2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor4:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_cnthor5:14;
        RBus_UInt32  res1:2;
    };
}ich1_cnthor4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor6:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_cnthor7:14;
        RBus_UInt32  res1:2;
    };
}ich1_cnthor6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_dlti_en:1;
        RBus_UInt32  ch1_filter_det_en:1;
        RBus_UInt32  ch1_lope_det_en:1;
        RBus_UInt32  ch1_mean_search_range:2;
        RBus_UInt32  ch1_lope_search_range_right:2;
        RBus_UInt32  ch1_lope_search_range_left:2;
        RBus_UInt32  ch1_dlti_gain:6;
        RBus_UInt32  res3:5;
        RBus_UInt32  undo_pixel:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  new_function_blend:1;
        RBus_UInt32  dummy18023170_29_26:4;
        RBus_UInt32  res1:2;
    };
}i_dlti_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_lower_th:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_upper_th:10;
        RBus_UInt32  res1:6;
    };
}ich1_dlti_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_filter_c0:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  ch1_filter_c1:9;
        RBus_UInt32  res1:7;
    };
}ich1_dlti_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_filter_c2:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  ch1_filter_c3:9;
        RBus_UInt32  res1:7;
    };
}ich1_dlti_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_filter_c4:9;
        RBus_UInt32  res1:23;
    };
}ich1_dlti_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsync_general_line_num:5;
        RBus_UInt32  fsync_general_en:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  fsync_general_standard_num:17;
        RBus_UInt32  res1:3;
    };
}fsync_general_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsync_general_delta_ratio:13;
        RBus_UInt32  res1:18;
        RBus_UInt32  fsync_debug_en:1;
    };
}fsync_general_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delta_trunc:15;
        RBus_UInt32  measure_result_tmp:17;
    };
}fsync_general_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measult_result:32;
    };
}fsync_general_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  res1:30;
    };
}ich1_accessdata_ctrl_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startx:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  starty:14;
        RBus_UInt32  res1:2;
    };
}ich1_accessdata_posctrl_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res1:6;
    };
}ich1_readdata_data_y1_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res1:6;
    };
}ich1_readdata_data_y2_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res1:6;
    };
}ich1_readdata_data_c1_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res1:6;
    };
}ich1_readdata_data_c2_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res1:6;
    };
}ich1_readdata_data_c3_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res1:6;
    };
}ich1_readdata_data_c4_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:4;
        RBus_UInt32  u:4;
        RBus_UInt32  v:4;
        RBus_UInt32  res1:20;
    };
}ich1_writedata_data_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_en:1;
        RBus_UInt32  cur_sel:1;
        RBus_UInt32  dummy180231f8_2:1;
        RBus_UInt32  dcti_mode:1;
        RBus_UInt32  uvgain:6;
        RBus_UInt32  offdiv:2;
        RBus_UInt32  engdiv:2;
        RBus_UInt32  lpmode:2;
        RBus_UInt32  psmth:10;
        RBus_UInt32  maxlen:3;
        RBus_UInt32  res1:2;
        RBus_UInt32  data_sel:1;
    };
}i_dcti_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  general_db_en:1;
        RBus_UInt32  general_db_rd_sel:1;
        RBus_UInt32  general_db_apply:1;
        RBus_UInt32  res1:29;
    };
}ich1_general_db_ctrl_RBUS;


#endif







#endif //_RBUS_PEAKING_REG_H_


