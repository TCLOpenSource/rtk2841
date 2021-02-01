/**
* @file rbusColor_osd_shpnrReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/7/14
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_OSD_SHPNR_REG_H_
#define _RBUS_COLOR_OSD_SHPNR_REG_H_

#include "rbusTypes.h"



//  COLOR_OSD_SHPNR Register Address



#define  COLOR_OSD_SHPNR_OSD_HPEAKING_CTRL_1_VADDR          	(0xb802ab00)
#define  COLOR_OSD_SHPNR_OSD_HPEAKING_FILTER_1_VADDR        	(0xb802ab04)
#define  COLOR_OSD_SHPNR_OSD_EMF_CTRL_1_VADDR               	(0xb802ab08)
#define  COLOR_OSD_SHPNR_OSD_EMF_EXTENT_1_VADDR             	(0xb802ab0c)
#define  COLOR_OSD_SHPNR_OSD_HPEAKING_GAIN_1_VADDR          	(0xb802ab10)
#define  COLOR_OSD_SHPNR_OSD_HPEAKING_BOUND_1_VADDR         	(0xb802ab14)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR_OSD_SHPNR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  dummy1802ab00_11_2:10;
        RBus_UInt32  osd_shpnr_en_ch1:1;
        RBus_UInt32  peaking_enable_ch1:1;
    };
}color_osd_shpnr_osd_hpeaking_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c2_ch1:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  c1_ch1:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  c0_ch1:9;
    };
}color_osd_shpnr_osd_hpeaking_filter_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  seg0_offset_ch1:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  seg2_gain_sel_ch1:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  seg1_gain_sel_ch1:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  seg0_gain_sel_ch1:3;
        RBus_UInt32  res5:3;
        RBus_UInt32  emf_range_ch1:1;
        RBus_UInt32  emf_shift_ch1:3;
        RBus_UInt32  emf_en_ch1:1;
    };
}color_osd_shpnr_osd_emf_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg2_offset_ch1:11;
        RBus_UInt32  seg1_offset_ch1:11;
        RBus_UInt32  res1:2;
        RBus_UInt32  emf_fixextent_ch1:8;
    };
}color_osd_shpnr_osd_emf_extent_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  gain_blr_ch1:8;
        RBus_UInt32  gain_pos_ch1:8;
        RBus_UInt32  gain_neg_ch1:8;
    };
}color_osd_shpnr_osd_hpeaking_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos_ch1:10;
        RBus_UInt32  hv_neg_ch1:10;
        RBus_UInt32  lv_ch1:8;
    };
}color_osd_shpnr_osd_hpeaking_bound_1_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR_OSD_SHPNR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peaking_enable_ch1:1;
        RBus_UInt32  osd_shpnr_en_ch1:1;
        RBus_UInt32  dummy1802ab00_11:10;
        RBus_UInt32  res1:20;
    };
}color_osd_shpnr_osd_hpeaking_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0_ch1:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  c1_ch1:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  c2_ch1:8;
    };
}color_osd_shpnr_osd_hpeaking_filter_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emf_en_ch1:1;
        RBus_UInt32  emf_shift_ch1:3;
        RBus_UInt32  emf_range_ch1:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  seg0_gain_sel_ch1:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  seg1_gain_sel_ch1:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  seg2_gain_sel_ch1:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  seg0_offset_ch1:11;
        RBus_UInt32  res5:1;
    };
}color_osd_shpnr_osd_emf_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emf_fixextent_ch1:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  seg1_offset_ch1:11;
        RBus_UInt32  seg2_offset_ch1:11;
    };
}color_osd_shpnr_osd_emf_extent_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg_ch1:8;
        RBus_UInt32  gain_pos_ch1:8;
        RBus_UInt32  gain_blr_ch1:8;
        RBus_UInt32  res1:8;
    };
}color_osd_shpnr_osd_hpeaking_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv_ch1:8;
        RBus_UInt32  hv_neg_ch1:10;
        RBus_UInt32  hv_pos_ch1:10;
        RBus_UInt32  res1:4;
    };
}color_osd_shpnr_osd_hpeaking_bound_1_RBUS;




#endif 


#endif 
