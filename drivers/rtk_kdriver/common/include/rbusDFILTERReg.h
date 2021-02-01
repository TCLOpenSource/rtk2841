/**
* @file rbusDfilterReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/8/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DFILTER_REG_H_
#define _RBUS_DFILTER_REG_H_

#include "rbusTypes.h"



//  DFILTER Register Address



#define  DFILTER_ICH1_DFILTER_PH_SMR_PRING_VADDR            	(0xb8023500)
#define  DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_VADDR     	(0xb8023504)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DFILTER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_pring_div:2;
        RBus_UInt32  ch1_thd_pring:3;
        RBus_UInt32  ch1_pring_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch1_nsmr_div:2;
        RBus_UInt32  ch1_thd_nsmr:3;
        RBus_UInt32  ch1_nsmr_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch1_psmr_div:2;
        RBus_UInt32  ch1_thd_psmr:3;
        RBus_UInt32  ch1_psmr_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch1_ph_div:2;
        RBus_UInt32  ch1_thd_ph:3;
        RBus_UInt32  ch1_ph_en:1;
    };
}dfilter_ich1_dfilter_ph_smr_pring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  ch1_fight_sel:2;
        RBus_UInt32  ch1_nos_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch1_pr_en:1;
        RBus_UInt32  ch1_pb_en:1;
        RBus_UInt32  ch1_y_en:1;
        RBus_UInt32  ch1_thd_nos:3;
        RBus_UInt32  ch1_nos_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch1_thd_mis:1;
        RBus_UInt32  ch1_mis_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch1_nring_div:2;
        RBus_UInt32  ch1_thd_nring:3;
        RBus_UInt32  ch1_nring_en:1;
    };
}dfilter_ich1_dfilter_nring_mis_nos_ypbpr_RBUS;

#else //apply LITTLE_ENDIAN

//======DFILTER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_ph_en:1;
        RBus_UInt32  ch1_thd_ph:3;
        RBus_UInt32  ch1_ph_div:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_psmr_en:1;
        RBus_UInt32  ch1_thd_psmr:3;
        RBus_UInt32  ch1_psmr_div:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch1_nsmr_en:1;
        RBus_UInt32  ch1_thd_nsmr:3;
        RBus_UInt32  ch1_nsmr_div:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch1_pring_en:1;
        RBus_UInt32  ch1_thd_pring:3;
        RBus_UInt32  ch1_pring_div:2;
        RBus_UInt32  res4:2;
    };
}dfilter_ich1_dfilter_ph_smr_pring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_nring_en:1;
        RBus_UInt32  ch1_thd_nring:3;
        RBus_UInt32  ch1_nring_div:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_mis_en:1;
        RBus_UInt32  ch1_thd_mis:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch1_nos_en:1;
        RBus_UInt32  ch1_thd_nos:3;
        RBus_UInt32  ch1_y_en:1;
        RBus_UInt32  ch1_pb_en:1;
        RBus_UInt32  ch1_pr_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  ch1_nos_sel:1;
        RBus_UInt32  ch1_fight_sel:2;
        RBus_UInt32  res4:9;
    };
}dfilter_ich1_dfilter_nring_mis_nos_ypbpr_RBUS;




#endif 


#endif 
