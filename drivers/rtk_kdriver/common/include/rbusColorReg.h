/**
* @file rbusColorReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_REG_H_
#define _RBUS_COLOR_REG_H_

#include "rbusTypes.h"



//  COLOR Register Address



#define  COLOR_D_VC_GLOBAL_CTRL_VADDR                       	(0xb802a000)
#define  COLOR_D_VC_GLOBAL_CTRL_DB_VADDR                    	(0xb802a004)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_vc_en:1;
        RBus_UInt32  m_vc_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  highlightwin_inv:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  s_sharp_en:1;
        RBus_UInt32  s_icm_en:1;
        RBus_UInt32  s_dcti_en:1;
        RBus_UInt32  icm_dcc_swap:1;
        RBus_UInt32  dummy1802a000_15_12:4;
        RBus_UInt32  hlw_shpnr_enhance_en:1;
        RBus_UInt32  hlw_shpnr_enhance_mode:3;
        RBus_UInt32  reg_bypass_pq:1;
        RBus_UInt32  reg_bypass_pq_sel:1;
        RBus_UInt32  m_edgesmooth_en:1;
        RBus_UInt32  m_sharp_en:1;
        RBus_UInt32  m_icm_en:1;
        RBus_UInt32  m_dcti_en:1;
        RBus_UInt32  m_lc_comp_en:1;
        RBus_UInt32  dcc_en:1;
    };
}color_d_vc_global_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_read:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_load:1;
    };
}color_d_vc_global_ctrl_db_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcc_en:1;
        RBus_UInt32  m_lc_comp_en:1;
        RBus_UInt32  m_dcti_en:1;
        RBus_UInt32  m_icm_en:1;
        RBus_UInt32  m_sharp_en:1;
        RBus_UInt32  m_edgesmooth_en:1;
        RBus_UInt32  reg_bypass_pq_sel:1;
        RBus_UInt32  reg_bypass_pq:1;
        RBus_UInt32  hlw_shpnr_enhance_mode:3;
        RBus_UInt32  hlw_shpnr_enhance_en:1;
        RBus_UInt32  dummy1802a000_15:4;
        RBus_UInt32  icm_dcc_swap:1;
        RBus_UInt32  s_dcti_en:1;
        RBus_UInt32  s_icm_en:1;
        RBus_UInt32  s_sharp_en:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  highlightwin_inv:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  m_vc_en:1;
        RBus_UInt32  s_vc_en:1;
    };
}color_d_vc_global_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_load:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read:1;
        RBus_UInt32  res1:29;
    };
}color_d_vc_global_ctrl_db_RBUS;




#endif 


#endif 
