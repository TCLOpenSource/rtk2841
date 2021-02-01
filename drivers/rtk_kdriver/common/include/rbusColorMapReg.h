/**
* @file rbusColorMapReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLORMAP_REG_H_
#define _RBUS_COLORMAP_REG_H_

#include "rbusTypes.h"



//  COLORMAP Register Address



#define  COLORMAP_D_CMRGB2RGB_CONTROL_VADDR                 	(0xb802c300)
#define  COLORMAP_D_CMRGB2RGB_TAB1_DATA_IN_OFFSET_0_VADDR   	(0xb802c304)
#define  COLORMAP_D_CMRGB2RGB_TAB1_DATA_IN_OFFSET_1_VADDR   	(0xb802c308)
#define  COLORMAP_D_CMRGB2RGB_TAB1_DATA_0_VADDR             	(0xb802c30c)
#define  COLORMAP_D_CMRGB2RGB_TAB1_DATA_1_VADDR             	(0xb802c310)
#define  COLORMAP_D_CMRGB2RGB_TAB1_DATA_2_VADDR             	(0xb802c314)
#define  COLORMAP_D_CMRGB2RGB_TAB1_DATA_3_VADDR             	(0xb802c318)
#define  COLORMAP_D_CMRGB2RGB_TAB1_DATA_4_VADDR             	(0xb802c31c)
#define  COLORMAP_D_CMRGB2RGB_TAB1_OUT_OFFSET_0_VADDR       	(0xb802c320)
#define  COLORMAP_D_CMRGB2RGB_TAB1_OUT_OFFSET_1_VADDR       	(0xb802c324)
#define  COLORMAP_D_CMRGB2RGB_TAB2_DATA_IN_OFFSET_0_VADDR   	(0xb802c328)
#define  COLORMAP_D_CMRGB2RGB_TAB2_DATA_IN_OFFSET_1_VADDR   	(0xb802c32c)
#define  COLORMAP_D_CMRGB2RGB_TAB2_DATA_0_VADDR             	(0xb802c330)
#define  COLORMAP_D_CMRGB2RGB_TAB2_DATA_1_VADDR             	(0xb802c334)
#define  COLORMAP_D_CMRGB2RGB_TAB2_DATA_2_VADDR             	(0xb802c338)
#define  COLORMAP_D_CMRGB2RGB_TAB2_DATA_3_VADDR             	(0xb802c33c)
#define  COLORMAP_D_CMRGB2RGB_TAB2_DATA_4_VADDR             	(0xb802c340)
#define  COLORMAP_D_CMRGB2RGB_TAB2_OUT_OFFSET_0_VADDR       	(0xb802c344)
#define  COLORMAP_D_CMRGB2RGB_TAB2_OUT_OFFSET_1_VADDR       	(0xb802c348)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLORMAP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  cmrgb2rgb_overlay:1;
        RBus_UInt32  cmrgb2rgb_sub_tab_sel:1;
        RBus_UInt32  cmrgb2rgb_main_tab_sel:1;
        RBus_UInt32  cmrgb2rgb_sub_en:1;
        RBus_UInt32  cmrgb2rgb_main_en:1;
    };
}colormap_d_cmrgb2rgb_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  y_offset:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  x_offset:15;
    };
}colormap_d_cmrgb2rgb_tab1_data_in_offset_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  z_offset:15;
    };
}colormap_d_cmrgb2rgb_tab1_data_in_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  k12:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  k11:14;
    };
}colormap_d_cmrgb2rgb_tab1_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  k21:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  k13:14;
    };
}colormap_d_cmrgb2rgb_tab1_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  k23:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  k22:14;
    };
}colormap_d_cmrgb2rgb_tab1_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  k32:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  k31:14;
    };
}colormap_d_cmrgb2rgb_tab1_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  k33:14;
    };
}colormap_d_cmrgb2rgb_tab1_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  goffset:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  roffset:15;
    };
}colormap_d_cmrgb2rgb_tab1_out_offset_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  boffset:15;
    };
}colormap_d_cmrgb2rgb_tab1_out_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  y_offset:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  x_offset:15;
    };
}colormap_d_cmrgb2rgb_tab2_data_in_offset_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  z_offset:15;
    };
}colormap_d_cmrgb2rgb_tab2_data_in_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  k12:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  k11:14;
    };
}colormap_d_cmrgb2rgb_tab2_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  k21:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  k13:14;
    };
}colormap_d_cmrgb2rgb_tab2_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  k23:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  k22:14;
    };
}colormap_d_cmrgb2rgb_tab2_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  k32:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  k31:14;
    };
}colormap_d_cmrgb2rgb_tab2_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  k33:14;
    };
}colormap_d_cmrgb2rgb_tab2_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  goffset:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  roffset:15;
    };
}colormap_d_cmrgb2rgb_tab2_out_offset_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  boffset:15;
    };
}colormap_d_cmrgb2rgb_tab2_out_offset_1_RBUS;

#else //apply LITTLE_ENDIAN

//======COLORMAP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmrgb2rgb_main_en:1;
        RBus_UInt32  cmrgb2rgb_sub_en:1;
        RBus_UInt32  cmrgb2rgb_main_tab_sel:1;
        RBus_UInt32  cmrgb2rgb_sub_tab_sel:1;
        RBus_UInt32  cmrgb2rgb_overlay:1;
        RBus_UInt32  res1:27;
    };
}colormap_d_cmrgb2rgb_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  x_offset:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  y_offset:15;
        RBus_UInt32  res2:1;
    };
}colormap_d_cmrgb2rgb_tab1_data_in_offset_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  z_offset:15;
        RBus_UInt32  res1:17;
    };
}colormap_d_cmrgb2rgb_tab1_data_in_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k11:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  k12:14;
        RBus_UInt32  res2:2;
    };
}colormap_d_cmrgb2rgb_tab1_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  k21:14;
        RBus_UInt32  res2:2;
    };
}colormap_d_cmrgb2rgb_tab1_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k22:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  k23:14;
        RBus_UInt32  res2:2;
    };
}colormap_d_cmrgb2rgb_tab1_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k31:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  k32:14;
        RBus_UInt32  res2:2;
    };
}colormap_d_cmrgb2rgb_tab1_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:14;
        RBus_UInt32  res1:18;
    };
}colormap_d_cmrgb2rgb_tab1_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  roffset:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  goffset:15;
        RBus_UInt32  res2:1;
    };
}colormap_d_cmrgb2rgb_tab1_out_offset_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  boffset:15;
        RBus_UInt32  res1:17;
    };
}colormap_d_cmrgb2rgb_tab1_out_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  x_offset:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  y_offset:15;
        RBus_UInt32  res2:1;
    };
}colormap_d_cmrgb2rgb_tab2_data_in_offset_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  z_offset:15;
        RBus_UInt32  res1:17;
    };
}colormap_d_cmrgb2rgb_tab2_data_in_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k11:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  k12:14;
        RBus_UInt32  res2:2;
    };
}colormap_d_cmrgb2rgb_tab2_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  k21:14;
        RBus_UInt32  res2:2;
    };
}colormap_d_cmrgb2rgb_tab2_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k22:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  k23:14;
        RBus_UInt32  res2:2;
    };
}colormap_d_cmrgb2rgb_tab2_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k31:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  k32:14;
        RBus_UInt32  res2:2;
    };
}colormap_d_cmrgb2rgb_tab2_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:14;
        RBus_UInt32  res1:18;
    };
}colormap_d_cmrgb2rgb_tab2_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  roffset:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  goffset:15;
        RBus_UInt32  res2:1;
    };
}colormap_d_cmrgb2rgb_tab2_out_offset_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  boffset:15;
        RBus_UInt32  res1:17;
    };
}colormap_d_cmrgb2rgb_tab2_out_offset_1_RBUS;




#endif 


#endif 
