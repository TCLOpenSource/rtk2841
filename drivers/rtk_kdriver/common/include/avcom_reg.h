/**
* @file rbusAvcomReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_AVCOM_REG_H_
#define _RBUS_AVCOM_REG_H_

#include "rbus_types.h"



//  AVCOM Register Address
#define  AVCOM_AVCOM_Netlist00                                                   0x1802ED00
#define  AVCOM_AVCOM_Netlist00_reg_addr                                          "0xB802ED00"
#define  AVCOM_AVCOM_Netlist00_reg                                               0xB802ED00
#define  AVCOM_AVCOM_Netlist00_inst_addr                                         "0x0000"
#define  set_AVCOM_AVCOM_Netlist00_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist00_reg)=data)
#define  get_AVCOM_AVCOM_Netlist00_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist00_reg))
#define  AVCOM_AVCOM_Netlist00_reg03_shift                                       (24)
#define  AVCOM_AVCOM_Netlist00_reg02_shift                                       (16)
#define  AVCOM_AVCOM_Netlist00_reg01_shift                                       (8)
#define  AVCOM_AVCOM_Netlist00_reg00_shift                                       (0)
#define  AVCOM_AVCOM_Netlist00_reg03_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist00_reg02_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist00_reg01_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist00_reg00_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist00_reg03(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist00_reg02(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist00_reg01(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist00_reg00(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist00_get_reg03(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist00_get_reg02(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist00_get_reg01(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist00_get_reg00(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist01                                                   0x1802ED04
#define  AVCOM_AVCOM_Netlist01_reg_addr                                          "0xB802ED04"
#define  AVCOM_AVCOM_Netlist01_reg                                               0xB802ED04
#define  AVCOM_AVCOM_Netlist01_inst_addr                                         "0x0001"
#define  set_AVCOM_AVCOM_Netlist01_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist01_reg)=data)
#define  get_AVCOM_AVCOM_Netlist01_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist01_reg))
#define  AVCOM_AVCOM_Netlist01_reg07_shift                                       (24)
#define  AVCOM_AVCOM_Netlist01_reg06_shift                                       (16)
#define  AVCOM_AVCOM_Netlist01_reg05_shift                                       (8)
#define  AVCOM_AVCOM_Netlist01_reg04_shift                                       (0)
#define  AVCOM_AVCOM_Netlist01_reg07_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist01_reg06_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist01_reg05_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist01_reg04_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist01_reg07(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist01_reg06(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist01_reg05(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist01_reg04(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist01_get_reg07(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist01_get_reg06(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist01_get_reg05(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist01_get_reg04(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist02                                                   0x1802ED08
#define  AVCOM_AVCOM_Netlist02_reg_addr                                          "0xB802ED08"
#define  AVCOM_AVCOM_Netlist02_reg                                               0xB802ED08
#define  AVCOM_AVCOM_Netlist02_inst_addr                                         "0x0002"
#define  set_AVCOM_AVCOM_Netlist02_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist02_reg)=data)
#define  get_AVCOM_AVCOM_Netlist02_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist02_reg))
#define  AVCOM_AVCOM_Netlist02_reg0b_shift                                       (24)
#define  AVCOM_AVCOM_Netlist02_reg0a_shift                                       (16)
#define  AVCOM_AVCOM_Netlist02_reg09_shift                                       (8)
#define  AVCOM_AVCOM_Netlist02_reg08_shift                                       (0)
#define  AVCOM_AVCOM_Netlist02_reg0b_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist02_reg0a_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist02_reg09_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist02_reg08_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist02_reg0b(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist02_reg0a(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist02_reg09(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist02_reg08(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist02_get_reg0b(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist02_get_reg0a(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist02_get_reg09(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist02_get_reg08(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist03                                                   0x1802ED0C
#define  AVCOM_AVCOM_Netlist03_reg_addr                                          "0xB802ED0C"
#define  AVCOM_AVCOM_Netlist03_reg                                               0xB802ED0C
#define  AVCOM_AVCOM_Netlist03_inst_addr                                         "0x0003"
#define  set_AVCOM_AVCOM_Netlist03_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist03_reg)=data)
#define  get_AVCOM_AVCOM_Netlist03_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist03_reg))
#define  AVCOM_AVCOM_Netlist03_reg0f_shift                                       (24)
#define  AVCOM_AVCOM_Netlist03_reg0e_shift                                       (16)
#define  AVCOM_AVCOM_Netlist03_reg0d_shift                                       (8)
#define  AVCOM_AVCOM_Netlist03_reg0c_shift                                       (0)
#define  AVCOM_AVCOM_Netlist03_reg0f_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist03_reg0e_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist03_reg0d_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist03_reg0c_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist03_reg0f(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist03_reg0e(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist03_reg0d(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist03_reg0c(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist03_get_reg0f(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist03_get_reg0e(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist03_get_reg0d(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist03_get_reg0c(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist04                                                   0x1802ED10
#define  AVCOM_AVCOM_Netlist04_reg_addr                                          "0xB802ED10"
#define  AVCOM_AVCOM_Netlist04_reg                                               0xB802ED10
#define  AVCOM_AVCOM_Netlist04_inst_addr                                         "0x0004"
#define  set_AVCOM_AVCOM_Netlist04_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist04_reg)=data)
#define  get_AVCOM_AVCOM_Netlist04_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist04_reg))
#define  AVCOM_AVCOM_Netlist04_reg13_shift                                       (24)
#define  AVCOM_AVCOM_Netlist04_reg12_shift                                       (16)
#define  AVCOM_AVCOM_Netlist04_reg11_shift                                       (8)
#define  AVCOM_AVCOM_Netlist04_reg10_shift                                       (0)
#define  AVCOM_AVCOM_Netlist04_reg13_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist04_reg12_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist04_reg11_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist04_reg10_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist04_reg13(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist04_reg12(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist04_reg11(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist04_reg10(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist04_get_reg13(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist04_get_reg12(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist04_get_reg11(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist04_get_reg10(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist05                                                   0x1802ED14
#define  AVCOM_AVCOM_Netlist05_reg_addr                                          "0xB802ED14"
#define  AVCOM_AVCOM_Netlist05_reg                                               0xB802ED14
#define  AVCOM_AVCOM_Netlist05_inst_addr                                         "0x0005"
#define  set_AVCOM_AVCOM_Netlist05_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist05_reg)=data)
#define  get_AVCOM_AVCOM_Netlist05_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist05_reg))
#define  AVCOM_AVCOM_Netlist05_reg17_shift                                       (24)
#define  AVCOM_AVCOM_Netlist05_reg16_shift                                       (16)
#define  AVCOM_AVCOM_Netlist05_reg15_shift                                       (8)
#define  AVCOM_AVCOM_Netlist05_reg14_shift                                       (0)
#define  AVCOM_AVCOM_Netlist05_reg17_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist05_reg16_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist05_reg15_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist05_reg14_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist05_reg17(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist05_reg16(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist05_reg15(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist05_reg14(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist05_get_reg17(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist05_get_reg16(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist05_get_reg15(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist05_get_reg14(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist06                                                   0x1802ED18
#define  AVCOM_AVCOM_Netlist06_reg_addr                                          "0xB802ED18"
#define  AVCOM_AVCOM_Netlist06_reg                                               0xB802ED18
#define  AVCOM_AVCOM_Netlist06_inst_addr                                         "0x0006"
#define  set_AVCOM_AVCOM_Netlist06_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist06_reg)=data)
#define  get_AVCOM_AVCOM_Netlist06_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist06_reg))
#define  AVCOM_AVCOM_Netlist06_reg1b_shift                                       (24)
#define  AVCOM_AVCOM_Netlist06_reg1a_shift                                       (16)
#define  AVCOM_AVCOM_Netlist06_reg19_shift                                       (8)
#define  AVCOM_AVCOM_Netlist06_reg18_shift                                       (0)
#define  AVCOM_AVCOM_Netlist06_reg1b_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist06_reg1a_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist06_reg19_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist06_reg18_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist06_reg1b(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist06_reg1a(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist06_reg19(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist06_reg18(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist06_get_reg1b(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist06_get_reg1a(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist06_get_reg19(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist06_get_reg18(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist07                                                   0x1802ED1C
#define  AVCOM_AVCOM_Netlist07_reg_addr                                          "0xB802ED1C"
#define  AVCOM_AVCOM_Netlist07_reg                                               0xB802ED1C
#define  AVCOM_AVCOM_Netlist07_inst_addr                                         "0x0007"
#define  set_AVCOM_AVCOM_Netlist07_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist07_reg)=data)
#define  get_AVCOM_AVCOM_Netlist07_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist07_reg))
#define  AVCOM_AVCOM_Netlist07_reg1f_shift                                       (24)
#define  AVCOM_AVCOM_Netlist07_reg1e_shift                                       (16)
#define  AVCOM_AVCOM_Netlist07_reg1d_shift                                       (8)
#define  AVCOM_AVCOM_Netlist07_reg1c_shift                                       (0)
#define  AVCOM_AVCOM_Netlist07_reg1f_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist07_reg1e_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist07_reg1d_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist07_reg1c_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist07_reg1f(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist07_reg1e(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist07_reg1d(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist07_reg1c(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist07_get_reg1f(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist07_get_reg1e(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist07_get_reg1d(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist07_get_reg1c(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist08                                                   0x1802ED20
#define  AVCOM_AVCOM_Netlist08_reg_addr                                          "0xB802ED20"
#define  AVCOM_AVCOM_Netlist08_reg                                               0xB802ED20
#define  AVCOM_AVCOM_Netlist08_inst_addr                                         "0x0008"
#define  set_AVCOM_AVCOM_Netlist08_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist08_reg)=data)
#define  get_AVCOM_AVCOM_Netlist08_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist08_reg))
#define  AVCOM_AVCOM_Netlist08_reg23_shift                                       (24)
#define  AVCOM_AVCOM_Netlist08_reg22_shift                                       (16)
#define  AVCOM_AVCOM_Netlist08_reg21_shift                                       (8)
#define  AVCOM_AVCOM_Netlist08_reg20_shift                                       (0)
#define  AVCOM_AVCOM_Netlist08_reg23_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist08_reg22_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist08_reg21_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist08_reg20_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist08_reg23(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist08_reg22(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist08_reg21(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist08_reg20(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist08_get_reg23(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist08_get_reg22(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist08_get_reg21(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist08_get_reg20(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist09                                                   0x1802ED24
#define  AVCOM_AVCOM_Netlist09_reg_addr                                          "0xB802ED24"
#define  AVCOM_AVCOM_Netlist09_reg                                               0xB802ED24
#define  AVCOM_AVCOM_Netlist09_inst_addr                                         "0x0009"
#define  set_AVCOM_AVCOM_Netlist09_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist09_reg)=data)
#define  get_AVCOM_AVCOM_Netlist09_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist09_reg))
#define  AVCOM_AVCOM_Netlist09_reg27_shift                                       (24)
#define  AVCOM_AVCOM_Netlist09_reg26_shift                                       (16)
#define  AVCOM_AVCOM_Netlist09_reg25_shift                                       (8)
#define  AVCOM_AVCOM_Netlist09_reg24_shift                                       (0)
#define  AVCOM_AVCOM_Netlist09_reg27_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist09_reg26_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist09_reg25_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist09_reg24_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist09_reg27(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist09_reg26(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist09_reg25(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist09_reg24(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist09_get_reg27(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist09_get_reg26(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist09_get_reg25(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist09_get_reg24(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist10                                                   0x1802ED28
#define  AVCOM_AVCOM_Netlist10_reg_addr                                          "0xB802ED28"
#define  AVCOM_AVCOM_Netlist10_reg                                               0xB802ED28
#define  AVCOM_AVCOM_Netlist10_inst_addr                                         "0x000A"
#define  set_AVCOM_AVCOM_Netlist10_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist10_reg)=data)
#define  get_AVCOM_AVCOM_Netlist10_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist10_reg))
#define  AVCOM_AVCOM_Netlist10_reg2b_shift                                       (24)
#define  AVCOM_AVCOM_Netlist10_reg2a_shift                                       (16)
#define  AVCOM_AVCOM_Netlist10_reg29_shift                                       (8)
#define  AVCOM_AVCOM_Netlist10_reg28_shift                                       (0)
#define  AVCOM_AVCOM_Netlist10_reg2b_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist10_reg2a_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist10_reg29_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist10_reg28_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist10_reg2b(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist10_reg2a(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist10_reg29(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist10_reg28(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist10_get_reg2b(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist10_get_reg2a(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist10_get_reg29(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist10_get_reg28(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist11                                                   0x1802ED2C
#define  AVCOM_AVCOM_Netlist11_reg_addr                                          "0xB802ED2C"
#define  AVCOM_AVCOM_Netlist11_reg                                               0xB802ED2C
#define  AVCOM_AVCOM_Netlist11_inst_addr                                         "0x000B"
#define  set_AVCOM_AVCOM_Netlist11_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist11_reg)=data)
#define  get_AVCOM_AVCOM_Netlist11_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist11_reg))
#define  AVCOM_AVCOM_Netlist11_reg2f_shift                                       (24)
#define  AVCOM_AVCOM_Netlist11_reg2e_shift                                       (16)
#define  AVCOM_AVCOM_Netlist11_reg2d_shift                                       (8)
#define  AVCOM_AVCOM_Netlist11_reg2c_shift                                       (0)
#define  AVCOM_AVCOM_Netlist11_reg2f_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist11_reg2e_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist11_reg2d_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist11_reg2c_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist11_reg2f(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist11_reg2e(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist11_reg2d(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist11_reg2c(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist11_get_reg2f(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist11_get_reg2e(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist11_get_reg2d(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist11_get_reg2c(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist12                                                   0x1802ED30
#define  AVCOM_AVCOM_Netlist12_reg_addr                                          "0xB802ED30"
#define  AVCOM_AVCOM_Netlist12_reg                                               0xB802ED30
#define  AVCOM_AVCOM_Netlist12_inst_addr                                         "0x000C"
#define  set_AVCOM_AVCOM_Netlist12_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist12_reg)=data)
#define  get_AVCOM_AVCOM_Netlist12_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist12_reg))
#define  AVCOM_AVCOM_Netlist12_reg33_shift                                       (24)
#define  AVCOM_AVCOM_Netlist12_reg32_shift                                       (16)
#define  AVCOM_AVCOM_Netlist12_reg31_shift                                       (8)
#define  AVCOM_AVCOM_Netlist12_reg30_shift                                       (0)
#define  AVCOM_AVCOM_Netlist12_reg33_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist12_reg32_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist12_reg31_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist12_reg30_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist12_reg33(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist12_reg32(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist12_reg31(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist12_reg30(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist12_get_reg33(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist12_get_reg32(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist12_get_reg31(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist12_get_reg30(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist13                                                   0x1802ED34
#define  AVCOM_AVCOM_Netlist13_reg_addr                                          "0xB802ED34"
#define  AVCOM_AVCOM_Netlist13_reg                                               0xB802ED34
#define  AVCOM_AVCOM_Netlist13_inst_addr                                         "0x000D"
#define  set_AVCOM_AVCOM_Netlist13_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist13_reg)=data)
#define  get_AVCOM_AVCOM_Netlist13_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist13_reg))
#define  AVCOM_AVCOM_Netlist13_reg37_shift                                       (24)
#define  AVCOM_AVCOM_Netlist13_reg36_shift                                       (16)
#define  AVCOM_AVCOM_Netlist13_reg35_shift                                       (8)
#define  AVCOM_AVCOM_Netlist13_reg34_shift                                       (0)
#define  AVCOM_AVCOM_Netlist13_reg37_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist13_reg36_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist13_reg35_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist13_reg34_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist13_reg37(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist13_reg36(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist13_reg35(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist13_reg34(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist13_get_reg37(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist13_get_reg36(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist13_get_reg35(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist13_get_reg34(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist14                                                   0x1802ED38
#define  AVCOM_AVCOM_Netlist14_reg_addr                                          "0xB802ED38"
#define  AVCOM_AVCOM_Netlist14_reg                                               0xB802ED38
#define  AVCOM_AVCOM_Netlist14_inst_addr                                         "0x000E"
#define  set_AVCOM_AVCOM_Netlist14_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist14_reg)=data)
#define  get_AVCOM_AVCOM_Netlist14_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist14_reg))
#define  AVCOM_AVCOM_Netlist14_reg3b_shift                                       (24)
#define  AVCOM_AVCOM_Netlist14_reg3a_shift                                       (16)
#define  AVCOM_AVCOM_Netlist14_reg39_shift                                       (8)
#define  AVCOM_AVCOM_Netlist14_reg38_shift                                       (0)
#define  AVCOM_AVCOM_Netlist14_reg3b_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist14_reg3a_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist14_reg39_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist14_reg38_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist14_reg3b(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist14_reg3a(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist14_reg39(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist14_reg38(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist14_get_reg3b(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist14_get_reg3a(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist14_get_reg39(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist14_get_reg38(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist15                                                   0x1802ED3C
#define  AVCOM_AVCOM_Netlist15_reg_addr                                          "0xB802ED3C"
#define  AVCOM_AVCOM_Netlist15_reg                                               0xB802ED3C
#define  AVCOM_AVCOM_Netlist15_inst_addr                                         "0x000F"
#define  set_AVCOM_AVCOM_Netlist15_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist15_reg)=data)
#define  get_AVCOM_AVCOM_Netlist15_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist15_reg))
#define  AVCOM_AVCOM_Netlist15_reg3f_shift                                       (24)
#define  AVCOM_AVCOM_Netlist15_reg3e_shift                                       (16)
#define  AVCOM_AVCOM_Netlist15_reg3d_shift                                       (8)
#define  AVCOM_AVCOM_Netlist15_reg3c_shift                                       (0)
#define  AVCOM_AVCOM_Netlist15_reg3f_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist15_reg3e_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist15_reg3d_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist15_reg3c_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist15_reg3f(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist15_reg3e(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist15_reg3d(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist15_reg3c(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist15_get_reg3f(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist15_get_reg3e(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist15_get_reg3d(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist15_get_reg3c(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist16                                                   0x1802ED40
#define  AVCOM_AVCOM_Netlist16_reg_addr                                          "0xB802ED40"
#define  AVCOM_AVCOM_Netlist16_reg                                               0xB802ED40
#define  AVCOM_AVCOM_Netlist16_inst_addr                                         "0x0010"
#define  set_AVCOM_AVCOM_Netlist16_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist16_reg)=data)
#define  get_AVCOM_AVCOM_Netlist16_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist16_reg))
#define  AVCOM_AVCOM_Netlist16_reg43_shift                                       (24)
#define  AVCOM_AVCOM_Netlist16_reg42_shift                                       (16)
#define  AVCOM_AVCOM_Netlist16_reg41_shift                                       (8)
#define  AVCOM_AVCOM_Netlist16_reg40_shift                                       (0)
#define  AVCOM_AVCOM_Netlist16_reg43_mask                                        (0xFF000000)
#define  AVCOM_AVCOM_Netlist16_reg42_mask                                        (0x00FF0000)
#define  AVCOM_AVCOM_Netlist16_reg41_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist16_reg40_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist16_reg43(data)                                       (0xFF000000&((data)<<24))
#define  AVCOM_AVCOM_Netlist16_reg42(data)                                       (0x00FF0000&((data)<<16))
#define  AVCOM_AVCOM_Netlist16_reg41(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist16_reg40(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist16_get_reg43(data)                                   ((0xFF000000&(data))>>24)
#define  AVCOM_AVCOM_Netlist16_get_reg42(data)                                   ((0x00FF0000&(data))>>16)
#define  AVCOM_AVCOM_Netlist16_get_reg41(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist16_get_reg40(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Netlist17                                                   0x1802ED44
#define  AVCOM_AVCOM_Netlist17_reg_addr                                          "0xB802ED44"
#define  AVCOM_AVCOM_Netlist17_reg                                               0xB802ED44
#define  AVCOM_AVCOM_Netlist17_inst_addr                                         "0x0011"
#define  set_AVCOM_AVCOM_Netlist17_reg(data)                                     (*((volatile unsigned int*)AVCOM_AVCOM_Netlist17_reg)=data)
#define  get_AVCOM_AVCOM_Netlist17_reg                                           (*((volatile unsigned int*)AVCOM_AVCOM_Netlist17_reg))
#define  AVCOM_AVCOM_Netlist17_reg45_shift                                       (8)
#define  AVCOM_AVCOM_Netlist17_reg44_shift                                       (0)
#define  AVCOM_AVCOM_Netlist17_reg45_mask                                        (0x0000FF00)
#define  AVCOM_AVCOM_Netlist17_reg44_mask                                        (0x000000FF)
#define  AVCOM_AVCOM_Netlist17_reg45(data)                                       (0x0000FF00&((data)<<8))
#define  AVCOM_AVCOM_Netlist17_reg44(data)                                       (0x000000FF&(data))
#define  AVCOM_AVCOM_Netlist17_get_reg45(data)                                   ((0x0000FF00&(data))>>8)
#define  AVCOM_AVCOM_Netlist17_get_reg44(data)                                   (0x000000FF&(data))

#define  AVCOM_AVCOM_Dummy0                                                      0x1802ED48
#define  AVCOM_AVCOM_Dummy0_reg_addr                                             "0xB802ED48"
#define  AVCOM_AVCOM_Dummy0_reg                                                  0xB802ED48
#define  AVCOM_AVCOM_Dummy0_inst_addr                                            "0x0012"
#define  set_AVCOM_AVCOM_Dummy0_reg(data)                                        (*((volatile unsigned int*)AVCOM_AVCOM_Dummy0_reg)=data)
#define  get_AVCOM_AVCOM_Dummy0_reg                                              (*((volatile unsigned int*)AVCOM_AVCOM_Dummy0_reg))
#define  AVCOM_AVCOM_Dummy0_dummy_7_0_shift                                      (0)
#define  AVCOM_AVCOM_Dummy0_dummy_7_0_mask                                       (0x000000FF)
#define  AVCOM_AVCOM_Dummy0_dummy_7_0(data)                                      (0x000000FF&(data))
#define  AVCOM_AVCOM_Dummy0_get_dummy_7_0(data)                                  (0x000000FF&(data))

#define  AVCOM_AVCOM_Dummy1                                                      0x1802ED4C
#define  AVCOM_AVCOM_Dummy1_reg_addr                                             "0xB802ED4C"
#define  AVCOM_AVCOM_Dummy1_reg                                                  0xB802ED4C
#define  AVCOM_AVCOM_Dummy1_inst_addr                                            "0x0013"
#define  set_AVCOM_AVCOM_Dummy1_reg(data)                                        (*((volatile unsigned int*)AVCOM_AVCOM_Dummy1_reg)=data)
#define  get_AVCOM_AVCOM_Dummy1_reg                                              (*((volatile unsigned int*)AVCOM_AVCOM_Dummy1_reg))
#define  AVCOM_AVCOM_Dummy1_dummy_7_0_shift                                      (0)
#define  AVCOM_AVCOM_Dummy1_dummy_7_0_mask                                       (0x000000FF)
#define  AVCOM_AVCOM_Dummy1_dummy_7_0(data)                                      (0x000000FF&(data))
#define  AVCOM_AVCOM_Dummy1_get_dummy_7_0(data)                                  (0x000000FF&(data))

#define  AVCOM_AVCOM_Wrap0                                                       0x1802ED50
#define  AVCOM_AVCOM_Wrap0_reg_addr                                              "0xB802ED50"
#define  AVCOM_AVCOM_Wrap0_reg                                                   0xB802ED50
#define  AVCOM_AVCOM_Wrap0_inst_addr                                             "0x0014"
#define  set_AVCOM_AVCOM_Wrap0_reg(data)                                         (*((volatile unsigned int*)AVCOM_AVCOM_Wrap0_reg)=data)
#define  get_AVCOM_AVCOM_Wrap0_reg                                               (*((volatile unsigned int*)AVCOM_AVCOM_Wrap0_reg))
#define  AVCOM_AVCOM_Wrap0_avcom_wrap_en_shift                                   (28)
#define  AVCOM_AVCOM_Wrap0_avcom_dbg_en_shift                                    (20)
#define  AVCOM_AVCOM_Wrap0_de_epi_delay_v_shift                                  (16)
#define  AVCOM_AVCOM_Wrap0_de_epi_delay_h_shift                                  (0)
#define  AVCOM_AVCOM_Wrap0_avcom_wrap_en_mask                                    (0x10000000)
#define  AVCOM_AVCOM_Wrap0_avcom_dbg_en_mask                                     (0x00100000)
#define  AVCOM_AVCOM_Wrap0_de_epi_delay_v_mask                                   (0x000F0000)
#define  AVCOM_AVCOM_Wrap0_de_epi_delay_h_mask                                   (0x00001FFF)
#define  AVCOM_AVCOM_Wrap0_avcom_wrap_en(data)                                   (0x10000000&((data)<<28))
#define  AVCOM_AVCOM_Wrap0_avcom_dbg_en(data)                                    (0x00100000&((data)<<20))
#define  AVCOM_AVCOM_Wrap0_de_epi_delay_v(data)                                  (0x000F0000&((data)<<16))
#define  AVCOM_AVCOM_Wrap0_de_epi_delay_h(data)                                  (0x00001FFF&(data))
#define  AVCOM_AVCOM_Wrap0_get_avcom_wrap_en(data)                               ((0x10000000&(data))>>28)
#define  AVCOM_AVCOM_Wrap0_get_avcom_dbg_en(data)                                ((0x00100000&(data))>>20)
#define  AVCOM_AVCOM_Wrap0_get_de_epi_delay_v(data)                              ((0x000F0000&(data))>>16)
#define  AVCOM_AVCOM_Wrap0_get_de_epi_delay_h(data)                              (0x00001FFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======AVCOM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg03:8;
        RBus_UInt32  reg02:8;
        RBus_UInt32  reg01:8;
        RBus_UInt32  reg00:8;
    };
}avcom_avcom_netlist00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg07:8;
        RBus_UInt32  reg06:8;
        RBus_UInt32  reg05:8;
        RBus_UInt32  reg04:8;
    };
}avcom_avcom_netlist01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg0b:8;
        RBus_UInt32  reg0a:8;
        RBus_UInt32  reg09:8;
        RBus_UInt32  reg08:8;
    };
}avcom_avcom_netlist02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg0f:8;
        RBus_UInt32  reg0e:8;
        RBus_UInt32  reg0d:8;
        RBus_UInt32  reg0c:8;
    };
}avcom_avcom_netlist03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg13:8;
        RBus_UInt32  reg12:8;
        RBus_UInt32  reg11:8;
        RBus_UInt32  reg10:8;
    };
}avcom_avcom_netlist04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg17:8;
        RBus_UInt32  reg16:8;
        RBus_UInt32  reg15:8;
        RBus_UInt32  reg14:8;
    };
}avcom_avcom_netlist05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg1b:8;
        RBus_UInt32  reg1a:8;
        RBus_UInt32  reg19:8;
        RBus_UInt32  reg18:8;
    };
}avcom_avcom_netlist06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg1f:8;
        RBus_UInt32  reg1e:8;
        RBus_UInt32  reg1d:8;
        RBus_UInt32  reg1c:8;
    };
}avcom_avcom_netlist07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg23:8;
        RBus_UInt32  reg22:8;
        RBus_UInt32  reg21:8;
        RBus_UInt32  reg20:8;
    };
}avcom_avcom_netlist08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg27:8;
        RBus_UInt32  reg26:8;
        RBus_UInt32  reg25:8;
        RBus_UInt32  reg24:8;
    };
}avcom_avcom_netlist09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg2b:8;
        RBus_UInt32  reg2a:8;
        RBus_UInt32  reg29:8;
        RBus_UInt32  reg28:8;
    };
}avcom_avcom_netlist10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg2f:8;
        RBus_UInt32  reg2e:8;
        RBus_UInt32  reg2d:8;
        RBus_UInt32  reg2c:8;
    };
}avcom_avcom_netlist11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg33:8;
        RBus_UInt32  reg32:8;
        RBus_UInt32  reg31:8;
        RBus_UInt32  reg30:8;
    };
}avcom_avcom_netlist12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg37:8;
        RBus_UInt32  reg36:8;
        RBus_UInt32  reg35:8;
        RBus_UInt32  reg34:8;
    };
}avcom_avcom_netlist13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg3b:8;
        RBus_UInt32  reg3a:8;
        RBus_UInt32  reg39:8;
        RBus_UInt32  reg38:8;
    };
}avcom_avcom_netlist14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg3f:8;
        RBus_UInt32  reg3e:8;
        RBus_UInt32  reg3d:8;
        RBus_UInt32  reg3c:8;
    };
}avcom_avcom_netlist15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg43:8;
        RBus_UInt32  reg42:8;
        RBus_UInt32  reg41:8;
        RBus_UInt32  reg40:8;
    };
}avcom_avcom_netlist16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg45:8;
        RBus_UInt32  reg44:8;
    };
}avcom_avcom_netlist17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1802ed48_7_0:8;
    };
}avcom_avcom_dummy0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1802ed4c_7_0:8;
    };
}avcom_avcom_dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  avcom_wrap_en:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  avcom_dbg_en:1;
        RBus_UInt32  de_epi_delay_v:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  de_epi_delay_h:13;
    };
}avcom_avcom_wrap0_RBUS;

#else //apply LITTLE_ENDIAN

//======AVCOM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg00:8;
        RBus_UInt32  reg01:8;
        RBus_UInt32  reg02:8;
        RBus_UInt32  reg03:8;
    };
}avcom_avcom_netlist00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg04:8;
        RBus_UInt32  reg05:8;
        RBus_UInt32  reg06:8;
        RBus_UInt32  reg07:8;
    };
}avcom_avcom_netlist01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg08:8;
        RBus_UInt32  reg09:8;
        RBus_UInt32  reg0a:8;
        RBus_UInt32  reg0b:8;
    };
}avcom_avcom_netlist02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg0c:8;
        RBus_UInt32  reg0d:8;
        RBus_UInt32  reg0e:8;
        RBus_UInt32  reg0f:8;
    };
}avcom_avcom_netlist03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg10:8;
        RBus_UInt32  reg11:8;
        RBus_UInt32  reg12:8;
        RBus_UInt32  reg13:8;
    };
}avcom_avcom_netlist04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg14:8;
        RBus_UInt32  reg15:8;
        RBus_UInt32  reg16:8;
        RBus_UInt32  reg17:8;
    };
}avcom_avcom_netlist05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg18:8;
        RBus_UInt32  reg19:8;
        RBus_UInt32  reg1a:8;
        RBus_UInt32  reg1b:8;
    };
}avcom_avcom_netlist06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg1c:8;
        RBus_UInt32  reg1d:8;
        RBus_UInt32  reg1e:8;
        RBus_UInt32  reg1f:8;
    };
}avcom_avcom_netlist07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg20:8;
        RBus_UInt32  reg21:8;
        RBus_UInt32  reg22:8;
        RBus_UInt32  reg23:8;
    };
}avcom_avcom_netlist08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg24:8;
        RBus_UInt32  reg25:8;
        RBus_UInt32  reg26:8;
        RBus_UInt32  reg27:8;
    };
}avcom_avcom_netlist09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg28:8;
        RBus_UInt32  reg29:8;
        RBus_UInt32  reg2a:8;
        RBus_UInt32  reg2b:8;
    };
}avcom_avcom_netlist10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg2c:8;
        RBus_UInt32  reg2d:8;
        RBus_UInt32  reg2e:8;
        RBus_UInt32  reg2f:8;
    };
}avcom_avcom_netlist11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg30:8;
        RBus_UInt32  reg31:8;
        RBus_UInt32  reg32:8;
        RBus_UInt32  reg33:8;
    };
}avcom_avcom_netlist12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg34:8;
        RBus_UInt32  reg35:8;
        RBus_UInt32  reg36:8;
        RBus_UInt32  reg37:8;
    };
}avcom_avcom_netlist13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg38:8;
        RBus_UInt32  reg39:8;
        RBus_UInt32  reg3a:8;
        RBus_UInt32  reg3b:8;
    };
}avcom_avcom_netlist14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg3c:8;
        RBus_UInt32  reg3d:8;
        RBus_UInt32  reg3e:8;
        RBus_UInt32  reg3f:8;
    };
}avcom_avcom_netlist15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg40:8;
        RBus_UInt32  reg41:8;
        RBus_UInt32  reg42:8;
        RBus_UInt32  reg43:8;
    };
}avcom_avcom_netlist16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg44:8;
        RBus_UInt32  reg45:8;
        RBus_UInt32  res1:16;
    };
}avcom_avcom_netlist17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802ed48_7_0:8;
        RBus_UInt32  res1:24;
    };
}avcom_avcom_dummy0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802ed4c_7_0:8;
        RBus_UInt32  res1:24;
    };
}avcom_avcom_dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  de_epi_delay_h:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  de_epi_delay_v:4;
        RBus_UInt32  avcom_dbg_en:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  avcom_wrap_en:1;
        RBus_UInt32  res3:3;
    };
}avcom_avcom_wrap0_RBUS;




#endif 


#endif 
