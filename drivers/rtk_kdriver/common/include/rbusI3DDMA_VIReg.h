/**
* @file rbusI3DDMA_VIReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/8/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_I3DDMA_VI_REG_H_
#define _RBUS_I3DDMA_VI_REG_H_

#include "rbusTypes.h"



//  I3DDMA_VI Register Address



#define  I3DDMA_VI_IDMA_V1_OUTPUT_FMT_VADDR                 	(0xb8025b00)
#define  I3DDMA_VI_IDMA_CWVH1_VADDR                         	(0xb8025b04)
#define  I3DDMA_VI_IDMA_CWVH1_2_VADDR                       	(0xb8025b08)
#define  I3DDMA_VI_IDMA_DMACTL_VADDR                        	(0xb8025b0c)
#define  I3DDMA_VI_IDMA_Y1BUF_VADDR                         	(0xb8025b10)
#define  I3DDMA_VI_IDMA_C1BUF_VADDR                         	(0xb8025b14)
#define  I3DDMA_VI_IDMA_DMACTL1_VADDR                       	(0xb8025b18)
#define  I3DDMA_VI_IDMA_DMA_MIN_TIME_VADDR                  	(0xb8025b1c)
#define  I3DDMA_VI_IDMA_INTEN_VADDR                         	(0xb8025b20)
#define  I3DDMA_VI_IDMA_INTST_VADDR                         	(0xb8025b24)
#define  I3DDMA_VI_IDMA_GCTL_VADDR                          	(0xb8025b28)
#define  I3DDMA_VI_IDMA_Y1OBUFF_VADDR                       	(0xb8025b2c)
#define  I3DDMA_VI_IDMA_C1OBUFF_VADDR                       	(0xb8025b30)
#define  I3DDMA_VI_IDMA_VI_DBG_VADDR                        	(0xb8025b68)
#define  I3DDMA_VI_VI_DOUBLEBUFFER_VADDR                    	(0xb8025b70)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======I3DDMA_VI register structure define==========

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
}i3ddma_vi_idma_v1_output_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  hsize:13;
        RBus_UInt32  vsize:12;
    };
}i3ddma_vi_idma_cwvh1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  vsize_c:12;
    };
}i3ddma_vi_idma_cwvh1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_blk_sel:1;
        RBus_UInt32  dummy18025b0c_30_9:22;
        RBus_UInt32  dmaen1:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  bstlen:3;
    };
}i3ddma_vi_idma_dmactl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  y_water_lvl:6;
        RBus_UInt32  res2:10;
    };
}i3ddma_vi_idma_y1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  c_water_lvl:6;
        RBus_UInt32  res2:20;
    };
}i3ddma_vi_idma_c1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  y_ads_set:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  c_ads_set:7;
        RBus_UInt32  dummy18025b18_15_0:16;
    };
}i3ddma_vi_idma_dmactl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  y1c1_min_time:4;
        RBus_UInt32  dummy18025b1c_24_0:25;
    };
}i3ddma_vi_idma_dma_min_time_RBUS;

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
}i3ddma_vi_idma_inten_RBUS;

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
}i3ddma_vi_idma_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  vsce1:1;
        RBus_UInt32  res2:4;
    };
}i3ddma_vi_idma_gctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  y_buf_start:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  y_buf_end:8;
    };
}i3ddma_vi_idma_y1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c_buf_start:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c_buf_end:8;
    };
}i3ddma_vi_idma_c1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dbg_sel:6;
    };
}i3ddma_vi_idma_vi_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  vi_db_apply:1;
        RBus_UInt32  vi_db_sel:1;
        RBus_UInt32  vi_db_en:1;
    };
}i3ddma_vi_vi_doublebuffer_RBUS;

#else //apply LITTLE_ENDIAN

//======I3DDMA_VI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_format:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  swap_1byte:1;
        RBus_UInt32  swap_2byte:1;
        RBus_UInt32  swap_4byte:1;
        RBus_UInt32  swap_8byte:1;
        RBus_UInt32  res2:24;
    };
}i3ddma_vi_idma_v1_output_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsize:12;
        RBus_UInt32  hsize:13;
        RBus_UInt32  res1:7;
    };
}i3ddma_vi_idma_cwvh1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsize_c:12;
        RBus_UInt32  res1:20;
    };
}i3ddma_vi_idma_cwvh1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bstlen:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  dmaen1:1;
        RBus_UInt32  dummy18025b0c_30_9:22;
        RBus_UInt32  seq_blk_sel:1;
    };
}i3ddma_vi_idma_dmactl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  y_water_lvl:6;
        RBus_UInt32  res2:16;
    };
}i3ddma_vi_idma_y1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  c_water_lvl:6;
        RBus_UInt32  res2:6;
    };
}i3ddma_vi_idma_c1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18025b18_15_0:16;
        RBus_UInt32  c_ads_set:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  y_ads_set:7;
        RBus_UInt32  res2:1;
    };
}i3ddma_vi_idma_dmactl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18025b1c_24_0:25;
        RBus_UInt32  y1c1_min_time:4;
        RBus_UInt32  res1:3;
    };
}i3ddma_vi_idma_dma_min_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsinte1:1;
        RBus_UInt32  video_in_last_wr_c_flag_ie:1;
        RBus_UInt32  video_in_last_wr_y_flag_ie:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dmaerrinte:1;
        RBus_UInt32  res2:27;
    };
}i3ddma_vi_idma_inten_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsints1:1;
        RBus_UInt32  video_in_last_wr_c_flag:1;
        RBus_UInt32  video_in_last_wr_y_flag:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dmaerrints:1;
        RBus_UInt32  res2:27;
    };
}i3ddma_vi_idma_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vsce1:1;
        RBus_UInt32  res2:27;
    };
}i3ddma_vi_idma_gctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_buf_end:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  y_buf_start:8;
        RBus_UInt32  res2:8;
    };
}i3ddma_vi_idma_y1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_buf_end:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c_buf_start:8;
        RBus_UInt32  res2:8;
    };
}i3ddma_vi_idma_c1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sel:6;
        RBus_UInt32  res1:26;
    };
}i3ddma_vi_idma_vi_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_db_en:1;
        RBus_UInt32  vi_db_sel:1;
        RBus_UInt32  vi_db_apply:1;
        RBus_UInt32  res1:29;
    };
}i3ddma_vi_vi_doublebuffer_RBUS;




#endif 


#endif 
