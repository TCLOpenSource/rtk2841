/**
* @file rbusIFD_49Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-2-16
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IFD_49M_REG_H_
#define _RBUS_IFD_49M_REG_H_

#include "rbusTypes.h"



//  IFD_49 Register Address


#define  IFD_49M_DEBUG_MODE2_VADDR                          	(0xb8032544)
#define  IFD_49M_CRC_CTRL_REGISTER_VADDR                    	(0xb8032550)
#define  IFD_49M_CRC1_RESULT_VADDR                          	(0xb8032554)
#define  IFD_49M_FIFO_CRC49_RESULT_VADDR                    	(0xb8032558)
#define  IFD_49M_AUDIO_BP_SEL_VADDR                         	(0xb80325c0)
#define  IFD_49M_AUDIO_GAIN_MANU_VADDR                      	(0xb80325c4)
#define  IFD_49M_AUDIO_GAIN_STATUS_VADDR                    	(0xb80325c8)
#define  IFD_49M_AUDIODN_FIFO_VADDR                         	(0xb80325d0)
#define  IFD_49M_AUDIODBG_FIFO_VADDR                        	(0xb80325d4)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IFD_49 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  debug_mode2_en:1;
        RBus_UInt32  debug_mode2:7;
    };
}debug_mode2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  crc1_en:1;
        RBus_UInt32  res2:7;
    };
}crc1_ctrl_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  crc1_result:16;
    };
}crc1_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fifo_crc49_result:16;
    };
}fifo_crc49_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  output_bpf_input_div2:2;
        RBus_UInt32  audio_bp_sel:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  audio_upsample_lp_sel:2;
    };
}audio_bp_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  aagc_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  audio_gain_manual:9;
    };
}audio_gain_manu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  audio_gain_status:9;
    };
}audio_gain_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  audiodn_fifo_clr:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  audiodn_fifo_full:1;
        RBus_UInt32  audiodn_fifo_empty:1;
    };
}audiodn_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  audiodbg_fifo_clr:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  audiodbg_fifo_full:1;
        RBus_UInt32  audiodbg_fifo_empty:1;
    };
}audiodbg_fifo_RBUS;

#else //apply LITTLE_ENDIAN

//======IFD_49 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode2:7;
        RBus_UInt32  debug_mode2_en:1;
        RBus_UInt32  res1:24;
    };
}debug_mode2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  crc1_en:1;
        RBus_UInt32  res2:24;
    };
}crc1_ctrl_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc1_result:16;
        RBus_UInt32  res1:16;
    };
}crc1_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_crc49_result:16;
        RBus_UInt32  res1:16;
    };
}fifo_crc49_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_upsample_lp_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  audio_bp_sel:8;
        RBus_UInt32  output_bpf_input_div2:2;
        RBus_UInt32  res2:18;
    };
}audio_bp_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_gain_manual:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  aagc_en:1;
        RBus_UInt32  res2:19;
    };
}audio_gain_manu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_gain_status:9;
        RBus_UInt32  res1:23;
    };
}audio_gain_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audiodn_fifo_empty:1;
        RBus_UInt32  audiodn_fifo_full:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  audiodn_fifo_clr:1;
        RBus_UInt32  res2:27;
    };
}audiodn_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audiodbg_fifo_empty:1;
        RBus_UInt32  audiodbg_fifo_full:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  audiodbg_fifo_clr:1;
        RBus_UInt32  res2:27;
    };
}audiodbg_fifo_RBUS;




#endif 


#endif 
