/**
* @file rbusModelCtrlReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2006/11/3
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_MODELCTRL_REG_H_
#define _RBUS_MODELCTRL_REG_H_

#include "rbus/rbusTypes.h"




// MODELCTRL Register Address
#define MODELCTRL_MODEL_CTRL_ADDR                  (0x180731fc)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======MODELCTRL register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  model_process_en:1;
    };
}model_ctrl_RBUS;





#else //apply LITTLE_ENDIAN


//======MODELCTRL register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  model_process_en:1;
        RBus_UInt32  res1:31;
    };
}model_ctrl_RBUS;


#endif







#endif //_RBUS_MODELCTRL_REG_H_
