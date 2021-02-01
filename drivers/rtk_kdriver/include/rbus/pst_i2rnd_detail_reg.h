/**
* @file Mac5-DesignSpec-IMD_Pst_and_I2rnd_detail_register
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PST_I2RND_DETAIL_REG_H_
#define _RBUS_PST_I2RND_DETAIL_REG_H_

#include "rbus_types.h"



//  PST_I2RND_DETAIL Register Address
#define  PST_I2RND_DETAIL_vodma_i2rnd                                            0x18005200
#define  PST_I2RND_DETAIL_vodma_i2rnd_reg_addr                                   "0xB8005200"
#define  PST_I2RND_DETAIL_vodma_i2rnd_reg                                        0xB8005200
#define  PST_I2RND_DETAIL_vodma_i2rnd_inst_addr                                  "0x0000"
#define  set_PST_I2RND_DETAIL_vodma_i2rnd_reg(data)                              (*((volatile unsigned int*)PST_I2RND_DETAIL_vodma_i2rnd_reg)=data)
#define  get_PST_I2RND_DETAIL_vodma_i2rnd_reg                                    (*((volatile unsigned int*)PST_I2RND_DETAIL_vodma_i2rnd_reg))
#define  PST_I2RND_DETAIL_vodma_i2rnd_i2rnd_src_flag_inv_shift                   (3)
#define  PST_I2RND_DETAIL_vodma_i2rnd_i2rnd_timing_mode_shift                    (1)
#define  PST_I2RND_DETAIL_vodma_i2rnd_i2rnd_timing_en_shift                      (0)
#define  PST_I2RND_DETAIL_vodma_i2rnd_i2rnd_src_flag_inv_mask                    (0x00000008)
#define  PST_I2RND_DETAIL_vodma_i2rnd_i2rnd_timing_mode_mask                     (0x00000006)
#define  PST_I2RND_DETAIL_vodma_i2rnd_i2rnd_timing_en_mask                       (0x00000001)
#define  PST_I2RND_DETAIL_vodma_i2rnd_i2rnd_src_flag_inv(data)                   (0x00000008&((data)<<3))
#define  PST_I2RND_DETAIL_vodma_i2rnd_i2rnd_timing_mode(data)                    (0x00000006&((data)<<1))
#define  PST_I2RND_DETAIL_vodma_i2rnd_i2rnd_timing_en(data)                      (0x00000001&(data))
#define  PST_I2RND_DETAIL_vodma_i2rnd_get_i2rnd_src_flag_inv(data)               ((0x00000008&(data))>>3)
#define  PST_I2RND_DETAIL_vodma_i2rnd_get_i2rnd_timing_mode(data)                ((0x00000006&(data))>>1)
#define  PST_I2RND_DETAIL_vodma_i2rnd_get_i2rnd_timing_en(data)                  (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PST_I2RND_DETAIL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  i2rnd_src_flag_inv:1;
        RBus_UInt32  i2rnd_timing_mode:2;
        RBus_UInt32  i2rnd_timing_en:1;
    };
}pst_i2rnd_detail_vodma_i2rnd_RBUS;

#else //apply LITTLE_ENDIAN

//======PST_I2RND_DETAIL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2rnd_timing_en:1;
        RBus_UInt32  i2rnd_timing_mode:2;
        RBus_UInt32  i2rnd_src_flag_inv:1;
        RBus_UInt32  res1:28;
    };
}pst_i2rnd_detail_vodma_i2rnd_RBUS;




#endif 


#endif 
