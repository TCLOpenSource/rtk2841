/**
* @file Mac5_LGCY_VE_MVDBLK_Arch_Spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LGCY_MVDBLK_REG_H_
#define _RBUS_LGCY_MVDBLK_REG_H_

#include "rbus_types.h"



//  LGCY_MVDBLK Register Address
#define  LGCY_MVDBLK_comm                                                        0x1800E660
#define  LGCY_MVDBLK_comm_reg_addr                                               "0xB800E660"
#define  LGCY_MVDBLK_comm_reg                                                    0xB800E660
#define  LGCY_MVDBLK_comm_inst_addr                                              "0x0000"
#define  set_LGCY_MVDBLK_comm_reg(data)                                          (*((volatile unsigned int*)LGCY_MVDBLK_comm_reg)=data)
#define  get_LGCY_MVDBLK_comm_reg                                                (*((volatile unsigned int*)LGCY_MVDBLK_comm_reg))
#define  LGCY_MVDBLK_comm_pictype_shift                                          (2)
#define  LGCY_MVDBLK_comm_firstmbofpic_shift                                     (1)
#define  LGCY_MVDBLK_comm_firstmbofslice_shift                                   (0)
#define  LGCY_MVDBLK_comm_pictype_mask                                           (0x0000001C)
#define  LGCY_MVDBLK_comm_firstmbofpic_mask                                      (0x00000002)
#define  LGCY_MVDBLK_comm_firstmbofslice_mask                                    (0x00000001)
#define  LGCY_MVDBLK_comm_pictype(data)                                          (0x0000001C&((data)<<2))
#define  LGCY_MVDBLK_comm_firstmbofpic(data)                                     (0x00000002&((data)<<1))
#define  LGCY_MVDBLK_comm_firstmbofslice(data)                                   (0x00000001&(data))
#define  LGCY_MVDBLK_comm_get_pictype(data)                                      ((0x0000001C&(data))>>2)
#define  LGCY_MVDBLK_comm_get_firstmbofpic(data)                                 ((0x00000002&(data))>>1)
#define  LGCY_MVDBLK_comm_get_firstmbofslice(data)                               (0x00000001&(data))

#define  LGCY_MVDBLK_comm1                                                       0x1800E664
#define  LGCY_MVDBLK_comm1_reg_addr                                              "0xB800E664"
#define  LGCY_MVDBLK_comm1_reg                                                   0xB800E664
#define  LGCY_MVDBLK_comm1_inst_addr                                             "0x0001"
#define  set_LGCY_MVDBLK_comm1_reg(data)                                         (*((volatile unsigned int*)LGCY_MVDBLK_comm1_reg)=data)
#define  get_LGCY_MVDBLK_comm1_reg                                               (*((volatile unsigned int*)LGCY_MVDBLK_comm1_reg))
#define  LGCY_MVDBLK_comm1_ldpxmemcount_shift                                    (0)
#define  LGCY_MVDBLK_comm1_ldpxmemcount_mask                                     (0x0000FFFF)
#define  LGCY_MVDBLK_comm1_ldpxmemcount(data)                                    (0x0000FFFF&(data))
#define  LGCY_MVDBLK_comm1_get_ldpxmemcount(data)                                (0x0000FFFF&(data))

#define  LGCY_MVDBLK_comm2                                                       0x1800E668
#define  LGCY_MVDBLK_comm2_reg_addr                                              "0xB800E668"
#define  LGCY_MVDBLK_comm2_reg                                                   0xB800E668
#define  LGCY_MVDBLK_comm2_inst_addr                                             "0x0002"
#define  set_LGCY_MVDBLK_comm2_reg(data)                                         (*((volatile unsigned int*)LGCY_MVDBLK_comm2_reg)=data)
#define  get_LGCY_MVDBLK_comm2_reg                                               (*((volatile unsigned int*)LGCY_MVDBLK_comm2_reg))
#define  LGCY_MVDBLK_comm2_dbgdumpcount_shift                                    (0)
#define  LGCY_MVDBLK_comm2_dbgdumpcount_mask                                     (0x0000FFFF)
#define  LGCY_MVDBLK_comm2_dbgdumpcount(data)                                    (0x0000FFFF&(data))
#define  LGCY_MVDBLK_comm2_get_dbgdumpcount(data)                                (0x0000FFFF&(data))

#define  LGCY_MVDBLK_comm3                                                       0x1800E66C
#define  LGCY_MVDBLK_comm3_reg_addr                                              "0xB800E66C"
#define  LGCY_MVDBLK_comm3_reg                                                   0xB800E66C
#define  LGCY_MVDBLK_comm3_inst_addr                                             "0x0003"
#define  set_LGCY_MVDBLK_comm3_reg(data)                                         (*((volatile unsigned int*)LGCY_MVDBLK_comm3_reg)=data)
#define  get_LGCY_MVDBLK_comm3_reg                                               (*((volatile unsigned int*)LGCY_MVDBLK_comm3_reg))
#define  LGCY_MVDBLK_comm3_setaddr_shift                                         (27)
#define  LGCY_MVDBLK_comm3_mbaddry_shift                                         (20)
#define  LGCY_MVDBLK_comm3_mbaddrx_shift                                         (13)
#define  LGCY_MVDBLK_comm3_mbaddr_shift                                          (0)
#define  LGCY_MVDBLK_comm3_setaddr_mask                                          (0x08000000)
#define  LGCY_MVDBLK_comm3_mbaddry_mask                                          (0x07F00000)
#define  LGCY_MVDBLK_comm3_mbaddrx_mask                                          (0x000FE000)
#define  LGCY_MVDBLK_comm3_mbaddr_mask                                           (0x00001FFF)
#define  LGCY_MVDBLK_comm3_setaddr(data)                                         (0x08000000&((data)<<27))
#define  LGCY_MVDBLK_comm3_mbaddry(data)                                         (0x07F00000&((data)<<20))
#define  LGCY_MVDBLK_comm3_mbaddrx(data)                                         (0x000FE000&((data)<<13))
#define  LGCY_MVDBLK_comm3_mbaddr(data)                                          (0x00001FFF&(data))
#define  LGCY_MVDBLK_comm3_get_setaddr(data)                                     ((0x08000000&(data))>>27)
#define  LGCY_MVDBLK_comm3_get_mbaddry(data)                                     ((0x07F00000&(data))>>20)
#define  LGCY_MVDBLK_comm3_get_mbaddrx(data)                                     ((0x000FE000&(data))>>13)
#define  LGCY_MVDBLK_comm3_get_mbaddr(data)                                      (0x00001FFF&(data))

#define  LGCY_MVDBLK_comm4                                                       0x1800E670
#define  LGCY_MVDBLK_comm4_reg_addr                                              "0xB800E670"
#define  LGCY_MVDBLK_comm4_reg                                                   0xB800E670
#define  LGCY_MVDBLK_comm4_inst_addr                                             "0x0004"
#define  set_LGCY_MVDBLK_comm4_reg(data)                                         (*((volatile unsigned int*)LGCY_MVDBLK_comm4_reg)=data)
#define  get_LGCY_MVDBLK_comm4_reg                                               (*((volatile unsigned int*)LGCY_MVDBLK_comm4_reg))
#define  LGCY_MVDBLK_comm4_hwctrl_shift                                          (1)
#define  LGCY_MVDBLK_comm4_softreset_shift                                       (0)
#define  LGCY_MVDBLK_comm4_hwctrl_mask                                           (0x000000FE)
#define  LGCY_MVDBLK_comm4_softreset_mask                                        (0x00000001)
#define  LGCY_MVDBLK_comm4_hwctrl(data)                                          (0x000000FE&((data)<<1))
#define  LGCY_MVDBLK_comm4_softreset(data)                                       (0x00000001&(data))
#define  LGCY_MVDBLK_comm4_get_hwctrl(data)                                      ((0x000000FE&(data))>>1)
#define  LGCY_MVDBLK_comm4_get_softreset(data)                                   (0x00000001&(data))

#define  LGCY_MVDBLK_comm5_0                                                     0x1800E674
#define  LGCY_MVDBLK_comm5_0_reg_addr                                            "0xB800E674"
#define  LGCY_MVDBLK_comm5_0_reg                                                 0xB800E674
#define  LGCY_MVDBLK_comm5_0_inst_addr                                           "0x0005"
#define  set_LGCY_MVDBLK_comm5_0_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_comm5_0_reg)=data)
#define  get_LGCY_MVDBLK_comm5_0_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_comm5_0_reg))
#define  LGCY_MVDBLK_comm5_0_dbgwritebuf_shift                                   (0)
#define  LGCY_MVDBLK_comm5_0_dbgwritebuf_mask                                    (0xFFFFFFFF)
#define  LGCY_MVDBLK_comm5_0_dbgwritebuf(data)                                   (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_comm5_0_get_dbgwritebuf(data)                               (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_comm5_1                                                     0x1800E678
#define  LGCY_MVDBLK_comm5_1_reg_addr                                            "0xB800E678"
#define  LGCY_MVDBLK_comm5_1_reg                                                 0xB800E678
#define  LGCY_MVDBLK_comm5_1_inst_addr                                           "0x0006"
#define  set_LGCY_MVDBLK_comm5_1_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_comm5_1_reg)=data)
#define  get_LGCY_MVDBLK_comm5_1_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_comm5_1_reg))
#define  LGCY_MVDBLK_comm5_1_dbgwritebuf_shift                                   (0)
#define  LGCY_MVDBLK_comm5_1_dbgwritebuf_mask                                    (0xFFFFFFFF)
#define  LGCY_MVDBLK_comm5_1_dbgwritebuf(data)                                   (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_comm5_1_get_dbgwritebuf(data)                               (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_comm5_2                                                     0x1800E67C
#define  LGCY_MVDBLK_comm5_2_reg_addr                                            "0xB800E67C"
#define  LGCY_MVDBLK_comm5_2_reg                                                 0xB800E67C
#define  LGCY_MVDBLK_comm5_2_inst_addr                                           "0x0007"
#define  set_LGCY_MVDBLK_comm5_2_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_comm5_2_reg)=data)
#define  get_LGCY_MVDBLK_comm5_2_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_comm5_2_reg))
#define  LGCY_MVDBLK_comm5_2_dbgwritebuf_shift                                   (0)
#define  LGCY_MVDBLK_comm5_2_dbgwritebuf_mask                                    (0xFFFFFFFF)
#define  LGCY_MVDBLK_comm5_2_dbgwritebuf(data)                                   (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_comm5_2_get_dbgwritebuf(data)                               (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_comm6                                                       0x1800E690
#define  LGCY_MVDBLK_comm6_reg_addr                                              "0xB800E690"
#define  LGCY_MVDBLK_comm6_reg                                                   0xB800E690
#define  LGCY_MVDBLK_comm6_inst_addr                                             "0x0008"
#define  set_LGCY_MVDBLK_comm6_reg(data)                                         (*((volatile unsigned int*)LGCY_MVDBLK_comm6_reg)=data)
#define  get_LGCY_MVDBLK_comm6_reg                                               (*((volatile unsigned int*)LGCY_MVDBLK_comm6_reg))
#define  LGCY_MVDBLK_comm6_dbgstorecount_shift                                   (0)
#define  LGCY_MVDBLK_comm6_dbgstorecount_mask                                    (0x0000FFFF)
#define  LGCY_MVDBLK_comm6_dbgstorecount(data)                                   (0x0000FFFF&(data))
#define  LGCY_MVDBLK_comm6_get_dbgstorecount(data)                               (0x0000FFFF&(data))

#define  LGCY_MVDBLK_h264pic                                                     0x1800E600
#define  LGCY_MVDBLK_h264pic_reg_addr                                            "0xB800E600"
#define  LGCY_MVDBLK_h264pic_reg                                                 0xB800E600
#define  LGCY_MVDBLK_h264pic_inst_addr                                           "0x0009"
#define  set_LGCY_MVDBLK_h264pic_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_h264pic_reg)=data)
#define  get_LGCY_MVDBLK_h264pic_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_h264pic_reg))
#define  LGCY_MVDBLK_h264pic_refpiclist10short_shift                             (7)
#define  LGCY_MVDBLK_h264pic_botletopabsdiffpoc_shift                            (6)
#define  LGCY_MVDBLK_h264pic_directspatial_shift                                 (5)
#define  LGCY_MVDBLK_h264pic_colpicstruct_shift                                  (3)
#define  LGCY_MVDBLK_h264pic_currpicstruct_shift                                 (1)
#define  LGCY_MVDBLK_h264pic_direct8x8inf_shift                                  (0)
#define  LGCY_MVDBLK_h264pic_refpiclist10short_mask                              (0x00000080)
#define  LGCY_MVDBLK_h264pic_botletopabsdiffpoc_mask                             (0x00000040)
#define  LGCY_MVDBLK_h264pic_directspatial_mask                                  (0x00000020)
#define  LGCY_MVDBLK_h264pic_colpicstruct_mask                                   (0x00000018)
#define  LGCY_MVDBLK_h264pic_currpicstruct_mask                                  (0x00000006)
#define  LGCY_MVDBLK_h264pic_direct8x8inf_mask                                   (0x00000001)
#define  LGCY_MVDBLK_h264pic_refpiclist10short(data)                             (0x00000080&((data)<<7))
#define  LGCY_MVDBLK_h264pic_botletopabsdiffpoc(data)                            (0x00000040&((data)<<6))
#define  LGCY_MVDBLK_h264pic_directspatial(data)                                 (0x00000020&((data)<<5))
#define  LGCY_MVDBLK_h264pic_colpicstruct(data)                                  (0x00000018&((data)<<3))
#define  LGCY_MVDBLK_h264pic_currpicstruct(data)                                 (0x00000006&((data)<<1))
#define  LGCY_MVDBLK_h264pic_direct8x8inf(data)                                  (0x00000001&(data))
#define  LGCY_MVDBLK_h264pic_get_refpiclist10short(data)                         ((0x00000080&(data))>>7)
#define  LGCY_MVDBLK_h264pic_get_botletopabsdiffpoc(data)                        ((0x00000040&(data))>>6)
#define  LGCY_MVDBLK_h264pic_get_directspatial(data)                             ((0x00000020&(data))>>5)
#define  LGCY_MVDBLK_h264pic_get_colpicstruct(data)                              ((0x00000018&(data))>>3)
#define  LGCY_MVDBLK_h264pic_get_currpicstruct(data)                             ((0x00000006&(data))>>1)
#define  LGCY_MVDBLK_h264pic_get_direct8x8inf(data)                              (0x00000001&(data))

#define  LGCY_MVDBLK_h264pic1                                                    0x1800E604
#define  LGCY_MVDBLK_h264pic1_reg_addr                                           "0xB800E604"
#define  LGCY_MVDBLK_h264pic1_reg                                                0xB800E604
#define  LGCY_MVDBLK_h264pic1_inst_addr                                          "0x000A"
#define  set_LGCY_MVDBLK_h264pic1_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_h264pic1_reg)=data)
#define  get_LGCY_MVDBLK_h264pic1_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_h264pic1_reg))
#define  LGCY_MVDBLK_h264pic1_currfrmpoc_shift                                   (0)
#define  LGCY_MVDBLK_h264pic1_currfrmpoc_mask                                    (0xFFFFFFFF)
#define  LGCY_MVDBLK_h264pic1_currfrmpoc(data)                                   (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_h264pic1_get_currfrmpoc(data)                               (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_h264pic2                                                    0x1800E608
#define  LGCY_MVDBLK_h264pic2_reg_addr                                           "0xB800E608"
#define  LGCY_MVDBLK_h264pic2_reg                                                0xB800E608
#define  LGCY_MVDBLK_h264pic2_inst_addr                                          "0x000B"
#define  set_LGCY_MVDBLK_h264pic2_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_h264pic2_reg)=data)
#define  get_LGCY_MVDBLK_h264pic2_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_h264pic2_reg))
#define  LGCY_MVDBLK_h264pic2_currtoppoc_shift                                   (0)
#define  LGCY_MVDBLK_h264pic2_currtoppoc_mask                                    (0xFFFFFFFF)
#define  LGCY_MVDBLK_h264pic2_currtoppoc(data)                                   (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_h264pic2_get_currtoppoc(data)                               (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_h264pic3                                                    0x1800E60C
#define  LGCY_MVDBLK_h264pic3_reg_addr                                           "0xB800E60C"
#define  LGCY_MVDBLK_h264pic3_reg                                                0xB800E60C
#define  LGCY_MVDBLK_h264pic3_inst_addr                                          "0x000C"
#define  set_LGCY_MVDBLK_h264pic3_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_h264pic3_reg)=data)
#define  get_LGCY_MVDBLK_h264pic3_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_h264pic3_reg))
#define  LGCY_MVDBLK_h264pic3_currbotpoc_shift                                   (0)
#define  LGCY_MVDBLK_h264pic3_currbotpoc_mask                                    (0xFFFFFFFF)
#define  LGCY_MVDBLK_h264pic3_currbotpoc(data)                                   (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_h264pic3_get_currbotpoc(data)                               (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_h264co                                                      0x1800E610
#define  LGCY_MVDBLK_h264co_reg_addr                                             "0xB800E610"
#define  LGCY_MVDBLK_h264co_reg                                                  0xB800E610
#define  LGCY_MVDBLK_h264co_inst_addr                                            "0x000D"
#define  set_LGCY_MVDBLK_h264co_reg(data)                                        (*((volatile unsigned int*)LGCY_MVDBLK_h264co_reg)=data)
#define  get_LGCY_MVDBLK_h264co_reg                                              (*((volatile unsigned int*)LGCY_MVDBLK_h264co_reg))
#define  LGCY_MVDBLK_h264co_comem8x8_shift                                       (0)
#define  LGCY_MVDBLK_h264co_comem8x8_mask                                        (0x0000000F)
#define  LGCY_MVDBLK_h264co_comem8x8(data)                                       (0x0000000F&(data))
#define  LGCY_MVDBLK_h264co_get_comem8x8(data)                                   (0x0000000F&(data))

#define  LGCY_MVDBLK_h264co1                                                     0x1800E614
#define  LGCY_MVDBLK_h264co1_reg_addr                                            "0xB800E614"
#define  LGCY_MVDBLK_h264co1_reg                                                 0xB800E614
#define  LGCY_MVDBLK_h264co1_inst_addr                                           "0x000E"
#define  set_LGCY_MVDBLK_h264co1_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_h264co1_reg)=data)
#define  get_LGCY_MVDBLK_h264co1_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_h264co1_reg))
#define  LGCY_MVDBLK_h264co1_stcomemsaddr_shift                                  (0)
#define  LGCY_MVDBLK_h264co1_stcomemsaddr_mask                                   (0xFFFFFFFF)
#define  LGCY_MVDBLK_h264co1_stcomemsaddr(data)                                  (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_h264co1_get_stcomemsaddr(data)                              (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_h264co2                                                     0x1800E618
#define  LGCY_MVDBLK_h264co2_reg_addr                                            "0xB800E618"
#define  LGCY_MVDBLK_h264co2_reg                                                 0xB800E618
#define  LGCY_MVDBLK_h264co2_inst_addr                                           "0x000F"
#define  set_LGCY_MVDBLK_h264co2_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_h264co2_reg)=data)
#define  get_LGCY_MVDBLK_h264co2_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_h264co2_reg))
#define  LGCY_MVDBLK_h264co2_mbaffaddr_shift                                     (31)
#define  LGCY_MVDBLK_h264co2_ldcomemsaddr_shift                                  (0)
#define  LGCY_MVDBLK_h264co2_mbaffaddr_mask                                      (0x80000000)
#define  LGCY_MVDBLK_h264co2_ldcomemsaddr_mask                                   (0x7FFFFFFF)
#define  LGCY_MVDBLK_h264co2_mbaffaddr(data)                                     (0x80000000&((data)<<31))
#define  LGCY_MVDBLK_h264co2_ldcomemsaddr(data)                                  (0x7FFFFFFF&(data))
#define  LGCY_MVDBLK_h264co2_get_mbaffaddr(data)                                 ((0x80000000&(data))>>31)
#define  LGCY_MVDBLK_h264co2_get_ldcomemsaddr(data)                              (0x7FFFFFFF&(data))

#define  LGCY_MVDBLK_h264co3                                                     0x1800E61C
#define  LGCY_MVDBLK_h264co3_reg_addr                                            "0xB800E61C"
#define  LGCY_MVDBLK_h264co3_reg                                                 0xB800E61C
#define  LGCY_MVDBLK_h264co3_inst_addr                                           "0x0010"
#define  set_LGCY_MVDBLK_h264co3_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_h264co3_reg)=data)
#define  get_LGCY_MVDBLK_h264co3_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_h264co3_reg))
#define  LGCY_MVDBLK_h264co3_enableldcomem1_shift                                (31)
#define  LGCY_MVDBLK_h264co3_ldcomemsaddr1_shift                                 (0)
#define  LGCY_MVDBLK_h264co3_enableldcomem1_mask                                 (0x80000000)
#define  LGCY_MVDBLK_h264co3_ldcomemsaddr1_mask                                  (0x7FFFFFFF)
#define  LGCY_MVDBLK_h264co3_enableldcomem1(data)                                (0x80000000&((data)<<31))
#define  LGCY_MVDBLK_h264co3_ldcomemsaddr1(data)                                 (0x7FFFFFFF&(data))
#define  LGCY_MVDBLK_h264co3_get_enableldcomem1(data)                            ((0x80000000&(data))>>31)
#define  LGCY_MVDBLK_h264co3_get_ldcomemsaddr1(data)                             (0x7FFFFFFF&(data))

#define  LGCY_MVDBLK_h264nh                                                      0x1800E6D0
#define  LGCY_MVDBLK_h264nh_reg_addr                                             "0xB800E6D0"
#define  LGCY_MVDBLK_h264nh_reg                                                  0xB800E6D0
#define  LGCY_MVDBLK_h264nh_inst_addr                                            "0x0011"
#define  set_LGCY_MVDBLK_h264nh_reg(data)                                        (*((volatile unsigned int*)LGCY_MVDBLK_h264nh_reg)=data)
#define  get_LGCY_MVDBLK_h264nh_reg                                              (*((volatile unsigned int*)LGCY_MVDBLK_h264nh_reg))
#define  LGCY_MVDBLK_h264nh_autoldstoff_shift                                    (3)
#define  LGCY_MVDBLK_h264nh_initnhmemcmd_shift                                   (2)
#define  LGCY_MVDBLK_h264nh_ldnhmemcmd_shift                                     (1)
#define  LGCY_MVDBLK_h264nh_stnhmemcmd_shift                                     (0)
#define  LGCY_MVDBLK_h264nh_autoldstoff_mask                                     (0x00000008)
#define  LGCY_MVDBLK_h264nh_initnhmemcmd_mask                                    (0x00000004)
#define  LGCY_MVDBLK_h264nh_ldnhmemcmd_mask                                      (0x00000002)
#define  LGCY_MVDBLK_h264nh_stnhmemcmd_mask                                      (0x00000001)
#define  LGCY_MVDBLK_h264nh_autoldstoff(data)                                    (0x00000008&((data)<<3))
#define  LGCY_MVDBLK_h264nh_initnhmemcmd(data)                                   (0x00000004&((data)<<2))
#define  LGCY_MVDBLK_h264nh_ldnhmemcmd(data)                                     (0x00000002&((data)<<1))
#define  LGCY_MVDBLK_h264nh_stnhmemcmd(data)                                     (0x00000001&(data))
#define  LGCY_MVDBLK_h264nh_get_autoldstoff(data)                                ((0x00000008&(data))>>3)
#define  LGCY_MVDBLK_h264nh_get_initnhmemcmd(data)                               ((0x00000004&(data))>>2)
#define  LGCY_MVDBLK_h264nh_get_ldnhmemcmd(data)                                 ((0x00000002&(data))>>1)
#define  LGCY_MVDBLK_h264nh_get_stnhmemcmd(data)                                 (0x00000001&(data))

#define  LGCY_MVDBLK_h264nh1                                                     0x1800E6D4
#define  LGCY_MVDBLK_h264nh1_reg_addr                                            "0xB800E6D4"
#define  LGCY_MVDBLK_h264nh1_reg                                                 0xB800E6D4
#define  LGCY_MVDBLK_h264nh1_inst_addr                                           "0x0012"
#define  set_LGCY_MVDBLK_h264nh1_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_h264nh1_reg)=data)
#define  get_LGCY_MVDBLK_h264nh1_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_h264nh1_reg))
#define  LGCY_MVDBLK_h264nh1_stnhmemsaddr_shift                                  (0)
#define  LGCY_MVDBLK_h264nh1_stnhmemsaddr_mask                                   (0xFFFFFFFF)
#define  LGCY_MVDBLK_h264nh1_stnhmemsaddr(data)                                  (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_h264nh1_get_stnhmemsaddr(data)                              (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_h264nh2                                                     0x1800E6D8
#define  LGCY_MVDBLK_h264nh2_reg_addr                                            "0xB800E6D8"
#define  LGCY_MVDBLK_h264nh2_reg                                                 0xB800E6D8
#define  LGCY_MVDBLK_h264nh2_inst_addr                                           "0x0013"
#define  set_LGCY_MVDBLK_h264nh2_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_h264nh2_reg)=data)
#define  get_LGCY_MVDBLK_h264nh2_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_h264nh2_reg))
#define  LGCY_MVDBLK_h264nh2_ldnhmemsaddr_shift                                  (0)
#define  LGCY_MVDBLK_h264nh2_ldnhmemsaddr_mask                                   (0xFFFFFFFF)
#define  LGCY_MVDBLK_h264nh2_ldnhmemsaddr(data)                                  (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_h264nh2_get_ldnhmemsaddr(data)                              (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_hevcsao                                                     0x1800E6E4
#define  LGCY_MVDBLK_hevcsao_reg_addr                                            "0xB800E6E4"
#define  LGCY_MVDBLK_hevcsao_reg                                                 0xB800E6E4
#define  LGCY_MVDBLK_hevcsao_inst_addr                                           "0x0014"
#define  set_LGCY_MVDBLK_hevcsao_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_hevcsao_reg)=data)
#define  get_LGCY_MVDBLK_hevcsao_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_hevcsao_reg))
#define  LGCY_MVDBLK_hevcsao_stsaddr_shift                                       (0)
#define  LGCY_MVDBLK_hevcsao_stsaddr_mask                                        (0xFFFFFFFF)
#define  LGCY_MVDBLK_hevcsao_stsaddr(data)                                       (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_hevcsao_get_stsaddr(data)                                   (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_hevcsao1                                                    0x1800E6E8
#define  LGCY_MVDBLK_hevcsao1_reg_addr                                           "0xB800E6E8"
#define  LGCY_MVDBLK_hevcsao1_reg                                                0xB800E6E8
#define  LGCY_MVDBLK_hevcsao1_inst_addr                                          "0x0015"
#define  set_LGCY_MVDBLK_hevcsao1_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_hevcsao1_reg)=data)
#define  get_LGCY_MVDBLK_hevcsao1_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_hevcsao1_reg))
#define  LGCY_MVDBLK_hevcsao1_ldsaddr_shift                                      (0)
#define  LGCY_MVDBLK_hevcsao1_ldsaddr_mask                                       (0xFFFFFFFF)
#define  LGCY_MVDBLK_hevcsao1_ldsaddr(data)                                      (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_hevcsao1_get_ldsaddr(data)                                  (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_h264px                                                      0x1800E620
#define  LGCY_MVDBLK_h264px_reg_addr                                             "0xB800E620"
#define  LGCY_MVDBLK_h264px_reg                                                  0xB800E620
#define  LGCY_MVDBLK_h264px_inst_addr                                            "0x0016"
#define  set_LGCY_MVDBLK_h264px_reg(data)                                        (*((volatile unsigned int*)LGCY_MVDBLK_h264px_reg)=data)
#define  get_LGCY_MVDBLK_h264px_reg                                              (*((volatile unsigned int*)LGCY_MVDBLK_h264px_reg))
#define  LGCY_MVDBLK_h264px_list1size_shift                                      (5)
#define  LGCY_MVDBLK_h264px_list0size_shift                                      (0)
#define  LGCY_MVDBLK_h264px_list1size_mask                                       (0x000003E0)
#define  LGCY_MVDBLK_h264px_list0size_mask                                       (0x0000001F)
#define  LGCY_MVDBLK_h264px_list1size(data)                                      (0x000003E0&((data)<<5))
#define  LGCY_MVDBLK_h264px_list0size(data)                                      (0x0000001F&(data))
#define  LGCY_MVDBLK_h264px_get_list1size(data)                                  ((0x000003E0&(data))>>5)
#define  LGCY_MVDBLK_h264px_get_list0size(data)                                  (0x0000001F&(data))

#define  LGCY_MVDBLK_h264px1                                                     0x1800E624
#define  LGCY_MVDBLK_h264px1_reg_addr                                            "0xB800E624"
#define  LGCY_MVDBLK_h264px1_reg                                                 0xB800E624
#define  LGCY_MVDBLK_h264px1_inst_addr                                           "0x0017"
#define  set_LGCY_MVDBLK_h264px1_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_h264px1_reg)=data)
#define  get_LGCY_MVDBLK_h264px1_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_h264px1_reg))
#define  LGCY_MVDBLK_h264px1_frmpocaddrl0_shift                                  (0)
#define  LGCY_MVDBLK_h264px1_frmpocaddrl0_mask                                   (0x0000FFFF)
#define  LGCY_MVDBLK_h264px1_frmpocaddrl0(data)                                  (0x0000FFFF&(data))
#define  LGCY_MVDBLK_h264px1_get_frmpocaddrl0(data)                              (0x0000FFFF&(data))

#define  LGCY_MVDBLK_h264px2                                                     0x1800E628
#define  LGCY_MVDBLK_h264px2_reg_addr                                            "0xB800E628"
#define  LGCY_MVDBLK_h264px2_reg                                                 0xB800E628
#define  LGCY_MVDBLK_h264px2_inst_addr                                           "0x0018"
#define  set_LGCY_MVDBLK_h264px2_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_h264px2_reg)=data)
#define  get_LGCY_MVDBLK_h264px2_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_h264px2_reg))
#define  LGCY_MVDBLK_h264px2_toppocaddrl0_shift                                  (0)
#define  LGCY_MVDBLK_h264px2_toppocaddrl0_mask                                   (0x0000FFFF)
#define  LGCY_MVDBLK_h264px2_toppocaddrl0(data)                                  (0x0000FFFF&(data))
#define  LGCY_MVDBLK_h264px2_get_toppocaddrl0(data)                              (0x0000FFFF&(data))

#define  LGCY_MVDBLK_h264px3                                                     0x1800E62C
#define  LGCY_MVDBLK_h264px3_reg_addr                                            "0xB800E62C"
#define  LGCY_MVDBLK_h264px3_reg                                                 0xB800E62C
#define  LGCY_MVDBLK_h264px3_inst_addr                                           "0x0019"
#define  set_LGCY_MVDBLK_h264px3_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_h264px3_reg)=data)
#define  get_LGCY_MVDBLK_h264px3_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_h264px3_reg))
#define  LGCY_MVDBLK_h264px3_botpocaddrl0_shift                                  (0)
#define  LGCY_MVDBLK_h264px3_botpocaddrl0_mask                                   (0x0000FFFF)
#define  LGCY_MVDBLK_h264px3_botpocaddrl0(data)                                  (0x0000FFFF&(data))
#define  LGCY_MVDBLK_h264px3_get_botpocaddrl0(data)                              (0x0000FFFF&(data))

#define  LGCY_MVDBLK_h264px4                                                     0x1800E630
#define  LGCY_MVDBLK_h264px4_reg_addr                                            "0xB800E630"
#define  LGCY_MVDBLK_h264px4_reg                                                 0xB800E630
#define  LGCY_MVDBLK_h264px4_inst_addr                                           "0x001A"
#define  set_LGCY_MVDBLK_h264px4_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_h264px4_reg)=data)
#define  get_LGCY_MVDBLK_h264px4_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_h264px4_reg))
#define  LGCY_MVDBLK_h264px4_frmpocaddrl1_shift                                  (0)
#define  LGCY_MVDBLK_h264px4_frmpocaddrl1_mask                                   (0x0000FFFF)
#define  LGCY_MVDBLK_h264px4_frmpocaddrl1(data)                                  (0x0000FFFF&(data))
#define  LGCY_MVDBLK_h264px4_get_frmpocaddrl1(data)                              (0x0000FFFF&(data))

#define  LGCY_MVDBLK_h264px5                                                     0x1800E634
#define  LGCY_MVDBLK_h264px5_reg_addr                                            "0xB800E634"
#define  LGCY_MVDBLK_h264px5_reg                                                 0xB800E634
#define  LGCY_MVDBLK_h264px5_inst_addr                                           "0x001B"
#define  set_LGCY_MVDBLK_h264px5_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_h264px5_reg)=data)
#define  get_LGCY_MVDBLK_h264px5_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_h264px5_reg))
#define  LGCY_MVDBLK_h264px5_toppocaddrl1_shift                                  (0)
#define  LGCY_MVDBLK_h264px5_toppocaddrl1_mask                                   (0x0000FFFF)
#define  LGCY_MVDBLK_h264px5_toppocaddrl1(data)                                  (0x0000FFFF&(data))
#define  LGCY_MVDBLK_h264px5_get_toppocaddrl1(data)                              (0x0000FFFF&(data))

#define  LGCY_MVDBLK_h264px6                                                     0x1800E638
#define  LGCY_MVDBLK_h264px6_reg_addr                                            "0xB800E638"
#define  LGCY_MVDBLK_h264px6_reg                                                 0xB800E638
#define  LGCY_MVDBLK_h264px6_inst_addr                                           "0x001C"
#define  set_LGCY_MVDBLK_h264px6_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_h264px6_reg)=data)
#define  get_LGCY_MVDBLK_h264px6_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_h264px6_reg))
#define  LGCY_MVDBLK_h264px6_botpocaddrl1_shift                                  (0)
#define  LGCY_MVDBLK_h264px6_botpocaddrl1_mask                                   (0x0000FFFF)
#define  LGCY_MVDBLK_h264px6_botpocaddrl1(data)                                  (0x0000FFFF&(data))
#define  LGCY_MVDBLK_h264px6_get_botpocaddrl1(data)                              (0x0000FFFF&(data))

#define  LGCY_MVDBLK_h264px7                                                     0x1800E63C
#define  LGCY_MVDBLK_h264px7_reg_addr                                            "0xB800E63C"
#define  LGCY_MVDBLK_h264px7_reg                                                 0xB800E63C
#define  LGCY_MVDBLK_h264px7_inst_addr                                           "0x001D"
#define  set_LGCY_MVDBLK_h264px7_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_h264px7_reg)=data)
#define  get_LGCY_MVDBLK_h264px7_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_h264px7_reg))
#define  LGCY_MVDBLK_h264px7_picinfoaddr_shift                                   (0)
#define  LGCY_MVDBLK_h264px7_picinfoaddr_mask                                    (0x0000FFFF)
#define  LGCY_MVDBLK_h264px7_picinfoaddr(data)                                   (0x0000FFFF&(data))
#define  LGCY_MVDBLK_h264px7_get_picinfoaddr(data)                               (0x0000FFFF&(data))

#define  LGCY_MVDBLK_vc1pic                                                      0x1800E640
#define  LGCY_MVDBLK_vc1pic_reg_addr                                             "0xB800E640"
#define  LGCY_MVDBLK_vc1pic_reg                                                  0xB800E640
#define  LGCY_MVDBLK_vc1pic_inst_addr                                            "0x001E"
#define  set_LGCY_MVDBLK_vc1pic_reg(data)                                        (*((volatile unsigned int*)LGCY_MVDBLK_vc1pic_reg)=data)
#define  get_LGCY_MVDBLK_vc1pic_reg                                              (*((volatile unsigned int*)LGCY_MVDBLK_vc1pic_reg))
#define  LGCY_MVDBLK_vc1pic_reffield_shift                                       (12)
#define  LGCY_MVDBLK_vc1pic_fastuvmc_shift                                       (11)
#define  LGCY_MVDBLK_vc1pic_scalefactor_shift                                    (0)
#define  LGCY_MVDBLK_vc1pic_reffield_mask                                        (0x00001000)
#define  LGCY_MVDBLK_vc1pic_fastuvmc_mask                                        (0x00000800)
#define  LGCY_MVDBLK_vc1pic_scalefactor_mask                                     (0x000007FF)
#define  LGCY_MVDBLK_vc1pic_reffield(data)                                       (0x00001000&((data)<<12))
#define  LGCY_MVDBLK_vc1pic_fastuvmc(data)                                       (0x00000800&((data)<<11))
#define  LGCY_MVDBLK_vc1pic_scalefactor(data)                                    (0x000007FF&(data))
#define  LGCY_MVDBLK_vc1pic_get_reffield(data)                                   ((0x00001000&(data))>>12)
#define  LGCY_MVDBLK_vc1pic_get_fastuvmc(data)                                   ((0x00000800&(data))>>11)
#define  LGCY_MVDBLK_vc1pic_get_scalefactor(data)                                (0x000007FF&(data))

#define  LGCY_MVDBLK_vc1pic1                                                     0x1800E644
#define  LGCY_MVDBLK_vc1pic1_reg_addr                                            "0xB800E644"
#define  LGCY_MVDBLK_vc1pic1_reg                                                 0xB800E644
#define  LGCY_MVDBLK_vc1pic1_inst_addr                                           "0x001F"
#define  set_LGCY_MVDBLK_vc1pic1_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_vc1pic1_reg)=data)
#define  get_LGCY_MVDBLK_vc1pic1_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_vc1pic1_reg))
#define  LGCY_MVDBLK_vc1pic1_scale_fw_shift                                      (20)
#define  LGCY_MVDBLK_vc1pic1_scale1_fw_shift                                     (8)
#define  LGCY_MVDBLK_vc1pic1_scale2_fw_shift                                     (0)
#define  LGCY_MVDBLK_vc1pic1_scale_fw_mask                                       (0x0FF00000)
#define  LGCY_MVDBLK_vc1pic1_scale1_fw_mask                                      (0x000FFF00)
#define  LGCY_MVDBLK_vc1pic1_scale2_fw_mask                                      (0x000000FF)
#define  LGCY_MVDBLK_vc1pic1_scale_fw(data)                                      (0x0FF00000&((data)<<20))
#define  LGCY_MVDBLK_vc1pic1_scale1_fw(data)                                     (0x000FFF00&((data)<<8))
#define  LGCY_MVDBLK_vc1pic1_scale2_fw(data)                                     (0x000000FF&(data))
#define  LGCY_MVDBLK_vc1pic1_get_scale_fw(data)                                  ((0x0FF00000&(data))>>20)
#define  LGCY_MVDBLK_vc1pic1_get_scale1_fw(data)                                 ((0x000FFF00&(data))>>8)
#define  LGCY_MVDBLK_vc1pic1_get_scale2_fw(data)                                 (0x000000FF&(data))

#define  LGCY_MVDBLK_vc1pic2                                                     0x1800E648
#define  LGCY_MVDBLK_vc1pic2_reg_addr                                            "0xB800E648"
#define  LGCY_MVDBLK_vc1pic2_reg                                                 0xB800E648
#define  LGCY_MVDBLK_vc1pic2_inst_addr                                           "0x0020"
#define  set_LGCY_MVDBLK_vc1pic2_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_vc1pic2_reg)=data)
#define  get_LGCY_MVDBLK_vc1pic2_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_vc1pic2_reg))
#define  LGCY_MVDBLK_vc1pic2_scaleupopp_fw_shift                                 (20)
#define  LGCY_MVDBLK_vc1pic2_scalezone1x_fw_shift                                (14)
#define  LGCY_MVDBLK_vc1pic2_scalezone1y_fw_shift                                (10)
#define  LGCY_MVDBLK_vc1pic2_zone1offsetx_fw_shift                               (4)
#define  LGCY_MVDBLK_vc1pic2_zone1offsety_fw_shift                               (0)
#define  LGCY_MVDBLK_vc1pic2_scaleupopp_fw_mask                                  (0x00100000)
#define  LGCY_MVDBLK_vc1pic2_scalezone1x_fw_mask                                 (0x000FC000)
#define  LGCY_MVDBLK_vc1pic2_scalezone1y_fw_mask                                 (0x00003C00)
#define  LGCY_MVDBLK_vc1pic2_zone1offsetx_fw_mask                                (0x000003F0)
#define  LGCY_MVDBLK_vc1pic2_zone1offsety_fw_mask                                (0x0000000F)
#define  LGCY_MVDBLK_vc1pic2_scaleupopp_fw(data)                                 (0x00100000&((data)<<20))
#define  LGCY_MVDBLK_vc1pic2_scalezone1x_fw(data)                                (0x000FC000&((data)<<14))
#define  LGCY_MVDBLK_vc1pic2_scalezone1y_fw(data)                                (0x00003C00&((data)<<10))
#define  LGCY_MVDBLK_vc1pic2_zone1offsetx_fw(data)                               (0x000003F0&((data)<<4))
#define  LGCY_MVDBLK_vc1pic2_zone1offsety_fw(data)                               (0x0000000F&(data))
#define  LGCY_MVDBLK_vc1pic2_get_scaleupopp_fw(data)                             ((0x00100000&(data))>>20)
#define  LGCY_MVDBLK_vc1pic2_get_scalezone1x_fw(data)                            ((0x000FC000&(data))>>14)
#define  LGCY_MVDBLK_vc1pic2_get_scalezone1y_fw(data)                            ((0x00003C00&(data))>>10)
#define  LGCY_MVDBLK_vc1pic2_get_zone1offsetx_fw(data)                           ((0x000003F0&(data))>>4)
#define  LGCY_MVDBLK_vc1pic2_get_zone1offsety_fw(data)                           (0x0000000F&(data))

#define  LGCY_MVDBLK_vc1pic3                                                     0x1800E64C
#define  LGCY_MVDBLK_vc1pic3_reg_addr                                            "0xB800E64C"
#define  LGCY_MVDBLK_vc1pic3_reg                                                 0xB800E64C
#define  LGCY_MVDBLK_vc1pic3_inst_addr                                           "0x0021"
#define  set_LGCY_MVDBLK_vc1pic3_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_vc1pic3_reg)=data)
#define  get_LGCY_MVDBLK_vc1pic3_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_vc1pic3_reg))
#define  LGCY_MVDBLK_vc1pic3_scale_bw_shift                                      (20)
#define  LGCY_MVDBLK_vc1pic3_scale1_bw_shift                                     (8)
#define  LGCY_MVDBLK_vc1pic3_scale2_bw_shift                                     (0)
#define  LGCY_MVDBLK_vc1pic3_scale_bw_mask                                       (0x0FF00000)
#define  LGCY_MVDBLK_vc1pic3_scale1_bw_mask                                      (0x000FFF00)
#define  LGCY_MVDBLK_vc1pic3_scale2_bw_mask                                      (0x000000FF)
#define  LGCY_MVDBLK_vc1pic3_scale_bw(data)                                      (0x0FF00000&((data)<<20))
#define  LGCY_MVDBLK_vc1pic3_scale1_bw(data)                                     (0x000FFF00&((data)<<8))
#define  LGCY_MVDBLK_vc1pic3_scale2_bw(data)                                     (0x000000FF&(data))
#define  LGCY_MVDBLK_vc1pic3_get_scale_bw(data)                                  ((0x0FF00000&(data))>>20)
#define  LGCY_MVDBLK_vc1pic3_get_scale1_bw(data)                                 ((0x000FFF00&(data))>>8)
#define  LGCY_MVDBLK_vc1pic3_get_scale2_bw(data)                                 (0x000000FF&(data))

#define  LGCY_MVDBLK_vc1pic4                                                     0x1800E650
#define  LGCY_MVDBLK_vc1pic4_reg_addr                                            "0xB800E650"
#define  LGCY_MVDBLK_vc1pic4_reg                                                 0xB800E650
#define  LGCY_MVDBLK_vc1pic4_inst_addr                                           "0x0022"
#define  set_LGCY_MVDBLK_vc1pic4_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_vc1pic4_reg)=data)
#define  get_LGCY_MVDBLK_vc1pic4_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_vc1pic4_reg))
#define  LGCY_MVDBLK_vc1pic4_scaleupopp_bw_shift                                 (20)
#define  LGCY_MVDBLK_vc1pic4_scalezone1x_bw_shift                                (14)
#define  LGCY_MVDBLK_vc1pic4_scalezone1y_bw_shift                                (10)
#define  LGCY_MVDBLK_vc1pic4_zone1offsetx_bw_shift                               (4)
#define  LGCY_MVDBLK_vc1pic4_zone1offsety_bw_shift                               (0)
#define  LGCY_MVDBLK_vc1pic4_scaleupopp_bw_mask                                  (0x00100000)
#define  LGCY_MVDBLK_vc1pic4_scalezone1x_bw_mask                                 (0x000FC000)
#define  LGCY_MVDBLK_vc1pic4_scalezone1y_bw_mask                                 (0x00003C00)
#define  LGCY_MVDBLK_vc1pic4_zone1offsetx_bw_mask                                (0x000003F0)
#define  LGCY_MVDBLK_vc1pic4_zone1offsety_bw_mask                                (0x0000000F)
#define  LGCY_MVDBLK_vc1pic4_scaleupopp_bw(data)                                 (0x00100000&((data)<<20))
#define  LGCY_MVDBLK_vc1pic4_scalezone1x_bw(data)                                (0x000FC000&((data)<<14))
#define  LGCY_MVDBLK_vc1pic4_scalezone1y_bw(data)                                (0x00003C00&((data)<<10))
#define  LGCY_MVDBLK_vc1pic4_zone1offsetx_bw(data)                               (0x000003F0&((data)<<4))
#define  LGCY_MVDBLK_vc1pic4_zone1offsety_bw(data)                               (0x0000000F&(data))
#define  LGCY_MVDBLK_vc1pic4_get_scaleupopp_bw(data)                             ((0x00100000&(data))>>20)
#define  LGCY_MVDBLK_vc1pic4_get_scalezone1x_bw(data)                            ((0x000FC000&(data))>>14)
#define  LGCY_MVDBLK_vc1pic4_get_scalezone1y_bw(data)                            ((0x00003C00&(data))>>10)
#define  LGCY_MVDBLK_vc1pic4_get_zone1offsetx_bw(data)                           ((0x000003F0&(data))>>4)
#define  LGCY_MVDBLK_vc1pic4_get_zone1offsety_bw(data)                           (0x0000000F&(data))

#define  LGCY_MVDBLK_vc1pic5                                                     0x1800E654
#define  LGCY_MVDBLK_vc1pic5_reg_addr                                            "0xB800E654"
#define  LGCY_MVDBLK_vc1pic5_reg                                                 0xB800E654
#define  LGCY_MVDBLK_vc1pic5_inst_addr                                           "0x0023"
#define  set_LGCY_MVDBLK_vc1pic5_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_vc1pic5_reg)=data)
#define  get_LGCY_MVDBLK_vc1pic5_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_vc1pic5_reg))
#define  LGCY_MVDBLK_vc1pic5_rangey_shift                                        (13)
#define  LGCY_MVDBLK_vc1pic5_rangex_shift                                        (0)
#define  LGCY_MVDBLK_vc1pic5_rangey_mask                                         (0x01FFE000)
#define  LGCY_MVDBLK_vc1pic5_rangex_mask                                         (0x00001FFF)
#define  LGCY_MVDBLK_vc1pic5_rangey(data)                                        (0x01FFE000&((data)<<13))
#define  LGCY_MVDBLK_vc1pic5_rangex(data)                                        (0x00001FFF&(data))
#define  LGCY_MVDBLK_vc1pic5_get_rangey(data)                                    ((0x01FFE000&(data))>>13)
#define  LGCY_MVDBLK_vc1pic5_get_rangex(data)                                    (0x00001FFF&(data))

#define  LGCY_MVDBLK_avspic                                                      0x1800E7D0
#define  LGCY_MVDBLK_avspic_reg_addr                                             "0xB800E7D0"
#define  LGCY_MVDBLK_avspic_reg                                                  0xB800E7D0
#define  LGCY_MVDBLK_avspic_inst_addr                                            "0x0024"
#define  set_LGCY_MVDBLK_avspic_reg(data)                                        (*((volatile unsigned int*)LGCY_MVDBLK_avspic_reg)=data)
#define  get_LGCY_MVDBLK_avspic_reg                                              (*((volatile unsigned int*)LGCY_MVDBLK_avspic_reg))
#define  LGCY_MVDBLK_avspic_aecenable_shift                                      (4)
#define  LGCY_MVDBLK_avspic_pfieldskip_shift                                     (3)
#define  LGCY_MVDBLK_avspic_bfieldenhanced_shift                                 (2)
#define  LGCY_MVDBLK_avspic_picrefflag_shift                                     (1)
#define  LGCY_MVDBLK_avspic_picstructure_shift                                   (0)
#define  LGCY_MVDBLK_avspic_aecenable_mask                                       (0x00000010)
#define  LGCY_MVDBLK_avspic_pfieldskip_mask                                      (0x00000008)
#define  LGCY_MVDBLK_avspic_bfieldenhanced_mask                                  (0x00000004)
#define  LGCY_MVDBLK_avspic_picrefflag_mask                                      (0x00000002)
#define  LGCY_MVDBLK_avspic_picstructure_mask                                    (0x00000001)
#define  LGCY_MVDBLK_avspic_aecenable(data)                                      (0x00000010&((data)<<4))
#define  LGCY_MVDBLK_avspic_pfieldskip(data)                                     (0x00000008&((data)<<3))
#define  LGCY_MVDBLK_avspic_bfieldenhanced(data)                                 (0x00000004&((data)<<2))
#define  LGCY_MVDBLK_avspic_picrefflag(data)                                     (0x00000002&((data)<<1))
#define  LGCY_MVDBLK_avspic_picstructure(data)                                   (0x00000001&(data))
#define  LGCY_MVDBLK_avspic_get_aecenable(data)                                  ((0x00000010&(data))>>4)
#define  LGCY_MVDBLK_avspic_get_pfieldskip(data)                                 ((0x00000008&(data))>>3)
#define  LGCY_MVDBLK_avspic_get_bfieldenhanced(data)                             ((0x00000004&(data))>>2)
#define  LGCY_MVDBLK_avspic_get_picrefflag(data)                                 ((0x00000002&(data))>>1)
#define  LGCY_MVDBLK_avspic_get_picstructure(data)                               (0x00000001&(data))

#define  LGCY_MVDBLK_avspic1                                                     0x1800E7D4
#define  LGCY_MVDBLK_avspic1_reg_addr                                            "0xB800E7D4"
#define  LGCY_MVDBLK_avspic1_reg                                                 0xB800E7D4
#define  LGCY_MVDBLK_avspic1_inst_addr                                           "0x0025"
#define  set_LGCY_MVDBLK_avspic1_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_avspic1_reg)=data)
#define  get_LGCY_MVDBLK_avspic1_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_avspic1_reg))
#define  LGCY_MVDBLK_avspic1_blockdist0_shift                                    (16)
#define  LGCY_MVDBLK_avspic1_blockdist1_shift                                    (0)
#define  LGCY_MVDBLK_avspic1_blockdist0_mask                                     (0x01FF0000)
#define  LGCY_MVDBLK_avspic1_blockdist1_mask                                     (0x000001FF)
#define  LGCY_MVDBLK_avspic1_blockdist0(data)                                    (0x01FF0000&((data)<<16))
#define  LGCY_MVDBLK_avspic1_blockdist1(data)                                    (0x000001FF&(data))
#define  LGCY_MVDBLK_avspic1_get_blockdist0(data)                                ((0x01FF0000&(data))>>16)
#define  LGCY_MVDBLK_avspic1_get_blockdist1(data)                                (0x000001FF&(data))

#define  LGCY_MVDBLK_avspic2                                                     0x1800E7D8
#define  LGCY_MVDBLK_avspic2_reg_addr                                            "0xB800E7D8"
#define  LGCY_MVDBLK_avspic2_reg                                                 0xB800E7D8
#define  LGCY_MVDBLK_avspic2_inst_addr                                           "0x0026"
#define  set_LGCY_MVDBLK_avspic2_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_avspic2_reg)=data)
#define  get_LGCY_MVDBLK_avspic2_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_avspic2_reg))
#define  LGCY_MVDBLK_avspic2_blockdist2_shift                                    (16)
#define  LGCY_MVDBLK_avspic2_blockdist3_shift                                    (0)
#define  LGCY_MVDBLK_avspic2_blockdist2_mask                                     (0x01FF0000)
#define  LGCY_MVDBLK_avspic2_blockdist3_mask                                     (0x000001FF)
#define  LGCY_MVDBLK_avspic2_blockdist2(data)                                    (0x01FF0000&((data)<<16))
#define  LGCY_MVDBLK_avspic2_blockdist3(data)                                    (0x000001FF&(data))
#define  LGCY_MVDBLK_avspic2_get_blockdist2(data)                                ((0x01FF0000&(data))>>16)
#define  LGCY_MVDBLK_avspic2_get_blockdist3(data)                                (0x000001FF&(data))

#define  LGCY_MVDBLK_avspic3                                                     0x1800E7DC
#define  LGCY_MVDBLK_avspic3_reg_addr                                            "0xB800E7DC"
#define  LGCY_MVDBLK_avspic3_reg                                                 0xB800E7DC
#define  LGCY_MVDBLK_avspic3_inst_addr                                           "0x0027"
#define  set_LGCY_MVDBLK_avspic3_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_avspic3_reg)=data)
#define  get_LGCY_MVDBLK_avspic3_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_avspic3_reg))
#define  LGCY_MVDBLK_avspic3_b16384divitrp0_shift                                (16)
#define  LGCY_MVDBLK_avspic3_b16384divitrp1_shift                                (0)
#define  LGCY_MVDBLK_avspic3_b16384divitrp0_mask                                 (0xFFFF0000)
#define  LGCY_MVDBLK_avspic3_b16384divitrp1_mask                                 (0x0000FFFF)
#define  LGCY_MVDBLK_avspic3_b16384divitrp0(data)                                (0xFFFF0000&((data)<<16))
#define  LGCY_MVDBLK_avspic3_b16384divitrp1(data)                                (0x0000FFFF&(data))
#define  LGCY_MVDBLK_avspic3_get_b16384divitrp0(data)                            ((0xFFFF0000&(data))>>16)
#define  LGCY_MVDBLK_avspic3_get_b16384divitrp1(data)                            (0x0000FFFF&(data))

#define  LGCY_MVDBLK_avspic4                                                     0x1800E7E0
#define  LGCY_MVDBLK_avspic4_reg_addr                                            "0xB800E7E0"
#define  LGCY_MVDBLK_avspic4_reg                                                 0xB800E7E0
#define  LGCY_MVDBLK_avspic4_inst_addr                                           "0x0028"
#define  set_LGCY_MVDBLK_avspic4_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_avspic4_reg)=data)
#define  get_LGCY_MVDBLK_avspic4_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_avspic4_reg))
#define  LGCY_MVDBLK_avspic4_b16384divitrp2_shift                                (16)
#define  LGCY_MVDBLK_avspic4_b16384divitrp3_shift                                (0)
#define  LGCY_MVDBLK_avspic4_b16384divitrp2_mask                                 (0xFFFF0000)
#define  LGCY_MVDBLK_avspic4_b16384divitrp3_mask                                 (0x0000FFFF)
#define  LGCY_MVDBLK_avspic4_b16384divitrp2(data)                                (0xFFFF0000&((data)<<16))
#define  LGCY_MVDBLK_avspic4_b16384divitrp3(data)                                (0x0000FFFF&(data))
#define  LGCY_MVDBLK_avspic4_get_b16384divitrp2(data)                            ((0xFFFF0000&(data))>>16)
#define  LGCY_MVDBLK_avspic4_get_b16384divitrp3(data)                            (0x0000FFFF&(data))

#define  LGCY_MVDBLK_avspic5                                                     0x1800E7E4
#define  LGCY_MVDBLK_avspic5_reg_addr                                            "0xB800E7E4"
#define  LGCY_MVDBLK_avspic5_reg                                                 0xB800E7E4
#define  LGCY_MVDBLK_avspic5_inst_addr                                           "0x0029"
#define  set_LGCY_MVDBLK_avspic5_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_avspic5_reg)=data)
#define  get_LGCY_MVDBLK_avspic5_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_avspic5_reg))
#define  LGCY_MVDBLK_avspic5_itrb0_shift                                         (16)
#define  LGCY_MVDBLK_avspic5_itrb1_shift                                         (0)
#define  LGCY_MVDBLK_avspic5_itrb0_mask                                          (0x01FF0000)
#define  LGCY_MVDBLK_avspic5_itrb1_mask                                          (0x000001FF)
#define  LGCY_MVDBLK_avspic5_itrb0(data)                                         (0x01FF0000&((data)<<16))
#define  LGCY_MVDBLK_avspic5_itrb1(data)                                         (0x000001FF&(data))
#define  LGCY_MVDBLK_avspic5_get_itrb0(data)                                     ((0x01FF0000&(data))>>16)
#define  LGCY_MVDBLK_avspic5_get_itrb1(data)                                     (0x000001FF&(data))

#define  LGCY_MVDBLK_avspic6                                                     0x1800E7E8
#define  LGCY_MVDBLK_avspic6_reg_addr                                            "0xB800E7E8"
#define  LGCY_MVDBLK_avspic6_reg                                                 0xB800E7E8
#define  LGCY_MVDBLK_avspic6_inst_addr                                           "0x002A"
#define  set_LGCY_MVDBLK_avspic6_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_avspic6_reg)=data)
#define  get_LGCY_MVDBLK_avspic6_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_avspic6_reg))
#define  LGCY_MVDBLK_avspic6_itrb2_shift                                         (16)
#define  LGCY_MVDBLK_avspic6_itrb3_shift                                         (0)
#define  LGCY_MVDBLK_avspic6_itrb2_mask                                          (0x01FF0000)
#define  LGCY_MVDBLK_avspic6_itrb3_mask                                          (0x000001FF)
#define  LGCY_MVDBLK_avspic6_itrb2(data)                                         (0x01FF0000&((data)<<16))
#define  LGCY_MVDBLK_avspic6_itrb3(data)                                         (0x000001FF&(data))
#define  LGCY_MVDBLK_avspic6_get_itrb2(data)                                     ((0x01FF0000&(data))>>16)
#define  LGCY_MVDBLK_avspic6_get_itrb3(data)                                     (0x000001FF&(data))

#define  LGCY_MVDBLK_avspic7                                                     0x1800E7EC
#define  LGCY_MVDBLK_avspic7_reg_addr                                            "0xB800E7EC"
#define  LGCY_MVDBLK_avspic7_reg                                                 0xB800E7EC
#define  LGCY_MVDBLK_avspic7_inst_addr                                           "0x002B"
#define  set_LGCY_MVDBLK_avspic7_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_avspic7_reg)=data)
#define  get_LGCY_MVDBLK_avspic7_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_avspic7_reg))
#define  LGCY_MVDBLK_avspic7_itrd_shift                                          (0)
#define  LGCY_MVDBLK_avspic7_itrd_mask                                           (0x000001FF)
#define  LGCY_MVDBLK_avspic7_itrd(data)                                          (0x000001FF&(data))
#define  LGCY_MVDBLK_avspic7_get_itrd(data)                                      (0x000001FF&(data))

#define  LGCY_MVDBLK_rm89pic                                                     0x1800E7C0
#define  LGCY_MVDBLK_rm89pic_reg_addr                                            "0xB800E7C0"
#define  LGCY_MVDBLK_rm89pic_reg                                                 0xB800E7C0
#define  LGCY_MVDBLK_rm89pic_inst_addr                                           "0x002C"
#define  set_LGCY_MVDBLK_rm89pic_reg(data)                                       (*((volatile unsigned int*)LGCY_MVDBLK_rm89pic_reg)=data)
#define  get_LGCY_MVDBLK_rm89pic_reg                                             (*((volatile unsigned int*)LGCY_MVDBLK_rm89pic_reg))
#define  LGCY_MVDBLK_rm89pic_iratio0_shift                                       (0)
#define  LGCY_MVDBLK_rm89pic_iratio0_mask                                        (0xFFFFFFFF)
#define  LGCY_MVDBLK_rm89pic_iratio0(data)                                       (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_rm89pic_get_iratio0(data)                                   (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_rm89pic1                                                    0x1800E7C4
#define  LGCY_MVDBLK_rm89pic1_reg_addr                                           "0xB800E7C4"
#define  LGCY_MVDBLK_rm89pic1_reg                                                0xB800E7C4
#define  LGCY_MVDBLK_rm89pic1_inst_addr                                          "0x002D"
#define  set_LGCY_MVDBLK_rm89pic1_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_rm89pic1_reg)=data)
#define  get_LGCY_MVDBLK_rm89pic1_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_rm89pic1_reg))
#define  LGCY_MVDBLK_rm89pic1_iratio1_shift                                      (0)
#define  LGCY_MVDBLK_rm89pic1_iratio1_mask                                       (0xFFFFFFFF)
#define  LGCY_MVDBLK_rm89pic1_iratio1(data)                                      (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_rm89pic1_get_iratio1(data)                                  (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_rm89direct                                                  0x1800E7C8
#define  LGCY_MVDBLK_rm89direct_reg_addr                                         "0xB800E7C8"
#define  LGCY_MVDBLK_rm89direct_reg                                              0xB800E7C8
#define  LGCY_MVDBLK_rm89direct_inst_addr                                        "0x002E"
#define  set_LGCY_MVDBLK_rm89direct_reg(data)                                    (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct_reg)=data)
#define  get_LGCY_MVDBLK_rm89direct_reg                                          (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct_reg))
#define  LGCY_MVDBLK_rm89direct_hix_shift                                        (16)
#define  LGCY_MVDBLK_rm89direct_lox_shift                                        (0)
#define  LGCY_MVDBLK_rm89direct_hix_mask                                         (0x3FFF0000)
#define  LGCY_MVDBLK_rm89direct_lox_mask                                         (0x00003FFF)
#define  LGCY_MVDBLK_rm89direct_hix(data)                                        (0x3FFF0000&((data)<<16))
#define  LGCY_MVDBLK_rm89direct_lox(data)                                        (0x00003FFF&(data))
#define  LGCY_MVDBLK_rm89direct_get_hix(data)                                    ((0x3FFF0000&(data))>>16)
#define  LGCY_MVDBLK_rm89direct_get_lox(data)                                    (0x00003FFF&(data))

#define  LGCY_MVDBLK_rm89direct1                                                 0x1800E7CC
#define  LGCY_MVDBLK_rm89direct1_reg_addr                                        "0xB800E7CC"
#define  LGCY_MVDBLK_rm89direct1_reg                                             0xB800E7CC
#define  LGCY_MVDBLK_rm89direct1_inst_addr                                       "0x002F"
#define  set_LGCY_MVDBLK_rm89direct1_reg(data)                                   (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct1_reg)=data)
#define  get_LGCY_MVDBLK_rm89direct1_reg                                         (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct1_reg))
#define  LGCY_MVDBLK_rm89direct1_hiy_shift                                       (16)
#define  LGCY_MVDBLK_rm89direct1_loy_shift                                       (0)
#define  LGCY_MVDBLK_rm89direct1_hiy_mask                                        (0x3FFF0000)
#define  LGCY_MVDBLK_rm89direct1_loy_mask                                        (0x00003FFF)
#define  LGCY_MVDBLK_rm89direct1_hiy(data)                                       (0x3FFF0000&((data)<<16))
#define  LGCY_MVDBLK_rm89direct1_loy(data)                                       (0x00003FFF&(data))
#define  LGCY_MVDBLK_rm89direct1_get_hiy(data)                                   ((0x3FFF0000&(data))>>16)
#define  LGCY_MVDBLK_rm89direct1_get_loy(data)                                   (0x00003FFF&(data))

#define  LGCY_MVDBLK_rm89direct2                                                 0x1800E7F0
#define  LGCY_MVDBLK_rm89direct2_reg_addr                                        "0xB800E7F0"
#define  LGCY_MVDBLK_rm89direct2_reg                                             0xB800E7F0
#define  LGCY_MVDBLK_rm89direct2_inst_addr                                       "0x0030"
#define  set_LGCY_MVDBLK_rm89direct2_reg(data)                                   (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct2_reg)=data)
#define  get_LGCY_MVDBLK_rm89direct2_reg                                         (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct2_reg))
#define  LGCY_MVDBLK_rm89direct2_hicx_shift                                      (16)
#define  LGCY_MVDBLK_rm89direct2_locx_shift                                      (0)
#define  LGCY_MVDBLK_rm89direct2_hicx_mask                                       (0x3FFF0000)
#define  LGCY_MVDBLK_rm89direct2_locx_mask                                       (0x00003FFF)
#define  LGCY_MVDBLK_rm89direct2_hicx(data)                                      (0x3FFF0000&((data)<<16))
#define  LGCY_MVDBLK_rm89direct2_locx(data)                                      (0x00003FFF&(data))
#define  LGCY_MVDBLK_rm89direct2_get_hicx(data)                                  ((0x3FFF0000&(data))>>16)
#define  LGCY_MVDBLK_rm89direct2_get_locx(data)                                  (0x00003FFF&(data))

#define  LGCY_MVDBLK_rm89direct3                                                 0x1800E7F4
#define  LGCY_MVDBLK_rm89direct3_reg_addr                                        "0xB800E7F4"
#define  LGCY_MVDBLK_rm89direct3_reg                                             0xB800E7F4
#define  LGCY_MVDBLK_rm89direct3_inst_addr                                       "0x0031"
#define  set_LGCY_MVDBLK_rm89direct3_reg(data)                                   (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct3_reg)=data)
#define  get_LGCY_MVDBLK_rm89direct3_reg                                         (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct3_reg))
#define  LGCY_MVDBLK_rm89direct3_hicy_shift                                      (16)
#define  LGCY_MVDBLK_rm89direct3_locy_shift                                      (0)
#define  LGCY_MVDBLK_rm89direct3_hicy_mask                                       (0x3FFF0000)
#define  LGCY_MVDBLK_rm89direct3_locy_mask                                       (0x00003FFF)
#define  LGCY_MVDBLK_rm89direct3_hicy(data)                                      (0x3FFF0000&((data)<<16))
#define  LGCY_MVDBLK_rm89direct3_locy(data)                                      (0x00003FFF&(data))
#define  LGCY_MVDBLK_rm89direct3_get_hicy(data)                                  ((0x3FFF0000&(data))>>16)
#define  LGCY_MVDBLK_rm89direct3_get_locy(data)                                  (0x00003FFF&(data))

#define  LGCY_MVDBLK_rm89pic2                                                    0x1800E7F8
#define  LGCY_MVDBLK_rm89pic2_reg_addr                                           "0xB800E7F8"
#define  LGCY_MVDBLK_rm89pic2_reg                                                0xB800E7F8
#define  LGCY_MVDBLK_rm89pic2_inst_addr                                          "0x0032"
#define  set_LGCY_MVDBLK_rm89pic2_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_rm89pic2_reg)=data)
#define  get_LGCY_MVDBLK_rm89pic2_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_rm89pic2_reg))
#define  LGCY_MVDBLK_rm89pic2_zeromvd_shift                                      (0)
#define  LGCY_MVDBLK_rm89pic2_zeromvd_mask                                       (0x00000001)
#define  LGCY_MVDBLK_rm89pic2_zeromvd(data)                                      (0x00000001&(data))
#define  LGCY_MVDBLK_rm89pic2_get_zeromvd(data)                                  (0x00000001&(data))

#define  LGCY_MVDBLK_rm89direct4                                                 0x1800E7FC
#define  LGCY_MVDBLK_rm89direct4_reg_addr                                        "0xB800E7FC"
#define  LGCY_MVDBLK_rm89direct4_reg                                             0xB800E7FC
#define  LGCY_MVDBLK_rm89direct4_inst_addr                                       "0x0033"
#define  set_LGCY_MVDBLK_rm89direct4_reg(data)                                   (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct4_reg)=data)
#define  get_LGCY_MVDBLK_rm89direct4_reg                                         (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct4_reg))
#define  LGCY_MVDBLK_rm89direct4_hix_4v_shift                                    (16)
#define  LGCY_MVDBLK_rm89direct4_lox_4v_shift                                    (0)
#define  LGCY_MVDBLK_rm89direct4_hix_4v_mask                                     (0x3FFF0000)
#define  LGCY_MVDBLK_rm89direct4_lox_4v_mask                                     (0x00003FFF)
#define  LGCY_MVDBLK_rm89direct4_hix_4v(data)                                    (0x3FFF0000&((data)<<16))
#define  LGCY_MVDBLK_rm89direct4_lox_4v(data)                                    (0x00003FFF&(data))
#define  LGCY_MVDBLK_rm89direct4_get_hix_4v(data)                                ((0x3FFF0000&(data))>>16)
#define  LGCY_MVDBLK_rm89direct4_get_lox_4v(data)                                (0x00003FFF&(data))

#define  LGCY_MVDBLK_rm89direct5                                                 0x1800E6CC
#define  LGCY_MVDBLK_rm89direct5_reg_addr                                        "0xB800E6CC"
#define  LGCY_MVDBLK_rm89direct5_reg                                             0xB800E6CC
#define  LGCY_MVDBLK_rm89direct5_inst_addr                                       "0x0034"
#define  set_LGCY_MVDBLK_rm89direct5_reg(data)                                   (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct5_reg)=data)
#define  get_LGCY_MVDBLK_rm89direct5_reg                                         (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct5_reg))
#define  LGCY_MVDBLK_rm89direct5_hiy_4v_shift                                    (16)
#define  LGCY_MVDBLK_rm89direct5_loy_4v_shift                                    (0)
#define  LGCY_MVDBLK_rm89direct5_hiy_4v_mask                                     (0x3FFF0000)
#define  LGCY_MVDBLK_rm89direct5_loy_4v_mask                                     (0x00003FFF)
#define  LGCY_MVDBLK_rm89direct5_hiy_4v(data)                                    (0x3FFF0000&((data)<<16))
#define  LGCY_MVDBLK_rm89direct5_loy_4v(data)                                    (0x00003FFF&(data))
#define  LGCY_MVDBLK_rm89direct5_get_hiy_4v(data)                                ((0x3FFF0000&(data))>>16)
#define  LGCY_MVDBLK_rm89direct5_get_loy_4v(data)                                (0x00003FFF&(data))

#define  LGCY_MVDBLK_rm89direct6                                                 0x1800E658
#define  LGCY_MVDBLK_rm89direct6_reg_addr                                        "0xB800E658"
#define  LGCY_MVDBLK_rm89direct6_reg                                             0xB800E658
#define  LGCY_MVDBLK_rm89direct6_inst_addr                                       "0x0035"
#define  set_LGCY_MVDBLK_rm89direct6_reg(data)                                   (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct6_reg)=data)
#define  get_LGCY_MVDBLK_rm89direct6_reg                                         (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct6_reg))
#define  LGCY_MVDBLK_rm89direct6_hicx_4v_shift                                   (16)
#define  LGCY_MVDBLK_rm89direct6_locx_4v_shift                                   (0)
#define  LGCY_MVDBLK_rm89direct6_hicx_4v_mask                                    (0x3FFF0000)
#define  LGCY_MVDBLK_rm89direct6_locx_4v_mask                                    (0x00003FFF)
#define  LGCY_MVDBLK_rm89direct6_hicx_4v(data)                                   (0x3FFF0000&((data)<<16))
#define  LGCY_MVDBLK_rm89direct6_locx_4v(data)                                   (0x00003FFF&(data))
#define  LGCY_MVDBLK_rm89direct6_get_hicx_4v(data)                               ((0x3FFF0000&(data))>>16)
#define  LGCY_MVDBLK_rm89direct6_get_locx_4v(data)                               (0x00003FFF&(data))

#define  LGCY_MVDBLK_rm89direct7                                                 0x1800E65C
#define  LGCY_MVDBLK_rm89direct7_reg_addr                                        "0xB800E65C"
#define  LGCY_MVDBLK_rm89direct7_reg                                             0xB800E65C
#define  LGCY_MVDBLK_rm89direct7_inst_addr                                       "0x0036"
#define  set_LGCY_MVDBLK_rm89direct7_reg(data)                                   (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct7_reg)=data)
#define  get_LGCY_MVDBLK_rm89direct7_reg                                         (*((volatile unsigned int*)LGCY_MVDBLK_rm89direct7_reg))
#define  LGCY_MVDBLK_rm89direct7_hicy_4v_shift                                   (16)
#define  LGCY_MVDBLK_rm89direct7_locy_4v_shift                                   (0)
#define  LGCY_MVDBLK_rm89direct7_hicy_4v_mask                                    (0x3FFF0000)
#define  LGCY_MVDBLK_rm89direct7_locy_4v_mask                                    (0x00003FFF)
#define  LGCY_MVDBLK_rm89direct7_hicy_4v(data)                                   (0x3FFF0000&((data)<<16))
#define  LGCY_MVDBLK_rm89direct7_locy_4v(data)                                   (0x00003FFF&(data))
#define  LGCY_MVDBLK_rm89direct7_get_hicy_4v(data)                               ((0x3FFF0000&(data))>>16)
#define  LGCY_MVDBLK_rm89direct7_get_locy_4v(data)                               (0x00003FFF&(data))

#define  LGCY_MVDBLK_sepool_0                                                    0x1800E700
#define  LGCY_MVDBLK_sepool_0_reg_addr                                           "0xB800E700"
#define  LGCY_MVDBLK_sepool_0_reg                                                0xB800E700
#define  LGCY_MVDBLK_sepool_0_inst_addr                                          "0x0037"
#define  set_LGCY_MVDBLK_sepool_0_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_sepool_0_reg)=data)
#define  get_LGCY_MVDBLK_sepool_0_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_sepool_0_reg))
#define  LGCY_MVDBLK_sepool_0_entry_shift                                        (0)
#define  LGCY_MVDBLK_sepool_0_entry_mask                                         (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_0_entry(data)                                        (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_0_get_entry(data)                                    (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_1                                                    0x1800E704
#define  LGCY_MVDBLK_sepool_1_reg_addr                                           "0xB800E704"
#define  LGCY_MVDBLK_sepool_1_reg                                                0xB800E704
#define  LGCY_MVDBLK_sepool_1_inst_addr                                          "0x0038"
#define  set_LGCY_MVDBLK_sepool_1_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_sepool_1_reg)=data)
#define  get_LGCY_MVDBLK_sepool_1_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_sepool_1_reg))
#define  LGCY_MVDBLK_sepool_1_entry_shift                                        (0)
#define  LGCY_MVDBLK_sepool_1_entry_mask                                         (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_1_entry(data)                                        (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_1_get_entry(data)                                    (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_2                                                    0x1800E708
#define  LGCY_MVDBLK_sepool_2_reg_addr                                           "0xB800E708"
#define  LGCY_MVDBLK_sepool_2_reg                                                0xB800E708
#define  LGCY_MVDBLK_sepool_2_inst_addr                                          "0x0039"
#define  set_LGCY_MVDBLK_sepool_2_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_sepool_2_reg)=data)
#define  get_LGCY_MVDBLK_sepool_2_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_sepool_2_reg))
#define  LGCY_MVDBLK_sepool_2_entry_shift                                        (0)
#define  LGCY_MVDBLK_sepool_2_entry_mask                                         (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_2_entry(data)                                        (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_2_get_entry(data)                                    (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_3                                                    0x1800E70C
#define  LGCY_MVDBLK_sepool_3_reg_addr                                           "0xB800E70C"
#define  LGCY_MVDBLK_sepool_3_reg                                                0xB800E70C
#define  LGCY_MVDBLK_sepool_3_inst_addr                                          "0x003A"
#define  set_LGCY_MVDBLK_sepool_3_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_sepool_3_reg)=data)
#define  get_LGCY_MVDBLK_sepool_3_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_sepool_3_reg))
#define  LGCY_MVDBLK_sepool_3_entry_shift                                        (0)
#define  LGCY_MVDBLK_sepool_3_entry_mask                                         (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_3_entry(data)                                        (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_3_get_entry(data)                                    (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_4                                                    0x1800E710
#define  LGCY_MVDBLK_sepool_4_reg_addr                                           "0xB800E710"
#define  LGCY_MVDBLK_sepool_4_reg                                                0xB800E710
#define  LGCY_MVDBLK_sepool_4_inst_addr                                          "0x003B"
#define  set_LGCY_MVDBLK_sepool_4_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_sepool_4_reg)=data)
#define  get_LGCY_MVDBLK_sepool_4_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_sepool_4_reg))
#define  LGCY_MVDBLK_sepool_4_entry_shift                                        (0)
#define  LGCY_MVDBLK_sepool_4_entry_mask                                         (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_4_entry(data)                                        (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_4_get_entry(data)                                    (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_5                                                    0x1800E714
#define  LGCY_MVDBLK_sepool_5_reg_addr                                           "0xB800E714"
#define  LGCY_MVDBLK_sepool_5_reg                                                0xB800E714
#define  LGCY_MVDBLK_sepool_5_inst_addr                                          "0x003C"
#define  set_LGCY_MVDBLK_sepool_5_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_sepool_5_reg)=data)
#define  get_LGCY_MVDBLK_sepool_5_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_sepool_5_reg))
#define  LGCY_MVDBLK_sepool_5_entry_shift                                        (0)
#define  LGCY_MVDBLK_sepool_5_entry_mask                                         (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_5_entry(data)                                        (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_5_get_entry(data)                                    (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_6                                                    0x1800E718
#define  LGCY_MVDBLK_sepool_6_reg_addr                                           "0xB800E718"
#define  LGCY_MVDBLK_sepool_6_reg                                                0xB800E718
#define  LGCY_MVDBLK_sepool_6_inst_addr                                          "0x003D"
#define  set_LGCY_MVDBLK_sepool_6_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_sepool_6_reg)=data)
#define  get_LGCY_MVDBLK_sepool_6_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_sepool_6_reg))
#define  LGCY_MVDBLK_sepool_6_entry_shift                                        (0)
#define  LGCY_MVDBLK_sepool_6_entry_mask                                         (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_6_entry(data)                                        (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_6_get_entry(data)                                    (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_7                                                    0x1800E71C
#define  LGCY_MVDBLK_sepool_7_reg_addr                                           "0xB800E71C"
#define  LGCY_MVDBLK_sepool_7_reg                                                0xB800E71C
#define  LGCY_MVDBLK_sepool_7_inst_addr                                          "0x003E"
#define  set_LGCY_MVDBLK_sepool_7_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_sepool_7_reg)=data)
#define  get_LGCY_MVDBLK_sepool_7_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_sepool_7_reg))
#define  LGCY_MVDBLK_sepool_7_entry_shift                                        (0)
#define  LGCY_MVDBLK_sepool_7_entry_mask                                         (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_7_entry(data)                                        (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_7_get_entry(data)                                    (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_8                                                    0x1800E720
#define  LGCY_MVDBLK_sepool_8_reg_addr                                           "0xB800E720"
#define  LGCY_MVDBLK_sepool_8_reg                                                0xB800E720
#define  LGCY_MVDBLK_sepool_8_inst_addr                                          "0x003F"
#define  set_LGCY_MVDBLK_sepool_8_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_sepool_8_reg)=data)
#define  get_LGCY_MVDBLK_sepool_8_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_sepool_8_reg))
#define  LGCY_MVDBLK_sepool_8_entry_shift                                        (0)
#define  LGCY_MVDBLK_sepool_8_entry_mask                                         (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_8_entry(data)                                        (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_8_get_entry(data)                                    (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_9                                                    0x1800E724
#define  LGCY_MVDBLK_sepool_9_reg_addr                                           "0xB800E724"
#define  LGCY_MVDBLK_sepool_9_reg                                                0xB800E724
#define  LGCY_MVDBLK_sepool_9_inst_addr                                          "0x0040"
#define  set_LGCY_MVDBLK_sepool_9_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_sepool_9_reg)=data)
#define  get_LGCY_MVDBLK_sepool_9_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_sepool_9_reg))
#define  LGCY_MVDBLK_sepool_9_entry_shift                                        (0)
#define  LGCY_MVDBLK_sepool_9_entry_mask                                         (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_9_entry(data)                                        (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_9_get_entry(data)                                    (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_10                                                   0x1800E728
#define  LGCY_MVDBLK_sepool_10_reg_addr                                          "0xB800E728"
#define  LGCY_MVDBLK_sepool_10_reg                                               0xB800E728
#define  LGCY_MVDBLK_sepool_10_inst_addr                                         "0x0041"
#define  set_LGCY_MVDBLK_sepool_10_reg(data)                                     (*((volatile unsigned int*)LGCY_MVDBLK_sepool_10_reg)=data)
#define  get_LGCY_MVDBLK_sepool_10_reg                                           (*((volatile unsigned int*)LGCY_MVDBLK_sepool_10_reg))
#define  LGCY_MVDBLK_sepool_10_entry_shift                                       (0)
#define  LGCY_MVDBLK_sepool_10_entry_mask                                        (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_10_entry(data)                                       (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_10_get_entry(data)                                   (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_11                                                   0x1800E72C
#define  LGCY_MVDBLK_sepool_11_reg_addr                                          "0xB800E72C"
#define  LGCY_MVDBLK_sepool_11_reg                                               0xB800E72C
#define  LGCY_MVDBLK_sepool_11_inst_addr                                         "0x0042"
#define  set_LGCY_MVDBLK_sepool_11_reg(data)                                     (*((volatile unsigned int*)LGCY_MVDBLK_sepool_11_reg)=data)
#define  get_LGCY_MVDBLK_sepool_11_reg                                           (*((volatile unsigned int*)LGCY_MVDBLK_sepool_11_reg))
#define  LGCY_MVDBLK_sepool_11_entry_shift                                       (0)
#define  LGCY_MVDBLK_sepool_11_entry_mask                                        (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_11_entry(data)                                       (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_11_get_entry(data)                                   (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_12                                                   0x1800E730
#define  LGCY_MVDBLK_sepool_12_reg_addr                                          "0xB800E730"
#define  LGCY_MVDBLK_sepool_12_reg                                               0xB800E730
#define  LGCY_MVDBLK_sepool_12_inst_addr                                         "0x0043"
#define  set_LGCY_MVDBLK_sepool_12_reg(data)                                     (*((volatile unsigned int*)LGCY_MVDBLK_sepool_12_reg)=data)
#define  get_LGCY_MVDBLK_sepool_12_reg                                           (*((volatile unsigned int*)LGCY_MVDBLK_sepool_12_reg))
#define  LGCY_MVDBLK_sepool_12_entry_shift                                       (0)
#define  LGCY_MVDBLK_sepool_12_entry_mask                                        (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_12_entry(data)                                       (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_12_get_entry(data)                                   (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_13                                                   0x1800E734
#define  LGCY_MVDBLK_sepool_13_reg_addr                                          "0xB800E734"
#define  LGCY_MVDBLK_sepool_13_reg                                               0xB800E734
#define  LGCY_MVDBLK_sepool_13_inst_addr                                         "0x0044"
#define  set_LGCY_MVDBLK_sepool_13_reg(data)                                     (*((volatile unsigned int*)LGCY_MVDBLK_sepool_13_reg)=data)
#define  get_LGCY_MVDBLK_sepool_13_reg                                           (*((volatile unsigned int*)LGCY_MVDBLK_sepool_13_reg))
#define  LGCY_MVDBLK_sepool_13_entry_shift                                       (0)
#define  LGCY_MVDBLK_sepool_13_entry_mask                                        (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_13_entry(data)                                       (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_13_get_entry(data)                                   (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_14                                                   0x1800E738
#define  LGCY_MVDBLK_sepool_14_reg_addr                                          "0xB800E738"
#define  LGCY_MVDBLK_sepool_14_reg                                               0xB800E738
#define  LGCY_MVDBLK_sepool_14_inst_addr                                         "0x0045"
#define  set_LGCY_MVDBLK_sepool_14_reg(data)                                     (*((volatile unsigned int*)LGCY_MVDBLK_sepool_14_reg)=data)
#define  get_LGCY_MVDBLK_sepool_14_reg                                           (*((volatile unsigned int*)LGCY_MVDBLK_sepool_14_reg))
#define  LGCY_MVDBLK_sepool_14_entry_shift                                       (0)
#define  LGCY_MVDBLK_sepool_14_entry_mask                                        (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_14_entry(data)                                       (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_14_get_entry(data)                                   (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_sepool_15                                                   0x1800E73C
#define  LGCY_MVDBLK_sepool_15_reg_addr                                          "0xB800E73C"
#define  LGCY_MVDBLK_sepool_15_reg                                               0xB800E73C
#define  LGCY_MVDBLK_sepool_15_inst_addr                                         "0x0046"
#define  set_LGCY_MVDBLK_sepool_15_reg(data)                                     (*((volatile unsigned int*)LGCY_MVDBLK_sepool_15_reg)=data)
#define  get_LGCY_MVDBLK_sepool_15_reg                                           (*((volatile unsigned int*)LGCY_MVDBLK_sepool_15_reg))
#define  LGCY_MVDBLK_sepool_15_entry_shift                                       (0)
#define  LGCY_MVDBLK_sepool_15_entry_mask                                        (0xFFFFFFFF)
#define  LGCY_MVDBLK_sepool_15_entry(data)                                       (0xFFFFFFFF&(data))
#define  LGCY_MVDBLK_sepool_15_get_entry(data)                                   (0xFFFFFFFF&(data))

#define  LGCY_MVDBLK_h264base                                                    0x1800E6C0
#define  LGCY_MVDBLK_h264base_reg_addr                                           "0xB800E6C0"
#define  LGCY_MVDBLK_h264base_reg                                                0xB800E6C0
#define  LGCY_MVDBLK_h264base_inst_addr                                          "0x0047"
#define  set_LGCY_MVDBLK_h264base_reg(data)                                      (*((volatile unsigned int*)LGCY_MVDBLK_h264base_reg)=data)
#define  get_LGCY_MVDBLK_h264base_reg                                            (*((volatile unsigned int*)LGCY_MVDBLK_h264base_reg))
#define  LGCY_MVDBLK_h264base_setnhavail_shift                                   (0)
#define  LGCY_MVDBLK_h264base_setnhavail_mask                                    (0x00000001)
#define  LGCY_MVDBLK_h264base_setnhavail(data)                                   (0x00000001&(data))
#define  LGCY_MVDBLK_h264base_get_setnhavail(data)                               (0x00000001&(data))

#define  LGCY_MVDBLK_h264base1                                                   0x1800E6C4
#define  LGCY_MVDBLK_h264base1_reg_addr                                          "0xB800E6C4"
#define  LGCY_MVDBLK_h264base1_reg                                               0xB800E6C4
#define  LGCY_MVDBLK_h264base1_inst_addr                                         "0x0048"
#define  set_LGCY_MVDBLK_h264base1_reg(data)                                     (*((volatile unsigned int*)LGCY_MVDBLK_h264base1_reg)=data)
#define  get_LGCY_MVDBLK_h264base1_reg                                           (*((volatile unsigned int*)LGCY_MVDBLK_h264base1_reg))
#define  LGCY_MVDBLK_h264base1_leftavail_shift                                   (3)
#define  LGCY_MVDBLK_h264base1_topavail_shift                                    (2)
#define  LGCY_MVDBLK_h264base1_toprightavail_shift                               (1)
#define  LGCY_MVDBLK_h264base1_topleftavail_shift                                (0)
#define  LGCY_MVDBLK_h264base1_leftavail_mask                                    (0x00000008)
#define  LGCY_MVDBLK_h264base1_topavail_mask                                     (0x00000004)
#define  LGCY_MVDBLK_h264base1_toprightavail_mask                                (0x00000002)
#define  LGCY_MVDBLK_h264base1_topleftavail_mask                                 (0x00000001)
#define  LGCY_MVDBLK_h264base1_leftavail(data)                                   (0x00000008&((data)<<3))
#define  LGCY_MVDBLK_h264base1_topavail(data)                                    (0x00000004&((data)<<2))
#define  LGCY_MVDBLK_h264base1_toprightavail(data)                               (0x00000002&((data)<<1))
#define  LGCY_MVDBLK_h264base1_topleftavail(data)                                (0x00000001&(data))
#define  LGCY_MVDBLK_h264base1_get_leftavail(data)                               ((0x00000008&(data))>>3)
#define  LGCY_MVDBLK_h264base1_get_topavail(data)                                ((0x00000004&(data))>>2)
#define  LGCY_MVDBLK_h264base1_get_toprightavail(data)                           ((0x00000002&(data))>>1)
#define  LGCY_MVDBLK_h264base1_get_topleftavail(data)                            (0x00000001&(data))

#define  LGCY_MVDBLK_dbg                                                         0x1800E6C8
#define  LGCY_MVDBLK_dbg_reg_addr                                                "0xB800E6C8"
#define  LGCY_MVDBLK_dbg_reg                                                     0xB800E6C8
#define  LGCY_MVDBLK_dbg_inst_addr                                               "0x0049"
#define  set_LGCY_MVDBLK_dbg_reg(data)                                           (*((volatile unsigned int*)LGCY_MVDBLK_dbg_reg)=data)
#define  get_LGCY_MVDBLK_dbg_reg                                                 (*((volatile unsigned int*)LGCY_MVDBLK_dbg_reg))
#define  LGCY_MVDBLK_dbg_genpulse_shift                                          (31)
#define  LGCY_MVDBLK_dbg_piccount_shift                                          (16)
#define  LGCY_MVDBLK_dbg_dbgctrl_shift                                           (13)
#define  LGCY_MVDBLK_dbg_mbaddr_shift                                            (0)
#define  LGCY_MVDBLK_dbg_genpulse_mask                                           (0x80000000)
#define  LGCY_MVDBLK_dbg_piccount_mask                                           (0x7FFF0000)
#define  LGCY_MVDBLK_dbg_dbgctrl_mask                                            (0x0000E000)
#define  LGCY_MVDBLK_dbg_mbaddr_mask                                             (0x00001FFF)
#define  LGCY_MVDBLK_dbg_genpulse(data)                                          (0x80000000&((data)<<31))
#define  LGCY_MVDBLK_dbg_piccount(data)                                          (0x7FFF0000&((data)<<16))
#define  LGCY_MVDBLK_dbg_dbgctrl(data)                                           (0x0000E000&((data)<<13))
#define  LGCY_MVDBLK_dbg_mbaddr(data)                                            (0x00001FFF&(data))
#define  LGCY_MVDBLK_dbg_get_genpulse(data)                                      ((0x80000000&(data))>>31)
#define  LGCY_MVDBLK_dbg_get_piccount(data)                                      ((0x7FFF0000&(data))>>16)
#define  LGCY_MVDBLK_dbg_get_dbgctrl(data)                                       ((0x0000E000&(data))>>13)
#define  LGCY_MVDBLK_dbg_get_mbaddr(data)                                        (0x00001FFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LGCY_MVDBLK register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  pictype:3;
        RBus_UInt32  firstmbofpic:1;
        RBus_UInt32  firstmbofslice:1;
    };
}lgcy_mvdblk_comm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ldpxmemcount:16;
    };
}lgcy_mvdblk_comm1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dbgdumpcount:16;
    };
}lgcy_mvdblk_comm2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  setaddr:1;
        RBus_UInt32  mbaddry:7;
        RBus_UInt32  mbaddrx:7;
        RBus_UInt32  mbaddr:13;
    };
}lgcy_mvdblk_comm3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hwctrl:7;
        RBus_UInt32  softreset:1;
    };
}lgcy_mvdblk_comm4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbgwritebuf:32;
    };
}lgcy_mvdblk_comm5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dbgstorecount:16;
    };
}lgcy_mvdblk_comm6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  refpiclist10short:1;
        RBus_UInt32  botletopabsdiffpoc:1;
        RBus_UInt32  directspatial:1;
        RBus_UInt32  colpicstruct:2;
        RBus_UInt32  currpicstruct:2;
        RBus_UInt32  direct8x8inf:1;
    };
}lgcy_mvdblk_h264pic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  currfrmpoc:32;
    };
}lgcy_mvdblk_h264pic1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  currtoppoc:32;
    };
}lgcy_mvdblk_h264pic2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  currbotpoc:32;
    };
}lgcy_mvdblk_h264pic3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  comem8x8:4;
    };
}lgcy_mvdblk_h264co_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stcomemsaddr:32;
    };
}lgcy_mvdblk_h264co1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbaffaddr:1;
        RBus_UInt32  ldcomemsaddr:31;
    };
}lgcy_mvdblk_h264co2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enableldcomem1:1;
        RBus_UInt32  ldcomemsaddr1:31;
    };
}lgcy_mvdblk_h264co3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  autoldstoff:1;
        RBus_UInt32  initnhmemcmd:1;
        RBus_UInt32  ldnhmemcmd:1;
        RBus_UInt32  stnhmemcmd:1;
    };
}lgcy_mvdblk_h264nh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stnhmemsaddr:32;
    };
}lgcy_mvdblk_h264nh1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldnhmemsaddr:32;
    };
}lgcy_mvdblk_h264nh2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stsaddr:32;
    };
}lgcy_mvdblk_hevcsao_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldsaddr:32;
    };
}lgcy_mvdblk_hevcsao1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  list1size:5;
        RBus_UInt32  list0size:5;
    };
}lgcy_mvdblk_h264px_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  frmpocaddrl0:16;
    };
}lgcy_mvdblk_h264px1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  toppocaddrl0:16;
    };
}lgcy_mvdblk_h264px2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  botpocaddrl0:16;
    };
}lgcy_mvdblk_h264px3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  frmpocaddrl1:16;
    };
}lgcy_mvdblk_h264px4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  toppocaddrl1:16;
    };
}lgcy_mvdblk_h264px5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  botpocaddrl1:16;
    };
}lgcy_mvdblk_h264px6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  picinfoaddr:16;
    };
}lgcy_mvdblk_h264px7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  reffield:1;
        RBus_UInt32  fastuvmc:1;
        RBus_UInt32  scalefactor:11;
    };
}lgcy_mvdblk_vc1pic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  scale_fw:8;
        RBus_UInt32  scale1_fw:12;
        RBus_UInt32  scale2_fw:8;
    };
}lgcy_mvdblk_vc1pic1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  scaleupopp_fw:1;
        RBus_UInt32  scalezone1x_fw:6;
        RBus_UInt32  scalezone1y_fw:4;
        RBus_UInt32  zone1offsetx_fw:6;
        RBus_UInt32  zone1offsety_fw:4;
    };
}lgcy_mvdblk_vc1pic2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  scale_bw:8;
        RBus_UInt32  scale1_bw:12;
        RBus_UInt32  scale2_bw:8;
    };
}lgcy_mvdblk_vc1pic3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  scaleupopp_bw:1;
        RBus_UInt32  scalezone1x_bw:6;
        RBus_UInt32  scalezone1y_bw:4;
        RBus_UInt32  zone1offsetx_bw:6;
        RBus_UInt32  zone1offsety_bw:4;
    };
}lgcy_mvdblk_vc1pic4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  rangey:12;
        RBus_UInt32  rangex:13;
    };
}lgcy_mvdblk_vc1pic5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  aecenable:1;
        RBus_UInt32  pfieldskip:1;
        RBus_UInt32  bfieldenhanced:1;
        RBus_UInt32  picrefflag:1;
        RBus_UInt32  picstructure:1;
    };
}lgcy_mvdblk_avspic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  blockdist0:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  blockdist1:9;
    };
}lgcy_mvdblk_avspic1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  blockdist2:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  blockdist3:9;
    };
}lgcy_mvdblk_avspic2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b16384divitrp0:16;
        RBus_UInt32  b16384divitrp1:16;
    };
}lgcy_mvdblk_avspic3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b16384divitrp2:16;
        RBus_UInt32  b16384divitrp3:16;
    };
}lgcy_mvdblk_avspic4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  itrb0:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  itrb1:9;
    };
}lgcy_mvdblk_avspic5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  itrb2:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  itrb3:9;
    };
}lgcy_mvdblk_avspic6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  itrd:9;
    };
}lgcy_mvdblk_avspic7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iratio0:32;
    };
}lgcy_mvdblk_rm89pic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iratio1:32;
    };
}lgcy_mvdblk_rm89pic1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hix:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  lox:14;
    };
}lgcy_mvdblk_rm89direct_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hiy:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  loy:14;
    };
}lgcy_mvdblk_rm89direct1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hicx:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  locx:14;
    };
}lgcy_mvdblk_rm89direct2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hicy:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  locy:14;
    };
}lgcy_mvdblk_rm89direct3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  zeromvd:1;
    };
}lgcy_mvdblk_rm89pic2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hix_4v:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  lox_4v:14;
    };
}lgcy_mvdblk_rm89direct4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hiy_4v:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  loy_4v:14;
    };
}lgcy_mvdblk_rm89direct5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hicx_4v:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  locx_4v:14;
    };
}lgcy_mvdblk_rm89direct6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hicy_4v:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  locy_4v:14;
    };
}lgcy_mvdblk_rm89direct7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  entry:32;
    };
}lgcy_mvdblk_sepool_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  setnhavail:1;
    };
}lgcy_mvdblk_h264base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  leftavail:1;
        RBus_UInt32  topavail:1;
        RBus_UInt32  toprightavail:1;
        RBus_UInt32  topleftavail:1;
    };
}lgcy_mvdblk_h264base1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  genpulse:1;
        RBus_UInt32  piccount:15;
        RBus_UInt32  dbgctrl:3;
        RBus_UInt32  mbaddr:13;
    };
}lgcy_mvdblk_dbg_RBUS;

#else //apply LITTLE_ENDIAN

//======LGCY_MVDBLK register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  firstmbofslice:1;
        RBus_UInt32  firstmbofpic:1;
        RBus_UInt32  pictype:3;
        RBus_UInt32  res1:27;
    };
}lgcy_mvdblk_comm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldpxmemcount:16;
        RBus_UInt32  res1:16;
    };
}lgcy_mvdblk_comm1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbgdumpcount:16;
        RBus_UInt32  res1:16;
    };
}lgcy_mvdblk_comm2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbaddr:13;
        RBus_UInt32  mbaddrx:7;
        RBus_UInt32  mbaddry:7;
        RBus_UInt32  setaddr:1;
        RBus_UInt32  res1:4;
    };
}lgcy_mvdblk_comm3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  softreset:1;
        RBus_UInt32  hwctrl:7;
        RBus_UInt32  res1:24;
    };
}lgcy_mvdblk_comm4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbgwritebuf:32;
    };
}lgcy_mvdblk_comm5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbgstorecount:16;
        RBus_UInt32  res1:16;
    };
}lgcy_mvdblk_comm6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  direct8x8inf:1;
        RBus_UInt32  currpicstruct:2;
        RBus_UInt32  colpicstruct:2;
        RBus_UInt32  directspatial:1;
        RBus_UInt32  botletopabsdiffpoc:1;
        RBus_UInt32  refpiclist10short:1;
        RBus_UInt32  res1:24;
    };
}lgcy_mvdblk_h264pic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  currfrmpoc:32;
    };
}lgcy_mvdblk_h264pic1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  currtoppoc:32;
    };
}lgcy_mvdblk_h264pic2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  currbotpoc:32;
    };
}lgcy_mvdblk_h264pic3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comem8x8:4;
        RBus_UInt32  res1:28;
    };
}lgcy_mvdblk_h264co_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stcomemsaddr:32;
    };
}lgcy_mvdblk_h264co1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldcomemsaddr:31;
        RBus_UInt32  mbaffaddr:1;
    };
}lgcy_mvdblk_h264co2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldcomemsaddr1:31;
        RBus_UInt32  enableldcomem1:1;
    };
}lgcy_mvdblk_h264co3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stnhmemcmd:1;
        RBus_UInt32  ldnhmemcmd:1;
        RBus_UInt32  initnhmemcmd:1;
        RBus_UInt32  autoldstoff:1;
        RBus_UInt32  res1:28;
    };
}lgcy_mvdblk_h264nh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stnhmemsaddr:32;
    };
}lgcy_mvdblk_h264nh1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldnhmemsaddr:32;
    };
}lgcy_mvdblk_h264nh2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stsaddr:32;
    };
}lgcy_mvdblk_hevcsao_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldsaddr:32;
    };
}lgcy_mvdblk_hevcsao1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  list0size:5;
        RBus_UInt32  list1size:5;
        RBus_UInt32  res1:22;
    };
}lgcy_mvdblk_h264px_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frmpocaddrl0:16;
        RBus_UInt32  res1:16;
    };
}lgcy_mvdblk_h264px1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  toppocaddrl0:16;
        RBus_UInt32  res1:16;
    };
}lgcy_mvdblk_h264px2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  botpocaddrl0:16;
        RBus_UInt32  res1:16;
    };
}lgcy_mvdblk_h264px3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frmpocaddrl1:16;
        RBus_UInt32  res1:16;
    };
}lgcy_mvdblk_h264px4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  toppocaddrl1:16;
        RBus_UInt32  res1:16;
    };
}lgcy_mvdblk_h264px5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  botpocaddrl1:16;
        RBus_UInt32  res1:16;
    };
}lgcy_mvdblk_h264px6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  picinfoaddr:16;
        RBus_UInt32  res1:16;
    };
}lgcy_mvdblk_h264px7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scalefactor:11;
        RBus_UInt32  fastuvmc:1;
        RBus_UInt32  reffield:1;
        RBus_UInt32  res1:19;
    };
}lgcy_mvdblk_vc1pic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scale2_fw:8;
        RBus_UInt32  scale1_fw:12;
        RBus_UInt32  scale_fw:8;
        RBus_UInt32  res1:4;
    };
}lgcy_mvdblk_vc1pic1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zone1offsety_fw:4;
        RBus_UInt32  zone1offsetx_fw:6;
        RBus_UInt32  scalezone1y_fw:4;
        RBus_UInt32  scalezone1x_fw:6;
        RBus_UInt32  scaleupopp_fw:1;
        RBus_UInt32  res1:11;
    };
}lgcy_mvdblk_vc1pic2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scale2_bw:8;
        RBus_UInt32  scale1_bw:12;
        RBus_UInt32  scale_bw:8;
        RBus_UInt32  res1:4;
    };
}lgcy_mvdblk_vc1pic3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zone1offsety_bw:4;
        RBus_UInt32  zone1offsetx_bw:6;
        RBus_UInt32  scalezone1y_bw:4;
        RBus_UInt32  scalezone1x_bw:6;
        RBus_UInt32  scaleupopp_bw:1;
        RBus_UInt32  res1:11;
    };
}lgcy_mvdblk_vc1pic4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rangex:13;
        RBus_UInt32  rangey:12;
        RBus_UInt32  res1:7;
    };
}lgcy_mvdblk_vc1pic5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  picstructure:1;
        RBus_UInt32  picrefflag:1;
        RBus_UInt32  bfieldenhanced:1;
        RBus_UInt32  pfieldskip:1;
        RBus_UInt32  aecenable:1;
        RBus_UInt32  res1:27;
    };
}lgcy_mvdblk_avspic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blockdist1:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  blockdist0:9;
        RBus_UInt32  res2:7;
    };
}lgcy_mvdblk_avspic1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blockdist3:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  blockdist2:9;
        RBus_UInt32  res2:7;
    };
}lgcy_mvdblk_avspic2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b16384divitrp1:16;
        RBus_UInt32  b16384divitrp0:16;
    };
}lgcy_mvdblk_avspic3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b16384divitrp3:16;
        RBus_UInt32  b16384divitrp2:16;
    };
}lgcy_mvdblk_avspic4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  itrb1:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  itrb0:9;
        RBus_UInt32  res2:7;
    };
}lgcy_mvdblk_avspic5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  itrb3:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  itrb2:9;
        RBus_UInt32  res2:7;
    };
}lgcy_mvdblk_avspic6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  itrd:9;
        RBus_UInt32  res1:23;
    };
}lgcy_mvdblk_avspic7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iratio0:32;
    };
}lgcy_mvdblk_rm89pic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iratio1:32;
    };
}lgcy_mvdblk_rm89pic1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lox:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hix:14;
        RBus_UInt32  res2:2;
    };
}lgcy_mvdblk_rm89direct_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  loy:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hiy:14;
        RBus_UInt32  res2:2;
    };
}lgcy_mvdblk_rm89direct1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  locx:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hicx:14;
        RBus_UInt32  res2:2;
    };
}lgcy_mvdblk_rm89direct2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  locy:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hicy:14;
        RBus_UInt32  res2:2;
    };
}lgcy_mvdblk_rm89direct3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zeromvd:1;
        RBus_UInt32  res1:31;
    };
}lgcy_mvdblk_rm89pic2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lox_4v:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hix_4v:14;
        RBus_UInt32  res2:2;
    };
}lgcy_mvdblk_rm89direct4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  loy_4v:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hiy_4v:14;
        RBus_UInt32  res2:2;
    };
}lgcy_mvdblk_rm89direct5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  locx_4v:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hicx_4v:14;
        RBus_UInt32  res2:2;
    };
}lgcy_mvdblk_rm89direct6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  locy_4v:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hicy_4v:14;
        RBus_UInt32  res2:2;
    };
}lgcy_mvdblk_rm89direct7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  entry:32;
    };
}lgcy_mvdblk_sepool_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  setnhavail:1;
        RBus_UInt32  res1:31;
    };
}lgcy_mvdblk_h264base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  topleftavail:1;
        RBus_UInt32  toprightavail:1;
        RBus_UInt32  topavail:1;
        RBus_UInt32  leftavail:1;
        RBus_UInt32  res1:28;
    };
}lgcy_mvdblk_h264base1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbaddr:13;
        RBus_UInt32  dbgctrl:3;
        RBus_UInt32  piccount:15;
        RBus_UInt32  genpulse:1;
    };
}lgcy_mvdblk_dbg_RBUS;




#endif 


#endif 
