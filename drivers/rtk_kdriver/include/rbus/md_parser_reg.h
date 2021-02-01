/**
* @file Mac5-DesignSpec-M_Domain_md_parser
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MD_PARSER_REG_H_
#define _RBUS_MD_PARSER_REG_H_

#include "rbus_types.h"



//  MD_PARSER Register Address
#define  MD_PARSER_MDP_CR                                                        0x18027600
#define  MD_PARSER_MDP_CR_reg_addr                                               "0xB8027600"
#define  MD_PARSER_MDP_CR_reg                                                    0xB8027600
#define  MD_PARSER_MDP_CR_inst_addr                                              "0x0000"
#define  set_MD_PARSER_MDP_CR_reg(data)                                          (*((volatile unsigned int*)MD_PARSER_MDP_CR_reg)=data)
#define  get_MD_PARSER_MDP_CR_reg                                                (*((volatile unsigned int*)MD_PARSER_MDP_CR_reg))
#define  MD_PARSER_MDP_CR_max_packet_num_shift                                   (16)
#define  MD_PARSER_MDP_CR_dummy_15_shift                                         (15)
#define  MD_PARSER_MDP_CR_dummy_14_shift                                         (14)
#define  MD_PARSER_MDP_CR_dummy_13_shift                                         (13)
#define  MD_PARSER_MDP_CR_dummy_12_shift                                         (12)
#define  MD_PARSER_MDP_CR_dummy_11_shift                                         (11)
#define  MD_PARSER_MDP_CR_dummy_10_8_shift                                       (8)
#define  MD_PARSER_MDP_CR_dummy_7_shift                                          (7)
#define  MD_PARSER_MDP_CR_dummy_6_4_shift                                        (4)
#define  MD_PARSER_MDP_CR_dummy_3_shift                                          (3)
#define  MD_PARSER_MDP_CR_mode_shift                                             (1)
#define  MD_PARSER_MDP_CR_en_shift                                               (0)
#define  MD_PARSER_MDP_CR_max_packet_num_mask                                    (0x01FF0000)
#define  MD_PARSER_MDP_CR_dummy_15_mask                                          (0x00008000)
#define  MD_PARSER_MDP_CR_dummy_14_mask                                          (0x00004000)
#define  MD_PARSER_MDP_CR_dummy_13_mask                                          (0x00002000)
#define  MD_PARSER_MDP_CR_dummy_12_mask                                          (0x00001000)
#define  MD_PARSER_MDP_CR_dummy_11_mask                                          (0x00000800)
#define  MD_PARSER_MDP_CR_dummy_10_8_mask                                        (0x00000700)
#define  MD_PARSER_MDP_CR_dummy_7_mask                                           (0x00000080)
#define  MD_PARSER_MDP_CR_dummy_6_4_mask                                         (0x00000070)
#define  MD_PARSER_MDP_CR_dummy_3_mask                                           (0x00000008)
#define  MD_PARSER_MDP_CR_mode_mask                                              (0x00000006)
#define  MD_PARSER_MDP_CR_en_mask                                                (0x00000001)
#define  MD_PARSER_MDP_CR_max_packet_num(data)                                   (0x01FF0000&((data)<<16))
#define  MD_PARSER_MDP_CR_dummy_15(data)                                         (0x00008000&((data)<<15))
#define  MD_PARSER_MDP_CR_dummy_14(data)                                         (0x00004000&((data)<<14))
#define  MD_PARSER_MDP_CR_dummy_13(data)                                         (0x00002000&((data)<<13))
#define  MD_PARSER_MDP_CR_dummy_12(data)                                         (0x00001000&((data)<<12))
#define  MD_PARSER_MDP_CR_dummy_11(data)                                         (0x00000800&((data)<<11))
#define  MD_PARSER_MDP_CR_dummy_10_8(data)                                       (0x00000700&((data)<<8))
#define  MD_PARSER_MDP_CR_dummy_7(data)                                          (0x00000080&((data)<<7))
#define  MD_PARSER_MDP_CR_dummy_6_4(data)                                        (0x00000070&((data)<<4))
#define  MD_PARSER_MDP_CR_dummy_3(data)                                          (0x00000008&((data)<<3))
#define  MD_PARSER_MDP_CR_mode(data)                                             (0x00000006&((data)<<1))
#define  MD_PARSER_MDP_CR_en(data)                                               (0x00000001&(data))
#define  MD_PARSER_MDP_CR_get_max_packet_num(data)                               ((0x01FF0000&(data))>>16)
#define  MD_PARSER_MDP_CR_get_dummy_15(data)                                     ((0x00008000&(data))>>15)
#define  MD_PARSER_MDP_CR_get_dummy_14(data)                                     ((0x00004000&(data))>>14)
#define  MD_PARSER_MDP_CR_get_dummy_13(data)                                     ((0x00002000&(data))>>13)
#define  MD_PARSER_MDP_CR_get_dummy_12(data)                                     ((0x00001000&(data))>>12)
#define  MD_PARSER_MDP_CR_get_dummy_11(data)                                     ((0x00000800&(data))>>11)
#define  MD_PARSER_MDP_CR_get_dummy_10_8(data)                                   ((0x00000700&(data))>>8)
#define  MD_PARSER_MDP_CR_get_dummy_7(data)                                      ((0x00000080&(data))>>7)
#define  MD_PARSER_MDP_CR_get_dummy_6_4(data)                                    ((0x00000070&(data))>>4)
#define  MD_PARSER_MDP_CR_get_dummy_3(data)                                      ((0x00000008&(data))>>3)
#define  MD_PARSER_MDP_CR_get_mode(data)                                         ((0x00000006&(data))>>1)
#define  MD_PARSER_MDP_CR_get_en(data)                                           (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MD_PARSER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  max_packet_num:9;
        RBus_UInt32  dummy18027600_15:1;
        RBus_UInt32  dummy18027600_14:1;
        RBus_UInt32  dummy18027600_13:1;
        RBus_UInt32  dummy18027600_12:1;
        RBus_UInt32  dummy18027600_11:1;
        RBus_UInt32  dummy18027600_10_8:3;
        RBus_UInt32  dummy18027600_7:1;
        RBus_UInt32  dummy18027600_6_4:3;
        RBus_UInt32  dummy18027600_3:1;
        RBus_UInt32  mode:2;
        RBus_UInt32  en:1;
    };
}md_parser_mdp_cr_RBUS;

#else //apply LITTLE_ENDIAN

//======MD_PARSER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en:1;
        RBus_UInt32  mode:2;
        RBus_UInt32  dummy18027600_3:1;
        RBus_UInt32  dummy18027600_6_4:3;
        RBus_UInt32  dummy18027600_7:1;
        RBus_UInt32  dummy18027600_10_8:3;
        RBus_UInt32  dummy18027600_11:1;
        RBus_UInt32  dummy18027600_12:1;
        RBus_UInt32  dummy18027600_13:1;
        RBus_UInt32  dummy18027600_14:1;
        RBus_UInt32  dummy18027600_15:1;
        RBus_UInt32  max_packet_num:9;
        RBus_UInt32  res1:7;
    };
}md_parser_mdp_cr_RBUS;




#endif 


#endif 
