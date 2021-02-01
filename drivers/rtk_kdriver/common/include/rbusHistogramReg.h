/**
* @file rbusHistogramReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/6/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_HISTOGRAM_REG_H_
#define _RBUS_HISTOGRAM_REG_H_

#include "rbusTypes.h"



//  HISTOGRAM Register Address



#define  HISTOGRAM_ICH1_HIST_IN_CSELECT_VADDR               	(0xb8023200)
#define  HISTOGRAM_ICH1_HIST_IN_RANGE_HOR_VADDR             	(0xb8023204)
#define  HISTOGRAM_ICH1_HIST_IN_RANGE_VER_VADDR             	(0xb8023208)
#define  HISTOGRAM_ICH1_HIST_STATUS_VADDR                   	(0xb802320c)
#define  HISTOGRAM_ICH1_HIST_MAX_MIN_VADDR                  	(0xb8023210)
#define  HISTOGRAM_ICH1_BYCOLOR_DEBUG_VADDR                 	(0xb8023214)
#define  HISTOGRAM_ICH1_HIST_SUMVAL_HIGH_VADDR              	(0xb8023218)
#define  HISTOGRAM_ICH1_HIST_SUMVAL_LOW_VADDR               	(0xb802321c)
#define  HISTOGRAM_ICH1_C0_HIST_BOUND_VADDR                 	(0xb8023220)
#define  HISTOGRAM_ICH1_C0_HIST_BOUND_U_VADDR               	(0xb8023224)
#define  HISTOGRAM_ICH1_C0_HIST_BOUND_V_VADDR               	(0xb8023228)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_01_00_VADDR         	(0xb8023230)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_03_02_VADDR         	(0xb8023234)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_05_04_VADDR         	(0xb8023238)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_07_06_VADDR         	(0xb802323c)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_09_08_VADDR         	(0xb8023240)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_11_10_VADDR         	(0xb8023244)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_13_12_VADDR         	(0xb8023248)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_15_14_VADDR         	(0xb802324c)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_17_16_VADDR         	(0xb8023250)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_19_18_VADDR         	(0xb8023254)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_21_20_VADDR         	(0xb8023258)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_23_22_VADDR         	(0xb802325c)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_25_24_VADDR         	(0xb8023260)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_27_26_VADDR         	(0xb8023264)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_29_28_VADDR         	(0xb8023268)
#define  HISTOGRAM_ICH1_C0_HIST_IN_DATA_31_30_VADDR         	(0xb802326c)
#define  HISTOGRAM_ICH1_C0_SECTIONHIST_IN_CSELECT_VADDR     	(0xb8023270)
#define  HISTOGRAM_ICH1_C0_SECTION0_DATA_01_00_VADDR        	(0xb8023274)
#define  HISTOGRAM_ICH1_C0_SECTION0_DATA_03_02_VADDR        	(0xb8023278)
#define  HISTOGRAM_ICH1_C0_SECTION0_DATA_05_04_VADDR        	(0xb802327c)
#define  HISTOGRAM_ICH1_C0_SECTION0_DATA_07_06_VADDR        	(0xb8023280)
#define  HISTOGRAM_ICH1_C0_SECTION1_DATA_01_00_VADDR        	(0xb8023284)
#define  HISTOGRAM_ICH1_C0_SECTION1_DATA_03_02_VADDR        	(0xb8023288)
#define  HISTOGRAM_ICH1_C0_SECTION1_DATA_05_04_VADDR        	(0xb802328c)
#define  HISTOGRAM_ICH1_C0_SECTION1_DATA_07_06_VADDR        	(0xb8023290)
#define  HISTOGRAM_ICH1_C1_HIST_BOUND_VADDR                 	(0xb80232a0)
#define  HISTOGRAM_ICH1_C1_HIST_BOUND_U_VADDR               	(0xb80232a4)
#define  HISTOGRAM_ICH1_C1_HIST_BOUND_V_VADDR               	(0xb80232a8)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_01_00_VADDR         	(0xb80232b0)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_03_02_VADDR         	(0xb80232b4)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_05_04_VADDR         	(0xb80232b8)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_07_06_VADDR         	(0xb80232bc)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_09_08_VADDR         	(0xb80232c0)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_11_10_VADDR         	(0xb80232c4)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_13_12_VADDR         	(0xb80232c8)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_15_14_VADDR         	(0xb80232cc)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_17_16_VADDR         	(0xb80232d0)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_19_18_VADDR         	(0xb80232d4)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_21_20_VADDR         	(0xb80232d8)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_23_22_VADDR         	(0xb80232dc)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_25_24_VADDR         	(0xb80232e0)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_27_26_VADDR         	(0xb80232e4)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_29_28_VADDR         	(0xb80232e8)
#define  HISTOGRAM_ICH1_C1_HIST_IN_DATA_31_30_VADDR         	(0xb80232ec)
#define  HISTOGRAM_ICH1_C1_SECTIONHIST_IN_CSELECT_VADDR     	(0xb80232f0)
#define  HISTOGRAM_ICH1_C1_SECTION0_DATA_01_00_VADDR        	(0xb80232f4)
#define  HISTOGRAM_ICH1_C1_SECTION0_DATA_03_02_VADDR        	(0xb80232f8)
#define  HISTOGRAM_ICH1_C1_SECTION0_DATA_05_04_VADDR        	(0xb80232fc)
#define  HISTOGRAM_ICH1_C1_SECTION0_DATA_07_06_VADDR        	(0xb8023300)
#define  HISTOGRAM_ICH1_C1_SECTION1_DATA_01_00_VADDR        	(0xb8023304)
#define  HISTOGRAM_ICH1_C1_SECTION1_DATA_03_02_VADDR        	(0xb8023308)
#define  HISTOGRAM_ICH1_C1_SECTION1_DATA_05_04_VADDR        	(0xb802330c)
#define  HISTOGRAM_ICH1_C1_SECTION1_DATA_07_06_VADDR        	(0xb8023310)
#define  HISTOGRAM_ICH2_HIST_IN_CSELECT_VADDR               	(0xb8023a00)
#define  HISTOGRAM_ICH2_HIST_IN_RANGE_HOR_VADDR             	(0xb8023a04)
#define  HISTOGRAM_ICH2_HIST_IN_RANGE_VER_VADDR             	(0xb8023a08)
#define  HISTOGRAM_ICH2_HIST_STATUS_VADDR                   	(0xb8023a0c)
#define  HISTOGRAM_ICH2_HIST_MAX_MIN_VADDR                  	(0xb8023a10)
#define  HISTOGRAM_ICH2_BYCOLOR_DEBUG_VADDR                 	(0xb8023a14)
#define  HISTOGRAM_ICH2_HIST_SUMVAL_HIGH_VADDR              	(0xb8023a18)
#define  HISTOGRAM_ICH2_HIST_SUMVAL_LOW_VADDR               	(0xb8023a1c)
#define  HISTOGRAM_ICH2_C0_HIST_BOUND_VADDR                 	(0xb8023a20)
#define  HISTOGRAM_ICH2_C0_HIST_BOUND_U_VADDR               	(0xb8023a24)
#define  HISTOGRAM_ICH2_C0_HIST_BOUND_V_VADDR               	(0xb8023a28)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_01_00_VADDR         	(0xb8023a30)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_03_02_VADDR         	(0xb8023a34)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_05_04_VADDR         	(0xb8023a38)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_07_06_VADDR         	(0xb8023a3c)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_09_08_VADDR         	(0xb8023a40)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_11_10_VADDR         	(0xb8023a44)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_13_12_VADDR         	(0xb8023a48)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_15_14_VADDR         	(0xb8023a4c)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_17_16_VADDR         	(0xb8023a50)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_19_18_VADDR         	(0xb8023a54)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_21_20_VADDR         	(0xb8023a58)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_23_22_VADDR         	(0xb8023a5c)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_25_24_VADDR         	(0xb8023a60)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_27_26_VADDR         	(0xb8023a64)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_29_28_VADDR         	(0xb8023a68)
#define  HISTOGRAM_ICH2_C0_HIST_IN_DATA_31_30_VADDR         	(0xb8023a6c)
#define  HISTOGRAM_ICH2_C0_SECTIONHIST_IN_CSELECT_VADDR     	(0xb8023a70)
#define  HISTOGRAM_ICH2_C0_SECTION0_DATA_01_00_VADDR        	(0xb8023a74)
#define  HISTOGRAM_ICH2_C0_SECTION0_DATA_03_02_VADDR        	(0xb8023a78)
#define  HISTOGRAM_ICH2_C0_SECTION0_DATA_05_04_VADDR        	(0xb8023a7c)
#define  HISTOGRAM_ICH2_C0_SECTION0_DATA_07_06_VADDR        	(0xb8023a80)
#define  HISTOGRAM_ICH2_C0_SECTION1_DATA_01_00_VADDR        	(0xb8023a84)
#define  HISTOGRAM_ICH2_C0_SECTION1_DATA_03_02_VADDR        	(0xb8023a88)
#define  HISTOGRAM_ICH2_C0_SECTION1_DATA_05_04_VADDR        	(0xb8023a8c)
#define  HISTOGRAM_ICH2_C0_SECTION1_DATA_07_06_VADDR        	(0xb8023a90)
#define  HISTOGRAM_ICH2_C1_HIST_BOUND_VADDR                 	(0xb8023aa0)
#define  HISTOGRAM_ICH2_C1_HIST_BOUND_U_VADDR               	(0xb8023aa4)
#define  HISTOGRAM_ICH2_C1_HIST_BOUND_V_VADDR               	(0xb8023aa8)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_01_00_VADDR         	(0xb8023ab0)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_03_02_VADDR         	(0xb8023ab4)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_05_04_VADDR         	(0xb8023ab8)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_07_06_VADDR         	(0xb8023abc)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_09_08_VADDR         	(0xb8023ac0)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_11_10_VADDR         	(0xb8023ac4)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_13_12_VADDR         	(0xb8023ac8)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_15_14_VADDR         	(0xb8023acc)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_17_16_VADDR         	(0xb8023ad0)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_19_18_VADDR         	(0xb8023ad4)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_21_20_VADDR         	(0xb8023ad8)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_23_22_VADDR         	(0xb8023adc)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_25_24_VADDR         	(0xb8023ae0)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_27_26_VADDR         	(0xb8023ae4)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_29_28_VADDR         	(0xb8023ae8)
#define  HISTOGRAM_ICH2_C1_HIST_IN_DATA_31_30_VADDR         	(0xb8023aec)
#define  HISTOGRAM_ICH2_C1_SECTIONHIST_IN_CSELECT_VADDR     	(0xb8023af0)
#define  HISTOGRAM_ICH2_C1_SECTION0_DATA_01_00_VADDR        	(0xb8023af4)
#define  HISTOGRAM_ICH2_C1_SECTION0_DATA_03_02_VADDR        	(0xb8023af8)
#define  HISTOGRAM_ICH2_C1_SECTION0_DATA_05_04_VADDR        	(0xb8023afc)
#define  HISTOGRAM_ICH2_C1_SECTION0_DATA_07_06_VADDR        	(0xb8023b00)
#define  HISTOGRAM_ICH2_C1_SECTION1_DATA_01_00_VADDR        	(0xb8023b04)
#define  HISTOGRAM_ICH2_C1_SECTION1_DATA_03_02_VADDR        	(0xb8023b08)
#define  HISTOGRAM_ICH2_C1_SECTION1_DATA_05_04_VADDR        	(0xb8023b0c)
#define  HISTOGRAM_ICH2_C1_SECTION1_DATA_07_06_VADDR        	(0xb8023b10)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======HISTOGRAM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  lr_select:1;
        RBus_UInt32  ch1_3d_en:1;
        RBus_UInt32  ch1_his_updatelockmode_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch1_his_enable_histog:1;
        RBus_UInt32  ch1_his_irq_en:1;
        RBus_UInt32  ch1_his_yuv_sel:2;
        RBus_UInt32  ch1_his_num_flds:4;
        RBus_UInt32  ch1_his_shift_sel:3;
        RBus_UInt32  ch1_his_offset:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  ch1_his_mode_sel:1;
        RBus_UInt32  ch1_his_even_odd_pos_en:1;
        RBus_UInt32  ch1_his_even_odd_pos_sel:1;
        RBus_UInt32  ch1_his_even_odd_fld_en:1;
        RBus_UInt32  ch1_his_even_odd_fld_sel:1;
        RBus_UInt32  res4:2;
    };
}histogram_ich1_hist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_his_horend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ch1_his_horstart:13;
    };
}histogram_ich1_hist_in_range_hor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_his_verend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ch1_his_verstart:13;
    };
}histogram_ich1_hist_in_range_ver_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ch1_his_dcc_invalid:1;
        RBus_UInt32  ch1_his_his_irq:1;
    };
}histogram_ich1_hist_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_his_max_val:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_his_min_val:10;
    };
}histogram_ich1_hist_max_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bycolor_debug_mode:2;
    };
}histogram_ich1_bycolor_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  ch1_his_sumval_high:9;
    };
}histogram_ich1_hist_sumval_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_his_sumval_low:24;
    };
}histogram_ich1_hist_sumval_low_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c0_upper_bound:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_c0_lower_bound:10;
    };
}histogram_ich1_c0_hist_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c0_upper_bound_u:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_c0_lower_bound_u:10;
    };
}histogram_ich1_c0_hist_bound_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c0_upper_bound_v:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_c0_lower_bound_v:10;
    };
}histogram_ich1_c0_hist_bound_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist01:16;
        RBus_UInt32  ch1_c0_hist00:16;
    };
}histogram_ich1_c0_hist_in_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist03:16;
        RBus_UInt32  ch1_c0_hist02:16;
    };
}histogram_ich1_c0_hist_in_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist05:16;
        RBus_UInt32  ch1_c0_hist04:16;
    };
}histogram_ich1_c0_hist_in_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist07:16;
        RBus_UInt32  ch1_c0_hist06:16;
    };
}histogram_ich1_c0_hist_in_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist09:16;
        RBus_UInt32  ch1_c0_hist08:16;
    };
}histogram_ich1_c0_hist_in_data_09_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist11:16;
        RBus_UInt32  ch1_c0_hist10:16;
    };
}histogram_ich1_c0_hist_in_data_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist13:16;
        RBus_UInt32  ch1_c0_hist12:16;
    };
}histogram_ich1_c0_hist_in_data_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist15:16;
        RBus_UInt32  ch1_c0_hist14:16;
    };
}histogram_ich1_c0_hist_in_data_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist17:16;
        RBus_UInt32  ch1_c0_hist16:16;
    };
}histogram_ich1_c0_hist_in_data_17_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist19:16;
        RBus_UInt32  ch1_c0_hist18:16;
    };
}histogram_ich1_c0_hist_in_data_19_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist21:16;
        RBus_UInt32  ch1_c0_hist20:16;
    };
}histogram_ich1_c0_hist_in_data_21_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist23:16;
        RBus_UInt32  ch1_c0_hist22:16;
    };
}histogram_ich1_c0_hist_in_data_23_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist25:16;
        RBus_UInt32  ch1_c0_hist24:16;
    };
}histogram_ich1_c0_hist_in_data_25_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist27:16;
        RBus_UInt32  ch1_c0_hist26:16;
    };
}histogram_ich1_c0_hist_in_data_27_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist29:16;
        RBus_UInt32  ch1_c0_hist28:16;
    };
}histogram_ich1_c0_hist_in_data_29_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist31:16;
        RBus_UInt32  ch1_c0_hist30:16;
    };
}histogram_ich1_c0_hist_in_data_31_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  ch1_c0_section1_bin_sel:5;
        RBus_UInt32  res2:11;
        RBus_UInt32  ch1_c0_section0_bin_sel:5;
    };
}histogram_ich1_c0_sectionhist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist01:16;
        RBus_UInt32  ch1_c0_section_his0_hist00:16;
    };
}histogram_ich1_c0_section0_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist03:16;
        RBus_UInt32  ch1_c0_section_his0_hist02:16;
    };
}histogram_ich1_c0_section0_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist05:16;
        RBus_UInt32  ch1_c0_section_his0_hist04:16;
    };
}histogram_ich1_c0_section0_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist07:16;
        RBus_UInt32  ch1_c0_section_his0_hist06:16;
    };
}histogram_ich1_c0_section0_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist01:16;
        RBus_UInt32  ch1_c0_section_his1_hist00:16;
    };
}histogram_ich1_c0_section1_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist03:16;
        RBus_UInt32  ch1_c0_section_his1_hist02:16;
    };
}histogram_ich1_c0_section1_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist05:16;
        RBus_UInt32  ch1_c0_section_his1_hist04:16;
    };
}histogram_ich1_c0_section1_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist07:16;
        RBus_UInt32  ch1_c0_section_his1_hist06:16;
    };
}histogram_ich1_c0_section1_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c1_upper_bound:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_c1_lower_bound:10;
    };
}histogram_ich1_c1_hist_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c1_upper_bound_u:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_c1_lower_bound_u:10;
    };
}histogram_ich1_c1_hist_bound_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c1_upper_bound_v:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_c1_lower_bound_v:10;
    };
}histogram_ich1_c1_hist_bound_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist01:16;
        RBus_UInt32  ch1_c1_hist00:16;
    };
}histogram_ich1_c1_hist_in_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist03:16;
        RBus_UInt32  ch1_c1_hist02:16;
    };
}histogram_ich1_c1_hist_in_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist05:16;
        RBus_UInt32  ch1_c1_hist04:16;
    };
}histogram_ich1_c1_hist_in_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist07:16;
        RBus_UInt32  ch1_c1_hist06:16;
    };
}histogram_ich1_c1_hist_in_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist09:16;
        RBus_UInt32  ch1_c1_hist08:16;
    };
}histogram_ich1_c1_hist_in_data_09_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist11:16;
        RBus_UInt32  ch1_c1_hist10:16;
    };
}histogram_ich1_c1_hist_in_data_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist13:16;
        RBus_UInt32  ch1_c1_hist12:16;
    };
}histogram_ich1_c1_hist_in_data_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist15:16;
        RBus_UInt32  ch1_c1_hist14:16;
    };
}histogram_ich1_c1_hist_in_data_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist17:16;
        RBus_UInt32  ch1_c1_hist16:16;
    };
}histogram_ich1_c1_hist_in_data_17_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist19:16;
        RBus_UInt32  ch1_c1_hist18:16;
    };
}histogram_ich1_c1_hist_in_data_19_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist21:16;
        RBus_UInt32  ch1_c1_hist20:16;
    };
}histogram_ich1_c1_hist_in_data_21_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist23:16;
        RBus_UInt32  ch1_c1_hist22:16;
    };
}histogram_ich1_c1_hist_in_data_23_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist25:16;
        RBus_UInt32  ch1_c1_hist24:16;
    };
}histogram_ich1_c1_hist_in_data_25_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist27:16;
        RBus_UInt32  ch1_c1_hist26:16;
    };
}histogram_ich1_c1_hist_in_data_27_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist29:16;
        RBus_UInt32  ch1_c1_hist28:16;
    };
}histogram_ich1_c1_hist_in_data_29_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist31:16;
        RBus_UInt32  ch1_c1_hist30:16;
    };
}histogram_ich1_c1_hist_in_data_31_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  ch1_c1_section1_bin_sel:5;
        RBus_UInt32  res2:11;
        RBus_UInt32  ch1_c1_section0_bin_sel:5;
    };
}histogram_ich1_c1_sectionhist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist01:16;
        RBus_UInt32  ch1_c1_section_his0_hist00:16;
    };
}histogram_ich1_c1_section0_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist03:16;
        RBus_UInt32  ch1_c1_section_his0_hist02:16;
    };
}histogram_ich1_c1_section0_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist05:16;
        RBus_UInt32  ch1_c1_section_his0_hist04:16;
    };
}histogram_ich1_c1_section0_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist07:16;
        RBus_UInt32  ch1_c1_section_his0_hist06:16;
    };
}histogram_ich1_c1_section0_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist01:16;
        RBus_UInt32  ch1_c1_section_his1_hist00:16;
    };
}histogram_ich1_c1_section1_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist03:16;
        RBus_UInt32  ch1_c1_section_his1_hist02:16;
    };
}histogram_ich1_c1_section1_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist05:16;
        RBus_UInt32  ch1_c1_section_his1_hist04:16;
    };
}histogram_ich1_c1_section1_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist07:16;
        RBus_UInt32  ch1_c1_section_his1_hist06:16;
    };
}histogram_ich1_c1_section1_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ch2_his_updatelockmode_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch2_his_enable_histog:1;
        RBus_UInt32  ch2_his_irq_en:1;
        RBus_UInt32  ch2_his_yuv_sel:2;
        RBus_UInt32  ch2_his_num_flds:4;
        RBus_UInt32  ch2_his_shift_sel:3;
        RBus_UInt32  ch2_his_offset:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  ch2_his_mode_sel:1;
        RBus_UInt32  ch2_his_even_odd_pos_en:1;
        RBus_UInt32  ch2_his_even_odd_pos_sel:1;
        RBus_UInt32  ch2_his_even_odd_fld_en:1;
        RBus_UInt32  ch2_his_even_odd_fld_sel:1;
        RBus_UInt32  res4:2;
    };
}histogram_ich2_hist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch2_his_horend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ch2_his_horstart:13;
    };
}histogram_ich2_hist_in_range_hor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch2_his_verend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ch2_his_verstart:13;
    };
}histogram_ich2_hist_in_range_ver_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ch2_his_dcc_invalid:1;
        RBus_UInt32  ch2_his_his_irq:1;
    };
}histogram_ich2_hist_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_his_max_val:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch2_his_min_val:10;
    };
}histogram_ich2_hist_max_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bycolor_debug_mode:2;
    };
}histogram_ich2_bycolor_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  ch2_his_sumval_high:9;
    };
}histogram_ich2_hist_sumval_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch2_his_sumval_low:24;
    };
}histogram_ich2_hist_sumval_low_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_c0_upper_bound:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch2_c0_lower_bound:10;
    };
}histogram_ich2_c0_hist_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_c0_upper_bound_u:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch2_c0_lower_bound_u:10;
    };
}histogram_ich2_c0_hist_bound_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_c0_upper_bound_v:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch2_c0_lower_bound_v:10;
    };
}histogram_ich2_c0_hist_bound_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist01:16;
        RBus_UInt32  ch2_c0_hist00:16;
    };
}histogram_ich2_c0_hist_in_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist03:16;
        RBus_UInt32  ch2_c0_hist02:16;
    };
}histogram_ich2_c0_hist_in_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist05:16;
        RBus_UInt32  ch2_c0_hist04:16;
    };
}histogram_ich2_c0_hist_in_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist07:16;
        RBus_UInt32  ch2_c0_hist06:16;
    };
}histogram_ich2_c0_hist_in_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist09:16;
        RBus_UInt32  ch2_c0_hist08:16;
    };
}histogram_ich2_c0_hist_in_data_09_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist11:16;
        RBus_UInt32  ch2_c0_hist10:16;
    };
}histogram_ich2_c0_hist_in_data_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist13:16;
        RBus_UInt32  ch2_c0_hist12:16;
    };
}histogram_ich2_c0_hist_in_data_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist15:16;
        RBus_UInt32  ch2_c0_hist14:16;
    };
}histogram_ich2_c0_hist_in_data_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist17:16;
        RBus_UInt32  ch2_c0_hist16:16;
    };
}histogram_ich2_c0_hist_in_data_17_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist19:16;
        RBus_UInt32  ch2_c0_hist18:16;
    };
}histogram_ich2_c0_hist_in_data_19_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist21:16;
        RBus_UInt32  ch2_c0_hist20:16;
    };
}histogram_ich2_c0_hist_in_data_21_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist23:16;
        RBus_UInt32  ch2_c0_hist22:16;
    };
}histogram_ich2_c0_hist_in_data_23_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist25:16;
        RBus_UInt32  ch2_c0_hist24:16;
    };
}histogram_ich2_c0_hist_in_data_25_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist27:16;
        RBus_UInt32  ch2_c0_hist26:16;
    };
}histogram_ich2_c0_hist_in_data_27_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist29:16;
        RBus_UInt32  ch2_c0_hist28:16;
    };
}histogram_ich2_c0_hist_in_data_29_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist31:16;
        RBus_UInt32  ch2_c0_hist30:16;
    };
}histogram_ich2_c0_hist_in_data_31_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  ch2_c0_section1_bin_sel:5;
        RBus_UInt32  res2:11;
        RBus_UInt32  ch2_c0_section0_bin_sel:5;
    };
}histogram_ich2_c0_sectionhist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his0_hist01:16;
        RBus_UInt32  ch2_c0_section_his0_hist00:16;
    };
}histogram_ich2_c0_section0_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his0_hist03:16;
        RBus_UInt32  ch2_c0_section_his0_hist02:16;
    };
}histogram_ich2_c0_section0_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his0_hist05:16;
        RBus_UInt32  ch2_c0_section_his0_hist04:16;
    };
}histogram_ich2_c0_section0_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his0_hist07:16;
        RBus_UInt32  ch2_c0_section_his0_hist06:16;
    };
}histogram_ich2_c0_section0_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his1_hist01:16;
        RBus_UInt32  ch2_c0_section_his1_hist00:16;
    };
}histogram_ich2_c0_section1_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his1_hist03:16;
        RBus_UInt32  ch2_c0_section_his1_hist02:16;
    };
}histogram_ich2_c0_section1_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his1_hist05:16;
        RBus_UInt32  ch2_c0_section_his1_hist04:16;
    };
}histogram_ich2_c0_section1_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his1_hist07:16;
        RBus_UInt32  ch2_c0_section_his1_hist06:16;
    };
}histogram_ich2_c0_section1_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_c1_upper_bound:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch2_c1_lower_bound:10;
    };
}histogram_ich2_c1_hist_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_c1_upper_bound_u:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch2_c1_lower_bound_u:10;
    };
}histogram_ich2_c1_hist_bound_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_c1_upper_bound_v:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch2_c1_lower_bound_v:10;
    };
}histogram_ich2_c1_hist_bound_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist01:16;
        RBus_UInt32  ch2_c1_hist00:16;
    };
}histogram_ich2_c1_hist_in_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist03:16;
        RBus_UInt32  ch2_c1_hist02:16;
    };
}histogram_ich2_c1_hist_in_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist05:16;
        RBus_UInt32  ch2_c1_hist04:16;
    };
}histogram_ich2_c1_hist_in_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist07:16;
        RBus_UInt32  ch2_c1_hist06:16;
    };
}histogram_ich2_c1_hist_in_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist09:16;
        RBus_UInt32  ch2_c1_hist08:16;
    };
}histogram_ich2_c1_hist_in_data_09_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist11:16;
        RBus_UInt32  ch2_c1_hist10:16;
    };
}histogram_ich2_c1_hist_in_data_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist13:16;
        RBus_UInt32  ch2_c1_hist12:16;
    };
}histogram_ich2_c1_hist_in_data_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist15:16;
        RBus_UInt32  ch2_c1_hist14:16;
    };
}histogram_ich2_c1_hist_in_data_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist17:16;
        RBus_UInt32  ch2_c1_hist16:16;
    };
}histogram_ich2_c1_hist_in_data_17_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist19:16;
        RBus_UInt32  ch2_c1_hist18:16;
    };
}histogram_ich2_c1_hist_in_data_19_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist21:16;
        RBus_UInt32  ch2_c1_hist20:16;
    };
}histogram_ich2_c1_hist_in_data_21_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist23:16;
        RBus_UInt32  ch2_c1_hist22:16;
    };
}histogram_ich2_c1_hist_in_data_23_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist25:16;
        RBus_UInt32  ch2_c1_hist24:16;
    };
}histogram_ich2_c1_hist_in_data_25_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist27:16;
        RBus_UInt32  ch2_c1_hist26:16;
    };
}histogram_ich2_c1_hist_in_data_27_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist29:16;
        RBus_UInt32  ch2_c1_hist28:16;
    };
}histogram_ich2_c1_hist_in_data_29_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist31:16;
        RBus_UInt32  ch2_c1_hist30:16;
    };
}histogram_ich2_c1_hist_in_data_31_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  ch2_c1_section1_bin_sel:5;
        RBus_UInt32  res2:11;
        RBus_UInt32  ch2_c1_section0_bin_sel:5;
    };
}histogram_ich2_c1_sectionhist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his0_hist01:16;
        RBus_UInt32  ch2_c1_section_his0_hist00:16;
    };
}histogram_ich2_c1_section0_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his0_hist03:16;
        RBus_UInt32  ch2_c1_section_his0_hist02:16;
    };
}histogram_ich2_c1_section0_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his0_hist05:16;
        RBus_UInt32  ch2_c1_section_his0_hist04:16;
    };
}histogram_ich2_c1_section0_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his0_hist07:16;
        RBus_UInt32  ch2_c1_section_his0_hist06:16;
    };
}histogram_ich2_c1_section0_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his1_hist01:16;
        RBus_UInt32  ch2_c1_section_his1_hist00:16;
    };
}histogram_ich2_c1_section1_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his1_hist03:16;
        RBus_UInt32  ch2_c1_section_his1_hist02:16;
    };
}histogram_ich2_c1_section1_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his1_hist05:16;
        RBus_UInt32  ch2_c1_section_his1_hist04:16;
    };
}histogram_ich2_c1_section1_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his1_hist07:16;
        RBus_UInt32  ch2_c1_section_his1_hist06:16;
    };
}histogram_ich2_c1_section1_data_07_06_RBUS;

#else //apply LITTLE_ENDIAN

//======HISTOGRAM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_his_even_odd_fld_sel:1;
        RBus_UInt32  ch1_his_even_odd_fld_en:1;
        RBus_UInt32  ch1_his_even_odd_pos_sel:1;
        RBus_UInt32  ch1_his_even_odd_pos_en:1;
        RBus_UInt32  ch1_his_mode_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch1_his_offset:4;
        RBus_UInt32  ch1_his_shift_sel:3;
        RBus_UInt32  ch1_his_num_flds:4;
        RBus_UInt32  ch1_his_yuv_sel:2;
        RBus_UInt32  ch1_his_irq_en:1;
        RBus_UInt32  ch1_his_enable_histog:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  ch1_his_updatelockmode_en:1;
        RBus_UInt32  ch1_3d_en:1;
        RBus_UInt32  lr_select:1;
        RBus_UInt32  res4:5;
    };
}histogram_ich1_hist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_his_horstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_his_horend:13;
        RBus_UInt32  res2:3;
    };
}histogram_ich1_hist_in_range_hor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_his_verstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_his_verend:13;
        RBus_UInt32  res2:3;
    };
}histogram_ich1_hist_in_range_ver_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_his_his_irq:1;
        RBus_UInt32  ch1_his_dcc_invalid:1;
        RBus_UInt32  res1:30;
    };
}histogram_ich1_hist_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_his_min_val:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_his_max_val:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_hist_max_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bycolor_debug_mode:2;
        RBus_UInt32  res1:30;
    };
}histogram_ich1_bycolor_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_his_sumval_high:9;
        RBus_UInt32  res1:23;
    };
}histogram_ich1_hist_sumval_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_his_sumval_low:24;
        RBus_UInt32  res1:8;
    };
}histogram_ich1_hist_sumval_low_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_lower_bound:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c0_upper_bound:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_c0_hist_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_lower_bound_u:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c0_upper_bound_u:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_c0_hist_bound_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_lower_bound_v:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c0_upper_bound_v:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_c0_hist_bound_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist00:16;
        RBus_UInt32  ch1_c0_hist01:16;
    };
}histogram_ich1_c0_hist_in_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist02:16;
        RBus_UInt32  ch1_c0_hist03:16;
    };
}histogram_ich1_c0_hist_in_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist04:16;
        RBus_UInt32  ch1_c0_hist05:16;
    };
}histogram_ich1_c0_hist_in_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist06:16;
        RBus_UInt32  ch1_c0_hist07:16;
    };
}histogram_ich1_c0_hist_in_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist08:16;
        RBus_UInt32  ch1_c0_hist09:16;
    };
}histogram_ich1_c0_hist_in_data_09_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist10:16;
        RBus_UInt32  ch1_c0_hist11:16;
    };
}histogram_ich1_c0_hist_in_data_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist12:16;
        RBus_UInt32  ch1_c0_hist13:16;
    };
}histogram_ich1_c0_hist_in_data_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist14:16;
        RBus_UInt32  ch1_c0_hist15:16;
    };
}histogram_ich1_c0_hist_in_data_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist16:16;
        RBus_UInt32  ch1_c0_hist17:16;
    };
}histogram_ich1_c0_hist_in_data_17_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist18:16;
        RBus_UInt32  ch1_c0_hist19:16;
    };
}histogram_ich1_c0_hist_in_data_19_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist20:16;
        RBus_UInt32  ch1_c0_hist21:16;
    };
}histogram_ich1_c0_hist_in_data_21_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist22:16;
        RBus_UInt32  ch1_c0_hist23:16;
    };
}histogram_ich1_c0_hist_in_data_23_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist24:16;
        RBus_UInt32  ch1_c0_hist25:16;
    };
}histogram_ich1_c0_hist_in_data_25_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist26:16;
        RBus_UInt32  ch1_c0_hist27:16;
    };
}histogram_ich1_c0_hist_in_data_27_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist28:16;
        RBus_UInt32  ch1_c0_hist29:16;
    };
}histogram_ich1_c0_hist_in_data_29_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist30:16;
        RBus_UInt32  ch1_c0_hist31:16;
    };
}histogram_ich1_c0_hist_in_data_31_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section0_bin_sel:5;
        RBus_UInt32  res1:11;
        RBus_UInt32  ch1_c0_section1_bin_sel:5;
        RBus_UInt32  res2:11;
    };
}histogram_ich1_c0_sectionhist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist00:16;
        RBus_UInt32  ch1_c0_section_his0_hist01:16;
    };
}histogram_ich1_c0_section0_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist02:16;
        RBus_UInt32  ch1_c0_section_his0_hist03:16;
    };
}histogram_ich1_c0_section0_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist04:16;
        RBus_UInt32  ch1_c0_section_his0_hist05:16;
    };
}histogram_ich1_c0_section0_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist06:16;
        RBus_UInt32  ch1_c0_section_his0_hist07:16;
    };
}histogram_ich1_c0_section0_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist00:16;
        RBus_UInt32  ch1_c0_section_his1_hist01:16;
    };
}histogram_ich1_c0_section1_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist02:16;
        RBus_UInt32  ch1_c0_section_his1_hist03:16;
    };
}histogram_ich1_c0_section1_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist04:16;
        RBus_UInt32  ch1_c0_section_his1_hist05:16;
    };
}histogram_ich1_c0_section1_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist06:16;
        RBus_UInt32  ch1_c0_section_his1_hist07:16;
    };
}histogram_ich1_c0_section1_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_lower_bound:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c1_upper_bound:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_c1_hist_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_lower_bound_u:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c1_upper_bound_u:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_c1_hist_bound_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_lower_bound_v:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c1_upper_bound_v:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_c1_hist_bound_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist00:16;
        RBus_UInt32  ch1_c1_hist01:16;
    };
}histogram_ich1_c1_hist_in_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist02:16;
        RBus_UInt32  ch1_c1_hist03:16;
    };
}histogram_ich1_c1_hist_in_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist04:16;
        RBus_UInt32  ch1_c1_hist05:16;
    };
}histogram_ich1_c1_hist_in_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist06:16;
        RBus_UInt32  ch1_c1_hist07:16;
    };
}histogram_ich1_c1_hist_in_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist08:16;
        RBus_UInt32  ch1_c1_hist09:16;
    };
}histogram_ich1_c1_hist_in_data_09_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist10:16;
        RBus_UInt32  ch1_c1_hist11:16;
    };
}histogram_ich1_c1_hist_in_data_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist12:16;
        RBus_UInt32  ch1_c1_hist13:16;
    };
}histogram_ich1_c1_hist_in_data_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist14:16;
        RBus_UInt32  ch1_c1_hist15:16;
    };
}histogram_ich1_c1_hist_in_data_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist16:16;
        RBus_UInt32  ch1_c1_hist17:16;
    };
}histogram_ich1_c1_hist_in_data_17_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist18:16;
        RBus_UInt32  ch1_c1_hist19:16;
    };
}histogram_ich1_c1_hist_in_data_19_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist20:16;
        RBus_UInt32  ch1_c1_hist21:16;
    };
}histogram_ich1_c1_hist_in_data_21_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist22:16;
        RBus_UInt32  ch1_c1_hist23:16;
    };
}histogram_ich1_c1_hist_in_data_23_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist24:16;
        RBus_UInt32  ch1_c1_hist25:16;
    };
}histogram_ich1_c1_hist_in_data_25_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist26:16;
        RBus_UInt32  ch1_c1_hist27:16;
    };
}histogram_ich1_c1_hist_in_data_27_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist28:16;
        RBus_UInt32  ch1_c1_hist29:16;
    };
}histogram_ich1_c1_hist_in_data_29_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist30:16;
        RBus_UInt32  ch1_c1_hist31:16;
    };
}histogram_ich1_c1_hist_in_data_31_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section0_bin_sel:5;
        RBus_UInt32  res1:11;
        RBus_UInt32  ch1_c1_section1_bin_sel:5;
        RBus_UInt32  res2:11;
    };
}histogram_ich1_c1_sectionhist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist00:16;
        RBus_UInt32  ch1_c1_section_his0_hist01:16;
    };
}histogram_ich1_c1_section0_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist02:16;
        RBus_UInt32  ch1_c1_section_his0_hist03:16;
    };
}histogram_ich1_c1_section0_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist04:16;
        RBus_UInt32  ch1_c1_section_his0_hist05:16;
    };
}histogram_ich1_c1_section0_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist06:16;
        RBus_UInt32  ch1_c1_section_his0_hist07:16;
    };
}histogram_ich1_c1_section0_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist00:16;
        RBus_UInt32  ch1_c1_section_his1_hist01:16;
    };
}histogram_ich1_c1_section1_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist02:16;
        RBus_UInt32  ch1_c1_section_his1_hist03:16;
    };
}histogram_ich1_c1_section1_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist04:16;
        RBus_UInt32  ch1_c1_section_his1_hist05:16;
    };
}histogram_ich1_c1_section1_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist06:16;
        RBus_UInt32  ch1_c1_section_his1_hist07:16;
    };
}histogram_ich1_c1_section1_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch2_his_even_odd_fld_sel:1;
        RBus_UInt32  ch2_his_even_odd_fld_en:1;
        RBus_UInt32  ch2_his_even_odd_pos_sel:1;
        RBus_UInt32  ch2_his_even_odd_pos_en:1;
        RBus_UInt32  ch2_his_mode_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch2_his_offset:4;
        RBus_UInt32  ch2_his_shift_sel:3;
        RBus_UInt32  ch2_his_num_flds:4;
        RBus_UInt32  ch2_his_yuv_sel:2;
        RBus_UInt32  ch2_his_irq_en:1;
        RBus_UInt32  ch2_his_enable_histog:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  ch2_his_updatelockmode_en:1;
        RBus_UInt32  res4:7;
    };
}histogram_ich2_hist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_his_horstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ch2_his_horend:13;
        RBus_UInt32  res2:3;
    };
}histogram_ich2_hist_in_range_hor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_his_verstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ch2_his_verend:13;
        RBus_UInt32  res2:3;
    };
}histogram_ich2_hist_in_range_ver_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_his_his_irq:1;
        RBus_UInt32  ch2_his_dcc_invalid:1;
        RBus_UInt32  res1:30;
    };
}histogram_ich2_hist_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_his_min_val:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_his_max_val:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich2_hist_max_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bycolor_debug_mode:2;
        RBus_UInt32  res1:30;
    };
}histogram_ich2_bycolor_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_his_sumval_high:9;
        RBus_UInt32  res1:23;
    };
}histogram_ich2_hist_sumval_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_his_sumval_low:24;
        RBus_UInt32  res1:8;
    };
}histogram_ich2_hist_sumval_low_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_lower_bound:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_c0_upper_bound:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich2_c0_hist_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_lower_bound_u:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_c0_upper_bound_u:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich2_c0_hist_bound_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_lower_bound_v:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_c0_upper_bound_v:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich2_c0_hist_bound_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist00:16;
        RBus_UInt32  ch2_c0_hist01:16;
    };
}histogram_ich2_c0_hist_in_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist02:16;
        RBus_UInt32  ch2_c0_hist03:16;
    };
}histogram_ich2_c0_hist_in_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist04:16;
        RBus_UInt32  ch2_c0_hist05:16;
    };
}histogram_ich2_c0_hist_in_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist06:16;
        RBus_UInt32  ch2_c0_hist07:16;
    };
}histogram_ich2_c0_hist_in_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist08:16;
        RBus_UInt32  ch2_c0_hist09:16;
    };
}histogram_ich2_c0_hist_in_data_09_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist10:16;
        RBus_UInt32  ch2_c0_hist11:16;
    };
}histogram_ich2_c0_hist_in_data_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist12:16;
        RBus_UInt32  ch2_c0_hist13:16;
    };
}histogram_ich2_c0_hist_in_data_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist14:16;
        RBus_UInt32  ch2_c0_hist15:16;
    };
}histogram_ich2_c0_hist_in_data_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist16:16;
        RBus_UInt32  ch2_c0_hist17:16;
    };
}histogram_ich2_c0_hist_in_data_17_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist18:16;
        RBus_UInt32  ch2_c0_hist19:16;
    };
}histogram_ich2_c0_hist_in_data_19_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist20:16;
        RBus_UInt32  ch2_c0_hist21:16;
    };
}histogram_ich2_c0_hist_in_data_21_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist22:16;
        RBus_UInt32  ch2_c0_hist23:16;
    };
}histogram_ich2_c0_hist_in_data_23_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist24:16;
        RBus_UInt32  ch2_c0_hist25:16;
    };
}histogram_ich2_c0_hist_in_data_25_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist26:16;
        RBus_UInt32  ch2_c0_hist27:16;
    };
}histogram_ich2_c0_hist_in_data_27_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist28:16;
        RBus_UInt32  ch2_c0_hist29:16;
    };
}histogram_ich2_c0_hist_in_data_29_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_hist30:16;
        RBus_UInt32  ch2_c0_hist31:16;
    };
}histogram_ich2_c0_hist_in_data_31_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section0_bin_sel:5;
        RBus_UInt32  res1:11;
        RBus_UInt32  ch2_c0_section1_bin_sel:5;
        RBus_UInt32  res2:11;
    };
}histogram_ich2_c0_sectionhist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his0_hist00:16;
        RBus_UInt32  ch2_c0_section_his0_hist01:16;
    };
}histogram_ich2_c0_section0_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his0_hist02:16;
        RBus_UInt32  ch2_c0_section_his0_hist03:16;
    };
}histogram_ich2_c0_section0_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his0_hist04:16;
        RBus_UInt32  ch2_c0_section_his0_hist05:16;
    };
}histogram_ich2_c0_section0_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his0_hist06:16;
        RBus_UInt32  ch2_c0_section_his0_hist07:16;
    };
}histogram_ich2_c0_section0_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his1_hist00:16;
        RBus_UInt32  ch2_c0_section_his1_hist01:16;
    };
}histogram_ich2_c0_section1_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his1_hist02:16;
        RBus_UInt32  ch2_c0_section_his1_hist03:16;
    };
}histogram_ich2_c0_section1_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his1_hist04:16;
        RBus_UInt32  ch2_c0_section_his1_hist05:16;
    };
}histogram_ich2_c0_section1_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c0_section_his1_hist06:16;
        RBus_UInt32  ch2_c0_section_his1_hist07:16;
    };
}histogram_ich2_c0_section1_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_lower_bound:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_c1_upper_bound:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich2_c1_hist_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_lower_bound_u:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_c1_upper_bound_u:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich2_c1_hist_bound_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_lower_bound_v:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch2_c1_upper_bound_v:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich2_c1_hist_bound_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist00:16;
        RBus_UInt32  ch2_c1_hist01:16;
    };
}histogram_ich2_c1_hist_in_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist02:16;
        RBus_UInt32  ch2_c1_hist03:16;
    };
}histogram_ich2_c1_hist_in_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist04:16;
        RBus_UInt32  ch2_c1_hist05:16;
    };
}histogram_ich2_c1_hist_in_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist06:16;
        RBus_UInt32  ch2_c1_hist07:16;
    };
}histogram_ich2_c1_hist_in_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist08:16;
        RBus_UInt32  ch2_c1_hist09:16;
    };
}histogram_ich2_c1_hist_in_data_09_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist10:16;
        RBus_UInt32  ch2_c1_hist11:16;
    };
}histogram_ich2_c1_hist_in_data_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist12:16;
        RBus_UInt32  ch2_c1_hist13:16;
    };
}histogram_ich2_c1_hist_in_data_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist14:16;
        RBus_UInt32  ch2_c1_hist15:16;
    };
}histogram_ich2_c1_hist_in_data_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist16:16;
        RBus_UInt32  ch2_c1_hist17:16;
    };
}histogram_ich2_c1_hist_in_data_17_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist18:16;
        RBus_UInt32  ch2_c1_hist19:16;
    };
}histogram_ich2_c1_hist_in_data_19_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist20:16;
        RBus_UInt32  ch2_c1_hist21:16;
    };
}histogram_ich2_c1_hist_in_data_21_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist22:16;
        RBus_UInt32  ch2_c1_hist23:16;
    };
}histogram_ich2_c1_hist_in_data_23_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist24:16;
        RBus_UInt32  ch2_c1_hist25:16;
    };
}histogram_ich2_c1_hist_in_data_25_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist26:16;
        RBus_UInt32  ch2_c1_hist27:16;
    };
}histogram_ich2_c1_hist_in_data_27_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist28:16;
        RBus_UInt32  ch2_c1_hist29:16;
    };
}histogram_ich2_c1_hist_in_data_29_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_hist30:16;
        RBus_UInt32  ch2_c1_hist31:16;
    };
}histogram_ich2_c1_hist_in_data_31_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section0_bin_sel:5;
        RBus_UInt32  res1:11;
        RBus_UInt32  ch2_c1_section1_bin_sel:5;
        RBus_UInt32  res2:11;
    };
}histogram_ich2_c1_sectionhist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his0_hist00:16;
        RBus_UInt32  ch2_c1_section_his0_hist01:16;
    };
}histogram_ich2_c1_section0_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his0_hist02:16;
        RBus_UInt32  ch2_c1_section_his0_hist03:16;
    };
}histogram_ich2_c1_section0_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his0_hist04:16;
        RBus_UInt32  ch2_c1_section_his0_hist05:16;
    };
}histogram_ich2_c1_section0_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his0_hist06:16;
        RBus_UInt32  ch2_c1_section_his0_hist07:16;
    };
}histogram_ich2_c1_section0_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his1_hist00:16;
        RBus_UInt32  ch2_c1_section_his1_hist01:16;
    };
}histogram_ich2_c1_section1_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his1_hist02:16;
        RBus_UInt32  ch2_c1_section_his1_hist03:16;
    };
}histogram_ich2_c1_section1_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his1_hist04:16;
        RBus_UInt32  ch2_c1_section_his1_hist05:16;
    };
}histogram_ich2_c1_section1_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_c1_section_his1_hist06:16;
        RBus_UInt32  ch2_c1_section_his1_hist07:16;
    };
}histogram_ich2_c1_section1_data_07_06_RBUS;




#endif 


#endif 
