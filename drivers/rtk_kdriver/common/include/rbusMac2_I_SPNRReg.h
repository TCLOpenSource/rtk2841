/**
* @file rbusMacArthur2-DesignSpec-I-Domain_SPNRReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2013/5/22
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MACARTHUR2_DESIGNSPEC_I_DOMAIN_SPNR_REG_H_
#define _RBUS_MACARTHUR2_DESIGNSPEC_I_DOMAIN_SPNR_REG_H_

#include "rbus/rbusTypes.h"



//  MACARTHUR2-DESIGNSPEC-I-DOMAIN_SPNR Register Address



#define  NR_DCH1_DEBUGMODE_VADDR 		(0xb8025000)
#define  NR_DCH1_CP_CTRL_VADDR 		(0xb8025004)
#define  NR_DCH1_IMPULSE_THL_VADDR 		(0xb8025008)
#define  NR_DCH1_IMPULSE_SMOOTHTHL_VADDR 		(0xb802500c)
#define  NR_DCH1_SPATIAL_THL_VADDR 		(0xb8025010)
#define  NR_DCH1_SPATIAL_THL2_VADDR 		(0xb8025014)
#define  NR_DCH1_SPATIAL_WEIGHT_VADDR 		(0xb8025018)
#define  NR_DCH1_LOCAL_VAR1_VADDR 		(0xb8025020)
#define  NR_DCH1_LOCAL_VAR2_VADDR 		(0xb8025024)
#define  NR_DCH1_MPEGNR1_VADDR 		(0xb802502c)
#define  NR_DCH1_NOISELEVEL1_VADDR 		(0xb8025030)
#define  NR_DCH1_NOISELEVEL2_VADDR 		(0xb8025034)
#define  NR_DCH1_MASK1_CTRL1_VADDR 		(0xb8025038)
#define  NR_DCH1_MASK1_CTRL2_VADDR 		(0xb802503c)
#define  NR_DCH1_MASK2_CTRL1_VADDR 		(0xb8025040)
#define  NR_DCH1_MASK2_CTRL2_VADDR 		(0xb8025044)
#define  NR_CURVE_MAPPING_CTRL_VADDR 		(0xb8025060)
#define  NR_CURVE_MAPPING_STEP_0_VADDR 		(0xb8025064)
#define  NR_CURVE_MAPPING_STEP_1_VADDR 		(0xb8025068)
#define  NR_CURVE_MAPPING_STEP_2_VADDR 		(0xb802506c)
#define  NR_CURVE_MAPPING_STEP_3_VADDR 		(0xb8025070)
#define  NR_CURVE_MAPPING_W1_1_VADDR 		(0xb8025074)
#define  NR_CURVE_MAPPING_W1_2_VADDR 		(0xb8025078)
#define  NR_CURVE_MAPPING_W2_1_VADDR 		(0xb802507c)
#define  NR_CURVE_MAPPING_W2_2_VADDR 		(0xb8025080)
#define  NR_NEW_LPF_NEARBY_CTRL_VADDR 		(0xb8025084)
#define  NR_SNR_DB_CTRL_VADDR 		(0xb8025088)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MACARTHUR2-DESIGNSPEC-I-DOMAIN_SPNR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dummy18025000_6_3:4;
        RBus_UInt32  cp_sweightydebug:2;
        RBus_UInt32  cp_debugmode:1;
    };
}dch1_debugmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_impulsewindow:1;
        RBus_UInt32  cp_iresultweight:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_sresultweight:3;
        RBus_UInt32  cp_zoranfiltersizey:2;
        RBus_UInt32  cp_zoranweight2y:2;
        RBus_UInt32  cp_zoranweight3y:2;
        RBus_UInt32  cp_zoranweight4y:2;
        RBus_UInt32  cp_zoranfiltersizec:2;
        RBus_UInt32  cp_zoranweight2c:2;
        RBus_UInt32  cp_zoranweight3c:2;
        RBus_UInt32  cp_zoranweight4c:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  cp_spatialenabley:1;
        RBus_UInt32  cp_spatialenablec:1;
        RBus_UInt32  cp_impulseenable:1;
        RBus_UInt32  res3:2;
    };
}dch1_cp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cp_ipixeldiffthly:4;
        RBus_UInt32  cp_ipixeldiffthlc:4;
        RBus_UInt32  cp_impulsethly:8;
        RBus_UInt32  cp_impulsethlc:8;
    };
}dch1_impulse_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_impulsethlyx2:8;
        RBus_UInt32  cp_impulsethlcx2:8;
        RBus_UInt32  cp_impulsesmooththly:8;
        RBus_UInt32  cp_impulsesmooththlc:8;
    };
}dch1_impulse_smooththl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_spatialthlyx2:8;
        RBus_UInt32  cp_spatialthlcx2:8;
        RBus_UInt32  cp_spatialthly:8;
        RBus_UInt32  cp_spatialthlc:8;
    };
}dch1_spatial_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  cp_spatialthlyx4:8;
        RBus_UInt32  cp_spatialthlcx4:8;
    };
}dch1_spatial_thl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_lpresultweightc:4;
        RBus_UInt32  cp_ringweighty:4;
        RBus_UInt32  cp_weight1y:4;
        RBus_UInt32  cp_weight2y:4;
        RBus_UInt32  cp_fixedweight1y:1;
        RBus_UInt32  cp_fixedweight2y:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  cp_ringrange:1;
        RBus_UInt32  cp_ringgain:1;
        RBus_UInt32  cp_ringsrc:2;
        RBus_UInt32  res2:5;
    };
}dch1_spatial_weight_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_max_local_var:16;
        RBus_UInt32  cp_mean_local_var:16;
    };
}dch1_local_var1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_sw_edge_thl:16;
        RBus_UInt32  res1:3;
        RBus_UInt32  cp_en_sw_edge_thl:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_var_ratio_thl:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  cp_en_yedgeforc:1;
        RBus_UInt32  cp_edge_weight:2;
    };
}dch1_local_var2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpglowerbound:8;
        RBus_UInt32  cp_mpgupperbound:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  cp_mpglpmode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_mpgidx_y:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cp_mpegresultweight_y:3;
        RBus_UInt32  cp_mpgidxmode_y:2;
        RBus_UInt32  cp_mpegenable_y_c:1;
        RBus_UInt32  cp_mpegenable_y_y:1;
    };
}dch1_mpegnr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_dsnoiselevel3:8;
        RBus_UInt32  cp_dsnoiselevel2:8;
        RBus_UInt32  cp_dsnoiselevel1:8;
        RBus_UInt32  cp_dsnoiselevel0:8;
    };
}dch1_noiselevel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_dsnoiselevel7:8;
        RBus_UInt32  cp_dsnoiselevel6:8;
        RBus_UInt32  cp_dsnoiselevel5:8;
        RBus_UInt32  cp_dsnoiselevel4:8;
    };
}dch1_noiselevel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mask1_yref:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_mask1_cbref:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_mask1_crref:6;
        RBus_UInt32  res3:4;
        RBus_UInt32  cp_mask1_ygain:2;
        RBus_UInt32  cp_mask1_cbgain:2;
        RBus_UInt32  cp_mask1_crgain:2;
    };
}dch1_mask1_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  cp_mask1_maplimit:3;
        RBus_UInt32  cp_mask1_mapthre:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_mask1_mapstep:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  cp_mask1_dir:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  cp_mask1_en:1;
    };
}dch1_mask1_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mask2_yref:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_mask2_cbref:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_mask2_crref:6;
        RBus_UInt32  res3:4;
        RBus_UInt32  cp_mask2_ygain:2;
        RBus_UInt32  cp_mask2_cbgain:2;
        RBus_UInt32  cp_mask2_crgain:2;
    };
}dch1_mask2_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  cp_mask2_maplimit:3;
        RBus_UInt32  cp_mask2_mapthre:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_mask2_mapstep:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  cp_mask2_dir:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  cp_mask2_en:1;
    };
}dch1_mask2_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18025060_31_2:30;
        RBus_UInt32  curvemappingmode_debug:1;
        RBus_UInt32  curvemappingmode_en:1;
    };
}curve_mapping_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step1:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  curvemapping_step2:9;
    };
}curve_mapping_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step3:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  curvemapping_step4:9;
    };
}curve_mapping_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step5:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  curvemapping_step6:9;
    };
}curve_mapping_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step7:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  curvemapping_step8:9;
    };
}curve_mapping_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_w1_0:4;
        RBus_UInt32  curvemapping_w1_1:4;
        RBus_UInt32  curvemapping_w1_2:4;
        RBus_UInt32  curvemapping_w1_3:4;
        RBus_UInt32  curvemapping_w1_4:4;
        RBus_UInt32  curvemapping_w1_5:4;
        RBus_UInt32  curvemapping_w1_6:4;
        RBus_UInt32  curvemapping_w1_7:4;
    };
}curve_mapping_w1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  curvemapping_w1_8:4;
    };
}curve_mapping_w1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_w2_0:4;
        RBus_UInt32  curvemapping_w2_1:4;
        RBus_UInt32  curvemapping_w2_2:4;
        RBus_UInt32  curvemapping_w2_3:4;
        RBus_UInt32  curvemapping_w2_4:4;
        RBus_UInt32  curvemapping_w2_5:4;
        RBus_UInt32  curvemapping_w2_6:4;
        RBus_UInt32  curvemapping_w2_7:4;
    };
}curve_mapping_w2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  curvemapping_w2_8:4;
    };
}curve_mapping_w2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smoothedgenearby_enable:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  smoothedgenearby_range:4;
        RBus_UInt32  smoothedgenearby_thd:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  modified_lpf_enable:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  modified_lpf_thr:10;
    };
}new_lpf_nearby_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  snr_db_apply:1;
        RBus_UInt32  snr_db_rd_sel:1;
        RBus_UInt32  snr_db_en:1;
    };
}snr_db_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======MACARTHUR2-DESIGNSPEC-I-DOMAIN_SPNR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_debugmode:1;
        RBus_UInt32  cp_sweightydebug:2;
        RBus_UInt32  dummy18025000_6:4;
        RBus_UInt32  res1:25;
    };
}dch1_debugmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_impulseenable:1;
        RBus_UInt32  cp_spatialenablec:1;
        RBus_UInt32  cp_spatialenabley:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cp_zoranweight4c:2;
        RBus_UInt32  cp_zoranweight3c:2;
        RBus_UInt32  cp_zoranweight2c:2;
        RBus_UInt32  cp_zoranfiltersizec:2;
        RBus_UInt32  cp_zoranweight4y:2;
        RBus_UInt32  cp_zoranweight3y:2;
        RBus_UInt32  cp_zoranweight2y:2;
        RBus_UInt32  cp_zoranfiltersizey:2;
        RBus_UInt32  cp_sresultweight:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cp_iresultweight:3;
        RBus_UInt32  cp_impulsewindow:1;
    };
}dch1_cp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_impulsethlc:8;
        RBus_UInt32  cp_impulsethly:8;
        RBus_UInt32  cp_ipixeldiffthlc:4;
        RBus_UInt32  cp_ipixeldiffthly:4;
        RBus_UInt32  res1:8;
    };
}dch1_impulse_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_impulsesmooththlc:8;
        RBus_UInt32  cp_impulsesmooththly:8;
        RBus_UInt32  cp_impulsethlcx2:8;
        RBus_UInt32  cp_impulsethlyx2:8;
    };
}dch1_impulse_smooththl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_spatialthlc:8;
        RBus_UInt32  cp_spatialthly:8;
        RBus_UInt32  cp_spatialthlcx2:8;
        RBus_UInt32  cp_spatialthlyx2:8;
    };
}dch1_spatial_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_spatialthlcx4:8;
        RBus_UInt32  cp_spatialthlyx4:8;
        RBus_UInt32  res1:16;
    };
}dch1_spatial_thl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  cp_ringsrc:2;
        RBus_UInt32  cp_ringgain:1;
        RBus_UInt32  cp_ringrange:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  cp_fixedweight2y:1;
        RBus_UInt32  cp_fixedweight1y:1;
        RBus_UInt32  cp_weight2y:4;
        RBus_UInt32  cp_weight1y:4;
        RBus_UInt32  cp_ringweighty:4;
        RBus_UInt32  cp_lpresultweightc:4;
    };
}dch1_spatial_weight_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mean_local_var:16;
        RBus_UInt32  cp_max_local_var:16;
    };
}dch1_local_var1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_edge_weight:2;
        RBus_UInt32  cp_en_yedgeforc:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_var_ratio_thl:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_en_sw_edge_thl:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  cp_sw_edge_thl:16;
    };
}dch1_local_var2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpegenable_y_y:1;
        RBus_UInt32  cp_mpegenable_y_c:1;
        RBus_UInt32  cp_mpgidxmode_y:2;
        RBus_UInt32  cp_mpegresultweight_y:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_mpgidx_y:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_mpglpmode:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  cp_mpgupperbound:8;
        RBus_UInt32  cp_mpglowerbound:8;
    };
}dch1_mpegnr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_dsnoiselevel0:8;
        RBus_UInt32  cp_dsnoiselevel1:8;
        RBus_UInt32  cp_dsnoiselevel2:8;
        RBus_UInt32  cp_dsnoiselevel3:8;
    };
}dch1_noiselevel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_dsnoiselevel4:8;
        RBus_UInt32  cp_dsnoiselevel5:8;
        RBus_UInt32  cp_dsnoiselevel6:8;
        RBus_UInt32  cp_dsnoiselevel7:8;
    };
}dch1_noiselevel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mask1_crgain:2;
        RBus_UInt32  cp_mask1_cbgain:2;
        RBus_UInt32  cp_mask1_ygain:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_mask1_crref:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_mask1_cbref:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cp_mask1_yref:6;
    };
}dch1_mask1_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mask1_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cp_mask1_dir:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cp_mask1_mapstep:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cp_mask1_mapthre:4;
        RBus_UInt32  cp_mask1_maplimit:3;
        RBus_UInt32  res4:13;
    };
}dch1_mask1_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mask2_crgain:2;
        RBus_UInt32  cp_mask2_cbgain:2;
        RBus_UInt32  cp_mask2_ygain:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_mask2_crref:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_mask2_cbref:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cp_mask2_yref:6;
    };
}dch1_mask2_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mask2_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cp_mask2_dir:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cp_mask2_mapstep:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cp_mask2_mapthre:4;
        RBus_UInt32  cp_mask2_maplimit:3;
        RBus_UInt32  res4:13;
    };
}dch1_mask2_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemappingmode_en:1;
        RBus_UInt32  curvemappingmode_debug:1;
        RBus_UInt32  dummy18025060_31:30;
    };
}curve_mapping_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_step2:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step1:9;
        RBus_UInt32  res2:7;
    };
}curve_mapping_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_step4:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step3:9;
        RBus_UInt32  res2:7;
    };
}curve_mapping_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_step6:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step5:9;
        RBus_UInt32  res2:7;
    };
}curve_mapping_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_step8:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step7:9;
        RBus_UInt32  res2:7;
    };
}curve_mapping_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_w1_7:4;
        RBus_UInt32  curvemapping_w1_6:4;
        RBus_UInt32  curvemapping_w1_5:4;
        RBus_UInt32  curvemapping_w1_4:4;
        RBus_UInt32  curvemapping_w1_3:4;
        RBus_UInt32  curvemapping_w1_2:4;
        RBus_UInt32  curvemapping_w1_1:4;
        RBus_UInt32  curvemapping_w1_0:4;
    };
}curve_mapping_w1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_w1_8:4;
        RBus_UInt32  res1:28;
    };
}curve_mapping_w1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_w2_7:4;
        RBus_UInt32  curvemapping_w2_6:4;
        RBus_UInt32  curvemapping_w2_5:4;
        RBus_UInt32  curvemapping_w2_4:4;
        RBus_UInt32  curvemapping_w2_3:4;
        RBus_UInt32  curvemapping_w2_2:4;
        RBus_UInt32  curvemapping_w2_1:4;
        RBus_UInt32  curvemapping_w2_0:4;
    };
}curve_mapping_w2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_w2_8:4;
        RBus_UInt32  res1:28;
    };
}curve_mapping_w2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  modified_lpf_thr:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  modified_lpf_enable:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  smoothedgenearby_thd:8;
        RBus_UInt32  smoothedgenearby_range:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  smoothedgenearby_enable:1;
    };
}new_lpf_nearby_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  snr_db_en:1;
        RBus_UInt32  snr_db_rd_sel:1;
        RBus_UInt32  snr_db_apply:1;
        RBus_UInt32  res1:29;
    };
}snr_db_ctrl_RBUS;




#endif 


#endif 
