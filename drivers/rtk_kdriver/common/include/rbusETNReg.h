/**
* @file rbusDefaultReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2010/6/4
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_ETN_REG_H_
#define _RBUS_ETN_REG_H_

#include "rbusTypes.h"




// ETN Register Address

#define ETN_ETN_IDR_03_VADDR                   (0xb8016800)
#define ETN_ETN_IDR_45_VADDR                   (0xb8016804)
#define ETN_ETN_MAR_03_VADDR                   (0xb8016808)
#define ETN_ETN_MAR_47_VADDR                   (0xb801680c)
#define ETN_ETN_TX_RX_CNT_VADDR                (0xb8016810)
#define ETN_ETN_TX_RX_ERR_VADDR                (0xb8016814)
#define ETN_ETN_MISS_FAE_VADDR                 (0xb8016818)
#define ETN_ETN_TX_COL_VADDR                   (0xb801681c)
#define ETN_ETN_RX_OK1_VADDR                   (0xb8016820)
#define ETN_ETN_RX_OK2_VADDR                   (0xb8016824)
#define ETN_ETN_TX_UN_VADDR                    (0xb8016828)
#define ETN_ETN_TRSR_VADDR                     (0xb8016834)
#define ETN_ETN_CR_VADDR                       (0xb8016838)
#define ETN_ETN_IMR_ISR_VADDR                  (0xb801683c)
#define ETN_ETN_TCR_VADDR                      (0xb8016840)
#define ETN_ETN_RCR_VADDR                      (0xb8016844)
#define ETN_ETN_MSR_VADDR                      (0xb8016858)
#define ETN_ETN_MII_AR_VADDR                   (0xb801685c)
#define ETN_ETN_SWINT_VADDR                    (0xb8016860)
#define ETN_ETN_TXFPD1_VADDR                   (0xb8016900)
#define ETN_ETN_TXCDO1_VADDR                   (0xb8016904)
#define ETN_ETN_TXFPD2_VADDR                   (0xb8016980)
#define ETN_ETN_TXCDO2_VADDR                   (0xb8016984)
#define ETN_LED_CTRL_VADDR                     (0xb8016988)
#define ETN_BIST_CTRL_VADDR                    (0xb801698c)
#define ETN_ETN_RXFPD_VADDR                    (0xb80169f0)
#define ETN_ETN_RXCDO_VADDR                    (0xb80169f4)
#define ETN_ETN_RXPLEN_VADDR                   (0xb8016a00)
#define ETN_ETN_RDESN_VADDR                    (0xb8016a30)
#define ETN_ETN_IOCMD_VADDR                    (0xb8016a34)
#define ETN_ETN_WOL_VADDR	                    (0xb8016a38)
#define ETN_ETN_PHY_INFO_VADDR					  (0xb8016a3c)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======ETN register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idr0:8;
        RBus_UInt32  idr1:8;
        RBus_UInt32  idr2:8;
        RBus_UInt32  idr3:8;
    };
}etn_etn_idr_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idr4:8;
        RBus_UInt32  idr5:8;
        RBus_UInt32  dummy18016004_15_0:16;
    };
}etn_etn_idr_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mar0:8;
        RBus_UInt32  mar1:8;
        RBus_UInt32  mar2:8;
        RBus_UInt32  mar3:8;
    };
}etn_etn_mar_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mar4:8;
        RBus_UInt32  mar5:8;
        RBus_UInt32  mar6:8;
        RBus_UInt32  mar7:8;
    };
}etn_etn_mar_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txokc:16;
        RBus_UInt32  rxokc:16;
    };
}etn_etn_tx_rx_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txerr:16;
        RBus_UInt32  rxerr:16;
    };
}etn_etn_tx_rx_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  misspkt:16;
        RBus_UInt32  fae:16;
    };
}etn_etn_miss_fae_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx1col:16;
        RBus_UInt32  txmcol:16;
    };
}etn_etn_tx_col_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxokphy:16;
        RBus_UInt32  rxokbrd:16;
    };
}etn_etn_rx_ok1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxokmul:16;
        RBus_UInt32  txabt:16;
    };
}etn_etn_rx_ok2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txundrn:16;
        RBus_UInt32  dummy18016028_15_0:16;
    };
}etn_etn_tx_un_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016034_31_4:28;
        RBus_UInt32  tok:1;
        RBus_UInt32  tun:1;
        RBus_UInt32  rxfifoempty:1;
        RBus_UInt32  rxfifofull:1;
    };
}etn_etn_trsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016038_31_4:28;
        RBus_UInt32  pow_etn_l:1;
        RBus_UInt32  rxvlan:1;
        RBus_UInt32  rxchksum:1;
        RBus_UInt32  rst:1;
    };
}etn_etn_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1801603c_31_27:5;
        RBus_UInt32  swint_en:1;
        RBus_UInt32  tdu_en:1;
        RBus_UInt32  punlinkchg_en:1;
        RBus_UInt32  ter_en:1;
        RBus_UInt32  tokti_en:1;
        RBus_UInt32  rdu_en:1;
        RBus_UInt32  rer_ovf_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rer_runt_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rok_en:1;
        RBus_UInt32  res3:5;
        RBus_UInt32  swint:1;
        RBus_UInt32  tdu:1;
        RBus_UInt32  punlinkchg:1;
        RBus_UInt32  ter:1;
        RBus_UInt32  tokti:1;
        RBus_UInt32  rdu:1;
        RBus_UInt32  rer_ovf:1;
        RBus_UInt32  dummy1801603c_3:1;
        RBus_UInt32  rer_runt:1;
        RBus_UInt32  dummy1801603c_1:1;
        RBus_UInt32  rok:1;
    };
}etn_etn_imr_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016040_31_13:19;
        RBus_UInt32  ifg:3;
        RBus_UInt32  lbk1lbk0:2;
        RBus_UInt32  dummy18016040_7_0:8;
    };
}etn_etn_tcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016044_31_7:25;
        RBus_UInt32  afl:1;
        RBus_UInt32  aer:1;
        RBus_UInt32  ar:1;
        RBus_UInt32  ab:1;
        RBus_UInt32  am:1;
        RBus_UInt32  apm:1;
        RBus_UInt32  aap:1;
    };
}etn_etn_rcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  force_txfce:1;
        RBus_UInt32  rxfce:1;
        RBus_UInt32  txfce:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  speed_10:1;
        RBus_UInt32  linkb:1;
        RBus_UInt32  txpf:1;
        RBus_UInt32  rxpf:1;
        RBus_UInt32  dummy18016058_23_0:24;
    };
}etn_etn_msr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag:1;
        RBus_UInt32  phyaddress:5;
        RBus_UInt32  res1:5;
        RBus_UInt32  regaddr4_0:5;
        RBus_UInt32  data15_0:16;
    };
}etn_etn_mii_ar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  swint:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  spreg:4;
        RBus_UInt32  reg_debug_4byte_write:1;
        RBus_UInt32  pwrdn_ana_pll:1;
        RBus_UInt32  pwrdn_dig_phy:1;
        RBus_UInt32  autostop_en:1;
    };
}etn_etn_swint_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txfpd1:24;
        RBus_UInt32  dummy18016100_7_0:8;
    };
}etn_etn_txfpd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016104_31_22:10;
        RBus_UInt32  txcdo1:6;
        RBus_UInt32  dummy18016104_15_0:16;
    };
}etn_etn_txcdo1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txfpd2:24;
        RBus_UInt32  dummy18016180_7_0:8;
    };
}etn_etn_txfpd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016184_31_22:10;
        RBus_UInt32  txcdo2:6;
        RBus_UInt32  dummy18016184_15_0:16;
    };
}etn_etn_txcdo2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  etn_led0_inv:1;
        RBus_UInt32  dummy18016188_22:1;
        RBus_UInt32  etn_led0_ps:2;
        RBus_UInt32  etn_led1_inv:1;
        RBus_UInt32  dummy18016188_18:1;
        RBus_UInt32  etn_led1_ps:2;
        RBus_UInt32  etn_led2_inv:1;
        RBus_UInt32  dummy18016188_14:1;
        RBus_UInt32  etn_led2_ps:2;
        RBus_UInt32  etn_led3_inv:1;
        RBus_UInt32  dummy18016188_10:1;
        RBus_UInt32  etn_led3_ps:2;
        RBus_UInt32  etn_led4_inv:1;
        RBus_UInt32  dummy18016188_6:1;
        RBus_UInt32  etn_led4_ps:2;
        RBus_UInt32  dummy18016188_3_0:4;
    };
}led_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  bist_mode:1;
        RBus_UInt32  bist_rst_n:1;
        RBus_UInt32  bist_done:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
    };
}bist_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxfpd:24;
        RBus_UInt32  dummy180161f0_7_0:8;
    };
}etn_etn_rxfpd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180161f4_31_22:10;
        RBus_UInt32  rxcdo:6;
        RBus_UInt32  dummy180161f4_15_10:6;
        RBus_UInt32  rxringsize:2;
        RBus_UInt32  dummy180161f4_7_0:8;
    };
}etn_etn_rxcdo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016200_31_8:24;
        RBus_UInt32  etn_dbg_en:1;
        RBus_UInt32  etn_sel1:2;
        RBus_UInt32  etn_sel0:2;
        RBus_UInt32  nowr_own:1;
        RBus_UInt32  probesignalselect:2;
    };
}etn_etn_rxplen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016230_31_30:2;
        RBus_UInt32  ethrntrxcpu_des_num:6;
        RBus_UInt32  res1:7;
        RBus_UInt32  wrap:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rx_pse_des_thres:5;
        RBus_UInt32  dummy18016230_7_0:8;
    };
}etn_etn_rdesn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test1:1;
        RBus_UInt32  dummy18016234_30_21:10;
        RBus_UInt32  txth:2;
        RBus_UInt32  txintmitigation:3;
        RBus_UInt32  rxpkttimer:3;
        RBus_UInt32  rxfth:2;
        RBus_UInt32  rxintmitigation:3;
        RBus_UInt32  res1:4;
        RBus_UInt32  re:1;
        RBus_UInt32  te:1;
        RBus_UInt32  txfnl:1;
        RBus_UInt32  txfnh:1;
    };
}etn_etn_iocmd_RBUS;





#else //apply LITTLE_ENDIAN


//======ETN register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idr3:8;
        RBus_UInt32  idr2:8;
        RBus_UInt32  idr1:8;
        RBus_UInt32  idr0:8;
    };
}etn_etn_idr_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016004_15_0:16;
        RBus_UInt32  idr5:8;
        RBus_UInt32  idr4:8;
    };
}etn_etn_idr_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mar3:8;
        RBus_UInt32  mar2:8;
        RBus_UInt32  mar1:8;
        RBus_UInt32  mar0:8;
    };
}etn_etn_mar_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mar7:8;
        RBus_UInt32  mar6:8;
        RBus_UInt32  mar5:8;
        RBus_UInt32  mar4:8;
    };
}etn_etn_mar_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxokc:16;
        RBus_UInt32  txokc:16;
    };
}etn_etn_tx_rx_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxerr:16;
        RBus_UInt32  txerr:16;
    };
}etn_etn_tx_rx_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fae:16;
        RBus_UInt32  misspkt:16;
    };
}etn_etn_miss_fae_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txmcol:16;
        RBus_UInt32  tx1col:16;
    };
}etn_etn_tx_col_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxokbrd:16;
        RBus_UInt32  rxokphy:16;
    };
}etn_etn_rx_ok1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txabt:16;
        RBus_UInt32  rxokmul:16;
    };
}etn_etn_rx_ok2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016028_15_0:16;
        RBus_UInt32  txundrn:16;
    };
}etn_etn_tx_un_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxfifofull:1;
        RBus_UInt32  rxfifoempty:1;
        RBus_UInt32  tun:1;
        RBus_UInt32  tok:1;
        RBus_UInt32  dummy18016034_31_4:28;
    };
}etn_etn_trsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rst:1;
        RBus_UInt32  rxchksum:1;
        RBus_UInt32  rxvlan:1;
        RBus_UInt32  pow_etn_l:1;
        RBus_UInt32  dummy18016038_31_4:28;
    };
}etn_etn_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rok:1;
        RBus_UInt32  dummy1801603c_1:1;
        RBus_UInt32  rer_runt:1;
        RBus_UInt32  dummy1801603c_3:1;
        RBus_UInt32  rer_ovf:1;
        RBus_UInt32  rdu:1;
        RBus_UInt32  tokti:1;
        RBus_UInt32  ter:1;
        RBus_UInt32  punlinkchg:1;
        RBus_UInt32  tdu:1;
        RBus_UInt32  swint:1;
        RBus_UInt32  res3:5;
        RBus_UInt32  rok:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rer_runt:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rer_ovf:1;
        RBus_UInt32  rdu:1;
        RBus_UInt32  tokti:1;
        RBus_UInt32  ter:1;
        RBus_UInt32  punlinkchg:1;
        RBus_UInt32  tdu:1;
        RBus_UInt32  swint_en:1;
        RBus_UInt32  dummy1801603c_31_27:5;
    };
}etn_etn_imr_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016040_7_0:8;
        RBus_UInt32  lbk1lbk0:2;
        RBus_UInt32  ifg:3;
        RBus_UInt32  dummy18016040_31_13:19;
    };
}etn_etn_tcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aap:1;
        RBus_UInt32  apm:1;
        RBus_UInt32  am:1;
        RBus_UInt32  ab:1;
        RBus_UInt32  ar:1;
        RBus_UInt32  aer:1;
        RBus_UInt32  afl:1;
        RBus_UInt32  dummy18016044_31_7:25;
    };
}etn_etn_rcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016058_23_0:24;
        RBus_UInt32  rxpf:1;
        RBus_UInt32  txpf:1;
        RBus_UInt32  linkb:1;
        RBus_UInt32  speed_10:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  txfce:1;
        RBus_UInt32  rxfce:1;
        RBus_UInt32  force_txfce:1;
    };
}etn_etn_msr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data15-0:16;
        RBus_UInt32  regaddr4-0:5;
        RBus_UInt32  res1:5;
        RBus_UInt32  phyaddress:5;
        RBus_UInt32  flag:1;
    };
}etn_etn_mii_ar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  autostop_en:1;
        RBus_UInt32  pwrdn_dig_phy:1;
        RBus_UInt32  pwrdn_ana_pll:1;
        RBus_UInt32  reg_debug_4byte_write:1;
        RBus_UInt32  spreg:4;
        RBus_UInt32  res2:16;
        RBus_UInt32  swint:1;
        RBus_UInt32  res1:7;
    };
}etn_etn_swint_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016100_7_0:8;
        RBus_UInt32  txfpd1:24;
    };
}etn_etn_txfpd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016104_15_0:16;
        RBus_UInt32  txcdo1:6;
        RBus_UInt32  dummy18016104_31_22:10;
    };
}etn_etn_txcdo1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016180_7_0:8;
        RBus_UInt32  txfpd2:24;
    };
}etn_etn_txfpd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016184_15_0:16;
        RBus_UInt32  txcdo2:6;
        RBus_UInt32  dummy18016184_31_22:10;
    };
}etn_etn_txcdo2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016188_3_0:4;
        RBus_UInt32  etn_led4_ps:2;
        RBus_UInt32  dummy18016188_6:1;
        RBus_UInt32  etn_led4_inv:1;
        RBus_UInt32  etn_led3_ps:2;
        RBus_UInt32  dummy18016188_10:1;
        RBus_UInt32  etn_led3_inv:1;
        RBus_UInt32  etn_led2_ps:2;
        RBus_UInt32  dummy18016188_14:1;
        RBus_UInt32  etn_led2_inv:1;
        RBus_UInt32  etn_led1_ps:2;
        RBus_UInt32  dummy18016188_18:1;
        RBus_UInt32  etn_led1_inv:1;
        RBus_UInt32  etn_led0_ps:2;
        RBus_UInt32  dummy18016188_22:1;
        RBus_UInt32  etn_led0_inv:1;
        RBus_UInt32  res1:8;
    };
}led_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_done:1;
        RBus_UInt32  bist_rst_n:1;
        RBus_UInt32  bist_mode:1;
        RBus_UInt32  res1:26;
    };
}bist_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180161f0_7_0:8;
        RBus_UInt32  rxfpd:24;
    };
}etn_etn_rxfpd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180161f4_7_0:8;
        RBus_UInt32  rxringsize:2;
        RBus_UInt32  dummy180161f4_15_10:6;
        RBus_UInt32  rxcdo:6;
        RBus_UInt32  dummy180161f4_31_22:10;
    };
}etn_etn_rxcdo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  probesignalselect:2;
        RBus_UInt32  nowr_own:1;
        RBus_UInt32  etn_sel0:2;
        RBus_UInt32  etn_sel1:2;
        RBus_UInt32  etn_dbg_en:1;
        RBus_UInt32  dummy18016200_31_8:24;
    };
}etn_etn_rxplen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016230_7_0:8;
        RBus_UInt32  rx_pse_des_thres:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  wrap:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  ethrntrxcpu_des_num:6;
        RBus_UInt32  dummy18016230_31_30:2;
    };
}etn_etn_rdesn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txfnh:1;
        RBus_UInt32  txfnl:1;
        RBus_UInt32  te:1;
        RBus_UInt32  re:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  rxintmitigation:3;
        RBus_UInt32  rxfth:2;
        RBus_UInt32  rxpkttimer:3;
        RBus_UInt32  txintmitigation:3;
        RBus_UInt32  txth:2;
        RBus_UInt32  dummy18016234_30_21:10;
        RBus_UInt32  test1:1;
    };
}etn_etn_iocmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Res1:20;
        RBus_UInt32  Force_4byte_align:1;
        RBus_UInt32  Res2:2;
        RBus_UInt32  Swap_wol_compare_nibble:1;
        RBus_UInt32  Wol_int_en:1;
        RBus_UInt32  Wol_pme:1;
        RBus_UInt32  Wol_sts:1;
        RBus_UInt32  Wol_cmd:1;
        RBus_UInt32  Res3:2;
        RBus_UInt32  Fetch_descriptor_swap_enable:1;
        RBus_UInt32  Close_descriptor_swap_enable:1;
    };
}etn_etn_wol_RBUS;


typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Efuse_rdy:1;
        RBus_UInt32  Efuse_default:1;
        RBus_UInt32  Afe_pow_state:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  Page_now:16;
        RBus_UInt32  res2:3;
        RBus_UInt32  Reg_now:5;
    };
}etn_etn_phy_info_RBUS;


#endif







#endif //_RBUS_ETN_REG_H_

