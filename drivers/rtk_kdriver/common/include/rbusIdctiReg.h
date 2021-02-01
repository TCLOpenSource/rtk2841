/**
* @file rbusIDCTIReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IDCTI_REG_H_
#define _RBUS_IDCTI_REG_H_

#include "rbusTypes.h"



//  IDCTI Register Address



#define  IDCTI_I_DCTI_CTRL_1_VADDR                          	(0xb80231d4)
#define  IDCTI_I_DCTI_CTRL_2_VADDR                          	(0xb80231d8)
#define  IDCTI_I_DCTI_CTRL_3_VADDR                          	(0xb80231dc)
#define  IDCTI_I_DCTI_CTRL_4_VADDR                          	(0xb80231e0)
#define  IDCTI_I_DCTI_CTRL_5_VADDR                          	(0xb80231e4)
#define  IDCTI_I_DCTI_CTRL_6_VADDR                          	(0xb80231e8)
#define  IDCTI_I_DCTI_CTRL_7_VADDR                          	(0xb80231ec)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IDCTI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_sel:1;
        RBus_UInt32  maxlen:3;
        RBus_UInt32  psmth:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  lp_mode:3;
        RBus_UInt32  engdiv:2;
        RBus_UInt32  offdiv:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  uvgain:7;
        RBus_UInt32  dcti_mode:1;
        RBus_UInt32  uvalign_en:1;
        RBus_UInt32  cur_sel:1;
        RBus_UInt32  dcti_en:1;
    };
}idcti_i_dcti_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvsync_en:1;
        RBus_UInt32  tran_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  rate_steep:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  th_steep:6;
        RBus_UInt32  th_coring:5;
        RBus_UInt32  steep_mode:3;
        RBus_UInt32  hp_mode:3;
        RBus_UInt32  vlp_mode:3;
        RBus_UInt32  median_mode:1;
        RBus_UInt32  blending_mode:1;
    };
}idcti_i_dcti_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  maxminlen:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  rate_tran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  th_tran:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  region_mode:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  rate_smooth:3;
        RBus_UInt32  res6:2;
        RBus_UInt32  th_smooth:6;
    };
}idcti_i_dcti_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  rate_align_weight:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  rate_align:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  th_align:7;
        RBus_UInt32  res4:2;
        RBus_UInt32  align_mingain:6;
        RBus_UInt32  res5:2;
        RBus_UInt32  th_gtran:6;
    };
}idcti_i_dcti_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_en:1;
        RBus_UInt32  th_uvmindiff:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  rate_stair2:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  rate_stair1:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  th_stair:6;
        RBus_UInt32  res4:3;
        RBus_UInt32  th_align_weight:5;
    };
}idcti_i_dcti_ctrl_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  statistic_hist:19;
        RBus_UInt32  rate_engsync:3;
        RBus_UInt32  rate_uvmindiff:3;
        RBus_UInt32  th_engsync:6;
    };
}idcti_i_dcti_ctrl_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  debug_shiftbit:3;
        RBus_UInt32  debug_mode:3;
        RBus_UInt32  high_bound:6;
        RBus_UInt32  low_bound:6;
    };
}idcti_i_dcti_ctrl_7_RBUS;

#else //apply LITTLE_ENDIAN

//======IDCTI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_en:1;
        RBus_UInt32  cur_sel:1;
        RBus_UInt32  uvalign_en:1;
        RBus_UInt32  dcti_mode:1;
        RBus_UInt32  uvgain:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  offdiv:2;
        RBus_UInt32  engdiv:2;
        RBus_UInt32  lp_mode:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  psmth:8;
        RBus_UInt32  maxlen:3;
        RBus_UInt32  data_sel:1;
    };
}idcti_i_dcti_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blending_mode:1;
        RBus_UInt32  median_mode:1;
        RBus_UInt32  vlp_mode:3;
        RBus_UInt32  hp_mode:3;
        RBus_UInt32  steep_mode:3;
        RBus_UInt32  th_coring:5;
        RBus_UInt32  th_steep:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  rate_steep:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  tran_mode:3;
        RBus_UInt32  uvsync_en:1;
    };
}idcti_i_dcti_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  th_smooth:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  rate_smooth:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  region_mode:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  th_tran:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  rate_tran:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  maxminlen:3;
        RBus_UInt32  res6:1;
    };
}idcti_i_dcti_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  th_gtran:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  align_mingain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  th_align:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  rate_align:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  rate_align_weight:3;
        RBus_UInt32  res5:1;
    };
}idcti_i_dcti_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  th_align_weight:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  th_stair:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  rate_stair1:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  rate_stair2:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  th_uvmindiff:7;
        RBus_UInt32  statistic_en:1;
    };
}idcti_i_dcti_ctrl_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  th_engsync:6;
        RBus_UInt32  rate_uvmindiff:3;
        RBus_UInt32  rate_engsync:3;
        RBus_UInt32  statistic_hist:19;
        RBus_UInt32  res1:1;
    };
}idcti_i_dcti_ctrl_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_bound:6;
        RBus_UInt32  high_bound:6;
        RBus_UInt32  debug_mode:3;
        RBus_UInt32  debug_shiftbit:3;
        RBus_UInt32  res1:14;
    };
}idcti_i_dcti_ctrl_7_RBUS;




#endif 


#endif 
