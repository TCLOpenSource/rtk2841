/**
* @file rbusDC_SYS_64BIT_WRAPPERReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/12/14
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DC_SYS_64BIT_WRAPPER_REG_H_
#define _RBUS_DC_SYS_64BIT_WRAPPER_REG_H_

#include "rbus_types.h"



//  DC_SYS_64BIT_WRAPPER Register Address
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl                                     0x18007F00
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_reg_addr                            "0xB8007F00"
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_reg                                 0xB8007F00
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_inst_addr                           "0x0000"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_reg(data)                       (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_reg                             (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_cmd_inorder_shift                   (29)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_cmd_zero_bl_bypass_shift            (28)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_wcmd_fifo_th_shift                  (16)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_rcmd_fifo_th_shift                  (8)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_wait_wdone_th_shift                 (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_cmd_inorder_mask                    (0xE0000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_cmd_zero_bl_bypass_mask             (0x10000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_wcmd_fifo_th_mask                   (0x00070000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_rcmd_fifo_th_mask                   (0x00000700)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_wait_wdone_th_mask                  (0x0000001F)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_cmd_inorder(data)                   (0xE0000000&((data)<<29))
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_cmd_zero_bl_bypass(data)            (0x10000000&((data)<<28))
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_wcmd_fifo_th(data)                  (0x00070000&((data)<<16))
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_rcmd_fifo_th(data)                  (0x00000700&((data)<<8))
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_wait_wdone_th(data)                 (0x0000001F&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_get_cmd_inorder(data)               ((0xE0000000&(data))>>29)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_get_cmd_zero_bl_bypass(data)        ((0x10000000&(data))>>28)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_get_wcmd_fifo_th(data)              ((0x00070000&(data))>>16)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_get_rcmd_fifo_th(data)              ((0x00000700&(data))>>8)
#define  DC_SYS_64BIT_WRAPPER_DC_64_cmd_ctrl_get_wait_wdone_th(data)             (0x0000001F&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl                                     0x18007F04
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_reg_addr                            "0xB8007F04"
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_reg                                 0xB8007F04
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_inst_addr                           "0x0001"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_reg(data)                       (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_reg                             (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_full_transfer_shift                 (29)
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_wdata_fifo_th_shift                 (8)
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_rdata_fifo_th_shift                 (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_full_transfer_mask                  (0xE0000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_wdata_fifo_th_mask                  (0x00003F00)
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_rdata_fifo_th_mask                  (0x0000003F)
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_full_transfer(data)                 (0xE0000000&((data)<<29))
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_wdata_fifo_th(data)                 (0x00003F00&((data)<<8))
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_rdata_fifo_th(data)                 (0x0000003F&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_get_full_transfer(data)             ((0xE0000000&(data))>>29)
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_get_wdata_fifo_th(data)             ((0x00003F00&(data))>>8)
#define  DC_SYS_64BIT_WRAPPER_DC_64_buf_ctrl_get_rdata_fifo_th(data)             (0x0000003F&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio                               0x18007F10
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_reg_addr                      "0xB8007F10"
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_reg                           0xB8007F10
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_inst_addr                     "0x0002"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_reg(data)                 (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_reg                       (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_dbg_en_shift                  (31)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_err_bl_zero_shift             (30)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_err_blk_wxh_odd_shift         (29)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_wcmd_in_fifo_shift        (24)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_rcmd_in_fifo_shift        (20)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_wait_wdone_shift          (14)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_wdata_in_fifo_shift       (7)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_rdata_in_fifo_shift       (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_dbg_en_mask                   (0x80000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_err_bl_zero_mask              (0x40000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_err_blk_wxh_odd_mask          (0x20000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_wcmd_in_fifo_mask         (0x0F000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_rcmd_in_fifo_mask         (0x00F00000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_wait_wdone_mask           (0x000FC000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_wdata_in_fifo_mask        (0x00003F80)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_rdata_in_fifo_mask        (0x0000007F)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_dbg_en(data)                  (0x80000000&((data)<<31))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_err_bl_zero(data)             (0x40000000&((data)<<30))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_err_blk_wxh_odd(data)         (0x20000000&((data)<<29))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_wcmd_in_fifo(data)        (0x0F000000&((data)<<24))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_rcmd_in_fifo(data)        (0x00F00000&((data)<<20))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_wait_wdone(data)          (0x000FC000&((data)<<14))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_wdata_in_fifo(data)       (0x00003F80&((data)<<7))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_max_rdata_in_fifo(data)       (0x0000007F&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_get_dbg_en(data)              ((0x80000000&(data))>>31)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_get_err_bl_zero(data)         ((0x40000000&(data))>>30)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_get_err_blk_wxh_odd(data)     ((0x20000000&(data))>>29)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_get_max_wcmd_in_fifo(data)    ((0x0F000000&(data))>>24)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_get_max_rcmd_in_fifo(data)    ((0x00F00000&(data))>>20)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_get_max_wait_wdone(data)      ((0x000FC000&(data))>>14)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_get_max_wdata_in_fifo(data)   ((0x00003F80&(data))>>7)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_aio_get_max_rdata_in_fifo(data)   (0x0000007F&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1                               0x18007F14
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_reg_addr                      "0xB8007F14"
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_reg                           0xB8007F14
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_inst_addr                     "0x0003"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_reg(data)                 (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_reg                       (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_dbg_en_shift                  (31)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_err_bl_zero_shift             (30)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_err_blk_wxh_odd_shift         (29)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_wcmd_in_fifo_shift        (24)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_rcmd_in_fifo_shift        (20)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_wait_wdone_shift          (14)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_wdata_in_fifo_shift       (7)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_rdata_in_fifo_shift       (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_dbg_en_mask                   (0x80000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_err_bl_zero_mask              (0x40000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_err_blk_wxh_odd_mask          (0x20000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_wcmd_in_fifo_mask         (0x0F000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_rcmd_in_fifo_mask         (0x00F00000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_wait_wdone_mask           (0x000FC000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_wdata_in_fifo_mask        (0x00003F80)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_rdata_in_fifo_mask        (0x0000007F)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_dbg_en(data)                  (0x80000000&((data)<<31))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_err_bl_zero(data)             (0x40000000&((data)<<30))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_err_blk_wxh_odd(data)         (0x20000000&((data)<<29))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_wcmd_in_fifo(data)        (0x0F000000&((data)<<24))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_rcmd_in_fifo(data)        (0x00F00000&((data)<<20))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_wait_wdone(data)          (0x000FC000&((data)<<14))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_wdata_in_fifo(data)       (0x00003F80&((data)<<7))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_max_rdata_in_fifo(data)       (0x0000007F&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_get_dbg_en(data)              ((0x80000000&(data))>>31)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_get_err_bl_zero(data)         ((0x40000000&(data))>>30)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_get_err_blk_wxh_odd(data)     ((0x20000000&(data))>>29)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_get_max_wcmd_in_fifo(data)    ((0x0F000000&(data))>>24)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_get_max_rcmd_in_fifo(data)    ((0x00F00000&(data))>>20)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_get_max_wait_wdone(data)      ((0x000FC000&(data))>>14)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_get_max_wdata_in_fifo(data)   ((0x00003F80&(data))>>7)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb1_get_max_rdata_in_fifo(data)   (0x0000007F&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3                               0x18007F18
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_reg_addr                      "0xB8007F18"
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_reg                           0xB8007F18
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_inst_addr                     "0x0004"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_reg(data)                 (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_reg                       (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_dbg_en_shift                  (31)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_err_bl_zero_shift             (30)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_err_blk_wxh_odd_shift         (29)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_wcmd_in_fifo_shift        (24)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_rcmd_in_fifo_shift        (20)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_wait_wdone_shift          (14)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_wdata_in_fifo_shift       (7)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_rdata_in_fifo_shift       (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_dbg_en_mask                   (0x80000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_err_bl_zero_mask              (0x40000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_err_blk_wxh_odd_mask          (0x20000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_wcmd_in_fifo_mask         (0x0F000000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_rcmd_in_fifo_mask         (0x00F00000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_wait_wdone_mask           (0x000FC000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_wdata_in_fifo_mask        (0x00003F80)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_rdata_in_fifo_mask        (0x0000007F)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_dbg_en(data)                  (0x80000000&((data)<<31))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_err_bl_zero(data)             (0x40000000&((data)<<30))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_err_blk_wxh_odd(data)         (0x20000000&((data)<<29))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_wcmd_in_fifo(data)        (0x0F000000&((data)<<24))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_rcmd_in_fifo(data)        (0x00F00000&((data)<<20))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_wait_wdone(data)          (0x000FC000&((data)<<14))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_wdata_in_fifo(data)       (0x00003F80&((data)<<7))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_max_rdata_in_fifo(data)       (0x0000007F&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_get_dbg_en(data)              ((0x80000000&(data))>>31)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_get_err_bl_zero(data)         ((0x40000000&(data))>>30)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_get_err_blk_wxh_odd(data)     ((0x20000000&(data))>>29)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_get_max_wcmd_in_fifo(data)    ((0x0F000000&(data))>>24)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_get_max_rcmd_in_fifo(data)    ((0x00F00000&(data))>>20)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_get_max_wait_wdone(data)      ((0x000FC000&(data))>>14)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_get_max_wdata_in_fifo(data)   ((0x00003F80&(data))>>7)
#define  DC_SYS_64BIT_WRAPPER_DC_64_err_status_sb3_get_max_rdata_in_fifo(data)   (0x0000007F&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode                                    0x18007F80
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_reg_addr                           "0xB8007F80"
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_reg                                0xB8007F80
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_inst_addr                          "0x0005"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_reg(data)                      (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_reg                            (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_dc_bist_mode_wrap2_shift           (2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_dc_bist_mode_wrap1_shift           (1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_dc_bist_mode_wrap0_shift           (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_dc_bist_mode_wrap2_mask            (0x00000004)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_dc_bist_mode_wrap1_mask            (0x00000002)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_dc_bist_mode_wrap0_mask            (0x00000001)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_dc_bist_mode_wrap2(data)           (0x00000004&((data)<<2))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_dc_bist_mode_wrap1(data)           (0x00000002&((data)<<1))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_dc_bist_mode_wrap0(data)           (0x00000001&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_get_dc_bist_mode_wrap2(data)       ((0x00000004&(data))>>2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_get_dc_bist_mode_wrap1(data)       ((0x00000002&(data))>>1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_mode_get_dc_bist_mode_wrap0(data)       (0x00000001&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done                                    0x18007F84
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_reg_addr                           "0xB8007F84"
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_reg                                0xB8007F84
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_inst_addr                          "0x0006"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_bist_done_reg(data)                      (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_bist_done_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_bist_done_reg                            (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_bist_done_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_dc_bist_done_wrap2_shift           (2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_dc_bist_done_wrap1_shift           (1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_dc_bist_done_wrap0_shift           (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_dc_bist_done_wrap2_mask            (0x00000004)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_dc_bist_done_wrap1_mask            (0x00000002)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_dc_bist_done_wrap0_mask            (0x00000001)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_dc_bist_done_wrap2(data)           (0x00000004&((data)<<2))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_dc_bist_done_wrap1(data)           (0x00000002&((data)<<1))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_dc_bist_done_wrap0(data)           (0x00000001&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_get_dc_bist_done_wrap2(data)       ((0x00000004&(data))>>2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_get_dc_bist_done_wrap1(data)       ((0x00000002&(data))>>1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_done_get_dc_bist_done_wrap0(data)       (0x00000001&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail                                    0x18007F88
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_reg_addr                           "0xB8007F88"
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_reg                                0xB8007F88
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_inst_addr                          "0x0007"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_reg(data)                      (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_reg                            (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_dc_bist_fail_group_wrap2_shift     (2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_dc_bist_fail_group_wrap1_shift     (1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_dc_bist_fail_group_wrap0_shift     (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_dc_bist_fail_group_wrap2_mask      (0x00000004)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_dc_bist_fail_group_wrap1_mask      (0x00000002)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_dc_bist_fail_group_wrap0_mask      (0x00000001)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_dc_bist_fail_group_wrap2(data)     (0x00000004&((data)<<2))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_dc_bist_fail_group_wrap1(data)     (0x00000002&((data)<<1))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_dc_bist_fail_group_wrap0(data)     (0x00000001&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_get_dc_bist_fail_group_wrap2(data) ((0x00000004&(data))>>2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_get_dc_bist_fail_group_wrap1(data) ((0x00000002&(data))>>1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_fail_get_dc_bist_fail_group_wrap0(data) (0x00000001&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_drf                                          0x18007F8C
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_reg_addr                                 "0xB8007F8C"
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_reg                                      0xB8007F8C
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_inst_addr                                "0x0008"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_drf_reg(data)                            (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_drf_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_drf_reg                                  (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_drf_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_dc_drf_mode_wrap2_shift                  (2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_dc_drf_mode_wrap1_shift                  (1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_dc_drf_mode_wrap0_shift                  (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_dc_drf_mode_wrap2_mask                   (0x00000004)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_dc_drf_mode_wrap1_mask                   (0x00000002)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_dc_drf_mode_wrap0_mask                   (0x00000001)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_dc_drf_mode_wrap2(data)                  (0x00000004&((data)<<2))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_dc_drf_mode_wrap1(data)                  (0x00000002&((data)<<1))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_dc_drf_mode_wrap0(data)                  (0x00000001&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_get_dc_drf_mode_wrap2(data)              ((0x00000004&(data))>>2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_get_dc_drf_mode_wrap1(data)              ((0x00000002&(data))>>1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_get_dc_drf_mode_wrap0(data)              (0x00000001&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume                                   0x18007F90
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_reg_addr                          "0xB8007F90"
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_reg                               0xB8007F90
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_inst_addr                         "0x0009"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_reg(data)                     (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_reg                           (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_dc_drf_resume_wrap2_shift         (2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_dc_drf_resume_wrap1_shift         (1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_dc_drf_resume_wrap0_shift         (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_dc_drf_resume_wrap2_mask          (0x00000004)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_dc_drf_resume_wrap1_mask          (0x00000002)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_dc_drf_resume_wrap0_mask          (0x00000001)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_dc_drf_resume_wrap2(data)         (0x00000004&((data)<<2))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_dc_drf_resume_wrap1(data)         (0x00000002&((data)<<1))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_dc_drf_resume_wrap0(data)         (0x00000001&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_get_dc_drf_resume_wrap2(data)     ((0x00000004&(data))>>2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_get_dc_drf_resume_wrap1(data)     ((0x00000002&(data))>>1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_resume_get_dc_drf_resume_wrap0(data)     (0x00000001&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done                                     0x18007F94
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_reg_addr                            "0xB8007F94"
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_reg                                 0xB8007F94
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_inst_addr                           "0x000A"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_drf_done_reg(data)                       (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_drf_done_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_drf_done_reg                             (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_drf_done_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_dc_drf_done_wrap2_shift             (2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_dc_drf_done_wrap1_shift             (1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_dc_drf_done_wrap0_shift             (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_dc_drf_done_wrap2_mask              (0x00000004)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_dc_drf_done_wrap1_mask              (0x00000002)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_dc_drf_done_wrap0_mask              (0x00000001)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_dc_drf_done_wrap2(data)             (0x00000004&((data)<<2))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_dc_drf_done_wrap1(data)             (0x00000002&((data)<<1))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_dc_drf_done_wrap0(data)             (0x00000001&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_get_dc_drf_done_wrap2(data)         ((0x00000004&(data))>>2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_get_dc_drf_done_wrap1(data)         ((0x00000002&(data))>>1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_done_get_dc_drf_done_wrap0(data)         (0x00000001&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause                                    0x18007F98
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_reg_addr                           "0xB8007F98"
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_reg                                0xB8007F98
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_inst_addr                          "0x000B"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_reg(data)                      (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_reg                            (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_dc_drf_pause_wrap2_shift           (2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_dc_drf_pause_wrap1_shift           (1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_dc_drf_pause_wrap0_shift           (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_dc_drf_pause_wrap2_mask            (0x00000004)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_dc_drf_pause_wrap1_mask            (0x00000002)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_dc_drf_pause_wrap0_mask            (0x00000001)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_dc_drf_pause_wrap2(data)           (0x00000004&((data)<<2))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_dc_drf_pause_wrap1(data)           (0x00000002&((data)<<1))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_dc_drf_pause_wrap0(data)           (0x00000001&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_get_dc_drf_pause_wrap2(data)       ((0x00000004&(data))>>2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_get_dc_drf_pause_wrap1(data)       ((0x00000002&(data))>>1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_pause_get_dc_drf_pause_wrap0(data)       (0x00000001&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail                                     0x18007F9C
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_reg_addr                            "0xB8007F9C"
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_reg                                 0xB8007F9C
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_inst_addr                           "0x000C"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_reg(data)                       (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_reg                             (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_dc_drf_fail_group_wrap2_shift       (2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_dc_drf_fail_group_wrap1_shift       (1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_dc_drf_fail_group_wrap0_shift       (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_dc_drf_fail_group_wrap2_mask        (0x00000004)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_dc_drf_fail_group_wrap1_mask        (0x00000002)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_dc_drf_fail_group_wrap0_mask        (0x00000001)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_dc_drf_fail_group_wrap2(data)       (0x00000004&((data)<<2))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_dc_drf_fail_group_wrap1(data)       (0x00000002&((data)<<1))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_dc_drf_fail_group_wrap0(data)       (0x00000001&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_get_dc_drf_fail_group_wrap2(data)   ((0x00000004&(data))>>2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_get_dc_drf_fail_group_wrap1(data)   ((0x00000002&(data))>>1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_drf_fail_get_dc_drf_fail_group_wrap0(data)   (0x00000001&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail                                  0x18007FA0
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_reg_addr                         "0xB8007FA0"
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_reg                              0xB8007FA0
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_inst_addr                        "0x000D"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_reg(data)                    (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_reg                          (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap2_fail_1_shift        (11)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap2_fail_0_shift        (10)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap2_fail_1_shift       (9)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap2_fail_0_shift       (8)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap1_fail_1_shift        (7)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap1_fail_0_shift        (6)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap1_fail_1_shift       (5)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap1_fail_0_shift       (4)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap0_fail_1_shift        (3)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap0_fail_0_shift        (2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap0_fail_1_shift       (1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap0_fail_0_shift       (0)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap2_fail_1_mask         (0x00000800)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap2_fail_0_mask         (0x00000400)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap2_fail_1_mask        (0x00000200)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap2_fail_0_mask        (0x00000100)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap1_fail_1_mask         (0x00000080)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap1_fail_0_mask         (0x00000040)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap1_fail_1_mask        (0x00000020)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap1_fail_0_mask        (0x00000010)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap0_fail_1_mask         (0x00000008)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap0_fail_0_mask         (0x00000004)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap0_fail_1_mask        (0x00000002)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap0_fail_0_mask        (0x00000001)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap2_fail_1(data)        (0x00000800&((data)<<11))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap2_fail_0(data)        (0x00000400&((data)<<10))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap2_fail_1(data)       (0x00000200&((data)<<9))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap2_fail_0(data)       (0x00000100&((data)<<8))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap1_fail_1(data)        (0x00000080&((data)<<7))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap1_fail_0(data)        (0x00000040&((data)<<6))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap1_fail_1(data)       (0x00000020&((data)<<5))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap1_fail_0(data)       (0x00000010&((data)<<4))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap0_fail_1(data)        (0x00000008&((data)<<3))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_drf_wrap0_fail_0(data)        (0x00000004&((data)<<2))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap0_fail_1(data)       (0x00000002&((data)<<1))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_dc_bist_wrap0_fail_0(data)       (0x00000001&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_get_dc_drf_wrap2_fail_1(data)    ((0x00000800&(data))>>11)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_get_dc_drf_wrap2_fail_0(data)    ((0x00000400&(data))>>10)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_get_dc_bist_wrap2_fail_1(data)   ((0x00000200&(data))>>9)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_get_dc_bist_wrap2_fail_0(data)   ((0x00000100&(data))>>8)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_get_dc_drf_wrap1_fail_1(data)    ((0x00000080&(data))>>7)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_get_dc_drf_wrap1_fail_0(data)    ((0x00000040&(data))>>6)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_get_dc_bist_wrap1_fail_1(data)   ((0x00000020&(data))>>5)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_get_dc_bist_wrap1_fail_0(data)   ((0x00000010&(data))>>4)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_get_dc_drf_wrap0_fail_1(data)    ((0x00000008&(data))>>3)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_get_dc_drf_wrap0_fail_0(data)    ((0x00000004&(data))>>2)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_get_dc_bist_wrap0_fail_1(data)   ((0x00000002&(data))>>1)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_detail_get_dc_bist_wrap0_fail_0(data)   (0x00000001&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm                                      0x18007FA4
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_reg_addr                             "0xB8007FA4"
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_reg                                  0xB8007FA4
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_inst_addr                            "0x000E"
#define  set_DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_reg(data)                        (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_reg                              (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_rmea_shift                           (20)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_rma_shift                            (16)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_rmeb_shift                           (12)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_rmb_shift                            (8)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_rmea_mask                            (0x00100000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_rma_mask                             (0x000F0000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_rmeb_mask                            (0x00001000)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_rmb_mask                             (0x00000F00)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_rmea(data)                           (0x00100000&((data)<<20))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_rma(data)                            (0x000F0000&((data)<<16))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_rmeb(data)                           (0x00001000&((data)<<12))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_rmb(data)                            (0x00000F00&((data)<<8))
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_get_rmea(data)                       ((0x00100000&(data))>>20)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_get_rma(data)                        ((0x000F0000&(data))>>16)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_get_rmeb(data)                       ((0x00001000&(data))>>12)
#define  DC_SYS_64BIT_WRAPPER_DC_64_bist_rm_get_rmb(data)                        ((0x00000F00&(data))>>8)

#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST                                       0x18007FB0
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_reg_addr                              "0xB8007FB0"
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_reg                                   0xB8007FB0
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_inst_addr                             "0x000F"
#define  set_DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_reg(data)                         (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_reg                               (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_sf_tx_work_ro_tvsb1_shift             (8)
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_sf_tx_start_tvsb1_shift               (4)
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_sf_tx_mode_tvsb1_shift                (0)
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_sf_tx_work_ro_tvsb1_mask              (0x00000100)
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_sf_tx_start_tvsb1_mask                (0x00000010)
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_sf_tx_mode_tvsb1_mask                 (0x00000001)
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_sf_tx_work_ro_tvsb1(data)             (0x00000100&((data)<<8))
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_sf_tx_start_tvsb1(data)               (0x00000010&((data)<<4))
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_sf_tx_mode_tvsb1(data)                (0x00000001&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_get_sf_tx_work_ro_tvsb1(data)         ((0x00000100&(data))>>8)
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_get_sf_tx_start_tvsb1(data)           ((0x00000010&(data))>>4)
#define  DC_SYS_64BIT_WRAPPER_DC_SFTX_TEST_get_sf_tx_mode_tvsb1(data)            (0x00000001&(data))

#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST                                       0x18007FB4
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_reg_addr                              "0xB8007FB4"
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_reg                                   0xB8007FB4
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_inst_addr                             "0x0010"
#define  set_DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_reg(data)                         (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_reg)=data)
#define  get_DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_reg                               (*((volatile unsigned int*)DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_reg))
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_err_ro_tvsb1_shift              (16)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_done_ro_tvsb1_shift             (12)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_start_tvsb1_shift               (8)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_gated_tvsb1_shift               (4)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_mode_tvsb1_shift                (0)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_err_ro_tvsb1_mask               (0x00010000)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_done_ro_tvsb1_mask              (0x00001000)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_start_tvsb1_mask                (0x00000100)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_gated_tvsb1_mask                (0x00000010)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_mode_tvsb1_mask                 (0x00000001)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_err_ro_tvsb1(data)              (0x00010000&((data)<<16))
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_done_ro_tvsb1(data)             (0x00001000&((data)<<12))
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_start_tvsb1(data)               (0x00000100&((data)<<8))
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_gated_tvsb1(data)               (0x00000010&((data)<<4))
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_sf_rx_mode_tvsb1(data)                (0x00000001&(data))
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_get_sf_rx_err_ro_tvsb1(data)          ((0x00010000&(data))>>16)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_get_sf_rx_done_ro_tvsb1(data)         ((0x00001000&(data))>>12)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_get_sf_rx_start_tvsb1(data)           ((0x00000100&(data))>>8)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_get_sf_rx_gated_tvsb1(data)           ((0x00000010&(data))>>4)
#define  DC_SYS_64BIT_WRAPPER_DC_SFRX_TEST_get_sf_rx_mode_tvsb1(data)            (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DC_SYS_64BIT_WRAPPER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_inorder:3;
        RBus_UInt32  cmd_zero_bl_bypass:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  wcmd_fifo_th:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  rcmd_fifo_th:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  wait_wdone_th:5;
    };
}dc_sys_64bit_wrapper_dc_64_cmd_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  full_transfer:3;
        RBus_UInt32  res1:15;
        RBus_UInt32  wdata_fifo_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  rdata_fifo_th:6;
    };
}dc_sys_64bit_wrapper_dc_64_buf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_en:1;
        RBus_UInt32  err_bl_zero:1;
        RBus_UInt32  err_blk_wxh_odd:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  max_wcmd_in_fifo:4;
        RBus_UInt32  max_rcmd_in_fifo:4;
        RBus_UInt32  max_wait_wdone:6;
        RBus_UInt32  max_wdata_in_fifo:7;
        RBus_UInt32  max_rdata_in_fifo:7;
    };
}dc_sys_64bit_wrapper_dc_64_err_status_aio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_en:1;
        RBus_UInt32  err_bl_zero:1;
        RBus_UInt32  err_blk_wxh_odd:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  max_wcmd_in_fifo:4;
        RBus_UInt32  max_rcmd_in_fifo:4;
        RBus_UInt32  max_wait_wdone:6;
        RBus_UInt32  max_wdata_in_fifo:7;
        RBus_UInt32  max_rdata_in_fifo:7;
    };
}dc_sys_64bit_wrapper_dc_64_err_status_sb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_en:1;
        RBus_UInt32  err_bl_zero:1;
        RBus_UInt32  err_blk_wxh_odd:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  max_wcmd_in_fifo:4;
        RBus_UInt32  max_rcmd_in_fifo:4;
        RBus_UInt32  max_wait_wdone:6;
        RBus_UInt32  max_wdata_in_fifo:7;
        RBus_UInt32  max_rdata_in_fifo:7;
    };
}dc_sys_64bit_wrapper_dc_64_err_status_sb3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dc_bist_mode_wrap2:1;
        RBus_UInt32  dc_bist_mode_wrap1:1;
        RBus_UInt32  dc_bist_mode_wrap0:1;
    };
}dc_sys_64bit_wrapper_dc_64_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dc_bist_done_wrap2:1;
        RBus_UInt32  dc_bist_done_wrap1:1;
        RBus_UInt32  dc_bist_done_wrap0:1;
    };
}dc_sys_64bit_wrapper_dc_64_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dc_bist_fail_group_wrap2:1;
        RBus_UInt32  dc_bist_fail_group_wrap1:1;
        RBus_UInt32  dc_bist_fail_group_wrap0:1;
    };
}dc_sys_64bit_wrapper_dc_64_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dc_drf_mode_wrap2:1;
        RBus_UInt32  dc_drf_mode_wrap1:1;
        RBus_UInt32  dc_drf_mode_wrap0:1;
    };
}dc_sys_64bit_wrapper_dc_64_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dc_drf_resume_wrap2:1;
        RBus_UInt32  dc_drf_resume_wrap1:1;
        RBus_UInt32  dc_drf_resume_wrap0:1;
    };
}dc_sys_64bit_wrapper_dc_64_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dc_drf_done_wrap2:1;
        RBus_UInt32  dc_drf_done_wrap1:1;
        RBus_UInt32  dc_drf_done_wrap0:1;
    };
}dc_sys_64bit_wrapper_dc_64_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dc_drf_pause_wrap2:1;
        RBus_UInt32  dc_drf_pause_wrap1:1;
        RBus_UInt32  dc_drf_pause_wrap0:1;
    };
}dc_sys_64bit_wrapper_dc_64_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dc_drf_fail_group_wrap2:1;
        RBus_UInt32  dc_drf_fail_group_wrap1:1;
        RBus_UInt32  dc_drf_fail_group_wrap0:1;
    };
}dc_sys_64bit_wrapper_dc_64_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  dc_drf_wrap2_fail_1:1;
        RBus_UInt32  dc_drf_wrap2_fail_0:1;
        RBus_UInt32  dc_bist_wrap2_fail_1:1;
        RBus_UInt32  dc_bist_wrap2_fail_0:1;
        RBus_UInt32  dc_drf_wrap1_fail_1:1;
        RBus_UInt32  dc_drf_wrap1_fail_0:1;
        RBus_UInt32  dc_bist_wrap1_fail_1:1;
        RBus_UInt32  dc_bist_wrap1_fail_0:1;
        RBus_UInt32  dc_drf_wrap0_fail_1:1;
        RBus_UInt32  dc_drf_wrap0_fail_0:1;
        RBus_UInt32  dc_bist_wrap0_fail_1:1;
        RBus_UInt32  dc_bist_wrap0_fail_0:1;
    };
}dc_sys_64bit_wrapper_dc_64_bist_detail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  rmea:1;
        RBus_UInt32  rma:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  rmeb:1;
        RBus_UInt32  rmb:4;
        RBus_UInt32  res3:8;
    };
}dc_sys_64bit_wrapper_dc_64_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  sf_tx_work_ro_tvsb1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sf_tx_start_tvsb1:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sf_tx_mode_tvsb1:1;
    };
}dc_sys_64bit_wrapper_dc_sftx_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  sf_rx_err_ro_tvsb1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sf_rx_done_ro_tvsb1:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sf_rx_start_tvsb1:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  sf_rx_gated_tvsb1:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  sf_rx_mode_tvsb1:1;
    };
}dc_sys_64bit_wrapper_dc_sfrx_test_RBUS;

#else //apply LITTLE_ENDIAN

//======DC_SYS_64BIT_WRAPPER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wait_wdone_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  rcmd_fifo_th:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  wcmd_fifo_th:3;
        RBus_UInt32  res3:9;
        RBus_UInt32  cmd_zero_bl_bypass:1;
        RBus_UInt32  cmd_inorder:3;
    };
}dc_sys_64bit_wrapper_dc_64_cmd_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rdata_fifo_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  wdata_fifo_th:6;
        RBus_UInt32  res2:15;
        RBus_UInt32  full_transfer:3;
    };
}dc_sys_64bit_wrapper_dc_64_buf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_rdata_in_fifo:7;
        RBus_UInt32  max_wdata_in_fifo:7;
        RBus_UInt32  max_wait_wdone:6;
        RBus_UInt32  max_rcmd_in_fifo:4;
        RBus_UInt32  max_wcmd_in_fifo:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  err_blk_wxh_odd:1;
        RBus_UInt32  err_bl_zero:1;
        RBus_UInt32  dbg_en:1;
    };
}dc_sys_64bit_wrapper_dc_64_err_status_aio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_rdata_in_fifo:7;
        RBus_UInt32  max_wdata_in_fifo:7;
        RBus_UInt32  max_wait_wdone:6;
        RBus_UInt32  max_rcmd_in_fifo:4;
        RBus_UInt32  max_wcmd_in_fifo:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  err_blk_wxh_odd:1;
        RBus_UInt32  err_bl_zero:1;
        RBus_UInt32  dbg_en:1;
    };
}dc_sys_64bit_wrapper_dc_64_err_status_sb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_rdata_in_fifo:7;
        RBus_UInt32  max_wdata_in_fifo:7;
        RBus_UInt32  max_wait_wdone:6;
        RBus_UInt32  max_rcmd_in_fifo:4;
        RBus_UInt32  max_wcmd_in_fifo:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  err_blk_wxh_odd:1;
        RBus_UInt32  err_bl_zero:1;
        RBus_UInt32  dbg_en:1;
    };
}dc_sys_64bit_wrapper_dc_64_err_status_sb3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_bist_mode_wrap0:1;
        RBus_UInt32  dc_bist_mode_wrap1:1;
        RBus_UInt32  dc_bist_mode_wrap2:1;
        RBus_UInt32  res1:29;
    };
}dc_sys_64bit_wrapper_dc_64_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_bist_done_wrap0:1;
        RBus_UInt32  dc_bist_done_wrap1:1;
        RBus_UInt32  dc_bist_done_wrap2:1;
        RBus_UInt32  res1:29;
    };
}dc_sys_64bit_wrapper_dc_64_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_bist_fail_group_wrap0:1;
        RBus_UInt32  dc_bist_fail_group_wrap1:1;
        RBus_UInt32  dc_bist_fail_group_wrap2:1;
        RBus_UInt32  res1:29;
    };
}dc_sys_64bit_wrapper_dc_64_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_drf_mode_wrap0:1;
        RBus_UInt32  dc_drf_mode_wrap1:1;
        RBus_UInt32  dc_drf_mode_wrap2:1;
        RBus_UInt32  res1:29;
    };
}dc_sys_64bit_wrapper_dc_64_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_drf_resume_wrap0:1;
        RBus_UInt32  dc_drf_resume_wrap1:1;
        RBus_UInt32  dc_drf_resume_wrap2:1;
        RBus_UInt32  res1:29;
    };
}dc_sys_64bit_wrapper_dc_64_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_drf_done_wrap0:1;
        RBus_UInt32  dc_drf_done_wrap1:1;
        RBus_UInt32  dc_drf_done_wrap2:1;
        RBus_UInt32  res1:29;
    };
}dc_sys_64bit_wrapper_dc_64_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_drf_pause_wrap0:1;
        RBus_UInt32  dc_drf_pause_wrap1:1;
        RBus_UInt32  dc_drf_pause_wrap2:1;
        RBus_UInt32  res1:29;
    };
}dc_sys_64bit_wrapper_dc_64_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_drf_fail_group_wrap0:1;
        RBus_UInt32  dc_drf_fail_group_wrap1:1;
        RBus_UInt32  dc_drf_fail_group_wrap2:1;
        RBus_UInt32  res1:29;
    };
}dc_sys_64bit_wrapper_dc_64_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_bist_wrap0_fail_0:1;
        RBus_UInt32  dc_bist_wrap0_fail_1:1;
        RBus_UInt32  dc_drf_wrap0_fail_0:1;
        RBus_UInt32  dc_drf_wrap0_fail_1:1;
        RBus_UInt32  dc_bist_wrap1_fail_0:1;
        RBus_UInt32  dc_bist_wrap1_fail_1:1;
        RBus_UInt32  dc_drf_wrap1_fail_0:1;
        RBus_UInt32  dc_drf_wrap1_fail_1:1;
        RBus_UInt32  dc_bist_wrap2_fail_0:1;
        RBus_UInt32  dc_bist_wrap2_fail_1:1;
        RBus_UInt32  dc_drf_wrap2_fail_0:1;
        RBus_UInt32  dc_drf_wrap2_fail_1:1;
        RBus_UInt32  res1:20;
    };
}dc_sys_64bit_wrapper_dc_64_bist_detail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rmb:4;
        RBus_UInt32  rmeb:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rma:4;
        RBus_UInt32  rmea:1;
        RBus_UInt32  res3:11;
    };
}dc_sys_64bit_wrapper_dc_64_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_tx_mode_tvsb1:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sf_tx_start_tvsb1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sf_tx_work_ro_tvsb1:1;
        RBus_UInt32  res3:23;
    };
}dc_sys_64bit_wrapper_dc_sftx_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_rx_mode_tvsb1:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sf_rx_gated_tvsb1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sf_rx_start_tvsb1:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sf_rx_done_ro_tvsb1:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  sf_rx_err_ro_tvsb1:1;
        RBus_UInt32  res5:15;
    };
}dc_sys_64bit_wrapper_dc_sfrx_test_RBUS;




#endif 


#endif 
