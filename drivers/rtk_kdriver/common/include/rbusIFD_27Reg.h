/**
* @file rbusIFD_27Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-2-16
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_REG_H_
#define _RBUS_REG_H_

#include "rbusTypes.h"



//  IFD_27 Register Address
#define  IFD_27M_MODULATION_LEVEL_VADDR                     	(0xb8032420)
#define  IFD_27M_VCLAMP_IN_MAX_SAT_VADDR                    	(0xb8032424)
#define  IFD_27M_VCLAMP_IN_MIN_SAT_VADDR                    	(0xb8032428)
#define  IFD_27M_INTERRUPT_MASK_EN_TWENTY_SEVEN_VADDR       	(0xb803242c)
#define  IFD_27M_SIMPLE_H_CNTL_VADDR                        	(0xb8032430)
#define  IFD_27M_SIMPLE_H_STATUS_VADDR                      	(0xb8032434)
#define  IFD_27M_FIFO_CRC27_RESULT_VADDR                    	(0xb8032440)
#define  IFD_27M_DMA_DATA_SEL_VADDR                         	(0xb803244c)
#define  IFD_27M_MOD_SEL_VADDR                              	(0xb8032480)
#define  IFD_27M_CLAMPING_SCALE_VADDR                       	(0xb803248c)
#define  IFD_27M_CLAMPING_THR_MAX_VADDR                     	(0xb8032490)
#define  IFD_27M_CLAMPING_THR_MIN_VADDR                     	(0xb8032494)
#define  IFD_27M_OFFSET_VADDR                               	(0xb8032498)
#define  IFD_27M_CLAMPING_THR_MIN_LIMIT_VADDR               	(0xb803249c)
#define  IFD_27M_WRONG_PC_VADDR                             	(0xb80324a0)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IFD_27 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  positive_level:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  negative_level:13;
    };
}modulation_level_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  vclamp_in_max_sat:13;
    };
}vclamp_in_max_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  vclamp_in_min_sat:13;
    };
}vclamp_in_min_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  vclamp_in_sat_int:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mask_vclamp_in_sat_en:1;
    };
}interrupt_mask_en_twenty_seven_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  simple_h_deb:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  simple_h_thd:13;
    };
}simple_h_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  simple_h_len_iir:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  simple_h_len:11;
    };
}simple_h_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fifo_crc27_result:16;
    };
}fifo_crc27_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  dma_data_sel:2;
        RBus_UInt32  res2:8;
    };
}dma_data_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mod_sel:1;
        RBus_UInt32  res2:16;
    };
}mod_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  clamp_offset_hold:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  clamping_reset:1;
        RBus_UInt32  clamping_scale:4;
    };
}clamping_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  clamping_thr_max:14;
    };
}clamping_thr_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  clamping_thr_min_auto:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  clamping_thr_min:14;
    };
}clamping_thr_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  offset_status:14;
    };
}offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  clamp_offset_min_limit_gap:14;
        RBus_UInt32  clamp_offset_min_limit_cnt:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  clamp_offset_min_limit_en:1;
    };
}clamping_thr_min_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  wrong_pc_th:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  wrong_pc_under_th:13;
        RBus_UInt32  res3:3;
        RBus_UInt32  wrong_if_pc_detect:1;
    };
}wrong_pc_RBUS;

#else //apply LITTLE_ENDIAN

//======IFD_27 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  negative_level:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  positive_level:13;
        RBus_UInt32  res2:3;
    };
}modulation_level_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vclamp_in_max_sat:13;
        RBus_UInt32  res1:19;
    };
}vclamp_in_max_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vclamp_in_min_sat:13;
        RBus_UInt32  res1:19;
    };
}vclamp_in_min_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_vclamp_in_sat_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  vclamp_in_sat_int:1;
        RBus_UInt32  res2:27;
    };
}interrupt_mask_en_twenty_seven_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  simple_h_thd:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  simple_h_deb:5;
        RBus_UInt32  res2:11;
    };
}simple_h_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  simple_h_len:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  simple_h_len_iir:11;
        RBus_UInt32  res2:9;
    };
}simple_h_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_crc27_result:16;
        RBus_UInt32  res1:16;
    };
}fifo_crc27_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  dma_data_sel:2;
        RBus_UInt32  res2:22;
    };
}dma_data_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  mod_sel:1;
        RBus_UInt32  res2:15;
    };
}mod_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clamping_scale:4;
        RBus_UInt32  clamping_reset:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  clamp_offset_hold:1;
        RBus_UInt32  res2:23;
    };
}clamping_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clamping_thr_max:14;
        RBus_UInt32  res1:18;
    };
}clamping_thr_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clamping_thr_min:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  clamping_thr_min_auto:14;
        RBus_UInt32  res2:2;
    };
}clamping_thr_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  offset_status:14;
        RBus_UInt32  res1:18;
    };
}offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clamp_offset_min_limit_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  clamp_offset_min_limit_cnt:4;
        RBus_UInt32  clamp_offset_min_limit_gap:14;
        RBus_UInt32  res2:10;
    };
}clamping_thr_min_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrong_if_pc_detect:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  wrong_pc_under_th:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  wrong_pc_th:8;
        RBus_UInt32  res3:4;
    };
}wrong_pc_RBUS;




#endif 


#endif 
