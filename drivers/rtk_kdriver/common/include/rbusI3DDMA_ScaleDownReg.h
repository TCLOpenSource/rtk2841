/**
* @file rbusI3DDMA_ScaledownReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/8/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_I3DDMA_SCALEDOWN_REG_H_
#define _RBUS_I3DDMA_SCALEDOWN_REG_H_

#include "rbusTypes.h"



//  I3DDMA_SCALEDOWN Register Address



#define  I3DDMA_SCALEDOWN_HSD_CTRL0_VADDR                   	(0xb8025900)
#define  I3DDMA_SCALEDOWN_HSD_SCALE_HOR_FACTOR_VADDR        	(0xb8025904)
#define  I3DDMA_SCALEDOWN_HSD_INITIAL_VALUE_VADDR           	(0xb8025908)
#define  I3DDMA_SCALEDOWN_HSD_HOR_DELTA1_VADDR              	(0xb802590c)
#define  I3DDMA_SCALEDOWN_HSD_HOR_SEGMENT_VADDR             	(0xb8025910)
#define  I3DDMA_SCALEDOWN_HSD_CRC_CTRL_VADDR                	(0xb8025914)
#define  I3DDMA_SCALEDOWN_HSD_CRC_RESULT_LEFT_VADDR         	(0xb8025918)
#define  I3DDMA_SCALEDOWN_HSD_CRC_RESULT_VADDR              	(0xb802591c)
#define  I3DDMA_SCALEDOWN_HSD_L_DES_CRC_VADDR               	(0xb8025920)
#define  I3DDMA_SCALEDOWN_HSD_R_DES_CRC_VADDR               	(0xb8025924)
#define  I3DDMA_SCALEDOWN_HSD_CRC_ERR_CNT_VADDR             	(0xb8025928)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C0_VADDR        	(0xb802592c)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C2_VADDR        	(0xb8025930)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C4_VADDR        	(0xb8025934)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C6_VADDR        	(0xb8025938)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C8_VADDR        	(0xb802593c)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C10_VADDR       	(0xb8025940)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C12_VADDR       	(0xb8025944)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C14_VADDR       	(0xb8025948)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C16_VADDR       	(0xb802594c)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C18_VADDR       	(0xb8025950)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C20_VADDR       	(0xb8025954)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C22_VADDR       	(0xb8025958)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C24_VADDR       	(0xb802595c)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C26_VADDR       	(0xb8025960)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C28_VADDR       	(0xb8025964)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C30_VADDR       	(0xb8025968)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C0_VADDR        	(0xb802596c)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C2_VADDR        	(0xb8025970)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C4_VADDR        	(0xb8025974)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C6_VADDR        	(0xb8025978)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C8_VADDR        	(0xb802597c)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C10_VADDR       	(0xb8025980)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C12_VADDR       	(0xb8025984)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C14_VADDR       	(0xb8025988)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C16_VADDR       	(0xb802598c)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C18_VADDR       	(0xb8025990)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C20_VADDR       	(0xb8025994)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C22_VADDR       	(0xb8025998)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C24_VADDR       	(0xb802599c)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C26_VADDR       	(0xb80259a0)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C28_VADDR       	(0xb80259a4)
#define  I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C30_VADDR       	(0xb80259a8)
#define  I3DDMA_SCALEDOWN_H_DB_CTRL_VADDR                   	(0xb80259ac)
#define  I3DDMA_SCALEDOWN_VSD_CTRL0_VADDR                   	(0xb8025600)
#define  I3DDMA_SCALEDOWN_VSD_CTRL1_VADDR                   	(0xb8025604)
#define  I3DDMA_SCALEDOWN_VSD_SCALE_VER_FACTOR_VADDR        	(0xb8025608)
#define  I3DDMA_SCALEDOWN_VSD_INITIAL_VALUE_VADDR           	(0xb802560c)
#define  I3DDMA_SCALEDOWN_VSD_CRC_CTRL_VADDR                	(0xb8025610)
#define  I3DDMA_SCALEDOWN_VSD_CRC_RESULT_VADDR              	(0xb8025614)
#define  I3DDMA_SCALEDOWN_VSD_CRC_RESULT_RIGHT_VADDR        	(0xb8025618)
#define  I3DDMA_SCALEDOWN_VSD_L_DES_CRC_VADDR               	(0xb802561c)
#define  I3DDMA_SCALEDOWN_VSD_R_DES_CRC_VADDR               	(0xb8025620)
#define  I3DDMA_SCALEDOWN_VSD_CRC_ERR_CNT_VADDR             	(0xb8025624)
#define  I3DDMA_SCALEDOWN_IBUFF_CTRLI_BUFF_CTRL_VADDR       	(0xb8025628)
#define  I3DDMA_SCALEDOWN_VSD_CHANNEL_SWAP_VADDR            	(0xb802562c)
#define  I3DDMA_SCALEDOWN_V_DB_CTRL_VADDR                   	(0xb8025630)
#define  I3DDMA_SCALEDOWN_IBUFF_STATUS_VADDR                	(0xb8025680)
#define  I3DDMA_SCALEDOWN_IBUFF_DRF_FAIL_VADDR              	(0xb8025684)
#define  I3DDMA_SCALEDOWN_LINEBUFF_STATUS_VADDR             	(0xb8025688)
#define  I3DDMA_SCALEDOWN_LINEBUFF_DRF_FAIL_VADDR           	(0xb802568c)
#define  I3DDMA_SCALEDOWN_UZD_SRAM_DRF_VADDR                	(0xb8025690)
#define  I3DDMA_SCALEDOWN_UZD_444TO422_CTRL_VADDR           	(0xb80256a0)
#define  I3DDMA_SCALEDOWN_MEASURE_IVST_RESULT_MAIN_PATH_VADDR 	(0xb80256b0)
#define  I3DDMA_SCALEDOWN_MEASURE_ACTIVE_LINE_PIXELS_RESULT_MAIN_PATH_VADDR  	(0xb80256b4)
#define  I3DDMA_SCALEDOWN_ACCESSDATA_CTRL_UZD_VADDR         	(0xb80256c0)
#define  I3DDMA_SCALEDOWN_ACCESSDATA_POSCTRL_UZD_VADDR      	(0xb80256c4)
#define  I3DDMA_SCALEDOWN_READDATA_DATA_Y1_UZD_VADDR        	(0xb80256c8)
#define  I3DDMA_SCALEDOWN_READDATA_DATA_Y2_UZD_VADDR        	(0xb80256cc)
#define  I3DDMA_SCALEDOWN_READDATA_DATA_C1_UZD_VADDR        	(0xb80256d0)
#define  I3DDMA_SCALEDOWN_READDATA_DATA_C2_UZD_VADDR        	(0xb80256d4)
#define  I3DDMA_SCALEDOWN_READDATA_DATA_C3_UZD_VADDR        	(0xb80256d8)
#define  I3DDMA_SCALEDOWN_READDATA_DATA_C4_UZD_VADDR        	(0xb80256dc)
#define  I3DDMA_SCALEDOWN_WRITEDATA_DATA_UZD_VADDR          	(0xb80256e0)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======I3DDMA_SCALEDOWN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  h_3d_sel_en:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  h_zoom_en:1;
    };
}i3ddma_scaledown_hsd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  hor_fac:25;
    };
}i3ddma_scaledown_hsd_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hor_ini_l:8;
        RBus_UInt32  hor_ini:8;
    };
}i3ddma_scaledown_hsd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  nl_d1:14;
    };
}i3ddma_scaledown_hsd_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  nl_seg1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  nl_seg2:12;
    };
}i3ddma_scaledown_hsd_hor_segment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  crc_3d_en:1;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  ch1_hsd_crc_conti:1;
        RBus_UInt32  ch1_hsd_crc_start:1;
    };
}i3ddma_scaledown_hsd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_l_result:32;
    };
}i3ddma_scaledown_hsd_crc_result_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_r_result:32;
    };
}i3ddma_scaledown_hsd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}i3ddma_scaledown_hsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}i3ddma_scaledown_hsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_err_cnt:16;
        RBus_UInt32  l_crc_err_cnt:16;
    };
}i3ddma_scaledown_hsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c1:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c3:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c5:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c7:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c9:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c11:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c13:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c15:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c17:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c19:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c21:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c23:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c25:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c27:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c29:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c31:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c1:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c3:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c5:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c7:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c9:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c11:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c13:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c15:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c17:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c19:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c21:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c23:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c25:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c27:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c29:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c31:12;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  h_db_apply:1;
        RBus_UInt32  h_db_rd_sel:1;
        RBus_UInt32  h_db_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
    };
}i3ddma_scaledown_h_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  truncationctrl:1;
        RBus_UInt32  argb_dummy_data:8;
        RBus_UInt32  dummy18025600_15_14:2;
        RBus_UInt32  argb_swap:1;
        RBus_UInt32  rgb_to_argb_en:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  out_bit:1;
        RBus_UInt32  sort_fmt:1;
        RBus_UInt32  v_y_table_sel:1;
        RBus_UInt32  v_c_table_sel:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  buffer_mode:2;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  res6:1;
    };
}i3ddma_scaledown_vsd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  lp121_en:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  vsd_3d_boundary:13;
        RBus_UInt32  res3:1;
        RBus_UInt32  vsd_3d_mode:2;
    };
}i3ddma_scaledown_vsd_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  ver_ini_int_l:1;
        RBus_UInt32  ver_ini_int:1;
        RBus_UInt32  ver_fac:25;
    };
}i3ddma_scaledown_vsd_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ver_ini_l:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  ver_ini:8;
    };
}i3ddma_scaledown_vsd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  start:1;
    };
}i3ddma_scaledown_vsd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}i3ddma_scaledown_vsd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}i3ddma_scaledown_vsd_crc_result_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}i3ddma_scaledown_vsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}i3ddma_scaledown_vsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_err_cnt:16;
        RBus_UInt32  l_crc_err_cnt:16;
    };
}i3ddma_scaledown_vsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ibuf_v_size:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ibuf_h_size:13;
    };
}i3ddma_scaledown_ibuff_ctrli_buff_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  rgb565_en:1;
        RBus_UInt32  rgb_ch_swap:3;
    };
}i3ddma_scaledown_vsd_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dummy18025630_6:1;
        RBus_UInt32  dummy18025630_5:1;
        RBus_UInt32  dummy18025630_4:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  v_db_apply:1;
        RBus_UInt32  v_db_rd_sel:1;
        RBus_UInt32  v_db_en:1;
    };
}i3ddma_scaledown_v_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dummy18025680_1:1;
        RBus_UInt32  dummy18025680_0:1;
    };
}i3ddma_scaledown_ibuff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dummy18025684_1:1;
        RBus_UInt32  dummy18025684_0:1;
    };
}i3ddma_scaledown_ibuff_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bisr_linebuff_fail_0:1;
    };
}i3ddma_scaledown_linebuff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  linebuff_drf_fail_0:1;
    };
}i3ddma_scaledown_linebuff_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linebuf_ls_en:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  dummy18025690_20:1;
        RBus_UInt32  dummy18025690_19_16:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  dummy18025690_12:1;
        RBus_UInt32  dummy18025690_11_8:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  linebuf_drf_dvse:1;
        RBus_UInt32  linebuf_drf_dvs:4;
    };
}i3ddma_scaledown_uzd_sram_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_420_en:1;
        RBus_UInt32  i3ddma_420_mode:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  i3ddma_420_blend_sel:8;
        RBus_UInt32  res2:13;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  dummy180256a0_0:1;
    };
}i3ddma_scaledown_uzd_444to422_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_ivst_en:1;
        RBus_UInt32  m_ihs_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  m_ivst_value_odd:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  m_ivst_value_even:12;
    };
}i3ddma_scaledown_measure_ivst_result_main_path_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_active_line_pixel_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  m_vactive_line_value:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  m_hactive_hpixel_value:13;
    };
}i3ddma_scaledown_measure_active_line_pixels_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}i3ddma_scaledown_accessdata_ctrl_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  starty:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  startx:13;
    };
}i3ddma_scaledown_accessdata_posctrl_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y00:10;
    };
}i3ddma_scaledown_readdata_data_y1_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y10:10;
    };
}i3ddma_scaledown_readdata_data_y2_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u00:10;
    };
}i3ddma_scaledown_readdata_data_c1_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u01:10;
    };
}i3ddma_scaledown_readdata_data_c2_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u10:10;
    };
}i3ddma_scaledown_readdata_data_c3_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u11:10;
    };
}i3ddma_scaledown_readdata_data_c4_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  v:4;
        RBus_UInt32  u:4;
        RBus_UInt32  y:4;
    };
}i3ddma_scaledown_writedata_data_uzd_RBUS;

#else //apply LITTLE_ENDIAN

//======I3DDMA_SCALEDOWN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_zoom_en:1;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  h_3d_sel_en:1;
        RBus_UInt32  res1:28;
    };
}i3ddma_scaledown_hsd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_fac:25;
        RBus_UInt32  res1:7;
    };
}i3ddma_scaledown_hsd_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  hor_ini_l:8;
        RBus_UInt32  res1:16;
    };
}i3ddma_scaledown_hsd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nl_d1:14;
        RBus_UInt32  res1:18;
    };
}i3ddma_scaledown_hsd_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nl_seg2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  nl_seg1:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_hsd_hor_segment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_start:1;
        RBus_UInt32  ch1_hsd_crc_conti:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  crc_3d_en:1;
        RBus_UInt32  res1:27;
    };
}i3ddma_scaledown_hsd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_l_result:32;
    };
}i3ddma_scaledown_hsd_crc_result_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_r_result:32;
    };
}i3ddma_scaledown_hsd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}i3ddma_scaledown_hsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}i3ddma_scaledown_hsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_err_cnt:16;
        RBus_UInt32  r_crc_err_cnt:16;
    };
}i3ddma_scaledown_hsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c0:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c2:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c4:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c6:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c8:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c11:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c10:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c13:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c12:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c15:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c14:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c17:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c16:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c19:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c18:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c21:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c20:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c23:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c22:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c25:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c24:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c27:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c26:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c29:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c28:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c31:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c30:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab1_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c0:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c2:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c4:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c6:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c8:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c11:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c10:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c13:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c12:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c15:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c14:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c17:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c16:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c19:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c18:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c21:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c20:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c23:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c22:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c25:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c24:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c27:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c26:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c29:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c28:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c31:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c30:12;
        RBus_UInt32  res2:4;
    };
}i3ddma_scaledown_uzd_fir_coef_tab2_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  h_db_en:1;
        RBus_UInt32  h_db_rd_sel:1;
        RBus_UInt32  h_db_apply:1;
        RBus_UInt32  res5:25;
    };
}i3ddma_scaledown_h_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  buffer_mode:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  v_c_table_sel:1;
        RBus_UInt32  v_y_table_sel:1;
        RBus_UInt32  sort_fmt:1;
        RBus_UInt32  out_bit:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  rgb_to_argb_en:1;
        RBus_UInt32  argb_swap:1;
        RBus_UInt32  dummy18025600_15:2;
        RBus_UInt32  argb_dummy_data:8;
        RBus_UInt32  truncationctrl:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:3;
    };
}i3ddma_scaledown_vsd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsd_3d_mode:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  vsd_3d_boundary:13;
        RBus_UInt32  res2:9;
        RBus_UInt32  lp121_en:1;
        RBus_UInt32  res3:6;
    };
}i3ddma_scaledown_vsd_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_fac:25;
        RBus_UInt32  ver_ini_int:1;
        RBus_UInt32  ver_ini_int_l:1;
        RBus_UInt32  res1:5;
    };
}i3ddma_scaledown_vsd_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_ini:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  ver_ini_l:8;
        RBus_UInt32  res2:8;
    };
}i3ddma_scaledown_vsd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  res2:27;
    };
}i3ddma_scaledown_vsd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}i3ddma_scaledown_vsd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}i3ddma_scaledown_vsd_crc_result_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}i3ddma_scaledown_vsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}i3ddma_scaledown_vsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_err_cnt:16;
        RBus_UInt32  r_crc_err_cnt:16;
    };
}i3ddma_scaledown_vsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ibuf_h_size:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ibuf_v_size:13;
        RBus_UInt32  res2:3;
    };
}i3ddma_scaledown_ibuff_ctrli_buff_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rgb_ch_swap:3;
        RBus_UInt32  rgb565_en:1;
        RBus_UInt32  res1:28;
    };
}i3ddma_scaledown_vsd_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_db_en:1;
        RBus_UInt32  v_db_rd_sel:1;
        RBus_UInt32  v_db_apply:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dummy18025630_4:1;
        RBus_UInt32  dummy18025630_5:1;
        RBus_UInt32  dummy18025630_6:1;
        RBus_UInt32  res2:25;
    };
}i3ddma_scaledown_v_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18025680_0:1;
        RBus_UInt32  dummy18025680_1:1;
        RBus_UInt32  res1:30;
    };
}i3ddma_scaledown_ibuff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18025684_0:1;
        RBus_UInt32  dummy18025684_1:1;
        RBus_UInt32  res1:30;
    };
}i3ddma_scaledown_ibuff_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr_linebuff_fail_0:1;
        RBus_UInt32  res1:31;
    };
}i3ddma_scaledown_linebuff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linebuff_drf_fail_0:1;
        RBus_UInt32  res1:31;
    };
}i3ddma_scaledown_linebuff_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linebuf_drf_dvs:4;
        RBus_UInt32  linebuf_drf_dvse:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dummy18025690_11_8:4;
        RBus_UInt32  dummy18025690_12_12:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dummy18025690_19_16:4;
        RBus_UInt32  dummy18025690_20_20:1;
        RBus_UInt32  res3:10;
        RBus_UInt32  linebuf_ls_en:1;
    };
}i3ddma_scaledown_uzd_sram_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180256a0_0:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  i3ddma_420_blend_sel:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  i3ddma_420_mode:1;
        RBus_UInt32  i3ddma_420_en:1;
    };
}i3ddma_scaledown_uzd_444to422_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_ivst_value_even:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  m_ivst_value_odd:12;
        RBus_UInt32  res2:2;
        RBus_UInt32  m_ihs_mode:1;
        RBus_UInt32  m_ivst_en:1;
    };
}i3ddma_scaledown_measure_ivst_result_main_path_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_hactive_hpixel_value:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  m_vactive_line_value:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  m_active_line_pixel_en:1;
    };
}i3ddma_scaledown_measure_active_line_pixels_result_main_path_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  res1:30;
    };
}i3ddma_scaledown_accessdata_ctrl_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startx:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  starty:13;
        RBus_UInt32  res2:3;
    };
}i3ddma_scaledown_accessdata_posctrl_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
    };
}i3ddma_scaledown_readdata_data_y1_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
    };
}i3ddma_scaledown_readdata_data_y2_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
    };
}i3ddma_scaledown_readdata_data_c1_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u01:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
    };
}i3ddma_scaledown_readdata_data_c2_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
    };
}i3ddma_scaledown_readdata_data_c3_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
    };
}i3ddma_scaledown_readdata_data_c4_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:4;
        RBus_UInt32  u:4;
        RBus_UInt32  v:4;
        RBus_UInt32  res1:20;
    };
}i3ddma_scaledown_writedata_data_uzd_RBUS;




#endif 


#endif 
