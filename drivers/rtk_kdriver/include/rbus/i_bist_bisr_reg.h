/**
* @file MarArthur5-DesignSpec-I-Domain_BIST_BISR_control
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_I_BIST_BISR_REG_H_
#define _RBUS_I_BIST_BISR_REG_H_

#include "rbus_types.h"



//  I_BIST_BISR Register Address
#define  I_BIST_BISR_DISPI_BIST_MODE                                             0x18025F00
#define  I_BIST_BISR_DISPI_BIST_MODE_reg_addr                                    "0xB8025F00"
#define  I_BIST_BISR_DISPI_BIST_MODE_reg                                         0xB8025F00
#define  I_BIST_BISR_DISPI_BIST_MODE_inst_addr                                   "0x0000"
#define  set_I_BIST_BISR_DISPI_BIST_MODE_reg(data)                               (*((volatile unsigned int*)I_BIST_BISR_DISPI_BIST_MODE_reg)=data)
#define  get_I_BIST_BISR_DISPI_BIST_MODE_reg                                     (*((volatile unsigned int*)I_BIST_BISR_DISPI_BIST_MODE_reg))
#define  I_BIST_BISR_DISPI_BIST_MODE_ch1_mbist_hist_1p_bist_mode_shift           (28)
#define  I_BIST_BISR_DISPI_BIST_MODE_ch1_mbist_hist_2p_bist_mode_shift           (27)
#define  I_BIST_BISR_DISPI_BIST_MODE_rtnr_mcnr_tmv1_bist_mode_shift              (26)
#define  I_BIST_BISR_DISPI_BIST_MODE_rtnr_mcnr_tmv2_bist_mode_shift              (25)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li4_bist_mode_shift                      (24)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li5_bist_mode_shift                      (23)
#define  I_BIST_BISR_DISPI_BIST_MODE_pqdc1_bist_mode_shift                       (22)
#define  I_BIST_BISR_DISPI_BIST_MODE_pqdc2_bist_mode_shift                       (21)
#define  I_BIST_BISR_DISPI_BIST_MODE_pqc1_bist_mode_shift                        (20)
#define  I_BIST_BISR_DISPI_BIST_MODE_pqc2_bist_mode_shift                        (19)
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_winfo_bist_mode_shift                (16)
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_wdat_bist_mode_shift                 (15)
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_rinfo_bist_mode_shift                (14)
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_rdat2_bist_mode_shift                (13)
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_rdat1_bist_mode_shift                (12)
#define  I_BIST_BISR_DISPI_BIST_MODE_i3ddma_bist_cap2_mode_shift                 (11)
#define  I_BIST_BISR_DISPI_BIST_MODE_sdnr_ch1_bist_mode_shift                    (10)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_tr2to1_bist_mode_shift                   (8)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_hmc_bist_mode_shift                      (7)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_dma_wdat_bist_mode_shift                 (6)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_dma_rdat_bist_mode_shift                 (5)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li1_bist_mode_shift                      (4)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li2_bist_mode_shift                      (3)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li3_bist_mode_shift                      (2)
#define  I_BIST_BISR_DISPI_BIST_MODE_i3ddma_uzd_bist_mode_shift                  (1)
#define  I_BIST_BISR_DISPI_BIST_MODE_i3ddma_bist_mode_shift                      (0)
#define  I_BIST_BISR_DISPI_BIST_MODE_ch1_mbist_hist_1p_bist_mode_mask            (0x10000000)
#define  I_BIST_BISR_DISPI_BIST_MODE_ch1_mbist_hist_2p_bist_mode_mask            (0x08000000)
#define  I_BIST_BISR_DISPI_BIST_MODE_rtnr_mcnr_tmv1_bist_mode_mask               (0x04000000)
#define  I_BIST_BISR_DISPI_BIST_MODE_rtnr_mcnr_tmv2_bist_mode_mask               (0x02000000)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li4_bist_mode_mask                       (0x01000000)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li5_bist_mode_mask                       (0x00800000)
#define  I_BIST_BISR_DISPI_BIST_MODE_pqdc1_bist_mode_mask                        (0x00400000)
#define  I_BIST_BISR_DISPI_BIST_MODE_pqdc2_bist_mode_mask                        (0x00200000)
#define  I_BIST_BISR_DISPI_BIST_MODE_pqc1_bist_mode_mask                         (0x00100000)
#define  I_BIST_BISR_DISPI_BIST_MODE_pqc2_bist_mode_mask                         (0x00080000)
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_winfo_bist_mode_mask                 (0x00010000)
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_wdat_bist_mode_mask                  (0x00008000)
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_rinfo_bist_mode_mask                 (0x00004000)
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_rdat2_bist_mode_mask                 (0x00002000)
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_rdat1_bist_mode_mask                 (0x00001000)
#define  I_BIST_BISR_DISPI_BIST_MODE_i3ddma_bist_cap2_mode_mask                  (0x00000800)
#define  I_BIST_BISR_DISPI_BIST_MODE_sdnr_ch1_bist_mode_mask                     (0x00000400)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_tr2to1_bist_mode_mask                    (0x00000100)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_hmc_bist_mode_mask                       (0x00000080)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_dma_wdat_bist_mode_mask                  (0x00000040)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_dma_rdat_bist_mode_mask                  (0x00000020)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li1_bist_mode_mask                       (0x00000010)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li2_bist_mode_mask                       (0x00000008)
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li3_bist_mode_mask                       (0x00000004)
#define  I_BIST_BISR_DISPI_BIST_MODE_i3ddma_uzd_bist_mode_mask                   (0x00000002)
#define  I_BIST_BISR_DISPI_BIST_MODE_i3ddma_bist_mode_mask                       (0x00000001)
#define  I_BIST_BISR_DISPI_BIST_MODE_ch1_mbist_hist_1p_bist_mode(data)           (0x10000000&((data)<<28))
#define  I_BIST_BISR_DISPI_BIST_MODE_ch1_mbist_hist_2p_bist_mode(data)           (0x08000000&((data)<<27))
#define  I_BIST_BISR_DISPI_BIST_MODE_rtnr_mcnr_tmv1_bist_mode(data)              (0x04000000&((data)<<26))
#define  I_BIST_BISR_DISPI_BIST_MODE_rtnr_mcnr_tmv2_bist_mode(data)              (0x02000000&((data)<<25))
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li4_bist_mode(data)                      (0x01000000&((data)<<24))
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li5_bist_mode(data)                      (0x00800000&((data)<<23))
#define  I_BIST_BISR_DISPI_BIST_MODE_pqdc1_bist_mode(data)                       (0x00400000&((data)<<22))
#define  I_BIST_BISR_DISPI_BIST_MODE_pqdc2_bist_mode(data)                       (0x00200000&((data)<<21))
#define  I_BIST_BISR_DISPI_BIST_MODE_pqc1_bist_mode(data)                        (0x00100000&((data)<<20))
#define  I_BIST_BISR_DISPI_BIST_MODE_pqc2_bist_mode(data)                        (0x00080000&((data)<<19))
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_winfo_bist_mode(data)                (0x00010000&((data)<<16))
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_wdat_bist_mode(data)                 (0x00008000&((data)<<15))
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_rinfo_bist_mode(data)                (0x00004000&((data)<<14))
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_rdat2_bist_mode(data)                (0x00002000&((data)<<13))
#define  I_BIST_BISR_DISPI_BIST_MODE_dexcxl_rdat1_bist_mode(data)                (0x00001000&((data)<<12))
#define  I_BIST_BISR_DISPI_BIST_MODE_i3ddma_bist_cap2_mode(data)                 (0x00000800&((data)<<11))
#define  I_BIST_BISR_DISPI_BIST_MODE_sdnr_ch1_bist_mode(data)                    (0x00000400&((data)<<10))
#define  I_BIST_BISR_DISPI_BIST_MODE_di_tr2to1_bist_mode(data)                   (0x00000100&((data)<<8))
#define  I_BIST_BISR_DISPI_BIST_MODE_di_hmc_bist_mode(data)                      (0x00000080&((data)<<7))
#define  I_BIST_BISR_DISPI_BIST_MODE_di_dma_wdat_bist_mode(data)                 (0x00000040&((data)<<6))
#define  I_BIST_BISR_DISPI_BIST_MODE_di_dma_rdat_bist_mode(data)                 (0x00000020&((data)<<5))
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li1_bist_mode(data)                      (0x00000010&((data)<<4))
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li2_bist_mode(data)                      (0x00000008&((data)<<3))
#define  I_BIST_BISR_DISPI_BIST_MODE_di_li3_bist_mode(data)                      (0x00000004&((data)<<2))
#define  I_BIST_BISR_DISPI_BIST_MODE_i3ddma_uzd_bist_mode(data)                  (0x00000002&((data)<<1))
#define  I_BIST_BISR_DISPI_BIST_MODE_i3ddma_bist_mode(data)                      (0x00000001&(data))
#define  I_BIST_BISR_DISPI_BIST_MODE_get_ch1_mbist_hist_1p_bist_mode(data)       ((0x10000000&(data))>>28)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_ch1_mbist_hist_2p_bist_mode(data)       ((0x08000000&(data))>>27)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_rtnr_mcnr_tmv1_bist_mode(data)          ((0x04000000&(data))>>26)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_rtnr_mcnr_tmv2_bist_mode(data)          ((0x02000000&(data))>>25)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_di_li4_bist_mode(data)                  ((0x01000000&(data))>>24)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_di_li5_bist_mode(data)                  ((0x00800000&(data))>>23)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_pqdc1_bist_mode(data)                   ((0x00400000&(data))>>22)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_pqdc2_bist_mode(data)                   ((0x00200000&(data))>>21)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_pqc1_bist_mode(data)                    ((0x00100000&(data))>>20)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_pqc2_bist_mode(data)                    ((0x00080000&(data))>>19)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_dexcxl_winfo_bist_mode(data)            ((0x00010000&(data))>>16)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_dexcxl_wdat_bist_mode(data)             ((0x00008000&(data))>>15)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_dexcxl_rinfo_bist_mode(data)            ((0x00004000&(data))>>14)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_dexcxl_rdat2_bist_mode(data)            ((0x00002000&(data))>>13)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_dexcxl_rdat1_bist_mode(data)            ((0x00001000&(data))>>12)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_i3ddma_bist_cap2_mode(data)             ((0x00000800&(data))>>11)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_sdnr_ch1_bist_mode(data)                ((0x00000400&(data))>>10)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_di_tr2to1_bist_mode(data)               ((0x00000100&(data))>>8)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_di_hmc_bist_mode(data)                  ((0x00000080&(data))>>7)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_di_dma_wdat_bist_mode(data)             ((0x00000040&(data))>>6)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_di_dma_rdat_bist_mode(data)             ((0x00000020&(data))>>5)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_di_li1_bist_mode(data)                  ((0x00000010&(data))>>4)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_di_li2_bist_mode(data)                  ((0x00000008&(data))>>3)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_di_li3_bist_mode(data)                  ((0x00000004&(data))>>2)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_i3ddma_uzd_bist_mode(data)              ((0x00000002&(data))>>1)
#define  I_BIST_BISR_DISPI_BIST_MODE_get_i3ddma_bist_mode(data)                  (0x00000001&(data))

#define  I_BIST_BISR_DISPI_BIST_DONE                                             0x18025F04
#define  I_BIST_BISR_DISPI_BIST_DONE_reg_addr                                    "0xB8025F04"
#define  I_BIST_BISR_DISPI_BIST_DONE_reg                                         0xB8025F04
#define  I_BIST_BISR_DISPI_BIST_DONE_inst_addr                                   "0x0001"
#define  set_I_BIST_BISR_DISPI_BIST_DONE_reg(data)                               (*((volatile unsigned int*)I_BIST_BISR_DISPI_BIST_DONE_reg)=data)
#define  get_I_BIST_BISR_DISPI_BIST_DONE_reg                                     (*((volatile unsigned int*)I_BIST_BISR_DISPI_BIST_DONE_reg))
#define  I_BIST_BISR_DISPI_BIST_DONE_ch1_mbist_hist_1p_bist_done_shift           (28)
#define  I_BIST_BISR_DISPI_BIST_DONE_ch1_mbist_hist_2p_bist_done_shift           (27)
#define  I_BIST_BISR_DISPI_BIST_DONE_rtnr_mcnr_tmv1_bist_done_shift              (26)
#define  I_BIST_BISR_DISPI_BIST_DONE_rtnr_mcnr_tmv2_bist_done_shift              (25)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li4_bist_done_shift                      (24)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li5_bist_done_shift                      (23)
#define  I_BIST_BISR_DISPI_BIST_DONE_pqdc1_bist_done_shift                       (22)
#define  I_BIST_BISR_DISPI_BIST_DONE_pqdc2_bist_done_shift                       (21)
#define  I_BIST_BISR_DISPI_BIST_DONE_pqc1_bist_done_shift                        (20)
#define  I_BIST_BISR_DISPI_BIST_DONE_pqc2_bist_done_shift                        (19)
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_winfo_bist_done_shift                (16)
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_wdat_bist_done_shift                 (15)
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_rinfo_bist_done_shift                (14)
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_rdat2_bist_done_shift                (13)
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_rdat1_bist_done_shift                (12)
#define  I_BIST_BISR_DISPI_BIST_DONE_i3ddma_bist_cap2_done_shift                 (11)
#define  I_BIST_BISR_DISPI_BIST_DONE_sdnr_ch1_bist_done_shift                    (10)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_tr2to1_bist_done_shift                   (8)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_hmc_bist_done_shift                      (7)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_dma_wdat_bist_done_shift                 (6)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_dma_rdat_bist_done_shift                 (5)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li1_bist_done_shift                      (4)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li2_bist_done_shift                      (3)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li3_bist_done_shift                      (2)
#define  I_BIST_BISR_DISPI_BIST_DONE_i3ddma_uzd_bist_done_shift                  (1)
#define  I_BIST_BISR_DISPI_BIST_DONE_i3ddma_bist_done_shift                      (0)
#define  I_BIST_BISR_DISPI_BIST_DONE_ch1_mbist_hist_1p_bist_done_mask            (0x10000000)
#define  I_BIST_BISR_DISPI_BIST_DONE_ch1_mbist_hist_2p_bist_done_mask            (0x08000000)
#define  I_BIST_BISR_DISPI_BIST_DONE_rtnr_mcnr_tmv1_bist_done_mask               (0x04000000)
#define  I_BIST_BISR_DISPI_BIST_DONE_rtnr_mcnr_tmv2_bist_done_mask               (0x02000000)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li4_bist_done_mask                       (0x01000000)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li5_bist_done_mask                       (0x00800000)
#define  I_BIST_BISR_DISPI_BIST_DONE_pqdc1_bist_done_mask                        (0x00400000)
#define  I_BIST_BISR_DISPI_BIST_DONE_pqdc2_bist_done_mask                        (0x00200000)
#define  I_BIST_BISR_DISPI_BIST_DONE_pqc1_bist_done_mask                         (0x00100000)
#define  I_BIST_BISR_DISPI_BIST_DONE_pqc2_bist_done_mask                         (0x00080000)
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_winfo_bist_done_mask                 (0x00010000)
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_wdat_bist_done_mask                  (0x00008000)
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_rinfo_bist_done_mask                 (0x00004000)
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_rdat2_bist_done_mask                 (0x00002000)
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_rdat1_bist_done_mask                 (0x00001000)
#define  I_BIST_BISR_DISPI_BIST_DONE_i3ddma_bist_cap2_done_mask                  (0x00000800)
#define  I_BIST_BISR_DISPI_BIST_DONE_sdnr_ch1_bist_done_mask                     (0x00000400)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_tr2to1_bist_done_mask                    (0x00000100)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_hmc_bist_done_mask                       (0x00000080)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_dma_wdat_bist_done_mask                  (0x00000040)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_dma_rdat_bist_done_mask                  (0x00000020)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li1_bist_done_mask                       (0x00000010)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li2_bist_done_mask                       (0x00000008)
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li3_bist_done_mask                       (0x00000004)
#define  I_BIST_BISR_DISPI_BIST_DONE_i3ddma_uzd_bist_done_mask                   (0x00000002)
#define  I_BIST_BISR_DISPI_BIST_DONE_i3ddma_bist_done_mask                       (0x00000001)
#define  I_BIST_BISR_DISPI_BIST_DONE_ch1_mbist_hist_1p_bist_done(data)           (0x10000000&((data)<<28))
#define  I_BIST_BISR_DISPI_BIST_DONE_ch1_mbist_hist_2p_bist_done(data)           (0x08000000&((data)<<27))
#define  I_BIST_BISR_DISPI_BIST_DONE_rtnr_mcnr_tmv1_bist_done(data)              (0x04000000&((data)<<26))
#define  I_BIST_BISR_DISPI_BIST_DONE_rtnr_mcnr_tmv2_bist_done(data)              (0x02000000&((data)<<25))
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li4_bist_done(data)                      (0x01000000&((data)<<24))
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li5_bist_done(data)                      (0x00800000&((data)<<23))
#define  I_BIST_BISR_DISPI_BIST_DONE_pqdc1_bist_done(data)                       (0x00400000&((data)<<22))
#define  I_BIST_BISR_DISPI_BIST_DONE_pqdc2_bist_done(data)                       (0x00200000&((data)<<21))
#define  I_BIST_BISR_DISPI_BIST_DONE_pqc1_bist_done(data)                        (0x00100000&((data)<<20))
#define  I_BIST_BISR_DISPI_BIST_DONE_pqc2_bist_done(data)                        (0x00080000&((data)<<19))
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_winfo_bist_done(data)                (0x00010000&((data)<<16))
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_wdat_bist_done(data)                 (0x00008000&((data)<<15))
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_rinfo_bist_done(data)                (0x00004000&((data)<<14))
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_rdat2_bist_done(data)                (0x00002000&((data)<<13))
#define  I_BIST_BISR_DISPI_BIST_DONE_dexcxl_rdat1_bist_done(data)                (0x00001000&((data)<<12))
#define  I_BIST_BISR_DISPI_BIST_DONE_i3ddma_bist_cap2_done(data)                 (0x00000800&((data)<<11))
#define  I_BIST_BISR_DISPI_BIST_DONE_sdnr_ch1_bist_done(data)                    (0x00000400&((data)<<10))
#define  I_BIST_BISR_DISPI_BIST_DONE_di_tr2to1_bist_done(data)                   (0x00000100&((data)<<8))
#define  I_BIST_BISR_DISPI_BIST_DONE_di_hmc_bist_done(data)                      (0x00000080&((data)<<7))
#define  I_BIST_BISR_DISPI_BIST_DONE_di_dma_wdat_bist_done(data)                 (0x00000040&((data)<<6))
#define  I_BIST_BISR_DISPI_BIST_DONE_di_dma_rdat_bist_done(data)                 (0x00000020&((data)<<5))
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li1_bist_done(data)                      (0x00000010&((data)<<4))
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li2_bist_done(data)                      (0x00000008&((data)<<3))
#define  I_BIST_BISR_DISPI_BIST_DONE_di_li3_bist_done(data)                      (0x00000004&((data)<<2))
#define  I_BIST_BISR_DISPI_BIST_DONE_i3ddma_uzd_bist_done(data)                  (0x00000002&((data)<<1))
#define  I_BIST_BISR_DISPI_BIST_DONE_i3ddma_bist_done(data)                      (0x00000001&(data))
#define  I_BIST_BISR_DISPI_BIST_DONE_get_ch1_mbist_hist_1p_bist_done(data)       ((0x10000000&(data))>>28)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_ch1_mbist_hist_2p_bist_done(data)       ((0x08000000&(data))>>27)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_rtnr_mcnr_tmv1_bist_done(data)          ((0x04000000&(data))>>26)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_rtnr_mcnr_tmv2_bist_done(data)          ((0x02000000&(data))>>25)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_di_li4_bist_done(data)                  ((0x01000000&(data))>>24)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_di_li5_bist_done(data)                  ((0x00800000&(data))>>23)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_pqdc1_bist_done(data)                   ((0x00400000&(data))>>22)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_pqdc2_bist_done(data)                   ((0x00200000&(data))>>21)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_pqc1_bist_done(data)                    ((0x00100000&(data))>>20)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_pqc2_bist_done(data)                    ((0x00080000&(data))>>19)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_dexcxl_winfo_bist_done(data)            ((0x00010000&(data))>>16)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_dexcxl_wdat_bist_done(data)             ((0x00008000&(data))>>15)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_dexcxl_rinfo_bist_done(data)            ((0x00004000&(data))>>14)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_dexcxl_rdat2_bist_done(data)            ((0x00002000&(data))>>13)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_dexcxl_rdat1_bist_done(data)            ((0x00001000&(data))>>12)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_i3ddma_bist_cap2_done(data)             ((0x00000800&(data))>>11)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_sdnr_ch1_bist_done(data)                ((0x00000400&(data))>>10)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_di_tr2to1_bist_done(data)               ((0x00000100&(data))>>8)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_di_hmc_bist_done(data)                  ((0x00000080&(data))>>7)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_di_dma_wdat_bist_done(data)             ((0x00000040&(data))>>6)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_di_dma_rdat_bist_done(data)             ((0x00000020&(data))>>5)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_di_li1_bist_done(data)                  ((0x00000010&(data))>>4)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_di_li2_bist_done(data)                  ((0x00000008&(data))>>3)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_di_li3_bist_done(data)                  ((0x00000004&(data))>>2)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_i3ddma_uzd_bist_done(data)              ((0x00000002&(data))>>1)
#define  I_BIST_BISR_DISPI_BIST_DONE_get_i3ddma_bist_done(data)                  (0x00000001&(data))

#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP                                       0x18025F08
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_reg_addr                              "0xB8025F08"
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_reg                                   0xB8025F08
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_inst_addr                             "0x0002"
#define  set_I_BIST_BISR_DISPI_BIST_FAIL_GROUP_reg(data)                         (*((volatile unsigned int*)I_BIST_BISR_DISPI_BIST_FAIL_GROUP_reg)=data)
#define  get_I_BIST_BISR_DISPI_BIST_FAIL_GROUP_reg                               (*((volatile unsigned int*)I_BIST_BISR_DISPI_BIST_FAIL_GROUP_reg))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_ch1_mbist_hist_1p_fail_group_shift    (28)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_ch1_mbist_hist_2p_fail_group_shift    (27)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_rtnr_mcnr_tmv1_bist_fail_group_shift  (26)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_rtnr_mcnr_tmv2_bist_fail_group_shift  (25)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li4_bist_fail_group_shift          (24)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li5_bist_fail_group_shift          (23)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_pqdc1_bist_fail_group_shift           (22)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_pqdc2_bist_fail_group_shift           (21)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_pqc1_bist_fail_group_shift            (20)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_pqc2_bist_fail_group_shift            (19)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_winfo_bist_fail_group_shift    (16)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_wdat_bist_fail_group_shift     (15)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_rinfo_bist_fai_groupl_shift    (14)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_rdat2_bist_fail_group_shift    (13)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_rdat1_bist_fail_group_shift    (12)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_i3ddma_bist_cap2_fail_group_shift     (11)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_sdnr_ch1_bist_fail_group_shift        (10)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_tr2to1_bist_fail_group_shift       (8)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_hmc_bist_fail_group_shift          (7)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_dma_wdat_bist_fail_group_shift     (6)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_dma_rdat_bist_fail_group_shift     (5)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li1_bist_fail_group_shift          (4)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li2_bist_fail_group_shift          (3)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li3_bist_fail_group_shift          (2)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_i3ddma_uzd_bist_fail_group_shift      (1)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_i3ddma_bist_fail_group_shift          (0)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_ch1_mbist_hist_1p_fail_group_mask     (0x10000000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_ch1_mbist_hist_2p_fail_group_mask     (0x08000000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_rtnr_mcnr_tmv1_bist_fail_group_mask   (0x04000000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_rtnr_mcnr_tmv2_bist_fail_group_mask   (0x02000000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li4_bist_fail_group_mask           (0x01000000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li5_bist_fail_group_mask           (0x00800000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_pqdc1_bist_fail_group_mask            (0x00400000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_pqdc2_bist_fail_group_mask            (0x00200000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_pqc1_bist_fail_group_mask             (0x00100000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_pqc2_bist_fail_group_mask             (0x00080000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_winfo_bist_fail_group_mask     (0x00010000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_wdat_bist_fail_group_mask      (0x00008000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_rinfo_bist_fai_groupl_mask     (0x00004000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_rdat2_bist_fail_group_mask     (0x00002000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_rdat1_bist_fail_group_mask     (0x00001000)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_i3ddma_bist_cap2_fail_group_mask      (0x00000800)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_sdnr_ch1_bist_fail_group_mask         (0x00000400)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_tr2to1_bist_fail_group_mask        (0x00000100)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_hmc_bist_fail_group_mask           (0x00000080)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_dma_wdat_bist_fail_group_mask      (0x00000040)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_dma_rdat_bist_fail_group_mask      (0x00000020)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li1_bist_fail_group_mask           (0x00000010)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li2_bist_fail_group_mask           (0x00000008)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li3_bist_fail_group_mask           (0x00000004)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_i3ddma_uzd_bist_fail_group_mask       (0x00000002)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_i3ddma_bist_fail_group_mask           (0x00000001)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_ch1_mbist_hist_1p_fail_group(data)    (0x10000000&((data)<<28))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_ch1_mbist_hist_2p_fail_group(data)    (0x08000000&((data)<<27))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_rtnr_mcnr_tmv1_bist_fail_group(data)  (0x04000000&((data)<<26))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_rtnr_mcnr_tmv2_bist_fail_group(data)  (0x02000000&((data)<<25))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li4_bist_fail_group(data)          (0x01000000&((data)<<24))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li5_bist_fail_group(data)          (0x00800000&((data)<<23))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_pqdc1_bist_fail_group(data)           (0x00400000&((data)<<22))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_pqdc2_bist_fail_group(data)           (0x00200000&((data)<<21))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_pqc1_bist_fail_group(data)            (0x00100000&((data)<<20))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_pqc2_bist_fail_group(data)            (0x00080000&((data)<<19))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_winfo_bist_fail_group(data)    (0x00010000&((data)<<16))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_wdat_bist_fail_group(data)     (0x00008000&((data)<<15))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_rinfo_bist_fai_groupl(data)    (0x00004000&((data)<<14))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_rdat2_bist_fail_group(data)    (0x00002000&((data)<<13))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_dexcxl_rdat1_bist_fail_group(data)    (0x00001000&((data)<<12))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_i3ddma_bist_cap2_fail_group(data)     (0x00000800&((data)<<11))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_sdnr_ch1_bist_fail_group(data)        (0x00000400&((data)<<10))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_tr2to1_bist_fail_group(data)       (0x00000100&((data)<<8))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_hmc_bist_fail_group(data)          (0x00000080&((data)<<7))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_dma_wdat_bist_fail_group(data)     (0x00000040&((data)<<6))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_dma_rdat_bist_fail_group(data)     (0x00000020&((data)<<5))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li1_bist_fail_group(data)          (0x00000010&((data)<<4))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li2_bist_fail_group(data)          (0x00000008&((data)<<3))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_di_li3_bist_fail_group(data)          (0x00000004&((data)<<2))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_i3ddma_uzd_bist_fail_group(data)      (0x00000002&((data)<<1))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_i3ddma_bist_fail_group(data)          (0x00000001&(data))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_ch1_mbist_hist_1p_fail_group(data) ((0x10000000&(data))>>28)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_ch1_mbist_hist_2p_fail_group(data) ((0x08000000&(data))>>27)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_rtnr_mcnr_tmv1_bist_fail_group(data) ((0x04000000&(data))>>26)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_rtnr_mcnr_tmv2_bist_fail_group(data) ((0x02000000&(data))>>25)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_di_li4_bist_fail_group(data)      ((0x01000000&(data))>>24)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_di_li5_bist_fail_group(data)      ((0x00800000&(data))>>23)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_pqdc1_bist_fail_group(data)       ((0x00400000&(data))>>22)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_pqdc2_bist_fail_group(data)       ((0x00200000&(data))>>21)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_pqc1_bist_fail_group(data)        ((0x00100000&(data))>>20)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_pqc2_bist_fail_group(data)        ((0x00080000&(data))>>19)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_dexcxl_winfo_bist_fail_group(data) ((0x00010000&(data))>>16)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_dexcxl_wdat_bist_fail_group(data) ((0x00008000&(data))>>15)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_dexcxl_rinfo_bist_fai_groupl(data) ((0x00004000&(data))>>14)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_dexcxl_rdat2_bist_fail_group(data) ((0x00002000&(data))>>13)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_dexcxl_rdat1_bist_fail_group(data) ((0x00001000&(data))>>12)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_i3ddma_bist_cap2_fail_group(data) ((0x00000800&(data))>>11)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_sdnr_ch1_bist_fail_group(data)    ((0x00000400&(data))>>10)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_di_tr2to1_bist_fail_group(data)   ((0x00000100&(data))>>8)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_di_hmc_bist_fail_group(data)      ((0x00000080&(data))>>7)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_di_dma_wdat_bist_fail_group(data) ((0x00000040&(data))>>6)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_di_dma_rdat_bist_fail_group(data) ((0x00000020&(data))>>5)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_di_li1_bist_fail_group(data)      ((0x00000010&(data))>>4)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_di_li2_bist_fail_group(data)      ((0x00000008&(data))>>3)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_di_li3_bist_fail_group(data)      ((0x00000004&(data))>>2)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_i3ddma_uzd_bist_fail_group(data)  ((0x00000002&(data))>>1)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_get_i3ddma_bist_fail_group(data)      (0x00000001&(data))

#define  I_BIST_BISR_DISPI_DRF_MODE                                              0x18025F0C
#define  I_BIST_BISR_DISPI_DRF_MODE_reg_addr                                     "0xB8025F0C"
#define  I_BIST_BISR_DISPI_DRF_MODE_reg                                          0xB8025F0C
#define  I_BIST_BISR_DISPI_DRF_MODE_inst_addr                                    "0x0003"
#define  set_I_BIST_BISR_DISPI_DRF_MODE_reg(data)                                (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_MODE_reg)=data)
#define  get_I_BIST_BISR_DISPI_DRF_MODE_reg                                      (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_MODE_reg))
#define  I_BIST_BISR_DISPI_DRF_MODE_ch1_mbist_hist_1p_drf_mode_shift             (28)
#define  I_BIST_BISR_DISPI_DRF_MODE_ch1_mbist_hist_2p_drf_mode_shift             (27)
#define  I_BIST_BISR_DISPI_DRF_MODE_rtnr_mcnr_tmv1_drf_mode_shift                (26)
#define  I_BIST_BISR_DISPI_DRF_MODE_rtnr_mcnr_tmv2_drf_mode_shift                (25)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li4_drf_mode_shift                        (24)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li5_drf_mode_shift                        (23)
#define  I_BIST_BISR_DISPI_DRF_MODE_pqdc1_drf_mode_shift                         (22)
#define  I_BIST_BISR_DISPI_DRF_MODE_pqdc2_drf_mode_shift                         (21)
#define  I_BIST_BISR_DISPI_DRF_MODE_pqc1_drf_mode_shift                          (20)
#define  I_BIST_BISR_DISPI_DRF_MODE_pqc2_drf_mode_shift                          (19)
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_winfo_drf_mode_shift                  (16)
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_wdat_drf_mode_shift                   (15)
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_rinfo_drf_mode_shift                  (14)
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_rdat2_drf_mode_shift                  (13)
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_rdat1_drf_mode_shift                  (12)
#define  I_BIST_BISR_DISPI_DRF_MODE_i3ddma_drf_cap2_mode_shift                   (11)
#define  I_BIST_BISR_DISPI_DRF_MODE_sdnr_ch1_drf_mode_shift                      (10)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_tr2to1_drf_mode_shift                     (8)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_hmc_drf_mode_shift                        (7)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_dma_wdat_drf_mode_shift                   (6)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_dma_rdat_drf_mode_shift                   (5)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li1_drf_mode_shift                        (4)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li2_drf_mode_shift                        (3)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li3_drf_mode_shift                        (2)
#define  I_BIST_BISR_DISPI_DRF_MODE_i3ddma_uzd_drf_mode_shift                    (1)
#define  I_BIST_BISR_DISPI_DRF_MODE_i3ddma_drf_mode_shift                        (0)
#define  I_BIST_BISR_DISPI_DRF_MODE_ch1_mbist_hist_1p_drf_mode_mask              (0x10000000)
#define  I_BIST_BISR_DISPI_DRF_MODE_ch1_mbist_hist_2p_drf_mode_mask              (0x08000000)
#define  I_BIST_BISR_DISPI_DRF_MODE_rtnr_mcnr_tmv1_drf_mode_mask                 (0x04000000)
#define  I_BIST_BISR_DISPI_DRF_MODE_rtnr_mcnr_tmv2_drf_mode_mask                 (0x02000000)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li4_drf_mode_mask                         (0x01000000)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li5_drf_mode_mask                         (0x00800000)
#define  I_BIST_BISR_DISPI_DRF_MODE_pqdc1_drf_mode_mask                          (0x00400000)
#define  I_BIST_BISR_DISPI_DRF_MODE_pqdc2_drf_mode_mask                          (0x00200000)
#define  I_BIST_BISR_DISPI_DRF_MODE_pqc1_drf_mode_mask                           (0x00100000)
#define  I_BIST_BISR_DISPI_DRF_MODE_pqc2_drf_mode_mask                           (0x00080000)
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_winfo_drf_mode_mask                   (0x00010000)
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_wdat_drf_mode_mask                    (0x00008000)
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_rinfo_drf_mode_mask                   (0x00004000)
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_rdat2_drf_mode_mask                   (0x00002000)
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_rdat1_drf_mode_mask                   (0x00001000)
#define  I_BIST_BISR_DISPI_DRF_MODE_i3ddma_drf_cap2_mode_mask                    (0x00000800)
#define  I_BIST_BISR_DISPI_DRF_MODE_sdnr_ch1_drf_mode_mask                       (0x00000400)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_tr2to1_drf_mode_mask                      (0x00000100)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_hmc_drf_mode_mask                         (0x00000080)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_dma_wdat_drf_mode_mask                    (0x00000040)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_dma_rdat_drf_mode_mask                    (0x00000020)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li1_drf_mode_mask                         (0x00000010)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li2_drf_mode_mask                         (0x00000008)
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li3_drf_mode_mask                         (0x00000004)
#define  I_BIST_BISR_DISPI_DRF_MODE_i3ddma_uzd_drf_mode_mask                     (0x00000002)
#define  I_BIST_BISR_DISPI_DRF_MODE_i3ddma_drf_mode_mask                         (0x00000001)
#define  I_BIST_BISR_DISPI_DRF_MODE_ch1_mbist_hist_1p_drf_mode(data)             (0x10000000&((data)<<28))
#define  I_BIST_BISR_DISPI_DRF_MODE_ch1_mbist_hist_2p_drf_mode(data)             (0x08000000&((data)<<27))
#define  I_BIST_BISR_DISPI_DRF_MODE_rtnr_mcnr_tmv1_drf_mode(data)                (0x04000000&((data)<<26))
#define  I_BIST_BISR_DISPI_DRF_MODE_rtnr_mcnr_tmv2_drf_mode(data)                (0x02000000&((data)<<25))
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li4_drf_mode(data)                        (0x01000000&((data)<<24))
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li5_drf_mode(data)                        (0x00800000&((data)<<23))
#define  I_BIST_BISR_DISPI_DRF_MODE_pqdc1_drf_mode(data)                         (0x00400000&((data)<<22))
#define  I_BIST_BISR_DISPI_DRF_MODE_pqdc2_drf_mode(data)                         (0x00200000&((data)<<21))
#define  I_BIST_BISR_DISPI_DRF_MODE_pqc1_drf_mode(data)                          (0x00100000&((data)<<20))
#define  I_BIST_BISR_DISPI_DRF_MODE_pqc2_drf_mode(data)                          (0x00080000&((data)<<19))
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_winfo_drf_mode(data)                  (0x00010000&((data)<<16))
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_wdat_drf_mode(data)                   (0x00008000&((data)<<15))
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_rinfo_drf_mode(data)                  (0x00004000&((data)<<14))
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_rdat2_drf_mode(data)                  (0x00002000&((data)<<13))
#define  I_BIST_BISR_DISPI_DRF_MODE_dexcxl_rdat1_drf_mode(data)                  (0x00001000&((data)<<12))
#define  I_BIST_BISR_DISPI_DRF_MODE_i3ddma_drf_cap2_mode(data)                   (0x00000800&((data)<<11))
#define  I_BIST_BISR_DISPI_DRF_MODE_sdnr_ch1_drf_mode(data)                      (0x00000400&((data)<<10))
#define  I_BIST_BISR_DISPI_DRF_MODE_di_tr2to1_drf_mode(data)                     (0x00000100&((data)<<8))
#define  I_BIST_BISR_DISPI_DRF_MODE_di_hmc_drf_mode(data)                        (0x00000080&((data)<<7))
#define  I_BIST_BISR_DISPI_DRF_MODE_di_dma_wdat_drf_mode(data)                   (0x00000040&((data)<<6))
#define  I_BIST_BISR_DISPI_DRF_MODE_di_dma_rdat_drf_mode(data)                   (0x00000020&((data)<<5))
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li1_drf_mode(data)                        (0x00000010&((data)<<4))
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li2_drf_mode(data)                        (0x00000008&((data)<<3))
#define  I_BIST_BISR_DISPI_DRF_MODE_di_li3_drf_mode(data)                        (0x00000004&((data)<<2))
#define  I_BIST_BISR_DISPI_DRF_MODE_i3ddma_uzd_drf_mode(data)                    (0x00000002&((data)<<1))
#define  I_BIST_BISR_DISPI_DRF_MODE_i3ddma_drf_mode(data)                        (0x00000001&(data))
#define  I_BIST_BISR_DISPI_DRF_MODE_get_ch1_mbist_hist_1p_drf_mode(data)         ((0x10000000&(data))>>28)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_ch1_mbist_hist_2p_drf_mode(data)         ((0x08000000&(data))>>27)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_rtnr_mcnr_tmv1_drf_mode(data)            ((0x04000000&(data))>>26)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_rtnr_mcnr_tmv2_drf_mode(data)            ((0x02000000&(data))>>25)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_di_li4_drf_mode(data)                    ((0x01000000&(data))>>24)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_di_li5_drf_mode(data)                    ((0x00800000&(data))>>23)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_pqdc1_drf_mode(data)                     ((0x00400000&(data))>>22)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_pqdc2_drf_mode(data)                     ((0x00200000&(data))>>21)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_pqc1_drf_mode(data)                      ((0x00100000&(data))>>20)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_pqc2_drf_mode(data)                      ((0x00080000&(data))>>19)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_dexcxl_winfo_drf_mode(data)              ((0x00010000&(data))>>16)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_dexcxl_wdat_drf_mode(data)               ((0x00008000&(data))>>15)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_dexcxl_rinfo_drf_mode(data)              ((0x00004000&(data))>>14)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_dexcxl_rdat2_drf_mode(data)              ((0x00002000&(data))>>13)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_dexcxl_rdat1_drf_mode(data)              ((0x00001000&(data))>>12)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_i3ddma_drf_cap2_mode(data)               ((0x00000800&(data))>>11)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_sdnr_ch1_drf_mode(data)                  ((0x00000400&(data))>>10)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_di_tr2to1_drf_mode(data)                 ((0x00000100&(data))>>8)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_di_hmc_drf_mode(data)                    ((0x00000080&(data))>>7)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_di_dma_wdat_drf_mode(data)               ((0x00000040&(data))>>6)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_di_dma_rdat_drf_mode(data)               ((0x00000020&(data))>>5)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_di_li1_drf_mode(data)                    ((0x00000010&(data))>>4)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_di_li2_drf_mode(data)                    ((0x00000008&(data))>>3)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_di_li3_drf_mode(data)                    ((0x00000004&(data))>>2)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_i3ddma_uzd_drf_mode(data)                ((0x00000002&(data))>>1)
#define  I_BIST_BISR_DISPI_DRF_MODE_get_i3ddma_drf_mode(data)                    (0x00000001&(data))

#define  I_BIST_BISR_DISPI_DRF_RESUME                                            0x18025F10
#define  I_BIST_BISR_DISPI_DRF_RESUME_reg_addr                                   "0xB8025F10"
#define  I_BIST_BISR_DISPI_DRF_RESUME_reg                                        0xB8025F10
#define  I_BIST_BISR_DISPI_DRF_RESUME_inst_addr                                  "0x0004"
#define  set_I_BIST_BISR_DISPI_DRF_RESUME_reg(data)                              (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_RESUME_reg)=data)
#define  get_I_BIST_BISR_DISPI_DRF_RESUME_reg                                    (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_RESUME_reg))
#define  I_BIST_BISR_DISPI_DRF_RESUME_ch1_mbist_hist_1p_drf_resume_shift         (28)
#define  I_BIST_BISR_DISPI_DRF_RESUME_ch1_mbist_hist_2p_drf_resume_shift         (27)
#define  I_BIST_BISR_DISPI_DRF_RESUME_rtnr_mcnr_tmv1_drf_resume_shift            (26)
#define  I_BIST_BISR_DISPI_DRF_RESUME_rtnr_mcnr_tmv2_drf_resume_shift            (25)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li4_drf_resume_shift                    (24)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li5_drf_resume_shift                    (23)
#define  I_BIST_BISR_DISPI_DRF_RESUME_pqdc1_drf_resume_shift                     (22)
#define  I_BIST_BISR_DISPI_DRF_RESUME_pqdc2_drf_resume_shift                     (21)
#define  I_BIST_BISR_DISPI_DRF_RESUME_pqc1_drf_resume_shift                      (20)
#define  I_BIST_BISR_DISPI_DRF_RESUME_pqc2_drf_resume_shift                      (19)
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_winfo_drf_resume_shift              (16)
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_wdat_drf_resume_shift               (15)
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_rinfo_drf_resume_shift              (14)
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_rdat2_drf_resume_shift              (13)
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_rdat1_drf_resume_shift              (12)
#define  I_BIST_BISR_DISPI_DRF_RESUME_i3ddma_drf_cap2_resume_shift               (11)
#define  I_BIST_BISR_DISPI_DRF_RESUME_sdnr_ch1_drf_resume_shift                  (10)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_tr2to1_drf_resume_shift                 (8)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_hmc_drf_resume_shift                    (7)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_dma_wdat_drf_resume_shift               (6)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_dma_rdat_drf_resume_shift               (5)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li1_drf_resume_shift                    (4)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li2_drf_resume_shift                    (3)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li3_drf_resume_shift                    (2)
#define  I_BIST_BISR_DISPI_DRF_RESUME_i3ddma_uzd_drf_resume_shift                (1)
#define  I_BIST_BISR_DISPI_DRF_RESUME_i3ddma_drf_resume_shift                    (0)
#define  I_BIST_BISR_DISPI_DRF_RESUME_ch1_mbist_hist_1p_drf_resume_mask          (0x10000000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_ch1_mbist_hist_2p_drf_resume_mask          (0x08000000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_rtnr_mcnr_tmv1_drf_resume_mask             (0x04000000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_rtnr_mcnr_tmv2_drf_resume_mask             (0x02000000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li4_drf_resume_mask                     (0x01000000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li5_drf_resume_mask                     (0x00800000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_pqdc1_drf_resume_mask                      (0x00400000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_pqdc2_drf_resume_mask                      (0x00200000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_pqc1_drf_resume_mask                       (0x00100000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_pqc2_drf_resume_mask                       (0x00080000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_winfo_drf_resume_mask               (0x00010000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_wdat_drf_resume_mask                (0x00008000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_rinfo_drf_resume_mask               (0x00004000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_rdat2_drf_resume_mask               (0x00002000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_rdat1_drf_resume_mask               (0x00001000)
#define  I_BIST_BISR_DISPI_DRF_RESUME_i3ddma_drf_cap2_resume_mask                (0x00000800)
#define  I_BIST_BISR_DISPI_DRF_RESUME_sdnr_ch1_drf_resume_mask                   (0x00000400)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_tr2to1_drf_resume_mask                  (0x00000100)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_hmc_drf_resume_mask                     (0x00000080)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_dma_wdat_drf_resume_mask                (0x00000040)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_dma_rdat_drf_resume_mask                (0x00000020)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li1_drf_resume_mask                     (0x00000010)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li2_drf_resume_mask                     (0x00000008)
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li3_drf_resume_mask                     (0x00000004)
#define  I_BIST_BISR_DISPI_DRF_RESUME_i3ddma_uzd_drf_resume_mask                 (0x00000002)
#define  I_BIST_BISR_DISPI_DRF_RESUME_i3ddma_drf_resume_mask                     (0x00000001)
#define  I_BIST_BISR_DISPI_DRF_RESUME_ch1_mbist_hist_1p_drf_resume(data)         (0x10000000&((data)<<28))
#define  I_BIST_BISR_DISPI_DRF_RESUME_ch1_mbist_hist_2p_drf_resume(data)         (0x08000000&((data)<<27))
#define  I_BIST_BISR_DISPI_DRF_RESUME_rtnr_mcnr_tmv1_drf_resume(data)            (0x04000000&((data)<<26))
#define  I_BIST_BISR_DISPI_DRF_RESUME_rtnr_mcnr_tmv2_drf_resume(data)            (0x02000000&((data)<<25))
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li4_drf_resume(data)                    (0x01000000&((data)<<24))
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li5_drf_resume(data)                    (0x00800000&((data)<<23))
#define  I_BIST_BISR_DISPI_DRF_RESUME_pqdc1_drf_resume(data)                     (0x00400000&((data)<<22))
#define  I_BIST_BISR_DISPI_DRF_RESUME_pqdc2_drf_resume(data)                     (0x00200000&((data)<<21))
#define  I_BIST_BISR_DISPI_DRF_RESUME_pqc1_drf_resume(data)                      (0x00100000&((data)<<20))
#define  I_BIST_BISR_DISPI_DRF_RESUME_pqc2_drf_resume(data)                      (0x00080000&((data)<<19))
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_winfo_drf_resume(data)              (0x00010000&((data)<<16))
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_wdat_drf_resume(data)               (0x00008000&((data)<<15))
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_rinfo_drf_resume(data)              (0x00004000&((data)<<14))
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_rdat2_drf_resume(data)              (0x00002000&((data)<<13))
#define  I_BIST_BISR_DISPI_DRF_RESUME_dexcxl_rdat1_drf_resume(data)              (0x00001000&((data)<<12))
#define  I_BIST_BISR_DISPI_DRF_RESUME_i3ddma_drf_cap2_resume(data)               (0x00000800&((data)<<11))
#define  I_BIST_BISR_DISPI_DRF_RESUME_sdnr_ch1_drf_resume(data)                  (0x00000400&((data)<<10))
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_tr2to1_drf_resume(data)                 (0x00000100&((data)<<8))
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_hmc_drf_resume(data)                    (0x00000080&((data)<<7))
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_dma_wdat_drf_resume(data)               (0x00000040&((data)<<6))
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_dma_rdat_drf_resume(data)               (0x00000020&((data)<<5))
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li1_drf_resume(data)                    (0x00000010&((data)<<4))
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li2_drf_resume(data)                    (0x00000008&((data)<<3))
#define  I_BIST_BISR_DISPI_DRF_RESUME_di_li3_drf_resume(data)                    (0x00000004&((data)<<2))
#define  I_BIST_BISR_DISPI_DRF_RESUME_i3ddma_uzd_drf_resume(data)                (0x00000002&((data)<<1))
#define  I_BIST_BISR_DISPI_DRF_RESUME_i3ddma_drf_resume(data)                    (0x00000001&(data))
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_ch1_mbist_hist_1p_drf_resume(data)     ((0x10000000&(data))>>28)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_ch1_mbist_hist_2p_drf_resume(data)     ((0x08000000&(data))>>27)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_rtnr_mcnr_tmv1_drf_resume(data)        ((0x04000000&(data))>>26)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_rtnr_mcnr_tmv2_drf_resume(data)        ((0x02000000&(data))>>25)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_di_li4_drf_resume(data)                ((0x01000000&(data))>>24)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_di_li5_drf_resume(data)                ((0x00800000&(data))>>23)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_pqdc1_drf_resume(data)                 ((0x00400000&(data))>>22)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_pqdc2_drf_resume(data)                 ((0x00200000&(data))>>21)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_pqc1_drf_resume(data)                  ((0x00100000&(data))>>20)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_pqc2_drf_resume(data)                  ((0x00080000&(data))>>19)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_dexcxl_winfo_drf_resume(data)          ((0x00010000&(data))>>16)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_dexcxl_wdat_drf_resume(data)           ((0x00008000&(data))>>15)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_dexcxl_rinfo_drf_resume(data)          ((0x00004000&(data))>>14)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_dexcxl_rdat2_drf_resume(data)          ((0x00002000&(data))>>13)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_dexcxl_rdat1_drf_resume(data)          ((0x00001000&(data))>>12)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_i3ddma_drf_cap2_resume(data)           ((0x00000800&(data))>>11)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_sdnr_ch1_drf_resume(data)              ((0x00000400&(data))>>10)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_di_tr2to1_drf_resume(data)             ((0x00000100&(data))>>8)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_di_hmc_drf_resume(data)                ((0x00000080&(data))>>7)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_di_dma_wdat_drf_resume(data)           ((0x00000040&(data))>>6)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_di_dma_rdat_drf_resume(data)           ((0x00000020&(data))>>5)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_di_li1_drf_resume(data)                ((0x00000010&(data))>>4)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_di_li2_drf_resume(data)                ((0x00000008&(data))>>3)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_di_li3_drf_resume(data)                ((0x00000004&(data))>>2)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_i3ddma_uzd_drf_resume(data)            ((0x00000002&(data))>>1)
#define  I_BIST_BISR_DISPI_DRF_RESUME_get_i3ddma_drf_resume(data)                (0x00000001&(data))

#define  I_BIST_BISR_DISPI_DRF_DONE                                              0x18025F14
#define  I_BIST_BISR_DISPI_DRF_DONE_reg_addr                                     "0xB8025F14"
#define  I_BIST_BISR_DISPI_DRF_DONE_reg                                          0xB8025F14
#define  I_BIST_BISR_DISPI_DRF_DONE_inst_addr                                    "0x0005"
#define  set_I_BIST_BISR_DISPI_DRF_DONE_reg(data)                                (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_DONE_reg)=data)
#define  get_I_BIST_BISR_DISPI_DRF_DONE_reg                                      (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_DONE_reg))
#define  I_BIST_BISR_DISPI_DRF_DONE_ch1_mbist_hist_1p_drf_done_shift             (28)
#define  I_BIST_BISR_DISPI_DRF_DONE_ch1_mbist_hist_2p_drf_done_shift             (27)
#define  I_BIST_BISR_DISPI_DRF_DONE_rtnr_mcnr_tmv1_drf_done_shift                (26)
#define  I_BIST_BISR_DISPI_DRF_DONE_rtnr_mcnr_tmv2_drf_done_shift                (25)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li4_drf_done_shift                        (24)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li5_drf_done_shift                        (23)
#define  I_BIST_BISR_DISPI_DRF_DONE_pqdc1_drf_done_shift                         (22)
#define  I_BIST_BISR_DISPI_DRF_DONE_pqdc2_drf_done_shift                         (21)
#define  I_BIST_BISR_DISPI_DRF_DONE_pqc1_drf_done_shift                          (20)
#define  I_BIST_BISR_DISPI_DRF_DONE_pqc2_drf_done_shift                          (19)
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_winfo_drf_done_shift                  (16)
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_wdat_drf_done_shift                   (15)
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_rinfo_drf_done_shift                  (14)
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_rdat2_drf_done_shift                  (13)
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_rdat1_drf_done_shift                  (12)
#define  I_BIST_BISR_DISPI_DRF_DONE_i3ddma_drf_cap2_done_shift                   (11)
#define  I_BIST_BISR_DISPI_DRF_DONE_sdnr_ch1_drf_done_shift                      (10)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_tr2to1_drf_done_shift                     (8)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_hmc_drf_done_shift                        (7)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_dma_wdat_drf_done_shift                   (6)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_dma_rdat_drf_done_shift                   (5)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li1_drf_done_shift                        (4)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li2_drf_done_shift                        (3)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li3_drf_done_shift                        (2)
#define  I_BIST_BISR_DISPI_DRF_DONE_i3ddma_uzd_drf_done_shift                    (1)
#define  I_BIST_BISR_DISPI_DRF_DONE_i3ddma_drf_done_shift                        (0)
#define  I_BIST_BISR_DISPI_DRF_DONE_ch1_mbist_hist_1p_drf_done_mask              (0x10000000)
#define  I_BIST_BISR_DISPI_DRF_DONE_ch1_mbist_hist_2p_drf_done_mask              (0x08000000)
#define  I_BIST_BISR_DISPI_DRF_DONE_rtnr_mcnr_tmv1_drf_done_mask                 (0x04000000)
#define  I_BIST_BISR_DISPI_DRF_DONE_rtnr_mcnr_tmv2_drf_done_mask                 (0x02000000)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li4_drf_done_mask                         (0x01000000)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li5_drf_done_mask                         (0x00800000)
#define  I_BIST_BISR_DISPI_DRF_DONE_pqdc1_drf_done_mask                          (0x00400000)
#define  I_BIST_BISR_DISPI_DRF_DONE_pqdc2_drf_done_mask                          (0x00200000)
#define  I_BIST_BISR_DISPI_DRF_DONE_pqc1_drf_done_mask                           (0x00100000)
#define  I_BIST_BISR_DISPI_DRF_DONE_pqc2_drf_done_mask                           (0x00080000)
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_winfo_drf_done_mask                   (0x00010000)
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_wdat_drf_done_mask                    (0x00008000)
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_rinfo_drf_done_mask                   (0x00004000)
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_rdat2_drf_done_mask                   (0x00002000)
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_rdat1_drf_done_mask                   (0x00001000)
#define  I_BIST_BISR_DISPI_DRF_DONE_i3ddma_drf_cap2_done_mask                    (0x00000800)
#define  I_BIST_BISR_DISPI_DRF_DONE_sdnr_ch1_drf_done_mask                       (0x00000400)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_tr2to1_drf_done_mask                      (0x00000100)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_hmc_drf_done_mask                         (0x00000080)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_dma_wdat_drf_done_mask                    (0x00000040)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_dma_rdat_drf_done_mask                    (0x00000020)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li1_drf_done_mask                         (0x00000010)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li2_drf_done_mask                         (0x00000008)
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li3_drf_done_mask                         (0x00000004)
#define  I_BIST_BISR_DISPI_DRF_DONE_i3ddma_uzd_drf_done_mask                     (0x00000002)
#define  I_BIST_BISR_DISPI_DRF_DONE_i3ddma_drf_done_mask                         (0x00000001)
#define  I_BIST_BISR_DISPI_DRF_DONE_ch1_mbist_hist_1p_drf_done(data)             (0x10000000&((data)<<28))
#define  I_BIST_BISR_DISPI_DRF_DONE_ch1_mbist_hist_2p_drf_done(data)             (0x08000000&((data)<<27))
#define  I_BIST_BISR_DISPI_DRF_DONE_rtnr_mcnr_tmv1_drf_done(data)                (0x04000000&((data)<<26))
#define  I_BIST_BISR_DISPI_DRF_DONE_rtnr_mcnr_tmv2_drf_done(data)                (0x02000000&((data)<<25))
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li4_drf_done(data)                        (0x01000000&((data)<<24))
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li5_drf_done(data)                        (0x00800000&((data)<<23))
#define  I_BIST_BISR_DISPI_DRF_DONE_pqdc1_drf_done(data)                         (0x00400000&((data)<<22))
#define  I_BIST_BISR_DISPI_DRF_DONE_pqdc2_drf_done(data)                         (0x00200000&((data)<<21))
#define  I_BIST_BISR_DISPI_DRF_DONE_pqc1_drf_done(data)                          (0x00100000&((data)<<20))
#define  I_BIST_BISR_DISPI_DRF_DONE_pqc2_drf_done(data)                          (0x00080000&((data)<<19))
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_winfo_drf_done(data)                  (0x00010000&((data)<<16))
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_wdat_drf_done(data)                   (0x00008000&((data)<<15))
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_rinfo_drf_done(data)                  (0x00004000&((data)<<14))
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_rdat2_drf_done(data)                  (0x00002000&((data)<<13))
#define  I_BIST_BISR_DISPI_DRF_DONE_dexcxl_rdat1_drf_done(data)                  (0x00001000&((data)<<12))
#define  I_BIST_BISR_DISPI_DRF_DONE_i3ddma_drf_cap2_done(data)                   (0x00000800&((data)<<11))
#define  I_BIST_BISR_DISPI_DRF_DONE_sdnr_ch1_drf_done(data)                      (0x00000400&((data)<<10))
#define  I_BIST_BISR_DISPI_DRF_DONE_di_tr2to1_drf_done(data)                     (0x00000100&((data)<<8))
#define  I_BIST_BISR_DISPI_DRF_DONE_di_hmc_drf_done(data)                        (0x00000080&((data)<<7))
#define  I_BIST_BISR_DISPI_DRF_DONE_di_dma_wdat_drf_done(data)                   (0x00000040&((data)<<6))
#define  I_BIST_BISR_DISPI_DRF_DONE_di_dma_rdat_drf_done(data)                   (0x00000020&((data)<<5))
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li1_drf_done(data)                        (0x00000010&((data)<<4))
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li2_drf_done(data)                        (0x00000008&((data)<<3))
#define  I_BIST_BISR_DISPI_DRF_DONE_di_li3_drf_done(data)                        (0x00000004&((data)<<2))
#define  I_BIST_BISR_DISPI_DRF_DONE_i3ddma_uzd_drf_done(data)                    (0x00000002&((data)<<1))
#define  I_BIST_BISR_DISPI_DRF_DONE_i3ddma_drf_done(data)                        (0x00000001&(data))
#define  I_BIST_BISR_DISPI_DRF_DONE_get_ch1_mbist_hist_1p_drf_done(data)         ((0x10000000&(data))>>28)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_ch1_mbist_hist_2p_drf_done(data)         ((0x08000000&(data))>>27)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_rtnr_mcnr_tmv1_drf_done(data)            ((0x04000000&(data))>>26)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_rtnr_mcnr_tmv2_drf_done(data)            ((0x02000000&(data))>>25)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_di_li4_drf_done(data)                    ((0x01000000&(data))>>24)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_di_li5_drf_done(data)                    ((0x00800000&(data))>>23)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_pqdc1_drf_done(data)                     ((0x00400000&(data))>>22)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_pqdc2_drf_done(data)                     ((0x00200000&(data))>>21)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_pqc1_drf_done(data)                      ((0x00100000&(data))>>20)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_pqc2_drf_done(data)                      ((0x00080000&(data))>>19)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_dexcxl_winfo_drf_done(data)              ((0x00010000&(data))>>16)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_dexcxl_wdat_drf_done(data)               ((0x00008000&(data))>>15)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_dexcxl_rinfo_drf_done(data)              ((0x00004000&(data))>>14)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_dexcxl_rdat2_drf_done(data)              ((0x00002000&(data))>>13)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_dexcxl_rdat1_drf_done(data)              ((0x00001000&(data))>>12)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_i3ddma_drf_cap2_done(data)               ((0x00000800&(data))>>11)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_sdnr_ch1_drf_done(data)                  ((0x00000400&(data))>>10)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_di_tr2to1_drf_done(data)                 ((0x00000100&(data))>>8)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_di_hmc_drf_done(data)                    ((0x00000080&(data))>>7)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_di_dma_wdat_drf_done(data)               ((0x00000040&(data))>>6)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_di_dma_rdat_drf_done(data)               ((0x00000020&(data))>>5)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_di_li1_drf_done(data)                    ((0x00000010&(data))>>4)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_di_li2_drf_done(data)                    ((0x00000008&(data))>>3)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_di_li3_drf_done(data)                    ((0x00000004&(data))>>2)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_i3ddma_uzd_drf_done(data)                ((0x00000002&(data))>>1)
#define  I_BIST_BISR_DISPI_DRF_DONE_get_i3ddma_drf_done(data)                    (0x00000001&(data))

#define  I_BIST_BISR_DISPI_DRF_PAUSE                                             0x18025F18
#define  I_BIST_BISR_DISPI_DRF_PAUSE_reg_addr                                    "0xB8025F18"
#define  I_BIST_BISR_DISPI_DRF_PAUSE_reg                                         0xB8025F18
#define  I_BIST_BISR_DISPI_DRF_PAUSE_inst_addr                                   "0x0006"
#define  set_I_BIST_BISR_DISPI_DRF_PAUSE_reg(data)                               (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_PAUSE_reg)=data)
#define  get_I_BIST_BISR_DISPI_DRF_PAUSE_reg                                     (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_PAUSE_reg))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_ch1_mbist_hist_1p_drf_pause_shift           (28)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_ch1_mbist_hist_2p_drf_pause_shift           (27)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_rtnr_mcnr_tmv1_drf_pause_shift              (26)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_rtnr_mcnr_tmv2_drf_pause_shift              (25)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li4_drf_pause_shift                      (24)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li5_drf_pause_shift                      (23)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_pqdc1_drf_pause_shift                       (22)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_pqdc2_drf_pause_shift                       (21)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_pqc1_drf_pause_shift                        (20)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_pqc2_drf_pause_shift                        (19)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_winfo_drf_pause_shift                (16)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_wdat_drf_pause_shift                 (15)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_rinfo_drf_pause_shift                (14)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_rdat2_drf_pause_shift                (13)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_rdat1_drf_pause_shift                (12)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_i3ddma_drf_cap2_pause_shift                 (11)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_sdnr_ch1_drf_pause_shift                    (10)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_tr2to1_drf_pause_shift                   (8)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_hmc_drf_pause_shift                      (7)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_dma_wdat_drf_pause_shift                 (6)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_dma_rdat_drf_pause_shift                 (5)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li1_drf_pause_shift                      (4)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li2_drf_pause_shift                      (3)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li3_drf_pause_shift                      (2)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_i3ddma_uzd_drf_pause_shift                  (1)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_i3ddma_drf_pause_shift                      (0)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_ch1_mbist_hist_1p_drf_pause_mask            (0x10000000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_ch1_mbist_hist_2p_drf_pause_mask            (0x08000000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_rtnr_mcnr_tmv1_drf_pause_mask               (0x04000000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_rtnr_mcnr_tmv2_drf_pause_mask               (0x02000000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li4_drf_pause_mask                       (0x01000000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li5_drf_pause_mask                       (0x00800000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_pqdc1_drf_pause_mask                        (0x00400000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_pqdc2_drf_pause_mask                        (0x00200000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_pqc1_drf_pause_mask                         (0x00100000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_pqc2_drf_pause_mask                         (0x00080000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_winfo_drf_pause_mask                 (0x00010000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_wdat_drf_pause_mask                  (0x00008000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_rinfo_drf_pause_mask                 (0x00004000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_rdat2_drf_pause_mask                 (0x00002000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_rdat1_drf_pause_mask                 (0x00001000)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_i3ddma_drf_cap2_pause_mask                  (0x00000800)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_sdnr_ch1_drf_pause_mask                     (0x00000400)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_tr2to1_drf_pause_mask                    (0x00000100)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_hmc_drf_pause_mask                       (0x00000080)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_dma_wdat_drf_pause_mask                  (0x00000040)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_dma_rdat_drf_pause_mask                  (0x00000020)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li1_drf_pause_mask                       (0x00000010)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li2_drf_pause_mask                       (0x00000008)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li3_drf_pause_mask                       (0x00000004)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_i3ddma_uzd_drf_pause_mask                   (0x00000002)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_i3ddma_drf_pause_mask                       (0x00000001)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_ch1_mbist_hist_1p_drf_pause(data)           (0x10000000&((data)<<28))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_ch1_mbist_hist_2p_drf_pause(data)           (0x08000000&((data)<<27))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_rtnr_mcnr_tmv1_drf_pause(data)              (0x04000000&((data)<<26))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_rtnr_mcnr_tmv2_drf_pause(data)              (0x02000000&((data)<<25))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li4_drf_pause(data)                      (0x01000000&((data)<<24))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li5_drf_pause(data)                      (0x00800000&((data)<<23))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_pqdc1_drf_pause(data)                       (0x00400000&((data)<<22))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_pqdc2_drf_pause(data)                       (0x00200000&((data)<<21))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_pqc1_drf_pause(data)                        (0x00100000&((data)<<20))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_pqc2_drf_pause(data)                        (0x00080000&((data)<<19))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_winfo_drf_pause(data)                (0x00010000&((data)<<16))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_wdat_drf_pause(data)                 (0x00008000&((data)<<15))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_rinfo_drf_pause(data)                (0x00004000&((data)<<14))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_rdat2_drf_pause(data)                (0x00002000&((data)<<13))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_dexcxl_rdat1_drf_pause(data)                (0x00001000&((data)<<12))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_i3ddma_drf_cap2_pause(data)                 (0x00000800&((data)<<11))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_sdnr_ch1_drf_pause(data)                    (0x00000400&((data)<<10))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_tr2to1_drf_pause(data)                   (0x00000100&((data)<<8))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_hmc_drf_pause(data)                      (0x00000080&((data)<<7))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_dma_wdat_drf_pause(data)                 (0x00000040&((data)<<6))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_dma_rdat_drf_pause(data)                 (0x00000020&((data)<<5))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li1_drf_pause(data)                      (0x00000010&((data)<<4))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li2_drf_pause(data)                      (0x00000008&((data)<<3))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_di_li3_drf_pause(data)                      (0x00000004&((data)<<2))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_i3ddma_uzd_drf_pause(data)                  (0x00000002&((data)<<1))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_i3ddma_drf_pause(data)                      (0x00000001&(data))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_ch1_mbist_hist_1p_drf_pause(data)       ((0x10000000&(data))>>28)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_ch1_mbist_hist_2p_drf_pause(data)       ((0x08000000&(data))>>27)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_rtnr_mcnr_tmv1_drf_pause(data)          ((0x04000000&(data))>>26)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_rtnr_mcnr_tmv2_drf_pause(data)          ((0x02000000&(data))>>25)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_di_li4_drf_pause(data)                  ((0x01000000&(data))>>24)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_di_li5_drf_pause(data)                  ((0x00800000&(data))>>23)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_pqdc1_drf_pause(data)                   ((0x00400000&(data))>>22)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_pqdc2_drf_pause(data)                   ((0x00200000&(data))>>21)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_pqc1_drf_pause(data)                    ((0x00100000&(data))>>20)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_pqc2_drf_pause(data)                    ((0x00080000&(data))>>19)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_dexcxl_winfo_drf_pause(data)            ((0x00010000&(data))>>16)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_dexcxl_wdat_drf_pause(data)             ((0x00008000&(data))>>15)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_dexcxl_rinfo_drf_pause(data)            ((0x00004000&(data))>>14)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_dexcxl_rdat2_drf_pause(data)            ((0x00002000&(data))>>13)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_dexcxl_rdat1_drf_pause(data)            ((0x00001000&(data))>>12)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_i3ddma_drf_cap2_pause(data)             ((0x00000800&(data))>>11)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_sdnr_ch1_drf_pause(data)                ((0x00000400&(data))>>10)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_di_tr2to1_drf_pause(data)               ((0x00000100&(data))>>8)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_di_hmc_drf_pause(data)                  ((0x00000080&(data))>>7)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_di_dma_wdat_drf_pause(data)             ((0x00000040&(data))>>6)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_di_dma_rdat_drf_pause(data)             ((0x00000020&(data))>>5)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_di_li1_drf_pause(data)                  ((0x00000010&(data))>>4)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_di_li2_drf_pause(data)                  ((0x00000008&(data))>>3)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_di_li3_drf_pause(data)                  ((0x00000004&(data))>>2)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_i3ddma_uzd_drf_pause(data)              ((0x00000002&(data))>>1)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_get_i3ddma_drf_pause(data)                  (0x00000001&(data))

#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP                                        0x18025F1C
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_reg_addr                               "0xB8025F1C"
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_reg                                    0xB8025F1C
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_inst_addr                              "0x0007"
#define  set_I_BIST_BISR_DISPI_DRF_FAIL_GROUP_reg(data)                          (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_FAIL_GROUP_reg)=data)
#define  get_I_BIST_BISR_DISPI_DRF_FAIL_GROUP_reg                                (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_FAIL_GROUP_reg))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_ch1_mbist_hist_1p_drf_fail_group_shift (28)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_ch1_mbist_hist_2p_drf_fail_group_shift (27)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_rtnr_mcnr_tmv1_drf_fail_group_shift    (26)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_rtnr_mcnr_tmv2_drf_fail_group_shift    (25)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li4_drf_fail_group_shift            (24)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li5_drf_fail_group_shift            (23)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_pqdc1_drf_fail_group_shift             (22)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_pqdc2_drf_fail_group_shift             (21)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_pqc1_drf_fail_group_shift              (20)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_pqc2_drf_fail_group_shift              (19)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_winfo_drf_fail_group_shift      (16)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_wdat_drf_fail_group_shift       (15)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_rinfo_drf_fail_group_shift      (14)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_rdat2_drf_fail_group_shift      (13)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_rdat1_drf_fail_group_shift      (12)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_i3ddma_drf_cap2_fail_group_shift       (11)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_sdnr_ch1_drf_fail_group_shift          (10)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_tr2to1_drf_fail_group_shift         (8)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_hmc_drf_fail_group_shift            (7)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_dma_wdat_drf_fail_group_shift       (6)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_dma_rdat_drf_fail_group_shift       (5)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li1_drf_fail_group_shift            (4)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li2_drf_fail_group_shift            (3)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li3_drf_fail_group_shift            (2)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_i3ddma_uzd_drf_fail_group_shift        (1)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_i3ddma_drf_fail_group_shift            (0)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_ch1_mbist_hist_1p_drf_fail_group_mask  (0x10000000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_ch1_mbist_hist_2p_drf_fail_group_mask  (0x08000000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_rtnr_mcnr_tmv1_drf_fail_group_mask     (0x04000000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_rtnr_mcnr_tmv2_drf_fail_group_mask     (0x02000000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li4_drf_fail_group_mask             (0x01000000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li5_drf_fail_group_mask             (0x00800000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_pqdc1_drf_fail_group_mask              (0x00400000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_pqdc2_drf_fail_group_mask              (0x00200000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_pqc1_drf_fail_group_mask               (0x00100000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_pqc2_drf_fail_group_mask               (0x00080000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_winfo_drf_fail_group_mask       (0x00010000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_wdat_drf_fail_group_mask        (0x00008000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_rinfo_drf_fail_group_mask       (0x00004000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_rdat2_drf_fail_group_mask       (0x00002000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_rdat1_drf_fail_group_mask       (0x00001000)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_i3ddma_drf_cap2_fail_group_mask        (0x00000800)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_sdnr_ch1_drf_fail_group_mask           (0x00000400)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_tr2to1_drf_fail_group_mask          (0x00000100)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_hmc_drf_fail_group_mask             (0x00000080)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_dma_wdat_drf_fail_group_mask        (0x00000040)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_dma_rdat_drf_fail_group_mask        (0x00000020)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li1_drf_fail_group_mask             (0x00000010)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li2_drf_fail_group_mask             (0x00000008)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li3_drf_fail_group_mask             (0x00000004)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_i3ddma_uzd_drf_fail_group_mask         (0x00000002)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_i3ddma_drf_fail_group_mask             (0x00000001)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_ch1_mbist_hist_1p_drf_fail_group(data) (0x10000000&((data)<<28))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_ch1_mbist_hist_2p_drf_fail_group(data) (0x08000000&((data)<<27))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_rtnr_mcnr_tmv1_drf_fail_group(data)    (0x04000000&((data)<<26))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_rtnr_mcnr_tmv2_drf_fail_group(data)    (0x02000000&((data)<<25))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li4_drf_fail_group(data)            (0x01000000&((data)<<24))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li5_drf_fail_group(data)            (0x00800000&((data)<<23))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_pqdc1_drf_fail_group(data)             (0x00400000&((data)<<22))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_pqdc2_drf_fail_group(data)             (0x00200000&((data)<<21))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_pqc1_drf_fail_group(data)              (0x00100000&((data)<<20))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_pqc2_drf_fail_group(data)              (0x00080000&((data)<<19))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_winfo_drf_fail_group(data)      (0x00010000&((data)<<16))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_wdat_drf_fail_group(data)       (0x00008000&((data)<<15))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_rinfo_drf_fail_group(data)      (0x00004000&((data)<<14))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_rdat2_drf_fail_group(data)      (0x00002000&((data)<<13))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_dexcxl_rdat1_drf_fail_group(data)      (0x00001000&((data)<<12))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_i3ddma_drf_cap2_fail_group(data)       (0x00000800&((data)<<11))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_sdnr_ch1_drf_fail_group(data)          (0x00000400&((data)<<10))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_tr2to1_drf_fail_group(data)         (0x00000100&((data)<<8))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_hmc_drf_fail_group(data)            (0x00000080&((data)<<7))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_dma_wdat_drf_fail_group(data)       (0x00000040&((data)<<6))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_dma_rdat_drf_fail_group(data)       (0x00000020&((data)<<5))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li1_drf_fail_group(data)            (0x00000010&((data)<<4))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li2_drf_fail_group(data)            (0x00000008&((data)<<3))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_di_li3_drf_fail_group(data)            (0x00000004&((data)<<2))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_i3ddma_uzd_drf_fail_group(data)        (0x00000002&((data)<<1))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_i3ddma_drf_fail_group(data)            (0x00000001&(data))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_ch1_mbist_hist_1p_drf_fail_group(data) ((0x10000000&(data))>>28)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_ch1_mbist_hist_2p_drf_fail_group(data) ((0x08000000&(data))>>27)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_rtnr_mcnr_tmv1_drf_fail_group(data) ((0x04000000&(data))>>26)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_rtnr_mcnr_tmv2_drf_fail_group(data) ((0x02000000&(data))>>25)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_di_li4_drf_fail_group(data)        ((0x01000000&(data))>>24)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_di_li5_drf_fail_group(data)        ((0x00800000&(data))>>23)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_pqdc1_drf_fail_group(data)         ((0x00400000&(data))>>22)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_pqdc2_drf_fail_group(data)         ((0x00200000&(data))>>21)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_pqc1_drf_fail_group(data)          ((0x00100000&(data))>>20)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_pqc2_drf_fail_group(data)          ((0x00080000&(data))>>19)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_dexcxl_winfo_drf_fail_group(data)  ((0x00010000&(data))>>16)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_dexcxl_wdat_drf_fail_group(data)   ((0x00008000&(data))>>15)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_dexcxl_rinfo_drf_fail_group(data)  ((0x00004000&(data))>>14)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_dexcxl_rdat2_drf_fail_group(data)  ((0x00002000&(data))>>13)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_dexcxl_rdat1_drf_fail_group(data)  ((0x00001000&(data))>>12)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_i3ddma_drf_cap2_fail_group(data)   ((0x00000800&(data))>>11)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_sdnr_ch1_drf_fail_group(data)      ((0x00000400&(data))>>10)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_di_tr2to1_drf_fail_group(data)     ((0x00000100&(data))>>8)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_di_hmc_drf_fail_group(data)        ((0x00000080&(data))>>7)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_di_dma_wdat_drf_fail_group(data)   ((0x00000040&(data))>>6)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_di_dma_rdat_drf_fail_group(data)   ((0x00000020&(data))>>5)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_di_li1_drf_fail_group(data)        ((0x00000010&(data))>>4)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_di_li2_drf_fail_group(data)        ((0x00000008&(data))>>3)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_di_li3_drf_fail_group(data)        ((0x00000004&(data))>>2)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_i3ddma_uzd_drf_fail_group(data)    ((0x00000002&(data))>>1)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_get_i3ddma_drf_fail_group(data)        (0x00000001&(data))

#define  I_BIST_BISR_DISPI_BISR_SECOND_RUN_EN                                    0x18025F20
#define  I_BIST_BISR_DISPI_BISR_SECOND_RUN_EN_reg_addr                           "0xB8025F20"
#define  I_BIST_BISR_DISPI_BISR_SECOND_RUN_EN_reg                                0xB8025F20
#define  I_BIST_BISR_DISPI_BISR_SECOND_RUN_EN_inst_addr                          "0x0008"
#define  set_I_BIST_BISR_DISPI_BISR_SECOND_RUN_EN_reg(data)                      (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_SECOND_RUN_EN_reg)=data)
#define  get_I_BIST_BISR_DISPI_BISR_SECOND_RUN_EN_reg                            (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_SECOND_RUN_EN_reg))
#define  I_BIST_BISR_DISPI_BISR_SECOND_RUN_EN_spnr_bisr_second_run_en_shift      (0)
#define  I_BIST_BISR_DISPI_BISR_SECOND_RUN_EN_spnr_bisr_second_run_en_mask       (0x00000001)
#define  I_BIST_BISR_DISPI_BISR_SECOND_RUN_EN_spnr_bisr_second_run_en(data)      (0x00000001&(data))
#define  I_BIST_BISR_DISPI_BISR_SECOND_RUN_EN_get_spnr_bisr_second_run_en(data)  (0x00000001&(data))

#define  I_BIST_BISR_DISPI_BISR_FAIL_GROUP                                       0x18025F24
#define  I_BIST_BISR_DISPI_BISR_FAIL_GROUP_reg_addr                              "0xB8025F24"
#define  I_BIST_BISR_DISPI_BISR_FAIL_GROUP_reg                                   0xB8025F24
#define  I_BIST_BISR_DISPI_BISR_FAIL_GROUP_inst_addr                             "0x0009"
#define  set_I_BIST_BISR_DISPI_BISR_FAIL_GROUP_reg(data)                         (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_FAIL_GROUP_reg)=data)
#define  get_I_BIST_BISR_DISPI_BISR_FAIL_GROUP_reg                               (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_FAIL_GROUP_reg))
#define  I_BIST_BISR_DISPI_BISR_FAIL_GROUP_spnr_bisr_fail_group_shift            (0)
#define  I_BIST_BISR_DISPI_BISR_FAIL_GROUP_spnr_bisr_fail_group_mask             (0x00000001)
#define  I_BIST_BISR_DISPI_BISR_FAIL_GROUP_spnr_bisr_fail_group(data)            (0x00000001&(data))
#define  I_BIST_BISR_DISPI_BISR_FAIL_GROUP_get_spnr_bisr_fail_group(data)        (0x00000001&(data))

#define  I_BIST_BISR_DISPI_BISR_DRF_MODE                                         0x18025F28
#define  I_BIST_BISR_DISPI_BISR_DRF_MODE_reg_addr                                "0xB8025F28"
#define  I_BIST_BISR_DISPI_BISR_DRF_MODE_reg                                     0xB8025F28
#define  I_BIST_BISR_DISPI_BISR_DRF_MODE_inst_addr                               "0x000A"
#define  set_I_BIST_BISR_DISPI_BISR_DRF_MODE_reg(data)                           (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_DRF_MODE_reg)=data)
#define  get_I_BIST_BISR_DISPI_BISR_DRF_MODE_reg                                 (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_DRF_MODE_reg))
#define  I_BIST_BISR_DISPI_BISR_DRF_MODE_spnr_bisr_drf_mode_shift                (0)
#define  I_BIST_BISR_DISPI_BISR_DRF_MODE_spnr_bisr_drf_mode_mask                 (0x00000001)
#define  I_BIST_BISR_DISPI_BISR_DRF_MODE_spnr_bisr_drf_mode(data)                (0x00000001&(data))
#define  I_BIST_BISR_DISPI_BISR_DRF_MODE_get_spnr_bisr_drf_mode(data)            (0x00000001&(data))

#define  I_BIST_BISR_DISPI_BISR_DRF_RESUME                                       0x18025F2C
#define  I_BIST_BISR_DISPI_BISR_DRF_RESUME_reg_addr                              "0xB8025F2C"
#define  I_BIST_BISR_DISPI_BISR_DRF_RESUME_reg                                   0xB8025F2C
#define  I_BIST_BISR_DISPI_BISR_DRF_RESUME_inst_addr                             "0x000B"
#define  set_I_BIST_BISR_DISPI_BISR_DRF_RESUME_reg(data)                         (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_DRF_RESUME_reg)=data)
#define  get_I_BIST_BISR_DISPI_BISR_DRF_RESUME_reg                               (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_DRF_RESUME_reg))
#define  I_BIST_BISR_DISPI_BISR_DRF_RESUME_spnr_bisr_drf_resume_shift            (0)
#define  I_BIST_BISR_DISPI_BISR_DRF_RESUME_spnr_bisr_drf_resume_mask             (0x00000001)
#define  I_BIST_BISR_DISPI_BISR_DRF_RESUME_spnr_bisr_drf_resume(data)            (0x00000001&(data))
#define  I_BIST_BISR_DISPI_BISR_DRF_RESUME_get_spnr_bisr_drf_resume(data)        (0x00000001&(data))

#define  I_BIST_BISR_DISPI_BISR_DRF_DONE                                         0x18025F30
#define  I_BIST_BISR_DISPI_BISR_DRF_DONE_reg_addr                                "0xB8025F30"
#define  I_BIST_BISR_DISPI_BISR_DRF_DONE_reg                                     0xB8025F30
#define  I_BIST_BISR_DISPI_BISR_DRF_DONE_inst_addr                               "0x000C"
#define  set_I_BIST_BISR_DISPI_BISR_DRF_DONE_reg(data)                           (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_DRF_DONE_reg)=data)
#define  get_I_BIST_BISR_DISPI_BISR_DRF_DONE_reg                                 (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_DRF_DONE_reg))
#define  I_BIST_BISR_DISPI_BISR_DRF_DONE_spnr_bisr_drf_done_shift                (0)
#define  I_BIST_BISR_DISPI_BISR_DRF_DONE_spnr_bisr_drf_done_mask                 (0x00000001)
#define  I_BIST_BISR_DISPI_BISR_DRF_DONE_spnr_bisr_drf_done(data)                (0x00000001&(data))
#define  I_BIST_BISR_DISPI_BISR_DRF_DONE_get_spnr_bisr_drf_done(data)            (0x00000001&(data))

#define  I_BIST_BISR_DISPI_BISR_DRF_PAUSE                                        0x18025F34
#define  I_BIST_BISR_DISPI_BISR_DRF_PAUSE_reg_addr                               "0xB8025F34"
#define  I_BIST_BISR_DISPI_BISR_DRF_PAUSE_reg                                    0xB8025F34
#define  I_BIST_BISR_DISPI_BISR_DRF_PAUSE_inst_addr                              "0x000D"
#define  set_I_BIST_BISR_DISPI_BISR_DRF_PAUSE_reg(data)                          (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_DRF_PAUSE_reg)=data)
#define  get_I_BIST_BISR_DISPI_BISR_DRF_PAUSE_reg                                (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_DRF_PAUSE_reg))
#define  I_BIST_BISR_DISPI_BISR_DRF_PAUSE_spnr_bisr_drf_pause_shift              (0)
#define  I_BIST_BISR_DISPI_BISR_DRF_PAUSE_spnr_bisr_drf_pause_mask               (0x00000001)
#define  I_BIST_BISR_DISPI_BISR_DRF_PAUSE_spnr_bisr_drf_pause(data)              (0x00000001&(data))
#define  I_BIST_BISR_DISPI_BISR_DRF_PAUSE_get_spnr_bisr_drf_pause(data)          (0x00000001&(data))

#define  I_BIST_BISR_DISPI_BISR_DRF_FAIL_GROUP                                   0x18025F38
#define  I_BIST_BISR_DISPI_BISR_DRF_FAIL_GROUP_reg_addr                          "0xB8025F38"
#define  I_BIST_BISR_DISPI_BISR_DRF_FAIL_GROUP_reg                               0xB8025F38
#define  I_BIST_BISR_DISPI_BISR_DRF_FAIL_GROUP_inst_addr                         "0x000E"
#define  set_I_BIST_BISR_DISPI_BISR_DRF_FAIL_GROUP_reg(data)                     (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_DRF_FAIL_GROUP_reg)=data)
#define  get_I_BIST_BISR_DISPI_BISR_DRF_FAIL_GROUP_reg                           (*((volatile unsigned int*)I_BIST_BISR_DISPI_BISR_DRF_FAIL_GROUP_reg))
#define  I_BIST_BISR_DISPI_BISR_DRF_FAIL_GROUP_spnr_bisr_drf_fail_group_shift    (0)
#define  I_BIST_BISR_DISPI_BISR_DRF_FAIL_GROUP_spnr_bisr_drf_fail_group_mask     (0x00000001)
#define  I_BIST_BISR_DISPI_BISR_DRF_FAIL_GROUP_spnr_bisr_drf_fail_group(data)    (0x00000001&(data))
#define  I_BIST_BISR_DISPI_BISR_DRF_FAIL_GROUP_get_spnr_bisr_drf_fail_group(data) (0x00000001&(data))

#define  I_BIST_BISR_DISPI_BIST_MODE_1                                           0x18025F40
#define  I_BIST_BISR_DISPI_BIST_MODE_1_reg_addr                                  "0xB8025F40"
#define  I_BIST_BISR_DISPI_BIST_MODE_1_reg                                       0xB8025F40
#define  I_BIST_BISR_DISPI_BIST_MODE_1_inst_addr                                 "0x000F"
#define  set_I_BIST_BISR_DISPI_BIST_MODE_1_reg(data)                             (*((volatile unsigned int*)I_BIST_BISR_DISPI_BIST_MODE_1_reg)=data)
#define  get_I_BIST_BISR_DISPI_BIST_MODE_1_reg                                   (*((volatile unsigned int*)I_BIST_BISR_DISPI_BIST_MODE_1_reg))
#define  I_BIST_BISR_DISPI_BIST_MODE_1_mpegnr_vdeblk_bist_mode_shift             (0)
#define  I_BIST_BISR_DISPI_BIST_MODE_1_mpegnr_vdeblk_bist_mode_mask              (0x00000001)
#define  I_BIST_BISR_DISPI_BIST_MODE_1_mpegnr_vdeblk_bist_mode(data)             (0x00000001&(data))
#define  I_BIST_BISR_DISPI_BIST_MODE_1_get_mpegnr_vdeblk_bist_mode(data)         (0x00000001&(data))

#define  I_BIST_BISR_DISPI_BIST_DONE_1                                           0x18025F44
#define  I_BIST_BISR_DISPI_BIST_DONE_1_reg_addr                                  "0xB8025F44"
#define  I_BIST_BISR_DISPI_BIST_DONE_1_reg                                       0xB8025F44
#define  I_BIST_BISR_DISPI_BIST_DONE_1_inst_addr                                 "0x0010"
#define  set_I_BIST_BISR_DISPI_BIST_DONE_1_reg(data)                             (*((volatile unsigned int*)I_BIST_BISR_DISPI_BIST_DONE_1_reg)=data)
#define  get_I_BIST_BISR_DISPI_BIST_DONE_1_reg                                   (*((volatile unsigned int*)I_BIST_BISR_DISPI_BIST_DONE_1_reg))
#define  I_BIST_BISR_DISPI_BIST_DONE_1_mpegnr_vdeblk_bist_done_shift             (0)
#define  I_BIST_BISR_DISPI_BIST_DONE_1_mpegnr_vdeblk_bist_done_mask              (0x00000001)
#define  I_BIST_BISR_DISPI_BIST_DONE_1_mpegnr_vdeblk_bist_done(data)             (0x00000001&(data))
#define  I_BIST_BISR_DISPI_BIST_DONE_1_get_mpegnr_vdeblk_bist_done(data)         (0x00000001&(data))

#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_1                                     0x18025F48
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_1_reg_addr                            "0xB8025F48"
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_1_reg                                 0xB8025F48
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_1_inst_addr                           "0x0011"
#define  set_I_BIST_BISR_DISPI_BIST_FAIL_GROUP_1_reg(data)                       (*((volatile unsigned int*)I_BIST_BISR_DISPI_BIST_FAIL_GROUP_1_reg)=data)
#define  get_I_BIST_BISR_DISPI_BIST_FAIL_GROUP_1_reg                             (*((volatile unsigned int*)I_BIST_BISR_DISPI_BIST_FAIL_GROUP_1_reg))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_1_mpegnr_vdeblk_bist_fail_group_shift (0)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_1_mpegnr_vdeblk_bist_fail_group_mask  (0x00000001)
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_1_mpegnr_vdeblk_bist_fail_group(data) (0x00000001&(data))
#define  I_BIST_BISR_DISPI_BIST_FAIL_GROUP_1_get_mpegnr_vdeblk_bist_fail_group(data) (0x00000001&(data))

#define  I_BIST_BISR_DISPI_DRF_MODE_1                                            0x18025F4C
#define  I_BIST_BISR_DISPI_DRF_MODE_1_reg_addr                                   "0xB8025F4C"
#define  I_BIST_BISR_DISPI_DRF_MODE_1_reg                                        0xB8025F4C
#define  I_BIST_BISR_DISPI_DRF_MODE_1_inst_addr                                  "0x0012"
#define  set_I_BIST_BISR_DISPI_DRF_MODE_1_reg(data)                              (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_MODE_1_reg)=data)
#define  get_I_BIST_BISR_DISPI_DRF_MODE_1_reg                                    (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_MODE_1_reg))
#define  I_BIST_BISR_DISPI_DRF_MODE_1_mpegnr_vdeblk_drf_mode_shift               (0)
#define  I_BIST_BISR_DISPI_DRF_MODE_1_mpegnr_vdeblk_drf_mode_mask                (0x00000001)
#define  I_BIST_BISR_DISPI_DRF_MODE_1_mpegnr_vdeblk_drf_mode(data)               (0x00000001&(data))
#define  I_BIST_BISR_DISPI_DRF_MODE_1_get_mpegnr_vdeblk_drf_mode(data)           (0x00000001&(data))

#define  I_BIST_BISR_DISPI_DRF_RESUME_1                                          0x18025F50
#define  I_BIST_BISR_DISPI_DRF_RESUME_1_reg_addr                                 "0xB8025F50"
#define  I_BIST_BISR_DISPI_DRF_RESUME_1_reg                                      0xB8025F50
#define  I_BIST_BISR_DISPI_DRF_RESUME_1_inst_addr                                "0x0013"
#define  set_I_BIST_BISR_DISPI_DRF_RESUME_1_reg(data)                            (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_RESUME_1_reg)=data)
#define  get_I_BIST_BISR_DISPI_DRF_RESUME_1_reg                                  (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_RESUME_1_reg))
#define  I_BIST_BISR_DISPI_DRF_RESUME_1_mpegnr_vdeblk_drf_resume_shift           (0)
#define  I_BIST_BISR_DISPI_DRF_RESUME_1_mpegnr_vdeblk_drf_resume_mask            (0x00000001)
#define  I_BIST_BISR_DISPI_DRF_RESUME_1_mpegnr_vdeblk_drf_resume(data)           (0x00000001&(data))
#define  I_BIST_BISR_DISPI_DRF_RESUME_1_get_mpegnr_vdeblk_drf_resume(data)       (0x00000001&(data))

#define  I_BIST_BISR_DISPI_DRF_DONE_1                                            0x18025F54
#define  I_BIST_BISR_DISPI_DRF_DONE_1_reg_addr                                   "0xB8025F54"
#define  I_BIST_BISR_DISPI_DRF_DONE_1_reg                                        0xB8025F54
#define  I_BIST_BISR_DISPI_DRF_DONE_1_inst_addr                                  "0x0014"
#define  set_I_BIST_BISR_DISPI_DRF_DONE_1_reg(data)                              (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_DONE_1_reg)=data)
#define  get_I_BIST_BISR_DISPI_DRF_DONE_1_reg                                    (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_DONE_1_reg))
#define  I_BIST_BISR_DISPI_DRF_DONE_1_mpegnr_vdeblk_drf_done_shift               (0)
#define  I_BIST_BISR_DISPI_DRF_DONE_1_mpegnr_vdeblk_drf_done_mask                (0x00000001)
#define  I_BIST_BISR_DISPI_DRF_DONE_1_mpegnr_vdeblk_drf_done(data)               (0x00000001&(data))
#define  I_BIST_BISR_DISPI_DRF_DONE_1_get_mpegnr_vdeblk_drf_done(data)           (0x00000001&(data))

#define  I_BIST_BISR_DISPI_DRF_PAUSE_1                                           0x18025F58
#define  I_BIST_BISR_DISPI_DRF_PAUSE_1_reg_addr                                  "0xB8025F58"
#define  I_BIST_BISR_DISPI_DRF_PAUSE_1_reg                                       0xB8025F58
#define  I_BIST_BISR_DISPI_DRF_PAUSE_1_inst_addr                                 "0x0015"
#define  set_I_BIST_BISR_DISPI_DRF_PAUSE_1_reg(data)                             (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_PAUSE_1_reg)=data)
#define  get_I_BIST_BISR_DISPI_DRF_PAUSE_1_reg                                   (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_PAUSE_1_reg))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_1_mpegnr_vdeblk_drf_pause_shift             (0)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_1_mpegnr_vdeblk_drf_pause_mask              (0x00000001)
#define  I_BIST_BISR_DISPI_DRF_PAUSE_1_mpegnr_vdeblk_drf_pause(data)             (0x00000001&(data))
#define  I_BIST_BISR_DISPI_DRF_PAUSE_1_get_mpegnr_vdeblk_drf_pause(data)         (0x00000001&(data))

#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_1                                      0x18025F5C
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_1_reg_addr                             "0xB8025F5C"
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_1_reg                                  0xB8025F5C
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_1_inst_addr                            "0x0016"
#define  set_I_BIST_BISR_DISPI_DRF_FAIL_GROUP_1_reg(data)                        (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_FAIL_GROUP_1_reg)=data)
#define  get_I_BIST_BISR_DISPI_DRF_FAIL_GROUP_1_reg                              (*((volatile unsigned int*)I_BIST_BISR_DISPI_DRF_FAIL_GROUP_1_reg))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_1_mpegnr_vdeblk_drf_fail_group_shift   (0)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_1_mpegnr_vdeblk_drf_fail_group_mask    (0x00000001)
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_1_mpegnr_vdeblk_drf_fail_group(data)   (0x00000001&(data))
#define  I_BIST_BISR_DISPI_DRF_FAIL_GROUP_1_get_mpegnr_vdeblk_drf_fail_group(data) (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======I_BIST_BISR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_mbist_hist_1p_bist_mode:1;
        RBus_UInt32  ch1_mbist_hist_2p_bist_mode:1;
        RBus_UInt32  rtnr_mcnr_tmv1_bist_mode:1;
        RBus_UInt32  rtnr_mcnr_tmv2_bist_mode:1;
        RBus_UInt32  di_li4_bist_mode:1;
        RBus_UInt32  di_li5_bist_mode:1;
        RBus_UInt32  pqdc1_bist_mode:1;
        RBus_UInt32  pqdc2_bist_mode:1;
        RBus_UInt32  pqc1_bist_mode:1;
        RBus_UInt32  pqc2_bist_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dexcxl_winfo_bist_mode:1;
        RBus_UInt32  dexcxl_wdat_bist_mode:1;
        RBus_UInt32  dexcxl_rinfo_bist_mode:1;
        RBus_UInt32  dexcxl_rdat2_bist_mode:1;
        RBus_UInt32  dexcxl_rdat1_bist_mode:1;
        RBus_UInt32  i3ddma_bist_cap2_mode:1;
        RBus_UInt32  sdnr_ch1_bist_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  di_tr2to1_bist_mode:1;
        RBus_UInt32  di_hmc_bist_mode:1;
        RBus_UInt32  di_dma_wdat_bist_mode:1;
        RBus_UInt32  di_dma_rdat_bist_mode:1;
        RBus_UInt32  di_li1_bist_mode:1;
        RBus_UInt32  di_li2_bist_mode:1;
        RBus_UInt32  di_li3_bist_mode:1;
        RBus_UInt32  i3ddma_uzd_bist_mode:1;
        RBus_UInt32  i3ddma_bist_mode:1;
    };
}i_bist_bisr_dispi_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_mbist_hist_1p_bist_done:1;
        RBus_UInt32  ch1_mbist_hist_2p_bist_done:1;
        RBus_UInt32  rtnr_mcnr_tmv1_bist_done:1;
        RBus_UInt32  rtnr_mcnr_tmv2_bist_done:1;
        RBus_UInt32  di_li4_bist_done:1;
        RBus_UInt32  di_li5_bist_done:1;
        RBus_UInt32  pqdc1_bist_done:1;
        RBus_UInt32  pqdc2_bist_done:1;
        RBus_UInt32  pqc1_bist_done:1;
        RBus_UInt32  pqc2_bist_done:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dexcxl_winfo_bist_done:1;
        RBus_UInt32  dexcxl_wdat_bist_done:1;
        RBus_UInt32  dexcxl_rinfo_bist_done:1;
        RBus_UInt32  dexcxl_rdat2_bist_done:1;
        RBus_UInt32  dexcxl_rdat1_bist_done:1;
        RBus_UInt32  i3ddma_bist_cap2_done:1;
        RBus_UInt32  sdnr_ch1_bist_done:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  di_tr2to1_bist_done:1;
        RBus_UInt32  di_hmc_bist_done:1;
        RBus_UInt32  di_dma_wdat_bist_done:1;
        RBus_UInt32  di_dma_rdat_bist_done:1;
        RBus_UInt32  di_li1_bist_done:1;
        RBus_UInt32  di_li2_bist_done:1;
        RBus_UInt32  di_li3_bist_done:1;
        RBus_UInt32  i3ddma_uzd_bist_done:1;
        RBus_UInt32  i3ddma_bist_done:1;
    };
}i_bist_bisr_dispi_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_mbist_hist_1p_fail_group:1;
        RBus_UInt32  ch1_mbist_hist_2p_fail_group:1;
        RBus_UInt32  rtnr_mcnr_tmv1_bist_fail_group:1;
        RBus_UInt32  rtnr_mcnr_tmv2_bist_fail_group:1;
        RBus_UInt32  di_li4_bist_fail_group:1;
        RBus_UInt32  di_li5_bist_fail_group:1;
        RBus_UInt32  pqdc1_bist_fail_group:1;
        RBus_UInt32  pqdc2_bist_fail_group:1;
        RBus_UInt32  pqc1_bist_fail_group:1;
        RBus_UInt32  pqc2_bist_fail_group:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dexcxl_winfo_bist_fail_group:1;
        RBus_UInt32  dexcxl_wdat_bist_fail_group:1;
        RBus_UInt32  dexcxl_rinfo_bist_fai_groupl:1;
        RBus_UInt32  dexcxl_rdat2_bist_fail_group:1;
        RBus_UInt32  dexcxl_rdat1_bist_fail_group:1;
        RBus_UInt32  i3ddma_bist_cap2_fail_group:1;
        RBus_UInt32  sdnr_ch1_bist_fail_group:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  di_tr2to1_bist_fail_group:1;
        RBus_UInt32  di_hmc_bist_fail_group:1;
        RBus_UInt32  di_dma_wdat_bist_fail_group:1;
        RBus_UInt32  di_dma_rdat_bist_fail_group:1;
        RBus_UInt32  di_li1_bist_fail_group:1;
        RBus_UInt32  di_li2_bist_fail_group:1;
        RBus_UInt32  di_li3_bist_fail_group:1;
        RBus_UInt32  i3ddma_uzd_bist_fail_group:1;
        RBus_UInt32  i3ddma_bist_fail_group:1;
    };
}i_bist_bisr_dispi_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_mbist_hist_1p_drf_mode:1;
        RBus_UInt32  ch1_mbist_hist_2p_drf_mode:1;
        RBus_UInt32  rtnr_mcnr_tmv1_drf_mode:1;
        RBus_UInt32  rtnr_mcnr_tmv2_drf_mode:1;
        RBus_UInt32  di_li4_drf_mode:1;
        RBus_UInt32  di_li5_drf_mode:1;
        RBus_UInt32  pqdc1_drf_mode:1;
        RBus_UInt32  pqdc2_drf_mode:1;
        RBus_UInt32  pqc1_drf_mode:1;
        RBus_UInt32  pqc2_drf_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dexcxl_winfo_drf_mode:1;
        RBus_UInt32  dexcxl_wdat_drf_mode:1;
        RBus_UInt32  dexcxl_rinfo_drf_mode:1;
        RBus_UInt32  dexcxl_rdat2_drf_mode:1;
        RBus_UInt32  dexcxl_rdat1_drf_mode:1;
        RBus_UInt32  i3ddma_drf_cap2_mode:1;
        RBus_UInt32  sdnr_ch1_drf_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  di_tr2to1_drf_mode:1;
        RBus_UInt32  di_hmc_drf_mode:1;
        RBus_UInt32  di_dma_wdat_drf_mode:1;
        RBus_UInt32  di_dma_rdat_drf_mode:1;
        RBus_UInt32  di_li1_drf_mode:1;
        RBus_UInt32  di_li2_drf_mode:1;
        RBus_UInt32  di_li3_drf_mode:1;
        RBus_UInt32  i3ddma_uzd_drf_mode:1;
        RBus_UInt32  i3ddma_drf_mode:1;
    };
}i_bist_bisr_dispi_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_mbist_hist_1p_drf_resume:1;
        RBus_UInt32  ch1_mbist_hist_2p_drf_resume:1;
        RBus_UInt32  rtnr_mcnr_tmv1_drf_resume:1;
        RBus_UInt32  rtnr_mcnr_tmv2_drf_resume:1;
        RBus_UInt32  di_li4_drf_resume:1;
        RBus_UInt32  di_li5_drf_resume:1;
        RBus_UInt32  pqdc1_drf_resume:1;
        RBus_UInt32  pqdc2_drf_resume:1;
        RBus_UInt32  pqc1_drf_resume:1;
        RBus_UInt32  pqc2_drf_resume:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dexcxl_winfo_drf_resume:1;
        RBus_UInt32  dexcxl_wdat_drf_resume:1;
        RBus_UInt32  dexcxl_rinfo_drf_resume:1;
        RBus_UInt32  dexcxl_rdat2_drf_resume:1;
        RBus_UInt32  dexcxl_rdat1_drf_resume:1;
        RBus_UInt32  i3ddma_drf_cap2_resume:1;
        RBus_UInt32  sdnr_ch1_drf_resume:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  di_tr2to1_drf_resume:1;
        RBus_UInt32  di_hmc_drf_resume:1;
        RBus_UInt32  di_dma_wdat_drf_resume:1;
        RBus_UInt32  di_dma_rdat_drf_resume:1;
        RBus_UInt32  di_li1_drf_resume:1;
        RBus_UInt32  di_li2_drf_resume:1;
        RBus_UInt32  di_li3_drf_resume:1;
        RBus_UInt32  i3ddma_uzd_drf_resume:1;
        RBus_UInt32  i3ddma_drf_resume:1;
    };
}i_bist_bisr_dispi_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_mbist_hist_1p_drf_done:1;
        RBus_UInt32  ch1_mbist_hist_2p_drf_done:1;
        RBus_UInt32  rtnr_mcnr_tmv1_drf_done:1;
        RBus_UInt32  rtnr_mcnr_tmv2_drf_done:1;
        RBus_UInt32  di_li4_drf_done:1;
        RBus_UInt32  di_li5_drf_done:1;
        RBus_UInt32  pqdc1_drf_done:1;
        RBus_UInt32  pqdc2_drf_done:1;
        RBus_UInt32  pqc1_drf_done:1;
        RBus_UInt32  pqc2_drf_done:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dexcxl_winfo_drf_done:1;
        RBus_UInt32  dexcxl_wdat_drf_done:1;
        RBus_UInt32  dexcxl_rinfo_drf_done:1;
        RBus_UInt32  dexcxl_rdat2_drf_done:1;
        RBus_UInt32  dexcxl_rdat1_drf_done:1;
        RBus_UInt32  i3ddma_drf_cap2_done:1;
        RBus_UInt32  sdnr_ch1_drf_done:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  di_tr2to1_drf_done:1;
        RBus_UInt32  di_hmc_drf_done:1;
        RBus_UInt32  di_dma_wdat_drf_done:1;
        RBus_UInt32  di_dma_rdat_drf_done:1;
        RBus_UInt32  di_li1_drf_done:1;
        RBus_UInt32  di_li2_drf_done:1;
        RBus_UInt32  di_li3_drf_done:1;
        RBus_UInt32  i3ddma_uzd_drf_done:1;
        RBus_UInt32  i3ddma_drf_done:1;
    };
}i_bist_bisr_dispi_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_mbist_hist_1p_drf_pause:1;
        RBus_UInt32  ch1_mbist_hist_2p_drf_pause:1;
        RBus_UInt32  rtnr_mcnr_tmv1_drf_pause:1;
        RBus_UInt32  rtnr_mcnr_tmv2_drf_pause:1;
        RBus_UInt32  di_li4_drf_pause:1;
        RBus_UInt32  di_li5_drf_pause:1;
        RBus_UInt32  pqdc1_drf_pause:1;
        RBus_UInt32  pqdc2_drf_pause:1;
        RBus_UInt32  pqc1_drf_pause:1;
        RBus_UInt32  pqc2_drf_pause:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dexcxl_winfo_drf_pause:1;
        RBus_UInt32  dexcxl_wdat_drf_pause:1;
        RBus_UInt32  dexcxl_rinfo_drf_pause:1;
        RBus_UInt32  dexcxl_rdat2_drf_pause:1;
        RBus_UInt32  dexcxl_rdat1_drf_pause:1;
        RBus_UInt32  i3ddma_drf_cap2_pause:1;
        RBus_UInt32  sdnr_ch1_drf_pause:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  di_tr2to1_drf_pause:1;
        RBus_UInt32  di_hmc_drf_pause:1;
        RBus_UInt32  di_dma_wdat_drf_pause:1;
        RBus_UInt32  di_dma_rdat_drf_pause:1;
        RBus_UInt32  di_li1_drf_pause:1;
        RBus_UInt32  di_li2_drf_pause:1;
        RBus_UInt32  di_li3_drf_pause:1;
        RBus_UInt32  i3ddma_uzd_drf_pause:1;
        RBus_UInt32  i3ddma_drf_pause:1;
    };
}i_bist_bisr_dispi_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_mbist_hist_1p_drf_fail_group:1;
        RBus_UInt32  ch1_mbist_hist_2p_drf_fail_group:1;
        RBus_UInt32  rtnr_mcnr_tmv1_drf_fail_group:1;
        RBus_UInt32  rtnr_mcnr_tmv2_drf_fail_group:1;
        RBus_UInt32  di_li4_drf_fail_group:1;
        RBus_UInt32  di_li5_drf_fail_group:1;
        RBus_UInt32  pqdc1_drf_fail_group:1;
        RBus_UInt32  pqdc2_drf_fail_group:1;
        RBus_UInt32  pqc1_drf_fail_group:1;
        RBus_UInt32  pqc2_drf_fail_group:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dexcxl_winfo_drf_fail_group:1;
        RBus_UInt32  dexcxl_wdat_drf_fail_group:1;
        RBus_UInt32  dexcxl_rinfo_drf_fail_group:1;
        RBus_UInt32  dexcxl_rdat2_drf_fail_group:1;
        RBus_UInt32  dexcxl_rdat1_drf_fail_group:1;
        RBus_UInt32  i3ddma_drf_cap2_fail_group:1;
        RBus_UInt32  sdnr_ch1_drf_fail_group:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  di_tr2to1_drf_fail_group:1;
        RBus_UInt32  di_hmc_drf_fail_group:1;
        RBus_UInt32  di_dma_wdat_drf_fail_group:1;
        RBus_UInt32  di_dma_rdat_drf_fail_group:1;
        RBus_UInt32  di_li1_drf_fail_group:1;
        RBus_UInt32  di_li2_drf_fail_group:1;
        RBus_UInt32  di_li3_drf_fail_group:1;
        RBus_UInt32  i3ddma_uzd_drf_fail_group:1;
        RBus_UInt32  i3ddma_drf_fail_group:1;
    };
}i_bist_bisr_dispi_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  spnr_bisr_second_run_en:1;
    };
}i_bist_bisr_dispi_bisr_second_run_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  spnr_bisr_fail_group:1;
    };
}i_bist_bisr_dispi_bisr_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  spnr_bisr_drf_mode:1;
    };
}i_bist_bisr_dispi_bisr_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  spnr_bisr_drf_resume:1;
    };
}i_bist_bisr_dispi_bisr_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  spnr_bisr_drf_done:1;
    };
}i_bist_bisr_dispi_bisr_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  spnr_bisr_drf_pause:1;
    };
}i_bist_bisr_dispi_bisr_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  spnr_bisr_drf_fail_group:1;
    };
}i_bist_bisr_dispi_bisr_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mpegnr_vdeblk_bist_mode:1;
    };
}i_bist_bisr_dispi_bist_mode_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mpegnr_vdeblk_bist_done:1;
    };
}i_bist_bisr_dispi_bist_done_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mpegnr_vdeblk_bist_fail_group:1;
    };
}i_bist_bisr_dispi_bist_fail_group_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mpegnr_vdeblk_drf_mode:1;
    };
}i_bist_bisr_dispi_drf_mode_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mpegnr_vdeblk_drf_resume:1;
    };
}i_bist_bisr_dispi_drf_resume_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mpegnr_vdeblk_drf_done:1;
    };
}i_bist_bisr_dispi_drf_done_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mpegnr_vdeblk_drf_pause:1;
    };
}i_bist_bisr_dispi_drf_pause_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mpegnr_vdeblk_drf_fail_group:1;
    };
}i_bist_bisr_dispi_drf_fail_group_1_RBUS;

#else //apply LITTLE_ENDIAN

//======I_BIST_BISR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_bist_mode:1;
        RBus_UInt32  i3ddma_uzd_bist_mode:1;
        RBus_UInt32  di_li3_bist_mode:1;
        RBus_UInt32  di_li2_bist_mode:1;
        RBus_UInt32  di_li1_bist_mode:1;
        RBus_UInt32  di_dma_rdat_bist_mode:1;
        RBus_UInt32  di_dma_wdat_bist_mode:1;
        RBus_UInt32  di_hmc_bist_mode:1;
        RBus_UInt32  di_tr2to1_bist_mode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sdnr_ch1_bist_mode:1;
        RBus_UInt32  i3ddma_bist_cap2_mode:1;
        RBus_UInt32  dexcxl_rdat1_bist_mode:1;
        RBus_UInt32  dexcxl_rdat2_bist_mode:1;
        RBus_UInt32  dexcxl_rinfo_bist_mode:1;
        RBus_UInt32  dexcxl_wdat_bist_mode:1;
        RBus_UInt32  dexcxl_winfo_bist_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pqc2_bist_mode:1;
        RBus_UInt32  pqc1_bist_mode:1;
        RBus_UInt32  pqdc2_bist_mode:1;
        RBus_UInt32  pqdc1_bist_mode:1;
        RBus_UInt32  di_li5_bist_mode:1;
        RBus_UInt32  di_li4_bist_mode:1;
        RBus_UInt32  rtnr_mcnr_tmv2_bist_mode:1;
        RBus_UInt32  rtnr_mcnr_tmv1_bist_mode:1;
        RBus_UInt32  ch1_mbist_hist_2p_bist_mode:1;
        RBus_UInt32  ch1_mbist_hist_1p_bist_mode:1;
        RBus_UInt32  res3:3;
    };
}i_bist_bisr_dispi_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_bist_done:1;
        RBus_UInt32  i3ddma_uzd_bist_done:1;
        RBus_UInt32  di_li3_bist_done:1;
        RBus_UInt32  di_li2_bist_done:1;
        RBus_UInt32  di_li1_bist_done:1;
        RBus_UInt32  di_dma_rdat_bist_done:1;
        RBus_UInt32  di_dma_wdat_bist_done:1;
        RBus_UInt32  di_hmc_bist_done:1;
        RBus_UInt32  di_tr2to1_bist_done:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sdnr_ch1_bist_done:1;
        RBus_UInt32  i3ddma_bist_cap2_done:1;
        RBus_UInt32  dexcxl_rdat1_bist_done:1;
        RBus_UInt32  dexcxl_rdat2_bist_done:1;
        RBus_UInt32  dexcxl_rinfo_bist_done:1;
        RBus_UInt32  dexcxl_wdat_bist_done:1;
        RBus_UInt32  dexcxl_winfo_bist_done:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pqc2_bist_done:1;
        RBus_UInt32  pqc1_bist_done:1;
        RBus_UInt32  pqdc2_bist_done:1;
        RBus_UInt32  pqdc1_bist_done:1;
        RBus_UInt32  di_li5_bist_done:1;
        RBus_UInt32  di_li4_bist_done:1;
        RBus_UInt32  rtnr_mcnr_tmv2_bist_done:1;
        RBus_UInt32  rtnr_mcnr_tmv1_bist_done:1;
        RBus_UInt32  ch1_mbist_hist_2p_bist_done:1;
        RBus_UInt32  ch1_mbist_hist_1p_bist_done:1;
        RBus_UInt32  res3:3;
    };
}i_bist_bisr_dispi_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_bist_fail_group:1;
        RBus_UInt32  i3ddma_uzd_bist_fail_group:1;
        RBus_UInt32  di_li3_bist_fail_group:1;
        RBus_UInt32  di_li2_bist_fail_group:1;
        RBus_UInt32  di_li1_bist_fail_group:1;
        RBus_UInt32  di_dma_rdat_bist_fail_group:1;
        RBus_UInt32  di_dma_wdat_bist_fail_group:1;
        RBus_UInt32  di_hmc_bist_fail_group:1;
        RBus_UInt32  di_tr2to1_bist_fail_group:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sdnr_ch1_bist_fail_group:1;
        RBus_UInt32  i3ddma_bist_cap2_fail_group:1;
        RBus_UInt32  dexcxl_rdat1_bist_fail_group:1;
        RBus_UInt32  dexcxl_rdat2_bist_fail_group:1;
        RBus_UInt32  dexcxl_rinfo_bist_fai_groupl:1;
        RBus_UInt32  dexcxl_wdat_bist_fail_group:1;
        RBus_UInt32  dexcxl_winfo_bist_fail_group:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pqc2_bist_fail_group:1;
        RBus_UInt32  pqc1_bist_fail_group:1;
        RBus_UInt32  pqdc2_bist_fail_group:1;
        RBus_UInt32  pqdc1_bist_fail_group:1;
        RBus_UInt32  di_li5_bist_fail_group:1;
        RBus_UInt32  di_li4_bist_fail_group:1;
        RBus_UInt32  rtnr_mcnr_tmv2_bist_fail_group:1;
        RBus_UInt32  rtnr_mcnr_tmv1_bist_fail_group:1;
        RBus_UInt32  ch1_mbist_hist_2p_fail_group:1;
        RBus_UInt32  ch1_mbist_hist_1p_fail_group:1;
        RBus_UInt32  res3:3;
    };
}i_bist_bisr_dispi_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_drf_mode:1;
        RBus_UInt32  i3ddma_uzd_drf_mode:1;
        RBus_UInt32  di_li3_drf_mode:1;
        RBus_UInt32  di_li2_drf_mode:1;
        RBus_UInt32  di_li1_drf_mode:1;
        RBus_UInt32  di_dma_rdat_drf_mode:1;
        RBus_UInt32  di_dma_wdat_drf_mode:1;
        RBus_UInt32  di_hmc_drf_mode:1;
        RBus_UInt32  di_tr2to1_drf_mode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sdnr_ch1_drf_mode:1;
        RBus_UInt32  i3ddma_drf_cap2_mode:1;
        RBus_UInt32  dexcxl_rdat1_drf_mode:1;
        RBus_UInt32  dexcxl_rdat2_drf_mode:1;
        RBus_UInt32  dexcxl_rinfo_drf_mode:1;
        RBus_UInt32  dexcxl_wdat_drf_mode:1;
        RBus_UInt32  dexcxl_winfo_drf_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pqc2_drf_mode:1;
        RBus_UInt32  pqc1_drf_mode:1;
        RBus_UInt32  pqdc2_drf_mode:1;
        RBus_UInt32  pqdc1_drf_mode:1;
        RBus_UInt32  di_li5_drf_mode:1;
        RBus_UInt32  di_li4_drf_mode:1;
        RBus_UInt32  rtnr_mcnr_tmv2_drf_mode:1;
        RBus_UInt32  rtnr_mcnr_tmv1_drf_mode:1;
        RBus_UInt32  ch1_mbist_hist_2p_drf_mode:1;
        RBus_UInt32  ch1_mbist_hist_1p_drf_mode:1;
        RBus_UInt32  res3:3;
    };
}i_bist_bisr_dispi_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_drf_resume:1;
        RBus_UInt32  i3ddma_uzd_drf_resume:1;
        RBus_UInt32  di_li3_drf_resume:1;
        RBus_UInt32  di_li2_drf_resume:1;
        RBus_UInt32  di_li1_drf_resume:1;
        RBus_UInt32  di_dma_rdat_drf_resume:1;
        RBus_UInt32  di_dma_wdat_drf_resume:1;
        RBus_UInt32  di_hmc_drf_resume:1;
        RBus_UInt32  di_tr2to1_drf_resume:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sdnr_ch1_drf_resume:1;
        RBus_UInt32  i3ddma_drf_cap2_resume:1;
        RBus_UInt32  dexcxl_rdat1_drf_resume:1;
        RBus_UInt32  dexcxl_rdat2_drf_resume:1;
        RBus_UInt32  dexcxl_rinfo_drf_resume:1;
        RBus_UInt32  dexcxl_wdat_drf_resume:1;
        RBus_UInt32  dexcxl_winfo_drf_resume:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pqc2_drf_resume:1;
        RBus_UInt32  pqc1_drf_resume:1;
        RBus_UInt32  pqdc2_drf_resume:1;
        RBus_UInt32  pqdc1_drf_resume:1;
        RBus_UInt32  di_li5_drf_resume:1;
        RBus_UInt32  di_li4_drf_resume:1;
        RBus_UInt32  rtnr_mcnr_tmv2_drf_resume:1;
        RBus_UInt32  rtnr_mcnr_tmv1_drf_resume:1;
        RBus_UInt32  ch1_mbist_hist_2p_drf_resume:1;
        RBus_UInt32  ch1_mbist_hist_1p_drf_resume:1;
        RBus_UInt32  res3:3;
    };
}i_bist_bisr_dispi_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_drf_done:1;
        RBus_UInt32  i3ddma_uzd_drf_done:1;
        RBus_UInt32  di_li3_drf_done:1;
        RBus_UInt32  di_li2_drf_done:1;
        RBus_UInt32  di_li1_drf_done:1;
        RBus_UInt32  di_dma_rdat_drf_done:1;
        RBus_UInt32  di_dma_wdat_drf_done:1;
        RBus_UInt32  di_hmc_drf_done:1;
        RBus_UInt32  di_tr2to1_drf_done:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sdnr_ch1_drf_done:1;
        RBus_UInt32  i3ddma_drf_cap2_done:1;
        RBus_UInt32  dexcxl_rdat1_drf_done:1;
        RBus_UInt32  dexcxl_rdat2_drf_done:1;
        RBus_UInt32  dexcxl_rinfo_drf_done:1;
        RBus_UInt32  dexcxl_wdat_drf_done:1;
        RBus_UInt32  dexcxl_winfo_drf_done:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pqc2_drf_done:1;
        RBus_UInt32  pqc1_drf_done:1;
        RBus_UInt32  pqdc2_drf_done:1;
        RBus_UInt32  pqdc1_drf_done:1;
        RBus_UInt32  di_li5_drf_done:1;
        RBus_UInt32  di_li4_drf_done:1;
        RBus_UInt32  rtnr_mcnr_tmv2_drf_done:1;
        RBus_UInt32  rtnr_mcnr_tmv1_drf_done:1;
        RBus_UInt32  ch1_mbist_hist_2p_drf_done:1;
        RBus_UInt32  ch1_mbist_hist_1p_drf_done:1;
        RBus_UInt32  res3:3;
    };
}i_bist_bisr_dispi_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_drf_pause:1;
        RBus_UInt32  i3ddma_uzd_drf_pause:1;
        RBus_UInt32  di_li3_drf_pause:1;
        RBus_UInt32  di_li2_drf_pause:1;
        RBus_UInt32  di_li1_drf_pause:1;
        RBus_UInt32  di_dma_rdat_drf_pause:1;
        RBus_UInt32  di_dma_wdat_drf_pause:1;
        RBus_UInt32  di_hmc_drf_pause:1;
        RBus_UInt32  di_tr2to1_drf_pause:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sdnr_ch1_drf_pause:1;
        RBus_UInt32  i3ddma_drf_cap2_pause:1;
        RBus_UInt32  dexcxl_rdat1_drf_pause:1;
        RBus_UInt32  dexcxl_rdat2_drf_pause:1;
        RBus_UInt32  dexcxl_rinfo_drf_pause:1;
        RBus_UInt32  dexcxl_wdat_drf_pause:1;
        RBus_UInt32  dexcxl_winfo_drf_pause:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pqc2_drf_pause:1;
        RBus_UInt32  pqc1_drf_pause:1;
        RBus_UInt32  pqdc2_drf_pause:1;
        RBus_UInt32  pqdc1_drf_pause:1;
        RBus_UInt32  di_li5_drf_pause:1;
        RBus_UInt32  di_li4_drf_pause:1;
        RBus_UInt32  rtnr_mcnr_tmv2_drf_pause:1;
        RBus_UInt32  rtnr_mcnr_tmv1_drf_pause:1;
        RBus_UInt32  ch1_mbist_hist_2p_drf_pause:1;
        RBus_UInt32  ch1_mbist_hist_1p_drf_pause:1;
        RBus_UInt32  res3:3;
    };
}i_bist_bisr_dispi_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_drf_fail_group:1;
        RBus_UInt32  i3ddma_uzd_drf_fail_group:1;
        RBus_UInt32  di_li3_drf_fail_group:1;
        RBus_UInt32  di_li2_drf_fail_group:1;
        RBus_UInt32  di_li1_drf_fail_group:1;
        RBus_UInt32  di_dma_rdat_drf_fail_group:1;
        RBus_UInt32  di_dma_wdat_drf_fail_group:1;
        RBus_UInt32  di_hmc_drf_fail_group:1;
        RBus_UInt32  di_tr2to1_drf_fail_group:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sdnr_ch1_drf_fail_group:1;
        RBus_UInt32  i3ddma_drf_cap2_fail_group:1;
        RBus_UInt32  dexcxl_rdat1_drf_fail_group:1;
        RBus_UInt32  dexcxl_rdat2_drf_fail_group:1;
        RBus_UInt32  dexcxl_rinfo_drf_fail_group:1;
        RBus_UInt32  dexcxl_wdat_drf_fail_group:1;
        RBus_UInt32  dexcxl_winfo_drf_fail_group:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pqc2_drf_fail_group:1;
        RBus_UInt32  pqc1_drf_fail_group:1;
        RBus_UInt32  pqdc2_drf_fail_group:1;
        RBus_UInt32  pqdc1_drf_fail_group:1;
        RBus_UInt32  di_li5_drf_fail_group:1;
        RBus_UInt32  di_li4_drf_fail_group:1;
        RBus_UInt32  rtnr_mcnr_tmv2_drf_fail_group:1;
        RBus_UInt32  rtnr_mcnr_tmv1_drf_fail_group:1;
        RBus_UInt32  ch1_mbist_hist_2p_drf_fail_group:1;
        RBus_UInt32  ch1_mbist_hist_1p_drf_fail_group:1;
        RBus_UInt32  res3:3;
    };
}i_bist_bisr_dispi_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_bisr_second_run_en:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_bisr_second_run_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_bisr_fail_group:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_bisr_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_bisr_drf_mode:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_bisr_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_bisr_drf_resume:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_bisr_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_bisr_drf_done:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_bisr_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_bisr_drf_pause:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_bisr_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_bisr_drf_fail_group:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_bisr_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpegnr_vdeblk_bist_mode:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_bist_mode_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpegnr_vdeblk_bist_done:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_bist_done_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpegnr_vdeblk_bist_fail_group:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_bist_fail_group_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpegnr_vdeblk_drf_mode:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_drf_mode_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpegnr_vdeblk_drf_resume:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_drf_resume_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpegnr_vdeblk_drf_done:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_drf_done_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpegnr_vdeblk_drf_pause:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_drf_pause_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mpegnr_vdeblk_drf_fail_group:1;
        RBus_UInt32  res1:31;
    };
}i_bist_bisr_dispi_drf_fail_group_1_RBUS;




#endif 


#endif 
