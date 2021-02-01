/**
* @file rbusDc2h_viReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2014-5-10
* @version 802
* @ingroup model_rbus
*
*/

#ifndef _RBUS_DC2H_VI_REG_H_
#define _RBUS_DC2H_VI_REG_H_

#include "rbus/rbusTypes.h"




// DC2H_VI Register Address

#define DC2H_VI_DC2H_V1_OUTPUT_FMT_VADDR           (0xb8029d00)
#define DC2H_VI_DC2H_CWVH1_VADDR                   (0xb8029d04)
#define DC2H_VI_DC2H_CWVH1_2_VADDR                 (0xb8029d08)
#define DC2H_VI_DC2H_DMACTL_VADDR                  (0xb8029d0c)
#define DC2H_VI_DC2H_Y1BUF_VADDR                   (0xb8029d10)
#define DC2H_VI_DC2H_C1BUF_VADDR                   (0xb8029d14)
#define DC2H_VI_DC2H_DMACTL1_VADDR                 (0xb8029d18)
#define DC2H_VI_DC2H_DMA_MIN_TIME_VADDR            (0xb8029d1c)
#define DC2H_VI_DC2H_INTEN_VADDR                   (0xb8029d20)
#define DC2H_VI_DC2H_INTST_VADDR                   (0xb8029d24)
#define DC2H_VI_DC2H_GCTL_VADDR                    (0xb8029d28)
#define DC2H_VI_DC2H_Y1OBUFF_VADDR                 (0xb8029d2c)
#define DC2H_VI_DC2H_C1OBUFF_VADDR                 (0xb8029d30)
#define DC2H_VI_DC2H_VI_LIGHT_SLEEP_MODE_VADDR     (0xb8029d34)
#define DC2H_VI_DC2H_VI_DEEP_SLEEP_MODE_VADDR      (0xb8029d38)
#define DC2H_VI_DC2H_VI_SHUT_DOWN_MODE_VADDR       (0xb8029d3c)
#define DC2H_VI_DC2H_VI_READ_MARGIN_ENABLE_VADDR   (0xb8029d40)
#define DC2H_VI_DC2H_VI_READ_MARGIN_VADDR          (0xb8029d44)
#define DC2H_VI_DC2H_VI_BIST_MODE_VADDR            (0xb8029d48)
#define DC2H_VI_DC2H_VI_BIST_DONE_VADDR            (0xb8029d4c)
#define DC2H_VI_DC2H_VI_BIST_FAIL_GROUP_VADDR      (0xb8029d50)
#define DC2H_VI_DC2H_VI_DRF_MODE_VADDR             (0xb8029d54)
#define DC2H_VI_VI_DRF_RESUME_VADDR                (0xb8029d58)
#define DC2H_VI_DC2H_VI_DRF_DONE_VADDR             (0xb8029d5c)
#define DC2H_VI_DC2H_VI_DRF_PAUSE_VADDR            (0xb8029d60)
#define DC2H_VI_DC2H_VI_DRF_FAIL_GROUP_VADDR       (0xb8029d64)
#define DC2H_VI_DC2H_DBG_VADDR                     (0xb8029d68)
#define DC2H_VI_DC2H_VI_DOUBLEBUFFER_VADDR         (0xb8029d6c)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======DC2H_VI register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  swap_8byte:1;
        RBus_UInt32  swap_4byte:1;
        RBus_UInt32  swap_2byte:1;
        RBus_UInt32  swap_1byte:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  data_format:1;
    };
}dc2h_v1_output_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  hsize:13;
        RBus_UInt32  vsize:12;
    };
}dc2h_cwvh1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  vsize_c:12;
    };
}dc2h_cwvh1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_blk_sel:1;
        RBus_UInt32  dummy18029d0c_30_9:22;
        RBus_UInt32  dmaen1:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  bstlen:3;
    };
}dc2h_dmactl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  y_water_lvl:6;
        RBus_UInt32  res2:10;
    };
}dc2h_y1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  c_water_lvl:6;
        RBus_UInt32  res2:20;
    };
}dc2h_c1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  y_ads_set:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  c_ads_set:7;
        RBus_UInt32  dummy18029d18_15_0:16;
    };
}dc2h_dmactl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  y1c1_min_time:4;
        RBus_UInt32  dummy18029d1c_24_0:25;
    };
}dc2h_dma_min_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  dmaerrinte:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  video_in_last_wr_y_flag_ie:1;
        RBus_UInt32  video_in_last_wr_c_flag_ie:1;
        RBus_UInt32  vsinte1:1;
    };
}dc2h_inten_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  dmaerrints:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  video_in_last_wr_y_flag:1;
        RBus_UInt32  video_in_last_wr_c_flag:1;
        RBus_UInt32  vsints1:1;
    };
}dc2h_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  vsce1:1;
        RBus_UInt32  res2:4;
    };
}dc2h_gctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  y_buf_start:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  y_buf_end:9;
    };
}dc2h_y1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  c_buf_start:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  c_buf_end:9;
    };
}dc2h_c1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_ls:1;
    };
}dc2h_vi_light_sleep_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_ds:1;
    };
}dc2h_vi_deep_sleep_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_sd:1;
    };
}dc2h_vi_shut_down_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_rme:1;
    };
}dc2h_vi_read_margin_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  vi_rm:4;
    };
}dc2h_vi_read_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_bist_mode:1;
    };
}dc2h_vi_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_bist_done:1;
    };
}dc2h_vi_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_bist_fail:1;
    };
}dc2h_vi_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_drf_mode:1;
    };
}dc2h_vi_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_drf_resume:1;
    };
}vi_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_drf_done:1;
    };
}dc2h_vi_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_drf_pause:1;
    };
}dc2h_vi_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_drf_fail:1;
    };
}dc2h_vi_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dbg_sel:6;
    };
}dc2h_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  vi_db_apply:1;
        RBus_UInt32  vi_db_sel:1;
        RBus_UInt32  vi_db_en:1;
    };
}dc2h_vi_doublebuffer_RBUS;





#else //apply LITTLE_ENDIAN


//======DC2H_VI register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_format:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  swap_1byte:1;
        RBus_UInt32  swap_2byte:1;
        RBus_UInt32  swap_4byte:1;
        RBus_UInt32  swap_8byte:1;
        RBus_UInt32  res1:24;
    };
}dc2h_v1_output_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsize:12;
        RBus_UInt32  hsize:13;
        RBus_UInt32  res1:7;
    };
}dc2h_cwvh1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsize_c:12;
        RBus_UInt32  res1:20;
    };
}dc2h_cwvh1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bstlen:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  dmaen1:1;
        RBus_UInt32  dummy18029d0c_30_9:22;
        RBus_UInt32  seq_blk_sel:1;
    };
}dc2h_dmactl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:10;
        RBus_UInt32  y_water_lvl:6;
        RBus_UInt32  res1:16;
    };
}dc2h_y1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:20;
        RBus_UInt32  c_water_lvl:6;
        RBus_UInt32  res1:6;
    };
}dc2h_c1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029d18_15_0:16;
        RBus_UInt32  c_ads_set:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  y_ads_set:7;
        RBus_UInt32  res1:1;
    };
}dc2h_dmactl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029d1c_24_0:25;
        RBus_UInt32  y1c1_min_time:4;
        RBus_UInt32  res1:3;
    };
}dc2h_dma_min_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsinte1:1;
        RBus_UInt32  video_in_last_wr_c_flag_ie:1;
        RBus_UInt32  video_in_last_wr_y_flag_ie:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dmaerrinte:1;
        RBus_UInt32  res1:27;
    };
}dc2h_inten_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsints1:1;
        RBus_UInt32  video_in_last_wr_c_flag:1;
        RBus_UInt32  video_in_last_wr_y_flag:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dmaerrints:1;
        RBus_UInt32  res1:27;
    };
}dc2h_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:4;
        RBus_UInt32  vsce1:1;
        RBus_UInt32  res1:27;
    };
}dc2h_gctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_buf_end:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  y_buf_start:9;
        RBus_UInt32  res1:7;
    };
}dc2h_y1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_buf_end:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  c_buf_start:9;
        RBus_UInt32  res1:7;
    };
}dc2h_c1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_ls:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_light_sleep_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_ds:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_deep_sleep_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_sd:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_shut_down_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_rme:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_read_margin_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_rm:4;
        RBus_UInt32  res1:28;
    };
}dc2h_vi_read_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_bist_mode:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_bist_done:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_bist_fail:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_drf_mode:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_drf_resume:1;
        RBus_UInt32  res1:31;
    };
}vi_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_drf_done:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_drf_pause:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_drf_fail:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sel:6;
        RBus_UInt32  res1:26;
    };
}dc2h_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_db_en:1;
        RBus_UInt32  vi_db_sel:1;
        RBus_UInt32  vi_db_apply:1;
        RBus_UInt32  res1:29;
    };
}dc2h_vi_doublebuffer_RBUS;


#endif







#endif //_RBUS_DC2H_VI_REG_H_

