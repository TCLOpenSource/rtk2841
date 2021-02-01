/**
* @file rbusDefaultReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2012-12-14
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_PIF_REG_H_
#define _RBUS_PIF_REG_H_

#include "rbus/rbusTypes.h"




// PIF Register Address

#define PIF_PAT_DET_WINDOW_H_INI_STA_WIDTH_VADDR  (0xb802d070)
#define PIF_PAT_DET_WINDOW_V_INI_STA_HEIGHT_VADDR  (0xb802d074)
#define PIF_PATTERN_DETECT_CTRL_VADDR          (0xb802d078)
#define PIF_PAT_DET_SUM1_VADDR                 (0xb802d080)
#define PIF_PAT_DET_SUM2_VADDR                 (0xb802d084)
#define PIF_PAT_DET_SUM3_VADDR                 (0xb802d088)
#define PIF_PAT_DET_SUM4_VADDR                 (0xb802d08c)
#define PIF_PAT_DET_SUM5_VADDR                 (0xb802d090)
#define PIF_PAT_DET_SUM6_VADDR                 (0xb802d094)
#define PIF_PAT_DET_SUM7_VADDR                 (0xb802d098)
#define PIF_PAT_DET_SUM8_VADDR                 (0xb802d09c)
#define PIF_PAT_DET_SUM9_VADDR                 (0xb802d0a0)
#define PIF_PAT_DET_SUM10_VADDR                (0xb802d0a4)
#define PIF_PAT_DET_SUM11_VADDR                (0xb802d0a8)
#define PIF_PAT_DET_SUM12_VADDR                (0xb802d0ac)
#define PIF_PAT_DET_SUM13_VADDR                (0xb802d0b0)
#define PIF_PAT_DET_SUM14_VADDR                (0xb802d0b4)
#define PIF_PAT_DET_SUM15_VADDR                (0xb802d0b8)
#define PIF_PAT_DET_SUM16_VADDR                (0xb802d0bc)
#define PIF_PAT_DET_TH1_VADDR                  (0xb802d0c0)
#define PIF_PAT_DET_TH2_VADDR                  (0xb802d0c4)
#define PIF_PAT_DET_TH3_VADDR                  (0xb802d0c8)
#define PIF_PAT_DET_TH4_VADDR                  (0xb802d0cc)
#define PIF_PAT_DET_TH5_VADDR                  (0xb802d0d0)
#define PIF_PAT_DET_TH6_VADDR                  (0xb802d0d4)
#define PIF_PAT_DET_TH7_VADDR                  (0xb802d0d8)
#define PIF_PAT_DET_TH8_VADDR                  (0xb802d0dc)
#define PIF_PAT_DET_TH9_VADDR                  (0xb802d0e0)
#define PIF_PAT_DET_TH10_VADDR                 (0xb802d0e4)
#define PIF_PAT_DET_TH11_VADDR                 (0xb802d0e8)
#define PIF_PAT_DET_TH12_VADDR                 (0xb802d0ec)
#define PIF_PAT_DET_TH13_VADDR                 (0xb802d0f0)
#define PIF_PAT_DET_TH14_VADDR                 (0xb802d0f4)
#define PIF_PAT_DET_TH15_VADDR                 (0xb802d0f8)
#define PIF_PAT_DET_TH16_VADDR                 (0xb802d0fc)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======PIF register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pat_det_h_ini_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  pat_det_width:13;
    };
}pat_det_window_h_ini_sta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pat_det_v_ini_sta:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pat_det_height:12;
    };
}pat_det_window_v_ini_sta_height_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  spc_pt_1:1;
        RBus_UInt32  spc_pt_2:1;
        RBus_UInt32  spc_pt_3:1;
        RBus_UInt32  spc_pt_4:1;
        RBus_UInt32  spc_pt_5:1;
        RBus_UInt32  spc_pt_6:1;
        RBus_UInt32  spc_pt_7:1;
        RBus_UInt32  spc_pt_8:1;
        RBus_UInt32  spc_pt_9:1;
        RBus_UInt32  spc_pt_10:1;
        RBus_UInt32  spc_pt_11:1;
        RBus_UInt32  spc_pt_12:1;
        RBus_UInt32  spc_pt_13:1;
        RBus_UInt32  spc_pt_14:1;
        RBus_UInt32  spc_pt_15:1;
        RBus_UInt32  spc_pt_16:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  pat_det_en:1;
        RBus_UInt32  pat_det_auto:1;
    };
}pattern_detect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_1:32;
    };
}pat_det_sum1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_2:32;
    };
}pat_det_sum2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_3:32;
    };
}pat_det_sum3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_4:32;
    };
}pat_det_sum4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_5:32;
    };
}pat_det_sum5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_6:32;
    };
}pat_det_sum6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_7:32;
    };
}pat_det_sum7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_8:32;
    };
}pat_det_sum8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_9:32;
    };
}pat_det_sum9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_10:32;
    };
}pat_det_sum10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_11:32;
    };
}pat_det_sum11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_12:32;
    };
}pat_det_sum12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_13:32;
    };
}pat_det_sum13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_14:32;
    };
}pat_det_sum14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_15:32;
    };
}pat_det_sum15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_16:32;
    };
}pat_det_sum16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th1:32;
    };
}pat_det_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th2:32;
    };
}pat_det_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th3:32;
    };
}pat_det_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th4:32;
    };
}pat_det_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th5:32;
    };
}pat_det_th5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th6:32;
    };
}pat_det_th6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th7:32;
    };
}pat_det_th7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th8:32;
    };
}pat_det_th8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th9:32;
    };
}pat_det_th9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th10:32;
    };
}pat_det_th10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th11:32;
    };
}pat_det_th11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th12:32;
    };
}pat_det_th12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th13:32;
    };
}pat_det_th13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th14:32;
    };
}pat_det_th14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th15:32;
    };
}pat_det_th15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th16:32;
    };
}pat_det_th16_RBUS;





#else //apply LITTLE_ENDIAN


//======PIF register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_det_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  pat_det_h_ini_sta:13;
        RBus_UInt32  res1:3;
    };
}pat_det_window_h_ini_sta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_det_height:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pat_det_v_ini_sta:12;
        RBus_UInt32  res1:4;
    };
}pat_det_window_v_ini_sta_height_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_det_auto:1;
        RBus_UInt32  pat_det_en:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  spc_pt_16:1;
        RBus_UInt32  spc_pt_15:1;
        RBus_UInt32  spc_pt_14:1;
        RBus_UInt32  spc_pt_13:1;
        RBus_UInt32  spc_pt_12:1;
        RBus_UInt32  spc_pt_11:1;
        RBus_UInt32  spc_pt_10:1;
        RBus_UInt32  spc_pt_9:1;
        RBus_UInt32  spc_pt_8:1;
        RBus_UInt32  spc_pt_7:1;
        RBus_UInt32  spc_pt_6:1;
        RBus_UInt32  spc_pt_5:1;
        RBus_UInt32  spc_pt_4:1;
        RBus_UInt32  spc_pt_3:1;
        RBus_UInt32  spc_pt_2:1;
        RBus_UInt32  spc_pt_1:1;
        RBus_UInt32  res1:8;
    };
}pattern_detect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_1:32;
    };
}pat_det_sum1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_2:32;
    };
}pat_det_sum2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_3:32;
    };
}pat_det_sum3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_4:32;
    };
}pat_det_sum4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_5:32;
    };
}pat_det_sum5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_6:32;
    };
}pat_det_sum6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_7:32;
    };
}pat_det_sum7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_8:32;
    };
}pat_det_sum8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_9:32;
    };
}pat_det_sum9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_10:32;
    };
}pat_det_sum10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_11:32;
    };
}pat_det_sum11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_12:32;
    };
}pat_det_sum12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_13:32;
    };
}pat_det_sum13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_14:32;
    };
}pat_det_sum14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_15:32;
    };
}pat_det_sum15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_16:32;
    };
}pat_det_sum16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th1:32;
    };
}pat_det_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th2:32;
    };
}pat_det_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th3:32;
    };
}pat_det_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th4:32;
    };
}pat_det_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th5:32;
    };
}pat_det_th5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th6:32;
    };
}pat_det_th6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th7:32;
    };
}pat_det_th7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th8:32;
    };
}pat_det_th8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th9:32;
    };
}pat_det_th9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th10:32;
    };
}pat_det_th10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th11:32;
    };
}pat_det_th11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th12:32;
    };
}pat_det_th12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th13:32;
    };
}pat_det_th13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th14:32;
    };
}pat_det_th14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th15:32;
    };
}pat_det_th15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th16:32;
    };
}pat_det_th16_RBUS;


#endif







#endif //_RBUS_PIF_REG_H_

