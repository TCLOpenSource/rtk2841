/**
* @file rbusInv_gammaReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/6/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_INV_GAMMA_REG_H_
#define _RBUS_INV_GAMMA_REG_H_

#include "rbusTypes.h"



//  INV_GAMMA Register Address



#define  INV_GAMMA_INV_GAMMA_PORT_VADDR                     	(0xb802c010)
#define  INV_GAMMA_INV_GAMMA_CTRL_1_VADDR                   	(0xb802c014)
#define  INV_GAMMA_INV_GAMMA_CTRL_2_VADDR                   	(0xb802c018)
#define  INV_GAMMA_ADAPT_INV_GAMMA_VADDR                    	(0xb802c01c)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======INV_GAMMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  inv_gamma_tab_index:14;
        RBus_UInt32  inv_gamma_tab_d0:8;
        RBus_UInt32  inv_gamma_tab_d1:8;
    };
}inv_gamma_inv_gamma_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  inv_gamma_tab_addr:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  inv_gamma_ax_rw_sel:2;
        RBus_UInt32  inv_gamma_ax_tab_sel:1;
        RBus_UInt32  inv_gamma_ax_ch_sel:2;
        RBus_UInt32  inv_gamma_fifo_empty:1;
        RBus_UInt32  inv_gamma_fifo_full:1;
        RBus_UInt32  inv_gamma_wr_error:1;
        RBus_UInt32  dummy1802c014_0:1;
    };
}inv_gamma_inv_gamma_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  inv_gamma_tab_size_sel:1;
        RBus_UInt32  inv_gamma_m_tab_sel:2;
        RBus_UInt32  inv_gamma_s_tab_sel:2;
        RBus_UInt32  inv_gamma_overlap:1;
        RBus_UInt32  dummy1802c018_2_0:3;
    };
}inv_gamma_inv_gamma_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inv_gamma_adapt_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  inv_gamma_sat_thl:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  inv_gamma_sat_thl_mul:14;
    };
}inv_gamma_adapt_inv_gamma_RBUS;

#else //apply LITTLE_ENDIAN

//======INV_GAMMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inv_gamma_tab_d1:8;
        RBus_UInt32  inv_gamma_tab_d0:8;
        RBus_UInt32  inv_gamma_tab_index:14;
        RBus_UInt32  res1:2;
    };
}inv_gamma_inv_gamma_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c014_0:1;
        RBus_UInt32  inv_gamma_wr_error:1;
        RBus_UInt32  inv_gamma_fifo_full:1;
        RBus_UInt32  inv_gamma_fifo_empty:1;
        RBus_UInt32  inv_gamma_ax_ch_sel:2;
        RBus_UInt32  inv_gamma_ax_tab_sel:1;
        RBus_UInt32  inv_gamma_ax_rw_sel:2;
        RBus_UInt32  res1:7;
        RBus_UInt32  inv_gamma_tab_addr:9;
        RBus_UInt32  res2:7;
    };
}inv_gamma_inv_gamma_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c018_2_0:3;
        RBus_UInt32  inv_gamma_overlap:1;
        RBus_UInt32  inv_gamma_s_tab_sel:2;
        RBus_UInt32  inv_gamma_m_tab_sel:2;
        RBus_UInt32  inv_gamma_tab_size_sel:1;
        RBus_UInt32  res1:23;
    };
}inv_gamma_inv_gamma_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inv_gamma_sat_thl_mul:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  inv_gamma_sat_thl:14;
        RBus_UInt32  res2:1;
        RBus_UInt32  inv_gamma_adapt_en:1;
    };
}inv_gamma_adapt_inv_gamma_RBUS;




#endif 


#endif 
