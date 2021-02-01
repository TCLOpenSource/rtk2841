/**
* @file rbusDispd_osd_bistReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DISPD_OSD_BIST_REG_H_
#define _RBUS_DISPD_OSD_BIST_REG_H_

#include "rbus_types.h"



//  DISPD_OSD_BIST Register Address
#define  DISPD_OSD_BIST_GDMA_BIST_MODE                                           0x18029E00
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_reg_addr                                  "0xB8029E00"
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_reg                                       0xB8029E00
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_inst_addr                                 "0x0000"
#define  set_DISPD_OSD_BIST_GDMA_BIST_MODE_reg(data)                             (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_BIST_MODE_reg)=data)
#define  get_DISPD_OSD_BIST_GDMA_BIST_MODE_reg                                   (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_BIST_MODE_reg))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_fbdc_data0_bist_mode_shift           (12)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_fbdc_data1_bist_mode_shift           (11)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_fbdc_dma_bist_mode_shift             (10)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_fbdc_header_bist_mode_shift          (9)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd_rbuf_bist_mode_shift             (8)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd_dma_buf_bist_mode_shift          (7)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_wdma_bist_mode_shift                 (6)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd1_clut_bist_mode_shift            (5)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd2_clut_bist_mode_shift            (4)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd3_clut_bist_mode_shift            (3)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd4_clut_bist_mode_shift            (2)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd5_clut_bist_mode_shift            (1)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd_dispbuf_bist_mode_shift          (0)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_fbdc_data0_bist_mode_mask            (0x00001000)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_fbdc_data1_bist_mode_mask            (0x00000800)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_fbdc_dma_bist_mode_mask              (0x00000400)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_fbdc_header_bist_mode_mask           (0x00000200)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd_rbuf_bist_mode_mask              (0x00000100)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd_dma_buf_bist_mode_mask           (0x00000080)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_wdma_bist_mode_mask                  (0x00000040)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd1_clut_bist_mode_mask             (0x00000020)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd2_clut_bist_mode_mask             (0x00000010)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd3_clut_bist_mode_mask             (0x00000008)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd4_clut_bist_mode_mask             (0x00000004)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd5_clut_bist_mode_mask             (0x00000002)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd_dispbuf_bist_mode_mask           (0x00000001)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_fbdc_data0_bist_mode(data)           (0x00001000&((data)<<12))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_fbdc_data1_bist_mode(data)           (0x00000800&((data)<<11))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_fbdc_dma_bist_mode(data)             (0x00000400&((data)<<10))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_fbdc_header_bist_mode(data)          (0x00000200&((data)<<9))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd_rbuf_bist_mode(data)             (0x00000100&((data)<<8))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd_dma_buf_bist_mode(data)          (0x00000080&((data)<<7))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_wdma_bist_mode(data)                 (0x00000040&((data)<<6))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd1_clut_bist_mode(data)            (0x00000020&((data)<<5))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd2_clut_bist_mode(data)            (0x00000010&((data)<<4))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd3_clut_bist_mode(data)            (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd4_clut_bist_mode(data)            (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd5_clut_bist_mode(data)            (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_gdma_osd_dispbuf_bist_mode(data)          (0x00000001&(data))
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_get_gdma_fbdc_data0_bist_mode(data)       ((0x00001000&(data))>>12)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_get_gdma_fbdc_data1_bist_mode(data)       ((0x00000800&(data))>>11)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_get_gdma_fbdc_dma_bist_mode(data)         ((0x00000400&(data))>>10)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_get_gdma_fbdc_header_bist_mode(data)      ((0x00000200&(data))>>9)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_get_gdma_osd_rbuf_bist_mode(data)         ((0x00000100&(data))>>8)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_get_gdma_osd_dma_buf_bist_mode(data)      ((0x00000080&(data))>>7)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_get_gdma_wdma_bist_mode(data)             ((0x00000040&(data))>>6)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_get_gdma_osd1_clut_bist_mode(data)        ((0x00000020&(data))>>5)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_get_gdma_osd2_clut_bist_mode(data)        ((0x00000010&(data))>>4)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_get_gdma_osd3_clut_bist_mode(data)        ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_get_gdma_osd4_clut_bist_mode(data)        ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_get_gdma_osd5_clut_bist_mode(data)        ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_GDMA_BIST_MODE_get_gdma_osd_dispbuf_bist_mode(data)      (0x00000001&(data))

#define  DISPD_OSD_BIST_GDMA_BIST_DONE                                           0x18029E04
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_reg_addr                                  "0xB8029E04"
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_reg                                       0xB8029E04
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_inst_addr                                 "0x0001"
#define  set_DISPD_OSD_BIST_GDMA_BIST_DONE_reg(data)                             (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_BIST_DONE_reg)=data)
#define  get_DISPD_OSD_BIST_GDMA_BIST_DONE_reg                                   (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_BIST_DONE_reg))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_fbdc_data0_bist_done_shift           (12)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_fbdc_data1_bist_done_shift           (11)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_fbdc_dma_bist_done_shift             (10)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_fbdc_header_bist_done_shift          (9)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd_rbuf_bist_done_shift             (8)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd_dma_buf_bist_done_shift          (7)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_wdma_bist_done_shift                 (6)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd1_clut_bist_done_shift            (5)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd2_clut_bist_done_shift            (4)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd3_clut_bist_done_shift            (3)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd4_clut_bist_done_shift            (2)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd5_clut_bist_done_shift            (1)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd_dispbuf_bist_done_shift          (0)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_fbdc_data0_bist_done_mask            (0x00001000)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_fbdc_data1_bist_done_mask            (0x00000800)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_fbdc_dma_bist_done_mask              (0x00000400)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_fbdc_header_bist_done_mask           (0x00000200)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd_rbuf_bist_done_mask              (0x00000100)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd_dma_buf_bist_done_mask           (0x00000080)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_wdma_bist_done_mask                  (0x00000040)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd1_clut_bist_done_mask             (0x00000020)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd2_clut_bist_done_mask             (0x00000010)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd3_clut_bist_done_mask             (0x00000008)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd4_clut_bist_done_mask             (0x00000004)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd5_clut_bist_done_mask             (0x00000002)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd_dispbuf_bist_done_mask           (0x00000001)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_fbdc_data0_bist_done(data)           (0x00001000&((data)<<12))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_fbdc_data1_bist_done(data)           (0x00000800&((data)<<11))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_fbdc_dma_bist_done(data)             (0x00000400&((data)<<10))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_fbdc_header_bist_done(data)          (0x00000200&((data)<<9))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd_rbuf_bist_done(data)             (0x00000100&((data)<<8))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd_dma_buf_bist_done(data)          (0x00000080&((data)<<7))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_wdma_bist_done(data)                 (0x00000040&((data)<<6))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd1_clut_bist_done(data)            (0x00000020&((data)<<5))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd2_clut_bist_done(data)            (0x00000010&((data)<<4))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd3_clut_bist_done(data)            (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd4_clut_bist_done(data)            (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd5_clut_bist_done(data)            (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_gdma_osd_dispbuf_bist_done(data)          (0x00000001&(data))
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_get_gdma_fbdc_data0_bist_done(data)       ((0x00001000&(data))>>12)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_get_gdma_fbdc_data1_bist_done(data)       ((0x00000800&(data))>>11)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_get_gdma_fbdc_dma_bist_done(data)         ((0x00000400&(data))>>10)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_get_gdma_fbdc_header_bist_done(data)      ((0x00000200&(data))>>9)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_get_gdma_osd_rbuf_bist_done(data)         ((0x00000100&(data))>>8)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_get_gdma_osd_dma_buf_bist_done(data)      ((0x00000080&(data))>>7)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_get_gdma_wdma_bist_done(data)             ((0x00000040&(data))>>6)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_get_gdma_osd1_clut_bist_done(data)        ((0x00000020&(data))>>5)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_get_gdma_osd2_clut_bist_done(data)        ((0x00000010&(data))>>4)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_get_gdma_osd3_clut_bist_done(data)        ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_get_gdma_osd4_clut_bist_done(data)        ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_get_gdma_osd5_clut_bist_done(data)        ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_GDMA_BIST_DONE_get_gdma_osd_dispbuf_bist_done(data)      (0x00000001&(data))

#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP                                     0x18029E08
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_reg_addr                            "0xB8029E08"
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_reg                                 0xB8029E08
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_inst_addr                           "0x0002"
#define  set_DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_reg(data)                       (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_reg)=data)
#define  get_DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_reg                             (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_reg))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_fbdc_data0_bist_fail_group_shift (12)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_fbdc_data1_bist_fail_group_shift (11)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_fbdc_dma_bist_fail_group_shift (10)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_fbdc_header_bist_fail_group_shift (9)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd_rbuf_bist_fail_group_shift (8)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd_dma_buf_bist_fail_group_shift (7)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_wdma_bist_fail_group_shift     (6)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd1_clut_bist_fail_group_shift (5)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd2_clut_bist_fail_group_shift (4)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd3_clut_bist_fail_group_shift (3)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd4_clut_bist_fail_group_shift (2)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd5_clut_bist_fail_group_shift (1)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd_dispbuf_bist_fail_group_shift (0)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_fbdc_data0_bist_fail_group_mask (0x00001000)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_fbdc_data1_bist_fail_group_mask (0x00000800)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_fbdc_dma_bist_fail_group_mask  (0x00000400)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_fbdc_header_bist_fail_group_mask (0x00000200)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd_rbuf_bist_fail_group_mask  (0x00000100)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd_dma_buf_bist_fail_group_mask (0x00000080)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_wdma_bist_fail_group_mask      (0x00000040)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd1_clut_bist_fail_group_mask (0x00000020)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd2_clut_bist_fail_group_mask (0x00000010)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd3_clut_bist_fail_group_mask (0x00000008)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd4_clut_bist_fail_group_mask (0x00000004)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd5_clut_bist_fail_group_mask (0x00000002)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd_dispbuf_bist_fail_group_mask (0x00000001)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_fbdc_data0_bist_fail_group(data) (0x00001000&((data)<<12))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_fbdc_data1_bist_fail_group(data) (0x00000800&((data)<<11))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_fbdc_dma_bist_fail_group(data) (0x00000400&((data)<<10))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_fbdc_header_bist_fail_group(data) (0x00000200&((data)<<9))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd_rbuf_bist_fail_group(data) (0x00000100&((data)<<8))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd_dma_buf_bist_fail_group(data) (0x00000080&((data)<<7))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_wdma_bist_fail_group(data)     (0x00000040&((data)<<6))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd1_clut_bist_fail_group(data) (0x00000020&((data)<<5))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd2_clut_bist_fail_group(data) (0x00000010&((data)<<4))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd3_clut_bist_fail_group(data) (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd4_clut_bist_fail_group(data) (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd5_clut_bist_fail_group(data) (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_gdma_osd_dispbuf_bist_fail_group(data) (0x00000001&(data))
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_get_gdma_fbdc_data0_bist_fail_group(data) ((0x00001000&(data))>>12)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_get_gdma_fbdc_data1_bist_fail_group(data) ((0x00000800&(data))>>11)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_get_gdma_fbdc_dma_bist_fail_group(data) ((0x00000400&(data))>>10)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_get_gdma_fbdc_header_bist_fail_group(data) ((0x00000200&(data))>>9)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_get_gdma_osd_rbuf_bist_fail_group(data) ((0x00000100&(data))>>8)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_get_gdma_osd_dma_buf_bist_fail_group(data) ((0x00000080&(data))>>7)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_get_gdma_wdma_bist_fail_group(data) ((0x00000040&(data))>>6)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_get_gdma_osd1_clut_bist_fail_group(data) ((0x00000020&(data))>>5)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_get_gdma_osd2_clut_bist_fail_group(data) ((0x00000010&(data))>>4)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_get_gdma_osd3_clut_bist_fail_group(data) ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_get_gdma_osd4_clut_bist_fail_group(data) ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_get_gdma_osd5_clut_bist_fail_group(data) ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_GDMA_BIST_FAIL_GROUP_get_gdma_osd_dispbuf_bist_fail_group(data) (0x00000001&(data))

#define  DISPD_OSD_BIST_GDMA_DRF_MODE                                            0x18029E0C
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_reg_addr                                   "0xB8029E0C"
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_reg                                        0xB8029E0C
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_inst_addr                                  "0x0003"
#define  set_DISPD_OSD_BIST_GDMA_DRF_MODE_reg(data)                              (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_DRF_MODE_reg)=data)
#define  get_DISPD_OSD_BIST_GDMA_DRF_MODE_reg                                    (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_DRF_MODE_reg))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_fbdc_data0_drf_mode_shift             (12)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_fbdc_data1_drf_mode_shift             (11)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_fbdc_dma_drf_mode_shift               (10)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_fbdc_header_drf_mode_shift            (9)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd_rbuf_drf_mode_shift               (8)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd_dma_buf_drf_mode_shift            (7)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_wdma_drf_mode_shift                   (6)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd1_clut_drf_mode_shift              (5)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd2_clut_drf_mode_shift              (4)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd3_clut_drf_mode_shift              (3)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd4_clut_drf_mode_shift              (2)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd5_clut_drf_mode_shift              (1)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd_dispbuf_drf_mode_shift            (0)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_fbdc_data0_drf_mode_mask              (0x00001000)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_fbdc_data1_drf_mode_mask              (0x00000800)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_fbdc_dma_drf_mode_mask                (0x00000400)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_fbdc_header_drf_mode_mask             (0x00000200)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd_rbuf_drf_mode_mask                (0x00000100)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd_dma_buf_drf_mode_mask             (0x00000080)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_wdma_drf_mode_mask                    (0x00000040)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd1_clut_drf_mode_mask               (0x00000020)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd2_clut_drf_mode_mask               (0x00000010)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd3_clut_drf_mode_mask               (0x00000008)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd4_clut_drf_mode_mask               (0x00000004)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd5_clut_drf_mode_mask               (0x00000002)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd_dispbuf_drf_mode_mask             (0x00000001)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_fbdc_data0_drf_mode(data)             (0x00001000&((data)<<12))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_fbdc_data1_drf_mode(data)             (0x00000800&((data)<<11))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_fbdc_dma_drf_mode(data)               (0x00000400&((data)<<10))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_fbdc_header_drf_mode(data)            (0x00000200&((data)<<9))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd_rbuf_drf_mode(data)               (0x00000100&((data)<<8))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd_dma_buf_drf_mode(data)            (0x00000080&((data)<<7))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_wdma_drf_mode(data)                   (0x00000040&((data)<<6))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd1_clut_drf_mode(data)              (0x00000020&((data)<<5))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd2_clut_drf_mode(data)              (0x00000010&((data)<<4))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd3_clut_drf_mode(data)              (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd4_clut_drf_mode(data)              (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd5_clut_drf_mode(data)              (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_gdma_osd_dispbuf_drf_mode(data)            (0x00000001&(data))
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_get_gdma_fbdc_data0_drf_mode(data)         ((0x00001000&(data))>>12)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_get_gdma_fbdc_data1_drf_mode(data)         ((0x00000800&(data))>>11)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_get_gdma_fbdc_dma_drf_mode(data)           ((0x00000400&(data))>>10)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_get_gdma_fbdc_header_drf_mode(data)        ((0x00000200&(data))>>9)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_get_gdma_osd_rbuf_drf_mode(data)           ((0x00000100&(data))>>8)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_get_gdma_osd_dma_buf_drf_mode(data)        ((0x00000080&(data))>>7)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_get_gdma_wdma_drf_mode(data)               ((0x00000040&(data))>>6)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_get_gdma_osd1_clut_drf_mode(data)          ((0x00000020&(data))>>5)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_get_gdma_osd2_clut_drf_mode(data)          ((0x00000010&(data))>>4)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_get_gdma_osd3_clut_drf_mode(data)          ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_get_gdma_osd4_clut_drf_mode(data)          ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_get_gdma_osd5_clut_drf_mode(data)          ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_GDMA_DRF_MODE_get_gdma_osd_dispbuf_drf_mode(data)        (0x00000001&(data))

#define  DISPD_OSD_BIST_GDMA_DRF_RESUME                                          0x18029E10
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_reg_addr                                 "0xB8029E10"
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_reg                                      0xB8029E10
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_inst_addr                                "0x0004"
#define  set_DISPD_OSD_BIST_GDMA_DRF_RESUME_reg(data)                            (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_DRF_RESUME_reg)=data)
#define  get_DISPD_OSD_BIST_GDMA_DRF_RESUME_reg                                  (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_DRF_RESUME_reg))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_fbdc_data0_drf_resume_shift         (12)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_fbdc_data1_drf_resume_shift         (11)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_fbdc_dma_drf_resume_shift           (10)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_fbdc_header_drf_resume_shift        (9)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd_rbuf_drf_resume_shift           (8)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd_dma_buf_drf_resume_shift        (7)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_wdma_drf_resume_shift               (6)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd1_clut_drf_resume_shift          (5)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd2_clut_drf_resume_shift          (4)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd3_clut_drf_resume_shift          (3)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd4_clut_drf_resume_shift          (2)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd5_clut_drf_resume_shift          (1)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd_dispbuf_drf_resume_shift        (0)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_fbdc_data0_drf_resume_mask          (0x00001000)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_fbdc_data1_drf_resume_mask          (0x00000800)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_fbdc_dma_drf_resume_mask            (0x00000400)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_fbdc_header_drf_resume_mask         (0x00000200)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd_rbuf_drf_resume_mask            (0x00000100)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd_dma_buf_drf_resume_mask         (0x00000080)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_wdma_drf_resume_mask                (0x00000040)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd1_clut_drf_resume_mask           (0x00000020)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd2_clut_drf_resume_mask           (0x00000010)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd3_clut_drf_resume_mask           (0x00000008)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd4_clut_drf_resume_mask           (0x00000004)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd5_clut_drf_resume_mask           (0x00000002)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd_dispbuf_drf_resume_mask         (0x00000001)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_fbdc_data0_drf_resume(data)         (0x00001000&((data)<<12))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_fbdc_data1_drf_resume(data)         (0x00000800&((data)<<11))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_fbdc_dma_drf_resume(data)           (0x00000400&((data)<<10))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_fbdc_header_drf_resume(data)        (0x00000200&((data)<<9))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd_rbuf_drf_resume(data)           (0x00000100&((data)<<8))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd_dma_buf_drf_resume(data)        (0x00000080&((data)<<7))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_wdma_drf_resume(data)               (0x00000040&((data)<<6))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd1_clut_drf_resume(data)          (0x00000020&((data)<<5))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd2_clut_drf_resume(data)          (0x00000010&((data)<<4))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd3_clut_drf_resume(data)          (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd4_clut_drf_resume(data)          (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd5_clut_drf_resume(data)          (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_gdma_osd_dispbuf_drf_resume(data)        (0x00000001&(data))
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_get_gdma_fbdc_data0_drf_resume(data)     ((0x00001000&(data))>>12)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_get_gdma_fbdc_data1_drf_resume(data)     ((0x00000800&(data))>>11)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_get_gdma_fbdc_dma_drf_resume(data)       ((0x00000400&(data))>>10)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_get_gdma_fbdc_header_drf_resume(data)    ((0x00000200&(data))>>9)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_get_gdma_osd_rbuf_drf_resume(data)       ((0x00000100&(data))>>8)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_get_gdma_osd_dma_buf_drf_resume(data)    ((0x00000080&(data))>>7)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_get_gdma_wdma_drf_resume(data)           ((0x00000040&(data))>>6)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_get_gdma_osd1_clut_drf_resume(data)      ((0x00000020&(data))>>5)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_get_gdma_osd2_clut_drf_resume(data)      ((0x00000010&(data))>>4)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_get_gdma_osd3_clut_drf_resume(data)      ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_get_gdma_osd4_clut_drf_resume(data)      ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_get_gdma_osd5_clut_drf_resume(data)      ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_GDMA_DRF_RESUME_get_gdma_osd_dispbuf_drf_resume(data)    (0x00000001&(data))

#define  DISPD_OSD_BIST_GDMA_DRF_DONE                                            0x18029E14
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_reg_addr                                   "0xB8029E14"
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_reg                                        0xB8029E14
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_inst_addr                                  "0x0005"
#define  set_DISPD_OSD_BIST_GDMA_DRF_DONE_reg(data)                              (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_DRF_DONE_reg)=data)
#define  get_DISPD_OSD_BIST_GDMA_DRF_DONE_reg                                    (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_DRF_DONE_reg))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_fbdc_data0_drf_done_shift             (12)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_fbdc_data1_drf_done_shift             (11)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_fbdc_dma_drf_done_shift               (10)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_fbdc_header_drf_done_shift            (9)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd_rbuf_drf_done_shift               (8)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd_dma_buf_drf_done_shift            (7)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_wdma_drf_done_shift                   (6)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd1_clut_drf_done_shift              (5)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd2_clut_drf_done_shift              (4)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd3_clut_drf_done_shift              (3)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd4_clut_drf_done_shift              (2)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd5_clut_drf_done_shift              (1)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd_dispbuf_drf_done_shift            (0)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_fbdc_data0_drf_done_mask              (0x00001000)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_fbdc_data1_drf_done_mask              (0x00000800)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_fbdc_dma_drf_done_mask                (0x00000400)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_fbdc_header_drf_done_mask             (0x00000200)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd_rbuf_drf_done_mask                (0x00000100)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd_dma_buf_drf_done_mask             (0x00000080)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_wdma_drf_done_mask                    (0x00000040)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd1_clut_drf_done_mask               (0x00000020)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd2_clut_drf_done_mask               (0x00000010)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd3_clut_drf_done_mask               (0x00000008)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd4_clut_drf_done_mask               (0x00000004)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd5_clut_drf_done_mask               (0x00000002)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd_dispbuf_drf_done_mask             (0x00000001)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_fbdc_data0_drf_done(data)             (0x00001000&((data)<<12))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_fbdc_data1_drf_done(data)             (0x00000800&((data)<<11))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_fbdc_dma_drf_done(data)               (0x00000400&((data)<<10))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_fbdc_header_drf_done(data)            (0x00000200&((data)<<9))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd_rbuf_drf_done(data)               (0x00000100&((data)<<8))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd_dma_buf_drf_done(data)            (0x00000080&((data)<<7))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_wdma_drf_done(data)                   (0x00000040&((data)<<6))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd1_clut_drf_done(data)              (0x00000020&((data)<<5))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd2_clut_drf_done(data)              (0x00000010&((data)<<4))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd3_clut_drf_done(data)              (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd4_clut_drf_done(data)              (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd5_clut_drf_done(data)              (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_gdma_osd_dispbuf_drf_done(data)            (0x00000001&(data))
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_get_gdma_fbdc_data0_drf_done(data)         ((0x00001000&(data))>>12)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_get_gdma_fbdc_data1_drf_done(data)         ((0x00000800&(data))>>11)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_get_gdma_fbdc_dma_drf_done(data)           ((0x00000400&(data))>>10)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_get_gdma_fbdc_header_drf_done(data)        ((0x00000200&(data))>>9)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_get_gdma_osd_rbuf_drf_done(data)           ((0x00000100&(data))>>8)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_get_gdma_osd_dma_buf_drf_done(data)        ((0x00000080&(data))>>7)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_get_gdma_wdma_drf_done(data)               ((0x00000040&(data))>>6)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_get_gdma_osd1_clut_drf_done(data)          ((0x00000020&(data))>>5)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_get_gdma_osd2_clut_drf_done(data)          ((0x00000010&(data))>>4)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_get_gdma_osd3_clut_drf_done(data)          ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_get_gdma_osd4_clut_drf_done(data)          ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_get_gdma_osd5_clut_drf_done(data)          ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_GDMA_DRF_DONE_get_gdma_osd_dispbuf_drf_done(data)        (0x00000001&(data))

#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE                                           0x18029E18
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_reg_addr                                  "0xB8029E18"
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_reg                                       0xB8029E18
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_inst_addr                                 "0x0006"
#define  set_DISPD_OSD_BIST_GDMA_DRF_PAUSE_reg(data)                             (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_DRF_PAUSE_reg)=data)
#define  get_DISPD_OSD_BIST_GDMA_DRF_PAUSE_reg                                   (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_DRF_PAUSE_reg))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_fbdc_data0_drf_pause_shift           (12)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_fbdc_data1_drf_pause_shift           (11)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_fbdc_dma_drf_pause_shift             (10)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_fbdc_header_drf_pause_shift          (9)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd_rbuf_drf_pause_shift             (8)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd_dma_buf_drf_pause_shift          (7)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_wdma_drf_pause_shift                 (6)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd1_clut_drf_pause_shift            (5)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd2_clut_drf_pause_shift            (4)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd3_clut_drf_pause_shift            (3)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd4_clut_drf_pause_shift            (2)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd5_clut_drf_pause_shift            (1)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd_dispbuf_drf_pause_shift          (0)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_fbdc_data0_drf_pause_mask            (0x00001000)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_fbdc_data1_drf_pause_mask            (0x00000800)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_fbdc_dma_drf_pause_mask              (0x00000400)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_fbdc_header_drf_pause_mask           (0x00000200)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd_rbuf_drf_pause_mask              (0x00000100)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd_dma_buf_drf_pause_mask           (0x00000080)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_wdma_drf_pause_mask                  (0x00000040)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd1_clut_drf_pause_mask             (0x00000020)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd2_clut_drf_pause_mask             (0x00000010)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd3_clut_drf_pause_mask             (0x00000008)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd4_clut_drf_pause_mask             (0x00000004)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd5_clut_drf_pause_mask             (0x00000002)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd_dispbuf_drf_pause_mask           (0x00000001)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_fbdc_data0_drf_pause(data)           (0x00001000&((data)<<12))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_fbdc_data1_drf_pause(data)           (0x00000800&((data)<<11))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_fbdc_dma_drf_pause(data)             (0x00000400&((data)<<10))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_fbdc_header_drf_pause(data)          (0x00000200&((data)<<9))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd_rbuf_drf_pause(data)             (0x00000100&((data)<<8))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd_dma_buf_drf_pause(data)          (0x00000080&((data)<<7))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_wdma_drf_pause(data)                 (0x00000040&((data)<<6))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd1_clut_drf_pause(data)            (0x00000020&((data)<<5))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd2_clut_drf_pause(data)            (0x00000010&((data)<<4))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd3_clut_drf_pause(data)            (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd4_clut_drf_pause(data)            (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd5_clut_drf_pause(data)            (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_gdma_osd_dispbuf_drf_pause(data)          (0x00000001&(data))
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_get_gdma_fbdc_data0_drf_pause(data)       ((0x00001000&(data))>>12)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_get_gdma_fbdc_data1_drf_pause(data)       ((0x00000800&(data))>>11)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_get_gdma_fbdc_dma_drf_pause(data)         ((0x00000400&(data))>>10)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_get_gdma_fbdc_header_drf_pause(data)      ((0x00000200&(data))>>9)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_get_gdma_osd_rbuf_drf_pause(data)         ((0x00000100&(data))>>8)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_get_gdma_osd_dma_buf_drf_pause(data)      ((0x00000080&(data))>>7)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_get_gdma_wdma_drf_pause(data)             ((0x00000040&(data))>>6)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_get_gdma_osd1_clut_drf_pause(data)        ((0x00000020&(data))>>5)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_get_gdma_osd2_clut_drf_pause(data)        ((0x00000010&(data))>>4)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_get_gdma_osd3_clut_drf_pause(data)        ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_get_gdma_osd4_clut_drf_pause(data)        ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_get_gdma_osd5_clut_drf_pause(data)        ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_GDMA_DRF_PAUSE_get_gdma_osd_dispbuf_drf_pause(data)      (0x00000001&(data))

#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP                                      0x18029E1C
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_reg_addr                             "0xB8029E1C"
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_reg                                  0xB8029E1C
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_inst_addr                            "0x0007"
#define  set_DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_reg(data)                        (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_reg)=data)
#define  get_DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_reg                              (*((volatile unsigned int*)DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_reg))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_fbdc_data0_drf_fail_group_shift (12)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_fbdc_data1_drf_fail_group_shift (11)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_fbdc_dma_drf_fail_group_shift   (10)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_fbdc_header_drf_fail_group_shift (9)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd_rbuf_drf_fail_group_shift   (8)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd_dma_buf_drf_fail_group_shift (7)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_wdma_drf_fail_group_shift       (6)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd1_clut_drf_fail_group_shift  (5)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd2_clut_drf_fail_group_shift  (4)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd3_clut_drf_fail_group_shift  (3)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd4_clut_drf_fail_group_shift  (2)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd5_clut_drf_fail_group_shift  (1)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd_dispbuf_drf_fail_group_shift (0)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_fbdc_data0_drf_fail_group_mask  (0x00001000)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_fbdc_data1_drf_fail_group_mask  (0x00000800)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_fbdc_dma_drf_fail_group_mask    (0x00000400)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_fbdc_header_drf_fail_group_mask (0x00000200)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd_rbuf_drf_fail_group_mask    (0x00000100)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd_dma_buf_drf_fail_group_mask (0x00000080)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_wdma_drf_fail_group_mask        (0x00000040)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd1_clut_drf_fail_group_mask   (0x00000020)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd2_clut_drf_fail_group_mask   (0x00000010)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd3_clut_drf_fail_group_mask   (0x00000008)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd4_clut_drf_fail_group_mask   (0x00000004)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd5_clut_drf_fail_group_mask   (0x00000002)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd_dispbuf_drf_fail_group_mask (0x00000001)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_fbdc_data0_drf_fail_group(data) (0x00001000&((data)<<12))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_fbdc_data1_drf_fail_group(data) (0x00000800&((data)<<11))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_fbdc_dma_drf_fail_group(data)   (0x00000400&((data)<<10))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_fbdc_header_drf_fail_group(data) (0x00000200&((data)<<9))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd_rbuf_drf_fail_group(data)   (0x00000100&((data)<<8))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd_dma_buf_drf_fail_group(data) (0x00000080&((data)<<7))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_wdma_drf_fail_group(data)       (0x00000040&((data)<<6))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd1_clut_drf_fail_group(data)  (0x00000020&((data)<<5))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd2_clut_drf_fail_group(data)  (0x00000010&((data)<<4))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd3_clut_drf_fail_group(data)  (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd4_clut_drf_fail_group(data)  (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd5_clut_drf_fail_group(data)  (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_gdma_osd_dispbuf_drf_fail_group(data) (0x00000001&(data))
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_get_gdma_fbdc_data0_drf_fail_group(data) ((0x00001000&(data))>>12)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_get_gdma_fbdc_data1_drf_fail_group(data) ((0x00000800&(data))>>11)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_get_gdma_fbdc_dma_drf_fail_group(data) ((0x00000400&(data))>>10)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_get_gdma_fbdc_header_drf_fail_group(data) ((0x00000200&(data))>>9)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_get_gdma_osd_rbuf_drf_fail_group(data) ((0x00000100&(data))>>8)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_get_gdma_osd_dma_buf_drf_fail_group(data) ((0x00000080&(data))>>7)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_get_gdma_wdma_drf_fail_group(data)   ((0x00000040&(data))>>6)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_get_gdma_osd1_clut_drf_fail_group(data) ((0x00000020&(data))>>5)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_get_gdma_osd2_clut_drf_fail_group(data) ((0x00000010&(data))>>4)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_get_gdma_osd3_clut_drf_fail_group(data) ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_get_gdma_osd4_clut_drf_fail_group(data) ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_get_gdma_osd5_clut_drf_fail_group(data) ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_GDMA_DRF_FAIL_GROUP_get_gdma_osd_dispbuf_drf_fail_group(data) (0x00000001&(data))

#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN                                 0x18029E20
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_reg_addr                        "0xB8029E20"
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_reg                             0xB8029E20
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_inst_addr                       "0x0008"
#define  set_DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_reg(data)                   (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_reg)=data)
#define  get_DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_reg                         (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_reg))
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_gdma_fbdc_bisr_second_run_en_003_shift (3)
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_gdma_fbdc_bisr_second_run_en_002_shift (2)
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_gdma_fbdc_bisr_second_run_en_001_shift (1)
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_gdma_fbdc_bisr_second_run_en_000_shift (0)
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_gdma_fbdc_bisr_second_run_en_003_mask (0x00000008)
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_gdma_fbdc_bisr_second_run_en_002_mask (0x00000004)
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_gdma_fbdc_bisr_second_run_en_001_mask (0x00000002)
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_gdma_fbdc_bisr_second_run_en_000_mask (0x00000001)
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_gdma_fbdc_bisr_second_run_en_003(data) (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_gdma_fbdc_bisr_second_run_en_002(data) (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_gdma_fbdc_bisr_second_run_en_001(data) (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_gdma_fbdc_bisr_second_run_en_000(data) (0x00000001&(data))
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_get_gdma_fbdc_bisr_second_run_en_003(data) ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_get_gdma_fbdc_bisr_second_run_en_002(data) ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_get_gdma_fbdc_bisr_second_run_en_001(data) ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_DISPD_BISR_SECOND_RUN_EN_get_gdma_fbdc_bisr_second_run_en_000(data) (0x00000001&(data))

#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP                                    0x18029E24
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_reg_addr                           "0xB8029E24"
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_reg                                0xB8029E24
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_inst_addr                          "0x0009"
#define  set_DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_reg(data)                      (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_reg)=data)
#define  get_DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_reg                            (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_reg))
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_gdma_fbdc_bisr_fail_003_group_shift (3)
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_gdma_fbdc_bisr_fail_002_group_shift (2)
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_gdma_fbdc_bisr_fail_001_group_shift (1)
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_gdma_fbdc_bisr_fail_000_group_shift (0)
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_gdma_fbdc_bisr_fail_003_group_mask (0x00000008)
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_gdma_fbdc_bisr_fail_002_group_mask (0x00000004)
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_gdma_fbdc_bisr_fail_001_group_mask (0x00000002)
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_gdma_fbdc_bisr_fail_000_group_mask (0x00000001)
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_gdma_fbdc_bisr_fail_003_group(data) (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_gdma_fbdc_bisr_fail_002_group(data) (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_gdma_fbdc_bisr_fail_001_group(data) (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_gdma_fbdc_bisr_fail_000_group(data) (0x00000001&(data))
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_get_gdma_fbdc_bisr_fail_003_group(data) ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_get_gdma_fbdc_bisr_fail_002_group(data) ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_get_gdma_fbdc_bisr_fail_001_group(data) ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_DISPD_BISR_FAIL_GROUP_get_gdma_fbdc_bisr_fail_000_group(data) (0x00000001&(data))

#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE                                      0x18029E28
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_reg_addr                             "0xB8029E28"
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_reg                                  0xB8029E28
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_inst_addr                            "0x000A"
#define  set_DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_reg(data)                        (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_reg)=data)
#define  get_DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_reg                              (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_reg))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_gdma_fbdc_drf_bisr_mode_003_shift    (3)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_gdma_fbdc_drf_bisr_mode_002_shift    (2)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_gdma_fbdc_drf_bisr_mode_001_shift    (1)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_gdma_fbdc_drf_bisr_mode_000_shift    (0)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_gdma_fbdc_drf_bisr_mode_003_mask     (0x00000008)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_gdma_fbdc_drf_bisr_mode_002_mask     (0x00000004)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_gdma_fbdc_drf_bisr_mode_001_mask     (0x00000002)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_gdma_fbdc_drf_bisr_mode_000_mask     (0x00000001)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_gdma_fbdc_drf_bisr_mode_003(data)    (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_gdma_fbdc_drf_bisr_mode_002(data)    (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_gdma_fbdc_drf_bisr_mode_001(data)    (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_gdma_fbdc_drf_bisr_mode_000(data)    (0x00000001&(data))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_get_gdma_fbdc_drf_bisr_mode_003(data) ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_get_gdma_fbdc_drf_bisr_mode_002(data) ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_get_gdma_fbdc_drf_bisr_mode_001(data) ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_MODE_get_gdma_fbdc_drf_bisr_mode_000(data) (0x00000001&(data))

#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME                                    0x18029E2C
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_reg_addr                           "0xB8029E2C"
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_reg                                0xB8029E2C
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_inst_addr                          "0x000B"
#define  set_DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_reg(data)                      (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_reg)=data)
#define  get_DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_reg                            (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_reg))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_gdma_fbdc_drf_bisr_test_resume_003_shift (3)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_gdma_fbdc_drf_bisr_test_resume_002_shift (2)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_gdma_fbdc_drf_bisr_test_resume_001_shift (1)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_gdma_fbdc_drf_bisr_test_resume_000_shift (0)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_gdma_fbdc_drf_bisr_test_resume_003_mask (0x00000008)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_gdma_fbdc_drf_bisr_test_resume_002_mask (0x00000004)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_gdma_fbdc_drf_bisr_test_resume_001_mask (0x00000002)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_gdma_fbdc_drf_bisr_test_resume_000_mask (0x00000001)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_gdma_fbdc_drf_bisr_test_resume_003(data) (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_gdma_fbdc_drf_bisr_test_resume_002(data) (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_gdma_fbdc_drf_bisr_test_resume_001(data) (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_gdma_fbdc_drf_bisr_test_resume_000(data) (0x00000001&(data))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_get_gdma_fbdc_drf_bisr_test_resume_003(data) ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_get_gdma_fbdc_drf_bisr_test_resume_002(data) ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_get_gdma_fbdc_drf_bisr_test_resume_001(data) ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_RESUME_get_gdma_fbdc_drf_bisr_test_resume_000(data) (0x00000001&(data))

#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE                                      0x18029E30
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_reg_addr                             "0xB8029E30"
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_reg                                  0xB8029E30
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_inst_addr                            "0x000C"
#define  set_DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_reg(data)                        (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_reg)=data)
#define  get_DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_reg                              (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_reg))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_gdma_fbdc_drf_bisr_done_003_shift    (3)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_gdma_fbdc_drf_bisr_done_002_shift    (2)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_gdma_fbdc_drf_bisr_done_001_shift    (1)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_gdma_fbdc_drf_bisr_done_000_shift    (0)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_gdma_fbdc_drf_bisr_done_003_mask     (0x00000008)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_gdma_fbdc_drf_bisr_done_002_mask     (0x00000004)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_gdma_fbdc_drf_bisr_done_001_mask     (0x00000002)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_gdma_fbdc_drf_bisr_done_000_mask     (0x00000001)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_gdma_fbdc_drf_bisr_done_003(data)    (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_gdma_fbdc_drf_bisr_done_002(data)    (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_gdma_fbdc_drf_bisr_done_001(data)    (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_gdma_fbdc_drf_bisr_done_000(data)    (0x00000001&(data))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_get_gdma_fbdc_drf_bisr_done_003(data) ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_get_gdma_fbdc_drf_bisr_done_002(data) ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_get_gdma_fbdc_drf_bisr_done_001(data) ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_DONE_get_gdma_fbdc_drf_bisr_done_000(data) (0x00000001&(data))

#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE                                     0x18029E34
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_reg_addr                            "0xB8029E34"
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_reg                                 0xB8029E34
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_inst_addr                           "0x000D"
#define  set_DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_reg(data)                       (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_reg)=data)
#define  get_DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_reg                             (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_reg))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_gdma_fbdc_drf_bisr_start_pause_003_shift (3)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_gdma_fbdc_drf_bisr_start_pause_002_shift (2)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_gdma_fbdc_drf_bisr_start_pause_001_shift (1)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_gdma_fbdc_drf_bisr_start_pause_000_shift (0)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_gdma_fbdc_drf_bisr_start_pause_003_mask (0x00000008)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_gdma_fbdc_drf_bisr_start_pause_002_mask (0x00000004)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_gdma_fbdc_drf_bisr_start_pause_001_mask (0x00000002)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_gdma_fbdc_drf_bisr_start_pause_000_mask (0x00000001)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_gdma_fbdc_drf_bisr_start_pause_003(data) (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_gdma_fbdc_drf_bisr_start_pause_002(data) (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_gdma_fbdc_drf_bisr_start_pause_001(data) (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_gdma_fbdc_drf_bisr_start_pause_000(data) (0x00000001&(data))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_get_gdma_fbdc_drf_bisr_start_pause_003(data) ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_get_gdma_fbdc_drf_bisr_start_pause_002(data) ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_get_gdma_fbdc_drf_bisr_start_pause_001(data) ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_PAUSE_get_gdma_fbdc_drf_bisr_start_pause_000(data) (0x00000001&(data))

#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP                                0x18029E38
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_reg_addr                       "0xB8029E38"
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_reg                            0xB8029E38
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_inst_addr                      "0x000E"
#define  set_DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_reg(data)                  (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_reg)=data)
#define  get_DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_reg                        (*((volatile unsigned int*)DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_reg))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_gdma_fbdc_drf_bisr_fail_003_group_shift (3)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_gdma_fbdc_drf_bisr_fail_002_group_shift (2)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_gdma_fbdc_drf_bisr_fail_001_group_shift (1)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_gdma_fbdc_drf_bisr_fail_000_group_shift (0)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_gdma_fbdc_drf_bisr_fail_003_group_mask (0x00000008)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_gdma_fbdc_drf_bisr_fail_002_group_mask (0x00000004)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_gdma_fbdc_drf_bisr_fail_001_group_mask (0x00000002)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_gdma_fbdc_drf_bisr_fail_000_group_mask (0x00000001)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_gdma_fbdc_drf_bisr_fail_003_group(data) (0x00000008&((data)<<3))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_gdma_fbdc_drf_bisr_fail_002_group(data) (0x00000004&((data)<<2))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_gdma_fbdc_drf_bisr_fail_001_group(data) (0x00000002&((data)<<1))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_gdma_fbdc_drf_bisr_fail_000_group(data) (0x00000001&(data))
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_get_gdma_fbdc_drf_bisr_fail_003_group(data) ((0x00000008&(data))>>3)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_get_gdma_fbdc_drf_bisr_fail_002_group(data) ((0x00000004&(data))>>2)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_get_gdma_fbdc_drf_bisr_fail_001_group(data) ((0x00000002&(data))>>1)
#define  DISPD_OSD_BIST_DISPD_BISR_DRF_FAIL_GROUP_get_gdma_fbdc_drf_bisr_fail_000_group(data) (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DISPD_OSD_BIST register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
        RBus_UInt32  gdma_fbdc_data0_bist_mode:1;
        RBus_UInt32  gdma_fbdc_data1_bist_mode:1;
        RBus_UInt32  gdma_fbdc_dma_bist_mode:1;
        RBus_UInt32  gdma_fbdc_header_bist_mode:1;
        RBus_UInt32  gdma_osd_rbuf_bist_mode:1;
        RBus_UInt32  gdma_osd_dma_buf_bist_mode:1;
        RBus_UInt32  gdma_wdma_bist_mode:1;
        RBus_UInt32  gdma_osd1_clut_bist_mode:1;
        RBus_UInt32  gdma_osd2_clut_bist_mode:1;
        RBus_UInt32  gdma_osd3_clut_bist_mode:1;
        RBus_UInt32  gdma_osd4_clut_bist_mode:1;
        RBus_UInt32  gdma_osd5_clut_bist_mode:1;
        RBus_UInt32  gdma_osd_dispbuf_bist_mode:1;
    };
}dispd_osd_bist_gdma_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
        RBus_UInt32  gdma_fbdc_data0_bist_done:1;
        RBus_UInt32  gdma_fbdc_data1_bist_done:1;
        RBus_UInt32  gdma_fbdc_dma_bist_done:1;
        RBus_UInt32  gdma_fbdc_header_bist_done:1;
        RBus_UInt32  gdma_osd_rbuf_bist_done:1;
        RBus_UInt32  gdma_osd_dma_buf_bist_done:1;
        RBus_UInt32  gdma_wdma_bist_done:1;
        RBus_UInt32  gdma_osd1_clut_bist_done:1;
        RBus_UInt32  gdma_osd2_clut_bist_done:1;
        RBus_UInt32  gdma_osd3_clut_bist_done:1;
        RBus_UInt32  gdma_osd4_clut_bist_done:1;
        RBus_UInt32  gdma_osd5_clut_bist_done:1;
        RBus_UInt32  gdma_osd_dispbuf_bist_done:1;
    };
}dispd_osd_bist_gdma_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
        RBus_UInt32  gdma_fbdc_data0_bist_fail_group:1;
        RBus_UInt32  gdma_fbdc_data1_bist_fail_group:1;
        RBus_UInt32  gdma_fbdc_dma_bist_fail_group:1;
        RBus_UInt32  gdma_fbdc_header_bist_fail_group:1;
        RBus_UInt32  gdma_osd_rbuf_bist_fail_group:1;
        RBus_UInt32  gdma_osd_dma_buf_bist_fail_group:1;
        RBus_UInt32  gdma_wdma_bist_fail_group:1;
        RBus_UInt32  gdma_osd1_clut_bist_fail_group:1;
        RBus_UInt32  gdma_osd2_clut_bist_fail_group:1;
        RBus_UInt32  gdma_osd3_clut_bist_fail_group:1;
        RBus_UInt32  gdma_osd4_clut_bist_fail_group:1;
        RBus_UInt32  gdma_osd5_clut_bist_fail_group:1;
        RBus_UInt32  gdma_osd_dispbuf_bist_fail_group:1;
    };
}dispd_osd_bist_gdma_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
        RBus_UInt32  gdma_fbdc_data0_drf_mode:1;
        RBus_UInt32  gdma_fbdc_data1_drf_mode:1;
        RBus_UInt32  gdma_fbdc_dma_drf_mode:1;
        RBus_UInt32  gdma_fbdc_header_drf_mode:1;
        RBus_UInt32  gdma_osd_rbuf_drf_mode:1;
        RBus_UInt32  gdma_osd_dma_buf_drf_mode:1;
        RBus_UInt32  gdma_wdma_drf_mode:1;
        RBus_UInt32  gdma_osd1_clut_drf_mode:1;
        RBus_UInt32  gdma_osd2_clut_drf_mode:1;
        RBus_UInt32  gdma_osd3_clut_drf_mode:1;
        RBus_UInt32  gdma_osd4_clut_drf_mode:1;
        RBus_UInt32  gdma_osd5_clut_drf_mode:1;
        RBus_UInt32  gdma_osd_dispbuf_drf_mode:1;
    };
}dispd_osd_bist_gdma_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
        RBus_UInt32  gdma_fbdc_data0_drf_resume:1;
        RBus_UInt32  gdma_fbdc_data1_drf_resume:1;
        RBus_UInt32  gdma_fbdc_dma_drf_resume:1;
        RBus_UInt32  gdma_fbdc_header_drf_resume:1;
        RBus_UInt32  gdma_osd_rbuf_drf_resume:1;
        RBus_UInt32  gdma_osd_dma_buf_drf_resume:1;
        RBus_UInt32  gdma_wdma_drf_resume:1;
        RBus_UInt32  gdma_osd1_clut_drf_resume:1;
        RBus_UInt32  gdma_osd2_clut_drf_resume:1;
        RBus_UInt32  gdma_osd3_clut_drf_resume:1;
        RBus_UInt32  gdma_osd4_clut_drf_resume:1;
        RBus_UInt32  gdma_osd5_clut_drf_resume:1;
        RBus_UInt32  gdma_osd_dispbuf_drf_resume:1;
    };
}dispd_osd_bist_gdma_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
        RBus_UInt32  gdma_fbdc_data0_drf_done:1;
        RBus_UInt32  gdma_fbdc_data1_drf_done:1;
        RBus_UInt32  gdma_fbdc_dma_drf_done:1;
        RBus_UInt32  gdma_fbdc_header_drf_done:1;
        RBus_UInt32  gdma_osd_rbuf_drf_done:1;
        RBus_UInt32  gdma_osd_dma_buf_drf_done:1;
        RBus_UInt32  gdma_wdma_drf_done:1;
        RBus_UInt32  gdma_osd1_clut_drf_done:1;
        RBus_UInt32  gdma_osd2_clut_drf_done:1;
        RBus_UInt32  gdma_osd3_clut_drf_done:1;
        RBus_UInt32  gdma_osd4_clut_drf_done:1;
        RBus_UInt32  gdma_osd5_clut_drf_done:1;
        RBus_UInt32  gdma_osd_dispbuf_drf_done:1;
    };
}dispd_osd_bist_gdma_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
        RBus_UInt32  gdma_fbdc_data0_drf_pause:1;
        RBus_UInt32  gdma_fbdc_data1_drf_pause:1;
        RBus_UInt32  gdma_fbdc_dma_drf_pause:1;
        RBus_UInt32  gdma_fbdc_header_drf_pause:1;
        RBus_UInt32  gdma_osd_rbuf_drf_pause:1;
        RBus_UInt32  gdma_osd_dma_buf_drf_pause:1;
        RBus_UInt32  gdma_wdma_drf_pause:1;
        RBus_UInt32  gdma_osd1_clut_drf_pause:1;
        RBus_UInt32  gdma_osd2_clut_drf_pause:1;
        RBus_UInt32  gdma_osd3_clut_drf_pause:1;
        RBus_UInt32  gdma_osd4_clut_drf_pause:1;
        RBus_UInt32  gdma_osd5_clut_drf_pause:1;
        RBus_UInt32  gdma_osd_dispbuf_drf_pause:1;
    };
}dispd_osd_bist_gdma_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
        RBus_UInt32  gdma_fbdc_data0_drf_fail_group:1;
        RBus_UInt32  gdma_fbdc_data1_drf_fail_group:1;
        RBus_UInt32  gdma_fbdc_dma_drf_fail_group:1;
        RBus_UInt32  gdma_fbdc_header_drf_fail_group:1;
        RBus_UInt32  gdma_osd_rbuf_drf_fail_group:1;
        RBus_UInt32  gdma_osd_dma_buf_drf_fail_group:1;
        RBus_UInt32  gdma_wdma_drf_fail_group:1;
        RBus_UInt32  gdma_osd1_clut_drf_fail_group:1;
        RBus_UInt32  gdma_osd2_clut_drf_fail_group:1;
        RBus_UInt32  gdma_osd3_clut_drf_fail_group:1;
        RBus_UInt32  gdma_osd4_clut_drf_fail_group:1;
        RBus_UInt32  gdma_osd5_clut_drf_fail_group:1;
        RBus_UInt32  gdma_osd_dispbuf_drf_fail_group:1;
    };
}dispd_osd_bist_gdma_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  gdma_fbdc_bisr_second_run_en_003:1;
        RBus_UInt32  gdma_fbdc_bisr_second_run_en_002:1;
        RBus_UInt32  gdma_fbdc_bisr_second_run_en_001:1;
        RBus_UInt32  gdma_fbdc_bisr_second_run_en_000:1;
    };
}dispd_osd_bist_dispd_bisr_second_run_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  gdma_fbdc_bisr_fail_003_group:1;
        RBus_UInt32  gdma_fbdc_bisr_fail_002_group:1;
        RBus_UInt32  gdma_fbdc_bisr_fail_001_group:1;
        RBus_UInt32  gdma_fbdc_bisr_fail_000_group:1;
    };
}dispd_osd_bist_dispd_bisr_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  gdma_fbdc_drf_bisr_mode_003:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_mode_002:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_mode_001:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_mode_000:1;
    };
}dispd_osd_bist_dispd_bisr_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  gdma_fbdc_drf_bisr_test_resume_003:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_test_resume_002:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_test_resume_001:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_test_resume_000:1;
    };
}dispd_osd_bist_dispd_bisr_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  gdma_fbdc_drf_bisr_done_003:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_done_002:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_done_001:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_done_000:1;
    };
}dispd_osd_bist_dispd_bisr_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  gdma_fbdc_drf_bisr_start_pause_003:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_start_pause_002:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_start_pause_001:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_start_pause_000:1;
    };
}dispd_osd_bist_dispd_bisr_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  gdma_fbdc_drf_bisr_fail_003_group:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_fail_002_group:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_fail_001_group:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_fail_000_group:1;
    };
}dispd_osd_bist_dispd_bisr_drf_fail_group_RBUS;

#else //apply LITTLE_ENDIAN

//======DISPD_OSD_BIST register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_osd_dispbuf_bist_mode:1;
        RBus_UInt32  gdma_osd5_clut_bist_mode:1;
        RBus_UInt32  gdma_osd4_clut_bist_mode:1;
        RBus_UInt32  gdma_osd3_clut_bist_mode:1;
        RBus_UInt32  gdma_osd2_clut_bist_mode:1;
        RBus_UInt32  gdma_osd1_clut_bist_mode:1;
        RBus_UInt32  gdma_wdma_bist_mode:1;
        RBus_UInt32  gdma_osd_dma_buf_bist_mode:1;
        RBus_UInt32  gdma_osd_rbuf_bist_mode:1;
        RBus_UInt32  gdma_fbdc_header_bist_mode:1;
        RBus_UInt32  gdma_fbdc_dma_bist_mode:1;
        RBus_UInt32  gdma_fbdc_data1_bist_mode:1;
        RBus_UInt32  gdma_fbdc_data0_bist_mode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
    };
}dispd_osd_bist_gdma_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_osd_dispbuf_bist_done:1;
        RBus_UInt32  gdma_osd5_clut_bist_done:1;
        RBus_UInt32  gdma_osd4_clut_bist_done:1;
        RBus_UInt32  gdma_osd3_clut_bist_done:1;
        RBus_UInt32  gdma_osd2_clut_bist_done:1;
        RBus_UInt32  gdma_osd1_clut_bist_done:1;
        RBus_UInt32  gdma_wdma_bist_done:1;
        RBus_UInt32  gdma_osd_dma_buf_bist_done:1;
        RBus_UInt32  gdma_osd_rbuf_bist_done:1;
        RBus_UInt32  gdma_fbdc_header_bist_done:1;
        RBus_UInt32  gdma_fbdc_dma_bist_done:1;
        RBus_UInt32  gdma_fbdc_data1_bist_done:1;
        RBus_UInt32  gdma_fbdc_data0_bist_done:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
    };
}dispd_osd_bist_gdma_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_osd_dispbuf_bist_fail_group:1;
        RBus_UInt32  gdma_osd5_clut_bist_fail_group:1;
        RBus_UInt32  gdma_osd4_clut_bist_fail_group:1;
        RBus_UInt32  gdma_osd3_clut_bist_fail_group:1;
        RBus_UInt32  gdma_osd2_clut_bist_fail_group:1;
        RBus_UInt32  gdma_osd1_clut_bist_fail_group:1;
        RBus_UInt32  gdma_wdma_bist_fail_group:1;
        RBus_UInt32  gdma_osd_dma_buf_bist_fail_group:1;
        RBus_UInt32  gdma_osd_rbuf_bist_fail_group:1;
        RBus_UInt32  gdma_fbdc_header_bist_fail_group:1;
        RBus_UInt32  gdma_fbdc_dma_bist_fail_group:1;
        RBus_UInt32  gdma_fbdc_data1_bist_fail_group:1;
        RBus_UInt32  gdma_fbdc_data0_bist_fail_group:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
    };
}dispd_osd_bist_gdma_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_osd_dispbuf_drf_mode:1;
        RBus_UInt32  gdma_osd5_clut_drf_mode:1;
        RBus_UInt32  gdma_osd4_clut_drf_mode:1;
        RBus_UInt32  gdma_osd3_clut_drf_mode:1;
        RBus_UInt32  gdma_osd2_clut_drf_mode:1;
        RBus_UInt32  gdma_osd1_clut_drf_mode:1;
        RBus_UInt32  gdma_wdma_drf_mode:1;
        RBus_UInt32  gdma_osd_dma_buf_drf_mode:1;
        RBus_UInt32  gdma_osd_rbuf_drf_mode:1;
        RBus_UInt32  gdma_fbdc_header_drf_mode:1;
        RBus_UInt32  gdma_fbdc_dma_drf_mode:1;
        RBus_UInt32  gdma_fbdc_data1_drf_mode:1;
        RBus_UInt32  gdma_fbdc_data0_drf_mode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
    };
}dispd_osd_bist_gdma_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_osd_dispbuf_drf_resume:1;
        RBus_UInt32  gdma_osd5_clut_drf_resume:1;
        RBus_UInt32  gdma_osd4_clut_drf_resume:1;
        RBus_UInt32  gdma_osd3_clut_drf_resume:1;
        RBus_UInt32  gdma_osd2_clut_drf_resume:1;
        RBus_UInt32  gdma_osd1_clut_drf_resume:1;
        RBus_UInt32  gdma_wdma_drf_resume:1;
        RBus_UInt32  gdma_osd_dma_buf_drf_resume:1;
        RBus_UInt32  gdma_osd_rbuf_drf_resume:1;
        RBus_UInt32  gdma_fbdc_header_drf_resume:1;
        RBus_UInt32  gdma_fbdc_dma_drf_resume:1;
        RBus_UInt32  gdma_fbdc_data1_drf_resume:1;
        RBus_UInt32  gdma_fbdc_data0_drf_resume:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
    };
}dispd_osd_bist_gdma_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_osd_dispbuf_drf_done:1;
        RBus_UInt32  gdma_osd5_clut_drf_done:1;
        RBus_UInt32  gdma_osd4_clut_drf_done:1;
        RBus_UInt32  gdma_osd3_clut_drf_done:1;
        RBus_UInt32  gdma_osd2_clut_drf_done:1;
        RBus_UInt32  gdma_osd1_clut_drf_done:1;
        RBus_UInt32  gdma_wdma_drf_done:1;
        RBus_UInt32  gdma_osd_dma_buf_drf_done:1;
        RBus_UInt32  gdma_osd_rbuf_drf_done:1;
        RBus_UInt32  gdma_fbdc_header_drf_done:1;
        RBus_UInt32  gdma_fbdc_dma_drf_done:1;
        RBus_UInt32  gdma_fbdc_data1_drf_done:1;
        RBus_UInt32  gdma_fbdc_data0_drf_done:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
    };
}dispd_osd_bist_gdma_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_osd_dispbuf_drf_pause:1;
        RBus_UInt32  gdma_osd5_clut_drf_pause:1;
        RBus_UInt32  gdma_osd4_clut_drf_pause:1;
        RBus_UInt32  gdma_osd3_clut_drf_pause:1;
        RBus_UInt32  gdma_osd2_clut_drf_pause:1;
        RBus_UInt32  gdma_osd1_clut_drf_pause:1;
        RBus_UInt32  gdma_wdma_drf_pause:1;
        RBus_UInt32  gdma_osd_dma_buf_drf_pause:1;
        RBus_UInt32  gdma_osd_rbuf_drf_pause:1;
        RBus_UInt32  gdma_fbdc_header_drf_pause:1;
        RBus_UInt32  gdma_fbdc_dma_drf_pause:1;
        RBus_UInt32  gdma_fbdc_data1_drf_pause:1;
        RBus_UInt32  gdma_fbdc_data0_drf_pause:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
    };
}dispd_osd_bist_gdma_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_osd_dispbuf_drf_fail_group:1;
        RBus_UInt32  gdma_osd5_clut_drf_fail_group:1;
        RBus_UInt32  gdma_osd4_clut_drf_fail_group:1;
        RBus_UInt32  gdma_osd3_clut_drf_fail_group:1;
        RBus_UInt32  gdma_osd2_clut_drf_fail_group:1;
        RBus_UInt32  gdma_osd1_clut_drf_fail_group:1;
        RBus_UInt32  gdma_wdma_drf_fail_group:1;
        RBus_UInt32  gdma_osd_dma_buf_drf_fail_group:1;
        RBus_UInt32  gdma_osd_rbuf_drf_fail_group:1;
        RBus_UInt32  gdma_fbdc_header_drf_fail_group:1;
        RBus_UInt32  gdma_fbdc_dma_drf_fail_group:1;
        RBus_UInt32  gdma_fbdc_data1_drf_fail_group:1;
        RBus_UInt32  gdma_fbdc_data0_drf_fail_group:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
    };
}dispd_osd_bist_gdma_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_fbdc_bisr_second_run_en_000:1;
        RBus_UInt32  gdma_fbdc_bisr_second_run_en_001:1;
        RBus_UInt32  gdma_fbdc_bisr_second_run_en_002:1;
        RBus_UInt32  gdma_fbdc_bisr_second_run_en_003:1;
        RBus_UInt32  res1:28;
    };
}dispd_osd_bist_dispd_bisr_second_run_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_fbdc_bisr_fail_000_group:1;
        RBus_UInt32  gdma_fbdc_bisr_fail_001_group:1;
        RBus_UInt32  gdma_fbdc_bisr_fail_002_group:1;
        RBus_UInt32  gdma_fbdc_bisr_fail_003_group:1;
        RBus_UInt32  res1:28;
    };
}dispd_osd_bist_dispd_bisr_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_fbdc_drf_bisr_mode_000:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_mode_001:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_mode_002:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_mode_003:1;
        RBus_UInt32  res1:28;
    };
}dispd_osd_bist_dispd_bisr_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_fbdc_drf_bisr_test_resume_000:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_test_resume_001:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_test_resume_002:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_test_resume_003:1;
        RBus_UInt32  res1:28;
    };
}dispd_osd_bist_dispd_bisr_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_fbdc_drf_bisr_done_000:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_done_001:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_done_002:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_done_003:1;
        RBus_UInt32  res1:28;
    };
}dispd_osd_bist_dispd_bisr_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_fbdc_drf_bisr_start_pause_000:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_start_pause_001:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_start_pause_002:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_start_pause_003:1;
        RBus_UInt32  res1:28;
    };
}dispd_osd_bist_dispd_bisr_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdma_fbdc_drf_bisr_fail_000_group:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_fail_001_group:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_fail_002_group:1;
        RBus_UInt32  gdma_fbdc_drf_bisr_fail_003_group:1;
        RBus_UInt32  res1:28;
    };
}dispd_osd_bist_dispd_bisr_drf_fail_group_RBUS;




#endif 


#endif 
