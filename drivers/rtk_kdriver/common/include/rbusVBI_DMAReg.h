/**
* @file rbusVBI_DMAReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2013/6/17
* @version 802
* @ingroup model_rbus
*
*/

#ifndef _RBUS_VBI_DMA_REG_H_
#define _RBUS_VBI_DMA_REG_H_

#include "rbus/rbusTypes.h"




// VBI_DMA Register Address
#define VBI_DMA_DISP2TVEVBIDMA_CTRL_ADDR           (0x18019000)
#define VBI_DMA_DISP2TVEVBIDMA_START_ADDR          (0x18019004)
#define VBI_DMA_DISP2TVEVBIDMA_READ_WINDOW_ADDR    (0x18019008)
#define VBI_DMA_DISP2TVEVBIDMA_START_STATUS_ADDR   (0x1801900c)
#define VBI_DMA_DISP2TVEVBIDMA_FIFOSTATUS_ADDR     (0x18019010)
#define VBI_DMA_DISP2TVEVBIDMA_CTRL_2_ADDR         (0x18019020)
#define VBI_DMA_DISP2TVEVBIDMA_START_2_ADDR        (0x18019024)
#define VBI_DMA_DISP2TVEVBIDMA_READ_WINDOW_2_ADDR  (0x18019028)
#define VBI_DMA_DISP2TVEVBIDMA_START_STATUS_2_ADDR (0x1801902c)
#define VBI_DMA_DISP2TVEVBIDMA_FIFOSTATUS_2_ADDR   (0x18019030)
#define VBI_DMA_DISP2TVEVBIDMA_BIST_DVS_ADDR       (0x18019040)
#define VBI_DMA_DISP2TVEVBIDMA_BIST_MODE_ADDR      (0x18019044)
#define VBI_DMA_DISP2TVEVBIDMA_DRF_BIST_MODE_ADDR  (0x18019048)
#define VBI_DMA_DISP2TVEVBIDMA_DRF_TEST_RESUME_ADDR  (0x1801904c)
#define VBI_DMA_DISP2TVEVBIDMA_LS_CNTL_ADDR        (0x18019050)
#define VBI_DMA_DISP2TVEVBIDMA_BIST_DONE_ADDR      (0x18019054)
#define VBI_DMA_DISP2TVEVBIDMA_DRF_BIST_DONE_ADDR  (0x18019058)
#define VBI_DMA_DISP2TVEVBIDMA_BIST_FAIL_ADDR      (0x1801905c)
#define VBI_DMA_DISP2TVEVBIDMA_DRF_BIST_FAIL_ADDR  (0x18019060)
#define VBI_DMA_DISP2TVEVBIDMA_DRF_BIST_PAUSE_ADDR (0x18019064)
#define VBI_DMA_DISP2TVEVBIDMA_VLINE_ADDR          (0x18019070)

#define VBI_DMA_DISP2TVEVBIDMA_CTRL_VADDR          (0xb8019000)
#define VBI_DMA_DISP2TVEVBIDMA_START_VADDR         (0xb8019004)
#define VBI_DMA_DISP2TVEVBIDMA_READ_WINDOW_VADDR   (0xb8019008)
#define VBI_DMA_DISP2TVEVBIDMA_START_STATUS_VADDR  (0xb801900c)
#define VBI_DMA_DISP2TVEVBIDMA_FIFOSTATUS_VADDR    (0xb8019010)
#define VBI_DMA_DISP2TVEVBIDMA_CTRL_2_VADDR        (0xb8019020)
#define VBI_DMA_DISP2TVEVBIDMA_START_2_VADDR       (0xb8019024)
#define VBI_DMA_DISP2TVEVBIDMA_READ_WINDOW_2_VADDR (0xb8019028)
#define VBI_DMA_DISP2TVEVBIDMA_START_STATUS_2_VADDR  (0xb801902c)
#define VBI_DMA_DISP2TVEVBIDMA_FIFOSTATUS_2_VADDR  (0xb8019030)
#define VBI_DMA_DISP2TVEVBIDMA_BIST_DVS_VADDR      (0xb8019040)
#define VBI_DMA_DISP2TVEVBIDMA_BIST_MODE_VADDR     (0xb8019044)
#define VBI_DMA_DISP2TVEVBIDMA_DRF_BIST_MODE_VADDR (0xb8019048)
#define VBI_DMA_DISP2TVEVBIDMA_DRF_TEST_RESUME_VADDR  (0xb801904c)
#define VBI_DMA_DISP2TVEVBIDMA_LS_CNTL_VADDR       (0xb8019050)
#define VBI_DMA_DISP2TVEVBIDMA_BIST_DONE_VADDR     (0xb8019054)
#define VBI_DMA_DISP2TVEVBIDMA_DRF_BIST_DONE_VADDR (0xb8019058)
#define VBI_DMA_DISP2TVEVBIDMA_BIST_FAIL_VADDR     (0xb801905c)
#define VBI_DMA_DISP2TVEVBIDMA_DRF_BIST_FAIL_VADDR (0xb8019060)
#define VBI_DMA_DISP2TVEVBIDMA_DRF_BIST_PAUSE_VADDR  (0xb8019064)
#define VBI_DMA_DISP2TVEVBIDMA_VLINE_VADDR         (0xb8019070)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======VBI_DMA register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  tve_vbidma_output_4byte_swap_1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tve_vbidma_endian_1:1;
        RBus_UInt32  tve_vbidma_buf_num_1:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  tve_vbidma_fetch_num_1:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  tve_vbidma_total_line_1:1;
    };
}DISP2TVEVBIDMA_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_edge_trig_auto_vs_1:1;
        RBus_UInt32  tve_vbidma_edge_trig_auto_window_1:1;
        RBus_UInt32  tve_vbidma_edge_trig_1:1;
        RBus_UInt32  tve_vbidma_start_addr_1:29;
    };
}DISP2TVEVBIDMA_START_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reset_error_1:1;
        RBus_UInt32  dummy_1:2;
        RBus_UInt32  tve_vbi_read_start_1:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vbi_read_end_1:13;
    };
}DISP2TVEVBIDMA_READ_WINDOW_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_error_1:1;
        RBus_UInt32  bandwidth_error_1:1;
        RBus_UInt32  error_dummy_1:1;
        RBus_UInt32  tve_vbidma_start_addr_now_1:29;
    };
}DISP2TVEVBIDMA_START_STATUS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vbidma_fifo_full_int_1:1;
        RBus_UInt32  vbidma_fifo_empty_int_1:1;
        RBus_UInt32  vbidma_fifo_full_1:1;
        RBus_UInt32  vbidma_fifo_empty_1:1;
        RBus_UInt32  res2:4;
    };
}DISP2TVEVBIDMA_FIFOSTATUS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  tve_vbidma_output_4byte_swap_2:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tve_vbidma_endian_2:1;
        RBus_UInt32  tve_vbidma_buf_num_2:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  tve_vbidma_fetch_num_2:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  tve_vbidma_total_line_2:1;
    };
}DISP2TVEVBIDMA_CTRL_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_edge_trig_auto_vs_2:1;
        RBus_UInt32  tve_vbidma_edge_trig_auto_window_2:1;
        RBus_UInt32  tve_vbidma_edge_trig_2:1;
        RBus_UInt32  tve_vbidma_start_addr_2:29;
    };
}DISP2TVEVBIDMA_START_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reset_error_2:1;
        RBus_UInt32  dummy_2:2;
        RBus_UInt32  tve_vbi_read_start_2:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vbi_read_end_2:13;
    };
}DISP2TVEVBIDMA_READ_WINDOW_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_error_2:1;
        RBus_UInt32  bandwidth_error_2:1;
        RBus_UInt32  error_dummy_2:1;
        RBus_UInt32  tve_vbidma_start_addr_now_2:29;
    };
}DISP2TVEVBIDMA_START_STATUS_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vbidma_fifo_full_int_2:1;
        RBus_UInt32  vbidma_fifo_empty_int_2:1;
        RBus_UInt32  vbidma_fifo_full_2:1;
        RBus_UInt32  vbidma_fifo_empty_2:1;
        RBus_UInt32  res2:4;
    };
}DISP2TVEVBIDMA_FIFOSTATUS_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  mbist_tve_dvse_2:1;
        RBus_UInt32  mbist_tve_dvs_2:4;
        RBus_UInt32  mbist_tve_dvse_1:1;
        RBus_UInt32  mbist_tve_dvs_1:4;
    };
}DISP2TVEVBIDMA_BIST_DVS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bist_mode_vbidma_1:1;
        RBus_UInt32  bist_mode_vbidma_2:1;
    };
}DISP2TVEVBIDMA_BIST_MODE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_bist_mode_vbidma_1:1;
        RBus_UInt32  drf_bist_mode_vbidma_2:1;
    };
}DISP2TVEVBIDMA_DRF_BIST_MODE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_test_resume_vbidma_1:1;
        RBus_UInt32  drf_test_resume_vbidma_2:1;
    };
}DISP2TVEVBIDMA_DRF_TEST_RESUME_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  mbist_ls_cntl_1:1;
        RBus_UInt32  mbist_ls_cntl_2:1;
    };
}DISP2TVEVBIDMA_LS_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bist_done_vbidma_1:1;
        RBus_UInt32  bist_done_vbidma_2:1;
    };
}DISP2TVEVBIDMA_BIST_DONE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_bist_done_vbidma_1:1;
        RBus_UInt32  drf_bist_done_vbidma_2:1;
    };
}DISP2TVEVBIDMA_DRF_BIST_DONE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bist_fail_vbidma_1:1;
        RBus_UInt32  bist_fail_vbidma_2:1;
    };
}DISP2TVEVBIDMA_BIST_FAIL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_bist_fail_vbidma_1:1;
        RBus_UInt32  drf_bist_fail_vbidma_2:1;
    };
}DISP2TVEVBIDMA_DRF_BIST_FAIL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_start_pause_vbidma_1:1;
        RBus_UInt32  drf_start_pause_vbidma_2:1;
    };
}DISP2TVEVBIDMA_DRF_BIST_PAUSE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vline_1:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  vline_2:13;
    };
}DISP2TVEVBIDMA_VLINE_RBUS;





#else //apply LITTLE_ENDIAN


//======VBI_DMA register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_total_line_1:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  tve_vbidma_fetch_num_1:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  tve_vbidma_buf_num_1:4;
        RBus_UInt32  tve_vbidma_endian_1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tve_vbidma_output_4byte_swap_1:1;
        RBus_UInt32  res1:15;
    };
}DISP2TVEVBIDMA_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_start_addr_1:29;
        RBus_UInt32  tve_vbidma_edge_trig_1:1;
        RBus_UInt32  tve_vbidma_edge_trig_auto_window_1:1;
        RBus_UInt32  tve_vbidma_edge_trig_auto_vs_1:1;
    };
}DISP2TVEVBIDMA_START_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbi_read_end_1:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vbi_read_start_1:13;
        RBus_UInt32  dummy_1:2;
        RBus_UInt32  reset_error_1:1;
    };
}DISP2TVEVBIDMA_READ_WINDOW_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_start_addr_now_1:29;
        RBus_UInt32  error_dummy_1:1;
        RBus_UInt32  bandwidth_error_1:1;
        RBus_UInt32  req_error_1:1;
    };
}DISP2TVEVBIDMA_START_STATUS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:4;
        RBus_UInt32  vbidma_fifo_empty_1:1;
        RBus_UInt32  vbidma_fifo_full_1:1;
        RBus_UInt32  vbidma_fifo_empty_int_1:1;
        RBus_UInt32  vbidma_fifo_full_int_1:1;
        RBus_UInt32  res1:24;
    };
}DISP2TVEVBIDMA_FIFOSTATUS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_total_line_2:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  tve_vbidma_fetch_num_2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  tve_vbidma_buf_num_2:4;
        RBus_UInt32  tve_vbidma_endian_2:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tve_vbidma_output_4byte_swap_2:1;
        RBus_UInt32  res1:15;
    };
}DISP2TVEVBIDMA_CTRL_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_start_addr_2:29;
        RBus_UInt32  tve_vbidma_edge_trig_2:1;
        RBus_UInt32  tve_vbidma_edge_trig_auto_window_2:1;
        RBus_UInt32  tve_vbidma_edge_trig_auto_vs_2:1;
    };
}DISP2TVEVBIDMA_START_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbi_read_end_2:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vbi_read_start_2:13;
        RBus_UInt32  dummy_2:2;
        RBus_UInt32  reset_error_2:1;
    };
}DISP2TVEVBIDMA_READ_WINDOW_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_start_addr_now_2:29;
        RBus_UInt32  error_dummy_2:1;
        RBus_UInt32  bandwidth_error_2:1;
        RBus_UInt32  req_error_2:1;
    };
}DISP2TVEVBIDMA_START_STATUS_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:4;
        RBus_UInt32  vbidma_fifo_empty_2:1;
        RBus_UInt32  vbidma_fifo_full_2:1;
        RBus_UInt32  vbidma_fifo_empty_int_2:1;
        RBus_UInt32  vbidma_fifo_full_int_2:1;
        RBus_UInt32  res1:24;
    };
}DISP2TVEVBIDMA_FIFOSTATUS_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_tve_dvs_1:4;
        RBus_UInt32  mbist_tve_dvse_1:1;
        RBus_UInt32  mbist_tve_dvs_2:4;
        RBus_UInt32  mbist_tve_dvse_2:1;
        RBus_UInt32  res1:22;
    };
}DISP2TVEVBIDMA_BIST_DVS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mode_vbidma_2:1;
        RBus_UInt32  bist_mode_vbidma_1:1;
        RBus_UInt32  res1:30;
    };
}DISP2TVEVBIDMA_BIST_MODE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_mode_vbidma_2:1;
        RBus_UInt32  drf_bist_mode_vbidma_1:1;
        RBus_UInt32  res1:30;
    };
}DISP2TVEVBIDMA_DRF_BIST_MODE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_test_resume_vbidma_2:1;
        RBus_UInt32  drf_test_resume_vbidma_1:1;
        RBus_UInt32  res1:30;
    };
}DISP2TVEVBIDMA_DRF_TEST_RESUME_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_ls_cntl_2:1;
        RBus_UInt32  mbist_ls_cntl_1:1;
        RBus_UInt32  res1:30;
    };
}DISP2TVEVBIDMA_LS_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_done_vbidma_2:1;
        RBus_UInt32  bist_done_vbidma_1:1;
        RBus_UInt32  res1:30;
    };
}DISP2TVEVBIDMA_BIST_DONE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_done_vbidma_2:1;
        RBus_UInt32  drf_bist_done_vbidma_1:1;
        RBus_UInt32  res1:30;
    };
}DISP2TVEVBIDMA_DRF_BIST_DONE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_vbidma_2:1;
        RBus_UInt32  bist_fail_vbidma_1:1;
        RBus_UInt32  res1:30;
    };
}DISP2TVEVBIDMA_BIST_FAIL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_vbidma_2:1;
        RBus_UInt32  drf_bist_fail_vbidma_1:1;
        RBus_UInt32  res1:30;
    };
}DISP2TVEVBIDMA_DRF_BIST_FAIL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_start_pause_vbidma_2:1;
        RBus_UInt32  drf_start_pause_vbidma_1:1;
        RBus_UInt32  res1:30;
    };
}DISP2TVEVBIDMA_DRF_BIST_PAUSE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vline_2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  vline_1:13;
        RBus_UInt32  res1:3;
    };
}DISP2TVEVBIDMA_VLINE_RBUS;


#endif







#endif //_RBUS_VBI_DMA_REG_H_

