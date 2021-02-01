/**
* @file Macarthur5-DesignSpec-ISO_MISC_OFF_arch_spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ISO_MISC_OFF_REG_H_
#define _RBUS_ISO_MISC_OFF_REG_H_

#include "rbus_types.h"



//  ISO_MISC_OFF Register Address
#define  ISO_MISC_OFF_ISR                                                        0x18062100
#define  ISO_MISC_OFF_ISR_reg_addr                                               "0xB8062100"
#define  ISO_MISC_OFF_ISR_reg                                                    0xB8062100
#define  ISO_MISC_OFF_ISR_inst_addr                                              "0x0000"
#define  set_ISO_MISC_OFF_ISR_reg(data)                                          (*((volatile unsigned int*)ISO_MISC_OFF_ISR_reg)=data)
#define  get_ISO_MISC_OFF_ISR_reg                                                (*((volatile unsigned int*)ISO_MISC_OFF_ISR_reg))
#define  ISO_MISC_OFF_ISR_wdog_ov_int_shift                                      (4)
#define  ISO_MISC_OFF_ISR_irda1_int_shift                                        (3)
#define  ISO_MISC_OFF_ISR_ur0_int_shift                                          (2)
#define  ISO_MISC_OFF_ISR_i2c0_int_shift                                         (1)
#define  ISO_MISC_OFF_ISR_i2c5_int_shift                                         (0)
#define  ISO_MISC_OFF_ISR_wdog_ov_int_mask                                       (0x00000010)
#define  ISO_MISC_OFF_ISR_irda1_int_mask                                         (0x00000008)
#define  ISO_MISC_OFF_ISR_ur0_int_mask                                           (0x00000004)
#define  ISO_MISC_OFF_ISR_i2c0_int_mask                                          (0x00000002)
#define  ISO_MISC_OFF_ISR_i2c5_int_mask                                          (0x00000001)
#define  ISO_MISC_OFF_ISR_wdog_ov_int(data)                                      (0x00000010&((data)<<4))
#define  ISO_MISC_OFF_ISR_irda1_int(data)                                        (0x00000008&((data)<<3))
#define  ISO_MISC_OFF_ISR_ur0_int(data)                                          (0x00000004&((data)<<2))
#define  ISO_MISC_OFF_ISR_i2c0_int(data)                                         (0x00000002&((data)<<1))
#define  ISO_MISC_OFF_ISR_i2c5_int(data)                                         (0x00000001&(data))
#define  ISO_MISC_OFF_ISR_get_wdog_ov_int(data)                                  ((0x00000010&(data))>>4)
#define  ISO_MISC_OFF_ISR_get_irda1_int(data)                                    ((0x00000008&(data))>>3)
#define  ISO_MISC_OFF_ISR_get_ur0_int(data)                                      ((0x00000004&(data))>>2)
#define  ISO_MISC_OFF_ISR_get_i2c0_int(data)                                     ((0x00000002&(data))>>1)
#define  ISO_MISC_OFF_ISR_get_i2c5_int(data)                                     (0x00000001&(data))

#define  ISO_MISC_OFF_SYSTEM                                                     0x18062104
#define  ISO_MISC_OFF_SYSTEM_reg_addr                                            "0xB8062104"
#define  ISO_MISC_OFF_SYSTEM_reg                                                 0xB8062104
#define  ISO_MISC_OFF_SYSTEM_inst_addr                                           "0x0001"
#define  set_ISO_MISC_OFF_SYSTEM_reg(data)                                       (*((volatile unsigned int*)ISO_MISC_OFF_SYSTEM_reg)=data)
#define  get_ISO_MISC_OFF_SYSTEM_reg                                             (*((volatile unsigned int*)ISO_MISC_OFF_SYSTEM_reg))
#define  ISO_MISC_OFF_SYSTEM_irdarxdetec_shift                                   (16)
#define  ISO_MISC_OFF_SYSTEM_uart_od_mode_en_shift                               (14)
#define  ISO_MISC_OFF_SYSTEM_dbg_sel_shift                                       (0)
#define  ISO_MISC_OFF_SYSTEM_irdarxdetec_mask                                    (0x00010000)
#define  ISO_MISC_OFF_SYSTEM_uart_od_mode_en_mask                                (0x00004000)
#define  ISO_MISC_OFF_SYSTEM_dbg_sel_mask                                        (0x0000000F)
#define  ISO_MISC_OFF_SYSTEM_irdarxdetec(data)                                   (0x00010000&((data)<<16))
#define  ISO_MISC_OFF_SYSTEM_uart_od_mode_en(data)                               (0x00004000&((data)<<14))
#define  ISO_MISC_OFF_SYSTEM_dbg_sel(data)                                       (0x0000000F&(data))
#define  ISO_MISC_OFF_SYSTEM_get_irdarxdetec(data)                               ((0x00010000&(data))>>16)
#define  ISO_MISC_OFF_SYSTEM_get_uart_od_mode_en(data)                           ((0x00004000&(data))>>14)
#define  ISO_MISC_OFF_SYSTEM_get_dbg_sel(data)                                   (0x0000000F&(data))

#define  ISO_MISC_OFF_DUMMY1                                                     0x18062108
#define  ISO_MISC_OFF_DUMMY1_reg_addr                                            "0xB8062108"
#define  ISO_MISC_OFF_DUMMY1_reg                                                 0xB8062108
#define  ISO_MISC_OFF_DUMMY1_inst_addr                                           "0x0002"
#define  set_ISO_MISC_OFF_DUMMY1_reg(data)                                       (*((volatile unsigned int*)ISO_MISC_OFF_DUMMY1_reg)=data)
#define  get_ISO_MISC_OFF_DUMMY1_reg                                             (*((volatile unsigned int*)ISO_MISC_OFF_DUMMY1_reg))
#define  ISO_MISC_OFF_DUMMY1_dummy1_shift                                        (0)
#define  ISO_MISC_OFF_DUMMY1_dummy1_mask                                         (0xFFFFFFFF)
#define  ISO_MISC_OFF_DUMMY1_dummy1(data)                                        (0xFFFFFFFF&(data))
#define  ISO_MISC_OFF_DUMMY1_get_dummy1(data)                                    (0xFFFFFFFF&(data))

#define  ISO_MISC_OFF_DUMMY2                                                     0x1806210C
#define  ISO_MISC_OFF_DUMMY2_reg_addr                                            "0xB806210C"
#define  ISO_MISC_OFF_DUMMY2_reg                                                 0xB806210C
#define  ISO_MISC_OFF_DUMMY2_inst_addr                                           "0x0003"
#define  set_ISO_MISC_OFF_DUMMY2_reg(data)                                       (*((volatile unsigned int*)ISO_MISC_OFF_DUMMY2_reg)=data)
#define  get_ISO_MISC_OFF_DUMMY2_reg                                             (*((volatile unsigned int*)ISO_MISC_OFF_DUMMY2_reg))
#define  ISO_MISC_OFF_DUMMY2_dummy2_shift                                        (0)
#define  ISO_MISC_OFF_DUMMY2_dummy2_mask                                         (0xFFFFFFFF)
#define  ISO_MISC_OFF_DUMMY2_dummy2(data)                                        (0xFFFFFFFF&(data))
#define  ISO_MISC_OFF_DUMMY2_get_dummy2(data)                                    (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ISO_MISC_OFF register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:16;
        RBus_UInt32  res5:1;
        RBus_UInt32  wdog_ov_int:1;
        RBus_UInt32  irda1_int:1;
        RBus_UInt32  ur0_int:1;
        RBus_UInt32  i2c0_int:1;
        RBus_UInt32  i2c5_int:1;
    };
}iso_misc_off_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  irdarxdetec:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  uart_od_mode_en:1;
        RBus_UInt32  res3:10;
        RBus_UInt32  dbg_sel:4;
    };
}iso_misc_off_system_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1:32;
    };
}iso_misc_off_dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy2:32;
    };
}iso_misc_off_dummy2_RBUS;

#else //apply LITTLE_ENDIAN

//======ISO_MISC_OFF register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2c5_int:1;
        RBus_UInt32  i2c0_int:1;
        RBus_UInt32  ur0_int:1;
        RBus_UInt32  irda1_int:1;
        RBus_UInt32  wdog_ov_int:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:8;
    };
}iso_misc_off_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sel:4;
        RBus_UInt32  res1:10;
        RBus_UInt32  uart_od_mode_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  irdarxdetec:1;
        RBus_UInt32  res3:15;
    };
}iso_misc_off_system_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1:32;
    };
}iso_misc_off_dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy2:32;
    };
}iso_misc_off_dummy2_RBUS;




#endif 


#endif 
