/**
* @file rbusWdogReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/12/21
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_WDOG_REG_H_
#define _RBUS_WDOG_REG_H_

#include "rbus_types.h"



//  WDOG Register Address
#define  WDOG_MSK_ISR                                                            0x18062200
#define  WDOG_MSK_ISR_reg_addr                                                   "0xB8062200"
#define  WDOG_MSK_ISR_reg                                                        0xB8062200
#define  WDOG_MSK_ISR_inst_addr                                                  "0x0000"
#define  set_WDOG_MSK_ISR_reg(data)                                              (*((volatile unsigned int*)WDOG_MSK_ISR_reg)=data)
#define  get_WDOG_MSK_ISR_reg                                                    (*((volatile unsigned int*)WDOG_MSK_ISR_reg))
#define  WDOG_MSK_ISR_wdog_int_shift                                             (8)
#define  WDOG_MSK_ISR_wdog_int_mask                                              (0x00000100)
#define  WDOG_MSK_ISR_wdog_int(data)                                             (0x00000100&((data)<<8))
#define  WDOG_MSK_ISR_get_wdog_int(data)                                         ((0x00000100&(data))>>8)

#define  WDOG_TCWCR                                                              0x18062204
#define  WDOG_TCWCR_reg_addr                                                     "0xB8062204"
#define  WDOG_TCWCR_reg                                                          0xB8062204
#define  WDOG_TCWCR_inst_addr                                                    "0x0001"
#define  set_WDOG_TCWCR_reg(data)                                                (*((volatile unsigned int*)WDOG_TCWCR_reg)=data)
#define  get_WDOG_TCWCR_reg                                                      (*((volatile unsigned int*)WDOG_TCWCR_reg))
#define  WDOG_TCWCR_im_wdog_rst_shift                                            (31)
#define  WDOG_TCWCR_wdie_shift                                                   (16)
#define  WDOG_TCWCR_nmic_shift                                                   (12)
#define  WDOG_TCWCR_wdc_shift                                                    (8)
#define  WDOG_TCWCR_wden_shift                                                   (0)
#define  WDOG_TCWCR_im_wdog_rst_mask                                             (0x80000000)
#define  WDOG_TCWCR_wdie_mask                                                    (0x00010000)
#define  WDOG_TCWCR_nmic_mask                                                    (0x0000F000)
#define  WDOG_TCWCR_wdc_mask                                                     (0x00000F00)
#define  WDOG_TCWCR_wden_mask                                                    (0x000000FF)
#define  WDOG_TCWCR_im_wdog_rst(data)                                            (0x80000000&((data)<<31))
#define  WDOG_TCWCR_wdie(data)                                                   (0x00010000&((data)<<16))
#define  WDOG_TCWCR_nmic(data)                                                   (0x0000F000&((data)<<12))
#define  WDOG_TCWCR_wdc(data)                                                    (0x00000F00&((data)<<8))
#define  WDOG_TCWCR_wden(data)                                                   (0x000000FF&(data))
#define  WDOG_TCWCR_get_im_wdog_rst(data)                                        ((0x80000000&(data))>>31)
#define  WDOG_TCWCR_get_wdie(data)                                               ((0x00010000&(data))>>16)
#define  WDOG_TCWCR_get_nmic(data)                                               ((0x0000F000&(data))>>12)
#define  WDOG_TCWCR_get_wdc(data)                                                ((0x00000F00&(data))>>8)
#define  WDOG_TCWCR_get_wden(data)                                               (0x000000FF&(data))

#define  WDOG_TCWTR                                                              0x18062208
#define  WDOG_TCWTR_reg_addr                                                     "0xB8062208"
#define  WDOG_TCWTR_reg                                                          0xB8062208
#define  WDOG_TCWTR_inst_addr                                                    "0x0002"
#define  set_WDOG_TCWTR_reg(data)                                                (*((volatile unsigned int*)WDOG_TCWTR_reg)=data)
#define  get_WDOG_TCWTR_reg                                                      (*((volatile unsigned int*)WDOG_TCWTR_reg))
#define  WDOG_TCWTR_wdclr_shift                                                  (0)
#define  WDOG_TCWTR_wdclr_mask                                                   (0x00000001)
#define  WDOG_TCWTR_wdclr(data)                                                  (0x00000001&(data))
#define  WDOG_TCWTR_get_wdclr(data)                                              (0x00000001&(data))

#define  WDOG_TCWNMI                                                             0x1806220C
#define  WDOG_TCWNMI_reg_addr                                                    "0xB806220C"
#define  WDOG_TCWNMI_reg                                                         0xB806220C
#define  WDOG_TCWNMI_inst_addr                                                   "0x0003"
#define  set_WDOG_TCWNMI_reg(data)                                               (*((volatile unsigned int*)WDOG_TCWNMI_reg)=data)
#define  get_WDOG_TCWNMI_reg                                                     (*((volatile unsigned int*)WDOG_TCWNMI_reg))
#define  WDOG_TCWNMI_sel_shift                                                   (0)
#define  WDOG_TCWNMI_sel_mask                                                    (0xFFFFFFFF)
#define  WDOG_TCWNMI_sel(data)                                                   (0xFFFFFFFF&(data))
#define  WDOG_TCWNMI_get_sel(data)                                               (0xFFFFFFFF&(data))

#define  WDOG_TCWOV                                                              0x18062210
#define  WDOG_TCWOV_reg_addr                                                     "0xB8062210"
#define  WDOG_TCWOV_reg                                                          0xB8062210
#define  WDOG_TCWOV_inst_addr                                                    "0x0004"
#define  set_WDOG_TCWOV_reg(data)                                                (*((volatile unsigned int*)WDOG_TCWOV_reg)=data)
#define  get_WDOG_TCWOV_reg                                                      (*((volatile unsigned int*)WDOG_TCWOV_reg))
#define  WDOG_TCWOV_sel_shift                                                    (0)
#define  WDOG_TCWOV_sel_mask                                                     (0xFFFFFFFF)
#define  WDOG_TCWOV_sel(data)                                                    (0xFFFFFFFF&(data))
#define  WDOG_TCWOV_get_sel(data)                                                (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======WDOG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  wdog_int:1;
        RBus_UInt32  res2:8;
    };
}wdog_msk_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  im_wdog_rst:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  wdie:1;
        RBus_UInt32  nmic:4;
        RBus_UInt32  wdc:4;
        RBus_UInt32  wden:8;
    };
}wdog_tcwcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  wdclr:1;
    };
}wdog_tcwtr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel:32;
    };
}wdog_tcwnmi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel:32;
    };
}wdog_tcwov_RBUS;

#else //apply LITTLE_ENDIAN

//======WDOG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  wdog_int:1;
        RBus_UInt32  res2:23;
    };
}wdog_msk_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wden:8;
        RBus_UInt32  wdc:4;
        RBus_UInt32  nmic:4;
        RBus_UInt32  wdie:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  im_wdog_rst:1;
    };
}wdog_tcwcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdclr:1;
        RBus_UInt32  res1:31;
    };
}wdog_tcwtr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel:32;
    };
}wdog_tcwnmi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel:32;
    };
}wdog_tcwov_RBUS;




#endif 


#endif 
