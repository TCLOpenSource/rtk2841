/**
* @file rbusNrReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/6/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_NR_REG_H_
#define _RBUS_NR_REG_H_

#include "rbusTypes.h"



//  NR Register Address



#define  NR_DCH1_DEBUGMODE_VADDR                            	(0xb8025000)
#define  NR_DCH1_CP_CTRL_VADDR                              	(0xb8025004)
#define  NR_DCH1_IMPULSE_THL_VADDR                          	(0xb8025008)
#define  NR_DCH1_IMPULSE_SMOOTHTHL_VADDR                    	(0xb802500c)
#define  NR_DCH1_SPATIAL_THL_VADDR                          	(0xb8025010)
#define  NR_DCH1_SPATIAL_THL2_VADDR                         	(0xb8025014)
#define  NR_DCH1_SPATIAL_WEIGHT_VADDR                       	(0xb8025018)
#define  NR_DCH1_LOCAL_VAR1_VADDR                           	(0xb8025020)
#define  NR_DCH1_LOCAL_VAR2_VADDR                           	(0xb8025024)
#define  NR_DCH1_MPEGNR1_VADDR                              	(0xb802502c)
#define  NR_DCH1_NOISELEVEL1_VADDR                          	(0xb8025030)
#define  NR_DCH1_NOISELEVEL2_VADDR                          	(0xb8025034)
#define  NR_DCH1_MASK1_CTRL1_VADDR                          	(0xb8025038)
#define  NR_DCH1_MASK1_CTRL2_VADDR                          	(0xb802503c)
#define  NR_DCH1_MASK2_CTRL1_VADDR                          	(0xb8025040)
#define  NR_DCH1_MASK2_CTRL2_VADDR                          	(0xb8025044)
#define  NR_DCH1_MASK3_CTRL1_VADDR                          	(0xb8025048)
#define  NR_DCH1_MASK3_CTRL2_VADDR                          	(0xb802504c)
#define  NR_DCH1_MASK_SHIFT_CTRL1_VADDR                     	(0xb8025050)
#define  NR_DCH1_MASK_SHIFT_CTRL2_VADDR                     	(0xb8025054)
#define  NR_CURVE_MAPPING_CTRL_VADDR                        	(0xb8025060)
#define  NR_CURVE_MAPPING_STEP_0_VADDR                      	(0xb8025064)
#define  NR_CURVE_MAPPING_STEP_1_VADDR                      	(0xb8025068)
#define  NR_CURVE_MAPPING_STEP_2_VADDR                      	(0xb802506c)
#define  NR_CURVE_MAPPING_STEP_3_VADDR                      	(0xb8025070)
#define  NR_CURVE_MAPPING_W1_1_VADDR                        	(0xb8025074)
#define  NR_CURVE_MAPPING_W1_2_VADDR                        	(0xb8025078)
#define  NR_CURVE_MAPPING_W1_3_VADDR                        	(0xb802507c)
#define  NR_CURVE_MAPPING_W2_1_VADDR                        	(0xb8025080)
#define  NR_CURVE_MAPPING_W2_2_VADDR                        	(0xb8025084)
#define  NR_CURVE_MAPPING_W2_3_VADDR                        	(0xb8025088)
#define  NR_SNR_DB_CTRL_VADDR                               	(0xb802508c)
#define  NR_MOSQUITO_CTRL_VADDR                             	(0xb8025090)
#define  NR_MOSQUITO_NR_KEEP_EDGE_CTRL_VADDR                	(0xb8025094)
#define  NR_MOSQUITO_NR_LEVEL_CTRL_VADDR                    	(0xb8025098)
#define  NR_MOSQUITO_NR_LEVEL_CTRL_1_VADDR                  	(0xb802509c)
#define  NR_MOSQUITO_NR_DECAY_CTRL_1_VADDR                  	(0xb80250a8)
#define  NR_NEW_LPF_NEARBY_CTRL_VADDR                       	(0xb80250ac)
#define  NR_TYPE_DETECT_CTRL0_VADDR                         	(0xb80250b0)
#define  NR_TYPE_DETECT_CTRL1_VADDR                         	(0xb80250b4)
#define  NR_LINE_KEEP_CTRL0_VADDR                           	(0xb80250b8)
#define  NR_LINE_KEEP_CTRL1_VADDR                           	(0xb80250bc)
#define  NR_UV_MODIFIED_MOSQUITO_EDGE_CTRL0_VADDR           	(0xb80250c0)
#define  NR_UV_MODIFIED_MOSQUITO_EDGE_CTRL1_VADDR           	(0xb80250c4)
#define  NR_SPNR_ACT_LENGTH_VADDR                           	(0xb80250c8)
#define  NR_MNR_LEVEL_HISTOGRAM_CTRL_0_VADDR                	(0xb8025508)
#define  NR_MNR_LEVEL_HISTOGRAM_CTRL_1_VADDR                	(0xb802550c)
#define  NR_MNR_LEVEL_HISTOGRAM_CTRL_2_VADDR                	(0xb8025510)
#define  NR_MNR_LEVEL_HISTOGRAM_CTRL_3_VADDR                	(0xb8025514)
#define  NR_MNR_LEVEL_HISTOGRAM_CTRL_4_VADDR                	(0xb8025518)
#define  NR_MNR_LEVEL_HISTOGRAM_DATA_0_VADDR                	(0xb802551c)
#define  NR_MNR_LEVEL_HISTOGRAM_DATA_1_VADDR                	(0xb8025520)
#define  NR_MNR_LEVEL_HISTOGRAM_DATA_2_VADDR                	(0xb8025524)
#define  NR_MNR_LEVEL_HISTOGRAM_DATA_3_VADDR                	(0xb8025528)
#define  NR_MAXMIN_HISTOGRAM_CTRL_0_VADDR                   	(0xb8025530)
#define  NR_MAXMIN_HISTOGRAM_CTRL_1_VADDR                   	(0xb8025534)
#define  NR_MAXMIN_HISTOGRAM_CTRL_2_VADDR                   	(0xb8025538)
#define  NR_MAXMIN_HISTOGRAM_DATA_0_VADDR                   	(0xb802553c)
#define  NR_MAXMIN_HISTOGRAM_DATA_1_VADDR                   	(0xb8025540)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======NR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dummy18025000_6_5:2;
        RBus_UInt32  cp_debugmode:4;
        RBus_UInt32  cp_debugmode_en:1;
    };
}nr_dch1_debugmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  vc_snr_lpf_sel:2;
        RBus_UInt32  cp_sresultweight:4;
        RBus_UInt32  cp_zoranfiltersizey:2;
        RBus_UInt32  cp_zoranweight2y:2;
        RBus_UInt32  cp_zoranweight3y:2;
        RBus_UInt32  cp_zoranweight4y:2;
        RBus_UInt32  cp_zoranfiltersizec:2;
        RBus_UInt32  cp_zoranweight2c:2;
        RBus_UInt32  cp_zoranweight3c:2;
        RBus_UInt32  cp_zoranweight4c:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  sresultweight_adjust_shift:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cp_spatialenabley:1;
        RBus_UInt32  cp_spatialenablec:1;
        RBus_UInt32  cp_impulseenable:1;
    };
}nr_dch1_cp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_impulsewindow:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cp_iresultweight:3;
        RBus_UInt32  cp_ipixeldiffthly:4;
        RBus_UInt32  cp_ipixeldiffthlc:4;
        RBus_UInt32  cp_impulsethly:8;
        RBus_UInt32  cp_impulsethlc:8;
    };
}nr_dch1_impulse_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_impulsethlyx2:8;
        RBus_UInt32  cp_impulsethlcx2:8;
        RBus_UInt32  cp_impulsesmooththly:8;
        RBus_UInt32  cp_impulsesmooththlc:8;
    };
}nr_dch1_impulse_smooththl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_spatialthlyx2:8;
        RBus_UInt32  cp_spatialthlcx2:8;
        RBus_UInt32  cp_spatialthly:8;
        RBus_UInt32  cp_spatialthlc:8;
    };
}nr_dch1_spatial_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  cp_spatialthlyx4:8;
        RBus_UInt32  cp_spatialthlcx4:8;
    };
}nr_dch1_spatial_thl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_lpresultweightc:4;
        RBus_UInt32  cp_ringweighty:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  cp_weight1y:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  cp_weight2y:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  cp_fixedweight1y:1;
        RBus_UInt32  cp_fixedweight2y:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  cp_ringrange:1;
        RBus_UInt32  cp_ringgain:1;
    };
}nr_dch1_spatial_weight_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_max_local_var:16;
        RBus_UInt32  cp_mean_local_var:16;
    };
}nr_dch1_local_var1_RBUS;

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
}nr_dch1_local_var2_RBUS;

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
}nr_dch1_mpegnr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_dsnoiselevel3:8;
        RBus_UInt32  cp_dsnoiselevel2:8;
        RBus_UInt32  cp_dsnoiselevel1:8;
        RBus_UInt32  cp_dsnoiselevel0:8;
    };
}nr_dch1_noiselevel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_dsnoiselevel7:8;
        RBus_UInt32  cp_dsnoiselevel6:8;
        RBus_UInt32  cp_dsnoiselevel5:8;
        RBus_UInt32  cp_dsnoiselevel4:8;
    };
}nr_dch1_noiselevel2_RBUS;

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
}nr_dch1_mask1_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cp_mask1_maplimit:4;
        RBus_UInt32  cp_mask1_mapthre:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_mask1_mapstep:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  cp_mask1_dir:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  cp_mask1_en:1;
    };
}nr_dch1_mask1_ctrl2_RBUS;

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
}nr_dch1_mask2_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cp_mask2_maplimit:4;
        RBus_UInt32  cp_mask2_mapthre:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_mask2_mapstep:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  cp_mask2_dir:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  cp_mask2_en:1;
    };
}nr_dch1_mask2_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mask3_yref:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_mask3_cbref:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_mask3_crref:6;
        RBus_UInt32  res3:4;
        RBus_UInt32  cp_mask3_ygain:2;
        RBus_UInt32  cp_mask3_cbgain:2;
        RBus_UInt32  cp_mask3_crgain:2;
    };
}nr_dch1_mask3_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cp_mask3_maplimit:4;
        RBus_UInt32  cp_mask3_mapthre:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_mask3_mapstep:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  cp_mask3_dir:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  cp_mask3_en:1;
    };
}nr_dch1_mask3_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  nr_mask2_w2_mapstep:3;
        RBus_UInt32  nr_mask2_w2_maplimit:4;
        RBus_UInt32  nr_mask2_filter_select:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  nr_mask1_w1_mapstep:3;
        RBus_UInt32  nr_mask1_w1_maplimit:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  nr_mask1_w2_mapstep:3;
        RBus_UInt32  nr_mask1_w2_maplimit:4;
        RBus_UInt32  nr_mask1_filter_select:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  nr_mask_shift_mode:2;
    };
}nr_dch1_mask_shift_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  nr_mask3_w1_mapstep:3;
        RBus_UInt32  nr_mask3_w1_maplimit:4;
        RBus_UInt32  res2:5;
        RBus_UInt32  nr_mask3_w2_mapstep:3;
        RBus_UInt32  nr_mask3_w2_maplimit:4;
        RBus_UInt32  nr_mask3_filter_select:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  nr_mask2_w1_mapstep:3;
        RBus_UInt32  nr_mask2_w1_maplimit:4;
    };
}nr_dch1_mask_shift_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18025060_31_2:30;
        RBus_UInt32  res1:1;
        RBus_UInt32  curvemappingmode_en:1;
    };
}nr_curve_mapping_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step1:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  curvemapping_step2:9;
    };
}nr_curve_mapping_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step3:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  curvemapping_step4:9;
    };
}nr_curve_mapping_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step5:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  curvemapping_step6:9;
    };
}nr_curve_mapping_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step7:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  curvemapping_step8:9;
    };
}nr_curve_mapping_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  curvemapping_w1_0:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  curvemapping_w1_1:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  curvemapping_w1_2:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  curvemapping_w1_3:5;
    };
}nr_curve_mapping_w1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  curvemapping_w1_4:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  curvemapping_w1_5:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  curvemapping_w1_6:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  curvemapping_w1_7:5;
    };
}nr_curve_mapping_w1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  curvemapping_w1_8:5;
    };
}nr_curve_mapping_w1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  curvemapping_w2_0:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  curvemapping_w2_1:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  curvemapping_w2_2:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  curvemapping_w2_3:5;
    };
}nr_curve_mapping_w2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  curvemapping_w2_4:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  curvemapping_w2_5:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  curvemapping_w2_6:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  curvemapping_w2_7:5;
    };
}nr_curve_mapping_w2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  curvemapping_w2_8:5;
    };
}nr_curve_mapping_w2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  snr_db_apply:1;
        RBus_UInt32  snr_db_rd_sel:1;
        RBus_UInt32  snr_db_en:1;
    };
}nr_snr_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_adjustnoiselevel_bytype:1;
        RBus_UInt32  mnr_vardiff_refine_2dsearch:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  mnr_lpf_sel:2;
        RBus_UInt32  mosquito_edgethd_step:6;
        RBus_UInt32  mosquito_edgethd:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  mosquitonr_edge_strength_gain:3;
        RBus_UInt32  mosquitonr_weight:4;
        RBus_UInt32  mosquitonr_blending_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  mosquitonr_vertical_en:1;
        RBus_UInt32  mosquito_detect_en:1;
    };
}nr_mosquito_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  mnr_keepedge_shift:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  mnr_keepedgethd_step:6;
        RBus_UInt32  mnr_keepedgethd:8;
    };
}nr_mosquito_nr_keep_edge_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  mnr_vardiff_refine_gain:3;
        RBus_UInt32  mosquitonr_nlevel_negative_offset:8;
        RBus_UInt32  mosquitonr_nlevel_positive_offset:8;
        RBus_UInt32  mosquitonr_nlevel_negative_shift:4;
        RBus_UInt32  mosquitonr_nlevel_positive_shift:4;
    };
}nr_mosquito_nr_level_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edge_lpf_en:1;
        RBus_UInt32  noise_level_mode:1;
        RBus_UInt32  farvar_faredge_refine_en:1;
        RBus_UInt32  noise_level_trim:2;
        RBus_UInt32  far_var_gain:3;
        RBus_UInt32  far_var_offset:8;
        RBus_UInt32  res1:6;
        RBus_UInt32  hdiff_frac_half_range:3;
        RBus_UInt32  vdiff_frac_shift:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  hdiff_frac_shift:3;
    };
}nr_mosquito_nr_level_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  mnr_vdecay_step:3;
        RBus_UInt32  mnr_vdecay_start:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  mnr_hdecay_step:3;
        RBus_UInt32  mnr_hdecay_start:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  mnr_decay_en:1;
    };
}nr_mosquito_nr_decay_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  modified_lpf_edge_gain:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  modified_lpf_thd_step:6;
        RBus_UInt32  modified_lpf_thd_lowbnd:8;
        RBus_UInt32  res3:2;
        RBus_UInt32  modified_lpf_thd_upbnd:10;
    };
}nr_new_lpf_nearby_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  typedetect_max_step:9;
        RBus_UInt32  res2:2;
        RBus_UInt32  typedetect_max_thd:10;
    };
}nr_type_detect_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  typedetect_mid_step:9;
        RBus_UInt32  res2:2;
        RBus_UInt32  typedetect_mid_thd:10;
    };
}nr_type_detect_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  linekeep_verhor_ctrl:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  linekeep_edgeflag_thd:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  linekeep_flatflag_thd:5;
        RBus_UInt32  res4:1;
        RBus_UInt32  linekeep_linestrength_shift:3;
        RBus_UInt32  res5:3;
        RBus_UInt32  linekeep_mode:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  linekeep_shift:3;
    };
}nr_line_keep_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linekeep_horline_judgeratio:4;
        RBus_UInt32  linekeep_verline_judgeratio:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  linekeep_yuvdiff_step:9;
        RBus_UInt32  res2:2;
        RBus_UInt32  linekeep_yuvdiff_thd:10;
    };
}nr_line_keep_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_uvedge_en:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  mnr_uvedge_gain0:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  mnr_uvedge_gain1:5;
        RBus_UInt32  res3:1;
        RBus_UInt32  mnr_uvedge_step0:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  mnr_uvedge_step1:3;
    };
}nr_uv_modified_mosquito_edge_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  mnr_uvedge_lowbd0:8;
        RBus_UInt32  mnr_uvedge_lowbd1:8;
    };
}nr_uv_modified_mosquito_edge_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  spnr_image_height:13;
    };
}nr_spnr_act_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  mnr_level_shift_sel:3;
        RBus_UInt32  res2:10;
        RBus_UInt32  mnr_level_hist_mode:1;
        RBus_UInt32  mnr_level_hist_en:1;
    };
}nr_mnr_level_histogram_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_his1_sta_sign:1;
        RBus_UInt32  mnr_level_his1_sta_abs:7;
        RBus_UInt32  mnr_level_his1_end_sign:1;
        RBus_UInt32  mnr_level_his1_end_abs:7;
        RBus_UInt32  mnr_level_his0_sta_sign:1;
        RBus_UInt32  mnr_level_his0_sta_abs:7;
        RBus_UInt32  mnr_level_his0_end_sign:1;
        RBus_UInt32  mnr_level_his0_end_abs:7;
    };
}nr_mnr_level_histogram_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_his3_sta_sign:1;
        RBus_UInt32  mnr_level_his3_sta_abs:7;
        RBus_UInt32  mnr_level_his3_end_sign:1;
        RBus_UInt32  mnr_level_his3_end_abs:7;
        RBus_UInt32  mnr_level_his2_sta_sign:1;
        RBus_UInt32  mnr_level_his2_sta_abs:7;
        RBus_UInt32  mnr_level_his2_end_sign:1;
        RBus_UInt32  mnr_level_his2_end_abs:7;
    };
}nr_mnr_level_histogram_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_his5_sta_sign:1;
        RBus_UInt32  mnr_level_his5_sta_abs:7;
        RBus_UInt32  mnr_level_his5_end_sign:1;
        RBus_UInt32  mnr_level_his5_end_abs:7;
        RBus_UInt32  mnr_level_his4_sta_sign:1;
        RBus_UInt32  mnr_level_his4_sta_abs:7;
        RBus_UInt32  mnr_level_his4_end_sign:1;
        RBus_UInt32  mnr_level_his4_end_abs:7;
    };
}nr_mnr_level_histogram_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_his7_sta_sign:1;
        RBus_UInt32  mnr_level_his7_sta_abs:7;
        RBus_UInt32  mnr_level_his7_end_sign:1;
        RBus_UInt32  mnr_level_his7_end_abs:7;
        RBus_UInt32  mnr_level_his6_sta_sign:1;
        RBus_UInt32  mnr_level_his6_sta_abs:7;
        RBus_UInt32  mnr_level_his6_end_sign:1;
        RBus_UInt32  mnr_level_his6_end_abs:7;
    };
}nr_mnr_level_histogram_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_hist1:16;
        RBus_UInt32  mnr_level_hist0:16;
    };
}nr_mnr_level_histogram_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_hist3:16;
        RBus_UInt32  mnr_level_hist2:16;
    };
}nr_mnr_level_histogram_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_hist5:16;
        RBus_UInt32  mnr_level_hist4:16;
    };
}nr_mnr_level_histogram_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_hist7:16;
        RBus_UInt32  mnr_level_hist6:16;
    };
}nr_mnr_level_histogram_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  maxmin_hist_shift_sel:3;
        RBus_UInt32  res2:10;
        RBus_UInt32  maxmin_hist_mode:1;
        RBus_UInt32  maxmin_hist_en:1;
    };
}nr_maxmin_histogram_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxmin_hist1_sta:8;
        RBus_UInt32  maxmin_hist1_end:8;
        RBus_UInt32  maxmin_hist0_sta:8;
        RBus_UInt32  maxmin_hist0_end:8;
    };
}nr_maxmin_histogram_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxmin_hist3_sta:8;
        RBus_UInt32  maxmin_hist3_end:8;
        RBus_UInt32  maxmin_hist2_sta:8;
        RBus_UInt32  maxmin_hist2_end:8;
    };
}nr_maxmin_histogram_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxmin_hist1:16;
        RBus_UInt32  maxmin_hist0:16;
    };
}nr_maxmin_histogram_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxmin_hist3:16;
        RBus_UInt32  maxmin_hist2:16;
    };
}nr_maxmin_histogram_data_1_RBUS;

#else //apply LITTLE_ENDIAN

//======NR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_debugmode_en:1;
        RBus_UInt32  cp_debugmode:4;
        RBus_UInt32  dummy18025000_6:2;
        RBus_UInt32  res1:25;
    };
}nr_dch1_debugmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_impulseenable:1;
        RBus_UInt32  cp_spatialenablec:1;
        RBus_UInt32  cp_spatialenabley:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sresultweight_adjust_shift:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_zoranweight4c:2;
        RBus_UInt32  cp_zoranweight3c:2;
        RBus_UInt32  cp_zoranweight2c:2;
        RBus_UInt32  cp_zoranfiltersizec:2;
        RBus_UInt32  cp_zoranweight4y:2;
        RBus_UInt32  cp_zoranweight3y:2;
        RBus_UInt32  cp_zoranweight2y:2;
        RBus_UInt32  cp_zoranfiltersizey:2;
        RBus_UInt32  cp_sresultweight:4;
        RBus_UInt32  vc_snr_lpf_sel:2;
        RBus_UInt32  res3:2;
    };
}nr_dch1_cp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_impulsethlc:8;
        RBus_UInt32  cp_impulsethly:8;
        RBus_UInt32  cp_ipixeldiffthlc:4;
        RBus_UInt32  cp_ipixeldiffthly:4;
        RBus_UInt32  cp_iresultweight:3;
        RBus_UInt32  res1:3;
        RBus_UInt32  cp_impulsewindow:1;
        RBus_UInt32  res2:1;
    };
}nr_dch1_impulse_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_impulsesmooththlc:8;
        RBus_UInt32  cp_impulsesmooththly:8;
        RBus_UInt32  cp_impulsethlcx2:8;
        RBus_UInt32  cp_impulsethlyx2:8;
    };
}nr_dch1_impulse_smooththl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_spatialthlc:8;
        RBus_UInt32  cp_spatialthly:8;
        RBus_UInt32  cp_spatialthlcx2:8;
        RBus_UInt32  cp_spatialthlyx2:8;
    };
}nr_dch1_spatial_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_spatialthlcx4:8;
        RBus_UInt32  cp_spatialthlyx4:8;
        RBus_UInt32  res1:16;
    };
}nr_dch1_spatial_thl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_ringgain:1;
        RBus_UInt32  cp_ringrange:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_fixedweight2y:1;
        RBus_UInt32  cp_fixedweight1y:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_weight2y:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  cp_weight1y:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  cp_ringweighty:4;
        RBus_UInt32  cp_lpresultweightc:4;
    };
}nr_dch1_spatial_weight_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mean_local_var:16;
        RBus_UInt32  cp_max_local_var:16;
    };
}nr_dch1_local_var1_RBUS;

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
}nr_dch1_local_var2_RBUS;

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
}nr_dch1_mpegnr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_dsnoiselevel0:8;
        RBus_UInt32  cp_dsnoiselevel1:8;
        RBus_UInt32  cp_dsnoiselevel2:8;
        RBus_UInt32  cp_dsnoiselevel3:8;
    };
}nr_dch1_noiselevel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_dsnoiselevel4:8;
        RBus_UInt32  cp_dsnoiselevel5:8;
        RBus_UInt32  cp_dsnoiselevel6:8;
        RBus_UInt32  cp_dsnoiselevel7:8;
    };
}nr_dch1_noiselevel2_RBUS;

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
}nr_dch1_mask1_ctrl1_RBUS;

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
        RBus_UInt32  cp_mask1_maplimit:4;
        RBus_UInt32  res4:12;
    };
}nr_dch1_mask1_ctrl2_RBUS;

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
}nr_dch1_mask2_ctrl1_RBUS;

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
        RBus_UInt32  cp_mask2_maplimit:4;
        RBus_UInt32  res4:12;
    };
}nr_dch1_mask2_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mask3_crgain:2;
        RBus_UInt32  cp_mask3_cbgain:2;
        RBus_UInt32  cp_mask3_ygain:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_mask3_crref:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_mask3_cbref:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cp_mask3_yref:6;
    };
}nr_dch1_mask3_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mask3_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cp_mask3_dir:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cp_mask3_mapstep:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cp_mask3_mapthre:4;
        RBus_UInt32  cp_mask3_maplimit:4;
        RBus_UInt32  res4:12;
    };
}nr_dch1_mask3_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nr_mask_shift_mode:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  nr_mask1_filter_select:1;
        RBus_UInt32  nr_mask1_w2_maplimit:4;
        RBus_UInt32  nr_mask1_w2_mapstep:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  nr_mask1_w1_maplimit:4;
        RBus_UInt32  nr_mask1_w1_mapstep:3;
        RBus_UInt32  res3:4;
        RBus_UInt32  nr_mask2_filter_select:1;
        RBus_UInt32  nr_mask2_w2_maplimit:4;
        RBus_UInt32  nr_mask2_w2_mapstep:3;
        RBus_UInt32  res4:1;
    };
}nr_dch1_mask_shift_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nr_mask2_w1_maplimit:4;
        RBus_UInt32  nr_mask2_w1_mapstep:3;
        RBus_UInt32  res1:4;
        RBus_UInt32  nr_mask3_filter_select:1;
        RBus_UInt32  nr_mask3_w2_maplimit:4;
        RBus_UInt32  nr_mask3_w2_mapstep:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  nr_mask3_w1_maplimit:4;
        RBus_UInt32  nr_mask3_w1_mapstep:3;
        RBus_UInt32  res3:1;
    };
}nr_dch1_mask_shift_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemappingmode_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dummy18025060_31:30;
    };
}nr_curve_mapping_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_step2:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step1:9;
        RBus_UInt32  res2:7;
    };
}nr_curve_mapping_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_step4:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step3:9;
        RBus_UInt32  res2:7;
    };
}nr_curve_mapping_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_step6:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step5:9;
        RBus_UInt32  res2:7;
    };
}nr_curve_mapping_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_step8:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  curvemapping_step7:9;
        RBus_UInt32  res2:7;
    };
}nr_curve_mapping_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_w1_3:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  curvemapping_w1_2:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  curvemapping_w1_1:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  curvemapping_w1_0:5;
        RBus_UInt32  res4:3;
    };
}nr_curve_mapping_w1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_w1_7:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  curvemapping_w1_6:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  curvemapping_w1_5:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  curvemapping_w1_4:5;
        RBus_UInt32  res4:3;
    };
}nr_curve_mapping_w1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_w1_8:5;
        RBus_UInt32  res1:27;
    };
}nr_curve_mapping_w1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_w2_3:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  curvemapping_w2_2:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  curvemapping_w2_1:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  curvemapping_w2_0:5;
        RBus_UInt32  res4:3;
    };
}nr_curve_mapping_w2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_w2_7:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  curvemapping_w2_6:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  curvemapping_w2_5:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  curvemapping_w2_4:5;
        RBus_UInt32  res4:3;
    };
}nr_curve_mapping_w2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curvemapping_w2_8:5;
        RBus_UInt32  res1:27;
    };
}nr_curve_mapping_w2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  snr_db_en:1;
        RBus_UInt32  snr_db_rd_sel:1;
        RBus_UInt32  snr_db_apply:1;
        RBus_UInt32  res1:29;
    };
}nr_snr_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mosquito_detect_en:1;
        RBus_UInt32  mosquitonr_vertical_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mosquitonr_blending_mode:1;
        RBus_UInt32  mosquitonr_weight:4;
        RBus_UInt32  mosquitonr_edge_strength_gain:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  mosquito_edgethd:8;
        RBus_UInt32  mosquito_edgethd_step:6;
        RBus_UInt32  mnr_lpf_sel:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  mnr_vardiff_refine_2dsearch:1;
        RBus_UInt32  mnr_adjustnoiselevel_bytype:1;
    };
}nr_mosquito_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_keepedgethd:8;
        RBus_UInt32  mnr_keepedgethd_step:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  mnr_keepedge_shift:3;
        RBus_UInt32  res2:13;
    };
}nr_mosquito_nr_keep_edge_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mosquitonr_nlevel_positive_shift:4;
        RBus_UInt32  mosquitonr_nlevel_negative_shift:4;
        RBus_UInt32  mosquitonr_nlevel_positive_offset:8;
        RBus_UInt32  mosquitonr_nlevel_negative_offset:8;
        RBus_UInt32  mnr_vardiff_refine_gain:3;
        RBus_UInt32  res1:5;
    };
}nr_mosquito_nr_level_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdiff_frac_shift:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  vdiff_frac_shift:3;
        RBus_UInt32  hdiff_frac_half_range:3;
        RBus_UInt32  res2:6;
        RBus_UInt32  far_var_offset:8;
        RBus_UInt32  far_var_gain:3;
        RBus_UInt32  noise_level_trim:2;
        RBus_UInt32  farvar_faredge_refine_en:1;
        RBus_UInt32  noise_level_mode:1;
        RBus_UInt32  edge_lpf_en:1;
    };
}nr_mosquito_nr_level_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_decay_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  mnr_hdecay_start:4;
        RBus_UInt32  mnr_hdecay_step:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  mnr_vdecay_start:4;
        RBus_UInt32  mnr_vdecay_step:3;
        RBus_UInt32  res3:13;
    };
}nr_mosquito_nr_decay_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  modified_lpf_thd_upbnd:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  modified_lpf_thd_lowbnd:8;
        RBus_UInt32  modified_lpf_thd_step:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  modified_lpf_edge_gain:3;
        RBus_UInt32  res3:1;
    };
}nr_new_lpf_nearby_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  typedetect_max_thd:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  typedetect_max_step:9;
        RBus_UInt32  res2:11;
    };
}nr_type_detect_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  typedetect_mid_thd:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  typedetect_mid_step:9;
        RBus_UInt32  res2:11;
    };
}nr_type_detect_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linekeep_shift:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  linekeep_mode:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  linekeep_linestrength_shift:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  linekeep_flatflag_thd:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  linekeep_edgeflag_thd:5;
        RBus_UInt32  res5:3;
        RBus_UInt32  linekeep_verhor_ctrl:2;
        RBus_UInt32  res6:2;
    };
}nr_line_keep_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linekeep_yuvdiff_thd:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  linekeep_yuvdiff_step:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  linekeep_verline_judgeratio:4;
        RBus_UInt32  linekeep_horline_judgeratio:4;
    };
}nr_line_keep_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_uvedge_step1:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  mnr_uvedge_step0:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  mnr_uvedge_gain1:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  mnr_uvedge_gain0:5;
        RBus_UInt32  res4:10;
        RBus_UInt32  mnr_uvedge_en:1;
    };
}nr_uv_modified_mosquito_edge_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_uvedge_lowbd1:8;
        RBus_UInt32  mnr_uvedge_lowbd0:8;
        RBus_UInt32  res1:16;
    };
}nr_uv_modified_mosquito_edge_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_image_height:13;
        RBus_UInt32  res1:19;
    };
}nr_spnr_act_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_hist_en:1;
        RBus_UInt32  mnr_level_hist_mode:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  mnr_level_shift_sel:3;
        RBus_UInt32  res2:17;
    };
}nr_mnr_level_histogram_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_his0_end_abs:7;
        RBus_UInt32  mnr_level_his0_end_sign:1;
        RBus_UInt32  mnr_level_his0_sta_abs:7;
        RBus_UInt32  mnr_level_his0_sta_sign:1;
        RBus_UInt32  mnr_level_his1_end_abs:7;
        RBus_UInt32  mnr_level_his1_end_sign:1;
        RBus_UInt32  mnr_level_his1_sta_abs:7;
        RBus_UInt32  mnr_level_his1_sta_sign:1;
    };
}nr_mnr_level_histogram_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_his2_end_abs:7;
        RBus_UInt32  mnr_level_his2_end_sign:1;
        RBus_UInt32  mnr_level_his2_sta_abs:7;
        RBus_UInt32  mnr_level_his2_sta_sign:1;
        RBus_UInt32  mnr_level_his3_end_abs:7;
        RBus_UInt32  mnr_level_his3_end_sign:1;
        RBus_UInt32  mnr_level_his3_sta_abs:7;
        RBus_UInt32  mnr_level_his3_sta_sign:1;
    };
}nr_mnr_level_histogram_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_his4_end_abs:7;
        RBus_UInt32  mnr_level_his4_end_sign:1;
        RBus_UInt32  mnr_level_his4_sta_abs:7;
        RBus_UInt32  mnr_level_his4_sta_sign:1;
        RBus_UInt32  mnr_level_his5_end_abs:7;
        RBus_UInt32  mnr_level_his5_end_sign:1;
        RBus_UInt32  mnr_level_his5_sta_abs:7;
        RBus_UInt32  mnr_level_his5_sta_sign:1;
    };
}nr_mnr_level_histogram_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_his6_end_abs:7;
        RBus_UInt32  mnr_level_his6_end_sign:1;
        RBus_UInt32  mnr_level_his6_sta_abs:7;
        RBus_UInt32  mnr_level_his6_sta_sign:1;
        RBus_UInt32  mnr_level_his7_end_abs:7;
        RBus_UInt32  mnr_level_his7_end_sign:1;
        RBus_UInt32  mnr_level_his7_sta_abs:7;
        RBus_UInt32  mnr_level_his7_sta_sign:1;
    };
}nr_mnr_level_histogram_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_hist0:16;
        RBus_UInt32  mnr_level_hist1:16;
    };
}nr_mnr_level_histogram_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_hist2:16;
        RBus_UInt32  mnr_level_hist3:16;
    };
}nr_mnr_level_histogram_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_hist4:16;
        RBus_UInt32  mnr_level_hist5:16;
    };
}nr_mnr_level_histogram_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mnr_level_hist6:16;
        RBus_UInt32  mnr_level_hist7:16;
    };
}nr_mnr_level_histogram_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxmin_hist_en:1;
        RBus_UInt32  maxmin_hist_mode:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  maxmin_hist_shift_sel:3;
        RBus_UInt32  res2:17;
    };
}nr_maxmin_histogram_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxmin_hist0_end:8;
        RBus_UInt32  maxmin_hist0_sta:8;
        RBus_UInt32  maxmin_hist1_end:8;
        RBus_UInt32  maxmin_hist1_sta:8;
    };
}nr_maxmin_histogram_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxmin_hist2_end:8;
        RBus_UInt32  maxmin_hist2_sta:8;
        RBus_UInt32  maxmin_hist3_end:8;
        RBus_UInt32  maxmin_hist3_sta:8;
    };
}nr_maxmin_histogram_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxmin_hist0:16;
        RBus_UInt32  maxmin_hist1:16;
    };
}nr_maxmin_histogram_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxmin_hist2:16;
        RBus_UInt32  maxmin_hist3:16;
    };
}nr_maxmin_histogram_data_1_RBUS;




#endif 


#endif 
