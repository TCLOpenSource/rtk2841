/**
* @file rbusPatDetectorReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2007/11/12
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_PATDETECTOR_REG_H_
#define _RBUS_PATDETECTOR_REG_H_

#include "rbus/rbusTypes.h"




// PATDETECTOR Register Address
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CTRL_ADDR  (0x18023300)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_1_ADDR  (0x18023304)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_2_ADDR  (0x18023308)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_3_ADDR  (0x1802330c)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_4_ADDR  (0x18023310)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_5_ADDR  (0x18023314)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_6_ADDR  (0x18023318)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_7_ADDR  (0x1802331c)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_8_ADDR  (0x18023320)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_9_ADDR  (0x18023324)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_10_ADDR  (0x18023328)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_11_ADDR  (0x1802332c)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CTRL_ADDR  (0x18023340)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_1_ADDR  (0x18023344)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_2_ADDR  (0x18023348)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_3_ADDR  (0x1802334c)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_4_ADDR  (0x18023350)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_5_ADDR  (0x18023354)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_6_ADDR  (0x18023358)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_7_ADDR  (0x1802335c)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_8_ADDR  (0x18023360)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_9_ADDR  (0x18023364)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_10_ADDR  (0x18023368)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_11_ADDR  (0x1802336c)

#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CTRL_VADDR (0xb8023300)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_1_VADDR  (0xb8023304)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_2_VADDR  (0xb8023308)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_3_VADDR  (0xb802330c)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_4_VADDR  (0xb8023310)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_5_VADDR  (0xb8023314)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_6_VADDR  (0xb8023318)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_7_VADDR  (0xb802331c)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_8_VADDR  (0xb8023320)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_9_VADDR  (0xb8023324)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_10_VADDR  (0xb8023328)
#define PATDETECTOR_ICH1_ITSP_HIST_FREQ_CNT_DATA_11_VADDR  (0xb802332c)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CTRL_VADDR (0xb8023340)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_1_VADDR  (0xb8023344)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_2_VADDR  (0xb8023348)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_3_VADDR  (0xb802334c)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_4_VADDR  (0xb8023350)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_5_VADDR  (0xb8023354)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_6_VADDR  (0xb8023358)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_7_VADDR  (0xb802335c)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_8_VADDR  (0xb8023360)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_9_VADDR  (0xb8023364)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_10_VADDR  (0xb8023368)
#define PATDETECTOR_ICH2_ITSP_HIST_FREQ_CNT_DATA_11_VADDR  (0xb802336c)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======PATDETECTOR register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  dummy18023300_8:1;
        RBus_UInt32  ch1_tsp_flag2:1;
        RBus_UInt32  ch1_tsp_flag1:1;
        RBus_UInt32  ch1_tsp_testmode:2;
        RBus_UInt32  ch1_tsp_pix_colordepend:1;
        RBus_UInt32  ch1_tsp_field_sel:2;
        RBus_UInt32  ch1_tsp_enable_tstpat:1;
    };
}ich1_itsp_hist_freq_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_freq_cnt04:8;
        RBus_UInt32  ch1_tsp_freq_cnt03:8;
        RBus_UInt32  ch1_tsp_freq_cnt02:8;
        RBus_UInt32  ch1_tsp_freq_cnt01:8;
    };
}ich1_itsp_hist_freq_cnt_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_freq_cnt08:8;
        RBus_UInt32  ch1_tsp_freq_cnt07:8;
        RBus_UInt32  ch1_tsp_freq_cnt06:8;
        RBus_UInt32  ch1_tsp_freq_cnt05:8;
    };
}ich1_itsp_hist_freq_cnt_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_hit_cnt03:8;
        RBus_UInt32  ch1_tsp_hit_cnt02:8;
        RBus_UInt32  ch1_tsp_hit_cnt01:8;
        RBus_UInt32  ch1_tsp_freq_cnt09:8;
    };
}ich1_itsp_hist_freq_cnt_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_hit_cnt07:8;
        RBus_UInt32  ch1_tsp_hit_cnt06:8;
        RBus_UInt32  ch1_tsp_hit_cnt05:8;
        RBus_UInt32  ch1_tsp_hit_cnt04:8;
    };
}ich1_itsp_hist_freq_cnt_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_tsp_multi_freq_cnt:8;
        RBus_UInt32  ch1_tsp_hit_cnt09:8;
        RBus_UInt32  ch1_tsp_hit_cnt08:8;
    };
}ich1_itsp_hist_freq_cnt_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ch1_tsp_all_lines:10;
        RBus_UInt32  ch1_tsp_color_line:10;
    };
}ich1_itsp_hist_freq_cnt_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_th_c:8;
        RBus_UInt32  ch1_tsp_th_g:8;
        RBus_UInt32  ch1_tsp_th_d:8;
        RBus_UInt32  ch1_tsp_th_pn:8;
    };
}ich1_itsp_hist_freq_cnt_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_th_f:8;
        RBus_UInt32  ch1_tsp_th_t3:8;
        RBus_UInt32  ch1_tsp_th_t2:8;
        RBus_UInt32  ch1_tsp_th_t1:8;
    };
}ich1_itsp_hist_freq_cnt_data_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_tsp_horend:12;
        RBus_UInt32  ch1_tsp_horstart:12;
    };
}ich1_itsp_hist_freq_cnt_data_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_tsp_verend:12;
        RBus_UInt32  ch1_tsp_verstart:12;
    };
}ich1_itsp_hist_freq_cnt_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  ch1_tsp_color_ratio:1;
        RBus_UInt32  ch1_tsp_fqcnt_mode_sel:1;
        RBus_UInt32  ch1_tsp_peak_mode_sel:2;
        RBus_UInt32  ch1_tsp_th_multi_freq:8;
    };
}ich1_itsp_hist_freq_cnt_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  dummy18023340_8:1;
        RBus_UInt32  ch2_tsp_flag2:1;
        RBus_UInt32  ch2_tsp_flag1:1;
        RBus_UInt32  ch2_tsp_testmode:2;
        RBus_UInt32  ch2_tsp_pix_colordepend:1;
        RBus_UInt32  ch2_tsp_field_sel:2;
        RBus_UInt32  ch2_tsp_enable_tstpat:1;
    };
}ich2_itsp_hist_freq_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_freq_cnt04:8;
        RBus_UInt32  ch2_tsp_freq_cnt03:8;
        RBus_UInt32  ch2_tsp_freq_cnt02:8;
        RBus_UInt32  ch2_tsp_freq_cnt01:8;
    };
}ich2_itsp_hist_freq_cnt_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_freq_cnt08:8;
        RBus_UInt32  ch2_tsp_freq_cnt07:8;
        RBus_UInt32  ch2_tsp_freq_cnt06:8;
        RBus_UInt32  ch2_tsp_freq_cnt05:8;
    };
}ich2_itsp_hist_freq_cnt_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_hit_cnt03:8;
        RBus_UInt32  ch2_tsp_hit_cnt02:8;
        RBus_UInt32  ch2_tsp_hit_cnt01:8;
        RBus_UInt32  ch2_tsp_freq_cnt09:8;
    };
}ich2_itsp_hist_freq_cnt_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_hit_cnt07:8;
        RBus_UInt32  ch2_tsp_hit_cnt06:8;
        RBus_UInt32  ch2_tsp_hit_cnt05:8;
        RBus_UInt32  ch2_tsp_hit_cnt04:8;
    };
}ich2_itsp_hist_freq_cnt_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch2_tsp_multi_freq_cnt:8;
        RBus_UInt32  ch2_tsp_hit_cnt09:8;
        RBus_UInt32  ch2_tsp_hit_cnt08:8;
    };
}ich2_itsp_hist_freq_cnt_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ch2_tsp_all_lines:10;
        RBus_UInt32  ch2_tsp_color_line:10;
    };
}ich2_itsp_hist_freq_cnt_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_th_c:8;
        RBus_UInt32  ch2_tsp_th_g:8;
        RBus_UInt32  ch2_tsp_th_d:8;
        RBus_UInt32  ch2_tsp_th_pn:8;
    };
}ich2_itsp_hist_freq_cnt_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_th_f:8;
        RBus_UInt32  ch2_tsp_th_t3:8;
        RBus_UInt32  ch2_tsp_th_t2:8;
        RBus_UInt32  ch2_tsp_th_t1:8;
    };
}ich2_itsp_hist_freq_cnt_data_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch2_tsp_horend:12;
        RBus_UInt32  ch2_tsp_horstart:12;
    };
}ich2_itsp_hist_freq_cnt_data_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch2_tsp_verend:12;
        RBus_UInt32  ch2_tsp_verstart:12;
    };
}ich2_itsp_hist_freq_cnt_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  ch2_tsp_color_ratio:1;
        RBus_UInt32  ch2_tsp_fqcnt_mode_sel:1;
        RBus_UInt32  ch2_tsp_peak_mode_sel:2;
        RBus_UInt32  ch2_tsp_th_multi_freq:8;
    };
}ich2_itsp_hist_freq_cnt_data_11_RBUS;





#else //apply LITTLE_ENDIAN


//======PATDETECTOR register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_enable_tstpat:1;
        RBus_UInt32  ch1_tsp_field_sel:2;
        RBus_UInt32  ch1_tsp_pix_colordepend:1;
        RBus_UInt32  ch1_tsp_testmode:2;
        RBus_UInt32  ch1_tsp_flag1:1;
        RBus_UInt32  ch1_tsp_flag2:1;
        RBus_UInt32  dummy18023300_8:1;
        RBus_UInt32  res1:23;
    };
}ich1_itsp_hist_freq_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_freq_cnt01:8;
        RBus_UInt32  ch1_tsp_freq_cnt02:8;
        RBus_UInt32  ch1_tsp_freq_cnt03:8;
        RBus_UInt32  ch1_tsp_freq_cnt04:8;
    };
}ich1_itsp_hist_freq_cnt_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_freq_cnt05:8;
        RBus_UInt32  ch1_tsp_freq_cnt06:8;
        RBus_UInt32  ch1_tsp_freq_cnt07:8;
        RBus_UInt32  ch1_tsp_freq_cnt08:8;
    };
}ich1_itsp_hist_freq_cnt_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_freq_cnt09:8;
        RBus_UInt32  ch1_tsp_hit_cnt01:8;
        RBus_UInt32  ch1_tsp_hit_cnt02:8;
        RBus_UInt32  ch1_tsp_hit_cnt03:8;
    };
}ich1_itsp_hist_freq_cnt_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_hit_cnt04:8;
        RBus_UInt32  ch1_tsp_hit_cnt05:8;
        RBus_UInt32  ch1_tsp_hit_cnt06:8;
        RBus_UInt32  ch1_tsp_hit_cnt07:8;
    };
}ich1_itsp_hist_freq_cnt_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_hit_cnt08:8;
        RBus_UInt32  ch1_tsp_hit_cnt09:8;
        RBus_UInt32  ch1_tsp_multi_freq_cnt:8;
        RBus_UInt32  res1:8;
    };
}ich1_itsp_hist_freq_cnt_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_color_line:10;
        RBus_UInt32  ch1_tsp_all_lines:10;
        RBus_UInt32  res1:12;
    };
}ich1_itsp_hist_freq_cnt_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_th_pn:8;
        RBus_UInt32  ch1_tsp_th_d:8;
        RBus_UInt32  ch1_tsp_th_g:8;
        RBus_UInt32  ch1_tsp_th_c:8;
    };
}ich1_itsp_hist_freq_cnt_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_th_t1:8;
        RBus_UInt32  ch1_tsp_th_t2:8;
        RBus_UInt32  ch1_tsp_th_t3:8;
        RBus_UInt32  ch1_tsp_th_f:8;
    };
}ich1_itsp_hist_freq_cnt_data_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_horstart:12;
        RBus_UInt32  ch1_tsp_horend:12;
        RBus_UInt32  res1:8;
    };
}ich1_itsp_hist_freq_cnt_data_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_verstart:12;
        RBus_UInt32  ch1_tsp_verend:12;
        RBus_UInt32  res1:8;
    };
}ich1_itsp_hist_freq_cnt_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_tsp_th_multi_freq:8;
        RBus_UInt32  ch1_tsp_peak_mode_sel:2;
        RBus_UInt32  ch1_tsp_fqcnt_mode_sel:1;
        RBus_UInt32  ch1_tsp_color_ratio:1;
        RBus_UInt32  res1:20;
    };
}ich1_itsp_hist_freq_cnt_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_enable_tstpat:1;
        RBus_UInt32  ch2_tsp_field_sel:2;
        RBus_UInt32  ch2_tsp_pix_colordepend:1;
        RBus_UInt32  ch2_tsp_testmode:2;
        RBus_UInt32  ch2_tsp_flag1:1;
        RBus_UInt32  ch2_tsp_flag2:1;
        RBus_UInt32  dummy18023340_8:1;
        RBus_UInt32  res1:23;
    };
}ich2_itsp_hist_freq_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_freq_cnt01:8;
        RBus_UInt32  ch2_tsp_freq_cnt02:8;
        RBus_UInt32  ch2_tsp_freq_cnt03:8;
        RBus_UInt32  ch2_tsp_freq_cnt04:8;
    };
}ich2_itsp_hist_freq_cnt_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_freq_cnt05:8;
        RBus_UInt32  ch2_tsp_freq_cnt06:8;
        RBus_UInt32  ch2_tsp_freq_cnt07:8;
        RBus_UInt32  ch2_tsp_freq_cnt08:8;
    };
}ich2_itsp_hist_freq_cnt_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_freq_cnt09:8;
        RBus_UInt32  ch2_tsp_hit_cnt01:8;
        RBus_UInt32  ch2_tsp_hit_cnt02:8;
        RBus_UInt32  ch2_tsp_hit_cnt03:8;
    };
}ich2_itsp_hist_freq_cnt_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_hit_cnt04:8;
        RBus_UInt32  ch2_tsp_hit_cnt05:8;
        RBus_UInt32  ch2_tsp_hit_cnt06:8;
        RBus_UInt32  ch2_tsp_hit_cnt07:8;
    };
}ich2_itsp_hist_freq_cnt_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_hit_cnt08:8;
        RBus_UInt32  ch2_tsp_hit_cnt09:8;
        RBus_UInt32  ch2_tsp_multi_freq_cnt:8;
        RBus_UInt32  res1:8;
    };
}ich2_itsp_hist_freq_cnt_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_color_line:10;
        RBus_UInt32  ch2_tsp_all_lines:10;
        RBus_UInt32  res1:12;
    };
}ich2_itsp_hist_freq_cnt_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_th_pn:8;
        RBus_UInt32  ch2_tsp_th_d:8;
        RBus_UInt32  ch2_tsp_th_g:8;
        RBus_UInt32  ch2_tsp_th_c:8;
    };
}ich2_itsp_hist_freq_cnt_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_th_t1:8;
        RBus_UInt32  ch2_tsp_th_t2:8;
        RBus_UInt32  ch2_tsp_th_t3:8;
        RBus_UInt32  ch2_tsp_th_f:8;
    };
}ich2_itsp_hist_freq_cnt_data_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_horstart:12;
        RBus_UInt32  ch2_tsp_horend:12;
        RBus_UInt32  res1:8;
    };
}ich2_itsp_hist_freq_cnt_data_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_verstart:12;
        RBus_UInt32  ch2_tsp_verend:12;
        RBus_UInt32  res1:8;
    };
}ich2_itsp_hist_freq_cnt_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_tsp_th_multi_freq:8;
        RBus_UInt32  ch2_tsp_peak_mode_sel:2;
        RBus_UInt32  ch2_tsp_fqcnt_mode_sel:1;
        RBus_UInt32  ch2_tsp_color_ratio:1;
        RBus_UInt32  res1:20;
    };
}ich2_itsp_hist_freq_cnt_data_11_RBUS;


#endif







#endif //_RBUS_PATDETECTOR_REG_H_

