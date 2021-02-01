/**
* @file Mac5-DesignSpec-SCPU_Wrapper_Spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SCPU_WRAPPER_REG_H_
#define _RBUS_SCPU_WRAPPER_REG_H_

#include "rbus_types.h"



//  SCPU_WRAPPER Register Address
#define  SCPU_WRAPPER_cssys_apb1                                                 0x1805C000
#define  SCPU_WRAPPER_cssys_apb1_reg_addr                                        "0xB805C000"
#define  SCPU_WRAPPER_cssys_apb1_reg                                             0xB805C000
#define  SCPU_WRAPPER_cssys_apb1_inst_addr                                       "0x0000"
#define  set_SCPU_WRAPPER_cssys_apb1_reg(data)                                   (*((volatile unsigned int*)SCPU_WRAPPER_cssys_apb1_reg)=data)
#define  get_SCPU_WRAPPER_cssys_apb1_reg                                         (*((volatile unsigned int*)SCPU_WRAPPER_cssys_apb1_reg))
#define  SCPU_WRAPPER_cssys_apb1_apb_cssys_a_shift                               (0)
#define  SCPU_WRAPPER_cssys_apb1_apb_cssys_a_mask                                (0xFFFFFFFF)
#define  SCPU_WRAPPER_cssys_apb1_apb_cssys_a(data)                               (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_cssys_apb1_get_apb_cssys_a(data)                           (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_cssys_apb2                                                 0x1805C004
#define  SCPU_WRAPPER_cssys_apb2_reg_addr                                        "0xB805C004"
#define  SCPU_WRAPPER_cssys_apb2_reg                                             0xB805C004
#define  SCPU_WRAPPER_cssys_apb2_inst_addr                                       "0x0001"
#define  set_SCPU_WRAPPER_cssys_apb2_reg(data)                                   (*((volatile unsigned int*)SCPU_WRAPPER_cssys_apb2_reg)=data)
#define  get_SCPU_WRAPPER_cssys_apb2_reg                                         (*((volatile unsigned int*)SCPU_WRAPPER_cssys_apb2_reg))
#define  SCPU_WRAPPER_cssys_apb2_apb_cssys_d_shift                               (0)
#define  SCPU_WRAPPER_cssys_apb2_apb_cssys_d_mask                                (0xFFFFFFFF)
#define  SCPU_WRAPPER_cssys_apb2_apb_cssys_d(data)                               (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_cssys_apb2_get_apb_cssys_d(data)                           (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_cssys_apb3                                                 0x1805C008
#define  SCPU_WRAPPER_cssys_apb3_reg_addr                                        "0xB805C008"
#define  SCPU_WRAPPER_cssys_apb3_reg                                             0xB805C008
#define  SCPU_WRAPPER_cssys_apb3_inst_addr                                       "0x0002"
#define  set_SCPU_WRAPPER_cssys_apb3_reg(data)                                   (*((volatile unsigned int*)SCPU_WRAPPER_cssys_apb3_reg)=data)
#define  get_SCPU_WRAPPER_cssys_apb3_reg                                         (*((volatile unsigned int*)SCPU_WRAPPER_cssys_apb3_reg))
#define  SCPU_WRAPPER_cssys_apb3_apb_cssys_slverr_shift                          (0)
#define  SCPU_WRAPPER_cssys_apb3_apb_cssys_slverr_mask                           (0x00000001)
#define  SCPU_WRAPPER_cssys_apb3_apb_cssys_slverr(data)                          (0x00000001&(data))
#define  SCPU_WRAPPER_cssys_apb3_get_apb_cssys_slverr(data)                      (0x00000001&(data))

#define  SCPU_WRAPPER_wrapper_cfg1                                               0x1805C010
#define  SCPU_WRAPPER_wrapper_cfg1_reg_addr                                      "0xB805C010"
#define  SCPU_WRAPPER_wrapper_cfg1_reg                                           0xB805C010
#define  SCPU_WRAPPER_wrapper_cfg1_inst_addr                                     "0x0003"
#define  set_SCPU_WRAPPER_wrapper_cfg1_reg(data)                                 (*((volatile unsigned int*)SCPU_WRAPPER_wrapper_cfg1_reg)=data)
#define  get_SCPU_WRAPPER_wrapper_cfg1_reg                                       (*((volatile unsigned int*)SCPU_WRAPPER_wrapper_cfg1_reg))
#define  SCPU_WRAPPER_wrapper_cfg1_chk_invalid_cmd_shift                         (19)
#define  SCPU_WRAPPER_wrapper_cfg1_fbusrandwstrb_shift                           (18)
#define  SCPU_WRAPPER_wrapper_cfg1_remote_cmd_num_shift                          (14)
#define  SCPU_WRAPPER_wrapper_cfg1_remote_wdata_num_shift                        (10)
#define  SCPU_WRAPPER_wrapper_cfg1_all_wr_nonbuf_shift                           (8)
#define  SCPU_WRAPPER_wrapper_cfg1_wr_outstand_num_shift                         (4)
#define  SCPU_WRAPPER_wrapper_cfg1_rd_outstand_num_shift                         (0)
#define  SCPU_WRAPPER_wrapper_cfg1_chk_invalid_cmd_mask                          (0x00080000)
#define  SCPU_WRAPPER_wrapper_cfg1_fbusrandwstrb_mask                            (0x00040000)
#define  SCPU_WRAPPER_wrapper_cfg1_remote_cmd_num_mask                           (0x0003C000)
#define  SCPU_WRAPPER_wrapper_cfg1_remote_wdata_num_mask                         (0x00003C00)
#define  SCPU_WRAPPER_wrapper_cfg1_all_wr_nonbuf_mask                            (0x00000100)
#define  SCPU_WRAPPER_wrapper_cfg1_wr_outstand_num_mask                          (0x000000F0)
#define  SCPU_WRAPPER_wrapper_cfg1_rd_outstand_num_mask                          (0x0000000F)
#define  SCPU_WRAPPER_wrapper_cfg1_chk_invalid_cmd(data)                         (0x00080000&((data)<<19))
#define  SCPU_WRAPPER_wrapper_cfg1_fbusrandwstrb(data)                           (0x00040000&((data)<<18))
#define  SCPU_WRAPPER_wrapper_cfg1_remote_cmd_num(data)                          (0x0003C000&((data)<<14))
#define  SCPU_WRAPPER_wrapper_cfg1_remote_wdata_num(data)                        (0x00003C00&((data)<<10))
#define  SCPU_WRAPPER_wrapper_cfg1_all_wr_nonbuf(data)                           (0x00000100&((data)<<8))
#define  SCPU_WRAPPER_wrapper_cfg1_wr_outstand_num(data)                         (0x000000F0&((data)<<4))
#define  SCPU_WRAPPER_wrapper_cfg1_rd_outstand_num(data)                         (0x0000000F&(data))
#define  SCPU_WRAPPER_wrapper_cfg1_get_chk_invalid_cmd(data)                     ((0x00080000&(data))>>19)
#define  SCPU_WRAPPER_wrapper_cfg1_get_fbusrandwstrb(data)                       ((0x00040000&(data))>>18)
#define  SCPU_WRAPPER_wrapper_cfg1_get_remote_cmd_num(data)                      ((0x0003C000&(data))>>14)
#define  SCPU_WRAPPER_wrapper_cfg1_get_remote_wdata_num(data)                    ((0x00003C00&(data))>>10)
#define  SCPU_WRAPPER_wrapper_cfg1_get_all_wr_nonbuf(data)                       ((0x00000100&(data))>>8)
#define  SCPU_WRAPPER_wrapper_cfg1_get_wr_outstand_num(data)                     ((0x000000F0&(data))>>4)
#define  SCPU_WRAPPER_wrapper_cfg1_get_rd_outstand_num(data)                     (0x0000000F&(data))

#define  SCPU_WRAPPER_wrapper_cfg2                                               0x1805C014
#define  SCPU_WRAPPER_wrapper_cfg2_reg_addr                                      "0xB805C014"
#define  SCPU_WRAPPER_wrapper_cfg2_reg                                           0xB805C014
#define  SCPU_WRAPPER_wrapper_cfg2_inst_addr                                     "0x0004"
#define  set_SCPU_WRAPPER_wrapper_cfg2_reg(data)                                 (*((volatile unsigned int*)SCPU_WRAPPER_wrapper_cfg2_reg)=data)
#define  get_SCPU_WRAPPER_wrapper_cfg2_reg                                       (*((volatile unsigned int*)SCPU_WRAPPER_wrapper_cfg2_reg))
#define  SCPU_WRAPPER_wrapper_cfg2_scpu_dbg_sel_shift                            (0)
#define  SCPU_WRAPPER_wrapper_cfg2_scpu_dbg_sel_mask                             (0x0000000F)
#define  SCPU_WRAPPER_wrapper_cfg2_scpu_dbg_sel(data)                            (0x0000000F&(data))
#define  SCPU_WRAPPER_wrapper_cfg2_get_scpu_dbg_sel(data)                        (0x0000000F&(data))

#define  SCPU_WRAPPER_dbg_sel_ctrl                                               0x1805C018
#define  SCPU_WRAPPER_dbg_sel_ctrl_reg_addr                                      "0xB805C018"
#define  SCPU_WRAPPER_dbg_sel_ctrl_reg                                           0xB805C018
#define  SCPU_WRAPPER_dbg_sel_ctrl_inst_addr                                     "0x0005"
#define  set_SCPU_WRAPPER_dbg_sel_ctrl_reg(data)                                 (*((volatile unsigned int*)SCPU_WRAPPER_dbg_sel_ctrl_reg)=data)
#define  get_SCPU_WRAPPER_dbg_sel_ctrl_reg                                       (*((volatile unsigned int*)SCPU_WRAPPER_dbg_sel_ctrl_reg))
#define  SCPU_WRAPPER_dbg_sel_ctrl_scpu_dbg_mode_sel_shift                       (12)
#define  SCPU_WRAPPER_dbg_sel_ctrl_scpu_dbg_sel_dc_shift                         (8)
#define  SCPU_WRAPPER_dbg_sel_ctrl_scpu_dbg_sel_fr_shift                         (4)
#define  SCPU_WRAPPER_dbg_sel_ctrl_scpu_dbg_sel_dis_shift                        (0)
#define  SCPU_WRAPPER_dbg_sel_ctrl_scpu_dbg_mode_sel_mask                        (0x00003000)
#define  SCPU_WRAPPER_dbg_sel_ctrl_scpu_dbg_sel_dc_mask                          (0x00000F00)
#define  SCPU_WRAPPER_dbg_sel_ctrl_scpu_dbg_sel_fr_mask                          (0x000000F0)
#define  SCPU_WRAPPER_dbg_sel_ctrl_scpu_dbg_sel_dis_mask                         (0x0000000F)
#define  SCPU_WRAPPER_dbg_sel_ctrl_scpu_dbg_mode_sel(data)                       (0x00003000&((data)<<12))
#define  SCPU_WRAPPER_dbg_sel_ctrl_scpu_dbg_sel_dc(data)                         (0x00000F00&((data)<<8))
#define  SCPU_WRAPPER_dbg_sel_ctrl_scpu_dbg_sel_fr(data)                         (0x000000F0&((data)<<4))
#define  SCPU_WRAPPER_dbg_sel_ctrl_scpu_dbg_sel_dis(data)                        (0x0000000F&(data))
#define  SCPU_WRAPPER_dbg_sel_ctrl_get_scpu_dbg_mode_sel(data)                   ((0x00003000&(data))>>12)
#define  SCPU_WRAPPER_dbg_sel_ctrl_get_scpu_dbg_sel_dc(data)                     ((0x00000F00&(data))>>8)
#define  SCPU_WRAPPER_dbg_sel_ctrl_get_scpu_dbg_sel_fr(data)                     ((0x000000F0&(data))>>4)
#define  SCPU_WRAPPER_dbg_sel_ctrl_get_scpu_dbg_sel_dis(data)                    (0x0000000F&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_start_0                                      0x1805C020
#define  SCPU_WRAPPER_mem_trash_dbg_start_0_reg_addr                             "0xB805C020"
#define  SCPU_WRAPPER_mem_trash_dbg_start_0_reg                                  0xB805C020
#define  SCPU_WRAPPER_mem_trash_dbg_start_0_inst_addr                            "0x0006"
#define  set_SCPU_WRAPPER_mem_trash_dbg_start_0_reg(data)                        (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_start_0_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_start_0_reg                              (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_start_0_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_start_0_dbg_start_addr_m0_shift              (0)
#define  SCPU_WRAPPER_mem_trash_dbg_start_0_dbg_start_addr_m0_mask               (0xFFFFFFFF)
#define  SCPU_WRAPPER_mem_trash_dbg_start_0_dbg_start_addr_m0(data)              (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_start_0_get_dbg_start_addr_m0(data)          (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_start_1                                      0x1805C024
#define  SCPU_WRAPPER_mem_trash_dbg_start_1_reg_addr                             "0xB805C024"
#define  SCPU_WRAPPER_mem_trash_dbg_start_1_reg                                  0xB805C024
#define  SCPU_WRAPPER_mem_trash_dbg_start_1_inst_addr                            "0x0007"
#define  set_SCPU_WRAPPER_mem_trash_dbg_start_1_reg(data)                        (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_start_1_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_start_1_reg                              (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_start_1_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_start_1_dbg_start_addr_m0_shift              (0)
#define  SCPU_WRAPPER_mem_trash_dbg_start_1_dbg_start_addr_m0_mask               (0xFFFFFFFF)
#define  SCPU_WRAPPER_mem_trash_dbg_start_1_dbg_start_addr_m0(data)              (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_start_1_get_dbg_start_addr_m0(data)          (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_start_2                                      0x1805C028
#define  SCPU_WRAPPER_mem_trash_dbg_start_2_reg_addr                             "0xB805C028"
#define  SCPU_WRAPPER_mem_trash_dbg_start_2_reg                                  0xB805C028
#define  SCPU_WRAPPER_mem_trash_dbg_start_2_inst_addr                            "0x0008"
#define  set_SCPU_WRAPPER_mem_trash_dbg_start_2_reg(data)                        (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_start_2_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_start_2_reg                              (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_start_2_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_start_2_dbg_start_addr_m0_shift              (0)
#define  SCPU_WRAPPER_mem_trash_dbg_start_2_dbg_start_addr_m0_mask               (0xFFFFFFFF)
#define  SCPU_WRAPPER_mem_trash_dbg_start_2_dbg_start_addr_m0(data)              (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_start_2_get_dbg_start_addr_m0(data)          (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_start_3                                      0x1805C02C
#define  SCPU_WRAPPER_mem_trash_dbg_start_3_reg_addr                             "0xB805C02C"
#define  SCPU_WRAPPER_mem_trash_dbg_start_3_reg                                  0xB805C02C
#define  SCPU_WRAPPER_mem_trash_dbg_start_3_inst_addr                            "0x0009"
#define  set_SCPU_WRAPPER_mem_trash_dbg_start_3_reg(data)                        (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_start_3_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_start_3_reg                              (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_start_3_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_start_3_dbg_start_addr_m0_shift              (0)
#define  SCPU_WRAPPER_mem_trash_dbg_start_3_dbg_start_addr_m0_mask               (0xFFFFFFFF)
#define  SCPU_WRAPPER_mem_trash_dbg_start_3_dbg_start_addr_m0(data)              (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_start_3_get_dbg_start_addr_m0(data)          (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_end_0                                        0x1805C030
#define  SCPU_WRAPPER_mem_trash_dbg_end_0_reg_addr                               "0xB805C030"
#define  SCPU_WRAPPER_mem_trash_dbg_end_0_reg                                    0xB805C030
#define  SCPU_WRAPPER_mem_trash_dbg_end_0_inst_addr                              "0x000A"
#define  set_SCPU_WRAPPER_mem_trash_dbg_end_0_reg(data)                          (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_end_0_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_end_0_reg                                (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_end_0_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_end_0_dbg_end_addr_m0_shift                  (0)
#define  SCPU_WRAPPER_mem_trash_dbg_end_0_dbg_end_addr_m0_mask                   (0xFFFFFFFF)
#define  SCPU_WRAPPER_mem_trash_dbg_end_0_dbg_end_addr_m0(data)                  (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_end_0_get_dbg_end_addr_m0(data)              (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_end_1                                        0x1805C034
#define  SCPU_WRAPPER_mem_trash_dbg_end_1_reg_addr                               "0xB805C034"
#define  SCPU_WRAPPER_mem_trash_dbg_end_1_reg                                    0xB805C034
#define  SCPU_WRAPPER_mem_trash_dbg_end_1_inst_addr                              "0x000B"
#define  set_SCPU_WRAPPER_mem_trash_dbg_end_1_reg(data)                          (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_end_1_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_end_1_reg                                (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_end_1_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_end_1_dbg_end_addr_m0_shift                  (0)
#define  SCPU_WRAPPER_mem_trash_dbg_end_1_dbg_end_addr_m0_mask                   (0xFFFFFFFF)
#define  SCPU_WRAPPER_mem_trash_dbg_end_1_dbg_end_addr_m0(data)                  (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_end_1_get_dbg_end_addr_m0(data)              (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_end_2                                        0x1805C038
#define  SCPU_WRAPPER_mem_trash_dbg_end_2_reg_addr                               "0xB805C038"
#define  SCPU_WRAPPER_mem_trash_dbg_end_2_reg                                    0xB805C038
#define  SCPU_WRAPPER_mem_trash_dbg_end_2_inst_addr                              "0x000C"
#define  set_SCPU_WRAPPER_mem_trash_dbg_end_2_reg(data)                          (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_end_2_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_end_2_reg                                (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_end_2_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_end_2_dbg_end_addr_m0_shift                  (0)
#define  SCPU_WRAPPER_mem_trash_dbg_end_2_dbg_end_addr_m0_mask                   (0xFFFFFFFF)
#define  SCPU_WRAPPER_mem_trash_dbg_end_2_dbg_end_addr_m0(data)                  (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_end_2_get_dbg_end_addr_m0(data)              (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_end_3                                        0x1805C03C
#define  SCPU_WRAPPER_mem_trash_dbg_end_3_reg_addr                               "0xB805C03C"
#define  SCPU_WRAPPER_mem_trash_dbg_end_3_reg                                    0xB805C03C
#define  SCPU_WRAPPER_mem_trash_dbg_end_3_inst_addr                              "0x000D"
#define  set_SCPU_WRAPPER_mem_trash_dbg_end_3_reg(data)                          (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_end_3_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_end_3_reg                                (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_end_3_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_end_3_dbg_end_addr_m0_shift                  (0)
#define  SCPU_WRAPPER_mem_trash_dbg_end_3_dbg_end_addr_m0_mask                   (0xFFFFFFFF)
#define  SCPU_WRAPPER_mem_trash_dbg_end_3_dbg_end_addr_m0(data)                  (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_end_3_get_dbg_end_addr_m0(data)              (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0                                       0x1805C040
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_reg_addr                              "0xB805C040"
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_reg                                   0xB805C040
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_inst_addr                             "0x000E"
#define  set_SCPU_WRAPPER_mem_trash_dbg_ctrl_0_reg(data)                         (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_ctrl_0_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_ctrl_0_reg                               (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_ctrl_0_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_write_en2_shift                       (4)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_dbg_wr_chk_m0_shift                   (2)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_write_en1_shift                       (1)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_dbg_en_m0_shift                       (0)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_write_en2_mask                        (0x00000010)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_dbg_wr_chk_m0_mask                    (0x0000000C)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_write_en1_mask                        (0x00000002)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_dbg_en_m0_mask                        (0x00000001)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_write_en2(data)                       (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_dbg_wr_chk_m0(data)                   (0x0000000C&((data)<<2))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_write_en1(data)                       (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_dbg_en_m0(data)                       (0x00000001&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_get_write_en2(data)                   ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_get_dbg_wr_chk_m0(data)               ((0x0000000C&(data))>>2)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_get_write_en1(data)                   ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_0_get_dbg_en_m0(data)                   (0x00000001&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1                                       0x1805C044
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_reg_addr                              "0xB805C044"
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_reg                                   0xB805C044
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_inst_addr                             "0x000F"
#define  set_SCPU_WRAPPER_mem_trash_dbg_ctrl_1_reg(data)                         (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_ctrl_1_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_ctrl_1_reg                               (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_ctrl_1_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_write_en2_shift                       (4)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_dbg_wr_chk_m0_shift                   (2)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_write_en1_shift                       (1)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_dbg_en_m0_shift                       (0)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_write_en2_mask                        (0x00000010)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_dbg_wr_chk_m0_mask                    (0x0000000C)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_write_en1_mask                        (0x00000002)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_dbg_en_m0_mask                        (0x00000001)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_write_en2(data)                       (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_dbg_wr_chk_m0(data)                   (0x0000000C&((data)<<2))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_write_en1(data)                       (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_dbg_en_m0(data)                       (0x00000001&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_get_write_en2(data)                   ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_get_dbg_wr_chk_m0(data)               ((0x0000000C&(data))>>2)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_get_write_en1(data)                   ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_1_get_dbg_en_m0(data)                   (0x00000001&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2                                       0x1805C048
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_reg_addr                              "0xB805C048"
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_reg                                   0xB805C048
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_inst_addr                             "0x0010"
#define  set_SCPU_WRAPPER_mem_trash_dbg_ctrl_2_reg(data)                         (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_ctrl_2_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_ctrl_2_reg                               (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_ctrl_2_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_write_en2_shift                       (4)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_dbg_wr_chk_m0_shift                   (2)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_write_en1_shift                       (1)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_dbg_en_m0_shift                       (0)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_write_en2_mask                        (0x00000010)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_dbg_wr_chk_m0_mask                    (0x0000000C)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_write_en1_mask                        (0x00000002)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_dbg_en_m0_mask                        (0x00000001)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_write_en2(data)                       (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_dbg_wr_chk_m0(data)                   (0x0000000C&((data)<<2))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_write_en1(data)                       (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_dbg_en_m0(data)                       (0x00000001&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_get_write_en2(data)                   ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_get_dbg_wr_chk_m0(data)               ((0x0000000C&(data))>>2)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_get_write_en1(data)                   ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_2_get_dbg_en_m0(data)                   (0x00000001&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3                                       0x1805C04C
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_reg_addr                              "0xB805C04C"
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_reg                                   0xB805C04C
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_inst_addr                             "0x0011"
#define  set_SCPU_WRAPPER_mem_trash_dbg_ctrl_3_reg(data)                         (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_ctrl_3_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_ctrl_3_reg                               (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_ctrl_3_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_write_en2_shift                       (4)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_dbg_wr_chk_m0_shift                   (2)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_write_en1_shift                       (1)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_dbg_en_m0_shift                       (0)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_write_en2_mask                        (0x00000010)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_dbg_wr_chk_m0_mask                    (0x0000000C)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_write_en1_mask                        (0x00000002)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_dbg_en_m0_mask                        (0x00000001)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_write_en2(data)                       (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_dbg_wr_chk_m0(data)                   (0x0000000C&((data)<<2))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_write_en1(data)                       (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_dbg_en_m0(data)                       (0x00000001&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_get_write_en2(data)                   ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_get_dbg_wr_chk_m0(data)               ((0x0000000C&(data))>>2)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_get_write_en1(data)                   ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_mem_trash_dbg_ctrl_3_get_dbg_en_m0(data)                   (0x00000001&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_int                                          0x1805C050
#define  SCPU_WRAPPER_mem_trash_dbg_int_reg_addr                                 "0xB805C050"
#define  SCPU_WRAPPER_mem_trash_dbg_int_reg                                      0xB805C050
#define  SCPU_WRAPPER_mem_trash_dbg_int_inst_addr                                "0x0012"
#define  set_SCPU_WRAPPER_mem_trash_dbg_int_reg(data)                            (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_int_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_int_reg                                  (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_int_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_int_scpu_int_m0_shift                        (4)
#define  SCPU_WRAPPER_mem_trash_dbg_int_scpu_int_en_m0_shift                     (3)
#define  SCPU_WRAPPER_mem_trash_dbg_int_scpu_neg_int_m0_shift                    (2)
#define  SCPU_WRAPPER_mem_trash_dbg_int_scpu_neg_int_en_m0_shift                 (1)
#define  SCPU_WRAPPER_mem_trash_dbg_int_write_data_shift                         (0)
#define  SCPU_WRAPPER_mem_trash_dbg_int_scpu_int_m0_mask                         (0x00000010)
#define  SCPU_WRAPPER_mem_trash_dbg_int_scpu_int_en_m0_mask                      (0x00000008)
#define  SCPU_WRAPPER_mem_trash_dbg_int_scpu_neg_int_m0_mask                     (0x00000004)
#define  SCPU_WRAPPER_mem_trash_dbg_int_scpu_neg_int_en_m0_mask                  (0x00000002)
#define  SCPU_WRAPPER_mem_trash_dbg_int_write_data_mask                          (0x00000001)
#define  SCPU_WRAPPER_mem_trash_dbg_int_scpu_int_m0(data)                        (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_mem_trash_dbg_int_scpu_int_en_m0(data)                     (0x00000008&((data)<<3))
#define  SCPU_WRAPPER_mem_trash_dbg_int_scpu_neg_int_m0(data)                    (0x00000004&((data)<<2))
#define  SCPU_WRAPPER_mem_trash_dbg_int_scpu_neg_int_en_m0(data)                 (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_mem_trash_dbg_int_write_data(data)                         (0x00000001&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_int_get_scpu_int_m0(data)                    ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_mem_trash_dbg_int_get_scpu_int_en_m0(data)                 ((0x00000008&(data))>>3)
#define  SCPU_WRAPPER_mem_trash_dbg_int_get_scpu_neg_int_m0(data)                ((0x00000004&(data))>>2)
#define  SCPU_WRAPPER_mem_trash_dbg_int_get_scpu_neg_int_en_m0(data)             ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_mem_trash_dbg_int_get_write_data(data)                     (0x00000001&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_addr                                         0x1805C054
#define  SCPU_WRAPPER_mem_trash_dbg_addr_reg_addr                                "0xB805C054"
#define  SCPU_WRAPPER_mem_trash_dbg_addr_reg                                     0xB805C054
#define  SCPU_WRAPPER_mem_trash_dbg_addr_inst_addr                               "0x0013"
#define  set_SCPU_WRAPPER_mem_trash_dbg_addr_reg(data)                           (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_addr_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_addr_reg                                 (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_addr_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_addr_dbg_addr_m0_shift                       (0)
#define  SCPU_WRAPPER_mem_trash_dbg_addr_dbg_addr_m0_mask                        (0xFFFFFFFF)
#define  SCPU_WRAPPER_mem_trash_dbg_addr_dbg_addr_m0(data)                       (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_addr_get_dbg_addr_m0(data)                   (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_mem_trash_dbg_rw                                           0x1805C058
#define  SCPU_WRAPPER_mem_trash_dbg_rw_reg_addr                                  "0xB805C058"
#define  SCPU_WRAPPER_mem_trash_dbg_rw_reg                                       0xB805C058
#define  SCPU_WRAPPER_mem_trash_dbg_rw_inst_addr                                 "0x0014"
#define  set_SCPU_WRAPPER_mem_trash_dbg_rw_reg(data)                             (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_rw_reg)=data)
#define  get_SCPU_WRAPPER_mem_trash_dbg_rw_reg                                   (*((volatile unsigned int*)SCPU_WRAPPER_mem_trash_dbg_rw_reg))
#define  SCPU_WRAPPER_mem_trash_dbg_rw_scpu_dbg_write_m0_shift                   (0)
#define  SCPU_WRAPPER_mem_trash_dbg_rw_scpu_dbg_write_m0_mask                    (0x00000001)
#define  SCPU_WRAPPER_mem_trash_dbg_rw_scpu_dbg_write_m0(data)                   (0x00000001&(data))
#define  SCPU_WRAPPER_mem_trash_dbg_rw_get_scpu_dbg_write_m0(data)               (0x00000001&(data))

#define  SCPU_WRAPPER_eco_rw_reg                                                 0x1805C090
#define  SCPU_WRAPPER_eco_rw_reg_reg_addr                                        "0xB805C090"
#define  SCPU_WRAPPER_eco_rw_reg_reg                                             0xB805C090
#define  SCPU_WRAPPER_eco_rw_reg_inst_addr                                       "0x0015"
#define  set_SCPU_WRAPPER_eco_rw_reg_reg(data)                                   (*((volatile unsigned int*)SCPU_WRAPPER_eco_rw_reg_reg)=data)
#define  get_SCPU_WRAPPER_eco_rw_reg_reg                                         (*((volatile unsigned int*)SCPU_WRAPPER_eco_rw_reg_reg))
#define  SCPU_WRAPPER_eco_rw_reg_eco_rw_shift                                    (0)
#define  SCPU_WRAPPER_eco_rw_reg_eco_rw_mask                                     (0xFFFFFFFF)
#define  SCPU_WRAPPER_eco_rw_reg_eco_rw(data)                                    (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_eco_rw_reg_get_eco_rw(data)                                (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_eco_r_reg                                                  0x1805C094
#define  SCPU_WRAPPER_eco_r_reg_reg_addr                                         "0xB805C094"
#define  SCPU_WRAPPER_eco_r_reg_reg                                              0xB805C094
#define  SCPU_WRAPPER_eco_r_reg_inst_addr                                        "0x0016"
#define  set_SCPU_WRAPPER_eco_r_reg_reg(data)                                    (*((volatile unsigned int*)SCPU_WRAPPER_eco_r_reg_reg)=data)
#define  get_SCPU_WRAPPER_eco_r_reg_reg                                          (*((volatile unsigned int*)SCPU_WRAPPER_eco_r_reg_reg))
#define  SCPU_WRAPPER_eco_r_reg_eco_r_only_shift                                 (0)
#define  SCPU_WRAPPER_eco_r_reg_eco_r_only_mask                                  (0xFFFFFFFF)
#define  SCPU_WRAPPER_eco_r_reg_eco_r_only(data)                                 (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_eco_r_reg_get_eco_r_only(data)                             (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_debugaxi128b_1                                             0x1805C600
#define  SCPU_WRAPPER_debugaxi128b_1_reg_addr                                    "0xB805C600"
#define  SCPU_WRAPPER_debugaxi128b_1_reg                                         0xB805C600
#define  SCPU_WRAPPER_debugaxi128b_1_inst_addr                                   "0x0017"
#define  set_SCPU_WRAPPER_debugaxi128b_1_reg(data)                               (*((volatile unsigned int*)SCPU_WRAPPER_debugaxi128b_1_reg)=data)
#define  get_SCPU_WRAPPER_debugaxi128b_1_reg                                     (*((volatile unsigned int*)SCPU_WRAPPER_debugaxi128b_1_reg))
#define  SCPU_WRAPPER_debugaxi128b_1_scpu_axi_bready_shift                       (5)
#define  SCPU_WRAPPER_debugaxi128b_1_axi_rdata_fifo_empty_shift                  (4)
#define  SCPU_WRAPPER_debugaxi128b_1_axi_wid_empty_shift                         (3)
#define  SCPU_WRAPPER_debugaxi128b_1_axi_wdata_fifo_empty_shift                  (2)
#define  SCPU_WRAPPER_debugaxi128b_1_axi_rcmd_fifo_empty_shift                   (1)
#define  SCPU_WRAPPER_debugaxi128b_1_axi_wcmd_fifo_empty_shift                   (0)
#define  SCPU_WRAPPER_debugaxi128b_1_scpu_axi_bready_mask                        (0x00000020)
#define  SCPU_WRAPPER_debugaxi128b_1_axi_rdata_fifo_empty_mask                   (0x00000010)
#define  SCPU_WRAPPER_debugaxi128b_1_axi_wid_empty_mask                          (0x00000008)
#define  SCPU_WRAPPER_debugaxi128b_1_axi_wdata_fifo_empty_mask                   (0x00000004)
#define  SCPU_WRAPPER_debugaxi128b_1_axi_rcmd_fifo_empty_mask                    (0x00000002)
#define  SCPU_WRAPPER_debugaxi128b_1_axi_wcmd_fifo_empty_mask                    (0x00000001)
#define  SCPU_WRAPPER_debugaxi128b_1_scpu_axi_bready(data)                       (0x00000020&((data)<<5))
#define  SCPU_WRAPPER_debugaxi128b_1_axi_rdata_fifo_empty(data)                  (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_debugaxi128b_1_axi_wid_empty(data)                         (0x00000008&((data)<<3))
#define  SCPU_WRAPPER_debugaxi128b_1_axi_wdata_fifo_empty(data)                  (0x00000004&((data)<<2))
#define  SCPU_WRAPPER_debugaxi128b_1_axi_rcmd_fifo_empty(data)                   (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_debugaxi128b_1_axi_wcmd_fifo_empty(data)                   (0x00000001&(data))
#define  SCPU_WRAPPER_debugaxi128b_1_get_scpu_axi_bready(data)                   ((0x00000020&(data))>>5)
#define  SCPU_WRAPPER_debugaxi128b_1_get_axi_rdata_fifo_empty(data)              ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_debugaxi128b_1_get_axi_wid_empty(data)                     ((0x00000008&(data))>>3)
#define  SCPU_WRAPPER_debugaxi128b_1_get_axi_wdata_fifo_empty(data)              ((0x00000004&(data))>>2)
#define  SCPU_WRAPPER_debugaxi128b_1_get_axi_rcmd_fifo_empty(data)               ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_debugaxi128b_1_get_axi_wcmd_fifo_empty(data)               (0x00000001&(data))

#define  SCPU_WRAPPER_debugaxi128b_2                                             0x1805C604
#define  SCPU_WRAPPER_debugaxi128b_2_reg_addr                                    "0xB805C604"
#define  SCPU_WRAPPER_debugaxi128b_2_reg                                         0xB805C604
#define  SCPU_WRAPPER_debugaxi128b_2_inst_addr                                   "0x0018"
#define  set_SCPU_WRAPPER_debugaxi128b_2_reg(data)                               (*((volatile unsigned int*)SCPU_WRAPPER_debugaxi128b_2_reg)=data)
#define  get_SCPU_WRAPPER_debugaxi128b_2_reg                                     (*((volatile unsigned int*)SCPU_WRAPPER_debugaxi128b_2_reg))
#define  SCPU_WRAPPER_debugaxi128b_2_axi_rdata_fifo_full_shift                   (4)
#define  SCPU_WRAPPER_debugaxi128b_2_axi_wid_full_shift                          (3)
#define  SCPU_WRAPPER_debugaxi128b_2_axi_wdata_fifo_full_shift                   (2)
#define  SCPU_WRAPPER_debugaxi128b_2_axi_rcmd_fifo_full_shift                    (1)
#define  SCPU_WRAPPER_debugaxi128b_2_axi_wcmd_fifo_full_shift                    (0)
#define  SCPU_WRAPPER_debugaxi128b_2_axi_rdata_fifo_full_mask                    (0x00000010)
#define  SCPU_WRAPPER_debugaxi128b_2_axi_wid_full_mask                           (0x00000008)
#define  SCPU_WRAPPER_debugaxi128b_2_axi_wdata_fifo_full_mask                    (0x00000004)
#define  SCPU_WRAPPER_debugaxi128b_2_axi_rcmd_fifo_full_mask                     (0x00000002)
#define  SCPU_WRAPPER_debugaxi128b_2_axi_wcmd_fifo_full_mask                     (0x00000001)
#define  SCPU_WRAPPER_debugaxi128b_2_axi_rdata_fifo_full(data)                   (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_debugaxi128b_2_axi_wid_full(data)                          (0x00000008&((data)<<3))
#define  SCPU_WRAPPER_debugaxi128b_2_axi_wdata_fifo_full(data)                   (0x00000004&((data)<<2))
#define  SCPU_WRAPPER_debugaxi128b_2_axi_rcmd_fifo_full(data)                    (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_debugaxi128b_2_axi_wcmd_fifo_full(data)                    (0x00000001&(data))
#define  SCPU_WRAPPER_debugaxi128b_2_get_axi_rdata_fifo_full(data)               ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_debugaxi128b_2_get_axi_wid_full(data)                      ((0x00000008&(data))>>3)
#define  SCPU_WRAPPER_debugaxi128b_2_get_axi_wdata_fifo_full(data)               ((0x00000004&(data))>>2)
#define  SCPU_WRAPPER_debugaxi128b_2_get_axi_rcmd_fifo_full(data)                ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_debugaxi128b_2_get_axi_wcmd_fifo_full(data)                (0x00000001&(data))

#define  SCPU_WRAPPER_debugaxi32b_1                                              0x1805C608
#define  SCPU_WRAPPER_debugaxi32b_1_reg_addr                                     "0xB805C608"
#define  SCPU_WRAPPER_debugaxi32b_1_reg                                          0xB805C608
#define  SCPU_WRAPPER_debugaxi32b_1_inst_addr                                    "0x0019"
#define  set_SCPU_WRAPPER_debugaxi32b_1_reg(data)                                (*((volatile unsigned int*)SCPU_WRAPPER_debugaxi32b_1_reg)=data)
#define  get_SCPU_WRAPPER_debugaxi32b_1_reg                                      (*((volatile unsigned int*)SCPU_WRAPPER_debugaxi32b_1_reg))
#define  SCPU_WRAPPER_debugaxi32b_1_scpu_axi_bready_mp_shift                     (5)
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_rdata_fifo_empty_shift              (4)
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_wid_empty_shift                     (3)
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_wdata_fifo_empty_shift              (2)
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_rcmd_fifo_empty_shift               (1)
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_wcmd_fifo_empty_shift               (0)
#define  SCPU_WRAPPER_debugaxi32b_1_scpu_axi_bready_mp_mask                      (0x00000020)
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_rdata_fifo_empty_mask               (0x00000010)
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_wid_empty_mask                      (0x00000008)
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_wdata_fifo_empty_mask               (0x00000004)
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_rcmd_fifo_empty_mask                (0x00000002)
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_wcmd_fifo_empty_mask                (0x00000001)
#define  SCPU_WRAPPER_debugaxi32b_1_scpu_axi_bready_mp(data)                     (0x00000020&((data)<<5))
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_rdata_fifo_empty(data)              (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_wid_empty(data)                     (0x00000008&((data)<<3))
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_wdata_fifo_empty(data)              (0x00000004&((data)<<2))
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_rcmd_fifo_empty(data)               (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_debugaxi32b_1_peri_axi_wcmd_fifo_empty(data)               (0x00000001&(data))
#define  SCPU_WRAPPER_debugaxi32b_1_get_scpu_axi_bready_mp(data)                 ((0x00000020&(data))>>5)
#define  SCPU_WRAPPER_debugaxi32b_1_get_peri_axi_rdata_fifo_empty(data)          ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_debugaxi32b_1_get_peri_axi_wid_empty(data)                 ((0x00000008&(data))>>3)
#define  SCPU_WRAPPER_debugaxi32b_1_get_peri_axi_wdata_fifo_empty(data)          ((0x00000004&(data))>>2)
#define  SCPU_WRAPPER_debugaxi32b_1_get_peri_axi_rcmd_fifo_empty(data)           ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_debugaxi32b_1_get_peri_axi_wcmd_fifo_empty(data)           (0x00000001&(data))

#define  SCPU_WRAPPER_debugaxi32b_2                                              0x1805C60C
#define  SCPU_WRAPPER_debugaxi32b_2_reg_addr                                     "0xB805C60C"
#define  SCPU_WRAPPER_debugaxi32b_2_reg                                          0xB805C60C
#define  SCPU_WRAPPER_debugaxi32b_2_inst_addr                                    "0x001A"
#define  set_SCPU_WRAPPER_debugaxi32b_2_reg(data)                                (*((volatile unsigned int*)SCPU_WRAPPER_debugaxi32b_2_reg)=data)
#define  get_SCPU_WRAPPER_debugaxi32b_2_reg                                      (*((volatile unsigned int*)SCPU_WRAPPER_debugaxi32b_2_reg))
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_rdata_fifo_full_shift               (4)
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_wid_full_shift                      (3)
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_wdata_fifo_full_shift               (2)
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_rcmd_fifo_full_shift                (1)
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_wcmd_fifo_full_shift                (0)
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_rdata_fifo_full_mask                (0x00000010)
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_wid_full_mask                       (0x00000008)
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_wdata_fifo_full_mask                (0x00000004)
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_rcmd_fifo_full_mask                 (0x00000002)
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_wcmd_fifo_full_mask                 (0x00000001)
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_rdata_fifo_full(data)               (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_wid_full(data)                      (0x00000008&((data)<<3))
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_wdata_fifo_full(data)               (0x00000004&((data)<<2))
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_rcmd_fifo_full(data)                (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_debugaxi32b_2_peri_axi_wcmd_fifo_full(data)                (0x00000001&(data))
#define  SCPU_WRAPPER_debugaxi32b_2_get_peri_axi_rdata_fifo_full(data)           ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_debugaxi32b_2_get_peri_axi_wid_full(data)                  ((0x00000008&(data))>>3)
#define  SCPU_WRAPPER_debugaxi32b_2_get_peri_axi_wdata_fifo_full(data)           ((0x00000004&(data))>>2)
#define  SCPU_WRAPPER_debugaxi32b_2_get_peri_axi_rcmd_fifo_full(data)            ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_debugaxi32b_2_get_peri_axi_wcmd_fifo_full(data)            (0x00000001&(data))

#define  SCPU_WRAPPER_debugwrapper_1                                             0x1805C610
#define  SCPU_WRAPPER_debugwrapper_1_reg_addr                                    "0xB805C610"
#define  SCPU_WRAPPER_debugwrapper_1_reg                                         0xB805C610
#define  SCPU_WRAPPER_debugwrapper_1_inst_addr                                   "0x001B"
#define  set_SCPU_WRAPPER_debugwrapper_1_reg(data)                               (*((volatile unsigned int*)SCPU_WRAPPER_debugwrapper_1_reg)=data)
#define  get_SCPU_WRAPPER_debugwrapper_1_reg                                     (*((volatile unsigned int*)SCPU_WRAPPER_debugwrapper_1_reg))
#define  SCPU_WRAPPER_debugwrapper_1_dis_cmd_async_fifo_empty_shift              (5)
#define  SCPU_WRAPPER_debugwrapper_1_dis_cmd_async_fifo_full_shift               (4)
#define  SCPU_WRAPPER_debugwrapper_1_dc2_cmd_async_fifo_empty_shift              (3)
#define  SCPU_WRAPPER_debugwrapper_1_dc2_cmd_async_fifo_full_shift               (2)
#define  SCPU_WRAPPER_debugwrapper_1_dc_cmd_async_fifo_empty_shift               (1)
#define  SCPU_WRAPPER_debugwrapper_1_dc_cmd_async_fifo_full_shift                (0)
#define  SCPU_WRAPPER_debugwrapper_1_dis_cmd_async_fifo_empty_mask               (0x00000020)
#define  SCPU_WRAPPER_debugwrapper_1_dis_cmd_async_fifo_full_mask                (0x00000010)
#define  SCPU_WRAPPER_debugwrapper_1_dc2_cmd_async_fifo_empty_mask               (0x00000008)
#define  SCPU_WRAPPER_debugwrapper_1_dc2_cmd_async_fifo_full_mask                (0x00000004)
#define  SCPU_WRAPPER_debugwrapper_1_dc_cmd_async_fifo_empty_mask                (0x00000002)
#define  SCPU_WRAPPER_debugwrapper_1_dc_cmd_async_fifo_full_mask                 (0x00000001)
#define  SCPU_WRAPPER_debugwrapper_1_dis_cmd_async_fifo_empty(data)              (0x00000020&((data)<<5))
#define  SCPU_WRAPPER_debugwrapper_1_dis_cmd_async_fifo_full(data)               (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_debugwrapper_1_dc2_cmd_async_fifo_empty(data)              (0x00000008&((data)<<3))
#define  SCPU_WRAPPER_debugwrapper_1_dc2_cmd_async_fifo_full(data)               (0x00000004&((data)<<2))
#define  SCPU_WRAPPER_debugwrapper_1_dc_cmd_async_fifo_empty(data)               (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_debugwrapper_1_dc_cmd_async_fifo_full(data)                (0x00000001&(data))
#define  SCPU_WRAPPER_debugwrapper_1_get_dis_cmd_async_fifo_empty(data)          ((0x00000020&(data))>>5)
#define  SCPU_WRAPPER_debugwrapper_1_get_dis_cmd_async_fifo_full(data)           ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_debugwrapper_1_get_dc2_cmd_async_fifo_empty(data)          ((0x00000008&(data))>>3)
#define  SCPU_WRAPPER_debugwrapper_1_get_dc2_cmd_async_fifo_full(data)           ((0x00000004&(data))>>2)
#define  SCPU_WRAPPER_debugwrapper_1_get_dc_cmd_async_fifo_empty(data)           ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_debugwrapper_1_get_dc_cmd_async_fifo_full(data)            (0x00000001&(data))

#define  SCPU_WRAPPER_debugwrapper_2                                             0x1805C614
#define  SCPU_WRAPPER_debugwrapper_2_reg_addr                                    "0xB805C614"
#define  SCPU_WRAPPER_debugwrapper_2_reg                                         0xB805C614
#define  SCPU_WRAPPER_debugwrapper_2_inst_addr                                   "0x001C"
#define  set_SCPU_WRAPPER_debugwrapper_2_reg(data)                               (*((volatile unsigned int*)SCPU_WRAPPER_debugwrapper_2_reg)=data)
#define  get_SCPU_WRAPPER_debugwrapper_2_reg                                     (*((volatile unsigned int*)SCPU_WRAPPER_debugwrapper_2_reg))
#define  SCPU_WRAPPER_debugwrapper_2_dis_wdata_async_fifo_empty_shift            (5)
#define  SCPU_WRAPPER_debugwrapper_2_dis_wdata_async_fifo_full_shift             (4)
#define  SCPU_WRAPPER_debugwrapper_2_dc2_wdata_async_fifo_empty_shift            (3)
#define  SCPU_WRAPPER_debugwrapper_2_dc2_wdata_async_fifo_full_shift             (2)
#define  SCPU_WRAPPER_debugwrapper_2_dc_wdata_async_fifo_empty_shift             (1)
#define  SCPU_WRAPPER_debugwrapper_2_dc_wdata_async_fifo_full_shift              (0)
#define  SCPU_WRAPPER_debugwrapper_2_dis_wdata_async_fifo_empty_mask             (0x00000020)
#define  SCPU_WRAPPER_debugwrapper_2_dis_wdata_async_fifo_full_mask              (0x00000010)
#define  SCPU_WRAPPER_debugwrapper_2_dc2_wdata_async_fifo_empty_mask             (0x00000008)
#define  SCPU_WRAPPER_debugwrapper_2_dc2_wdata_async_fifo_full_mask              (0x00000004)
#define  SCPU_WRAPPER_debugwrapper_2_dc_wdata_async_fifo_empty_mask              (0x00000002)
#define  SCPU_WRAPPER_debugwrapper_2_dc_wdata_async_fifo_full_mask               (0x00000001)
#define  SCPU_WRAPPER_debugwrapper_2_dis_wdata_async_fifo_empty(data)            (0x00000020&((data)<<5))
#define  SCPU_WRAPPER_debugwrapper_2_dis_wdata_async_fifo_full(data)             (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_debugwrapper_2_dc2_wdata_async_fifo_empty(data)            (0x00000008&((data)<<3))
#define  SCPU_WRAPPER_debugwrapper_2_dc2_wdata_async_fifo_full(data)             (0x00000004&((data)<<2))
#define  SCPU_WRAPPER_debugwrapper_2_dc_wdata_async_fifo_empty(data)             (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_debugwrapper_2_dc_wdata_async_fifo_full(data)              (0x00000001&(data))
#define  SCPU_WRAPPER_debugwrapper_2_get_dis_wdata_async_fifo_empty(data)        ((0x00000020&(data))>>5)
#define  SCPU_WRAPPER_debugwrapper_2_get_dis_wdata_async_fifo_full(data)         ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_debugwrapper_2_get_dc2_wdata_async_fifo_empty(data)        ((0x00000008&(data))>>3)
#define  SCPU_WRAPPER_debugwrapper_2_get_dc2_wdata_async_fifo_full(data)         ((0x00000004&(data))>>2)
#define  SCPU_WRAPPER_debugwrapper_2_get_dc_wdata_async_fifo_empty(data)         ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_debugwrapper_2_get_dc_wdata_async_fifo_full(data)          (0x00000001&(data))

#define  SCPU_WRAPPER_debugwrapper_3                                             0x1805C618
#define  SCPU_WRAPPER_debugwrapper_3_reg_addr                                    "0xB805C618"
#define  SCPU_WRAPPER_debugwrapper_3_reg                                         0xB805C618
#define  SCPU_WRAPPER_debugwrapper_3_inst_addr                                   "0x001D"
#define  set_SCPU_WRAPPER_debugwrapper_3_reg(data)                               (*((volatile unsigned int*)SCPU_WRAPPER_debugwrapper_3_reg)=data)
#define  get_SCPU_WRAPPER_debugwrapper_3_reg                                     (*((volatile unsigned int*)SCPU_WRAPPER_debugwrapper_3_reg))
#define  SCPU_WRAPPER_debugwrapper_3_dis_rdata_async_fifo_empty_shift            (5)
#define  SCPU_WRAPPER_debugwrapper_3_dis_rdata_async_fifo_full_shift             (4)
#define  SCPU_WRAPPER_debugwrapper_3_dc2_rdata_async_fifo_empty_shift            (3)
#define  SCPU_WRAPPER_debugwrapper_3_dc2_rdata_async_fifo_full_shift             (2)
#define  SCPU_WRAPPER_debugwrapper_3_dc_rdata_async_fifo_empty_shift             (1)
#define  SCPU_WRAPPER_debugwrapper_3_dc_rdata_async_fifo_full_shift              (0)
#define  SCPU_WRAPPER_debugwrapper_3_dis_rdata_async_fifo_empty_mask             (0x00000020)
#define  SCPU_WRAPPER_debugwrapper_3_dis_rdata_async_fifo_full_mask              (0x00000010)
#define  SCPU_WRAPPER_debugwrapper_3_dc2_rdata_async_fifo_empty_mask             (0x00000008)
#define  SCPU_WRAPPER_debugwrapper_3_dc2_rdata_async_fifo_full_mask              (0x00000004)
#define  SCPU_WRAPPER_debugwrapper_3_dc_rdata_async_fifo_empty_mask              (0x00000002)
#define  SCPU_WRAPPER_debugwrapper_3_dc_rdata_async_fifo_full_mask               (0x00000001)
#define  SCPU_WRAPPER_debugwrapper_3_dis_rdata_async_fifo_empty(data)            (0x00000020&((data)<<5))
#define  SCPU_WRAPPER_debugwrapper_3_dis_rdata_async_fifo_full(data)             (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_debugwrapper_3_dc2_rdata_async_fifo_empty(data)            (0x00000008&((data)<<3))
#define  SCPU_WRAPPER_debugwrapper_3_dc2_rdata_async_fifo_full(data)             (0x00000004&((data)<<2))
#define  SCPU_WRAPPER_debugwrapper_3_dc_rdata_async_fifo_empty(data)             (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_debugwrapper_3_dc_rdata_async_fifo_full(data)              (0x00000001&(data))
#define  SCPU_WRAPPER_debugwrapper_3_get_dis_rdata_async_fifo_empty(data)        ((0x00000020&(data))>>5)
#define  SCPU_WRAPPER_debugwrapper_3_get_dis_rdata_async_fifo_full(data)         ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_debugwrapper_3_get_dc2_rdata_async_fifo_empty(data)        ((0x00000008&(data))>>3)
#define  SCPU_WRAPPER_debugwrapper_3_get_dc2_rdata_async_fifo_full(data)         ((0x00000004&(data))>>2)
#define  SCPU_WRAPPER_debugwrapper_3_get_dc_rdata_async_fifo_empty(data)         ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_debugwrapper_3_get_dc_rdata_async_fifo_full(data)          (0x00000001&(data))

#define  SCPU_WRAPPER_debugwrapper_4                                             0x1805C61C
#define  SCPU_WRAPPER_debugwrapper_4_reg_addr                                    "0xB805C61C"
#define  SCPU_WRAPPER_debugwrapper_4_reg                                         0xB805C61C
#define  SCPU_WRAPPER_debugwrapper_4_inst_addr                                   "0x001E"
#define  set_SCPU_WRAPPER_debugwrapper_4_reg(data)                               (*((volatile unsigned int*)SCPU_WRAPPER_debugwrapper_4_reg)=data)
#define  get_SCPU_WRAPPER_debugwrapper_4_reg                                     (*((volatile unsigned int*)SCPU_WRAPPER_debugwrapper_4_reg))
#define  SCPU_WRAPPER_debugwrapper_4_dis_rdata_sync_fifo_full_shift              (19)
#define  SCPU_WRAPPER_debugwrapper_4_dis_rdata_sync_fifo_empty_shift             (18)
#define  SCPU_WRAPPER_debugwrapper_4_dc2_rd_outstanding_buf_fifo_cnt_shift       (11)
#define  SCPU_WRAPPER_debugwrapper_4_dc2_rd_outstanding_buf_full_shift           (10)
#define  SCPU_WRAPPER_debugwrapper_4_dc2_rd_outstanding_buf_empty_shift          (9)
#define  SCPU_WRAPPER_debugwrapper_4_dc_rd_outstanding_buf_fifo_cnt_shift        (2)
#define  SCPU_WRAPPER_debugwrapper_4_dc_rd_outstanding_buf_full_shift            (1)
#define  SCPU_WRAPPER_debugwrapper_4_dc_rd_outstanding_buf_empty_shift           (0)
#define  SCPU_WRAPPER_debugwrapper_4_dis_rdata_sync_fifo_full_mask               (0x00080000)
#define  SCPU_WRAPPER_debugwrapper_4_dis_rdata_sync_fifo_empty_mask              (0x00040000)
#define  SCPU_WRAPPER_debugwrapper_4_dc2_rd_outstanding_buf_fifo_cnt_mask        (0x0003F800)
#define  SCPU_WRAPPER_debugwrapper_4_dc2_rd_outstanding_buf_full_mask            (0x00000400)
#define  SCPU_WRAPPER_debugwrapper_4_dc2_rd_outstanding_buf_empty_mask           (0x00000200)
#define  SCPU_WRAPPER_debugwrapper_4_dc_rd_outstanding_buf_fifo_cnt_mask         (0x000001FC)
#define  SCPU_WRAPPER_debugwrapper_4_dc_rd_outstanding_buf_full_mask             (0x00000002)
#define  SCPU_WRAPPER_debugwrapper_4_dc_rd_outstanding_buf_empty_mask            (0x00000001)
#define  SCPU_WRAPPER_debugwrapper_4_dis_rdata_sync_fifo_full(data)              (0x00080000&((data)<<19))
#define  SCPU_WRAPPER_debugwrapper_4_dis_rdata_sync_fifo_empty(data)             (0x00040000&((data)<<18))
#define  SCPU_WRAPPER_debugwrapper_4_dc2_rd_outstanding_buf_fifo_cnt(data)       (0x0003F800&((data)<<11))
#define  SCPU_WRAPPER_debugwrapper_4_dc2_rd_outstanding_buf_full(data)           (0x00000400&((data)<<10))
#define  SCPU_WRAPPER_debugwrapper_4_dc2_rd_outstanding_buf_empty(data)          (0x00000200&((data)<<9))
#define  SCPU_WRAPPER_debugwrapper_4_dc_rd_outstanding_buf_fifo_cnt(data)        (0x000001FC&((data)<<2))
#define  SCPU_WRAPPER_debugwrapper_4_dc_rd_outstanding_buf_full(data)            (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_debugwrapper_4_dc_rd_outstanding_buf_empty(data)           (0x00000001&(data))
#define  SCPU_WRAPPER_debugwrapper_4_get_dis_rdata_sync_fifo_full(data)          ((0x00080000&(data))>>19)
#define  SCPU_WRAPPER_debugwrapper_4_get_dis_rdata_sync_fifo_empty(data)         ((0x00040000&(data))>>18)
#define  SCPU_WRAPPER_debugwrapper_4_get_dc2_rd_outstanding_buf_fifo_cnt(data)   ((0x0003F800&(data))>>11)
#define  SCPU_WRAPPER_debugwrapper_4_get_dc2_rd_outstanding_buf_full(data)       ((0x00000400&(data))>>10)
#define  SCPU_WRAPPER_debugwrapper_4_get_dc2_rd_outstanding_buf_empty(data)      ((0x00000200&(data))>>9)
#define  SCPU_WRAPPER_debugwrapper_4_get_dc_rd_outstanding_buf_fifo_cnt(data)    ((0x000001FC&(data))>>2)
#define  SCPU_WRAPPER_debugwrapper_4_get_dc_rd_outstanding_buf_full(data)        ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_debugwrapper_4_get_dc_rd_outstanding_buf_empty(data)       (0x00000001&(data))

#define  SCPU_WRAPPER_axidbg_ctrl                                                0x1805C620
#define  SCPU_WRAPPER_axidbg_ctrl_reg_addr                                       "0xB805C620"
#define  SCPU_WRAPPER_axidbg_ctrl_reg                                            0xB805C620
#define  SCPU_WRAPPER_axidbg_ctrl_inst_addr                                      "0x001F"
#define  set_SCPU_WRAPPER_axidbg_ctrl_reg(data)                                  (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_ctrl_reg)=data)
#define  get_SCPU_WRAPPER_axidbg_ctrl_reg                                        (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_ctrl_reg))
#define  SCPU_WRAPPER_axidbg_ctrl_stop_dbg_main_wr_shift                         (3)
#define  SCPU_WRAPPER_axidbg_ctrl_stop_dbg_main_rd_shift                         (2)
#define  SCPU_WRAPPER_axidbg_ctrl_stop_dbg_peri_wr_shift                         (1)
#define  SCPU_WRAPPER_axidbg_ctrl_stop_dbg_peri_rd_shift                         (0)
#define  SCPU_WRAPPER_axidbg_ctrl_stop_dbg_main_wr_mask                          (0x00000008)
#define  SCPU_WRAPPER_axidbg_ctrl_stop_dbg_main_rd_mask                          (0x00000004)
#define  SCPU_WRAPPER_axidbg_ctrl_stop_dbg_peri_wr_mask                          (0x00000002)
#define  SCPU_WRAPPER_axidbg_ctrl_stop_dbg_peri_rd_mask                          (0x00000001)
#define  SCPU_WRAPPER_axidbg_ctrl_stop_dbg_main_wr(data)                         (0x00000008&((data)<<3))
#define  SCPU_WRAPPER_axidbg_ctrl_stop_dbg_main_rd(data)                         (0x00000004&((data)<<2))
#define  SCPU_WRAPPER_axidbg_ctrl_stop_dbg_peri_wr(data)                         (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_axidbg_ctrl_stop_dbg_peri_rd(data)                         (0x00000001&(data))
#define  SCPU_WRAPPER_axidbg_ctrl_get_stop_dbg_main_wr(data)                     ((0x00000008&(data))>>3)
#define  SCPU_WRAPPER_axidbg_ctrl_get_stop_dbg_main_rd(data)                     ((0x00000004&(data))>>2)
#define  SCPU_WRAPPER_axidbg_ctrl_get_stop_dbg_peri_wr(data)                     ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_axidbg_ctrl_get_stop_dbg_peri_rd(data)                     (0x00000001&(data))

#define  SCPU_WRAPPER_axidbg_status                                              0x1805C624
#define  SCPU_WRAPPER_axidbg_status_reg_addr                                     "0xB805C624"
#define  SCPU_WRAPPER_axidbg_status_reg                                          0xB805C624
#define  SCPU_WRAPPER_axidbg_status_inst_addr                                    "0x0020"
#define  set_SCPU_WRAPPER_axidbg_status_reg(data)                                (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_status_reg)=data)
#define  get_SCPU_WRAPPER_axidbg_status_reg                                      (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_status_reg))
#define  SCPU_WRAPPER_axidbg_status_valid_entry_cnt_main_wr_shift                (24)
#define  SCPU_WRAPPER_axidbg_status_valid_entry_cnt_main_rd_shift                (16)
#define  SCPU_WRAPPER_axidbg_status_valid_entry_cnt_peri_wr_shift                (8)
#define  SCPU_WRAPPER_axidbg_status_valid_entry_cnt_peri_rd_shift                (0)
#define  SCPU_WRAPPER_axidbg_status_valid_entry_cnt_main_wr_mask                 (0x1F000000)
#define  SCPU_WRAPPER_axidbg_status_valid_entry_cnt_main_rd_mask                 (0x001F0000)
#define  SCPU_WRAPPER_axidbg_status_valid_entry_cnt_peri_wr_mask                 (0x00000300)
#define  SCPU_WRAPPER_axidbg_status_valid_entry_cnt_peri_rd_mask                 (0x00000003)
#define  SCPU_WRAPPER_axidbg_status_valid_entry_cnt_main_wr(data)                (0x1F000000&((data)<<24))
#define  SCPU_WRAPPER_axidbg_status_valid_entry_cnt_main_rd(data)                (0x001F0000&((data)<<16))
#define  SCPU_WRAPPER_axidbg_status_valid_entry_cnt_peri_wr(data)                (0x00000300&((data)<<8))
#define  SCPU_WRAPPER_axidbg_status_valid_entry_cnt_peri_rd(data)                (0x00000003&(data))
#define  SCPU_WRAPPER_axidbg_status_get_valid_entry_cnt_main_wr(data)            ((0x1F000000&(data))>>24)
#define  SCPU_WRAPPER_axidbg_status_get_valid_entry_cnt_main_rd(data)            ((0x001F0000&(data))>>16)
#define  SCPU_WRAPPER_axidbg_status_get_valid_entry_cnt_peri_wr(data)            ((0x00000300&(data))>>8)
#define  SCPU_WRAPPER_axidbg_status_get_valid_entry_cnt_peri_rd(data)            (0x00000003&(data))

#define  SCPU_WRAPPER_axidbg_main_waddr                                          0x1805C628
#define  SCPU_WRAPPER_axidbg_main_waddr_reg_addr                                 "0xB805C628"
#define  SCPU_WRAPPER_axidbg_main_waddr_reg                                      0xB805C628
#define  SCPU_WRAPPER_axidbg_main_waddr_inst_addr                                "0x0021"
#define  set_SCPU_WRAPPER_axidbg_main_waddr_reg(data)                            (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_main_waddr_reg)=data)
#define  get_SCPU_WRAPPER_axidbg_main_waddr_reg                                  (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_main_waddr_reg))
#define  SCPU_WRAPPER_axidbg_main_waddr_main_waddr_shift                         (0)
#define  SCPU_WRAPPER_axidbg_main_waddr_main_waddr_mask                          (0xFFFFFFFF)
#define  SCPU_WRAPPER_axidbg_main_waddr_main_waddr(data)                         (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_axidbg_main_waddr_get_main_waddr(data)                     (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_axidbg_main_wid                                            0x1805C62C
#define  SCPU_WRAPPER_axidbg_main_wid_reg_addr                                   "0xB805C62C"
#define  SCPU_WRAPPER_axidbg_main_wid_reg                                        0xB805C62C
#define  SCPU_WRAPPER_axidbg_main_wid_inst_addr                                  "0x0022"
#define  set_SCPU_WRAPPER_axidbg_main_wid_reg(data)                              (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_main_wid_reg)=data)
#define  get_SCPU_WRAPPER_axidbg_main_wid_reg                                    (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_main_wid_reg))
#define  SCPU_WRAPPER_axidbg_main_wid_main_wid_shift                             (0)
#define  SCPU_WRAPPER_axidbg_main_wid_main_wid_mask                              (0x000001FF)
#define  SCPU_WRAPPER_axidbg_main_wid_main_wid(data)                             (0x000001FF&(data))
#define  SCPU_WRAPPER_axidbg_main_wid_get_main_wid(data)                         (0x000001FF&(data))

#define  SCPU_WRAPPER_axidbg_main_raddr                                          0x1805C630
#define  SCPU_WRAPPER_axidbg_main_raddr_reg_addr                                 "0xB805C630"
#define  SCPU_WRAPPER_axidbg_main_raddr_reg                                      0xB805C630
#define  SCPU_WRAPPER_axidbg_main_raddr_inst_addr                                "0x0023"
#define  set_SCPU_WRAPPER_axidbg_main_raddr_reg(data)                            (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_main_raddr_reg)=data)
#define  get_SCPU_WRAPPER_axidbg_main_raddr_reg                                  (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_main_raddr_reg))
#define  SCPU_WRAPPER_axidbg_main_raddr_main_raddr_shift                         (0)
#define  SCPU_WRAPPER_axidbg_main_raddr_main_raddr_mask                          (0xFFFFFFFF)
#define  SCPU_WRAPPER_axidbg_main_raddr_main_raddr(data)                         (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_axidbg_main_raddr_get_main_raddr(data)                     (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_axidbg_main_rid                                            0x1805C634
#define  SCPU_WRAPPER_axidbg_main_rid_reg_addr                                   "0xB805C634"
#define  SCPU_WRAPPER_axidbg_main_rid_reg                                        0xB805C634
#define  SCPU_WRAPPER_axidbg_main_rid_inst_addr                                  "0x0024"
#define  set_SCPU_WRAPPER_axidbg_main_rid_reg(data)                              (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_main_rid_reg)=data)
#define  get_SCPU_WRAPPER_axidbg_main_rid_reg                                    (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_main_rid_reg))
#define  SCPU_WRAPPER_axidbg_main_rid_main_rid_shift                             (0)
#define  SCPU_WRAPPER_axidbg_main_rid_main_rid_mask                              (0x000001FF)
#define  SCPU_WRAPPER_axidbg_main_rid_main_rid(data)                             (0x000001FF&(data))
#define  SCPU_WRAPPER_axidbg_main_rid_get_main_rid(data)                         (0x000001FF&(data))

#define  SCPU_WRAPPER_axidbg_peri_waddr                                          0x1805C638
#define  SCPU_WRAPPER_axidbg_peri_waddr_reg_addr                                 "0xB805C638"
#define  SCPU_WRAPPER_axidbg_peri_waddr_reg                                      0xB805C638
#define  SCPU_WRAPPER_axidbg_peri_waddr_inst_addr                                "0x0025"
#define  set_SCPU_WRAPPER_axidbg_peri_waddr_reg(data)                            (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_peri_waddr_reg)=data)
#define  get_SCPU_WRAPPER_axidbg_peri_waddr_reg                                  (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_peri_waddr_reg))
#define  SCPU_WRAPPER_axidbg_peri_waddr_peri_waddr_shift                         (0)
#define  SCPU_WRAPPER_axidbg_peri_waddr_peri_waddr_mask                          (0xFFFFFFFF)
#define  SCPU_WRAPPER_axidbg_peri_waddr_peri_waddr(data)                         (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_axidbg_peri_waddr_get_peri_waddr(data)                     (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_axidbg_peri_wid                                            0x1805C63C
#define  SCPU_WRAPPER_axidbg_peri_wid_reg_addr                                   "0xB805C63C"
#define  SCPU_WRAPPER_axidbg_peri_wid_reg                                        0xB805C63C
#define  SCPU_WRAPPER_axidbg_peri_wid_inst_addr                                  "0x0026"
#define  set_SCPU_WRAPPER_axidbg_peri_wid_reg(data)                              (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_peri_wid_reg)=data)
#define  get_SCPU_WRAPPER_axidbg_peri_wid_reg                                    (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_peri_wid_reg))
#define  SCPU_WRAPPER_axidbg_peri_wid_peri_wid_shift                             (0)
#define  SCPU_WRAPPER_axidbg_peri_wid_peri_wid_mask                              (0x000001FF)
#define  SCPU_WRAPPER_axidbg_peri_wid_peri_wid(data)                             (0x000001FF&(data))
#define  SCPU_WRAPPER_axidbg_peri_wid_get_peri_wid(data)                         (0x000001FF&(data))

#define  SCPU_WRAPPER_axidbg_peri_raddr                                          0x1805C640
#define  SCPU_WRAPPER_axidbg_peri_raddr_reg_addr                                 "0xB805C640"
#define  SCPU_WRAPPER_axidbg_peri_raddr_reg                                      0xB805C640
#define  SCPU_WRAPPER_axidbg_peri_raddr_inst_addr                                "0x0027"
#define  set_SCPU_WRAPPER_axidbg_peri_raddr_reg(data)                            (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_peri_raddr_reg)=data)
#define  get_SCPU_WRAPPER_axidbg_peri_raddr_reg                                  (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_peri_raddr_reg))
#define  SCPU_WRAPPER_axidbg_peri_raddr_peri_raddr_shift                         (0)
#define  SCPU_WRAPPER_axidbg_peri_raddr_peri_raddr_mask                          (0xFFFFFFFF)
#define  SCPU_WRAPPER_axidbg_peri_raddr_peri_raddr(data)                         (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_axidbg_peri_raddr_get_peri_raddr(data)                     (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_axidbg_peri_rid                                            0x1805C644
#define  SCPU_WRAPPER_axidbg_peri_rid_reg_addr                                   "0xB805C644"
#define  SCPU_WRAPPER_axidbg_peri_rid_reg                                        0xB805C644
#define  SCPU_WRAPPER_axidbg_peri_rid_inst_addr                                  "0x0028"
#define  set_SCPU_WRAPPER_axidbg_peri_rid_reg(data)                              (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_peri_rid_reg)=data)
#define  get_SCPU_WRAPPER_axidbg_peri_rid_reg                                    (*((volatile unsigned int*)SCPU_WRAPPER_axidbg_peri_rid_reg))
#define  SCPU_WRAPPER_axidbg_peri_rid_peri_rid_shift                             (0)
#define  SCPU_WRAPPER_axidbg_peri_rid_peri_rid_mask                              (0x000001FF)
#define  SCPU_WRAPPER_axidbg_peri_rid_peri_rid(data)                             (0x000001FF&(data))
#define  SCPU_WRAPPER_axidbg_peri_rid_get_peri_rid(data)                         (0x000001FF&(data))

#define  SCPU_WRAPPER_sf_test_ctrl                                               0x1805C700
#define  SCPU_WRAPPER_sf_test_ctrl_reg_addr                                      "0xB805C700"
#define  SCPU_WRAPPER_sf_test_ctrl_reg                                           0xB805C700
#define  SCPU_WRAPPER_sf_test_ctrl_inst_addr                                     "0x0029"
#define  set_SCPU_WRAPPER_sf_test_ctrl_reg(data)                                 (*((volatile unsigned int*)SCPU_WRAPPER_sf_test_ctrl_reg)=data)
#define  get_SCPU_WRAPPER_sf_test_ctrl_reg                                       (*((volatile unsigned int*)SCPU_WRAPPER_sf_test_ctrl_reg))
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_rx_gated_shift                         (6)
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_rx_start_shift                         (5)
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_rx_mode_shift                          (4)
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_tx_start_shift                         (1)
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_tx_mode_shift                          (0)
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_rx_gated_mask                          (0x00000040)
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_rx_start_mask                          (0x00000020)
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_rx_mode_mask                           (0x00000010)
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_tx_start_mask                          (0x00000002)
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_tx_mode_mask                           (0x00000001)
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_rx_gated(data)                         (0x00000040&((data)<<6))
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_rx_start(data)                         (0x00000020&((data)<<5))
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_rx_mode(data)                          (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_tx_start(data)                         (0x00000002&((data)<<1))
#define  SCPU_WRAPPER_sf_test_ctrl_reg_sf_tx_mode(data)                          (0x00000001&(data))
#define  SCPU_WRAPPER_sf_test_ctrl_get_reg_sf_rx_gated(data)                     ((0x00000040&(data))>>6)
#define  SCPU_WRAPPER_sf_test_ctrl_get_reg_sf_rx_start(data)                     ((0x00000020&(data))>>5)
#define  SCPU_WRAPPER_sf_test_ctrl_get_reg_sf_rx_mode(data)                      ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_sf_test_ctrl_get_reg_sf_tx_start(data)                     ((0x00000002&(data))>>1)
#define  SCPU_WRAPPER_sf_test_ctrl_get_reg_sf_tx_mode(data)                      (0x00000001&(data))

#define  SCPU_WRAPPER_sf_test_status                                             0x1805C704
#define  SCPU_WRAPPER_sf_test_status_reg_addr                                    "0xB805C704"
#define  SCPU_WRAPPER_sf_test_status_reg                                         0xB805C704
#define  SCPU_WRAPPER_sf_test_status_inst_addr                                   "0x002A"
#define  set_SCPU_WRAPPER_sf_test_status_reg(data)                               (*((volatile unsigned int*)SCPU_WRAPPER_sf_test_status_reg)=data)
#define  get_SCPU_WRAPPER_sf_test_status_reg                                     (*((volatile unsigned int*)SCPU_WRAPPER_sf_test_status_reg))
#define  SCPU_WRAPPER_sf_test_status_reg_sf_rx_err_shift                         (5)
#define  SCPU_WRAPPER_sf_test_status_reg_sf_rx_done_shift                        (4)
#define  SCPU_WRAPPER_sf_test_status_reg_sf_tx_work_shift                        (0)
#define  SCPU_WRAPPER_sf_test_status_reg_sf_rx_err_mask                          (0x00000020)
#define  SCPU_WRAPPER_sf_test_status_reg_sf_rx_done_mask                         (0x00000010)
#define  SCPU_WRAPPER_sf_test_status_reg_sf_tx_work_mask                         (0x00000001)
#define  SCPU_WRAPPER_sf_test_status_reg_sf_rx_err(data)                         (0x00000020&((data)<<5))
#define  SCPU_WRAPPER_sf_test_status_reg_sf_rx_done(data)                        (0x00000010&((data)<<4))
#define  SCPU_WRAPPER_sf_test_status_reg_sf_tx_work(data)                        (0x00000001&(data))
#define  SCPU_WRAPPER_sf_test_status_get_reg_sf_rx_err(data)                     ((0x00000020&(data))>>5)
#define  SCPU_WRAPPER_sf_test_status_get_reg_sf_rx_done(data)                    ((0x00000010&(data))>>4)
#define  SCPU_WRAPPER_sf_test_status_get_reg_sf_tx_work(data)                    (0x00000001&(data))

#define  SCPU_WRAPPER_tsgen_input_ctrl0                                          0x1805C800
#define  SCPU_WRAPPER_tsgen_input_ctrl0_reg_addr                                 "0xB805C800"
#define  SCPU_WRAPPER_tsgen_input_ctrl0_reg                                      0xB805C800
#define  SCPU_WRAPPER_tsgen_input_ctrl0_inst_addr                                "0x002B"
#define  set_SCPU_WRAPPER_tsgen_input_ctrl0_reg(data)                            (*((volatile unsigned int*)SCPU_WRAPPER_tsgen_input_ctrl0_reg)=data)
#define  get_SCPU_WRAPPER_tsgen_input_ctrl0_reg                                  (*((volatile unsigned int*)SCPU_WRAPPER_tsgen_input_ctrl0_reg))
#define  SCPU_WRAPPER_tsgen_input_ctrl0_apb_tsgen_a_shift                        (0)
#define  SCPU_WRAPPER_tsgen_input_ctrl0_apb_tsgen_a_mask                         (0xFFFFFFFF)
#define  SCPU_WRAPPER_tsgen_input_ctrl0_apb_tsgen_a(data)                        (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_tsgen_input_ctrl0_get_apb_tsgen_a(data)                    (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_tsgen_input_ctrl1                                          0x1805C804
#define  SCPU_WRAPPER_tsgen_input_ctrl1_reg_addr                                 "0xB805C804"
#define  SCPU_WRAPPER_tsgen_input_ctrl1_reg                                      0xB805C804
#define  SCPU_WRAPPER_tsgen_input_ctrl1_inst_addr                                "0x002C"
#define  set_SCPU_WRAPPER_tsgen_input_ctrl1_reg(data)                            (*((volatile unsigned int*)SCPU_WRAPPER_tsgen_input_ctrl1_reg)=data)
#define  get_SCPU_WRAPPER_tsgen_input_ctrl1_reg                                  (*((volatile unsigned int*)SCPU_WRAPPER_tsgen_input_ctrl1_reg))
#define  SCPU_WRAPPER_tsgen_input_ctrl1_apb_tsgen_d_shift                        (0)
#define  SCPU_WRAPPER_tsgen_input_ctrl1_apb_tsgen_d_mask                         (0xFFFFFFFF)
#define  SCPU_WRAPPER_tsgen_input_ctrl1_apb_tsgen_d(data)                        (0xFFFFFFFF&(data))
#define  SCPU_WRAPPER_tsgen_input_ctrl1_get_apb_tsgen_d(data)                    (0xFFFFFFFF&(data))

#define  SCPU_WRAPPER_tsgen_input_ctrl2                                          0x1805C808
#define  SCPU_WRAPPER_tsgen_input_ctrl2_reg_addr                                 "0xB805C808"
#define  SCPU_WRAPPER_tsgen_input_ctrl2_reg                                      0xB805C808
#define  SCPU_WRAPPER_tsgen_input_ctrl2_inst_addr                                "0x002D"
#define  set_SCPU_WRAPPER_tsgen_input_ctrl2_reg(data)                            (*((volatile unsigned int*)SCPU_WRAPPER_tsgen_input_ctrl2_reg)=data)
#define  get_SCPU_WRAPPER_tsgen_input_ctrl2_reg                                  (*((volatile unsigned int*)SCPU_WRAPPER_tsgen_input_ctrl2_reg))
#define  SCPU_WRAPPER_tsgen_input_ctrl2_apb_tsgen_slverr_shift                   (0)
#define  SCPU_WRAPPER_tsgen_input_ctrl2_apb_tsgen_slverr_mask                    (0x00000001)
#define  SCPU_WRAPPER_tsgen_input_ctrl2_apb_tsgen_slverr(data)                   (0x00000001&(data))
#define  SCPU_WRAPPER_tsgen_input_ctrl2_get_apb_tsgen_slverr(data)               (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SCPU_WRAPPER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apb_cssys_a:32;
    };
}scpu_wrapper_cssys_apb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apb_cssys_d:32;
    };
}scpu_wrapper_cssys_apb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  apb_cssys_slverr:1;
    };
}scpu_wrapper_cssys_apb3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  chk_invalid_cmd:1;
        RBus_UInt32  fbusrandwstrb:1;
        RBus_UInt32  remote_cmd_num:4;
        RBus_UInt32  remote_wdata_num:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  all_wr_nonbuf:1;
        RBus_UInt32  wr_outstand_num:4;
        RBus_UInt32  rd_outstand_num:4;
    };
}scpu_wrapper_wrapper_cfg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  scpu_dbg_sel:4;
    };
}scpu_wrapper_wrapper_cfg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  scpu_dbg_mode_sel:2;
        RBus_UInt32  scpu_dbg_sel_dc:4;
        RBus_UInt32  scpu_dbg_sel_fr:4;
        RBus_UInt32  scpu_dbg_sel_dis:4;
    };
}scpu_wrapper_dbg_sel_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_start_addr_m0:32;
    };
}scpu_wrapper_mem_trash_dbg_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_end_addr_m0:32;
    };
}scpu_wrapper_mem_trash_dbg_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  dbg_wr_chk_m0:2;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  dbg_en_m0:1;
    };
}scpu_wrapper_mem_trash_dbg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  scpu_int_m0:1;
        RBus_UInt32  scpu_int_en_m0:1;
        RBus_UInt32  scpu_neg_int_m0:1;
        RBus_UInt32  scpu_neg_int_en_m0:1;
        RBus_UInt32  write_data:1;
    };
}scpu_wrapper_mem_trash_dbg_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_addr_m0:32;
    };
}scpu_wrapper_mem_trash_dbg_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  scpu_dbg_write_m0:1;
    };
}scpu_wrapper_mem_trash_dbg_rw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_rw:32;
    };
}scpu_wrapper_eco_rw_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_r_only:32;
    };
}scpu_wrapper_eco_r_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  scpu_axi_bready:1;
        RBus_UInt32  axi_rdata_fifo_empty:1;
        RBus_UInt32  axi_wid_empty:1;
        RBus_UInt32  axi_wdata_fifo_empty:1;
        RBus_UInt32  axi_rcmd_fifo_empty:1;
        RBus_UInt32  axi_wcmd_fifo_empty:1;
    };
}scpu_wrapper_debugaxi128b_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  axi_rdata_fifo_full:1;
        RBus_UInt32  axi_wid_full:1;
        RBus_UInt32  axi_wdata_fifo_full:1;
        RBus_UInt32  axi_rcmd_fifo_full:1;
        RBus_UInt32  axi_wcmd_fifo_full:1;
    };
}scpu_wrapper_debugaxi128b_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  scpu_axi_bready_mp:1;
        RBus_UInt32  peri_axi_rdata_fifo_empty:1;
        RBus_UInt32  peri_axi_wid_empty:1;
        RBus_UInt32  peri_axi_wdata_fifo_empty:1;
        RBus_UInt32  peri_axi_rcmd_fifo_empty:1;
        RBus_UInt32  peri_axi_wcmd_fifo_empty:1;
    };
}scpu_wrapper_debugaxi32b_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  peri_axi_rdata_fifo_full:1;
        RBus_UInt32  peri_axi_wid_full:1;
        RBus_UInt32  peri_axi_wdata_fifo_full:1;
        RBus_UInt32  peri_axi_rcmd_fifo_full:1;
        RBus_UInt32  peri_axi_wcmd_fifo_full:1;
    };
}scpu_wrapper_debugaxi32b_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dis_cmd_async_fifo_empty:1;
        RBus_UInt32  dis_cmd_async_fifo_full:1;
        RBus_UInt32  dc2_cmd_async_fifo_empty:1;
        RBus_UInt32  dc2_cmd_async_fifo_full:1;
        RBus_UInt32  dc_cmd_async_fifo_empty:1;
        RBus_UInt32  dc_cmd_async_fifo_full:1;
    };
}scpu_wrapper_debugwrapper_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dis_wdata_async_fifo_empty:1;
        RBus_UInt32  dis_wdata_async_fifo_full:1;
        RBus_UInt32  dc2_wdata_async_fifo_empty:1;
        RBus_UInt32  dc2_wdata_async_fifo_full:1;
        RBus_UInt32  dc_wdata_async_fifo_empty:1;
        RBus_UInt32  dc_wdata_async_fifo_full:1;
    };
}scpu_wrapper_debugwrapper_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dis_rdata_async_fifo_empty:1;
        RBus_UInt32  dis_rdata_async_fifo_full:1;
        RBus_UInt32  dc2_rdata_async_fifo_empty:1;
        RBus_UInt32  dc2_rdata_async_fifo_full:1;
        RBus_UInt32  dc_rdata_async_fifo_empty:1;
        RBus_UInt32  dc_rdata_async_fifo_full:1;
    };
}scpu_wrapper_debugwrapper_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  dis_rdata_sync_fifo_full:1;
        RBus_UInt32  dis_rdata_sync_fifo_empty:1;
        RBus_UInt32  dc2_rd_outstanding_buf_fifo_cnt:7;
        RBus_UInt32  dc2_rd_outstanding_buf_full:1;
        RBus_UInt32  dc2_rd_outstanding_buf_empty:1;
        RBus_UInt32  dc_rd_outstanding_buf_fifo_cnt:7;
        RBus_UInt32  dc_rd_outstanding_buf_full:1;
        RBus_UInt32  dc_rd_outstanding_buf_empty:1;
    };
}scpu_wrapper_debugwrapper_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  stop_dbg_main_wr:1;
        RBus_UInt32  stop_dbg_main_rd:1;
        RBus_UInt32  stop_dbg_peri_wr:1;
        RBus_UInt32  stop_dbg_peri_rd:1;
    };
}scpu_wrapper_axidbg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  valid_entry_cnt_main_wr:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  valid_entry_cnt_main_rd:5;
        RBus_UInt32  res3:6;
        RBus_UInt32  valid_entry_cnt_peri_wr:2;
        RBus_UInt32  res4:6;
        RBus_UInt32  valid_entry_cnt_peri_rd:2;
    };
}scpu_wrapper_axidbg_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_waddr:32;
    };
}scpu_wrapper_axidbg_main_waddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  main_wid:9;
    };
}scpu_wrapper_axidbg_main_wid_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_raddr:32;
    };
}scpu_wrapper_axidbg_main_raddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  main_rid:9;
    };
}scpu_wrapper_axidbg_main_rid_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peri_waddr:32;
    };
}scpu_wrapper_axidbg_peri_waddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  peri_wid:9;
    };
}scpu_wrapper_axidbg_peri_wid_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peri_raddr:32;
    };
}scpu_wrapper_axidbg_peri_raddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  peri_rid:9;
    };
}scpu_wrapper_axidbg_peri_rid_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  reg_sf_rx_gated:1;
        RBus_UInt32  reg_sf_rx_start:1;
        RBus_UInt32  reg_sf_rx_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_sf_tx_start:1;
        RBus_UInt32  reg_sf_tx_mode:1;
    };
}scpu_wrapper_sf_test_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  reg_sf_rx_err:1;
        RBus_UInt32  reg_sf_rx_done:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_sf_tx_work:1;
    };
}scpu_wrapper_sf_test_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apb_tsgen_a:32;
    };
}scpu_wrapper_tsgen_input_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apb_tsgen_d:32;
    };
}scpu_wrapper_tsgen_input_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  apb_tsgen_slverr:1;
    };
}scpu_wrapper_tsgen_input_ctrl2_RBUS;

#else //apply LITTLE_ENDIAN

//======SCPU_WRAPPER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apb_cssys_a:32;
    };
}scpu_wrapper_cssys_apb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apb_cssys_d:32;
    };
}scpu_wrapper_cssys_apb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apb_cssys_slverr:1;
        RBus_UInt32  res1:31;
    };
}scpu_wrapper_cssys_apb3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_outstand_num:4;
        RBus_UInt32  wr_outstand_num:4;
        RBus_UInt32  all_wr_nonbuf:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  remote_wdata_num:4;
        RBus_UInt32  remote_cmd_num:4;
        RBus_UInt32  fbusrandwstrb:1;
        RBus_UInt32  chk_invalid_cmd:1;
        RBus_UInt32  res2:12;
    };
}scpu_wrapper_wrapper_cfg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_dbg_sel:4;
        RBus_UInt32  res1:28;
    };
}scpu_wrapper_wrapper_cfg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_dbg_sel_dis:4;
        RBus_UInt32  scpu_dbg_sel_fr:4;
        RBus_UInt32  scpu_dbg_sel_dc:4;
        RBus_UInt32  scpu_dbg_mode_sel:2;
        RBus_UInt32  res1:18;
    };
}scpu_wrapper_dbg_sel_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_start_addr_m0:32;
    };
}scpu_wrapper_mem_trash_dbg_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_end_addr_m0:32;
    };
}scpu_wrapper_mem_trash_dbg_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_en_m0:1;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  dbg_wr_chk_m0:2;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  res1:27;
    };
}scpu_wrapper_mem_trash_dbg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  scpu_neg_int_en_m0:1;
        RBus_UInt32  scpu_neg_int_m0:1;
        RBus_UInt32  scpu_int_en_m0:1;
        RBus_UInt32  scpu_int_m0:1;
        RBus_UInt32  res1:27;
    };
}scpu_wrapper_mem_trash_dbg_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_addr_m0:32;
    };
}scpu_wrapper_mem_trash_dbg_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_dbg_write_m0:1;
        RBus_UInt32  res1:31;
    };
}scpu_wrapper_mem_trash_dbg_rw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_rw:32;
    };
}scpu_wrapper_eco_rw_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_r_only:32;
    };
}scpu_wrapper_eco_r_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  axi_wcmd_fifo_empty:1;
        RBus_UInt32  axi_rcmd_fifo_empty:1;
        RBus_UInt32  axi_wdata_fifo_empty:1;
        RBus_UInt32  axi_wid_empty:1;
        RBus_UInt32  axi_rdata_fifo_empty:1;
        RBus_UInt32  scpu_axi_bready:1;
        RBus_UInt32  res1:26;
    };
}scpu_wrapper_debugaxi128b_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  axi_wcmd_fifo_full:1;
        RBus_UInt32  axi_rcmd_fifo_full:1;
        RBus_UInt32  axi_wdata_fifo_full:1;
        RBus_UInt32  axi_wid_full:1;
        RBus_UInt32  axi_rdata_fifo_full:1;
        RBus_UInt32  res1:27;
    };
}scpu_wrapper_debugaxi128b_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peri_axi_wcmd_fifo_empty:1;
        RBus_UInt32  peri_axi_rcmd_fifo_empty:1;
        RBus_UInt32  peri_axi_wdata_fifo_empty:1;
        RBus_UInt32  peri_axi_wid_empty:1;
        RBus_UInt32  peri_axi_rdata_fifo_empty:1;
        RBus_UInt32  scpu_axi_bready_mp:1;
        RBus_UInt32  res1:26;
    };
}scpu_wrapper_debugaxi32b_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peri_axi_wcmd_fifo_full:1;
        RBus_UInt32  peri_axi_rcmd_fifo_full:1;
        RBus_UInt32  peri_axi_wdata_fifo_full:1;
        RBus_UInt32  peri_axi_wid_full:1;
        RBus_UInt32  peri_axi_rdata_fifo_full:1;
        RBus_UInt32  res1:27;
    };
}scpu_wrapper_debugaxi32b_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_cmd_async_fifo_full:1;
        RBus_UInt32  dc_cmd_async_fifo_empty:1;
        RBus_UInt32  dc2_cmd_async_fifo_full:1;
        RBus_UInt32  dc2_cmd_async_fifo_empty:1;
        RBus_UInt32  dis_cmd_async_fifo_full:1;
        RBus_UInt32  dis_cmd_async_fifo_empty:1;
        RBus_UInt32  res1:26;
    };
}scpu_wrapper_debugwrapper_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_wdata_async_fifo_full:1;
        RBus_UInt32  dc_wdata_async_fifo_empty:1;
        RBus_UInt32  dc2_wdata_async_fifo_full:1;
        RBus_UInt32  dc2_wdata_async_fifo_empty:1;
        RBus_UInt32  dis_wdata_async_fifo_full:1;
        RBus_UInt32  dis_wdata_async_fifo_empty:1;
        RBus_UInt32  res1:26;
    };
}scpu_wrapper_debugwrapper_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_rdata_async_fifo_full:1;
        RBus_UInt32  dc_rdata_async_fifo_empty:1;
        RBus_UInt32  dc2_rdata_async_fifo_full:1;
        RBus_UInt32  dc2_rdata_async_fifo_empty:1;
        RBus_UInt32  dis_rdata_async_fifo_full:1;
        RBus_UInt32  dis_rdata_async_fifo_empty:1;
        RBus_UInt32  res1:26;
    };
}scpu_wrapper_debugwrapper_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_rd_outstanding_buf_empty:1;
        RBus_UInt32  dc_rd_outstanding_buf_full:1;
        RBus_UInt32  dc_rd_outstanding_buf_fifo_cnt:7;
        RBus_UInt32  dc2_rd_outstanding_buf_empty:1;
        RBus_UInt32  dc2_rd_outstanding_buf_full:1;
        RBus_UInt32  dc2_rd_outstanding_buf_fifo_cnt:7;
        RBus_UInt32  dis_rdata_sync_fifo_empty:1;
        RBus_UInt32  dis_rdata_sync_fifo_full:1;
        RBus_UInt32  res1:12;
    };
}scpu_wrapper_debugwrapper_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stop_dbg_peri_rd:1;
        RBus_UInt32  stop_dbg_peri_wr:1;
        RBus_UInt32  stop_dbg_main_rd:1;
        RBus_UInt32  stop_dbg_main_wr:1;
        RBus_UInt32  res1:28;
    };
}scpu_wrapper_axidbg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  valid_entry_cnt_peri_rd:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  valid_entry_cnt_peri_wr:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  valid_entry_cnt_main_rd:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  valid_entry_cnt_main_wr:5;
        RBus_UInt32  res4:3;
    };
}scpu_wrapper_axidbg_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_waddr:32;
    };
}scpu_wrapper_axidbg_main_waddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_wid:9;
        RBus_UInt32  res1:23;
    };
}scpu_wrapper_axidbg_main_wid_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_raddr:32;
    };
}scpu_wrapper_axidbg_main_raddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_rid:9;
        RBus_UInt32  res1:23;
    };
}scpu_wrapper_axidbg_main_rid_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peri_waddr:32;
    };
}scpu_wrapper_axidbg_peri_waddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peri_wid:9;
        RBus_UInt32  res1:23;
    };
}scpu_wrapper_axidbg_peri_wid_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peri_raddr:32;
    };
}scpu_wrapper_axidbg_peri_raddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peri_rid:9;
        RBus_UInt32  res1:23;
    };
}scpu_wrapper_axidbg_peri_rid_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_sf_tx_mode:1;
        RBus_UInt32  reg_sf_tx_start:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_sf_rx_mode:1;
        RBus_UInt32  reg_sf_rx_start:1;
        RBus_UInt32  reg_sf_rx_gated:1;
        RBus_UInt32  res2:25;
    };
}scpu_wrapper_sf_test_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_sf_tx_work:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_sf_rx_done:1;
        RBus_UInt32  reg_sf_rx_err:1;
        RBus_UInt32  res2:26;
    };
}scpu_wrapper_sf_test_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apb_tsgen_a:32;
    };
}scpu_wrapper_tsgen_input_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apb_tsgen_d:32;
    };
}scpu_wrapper_tsgen_input_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apb_tsgen_slverr:1;
        RBus_UInt32  res1:31;
    };
}scpu_wrapper_tsgen_input_ctrl2_RBUS;




#endif 


#endif 
