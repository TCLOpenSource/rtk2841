/**
* @file rbusTV_SB1_ANAReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/30
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_TV_SB1_ANA_REG_H_
#define _RBUS_TV_SB1_ANA_REG_H_

#include "rbus_types.h"



//  TV_SB1_ANA Register Address



#define  TV_SB1_ANA_VDAC_VDBSO_VADDR                        	(0xb8033000)
#define  TV_SB1_ANA_VDAC_VADDR                              	(0xb8033004)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_VADDR                  	(0xb8033008)
#define  TV_SB1_ANA_VDAC_SRC_SEL_VADDR                      	(0xb8033024)
#define  TV_SB1_ANA_IFADC_CTRL1_VADDR                       	(0xb8033100)
#define  TV_SB1_ANA_IFADC_CTRL2_VADDR                       	(0xb8033104)
#define  TV_SB1_ANA_IFADC_CTRL3_VADDR                       	(0xb8033108)
#define  TV_SB1_ANA_IFADC_CTRL4_VADDR                       	(0xb803310c)
#define  TV_SB1_ANA_IFADC_CTRL5_VADDR                       	(0xb8033110)
#define  TV_SB1_ANA_IFADC_AGC_PGA_CTRL_VADDR                	(0xb8033114)
#define  TV_SB1_ANA_IQADC_CTRL0_VADDR                       	(0xb8033118)
#define  TV_SB1_ANA_IQADC_CTRL1_VADDR                       	(0xb803311c)
#define  TV_SB1_ANA_IQADC_CTRL2_VADDR                       	(0xb8033120)
#define  TV_SB1_ANA_IQADC_CTRL3_VADDR                       	(0xb8033124)
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_VADDR                   	(0xb8033128)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======TV_SB1_ANA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_vid_powldv:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_vid_powmbias:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_vid_powvdac:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_vid_mbias_ibsel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_vid_mbias_ibxsel:2;
        RBus_UInt32  res6:3;
        RBus_UInt32  reg_vid_ldv_bufgain:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  reg_vid_ldv_dcc:1;
        RBus_UInt32  res8:2;
        RBus_UInt32  reg_vid_ldv_vcmsel:2;
    };
}audio_vdac_vdbso_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_vid_ldv_stby:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_vid_ldv_biassel:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_vid_ldv_endrv:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_vid_ldv_iqsel:2;
        RBus_UInt32  res5:1;
        RBus_UInt32  reg_vid_ldv_odsel:3;
        RBus_UInt32  res6:2;
        RBus_UInt32  reg_vid_vdac_biassel:2;
        RBus_UInt32  res7:3;
        RBus_UInt32  reg_vid_vdac_dcc:1;
        RBus_UInt32  res8:3;
        RBus_UInt32  reg_vid_vdac_stby:1;
    };
}audio_vdac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_vid_vdac_vcmsel:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_vid_vdac_endrv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_vid_vdac_iqsel:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  reg_vid_vdac_odsel:3;
        RBus_UInt32  res5:3;
        RBus_UInt32  reg_vid_vdac_ckmode:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  reg_vid_vdac_dacisel:3;
        RBus_UInt32  res7:2;
        RBus_UInt32  reg_vid_vdac_rsel:2;
        RBus_UInt32  res8:2;
        RBus_UInt32  reg_vid_vdac_csel:2;
    };
}audio_vadc_idaco_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  reg_vdac_clk_polar:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_vdac_src_sel:3;
    };
}audio_vdac_src_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_adc2x_svbwr:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_adc2x_adcpow:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_adc2x_meta_pow:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_pow_mbias:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_rssi_cl:2;
        RBus_UInt32  reg_mbias_rssi:2;
        RBus_UInt32  reg_adc2x_bg_sel:2;
        RBus_UInt32  reg_ifd_reserved:8;
    };
}audio_ifadc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_rssi_bias:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_adc2x_difpow:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_mbias_isel:2;
        RBus_UInt32  reg_adc2x_fixgain:4;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_rssi_lsadc_pow:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_adc2x_ifbw:2;
        RBus_UInt32  res6:1;
        RBus_UInt32  reg_ifcmp_isel:3;
        RBus_UInt32  res7:2;
        RBus_UInt32  reg_adc2x_svbwc:2;
    };
}audio_ifadc_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  reg_adc2x_insel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_lsadc_cksel:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_lsadc_div:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_mbias_lsadc:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_adc2x_ckout_div:2;
        RBus_UInt32  res6:2;
        RBus_UInt32  reg_adc2x_vref_sel:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  reg_ifd_ckin_sel:2;
    };
}audio_ifadc_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mbias_ifpga:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_adc2x_servopow2:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_adc2x_ldo_sel:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_adc2x_ckout_edge:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_adc2x_delay:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_adc2x_servo:2;
    };
}audio_ifadc_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  reg_adc2x_ifpga_stg12_pow:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_adc2x_ifpga_stg3_pow:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_adc2x_sif_in_sel:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_adc2x_ifpga_stg3_in_sel:1;
    };
}audio_ifadc_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  reg_adc2x_vcm_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_agc_pga_src_sel:1;
    };
}audio_ifadc_agc_pga_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_iq_cal_vref:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_iq_cal_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_iq_cal_div:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_iq_bw:2;
        RBus_UInt32  res5:3;
        RBus_UInt32  reg_q_ckout_edge:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  reg_i_ckout_edge:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  reg_ckout_sel_q:1;
        RBus_UInt32  res8:3;
        RBus_UInt32  reg_ckout_sel_i:1;
    };
}audio_iqadc_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_iq_meta_pow:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_iq_ldo_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_iq_fix_gain:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  reg_iq_duty_sel:3;
        RBus_UInt32  res5:3;
        RBus_UInt32  reg_iq_delay_en:1;
        RBus_UInt32  reg_iq_d:4;
        RBus_UInt32  res6:2;
        RBus_UInt32  reg_iq_ckout_div:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  reg_iq_ckin_sel:2;
    };
}audio_iqadc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  reg_iqcmp_isel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_iqcal_isel:3;
        RBus_UInt32  res3:6;
        RBus_UInt32  reg_iq_vref_sel:2;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_iq_single_end_en:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  reg_iq_pre_set:1;
    };
}audio_iqadc_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  reg_pow_q_pga:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_pow_i_pga:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_pow_q_adc:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_pow_i_adc:1;
    };
}audio_iqadc_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_if_agc_pga3:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_if_agc_pga2:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_if_agc_pga1:2;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_if_fix_en:1;
    };
}audio_ifadc_gain_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======TV_SB1_ANA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_vid_ldv_vcmsel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_vid_ldv_dcc:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_vid_ldv_bufgain:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_vid_mbias_ibxsel:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_vid_mbias_ibsel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_vid_powvdac:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  reg_vid_powmbias:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  reg_vid_powldv:1;
        RBus_UInt32  res8:3;
    };
}audio_vdac_vdbso_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_vid_vdac_stby:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_vid_vdac_dcc:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_vid_vdac_biassel:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_vid_ldv_odsel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  reg_vid_ldv_iqsel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_vid_ldv_endrv:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  reg_vid_ldv_biassel:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  reg_vid_ldv_stby:1;
        RBus_UInt32  res8:3;
    };
}audio_vdac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_vid_vdac_csel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_vid_vdac_rsel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_vid_vdac_dacisel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_vid_vdac_ckmode:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_vid_vdac_odsel:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  reg_vid_vdac_iqsel:2;
        RBus_UInt32  res6:2;
        RBus_UInt32  reg_vid_vdac_endrv:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  reg_vid_vdac_vcmsel:2;
        RBus_UInt32  res8:2;
    };
}audio_vadc_idaco_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_vdac_src_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_vdac_clk_polar:1;
        RBus_UInt32  res2:27;
    };
}audio_vdac_src_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_ifd_reserved:8;
        RBus_UInt32  reg_adc2x_bg_sel:2;
        RBus_UInt32  reg_mbias_rssi:2;
        RBus_UInt32  reg_rssi_cl:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_pow_mbias:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_adc2x_meta_pow:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_adc2x_adcpow:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_adc2x_svbwr:2;
        RBus_UInt32  res5:2;
    };
}audio_ifadc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_adc2x_svbwc:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_ifcmp_isel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_adc2x_ifbw:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_rssi_lsadc_pow:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_adc2x_fixgain:4;
        RBus_UInt32  reg_mbias_isel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_adc2x_difpow:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  reg_rssi_bias:2;
        RBus_UInt32  res7:2;
    };
}audio_ifadc_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_ifd_ckin_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_adc2x_vref_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_adc2x_ckout_div:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_mbias_lsadc:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_lsadc_div:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_lsadc_cksel:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  reg_adc2x_insel:1;
        RBus_UInt32  res7:7;
    };
}audio_ifadc_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_adc2x_servo:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_adc2x_delay:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_adc2x_ckout_edge:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_adc2x_ldo_sel:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_adc2x_servopow2:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  reg_mbias_ifpga:12;
    };
}audio_ifadc_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_adc2x_ifpga_stg3_in_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_adc2x_sif_in_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_adc2x_ifpga_stg3_pow:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_adc2x_ifpga_stg12_pow:1;
        RBus_UInt32  res4:19;
    };
}audio_ifadc_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_agc_pga_src_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_adc2x_vcm_sel:1;
        RBus_UInt32  res2:27;
    };
}audio_ifadc_agc_pga_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_ckout_sel_i:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_ckout_sel_q:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_i_ckout_edge:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_q_ckout_edge:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_iq_bw:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_iq_cal_div:2;
        RBus_UInt32  res6:2;
        RBus_UInt32  reg_iq_cal_en:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  reg_iq_cal_vref:3;
        RBus_UInt32  res8:1;
    };
}audio_iqadc_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_iq_ckin_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_iq_ckout_div:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_iq_d:4;
        RBus_UInt32  reg_iq_delay_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_iq_duty_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  reg_iq_fix_gain:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  reg_iq_ldo_sel:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  reg_iq_meta_pow:1;
        RBus_UInt32  res7:3;
    };
}audio_iqadc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_iq_pre_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_iq_single_end_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_iq_vref_sel:2;
        RBus_UInt32  res3:6;
        RBus_UInt32  reg_iqcal_isel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  reg_iqcmp_isel:3;
        RBus_UInt32  res5:9;
    };
}audio_iqadc_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_pow_i_adc:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_pow_q_adc:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_pow_i_pga:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_pow_q_pga:1;
        RBus_UInt32  res4:19;
    };
}audio_iqadc_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_if_fix_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_if_agc_pga1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_if_agc_pga2:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_if_agc_pga3:4;
        RBus_UInt32  res4:16;
    };
}audio_ifadc_gain_ctrl_RBUS;




#endif 


#endif 
