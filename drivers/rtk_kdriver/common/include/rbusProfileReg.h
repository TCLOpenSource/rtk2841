/**
* @file rbusProfileReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PROFILE_REG_H_
#define _RBUS_PROFILE_REG_H_

#include "rbusTypes.h"



//  PROFILE Register Address



#define  PROFILE_ICH1_HIST_PROFILE_CTRL_VADDR               	(0xb8023400)
#define  PROFILE_ICH1_HIST_PROFILE_SIZE_VADDR               	(0xb8023404)
#define  PROFILE_ICH1_HIST_PROFILE_STARTH_VADDR             	(0xb8023408)
#define  PROFILE_ICH1_HIST_PROFILE_STARTV_VADDR             	(0xb802340c)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_00_VADDR            	(0xb8023410)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_01_VADDR            	(0xb8023414)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_02_VADDR            	(0xb8023418)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_03_VADDR            	(0xb802341c)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_04_VADDR            	(0xb8023420)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_05_VADDR            	(0xb8023424)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_06_VADDR            	(0xb8023428)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_07_VADDR            	(0xb802342c)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_08_VADDR            	(0xb8023430)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_09_VADDR            	(0xb8023434)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_10_VADDR            	(0xb8023438)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_11_VADDR            	(0xb802343c)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_12_VADDR            	(0xb8023440)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_13_VADDR            	(0xb8023444)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_14_VADDR            	(0xb8023448)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_15_VADDR            	(0xb802344c)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_16_VADDR            	(0xb8023450)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_17_VADDR            	(0xb8023454)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_18_VADDR            	(0xb8023458)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_19_VADDR            	(0xb802345c)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_20_VADDR            	(0xb8023460)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_21_VADDR            	(0xb8023464)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_22_VADDR            	(0xb8023468)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_23_VADDR            	(0xb802346c)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_24_VADDR            	(0xb8023470)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_25_VADDR            	(0xb8023474)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_26_VADDR            	(0xb8023478)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_27_VADDR            	(0xb802347c)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_28_VADDR            	(0xb8023480)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_29_VADDR            	(0xb8023484)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_30_VADDR            	(0xb8023488)
#define  PROFILE_ICH1_HIST_PROFILE_DATA_31_VADDR            	(0xb802348c)
#define  PROFILE_ICH1_HIST_PROFILE_DIFF_VADDR               	(0xb8023490)
#define  PROFILE_ICH1_HIST_PROFILE_DIFF_TH_VADDR            	(0xb8023494)
#define  PROFILE_ICH1_HIST_PROFILE_DIFF_BIN_L_VADDR         	(0xb8023498)
#define  PROFILE_ICH1_HIST_PROFILE_DIFF_BIN_M_VADDR         	(0xb802349c)
#define  PROFILE_ICH1_HIST_PROFILE_DIFF_BIN_H_VADDR         	(0xb80234a0)
#define  PROFILE_ICH1_HIST_PROFILE2_CTRL_VADDR              	(0xb80234a4)
#define  PROFILE_ICH1_HIST_PROFILE2_SIZE_VADDR              	(0xb80234a8)
#define  PROFILE_ICH1_HIST_PROFILE2_STARTH_VADDR            	(0xb80234ac)
#define  PROFILE_ICH1_HIST_PROFILE2_STARTV_VADDR            	(0xb80234b0)
#define  PROFILE_ICH1_HIST_PROFILE2_DIFF_VADDR              	(0xb80234b4)
#define  PROFILE_ICH1_HIST_PROFILE2_DIFF_TH_VADDR           	(0xb80234b8)
#define  PROFILE_ICH1_HIST_PROFILE2_DIFF_BIN_L_VADDR        	(0xb80234bc)
#define  PROFILE_ICH1_HIST_PROFILE2_DIFF_BIN_M_VADDR        	(0xb80234c0)
#define  PROFILE_ICH1_HIST_PROFILE2_DIFF_BIN_H_VADDR        	(0xb80234c4)
#define  PROFILE_SRCDET_CONTROL_VADDR                       	(0xb8023700)
#define  PROFILE_SRCDET_TSH_STEP_THL_VADDR                  	(0xb8023704)
#define  PROFILE_SRCDET_TSH_STEP_MAX_VADDR                  	(0xb8023708)
#define  PROFILE_SRCDET_TSH_STEP_MIN_VADDR                  	(0xb802370c)
#define  PROFILE_SRCDET_TSH_HIST01_VADDR                    	(0xb8023710)
#define  PROFILE_SRCDET_TSH_HIST02_VADDR                    	(0xb8023714)
#define  PROFILE_SRCDET_TSH_HIST03_VADDR                    	(0xb8023718)
#define  PROFILE_SRCDET_TSH_HIST04_VADDR                    	(0xb802371c)
#define  PROFILE_SRCDET_TSH_HIST05_VADDR                    	(0xb8023720)
#define  PROFILE_SRCDET_TSH_HIST06_VADDR                    	(0xb8023724)
#define  PROFILE_SRCDET_TSH_HIST07_VADDR                    	(0xb8023728)
#define  PROFILE_SRCDET_TSH_HIST08_VADDR                    	(0xb802372c)
#define  PROFILE_SRCDET_TSH_HIST09_VADDR                    	(0xb8023730)
#define  PROFILE_SRCDET_TSH_HIST10_VADDR                    	(0xb8023734)
#define  PROFILE_SRCDET_TSH_HIST11_VADDR                    	(0xb8023738)
#define  PROFILE_SRCDET_TSH_HIST12_VADDR                    	(0xb802373c)
#define  PROFILE_SRCDET_TSH_HIST13_VADDR                    	(0xb8023740)
#define  PROFILE_SRCDET_TSH_HIST14_VADDR                    	(0xb8023744)
#define  PROFILE_SRCDET_TSH_HIST15_VADDR                    	(0xb8023748)
#define  PROFILE_SRCDET_TSH_HIST16_VADDR                    	(0xb802374c)
#define  PROFILE_SRCDET_TSH_HIST17_VADDR                    	(0xb8023750)
#define  PROFILE_SRCDET_TSH_HIST18_VADDR                    	(0xb8023754)
#define  PROFILE_SRCDET_TSH_HIST19_VADDR                    	(0xb8023758)
#define  PROFILE_SRCDET_TSH_HIST20_VADDR                    	(0xb802375c)
#define  PROFILE_SRCDET_PMH_HIST0_VADDR                     	(0xb8023760)
#define  PROFILE_SRCDET_PMH_HIST1_VADDR                     	(0xb8023764)
#define  PROFILE_SRCDET_PMH_HIST2_VADDR                     	(0xb8023768)
#define  PROFILE_SRCDET_PMH_HIST3_VADDR                     	(0xb802376c)
#define  PROFILE_SRCDET_PMH_HIST4_VADDR                     	(0xb8023770)
#define  PROFILE_SRCDET_PMH_HIST5_VADDR                     	(0xb8023774)
#define  PROFILE_ICH1_HIST_PROFILE3_CTRL_VADDR              	(0xb8023780)
#define  PROFILE_ICH1_HIST_PROFILE3_SIZE_VADDR              	(0xb8023784)
#define  PROFILE_ICH1_HIST_PROFILE3_STARTH_VADDR            	(0xb8023788)
#define  PROFILE_ICH1_HIST_PROFILE3_STARTV_VADDR            	(0xb802378c)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_00_VADDR           	(0xb8023790)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_01_VADDR           	(0xb8023794)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_02_VADDR           	(0xb8023798)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_03_VADDR           	(0xb802379c)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_04_VADDR           	(0xb80237a0)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_05_VADDR           	(0xb80237a4)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_06_VADDR           	(0xb80237a8)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_07_VADDR           	(0xb80237ac)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_08_VADDR           	(0xb80237b0)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_09_VADDR           	(0xb80237b4)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_10_VADDR           	(0xb80237b8)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_11_VADDR           	(0xb80237bc)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_12_VADDR           	(0xb80237c0)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_13_VADDR           	(0xb80237c4)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_14_VADDR           	(0xb80237c8)
#define  PROFILE_ICH1_HIST_PROFILE3_DATA_15_VADDR           	(0xb80237cc)
#define  PROFILE_ICH1_HIST_PROFILE3_DIFF_VADDR              	(0xb80237d0)
#define  PROFILE_ICH1_HIST_PROFILE3_DIFF_TH_VADDR           	(0xb80237d4)
#define  PROFILE_ICH1_HIST_PROFILE3_DIFF_BIN_L_VADDR        	(0xb80237d8)
#define  PROFILE_ICH1_HIST_PROFILE3_DIFF_BIN_M_VADDR        	(0xb80237dc)
#define  PROFILE_ICH1_HIST_PROFILE3_DIFF_BIN_H_VADDR        	(0xb80237e0)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PROFILE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  dummy18023400_18_16:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  en_4k2k_mode:1;
        RBus_UInt32  en_3d_mode:1;
        RBus_UInt32  ch1_pf_yuv_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch1_pf_hnsr:2;
        RBus_UInt32  ch1_pf_vnsr:2;
        RBus_UInt32  ch1_pf_field_sel:2;
        RBus_UInt32  ch1_pf_overflow_sel:1;
        RBus_UInt32  ch1_pf_enable_profile:1;
    };
}profile_ich1_hist_profile_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_pf_vsize:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_pf_hsize:10;
    };
}profile_ich1_hist_profile_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ch1_pf_starth:14;
    };
}profile_ich1_hist_profile_starth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ch1_pf_startv:14;
    };
}profile_ich1_hist_profile_startv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h01:16;
        RBus_UInt32  ch1_pf_h00:16;
    };
}profile_ich1_hist_profile_data_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h03:16;
        RBus_UInt32  ch1_pf_h02:16;
    };
}profile_ich1_hist_profile_data_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h05:16;
        RBus_UInt32  ch1_pf_h04:16;
    };
}profile_ich1_hist_profile_data_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h07:16;
        RBus_UInt32  ch1_pf_h06:16;
    };
}profile_ich1_hist_profile_data_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h09:16;
        RBus_UInt32  ch1_pf_h08:16;
    };
}profile_ich1_hist_profile_data_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h11:16;
        RBus_UInt32  ch1_pf_h10:16;
    };
}profile_ich1_hist_profile_data_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h13:16;
        RBus_UInt32  ch1_pf_h12:16;
    };
}profile_ich1_hist_profile_data_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h15:16;
        RBus_UInt32  ch1_pf_h14:16;
    };
}profile_ich1_hist_profile_data_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v01:16;
        RBus_UInt32  ch1_pf_v00:16;
    };
}profile_ich1_hist_profile_data_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v03:16;
        RBus_UInt32  ch1_pf_v02:16;
    };
}profile_ich1_hist_profile_data_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v05:16;
        RBus_UInt32  ch1_pf_v04:16;
    };
}profile_ich1_hist_profile_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v07:16;
        RBus_UInt32  ch1_pf_v06:16;
    };
}profile_ich1_hist_profile_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v09:16;
        RBus_UInt32  ch1_pf_v08:16;
    };
}profile_ich1_hist_profile_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v11:16;
        RBus_UInt32  ch1_pf_v10:16;
    };
}profile_ich1_hist_profile_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v13:16;
        RBus_UInt32  ch1_pf_v12:16;
    };
}profile_ich1_hist_profile_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v15:16;
        RBus_UInt32  ch1_pf_v14:16;
    };
}profile_ich1_hist_profile_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h01_right:16;
        RBus_UInt32  ch1_pf_h00_right:16;
    };
}profile_ich1_hist_profile_data_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h03_right:16;
        RBus_UInt32  ch1_pf_h02_right:16;
    };
}profile_ich1_hist_profile_data_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h05_right:16;
        RBus_UInt32  ch1_pf_h04_right:16;
    };
}profile_ich1_hist_profile_data_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h07_right:16;
        RBus_UInt32  ch1_pf_h06_right:16;
    };
}profile_ich1_hist_profile_data_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h09_right:16;
        RBus_UInt32  ch1_pf_h08_right:16;
    };
}profile_ich1_hist_profile_data_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h11_right:16;
        RBus_UInt32  ch1_pf_h10_right:16;
    };
}profile_ich1_hist_profile_data_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h13_right:16;
        RBus_UInt32  ch1_pf_h12_right:16;
    };
}profile_ich1_hist_profile_data_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h15_right:16;
        RBus_UInt32  ch1_pf_h14_right:16;
    };
}profile_ich1_hist_profile_data_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v01_right:16;
        RBus_UInt32  ch1_pf_v00_right:16;
    };
}profile_ich1_hist_profile_data_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v03_right:16;
        RBus_UInt32  ch1_pf_v02_right:16;
    };
}profile_ich1_hist_profile_data_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v05_right:16;
        RBus_UInt32  ch1_pf_v04_right:16;
    };
}profile_ich1_hist_profile_data_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v07_right:16;
        RBus_UInt32  ch1_pf_v06_right:16;
    };
}profile_ich1_hist_profile_data_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v09_right:16;
        RBus_UInt32  ch1_pf_v08_right:16;
    };
}profile_ich1_hist_profile_data_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v11_right:16;
        RBus_UInt32  ch1_pf_v10_right:16;
    };
}profile_ich1_hist_profile_data_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v13_right:16;
        RBus_UInt32  ch1_pf_v12_right:16;
    };
}profile_ich1_hist_profile_data_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v15_right:16;
        RBus_UInt32  ch1_pf_v14_right:16;
    };
}profile_ich1_hist_profile_data_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_pf_diffsum:30;
    };
}profile_ich1_hist_profile_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ch1_pf_diff_th_h:8;
        RBus_UInt32  ch1_pf_diff_th_l:8;
    };
}profile_ich1_hist_profile_diff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf_diff_bin_l:24;
    };
}profile_ich1_hist_profile_diff_bin_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf_diff_bin_m:24;
    };
}profile_ich1_hist_profile_diff_bin_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf_diff_bin_h:24;
    };
}profile_ich1_hist_profile_diff_bin_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  ch1_pf2_yuv_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch1_pf2_hnsr:2;
        RBus_UInt32  ch1_pf2_vnsr:2;
        RBus_UInt32  ch1_pf2_field_sel:2;
        RBus_UInt32  ch1_pf2_overflow_sel:1;
        RBus_UInt32  ch1_pf2_enable_profile:1;
    };
}profile_ich1_hist_profile2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_pf2_vsize:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_pf2_hsize:10;
    };
}profile_ich1_hist_profile2_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ch1_pf2_starth:14;
    };
}profile_ich1_hist_profile2_starth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ch1_pf2_startv:14;
    };
}profile_ich1_hist_profile2_startv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_pf2_diffsum:30;
    };
}profile_ich1_hist_profile2_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ch1_pf2_diff_th_h:8;
        RBus_UInt32  ch1_pf2_diff_th_l:8;
    };
}profile_ich1_hist_profile2_diff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf2_diff_bin_l:24;
    };
}profile_ich1_hist_profile2_diff_bin_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf2_diff_bin_m:24;
    };
}profile_ich1_hist_profile2_diff_bin_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf2_diff_bin_h:24;
    };
}profile_ich1_hist_profile2_diff_bin_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  srcdet_pmh_depend_tsh:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  srcdet_start:1;
    };
}profile_srcdet_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  srcdet_tsh_step_thl:8;
    };
}profile_srcdet_tsh_step_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  srcdet_tsh_step_max:5;
    };
}profile_srcdet_tsh_step_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  srcdet_tsh_step_min:5;
    };
}profile_srcdet_tsh_step_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist01:22;
    };
}profile_srcdet_tsh_hist01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist02:22;
    };
}profile_srcdet_tsh_hist02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist03:22;
    };
}profile_srcdet_tsh_hist03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist04:22;
    };
}profile_srcdet_tsh_hist04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist05:22;
    };
}profile_srcdet_tsh_hist05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist06:22;
    };
}profile_srcdet_tsh_hist06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist07:22;
    };
}profile_srcdet_tsh_hist07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist08:22;
    };
}profile_srcdet_tsh_hist08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist09:22;
    };
}profile_srcdet_tsh_hist09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist10:22;
    };
}profile_srcdet_tsh_hist10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist11:22;
    };
}profile_srcdet_tsh_hist11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist12:22;
    };
}profile_srcdet_tsh_hist12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist13:22;
    };
}profile_srcdet_tsh_hist13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist14:22;
    };
}profile_srcdet_tsh_hist14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist15:22;
    };
}profile_srcdet_tsh_hist15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist16:22;
    };
}profile_srcdet_tsh_hist16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist17:22;
    };
}profile_srcdet_tsh_hist17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist18:22;
    };
}profile_srcdet_tsh_hist18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist19:22;
    };
}profile_srcdet_tsh_hist19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist20:22;
    };
}profile_srcdet_tsh_hist20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_pmh_hist0:22;
    };
}profile_srcdet_pmh_hist0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_pmh_hist1:22;
    };
}profile_srcdet_pmh_hist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_pmh_hist2:22;
    };
}profile_srcdet_pmh_hist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_pmh_hist3:22;
    };
}profile_srcdet_pmh_hist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_pmh_hist4:22;
    };
}profile_srcdet_pmh_hist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_pmh_hist5:22;
    };
}profile_srcdet_pmh_hist5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  ch1_pf3_yuv_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch1_pf3_hnsr:2;
        RBus_UInt32  ch1_pf3_vnsr:2;
        RBus_UInt32  ch1_pf3_field_sel:2;
        RBus_UInt32  ch1_pf3_overflow_sel:1;
        RBus_UInt32  ch1_pf3_enable_profile:1;
    };
}profile_ich1_hist_profile3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_pf3_vsize:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_pf3_hsize:10;
    };
}profile_ich1_hist_profile3_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ch1_pf3_starth:14;
    };
}profile_ich1_hist_profile3_starth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ch1_pf3_startv:14;
    };
}profile_ich1_hist_profile3_startv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h01:16;
        RBus_UInt32  ch1_pf3_h00:16;
    };
}profile_ich1_hist_profile3_data_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h03:16;
        RBus_UInt32  ch1_pf3_h02:16;
    };
}profile_ich1_hist_profile3_data_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h05:16;
        RBus_UInt32  ch1_pf3_h04:16;
    };
}profile_ich1_hist_profile3_data_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h07:16;
        RBus_UInt32  ch1_pf3_h06:16;
    };
}profile_ich1_hist_profile3_data_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h09:16;
        RBus_UInt32  ch1_pf3_h08:16;
    };
}profile_ich1_hist_profile3_data_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h11:16;
        RBus_UInt32  ch1_pf3_h10:16;
    };
}profile_ich1_hist_profile3_data_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h13:16;
        RBus_UInt32  ch1_pf3_h12:16;
    };
}profile_ich1_hist_profile3_data_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h15:16;
        RBus_UInt32  ch1_pf3_h14:16;
    };
}profile_ich1_hist_profile3_data_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v01:16;
        RBus_UInt32  ch1_pf3_v00:16;
    };
}profile_ich1_hist_profile3_data_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v03:16;
        RBus_UInt32  ch1_pf3_v02:16;
    };
}profile_ich1_hist_profile3_data_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v05:16;
        RBus_UInt32  ch1_pf3_v04:16;
    };
}profile_ich1_hist_profile3_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v07:16;
        RBus_UInt32  ch1_pf3_v06:16;
    };
}profile_ich1_hist_profile3_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v09:16;
        RBus_UInt32  ch1_pf3_v08:16;
    };
}profile_ich1_hist_profile3_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v11:16;
        RBus_UInt32  ch1_pf3_v10:16;
    };
}profile_ich1_hist_profile3_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v13:16;
        RBus_UInt32  ch1_pf3_v12:16;
    };
}profile_ich1_hist_profile3_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v15:16;
        RBus_UInt32  ch1_pf3_v14:16;
    };
}profile_ich1_hist_profile3_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_pf3_diffsum:30;
    };
}profile_ich1_hist_profile3_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ch1_pf3_diff_th_h:8;
        RBus_UInt32  ch1_pf3_diff_th_l:8;
    };
}profile_ich1_hist_profile3_diff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf3_diff_bin_l:24;
    };
}profile_ich1_hist_profile3_diff_bin_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf3_diff_bin_m:24;
    };
}profile_ich1_hist_profile3_diff_bin_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf3_diff_bin_h:24;
    };
}profile_ich1_hist_profile3_diff_bin_h_RBUS;

#else //apply LITTLE_ENDIAN

//======PROFILE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_enable_profile:1;
        RBus_UInt32  ch1_pf_overflow_sel:1;
        RBus_UInt32  ch1_pf_field_sel:2;
        RBus_UInt32  ch1_pf_vnsr:2;
        RBus_UInt32  ch1_pf_hnsr:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch1_pf_yuv_sel:2;
        RBus_UInt32  en_3d_mode:1;
        RBus_UInt32  en_4k2k_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dummy18023400_18:3;
        RBus_UInt32  res4:13;
    };
}profile_ich1_hist_profile_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_hsize:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_pf_vsize:10;
        RBus_UInt32  res2:6;
    };
}profile_ich1_hist_profile_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_starth:14;
        RBus_UInt32  res1:18;
    };
}profile_ich1_hist_profile_starth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_startv:14;
        RBus_UInt32  res1:18;
    };
}profile_ich1_hist_profile_startv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h00:16;
        RBus_UInt32  ch1_pf_h01:16;
    };
}profile_ich1_hist_profile_data_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h02:16;
        RBus_UInt32  ch1_pf_h03:16;
    };
}profile_ich1_hist_profile_data_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h04:16;
        RBus_UInt32  ch1_pf_h05:16;
    };
}profile_ich1_hist_profile_data_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h06:16;
        RBus_UInt32  ch1_pf_h07:16;
    };
}profile_ich1_hist_profile_data_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h08:16;
        RBus_UInt32  ch1_pf_h09:16;
    };
}profile_ich1_hist_profile_data_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h10:16;
        RBus_UInt32  ch1_pf_h11:16;
    };
}profile_ich1_hist_profile_data_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h12:16;
        RBus_UInt32  ch1_pf_h13:16;
    };
}profile_ich1_hist_profile_data_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h14:16;
        RBus_UInt32  ch1_pf_h15:16;
    };
}profile_ich1_hist_profile_data_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v00:16;
        RBus_UInt32  ch1_pf_v01:16;
    };
}profile_ich1_hist_profile_data_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v02:16;
        RBus_UInt32  ch1_pf_v03:16;
    };
}profile_ich1_hist_profile_data_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v04:16;
        RBus_UInt32  ch1_pf_v05:16;
    };
}profile_ich1_hist_profile_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v06:16;
        RBus_UInt32  ch1_pf_v07:16;
    };
}profile_ich1_hist_profile_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v08:16;
        RBus_UInt32  ch1_pf_v09:16;
    };
}profile_ich1_hist_profile_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v10:16;
        RBus_UInt32  ch1_pf_v11:16;
    };
}profile_ich1_hist_profile_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v12:16;
        RBus_UInt32  ch1_pf_v13:16;
    };
}profile_ich1_hist_profile_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v14:16;
        RBus_UInt32  ch1_pf_v15:16;
    };
}profile_ich1_hist_profile_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h00_right:16;
        RBus_UInt32  ch1_pf_h01_right:16;
    };
}profile_ich1_hist_profile_data_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h02_right:16;
        RBus_UInt32  ch1_pf_h03_right:16;
    };
}profile_ich1_hist_profile_data_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h04_right:16;
        RBus_UInt32  ch1_pf_h05_right:16;
    };
}profile_ich1_hist_profile_data_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h06_right:16;
        RBus_UInt32  ch1_pf_h07_right:16;
    };
}profile_ich1_hist_profile_data_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h08_right:16;
        RBus_UInt32  ch1_pf_h09_right:16;
    };
}profile_ich1_hist_profile_data_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h10_right:16;
        RBus_UInt32  ch1_pf_h11_right:16;
    };
}profile_ich1_hist_profile_data_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h12_right:16;
        RBus_UInt32  ch1_pf_h13_right:16;
    };
}profile_ich1_hist_profile_data_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h14_right:16;
        RBus_UInt32  ch1_pf_h15_right:16;
    };
}profile_ich1_hist_profile_data_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v00_right:16;
        RBus_UInt32  ch1_pf_v01_right:16;
    };
}profile_ich1_hist_profile_data_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v02_right:16;
        RBus_UInt32  ch1_pf_v03_right:16;
    };
}profile_ich1_hist_profile_data_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v04_right:16;
        RBus_UInt32  ch1_pf_v05_right:16;
    };
}profile_ich1_hist_profile_data_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v06_right:16;
        RBus_UInt32  ch1_pf_v07_right:16;
    };
}profile_ich1_hist_profile_data_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v08_right:16;
        RBus_UInt32  ch1_pf_v09_right:16;
    };
}profile_ich1_hist_profile_data_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v10_right:16;
        RBus_UInt32  ch1_pf_v11_right:16;
    };
}profile_ich1_hist_profile_data_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v12_right:16;
        RBus_UInt32  ch1_pf_v13_right:16;
    };
}profile_ich1_hist_profile_data_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v14_right:16;
        RBus_UInt32  ch1_pf_v15_right:16;
    };
}profile_ich1_hist_profile_data_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_diffsum:30;
        RBus_UInt32  res1:2;
    };
}profile_ich1_hist_profile_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_diff_th_l:8;
        RBus_UInt32  ch1_pf_diff_th_h:8;
        RBus_UInt32  res1:16;
    };
}profile_ich1_hist_profile_diff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_diff_bin_l:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile_diff_bin_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_diff_bin_m:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile_diff_bin_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_diff_bin_h:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile_diff_bin_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_enable_profile:1;
        RBus_UInt32  ch1_pf2_overflow_sel:1;
        RBus_UInt32  ch1_pf2_field_sel:2;
        RBus_UInt32  ch1_pf2_vnsr:2;
        RBus_UInt32  ch1_pf2_hnsr:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch1_pf2_yuv_sel:2;
        RBus_UInt32  res3:19;
    };
}profile_ich1_hist_profile2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_hsize:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_pf2_vsize:10;
        RBus_UInt32  res2:6;
    };
}profile_ich1_hist_profile2_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_starth:14;
        RBus_UInt32  res1:18;
    };
}profile_ich1_hist_profile2_starth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_startv:14;
        RBus_UInt32  res1:18;
    };
}profile_ich1_hist_profile2_startv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_diffsum:30;
        RBus_UInt32  res1:2;
    };
}profile_ich1_hist_profile2_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_diff_th_l:8;
        RBus_UInt32  ch1_pf2_diff_th_h:8;
        RBus_UInt32  res1:16;
    };
}profile_ich1_hist_profile2_diff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_diff_bin_l:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile2_diff_bin_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_diff_bin_m:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile2_diff_bin_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_diff_bin_h:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile2_diff_bin_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_start:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  srcdet_pmh_depend_tsh:1;
        RBus_UInt32  res2:27;
    };
}profile_srcdet_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_step_thl:8;
        RBus_UInt32  res1:24;
    };
}profile_srcdet_tsh_step_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_step_max:5;
        RBus_UInt32  res1:27;
    };
}profile_srcdet_tsh_step_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_step_min:5;
        RBus_UInt32  res1:27;
    };
}profile_srcdet_tsh_step_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist01:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist02:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist03:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist04:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist05:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist06:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist07:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist08:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist09:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist10:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist11:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist12:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist13:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist14:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist15:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist16:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist17:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist18:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist19:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist20:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_pmh_hist0:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_pmh_hist0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_pmh_hist1:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_pmh_hist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_pmh_hist2:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_pmh_hist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_pmh_hist3:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_pmh_hist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_pmh_hist4:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_pmh_hist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_pmh_hist5:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_pmh_hist5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_enable_profile:1;
        RBus_UInt32  ch1_pf3_overflow_sel:1;
        RBus_UInt32  ch1_pf3_field_sel:2;
        RBus_UInt32  ch1_pf3_vnsr:2;
        RBus_UInt32  ch1_pf3_hnsr:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch1_pf3_yuv_sel:2;
        RBus_UInt32  res3:19;
    };
}profile_ich1_hist_profile3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_hsize:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_pf3_vsize:10;
        RBus_UInt32  res2:6;
    };
}profile_ich1_hist_profile3_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_starth:14;
        RBus_UInt32  res1:18;
    };
}profile_ich1_hist_profile3_starth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_startv:14;
        RBus_UInt32  res1:18;
    };
}profile_ich1_hist_profile3_startv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h00:16;
        RBus_UInt32  ch1_pf3_h01:16;
    };
}profile_ich1_hist_profile3_data_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h02:16;
        RBus_UInt32  ch1_pf3_h03:16;
    };
}profile_ich1_hist_profile3_data_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h04:16;
        RBus_UInt32  ch1_pf3_h05:16;
    };
}profile_ich1_hist_profile3_data_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h06:16;
        RBus_UInt32  ch1_pf3_h07:16;
    };
}profile_ich1_hist_profile3_data_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h08:16;
        RBus_UInt32  ch1_pf3_h09:16;
    };
}profile_ich1_hist_profile3_data_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h10:16;
        RBus_UInt32  ch1_pf3_h11:16;
    };
}profile_ich1_hist_profile3_data_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h12:16;
        RBus_UInt32  ch1_pf3_h13:16;
    };
}profile_ich1_hist_profile3_data_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h14:16;
        RBus_UInt32  ch1_pf3_h15:16;
    };
}profile_ich1_hist_profile3_data_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v00:16;
        RBus_UInt32  ch1_pf3_v01:16;
    };
}profile_ich1_hist_profile3_data_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v02:16;
        RBus_UInt32  ch1_pf3_v03:16;
    };
}profile_ich1_hist_profile3_data_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v04:16;
        RBus_UInt32  ch1_pf3_v05:16;
    };
}profile_ich1_hist_profile3_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v06:16;
        RBus_UInt32  ch1_pf3_v07:16;
    };
}profile_ich1_hist_profile3_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v08:16;
        RBus_UInt32  ch1_pf3_v09:16;
    };
}profile_ich1_hist_profile3_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v10:16;
        RBus_UInt32  ch1_pf3_v11:16;
    };
}profile_ich1_hist_profile3_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v12:16;
        RBus_UInt32  ch1_pf3_v13:16;
    };
}profile_ich1_hist_profile3_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v14:16;
        RBus_UInt32  ch1_pf3_v15:16;
    };
}profile_ich1_hist_profile3_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_diffsum:30;
        RBus_UInt32  res1:2;
    };
}profile_ich1_hist_profile3_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_diff_th_l:8;
        RBus_UInt32  ch1_pf3_diff_th_h:8;
        RBus_UInt32  res1:16;
    };
}profile_ich1_hist_profile3_diff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_diff_bin_l:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile3_diff_bin_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_diff_bin_m:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile3_diff_bin_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_diff_bin_h:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile3_diff_bin_h_RBUS;




#endif 


#endif 
