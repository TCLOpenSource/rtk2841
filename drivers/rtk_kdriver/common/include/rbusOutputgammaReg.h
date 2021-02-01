/**
* @file rbusOutputgammaReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/6/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_OUTPUTGAMMA_REG_H_
#define _RBUS_OUTPUTGAMMA_REG_H_

#include "rbusTypes.h"



//  OUTPUTGAMMA Register Address



#define  OUTPUTGAMMA_OUT_GAMMA_PORT_VADDR                   	(0xb802c800)
#define  OUTPUTGAMMA_OUT_GAMMA_CTRL_1_VADDR                 	(0xb802c804)
#define  OUTPUTGAMMA_OUT_GAMMA_BIST_CTRL_1_VADDR            	(0xb802c808)
#define  OUTPUTGAMMA_OUT_GAMMA_BIST_CTRL_3_VADDR            	(0xb802c810)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======OUTPUTGAMMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  out_gamma_tab_index:12;
        RBus_UInt32  res2:1;
        RBus_UInt32  out_gamma_tab_d0:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  out_gamma_tab_d1:7;
    };
}outputgamma_out_gamma_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  out_gamma_tab_addr:7;
        RBus_UInt32  res2:7;
        RBus_UInt32  out_gamma_ax_rw_sel:2;
        RBus_UInt32  out_gamma_ax_ch_sel:2;
        RBus_UInt32  out_gamma_fifo_empty:1;
        RBus_UInt32  out_gamma_fifo_full:1;
        RBus_UInt32  out_gamma_wr_error:1;
        RBus_UInt32  dummy1802c804_1:1;
        RBus_UInt32  out_gamma_en:1;
    };
}outputgamma_out_gamma_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ls:1;
        RBus_UInt32  rme:1;
        RBus_UInt32  rm:4;
    };
}outputgamma_out_gamma_bist_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  out_gamma_r1_drf_bist_fail:1;
        RBus_UInt32  out_gamma_g1_drf_bist_fail:1;
        RBus_UInt32  out_gamma_b1_drf_bist_fail:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  out_gamma_r_drf_bist_fail:1;
        RBus_UInt32  out_gamma_g_drf_bist_fail:1;
        RBus_UInt32  out_gamma_b_drf_bist_fail:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  out_gamma_r1_bist_fail:1;
        RBus_UInt32  out_gamma_g1_bist_fail:1;
        RBus_UInt32  out_gamma_b1_bist_fail:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  out_gamma_r_bist_fail:1;
        RBus_UInt32  out_gamma_g_bist_fail:1;
        RBus_UInt32  out_gamma_b_bist_fail:1;
    };
}outputgamma_out_gamma_bist_ctrl_3_RBUS;

#else //apply LITTLE_ENDIAN

//======OUTPUTGAMMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  out_gamma_tab_d1:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  out_gamma_tab_d0:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  out_gamma_tab_index:12;
        RBus_UInt32  res3:4;
    };
}outputgamma_out_gamma_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  out_gamma_en:1;
        RBus_UInt32  dummy1802c804_1:1;
        RBus_UInt32  out_gamma_wr_error:1;
        RBus_UInt32  out_gamma_fifo_full:1;
        RBus_UInt32  out_gamma_fifo_empty:1;
        RBus_UInt32  out_gamma_ax_ch_sel:2;
        RBus_UInt32  out_gamma_ax_rw_sel:2;
        RBus_UInt32  res1:7;
        RBus_UInt32  out_gamma_tab_addr:7;
        RBus_UInt32  res2:9;
    };
}outputgamma_out_gamma_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm:4;
        RBus_UInt32  rme:1;
        RBus_UInt32  ls:1;
        RBus_UInt32  res1:26;
    };
}outputgamma_out_gamma_bist_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  out_gamma_b_bist_fail:1;
        RBus_UInt32  out_gamma_g_bist_fail:1;
        RBus_UInt32  out_gamma_r_bist_fail:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  out_gamma_b1_bist_fail:1;
        RBus_UInt32  out_gamma_g1_bist_fail:1;
        RBus_UInt32  out_gamma_r1_bist_fail:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  out_gamma_b_drf_bist_fail:1;
        RBus_UInt32  out_gamma_g_drf_bist_fail:1;
        RBus_UInt32  out_gamma_r_drf_bist_fail:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  out_gamma_b1_drf_bist_fail:1;
        RBus_UInt32  out_gamma_g1_drf_bist_fail:1;
        RBus_UInt32  out_gamma_r1_drf_bist_fail:1;
        RBus_UInt32  res4:17;
    };
}outputgamma_out_gamma_bist_ctrl_3_RBUS;




#endif 


#endif 
