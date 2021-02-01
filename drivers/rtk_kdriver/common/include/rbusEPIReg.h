/**
* @file rbusVgipReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2012-12-25
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_EPI_REG_H_
#define _RBUS_EPI_REG_H_

#include "rbus/rbusTypes.h"




// EPI Register Address

#define EPI_PACKET_CTR_START_VADDR            (0xb802d500)
#define EPI_PACKET_CTR1_0_0_VADDR             (0xb802d504)
#define EPI_PACKET_CTR1_0_1_VADDR             (0xb802d508)
#define EPI_PACKET_CTR1_0_2_VADDR             (0xb802d50c)
#define EPI_PACKET_CTR1_0_3_VADDR             (0xb802d510)
#define EPI_PACKET_CTR1_0_4_VADDR             (0xb802d514)
#define EPI_PACKET_CTR1_0_5_VADDR             (0xb802d518)
#define EPI_PACKET_CTR1_0_6_VADDR             (0xb802d51c)
#define EPI_PACKET_CTR1_0_7_VADDR             (0xb802d520)
#define EPI_PACKET_CTR1_1_0_VADDR             (0xb802d524)
#define EPI_PACKET_CTR1_1_1_VADDR             (0xb802d528)
#define EPI_PACKET_CTR1_1_2_VADDR             (0xb802d52c)
#define EPI_PACKET_CTR1_1_3_VADDR             (0xb802d530)
#define EPI_PACKET_CTR1_1_4_VADDR             (0xb802d534)
#define EPI_PACKET_CTR1_1_5_VADDR             (0xb802d538)
#define EPI_PACKET_CTR1_1_6_VADDR             (0xb802d53c)
#define EPI_PACKET_CTR1_1_7_VADDR             (0xb802d540)
#define EPI_PACKET_CTR2_0_0_VADDR             (0xb802d544)
#define EPI_PACKET_CTR2_0_1_VADDR             (0xb802d548)
#define EPI_PACKET_CTR2_0_2_VADDR             (0xb802d54c)
#define EPI_PACKET_CTR2_0_3_VADDR             (0xb802d550)
#define EPI_PACKET_CTR2_0_4_VADDR             (0xb802d554)
#define EPI_PACKET_CTR2_0_5_VADDR             (0xb802d558)
#define EPI_PACKET_CTR2_0_6_VADDR             (0xb802d55c)
#define EPI_PACKET_CTR2_0_7_VADDR             (0xb802d560)
#define EPI_PACKET_CTR2_1_VADDR               (0xb802d564)
#define EPI_PACKET_CTR2_2_VADDR               (0xb802d568)
#define EPI_PACKET_CTR2_3_VADDR               (0xb802d56c)
#define EPI_PACKET_CTR2_4_VADDR               (0xb802d570)
#define EPI_PACKET_CTR2_5_VADDR               (0xb802d574)
#define EPI_PACKET_CTR3_VADDR                 (0xb802d578)
#define EPI_PACKET_DATA_START_VADDR           (0xb802d57c)
#define EPI_PACKET_CTRL_VADDR                 (0xb802d580)
#define EPI_CLOCK_CTRL_VADDR                  (0xb802d584)
#define EPI_PORT_OPTION_CTRL_VADDR            (0xb802d588)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======EPI register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pn_swap:1;
        RBus_UInt32  ctr_start_dummy:24;
        RBus_UInt32  ctr_start_indicator:6;
    };
}epi_packet_ctr_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_width_num_0:16;
        RBus_UInt32  soe_sta_num_0:16;
    };
}epi_packet_ctr1_0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_width_num_1:16;
        RBus_UInt32  soe_sta_num_1:16;
    };
}epi_packet_ctr1_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_width_num_2:16;
        RBus_UInt32  soe_sta_num_2:16;
    };
}epi_packet_ctr1_0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_width_num_3:16;
        RBus_UInt32  soe_sta_num_3:16;
    };
}epi_packet_ctr1_0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_width_num_4:16;
        RBus_UInt32  soe_sta_num_4:16;
    };
}epi_packet_ctr1_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_width_num_5:16;
        RBus_UInt32  soe_sta_num_5:16;
    };
}epi_packet_ctr1_0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_width_num_6:16;
        RBus_UInt32  soe_sta_num_6:16;
    };
}epi_packet_ctr1_0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_width_num_7:16;
        RBus_UInt32  soe_sta_num_7:16;
    };
}epi_packet_ctr1_0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ctr1_dummy:12;
        RBus_UInt32  soe_width_pkt_0:10;
        RBus_UInt32  soe_sta_pkt_0:8;
    };
}epi_packet_ctr1_1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:12;
        RBus_UInt32  soe_width_pkt_1:10;
        RBus_UInt32  soe_sta_pkt_1:8;
    };
}epi_packet_ctr1_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:12;
        RBus_UInt32  soe_width_pkt_2:10;
        RBus_UInt32  soe_sta_pkt_2:8;
    };
}epi_packet_ctr1_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:12;
        RBus_UInt32  soe_width_pkt_3:10;
        RBus_UInt32  soe_sta_pkt_3:8;
    };
}epi_packet_ctr1_1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:12;
        RBus_UInt32  soe_width_pkt_4:10;
        RBus_UInt32  soe_sta_pkt_4:8;
    };
}epi_packet_ctr1_1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:12;
        RBus_UInt32  soe_width_pkt_5:10;
        RBus_UInt32  soe_sta_pkt_5:8;
    };
}epi_packet_ctr1_1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:12;
        RBus_UInt32  soe_width_pkt_6:10;
        RBus_UInt32  soe_sta_pkt_6:8;
    };
}epi_packet_ctr1_1_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:12;
        RBus_UInt32  soe_width_pkt_7:10;
        RBus_UInt32  soe_sta_pkt_7:8;
    };
}epi_packet_ctr1_1_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ctr2_data_0:30;
    };
}epi_packet_ctr2_0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ctr2_data_1:30;
    };
}epi_packet_ctr2_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ctr2_data_2:30;
    };
}epi_packet_ctr2_0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ctr2_data_3:30;
    };
}epi_packet_ctr2_0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ctr2_data_4:30;
    };
}epi_packet_ctr2_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ctr2_data_5:30;
    };
}epi_packet_ctr2_0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ctr2_data_6:30;
    };
}epi_packet_ctr2_0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ctr2_data_7:30;
    };
}epi_packet_ctr2_0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon_sel_c5:5;
        RBus_UInt32  tcon_sel_c4:5;
        RBus_UInt32  tcon_sel_c3:5;
        RBus_UInt32  tcon_sel_c2:5;
        RBus_UInt32  tcon_sel_c1:5;
        RBus_UInt32  tcon_sel_c0:5;
    };
}epi_packet_ctr2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon_sel_c11:5;
        RBus_UInt32  tcon_sel_c10:5;
        RBus_UInt32  tcon_sel_c9:5;
        RBus_UInt32  tcon_sel_c8:5;
        RBus_UInt32  tcon_sel_c7:5;
        RBus_UInt32  tcon_sel_c6:5;
    };
}epi_packet_ctr2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon_sel_c17:5;
        RBus_UInt32  tcon_sel_c16:5;
        RBus_UInt32  tcon_sel_c15:5;
        RBus_UInt32  tcon_sel_c14:5;
        RBus_UInt32  tcon_sel_c13:5;
        RBus_UInt32  tcon_sel_c12:5;
    };
}epi_packet_ctr2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon_sel_c23:5;
        RBus_UInt32  tcon_sel_c22:5;
        RBus_UInt32  tcon_sel_c21:5;
        RBus_UInt32  tcon_sel_c20:5;
        RBus_UInt32  tcon_sel_c19:5;
        RBus_UInt32  tcon_sel_c18:5;
    };
}epi_packet_ctr2_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon_sel_c29:5;
        RBus_UInt32  tcon_sel_c28:5;
        RBus_UInt32  tcon_sel_c27:5;
        RBus_UInt32  tcon_sel_c26:5;
        RBus_UInt32  tcon_sel_c25:5;
        RBus_UInt32  tcon_sel_c24:5;
    };
}epi_packet_ctr2_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ctr3_enable:1;
        RBus_UInt32  ctr3_data:30;
    };
}epi_packet_ctr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  data_start_dummy:24;
        RBus_UInt32  data_start_indicator:6;
    };
}epi_packet_data_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  epi_data_unfl:1;
        RBus_UInt32  epi_data_unfl_clr:1;
        RBus_UInt32  prbs7_tx_en:1;
        RBus_UInt32  epi_bit_mode:2;
        RBus_UInt32  res1:27;
    };
}epi_packet_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  force_ctsfifo_rstn_epi:1;
        RBus_UInt32  en_ctsfifo_vsrst_epi:1;
        RBus_UInt32  en_ctsfifo_bypass_epi:1;
        RBus_UInt32  epi_reset:1;
        RBus_UInt32  res1:24;
        RBus_UInt32  hw_lock:1;
        RBus_UInt32  epi_lock:1;
        RBus_UInt32  epi_lock_sel:1;
        RBus_UInt32  res2:1;
    };
}epi_clock_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  back_value:2;
        RBus_UInt32  front_value:2;
        RBus_UInt32  map_type_sel:2;
        RBus_UInt32  soe_offset_en:1;
        RBus_UInt32  epi_otpin_ver_sel:1;
        RBus_UInt32  soe_sel_1:3;
        RBus_UInt32  epi_otpin_port_sel:3;
    };
}epi_port_option_ctrl_RBUS;





#else //apply LITTLE_ENDIAN


//======EPI register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctr_start_indicator:6;
        RBus_UInt32  ctr_start_dummy:24;
        RBus_UInt32  pn_swap:1;
        RBus_UInt32  res1:1;
    };
}epi_packet_ctr_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_num_0:16;
        RBus_UInt32  soe_width_num_0:16;
    };
}epi_packet_ctr1_0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_num_1:16;
        RBus_UInt32  soe_width_num_1:16;
    };
}epi_packet_ctr1_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_num_2:16;
        RBus_UInt32  soe_width_num_2:16;
    };
}epi_packet_ctr1_0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_num_3:16;
        RBus_UInt32  soe_width_num_3:16;
    };
}epi_packet_ctr1_0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_num_4:16;
        RBus_UInt32  soe_width_num_4:16;
    };
}epi_packet_ctr1_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_num_5:16;
        RBus_UInt32  soe_width_num_5:16;
    };
}epi_packet_ctr1_0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_num_6:16;
        RBus_UInt32  soe_width_num_6:16;
    };
}epi_packet_ctr1_0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_num_7:16;
        RBus_UInt32  soe_width_num_7:16;
    };
}epi_packet_ctr1_0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_pkt_0:8;
        RBus_UInt32  soe_width_pkt_0:10;
        RBus_UInt32  ctr1_dummy:12;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr1_1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_pkt_1:8;
        RBus_UInt32  soe_width_pkt_1:10;
        RBus_UInt32  res2:12;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr1_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_pkt_2:8;
        RBus_UInt32  soe_width_pkt_2:10;
        RBus_UInt32  res2:12;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr1_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_pkt_3:8;
        RBus_UInt32  soe_width_pkt_3:10;
        RBus_UInt32  res2:12;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr1_1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_pkt_4:8;
        RBus_UInt32  soe_width_pkt_4:10;
        RBus_UInt32  res2:12;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr1_1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_pkt_5:8;
        RBus_UInt32  soe_width_pkt_5:10;
        RBus_UInt32  res2:12;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr1_1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_pkt_6:8;
        RBus_UInt32  soe_width_pkt_6:10;
        RBus_UInt32  res2:12;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr1_1_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soe_sta_pkt_7:8;
        RBus_UInt32  soe_width_pkt_7:10;
        RBus_UInt32  res2:12;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr1_1_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctr2_data_0:30;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr2_0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctr2_data_1:30;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr2_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctr2_data_2:30;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr2_0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctr2_data_3:30;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr2_0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctr2_data_4:30;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr2_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctr2_data_5:30;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr2_0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctr2_data_6:30;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr2_0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctr2_data_7:30;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr2_0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_sel_c0:5;
        RBus_UInt32  tcon_sel_c1:5;
        RBus_UInt32  tcon_sel_c2:5;
        RBus_UInt32  tcon_sel_c3:5;
        RBus_UInt32  tcon_sel_c4:5;
        RBus_UInt32  tcon_sel_c5:5;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_sel_c6:5;
        RBus_UInt32  tcon_sel_c7:5;
        RBus_UInt32  tcon_sel_c8:5;
        RBus_UInt32  tcon_sel_c9:5;
        RBus_UInt32  tcon_sel_c10:5;
        RBus_UInt32  tcon_sel_c11:5;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_sel_c12:5;
        RBus_UInt32  tcon_sel_c13:5;
        RBus_UInt32  tcon_sel_c14:5;
        RBus_UInt32  tcon_sel_c15:5;
        RBus_UInt32  tcon_sel_c16:5;
        RBus_UInt32  tcon_sel_c17:5;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_sel_c18:5;
        RBus_UInt32  tcon_sel_c19:5;
        RBus_UInt32  tcon_sel_c20:5;
        RBus_UInt32  tcon_sel_c21:5;
        RBus_UInt32  tcon_sel_c22:5;
        RBus_UInt32  tcon_sel_c23:5;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr2_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_sel_c24:5;
        RBus_UInt32  tcon_sel_c25:5;
        RBus_UInt32  tcon_sel_c26:5;
        RBus_UInt32  tcon_sel_c27:5;
        RBus_UInt32  tcon_sel_c28:5;
        RBus_UInt32  tcon_sel_c29:5;
        RBus_UInt32  res1:2;
    };
}epi_packet_ctr2_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctr3_data:30;
        RBus_UInt32  ctr3_enable:1;
        RBus_UInt32  res1:1;
    };
}epi_packet_ctr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_start_indicator:6;
        RBus_UInt32  data_start_dummy:24;
        RBus_UInt32  res1:2;
    };
}epi_packet_data_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  epi_bit_mode:2;
        RBus_UInt32  prbs7_tx_en:1;
        RBus_UInt32  epi_data_unfl_clr:1;
        RBus_UInt32  epi_data_unfl:1;
    };
}epi_packet_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:1;
        RBus_UInt32  epi_lock_sel:1;
        RBus_UInt32  epi_lock:1;
        RBus_UInt32  hw_lock:1;
        RBus_UInt32  res1:24;
        RBus_UInt32  epi_reset:1;
        RBus_UInt32  en_ctsfifo_bypass_epi:1;
        RBus_UInt32  en_ctsfifo_vsrst_epi:1;
        RBus_UInt32  force_ctsfifo_rstn_epi:1;
    };
}epi_clock_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  epi_otpin_port_sel:3;
        RBus_UInt32  soe_sel_1:3;
        RBus_UInt32  epi_otpin_ver_sel:1;
        RBus_UInt32  soe_offset_en:1;
        RBus_UInt32  map_type_sel:2;
        RBus_UInt32  front_value:2;
        RBus_UInt32  back_value:2;
        RBus_UInt32  res1:18;
    };
}epi_port_option_ctrl_RBUS;


#endif







#endif //_RBUS_EPI_REG_H_

