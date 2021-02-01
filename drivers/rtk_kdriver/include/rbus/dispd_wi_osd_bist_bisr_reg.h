/**
* @file Mac5-DesignSpec-D-Domain_WI_OSD_TOP_BIST_BISR_control
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DISPD_WI_OSD_BIST_BISR_REG_H_
#define _RBUS_DISPD_WI_OSD_BIST_BISR_REG_H_

#include "rbus_types.h"



//  DISPD_WI_OSD_BIST_BISR Register Address
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE                                  0x18029F80
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_reg_addr                         "0xB8029F80"
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_reg                              0xB8029F80
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_inst_addr                        "0x0000"
#define  set_DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_reg(data)                    (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_reg)=data)
#define  get_DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_reg                          (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_reg))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_vi_bist_mode_shift               (21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_duzd_bist_mode_shift             (20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pqdc2_bist_mode_shift            (19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pqdc1_bist_mode_shift            (18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pqc2_bist_mode_shift             (17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pqc1_bist_mode_shift             (16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_dispbuf_bist_mode_shift (12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_dma_buf_bist_mode_shift (11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_lb_bist_mode_shift     (10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_rbuf_bist_mode_shift   (9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_clut_bist_mode_shift   (8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gamma2_bist_mode_shift           (7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pcid_bist_mode_shift             (6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_oddma_bist_mode_shift            (3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_od_bist_mode_shift               (2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_ld_con_bist_mode_shift           (1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_ld_spi_con_bist_mode_shift       (0)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_vi_bist_mode_mask                (0x00200000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_duzd_bist_mode_mask              (0x00100000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pqdc2_bist_mode_mask             (0x00080000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pqdc1_bist_mode_mask             (0x00040000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pqc2_bist_mode_mask              (0x00020000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pqc1_bist_mode_mask              (0x00010000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_dispbuf_bist_mode_mask (0x00001000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_dma_buf_bist_mode_mask (0x00000800)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_lb_bist_mode_mask      (0x00000400)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_rbuf_bist_mode_mask    (0x00000200)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_clut_bist_mode_mask    (0x00000100)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gamma2_bist_mode_mask            (0x00000080)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pcid_bist_mode_mask              (0x00000040)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_oddma_bist_mode_mask             (0x00000008)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_od_bist_mode_mask                (0x00000004)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_ld_con_bist_mode_mask            (0x00000002)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_ld_spi_con_bist_mode_mask        (0x00000001)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_vi_bist_mode(data)               (0x00200000&((data)<<21))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_duzd_bist_mode(data)             (0x00100000&((data)<<20))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pqdc2_bist_mode(data)            (0x00080000&((data)<<19))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pqdc1_bist_mode(data)            (0x00040000&((data)<<18))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pqc2_bist_mode(data)             (0x00020000&((data)<<17))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pqc1_bist_mode(data)             (0x00010000&((data)<<16))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_dispbuf_bist_mode(data) (0x00001000&((data)<<12))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_dma_buf_bist_mode(data) (0x00000800&((data)<<11))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_lb_bist_mode(data)     (0x00000400&((data)<<10))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_rbuf_bist_mode(data)   (0x00000200&((data)<<9))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gdma_subt_clut_bist_mode(data)   (0x00000100&((data)<<8))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_gamma2_bist_mode(data)           (0x00000080&((data)<<7))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_pcid_bist_mode(data)             (0x00000040&((data)<<6))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_oddma_bist_mode(data)            (0x00000008&((data)<<3))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_od_bist_mode(data)               (0x00000004&((data)<<2))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_ld_con_bist_mode(data)           (0x00000002&((data)<<1))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_ld_spi_con_bist_mode(data)       (0x00000001&(data))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_vi_bist_mode(data)           ((0x00200000&(data))>>21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_duzd_bist_mode(data)         ((0x00100000&(data))>>20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_pqdc2_bist_mode(data)        ((0x00080000&(data))>>19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_pqdc1_bist_mode(data)        ((0x00040000&(data))>>18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_pqc2_bist_mode(data)         ((0x00020000&(data))>>17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_pqc1_bist_mode(data)         ((0x00010000&(data))>>16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_gdma_subt_dispbuf_bist_mode(data) ((0x00001000&(data))>>12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_gdma_subt_dma_buf_bist_mode(data) ((0x00000800&(data))>>11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_gdma_subt_lb_bist_mode(data) ((0x00000400&(data))>>10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_gdma_subt_rbuf_bist_mode(data) ((0x00000200&(data))>>9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_gdma_subt_clut_bist_mode(data) ((0x00000100&(data))>>8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_gamma2_bist_mode(data)       ((0x00000080&(data))>>7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_pcid_bist_mode(data)         ((0x00000040&(data))>>6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_oddma_bist_mode(data)        ((0x00000008&(data))>>3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_od_bist_mode(data)           ((0x00000004&(data))>>2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_ld_con_bist_mode(data)       ((0x00000002&(data))>>1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_MODE_get_ld_spi_con_bist_mode(data)   (0x00000001&(data))

#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE                                  0x18029F84
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_reg_addr                         "0xB8029F84"
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_reg                              0xB8029F84
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_inst_addr                        "0x0001"
#define  set_DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_reg(data)                    (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_reg)=data)
#define  get_DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_reg                          (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_reg))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_vi_bist_done_shift               (21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_duzd_bist_done_shift             (20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pqdc2_bist_done_shift            (19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pqdc1_bist_done_shift            (18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pqc2_bist_done_shift             (17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pqc1_bist_done_shift             (16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_dispbuf_bist_done_shift (12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_dma_buf_bist_done_shift (11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_lb_bist_done_shift     (10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_rbuf_bist_done_shift   (9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_clut_bist_done_shift   (8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gamma2_bist_done_shift           (7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pcid_bist_done_shift             (6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_oddma_bist_done_shift            (3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_od_bist_done_shift               (2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_ld_con_bist_done_shift           (1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_ld_spi_con_bist_done_shift       (0)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_vi_bist_done_mask                (0x00200000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_duzd_bist_done_mask              (0x00100000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pqdc2_bist_done_mask             (0x00080000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pqdc1_bist_done_mask             (0x00040000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pqc2_bist_done_mask              (0x00020000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pqc1_bist_done_mask              (0x00010000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_dispbuf_bist_done_mask (0x00001000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_dma_buf_bist_done_mask (0x00000800)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_lb_bist_done_mask      (0x00000400)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_rbuf_bist_done_mask    (0x00000200)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_clut_bist_done_mask    (0x00000100)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gamma2_bist_done_mask            (0x00000080)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pcid_bist_done_mask              (0x00000040)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_oddma_bist_done_mask             (0x00000008)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_od_bist_done_mask                (0x00000004)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_ld_con_bist_done_mask            (0x00000002)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_ld_spi_con_bist_done_mask        (0x00000001)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_vi_bist_done(data)               (0x00200000&((data)<<21))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_duzd_bist_done(data)             (0x00100000&((data)<<20))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pqdc2_bist_done(data)            (0x00080000&((data)<<19))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pqdc1_bist_done(data)            (0x00040000&((data)<<18))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pqc2_bist_done(data)             (0x00020000&((data)<<17))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pqc1_bist_done(data)             (0x00010000&((data)<<16))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_dispbuf_bist_done(data) (0x00001000&((data)<<12))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_dma_buf_bist_done(data) (0x00000800&((data)<<11))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_lb_bist_done(data)     (0x00000400&((data)<<10))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_rbuf_bist_done(data)   (0x00000200&((data)<<9))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gdma_subt_clut_bist_done(data)   (0x00000100&((data)<<8))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_gamma2_bist_done(data)           (0x00000080&((data)<<7))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_pcid_bist_done(data)             (0x00000040&((data)<<6))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_oddma_bist_done(data)            (0x00000008&((data)<<3))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_od_bist_done(data)               (0x00000004&((data)<<2))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_ld_con_bist_done(data)           (0x00000002&((data)<<1))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_ld_spi_con_bist_done(data)       (0x00000001&(data))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_vi_bist_done(data)           ((0x00200000&(data))>>21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_duzd_bist_done(data)         ((0x00100000&(data))>>20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_pqdc2_bist_done(data)        ((0x00080000&(data))>>19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_pqdc1_bist_done(data)        ((0x00040000&(data))>>18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_pqc2_bist_done(data)         ((0x00020000&(data))>>17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_pqc1_bist_done(data)         ((0x00010000&(data))>>16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_gdma_subt_dispbuf_bist_done(data) ((0x00001000&(data))>>12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_gdma_subt_dma_buf_bist_done(data) ((0x00000800&(data))>>11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_gdma_subt_lb_bist_done(data) ((0x00000400&(data))>>10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_gdma_subt_rbuf_bist_done(data) ((0x00000200&(data))>>9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_gdma_subt_clut_bist_done(data) ((0x00000100&(data))>>8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_gamma2_bist_done(data)       ((0x00000080&(data))>>7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_pcid_bist_done(data)         ((0x00000040&(data))>>6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_oddma_bist_done(data)        ((0x00000008&(data))>>3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_od_bist_done(data)           ((0x00000004&(data))>>2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_ld_con_bist_done(data)       ((0x00000002&(data))>>1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_DONE_get_ld_spi_con_bist_done(data)   (0x00000001&(data))

#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP                            0x18029F88
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_reg_addr                   "0xB8029F88"
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_reg                        0xB8029F88
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_inst_addr                  "0x0002"
#define  set_DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_reg(data)              (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_reg)=data)
#define  get_DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_reg                    (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_reg))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_vi_bist_fail_group_shift   (21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_duzd_bist_fail_group_shift (20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pqdc2_bist_fail_group_shift (19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pqdc1_bist_fail_group_shift (18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pqc2_bist_fail_group_shift (17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pqc1_bist_fail_group_shift (16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_dispbuf_bist_fail_group_shift (12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_dma_buf_bist_fail_group_shift (11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_lb_bist_fail_group_shift (10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_rbuf_bist_fail_group_shift (9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_clut_bist_fail_group_shift (8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gamma2_bist_fail_group_shift (7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pcid_bist_fail_group_shift (6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_oddma_bist_fail_group_shift (3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_od_bist_fail_group_shift   (2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ld_con_bist_fail_group_shift (1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ld_spi_con_bist_fail_group_shift (0)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_vi_bist_fail_group_mask    (0x00200000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_duzd_bist_fail_group_mask  (0x00100000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pqdc2_bist_fail_group_mask (0x00080000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pqdc1_bist_fail_group_mask (0x00040000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pqc2_bist_fail_group_mask  (0x00020000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pqc1_bist_fail_group_mask  (0x00010000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_dispbuf_bist_fail_group_mask (0x00001000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_dma_buf_bist_fail_group_mask (0x00000800)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_lb_bist_fail_group_mask (0x00000400)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_rbuf_bist_fail_group_mask (0x00000200)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_clut_bist_fail_group_mask (0x00000100)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gamma2_bist_fail_group_mask (0x00000080)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pcid_bist_fail_group_mask  (0x00000040)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_oddma_bist_fail_group_mask (0x00000008)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_od_bist_fail_group_mask    (0x00000004)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ld_con_bist_fail_group_mask (0x00000002)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ld_spi_con_bist_fail_group_mask (0x00000001)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_vi_bist_fail_group(data)   (0x00200000&((data)<<21))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_duzd_bist_fail_group(data) (0x00100000&((data)<<20))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pqdc2_bist_fail_group(data) (0x00080000&((data)<<19))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pqdc1_bist_fail_group(data) (0x00040000&((data)<<18))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pqc2_bist_fail_group(data) (0x00020000&((data)<<17))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pqc1_bist_fail_group(data) (0x00010000&((data)<<16))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_dispbuf_bist_fail_group(data) (0x00001000&((data)<<12))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_dma_buf_bist_fail_group(data) (0x00000800&((data)<<11))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_lb_bist_fail_group(data) (0x00000400&((data)<<10))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_rbuf_bist_fail_group(data) (0x00000200&((data)<<9))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gdma_subt_clut_bist_fail_group(data) (0x00000100&((data)<<8))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_gamma2_bist_fail_group(data) (0x00000080&((data)<<7))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_pcid_bist_fail_group(data) (0x00000040&((data)<<6))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_oddma_bist_fail_group(data) (0x00000008&((data)<<3))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_od_bist_fail_group(data)   (0x00000004&((data)<<2))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ld_con_bist_fail_group(data) (0x00000002&((data)<<1))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_ld_spi_con_bist_fail_group(data) (0x00000001&(data))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_vi_bist_fail_group(data) ((0x00200000&(data))>>21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_duzd_bist_fail_group(data) ((0x00100000&(data))>>20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_pqdc2_bist_fail_group(data) ((0x00080000&(data))>>19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_pqdc1_bist_fail_group(data) ((0x00040000&(data))>>18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_pqc2_bist_fail_group(data) ((0x00020000&(data))>>17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_pqc1_bist_fail_group(data) ((0x00010000&(data))>>16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_gdma_subt_dispbuf_bist_fail_group(data) ((0x00001000&(data))>>12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_gdma_subt_dma_buf_bist_fail_group(data) ((0x00000800&(data))>>11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_gdma_subt_lb_bist_fail_group(data) ((0x00000400&(data))>>10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_gdma_subt_rbuf_bist_fail_group(data) ((0x00000200&(data))>>9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_gdma_subt_clut_bist_fail_group(data) ((0x00000100&(data))>>8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_gamma2_bist_fail_group(data) ((0x00000080&(data))>>7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_pcid_bist_fail_group(data) ((0x00000040&(data))>>6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_oddma_bist_fail_group(data) ((0x00000008&(data))>>3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_od_bist_fail_group(data) ((0x00000004&(data))>>2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_ld_con_bist_fail_group(data) ((0x00000002&(data))>>1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_BIST_FAIL_GROUP_get_ld_spi_con_bist_fail_group(data) (0x00000001&(data))

#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE                                   0x18029F8C
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_reg_addr                          "0xB8029F8C"
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_reg                               0xB8029F8C
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_inst_addr                         "0x0003"
#define  set_DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_reg(data)                     (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_reg)=data)
#define  get_DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_reg                           (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_reg))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_vi_drf_mode_shift                 (21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_duzd_drf_mode_shift               (20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pqdc2_drf_bist_mode_shift         (19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pqdc1_drf_bist_mode_shift         (18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pqc2_drf_bist_mode_shift          (17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pqc1_drf_bist_mode_shift          (16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_dispbuf_drf_mode_shift  (12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_dma_buf_drf_mode_shift  (11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_lb_drf_mode_shift       (10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_rbuf_drf_mode_shift     (9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_clut_drf_mode_shift     (8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gamma2_drf_mode_shift             (7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pcid_drf_mode_shift               (6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_oddma_drf_mode_shift              (3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_od_drf_mode_shift                 (2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_ld_con_drf_mode_shift             (1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_ld_spi_con_drf_mode_shift         (0)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_vi_drf_mode_mask                  (0x00200000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_duzd_drf_mode_mask                (0x00100000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pqdc2_drf_bist_mode_mask          (0x00080000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pqdc1_drf_bist_mode_mask          (0x00040000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pqc2_drf_bist_mode_mask           (0x00020000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pqc1_drf_bist_mode_mask           (0x00010000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_dispbuf_drf_mode_mask   (0x00001000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_dma_buf_drf_mode_mask   (0x00000800)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_lb_drf_mode_mask        (0x00000400)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_rbuf_drf_mode_mask      (0x00000200)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_clut_drf_mode_mask      (0x00000100)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gamma2_drf_mode_mask              (0x00000080)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pcid_drf_mode_mask                (0x00000040)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_oddma_drf_mode_mask               (0x00000008)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_od_drf_mode_mask                  (0x00000004)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_ld_con_drf_mode_mask              (0x00000002)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_ld_spi_con_drf_mode_mask          (0x00000001)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_vi_drf_mode(data)                 (0x00200000&((data)<<21))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_duzd_drf_mode(data)               (0x00100000&((data)<<20))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pqdc2_drf_bist_mode(data)         (0x00080000&((data)<<19))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pqdc1_drf_bist_mode(data)         (0x00040000&((data)<<18))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pqc2_drf_bist_mode(data)          (0x00020000&((data)<<17))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pqc1_drf_bist_mode(data)          (0x00010000&((data)<<16))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_dispbuf_drf_mode(data)  (0x00001000&((data)<<12))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_dma_buf_drf_mode(data)  (0x00000800&((data)<<11))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_lb_drf_mode(data)       (0x00000400&((data)<<10))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_rbuf_drf_mode(data)     (0x00000200&((data)<<9))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gdma_subt_clut_drf_mode(data)     (0x00000100&((data)<<8))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_gamma2_drf_mode(data)             (0x00000080&((data)<<7))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_pcid_drf_mode(data)               (0x00000040&((data)<<6))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_oddma_drf_mode(data)              (0x00000008&((data)<<3))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_od_drf_mode(data)                 (0x00000004&((data)<<2))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_ld_con_drf_mode(data)             (0x00000002&((data)<<1))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_ld_spi_con_drf_mode(data)         (0x00000001&(data))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_vi_drf_mode(data)             ((0x00200000&(data))>>21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_duzd_drf_mode(data)           ((0x00100000&(data))>>20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_pqdc2_drf_bist_mode(data)     ((0x00080000&(data))>>19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_pqdc1_drf_bist_mode(data)     ((0x00040000&(data))>>18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_pqc2_drf_bist_mode(data)      ((0x00020000&(data))>>17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_pqc1_drf_bist_mode(data)      ((0x00010000&(data))>>16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_gdma_subt_dispbuf_drf_mode(data) ((0x00001000&(data))>>12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_gdma_subt_dma_buf_drf_mode(data) ((0x00000800&(data))>>11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_gdma_subt_lb_drf_mode(data)   ((0x00000400&(data))>>10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_gdma_subt_rbuf_drf_mode(data) ((0x00000200&(data))>>9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_gdma_subt_clut_drf_mode(data) ((0x00000100&(data))>>8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_gamma2_drf_mode(data)         ((0x00000080&(data))>>7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_pcid_drf_mode(data)           ((0x00000040&(data))>>6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_oddma_drf_mode(data)          ((0x00000008&(data))>>3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_od_drf_mode(data)             ((0x00000004&(data))>>2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_ld_con_drf_mode(data)         ((0x00000002&(data))>>1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_MODE_get_ld_spi_con_drf_mode(data)     (0x00000001&(data))

#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME                                 0x18029F90
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_reg_addr                        "0xB8029F90"
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_reg                             0xB8029F90
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_inst_addr                       "0x0004"
#define  set_DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_reg(data)                   (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_reg)=data)
#define  get_DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_reg                         (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_reg))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_vi_drf_resume_shift             (21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_duzd_drf_resume_shift           (20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pqdc2_drf_test_resume_shift     (19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pqdc1_drf_test_resume_shift     (18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pqc2_drf_test_resume_shift      (17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pqc1_drf_test_resume_shift      (16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_dispbuf_drf_resume_shift (12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_dma_buf_drf_resume_shift (11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_lb_drf_resume_shift   (10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_rbuf_drf_resume_shift (9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_clut_drf_resume_shift (8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gamma2_drf_resume_shift         (7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pcid_drf_resume_shift           (6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_oddma_drf_resume_shift          (3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_od_drf_resume_shift             (2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_ld_con_drf_resume_shift         (1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_ld_spi_con_drf_resume_shift     (0)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_vi_drf_resume_mask              (0x00200000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_duzd_drf_resume_mask            (0x00100000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pqdc2_drf_test_resume_mask      (0x00080000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pqdc1_drf_test_resume_mask      (0x00040000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pqc2_drf_test_resume_mask       (0x00020000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pqc1_drf_test_resume_mask       (0x00010000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_dispbuf_drf_resume_mask (0x00001000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_dma_buf_drf_resume_mask (0x00000800)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_lb_drf_resume_mask    (0x00000400)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_rbuf_drf_resume_mask  (0x00000200)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_clut_drf_resume_mask  (0x00000100)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gamma2_drf_resume_mask          (0x00000080)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pcid_drf_resume_mask            (0x00000040)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_oddma_drf_resume_mask           (0x00000008)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_od_drf_resume_mask              (0x00000004)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_ld_con_drf_resume_mask          (0x00000002)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_ld_spi_con_drf_resume_mask      (0x00000001)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_vi_drf_resume(data)             (0x00200000&((data)<<21))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_duzd_drf_resume(data)           (0x00100000&((data)<<20))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pqdc2_drf_test_resume(data)     (0x00080000&((data)<<19))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pqdc1_drf_test_resume(data)     (0x00040000&((data)<<18))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pqc2_drf_test_resume(data)      (0x00020000&((data)<<17))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pqc1_drf_test_resume(data)      (0x00010000&((data)<<16))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_dispbuf_drf_resume(data) (0x00001000&((data)<<12))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_dma_buf_drf_resume(data) (0x00000800&((data)<<11))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_lb_drf_resume(data)   (0x00000400&((data)<<10))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_rbuf_drf_resume(data) (0x00000200&((data)<<9))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gdma_subt_clut_drf_resume(data) (0x00000100&((data)<<8))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_gamma2_drf_resume(data)         (0x00000080&((data)<<7))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_pcid_drf_resume(data)           (0x00000040&((data)<<6))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_oddma_drf_resume(data)          (0x00000008&((data)<<3))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_od_drf_resume(data)             (0x00000004&((data)<<2))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_ld_con_drf_resume(data)         (0x00000002&((data)<<1))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_ld_spi_con_drf_resume(data)     (0x00000001&(data))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_vi_drf_resume(data)         ((0x00200000&(data))>>21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_duzd_drf_resume(data)       ((0x00100000&(data))>>20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_pqdc2_drf_test_resume(data) ((0x00080000&(data))>>19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_pqdc1_drf_test_resume(data) ((0x00040000&(data))>>18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_pqc2_drf_test_resume(data)  ((0x00020000&(data))>>17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_pqc1_drf_test_resume(data)  ((0x00010000&(data))>>16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_gdma_subt_dispbuf_drf_resume(data) ((0x00001000&(data))>>12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_gdma_subt_dma_buf_drf_resume(data) ((0x00000800&(data))>>11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_gdma_subt_lb_drf_resume(data) ((0x00000400&(data))>>10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_gdma_subt_rbuf_drf_resume(data) ((0x00000200&(data))>>9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_gdma_subt_clut_drf_resume(data) ((0x00000100&(data))>>8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_gamma2_drf_resume(data)     ((0x00000080&(data))>>7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_pcid_drf_resume(data)       ((0x00000040&(data))>>6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_oddma_drf_resume(data)      ((0x00000008&(data))>>3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_od_drf_resume(data)         ((0x00000004&(data))>>2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_ld_con_drf_resume(data)     ((0x00000002&(data))>>1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_RESUME_get_ld_spi_con_drf_resume(data) (0x00000001&(data))

#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE                                   0x18029F94
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_reg_addr                          "0xB8029F94"
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_reg                               0xB8029F94
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_inst_addr                         "0x0005"
#define  set_DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_reg(data)                     (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_reg)=data)
#define  get_DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_reg                           (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_reg))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_vi_drf_done_shift                 (21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_duzd_drf_done_shift               (20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pqdc2_drf_bist_done_shift         (19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pqdc1_drf_bist_done_shift         (18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pqc2_drf_bist_done_shift          (17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pqc1_drf_bist_done_shift          (16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_dispbuf_drf_done_shift  (12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_dma_buf_drf_done_shift  (11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_lb_drf_done_shift       (10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_rbuf_drf_done_shift     (9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_clut_drf_done_shift     (8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gamma2_drf_done_shift             (7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pcid_drf_done_shift               (6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_oddma_drf_done_shift              (3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_od_drf_done_shift                 (2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_ld_con_drf_done_shift             (1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_ld_spi_con_drf_done_shift         (0)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_vi_drf_done_mask                  (0x00200000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_duzd_drf_done_mask                (0x00100000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pqdc2_drf_bist_done_mask          (0x00080000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pqdc1_drf_bist_done_mask          (0x00040000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pqc2_drf_bist_done_mask           (0x00020000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pqc1_drf_bist_done_mask           (0x00010000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_dispbuf_drf_done_mask   (0x00001000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_dma_buf_drf_done_mask   (0x00000800)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_lb_drf_done_mask        (0x00000400)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_rbuf_drf_done_mask      (0x00000200)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_clut_drf_done_mask      (0x00000100)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gamma2_drf_done_mask              (0x00000080)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pcid_drf_done_mask                (0x00000040)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_oddma_drf_done_mask               (0x00000008)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_od_drf_done_mask                  (0x00000004)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_ld_con_drf_done_mask              (0x00000002)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_ld_spi_con_drf_done_mask          (0x00000001)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_vi_drf_done(data)                 (0x00200000&((data)<<21))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_duzd_drf_done(data)               (0x00100000&((data)<<20))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pqdc2_drf_bist_done(data)         (0x00080000&((data)<<19))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pqdc1_drf_bist_done(data)         (0x00040000&((data)<<18))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pqc2_drf_bist_done(data)          (0x00020000&((data)<<17))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pqc1_drf_bist_done(data)          (0x00010000&((data)<<16))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_dispbuf_drf_done(data)  (0x00001000&((data)<<12))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_dma_buf_drf_done(data)  (0x00000800&((data)<<11))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_lb_drf_done(data)       (0x00000400&((data)<<10))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_rbuf_drf_done(data)     (0x00000200&((data)<<9))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gdma_subt_clut_drf_done(data)     (0x00000100&((data)<<8))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_gamma2_drf_done(data)             (0x00000080&((data)<<7))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_pcid_drf_done(data)               (0x00000040&((data)<<6))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_oddma_drf_done(data)              (0x00000008&((data)<<3))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_od_drf_done(data)                 (0x00000004&((data)<<2))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_ld_con_drf_done(data)             (0x00000002&((data)<<1))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_ld_spi_con_drf_done(data)         (0x00000001&(data))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_vi_drf_done(data)             ((0x00200000&(data))>>21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_duzd_drf_done(data)           ((0x00100000&(data))>>20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_pqdc2_drf_bist_done(data)     ((0x00080000&(data))>>19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_pqdc1_drf_bist_done(data)     ((0x00040000&(data))>>18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_pqc2_drf_bist_done(data)      ((0x00020000&(data))>>17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_pqc1_drf_bist_done(data)      ((0x00010000&(data))>>16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_gdma_subt_dispbuf_drf_done(data) ((0x00001000&(data))>>12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_gdma_subt_dma_buf_drf_done(data) ((0x00000800&(data))>>11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_gdma_subt_lb_drf_done(data)   ((0x00000400&(data))>>10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_gdma_subt_rbuf_drf_done(data) ((0x00000200&(data))>>9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_gdma_subt_clut_drf_done(data) ((0x00000100&(data))>>8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_gamma2_drf_done(data)         ((0x00000080&(data))>>7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_pcid_drf_done(data)           ((0x00000040&(data))>>6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_oddma_drf_done(data)          ((0x00000008&(data))>>3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_od_drf_done(data)             ((0x00000004&(data))>>2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_ld_con_drf_done(data)         ((0x00000002&(data))>>1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_DONE_get_ld_spi_con_drf_done(data)     (0x00000001&(data))

#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE                                  0x18029F98
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_reg_addr                         "0xB8029F98"
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_reg                              0xB8029F98
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_inst_addr                        "0x0006"
#define  set_DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_reg(data)                    (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_reg)=data)
#define  get_DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_reg                          (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_reg))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_vi_drf_pause_shift               (21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_duzd_drf_pause_shift             (20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pqdc2_drf_start_pause_shift      (19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pqdc1_drf_start_pause_shift      (18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pqc2_drf_start_pause_shift       (17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pqc1_drf_start_pause_shift       (16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_dispbuf_drf_pause_shift (12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_dma_buf_drf_pause_shift (11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_lb_drf_pause_shift     (10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_rbuf_drf_pause_shift   (9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_clut_drf_pause_shift   (8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gamma2_drf_pause_shift           (7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pcid_drf_pause_shift             (6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_oddma_drf_pause_shift            (3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_od_drf_pause_shift               (2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_ld_con_drf_pause_shift           (1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_ld_spi_con_drf_pause_shift       (0)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_vi_drf_pause_mask                (0x00200000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_duzd_drf_pause_mask              (0x00100000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pqdc2_drf_start_pause_mask       (0x00080000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pqdc1_drf_start_pause_mask       (0x00040000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pqc2_drf_start_pause_mask        (0x00020000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pqc1_drf_start_pause_mask        (0x00010000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_dispbuf_drf_pause_mask (0x00001000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_dma_buf_drf_pause_mask (0x00000800)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_lb_drf_pause_mask      (0x00000400)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_rbuf_drf_pause_mask    (0x00000200)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_clut_drf_pause_mask    (0x00000100)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gamma2_drf_pause_mask            (0x00000080)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pcid_drf_pause_mask              (0x00000040)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_oddma_drf_pause_mask             (0x00000008)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_od_drf_pause_mask                (0x00000004)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_ld_con_drf_pause_mask            (0x00000002)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_ld_spi_con_drf_pause_mask        (0x00000001)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_vi_drf_pause(data)               (0x00200000&((data)<<21))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_duzd_drf_pause(data)             (0x00100000&((data)<<20))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pqdc2_drf_start_pause(data)      (0x00080000&((data)<<19))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pqdc1_drf_start_pause(data)      (0x00040000&((data)<<18))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pqc2_drf_start_pause(data)       (0x00020000&((data)<<17))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pqc1_drf_start_pause(data)       (0x00010000&((data)<<16))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_dispbuf_drf_pause(data) (0x00001000&((data)<<12))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_dma_buf_drf_pause(data) (0x00000800&((data)<<11))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_lb_drf_pause(data)     (0x00000400&((data)<<10))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_rbuf_drf_pause(data)   (0x00000200&((data)<<9))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gdma_subt_clut_drf_pause(data)   (0x00000100&((data)<<8))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_gamma2_drf_pause(data)           (0x00000080&((data)<<7))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_pcid_drf_pause(data)             (0x00000040&((data)<<6))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_oddma_drf_pause(data)            (0x00000008&((data)<<3))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_od_drf_pause(data)               (0x00000004&((data)<<2))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_ld_con_drf_pause(data)           (0x00000002&((data)<<1))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_ld_spi_con_drf_pause(data)       (0x00000001&(data))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_vi_drf_pause(data)           ((0x00200000&(data))>>21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_duzd_drf_pause(data)         ((0x00100000&(data))>>20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_pqdc2_drf_start_pause(data)  ((0x00080000&(data))>>19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_pqdc1_drf_start_pause(data)  ((0x00040000&(data))>>18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_pqc2_drf_start_pause(data)   ((0x00020000&(data))>>17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_pqc1_drf_start_pause(data)   ((0x00010000&(data))>>16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_gdma_subt_dispbuf_drf_pause(data) ((0x00001000&(data))>>12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_gdma_subt_dma_buf_drf_pause(data) ((0x00000800&(data))>>11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_gdma_subt_lb_drf_pause(data) ((0x00000400&(data))>>10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_gdma_subt_rbuf_drf_pause(data) ((0x00000200&(data))>>9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_gdma_subt_clut_drf_pause(data) ((0x00000100&(data))>>8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_gamma2_drf_pause(data)       ((0x00000080&(data))>>7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_pcid_drf_pause(data)         ((0x00000040&(data))>>6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_oddma_drf_pause(data)        ((0x00000008&(data))>>3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_od_drf_pause(data)           ((0x00000004&(data))>>2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_ld_con_drf_pause(data)       ((0x00000002&(data))>>1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_PAUSE_get_ld_spi_con_drf_pause(data)   (0x00000001&(data))

#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP                             0x18029F9C
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_reg_addr                    "0xB8029F9C"
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_reg                         0xB8029F9C
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_inst_addr                   "0x0007"
#define  set_DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_reg(data)               (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_reg)=data)
#define  get_DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_reg                     (*((volatile unsigned int*)DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_reg))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_vi_drf_fail_group_shift     (21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_duzd_drf_fail_group_shift   (20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pqdc2_drf_fail_group_shift  (19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pqdc1_drf_fail_group_shift  (18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pqc2_drf_fail_group_shift   (17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pqc1_drf_fail_group_shift   (16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_dispbuf_drf_fail_group_shift (12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_dma_buf_drf_fail_group_shift (11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_lb_drf_fail_group_shift (10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_rbuf_drf_fail_group_shift (9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_clut_drf_fail_group_shift (8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gamma2_drf_fail_group_shift (7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pcid_drf_fail_group_shift   (6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_oddma_drf_fail_group_shift  (3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_od_drf_fail_group_shift     (2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ld_con_drf_fail_group_shift (1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ld_spi_con_drf_fail_group_shift (0)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_vi_drf_fail_group_mask      (0x00200000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_duzd_drf_fail_group_mask    (0x00100000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pqdc2_drf_fail_group_mask   (0x00080000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pqdc1_drf_fail_group_mask   (0x00040000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pqc2_drf_fail_group_mask    (0x00020000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pqc1_drf_fail_group_mask    (0x00010000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_dispbuf_drf_fail_group_mask (0x00001000)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_dma_buf_drf_fail_group_mask (0x00000800)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_lb_drf_fail_group_mask (0x00000400)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_rbuf_drf_fail_group_mask (0x00000200)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_clut_drf_fail_group_mask (0x00000100)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gamma2_drf_fail_group_mask  (0x00000080)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pcid_drf_fail_group_mask    (0x00000040)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_oddma_drf_fail_group_mask   (0x00000008)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_od_drf_fail_group_mask      (0x00000004)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ld_con_drf_fail_group_mask  (0x00000002)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ld_spi_con_drf_fail_group_mask (0x00000001)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_vi_drf_fail_group(data)     (0x00200000&((data)<<21))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_duzd_drf_fail_group(data)   (0x00100000&((data)<<20))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pqdc2_drf_fail_group(data)  (0x00080000&((data)<<19))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pqdc1_drf_fail_group(data)  (0x00040000&((data)<<18))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pqc2_drf_fail_group(data)   (0x00020000&((data)<<17))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pqc1_drf_fail_group(data)   (0x00010000&((data)<<16))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_dispbuf_drf_fail_group(data) (0x00001000&((data)<<12))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_dma_buf_drf_fail_group(data) (0x00000800&((data)<<11))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_lb_drf_fail_group(data) (0x00000400&((data)<<10))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_rbuf_drf_fail_group(data) (0x00000200&((data)<<9))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gdma_subt_clut_drf_fail_group(data) (0x00000100&((data)<<8))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_gamma2_drf_fail_group(data) (0x00000080&((data)<<7))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_pcid_drf_fail_group(data)   (0x00000040&((data)<<6))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_oddma_drf_fail_group(data)  (0x00000008&((data)<<3))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_od_drf_fail_group(data)     (0x00000004&((data)<<2))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ld_con_drf_fail_group(data) (0x00000002&((data)<<1))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_ld_spi_con_drf_fail_group(data) (0x00000001&(data))
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_vi_drf_fail_group(data) ((0x00200000&(data))>>21)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_duzd_drf_fail_group(data) ((0x00100000&(data))>>20)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_pqdc2_drf_fail_group(data) ((0x00080000&(data))>>19)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_pqdc1_drf_fail_group(data) ((0x00040000&(data))>>18)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_pqc2_drf_fail_group(data) ((0x00020000&(data))>>17)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_pqc1_drf_fail_group(data) ((0x00010000&(data))>>16)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_gdma_subt_dispbuf_drf_fail_group(data) ((0x00001000&(data))>>12)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_gdma_subt_dma_buf_drf_fail_group(data) ((0x00000800&(data))>>11)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_gdma_subt_lb_drf_fail_group(data) ((0x00000400&(data))>>10)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_gdma_subt_rbuf_drf_fail_group(data) ((0x00000200&(data))>>9)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_gdma_subt_clut_drf_fail_group(data) ((0x00000100&(data))>>8)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_gamma2_drf_fail_group(data) ((0x00000080&(data))>>7)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_pcid_drf_fail_group(data) ((0x00000040&(data))>>6)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_oddma_drf_fail_group(data) ((0x00000008&(data))>>3)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_od_drf_fail_group(data) ((0x00000004&(data))>>2)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_ld_con_drf_fail_group(data) ((0x00000002&(data))>>1)
#define  DISPD_WI_OSD_BIST_BISR_DISPD_DRF_FAIL_GROUP_get_ld_spi_con_drf_fail_group(data) (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DISPD_WI_OSD_BIST_BISR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  vi_bist_mode:1;
        RBus_UInt32  duzd_bist_mode:1;
        RBus_UInt32  pqdc2_bist_mode:1;
        RBus_UInt32  pqdc1_bist_mode:1;
        RBus_UInt32  pqc2_bist_mode:1;
        RBus_UInt32  pqc1_bist_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  gdma_subt_dispbuf_bist_mode:1;
        RBus_UInt32  gdma_subt_dma_buf_bist_mode:1;
        RBus_UInt32  gdma_subt_lb_bist_mode:1;
        RBus_UInt32  gdma_subt_rbuf_bist_mode:1;
        RBus_UInt32  gdma_subt_clut_bist_mode:1;
        RBus_UInt32  gamma2_bist_mode:1;
        RBus_UInt32  pcid_bist_mode:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  oddma_bist_mode:1;
        RBus_UInt32  od_bist_mode:1;
        RBus_UInt32  ld_con_bist_mode:1;
        RBus_UInt32  ld_spi_con_bist_mode:1;
    };
}dispd_wi_osd_bist_bisr_dispd_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  vi_bist_done:1;
        RBus_UInt32  duzd_bist_done:1;
        RBus_UInt32  pqdc2_bist_done:1;
        RBus_UInt32  pqdc1_bist_done:1;
        RBus_UInt32  pqc2_bist_done:1;
        RBus_UInt32  pqc1_bist_done:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  gdma_subt_dispbuf_bist_done:1;
        RBus_UInt32  gdma_subt_dma_buf_bist_done:1;
        RBus_UInt32  gdma_subt_lb_bist_done:1;
        RBus_UInt32  gdma_subt_rbuf_bist_done:1;
        RBus_UInt32  gdma_subt_clut_bist_done:1;
        RBus_UInt32  gamma2_bist_done:1;
        RBus_UInt32  pcid_bist_done:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  oddma_bist_done:1;
        RBus_UInt32  od_bist_done:1;
        RBus_UInt32  ld_con_bist_done:1;
        RBus_UInt32  ld_spi_con_bist_done:1;
    };
}dispd_wi_osd_bist_bisr_dispd_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  vi_bist_fail_group:1;
        RBus_UInt32  duzd_bist_fail_group:1;
        RBus_UInt32  pqdc2_bist_fail_group:1;
        RBus_UInt32  pqdc1_bist_fail_group:1;
        RBus_UInt32  pqc2_bist_fail_group:1;
        RBus_UInt32  pqc1_bist_fail_group:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  gdma_subt_dispbuf_bist_fail_group:1;
        RBus_UInt32  gdma_subt_dma_buf_bist_fail_group:1;
        RBus_UInt32  gdma_subt_lb_bist_fail_group:1;
        RBus_UInt32  gdma_subt_rbuf_bist_fail_group:1;
        RBus_UInt32  gdma_subt_clut_bist_fail_group:1;
        RBus_UInt32  gamma2_bist_fail_group:1;
        RBus_UInt32  pcid_bist_fail_group:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  oddma_bist_fail_group:1;
        RBus_UInt32  od_bist_fail_group:1;
        RBus_UInt32  ld_con_bist_fail_group:1;
        RBus_UInt32  ld_spi_con_bist_fail_group:1;
    };
}dispd_wi_osd_bist_bisr_dispd_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  vi_drf_mode:1;
        RBus_UInt32  duzd_drf_mode:1;
        RBus_UInt32  pqdc2_drf_bist_mode:1;
        RBus_UInt32  pqdc1_drf_bist_mode:1;
        RBus_UInt32  pqc2_drf_bist_mode:1;
        RBus_UInt32  pqc1_drf_bist_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  gdma_subt_dispbuf_drf_mode:1;
        RBus_UInt32  gdma_subt_dma_buf_drf_mode:1;
        RBus_UInt32  gdma_subt_lb_drf_mode:1;
        RBus_UInt32  gdma_subt_rbuf_drf_mode:1;
        RBus_UInt32  gdma_subt_clut_drf_mode:1;
        RBus_UInt32  gamma2_drf_mode:1;
        RBus_UInt32  pcid_drf_mode:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  oddma_drf_mode:1;
        RBus_UInt32  od_drf_mode:1;
        RBus_UInt32  ld_con_drf_mode:1;
        RBus_UInt32  ld_spi_con_drf_mode:1;
    };
}dispd_wi_osd_bist_bisr_dispd_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  vi_drf_resume:1;
        RBus_UInt32  duzd_drf_resume:1;
        RBus_UInt32  pqdc2_drf_test_resume:1;
        RBus_UInt32  pqdc1_drf_test_resume:1;
        RBus_UInt32  pqc2_drf_test_resume:1;
        RBus_UInt32  pqc1_drf_test_resume:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  gdma_subt_dispbuf_drf_resume:1;
        RBus_UInt32  gdma_subt_dma_buf_drf_resume:1;
        RBus_UInt32  gdma_subt_lb_drf_resume:1;
        RBus_UInt32  gdma_subt_rbuf_drf_resume:1;
        RBus_UInt32  gdma_subt_clut_drf_resume:1;
        RBus_UInt32  gamma2_drf_resume:1;
        RBus_UInt32  pcid_drf_resume:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  oddma_drf_resume:1;
        RBus_UInt32  od_drf_resume:1;
        RBus_UInt32  ld_con_drf_resume:1;
        RBus_UInt32  ld_spi_con_drf_resume:1;
    };
}dispd_wi_osd_bist_bisr_dispd_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  vi_drf_done:1;
        RBus_UInt32  duzd_drf_done:1;
        RBus_UInt32  pqdc2_drf_bist_done:1;
        RBus_UInt32  pqdc1_drf_bist_done:1;
        RBus_UInt32  pqc2_drf_bist_done:1;
        RBus_UInt32  pqc1_drf_bist_done:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  gdma_subt_dispbuf_drf_done:1;
        RBus_UInt32  gdma_subt_dma_buf_drf_done:1;
        RBus_UInt32  gdma_subt_lb_drf_done:1;
        RBus_UInt32  gdma_subt_rbuf_drf_done:1;
        RBus_UInt32  gdma_subt_clut_drf_done:1;
        RBus_UInt32  gamma2_drf_done:1;
        RBus_UInt32  pcid_drf_done:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  oddma_drf_done:1;
        RBus_UInt32  od_drf_done:1;
        RBus_UInt32  ld_con_drf_done:1;
        RBus_UInt32  ld_spi_con_drf_done:1;
    };
}dispd_wi_osd_bist_bisr_dispd_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  vi_drf_pause:1;
        RBus_UInt32  duzd_drf_pause:1;
        RBus_UInt32  pqdc2_drf_start_pause:1;
        RBus_UInt32  pqdc1_drf_start_pause:1;
        RBus_UInt32  pqc2_drf_start_pause:1;
        RBus_UInt32  pqc1_drf_start_pause:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  gdma_subt_dispbuf_drf_pause:1;
        RBus_UInt32  gdma_subt_dma_buf_drf_pause:1;
        RBus_UInt32  gdma_subt_lb_drf_pause:1;
        RBus_UInt32  gdma_subt_rbuf_drf_pause:1;
        RBus_UInt32  gdma_subt_clut_drf_pause:1;
        RBus_UInt32  gamma2_drf_pause:1;
        RBus_UInt32  pcid_drf_pause:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  oddma_drf_pause:1;
        RBus_UInt32  od_drf_pause:1;
        RBus_UInt32  ld_con_drf_pause:1;
        RBus_UInt32  ld_spi_con_drf_pause:1;
    };
}dispd_wi_osd_bist_bisr_dispd_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  vi_drf_fail_group:1;
        RBus_UInt32  duzd_drf_fail_group:1;
        RBus_UInt32  pqdc2_drf_fail_group:1;
        RBus_UInt32  pqdc1_drf_fail_group:1;
        RBus_UInt32  pqc2_drf_fail_group:1;
        RBus_UInt32  pqc1_drf_fail_group:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  gdma_subt_dispbuf_drf_fail_group:1;
        RBus_UInt32  gdma_subt_dma_buf_drf_fail_group:1;
        RBus_UInt32  gdma_subt_lb_drf_fail_group:1;
        RBus_UInt32  gdma_subt_rbuf_drf_fail_group:1;
        RBus_UInt32  gdma_subt_clut_drf_fail_group:1;
        RBus_UInt32  gamma2_drf_fail_group:1;
        RBus_UInt32  pcid_drf_fail_group:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  oddma_drf_fail_group:1;
        RBus_UInt32  od_drf_fail_group:1;
        RBus_UInt32  ld_con_drf_fail_group:1;
        RBus_UInt32  ld_spi_con_drf_fail_group:1;
    };
}dispd_wi_osd_bist_bisr_dispd_drf_fail_group_RBUS;

#else //apply LITTLE_ENDIAN

//======DISPD_WI_OSD_BIST_BISR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spi_con_bist_mode:1;
        RBus_UInt32  ld_con_bist_mode:1;
        RBus_UInt32  od_bist_mode:1;
        RBus_UInt32  oddma_bist_mode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pcid_bist_mode:1;
        RBus_UInt32  gamma2_bist_mode:1;
        RBus_UInt32  gdma_subt_clut_bist_mode:1;
        RBus_UInt32  gdma_subt_rbuf_bist_mode:1;
        RBus_UInt32  gdma_subt_lb_bist_mode:1;
        RBus_UInt32  gdma_subt_dma_buf_bist_mode:1;
        RBus_UInt32  gdma_subt_dispbuf_bist_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  pqc1_bist_mode:1;
        RBus_UInt32  pqc2_bist_mode:1;
        RBus_UInt32  pqdc1_bist_mode:1;
        RBus_UInt32  pqdc2_bist_mode:1;
        RBus_UInt32  duzd_bist_mode:1;
        RBus_UInt32  vi_bist_mode:1;
        RBus_UInt32  res6:10;
    };
}dispd_wi_osd_bist_bisr_dispd_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spi_con_bist_done:1;
        RBus_UInt32  ld_con_bist_done:1;
        RBus_UInt32  od_bist_done:1;
        RBus_UInt32  oddma_bist_done:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pcid_bist_done:1;
        RBus_UInt32  gamma2_bist_done:1;
        RBus_UInt32  gdma_subt_clut_bist_done:1;
        RBus_UInt32  gdma_subt_rbuf_bist_done:1;
        RBus_UInt32  gdma_subt_lb_bist_done:1;
        RBus_UInt32  gdma_subt_dma_buf_bist_done:1;
        RBus_UInt32  gdma_subt_dispbuf_bist_done:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  pqc1_bist_done:1;
        RBus_UInt32  pqc2_bist_done:1;
        RBus_UInt32  pqdc1_bist_done:1;
        RBus_UInt32  pqdc2_bist_done:1;
        RBus_UInt32  duzd_bist_done:1;
        RBus_UInt32  vi_bist_done:1;
        RBus_UInt32  res6:10;
    };
}dispd_wi_osd_bist_bisr_dispd_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spi_con_bist_fail_group:1;
        RBus_UInt32  ld_con_bist_fail_group:1;
        RBus_UInt32  od_bist_fail_group:1;
        RBus_UInt32  oddma_bist_fail_group:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pcid_bist_fail_group:1;
        RBus_UInt32  gamma2_bist_fail_group:1;
        RBus_UInt32  gdma_subt_clut_bist_fail_group:1;
        RBus_UInt32  gdma_subt_rbuf_bist_fail_group:1;
        RBus_UInt32  gdma_subt_lb_bist_fail_group:1;
        RBus_UInt32  gdma_subt_dma_buf_bist_fail_group:1;
        RBus_UInt32  gdma_subt_dispbuf_bist_fail_group:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  pqc1_bist_fail_group:1;
        RBus_UInt32  pqc2_bist_fail_group:1;
        RBus_UInt32  pqdc1_bist_fail_group:1;
        RBus_UInt32  pqdc2_bist_fail_group:1;
        RBus_UInt32  duzd_bist_fail_group:1;
        RBus_UInt32  vi_bist_fail_group:1;
        RBus_UInt32  res6:10;
    };
}dispd_wi_osd_bist_bisr_dispd_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spi_con_drf_mode:1;
        RBus_UInt32  ld_con_drf_mode:1;
        RBus_UInt32  od_drf_mode:1;
        RBus_UInt32  oddma_drf_mode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pcid_drf_mode:1;
        RBus_UInt32  gamma2_drf_mode:1;
        RBus_UInt32  gdma_subt_clut_drf_mode:1;
        RBus_UInt32  gdma_subt_rbuf_drf_mode:1;
        RBus_UInt32  gdma_subt_lb_drf_mode:1;
        RBus_UInt32  gdma_subt_dma_buf_drf_mode:1;
        RBus_UInt32  gdma_subt_dispbuf_drf_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  pqc1_drf_bist_mode:1;
        RBus_UInt32  pqc2_drf_bist_mode:1;
        RBus_UInt32  pqdc1_drf_bist_mode:1;
        RBus_UInt32  pqdc2_drf_bist_mode:1;
        RBus_UInt32  duzd_drf_mode:1;
        RBus_UInt32  vi_drf_mode:1;
        RBus_UInt32  res6:10;
    };
}dispd_wi_osd_bist_bisr_dispd_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spi_con_drf_resume:1;
        RBus_UInt32  ld_con_drf_resume:1;
        RBus_UInt32  od_drf_resume:1;
        RBus_UInt32  oddma_drf_resume:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pcid_drf_resume:1;
        RBus_UInt32  gamma2_drf_resume:1;
        RBus_UInt32  gdma_subt_clut_drf_resume:1;
        RBus_UInt32  gdma_subt_rbuf_drf_resume:1;
        RBus_UInt32  gdma_subt_lb_drf_resume:1;
        RBus_UInt32  gdma_subt_dma_buf_drf_resume:1;
        RBus_UInt32  gdma_subt_dispbuf_drf_resume:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  pqc1_drf_test_resume:1;
        RBus_UInt32  pqc2_drf_test_resume:1;
        RBus_UInt32  pqdc1_drf_test_resume:1;
        RBus_UInt32  pqdc2_drf_test_resume:1;
        RBus_UInt32  duzd_drf_resume:1;
        RBus_UInt32  vi_drf_resume:1;
        RBus_UInt32  res6:10;
    };
}dispd_wi_osd_bist_bisr_dispd_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spi_con_drf_done:1;
        RBus_UInt32  ld_con_drf_done:1;
        RBus_UInt32  od_drf_done:1;
        RBus_UInt32  oddma_drf_done:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pcid_drf_done:1;
        RBus_UInt32  gamma2_drf_done:1;
        RBus_UInt32  gdma_subt_clut_drf_done:1;
        RBus_UInt32  gdma_subt_rbuf_drf_done:1;
        RBus_UInt32  gdma_subt_lb_drf_done:1;
        RBus_UInt32  gdma_subt_dma_buf_drf_done:1;
        RBus_UInt32  gdma_subt_dispbuf_drf_done:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  pqc1_drf_bist_done:1;
        RBus_UInt32  pqc2_drf_bist_done:1;
        RBus_UInt32  pqdc1_drf_bist_done:1;
        RBus_UInt32  pqdc2_drf_bist_done:1;
        RBus_UInt32  duzd_drf_done:1;
        RBus_UInt32  vi_drf_done:1;
        RBus_UInt32  res6:10;
    };
}dispd_wi_osd_bist_bisr_dispd_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spi_con_drf_pause:1;
        RBus_UInt32  ld_con_drf_pause:1;
        RBus_UInt32  od_drf_pause:1;
        RBus_UInt32  oddma_drf_pause:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pcid_drf_pause:1;
        RBus_UInt32  gamma2_drf_pause:1;
        RBus_UInt32  gdma_subt_clut_drf_pause:1;
        RBus_UInt32  gdma_subt_rbuf_drf_pause:1;
        RBus_UInt32  gdma_subt_lb_drf_pause:1;
        RBus_UInt32  gdma_subt_dma_buf_drf_pause:1;
        RBus_UInt32  gdma_subt_dispbuf_drf_pause:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  pqc1_drf_start_pause:1;
        RBus_UInt32  pqc2_drf_start_pause:1;
        RBus_UInt32  pqdc1_drf_start_pause:1;
        RBus_UInt32  pqdc2_drf_start_pause:1;
        RBus_UInt32  duzd_drf_pause:1;
        RBus_UInt32  vi_drf_pause:1;
        RBus_UInt32  res6:10;
    };
}dispd_wi_osd_bist_bisr_dispd_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spi_con_drf_fail_group:1;
        RBus_UInt32  ld_con_drf_fail_group:1;
        RBus_UInt32  od_drf_fail_group:1;
        RBus_UInt32  oddma_drf_fail_group:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pcid_drf_fail_group:1;
        RBus_UInt32  gamma2_drf_fail_group:1;
        RBus_UInt32  gdma_subt_clut_drf_fail_group:1;
        RBus_UInt32  gdma_subt_rbuf_drf_fail_group:1;
        RBus_UInt32  gdma_subt_lb_drf_fail_group:1;
        RBus_UInt32  gdma_subt_dma_buf_drf_fail_group:1;
        RBus_UInt32  gdma_subt_dispbuf_drf_fail_group:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  pqc1_drf_fail_group:1;
        RBus_UInt32  pqc2_drf_fail_group:1;
        RBus_UInt32  pqdc1_drf_fail_group:1;
        RBus_UInt32  pqdc2_drf_fail_group:1;
        RBus_UInt32  duzd_drf_fail_group:1;
        RBus_UInt32  vi_drf_fail_group:1;
        RBus_UInt32  res6:10;
    };
}dispd_wi_osd_bist_bisr_dispd_drf_fail_group_RBUS;




#endif 


#endif 
