/**
* @file rbusPLL27X_REGReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PLL27X_REG_REG_H_
#define _RBUS_PLL27X_REG_REG_H_

#include "rbus_types.h"



//  PLL27X_REG Register Address
#define  PLL27X_REG_SYS_PLL_512FS_1                                              0x180004B0
#define  PLL27X_REG_SYS_PLL_512FS_1_reg_addr                                     "0xB80004B0"
#define  PLL27X_REG_SYS_PLL_512FS_1_reg                                          0xB80004B0
#define  PLL27X_REG_SYS_PLL_512FS_1_inst_addr                                    "0x0000"
#define  set_PLL27X_REG_SYS_PLL_512FS_1_reg(data)                                (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_512FS_1_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_512FS_1_reg                                      (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_512FS_1_reg))
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_n_shift                             (28)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_m_shift                             (20)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_bpn_shift                           (19)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_bps_shift                           (18)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_cs_shift                            (16)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_ip_shift                            (12)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_s_shift                             (9)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_q_shift                             (6)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_rs_shift                            (3)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_tst_shift                           (2)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_wdrst_shift                         (1)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_wdset_shift                         (0)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_n_mask                              (0x70000000)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_m_mask                              (0x07F00000)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_bpn_mask                            (0x00080000)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_bps_mask                            (0x00040000)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_cs_mask                             (0x00030000)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_ip_mask                             (0x00007000)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_s_mask                              (0x00000E00)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_q_mask                              (0x000001C0)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_rs_mask                             (0x00000038)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_tst_mask                            (0x00000004)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_wdrst_mask                          (0x00000002)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_wdset_mask                          (0x00000001)
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_n(data)                             (0x70000000&((data)<<28))
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_m(data)                             (0x07F00000&((data)<<20))
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_bpn(data)                           (0x00080000&((data)<<19))
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_bps(data)                           (0x00040000&((data)<<18))
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_cs(data)                            (0x00030000&((data)<<16))
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_ip(data)                            (0x00007000&((data)<<12))
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_s(data)                             (0x00000E00&((data)<<9))
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_q(data)                             (0x000001C0&((data)<<6))
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_rs(data)                            (0x00000038&((data)<<3))
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_tst(data)                           (0x00000004&((data)<<2))
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_wdrst(data)                         (0x00000002&((data)<<1))
#define  PLL27X_REG_SYS_PLL_512FS_1_pll512fs_wdset(data)                         (0x00000001&(data))
#define  PLL27X_REG_SYS_PLL_512FS_1_get_pll512fs_n(data)                         ((0x70000000&(data))>>28)
#define  PLL27X_REG_SYS_PLL_512FS_1_get_pll512fs_m(data)                         ((0x07F00000&(data))>>20)
#define  PLL27X_REG_SYS_PLL_512FS_1_get_pll512fs_bpn(data)                       ((0x00080000&(data))>>19)
#define  PLL27X_REG_SYS_PLL_512FS_1_get_pll512fs_bps(data)                       ((0x00040000&(data))>>18)
#define  PLL27X_REG_SYS_PLL_512FS_1_get_pll512fs_cs(data)                        ((0x00030000&(data))>>16)
#define  PLL27X_REG_SYS_PLL_512FS_1_get_pll512fs_ip(data)                        ((0x00007000&(data))>>12)
#define  PLL27X_REG_SYS_PLL_512FS_1_get_pll512fs_s(data)                         ((0x00000E00&(data))>>9)
#define  PLL27X_REG_SYS_PLL_512FS_1_get_pll512fs_q(data)                         ((0x000001C0&(data))>>6)
#define  PLL27X_REG_SYS_PLL_512FS_1_get_pll512fs_rs(data)                        ((0x00000038&(data))>>3)
#define  PLL27X_REG_SYS_PLL_512FS_1_get_pll512fs_tst(data)                       ((0x00000004&(data))>>2)
#define  PLL27X_REG_SYS_PLL_512FS_1_get_pll512fs_wdrst(data)                     ((0x00000002&(data))>>1)
#define  PLL27X_REG_SYS_PLL_512FS_1_get_pll512fs_wdset(data)                     (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_512FS_2                                              0x180004B4
#define  PLL27X_REG_SYS_PLL_512FS_2_reg_addr                                     "0xB80004B4"
#define  PLL27X_REG_SYS_PLL_512FS_2_reg                                          0xB80004B4
#define  PLL27X_REG_SYS_PLL_512FS_2_inst_addr                                    "0x0001"
#define  set_PLL27X_REG_SYS_PLL_512FS_2_reg(data)                                (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_512FS_2_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_512FS_2_reg                                      (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_512FS_2_reg))
#define  PLL27X_REG_SYS_PLL_512FS_2_pll512fs_oeb_shift                           (2)
#define  PLL27X_REG_SYS_PLL_512FS_2_pll512fs_rstb_shift                          (1)
#define  PLL27X_REG_SYS_PLL_512FS_2_pll512fs_pow_shift                           (0)
#define  PLL27X_REG_SYS_PLL_512FS_2_pll512fs_oeb_mask                            (0x00000004)
#define  PLL27X_REG_SYS_PLL_512FS_2_pll512fs_rstb_mask                           (0x00000002)
#define  PLL27X_REG_SYS_PLL_512FS_2_pll512fs_pow_mask                            (0x00000001)
#define  PLL27X_REG_SYS_PLL_512FS_2_pll512fs_oeb(data)                           (0x00000004&((data)<<2))
#define  PLL27X_REG_SYS_PLL_512FS_2_pll512fs_rstb(data)                          (0x00000002&((data)<<1))
#define  PLL27X_REG_SYS_PLL_512FS_2_pll512fs_pow(data)                           (0x00000001&(data))
#define  PLL27X_REG_SYS_PLL_512FS_2_get_pll512fs_oeb(data)                       ((0x00000004&(data))>>2)
#define  PLL27X_REG_SYS_PLL_512FS_2_get_pll512fs_rstb(data)                      ((0x00000002&(data))>>1)
#define  PLL27X_REG_SYS_PLL_512FS_2_get_pll512fs_pow(data)                       (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_512FS2_1                                             0x180004B8
#define  PLL27X_REG_SYS_PLL_512FS2_1_reg_addr                                    "0xB80004B8"
#define  PLL27X_REG_SYS_PLL_512FS2_1_reg                                         0xB80004B8
#define  PLL27X_REG_SYS_PLL_512FS2_1_inst_addr                                   "0x0002"
#define  set_PLL27X_REG_SYS_PLL_512FS2_1_reg(data)                               (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_512FS2_1_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_512FS2_1_reg                                     (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_512FS2_1_reg))
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_n2_shift                           (28)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_m2_shift                           (20)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_bpn2_shift                         (19)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_bps2_shift                         (18)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_cs2_shift                          (16)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_ip2_shift                          (12)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_s2_shift                           (9)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_q2_shift                           (6)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_rs2_shift                          (3)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_tst2_shift                         (2)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_wdrst2_shift                       (1)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_wdset2_shift                       (0)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_n2_mask                            (0x70000000)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_m2_mask                            (0x07F00000)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_bpn2_mask                          (0x00080000)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_bps2_mask                          (0x00040000)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_cs2_mask                           (0x00030000)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_ip2_mask                           (0x00007000)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_s2_mask                            (0x00000E00)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_q2_mask                            (0x000001C0)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_rs2_mask                           (0x00000038)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_tst2_mask                          (0x00000004)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_wdrst2_mask                        (0x00000002)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_wdset2_mask                        (0x00000001)
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_n2(data)                           (0x70000000&((data)<<28))
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_m2(data)                           (0x07F00000&((data)<<20))
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_bpn2(data)                         (0x00080000&((data)<<19))
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_bps2(data)                         (0x00040000&((data)<<18))
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_cs2(data)                          (0x00030000&((data)<<16))
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_ip2(data)                          (0x00007000&((data)<<12))
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_s2(data)                           (0x00000E00&((data)<<9))
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_q2(data)                           (0x000001C0&((data)<<6))
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_rs2(data)                          (0x00000038&((data)<<3))
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_tst2(data)                         (0x00000004&((data)<<2))
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_wdrst2(data)                       (0x00000002&((data)<<1))
#define  PLL27X_REG_SYS_PLL_512FS2_1_pll512fs_wdset2(data)                       (0x00000001&(data))
#define  PLL27X_REG_SYS_PLL_512FS2_1_get_pll512fs_n2(data)                       ((0x70000000&(data))>>28)
#define  PLL27X_REG_SYS_PLL_512FS2_1_get_pll512fs_m2(data)                       ((0x07F00000&(data))>>20)
#define  PLL27X_REG_SYS_PLL_512FS2_1_get_pll512fs_bpn2(data)                     ((0x00080000&(data))>>19)
#define  PLL27X_REG_SYS_PLL_512FS2_1_get_pll512fs_bps2(data)                     ((0x00040000&(data))>>18)
#define  PLL27X_REG_SYS_PLL_512FS2_1_get_pll512fs_cs2(data)                      ((0x00030000&(data))>>16)
#define  PLL27X_REG_SYS_PLL_512FS2_1_get_pll512fs_ip2(data)                      ((0x00007000&(data))>>12)
#define  PLL27X_REG_SYS_PLL_512FS2_1_get_pll512fs_s2(data)                       ((0x00000E00&(data))>>9)
#define  PLL27X_REG_SYS_PLL_512FS2_1_get_pll512fs_q2(data)                       ((0x000001C0&(data))>>6)
#define  PLL27X_REG_SYS_PLL_512FS2_1_get_pll512fs_rs2(data)                      ((0x00000038&(data))>>3)
#define  PLL27X_REG_SYS_PLL_512FS2_1_get_pll512fs_tst2(data)                     ((0x00000004&(data))>>2)
#define  PLL27X_REG_SYS_PLL_512FS2_1_get_pll512fs_wdrst2(data)                   ((0x00000002&(data))>>1)
#define  PLL27X_REG_SYS_PLL_512FS2_1_get_pll512fs_wdset2(data)                   (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_512FS2_2                                             0x180004BC
#define  PLL27X_REG_SYS_PLL_512FS2_2_reg_addr                                    "0xB80004BC"
#define  PLL27X_REG_SYS_PLL_512FS2_2_reg                                         0xB80004BC
#define  PLL27X_REG_SYS_PLL_512FS2_2_inst_addr                                   "0x0003"
#define  set_PLL27X_REG_SYS_PLL_512FS2_2_reg(data)                               (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_512FS2_2_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_512FS2_2_reg                                     (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_512FS2_2_reg))
#define  PLL27X_REG_SYS_PLL_512FS2_2_pll512fs_oeb2_shift                         (2)
#define  PLL27X_REG_SYS_PLL_512FS2_2_pll512fs_rstb2_shift                        (1)
#define  PLL27X_REG_SYS_PLL_512FS2_2_pll512fs_pow2_shift                         (0)
#define  PLL27X_REG_SYS_PLL_512FS2_2_pll512fs_oeb2_mask                          (0x00000004)
#define  PLL27X_REG_SYS_PLL_512FS2_2_pll512fs_rstb2_mask                         (0x00000002)
#define  PLL27X_REG_SYS_PLL_512FS2_2_pll512fs_pow2_mask                          (0x00000001)
#define  PLL27X_REG_SYS_PLL_512FS2_2_pll512fs_oeb2(data)                         (0x00000004&((data)<<2))
#define  PLL27X_REG_SYS_PLL_512FS2_2_pll512fs_rstb2(data)                        (0x00000002&((data)<<1))
#define  PLL27X_REG_SYS_PLL_512FS2_2_pll512fs_pow2(data)                         (0x00000001&(data))
#define  PLL27X_REG_SYS_PLL_512FS2_2_get_pll512fs_oeb2(data)                     ((0x00000004&(data))>>2)
#define  PLL27X_REG_SYS_PLL_512FS2_2_get_pll512fs_rstb2(data)                    ((0x00000002&(data))>>1)
#define  PLL27X_REG_SYS_PLL_512FS2_2_get_pll512fs_pow2(data)                     (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_DIF1                                                 0x180004C0
#define  PLL27X_REG_SYS_PLL_DIF1_reg_addr                                        "0xB80004C0"
#define  PLL27X_REG_SYS_PLL_DIF1_reg                                             0xB80004C0
#define  PLL27X_REG_SYS_PLL_DIF1_inst_addr                                       "0x0004"
#define  set_PLL27X_REG_SYS_PLL_DIF1_reg(data)                                   (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DIF1_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_DIF1_reg                                         (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DIF1_reg))
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_n_shift                                  (28)
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_m_shift                                  (20)
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_ip_shift                                 (16)
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_lf_rs_shift                              (14)
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_lf_cp_shift                              (12)
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_n_mask                                   (0x30000000)
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_m_mask                                   (0x07F00000)
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_ip_mask                                  (0x00070000)
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_lf_rs_mask                               (0x0000C000)
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_lf_cp_mask                               (0x00003000)
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_n(data)                                  (0x30000000&((data)<<28))
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_m(data)                                  (0x07F00000&((data)<<20))
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_ip(data)                                 (0x00070000&((data)<<16))
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_lf_rs(data)                              (0x0000C000&((data)<<14))
#define  PLL27X_REG_SYS_PLL_DIF1_plldif_lf_cp(data)                              (0x00003000&((data)<<12))
#define  PLL27X_REG_SYS_PLL_DIF1_get_plldif_n(data)                              ((0x30000000&(data))>>28)
#define  PLL27X_REG_SYS_PLL_DIF1_get_plldif_m(data)                              ((0x07F00000&(data))>>20)
#define  PLL27X_REG_SYS_PLL_DIF1_get_plldif_ip(data)                             ((0x00070000&(data))>>16)
#define  PLL27X_REG_SYS_PLL_DIF1_get_plldif_lf_rs(data)                          ((0x0000C000&(data))>>14)
#define  PLL27X_REG_SYS_PLL_DIF1_get_plldif_lf_cp(data)                          ((0x00003000&(data))>>12)

#define  PLL27X_REG_SYS_PLL_DIF2                                                 0x180004C4
#define  PLL27X_REG_SYS_PLL_DIF2_reg_addr                                        "0xB80004C4"
#define  PLL27X_REG_SYS_PLL_DIF2_reg                                             0xB80004C4
#define  PLL27X_REG_SYS_PLL_DIF2_inst_addr                                       "0x0005"
#define  set_PLL27X_REG_SYS_PLL_DIF2_reg(data)                                   (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DIF2_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_DIF2_reg                                         (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DIF2_reg))
#define  PLL27X_REG_SYS_PLL_DIF2_plldif_dvbs2_en_shift                           (12)
#define  PLL27X_REG_SYS_PLL_DIF2_plldif_wdmode_shift                             (8)
#define  PLL27X_REG_SYS_PLL_DIF2_plldif_divdig_sel_shift                         (4)
#define  PLL27X_REG_SYS_PLL_DIF2_plldif_divadc_sel_shift                         (0)
#define  PLL27X_REG_SYS_PLL_DIF2_plldif_dvbs2_en_mask                            (0x00001000)
#define  PLL27X_REG_SYS_PLL_DIF2_plldif_wdmode_mask                              (0x00000300)
#define  PLL27X_REG_SYS_PLL_DIF2_plldif_divdig_sel_mask                          (0x00000070)
#define  PLL27X_REG_SYS_PLL_DIF2_plldif_divadc_sel_mask                          (0x00000007)
#define  PLL27X_REG_SYS_PLL_DIF2_plldif_dvbs2_en(data)                           (0x00001000&((data)<<12))
#define  PLL27X_REG_SYS_PLL_DIF2_plldif_wdmode(data)                             (0x00000300&((data)<<8))
#define  PLL27X_REG_SYS_PLL_DIF2_plldif_divdig_sel(data)                         (0x00000070&((data)<<4))
#define  PLL27X_REG_SYS_PLL_DIF2_plldif_divadc_sel(data)                         (0x00000007&(data))
#define  PLL27X_REG_SYS_PLL_DIF2_get_plldif_dvbs2_en(data)                       ((0x00001000&(data))>>12)
#define  PLL27X_REG_SYS_PLL_DIF2_get_plldif_wdmode(data)                         ((0x00000300&(data))>>8)
#define  PLL27X_REG_SYS_PLL_DIF2_get_plldif_divdig_sel(data)                     ((0x00000070&(data))>>4)
#define  PLL27X_REG_SYS_PLL_DIF2_get_plldif_divadc_sel(data)                     (0x00000007&(data))

#define  PLL27X_REG_SYS_PLL_DIF3                                                 0x180004C8
#define  PLL27X_REG_SYS_PLL_DIF3_reg_addr                                        "0xB80004C8"
#define  PLL27X_REG_SYS_PLL_DIF3_reg                                             0xB80004C8
#define  PLL27X_REG_SYS_PLL_DIF3_inst_addr                                       "0x0006"
#define  set_PLL27X_REG_SYS_PLL_DIF3_reg(data)                                   (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DIF3_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_DIF3_reg                                         (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DIF3_reg))
#define  PLL27X_REG_SYS_PLL_DIF3_hdic_dtmb_dig_mux_shift                         (31)
#define  PLL27X_REG_SYS_PLL_DIF3_plldif_vco_rstb_shift                           (2)
#define  PLL27X_REG_SYS_PLL_DIF3_plldif_rstb_shift                               (1)
#define  PLL27X_REG_SYS_PLL_DIF3_plldif_pow_shift                                (0)
#define  PLL27X_REG_SYS_PLL_DIF3_hdic_dtmb_dig_mux_mask                          (0x80000000)
#define  PLL27X_REG_SYS_PLL_DIF3_plldif_vco_rstb_mask                            (0x00000004)
#define  PLL27X_REG_SYS_PLL_DIF3_plldif_rstb_mask                                (0x00000002)
#define  PLL27X_REG_SYS_PLL_DIF3_plldif_pow_mask                                 (0x00000001)
#define  PLL27X_REG_SYS_PLL_DIF3_hdic_dtmb_dig_mux(data)                         (0x80000000&((data)<<31))
#define  PLL27X_REG_SYS_PLL_DIF3_plldif_vco_rstb(data)                           (0x00000004&((data)<<2))
#define  PLL27X_REG_SYS_PLL_DIF3_plldif_rstb(data)                               (0x00000002&((data)<<1))
#define  PLL27X_REG_SYS_PLL_DIF3_plldif_pow(data)                                (0x00000001&(data))
#define  PLL27X_REG_SYS_PLL_DIF3_get_hdic_dtmb_dig_mux(data)                     ((0x80000000&(data))>>31)
#define  PLL27X_REG_SYS_PLL_DIF3_get_plldif_vco_rstb(data)                       ((0x00000004&(data))>>2)
#define  PLL27X_REG_SYS_PLL_DIF3_get_plldif_rstb(data)                           ((0x00000002&(data))>>1)
#define  PLL27X_REG_SYS_PLL_DIF3_get_plldif_pow(data)                            (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_27X1                                                 0x180004D0
#define  PLL27X_REG_SYS_PLL_27X1_reg_addr                                        "0xB80004D0"
#define  PLL27X_REG_SYS_PLL_27X1_reg                                             0xB80004D0
#define  PLL27X_REG_SYS_PLL_27X1_inst_addr                                       "0x0007"
#define  set_PLL27X_REG_SYS_PLL_27X1_reg(data)                                   (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_27X1_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_27X1_reg                                         (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_27X1_reg))
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_wdmode_shift                             (28)
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_lf_cp_shift                              (24)
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_lf_rs_shift                              (20)
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_ip_shift                                 (16)
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_n_shift                                  (8)
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_m_shift                                  (0)
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_wdmode_mask                              (0x30000000)
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_lf_cp_mask                               (0x03000000)
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_lf_rs_mask                               (0x00300000)
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_ip_mask                                  (0x00070000)
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_n_mask                                   (0x00000300)
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_m_mask                                   (0x0000007F)
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_wdmode(data)                             (0x30000000&((data)<<28))
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_lf_cp(data)                              (0x03000000&((data)<<24))
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_lf_rs(data)                              (0x00300000&((data)<<20))
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_ip(data)                                 (0x00070000&((data)<<16))
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_n(data)                                  (0x00000300&((data)<<8))
#define  PLL27X_REG_SYS_PLL_27X1_pll27x_m(data)                                  (0x0000007F&(data))
#define  PLL27X_REG_SYS_PLL_27X1_get_pll27x_wdmode(data)                         ((0x30000000&(data))>>28)
#define  PLL27X_REG_SYS_PLL_27X1_get_pll27x_lf_cp(data)                          ((0x03000000&(data))>>24)
#define  PLL27X_REG_SYS_PLL_27X1_get_pll27x_lf_rs(data)                          ((0x00300000&(data))>>20)
#define  PLL27X_REG_SYS_PLL_27X1_get_pll27x_ip(data)                             ((0x00070000&(data))>>16)
#define  PLL27X_REG_SYS_PLL_27X1_get_pll27x_n(data)                              ((0x00000300&(data))>>8)
#define  PLL27X_REG_SYS_PLL_27X1_get_pll27x_m(data)                              (0x0000007F&(data))

#define  PLL27X_REG_SYS_PLL_27X2                                                 0x180004D4
#define  PLL27X_REG_SYS_PLL_27X2_reg_addr                                        "0xB80004D4"
#define  PLL27X_REG_SYS_PLL_27X2_reg                                             0xB80004D4
#define  PLL27X_REG_SYS_PLL_27X2_inst_addr                                       "0x0008"
#define  set_PLL27X_REG_SYS_PLL_27X2_reg(data)                                   (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_27X2_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_27X2_reg                                         (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_27X2_reg))
#define  PLL27X_REG_SYS_PLL_27X2_xi_cap_shift                                    (28)
#define  PLL27X_REG_SYS_PLL_27X2_xo_cap_shift                                    (24)
#define  PLL27X_REG_SYS_PLL_27X2_vdd11_pad_sel_shift                             (21)
#define  PLL27X_REG_SYS_PLL_27X2_pll_ldo_xtal_sel_shift                          (19)
#define  PLL27X_REG_SYS_PLL_27X2_pll_xixo_load_shift                             (18)
#define  PLL27X_REG_SYS_PLL_27X2_pll_xixo_drive_sel_shift                        (16)
#define  PLL27X_REG_SYS_PLL_27X2_pad_sel_en_shift                                (15)
#define  PLL27X_REG_SYS_PLL_27X2_pll_pow_ldo11v_shift                            (14)
#define  PLL27X_REG_SYS_PLL_27X2_pll_ldo11v_sel_shift                            (12)
#define  PLL27X_REG_SYS_PLL_27X2_pll_pow_ldo_shift                               (10)
#define  PLL27X_REG_SYS_PLL_27X2_pll_ldo_sel_shift                               (8)
#define  PLL27X_REG_SYS_PLL_27X2_pll27x_ps_54m_delay_shift                       (4)
#define  PLL27X_REG_SYS_PLL_27X2_pll27x_ps_psel_pulse_w_shift                    (1)
#define  PLL27X_REG_SYS_PLL_27X2_pll27x_ps_duty_sel_shift                        (0)
#define  PLL27X_REG_SYS_PLL_27X2_xi_cap_mask                                     (0xF0000000)
#define  PLL27X_REG_SYS_PLL_27X2_xo_cap_mask                                     (0x0F000000)
#define  PLL27X_REG_SYS_PLL_27X2_vdd11_pad_sel_mask                              (0x00E00000)
#define  PLL27X_REG_SYS_PLL_27X2_pll_ldo_xtal_sel_mask                           (0x00180000)
#define  PLL27X_REG_SYS_PLL_27X2_pll_xixo_load_mask                              (0x00040000)
#define  PLL27X_REG_SYS_PLL_27X2_pll_xixo_drive_sel_mask                         (0x00030000)
#define  PLL27X_REG_SYS_PLL_27X2_pad_sel_en_mask                                 (0x00008000)
#define  PLL27X_REG_SYS_PLL_27X2_pll_pow_ldo11v_mask                             (0x00004000)
#define  PLL27X_REG_SYS_PLL_27X2_pll_ldo11v_sel_mask                             (0x00003000)
#define  PLL27X_REG_SYS_PLL_27X2_pll_pow_ldo_mask                                (0x00000400)
#define  PLL27X_REG_SYS_PLL_27X2_pll_ldo_sel_mask                                (0x00000300)
#define  PLL27X_REG_SYS_PLL_27X2_pll27x_ps_54m_delay_mask                        (0x00000030)
#define  PLL27X_REG_SYS_PLL_27X2_pll27x_ps_psel_pulse_w_mask                     (0x00000002)
#define  PLL27X_REG_SYS_PLL_27X2_pll27x_ps_duty_sel_mask                         (0x00000001)
#define  PLL27X_REG_SYS_PLL_27X2_xi_cap(data)                                    (0xF0000000&((data)<<28))
#define  PLL27X_REG_SYS_PLL_27X2_xo_cap(data)                                    (0x0F000000&((data)<<24))
#define  PLL27X_REG_SYS_PLL_27X2_vdd11_pad_sel(data)                             (0x00E00000&((data)<<21))
#define  PLL27X_REG_SYS_PLL_27X2_pll_ldo_xtal_sel(data)                          (0x00180000&((data)<<19))
#define  PLL27X_REG_SYS_PLL_27X2_pll_xixo_load(data)                             (0x00040000&((data)<<18))
#define  PLL27X_REG_SYS_PLL_27X2_pll_xixo_drive_sel(data)                        (0x00030000&((data)<<16))
#define  PLL27X_REG_SYS_PLL_27X2_pad_sel_en(data)                                (0x00008000&((data)<<15))
#define  PLL27X_REG_SYS_PLL_27X2_pll_pow_ldo11v(data)                            (0x00004000&((data)<<14))
#define  PLL27X_REG_SYS_PLL_27X2_pll_ldo11v_sel(data)                            (0x00003000&((data)<<12))
#define  PLL27X_REG_SYS_PLL_27X2_pll_pow_ldo(data)                               (0x00000400&((data)<<10))
#define  PLL27X_REG_SYS_PLL_27X2_pll_ldo_sel(data)                               (0x00000300&((data)<<8))
#define  PLL27X_REG_SYS_PLL_27X2_pll27x_ps_54m_delay(data)                       (0x00000030&((data)<<4))
#define  PLL27X_REG_SYS_PLL_27X2_pll27x_ps_psel_pulse_w(data)                    (0x00000002&((data)<<1))
#define  PLL27X_REG_SYS_PLL_27X2_pll27x_ps_duty_sel(data)                        (0x00000001&(data))
#define  PLL27X_REG_SYS_PLL_27X2_get_xi_cap(data)                                ((0xF0000000&(data))>>28)
#define  PLL27X_REG_SYS_PLL_27X2_get_xo_cap(data)                                ((0x0F000000&(data))>>24)
#define  PLL27X_REG_SYS_PLL_27X2_get_vdd11_pad_sel(data)                         ((0x00E00000&(data))>>21)
#define  PLL27X_REG_SYS_PLL_27X2_get_pll_ldo_xtal_sel(data)                      ((0x00180000&(data))>>19)
#define  PLL27X_REG_SYS_PLL_27X2_get_pll_xixo_load(data)                         ((0x00040000&(data))>>18)
#define  PLL27X_REG_SYS_PLL_27X2_get_pll_xixo_drive_sel(data)                    ((0x00030000&(data))>>16)
#define  PLL27X_REG_SYS_PLL_27X2_get_pad_sel_en(data)                            ((0x00008000&(data))>>15)
#define  PLL27X_REG_SYS_PLL_27X2_get_pll_pow_ldo11v(data)                        ((0x00004000&(data))>>14)
#define  PLL27X_REG_SYS_PLL_27X2_get_pll_ldo11v_sel(data)                        ((0x00003000&(data))>>12)
#define  PLL27X_REG_SYS_PLL_27X2_get_pll_pow_ldo(data)                           ((0x00000400&(data))>>10)
#define  PLL27X_REG_SYS_PLL_27X2_get_pll_ldo_sel(data)                           ((0x00000300&(data))>>8)
#define  PLL27X_REG_SYS_PLL_27X2_get_pll27x_ps_54m_delay(data)                   ((0x00000030&(data))>>4)
#define  PLL27X_REG_SYS_PLL_27X2_get_pll27x_ps_psel_pulse_w(data)                ((0x00000002&(data))>>1)
#define  PLL27X_REG_SYS_PLL_27X2_get_pll27x_ps_duty_sel(data)                    (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_27X3                                                 0x180004D8
#define  PLL27X_REG_SYS_PLL_27X3_reg_addr                                        "0xB80004D8"
#define  PLL27X_REG_SYS_PLL_27X3_reg                                             0xB80004D8
#define  PLL27X_REG_SYS_PLL_27X3_inst_addr                                       "0x0009"
#define  set_PLL27X_REG_SYS_PLL_27X3_reg(data)                                   (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_27X3_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_27X3_reg                                         (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_27X3_reg))
#define  PLL27X_REG_SYS_PLL_27X3_pll_reserve_shift                               (8)
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_ps_en_shift                              (4)
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_ps_div2_shift                            (3)
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_vcorstb_shift                            (2)
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_rstb_shift                               (1)
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_pow_shift                                (0)
#define  PLL27X_REG_SYS_PLL_27X3_pll_reserve_mask                                (0x0000FF00)
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_ps_en_mask                               (0x00000010)
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_ps_div2_mask                             (0x00000008)
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_vcorstb_mask                             (0x00000004)
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_rstb_mask                                (0x00000002)
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_pow_mask                                 (0x00000001)
#define  PLL27X_REG_SYS_PLL_27X3_pll_reserve(data)                               (0x0000FF00&((data)<<8))
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_ps_en(data)                              (0x00000010&((data)<<4))
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_ps_div2(data)                            (0x00000008&((data)<<3))
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_vcorstb(data)                            (0x00000004&((data)<<2))
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_rstb(data)                               (0x00000002&((data)<<1))
#define  PLL27X_REG_SYS_PLL_27X3_pll27x_pow(data)                                (0x00000001&(data))
#define  PLL27X_REG_SYS_PLL_27X3_get_pll_reserve(data)                           ((0x0000FF00&(data))>>8)
#define  PLL27X_REG_SYS_PLL_27X3_get_pll27x_ps_en(data)                          ((0x00000010&(data))>>4)
#define  PLL27X_REG_SYS_PLL_27X3_get_pll27x_ps_div2(data)                        ((0x00000008&(data))>>3)
#define  PLL27X_REG_SYS_PLL_27X3_get_pll27x_vcorstb(data)                        ((0x00000004&(data))>>2)
#define  PLL27X_REG_SYS_PLL_27X3_get_pll27x_rstb(data)                           ((0x00000002&(data))>>1)
#define  PLL27X_REG_SYS_PLL_27X3_get_pll27x_pow(data)                            (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_27X4                                                 0x180004DC
#define  PLL27X_REG_SYS_PLL_27X4_reg_addr                                        "0xB80004DC"
#define  PLL27X_REG_SYS_PLL_27X4_reg                                             0xB80004DC
#define  PLL27X_REG_SYS_PLL_27X4_inst_addr                                       "0x000A"
#define  set_PLL27X_REG_SYS_PLL_27X4_reg(data)                                   (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_27X4_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_27X4_reg                                         (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_27X4_reg))
#define  PLL27X_REG_SYS_PLL_27X4_dummy_31_shift                                  (31)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ifadc_duty_shift                         (29)
#define  PLL27X_REG_SYS_PLL_27X4_iqadc_cko_polar_shift                           (28)
#define  PLL27X_REG_SYS_PLL_27X4_pll_yppadc_cko_polar_shift                      (27)
#define  PLL27X_REG_SYS_PLL_27X4_pll_ifadc_cko_polar_shift                       (26)
#define  PLL27X_REG_SYS_PLL_27X4_pll_l2h_cml_pow_shift                           (25)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_d16_en_shift                             (24)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_pll_tst_shift                            (21)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_en_tst_shift                             (20)
#define  PLL27X_REG_SYS_PLL_27X4_pll_rssi_cko_en_shift                           (19)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ck108m_en_shift                          (18)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ck108m_div_shift                         (16)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_yppadc_cko_sel_shift                     (14)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_yppadc_cko_en_shift                      (13)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_yppadc_ck54m_en_shift                    (12)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ifadc_cko_sel_shift                      (10)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ifadc_div_shift                          (9)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ifadc_cko_en_shift                       (8)
#define  PLL27X_REG_SYS_PLL_27X4_pllaud_ckin_mux_shift                           (4)
#define  PLL27X_REG_SYS_PLL_27X4_pll_xtalwd_rst_shift                            (3)
#define  PLL27X_REG_SYS_PLL_27X4_pll_xtalwd_set_shift                            (2)
#define  PLL27X_REG_SYS_PLL_27X4_pll_ck_ifadc_mux_shift                          (0)
#define  PLL27X_REG_SYS_PLL_27X4_dummy_31_mask                                   (0x80000000)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ifadc_duty_mask                          (0x60000000)
#define  PLL27X_REG_SYS_PLL_27X4_iqadc_cko_polar_mask                            (0x10000000)
#define  PLL27X_REG_SYS_PLL_27X4_pll_yppadc_cko_polar_mask                       (0x08000000)
#define  PLL27X_REG_SYS_PLL_27X4_pll_ifadc_cko_polar_mask                        (0x04000000)
#define  PLL27X_REG_SYS_PLL_27X4_pll_l2h_cml_pow_mask                            (0x02000000)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_d16_en_mask                              (0x01000000)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_pll_tst_mask                             (0x00E00000)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_en_tst_mask                              (0x00100000)
#define  PLL27X_REG_SYS_PLL_27X4_pll_rssi_cko_en_mask                            (0x00080000)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ck108m_en_mask                           (0x00040000)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ck108m_div_mask                          (0x00030000)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_yppadc_cko_sel_mask                      (0x0000C000)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_yppadc_cko_en_mask                       (0x00002000)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_yppadc_ck54m_en_mask                     (0x00001000)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ifadc_cko_sel_mask                       (0x00000C00)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ifadc_div_mask                           (0x00000200)
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ifadc_cko_en_mask                        (0x00000100)
#define  PLL27X_REG_SYS_PLL_27X4_pllaud_ckin_mux_mask                            (0x00000010)
#define  PLL27X_REG_SYS_PLL_27X4_pll_xtalwd_rst_mask                             (0x00000008)
#define  PLL27X_REG_SYS_PLL_27X4_pll_xtalwd_set_mask                             (0x00000004)
#define  PLL27X_REG_SYS_PLL_27X4_pll_ck_ifadc_mux_mask                           (0x00000001)
#define  PLL27X_REG_SYS_PLL_27X4_dummy_31(data)                                  (0x80000000&((data)<<31))
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ifadc_duty(data)                         (0x60000000&((data)<<29))
#define  PLL27X_REG_SYS_PLL_27X4_iqadc_cko_polar(data)                           (0x10000000&((data)<<28))
#define  PLL27X_REG_SYS_PLL_27X4_pll_yppadc_cko_polar(data)                      (0x08000000&((data)<<27))
#define  PLL27X_REG_SYS_PLL_27X4_pll_ifadc_cko_polar(data)                       (0x04000000&((data)<<26))
#define  PLL27X_REG_SYS_PLL_27X4_pll_l2h_cml_pow(data)                           (0x02000000&((data)<<25))
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_d16_en(data)                             (0x01000000&((data)<<24))
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_pll_tst(data)                            (0x00E00000&((data)<<21))
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_en_tst(data)                             (0x00100000&((data)<<20))
#define  PLL27X_REG_SYS_PLL_27X4_pll_rssi_cko_en(data)                           (0x00080000&((data)<<19))
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ck108m_en(data)                          (0x00040000&((data)<<18))
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ck108m_div(data)                         (0x00030000&((data)<<16))
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_yppadc_cko_sel(data)                     (0x0000C000&((data)<<14))
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_yppadc_cko_en(data)                      (0x00002000&((data)<<13))
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_yppadc_ck54m_en(data)                    (0x00001000&((data)<<12))
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ifadc_cko_sel(data)                      (0x00000C00&((data)<<10))
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ifadc_div(data)                          (0x00000200&((data)<<9))
#define  PLL27X_REG_SYS_PLL_27X4_pll27x_ifadc_cko_en(data)                       (0x00000100&((data)<<8))
#define  PLL27X_REG_SYS_PLL_27X4_pllaud_ckin_mux(data)                           (0x00000010&((data)<<4))
#define  PLL27X_REG_SYS_PLL_27X4_pll_xtalwd_rst(data)                            (0x00000008&((data)<<3))
#define  PLL27X_REG_SYS_PLL_27X4_pll_xtalwd_set(data)                            (0x00000004&((data)<<2))
#define  PLL27X_REG_SYS_PLL_27X4_pll_ck_ifadc_mux(data)                          (0x00000001&(data))
#define  PLL27X_REG_SYS_PLL_27X4_get_dummy_31(data)                              ((0x80000000&(data))>>31)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll27x_ifadc_duty(data)                     ((0x60000000&(data))>>29)
#define  PLL27X_REG_SYS_PLL_27X4_get_iqadc_cko_polar(data)                       ((0x10000000&(data))>>28)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll_yppadc_cko_polar(data)                  ((0x08000000&(data))>>27)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll_ifadc_cko_polar(data)                   ((0x04000000&(data))>>26)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll_l2h_cml_pow(data)                       ((0x02000000&(data))>>25)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll27x_d16_en(data)                         ((0x01000000&(data))>>24)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll27x_pll_tst(data)                        ((0x00E00000&(data))>>21)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll27x_en_tst(data)                         ((0x00100000&(data))>>20)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll_rssi_cko_en(data)                       ((0x00080000&(data))>>19)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll27x_ck108m_en(data)                      ((0x00040000&(data))>>18)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll27x_ck108m_div(data)                     ((0x00030000&(data))>>16)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll27x_yppadc_cko_sel(data)                 ((0x0000C000&(data))>>14)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll27x_yppadc_cko_en(data)                  ((0x00002000&(data))>>13)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll27x_yppadc_ck54m_en(data)                ((0x00001000&(data))>>12)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll27x_ifadc_cko_sel(data)                  ((0x00000C00&(data))>>10)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll27x_ifadc_div(data)                      ((0x00000200&(data))>>9)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll27x_ifadc_cko_en(data)                   ((0x00000100&(data))>>8)
#define  PLL27X_REG_SYS_PLL_27X4_get_pllaud_ckin_mux(data)                       ((0x00000010&(data))>>4)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll_xtalwd_rst(data)                        ((0x00000008&(data))>>3)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll_xtalwd_set(data)                        ((0x00000004&(data))>>2)
#define  PLL27X_REG_SYS_PLL_27X4_get_pll_ck_ifadc_mux(data)                      (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_AUD1                                                 0x180004E0
#define  PLL27X_REG_SYS_PLL_AUD1_reg_addr                                        "0xB80004E0"
#define  PLL27X_REG_SYS_PLL_AUD1_reg                                             0xB80004E0
#define  PLL27X_REG_SYS_PLL_AUD1_inst_addr                                       "0x000B"
#define  set_PLL27X_REG_SYS_PLL_AUD1_reg(data)                                   (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_AUD1_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_AUD1_reg                                         (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_AUD1_reg))
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_ip_shift                                 (15)
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_rs_shift                                 (11)
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_cp_shift                                 (8)
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_wdrst_shift                              (2)
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_wdset_shift                              (1)
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_tst_shift                                (0)
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_ip_mask                                  (0x00038000)
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_rs_mask                                  (0x00001800)
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_cp_mask                                  (0x00000300)
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_wdrst_mask                               (0x00000004)
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_wdset_mask                               (0x00000002)
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_tst_mask                                 (0x00000001)
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_ip(data)                                 (0x00038000&((data)<<15))
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_rs(data)                                 (0x00001800&((data)<<11))
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_cp(data)                                 (0x00000300&((data)<<8))
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_wdrst(data)                              (0x00000004&((data)<<2))
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_wdset(data)                              (0x00000002&((data)<<1))
#define  PLL27X_REG_SYS_PLL_AUD1_pllaud_tst(data)                                (0x00000001&(data))
#define  PLL27X_REG_SYS_PLL_AUD1_get_pllaud_ip(data)                             ((0x00038000&(data))>>15)
#define  PLL27X_REG_SYS_PLL_AUD1_get_pllaud_rs(data)                             ((0x00001800&(data))>>11)
#define  PLL27X_REG_SYS_PLL_AUD1_get_pllaud_cp(data)                             ((0x00000300&(data))>>8)
#define  PLL27X_REG_SYS_PLL_AUD1_get_pllaud_wdrst(data)                          ((0x00000004&(data))>>2)
#define  PLL27X_REG_SYS_PLL_AUD1_get_pllaud_wdset(data)                          ((0x00000002&(data))>>1)
#define  PLL27X_REG_SYS_PLL_AUD1_get_pllaud_tst(data)                            (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_AUD3                                                 0x180004E4
#define  PLL27X_REG_SYS_PLL_AUD3_reg_addr                                        "0xB80004E4"
#define  PLL27X_REG_SYS_PLL_AUD3_reg                                             0xB80004E4
#define  PLL27X_REG_SYS_PLL_AUD3_inst_addr                                       "0x000C"
#define  set_PLL27X_REG_SYS_PLL_AUD3_reg(data)                                   (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_AUD3_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_AUD3_reg                                         (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_AUD3_reg))
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_vcorstb_shift                            (4)
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_rstb_shift                               (3)
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_oeb1_shift                               (2)
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_oeb2_shift                               (1)
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_pow_shift                                (0)
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_vcorstb_mask                             (0x00000010)
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_rstb_mask                                (0x00000008)
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_oeb1_mask                                (0x00000004)
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_oeb2_mask                                (0x00000002)
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_pow_mask                                 (0x00000001)
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_vcorstb(data)                            (0x00000010&((data)<<4))
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_rstb(data)                               (0x00000008&((data)<<3))
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_oeb1(data)                               (0x00000004&((data)<<2))
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_oeb2(data)                               (0x00000002&((data)<<1))
#define  PLL27X_REG_SYS_PLL_AUD3_pllaud_pow(data)                                (0x00000001&(data))
#define  PLL27X_REG_SYS_PLL_AUD3_get_pllaud_vcorstb(data)                        ((0x00000010&(data))>>4)
#define  PLL27X_REG_SYS_PLL_AUD3_get_pllaud_rstb(data)                           ((0x00000008&(data))>>3)
#define  PLL27X_REG_SYS_PLL_AUD3_get_pllaud_oeb1(data)                           ((0x00000004&(data))>>2)
#define  PLL27X_REG_SYS_PLL_AUD3_get_pllaud_oeb2(data)                           ((0x00000002&(data))>>1)
#define  PLL27X_REG_SYS_PLL_AUD3_get_pllaud_pow(data)                            (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_AUD4                                                 0x180004E8
#define  PLL27X_REG_SYS_PLL_AUD4_reg_addr                                        "0xB80004E8"
#define  PLL27X_REG_SYS_PLL_AUD4_reg                                             0xB80004E8
#define  PLL27X_REG_SYS_PLL_AUD4_inst_addr                                       "0x000D"
#define  set_PLL27X_REG_SYS_PLL_AUD4_reg(data)                                   (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_AUD4_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_AUD4_reg                                         (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_AUD4_reg))
#define  PLL27X_REG_SYS_PLL_AUD4_bb_micbias_clksel_shift                         (0)
#define  PLL27X_REG_SYS_PLL_AUD4_bb_micbias_clksel_mask                          (0x00000003)
#define  PLL27X_REG_SYS_PLL_AUD4_bb_micbias_clksel(data)                         (0x00000003&(data))
#define  PLL27X_REG_SYS_PLL_AUD4_get_bb_micbias_clksel(data)                     (0x00000003&(data))

#define  PLL27X_REG_SYS_PLL_PSAUD1                                               0x180004EC
#define  PLL27X_REG_SYS_PLL_PSAUD1_reg_addr                                      "0xB80004EC"
#define  PLL27X_REG_SYS_PLL_PSAUD1_reg                                           0xB80004EC
#define  PLL27X_REG_SYS_PLL_PSAUD1_inst_addr                                     "0x000E"
#define  set_PLL27X_REG_SYS_PLL_PSAUD1_reg(data)                                 (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_PSAUD1_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_PSAUD1_reg                                       (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_PSAUD1_reg))
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_adder_mode_shift                        (4)
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_psen_shift                              (3)
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_en_shift                                (2)
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_tst_shift                               (1)
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_ctrl_shift                              (0)
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_adder_mode_mask                         (0x00000010)
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_psen_mask                               (0x00000008)
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_en_mask                                 (0x00000004)
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_tst_mask                                (0x00000002)
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_ctrl_mask                               (0x00000001)
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_adder_mode(data)                        (0x00000010&((data)<<4))
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_psen(data)                              (0x00000008&((data)<<3))
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_en(data)                                (0x00000004&((data)<<2))
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_tst(data)                               (0x00000002&((data)<<1))
#define  PLL27X_REG_SYS_PLL_PSAUD1_psaud_ctrl(data)                              (0x00000001&(data))
#define  PLL27X_REG_SYS_PLL_PSAUD1_get_psaud_adder_mode(data)                    ((0x00000010&(data))>>4)
#define  PLL27X_REG_SYS_PLL_PSAUD1_get_psaud_psen(data)                          ((0x00000008&(data))>>3)
#define  PLL27X_REG_SYS_PLL_PSAUD1_get_psaud_en(data)                            ((0x00000004&(data))>>2)
#define  PLL27X_REG_SYS_PLL_PSAUD1_get_psaud_tst(data)                           ((0x00000002&(data))>>1)
#define  PLL27X_REG_SYS_PLL_PSAUD1_get_psaud_ctrl(data)                          (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_PSAUD2                                               0x180004F0
#define  PLL27X_REG_SYS_PLL_PSAUD2_reg_addr                                      "0xB80004F0"
#define  PLL27X_REG_SYS_PLL_PSAUD2_reg                                           0xB80004F0
#define  PLL27X_REG_SYS_PLL_PSAUD2_inst_addr                                     "0x000F"
#define  set_PLL27X_REG_SYS_PLL_PSAUD2_reg(data)                                 (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_PSAUD2_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_PSAUD2_reg                                       (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_PSAUD2_reg))
#define  PLL27X_REG_SYS_PLL_PSAUD2_psaud_div_shift                               (0)
#define  PLL27X_REG_SYS_PLL_PSAUD2_psaud_div_mask                                (0x0000000F)
#define  PLL27X_REG_SYS_PLL_PSAUD2_psaud_div(data)                               (0x0000000F&(data))
#define  PLL27X_REG_SYS_PLL_PSAUD2_get_psaud_div(data)                           (0x0000000F&(data))

#define  PLL27X_REG_SS_ADTV_0                                                    0x180004F4
#define  PLL27X_REG_SS_ADTV_0_reg_addr                                           "0xB80004F4"
#define  PLL27X_REG_SS_ADTV_0_reg                                                0xB80004F4
#define  PLL27X_REG_SS_ADTV_0_inst_addr                                          "0x0010"
#define  set_PLL27X_REG_SS_ADTV_0_reg(data)                                      (*((volatile unsigned int*)PLL27X_REG_SS_ADTV_0_reg)=data)
#define  get_PLL27X_REG_SS_ADTV_0_reg                                            (*((volatile unsigned int*)PLL27X_REG_SS_ADTV_0_reg))
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_dss_rst_n_shift                           (31)
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_ro_sel_shift                              (25)
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_wire_sel_shift                            (24)
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_ready_shift                               (20)
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_count_out_shift                           (0)
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_dss_rst_n_mask                            (0x80000000)
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_ro_sel_mask                               (0x0E000000)
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_wire_sel_mask                             (0x01000000)
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_ready_mask                                (0x00100000)
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_count_out_mask                            (0x000FFFFF)
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_dss_rst_n(data)                           (0x80000000&((data)<<31))
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_ro_sel(data)                              (0x0E000000&((data)<<25))
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_wire_sel(data)                            (0x01000000&((data)<<24))
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_ready(data)                               (0x00100000&((data)<<20))
#define  PLL27X_REG_SS_ADTV_0_dss_adtv_count_out(data)                           (0x000FFFFF&(data))
#define  PLL27X_REG_SS_ADTV_0_get_dss_adtv_dss_rst_n(data)                       ((0x80000000&(data))>>31)
#define  PLL27X_REG_SS_ADTV_0_get_dss_adtv_ro_sel(data)                          ((0x0E000000&(data))>>25)
#define  PLL27X_REG_SS_ADTV_0_get_dss_adtv_wire_sel(data)                        ((0x01000000&(data))>>24)
#define  PLL27X_REG_SS_ADTV_0_get_dss_adtv_ready(data)                           ((0x00100000&(data))>>20)
#define  PLL27X_REG_SS_ADTV_0_get_dss_adtv_count_out(data)                       (0x000FFFFF&(data))

#define  PLL27X_REG_SS_ADTV_1                                                    0x180004F8
#define  PLL27X_REG_SS_ADTV_1_reg_addr                                           "0xB80004F8"
#define  PLL27X_REG_SS_ADTV_1_reg                                                0xB80004F8
#define  PLL27X_REG_SS_ADTV_1_inst_addr                                          "0x0011"
#define  set_PLL27X_REG_SS_ADTV_1_reg(data)                                      (*((volatile unsigned int*)PLL27X_REG_SS_ADTV_1_reg)=data)
#define  get_PLL27X_REG_SS_ADTV_1_reg                                            (*((volatile unsigned int*)PLL27X_REG_SS_ADTV_1_reg))
#define  PLL27X_REG_SS_ADTV_1_dss_adtv_speed_en_shift                            (21)
#define  PLL27X_REG_SS_ADTV_1_dss_adtv_wsort_go_shift                            (20)
#define  PLL27X_REG_SS_ADTV_1_dss_adtv_data_in_shift                             (0)
#define  PLL27X_REG_SS_ADTV_1_dss_adtv_speed_en_mask                             (0x00200000)
#define  PLL27X_REG_SS_ADTV_1_dss_adtv_wsort_go_mask                             (0x00100000)
#define  PLL27X_REG_SS_ADTV_1_dss_adtv_data_in_mask                              (0x000FFFFF)
#define  PLL27X_REG_SS_ADTV_1_dss_adtv_speed_en(data)                            (0x00200000&((data)<<21))
#define  PLL27X_REG_SS_ADTV_1_dss_adtv_wsort_go(data)                            (0x00100000&((data)<<20))
#define  PLL27X_REG_SS_ADTV_1_dss_adtv_data_in(data)                             (0x000FFFFF&(data))
#define  PLL27X_REG_SS_ADTV_1_get_dss_adtv_speed_en(data)                        ((0x00200000&(data))>>21)
#define  PLL27X_REG_SS_ADTV_1_get_dss_adtv_wsort_go(data)                        ((0x00100000&(data))>>20)
#define  PLL27X_REG_SS_ADTV_1_get_dss_adtv_data_in(data)                         (0x000FFFFF&(data))

#define  PLL27X_REG_SS_ADTV_2                                                    0x180004FC
#define  PLL27X_REG_SS_ADTV_2_reg_addr                                           "0xB80004FC"
#define  PLL27X_REG_SS_ADTV_2_reg                                                0xB80004FC
#define  PLL27X_REG_SS_ADTV_2_inst_addr                                          "0x0012"
#define  set_PLL27X_REG_SS_ADTV_2_reg(data)                                      (*((volatile unsigned int*)PLL27X_REG_SS_ADTV_2_reg)=data)
#define  get_PLL27X_REG_SS_ADTV_2_reg                                            (*((volatile unsigned int*)PLL27X_REG_SS_ADTV_2_reg))
#define  PLL27X_REG_SS_ADTV_2_dss_adtv_dbgo_shift                                (0)
#define  PLL27X_REG_SS_ADTV_2_dss_adtv_dbgo_mask                                 (0x0000FFFF)
#define  PLL27X_REG_SS_ADTV_2_dss_adtv_dbgo(data)                                (0x0000FFFF&(data))
#define  PLL27X_REG_SS_ADTV_2_get_dss_adtv_dbgo(data)                            (0x0000FFFF&(data))

#define  PLL27X_REG_IFADC_1                                                      0x18000500
#define  PLL27X_REG_IFADC_1_reg_addr                                             "0xB8000500"
#define  PLL27X_REG_IFADC_1_reg                                                  0xB8000500
#define  PLL27X_REG_IFADC_1_inst_addr                                            "0x0013"
#define  set_PLL27X_REG_IFADC_1_reg(data)                                        (*((volatile unsigned int*)PLL27X_REG_IFADC_1_reg)=data)
#define  get_PLL27X_REG_IFADC_1_reg                                              (*((volatile unsigned int*)PLL27X_REG_IFADC_1_reg))
#define  PLL27X_REG_IFADC_1_pll27x_iqadc_cko_sel_shift                           (10)
#define  PLL27X_REG_IFADC_1_pll27x_iqadc_cko_en_shift                            (8)
#define  PLL27X_REG_IFADC_1_pll27x_ifadc_dtv_cko_sel_shift                       (6)
#define  PLL27X_REG_IFADC_1_pll27x_ifadc_dtv_cko_en_shift                        (4)
#define  PLL27X_REG_IFADC_1_pll27x_ifadc_atv_cko_sel_shift                       (2)
#define  PLL27X_REG_IFADC_1_pip_ifadc_atv_cko_sel_shift                          (0)
#define  PLL27X_REG_IFADC_1_pll27x_iqadc_cko_sel_mask                            (0x00000C00)
#define  PLL27X_REG_IFADC_1_pll27x_iqadc_cko_en_mask                             (0x00000100)
#define  PLL27X_REG_IFADC_1_pll27x_ifadc_dtv_cko_sel_mask                        (0x000000C0)
#define  PLL27X_REG_IFADC_1_pll27x_ifadc_dtv_cko_en_mask                         (0x00000010)
#define  PLL27X_REG_IFADC_1_pll27x_ifadc_atv_cko_sel_mask                        (0x0000000C)
#define  PLL27X_REG_IFADC_1_pip_ifadc_atv_cko_sel_mask                           (0x00000001)
#define  PLL27X_REG_IFADC_1_pll27x_iqadc_cko_sel(data)                           (0x00000C00&((data)<<10))
#define  PLL27X_REG_IFADC_1_pll27x_iqadc_cko_en(data)                            (0x00000100&((data)<<8))
#define  PLL27X_REG_IFADC_1_pll27x_ifadc_dtv_cko_sel(data)                       (0x000000C0&((data)<<6))
#define  PLL27X_REG_IFADC_1_pll27x_ifadc_dtv_cko_en(data)                        (0x00000010&((data)<<4))
#define  PLL27X_REG_IFADC_1_pll27x_ifadc_atv_cko_sel(data)                       (0x0000000C&((data)<<2))
#define  PLL27X_REG_IFADC_1_pip_ifadc_atv_cko_sel(data)                          (0x00000001&(data))
#define  PLL27X_REG_IFADC_1_get_pll27x_iqadc_cko_sel(data)                       ((0x00000C00&(data))>>10)
#define  PLL27X_REG_IFADC_1_get_pll27x_iqadc_cko_en(data)                        ((0x00000100&(data))>>8)
#define  PLL27X_REG_IFADC_1_get_pll27x_ifadc_dtv_cko_sel(data)                   ((0x000000C0&(data))>>6)
#define  PLL27X_REG_IFADC_1_get_pll27x_ifadc_dtv_cko_en(data)                    ((0x00000010&(data))>>4)
#define  PLL27X_REG_IFADC_1_get_pll27x_ifadc_atv_cko_sel(data)                   ((0x0000000C&(data))>>2)
#define  PLL27X_REG_IFADC_1_get_pip_ifadc_atv_cko_sel(data)                      (0x00000001&(data))

#define  PLL27X_REG_IFADC_2                                                      0x18000504
#define  PLL27X_REG_IFADC_2_reg_addr                                             "0xB8000504"
#define  PLL27X_REG_IFADC_2_reg                                                  0xB8000504
#define  PLL27X_REG_IFADC_2_inst_addr                                            "0x0014"
#define  set_PLL27X_REG_IFADC_2_reg(data)                                        (*((volatile unsigned int*)PLL27X_REG_IFADC_2_reg)=data)
#define  get_PLL27X_REG_IFADC_2_reg                                              (*((volatile unsigned int*)PLL27X_REG_IFADC_2_reg))
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_n_shift                                 (24)
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_m_shift                                 (16)
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_lf_rs_shift                             (8)
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_lf_cp_shift                             (4)
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_ip_shift                                (0)
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_n_mask                                  (0x03000000)
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_m_mask                                  (0x007F0000)
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_lf_rs_mask                              (0x00000300)
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_lf_cp_mask                              (0x00000030)
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_ip_mask                                 (0x00000007)
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_n(data)                                 (0x03000000&((data)<<24))
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_m(data)                                 (0x007F0000&((data)<<16))
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_lf_rs(data)                             (0x00000300&((data)<<8))
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_lf_cp(data)                             (0x00000030&((data)<<4))
#define  PLL27X_REG_IFADC_2_pll27x_ifadc_ip(data)                                (0x00000007&(data))
#define  PLL27X_REG_IFADC_2_get_pll27x_ifadc_n(data)                             ((0x03000000&(data))>>24)
#define  PLL27X_REG_IFADC_2_get_pll27x_ifadc_m(data)                             ((0x007F0000&(data))>>16)
#define  PLL27X_REG_IFADC_2_get_pll27x_ifadc_lf_rs(data)                         ((0x00000300&(data))>>8)
#define  PLL27X_REG_IFADC_2_get_pll27x_ifadc_lf_cp(data)                         ((0x00000030&(data))>>4)
#define  PLL27X_REG_IFADC_2_get_pll27x_ifadc_ip(data)                            (0x00000007&(data))

#define  PLL27X_REG_IFADC_3                                                      0x18000508
#define  PLL27X_REG_IFADC_3_reg_addr                                             "0xB8000508"
#define  PLL27X_REG_IFADC_3_reg                                                  0xB8000508
#define  PLL27X_REG_IFADC_3_inst_addr                                            "0x0015"
#define  set_PLL27X_REG_IFADC_3_reg(data)                                        (*((volatile unsigned int*)PLL27X_REG_IFADC_3_reg)=data)
#define  get_PLL27X_REG_IFADC_3_reg                                              (*((volatile unsigned int*)PLL27X_REG_IFADC_3_reg))
#define  PLL27X_REG_IFADC_3_pll27x_ifadc_wdmode_shift                            (4)
#define  PLL27X_REG_IFADC_3_pll27x_ifadc_vcorstb_shift                           (2)
#define  PLL27X_REG_IFADC_3_pll27x_ifadc_rstb_shift                              (1)
#define  PLL27X_REG_IFADC_3_pll27x_ifadc_pow_shift                               (0)
#define  PLL27X_REG_IFADC_3_pll27x_ifadc_wdmode_mask                             (0x00000030)
#define  PLL27X_REG_IFADC_3_pll27x_ifadc_vcorstb_mask                            (0x00000004)
#define  PLL27X_REG_IFADC_3_pll27x_ifadc_rstb_mask                               (0x00000002)
#define  PLL27X_REG_IFADC_3_pll27x_ifadc_pow_mask                                (0x00000001)
#define  PLL27X_REG_IFADC_3_pll27x_ifadc_wdmode(data)                            (0x00000030&((data)<<4))
#define  PLL27X_REG_IFADC_3_pll27x_ifadc_vcorstb(data)                           (0x00000004&((data)<<2))
#define  PLL27X_REG_IFADC_3_pll27x_ifadc_rstb(data)                              (0x00000002&((data)<<1))
#define  PLL27X_REG_IFADC_3_pll27x_ifadc_pow(data)                               (0x00000001&(data))
#define  PLL27X_REG_IFADC_3_get_pll27x_ifadc_wdmode(data)                        ((0x00000030&(data))>>4)
#define  PLL27X_REG_IFADC_3_get_pll27x_ifadc_vcorstb(data)                       ((0x00000004&(data))>>2)
#define  PLL27X_REG_IFADC_3_get_pll27x_ifadc_rstb(data)                          ((0x00000002&(data))>>1)
#define  PLL27X_REG_IFADC_3_get_pll27x_ifadc_pow(data)                           (0x00000001&(data))

#define  PLL27X_REG_SYS_DCLKSS                                                   0x18000640
#define  PLL27X_REG_SYS_DCLKSS_reg_addr                                          "0xB8000640"
#define  PLL27X_REG_SYS_DCLKSS_reg                                               0xB8000640
#define  PLL27X_REG_SYS_DCLKSS_inst_addr                                         "0x0016"
#define  set_PLL27X_REG_SYS_DCLKSS_reg(data)                                     (*((volatile unsigned int*)PLL27X_REG_SYS_DCLKSS_reg)=data)
#define  get_PLL27X_REG_SYS_DCLKSS_reg                                           (*((volatile unsigned int*)PLL27X_REG_SYS_DCLKSS_reg))
#define  PLL27X_REG_SYS_DCLKSS_dclk_field_flag_mode_en_shift                     (31)
#define  PLL27X_REG_SYS_DCLKSS_dclk_filed_flag_slt_shift                         (28)
#define  PLL27X_REG_SYS_DCLKSS_dclk_new_en_shift                                 (15)
#define  PLL27X_REG_SYS_DCLKSS_dummy_3_shift                                     (3)
#define  PLL27X_REG_SYS_DCLKSS_dclk_ss_load_shift                                (2)
#define  PLL27X_REG_SYS_DCLKSS_dummy_1_shift                                     (1)
#define  PLL27X_REG_SYS_DCLKSS_dclk_ss_en_shift                                  (0)
#define  PLL27X_REG_SYS_DCLKSS_dclk_field_flag_mode_en_mask                      (0x80000000)
#define  PLL27X_REG_SYS_DCLKSS_dclk_filed_flag_slt_mask                          (0x70000000)
#define  PLL27X_REG_SYS_DCLKSS_dclk_new_en_mask                                  (0x00008000)
#define  PLL27X_REG_SYS_DCLKSS_dummy_3_mask                                      (0x00000008)
#define  PLL27X_REG_SYS_DCLKSS_dclk_ss_load_mask                                 (0x00000004)
#define  PLL27X_REG_SYS_DCLKSS_dummy_1_mask                                      (0x00000002)
#define  PLL27X_REG_SYS_DCLKSS_dclk_ss_en_mask                                   (0x00000001)
#define  PLL27X_REG_SYS_DCLKSS_dclk_field_flag_mode_en(data)                     (0x80000000&((data)<<31))
#define  PLL27X_REG_SYS_DCLKSS_dclk_filed_flag_slt(data)                         (0x70000000&((data)<<28))
#define  PLL27X_REG_SYS_DCLKSS_dclk_new_en(data)                                 (0x00008000&((data)<<15))
#define  PLL27X_REG_SYS_DCLKSS_dummy_3(data)                                     (0x00000008&((data)<<3))
#define  PLL27X_REG_SYS_DCLKSS_dclk_ss_load(data)                                (0x00000004&((data)<<2))
#define  PLL27X_REG_SYS_DCLKSS_dummy_1(data)                                     (0x00000002&((data)<<1))
#define  PLL27X_REG_SYS_DCLKSS_dclk_ss_en(data)                                  (0x00000001&(data))
#define  PLL27X_REG_SYS_DCLKSS_get_dclk_field_flag_mode_en(data)                 ((0x80000000&(data))>>31)
#define  PLL27X_REG_SYS_DCLKSS_get_dclk_filed_flag_slt(data)                     ((0x70000000&(data))>>28)
#define  PLL27X_REG_SYS_DCLKSS_get_dclk_new_en(data)                             ((0x00008000&(data))>>15)
#define  PLL27X_REG_SYS_DCLKSS_get_dummy_3(data)                                 ((0x00000008&(data))>>3)
#define  PLL27X_REG_SYS_DCLKSS_get_dclk_ss_load(data)                            ((0x00000004&(data))>>2)
#define  PLL27X_REG_SYS_DCLKSS_get_dummy_1(data)                                 ((0x00000002&(data))>>1)
#define  PLL27X_REG_SYS_DCLKSS_get_dclk_ss_en(data)                              (0x00000001&(data))

#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL                                  0x18000644
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_reg_addr                         "0xB8000644"
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_reg                              0xB8000644
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_inst_addr                        "0x0017"
#define  set_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_reg(data)                    (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_reg)=data)
#define  get_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_reg                          (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_reg))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_dclk_freq_syn_slt_shift          (16)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_fll_tracking_en_shift            (4)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_offset_inverse_shift (3)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_ypbpr_en_shift (2)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_vd_dec_en_shift (1)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_general_en_shift (0)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_dclk_freq_syn_slt_mask           (0x3FFF0000)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_fll_tracking_en_mask             (0x00000010)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_offset_inverse_mask (0x00000008)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_ypbpr_en_mask  (0x00000004)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_vd_dec_en_mask (0x00000002)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_general_en_mask (0x00000001)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_dclk_freq_syn_slt(data)          (0x3FFF0000&((data)<<16))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_fll_tracking_en(data)            (0x00000010&((data)<<4))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_offset_inverse(data) (0x00000008&((data)<<3))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_ypbpr_en(data) (0x00000004&((data)<<2))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_vd_dec_en(data) (0x00000002&((data)<<1))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_general_en(data) (0x00000001&(data))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_get_dclk_freq_syn_slt(data)      ((0x3FFF0000&(data))>>16)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_get_fll_tracking_en(data)        ((0x00000010&(data))>>4)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_offset_inverse(data) ((0x00000008&(data))>>3)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_ypbpr_en(data) ((0x00000004&(data))>>2)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_vd_dec_en(data) ((0x00000002&(data))>>1)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_general_en(data) (0x00000001&(data))

#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL2                                 0x18000648
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL2_reg_addr                        "0xB8000648"
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL2_reg                             0xB8000648
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL2_inst_addr                       "0x0018"
#define  set_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL2_reg(data)                   (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL2_reg)=data)
#define  get_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL2_reg                         (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL2_reg))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_mul_shift     (0)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_mul_mask      (0x0007FFFF)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_mul(data)     (0x0007FFFF&(data))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL2_get_in_frame_tracking_mul(data) (0x0007FFFF&(data))

#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3                                 0x1800064C
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_reg_addr                        "0xB800064C"
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_reg                             0xB800064C
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_inst_addr                       "0x0019"
#define  set_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_reg(data)                   (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_reg)=data)
#define  get_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_reg                         (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_reg))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_neg_th_shift  (16)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_pos_th_shift  (0)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_neg_th_mask   (0xFFFF0000)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_pos_th_mask   (0x0000FFFF)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_neg_th(data)  (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_pos_th(data)  (0x0000FFFF&(data))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_get_in_frame_tracking_neg_th(data) ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL3_get_in_frame_tracking_pos_th(data) (0x0000FFFF&(data))

#define  PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP                                       0x18000650
#define  PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_reg_addr                              "0xB8000650"
#define  PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_reg                                   0xB8000650
#define  PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_inst_addr                             "0x001A"
#define  set_PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_reg(data)                         (*((volatile unsigned int*)PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_reg)=data)
#define  get_PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_reg                               (*((volatile unsigned int*)PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_reg))
#define  PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speed_dir_shift             (16)
#define  PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_offset_shift        (0)
#define  PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speed_dir_mask              (0x00010000)
#define  PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_offset_mask         (0x00001FFF)
#define  PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speed_dir(data)             (0x00010000&((data)<<16))
#define  PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_offset(data)        (0x00001FFF&(data))
#define  PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_get_frc2fsync_speed_dir(data)         ((0x00010000&(data))>>16)
#define  PLL27X_REG_DCLK_FRC2FSYNC_SPEEDUP_get_frc2fsync_speedup_offset(data)    (0x00001FFF&(data))

#define  PLL27X_REG_DPLL_STATUS_RO                                               0x18000654
#define  PLL27X_REG_DPLL_STATUS_RO_reg_addr                                      "0xB8000654"
#define  PLL27X_REG_DPLL_STATUS_RO_reg                                           0xB8000654
#define  PLL27X_REG_DPLL_STATUS_RO_inst_addr                                     "0x001B"
#define  set_PLL27X_REG_DPLL_STATUS_RO_reg(data)                                 (*((volatile unsigned int*)PLL27X_REG_DPLL_STATUS_RO_reg)=data)
#define  get_PLL27X_REG_DPLL_STATUS_RO_reg                                       (*((volatile unsigned int*)PLL27X_REG_DPLL_STATUS_RO_reg))
#define  PLL27X_REG_DPLL_STATUS_RO_final_profile_shift                           (0)
#define  PLL27X_REG_DPLL_STATUS_RO_final_profile_mask                            (0x0003FFFF)
#define  PLL27X_REG_DPLL_STATUS_RO_final_profile(data)                           (0x0003FFFF&(data))
#define  PLL27X_REG_DPLL_STATUS_RO_get_final_profile(data)                       (0x0003FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE_CTL                                           0x18000658
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_reg_addr                                  "0xB8000658"
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_reg                                       0xB8000658
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_inst_addr                                 "0x001C"
#define  set_PLL27X_REG_DCLKSS_PROFILE_CTL_reg(data)                             (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE_CTL_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE_CTL_reg                                   (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE_CTL_reg))
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_dummy_31_12_shift                         (12)
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_dclk_profile_remap_cnt_shift              (4)
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_dclk_profile_remap_en_shift               (0)
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_dummy_31_12_mask                          (0xFFFFF000)
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_dclk_profile_remap_cnt_mask               (0x00000FF0)
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_dclk_profile_remap_en_mask                (0x00000001)
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_dummy_31_12(data)                         (0xFFFFF000&((data)<<12))
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_dclk_profile_remap_cnt(data)              (0x00000FF0&((data)<<4))
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_dclk_profile_remap_en(data)               (0x00000001&(data))
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_get_dummy_31_12(data)                     ((0xFFFFF000&(data))>>12)
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_get_dclk_profile_remap_cnt(data)          ((0x00000FF0&(data))>>4)
#define  PLL27X_REG_DCLKSS_PROFILE_CTL_get_dclk_profile_remap_en(data)           (0x00000001&(data))

#define  PLL27X_REG_DCLKSS_PROFILE0                                              0x1800065C
#define  PLL27X_REG_DCLKSS_PROFILE0_reg_addr                                     "0xB800065C"
#define  PLL27X_REG_DCLKSS_PROFILE0_reg                                          0xB800065C
#define  PLL27X_REG_DCLKSS_PROFILE0_inst_addr                                    "0x001D"
#define  set_PLL27X_REG_DCLKSS_PROFILE0_reg(data)                                (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE0_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE0_reg                                      (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE0_reg))
#define  PLL27X_REG_DCLKSS_PROFILE0_dclk_profile_remap_1_shift                   (16)
#define  PLL27X_REG_DCLKSS_PROFILE0_dclk_profile_remap_0_shift                   (0)
#define  PLL27X_REG_DCLKSS_PROFILE0_dclk_profile_remap_1_mask                    (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE0_dclk_profile_remap_0_mask                    (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE0_dclk_profile_remap_1(data)                   (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE0_dclk_profile_remap_0(data)                   (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE0_get_dclk_profile_remap_1(data)               ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE0_get_dclk_profile_remap_0(data)               (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE1                                              0x18000660
#define  PLL27X_REG_DCLKSS_PROFILE1_reg_addr                                     "0xB8000660"
#define  PLL27X_REG_DCLKSS_PROFILE1_reg                                          0xB8000660
#define  PLL27X_REG_DCLKSS_PROFILE1_inst_addr                                    "0x001E"
#define  set_PLL27X_REG_DCLKSS_PROFILE1_reg(data)                                (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE1_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE1_reg                                      (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE1_reg))
#define  PLL27X_REG_DCLKSS_PROFILE1_dclk_profile_remap_3_shift                   (16)
#define  PLL27X_REG_DCLKSS_PROFILE1_dclk_profile_remap_2_shift                   (0)
#define  PLL27X_REG_DCLKSS_PROFILE1_dclk_profile_remap_3_mask                    (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE1_dclk_profile_remap_2_mask                    (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE1_dclk_profile_remap_3(data)                   (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE1_dclk_profile_remap_2(data)                   (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE1_get_dclk_profile_remap_3(data)               ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE1_get_dclk_profile_remap_2(data)               (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE2                                              0x18000664
#define  PLL27X_REG_DCLKSS_PROFILE2_reg_addr                                     "0xB8000664"
#define  PLL27X_REG_DCLKSS_PROFILE2_reg                                          0xB8000664
#define  PLL27X_REG_DCLKSS_PROFILE2_inst_addr                                    "0x001F"
#define  set_PLL27X_REG_DCLKSS_PROFILE2_reg(data)                                (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE2_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE2_reg                                      (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE2_reg))
#define  PLL27X_REG_DCLKSS_PROFILE2_dclk_profile_remap_5_shift                   (16)
#define  PLL27X_REG_DCLKSS_PROFILE2_dclk_profile_remap_4_shift                   (0)
#define  PLL27X_REG_DCLKSS_PROFILE2_dclk_profile_remap_5_mask                    (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE2_dclk_profile_remap_4_mask                    (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE2_dclk_profile_remap_5(data)                   (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE2_dclk_profile_remap_4(data)                   (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE2_get_dclk_profile_remap_5(data)               ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE2_get_dclk_profile_remap_4(data)               (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE3                                              0x18000668
#define  PLL27X_REG_DCLKSS_PROFILE3_reg_addr                                     "0xB8000668"
#define  PLL27X_REG_DCLKSS_PROFILE3_reg                                          0xB8000668
#define  PLL27X_REG_DCLKSS_PROFILE3_inst_addr                                    "0x0020"
#define  set_PLL27X_REG_DCLKSS_PROFILE3_reg(data)                                (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE3_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE3_reg                                      (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE3_reg))
#define  PLL27X_REG_DCLKSS_PROFILE3_dclk_profile_remap_7_shift                   (16)
#define  PLL27X_REG_DCLKSS_PROFILE3_dclk_profile_remap_6_shift                   (0)
#define  PLL27X_REG_DCLKSS_PROFILE3_dclk_profile_remap_7_mask                    (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE3_dclk_profile_remap_6_mask                    (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE3_dclk_profile_remap_7(data)                   (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE3_dclk_profile_remap_6(data)                   (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE3_get_dclk_profile_remap_7(data)               ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE3_get_dclk_profile_remap_6(data)               (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE4                                              0x1800066C
#define  PLL27X_REG_DCLKSS_PROFILE4_reg_addr                                     "0xB800066C"
#define  PLL27X_REG_DCLKSS_PROFILE4_reg                                          0xB800066C
#define  PLL27X_REG_DCLKSS_PROFILE4_inst_addr                                    "0x0021"
#define  set_PLL27X_REG_DCLKSS_PROFILE4_reg(data)                                (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE4_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE4_reg                                      (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE4_reg))
#define  PLL27X_REG_DCLKSS_PROFILE4_dclk_profile_remap_9_shift                   (16)
#define  PLL27X_REG_DCLKSS_PROFILE4_dclk_profile_remap_8_shift                   (0)
#define  PLL27X_REG_DCLKSS_PROFILE4_dclk_profile_remap_9_mask                    (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE4_dclk_profile_remap_8_mask                    (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE4_dclk_profile_remap_9(data)                   (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE4_dclk_profile_remap_8(data)                   (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE4_get_dclk_profile_remap_9(data)               ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE4_get_dclk_profile_remap_8(data)               (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE5                                              0x18000670
#define  PLL27X_REG_DCLKSS_PROFILE5_reg_addr                                     "0xB8000670"
#define  PLL27X_REG_DCLKSS_PROFILE5_reg                                          0xB8000670
#define  PLL27X_REG_DCLKSS_PROFILE5_inst_addr                                    "0x0022"
#define  set_PLL27X_REG_DCLKSS_PROFILE5_reg(data)                                (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE5_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE5_reg                                      (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE5_reg))
#define  PLL27X_REG_DCLKSS_PROFILE5_dclk_profile_remap_11_shift                  (16)
#define  PLL27X_REG_DCLKSS_PROFILE5_dclk_profile_remap_10_shift                  (0)
#define  PLL27X_REG_DCLKSS_PROFILE5_dclk_profile_remap_11_mask                   (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE5_dclk_profile_remap_10_mask                   (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE5_dclk_profile_remap_11(data)                  (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE5_dclk_profile_remap_10(data)                  (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE5_get_dclk_profile_remap_11(data)              ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE5_get_dclk_profile_remap_10(data)              (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE6                                              0x18000674
#define  PLL27X_REG_DCLKSS_PROFILE6_reg_addr                                     "0xB8000674"
#define  PLL27X_REG_DCLKSS_PROFILE6_reg                                          0xB8000674
#define  PLL27X_REG_DCLKSS_PROFILE6_inst_addr                                    "0x0023"
#define  set_PLL27X_REG_DCLKSS_PROFILE6_reg(data)                                (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE6_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE6_reg                                      (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE6_reg))
#define  PLL27X_REG_DCLKSS_PROFILE6_dclk_profile_remap_13_shift                  (16)
#define  PLL27X_REG_DCLKSS_PROFILE6_dclk_profile_remap_12_shift                  (0)
#define  PLL27X_REG_DCLKSS_PROFILE6_dclk_profile_remap_13_mask                   (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE6_dclk_profile_remap_12_mask                   (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE6_dclk_profile_remap_13(data)                  (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE6_dclk_profile_remap_12(data)                  (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE6_get_dclk_profile_remap_13(data)              ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE6_get_dclk_profile_remap_12(data)              (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE7                                              0x18000678
#define  PLL27X_REG_DCLKSS_PROFILE7_reg_addr                                     "0xB8000678"
#define  PLL27X_REG_DCLKSS_PROFILE7_reg                                          0xB8000678
#define  PLL27X_REG_DCLKSS_PROFILE7_inst_addr                                    "0x0024"
#define  set_PLL27X_REG_DCLKSS_PROFILE7_reg(data)                                (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE7_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE7_reg                                      (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE7_reg))
#define  PLL27X_REG_DCLKSS_PROFILE7_dclk_profile_remap_15_shift                  (16)
#define  PLL27X_REG_DCLKSS_PROFILE7_dclk_profile_remap_14_shift                  (0)
#define  PLL27X_REG_DCLKSS_PROFILE7_dclk_profile_remap_15_mask                   (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE7_dclk_profile_remap_14_mask                   (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE7_dclk_profile_remap_15(data)                  (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE7_dclk_profile_remap_14(data)                  (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE7_get_dclk_profile_remap_15(data)              ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE7_get_dclk_profile_remap_14(data)              (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE8                                              0x1800067C
#define  PLL27X_REG_DCLKSS_PROFILE8_reg_addr                                     "0xB800067C"
#define  PLL27X_REG_DCLKSS_PROFILE8_reg                                          0xB800067C
#define  PLL27X_REG_DCLKSS_PROFILE8_inst_addr                                    "0x0025"
#define  set_PLL27X_REG_DCLKSS_PROFILE8_reg(data)                                (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE8_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE8_reg                                      (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE8_reg))
#define  PLL27X_REG_DCLKSS_PROFILE8_dclk_profile_remap_17_shift                  (16)
#define  PLL27X_REG_DCLKSS_PROFILE8_dclk_profile_remap_16_shift                  (0)
#define  PLL27X_REG_DCLKSS_PROFILE8_dclk_profile_remap_17_mask                   (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE8_dclk_profile_remap_16_mask                   (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE8_dclk_profile_remap_17(data)                  (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE8_dclk_profile_remap_16(data)                  (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE8_get_dclk_profile_remap_17(data)              ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE8_get_dclk_profile_remap_16(data)              (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE9                                              0x18000680
#define  PLL27X_REG_DCLKSS_PROFILE9_reg_addr                                     "0xB8000680"
#define  PLL27X_REG_DCLKSS_PROFILE9_reg                                          0xB8000680
#define  PLL27X_REG_DCLKSS_PROFILE9_inst_addr                                    "0x0026"
#define  set_PLL27X_REG_DCLKSS_PROFILE9_reg(data)                                (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE9_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE9_reg                                      (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE9_reg))
#define  PLL27X_REG_DCLKSS_PROFILE9_dclk_profile_remap_19_shift                  (16)
#define  PLL27X_REG_DCLKSS_PROFILE9_dclk_profile_remap_18_shift                  (0)
#define  PLL27X_REG_DCLKSS_PROFILE9_dclk_profile_remap_19_mask                   (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE9_dclk_profile_remap_18_mask                   (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE9_dclk_profile_remap_19(data)                  (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE9_dclk_profile_remap_18(data)                  (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE9_get_dclk_profile_remap_19(data)              ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE9_get_dclk_profile_remap_18(data)              (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE10                                             0x18000684
#define  PLL27X_REG_DCLKSS_PROFILE10_reg_addr                                    "0xB8000684"
#define  PLL27X_REG_DCLKSS_PROFILE10_reg                                         0xB8000684
#define  PLL27X_REG_DCLKSS_PROFILE10_inst_addr                                   "0x0027"
#define  set_PLL27X_REG_DCLKSS_PROFILE10_reg(data)                               (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE10_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE10_reg                                     (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE10_reg))
#define  PLL27X_REG_DCLKSS_PROFILE10_dclk_profile_remap_21_shift                 (16)
#define  PLL27X_REG_DCLKSS_PROFILE10_dclk_profile_remap_20_shift                 (0)
#define  PLL27X_REG_DCLKSS_PROFILE10_dclk_profile_remap_21_mask                  (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE10_dclk_profile_remap_20_mask                  (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE10_dclk_profile_remap_21(data)                 (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE10_dclk_profile_remap_20(data)                 (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE10_get_dclk_profile_remap_21(data)             ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE10_get_dclk_profile_remap_20(data)             (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE11                                             0x18000688
#define  PLL27X_REG_DCLKSS_PROFILE11_reg_addr                                    "0xB8000688"
#define  PLL27X_REG_DCLKSS_PROFILE11_reg                                         0xB8000688
#define  PLL27X_REG_DCLKSS_PROFILE11_inst_addr                                   "0x0028"
#define  set_PLL27X_REG_DCLKSS_PROFILE11_reg(data)                               (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE11_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE11_reg                                     (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE11_reg))
#define  PLL27X_REG_DCLKSS_PROFILE11_dclk_profile_remap_23_shift                 (16)
#define  PLL27X_REG_DCLKSS_PROFILE11_dclk_profile_remap_22_shift                 (0)
#define  PLL27X_REG_DCLKSS_PROFILE11_dclk_profile_remap_23_mask                  (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE11_dclk_profile_remap_22_mask                  (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE11_dclk_profile_remap_23(data)                 (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE11_dclk_profile_remap_22(data)                 (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE11_get_dclk_profile_remap_23(data)             ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE11_get_dclk_profile_remap_22(data)             (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE12                                             0x1800068C
#define  PLL27X_REG_DCLKSS_PROFILE12_reg_addr                                    "0xB800068C"
#define  PLL27X_REG_DCLKSS_PROFILE12_reg                                         0xB800068C
#define  PLL27X_REG_DCLKSS_PROFILE12_inst_addr                                   "0x0029"
#define  set_PLL27X_REG_DCLKSS_PROFILE12_reg(data)                               (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE12_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE12_reg                                     (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE12_reg))
#define  PLL27X_REG_DCLKSS_PROFILE12_dclk_profile_remap_25_shift                 (16)
#define  PLL27X_REG_DCLKSS_PROFILE12_dclk_profile_remap_24_shift                 (0)
#define  PLL27X_REG_DCLKSS_PROFILE12_dclk_profile_remap_25_mask                  (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE12_dclk_profile_remap_24_mask                  (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE12_dclk_profile_remap_25(data)                 (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE12_dclk_profile_remap_24(data)                 (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE12_get_dclk_profile_remap_25(data)             ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE12_get_dclk_profile_remap_24(data)             (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE13                                             0x18000690
#define  PLL27X_REG_DCLKSS_PROFILE13_reg_addr                                    "0xB8000690"
#define  PLL27X_REG_DCLKSS_PROFILE13_reg                                         0xB8000690
#define  PLL27X_REG_DCLKSS_PROFILE13_inst_addr                                   "0x002A"
#define  set_PLL27X_REG_DCLKSS_PROFILE13_reg(data)                               (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE13_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE13_reg                                     (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE13_reg))
#define  PLL27X_REG_DCLKSS_PROFILE13_dclk_profile_remap_27_shift                 (16)
#define  PLL27X_REG_DCLKSS_PROFILE13_dclk_profile_remap_26_shift                 (0)
#define  PLL27X_REG_DCLKSS_PROFILE13_dclk_profile_remap_27_mask                  (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE13_dclk_profile_remap_26_mask                  (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE13_dclk_profile_remap_27(data)                 (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE13_dclk_profile_remap_26(data)                 (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE13_get_dclk_profile_remap_27(data)             ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE13_get_dclk_profile_remap_26(data)             (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE14                                             0x18000694
#define  PLL27X_REG_DCLKSS_PROFILE14_reg_addr                                    "0xB8000694"
#define  PLL27X_REG_DCLKSS_PROFILE14_reg                                         0xB8000694
#define  PLL27X_REG_DCLKSS_PROFILE14_inst_addr                                   "0x002B"
#define  set_PLL27X_REG_DCLKSS_PROFILE14_reg(data)                               (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE14_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE14_reg                                     (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE14_reg))
#define  PLL27X_REG_DCLKSS_PROFILE14_dclk_profile_remap_29_shift                 (16)
#define  PLL27X_REG_DCLKSS_PROFILE14_dclk_profile_remap_28_shift                 (0)
#define  PLL27X_REG_DCLKSS_PROFILE14_dclk_profile_remap_29_mask                  (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE14_dclk_profile_remap_28_mask                  (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE14_dclk_profile_remap_29(data)                 (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE14_dclk_profile_remap_28(data)                 (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE14_get_dclk_profile_remap_29(data)             ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE14_get_dclk_profile_remap_28(data)             (0x0000FFFF&(data))

#define  PLL27X_REG_DCLKSS_PROFILE15                                             0x18000698
#define  PLL27X_REG_DCLKSS_PROFILE15_reg_addr                                    "0xB8000698"
#define  PLL27X_REG_DCLKSS_PROFILE15_reg                                         0xB8000698
#define  PLL27X_REG_DCLKSS_PROFILE15_inst_addr                                   "0x002C"
#define  set_PLL27X_REG_DCLKSS_PROFILE15_reg(data)                               (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE15_reg)=data)
#define  get_PLL27X_REG_DCLKSS_PROFILE15_reg                                     (*((volatile unsigned int*)PLL27X_REG_DCLKSS_PROFILE15_reg))
#define  PLL27X_REG_DCLKSS_PROFILE15_dclk_profile_remap_31_shift                 (16)
#define  PLL27X_REG_DCLKSS_PROFILE15_dclk_profile_remap_30_shift                 (0)
#define  PLL27X_REG_DCLKSS_PROFILE15_dclk_profile_remap_31_mask                  (0xFFFF0000)
#define  PLL27X_REG_DCLKSS_PROFILE15_dclk_profile_remap_30_mask                  (0x0000FFFF)
#define  PLL27X_REG_DCLKSS_PROFILE15_dclk_profile_remap_31(data)                 (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DCLKSS_PROFILE15_dclk_profile_remap_30(data)                 (0x0000FFFF&(data))
#define  PLL27X_REG_DCLKSS_PROFILE15_get_dclk_profile_remap_31(data)             ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DCLKSS_PROFILE15_get_dclk_profile_remap_30(data)             (0x0000FFFF&(data))

#define  PLL27X_REG_dpll_Double_Buffer_CTRL                                      0x1800069C
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_reg_addr                             "0xB800069C"
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_reg                                  0xB800069C
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_inst_addr                            "0x002D"
#define  set_PLL27X_REG_dpll_Double_Buffer_CTRL_reg(data)                        (*((volatile unsigned int*)PLL27X_REG_dpll_Double_Buffer_CTRL_reg)=data)
#define  get_PLL27X_REG_dpll_Double_Buffer_CTRL_reg                              (*((volatile unsigned int*)PLL27X_REG_dpll_Double_Buffer_CTRL_reg))
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_double_buf_en_shift                  (2)
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_double_buf_read_sel_shift            (1)
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_double_buf_apply_shift               (0)
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_double_buf_en_mask                   (0x00000004)
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_double_buf_read_sel_mask             (0x00000002)
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_double_buf_apply_mask                (0x00000001)
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_double_buf_en(data)                  (0x00000004&((data)<<2))
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_double_buf_read_sel(data)            (0x00000002&((data)<<1))
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_double_buf_apply(data)               (0x00000001&(data))
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_get_double_buf_en(data)              ((0x00000004&(data))>>2)
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_get_double_buf_read_sel(data)        ((0x00000002&(data))>>1)
#define  PLL27X_REG_dpll_Double_Buffer_CTRL_get_double_buf_apply(data)           (0x00000001&(data))

#define  PLL27X_REG_PLL_SSC0                                                     0x180006A0
#define  PLL27X_REG_PLL_SSC0_reg_addr                                            "0xB80006A0"
#define  PLL27X_REG_PLL_SSC0_reg                                                 0xB80006A0
#define  PLL27X_REG_PLL_SSC0_inst_addr                                           "0x002E"
#define  set_PLL27X_REG_PLL_SSC0_reg(data)                                       (*((volatile unsigned int*)PLL27X_REG_PLL_SSC0_reg)=data)
#define  get_PLL27X_REG_PLL_SSC0_reg                                             (*((volatile unsigned int*)PLL27X_REG_PLL_SSC0_reg))
#define  PLL27X_REG_PLL_SSC0_fcode_t_ssc_shift                                   (16)
#define  PLL27X_REG_PLL_SSC0_oc_step_set_shift                                   (4)
#define  PLL27X_REG_PLL_SSC0_oc_en_shift                                         (0)
#define  PLL27X_REG_PLL_SSC0_fcode_t_ssc_mask                                    (0x07FF0000)
#define  PLL27X_REG_PLL_SSC0_oc_step_set_mask                                    (0x00003FF0)
#define  PLL27X_REG_PLL_SSC0_oc_en_mask                                          (0x00000001)
#define  PLL27X_REG_PLL_SSC0_fcode_t_ssc(data)                                   (0x07FF0000&((data)<<16))
#define  PLL27X_REG_PLL_SSC0_oc_step_set(data)                                   (0x00003FF0&((data)<<4))
#define  PLL27X_REG_PLL_SSC0_oc_en(data)                                         (0x00000001&(data))
#define  PLL27X_REG_PLL_SSC0_get_fcode_t_ssc(data)                               ((0x07FF0000&(data))>>16)
#define  PLL27X_REG_PLL_SSC0_get_oc_step_set(data)                               ((0x00003FF0&(data))>>4)
#define  PLL27X_REG_PLL_SSC0_get_oc_en(data)                                     (0x00000001&(data))

#define  PLL27X_REG_PLL_SSC1                                                     0x180006A4
#define  PLL27X_REG_PLL_SSC1_reg_addr                                            "0xB80006A4"
#define  PLL27X_REG_PLL_SSC1_reg                                                 0xB80006A4
#define  PLL27X_REG_PLL_SSC1_inst_addr                                           "0x002F"
#define  set_PLL27X_REG_PLL_SSC1_reg(data)                                       (*((volatile unsigned int*)PLL27X_REG_PLL_SSC1_reg)=data)
#define  get_PLL27X_REG_PLL_SSC1_reg                                             (*((volatile unsigned int*)PLL27X_REG_PLL_SSC1_reg))
#define  PLL27X_REG_PLL_SSC1_oc_done_delay_shift                                 (16)
#define  PLL27X_REG_PLL_SSC1_hs_oc_stop_diff_shift                               (12)
#define  PLL27X_REG_PLL_SSC1_sel_oc_mode_shift                                   (8)
#define  PLL27X_REG_PLL_SSC1_oc_done_delay_mask                                  (0x003F0000)
#define  PLL27X_REG_PLL_SSC1_hs_oc_stop_diff_mask                                (0x00003000)
#define  PLL27X_REG_PLL_SSC1_sel_oc_mode_mask                                    (0x00000300)
#define  PLL27X_REG_PLL_SSC1_oc_done_delay(data)                                 (0x003F0000&((data)<<16))
#define  PLL27X_REG_PLL_SSC1_hs_oc_stop_diff(data)                               (0x00003000&((data)<<12))
#define  PLL27X_REG_PLL_SSC1_sel_oc_mode(data)                                   (0x00000300&((data)<<8))
#define  PLL27X_REG_PLL_SSC1_get_oc_done_delay(data)                             ((0x003F0000&(data))>>16)
#define  PLL27X_REG_PLL_SSC1_get_hs_oc_stop_diff(data)                           ((0x00003000&(data))>>12)
#define  PLL27X_REG_PLL_SSC1_get_sel_oc_mode(data)                               ((0x00000300&(data))>>8)

#define  PLL27X_REG_PLL_SSC2                                                     0x180006A8
#define  PLL27X_REG_PLL_SSC2_reg_addr                                            "0xB80006A8"
#define  PLL27X_REG_PLL_SSC2_reg                                                 0xB80006A8
#define  PLL27X_REG_PLL_SSC2_inst_addr                                           "0x0030"
#define  set_PLL27X_REG_PLL_SSC2_reg(data)                                       (*((volatile unsigned int*)PLL27X_REG_PLL_SSC2_reg)=data)
#define  get_PLL27X_REG_PLL_SSC2_reg                                             (*((volatile unsigned int*)PLL27X_REG_PLL_SSC2_reg))
#define  PLL27X_REG_PLL_SSC2_en_pi_debug_shift                                   (2)
#define  PLL27X_REG_PLL_SSC2_sdm_order_shift                                     (1)
#define  PLL27X_REG_PLL_SSC2_bypass_pi_shift                                     (0)
#define  PLL27X_REG_PLL_SSC2_en_pi_debug_mask                                    (0x00000004)
#define  PLL27X_REG_PLL_SSC2_sdm_order_mask                                      (0x00000002)
#define  PLL27X_REG_PLL_SSC2_bypass_pi_mask                                      (0x00000001)
#define  PLL27X_REG_PLL_SSC2_en_pi_debug(data)                                   (0x00000004&((data)<<2))
#define  PLL27X_REG_PLL_SSC2_sdm_order(data)                                     (0x00000002&((data)<<1))
#define  PLL27X_REG_PLL_SSC2_bypass_pi(data)                                     (0x00000001&(data))
#define  PLL27X_REG_PLL_SSC2_get_en_pi_debug(data)                               ((0x00000004&(data))>>2)
#define  PLL27X_REG_PLL_SSC2_get_sdm_order(data)                                 ((0x00000002&(data))>>1)
#define  PLL27X_REG_PLL_SSC2_get_bypass_pi(data)                                 (0x00000001&(data))

#define  PLL27X_REG_PLL_SSC3                                                     0x180006AC
#define  PLL27X_REG_PLL_SSC3_reg_addr                                            "0xB80006AC"
#define  PLL27X_REG_PLL_SSC3_reg                                                 0xB80006AC
#define  PLL27X_REG_PLL_SSC3_inst_addr                                           "0x0031"
#define  set_PLL27X_REG_PLL_SSC3_reg(data)                                       (*((volatile unsigned int*)PLL27X_REG_PLL_SSC3_reg)=data)
#define  get_PLL27X_REG_PLL_SSC3_reg                                             (*((volatile unsigned int*)PLL27X_REG_PLL_SSC3_reg))
#define  PLL27X_REG_PLL_SSC3_ncode_ssc_shift                                     (16)
#define  PLL27X_REG_PLL_SSC3_fcode_ssc_shift                                     (0)
#define  PLL27X_REG_PLL_SSC3_ncode_ssc_mask                                      (0x00FF0000)
#define  PLL27X_REG_PLL_SSC3_fcode_ssc_mask                                      (0x000007FF)
#define  PLL27X_REG_PLL_SSC3_ncode_ssc(data)                                     (0x00FF0000&((data)<<16))
#define  PLL27X_REG_PLL_SSC3_fcode_ssc(data)                                     (0x000007FF&(data))
#define  PLL27X_REG_PLL_SSC3_get_ncode_ssc(data)                                 ((0x00FF0000&(data))>>16)
#define  PLL27X_REG_PLL_SSC3_get_fcode_ssc(data)                                 (0x000007FF&(data))

#define  PLL27X_REG_PLL_SSC4                                                     0x180006B0
#define  PLL27X_REG_PLL_SSC4_reg_addr                                            "0xB80006B0"
#define  PLL27X_REG_PLL_SSC4_reg                                                 0xB80006B0
#define  PLL27X_REG_PLL_SSC4_inst_addr                                           "0x0032"
#define  set_PLL27X_REG_PLL_SSC4_reg(data)                                       (*((volatile unsigned int*)PLL27X_REG_PLL_SSC4_reg)=data)
#define  get_PLL27X_REG_PLL_SSC4_reg                                             (*((volatile unsigned int*)PLL27X_REG_PLL_SSC4_reg))
#define  PLL27X_REG_PLL_SSC4_gran_auto_rst_shift                                 (28)
#define  PLL27X_REG_PLL_SSC4_dot_gran_shift                                      (24)
#define  PLL27X_REG_PLL_SSC4_gran_est_shift                                      (4)
#define  PLL27X_REG_PLL_SSC4_en_ssc_shift                                        (0)
#define  PLL27X_REG_PLL_SSC4_gran_auto_rst_mask                                  (0x10000000)
#define  PLL27X_REG_PLL_SSC4_dot_gran_mask                                       (0x07000000)
#define  PLL27X_REG_PLL_SSC4_gran_est_mask                                       (0x007FFFF0)
#define  PLL27X_REG_PLL_SSC4_en_ssc_mask                                         (0x00000001)
#define  PLL27X_REG_PLL_SSC4_gran_auto_rst(data)                                 (0x10000000&((data)<<28))
#define  PLL27X_REG_PLL_SSC4_dot_gran(data)                                      (0x07000000&((data)<<24))
#define  PLL27X_REG_PLL_SSC4_gran_est(data)                                      (0x007FFFF0&((data)<<4))
#define  PLL27X_REG_PLL_SSC4_en_ssc(data)                                        (0x00000001&(data))
#define  PLL27X_REG_PLL_SSC4_get_gran_auto_rst(data)                             ((0x10000000&(data))>>28)
#define  PLL27X_REG_PLL_SSC4_get_dot_gran(data)                                  ((0x07000000&(data))>>24)
#define  PLL27X_REG_PLL_SSC4_get_gran_est(data)                                  ((0x007FFFF0&(data))>>4)
#define  PLL27X_REG_PLL_SSC4_get_en_ssc(data)                                    (0x00000001&(data))

#define  PLL27X_REG_PLL_SSC5                                                     0x180006B4
#define  PLL27X_REG_PLL_SSC5_reg_addr                                            "0xB80006B4"
#define  PLL27X_REG_PLL_SSC5_reg                                                 0xB80006B4
#define  PLL27X_REG_PLL_SSC5_inst_addr                                           "0x0033"
#define  set_PLL27X_REG_PLL_SSC5_reg(data)                                       (*((volatile unsigned int*)PLL27X_REG_PLL_SSC5_reg)=data)
#define  get_PLL27X_REG_PLL_SSC5_reg                                             (*((volatile unsigned int*)PLL27X_REG_PLL_SSC5_reg))
#define  PLL27X_REG_PLL_SSC5_fcode_debug_shift                                   (16)
#define  PLL27X_REG_PLL_SSC5_ncode_debug_shift                                   (8)
#define  PLL27X_REG_PLL_SSC5_oc_done_shift                                       (4)
#define  PLL27X_REG_PLL_SSC5_load_fcw_shift                                      (1)
#define  PLL27X_REG_PLL_SSC5_fmod_shift                                          (0)
#define  PLL27X_REG_PLL_SSC5_fcode_debug_mask                                    (0x07FF0000)
#define  PLL27X_REG_PLL_SSC5_ncode_debug_mask                                    (0x0000FF00)
#define  PLL27X_REG_PLL_SSC5_oc_done_mask                                        (0x00000010)
#define  PLL27X_REG_PLL_SSC5_load_fcw_mask                                       (0x00000002)
#define  PLL27X_REG_PLL_SSC5_fmod_mask                                           (0x00000001)
#define  PLL27X_REG_PLL_SSC5_fcode_debug(data)                                   (0x07FF0000&((data)<<16))
#define  PLL27X_REG_PLL_SSC5_ncode_debug(data)                                   (0x0000FF00&((data)<<8))
#define  PLL27X_REG_PLL_SSC5_oc_done(data)                                       (0x00000010&((data)<<4))
#define  PLL27X_REG_PLL_SSC5_load_fcw(data)                                      (0x00000002&((data)<<1))
#define  PLL27X_REG_PLL_SSC5_fmod(data)                                          (0x00000001&(data))
#define  PLL27X_REG_PLL_SSC5_get_fcode_debug(data)                               ((0x07FF0000&(data))>>16)
#define  PLL27X_REG_PLL_SSC5_get_ncode_debug(data)                               ((0x0000FF00&(data))>>8)
#define  PLL27X_REG_PLL_SSC5_get_oc_done(data)                                   ((0x00000010&(data))>>4)
#define  PLL27X_REG_PLL_SSC5_get_load_fcw(data)                                  ((0x00000002&(data))>>1)
#define  PLL27X_REG_PLL_SSC5_get_fmod(data)                                      (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_DISP1                                                0x180006C0
#define  PLL27X_REG_SYS_PLL_DISP1_reg_addr                                       "0xB80006C0"
#define  PLL27X_REG_SYS_PLL_DISP1_reg                                            0xB80006C0
#define  PLL27X_REG_SYS_PLL_DISP1_inst_addr                                      "0x0034"
#define  set_PLL27X_REG_SYS_PLL_DISP1_reg(data)                                  (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DISP1_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_DISP1_reg                                        (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DISP1_reg))
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_m_shift                                   (20)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_n_shift                                   (12)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_ip_shift                                  (8)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_ssc_inv_shift                             (7)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_rs_shift                                  (4)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_cp_shift                                  (2)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_cs_shift                                  (0)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_m_mask                                    (0x0FF00000)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_n_mask                                    (0x00007000)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_ip_mask                                   (0x00000700)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_ssc_inv_mask                              (0x00000080)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_rs_mask                                   (0x00000070)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_cp_mask                                   (0x0000000C)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_cs_mask                                   (0x00000003)
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_m(data)                                   (0x0FF00000&((data)<<20))
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_n(data)                                   (0x00007000&((data)<<12))
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_ip(data)                                  (0x00000700&((data)<<8))
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_ssc_inv(data)                             (0x00000080&((data)<<7))
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_rs(data)                                  (0x00000070&((data)<<4))
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_cp(data)                                  (0x0000000C&((data)<<2))
#define  PLL27X_REG_SYS_PLL_DISP1_dpll_cs(data)                                  (0x00000003&(data))
#define  PLL27X_REG_SYS_PLL_DISP1_get_dpll_m(data)                               ((0x0FF00000&(data))>>20)
#define  PLL27X_REG_SYS_PLL_DISP1_get_dpll_n(data)                               ((0x00007000&(data))>>12)
#define  PLL27X_REG_SYS_PLL_DISP1_get_dpll_ip(data)                              ((0x00000700&(data))>>8)
#define  PLL27X_REG_SYS_PLL_DISP1_get_dpll_ssc_inv(data)                         ((0x00000080&(data))>>7)
#define  PLL27X_REG_SYS_PLL_DISP1_get_dpll_rs(data)                              ((0x00000070&(data))>>4)
#define  PLL27X_REG_SYS_PLL_DISP1_get_dpll_cp(data)                              ((0x0000000C&(data))>>2)
#define  PLL27X_REG_SYS_PLL_DISP1_get_dpll_cs(data)                              (0x00000003&(data))

#define  PLL27X_REG_SYS_PLL_DISP2                                                0x180006C4
#define  PLL27X_REG_SYS_PLL_DISP2_reg_addr                                       "0xB80006C4"
#define  PLL27X_REG_SYS_PLL_DISP2_reg                                            0xB80006C4
#define  PLL27X_REG_SYS_PLL_DISP2_inst_addr                                      "0x0035"
#define  set_PLL27X_REG_SYS_PLL_DISP2_reg(data)                                  (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DISP2_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_DISP2_reg                                        (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DISP2_reg))
#define  PLL27X_REG_SYS_PLL_DISP2_dpll_x_bpspi_shift                             (1)
#define  PLL27X_REG_SYS_PLL_DISP2_dpll_x_bpsin_shift                             (0)
#define  PLL27X_REG_SYS_PLL_DISP2_dpll_x_bpspi_mask                              (0x00000002)
#define  PLL27X_REG_SYS_PLL_DISP2_dpll_x_bpsin_mask                              (0x00000001)
#define  PLL27X_REG_SYS_PLL_DISP2_dpll_x_bpspi(data)                             (0x00000002&((data)<<1))
#define  PLL27X_REG_SYS_PLL_DISP2_dpll_x_bpsin(data)                             (0x00000001&(data))
#define  PLL27X_REG_SYS_PLL_DISP2_get_dpll_x_bpspi(data)                         ((0x00000002&(data))>>1)
#define  PLL27X_REG_SYS_PLL_DISP2_get_dpll_x_bpsin(data)                         (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_DISP3                                                0x180006C8
#define  PLL27X_REG_SYS_PLL_DISP3_reg_addr                                       "0xB80006C8"
#define  PLL27X_REG_SYS_PLL_DISP3_reg                                            0xB80006C8
#define  PLL27X_REG_SYS_PLL_DISP3_inst_addr                                      "0x0036"
#define  set_PLL27X_REG_SYS_PLL_DISP3_reg(data)                                  (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DISP3_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_DISP3_reg                                        (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DISP3_reg))
#define  PLL27X_REG_SYS_PLL_DISP3_pif_dpll_src_sel_shift                         (31)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_ldosel_shift                              (28)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_reser_shift                               (24)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_dummy_shift                               (20)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_picap_shift                               (18)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_prescaler_shift                           (17)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_test_en_shift                             (16)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_o_shift                                   (12)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_rstb_shift                                (6)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_wdrst_shift                               (5)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_wdset_shift                               (4)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_freeze_shift                              (2)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_vcorstb_shift                             (1)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_pow_shift                                 (0)
#define  PLL27X_REG_SYS_PLL_DISP3_pif_dpll_src_sel_mask                          (0x80000000)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_ldosel_mask                               (0x30000000)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_reser_mask                                (0x0F000000)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_dummy_mask                                (0x00700000)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_picap_mask                                (0x00040000)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_prescaler_mask                            (0x00020000)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_test_en_mask                              (0x00010000)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_o_mask                                    (0x00003000)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_rstb_mask                                 (0x00000040)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_wdrst_mask                                (0x00000020)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_wdset_mask                                (0x00000010)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_freeze_mask                               (0x00000004)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_vcorstb_mask                              (0x00000002)
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_pow_mask                                  (0x00000001)
#define  PLL27X_REG_SYS_PLL_DISP3_pif_dpll_src_sel(data)                         (0x80000000&((data)<<31))
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_ldosel(data)                              (0x30000000&((data)<<28))
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_reser(data)                               (0x0F000000&((data)<<24))
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_dummy(data)                               (0x00700000&((data)<<20))
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_picap(data)                               (0x00040000&((data)<<18))
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_prescaler(data)                           (0x00020000&((data)<<17))
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_test_en(data)                             (0x00010000&((data)<<16))
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_o(data)                                   (0x00003000&((data)<<12))
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_rstb(data)                                (0x00000040&((data)<<6))
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_wdrst(data)                               (0x00000020&((data)<<5))
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_wdset(data)                               (0x00000010&((data)<<4))
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_freeze(data)                              (0x00000004&((data)<<2))
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_vcorstb(data)                             (0x00000002&((data)<<1))
#define  PLL27X_REG_SYS_PLL_DISP3_dpll_pow(data)                                 (0x00000001&(data))
#define  PLL27X_REG_SYS_PLL_DISP3_get_pif_dpll_src_sel(data)                     ((0x80000000&(data))>>31)
#define  PLL27X_REG_SYS_PLL_DISP3_get_dpll_ldosel(data)                          ((0x30000000&(data))>>28)
#define  PLL27X_REG_SYS_PLL_DISP3_get_dpll_reser(data)                           ((0x0F000000&(data))>>24)
#define  PLL27X_REG_SYS_PLL_DISP3_get_dpll_dummy(data)                           ((0x00700000&(data))>>20)
#define  PLL27X_REG_SYS_PLL_DISP3_get_dpll_picap(data)                           ((0x00040000&(data))>>18)
#define  PLL27X_REG_SYS_PLL_DISP3_get_dpll_prescaler(data)                       ((0x00020000&(data))>>17)
#define  PLL27X_REG_SYS_PLL_DISP3_get_dpll_test_en(data)                         ((0x00010000&(data))>>16)
#define  PLL27X_REG_SYS_PLL_DISP3_get_dpll_o(data)                               ((0x00003000&(data))>>12)
#define  PLL27X_REG_SYS_PLL_DISP3_get_dpll_rstb(data)                            ((0x00000040&(data))>>6)
#define  PLL27X_REG_SYS_PLL_DISP3_get_dpll_wdrst(data)                           ((0x00000020&(data))>>5)
#define  PLL27X_REG_SYS_PLL_DISP3_get_dpll_wdset(data)                           ((0x00000010&(data))>>4)
#define  PLL27X_REG_SYS_PLL_DISP3_get_dpll_freeze(data)                          ((0x00000004&(data))>>2)
#define  PLL27X_REG_SYS_PLL_DISP3_get_dpll_vcorstb(data)                         ((0x00000002&(data))>>1)
#define  PLL27X_REG_SYS_PLL_DISP3_get_dpll_pow(data)                             (0x00000001&(data))

#define  PLL27X_REG_SYS_PLL_DISP4                                                0x180006CC
#define  PLL27X_REG_SYS_PLL_DISP4_reg_addr                                       "0xB80006CC"
#define  PLL27X_REG_SYS_PLL_DISP4_reg                                            0xB80006CC
#define  PLL27X_REG_SYS_PLL_DISP4_inst_addr                                      "0x0037"
#define  set_PLL27X_REG_SYS_PLL_DISP4_reg(data)                                  (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DISP4_reg)=data)
#define  get_PLL27X_REG_SYS_PLL_DISP4_reg                                        (*((volatile unsigned int*)PLL27X_REG_SYS_PLL_DISP4_reg))
#define  PLL27X_REG_SYS_PLL_DISP4_dpll_ldodpll_pow_shift                         (2)
#define  PLL27X_REG_SYS_PLL_DISP4_dpll_pi_ibsel_shift                            (0)
#define  PLL27X_REG_SYS_PLL_DISP4_dpll_ldodpll_pow_mask                          (0x00000004)
#define  PLL27X_REG_SYS_PLL_DISP4_dpll_pi_ibsel_mask                             (0x00000003)
#define  PLL27X_REG_SYS_PLL_DISP4_dpll_ldodpll_pow(data)                         (0x00000004&((data)<<2))
#define  PLL27X_REG_SYS_PLL_DISP4_dpll_pi_ibsel(data)                            (0x00000003&(data))
#define  PLL27X_REG_SYS_PLL_DISP4_get_dpll_ldodpll_pow(data)                     ((0x00000004&(data))>>2)
#define  PLL27X_REG_SYS_PLL_DISP4_get_dpll_pi_ibsel(data)                        (0x00000003&(data))

#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0                                0x180006D0
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_reg_addr                       "0xB80006D0"
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_reg                            0xB80006D0
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_inst_addr                      "0x0038"
#define  set_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_reg(data)                  (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_reg)=data)
#define  get_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_reg                        (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_reg))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_sscg_offset_over_flag_shift    (31)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_sscg_offset_over_th_value_shift (0)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_sscg_offset_over_flag_mask     (0x80000000)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_sscg_offset_over_th_value_mask (0x0001FFFF)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_sscg_offset_over_flag(data)    (0x80000000&((data)<<31))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_sscg_offset_over_th_value(data) (0x0001FFFF&(data))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_get_sscg_offset_over_flag(data) ((0x80000000&(data))>>31)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug0_get_sscg_offset_over_th_value(data) (0x0001FFFF&(data))

#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug1                                0x180006D4
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug1_reg_addr                       "0xB80006D4"
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug1_reg                            0xB80006D4
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug1_inst_addr                      "0x0039"
#define  set_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug1_reg(data)                  (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug1_reg)=data)
#define  get_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug1_reg                        (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug1_reg))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug1_sscg_offset_over_th_max_shift  (0)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug1_sscg_offset_over_th_max_mask   (0x0001FFFF)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug1_sscg_offset_over_th_max(data)  (0x0001FFFF&(data))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug1_get_sscg_offset_over_th_max(data) (0x0001FFFF&(data))

#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2                                0x180006D8
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_reg_addr                       "0xB80006D8"
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_reg                            0xB80006D8
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_inst_addr                      "0x003A"
#define  set_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_reg(data)                  (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_reg)=data)
#define  get_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_reg                        (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_reg))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_new_fll_offset_over_flag_shift (31)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_new_fll_offset_over_th_value_shift (0)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_new_fll_offset_over_flag_mask  (0x80000000)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_new_fll_offset_over_th_value_mask (0x0001FFFF)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_new_fll_offset_over_flag(data) (0x80000000&((data)<<31))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_new_fll_offset_over_th_value(data) (0x0001FFFF&(data))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_get_new_fll_offset_over_flag(data) ((0x80000000&(data))>>31)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug2_get_new_fll_offset_over_th_value(data) (0x0001FFFF&(data))

#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug3                                0x180006DC
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug3_reg_addr                       "0xB80006DC"
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug3_reg                            0xB80006DC
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug3_inst_addr                      "0x003B"
#define  set_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug3_reg(data)                  (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug3_reg)=data)
#define  get_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug3_reg                        (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug3_reg))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug3_new_fll_offset_over_th_max_shift (0)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug3_new_fll_offset_over_th_max_mask (0x0001FFFF)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug3_new_fll_offset_over_th_max(data) (0x0001FFFF&(data))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_debug3_get_new_fll_offset_over_th_max(data) (0x0001FFFF&(data))

#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4                                 0x180006E0
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_reg_addr                        "0xB80006E0"
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_reg                             0xB80006E0
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_inst_addr                       "0x003C"
#define  set_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_reg(data)                   (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_reg)=data)
#define  get_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_reg                         (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_reg))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_offset_inverse_shift (20)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_mul_shift      (0)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_offset_inverse_mask (0x00100000)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_mul_mask       (0x0007FFFF)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_offset_inverse(data) (0x00100000&((data)<<20))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_mul(data)      (0x0007FFFF&(data))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_get_new_fll_tracking_offset_inverse(data) ((0x00100000&(data))>>20)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_get_new_fll_tracking_mul(data)  (0x0007FFFF&(data))

#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5                                 0x180006E4
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_reg_addr                        "0xB80006E4"
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_reg                             0xB80006E4
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_inst_addr                       "0x003D"
#define  set_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_reg(data)                   (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_reg)=data)
#define  get_PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_reg                         (*((volatile unsigned int*)PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_reg))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_neg_th_shift   (16)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_pos_th_shift   (0)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_neg_th_mask    (0xFFFF0000)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_pos_th_mask    (0x0000FFFF)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_neg_th(data)   (0xFFFF0000&((data)<<16))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_pos_th(data)   (0x0000FFFF&(data))
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_get_new_fll_tracking_neg_th(data) ((0xFFFF0000&(data))>>16)
#define  PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL5_get_new_fll_tracking_pos_th(data) (0x0000FFFF&(data))

#define  PLL27X_REG_EMMC_PLL_SET                                                 0x18000700
#define  PLL27X_REG_EMMC_PLL_SET_reg_addr                                        "0xB8000700"
#define  PLL27X_REG_EMMC_PLL_SET_reg                                             0xB8000700
#define  PLL27X_REG_EMMC_PLL_SET_inst_addr                                       "0x003E"
#define  set_PLL27X_REG_EMMC_PLL_SET_reg(data)                                   (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SET_reg)=data)
#define  get_PLL27X_REG_EMMC_PLL_SET_reg                                         (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SET_reg))
#define  PLL27X_REG_EMMC_PLL_SET_pll_emmc_ckssc_inv_shift                        (30)
#define  PLL27X_REG_EMMC_PLL_SET_pllscp_shift                                    (29)
#define  PLL27X_REG_EMMC_PLL_SET_pllscs_shift                                    (27)
#define  PLL27X_REG_EMMC_PLL_SET_pllsrs_shift                                    (24)
#define  PLL27X_REG_EMMC_PLL_SET_pllsdiv2_shift                                  (17)
#define  PLL27X_REG_EMMC_PLL_SET_pllssi_shift                                    (12)
#define  PLL27X_REG_EMMC_PLL_SET_pllsnbp_shift                                   (11)
#define  PLL27X_REG_EMMC_PLL_SET_pllsn_shift                                     (8)
#define  PLL27X_REG_EMMC_PLL_SET_pllallrstb_shift                                (0)
#define  PLL27X_REG_EMMC_PLL_SET_pll_emmc_ckssc_inv_mask                         (0x40000000)
#define  PLL27X_REG_EMMC_PLL_SET_pllscp_mask                                     (0x20000000)
#define  PLL27X_REG_EMMC_PLL_SET_pllscs_mask                                     (0x18000000)
#define  PLL27X_REG_EMMC_PLL_SET_pllsrs_mask                                     (0x07000000)
#define  PLL27X_REG_EMMC_PLL_SET_pllsdiv2_mask                                   (0x00020000)
#define  PLL27X_REG_EMMC_PLL_SET_pllssi_mask                                     (0x0001F000)
#define  PLL27X_REG_EMMC_PLL_SET_pllsnbp_mask                                    (0x00000800)
#define  PLL27X_REG_EMMC_PLL_SET_pllsn_mask                                      (0x00000700)
#define  PLL27X_REG_EMMC_PLL_SET_pllallrstb_mask                                 (0x00000001)
#define  PLL27X_REG_EMMC_PLL_SET_pll_emmc_ckssc_inv(data)                        (0x40000000&((data)<<30))
#define  PLL27X_REG_EMMC_PLL_SET_pllscp(data)                                    (0x20000000&((data)<<29))
#define  PLL27X_REG_EMMC_PLL_SET_pllscs(data)                                    (0x18000000&((data)<<27))
#define  PLL27X_REG_EMMC_PLL_SET_pllsrs(data)                                    (0x07000000&((data)<<24))
#define  PLL27X_REG_EMMC_PLL_SET_pllsdiv2(data)                                  (0x00020000&((data)<<17))
#define  PLL27X_REG_EMMC_PLL_SET_pllssi(data)                                    (0x0001F000&((data)<<12))
#define  PLL27X_REG_EMMC_PLL_SET_pllsnbp(data)                                   (0x00000800&((data)<<11))
#define  PLL27X_REG_EMMC_PLL_SET_pllsn(data)                                     (0x00000700&((data)<<8))
#define  PLL27X_REG_EMMC_PLL_SET_pllallrstb(data)                                (0x00000001&(data))
#define  PLL27X_REG_EMMC_PLL_SET_get_pll_emmc_ckssc_inv(data)                    ((0x40000000&(data))>>30)
#define  PLL27X_REG_EMMC_PLL_SET_get_pllscp(data)                                ((0x20000000&(data))>>29)
#define  PLL27X_REG_EMMC_PLL_SET_get_pllscs(data)                                ((0x18000000&(data))>>27)
#define  PLL27X_REG_EMMC_PLL_SET_get_pllsrs(data)                                ((0x07000000&(data))>>24)
#define  PLL27X_REG_EMMC_PLL_SET_get_pllsdiv2(data)                              ((0x00020000&(data))>>17)
#define  PLL27X_REG_EMMC_PLL_SET_get_pllssi(data)                                ((0x0001F000&(data))>>12)
#define  PLL27X_REG_EMMC_PLL_SET_get_pllsnbp(data)                               ((0x00000800&(data))>>11)
#define  PLL27X_REG_EMMC_PLL_SET_get_pllsn(data)                                 ((0x00000700&(data))>>8)
#define  PLL27X_REG_EMMC_PLL_SET_get_pllallrstb(data)                            (0x00000001&(data))

#define  PLL27X_REG_EMMC_PLL_CTRL                                                0x18000704
#define  PLL27X_REG_EMMC_PLL_CTRL_reg_addr                                       "0xB8000704"
#define  PLL27X_REG_EMMC_PLL_CTRL_reg                                            0xB8000704
#define  PLL27X_REG_EMMC_PLL_CTRL_inst_addr                                      "0x003F"
#define  set_PLL27X_REG_EMMC_PLL_CTRL_reg(data)                                  (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_CTRL_reg)=data)
#define  get_PLL27X_REG_EMMC_PLL_CTRL_reg                                        (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_CTRL_reg))
#define  PLL27X_REG_EMMC_PLL_CTRL_reg_pllemmc_bpspi_shift                        (23)
#define  PLL27X_REG_EMMC_PLL_CTRL_reg_pll_tp2_mux_shift                          (20)
#define  PLL27X_REG_EMMC_PLL_CTRL_reg_pll_tp1_mux_shift                          (17)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllemmc_rsvd_shift                             (8)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllsstatus_shift                               (6)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllswdrst_shift                                (5)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllswdset_shift                                (4)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllemmc_reg_shift                              (2)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllemmcldopow_shift                            (1)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllemmcpwdn_shift                              (0)
#define  PLL27X_REG_EMMC_PLL_CTRL_reg_pllemmc_bpspi_mask                         (0x00800000)
#define  PLL27X_REG_EMMC_PLL_CTRL_reg_pll_tp2_mux_mask                           (0x00700000)
#define  PLL27X_REG_EMMC_PLL_CTRL_reg_pll_tp1_mux_mask                           (0x000E0000)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllemmc_rsvd_mask                              (0x0000FF00)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllsstatus_mask                                (0x00000040)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllswdrst_mask                                 (0x00000020)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllswdset_mask                                 (0x00000010)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllemmc_reg_mask                               (0x0000000C)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllemmcldopow_mask                             (0x00000002)
#define  PLL27X_REG_EMMC_PLL_CTRL_pllemmcpwdn_mask                               (0x00000001)
#define  PLL27X_REG_EMMC_PLL_CTRL_reg_pllemmc_bpspi(data)                        (0x00800000&((data)<<23))
#define  PLL27X_REG_EMMC_PLL_CTRL_reg_pll_tp2_mux(data)                          (0x00700000&((data)<<20))
#define  PLL27X_REG_EMMC_PLL_CTRL_reg_pll_tp1_mux(data)                          (0x000E0000&((data)<<17))
#define  PLL27X_REG_EMMC_PLL_CTRL_pllemmc_rsvd(data)                             (0x0000FF00&((data)<<8))
#define  PLL27X_REG_EMMC_PLL_CTRL_pllsstatus(data)                               (0x00000040&((data)<<6))
#define  PLL27X_REG_EMMC_PLL_CTRL_pllswdrst(data)                                (0x00000020&((data)<<5))
#define  PLL27X_REG_EMMC_PLL_CTRL_pllswdset(data)                                (0x00000010&((data)<<4))
#define  PLL27X_REG_EMMC_PLL_CTRL_pllemmc_reg(data)                              (0x0000000C&((data)<<2))
#define  PLL27X_REG_EMMC_PLL_CTRL_pllemmcldopow(data)                            (0x00000002&((data)<<1))
#define  PLL27X_REG_EMMC_PLL_CTRL_pllemmcpwdn(data)                              (0x00000001&(data))
#define  PLL27X_REG_EMMC_PLL_CTRL_get_reg_pllemmc_bpspi(data)                    ((0x00800000&(data))>>23)
#define  PLL27X_REG_EMMC_PLL_CTRL_get_reg_pll_tp2_mux(data)                      ((0x00700000&(data))>>20)
#define  PLL27X_REG_EMMC_PLL_CTRL_get_reg_pll_tp1_mux(data)                      ((0x000E0000&(data))>>17)
#define  PLL27X_REG_EMMC_PLL_CTRL_get_pllemmc_rsvd(data)                         ((0x0000FF00&(data))>>8)
#define  PLL27X_REG_EMMC_PLL_CTRL_get_pllsstatus(data)                           ((0x00000040&(data))>>6)
#define  PLL27X_REG_EMMC_PLL_CTRL_get_pllswdrst(data)                            ((0x00000020&(data))>>5)
#define  PLL27X_REG_EMMC_PLL_CTRL_get_pllswdset(data)                            ((0x00000010&(data))>>4)
#define  PLL27X_REG_EMMC_PLL_CTRL_get_pllemmc_reg(data)                          ((0x0000000C&(data))>>2)
#define  PLL27X_REG_EMMC_PLL_CTRL_get_pllemmcldopow(data)                        ((0x00000002&(data))>>1)
#define  PLL27X_REG_EMMC_PLL_CTRL_get_pllemmcpwdn(data)                          (0x00000001&(data))

#define  PLL27X_REG_EMMC_PLLPHASE_CTRL                                           0x18000708
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_reg_addr                                  "0xB8000708"
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_reg                                       0xB8000708
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_inst_addr                                 "0x0040"
#define  set_PLL27X_REG_EMMC_PLLPHASE_CTRL_reg(data)                             (*((volatile unsigned int*)PLL27X_REG_EMMC_PLLPHASE_CTRL_reg)=data)
#define  get_PLL27X_REG_EMMC_PLLPHASE_CTRL_reg                                   (*((volatile unsigned int*)PLL27X_REG_EMMC_PLLPHASE_CTRL_reg))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pll_pi_autoset_shift                      (30)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2x_3_shift                           (29)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2y_3_shift                           (28)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsx_3_shift                             (27)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsy_3_shift                             (26)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllssck_3_shift                           (20)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2x_2_shift                           (19)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2y_2_shift                           (18)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsx_2_shift                             (17)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsy_2_shift                             (16)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllssck_2_shift                           (10)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2x_shift                             (9)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2y_shift                             (8)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsx_shift                               (7)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsy_shift                               (6)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllssck_shift                             (0)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pll_pi_autoset_mask                       (0x40000000)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2x_3_mask                            (0x20000000)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2y_3_mask                            (0x10000000)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsx_3_mask                              (0x08000000)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsy_3_mask                              (0x04000000)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllssck_3_mask                            (0x03F00000)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2x_2_mask                            (0x00080000)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2y_2_mask                            (0x00040000)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsx_2_mask                              (0x00020000)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsy_2_mask                              (0x00010000)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllssck_2_mask                            (0x0000FC00)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2x_mask                              (0x00000200)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2y_mask                              (0x00000100)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsx_mask                                (0x00000080)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsy_mask                                (0x00000040)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllssck_mask                              (0x0000003F)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pll_pi_autoset(data)                      (0x40000000&((data)<<30))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2x_3(data)                           (0x20000000&((data)<<29))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2y_3(data)                           (0x10000000&((data)<<28))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsx_3(data)                             (0x08000000&((data)<<27))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsy_3(data)                             (0x04000000&((data)<<26))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllssck_3(data)                           (0x03F00000&((data)<<20))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2x_2(data)                           (0x00080000&((data)<<19))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2y_2(data)                           (0x00040000&((data)<<18))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsx_2(data)                             (0x00020000&((data)<<17))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsy_2(data)                             (0x00010000&((data)<<16))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllssck_2(data)                           (0x0000FC00&((data)<<10))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2x(data)                             (0x00000200&((data)<<9))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsd2y(data)                             (0x00000100&((data)<<8))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsx(data)                               (0x00000080&((data)<<7))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllsy(data)                               (0x00000040&((data)<<6))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_pllssck(data)                             (0x0000003F&(data))
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pll_pi_autoset(data)                  ((0x40000000&(data))>>30)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllsd2x_3(data)                       ((0x20000000&(data))>>29)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllsd2y_3(data)                       ((0x10000000&(data))>>28)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllsx_3(data)                         ((0x08000000&(data))>>27)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllsy_3(data)                         ((0x04000000&(data))>>26)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllssck_3(data)                       ((0x03F00000&(data))>>20)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllsd2x_2(data)                       ((0x00080000&(data))>>19)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllsd2y_2(data)                       ((0x00040000&(data))>>18)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllsx_2(data)                         ((0x00020000&(data))>>17)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllsy_2(data)                         ((0x00010000&(data))>>16)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllssck_2(data)                       ((0x0000FC00&(data))>>10)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllsd2x(data)                         ((0x00000200&(data))>>9)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllsd2y(data)                         ((0x00000100&(data))>>8)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllsx(data)                           ((0x00000080&(data))>>7)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllsy(data)                           ((0x00000040&(data))>>6)
#define  PLL27X_REG_EMMC_PLLPHASE_CTRL_get_pllssck(data)                         (0x0000003F&(data))

#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION                                 0x1800070C
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_reg_addr                        "0xB800070C"
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_reg                             0xB800070C
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_inst_addr                       "0x0041"
#define  set_PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_reg(data)                   (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_reg)=data)
#define  get_PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_reg                         (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_reg))
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsd2x_4_shift                 (19)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsd2y_4_shift                 (18)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsx_4_shift                   (17)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsy_4_shift                   (16)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllssck_4_shift                 (10)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsphrl_shift                  (4)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsphrs_shift                  (0)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsd2x_4_mask                  (0x00080000)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsd2y_4_mask                  (0x00040000)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsx_4_mask                    (0x00020000)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsy_4_mask                    (0x00010000)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllssck_4_mask                  (0x0000FC00)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsphrl_mask                   (0x00000030)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsphrs_mask                   (0x00000007)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsd2x_4(data)                 (0x00080000&((data)<<19))
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsd2y_4(data)                 (0x00040000&((data)<<18))
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsx_4(data)                   (0x00020000&((data)<<17))
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsy_4(data)                   (0x00010000&((data)<<16))
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllssck_4(data)                 (0x0000FC00&((data)<<10))
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsphrl(data)                  (0x00000030&((data)<<4))
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_pllsphrs(data)                  (0x00000007&(data))
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_get_pllsd2x_4(data)             ((0x00080000&(data))>>19)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_get_pllsd2y_4(data)             ((0x00040000&(data))>>18)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_get_pllsx_4(data)               ((0x00020000&(data))>>17)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_get_pllsy_4(data)               ((0x00010000&(data))>>16)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_get_pllssck_4(data)             ((0x0000FC00&(data))>>10)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_get_pllsphrl(data)              ((0x00000030&(data))>>4)
#define  PLL27X_REG_EMMC_PLL_PHASE_INTERPOLATION_get_pllsphrs(data)              (0x00000007&(data))

#define  PLL27X_REG_EMMC_PLL_SSC0                                                0x18000710
#define  PLL27X_REG_EMMC_PLL_SSC0_reg_addr                                       "0xB8000710"
#define  PLL27X_REG_EMMC_PLL_SSC0_reg                                            0xB8000710
#define  PLL27X_REG_EMMC_PLL_SSC0_inst_addr                                      "0x0042"
#define  set_PLL27X_REG_EMMC_PLL_SSC0_reg(data)                                  (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC0_reg)=data)
#define  get_PLL27X_REG_EMMC_PLL_SSC0_reg                                        (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC0_reg))
#define  PLL27X_REG_EMMC_PLL_SSC0_pllemmc_oc_step_set_shift                      (4)
#define  PLL27X_REG_EMMC_PLL_SSC0_pllemmc_oc_en_shift                            (0)
#define  PLL27X_REG_EMMC_PLL_SSC0_pllemmc_oc_step_set_mask                       (0x00003FF0)
#define  PLL27X_REG_EMMC_PLL_SSC0_pllemmc_oc_en_mask                             (0x00000001)
#define  PLL27X_REG_EMMC_PLL_SSC0_pllemmc_oc_step_set(data)                      (0x00003FF0&((data)<<4))
#define  PLL27X_REG_EMMC_PLL_SSC0_pllemmc_oc_en(data)                            (0x00000001&(data))
#define  PLL27X_REG_EMMC_PLL_SSC0_get_pllemmc_oc_step_set(data)                  ((0x00003FF0&(data))>>4)
#define  PLL27X_REG_EMMC_PLL_SSC0_get_pllemmc_oc_en(data)                        (0x00000001&(data))

#define  PLL27X_REG_EMMC_PLL_SSC1                                                0x18000714
#define  PLL27X_REG_EMMC_PLL_SSC1_reg_addr                                       "0xB8000714"
#define  PLL27X_REG_EMMC_PLL_SSC1_reg                                            0xB8000714
#define  PLL27X_REG_EMMC_PLL_SSC1_inst_addr                                      "0x0043"
#define  set_PLL27X_REG_EMMC_PLL_SSC1_reg(data)                                  (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC1_reg)=data)
#define  get_PLL27X_REG_EMMC_PLL_SSC1_reg                                        (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC1_reg))
#define  PLL27X_REG_EMMC_PLL_SSC1_pllemmc_oc_done_delay_shift                    (16)
#define  PLL27X_REG_EMMC_PLL_SSC1_pllemmc_hs_oc_stop_diff_shift                  (12)
#define  PLL27X_REG_EMMC_PLL_SSC1_pllemmc_pi_cur_sel_shift                       (10)
#define  PLL27X_REG_EMMC_PLL_SSC1_pllemmc_sel_oc_mode_shift                      (8)
#define  PLL27X_REG_EMMC_PLL_SSC1_pllemmc_oc_done_delay_mask                     (0x003F0000)
#define  PLL27X_REG_EMMC_PLL_SSC1_pllemmc_hs_oc_stop_diff_mask                   (0x00003000)
#define  PLL27X_REG_EMMC_PLL_SSC1_pllemmc_pi_cur_sel_mask                        (0x00000C00)
#define  PLL27X_REG_EMMC_PLL_SSC1_pllemmc_sel_oc_mode_mask                       (0x00000300)
#define  PLL27X_REG_EMMC_PLL_SSC1_pllemmc_oc_done_delay(data)                    (0x003F0000&((data)<<16))
#define  PLL27X_REG_EMMC_PLL_SSC1_pllemmc_hs_oc_stop_diff(data)                  (0x00003000&((data)<<12))
#define  PLL27X_REG_EMMC_PLL_SSC1_pllemmc_pi_cur_sel(data)                       (0x00000C00&((data)<<10))
#define  PLL27X_REG_EMMC_PLL_SSC1_pllemmc_sel_oc_mode(data)                      (0x00000300&((data)<<8))
#define  PLL27X_REG_EMMC_PLL_SSC1_get_pllemmc_oc_done_delay(data)                ((0x003F0000&(data))>>16)
#define  PLL27X_REG_EMMC_PLL_SSC1_get_pllemmc_hs_oc_stop_diff(data)              ((0x00003000&(data))>>12)
#define  PLL27X_REG_EMMC_PLL_SSC1_get_pllemmc_pi_cur_sel(data)                   ((0x00000C00&(data))>>10)
#define  PLL27X_REG_EMMC_PLL_SSC1_get_pllemmc_sel_oc_mode(data)                  ((0x00000300&(data))>>8)

#define  PLL27X_REG_EMMC_PLL_SSC2                                                0x18000718
#define  PLL27X_REG_EMMC_PLL_SSC2_reg_addr                                       "0xB8000718"
#define  PLL27X_REG_EMMC_PLL_SSC2_reg                                            0xB8000718
#define  PLL27X_REG_EMMC_PLL_SSC2_inst_addr                                      "0x0044"
#define  set_PLL27X_REG_EMMC_PLL_SSC2_reg(data)                                  (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC2_reg)=data)
#define  get_PLL27X_REG_EMMC_PLL_SSC2_reg                                        (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC2_reg))
#define  PLL27X_REG_EMMC_PLL_SSC2_pllemmc_en_pi_debug_shift                      (2)
#define  PLL27X_REG_EMMC_PLL_SSC2_pllemmc_sdm_order_shift                        (1)
#define  PLL27X_REG_EMMC_PLL_SSC2_pllemmc_bypass_pi_shift                        (0)
#define  PLL27X_REG_EMMC_PLL_SSC2_pllemmc_en_pi_debug_mask                       (0x00000004)
#define  PLL27X_REG_EMMC_PLL_SSC2_pllemmc_sdm_order_mask                         (0x00000002)
#define  PLL27X_REG_EMMC_PLL_SSC2_pllemmc_bypass_pi_mask                         (0x00000001)
#define  PLL27X_REG_EMMC_PLL_SSC2_pllemmc_en_pi_debug(data)                      (0x00000004&((data)<<2))
#define  PLL27X_REG_EMMC_PLL_SSC2_pllemmc_sdm_order(data)                        (0x00000002&((data)<<1))
#define  PLL27X_REG_EMMC_PLL_SSC2_pllemmc_bypass_pi(data)                        (0x00000001&(data))
#define  PLL27X_REG_EMMC_PLL_SSC2_get_pllemmc_en_pi_debug(data)                  ((0x00000004&(data))>>2)
#define  PLL27X_REG_EMMC_PLL_SSC2_get_pllemmc_sdm_order(data)                    ((0x00000002&(data))>>1)
#define  PLL27X_REG_EMMC_PLL_SSC2_get_pllemmc_bypass_pi(data)                    (0x00000001&(data))

#define  PLL27X_REG_EMMC_PLL_SSC3                                                0x1800071C
#define  PLL27X_REG_EMMC_PLL_SSC3_reg_addr                                       "0xB800071C"
#define  PLL27X_REG_EMMC_PLL_SSC3_reg                                            0xB800071C
#define  PLL27X_REG_EMMC_PLL_SSC3_inst_addr                                      "0x0045"
#define  set_PLL27X_REG_EMMC_PLL_SSC3_reg(data)                                  (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC3_reg)=data)
#define  get_PLL27X_REG_EMMC_PLL_SSC3_reg                                        (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC3_reg))
#define  PLL27X_REG_EMMC_PLL_SSC3_pllemmc_ncode_ssc_shift                        (16)
#define  PLL27X_REG_EMMC_PLL_SSC3_pllemmc_fcode_ssc_shift                        (0)
#define  PLL27X_REG_EMMC_PLL_SSC3_pllemmc_ncode_ssc_mask                         (0x00FF0000)
#define  PLL27X_REG_EMMC_PLL_SSC3_pllemmc_fcode_ssc_mask                         (0x000007FF)
#define  PLL27X_REG_EMMC_PLL_SSC3_pllemmc_ncode_ssc(data)                        (0x00FF0000&((data)<<16))
#define  PLL27X_REG_EMMC_PLL_SSC3_pllemmc_fcode_ssc(data)                        (0x000007FF&(data))
#define  PLL27X_REG_EMMC_PLL_SSC3_get_pllemmc_ncode_ssc(data)                    ((0x00FF0000&(data))>>16)
#define  PLL27X_REG_EMMC_PLL_SSC3_get_pllemmc_fcode_ssc(data)                    (0x000007FF&(data))

#define  PLL27X_REG_EMMC_PLL_SSC4                                                0x18000720
#define  PLL27X_REG_EMMC_PLL_SSC4_reg_addr                                       "0xB8000720"
#define  PLL27X_REG_EMMC_PLL_SSC4_reg                                            0xB8000720
#define  PLL27X_REG_EMMC_PLL_SSC4_inst_addr                                      "0x0046"
#define  set_PLL27X_REG_EMMC_PLL_SSC4_reg(data)                                  (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC4_reg)=data)
#define  get_PLL27X_REG_EMMC_PLL_SSC4_reg                                        (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC4_reg))
#define  PLL27X_REG_EMMC_PLL_SSC4_pllemmc_ncode_t_shift                          (16)
#define  PLL27X_REG_EMMC_PLL_SSC4_pllemmc_fcode_t_shift                          (0)
#define  PLL27X_REG_EMMC_PLL_SSC4_pllemmc_ncode_t_mask                           (0x00FF0000)
#define  PLL27X_REG_EMMC_PLL_SSC4_pllemmc_fcode_t_mask                           (0x000007FF)
#define  PLL27X_REG_EMMC_PLL_SSC4_pllemmc_ncode_t(data)                          (0x00FF0000&((data)<<16))
#define  PLL27X_REG_EMMC_PLL_SSC4_pllemmc_fcode_t(data)                          (0x000007FF&(data))
#define  PLL27X_REG_EMMC_PLL_SSC4_get_pllemmc_ncode_t(data)                      ((0x00FF0000&(data))>>16)
#define  PLL27X_REG_EMMC_PLL_SSC4_get_pllemmc_fcode_t(data)                      (0x000007FF&(data))

#define  PLL27X_REG_EMMC_PLL_SSC5                                                0x18000724
#define  PLL27X_REG_EMMC_PLL_SSC5_reg_addr                                       "0xB8000724"
#define  PLL27X_REG_EMMC_PLL_SSC5_reg                                            0xB8000724
#define  PLL27X_REG_EMMC_PLL_SSC5_inst_addr                                      "0x0047"
#define  set_PLL27X_REG_EMMC_PLL_SSC5_reg(data)                                  (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC5_reg)=data)
#define  get_PLL27X_REG_EMMC_PLL_SSC5_reg                                        (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC5_reg))
#define  PLL27X_REG_EMMC_PLL_SSC5_pllemmc_gran_auto_rst_shift                    (28)
#define  PLL27X_REG_EMMC_PLL_SSC5_pllemmc_dot_gran_shift                         (24)
#define  PLL27X_REG_EMMC_PLL_SSC5_pllemmc_gran_est_shift                         (4)
#define  PLL27X_REG_EMMC_PLL_SSC5_pllemmc_en_ssc_shift                           (0)
#define  PLL27X_REG_EMMC_PLL_SSC5_pllemmc_gran_auto_rst_mask                     (0x10000000)
#define  PLL27X_REG_EMMC_PLL_SSC5_pllemmc_dot_gran_mask                          (0x07000000)
#define  PLL27X_REG_EMMC_PLL_SSC5_pllemmc_gran_est_mask                          (0x007FFFF0)
#define  PLL27X_REG_EMMC_PLL_SSC5_pllemmc_en_ssc_mask                            (0x00000001)
#define  PLL27X_REG_EMMC_PLL_SSC5_pllemmc_gran_auto_rst(data)                    (0x10000000&((data)<<28))
#define  PLL27X_REG_EMMC_PLL_SSC5_pllemmc_dot_gran(data)                         (0x07000000&((data)<<24))
#define  PLL27X_REG_EMMC_PLL_SSC5_pllemmc_gran_est(data)                         (0x007FFFF0&((data)<<4))
#define  PLL27X_REG_EMMC_PLL_SSC5_pllemmc_en_ssc(data)                           (0x00000001&(data))
#define  PLL27X_REG_EMMC_PLL_SSC5_get_pllemmc_gran_auto_rst(data)                ((0x10000000&(data))>>28)
#define  PLL27X_REG_EMMC_PLL_SSC5_get_pllemmc_dot_gran(data)                     ((0x07000000&(data))>>24)
#define  PLL27X_REG_EMMC_PLL_SSC5_get_pllemmc_gran_est(data)                     ((0x007FFFF0&(data))>>4)
#define  PLL27X_REG_EMMC_PLL_SSC5_get_pllemmc_en_ssc(data)                       (0x00000001&(data))

#define  PLL27X_REG_EMMC_PLL_SSC6                                                0x18000728
#define  PLL27X_REG_EMMC_PLL_SSC6_reg_addr                                       "0xB8000728"
#define  PLL27X_REG_EMMC_PLL_SSC6_reg                                            0xB8000728
#define  PLL27X_REG_EMMC_PLL_SSC6_inst_addr                                      "0x0048"
#define  set_PLL27X_REG_EMMC_PLL_SSC6_reg(data)                                  (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC6_reg)=data)
#define  get_PLL27X_REG_EMMC_PLL_SSC6_reg                                        (*((volatile unsigned int*)PLL27X_REG_EMMC_PLL_SSC6_reg))
#define  PLL27X_REG_EMMC_PLL_SSC6_pllemmc_fcode_debug_shift                      (16)
#define  PLL27X_REG_EMMC_PLL_SSC6_pllemmc_ncode_debug_shift                      (8)
#define  PLL27X_REG_EMMC_PLL_SSC6_pllemmc_oc_done_shift                          (4)
#define  PLL27X_REG_EMMC_PLL_SSC6_pllemmc_fmod_shift                             (0)
#define  PLL27X_REG_EMMC_PLL_SSC6_pllemmc_fcode_debug_mask                       (0x07FF0000)
#define  PLL27X_REG_EMMC_PLL_SSC6_pllemmc_ncode_debug_mask                       (0x0000FF00)
#define  PLL27X_REG_EMMC_PLL_SSC6_pllemmc_oc_done_mask                           (0x00000010)
#define  PLL27X_REG_EMMC_PLL_SSC6_pllemmc_fmod_mask                              (0x00000001)
#define  PLL27X_REG_EMMC_PLL_SSC6_pllemmc_fcode_debug(data)                      (0x07FF0000&((data)<<16))
#define  PLL27X_REG_EMMC_PLL_SSC6_pllemmc_ncode_debug(data)                      (0x0000FF00&((data)<<8))
#define  PLL27X_REG_EMMC_PLL_SSC6_pllemmc_oc_done(data)                          (0x00000010&((data)<<4))
#define  PLL27X_REG_EMMC_PLL_SSC6_pllemmc_fmod(data)                             (0x00000001&(data))
#define  PLL27X_REG_EMMC_PLL_SSC6_get_pllemmc_fcode_debug(data)                  ((0x07FF0000&(data))>>16)
#define  PLL27X_REG_EMMC_PLL_SSC6_get_pllemmc_ncode_debug(data)                  ((0x0000FF00&(data))>>8)
#define  PLL27X_REG_EMMC_PLL_SSC6_get_pllemmc_oc_done(data)                      ((0x00000010&(data))>>4)
#define  PLL27X_REG_EMMC_PLL_SSC6_get_pllemmc_fmod(data)                         (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PLL27X_REG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pll512fs_n:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll512fs_m:7;
        RBus_UInt32  pll512fs_bpn:1;
        RBus_UInt32  pll512fs_bps:1;
        RBus_UInt32  pll512fs_cs:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll512fs_ip:3;
        RBus_UInt32  pll512fs_s:3;
        RBus_UInt32  pll512fs_q:3;
        RBus_UInt32  pll512fs_rs:3;
        RBus_UInt32  pll512fs_tst:1;
        RBus_UInt32  pll512fs_wdrst:1;
        RBus_UInt32  pll512fs_wdset:1;
    };
}pll27x_reg_sys_pll_512fs_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pll512fs_oeb:1;
        RBus_UInt32  pll512fs_rstb:1;
        RBus_UInt32  pll512fs_pow:1;
    };
}pll27x_reg_sys_pll_512fs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pll512fs_n2:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll512fs_m2:7;
        RBus_UInt32  pll512fs_bpn2:1;
        RBus_UInt32  pll512fs_bps2:1;
        RBus_UInt32  pll512fs_cs2:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll512fs_ip2:3;
        RBus_UInt32  pll512fs_s2:3;
        RBus_UInt32  pll512fs_q2:3;
        RBus_UInt32  pll512fs_rs2:3;
        RBus_UInt32  pll512fs_tst2:1;
        RBus_UInt32  pll512fs_wdrst2:1;
        RBus_UInt32  pll512fs_wdset2:1;
    };
}pll27x_reg_sys_pll_512fs2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pll512fs_oeb2:1;
        RBus_UInt32  pll512fs_rstb2:1;
        RBus_UInt32  pll512fs_pow2:1;
    };
}pll27x_reg_sys_pll_512fs2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  plldif_n:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  plldif_m:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  plldif_ip:3;
        RBus_UInt32  plldif_lf_rs:2;
        RBus_UInt32  plldif_lf_cp:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:11;
    };
}pll27x_reg_sys_pll_dif1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  plldif_dvbs2_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  plldif_wdmode:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  plldif_divdig_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  plldif_divadc_sel:3;
    };
}pll27x_reg_sys_pll_dif2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdic_dtmb_dig_mux:1;
        RBus_UInt32  res1:28;
        RBus_UInt32  plldif_vco_rstb:1;
        RBus_UInt32  plldif_rstb:1;
        RBus_UInt32  plldif_pow:1;
    };
}pll27x_reg_sys_pll_dif3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pll27x_wdmode:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pll27x_lf_cp:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pll27x_lf_rs:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  pll27x_ip:3;
        RBus_UInt32  res5:4;
        RBus_UInt32  res6:2;
        RBus_UInt32  pll27x_n:2;
        RBus_UInt32  res7:1;
        RBus_UInt32  pll27x_m:7;
    };
}pll27x_reg_sys_pll_27x1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xi_cap:4;
        RBus_UInt32  xo_cap:4;
        RBus_UInt32  vdd11_pad_sel:3;
        RBus_UInt32  pll_ldo_xtal_sel:2;
        RBus_UInt32  pll_xixo_load:1;
        RBus_UInt32  pll_xixo_drive_sel:2;
        RBus_UInt32  pad_sel_en:1;
        RBus_UInt32  pll_pow_ldo11v:1;
        RBus_UInt32  pll_ldo11v_sel:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll_pow_ldo:1;
        RBus_UInt32  pll_ldo_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pll27x_ps_54m_delay:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pll27x_ps_psel_pulse_w:1;
        RBus_UInt32  pll27x_ps_duty_sel:1;
    };
}pll27x_reg_sys_pll_27x2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  pll_reserve:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  pll27x_ps_en:1;
        RBus_UInt32  pll27x_ps_div2:1;
        RBus_UInt32  pll27x_vcorstb:1;
        RBus_UInt32  pll27x_rstb:1;
        RBus_UInt32  pll27x_pow:1;
    };
}pll27x_reg_sys_pll_27x3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180004dc_31:1;
        RBus_UInt32  pll27x_ifadc_duty:2;
        RBus_UInt32  iqadc_cko_polar:1;
        RBus_UInt32  pll_yppadc_cko_polar:1;
        RBus_UInt32  pll_ifadc_cko_polar:1;
        RBus_UInt32  pll_l2h_cml_pow:1;
        RBus_UInt32  pll27x_d16_en:1;
        RBus_UInt32  pll27x_pll_tst:3;
        RBus_UInt32  pll27x_en_tst:1;
        RBus_UInt32  pll_rssi_cko_en:1;
        RBus_UInt32  pll27x_ck108m_en:1;
        RBus_UInt32  pll27x_ck108m_div:2;
        RBus_UInt32  pll27x_yppadc_cko_sel:2;
        RBus_UInt32  pll27x_yppadc_cko_en:1;
        RBus_UInt32  pll27x_yppadc_ck54m_en:1;
        RBus_UInt32  pll27x_ifadc_cko_sel:2;
        RBus_UInt32  pll27x_ifadc_div:1;
        RBus_UInt32  pll27x_ifadc_cko_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllaud_ckin_mux:1;
        RBus_UInt32  pll_xtalwd_rst:1;
        RBus_UInt32  pll_xtalwd_set:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll_ck_ifadc_mux:1;
    };
}pll27x_reg_sys_pll_27x4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  pllaud_ip:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllaud_rs:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllaud_cp:2;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  pllaud_wdrst:1;
        RBus_UInt32  pllaud_wdset:1;
        RBus_UInt32  pllaud_tst:1;
    };
}pll27x_reg_sys_pll_aud1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  pllaud_vcorstb:1;
        RBus_UInt32  pllaud_rstb:1;
        RBus_UInt32  pllaud_oeb1:1;
        RBus_UInt32  pllaud_oeb2:1;
        RBus_UInt32  pllaud_pow:1;
    };
}pll27x_reg_sys_pll_aud3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bb_micbias_clksel:2;
    };
}pll27x_reg_sys_pll_aud4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  psaud_adder_mode:1;
        RBus_UInt32  psaud_psen:1;
        RBus_UInt32  psaud_en:1;
        RBus_UInt32  psaud_tst:1;
        RBus_UInt32  psaud_ctrl:1;
    };
}pll27x_reg_sys_pll_psaud1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  psaud_div:4;
    };
}pll27x_reg_sys_pll_psaud2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_adtv_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dss_adtv_ro_sel:3;
        RBus_UInt32  dss_adtv_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dss_adtv_ready:1;
        RBus_UInt32  dss_adtv_count_out:20;
    };
}pll27x_reg_ss_adtv_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dss_adtv_speed_en:1;
        RBus_UInt32  dss_adtv_wsort_go:1;
        RBus_UInt32  dss_adtv_data_in:20;
    };
}pll27x_reg_ss_adtv_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dss_adtv_dbgo:16;
    };
}pll27x_reg_ss_adtv_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  pll27x_iqadc_cko_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll27x_iqadc_cko_en:1;
        RBus_UInt32  pll27x_ifadc_dtv_cko_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll27x_ifadc_dtv_cko_en:1;
        RBus_UInt32  pll27x_ifadc_atv_cko_sel:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  pip_ifadc_atv_cko_sel:1;
    };
}pll27x_reg_ifadc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pll27x_ifadc_n:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll27x_ifadc_m:7;
        RBus_UInt32  res3:6;
        RBus_UInt32  pll27x_ifadc_lf_rs:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  pll27x_ifadc_lf_cp:2;
        RBus_UInt32  res5:1;
        RBus_UInt32  pll27x_ifadc_ip:3;
    };
}pll27x_reg_ifadc_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  pll27x_ifadc_wdmode:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll27x_ifadc_vcorstb:1;
        RBus_UInt32  pll27x_ifadc_rstb:1;
        RBus_UInt32  pll27x_ifadc_pow:1;
    };
}pll27x_reg_ifadc_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_field_flag_mode_en:1;
        RBus_UInt32  dclk_filed_flag_slt:3;
        RBus_UInt32  res1:12;
        RBus_UInt32  dclk_new_en:1;
        RBus_UInt32  res2:11;
        RBus_UInt32  dummy18000640_3:1;
        RBus_UInt32  dclk_ss_load:1;
        RBus_UInt32  dummy18000640_1:1;
        RBus_UInt32  dclk_ss_en:1;
    };
}pll27x_reg_sys_dclkss_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dclk_freq_syn_slt:14;
        RBus_UInt32  res2:11;
        RBus_UInt32  fll_tracking_en:1;
        RBus_UInt32  in_frame_tracking_offset_inverse:1;
        RBus_UInt32  in_frame_tracking_ypbpr_en:1;
        RBus_UInt32  in_frame_tracking_vd_dec_en:1;
        RBus_UInt32  in_frame_tracking_general_en:1;
    };
}pll27x_reg_dpll_in_fsync_tracking_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  in_frame_tracking_mul:19;
    };
}pll27x_reg_dpll_in_fsync_tracking_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in_frame_tracking_neg_th:16;
        RBus_UInt32  in_frame_tracking_pos_th:16;
    };
}pll27x_reg_dpll_in_fsync_tracking_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  frc2fsync_speed_dir:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  frc2fsync_speedup_offset:13;
    };
}pll27x_reg_dclk_frc2fsync_speedup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  final_profile:18;
    };
}pll27x_reg_dpll_status_ro_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18000658_31_12:20;
        RBus_UInt32  dclk_profile_remap_cnt:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  dclk_profile_remap_en:1;
    };
}pll27x_reg_dclkss_profile_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_1:16;
        RBus_UInt32  dclk_profile_remap_0:16;
    };
}pll27x_reg_dclkss_profile0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_3:16;
        RBus_UInt32  dclk_profile_remap_2:16;
    };
}pll27x_reg_dclkss_profile1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_5:16;
        RBus_UInt32  dclk_profile_remap_4:16;
    };
}pll27x_reg_dclkss_profile2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_7:16;
        RBus_UInt32  dclk_profile_remap_6:16;
    };
}pll27x_reg_dclkss_profile3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_9:16;
        RBus_UInt32  dclk_profile_remap_8:16;
    };
}pll27x_reg_dclkss_profile4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_11:16;
        RBus_UInt32  dclk_profile_remap_10:16;
    };
}pll27x_reg_dclkss_profile5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_13:16;
        RBus_UInt32  dclk_profile_remap_12:16;
    };
}pll27x_reg_dclkss_profile6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_15:16;
        RBus_UInt32  dclk_profile_remap_14:16;
    };
}pll27x_reg_dclkss_profile7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_17:16;
        RBus_UInt32  dclk_profile_remap_16:16;
    };
}pll27x_reg_dclkss_profile8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_19:16;
        RBus_UInt32  dclk_profile_remap_18:16;
    };
}pll27x_reg_dclkss_profile9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_21:16;
        RBus_UInt32  dclk_profile_remap_20:16;
    };
}pll27x_reg_dclkss_profile10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_23:16;
        RBus_UInt32  dclk_profile_remap_22:16;
    };
}pll27x_reg_dclkss_profile11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_25:16;
        RBus_UInt32  dclk_profile_remap_24:16;
    };
}pll27x_reg_dclkss_profile12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_27:16;
        RBus_UInt32  dclk_profile_remap_26:16;
    };
}pll27x_reg_dclkss_profile13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_29:16;
        RBus_UInt32  dclk_profile_remap_28:16;
    };
}pll27x_reg_dclkss_profile14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_31:16;
        RBus_UInt32  dclk_profile_remap_30:16;
    };
}pll27x_reg_dclkss_profile15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  double_buf_en:1;
        RBus_UInt32  double_buf_read_sel:1;
        RBus_UInt32  double_buf_apply:1;
    };
}pll27x_reg_dpll_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  fcode_t_ssc:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  oc_step_set:10;
        RBus_UInt32  res3:3;
        RBus_UInt32  oc_en:1;
    };
}pll27x_reg_pll_ssc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  oc_done_delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  hs_oc_stop_diff:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  sel_oc_mode:2;
        RBus_UInt32  res4:8;
    };
}pll27x_reg_pll_ssc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  en_pi_debug:1;
        RBus_UInt32  sdm_order:1;
        RBus_UInt32  bypass_pi:1;
    };
}pll27x_reg_pll_ssc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ncode_ssc:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  fcode_ssc:11;
    };
}pll27x_reg_pll_ssc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  gran_auto_rst:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  gran_est:19;
        RBus_UInt32  res4:3;
        RBus_UInt32  en_ssc:1;
    };
}pll27x_reg_pll_ssc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  fcode_debug:11;
        RBus_UInt32  ncode_debug:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  oc_done:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  load_fcw:1;
        RBus_UInt32  fmod:1;
    };
}pll27x_reg_pll_ssc5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dpll_m:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  dpll_n:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  dpll_ip:3;
        RBus_UInt32  dpll_ssc_inv:1;
        RBus_UInt32  dpll_rs:3;
        RBus_UInt32  dpll_cp:2;
        RBus_UInt32  dpll_cs:2;
    };
}pll27x_reg_sys_pll_disp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dpll_x_bpspi:1;
        RBus_UInt32  dpll_x_bpsin:1;
    };
}pll27x_reg_sys_pll_disp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_dpll_src_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dpll_ldosel:2;
        RBus_UInt32  dpll_reser:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  dpll_dummy:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  dpll_picap:1;
        RBus_UInt32  dpll_prescaler:1;
        RBus_UInt32  dpll_test_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  dpll_o:2;
        RBus_UInt32  res5:5;
        RBus_UInt32  dpll_rstb:1;
        RBus_UInt32  dpll_wdrst:1;
        RBus_UInt32  dpll_wdset:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  dpll_freeze:1;
        RBus_UInt32  dpll_vcorstb:1;
        RBus_UInt32  dpll_pow:1;
    };
}pll27x_reg_sys_pll_disp3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dpll_ldodpll_pow:1;
        RBus_UInt32  dpll_pi_ibsel:2;
    };
}pll27x_reg_sys_pll_disp4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sscg_offset_over_flag:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  sscg_offset_over_th_value:17;
    };
}pll27x_reg_dpll_in_fsync_tracking_debug0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  sscg_offset_over_th_max:17;
    };
}pll27x_reg_dpll_in_fsync_tracking_debug1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_fll_offset_over_flag:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  new_fll_offset_over_th_value:17;
    };
}pll27x_reg_dpll_in_fsync_tracking_debug2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  new_fll_offset_over_th_max:17;
    };
}pll27x_reg_dpll_in_fsync_tracking_debug3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  new_fll_tracking_offset_inverse:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  new_fll_tracking_mul:19;
    };
}pll27x_reg_dpll_in_fsync_tracking_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_fll_tracking_neg_th:16;
        RBus_UInt32  new_fll_tracking_pos_th:16;
    };
}pll27x_reg_dpll_in_fsync_tracking_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pll_emmc_ckssc_inv:1;
        RBus_UInt32  pllscp:1;
        RBus_UInt32  pllscs:2;
        RBus_UInt32  pllsrs:3;
        RBus_UInt32  res2:6;
        RBus_UInt32  pllsdiv2:1;
        RBus_UInt32  pllssi:5;
        RBus_UInt32  pllsnbp:1;
        RBus_UInt32  pllsn:3;
        RBus_UInt32  res3:7;
        RBus_UInt32  pllallrstb:1;
    };
}pll27x_reg_emmc_pll_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_pllemmc_bpspi:1;
        RBus_UInt32  reg_pll_tp2_mux:3;
        RBus_UInt32  reg_pll_tp1_mux:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllemmc_rsvd:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllsstatus:1;
        RBus_UInt32  pllswdrst:1;
        RBus_UInt32  pllswdset:1;
        RBus_UInt32  pllemmc_reg:2;
        RBus_UInt32  pllemmcldopow:1;
        RBus_UInt32  pllemmcpwdn:1;
    };
}pll27x_reg_emmc_pll_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pll_pi_autoset:1;
        RBus_UInt32  pllsd2x_3:1;
        RBus_UInt32  pllsd2y_3:1;
        RBus_UInt32  pllsx_3:1;
        RBus_UInt32  pllsy_3:1;
        RBus_UInt32  pllssck_3:6;
        RBus_UInt32  pllsd2x_2:1;
        RBus_UInt32  pllsd2y_2:1;
        RBus_UInt32  pllsx_2:1;
        RBus_UInt32  pllsy_2:1;
        RBus_UInt32  pllssck_2:6;
        RBus_UInt32  pllsd2x:1;
        RBus_UInt32  pllsd2y:1;
        RBus_UInt32  pllsx:1;
        RBus_UInt32  pllsy:1;
        RBus_UInt32  pllssck:6;
    };
}pll27x_reg_emmc_pllphase_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  pllsd2x_4:1;
        RBus_UInt32  pllsd2y_4:1;
        RBus_UInt32  pllsx_4:1;
        RBus_UInt32  pllsy_4:1;
        RBus_UInt32  pllssck_4:6;
        RBus_UInt32  res2:4;
        RBus_UInt32  pllsphrl:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllsphrs:3;
    };
}pll27x_reg_emmc_pll_phase_interpolation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  pllemmc_oc_step_set:10;
        RBus_UInt32  res2:3;
        RBus_UInt32  pllemmc_oc_en:1;
    };
}pll27x_reg_emmc_pll_ssc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  pllemmc_oc_done_delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllemmc_hs_oc_stop_diff:2;
        RBus_UInt32  pllemmc_pi_cur_sel:2;
        RBus_UInt32  pllemmc_sel_oc_mode:2;
        RBus_UInt32  res3:8;
    };
}pll27x_reg_emmc_pll_ssc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pllemmc_en_pi_debug:1;
        RBus_UInt32  pllemmc_sdm_order:1;
        RBus_UInt32  pllemmc_bypass_pi:1;
    };
}pll27x_reg_emmc_pll_ssc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllemmc_ncode_ssc:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  pllemmc_fcode_ssc:11;
    };
}pll27x_reg_emmc_pll_ssc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllemmc_ncode_t:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  pllemmc_fcode_t:11;
    };
}pll27x_reg_emmc_pll_ssc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pllemmc_gran_auto_rst:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllemmc_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllemmc_gran_est:19;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllemmc_en_ssc:1;
    };
}pll27x_reg_emmc_pll_ssc5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllemmc_fcode_debug:11;
        RBus_UInt32  pllemmc_ncode_debug:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  pllemmc_oc_done:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  pllemmc_fmod:1;
    };
}pll27x_reg_emmc_pll_ssc6_RBUS;

#else //apply LITTLE_ENDIAN

//======PLL27X_REG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll512fs_wdset:1;
        RBus_UInt32  pll512fs_wdrst:1;
        RBus_UInt32  pll512fs_tst:1;
        RBus_UInt32  pll512fs_rs:3;
        RBus_UInt32  pll512fs_q:3;
        RBus_UInt32  pll512fs_s:3;
        RBus_UInt32  pll512fs_ip:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll512fs_cs:2;
        RBus_UInt32  pll512fs_bps:1;
        RBus_UInt32  pll512fs_bpn:1;
        RBus_UInt32  pll512fs_m:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll512fs_n:3;
        RBus_UInt32  res3:1;
    };
}pll27x_reg_sys_pll_512fs_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll512fs_pow:1;
        RBus_UInt32  pll512fs_rstb:1;
        RBus_UInt32  pll512fs_oeb:1;
        RBus_UInt32  res1:29;
    };
}pll27x_reg_sys_pll_512fs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll512fs_wdset2:1;
        RBus_UInt32  pll512fs_wdrst2:1;
        RBus_UInt32  pll512fs_tst2:1;
        RBus_UInt32  pll512fs_rs2:3;
        RBus_UInt32  pll512fs_q2:3;
        RBus_UInt32  pll512fs_s2:3;
        RBus_UInt32  pll512fs_ip2:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll512fs_cs2:2;
        RBus_UInt32  pll512fs_bps2:1;
        RBus_UInt32  pll512fs_bpn2:1;
        RBus_UInt32  pll512fs_m2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll512fs_n2:3;
        RBus_UInt32  res3:1;
    };
}pll27x_reg_sys_pll_512fs2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll512fs_pow2:1;
        RBus_UInt32  pll512fs_rstb2:1;
        RBus_UInt32  pll512fs_oeb2:1;
        RBus_UInt32  res1:29;
    };
}pll27x_reg_sys_pll_512fs2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  plldif_lf_cp:2;
        RBus_UInt32  plldif_lf_rs:2;
        RBus_UInt32  plldif_ip:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  plldif_m:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  plldif_n:2;
        RBus_UInt32  res5:2;
    };
}pll27x_reg_sys_pll_dif1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plldif_divadc_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  plldif_divdig_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  plldif_wdmode:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  plldif_dvbs2_en:1;
        RBus_UInt32  res4:19;
    };
}pll27x_reg_sys_pll_dif2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plldif_pow:1;
        RBus_UInt32  plldif_rstb:1;
        RBus_UInt32  plldif_vco_rstb:1;
        RBus_UInt32  res1:28;
        RBus_UInt32  hdic_dtmb_dig_mux:1;
    };
}pll27x_reg_sys_pll_dif3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll27x_m:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll27x_n:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:4;
        RBus_UInt32  pll27x_ip:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  pll27x_lf_rs:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  pll27x_lf_cp:2;
        RBus_UInt32  res6:2;
        RBus_UInt32  pll27x_wdmode:2;
        RBus_UInt32  res7:2;
    };
}pll27x_reg_sys_pll_27x1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll27x_ps_duty_sel:1;
        RBus_UInt32  pll27x_ps_psel_pulse_w:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pll27x_ps_54m_delay:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pll_ldo_sel:2;
        RBus_UInt32  pll_pow_ldo:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll_ldo11v_sel:2;
        RBus_UInt32  pll_pow_ldo11v:1;
        RBus_UInt32  pad_sel_en:1;
        RBus_UInt32  pll_xixo_drive_sel:2;
        RBus_UInt32  pll_xixo_load:1;
        RBus_UInt32  pll_ldo_xtal_sel:2;
        RBus_UInt32  vdd11_pad_sel:3;
        RBus_UInt32  xo_cap:4;
        RBus_UInt32  xi_cap:4;
    };
}pll27x_reg_sys_pll_27x2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll27x_pow:1;
        RBus_UInt32  pll27x_rstb:1;
        RBus_UInt32  pll27x_vcorstb:1;
        RBus_UInt32  pll27x_ps_div2:1;
        RBus_UInt32  pll27x_ps_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pll_reserve:8;
        RBus_UInt32  res2:16;
    };
}pll27x_reg_sys_pll_27x3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_ck_ifadc_mux:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll_xtalwd_set:1;
        RBus_UInt32  pll_xtalwd_rst:1;
        RBus_UInt32  pllaud_ckin_mux:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  pll27x_ifadc_cko_en:1;
        RBus_UInt32  pll27x_ifadc_div:1;
        RBus_UInt32  pll27x_ifadc_cko_sel:2;
        RBus_UInt32  pll27x_yppadc_ck54m_en:1;
        RBus_UInt32  pll27x_yppadc_cko_en:1;
        RBus_UInt32  pll27x_yppadc_cko_sel:2;
        RBus_UInt32  pll27x_ck108m_div:2;
        RBus_UInt32  pll27x_ck108m_en:1;
        RBus_UInt32  pll_rssi_cko_en:1;
        RBus_UInt32  pll27x_en_tst:1;
        RBus_UInt32  pll27x_pll_tst:3;
        RBus_UInt32  pll27x_d16_en:1;
        RBus_UInt32  pll_l2h_cml_pow:1;
        RBus_UInt32  pll_ifadc_cko_polar:1;
        RBus_UInt32  pll_yppadc_cko_polar:1;
        RBus_UInt32  iqadc_cko_polar:1;
        RBus_UInt32  pll27x_ifadc_duty:2;
        RBus_UInt32  dummy180004dc_31:1;
    };
}pll27x_reg_sys_pll_27x4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllaud_tst:1;
        RBus_UInt32  pllaud_wdset:1;
        RBus_UInt32  pllaud_wdrst:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  pllaud_cp:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  pllaud_rs:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  pllaud_ip:3;
        RBus_UInt32  res6:14;
    };
}pll27x_reg_sys_pll_aud1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllaud_pow:1;
        RBus_UInt32  pllaud_oeb2:1;
        RBus_UInt32  pllaud_oeb1:1;
        RBus_UInt32  pllaud_rstb:1;
        RBus_UInt32  pllaud_vcorstb:1;
        RBus_UInt32  res1:27;
    };
}pll27x_reg_sys_pll_aud3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bb_micbias_clksel:2;
        RBus_UInt32  res1:30;
    };
}pll27x_reg_sys_pll_aud4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psaud_ctrl:1;
        RBus_UInt32  psaud_tst:1;
        RBus_UInt32  psaud_en:1;
        RBus_UInt32  psaud_psen:1;
        RBus_UInt32  psaud_adder_mode:1;
        RBus_UInt32  res1:27;
    };
}pll27x_reg_sys_pll_psaud1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psaud_div:4;
        RBus_UInt32  res1:28;
    };
}pll27x_reg_sys_pll_psaud2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_adtv_count_out:20;
        RBus_UInt32  dss_adtv_ready:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dss_adtv_wire_sel:1;
        RBus_UInt32  dss_adtv_ro_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  dss_adtv_dss_rst_n:1;
    };
}pll27x_reg_ss_adtv_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_adtv_data_in:20;
        RBus_UInt32  dss_adtv_wsort_go:1;
        RBus_UInt32  dss_adtv_speed_en:1;
        RBus_UInt32  res1:10;
    };
}pll27x_reg_ss_adtv_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_adtv_dbgo:16;
        RBus_UInt32  res1:16;
    };
}pll27x_reg_ss_adtv_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pip_ifadc_atv_cko_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll27x_ifadc_atv_cko_sel:2;
        RBus_UInt32  pll27x_ifadc_dtv_cko_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll27x_ifadc_dtv_cko_sel:2;
        RBus_UInt32  pll27x_iqadc_cko_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll27x_iqadc_cko_sel:2;
        RBus_UInt32  res4:20;
    };
}pll27x_reg_ifadc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll27x_ifadc_ip:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll27x_ifadc_lf_cp:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pll27x_ifadc_lf_rs:2;
        RBus_UInt32  res3:6;
        RBus_UInt32  pll27x_ifadc_m:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  pll27x_ifadc_n:2;
        RBus_UInt32  res5:6;
    };
}pll27x_reg_ifadc_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll27x_ifadc_pow:1;
        RBus_UInt32  pll27x_ifadc_rstb:1;
        RBus_UInt32  pll27x_ifadc_vcorstb:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll27x_ifadc_wdmode:2;
        RBus_UInt32  res2:26;
    };
}pll27x_reg_ifadc_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_ss_en:1;
        RBus_UInt32  dummy18000640_1:1;
        RBus_UInt32  dclk_ss_load:1;
        RBus_UInt32  dummy18000640_3:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  dclk_new_en:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  dclk_filed_flag_slt:3;
        RBus_UInt32  dclk_field_flag_mode_en:1;
    };
}pll27x_reg_sys_dclkss_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in_frame_tracking_general_en:1;
        RBus_UInt32  in_frame_tracking_vd_dec_en:1;
        RBus_UInt32  in_frame_tracking_ypbpr_en:1;
        RBus_UInt32  in_frame_tracking_offset_inverse:1;
        RBus_UInt32  fll_tracking_en:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  dclk_freq_syn_slt:14;
        RBus_UInt32  res2:2;
    };
}pll27x_reg_dpll_in_fsync_tracking_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in_frame_tracking_mul:19;
        RBus_UInt32  res1:13;
    };
}pll27x_reg_dpll_in_fsync_tracking_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in_frame_tracking_pos_th:16;
        RBus_UInt32  in_frame_tracking_neg_th:16;
    };
}pll27x_reg_dpll_in_fsync_tracking_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frc2fsync_speedup_offset:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  frc2fsync_speed_dir:1;
        RBus_UInt32  res2:15;
    };
}pll27x_reg_dclk_frc2fsync_speedup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  final_profile:18;
        RBus_UInt32  res1:14;
    };
}pll27x_reg_dpll_status_ro_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dclk_profile_remap_cnt:8;
        RBus_UInt32  dummy18000658_31:20;
    };
}pll27x_reg_dclkss_profile_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_0:16;
        RBus_UInt32  dclk_profile_remap_1:16;
    };
}pll27x_reg_dclkss_profile0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_2:16;
        RBus_UInt32  dclk_profile_remap_3:16;
    };
}pll27x_reg_dclkss_profile1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_4:16;
        RBus_UInt32  dclk_profile_remap_5:16;
    };
}pll27x_reg_dclkss_profile2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_6:16;
        RBus_UInt32  dclk_profile_remap_7:16;
    };
}pll27x_reg_dclkss_profile3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_8:16;
        RBus_UInt32  dclk_profile_remap_9:16;
    };
}pll27x_reg_dclkss_profile4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_10:16;
        RBus_UInt32  dclk_profile_remap_11:16;
    };
}pll27x_reg_dclkss_profile5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_12:16;
        RBus_UInt32  dclk_profile_remap_13:16;
    };
}pll27x_reg_dclkss_profile6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_14:16;
        RBus_UInt32  dclk_profile_remap_15:16;
    };
}pll27x_reg_dclkss_profile7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_16:16;
        RBus_UInt32  dclk_profile_remap_17:16;
    };
}pll27x_reg_dclkss_profile8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_18:16;
        RBus_UInt32  dclk_profile_remap_19:16;
    };
}pll27x_reg_dclkss_profile9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_20:16;
        RBus_UInt32  dclk_profile_remap_21:16;
    };
}pll27x_reg_dclkss_profile10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_22:16;
        RBus_UInt32  dclk_profile_remap_23:16;
    };
}pll27x_reg_dclkss_profile11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_24:16;
        RBus_UInt32  dclk_profile_remap_25:16;
    };
}pll27x_reg_dclkss_profile12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_26:16;
        RBus_UInt32  dclk_profile_remap_27:16;
    };
}pll27x_reg_dclkss_profile13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_28:16;
        RBus_UInt32  dclk_profile_remap_29:16;
    };
}pll27x_reg_dclkss_profile14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_30:16;
        RBus_UInt32  dclk_profile_remap_31:16;
    };
}pll27x_reg_dclkss_profile15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  double_buf_apply:1;
        RBus_UInt32  double_buf_read_sel:1;
        RBus_UInt32  double_buf_en:1;
        RBus_UInt32  res1:29;
    };
}pll27x_reg_dpll_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  oc_step_set:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  fcode_t_ssc:11;
        RBus_UInt32  res3:5;
    };
}pll27x_reg_pll_ssc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sel_oc_mode:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  hs_oc_stop_diff:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  oc_done_delay:6;
        RBus_UInt32  res4:10;
    };
}pll27x_reg_pll_ssc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bypass_pi:1;
        RBus_UInt32  sdm_order:1;
        RBus_UInt32  en_pi_debug:1;
        RBus_UInt32  res1:29;
    };
}pll27x_reg_pll_ssc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcode_ssc:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  ncode_ssc:8;
        RBus_UInt32  res2:8;
    };
}pll27x_reg_pll_ssc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_ssc:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  gran_est:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  gran_auto_rst:1;
        RBus_UInt32  res4:3;
    };
}pll27x_reg_pll_ssc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fmod:1;
        RBus_UInt32  load_fcw:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  oc_done:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ncode_debug:8;
        RBus_UInt32  fcode_debug:11;
        RBus_UInt32  res3:5;
    };
}pll27x_reg_pll_ssc5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_cs:2;
        RBus_UInt32  dpll_cp:2;
        RBus_UInt32  dpll_rs:3;
        RBus_UInt32  dpll_ssc_inv:1;
        RBus_UInt32  dpll_ip:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  dpll_n:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  dpll_m:8;
        RBus_UInt32  res3:4;
    };
}pll27x_reg_sys_pll_disp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_x_bpsin:1;
        RBus_UInt32  dpll_x_bpspi:1;
        RBus_UInt32  res1:30;
    };
}pll27x_reg_sys_pll_disp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_pow:1;
        RBus_UInt32  dpll_vcorstb:1;
        RBus_UInt32  dpll_freeze:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dpll_wdset:1;
        RBus_UInt32  dpll_wdrst:1;
        RBus_UInt32  dpll_rstb:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  dpll_o:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  dpll_test_en:1;
        RBus_UInt32  dpll_prescaler:1;
        RBus_UInt32  dpll_picap:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  dpll_dummy:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  dpll_reser:4;
        RBus_UInt32  dpll_ldosel:2;
        RBus_UInt32  res6:1;
        RBus_UInt32  pif_dpll_src_sel:1;
    };
}pll27x_reg_sys_pll_disp3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_pi_ibsel:2;
        RBus_UInt32  dpll_ldodpll_pow:1;
        RBus_UInt32  res1:29;
    };
}pll27x_reg_sys_pll_disp4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sscg_offset_over_th_value:17;
        RBus_UInt32  res1:14;
        RBus_UInt32  sscg_offset_over_flag:1;
    };
}pll27x_reg_dpll_in_fsync_tracking_debug0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sscg_offset_over_th_max:17;
        RBus_UInt32  res1:15;
    };
}pll27x_reg_dpll_in_fsync_tracking_debug1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_fll_offset_over_th_value:17;
        RBus_UInt32  res1:14;
        RBus_UInt32  new_fll_offset_over_flag:1;
    };
}pll27x_reg_dpll_in_fsync_tracking_debug2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_fll_offset_over_th_max:17;
        RBus_UInt32  res1:15;
    };
}pll27x_reg_dpll_in_fsync_tracking_debug3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_fll_tracking_mul:19;
        RBus_UInt32  res1:1;
        RBus_UInt32  new_fll_tracking_offset_inverse:1;
        RBus_UInt32  res2:11;
    };
}pll27x_reg_dpll_in_fsync_tracking_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_fll_tracking_pos_th:16;
        RBus_UInt32  new_fll_tracking_neg_th:16;
    };
}pll27x_reg_dpll_in_fsync_tracking_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllallrstb:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pllsn:3;
        RBus_UInt32  pllsnbp:1;
        RBus_UInt32  pllssi:5;
        RBus_UInt32  pllsdiv2:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  pllsrs:3;
        RBus_UInt32  pllscs:2;
        RBus_UInt32  pllscp:1;
        RBus_UInt32  pll_emmc_ckssc_inv:1;
        RBus_UInt32  res3:1;
    };
}pll27x_reg_emmc_pll_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmcpwdn:1;
        RBus_UInt32  pllemmcldopow:1;
        RBus_UInt32  pllemmc_reg:2;
        RBus_UInt32  pllswdset:1;
        RBus_UInt32  pllswdrst:1;
        RBus_UInt32  pllsstatus:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllemmc_rsvd:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_pll_tp1_mux:3;
        RBus_UInt32  reg_pll_tp2_mux:3;
        RBus_UInt32  reg_pllemmc_bpspi:1;
        RBus_UInt32  res3:8;
    };
}pll27x_reg_emmc_pll_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllssck:6;
        RBus_UInt32  pllsy:1;
        RBus_UInt32  pllsx:1;
        RBus_UInt32  pllsd2y:1;
        RBus_UInt32  pllsd2x:1;
        RBus_UInt32  pllssck_2:6;
        RBus_UInt32  pllsy_2:1;
        RBus_UInt32  pllsx_2:1;
        RBus_UInt32  pllsd2y_2:1;
        RBus_UInt32  pllsd2x_2:1;
        RBus_UInt32  pllssck_3:6;
        RBus_UInt32  pllsy_3:1;
        RBus_UInt32  pllsx_3:1;
        RBus_UInt32  pllsd2y_3:1;
        RBus_UInt32  pllsd2x_3:1;
        RBus_UInt32  pll_pi_autoset:1;
        RBus_UInt32  res1:1;
    };
}pll27x_reg_emmc_pllphase_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllsphrs:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllsphrl:2;
        RBus_UInt32  res2:4;
        RBus_UInt32  pllssck_4:6;
        RBus_UInt32  pllsy_4:1;
        RBus_UInt32  pllsx_4:1;
        RBus_UInt32  pllsd2y_4:1;
        RBus_UInt32  pllsd2x_4:1;
        RBus_UInt32  res3:12;
    };
}pll27x_reg_emmc_pll_phase_interpolation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmc_oc_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllemmc_oc_step_set:10;
        RBus_UInt32  res2:18;
    };
}pll27x_reg_emmc_pll_ssc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllemmc_sel_oc_mode:2;
        RBus_UInt32  pllemmc_pi_cur_sel:2;
        RBus_UInt32  pllemmc_hs_oc_stop_diff:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllemmc_oc_done_delay:6;
        RBus_UInt32  res3:10;
    };
}pll27x_reg_emmc_pll_ssc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmc_bypass_pi:1;
        RBus_UInt32  pllemmc_sdm_order:1;
        RBus_UInt32  pllemmc_en_pi_debug:1;
        RBus_UInt32  res1:29;
    };
}pll27x_reg_emmc_pll_ssc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmc_fcode_ssc:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  pllemmc_ncode_ssc:8;
        RBus_UInt32  res2:8;
    };
}pll27x_reg_emmc_pll_ssc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmc_fcode_t:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  pllemmc_ncode_t:8;
        RBus_UInt32  res2:8;
    };
}pll27x_reg_emmc_pll_ssc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmc_en_ssc:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllemmc_gran_est:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllemmc_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllemmc_gran_auto_rst:1;
        RBus_UInt32  res4:3;
    };
}pll27x_reg_emmc_pll_ssc5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmc_fmod:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllemmc_oc_done:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  pllemmc_ncode_debug:8;
        RBus_UInt32  pllemmc_fcode_debug:11;
        RBus_UInt32  res3:5;
    };
}pll27x_reg_emmc_pll_ssc6_RBUS;




#endif 


#endif 
