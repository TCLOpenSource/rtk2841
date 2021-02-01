/**
* @file Mac5_LGCY_VE_Mbist_Arch_spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LGCY_VE_MBIST_REG_H_
#define _RBUS_LGCY_VE_MBIST_REG_H_

#include "rbus_types.h"



//  LGCY_VE_MBIST Register Address
#define  LGCY_VE_MBIST_ve_bist_rm                                                0x1800FE00
#define  LGCY_VE_MBIST_ve_bist_rm_reg_addr                                       "0xB800FE00"
#define  LGCY_VE_MBIST_ve_bist_rm_reg                                            0xB800FE00
#define  LGCY_VE_MBIST_ve_bist_rm_inst_addr                                      "0x0000"
#define  set_LGCY_VE_MBIST_ve_bist_rm_reg(data)                                  (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_rm_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_rm_reg                                        (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_rm_reg))
#define  LGCY_VE_MBIST_ve_bist_rm_test_rwm_shift                                 (31)
#define  LGCY_VE_MBIST_ve_bist_rm_bist_2p_clk_sel_shift                          (30)
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rmea_shift                                (29)
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rma_shift                                 (25)
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rmeb_shift                                (24)
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rmb_shift                                 (20)
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rme_shift                                 (19)
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rm_shift                                  (15)
#define  LGCY_VE_MBIST_ve_bist_rm_rmea_shift                                     (14)
#define  LGCY_VE_MBIST_ve_bist_rm_rma_shift                                      (10)
#define  LGCY_VE_MBIST_ve_bist_rm_rmeb_shift                                     (9)
#define  LGCY_VE_MBIST_ve_bist_rm_rmb_shift                                      (5)
#define  LGCY_VE_MBIST_ve_bist_rm_rme_shift                                      (4)
#define  LGCY_VE_MBIST_ve_bist_rm_rm_shift                                       (0)
#define  LGCY_VE_MBIST_ve_bist_rm_test_rwm_mask                                  (0x80000000)
#define  LGCY_VE_MBIST_ve_bist_rm_bist_2p_clk_sel_mask                           (0x40000000)
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rmea_mask                                 (0x20000000)
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rma_mask                                  (0x1E000000)
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rmeb_mask                                 (0x01000000)
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rmb_mask                                  (0x00F00000)
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rme_mask                                  (0x00080000)
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rm_mask                                   (0x00078000)
#define  LGCY_VE_MBIST_ve_bist_rm_rmea_mask                                      (0x00004000)
#define  LGCY_VE_MBIST_ve_bist_rm_rma_mask                                       (0x00003C00)
#define  LGCY_VE_MBIST_ve_bist_rm_rmeb_mask                                      (0x00000200)
#define  LGCY_VE_MBIST_ve_bist_rm_rmb_mask                                       (0x000001E0)
#define  LGCY_VE_MBIST_ve_bist_rm_rme_mask                                       (0x00000010)
#define  LGCY_VE_MBIST_ve_bist_rm_rm_mask                                        (0x0000000F)
#define  LGCY_VE_MBIST_ve_bist_rm_test_rwm(data)                                 (0x80000000&((data)<<31))
#define  LGCY_VE_MBIST_ve_bist_rm_bist_2p_clk_sel(data)                          (0x40000000&((data)<<30))
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rmea(data)                                (0x20000000&((data)<<29))
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rma(data)                                 (0x1E000000&((data)<<25))
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rmeb(data)                                (0x01000000&((data)<<24))
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rmb(data)                                 (0x00F00000&((data)<<20))
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rme(data)                                 (0x00080000&((data)<<19))
#define  LGCY_VE_MBIST_ve_bist_rm_sysh_rm(data)                                  (0x00078000&((data)<<15))
#define  LGCY_VE_MBIST_ve_bist_rm_rmea(data)                                     (0x00004000&((data)<<14))
#define  LGCY_VE_MBIST_ve_bist_rm_rma(data)                                      (0x00003C00&((data)<<10))
#define  LGCY_VE_MBIST_ve_bist_rm_rmeb(data)                                     (0x00000200&((data)<<9))
#define  LGCY_VE_MBIST_ve_bist_rm_rmb(data)                                      (0x000001E0&((data)<<5))
#define  LGCY_VE_MBIST_ve_bist_rm_rme(data)                                      (0x00000010&((data)<<4))
#define  LGCY_VE_MBIST_ve_bist_rm_rm(data)                                       (0x0000000F&(data))
#define  LGCY_VE_MBIST_ve_bist_rm_get_test_rwm(data)                             ((0x80000000&(data))>>31)
#define  LGCY_VE_MBIST_ve_bist_rm_get_bist_2p_clk_sel(data)                      ((0x40000000&(data))>>30)
#define  LGCY_VE_MBIST_ve_bist_rm_get_sysh_rmea(data)                            ((0x20000000&(data))>>29)
#define  LGCY_VE_MBIST_ve_bist_rm_get_sysh_rma(data)                             ((0x1E000000&(data))>>25)
#define  LGCY_VE_MBIST_ve_bist_rm_get_sysh_rmeb(data)                            ((0x01000000&(data))>>24)
#define  LGCY_VE_MBIST_ve_bist_rm_get_sysh_rmb(data)                             ((0x00F00000&(data))>>20)
#define  LGCY_VE_MBIST_ve_bist_rm_get_sysh_rme(data)                             ((0x00080000&(data))>>19)
#define  LGCY_VE_MBIST_ve_bist_rm_get_sysh_rm(data)                              ((0x00078000&(data))>>15)
#define  LGCY_VE_MBIST_ve_bist_rm_get_rmea(data)                                 ((0x00004000&(data))>>14)
#define  LGCY_VE_MBIST_ve_bist_rm_get_rma(data)                                  ((0x00003C00&(data))>>10)
#define  LGCY_VE_MBIST_ve_bist_rm_get_rmeb(data)                                 ((0x00000200&(data))>>9)
#define  LGCY_VE_MBIST_ve_bist_rm_get_rmb(data)                                  ((0x000001E0&(data))>>5)
#define  LGCY_VE_MBIST_ve_bist_rm_get_rme(data)                                  ((0x00000010&(data))>>4)
#define  LGCY_VE_MBIST_ve_bist_rm_get_rm(data)                                   (0x0000000F&(data))

#define  LGCY_VE_MBIST_ve_bist_ls_0                                              0x1800FE24
#define  LGCY_VE_MBIST_ve_bist_ls_0_reg_addr                                     "0xB800FE24"
#define  LGCY_VE_MBIST_ve_bist_ls_0_reg                                          0xB800FE24
#define  LGCY_VE_MBIST_ve_bist_ls_0_inst_addr                                    "0x0001"
#define  set_LGCY_VE_MBIST_ve_bist_ls_0_reg(data)                                (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_ls_0_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_ls_0_reg                                      (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_ls_0_reg))
#define  LGCY_VE_MBIST_ve_bist_ls_0_ip_gc_ls_shift                               (30)
#define  LGCY_VE_MBIST_ve_bist_ls_0_fme_ls_shift                                 (28)
#define  LGCY_VE_MBIST_ve_bist_ls_0_ndb_ls_shift                                 (26)
#define  LGCY_VE_MBIST_ve_bist_ls_0_bs_ls_shift                                  (24)
#define  LGCY_VE_MBIST_ve_bist_ls_0_dmem_ls_shift                                (22)
#define  LGCY_VE_MBIST_ve_bist_ls_0_brg_ls_shift                                 (20)
#define  LGCY_VE_MBIST_ve_bist_ls_0_vmem_ls_shift                                (18)
#define  LGCY_VE_MBIST_ve_bist_ls_0_cmprs_ls_shift                               (16)
#define  LGCY_VE_MBIST_ve_bist_ls_0_deblk_ls_shift                               (14)
#define  LGCY_VE_MBIST_ve_bist_ls_0_pred_ls_shift                                (12)
#define  LGCY_VE_MBIST_ve_bist_ls_0_cache_ls_shift                               (10)
#define  LGCY_VE_MBIST_ve_bist_ls_0_rl_ls_shift                                  (8)
#define  LGCY_VE_MBIST_ve_bist_ls_0_cm_ls_shift                                  (6)
#define  LGCY_VE_MBIST_ve_bist_ls_0_itblk_ls_shift                               (4)
#define  LGCY_VE_MBIST_ve_bist_ls_0_mvd_ls_shift                                 (2)
#define  LGCY_VE_MBIST_ve_bist_ls_0_vld_ls_shift                                 (0)
#define  LGCY_VE_MBIST_ve_bist_ls_0_ip_gc_ls_mask                                (0xC0000000)
#define  LGCY_VE_MBIST_ve_bist_ls_0_fme_ls_mask                                  (0x30000000)
#define  LGCY_VE_MBIST_ve_bist_ls_0_ndb_ls_mask                                  (0x0C000000)
#define  LGCY_VE_MBIST_ve_bist_ls_0_bs_ls_mask                                   (0x03000000)
#define  LGCY_VE_MBIST_ve_bist_ls_0_dmem_ls_mask                                 (0x00C00000)
#define  LGCY_VE_MBIST_ve_bist_ls_0_brg_ls_mask                                  (0x00300000)
#define  LGCY_VE_MBIST_ve_bist_ls_0_vmem_ls_mask                                 (0x000C0000)
#define  LGCY_VE_MBIST_ve_bist_ls_0_cmprs_ls_mask                                (0x00030000)
#define  LGCY_VE_MBIST_ve_bist_ls_0_deblk_ls_mask                                (0x0000C000)
#define  LGCY_VE_MBIST_ve_bist_ls_0_pred_ls_mask                                 (0x00003000)
#define  LGCY_VE_MBIST_ve_bist_ls_0_cache_ls_mask                                (0x00000C00)
#define  LGCY_VE_MBIST_ve_bist_ls_0_rl_ls_mask                                   (0x00000300)
#define  LGCY_VE_MBIST_ve_bist_ls_0_cm_ls_mask                                   (0x000000C0)
#define  LGCY_VE_MBIST_ve_bist_ls_0_itblk_ls_mask                                (0x00000030)
#define  LGCY_VE_MBIST_ve_bist_ls_0_mvd_ls_mask                                  (0x0000000C)
#define  LGCY_VE_MBIST_ve_bist_ls_0_vld_ls_mask                                  (0x00000003)
#define  LGCY_VE_MBIST_ve_bist_ls_0_ip_gc_ls(data)                               (0xC0000000&((data)<<30))
#define  LGCY_VE_MBIST_ve_bist_ls_0_fme_ls(data)                                 (0x30000000&((data)<<28))
#define  LGCY_VE_MBIST_ve_bist_ls_0_ndb_ls(data)                                 (0x0C000000&((data)<<26))
#define  LGCY_VE_MBIST_ve_bist_ls_0_bs_ls(data)                                  (0x03000000&((data)<<24))
#define  LGCY_VE_MBIST_ve_bist_ls_0_dmem_ls(data)                                (0x00C00000&((data)<<22))
#define  LGCY_VE_MBIST_ve_bist_ls_0_brg_ls(data)                                 (0x00300000&((data)<<20))
#define  LGCY_VE_MBIST_ve_bist_ls_0_vmem_ls(data)                                (0x000C0000&((data)<<18))
#define  LGCY_VE_MBIST_ve_bist_ls_0_cmprs_ls(data)                               (0x00030000&((data)<<16))
#define  LGCY_VE_MBIST_ve_bist_ls_0_deblk_ls(data)                               (0x0000C000&((data)<<14))
#define  LGCY_VE_MBIST_ve_bist_ls_0_pred_ls(data)                                (0x00003000&((data)<<12))
#define  LGCY_VE_MBIST_ve_bist_ls_0_cache_ls(data)                               (0x00000C00&((data)<<10))
#define  LGCY_VE_MBIST_ve_bist_ls_0_rl_ls(data)                                  (0x00000300&((data)<<8))
#define  LGCY_VE_MBIST_ve_bist_ls_0_cm_ls(data)                                  (0x000000C0&((data)<<6))
#define  LGCY_VE_MBIST_ve_bist_ls_0_itblk_ls(data)                               (0x00000030&((data)<<4))
#define  LGCY_VE_MBIST_ve_bist_ls_0_mvd_ls(data)                                 (0x0000000C&((data)<<2))
#define  LGCY_VE_MBIST_ve_bist_ls_0_vld_ls(data)                                 (0x00000003&(data))
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_ip_gc_ls(data)                           ((0xC0000000&(data))>>30)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_fme_ls(data)                             ((0x30000000&(data))>>28)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_ndb_ls(data)                             ((0x0C000000&(data))>>26)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_bs_ls(data)                              ((0x03000000&(data))>>24)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_dmem_ls(data)                            ((0x00C00000&(data))>>22)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_brg_ls(data)                             ((0x00300000&(data))>>20)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_vmem_ls(data)                            ((0x000C0000&(data))>>18)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_cmprs_ls(data)                           ((0x00030000&(data))>>16)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_deblk_ls(data)                           ((0x0000C000&(data))>>14)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_pred_ls(data)                            ((0x00003000&(data))>>12)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_cache_ls(data)                           ((0x00000C00&(data))>>10)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_rl_ls(data)                              ((0x00000300&(data))>>8)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_cm_ls(data)                              ((0x000000C0&(data))>>6)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_itblk_ls(data)                           ((0x00000030&(data))>>4)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_mvd_ls(data)                             ((0x0000000C&(data))>>2)
#define  LGCY_VE_MBIST_ve_bist_ls_0_get_vld_ls(data)                             (0x00000003&(data))

#define  LGCY_VE_MBIST_ve_bist_mode                                              0x1800FE04
#define  LGCY_VE_MBIST_ve_bist_mode_reg_addr                                     "0xB800FE04"
#define  LGCY_VE_MBIST_ve_bist_mode_reg                                          0xB800FE04
#define  LGCY_VE_MBIST_ve_bist_mode_inst_addr                                    "0x0002"
#define  set_LGCY_VE_MBIST_ve_bist_mode_reg(data)                                (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_mode_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_mode_reg                                      (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_mode_reg))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_dmem_bist_en_shift                        (17)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_ip_gc_bist_en_shift                       (16)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_pred_2p_bist_en_shift                     (15)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_pred_bist_en_shift                        (14)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_fme_bist_en_shift                         (13)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_cah_2p_bist_en_shift                      (12)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_cah_1p_bist_en_shift                      (11)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_dbk_bist_en_shift                         (10)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_mvd_rlmvbuf_bist_en_shift                 (9)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_rlrmem_fme_bist_en_shift                  (8)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_cm_bist_en_shift                          (7)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_ndb_bist_en_shift                         (6)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_brg_bist_en_shift                         (5)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_it_bs_bist_en_shift                       (4)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_it_bist_en_shift                          (3)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_vm_bist_en_shift                          (2)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_vld_bist_en_shift                         (1)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_rif_bist_en_shift                         (0)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_dmem_bist_en_mask                         (0x00020000)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_ip_gc_bist_en_mask                        (0x00010000)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_pred_2p_bist_en_mask                      (0x00008000)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_pred_bist_en_mask                         (0x00004000)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_fme_bist_en_mask                          (0x00002000)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_cah_2p_bist_en_mask                       (0x00001000)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_cah_1p_bist_en_mask                       (0x00000800)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_dbk_bist_en_mask                          (0x00000400)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_mvd_rlmvbuf_bist_en_mask                  (0x00000200)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_rlrmem_fme_bist_en_mask                   (0x00000100)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_cm_bist_en_mask                           (0x00000080)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_ndb_bist_en_mask                          (0x00000040)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_brg_bist_en_mask                          (0x00000020)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_it_bs_bist_en_mask                        (0x00000010)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_it_bist_en_mask                           (0x00000008)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_vm_bist_en_mask                           (0x00000004)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_vld_bist_en_mask                          (0x00000002)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_rif_bist_en_mask                          (0x00000001)
#define  LGCY_VE_MBIST_ve_bist_mode_ve_dmem_bist_en(data)                        (0x00020000&((data)<<17))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_ip_gc_bist_en(data)                       (0x00010000&((data)<<16))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_pred_2p_bist_en(data)                     (0x00008000&((data)<<15))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_pred_bist_en(data)                        (0x00004000&((data)<<14))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_fme_bist_en(data)                         (0x00002000&((data)<<13))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_cah_2p_bist_en(data)                      (0x00001000&((data)<<12))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_cah_1p_bist_en(data)                      (0x00000800&((data)<<11))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_dbk_bist_en(data)                         (0x00000400&((data)<<10))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_mvd_rlmvbuf_bist_en(data)                 (0x00000200&((data)<<9))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_rlrmem_fme_bist_en(data)                  (0x00000100&((data)<<8))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_cm_bist_en(data)                          (0x00000080&((data)<<7))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_ndb_bist_en(data)                         (0x00000040&((data)<<6))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_brg_bist_en(data)                         (0x00000020&((data)<<5))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_it_bs_bist_en(data)                       (0x00000010&((data)<<4))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_it_bist_en(data)                          (0x00000008&((data)<<3))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_vm_bist_en(data)                          (0x00000004&((data)<<2))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_vld_bist_en(data)                         (0x00000002&((data)<<1))
#define  LGCY_VE_MBIST_ve_bist_mode_ve_rif_bist_en(data)                         (0x00000001&(data))
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_dmem_bist_en(data)                    ((0x00020000&(data))>>17)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_ip_gc_bist_en(data)                   ((0x00010000&(data))>>16)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_pred_2p_bist_en(data)                 ((0x00008000&(data))>>15)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_pred_bist_en(data)                    ((0x00004000&(data))>>14)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_fme_bist_en(data)                     ((0x00002000&(data))>>13)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_cah_2p_bist_en(data)                  ((0x00001000&(data))>>12)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_cah_1p_bist_en(data)                  ((0x00000800&(data))>>11)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_dbk_bist_en(data)                     ((0x00000400&(data))>>10)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_mvd_rlmvbuf_bist_en(data)             ((0x00000200&(data))>>9)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_rlrmem_fme_bist_en(data)              ((0x00000100&(data))>>8)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_cm_bist_en(data)                      ((0x00000080&(data))>>7)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_ndb_bist_en(data)                     ((0x00000040&(data))>>6)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_brg_bist_en(data)                     ((0x00000020&(data))>>5)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_it_bs_bist_en(data)                   ((0x00000010&(data))>>4)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_it_bist_en(data)                      ((0x00000008&(data))>>3)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_vm_bist_en(data)                      ((0x00000004&(data))>>2)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_vld_bist_en(data)                     ((0x00000002&(data))>>1)
#define  LGCY_VE_MBIST_ve_bist_mode_get_ve_rif_bist_en(data)                     (0x00000001&(data))

#define  LGCY_VE_MBIST_ve_bist_done                                              0x1800FE08
#define  LGCY_VE_MBIST_ve_bist_done_reg_addr                                     "0xB800FE08"
#define  LGCY_VE_MBIST_ve_bist_done_reg                                          0xB800FE08
#define  LGCY_VE_MBIST_ve_bist_done_inst_addr                                    "0x0003"
#define  set_LGCY_VE_MBIST_ve_bist_done_reg(data)                                (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_done_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_done_reg                                      (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_done_reg))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_dmem_done_shift                      (17)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_ip_gc_done_shift                     (16)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_pred_2p_done_shift                   (15)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_pred_done_shift                      (14)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_fme_done_shift                       (13)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_cah_2p_done_shift                    (12)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_cah_1p_done_shift                    (11)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_dbk_done_shift                       (10)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_mvd_rlmvbuf_done_shift               (9)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_rlrmem_fme_done_shift                (8)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_cm_done_shift                        (7)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_ndb_done_shift                       (6)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_brg_done_shift                       (5)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_it_bs_done_shift                     (4)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_it_done_shift                        (3)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_vm_done_shift                        (2)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_vld_done_shift                       (1)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_rif_done_shift                       (0)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_dmem_done_mask                       (0x00020000)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_ip_gc_done_mask                      (0x00010000)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_pred_2p_done_mask                    (0x00008000)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_pred_done_mask                       (0x00004000)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_fme_done_mask                        (0x00002000)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_cah_2p_done_mask                     (0x00001000)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_cah_1p_done_mask                     (0x00000800)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_dbk_done_mask                        (0x00000400)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_mvd_rlmvbuf_done_mask                (0x00000200)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_rlrmem_fme_done_mask                 (0x00000100)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_cm_done_mask                         (0x00000080)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_ndb_done_mask                        (0x00000040)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_brg_done_mask                        (0x00000020)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_it_bs_done_mask                      (0x00000010)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_it_done_mask                         (0x00000008)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_vm_done_mask                         (0x00000004)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_vld_done_mask                        (0x00000002)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_rif_done_mask                        (0x00000001)
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_dmem_done(data)                      (0x00020000&((data)<<17))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_ip_gc_done(data)                     (0x00010000&((data)<<16))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_pred_2p_done(data)                   (0x00008000&((data)<<15))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_pred_done(data)                      (0x00004000&((data)<<14))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_fme_done(data)                       (0x00002000&((data)<<13))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_cah_2p_done(data)                    (0x00001000&((data)<<12))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_cah_1p_done(data)                    (0x00000800&((data)<<11))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_dbk_done(data)                       (0x00000400&((data)<<10))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_mvd_rlmvbuf_done(data)               (0x00000200&((data)<<9))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_rlrmem_fme_done(data)                (0x00000100&((data)<<8))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_cm_done(data)                        (0x00000080&((data)<<7))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_ndb_done(data)                       (0x00000040&((data)<<6))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_brg_done(data)                       (0x00000020&((data)<<5))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_it_bs_done(data)                     (0x00000010&((data)<<4))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_it_done(data)                        (0x00000008&((data)<<3))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_vm_done(data)                        (0x00000004&((data)<<2))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_vld_done(data)                       (0x00000002&((data)<<1))
#define  LGCY_VE_MBIST_ve_bist_done_ve_bist_rif_done(data)                       (0x00000001&(data))
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_dmem_done(data)                  ((0x00020000&(data))>>17)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_ip_gc_done(data)                 ((0x00010000&(data))>>16)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_pred_2p_done(data)               ((0x00008000&(data))>>15)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_pred_done(data)                  ((0x00004000&(data))>>14)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_fme_done(data)                   ((0x00002000&(data))>>13)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_cah_2p_done(data)                ((0x00001000&(data))>>12)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_cah_1p_done(data)                ((0x00000800&(data))>>11)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_dbk_done(data)                   ((0x00000400&(data))>>10)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_mvd_rlmvbuf_done(data)           ((0x00000200&(data))>>9)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_rlrmem_fme_done(data)            ((0x00000100&(data))>>8)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_cm_done(data)                    ((0x00000080&(data))>>7)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_ndb_done(data)                   ((0x00000040&(data))>>6)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_brg_done(data)                   ((0x00000020&(data))>>5)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_it_bs_done(data)                 ((0x00000010&(data))>>4)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_it_done(data)                    ((0x00000008&(data))>>3)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_vm_done(data)                    ((0x00000004&(data))>>2)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_vld_done(data)                   ((0x00000002&(data))>>1)
#define  LGCY_VE_MBIST_ve_bist_done_get_ve_bist_rif_done(data)                   (0x00000001&(data))

#define  LGCY_VE_MBIST_ve_bist_fail_group                                        0x1800FE0C
#define  LGCY_VE_MBIST_ve_bist_fail_group_reg_addr                               "0xB800FE0C"
#define  LGCY_VE_MBIST_ve_bist_fail_group_reg                                    0xB800FE0C
#define  LGCY_VE_MBIST_ve_bist_fail_group_inst_addr                              "0x0004"
#define  set_LGCY_VE_MBIST_ve_bist_fail_group_reg(data)                          (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_fail_group_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_fail_group_reg                                (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_fail_group_reg))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_dmem_fail_group_shift          (17)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_ip_gc_fail_group_shift         (16)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_pred_2p_fail_group_shift       (15)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_pred_fail_group_shift          (14)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_fme_fail_group_shift           (13)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_cah_2p_fail_group_shift        (12)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_cah_1p_fail_group_shift        (11)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_dbk_fail_group_shift           (10)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_mvd_rlmvbuf_fail_group_shift   (9)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_rlrmem_fme_fail_group_shift    (8)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_cm_fail_group_shift            (7)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_ndb_fail_group_shift           (6)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_brg_fail_group_shift           (5)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_it_bs_fail_group_shift         (4)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_it_fail_group_shift            (3)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_vm_fail_group_shift            (2)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_vld_fail_group_shift           (1)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_rif_fail_group_shift           (0)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_dmem_fail_group_mask           (0x00020000)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_ip_gc_fail_group_mask          (0x00010000)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_pred_2p_fail_group_mask        (0x00008000)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_pred_fail_group_mask           (0x00004000)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_fme_fail_group_mask            (0x00002000)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_cah_2p_fail_group_mask         (0x00001000)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_cah_1p_fail_group_mask         (0x00000800)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_dbk_fail_group_mask            (0x00000400)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_mvd_rlmvbuf_fail_group_mask    (0x00000200)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_rlrmem_fme_fail_group_mask     (0x00000100)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_cm_fail_group_mask             (0x00000080)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_ndb_fail_group_mask            (0x00000040)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_brg_fail_group_mask            (0x00000020)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_it_bs_fail_group_mask          (0x00000010)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_it_fail_group_mask             (0x00000008)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_vm_fail_group_mask             (0x00000004)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_vld_fail_group_mask            (0x00000002)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_rif_fail_group_mask            (0x00000001)
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_dmem_fail_group(data)          (0x00020000&((data)<<17))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_ip_gc_fail_group(data)         (0x00010000&((data)<<16))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_pred_2p_fail_group(data)       (0x00008000&((data)<<15))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_pred_fail_group(data)          (0x00004000&((data)<<14))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_fme_fail_group(data)           (0x00002000&((data)<<13))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_cah_2p_fail_group(data)        (0x00001000&((data)<<12))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_cah_1p_fail_group(data)        (0x00000800&((data)<<11))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_dbk_fail_group(data)           (0x00000400&((data)<<10))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_mvd_rlmvbuf_fail_group(data)   (0x00000200&((data)<<9))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_rlrmem_fme_fail_group(data)    (0x00000100&((data)<<8))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_cm_fail_group(data)            (0x00000080&((data)<<7))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_ndb_fail_group(data)           (0x00000040&((data)<<6))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_brg_fail_group(data)           (0x00000020&((data)<<5))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_it_bs_fail_group(data)         (0x00000010&((data)<<4))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_it_fail_group(data)            (0x00000008&((data)<<3))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_vm_fail_group(data)            (0x00000004&((data)<<2))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_vld_fail_group(data)           (0x00000002&((data)<<1))
#define  LGCY_VE_MBIST_ve_bist_fail_group_ve_bist_rif_fail_group(data)           (0x00000001&(data))
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_dmem_fail_group(data)      ((0x00020000&(data))>>17)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_ip_gc_fail_group(data)     ((0x00010000&(data))>>16)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_pred_2p_fail_group(data)   ((0x00008000&(data))>>15)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_pred_fail_group(data)      ((0x00004000&(data))>>14)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_fme_fail_group(data)       ((0x00002000&(data))>>13)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_cah_2p_fail_group(data)    ((0x00001000&(data))>>12)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_cah_1p_fail_group(data)    ((0x00000800&(data))>>11)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_dbk_fail_group(data)       ((0x00000400&(data))>>10)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_mvd_rlmvbuf_fail_group(data) ((0x00000200&(data))>>9)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_rlrmem_fme_fail_group(data) ((0x00000100&(data))>>8)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_cm_fail_group(data)        ((0x00000080&(data))>>7)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_ndb_fail_group(data)       ((0x00000040&(data))>>6)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_brg_fail_group(data)       ((0x00000020&(data))>>5)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_it_bs_fail_group(data)     ((0x00000010&(data))>>4)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_it_fail_group(data)        ((0x00000008&(data))>>3)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_vm_fail_group(data)        ((0x00000004&(data))>>2)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_vld_fail_group(data)       ((0x00000002&(data))>>1)
#define  LGCY_VE_MBIST_ve_bist_fail_group_get_ve_bist_rif_fail_group(data)       (0x00000001&(data))

#define  LGCY_VE_MBIST_ve_drf_mode                                               0x1800FE10
#define  LGCY_VE_MBIST_ve_drf_mode_reg_addr                                      "0xB800FE10"
#define  LGCY_VE_MBIST_ve_drf_mode_reg                                           0xB800FE10
#define  LGCY_VE_MBIST_ve_drf_mode_inst_addr                                     "0x0005"
#define  set_LGCY_VE_MBIST_ve_drf_mode_reg(data)                                 (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_mode_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_mode_reg                                       (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_mode_reg))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_dmem_drf_bist_en_shift                     (17)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_ip_gc_drf_bist_en_shift                    (16)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_pred_2p_drf_bist_en_shift                  (15)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_pred_drf_bist_en_shift                     (14)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_fme_drf_bist_en_shift                      (13)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_cah_2p_drf_bist_en_shift                   (12)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_cah_1p_drf_bist_en_shift                   (11)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_dbk_drf_bist_en_shift                      (10)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_mvd_rlmvbuf_drf_bist_en_shift              (9)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_rlrmem_fme_drf_bist_en_shift               (8)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_cm_drf_bist_en_shift                       (7)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_ndb_drf_bist_en_shift                      (6)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_brg_drf_bist_en_shift                      (5)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_it_bs_drf_bist_en_shift                    (4)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_it_drf_bist_en_shift                       (3)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_vm_drf_bist_en_shift                       (2)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_vld_drf_bist_en_shift                      (1)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_rif_drf_bist_en_shift                      (0)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_dmem_drf_bist_en_mask                      (0x00020000)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_ip_gc_drf_bist_en_mask                     (0x00010000)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_pred_2p_drf_bist_en_mask                   (0x00008000)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_pred_drf_bist_en_mask                      (0x00004000)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_fme_drf_bist_en_mask                       (0x00002000)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_cah_2p_drf_bist_en_mask                    (0x00001000)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_cah_1p_drf_bist_en_mask                    (0x00000800)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_dbk_drf_bist_en_mask                       (0x00000400)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_mvd_rlmvbuf_drf_bist_en_mask               (0x00000200)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_rlrmem_fme_drf_bist_en_mask                (0x00000100)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_cm_drf_bist_en_mask                        (0x00000080)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_ndb_drf_bist_en_mask                       (0x00000040)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_brg_drf_bist_en_mask                       (0x00000020)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_it_bs_drf_bist_en_mask                     (0x00000010)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_it_drf_bist_en_mask                        (0x00000008)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_vm_drf_bist_en_mask                        (0x00000004)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_vld_drf_bist_en_mask                       (0x00000002)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_rif_drf_bist_en_mask                       (0x00000001)
#define  LGCY_VE_MBIST_ve_drf_mode_ve_dmem_drf_bist_en(data)                     (0x00020000&((data)<<17))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_ip_gc_drf_bist_en(data)                    (0x00010000&((data)<<16))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_pred_2p_drf_bist_en(data)                  (0x00008000&((data)<<15))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_pred_drf_bist_en(data)                     (0x00004000&((data)<<14))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_fme_drf_bist_en(data)                      (0x00002000&((data)<<13))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_cah_2p_drf_bist_en(data)                   (0x00001000&((data)<<12))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_cah_1p_drf_bist_en(data)                   (0x00000800&((data)<<11))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_dbk_drf_bist_en(data)                      (0x00000400&((data)<<10))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_mvd_rlmvbuf_drf_bist_en(data)              (0x00000200&((data)<<9))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_rlrmem_fme_drf_bist_en(data)               (0x00000100&((data)<<8))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_cm_drf_bist_en(data)                       (0x00000080&((data)<<7))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_ndb_drf_bist_en(data)                      (0x00000040&((data)<<6))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_brg_drf_bist_en(data)                      (0x00000020&((data)<<5))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_it_bs_drf_bist_en(data)                    (0x00000010&((data)<<4))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_it_drf_bist_en(data)                       (0x00000008&((data)<<3))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_vm_drf_bist_en(data)                       (0x00000004&((data)<<2))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_vld_drf_bist_en(data)                      (0x00000002&((data)<<1))
#define  LGCY_VE_MBIST_ve_drf_mode_ve_rif_drf_bist_en(data)                      (0x00000001&(data))
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_dmem_drf_bist_en(data)                 ((0x00020000&(data))>>17)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_ip_gc_drf_bist_en(data)                ((0x00010000&(data))>>16)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_pred_2p_drf_bist_en(data)              ((0x00008000&(data))>>15)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_pred_drf_bist_en(data)                 ((0x00004000&(data))>>14)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_fme_drf_bist_en(data)                  ((0x00002000&(data))>>13)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_cah_2p_drf_bist_en(data)               ((0x00001000&(data))>>12)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_cah_1p_drf_bist_en(data)               ((0x00000800&(data))>>11)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_dbk_drf_bist_en(data)                  ((0x00000400&(data))>>10)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_mvd_rlmvbuf_drf_bist_en(data)          ((0x00000200&(data))>>9)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_rlrmem_fme_drf_bist_en(data)           ((0x00000100&(data))>>8)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_cm_drf_bist_en(data)                   ((0x00000080&(data))>>7)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_ndb_drf_bist_en(data)                  ((0x00000040&(data))>>6)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_brg_drf_bist_en(data)                  ((0x00000020&(data))>>5)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_it_bs_drf_bist_en(data)                ((0x00000010&(data))>>4)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_it_drf_bist_en(data)                   ((0x00000008&(data))>>3)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_vm_drf_bist_en(data)                   ((0x00000004&(data))>>2)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_vld_drf_bist_en(data)                  ((0x00000002&(data))>>1)
#define  LGCY_VE_MBIST_ve_drf_mode_get_ve_rif_drf_bist_en(data)                  (0x00000001&(data))

#define  LGCY_VE_MBIST_ve_drf_resume                                             0x1800FE14
#define  LGCY_VE_MBIST_ve_drf_resume_reg_addr                                    "0xB800FE14"
#define  LGCY_VE_MBIST_ve_drf_resume_reg                                         0xB800FE14
#define  LGCY_VE_MBIST_ve_drf_resume_inst_addr                                   "0x0006"
#define  set_LGCY_VE_MBIST_ve_drf_resume_reg(data)                               (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_resume_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_resume_reg                                     (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_resume_reg))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_dmem_drf_resume_shift                    (17)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_ip_gc_drf_resume_shift                   (16)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_pred_2p_drf_resume_shift                 (15)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_pred_drf_resume_shift                    (14)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_fme_drf_resume_shift                     (13)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_cah_2p_drf_resume_shift                  (12)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_cah_1p_drf_resume_shift                  (11)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_dbk_drf_resume_shift                     (10)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_mvd_rlmvbuf_drf_resume_shift             (9)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_rlrmem_fme_drf_resume_shift              (8)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_cm_drf_resume_shift                      (7)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_ndb_drf_resume_shift                     (6)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_brg_drf_resume_shift                     (5)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_it_bs_drf_resume_shift                   (4)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_it_drf_resume_shift                      (3)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_vm_drf_resume_shift                      (2)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_vld_drf_resume_shift                     (1)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_rif_drf_resume_shift                     (0)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_dmem_drf_resume_mask                     (0x00020000)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_ip_gc_drf_resume_mask                    (0x00010000)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_pred_2p_drf_resume_mask                  (0x00008000)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_pred_drf_resume_mask                     (0x00004000)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_fme_drf_resume_mask                      (0x00002000)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_cah_2p_drf_resume_mask                   (0x00001000)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_cah_1p_drf_resume_mask                   (0x00000800)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_dbk_drf_resume_mask                      (0x00000400)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_mvd_rlmvbuf_drf_resume_mask              (0x00000200)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_rlrmem_fme_drf_resume_mask               (0x00000100)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_cm_drf_resume_mask                       (0x00000080)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_ndb_drf_resume_mask                      (0x00000040)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_brg_drf_resume_mask                      (0x00000020)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_it_bs_drf_resume_mask                    (0x00000010)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_it_drf_resume_mask                       (0x00000008)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_vm_drf_resume_mask                       (0x00000004)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_vld_drf_resume_mask                      (0x00000002)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_rif_drf_resume_mask                      (0x00000001)
#define  LGCY_VE_MBIST_ve_drf_resume_ve_dmem_drf_resume(data)                    (0x00020000&((data)<<17))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_ip_gc_drf_resume(data)                   (0x00010000&((data)<<16))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_pred_2p_drf_resume(data)                 (0x00008000&((data)<<15))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_pred_drf_resume(data)                    (0x00004000&((data)<<14))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_fme_drf_resume(data)                     (0x00002000&((data)<<13))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_cah_2p_drf_resume(data)                  (0x00001000&((data)<<12))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_cah_1p_drf_resume(data)                  (0x00000800&((data)<<11))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_dbk_drf_resume(data)                     (0x00000400&((data)<<10))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_mvd_rlmvbuf_drf_resume(data)             (0x00000200&((data)<<9))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_rlrmem_fme_drf_resume(data)              (0x00000100&((data)<<8))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_cm_drf_resume(data)                      (0x00000080&((data)<<7))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_ndb_drf_resume(data)                     (0x00000040&((data)<<6))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_brg_drf_resume(data)                     (0x00000020&((data)<<5))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_it_bs_drf_resume(data)                   (0x00000010&((data)<<4))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_it_drf_resume(data)                      (0x00000008&((data)<<3))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_vm_drf_resume(data)                      (0x00000004&((data)<<2))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_vld_drf_resume(data)                     (0x00000002&((data)<<1))
#define  LGCY_VE_MBIST_ve_drf_resume_ve_rif_drf_resume(data)                     (0x00000001&(data))
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_dmem_drf_resume(data)                ((0x00020000&(data))>>17)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_ip_gc_drf_resume(data)               ((0x00010000&(data))>>16)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_pred_2p_drf_resume(data)             ((0x00008000&(data))>>15)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_pred_drf_resume(data)                ((0x00004000&(data))>>14)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_fme_drf_resume(data)                 ((0x00002000&(data))>>13)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_cah_2p_drf_resume(data)              ((0x00001000&(data))>>12)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_cah_1p_drf_resume(data)              ((0x00000800&(data))>>11)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_dbk_drf_resume(data)                 ((0x00000400&(data))>>10)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_mvd_rlmvbuf_drf_resume(data)         ((0x00000200&(data))>>9)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_rlrmem_fme_drf_resume(data)          ((0x00000100&(data))>>8)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_cm_drf_resume(data)                  ((0x00000080&(data))>>7)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_ndb_drf_resume(data)                 ((0x00000040&(data))>>6)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_brg_drf_resume(data)                 ((0x00000020&(data))>>5)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_it_bs_drf_resume(data)               ((0x00000010&(data))>>4)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_it_drf_resume(data)                  ((0x00000008&(data))>>3)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_vm_drf_resume(data)                  ((0x00000004&(data))>>2)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_vld_drf_resume(data)                 ((0x00000002&(data))>>1)
#define  LGCY_VE_MBIST_ve_drf_resume_get_ve_rif_drf_resume(data)                 (0x00000001&(data))

#define  LGCY_VE_MBIST_ve_drf_pause                                              0x1800FE18
#define  LGCY_VE_MBIST_ve_drf_pause_reg_addr                                     "0xB800FE18"
#define  LGCY_VE_MBIST_ve_drf_pause_reg                                          0xB800FE18
#define  LGCY_VE_MBIST_ve_drf_pause_inst_addr                                    "0x0007"
#define  set_LGCY_VE_MBIST_ve_drf_pause_reg(data)                                (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_pause_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_pause_reg                                      (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_pause_reg))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_dmem_drf_start_pause_shift                (17)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_ip_gc_drf_start_pause_shift               (16)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_pred_2p_drf_start_pause_shift             (15)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_pred_drf_start_pause_shift                (14)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_fme_drf_start_pause_shift                 (13)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_cah_2p_drf_start_pause_shift              (12)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_cah_1p_drf_start_pause_shift              (11)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_dbk_drf_start_pause_shift                 (10)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_mvd_rlmvbuf_drf_start_pause_shift         (9)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_rlrmem_fme_drf_start_pause_shift          (8)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_cm_drf_start_pause_shift                  (7)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_ndb_drf_start_pause_shift                 (6)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_brg_drf_start_pause_shift                 (5)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_it_bs_drf_start_pause_shift               (4)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_it_drf_start_pause_shift                  (3)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_vm_drf_start_pause_shift                  (2)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_vld_drf_start_pause_shift                 (1)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_rif_drf_start_pause_shift                 (0)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_dmem_drf_start_pause_mask                 (0x00020000)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_ip_gc_drf_start_pause_mask                (0x00010000)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_pred_2p_drf_start_pause_mask              (0x00008000)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_pred_drf_start_pause_mask                 (0x00004000)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_fme_drf_start_pause_mask                  (0x00002000)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_cah_2p_drf_start_pause_mask               (0x00001000)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_cah_1p_drf_start_pause_mask               (0x00000800)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_dbk_drf_start_pause_mask                  (0x00000400)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_mvd_rlmvbuf_drf_start_pause_mask          (0x00000200)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_rlrmem_fme_drf_start_pause_mask           (0x00000100)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_cm_drf_start_pause_mask                   (0x00000080)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_ndb_drf_start_pause_mask                  (0x00000040)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_brg_drf_start_pause_mask                  (0x00000020)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_it_bs_drf_start_pause_mask                (0x00000010)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_it_drf_start_pause_mask                   (0x00000008)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_vm_drf_start_pause_mask                   (0x00000004)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_vld_drf_start_pause_mask                  (0x00000002)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_rif_drf_start_pause_mask                  (0x00000001)
#define  LGCY_VE_MBIST_ve_drf_pause_ve_dmem_drf_start_pause(data)                (0x00020000&((data)<<17))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_ip_gc_drf_start_pause(data)               (0x00010000&((data)<<16))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_pred_2p_drf_start_pause(data)             (0x00008000&((data)<<15))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_pred_drf_start_pause(data)                (0x00004000&((data)<<14))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_fme_drf_start_pause(data)                 (0x00002000&((data)<<13))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_cah_2p_drf_start_pause(data)              (0x00001000&((data)<<12))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_cah_1p_drf_start_pause(data)              (0x00000800&((data)<<11))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_dbk_drf_start_pause(data)                 (0x00000400&((data)<<10))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_mvd_rlmvbuf_drf_start_pause(data)         (0x00000200&((data)<<9))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_rlrmem_fme_drf_start_pause(data)          (0x00000100&((data)<<8))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_cm_drf_start_pause(data)                  (0x00000080&((data)<<7))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_ndb_drf_start_pause(data)                 (0x00000040&((data)<<6))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_brg_drf_start_pause(data)                 (0x00000020&((data)<<5))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_it_bs_drf_start_pause(data)               (0x00000010&((data)<<4))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_it_drf_start_pause(data)                  (0x00000008&((data)<<3))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_vm_drf_start_pause(data)                  (0x00000004&((data)<<2))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_vld_drf_start_pause(data)                 (0x00000002&((data)<<1))
#define  LGCY_VE_MBIST_ve_drf_pause_ve_rif_drf_start_pause(data)                 (0x00000001&(data))
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_dmem_drf_start_pause(data)            ((0x00020000&(data))>>17)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_ip_gc_drf_start_pause(data)           ((0x00010000&(data))>>16)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_pred_2p_drf_start_pause(data)         ((0x00008000&(data))>>15)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_pred_drf_start_pause(data)            ((0x00004000&(data))>>14)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_fme_drf_start_pause(data)             ((0x00002000&(data))>>13)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_cah_2p_drf_start_pause(data)          ((0x00001000&(data))>>12)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_cah_1p_drf_start_pause(data)          ((0x00000800&(data))>>11)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_dbk_drf_start_pause(data)             ((0x00000400&(data))>>10)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_mvd_rlmvbuf_drf_start_pause(data)     ((0x00000200&(data))>>9)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_rlrmem_fme_drf_start_pause(data)      ((0x00000100&(data))>>8)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_cm_drf_start_pause(data)              ((0x00000080&(data))>>7)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_ndb_drf_start_pause(data)             ((0x00000040&(data))>>6)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_brg_drf_start_pause(data)             ((0x00000020&(data))>>5)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_it_bs_drf_start_pause(data)           ((0x00000010&(data))>>4)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_it_drf_start_pause(data)              ((0x00000008&(data))>>3)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_vm_drf_start_pause(data)              ((0x00000004&(data))>>2)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_vld_drf_start_pause(data)             ((0x00000002&(data))>>1)
#define  LGCY_VE_MBIST_ve_drf_pause_get_ve_rif_drf_start_pause(data)             (0x00000001&(data))

#define  LGCY_VE_MBIST_ve_drf_done                                               0x1800FE1C
#define  LGCY_VE_MBIST_ve_drf_done_reg_addr                                      "0xB800FE1C"
#define  LGCY_VE_MBIST_ve_drf_done_reg                                           0xB800FE1C
#define  LGCY_VE_MBIST_ve_drf_done_inst_addr                                     "0x0008"
#define  set_LGCY_VE_MBIST_ve_drf_done_reg(data)                                 (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_done_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_done_reg                                       (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_done_reg))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_dmem_done_shift                        (17)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_ip_gc_done_shift                       (16)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_pred_2p_done_shift                     (15)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_pred_done_shift                        (14)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_fme_done_shift                         (13)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_cah_2p_done_shift                      (12)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_cah_1p_done_shift                      (11)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_dbk_done_shift                         (10)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_mvd_rlmvbuf_done_shift                 (9)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_rlrmem_fme_done_shift                  (8)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_cm_done_shift                          (7)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_ndb_done_shift                         (6)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_brg_done_shift                         (5)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_it_bs_done_shift                       (4)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_it_done_shift                          (3)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_vm_done_shift                          (2)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_vld_done_shift                         (1)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_rif_done_shift                         (0)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_dmem_done_mask                         (0x00020000)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_ip_gc_done_mask                        (0x00010000)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_pred_2p_done_mask                      (0x00008000)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_pred_done_mask                         (0x00004000)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_fme_done_mask                          (0x00002000)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_cah_2p_done_mask                       (0x00001000)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_cah_1p_done_mask                       (0x00000800)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_dbk_done_mask                          (0x00000400)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_mvd_rlmvbuf_done_mask                  (0x00000200)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_rlrmem_fme_done_mask                   (0x00000100)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_cm_done_mask                           (0x00000080)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_ndb_done_mask                          (0x00000040)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_brg_done_mask                          (0x00000020)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_it_bs_done_mask                        (0x00000010)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_it_done_mask                           (0x00000008)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_vm_done_mask                           (0x00000004)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_vld_done_mask                          (0x00000002)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_rif_done_mask                          (0x00000001)
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_dmem_done(data)                        (0x00020000&((data)<<17))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_ip_gc_done(data)                       (0x00010000&((data)<<16))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_pred_2p_done(data)                     (0x00008000&((data)<<15))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_pred_done(data)                        (0x00004000&((data)<<14))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_fme_done(data)                         (0x00002000&((data)<<13))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_cah_2p_done(data)                      (0x00001000&((data)<<12))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_cah_1p_done(data)                      (0x00000800&((data)<<11))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_dbk_done(data)                         (0x00000400&((data)<<10))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_mvd_rlmvbuf_done(data)                 (0x00000200&((data)<<9))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_rlrmem_fme_done(data)                  (0x00000100&((data)<<8))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_cm_done(data)                          (0x00000080&((data)<<7))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_ndb_done(data)                         (0x00000040&((data)<<6))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_brg_done(data)                         (0x00000020&((data)<<5))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_it_bs_done(data)                       (0x00000010&((data)<<4))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_it_done(data)                          (0x00000008&((data)<<3))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_vm_done(data)                          (0x00000004&((data)<<2))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_vld_done(data)                         (0x00000002&((data)<<1))
#define  LGCY_VE_MBIST_ve_drf_done_ve_drf_rif_done(data)                         (0x00000001&(data))
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_dmem_done(data)                    ((0x00020000&(data))>>17)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_ip_gc_done(data)                   ((0x00010000&(data))>>16)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_pred_2p_done(data)                 ((0x00008000&(data))>>15)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_pred_done(data)                    ((0x00004000&(data))>>14)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_fme_done(data)                     ((0x00002000&(data))>>13)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_cah_2p_done(data)                  ((0x00001000&(data))>>12)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_cah_1p_done(data)                  ((0x00000800&(data))>>11)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_dbk_done(data)                     ((0x00000400&(data))>>10)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_mvd_rlmvbuf_done(data)             ((0x00000200&(data))>>9)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_rlrmem_fme_done(data)              ((0x00000100&(data))>>8)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_cm_done(data)                      ((0x00000080&(data))>>7)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_ndb_done(data)                     ((0x00000040&(data))>>6)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_brg_done(data)                     ((0x00000020&(data))>>5)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_it_bs_done(data)                   ((0x00000010&(data))>>4)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_it_done(data)                      ((0x00000008&(data))>>3)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_vm_done(data)                      ((0x00000004&(data))>>2)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_vld_done(data)                     ((0x00000002&(data))>>1)
#define  LGCY_VE_MBIST_ve_drf_done_get_ve_drf_rif_done(data)                     (0x00000001&(data))

#define  LGCY_VE_MBIST_ve_drf_fail_group                                         0x1800FE20
#define  LGCY_VE_MBIST_ve_drf_fail_group_reg_addr                                "0xB800FE20"
#define  LGCY_VE_MBIST_ve_drf_fail_group_reg                                     0xB800FE20
#define  LGCY_VE_MBIST_ve_drf_fail_group_inst_addr                               "0x0009"
#define  set_LGCY_VE_MBIST_ve_drf_fail_group_reg(data)                           (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_fail_group_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_fail_group_reg                                 (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_fail_group_reg))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_dmem_fail_group_shift            (17)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_ip_gc_fail_group_shift           (16)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_pred_2p_fail_group_shift         (15)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_pred_fail_group_shift            (14)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_fme_fail_group_shift             (13)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_cah_2p_fail_group_shift          (12)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_cah_1p_fail_group_shift          (11)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_dbk_fail_group_shift             (10)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_mvd_rlmvbuf_fail_group_shift     (9)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_rlrmem_fme_fail_group_shift      (8)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_cm_fail_group_shift              (7)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_ndb_fail_group_shift             (6)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_brg_fail_group_shift             (5)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_it_bs_fail_group_shift           (4)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_it_fail_group_shift              (3)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_vm_fail_group_shift              (2)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_vld_fail_group_shift             (1)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_rif_fail_group_shift             (0)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_dmem_fail_group_mask             (0x00020000)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_ip_gc_fail_group_mask            (0x00010000)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_pred_2p_fail_group_mask          (0x00008000)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_pred_fail_group_mask             (0x00004000)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_fme_fail_group_mask              (0x00002000)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_cah_2p_fail_group_mask           (0x00001000)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_cah_1p_fail_group_mask           (0x00000800)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_dbk_fail_group_mask              (0x00000400)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_mvd_rlmvbuf_fail_group_mask      (0x00000200)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_rlrmem_fme_fail_group_mask       (0x00000100)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_cm_fail_group_mask               (0x00000080)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_ndb_fail_group_mask              (0x00000040)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_brg_fail_group_mask              (0x00000020)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_it_bs_fail_group_mask            (0x00000010)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_it_fail_group_mask               (0x00000008)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_vm_fail_group_mask               (0x00000004)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_vld_fail_group_mask              (0x00000002)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_rif_fail_group_mask              (0x00000001)
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_dmem_fail_group(data)            (0x00020000&((data)<<17))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_ip_gc_fail_group(data)           (0x00010000&((data)<<16))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_pred_2p_fail_group(data)         (0x00008000&((data)<<15))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_pred_fail_group(data)            (0x00004000&((data)<<14))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_fme_fail_group(data)             (0x00002000&((data)<<13))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_cah_2p_fail_group(data)          (0x00001000&((data)<<12))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_cah_1p_fail_group(data)          (0x00000800&((data)<<11))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_dbk_fail_group(data)             (0x00000400&((data)<<10))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_mvd_rlmvbuf_fail_group(data)     (0x00000200&((data)<<9))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_rlrmem_fme_fail_group(data)      (0x00000100&((data)<<8))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_cm_fail_group(data)              (0x00000080&((data)<<7))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_ndb_fail_group(data)             (0x00000040&((data)<<6))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_brg_fail_group(data)             (0x00000020&((data)<<5))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_it_bs_fail_group(data)           (0x00000010&((data)<<4))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_it_fail_group(data)              (0x00000008&((data)<<3))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_vm_fail_group(data)              (0x00000004&((data)<<2))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_vld_fail_group(data)             (0x00000002&((data)<<1))
#define  LGCY_VE_MBIST_ve_drf_fail_group_ve_drf_rif_fail_group(data)             (0x00000001&(data))
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_dmem_fail_group(data)        ((0x00020000&(data))>>17)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_ip_gc_fail_group(data)       ((0x00010000&(data))>>16)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_pred_2p_fail_group(data)     ((0x00008000&(data))>>15)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_pred_fail_group(data)        ((0x00004000&(data))>>14)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_fme_fail_group(data)         ((0x00002000&(data))>>13)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_cah_2p_fail_group(data)      ((0x00001000&(data))>>12)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_cah_1p_fail_group(data)      ((0x00000800&(data))>>11)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_dbk_fail_group(data)         ((0x00000400&(data))>>10)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_mvd_rlmvbuf_fail_group(data) ((0x00000200&(data))>>9)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_rlrmem_fme_fail_group(data)  ((0x00000100&(data))>>8)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_cm_fail_group(data)          ((0x00000080&(data))>>7)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_ndb_fail_group(data)         ((0x00000040&(data))>>6)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_brg_fail_group(data)         ((0x00000020&(data))>>5)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_it_bs_fail_group(data)       ((0x00000010&(data))>>4)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_it_fail_group(data)          ((0x00000008&(data))>>3)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_vm_fail_group(data)          ((0x00000004&(data))>>2)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_vld_fail_group(data)         ((0x00000002&(data))>>1)
#define  LGCY_VE_MBIST_ve_drf_fail_group_get_ve_drf_rif_fail_group(data)         (0x00000001&(data))

#define  LGCY_VE_MBIST_ve_bist_rif_fail                                          0x1800FE30
#define  LGCY_VE_MBIST_ve_bist_rif_fail_reg_addr                                 "0xB800FE30"
#define  LGCY_VE_MBIST_ve_bist_rif_fail_reg                                      0xB800FE30
#define  LGCY_VE_MBIST_ve_bist_rif_fail_inst_addr                                "0x000A"
#define  set_LGCY_VE_MBIST_ve_bist_rif_fail_reg(data)                            (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_rif_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_rif_fail_reg                                  (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_rif_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_rif_fail_ve_bist_rif_fail_shift                   (0)
#define  LGCY_VE_MBIST_ve_bist_rif_fail_ve_bist_rif_fail_mask                    (0x000001FF)
#define  LGCY_VE_MBIST_ve_bist_rif_fail_ve_bist_rif_fail(data)                   (0x000001FF&(data))
#define  LGCY_VE_MBIST_ve_bist_rif_fail_get_ve_bist_rif_fail(data)               (0x000001FF&(data))

#define  LGCY_VE_MBIST_ve_drf_rif_fail                                           0x1800FE34
#define  LGCY_VE_MBIST_ve_drf_rif_fail_reg_addr                                  "0xB800FE34"
#define  LGCY_VE_MBIST_ve_drf_rif_fail_reg                                       0xB800FE34
#define  LGCY_VE_MBIST_ve_drf_rif_fail_inst_addr                                 "0x000B"
#define  set_LGCY_VE_MBIST_ve_drf_rif_fail_reg(data)                             (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_rif_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_rif_fail_reg                                   (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_rif_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_rif_fail_ve_drf_rif_fail_shift                     (0)
#define  LGCY_VE_MBIST_ve_drf_rif_fail_ve_drf_rif_fail_mask                      (0x000001FF)
#define  LGCY_VE_MBIST_ve_drf_rif_fail_ve_drf_rif_fail(data)                     (0x000001FF&(data))
#define  LGCY_VE_MBIST_ve_drf_rif_fail_get_ve_drf_rif_fail(data)                 (0x000001FF&(data))

#define  LGCY_VE_MBIST_ve_bist_vld_fail                                          0x1800FE38
#define  LGCY_VE_MBIST_ve_bist_vld_fail_reg_addr                                 "0xB800FE38"
#define  LGCY_VE_MBIST_ve_bist_vld_fail_reg                                      0xB800FE38
#define  LGCY_VE_MBIST_ve_bist_vld_fail_inst_addr                                "0x000C"
#define  set_LGCY_VE_MBIST_ve_bist_vld_fail_reg(data)                            (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_vld_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_vld_fail_reg                                  (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_vld_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_vld_fail_ve_bist_vld_fail_shift                   (0)
#define  LGCY_VE_MBIST_ve_bist_vld_fail_ve_bist_vld_fail_mask                    (0x0000001F)
#define  LGCY_VE_MBIST_ve_bist_vld_fail_ve_bist_vld_fail(data)                   (0x0000001F&(data))
#define  LGCY_VE_MBIST_ve_bist_vld_fail_get_ve_bist_vld_fail(data)               (0x0000001F&(data))

#define  LGCY_VE_MBIST_ve_drf_vld_fail                                           0x1800FE3C
#define  LGCY_VE_MBIST_ve_drf_vld_fail_reg_addr                                  "0xB800FE3C"
#define  LGCY_VE_MBIST_ve_drf_vld_fail_reg                                       0xB800FE3C
#define  LGCY_VE_MBIST_ve_drf_vld_fail_inst_addr                                 "0x000D"
#define  set_LGCY_VE_MBIST_ve_drf_vld_fail_reg(data)                             (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_vld_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_vld_fail_reg                                   (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_vld_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_vld_fail_ve_drf_vld_fail_shift                     (0)
#define  LGCY_VE_MBIST_ve_drf_vld_fail_ve_drf_vld_fail_mask                      (0x0000001F)
#define  LGCY_VE_MBIST_ve_drf_vld_fail_ve_drf_vld_fail(data)                     (0x0000001F&(data))
#define  LGCY_VE_MBIST_ve_drf_vld_fail_get_ve_drf_vld_fail(data)                 (0x0000001F&(data))

#define  LGCY_VE_MBIST_ve_bist_vm_fail                                           0x1800FE40
#define  LGCY_VE_MBIST_ve_bist_vm_fail_reg_addr                                  "0xB800FE40"
#define  LGCY_VE_MBIST_ve_bist_vm_fail_reg                                       0xB800FE40
#define  LGCY_VE_MBIST_ve_bist_vm_fail_inst_addr                                 "0x000E"
#define  set_LGCY_VE_MBIST_ve_bist_vm_fail_reg(data)                             (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_vm_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_vm_fail_reg                                   (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_vm_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_vm_fail_ve_bist_vm_fail_shift                     (0)
#define  LGCY_VE_MBIST_ve_bist_vm_fail_ve_bist_vm_fail_mask                      (0x0000007F)
#define  LGCY_VE_MBIST_ve_bist_vm_fail_ve_bist_vm_fail(data)                     (0x0000007F&(data))
#define  LGCY_VE_MBIST_ve_bist_vm_fail_get_ve_bist_vm_fail(data)                 (0x0000007F&(data))

#define  LGCY_VE_MBIST_ve_drf_vm_fail                                            0x1800FE44
#define  LGCY_VE_MBIST_ve_drf_vm_fail_reg_addr                                   "0xB800FE44"
#define  LGCY_VE_MBIST_ve_drf_vm_fail_reg                                        0xB800FE44
#define  LGCY_VE_MBIST_ve_drf_vm_fail_inst_addr                                  "0x000F"
#define  set_LGCY_VE_MBIST_ve_drf_vm_fail_reg(data)                              (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_vm_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_vm_fail_reg                                    (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_vm_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_vm_fail_ve_drf_vm_fail_shift                       (0)
#define  LGCY_VE_MBIST_ve_drf_vm_fail_ve_drf_vm_fail_mask                        (0x0000007F)
#define  LGCY_VE_MBIST_ve_drf_vm_fail_ve_drf_vm_fail(data)                       (0x0000007F&(data))
#define  LGCY_VE_MBIST_ve_drf_vm_fail_get_ve_drf_vm_fail(data)                   (0x0000007F&(data))

#define  LGCY_VE_MBIST_ve_bist_it_fail                                           0x1800FE48
#define  LGCY_VE_MBIST_ve_bist_it_fail_reg_addr                                  "0xB800FE48"
#define  LGCY_VE_MBIST_ve_bist_it_fail_reg                                       0xB800FE48
#define  LGCY_VE_MBIST_ve_bist_it_fail_inst_addr                                 "0x0010"
#define  set_LGCY_VE_MBIST_ve_bist_it_fail_reg(data)                             (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_it_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_it_fail_reg                                   (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_it_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_it_fail_ve_bist_it_fail_shift                     (0)
#define  LGCY_VE_MBIST_ve_bist_it_fail_ve_bist_it_fail_mask                      (0x0000000F)
#define  LGCY_VE_MBIST_ve_bist_it_fail_ve_bist_it_fail(data)                     (0x0000000F&(data))
#define  LGCY_VE_MBIST_ve_bist_it_fail_get_ve_bist_it_fail(data)                 (0x0000000F&(data))

#define  LGCY_VE_MBIST_ve_drf_it_fail                                            0x1800FE4C
#define  LGCY_VE_MBIST_ve_drf_it_fail_reg_addr                                   "0xB800FE4C"
#define  LGCY_VE_MBIST_ve_drf_it_fail_reg                                        0xB800FE4C
#define  LGCY_VE_MBIST_ve_drf_it_fail_inst_addr                                  "0x0011"
#define  set_LGCY_VE_MBIST_ve_drf_it_fail_reg(data)                              (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_it_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_it_fail_reg                                    (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_it_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_it_fail_ve_drf_it_fail_shift                       (0)
#define  LGCY_VE_MBIST_ve_drf_it_fail_ve_drf_it_fail_mask                        (0x0000000F)
#define  LGCY_VE_MBIST_ve_drf_it_fail_ve_drf_it_fail(data)                       (0x0000000F&(data))
#define  LGCY_VE_MBIST_ve_drf_it_fail_get_ve_drf_it_fail(data)                   (0x0000000F&(data))

#define  LGCY_VE_MBIST_ve_bist_it_bs_fail                                        0x1800FE50
#define  LGCY_VE_MBIST_ve_bist_it_bs_fail_reg_addr                               "0xB800FE50"
#define  LGCY_VE_MBIST_ve_bist_it_bs_fail_reg                                    0xB800FE50
#define  LGCY_VE_MBIST_ve_bist_it_bs_fail_inst_addr                              "0x0012"
#define  set_LGCY_VE_MBIST_ve_bist_it_bs_fail_reg(data)                          (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_it_bs_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_it_bs_fail_reg                                (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_it_bs_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_it_bs_fail_ve_bist_it_bs_fail_shift               (0)
#define  LGCY_VE_MBIST_ve_bist_it_bs_fail_ve_bist_it_bs_fail_mask                (0x00000007)
#define  LGCY_VE_MBIST_ve_bist_it_bs_fail_ve_bist_it_bs_fail(data)               (0x00000007&(data))
#define  LGCY_VE_MBIST_ve_bist_it_bs_fail_get_ve_bist_it_bs_fail(data)           (0x00000007&(data))

#define  LGCY_VE_MBIST_ve_drf_it_bs_fail                                         0x1800FE54
#define  LGCY_VE_MBIST_ve_drf_it_bs_fail_reg_addr                                "0xB800FE54"
#define  LGCY_VE_MBIST_ve_drf_it_bs_fail_reg                                     0xB800FE54
#define  LGCY_VE_MBIST_ve_drf_it_bs_fail_inst_addr                               "0x0013"
#define  set_LGCY_VE_MBIST_ve_drf_it_bs_fail_reg(data)                           (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_it_bs_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_it_bs_fail_reg                                 (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_it_bs_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_it_bs_fail_ve_drf_it_bs_fail_shift                 (0)
#define  LGCY_VE_MBIST_ve_drf_it_bs_fail_ve_drf_it_bs_fail_mask                  (0x00000007)
#define  LGCY_VE_MBIST_ve_drf_it_bs_fail_ve_drf_it_bs_fail(data)                 (0x00000007&(data))
#define  LGCY_VE_MBIST_ve_drf_it_bs_fail_get_ve_drf_it_bs_fail(data)             (0x00000007&(data))

#define  LGCY_VE_MBIST_ve_bist_brg_fail                                          0x1800FE60
#define  LGCY_VE_MBIST_ve_bist_brg_fail_reg_addr                                 "0xB800FE60"
#define  LGCY_VE_MBIST_ve_bist_brg_fail_reg                                      0xB800FE60
#define  LGCY_VE_MBIST_ve_bist_brg_fail_inst_addr                                "0x0014"
#define  set_LGCY_VE_MBIST_ve_bist_brg_fail_reg(data)                            (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_brg_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_brg_fail_reg                                  (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_brg_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_brg_fail_ve_bist_brg_fail_shift                   (0)
#define  LGCY_VE_MBIST_ve_bist_brg_fail_ve_bist_brg_fail_mask                    (0x0000003F)
#define  LGCY_VE_MBIST_ve_bist_brg_fail_ve_bist_brg_fail(data)                   (0x0000003F&(data))
#define  LGCY_VE_MBIST_ve_bist_brg_fail_get_ve_bist_brg_fail(data)               (0x0000003F&(data))

#define  LGCY_VE_MBIST_ve_drf_brg_fail                                           0x1800FE64
#define  LGCY_VE_MBIST_ve_drf_brg_fail_reg_addr                                  "0xB800FE64"
#define  LGCY_VE_MBIST_ve_drf_brg_fail_reg                                       0xB800FE64
#define  LGCY_VE_MBIST_ve_drf_brg_fail_inst_addr                                 "0x0015"
#define  set_LGCY_VE_MBIST_ve_drf_brg_fail_reg(data)                             (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_brg_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_brg_fail_reg                                   (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_brg_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_brg_fail_ve_drf_brg_fail_shift                     (0)
#define  LGCY_VE_MBIST_ve_drf_brg_fail_ve_drf_brg_fail_mask                      (0x0000003F)
#define  LGCY_VE_MBIST_ve_drf_brg_fail_ve_drf_brg_fail(data)                     (0x0000003F&(data))
#define  LGCY_VE_MBIST_ve_drf_brg_fail_get_ve_drf_brg_fail(data)                 (0x0000003F&(data))

#define  LGCY_VE_MBIST_ve_bist_ndb_fail                                          0x1800FE68
#define  LGCY_VE_MBIST_ve_bist_ndb_fail_reg_addr                                 "0xB800FE68"
#define  LGCY_VE_MBIST_ve_bist_ndb_fail_reg                                      0xB800FE68
#define  LGCY_VE_MBIST_ve_bist_ndb_fail_inst_addr                                "0x0016"
#define  set_LGCY_VE_MBIST_ve_bist_ndb_fail_reg(data)                            (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_ndb_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_ndb_fail_reg                                  (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_ndb_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_ndb_fail_ve_bist_ndb_fail_shift                   (0)
#define  LGCY_VE_MBIST_ve_bist_ndb_fail_ve_bist_ndb_fail_mask                    (0x0000000F)
#define  LGCY_VE_MBIST_ve_bist_ndb_fail_ve_bist_ndb_fail(data)                   (0x0000000F&(data))
#define  LGCY_VE_MBIST_ve_bist_ndb_fail_get_ve_bist_ndb_fail(data)               (0x0000000F&(data))

#define  LGCY_VE_MBIST_ve_drf_ndb_fail                                           0x1800FE6C
#define  LGCY_VE_MBIST_ve_drf_ndb_fail_reg_addr                                  "0xB800FE6C"
#define  LGCY_VE_MBIST_ve_drf_ndb_fail_reg                                       0xB800FE6C
#define  LGCY_VE_MBIST_ve_drf_ndb_fail_inst_addr                                 "0x0017"
#define  set_LGCY_VE_MBIST_ve_drf_ndb_fail_reg(data)                             (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_ndb_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_ndb_fail_reg                                   (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_ndb_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_ndb_fail_ve_drf_ndb_fail_shift                     (0)
#define  LGCY_VE_MBIST_ve_drf_ndb_fail_ve_drf_ndb_fail_mask                      (0x0000000F)
#define  LGCY_VE_MBIST_ve_drf_ndb_fail_ve_drf_ndb_fail(data)                     (0x0000000F&(data))
#define  LGCY_VE_MBIST_ve_drf_ndb_fail_get_ve_drf_ndb_fail(data)                 (0x0000000F&(data))

#define  LGCY_VE_MBIST_ve_bist_cm1_fail                                          0x1800FE70
#define  LGCY_VE_MBIST_ve_bist_cm1_fail_reg_addr                                 "0xB800FE70"
#define  LGCY_VE_MBIST_ve_bist_cm1_fail_reg                                      0xB800FE70
#define  LGCY_VE_MBIST_ve_bist_cm1_fail_inst_addr                                "0x0018"
#define  set_LGCY_VE_MBIST_ve_bist_cm1_fail_reg(data)                            (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_cm1_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_cm1_fail_reg                                  (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_cm1_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_cm1_fail_ve_bist_cm_fail_shift                    (0)
#define  LGCY_VE_MBIST_ve_bist_cm1_fail_ve_bist_cm_fail_mask                     (0x00000FFF)
#define  LGCY_VE_MBIST_ve_bist_cm1_fail_ve_bist_cm_fail(data)                    (0x00000FFF&(data))
#define  LGCY_VE_MBIST_ve_bist_cm1_fail_get_ve_bist_cm_fail(data)                (0x00000FFF&(data))

#define  LGCY_VE_MBIST_ve_drf_cm1_fail                                           0x1800FE74
#define  LGCY_VE_MBIST_ve_drf_cm1_fail_reg_addr                                  "0xB800FE74"
#define  LGCY_VE_MBIST_ve_drf_cm1_fail_reg                                       0xB800FE74
#define  LGCY_VE_MBIST_ve_drf_cm1_fail_inst_addr                                 "0x0019"
#define  set_LGCY_VE_MBIST_ve_drf_cm1_fail_reg(data)                             (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_cm1_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_cm1_fail_reg                                   (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_cm1_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_cm1_fail_ve_drf_cm_fail_shift                      (0)
#define  LGCY_VE_MBIST_ve_drf_cm1_fail_ve_drf_cm_fail_mask                       (0x00000FFF)
#define  LGCY_VE_MBIST_ve_drf_cm1_fail_ve_drf_cm_fail(data)                      (0x00000FFF&(data))
#define  LGCY_VE_MBIST_ve_drf_cm1_fail_get_ve_drf_cm_fail(data)                  (0x00000FFF&(data))

#define  LGCY_VE_MBIST_ve_bist_rlrmem_fme_fail                                   0x1800FE80
#define  LGCY_VE_MBIST_ve_bist_rlrmem_fme_fail_reg_addr                          "0xB800FE80"
#define  LGCY_VE_MBIST_ve_bist_rlrmem_fme_fail_reg                               0xB800FE80
#define  LGCY_VE_MBIST_ve_bist_rlrmem_fme_fail_inst_addr                         "0x001A"
#define  set_LGCY_VE_MBIST_ve_bist_rlrmem_fme_fail_reg(data)                     (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_rlrmem_fme_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_rlrmem_fme_fail_reg                           (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_rlrmem_fme_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_rlrmem_fme_fail_ve_bist_rlrmem_fme_fail_shift     (0)
#define  LGCY_VE_MBIST_ve_bist_rlrmem_fme_fail_ve_bist_rlrmem_fme_fail_mask      (0x00000007)
#define  LGCY_VE_MBIST_ve_bist_rlrmem_fme_fail_ve_bist_rlrmem_fme_fail(data)     (0x00000007&(data))
#define  LGCY_VE_MBIST_ve_bist_rlrmem_fme_fail_get_ve_bist_rlrmem_fme_fail(data) (0x00000007&(data))

#define  LGCY_VE_MBIST_ve_drf_rlrmem_fme_fail                                    0x1800FE84
#define  LGCY_VE_MBIST_ve_drf_rlrmem_fme_fail_reg_addr                           "0xB800FE84"
#define  LGCY_VE_MBIST_ve_drf_rlrmem_fme_fail_reg                                0xB800FE84
#define  LGCY_VE_MBIST_ve_drf_rlrmem_fme_fail_inst_addr                          "0x001B"
#define  set_LGCY_VE_MBIST_ve_drf_rlrmem_fme_fail_reg(data)                      (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_rlrmem_fme_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_rlrmem_fme_fail_reg                            (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_rlrmem_fme_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_rlrmem_fme_fail_ve_drf_rlrmem_fme_fail_shift       (0)
#define  LGCY_VE_MBIST_ve_drf_rlrmem_fme_fail_ve_drf_rlrmem_fme_fail_mask        (0x00000007)
#define  LGCY_VE_MBIST_ve_drf_rlrmem_fme_fail_ve_drf_rlrmem_fme_fail(data)       (0x00000007&(data))
#define  LGCY_VE_MBIST_ve_drf_rlrmem_fme_fail_get_ve_drf_rlrmem_fme_fail(data)   (0x00000007&(data))

#define  LGCY_VE_MBIST_ve_bist_mvd_rlmvbuf_fail                                  0x1800FE88
#define  LGCY_VE_MBIST_ve_bist_mvd_rlmvbuf_fail_reg_addr                         "0xB800FE88"
#define  LGCY_VE_MBIST_ve_bist_mvd_rlmvbuf_fail_reg                              0xB800FE88
#define  LGCY_VE_MBIST_ve_bist_mvd_rlmvbuf_fail_inst_addr                        "0x001C"
#define  set_LGCY_VE_MBIST_ve_bist_mvd_rlmvbuf_fail_reg(data)                    (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_mvd_rlmvbuf_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_mvd_rlmvbuf_fail_reg                          (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_mvd_rlmvbuf_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_mvd_rlmvbuf_fail_ve_bist_mvd_rlmvbuf_fail_shift   (0)
#define  LGCY_VE_MBIST_ve_bist_mvd_rlmvbuf_fail_ve_bist_mvd_rlmvbuf_fail_mask    (0x0000000F)
#define  LGCY_VE_MBIST_ve_bist_mvd_rlmvbuf_fail_ve_bist_mvd_rlmvbuf_fail(data)   (0x0000000F&(data))
#define  LGCY_VE_MBIST_ve_bist_mvd_rlmvbuf_fail_get_ve_bist_mvd_rlmvbuf_fail(data) (0x0000000F&(data))

#define  LGCY_VE_MBIST_ve_drf_mvd_rlmvbuf_fail                                   0x1800FE8C
#define  LGCY_VE_MBIST_ve_drf_mvd_rlmvbuf_fail_reg_addr                          "0xB800FE8C"
#define  LGCY_VE_MBIST_ve_drf_mvd_rlmvbuf_fail_reg                               0xB800FE8C
#define  LGCY_VE_MBIST_ve_drf_mvd_rlmvbuf_fail_inst_addr                         "0x001D"
#define  set_LGCY_VE_MBIST_ve_drf_mvd_rlmvbuf_fail_reg(data)                     (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_mvd_rlmvbuf_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_mvd_rlmvbuf_fail_reg                           (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_mvd_rlmvbuf_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_mvd_rlmvbuf_fail_ve_drf_mvd_rlmvbuf_fail_shift     (0)
#define  LGCY_VE_MBIST_ve_drf_mvd_rlmvbuf_fail_ve_drf_mvd_rlmvbuf_fail_mask      (0x0000000F)
#define  LGCY_VE_MBIST_ve_drf_mvd_rlmvbuf_fail_ve_drf_mvd_rlmvbuf_fail(data)     (0x0000000F&(data))
#define  LGCY_VE_MBIST_ve_drf_mvd_rlmvbuf_fail_get_ve_drf_mvd_rlmvbuf_fail(data) (0x0000000F&(data))

#define  LGCY_VE_MBIST_ve_bist_dbk_fail                                          0x1800FE90
#define  LGCY_VE_MBIST_ve_bist_dbk_fail_reg_addr                                 "0xB800FE90"
#define  LGCY_VE_MBIST_ve_bist_dbk_fail_reg                                      0xB800FE90
#define  LGCY_VE_MBIST_ve_bist_dbk_fail_inst_addr                                "0x001E"
#define  set_LGCY_VE_MBIST_ve_bist_dbk_fail_reg(data)                            (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_dbk_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_dbk_fail_reg                                  (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_dbk_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_dbk_fail_ve_bist_dbk_fail_shift                   (0)
#define  LGCY_VE_MBIST_ve_bist_dbk_fail_ve_bist_dbk_fail_mask                    (0x000001FF)
#define  LGCY_VE_MBIST_ve_bist_dbk_fail_ve_bist_dbk_fail(data)                   (0x000001FF&(data))
#define  LGCY_VE_MBIST_ve_bist_dbk_fail_get_ve_bist_dbk_fail(data)               (0x000001FF&(data))

#define  LGCY_VE_MBIST_ve_drf_dbk_fail                                           0x1800FE94
#define  LGCY_VE_MBIST_ve_drf_dbk_fail_reg_addr                                  "0xB800FE94"
#define  LGCY_VE_MBIST_ve_drf_dbk_fail_reg                                       0xB800FE94
#define  LGCY_VE_MBIST_ve_drf_dbk_fail_inst_addr                                 "0x001F"
#define  set_LGCY_VE_MBIST_ve_drf_dbk_fail_reg(data)                             (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_dbk_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_dbk_fail_reg                                   (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_dbk_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_dbk_fail_ve_drf_dbk_fail_shift                     (0)
#define  LGCY_VE_MBIST_ve_drf_dbk_fail_ve_drf_dbk_fail_mask                      (0x000001FF)
#define  LGCY_VE_MBIST_ve_drf_dbk_fail_ve_drf_dbk_fail(data)                     (0x000001FF&(data))
#define  LGCY_VE_MBIST_ve_drf_dbk_fail_get_ve_drf_dbk_fail(data)                 (0x000001FF&(data))

#define  LGCY_VE_MBIST_ve_bist_cah_1p_fail                                       0x1800FEA0
#define  LGCY_VE_MBIST_ve_bist_cah_1p_fail_reg_addr                              "0xB800FEA0"
#define  LGCY_VE_MBIST_ve_bist_cah_1p_fail_reg                                   0xB800FEA0
#define  LGCY_VE_MBIST_ve_bist_cah_1p_fail_inst_addr                             "0x0020"
#define  set_LGCY_VE_MBIST_ve_bist_cah_1p_fail_reg(data)                         (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_cah_1p_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_cah_1p_fail_reg                               (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_cah_1p_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_cah_1p_fail_ve_bist_cah_1p_fail_shift             (0)
#define  LGCY_VE_MBIST_ve_bist_cah_1p_fail_ve_bist_cah_1p_fail_mask              (0x0000000F)
#define  LGCY_VE_MBIST_ve_bist_cah_1p_fail_ve_bist_cah_1p_fail(data)             (0x0000000F&(data))
#define  LGCY_VE_MBIST_ve_bist_cah_1p_fail_get_ve_bist_cah_1p_fail(data)         (0x0000000F&(data))

#define  LGCY_VE_MBIST_ve_drf_cah_1p_fail                                        0x1800FEA4
#define  LGCY_VE_MBIST_ve_drf_cah_1p_fail_reg_addr                               "0xB800FEA4"
#define  LGCY_VE_MBIST_ve_drf_cah_1p_fail_reg                                    0xB800FEA4
#define  LGCY_VE_MBIST_ve_drf_cah_1p_fail_inst_addr                              "0x0021"
#define  set_LGCY_VE_MBIST_ve_drf_cah_1p_fail_reg(data)                          (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_cah_1p_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_cah_1p_fail_reg                                (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_cah_1p_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_cah_1p_fail_ve_drf_cah_1p_fail_shift               (0)
#define  LGCY_VE_MBIST_ve_drf_cah_1p_fail_ve_drf_cah_1p_fail_mask                (0x0000000F)
#define  LGCY_VE_MBIST_ve_drf_cah_1p_fail_ve_drf_cah_1p_fail(data)               (0x0000000F&(data))
#define  LGCY_VE_MBIST_ve_drf_cah_1p_fail_get_ve_drf_cah_1p_fail(data)           (0x0000000F&(data))

#define  LGCY_VE_MBIST_ve_bist_cah_2p_fail                                       0x1800FEA8
#define  LGCY_VE_MBIST_ve_bist_cah_2p_fail_reg_addr                              "0xB800FEA8"
#define  LGCY_VE_MBIST_ve_bist_cah_2p_fail_reg                                   0xB800FEA8
#define  LGCY_VE_MBIST_ve_bist_cah_2p_fail_inst_addr                             "0x0022"
#define  set_LGCY_VE_MBIST_ve_bist_cah_2p_fail_reg(data)                         (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_cah_2p_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_cah_2p_fail_reg                               (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_cah_2p_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_cah_2p_fail_ve_bist_cah_2p_fail_shift             (0)
#define  LGCY_VE_MBIST_ve_bist_cah_2p_fail_ve_bist_cah_2p_fail_mask              (0x00000007)
#define  LGCY_VE_MBIST_ve_bist_cah_2p_fail_ve_bist_cah_2p_fail(data)             (0x00000007&(data))
#define  LGCY_VE_MBIST_ve_bist_cah_2p_fail_get_ve_bist_cah_2p_fail(data)         (0x00000007&(data))

#define  LGCY_VE_MBIST_ve_drf_cah_2p_fail                                        0x1800FEAC
#define  LGCY_VE_MBIST_ve_drf_cah_2p_fail_reg_addr                               "0xB800FEAC"
#define  LGCY_VE_MBIST_ve_drf_cah_2p_fail_reg                                    0xB800FEAC
#define  LGCY_VE_MBIST_ve_drf_cah_2p_fail_inst_addr                              "0x0023"
#define  set_LGCY_VE_MBIST_ve_drf_cah_2p_fail_reg(data)                          (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_cah_2p_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_cah_2p_fail_reg                                (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_cah_2p_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_cah_2p_fail_ve_drf_cah_2p_fail_shift               (0)
#define  LGCY_VE_MBIST_ve_drf_cah_2p_fail_ve_drf_cah_2p_fail_mask                (0x00000007)
#define  LGCY_VE_MBIST_ve_drf_cah_2p_fail_ve_drf_cah_2p_fail(data)               (0x00000007&(data))
#define  LGCY_VE_MBIST_ve_drf_cah_2p_fail_get_ve_drf_cah_2p_fail(data)           (0x00000007&(data))

#define  LGCY_VE_MBIST_ve_bist_fme_fail                                          0x1800FEB0
#define  LGCY_VE_MBIST_ve_bist_fme_fail_reg_addr                                 "0xB800FEB0"
#define  LGCY_VE_MBIST_ve_bist_fme_fail_reg                                      0xB800FEB0
#define  LGCY_VE_MBIST_ve_bist_fme_fail_inst_addr                                "0x0024"
#define  set_LGCY_VE_MBIST_ve_bist_fme_fail_reg(data)                            (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_fme_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_fme_fail_reg                                  (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_fme_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_fme_fail_ve_bist_fme_fail_shift                   (0)
#define  LGCY_VE_MBIST_ve_bist_fme_fail_ve_bist_fme_fail_mask                    (0x0000007F)
#define  LGCY_VE_MBIST_ve_bist_fme_fail_ve_bist_fme_fail(data)                   (0x0000007F&(data))
#define  LGCY_VE_MBIST_ve_bist_fme_fail_get_ve_bist_fme_fail(data)               (0x0000007F&(data))

#define  LGCY_VE_MBIST_ve_drf_fme_fail                                           0x1800FEB4
#define  LGCY_VE_MBIST_ve_drf_fme_fail_reg_addr                                  "0xB800FEB4"
#define  LGCY_VE_MBIST_ve_drf_fme_fail_reg                                       0xB800FEB4
#define  LGCY_VE_MBIST_ve_drf_fme_fail_inst_addr                                 "0x0025"
#define  set_LGCY_VE_MBIST_ve_drf_fme_fail_reg(data)                             (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_fme_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_fme_fail_reg                                   (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_fme_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_fme_fail_ve_drf_fme_fail_shift                     (0)
#define  LGCY_VE_MBIST_ve_drf_fme_fail_ve_drf_fme_fail_mask                      (0x0000007F)
#define  LGCY_VE_MBIST_ve_drf_fme_fail_ve_drf_fme_fail(data)                     (0x0000007F&(data))
#define  LGCY_VE_MBIST_ve_drf_fme_fail_get_ve_drf_fme_fail(data)                 (0x0000007F&(data))

#define  LGCY_VE_MBIST_ve_bist_pred_0_fail                                       0x1800FEB8
#define  LGCY_VE_MBIST_ve_bist_pred_0_fail_reg_addr                              "0xB800FEB8"
#define  LGCY_VE_MBIST_ve_bist_pred_0_fail_reg                                   0xB800FEB8
#define  LGCY_VE_MBIST_ve_bist_pred_0_fail_inst_addr                             "0x0026"
#define  set_LGCY_VE_MBIST_ve_bist_pred_0_fail_reg(data)                         (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_pred_0_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_pred_0_fail_reg                               (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_pred_0_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_pred_0_fail_ve_bist_pred_fail_shift               (0)
#define  LGCY_VE_MBIST_ve_bist_pred_0_fail_ve_bist_pred_fail_mask                (0x0000007F)
#define  LGCY_VE_MBIST_ve_bist_pred_0_fail_ve_bist_pred_fail(data)               (0x0000007F&(data))
#define  LGCY_VE_MBIST_ve_bist_pred_0_fail_get_ve_bist_pred_fail(data)           (0x0000007F&(data))

#define  LGCY_VE_MBIST_ve_drf_pred_0_fail                                        0x1800FEBC
#define  LGCY_VE_MBIST_ve_drf_pred_0_fail_reg_addr                               "0xB800FEBC"
#define  LGCY_VE_MBIST_ve_drf_pred_0_fail_reg                                    0xB800FEBC
#define  LGCY_VE_MBIST_ve_drf_pred_0_fail_inst_addr                              "0x0027"
#define  set_LGCY_VE_MBIST_ve_drf_pred_0_fail_reg(data)                          (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_pred_0_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_pred_0_fail_reg                                (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_pred_0_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_pred_0_fail_ve_drf_pred_fail_shift                 (0)
#define  LGCY_VE_MBIST_ve_drf_pred_0_fail_ve_drf_pred_fail_mask                  (0x0000007F)
#define  LGCY_VE_MBIST_ve_drf_pred_0_fail_ve_drf_pred_fail(data)                 (0x0000007F&(data))
#define  LGCY_VE_MBIST_ve_drf_pred_0_fail_get_ve_drf_pred_fail(data)             (0x0000007F&(data))

#define  LGCY_VE_MBIST_ve_bist_pred_2p_fail                                      0x1800FEC8
#define  LGCY_VE_MBIST_ve_bist_pred_2p_fail_reg_addr                             "0xB800FEC8"
#define  LGCY_VE_MBIST_ve_bist_pred_2p_fail_reg                                  0xB800FEC8
#define  LGCY_VE_MBIST_ve_bist_pred_2p_fail_inst_addr                            "0x0028"
#define  set_LGCY_VE_MBIST_ve_bist_pred_2p_fail_reg(data)                        (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_pred_2p_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_pred_2p_fail_reg                              (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_pred_2p_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_pred_2p_fail_ve_bist_pred_2p_fail_shift           (0)
#define  LGCY_VE_MBIST_ve_bist_pred_2p_fail_ve_bist_pred_2p_fail_mask            (0x00000003)
#define  LGCY_VE_MBIST_ve_bist_pred_2p_fail_ve_bist_pred_2p_fail(data)           (0x00000003&(data))
#define  LGCY_VE_MBIST_ve_bist_pred_2p_fail_get_ve_bist_pred_2p_fail(data)       (0x00000003&(data))

#define  LGCY_VE_MBIST_ve_drf_pred_2p_fail                                       0x1800FECC
#define  LGCY_VE_MBIST_ve_drf_pred_2p_fail_reg_addr                              "0xB800FECC"
#define  LGCY_VE_MBIST_ve_drf_pred_2p_fail_reg                                   0xB800FECC
#define  LGCY_VE_MBIST_ve_drf_pred_2p_fail_inst_addr                             "0x0029"
#define  set_LGCY_VE_MBIST_ve_drf_pred_2p_fail_reg(data)                         (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_pred_2p_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_pred_2p_fail_reg                               (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_pred_2p_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_pred_2p_fail_ve_drf_pred_2p_fail_shift             (0)
#define  LGCY_VE_MBIST_ve_drf_pred_2p_fail_ve_drf_pred_2p_fail_mask              (0x00000003)
#define  LGCY_VE_MBIST_ve_drf_pred_2p_fail_ve_drf_pred_2p_fail(data)             (0x00000003&(data))
#define  LGCY_VE_MBIST_ve_drf_pred_2p_fail_get_ve_drf_pred_2p_fail(data)         (0x00000003&(data))

#define  LGCY_VE_MBIST_ve_bist_ip_gc_fail                                        0x1800FED0
#define  LGCY_VE_MBIST_ve_bist_ip_gc_fail_reg_addr                               "0xB800FED0"
#define  LGCY_VE_MBIST_ve_bist_ip_gc_fail_reg                                    0xB800FED0
#define  LGCY_VE_MBIST_ve_bist_ip_gc_fail_inst_addr                              "0x002A"
#define  set_LGCY_VE_MBIST_ve_bist_ip_gc_fail_reg(data)                          (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_ip_gc_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_ip_gc_fail_reg                                (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_ip_gc_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_ip_gc_fail_ve_bist_ip_gc_fail_shift               (0)
#define  LGCY_VE_MBIST_ve_bist_ip_gc_fail_ve_bist_ip_gc_fail_mask                (0x0000007F)
#define  LGCY_VE_MBIST_ve_bist_ip_gc_fail_ve_bist_ip_gc_fail(data)               (0x0000007F&(data))
#define  LGCY_VE_MBIST_ve_bist_ip_gc_fail_get_ve_bist_ip_gc_fail(data)           (0x0000007F&(data))

#define  LGCY_VE_MBIST_ve_drf_ip_gc_fail                                         0x1800FED4
#define  LGCY_VE_MBIST_ve_drf_ip_gc_fail_reg_addr                                "0xB800FED4"
#define  LGCY_VE_MBIST_ve_drf_ip_gc_fail_reg                                     0xB800FED4
#define  LGCY_VE_MBIST_ve_drf_ip_gc_fail_inst_addr                               "0x002B"
#define  set_LGCY_VE_MBIST_ve_drf_ip_gc_fail_reg(data)                           (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_ip_gc_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_ip_gc_fail_reg                                 (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_ip_gc_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_ip_gc_fail_ve_drf_ip_gc_fail_shift                 (0)
#define  LGCY_VE_MBIST_ve_drf_ip_gc_fail_ve_drf_ip_gc_fail_mask                  (0x0000007F)
#define  LGCY_VE_MBIST_ve_drf_ip_gc_fail_ve_drf_ip_gc_fail(data)                 (0x0000007F&(data))
#define  LGCY_VE_MBIST_ve_drf_ip_gc_fail_get_ve_drf_ip_gc_fail(data)             (0x0000007F&(data))

#define  LGCY_VE_MBIST_ve_bist_dmem_fail                                         0x1800FEE0
#define  LGCY_VE_MBIST_ve_bist_dmem_fail_reg_addr                                "0xB800FEE0"
#define  LGCY_VE_MBIST_ve_bist_dmem_fail_reg                                     0xB800FEE0
#define  LGCY_VE_MBIST_ve_bist_dmem_fail_inst_addr                               "0x002C"
#define  set_LGCY_VE_MBIST_ve_bist_dmem_fail_reg(data)                           (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_dmem_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_bist_dmem_fail_reg                                 (*((volatile unsigned int*)LGCY_VE_MBIST_ve_bist_dmem_fail_reg))
#define  LGCY_VE_MBIST_ve_bist_dmem_fail_ve_bist_dmem_fail_shift                 (0)
#define  LGCY_VE_MBIST_ve_bist_dmem_fail_ve_bist_dmem_fail_mask                  (0x00000003)
#define  LGCY_VE_MBIST_ve_bist_dmem_fail_ve_bist_dmem_fail(data)                 (0x00000003&(data))
#define  LGCY_VE_MBIST_ve_bist_dmem_fail_get_ve_bist_dmem_fail(data)             (0x00000003&(data))

#define  LGCY_VE_MBIST_ve_drf_dmem_fail                                          0x1800FEE4
#define  LGCY_VE_MBIST_ve_drf_dmem_fail_reg_addr                                 "0xB800FEE4"
#define  LGCY_VE_MBIST_ve_drf_dmem_fail_reg                                      0xB800FEE4
#define  LGCY_VE_MBIST_ve_drf_dmem_fail_inst_addr                                "0x002D"
#define  set_LGCY_VE_MBIST_ve_drf_dmem_fail_reg(data)                            (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_dmem_fail_reg)=data)
#define  get_LGCY_VE_MBIST_ve_drf_dmem_fail_reg                                  (*((volatile unsigned int*)LGCY_VE_MBIST_ve_drf_dmem_fail_reg))
#define  LGCY_VE_MBIST_ve_drf_dmem_fail_ve_drf_dmem_fail_shift                   (0)
#define  LGCY_VE_MBIST_ve_drf_dmem_fail_ve_drf_dmem_fail_mask                    (0x00000003)
#define  LGCY_VE_MBIST_ve_drf_dmem_fail_ve_drf_dmem_fail(data)                   (0x00000003&(data))
#define  LGCY_VE_MBIST_ve_drf_dmem_fail_get_ve_drf_dmem_fail(data)               (0x00000003&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LGCY_VE_MBIST register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_rwm:1;
        RBus_UInt32  bist_2p_clk_sel:1;
        RBus_UInt32  sysh_rmea:1;
        RBus_UInt32  sysh_rma:4;
        RBus_UInt32  sysh_rmeb:1;
        RBus_UInt32  sysh_rmb:4;
        RBus_UInt32  sysh_rme:1;
        RBus_UInt32  sysh_rm:4;
        RBus_UInt32  rmea:1;
        RBus_UInt32  rma:4;
        RBus_UInt32  rmeb:1;
        RBus_UInt32  rmb:4;
        RBus_UInt32  rme:1;
        RBus_UInt32  rm:4;
    };
}lgcy_ve_mbist_ve_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ip_gc_ls:2;
        RBus_UInt32  fme_ls:2;
        RBus_UInt32  ndb_ls:2;
        RBus_UInt32  bs_ls:2;
        RBus_UInt32  dmem_ls:2;
        RBus_UInt32  brg_ls:2;
        RBus_UInt32  vmem_ls:2;
        RBus_UInt32  cmprs_ls:2;
        RBus_UInt32  deblk_ls:2;
        RBus_UInt32  pred_ls:2;
        RBus_UInt32  cache_ls:2;
        RBus_UInt32  rl_ls:2;
        RBus_UInt32  cm_ls:2;
        RBus_UInt32  itblk_ls:2;
        RBus_UInt32  mvd_ls:2;
        RBus_UInt32  vld_ls:2;
    };
}lgcy_ve_mbist_ve_bist_ls_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  ve_dmem_bist_en:1;
        RBus_UInt32  ve_ip_gc_bist_en:1;
        RBus_UInt32  ve_pred_2p_bist_en:1;
        RBus_UInt32  ve_pred_bist_en:1;
        RBus_UInt32  ve_fme_bist_en:1;
        RBus_UInt32  ve_cah_2p_bist_en:1;
        RBus_UInt32  ve_cah_1p_bist_en:1;
        RBus_UInt32  ve_dbk_bist_en:1;
        RBus_UInt32  ve_mvd_rlmvbuf_bist_en:1;
        RBus_UInt32  ve_rlrmem_fme_bist_en:1;
        RBus_UInt32  ve_cm_bist_en:1;
        RBus_UInt32  ve_ndb_bist_en:1;
        RBus_UInt32  ve_brg_bist_en:1;
        RBus_UInt32  ve_it_bs_bist_en:1;
        RBus_UInt32  ve_it_bist_en:1;
        RBus_UInt32  ve_vm_bist_en:1;
        RBus_UInt32  ve_vld_bist_en:1;
        RBus_UInt32  ve_rif_bist_en:1;
    };
}lgcy_ve_mbist_ve_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  ve_bist_dmem_done:1;
        RBus_UInt32  ve_bist_ip_gc_done:1;
        RBus_UInt32  ve_bist_pred_2p_done:1;
        RBus_UInt32  ve_bist_pred_done:1;
        RBus_UInt32  ve_bist_fme_done:1;
        RBus_UInt32  ve_bist_cah_2p_done:1;
        RBus_UInt32  ve_bist_cah_1p_done:1;
        RBus_UInt32  ve_bist_dbk_done:1;
        RBus_UInt32  ve_bist_mvd_rlmvbuf_done:1;
        RBus_UInt32  ve_bist_rlrmem_fme_done:1;
        RBus_UInt32  ve_bist_cm_done:1;
        RBus_UInt32  ve_bist_ndb_done:1;
        RBus_UInt32  ve_bist_brg_done:1;
        RBus_UInt32  ve_bist_it_bs_done:1;
        RBus_UInt32  ve_bist_it_done:1;
        RBus_UInt32  ve_bist_vm_done:1;
        RBus_UInt32  ve_bist_vld_done:1;
        RBus_UInt32  ve_bist_rif_done:1;
    };
}lgcy_ve_mbist_ve_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  ve_bist_dmem_fail_group:1;
        RBus_UInt32  ve_bist_ip_gc_fail_group:1;
        RBus_UInt32  ve_bist_pred_2p_fail_group:1;
        RBus_UInt32  ve_bist_pred_fail_group:1;
        RBus_UInt32  ve_bist_fme_fail_group:1;
        RBus_UInt32  ve_bist_cah_2p_fail_group:1;
        RBus_UInt32  ve_bist_cah_1p_fail_group:1;
        RBus_UInt32  ve_bist_dbk_fail_group:1;
        RBus_UInt32  ve_bist_mvd_rlmvbuf_fail_group:1;
        RBus_UInt32  ve_bist_rlrmem_fme_fail_group:1;
        RBus_UInt32  ve_bist_cm_fail_group:1;
        RBus_UInt32  ve_bist_ndb_fail_group:1;
        RBus_UInt32  ve_bist_brg_fail_group:1;
        RBus_UInt32  ve_bist_it_bs_fail_group:1;
        RBus_UInt32  ve_bist_it_fail_group:1;
        RBus_UInt32  ve_bist_vm_fail_group:1;
        RBus_UInt32  ve_bist_vld_fail_group:1;
        RBus_UInt32  ve_bist_rif_fail_group:1;
    };
}lgcy_ve_mbist_ve_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  ve_dmem_drf_bist_en:1;
        RBus_UInt32  ve_ip_gc_drf_bist_en:1;
        RBus_UInt32  ve_pred_2p_drf_bist_en:1;
        RBus_UInt32  ve_pred_drf_bist_en:1;
        RBus_UInt32  ve_fme_drf_bist_en:1;
        RBus_UInt32  ve_cah_2p_drf_bist_en:1;
        RBus_UInt32  ve_cah_1p_drf_bist_en:1;
        RBus_UInt32  ve_dbk_drf_bist_en:1;
        RBus_UInt32  ve_mvd_rlmvbuf_drf_bist_en:1;
        RBus_UInt32  ve_rlrmem_fme_drf_bist_en:1;
        RBus_UInt32  ve_cm_drf_bist_en:1;
        RBus_UInt32  ve_ndb_drf_bist_en:1;
        RBus_UInt32  ve_brg_drf_bist_en:1;
        RBus_UInt32  ve_it_bs_drf_bist_en:1;
        RBus_UInt32  ve_it_drf_bist_en:1;
        RBus_UInt32  ve_vm_drf_bist_en:1;
        RBus_UInt32  ve_vld_drf_bist_en:1;
        RBus_UInt32  ve_rif_drf_bist_en:1;
    };
}lgcy_ve_mbist_ve_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  ve_dmem_drf_resume:1;
        RBus_UInt32  ve_ip_gc_drf_resume:1;
        RBus_UInt32  ve_pred_2p_drf_resume:1;
        RBus_UInt32  ve_pred_drf_resume:1;
        RBus_UInt32  ve_fme_drf_resume:1;
        RBus_UInt32  ve_cah_2p_drf_resume:1;
        RBus_UInt32  ve_cah_1p_drf_resume:1;
        RBus_UInt32  ve_dbk_drf_resume:1;
        RBus_UInt32  ve_mvd_rlmvbuf_drf_resume:1;
        RBus_UInt32  ve_rlrmem_fme_drf_resume:1;
        RBus_UInt32  ve_cm_drf_resume:1;
        RBus_UInt32  ve_ndb_drf_resume:1;
        RBus_UInt32  ve_brg_drf_resume:1;
        RBus_UInt32  ve_it_bs_drf_resume:1;
        RBus_UInt32  ve_it_drf_resume:1;
        RBus_UInt32  ve_vm_drf_resume:1;
        RBus_UInt32  ve_vld_drf_resume:1;
        RBus_UInt32  ve_rif_drf_resume:1;
    };
}lgcy_ve_mbist_ve_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  ve_dmem_drf_start_pause:1;
        RBus_UInt32  ve_ip_gc_drf_start_pause:1;
        RBus_UInt32  ve_pred_2p_drf_start_pause:1;
        RBus_UInt32  ve_pred_drf_start_pause:1;
        RBus_UInt32  ve_fme_drf_start_pause:1;
        RBus_UInt32  ve_cah_2p_drf_start_pause:1;
        RBus_UInt32  ve_cah_1p_drf_start_pause:1;
        RBus_UInt32  ve_dbk_drf_start_pause:1;
        RBus_UInt32  ve_mvd_rlmvbuf_drf_start_pause:1;
        RBus_UInt32  ve_rlrmem_fme_drf_start_pause:1;
        RBus_UInt32  ve_cm_drf_start_pause:1;
        RBus_UInt32  ve_ndb_drf_start_pause:1;
        RBus_UInt32  ve_brg_drf_start_pause:1;
        RBus_UInt32  ve_it_bs_drf_start_pause:1;
        RBus_UInt32  ve_it_drf_start_pause:1;
        RBus_UInt32  ve_vm_drf_start_pause:1;
        RBus_UInt32  ve_vld_drf_start_pause:1;
        RBus_UInt32  ve_rif_drf_start_pause:1;
    };
}lgcy_ve_mbist_ve_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  ve_drf_dmem_done:1;
        RBus_UInt32  ve_drf_ip_gc_done:1;
        RBus_UInt32  ve_drf_pred_2p_done:1;
        RBus_UInt32  ve_drf_pred_done:1;
        RBus_UInt32  ve_drf_fme_done:1;
        RBus_UInt32  ve_drf_cah_2p_done:1;
        RBus_UInt32  ve_drf_cah_1p_done:1;
        RBus_UInt32  ve_drf_dbk_done:1;
        RBus_UInt32  ve_drf_mvd_rlmvbuf_done:1;
        RBus_UInt32  ve_drf_rlrmem_fme_done:1;
        RBus_UInt32  ve_drf_cm_done:1;
        RBus_UInt32  ve_drf_ndb_done:1;
        RBus_UInt32  ve_drf_brg_done:1;
        RBus_UInt32  ve_drf_it_bs_done:1;
        RBus_UInt32  ve_drf_it_done:1;
        RBus_UInt32  ve_drf_vm_done:1;
        RBus_UInt32  ve_drf_vld_done:1;
        RBus_UInt32  ve_drf_rif_done:1;
    };
}lgcy_ve_mbist_ve_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  ve_drf_dmem_fail_group:1;
        RBus_UInt32  ve_drf_ip_gc_fail_group:1;
        RBus_UInt32  ve_drf_pred_2p_fail_group:1;
        RBus_UInt32  ve_drf_pred_fail_group:1;
        RBus_UInt32  ve_drf_fme_fail_group:1;
        RBus_UInt32  ve_drf_cah_2p_fail_group:1;
        RBus_UInt32  ve_drf_cah_1p_fail_group:1;
        RBus_UInt32  ve_drf_dbk_fail_group:1;
        RBus_UInt32  ve_drf_mvd_rlmvbuf_fail_group:1;
        RBus_UInt32  ve_drf_rlrmem_fme_fail_group:1;
        RBus_UInt32  ve_drf_cm_fail_group:1;
        RBus_UInt32  ve_drf_ndb_fail_group:1;
        RBus_UInt32  ve_drf_brg_fail_group:1;
        RBus_UInt32  ve_drf_it_bs_fail_group:1;
        RBus_UInt32  ve_drf_it_fail_group:1;
        RBus_UInt32  ve_drf_vm_fail_group:1;
        RBus_UInt32  ve_drf_vld_fail_group:1;
        RBus_UInt32  ve_drf_rif_fail_group:1;
    };
}lgcy_ve_mbist_ve_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  ve_bist_rif_fail:9;
    };
}lgcy_ve_mbist_ve_bist_rif_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  ve_drf_rif_fail:9;
    };
}lgcy_ve_mbist_ve_drf_rif_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  ve_bist_vld_fail:5;
    };
}lgcy_ve_mbist_ve_bist_vld_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  ve_drf_vld_fail:5;
    };
}lgcy_ve_mbist_ve_drf_vld_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ve_bist_vm_fail:7;
    };
}lgcy_ve_mbist_ve_bist_vm_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ve_drf_vm_fail:7;
    };
}lgcy_ve_mbist_ve_drf_vm_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ve_bist_it_fail:4;
    };
}lgcy_ve_mbist_ve_bist_it_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ve_drf_it_fail:4;
    };
}lgcy_ve_mbist_ve_drf_it_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ve_bist_it_bs_fail:3;
    };
}lgcy_ve_mbist_ve_bist_it_bs_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ve_drf_it_bs_fail:3;
    };
}lgcy_ve_mbist_ve_drf_it_bs_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ve_bist_brg_fail:6;
    };
}lgcy_ve_mbist_ve_bist_brg_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ve_drf_brg_fail:6;
    };
}lgcy_ve_mbist_ve_drf_brg_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ve_bist_ndb_fail:4;
    };
}lgcy_ve_mbist_ve_bist_ndb_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ve_drf_ndb_fail:4;
    };
}lgcy_ve_mbist_ve_drf_ndb_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  ve_bist_cm_fail:12;
    };
}lgcy_ve_mbist_ve_bist_cm1_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  ve_drf_cm_fail:12;
    };
}lgcy_ve_mbist_ve_drf_cm1_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ve_bist_rlrmem_fme_fail:3;
    };
}lgcy_ve_mbist_ve_bist_rlrmem_fme_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ve_drf_rlrmem_fme_fail:3;
    };
}lgcy_ve_mbist_ve_drf_rlrmem_fme_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ve_bist_mvd_rlmvbuf_fail:4;
    };
}lgcy_ve_mbist_ve_bist_mvd_rlmvbuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ve_drf_mvd_rlmvbuf_fail:4;
    };
}lgcy_ve_mbist_ve_drf_mvd_rlmvbuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  ve_bist_dbk_fail:9;
    };
}lgcy_ve_mbist_ve_bist_dbk_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  ve_drf_dbk_fail:9;
    };
}lgcy_ve_mbist_ve_drf_dbk_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ve_bist_cah_1p_fail:4;
    };
}lgcy_ve_mbist_ve_bist_cah_1p_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ve_drf_cah_1p_fail:4;
    };
}lgcy_ve_mbist_ve_drf_cah_1p_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ve_bist_cah_2p_fail:3;
    };
}lgcy_ve_mbist_ve_bist_cah_2p_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ve_drf_cah_2p_fail:3;
    };
}lgcy_ve_mbist_ve_drf_cah_2p_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ve_bist_fme_fail:7;
    };
}lgcy_ve_mbist_ve_bist_fme_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ve_drf_fme_fail:7;
    };
}lgcy_ve_mbist_ve_drf_fme_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ve_bist_pred_fail:7;
    };
}lgcy_ve_mbist_ve_bist_pred_0_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ve_drf_pred_fail:7;
    };
}lgcy_ve_mbist_ve_drf_pred_0_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ve_bist_pred_2p_fail:2;
    };
}lgcy_ve_mbist_ve_bist_pred_2p_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ve_drf_pred_2p_fail:2;
    };
}lgcy_ve_mbist_ve_drf_pred_2p_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ve_bist_ip_gc_fail:7;
    };
}lgcy_ve_mbist_ve_bist_ip_gc_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ve_drf_ip_gc_fail:7;
    };
}lgcy_ve_mbist_ve_drf_ip_gc_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ve_bist_dmem_fail:2;
    };
}lgcy_ve_mbist_ve_bist_dmem_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ve_drf_dmem_fail:2;
    };
}lgcy_ve_mbist_ve_drf_dmem_fail_RBUS;

#else //apply LITTLE_ENDIAN

//======LGCY_VE_MBIST register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm:4;
        RBus_UInt32  rme:1;
        RBus_UInt32  rmb:4;
        RBus_UInt32  rmeb:1;
        RBus_UInt32  rma:4;
        RBus_UInt32  rmea:1;
        RBus_UInt32  sysh_rm:4;
        RBus_UInt32  sysh_rme:1;
        RBus_UInt32  sysh_rmb:4;
        RBus_UInt32  sysh_rmeb:1;
        RBus_UInt32  sysh_rma:4;
        RBus_UInt32  sysh_rmea:1;
        RBus_UInt32  bist_2p_clk_sel:1;
        RBus_UInt32  test_rwm:1;
    };
}lgcy_ve_mbist_ve_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vld_ls:2;
        RBus_UInt32  mvd_ls:2;
        RBus_UInt32  itblk_ls:2;
        RBus_UInt32  cm_ls:2;
        RBus_UInt32  rl_ls:2;
        RBus_UInt32  cache_ls:2;
        RBus_UInt32  pred_ls:2;
        RBus_UInt32  deblk_ls:2;
        RBus_UInt32  cmprs_ls:2;
        RBus_UInt32  vmem_ls:2;
        RBus_UInt32  brg_ls:2;
        RBus_UInt32  dmem_ls:2;
        RBus_UInt32  bs_ls:2;
        RBus_UInt32  ndb_ls:2;
        RBus_UInt32  fme_ls:2;
        RBus_UInt32  ip_gc_ls:2;
    };
}lgcy_ve_mbist_ve_bist_ls_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_rif_bist_en:1;
        RBus_UInt32  ve_vld_bist_en:1;
        RBus_UInt32  ve_vm_bist_en:1;
        RBus_UInt32  ve_it_bist_en:1;
        RBus_UInt32  ve_it_bs_bist_en:1;
        RBus_UInt32  ve_brg_bist_en:1;
        RBus_UInt32  ve_ndb_bist_en:1;
        RBus_UInt32  ve_cm_bist_en:1;
        RBus_UInt32  ve_rlrmem_fme_bist_en:1;
        RBus_UInt32  ve_mvd_rlmvbuf_bist_en:1;
        RBus_UInt32  ve_dbk_bist_en:1;
        RBus_UInt32  ve_cah_1p_bist_en:1;
        RBus_UInt32  ve_cah_2p_bist_en:1;
        RBus_UInt32  ve_fme_bist_en:1;
        RBus_UInt32  ve_pred_bist_en:1;
        RBus_UInt32  ve_pred_2p_bist_en:1;
        RBus_UInt32  ve_ip_gc_bist_en:1;
        RBus_UInt32  ve_dmem_bist_en:1;
        RBus_UInt32  res1:14;
    };
}lgcy_ve_mbist_ve_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_rif_done:1;
        RBus_UInt32  ve_bist_vld_done:1;
        RBus_UInt32  ve_bist_vm_done:1;
        RBus_UInt32  ve_bist_it_done:1;
        RBus_UInt32  ve_bist_it_bs_done:1;
        RBus_UInt32  ve_bist_brg_done:1;
        RBus_UInt32  ve_bist_ndb_done:1;
        RBus_UInt32  ve_bist_cm_done:1;
        RBus_UInt32  ve_bist_rlrmem_fme_done:1;
        RBus_UInt32  ve_bist_mvd_rlmvbuf_done:1;
        RBus_UInt32  ve_bist_dbk_done:1;
        RBus_UInt32  ve_bist_cah_1p_done:1;
        RBus_UInt32  ve_bist_cah_2p_done:1;
        RBus_UInt32  ve_bist_fme_done:1;
        RBus_UInt32  ve_bist_pred_done:1;
        RBus_UInt32  ve_bist_pred_2p_done:1;
        RBus_UInt32  ve_bist_ip_gc_done:1;
        RBus_UInt32  ve_bist_dmem_done:1;
        RBus_UInt32  res1:14;
    };
}lgcy_ve_mbist_ve_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_rif_fail_group:1;
        RBus_UInt32  ve_bist_vld_fail_group:1;
        RBus_UInt32  ve_bist_vm_fail_group:1;
        RBus_UInt32  ve_bist_it_fail_group:1;
        RBus_UInt32  ve_bist_it_bs_fail_group:1;
        RBus_UInt32  ve_bist_brg_fail_group:1;
        RBus_UInt32  ve_bist_ndb_fail_group:1;
        RBus_UInt32  ve_bist_cm_fail_group:1;
        RBus_UInt32  ve_bist_rlrmem_fme_fail_group:1;
        RBus_UInt32  ve_bist_mvd_rlmvbuf_fail_group:1;
        RBus_UInt32  ve_bist_dbk_fail_group:1;
        RBus_UInt32  ve_bist_cah_1p_fail_group:1;
        RBus_UInt32  ve_bist_cah_2p_fail_group:1;
        RBus_UInt32  ve_bist_fme_fail_group:1;
        RBus_UInt32  ve_bist_pred_fail_group:1;
        RBus_UInt32  ve_bist_pred_2p_fail_group:1;
        RBus_UInt32  ve_bist_ip_gc_fail_group:1;
        RBus_UInt32  ve_bist_dmem_fail_group:1;
        RBus_UInt32  res1:14;
    };
}lgcy_ve_mbist_ve_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_rif_drf_bist_en:1;
        RBus_UInt32  ve_vld_drf_bist_en:1;
        RBus_UInt32  ve_vm_drf_bist_en:1;
        RBus_UInt32  ve_it_drf_bist_en:1;
        RBus_UInt32  ve_it_bs_drf_bist_en:1;
        RBus_UInt32  ve_brg_drf_bist_en:1;
        RBus_UInt32  ve_ndb_drf_bist_en:1;
        RBus_UInt32  ve_cm_drf_bist_en:1;
        RBus_UInt32  ve_rlrmem_fme_drf_bist_en:1;
        RBus_UInt32  ve_mvd_rlmvbuf_drf_bist_en:1;
        RBus_UInt32  ve_dbk_drf_bist_en:1;
        RBus_UInt32  ve_cah_1p_drf_bist_en:1;
        RBus_UInt32  ve_cah_2p_drf_bist_en:1;
        RBus_UInt32  ve_fme_drf_bist_en:1;
        RBus_UInt32  ve_pred_drf_bist_en:1;
        RBus_UInt32  ve_pred_2p_drf_bist_en:1;
        RBus_UInt32  ve_ip_gc_drf_bist_en:1;
        RBus_UInt32  ve_dmem_drf_bist_en:1;
        RBus_UInt32  res1:14;
    };
}lgcy_ve_mbist_ve_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_rif_drf_resume:1;
        RBus_UInt32  ve_vld_drf_resume:1;
        RBus_UInt32  ve_vm_drf_resume:1;
        RBus_UInt32  ve_it_drf_resume:1;
        RBus_UInt32  ve_it_bs_drf_resume:1;
        RBus_UInt32  ve_brg_drf_resume:1;
        RBus_UInt32  ve_ndb_drf_resume:1;
        RBus_UInt32  ve_cm_drf_resume:1;
        RBus_UInt32  ve_rlrmem_fme_drf_resume:1;
        RBus_UInt32  ve_mvd_rlmvbuf_drf_resume:1;
        RBus_UInt32  ve_dbk_drf_resume:1;
        RBus_UInt32  ve_cah_1p_drf_resume:1;
        RBus_UInt32  ve_cah_2p_drf_resume:1;
        RBus_UInt32  ve_fme_drf_resume:1;
        RBus_UInt32  ve_pred_drf_resume:1;
        RBus_UInt32  ve_pred_2p_drf_resume:1;
        RBus_UInt32  ve_ip_gc_drf_resume:1;
        RBus_UInt32  ve_dmem_drf_resume:1;
        RBus_UInt32  res1:14;
    };
}lgcy_ve_mbist_ve_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_rif_drf_start_pause:1;
        RBus_UInt32  ve_vld_drf_start_pause:1;
        RBus_UInt32  ve_vm_drf_start_pause:1;
        RBus_UInt32  ve_it_drf_start_pause:1;
        RBus_UInt32  ve_it_bs_drf_start_pause:1;
        RBus_UInt32  ve_brg_drf_start_pause:1;
        RBus_UInt32  ve_ndb_drf_start_pause:1;
        RBus_UInt32  ve_cm_drf_start_pause:1;
        RBus_UInt32  ve_rlrmem_fme_drf_start_pause:1;
        RBus_UInt32  ve_mvd_rlmvbuf_drf_start_pause:1;
        RBus_UInt32  ve_dbk_drf_start_pause:1;
        RBus_UInt32  ve_cah_1p_drf_start_pause:1;
        RBus_UInt32  ve_cah_2p_drf_start_pause:1;
        RBus_UInt32  ve_fme_drf_start_pause:1;
        RBus_UInt32  ve_pred_drf_start_pause:1;
        RBus_UInt32  ve_pred_2p_drf_start_pause:1;
        RBus_UInt32  ve_ip_gc_drf_start_pause:1;
        RBus_UInt32  ve_dmem_drf_start_pause:1;
        RBus_UInt32  res1:14;
    };
}lgcy_ve_mbist_ve_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_rif_done:1;
        RBus_UInt32  ve_drf_vld_done:1;
        RBus_UInt32  ve_drf_vm_done:1;
        RBus_UInt32  ve_drf_it_done:1;
        RBus_UInt32  ve_drf_it_bs_done:1;
        RBus_UInt32  ve_drf_brg_done:1;
        RBus_UInt32  ve_drf_ndb_done:1;
        RBus_UInt32  ve_drf_cm_done:1;
        RBus_UInt32  ve_drf_rlrmem_fme_done:1;
        RBus_UInt32  ve_drf_mvd_rlmvbuf_done:1;
        RBus_UInt32  ve_drf_dbk_done:1;
        RBus_UInt32  ve_drf_cah_1p_done:1;
        RBus_UInt32  ve_drf_cah_2p_done:1;
        RBus_UInt32  ve_drf_fme_done:1;
        RBus_UInt32  ve_drf_pred_done:1;
        RBus_UInt32  ve_drf_pred_2p_done:1;
        RBus_UInt32  ve_drf_ip_gc_done:1;
        RBus_UInt32  ve_drf_dmem_done:1;
        RBus_UInt32  res1:14;
    };
}lgcy_ve_mbist_ve_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_rif_fail_group:1;
        RBus_UInt32  ve_drf_vld_fail_group:1;
        RBus_UInt32  ve_drf_vm_fail_group:1;
        RBus_UInt32  ve_drf_it_fail_group:1;
        RBus_UInt32  ve_drf_it_bs_fail_group:1;
        RBus_UInt32  ve_drf_brg_fail_group:1;
        RBus_UInt32  ve_drf_ndb_fail_group:1;
        RBus_UInt32  ve_drf_cm_fail_group:1;
        RBus_UInt32  ve_drf_rlrmem_fme_fail_group:1;
        RBus_UInt32  ve_drf_mvd_rlmvbuf_fail_group:1;
        RBus_UInt32  ve_drf_dbk_fail_group:1;
        RBus_UInt32  ve_drf_cah_1p_fail_group:1;
        RBus_UInt32  ve_drf_cah_2p_fail_group:1;
        RBus_UInt32  ve_drf_fme_fail_group:1;
        RBus_UInt32  ve_drf_pred_fail_group:1;
        RBus_UInt32  ve_drf_pred_2p_fail_group:1;
        RBus_UInt32  ve_drf_ip_gc_fail_group:1;
        RBus_UInt32  ve_drf_dmem_fail_group:1;
        RBus_UInt32  res1:14;
    };
}lgcy_ve_mbist_ve_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_rif_fail:9;
        RBus_UInt32  res1:23;
    };
}lgcy_ve_mbist_ve_bist_rif_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_rif_fail:9;
        RBus_UInt32  res1:23;
    };
}lgcy_ve_mbist_ve_drf_rif_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_vld_fail:5;
        RBus_UInt32  res1:27;
    };
}lgcy_ve_mbist_ve_bist_vld_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_vld_fail:5;
        RBus_UInt32  res1:27;
    };
}lgcy_ve_mbist_ve_drf_vld_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_vm_fail:7;
        RBus_UInt32  res1:25;
    };
}lgcy_ve_mbist_ve_bist_vm_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_vm_fail:7;
        RBus_UInt32  res1:25;
    };
}lgcy_ve_mbist_ve_drf_vm_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_it_fail:4;
        RBus_UInt32  res1:28;
    };
}lgcy_ve_mbist_ve_bist_it_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_it_fail:4;
        RBus_UInt32  res1:28;
    };
}lgcy_ve_mbist_ve_drf_it_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_it_bs_fail:3;
        RBus_UInt32  res1:29;
    };
}lgcy_ve_mbist_ve_bist_it_bs_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_it_bs_fail:3;
        RBus_UInt32  res1:29;
    };
}lgcy_ve_mbist_ve_drf_it_bs_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_brg_fail:6;
        RBus_UInt32  res1:26;
    };
}lgcy_ve_mbist_ve_bist_brg_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_brg_fail:6;
        RBus_UInt32  res1:26;
    };
}lgcy_ve_mbist_ve_drf_brg_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_ndb_fail:4;
        RBus_UInt32  res1:28;
    };
}lgcy_ve_mbist_ve_bist_ndb_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_ndb_fail:4;
        RBus_UInt32  res1:28;
    };
}lgcy_ve_mbist_ve_drf_ndb_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_cm_fail:12;
        RBus_UInt32  res1:20;
    };
}lgcy_ve_mbist_ve_bist_cm1_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_cm_fail:12;
        RBus_UInt32  res1:20;
    };
}lgcy_ve_mbist_ve_drf_cm1_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_rlrmem_fme_fail:3;
        RBus_UInt32  res1:29;
    };
}lgcy_ve_mbist_ve_bist_rlrmem_fme_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_rlrmem_fme_fail:3;
        RBus_UInt32  res1:29;
    };
}lgcy_ve_mbist_ve_drf_rlrmem_fme_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_mvd_rlmvbuf_fail:4;
        RBus_UInt32  res1:28;
    };
}lgcy_ve_mbist_ve_bist_mvd_rlmvbuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_mvd_rlmvbuf_fail:4;
        RBus_UInt32  res1:28;
    };
}lgcy_ve_mbist_ve_drf_mvd_rlmvbuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_dbk_fail:9;
        RBus_UInt32  res1:23;
    };
}lgcy_ve_mbist_ve_bist_dbk_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_dbk_fail:9;
        RBus_UInt32  res1:23;
    };
}lgcy_ve_mbist_ve_drf_dbk_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_cah_1p_fail:4;
        RBus_UInt32  res1:28;
    };
}lgcy_ve_mbist_ve_bist_cah_1p_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_cah_1p_fail:4;
        RBus_UInt32  res1:28;
    };
}lgcy_ve_mbist_ve_drf_cah_1p_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_cah_2p_fail:3;
        RBus_UInt32  res1:29;
    };
}lgcy_ve_mbist_ve_bist_cah_2p_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_cah_2p_fail:3;
        RBus_UInt32  res1:29;
    };
}lgcy_ve_mbist_ve_drf_cah_2p_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_fme_fail:7;
        RBus_UInt32  res1:25;
    };
}lgcy_ve_mbist_ve_bist_fme_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_fme_fail:7;
        RBus_UInt32  res1:25;
    };
}lgcy_ve_mbist_ve_drf_fme_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_pred_fail:7;
        RBus_UInt32  res1:25;
    };
}lgcy_ve_mbist_ve_bist_pred_0_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_pred_fail:7;
        RBus_UInt32  res1:25;
    };
}lgcy_ve_mbist_ve_drf_pred_0_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_pred_2p_fail:2;
        RBus_UInt32  res1:30;
    };
}lgcy_ve_mbist_ve_bist_pred_2p_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_pred_2p_fail:2;
        RBus_UInt32  res1:30;
    };
}lgcy_ve_mbist_ve_drf_pred_2p_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_ip_gc_fail:7;
        RBus_UInt32  res1:25;
    };
}lgcy_ve_mbist_ve_bist_ip_gc_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_ip_gc_fail:7;
        RBus_UInt32  res1:25;
    };
}lgcy_ve_mbist_ve_drf_ip_gc_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_bist_dmem_fail:2;
        RBus_UInt32  res1:30;
    };
}lgcy_ve_mbist_ve_bist_dmem_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_drf_dmem_fail:2;
        RBus_UInt32  res1:30;
    };
}lgcy_ve_mbist_ve_drf_dmem_fail_RBUS;




#endif 


#endif 
