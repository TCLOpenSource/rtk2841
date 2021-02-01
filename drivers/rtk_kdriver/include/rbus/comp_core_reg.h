/**
* @file Mac5_DesignSpec-compdec_core
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COMP_CORE_REG_H_
#define _RBUS_COMP_CORE_REG_H_

#include "rbus_types.h"



//  COMP_CORE Register Address
#define  COMP_CORE_comp_core_set0                                                0x18027300
#define  COMP_CORE_comp_core_set0_reg_addr                                       "0xB8027300"
#define  COMP_CORE_comp_core_set0_reg                                            0xB8027300
#define  COMP_CORE_comp_core_set0_inst_addr                                      "0x0000"
#define  set_COMP_CORE_comp_core_set0_reg(data)                                  (*((volatile unsigned int*)COMP_CORE_comp_core_set0_reg)=data)
#define  get_COMP_CORE_comp_core_set0_reg                                        (*((volatile unsigned int*)COMP_CORE_comp_core_set0_reg))
#define  COMP_CORE_comp_core_set0_lossy_en_shift                                 (31)
#define  COMP_CORE_comp_core_set0_comp_bypass_en_shift                           (30)
#define  COMP_CORE_comp_core_set0_qp_decision_method_shift                       (23)
#define  COMP_CORE_comp_core_set0_budget_bytes_shift                             (12)
#define  COMP_CORE_comp_core_set0_comp_bpp_shift                                 (0)
#define  COMP_CORE_comp_core_set0_lossy_en_mask                                  (0x80000000)
#define  COMP_CORE_comp_core_set0_comp_bypass_en_mask                            (0x40000000)
#define  COMP_CORE_comp_core_set0_qp_decision_method_mask                        (0x00800000)
#define  COMP_CORE_comp_core_set0_budget_bytes_mask                              (0x0007F000)
#define  COMP_CORE_comp_core_set0_comp_bpp_mask                                  (0x00000003)
#define  COMP_CORE_comp_core_set0_lossy_en(data)                                 (0x80000000&((data)<<31))
#define  COMP_CORE_comp_core_set0_comp_bypass_en(data)                           (0x40000000&((data)<<30))
#define  COMP_CORE_comp_core_set0_qp_decision_method(data)                       (0x00800000&((data)<<23))
#define  COMP_CORE_comp_core_set0_budget_bytes(data)                             (0x0007F000&((data)<<12))
#define  COMP_CORE_comp_core_set0_comp_bpp(data)                                 (0x00000003&(data))
#define  COMP_CORE_comp_core_set0_get_lossy_en(data)                             ((0x80000000&(data))>>31)
#define  COMP_CORE_comp_core_set0_get_comp_bypass_en(data)                       ((0x40000000&(data))>>30)
#define  COMP_CORE_comp_core_set0_get_qp_decision_method(data)                   ((0x00800000&(data))>>23)
#define  COMP_CORE_comp_core_set0_get_budget_bytes(data)                         ((0x0007F000&(data))>>12)
#define  COMP_CORE_comp_core_set0_get_comp_bpp(data)                             (0x00000003&(data))

#define  COMP_CORE_comp_core_set1                                                0x18027304
#define  COMP_CORE_comp_core_set1_reg_addr                                       "0xB8027304"
#define  COMP_CORE_comp_core_set1_reg                                            0xB8027304
#define  COMP_CORE_comp_core_set1_inst_addr                                      "0x0001"
#define  set_COMP_CORE_comp_core_set1_reg(data)                                  (*((volatile unsigned int*)COMP_CORE_comp_core_set1_reg)=data)
#define  get_COMP_CORE_comp_core_set1_reg                                        (*((volatile unsigned int*)COMP_CORE_comp_core_set1_reg))
#define  COMP_CORE_comp_core_set1_min_qp_y_shift                                 (10)
#define  COMP_CORE_comp_core_set1_min_qp_c_shift                                 (8)
#define  COMP_CORE_comp_core_set1_alternate_budget_shift                         (2)
#define  COMP_CORE_comp_core_set1_comp_bpp_shift                                 (0)
#define  COMP_CORE_comp_core_set1_min_qp_y_mask                                  (0x00000C00)
#define  COMP_CORE_comp_core_set1_min_qp_c_mask                                  (0x00000300)
#define  COMP_CORE_comp_core_set1_alternate_budget_mask                          (0x000000FC)
#define  COMP_CORE_comp_core_set1_comp_bpp_mask                                  (0x00000003)
#define  COMP_CORE_comp_core_set1_min_qp_y(data)                                 (0x00000C00&((data)<<10))
#define  COMP_CORE_comp_core_set1_min_qp_c(data)                                 (0x00000300&((data)<<8))
#define  COMP_CORE_comp_core_set1_alternate_budget(data)                         (0x000000FC&((data)<<2))
#define  COMP_CORE_comp_core_set1_comp_bpp(data)                                 (0x00000003&(data))
#define  COMP_CORE_comp_core_set1_get_min_qp_y(data)                             ((0x00000C00&(data))>>10)
#define  COMP_CORE_comp_core_set1_get_min_qp_c(data)                             ((0x00000300&(data))>>8)
#define  COMP_CORE_comp_core_set1_get_alternate_budget(data)                     ((0x000000FC&(data))>>2)
#define  COMP_CORE_comp_core_set1_get_comp_bpp(data)                             (0x00000003&(data))

#define  COMP_CORE_comp_core_status                                              0x18027308
#define  COMP_CORE_comp_core_status_reg_addr                                     "0xB8027308"
#define  COMP_CORE_comp_core_status_reg                                          0xB8027308
#define  COMP_CORE_comp_core_status_inst_addr                                    "0x0002"
#define  set_COMP_CORE_comp_core_status_reg(data)                                (*((volatile unsigned int*)COMP_CORE_comp_core_status_reg)=data)
#define  get_COMP_CORE_comp_core_status_reg                                      (*((volatile unsigned int*)COMP_CORE_comp_core_status_reg))
#define  COMP_CORE_comp_core_status_comp_core_irq_shift                          (31)
#define  COMP_CORE_comp_core_status_comp_core_errflag_clr_shift                  (8)
#define  COMP_CORE_comp_core_status_comp_core_flag2irq_en_shift                  (4)
#define  COMP_CORE_comp_core_status_comp_core_errflag_shift                      (0)
#define  COMP_CORE_comp_core_status_comp_core_irq_mask                           (0x80000000)
#define  COMP_CORE_comp_core_status_comp_core_errflag_clr_mask                   (0x00000F00)
#define  COMP_CORE_comp_core_status_comp_core_flag2irq_en_mask                   (0x000000F0)
#define  COMP_CORE_comp_core_status_comp_core_errflag_mask                       (0x0000000F)
#define  COMP_CORE_comp_core_status_comp_core_irq(data)                          (0x80000000&((data)<<31))
#define  COMP_CORE_comp_core_status_comp_core_errflag_clr(data)                  (0x00000F00&((data)<<8))
#define  COMP_CORE_comp_core_status_comp_core_flag2irq_en(data)                  (0x000000F0&((data)<<4))
#define  COMP_CORE_comp_core_status_comp_core_errflag(data)                      (0x0000000F&(data))
#define  COMP_CORE_comp_core_status_get_comp_core_irq(data)                      ((0x80000000&(data))>>31)
#define  COMP_CORE_comp_core_status_get_comp_core_errflag_clr(data)              ((0x00000F00&(data))>>8)
#define  COMP_CORE_comp_core_status_get_comp_core_flag2irq_en(data)              ((0x000000F0&(data))>>4)
#define  COMP_CORE_comp_core_status_get_comp_core_errflag(data)                  (0x0000000F&(data))

#define  COMP_CORE_decomp_core_set                                               0x18027400
#define  COMP_CORE_decomp_core_set_reg_addr                                      "0xB8027400"
#define  COMP_CORE_decomp_core_set_reg                                           0xB8027400
#define  COMP_CORE_decomp_core_set_inst_addr                                     "0x0003"
#define  set_COMP_CORE_decomp_core_set_reg(data)                                 (*((volatile unsigned int*)COMP_CORE_decomp_core_set_reg)=data)
#define  get_COMP_CORE_decomp_core_set_reg                                       (*((volatile unsigned int*)COMP_CORE_decomp_core_set_reg))
#define  COMP_CORE_decomp_core_set_lossy_en_shift                                (31)
#define  COMP_CORE_decomp_core_set_decomp_bypass_en_shift                        (30)
#define  COMP_CORE_decomp_core_set_decomp_bpp_shift                              (0)
#define  COMP_CORE_decomp_core_set_lossy_en_mask                                 (0x80000000)
#define  COMP_CORE_decomp_core_set_decomp_bypass_en_mask                         (0x40000000)
#define  COMP_CORE_decomp_core_set_decomp_bpp_mask                               (0x00000003)
#define  COMP_CORE_decomp_core_set_lossy_en(data)                                (0x80000000&((data)<<31))
#define  COMP_CORE_decomp_core_set_decomp_bypass_en(data)                        (0x40000000&((data)<<30))
#define  COMP_CORE_decomp_core_set_decomp_bpp(data)                              (0x00000003&(data))
#define  COMP_CORE_decomp_core_set_get_lossy_en(data)                            ((0x80000000&(data))>>31)
#define  COMP_CORE_decomp_core_set_get_decomp_bypass_en(data)                    ((0x40000000&(data))>>30)
#define  COMP_CORE_decomp_core_set_get_decomp_bpp(data)                          (0x00000003&(data))

#define  COMP_CORE_decomp_core_status                                            0x18027404
#define  COMP_CORE_decomp_core_status_reg_addr                                   "0xB8027404"
#define  COMP_CORE_decomp_core_status_reg                                        0xB8027404
#define  COMP_CORE_decomp_core_status_inst_addr                                  "0x0004"
#define  set_COMP_CORE_decomp_core_status_reg(data)                              (*((volatile unsigned int*)COMP_CORE_decomp_core_status_reg)=data)
#define  get_COMP_CORE_decomp_core_status_reg                                    (*((volatile unsigned int*)COMP_CORE_decomp_core_status_reg))
#define  COMP_CORE_decomp_core_status_decomp_core_irq_shift                      (31)
#define  COMP_CORE_decomp_core_status_decomp_core_errflag_clr_shift              (16)
#define  COMP_CORE_decomp_core_status_decomp_core_flag2irq_en_shift              (8)
#define  COMP_CORE_decomp_core_status_decomp_core_errflag_shift                  (0)
#define  COMP_CORE_decomp_core_status_decomp_core_irq_mask                       (0x80000000)
#define  COMP_CORE_decomp_core_status_decomp_core_errflag_clr_mask               (0x00FF0000)
#define  COMP_CORE_decomp_core_status_decomp_core_flag2irq_en_mask               (0x0000FF00)
#define  COMP_CORE_decomp_core_status_decomp_core_errflag_mask                   (0x000000FF)
#define  COMP_CORE_decomp_core_status_decomp_core_irq(data)                      (0x80000000&((data)<<31))
#define  COMP_CORE_decomp_core_status_decomp_core_errflag_clr(data)              (0x00FF0000&((data)<<16))
#define  COMP_CORE_decomp_core_status_decomp_core_flag2irq_en(data)              (0x0000FF00&((data)<<8))
#define  COMP_CORE_decomp_core_status_decomp_core_errflag(data)                  (0x000000FF&(data))
#define  COMP_CORE_decomp_core_status_get_decomp_core_irq(data)                  ((0x80000000&(data))>>31)
#define  COMP_CORE_decomp_core_status_get_decomp_core_errflag_clr(data)          ((0x00FF0000&(data))>>16)
#define  COMP_CORE_decomp_core_status_get_decomp_core_flag2irq_en(data)          ((0x0000FF00&(data))>>8)
#define  COMP_CORE_decomp_core_status_get_decomp_core_errflag(data)              (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COMP_CORE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lossy_en:1;
        RBus_UInt32  comp_bypass_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  qp_decision_method:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  budget_bytes:7;
        RBus_UInt32  res3:8;
        RBus_UInt32  res4:2;
        RBus_UInt32  comp_bpp:2;
    };
}comp_core_comp_core_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  min_qp_y:2;
        RBus_UInt32  min_qp_c:2;
        RBus_UInt32  alternate_budget:6;
        RBus_UInt32  comp_bpp:2;
    };
}comp_core_comp_core_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_core_irq:1;
        RBus_UInt32  res1:19;
        RBus_UInt32  comp_core_errflag_clr:4;
        RBus_UInt32  comp_core_flag2irq_en:4;
        RBus_UInt32  comp_core_errflag:4;
    };
}comp_core_comp_core_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lossy_en:1;
        RBus_UInt32  decomp_bypass_en:1;
        RBus_UInt32  res1:28;
        RBus_UInt32  decomp_bpp:2;
    };
}comp_core_decomp_core_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decomp_core_irq:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  decomp_core_errflag_clr:8;
        RBus_UInt32  decomp_core_flag2irq_en:8;
        RBus_UInt32  decomp_core_errflag:8;
    };
}comp_core_decomp_core_status_RBUS;

#else //apply LITTLE_ENDIAN

//======COMP_CORE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_bpp:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:8;
        RBus_UInt32  budget_bytes:7;
        RBus_UInt32  res3:4;
        RBus_UInt32  qp_decision_method:1;
        RBus_UInt32  res4:6;
        RBus_UInt32  comp_bypass_en:1;
        RBus_UInt32  lossy_en:1;
    };
}comp_core_comp_core_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_bpp:2;
        RBus_UInt32  alternate_budget:6;
        RBus_UInt32  min_qp_c:2;
        RBus_UInt32  min_qp_y:2;
        RBus_UInt32  res1:20;
    };
}comp_core_comp_core_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_core_errflag:4;
        RBus_UInt32  comp_core_flag2irq_en:4;
        RBus_UInt32  comp_core_errflag_clr:4;
        RBus_UInt32  res1:19;
        RBus_UInt32  comp_core_irq:1;
    };
}comp_core_comp_core_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decomp_bpp:2;
        RBus_UInt32  res1:28;
        RBus_UInt32  decomp_bypass_en:1;
        RBus_UInt32  lossy_en:1;
    };
}comp_core_decomp_core_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decomp_core_errflag:8;
        RBus_UInt32  decomp_core_flag2irq_en:8;
        RBus_UInt32  decomp_core_errflag_clr:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  decomp_core_irq:1;
    };
}comp_core_decomp_core_status_RBUS;




#endif 


#endif 
