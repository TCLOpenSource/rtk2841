/**
* @file rbusTPReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014-7-11
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUSTP_REG_H_
#define _RBUSTP_REG_H_

#include "rbusTypes.h"



//  TP Register Address



#define  TP_TF0_CNTL_VADDR                                  	(0xb8014000)
#define  TP_TF0_STRM_ID_0_VADDR                             	(0xb8014004)
#define  TP_TF0_STRM_ID_1_VADDR                             	(0xb8014008)
#define  TP_TF0_STRM_ID_2_VADDR                             	(0xb801400c)
#define  TP_TF0_STRM_ID_3_VADDR                             	(0xb8014010)
#define  TP_TF0_STRM_VAL_VADDR                              	(0xb8014014)
#define  TP_TF0_CNT_VADDR                                   	(0xb8014018)
#define  TP_TF0_DRP_CNT_VADDR                               	(0xb801401c)
#define  TP_TF0_ERR_CNT_VADDR                               	(0xb8014020)
#define  TP_TF0_FRMCFG_VADDR                                	(0xb8014024)
#define  TP_TF0_INT_VADDR                                   	(0xb8014028)
#define  TP_TF0_INT_EN_VADDR                                	(0xb801402c)
#define  TP_TF1_CNTL_VADDR                                  	(0xb8014030)
#define  TP_TF1_STRM_ID_0_VADDR                             	(0xb8014034)
#define  TP_TF1_STRM_ID_1_VADDR                             	(0xb8014038)
#define  TP_TF1_STRM_ID_2_VADDR                             	(0xb801403c)
#define  TP_TF1_STRM_ID_3_VADDR                             	(0xb8014040)
#define  TP_TF1_STRM_VAL_VADDR                              	(0xb8014044)
#define  TP_TF1_CNT_VADDR                                   	(0xb8014048)
#define  TP_TF1_DRP_CNT_VADDR                               	(0xb801404c)
#define  TP_TF1_ERR_CNT_VADDR                               	(0xb8014050)
#define  TP_TF1_FRMCFG_VADDR                                	(0xb8014054)
#define  TP_TF1_INT_VADDR                                   	(0xb8014058)
#define  TP_TF1_INT_EN_VADDR                                	(0xb801405c)
#define  TP_TF_OUT_FRMCFG_VADDR                             	(0xb8014060)
#define  TP_OUT_CTRL_VADDR                                  	(0xb8014064)
#define  TP_TF2_CNTL_VADDR                                  	(0xb8014068)
#define  TP_TF2_FRMCFG_VADDR                                	(0xb80140cc)
#define  TP_PCR_90K_CNT_HIGH_VADDR                          	(0xb801406c)
#define  TP_PCR_90K_CNT_VADDR                               	(0xb8014070)
#define  TP0_PCR_CTL_VADDR                                  	(0xb8014074)
#define  TP1_PCR_CTL_VADDR                                  	(0xb8014078)
#define  TP_PCR_LATCH_VADDR                                 	(0xb801407c)
#define  TP_PCR_BASE_VADDR                                  	(0xb8014080)
#define  TP_PCR_EXT_VADDR                                   	(0xb8014084)
#define  TP_PCR_SYSTEM_VADDR                                	(0xb8014088)
#define  TP_PID_PART_VADDR                                  	(0xb8014090)
#define  TP_PID_CTRL_VADDR                                  	(0xb8014094)
#define  TP_PID_DATA_VADDR                                  	(0xb8014098)
#define  TP_PID_DATA2_VADDR                                 	(0xb801409c)
#define  TP_SEC_CTRL_VADDR                                  	(0xb80140a0)
#define  TP_SEC_DATA0_VADDR                                 	(0xb80140a4)
#define  TP_SEC_DATA1_VADDR                                 	(0xb80140a8)
#define  TP_SEC_DATA2_VADDR                                 	(0xb80140ac)
#define  TP_SEC_DATA3_VADDR                                 	(0xb80140b0)
#define  TP_SEC_DATA4_VADDR                                 	(0xb80140b4)
#define  TP_SEC_DATA5_VADDR                                 	(0xb80140b8)
#define  TP_SEC_DATA6_VADDR                                 	(0xb80140bc)
#define  TP_SEC_DATA7_VADDR                                 	(0xb80140c0)
#define  TP_SEC_DATA8_VADDR                                 	(0xb80140c4)
#define  TP_SEC_DATA9_VADDR                                 	(0xb80140c8)
#define  TP_TP0_DES_CNTL_VADDR                              	(0xb80140d0)
#define  TP_KEY_INFO_VADDR                                  	(0xb80140d4)
#define  TP_KEY_CTRL_VADDR                                  	(0xb80140dc)
#define  TP_TP1_DES_CNTL_VADDR                              	(0xb80140e0)
#define  TP_CRC_INIT_VADDR                                  	(0xb80140e8)
#define  TP_THRESHOLD_VADDR                                 	(0xb80140f0)
#define  TP_FULLNESS_VADDR                                  	(0xb80140f4)
#define  TP_RING_CTRL_VADDR                                 	(0xb80140fc)
#define  TP_RING_LIMIT_VADDR                                	(0xb8014100)
#define  TP_RING_BASE_VADDR                                 	(0xb8014104)
#define  TP_RING_RP_VADDR                                   	(0xb8014108)
#define  TP_RING_WP_VADDR                                   	(0xb801410c)
#define  TP_RING_AVAIL_INT_VADDR                            	(0xb8014110)
#define  TP_RING_FULL_INT_VADDR                             	(0xb8014120)
#define  TP_RING_AVAIL_INT_EN_VADDR                         	(0xb8014204)
#define  TP_RING_FULL_INT_EN_VADDR                          	(0xb8014214)
#define  TP_M2M_RING_LIMIT_VADDR                            	(0xb8014224)
#define  TP_M2M_RING_BASE_VADDR                             	(0xb8014130)
#define  TP_M2M_RING_RP_VADDR                               	(0xb8014134)
#define  TP_M2M_RING_WP_VADDR                               	(0xb8014138)
#define  TP_M2M_RING_CTRL_VADDR                             	(0xb801413c)
#define  TP_SYNC_POS_VADDR                                  	(0xb8014140)
#define  TP_DMY_A_VADDR                                     	(0xb8014144)
#define  TP_DMY_B_VADDR                                     	(0xb8014148)
#define  BIST_MODE_VADDR                                    	(0xb8014150)
#define  BIST_DONE_VADDR                                    	(0xb8014154)
#define  BIST_FAIL_GROUP_VADDR                              	(0xb8014158)
#define  BIST_FAIL_VADDR                                    	(0xb801415c)
#define  DRF_MODE_VADDR                                     	(0xb8014164)
#define  DRF_RESUME_VADDR                                   	(0xb8014168)
#define  DRF_DONE_VADDR                                     	(0xb801416c)
#define  DRF_PAUSE_VADDR                                    	(0xb8014170)
#define  DRF_FAIL_GROUP_VADDR                               	(0xb8014174)
#define  DRF_FAIL_VADDR                                     	(0xb8014178)
#define  BIST_DVSE_VADDR                                    	(0xb8014180)
#define  BIST_DVS_VADDR                                     	(0xb8014184)
#define  TP_TF0_DETECT_1_VADDR                              	(0xb8014188)
#define  TP_TF0_DETECT_2_VADDR                              	(0xb801418c)
#define  TP_TF0_DETECT_3_VADDR                              	(0xb8014190)
#define  TP_TF0_DETECT_4_VADDR                              	(0xb8014194)
#define  TP_TF0_DETECT_5_VADDR                              	(0xb8014198)
#define  TP_TF0_DETECT_6_VADDR                              	(0xb801419c)
#define  TP_TF0_DETECT_7_VADDR                              	(0xb80141a0)
#define  TP_TF0_DETECT_8_VADDR                              	(0xb80141a4)
#define  TP_TF0_DETECT_9_VADDR                              	(0xb80141a8)
#define  TP_TF0_DETECT_10_VADDR                             	(0xb80141ac)
#define  TP_TF0_DETECT_11_VADDR                             	(0xb80141b0)
#define  TP_TF0_DETECT_12_VADDR                             	(0xb80141b4)
#define  TP_TF0_DETECT_13_VADDR                             	(0xb80141b8)
#define  TP_TF0_DETECT_CTRL_VADDR                           	(0xb80141bc)
#define  TP_TF1_DETECT_1_VADDR                              	(0xb80141c0)
#define  TP_TF1_DETECT_2_VADDR                              	(0xb80141c4)
#define  TP_TF1_DETECT_3_VADDR                              	(0xb80141c8)
#define  TP_TF1_DETECT_4_VADDR                              	(0xb80141cc)
#define  TP_TF1_DETECT_5_VADDR                              	(0xb80141d0)
#define  TP_TF1_DETECT_6_VADDR                              	(0xb80141d4)
#define  TP_TF1_DETECT_7_VADDR                              	(0xb80141d8)
#define  TP_TF1_DETECT_8_VADDR                              	(0xb80141dc)
#define  TP_TF1_DETECT_9_VADDR                              	(0xb80141e0)
#define  TP_TF1_DETECT_10_VADDR                             	(0xb80141e4)
#define  TP_TF1_DETECT_11_VADDR                             	(0xb80141e8)
#define  TP_TF1_DETECT_12_VADDR                             	(0xb80141ec)
#define  TP_TF1_DETECT_13_VADDR                             	(0xb80141f0)
#define  TP_TF1_DETECT_CTRL_VADDR                           	(0xb80141f4)
#define  TP_DUMMY_1_VADDR                                   	(0xb80141f8)
#define  TP_DUMMY_2_VADDR                                   	(0xb80141fc)
#define  TP_DEBUG_VADDR                                     	(0xb8014200)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======TP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tf0_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tf0_strm_id_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tf0_strm_id_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tf0_strm_id_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tf0_strm_id_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  val_set33:1;
        RBus_UInt32  val_set32:1;
        RBus_UInt32  val_set31:1;
        RBus_UInt32  val_set30:1;
        RBus_UInt32  val_set23:1;
        RBus_UInt32  val_set22:1;
        RBus_UInt32  val_set21:1;
        RBus_UInt32  val_set20:1;
        RBus_UInt32  val_set13:1;
        RBus_UInt32  val_set12:1;
        RBus_UInt32  val_set11:1;
        RBus_UInt32  val_set10:1;
        RBus_UInt32  val_set03:1;
        RBus_UInt32  val_set02:1;
        RBus_UInt32  val_set01:1;
        RBus_UInt32  val_set00:1;
    };
}tp_tf0_strm_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt:24;
    };
}tp_tf0_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  drp_cnt:16;
    };
}tp_tf0_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  err_cnt:16;
    };
}tp_tf0_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_byte:8;
        RBus_UInt32  dropno:4;
        RBus_UInt32  lockno:4;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  data_order:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  serial:1;
        RBus_UInt32  datapin:1;
        RBus_UInt32  err_pol:1;
        RBus_UInt32  sync_pol:1;
        RBus_UInt32  val_pol:1;
        RBus_UInt32  clk_pol:1;
    };
}tp_tf0_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  write_data:1;
    };
}tp_tf0_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tf0_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tf1_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tf1_strm_id_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tf1_strm_id_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tf1_strm_id_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tf1_strm_id_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  val_set33:1;
        RBus_UInt32  val_set32:1;
        RBus_UInt32  val_set31:1;
        RBus_UInt32  val_set30:1;
        RBus_UInt32  val_set23:1;
        RBus_UInt32  val_set22:1;
        RBus_UInt32  val_set21:1;
        RBus_UInt32  val_set20:1;
        RBus_UInt32  val_set13:1;
        RBus_UInt32  val_set12:1;
        RBus_UInt32  val_set11:1;
        RBus_UInt32  val_set10:1;
        RBus_UInt32  val_set03:1;
        RBus_UInt32  val_set02:1;
        RBus_UInt32  val_set01:1;
        RBus_UInt32  val_set00:1;
    };
}tp_tf1_strm_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt:24;
    };
}tp_tf1_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  drp_cnt:16;
    };
}tp_tf1_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  err_cnt:16;
    };
}tp_tf1_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_byte:8;
        RBus_UInt32  dropno:4;
        RBus_UInt32  lockno:4;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  data_order:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  serial:1;
        RBus_UInt32  datapin:1;
        RBus_UInt32  err_pol:1;
        RBus_UInt32  sync_pol:1;
        RBus_UInt32  val_pol:1;
        RBus_UInt32  clk_pol:1;
    };
}tp_tf1_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  write_data:1;
    };
}tp_tf1_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tf1_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  byps_tperr_en:1;
        RBus_UInt32  tperr_bit_sel:1;
        RBus_UInt32  in_tp_out_en:1;
        RBus_UInt32  in_tp_rst:1;
        RBus_UInt32  data_src:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  in_data_order:1;
        RBus_UInt32  in_serial:1;
        RBus_UInt32  in_datapin:1;
        RBus_UInt32  in_err_pol:1;
        RBus_UInt32  in_sync_pol:1;
        RBus_UInt32  in_val_pol:1;
        RBus_UInt32  in_clk_pol:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  out_data_order:1;
        RBus_UInt32  out_serial:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  out_err_pol:1;
        RBus_UInt32  out_sync_pol:1;
        RBus_UInt32  out_val_pol:1;
        RBus_UInt32  out_clk_pol:1;
    };
}tp_tf_out_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  sync_dur:1;
        RBus_UInt32  ck_gate:1;
        RBus_UInt32  tp_frame_rate:13;
        RBus_UInt32  tp_clk_div:5;
    };
}tp_out_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tf2_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  res2:6;
    };
}tp_tf2_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcr_90k_cnt_high:32;
    };
}tp_pcr_90k_cnt_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcr_90k_cnt:32;
    };
}tp_pcr_90k_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  stc_cnt_sel:1;
        RBus_UInt32  stc_64bit_en:1;
        RBus_UInt32  extra_func_ena:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  extra_pid_addr:7;
    };
}tp0_pcr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  extra_func_ena:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  extra_pid_addr:7;
    };
}tp1_pcr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  latch_ena:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  latch_sel:2;
    };
}tp_pcr_latch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcr_base_lo:32;
    };
}tp_pcr_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  pcr_base_hi:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  pcr_ext:9;
    };
}tp_pcr_ext_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  system_ts:32;
    };
}tp_pcr_system_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  partition1:7;
    };
}tp_pid_part_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  r_w:1;
        RBus_UInt32  idx:7;
    };
}tp_pid_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  si_en:1;
        RBus_UInt32  pid_ini:1;
        RBus_UInt32  ai_en:1;
        RBus_UInt32  ti_en:1;
        RBus_UInt32  sec_idx:6;
        RBus_UInt32  sec_en:1;
        RBus_UInt32  ddr_q_en:1;
        RBus_UInt32  ddr_q:5;
        RBus_UInt32  cc_en:1;
        RBus_UInt32  v:1;
        RBus_UInt32  pid:13;
    };
}tp_pid_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  info_q_en:1;
        RBus_UInt32  pre_des:1;
        RBus_UInt32  key:5;
        RBus_UInt32  reversed:2;
        RBus_UInt32  info_q:5;
    };
}tp_pid_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  r_w:1;
        RBus_UInt32  idx:6;
    };
}tp_sec_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_value_msb:32;
    };
}tp_sec_data0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_value_lsb:32;
    };
}tp_sec_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_value_msb:32;
    };
}tp_sec_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_value_lsb:32;
    };
}tp_sec_data3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  sp_filter:2;
        RBus_UInt32  sp_mask:2;
        RBus_UInt32  crc_en:1;
        RBus_UInt32  p_d:1;
        RBus_UInt32  p_n:1;
        RBus_UInt32  last:1;
        RBus_UInt32  next_sec:6;
    };
}tp_sec_data4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_filter_value_msb:32;
    };
}tp_sec_data5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_filter_value_lsb:32;
    };
}tp_sec_data6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_mask_value_msb:32;
    };
}tp_sec_data7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_mask_value_lsb:32;
    };
}tp_sec_data8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  neg_sp_filter:2;
        RBus_UInt32  neg_sp_mask:2;
        RBus_UInt32  res2:8;
        RBus_UInt32  filter_sel:2;
    };
}tp_sec_data9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ofb_mode:2;
        RBus_UInt32  csa_mode:2;
        RBus_UInt32  round:8;
        RBus_UInt32  multi2_mode:1;
        RBus_UInt32  map_11:1;
        RBus_UInt32  map_10:1;
        RBus_UInt32  map_01:1;
        RBus_UInt32  des_mode:1;
        RBus_UInt32  mode:3;
    };
}tp_tp0_des_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key_info:32;
    };
}tp_key_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  r_w:1;
        RBus_UInt32  idx:7;
    };
}tp_key_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ofb_mode:2;
        RBus_UInt32  csa_mode:2;
        RBus_UInt32  round:8;
        RBus_UInt32  multi2_mode:1;
        RBus_UInt32  map_11:1;
        RBus_UInt32  map_10:1;
        RBus_UInt32  map_01:1;
        RBus_UInt32  des_mode:1;
        RBus_UInt32  mode:3;
    };
}tp_tp1_des_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_init:32;
    };
}tp_crc_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  threshold:27;
    };
}tp_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  fullness:27;
    };
}tp_fullness_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  wm:4;
        RBus_UInt32  r_w:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  idx:5;
    };
}tp_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ring_limit:27;
        RBus_UInt32  res2:3;
    };
}tp_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ring_base:27;
        RBus_UInt32  res2:3;
    };
}tp_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ring_rp:30;
    };
}tp_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ring_wp:30;
    };
}tp_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  ring_avail_15:1;
        RBus_UInt32  ring_avail_14:1;
        RBus_UInt32  ring_avail_13:1;
        RBus_UInt32  ring_avail_12:1;
        RBus_UInt32  ring_avail_11:1;
        RBus_UInt32  ring_avail_10:1;
        RBus_UInt32  ring_avail_9:1;
        RBus_UInt32  ring_avail_8:1;
        RBus_UInt32  ring_avail_7:1;
        RBus_UInt32  ring_avail_6:1;
        RBus_UInt32  ring_avail_5:1;
        RBus_UInt32  ring_avail_4:1;
        RBus_UInt32  ring_avail_3:1;
        RBus_UInt32  ring_avail_2:1;
        RBus_UInt32  ring_avail_1:1;
        RBus_UInt32  ring_avail_0:1;
        RBus_UInt32  write_data:1;
    };
}tp_ring_avail_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  ring_full_15:1;
        RBus_UInt32  ring_full_14:1;
        RBus_UInt32  ring_full_13:1;
        RBus_UInt32  ring_full_12:1;
        RBus_UInt32  ring_full_11:1;
        RBus_UInt32  ring_full_10:1;
        RBus_UInt32  ring_full_9:1;
        RBus_UInt32  ring_full_8:1;
        RBus_UInt32  ring_full_7:1;
        RBus_UInt32  ring_full_6:1;
        RBus_UInt32  ring_full_5:1;
        RBus_UInt32  ring_full_4:1;
        RBus_UInt32  ring_full_3:1;
        RBus_UInt32  ring_full_2:1;
        RBus_UInt32  ring_full_1:1;
        RBus_UInt32  ring_full_0:1;
        RBus_UInt32  write_data:1;
    };
}tp_ring_full_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  ring_avail_15_en:1;
        RBus_UInt32  ring_avail_14_en:1;
        RBus_UInt32  ring_avail_13_en:1;
        RBus_UInt32  ring_avail_12_en:1;
        RBus_UInt32  ring_avail_11_en:1;
        RBus_UInt32  ring_avail_10_en:1;
        RBus_UInt32  ring_avail_9_en:1;
        RBus_UInt32  ring_avail_8_en:1;
        RBus_UInt32  ring_avail_7_en:1;
        RBus_UInt32  ring_avail_6_en:1;
        RBus_UInt32  ring_avail_5_en:1;
        RBus_UInt32  ring_avail_4_en:1;
        RBus_UInt32  ring_avail_3_en:1;
        RBus_UInt32  ring_avail_2_en:1;
        RBus_UInt32  ring_avail_1_en:1;
        RBus_UInt32  ring_avail_0_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_ring_avail_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  ring_full_15_en:1;
        RBus_UInt32  ring_full_14_en:1;
        RBus_UInt32  ring_full_13_en:1;
        RBus_UInt32  ring_full_12_en:1;
        RBus_UInt32  ring_full_11_en:1;
        RBus_UInt32  ring_full_10_en:1;
        RBus_UInt32  ring_full_9_en:1;
        RBus_UInt32  ring_full_8_en:1;
        RBus_UInt32  ring_full_7_en:1;
        RBus_UInt32  ring_full_6_en:1;
        RBus_UInt32  ring_full_5_en:1;
        RBus_UInt32  ring_full_4_en:1;
        RBus_UInt32  ring_full_3_en:1;
        RBus_UInt32  ring_full_2_en:1;
        RBus_UInt32  ring_full_1_en:1;
        RBus_UInt32  ring_full_0_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_ring_full_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ring_limit:27;
        RBus_UInt32  res2:3;
    };
}tp_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ring_base:27;
        RBus_UInt32  res2:3;
    };
}tp_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ring_rp:30;
    };
}tp_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ring_wp:30;
    };
}tp_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  empty:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  stop:1;
        RBus_UInt32  go:1;
        RBus_UInt32  write_data:1;
    };
}tp_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  sync_pos:30;
    };
}tp_sync_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:32;
    };
}tp_dmy_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:32;
    };
}tp_dmy_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ls:1;
        RBus_UInt32  bist_mode_tp:1;
    };
}bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_done_tp:1;
    };
}bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  tp_bist_fail_group_tp:1;
    };
}bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  tp_bist_dma_fail_0:1;
        RBus_UInt32  tp_bist_ri_sram:1;
        RBus_UInt32  tp_bist_reg_crc_sram_fail_2:1;
        RBus_UInt32  tp_bist_reg_crc_sram_fail_1:1;
        RBus_UInt32  tp_bist_reg_crc_sram_fail_0:1;
    };
}bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_mode_tp:1;
    };
}drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_resume_tp:1;
    };
}drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_done_tp:1;
    };
}drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_pause_tp:1;
    };
}drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_fail_group_tp:1;
    };
}drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  tp_drf_dma_fail_0:1;
        RBus_UInt32  tp_drf_ri_sram_fail:1;
        RBus_UInt32  tp_drf_reg_crc_sram_fail_2:1;
        RBus_UInt32  tp_drf_reg_crc_sram_fail_1:1;
        RBus_UInt32  tp_drf_reg_crc_sram_fail_0:1;
    };
}drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  tp_dvse_dma0:1;
        RBus_UInt32  tp_dvse_ri_sram:1;
        RBus_UInt32  tp_dvse_reg_crc_sram2:1;
        RBus_UInt32  tp_dvse_reg_crc_sram1:1;
        RBus_UInt32  tp_dvse_reg_crc_sram0:1;
    };
}bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  tp_dvs_dma0:4;
        RBus_UInt32  tp_dvs_ri_sram:4;
        RBus_UInt32  tp_dvs_reg_crc_sram2:4;
        RBus_UInt32  tp_dvs_reg_crc_sram1:4;
        RBus_UInt32  tp_dvs_reg_crc_sram0:4;
    };
}bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  delay_cnt_status:24;
    };
}tp_tf0_detect_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  detect_delay:8;
        RBus_UInt32  detect_en:1;
        RBus_UInt32  detect_start:1;
    };
}tp_tf0_detect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  delay_cnt_status:24;
    };
}tp_tf1_detect_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  detect_delay:8;
        RBus_UInt32  detect_en:1;
        RBus_UInt32  detect_start:1;
    };
}tp_tf1_detect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180141f8_31_0:32;
    };
}tp_dummy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180141fc_31_0:32;
    };
}tp_dummy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dv_verify_only:1;
        RBus_UInt32  tp_sram_sleep_off:1;
        RBus_UInt32  tp_pkt_sram_addr_rst_sel:1;
        RBus_UInt32  dbg_mode:5;
    };
}tp_debug_RBUS;

#else //apply LITTLE_ENDIAN

//======MACARTHUR3_DESIGNSPEC_TP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  res1:14;
    };
}tp_tf0_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tf0_strm_id_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tf0_strm_id_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tf0_strm_id_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tf0_strm_id_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  val_set00:1;
        RBus_UInt32  val_set01:1;
        RBus_UInt32  val_set02:1;
        RBus_UInt32  val_set03:1;
        RBus_UInt32  val_set10:1;
        RBus_UInt32  val_set11:1;
        RBus_UInt32  val_set12:1;
        RBus_UInt32  val_set13:1;
        RBus_UInt32  val_set20:1;
        RBus_UInt32  val_set21:1;
        RBus_UInt32  val_set22:1;
        RBus_UInt32  val_set23:1;
        RBus_UInt32  val_set30:1;
        RBus_UInt32  val_set31:1;
        RBus_UInt32  val_set32:1;
        RBus_UInt32  val_set33:1;
        RBus_UInt32  res1:16;
    };
}tp_tf0_strm_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:24;
        RBus_UInt32  res1:8;
    };
}tp_tf0_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drp_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tf0_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tf0_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_pol:1;
        RBus_UInt32  val_pol:1;
        RBus_UInt32  sync_pol:1;
        RBus_UInt32  err_pol:1;
        RBus_UInt32  datapin:1;
        RBus_UInt32  serial:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  data_order:1;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  lockno:4;
        RBus_UInt32  dropno:4;
        RBus_UInt32  sync_byte:8;
    };
}tp_tf0_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  res1:27;
    };
}tp_tf0_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  res1:27;
    };
}tp_tf0_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  res1:14;
    };
}tp_tf1_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tf1_strm_id_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tf1_strm_id_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tf1_strm_id_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tf1_strm_id_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  val_set00:1;
        RBus_UInt32  val_set01:1;
        RBus_UInt32  val_set02:1;
        RBus_UInt32  val_set03:1;
        RBus_UInt32  val_set10:1;
        RBus_UInt32  val_set11:1;
        RBus_UInt32  val_set12:1;
        RBus_UInt32  val_set13:1;
        RBus_UInt32  val_set20:1;
        RBus_UInt32  val_set21:1;
        RBus_UInt32  val_set22:1;
        RBus_UInt32  val_set23:1;
        RBus_UInt32  val_set30:1;
        RBus_UInt32  val_set31:1;
        RBus_UInt32  val_set32:1;
        RBus_UInt32  val_set33:1;
        RBus_UInt32  res1:16;
    };
}tp_tf1_strm_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:24;
        RBus_UInt32  res1:8;
    };
}tp_tf1_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drp_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tf1_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tf1_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_pol:1;
        RBus_UInt32  val_pol:1;
        RBus_UInt32  sync_pol:1;
        RBus_UInt32  err_pol:1;
        RBus_UInt32  datapin:1;
        RBus_UInt32  serial:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  data_order:1;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  lockno:4;
        RBus_UInt32  dropno:4;
        RBus_UInt32  sync_byte:8;
    };
}tp_tf1_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  res1:27;
    };
}tp_tf1_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  res1:27;
    };
}tp_tf1_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  out_clk_pol:1;
        RBus_UInt32  out_val_pol:1;
        RBus_UInt32  out_sync_pol:1;
        RBus_UInt32  out_err_pol:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  out_serial:1;
        RBus_UInt32  out_data_order:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  in_clk_pol:1;
        RBus_UInt32  in_val_pol:1;
        RBus_UInt32  in_sync_pol:1;
        RBus_UInt32  in_err_pol:1;
        RBus_UInt32  in_datapin:1;
        RBus_UInt32  in_serial:1;
        RBus_UInt32  in_data_order:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  data_src:2;
        RBus_UInt32  in_tp_rst:1;
        RBus_UInt32  in_tp_out_en:1;
        RBus_UInt32  tperr_bit_sel:1;
        RBus_UInt32  byps_tperr_en:1;
        RBus_UInt32  res4:10;
    };
}tp_tf_out_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_clk_div:5;
        RBus_UInt32  tp_frame_rate:13;
        RBus_UInt32  ck_gate:1;
        RBus_UInt32  sync_dur:1;
        RBus_UInt32  res1:12;
    };
}tp_out_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  res1:30;
    };
}tp_tf2_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  res2:21;
    };
}tp_tf2_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcr_90k_cnt_high:32;
    };
}tp_pcr_90k_cnt_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcr_90k_cnt:32;
    };
}tp_pcr_90k_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  extra_pid_addr:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  extra_func_ena:1;
        RBus_UInt32  stc_64bit_en:1;
        RBus_UInt32  stc_cnt_sel:1;
        RBus_UInt32  res2:21;
    };
}tp0_pcr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  extra_pid_addr:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  extra_func_ena:1;
        RBus_UInt32  res2:23;
    };
}tp1_pcr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  latch_sel:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  latch_ena:1;
        RBus_UInt32  res2:23;
    };
}tp_pcr_latch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcr_base_lo:32;
    };
}tp_pcr_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcr_ext:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  pcr_base_hi:1;
        RBus_UInt32  res2:15;
    };
}tp_pcr_ext_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  system_ts:32;
    };
}tp_pcr_system_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  partition1:7;
        RBus_UInt32  res1:25;
    };
}tp_pid_part_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idx:7;
        RBus_UInt32  r_w:1;
        RBus_UInt32  res1:24;
    };
}tp_pid_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pid:13;
        RBus_UInt32  v:1;
        RBus_UInt32  cc_en:1;
        RBus_UInt32  ddr_q:5;
        RBus_UInt32  ddr_q_en:1;
        RBus_UInt32  sec_en:1;
        RBus_UInt32  sec_idx:6;
        RBus_UInt32  ti_en:1;
        RBus_UInt32  ai_en:1;
        RBus_UInt32  pid_ini:1;
        RBus_UInt32  si_en:1;
    };
}tp_pid_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  info_q:5;
        RBus_UInt32  reversed:2;
        RBus_UInt32  key:5;
        RBus_UInt32  pre_des:1;
        RBus_UInt32  info_q_en:1;
        RBus_UInt32  res1:18;
    };
}tp_pid_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idx:6;
        RBus_UInt32  r_w:1;
        RBus_UInt32  res1:25;
    };
}tp_sec_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_value_msb:32;
    };
}tp_sec_data0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_value_lsb:32;
    };
}tp_sec_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_value_msb:32;
    };
}tp_sec_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_value_lsb:32;
    };
}tp_sec_data3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  next_sec:6;
        RBus_UInt32  last:1;
        RBus_UInt32  p_n:1;
        RBus_UInt32  p_d:1;
        RBus_UInt32  crc_en:1;
        RBus_UInt32  sp_mask:2;
        RBus_UInt32  sp_filter:2;
        RBus_UInt32  res1:18;
    };
}tp_sec_data4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_filter_value_msb:32;
    };
}tp_sec_data5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_filter_value_lsb:32;
    };
}tp_sec_data6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_mask_value_msb:32;
    };
}tp_sec_data7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_mask_value_lsb:32;
    };
}tp_sec_data8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_sel:2;
        RBus_UInt32  res1:8;
        RBus_UInt32  neg_sp_mask:2;
        RBus_UInt32  neg_sp_filter:2;
        RBus_UInt32  res2:18;
    };
}tp_sec_data9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode:3;
        RBus_UInt32  des_mode:1;
        RBus_UInt32  map_01:1;
        RBus_UInt32  map_10:1;
        RBus_UInt32  map_11:1;
        RBus_UInt32  multi2_mode:1;
        RBus_UInt32  round:8;
        RBus_UInt32  csa_mode:2;
        RBus_UInt32  ofb_mode:2;
        RBus_UInt32  res1:12;
    };
}tp_tp0_des_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key_info:32;
    };
}tp_key_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idx:7;
        RBus_UInt32  r_w:1;
        RBus_UInt32  res1:24;
    };
}tp_key_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode:3;
        RBus_UInt32  des_mode:1;
        RBus_UInt32  map_01:1;
        RBus_UInt32  map_10:1;
        RBus_UInt32  map_11:1;
        RBus_UInt32  multi2_mode:1;
        RBus_UInt32  round:8;
        RBus_UInt32  csa_mode:2;
        RBus_UInt32  ofb_mode:2;
        RBus_UInt32  res1:12;
    };
}tp_tp1_des_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_init:32;
    };
}tp_crc_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  threshold:27;
        RBus_UInt32  res1:5;
    };
}tp_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fullness:27;
        RBus_UInt32  res1:5;
    };
}tp_fullness_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idx:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  r_w:1;
        RBus_UInt32  wm:4;
        RBus_UInt32  res2:21;
    };
}tp_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:27;
        RBus_UInt32  res2:2;
    };
}tp_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:27;
        RBus_UInt32  res2:2;
    };
}tp_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:30;
        RBus_UInt32  res1:2;
    };
}tp_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:30;
        RBus_UInt32  res1:2;
    };
}tp_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_avail_0:1;
        RBus_UInt32  ring_avail_1:1;
        RBus_UInt32  ring_avail_2:1;
        RBus_UInt32  ring_avail_3:1;
        RBus_UInt32  ring_avail_4:1;
        RBus_UInt32  ring_avail_5:1;
        RBus_UInt32  ring_avail_6:1;
        RBus_UInt32  ring_avail_7:1;
        RBus_UInt32  ring_avail_8:1;
        RBus_UInt32  ring_avail_9:1;
        RBus_UInt32  ring_avail_10:1;
        RBus_UInt32  ring_avail_11:1;
        RBus_UInt32  ring_avail_12:1;
        RBus_UInt32  ring_avail_13:1;
        RBus_UInt32  ring_avail_14:1;
        RBus_UInt32  ring_avail_15:1;
        RBus_UInt32  res1:15;
    };
}tp_ring_avail_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_full_0:1;
        RBus_UInt32  ring_full_1:1;
        RBus_UInt32  ring_full_2:1;
        RBus_UInt32  ring_full_3:1;
        RBus_UInt32  ring_full_4:1;
        RBus_UInt32  ring_full_5:1;
        RBus_UInt32  ring_full_6:1;
        RBus_UInt32  ring_full_7:1;
        RBus_UInt32  ring_full_8:1;
        RBus_UInt32  ring_full_9:1;
        RBus_UInt32  ring_full_10:1;
        RBus_UInt32  ring_full_11:1;
        RBus_UInt32  ring_full_12:1;
        RBus_UInt32  ring_full_13:1;
        RBus_UInt32  ring_full_14:1;
        RBus_UInt32  ring_full_15:1;
        RBus_UInt32  res1:15;
    };
}tp_ring_full_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_avail_0_en:1;
        RBus_UInt32  ring_avail_1_en:1;
        RBus_UInt32  ring_avail_2_en:1;
        RBus_UInt32  ring_avail_3_en:1;
        RBus_UInt32  ring_avail_4_en:1;
        RBus_UInt32  ring_avail_5_en:1;
        RBus_UInt32  ring_avail_6_en:1;
        RBus_UInt32  ring_avail_7_en:1;
        RBus_UInt32  ring_avail_8_en:1;
        RBus_UInt32  ring_avail_9_en:1;
        RBus_UInt32  ring_avail_10_en:1;
        RBus_UInt32  ring_avail_11_en:1;
        RBus_UInt32  ring_avail_12_en:1;
        RBus_UInt32  ring_avail_13_en:1;
        RBus_UInt32  ring_avail_14_en:1;
        RBus_UInt32  ring_avail_15_en:1;
        RBus_UInt32  res1:15;
    };
}tp_ring_avail_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_full_0_en:1;
        RBus_UInt32  ring_full_1_en:1;
        RBus_UInt32  ring_full_2_en:1;
        RBus_UInt32  ring_full_3_en:1;
        RBus_UInt32  ring_full_4_en:1;
        RBus_UInt32  ring_full_5_en:1;
        RBus_UInt32  ring_full_6_en:1;
        RBus_UInt32  ring_full_7_en:1;
        RBus_UInt32  ring_full_8_en:1;
        RBus_UInt32  ring_full_9_en:1;
        RBus_UInt32  ring_full_10_en:1;
        RBus_UInt32  ring_full_11_en:1;
        RBus_UInt32  ring_full_12_en:1;
        RBus_UInt32  ring_full_13_en:1;
        RBus_UInt32  ring_full_14_en:1;
        RBus_UInt32  ring_full_15_en:1;
        RBus_UInt32  res1:15;
    };
}tp_ring_full_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:27;
        RBus_UInt32  res2:2;
    };
}tp_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:27;
        RBus_UInt32  res2:2;
    };
}tp_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:30;
        RBus_UInt32  res1:2;
    };
}tp_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:30;
        RBus_UInt32  res1:2;
    };
}tp_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  go:1;
        RBus_UInt32  stop:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  empty:1;
        RBus_UInt32  res1:27;
    };
}tp_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_pos:30;
        RBus_UInt32  res1:2;
    };
}tp_sync_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:32;
    };
}tp_dmy_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:32;
    };
}tp_dmy_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mode_tp:1;
        RBus_UInt32  ls:1;
        RBus_UInt32  res1:30;
    };
}bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_done_tp:1;
        RBus_UInt32  res1:31;
    };
}bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_bist_fail_group_tp:1;
        RBus_UInt32  res1:31;
    };
}bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_bist_reg_crc_sram_fail_0:1;
        RBus_UInt32  tp_bist_reg_crc_sram_fail_1:1;
        RBus_UInt32  tp_bist_reg_crc_sram_fail_2:1;
        RBus_UInt32  tp_bist_ri_sram:1;
        RBus_UInt32  tp_bist_dma_fail_0:1;
        RBus_UInt32  res1:27;
    };
}bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_mode_tp:1;
        RBus_UInt32  res1:31;
    };
}drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_resume_tp:1;
        RBus_UInt32  res1:31;
    };
}drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_done_tp:1;
        RBus_UInt32  res1:31;
    };
}drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_pause_tp:1;
        RBus_UInt32  res1:31;
    };
}drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_fail_group_tp:1;
        RBus_UInt32  res1:31;
    };
}drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_drf_reg_crc_sram_fail_0:1;
        RBus_UInt32  tp_drf_reg_crc_sram_fail_1:1;
        RBus_UInt32  tp_drf_reg_crc_sram_fail_2:1;
        RBus_UInt32  tp_drf_ri_sram_fail:1;
        RBus_UInt32  tp_drf_dma_fail_0:1;
        RBus_UInt32  res1:27;
    };
}drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_dvse_reg_crc_sram0:1;
        RBus_UInt32  tp_dvse_reg_crc_sram1:1;
        RBus_UInt32  tp_dvse_reg_crc_sram2:1;
        RBus_UInt32  tp_dvse_ri_sram:1;
        RBus_UInt32  tp_dvse_dma0:1;
        RBus_UInt32  res1:27;
    };
}bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_dvs_reg_crc_sram0:4;
        RBus_UInt32  tp_dvs_reg_crc_sram1:4;
        RBus_UInt32  tp_dvs_reg_crc_sram2:4;
        RBus_UInt32  tp_dvs_ri_sram:4;
        RBus_UInt32  tp_dvs_dma0:4;
        RBus_UInt32  res1:12;
    };
}bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf0_detect_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:24;
        RBus_UInt32  res1:8;
    };
}tp_tf0_detect_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  detect_start:1;
        RBus_UInt32  detect_en:1;
        RBus_UInt32  detect_delay:8;
        RBus_UInt32  res1:22;
    };
}tp_tf0_detect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:32;
    };
}tp_tf1_detect_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cnt_status:24;
        RBus_UInt32  res1:8;
    };
}tp_tf1_detect_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  detect_start:1;
        RBus_UInt32  detect_en:1;
        RBus_UInt32  detect_delay:8;
        RBus_UInt32  res1:22;
    };
}tp_tf1_detect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180141f8_31_0:32;
    };
}tp_dummy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180141fc_31_0:32;
    };
}tp_dummy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_mode:5;
        RBus_UInt32  tp_pkt_sram_addr_rst_sel:1;
        RBus_UInt32  tp_sram_sleep_off:1;
        RBus_UInt32  dv_verify_only:1;
        RBus_UInt32  res1:24;
    };
}tp_debug_RBUS;




#endif 


#endif 
