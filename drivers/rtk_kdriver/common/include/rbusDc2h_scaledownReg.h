/**
* @file rbusDc2h_scaledownReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2014-4-9
* @version 802
* @ingroup model_rbus
*
*/

#ifndef _RBUS_DC2H_SCALEDOWN_REG_H_
#define _RBUS_DC2H_SCALEDOWN_REG_H_

#include "rbus/rbusTypes.h"




// DC2H_SCALEDOWN Register Address

#define DC2H_SCALEDOWN_DC2H_HSD_CTRL0_VADDR        (0xb8029900)
#define DC2H_SCALEDOWN_DC2H_HSD_SCALE_HOR_FACTOR_VADDR  (0xb8029904)
#define DC2H_SCALEDOWN_DC2H_HSD_INITIAL_VALUE_VADDR  (0xb8029908)
#define DC2H_SCALEDOWN_DC2H_HSD_HOR_DELTA1_VADDR   (0xb802990c)
#define DC2H_SCALEDOWN_DC2H_HSD_HOR_SEGMENT_VADDR  (0xb8029910)
#define DC2H_SCALEDOWN_DC2H_HSD_CRC_CTRL_VADDR     (0xb8029914)
#define DC2H_SCALEDOWN_DC2H_HSD_CRC_RESULT_LEFT_VADDR  (0xb8029918)
#define DC2H_SCALEDOWN_DC2H_HSD_CRC_RESULT_VADDR   (0xb802991c)
#define DC2H_SCALEDOWN_DC2H_HSD_L_DES_CRC_VADDR    (0xb8029920)
#define DC2H_SCALEDOWN_DC2H_HSD_R_DES_CRC_VADDR    (0xb8029924)
#define DC2H_SCALEDOWN_DC2H_HSD_CRC_ERR_CNT_VADDR  (0xb8029928)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C0_VADDR  (0xb802992c)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C2_VADDR  (0xb8029930)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C4_VADDR  (0xb8029934)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C6_VADDR  (0xb8029938)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C8_VADDR  (0xb802993c)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C10_VADDR  (0xb8029940)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C12_VADDR  (0xb8029944)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C14_VADDR  (0xb8029948)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C16_VADDR  (0xb802994c)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C18_VADDR  (0xb8029950)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C20_VADDR  (0xb8029954)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C22_VADDR  (0xb8029958)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C24_VADDR  (0xb802995c)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C26_VADDR  (0xb8029960)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C28_VADDR  (0xb8029964)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB1_C30_VADDR  (0xb8029968)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C0_VADDR  (0xb802996c)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C2_VADDR  (0xb8029970)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C4_VADDR  (0xb8029974)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C6_VADDR  (0xb8029978)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C8_VADDR  (0xb802997c)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C10_VADDR  (0xb8029980)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C12_VADDR  (0xb8029984)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C14_VADDR  (0xb8029988)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C16_VADDR  (0xb802998c)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C18_VADDR  (0xb8029990)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C20_VADDR  (0xb8029994)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C22_VADDR  (0xb8029998)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C24_VADDR  (0xb802999c)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C26_VADDR  (0xb80299a0)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C28_VADDR  (0xb80299a4)
#define DC2H_SCALEDOWN_DC2H_UZD_FIR_COEF_TAB2_C30_VADDR  (0xb80299a8)
#define DC2H_SCALEDOWN_DC2H_H_DB_CTRL_VADDR        (0xb80299ac)
#define DC2H_SCALEDOWN_DC2H_VSD_CTRL0_VADDR        (0xb8029a00)
#define DC2H_SCALEDOWN_DC2H_VSD_CTRL1_VADDR        (0xb8029a04)
#define DC2H_SCALEDOWN_DC2H_VSD_SCALE_VER_FACTOR_VADDR  (0xb8029a08)
#define DC2H_SCALEDOWN_DC2H_VSD_INITIAL_VALUE_VADDR  (0xb8029a0c)
#define DC2H_SCALEDOWN_DC2H_VSD_CRC_CTRL_VADDR     (0xb8029a10)
#define DC2H_SCALEDOWN_DC2H_VSD_CRC_RESULT_VADDR   (0xb8029a14)
#define DC2H_SCALEDOWN_DC2H_VSD_CRC_RESULT_RIGHT_VADDR  (0xb8029a18)
#define DC2H_SCALEDOWN_DC2H_VSD_L_DES_CRC_VADDR    (0xb8029a1c)
#define DC2H_SCALEDOWN_DC2H_VSD_R_DES_CRC_VADDR    (0xb8029a20)
#define DC2H_SCALEDOWN_DC2H_VSD_CRC_ERR_CNT_VADDR  (0xb8029a24)
#define DC2H_SCALEDOWN_DC2H_IBUFF_CTRLI_BUFF_CTRL_VADDR  (0xb8029a28)
#define DC2H_SCALEDOWN_DC2H_LINEBUFF_STATUS_VADDR  (0xb8029a34)
#define DC2H_SCALEDOWN_DC2H_LINEBUFF_DRF_FAIL_VADDR  (0xb8029a38)
#define DC2H_SCALEDOWN_DC2H_UZD_SRAM_DRF_VADDR     (0xb8029a3c)
#define DC2H_SCALEDOWN_DC2H_MEASURE_IVST_RESULT_MAIN_VADDR  (0xb8029a40)
#define DC2H_SCALEDOWN_DC2H_MEASURE_ACTLINE_RESULT_MAIN_VADDR  (0xb8029a44)
#define DC2H_SCALEDOWN_DC2H_ACCESSDATA_CTRL_UZD_VADDR  (0xb8029a48)
#define DC2H_SCALEDOWN_DC2H_ACCESSDATA_POSCTRL_UZD_VADDR  (0xb8029a4c)
#define DC2H_SCALEDOWN_DC2H_READDATA_DATA_Y1_UZD_VADDR  (0xb8029a50)
#define DC2H_SCALEDOWN_DC2H_READDATA_DATA_Y2_UZD_VADDR  (0xb8029a54)
#define DC2H_SCALEDOWN_DC2H_READDATA_DATA_C1_UZD_VADDR  (0xb8029a58)
#define DC2H_SCALEDOWN_DC2H_READDATA_DATA_C2_UZD_VADDR  (0xb8029a5c)
#define DC2H_SCALEDOWN_DC2H_READDATA_DATA_C3_UZD_VADDR  (0xb8029a60)
#define DC2H_SCALEDOWN_DC2H_READDATA_DATA_C4_UZD_VADDR  (0xb8029a64)
#define DC2H_SCALEDOWN_DC2H_WRITEDATA_DATA_UZD_VADDR  (0xb8029a68)
#define DC2H_SCALEDOWN_DC2H_V_DB_CTRL_VADDR        (0xb8029a6c)
#define DC2H_SCALEDOWN_DC2H_444TO422_CTRL_VADDR    (0xb8029a70)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======DC2H_SCALEDOWN register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  res2:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  h_zoom_en:1;
    };
}dc2h_hsd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  hor_fac:25;
    };
}dc2h_hsd_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  res2:8;
        RBus_UInt32  hor_ini:8;
    };
}dc2h_hsd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  nl_d1:14;
    };
}dc2h_hsd_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  nl_seg1:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  nl_seg2:13;
    };
}dc2h_hsd_hor_segment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  ch1_hsd_crc_conti:1;
        RBus_UInt32  ch1_hsd_crc_start:1;
    };
}dc2h_hsd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_l_result:32;
    };
}dc2h_hsd_crc_result_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dc2h_hsd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}dc2h_hsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dc2h_hsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  l_crc_err_cnt:16;
    };
}dc2h_hsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c1:12;
    };
}dc2h_uzd_fir_coef_tab1_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c3:12;
    };
}dc2h_uzd_fir_coef_tab1_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c5:12;
    };
}dc2h_uzd_fir_coef_tab1_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c7:12;
    };
}dc2h_uzd_fir_coef_tab1_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c9:12;
    };
}dc2h_uzd_fir_coef_tab1_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c11:12;
    };
}dc2h_uzd_fir_coef_tab1_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c13:12;
    };
}dc2h_uzd_fir_coef_tab1_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c15:12;
    };
}dc2h_uzd_fir_coef_tab1_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c17:12;
    };
}dc2h_uzd_fir_coef_tab1_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c19:12;
    };
}dc2h_uzd_fir_coef_tab1_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c21:12;
    };
}dc2h_uzd_fir_coef_tab1_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c23:12;
    };
}dc2h_uzd_fir_coef_tab1_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c25:12;
    };
}dc2h_uzd_fir_coef_tab1_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c27:12;
    };
}dc2h_uzd_fir_coef_tab1_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c29:12;
    };
}dc2h_uzd_fir_coef_tab1_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c31:12;
    };
}dc2h_uzd_fir_coef_tab1_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c1:12;
    };
}dc2h_uzd_fir_coef_tab2_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c3:12;
    };
}dc2h_uzd_fir_coef_tab2_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c5:12;
    };
}dc2h_uzd_fir_coef_tab2_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c7:12;
    };
}dc2h_uzd_fir_coef_tab2_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c9:12;
    };
}dc2h_uzd_fir_coef_tab2_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c11:12;
    };
}dc2h_uzd_fir_coef_tab2_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c13:12;
    };
}dc2h_uzd_fir_coef_tab2_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c15:12;
    };
}dc2h_uzd_fir_coef_tab2_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c17:12;
    };
}dc2h_uzd_fir_coef_tab2_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c19:12;
    };
}dc2h_uzd_fir_coef_tab2_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c21:12;
    };
}dc2h_uzd_fir_coef_tab2_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c23:12;
    };
}dc2h_uzd_fir_coef_tab2_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c25:12;
    };
}dc2h_uzd_fir_coef_tab2_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c27:12;
    };
}dc2h_uzd_fir_coef_tab2_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c29:12;
    };
}dc2h_uzd_fir_coef_tab2_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c31:12;
    };
}dc2h_uzd_fir_coef_tab2_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  h_db_apply:1;
        RBus_UInt32  h_db_rd_sel:1;
        RBus_UInt32  h_db_en:1;
        RBus_UInt32  res2:4;
    };
}dc2h_h_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:8;
        RBus_UInt32  dummy18029a00_15_14:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  sort_fmt:1;
        RBus_UInt32  v_y_table_sel:1;
        RBus_UInt32  v_c_table_sel:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  buffer_mode:2;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  res13:1;
    };
}dc2h_vsd_Ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  lp121_en:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  res3:13;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:2;
    };
}dc2h_vsd_Ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  ver_fac:25;
    };
}dc2h_vsd_Scale_Ver_Factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  res3:8;
        RBus_UInt32  ver_ini:8;
    };
}dc2h_vsd_Initial_Value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  res2:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  start:1;
    };
}dc2h_vsd_CRC_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}dc2h_vsd_CRC_Result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dc2h_vsd_CRC_Result_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}dc2h_vsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dc2h_vsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  l_crc_err_cnt:16;
    };
}dc2h_vsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  res3:4;
        RBus_UInt32  res4:12;
    };
}dc2h_ibuff_ctrlI_BUFF_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:30;
        RBus_UInt32  bisr_linebuff_fail_0:1;
    };
}dc2h_linebuff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  linebuff_drf_fail_0:1;
    };
}dc2h_linebuff_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  linebuf_ls_en:1;
        RBus_UInt32  linebuf_drf_dvse:1;
        RBus_UInt32  linebuf_drf_dvs:4;
    };
}dc2h_uzd_sram_drf_RBUS;

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
}dc2h_measure_ivst_result_main_RBUS;

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
}dc2h_measure_actline_result_main_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}dc2h_accessdata_CTRL_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  starty:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  startx:13;
    };
}dc2h_accessdata_PosCtrl_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y00:10;
    };
}dc2h_readdata_DATA_Y1_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y10:10;
    };
}dc2h_readdata_DATA_Y2_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u00:10;
    };
}dc2h_readdata_DATA_C1_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u01:10;
    };
}dc2h_readdata_DATA_C2_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u10:10;
    };
}dc2h_readdata_DATA_C3_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u11:10;
    };
}dc2h_readdata_DATA_C4_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  v:4;
        RBus_UInt32  u:4;
        RBus_UInt32  y:4;
    };
}dc2h_writedata_DATA_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  res2:4;
        RBus_UInt32  v_db_apply:1;
        RBus_UInt32  v_db_rd_sel:1;
        RBus_UInt32  v_db_en:1;
    };
}dc2h_v_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  dummy18029a70_0:1;
    };
}dc2h_444to422_ctrl_RBUS;





#else //apply LITTLE_ENDIAN


//======DC2H_SCALEDOWN register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_zoom_en:1;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res1:28;
    };
}dc2h_hsd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_fac:25;
        RBus_UInt32  res1:7;
    };
}dc2h_hsd_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  res1:16;
    };
}dc2h_hsd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nl_d1:14;
        RBus_UInt32  res1:18;
    };
}dc2h_hsd_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nl_seg2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  nl_seg1:13;
        RBus_UInt32  res1:3;
    };
}dc2h_hsd_hor_segment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_start:1;
        RBus_UInt32  ch1_hsd_crc_conti:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res1:27;
    };
}dc2h_hsd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_l_result:32;
    };
}dc2h_hsd_crc_result_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dc2h_hsd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}dc2h_hsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dc2h_hsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_err_cnt:16;
        RBus_UInt32  res1:16;
    };
}dc2h_hsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c0:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c2:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c5:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c4:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c7:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c6:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c9:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c8:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c11:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c10:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c13:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c12:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c15:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c14:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c17:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c16:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c19:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c18:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c21:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c20:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c23:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c22:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c25:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c24:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c27:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c26:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c29:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c28:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c31:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c30:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab1_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c0:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c2:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c5:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c4:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c7:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c6:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c9:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c8:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c11:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c10:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c13:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c12:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c15:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c14:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c17:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c16:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c19:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c18:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c21:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c20:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c23:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c22:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c25:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c24:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c27:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c26:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c29:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c28:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c31:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c30:12;
        RBus_UInt32  res1:4;
    };
}dc2h_uzd_fir_coef_tab2_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:4;
        RBus_UInt32  h_db_en:1;
        RBus_UInt32  h_db_rd_sel:1;
        RBus_UInt32  h_db_apply:1;
        RBus_UInt32  res1:25;
    };
}dc2h_h_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res13:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  buffer_mode:2;
        RBus_UInt32  res12:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  v_c_table_sel:1;
        RBus_UInt32  v_y_table_sel:1;
        RBus_UInt32  sort_fmt:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res7:2;
        RBus_UInt32  dummy18029a00_15_14:2;
        RBus_UInt32  res6:8;
        RBus_UInt32  res5:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res1:2;
    };
}dc2h_vsd_Ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res5:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  res3:13;
        RBus_UInt32  res2:9;
        RBus_UInt32  lp121_en:1;
        RBus_UInt32  res1:6;
    };
}dc2h_vsd_Ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_fac:25;
        RBus_UInt32  res3:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res1:5;
    };
}dc2h_vsd_Scale_Ver_Factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_ini:8;
        RBus_UInt32  res3:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  res1:8;
    };
}dc2h_vsd_Initial_Value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res1:27;
    };
}dc2h_vsd_CRC_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}dc2h_vsd_CRC_Result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dc2h_vsd_CRC_Result_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}dc2h_vsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dc2h_vsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_err_cnt:16;
        RBus_UInt32  res1:16;
    };
}dc2h_vsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res4:12;
        RBus_UInt32  res3:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  res1:4;
    };
}dc2h_ibuff_ctrlI_BUFF_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr_linebuff_fail_0:1;
        RBus_UInt32  res2:30;
        RBus_UInt32  res1:1;
    };
}dc2h_linebuff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linebuff_drf_fail_0:1;
        RBus_UInt32  res1:31;
    };
}dc2h_linebuff_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linebuf_drf_dvs:4;
        RBus_UInt32  linebuf_drf_dvse:1;
        RBus_UInt32  linebuf_ls_en:1;
        RBus_UInt32  res1:26;
    };
}dc2h_uzd_sram_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_ivst_value_even:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  m_ivst_value_odd:12;
        RBus_UInt32  res1:2;
        RBus_UInt32  m_ihs_mode:1;
        RBus_UInt32  m_ivst_en:1;
    };
}dc2h_measure_ivst_result_main_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_hactive_hpixel_value:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m_vactive_line_value:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  m_active_line_pixel_en:1;
    };
}dc2h_measure_actline_result_main_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  res1:30;
    };
}dc2h_accessdata_CTRL_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startx:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  starty:13;
        RBus_UInt32  res1:3;
    };
}dc2h_accessdata_PosCtrl_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res1:6;
    };
}dc2h_readdata_DATA_Y1_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res1:6;
    };
}dc2h_readdata_DATA_Y2_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res1:6;
    };
}dc2h_readdata_DATA_C1_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res1:6;
    };
}dc2h_readdata_DATA_C2_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res1:6;
    };
}dc2h_readdata_DATA_C3_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res1:6;
    };
}dc2h_readdata_DATA_C4_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:4;
        RBus_UInt32  u:4;
        RBus_UInt32  v:4;
        RBus_UInt32  res1:20;
    };
}dc2h_writedata_DATA_UZD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_db_en:1;
        RBus_UInt32  v_db_rd_sel:1;
        RBus_UInt32  v_db_apply:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  res1:25;
    };
}dc2h_v_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029a70_0:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  res1:29;
    };
}dc2h_444to422_ctrl_RBUS;


#endif







#endif //_RBUS_DC2H_SCALEDOWN_REG_H_

