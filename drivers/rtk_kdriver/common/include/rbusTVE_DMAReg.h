/**
* @file rbusTVE_DMAReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014-8-4
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_TVE_DMA_REG_H_
#define _RBUS_TVE_DMA_REG_H_

#include "rbusTypes.h"



//  TVE_DMA Register Address



#define  TVE_DMA_TVE_VDDMA_CTRL_VADDR                       	(0xb801f400)
#define  TVE_DMA_TVE_VDDMA_VADDR                            	(0xb801f404)
#define  TVE_DMA_TVEVDDMA_LINESTEP_VADDR                    	(0xb801f408)
#define  TVE_DMA_TVEVDDMA_SATRT0_VADDR                      	(0xb801f410)
#define  TVE_DMA_TVEVDDMA_SATRT1_VADDR                      	(0xb801f414)
#define  TVE_DMA_TVEVDDMA_SATRT2_VADDR                      	(0xb801f418)
#define  TVE_DMA_TVEVDDMA_SATRT3_VADDR                      	(0xb801f41c)
#define  TVE_DMA_TVEVBIDMA_CTRL_VADDR                       	(0xb801f420)
#define  TVE_DMA_TVEVBIDMA_START_VADDR                      	(0xb801f424)
#define  TVE_DMA_TVEVBIDMA_READ_WINDOW_VADDR                	(0xb801f428)
#define  TVE_DMA_TVEVBIDMA_START_STATUS_VADDR               	(0xb801f42c)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_VADDR                    	(0xb801f430)
#define  TVE_DMA_TVEDMA_BIST_DVS_VADDR                      	(0xb801f440)
#define  TVE_DMA_TVEDMA_BIST_MODE_VADDR                     	(0xb801f444)
#define  TVE_DMA_TVEDMA_DRF_BIST_MODE_VADDR                 	(0xb801f448)
#define  TVE_DMA_TVEDMA_DRF_TEST_RESUME_VADDR               	(0xb801f44c)
#define  TVE_DMA_TVEDMA_LS_CNTL_VADDR                       	(0xb801f450)
#define  TVE_DMA_TVEDMA_BIST_DONE_VADDR                     	(0xb801f454)
#define  TVE_DMA_TVEDMA_DRF_BIST_DONE_VADDR                 	(0xb801f458)
#define  TVE_DMA_TVEDMA_BIST_FAIL_VADDR                     	(0xb801f45c)
#define  TVE_DMA_TVEDMA_DRF_BIST_FAIL_VADDR                 	(0xb801f460)
#define  TVE_DMA_TVEDMA_DRF_BIST_PAUSE_VADDR                	(0xb801f464)
#define  TVE_DMA_TVECRC_VADDR                               	(0xb801f470)
#define  TVE_DMA_TVECRC_VALUE_VADDR                         	(0xb801f474)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======TVE_DMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  tve_vddma_output_4byte_swap:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tve_vddma_output_y_cr_swap:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  tve_vddma_output_seq_sel:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  tve_vddma_buf_ctrl:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  tve_vddma_buf_sel:1;
    };
}tve_dma_tve_vddma_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  tve_vddma_waterlvl:6;
        RBus_UInt32  tve_vddma_num:8;
        RBus_UInt32  tve_vddma_length:8;
        RBus_UInt32  tve_vddma_remain:8;
    };
}tve_dma_tve_vddma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vddma_line_step:29;
    };
}tve_dma_tvevddma_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vddma_start_addr0:29;
    };
}tve_dma_tvevddma_satrt0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vddma_start_addr1:29;
    };
}tve_dma_tvevddma_satrt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vddma_start_addr2:29;
    };
}tve_dma_tvevddma_satrt2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vddma_start_addr3:29;
    };
}tve_dma_tvevddma_satrt3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  tve_vbidma_output_4byte_swap:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tve_vbidma_endian:1;
        RBus_UInt32  tve_vbidma_buf_num:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  tve_vbidma_fetch_num:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  tve_vbidma_total_line:1;
    };
}tve_dma_tvevbidma_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  tve_vbidma_edge_trig:1;
        RBus_UInt32  tve_vbidma_start_addr:29;
    };
}tve_dma_tvevbidma_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tve_vbi_read_start:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  tve_vbi_read_end:11;
    };
}tve_dma_tvevbidma_read_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vbidma_start_addr_now:29;
    };
}tve_dma_tvevbidma_start_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vbidma_fifo_full_int:1;
        RBus_UInt32  vbidma_fifo_empty_int:1;
        RBus_UInt32  vbidma_fifo_full:1;
        RBus_UInt32  vbidma_fifo_empty:1;
        RBus_UInt32  vddma_fifo_full_int:1;
        RBus_UInt32  vddma_fifo_empty_int:1;
        RBus_UInt32  vddma_fifo_full:1;
        RBus_UInt32  vddma_fifo_empty:1;
    };
}tve_dma_tvedma_fifostatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  mbist_tve_dvse:1;
        RBus_UInt32  mbist_tve_dvs:4;
    };
}tve_dma_tvedma_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bist_mode_vbidma:1;
        RBus_UInt32  bist_mode_vddma:1;
    };
}tve_dma_tvedma_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_bist_mode_vbidma:1;
        RBus_UInt32  drf_bist_mode_vddma:1;
    };
}tve_dma_tvedma_drf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_test_resume_vbidma:1;
        RBus_UInt32  drf_test_resume_vddma:1;
    };
}tve_dma_tvedma_drf_test_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mbist_ls_cntl:1;
    };
}tve_dma_tvedma_ls_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bist_done_vbidma:1;
        RBus_UInt32  bist_done_vddma:1;
    };
}tve_dma_tvedma_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_bist_done_vbidma:1;
        RBus_UInt32  drf_bist_done_vddma:1;
    };
}tve_dma_tvedma_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bist_fail_vbidma:1;
        RBus_UInt32  bist_fail_vddma:1;
    };
}tve_dma_tvedma_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_bist_fail_vbidma:1;
        RBus_UInt32  drf_bist_fail_vddma:1;
    };
}tve_dma_tvedma_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_start_pause_vbidma:1;
        RBus_UInt32  drf_start_pause_vddma:1;
    };
}tve_dma_tvedma_drf_bist_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_en:1;
        RBus_UInt32  mv_go:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  crc_num_count:21;
    };
}tve_dma_tvecrc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  crc_value:16;
    };
}tve_dma_tvecrc_value_RBUS;

#else //apply LITTLE_ENDIAN

//======TVE_DMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_buf_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vddma_buf_ctrl:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tve_vddma_output_seq_sel:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  tve_vddma_output_y_cr_swap:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  tve_vddma_output_4byte_swap:1;
        RBus_UInt32  res5:15;
    };
}tve_dma_tve_vddma_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_remain:8;
        RBus_UInt32  tve_vddma_length:8;
        RBus_UInt32  tve_vddma_num:8;
        RBus_UInt32  tve_vddma_waterlvl:6;
        RBus_UInt32  res1:2;
    };
}tve_dma_tve_vddma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_line_step:29;
        RBus_UInt32  res1:3;
    };
}tve_dma_tvevddma_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_start_addr0:29;
        RBus_UInt32  res1:3;
    };
}tve_dma_tvevddma_satrt0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_start_addr1:29;
        RBus_UInt32  res1:3;
    };
}tve_dma_tvevddma_satrt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_start_addr2:29;
        RBus_UInt32  res1:3;
    };
}tve_dma_tvevddma_satrt2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_start_addr3:29;
        RBus_UInt32  res1:3;
    };
}tve_dma_tvevddma_satrt3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_total_line:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vbidma_fetch_num:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tve_vbidma_buf_num:4;
        RBus_UInt32  tve_vbidma_endian:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  tve_vbidma_output_4byte_swap:1;
        RBus_UInt32  res4:15;
    };
}tve_dma_tvevbidma_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_start_addr:29;
        RBus_UInt32  tve_vbidma_edge_trig:1;
        RBus_UInt32  res1:2;
    };
}tve_dma_tvevbidma_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbi_read_end:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  tve_vbi_read_start:11;
        RBus_UInt32  res2:9;
    };
}tve_dma_tvevbidma_read_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_start_addr_now:29;
        RBus_UInt32  res1:3;
    };
}tve_dma_tvevbidma_start_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vddma_fifo_empty:1;
        RBus_UInt32  vddma_fifo_full:1;
        RBus_UInt32  vddma_fifo_empty_int:1;
        RBus_UInt32  vddma_fifo_full_int:1;
        RBus_UInt32  vbidma_fifo_empty:1;
        RBus_UInt32  vbidma_fifo_full:1;
        RBus_UInt32  vbidma_fifo_empty_int:1;
        RBus_UInt32  vbidma_fifo_full_int:1;
        RBus_UInt32  res1:24;
    };
}tve_dma_tvedma_fifostatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_tve_dvs:4;
        RBus_UInt32  mbist_tve_dvse:1;
        RBus_UInt32  res1:27;
    };
}tve_dma_tvedma_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mode_vddma:1;
        RBus_UInt32  bist_mode_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_mode_vddma:1;
        RBus_UInt32  drf_bist_mode_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_drf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_test_resume_vddma:1;
        RBus_UInt32  drf_test_resume_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_drf_test_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_ls_cntl:1;
        RBus_UInt32  res1:31;
    };
}tve_dma_tvedma_ls_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_done_vddma:1;
        RBus_UInt32  bist_done_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_done_vddma:1;
        RBus_UInt32  drf_bist_done_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_vddma:1;
        RBus_UInt32  bist_fail_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_vddma:1;
        RBus_UInt32  drf_bist_fail_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_start_pause_vddma:1;
        RBus_UInt32  drf_start_pause_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_drf_bist_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_num_count:21;
        RBus_UInt32  res1:9;
        RBus_UInt32  mv_go:1;
        RBus_UInt32  crc_en:1;
    };
}tve_dma_tvecrc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_value:16;
        RBus_UInt32  res1:16;
    };
}tve_dma_tvecrc_value_RBUS;




#endif 


#endif 
