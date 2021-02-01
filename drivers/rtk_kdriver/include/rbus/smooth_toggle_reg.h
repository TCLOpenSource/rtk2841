/**
* @file Mac5-DesignSpec-IMD_smooth_toggle
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SMOOTH_TOGGLE_REG_H_
#define _RBUS_SMOOTH_TOGGLE_REG_H_

#include "rbus_types.h"



//  SMOOTH_TOGGLE Register Address
#define  SMOOTH_TOGGLE_db_reg_ctl                                                0x18024490
#define  SMOOTH_TOGGLE_db_reg_ctl_reg_addr                                       "0xB8024490"
#define  SMOOTH_TOGGLE_db_reg_ctl_reg                                            0xB8024490
#define  SMOOTH_TOGGLE_db_reg_ctl_inst_addr                                      "0x0000"
#define  set_SMOOTH_TOGGLE_db_reg_ctl_reg(data)                                  (*((volatile unsigned int*)SMOOTH_TOGGLE_db_reg_ctl_reg)=data)
#define  get_SMOOTH_TOGGLE_db_reg_ctl_reg                                        (*((volatile unsigned int*)SMOOTH_TOGGLE_db_reg_ctl_reg))
#define  SMOOTH_TOGGLE_db_reg_ctl_sm_tog_apply_disable_shift                     (31)
#define  SMOOTH_TOGGLE_db_reg_ctl_sm_tog_3d_mode_shift                           (30)
#define  SMOOTH_TOGGLE_db_reg_ctl_db_read_shift                                  (2)
#define  SMOOTH_TOGGLE_db_reg_ctl_db_en_shift                                    (1)
#define  SMOOTH_TOGGLE_db_reg_ctl_db_apply_shift                                 (0)
#define  SMOOTH_TOGGLE_db_reg_ctl_sm_tog_apply_disable_mask                      (0x80000000)
#define  SMOOTH_TOGGLE_db_reg_ctl_sm_tog_3d_mode_mask                            (0x40000000)
#define  SMOOTH_TOGGLE_db_reg_ctl_db_read_mask                                   (0x00000004)
#define  SMOOTH_TOGGLE_db_reg_ctl_db_en_mask                                     (0x00000002)
#define  SMOOTH_TOGGLE_db_reg_ctl_db_apply_mask                                  (0x00000001)
#define  SMOOTH_TOGGLE_db_reg_ctl_sm_tog_apply_disable(data)                     (0x80000000&((data)<<31))
#define  SMOOTH_TOGGLE_db_reg_ctl_sm_tog_3d_mode(data)                           (0x40000000&((data)<<30))
#define  SMOOTH_TOGGLE_db_reg_ctl_db_read(data)                                  (0x00000004&((data)<<2))
#define  SMOOTH_TOGGLE_db_reg_ctl_db_en(data)                                    (0x00000002&((data)<<1))
#define  SMOOTH_TOGGLE_db_reg_ctl_db_apply(data)                                 (0x00000001&(data))
#define  SMOOTH_TOGGLE_db_reg_ctl_get_sm_tog_apply_disable(data)                 ((0x80000000&(data))>>31)
#define  SMOOTH_TOGGLE_db_reg_ctl_get_sm_tog_3d_mode(data)                       ((0x40000000&(data))>>30)
#define  SMOOTH_TOGGLE_db_reg_ctl_get_db_read(data)                              ((0x00000004&(data))>>2)
#define  SMOOTH_TOGGLE_db_reg_ctl_get_db_en(data)                                ((0x00000002&(data))>>1)
#define  SMOOTH_TOGGLE_db_reg_ctl_get_db_apply(data)                             (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SMOOTH_TOGGLE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sm_tog_apply_disable:1;
        RBus_UInt32  sm_tog_3d_mode:1;
        RBus_UInt32  res1:27;
        RBus_UInt32  db_read:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_apply:1;
    };
}smooth_toggle_db_reg_ctl_RBUS;

#else //apply LITTLE_ENDIAN

//======SMOOTH_TOGGLE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read:1;
        RBus_UInt32  res1:27;
        RBus_UInt32  sm_tog_3d_mode:1;
        RBus_UInt32  sm_tog_apply_disable:1;
    };
}smooth_toggle_db_reg_ctl_RBUS;




#endif 


#endif 
