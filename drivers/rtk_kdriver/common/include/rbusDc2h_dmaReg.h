/**
* @file rbusDc2h_dmaReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2014-6-9
* @version 802
* @ingroup model_rbus
*
*/

#ifndef _RBUS_DC2H_DMA_REG_H_
#define _RBUS_DC2H_DMA_REG_H_

#include "rbus/rbusTypes.h"




// DC2H_DMA Register Address

#define DC2H_DMA_DC2H_SEQ_MODE_CTRL1_VADDR         (0xb8029d80)
#define DC2H_DMA_DC2H_SEQ_MODE_CTRL2_VADDR         (0xb8029d84)
#define DC2H_DMA_DC2H_CAP_CTL0_VADDR               (0xb8029d88)
#define DC2H_DMA_DC2H_CAP_CTL1_VADDR               (0xb8029d8c)
#define DC2H_DMA_DC2H_CAP_BOUNDARYADDR1_VADDR      (0xb8029d90)
#define DC2H_DMA_DC2H_CAP_BOUNDARYADDR2_VADDR      (0xb8029d94)
#define DC2H_DMA_DC2H_CAP_L1_START_VADDR           (0xb8029d98)
#define DC2H_DMA_DC2H_CAP_L2_START_VADDR           (0xb8029d9c)
#define DC2H_DMA_DC2H_CAP_L3_START_VADDR           (0xb8029da0)
#define DC2H_DMA_DC2H_CAP_L1_START_DB_VADDR        (0xb8029da4)
#define DC2H_DMA_DC2H_CAP_STATUS_VADDR             (0xb8029da8)
#define DC2H_DMA_DC2H_CAP_CRC_CTRL_VADDR           (0xb8029dac)
#define DC2H_DMA_DC2H_CRC_RESULT_VADDR             (0xb8029db0)
#define DC2H_DMA_DC2H_SEQ_INTERRUPT_ENABLE_VADDR   (0xb8029db4)
#define DC2H_DMA_DC2H_SEQ_BYTE_CHANNEL_SWAP_VADDR  (0xb8029db8)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======DC2H_DMA register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  argb_dummy_data:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  argb_swap:1;
        RBus_UInt32  rgb_to_argb_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  cap_en:1;
    };
}dc2h_seq_mode_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact:16;
        RBus_UInt32  res1:1;
        RBus_UInt32  hact:15;
    };
}dc2h_seq_mode_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  triple_buf_en:1;
        RBus_UInt32  cap_block_fw:2;
        RBus_UInt32  set_block_sel:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  vs_fall_rst_en:1;
        RBus_UInt32  auto_block_sel_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  bit_sel:1;
        RBus_UInt32  pixel_encoding:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  cap_write_len:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  cap_write_rem:7;
    };
}dc2h_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  cap_water_lv:7;
        RBus_UInt32  cap_write_num:8;
    };
}dc2h_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_mem_up_limit:29;
        RBus_UInt32  res1:3;
    };
}dc2h_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_mem_low_limit:29;
        RBus_UInt32  res1:3;
    };
}dc2h_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l1_start:29;
        RBus_UInt32  res1:3;
    };
}dc2h_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l2_start:29;
        RBus_UInt32  res1:3;
    };
}dc2h_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l3_start:29;
        RBus_UInt32  res1:3;
    };
}dc2h_cap_l3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l1_start_db:29;
        RBus_UInt32  res1:3;
    };
}dc2h_cap_l1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  cap_block_2:2;
        RBus_UInt32  cap_over_size:1;
        RBus_UInt32  cap_under_size:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vs_rising_occur:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  cap_block:1;
        RBus_UInt32  cap_field:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_ddr_over_range:1;
    };
}dc2h_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  l_crc_conti:1;
        RBus_UInt32  l_crc_start:1;
    };
}dc2h_cap_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc2h_seq_crc_result:32;
    };
}dc2h_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  mem_err_ie:1;
        RBus_UInt32  fifo_err_ie:1;
        RBus_UInt32  vs_rising_ie:1;
    };
}dc2h_seq_interrupt_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dma_channel_swap:3;
        RBus_UInt32  dma_8byte_swap:1;
        RBus_UInt32  dma_4byte_swap:1;
        RBus_UInt32  dma_2byte_swap:1;
        RBus_UInt32  dma_1byte_swap:1;
    };
}dc2h_seq_byte_channel_swap_RBUS;





#else //apply LITTLE_ENDIAN


//======DC2H_DMA register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  rgb_to_argb_en:1;
        RBus_UInt32  argb_swap:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  argb_dummy_data:8;
        RBus_UInt32  res1:16;
    };
}dc2h_seq_mode_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hact:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  vact:16;
    };
}dc2h_seq_mode_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_rem:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  cap_write_len:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  pixel_encoding:2;
        RBus_UInt32  bit_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  auto_block_sel_en:1;
        RBus_UInt32  vs_fall_rst_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  set_block_sel:1;
        RBus_UInt32  cap_block_fw:2;
        RBus_UInt32  triple_buf_en:1;
    };
}dc2h_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_num:8;
        RBus_UInt32  cap_water_lv:7;
        RBus_UInt32  res1:17;
    };
}dc2h_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_mem_up_limit:29;
    };
}dc2h_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_mem_low_limit:29;
    };
}dc2h_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l1_start:29;
    };
}dc2h_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l2_start:29;
    };
}dc2h_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l3_start:29;
    };
}dc2h_cap_l3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l1_start_db:29;
    };
}dc2h_cap_l1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_ddr_over_range:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  cap_field:1;
        RBus_UInt32  cap_block:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  vs_rising_occur:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cap_under_size:1;
        RBus_UInt32  cap_over_size:1;
        RBus_UInt32  cap_block_2:2;
        RBus_UInt32  res1:18;
    };
}dc2h_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_start:1;
        RBus_UInt32  l_crc_conti:1;
        RBus_UInt32  res1:30;
    };
}dc2h_cap_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc2h_seq_crc_result:32;
    };
}dc2h_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vs_rising_ie:1;
        RBus_UInt32  fifo_err_ie:1;
        RBus_UInt32  mem_err_ie:1;
        RBus_UInt32  res1:29;
    };
}dc2h_seq_interrupt_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_1byte_swap:1;
        RBus_UInt32  dma_2byte_swap:1;
        RBus_UInt32  dma_4byte_swap:1;
        RBus_UInt32  dma_8byte_swap:1;
        RBus_UInt32  dma_channel_swap:3;
        RBus_UInt32  res1:25;
    };
}dc2h_seq_byte_channel_swap_RBUS;


#endif







#endif //_RBUS_DC2H_DMA_REG_H_

