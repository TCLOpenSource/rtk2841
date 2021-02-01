/**
* @file rbusMd_parserReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
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
#define  MD_PARSER_MDP_CR_max_packet_num_shift                                   (8)
#define  MD_PARSER_MDP_CR_dummy_7_5_shift                                        (5)
#define  MD_PARSER_MDP_CR_dummy_4_shift                                          (4)
#define  MD_PARSER_MDP_CR_dummy_3_shift                                          (3)
#define  MD_PARSER_MDP_CR_mode_shift                                             (1)
#define  MD_PARSER_MDP_CR_en_shift                                               (0)
#define  MD_PARSER_MDP_CR_max_packet_num_mask                                    (0x0001FF00)
#define  MD_PARSER_MDP_CR_dummy_7_5_mask                                         (0x000000E0)
#define  MD_PARSER_MDP_CR_dummy_4_mask                                           (0x00000010)
#define  MD_PARSER_MDP_CR_dummy_3_mask                                           (0x00000008)
#define  MD_PARSER_MDP_CR_mode_mask                                              (0x00000006)
#define  MD_PARSER_MDP_CR_en_mask                                                (0x00000001)
#define  MD_PARSER_MDP_CR_max_packet_num(data)                                   (0x0001FF00&((data)<<8))
#define  MD_PARSER_MDP_CR_dummy_7_5(data)                                        (0x000000E0&((data)<<5))
#define  MD_PARSER_MDP_CR_dummy_4(data)                                          (0x00000010&((data)<<4))
#define  MD_PARSER_MDP_CR_dummy_3(data)                                          (0x00000008&((data)<<3))
#define  MD_PARSER_MDP_CR_mode(data)                                             (0x00000006&((data)<<1))
#define  MD_PARSER_MDP_CR_en(data)                                               (0x00000001&(data))
#define  MD_PARSER_MDP_CR_get_max_packet_num(data)                               ((0x0001FF00&(data))>>8)
#define  MD_PARSER_MDP_CR_get_dummy_7_5(data)                                    ((0x000000E0&(data))>>5)
#define  MD_PARSER_MDP_CR_get_dummy_4(data)                                      ((0x00000010&(data))>>4)
#define  MD_PARSER_MDP_CR_get_dummy_3(data)                                      ((0x00000008&(data))>>3)
#define  MD_PARSER_MDP_CR_get_mode(data)                                         ((0x00000006&(data))>>1)
#define  MD_PARSER_MDP_CR_get_en(data)                                           (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MD_PARSER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  max_packet_num:9;
        RBus_UInt32  dummy18027600_7_5:3;
        RBus_UInt32  dummy18027600_4:1;
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
        RBus_UInt32  dummy18027600_4:1;
        RBus_UInt32  dummy18027600_7:3;
        RBus_UInt32  max_packet_num:9;
        RBus_UInt32  res1:15;
    };
}md_parser_mdp_cr_RBUS;




#endif 


#endif 
