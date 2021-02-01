/**
* @file rbusIedge_smoothReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IEDGE_SMOOTH_REG_H_
#define _RBUS_IEDGE_SMOOTH_REG_H_

#include "rbusTypes.h"



//  IEDGE_SMOOTH Register Address



#define  IEDGE_SMOOTH_EDGESMOOTH_EX_CTRL_VADDR              	(0xb8025100)
#define  IEDGE_SMOOTH_EDGESMOOTH_EX_CTRL2_VADDR             	(0xb8025104)
#define  IEDGE_SMOOTH_EDGESMOOTH_EX_CTRL3_VADDR             	(0xb8025108)
#define  IEDGE_SMOOTH_MIXER_CTRL_VADDR                      	(0xb802510c)
#define  IEDGE_SMOOTH_EDGESMOOTH_EXTENSION_VADDR            	(0xb8025110)
#define  IEDGE_SMOOTH_EDGESMOOTH_EXT_ANGLE_VADDR            	(0xb802511c)
#define  IEDGE_SMOOTH_DEMO_WINDOW_CTRL0_VADDR               	(0xb8025120)
#define  IEDGE_SMOOTH_DEMO_WINDOW_CTRL1_VADDR               	(0xb8025124)
#define  IEDGE_SMOOTH_PRELPF_CTRL_VADDR                     	(0xb8025128)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_VADDR                     	(0xb802512c)
#define  IEDGE_SMOOTH_EDGESMOOTH_MESS_DIRECTION1_VADDR      	(0xb8025130)
#define  IEDGE_SMOOTH_EDGESMOOTH_MESS_DIRECTION2_VADDR      	(0xb8025134)
#define  IEDGE_SMOOTH_EDGESMOOTH_BLEND_WEIGHT_LPF_VADDR     	(0xb8025138)
#define  IEDGE_SMOOTH_EDGESMOOTH_UNSTABLE_AREA_VADDR        	(0xb802513c)
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_VADDR                 	(0xb8025144)
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_VADDR                	(0xb8025148)
#define  IEDGE_SMOOTH_SPNR_DRF_FAIL_VADDR                   	(0xb802514c)
#define  IEDGE_SMOOTH_SPNR_DVS0_VADDR                       	(0xb8025150)
#define  IEDGE_SMOOTH_VFILTER_0_VADDR                       	(0xb8025154)
#define  IEDGE_SMOOTH_VFILTER_1_VADDR                       	(0xb8025158)
#define  IEDGE_SMOOTH_VFILTER_2_VADDR                       	(0xb802515c)
#define  IEDGE_SMOOTH_VFILTER_3_VADDR                       	(0xb8025160)
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_VADDR                    	(0xb8025170)
#define  IEDGE_SMOOTH_FORMAT_CONVERT_VADDR                  	(0xb8025180)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IEDGE_SMOOTH register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  dummy18025100_25_18:8;
        RBus_UInt32  tst_en:1;
        RBus_UInt32  lbuf_disable:1;
        RBus_UInt32  debug_mode:4;
        RBus_UInt32  edgemode:1;
        RBus_UInt32  lbuf_linemode:2;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  crct_5linemode:1;
        RBus_UInt32  chaos_5linemode:1;
        RBus_UInt32  lpf_5tapmode:1;
        RBus_UInt32  edge_en:1;
        RBus_UInt32  chaos_en:1;
        RBus_UInt32  crct_en:1;
        RBus_UInt32  t2df_en:1;
        RBus_UInt32  edgesmoothex_en:1;
    };
}iedge_smooth_edgesmooth_ex_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chaos_diffth:8;
        RBus_UInt32  res1:6;
        RBus_UInt32  chaos_mode:2;
        RBus_UInt32  t2df_stepbit:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  t2df_upbnd:10;
    };
}iedge_smooth_edgesmooth_ex_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  chaos_lwbnd:5;
        RBus_UInt32  edge_stepbit:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  edge_upbnd:10;
    };
}iedge_smooth_edgesmooth_ex_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  iedge_nr_sel:1;
        RBus_UInt32  iedge_mixer_weight:4;
        RBus_UInt32  res2:4;
    };
}iedge_smooth_mixer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_range_en:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  ext_uvrange:2;
        RBus_UInt32  ext_range:2;
        RBus_UInt32  ext_uvdiff_stepbit:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  ext_uvdiff_upbnd:10;
    };
}iedge_smooth_edgesmooth_extension_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_angle_crc_en:1;
        RBus_UInt32  ext_angle_en:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  ext_angle_rl_thd:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ext_angle_maxdiff_thd:10;
    };
}iedge_smooth_edgesmooth_ext_angle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_demo_en:1;
        RBus_UInt32  reg_demo_inv:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  reg_h_end:12;
        RBus_UInt32  reg_h_start:12;
    };
}iedge_smooth_demo_window_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_v_end:12;
        RBus_UInt32  reg_v_start:12;
    };
}iedge_smooth_demo_window_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prelpf_iedge2_sel:1;
        RBus_UInt32  dummy18025128_30_28:3;
        RBus_UInt32  res1:8;
        RBus_UInt32  prelpf_iedge1_sel:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  prelpf_snr_sel:4;
    };
}iedge_smooth_prelpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dlti2d_hlpf_type:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  dlti2d_vlpf_type:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  dlti2d_chaos_gain:3;
        RBus_UInt32  res4:3;
        RBus_UInt32  dlti2d_maxmin_en:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  dlti2d_gain:6;
    };
}iedge_smooth_dlti2d_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mess_direction_en:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  mess_4direction_thd:4;
        RBus_UInt32  mess_4direction_step:4;
        RBus_UInt32  mess_4direction_w0:4;
        RBus_UInt32  mess_4direction_w1:4;
        RBus_UInt32  mess_4direction_w2:4;
    };
}iedge_smooth_edgesmooth_mess_direction1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  mess_8direction_thd:4;
        RBus_UInt32  mess_8direction_step:4;
        RBus_UInt32  mess_8direction_w0:4;
        RBus_UInt32  mess_8direction_w1:4;
        RBus_UInt32  mess_8direction_w2:4;
    };
}iedge_smooth_edgesmooth_mess_direction2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blend_weight_lpf_en:1;
        RBus_UInt32  res1:31;
    };
}iedge_smooth_edgesmooth_blend_weight_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  unstable_area_en:1;
        RBus_UInt32  res1:26;
        RBus_UInt32  unstable_area_thd:5;
    };
}iedge_smooth_edgesmooth_unstable_area_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  vsync_line_delay:6;
        RBus_UInt32  res2:8;
        RBus_UInt32  back_porch_meas:8;
        RBus_UInt32  front_porch_meas:8;
    };
}iedge_smooth_spnr_porch_meas_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr_spnr_repaired:1;
        RBus_UInt32  res1:29;
        RBus_UInt32  bisr_spnr_fail_1:1;
        RBus_UInt32  bisr_spnr_fail_0:1;
    };
}iedge_smooth_spnr_bisr_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  spnr_drf_fail_1:1;
        RBus_UInt32  spnr_drf_fail_0:1;
    };
}iedge_smooth_spnr_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  spnr_ls_en:1;
        RBus_UInt32  spnr_dvse0:1;
        RBus_UInt32  spnr_dvs0:4;
    };
}iedge_smooth_spnr_dvs0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  vfir_weight:6;
        RBus_UInt32  avlpf_mindiff_th_start:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  avlpf_mindiff_curve_rate_start:3;
        RBus_UInt32  avlpf_mindiff_th_finish:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  avlpf_mindiff_curve_rate_finish:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  avlpf_en:1;
        RBus_UInt32  avlpf_correct_en:1;
        RBus_UInt32  avlpf_bw_pattern_en:1;
    };
}iedge_smooth_vfilter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avlpf_maxmindiff_th:8;
        RBus_UInt32  res1:5;
        RBus_UInt32  avlpf_maxmindiff_curve_rate:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  avlpf_max_weight:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  avlpf_min_weight:6;
    };
}iedge_smooth_vfilter_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avlpf_bw_th:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  avlpf_bw_margin:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  avlpf_bw_curve_rate:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  avlpf_c_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  vfir_c_weight:6;
    };
}iedge_smooth_vfilter_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  vfir_debug:4;
    };
}iedge_smooth_vfilter_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  edsm_db_apply:1;
        RBus_UInt32  edsm_db_rd_sel:1;
        RBus_UInt32  edsm_db_en:1;
    };
}iedge_smooth_edsm_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_422_to_444_en:1;
        RBus_UInt32  main_422_to_444_type:1;
        RBus_UInt32  main_422_to_444_dup:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  sub_422_to_444_en:1;
        RBus_UInt32  sub_422_to_444_type:1;
        RBus_UInt32  sub_422_to_444_dup:1;
        RBus_UInt32  res2:13;
    };
}iedge_smooth_format_convert_RBUS;

#else //apply LITTLE_ENDIAN

//======IEDGE_SMOOTH register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edgesmoothex_en:1;
        RBus_UInt32  t2df_en:1;
        RBus_UInt32  crct_en:1;
        RBus_UInt32  chaos_en:1;
        RBus_UInt32  edge_en:1;
        RBus_UInt32  lpf_5tapmode:1;
        RBus_UInt32  chaos_5linemode:1;
        RBus_UInt32  crct_5linemode:1;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  lbuf_linemode:2;
        RBus_UInt32  edgemode:1;
        RBus_UInt32  debug_mode:4;
        RBus_UInt32  lbuf_disable:1;
        RBus_UInt32  tst_en:1;
        RBus_UInt32  dummy18025100_25:8;
        RBus_UInt32  res1:6;
    };
}iedge_smooth_edgesmooth_ex_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t2df_upbnd:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  t2df_stepbit:4;
        RBus_UInt32  chaos_mode:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  chaos_diffth:8;
    };
}iedge_smooth_edgesmooth_ex_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edge_upbnd:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  edge_stepbit:4;
        RBus_UInt32  chaos_lwbnd:5;
        RBus_UInt32  res2:11;
    };
}iedge_smooth_edgesmooth_ex_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  iedge_mixer_weight:4;
        RBus_UInt32  iedge_nr_sel:1;
        RBus_UInt32  res2:23;
    };
}iedge_smooth_mixer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_uvdiff_upbnd:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  ext_uvdiff_stepbit:4;
        RBus_UInt32  ext_range:2;
        RBus_UInt32  ext_uvrange:2;
        RBus_UInt32  res2:11;
        RBus_UInt32  ext_range_en:1;
    };
}iedge_smooth_edgesmooth_extension_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_angle_maxdiff_thd:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  ext_angle_rl_thd:6;
        RBus_UInt32  res2:12;
        RBus_UInt32  ext_angle_en:1;
        RBus_UInt32  ext_angle_crc_en:1;
    };
}iedge_smooth_edgesmooth_ext_angle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_h_start:12;
        RBus_UInt32  reg_h_end:12;
        RBus_UInt32  res1:6;
        RBus_UInt32  reg_demo_inv:1;
        RBus_UInt32  reg_demo_en:1;
    };
}iedge_smooth_demo_window_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_v_start:12;
        RBus_UInt32  reg_v_end:12;
        RBus_UInt32  res1:8;
    };
}iedge_smooth_demo_window_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prelpf_snr_sel:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  prelpf_iedge1_sel:4;
        RBus_UInt32  res2:8;
        RBus_UInt32  dummy18025128_30_28:3;
        RBus_UInt32  prelpf_iedge2_sel:1;
    };
}iedge_smooth_prelpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti2d_gain:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  dlti2d_maxmin_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dlti2d_chaos_gain:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  dlti2d_vlpf_type:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  dlti2d_hlpf_type:2;
        RBus_UInt32  res5:10;
    };
}iedge_smooth_dlti2d_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mess_4direction_w2:4;
        RBus_UInt32  mess_4direction_w1:4;
        RBus_UInt32  mess_4direction_w0:4;
        RBus_UInt32  mess_4direction_step:4;
        RBus_UInt32  mess_4direction_thd:4;
        RBus_UInt32  res1:11;
        RBus_UInt32  mess_direction_en:1;
    };
}iedge_smooth_edgesmooth_mess_direction1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mess_8direction_w2:4;
        RBus_UInt32  mess_8direction_w1:4;
        RBus_UInt32  mess_8direction_w0:4;
        RBus_UInt32  mess_8direction_step:4;
        RBus_UInt32  mess_8direction_thd:4;
        RBus_UInt32  res1:12;
    };
}iedge_smooth_edgesmooth_mess_direction2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  blend_weight_lpf_en:1;
    };
}iedge_smooth_edgesmooth_blend_weight_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  unstable_area_thd:5;
        RBus_UInt32  res1:26;
        RBus_UInt32  unstable_area_en:1;
    };
}iedge_smooth_edgesmooth_unstable_area_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  front_porch_meas:8;
        RBus_UInt32  back_porch_meas:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  vsync_line_delay:6;
        RBus_UInt32  res2:2;
    };
}iedge_smooth_spnr_porch_meas_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr_spnr_fail_0:1;
        RBus_UInt32  bisr_spnr_fail_1:1;
        RBus_UInt32  res1:29;
        RBus_UInt32  bisr_spnr_repaired:1;
    };
}iedge_smooth_spnr_bisr_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_drf_fail_0:1;
        RBus_UInt32  spnr_drf_fail_1:1;
        RBus_UInt32  res1:30;
    };
}iedge_smooth_spnr_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_dvs0:4;
        RBus_UInt32  spnr_dvse0:1;
        RBus_UInt32  spnr_ls_en:1;
        RBus_UInt32  res1:26;
    };
}iedge_smooth_spnr_dvs0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avlpf_bw_pattern_en:1;
        RBus_UInt32  avlpf_correct_en:1;
        RBus_UInt32  avlpf_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  avlpf_mindiff_curve_rate_finish:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  avlpf_mindiff_th_finish:8;
        RBus_UInt32  avlpf_mindiff_curve_rate_start:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  avlpf_mindiff_th_start:4;
        RBus_UInt32  vfir_weight:6;
        RBus_UInt32  res4:2;
    };
}iedge_smooth_vfilter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avlpf_min_weight:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  avlpf_max_weight:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  avlpf_maxmindiff_curve_rate:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  avlpf_maxmindiff_th:8;
    };
}iedge_smooth_vfilter_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vfir_c_weight:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  avlpf_c_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  avlpf_bw_curve_rate:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  avlpf_bw_margin:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  avlpf_bw_th:8;
    };
}iedge_smooth_vfilter_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vfir_debug:4;
        RBus_UInt32  res1:28;
    };
}iedge_smooth_vfilter_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edsm_db_en:1;
        RBus_UInt32  edsm_db_rd_sel:1;
        RBus_UInt32  edsm_db_apply:1;
        RBus_UInt32  res1:29;
    };
}iedge_smooth_edsm_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  sub_422_to_444_dup:1;
        RBus_UInt32  sub_422_to_444_type:1;
        RBus_UInt32  sub_422_to_444_en:1;
        RBus_UInt32  res2:13;
        RBus_UInt32  main_422_to_444_dup:1;
        RBus_UInt32  main_422_to_444_type:1;
        RBus_UInt32  main_422_to_444_en:1;
    };
}iedge_smooth_format_convert_RBUS;




#endif 


#endif 
