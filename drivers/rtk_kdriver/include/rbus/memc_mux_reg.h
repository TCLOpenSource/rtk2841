/**
* @file Mac5-DesignSpec-D-Domain_MEMC_mux
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MEMC_MUX_REG_H_
#define _RBUS_MEMC_MUX_REG_H_

#include "rbus_types.h"



//  MEMC_MUX Register Address
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL                                             0x1802E800
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_reg_addr                                    "0xB802E800"
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_reg                                         0xB802E800
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_inst_addr                                   "0x0000"
#define  set_MEMC_MUX_MEMC_MUX_FUNC_CTRL_reg(data)                               (*((volatile unsigned int*)MEMC_MUX_MEMC_MUX_FUNC_CTRL_reg)=data)
#define  get_MEMC_MUX_MEMC_MUX_FUNC_CTRL_reg                                     (*((volatile unsigned int*)MEMC_MUX_MEMC_MUX_FUNC_CTRL_reg))
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_fifoof_shift                       (7)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_fifofull_shift                     (6)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_fifouf_shift                       (5)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_fifoempty_shift                    (4)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_en_shift                           (0)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_fifoof_mask                        (0x00000080)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_fifofull_mask                      (0x00000040)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_fifouf_mask                        (0x00000020)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_fifoempty_mask                     (0x00000010)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_en_mask                            (0x00000001)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_fifoof(data)                       (0x00000080&((data)<<7))
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_fifofull(data)                     (0x00000040&((data)<<6))
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_fifouf(data)                       (0x00000020&((data)<<5))
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_fifoempty(data)                    (0x00000010&((data)<<4))
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_memc_mux_en(data)                           (0x00000001&(data))
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_get_memc_mux_fifoof(data)                   ((0x00000080&(data))>>7)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_get_memc_mux_fifofull(data)                 ((0x00000040&(data))>>6)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_get_memc_mux_fifouf(data)                   ((0x00000020&(data))>>5)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_get_memc_mux_fifoempty(data)                ((0x00000010&(data))>>4)
#define  MEMC_MUX_MEMC_MUX_FUNC_CTRL_get_memc_mux_en(data)                       (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MEMC_MUX register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  memc_mux_fifoof:1;
        RBus_UInt32  memc_mux_fifofull:1;
        RBus_UInt32  memc_mux_fifouf:1;
        RBus_UInt32  memc_mux_fifoempty:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  memc_mux_en:1;
    };
}memc_mux_memc_mux_func_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======MEMC_MUX register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_mux_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  memc_mux_fifoempty:1;
        RBus_UInt32  memc_mux_fifouf:1;
        RBus_UInt32  memc_mux_fifofull:1;
        RBus_UInt32  memc_mux_fifoof:1;
        RBus_UInt32  res2:24;
    };
}memc_mux_memc_mux_func_ctrl_RBUS;




#endif 


#endif 
