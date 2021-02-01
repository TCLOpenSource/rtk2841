/**
* @file rbusMacArthur2-DesignSpec-I-Domain_Edge_SmoothReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2013/5/22
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MACARTHUR2_DESIGNSPEC_I_DOMAIN_EDGE_SMOOTH_REG_H_
#define _RBUS_MACARTHUR2_DESIGNSPEC_I_DOMAIN_EDGE_SMOOTH_REG_H_

#include "rbus/rbusTypes.h"



//  MACARTHUR2-DESIGNSPEC-I-DOMAIN_EDGE_SMOOTH Register Address



#define  I_EDGE_SMOOTH_EDGESMOOTH_EX_CTRL_VADDR 		(0xb8025100)
#define  I_EDGE_SMOOTH_EDGESMOOTH_EX_CTRL2_VADDR 		(0xb8025104)
#define  I_EDGE_SMOOTH_EDGESMOOTH_EX_CTRL3_VADDR 		(0xb8025108)
#define  I_EDGE_SMOOTH_MIXER_CTRL_VADDR 		(0xb802510c)
#define  I_EDGE_SMOOTH_EDGESMOOTH_EXTENSION_VADDR 		(0xb8025110)
#define  I_EDGE_SMOOTH_EDGESMOOTH_EXT_ANGLE_VADDR 		(0xb802511c)
#define  I_EDGE_SMOOTH_DEMO_WINDOW_CTRL0_VADDR 		(0xb8025120)
#define  I_EDGE_SMOOTH_DEMO_WINDOW_CTRL1_VADDR 		(0xb8025124)
#define  I_EDGE_SMOOTH_PRELPF_CTRL_VADDR 		(0xb8025128)
#define  I_EDGE_SMOOTH_DLTI2D_CTRL_VADDR 		(0xb802512c)
#define  I_EDGE_SMOOTH_EDGESMOOTH_MESS_DIRECTION1_VADDR 		(0xb8025130)
#define  I_EDGE_SMOOTH_EDGESMOOTH_MESS_DIRECTION2_VADDR 		(0xb8025134)
#define  I_EDGE_SMOOTH_EDGESMOOTH_BLEND_WEIGHT_LPF_VADDR 		(0xb8025138)
#define  I_EDGE_SMOOTH_EDGESMOOTH_UNSTABLE_AREA_VADDR 		(0xb802513c)
#define  I_EDGE_SMOOTH_SPNR_DRF_FAIL_VADDR 		(0xb802514c)
#define  I_EDGE_SMOOTH_SPNR_DVS0_VADDR 		(0xb8025150)
#define  I_EDGE_SMOOTH_EDSM_DB_CTRL_VADDR 		(0xb8025170)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MACARTHUR2-DESIGNSPEC-I-DOMAIN_EDGE_SMOOTH register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  dummy18025100_25_18:8;
        RBus_UInt32  tst_en:1;
        RBus_UInt32  lbuf_disable:1;
        RBus_UInt32  debug_mode:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  edgemode:1;
        RBus_UInt32  lbuf_5linemode:1;
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
}edgesmooth_ex_ctrl_RBUS;

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
}edgesmooth_ex_ctrl2_RBUS;

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
}edgesmooth_ex_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  iedge_nr_sel:1;
        RBus_UInt32  iedge_mixer_weight:4;
        RBus_UInt32  vfir_weight:4;
    };
}mixer_ctrl_RBUS;

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
}edgesmooth_extension_RBUS;

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
}edgesmooth_ext_angle_RBUS;

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
}demo_window_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_v_end:12;
        RBus_UInt32  reg_v_start:12;
    };
}demo_window_ctrl1_RBUS;

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
}prelpf_ctrl_RBUS;

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
}dlti2d_ctrl_RBUS;

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
}edgesmooth_mess_direction1_RBUS;

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
}edgesmooth_mess_direction2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blend_weight_lpf_en:1;
        RBus_UInt32  res1:31;
    };
}edgesmooth_blend_weight_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  unstable_area_en:1;
        RBus_UInt32  res1:26;
        RBus_UInt32  unstable_area_thd:5;
    };
}edgesmooth_unstable_area_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  spnr_drf_fail_0:1;
    };
}spnr_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  spnr_ls_en:1;
        RBus_UInt32  spnr_dvse0:1;
        RBus_UInt32  spnr_dvs0:4;
    };
}spnr_dvs0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  edsm_db_apply:1;
        RBus_UInt32  edsm_db_rd_sel:1;
        RBus_UInt32  edsm_db_en:1;
    };
}edsm_db_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======MACARTHUR2-DESIGNSPEC-I-DOMAIN_EDGE_SMOOTH register structure define==========

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
        RBus_UInt32  lbuf_5linemode:1;
        RBus_UInt32  edgemode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  debug_mode:4;
        RBus_UInt32  lbuf_disable:1;
        RBus_UInt32  tst_en:1;
        RBus_UInt32  dummy18025100_25:8;
        RBus_UInt32  res2:6;
    };
}edgesmooth_ex_ctrl_RBUS;

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
}edgesmooth_ex_ctrl2_RBUS;

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
}edgesmooth_ex_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vfir_weight:4;
        RBus_UInt32  iedge_mixer_weight:4;
        RBus_UInt32  iedge_nr_sel:1;
        RBus_UInt32  res1:23;
    };
}mixer_ctrl_RBUS;

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
}edgesmooth_extension_RBUS;

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
}edgesmooth_ext_angle_RBUS;

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
}demo_window_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_v_start:12;
        RBus_UInt32  reg_v_end:12;
        RBus_UInt32  res1:8;
    };
}demo_window_ctrl1_RBUS;

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
}prelpf_ctrl_RBUS;

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
}dlti2d_ctrl_RBUS;

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
}edgesmooth_mess_direction1_RBUS;

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
}edgesmooth_mess_direction2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  blend_weight_lpf_en:1;
    };
}edgesmooth_blend_weight_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  unstable_area_thd:5;
        RBus_UInt32  res1:26;
        RBus_UInt32  unstable_area_en:1;
    };
}edgesmooth_unstable_area_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_drf_fail_0:1;
        RBus_UInt32  res1:31;
    };
}spnr_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_dvs0:4;
        RBus_UInt32  spnr_dvse0:1;
        RBus_UInt32  spnr_ls_en:1;
        RBus_UInt32  res1:26;
    };
}spnr_dvs0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edsm_db_en:1;
        RBus_UInt32  edsm_db_rd_sel:1;
        RBus_UInt32  edsm_db_apply:1;
        RBus_UInt32  res1:29;
    };
}edsm_db_ctrl_RBUS;




#endif 


#endif 
