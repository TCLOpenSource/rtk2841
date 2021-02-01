/**
* @file rbusYuv2rgbReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_YUV2RGB_REG_H_
#define _RBUS_YUV2RGB_REG_H_

#include "rbusTypes.h"



//  YUV2RGB Register Address



#define  YUV2RGB_D_YUV2RGB_CONTROL_VADDR                    	(0xb802ac00)
#define  YUV2RGB_D_YUV2RGB_CONTROL_1_VADDR                  	(0xb802ac04)
#define  YUV2RGB_D_YUV2RGB_TAB1_DATA_CLAMP_VADDR            	(0xb802ac08)
#define  YUV2RGB_D_YUV2RGB_TAB1_DATA_0_VADDR                	(0xb802ac0c)
#define  YUV2RGB_D_YUV2RGB_TAB1_DATA_1_VADDR                	(0xb802ac10)
#define  YUV2RGB_D_YUV2RGB_TAB1_DATA_2_VADDR                	(0xb802ac14)
#define  YUV2RGB_D_YUV2RGB_TAB1_DATA_3_VADDR                	(0xb802ac18)
#define  YUV2RGB_D_YUV2RGB_TAB1_DATA_4_VADDR                	(0xb802ac1c)
#define  YUV2RGB_D_YUV2RGB_TAB1_DATA_5_VADDR                	(0xb802ac20)
#define  YUV2RGB_D_YUV2RGB_TAB1_DATA_6_VADDR                	(0xb802ac24)
#define  YUV2RGB_D_YUV2RGB_TAB1_DATA_7_VADDR                	(0xb802adb4)
#define  YUV2RGB_D_YUV2RGB_TAB2_DATA_CLAMP_VADDR            	(0xb802adb8)
#define  YUV2RGB_D_YUV2RGB_TAB2_DATA_0_VADDR                	(0xb802ac28)
#define  YUV2RGB_D_YUV2RGB_TAB2_DATA_1_VADDR                	(0xb802ac2c)
#define  YUV2RGB_D_YUV2RGB_TAB2_DATA_2_VADDR                	(0xb802ac30)
#define  YUV2RGB_D_YUV2RGB_TAB2_DATA_3_VADDR                	(0xb802ac34)
#define  YUV2RGB_D_YUV2RGB_TAB2_DATA_4_VADDR                	(0xb802adbc)
#define  YUV2RGB_D_YUV2RGB_TAB2_DATA_5_VADDR                	(0xb802adf0)
#define  YUV2RGB_D_YUV2RGB_TAB2_DATA_6_VADDR                	(0xb802adf4)
#define  YUV2RGB_D_YUV2RGB_TAB2_DATA_7_VADDR                	(0xb802adf8)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_VADDR                	(0xb802ac38)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_VADDR                	(0xb802ac3c)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_VADDR                	(0xb802ac40)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_VADDR                	(0xb802ac44)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_VADDR              	(0xb802ac48)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_VADDR              	(0xb802ac4c)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_VADDR              	(0xb802ac50)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_VADDR              	(0xb802ac54)
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_VADDR                 	(0xb802ac58)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_1_0_VADDR            	(0xb802ac5c)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_1_1_VADDR            	(0xb802ac60)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_1_2_VADDR            	(0xb802ac64)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_1_3_VADDR            	(0xb802ac68)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_2_0_VADDR            	(0xb802ac6c)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_2_1_VADDR            	(0xb802ac70)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_2_2_VADDR            	(0xb802ac74)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_2_3_VADDR            	(0xb802ac78)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_3_0_VADDR            	(0xb802ac7c)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_3_1_VADDR            	(0xb802ac80)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_3_2_VADDR            	(0xb802ac84)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_3_3_VADDR            	(0xb802ac88)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_4_0_VADDR            	(0xb802ac8c)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_4_1_VADDR            	(0xb802ac90)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_4_2_VADDR            	(0xb802ac94)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_4_3_VADDR            	(0xb802ac9c)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_5_0_VADDR            	(0xb802aca0)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_5_1_VADDR            	(0xb802aca4)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_5_2_VADDR            	(0xb802aca8)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_5_3_VADDR            	(0xb802acac)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_6_0_VADDR            	(0xb802acb0)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_6_1_VADDR            	(0xb802acb4)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_6_2_VADDR            	(0xb802acb8)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_6_3_VADDR            	(0xb802acbc)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_7_0_VADDR            	(0xb802acc0)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_7_1_VADDR            	(0xb802acc4)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_7_2_VADDR            	(0xb802acc8)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_7_3_VADDR            	(0xb802accc)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_8_0_VADDR            	(0xb802acd0)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_8_1_VADDR            	(0xb802acd4)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_8_2_VADDR            	(0xb802acd8)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_8_3_VADDR            	(0xb802acdc)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_9_0_VADDR            	(0xb802ace0)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_9_1_VADDR            	(0xb802ace4)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_9_2_VADDR            	(0xb802ace8)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_9_3_VADDR            	(0xb802acec)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_10_0_VADDR           	(0xb802acf0)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_10_1_VADDR           	(0xb802acf4)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_10_2_VADDR           	(0xb802acf8)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_10_3_VADDR           	(0xb802acfc)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_11_0_VADDR           	(0xb802ad00)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_11_1_VADDR           	(0xb802ad04)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_11_2_VADDR           	(0xb802ad08)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_11_3_VADDR           	(0xb802ad0c)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_12_0_VADDR           	(0xb802ad10)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_12_1_VADDR           	(0xb802ad14)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_12_2_VADDR           	(0xb802ad18)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_12_3_VADDR           	(0xb802ad1c)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_13_0_VADDR           	(0xb802ad20)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_13_1_VADDR           	(0xb802ad24)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_13_2_VADDR           	(0xb802ad28)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_13_3_VADDR           	(0xb802ad2c)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_14_0_VADDR           	(0xb802ad30)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_14_1_VADDR           	(0xb802ad34)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_14_2_VADDR           	(0xb802ad38)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_14_3_VADDR           	(0xb802ad3c)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_15_0_VADDR           	(0xb802ad40)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_15_1_VADDR           	(0xb802ad44)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_15_2_VADDR           	(0xb802ad48)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_15_3_VADDR           	(0xb802ad4c)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_16_0_VADDR           	(0xb802ad50)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_16_1_VADDR           	(0xb802ad54)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_16_2_VADDR           	(0xb802ad58)
#define  YUV2RGB_D_YUV2RGBBYY_TAB_DATA_16_3_VADDR           	(0xb802ad5c)
#define  YUV2RGB_D_UVOFFSETBYY_CONTROL_VADDR                	(0xb802ad60)
#define  YUV2RGB_D_UVOFFSETBYY_U_TAB_DATA_1_VADDR           	(0xb802ad64)
#define  YUV2RGB_D_UVOFFSETBYY_U_TAB_DATA_2_VADDR           	(0xb802ad68)
#define  YUV2RGB_D_UVOFFSETBYY_U_TAB_DATA_3_VADDR           	(0xb802ad6c)
#define  YUV2RGB_D_UVOFFSETBYY_U_TAB_DATA_4_VADDR           	(0xb802ad70)
#define  YUV2RGB_D_UVOFFSETBYY_U_TAB_DATA_5_VADDR           	(0xb802ad74)
#define  YUV2RGB_D_UVOFFSETBYY_V_TAB_DATA_1_VADDR           	(0xb802ad78)
#define  YUV2RGB_D_UVOFFSETBYY_V_TAB_DATA_2_VADDR           	(0xb802ad7c)
#define  YUV2RGB_D_UVOFFSETBYY_V_TAB_DATA_3_VADDR           	(0xb802ad80)
#define  YUV2RGB_D_UVOFFSETBYY_V_TAB_DATA_4_VADDR           	(0xb802ad84)
#define  YUV2RGB_D_UVOFFSETBYY_V_TAB_DATA_5_VADDR           	(0xb802ad88)
#define  YUV2RGB_D_UVOFFSETBYY_U_TAB_STEP_1_VADDR           	(0xb802ad8c)
#define  YUV2RGB_D_UVOFFSETBYY_U_TAB_STEP_2_VADDR           	(0xb802ad90)
#define  YUV2RGB_D_UVOFFSETBYY_U_TAB_STEP_3_VADDR           	(0xb802ad94)
#define  YUV2RGB_D_UVOFFSETBYY_U_TAB_STEP_4_VADDR           	(0xb802ad98)
#define  YUV2RGB_D_UVOFFSETBYY_U_TAB_STEP_5_VADDR           	(0xb802ad9c)
#define  YUV2RGB_D_UVOFFSETBYY_V_TAB_STEP_1_VADDR           	(0xb802ada0)
#define  YUV2RGB_D_UVOFFSETBYY_V_TAB_STEP_2_VADDR           	(0xb802ada4)
#define  YUV2RGB_D_UVOFFSETBYY_V_TAB_STEP_3_VADDR           	(0xb802ada8)
#define  YUV2RGB_D_UVOFFSETBYY_V_TAB_STEP_4_VADDR           	(0xb802adac)
#define  YUV2RGB_D_UVOFFSETBYY_V_TAB_STEP_5_VADDR           	(0xb802adb0)
#define  YUV2RGB_ACCESSDATA_CTRL_VADDR                      	(0xb802adc0)
#define  YUV2RGB_ACCESSDATA_POSCTRL_VADDR                   	(0xb802adc4)
#define  YUV2RGB_READDATA_DATA_Y1_VADDR                     	(0xb802adc8)
#define  YUV2RGB_READDATA_DATA_Y2_VADDR                     	(0xb802adcc)
#define  YUV2RGB_READDATA_DATA_C1_VADDR                     	(0xb802add0)
#define  YUV2RGB_READDATA_DATA_C2_VADDR                     	(0xb802add4)
#define  YUV2RGB_READDATA_DATA_C3_VADDR                     	(0xb802add8)
#define  YUV2RGB_READDATA_DATA_C4_VADDR                     	(0xb802addc)
#define  YUV2RGB_WRITEDATA_DATA_VADDR                       	(0xb802ade0)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======YUV2RGB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  yuv2rgb_overlay:1;
        RBus_UInt32  yuv2rgb_sub_tab_sel:1;
        RBus_UInt32  yuv2rgb_main_tab_sel:1;
        RBus_UInt32  yuv2rgb_sub_out_shift:1;
        RBus_UInt32  yuv2rgb_main_out_shift:1;
        RBus_UInt32  yuv2rgb_sub_en:1;
        RBus_UInt32  yuv2rgb_main_en:1;
    };
}yuv2rgb_d_yuv2rgb_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  yuv2rgb_db_read_level:1;
        RBus_UInt32  yuv2rgb_db_en:1;
        RBus_UInt32  yuv2rgb_db_apply:1;
    };
}yuv2rgb_d_yuv2rgb_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  bt2020_en:1;
        RBus_UInt32  cb_cr_clamp:1;
        RBus_UInt32  y_clamp:1;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_clamp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  roffset:15;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  goffset:15;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  boffset:15;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k132:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k322:11;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  bt2020_en:1;
        RBus_UInt32  cb_cr_clamp:1;
        RBus_UInt32  y_clamp:1;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_clamp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  roffset:15;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  goffset:15;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  boffset:15;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k132:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k322:11;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_4:8;
        RBus_UInt32  index_3:8;
        RBus_UInt32  index_2:8;
        RBus_UInt32  index_1:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_8:8;
        RBus_UInt32  index_7:8;
        RBus_UInt32  index_6:8;
        RBus_UInt32  index_5:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_12:8;
        RBus_UInt32  index_11:8;
        RBus_UInt32  index_10:8;
        RBus_UInt32  index_9:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_16:8;
        RBus_UInt32  index_15:8;
        RBus_UInt32  index_14:8;
        RBus_UInt32  index_13:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_4:8;
        RBus_UInt32  index_3:8;
        RBus_UInt32  index_2:8;
        RBus_UInt32  index_1:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_8:8;
        RBus_UInt32  index_7:8;
        RBus_UInt32  index_6:8;
        RBus_UInt32  index_5:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_12:8;
        RBus_UInt32  index_11:8;
        RBus_UInt32  index_10:8;
        RBus_UInt32  index_9:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_16:8;
        RBus_UInt32  index_15:8;
        RBus_UInt32  index_14:8;
        RBus_UInt32  index_13:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  yuv2rgbbymode_sub_en:2;
        RBus_UInt32  yuv2rgb_coef_by_sat_gain:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  yuv2rgb_coef_by_sat_mode:1;
        RBus_UInt32  yuv2rgbbymode_main_en:2;
    };
}yuv2rgb_d_yuv2rgbbyy_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  uvoffsetbyy_sub_en:1;
        RBus_UInt32  res2:13;
        RBus_UInt32  uvoffsetbyy_mode:2;
        RBus_UInt32  uvoffsetbyy_main_en:1;
    };
}yuv2rgb_d_uvoffsetbyy_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m3:8;
        RBus_UInt32  uoffset_m2:8;
        RBus_UInt32  uoffset_m1:8;
        RBus_UInt32  uoffset_m0:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m7:8;
        RBus_UInt32  uoffset_m6:8;
        RBus_UInt32  uoffset_m5:8;
        RBus_UInt32  uoffset_m4:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m11:8;
        RBus_UInt32  uoffset_m10:8;
        RBus_UInt32  uoffset_m9:8;
        RBus_UInt32  uoffset_m8:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m15:8;
        RBus_UInt32  uoffset_m14:8;
        RBus_UInt32  uoffset_m13:8;
        RBus_UInt32  uoffset_m12:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  uoffset_m16:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m3:8;
        RBus_UInt32  voffset_m2:8;
        RBus_UInt32  voffset_m1:8;
        RBus_UInt32  voffset_m0:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m7:8;
        RBus_UInt32  voffset_m6:8;
        RBus_UInt32  voffset_m5:8;
        RBus_UInt32  voffset_m4:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m11:8;
        RBus_UInt32  voffset_m10:8;
        RBus_UInt32  voffset_m9:8;
        RBus_UInt32  voffset_m8:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m15:8;
        RBus_UInt32  voffset_m14:8;
        RBus_UInt32  voffset_m13:8;
        RBus_UInt32  voffset_m12:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  voffset_m16:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m3:8;
        RBus_UInt32  ustep_m2:8;
        RBus_UInt32  ustep_m1:8;
        RBus_UInt32  ustep_m0:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m7:8;
        RBus_UInt32  ustep_m6:8;
        RBus_UInt32  ustep_m5:8;
        RBus_UInt32  ustep_m4:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m11:8;
        RBus_UInt32  ustep_m10:8;
        RBus_UInt32  ustep_m9:8;
        RBus_UInt32  ustep_m8:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m15:8;
        RBus_UInt32  ustep_m14:8;
        RBus_UInt32  ustep_m13:8;
        RBus_UInt32  ustep_m12:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ustep_m16:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m3:8;
        RBus_UInt32  vstep_m2:8;
        RBus_UInt32  vstep_m1:8;
        RBus_UInt32  vstep_m0:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m7:8;
        RBus_UInt32  vstep_m6:8;
        RBus_UInt32  vstep_m5:8;
        RBus_UInt32  vstep_m4:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m11:8;
        RBus_UInt32  vstep_m10:8;
        RBus_UInt32  vstep_m9:8;
        RBus_UInt32  vstep_m8:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m15:8;
        RBus_UInt32  vstep_m14:8;
        RBus_UInt32  vstep_m13:8;
        RBus_UInt32  vstep_m12:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vstep_m16:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}yuv2rgb_accessdata_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  starty:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  startx:13;
    };
}yuv2rgb_accessdata_posctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y01:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  y00:14;
    };
}yuv2rgb_readdata_data_y1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y11:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  y10:14;
    };
}yuv2rgb_readdata_data_y2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  v00:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  u00:14;
    };
}yuv2rgb_readdata_data_c1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  v01:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  u01:14;
    };
}yuv2rgb_readdata_data_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  v10:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  u10:14;
    };
}yuv2rgb_readdata_data_c3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  v11:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  u11:14;
    };
}yuv2rgb_readdata_data_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  v:4;
        RBus_UInt32  u:4;
        RBus_UInt32  y:4;
    };
}yuv2rgb_writedata_data_RBUS;

#else //apply LITTLE_ENDIAN

//======YUV2RGB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yuv2rgb_main_en:1;
        RBus_UInt32  yuv2rgb_sub_en:1;
        RBus_UInt32  yuv2rgb_main_out_shift:1;
        RBus_UInt32  yuv2rgb_sub_out_shift:1;
        RBus_UInt32  yuv2rgb_main_tab_sel:1;
        RBus_UInt32  yuv2rgb_sub_tab_sel:1;
        RBus_UInt32  yuv2rgb_overlay:1;
        RBus_UInt32  res1:25;
    };
}yuv2rgb_d_yuv2rgb_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yuv2rgb_db_apply:1;
        RBus_UInt32  yuv2rgb_db_en:1;
        RBus_UInt32  yuv2rgb_db_read_level:1;
        RBus_UInt32  res1:29;
    };
}yuv2rgb_d_yuv2rgb_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_clamp:1;
        RBus_UInt32  cb_cr_clamp:1;
        RBus_UInt32  bt2020_en:1;
        RBus_UInt32  res1:29;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_clamp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  roffset:15;
        RBus_UInt32  res1:17;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  goffset:15;
        RBus_UInt32  res1:17;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  boffset:15;
        RBus_UInt32  res1:17;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k322:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k132:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_clamp:1;
        RBus_UInt32  cb_cr_clamp:1;
        RBus_UInt32  bt2020_en:1;
        RBus_UInt32  res1:29;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_clamp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  roffset:15;
        RBus_UInt32  res1:17;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  goffset:15;
        RBus_UInt32  res1:17;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  boffset:15;
        RBus_UInt32  res1:17;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k322:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k132:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgb_tab2_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_1:8;
        RBus_UInt32  index_2:8;
        RBus_UInt32  index_3:8;
        RBus_UInt32  index_4:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_5:8;
        RBus_UInt32  index_6:8;
        RBus_UInt32  index_7:8;
        RBus_UInt32  index_8:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_9:8;
        RBus_UInt32  index_10:8;
        RBus_UInt32  index_11:8;
        RBus_UInt32  index_12:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_13:8;
        RBus_UInt32  index_14:8;
        RBus_UInt32  index_15:8;
        RBus_UInt32  index_16:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_1:8;
        RBus_UInt32  index_2:8;
        RBus_UInt32  index_3:8;
        RBus_UInt32  index_4:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_5:8;
        RBus_UInt32  index_6:8;
        RBus_UInt32  index_7:8;
        RBus_UInt32  index_8:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_9:8;
        RBus_UInt32  index_10:8;
        RBus_UInt32  index_11:8;
        RBus_UInt32  index_12:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_13:8;
        RBus_UInt32  index_14:8;
        RBus_UInt32  index_15:8;
        RBus_UInt32  index_16:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yuv2rgbbymode_main_en:2;
        RBus_UInt32  yuv2rgb_coef_by_sat_mode:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  yuv2rgb_coef_by_sat_gain:8;
        RBus_UInt32  yuv2rgbbymode_sub_en:2;
        RBus_UInt32  res2:14;
    };
}yuv2rgb_d_yuv2rgbbyy_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvoffsetbyy_main_en:1;
        RBus_UInt32  uvoffsetbyy_mode:2;
        RBus_UInt32  res1:13;
        RBus_UInt32  uvoffsetbyy_sub_en:1;
        RBus_UInt32  res2:15;
    };
}yuv2rgb_d_uvoffsetbyy_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m0:8;
        RBus_UInt32  uoffset_m1:8;
        RBus_UInt32  uoffset_m2:8;
        RBus_UInt32  uoffset_m3:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m4:8;
        RBus_UInt32  uoffset_m5:8;
        RBus_UInt32  uoffset_m6:8;
        RBus_UInt32  uoffset_m7:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m8:8;
        RBus_UInt32  uoffset_m9:8;
        RBus_UInt32  uoffset_m10:8;
        RBus_UInt32  uoffset_m11:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m12:8;
        RBus_UInt32  uoffset_m13:8;
        RBus_UInt32  uoffset_m14:8;
        RBus_UInt32  uoffset_m15:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m16:8;
        RBus_UInt32  res1:24;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m0:8;
        RBus_UInt32  voffset_m1:8;
        RBus_UInt32  voffset_m2:8;
        RBus_UInt32  voffset_m3:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m4:8;
        RBus_UInt32  voffset_m5:8;
        RBus_UInt32  voffset_m6:8;
        RBus_UInt32  voffset_m7:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m8:8;
        RBus_UInt32  voffset_m9:8;
        RBus_UInt32  voffset_m10:8;
        RBus_UInt32  voffset_m11:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m12:8;
        RBus_UInt32  voffset_m13:8;
        RBus_UInt32  voffset_m14:8;
        RBus_UInt32  voffset_m15:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m16:8;
        RBus_UInt32  res1:24;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m0:8;
        RBus_UInt32  ustep_m1:8;
        RBus_UInt32  ustep_m2:8;
        RBus_UInt32  ustep_m3:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m4:8;
        RBus_UInt32  ustep_m5:8;
        RBus_UInt32  ustep_m6:8;
        RBus_UInt32  ustep_m7:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m8:8;
        RBus_UInt32  ustep_m9:8;
        RBus_UInt32  ustep_m10:8;
        RBus_UInt32  ustep_m11:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m12:8;
        RBus_UInt32  ustep_m13:8;
        RBus_UInt32  ustep_m14:8;
        RBus_UInt32  ustep_m15:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m16:8;
        RBus_UInt32  res1:24;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m0:8;
        RBus_UInt32  vstep_m1:8;
        RBus_UInt32  vstep_m2:8;
        RBus_UInt32  vstep_m3:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m4:8;
        RBus_UInt32  vstep_m5:8;
        RBus_UInt32  vstep_m6:8;
        RBus_UInt32  vstep_m7:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m8:8;
        RBus_UInt32  vstep_m9:8;
        RBus_UInt32  vstep_m10:8;
        RBus_UInt32  vstep_m11:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m12:8;
        RBus_UInt32  vstep_m13:8;
        RBus_UInt32  vstep_m14:8;
        RBus_UInt32  vstep_m15:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m16:8;
        RBus_UInt32  res1:24;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  res1:30;
    };
}yuv2rgb_accessdata_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startx:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  starty:12;
        RBus_UInt32  res2:4;
    };
}yuv2rgb_accessdata_posctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y00:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  y01:14;
        RBus_UInt32  res2:2;
    };
}yuv2rgb_readdata_data_y1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y10:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  y11:14;
        RBus_UInt32  res2:2;
    };
}yuv2rgb_readdata_data_y2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u00:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  v00:14;
        RBus_UInt32  res2:2;
    };
}yuv2rgb_readdata_data_c1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u01:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  v01:14;
        RBus_UInt32  res2:2;
    };
}yuv2rgb_readdata_data_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u10:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  v10:14;
        RBus_UInt32  res2:2;
    };
}yuv2rgb_readdata_data_c3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u11:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  v11:14;
        RBus_UInt32  res2:2;
    };
}yuv2rgb_readdata_data_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:4;
        RBus_UInt32  u:4;
        RBus_UInt32  v:4;
        RBus_UInt32  res1:20;
    };
}yuv2rgb_writedata_data_RBUS;




#endif 


#endif 
