/**
* @file rbusMagellan2_DC_PHY_Arch_SpecReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-2-5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MAGELLAN2_DC_PHY_ARCH_SPEC_REG_H_
#define _RBUS_MAGELLAN2_DC_PHY_ARCH_SPEC_REG_H_

#include "rbus_types.h"



//  MAGELLAN2_DC_PHY_ARCH_SPEC Register Address



#define  TMCTRL0_VADDR                                      	(0xb8008800)
#define  TMCTRL1_VADDR                                      	(0xb8008804)
#define  TMCTRL2_VADDR                                      	(0xb8008808)
#define  TMCTRL3_VADDR                                      	(0xb800880c)
#define  TMCTRL4_VADDR                                      	(0xb8008810)
#define  TMCTRL5_VADDR                                      	(0xb8008814)
#define  TMCTRL6_VADDR                                      	(0xb8008818)
#define  BKFEE_CTRL0_VADDR                                    (0xb800881c)
#define  ODT_CTRL_VADDR                                     	(0xb8008820)
#define  CAL_CTRL2_VADDR                                    	(0xb8008824)
#define  DC_MIS2_VADDR                                      	(0xb8008828)
#define  DC_MIS_VADDR                                       	(0xb800882c)
#define  DC_MISA_VADDR                                      	(0xb8008830)
#define  DC_MISB_VADDR                                      	(0xb8008834)
#define  DC_MISC_VADDR                                      	(0xb8008838)
#define  DC_TEST_MODE_SEL_VADDR                             	(0xb800883c)
#define  DC_DDR3_CTL_VADDR                                  	(0xb8008840)
#define  MOD_REG_VADDR                                      	(0xb8008844)
#define  MOD23_REG_VADDR                                    	(0xb8008848)
#define  RFIFO_CTL_VADDR                                    	(0xb800884c)
#define  ERR_STATUS_VADDR                                   	(0xb8008850)
#define  DC_WRITE_LEVEL_VADDR                               	(0xb8008854)
#define  INT_ENABLE_VADDR                                   	(0xb8008858)
#define  GRP_CTRL_VADDR                                     	(0xb800885c)
#define  SM_STATUS_VADDR                                    	(0xb8008860)
#define  WFIFO_CNT_VADDR                                    	(0xb8008864)
#define  DC_DEBUG_PHY_VADDR                                   (0xb8008868)
#define  ERR_STATUS_INFO_VADDR                              	(0xb800886c)
#define  INFO_INT_ENABLE_VADDR                              	(0xb8008870)
#define  WFIFO_DDR_REQ_WAIT_VADDR                           	(0xb8008874)
#define  WFIFO_MAX_REQ_WAIT_VADDR                           	(0xb8008878)
#define  AUTO_SHORT_ZQ_CAL_VADDR                            	(0xb800887c)
#define  BKFREE_CTRL1_VADDR                                 	(0xb8008880)
#define  WFIFO2_DDR_REQ_WAIT_VADDR                          	(0xb8008884)
#define  WFIFO2_MAX_REQ_WAIT_VADDR                          	(0xb8008888)
#define  PAR_DBG_SEL_VADDR                                  	(0xb80088a0)
#define  PAR_DBG_DATA_VADDR                                 	(0xb80088a4)
#define  DUMMY_REG_VADDR                                    	(0xb8008940)
#define  CAL_MODE_VADDR                                     	(0xb8008954)
#define  ANA_DLL_VADDR                                      	(0xb8008b20)
#define  LPDDR_CTRL_VADDR                                   	(0xb8008b24)
#define  LPDDR_RDAT_VADDR                                   	(0xb8008b28)
#define  LPDDR_MODE_VADDR                                   	(0xb8008b2c)
#define  FIFO_ARB_0_VADDR                                   	(0xb8008e00)
#define  FIFO_ARB_1_VADDR                                   	(0xb8008e04)
#define  FIFO_ARB_2_VADDR                                   	(0xb8008e08)
#define  FIFO_ARB_3_VADDR                                   	(0xb8008e0c)
#define  FIFO_ARB_4_VADDR                                   	(0xb8008e10)
#define  FIFO_ARB_5_VADDR                                   	(0xb8008e14)
#define  FIFO_ARB_6_VADDR                                   	(0xb8008e18)
#define  FIFO_ARB_7_VADDR                                   	(0xb8008e1c)
#define  FIFO_ARB_8_VADDR                                   	(0xb8008e20)
#define  FIFO_ARB_9_VADDR                                   	(0xb8008e24)
#define  FIFO_ARB_10_VADDR                                  	(0xb8008e28)
#define  FIFO_ARB_11_VADDR                                  	(0xb8008e2c)
#define  FIFO_ARB_13_VADDR                                  	(0xb8008e34)
#define  FIFO_ARB_16_VADDR                                  	(0xb8008e40)
#define  FIFO_ARB_17_VADDR                                  	(0xb8008e44)
#define  FIFO_ARB_18_VADDR                                  	(0xb8008e48)
#define  FIFO_ARB_19_VADDR                                  	(0xb8008e4c)
#define  FIFO_ARB_20_VADDR                                  	(0xb8008e50)
#define  FIFO_ARB_21_VADDR                                  	(0xb8008e54)
#define  FIFO_ARB_22_VADDR                                  	(0xb8008e58)
#define  FIFO_ARB_23_VADDR                                  	(0xb8008e5c)
#define  FIFO_ARB_24_VADDR                                  	(0xb8008e60)
#define  FIFO_ARB_25_VADDR                                  	(0xb8008e64)
#define  FIFO_ARB_26_VADDR                                  	(0xb8008e68)
#define  FIFO_ARB_27_VADDR                                  	(0xb8008e6c)
#define  FIFO_ARB_28_VADDR                                  	(0xb8008e70)
#define  SCRAMBLE_CTRL_VADDR                                	(0xb8008e74)
#define  SCRAMBLE_KEY_01_VADDR                              	(0xb8008e78)
#define  SCRAMBLE_KEY_23_VADDR                              	(0xb8008e7c)
#define  SCRAMBLE_KEY_45_VADDR                              	(0xb8008e80)
#define  SCRAMBLE_KEY_67_VADDR                              	(0xb8008e84)
#define  SCRAMBLE_KEY_89_VADDR                              	(0xb8008e88)
#define  SCRAMBLE_KEY_1011_VADDR                            	(0xb8008e8c)
#define  SCRAMBLE_KEY_1213_VADDR                            	(0xb8008e90)
#define  SCRAMBLE_KEY_1415_VADDR                            	(0xb8008e94)
#define  SCRAMBLE_KEY_1617_VADDR                            	(0xb8008e98)
#define  SCRAMBLE_KEY_1819_VADDR                            	(0xb8008e9c)
#define  SCRAMBLE_KEY_2021_VADDR                            	(0xb8008ea0)
#define  SCRAMBLE_KEY_2223_VADDR                            	(0xb8008ea4)
#define  SCRAMBLE_KEY_2425_VADDR                            	(0xb8008ea8)
#define  SCRAMBLE_KEY_2627_VADDR                            	(0xb8008eac)
#define  SCRAMBLE_KEY_2829_VADDR                            	(0xb8008eb0)
#define  SCRAMBLE_KEY_3031_VADDR                            	(0xb8008eb4)
#define  DUMMY_0_VADDR                                      	(0xb8008ee0)
#define  DUMMY_1_VADDR                                      	(0xb8008ee4)
#define  DUMMY_2_VADDR                                      	(0xb8008ee8)
#define  DUMMY_3_VADDR                                      	(0xb8008eec)
#define  DUMMY_4_VADDR                                      	(0xb8008ef0)
#define  DUMMY_5_VADDR                                      	(0xb8008ef4)
#define  CS_CTRL_VADDR                                      	(0xb8008ef8)
#define  CMD_DLY_1T_VADDR                                   	(0xb8008f00)
#define  EXP_LANE_CTRL_VADDR                                	(0xb8008f04)
#define  SCPU_PC_TOTA_MON_NUM_VADDR                         	(0xb8008f18)
#define  SCPU_PC_TOTA_ACK_NUM_VADDR                         	(0xb8008f1c)
#define  SCPU_PC_TOTA_IDL_NUM_VADDR                         	(0xb8008f20)
#define  SCPU_PC_ACC_LAT_VADDR                              	(0xb8008f24)
#define  SCPU_PC_MAX_LAT_VADDR                              	(0xb8008f28)
#define  SCPU_PC_REQ_NUM_VADDR                              	(0xb8008f2c)
#define  SCPU_PC_ACK_NUM_VADDR                              	(0xb8008f30)
#define  SCPU_PC_CTRL_VADDR                                 	(0xb8008f34)
#define  GCK_CTRL_VADDR                                     	(0xb8008f38)
#define  SCPU_LEAKY_BUCKET_CTRL_0_VADDR                     	(0xb8008f3c)
#define  SCPU_LEAKY_BUCKET_CTRL_1_VADDR                     	(0xb8008f40)
#define  SCPU_LEAKY_BUCKET_CTRL_2_VADDR                     	(0xb8008f44)
#define  SCPU_PC_MERGE_NUM_VADDR                            	(0xb8008f48)
#define  SCPU_PC_WR_REQ_NUM_VADDR                           	(0xb8008f4c)
#define  SPEED_SENSOR_CTRL_VADDR                            	(0xb8008f50)
#define  SPEED_SENSOR_STATUS_VADDR                          	(0xb8008f54)
#define  EXPRESS_LANE_CTRL_MISC_VADDR                       	(0xb8008f58)
#define  DEBUG01_VADDR                                      	(0xb8008f64)
#define  DEBUG23_VADDR                                      	(0xb8008f68)
#define  DC_PHY_BIST_MODE_VADDR                             	(0xb8008fc0)
#define  DC_PHY_BIST_DONE_VADDR                             	(0xb8008fc4)
#define  DC_PHY_BIST_FAIL_VADDR                             	(0xb8008fc8)
#define  DC_PHY_BIST_DRF_VADDR                              	(0xb8008fcc)
#define  DC_PHY_BIST_RESUME_VADDR                           	(0xb8008fd0)
#define  DC_PHY_BIST0_DRF_DONE_VADDR                        	(0xb8008fd4)
#define  DC_PHY_BIST_DRF_PAUSE_VADDR                        	(0xb8008fd8)
#define  DC_PHY_BIST_DRF_FAIL_VADDR                         	(0xb8008fdc)
#define  DC_PHY_BIST_DETAIL_VADDR                           	(0xb8008fe0)
#define  DC_PHY_BIST_RM_VADDR                               	(0xb8008fe4)
#define  PTG_READY_VADDR                                    	(0xb8008ff8)
#define  PTG_SELECT_VADDR                                   	(0xb8008ffc)
#define  EFF_MEAS_CTRL_VADDR                                	(0xb8008d80)
#define  READ_CMD_VADDR                                     	(0xb8008d84)
#define  WRITE_CMD_VADDR                                    	(0xb8008d88)
#define  READ_CHOP_CMD_VADDR                                	(0xb8008d8c)
#define  WRITE_CHOP_CMD_VADDR                               	(0xb8008d90)
#define  ACT_BANK_0_VADDR                                   	(0xb8008d94)
#define  PRECHG_BANK_0_VADDR                                	(0xb8008d98)
#define  ACT_BANK_1_VADDR                                   	(0xb8008d9c)
#define  PRECHG_BANK_1_VADDR                                	(0xb8008da0)
#define  ACT_BANK_2_VADDR                                   	(0xb8008da4)
#define  PRECHG_BANK_2_VADDR                                	(0xb8008da8)
#define  ACT_BANK_3_VADDR                                   	(0xb8008dac)
#define  PRECHG_BANK_3_VADDR                                	(0xb8008db0)
#define  ACT_BANK_4_VADDR                                   	(0xb8008db4)
#define  PRECHG_BANK_4_VADDR                                	(0xb8008db8)
#define  ACT_BANK_5_VADDR                                   	(0xb8008dbc)
#define  PRECHG_BANK_5_VADDR                                	(0xb8008dc0)
#define  ACT_BANK_6_VADDR                                   	(0xb8008dc4)
#define  PRECHG_BANK_6_VADDR                                	(0xb8008dc8)
#define  ACT_BANK_7_VADDR                                   	(0xb8008dcc)
#define  PRECHG_BANK_7_VADDR                                	(0xb8008dd0)
#define  WRITE_TO_READ_VADDR                                	(0xb8008dd4)
#define  READ_TO_WRITE_VADDR                                	(0xb8008dd8)
#define  WRITE_CMD_LATENCY_VADDR                            	(0xb8008ddc)
#define  READ_CMD_LATENCY_VADDR                             	(0xb8008de0)
#define  BANK_CONFLICT_VADDR                                	(0xb8008de4)
#define  WRITE_MERGE_VADDR                                  	(0xb8008de8)
#define  READ_BYPASS_VADDR                                  	(0xb8008dec)
#define  DC_SYS1_READ_BYPASS_VADDR                          	(0xb8008df0)
#define  READ_CMD_AP_VADDR                                  	(0xb8008df4)
#define  WRITE_CMD_AP_VADDR                                 	(0xb8008df8)
#define  WEIGHT_ENABLE_VADDR                                	(0xb8008b80)
#define  WEIGHT_PRIORITY_VADDR                              	(0xb8008b84)
#define  WEIGHT_DIERECTION_VADDR                            	(0xb8008b88)
#define  WEIGHT_LENGTH_VADDR                                	(0xb8008b8c)
#define  WEIGHT_BANK_VADDR                                  	(0xb8008b90)
#define  MULTI_CLIENT_VADDR                                 	(0xb8008bf0)
#define  EXPRESS_LANE_DEBUG_VADDR                           	(0xb8008bf4)
#define  WEIGHT_DEBUG_VADDR                                 	(0xb8008bf8)
#define  DDR4_CTRL_VADDR                                    	(0xb8008c00)
#define  DDR4_TM0_VADDR                                     	(0xb8008c04)
#define  DDR4_MR45_VADDR                                    	(0xb8008c08)
#define  DDR4_MR6_VADDR                                     	(0xb8008c0c)
#define  DDR4_ALERT_STATUS_VADDR                            	(0xb8008c10)
#define  DC_DDR4_CTL_VADDR                                  	(0xb8008c14)
#define  DDR4_EXE_RW_CMD_VADDR                              	(0xb8008c18)
#define  BLOCK_REQ_VADDR                                    	(0xb8008c1c)
#define  DDR4_FAIL_CMD_VADDR                                	(0xb8008c20)
#define  DDR4_MPR_RD_DAT0_VADDR                             	(0xb8008c60)
#define  DDR4_MPR_RD_DAT1_VADDR                             	(0xb8008c64)
#define  DDR4_MPR_RD_DAT2_VADDR                             	(0xb8008c68)
#define  DDR4_MPR_RD_DAT3_VADDR                             	(0xb8008c6c)
#define  DDR4_MPR_RD_DAT4_VADDR                             	(0xb8008c70)
#define  DDR4_MPR_RD_DAT5_VADDR                             	(0xb8008c74)
#define  DDR4_MPR_RD_DAT6_0_VADDR                           	(0xb8008c78)
#define  DDR4_MPR_RD_DAT6_1_VADDR                           	(0xb8008c7c)
#define  CTS_FIFO_CTRL_VADDR                                	(0xb8008c80)
#define  DC_SYS1_CTRL_VADDR                                 	(0xb8008c94)
#define  DC_SYS2_CTRL_VADDR                                 	(0xb8008c98)
#define  QOS_CTRL_VADDR                                     	(0xb8008ca0)
#define  QOS_OT_VADDR                                       	(0xb8008ca8)
#define  QOS_BW0_VADDR                                      	(0xb8008cb0)
#define  QOS_BW1_VADDR                                      	(0xb8008cb8)
#define  QOS_BW2_VADDR                                      	(0xb8008cc0)
#define  QOS_BW3_VADDR                                      	(0xb8008cc8)
#define  QOS_LAT0_VADDR                                     	(0xb8008cd0)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MAGELLAN2_DC_PHY_ARCH_SPEC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tmras:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  tmrcl:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  tmcl:6;
    };
}tmctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tmrrd:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  tmrp:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  tmrcdrd:6;
        RBus_UInt32  tmrc:8;
    };
}tmctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tmccd_r2r:4;
        RBus_UInt32  tmccd:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  trtp:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  tmwtr:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  tmwr:6;
    };
}tmctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tmfaw:8;
        RBus_UInt32  refcycle:12;
        RBus_UInt32  res1:1;
        RBus_UInt32  tmrfc:11;
    };
}tmctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  taond:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  taofd:6;
        RBus_UInt32  tmmod:8;
        RBus_UInt32  res3:3;
        RBus_UInt32  tmmrd:5;
    };
}tmctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tzqoper:12;
        RBus_UInt32  tzqinit:12;
    };
}tmctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  tdllk:12;
        RBus_UInt32  tzqcs:12;
    };
}tmctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  odt_post_3t_en:1;
        RBus_UInt32  odt_post_2t_en:1;
        RBus_UInt32  odt_post_1t_en:1;
        RBus_UInt32  odt_pre_1t_en:1;
        RBus_UInt32  odt_first_cycle_dis:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  odt_force_sel:1;
        RBus_UInt32  odt_force_sig:1;
        RBus_UInt32  odt_en:1;
        RBus_UInt32  odt_dis:1;
        RBus_UInt32  res4:5;
        RBus_UInt32  res5:15;
    };
}odt_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  res2:6;
        RBus_UInt32  res3:8;
    };
}cal_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  issue_nop_after_sre:1;
        RBus_UInt32  init:1;
        RBus_UInt32  sren:1;
        RBus_UInt32  srex:1;
        RBus_UInt32  exe_emr:1;
        RBus_UInt32  exe_mr:1;
    };
}dc_mis2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tmrcdwr:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:12;
    };
}dc_mis_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ref_after_last_cmd:1;
        RBus_UInt32  pre_dis:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  lbk_en:1;
        RBus_UInt32  res3:2;
    };
}dc_misa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tmrc_sel:1;
        RBus_UInt32  res2:28;
    };
}dc_misb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:24;
    };
}dc_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
    };
}dc_test_mode_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_en_15:1;
        RBus_UInt32  dis_ap:1;
        RBus_UInt32  write_en_14:1;
        RBus_UInt32  ddr3_swap:1;
        RBus_UInt32  write_en_13:1;
        RBus_UInt32  end_500us:1;
        RBus_UInt32  write_en_12:1;
        RBus_UInt32  end_200us:1;
        RBus_UInt32  write_en_11:1;
        RBus_UInt32  fast_prechg:1;
        RBus_UInt32  write_en_10:1;
        RBus_UInt32  dis_cti:1;
        RBus_UInt32  write_en_9:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  write_en_8:1;
        RBus_UInt32  use_tmmrd:1;
        RBus_UInt32  write_en_7:1;
        RBus_UInt32  dis_pre_all:1;
        RBus_UInt32  write_en_6:1;
        RBus_UInt32  ddr3_zqcl_short:1;
        RBus_UInt32  write_en_5:1;
        RBus_UInt32  ddr3_exe_zqcl:1;
        RBus_UInt32  write_en_4:1;
        RBus_UInt32  ddr3_exe_mr3:1;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  ddr3_exe_mr2:1;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  ddr3_exe_mr1:1;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  ddr3_exe_mr0:1;
        RBus_UInt32  write_en_0:1;
        RBus_UInt32  ddr3_init:1;
    };
}dc_ddr3_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  exmod_reg:16;
        RBus_UInt32  mod_reg:16;
    };
}mod_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod3_reg:16;
        RBus_UInt32  mod2_reg:16;
    };
}mod23_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  wfifo_rdy_gated:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rdwr_use_full:1;
        RBus_UInt32  full_gated:1;
        RBus_UInt32  rfifo_thred:7;
    };
}rfifo_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  express_lane_qfifo_overflow:1;
        RBus_UInt32  express_lane_qfifo_underflow:1;
        RBus_UInt32  express_lane_wfifo_overflow:1;
        RBus_UInt32  express_lane_wfifo_underflow:1;
        RBus_UInt32  exp_rfifo_overflow:1;
        RBus_UInt32  sys2_rfifo_overflow:1;
        RBus_UInt32  sys1_rfifo_overflow:1;
        RBus_UInt32  ddr4_parity_err_1:1;
        RBus_UInt32  ddr4_crc_err_1:1;
        RBus_UInt32  ddr4_parity_err_0:1;
        RBus_UInt32  ddr4_crc_err_0:1;
        RBus_UInt32  sys2_wfifo_underflow:1;
        RBus_UInt32  sys2_wfifo_overflow:1;
        RBus_UInt32  sys1_wfifo_underflow:1;
        RBus_UInt32  sys1_wfifo_overflow:1;
        RBus_UInt32  sys2_qfifo_underflow:1;
        RBus_UInt32  sys2_qfifo_overflow:1;
        RBus_UInt32  sys1_qfifo_underflow:1;
        RBus_UInt32  sys1_qfifo_overflow:1;
        RBus_UInt32  err_cti_cmd:1;
        RBus_UInt32  err_active:1;
    };
}err_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  exe_prea:1;
        RBus_UInt32  dis_refresh:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
    };
}dc_write_level_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  int_express_lane_qfifo_overflow_en:1;
        RBus_UInt32  int_express_lane_qfifo_underflow_en:1;
        RBus_UInt32  int_express_lane_wfifo_overflow_en:1;
        RBus_UInt32  int_express_lane_wfifo_underflow_en:1;
        RBus_UInt32  int_exp_rfifo_overflow_en:1;
        RBus_UInt32  int_sys2_rfifo_overflow_en:1;
        RBus_UInt32  int_sys1_rfifo_overflow_en:1;
        RBus_UInt32  crc_err_int_en_1:1;
        RBus_UInt32  parity_err_int_en_1:1;
        RBus_UInt32  crc_err_int_en_0:1;
        RBus_UInt32  parity_err_int_en_0:1;
        RBus_UInt32  int_sys2_wfifo_underflow_en:1;
        RBus_UInt32  int_sys2_wfifo_overflow_en:1;
        RBus_UInt32  int_sys1_wfifo_underflow_en:1;
        RBus_UInt32  int_sys1_wfifo_overflow_en:1;
        RBus_UInt32  int_sys2_qfifo_underflow_en:1;
        RBus_UInt32  int_sys2_qfifo_overflow_en:1;
        RBus_UInt32  int_sys1_qfifo_underflow_en:1;
        RBus_UInt32  int_sys1_qfifo_overflow_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  int_err_cticmd_en:1;
        RBus_UInt32  int_err_active_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  int_en:1;
    };
}int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bank_act:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  cmd_cnt:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  par_st:19;
    };
}sm_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  wfifo_ddr_req_statistic_en:1;
        RBus_UInt32  clear_wfifo_record:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  wfifo_rd_cnt_et:8;
        RBus_UInt32  wfifo_rd_cnt_rl:8;
        RBus_UInt32  wfifo_wr_cnt_rl:8;
    };
}wfifo_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:4;
        RBus_UInt32  res6:7;
        RBus_UInt32  res7:3;
        RBus_UInt32  dbg_mod:6;
    };
}dc_debug_PHY_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  sys1_rd_demux_info_underflow:1;
        RBus_UInt32  sys1_rd_demux_info_overflow:1;
        RBus_UInt32  sys2_rd_info_underflow:1;
        RBus_UInt32  sys2_rd_info_overflow:1;
        RBus_UInt32  sys1_rd_exp_info_underflow:1;
        RBus_UInt32  sys1_rd_exp_info_overflow:1;
        RBus_UInt32  sys1_rd_info_underflow:1;
        RBus_UInt32  sys1_rd_info_overflow:1;
        RBus_UInt32  sys2_wr_info_underflow:1;
        RBus_UInt32  sys2_wr_info_overflow:1;
        RBus_UInt32  sys1_wr_info_underflow:1;
        RBus_UInt32  sys1_wr_info_overflow:1;
    };
}err_status_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  int_en_sys1_rd_demux_info_underflow:1;
        RBus_UInt32  int_en_sys1_rd_demux_info_overflow:1;
        RBus_UInt32  int_en_sys2_rd_info_underflow:1;
        RBus_UInt32  int_en_sys2_rd_info_overflow:1;
        RBus_UInt32  int_en_sys1_rd_exp_info_underflow:1;
        RBus_UInt32  int_en_sys1_rd_exp_info_overflow:1;
        RBus_UInt32  int_en_sys1_rd_info_underflow:1;
        RBus_UInt32  int_en_sys1_rd_info_overflow:1;
        RBus_UInt32  int_en_sys2_wr_info_underflow:1;
        RBus_UInt32  int_en_sys2_wr_info_overflow:1;
        RBus_UInt32  int_en_sys1_wr_info_underflow:1;
        RBus_UInt32  int_en_sys1_wr_info_overflow:1;
    };
}info_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wfifo_ddr_req_wait_total:32;
    };
}wfifo_ddr_req_wait_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wfifo_ddr_req_wait_max:16;
        RBus_UInt32  res1:16;
    };
}wfifo_max_req_wait_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  short_zqcl_per_sel:3;
        RBus_UInt32  auto_short_zqcl_en:1;
    };
}auto_short_zq_cal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wfifo_ddr_req_wait_total:32;
    };
}wfifo2_ddr_req_wait_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wfifo_ddr_req_wait_max:16;
        RBus_UInt32  res1:16;
    };
}wfifo2_max_req_wait_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  parser_rbus_dbg_sel:4;
    };
}par_dbg_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  parser_rbus_dbg:32;
    };
}par_dbg_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg:32;
    };
}dummy_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:3;
        RBus_UInt32  dq_sel:1;
    };
}cal_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}ana_dll_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  lpddr_ck_en:1;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  mod_reg_read:1;
        RBus_UInt32  write_en_0:1;
        RBus_UInt32  mod_reg_write:1;
    };
}lpddr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode_reg_rdata:8;
        RBus_UInt32  res1:24;
    };
}lpddr_rdat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  mode_reg_wdata:8;
        RBus_UInt32  mode_reg_addr:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  lpddr:1;
        RBus_UInt32  res3:6;
    };
}lpddr_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  mem_num_sel:1;
        RBus_UInt32  fifo_arb_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cmdq_ch_fifo_cnt:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  cmdq_ch_fifo_rd_ptr:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  cmdq_ch_fifo_wr_ptr:2;
        RBus_UInt32  cmdq_ch_fifo_overflow:1;
        RBus_UInt32  cmdq_ch_fifo_underflow:1;
        RBus_UInt32  cmdq_ch_fifo_full:1;
        RBus_UInt32  cmdq_ch_fifo_empty:1;
        RBus_UInt32  cmdq_ch_fifo_thr:4;
        RBus_UInt32  cmdq_ch_fifo_overflow_clr:1;
        RBus_UInt32  cmdq_ch_fifo_underflow_clr:1;
        RBus_UInt32  cmdq_ch_clk_gated_en:1;
        RBus_UInt32  fifo_arb_dis:1;
    };
}fifo_arb_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  cmdq_ch_gnt_mst1_cmd_dis:1;
        RBus_UInt32  cmdq_ch_gnt_mst1_cti_dis:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cmdq_ch_gnt_mst0_cmd_dis:1;
        RBus_UInt32  cmdq_ch_gnt_mst0_cti_dis:1;
    };
}fifo_arb_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cmdq_ch_dbg_mod:8;
    };
}fifo_arb_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_dummy_0:32;
    };
}fifo_arb_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st0:32;
    };
}fifo_arb_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st1:32;
    };
}fifo_arb_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st2:32;
    };
}fifo_arb_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st3:32;
    };
}fifo_arb_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st4:32;
    };
}fifo_arb_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st5:32;
    };
}fifo_arb_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st6:32;
    };
}fifo_arb_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st7:32;
    };
}fifo_arb_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  wq_ch_dbg_mod:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:6;
    };
}fifo_arb_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wq_ch_dummy_0:32;
    };
}fifo_arb_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wq_ch_st0:32;
    };
}fifo_arb_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wq_ch_st1:32;
    };
}fifo_arb_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wq_ch_st2:32;
    };
}fifo_arb_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wq_ch_st3:32;
    };
}fifo_arb_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  rq_ch_fifo_rd_ptr:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  rq_ch_fifo_wr_ptr:7;
        RBus_UInt32  rq_ch_fifo_overflow:1;
        RBus_UInt32  rq_ch_fifo_underflow:1;
        RBus_UInt32  rq_ch_fifo_full:1;
        RBus_UInt32  rq_ch_fifo_empty:1;
        RBus_UInt32  rq_ch_fifo_thr:8;
        RBus_UInt32  rq_ch_fifo_overflow_clr:1;
        RBus_UInt32  rq_ch_fifo_underflow_clr:1;
        RBus_UInt32  rq_ch_clk_gated_en:1;
        RBus_UInt32  res3:1;
    };
}fifo_arb_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rq_ch_fifo_cnt:8;
    };
}fifo_arb_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rq_ch_dbg_mod:8;
    };
}fifo_arb_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rq_ch_dummy_0:32;
    };
}fifo_arb_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rq_ch_st0:32;
    };
}fifo_arb_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rq_ch_st1:32;
    };
}fifo_arb_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rq_ch_st2:32;
    };
}fifo_arb_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rq_ch_st3:32;
    };
}fifo_arb_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  seq_mode_sc_sel:1;
        RBus_UInt32  scramble_en:1;
    };
}scramble_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_1:16;
        RBus_UInt32  sc_key_0:16;
    };
}scramble_key_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_3:16;
        RBus_UInt32  sc_key_2:16;
    };
}scramble_key_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_5:16;
        RBus_UInt32  sc_key_4:16;
    };
}scramble_key_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_7:16;
        RBus_UInt32  sc_key_6:16;
    };
}scramble_key_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_9:16;
        RBus_UInt32  sc_key_8:16;
    };
}scramble_key_89_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_11:16;
        RBus_UInt32  sc_key_10:16;
    };
}scramble_key_1011_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_13:16;
        RBus_UInt32  sc_key_12:16;
    };
}scramble_key_1213_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_15:16;
        RBus_UInt32  sc_key_14:16;
    };
}scramble_key_1415_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_17:16;
        RBus_UInt32  sc_key_16:16;
    };
}scramble_key_1617_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_19:16;
        RBus_UInt32  sc_key_18:16;
    };
}scramble_key_1819_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_21:16;
        RBus_UInt32  sc_key_20:16;
    };
}scramble_key_2021_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_23:16;
        RBus_UInt32  sc_key_22:16;
    };
}scramble_key_2223_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_25:16;
        RBus_UInt32  sc_key_24:16;
    };
}scramble_key_2425_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_27:16;
        RBus_UInt32  sc_key_26:16;
    };
}scramble_key_2627_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_29:16;
        RBus_UInt32  sc_key_28:16;
    };
}scramble_key_2829_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_31:16;
        RBus_UInt32  sc_key_30:16;
    };
}scramble_key_3031_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_0:32;
    };
}dummy_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_1:32;
    };
}dummy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_2:32;
    };
}dummy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_3:32;
    };
}dummy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_4:32;
    };
}dummy_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_5:32;
    };
}dummy_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  swap_2ddr_addr:1;
        RBus_UInt32  ddrx2_csx1_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  data_mask_h:1;
        RBus_UInt32  data_mask_l:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  cs_mask:1;
        RBus_UInt32  cs1_mask:1;
        RBus_UInt32  cs_swap:1;
    };
}cs_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  res2:1;
        RBus_UInt32  cmd_addr_2t_en:1;
        RBus_UInt32  res3:1;
    };
}cmd_dly_1t_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_merge_en:1;
        RBus_UInt32  read_bypass_en:1;
    };
}exp_lane_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tota_mon_num:32;
    };
}scpu_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tota_ack_num:32;
    };
}scpu_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tota_idl_num:32;
    };
}scpu_pc_tota_idl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acc_lat:32;
    };
}scpu_pc_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  max_lat:16;
    };
}scpu_pc_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  req_num:24;
    };
}scpu_pc_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ack_num:32;
    };
}scpu_pc_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  pc_go:1;
    };
}scpu_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  gck_ext_cyc:6;
        RBus_UInt32  res2:5;
        RBus_UInt32  par_gck_en:1;
        RBus_UInt32  fsm_gck_en:1;
        RBus_UInt32  ioblk_gck_en:1;
    };
}gck_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  enable:1;
    };
}scpu_leaky_bucket_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timer_threshold:32;
    };
}scpu_leaky_bucket_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  count_threshold:24;
    };
}scpu_leaky_bucket_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  merge_num:24;
    };
}scpu_pc_merge_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  wr_req_num:24;
    };
}scpu_pc_wr_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  data_in:20;
        RBus_UInt32  res2:1;
        RBus_UInt32  speed_en:1;
        RBus_UInt32  data_in_ready:1;
        RBus_UInt32  wire_sel:1;
        RBus_UInt32  ro_sel:3;
        RBus_UInt32  dss_rst_n:1;
    };
}speed_sensor_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  count_out:20;
        RBus_UInt32  res2:2;
        RBus_UInt32  wsort_go:1;
        RBus_UInt32  ready:1;
    };
}speed_sensor_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctrl_misc:32;
    };
}express_lane_ctrl_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_dbg_out1:16;
        RBus_UInt32  dc_dbg_out0:16;
    };
}debug01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_dbg_out3:16;
        RBus_UInt32  dc_dbg_out2:16;
    };
}debug23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  dc_phy_bist_clksel:1;
        RBus_UInt32  dc_phy_bist_mode_3:1;
        RBus_UInt32  dc_phy_bist_mode_2:1;
        RBus_UInt32  dc_phy_ptg_bist_mode_3:1;
        RBus_UInt32  dc_phy_ptg_bist_mode_2:1;
        RBus_UInt32  dc_phy_ptg_bist_mode_1:1;
        RBus_UInt32  dc_phy_ptg_bist_mode_0:1;
        RBus_UInt32  dc_phy_bist_mode_0:1;
        RBus_UInt32  dc_phy_bist_mode_1:1;
    };
}dc_phy_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dc_phy_bist_done_3:1;
        RBus_UInt32  dc_phy_bist_done_2:1;
        RBus_UInt32  dc_phy_ptg_bist_done_3:1;
        RBus_UInt32  dc_phy_ptg_bist_done_2:1;
        RBus_UInt32  dc_phy_ptg_bist_done_1:1;
        RBus_UInt32  dc_phy_ptg_bist_done_0:1;
        RBus_UInt32  dc_phy_bist_done_0:1;
        RBus_UInt32  dc_phy_bist_done_1:1;
    };
}dc_phy_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dc_phy_bist_fail_group_3:1;
        RBus_UInt32  dc_phy_bist_fail_group_2:1;
        RBus_UInt32  dc_phy_ptg_bist_fail_group_3:1;
        RBus_UInt32  dc_phy_ptg_bist_fail_group_2:1;
        RBus_UInt32  dc_phy_ptg_bist_fail_group_1:1;
        RBus_UInt32  dc_phy_ptg_bist_fail_group_0:1;
        RBus_UInt32  dc_phy_bist_fail_group_0:1;
        RBus_UInt32  dc_phy_bist_fail_group_1:1;
    };
}dc_phy_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dc_phy_drf_mode_3:1;
        RBus_UInt32  dc_phy_drf_mode_2:1;
        RBus_UInt32  dc_phy_ptg_drf_mode_3:1;
        RBus_UInt32  dc_phy_ptg_drf_mode_2:1;
        RBus_UInt32  dc_phy_ptg_drf_mode_1:1;
        RBus_UInt32  dc_phy_ptg_drf_mode_0:1;
        RBus_UInt32  dc_phy_drf_mode_0:1;
        RBus_UInt32  dc_phy_drf_mode_1:1;
    };
}dc_phy_bist_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dc_phy_drf_resume_3:1;
        RBus_UInt32  dc_phy_drf_resume_2:1;
        RBus_UInt32  dc_phy_ptg_drf_resume_3:1;
        RBus_UInt32  dc_phy_ptg_drf_resume_2:1;
        RBus_UInt32  dc_phy_ptg_drf_resume_1:1;
        RBus_UInt32  dc_phy_ptg_drf_resume_0:1;
        RBus_UInt32  dc_phy_drf_resume_0:1;
        RBus_UInt32  dc_phy_drf_resume_1:1;
    };
}dc_phy_bist_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dc_phy_drf_done_3:1;
        RBus_UInt32  dc_phy_drf_done_2:1;
        RBus_UInt32  dc_phy_ptg_drf_done_3:1;
        RBus_UInt32  dc_phy_ptg_drf_done_2:1;
        RBus_UInt32  dc_phy_ptg_drf_done_1:1;
        RBus_UInt32  dc_phy_ptg_drf_done_0:1;
        RBus_UInt32  dc_phy_drf_done_0:1;
        RBus_UInt32  dc_phy_drf_done_1:1;
    };
}dc_phy_bist0_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dc_phy_drf_pause_3:1;
        RBus_UInt32  dc_phy_drf_pause_2:1;
        RBus_UInt32  dc_phy_ptg_drf_pause_3:1;
        RBus_UInt32  dc_phy_ptg_drf_pause_2:1;
        RBus_UInt32  dc_phy_ptg_drf_pause_1:1;
        RBus_UInt32  dc_phy_ptg_drf_pause_0:1;
        RBus_UInt32  dc_phy_drf_pause_0:1;
        RBus_UInt32  dc_phy_drf_pause_1:1;
    };
}dc_phy_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dc_phy_drf_fail_group_3:1;
        RBus_UInt32  dc_phy_drf_fail_group_2:1;
        RBus_UInt32  dc_phy_ptg_drf_fail_group_3:1;
        RBus_UInt32  dc_phy_ptg_drf_fail_group_2:1;
        RBus_UInt32  dc_phy_ptg_drf_fail_group_1:1;
        RBus_UInt32  dc_phy_ptg_drf_fail_group_0:1;
        RBus_UInt32  dc_phy_drf_fail_group_0:1;
        RBus_UInt32  dc_phy_drf_fail_group_1:1;
    };
}dc_phy_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18008fe0_31_0:32;
    };
}dc_phy_bist_detail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  dc_phy_ls:1;
        RBus_UInt32  dc_phy_ptg_ls:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rme:1;
        RBus_UInt32  rm_3:1;
        RBus_UInt32  rm_2:1;
        RBus_UInt32  rm_1:1;
        RBus_UInt32  rm_0:1;
    };
}dc_phy_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  dc_phy_ptg_ready:1;
    };
}ptg_ready_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dc_phy_ptg_rst_n:1;
        RBus_UInt32  dc_phy_ptg_clk_en:1;
        RBus_UInt32  dc_phy_ptg_sel:1;
    };
}ptg_select_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  meas_period:14;
        RBus_UInt32  res2:7;
        RBus_UInt32  eff_meas_en:1;
    };
}eff_meas_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  rd_cnt:29;
    };
}read_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  wr_cnt:29;
    };
}write_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  rd_chop_cnt:29;
    };
}read_chop_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  wr_chop_cnt:29;
    };
}write_chop_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  active_cnt_bank0:29;
    };
}act_bank_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  precharge_cnt_bank0:29;
    };
}prechg_bank_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  active_cnt_bank1:29;
    };
}act_bank_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  precharge_cnt_bank1:29;
    };
}prechg_bank_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  active_cnt_bank2:29;
    };
}act_bank_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  precharge_cnt_bank2:29;
    };
}prechg_bank_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  active_cnt_bank3:29;
    };
}act_bank_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  precharge_cnt_bank3:29;
    };
}prechg_bank_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  active_cnt_bank4:29;
    };
}act_bank_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  precharge_cnt_bank4:29;
    };
}prechg_bank_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  active_cnt_bank5:29;
    };
}act_bank_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  precharge_cnt_bank5:29;
    };
}prechg_bank_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  active_cnt_bank6:29;
    };
}act_bank_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  precharge_cnt_bank6:29;
    };
}prechg_bank_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  active_cnt_bank7:29;
    };
}act_bank_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  precharge_cnt_bank7:29;
    };
}prechg_bank_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  w2r_cnt:27;
    };
}write_to_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  r2w_cnt:27;
    };
}read_to_write_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  req_to_cmd_w:26;
    };
}write_cmd_latency_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  req_to_cmd_r:26;
    };
}read_cmd_latency_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  bank_conflict_cnt:20;
    };
}bank_conflict_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  wr_merge_cnt_exp:28;
    };
}write_merge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  rd_bypass_cnt_exp:28;
    };
}read_bypass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  rd_bypass_cnt_dc_sys1:28;
    };
}dc_sys1_read_bypass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  rd_ap_cnt:29;
    };
}read_cmd_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  wr_ap_cnt:29;
    };
}write_cmd_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  outstand_reorder_en:1;
        RBus_UInt32  priority_weight_en:1;
        RBus_UInt32  direction_weight_en:1;
        RBus_UInt32  length_weight_en:1;
        RBus_UInt32  bank_weight_en:1;
    };
}weight_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  pw_sys1_level:1;
        RBus_UInt32  pw_sys2_level:1;
        RBus_UInt32  pw_multiplier:3;
    };
}weight_priority_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  dw_init_dynamic_en:1;
        RBus_UInt32  dw_init_r:8;
        RBus_UInt32  dw_init_w:8;
        RBus_UInt32  dw_multiplier:3;
    };
}weight_dierection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  lw_long_burst_prior:1;
        RBus_UInt32  lw_multiplier:3;
    };
}weight_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  bw_pend_mode:1;
        RBus_UInt32  bw_pend_cycle:7;
        RBus_UInt32  bw_pend_en:1;
        RBus_UInt32  bw_trc:7;
        RBus_UInt32  bw_trp:5;
        RBus_UInt32  bw_multiplier:3;
    };
}weight_bank_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  priority_down_sample_rate:2;
        RBus_UInt32  read_bypass_seq_mode:1;
        RBus_UInt32  dc_sys1_group_en:1;
        RBus_UInt32  express_lane_group_en:1;
        RBus_UInt32  express_lane_wr_separate_en:1;
    };
}multi_client_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  write_buffer_3_occupy:1;
        RBus_UInt32  write_buffer_2_occupy:1;
        RBus_UInt32  write_buffer_1_occupy:1;
        RBus_UInt32  write_buffer_0_occupy:1;
        RBus_UInt32  read_cmd_queue_cnt:3;
        RBus_UInt32  cmd_queue_cnt:3;
    };
}express_lane_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  qos_5_bank_wait_error:1;
        RBus_UInt32  qos_4_bank_wait_error:1;
        RBus_UInt32  qos_3_bank_wait_error:1;
        RBus_UInt32  qos_2_bank_wait_error:1;
        RBus_UInt32  qos_1_bank_wait_error:1;
        RBus_UInt32  qos_0_bank_wait_error:1;
        RBus_UInt32  weight_5_req:1;
        RBus_UInt32  weight_4_req:1;
        RBus_UInt32  weight_3_req:1;
        RBus_UInt32  weight_2_req:1;
        RBus_UInt32  weight_1_req:1;
        RBus_UInt32  weight_0_req:1;
        RBus_UInt32  qos_5_req:1;
        RBus_UInt32  qos_4_req:1;
        RBus_UInt32  qos_3_req:1;
        RBus_UInt32  qos_2_req:1;
        RBus_UInt32  qos_1_req:1;
        RBus_UInt32  qos_0_req:1;
    };
}weight_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  ddr4_wr_crc_bc4_use_dm:1;
        RBus_UInt32  ddr4_wr_crc_bl8_use_dm:1;
        RBus_UInt32  ddr4_pda_mrs_dram_sel:1;
        RBus_UInt32  ddr4_gear_set_dpi_sel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  alert_n_pw_judge:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  ddr4_record_cmd_en:1;
        RBus_UInt32  ddr4_rd_dbi_en:1;
        RBus_UInt32  ddr4_parity_add_sel:1;
        RBus_UInt32  ddr4_ca_parity_en:1;
        RBus_UInt32  ddr4_wr_crc_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  ddr4:1;
    };
}ddr4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  tmwtr_l:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  tmrrd_l:5;
        RBus_UInt32  tmccd_l:4;
    };
}ddr4_tm0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode_reg5:16;
        RBus_UInt32  mode_reg4:16;
    };
}ddr4_mr45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  mode_reg6:16;
    };
}ddr4_mr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  ddr4_pda_en:1;
        RBus_UInt32  ddr4_rd_dbi_en:1;
        RBus_UInt32  ddr4_max_pw_sav_en:1;
        RBus_UInt32  ddr4_gear_down_en:1;
        RBus_UInt32  ddr4_mpr_rw_en:1;
        RBus_UInt32  ddr4_wr_crc_en:1;
        RBus_UInt32  ddr4_parity_en:1;
        RBus_UInt32  alert_n_pw_1:8;
        RBus_UInt32  alert_n_pw_0:8;
    };
}ddr4_alert_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  write_en_4:1;
        RBus_UInt32  exe_mpr_wr:1;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  exe_mpr_rd:1;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  ddr4_exe_mr6:1;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  ddr4_exe_mr5:1;
        RBus_UInt32  write_en_0:1;
        RBus_UInt32  ddr4_exe_mr4:1;
    };
}dc_ddr4_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  mpr_rw_bank:2;
        RBus_UInt32  mpr_rw_add:8;
    };
}ddr4_exe_rw_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dc_sys2_rd_block_en:1;
        RBus_UInt32  dc_sys2_wr_block_en:1;
        RBus_UInt32  dc_sys1_rd_block_en:1;
        RBus_UInt32  dc_sys1_wr_block_en:1;
        RBus_UInt32  exp_rd_block_en:1;
        RBus_UInt32  exp_wr_block_en:1;
    };
}block_req_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  fail_cmd:25;
    };
}ddr4_fail_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_3:8;
        RBus_UInt32  mpr_data_2:8;
        RBus_UInt32  mpr_data_1:8;
        RBus_UInt32  mpr_data_0:8;
    };
}ddr4_mpr_rd_dat0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_7:8;
        RBus_UInt32  mpr_data_6:8;
        RBus_UInt32  mpr_data_5:8;
        RBus_UInt32  mpr_data_4:8;
    };
}ddr4_mpr_rd_dat1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_11:8;
        RBus_UInt32  mpr_data_10:8;
        RBus_UInt32  mpr_data_9:8;
        RBus_UInt32  mpr_data_8:8;
    };
}ddr4_mpr_rd_dat2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_15:8;
        RBus_UInt32  mpr_data_14:8;
        RBus_UInt32  mpr_data_13:8;
        RBus_UInt32  mpr_data_12:8;
    };
}ddr4_mpr_rd_dat3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_19:8;
        RBus_UInt32  mpr_data_18:8;
        RBus_UInt32  mpr_data_17:8;
        RBus_UInt32  mpr_data_16:8;
    };
}ddr4_mpr_rd_dat4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_23:8;
        RBus_UInt32  mpr_data_22:8;
        RBus_UInt32  mpr_data_21:8;
        RBus_UInt32  mpr_data_20:8;
    };
}ddr4_mpr_rd_dat5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_27:8;
        RBus_UInt32  mpr_data_26:8;
        RBus_UInt32  mpr_data_25:8;
        RBus_UInt32  mpr_data_24:8;
    };
}ddr4_mpr_rd_dat6_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_31:8;
        RBus_UInt32  mpr_data_30:8;
        RBus_UInt32  mpr_data_29:8;
        RBus_UInt32  mpr_data_28:8;
    };
}ddr4_mpr_rd_dat6_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ref_rst_dly_rx:8;
        RBus_UInt32  ref_rst_dly_tx:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  force_rst_n_rx:1;
        RBus_UInt32  bypass_en_rx:1;
        RBus_UInt32  ref_rst_en_rx:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  force_rst_n_tx:1;
        RBus_UInt32  bypass_en_tx:1;
        RBus_UInt32  ref_rst_en_tx:1;
    };
}cts_fifo_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  dc_sys1_read_bypass_seq_mode:1;
        RBus_UInt32  dc_sys1_read_bypass_rw_separate_en:1;
        RBus_UInt32  dc_sys1_read_bypass_en:1;
        RBus_UInt32  dc_sys1_path_sel:1;
    };
}dc_sys1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dc_sys2_wr_qfifo_en:1;
        RBus_UInt32  dc_sys2_client_sep_enable:1;
        RBus_UInt32  dc_sys2_rw_sep_en:1;
    };
}dc_sys2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ki_neg:12;
        RBus_UInt32  ki_pos:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  ot_en:1;
        RBus_UInt32  occ_status_clear:1;
        RBus_UInt32  stp_ref_cal_en:1;
        RBus_UInt32  lat_en:1;
        RBus_UInt32  bw_en:1;
    };
}qos_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qos_ot_dummy:20;
        RBus_UInt32  max_oti:4;
        RBus_UInt32  max_otf:8;
    };
}qos_ot_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  idle_period:16;
        RBus_UInt32  add_data:8;
    };
}qos_bw0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_data:16;
        RBus_UInt32  min_data:16;
    };
}qos_bw1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  max_pri:8;
        RBus_UInt32  def_pri:8;
        RBus_UInt32  min_pri:8;
    };
}qos_bw2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cur_data_max_occ:1;
        RBus_UInt32  cur_data_min_occ:1;
        RBus_UInt32  pri_max_occ:1;
        RBus_UInt32  pri_min_occ:1;
        RBus_UInt32  cur_pri:8;
        RBus_UInt32  cur_data:16;
    };
}qos_bw3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lat_upper:16;
        RBus_UInt32  lat_lower:16;
    };
}qos_lat0_RBUS;

#else //apply LITTLE_ENDIAN

//======MAGELLAN2_DC_PHY_ARCH_SPEC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tmcl:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  tmrcl:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  tmras:8;
        RBus_UInt32  res3:8;
    };
}tmctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tmrc:8;
        RBus_UInt32  tmrcdrd:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  tmrp:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  tmrrd:5;
        RBus_UInt32  res3:3;
    };
}tmctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tmwr:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  tmwtr:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  trtp:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  tmccd:4;
        RBus_UInt32  tmccd_r2r:4;
    };
}tmctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tmrfc:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  refcycle:12;
        RBus_UInt32  tmfaw:8;
    };
}tmctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tmmrd:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  tmmod:8;
        RBus_UInt32  taofd:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  taond:6;
        RBus_UInt32  res3:2;
    };
}tmctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tzqinit:12;
        RBus_UInt32  tzqoper:12;
        RBus_UInt32  res1:8;
    };
}tmctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tzqcs:12;
        RBus_UInt32  tdllk:12;
        RBus_UInt32  res1:7;
        RBus_UInt32  res2:1;
    };
}tmctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  res2:5;
        RBus_UInt32  odt_dis:1;
        RBus_UInt32  odt_en:1;
        RBus_UInt32  odt_force_sig:1;
        RBus_UInt32  odt_force_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  odt_first_cycle_dis:1;
        RBus_UInt32  odt_pre_1t_en:1;
        RBus_UInt32  odt_post_1t_en:1;
        RBus_UInt32  odt_post_2t_en:1;
        RBus_UInt32  odt_post_3t_en:1;
    };
}odt_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  res3:18;
    };
}cal_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  exe_mr:1;
        RBus_UInt32  exe_emr:1;
        RBus_UInt32  srex:1;
        RBus_UInt32  sren:1;
        RBus_UInt32  init:1;
        RBus_UInt32  issue_nop_after_sre:1;
        RBus_UInt32  res1:26;
    };
}dc_mis2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  tmrcdwr:6;
        RBus_UInt32  res5:2;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:7;
    };
}dc_mis_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lbk_en:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  pre_dis:1;
        RBus_UInt32  ref_after_last_cmd:1;
        RBus_UInt32  res3:18;
    };
}dc_misa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  tmrc_sel:1;
        RBus_UInt32  res2:3;
    };
}dc_misb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:4;
    };
}dc_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:29;
    };
}dc_test_mode_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr3_init:1;
        RBus_UInt32  write_en_0:1;
        RBus_UInt32  ddr3_exe_mr0:1;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  ddr3_exe_mr1:1;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  ddr3_exe_mr2:1;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  ddr3_exe_mr3:1;
        RBus_UInt32  write_en_4:1;
        RBus_UInt32  ddr3_exe_zqcl:1;
        RBus_UInt32  write_en_5:1;
        RBus_UInt32  ddr3_zqcl_short:1;
        RBus_UInt32  write_en_6:1;
        RBus_UInt32  dis_pre_all:1;
        RBus_UInt32  write_en_7:1;
        RBus_UInt32  use_tmmrd:1;
        RBus_UInt32  write_en_8:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  write_en_9:1;
        RBus_UInt32  dis_cti:1;
        RBus_UInt32  write_en_10:1;
        RBus_UInt32  fast_prechg:1;
        RBus_UInt32  write_en_11:1;
        RBus_UInt32  end_200us:1;
        RBus_UInt32  write_en_12:1;
        RBus_UInt32  end_500us:1;
        RBus_UInt32  write_en_13:1;
        RBus_UInt32  ddr3_swap:1;
        RBus_UInt32  write_en_14:1;
        RBus_UInt32  dis_ap:1;
        RBus_UInt32  write_en_15:1;
    };
}dc_ddr3_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod_reg:16;
        RBus_UInt32  exmod_reg:16;
    };
}mod_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod2_reg:16;
        RBus_UInt32  mod3_reg:16;
    };
}mod23_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rfifo_thred:7;
        RBus_UInt32  full_gated:1;
        RBus_UInt32  rdwr_use_full:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  wfifo_rdy_gated:1;
        RBus_UInt32  res2:19;
    };
}rfifo_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_active:1;
        RBus_UInt32  err_cti_cmd:1;
        RBus_UInt32  sys1_qfifo_overflow:1;
        RBus_UInt32  sys1_qfifo_underflow:1;
        RBus_UInt32  sys2_qfifo_overflow:1;
        RBus_UInt32  sys2_qfifo_underflow:1;
        RBus_UInt32  sys1_wfifo_overflow:1;
        RBus_UInt32  sys1_wfifo_underflow:1;
        RBus_UInt32  sys2_wfifo_overflow:1;
        RBus_UInt32  sys2_wfifo_underflow:1;
        RBus_UInt32  ddr4_crc_err_0:1;
        RBus_UInt32  ddr4_parity_err_0:1;
        RBus_UInt32  ddr4_crc_err_1:1;
        RBus_UInt32  ddr4_parity_err_1:1;
        RBus_UInt32  sys1_rfifo_overflow:1;
        RBus_UInt32  sys2_rfifo_overflow:1;
        RBus_UInt32  exp_rfifo_overflow:1;
        RBus_UInt32  express_lane_wfifo_underflow:1;
        RBus_UInt32  express_lane_wfifo_overflow:1;
        RBus_UInt32  express_lane_qfifo_underflow:1;
        RBus_UInt32  express_lane_qfifo_overflow:1;
        RBus_UInt32  res1:11;
    };
}err_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dis_refresh:1;
        RBus_UInt32  exe_prea:1;
        RBus_UInt32  res3:28;
    };
}dc_write_level_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  int_err_active_en:1;
        RBus_UInt32  int_err_cticmd_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  int_sys1_qfifo_overflow_en:1;
        RBus_UInt32  int_sys1_qfifo_underflow_en:1;
        RBus_UInt32  int_sys2_qfifo_overflow_en:1;
        RBus_UInt32  int_sys2_qfifo_underflow_en:1;
        RBus_UInt32  int_sys1_wfifo_overflow_en:1;
        RBus_UInt32  int_sys1_wfifo_underflow_en:1;
        RBus_UInt32  int_sys2_wfifo_overflow_en:1;
        RBus_UInt32  int_sys2_wfifo_underflow_en:1;
        RBus_UInt32  parity_err_int_en_0:1;
        RBus_UInt32  crc_err_int_en_0:1;
        RBus_UInt32  parity_err_int_en_1:1;
        RBus_UInt32  crc_err_int_en_1:1;
        RBus_UInt32  int_sys1_rfifo_overflow_en:1;
        RBus_UInt32  int_sys2_rfifo_overflow_en:1;
        RBus_UInt32  int_exp_rfifo_overflow_en:1;
        RBus_UInt32  int_express_lane_wfifo_underflow_en:1;
        RBus_UInt32  int_express_lane_wfifo_overflow_en:1;
        RBus_UInt32  int_express_lane_qfifo_underflow_en:1;
        RBus_UInt32  int_express_lane_qfifo_overflow_en:1;
        RBus_UInt32  res4:7;
    };
}int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  par_st:19;
        RBus_UInt32  res1:1;
        RBus_UInt32  cmd_cnt:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  bank_act:8;
    };
}sm_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wfifo_wr_cnt_rl:8;
        RBus_UInt32  wfifo_rd_cnt_rl:8;
        RBus_UInt32  wfifo_rd_cnt_et:8;
        RBus_UInt32  res1:5;
        RBus_UInt32  clear_wfifo_record:1;
        RBus_UInt32  wfifo_ddr_req_statistic_en:1;
        RBus_UInt32  res2:1;
    };
}wfifo_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_mod:6;
        RBus_UInt32  res1:3;
        RBus_UInt32  res2:7;
        RBus_UInt32  res3:4;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  res7:5;
    };
}dc_debug_PHY_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys1_wr_info_overflow:1;
        RBus_UInt32  sys1_wr_info_underflow:1;
        RBus_UInt32  sys2_wr_info_overflow:1;
        RBus_UInt32  sys2_wr_info_underflow:1;
        RBus_UInt32  sys1_rd_info_overflow:1;
        RBus_UInt32  sys1_rd_info_underflow:1;
        RBus_UInt32  sys1_rd_exp_info_overflow:1;
        RBus_UInt32  sys1_rd_exp_info_underflow:1;
        RBus_UInt32  sys2_rd_info_overflow:1;
        RBus_UInt32  sys2_rd_info_underflow:1;
        RBus_UInt32  sys1_rd_demux_info_overflow:1;
        RBus_UInt32  sys1_rd_demux_info_underflow:1;
        RBus_UInt32  res1:20;
    };
}err_status_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_en_sys1_wr_info_overflow:1;
        RBus_UInt32  int_en_sys1_wr_info_underflow:1;
        RBus_UInt32  int_en_sys2_wr_info_overflow:1;
        RBus_UInt32  int_en_sys2_wr_info_underflow:1;
        RBus_UInt32  int_en_sys1_rd_info_overflow:1;
        RBus_UInt32  int_en_sys1_rd_info_underflow:1;
        RBus_UInt32  int_en_sys1_rd_exp_info_overflow:1;
        RBus_UInt32  int_en_sys1_rd_exp_info_underflow:1;
        RBus_UInt32  int_en_sys2_rd_info_overflow:1;
        RBus_UInt32  int_en_sys2_rd_info_underflow:1;
        RBus_UInt32  int_en_sys1_rd_demux_info_overflow:1;
        RBus_UInt32  int_en_sys1_rd_demux_info_underflow:1;
        RBus_UInt32  res1:20;
    };
}info_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wfifo_ddr_req_wait_total:32;
    };
}wfifo_ddr_req_wait_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  wfifo_ddr_req_wait_max:16;
    };
}wfifo_max_req_wait_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_short_zqcl_en:1;
        RBus_UInt32  short_zqcl_per_sel:3;
        RBus_UInt32  res1:28;
    };
}auto_short_zq_cal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wfifo_ddr_req_wait_total:32;
    };
}wfifo2_ddr_req_wait_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  wfifo_ddr_req_wait_max:16;
    };
}wfifo2_max_req_wait_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  parser_rbus_dbg_sel:4;
        RBus_UInt32  res1:28;
    };
}par_dbg_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  parser_rbus_dbg:32;
    };
}par_dbg_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg:32;
    };
}dummy_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dq_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:18;
    };
}cal_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}ana_dll_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod_reg_write:1;
        RBus_UInt32  write_en_0:1;
        RBus_UInt32  mod_reg_read:1;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  lpddr_ck_en:1;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  res1:26;
    };
}lpddr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mode_reg_rdata:8;
    };
}lpddr_rdat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  lpddr:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mode_reg_addr:8;
        RBus_UInt32  mode_reg_wdata:8;
        RBus_UInt32  res3:8;
    };
}lpddr_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_arb_dis:1;
        RBus_UInt32  cmdq_ch_clk_gated_en:1;
        RBus_UInt32  cmdq_ch_fifo_underflow_clr:1;
        RBus_UInt32  cmdq_ch_fifo_overflow_clr:1;
        RBus_UInt32  cmdq_ch_fifo_thr:4;
        RBus_UInt32  cmdq_ch_fifo_empty:1;
        RBus_UInt32  cmdq_ch_fifo_full:1;
        RBus_UInt32  cmdq_ch_fifo_underflow:1;
        RBus_UInt32  cmdq_ch_fifo_overflow:1;
        RBus_UInt32  cmdq_ch_fifo_wr_ptr:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  cmdq_ch_fifo_rd_ptr:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  cmdq_ch_fifo_cnt:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  fifo_arb_sel:1;
        RBus_UInt32  mem_num_sel:1;
        RBus_UInt32  res4:6;
    };
}fifo_arb_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_mst0_cti_dis:1;
        RBus_UInt32  cmdq_ch_gnt_mst0_cmd_dis:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  cmdq_ch_gnt_mst1_cti_dis:1;
        RBus_UInt32  cmdq_ch_gnt_mst1_cmd_dis:1;
        RBus_UInt32  res2:26;
    };
}fifo_arb_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_dbg_mod:8;
        RBus_UInt32  res1:24;
    };
}fifo_arb_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_dummy_0:32;
    };
}fifo_arb_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st0:32;
    };
}fifo_arb_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st1:32;
    };
}fifo_arb_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st2:32;
    };
}fifo_arb_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st3:32;
    };
}fifo_arb_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st4:32;
    };
}fifo_arb_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st5:32;
    };
}fifo_arb_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st6:32;
    };
}fifo_arb_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdq_ch_gnt_st7:32;
    };
}fifo_arb_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  wq_ch_dbg_mod:8;
        RBus_UInt32  res3:16;
    };
}fifo_arb_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wq_ch_dummy_0:32;
    };
}fifo_arb_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wq_ch_st0:32;
    };
}fifo_arb_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wq_ch_st1:32;
    };
}fifo_arb_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wq_ch_st2:32;
    };
}fifo_arb_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wq_ch_st3:32;
    };
}fifo_arb_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  rq_ch_clk_gated_en:1;
        RBus_UInt32  rq_ch_fifo_underflow_clr:1;
        RBus_UInt32  rq_ch_fifo_overflow_clr:1;
        RBus_UInt32  rq_ch_fifo_thr:8;
        RBus_UInt32  rq_ch_fifo_empty:1;
        RBus_UInt32  rq_ch_fifo_full:1;
        RBus_UInt32  rq_ch_fifo_underflow:1;
        RBus_UInt32  rq_ch_fifo_overflow:1;
        RBus_UInt32  rq_ch_fifo_wr_ptr:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  rq_ch_fifo_rd_ptr:7;
        RBus_UInt32  res3:1;
    };
}fifo_arb_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rq_ch_fifo_cnt:8;
        RBus_UInt32  res1:24;
    };
}fifo_arb_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rq_ch_dbg_mod:8;
        RBus_UInt32  res1:24;
    };
}fifo_arb_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rq_ch_dummy_0:32;
    };
}fifo_arb_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rq_ch_st0:32;
    };
}fifo_arb_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rq_ch_st1:32;
    };
}fifo_arb_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rq_ch_st2:32;
    };
}fifo_arb_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rq_ch_st3:32;
    };
}fifo_arb_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scramble_en:1;
        RBus_UInt32  seq_mode_sc_sel:1;
        RBus_UInt32  res1:30;
    };
}scramble_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_0:16;
        RBus_UInt32  sc_key_1:16;
    };
}scramble_key_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_2:16;
        RBus_UInt32  sc_key_3:16;
    };
}scramble_key_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_4:16;
        RBus_UInt32  sc_key_5:16;
    };
}scramble_key_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_6:16;
        RBus_UInt32  sc_key_7:16;
    };
}scramble_key_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_8:16;
        RBus_UInt32  sc_key_9:16;
    };
}scramble_key_89_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_10:16;
        RBus_UInt32  sc_key_11:16;
    };
}scramble_key_1011_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_12:16;
        RBus_UInt32  sc_key_13:16;
    };
}scramble_key_1213_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_14:16;
        RBus_UInt32  sc_key_15:16;
    };
}scramble_key_1415_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_16:16;
        RBus_UInt32  sc_key_17:16;
    };
}scramble_key_1617_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_18:16;
        RBus_UInt32  sc_key_19:16;
    };
}scramble_key_1819_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_20:16;
        RBus_UInt32  sc_key_21:16;
    };
}scramble_key_2021_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_22:16;
        RBus_UInt32  sc_key_23:16;
    };
}scramble_key_2223_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_24:16;
        RBus_UInt32  sc_key_25:16;
    };
}scramble_key_2425_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_26:16;
        RBus_UInt32  sc_key_27:16;
    };
}scramble_key_2627_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_28:16;
        RBus_UInt32  sc_key_29:16;
    };
}scramble_key_2829_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_key_30:16;
        RBus_UInt32  sc_key_31:16;
    };
}scramble_key_3031_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_0:32;
    };
}dummy_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_1:32;
    };
}dummy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_2:32;
    };
}dummy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_3:32;
    };
}dummy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_4:32;
    };
}dummy_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_5:32;
    };
}dummy_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_swap:1;
        RBus_UInt32  cs1_mask:1;
        RBus_UInt32  cs_mask:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  data_mask_l:1;
        RBus_UInt32  data_mask_h:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  ddrx2_csx1_mode:1;
        RBus_UInt32  swap_2ddr_addr:1;
        RBus_UInt32  res3:22;
    };
}cs_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cmd_addr_2t_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:29;
    };
}cmd_dly_1t_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_bypass_en:1;
        RBus_UInt32  write_merge_en:1;
        RBus_UInt32  res1:30;
    };
}exp_lane_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tota_mon_num:32;
    };
}scpu_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tota_ack_num:32;
    };
}scpu_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tota_idl_num:32;
    };
}scpu_pc_tota_idl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acc_lat:32;
    };
}scpu_pc_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_lat:16;
        RBus_UInt32  res1:16;
    };
}scpu_pc_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_num:24;
        RBus_UInt32  res1:8;
    };
}scpu_pc_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ack_num:32;
    };
}scpu_pc_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_go:1;
        RBus_UInt32  res1:31;
    };
}scpu_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ioblk_gck_en:1;
        RBus_UInt32  fsm_gck_en:1;
        RBus_UInt32  par_gck_en:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  gck_ext_cyc:6;
        RBus_UInt32  res2:18;
    };
}gck_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:31;
    };
}scpu_leaky_bucket_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timer_threshold:32;
    };
}scpu_leaky_bucket_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  count_threshold:24;
        RBus_UInt32  res1:8;
    };
}scpu_leaky_bucket_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  merge_num:24;
        RBus_UInt32  res1:8;
    };
}scpu_pc_merge_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_req_num:24;
        RBus_UInt32  res1:8;
    };
}scpu_pc_wr_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_rst_n:1;
        RBus_UInt32  ro_sel:3;
        RBus_UInt32  wire_sel:1;
        RBus_UInt32  data_in_ready:1;
        RBus_UInt32  speed_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  data_in:20;
        RBus_UInt32  res2:4;
    };
}speed_sensor_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ready:1;
        RBus_UInt32  wsort_go:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  count_out:20;
        RBus_UInt32  res2:8;
    };
}speed_sensor_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctrl_misc:32;
    };
}express_lane_ctrl_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_dbg_out0:16;
        RBus_UInt32  dc_dbg_out1:16;
    };
}debug01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_dbg_out2:16;
        RBus_UInt32  dc_dbg_out3:16;
    };
}debug23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_phy_bist_mode_1:1;
        RBus_UInt32  dc_phy_bist_mode_0:1;
        RBus_UInt32  dc_phy_ptg_bist_mode_0:1;
        RBus_UInt32  dc_phy_ptg_bist_mode_1:1;
        RBus_UInt32  dc_phy_ptg_bist_mode_2:1;
        RBus_UInt32  dc_phy_ptg_bist_mode_3:1;
        RBus_UInt32  dc_phy_bist_mode_2:1;
        RBus_UInt32  dc_phy_bist_mode_3:1;
        RBus_UInt32  dc_phy_bist_clksel:1;
        RBus_UInt32  res1:23;
    };
}dc_phy_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_phy_bist_done_1:1;
        RBus_UInt32  dc_phy_bist_done_0:1;
        RBus_UInt32  dc_phy_ptg_bist_done_0:1;
        RBus_UInt32  dc_phy_ptg_bist_done_1:1;
        RBus_UInt32  dc_phy_ptg_bist_done_2:1;
        RBus_UInt32  dc_phy_ptg_bist_done_3:1;
        RBus_UInt32  dc_phy_bist_done_2:1;
        RBus_UInt32  dc_phy_bist_done_3:1;
        RBus_UInt32  res1:24;
    };
}dc_phy_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_phy_bist_fail_group_1:1;
        RBus_UInt32  dc_phy_bist_fail_group_0:1;
        RBus_UInt32  dc_phy_ptg_bist_fail_group_0:1;
        RBus_UInt32  dc_phy_ptg_bist_fail_group_1:1;
        RBus_UInt32  dc_phy_ptg_bist_fail_group_2:1;
        RBus_UInt32  dc_phy_ptg_bist_fail_group_3:1;
        RBus_UInt32  dc_phy_bist_fail_group_2:1;
        RBus_UInt32  dc_phy_bist_fail_group_3:1;
        RBus_UInt32  res1:24;
    };
}dc_phy_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_phy_drf_mode_1:1;
        RBus_UInt32  dc_phy_drf_mode_0:1;
        RBus_UInt32  dc_phy_ptg_drf_mode_0:1;
        RBus_UInt32  dc_phy_ptg_drf_mode_1:1;
        RBus_UInt32  dc_phy_ptg_drf_mode_2:1;
        RBus_UInt32  dc_phy_ptg_drf_mode_3:1;
        RBus_UInt32  dc_phy_drf_mode_2:1;
        RBus_UInt32  dc_phy_drf_mode_3:1;
        RBus_UInt32  res1:24;
    };
}dc_phy_bist_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_phy_drf_resume_1:1;
        RBus_UInt32  dc_phy_drf_resume_0:1;
        RBus_UInt32  dc_phy_ptg_drf_resume_0:1;
        RBus_UInt32  dc_phy_ptg_drf_resume_1:1;
        RBus_UInt32  dc_phy_ptg_drf_resume_2:1;
        RBus_UInt32  dc_phy_ptg_drf_resume_3:1;
        RBus_UInt32  dc_phy_drf_resume_2:1;
        RBus_UInt32  dc_phy_drf_resume_3:1;
        RBus_UInt32  res1:24;
    };
}dc_phy_bist_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_phy_drf_done_1:1;
        RBus_UInt32  dc_phy_drf_done_0:1;
        RBus_UInt32  dc_phy_ptg_drf_done_0:1;
        RBus_UInt32  dc_phy_ptg_drf_done_1:1;
        RBus_UInt32  dc_phy_ptg_drf_done_2:1;
        RBus_UInt32  dc_phy_ptg_drf_done_3:1;
        RBus_UInt32  dc_phy_drf_done_2:1;
        RBus_UInt32  dc_phy_drf_done_3:1;
        RBus_UInt32  res1:24;
    };
}dc_phy_bist0_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_phy_drf_pause_1:1;
        RBus_UInt32  dc_phy_drf_pause_0:1;
        RBus_UInt32  dc_phy_ptg_drf_pause_0:1;
        RBus_UInt32  dc_phy_ptg_drf_pause_1:1;
        RBus_UInt32  dc_phy_ptg_drf_pause_2:1;
        RBus_UInt32  dc_phy_ptg_drf_pause_3:1;
        RBus_UInt32  dc_phy_drf_pause_2:1;
        RBus_UInt32  dc_phy_drf_pause_3:1;
        RBus_UInt32  res1:24;
    };
}dc_phy_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_phy_drf_fail_group_1:1;
        RBus_UInt32  dc_phy_drf_fail_group_0:1;
        RBus_UInt32  dc_phy_ptg_drf_fail_group_0:1;
        RBus_UInt32  dc_phy_ptg_drf_fail_group_1:1;
        RBus_UInt32  dc_phy_ptg_drf_fail_group_2:1;
        RBus_UInt32  dc_phy_ptg_drf_fail_group_3:1;
        RBus_UInt32  dc_phy_drf_fail_group_2:1;
        RBus_UInt32  dc_phy_drf_fail_group_3:1;
        RBus_UInt32  res1:24;
    };
}dc_phy_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18008fe0_31_0:32;
    };
}dc_phy_bist_detail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:1;
        RBus_UInt32  rm_1:1;
        RBus_UInt32  rm_2:1;
        RBus_UInt32  rm_3:1;
        RBus_UInt32  rme:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dc_phy_ptg_ls:1;
        RBus_UInt32  dc_phy_ls:1;
        RBus_UInt32  res2:22;
    };
}dc_phy_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_phy_ptg_ready:1;
        RBus_UInt32  res1:31;
    };
}ptg_ready_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_phy_ptg_sel:1;
        RBus_UInt32  dc_phy_ptg_clk_en:1;
        RBus_UInt32  dc_phy_ptg_rst_n:1;
        RBus_UInt32  res1:29;
    };
}ptg_select_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eff_meas_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  meas_period:14;
        RBus_UInt32  res2:10;
    };
}eff_meas_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_cnt:29;
        RBus_UInt32  res1:3;
    };
}read_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_cnt:29;
        RBus_UInt32  res1:3;
    };
}write_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_chop_cnt:29;
        RBus_UInt32  res1:3;
    };
}read_chop_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_chop_cnt:29;
        RBus_UInt32  res1:3;
    };
}write_chop_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  active_cnt_bank0:29;
        RBus_UInt32  res1:3;
    };
}act_bank_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  precharge_cnt_bank0:29;
        RBus_UInt32  res1:3;
    };
}prechg_bank_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  active_cnt_bank1:29;
        RBus_UInt32  res1:3;
    };
}act_bank_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  precharge_cnt_bank1:29;
        RBus_UInt32  res1:3;
    };
}prechg_bank_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  active_cnt_bank2:29;
        RBus_UInt32  res1:3;
    };
}act_bank_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  precharge_cnt_bank2:29;
        RBus_UInt32  res1:3;
    };
}prechg_bank_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  active_cnt_bank3:29;
        RBus_UInt32  res1:3;
    };
}act_bank_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  precharge_cnt_bank3:29;
        RBus_UInt32  res1:3;
    };
}prechg_bank_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  active_cnt_bank4:29;
        RBus_UInt32  res1:3;
    };
}act_bank_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  precharge_cnt_bank4:29;
        RBus_UInt32  res1:3;
    };
}prechg_bank_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  active_cnt_bank5:29;
        RBus_UInt32  res1:3;
    };
}act_bank_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  precharge_cnt_bank5:29;
        RBus_UInt32  res1:3;
    };
}prechg_bank_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  active_cnt_bank6:29;
        RBus_UInt32  res1:3;
    };
}act_bank_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  precharge_cnt_bank6:29;
        RBus_UInt32  res1:3;
    };
}prechg_bank_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  active_cnt_bank7:29;
        RBus_UInt32  res1:3;
    };
}act_bank_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  precharge_cnt_bank7:29;
        RBus_UInt32  res1:3;
    };
}prechg_bank_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w2r_cnt:27;
        RBus_UInt32  res1:5;
    };
}write_to_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r2w_cnt:27;
        RBus_UInt32  res1:5;
    };
}read_to_write_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_to_cmd_w:26;
        RBus_UInt32  res1:6;
    };
}write_cmd_latency_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_to_cmd_r:26;
        RBus_UInt32  res1:6;
    };
}read_cmd_latency_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bank_conflict_cnt:20;
        RBus_UInt32  res1:12;
    };
}bank_conflict_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_merge_cnt_exp:28;
        RBus_UInt32  res1:4;
    };
}write_merge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_bypass_cnt_exp:28;
        RBus_UInt32  res1:4;
    };
}read_bypass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_bypass_cnt_dc_sys1:28;
        RBus_UInt32  res1:4;
    };
}dc_sys1_read_bypass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_ap_cnt:29;
        RBus_UInt32  res1:3;
    };
}read_cmd_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ap_cnt:29;
        RBus_UInt32  res1:3;
    };
}write_cmd_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bank_weight_en:1;
        RBus_UInt32  length_weight_en:1;
        RBus_UInt32  direction_weight_en:1;
        RBus_UInt32  priority_weight_en:1;
        RBus_UInt32  outstand_reorder_en:1;
        RBus_UInt32  res1:27;
    };
}weight_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pw_multiplier:3;
        RBus_UInt32  pw_sys2_level:1;
        RBus_UInt32  pw_sys1_level:1;
        RBus_UInt32  res1:27;
    };
}weight_priority_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dw_multiplier:3;
        RBus_UInt32  dw_init_w:8;
        RBus_UInt32  dw_init_r:8;
        RBus_UInt32  dw_init_dynamic_en:1;
        RBus_UInt32  res1:12;
    };
}weight_dierection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lw_multiplier:3;
        RBus_UInt32  lw_long_burst_prior:1;
        RBus_UInt32  res1:28;
    };
}weight_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bw_multiplier:3;
        RBus_UInt32  bw_trp:5;
        RBus_UInt32  bw_trc:7;
        RBus_UInt32  bw_pend_en:1;
        RBus_UInt32  bw_pend_cycle:7;
        RBus_UInt32  bw_pend_mode:1;
        RBus_UInt32  res1:8;
    };
}weight_bank_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  express_lane_wr_separate_en:1;
        RBus_UInt32  express_lane_group_en:1;
        RBus_UInt32  dc_sys1_group_en:1;
        RBus_UInt32  read_bypass_seq_mode:1;
        RBus_UInt32  priority_down_sample_rate:2;
        RBus_UInt32  res1:26;
    };
}multi_client_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_queue_cnt:3;
        RBus_UInt32  read_cmd_queue_cnt:3;
        RBus_UInt32  write_buffer_0_occupy:1;
        RBus_UInt32  write_buffer_1_occupy:1;
        RBus_UInt32  write_buffer_2_occupy:1;
        RBus_UInt32  write_buffer_3_occupy:1;
        RBus_UInt32  res1:22;
    };
}express_lane_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qos_0_req:1;
        RBus_UInt32  qos_1_req:1;
        RBus_UInt32  qos_2_req:1;
        RBus_UInt32  qos_3_req:1;
        RBus_UInt32  qos_4_req:1;
        RBus_UInt32  qos_5_req:1;
        RBus_UInt32  weight_0_req:1;
        RBus_UInt32  weight_1_req:1;
        RBus_UInt32  weight_2_req:1;
        RBus_UInt32  weight_3_req:1;
        RBus_UInt32  weight_4_req:1;
        RBus_UInt32  weight_5_req:1;
        RBus_UInt32  qos_0_bank_wait_error:1;
        RBus_UInt32  qos_1_bank_wait_error:1;
        RBus_UInt32  qos_2_bank_wait_error:1;
        RBus_UInt32  qos_3_bank_wait_error:1;
        RBus_UInt32  qos_4_bank_wait_error:1;
        RBus_UInt32  qos_5_bank_wait_error:1;
        RBus_UInt32  res1:14;
    };
}weight_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr4:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ddr4_wr_crc_en:1;
        RBus_UInt32  ddr4_ca_parity_en:1;
        RBus_UInt32  ddr4_parity_add_sel:1;
        RBus_UInt32  ddr4_rd_dbi_en:1;
        RBus_UInt32  ddr4_record_cmd_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  alert_n_pw_judge:8;
        RBus_UInt32  res3:2;
        RBus_UInt32  ddr4_gear_set_dpi_sel:1;
        RBus_UInt32  ddr4_pda_mrs_dram_sel:1;
        RBus_UInt32  ddr4_wr_crc_bl8_use_dm:1;
        RBus_UInt32  ddr4_wr_crc_bc4_use_dm:1;
        RBus_UInt32  res4:10;
    };
}ddr4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tmccd_l:4;
        RBus_UInt32  tmrrd_l:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  tmwtr_l:5;
        RBus_UInt32  res2:15;
    };
}ddr4_tm0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode_reg4:16;
        RBus_UInt32  mode_reg5:16;
    };
}ddr4_mr45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode_reg6:16;
        RBus_UInt32  res1:16;
    };
}ddr4_mr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  alert_n_pw_0:8;
        RBus_UInt32  alert_n_pw_1:8;
        RBus_UInt32  ddr4_parity_en:1;
        RBus_UInt32  ddr4_wr_crc_en:1;
        RBus_UInt32  ddr4_mpr_rw_en:1;
        RBus_UInt32  ddr4_gear_down_en:1;
        RBus_UInt32  ddr4_max_pw_sav_en:1;
        RBus_UInt32  ddr4_rd_dbi_en:1;
        RBus_UInt32  ddr4_pda_en:1;
        RBus_UInt32  res1:9;
    };
}ddr4_alert_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr4_exe_mr4:1;
        RBus_UInt32  write_en_0:1;
        RBus_UInt32  ddr4_exe_mr5:1;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  ddr4_exe_mr6:1;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  exe_mpr_rd:1;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  exe_mpr_wr:1;
        RBus_UInt32  write_en_4:1;
        RBus_UInt32  res1:22;
    };
}dc_ddr4_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_rw_add:8;
        RBus_UInt32  mpr_rw_bank:2;
        RBus_UInt32  res1:22;
    };
}ddr4_exe_rw_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  exp_wr_block_en:1;
        RBus_UInt32  exp_rd_block_en:1;
        RBus_UInt32  dc_sys1_wr_block_en:1;
        RBus_UInt32  dc_sys1_rd_block_en:1;
        RBus_UInt32  dc_sys2_wr_block_en:1;
        RBus_UInt32  dc_sys2_rd_block_en:1;
        RBus_UInt32  res1:26;
    };
}block_req_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fail_cmd:25;
        RBus_UInt32  res1:7;
    };
}ddr4_fail_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_0:8;
        RBus_UInt32  mpr_data_1:8;
        RBus_UInt32  mpr_data_2:8;
        RBus_UInt32  mpr_data_3:8;
    };
}ddr4_mpr_rd_dat0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_4:8;
        RBus_UInt32  mpr_data_5:8;
        RBus_UInt32  mpr_data_6:8;
        RBus_UInt32  mpr_data_7:8;
    };
}ddr4_mpr_rd_dat1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_8:8;
        RBus_UInt32  mpr_data_9:8;
        RBus_UInt32  mpr_data_10:8;
        RBus_UInt32  mpr_data_11:8;
    };
}ddr4_mpr_rd_dat2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_12:8;
        RBus_UInt32  mpr_data_13:8;
        RBus_UInt32  mpr_data_14:8;
        RBus_UInt32  mpr_data_15:8;
    };
}ddr4_mpr_rd_dat3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_16:8;
        RBus_UInt32  mpr_data_17:8;
        RBus_UInt32  mpr_data_18:8;
        RBus_UInt32  mpr_data_19:8;
    };
}ddr4_mpr_rd_dat4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_20:8;
        RBus_UInt32  mpr_data_21:8;
        RBus_UInt32  mpr_data_22:8;
        RBus_UInt32  mpr_data_23:8;
    };
}ddr4_mpr_rd_dat5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_24:8;
        RBus_UInt32  mpr_data_25:8;
        RBus_UInt32  mpr_data_26:8;
        RBus_UInt32  mpr_data_27:8;
    };
}ddr4_mpr_rd_dat6_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpr_data_28:8;
        RBus_UInt32  mpr_data_29:8;
        RBus_UInt32  mpr_data_30:8;
        RBus_UInt32  mpr_data_31:8;
    };
}ddr4_mpr_rd_dat6_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ref_rst_en_tx:1;
        RBus_UInt32  bypass_en_tx:1;
        RBus_UInt32  force_rst_n_tx:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ref_rst_en_rx:1;
        RBus_UInt32  bypass_en_rx:1;
        RBus_UInt32  force_rst_n_rx:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ref_rst_dly_tx:8;
        RBus_UInt32  ref_rst_dly_rx:8;
        RBus_UInt32  res3:8;
    };
}cts_fifo_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_sys1_path_sel:1;
        RBus_UInt32  dc_sys1_read_bypass_en:1;
        RBus_UInt32  dc_sys1_read_bypass_rw_separate_en:1;
        RBus_UInt32  dc_sys1_read_bypass_seq_mode:1;
        RBus_UInt32  res1:28;
    };
}dc_sys1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_sys2_rw_sep_en:1;
        RBus_UInt32  dc_sys2_client_sep_enable:1;
        RBus_UInt32  dc_sys2_wr_qfifo_en:1;
        RBus_UInt32  res1:29;
    };
}dc_sys2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bw_en:1;
        RBus_UInt32  lat_en:1;
        RBus_UInt32  stp_ref_cal_en:1;
        RBus_UInt32  occ_status_clear:1;
        RBus_UInt32  ot_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  ki_pos:12;
        RBus_UInt32  ki_neg:12;
    };
}qos_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_otf:8;
        RBus_UInt32  max_oti:4;
        RBus_UInt32  qos_ot_dummy:20;
    };
}qos_ot_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  add_data:8;
        RBus_UInt32  idle_period:16;
        RBus_UInt32  res1:8;
    };
}qos_bw0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  min_data:16;
        RBus_UInt32  max_data:16;
    };
}qos_bw1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  min_pri:8;
        RBus_UInt32  def_pri:8;
        RBus_UInt32  max_pri:8;
        RBus_UInt32  res1:8;
    };
}qos_bw2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_data:16;
        RBus_UInt32  cur_pri:8;
        RBus_UInt32  pri_min_occ:1;
        RBus_UInt32  pri_max_occ:1;
        RBus_UInt32  cur_data_min_occ:1;
        RBus_UInt32  cur_data_max_occ:1;
        RBus_UInt32  res1:4;
    };
}qos_bw3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lat_lower:16;
        RBus_UInt32  lat_upper:16;
    };
}qos_lat0_RBUS;




#endif 


#endif 
