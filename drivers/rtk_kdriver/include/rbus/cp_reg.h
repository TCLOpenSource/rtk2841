/**
* @file Mac5-DesignSpec-CP
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_CP_REG_H_
#define _RBUS_CP_REG_H_

#include "rbus_types.h"



//  CP Register Address
#define  CP_MCP_CTRL                                                             0x18015100
#define  CP_MCP_CTRL_reg_addr                                                    "0xB8015100"
#define  CP_MCP_CTRL_reg                                                         0xB8015100
#define  CP_MCP_CTRL_inst_addr                                                   "0x0000"
#define  set_CP_MCP_CTRL_reg(data)                                               (*((volatile unsigned int*)CP_MCP_CTRL_reg)=data)
#define  get_CP_MCP_CTRL_reg                                                     (*((volatile unsigned int*)CP_MCP_CTRL_reg))
#define  CP_MCP_CTRL_arb_mode_shift                                              (6)
#define  CP_MCP_CTRL_clear_shift                                                 (4)
#define  CP_MCP_CTRL_swap_shift                                                  (3)
#define  CP_MCP_CTRL_idle_shift                                                  (2)
#define  CP_MCP_CTRL_go_shift                                                    (1)
#define  CP_MCP_CTRL_write_data_shift                                            (0)
#define  CP_MCP_CTRL_arb_mode_mask                                               (0x00000040)
#define  CP_MCP_CTRL_clear_mask                                                  (0x00000010)
#define  CP_MCP_CTRL_swap_mask                                                   (0x00000008)
#define  CP_MCP_CTRL_idle_mask                                                   (0x00000004)
#define  CP_MCP_CTRL_go_mask                                                     (0x00000002)
#define  CP_MCP_CTRL_write_data_mask                                             (0x00000001)
#define  CP_MCP_CTRL_arb_mode(data)                                              (0x00000040&((data)<<6))
#define  CP_MCP_CTRL_clear(data)                                                 (0x00000010&((data)<<4))
#define  CP_MCP_CTRL_swap(data)                                                  (0x00000008&((data)<<3))
#define  CP_MCP_CTRL_idle(data)                                                  (0x00000004&((data)<<2))
#define  CP_MCP_CTRL_go(data)                                                    (0x00000002&((data)<<1))
#define  CP_MCP_CTRL_write_data(data)                                            (0x00000001&(data))
#define  CP_MCP_CTRL_get_arb_mode(data)                                          ((0x00000040&(data))>>6)
#define  CP_MCP_CTRL_get_clear(data)                                             ((0x00000010&(data))>>4)
#define  CP_MCP_CTRL_get_swap(data)                                              ((0x00000008&(data))>>3)
#define  CP_MCP_CTRL_get_idle(data)                                              ((0x00000004&(data))>>2)
#define  CP_MCP_CTRL_get_go(data)                                                ((0x00000002&(data))>>1)
#define  CP_MCP_CTRL_get_write_data(data)                                        (0x00000001&(data))

#define  CP_MCP_STATUS                                                           0x18015104
#define  CP_MCP_STATUS_reg_addr                                                  "0xB8015104"
#define  CP_MCP_STATUS_reg                                                       0xB8015104
#define  CP_MCP_STATUS_inst_addr                                                 "0x0001"
#define  set_CP_MCP_STATUS_reg(data)                                             (*((volatile unsigned int*)CP_MCP_STATUS_reg)=data)
#define  get_CP_MCP_STATUS_reg                                                   (*((volatile unsigned int*)CP_MCP_STATUS_reg))
#define  CP_MCP_STATUS_k_error_shift                                             (9)
#define  CP_MCP_STATUS_k_compare_shift                                           (8)
#define  CP_MCP_STATUS_k_ring_empty_shift                                        (7)
#define  CP_MCP_STATUS_compare_shift                                             (3)
#define  CP_MCP_STATUS_error_shift                                               (2)
#define  CP_MCP_STATUS_ring_empty_shift                                          (1)
#define  CP_MCP_STATUS_write_data_shift                                          (0)
#define  CP_MCP_STATUS_k_error_mask                                              (0x00000200)
#define  CP_MCP_STATUS_k_compare_mask                                            (0x00000100)
#define  CP_MCP_STATUS_k_ring_empty_mask                                         (0x00000080)
#define  CP_MCP_STATUS_compare_mask                                              (0x00000008)
#define  CP_MCP_STATUS_error_mask                                                (0x00000004)
#define  CP_MCP_STATUS_ring_empty_mask                                           (0x00000002)
#define  CP_MCP_STATUS_write_data_mask                                           (0x00000001)
#define  CP_MCP_STATUS_k_error(data)                                             (0x00000200&((data)<<9))
#define  CP_MCP_STATUS_k_compare(data)                                           (0x00000100&((data)<<8))
#define  CP_MCP_STATUS_k_ring_empty(data)                                        (0x00000080&((data)<<7))
#define  CP_MCP_STATUS_compare(data)                                             (0x00000008&((data)<<3))
#define  CP_MCP_STATUS_error(data)                                               (0x00000004&((data)<<2))
#define  CP_MCP_STATUS_ring_empty(data)                                          (0x00000002&((data)<<1))
#define  CP_MCP_STATUS_write_data(data)                                          (0x00000001&(data))
#define  CP_MCP_STATUS_get_k_error(data)                                         ((0x00000200&(data))>>9)
#define  CP_MCP_STATUS_get_k_compare(data)                                       ((0x00000100&(data))>>8)
#define  CP_MCP_STATUS_get_k_ring_empty(data)                                    ((0x00000080&(data))>>7)
#define  CP_MCP_STATUS_get_compare(data)                                         ((0x00000008&(data))>>3)
#define  CP_MCP_STATUS_get_error(data)                                           ((0x00000004&(data))>>2)
#define  CP_MCP_STATUS_get_ring_empty(data)                                      ((0x00000002&(data))>>1)
#define  CP_MCP_STATUS_get_write_data(data)                                      (0x00000001&(data))

#define  CP_MCP_EN                                                               0x18015108
#define  CP_MCP_EN_reg_addr                                                      "0xB8015108"
#define  CP_MCP_EN_reg                                                           0xB8015108
#define  CP_MCP_EN_inst_addr                                                     "0x0002"
#define  set_CP_MCP_EN_reg(data)                                                 (*((volatile unsigned int*)CP_MCP_EN_reg)=data)
#define  get_CP_MCP_EN_reg                                                       (*((volatile unsigned int*)CP_MCP_EN_reg))
#define  CP_MCP_EN_compare_en_shift                                              (3)
#define  CP_MCP_EN_error_en_shift                                                (2)
#define  CP_MCP_EN_ring_empty_en_shift                                           (1)
#define  CP_MCP_EN_write_data_shift                                              (0)
#define  CP_MCP_EN_compare_en_mask                                               (0x00000008)
#define  CP_MCP_EN_error_en_mask                                                 (0x00000004)
#define  CP_MCP_EN_ring_empty_en_mask                                            (0x00000002)
#define  CP_MCP_EN_write_data_mask                                               (0x00000001)
#define  CP_MCP_EN_compare_en(data)                                              (0x00000008&((data)<<3))
#define  CP_MCP_EN_error_en(data)                                                (0x00000004&((data)<<2))
#define  CP_MCP_EN_ring_empty_en(data)                                           (0x00000002&((data)<<1))
#define  CP_MCP_EN_write_data(data)                                              (0x00000001&(data))
#define  CP_MCP_EN_get_compare_en(data)                                          ((0x00000008&(data))>>3)
#define  CP_MCP_EN_get_error_en(data)                                            ((0x00000004&(data))>>2)
#define  CP_MCP_EN_get_ring_empty_en(data)                                       ((0x00000002&(data))>>1)
#define  CP_MCP_EN_get_write_data(data)                                          (0x00000001&(data))

#define  CP_MCP_CTRL1                                                            0x18015198
#define  CP_MCP_CTRL1_reg_addr                                                   "0xB8015198"
#define  CP_MCP_CTRL1_reg                                                        0xB8015198
#define  CP_MCP_CTRL1_inst_addr                                                  "0x0003"
#define  set_CP_MCP_CTRL1_reg(data)                                              (*((volatile unsigned int*)CP_MCP_CTRL1_reg)=data)
#define  get_CP_MCP_CTRL1_reg                                                    (*((volatile unsigned int*)CP_MCP_CTRL1_reg))
#define  CP_MCP_CTRL1_aesh_pad_off_shift                                         (10)
#define  CP_MCP_CTRL1_csa_entropy_shift                                          (8)
#define  CP_MCP_CTRL1_mcp_round_no_shift                                         (0)
#define  CP_MCP_CTRL1_aesh_pad_off_mask                                          (0x00000400)
#define  CP_MCP_CTRL1_csa_entropy_mask                                           (0x00000300)
#define  CP_MCP_CTRL1_mcp_round_no_mask                                          (0x000000FF)
#define  CP_MCP_CTRL1_aesh_pad_off(data)                                         (0x00000400&((data)<<10))
#define  CP_MCP_CTRL1_csa_entropy(data)                                          (0x00000300&((data)<<8))
#define  CP_MCP_CTRL1_mcp_round_no(data)                                         (0x000000FF&(data))
#define  CP_MCP_CTRL1_get_aesh_pad_off(data)                                     ((0x00000400&(data))>>10)
#define  CP_MCP_CTRL1_get_csa_entropy(data)                                      ((0x00000300&(data))>>8)
#define  CP_MCP_CTRL1_get_mcp_round_no(data)                                     (0x000000FF&(data))

#define  CP_MCP_BASE                                                             0x1801510C
#define  CP_MCP_BASE_reg_addr                                                    "0xB801510C"
#define  CP_MCP_BASE_reg                                                         0xB801510C
#define  CP_MCP_BASE_inst_addr                                                   "0x0004"
#define  set_CP_MCP_BASE_reg(data)                                               (*((volatile unsigned int*)CP_MCP_BASE_reg)=data)
#define  get_CP_MCP_BASE_reg                                                     (*((volatile unsigned int*)CP_MCP_BASE_reg))
#define  CP_MCP_BASE_base_shift                                                  (0)
#define  CP_MCP_BASE_base_mask                                                   (0xFFFFFFFF)
#define  CP_MCP_BASE_base(data)                                                  (0xFFFFFFFF&(data))
#define  CP_MCP_BASE_get_base(data)                                              (0xFFFFFFFF&(data))

#define  CP_MCP_LIMIT                                                            0x18015110
#define  CP_MCP_LIMIT_reg_addr                                                   "0xB8015110"
#define  CP_MCP_LIMIT_reg                                                        0xB8015110
#define  CP_MCP_LIMIT_inst_addr                                                  "0x0005"
#define  set_CP_MCP_LIMIT_reg(data)                                              (*((volatile unsigned int*)CP_MCP_LIMIT_reg)=data)
#define  get_CP_MCP_LIMIT_reg                                                    (*((volatile unsigned int*)CP_MCP_LIMIT_reg))
#define  CP_MCP_LIMIT_limit_shift                                                (0)
#define  CP_MCP_LIMIT_limit_mask                                                 (0xFFFFFFFF)
#define  CP_MCP_LIMIT_limit(data)                                                (0xFFFFFFFF&(data))
#define  CP_MCP_LIMIT_get_limit(data)                                            (0xFFFFFFFF&(data))

#define  CP_MCP_RDPTR                                                            0x18015114
#define  CP_MCP_RDPTR_reg_addr                                                   "0xB8015114"
#define  CP_MCP_RDPTR_reg                                                        0xB8015114
#define  CP_MCP_RDPTR_inst_addr                                                  "0x0006"
#define  set_CP_MCP_RDPTR_reg(data)                                              (*((volatile unsigned int*)CP_MCP_RDPTR_reg)=data)
#define  get_CP_MCP_RDPTR_reg                                                    (*((volatile unsigned int*)CP_MCP_RDPTR_reg))
#define  CP_MCP_RDPTR_rdptr_shift                                                (0)
#define  CP_MCP_RDPTR_rdptr_mask                                                 (0xFFFFFFFF)
#define  CP_MCP_RDPTR_rdptr(data)                                                (0xFFFFFFFF&(data))
#define  CP_MCP_RDPTR_get_rdptr(data)                                            (0xFFFFFFFF&(data))

#define  CP_MCP_WRPTR                                                            0x18015118
#define  CP_MCP_WRPTR_reg_addr                                                   "0xB8015118"
#define  CP_MCP_WRPTR_reg                                                        0xB8015118
#define  CP_MCP_WRPTR_inst_addr                                                  "0x0007"
#define  set_CP_MCP_WRPTR_reg(data)                                              (*((volatile unsigned int*)CP_MCP_WRPTR_reg)=data)
#define  get_CP_MCP_WRPTR_reg                                                    (*((volatile unsigned int*)CP_MCP_WRPTR_reg))
#define  CP_MCP_WRPTR_wrptr_shift                                                (0)
#define  CP_MCP_WRPTR_wrptr_mask                                                 (0xFFFFFFFF)
#define  CP_MCP_WRPTR_wrptr(data)                                                (0xFFFFFFFF&(data))
#define  CP_MCP_WRPTR_get_wrptr(data)                                            (0xFFFFFFFF&(data))

#define  CP_MCP_DES_COUNT                                                        0x18015134
#define  CP_MCP_DES_COUNT_reg_addr                                               "0xB8015134"
#define  CP_MCP_DES_COUNT_reg                                                    0xB8015134
#define  CP_MCP_DES_COUNT_inst_addr                                              "0x0008"
#define  set_CP_MCP_DES_COUNT_reg(data)                                          (*((volatile unsigned int*)CP_MCP_DES_COUNT_reg)=data)
#define  get_CP_MCP_DES_COUNT_reg                                                (*((volatile unsigned int*)CP_MCP_DES_COUNT_reg))
#define  CP_MCP_DES_COUNT_count_shift                                            (0)
#define  CP_MCP_DES_COUNT_count_mask                                             (0x0000FFFF)
#define  CP_MCP_DES_COUNT_count(data)                                            (0x0000FFFF&(data))
#define  CP_MCP_DES_COUNT_get_count(data)                                        (0x0000FFFF&(data))

#define  CP_MCP_DES_COMPARE                                                      0x18015138
#define  CP_MCP_DES_COMPARE_reg_addr                                             "0xB8015138"
#define  CP_MCP_DES_COMPARE_reg                                                  0xB8015138
#define  CP_MCP_DES_COMPARE_inst_addr                                            "0x0009"
#define  set_CP_MCP_DES_COMPARE_reg(data)                                        (*((volatile unsigned int*)CP_MCP_DES_COMPARE_reg)=data)
#define  get_CP_MCP_DES_COMPARE_reg                                              (*((volatile unsigned int*)CP_MCP_DES_COMPARE_reg))
#define  CP_MCP_DES_COMPARE_compare_shift                                        (0)
#define  CP_MCP_DES_COMPARE_compare_mask                                         (0x0000FFFF)
#define  CP_MCP_DES_COMPARE_compare(data)                                        (0x0000FFFF&(data))
#define  CP_MCP_DES_COMPARE_get_compare(data)                                    (0x0000FFFF&(data))

#define  CP_MCP_DES_INI_KEY_0                                                    0x1801511C
#define  CP_MCP_DES_INI_KEY_0_reg_addr                                           "0xB801511C"
#define  CP_MCP_DES_INI_KEY_0_reg                                                0xB801511C
#define  CP_MCP_DES_INI_KEY_0_inst_addr                                          "0x000A"
#define  set_CP_MCP_DES_INI_KEY_0_reg(data)                                      (*((volatile unsigned int*)CP_MCP_DES_INI_KEY_0_reg)=data)
#define  get_CP_MCP_DES_INI_KEY_0_reg                                            (*((volatile unsigned int*)CP_MCP_DES_INI_KEY_0_reg))
#define  CP_MCP_DES_INI_KEY_0_data_shift                                         (0)
#define  CP_MCP_DES_INI_KEY_0_data_mask                                          (0xFFFFFFFF)
#define  CP_MCP_DES_INI_KEY_0_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_MCP_DES_INI_KEY_0_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_MCP_DES_INI_KEY_1                                                    0x18015120
#define  CP_MCP_DES_INI_KEY_1_reg_addr                                           "0xB8015120"
#define  CP_MCP_DES_INI_KEY_1_reg                                                0xB8015120
#define  CP_MCP_DES_INI_KEY_1_inst_addr                                          "0x000B"
#define  set_CP_MCP_DES_INI_KEY_1_reg(data)                                      (*((volatile unsigned int*)CP_MCP_DES_INI_KEY_1_reg)=data)
#define  get_CP_MCP_DES_INI_KEY_1_reg                                            (*((volatile unsigned int*)CP_MCP_DES_INI_KEY_1_reg))
#define  CP_MCP_DES_INI_KEY_1_data_shift                                         (0)
#define  CP_MCP_DES_INI_KEY_1_data_mask                                          (0xFFFFFFFF)
#define  CP_MCP_DES_INI_KEY_1_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_MCP_DES_INI_KEY_1_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_MCP_AES_INI_KEY_0                                                    0x18015124
#define  CP_MCP_AES_INI_KEY_0_reg_addr                                           "0xB8015124"
#define  CP_MCP_AES_INI_KEY_0_reg                                                0xB8015124
#define  CP_MCP_AES_INI_KEY_0_inst_addr                                          "0x000C"
#define  set_CP_MCP_AES_INI_KEY_0_reg(data)                                      (*((volatile unsigned int*)CP_MCP_AES_INI_KEY_0_reg)=data)
#define  get_CP_MCP_AES_INI_KEY_0_reg                                            (*((volatile unsigned int*)CP_MCP_AES_INI_KEY_0_reg))
#define  CP_MCP_AES_INI_KEY_0_data_shift                                         (0)
#define  CP_MCP_AES_INI_KEY_0_data_mask                                          (0xFFFFFFFF)
#define  CP_MCP_AES_INI_KEY_0_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_MCP_AES_INI_KEY_0_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_MCP_AES_INI_KEY_1                                                    0x18015128
#define  CP_MCP_AES_INI_KEY_1_reg_addr                                           "0xB8015128"
#define  CP_MCP_AES_INI_KEY_1_reg                                                0xB8015128
#define  CP_MCP_AES_INI_KEY_1_inst_addr                                          "0x000D"
#define  set_CP_MCP_AES_INI_KEY_1_reg(data)                                      (*((volatile unsigned int*)CP_MCP_AES_INI_KEY_1_reg)=data)
#define  get_CP_MCP_AES_INI_KEY_1_reg                                            (*((volatile unsigned int*)CP_MCP_AES_INI_KEY_1_reg))
#define  CP_MCP_AES_INI_KEY_1_data_shift                                         (0)
#define  CP_MCP_AES_INI_KEY_1_data_mask                                          (0xFFFFFFFF)
#define  CP_MCP_AES_INI_KEY_1_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_MCP_AES_INI_KEY_1_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_MCP_AES_INI_KEY_2                                                    0x1801512C
#define  CP_MCP_AES_INI_KEY_2_reg_addr                                           "0xB801512C"
#define  CP_MCP_AES_INI_KEY_2_reg                                                0xB801512C
#define  CP_MCP_AES_INI_KEY_2_inst_addr                                          "0x000E"
#define  set_CP_MCP_AES_INI_KEY_2_reg(data)                                      (*((volatile unsigned int*)CP_MCP_AES_INI_KEY_2_reg)=data)
#define  get_CP_MCP_AES_INI_KEY_2_reg                                            (*((volatile unsigned int*)CP_MCP_AES_INI_KEY_2_reg))
#define  CP_MCP_AES_INI_KEY_2_data_shift                                         (0)
#define  CP_MCP_AES_INI_KEY_2_data_mask                                          (0xFFFFFFFF)
#define  CP_MCP_AES_INI_KEY_2_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_MCP_AES_INI_KEY_2_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_MCP_AES_INI_KEY_3                                                    0x18015130
#define  CP_MCP_AES_INI_KEY_3_reg_addr                                           "0xB8015130"
#define  CP_MCP_AES_INI_KEY_3_reg                                                0xB8015130
#define  CP_MCP_AES_INI_KEY_3_inst_addr                                          "0x000F"
#define  set_CP_MCP_AES_INI_KEY_3_reg(data)                                      (*((volatile unsigned int*)CP_MCP_AES_INI_KEY_3_reg)=data)
#define  get_CP_MCP_AES_INI_KEY_3_reg                                            (*((volatile unsigned int*)CP_MCP_AES_INI_KEY_3_reg))
#define  CP_MCP_AES_INI_KEY_3_data_shift                                         (0)
#define  CP_MCP_AES_INI_KEY_3_data_mask                                          (0xFFFFFFFF)
#define  CP_MCP_AES_INI_KEY_3_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_MCP_AES_INI_KEY_3_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_MCP_CAME_INI_KEY_0                                                   0x1801513C
#define  CP_MCP_CAME_INI_KEY_0_reg_addr                                          "0xB801513C"
#define  CP_MCP_CAME_INI_KEY_0_reg                                               0xB801513C
#define  CP_MCP_CAME_INI_KEY_0_inst_addr                                         "0x0010"
#define  set_CP_MCP_CAME_INI_KEY_0_reg(data)                                     (*((volatile unsigned int*)CP_MCP_CAME_INI_KEY_0_reg)=data)
#define  get_CP_MCP_CAME_INI_KEY_0_reg                                           (*((volatile unsigned int*)CP_MCP_CAME_INI_KEY_0_reg))
#define  CP_MCP_CAME_INI_KEY_0_data_shift                                        (0)
#define  CP_MCP_CAME_INI_KEY_0_data_mask                                         (0xFFFFFFFF)
#define  CP_MCP_CAME_INI_KEY_0_data(data)                                        (0xFFFFFFFF&(data))
#define  CP_MCP_CAME_INI_KEY_0_get_data(data)                                    (0xFFFFFFFF&(data))

#define  CP_MCP_CAME_INI_KEY_1                                                   0x18015140
#define  CP_MCP_CAME_INI_KEY_1_reg_addr                                          "0xB8015140"
#define  CP_MCP_CAME_INI_KEY_1_reg                                               0xB8015140
#define  CP_MCP_CAME_INI_KEY_1_inst_addr                                         "0x0011"
#define  set_CP_MCP_CAME_INI_KEY_1_reg(data)                                     (*((volatile unsigned int*)CP_MCP_CAME_INI_KEY_1_reg)=data)
#define  get_CP_MCP_CAME_INI_KEY_1_reg                                           (*((volatile unsigned int*)CP_MCP_CAME_INI_KEY_1_reg))
#define  CP_MCP_CAME_INI_KEY_1_data_shift                                        (0)
#define  CP_MCP_CAME_INI_KEY_1_data_mask                                         (0xFFFFFFFF)
#define  CP_MCP_CAME_INI_KEY_1_data(data)                                        (0xFFFFFFFF&(data))
#define  CP_MCP_CAME_INI_KEY_1_get_data(data)                                    (0xFFFFFFFF&(data))

#define  CP_MCP_CAME_INI_KEY_2                                                   0x18015144
#define  CP_MCP_CAME_INI_KEY_2_reg_addr                                          "0xB8015144"
#define  CP_MCP_CAME_INI_KEY_2_reg                                               0xB8015144
#define  CP_MCP_CAME_INI_KEY_2_inst_addr                                         "0x0012"
#define  set_CP_MCP_CAME_INI_KEY_2_reg(data)                                     (*((volatile unsigned int*)CP_MCP_CAME_INI_KEY_2_reg)=data)
#define  get_CP_MCP_CAME_INI_KEY_2_reg                                           (*((volatile unsigned int*)CP_MCP_CAME_INI_KEY_2_reg))
#define  CP_MCP_CAME_INI_KEY_2_data_shift                                        (0)
#define  CP_MCP_CAME_INI_KEY_2_data_mask                                         (0xFFFFFFFF)
#define  CP_MCP_CAME_INI_KEY_2_data(data)                                        (0xFFFFFFFF&(data))
#define  CP_MCP_CAME_INI_KEY_2_get_data(data)                                    (0xFFFFFFFF&(data))

#define  CP_MCP_CAME_INI_KEY_3                                                   0x18015148
#define  CP_MCP_CAME_INI_KEY_3_reg_addr                                          "0xB8015148"
#define  CP_MCP_CAME_INI_KEY_3_reg                                               0xB8015148
#define  CP_MCP_CAME_INI_KEY_3_inst_addr                                         "0x0013"
#define  set_CP_MCP_CAME_INI_KEY_3_reg(data)                                     (*((volatile unsigned int*)CP_MCP_CAME_INI_KEY_3_reg)=data)
#define  get_CP_MCP_CAME_INI_KEY_3_reg                                           (*((volatile unsigned int*)CP_MCP_CAME_INI_KEY_3_reg))
#define  CP_MCP_CAME_INI_KEY_3_data_shift                                        (0)
#define  CP_MCP_CAME_INI_KEY_3_data_mask                                         (0xFFFFFFFF)
#define  CP_MCP_CAME_INI_KEY_3_data(data)                                        (0xFFFFFFFF&(data))
#define  CP_MCP_CAME_INI_KEY_3_get_data(data)                                    (0xFFFFFFFF&(data))

#define  CP_MCP_MULTI2_SYS_KEY_0                                                 0x18015178
#define  CP_MCP_MULTI2_SYS_KEY_0_reg_addr                                        "0xB8015178"
#define  CP_MCP_MULTI2_SYS_KEY_0_reg                                             0xB8015178
#define  CP_MCP_MULTI2_SYS_KEY_0_inst_addr                                       "0x0014"
#define  set_CP_MCP_MULTI2_SYS_KEY_0_reg(data)                                   (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_0_reg)=data)
#define  get_CP_MCP_MULTI2_SYS_KEY_0_reg                                         (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_0_reg))
#define  CP_MCP_MULTI2_SYS_KEY_0_data_shift                                      (0)
#define  CP_MCP_MULTI2_SYS_KEY_0_data_mask                                       (0xFFFFFFFF)
#define  CP_MCP_MULTI2_SYS_KEY_0_data(data)                                      (0xFFFFFFFF&(data))
#define  CP_MCP_MULTI2_SYS_KEY_0_get_data(data)                                  (0xFFFFFFFF&(data))

#define  CP_MCP_MULTI2_SYS_KEY_1                                                 0x1801517C
#define  CP_MCP_MULTI2_SYS_KEY_1_reg_addr                                        "0xB801517C"
#define  CP_MCP_MULTI2_SYS_KEY_1_reg                                             0xB801517C
#define  CP_MCP_MULTI2_SYS_KEY_1_inst_addr                                       "0x0015"
#define  set_CP_MCP_MULTI2_SYS_KEY_1_reg(data)                                   (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_1_reg)=data)
#define  get_CP_MCP_MULTI2_SYS_KEY_1_reg                                         (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_1_reg))
#define  CP_MCP_MULTI2_SYS_KEY_1_data_shift                                      (0)
#define  CP_MCP_MULTI2_SYS_KEY_1_data_mask                                       (0xFFFFFFFF)
#define  CP_MCP_MULTI2_SYS_KEY_1_data(data)                                      (0xFFFFFFFF&(data))
#define  CP_MCP_MULTI2_SYS_KEY_1_get_data(data)                                  (0xFFFFFFFF&(data))

#define  CP_MCP_MULTI2_SYS_KEY_2                                                 0x18015180
#define  CP_MCP_MULTI2_SYS_KEY_2_reg_addr                                        "0xB8015180"
#define  CP_MCP_MULTI2_SYS_KEY_2_reg                                             0xB8015180
#define  CP_MCP_MULTI2_SYS_KEY_2_inst_addr                                       "0x0016"
#define  set_CP_MCP_MULTI2_SYS_KEY_2_reg(data)                                   (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_2_reg)=data)
#define  get_CP_MCP_MULTI2_SYS_KEY_2_reg                                         (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_2_reg))
#define  CP_MCP_MULTI2_SYS_KEY_2_data_shift                                      (0)
#define  CP_MCP_MULTI2_SYS_KEY_2_data_mask                                       (0xFFFFFFFF)
#define  CP_MCP_MULTI2_SYS_KEY_2_data(data)                                      (0xFFFFFFFF&(data))
#define  CP_MCP_MULTI2_SYS_KEY_2_get_data(data)                                  (0xFFFFFFFF&(data))

#define  CP_MCP_MULTI2_SYS_KEY_3                                                 0x18015184
#define  CP_MCP_MULTI2_SYS_KEY_3_reg_addr                                        "0xB8015184"
#define  CP_MCP_MULTI2_SYS_KEY_3_reg                                             0xB8015184
#define  CP_MCP_MULTI2_SYS_KEY_3_inst_addr                                       "0x0017"
#define  set_CP_MCP_MULTI2_SYS_KEY_3_reg(data)                                   (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_3_reg)=data)
#define  get_CP_MCP_MULTI2_SYS_KEY_3_reg                                         (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_3_reg))
#define  CP_MCP_MULTI2_SYS_KEY_3_data_shift                                      (0)
#define  CP_MCP_MULTI2_SYS_KEY_3_data_mask                                       (0xFFFFFFFF)
#define  CP_MCP_MULTI2_SYS_KEY_3_data(data)                                      (0xFFFFFFFF&(data))
#define  CP_MCP_MULTI2_SYS_KEY_3_get_data(data)                                  (0xFFFFFFFF&(data))

#define  CP_MCP_MULTI2_SYS_KEY_4                                                 0x18015188
#define  CP_MCP_MULTI2_SYS_KEY_4_reg_addr                                        "0xB8015188"
#define  CP_MCP_MULTI2_SYS_KEY_4_reg                                             0xB8015188
#define  CP_MCP_MULTI2_SYS_KEY_4_inst_addr                                       "0x0018"
#define  set_CP_MCP_MULTI2_SYS_KEY_4_reg(data)                                   (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_4_reg)=data)
#define  get_CP_MCP_MULTI2_SYS_KEY_4_reg                                         (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_4_reg))
#define  CP_MCP_MULTI2_SYS_KEY_4_data_shift                                      (0)
#define  CP_MCP_MULTI2_SYS_KEY_4_data_mask                                       (0xFFFFFFFF)
#define  CP_MCP_MULTI2_SYS_KEY_4_data(data)                                      (0xFFFFFFFF&(data))
#define  CP_MCP_MULTI2_SYS_KEY_4_get_data(data)                                  (0xFFFFFFFF&(data))

#define  CP_MCP_MULTI2_SYS_KEY_5                                                 0x1801518C
#define  CP_MCP_MULTI2_SYS_KEY_5_reg_addr                                        "0xB801518C"
#define  CP_MCP_MULTI2_SYS_KEY_5_reg                                             0xB801518C
#define  CP_MCP_MULTI2_SYS_KEY_5_inst_addr                                       "0x0019"
#define  set_CP_MCP_MULTI2_SYS_KEY_5_reg(data)                                   (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_5_reg)=data)
#define  get_CP_MCP_MULTI2_SYS_KEY_5_reg                                         (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_5_reg))
#define  CP_MCP_MULTI2_SYS_KEY_5_data_shift                                      (0)
#define  CP_MCP_MULTI2_SYS_KEY_5_data_mask                                       (0xFFFFFFFF)
#define  CP_MCP_MULTI2_SYS_KEY_5_data(data)                                      (0xFFFFFFFF&(data))
#define  CP_MCP_MULTI2_SYS_KEY_5_get_data(data)                                  (0xFFFFFFFF&(data))

#define  CP_MCP_MULTI2_SYS_KEY_6                                                 0x18015190
#define  CP_MCP_MULTI2_SYS_KEY_6_reg_addr                                        "0xB8015190"
#define  CP_MCP_MULTI2_SYS_KEY_6_reg                                             0xB8015190
#define  CP_MCP_MULTI2_SYS_KEY_6_inst_addr                                       "0x001A"
#define  set_CP_MCP_MULTI2_SYS_KEY_6_reg(data)                                   (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_6_reg)=data)
#define  get_CP_MCP_MULTI2_SYS_KEY_6_reg                                         (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_6_reg))
#define  CP_MCP_MULTI2_SYS_KEY_6_data_shift                                      (0)
#define  CP_MCP_MULTI2_SYS_KEY_6_data_mask                                       (0xFFFFFFFF)
#define  CP_MCP_MULTI2_SYS_KEY_6_data(data)                                      (0xFFFFFFFF&(data))
#define  CP_MCP_MULTI2_SYS_KEY_6_get_data(data)                                  (0xFFFFFFFF&(data))

#define  CP_MCP_MULTI2_SYS_KEY_7                                                 0x18015194
#define  CP_MCP_MULTI2_SYS_KEY_7_reg_addr                                        "0xB8015194"
#define  CP_MCP_MULTI2_SYS_KEY_7_reg                                             0xB8015194
#define  CP_MCP_MULTI2_SYS_KEY_7_inst_addr                                       "0x001B"
#define  set_CP_MCP_MULTI2_SYS_KEY_7_reg(data)                                   (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_7_reg)=data)
#define  get_CP_MCP_MULTI2_SYS_KEY_7_reg                                         (*((volatile unsigned int*)CP_MCP_MULTI2_SYS_KEY_7_reg))
#define  CP_MCP_MULTI2_SYS_KEY_7_data_shift                                      (0)
#define  CP_MCP_MULTI2_SYS_KEY_7_data_mask                                       (0xFFFFFFFF)
#define  CP_MCP_MULTI2_SYS_KEY_7_data(data)                                      (0xFFFFFFFF&(data))
#define  CP_MCP_MULTI2_SYS_KEY_7_get_data(data)                                  (0xFFFFFFFF&(data))

#define  CP_CP_OTP_LOAD                                                          0x1801519C
#define  CP_CP_OTP_LOAD_reg_addr                                                 "0xB801519C"
#define  CP_CP_OTP_LOAD_reg                                                      0xB801519C
#define  CP_CP_OTP_LOAD_inst_addr                                                "0x001C"
#define  set_CP_CP_OTP_LOAD_reg(data)                                            (*((volatile unsigned int*)CP_CP_OTP_LOAD_reg)=data)
#define  get_CP_CP_OTP_LOAD_reg                                                  (*((volatile unsigned int*)CP_CP_OTP_LOAD_reg))
#define  CP_CP_OTP_LOAD_otp_load_shift                                           (0)
#define  CP_CP_OTP_LOAD_otp_load_mask                                            (0x00000001)
#define  CP_CP_OTP_LOAD_otp_load(data)                                           (0x00000001&(data))
#define  CP_CP_OTP_LOAD_get_otp_load(data)                                       (0x00000001&(data))

#define  CP_K_MCP_CTRL                                                           0x18015900
#define  CP_K_MCP_CTRL_reg_addr                                                  "0xB8015900"
#define  CP_K_MCP_CTRL_reg                                                       0xB8015900
#define  CP_K_MCP_CTRL_inst_addr                                                 "0x001D"
#define  set_CP_K_MCP_CTRL_reg(data)                                             (*((volatile unsigned int*)CP_K_MCP_CTRL_reg)=data)
#define  get_CP_K_MCP_CTRL_reg                                                   (*((volatile unsigned int*)CP_K_MCP_CTRL_reg))
#define  CP_K_MCP_CTRL_clear_shift                                               (4)
#define  CP_K_MCP_CTRL_swap_shift                                                (3)
#define  CP_K_MCP_CTRL_idle_shift                                                (2)
#define  CP_K_MCP_CTRL_go_shift                                                  (1)
#define  CP_K_MCP_CTRL_write_data_shift                                          (0)
#define  CP_K_MCP_CTRL_clear_mask                                                (0x00000010)
#define  CP_K_MCP_CTRL_swap_mask                                                 (0x00000008)
#define  CP_K_MCP_CTRL_idle_mask                                                 (0x00000004)
#define  CP_K_MCP_CTRL_go_mask                                                   (0x00000002)
#define  CP_K_MCP_CTRL_write_data_mask                                           (0x00000001)
#define  CP_K_MCP_CTRL_clear(data)                                               (0x00000010&((data)<<4))
#define  CP_K_MCP_CTRL_swap(data)                                                (0x00000008&((data)<<3))
#define  CP_K_MCP_CTRL_idle(data)                                                (0x00000004&((data)<<2))
#define  CP_K_MCP_CTRL_go(data)                                                  (0x00000002&((data)<<1))
#define  CP_K_MCP_CTRL_write_data(data)                                          (0x00000001&(data))
#define  CP_K_MCP_CTRL_get_clear(data)                                           ((0x00000010&(data))>>4)
#define  CP_K_MCP_CTRL_get_swap(data)                                            ((0x00000008&(data))>>3)
#define  CP_K_MCP_CTRL_get_idle(data)                                            ((0x00000004&(data))>>2)
#define  CP_K_MCP_CTRL_get_go(data)                                              ((0x00000002&(data))>>1)
#define  CP_K_MCP_CTRL_get_write_data(data)                                      (0x00000001&(data))

#define  CP_K_MCP_STATUS                                                         0x18015904
#define  CP_K_MCP_STATUS_reg_addr                                                "0xB8015904"
#define  CP_K_MCP_STATUS_reg                                                     0xB8015904
#define  CP_K_MCP_STATUS_inst_addr                                               "0x001E"
#define  set_CP_K_MCP_STATUS_reg(data)                                           (*((volatile unsigned int*)CP_K_MCP_STATUS_reg)=data)
#define  get_CP_K_MCP_STATUS_reg                                                 (*((volatile unsigned int*)CP_K_MCP_STATUS_reg))
#define  CP_K_MCP_STATUS_s_error_shift                                           (9)
#define  CP_K_MCP_STATUS_s_compare_shift                                         (8)
#define  CP_K_MCP_STATUS_s_ring_empty_shift                                      (7)
#define  CP_K_MCP_STATUS_compare_shift                                           (3)
#define  CP_K_MCP_STATUS_error_shift                                             (2)
#define  CP_K_MCP_STATUS_ring_empty_shift                                        (1)
#define  CP_K_MCP_STATUS_write_data_shift                                        (0)
#define  CP_K_MCP_STATUS_s_error_mask                                            (0x00000200)
#define  CP_K_MCP_STATUS_s_compare_mask                                          (0x00000100)
#define  CP_K_MCP_STATUS_s_ring_empty_mask                                       (0x00000080)
#define  CP_K_MCP_STATUS_compare_mask                                            (0x00000008)
#define  CP_K_MCP_STATUS_error_mask                                              (0x00000004)
#define  CP_K_MCP_STATUS_ring_empty_mask                                         (0x00000002)
#define  CP_K_MCP_STATUS_write_data_mask                                         (0x00000001)
#define  CP_K_MCP_STATUS_s_error(data)                                           (0x00000200&((data)<<9))
#define  CP_K_MCP_STATUS_s_compare(data)                                         (0x00000100&((data)<<8))
#define  CP_K_MCP_STATUS_s_ring_empty(data)                                      (0x00000080&((data)<<7))
#define  CP_K_MCP_STATUS_compare(data)                                           (0x00000008&((data)<<3))
#define  CP_K_MCP_STATUS_error(data)                                             (0x00000004&((data)<<2))
#define  CP_K_MCP_STATUS_ring_empty(data)                                        (0x00000002&((data)<<1))
#define  CP_K_MCP_STATUS_write_data(data)                                        (0x00000001&(data))
#define  CP_K_MCP_STATUS_get_s_error(data)                                       ((0x00000200&(data))>>9)
#define  CP_K_MCP_STATUS_get_s_compare(data)                                     ((0x00000100&(data))>>8)
#define  CP_K_MCP_STATUS_get_s_ring_empty(data)                                  ((0x00000080&(data))>>7)
#define  CP_K_MCP_STATUS_get_compare(data)                                       ((0x00000008&(data))>>3)
#define  CP_K_MCP_STATUS_get_error(data)                                         ((0x00000004&(data))>>2)
#define  CP_K_MCP_STATUS_get_ring_empty(data)                                    ((0x00000002&(data))>>1)
#define  CP_K_MCP_STATUS_get_write_data(data)                                    (0x00000001&(data))

#define  CP_K_MCP_EN                                                             0x18015908
#define  CP_K_MCP_EN_reg_addr                                                    "0xB8015908"
#define  CP_K_MCP_EN_reg                                                         0xB8015908
#define  CP_K_MCP_EN_inst_addr                                                   "0x001F"
#define  set_CP_K_MCP_EN_reg(data)                                               (*((volatile unsigned int*)CP_K_MCP_EN_reg)=data)
#define  get_CP_K_MCP_EN_reg                                                     (*((volatile unsigned int*)CP_K_MCP_EN_reg))
#define  CP_K_MCP_EN_compare_en_shift                                            (3)
#define  CP_K_MCP_EN_error_en_shift                                              (2)
#define  CP_K_MCP_EN_ring_empty_en_shift                                         (1)
#define  CP_K_MCP_EN_write_data_shift                                            (0)
#define  CP_K_MCP_EN_compare_en_mask                                             (0x00000008)
#define  CP_K_MCP_EN_error_en_mask                                               (0x00000004)
#define  CP_K_MCP_EN_ring_empty_en_mask                                          (0x00000002)
#define  CP_K_MCP_EN_write_data_mask                                             (0x00000001)
#define  CP_K_MCP_EN_compare_en(data)                                            (0x00000008&((data)<<3))
#define  CP_K_MCP_EN_error_en(data)                                              (0x00000004&((data)<<2))
#define  CP_K_MCP_EN_ring_empty_en(data)                                         (0x00000002&((data)<<1))
#define  CP_K_MCP_EN_write_data(data)                                            (0x00000001&(data))
#define  CP_K_MCP_EN_get_compare_en(data)                                        ((0x00000008&(data))>>3)
#define  CP_K_MCP_EN_get_error_en(data)                                          ((0x00000004&(data))>>2)
#define  CP_K_MCP_EN_get_ring_empty_en(data)                                     ((0x00000002&(data))>>1)
#define  CP_K_MCP_EN_get_write_data(data)                                        (0x00000001&(data))

#define  CP_K_MCP_CTRL1                                                          0x18015998
#define  CP_K_MCP_CTRL1_reg_addr                                                 "0xB8015998"
#define  CP_K_MCP_CTRL1_reg                                                      0xB8015998
#define  CP_K_MCP_CTRL1_inst_addr                                                "0x0020"
#define  set_CP_K_MCP_CTRL1_reg(data)                                            (*((volatile unsigned int*)CP_K_MCP_CTRL1_reg)=data)
#define  get_CP_K_MCP_CTRL1_reg                                                  (*((volatile unsigned int*)CP_K_MCP_CTRL1_reg))
#define  CP_K_MCP_CTRL1_aesh_pad_off_shift                                       (10)
#define  CP_K_MCP_CTRL1_csa_entropy_shift                                        (8)
#define  CP_K_MCP_CTRL1_mcp_round_no_shift                                       (0)
#define  CP_K_MCP_CTRL1_aesh_pad_off_mask                                        (0x00000400)
#define  CP_K_MCP_CTRL1_csa_entropy_mask                                         (0x00000300)
#define  CP_K_MCP_CTRL1_mcp_round_no_mask                                        (0x000000FF)
#define  CP_K_MCP_CTRL1_aesh_pad_off(data)                                       (0x00000400&((data)<<10))
#define  CP_K_MCP_CTRL1_csa_entropy(data)                                        (0x00000300&((data)<<8))
#define  CP_K_MCP_CTRL1_mcp_round_no(data)                                       (0x000000FF&(data))
#define  CP_K_MCP_CTRL1_get_aesh_pad_off(data)                                   ((0x00000400&(data))>>10)
#define  CP_K_MCP_CTRL1_get_csa_entropy(data)                                    ((0x00000300&(data))>>8)
#define  CP_K_MCP_CTRL1_get_mcp_round_no(data)                                   (0x000000FF&(data))

#define  CP_K_MCP_BASE                                                           0x1801590C
#define  CP_K_MCP_BASE_reg_addr                                                  "0xB801590C"
#define  CP_K_MCP_BASE_reg                                                       0xB801590C
#define  CP_K_MCP_BASE_inst_addr                                                 "0x0021"
#define  set_CP_K_MCP_BASE_reg(data)                                             (*((volatile unsigned int*)CP_K_MCP_BASE_reg)=data)
#define  get_CP_K_MCP_BASE_reg                                                   (*((volatile unsigned int*)CP_K_MCP_BASE_reg))
#define  CP_K_MCP_BASE_base_shift                                                (0)
#define  CP_K_MCP_BASE_base_mask                                                 (0xFFFFFFFF)
#define  CP_K_MCP_BASE_base(data)                                                (0xFFFFFFFF&(data))
#define  CP_K_MCP_BASE_get_base(data)                                            (0xFFFFFFFF&(data))

#define  CP_K_MCP_LIMIT                                                          0x18015910
#define  CP_K_MCP_LIMIT_reg_addr                                                 "0xB8015910"
#define  CP_K_MCP_LIMIT_reg                                                      0xB8015910
#define  CP_K_MCP_LIMIT_inst_addr                                                "0x0022"
#define  set_CP_K_MCP_LIMIT_reg(data)                                            (*((volatile unsigned int*)CP_K_MCP_LIMIT_reg)=data)
#define  get_CP_K_MCP_LIMIT_reg                                                  (*((volatile unsigned int*)CP_K_MCP_LIMIT_reg))
#define  CP_K_MCP_LIMIT_limit_shift                                              (0)
#define  CP_K_MCP_LIMIT_limit_mask                                               (0xFFFFFFFF)
#define  CP_K_MCP_LIMIT_limit(data)                                              (0xFFFFFFFF&(data))
#define  CP_K_MCP_LIMIT_get_limit(data)                                          (0xFFFFFFFF&(data))

#define  CP_K_MCP_RDPTR                                                          0x18015914
#define  CP_K_MCP_RDPTR_reg_addr                                                 "0xB8015914"
#define  CP_K_MCP_RDPTR_reg                                                      0xB8015914
#define  CP_K_MCP_RDPTR_inst_addr                                                "0x0023"
#define  set_CP_K_MCP_RDPTR_reg(data)                                            (*((volatile unsigned int*)CP_K_MCP_RDPTR_reg)=data)
#define  get_CP_K_MCP_RDPTR_reg                                                  (*((volatile unsigned int*)CP_K_MCP_RDPTR_reg))
#define  CP_K_MCP_RDPTR_rdptr_shift                                              (0)
#define  CP_K_MCP_RDPTR_rdptr_mask                                               (0xFFFFFFFF)
#define  CP_K_MCP_RDPTR_rdptr(data)                                              (0xFFFFFFFF&(data))
#define  CP_K_MCP_RDPTR_get_rdptr(data)                                          (0xFFFFFFFF&(data))

#define  CP_K_MCP_WRPTR                                                          0x18015918
#define  CP_K_MCP_WRPTR_reg_addr                                                 "0xB8015918"
#define  CP_K_MCP_WRPTR_reg                                                      0xB8015918
#define  CP_K_MCP_WRPTR_inst_addr                                                "0x0024"
#define  set_CP_K_MCP_WRPTR_reg(data)                                            (*((volatile unsigned int*)CP_K_MCP_WRPTR_reg)=data)
#define  get_CP_K_MCP_WRPTR_reg                                                  (*((volatile unsigned int*)CP_K_MCP_WRPTR_reg))
#define  CP_K_MCP_WRPTR_wrptr_shift                                              (0)
#define  CP_K_MCP_WRPTR_wrptr_mask                                               (0xFFFFFFFF)
#define  CP_K_MCP_WRPTR_wrptr(data)                                              (0xFFFFFFFF&(data))
#define  CP_K_MCP_WRPTR_get_wrptr(data)                                          (0xFFFFFFFF&(data))

#define  CP_K_MCP_DES_COUNT                                                      0x18015934
#define  CP_K_MCP_DES_COUNT_reg_addr                                             "0xB8015934"
#define  CP_K_MCP_DES_COUNT_reg                                                  0xB8015934
#define  CP_K_MCP_DES_COUNT_inst_addr                                            "0x0025"
#define  set_CP_K_MCP_DES_COUNT_reg(data)                                        (*((volatile unsigned int*)CP_K_MCP_DES_COUNT_reg)=data)
#define  get_CP_K_MCP_DES_COUNT_reg                                              (*((volatile unsigned int*)CP_K_MCP_DES_COUNT_reg))
#define  CP_K_MCP_DES_COUNT_count_shift                                          (0)
#define  CP_K_MCP_DES_COUNT_count_mask                                           (0x0000FFFF)
#define  CP_K_MCP_DES_COUNT_count(data)                                          (0x0000FFFF&(data))
#define  CP_K_MCP_DES_COUNT_get_count(data)                                      (0x0000FFFF&(data))

#define  CP_K_MCP_DES_COMPARE                                                    0x18015938
#define  CP_K_MCP_DES_COMPARE_reg_addr                                           "0xB8015938"
#define  CP_K_MCP_DES_COMPARE_reg                                                0xB8015938
#define  CP_K_MCP_DES_COMPARE_inst_addr                                          "0x0026"
#define  set_CP_K_MCP_DES_COMPARE_reg(data)                                      (*((volatile unsigned int*)CP_K_MCP_DES_COMPARE_reg)=data)
#define  get_CP_K_MCP_DES_COMPARE_reg                                            (*((volatile unsigned int*)CP_K_MCP_DES_COMPARE_reg))
#define  CP_K_MCP_DES_COMPARE_compare_shift                                      (0)
#define  CP_K_MCP_DES_COMPARE_compare_mask                                       (0x0000FFFF)
#define  CP_K_MCP_DES_COMPARE_compare(data)                                      (0x0000FFFF&(data))
#define  CP_K_MCP_DES_COMPARE_get_compare(data)                                  (0x0000FFFF&(data))

#define  CP_K_MCP_DES_INI_KEY_0                                                  0x1801591C
#define  CP_K_MCP_DES_INI_KEY_0_reg_addr                                         "0xB801591C"
#define  CP_K_MCP_DES_INI_KEY_0_reg                                              0xB801591C
#define  CP_K_MCP_DES_INI_KEY_0_inst_addr                                        "0x0027"
#define  set_CP_K_MCP_DES_INI_KEY_0_reg(data)                                    (*((volatile unsigned int*)CP_K_MCP_DES_INI_KEY_0_reg)=data)
#define  get_CP_K_MCP_DES_INI_KEY_0_reg                                          (*((volatile unsigned int*)CP_K_MCP_DES_INI_KEY_0_reg))
#define  CP_K_MCP_DES_INI_KEY_0_data_shift                                       (0)
#define  CP_K_MCP_DES_INI_KEY_0_data_mask                                        (0xFFFFFFFF)
#define  CP_K_MCP_DES_INI_KEY_0_data(data)                                       (0xFFFFFFFF&(data))
#define  CP_K_MCP_DES_INI_KEY_0_get_data(data)                                   (0xFFFFFFFF&(data))

#define  CP_K_MCP_DES_INI_KEY_1                                                  0x18015920
#define  CP_K_MCP_DES_INI_KEY_1_reg_addr                                         "0xB8015920"
#define  CP_K_MCP_DES_INI_KEY_1_reg                                              0xB8015920
#define  CP_K_MCP_DES_INI_KEY_1_inst_addr                                        "0x0028"
#define  set_CP_K_MCP_DES_INI_KEY_1_reg(data)                                    (*((volatile unsigned int*)CP_K_MCP_DES_INI_KEY_1_reg)=data)
#define  get_CP_K_MCP_DES_INI_KEY_1_reg                                          (*((volatile unsigned int*)CP_K_MCP_DES_INI_KEY_1_reg))
#define  CP_K_MCP_DES_INI_KEY_1_data_shift                                       (0)
#define  CP_K_MCP_DES_INI_KEY_1_data_mask                                        (0xFFFFFFFF)
#define  CP_K_MCP_DES_INI_KEY_1_data(data)                                       (0xFFFFFFFF&(data))
#define  CP_K_MCP_DES_INI_KEY_1_get_data(data)                                   (0xFFFFFFFF&(data))

#define  CP_K_MCP_AES_INI_KEY_0                                                  0x18015924
#define  CP_K_MCP_AES_INI_KEY_0_reg_addr                                         "0xB8015924"
#define  CP_K_MCP_AES_INI_KEY_0_reg                                              0xB8015924
#define  CP_K_MCP_AES_INI_KEY_0_inst_addr                                        "0x0029"
#define  set_CP_K_MCP_AES_INI_KEY_0_reg(data)                                    (*((volatile unsigned int*)CP_K_MCP_AES_INI_KEY_0_reg)=data)
#define  get_CP_K_MCP_AES_INI_KEY_0_reg                                          (*((volatile unsigned int*)CP_K_MCP_AES_INI_KEY_0_reg))
#define  CP_K_MCP_AES_INI_KEY_0_data_shift                                       (0)
#define  CP_K_MCP_AES_INI_KEY_0_data_mask                                        (0xFFFFFFFF)
#define  CP_K_MCP_AES_INI_KEY_0_data(data)                                       (0xFFFFFFFF&(data))
#define  CP_K_MCP_AES_INI_KEY_0_get_data(data)                                   (0xFFFFFFFF&(data))

#define  CP_K_MCP_AES_INI_KEY_1                                                  0x18015928
#define  CP_K_MCP_AES_INI_KEY_1_reg_addr                                         "0xB8015928"
#define  CP_K_MCP_AES_INI_KEY_1_reg                                              0xB8015928
#define  CP_K_MCP_AES_INI_KEY_1_inst_addr                                        "0x002A"
#define  set_CP_K_MCP_AES_INI_KEY_1_reg(data)                                    (*((volatile unsigned int*)CP_K_MCP_AES_INI_KEY_1_reg)=data)
#define  get_CP_K_MCP_AES_INI_KEY_1_reg                                          (*((volatile unsigned int*)CP_K_MCP_AES_INI_KEY_1_reg))
#define  CP_K_MCP_AES_INI_KEY_1_data_shift                                       (0)
#define  CP_K_MCP_AES_INI_KEY_1_data_mask                                        (0xFFFFFFFF)
#define  CP_K_MCP_AES_INI_KEY_1_data(data)                                       (0xFFFFFFFF&(data))
#define  CP_K_MCP_AES_INI_KEY_1_get_data(data)                                   (0xFFFFFFFF&(data))

#define  CP_K_MCP_AES_INI_KEY_2                                                  0x1801592C
#define  CP_K_MCP_AES_INI_KEY_2_reg_addr                                         "0xB801592C"
#define  CP_K_MCP_AES_INI_KEY_2_reg                                              0xB801592C
#define  CP_K_MCP_AES_INI_KEY_2_inst_addr                                        "0x002B"
#define  set_CP_K_MCP_AES_INI_KEY_2_reg(data)                                    (*((volatile unsigned int*)CP_K_MCP_AES_INI_KEY_2_reg)=data)
#define  get_CP_K_MCP_AES_INI_KEY_2_reg                                          (*((volatile unsigned int*)CP_K_MCP_AES_INI_KEY_2_reg))
#define  CP_K_MCP_AES_INI_KEY_2_data_shift                                       (0)
#define  CP_K_MCP_AES_INI_KEY_2_data_mask                                        (0xFFFFFFFF)
#define  CP_K_MCP_AES_INI_KEY_2_data(data)                                       (0xFFFFFFFF&(data))
#define  CP_K_MCP_AES_INI_KEY_2_get_data(data)                                   (0xFFFFFFFF&(data))

#define  CP_K_MCP_AES_INI_KEY_3                                                  0x18015930
#define  CP_K_MCP_AES_INI_KEY_3_reg_addr                                         "0xB8015930"
#define  CP_K_MCP_AES_INI_KEY_3_reg                                              0xB8015930
#define  CP_K_MCP_AES_INI_KEY_3_inst_addr                                        "0x002C"
#define  set_CP_K_MCP_AES_INI_KEY_3_reg(data)                                    (*((volatile unsigned int*)CP_K_MCP_AES_INI_KEY_3_reg)=data)
#define  get_CP_K_MCP_AES_INI_KEY_3_reg                                          (*((volatile unsigned int*)CP_K_MCP_AES_INI_KEY_3_reg))
#define  CP_K_MCP_AES_INI_KEY_3_data_shift                                       (0)
#define  CP_K_MCP_AES_INI_KEY_3_data_mask                                        (0xFFFFFFFF)
#define  CP_K_MCP_AES_INI_KEY_3_data(data)                                       (0xFFFFFFFF&(data))
#define  CP_K_MCP_AES_INI_KEY_3_get_data(data)                                   (0xFFFFFFFF&(data))

#define  CP_K_MCP_CAME_INI_KEY_0                                                 0x1801593C
#define  CP_K_MCP_CAME_INI_KEY_0_reg_addr                                        "0xB801593C"
#define  CP_K_MCP_CAME_INI_KEY_0_reg                                             0xB801593C
#define  CP_K_MCP_CAME_INI_KEY_0_inst_addr                                       "0x002D"
#define  set_CP_K_MCP_CAME_INI_KEY_0_reg(data)                                   (*((volatile unsigned int*)CP_K_MCP_CAME_INI_KEY_0_reg)=data)
#define  get_CP_K_MCP_CAME_INI_KEY_0_reg                                         (*((volatile unsigned int*)CP_K_MCP_CAME_INI_KEY_0_reg))
#define  CP_K_MCP_CAME_INI_KEY_0_data_shift                                      (0)
#define  CP_K_MCP_CAME_INI_KEY_0_data_mask                                       (0xFFFFFFFF)
#define  CP_K_MCP_CAME_INI_KEY_0_data(data)                                      (0xFFFFFFFF&(data))
#define  CP_K_MCP_CAME_INI_KEY_0_get_data(data)                                  (0xFFFFFFFF&(data))

#define  CP_K_MCP_CAME_INI_KEY_1                                                 0x18015940
#define  CP_K_MCP_CAME_INI_KEY_1_reg_addr                                        "0xB8015940"
#define  CP_K_MCP_CAME_INI_KEY_1_reg                                             0xB8015940
#define  CP_K_MCP_CAME_INI_KEY_1_inst_addr                                       "0x002E"
#define  set_CP_K_MCP_CAME_INI_KEY_1_reg(data)                                   (*((volatile unsigned int*)CP_K_MCP_CAME_INI_KEY_1_reg)=data)
#define  get_CP_K_MCP_CAME_INI_KEY_1_reg                                         (*((volatile unsigned int*)CP_K_MCP_CAME_INI_KEY_1_reg))
#define  CP_K_MCP_CAME_INI_KEY_1_data_shift                                      (0)
#define  CP_K_MCP_CAME_INI_KEY_1_data_mask                                       (0xFFFFFFFF)
#define  CP_K_MCP_CAME_INI_KEY_1_data(data)                                      (0xFFFFFFFF&(data))
#define  CP_K_MCP_CAME_INI_KEY_1_get_data(data)                                  (0xFFFFFFFF&(data))

#define  CP_K_MCP_CAME_INI_KEY_2                                                 0x18015944
#define  CP_K_MCP_CAME_INI_KEY_2_reg_addr                                        "0xB8015944"
#define  CP_K_MCP_CAME_INI_KEY_2_reg                                             0xB8015944
#define  CP_K_MCP_CAME_INI_KEY_2_inst_addr                                       "0x002F"
#define  set_CP_K_MCP_CAME_INI_KEY_2_reg(data)                                   (*((volatile unsigned int*)CP_K_MCP_CAME_INI_KEY_2_reg)=data)
#define  get_CP_K_MCP_CAME_INI_KEY_2_reg                                         (*((volatile unsigned int*)CP_K_MCP_CAME_INI_KEY_2_reg))
#define  CP_K_MCP_CAME_INI_KEY_2_data_shift                                      (0)
#define  CP_K_MCP_CAME_INI_KEY_2_data_mask                                       (0xFFFFFFFF)
#define  CP_K_MCP_CAME_INI_KEY_2_data(data)                                      (0xFFFFFFFF&(data))
#define  CP_K_MCP_CAME_INI_KEY_2_get_data(data)                                  (0xFFFFFFFF&(data))

#define  CP_K_MCP_CAME_INI_KEY_3                                                 0x18015948
#define  CP_K_MCP_CAME_INI_KEY_3_reg_addr                                        "0xB8015948"
#define  CP_K_MCP_CAME_INI_KEY_3_reg                                             0xB8015948
#define  CP_K_MCP_CAME_INI_KEY_3_inst_addr                                       "0x0030"
#define  set_CP_K_MCP_CAME_INI_KEY_3_reg(data)                                   (*((volatile unsigned int*)CP_K_MCP_CAME_INI_KEY_3_reg)=data)
#define  get_CP_K_MCP_CAME_INI_KEY_3_reg                                         (*((volatile unsigned int*)CP_K_MCP_CAME_INI_KEY_3_reg))
#define  CP_K_MCP_CAME_INI_KEY_3_data_shift                                      (0)
#define  CP_K_MCP_CAME_INI_KEY_3_data_mask                                       (0xFFFFFFFF)
#define  CP_K_MCP_CAME_INI_KEY_3_data(data)                                      (0xFFFFFFFF&(data))
#define  CP_K_MCP_CAME_INI_KEY_3_get_data(data)                                  (0xFFFFFFFF&(data))

#define  CP_K_MCP_MULTI2_SYS_KEY_0                                               0x18015978
#define  CP_K_MCP_MULTI2_SYS_KEY_0_reg_addr                                      "0xB8015978"
#define  CP_K_MCP_MULTI2_SYS_KEY_0_reg                                           0xB8015978
#define  CP_K_MCP_MULTI2_SYS_KEY_0_inst_addr                                     "0x0031"
#define  set_CP_K_MCP_MULTI2_SYS_KEY_0_reg(data)                                 (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_0_reg)=data)
#define  get_CP_K_MCP_MULTI2_SYS_KEY_0_reg                                       (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_0_reg))
#define  CP_K_MCP_MULTI2_SYS_KEY_0_data_shift                                    (0)
#define  CP_K_MCP_MULTI2_SYS_KEY_0_data_mask                                     (0xFFFFFFFF)
#define  CP_K_MCP_MULTI2_SYS_KEY_0_data(data)                                    (0xFFFFFFFF&(data))
#define  CP_K_MCP_MULTI2_SYS_KEY_0_get_data(data)                                (0xFFFFFFFF&(data))

#define  CP_K_MCP_MULTI2_SYS_KEY_1                                               0x1801597C
#define  CP_K_MCP_MULTI2_SYS_KEY_1_reg_addr                                      "0xB801597C"
#define  CP_K_MCP_MULTI2_SYS_KEY_1_reg                                           0xB801597C
#define  CP_K_MCP_MULTI2_SYS_KEY_1_inst_addr                                     "0x0032"
#define  set_CP_K_MCP_MULTI2_SYS_KEY_1_reg(data)                                 (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_1_reg)=data)
#define  get_CP_K_MCP_MULTI2_SYS_KEY_1_reg                                       (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_1_reg))
#define  CP_K_MCP_MULTI2_SYS_KEY_1_data_shift                                    (0)
#define  CP_K_MCP_MULTI2_SYS_KEY_1_data_mask                                     (0xFFFFFFFF)
#define  CP_K_MCP_MULTI2_SYS_KEY_1_data(data)                                    (0xFFFFFFFF&(data))
#define  CP_K_MCP_MULTI2_SYS_KEY_1_get_data(data)                                (0xFFFFFFFF&(data))

#define  CP_K_MCP_MULTI2_SYS_KEY_2                                               0x18015980
#define  CP_K_MCP_MULTI2_SYS_KEY_2_reg_addr                                      "0xB8015980"
#define  CP_K_MCP_MULTI2_SYS_KEY_2_reg                                           0xB8015980
#define  CP_K_MCP_MULTI2_SYS_KEY_2_inst_addr                                     "0x0033"
#define  set_CP_K_MCP_MULTI2_SYS_KEY_2_reg(data)                                 (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_2_reg)=data)
#define  get_CP_K_MCP_MULTI2_SYS_KEY_2_reg                                       (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_2_reg))
#define  CP_K_MCP_MULTI2_SYS_KEY_2_data_shift                                    (0)
#define  CP_K_MCP_MULTI2_SYS_KEY_2_data_mask                                     (0xFFFFFFFF)
#define  CP_K_MCP_MULTI2_SYS_KEY_2_data(data)                                    (0xFFFFFFFF&(data))
#define  CP_K_MCP_MULTI2_SYS_KEY_2_get_data(data)                                (0xFFFFFFFF&(data))

#define  CP_K_MCP_MULTI2_SYS_KEY_3                                               0x18015984
#define  CP_K_MCP_MULTI2_SYS_KEY_3_reg_addr                                      "0xB8015984"
#define  CP_K_MCP_MULTI2_SYS_KEY_3_reg                                           0xB8015984
#define  CP_K_MCP_MULTI2_SYS_KEY_3_inst_addr                                     "0x0034"
#define  set_CP_K_MCP_MULTI2_SYS_KEY_3_reg(data)                                 (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_3_reg)=data)
#define  get_CP_K_MCP_MULTI2_SYS_KEY_3_reg                                       (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_3_reg))
#define  CP_K_MCP_MULTI2_SYS_KEY_3_data_shift                                    (0)
#define  CP_K_MCP_MULTI2_SYS_KEY_3_data_mask                                     (0xFFFFFFFF)
#define  CP_K_MCP_MULTI2_SYS_KEY_3_data(data)                                    (0xFFFFFFFF&(data))
#define  CP_K_MCP_MULTI2_SYS_KEY_3_get_data(data)                                (0xFFFFFFFF&(data))

#define  CP_K_MCP_MULTI2_SYS_KEY_4                                               0x18015988
#define  CP_K_MCP_MULTI2_SYS_KEY_4_reg_addr                                      "0xB8015988"
#define  CP_K_MCP_MULTI2_SYS_KEY_4_reg                                           0xB8015988
#define  CP_K_MCP_MULTI2_SYS_KEY_4_inst_addr                                     "0x0035"
#define  set_CP_K_MCP_MULTI2_SYS_KEY_4_reg(data)                                 (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_4_reg)=data)
#define  get_CP_K_MCP_MULTI2_SYS_KEY_4_reg                                       (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_4_reg))
#define  CP_K_MCP_MULTI2_SYS_KEY_4_data_shift                                    (0)
#define  CP_K_MCP_MULTI2_SYS_KEY_4_data_mask                                     (0xFFFFFFFF)
#define  CP_K_MCP_MULTI2_SYS_KEY_4_data(data)                                    (0xFFFFFFFF&(data))
#define  CP_K_MCP_MULTI2_SYS_KEY_4_get_data(data)                                (0xFFFFFFFF&(data))

#define  CP_K_MCP_MULTI2_SYS_KEY_5                                               0x1801598C
#define  CP_K_MCP_MULTI2_SYS_KEY_5_reg_addr                                      "0xB801598C"
#define  CP_K_MCP_MULTI2_SYS_KEY_5_reg                                           0xB801598C
#define  CP_K_MCP_MULTI2_SYS_KEY_5_inst_addr                                     "0x0036"
#define  set_CP_K_MCP_MULTI2_SYS_KEY_5_reg(data)                                 (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_5_reg)=data)
#define  get_CP_K_MCP_MULTI2_SYS_KEY_5_reg                                       (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_5_reg))
#define  CP_K_MCP_MULTI2_SYS_KEY_5_data_shift                                    (0)
#define  CP_K_MCP_MULTI2_SYS_KEY_5_data_mask                                     (0xFFFFFFFF)
#define  CP_K_MCP_MULTI2_SYS_KEY_5_data(data)                                    (0xFFFFFFFF&(data))
#define  CP_K_MCP_MULTI2_SYS_KEY_5_get_data(data)                                (0xFFFFFFFF&(data))

#define  CP_K_MCP_MULTI2_SYS_KEY_6                                               0x18015990
#define  CP_K_MCP_MULTI2_SYS_KEY_6_reg_addr                                      "0xB8015990"
#define  CP_K_MCP_MULTI2_SYS_KEY_6_reg                                           0xB8015990
#define  CP_K_MCP_MULTI2_SYS_KEY_6_inst_addr                                     "0x0037"
#define  set_CP_K_MCP_MULTI2_SYS_KEY_6_reg(data)                                 (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_6_reg)=data)
#define  get_CP_K_MCP_MULTI2_SYS_KEY_6_reg                                       (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_6_reg))
#define  CP_K_MCP_MULTI2_SYS_KEY_6_data_shift                                    (0)
#define  CP_K_MCP_MULTI2_SYS_KEY_6_data_mask                                     (0xFFFFFFFF)
#define  CP_K_MCP_MULTI2_SYS_KEY_6_data(data)                                    (0xFFFFFFFF&(data))
#define  CP_K_MCP_MULTI2_SYS_KEY_6_get_data(data)                                (0xFFFFFFFF&(data))

#define  CP_K_MCP_MULTI2_SYS_KEY_7                                               0x18015994
#define  CP_K_MCP_MULTI2_SYS_KEY_7_reg_addr                                      "0xB8015994"
#define  CP_K_MCP_MULTI2_SYS_KEY_7_reg                                           0xB8015994
#define  CP_K_MCP_MULTI2_SYS_KEY_7_inst_addr                                     "0x0038"
#define  set_CP_K_MCP_MULTI2_SYS_KEY_7_reg(data)                                 (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_7_reg)=data)
#define  get_CP_K_MCP_MULTI2_SYS_KEY_7_reg                                       (*((volatile unsigned int*)CP_K_MCP_MULTI2_SYS_KEY_7_reg))
#define  CP_K_MCP_MULTI2_SYS_KEY_7_data_shift                                    (0)
#define  CP_K_MCP_MULTI2_SYS_KEY_7_data_mask                                     (0xFFFFFFFF)
#define  CP_K_MCP_MULTI2_SYS_KEY_7_data(data)                                    (0xFFFFFFFF&(data))
#define  CP_K_MCP_MULTI2_SYS_KEY_7_get_data(data)                                (0xFFFFFFFF&(data))

#define  CP_MCP_ST                                                               0x180151A0
#define  CP_MCP_ST_reg_addr                                                      "0xB80151A0"
#define  CP_MCP_ST_reg                                                           0xB80151A0
#define  CP_MCP_ST_inst_addr                                                     "0x0039"
#define  set_CP_MCP_ST_reg(data)                                                 (*((volatile unsigned int*)CP_MCP_ST_reg)=data)
#define  get_CP_MCP_ST_reg                                                       (*((volatile unsigned int*)CP_MCP_ST_reg))
#define  CP_MCP_ST_rd_sm_shift                                                   (24)
#define  CP_MCP_ST_wr_sm_shift                                                   (21)
#define  CP_MCP_ST_mcp_aes_like_sm_shift                                         (0)
#define  CP_MCP_ST_rd_sm_mask                                                    (0x0F000000)
#define  CP_MCP_ST_wr_sm_mask                                                    (0x00E00000)
#define  CP_MCP_ST_mcp_aes_like_sm_mask                                          (0x000007FF)
#define  CP_MCP_ST_rd_sm(data)                                                   (0x0F000000&((data)<<24))
#define  CP_MCP_ST_wr_sm(data)                                                   (0x00E00000&((data)<<21))
#define  CP_MCP_ST_mcp_aes_like_sm(data)                                         (0x000007FF&(data))
#define  CP_MCP_ST_get_rd_sm(data)                                               ((0x0F000000&(data))>>24)
#define  CP_MCP_ST_get_wr_sm(data)                                               ((0x00E00000&(data))>>21)
#define  CP_MCP_ST_get_mcp_aes_like_sm(data)                                     (0x000007FF&(data))

#define  CP_MCP_ST1                                                              0x180151A4
#define  CP_MCP_ST1_reg_addr                                                     "0xB80151A4"
#define  CP_MCP_ST1_reg                                                          0xB80151A4
#define  CP_MCP_ST1_inst_addr                                                    "0x003A"
#define  set_CP_MCP_ST1_reg(data)                                                (*((volatile unsigned int*)CP_MCP_ST1_reg)=data)
#define  get_CP_MCP_ST1_reg                                                      (*((volatile unsigned int*)CP_MCP_ST1_reg))
#define  CP_MCP_ST1_mcp_top_sm_shift                                             (0)
#define  CP_MCP_ST1_mcp_top_sm_mask                                              (0x0003FFFF)
#define  CP_MCP_ST1_mcp_top_sm(data)                                             (0x0003FFFF&(data))
#define  CP_MCP_ST1_get_mcp_top_sm(data)                                         (0x0003FFFF&(data))

#define  CP_CP_PWM_CTRL                                                          0x180151E0
#define  CP_CP_PWM_CTRL_reg_addr                                                 "0xB80151E0"
#define  CP_CP_PWM_CTRL_reg                                                      0xB80151E0
#define  CP_CP_PWM_CTRL_inst_addr                                                "0x003B"
#define  set_CP_CP_PWM_CTRL_reg(data)                                            (*((volatile unsigned int*)CP_CP_PWM_CTRL_reg)=data)
#define  get_CP_CP_PWM_CTRL_reg                                                  (*((volatile unsigned int*)CP_CP_PWM_CTRL_reg))
#define  CP_CP_PWM_CTRL_en_rsa_shift                                             (23)
#define  CP_CP_PWM_CTRL_en_cp_shift                                              (22)
#define  CP_CP_PWM_CTRL_sram_ctr_shift                                           (10)
#define  CP_CP_PWM_CTRL_en_rsa_mask                                              (0x00800000)
#define  CP_CP_PWM_CTRL_en_cp_mask                                               (0x00400000)
#define  CP_CP_PWM_CTRL_sram_ctr_mask                                            (0x00007C00)
#define  CP_CP_PWM_CTRL_en_rsa(data)                                             (0x00800000&((data)<<23))
#define  CP_CP_PWM_CTRL_en_cp(data)                                              (0x00400000&((data)<<22))
#define  CP_CP_PWM_CTRL_sram_ctr(data)                                           (0x00007C00&((data)<<10))
#define  CP_CP_PWM_CTRL_get_en_rsa(data)                                         ((0x00800000&(data))>>23)
#define  CP_CP_PWM_CTRL_get_en_cp(data)                                          ((0x00400000&(data))>>22)
#define  CP_CP_PWM_CTRL_get_sram_ctr(data)                                       ((0x00007C00&(data))>>10)

#define  CP_RCIC_CTRL                                                            0x180159A0
#define  CP_RCIC_CTRL_reg_addr                                                   "0xB80159A0"
#define  CP_RCIC_CTRL_reg                                                        0xB80159A0
#define  CP_RCIC_CTRL_inst_addr                                                  "0x003C"
#define  set_CP_RCIC_CTRL_reg(data)                                              (*((volatile unsigned int*)CP_RCIC_CTRL_reg)=data)
#define  get_CP_RCIC_CTRL_reg                                                    (*((volatile unsigned int*)CP_RCIC_CTRL_reg))
#define  CP_RCIC_CTRL_write_en3_shift                                            (10)
#define  CP_RCIC_CTRL_stop_shift                                                 (9)
#define  CP_RCIC_CTRL_write_en2_shift                                            (8)
#define  CP_RCIC_CTRL_test_mode_shift                                            (6)
#define  CP_RCIC_CTRL_write_en1_shift                                            (5)
#define  CP_RCIC_CTRL_wait_sec_shift                                             (0)
#define  CP_RCIC_CTRL_write_en3_mask                                             (0x00000400)
#define  CP_RCIC_CTRL_stop_mask                                                  (0x00000200)
#define  CP_RCIC_CTRL_write_en2_mask                                             (0x00000100)
#define  CP_RCIC_CTRL_test_mode_mask                                             (0x000000C0)
#define  CP_RCIC_CTRL_write_en1_mask                                             (0x00000020)
#define  CP_RCIC_CTRL_wait_sec_mask                                              (0x0000001F)
#define  CP_RCIC_CTRL_write_en3(data)                                            (0x00000400&((data)<<10))
#define  CP_RCIC_CTRL_stop(data)                                                 (0x00000200&((data)<<9))
#define  CP_RCIC_CTRL_write_en2(data)                                            (0x00000100&((data)<<8))
#define  CP_RCIC_CTRL_test_mode(data)                                            (0x000000C0&((data)<<6))
#define  CP_RCIC_CTRL_write_en1(data)                                            (0x00000020&((data)<<5))
#define  CP_RCIC_CTRL_wait_sec(data)                                             (0x0000001F&(data))
#define  CP_RCIC_CTRL_get_write_en3(data)                                        ((0x00000400&(data))>>10)
#define  CP_RCIC_CTRL_get_stop(data)                                             ((0x00000200&(data))>>9)
#define  CP_RCIC_CTRL_get_write_en2(data)                                        ((0x00000100&(data))>>8)
#define  CP_RCIC_CTRL_get_test_mode(data)                                        ((0x000000C0&(data))>>6)
#define  CP_RCIC_CTRL_get_write_en1(data)                                        ((0x00000020&(data))>>5)
#define  CP_RCIC_CTRL_get_wait_sec(data)                                         (0x0000001F&(data))

#define  CP_RCIC_ENTR_VLD                                                        0x180159A4
#define  CP_RCIC_ENTR_VLD_reg_addr                                               "0xB80159A4"
#define  CP_RCIC_ENTR_VLD_reg                                                    0xB80159A4
#define  CP_RCIC_ENTR_VLD_inst_addr                                              "0x003D"
#define  set_CP_RCIC_ENTR_VLD_reg(data)                                          (*((volatile unsigned int*)CP_RCIC_ENTR_VLD_reg)=data)
#define  get_CP_RCIC_ENTR_VLD_reg                                                (*((volatile unsigned int*)CP_RCIC_ENTR_VLD_reg))
#define  CP_RCIC_ENTR_VLD_write_en7_shift                                        (15)
#define  CP_RCIC_ENTR_VLD_valid_7_shift                                          (14)
#define  CP_RCIC_ENTR_VLD_write_en6_shift                                        (13)
#define  CP_RCIC_ENTR_VLD_valid_6_shift                                          (12)
#define  CP_RCIC_ENTR_VLD_write_en5_shift                                        (11)
#define  CP_RCIC_ENTR_VLD_valid_5_shift                                          (10)
#define  CP_RCIC_ENTR_VLD_write_en4_shift                                        (9)
#define  CP_RCIC_ENTR_VLD_valid_4_shift                                          (8)
#define  CP_RCIC_ENTR_VLD_write_en3_shift                                        (7)
#define  CP_RCIC_ENTR_VLD_valid_3_shift                                          (6)
#define  CP_RCIC_ENTR_VLD_write_en2_shift                                        (5)
#define  CP_RCIC_ENTR_VLD_valid_2_shift                                          (4)
#define  CP_RCIC_ENTR_VLD_write_en1_shift                                        (3)
#define  CP_RCIC_ENTR_VLD_valid_1_shift                                          (2)
#define  CP_RCIC_ENTR_VLD_write_en0_shift                                        (1)
#define  CP_RCIC_ENTR_VLD_valid_0_shift                                          (0)
#define  CP_RCIC_ENTR_VLD_write_en7_mask                                         (0x00008000)
#define  CP_RCIC_ENTR_VLD_valid_7_mask                                           (0x00004000)
#define  CP_RCIC_ENTR_VLD_write_en6_mask                                         (0x00002000)
#define  CP_RCIC_ENTR_VLD_valid_6_mask                                           (0x00001000)
#define  CP_RCIC_ENTR_VLD_write_en5_mask                                         (0x00000800)
#define  CP_RCIC_ENTR_VLD_valid_5_mask                                           (0x00000400)
#define  CP_RCIC_ENTR_VLD_write_en4_mask                                         (0x00000200)
#define  CP_RCIC_ENTR_VLD_valid_4_mask                                           (0x00000100)
#define  CP_RCIC_ENTR_VLD_write_en3_mask                                         (0x00000080)
#define  CP_RCIC_ENTR_VLD_valid_3_mask                                           (0x00000040)
#define  CP_RCIC_ENTR_VLD_write_en2_mask                                         (0x00000020)
#define  CP_RCIC_ENTR_VLD_valid_2_mask                                           (0x00000010)
#define  CP_RCIC_ENTR_VLD_write_en1_mask                                         (0x00000008)
#define  CP_RCIC_ENTR_VLD_valid_1_mask                                           (0x00000004)
#define  CP_RCIC_ENTR_VLD_write_en0_mask                                         (0x00000002)
#define  CP_RCIC_ENTR_VLD_valid_0_mask                                           (0x00000001)
#define  CP_RCIC_ENTR_VLD_write_en7(data)                                        (0x00008000&((data)<<15))
#define  CP_RCIC_ENTR_VLD_valid_7(data)                                          (0x00004000&((data)<<14))
#define  CP_RCIC_ENTR_VLD_write_en6(data)                                        (0x00002000&((data)<<13))
#define  CP_RCIC_ENTR_VLD_valid_6(data)                                          (0x00001000&((data)<<12))
#define  CP_RCIC_ENTR_VLD_write_en5(data)                                        (0x00000800&((data)<<11))
#define  CP_RCIC_ENTR_VLD_valid_5(data)                                          (0x00000400&((data)<<10))
#define  CP_RCIC_ENTR_VLD_write_en4(data)                                        (0x00000200&((data)<<9))
#define  CP_RCIC_ENTR_VLD_valid_4(data)                                          (0x00000100&((data)<<8))
#define  CP_RCIC_ENTR_VLD_write_en3(data)                                        (0x00000080&((data)<<7))
#define  CP_RCIC_ENTR_VLD_valid_3(data)                                          (0x00000040&((data)<<6))
#define  CP_RCIC_ENTR_VLD_write_en2(data)                                        (0x00000020&((data)<<5))
#define  CP_RCIC_ENTR_VLD_valid_2(data)                                          (0x00000010&((data)<<4))
#define  CP_RCIC_ENTR_VLD_write_en1(data)                                        (0x00000008&((data)<<3))
#define  CP_RCIC_ENTR_VLD_valid_1(data)                                          (0x00000004&((data)<<2))
#define  CP_RCIC_ENTR_VLD_write_en0(data)                                        (0x00000002&((data)<<1))
#define  CP_RCIC_ENTR_VLD_valid_0(data)                                          (0x00000001&(data))
#define  CP_RCIC_ENTR_VLD_get_write_en7(data)                                    ((0x00008000&(data))>>15)
#define  CP_RCIC_ENTR_VLD_get_valid_7(data)                                      ((0x00004000&(data))>>14)
#define  CP_RCIC_ENTR_VLD_get_write_en6(data)                                    ((0x00002000&(data))>>13)
#define  CP_RCIC_ENTR_VLD_get_valid_6(data)                                      ((0x00001000&(data))>>12)
#define  CP_RCIC_ENTR_VLD_get_write_en5(data)                                    ((0x00000800&(data))>>11)
#define  CP_RCIC_ENTR_VLD_get_valid_5(data)                                      ((0x00000400&(data))>>10)
#define  CP_RCIC_ENTR_VLD_get_write_en4(data)                                    ((0x00000200&(data))>>9)
#define  CP_RCIC_ENTR_VLD_get_valid_4(data)                                      ((0x00000100&(data))>>8)
#define  CP_RCIC_ENTR_VLD_get_write_en3(data)                                    ((0x00000080&(data))>>7)
#define  CP_RCIC_ENTR_VLD_get_valid_3(data)                                      ((0x00000040&(data))>>6)
#define  CP_RCIC_ENTR_VLD_get_write_en2(data)                                    ((0x00000020&(data))>>5)
#define  CP_RCIC_ENTR_VLD_get_valid_2(data)                                      ((0x00000010&(data))>>4)
#define  CP_RCIC_ENTR_VLD_get_write_en1(data)                                    ((0x00000008&(data))>>3)
#define  CP_RCIC_ENTR_VLD_get_valid_1(data)                                      ((0x00000004&(data))>>2)
#define  CP_RCIC_ENTR_VLD_get_write_en0(data)                                    ((0x00000002&(data))>>1)
#define  CP_RCIC_ENTR_VLD_get_valid_0(data)                                      (0x00000001&(data))

#define  CP_RCIC_STATUS                                                          0x180159A8
#define  CP_RCIC_STATUS_reg_addr                                                 "0xB80159A8"
#define  CP_RCIC_STATUS_reg                                                      0xB80159A8
#define  CP_RCIC_STATUS_inst_addr                                                "0x003E"
#define  set_CP_RCIC_STATUS_reg(data)                                            (*((volatile unsigned int*)CP_RCIC_STATUS_reg)=data)
#define  get_CP_RCIC_STATUS_reg                                                  (*((volatile unsigned int*)CP_RCIC_STATUS_reg))
#define  CP_RCIC_STATUS_entry_shift                                              (1)
#define  CP_RCIC_STATUS_done_shift                                               (0)
#define  CP_RCIC_STATUS_entry_mask                                               (0x0000000E)
#define  CP_RCIC_STATUS_done_mask                                                (0x00000001)
#define  CP_RCIC_STATUS_entry(data)                                              (0x0000000E&((data)<<1))
#define  CP_RCIC_STATUS_done(data)                                               (0x00000001&(data))
#define  CP_RCIC_STATUS_get_entry(data)                                          ((0x0000000E&(data))>>1)
#define  CP_RCIC_STATUS_get_done(data)                                           (0x00000001&(data))

#define  CP_RCIC_ENTR_SRC_0                                                      0x180159AC
#define  CP_RCIC_ENTR_SRC_0_reg_addr                                             "0xB80159AC"
#define  CP_RCIC_ENTR_SRC_0_reg                                                  0xB80159AC
#define  CP_RCIC_ENTR_SRC_0_inst_addr                                            "0x003F"
#define  set_CP_RCIC_ENTR_SRC_0_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_0_reg)=data)
#define  get_CP_RCIC_ENTR_SRC_0_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_0_reg))
#define  CP_RCIC_ENTR_SRC_0_adr_shift                                            (0)
#define  CP_RCIC_ENTR_SRC_0_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_SRC_0_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_SRC_0_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_SRC_1                                                      0x180159B0
#define  CP_RCIC_ENTR_SRC_1_reg_addr                                             "0xB80159B0"
#define  CP_RCIC_ENTR_SRC_1_reg                                                  0xB80159B0
#define  CP_RCIC_ENTR_SRC_1_inst_addr                                            "0x0040"
#define  set_CP_RCIC_ENTR_SRC_1_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_1_reg)=data)
#define  get_CP_RCIC_ENTR_SRC_1_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_1_reg))
#define  CP_RCIC_ENTR_SRC_1_adr_shift                                            (0)
#define  CP_RCIC_ENTR_SRC_1_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_SRC_1_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_SRC_1_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_SRC_2                                                      0x180159B4
#define  CP_RCIC_ENTR_SRC_2_reg_addr                                             "0xB80159B4"
#define  CP_RCIC_ENTR_SRC_2_reg                                                  0xB80159B4
#define  CP_RCIC_ENTR_SRC_2_inst_addr                                            "0x0041"
#define  set_CP_RCIC_ENTR_SRC_2_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_2_reg)=data)
#define  get_CP_RCIC_ENTR_SRC_2_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_2_reg))
#define  CP_RCIC_ENTR_SRC_2_adr_shift                                            (0)
#define  CP_RCIC_ENTR_SRC_2_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_SRC_2_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_SRC_2_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_SRC_3                                                      0x180159B8
#define  CP_RCIC_ENTR_SRC_3_reg_addr                                             "0xB80159B8"
#define  CP_RCIC_ENTR_SRC_3_reg                                                  0xB80159B8
#define  CP_RCIC_ENTR_SRC_3_inst_addr                                            "0x0042"
#define  set_CP_RCIC_ENTR_SRC_3_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_3_reg)=data)
#define  get_CP_RCIC_ENTR_SRC_3_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_3_reg))
#define  CP_RCIC_ENTR_SRC_3_adr_shift                                            (0)
#define  CP_RCIC_ENTR_SRC_3_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_SRC_3_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_SRC_3_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_SRC_4                                                      0x180159BC
#define  CP_RCIC_ENTR_SRC_4_reg_addr                                             "0xB80159BC"
#define  CP_RCIC_ENTR_SRC_4_reg                                                  0xB80159BC
#define  CP_RCIC_ENTR_SRC_4_inst_addr                                            "0x0043"
#define  set_CP_RCIC_ENTR_SRC_4_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_4_reg)=data)
#define  get_CP_RCIC_ENTR_SRC_4_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_4_reg))
#define  CP_RCIC_ENTR_SRC_4_adr_shift                                            (0)
#define  CP_RCIC_ENTR_SRC_4_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_SRC_4_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_SRC_4_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_SRC_5                                                      0x180159C0
#define  CP_RCIC_ENTR_SRC_5_reg_addr                                             "0xB80159C0"
#define  CP_RCIC_ENTR_SRC_5_reg                                                  0xB80159C0
#define  CP_RCIC_ENTR_SRC_5_inst_addr                                            "0x0044"
#define  set_CP_RCIC_ENTR_SRC_5_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_5_reg)=data)
#define  get_CP_RCIC_ENTR_SRC_5_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_5_reg))
#define  CP_RCIC_ENTR_SRC_5_adr_shift                                            (0)
#define  CP_RCIC_ENTR_SRC_5_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_SRC_5_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_SRC_5_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_SRC_6                                                      0x180159C4
#define  CP_RCIC_ENTR_SRC_6_reg_addr                                             "0xB80159C4"
#define  CP_RCIC_ENTR_SRC_6_reg                                                  0xB80159C4
#define  CP_RCIC_ENTR_SRC_6_inst_addr                                            "0x0045"
#define  set_CP_RCIC_ENTR_SRC_6_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_6_reg)=data)
#define  get_CP_RCIC_ENTR_SRC_6_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_6_reg))
#define  CP_RCIC_ENTR_SRC_6_adr_shift                                            (0)
#define  CP_RCIC_ENTR_SRC_6_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_SRC_6_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_SRC_6_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_SRC_7                                                      0x180159C8
#define  CP_RCIC_ENTR_SRC_7_reg_addr                                             "0xB80159C8"
#define  CP_RCIC_ENTR_SRC_7_reg                                                  0xB80159C8
#define  CP_RCIC_ENTR_SRC_7_inst_addr                                            "0x0046"
#define  set_CP_RCIC_ENTR_SRC_7_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_7_reg)=data)
#define  get_CP_RCIC_ENTR_SRC_7_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_SRC_7_reg))
#define  CP_RCIC_ENTR_SRC_7_adr_shift                                            (0)
#define  CP_RCIC_ENTR_SRC_7_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_SRC_7_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_SRC_7_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_DST_0                                                      0x180159CC
#define  CP_RCIC_ENTR_DST_0_reg_addr                                             "0xB80159CC"
#define  CP_RCIC_ENTR_DST_0_reg                                                  0xB80159CC
#define  CP_RCIC_ENTR_DST_0_inst_addr                                            "0x0047"
#define  set_CP_RCIC_ENTR_DST_0_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_DST_0_reg)=data)
#define  get_CP_RCIC_ENTR_DST_0_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_DST_0_reg))
#define  CP_RCIC_ENTR_DST_0_adr_shift                                            (0)
#define  CP_RCIC_ENTR_DST_0_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_DST_0_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_DST_0_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_DST_1                                                      0x180159D0
#define  CP_RCIC_ENTR_DST_1_reg_addr                                             "0xB80159D0"
#define  CP_RCIC_ENTR_DST_1_reg                                                  0xB80159D0
#define  CP_RCIC_ENTR_DST_1_inst_addr                                            "0x0048"
#define  set_CP_RCIC_ENTR_DST_1_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_DST_1_reg)=data)
#define  get_CP_RCIC_ENTR_DST_1_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_DST_1_reg))
#define  CP_RCIC_ENTR_DST_1_adr_shift                                            (0)
#define  CP_RCIC_ENTR_DST_1_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_DST_1_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_DST_1_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_DST_2                                                      0x180159D4
#define  CP_RCIC_ENTR_DST_2_reg_addr                                             "0xB80159D4"
#define  CP_RCIC_ENTR_DST_2_reg                                                  0xB80159D4
#define  CP_RCIC_ENTR_DST_2_inst_addr                                            "0x0049"
#define  set_CP_RCIC_ENTR_DST_2_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_DST_2_reg)=data)
#define  get_CP_RCIC_ENTR_DST_2_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_DST_2_reg))
#define  CP_RCIC_ENTR_DST_2_adr_shift                                            (0)
#define  CP_RCIC_ENTR_DST_2_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_DST_2_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_DST_2_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_DST_3                                                      0x180159D8
#define  CP_RCIC_ENTR_DST_3_reg_addr                                             "0xB80159D8"
#define  CP_RCIC_ENTR_DST_3_reg                                                  0xB80159D8
#define  CP_RCIC_ENTR_DST_3_inst_addr                                            "0x004A"
#define  set_CP_RCIC_ENTR_DST_3_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_DST_3_reg)=data)
#define  get_CP_RCIC_ENTR_DST_3_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_DST_3_reg))
#define  CP_RCIC_ENTR_DST_3_adr_shift                                            (0)
#define  CP_RCIC_ENTR_DST_3_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_DST_3_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_DST_3_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_DST_4                                                      0x180159DC
#define  CP_RCIC_ENTR_DST_4_reg_addr                                             "0xB80159DC"
#define  CP_RCIC_ENTR_DST_4_reg                                                  0xB80159DC
#define  CP_RCIC_ENTR_DST_4_inst_addr                                            "0x004B"
#define  set_CP_RCIC_ENTR_DST_4_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_DST_4_reg)=data)
#define  get_CP_RCIC_ENTR_DST_4_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_DST_4_reg))
#define  CP_RCIC_ENTR_DST_4_adr_shift                                            (0)
#define  CP_RCIC_ENTR_DST_4_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_DST_4_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_DST_4_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_DST_5                                                      0x180159E0
#define  CP_RCIC_ENTR_DST_5_reg_addr                                             "0xB80159E0"
#define  CP_RCIC_ENTR_DST_5_reg                                                  0xB80159E0
#define  CP_RCIC_ENTR_DST_5_inst_addr                                            "0x004C"
#define  set_CP_RCIC_ENTR_DST_5_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_DST_5_reg)=data)
#define  get_CP_RCIC_ENTR_DST_5_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_DST_5_reg))
#define  CP_RCIC_ENTR_DST_5_adr_shift                                            (0)
#define  CP_RCIC_ENTR_DST_5_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_DST_5_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_DST_5_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_DST_6                                                      0x180159E4
#define  CP_RCIC_ENTR_DST_6_reg_addr                                             "0xB80159E4"
#define  CP_RCIC_ENTR_DST_6_reg                                                  0xB80159E4
#define  CP_RCIC_ENTR_DST_6_inst_addr                                            "0x004D"
#define  set_CP_RCIC_ENTR_DST_6_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_DST_6_reg)=data)
#define  get_CP_RCIC_ENTR_DST_6_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_DST_6_reg))
#define  CP_RCIC_ENTR_DST_6_adr_shift                                            (0)
#define  CP_RCIC_ENTR_DST_6_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_DST_6_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_DST_6_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_ENTR_DST_7                                                      0x180159E8
#define  CP_RCIC_ENTR_DST_7_reg_addr                                             "0xB80159E8"
#define  CP_RCIC_ENTR_DST_7_reg                                                  0xB80159E8
#define  CP_RCIC_ENTR_DST_7_inst_addr                                            "0x004E"
#define  set_CP_RCIC_ENTR_DST_7_reg(data)                                        (*((volatile unsigned int*)CP_RCIC_ENTR_DST_7_reg)=data)
#define  get_CP_RCIC_ENTR_DST_7_reg                                              (*((volatile unsigned int*)CP_RCIC_ENTR_DST_7_reg))
#define  CP_RCIC_ENTR_DST_7_adr_shift                                            (0)
#define  CP_RCIC_ENTR_DST_7_adr_mask                                             (0xFFFFFFFF)
#define  CP_RCIC_ENTR_DST_7_adr(data)                                            (0xFFFFFFFF&(data))
#define  CP_RCIC_ENTR_DST_7_get_adr(data)                                        (0xFFFFFFFF&(data))

#define  CP_RCIC_INT_EN                                                          0x180159EC
#define  CP_RCIC_INT_EN_reg_addr                                                 "0xB80159EC"
#define  CP_RCIC_INT_EN_reg                                                      0xB80159EC
#define  CP_RCIC_INT_EN_inst_addr                                                "0x004F"
#define  set_CP_RCIC_INT_EN_reg(data)                                            (*((volatile unsigned int*)CP_RCIC_INT_EN_reg)=data)
#define  get_CP_RCIC_INT_EN_reg                                                  (*((volatile unsigned int*)CP_RCIC_INT_EN_reg))
#define  CP_RCIC_INT_EN_int_en_shift                                             (0)
#define  CP_RCIC_INT_EN_int_en_mask                                              (0x00000001)
#define  CP_RCIC_INT_EN_int_en(data)                                             (0x00000001&(data))
#define  CP_RCIC_INT_EN_get_int_en(data)                                         (0x00000001&(data))

#define  CP_CP_REG_SEMAPHORE                                                     0x18015030
#define  CP_CP_REG_SEMAPHORE_reg_addr                                            "0xB8015030"
#define  CP_CP_REG_SEMAPHORE_reg                                                 0xB8015030
#define  CP_CP_REG_SEMAPHORE_inst_addr                                           "0x0050"
#define  set_CP_CP_REG_SEMAPHORE_reg(data)                                       (*((volatile unsigned int*)CP_CP_REG_SEMAPHORE_reg)=data)
#define  get_CP_CP_REG_SEMAPHORE_reg                                             (*((volatile unsigned int*)CP_CP_REG_SEMAPHORE_reg))
#define  CP_CP_REG_SEMAPHORE_semaphore_shift                                     (0)
#define  CP_CP_REG_SEMAPHORE_semaphore_mask                                      (0x00000001)
#define  CP_CP_REG_SEMAPHORE_semaphore(data)                                     (0x00000001&(data))
#define  CP_CP_REG_SEMAPHORE_get_semaphore(data)                                 (0x00000001&(data))

#define  CP_CP_REG_KEY_0                                                         0x18015034
#define  CP_CP_REG_KEY_0_reg_addr                                                "0xB8015034"
#define  CP_CP_REG_KEY_0_reg                                                     0xB8015034
#define  CP_CP_REG_KEY_0_inst_addr                                               "0x0051"
#define  set_CP_CP_REG_KEY_0_reg(data)                                           (*((volatile unsigned int*)CP_CP_REG_KEY_0_reg)=data)
#define  get_CP_CP_REG_KEY_0_reg                                                 (*((volatile unsigned int*)CP_CP_REG_KEY_0_reg))
#define  CP_CP_REG_KEY_0_data_shift                                              (0)
#define  CP_CP_REG_KEY_0_data_mask                                               (0xFFFFFFFF)
#define  CP_CP_REG_KEY_0_data(data)                                              (0xFFFFFFFF&(data))
#define  CP_CP_REG_KEY_0_get_data(data)                                          (0xFFFFFFFF&(data))

#define  CP_CP_REG_KEY_1                                                         0x18015038
#define  CP_CP_REG_KEY_1_reg_addr                                                "0xB8015038"
#define  CP_CP_REG_KEY_1_reg                                                     0xB8015038
#define  CP_CP_REG_KEY_1_inst_addr                                               "0x0052"
#define  set_CP_CP_REG_KEY_1_reg(data)                                           (*((volatile unsigned int*)CP_CP_REG_KEY_1_reg)=data)
#define  get_CP_CP_REG_KEY_1_reg                                                 (*((volatile unsigned int*)CP_CP_REG_KEY_1_reg))
#define  CP_CP_REG_KEY_1_data_shift                                              (0)
#define  CP_CP_REG_KEY_1_data_mask                                               (0xFFFFFFFF)
#define  CP_CP_REG_KEY_1_data(data)                                              (0xFFFFFFFF&(data))
#define  CP_CP_REG_KEY_1_get_data(data)                                          (0xFFFFFFFF&(data))

#define  CP_CP_REG_KEY_2                                                         0x1801503C
#define  CP_CP_REG_KEY_2_reg_addr                                                "0xB801503C"
#define  CP_CP_REG_KEY_2_reg                                                     0xB801503C
#define  CP_CP_REG_KEY_2_inst_addr                                               "0x0053"
#define  set_CP_CP_REG_KEY_2_reg(data)                                           (*((volatile unsigned int*)CP_CP_REG_KEY_2_reg)=data)
#define  get_CP_CP_REG_KEY_2_reg                                                 (*((volatile unsigned int*)CP_CP_REG_KEY_2_reg))
#define  CP_CP_REG_KEY_2_data_shift                                              (0)
#define  CP_CP_REG_KEY_2_data_mask                                               (0xFFFFFFFF)
#define  CP_CP_REG_KEY_2_data(data)                                              (0xFFFFFFFF&(data))
#define  CP_CP_REG_KEY_2_get_data(data)                                          (0xFFFFFFFF&(data))

#define  CP_CP_REG_KEY_3                                                         0x18015040
#define  CP_CP_REG_KEY_3_reg_addr                                                "0xB8015040"
#define  CP_CP_REG_KEY_3_reg                                                     0xB8015040
#define  CP_CP_REG_KEY_3_inst_addr                                               "0x0054"
#define  set_CP_CP_REG_KEY_3_reg(data)                                           (*((volatile unsigned int*)CP_CP_REG_KEY_3_reg)=data)
#define  get_CP_CP_REG_KEY_3_reg                                                 (*((volatile unsigned int*)CP_CP_REG_KEY_3_reg))
#define  CP_CP_REG_KEY_3_data_shift                                              (0)
#define  CP_CP_REG_KEY_3_data_mask                                               (0xFFFFFFFF)
#define  CP_CP_REG_KEY_3_data(data)                                              (0xFFFFFFFF&(data))
#define  CP_CP_REG_KEY_3_get_data(data)                                          (0xFFFFFFFF&(data))

#define  CP_CP_REG_KEY1_0                                                        0x18015210
#define  CP_CP_REG_KEY1_0_reg_addr                                               "0xB8015210"
#define  CP_CP_REG_KEY1_0_reg                                                    0xB8015210
#define  CP_CP_REG_KEY1_0_inst_addr                                              "0x0055"
#define  set_CP_CP_REG_KEY1_0_reg(data)                                          (*((volatile unsigned int*)CP_CP_REG_KEY1_0_reg)=data)
#define  get_CP_CP_REG_KEY1_0_reg                                                (*((volatile unsigned int*)CP_CP_REG_KEY1_0_reg))
#define  CP_CP_REG_KEY1_0_data_shift                                             (0)
#define  CP_CP_REG_KEY1_0_data_mask                                              (0xFFFFFFFF)
#define  CP_CP_REG_KEY1_0_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_CP_REG_KEY1_0_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_CP_REG_KEY1_1                                                        0x18015214
#define  CP_CP_REG_KEY1_1_reg_addr                                               "0xB8015214"
#define  CP_CP_REG_KEY1_1_reg                                                    0xB8015214
#define  CP_CP_REG_KEY1_1_inst_addr                                              "0x0056"
#define  set_CP_CP_REG_KEY1_1_reg(data)                                          (*((volatile unsigned int*)CP_CP_REG_KEY1_1_reg)=data)
#define  get_CP_CP_REG_KEY1_1_reg                                                (*((volatile unsigned int*)CP_CP_REG_KEY1_1_reg))
#define  CP_CP_REG_KEY1_1_data_shift                                             (0)
#define  CP_CP_REG_KEY1_1_data_mask                                              (0xFFFFFFFF)
#define  CP_CP_REG_KEY1_1_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_CP_REG_KEY1_1_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_CP_REG_KEY1_2                                                        0x18015218
#define  CP_CP_REG_KEY1_2_reg_addr                                               "0xB8015218"
#define  CP_CP_REG_KEY1_2_reg                                                    0xB8015218
#define  CP_CP_REG_KEY1_2_inst_addr                                              "0x0057"
#define  set_CP_CP_REG_KEY1_2_reg(data)                                          (*((volatile unsigned int*)CP_CP_REG_KEY1_2_reg)=data)
#define  get_CP_CP_REG_KEY1_2_reg                                                (*((volatile unsigned int*)CP_CP_REG_KEY1_2_reg))
#define  CP_CP_REG_KEY1_2_data_shift                                             (0)
#define  CP_CP_REG_KEY1_2_data_mask                                              (0xFFFFFFFF)
#define  CP_CP_REG_KEY1_2_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_CP_REG_KEY1_2_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_CP_REG_KEY1_3                                                        0x1801521C
#define  CP_CP_REG_KEY1_3_reg_addr                                               "0xB801521C"
#define  CP_CP_REG_KEY1_3_reg                                                    0xB801521C
#define  CP_CP_REG_KEY1_3_inst_addr                                              "0x0058"
#define  set_CP_CP_REG_KEY1_3_reg(data)                                          (*((volatile unsigned int*)CP_CP_REG_KEY1_3_reg)=data)
#define  get_CP_CP_REG_KEY1_3_reg                                                (*((volatile unsigned int*)CP_CP_REG_KEY1_3_reg))
#define  CP_CP_REG_KEY1_3_data_shift                                             (0)
#define  CP_CP_REG_KEY1_3_data_mask                                              (0xFFFFFFFF)
#define  CP_CP_REG_KEY1_3_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_CP_REG_KEY1_3_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_CP_REG_DATAIN_0                                                      0x18015044
#define  CP_CP_REG_DATAIN_0_reg_addr                                             "0xB8015044"
#define  CP_CP_REG_DATAIN_0_reg                                                  0xB8015044
#define  CP_CP_REG_DATAIN_0_inst_addr                                            "0x0059"
#define  set_CP_CP_REG_DATAIN_0_reg(data)                                        (*((volatile unsigned int*)CP_CP_REG_DATAIN_0_reg)=data)
#define  get_CP_CP_REG_DATAIN_0_reg                                              (*((volatile unsigned int*)CP_CP_REG_DATAIN_0_reg))
#define  CP_CP_REG_DATAIN_0_data_shift                                           (0)
#define  CP_CP_REG_DATAIN_0_data_mask                                            (0xFFFFFFFF)
#define  CP_CP_REG_DATAIN_0_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_CP_REG_DATAIN_0_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_CP_REG_DATAIN_1                                                      0x18015048
#define  CP_CP_REG_DATAIN_1_reg_addr                                             "0xB8015048"
#define  CP_CP_REG_DATAIN_1_reg                                                  0xB8015048
#define  CP_CP_REG_DATAIN_1_inst_addr                                            "0x005A"
#define  set_CP_CP_REG_DATAIN_1_reg(data)                                        (*((volatile unsigned int*)CP_CP_REG_DATAIN_1_reg)=data)
#define  get_CP_CP_REG_DATAIN_1_reg                                              (*((volatile unsigned int*)CP_CP_REG_DATAIN_1_reg))
#define  CP_CP_REG_DATAIN_1_data_shift                                           (0)
#define  CP_CP_REG_DATAIN_1_data_mask                                            (0xFFFFFFFF)
#define  CP_CP_REG_DATAIN_1_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_CP_REG_DATAIN_1_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_CP_REG_DATAIN_2                                                      0x1801504C
#define  CP_CP_REG_DATAIN_2_reg_addr                                             "0xB801504C"
#define  CP_CP_REG_DATAIN_2_reg                                                  0xB801504C
#define  CP_CP_REG_DATAIN_2_inst_addr                                            "0x005B"
#define  set_CP_CP_REG_DATAIN_2_reg(data)                                        (*((volatile unsigned int*)CP_CP_REG_DATAIN_2_reg)=data)
#define  get_CP_CP_REG_DATAIN_2_reg                                              (*((volatile unsigned int*)CP_CP_REG_DATAIN_2_reg))
#define  CP_CP_REG_DATAIN_2_data_shift                                           (0)
#define  CP_CP_REG_DATAIN_2_data_mask                                            (0xFFFFFFFF)
#define  CP_CP_REG_DATAIN_2_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_CP_REG_DATAIN_2_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_CP_REG_DATAIN_3                                                      0x18015050
#define  CP_CP_REG_DATAIN_3_reg_addr                                             "0xB8015050"
#define  CP_CP_REG_DATAIN_3_reg                                                  0xB8015050
#define  CP_CP_REG_DATAIN_3_inst_addr                                            "0x005C"
#define  set_CP_CP_REG_DATAIN_3_reg(data)                                        (*((volatile unsigned int*)CP_CP_REG_DATAIN_3_reg)=data)
#define  get_CP_CP_REG_DATAIN_3_reg                                              (*((volatile unsigned int*)CP_CP_REG_DATAIN_3_reg))
#define  CP_CP_REG_DATAIN_3_data_shift                                           (0)
#define  CP_CP_REG_DATAIN_3_data_mask                                            (0xFFFFFFFF)
#define  CP_CP_REG_DATAIN_3_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_CP_REG_DATAIN_3_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_CP_REG_DATAOUT_0                                                     0x18015054
#define  CP_CP_REG_DATAOUT_0_reg_addr                                            "0xB8015054"
#define  CP_CP_REG_DATAOUT_0_reg                                                 0xB8015054
#define  CP_CP_REG_DATAOUT_0_inst_addr                                           "0x005D"
#define  set_CP_CP_REG_DATAOUT_0_reg(data)                                       (*((volatile unsigned int*)CP_CP_REG_DATAOUT_0_reg)=data)
#define  get_CP_CP_REG_DATAOUT_0_reg                                             (*((volatile unsigned int*)CP_CP_REG_DATAOUT_0_reg))
#define  CP_CP_REG_DATAOUT_0_data_shift                                          (0)
#define  CP_CP_REG_DATAOUT_0_data_mask                                           (0xFFFFFFFF)
#define  CP_CP_REG_DATAOUT_0_data(data)                                          (0xFFFFFFFF&(data))
#define  CP_CP_REG_DATAOUT_0_get_data(data)                                      (0xFFFFFFFF&(data))

#define  CP_CP_REG_DATAOUT_1                                                     0x18015058
#define  CP_CP_REG_DATAOUT_1_reg_addr                                            "0xB8015058"
#define  CP_CP_REG_DATAOUT_1_reg                                                 0xB8015058
#define  CP_CP_REG_DATAOUT_1_inst_addr                                           "0x005E"
#define  set_CP_CP_REG_DATAOUT_1_reg(data)                                       (*((volatile unsigned int*)CP_CP_REG_DATAOUT_1_reg)=data)
#define  get_CP_CP_REG_DATAOUT_1_reg                                             (*((volatile unsigned int*)CP_CP_REG_DATAOUT_1_reg))
#define  CP_CP_REG_DATAOUT_1_data_shift                                          (0)
#define  CP_CP_REG_DATAOUT_1_data_mask                                           (0xFFFFFFFF)
#define  CP_CP_REG_DATAOUT_1_data(data)                                          (0xFFFFFFFF&(data))
#define  CP_CP_REG_DATAOUT_1_get_data(data)                                      (0xFFFFFFFF&(data))

#define  CP_CP_REG_DATAOUT_2                                                     0x1801505C
#define  CP_CP_REG_DATAOUT_2_reg_addr                                            "0xB801505C"
#define  CP_CP_REG_DATAOUT_2_reg                                                 0xB801505C
#define  CP_CP_REG_DATAOUT_2_inst_addr                                           "0x005F"
#define  set_CP_CP_REG_DATAOUT_2_reg(data)                                       (*((volatile unsigned int*)CP_CP_REG_DATAOUT_2_reg)=data)
#define  get_CP_CP_REG_DATAOUT_2_reg                                             (*((volatile unsigned int*)CP_CP_REG_DATAOUT_2_reg))
#define  CP_CP_REG_DATAOUT_2_data_shift                                          (0)
#define  CP_CP_REG_DATAOUT_2_data_mask                                           (0xFFFFFFFF)
#define  CP_CP_REG_DATAOUT_2_data(data)                                          (0xFFFFFFFF&(data))
#define  CP_CP_REG_DATAOUT_2_get_data(data)                                      (0xFFFFFFFF&(data))

#define  CP_CP_REG_DATAOUT_3                                                     0x18015060
#define  CP_CP_REG_DATAOUT_3_reg_addr                                            "0xB8015060"
#define  CP_CP_REG_DATAOUT_3_reg                                                 0xB8015060
#define  CP_CP_REG_DATAOUT_3_inst_addr                                           "0x0060"
#define  set_CP_CP_REG_DATAOUT_3_reg(data)                                       (*((volatile unsigned int*)CP_CP_REG_DATAOUT_3_reg)=data)
#define  get_CP_CP_REG_DATAOUT_3_reg                                             (*((volatile unsigned int*)CP_CP_REG_DATAOUT_3_reg))
#define  CP_CP_REG_DATAOUT_3_data_shift                                          (0)
#define  CP_CP_REG_DATAOUT_3_data_mask                                           (0xFFFFFFFF)
#define  CP_CP_REG_DATAOUT_3_data(data)                                          (0xFFFFFFFF&(data))
#define  CP_CP_REG_DATAOUT_3_get_data(data)                                      (0xFFFFFFFF&(data))

#define  CP_CP_REG_DATAOUT_4                                                     0x18015064
#define  CP_CP_REG_DATAOUT_4_reg_addr                                            "0xB8015064"
#define  CP_CP_REG_DATAOUT_4_reg                                                 0xB8015064
#define  CP_CP_REG_DATAOUT_4_inst_addr                                           "0x0061"
#define  set_CP_CP_REG_DATAOUT_4_reg(data)                                       (*((volatile unsigned int*)CP_CP_REG_DATAOUT_4_reg)=data)
#define  get_CP_CP_REG_DATAOUT_4_reg                                             (*((volatile unsigned int*)CP_CP_REG_DATAOUT_4_reg))
#define  CP_CP_REG_DATAOUT_4_data_shift                                          (0)
#define  CP_CP_REG_DATAOUT_4_data_mask                                           (0xFFFFFFFF)
#define  CP_CP_REG_DATAOUT_4_data(data)                                          (0xFFFFFFFF&(data))
#define  CP_CP_REG_DATAOUT_4_get_data(data)                                      (0xFFFFFFFF&(data))

#define  CP_CP_REG_DATAOUT_5                                                     0x18015068
#define  CP_CP_REG_DATAOUT_5_reg_addr                                            "0xB8015068"
#define  CP_CP_REG_DATAOUT_5_reg                                                 0xB8015068
#define  CP_CP_REG_DATAOUT_5_inst_addr                                           "0x0062"
#define  set_CP_CP_REG_DATAOUT_5_reg(data)                                       (*((volatile unsigned int*)CP_CP_REG_DATAOUT_5_reg)=data)
#define  get_CP_CP_REG_DATAOUT_5_reg                                             (*((volatile unsigned int*)CP_CP_REG_DATAOUT_5_reg))
#define  CP_CP_REG_DATAOUT_5_data_shift                                          (0)
#define  CP_CP_REG_DATAOUT_5_data_mask                                           (0xFFFFFFFF)
#define  CP_CP_REG_DATAOUT_5_data(data)                                          (0xFFFFFFFF&(data))
#define  CP_CP_REG_DATAOUT_5_get_data(data)                                      (0xFFFFFFFF&(data))

#define  CP_CP_REG_DATAOUT_6                                                     0x1801506C
#define  CP_CP_REG_DATAOUT_6_reg_addr                                            "0xB801506C"
#define  CP_CP_REG_DATAOUT_6_reg                                                 0xB801506C
#define  CP_CP_REG_DATAOUT_6_inst_addr                                           "0x0063"
#define  set_CP_CP_REG_DATAOUT_6_reg(data)                                       (*((volatile unsigned int*)CP_CP_REG_DATAOUT_6_reg)=data)
#define  get_CP_CP_REG_DATAOUT_6_reg                                             (*((volatile unsigned int*)CP_CP_REG_DATAOUT_6_reg))
#define  CP_CP_REG_DATAOUT_6_data_shift                                          (0)
#define  CP_CP_REG_DATAOUT_6_data_mask                                           (0xFFFFFFFF)
#define  CP_CP_REG_DATAOUT_6_data(data)                                          (0xFFFFFFFF&(data))
#define  CP_CP_REG_DATAOUT_6_get_data(data)                                      (0xFFFFFFFF&(data))

#define  CP_CP_REG_DATAOUT_7                                                     0x18015070
#define  CP_CP_REG_DATAOUT_7_reg_addr                                            "0xB8015070"
#define  CP_CP_REG_DATAOUT_7_reg                                                 0xB8015070
#define  CP_CP_REG_DATAOUT_7_inst_addr                                           "0x0064"
#define  set_CP_CP_REG_DATAOUT_7_reg(data)                                       (*((volatile unsigned int*)CP_CP_REG_DATAOUT_7_reg)=data)
#define  get_CP_CP_REG_DATAOUT_7_reg                                             (*((volatile unsigned int*)CP_CP_REG_DATAOUT_7_reg))
#define  CP_CP_REG_DATAOUT_7_data_shift                                          (0)
#define  CP_CP_REG_DATAOUT_7_data_mask                                           (0xFFFFFFFF)
#define  CP_CP_REG_DATAOUT_7_data(data)                                          (0xFFFFFFFF&(data))
#define  CP_CP_REG_DATAOUT_7_get_data(data)                                      (0xFFFFFFFF&(data))

#define  CP_CP_REG_IV_0                                                          0x180150D0
#define  CP_CP_REG_IV_0_reg_addr                                                 "0xB80150D0"
#define  CP_CP_REG_IV_0_reg                                                      0xB80150D0
#define  CP_CP_REG_IV_0_inst_addr                                                "0x0065"
#define  set_CP_CP_REG_IV_0_reg(data)                                            (*((volatile unsigned int*)CP_CP_REG_IV_0_reg)=data)
#define  get_CP_CP_REG_IV_0_reg                                                  (*((volatile unsigned int*)CP_CP_REG_IV_0_reg))
#define  CP_CP_REG_IV_0_data_shift                                               (0)
#define  CP_CP_REG_IV_0_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_REG_IV_0_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_REG_IV_0_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_REG_IV_1                                                          0x180150D4
#define  CP_CP_REG_IV_1_reg_addr                                                 "0xB80150D4"
#define  CP_CP_REG_IV_1_reg                                                      0xB80150D4
#define  CP_CP_REG_IV_1_inst_addr                                                "0x0066"
#define  set_CP_CP_REG_IV_1_reg(data)                                            (*((volatile unsigned int*)CP_CP_REG_IV_1_reg)=data)
#define  get_CP_CP_REG_IV_1_reg                                                  (*((volatile unsigned int*)CP_CP_REG_IV_1_reg))
#define  CP_CP_REG_IV_1_data_shift                                               (0)
#define  CP_CP_REG_IV_1_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_REG_IV_1_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_REG_IV_1_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_REG_IV_2                                                          0x180150D8
#define  CP_CP_REG_IV_2_reg_addr                                                 "0xB80150D8"
#define  CP_CP_REG_IV_2_reg                                                      0xB80150D8
#define  CP_CP_REG_IV_2_inst_addr                                                "0x0067"
#define  set_CP_CP_REG_IV_2_reg(data)                                            (*((volatile unsigned int*)CP_CP_REG_IV_2_reg)=data)
#define  get_CP_CP_REG_IV_2_reg                                                  (*((volatile unsigned int*)CP_CP_REG_IV_2_reg))
#define  CP_CP_REG_IV_2_data_shift                                               (0)
#define  CP_CP_REG_IV_2_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_REG_IV_2_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_REG_IV_2_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_REG_IV_3                                                          0x180150DC
#define  CP_CP_REG_IV_3_reg_addr                                                 "0xB80150DC"
#define  CP_CP_REG_IV_3_reg                                                      0xB80150DC
#define  CP_CP_REG_IV_3_inst_addr                                                "0x0068"
#define  set_CP_CP_REG_IV_3_reg(data)                                            (*((volatile unsigned int*)CP_CP_REG_IV_3_reg)=data)
#define  get_CP_CP_REG_IV_3_reg                                                  (*((volatile unsigned int*)CP_CP_REG_IV_3_reg))
#define  CP_CP_REG_IV_3_data_shift                                               (0)
#define  CP_CP_REG_IV_3_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_REG_IV_3_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_REG_IV_3_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_REG_IV_4                                                          0x180150E0
#define  CP_CP_REG_IV_4_reg_addr                                                 "0xB80150E0"
#define  CP_CP_REG_IV_4_reg                                                      0xB80150E0
#define  CP_CP_REG_IV_4_inst_addr                                                "0x0069"
#define  set_CP_CP_REG_IV_4_reg(data)                                            (*((volatile unsigned int*)CP_CP_REG_IV_4_reg)=data)
#define  get_CP_CP_REG_IV_4_reg                                                  (*((volatile unsigned int*)CP_CP_REG_IV_4_reg))
#define  CP_CP_REG_IV_4_data_shift                                               (0)
#define  CP_CP_REG_IV_4_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_REG_IV_4_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_REG_IV_4_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_REG_IV_5                                                          0x180150E4
#define  CP_CP_REG_IV_5_reg_addr                                                 "0xB80150E4"
#define  CP_CP_REG_IV_5_reg                                                      0xB80150E4
#define  CP_CP_REG_IV_5_inst_addr                                                "0x006A"
#define  set_CP_CP_REG_IV_5_reg(data)                                            (*((volatile unsigned int*)CP_CP_REG_IV_5_reg)=data)
#define  get_CP_CP_REG_IV_5_reg                                                  (*((volatile unsigned int*)CP_CP_REG_IV_5_reg))
#define  CP_CP_REG_IV_5_data_shift                                               (0)
#define  CP_CP_REG_IV_5_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_REG_IV_5_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_REG_IV_5_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_REG_IV_6                                                          0x180150E8
#define  CP_CP_REG_IV_6_reg_addr                                                 "0xB80150E8"
#define  CP_CP_REG_IV_6_reg                                                      0xB80150E8
#define  CP_CP_REG_IV_6_inst_addr                                                "0x006B"
#define  set_CP_CP_REG_IV_6_reg(data)                                            (*((volatile unsigned int*)CP_CP_REG_IV_6_reg)=data)
#define  get_CP_CP_REG_IV_6_reg                                                  (*((volatile unsigned int*)CP_CP_REG_IV_6_reg))
#define  CP_CP_REG_IV_6_data_shift                                               (0)
#define  CP_CP_REG_IV_6_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_REG_IV_6_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_REG_IV_6_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_REG_IV_7                                                          0x180150EC
#define  CP_CP_REG_IV_7_reg_addr                                                 "0xB80150EC"
#define  CP_CP_REG_IV_7_reg                                                      0xB80150EC
#define  CP_CP_REG_IV_7_inst_addr                                                "0x006C"
#define  set_CP_CP_REG_IV_7_reg(data)                                            (*((volatile unsigned int*)CP_CP_REG_IV_7_reg)=data)
#define  get_CP_CP_REG_IV_7_reg                                                  (*((volatile unsigned int*)CP_CP_REG_IV_7_reg))
#define  CP_CP_REG_IV_7_data_shift                                               (0)
#define  CP_CP_REG_IV_7_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_REG_IV_7_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_REG_IV_7_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_REG_SET                                                           0x18015074
#define  CP_CP_REG_SET_reg_addr                                                  "0xB8015074"
#define  CP_CP_REG_SET_reg                                                       0xB8015074
#define  CP_CP_REG_SET_inst_addr                                                 "0x006D"
#define  set_CP_CP_REG_SET_reg(data)                                             (*((volatile unsigned int*)CP_CP_REG_SET_reg)=data)
#define  get_CP_CP_REG_SET_reg                                                   (*((volatile unsigned int*)CP_CP_REG_SET_reg))
#define  CP_CP_REG_SET_write_enable5_shift                                       (17)
#define  CP_CP_REG_SET_mode_shift                                                (13)
#define  CP_CP_REG_SET_write_enable4_shift                                       (11)
#define  CP_CP_REG_SET_endian_swap_shift                                         (10)
#define  CP_CP_REG_SET_write_enable3_shift                                       (9)
#define  CP_CP_REG_SET_cw_logic_opsel_shift                                      (7)
#define  CP_CP_REG_SET_write_enable2_shift                                       (6)
#define  CP_CP_REG_SET_bcm_shift                                                 (4)
#define  CP_CP_REG_SET_write_enable1_shift                                       (3)
#define  CP_CP_REG_SET_reg_first_shift                                           (2)
#define  CP_CP_REG_SET_write_enable0_shift                                       (1)
#define  CP_CP_REG_SET_reg_ende_shift                                            (0)
#define  CP_CP_REG_SET_write_enable5_mask                                        (0x00020000)
#define  CP_CP_REG_SET_mode_mask                                                 (0x0001E000)
#define  CP_CP_REG_SET_write_enable4_mask                                        (0x00000800)
#define  CP_CP_REG_SET_endian_swap_mask                                          (0x00000400)
#define  CP_CP_REG_SET_write_enable3_mask                                        (0x00000200)
#define  CP_CP_REG_SET_cw_logic_opsel_mask                                       (0x00000180)
#define  CP_CP_REG_SET_write_enable2_mask                                        (0x00000040)
#define  CP_CP_REG_SET_bcm_mask                                                  (0x00000030)
#define  CP_CP_REG_SET_write_enable1_mask                                        (0x00000008)
#define  CP_CP_REG_SET_reg_first_mask                                            (0x00000004)
#define  CP_CP_REG_SET_write_enable0_mask                                        (0x00000002)
#define  CP_CP_REG_SET_reg_ende_mask                                             (0x00000001)
#define  CP_CP_REG_SET_write_enable5(data)                                       (0x00020000&((data)<<17))
#define  CP_CP_REG_SET_mode(data)                                                (0x0001E000&((data)<<13))
#define  CP_CP_REG_SET_write_enable4(data)                                       (0x00000800&((data)<<11))
#define  CP_CP_REG_SET_endian_swap(data)                                         (0x00000400&((data)<<10))
#define  CP_CP_REG_SET_write_enable3(data)                                       (0x00000200&((data)<<9))
#define  CP_CP_REG_SET_cw_logic_opsel(data)                                      (0x00000180&((data)<<7))
#define  CP_CP_REG_SET_write_enable2(data)                                       (0x00000040&((data)<<6))
#define  CP_CP_REG_SET_bcm(data)                                                 (0x00000030&((data)<<4))
#define  CP_CP_REG_SET_write_enable1(data)                                       (0x00000008&((data)<<3))
#define  CP_CP_REG_SET_reg_first(data)                                           (0x00000004&((data)<<2))
#define  CP_CP_REG_SET_write_enable0(data)                                       (0x00000002&((data)<<1))
#define  CP_CP_REG_SET_reg_ende(data)                                            (0x00000001&(data))
#define  CP_CP_REG_SET_get_write_enable5(data)                                   ((0x00020000&(data))>>17)
#define  CP_CP_REG_SET_get_mode(data)                                            ((0x0001E000&(data))>>13)
#define  CP_CP_REG_SET_get_write_enable4(data)                                   ((0x00000800&(data))>>11)
#define  CP_CP_REG_SET_get_endian_swap(data)                                     ((0x00000400&(data))>>10)
#define  CP_CP_REG_SET_get_write_enable3(data)                                   ((0x00000200&(data))>>9)
#define  CP_CP_REG_SET_get_cw_logic_opsel(data)                                  ((0x00000180&(data))>>7)
#define  CP_CP_REG_SET_get_write_enable2(data)                                   ((0x00000040&(data))>>6)
#define  CP_CP_REG_SET_get_bcm(data)                                             ((0x00000030&(data))>>4)
#define  CP_CP_REG_SET_get_write_enable1(data)                                   ((0x00000008&(data))>>3)
#define  CP_CP_REG_SET_get_reg_first(data)                                       ((0x00000004&(data))>>2)
#define  CP_CP_REG_SET_get_write_enable0(data)                                   ((0x00000002&(data))>>1)
#define  CP_CP_REG_SET_get_reg_ende(data)                                        (0x00000001&(data))

#define  CP_CP_REG_SET1                                                          0x18015078
#define  CP_CP_REG_SET1_reg_addr                                                 "0xB8015078"
#define  CP_CP_REG_SET1_reg                                                      0xB8015078
#define  CP_CP_REG_SET1_inst_addr                                                "0x006E"
#define  set_CP_CP_REG_SET1_reg(data)                                            (*((volatile unsigned int*)CP_CP_REG_SET1_reg)=data)
#define  get_CP_CP_REG_SET1_reg                                                  (*((volatile unsigned int*)CP_CP_REG_SET1_reg))
#define  CP_CP_REG_SET1_key_mode_shift                                           (6)
#define  CP_CP_REG_SET1_iv_mode_shift                                            (4)
#define  CP_CP_REG_SET1_input_mode_shift                                         (2)
#define  CP_CP_REG_SET1_output_mode_shift                                        (0)
#define  CP_CP_REG_SET1_key_mode_mask                                            (0x000000C0)
#define  CP_CP_REG_SET1_iv_mode_mask                                             (0x00000030)
#define  CP_CP_REG_SET1_input_mode_mask                                          (0x0000000C)
#define  CP_CP_REG_SET1_output_mode_mask                                         (0x00000003)
#define  CP_CP_REG_SET1_key_mode(data)                                           (0x000000C0&((data)<<6))
#define  CP_CP_REG_SET1_iv_mode(data)                                            (0x00000030&((data)<<4))
#define  CP_CP_REG_SET1_input_mode(data)                                         (0x0000000C&((data)<<2))
#define  CP_CP_REG_SET1_output_mode(data)                                        (0x00000003&(data))
#define  CP_CP_REG_SET1_get_key_mode(data)                                       ((0x000000C0&(data))>>6)
#define  CP_CP_REG_SET1_get_iv_mode(data)                                        ((0x00000030&(data))>>4)
#define  CP_CP_REG_SET1_get_input_mode(data)                                     ((0x0000000C&(data))>>2)
#define  CP_CP_REG_SET1_get_output_mode(data)                                    (0x00000003&(data))

#define  CP_CP_REG_SET2                                                          0x1801507C
#define  CP_CP_REG_SET2_reg_addr                                                 "0xB801507C"
#define  CP_CP_REG_SET2_reg                                                      0xB801507C
#define  CP_CP_REG_SET2_inst_addr                                                "0x006F"
#define  set_CP_CP_REG_SET2_reg(data)                                            (*((volatile unsigned int*)CP_CP_REG_SET2_reg)=data)
#define  get_CP_CP_REG_SET2_reg                                                  (*((volatile unsigned int*)CP_CP_REG_SET2_reg))
#define  CP_CP_REG_SET2_output_entry_shift                                       (24)
#define  CP_CP_REG_SET2_input_entry_shift                                        (16)
#define  CP_CP_REG_SET2_key_entry_shift                                          (8)
#define  CP_CP_REG_SET2_iv_entry_shift                                           (0)
#define  CP_CP_REG_SET2_output_entry_mask                                        (0x7F000000)
#define  CP_CP_REG_SET2_input_entry_mask                                         (0x007F0000)
#define  CP_CP_REG_SET2_key_entry_mask                                           (0x00007F00)
#define  CP_CP_REG_SET2_iv_entry_mask                                            (0x0000007F)
#define  CP_CP_REG_SET2_output_entry(data)                                       (0x7F000000&((data)<<24))
#define  CP_CP_REG_SET2_input_entry(data)                                        (0x007F0000&((data)<<16))
#define  CP_CP_REG_SET2_key_entry(data)                                          (0x00007F00&((data)<<8))
#define  CP_CP_REG_SET2_iv_entry(data)                                           (0x0000007F&(data))
#define  CP_CP_REG_SET2_get_output_entry(data)                                   ((0x7F000000&(data))>>24)
#define  CP_CP_REG_SET2_get_input_entry(data)                                    ((0x007F0000&(data))>>16)
#define  CP_CP_REG_SET2_get_key_entry(data)                                      ((0x00007F00&(data))>>8)
#define  CP_CP_REG_SET2_get_iv_entry(data)                                       (0x0000007F&(data))

#define  CP_CP_SCTCH                                                             0x18015080
#define  CP_CP_SCTCH_reg_addr                                                    "0xB8015080"
#define  CP_CP_SCTCH_reg                                                         0xB8015080
#define  CP_CP_SCTCH_inst_addr                                                   "0x0070"
#define  set_CP_CP_SCTCH_reg(data)                                               (*((volatile unsigned int*)CP_CP_SCTCH_reg)=data)
#define  get_CP_CP_SCTCH_reg                                                     (*((volatile unsigned int*)CP_CP_SCTCH_reg))
#define  CP_CP_SCTCH_reg1_shift                                                  (16)
#define  CP_CP_SCTCH_reg0_shift                                                  (0)
#define  CP_CP_SCTCH_reg1_mask                                                   (0xFFFF0000)
#define  CP_CP_SCTCH_reg0_mask                                                   (0x0000FFFF)
#define  CP_CP_SCTCH_reg1(data)                                                  (0xFFFF0000&((data)<<16))
#define  CP_CP_SCTCH_reg0(data)                                                  (0x0000FFFF&(data))
#define  CP_CP_SCTCH_get_reg1(data)                                              ((0xFFFF0000&(data))>>16)
#define  CP_CP_SCTCH_get_reg0(data)                                              (0x0000FFFF&(data))

#define  CP_CP_NF_KEY_0                                                          0x18015084
#define  CP_CP_NF_KEY_0_reg_addr                                                 "0xB8015084"
#define  CP_CP_NF_KEY_0_reg                                                      0xB8015084
#define  CP_CP_NF_KEY_0_inst_addr                                                "0x0071"
#define  set_CP_CP_NF_KEY_0_reg(data)                                            (*((volatile unsigned int*)CP_CP_NF_KEY_0_reg)=data)
#define  get_CP_CP_NF_KEY_0_reg                                                  (*((volatile unsigned int*)CP_CP_NF_KEY_0_reg))
#define  CP_CP_NF_KEY_0_data_shift                                               (0)
#define  CP_CP_NF_KEY_0_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_NF_KEY_0_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_NF_KEY_0_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_NF_KEY_1                                                          0x18015088
#define  CP_CP_NF_KEY_1_reg_addr                                                 "0xB8015088"
#define  CP_CP_NF_KEY_1_reg                                                      0xB8015088
#define  CP_CP_NF_KEY_1_inst_addr                                                "0x0072"
#define  set_CP_CP_NF_KEY_1_reg(data)                                            (*((volatile unsigned int*)CP_CP_NF_KEY_1_reg)=data)
#define  get_CP_CP_NF_KEY_1_reg                                                  (*((volatile unsigned int*)CP_CP_NF_KEY_1_reg))
#define  CP_CP_NF_KEY_1_data_shift                                               (0)
#define  CP_CP_NF_KEY_1_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_NF_KEY_1_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_NF_KEY_1_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_NF_KEY_2                                                          0x1801508C
#define  CP_CP_NF_KEY_2_reg_addr                                                 "0xB801508C"
#define  CP_CP_NF_KEY_2_reg                                                      0xB801508C
#define  CP_CP_NF_KEY_2_inst_addr                                                "0x0073"
#define  set_CP_CP_NF_KEY_2_reg(data)                                            (*((volatile unsigned int*)CP_CP_NF_KEY_2_reg)=data)
#define  get_CP_CP_NF_KEY_2_reg                                                  (*((volatile unsigned int*)CP_CP_NF_KEY_2_reg))
#define  CP_CP_NF_KEY_2_data_shift                                               (0)
#define  CP_CP_NF_KEY_2_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_NF_KEY_2_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_NF_KEY_2_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_NF_KEY_3                                                          0x18015090
#define  CP_CP_NF_KEY_3_reg_addr                                                 "0xB8015090"
#define  CP_CP_NF_KEY_3_reg                                                      0xB8015090
#define  CP_CP_NF_KEY_3_inst_addr                                                "0x0074"
#define  set_CP_CP_NF_KEY_3_reg(data)                                            (*((volatile unsigned int*)CP_CP_NF_KEY_3_reg)=data)
#define  get_CP_CP_NF_KEY_3_reg                                                  (*((volatile unsigned int*)CP_CP_NF_KEY_3_reg))
#define  CP_CP_NF_KEY_3_data_shift                                               (0)
#define  CP_CP_NF_KEY_3_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_NF_KEY_3_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_NF_KEY_3_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_NF_KEY1_0                                                         0x18015220
#define  CP_CP_NF_KEY1_0_reg_addr                                                "0xB8015220"
#define  CP_CP_NF_KEY1_0_reg                                                     0xB8015220
#define  CP_CP_NF_KEY1_0_inst_addr                                               "0x0075"
#define  set_CP_CP_NF_KEY1_0_reg(data)                                           (*((volatile unsigned int*)CP_CP_NF_KEY1_0_reg)=data)
#define  get_CP_CP_NF_KEY1_0_reg                                                 (*((volatile unsigned int*)CP_CP_NF_KEY1_0_reg))
#define  CP_CP_NF_KEY1_0_data_shift                                              (0)
#define  CP_CP_NF_KEY1_0_data_mask                                               (0xFFFFFFFF)
#define  CP_CP_NF_KEY1_0_data(data)                                              (0xFFFFFFFF&(data))
#define  CP_CP_NF_KEY1_0_get_data(data)                                          (0xFFFFFFFF&(data))

#define  CP_CP_NF_KEY1_1                                                         0x18015224
#define  CP_CP_NF_KEY1_1_reg_addr                                                "0xB8015224"
#define  CP_CP_NF_KEY1_1_reg                                                     0xB8015224
#define  CP_CP_NF_KEY1_1_inst_addr                                               "0x0076"
#define  set_CP_CP_NF_KEY1_1_reg(data)                                           (*((volatile unsigned int*)CP_CP_NF_KEY1_1_reg)=data)
#define  get_CP_CP_NF_KEY1_1_reg                                                 (*((volatile unsigned int*)CP_CP_NF_KEY1_1_reg))
#define  CP_CP_NF_KEY1_1_data_shift                                              (0)
#define  CP_CP_NF_KEY1_1_data_mask                                               (0xFFFFFFFF)
#define  CP_CP_NF_KEY1_1_data(data)                                              (0xFFFFFFFF&(data))
#define  CP_CP_NF_KEY1_1_get_data(data)                                          (0xFFFFFFFF&(data))

#define  CP_CP_NF_KEY1_2                                                         0x18015228
#define  CP_CP_NF_KEY1_2_reg_addr                                                "0xB8015228"
#define  CP_CP_NF_KEY1_2_reg                                                     0xB8015228
#define  CP_CP_NF_KEY1_2_inst_addr                                               "0x0077"
#define  set_CP_CP_NF_KEY1_2_reg(data)                                           (*((volatile unsigned int*)CP_CP_NF_KEY1_2_reg)=data)
#define  get_CP_CP_NF_KEY1_2_reg                                                 (*((volatile unsigned int*)CP_CP_NF_KEY1_2_reg))
#define  CP_CP_NF_KEY1_2_data_shift                                              (0)
#define  CP_CP_NF_KEY1_2_data_mask                                               (0xFFFFFFFF)
#define  CP_CP_NF_KEY1_2_data(data)                                              (0xFFFFFFFF&(data))
#define  CP_CP_NF_KEY1_2_get_data(data)                                          (0xFFFFFFFF&(data))

#define  CP_CP_NF_KEY1_3                                                         0x1801522C
#define  CP_CP_NF_KEY1_3_reg_addr                                                "0xB801522C"
#define  CP_CP_NF_KEY1_3_reg                                                     0xB801522C
#define  CP_CP_NF_KEY1_3_inst_addr                                               "0x0078"
#define  set_CP_CP_NF_KEY1_3_reg(data)                                           (*((volatile unsigned int*)CP_CP_NF_KEY1_3_reg)=data)
#define  get_CP_CP_NF_KEY1_3_reg                                                 (*((volatile unsigned int*)CP_CP_NF_KEY1_3_reg))
#define  CP_CP_NF_KEY1_3_data_shift                                              (0)
#define  CP_CP_NF_KEY1_3_data_mask                                               (0xFFFFFFFF)
#define  CP_CP_NF_KEY1_3_data(data)                                              (0xFFFFFFFF&(data))
#define  CP_CP_NF_KEY1_3_get_data(data)                                          (0xFFFFFFFF&(data))

#define  CP_CP_NF_INI_KEY_0                                                      0x18015094
#define  CP_CP_NF_INI_KEY_0_reg_addr                                             "0xB8015094"
#define  CP_CP_NF_INI_KEY_0_reg                                                  0xB8015094
#define  CP_CP_NF_INI_KEY_0_inst_addr                                            "0x0079"
#define  set_CP_CP_NF_INI_KEY_0_reg(data)                                        (*((volatile unsigned int*)CP_CP_NF_INI_KEY_0_reg)=data)
#define  get_CP_CP_NF_INI_KEY_0_reg                                              (*((volatile unsigned int*)CP_CP_NF_INI_KEY_0_reg))
#define  CP_CP_NF_INI_KEY_0_data_shift                                           (0)
#define  CP_CP_NF_INI_KEY_0_data_mask                                            (0xFFFFFFFF)
#define  CP_CP_NF_INI_KEY_0_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_CP_NF_INI_KEY_0_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_CP_NF_INI_KEY_1                                                      0x18015098
#define  CP_CP_NF_INI_KEY_1_reg_addr                                             "0xB8015098"
#define  CP_CP_NF_INI_KEY_1_reg                                                  0xB8015098
#define  CP_CP_NF_INI_KEY_1_inst_addr                                            "0x007A"
#define  set_CP_CP_NF_INI_KEY_1_reg(data)                                        (*((volatile unsigned int*)CP_CP_NF_INI_KEY_1_reg)=data)
#define  get_CP_CP_NF_INI_KEY_1_reg                                              (*((volatile unsigned int*)CP_CP_NF_INI_KEY_1_reg))
#define  CP_CP_NF_INI_KEY_1_data_shift                                           (0)
#define  CP_CP_NF_INI_KEY_1_data_mask                                            (0xFFFFFFFF)
#define  CP_CP_NF_INI_KEY_1_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_CP_NF_INI_KEY_1_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_CP_NF_INI_KEY_2                                                      0x1801509C
#define  CP_CP_NF_INI_KEY_2_reg_addr                                             "0xB801509C"
#define  CP_CP_NF_INI_KEY_2_reg                                                  0xB801509C
#define  CP_CP_NF_INI_KEY_2_inst_addr                                            "0x007B"
#define  set_CP_CP_NF_INI_KEY_2_reg(data)                                        (*((volatile unsigned int*)CP_CP_NF_INI_KEY_2_reg)=data)
#define  get_CP_CP_NF_INI_KEY_2_reg                                              (*((volatile unsigned int*)CP_CP_NF_INI_KEY_2_reg))
#define  CP_CP_NF_INI_KEY_2_data_shift                                           (0)
#define  CP_CP_NF_INI_KEY_2_data_mask                                            (0xFFFFFFFF)
#define  CP_CP_NF_INI_KEY_2_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_CP_NF_INI_KEY_2_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_CP_NF_INI_KEY_3                                                      0x180150A0
#define  CP_CP_NF_INI_KEY_3_reg_addr                                             "0xB80150A0"
#define  CP_CP_NF_INI_KEY_3_reg                                                  0xB80150A0
#define  CP_CP_NF_INI_KEY_3_inst_addr                                            "0x007C"
#define  set_CP_CP_NF_INI_KEY_3_reg(data)                                        (*((volatile unsigned int*)CP_CP_NF_INI_KEY_3_reg)=data)
#define  get_CP_CP_NF_INI_KEY_3_reg                                              (*((volatile unsigned int*)CP_CP_NF_INI_KEY_3_reg))
#define  CP_CP_NF_INI_KEY_3_data_shift                                           (0)
#define  CP_CP_NF_INI_KEY_3_data_mask                                            (0xFFFFFFFF)
#define  CP_CP_NF_INI_KEY_3_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_CP_NF_INI_KEY_3_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_CP_NF_SET                                                            0x180150A4
#define  CP_CP_NF_SET_reg_addr                                                   "0xB80150A4"
#define  CP_CP_NF_SET_reg                                                        0xB80150A4
#define  CP_CP_NF_SET_inst_addr                                                  "0x007D"
#define  set_CP_CP_NF_SET_reg(data)                                              (*((volatile unsigned int*)CP_CP_NF_SET_reg)=data)
#define  get_CP_CP_NF_SET_reg                                                    (*((volatile unsigned int*)CP_CP_NF_SET_reg))
#define  CP_CP_NF_SET_key_length_shift                                           (11)
#define  CP_CP_NF_SET_bcm_shift                                                  (9)
#define  CP_CP_NF_SET_cw_entry_shift                                             (2)
#define  CP_CP_NF_SET_sel_shift                                                  (0)
#define  CP_CP_NF_SET_key_length_mask                                            (0x00001800)
#define  CP_CP_NF_SET_bcm_mask                                                   (0x00000600)
#define  CP_CP_NF_SET_cw_entry_mask                                              (0x000001FC)
#define  CP_CP_NF_SET_sel_mask                                                   (0x00000003)
#define  CP_CP_NF_SET_key_length(data)                                           (0x00001800&((data)<<11))
#define  CP_CP_NF_SET_bcm(data)                                                  (0x00000600&((data)<<9))
#define  CP_CP_NF_SET_cw_entry(data)                                             (0x000001FC&((data)<<2))
#define  CP_CP_NF_SET_sel(data)                                                  (0x00000003&(data))
#define  CP_CP_NF_SET_get_key_length(data)                                       ((0x00001800&(data))>>11)
#define  CP_CP_NF_SET_get_bcm(data)                                              ((0x00000600&(data))>>9)
#define  CP_CP_NF_SET_get_cw_entry(data)                                         ((0x000001FC&(data))>>2)
#define  CP_CP_NF_SET_get_sel(data)                                              (0x00000003&(data))

#define  CP_CP_NF_EMMC                                                           0x18015200
#define  CP_CP_NF_EMMC_reg_addr                                                  "0xB8015200"
#define  CP_CP_NF_EMMC_reg                                                       0xB8015200
#define  CP_CP_NF_EMMC_inst_addr                                                 "0x007E"
#define  set_CP_CP_NF_EMMC_reg(data)                                             (*((volatile unsigned int*)CP_CP_NF_EMMC_reg)=data)
#define  get_CP_CP_NF_EMMC_reg                                                   (*((volatile unsigned int*)CP_CP_NF_EMMC_reg))
#define  CP_CP_NF_EMMC_sel_shift                                                 (0)
#define  CP_CP_NF_EMMC_sel_mask                                                  (0x00000001)
#define  CP_CP_NF_EMMC_sel(data)                                                 (0x00000001&(data))
#define  CP_CP_NF_EMMC_get_sel(data)                                             (0x00000001&(data))

#define  CP_CP_MD_KEY_0                                                          0x180150A8
#define  CP_CP_MD_KEY_0_reg_addr                                                 "0xB80150A8"
#define  CP_CP_MD_KEY_0_reg                                                      0xB80150A8
#define  CP_CP_MD_KEY_0_inst_addr                                                "0x007F"
#define  set_CP_CP_MD_KEY_0_reg(data)                                            (*((volatile unsigned int*)CP_CP_MD_KEY_0_reg)=data)
#define  get_CP_CP_MD_KEY_0_reg                                                  (*((volatile unsigned int*)CP_CP_MD_KEY_0_reg))
#define  CP_CP_MD_KEY_0_data_shift                                               (0)
#define  CP_CP_MD_KEY_0_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_MD_KEY_0_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_MD_KEY_0_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_MD_KEY_1                                                          0x180150AC
#define  CP_CP_MD_KEY_1_reg_addr                                                 "0xB80150AC"
#define  CP_CP_MD_KEY_1_reg                                                      0xB80150AC
#define  CP_CP_MD_KEY_1_inst_addr                                                "0x0080"
#define  set_CP_CP_MD_KEY_1_reg(data)                                            (*((volatile unsigned int*)CP_CP_MD_KEY_1_reg)=data)
#define  get_CP_CP_MD_KEY_1_reg                                                  (*((volatile unsigned int*)CP_CP_MD_KEY_1_reg))
#define  CP_CP_MD_KEY_1_data_shift                                               (0)
#define  CP_CP_MD_KEY_1_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_MD_KEY_1_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_MD_KEY_1_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_MD_KEY_2                                                          0x180150B0
#define  CP_CP_MD_KEY_2_reg_addr                                                 "0xB80150B0"
#define  CP_CP_MD_KEY_2_reg                                                      0xB80150B0
#define  CP_CP_MD_KEY_2_inst_addr                                                "0x0081"
#define  set_CP_CP_MD_KEY_2_reg(data)                                            (*((volatile unsigned int*)CP_CP_MD_KEY_2_reg)=data)
#define  get_CP_CP_MD_KEY_2_reg                                                  (*((volatile unsigned int*)CP_CP_MD_KEY_2_reg))
#define  CP_CP_MD_KEY_2_data_shift                                               (0)
#define  CP_CP_MD_KEY_2_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_MD_KEY_2_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_MD_KEY_2_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_MD_KEY_3                                                          0x180150B4
#define  CP_CP_MD_KEY_3_reg_addr                                                 "0xB80150B4"
#define  CP_CP_MD_KEY_3_reg                                                      0xB80150B4
#define  CP_CP_MD_KEY_3_inst_addr                                                "0x0082"
#define  set_CP_CP_MD_KEY_3_reg(data)                                            (*((volatile unsigned int*)CP_CP_MD_KEY_3_reg)=data)
#define  get_CP_CP_MD_KEY_3_reg                                                  (*((volatile unsigned int*)CP_CP_MD_KEY_3_reg))
#define  CP_CP_MD_KEY_3_data_shift                                               (0)
#define  CP_CP_MD_KEY_3_data_mask                                                (0xFFFFFFFF)
#define  CP_CP_MD_KEY_3_data(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_MD_KEY_3_get_data(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_MD_KEY1_0                                                         0x18015230
#define  CP_CP_MD_KEY1_0_reg_addr                                                "0xB8015230"
#define  CP_CP_MD_KEY1_0_reg                                                     0xB8015230
#define  CP_CP_MD_KEY1_0_inst_addr                                               "0x0083"
#define  set_CP_CP_MD_KEY1_0_reg(data)                                           (*((volatile unsigned int*)CP_CP_MD_KEY1_0_reg)=data)
#define  get_CP_CP_MD_KEY1_0_reg                                                 (*((volatile unsigned int*)CP_CP_MD_KEY1_0_reg))
#define  CP_CP_MD_KEY1_0_data_shift                                              (0)
#define  CP_CP_MD_KEY1_0_data_mask                                               (0xFFFFFFFF)
#define  CP_CP_MD_KEY1_0_data(data)                                              (0xFFFFFFFF&(data))
#define  CP_CP_MD_KEY1_0_get_data(data)                                          (0xFFFFFFFF&(data))

#define  CP_CP_MD_KEY1_1                                                         0x18015234
#define  CP_CP_MD_KEY1_1_reg_addr                                                "0xB8015234"
#define  CP_CP_MD_KEY1_1_reg                                                     0xB8015234
#define  CP_CP_MD_KEY1_1_inst_addr                                               "0x0084"
#define  set_CP_CP_MD_KEY1_1_reg(data)                                           (*((volatile unsigned int*)CP_CP_MD_KEY1_1_reg)=data)
#define  get_CP_CP_MD_KEY1_1_reg                                                 (*((volatile unsigned int*)CP_CP_MD_KEY1_1_reg))
#define  CP_CP_MD_KEY1_1_data_shift                                              (0)
#define  CP_CP_MD_KEY1_1_data_mask                                               (0xFFFFFFFF)
#define  CP_CP_MD_KEY1_1_data(data)                                              (0xFFFFFFFF&(data))
#define  CP_CP_MD_KEY1_1_get_data(data)                                          (0xFFFFFFFF&(data))

#define  CP_CP_MD_KEY1_2                                                         0x18015238
#define  CP_CP_MD_KEY1_2_reg_addr                                                "0xB8015238"
#define  CP_CP_MD_KEY1_2_reg                                                     0xB8015238
#define  CP_CP_MD_KEY1_2_inst_addr                                               "0x0085"
#define  set_CP_CP_MD_KEY1_2_reg(data)                                           (*((volatile unsigned int*)CP_CP_MD_KEY1_2_reg)=data)
#define  get_CP_CP_MD_KEY1_2_reg                                                 (*((volatile unsigned int*)CP_CP_MD_KEY1_2_reg))
#define  CP_CP_MD_KEY1_2_data_shift                                              (0)
#define  CP_CP_MD_KEY1_2_data_mask                                               (0xFFFFFFFF)
#define  CP_CP_MD_KEY1_2_data(data)                                              (0xFFFFFFFF&(data))
#define  CP_CP_MD_KEY1_2_get_data(data)                                          (0xFFFFFFFF&(data))

#define  CP_CP_MD_KEY1_3                                                         0x1801523C
#define  CP_CP_MD_KEY1_3_reg_addr                                                "0xB801523C"
#define  CP_CP_MD_KEY1_3_reg                                                     0xB801523C
#define  CP_CP_MD_KEY1_3_inst_addr                                               "0x0086"
#define  set_CP_CP_MD_KEY1_3_reg(data)                                           (*((volatile unsigned int*)CP_CP_MD_KEY1_3_reg)=data)
#define  get_CP_CP_MD_KEY1_3_reg                                                 (*((volatile unsigned int*)CP_CP_MD_KEY1_3_reg))
#define  CP_CP_MD_KEY1_3_data_shift                                              (0)
#define  CP_CP_MD_KEY1_3_data_mask                                               (0xFFFFFFFF)
#define  CP_CP_MD_KEY1_3_data(data)                                              (0xFFFFFFFF&(data))
#define  CP_CP_MD_KEY1_3_get_data(data)                                          (0xFFFFFFFF&(data))

#define  CP_CP_MD_INI_KEY_0                                                      0x180150B8
#define  CP_CP_MD_INI_KEY_0_reg_addr                                             "0xB80150B8"
#define  CP_CP_MD_INI_KEY_0_reg                                                  0xB80150B8
#define  CP_CP_MD_INI_KEY_0_inst_addr                                            "0x0087"
#define  set_CP_CP_MD_INI_KEY_0_reg(data)                                        (*((volatile unsigned int*)CP_CP_MD_INI_KEY_0_reg)=data)
#define  get_CP_CP_MD_INI_KEY_0_reg                                              (*((volatile unsigned int*)CP_CP_MD_INI_KEY_0_reg))
#define  CP_CP_MD_INI_KEY_0_data_shift                                           (0)
#define  CP_CP_MD_INI_KEY_0_data_mask                                            (0xFFFFFFFF)
#define  CP_CP_MD_INI_KEY_0_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_CP_MD_INI_KEY_0_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_CP_MD_INI_KEY_1                                                      0x180150BC
#define  CP_CP_MD_INI_KEY_1_reg_addr                                             "0xB80150BC"
#define  CP_CP_MD_INI_KEY_1_reg                                                  0xB80150BC
#define  CP_CP_MD_INI_KEY_1_inst_addr                                            "0x0088"
#define  set_CP_CP_MD_INI_KEY_1_reg(data)                                        (*((volatile unsigned int*)CP_CP_MD_INI_KEY_1_reg)=data)
#define  get_CP_CP_MD_INI_KEY_1_reg                                              (*((volatile unsigned int*)CP_CP_MD_INI_KEY_1_reg))
#define  CP_CP_MD_INI_KEY_1_data_shift                                           (0)
#define  CP_CP_MD_INI_KEY_1_data_mask                                            (0xFFFFFFFF)
#define  CP_CP_MD_INI_KEY_1_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_CP_MD_INI_KEY_1_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_CP_MD_INI_KEY_2                                                      0x180150C0
#define  CP_CP_MD_INI_KEY_2_reg_addr                                             "0xB80150C0"
#define  CP_CP_MD_INI_KEY_2_reg                                                  0xB80150C0
#define  CP_CP_MD_INI_KEY_2_inst_addr                                            "0x0089"
#define  set_CP_CP_MD_INI_KEY_2_reg(data)                                        (*((volatile unsigned int*)CP_CP_MD_INI_KEY_2_reg)=data)
#define  get_CP_CP_MD_INI_KEY_2_reg                                              (*((volatile unsigned int*)CP_CP_MD_INI_KEY_2_reg))
#define  CP_CP_MD_INI_KEY_2_data_shift                                           (0)
#define  CP_CP_MD_INI_KEY_2_data_mask                                            (0xFFFFFFFF)
#define  CP_CP_MD_INI_KEY_2_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_CP_MD_INI_KEY_2_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_CP_MD_INI_KEY_3                                                      0x180150C4
#define  CP_CP_MD_INI_KEY_3_reg_addr                                             "0xB80150C4"
#define  CP_CP_MD_INI_KEY_3_reg                                                  0xB80150C4
#define  CP_CP_MD_INI_KEY_3_inst_addr                                            "0x008A"
#define  set_CP_CP_MD_INI_KEY_3_reg(data)                                        (*((volatile unsigned int*)CP_CP_MD_INI_KEY_3_reg)=data)
#define  get_CP_CP_MD_INI_KEY_3_reg                                              (*((volatile unsigned int*)CP_CP_MD_INI_KEY_3_reg))
#define  CP_CP_MD_INI_KEY_3_data_shift                                           (0)
#define  CP_CP_MD_INI_KEY_3_data_mask                                            (0xFFFFFFFF)
#define  CP_CP_MD_INI_KEY_3_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_CP_MD_INI_KEY_3_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_CP_MD_SET                                                            0x180150C8
#define  CP_CP_MD_SET_reg_addr                                                   "0xB80150C8"
#define  CP_CP_MD_SET_reg                                                        0xB80150C8
#define  CP_CP_MD_SET_inst_addr                                                  "0x008B"
#define  set_CP_CP_MD_SET_reg(data)                                              (*((volatile unsigned int*)CP_CP_MD_SET_reg)=data)
#define  get_CP_CP_MD_SET_reg                                                    (*((volatile unsigned int*)CP_CP_MD_SET_reg))
#define  CP_CP_MD_SET_key_length_shift                                           (11)
#define  CP_CP_MD_SET_bcm_shift                                                  (9)
#define  CP_CP_MD_SET_cw_entry_shift                                             (2)
#define  CP_CP_MD_SET_sel_shift                                                  (0)
#define  CP_CP_MD_SET_key_length_mask                                            (0x00001800)
#define  CP_CP_MD_SET_bcm_mask                                                   (0x00000600)
#define  CP_CP_MD_SET_cw_entry_mask                                              (0x000001FC)
#define  CP_CP_MD_SET_sel_mask                                                   (0x00000003)
#define  CP_CP_MD_SET_key_length(data)                                           (0x00001800&((data)<<11))
#define  CP_CP_MD_SET_bcm(data)                                                  (0x00000600&((data)<<9))
#define  CP_CP_MD_SET_cw_entry(data)                                             (0x000001FC&((data)<<2))
#define  CP_CP_MD_SET_sel(data)                                                  (0x00000003&(data))
#define  CP_CP_MD_SET_get_key_length(data)                                       ((0x00001800&(data))>>11)
#define  CP_CP_MD_SET_get_bcm(data)                                              ((0x00000600&(data))>>9)
#define  CP_CP_MD_SET_get_cw_entry(data)                                         ((0x000001FC&(data))>>2)
#define  CP_CP_MD_SET_get_sel(data)                                              (0x00000003&(data))

#define  CP_K_CP_REG_SEMAPHORE                                                   0x18015830
#define  CP_K_CP_REG_SEMAPHORE_reg_addr                                          "0xB8015830"
#define  CP_K_CP_REG_SEMAPHORE_reg                                               0xB8015830
#define  CP_K_CP_REG_SEMAPHORE_inst_addr                                         "0x008C"
#define  set_CP_K_CP_REG_SEMAPHORE_reg(data)                                     (*((volatile unsigned int*)CP_K_CP_REG_SEMAPHORE_reg)=data)
#define  get_CP_K_CP_REG_SEMAPHORE_reg                                           (*((volatile unsigned int*)CP_K_CP_REG_SEMAPHORE_reg))
#define  CP_K_CP_REG_SEMAPHORE_semaphore_shift                                   (0)
#define  CP_K_CP_REG_SEMAPHORE_semaphore_mask                                    (0x00000001)
#define  CP_K_CP_REG_SEMAPHORE_semaphore(data)                                   (0x00000001&(data))
#define  CP_K_CP_REG_SEMAPHORE_get_semaphore(data)                               (0x00000001&(data))

#define  CP_K_CP_REG_KEY_0                                                       0x18015834
#define  CP_K_CP_REG_KEY_0_reg_addr                                              "0xB8015834"
#define  CP_K_CP_REG_KEY_0_reg                                                   0xB8015834
#define  CP_K_CP_REG_KEY_0_inst_addr                                             "0x008D"
#define  set_CP_K_CP_REG_KEY_0_reg(data)                                         (*((volatile unsigned int*)CP_K_CP_REG_KEY_0_reg)=data)
#define  get_CP_K_CP_REG_KEY_0_reg                                               (*((volatile unsigned int*)CP_K_CP_REG_KEY_0_reg))
#define  CP_K_CP_REG_KEY_0_data_shift                                            (0)
#define  CP_K_CP_REG_KEY_0_data_mask                                             (0xFFFFFFFF)
#define  CP_K_CP_REG_KEY_0_data(data)                                            (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_KEY_0_get_data(data)                                        (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_KEY_1                                                       0x18015838
#define  CP_K_CP_REG_KEY_1_reg_addr                                              "0xB8015838"
#define  CP_K_CP_REG_KEY_1_reg                                                   0xB8015838
#define  CP_K_CP_REG_KEY_1_inst_addr                                             "0x008E"
#define  set_CP_K_CP_REG_KEY_1_reg(data)                                         (*((volatile unsigned int*)CP_K_CP_REG_KEY_1_reg)=data)
#define  get_CP_K_CP_REG_KEY_1_reg                                               (*((volatile unsigned int*)CP_K_CP_REG_KEY_1_reg))
#define  CP_K_CP_REG_KEY_1_data_shift                                            (0)
#define  CP_K_CP_REG_KEY_1_data_mask                                             (0xFFFFFFFF)
#define  CP_K_CP_REG_KEY_1_data(data)                                            (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_KEY_1_get_data(data)                                        (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_KEY_2                                                       0x1801583C
#define  CP_K_CP_REG_KEY_2_reg_addr                                              "0xB801583C"
#define  CP_K_CP_REG_KEY_2_reg                                                   0xB801583C
#define  CP_K_CP_REG_KEY_2_inst_addr                                             "0x008F"
#define  set_CP_K_CP_REG_KEY_2_reg(data)                                         (*((volatile unsigned int*)CP_K_CP_REG_KEY_2_reg)=data)
#define  get_CP_K_CP_REG_KEY_2_reg                                               (*((volatile unsigned int*)CP_K_CP_REG_KEY_2_reg))
#define  CP_K_CP_REG_KEY_2_data_shift                                            (0)
#define  CP_K_CP_REG_KEY_2_data_mask                                             (0xFFFFFFFF)
#define  CP_K_CP_REG_KEY_2_data(data)                                            (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_KEY_2_get_data(data)                                        (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_KEY_3                                                       0x18015840
#define  CP_K_CP_REG_KEY_3_reg_addr                                              "0xB8015840"
#define  CP_K_CP_REG_KEY_3_reg                                                   0xB8015840
#define  CP_K_CP_REG_KEY_3_inst_addr                                             "0x0090"
#define  set_CP_K_CP_REG_KEY_3_reg(data)                                         (*((volatile unsigned int*)CP_K_CP_REG_KEY_3_reg)=data)
#define  get_CP_K_CP_REG_KEY_3_reg                                               (*((volatile unsigned int*)CP_K_CP_REG_KEY_3_reg))
#define  CP_K_CP_REG_KEY_3_data_shift                                            (0)
#define  CP_K_CP_REG_KEY_3_data_mask                                             (0xFFFFFFFF)
#define  CP_K_CP_REG_KEY_3_data(data)                                            (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_KEY_3_get_data(data)                                        (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_KEY1_0                                                      0x18015A10
#define  CP_K_CP_REG_KEY1_0_reg_addr                                             "0xB8015A10"
#define  CP_K_CP_REG_KEY1_0_reg                                                  0xB8015A10
#define  CP_K_CP_REG_KEY1_0_inst_addr                                            "0x0091"
#define  set_CP_K_CP_REG_KEY1_0_reg(data)                                        (*((volatile unsigned int*)CP_K_CP_REG_KEY1_0_reg)=data)
#define  get_CP_K_CP_REG_KEY1_0_reg                                              (*((volatile unsigned int*)CP_K_CP_REG_KEY1_0_reg))
#define  CP_K_CP_REG_KEY1_0_data_shift                                           (0)
#define  CP_K_CP_REG_KEY1_0_data_mask                                            (0xFFFFFFFF)
#define  CP_K_CP_REG_KEY1_0_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_KEY1_0_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_KEY1_1                                                      0x18015A14
#define  CP_K_CP_REG_KEY1_1_reg_addr                                             "0xB8015A14"
#define  CP_K_CP_REG_KEY1_1_reg                                                  0xB8015A14
#define  CP_K_CP_REG_KEY1_1_inst_addr                                            "0x0092"
#define  set_CP_K_CP_REG_KEY1_1_reg(data)                                        (*((volatile unsigned int*)CP_K_CP_REG_KEY1_1_reg)=data)
#define  get_CP_K_CP_REG_KEY1_1_reg                                              (*((volatile unsigned int*)CP_K_CP_REG_KEY1_1_reg))
#define  CP_K_CP_REG_KEY1_1_data_shift                                           (0)
#define  CP_K_CP_REG_KEY1_1_data_mask                                            (0xFFFFFFFF)
#define  CP_K_CP_REG_KEY1_1_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_KEY1_1_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_KEY1_2                                                      0x18015A18
#define  CP_K_CP_REG_KEY1_2_reg_addr                                             "0xB8015A18"
#define  CP_K_CP_REG_KEY1_2_reg                                                  0xB8015A18
#define  CP_K_CP_REG_KEY1_2_inst_addr                                            "0x0093"
#define  set_CP_K_CP_REG_KEY1_2_reg(data)                                        (*((volatile unsigned int*)CP_K_CP_REG_KEY1_2_reg)=data)
#define  get_CP_K_CP_REG_KEY1_2_reg                                              (*((volatile unsigned int*)CP_K_CP_REG_KEY1_2_reg))
#define  CP_K_CP_REG_KEY1_2_data_shift                                           (0)
#define  CP_K_CP_REG_KEY1_2_data_mask                                            (0xFFFFFFFF)
#define  CP_K_CP_REG_KEY1_2_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_KEY1_2_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_KEY1_3                                                      0x18015A1C
#define  CP_K_CP_REG_KEY1_3_reg_addr                                             "0xB8015A1C"
#define  CP_K_CP_REG_KEY1_3_reg                                                  0xB8015A1C
#define  CP_K_CP_REG_KEY1_3_inst_addr                                            "0x0094"
#define  set_CP_K_CP_REG_KEY1_3_reg(data)                                        (*((volatile unsigned int*)CP_K_CP_REG_KEY1_3_reg)=data)
#define  get_CP_K_CP_REG_KEY1_3_reg                                              (*((volatile unsigned int*)CP_K_CP_REG_KEY1_3_reg))
#define  CP_K_CP_REG_KEY1_3_data_shift                                           (0)
#define  CP_K_CP_REG_KEY1_3_data_mask                                            (0xFFFFFFFF)
#define  CP_K_CP_REG_KEY1_3_data(data)                                           (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_KEY1_3_get_data(data)                                       (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_DATAIN_0                                                    0x18015844
#define  CP_K_CP_REG_DATAIN_0_reg_addr                                           "0xB8015844"
#define  CP_K_CP_REG_DATAIN_0_reg                                                0xB8015844
#define  CP_K_CP_REG_DATAIN_0_inst_addr                                          "0x0095"
#define  set_CP_K_CP_REG_DATAIN_0_reg(data)                                      (*((volatile unsigned int*)CP_K_CP_REG_DATAIN_0_reg)=data)
#define  get_CP_K_CP_REG_DATAIN_0_reg                                            (*((volatile unsigned int*)CP_K_CP_REG_DATAIN_0_reg))
#define  CP_K_CP_REG_DATAIN_0_data_shift                                         (0)
#define  CP_K_CP_REG_DATAIN_0_data_mask                                          (0xFFFFFFFF)
#define  CP_K_CP_REG_DATAIN_0_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_DATAIN_0_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_DATAIN_1                                                    0x18015848
#define  CP_K_CP_REG_DATAIN_1_reg_addr                                           "0xB8015848"
#define  CP_K_CP_REG_DATAIN_1_reg                                                0xB8015848
#define  CP_K_CP_REG_DATAIN_1_inst_addr                                          "0x0096"
#define  set_CP_K_CP_REG_DATAIN_1_reg(data)                                      (*((volatile unsigned int*)CP_K_CP_REG_DATAIN_1_reg)=data)
#define  get_CP_K_CP_REG_DATAIN_1_reg                                            (*((volatile unsigned int*)CP_K_CP_REG_DATAIN_1_reg))
#define  CP_K_CP_REG_DATAIN_1_data_shift                                         (0)
#define  CP_K_CP_REG_DATAIN_1_data_mask                                          (0xFFFFFFFF)
#define  CP_K_CP_REG_DATAIN_1_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_DATAIN_1_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_DATAIN_2                                                    0x1801584C
#define  CP_K_CP_REG_DATAIN_2_reg_addr                                           "0xB801584C"
#define  CP_K_CP_REG_DATAIN_2_reg                                                0xB801584C
#define  CP_K_CP_REG_DATAIN_2_inst_addr                                          "0x0097"
#define  set_CP_K_CP_REG_DATAIN_2_reg(data)                                      (*((volatile unsigned int*)CP_K_CP_REG_DATAIN_2_reg)=data)
#define  get_CP_K_CP_REG_DATAIN_2_reg                                            (*((volatile unsigned int*)CP_K_CP_REG_DATAIN_2_reg))
#define  CP_K_CP_REG_DATAIN_2_data_shift                                         (0)
#define  CP_K_CP_REG_DATAIN_2_data_mask                                          (0xFFFFFFFF)
#define  CP_K_CP_REG_DATAIN_2_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_DATAIN_2_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_DATAIN_3                                                    0x18015850
#define  CP_K_CP_REG_DATAIN_3_reg_addr                                           "0xB8015850"
#define  CP_K_CP_REG_DATAIN_3_reg                                                0xB8015850
#define  CP_K_CP_REG_DATAIN_3_inst_addr                                          "0x0098"
#define  set_CP_K_CP_REG_DATAIN_3_reg(data)                                      (*((volatile unsigned int*)CP_K_CP_REG_DATAIN_3_reg)=data)
#define  get_CP_K_CP_REG_DATAIN_3_reg                                            (*((volatile unsigned int*)CP_K_CP_REG_DATAIN_3_reg))
#define  CP_K_CP_REG_DATAIN_3_data_shift                                         (0)
#define  CP_K_CP_REG_DATAIN_3_data_mask                                          (0xFFFFFFFF)
#define  CP_K_CP_REG_DATAIN_3_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_DATAIN_3_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_DATAOUT_0                                                   0x18015854
#define  CP_K_CP_REG_DATAOUT_0_reg_addr                                          "0xB8015854"
#define  CP_K_CP_REG_DATAOUT_0_reg                                               0xB8015854
#define  CP_K_CP_REG_DATAOUT_0_inst_addr                                         "0x0099"
#define  set_CP_K_CP_REG_DATAOUT_0_reg(data)                                     (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_0_reg)=data)
#define  get_CP_K_CP_REG_DATAOUT_0_reg                                           (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_0_reg))
#define  CP_K_CP_REG_DATAOUT_0_data_shift                                        (0)
#define  CP_K_CP_REG_DATAOUT_0_data_mask                                         (0xFFFFFFFF)
#define  CP_K_CP_REG_DATAOUT_0_data(data)                                        (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_DATAOUT_0_get_data(data)                                    (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_DATAOUT_1                                                   0x18015858
#define  CP_K_CP_REG_DATAOUT_1_reg_addr                                          "0xB8015858"
#define  CP_K_CP_REG_DATAOUT_1_reg                                               0xB8015858
#define  CP_K_CP_REG_DATAOUT_1_inst_addr                                         "0x009A"
#define  set_CP_K_CP_REG_DATAOUT_1_reg(data)                                     (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_1_reg)=data)
#define  get_CP_K_CP_REG_DATAOUT_1_reg                                           (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_1_reg))
#define  CP_K_CP_REG_DATAOUT_1_data_shift                                        (0)
#define  CP_K_CP_REG_DATAOUT_1_data_mask                                         (0xFFFFFFFF)
#define  CP_K_CP_REG_DATAOUT_1_data(data)                                        (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_DATAOUT_1_get_data(data)                                    (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_DATAOUT_2                                                   0x1801585C
#define  CP_K_CP_REG_DATAOUT_2_reg_addr                                          "0xB801585C"
#define  CP_K_CP_REG_DATAOUT_2_reg                                               0xB801585C
#define  CP_K_CP_REG_DATAOUT_2_inst_addr                                         "0x009B"
#define  set_CP_K_CP_REG_DATAOUT_2_reg(data)                                     (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_2_reg)=data)
#define  get_CP_K_CP_REG_DATAOUT_2_reg                                           (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_2_reg))
#define  CP_K_CP_REG_DATAOUT_2_data_shift                                        (0)
#define  CP_K_CP_REG_DATAOUT_2_data_mask                                         (0xFFFFFFFF)
#define  CP_K_CP_REG_DATAOUT_2_data(data)                                        (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_DATAOUT_2_get_data(data)                                    (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_DATAOUT_3                                                   0x18015860
#define  CP_K_CP_REG_DATAOUT_3_reg_addr                                          "0xB8015860"
#define  CP_K_CP_REG_DATAOUT_3_reg                                               0xB8015860
#define  CP_K_CP_REG_DATAOUT_3_inst_addr                                         "0x009C"
#define  set_CP_K_CP_REG_DATAOUT_3_reg(data)                                     (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_3_reg)=data)
#define  get_CP_K_CP_REG_DATAOUT_3_reg                                           (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_3_reg))
#define  CP_K_CP_REG_DATAOUT_3_data_shift                                        (0)
#define  CP_K_CP_REG_DATAOUT_3_data_mask                                         (0xFFFFFFFF)
#define  CP_K_CP_REG_DATAOUT_3_data(data)                                        (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_DATAOUT_3_get_data(data)                                    (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_DATAOUT_4                                                   0x18015864
#define  CP_K_CP_REG_DATAOUT_4_reg_addr                                          "0xB8015864"
#define  CP_K_CP_REG_DATAOUT_4_reg                                               0xB8015864
#define  CP_K_CP_REG_DATAOUT_4_inst_addr                                         "0x009D"
#define  set_CP_K_CP_REG_DATAOUT_4_reg(data)                                     (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_4_reg)=data)
#define  get_CP_K_CP_REG_DATAOUT_4_reg                                           (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_4_reg))
#define  CP_K_CP_REG_DATAOUT_4_data_shift                                        (0)
#define  CP_K_CP_REG_DATAOUT_4_data_mask                                         (0xFFFFFFFF)
#define  CP_K_CP_REG_DATAOUT_4_data(data)                                        (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_DATAOUT_4_get_data(data)                                    (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_DATAOUT_5                                                   0x18015868
#define  CP_K_CP_REG_DATAOUT_5_reg_addr                                          "0xB8015868"
#define  CP_K_CP_REG_DATAOUT_5_reg                                               0xB8015868
#define  CP_K_CP_REG_DATAOUT_5_inst_addr                                         "0x009E"
#define  set_CP_K_CP_REG_DATAOUT_5_reg(data)                                     (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_5_reg)=data)
#define  get_CP_K_CP_REG_DATAOUT_5_reg                                           (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_5_reg))
#define  CP_K_CP_REG_DATAOUT_5_data_shift                                        (0)
#define  CP_K_CP_REG_DATAOUT_5_data_mask                                         (0xFFFFFFFF)
#define  CP_K_CP_REG_DATAOUT_5_data(data)                                        (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_DATAOUT_5_get_data(data)                                    (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_DATAOUT_6                                                   0x1801586C
#define  CP_K_CP_REG_DATAOUT_6_reg_addr                                          "0xB801586C"
#define  CP_K_CP_REG_DATAOUT_6_reg                                               0xB801586C
#define  CP_K_CP_REG_DATAOUT_6_inst_addr                                         "0x009F"
#define  set_CP_K_CP_REG_DATAOUT_6_reg(data)                                     (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_6_reg)=data)
#define  get_CP_K_CP_REG_DATAOUT_6_reg                                           (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_6_reg))
#define  CP_K_CP_REG_DATAOUT_6_data_shift                                        (0)
#define  CP_K_CP_REG_DATAOUT_6_data_mask                                         (0xFFFFFFFF)
#define  CP_K_CP_REG_DATAOUT_6_data(data)                                        (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_DATAOUT_6_get_data(data)                                    (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_DATAOUT_7                                                   0x18015870
#define  CP_K_CP_REG_DATAOUT_7_reg_addr                                          "0xB8015870"
#define  CP_K_CP_REG_DATAOUT_7_reg                                               0xB8015870
#define  CP_K_CP_REG_DATAOUT_7_inst_addr                                         "0x00A0"
#define  set_CP_K_CP_REG_DATAOUT_7_reg(data)                                     (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_7_reg)=data)
#define  get_CP_K_CP_REG_DATAOUT_7_reg                                           (*((volatile unsigned int*)CP_K_CP_REG_DATAOUT_7_reg))
#define  CP_K_CP_REG_DATAOUT_7_data_shift                                        (0)
#define  CP_K_CP_REG_DATAOUT_7_data_mask                                         (0xFFFFFFFF)
#define  CP_K_CP_REG_DATAOUT_7_data(data)                                        (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_DATAOUT_7_get_data(data)                                    (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_IV_0                                                        0x180158D0
#define  CP_K_CP_REG_IV_0_reg_addr                                               "0xB80158D0"
#define  CP_K_CP_REG_IV_0_reg                                                    0xB80158D0
#define  CP_K_CP_REG_IV_0_inst_addr                                              "0x00A1"
#define  set_CP_K_CP_REG_IV_0_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_REG_IV_0_reg)=data)
#define  get_CP_K_CP_REG_IV_0_reg                                                (*((volatile unsigned int*)CP_K_CP_REG_IV_0_reg))
#define  CP_K_CP_REG_IV_0_data_shift                                             (0)
#define  CP_K_CP_REG_IV_0_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_REG_IV_0_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_IV_0_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_IV_1                                                        0x180158D4
#define  CP_K_CP_REG_IV_1_reg_addr                                               "0xB80158D4"
#define  CP_K_CP_REG_IV_1_reg                                                    0xB80158D4
#define  CP_K_CP_REG_IV_1_inst_addr                                              "0x00A2"
#define  set_CP_K_CP_REG_IV_1_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_REG_IV_1_reg)=data)
#define  get_CP_K_CP_REG_IV_1_reg                                                (*((volatile unsigned int*)CP_K_CP_REG_IV_1_reg))
#define  CP_K_CP_REG_IV_1_data_shift                                             (0)
#define  CP_K_CP_REG_IV_1_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_REG_IV_1_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_IV_1_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_IV_2                                                        0x180158D8
#define  CP_K_CP_REG_IV_2_reg_addr                                               "0xB80158D8"
#define  CP_K_CP_REG_IV_2_reg                                                    0xB80158D8
#define  CP_K_CP_REG_IV_2_inst_addr                                              "0x00A3"
#define  set_CP_K_CP_REG_IV_2_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_REG_IV_2_reg)=data)
#define  get_CP_K_CP_REG_IV_2_reg                                                (*((volatile unsigned int*)CP_K_CP_REG_IV_2_reg))
#define  CP_K_CP_REG_IV_2_data_shift                                             (0)
#define  CP_K_CP_REG_IV_2_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_REG_IV_2_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_IV_2_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_IV_3                                                        0x180158DC
#define  CP_K_CP_REG_IV_3_reg_addr                                               "0xB80158DC"
#define  CP_K_CP_REG_IV_3_reg                                                    0xB80158DC
#define  CP_K_CP_REG_IV_3_inst_addr                                              "0x00A4"
#define  set_CP_K_CP_REG_IV_3_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_REG_IV_3_reg)=data)
#define  get_CP_K_CP_REG_IV_3_reg                                                (*((volatile unsigned int*)CP_K_CP_REG_IV_3_reg))
#define  CP_K_CP_REG_IV_3_data_shift                                             (0)
#define  CP_K_CP_REG_IV_3_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_REG_IV_3_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_IV_3_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_IV_4                                                        0x180158E0
#define  CP_K_CP_REG_IV_4_reg_addr                                               "0xB80158E0"
#define  CP_K_CP_REG_IV_4_reg                                                    0xB80158E0
#define  CP_K_CP_REG_IV_4_inst_addr                                              "0x00A5"
#define  set_CP_K_CP_REG_IV_4_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_REG_IV_4_reg)=data)
#define  get_CP_K_CP_REG_IV_4_reg                                                (*((volatile unsigned int*)CP_K_CP_REG_IV_4_reg))
#define  CP_K_CP_REG_IV_4_data_shift                                             (0)
#define  CP_K_CP_REG_IV_4_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_REG_IV_4_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_IV_4_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_IV_5                                                        0x180158E4
#define  CP_K_CP_REG_IV_5_reg_addr                                               "0xB80158E4"
#define  CP_K_CP_REG_IV_5_reg                                                    0xB80158E4
#define  CP_K_CP_REG_IV_5_inst_addr                                              "0x00A6"
#define  set_CP_K_CP_REG_IV_5_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_REG_IV_5_reg)=data)
#define  get_CP_K_CP_REG_IV_5_reg                                                (*((volatile unsigned int*)CP_K_CP_REG_IV_5_reg))
#define  CP_K_CP_REG_IV_5_data_shift                                             (0)
#define  CP_K_CP_REG_IV_5_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_REG_IV_5_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_IV_5_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_IV_6                                                        0x180158E8
#define  CP_K_CP_REG_IV_6_reg_addr                                               "0xB80158E8"
#define  CP_K_CP_REG_IV_6_reg                                                    0xB80158E8
#define  CP_K_CP_REG_IV_6_inst_addr                                              "0x00A7"
#define  set_CP_K_CP_REG_IV_6_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_REG_IV_6_reg)=data)
#define  get_CP_K_CP_REG_IV_6_reg                                                (*((volatile unsigned int*)CP_K_CP_REG_IV_6_reg))
#define  CP_K_CP_REG_IV_6_data_shift                                             (0)
#define  CP_K_CP_REG_IV_6_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_REG_IV_6_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_IV_6_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_IV_7                                                        0x180158EC
#define  CP_K_CP_REG_IV_7_reg_addr                                               "0xB80158EC"
#define  CP_K_CP_REG_IV_7_reg                                                    0xB80158EC
#define  CP_K_CP_REG_IV_7_inst_addr                                              "0x00A8"
#define  set_CP_K_CP_REG_IV_7_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_REG_IV_7_reg)=data)
#define  get_CP_K_CP_REG_IV_7_reg                                                (*((volatile unsigned int*)CP_K_CP_REG_IV_7_reg))
#define  CP_K_CP_REG_IV_7_data_shift                                             (0)
#define  CP_K_CP_REG_IV_7_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_REG_IV_7_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_REG_IV_7_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_REG_SET                                                         0x18015874
#define  CP_K_CP_REG_SET_reg_addr                                                "0xB8015874"
#define  CP_K_CP_REG_SET_reg                                                     0xB8015874
#define  CP_K_CP_REG_SET_inst_addr                                               "0x00A9"
#define  set_CP_K_CP_REG_SET_reg(data)                                           (*((volatile unsigned int*)CP_K_CP_REG_SET_reg)=data)
#define  get_CP_K_CP_REG_SET_reg                                                 (*((volatile unsigned int*)CP_K_CP_REG_SET_reg))
#define  CP_K_CP_REG_SET_write_enable5_shift                                     (17)
#define  CP_K_CP_REG_SET_mode_shift                                              (13)
#define  CP_K_CP_REG_SET_write_enable4_shift                                     (11)
#define  CP_K_CP_REG_SET_endian_swap_shift                                       (10)
#define  CP_K_CP_REG_SET_write_enable3_shift                                     (9)
#define  CP_K_CP_REG_SET_cw_logic_opsel_shift                                    (7)
#define  CP_K_CP_REG_SET_write_enable2_shift                                     (6)
#define  CP_K_CP_REG_SET_bcm_shift                                               (4)
#define  CP_K_CP_REG_SET_write_enable1_shift                                     (3)
#define  CP_K_CP_REG_SET_reg_first_shift                                         (2)
#define  CP_K_CP_REG_SET_write_enable0_shift                                     (1)
#define  CP_K_CP_REG_SET_reg_ende_shift                                          (0)
#define  CP_K_CP_REG_SET_write_enable5_mask                                      (0x00020000)
#define  CP_K_CP_REG_SET_mode_mask                                               (0x0001E000)
#define  CP_K_CP_REG_SET_write_enable4_mask                                      (0x00000800)
#define  CP_K_CP_REG_SET_endian_swap_mask                                        (0x00000400)
#define  CP_K_CP_REG_SET_write_enable3_mask                                      (0x00000200)
#define  CP_K_CP_REG_SET_cw_logic_opsel_mask                                     (0x00000180)
#define  CP_K_CP_REG_SET_write_enable2_mask                                      (0x00000040)
#define  CP_K_CP_REG_SET_bcm_mask                                                (0x00000030)
#define  CP_K_CP_REG_SET_write_enable1_mask                                      (0x00000008)
#define  CP_K_CP_REG_SET_reg_first_mask                                          (0x00000004)
#define  CP_K_CP_REG_SET_write_enable0_mask                                      (0x00000002)
#define  CP_K_CP_REG_SET_reg_ende_mask                                           (0x00000001)
#define  CP_K_CP_REG_SET_write_enable5(data)                                     (0x00020000&((data)<<17))
#define  CP_K_CP_REG_SET_mode(data)                                              (0x0001E000&((data)<<13))
#define  CP_K_CP_REG_SET_write_enable4(data)                                     (0x00000800&((data)<<11))
#define  CP_K_CP_REG_SET_endian_swap(data)                                       (0x00000400&((data)<<10))
#define  CP_K_CP_REG_SET_write_enable3(data)                                     (0x00000200&((data)<<9))
#define  CP_K_CP_REG_SET_cw_logic_opsel(data)                                    (0x00000180&((data)<<7))
#define  CP_K_CP_REG_SET_write_enable2(data)                                     (0x00000040&((data)<<6))
#define  CP_K_CP_REG_SET_bcm(data)                                               (0x00000030&((data)<<4))
#define  CP_K_CP_REG_SET_write_enable1(data)                                     (0x00000008&((data)<<3))
#define  CP_K_CP_REG_SET_reg_first(data)                                         (0x00000004&((data)<<2))
#define  CP_K_CP_REG_SET_write_enable0(data)                                     (0x00000002&((data)<<1))
#define  CP_K_CP_REG_SET_reg_ende(data)                                          (0x00000001&(data))
#define  CP_K_CP_REG_SET_get_write_enable5(data)                                 ((0x00020000&(data))>>17)
#define  CP_K_CP_REG_SET_get_mode(data)                                          ((0x0001E000&(data))>>13)
#define  CP_K_CP_REG_SET_get_write_enable4(data)                                 ((0x00000800&(data))>>11)
#define  CP_K_CP_REG_SET_get_endian_swap(data)                                   ((0x00000400&(data))>>10)
#define  CP_K_CP_REG_SET_get_write_enable3(data)                                 ((0x00000200&(data))>>9)
#define  CP_K_CP_REG_SET_get_cw_logic_opsel(data)                                ((0x00000180&(data))>>7)
#define  CP_K_CP_REG_SET_get_write_enable2(data)                                 ((0x00000040&(data))>>6)
#define  CP_K_CP_REG_SET_get_bcm(data)                                           ((0x00000030&(data))>>4)
#define  CP_K_CP_REG_SET_get_write_enable1(data)                                 ((0x00000008&(data))>>3)
#define  CP_K_CP_REG_SET_get_reg_first(data)                                     ((0x00000004&(data))>>2)
#define  CP_K_CP_REG_SET_get_write_enable0(data)                                 ((0x00000002&(data))>>1)
#define  CP_K_CP_REG_SET_get_reg_ende(data)                                      (0x00000001&(data))

#define  CP_K_CP_REG_SET1                                                        0x18015878
#define  CP_K_CP_REG_SET1_reg_addr                                               "0xB8015878"
#define  CP_K_CP_REG_SET1_reg                                                    0xB8015878
#define  CP_K_CP_REG_SET1_inst_addr                                              "0x00AA"
#define  set_CP_K_CP_REG_SET1_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_REG_SET1_reg)=data)
#define  get_CP_K_CP_REG_SET1_reg                                                (*((volatile unsigned int*)CP_K_CP_REG_SET1_reg))
#define  CP_K_CP_REG_SET1_key_mode_shift                                         (6)
#define  CP_K_CP_REG_SET1_iv_mode_shift                                          (4)
#define  CP_K_CP_REG_SET1_input_mode_shift                                       (2)
#define  CP_K_CP_REG_SET1_output_mode_shift                                      (0)
#define  CP_K_CP_REG_SET1_key_mode_mask                                          (0x000001C0)
#define  CP_K_CP_REG_SET1_iv_mode_mask                                           (0x00000030)
#define  CP_K_CP_REG_SET1_input_mode_mask                                        (0x0000000C)
#define  CP_K_CP_REG_SET1_output_mode_mask                                       (0x00000003)
#define  CP_K_CP_REG_SET1_key_mode(data)                                         (0x000001C0&((data)<<6))
#define  CP_K_CP_REG_SET1_iv_mode(data)                                          (0x00000030&((data)<<4))
#define  CP_K_CP_REG_SET1_input_mode(data)                                       (0x0000000C&((data)<<2))
#define  CP_K_CP_REG_SET1_output_mode(data)                                      (0x00000003&(data))
#define  CP_K_CP_REG_SET1_get_key_mode(data)                                     ((0x000001C0&(data))>>6)
#define  CP_K_CP_REG_SET1_get_iv_mode(data)                                      ((0x00000030&(data))>>4)
#define  CP_K_CP_REG_SET1_get_input_mode(data)                                   ((0x0000000C&(data))>>2)
#define  CP_K_CP_REG_SET1_get_output_mode(data)                                  (0x00000003&(data))

#define  CP_K_CP_REG_SET2                                                        0x1801587C
#define  CP_K_CP_REG_SET2_reg_addr                                               "0xB801587C"
#define  CP_K_CP_REG_SET2_reg                                                    0xB801587C
#define  CP_K_CP_REG_SET2_inst_addr                                              "0x00AB"
#define  set_CP_K_CP_REG_SET2_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_REG_SET2_reg)=data)
#define  get_CP_K_CP_REG_SET2_reg                                                (*((volatile unsigned int*)CP_K_CP_REG_SET2_reg))
#define  CP_K_CP_REG_SET2_output_entry_shift                                     (24)
#define  CP_K_CP_REG_SET2_input_entry_shift                                      (16)
#define  CP_K_CP_REG_SET2_key_entry_shift                                        (8)
#define  CP_K_CP_REG_SET2_iv_entry_shift                                         (0)
#define  CP_K_CP_REG_SET2_output_entry_mask                                      (0x7F000000)
#define  CP_K_CP_REG_SET2_input_entry_mask                                       (0x007F0000)
#define  CP_K_CP_REG_SET2_key_entry_mask                                         (0x00007F00)
#define  CP_K_CP_REG_SET2_iv_entry_mask                                          (0x0000007F)
#define  CP_K_CP_REG_SET2_output_entry(data)                                     (0x7F000000&((data)<<24))
#define  CP_K_CP_REG_SET2_input_entry(data)                                      (0x007F0000&((data)<<16))
#define  CP_K_CP_REG_SET2_key_entry(data)                                        (0x00007F00&((data)<<8))
#define  CP_K_CP_REG_SET2_iv_entry(data)                                         (0x0000007F&(data))
#define  CP_K_CP_REG_SET2_get_output_entry(data)                                 ((0x7F000000&(data))>>24)
#define  CP_K_CP_REG_SET2_get_input_entry(data)                                  ((0x007F0000&(data))>>16)
#define  CP_K_CP_REG_SET2_get_key_entry(data)                                    ((0x00007F00&(data))>>8)
#define  CP_K_CP_REG_SET2_get_iv_entry(data)                                     (0x0000007F&(data))

#define  CP_K_CP_NF_KEY_0                                                        0x18015884
#define  CP_K_CP_NF_KEY_0_reg_addr                                               "0xB8015884"
#define  CP_K_CP_NF_KEY_0_reg                                                    0xB8015884
#define  CP_K_CP_NF_KEY_0_inst_addr                                              "0x00AC"
#define  set_CP_K_CP_NF_KEY_0_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_NF_KEY_0_reg)=data)
#define  get_CP_K_CP_NF_KEY_0_reg                                                (*((volatile unsigned int*)CP_K_CP_NF_KEY_0_reg))
#define  CP_K_CP_NF_KEY_0_data_shift                                             (0)
#define  CP_K_CP_NF_KEY_0_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_NF_KEY_0_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_NF_KEY_0_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_NF_KEY_1                                                        0x18015888
#define  CP_K_CP_NF_KEY_1_reg_addr                                               "0xB8015888"
#define  CP_K_CP_NF_KEY_1_reg                                                    0xB8015888
#define  CP_K_CP_NF_KEY_1_inst_addr                                              "0x00AD"
#define  set_CP_K_CP_NF_KEY_1_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_NF_KEY_1_reg)=data)
#define  get_CP_K_CP_NF_KEY_1_reg                                                (*((volatile unsigned int*)CP_K_CP_NF_KEY_1_reg))
#define  CP_K_CP_NF_KEY_1_data_shift                                             (0)
#define  CP_K_CP_NF_KEY_1_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_NF_KEY_1_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_NF_KEY_1_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_NF_KEY_2                                                        0x1801588C
#define  CP_K_CP_NF_KEY_2_reg_addr                                               "0xB801588C"
#define  CP_K_CP_NF_KEY_2_reg                                                    0xB801588C
#define  CP_K_CP_NF_KEY_2_inst_addr                                              "0x00AE"
#define  set_CP_K_CP_NF_KEY_2_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_NF_KEY_2_reg)=data)
#define  get_CP_K_CP_NF_KEY_2_reg                                                (*((volatile unsigned int*)CP_K_CP_NF_KEY_2_reg))
#define  CP_K_CP_NF_KEY_2_data_shift                                             (0)
#define  CP_K_CP_NF_KEY_2_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_NF_KEY_2_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_NF_KEY_2_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_NF_KEY_3                                                        0x18015890
#define  CP_K_CP_NF_KEY_3_reg_addr                                               "0xB8015890"
#define  CP_K_CP_NF_KEY_3_reg                                                    0xB8015890
#define  CP_K_CP_NF_KEY_3_inst_addr                                              "0x00AF"
#define  set_CP_K_CP_NF_KEY_3_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_NF_KEY_3_reg)=data)
#define  get_CP_K_CP_NF_KEY_3_reg                                                (*((volatile unsigned int*)CP_K_CP_NF_KEY_3_reg))
#define  CP_K_CP_NF_KEY_3_data_shift                                             (0)
#define  CP_K_CP_NF_KEY_3_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_NF_KEY_3_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_NF_KEY_3_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_NF_KEY1_0                                                       0x18015A20
#define  CP_K_CP_NF_KEY1_0_reg_addr                                              "0xB8015A20"
#define  CP_K_CP_NF_KEY1_0_reg                                                   0xB8015A20
#define  CP_K_CP_NF_KEY1_0_inst_addr                                             "0x00B0"
#define  set_CP_K_CP_NF_KEY1_0_reg(data)                                         (*((volatile unsigned int*)CP_K_CP_NF_KEY1_0_reg)=data)
#define  get_CP_K_CP_NF_KEY1_0_reg                                               (*((volatile unsigned int*)CP_K_CP_NF_KEY1_0_reg))
#define  CP_K_CP_NF_KEY1_0_data_shift                                            (0)
#define  CP_K_CP_NF_KEY1_0_data_mask                                             (0xFFFFFFFF)
#define  CP_K_CP_NF_KEY1_0_data(data)                                            (0xFFFFFFFF&(data))
#define  CP_K_CP_NF_KEY1_0_get_data(data)                                        (0xFFFFFFFF&(data))

#define  CP_K_CP_NF_KEY1_1                                                       0x18015A24
#define  CP_K_CP_NF_KEY1_1_reg_addr                                              "0xB8015A24"
#define  CP_K_CP_NF_KEY1_1_reg                                                   0xB8015A24
#define  CP_K_CP_NF_KEY1_1_inst_addr                                             "0x00B1"
#define  set_CP_K_CP_NF_KEY1_1_reg(data)                                         (*((volatile unsigned int*)CP_K_CP_NF_KEY1_1_reg)=data)
#define  get_CP_K_CP_NF_KEY1_1_reg                                               (*((volatile unsigned int*)CP_K_CP_NF_KEY1_1_reg))
#define  CP_K_CP_NF_KEY1_1_data_shift                                            (0)
#define  CP_K_CP_NF_KEY1_1_data_mask                                             (0xFFFFFFFF)
#define  CP_K_CP_NF_KEY1_1_data(data)                                            (0xFFFFFFFF&(data))
#define  CP_K_CP_NF_KEY1_1_get_data(data)                                        (0xFFFFFFFF&(data))

#define  CP_K_CP_NF_KEY1_2                                                       0x18015A28
#define  CP_K_CP_NF_KEY1_2_reg_addr                                              "0xB8015A28"
#define  CP_K_CP_NF_KEY1_2_reg                                                   0xB8015A28
#define  CP_K_CP_NF_KEY1_2_inst_addr                                             "0x00B2"
#define  set_CP_K_CP_NF_KEY1_2_reg(data)                                         (*((volatile unsigned int*)CP_K_CP_NF_KEY1_2_reg)=data)
#define  get_CP_K_CP_NF_KEY1_2_reg                                               (*((volatile unsigned int*)CP_K_CP_NF_KEY1_2_reg))
#define  CP_K_CP_NF_KEY1_2_data_shift                                            (0)
#define  CP_K_CP_NF_KEY1_2_data_mask                                             (0xFFFFFFFF)
#define  CP_K_CP_NF_KEY1_2_data(data)                                            (0xFFFFFFFF&(data))
#define  CP_K_CP_NF_KEY1_2_get_data(data)                                        (0xFFFFFFFF&(data))

#define  CP_K_CP_NF_KEY1_3                                                       0x18015A2C
#define  CP_K_CP_NF_KEY1_3_reg_addr                                              "0xB8015A2C"
#define  CP_K_CP_NF_KEY1_3_reg                                                   0xB8015A2C
#define  CP_K_CP_NF_KEY1_3_inst_addr                                             "0x00B3"
#define  set_CP_K_CP_NF_KEY1_3_reg(data)                                         (*((volatile unsigned int*)CP_K_CP_NF_KEY1_3_reg)=data)
#define  get_CP_K_CP_NF_KEY1_3_reg                                               (*((volatile unsigned int*)CP_K_CP_NF_KEY1_3_reg))
#define  CP_K_CP_NF_KEY1_3_data_shift                                            (0)
#define  CP_K_CP_NF_KEY1_3_data_mask                                             (0xFFFFFFFF)
#define  CP_K_CP_NF_KEY1_3_data(data)                                            (0xFFFFFFFF&(data))
#define  CP_K_CP_NF_KEY1_3_get_data(data)                                        (0xFFFFFFFF&(data))

#define  CP_K_CP_NF_INI_KEY_0                                                    0x18015894
#define  CP_K_CP_NF_INI_KEY_0_reg_addr                                           "0xB8015894"
#define  CP_K_CP_NF_INI_KEY_0_reg                                                0xB8015894
#define  CP_K_CP_NF_INI_KEY_0_inst_addr                                          "0x00B4"
#define  set_CP_K_CP_NF_INI_KEY_0_reg(data)                                      (*((volatile unsigned int*)CP_K_CP_NF_INI_KEY_0_reg)=data)
#define  get_CP_K_CP_NF_INI_KEY_0_reg                                            (*((volatile unsigned int*)CP_K_CP_NF_INI_KEY_0_reg))
#define  CP_K_CP_NF_INI_KEY_0_data_shift                                         (0)
#define  CP_K_CP_NF_INI_KEY_0_data_mask                                          (0xFFFFFFFF)
#define  CP_K_CP_NF_INI_KEY_0_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_K_CP_NF_INI_KEY_0_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_K_CP_NF_INI_KEY_1                                                    0x18015898
#define  CP_K_CP_NF_INI_KEY_1_reg_addr                                           "0xB8015898"
#define  CP_K_CP_NF_INI_KEY_1_reg                                                0xB8015898
#define  CP_K_CP_NF_INI_KEY_1_inst_addr                                          "0x00B5"
#define  set_CP_K_CP_NF_INI_KEY_1_reg(data)                                      (*((volatile unsigned int*)CP_K_CP_NF_INI_KEY_1_reg)=data)
#define  get_CP_K_CP_NF_INI_KEY_1_reg                                            (*((volatile unsigned int*)CP_K_CP_NF_INI_KEY_1_reg))
#define  CP_K_CP_NF_INI_KEY_1_data_shift                                         (0)
#define  CP_K_CP_NF_INI_KEY_1_data_mask                                          (0xFFFFFFFF)
#define  CP_K_CP_NF_INI_KEY_1_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_K_CP_NF_INI_KEY_1_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_K_CP_NF_INI_KEY_2                                                    0x1801589C
#define  CP_K_CP_NF_INI_KEY_2_reg_addr                                           "0xB801589C"
#define  CP_K_CP_NF_INI_KEY_2_reg                                                0xB801589C
#define  CP_K_CP_NF_INI_KEY_2_inst_addr                                          "0x00B6"
#define  set_CP_K_CP_NF_INI_KEY_2_reg(data)                                      (*((volatile unsigned int*)CP_K_CP_NF_INI_KEY_2_reg)=data)
#define  get_CP_K_CP_NF_INI_KEY_2_reg                                            (*((volatile unsigned int*)CP_K_CP_NF_INI_KEY_2_reg))
#define  CP_K_CP_NF_INI_KEY_2_data_shift                                         (0)
#define  CP_K_CP_NF_INI_KEY_2_data_mask                                          (0xFFFFFFFF)
#define  CP_K_CP_NF_INI_KEY_2_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_K_CP_NF_INI_KEY_2_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_K_CP_NF_INI_KEY_3                                                    0x180158A0
#define  CP_K_CP_NF_INI_KEY_3_reg_addr                                           "0xB80158A0"
#define  CP_K_CP_NF_INI_KEY_3_reg                                                0xB80158A0
#define  CP_K_CP_NF_INI_KEY_3_inst_addr                                          "0x00B7"
#define  set_CP_K_CP_NF_INI_KEY_3_reg(data)                                      (*((volatile unsigned int*)CP_K_CP_NF_INI_KEY_3_reg)=data)
#define  get_CP_K_CP_NF_INI_KEY_3_reg                                            (*((volatile unsigned int*)CP_K_CP_NF_INI_KEY_3_reg))
#define  CP_K_CP_NF_INI_KEY_3_data_shift                                         (0)
#define  CP_K_CP_NF_INI_KEY_3_data_mask                                          (0xFFFFFFFF)
#define  CP_K_CP_NF_INI_KEY_3_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_K_CP_NF_INI_KEY_3_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_K_CP_NF_SET                                                          0x180158A4
#define  CP_K_CP_NF_SET_reg_addr                                                 "0xB80158A4"
#define  CP_K_CP_NF_SET_reg                                                      0xB80158A4
#define  CP_K_CP_NF_SET_inst_addr                                                "0x00B8"
#define  set_CP_K_CP_NF_SET_reg(data)                                            (*((volatile unsigned int*)CP_K_CP_NF_SET_reg)=data)
#define  get_CP_K_CP_NF_SET_reg                                                  (*((volatile unsigned int*)CP_K_CP_NF_SET_reg))
#define  CP_K_CP_NF_SET_key_length_shift                                         (11)
#define  CP_K_CP_NF_SET_bcm_shift                                                (9)
#define  CP_K_CP_NF_SET_cw_entry_shift                                           (2)
#define  CP_K_CP_NF_SET_sel_shift                                                (0)
#define  CP_K_CP_NF_SET_key_length_mask                                          (0x00001800)
#define  CP_K_CP_NF_SET_bcm_mask                                                 (0x00000600)
#define  CP_K_CP_NF_SET_cw_entry_mask                                            (0x000001FC)
#define  CP_K_CP_NF_SET_sel_mask                                                 (0x00000003)
#define  CP_K_CP_NF_SET_key_length(data)                                         (0x00001800&((data)<<11))
#define  CP_K_CP_NF_SET_bcm(data)                                                (0x00000600&((data)<<9))
#define  CP_K_CP_NF_SET_cw_entry(data)                                           (0x000001FC&((data)<<2))
#define  CP_K_CP_NF_SET_sel(data)                                                (0x00000003&(data))
#define  CP_K_CP_NF_SET_get_key_length(data)                                     ((0x00001800&(data))>>11)
#define  CP_K_CP_NF_SET_get_bcm(data)                                            ((0x00000600&(data))>>9)
#define  CP_K_CP_NF_SET_get_cw_entry(data)                                       ((0x000001FC&(data))>>2)
#define  CP_K_CP_NF_SET_get_sel(data)                                            (0x00000003&(data))

#define  CP_K_CP_MD_KEY_0                                                        0x180158A8
#define  CP_K_CP_MD_KEY_0_reg_addr                                               "0xB80158A8"
#define  CP_K_CP_MD_KEY_0_reg                                                    0xB80158A8
#define  CP_K_CP_MD_KEY_0_inst_addr                                              "0x00B9"
#define  set_CP_K_CP_MD_KEY_0_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_MD_KEY_0_reg)=data)
#define  get_CP_K_CP_MD_KEY_0_reg                                                (*((volatile unsigned int*)CP_K_CP_MD_KEY_0_reg))
#define  CP_K_CP_MD_KEY_0_data_shift                                             (0)
#define  CP_K_CP_MD_KEY_0_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_MD_KEY_0_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_MD_KEY_0_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_MD_KEY_1                                                        0x180158AC
#define  CP_K_CP_MD_KEY_1_reg_addr                                               "0xB80158AC"
#define  CP_K_CP_MD_KEY_1_reg                                                    0xB80158AC
#define  CP_K_CP_MD_KEY_1_inst_addr                                              "0x00BA"
#define  set_CP_K_CP_MD_KEY_1_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_MD_KEY_1_reg)=data)
#define  get_CP_K_CP_MD_KEY_1_reg                                                (*((volatile unsigned int*)CP_K_CP_MD_KEY_1_reg))
#define  CP_K_CP_MD_KEY_1_data_shift                                             (0)
#define  CP_K_CP_MD_KEY_1_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_MD_KEY_1_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_MD_KEY_1_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_MD_KEY_2                                                        0x180158B0
#define  CP_K_CP_MD_KEY_2_reg_addr                                               "0xB80158B0"
#define  CP_K_CP_MD_KEY_2_reg                                                    0xB80158B0
#define  CP_K_CP_MD_KEY_2_inst_addr                                              "0x00BB"
#define  set_CP_K_CP_MD_KEY_2_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_MD_KEY_2_reg)=data)
#define  get_CP_K_CP_MD_KEY_2_reg                                                (*((volatile unsigned int*)CP_K_CP_MD_KEY_2_reg))
#define  CP_K_CP_MD_KEY_2_data_shift                                             (0)
#define  CP_K_CP_MD_KEY_2_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_MD_KEY_2_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_MD_KEY_2_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_MD_KEY_3                                                        0x180158B4
#define  CP_K_CP_MD_KEY_3_reg_addr                                               "0xB80158B4"
#define  CP_K_CP_MD_KEY_3_reg                                                    0xB80158B4
#define  CP_K_CP_MD_KEY_3_inst_addr                                              "0x00BC"
#define  set_CP_K_CP_MD_KEY_3_reg(data)                                          (*((volatile unsigned int*)CP_K_CP_MD_KEY_3_reg)=data)
#define  get_CP_K_CP_MD_KEY_3_reg                                                (*((volatile unsigned int*)CP_K_CP_MD_KEY_3_reg))
#define  CP_K_CP_MD_KEY_3_data_shift                                             (0)
#define  CP_K_CP_MD_KEY_3_data_mask                                              (0xFFFFFFFF)
#define  CP_K_CP_MD_KEY_3_data(data)                                             (0xFFFFFFFF&(data))
#define  CP_K_CP_MD_KEY_3_get_data(data)                                         (0xFFFFFFFF&(data))

#define  CP_K_CP_MD_KEY1_0                                                       0x18015A30
#define  CP_K_CP_MD_KEY1_0_reg_addr                                              "0xB8015A30"
#define  CP_K_CP_MD_KEY1_0_reg                                                   0xB8015A30
#define  CP_K_CP_MD_KEY1_0_inst_addr                                             "0x00BD"
#define  set_CP_K_CP_MD_KEY1_0_reg(data)                                         (*((volatile unsigned int*)CP_K_CP_MD_KEY1_0_reg)=data)
#define  get_CP_K_CP_MD_KEY1_0_reg                                               (*((volatile unsigned int*)CP_K_CP_MD_KEY1_0_reg))
#define  CP_K_CP_MD_KEY1_0_data_shift                                            (0)
#define  CP_K_CP_MD_KEY1_0_data_mask                                             (0xFFFFFFFF)
#define  CP_K_CP_MD_KEY1_0_data(data)                                            (0xFFFFFFFF&(data))
#define  CP_K_CP_MD_KEY1_0_get_data(data)                                        (0xFFFFFFFF&(data))

#define  CP_K_CP_MD_KEY1_1                                                       0x18015A34
#define  CP_K_CP_MD_KEY1_1_reg_addr                                              "0xB8015A34"
#define  CP_K_CP_MD_KEY1_1_reg                                                   0xB8015A34
#define  CP_K_CP_MD_KEY1_1_inst_addr                                             "0x00BE"
#define  set_CP_K_CP_MD_KEY1_1_reg(data)                                         (*((volatile unsigned int*)CP_K_CP_MD_KEY1_1_reg)=data)
#define  get_CP_K_CP_MD_KEY1_1_reg                                               (*((volatile unsigned int*)CP_K_CP_MD_KEY1_1_reg))
#define  CP_K_CP_MD_KEY1_1_data_shift                                            (0)
#define  CP_K_CP_MD_KEY1_1_data_mask                                             (0xFFFFFFFF)
#define  CP_K_CP_MD_KEY1_1_data(data)                                            (0xFFFFFFFF&(data))
#define  CP_K_CP_MD_KEY1_1_get_data(data)                                        (0xFFFFFFFF&(data))

#define  CP_K_CP_MD_KEY1_2                                                       0x18015A38
#define  CP_K_CP_MD_KEY1_2_reg_addr                                              "0xB8015A38"
#define  CP_K_CP_MD_KEY1_2_reg                                                   0xB8015A38
#define  CP_K_CP_MD_KEY1_2_inst_addr                                             "0x00BF"
#define  set_CP_K_CP_MD_KEY1_2_reg(data)                                         (*((volatile unsigned int*)CP_K_CP_MD_KEY1_2_reg)=data)
#define  get_CP_K_CP_MD_KEY1_2_reg                                               (*((volatile unsigned int*)CP_K_CP_MD_KEY1_2_reg))
#define  CP_K_CP_MD_KEY1_2_data_shift                                            (0)
#define  CP_K_CP_MD_KEY1_2_data_mask                                             (0xFFFFFFFF)
#define  CP_K_CP_MD_KEY1_2_data(data)                                            (0xFFFFFFFF&(data))
#define  CP_K_CP_MD_KEY1_2_get_data(data)                                        (0xFFFFFFFF&(data))

#define  CP_K_CP_MD_KEY1_3                                                       0x18015A3C
#define  CP_K_CP_MD_KEY1_3_reg_addr                                              "0xB8015A3C"
#define  CP_K_CP_MD_KEY1_3_reg                                                   0xB8015A3C
#define  CP_K_CP_MD_KEY1_3_inst_addr                                             "0x00C0"
#define  set_CP_K_CP_MD_KEY1_3_reg(data)                                         (*((volatile unsigned int*)CP_K_CP_MD_KEY1_3_reg)=data)
#define  get_CP_K_CP_MD_KEY1_3_reg                                               (*((volatile unsigned int*)CP_K_CP_MD_KEY1_3_reg))
#define  CP_K_CP_MD_KEY1_3_data_shift                                            (0)
#define  CP_K_CP_MD_KEY1_3_data_mask                                             (0xFFFFFFFF)
#define  CP_K_CP_MD_KEY1_3_data(data)                                            (0xFFFFFFFF&(data))
#define  CP_K_CP_MD_KEY1_3_get_data(data)                                        (0xFFFFFFFF&(data))

#define  CP_K_CP_MD_INI_KEY_0                                                    0x180158B8
#define  CP_K_CP_MD_INI_KEY_0_reg_addr                                           "0xB80158B8"
#define  CP_K_CP_MD_INI_KEY_0_reg                                                0xB80158B8
#define  CP_K_CP_MD_INI_KEY_0_inst_addr                                          "0x00C1"
#define  set_CP_K_CP_MD_INI_KEY_0_reg(data)                                      (*((volatile unsigned int*)CP_K_CP_MD_INI_KEY_0_reg)=data)
#define  get_CP_K_CP_MD_INI_KEY_0_reg                                            (*((volatile unsigned int*)CP_K_CP_MD_INI_KEY_0_reg))
#define  CP_K_CP_MD_INI_KEY_0_data_shift                                         (0)
#define  CP_K_CP_MD_INI_KEY_0_data_mask                                          (0xFFFFFFFF)
#define  CP_K_CP_MD_INI_KEY_0_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_K_CP_MD_INI_KEY_0_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_K_CP_MD_INI_KEY_1                                                    0x180158BC
#define  CP_K_CP_MD_INI_KEY_1_reg_addr                                           "0xB80158BC"
#define  CP_K_CP_MD_INI_KEY_1_reg                                                0xB80158BC
#define  CP_K_CP_MD_INI_KEY_1_inst_addr                                          "0x00C2"
#define  set_CP_K_CP_MD_INI_KEY_1_reg(data)                                      (*((volatile unsigned int*)CP_K_CP_MD_INI_KEY_1_reg)=data)
#define  get_CP_K_CP_MD_INI_KEY_1_reg                                            (*((volatile unsigned int*)CP_K_CP_MD_INI_KEY_1_reg))
#define  CP_K_CP_MD_INI_KEY_1_data_shift                                         (0)
#define  CP_K_CP_MD_INI_KEY_1_data_mask                                          (0xFFFFFFFF)
#define  CP_K_CP_MD_INI_KEY_1_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_K_CP_MD_INI_KEY_1_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_K_CP_MD_INI_KEY_2                                                    0x180158C0
#define  CP_K_CP_MD_INI_KEY_2_reg_addr                                           "0xB80158C0"
#define  CP_K_CP_MD_INI_KEY_2_reg                                                0xB80158C0
#define  CP_K_CP_MD_INI_KEY_2_inst_addr                                          "0x00C3"
#define  set_CP_K_CP_MD_INI_KEY_2_reg(data)                                      (*((volatile unsigned int*)CP_K_CP_MD_INI_KEY_2_reg)=data)
#define  get_CP_K_CP_MD_INI_KEY_2_reg                                            (*((volatile unsigned int*)CP_K_CP_MD_INI_KEY_2_reg))
#define  CP_K_CP_MD_INI_KEY_2_data_shift                                         (0)
#define  CP_K_CP_MD_INI_KEY_2_data_mask                                          (0xFFFFFFFF)
#define  CP_K_CP_MD_INI_KEY_2_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_K_CP_MD_INI_KEY_2_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_K_CP_MD_INI_KEY_3                                                    0x180158C4
#define  CP_K_CP_MD_INI_KEY_3_reg_addr                                           "0xB80158C4"
#define  CP_K_CP_MD_INI_KEY_3_reg                                                0xB80158C4
#define  CP_K_CP_MD_INI_KEY_3_inst_addr                                          "0x00C4"
#define  set_CP_K_CP_MD_INI_KEY_3_reg(data)                                      (*((volatile unsigned int*)CP_K_CP_MD_INI_KEY_3_reg)=data)
#define  get_CP_K_CP_MD_INI_KEY_3_reg                                            (*((volatile unsigned int*)CP_K_CP_MD_INI_KEY_3_reg))
#define  CP_K_CP_MD_INI_KEY_3_data_shift                                         (0)
#define  CP_K_CP_MD_INI_KEY_3_data_mask                                          (0xFFFFFFFF)
#define  CP_K_CP_MD_INI_KEY_3_data(data)                                         (0xFFFFFFFF&(data))
#define  CP_K_CP_MD_INI_KEY_3_get_data(data)                                     (0xFFFFFFFF&(data))

#define  CP_K_CP_MD_SET                                                          0x180158C8
#define  CP_K_CP_MD_SET_reg_addr                                                 "0xB80158C8"
#define  CP_K_CP_MD_SET_reg                                                      0xB80158C8
#define  CP_K_CP_MD_SET_inst_addr                                                "0x00C5"
#define  set_CP_K_CP_MD_SET_reg(data)                                            (*((volatile unsigned int*)CP_K_CP_MD_SET_reg)=data)
#define  get_CP_K_CP_MD_SET_reg                                                  (*((volatile unsigned int*)CP_K_CP_MD_SET_reg))
#define  CP_K_CP_MD_SET_key_length_shift                                         (11)
#define  CP_K_CP_MD_SET_bcm_shift                                                (9)
#define  CP_K_CP_MD_SET_cw_entry_shift                                           (2)
#define  CP_K_CP_MD_SET_sel_shift                                                (0)
#define  CP_K_CP_MD_SET_key_length_mask                                          (0x00001800)
#define  CP_K_CP_MD_SET_bcm_mask                                                 (0x00000600)
#define  CP_K_CP_MD_SET_cw_entry_mask                                            (0x000001FC)
#define  CP_K_CP_MD_SET_sel_mask                                                 (0x00000003)
#define  CP_K_CP_MD_SET_key_length(data)                                         (0x00001800&((data)<<11))
#define  CP_K_CP_MD_SET_bcm(data)                                                (0x00000600&((data)<<9))
#define  CP_K_CP_MD_SET_cw_entry(data)                                           (0x000001FC&((data)<<2))
#define  CP_K_CP_MD_SET_sel(data)                                                (0x00000003&(data))
#define  CP_K_CP_MD_SET_get_key_length(data)                                     ((0x00001800&(data))>>11)
#define  CP_K_CP_MD_SET_get_bcm(data)                                            ((0x00000600&(data))>>9)
#define  CP_K_CP_MD_SET_get_cw_entry(data)                                       ((0x000001FC&(data))>>2)
#define  CP_K_CP_MD_SET_get_sel(data)                                            (0x00000003&(data))

#define  CP_CP_DBG                                                               0x180150CC
#define  CP_CP_DBG_reg_addr                                                      "0xB80150CC"
#define  CP_CP_DBG_reg                                                           0xB80150CC
#define  CP_CP_DBG_inst_addr                                                     "0x00C6"
#define  set_CP_CP_DBG_reg(data)                                                 (*((volatile unsigned int*)CP_CP_DBG_reg)=data)
#define  get_CP_CP_DBG_reg                                                       (*((volatile unsigned int*)CP_CP_DBG_reg))
#define  CP_CP_DBG_dbg_sel1_shift                                                (6)
#define  CP_CP_DBG_dbg_sel0_shift                                                (1)
#define  CP_CP_DBG_dbg_en_shift                                                  (0)
#define  CP_CP_DBG_dbg_sel1_mask                                                 (0x000007C0)
#define  CP_CP_DBG_dbg_sel0_mask                                                 (0x0000003E)
#define  CP_CP_DBG_dbg_en_mask                                                   (0x00000001)
#define  CP_CP_DBG_dbg_sel1(data)                                                (0x000007C0&((data)<<6))
#define  CP_CP_DBG_dbg_sel0(data)                                                (0x0000003E&((data)<<1))
#define  CP_CP_DBG_dbg_en(data)                                                  (0x00000001&(data))
#define  CP_CP_DBG_get_dbg_sel1(data)                                            ((0x000007C0&(data))>>6)
#define  CP_CP_DBG_get_dbg_sel0(data)                                            ((0x0000003E&(data))>>1)
#define  CP_CP_DBG_get_dbg_en(data)                                              (0x00000001&(data))

#define  CP_CP_TST1                                                              0x180150F0
#define  CP_CP_TST1_reg_addr                                                     "0xB80150F0"
#define  CP_CP_TST1_reg                                                          0xB80150F0
#define  CP_CP_TST1_inst_addr                                                    "0x00C7"
#define  set_CP_CP_TST1_reg(data)                                                (*((volatile unsigned int*)CP_CP_TST1_reg)=data)
#define  get_CP_CP_TST1_reg                                                      (*((volatile unsigned int*)CP_CP_TST1_reg))
#define  CP_CP_TST1_tst_sel1_shift                                               (6)
#define  CP_CP_TST1_tst_sel0_shift                                               (1)
#define  CP_CP_TST1_tst_en_shift                                                 (0)
#define  CP_CP_TST1_tst_sel1_mask                                                (0x000007C0)
#define  CP_CP_TST1_tst_sel0_mask                                                (0x0000003E)
#define  CP_CP_TST1_tst_en_mask                                                  (0x00000001)
#define  CP_CP_TST1_tst_sel1(data)                                               (0x000007C0&((data)<<6))
#define  CP_CP_TST1_tst_sel0(data)                                               (0x0000003E&((data)<<1))
#define  CP_CP_TST1_tst_en(data)                                                 (0x00000001&(data))
#define  CP_CP_TST1_get_tst_sel1(data)                                           ((0x000007C0&(data))>>6)
#define  CP_CP_TST1_get_tst_sel0(data)                                           ((0x0000003E&(data))>>1)
#define  CP_CP_TST1_get_tst_en(data)                                             (0x00000001&(data))

#define  CP_CP_TST2                                                              0x180150F4
#define  CP_CP_TST2_reg_addr                                                     "0xB80150F4"
#define  CP_CP_TST2_reg                                                          0xB80150F4
#define  CP_CP_TST2_inst_addr                                                    "0x00C8"
#define  set_CP_CP_TST2_reg(data)                                                (*((volatile unsigned int*)CP_CP_TST2_reg)=data)
#define  get_CP_CP_TST2_reg                                                      (*((volatile unsigned int*)CP_CP_TST2_reg))
#define  CP_CP_TST2_test_out_shift                                               (0)
#define  CP_CP_TST2_test_out_mask                                                (0xFFFFFFFF)
#define  CP_CP_TST2_test_out(data)                                               (0xFFFFFFFF&(data))
#define  CP_CP_TST2_get_test_out(data)                                           (0xFFFFFFFF&(data))

#define  CP_CP_BIST_MODE                                                         0x18015000
#define  CP_CP_BIST_MODE_reg_addr                                                "0xB8015000"
#define  CP_CP_BIST_MODE_reg                                                     0xB8015000
#define  CP_CP_BIST_MODE_inst_addr                                               "0x00C9"
#define  set_CP_CP_BIST_MODE_reg(data)                                           (*((volatile unsigned int*)CP_CP_BIST_MODE_reg)=data)
#define  get_CP_CP_BIST_MODE_reg                                                 (*((volatile unsigned int*)CP_CP_BIST_MODE_reg))
#define  CP_CP_BIST_MODE_en2_shift                                               (1)
#define  CP_CP_BIST_MODE_en_shift                                                (0)
#define  CP_CP_BIST_MODE_en2_mask                                                (0x00000002)
#define  CP_CP_BIST_MODE_en_mask                                                 (0x00000001)
#define  CP_CP_BIST_MODE_en2(data)                                               (0x00000002&((data)<<1))
#define  CP_CP_BIST_MODE_en(data)                                                (0x00000001&(data))
#define  CP_CP_BIST_MODE_get_en2(data)                                           ((0x00000002&(data))>>1)
#define  CP_CP_BIST_MODE_get_en(data)                                            (0x00000001&(data))

#define  CP_CP_BIST_DONE                                                         0x18015004
#define  CP_CP_BIST_DONE_reg_addr                                                "0xB8015004"
#define  CP_CP_BIST_DONE_reg                                                     0xB8015004
#define  CP_CP_BIST_DONE_inst_addr                                               "0x00CA"
#define  set_CP_CP_BIST_DONE_reg(data)                                           (*((volatile unsigned int*)CP_CP_BIST_DONE_reg)=data)
#define  get_CP_CP_BIST_DONE_reg                                                 (*((volatile unsigned int*)CP_CP_BIST_DONE_reg))
#define  CP_CP_BIST_DONE_done2_shift                                             (1)
#define  CP_CP_BIST_DONE_done_shift                                              (0)
#define  CP_CP_BIST_DONE_done2_mask                                              (0x00000002)
#define  CP_CP_BIST_DONE_done_mask                                               (0x00000001)
#define  CP_CP_BIST_DONE_done2(data)                                             (0x00000002&((data)<<1))
#define  CP_CP_BIST_DONE_done(data)                                              (0x00000001&(data))
#define  CP_CP_BIST_DONE_get_done2(data)                                         ((0x00000002&(data))>>1)
#define  CP_CP_BIST_DONE_get_done(data)                                          (0x00000001&(data))

#define  CP_CP_BIST_FAIL_GROUP                                                   0x18015008
#define  CP_CP_BIST_FAIL_GROUP_reg_addr                                          "0xB8015008"
#define  CP_CP_BIST_FAIL_GROUP_reg                                               0xB8015008
#define  CP_CP_BIST_FAIL_GROUP_inst_addr                                         "0x00CB"
#define  set_CP_CP_BIST_FAIL_GROUP_reg(data)                                     (*((volatile unsigned int*)CP_CP_BIST_FAIL_GROUP_reg)=data)
#define  get_CP_CP_BIST_FAIL_GROUP_reg                                           (*((volatile unsigned int*)CP_CP_BIST_FAIL_GROUP_reg))
#define  CP_CP_BIST_FAIL_GROUP_fail_group_shift                                  (0)
#define  CP_CP_BIST_FAIL_GROUP_fail_group_mask                                   (0x00000001)
#define  CP_CP_BIST_FAIL_GROUP_fail_group(data)                                  (0x00000001&(data))
#define  CP_CP_BIST_FAIL_GROUP_get_fail_group(data)                              (0x00000001&(data))

#define  CP_CP_BIST_FAIL                                                         0x1801500C
#define  CP_CP_BIST_FAIL_reg_addr                                                "0xB801500C"
#define  CP_CP_BIST_FAIL_reg                                                     0xB801500C
#define  CP_CP_BIST_FAIL_inst_addr                                               "0x00CC"
#define  set_CP_CP_BIST_FAIL_reg(data)                                           (*((volatile unsigned int*)CP_CP_BIST_FAIL_reg)=data)
#define  get_CP_CP_BIST_FAIL_reg                                                 (*((volatile unsigned int*)CP_CP_BIST_FAIL_reg))
#define  CP_CP_BIST_FAIL_fail3_shift                                             (12)
#define  CP_CP_BIST_FAIL_fail2_shift                                             (8)
#define  CP_CP_BIST_FAIL_fail1_shift                                             (4)
#define  CP_CP_BIST_FAIL_fail0_shift                                             (0)
#define  CP_CP_BIST_FAIL_fail3_mask                                              (0x00001000)
#define  CP_CP_BIST_FAIL_fail2_mask                                              (0x00000100)
#define  CP_CP_BIST_FAIL_fail1_mask                                              (0x00000010)
#define  CP_CP_BIST_FAIL_fail0_mask                                              (0x00000001)
#define  CP_CP_BIST_FAIL_fail3(data)                                             (0x00001000&((data)<<12))
#define  CP_CP_BIST_FAIL_fail2(data)                                             (0x00000100&((data)<<8))
#define  CP_CP_BIST_FAIL_fail1(data)                                             (0x00000010&((data)<<4))
#define  CP_CP_BIST_FAIL_fail0(data)                                             (0x00000001&(data))
#define  CP_CP_BIST_FAIL_get_fail3(data)                                         ((0x00001000&(data))>>12)
#define  CP_CP_BIST_FAIL_get_fail2(data)                                         ((0x00000100&(data))>>8)
#define  CP_CP_BIST_FAIL_get_fail1(data)                                         ((0x00000010&(data))>>4)
#define  CP_CP_BIST_FAIL_get_fail0(data)                                         (0x00000001&(data))

#define  CP_CP_DRF_MODE                                                          0x18015010
#define  CP_CP_DRF_MODE_reg_addr                                                 "0xB8015010"
#define  CP_CP_DRF_MODE_reg                                                      0xB8015010
#define  CP_CP_DRF_MODE_inst_addr                                                "0x00CD"
#define  set_CP_CP_DRF_MODE_reg(data)                                            (*((volatile unsigned int*)CP_CP_DRF_MODE_reg)=data)
#define  get_CP_CP_DRF_MODE_reg                                                  (*((volatile unsigned int*)CP_CP_DRF_MODE_reg))
#define  CP_CP_DRF_MODE_en2_shift                                                (1)
#define  CP_CP_DRF_MODE_en_shift                                                 (0)
#define  CP_CP_DRF_MODE_en2_mask                                                 (0x00000002)
#define  CP_CP_DRF_MODE_en_mask                                                  (0x00000001)
#define  CP_CP_DRF_MODE_en2(data)                                                (0x00000002&((data)<<1))
#define  CP_CP_DRF_MODE_en(data)                                                 (0x00000001&(data))
#define  CP_CP_DRF_MODE_get_en2(data)                                            ((0x00000002&(data))>>1)
#define  CP_CP_DRF_MODE_get_en(data)                                             (0x00000001&(data))

#define  CP_CP_DRF_DONE                                                          0x18015014
#define  CP_CP_DRF_DONE_reg_addr                                                 "0xB8015014"
#define  CP_CP_DRF_DONE_reg                                                      0xB8015014
#define  CP_CP_DRF_DONE_inst_addr                                                "0x00CE"
#define  set_CP_CP_DRF_DONE_reg(data)                                            (*((volatile unsigned int*)CP_CP_DRF_DONE_reg)=data)
#define  get_CP_CP_DRF_DONE_reg                                                  (*((volatile unsigned int*)CP_CP_DRF_DONE_reg))
#define  CP_CP_DRF_DONE_done2_shift                                              (1)
#define  CP_CP_DRF_DONE_done_shift                                               (0)
#define  CP_CP_DRF_DONE_done2_mask                                               (0x00000002)
#define  CP_CP_DRF_DONE_done_mask                                                (0x00000001)
#define  CP_CP_DRF_DONE_done2(data)                                              (0x00000002&((data)<<1))
#define  CP_CP_DRF_DONE_done(data)                                               (0x00000001&(data))
#define  CP_CP_DRF_DONE_get_done2(data)                                          ((0x00000002&(data))>>1)
#define  CP_CP_DRF_DONE_get_done(data)                                           (0x00000001&(data))

#define  CP_CP_DRF_FAIL_GROUP                                                    0x18015018
#define  CP_CP_DRF_FAIL_GROUP_reg_addr                                           "0xB8015018"
#define  CP_CP_DRF_FAIL_GROUP_reg                                                0xB8015018
#define  CP_CP_DRF_FAIL_GROUP_inst_addr                                          "0x00CF"
#define  set_CP_CP_DRF_FAIL_GROUP_reg(data)                                      (*((volatile unsigned int*)CP_CP_DRF_FAIL_GROUP_reg)=data)
#define  get_CP_CP_DRF_FAIL_GROUP_reg                                            (*((volatile unsigned int*)CP_CP_DRF_FAIL_GROUP_reg))
#define  CP_CP_DRF_FAIL_GROUP_fail_group_shift                                   (0)
#define  CP_CP_DRF_FAIL_GROUP_fail_group_mask                                    (0x00000001)
#define  CP_CP_DRF_FAIL_GROUP_fail_group(data)                                   (0x00000001&(data))
#define  CP_CP_DRF_FAIL_GROUP_get_fail_group(data)                               (0x00000001&(data))

#define  CP_CP_DRF_FAIL                                                          0x1801501C
#define  CP_CP_DRF_FAIL_reg_addr                                                 "0xB801501C"
#define  CP_CP_DRF_FAIL_reg                                                      0xB801501C
#define  CP_CP_DRF_FAIL_inst_addr                                                "0x00D0"
#define  set_CP_CP_DRF_FAIL_reg(data)                                            (*((volatile unsigned int*)CP_CP_DRF_FAIL_reg)=data)
#define  get_CP_CP_DRF_FAIL_reg                                                  (*((volatile unsigned int*)CP_CP_DRF_FAIL_reg))
#define  CP_CP_DRF_FAIL_fail3_shift                                              (12)
#define  CP_CP_DRF_FAIL_fail2_shift                                              (8)
#define  CP_CP_DRF_FAIL_fail1_shift                                              (4)
#define  CP_CP_DRF_FAIL_fail0_shift                                              (0)
#define  CP_CP_DRF_FAIL_fail3_mask                                               (0x00001000)
#define  CP_CP_DRF_FAIL_fail2_mask                                               (0x00000100)
#define  CP_CP_DRF_FAIL_fail1_mask                                               (0x00000010)
#define  CP_CP_DRF_FAIL_fail0_mask                                               (0x00000001)
#define  CP_CP_DRF_FAIL_fail3(data)                                              (0x00001000&((data)<<12))
#define  CP_CP_DRF_FAIL_fail2(data)                                              (0x00000100&((data)<<8))
#define  CP_CP_DRF_FAIL_fail1(data)                                              (0x00000010&((data)<<4))
#define  CP_CP_DRF_FAIL_fail0(data)                                              (0x00000001&(data))
#define  CP_CP_DRF_FAIL_get_fail3(data)                                          ((0x00001000&(data))>>12)
#define  CP_CP_DRF_FAIL_get_fail2(data)                                          ((0x00000100&(data))>>8)
#define  CP_CP_DRF_FAIL_get_fail1(data)                                          ((0x00000010&(data))>>4)
#define  CP_CP_DRF_FAIL_get_fail0(data)                                          (0x00000001&(data))

#define  CP_CP_DRF_RESUME                                                        0x18015020
#define  CP_CP_DRF_RESUME_reg_addr                                               "0xB8015020"
#define  CP_CP_DRF_RESUME_reg                                                    0xB8015020
#define  CP_CP_DRF_RESUME_inst_addr                                              "0x00D1"
#define  set_CP_CP_DRF_RESUME_reg(data)                                          (*((volatile unsigned int*)CP_CP_DRF_RESUME_reg)=data)
#define  get_CP_CP_DRF_RESUME_reg                                                (*((volatile unsigned int*)CP_CP_DRF_RESUME_reg))
#define  CP_CP_DRF_RESUME_en2_shift                                              (1)
#define  CP_CP_DRF_RESUME_en_shift                                               (0)
#define  CP_CP_DRF_RESUME_en2_mask                                               (0x00000002)
#define  CP_CP_DRF_RESUME_en_mask                                                (0x00000001)
#define  CP_CP_DRF_RESUME_en2(data)                                              (0x00000002&((data)<<1))
#define  CP_CP_DRF_RESUME_en(data)                                               (0x00000001&(data))
#define  CP_CP_DRF_RESUME_get_en2(data)                                          ((0x00000002&(data))>>1)
#define  CP_CP_DRF_RESUME_get_en(data)                                           (0x00000001&(data))

#define  CP_CP_DRF_PAUSE                                                         0x18015024
#define  CP_CP_DRF_PAUSE_reg_addr                                                "0xB8015024"
#define  CP_CP_DRF_PAUSE_reg                                                     0xB8015024
#define  CP_CP_DRF_PAUSE_inst_addr                                               "0x00D2"
#define  set_CP_CP_DRF_PAUSE_reg(data)                                           (*((volatile unsigned int*)CP_CP_DRF_PAUSE_reg)=data)
#define  get_CP_CP_DRF_PAUSE_reg                                                 (*((volatile unsigned int*)CP_CP_DRF_PAUSE_reg))
#define  CP_CP_DRF_PAUSE_flag2_shift                                             (1)
#define  CP_CP_DRF_PAUSE_flag_shift                                              (0)
#define  CP_CP_DRF_PAUSE_flag2_mask                                              (0x00000002)
#define  CP_CP_DRF_PAUSE_flag_mask                                               (0x00000001)
#define  CP_CP_DRF_PAUSE_flag2(data)                                             (0x00000002&((data)<<1))
#define  CP_CP_DRF_PAUSE_flag(data)                                              (0x00000001&(data))
#define  CP_CP_DRF_PAUSE_get_flag2(data)                                         ((0x00000002&(data))>>1)
#define  CP_CP_DRF_PAUSE_get_flag(data)                                          (0x00000001&(data))

#define  CP_CP_SRAM_RM                                                           0x18015028
#define  CP_CP_SRAM_RM_reg_addr                                                  "0xB8015028"
#define  CP_CP_SRAM_RM_reg                                                       0xB8015028
#define  CP_CP_SRAM_RM_inst_addr                                                 "0x00D3"
#define  set_CP_CP_SRAM_RM_reg(data)                                             (*((volatile unsigned int*)CP_CP_SRAM_RM_reg)=data)
#define  get_CP_CP_SRAM_RM_reg                                                   (*((volatile unsigned int*)CP_CP_SRAM_RM_reg))
#define  CP_CP_SRAM_RM_rsa_rme_shift                                             (25)
#define  CP_CP_SRAM_RM_rsa_rm_shift                                              (21)
#define  CP_CP_SRAM_RM_din1_rme_shift                                            (20)
#define  CP_CP_SRAM_RM_din1_rm_shift                                             (16)
#define  CP_CP_SRAM_RM_din0_rme_shift                                            (12)
#define  CP_CP_SRAM_RM_din0_rm_shift                                             (8)
#define  CP_CP_SRAM_RM_desc_rme_shift                                            (4)
#define  CP_CP_SRAM_RM_desc_rm_shift                                             (0)
#define  CP_CP_SRAM_RM_rsa_rme_mask                                              (0x02000000)
#define  CP_CP_SRAM_RM_rsa_rm_mask                                               (0x01E00000)
#define  CP_CP_SRAM_RM_din1_rme_mask                                             (0x00100000)
#define  CP_CP_SRAM_RM_din1_rm_mask                                              (0x000F0000)
#define  CP_CP_SRAM_RM_din0_rme_mask                                             (0x00001000)
#define  CP_CP_SRAM_RM_din0_rm_mask                                              (0x00000F00)
#define  CP_CP_SRAM_RM_desc_rme_mask                                             (0x00000010)
#define  CP_CP_SRAM_RM_desc_rm_mask                                              (0x0000000F)
#define  CP_CP_SRAM_RM_rsa_rme(data)                                             (0x02000000&((data)<<25))
#define  CP_CP_SRAM_RM_rsa_rm(data)                                              (0x01E00000&((data)<<21))
#define  CP_CP_SRAM_RM_din1_rme(data)                                            (0x00100000&((data)<<20))
#define  CP_CP_SRAM_RM_din1_rm(data)                                             (0x000F0000&((data)<<16))
#define  CP_CP_SRAM_RM_din0_rme(data)                                            (0x00001000&((data)<<12))
#define  CP_CP_SRAM_RM_din0_rm(data)                                             (0x00000F00&((data)<<8))
#define  CP_CP_SRAM_RM_desc_rme(data)                                            (0x00000010&((data)<<4))
#define  CP_CP_SRAM_RM_desc_rm(data)                                             (0x0000000F&(data))
#define  CP_CP_SRAM_RM_get_rsa_rme(data)                                         ((0x02000000&(data))>>25)
#define  CP_CP_SRAM_RM_get_rsa_rm(data)                                          ((0x01E00000&(data))>>21)
#define  CP_CP_SRAM_RM_get_din1_rme(data)                                        ((0x00100000&(data))>>20)
#define  CP_CP_SRAM_RM_get_din1_rm(data)                                         ((0x000F0000&(data))>>16)
#define  CP_CP_SRAM_RM_get_din0_rme(data)                                        ((0x00001000&(data))>>12)
#define  CP_CP_SRAM_RM_get_din0_rm(data)                                         ((0x00000F00&(data))>>8)
#define  CP_CP_SRAM_RM_get_desc_rme(data)                                        ((0x00000010&(data))>>4)
#define  CP_CP_SRAM_RM_get_desc_rm(data)                                         (0x0000000F&(data))

#define  CP_CP_SRAM_LS                                                           0x1801502C
#define  CP_CP_SRAM_LS_reg_addr                                                  "0xB801502C"
#define  CP_CP_SRAM_LS_reg                                                       0xB801502C
#define  CP_CP_SRAM_LS_inst_addr                                                 "0x00D4"
#define  set_CP_CP_SRAM_LS_reg(data)                                             (*((volatile unsigned int*)CP_CP_SRAM_LS_reg)=data)
#define  get_CP_CP_SRAM_LS_reg                                                   (*((volatile unsigned int*)CP_CP_SRAM_LS_reg))
#define  CP_CP_SRAM_LS_rsa_ls_shift                                              (12)
#define  CP_CP_SRAM_LS_din1_ls_shift                                             (8)
#define  CP_CP_SRAM_LS_din0_ls_shift                                             (4)
#define  CP_CP_SRAM_LS_desc_ls_shift                                             (0)
#define  CP_CP_SRAM_LS_rsa_ls_mask                                               (0x00001000)
#define  CP_CP_SRAM_LS_din1_ls_mask                                              (0x00000100)
#define  CP_CP_SRAM_LS_din0_ls_mask                                              (0x00000010)
#define  CP_CP_SRAM_LS_desc_ls_mask                                              (0x00000001)
#define  CP_CP_SRAM_LS_rsa_ls(data)                                              (0x00001000&((data)<<12))
#define  CP_CP_SRAM_LS_din1_ls(data)                                             (0x00000100&((data)<<8))
#define  CP_CP_SRAM_LS_din0_ls(data)                                             (0x00000010&((data)<<4))
#define  CP_CP_SRAM_LS_desc_ls(data)                                             (0x00000001&(data))
#define  CP_CP_SRAM_LS_get_rsa_ls(data)                                          ((0x00001000&(data))>>12)
#define  CP_CP_SRAM_LS_get_din1_ls(data)                                         ((0x00000100&(data))>>8)
#define  CP_CP_SRAM_LS_get_din0_ls(data)                                         ((0x00000010&(data))>>4)
#define  CP_CP_SRAM_LS_get_desc_ls(data)                                         (0x00000001&(data))

#define  CP_K_CP_SCPU_CW_RANGE                                                   0x18015A00
#define  CP_K_CP_SCPU_CW_RANGE_reg_addr                                          "0xB8015A00"
#define  CP_K_CP_SCPU_CW_RANGE_reg                                               0xB8015A00
#define  CP_K_CP_SCPU_CW_RANGE_inst_addr                                         "0x00D5"
#define  set_CP_K_CP_SCPU_CW_RANGE_reg(data)                                     (*((volatile unsigned int*)CP_K_CP_SCPU_CW_RANGE_reg)=data)
#define  get_CP_K_CP_SCPU_CW_RANGE_reg                                           (*((volatile unsigned int*)CP_K_CP_SCPU_CW_RANGE_reg))
#define  CP_K_CP_SCPU_CW_RANGE_start_shift                                       (8)
#define  CP_K_CP_SCPU_CW_RANGE_end_shift                                         (0)
#define  CP_K_CP_SCPU_CW_RANGE_start_mask                                        (0x00007F00)
#define  CP_K_CP_SCPU_CW_RANGE_end_mask                                          (0x0000007F)
#define  CP_K_CP_SCPU_CW_RANGE_start(data)                                       (0x00007F00&((data)<<8))
#define  CP_K_CP_SCPU_CW_RANGE_end(data)                                         (0x0000007F&(data))
#define  CP_K_CP_SCPU_CW_RANGE_get_start(data)                                   ((0x00007F00&(data))>>8)
#define  CP_K_CP_SCPU_CW_RANGE_get_end(data)                                     (0x0000007F&(data))

#define  CP_K_CP_STATUS                                                          0x180158F0
#define  CP_K_CP_STATUS_reg_addr                                                 "0xB80158F0"
#define  CP_K_CP_STATUS_reg                                                      0xB80158F0
#define  CP_K_CP_STATUS_inst_addr                                                "0x00D6"
#define  set_CP_K_CP_STATUS_reg(data)                                            (*((volatile unsigned int*)CP_K_CP_STATUS_reg)=data)
#define  get_CP_K_CP_STATUS_reg                                                  (*((volatile unsigned int*)CP_K_CP_STATUS_reg))
#define  CP_K_CP_STATUS_scpu_illegal_access_shift                                (0)
#define  CP_K_CP_STATUS_scpu_illegal_access_mask                                 (0x00000001)
#define  CP_K_CP_STATUS_scpu_illegal_access(data)                                (0x00000001&(data))
#define  CP_K_CP_STATUS_get_scpu_illegal_access(data)                            (0x00000001&(data))

#define  CP_K_CP_EN                                                              0x180158F4
#define  CP_K_CP_EN_reg_addr                                                     "0xB80158F4"
#define  CP_K_CP_EN_reg                                                          0xB80158F4
#define  CP_K_CP_EN_inst_addr                                                    "0x00D7"
#define  set_CP_K_CP_EN_reg(data)                                                (*((volatile unsigned int*)CP_K_CP_EN_reg)=data)
#define  get_CP_K_CP_EN_reg                                                      (*((volatile unsigned int*)CP_K_CP_EN_reg))
#define  CP_K_CP_EN_scpu_illegal_access_en_shift                                 (0)
#define  CP_K_CP_EN_scpu_illegal_access_en_mask                                  (0x00000001)
#define  CP_K_CP_EN_scpu_illegal_access_en(data)                                 (0x00000001&(data))
#define  CP_K_CP_EN_get_scpu_illegal_access_en(data)                             (0x00000001&(data))

#define  CP_RSA_X_0                                                              0x1806E000
#define  CP_RSA_X_0_reg_addr                                                     "0xB806E000"
#define  CP_RSA_X_0_reg                                                          0xB806E000
#define  CP_RSA_X_0_inst_addr                                                    "0x00D8"
#define  set_CP_RSA_X_0_reg(data)                                                (*((volatile unsigned int*)CP_RSA_X_0_reg)=data)
#define  get_CP_RSA_X_0_reg                                                      (*((volatile unsigned int*)CP_RSA_X_0_reg))
#define  CP_RSA_X_0_data_shift                                                   (0)
#define  CP_RSA_X_0_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_X_0_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_X_0_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_X_1                                                              0x1806E004
#define  CP_RSA_X_1_reg_addr                                                     "0xB806E004"
#define  CP_RSA_X_1_reg                                                          0xB806E004
#define  CP_RSA_X_1_inst_addr                                                    "0x00D9"
#define  set_CP_RSA_X_1_reg(data)                                                (*((volatile unsigned int*)CP_RSA_X_1_reg)=data)
#define  get_CP_RSA_X_1_reg                                                      (*((volatile unsigned int*)CP_RSA_X_1_reg))
#define  CP_RSA_X_1_data_shift                                                   (0)
#define  CP_RSA_X_1_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_X_1_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_X_1_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_X_2                                                              0x1806E008
#define  CP_RSA_X_2_reg_addr                                                     "0xB806E008"
#define  CP_RSA_X_2_reg                                                          0xB806E008
#define  CP_RSA_X_2_inst_addr                                                    "0x00DA"
#define  set_CP_RSA_X_2_reg(data)                                                (*((volatile unsigned int*)CP_RSA_X_2_reg)=data)
#define  get_CP_RSA_X_2_reg                                                      (*((volatile unsigned int*)CP_RSA_X_2_reg))
#define  CP_RSA_X_2_data_shift                                                   (0)
#define  CP_RSA_X_2_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_X_2_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_X_2_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_X_3                                                              0x1806E00C
#define  CP_RSA_X_3_reg_addr                                                     "0xB806E00C"
#define  CP_RSA_X_3_reg                                                          0xB806E00C
#define  CP_RSA_X_3_inst_addr                                                    "0x00DB"
#define  set_CP_RSA_X_3_reg(data)                                                (*((volatile unsigned int*)CP_RSA_X_3_reg)=data)
#define  get_CP_RSA_X_3_reg                                                      (*((volatile unsigned int*)CP_RSA_X_3_reg))
#define  CP_RSA_X_3_data_shift                                                   (0)
#define  CP_RSA_X_3_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_X_3_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_X_3_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_X_4                                                              0x1806E010
#define  CP_RSA_X_4_reg_addr                                                     "0xB806E010"
#define  CP_RSA_X_4_reg                                                          0xB806E010
#define  CP_RSA_X_4_inst_addr                                                    "0x00DC"
#define  set_CP_RSA_X_4_reg(data)                                                (*((volatile unsigned int*)CP_RSA_X_4_reg)=data)
#define  get_CP_RSA_X_4_reg                                                      (*((volatile unsigned int*)CP_RSA_X_4_reg))
#define  CP_RSA_X_4_data_shift                                                   (0)
#define  CP_RSA_X_4_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_X_4_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_X_4_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_X_5                                                              0x1806E014
#define  CP_RSA_X_5_reg_addr                                                     "0xB806E014"
#define  CP_RSA_X_5_reg                                                          0xB806E014
#define  CP_RSA_X_5_inst_addr                                                    "0x00DD"
#define  set_CP_RSA_X_5_reg(data)                                                (*((volatile unsigned int*)CP_RSA_X_5_reg)=data)
#define  get_CP_RSA_X_5_reg                                                      (*((volatile unsigned int*)CP_RSA_X_5_reg))
#define  CP_RSA_X_5_data_shift                                                   (0)
#define  CP_RSA_X_5_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_X_5_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_X_5_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_X_6                                                              0x1806E018
#define  CP_RSA_X_6_reg_addr                                                     "0xB806E018"
#define  CP_RSA_X_6_reg                                                          0xB806E018
#define  CP_RSA_X_6_inst_addr                                                    "0x00DE"
#define  set_CP_RSA_X_6_reg(data)                                                (*((volatile unsigned int*)CP_RSA_X_6_reg)=data)
#define  get_CP_RSA_X_6_reg                                                      (*((volatile unsigned int*)CP_RSA_X_6_reg))
#define  CP_RSA_X_6_data_shift                                                   (0)
#define  CP_RSA_X_6_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_X_6_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_X_6_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_X_7                                                              0x1806E01C
#define  CP_RSA_X_7_reg_addr                                                     "0xB806E01C"
#define  CP_RSA_X_7_reg                                                          0xB806E01C
#define  CP_RSA_X_7_inst_addr                                                    "0x00DF"
#define  set_CP_RSA_X_7_reg(data)                                                (*((volatile unsigned int*)CP_RSA_X_7_reg)=data)
#define  get_CP_RSA_X_7_reg                                                      (*((volatile unsigned int*)CP_RSA_X_7_reg))
#define  CP_RSA_X_7_data_shift                                                   (0)
#define  CP_RSA_X_7_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_X_7_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_X_7_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_X_8                                                              0x1806E020
#define  CP_RSA_X_8_reg_addr                                                     "0xB806E020"
#define  CP_RSA_X_8_reg                                                          0xB806E020
#define  CP_RSA_X_8_inst_addr                                                    "0x00E0"
#define  set_CP_RSA_X_8_reg(data)                                                (*((volatile unsigned int*)CP_RSA_X_8_reg)=data)
#define  get_CP_RSA_X_8_reg                                                      (*((volatile unsigned int*)CP_RSA_X_8_reg))
#define  CP_RSA_X_8_data_shift                                                   (0)
#define  CP_RSA_X_8_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_X_8_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_X_8_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_X_9                                                              0x1806E024
#define  CP_RSA_X_9_reg_addr                                                     "0xB806E024"
#define  CP_RSA_X_9_reg                                                          0xB806E024
#define  CP_RSA_X_9_inst_addr                                                    "0x00E1"
#define  set_CP_RSA_X_9_reg(data)                                                (*((volatile unsigned int*)CP_RSA_X_9_reg)=data)
#define  get_CP_RSA_X_9_reg                                                      (*((volatile unsigned int*)CP_RSA_X_9_reg))
#define  CP_RSA_X_9_data_shift                                                   (0)
#define  CP_RSA_X_9_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_X_9_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_X_9_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_X_10                                                             0x1806E028
#define  CP_RSA_X_10_reg_addr                                                    "0xB806E028"
#define  CP_RSA_X_10_reg                                                         0xB806E028
#define  CP_RSA_X_10_inst_addr                                                   "0x00E2"
#define  set_CP_RSA_X_10_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_10_reg)=data)
#define  get_CP_RSA_X_10_reg                                                     (*((volatile unsigned int*)CP_RSA_X_10_reg))
#define  CP_RSA_X_10_data_shift                                                  (0)
#define  CP_RSA_X_10_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_10_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_10_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_11                                                             0x1806E02C
#define  CP_RSA_X_11_reg_addr                                                    "0xB806E02C"
#define  CP_RSA_X_11_reg                                                         0xB806E02C
#define  CP_RSA_X_11_inst_addr                                                   "0x00E3"
#define  set_CP_RSA_X_11_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_11_reg)=data)
#define  get_CP_RSA_X_11_reg                                                     (*((volatile unsigned int*)CP_RSA_X_11_reg))
#define  CP_RSA_X_11_data_shift                                                  (0)
#define  CP_RSA_X_11_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_11_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_11_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_12                                                             0x1806E030
#define  CP_RSA_X_12_reg_addr                                                    "0xB806E030"
#define  CP_RSA_X_12_reg                                                         0xB806E030
#define  CP_RSA_X_12_inst_addr                                                   "0x00E4"
#define  set_CP_RSA_X_12_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_12_reg)=data)
#define  get_CP_RSA_X_12_reg                                                     (*((volatile unsigned int*)CP_RSA_X_12_reg))
#define  CP_RSA_X_12_data_shift                                                  (0)
#define  CP_RSA_X_12_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_12_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_12_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_13                                                             0x1806E034
#define  CP_RSA_X_13_reg_addr                                                    "0xB806E034"
#define  CP_RSA_X_13_reg                                                         0xB806E034
#define  CP_RSA_X_13_inst_addr                                                   "0x00E5"
#define  set_CP_RSA_X_13_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_13_reg)=data)
#define  get_CP_RSA_X_13_reg                                                     (*((volatile unsigned int*)CP_RSA_X_13_reg))
#define  CP_RSA_X_13_data_shift                                                  (0)
#define  CP_RSA_X_13_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_13_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_13_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_14                                                             0x1806E038
#define  CP_RSA_X_14_reg_addr                                                    "0xB806E038"
#define  CP_RSA_X_14_reg                                                         0xB806E038
#define  CP_RSA_X_14_inst_addr                                                   "0x00E6"
#define  set_CP_RSA_X_14_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_14_reg)=data)
#define  get_CP_RSA_X_14_reg                                                     (*((volatile unsigned int*)CP_RSA_X_14_reg))
#define  CP_RSA_X_14_data_shift                                                  (0)
#define  CP_RSA_X_14_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_14_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_14_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_15                                                             0x1806E03C
#define  CP_RSA_X_15_reg_addr                                                    "0xB806E03C"
#define  CP_RSA_X_15_reg                                                         0xB806E03C
#define  CP_RSA_X_15_inst_addr                                                   "0x00E7"
#define  set_CP_RSA_X_15_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_15_reg)=data)
#define  get_CP_RSA_X_15_reg                                                     (*((volatile unsigned int*)CP_RSA_X_15_reg))
#define  CP_RSA_X_15_data_shift                                                  (0)
#define  CP_RSA_X_15_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_15_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_15_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_16                                                             0x1806E040
#define  CP_RSA_X_16_reg_addr                                                    "0xB806E040"
#define  CP_RSA_X_16_reg                                                         0xB806E040
#define  CP_RSA_X_16_inst_addr                                                   "0x00E8"
#define  set_CP_RSA_X_16_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_16_reg)=data)
#define  get_CP_RSA_X_16_reg                                                     (*((volatile unsigned int*)CP_RSA_X_16_reg))
#define  CP_RSA_X_16_data_shift                                                  (0)
#define  CP_RSA_X_16_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_16_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_16_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_17                                                             0x1806E044
#define  CP_RSA_X_17_reg_addr                                                    "0xB806E044"
#define  CP_RSA_X_17_reg                                                         0xB806E044
#define  CP_RSA_X_17_inst_addr                                                   "0x00E9"
#define  set_CP_RSA_X_17_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_17_reg)=data)
#define  get_CP_RSA_X_17_reg                                                     (*((volatile unsigned int*)CP_RSA_X_17_reg))
#define  CP_RSA_X_17_data_shift                                                  (0)
#define  CP_RSA_X_17_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_17_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_17_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_18                                                             0x1806E048
#define  CP_RSA_X_18_reg_addr                                                    "0xB806E048"
#define  CP_RSA_X_18_reg                                                         0xB806E048
#define  CP_RSA_X_18_inst_addr                                                   "0x00EA"
#define  set_CP_RSA_X_18_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_18_reg)=data)
#define  get_CP_RSA_X_18_reg                                                     (*((volatile unsigned int*)CP_RSA_X_18_reg))
#define  CP_RSA_X_18_data_shift                                                  (0)
#define  CP_RSA_X_18_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_18_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_18_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_19                                                             0x1806E04C
#define  CP_RSA_X_19_reg_addr                                                    "0xB806E04C"
#define  CP_RSA_X_19_reg                                                         0xB806E04C
#define  CP_RSA_X_19_inst_addr                                                   "0x00EB"
#define  set_CP_RSA_X_19_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_19_reg)=data)
#define  get_CP_RSA_X_19_reg                                                     (*((volatile unsigned int*)CP_RSA_X_19_reg))
#define  CP_RSA_X_19_data_shift                                                  (0)
#define  CP_RSA_X_19_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_19_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_19_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_20                                                             0x1806E050
#define  CP_RSA_X_20_reg_addr                                                    "0xB806E050"
#define  CP_RSA_X_20_reg                                                         0xB806E050
#define  CP_RSA_X_20_inst_addr                                                   "0x00EC"
#define  set_CP_RSA_X_20_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_20_reg)=data)
#define  get_CP_RSA_X_20_reg                                                     (*((volatile unsigned int*)CP_RSA_X_20_reg))
#define  CP_RSA_X_20_data_shift                                                  (0)
#define  CP_RSA_X_20_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_20_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_20_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_21                                                             0x1806E054
#define  CP_RSA_X_21_reg_addr                                                    "0xB806E054"
#define  CP_RSA_X_21_reg                                                         0xB806E054
#define  CP_RSA_X_21_inst_addr                                                   "0x00ED"
#define  set_CP_RSA_X_21_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_21_reg)=data)
#define  get_CP_RSA_X_21_reg                                                     (*((volatile unsigned int*)CP_RSA_X_21_reg))
#define  CP_RSA_X_21_data_shift                                                  (0)
#define  CP_RSA_X_21_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_21_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_21_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_22                                                             0x1806E058
#define  CP_RSA_X_22_reg_addr                                                    "0xB806E058"
#define  CP_RSA_X_22_reg                                                         0xB806E058
#define  CP_RSA_X_22_inst_addr                                                   "0x00EE"
#define  set_CP_RSA_X_22_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_22_reg)=data)
#define  get_CP_RSA_X_22_reg                                                     (*((volatile unsigned int*)CP_RSA_X_22_reg))
#define  CP_RSA_X_22_data_shift                                                  (0)
#define  CP_RSA_X_22_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_22_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_22_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_23                                                             0x1806E05C
#define  CP_RSA_X_23_reg_addr                                                    "0xB806E05C"
#define  CP_RSA_X_23_reg                                                         0xB806E05C
#define  CP_RSA_X_23_inst_addr                                                   "0x00EF"
#define  set_CP_RSA_X_23_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_23_reg)=data)
#define  get_CP_RSA_X_23_reg                                                     (*((volatile unsigned int*)CP_RSA_X_23_reg))
#define  CP_RSA_X_23_data_shift                                                  (0)
#define  CP_RSA_X_23_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_23_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_23_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_24                                                             0x1806E060
#define  CP_RSA_X_24_reg_addr                                                    "0xB806E060"
#define  CP_RSA_X_24_reg                                                         0xB806E060
#define  CP_RSA_X_24_inst_addr                                                   "0x00F0"
#define  set_CP_RSA_X_24_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_24_reg)=data)
#define  get_CP_RSA_X_24_reg                                                     (*((volatile unsigned int*)CP_RSA_X_24_reg))
#define  CP_RSA_X_24_data_shift                                                  (0)
#define  CP_RSA_X_24_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_24_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_24_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_25                                                             0x1806E064
#define  CP_RSA_X_25_reg_addr                                                    "0xB806E064"
#define  CP_RSA_X_25_reg                                                         0xB806E064
#define  CP_RSA_X_25_inst_addr                                                   "0x00F1"
#define  set_CP_RSA_X_25_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_25_reg)=data)
#define  get_CP_RSA_X_25_reg                                                     (*((volatile unsigned int*)CP_RSA_X_25_reg))
#define  CP_RSA_X_25_data_shift                                                  (0)
#define  CP_RSA_X_25_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_25_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_25_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_26                                                             0x1806E068
#define  CP_RSA_X_26_reg_addr                                                    "0xB806E068"
#define  CP_RSA_X_26_reg                                                         0xB806E068
#define  CP_RSA_X_26_inst_addr                                                   "0x00F2"
#define  set_CP_RSA_X_26_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_26_reg)=data)
#define  get_CP_RSA_X_26_reg                                                     (*((volatile unsigned int*)CP_RSA_X_26_reg))
#define  CP_RSA_X_26_data_shift                                                  (0)
#define  CP_RSA_X_26_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_26_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_26_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_27                                                             0x1806E06C
#define  CP_RSA_X_27_reg_addr                                                    "0xB806E06C"
#define  CP_RSA_X_27_reg                                                         0xB806E06C
#define  CP_RSA_X_27_inst_addr                                                   "0x00F3"
#define  set_CP_RSA_X_27_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_27_reg)=data)
#define  get_CP_RSA_X_27_reg                                                     (*((volatile unsigned int*)CP_RSA_X_27_reg))
#define  CP_RSA_X_27_data_shift                                                  (0)
#define  CP_RSA_X_27_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_27_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_27_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_28                                                             0x1806E070
#define  CP_RSA_X_28_reg_addr                                                    "0xB806E070"
#define  CP_RSA_X_28_reg                                                         0xB806E070
#define  CP_RSA_X_28_inst_addr                                                   "0x00F4"
#define  set_CP_RSA_X_28_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_28_reg)=data)
#define  get_CP_RSA_X_28_reg                                                     (*((volatile unsigned int*)CP_RSA_X_28_reg))
#define  CP_RSA_X_28_data_shift                                                  (0)
#define  CP_RSA_X_28_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_28_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_28_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_29                                                             0x1806E074
#define  CP_RSA_X_29_reg_addr                                                    "0xB806E074"
#define  CP_RSA_X_29_reg                                                         0xB806E074
#define  CP_RSA_X_29_inst_addr                                                   "0x00F5"
#define  set_CP_RSA_X_29_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_29_reg)=data)
#define  get_CP_RSA_X_29_reg                                                     (*((volatile unsigned int*)CP_RSA_X_29_reg))
#define  CP_RSA_X_29_data_shift                                                  (0)
#define  CP_RSA_X_29_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_29_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_29_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_30                                                             0x1806E078
#define  CP_RSA_X_30_reg_addr                                                    "0xB806E078"
#define  CP_RSA_X_30_reg                                                         0xB806E078
#define  CP_RSA_X_30_inst_addr                                                   "0x00F6"
#define  set_CP_RSA_X_30_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_30_reg)=data)
#define  get_CP_RSA_X_30_reg                                                     (*((volatile unsigned int*)CP_RSA_X_30_reg))
#define  CP_RSA_X_30_data_shift                                                  (0)
#define  CP_RSA_X_30_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_30_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_30_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_31                                                             0x1806E07C
#define  CP_RSA_X_31_reg_addr                                                    "0xB806E07C"
#define  CP_RSA_X_31_reg                                                         0xB806E07C
#define  CP_RSA_X_31_inst_addr                                                   "0x00F7"
#define  set_CP_RSA_X_31_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_31_reg)=data)
#define  get_CP_RSA_X_31_reg                                                     (*((volatile unsigned int*)CP_RSA_X_31_reg))
#define  CP_RSA_X_31_data_shift                                                  (0)
#define  CP_RSA_X_31_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_31_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_31_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_32                                                             0x1806E080
#define  CP_RSA_X_32_reg_addr                                                    "0xB806E080"
#define  CP_RSA_X_32_reg                                                         0xB806E080
#define  CP_RSA_X_32_inst_addr                                                   "0x00F8"
#define  set_CP_RSA_X_32_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_32_reg)=data)
#define  get_CP_RSA_X_32_reg                                                     (*((volatile unsigned int*)CP_RSA_X_32_reg))
#define  CP_RSA_X_32_data_shift                                                  (0)
#define  CP_RSA_X_32_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_32_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_32_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_33                                                             0x1806E084
#define  CP_RSA_X_33_reg_addr                                                    "0xB806E084"
#define  CP_RSA_X_33_reg                                                         0xB806E084
#define  CP_RSA_X_33_inst_addr                                                   "0x00F9"
#define  set_CP_RSA_X_33_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_33_reg)=data)
#define  get_CP_RSA_X_33_reg                                                     (*((volatile unsigned int*)CP_RSA_X_33_reg))
#define  CP_RSA_X_33_data_shift                                                  (0)
#define  CP_RSA_X_33_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_33_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_33_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_34                                                             0x1806E088
#define  CP_RSA_X_34_reg_addr                                                    "0xB806E088"
#define  CP_RSA_X_34_reg                                                         0xB806E088
#define  CP_RSA_X_34_inst_addr                                                   "0x00FA"
#define  set_CP_RSA_X_34_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_34_reg)=data)
#define  get_CP_RSA_X_34_reg                                                     (*((volatile unsigned int*)CP_RSA_X_34_reg))
#define  CP_RSA_X_34_data_shift                                                  (0)
#define  CP_RSA_X_34_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_34_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_34_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_35                                                             0x1806E08C
#define  CP_RSA_X_35_reg_addr                                                    "0xB806E08C"
#define  CP_RSA_X_35_reg                                                         0xB806E08C
#define  CP_RSA_X_35_inst_addr                                                   "0x00FB"
#define  set_CP_RSA_X_35_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_35_reg)=data)
#define  get_CP_RSA_X_35_reg                                                     (*((volatile unsigned int*)CP_RSA_X_35_reg))
#define  CP_RSA_X_35_data_shift                                                  (0)
#define  CP_RSA_X_35_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_35_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_35_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_36                                                             0x1806E090
#define  CP_RSA_X_36_reg_addr                                                    "0xB806E090"
#define  CP_RSA_X_36_reg                                                         0xB806E090
#define  CP_RSA_X_36_inst_addr                                                   "0x00FC"
#define  set_CP_RSA_X_36_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_36_reg)=data)
#define  get_CP_RSA_X_36_reg                                                     (*((volatile unsigned int*)CP_RSA_X_36_reg))
#define  CP_RSA_X_36_data_shift                                                  (0)
#define  CP_RSA_X_36_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_36_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_36_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_37                                                             0x1806E094
#define  CP_RSA_X_37_reg_addr                                                    "0xB806E094"
#define  CP_RSA_X_37_reg                                                         0xB806E094
#define  CP_RSA_X_37_inst_addr                                                   "0x00FD"
#define  set_CP_RSA_X_37_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_37_reg)=data)
#define  get_CP_RSA_X_37_reg                                                     (*((volatile unsigned int*)CP_RSA_X_37_reg))
#define  CP_RSA_X_37_data_shift                                                  (0)
#define  CP_RSA_X_37_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_37_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_37_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_38                                                             0x1806E098
#define  CP_RSA_X_38_reg_addr                                                    "0xB806E098"
#define  CP_RSA_X_38_reg                                                         0xB806E098
#define  CP_RSA_X_38_inst_addr                                                   "0x00FE"
#define  set_CP_RSA_X_38_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_38_reg)=data)
#define  get_CP_RSA_X_38_reg                                                     (*((volatile unsigned int*)CP_RSA_X_38_reg))
#define  CP_RSA_X_38_data_shift                                                  (0)
#define  CP_RSA_X_38_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_38_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_38_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_39                                                             0x1806E09C
#define  CP_RSA_X_39_reg_addr                                                    "0xB806E09C"
#define  CP_RSA_X_39_reg                                                         0xB806E09C
#define  CP_RSA_X_39_inst_addr                                                   "0x00FF"
#define  set_CP_RSA_X_39_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_39_reg)=data)
#define  get_CP_RSA_X_39_reg                                                     (*((volatile unsigned int*)CP_RSA_X_39_reg))
#define  CP_RSA_X_39_data_shift                                                  (0)
#define  CP_RSA_X_39_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_39_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_39_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_40                                                             0x1806E0A0
#define  CP_RSA_X_40_reg_addr                                                    "0xB806E0A0"
#define  CP_RSA_X_40_reg                                                         0xB806E0A0
#define  CP_RSA_X_40_inst_addr                                                   "0x0100"
#define  set_CP_RSA_X_40_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_40_reg)=data)
#define  get_CP_RSA_X_40_reg                                                     (*((volatile unsigned int*)CP_RSA_X_40_reg))
#define  CP_RSA_X_40_data_shift                                                  (0)
#define  CP_RSA_X_40_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_40_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_40_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_41                                                             0x1806E0A4
#define  CP_RSA_X_41_reg_addr                                                    "0xB806E0A4"
#define  CP_RSA_X_41_reg                                                         0xB806E0A4
#define  CP_RSA_X_41_inst_addr                                                   "0x0101"
#define  set_CP_RSA_X_41_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_41_reg)=data)
#define  get_CP_RSA_X_41_reg                                                     (*((volatile unsigned int*)CP_RSA_X_41_reg))
#define  CP_RSA_X_41_data_shift                                                  (0)
#define  CP_RSA_X_41_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_41_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_41_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_42                                                             0x1806E0A8
#define  CP_RSA_X_42_reg_addr                                                    "0xB806E0A8"
#define  CP_RSA_X_42_reg                                                         0xB806E0A8
#define  CP_RSA_X_42_inst_addr                                                   "0x0102"
#define  set_CP_RSA_X_42_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_42_reg)=data)
#define  get_CP_RSA_X_42_reg                                                     (*((volatile unsigned int*)CP_RSA_X_42_reg))
#define  CP_RSA_X_42_data_shift                                                  (0)
#define  CP_RSA_X_42_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_42_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_42_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_43                                                             0x1806E0AC
#define  CP_RSA_X_43_reg_addr                                                    "0xB806E0AC"
#define  CP_RSA_X_43_reg                                                         0xB806E0AC
#define  CP_RSA_X_43_inst_addr                                                   "0x0103"
#define  set_CP_RSA_X_43_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_43_reg)=data)
#define  get_CP_RSA_X_43_reg                                                     (*((volatile unsigned int*)CP_RSA_X_43_reg))
#define  CP_RSA_X_43_data_shift                                                  (0)
#define  CP_RSA_X_43_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_43_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_43_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_44                                                             0x1806E0B0
#define  CP_RSA_X_44_reg_addr                                                    "0xB806E0B0"
#define  CP_RSA_X_44_reg                                                         0xB806E0B0
#define  CP_RSA_X_44_inst_addr                                                   "0x0104"
#define  set_CP_RSA_X_44_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_44_reg)=data)
#define  get_CP_RSA_X_44_reg                                                     (*((volatile unsigned int*)CP_RSA_X_44_reg))
#define  CP_RSA_X_44_data_shift                                                  (0)
#define  CP_RSA_X_44_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_44_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_44_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_45                                                             0x1806E0B4
#define  CP_RSA_X_45_reg_addr                                                    "0xB806E0B4"
#define  CP_RSA_X_45_reg                                                         0xB806E0B4
#define  CP_RSA_X_45_inst_addr                                                   "0x0105"
#define  set_CP_RSA_X_45_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_45_reg)=data)
#define  get_CP_RSA_X_45_reg                                                     (*((volatile unsigned int*)CP_RSA_X_45_reg))
#define  CP_RSA_X_45_data_shift                                                  (0)
#define  CP_RSA_X_45_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_45_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_45_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_46                                                             0x1806E0B8
#define  CP_RSA_X_46_reg_addr                                                    "0xB806E0B8"
#define  CP_RSA_X_46_reg                                                         0xB806E0B8
#define  CP_RSA_X_46_inst_addr                                                   "0x0106"
#define  set_CP_RSA_X_46_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_46_reg)=data)
#define  get_CP_RSA_X_46_reg                                                     (*((volatile unsigned int*)CP_RSA_X_46_reg))
#define  CP_RSA_X_46_data_shift                                                  (0)
#define  CP_RSA_X_46_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_46_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_46_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_47                                                             0x1806E0BC
#define  CP_RSA_X_47_reg_addr                                                    "0xB806E0BC"
#define  CP_RSA_X_47_reg                                                         0xB806E0BC
#define  CP_RSA_X_47_inst_addr                                                   "0x0107"
#define  set_CP_RSA_X_47_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_47_reg)=data)
#define  get_CP_RSA_X_47_reg                                                     (*((volatile unsigned int*)CP_RSA_X_47_reg))
#define  CP_RSA_X_47_data_shift                                                  (0)
#define  CP_RSA_X_47_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_47_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_47_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_48                                                             0x1806E0C0
#define  CP_RSA_X_48_reg_addr                                                    "0xB806E0C0"
#define  CP_RSA_X_48_reg                                                         0xB806E0C0
#define  CP_RSA_X_48_inst_addr                                                   "0x0108"
#define  set_CP_RSA_X_48_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_48_reg)=data)
#define  get_CP_RSA_X_48_reg                                                     (*((volatile unsigned int*)CP_RSA_X_48_reg))
#define  CP_RSA_X_48_data_shift                                                  (0)
#define  CP_RSA_X_48_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_48_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_48_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_49                                                             0x1806E0C4
#define  CP_RSA_X_49_reg_addr                                                    "0xB806E0C4"
#define  CP_RSA_X_49_reg                                                         0xB806E0C4
#define  CP_RSA_X_49_inst_addr                                                   "0x0109"
#define  set_CP_RSA_X_49_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_49_reg)=data)
#define  get_CP_RSA_X_49_reg                                                     (*((volatile unsigned int*)CP_RSA_X_49_reg))
#define  CP_RSA_X_49_data_shift                                                  (0)
#define  CP_RSA_X_49_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_49_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_49_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_50                                                             0x1806E0C8
#define  CP_RSA_X_50_reg_addr                                                    "0xB806E0C8"
#define  CP_RSA_X_50_reg                                                         0xB806E0C8
#define  CP_RSA_X_50_inst_addr                                                   "0x010A"
#define  set_CP_RSA_X_50_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_50_reg)=data)
#define  get_CP_RSA_X_50_reg                                                     (*((volatile unsigned int*)CP_RSA_X_50_reg))
#define  CP_RSA_X_50_data_shift                                                  (0)
#define  CP_RSA_X_50_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_50_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_50_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_51                                                             0x1806E0CC
#define  CP_RSA_X_51_reg_addr                                                    "0xB806E0CC"
#define  CP_RSA_X_51_reg                                                         0xB806E0CC
#define  CP_RSA_X_51_inst_addr                                                   "0x010B"
#define  set_CP_RSA_X_51_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_51_reg)=data)
#define  get_CP_RSA_X_51_reg                                                     (*((volatile unsigned int*)CP_RSA_X_51_reg))
#define  CP_RSA_X_51_data_shift                                                  (0)
#define  CP_RSA_X_51_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_51_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_51_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_52                                                             0x1806E0D0
#define  CP_RSA_X_52_reg_addr                                                    "0xB806E0D0"
#define  CP_RSA_X_52_reg                                                         0xB806E0D0
#define  CP_RSA_X_52_inst_addr                                                   "0x010C"
#define  set_CP_RSA_X_52_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_52_reg)=data)
#define  get_CP_RSA_X_52_reg                                                     (*((volatile unsigned int*)CP_RSA_X_52_reg))
#define  CP_RSA_X_52_data_shift                                                  (0)
#define  CP_RSA_X_52_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_52_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_52_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_53                                                             0x1806E0D4
#define  CP_RSA_X_53_reg_addr                                                    "0xB806E0D4"
#define  CP_RSA_X_53_reg                                                         0xB806E0D4
#define  CP_RSA_X_53_inst_addr                                                   "0x010D"
#define  set_CP_RSA_X_53_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_53_reg)=data)
#define  get_CP_RSA_X_53_reg                                                     (*((volatile unsigned int*)CP_RSA_X_53_reg))
#define  CP_RSA_X_53_data_shift                                                  (0)
#define  CP_RSA_X_53_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_53_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_53_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_54                                                             0x1806E0D8
#define  CP_RSA_X_54_reg_addr                                                    "0xB806E0D8"
#define  CP_RSA_X_54_reg                                                         0xB806E0D8
#define  CP_RSA_X_54_inst_addr                                                   "0x010E"
#define  set_CP_RSA_X_54_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_54_reg)=data)
#define  get_CP_RSA_X_54_reg                                                     (*((volatile unsigned int*)CP_RSA_X_54_reg))
#define  CP_RSA_X_54_data_shift                                                  (0)
#define  CP_RSA_X_54_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_54_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_54_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_55                                                             0x1806E0DC
#define  CP_RSA_X_55_reg_addr                                                    "0xB806E0DC"
#define  CP_RSA_X_55_reg                                                         0xB806E0DC
#define  CP_RSA_X_55_inst_addr                                                   "0x010F"
#define  set_CP_RSA_X_55_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_55_reg)=data)
#define  get_CP_RSA_X_55_reg                                                     (*((volatile unsigned int*)CP_RSA_X_55_reg))
#define  CP_RSA_X_55_data_shift                                                  (0)
#define  CP_RSA_X_55_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_55_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_55_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_56                                                             0x1806E0E0
#define  CP_RSA_X_56_reg_addr                                                    "0xB806E0E0"
#define  CP_RSA_X_56_reg                                                         0xB806E0E0
#define  CP_RSA_X_56_inst_addr                                                   "0x0110"
#define  set_CP_RSA_X_56_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_56_reg)=data)
#define  get_CP_RSA_X_56_reg                                                     (*((volatile unsigned int*)CP_RSA_X_56_reg))
#define  CP_RSA_X_56_data_shift                                                  (0)
#define  CP_RSA_X_56_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_56_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_56_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_57                                                             0x1806E0E4
#define  CP_RSA_X_57_reg_addr                                                    "0xB806E0E4"
#define  CP_RSA_X_57_reg                                                         0xB806E0E4
#define  CP_RSA_X_57_inst_addr                                                   "0x0111"
#define  set_CP_RSA_X_57_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_57_reg)=data)
#define  get_CP_RSA_X_57_reg                                                     (*((volatile unsigned int*)CP_RSA_X_57_reg))
#define  CP_RSA_X_57_data_shift                                                  (0)
#define  CP_RSA_X_57_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_57_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_57_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_58                                                             0x1806E0E8
#define  CP_RSA_X_58_reg_addr                                                    "0xB806E0E8"
#define  CP_RSA_X_58_reg                                                         0xB806E0E8
#define  CP_RSA_X_58_inst_addr                                                   "0x0112"
#define  set_CP_RSA_X_58_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_58_reg)=data)
#define  get_CP_RSA_X_58_reg                                                     (*((volatile unsigned int*)CP_RSA_X_58_reg))
#define  CP_RSA_X_58_data_shift                                                  (0)
#define  CP_RSA_X_58_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_58_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_58_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_59                                                             0x1806E0EC
#define  CP_RSA_X_59_reg_addr                                                    "0xB806E0EC"
#define  CP_RSA_X_59_reg                                                         0xB806E0EC
#define  CP_RSA_X_59_inst_addr                                                   "0x0113"
#define  set_CP_RSA_X_59_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_59_reg)=data)
#define  get_CP_RSA_X_59_reg                                                     (*((volatile unsigned int*)CP_RSA_X_59_reg))
#define  CP_RSA_X_59_data_shift                                                  (0)
#define  CP_RSA_X_59_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_59_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_59_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_60                                                             0x1806E0F0
#define  CP_RSA_X_60_reg_addr                                                    "0xB806E0F0"
#define  CP_RSA_X_60_reg                                                         0xB806E0F0
#define  CP_RSA_X_60_inst_addr                                                   "0x0114"
#define  set_CP_RSA_X_60_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_60_reg)=data)
#define  get_CP_RSA_X_60_reg                                                     (*((volatile unsigned int*)CP_RSA_X_60_reg))
#define  CP_RSA_X_60_data_shift                                                  (0)
#define  CP_RSA_X_60_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_60_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_60_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_61                                                             0x1806E0F4
#define  CP_RSA_X_61_reg_addr                                                    "0xB806E0F4"
#define  CP_RSA_X_61_reg                                                         0xB806E0F4
#define  CP_RSA_X_61_inst_addr                                                   "0x0115"
#define  set_CP_RSA_X_61_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_61_reg)=data)
#define  get_CP_RSA_X_61_reg                                                     (*((volatile unsigned int*)CP_RSA_X_61_reg))
#define  CP_RSA_X_61_data_shift                                                  (0)
#define  CP_RSA_X_61_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_61_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_61_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_62                                                             0x1806E0F8
#define  CP_RSA_X_62_reg_addr                                                    "0xB806E0F8"
#define  CP_RSA_X_62_reg                                                         0xB806E0F8
#define  CP_RSA_X_62_inst_addr                                                   "0x0116"
#define  set_CP_RSA_X_62_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_62_reg)=data)
#define  get_CP_RSA_X_62_reg                                                     (*((volatile unsigned int*)CP_RSA_X_62_reg))
#define  CP_RSA_X_62_data_shift                                                  (0)
#define  CP_RSA_X_62_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_62_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_62_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_X_63                                                             0x1806E0FC
#define  CP_RSA_X_63_reg_addr                                                    "0xB806E0FC"
#define  CP_RSA_X_63_reg                                                         0xB806E0FC
#define  CP_RSA_X_63_inst_addr                                                   "0x0117"
#define  set_CP_RSA_X_63_reg(data)                                               (*((volatile unsigned int*)CP_RSA_X_63_reg)=data)
#define  get_CP_RSA_X_63_reg                                                     (*((volatile unsigned int*)CP_RSA_X_63_reg))
#define  CP_RSA_X_63_data_shift                                                  (0)
#define  CP_RSA_X_63_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_X_63_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_X_63_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_0                                                              0x1806E100
#define  CP_RSA_Y_0_reg_addr                                                     "0xB806E100"
#define  CP_RSA_Y_0_reg                                                          0xB806E100
#define  CP_RSA_Y_0_inst_addr                                                    "0x0118"
#define  set_CP_RSA_Y_0_reg(data)                                                (*((volatile unsigned int*)CP_RSA_Y_0_reg)=data)
#define  get_CP_RSA_Y_0_reg                                                      (*((volatile unsigned int*)CP_RSA_Y_0_reg))
#define  CP_RSA_Y_0_data_shift                                                   (0)
#define  CP_RSA_Y_0_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_Y_0_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_Y_0_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_Y_1                                                              0x1806E104
#define  CP_RSA_Y_1_reg_addr                                                     "0xB806E104"
#define  CP_RSA_Y_1_reg                                                          0xB806E104
#define  CP_RSA_Y_1_inst_addr                                                    "0x0119"
#define  set_CP_RSA_Y_1_reg(data)                                                (*((volatile unsigned int*)CP_RSA_Y_1_reg)=data)
#define  get_CP_RSA_Y_1_reg                                                      (*((volatile unsigned int*)CP_RSA_Y_1_reg))
#define  CP_RSA_Y_1_data_shift                                                   (0)
#define  CP_RSA_Y_1_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_Y_1_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_Y_1_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_Y_2                                                              0x1806E108
#define  CP_RSA_Y_2_reg_addr                                                     "0xB806E108"
#define  CP_RSA_Y_2_reg                                                          0xB806E108
#define  CP_RSA_Y_2_inst_addr                                                    "0x011A"
#define  set_CP_RSA_Y_2_reg(data)                                                (*((volatile unsigned int*)CP_RSA_Y_2_reg)=data)
#define  get_CP_RSA_Y_2_reg                                                      (*((volatile unsigned int*)CP_RSA_Y_2_reg))
#define  CP_RSA_Y_2_data_shift                                                   (0)
#define  CP_RSA_Y_2_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_Y_2_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_Y_2_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_Y_3                                                              0x1806E10C
#define  CP_RSA_Y_3_reg_addr                                                     "0xB806E10C"
#define  CP_RSA_Y_3_reg                                                          0xB806E10C
#define  CP_RSA_Y_3_inst_addr                                                    "0x011B"
#define  set_CP_RSA_Y_3_reg(data)                                                (*((volatile unsigned int*)CP_RSA_Y_3_reg)=data)
#define  get_CP_RSA_Y_3_reg                                                      (*((volatile unsigned int*)CP_RSA_Y_3_reg))
#define  CP_RSA_Y_3_data_shift                                                   (0)
#define  CP_RSA_Y_3_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_Y_3_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_Y_3_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_Y_4                                                              0x1806E110
#define  CP_RSA_Y_4_reg_addr                                                     "0xB806E110"
#define  CP_RSA_Y_4_reg                                                          0xB806E110
#define  CP_RSA_Y_4_inst_addr                                                    "0x011C"
#define  set_CP_RSA_Y_4_reg(data)                                                (*((volatile unsigned int*)CP_RSA_Y_4_reg)=data)
#define  get_CP_RSA_Y_4_reg                                                      (*((volatile unsigned int*)CP_RSA_Y_4_reg))
#define  CP_RSA_Y_4_data_shift                                                   (0)
#define  CP_RSA_Y_4_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_Y_4_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_Y_4_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_Y_5                                                              0x1806E114
#define  CP_RSA_Y_5_reg_addr                                                     "0xB806E114"
#define  CP_RSA_Y_5_reg                                                          0xB806E114
#define  CP_RSA_Y_5_inst_addr                                                    "0x011D"
#define  set_CP_RSA_Y_5_reg(data)                                                (*((volatile unsigned int*)CP_RSA_Y_5_reg)=data)
#define  get_CP_RSA_Y_5_reg                                                      (*((volatile unsigned int*)CP_RSA_Y_5_reg))
#define  CP_RSA_Y_5_data_shift                                                   (0)
#define  CP_RSA_Y_5_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_Y_5_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_Y_5_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_Y_6                                                              0x1806E118
#define  CP_RSA_Y_6_reg_addr                                                     "0xB806E118"
#define  CP_RSA_Y_6_reg                                                          0xB806E118
#define  CP_RSA_Y_6_inst_addr                                                    "0x011E"
#define  set_CP_RSA_Y_6_reg(data)                                                (*((volatile unsigned int*)CP_RSA_Y_6_reg)=data)
#define  get_CP_RSA_Y_6_reg                                                      (*((volatile unsigned int*)CP_RSA_Y_6_reg))
#define  CP_RSA_Y_6_data_shift                                                   (0)
#define  CP_RSA_Y_6_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_Y_6_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_Y_6_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_Y_7                                                              0x1806E11C
#define  CP_RSA_Y_7_reg_addr                                                     "0xB806E11C"
#define  CP_RSA_Y_7_reg                                                          0xB806E11C
#define  CP_RSA_Y_7_inst_addr                                                    "0x011F"
#define  set_CP_RSA_Y_7_reg(data)                                                (*((volatile unsigned int*)CP_RSA_Y_7_reg)=data)
#define  get_CP_RSA_Y_7_reg                                                      (*((volatile unsigned int*)CP_RSA_Y_7_reg))
#define  CP_RSA_Y_7_data_shift                                                   (0)
#define  CP_RSA_Y_7_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_Y_7_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_Y_7_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_Y_8                                                              0x1806E120
#define  CP_RSA_Y_8_reg_addr                                                     "0xB806E120"
#define  CP_RSA_Y_8_reg                                                          0xB806E120
#define  CP_RSA_Y_8_inst_addr                                                    "0x0120"
#define  set_CP_RSA_Y_8_reg(data)                                                (*((volatile unsigned int*)CP_RSA_Y_8_reg)=data)
#define  get_CP_RSA_Y_8_reg                                                      (*((volatile unsigned int*)CP_RSA_Y_8_reg))
#define  CP_RSA_Y_8_data_shift                                                   (0)
#define  CP_RSA_Y_8_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_Y_8_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_Y_8_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_Y_9                                                              0x1806E124
#define  CP_RSA_Y_9_reg_addr                                                     "0xB806E124"
#define  CP_RSA_Y_9_reg                                                          0xB806E124
#define  CP_RSA_Y_9_inst_addr                                                    "0x0121"
#define  set_CP_RSA_Y_9_reg(data)                                                (*((volatile unsigned int*)CP_RSA_Y_9_reg)=data)
#define  get_CP_RSA_Y_9_reg                                                      (*((volatile unsigned int*)CP_RSA_Y_9_reg))
#define  CP_RSA_Y_9_data_shift                                                   (0)
#define  CP_RSA_Y_9_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_Y_9_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_Y_9_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_Y_10                                                             0x1806E128
#define  CP_RSA_Y_10_reg_addr                                                    "0xB806E128"
#define  CP_RSA_Y_10_reg                                                         0xB806E128
#define  CP_RSA_Y_10_inst_addr                                                   "0x0122"
#define  set_CP_RSA_Y_10_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_10_reg)=data)
#define  get_CP_RSA_Y_10_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_10_reg))
#define  CP_RSA_Y_10_data_shift                                                  (0)
#define  CP_RSA_Y_10_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_10_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_10_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_11                                                             0x1806E12C
#define  CP_RSA_Y_11_reg_addr                                                    "0xB806E12C"
#define  CP_RSA_Y_11_reg                                                         0xB806E12C
#define  CP_RSA_Y_11_inst_addr                                                   "0x0123"
#define  set_CP_RSA_Y_11_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_11_reg)=data)
#define  get_CP_RSA_Y_11_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_11_reg))
#define  CP_RSA_Y_11_data_shift                                                  (0)
#define  CP_RSA_Y_11_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_11_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_11_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_12                                                             0x1806E130
#define  CP_RSA_Y_12_reg_addr                                                    "0xB806E130"
#define  CP_RSA_Y_12_reg                                                         0xB806E130
#define  CP_RSA_Y_12_inst_addr                                                   "0x0124"
#define  set_CP_RSA_Y_12_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_12_reg)=data)
#define  get_CP_RSA_Y_12_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_12_reg))
#define  CP_RSA_Y_12_data_shift                                                  (0)
#define  CP_RSA_Y_12_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_12_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_12_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_13                                                             0x1806E134
#define  CP_RSA_Y_13_reg_addr                                                    "0xB806E134"
#define  CP_RSA_Y_13_reg                                                         0xB806E134
#define  CP_RSA_Y_13_inst_addr                                                   "0x0125"
#define  set_CP_RSA_Y_13_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_13_reg)=data)
#define  get_CP_RSA_Y_13_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_13_reg))
#define  CP_RSA_Y_13_data_shift                                                  (0)
#define  CP_RSA_Y_13_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_13_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_13_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_14                                                             0x1806E138
#define  CP_RSA_Y_14_reg_addr                                                    "0xB806E138"
#define  CP_RSA_Y_14_reg                                                         0xB806E138
#define  CP_RSA_Y_14_inst_addr                                                   "0x0126"
#define  set_CP_RSA_Y_14_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_14_reg)=data)
#define  get_CP_RSA_Y_14_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_14_reg))
#define  CP_RSA_Y_14_data_shift                                                  (0)
#define  CP_RSA_Y_14_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_14_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_14_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_15                                                             0x1806E13C
#define  CP_RSA_Y_15_reg_addr                                                    "0xB806E13C"
#define  CP_RSA_Y_15_reg                                                         0xB806E13C
#define  CP_RSA_Y_15_inst_addr                                                   "0x0127"
#define  set_CP_RSA_Y_15_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_15_reg)=data)
#define  get_CP_RSA_Y_15_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_15_reg))
#define  CP_RSA_Y_15_data_shift                                                  (0)
#define  CP_RSA_Y_15_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_15_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_15_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_16                                                             0x1806E140
#define  CP_RSA_Y_16_reg_addr                                                    "0xB806E140"
#define  CP_RSA_Y_16_reg                                                         0xB806E140
#define  CP_RSA_Y_16_inst_addr                                                   "0x0128"
#define  set_CP_RSA_Y_16_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_16_reg)=data)
#define  get_CP_RSA_Y_16_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_16_reg))
#define  CP_RSA_Y_16_data_shift                                                  (0)
#define  CP_RSA_Y_16_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_16_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_16_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_17                                                             0x1806E144
#define  CP_RSA_Y_17_reg_addr                                                    "0xB806E144"
#define  CP_RSA_Y_17_reg                                                         0xB806E144
#define  CP_RSA_Y_17_inst_addr                                                   "0x0129"
#define  set_CP_RSA_Y_17_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_17_reg)=data)
#define  get_CP_RSA_Y_17_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_17_reg))
#define  CP_RSA_Y_17_data_shift                                                  (0)
#define  CP_RSA_Y_17_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_17_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_17_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_18                                                             0x1806E148
#define  CP_RSA_Y_18_reg_addr                                                    "0xB806E148"
#define  CP_RSA_Y_18_reg                                                         0xB806E148
#define  CP_RSA_Y_18_inst_addr                                                   "0x012A"
#define  set_CP_RSA_Y_18_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_18_reg)=data)
#define  get_CP_RSA_Y_18_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_18_reg))
#define  CP_RSA_Y_18_data_shift                                                  (0)
#define  CP_RSA_Y_18_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_18_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_18_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_19                                                             0x1806E14C
#define  CP_RSA_Y_19_reg_addr                                                    "0xB806E14C"
#define  CP_RSA_Y_19_reg                                                         0xB806E14C
#define  CP_RSA_Y_19_inst_addr                                                   "0x012B"
#define  set_CP_RSA_Y_19_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_19_reg)=data)
#define  get_CP_RSA_Y_19_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_19_reg))
#define  CP_RSA_Y_19_data_shift                                                  (0)
#define  CP_RSA_Y_19_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_19_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_19_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_20                                                             0x1806E150
#define  CP_RSA_Y_20_reg_addr                                                    "0xB806E150"
#define  CP_RSA_Y_20_reg                                                         0xB806E150
#define  CP_RSA_Y_20_inst_addr                                                   "0x012C"
#define  set_CP_RSA_Y_20_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_20_reg)=data)
#define  get_CP_RSA_Y_20_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_20_reg))
#define  CP_RSA_Y_20_data_shift                                                  (0)
#define  CP_RSA_Y_20_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_20_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_20_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_21                                                             0x1806E154
#define  CP_RSA_Y_21_reg_addr                                                    "0xB806E154"
#define  CP_RSA_Y_21_reg                                                         0xB806E154
#define  CP_RSA_Y_21_inst_addr                                                   "0x012D"
#define  set_CP_RSA_Y_21_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_21_reg)=data)
#define  get_CP_RSA_Y_21_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_21_reg))
#define  CP_RSA_Y_21_data_shift                                                  (0)
#define  CP_RSA_Y_21_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_21_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_21_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_22                                                             0x1806E158
#define  CP_RSA_Y_22_reg_addr                                                    "0xB806E158"
#define  CP_RSA_Y_22_reg                                                         0xB806E158
#define  CP_RSA_Y_22_inst_addr                                                   "0x012E"
#define  set_CP_RSA_Y_22_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_22_reg)=data)
#define  get_CP_RSA_Y_22_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_22_reg))
#define  CP_RSA_Y_22_data_shift                                                  (0)
#define  CP_RSA_Y_22_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_22_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_22_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_23                                                             0x1806E15C
#define  CP_RSA_Y_23_reg_addr                                                    "0xB806E15C"
#define  CP_RSA_Y_23_reg                                                         0xB806E15C
#define  CP_RSA_Y_23_inst_addr                                                   "0x012F"
#define  set_CP_RSA_Y_23_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_23_reg)=data)
#define  get_CP_RSA_Y_23_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_23_reg))
#define  CP_RSA_Y_23_data_shift                                                  (0)
#define  CP_RSA_Y_23_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_23_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_23_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_24                                                             0x1806E160
#define  CP_RSA_Y_24_reg_addr                                                    "0xB806E160"
#define  CP_RSA_Y_24_reg                                                         0xB806E160
#define  CP_RSA_Y_24_inst_addr                                                   "0x0130"
#define  set_CP_RSA_Y_24_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_24_reg)=data)
#define  get_CP_RSA_Y_24_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_24_reg))
#define  CP_RSA_Y_24_data_shift                                                  (0)
#define  CP_RSA_Y_24_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_24_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_24_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_25                                                             0x1806E164
#define  CP_RSA_Y_25_reg_addr                                                    "0xB806E164"
#define  CP_RSA_Y_25_reg                                                         0xB806E164
#define  CP_RSA_Y_25_inst_addr                                                   "0x0131"
#define  set_CP_RSA_Y_25_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_25_reg)=data)
#define  get_CP_RSA_Y_25_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_25_reg))
#define  CP_RSA_Y_25_data_shift                                                  (0)
#define  CP_RSA_Y_25_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_25_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_25_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_26                                                             0x1806E168
#define  CP_RSA_Y_26_reg_addr                                                    "0xB806E168"
#define  CP_RSA_Y_26_reg                                                         0xB806E168
#define  CP_RSA_Y_26_inst_addr                                                   "0x0132"
#define  set_CP_RSA_Y_26_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_26_reg)=data)
#define  get_CP_RSA_Y_26_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_26_reg))
#define  CP_RSA_Y_26_data_shift                                                  (0)
#define  CP_RSA_Y_26_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_26_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_26_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_27                                                             0x1806E16C
#define  CP_RSA_Y_27_reg_addr                                                    "0xB806E16C"
#define  CP_RSA_Y_27_reg                                                         0xB806E16C
#define  CP_RSA_Y_27_inst_addr                                                   "0x0133"
#define  set_CP_RSA_Y_27_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_27_reg)=data)
#define  get_CP_RSA_Y_27_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_27_reg))
#define  CP_RSA_Y_27_data_shift                                                  (0)
#define  CP_RSA_Y_27_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_27_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_27_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_28                                                             0x1806E170
#define  CP_RSA_Y_28_reg_addr                                                    "0xB806E170"
#define  CP_RSA_Y_28_reg                                                         0xB806E170
#define  CP_RSA_Y_28_inst_addr                                                   "0x0134"
#define  set_CP_RSA_Y_28_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_28_reg)=data)
#define  get_CP_RSA_Y_28_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_28_reg))
#define  CP_RSA_Y_28_data_shift                                                  (0)
#define  CP_RSA_Y_28_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_28_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_28_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_29                                                             0x1806E174
#define  CP_RSA_Y_29_reg_addr                                                    "0xB806E174"
#define  CP_RSA_Y_29_reg                                                         0xB806E174
#define  CP_RSA_Y_29_inst_addr                                                   "0x0135"
#define  set_CP_RSA_Y_29_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_29_reg)=data)
#define  get_CP_RSA_Y_29_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_29_reg))
#define  CP_RSA_Y_29_data_shift                                                  (0)
#define  CP_RSA_Y_29_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_29_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_29_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_30                                                             0x1806E178
#define  CP_RSA_Y_30_reg_addr                                                    "0xB806E178"
#define  CP_RSA_Y_30_reg                                                         0xB806E178
#define  CP_RSA_Y_30_inst_addr                                                   "0x0136"
#define  set_CP_RSA_Y_30_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_30_reg)=data)
#define  get_CP_RSA_Y_30_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_30_reg))
#define  CP_RSA_Y_30_data_shift                                                  (0)
#define  CP_RSA_Y_30_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_30_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_30_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_31                                                             0x1806E17C
#define  CP_RSA_Y_31_reg_addr                                                    "0xB806E17C"
#define  CP_RSA_Y_31_reg                                                         0xB806E17C
#define  CP_RSA_Y_31_inst_addr                                                   "0x0137"
#define  set_CP_RSA_Y_31_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_31_reg)=data)
#define  get_CP_RSA_Y_31_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_31_reg))
#define  CP_RSA_Y_31_data_shift                                                  (0)
#define  CP_RSA_Y_31_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_31_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_31_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_32                                                             0x1806E180
#define  CP_RSA_Y_32_reg_addr                                                    "0xB806E180"
#define  CP_RSA_Y_32_reg                                                         0xB806E180
#define  CP_RSA_Y_32_inst_addr                                                   "0x0138"
#define  set_CP_RSA_Y_32_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_32_reg)=data)
#define  get_CP_RSA_Y_32_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_32_reg))
#define  CP_RSA_Y_32_data_shift                                                  (0)
#define  CP_RSA_Y_32_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_32_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_32_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_33                                                             0x1806E184
#define  CP_RSA_Y_33_reg_addr                                                    "0xB806E184"
#define  CP_RSA_Y_33_reg                                                         0xB806E184
#define  CP_RSA_Y_33_inst_addr                                                   "0x0139"
#define  set_CP_RSA_Y_33_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_33_reg)=data)
#define  get_CP_RSA_Y_33_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_33_reg))
#define  CP_RSA_Y_33_data_shift                                                  (0)
#define  CP_RSA_Y_33_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_33_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_33_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_34                                                             0x1806E188
#define  CP_RSA_Y_34_reg_addr                                                    "0xB806E188"
#define  CP_RSA_Y_34_reg                                                         0xB806E188
#define  CP_RSA_Y_34_inst_addr                                                   "0x013A"
#define  set_CP_RSA_Y_34_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_34_reg)=data)
#define  get_CP_RSA_Y_34_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_34_reg))
#define  CP_RSA_Y_34_data_shift                                                  (0)
#define  CP_RSA_Y_34_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_34_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_34_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_35                                                             0x1806E18C
#define  CP_RSA_Y_35_reg_addr                                                    "0xB806E18C"
#define  CP_RSA_Y_35_reg                                                         0xB806E18C
#define  CP_RSA_Y_35_inst_addr                                                   "0x013B"
#define  set_CP_RSA_Y_35_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_35_reg)=data)
#define  get_CP_RSA_Y_35_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_35_reg))
#define  CP_RSA_Y_35_data_shift                                                  (0)
#define  CP_RSA_Y_35_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_35_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_35_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_36                                                             0x1806E190
#define  CP_RSA_Y_36_reg_addr                                                    "0xB806E190"
#define  CP_RSA_Y_36_reg                                                         0xB806E190
#define  CP_RSA_Y_36_inst_addr                                                   "0x013C"
#define  set_CP_RSA_Y_36_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_36_reg)=data)
#define  get_CP_RSA_Y_36_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_36_reg))
#define  CP_RSA_Y_36_data_shift                                                  (0)
#define  CP_RSA_Y_36_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_36_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_36_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_37                                                             0x1806E194
#define  CP_RSA_Y_37_reg_addr                                                    "0xB806E194"
#define  CP_RSA_Y_37_reg                                                         0xB806E194
#define  CP_RSA_Y_37_inst_addr                                                   "0x013D"
#define  set_CP_RSA_Y_37_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_37_reg)=data)
#define  get_CP_RSA_Y_37_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_37_reg))
#define  CP_RSA_Y_37_data_shift                                                  (0)
#define  CP_RSA_Y_37_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_37_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_37_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_38                                                             0x1806E198
#define  CP_RSA_Y_38_reg_addr                                                    "0xB806E198"
#define  CP_RSA_Y_38_reg                                                         0xB806E198
#define  CP_RSA_Y_38_inst_addr                                                   "0x013E"
#define  set_CP_RSA_Y_38_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_38_reg)=data)
#define  get_CP_RSA_Y_38_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_38_reg))
#define  CP_RSA_Y_38_data_shift                                                  (0)
#define  CP_RSA_Y_38_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_38_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_38_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_39                                                             0x1806E19C
#define  CP_RSA_Y_39_reg_addr                                                    "0xB806E19C"
#define  CP_RSA_Y_39_reg                                                         0xB806E19C
#define  CP_RSA_Y_39_inst_addr                                                   "0x013F"
#define  set_CP_RSA_Y_39_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_39_reg)=data)
#define  get_CP_RSA_Y_39_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_39_reg))
#define  CP_RSA_Y_39_data_shift                                                  (0)
#define  CP_RSA_Y_39_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_39_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_39_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_40                                                             0x1806E1A0
#define  CP_RSA_Y_40_reg_addr                                                    "0xB806E1A0"
#define  CP_RSA_Y_40_reg                                                         0xB806E1A0
#define  CP_RSA_Y_40_inst_addr                                                   "0x0140"
#define  set_CP_RSA_Y_40_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_40_reg)=data)
#define  get_CP_RSA_Y_40_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_40_reg))
#define  CP_RSA_Y_40_data_shift                                                  (0)
#define  CP_RSA_Y_40_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_40_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_40_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_41                                                             0x1806E1A4
#define  CP_RSA_Y_41_reg_addr                                                    "0xB806E1A4"
#define  CP_RSA_Y_41_reg                                                         0xB806E1A4
#define  CP_RSA_Y_41_inst_addr                                                   "0x0141"
#define  set_CP_RSA_Y_41_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_41_reg)=data)
#define  get_CP_RSA_Y_41_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_41_reg))
#define  CP_RSA_Y_41_data_shift                                                  (0)
#define  CP_RSA_Y_41_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_41_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_41_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_42                                                             0x1806E1A8
#define  CP_RSA_Y_42_reg_addr                                                    "0xB806E1A8"
#define  CP_RSA_Y_42_reg                                                         0xB806E1A8
#define  CP_RSA_Y_42_inst_addr                                                   "0x0142"
#define  set_CP_RSA_Y_42_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_42_reg)=data)
#define  get_CP_RSA_Y_42_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_42_reg))
#define  CP_RSA_Y_42_data_shift                                                  (0)
#define  CP_RSA_Y_42_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_42_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_42_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_43                                                             0x1806E1AC
#define  CP_RSA_Y_43_reg_addr                                                    "0xB806E1AC"
#define  CP_RSA_Y_43_reg                                                         0xB806E1AC
#define  CP_RSA_Y_43_inst_addr                                                   "0x0143"
#define  set_CP_RSA_Y_43_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_43_reg)=data)
#define  get_CP_RSA_Y_43_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_43_reg))
#define  CP_RSA_Y_43_data_shift                                                  (0)
#define  CP_RSA_Y_43_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_43_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_43_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_44                                                             0x1806E1B0
#define  CP_RSA_Y_44_reg_addr                                                    "0xB806E1B0"
#define  CP_RSA_Y_44_reg                                                         0xB806E1B0
#define  CP_RSA_Y_44_inst_addr                                                   "0x0144"
#define  set_CP_RSA_Y_44_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_44_reg)=data)
#define  get_CP_RSA_Y_44_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_44_reg))
#define  CP_RSA_Y_44_data_shift                                                  (0)
#define  CP_RSA_Y_44_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_44_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_44_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_45                                                             0x1806E1B4
#define  CP_RSA_Y_45_reg_addr                                                    "0xB806E1B4"
#define  CP_RSA_Y_45_reg                                                         0xB806E1B4
#define  CP_RSA_Y_45_inst_addr                                                   "0x0145"
#define  set_CP_RSA_Y_45_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_45_reg)=data)
#define  get_CP_RSA_Y_45_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_45_reg))
#define  CP_RSA_Y_45_data_shift                                                  (0)
#define  CP_RSA_Y_45_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_45_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_45_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_46                                                             0x1806E1B8
#define  CP_RSA_Y_46_reg_addr                                                    "0xB806E1B8"
#define  CP_RSA_Y_46_reg                                                         0xB806E1B8
#define  CP_RSA_Y_46_inst_addr                                                   "0x0146"
#define  set_CP_RSA_Y_46_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_46_reg)=data)
#define  get_CP_RSA_Y_46_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_46_reg))
#define  CP_RSA_Y_46_data_shift                                                  (0)
#define  CP_RSA_Y_46_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_46_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_46_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_47                                                             0x1806E1BC
#define  CP_RSA_Y_47_reg_addr                                                    "0xB806E1BC"
#define  CP_RSA_Y_47_reg                                                         0xB806E1BC
#define  CP_RSA_Y_47_inst_addr                                                   "0x0147"
#define  set_CP_RSA_Y_47_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_47_reg)=data)
#define  get_CP_RSA_Y_47_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_47_reg))
#define  CP_RSA_Y_47_data_shift                                                  (0)
#define  CP_RSA_Y_47_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_47_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_47_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_48                                                             0x1806E1C0
#define  CP_RSA_Y_48_reg_addr                                                    "0xB806E1C0"
#define  CP_RSA_Y_48_reg                                                         0xB806E1C0
#define  CP_RSA_Y_48_inst_addr                                                   "0x0148"
#define  set_CP_RSA_Y_48_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_48_reg)=data)
#define  get_CP_RSA_Y_48_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_48_reg))
#define  CP_RSA_Y_48_data_shift                                                  (0)
#define  CP_RSA_Y_48_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_48_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_48_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_49                                                             0x1806E1C4
#define  CP_RSA_Y_49_reg_addr                                                    "0xB806E1C4"
#define  CP_RSA_Y_49_reg                                                         0xB806E1C4
#define  CP_RSA_Y_49_inst_addr                                                   "0x0149"
#define  set_CP_RSA_Y_49_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_49_reg)=data)
#define  get_CP_RSA_Y_49_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_49_reg))
#define  CP_RSA_Y_49_data_shift                                                  (0)
#define  CP_RSA_Y_49_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_49_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_49_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_50                                                             0x1806E1C8
#define  CP_RSA_Y_50_reg_addr                                                    "0xB806E1C8"
#define  CP_RSA_Y_50_reg                                                         0xB806E1C8
#define  CP_RSA_Y_50_inst_addr                                                   "0x014A"
#define  set_CP_RSA_Y_50_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_50_reg)=data)
#define  get_CP_RSA_Y_50_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_50_reg))
#define  CP_RSA_Y_50_data_shift                                                  (0)
#define  CP_RSA_Y_50_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_50_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_50_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_51                                                             0x1806E1CC
#define  CP_RSA_Y_51_reg_addr                                                    "0xB806E1CC"
#define  CP_RSA_Y_51_reg                                                         0xB806E1CC
#define  CP_RSA_Y_51_inst_addr                                                   "0x014B"
#define  set_CP_RSA_Y_51_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_51_reg)=data)
#define  get_CP_RSA_Y_51_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_51_reg))
#define  CP_RSA_Y_51_data_shift                                                  (0)
#define  CP_RSA_Y_51_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_51_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_51_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_52                                                             0x1806E1D0
#define  CP_RSA_Y_52_reg_addr                                                    "0xB806E1D0"
#define  CP_RSA_Y_52_reg                                                         0xB806E1D0
#define  CP_RSA_Y_52_inst_addr                                                   "0x014C"
#define  set_CP_RSA_Y_52_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_52_reg)=data)
#define  get_CP_RSA_Y_52_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_52_reg))
#define  CP_RSA_Y_52_data_shift                                                  (0)
#define  CP_RSA_Y_52_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_52_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_52_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_53                                                             0x1806E1D4
#define  CP_RSA_Y_53_reg_addr                                                    "0xB806E1D4"
#define  CP_RSA_Y_53_reg                                                         0xB806E1D4
#define  CP_RSA_Y_53_inst_addr                                                   "0x014D"
#define  set_CP_RSA_Y_53_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_53_reg)=data)
#define  get_CP_RSA_Y_53_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_53_reg))
#define  CP_RSA_Y_53_data_shift                                                  (0)
#define  CP_RSA_Y_53_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_53_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_53_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_54                                                             0x1806E1D8
#define  CP_RSA_Y_54_reg_addr                                                    "0xB806E1D8"
#define  CP_RSA_Y_54_reg                                                         0xB806E1D8
#define  CP_RSA_Y_54_inst_addr                                                   "0x014E"
#define  set_CP_RSA_Y_54_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_54_reg)=data)
#define  get_CP_RSA_Y_54_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_54_reg))
#define  CP_RSA_Y_54_data_shift                                                  (0)
#define  CP_RSA_Y_54_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_54_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_54_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_55                                                             0x1806E1DC
#define  CP_RSA_Y_55_reg_addr                                                    "0xB806E1DC"
#define  CP_RSA_Y_55_reg                                                         0xB806E1DC
#define  CP_RSA_Y_55_inst_addr                                                   "0x014F"
#define  set_CP_RSA_Y_55_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_55_reg)=data)
#define  get_CP_RSA_Y_55_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_55_reg))
#define  CP_RSA_Y_55_data_shift                                                  (0)
#define  CP_RSA_Y_55_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_55_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_55_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_56                                                             0x1806E1E0
#define  CP_RSA_Y_56_reg_addr                                                    "0xB806E1E0"
#define  CP_RSA_Y_56_reg                                                         0xB806E1E0
#define  CP_RSA_Y_56_inst_addr                                                   "0x0150"
#define  set_CP_RSA_Y_56_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_56_reg)=data)
#define  get_CP_RSA_Y_56_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_56_reg))
#define  CP_RSA_Y_56_data_shift                                                  (0)
#define  CP_RSA_Y_56_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_56_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_56_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_57                                                             0x1806E1E4
#define  CP_RSA_Y_57_reg_addr                                                    "0xB806E1E4"
#define  CP_RSA_Y_57_reg                                                         0xB806E1E4
#define  CP_RSA_Y_57_inst_addr                                                   "0x0151"
#define  set_CP_RSA_Y_57_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_57_reg)=data)
#define  get_CP_RSA_Y_57_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_57_reg))
#define  CP_RSA_Y_57_data_shift                                                  (0)
#define  CP_RSA_Y_57_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_57_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_57_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_58                                                             0x1806E1E8
#define  CP_RSA_Y_58_reg_addr                                                    "0xB806E1E8"
#define  CP_RSA_Y_58_reg                                                         0xB806E1E8
#define  CP_RSA_Y_58_inst_addr                                                   "0x0152"
#define  set_CP_RSA_Y_58_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_58_reg)=data)
#define  get_CP_RSA_Y_58_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_58_reg))
#define  CP_RSA_Y_58_data_shift                                                  (0)
#define  CP_RSA_Y_58_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_58_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_58_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_59                                                             0x1806E1EC
#define  CP_RSA_Y_59_reg_addr                                                    "0xB806E1EC"
#define  CP_RSA_Y_59_reg                                                         0xB806E1EC
#define  CP_RSA_Y_59_inst_addr                                                   "0x0153"
#define  set_CP_RSA_Y_59_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_59_reg)=data)
#define  get_CP_RSA_Y_59_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_59_reg))
#define  CP_RSA_Y_59_data_shift                                                  (0)
#define  CP_RSA_Y_59_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_59_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_59_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_60                                                             0x1806E1F0
#define  CP_RSA_Y_60_reg_addr                                                    "0xB806E1F0"
#define  CP_RSA_Y_60_reg                                                         0xB806E1F0
#define  CP_RSA_Y_60_inst_addr                                                   "0x0154"
#define  set_CP_RSA_Y_60_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_60_reg)=data)
#define  get_CP_RSA_Y_60_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_60_reg))
#define  CP_RSA_Y_60_data_shift                                                  (0)
#define  CP_RSA_Y_60_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_60_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_60_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_61                                                             0x1806E1F4
#define  CP_RSA_Y_61_reg_addr                                                    "0xB806E1F4"
#define  CP_RSA_Y_61_reg                                                         0xB806E1F4
#define  CP_RSA_Y_61_inst_addr                                                   "0x0155"
#define  set_CP_RSA_Y_61_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_61_reg)=data)
#define  get_CP_RSA_Y_61_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_61_reg))
#define  CP_RSA_Y_61_data_shift                                                  (0)
#define  CP_RSA_Y_61_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_61_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_61_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_62                                                             0x1806E1F8
#define  CP_RSA_Y_62_reg_addr                                                    "0xB806E1F8"
#define  CP_RSA_Y_62_reg                                                         0xB806E1F8
#define  CP_RSA_Y_62_inst_addr                                                   "0x0156"
#define  set_CP_RSA_Y_62_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_62_reg)=data)
#define  get_CP_RSA_Y_62_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_62_reg))
#define  CP_RSA_Y_62_data_shift                                                  (0)
#define  CP_RSA_Y_62_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_62_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_62_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_Y_63                                                             0x1806E1FC
#define  CP_RSA_Y_63_reg_addr                                                    "0xB806E1FC"
#define  CP_RSA_Y_63_reg                                                         0xB806E1FC
#define  CP_RSA_Y_63_inst_addr                                                   "0x0157"
#define  set_CP_RSA_Y_63_reg(data)                                               (*((volatile unsigned int*)CP_RSA_Y_63_reg)=data)
#define  get_CP_RSA_Y_63_reg                                                     (*((volatile unsigned int*)CP_RSA_Y_63_reg))
#define  CP_RSA_Y_63_data_shift                                                  (0)
#define  CP_RSA_Y_63_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_Y_63_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_Y_63_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_0                                                              0x1806E200
#define  CP_RSA_M_0_reg_addr                                                     "0xB806E200"
#define  CP_RSA_M_0_reg                                                          0xB806E200
#define  CP_RSA_M_0_inst_addr                                                    "0x0158"
#define  set_CP_RSA_M_0_reg(data)                                                (*((volatile unsigned int*)CP_RSA_M_0_reg)=data)
#define  get_CP_RSA_M_0_reg                                                      (*((volatile unsigned int*)CP_RSA_M_0_reg))
#define  CP_RSA_M_0_data_shift                                                   (0)
#define  CP_RSA_M_0_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_M_0_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_M_0_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_M_1                                                              0x1806E204
#define  CP_RSA_M_1_reg_addr                                                     "0xB806E204"
#define  CP_RSA_M_1_reg                                                          0xB806E204
#define  CP_RSA_M_1_inst_addr                                                    "0x0159"
#define  set_CP_RSA_M_1_reg(data)                                                (*((volatile unsigned int*)CP_RSA_M_1_reg)=data)
#define  get_CP_RSA_M_1_reg                                                      (*((volatile unsigned int*)CP_RSA_M_1_reg))
#define  CP_RSA_M_1_data_shift                                                   (0)
#define  CP_RSA_M_1_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_M_1_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_M_1_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_M_2                                                              0x1806E208
#define  CP_RSA_M_2_reg_addr                                                     "0xB806E208"
#define  CP_RSA_M_2_reg                                                          0xB806E208
#define  CP_RSA_M_2_inst_addr                                                    "0x015A"
#define  set_CP_RSA_M_2_reg(data)                                                (*((volatile unsigned int*)CP_RSA_M_2_reg)=data)
#define  get_CP_RSA_M_2_reg                                                      (*((volatile unsigned int*)CP_RSA_M_2_reg))
#define  CP_RSA_M_2_data_shift                                                   (0)
#define  CP_RSA_M_2_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_M_2_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_M_2_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_M_3                                                              0x1806E20C
#define  CP_RSA_M_3_reg_addr                                                     "0xB806E20C"
#define  CP_RSA_M_3_reg                                                          0xB806E20C
#define  CP_RSA_M_3_inst_addr                                                    "0x015B"
#define  set_CP_RSA_M_3_reg(data)                                                (*((volatile unsigned int*)CP_RSA_M_3_reg)=data)
#define  get_CP_RSA_M_3_reg                                                      (*((volatile unsigned int*)CP_RSA_M_3_reg))
#define  CP_RSA_M_3_data_shift                                                   (0)
#define  CP_RSA_M_3_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_M_3_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_M_3_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_M_4                                                              0x1806E210
#define  CP_RSA_M_4_reg_addr                                                     "0xB806E210"
#define  CP_RSA_M_4_reg                                                          0xB806E210
#define  CP_RSA_M_4_inst_addr                                                    "0x015C"
#define  set_CP_RSA_M_4_reg(data)                                                (*((volatile unsigned int*)CP_RSA_M_4_reg)=data)
#define  get_CP_RSA_M_4_reg                                                      (*((volatile unsigned int*)CP_RSA_M_4_reg))
#define  CP_RSA_M_4_data_shift                                                   (0)
#define  CP_RSA_M_4_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_M_4_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_M_4_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_M_5                                                              0x1806E214
#define  CP_RSA_M_5_reg_addr                                                     "0xB806E214"
#define  CP_RSA_M_5_reg                                                          0xB806E214
#define  CP_RSA_M_5_inst_addr                                                    "0x015D"
#define  set_CP_RSA_M_5_reg(data)                                                (*((volatile unsigned int*)CP_RSA_M_5_reg)=data)
#define  get_CP_RSA_M_5_reg                                                      (*((volatile unsigned int*)CP_RSA_M_5_reg))
#define  CP_RSA_M_5_data_shift                                                   (0)
#define  CP_RSA_M_5_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_M_5_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_M_5_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_M_6                                                              0x1806E218
#define  CP_RSA_M_6_reg_addr                                                     "0xB806E218"
#define  CP_RSA_M_6_reg                                                          0xB806E218
#define  CP_RSA_M_6_inst_addr                                                    "0x015E"
#define  set_CP_RSA_M_6_reg(data)                                                (*((volatile unsigned int*)CP_RSA_M_6_reg)=data)
#define  get_CP_RSA_M_6_reg                                                      (*((volatile unsigned int*)CP_RSA_M_6_reg))
#define  CP_RSA_M_6_data_shift                                                   (0)
#define  CP_RSA_M_6_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_M_6_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_M_6_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_M_7                                                              0x1806E21C
#define  CP_RSA_M_7_reg_addr                                                     "0xB806E21C"
#define  CP_RSA_M_7_reg                                                          0xB806E21C
#define  CP_RSA_M_7_inst_addr                                                    "0x015F"
#define  set_CP_RSA_M_7_reg(data)                                                (*((volatile unsigned int*)CP_RSA_M_7_reg)=data)
#define  get_CP_RSA_M_7_reg                                                      (*((volatile unsigned int*)CP_RSA_M_7_reg))
#define  CP_RSA_M_7_data_shift                                                   (0)
#define  CP_RSA_M_7_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_M_7_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_M_7_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_M_8                                                              0x1806E220
#define  CP_RSA_M_8_reg_addr                                                     "0xB806E220"
#define  CP_RSA_M_8_reg                                                          0xB806E220
#define  CP_RSA_M_8_inst_addr                                                    "0x0160"
#define  set_CP_RSA_M_8_reg(data)                                                (*((volatile unsigned int*)CP_RSA_M_8_reg)=data)
#define  get_CP_RSA_M_8_reg                                                      (*((volatile unsigned int*)CP_RSA_M_8_reg))
#define  CP_RSA_M_8_data_shift                                                   (0)
#define  CP_RSA_M_8_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_M_8_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_M_8_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_M_9                                                              0x1806E224
#define  CP_RSA_M_9_reg_addr                                                     "0xB806E224"
#define  CP_RSA_M_9_reg                                                          0xB806E224
#define  CP_RSA_M_9_inst_addr                                                    "0x0161"
#define  set_CP_RSA_M_9_reg(data)                                                (*((volatile unsigned int*)CP_RSA_M_9_reg)=data)
#define  get_CP_RSA_M_9_reg                                                      (*((volatile unsigned int*)CP_RSA_M_9_reg))
#define  CP_RSA_M_9_data_shift                                                   (0)
#define  CP_RSA_M_9_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_M_9_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_M_9_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_M_10                                                             0x1806E228
#define  CP_RSA_M_10_reg_addr                                                    "0xB806E228"
#define  CP_RSA_M_10_reg                                                         0xB806E228
#define  CP_RSA_M_10_inst_addr                                                   "0x0162"
#define  set_CP_RSA_M_10_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_10_reg)=data)
#define  get_CP_RSA_M_10_reg                                                     (*((volatile unsigned int*)CP_RSA_M_10_reg))
#define  CP_RSA_M_10_data_shift                                                  (0)
#define  CP_RSA_M_10_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_10_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_10_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_11                                                             0x1806E22C
#define  CP_RSA_M_11_reg_addr                                                    "0xB806E22C"
#define  CP_RSA_M_11_reg                                                         0xB806E22C
#define  CP_RSA_M_11_inst_addr                                                   "0x0163"
#define  set_CP_RSA_M_11_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_11_reg)=data)
#define  get_CP_RSA_M_11_reg                                                     (*((volatile unsigned int*)CP_RSA_M_11_reg))
#define  CP_RSA_M_11_data_shift                                                  (0)
#define  CP_RSA_M_11_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_11_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_11_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_12                                                             0x1806E230
#define  CP_RSA_M_12_reg_addr                                                    "0xB806E230"
#define  CP_RSA_M_12_reg                                                         0xB806E230
#define  CP_RSA_M_12_inst_addr                                                   "0x0164"
#define  set_CP_RSA_M_12_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_12_reg)=data)
#define  get_CP_RSA_M_12_reg                                                     (*((volatile unsigned int*)CP_RSA_M_12_reg))
#define  CP_RSA_M_12_data_shift                                                  (0)
#define  CP_RSA_M_12_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_12_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_12_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_13                                                             0x1806E234
#define  CP_RSA_M_13_reg_addr                                                    "0xB806E234"
#define  CP_RSA_M_13_reg                                                         0xB806E234
#define  CP_RSA_M_13_inst_addr                                                   "0x0165"
#define  set_CP_RSA_M_13_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_13_reg)=data)
#define  get_CP_RSA_M_13_reg                                                     (*((volatile unsigned int*)CP_RSA_M_13_reg))
#define  CP_RSA_M_13_data_shift                                                  (0)
#define  CP_RSA_M_13_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_13_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_13_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_14                                                             0x1806E238
#define  CP_RSA_M_14_reg_addr                                                    "0xB806E238"
#define  CP_RSA_M_14_reg                                                         0xB806E238
#define  CP_RSA_M_14_inst_addr                                                   "0x0166"
#define  set_CP_RSA_M_14_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_14_reg)=data)
#define  get_CP_RSA_M_14_reg                                                     (*((volatile unsigned int*)CP_RSA_M_14_reg))
#define  CP_RSA_M_14_data_shift                                                  (0)
#define  CP_RSA_M_14_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_14_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_14_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_15                                                             0x1806E23C
#define  CP_RSA_M_15_reg_addr                                                    "0xB806E23C"
#define  CP_RSA_M_15_reg                                                         0xB806E23C
#define  CP_RSA_M_15_inst_addr                                                   "0x0167"
#define  set_CP_RSA_M_15_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_15_reg)=data)
#define  get_CP_RSA_M_15_reg                                                     (*((volatile unsigned int*)CP_RSA_M_15_reg))
#define  CP_RSA_M_15_data_shift                                                  (0)
#define  CP_RSA_M_15_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_15_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_15_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_16                                                             0x1806E240
#define  CP_RSA_M_16_reg_addr                                                    "0xB806E240"
#define  CP_RSA_M_16_reg                                                         0xB806E240
#define  CP_RSA_M_16_inst_addr                                                   "0x0168"
#define  set_CP_RSA_M_16_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_16_reg)=data)
#define  get_CP_RSA_M_16_reg                                                     (*((volatile unsigned int*)CP_RSA_M_16_reg))
#define  CP_RSA_M_16_data_shift                                                  (0)
#define  CP_RSA_M_16_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_16_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_16_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_17                                                             0x1806E244
#define  CP_RSA_M_17_reg_addr                                                    "0xB806E244"
#define  CP_RSA_M_17_reg                                                         0xB806E244
#define  CP_RSA_M_17_inst_addr                                                   "0x0169"
#define  set_CP_RSA_M_17_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_17_reg)=data)
#define  get_CP_RSA_M_17_reg                                                     (*((volatile unsigned int*)CP_RSA_M_17_reg))
#define  CP_RSA_M_17_data_shift                                                  (0)
#define  CP_RSA_M_17_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_17_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_17_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_18                                                             0x1806E248
#define  CP_RSA_M_18_reg_addr                                                    "0xB806E248"
#define  CP_RSA_M_18_reg                                                         0xB806E248
#define  CP_RSA_M_18_inst_addr                                                   "0x016A"
#define  set_CP_RSA_M_18_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_18_reg)=data)
#define  get_CP_RSA_M_18_reg                                                     (*((volatile unsigned int*)CP_RSA_M_18_reg))
#define  CP_RSA_M_18_data_shift                                                  (0)
#define  CP_RSA_M_18_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_18_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_18_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_19                                                             0x1806E24C
#define  CP_RSA_M_19_reg_addr                                                    "0xB806E24C"
#define  CP_RSA_M_19_reg                                                         0xB806E24C
#define  CP_RSA_M_19_inst_addr                                                   "0x016B"
#define  set_CP_RSA_M_19_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_19_reg)=data)
#define  get_CP_RSA_M_19_reg                                                     (*((volatile unsigned int*)CP_RSA_M_19_reg))
#define  CP_RSA_M_19_data_shift                                                  (0)
#define  CP_RSA_M_19_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_19_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_19_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_20                                                             0x1806E250
#define  CP_RSA_M_20_reg_addr                                                    "0xB806E250"
#define  CP_RSA_M_20_reg                                                         0xB806E250
#define  CP_RSA_M_20_inst_addr                                                   "0x016C"
#define  set_CP_RSA_M_20_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_20_reg)=data)
#define  get_CP_RSA_M_20_reg                                                     (*((volatile unsigned int*)CP_RSA_M_20_reg))
#define  CP_RSA_M_20_data_shift                                                  (0)
#define  CP_RSA_M_20_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_20_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_20_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_21                                                             0x1806E254
#define  CP_RSA_M_21_reg_addr                                                    "0xB806E254"
#define  CP_RSA_M_21_reg                                                         0xB806E254
#define  CP_RSA_M_21_inst_addr                                                   "0x016D"
#define  set_CP_RSA_M_21_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_21_reg)=data)
#define  get_CP_RSA_M_21_reg                                                     (*((volatile unsigned int*)CP_RSA_M_21_reg))
#define  CP_RSA_M_21_data_shift                                                  (0)
#define  CP_RSA_M_21_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_21_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_21_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_22                                                             0x1806E258
#define  CP_RSA_M_22_reg_addr                                                    "0xB806E258"
#define  CP_RSA_M_22_reg                                                         0xB806E258
#define  CP_RSA_M_22_inst_addr                                                   "0x016E"
#define  set_CP_RSA_M_22_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_22_reg)=data)
#define  get_CP_RSA_M_22_reg                                                     (*((volatile unsigned int*)CP_RSA_M_22_reg))
#define  CP_RSA_M_22_data_shift                                                  (0)
#define  CP_RSA_M_22_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_22_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_22_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_23                                                             0x1806E25C
#define  CP_RSA_M_23_reg_addr                                                    "0xB806E25C"
#define  CP_RSA_M_23_reg                                                         0xB806E25C
#define  CP_RSA_M_23_inst_addr                                                   "0x016F"
#define  set_CP_RSA_M_23_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_23_reg)=data)
#define  get_CP_RSA_M_23_reg                                                     (*((volatile unsigned int*)CP_RSA_M_23_reg))
#define  CP_RSA_M_23_data_shift                                                  (0)
#define  CP_RSA_M_23_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_23_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_23_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_24                                                             0x1806E260
#define  CP_RSA_M_24_reg_addr                                                    "0xB806E260"
#define  CP_RSA_M_24_reg                                                         0xB806E260
#define  CP_RSA_M_24_inst_addr                                                   "0x0170"
#define  set_CP_RSA_M_24_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_24_reg)=data)
#define  get_CP_RSA_M_24_reg                                                     (*((volatile unsigned int*)CP_RSA_M_24_reg))
#define  CP_RSA_M_24_data_shift                                                  (0)
#define  CP_RSA_M_24_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_24_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_24_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_25                                                             0x1806E264
#define  CP_RSA_M_25_reg_addr                                                    "0xB806E264"
#define  CP_RSA_M_25_reg                                                         0xB806E264
#define  CP_RSA_M_25_inst_addr                                                   "0x0171"
#define  set_CP_RSA_M_25_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_25_reg)=data)
#define  get_CP_RSA_M_25_reg                                                     (*((volatile unsigned int*)CP_RSA_M_25_reg))
#define  CP_RSA_M_25_data_shift                                                  (0)
#define  CP_RSA_M_25_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_25_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_25_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_26                                                             0x1806E268
#define  CP_RSA_M_26_reg_addr                                                    "0xB806E268"
#define  CP_RSA_M_26_reg                                                         0xB806E268
#define  CP_RSA_M_26_inst_addr                                                   "0x0172"
#define  set_CP_RSA_M_26_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_26_reg)=data)
#define  get_CP_RSA_M_26_reg                                                     (*((volatile unsigned int*)CP_RSA_M_26_reg))
#define  CP_RSA_M_26_data_shift                                                  (0)
#define  CP_RSA_M_26_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_26_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_26_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_27                                                             0x1806E26C
#define  CP_RSA_M_27_reg_addr                                                    "0xB806E26C"
#define  CP_RSA_M_27_reg                                                         0xB806E26C
#define  CP_RSA_M_27_inst_addr                                                   "0x0173"
#define  set_CP_RSA_M_27_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_27_reg)=data)
#define  get_CP_RSA_M_27_reg                                                     (*((volatile unsigned int*)CP_RSA_M_27_reg))
#define  CP_RSA_M_27_data_shift                                                  (0)
#define  CP_RSA_M_27_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_27_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_27_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_28                                                             0x1806E270
#define  CP_RSA_M_28_reg_addr                                                    "0xB806E270"
#define  CP_RSA_M_28_reg                                                         0xB806E270
#define  CP_RSA_M_28_inst_addr                                                   "0x0174"
#define  set_CP_RSA_M_28_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_28_reg)=data)
#define  get_CP_RSA_M_28_reg                                                     (*((volatile unsigned int*)CP_RSA_M_28_reg))
#define  CP_RSA_M_28_data_shift                                                  (0)
#define  CP_RSA_M_28_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_28_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_28_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_29                                                             0x1806E274
#define  CP_RSA_M_29_reg_addr                                                    "0xB806E274"
#define  CP_RSA_M_29_reg                                                         0xB806E274
#define  CP_RSA_M_29_inst_addr                                                   "0x0175"
#define  set_CP_RSA_M_29_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_29_reg)=data)
#define  get_CP_RSA_M_29_reg                                                     (*((volatile unsigned int*)CP_RSA_M_29_reg))
#define  CP_RSA_M_29_data_shift                                                  (0)
#define  CP_RSA_M_29_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_29_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_29_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_30                                                             0x1806E278
#define  CP_RSA_M_30_reg_addr                                                    "0xB806E278"
#define  CP_RSA_M_30_reg                                                         0xB806E278
#define  CP_RSA_M_30_inst_addr                                                   "0x0176"
#define  set_CP_RSA_M_30_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_30_reg)=data)
#define  get_CP_RSA_M_30_reg                                                     (*((volatile unsigned int*)CP_RSA_M_30_reg))
#define  CP_RSA_M_30_data_shift                                                  (0)
#define  CP_RSA_M_30_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_30_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_30_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_31                                                             0x1806E27C
#define  CP_RSA_M_31_reg_addr                                                    "0xB806E27C"
#define  CP_RSA_M_31_reg                                                         0xB806E27C
#define  CP_RSA_M_31_inst_addr                                                   "0x0177"
#define  set_CP_RSA_M_31_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_31_reg)=data)
#define  get_CP_RSA_M_31_reg                                                     (*((volatile unsigned int*)CP_RSA_M_31_reg))
#define  CP_RSA_M_31_data_shift                                                  (0)
#define  CP_RSA_M_31_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_31_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_31_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_32                                                             0x1806E280
#define  CP_RSA_M_32_reg_addr                                                    "0xB806E280"
#define  CP_RSA_M_32_reg                                                         0xB806E280
#define  CP_RSA_M_32_inst_addr                                                   "0x0178"
#define  set_CP_RSA_M_32_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_32_reg)=data)
#define  get_CP_RSA_M_32_reg                                                     (*((volatile unsigned int*)CP_RSA_M_32_reg))
#define  CP_RSA_M_32_data_shift                                                  (0)
#define  CP_RSA_M_32_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_32_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_32_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_33                                                             0x1806E284
#define  CP_RSA_M_33_reg_addr                                                    "0xB806E284"
#define  CP_RSA_M_33_reg                                                         0xB806E284
#define  CP_RSA_M_33_inst_addr                                                   "0x0179"
#define  set_CP_RSA_M_33_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_33_reg)=data)
#define  get_CP_RSA_M_33_reg                                                     (*((volatile unsigned int*)CP_RSA_M_33_reg))
#define  CP_RSA_M_33_data_shift                                                  (0)
#define  CP_RSA_M_33_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_33_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_33_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_34                                                             0x1806E288
#define  CP_RSA_M_34_reg_addr                                                    "0xB806E288"
#define  CP_RSA_M_34_reg                                                         0xB806E288
#define  CP_RSA_M_34_inst_addr                                                   "0x017A"
#define  set_CP_RSA_M_34_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_34_reg)=data)
#define  get_CP_RSA_M_34_reg                                                     (*((volatile unsigned int*)CP_RSA_M_34_reg))
#define  CP_RSA_M_34_data_shift                                                  (0)
#define  CP_RSA_M_34_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_34_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_34_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_35                                                             0x1806E28C
#define  CP_RSA_M_35_reg_addr                                                    "0xB806E28C"
#define  CP_RSA_M_35_reg                                                         0xB806E28C
#define  CP_RSA_M_35_inst_addr                                                   "0x017B"
#define  set_CP_RSA_M_35_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_35_reg)=data)
#define  get_CP_RSA_M_35_reg                                                     (*((volatile unsigned int*)CP_RSA_M_35_reg))
#define  CP_RSA_M_35_data_shift                                                  (0)
#define  CP_RSA_M_35_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_35_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_35_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_36                                                             0x1806E290
#define  CP_RSA_M_36_reg_addr                                                    "0xB806E290"
#define  CP_RSA_M_36_reg                                                         0xB806E290
#define  CP_RSA_M_36_inst_addr                                                   "0x017C"
#define  set_CP_RSA_M_36_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_36_reg)=data)
#define  get_CP_RSA_M_36_reg                                                     (*((volatile unsigned int*)CP_RSA_M_36_reg))
#define  CP_RSA_M_36_data_shift                                                  (0)
#define  CP_RSA_M_36_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_36_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_36_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_37                                                             0x1806E294
#define  CP_RSA_M_37_reg_addr                                                    "0xB806E294"
#define  CP_RSA_M_37_reg                                                         0xB806E294
#define  CP_RSA_M_37_inst_addr                                                   "0x017D"
#define  set_CP_RSA_M_37_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_37_reg)=data)
#define  get_CP_RSA_M_37_reg                                                     (*((volatile unsigned int*)CP_RSA_M_37_reg))
#define  CP_RSA_M_37_data_shift                                                  (0)
#define  CP_RSA_M_37_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_37_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_37_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_38                                                             0x1806E298
#define  CP_RSA_M_38_reg_addr                                                    "0xB806E298"
#define  CP_RSA_M_38_reg                                                         0xB806E298
#define  CP_RSA_M_38_inst_addr                                                   "0x017E"
#define  set_CP_RSA_M_38_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_38_reg)=data)
#define  get_CP_RSA_M_38_reg                                                     (*((volatile unsigned int*)CP_RSA_M_38_reg))
#define  CP_RSA_M_38_data_shift                                                  (0)
#define  CP_RSA_M_38_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_38_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_38_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_39                                                             0x1806E29C
#define  CP_RSA_M_39_reg_addr                                                    "0xB806E29C"
#define  CP_RSA_M_39_reg                                                         0xB806E29C
#define  CP_RSA_M_39_inst_addr                                                   "0x017F"
#define  set_CP_RSA_M_39_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_39_reg)=data)
#define  get_CP_RSA_M_39_reg                                                     (*((volatile unsigned int*)CP_RSA_M_39_reg))
#define  CP_RSA_M_39_data_shift                                                  (0)
#define  CP_RSA_M_39_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_39_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_39_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_40                                                             0x1806E2A0
#define  CP_RSA_M_40_reg_addr                                                    "0xB806E2A0"
#define  CP_RSA_M_40_reg                                                         0xB806E2A0
#define  CP_RSA_M_40_inst_addr                                                   "0x0180"
#define  set_CP_RSA_M_40_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_40_reg)=data)
#define  get_CP_RSA_M_40_reg                                                     (*((volatile unsigned int*)CP_RSA_M_40_reg))
#define  CP_RSA_M_40_data_shift                                                  (0)
#define  CP_RSA_M_40_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_40_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_40_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_41                                                             0x1806E2A4
#define  CP_RSA_M_41_reg_addr                                                    "0xB806E2A4"
#define  CP_RSA_M_41_reg                                                         0xB806E2A4
#define  CP_RSA_M_41_inst_addr                                                   "0x0181"
#define  set_CP_RSA_M_41_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_41_reg)=data)
#define  get_CP_RSA_M_41_reg                                                     (*((volatile unsigned int*)CP_RSA_M_41_reg))
#define  CP_RSA_M_41_data_shift                                                  (0)
#define  CP_RSA_M_41_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_41_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_41_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_42                                                             0x1806E2A8
#define  CP_RSA_M_42_reg_addr                                                    "0xB806E2A8"
#define  CP_RSA_M_42_reg                                                         0xB806E2A8
#define  CP_RSA_M_42_inst_addr                                                   "0x0182"
#define  set_CP_RSA_M_42_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_42_reg)=data)
#define  get_CP_RSA_M_42_reg                                                     (*((volatile unsigned int*)CP_RSA_M_42_reg))
#define  CP_RSA_M_42_data_shift                                                  (0)
#define  CP_RSA_M_42_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_42_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_42_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_43                                                             0x1806E2AC
#define  CP_RSA_M_43_reg_addr                                                    "0xB806E2AC"
#define  CP_RSA_M_43_reg                                                         0xB806E2AC
#define  CP_RSA_M_43_inst_addr                                                   "0x0183"
#define  set_CP_RSA_M_43_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_43_reg)=data)
#define  get_CP_RSA_M_43_reg                                                     (*((volatile unsigned int*)CP_RSA_M_43_reg))
#define  CP_RSA_M_43_data_shift                                                  (0)
#define  CP_RSA_M_43_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_43_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_43_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_44                                                             0x1806E2B0
#define  CP_RSA_M_44_reg_addr                                                    "0xB806E2B0"
#define  CP_RSA_M_44_reg                                                         0xB806E2B0
#define  CP_RSA_M_44_inst_addr                                                   "0x0184"
#define  set_CP_RSA_M_44_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_44_reg)=data)
#define  get_CP_RSA_M_44_reg                                                     (*((volatile unsigned int*)CP_RSA_M_44_reg))
#define  CP_RSA_M_44_data_shift                                                  (0)
#define  CP_RSA_M_44_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_44_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_44_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_45                                                             0x1806E2B4
#define  CP_RSA_M_45_reg_addr                                                    "0xB806E2B4"
#define  CP_RSA_M_45_reg                                                         0xB806E2B4
#define  CP_RSA_M_45_inst_addr                                                   "0x0185"
#define  set_CP_RSA_M_45_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_45_reg)=data)
#define  get_CP_RSA_M_45_reg                                                     (*((volatile unsigned int*)CP_RSA_M_45_reg))
#define  CP_RSA_M_45_data_shift                                                  (0)
#define  CP_RSA_M_45_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_45_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_45_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_46                                                             0x1806E2B8
#define  CP_RSA_M_46_reg_addr                                                    "0xB806E2B8"
#define  CP_RSA_M_46_reg                                                         0xB806E2B8
#define  CP_RSA_M_46_inst_addr                                                   "0x0186"
#define  set_CP_RSA_M_46_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_46_reg)=data)
#define  get_CP_RSA_M_46_reg                                                     (*((volatile unsigned int*)CP_RSA_M_46_reg))
#define  CP_RSA_M_46_data_shift                                                  (0)
#define  CP_RSA_M_46_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_46_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_46_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_47                                                             0x1806E2BC
#define  CP_RSA_M_47_reg_addr                                                    "0xB806E2BC"
#define  CP_RSA_M_47_reg                                                         0xB806E2BC
#define  CP_RSA_M_47_inst_addr                                                   "0x0187"
#define  set_CP_RSA_M_47_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_47_reg)=data)
#define  get_CP_RSA_M_47_reg                                                     (*((volatile unsigned int*)CP_RSA_M_47_reg))
#define  CP_RSA_M_47_data_shift                                                  (0)
#define  CP_RSA_M_47_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_47_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_47_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_48                                                             0x1806E2C0
#define  CP_RSA_M_48_reg_addr                                                    "0xB806E2C0"
#define  CP_RSA_M_48_reg                                                         0xB806E2C0
#define  CP_RSA_M_48_inst_addr                                                   "0x0188"
#define  set_CP_RSA_M_48_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_48_reg)=data)
#define  get_CP_RSA_M_48_reg                                                     (*((volatile unsigned int*)CP_RSA_M_48_reg))
#define  CP_RSA_M_48_data_shift                                                  (0)
#define  CP_RSA_M_48_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_48_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_48_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_49                                                             0x1806E2C4
#define  CP_RSA_M_49_reg_addr                                                    "0xB806E2C4"
#define  CP_RSA_M_49_reg                                                         0xB806E2C4
#define  CP_RSA_M_49_inst_addr                                                   "0x0189"
#define  set_CP_RSA_M_49_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_49_reg)=data)
#define  get_CP_RSA_M_49_reg                                                     (*((volatile unsigned int*)CP_RSA_M_49_reg))
#define  CP_RSA_M_49_data_shift                                                  (0)
#define  CP_RSA_M_49_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_49_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_49_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_50                                                             0x1806E2C8
#define  CP_RSA_M_50_reg_addr                                                    "0xB806E2C8"
#define  CP_RSA_M_50_reg                                                         0xB806E2C8
#define  CP_RSA_M_50_inst_addr                                                   "0x018A"
#define  set_CP_RSA_M_50_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_50_reg)=data)
#define  get_CP_RSA_M_50_reg                                                     (*((volatile unsigned int*)CP_RSA_M_50_reg))
#define  CP_RSA_M_50_data_shift                                                  (0)
#define  CP_RSA_M_50_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_50_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_50_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_51                                                             0x1806E2CC
#define  CP_RSA_M_51_reg_addr                                                    "0xB806E2CC"
#define  CP_RSA_M_51_reg                                                         0xB806E2CC
#define  CP_RSA_M_51_inst_addr                                                   "0x018B"
#define  set_CP_RSA_M_51_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_51_reg)=data)
#define  get_CP_RSA_M_51_reg                                                     (*((volatile unsigned int*)CP_RSA_M_51_reg))
#define  CP_RSA_M_51_data_shift                                                  (0)
#define  CP_RSA_M_51_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_51_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_51_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_52                                                             0x1806E2D0
#define  CP_RSA_M_52_reg_addr                                                    "0xB806E2D0"
#define  CP_RSA_M_52_reg                                                         0xB806E2D0
#define  CP_RSA_M_52_inst_addr                                                   "0x018C"
#define  set_CP_RSA_M_52_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_52_reg)=data)
#define  get_CP_RSA_M_52_reg                                                     (*((volatile unsigned int*)CP_RSA_M_52_reg))
#define  CP_RSA_M_52_data_shift                                                  (0)
#define  CP_RSA_M_52_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_52_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_52_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_53                                                             0x1806E2D4
#define  CP_RSA_M_53_reg_addr                                                    "0xB806E2D4"
#define  CP_RSA_M_53_reg                                                         0xB806E2D4
#define  CP_RSA_M_53_inst_addr                                                   "0x018D"
#define  set_CP_RSA_M_53_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_53_reg)=data)
#define  get_CP_RSA_M_53_reg                                                     (*((volatile unsigned int*)CP_RSA_M_53_reg))
#define  CP_RSA_M_53_data_shift                                                  (0)
#define  CP_RSA_M_53_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_53_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_53_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_54                                                             0x1806E2D8
#define  CP_RSA_M_54_reg_addr                                                    "0xB806E2D8"
#define  CP_RSA_M_54_reg                                                         0xB806E2D8
#define  CP_RSA_M_54_inst_addr                                                   "0x018E"
#define  set_CP_RSA_M_54_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_54_reg)=data)
#define  get_CP_RSA_M_54_reg                                                     (*((volatile unsigned int*)CP_RSA_M_54_reg))
#define  CP_RSA_M_54_data_shift                                                  (0)
#define  CP_RSA_M_54_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_54_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_54_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_55                                                             0x1806E2DC
#define  CP_RSA_M_55_reg_addr                                                    "0xB806E2DC"
#define  CP_RSA_M_55_reg                                                         0xB806E2DC
#define  CP_RSA_M_55_inst_addr                                                   "0x018F"
#define  set_CP_RSA_M_55_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_55_reg)=data)
#define  get_CP_RSA_M_55_reg                                                     (*((volatile unsigned int*)CP_RSA_M_55_reg))
#define  CP_RSA_M_55_data_shift                                                  (0)
#define  CP_RSA_M_55_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_55_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_55_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_56                                                             0x1806E2E0
#define  CP_RSA_M_56_reg_addr                                                    "0xB806E2E0"
#define  CP_RSA_M_56_reg                                                         0xB806E2E0
#define  CP_RSA_M_56_inst_addr                                                   "0x0190"
#define  set_CP_RSA_M_56_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_56_reg)=data)
#define  get_CP_RSA_M_56_reg                                                     (*((volatile unsigned int*)CP_RSA_M_56_reg))
#define  CP_RSA_M_56_data_shift                                                  (0)
#define  CP_RSA_M_56_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_56_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_56_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_57                                                             0x1806E2E4
#define  CP_RSA_M_57_reg_addr                                                    "0xB806E2E4"
#define  CP_RSA_M_57_reg                                                         0xB806E2E4
#define  CP_RSA_M_57_inst_addr                                                   "0x0191"
#define  set_CP_RSA_M_57_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_57_reg)=data)
#define  get_CP_RSA_M_57_reg                                                     (*((volatile unsigned int*)CP_RSA_M_57_reg))
#define  CP_RSA_M_57_data_shift                                                  (0)
#define  CP_RSA_M_57_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_57_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_57_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_58                                                             0x1806E2E8
#define  CP_RSA_M_58_reg_addr                                                    "0xB806E2E8"
#define  CP_RSA_M_58_reg                                                         0xB806E2E8
#define  CP_RSA_M_58_inst_addr                                                   "0x0192"
#define  set_CP_RSA_M_58_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_58_reg)=data)
#define  get_CP_RSA_M_58_reg                                                     (*((volatile unsigned int*)CP_RSA_M_58_reg))
#define  CP_RSA_M_58_data_shift                                                  (0)
#define  CP_RSA_M_58_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_58_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_58_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_59                                                             0x1806E2EC
#define  CP_RSA_M_59_reg_addr                                                    "0xB806E2EC"
#define  CP_RSA_M_59_reg                                                         0xB806E2EC
#define  CP_RSA_M_59_inst_addr                                                   "0x0193"
#define  set_CP_RSA_M_59_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_59_reg)=data)
#define  get_CP_RSA_M_59_reg                                                     (*((volatile unsigned int*)CP_RSA_M_59_reg))
#define  CP_RSA_M_59_data_shift                                                  (0)
#define  CP_RSA_M_59_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_59_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_59_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_60                                                             0x1806E2F0
#define  CP_RSA_M_60_reg_addr                                                    "0xB806E2F0"
#define  CP_RSA_M_60_reg                                                         0xB806E2F0
#define  CP_RSA_M_60_inst_addr                                                   "0x0194"
#define  set_CP_RSA_M_60_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_60_reg)=data)
#define  get_CP_RSA_M_60_reg                                                     (*((volatile unsigned int*)CP_RSA_M_60_reg))
#define  CP_RSA_M_60_data_shift                                                  (0)
#define  CP_RSA_M_60_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_60_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_60_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_61                                                             0x1806E2F4
#define  CP_RSA_M_61_reg_addr                                                    "0xB806E2F4"
#define  CP_RSA_M_61_reg                                                         0xB806E2F4
#define  CP_RSA_M_61_inst_addr                                                   "0x0195"
#define  set_CP_RSA_M_61_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_61_reg)=data)
#define  get_CP_RSA_M_61_reg                                                     (*((volatile unsigned int*)CP_RSA_M_61_reg))
#define  CP_RSA_M_61_data_shift                                                  (0)
#define  CP_RSA_M_61_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_61_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_61_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_62                                                             0x1806E2F8
#define  CP_RSA_M_62_reg_addr                                                    "0xB806E2F8"
#define  CP_RSA_M_62_reg                                                         0xB806E2F8
#define  CP_RSA_M_62_inst_addr                                                   "0x0196"
#define  set_CP_RSA_M_62_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_62_reg)=data)
#define  get_CP_RSA_M_62_reg                                                     (*((volatile unsigned int*)CP_RSA_M_62_reg))
#define  CP_RSA_M_62_data_shift                                                  (0)
#define  CP_RSA_M_62_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_62_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_62_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_M_63                                                             0x1806E2FC
#define  CP_RSA_M_63_reg_addr                                                    "0xB806E2FC"
#define  CP_RSA_M_63_reg                                                         0xB806E2FC
#define  CP_RSA_M_63_inst_addr                                                   "0x0197"
#define  set_CP_RSA_M_63_reg(data)                                               (*((volatile unsigned int*)CP_RSA_M_63_reg)=data)
#define  get_CP_RSA_M_63_reg                                                     (*((volatile unsigned int*)CP_RSA_M_63_reg))
#define  CP_RSA_M_63_data_shift                                                  (0)
#define  CP_RSA_M_63_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_M_63_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_M_63_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_0                                                              0x1806E300
#define  CP_RSA_A_0_reg_addr                                                     "0xB806E300"
#define  CP_RSA_A_0_reg                                                          0xB806E300
#define  CP_RSA_A_0_inst_addr                                                    "0x0198"
#define  set_CP_RSA_A_0_reg(data)                                                (*((volatile unsigned int*)CP_RSA_A_0_reg)=data)
#define  get_CP_RSA_A_0_reg                                                      (*((volatile unsigned int*)CP_RSA_A_0_reg))
#define  CP_RSA_A_0_data_shift                                                   (0)
#define  CP_RSA_A_0_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_A_0_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_A_0_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_A_1                                                              0x1806E304
#define  CP_RSA_A_1_reg_addr                                                     "0xB806E304"
#define  CP_RSA_A_1_reg                                                          0xB806E304
#define  CP_RSA_A_1_inst_addr                                                    "0x0199"
#define  set_CP_RSA_A_1_reg(data)                                                (*((volatile unsigned int*)CP_RSA_A_1_reg)=data)
#define  get_CP_RSA_A_1_reg                                                      (*((volatile unsigned int*)CP_RSA_A_1_reg))
#define  CP_RSA_A_1_data_shift                                                   (0)
#define  CP_RSA_A_1_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_A_1_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_A_1_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_A_2                                                              0x1806E308
#define  CP_RSA_A_2_reg_addr                                                     "0xB806E308"
#define  CP_RSA_A_2_reg                                                          0xB806E308
#define  CP_RSA_A_2_inst_addr                                                    "0x019A"
#define  set_CP_RSA_A_2_reg(data)                                                (*((volatile unsigned int*)CP_RSA_A_2_reg)=data)
#define  get_CP_RSA_A_2_reg                                                      (*((volatile unsigned int*)CP_RSA_A_2_reg))
#define  CP_RSA_A_2_data_shift                                                   (0)
#define  CP_RSA_A_2_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_A_2_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_A_2_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_A_3                                                              0x1806E30C
#define  CP_RSA_A_3_reg_addr                                                     "0xB806E30C"
#define  CP_RSA_A_3_reg                                                          0xB806E30C
#define  CP_RSA_A_3_inst_addr                                                    "0x019B"
#define  set_CP_RSA_A_3_reg(data)                                                (*((volatile unsigned int*)CP_RSA_A_3_reg)=data)
#define  get_CP_RSA_A_3_reg                                                      (*((volatile unsigned int*)CP_RSA_A_3_reg))
#define  CP_RSA_A_3_data_shift                                                   (0)
#define  CP_RSA_A_3_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_A_3_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_A_3_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_A_4                                                              0x1806E310
#define  CP_RSA_A_4_reg_addr                                                     "0xB806E310"
#define  CP_RSA_A_4_reg                                                          0xB806E310
#define  CP_RSA_A_4_inst_addr                                                    "0x019C"
#define  set_CP_RSA_A_4_reg(data)                                                (*((volatile unsigned int*)CP_RSA_A_4_reg)=data)
#define  get_CP_RSA_A_4_reg                                                      (*((volatile unsigned int*)CP_RSA_A_4_reg))
#define  CP_RSA_A_4_data_shift                                                   (0)
#define  CP_RSA_A_4_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_A_4_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_A_4_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_A_5                                                              0x1806E314
#define  CP_RSA_A_5_reg_addr                                                     "0xB806E314"
#define  CP_RSA_A_5_reg                                                          0xB806E314
#define  CP_RSA_A_5_inst_addr                                                    "0x019D"
#define  set_CP_RSA_A_5_reg(data)                                                (*((volatile unsigned int*)CP_RSA_A_5_reg)=data)
#define  get_CP_RSA_A_5_reg                                                      (*((volatile unsigned int*)CP_RSA_A_5_reg))
#define  CP_RSA_A_5_data_shift                                                   (0)
#define  CP_RSA_A_5_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_A_5_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_A_5_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_A_6                                                              0x1806E318
#define  CP_RSA_A_6_reg_addr                                                     "0xB806E318"
#define  CP_RSA_A_6_reg                                                          0xB806E318
#define  CP_RSA_A_6_inst_addr                                                    "0x019E"
#define  set_CP_RSA_A_6_reg(data)                                                (*((volatile unsigned int*)CP_RSA_A_6_reg)=data)
#define  get_CP_RSA_A_6_reg                                                      (*((volatile unsigned int*)CP_RSA_A_6_reg))
#define  CP_RSA_A_6_data_shift                                                   (0)
#define  CP_RSA_A_6_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_A_6_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_A_6_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_A_7                                                              0x1806E31C
#define  CP_RSA_A_7_reg_addr                                                     "0xB806E31C"
#define  CP_RSA_A_7_reg                                                          0xB806E31C
#define  CP_RSA_A_7_inst_addr                                                    "0x019F"
#define  set_CP_RSA_A_7_reg(data)                                                (*((volatile unsigned int*)CP_RSA_A_7_reg)=data)
#define  get_CP_RSA_A_7_reg                                                      (*((volatile unsigned int*)CP_RSA_A_7_reg))
#define  CP_RSA_A_7_data_shift                                                   (0)
#define  CP_RSA_A_7_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_A_7_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_A_7_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_A_8                                                              0x1806E320
#define  CP_RSA_A_8_reg_addr                                                     "0xB806E320"
#define  CP_RSA_A_8_reg                                                          0xB806E320
#define  CP_RSA_A_8_inst_addr                                                    "0x01A0"
#define  set_CP_RSA_A_8_reg(data)                                                (*((volatile unsigned int*)CP_RSA_A_8_reg)=data)
#define  get_CP_RSA_A_8_reg                                                      (*((volatile unsigned int*)CP_RSA_A_8_reg))
#define  CP_RSA_A_8_data_shift                                                   (0)
#define  CP_RSA_A_8_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_A_8_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_A_8_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_A_9                                                              0x1806E324
#define  CP_RSA_A_9_reg_addr                                                     "0xB806E324"
#define  CP_RSA_A_9_reg                                                          0xB806E324
#define  CP_RSA_A_9_inst_addr                                                    "0x01A1"
#define  set_CP_RSA_A_9_reg(data)                                                (*((volatile unsigned int*)CP_RSA_A_9_reg)=data)
#define  get_CP_RSA_A_9_reg                                                      (*((volatile unsigned int*)CP_RSA_A_9_reg))
#define  CP_RSA_A_9_data_shift                                                   (0)
#define  CP_RSA_A_9_data_mask                                                    (0xFFFFFFFF)
#define  CP_RSA_A_9_data(data)                                                   (0xFFFFFFFF&(data))
#define  CP_RSA_A_9_get_data(data)                                               (0xFFFFFFFF&(data))

#define  CP_RSA_A_10                                                             0x1806E328
#define  CP_RSA_A_10_reg_addr                                                    "0xB806E328"
#define  CP_RSA_A_10_reg                                                         0xB806E328
#define  CP_RSA_A_10_inst_addr                                                   "0x01A2"
#define  set_CP_RSA_A_10_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_10_reg)=data)
#define  get_CP_RSA_A_10_reg                                                     (*((volatile unsigned int*)CP_RSA_A_10_reg))
#define  CP_RSA_A_10_data_shift                                                  (0)
#define  CP_RSA_A_10_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_10_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_10_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_11                                                             0x1806E32C
#define  CP_RSA_A_11_reg_addr                                                    "0xB806E32C"
#define  CP_RSA_A_11_reg                                                         0xB806E32C
#define  CP_RSA_A_11_inst_addr                                                   "0x01A3"
#define  set_CP_RSA_A_11_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_11_reg)=data)
#define  get_CP_RSA_A_11_reg                                                     (*((volatile unsigned int*)CP_RSA_A_11_reg))
#define  CP_RSA_A_11_data_shift                                                  (0)
#define  CP_RSA_A_11_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_11_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_11_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_12                                                             0x1806E330
#define  CP_RSA_A_12_reg_addr                                                    "0xB806E330"
#define  CP_RSA_A_12_reg                                                         0xB806E330
#define  CP_RSA_A_12_inst_addr                                                   "0x01A4"
#define  set_CP_RSA_A_12_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_12_reg)=data)
#define  get_CP_RSA_A_12_reg                                                     (*((volatile unsigned int*)CP_RSA_A_12_reg))
#define  CP_RSA_A_12_data_shift                                                  (0)
#define  CP_RSA_A_12_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_12_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_12_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_13                                                             0x1806E334
#define  CP_RSA_A_13_reg_addr                                                    "0xB806E334"
#define  CP_RSA_A_13_reg                                                         0xB806E334
#define  CP_RSA_A_13_inst_addr                                                   "0x01A5"
#define  set_CP_RSA_A_13_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_13_reg)=data)
#define  get_CP_RSA_A_13_reg                                                     (*((volatile unsigned int*)CP_RSA_A_13_reg))
#define  CP_RSA_A_13_data_shift                                                  (0)
#define  CP_RSA_A_13_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_13_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_13_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_14                                                             0x1806E338
#define  CP_RSA_A_14_reg_addr                                                    "0xB806E338"
#define  CP_RSA_A_14_reg                                                         0xB806E338
#define  CP_RSA_A_14_inst_addr                                                   "0x01A6"
#define  set_CP_RSA_A_14_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_14_reg)=data)
#define  get_CP_RSA_A_14_reg                                                     (*((volatile unsigned int*)CP_RSA_A_14_reg))
#define  CP_RSA_A_14_data_shift                                                  (0)
#define  CP_RSA_A_14_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_14_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_14_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_15                                                             0x1806E33C
#define  CP_RSA_A_15_reg_addr                                                    "0xB806E33C"
#define  CP_RSA_A_15_reg                                                         0xB806E33C
#define  CP_RSA_A_15_inst_addr                                                   "0x01A7"
#define  set_CP_RSA_A_15_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_15_reg)=data)
#define  get_CP_RSA_A_15_reg                                                     (*((volatile unsigned int*)CP_RSA_A_15_reg))
#define  CP_RSA_A_15_data_shift                                                  (0)
#define  CP_RSA_A_15_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_15_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_15_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_16                                                             0x1806E340
#define  CP_RSA_A_16_reg_addr                                                    "0xB806E340"
#define  CP_RSA_A_16_reg                                                         0xB806E340
#define  CP_RSA_A_16_inst_addr                                                   "0x01A8"
#define  set_CP_RSA_A_16_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_16_reg)=data)
#define  get_CP_RSA_A_16_reg                                                     (*((volatile unsigned int*)CP_RSA_A_16_reg))
#define  CP_RSA_A_16_data_shift                                                  (0)
#define  CP_RSA_A_16_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_16_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_16_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_17                                                             0x1806E344
#define  CP_RSA_A_17_reg_addr                                                    "0xB806E344"
#define  CP_RSA_A_17_reg                                                         0xB806E344
#define  CP_RSA_A_17_inst_addr                                                   "0x01A9"
#define  set_CP_RSA_A_17_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_17_reg)=data)
#define  get_CP_RSA_A_17_reg                                                     (*((volatile unsigned int*)CP_RSA_A_17_reg))
#define  CP_RSA_A_17_data_shift                                                  (0)
#define  CP_RSA_A_17_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_17_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_17_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_18                                                             0x1806E348
#define  CP_RSA_A_18_reg_addr                                                    "0xB806E348"
#define  CP_RSA_A_18_reg                                                         0xB806E348
#define  CP_RSA_A_18_inst_addr                                                   "0x01AA"
#define  set_CP_RSA_A_18_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_18_reg)=data)
#define  get_CP_RSA_A_18_reg                                                     (*((volatile unsigned int*)CP_RSA_A_18_reg))
#define  CP_RSA_A_18_data_shift                                                  (0)
#define  CP_RSA_A_18_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_18_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_18_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_19                                                             0x1806E34C
#define  CP_RSA_A_19_reg_addr                                                    "0xB806E34C"
#define  CP_RSA_A_19_reg                                                         0xB806E34C
#define  CP_RSA_A_19_inst_addr                                                   "0x01AB"
#define  set_CP_RSA_A_19_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_19_reg)=data)
#define  get_CP_RSA_A_19_reg                                                     (*((volatile unsigned int*)CP_RSA_A_19_reg))
#define  CP_RSA_A_19_data_shift                                                  (0)
#define  CP_RSA_A_19_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_19_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_19_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_20                                                             0x1806E350
#define  CP_RSA_A_20_reg_addr                                                    "0xB806E350"
#define  CP_RSA_A_20_reg                                                         0xB806E350
#define  CP_RSA_A_20_inst_addr                                                   "0x01AC"
#define  set_CP_RSA_A_20_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_20_reg)=data)
#define  get_CP_RSA_A_20_reg                                                     (*((volatile unsigned int*)CP_RSA_A_20_reg))
#define  CP_RSA_A_20_data_shift                                                  (0)
#define  CP_RSA_A_20_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_20_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_20_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_21                                                             0x1806E354
#define  CP_RSA_A_21_reg_addr                                                    "0xB806E354"
#define  CP_RSA_A_21_reg                                                         0xB806E354
#define  CP_RSA_A_21_inst_addr                                                   "0x01AD"
#define  set_CP_RSA_A_21_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_21_reg)=data)
#define  get_CP_RSA_A_21_reg                                                     (*((volatile unsigned int*)CP_RSA_A_21_reg))
#define  CP_RSA_A_21_data_shift                                                  (0)
#define  CP_RSA_A_21_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_21_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_21_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_22                                                             0x1806E358
#define  CP_RSA_A_22_reg_addr                                                    "0xB806E358"
#define  CP_RSA_A_22_reg                                                         0xB806E358
#define  CP_RSA_A_22_inst_addr                                                   "0x01AE"
#define  set_CP_RSA_A_22_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_22_reg)=data)
#define  get_CP_RSA_A_22_reg                                                     (*((volatile unsigned int*)CP_RSA_A_22_reg))
#define  CP_RSA_A_22_data_shift                                                  (0)
#define  CP_RSA_A_22_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_22_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_22_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_23                                                             0x1806E35C
#define  CP_RSA_A_23_reg_addr                                                    "0xB806E35C"
#define  CP_RSA_A_23_reg                                                         0xB806E35C
#define  CP_RSA_A_23_inst_addr                                                   "0x01AF"
#define  set_CP_RSA_A_23_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_23_reg)=data)
#define  get_CP_RSA_A_23_reg                                                     (*((volatile unsigned int*)CP_RSA_A_23_reg))
#define  CP_RSA_A_23_data_shift                                                  (0)
#define  CP_RSA_A_23_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_23_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_23_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_24                                                             0x1806E360
#define  CP_RSA_A_24_reg_addr                                                    "0xB806E360"
#define  CP_RSA_A_24_reg                                                         0xB806E360
#define  CP_RSA_A_24_inst_addr                                                   "0x01B0"
#define  set_CP_RSA_A_24_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_24_reg)=data)
#define  get_CP_RSA_A_24_reg                                                     (*((volatile unsigned int*)CP_RSA_A_24_reg))
#define  CP_RSA_A_24_data_shift                                                  (0)
#define  CP_RSA_A_24_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_24_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_24_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_25                                                             0x1806E364
#define  CP_RSA_A_25_reg_addr                                                    "0xB806E364"
#define  CP_RSA_A_25_reg                                                         0xB806E364
#define  CP_RSA_A_25_inst_addr                                                   "0x01B1"
#define  set_CP_RSA_A_25_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_25_reg)=data)
#define  get_CP_RSA_A_25_reg                                                     (*((volatile unsigned int*)CP_RSA_A_25_reg))
#define  CP_RSA_A_25_data_shift                                                  (0)
#define  CP_RSA_A_25_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_25_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_25_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_26                                                             0x1806E368
#define  CP_RSA_A_26_reg_addr                                                    "0xB806E368"
#define  CP_RSA_A_26_reg                                                         0xB806E368
#define  CP_RSA_A_26_inst_addr                                                   "0x01B2"
#define  set_CP_RSA_A_26_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_26_reg)=data)
#define  get_CP_RSA_A_26_reg                                                     (*((volatile unsigned int*)CP_RSA_A_26_reg))
#define  CP_RSA_A_26_data_shift                                                  (0)
#define  CP_RSA_A_26_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_26_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_26_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_27                                                             0x1806E36C
#define  CP_RSA_A_27_reg_addr                                                    "0xB806E36C"
#define  CP_RSA_A_27_reg                                                         0xB806E36C
#define  CP_RSA_A_27_inst_addr                                                   "0x01B3"
#define  set_CP_RSA_A_27_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_27_reg)=data)
#define  get_CP_RSA_A_27_reg                                                     (*((volatile unsigned int*)CP_RSA_A_27_reg))
#define  CP_RSA_A_27_data_shift                                                  (0)
#define  CP_RSA_A_27_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_27_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_27_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_28                                                             0x1806E370
#define  CP_RSA_A_28_reg_addr                                                    "0xB806E370"
#define  CP_RSA_A_28_reg                                                         0xB806E370
#define  CP_RSA_A_28_inst_addr                                                   "0x01B4"
#define  set_CP_RSA_A_28_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_28_reg)=data)
#define  get_CP_RSA_A_28_reg                                                     (*((volatile unsigned int*)CP_RSA_A_28_reg))
#define  CP_RSA_A_28_data_shift                                                  (0)
#define  CP_RSA_A_28_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_28_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_28_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_29                                                             0x1806E374
#define  CP_RSA_A_29_reg_addr                                                    "0xB806E374"
#define  CP_RSA_A_29_reg                                                         0xB806E374
#define  CP_RSA_A_29_inst_addr                                                   "0x01B5"
#define  set_CP_RSA_A_29_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_29_reg)=data)
#define  get_CP_RSA_A_29_reg                                                     (*((volatile unsigned int*)CP_RSA_A_29_reg))
#define  CP_RSA_A_29_data_shift                                                  (0)
#define  CP_RSA_A_29_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_29_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_29_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_30                                                             0x1806E378
#define  CP_RSA_A_30_reg_addr                                                    "0xB806E378"
#define  CP_RSA_A_30_reg                                                         0xB806E378
#define  CP_RSA_A_30_inst_addr                                                   "0x01B6"
#define  set_CP_RSA_A_30_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_30_reg)=data)
#define  get_CP_RSA_A_30_reg                                                     (*((volatile unsigned int*)CP_RSA_A_30_reg))
#define  CP_RSA_A_30_data_shift                                                  (0)
#define  CP_RSA_A_30_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_30_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_30_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_31                                                             0x1806E37C
#define  CP_RSA_A_31_reg_addr                                                    "0xB806E37C"
#define  CP_RSA_A_31_reg                                                         0xB806E37C
#define  CP_RSA_A_31_inst_addr                                                   "0x01B7"
#define  set_CP_RSA_A_31_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_31_reg)=data)
#define  get_CP_RSA_A_31_reg                                                     (*((volatile unsigned int*)CP_RSA_A_31_reg))
#define  CP_RSA_A_31_data_shift                                                  (0)
#define  CP_RSA_A_31_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_31_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_31_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_32                                                             0x1806E380
#define  CP_RSA_A_32_reg_addr                                                    "0xB806E380"
#define  CP_RSA_A_32_reg                                                         0xB806E380
#define  CP_RSA_A_32_inst_addr                                                   "0x01B8"
#define  set_CP_RSA_A_32_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_32_reg)=data)
#define  get_CP_RSA_A_32_reg                                                     (*((volatile unsigned int*)CP_RSA_A_32_reg))
#define  CP_RSA_A_32_data_shift                                                  (0)
#define  CP_RSA_A_32_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_32_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_32_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_33                                                             0x1806E384
#define  CP_RSA_A_33_reg_addr                                                    "0xB806E384"
#define  CP_RSA_A_33_reg                                                         0xB806E384
#define  CP_RSA_A_33_inst_addr                                                   "0x01B9"
#define  set_CP_RSA_A_33_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_33_reg)=data)
#define  get_CP_RSA_A_33_reg                                                     (*((volatile unsigned int*)CP_RSA_A_33_reg))
#define  CP_RSA_A_33_data_shift                                                  (0)
#define  CP_RSA_A_33_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_33_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_33_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_34                                                             0x1806E388
#define  CP_RSA_A_34_reg_addr                                                    "0xB806E388"
#define  CP_RSA_A_34_reg                                                         0xB806E388
#define  CP_RSA_A_34_inst_addr                                                   "0x01BA"
#define  set_CP_RSA_A_34_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_34_reg)=data)
#define  get_CP_RSA_A_34_reg                                                     (*((volatile unsigned int*)CP_RSA_A_34_reg))
#define  CP_RSA_A_34_data_shift                                                  (0)
#define  CP_RSA_A_34_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_34_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_34_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_35                                                             0x1806E38C
#define  CP_RSA_A_35_reg_addr                                                    "0xB806E38C"
#define  CP_RSA_A_35_reg                                                         0xB806E38C
#define  CP_RSA_A_35_inst_addr                                                   "0x01BB"
#define  set_CP_RSA_A_35_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_35_reg)=data)
#define  get_CP_RSA_A_35_reg                                                     (*((volatile unsigned int*)CP_RSA_A_35_reg))
#define  CP_RSA_A_35_data_shift                                                  (0)
#define  CP_RSA_A_35_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_35_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_35_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_36                                                             0x1806E390
#define  CP_RSA_A_36_reg_addr                                                    "0xB806E390"
#define  CP_RSA_A_36_reg                                                         0xB806E390
#define  CP_RSA_A_36_inst_addr                                                   "0x01BC"
#define  set_CP_RSA_A_36_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_36_reg)=data)
#define  get_CP_RSA_A_36_reg                                                     (*((volatile unsigned int*)CP_RSA_A_36_reg))
#define  CP_RSA_A_36_data_shift                                                  (0)
#define  CP_RSA_A_36_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_36_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_36_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_37                                                             0x1806E394
#define  CP_RSA_A_37_reg_addr                                                    "0xB806E394"
#define  CP_RSA_A_37_reg                                                         0xB806E394
#define  CP_RSA_A_37_inst_addr                                                   "0x01BD"
#define  set_CP_RSA_A_37_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_37_reg)=data)
#define  get_CP_RSA_A_37_reg                                                     (*((volatile unsigned int*)CP_RSA_A_37_reg))
#define  CP_RSA_A_37_data_shift                                                  (0)
#define  CP_RSA_A_37_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_37_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_37_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_38                                                             0x1806E398
#define  CP_RSA_A_38_reg_addr                                                    "0xB806E398"
#define  CP_RSA_A_38_reg                                                         0xB806E398
#define  CP_RSA_A_38_inst_addr                                                   "0x01BE"
#define  set_CP_RSA_A_38_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_38_reg)=data)
#define  get_CP_RSA_A_38_reg                                                     (*((volatile unsigned int*)CP_RSA_A_38_reg))
#define  CP_RSA_A_38_data_shift                                                  (0)
#define  CP_RSA_A_38_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_38_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_38_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_39                                                             0x1806E39C
#define  CP_RSA_A_39_reg_addr                                                    "0xB806E39C"
#define  CP_RSA_A_39_reg                                                         0xB806E39C
#define  CP_RSA_A_39_inst_addr                                                   "0x01BF"
#define  set_CP_RSA_A_39_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_39_reg)=data)
#define  get_CP_RSA_A_39_reg                                                     (*((volatile unsigned int*)CP_RSA_A_39_reg))
#define  CP_RSA_A_39_data_shift                                                  (0)
#define  CP_RSA_A_39_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_39_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_39_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_40                                                             0x1806E3A0
#define  CP_RSA_A_40_reg_addr                                                    "0xB806E3A0"
#define  CP_RSA_A_40_reg                                                         0xB806E3A0
#define  CP_RSA_A_40_inst_addr                                                   "0x01C0"
#define  set_CP_RSA_A_40_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_40_reg)=data)
#define  get_CP_RSA_A_40_reg                                                     (*((volatile unsigned int*)CP_RSA_A_40_reg))
#define  CP_RSA_A_40_data_shift                                                  (0)
#define  CP_RSA_A_40_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_40_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_40_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_41                                                             0x1806E3A4
#define  CP_RSA_A_41_reg_addr                                                    "0xB806E3A4"
#define  CP_RSA_A_41_reg                                                         0xB806E3A4
#define  CP_RSA_A_41_inst_addr                                                   "0x01C1"
#define  set_CP_RSA_A_41_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_41_reg)=data)
#define  get_CP_RSA_A_41_reg                                                     (*((volatile unsigned int*)CP_RSA_A_41_reg))
#define  CP_RSA_A_41_data_shift                                                  (0)
#define  CP_RSA_A_41_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_41_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_41_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_42                                                             0x1806E3A8
#define  CP_RSA_A_42_reg_addr                                                    "0xB806E3A8"
#define  CP_RSA_A_42_reg                                                         0xB806E3A8
#define  CP_RSA_A_42_inst_addr                                                   "0x01C2"
#define  set_CP_RSA_A_42_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_42_reg)=data)
#define  get_CP_RSA_A_42_reg                                                     (*((volatile unsigned int*)CP_RSA_A_42_reg))
#define  CP_RSA_A_42_data_shift                                                  (0)
#define  CP_RSA_A_42_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_42_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_42_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_43                                                             0x1806E3AC
#define  CP_RSA_A_43_reg_addr                                                    "0xB806E3AC"
#define  CP_RSA_A_43_reg                                                         0xB806E3AC
#define  CP_RSA_A_43_inst_addr                                                   "0x01C3"
#define  set_CP_RSA_A_43_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_43_reg)=data)
#define  get_CP_RSA_A_43_reg                                                     (*((volatile unsigned int*)CP_RSA_A_43_reg))
#define  CP_RSA_A_43_data_shift                                                  (0)
#define  CP_RSA_A_43_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_43_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_43_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_44                                                             0x1806E3B0
#define  CP_RSA_A_44_reg_addr                                                    "0xB806E3B0"
#define  CP_RSA_A_44_reg                                                         0xB806E3B0
#define  CP_RSA_A_44_inst_addr                                                   "0x01C4"
#define  set_CP_RSA_A_44_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_44_reg)=data)
#define  get_CP_RSA_A_44_reg                                                     (*((volatile unsigned int*)CP_RSA_A_44_reg))
#define  CP_RSA_A_44_data_shift                                                  (0)
#define  CP_RSA_A_44_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_44_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_44_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_45                                                             0x1806E3B4
#define  CP_RSA_A_45_reg_addr                                                    "0xB806E3B4"
#define  CP_RSA_A_45_reg                                                         0xB806E3B4
#define  CP_RSA_A_45_inst_addr                                                   "0x01C5"
#define  set_CP_RSA_A_45_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_45_reg)=data)
#define  get_CP_RSA_A_45_reg                                                     (*((volatile unsigned int*)CP_RSA_A_45_reg))
#define  CP_RSA_A_45_data_shift                                                  (0)
#define  CP_RSA_A_45_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_45_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_45_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_46                                                             0x1806E3B8
#define  CP_RSA_A_46_reg_addr                                                    "0xB806E3B8"
#define  CP_RSA_A_46_reg                                                         0xB806E3B8
#define  CP_RSA_A_46_inst_addr                                                   "0x01C6"
#define  set_CP_RSA_A_46_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_46_reg)=data)
#define  get_CP_RSA_A_46_reg                                                     (*((volatile unsigned int*)CP_RSA_A_46_reg))
#define  CP_RSA_A_46_data_shift                                                  (0)
#define  CP_RSA_A_46_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_46_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_46_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_47                                                             0x1806E3BC
#define  CP_RSA_A_47_reg_addr                                                    "0xB806E3BC"
#define  CP_RSA_A_47_reg                                                         0xB806E3BC
#define  CP_RSA_A_47_inst_addr                                                   "0x01C7"
#define  set_CP_RSA_A_47_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_47_reg)=data)
#define  get_CP_RSA_A_47_reg                                                     (*((volatile unsigned int*)CP_RSA_A_47_reg))
#define  CP_RSA_A_47_data_shift                                                  (0)
#define  CP_RSA_A_47_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_47_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_47_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_48                                                             0x1806E3C0
#define  CP_RSA_A_48_reg_addr                                                    "0xB806E3C0"
#define  CP_RSA_A_48_reg                                                         0xB806E3C0
#define  CP_RSA_A_48_inst_addr                                                   "0x01C8"
#define  set_CP_RSA_A_48_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_48_reg)=data)
#define  get_CP_RSA_A_48_reg                                                     (*((volatile unsigned int*)CP_RSA_A_48_reg))
#define  CP_RSA_A_48_data_shift                                                  (0)
#define  CP_RSA_A_48_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_48_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_48_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_49                                                             0x1806E3C4
#define  CP_RSA_A_49_reg_addr                                                    "0xB806E3C4"
#define  CP_RSA_A_49_reg                                                         0xB806E3C4
#define  CP_RSA_A_49_inst_addr                                                   "0x01C9"
#define  set_CP_RSA_A_49_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_49_reg)=data)
#define  get_CP_RSA_A_49_reg                                                     (*((volatile unsigned int*)CP_RSA_A_49_reg))
#define  CP_RSA_A_49_data_shift                                                  (0)
#define  CP_RSA_A_49_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_49_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_49_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_50                                                             0x1806E3C8
#define  CP_RSA_A_50_reg_addr                                                    "0xB806E3C8"
#define  CP_RSA_A_50_reg                                                         0xB806E3C8
#define  CP_RSA_A_50_inst_addr                                                   "0x01CA"
#define  set_CP_RSA_A_50_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_50_reg)=data)
#define  get_CP_RSA_A_50_reg                                                     (*((volatile unsigned int*)CP_RSA_A_50_reg))
#define  CP_RSA_A_50_data_shift                                                  (0)
#define  CP_RSA_A_50_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_50_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_50_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_51                                                             0x1806E3CC
#define  CP_RSA_A_51_reg_addr                                                    "0xB806E3CC"
#define  CP_RSA_A_51_reg                                                         0xB806E3CC
#define  CP_RSA_A_51_inst_addr                                                   "0x01CB"
#define  set_CP_RSA_A_51_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_51_reg)=data)
#define  get_CP_RSA_A_51_reg                                                     (*((volatile unsigned int*)CP_RSA_A_51_reg))
#define  CP_RSA_A_51_data_shift                                                  (0)
#define  CP_RSA_A_51_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_51_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_51_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_52                                                             0x1806E3D0
#define  CP_RSA_A_52_reg_addr                                                    "0xB806E3D0"
#define  CP_RSA_A_52_reg                                                         0xB806E3D0
#define  CP_RSA_A_52_inst_addr                                                   "0x01CC"
#define  set_CP_RSA_A_52_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_52_reg)=data)
#define  get_CP_RSA_A_52_reg                                                     (*((volatile unsigned int*)CP_RSA_A_52_reg))
#define  CP_RSA_A_52_data_shift                                                  (0)
#define  CP_RSA_A_52_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_52_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_52_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_53                                                             0x1806E3D4
#define  CP_RSA_A_53_reg_addr                                                    "0xB806E3D4"
#define  CP_RSA_A_53_reg                                                         0xB806E3D4
#define  CP_RSA_A_53_inst_addr                                                   "0x01CD"
#define  set_CP_RSA_A_53_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_53_reg)=data)
#define  get_CP_RSA_A_53_reg                                                     (*((volatile unsigned int*)CP_RSA_A_53_reg))
#define  CP_RSA_A_53_data_shift                                                  (0)
#define  CP_RSA_A_53_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_53_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_53_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_54                                                             0x1806E3D8
#define  CP_RSA_A_54_reg_addr                                                    "0xB806E3D8"
#define  CP_RSA_A_54_reg                                                         0xB806E3D8
#define  CP_RSA_A_54_inst_addr                                                   "0x01CE"
#define  set_CP_RSA_A_54_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_54_reg)=data)
#define  get_CP_RSA_A_54_reg                                                     (*((volatile unsigned int*)CP_RSA_A_54_reg))
#define  CP_RSA_A_54_data_shift                                                  (0)
#define  CP_RSA_A_54_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_54_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_54_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_55                                                             0x1806E3DC
#define  CP_RSA_A_55_reg_addr                                                    "0xB806E3DC"
#define  CP_RSA_A_55_reg                                                         0xB806E3DC
#define  CP_RSA_A_55_inst_addr                                                   "0x01CF"
#define  set_CP_RSA_A_55_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_55_reg)=data)
#define  get_CP_RSA_A_55_reg                                                     (*((volatile unsigned int*)CP_RSA_A_55_reg))
#define  CP_RSA_A_55_data_shift                                                  (0)
#define  CP_RSA_A_55_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_55_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_55_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_56                                                             0x1806E3E0
#define  CP_RSA_A_56_reg_addr                                                    "0xB806E3E0"
#define  CP_RSA_A_56_reg                                                         0xB806E3E0
#define  CP_RSA_A_56_inst_addr                                                   "0x01D0"
#define  set_CP_RSA_A_56_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_56_reg)=data)
#define  get_CP_RSA_A_56_reg                                                     (*((volatile unsigned int*)CP_RSA_A_56_reg))
#define  CP_RSA_A_56_data_shift                                                  (0)
#define  CP_RSA_A_56_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_56_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_56_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_57                                                             0x1806E3E4
#define  CP_RSA_A_57_reg_addr                                                    "0xB806E3E4"
#define  CP_RSA_A_57_reg                                                         0xB806E3E4
#define  CP_RSA_A_57_inst_addr                                                   "0x01D1"
#define  set_CP_RSA_A_57_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_57_reg)=data)
#define  get_CP_RSA_A_57_reg                                                     (*((volatile unsigned int*)CP_RSA_A_57_reg))
#define  CP_RSA_A_57_data_shift                                                  (0)
#define  CP_RSA_A_57_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_57_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_57_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_58                                                             0x1806E3E8
#define  CP_RSA_A_58_reg_addr                                                    "0xB806E3E8"
#define  CP_RSA_A_58_reg                                                         0xB806E3E8
#define  CP_RSA_A_58_inst_addr                                                   "0x01D2"
#define  set_CP_RSA_A_58_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_58_reg)=data)
#define  get_CP_RSA_A_58_reg                                                     (*((volatile unsigned int*)CP_RSA_A_58_reg))
#define  CP_RSA_A_58_data_shift                                                  (0)
#define  CP_RSA_A_58_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_58_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_58_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_59                                                             0x1806E3EC
#define  CP_RSA_A_59_reg_addr                                                    "0xB806E3EC"
#define  CP_RSA_A_59_reg                                                         0xB806E3EC
#define  CP_RSA_A_59_inst_addr                                                   "0x01D3"
#define  set_CP_RSA_A_59_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_59_reg)=data)
#define  get_CP_RSA_A_59_reg                                                     (*((volatile unsigned int*)CP_RSA_A_59_reg))
#define  CP_RSA_A_59_data_shift                                                  (0)
#define  CP_RSA_A_59_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_59_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_59_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_60                                                             0x1806E3F0
#define  CP_RSA_A_60_reg_addr                                                    "0xB806E3F0"
#define  CP_RSA_A_60_reg                                                         0xB806E3F0
#define  CP_RSA_A_60_inst_addr                                                   "0x01D4"
#define  set_CP_RSA_A_60_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_60_reg)=data)
#define  get_CP_RSA_A_60_reg                                                     (*((volatile unsigned int*)CP_RSA_A_60_reg))
#define  CP_RSA_A_60_data_shift                                                  (0)
#define  CP_RSA_A_60_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_60_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_60_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_61                                                             0x1806E3F4
#define  CP_RSA_A_61_reg_addr                                                    "0xB806E3F4"
#define  CP_RSA_A_61_reg                                                         0xB806E3F4
#define  CP_RSA_A_61_inst_addr                                                   "0x01D5"
#define  set_CP_RSA_A_61_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_61_reg)=data)
#define  get_CP_RSA_A_61_reg                                                     (*((volatile unsigned int*)CP_RSA_A_61_reg))
#define  CP_RSA_A_61_data_shift                                                  (0)
#define  CP_RSA_A_61_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_61_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_61_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_62                                                             0x1806E3F8
#define  CP_RSA_A_62_reg_addr                                                    "0xB806E3F8"
#define  CP_RSA_A_62_reg                                                         0xB806E3F8
#define  CP_RSA_A_62_inst_addr                                                   "0x01D6"
#define  set_CP_RSA_A_62_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_62_reg)=data)
#define  get_CP_RSA_A_62_reg                                                     (*((volatile unsigned int*)CP_RSA_A_62_reg))
#define  CP_RSA_A_62_data_shift                                                  (0)
#define  CP_RSA_A_62_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_62_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_62_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_A_63                                                             0x1806E3FC
#define  CP_RSA_A_63_reg_addr                                                    "0xB806E3FC"
#define  CP_RSA_A_63_reg                                                         0xB806E3FC
#define  CP_RSA_A_63_inst_addr                                                   "0x01D7"
#define  set_CP_RSA_A_63_reg(data)                                               (*((volatile unsigned int*)CP_RSA_A_63_reg)=data)
#define  get_CP_RSA_A_63_reg                                                     (*((volatile unsigned int*)CP_RSA_A_63_reg))
#define  CP_RSA_A_63_data_shift                                                  (0)
#define  CP_RSA_A_63_data_mask                                                   (0xFFFFFFFF)
#define  CP_RSA_A_63_data(data)                                                  (0xFFFFFFFF&(data))
#define  CP_RSA_A_63_get_data(data)                                              (0xFFFFFFFF&(data))

#define  CP_RSA_CTRL                                                             0x1806E400
#define  CP_RSA_CTRL_reg_addr                                                    "0xB806E400"
#define  CP_RSA_CTRL_reg                                                         0xB806E400
#define  CP_RSA_CTRL_inst_addr                                                   "0x01D8"
#define  set_CP_RSA_CTRL_reg(data)                                               (*((volatile unsigned int*)CP_RSA_CTRL_reg)=data)
#define  get_CP_RSA_CTRL_reg                                                     (*((volatile unsigned int*)CP_RSA_CTRL_reg))
#define  CP_RSA_CTRL_ecc_go_shift                                                (4)
#define  CP_RSA_CTRL_rsa_go_shift                                                (0)
#define  CP_RSA_CTRL_ecc_go_mask                                                 (0x00000010)
#define  CP_RSA_CTRL_rsa_go_mask                                                 (0x00000001)
#define  CP_RSA_CTRL_ecc_go(data)                                                (0x00000010&((data)<<4))
#define  CP_RSA_CTRL_rsa_go(data)                                                (0x00000001&(data))
#define  CP_RSA_CTRL_get_ecc_go(data)                                            ((0x00000010&(data))>>4)
#define  CP_RSA_CTRL_get_rsa_go(data)                                            (0x00000001&(data))

#define  CP_RSA_NUM                                                              0x1806E404
#define  CP_RSA_NUM_reg_addr                                                     "0xB806E404"
#define  CP_RSA_NUM_reg                                                          0xB806E404
#define  CP_RSA_NUM_inst_addr                                                    "0x01D9"
#define  set_CP_RSA_NUM_reg(data)                                                (*((volatile unsigned int*)CP_RSA_NUM_reg)=data)
#define  get_CP_RSA_NUM_reg                                                      (*((volatile unsigned int*)CP_RSA_NUM_reg))
#define  CP_RSA_NUM_bits_num_shift                                               (0)
#define  CP_RSA_NUM_bits_num_mask                                                (0x0000003F)
#define  CP_RSA_NUM_bits_num(data)                                               (0x0000003F&(data))
#define  CP_RSA_NUM_get_bits_num(data)                                           (0x0000003F&(data))

#define  CP_RSA_INT_STATUS                                                       0x1806E408
#define  CP_RSA_INT_STATUS_reg_addr                                              "0xB806E408"
#define  CP_RSA_INT_STATUS_reg                                                   0xB806E408
#define  CP_RSA_INT_STATUS_inst_addr                                             "0x01DA"
#define  set_CP_RSA_INT_STATUS_reg(data)                                         (*((volatile unsigned int*)CP_RSA_INT_STATUS_reg)=data)
#define  get_CP_RSA_INT_STATUS_reg                                               (*((volatile unsigned int*)CP_RSA_INT_STATUS_reg))
#define  CP_RSA_INT_STATUS_ecc_done_shift                                        (4)
#define  CP_RSA_INT_STATUS_rsa_done_shift                                        (0)
#define  CP_RSA_INT_STATUS_ecc_done_mask                                         (0x00000010)
#define  CP_RSA_INT_STATUS_rsa_done_mask                                         (0x00000001)
#define  CP_RSA_INT_STATUS_ecc_done(data)                                        (0x00000010&((data)<<4))
#define  CP_RSA_INT_STATUS_rsa_done(data)                                        (0x00000001&(data))
#define  CP_RSA_INT_STATUS_get_ecc_done(data)                                    ((0x00000010&(data))>>4)
#define  CP_RSA_INT_STATUS_get_rsa_done(data)                                    (0x00000001&(data))

#define  CP_RSA_CLEAR                                                            0x1806E40C
#define  CP_RSA_CLEAR_reg_addr                                                   "0xB806E40C"
#define  CP_RSA_CLEAR_reg                                                        0xB806E40C
#define  CP_RSA_CLEAR_inst_addr                                                  "0x01DB"
#define  set_CP_RSA_CLEAR_reg(data)                                              (*((volatile unsigned int*)CP_RSA_CLEAR_reg)=data)
#define  get_CP_RSA_CLEAR_reg                                                    (*((volatile unsigned int*)CP_RSA_CLEAR_reg))
#define  CP_RSA_CLEAR_rsa_clear_shift                                            (0)
#define  CP_RSA_CLEAR_rsa_clear_mask                                             (0x00000001)
#define  CP_RSA_CLEAR_rsa_clear(data)                                            (0x00000001&(data))
#define  CP_RSA_CLEAR_get_rsa_clear(data)                                        (0x00000001&(data))

#define  CP_RSA_DUMMY                                                            0x1806E410
#define  CP_RSA_DUMMY_reg_addr                                                   "0xB806E410"
#define  CP_RSA_DUMMY_reg                                                        0xB806E410
#define  CP_RSA_DUMMY_inst_addr                                                  "0x01DC"
#define  set_CP_RSA_DUMMY_reg(data)                                              (*((volatile unsigned int*)CP_RSA_DUMMY_reg)=data)
#define  get_CP_RSA_DUMMY_reg                                                    (*((volatile unsigned int*)CP_RSA_DUMMY_reg))
#define  CP_RSA_DUMMY_dummy_31_0_shift                                           (0)
#define  CP_RSA_DUMMY_dummy_31_0_mask                                            (0xFFFFFFFF)
#define  CP_RSA_DUMMY_dummy_31_0(data)                                           (0xFFFFFFFF&(data))
#define  CP_RSA_DUMMY_get_dummy_31_0(data)                                       (0xFFFFFFFF&(data))

#define  CP_S_RSA_INT_EN                                                         0x1806E500
#define  CP_S_RSA_INT_EN_reg_addr                                                "0xB806E500"
#define  CP_S_RSA_INT_EN_reg                                                     0xB806E500
#define  CP_S_RSA_INT_EN_inst_addr                                               "0x01DD"
#define  set_CP_S_RSA_INT_EN_reg(data)                                           (*((volatile unsigned int*)CP_S_RSA_INT_EN_reg)=data)
#define  get_CP_S_RSA_INT_EN_reg                                                 (*((volatile unsigned int*)CP_S_RSA_INT_EN_reg))
#define  CP_S_RSA_INT_EN_scpu_en_shift                                           (0)
#define  CP_S_RSA_INT_EN_scpu_en_mask                                            (0x00000001)
#define  CP_S_RSA_INT_EN_scpu_en(data)                                           (0x00000001&(data))
#define  CP_S_RSA_INT_EN_get_scpu_en(data)                                       (0x00000001&(data))

#define  CP_S_RSA_SEL                                                            0x1806E504
#define  CP_S_RSA_SEL_reg_addr                                                   "0xB806E504"
#define  CP_S_RSA_SEL_reg                                                        0xB806E504
#define  CP_S_RSA_SEL_inst_addr                                                  "0x01DE"
#define  set_CP_S_RSA_SEL_reg(data)                                              (*((volatile unsigned int*)CP_S_RSA_SEL_reg)=data)
#define  get_CP_S_RSA_SEL_reg                                                    (*((volatile unsigned int*)CP_S_RSA_SEL_reg))
#define  CP_S_RSA_SEL_scpu_sel_shift                                             (0)
#define  CP_S_RSA_SEL_scpu_sel_mask                                              (0x00000001)
#define  CP_S_RSA_SEL_scpu_sel(data)                                             (0x00000001&(data))
#define  CP_S_RSA_SEL_get_scpu_sel(data)                                         (0x00000001&(data))

#define  CP_S_RSA_ST                                                             0x1806E508
#define  CP_S_RSA_ST_reg_addr                                                    "0xB806E508"
#define  CP_S_RSA_ST_reg                                                         0xB806E508
#define  CP_S_RSA_ST_inst_addr                                                   "0x01DF"
#define  set_CP_S_RSA_ST_reg(data)                                               (*((volatile unsigned int*)CP_S_RSA_ST_reg)=data)
#define  get_CP_S_RSA_ST_reg                                                     (*((volatile unsigned int*)CP_S_RSA_ST_reg))
#define  CP_S_RSA_ST_scpu_st_shift                                               (0)
#define  CP_S_RSA_ST_scpu_st_mask                                                (0x00000001)
#define  CP_S_RSA_ST_scpu_st(data)                                               (0x00000001&(data))
#define  CP_S_RSA_ST_get_scpu_st(data)                                           (0x00000001&(data))

#define  CP_K_RSA_INT_EN                                                         0x1806E600
#define  CP_K_RSA_INT_EN_reg_addr                                                "0xB806E600"
#define  CP_K_RSA_INT_EN_reg                                                     0xB806E600
#define  CP_K_RSA_INT_EN_inst_addr                                               "0x01E0"
#define  set_CP_K_RSA_INT_EN_reg(data)                                           (*((volatile unsigned int*)CP_K_RSA_INT_EN_reg)=data)
#define  get_CP_K_RSA_INT_EN_reg                                                 (*((volatile unsigned int*)CP_K_RSA_INT_EN_reg))
#define  CP_K_RSA_INT_EN_kcpu_en_shift                                           (0)
#define  CP_K_RSA_INT_EN_kcpu_en_mask                                            (0x00000001)
#define  CP_K_RSA_INT_EN_kcpu_en(data)                                           (0x00000001&(data))
#define  CP_K_RSA_INT_EN_get_kcpu_en(data)                                       (0x00000001&(data))

#define  CP_K_RSA_SEL                                                            0x1806E604
#define  CP_K_RSA_SEL_reg_addr                                                   "0xB806E604"
#define  CP_K_RSA_SEL_reg                                                        0xB806E604
#define  CP_K_RSA_SEL_inst_addr                                                  "0x01E1"
#define  set_CP_K_RSA_SEL_reg(data)                                              (*((volatile unsigned int*)CP_K_RSA_SEL_reg)=data)
#define  get_CP_K_RSA_SEL_reg                                                    (*((volatile unsigned int*)CP_K_RSA_SEL_reg))
#define  CP_K_RSA_SEL_kcpu_sel_shift                                             (0)
#define  CP_K_RSA_SEL_kcpu_sel_mask                                              (0x00000001)
#define  CP_K_RSA_SEL_kcpu_sel(data)                                             (0x00000001&(data))
#define  CP_K_RSA_SEL_get_kcpu_sel(data)                                         (0x00000001&(data))

#define  CP_K_RSA_ST                                                             0x1806E608
#define  CP_K_RSA_ST_reg_addr                                                    "0xB806E608"
#define  CP_K_RSA_ST_reg                                                         0xB806E608
#define  CP_K_RSA_ST_inst_addr                                                   "0x01E2"
#define  set_CP_K_RSA_ST_reg(data)                                               (*((volatile unsigned int*)CP_K_RSA_ST_reg)=data)
#define  get_CP_K_RSA_ST_reg                                                     (*((volatile unsigned int*)CP_K_RSA_ST_reg))
#define  CP_K_RSA_ST_kcpu_st_shift                                               (0)
#define  CP_K_RSA_ST_kcpu_st_mask                                                (0x00000001)
#define  CP_K_RSA_ST_kcpu_st(data)                                               (0x00000001&(data))
#define  CP_K_RSA_ST_get_kcpu_st(data)                                           (0x00000001&(data))

#define  CP_K_RSA_SECURITY                                                       0x1806E610
#define  CP_K_RSA_SECURITY_reg_addr                                              "0xB806E610"
#define  CP_K_RSA_SECURITY_reg                                                   0xB806E610
#define  CP_K_RSA_SECURITY_inst_addr                                             "0x01E3"
#define  set_CP_K_RSA_SECURITY_reg(data)                                         (*((volatile unsigned int*)CP_K_RSA_SECURITY_reg)=data)
#define  get_CP_K_RSA_SECURITY_reg                                               (*((volatile unsigned int*)CP_K_RSA_SECURITY_reg))
#define  CP_K_RSA_SECURITY_on_shift                                              (0)
#define  CP_K_RSA_SECURITY_on_mask                                               (0x00000001)
#define  CP_K_RSA_SECURITY_on(data)                                              (0x00000001&(data))
#define  CP_K_RSA_SECURITY_get_on(data)                                          (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======CP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  arb_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  clear:1;
        RBus_UInt32  swap:1;
        RBus_UInt32  idle:1;
        RBus_UInt32  go:1;
        RBus_UInt32  write_data:1;
    };
}cp_mcp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  k_error:1;
        RBus_UInt32  k_compare:1;
        RBus_UInt32  k_ring_empty:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  compare:1;
        RBus_UInt32  error:1;
        RBus_UInt32  ring_empty:1;
        RBus_UInt32  write_data:1;
    };
}cp_mcp_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  compare_en:1;
        RBus_UInt32  error_en:1;
        RBus_UInt32  ring_empty_en:1;
        RBus_UInt32  write_data:1;
    };
}cp_mcp_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  aesh_pad_off:1;
        RBus_UInt32  csa_entropy:2;
        RBus_UInt32  mcp_round_no:8;
    };
}cp_mcp_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base:32;
    };
}cp_mcp_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit:32;
    };
}cp_mcp_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rdptr:32;
    };
}cp_mcp_rdptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrptr:32;
    };
}cp_mcp_wrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  count:16;
    };
}cp_mcp_des_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  compare:16;
    };
}cp_mcp_des_compare_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_mcp_des_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_mcp_aes_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_mcp_came_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_mcp_multi2_sys_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  otp_load:1;
    };
}cp_cp_otp_load_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  clear:1;
        RBus_UInt32  swap:1;
        RBus_UInt32  idle:1;
        RBus_UInt32  go:1;
        RBus_UInt32  write_data:1;
    };
}cp_k_mcp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  s_error:1;
        RBus_UInt32  s_compare:1;
        RBus_UInt32  s_ring_empty:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  compare:1;
        RBus_UInt32  error:1;
        RBus_UInt32  ring_empty:1;
        RBus_UInt32  write_data:1;
    };
}cp_k_mcp_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  compare_en:1;
        RBus_UInt32  error_en:1;
        RBus_UInt32  ring_empty_en:1;
        RBus_UInt32  write_data:1;
    };
}cp_k_mcp_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  aesh_pad_off:1;
        RBus_UInt32  csa_entropy:2;
        RBus_UInt32  mcp_round_no:8;
    };
}cp_k_mcp_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base:32;
    };
}cp_k_mcp_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit:32;
    };
}cp_k_mcp_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rdptr:32;
    };
}cp_k_mcp_rdptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrptr:32;
    };
}cp_k_mcp_wrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  count:16;
    };
}cp_k_mcp_des_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  compare:16;
    };
}cp_k_mcp_des_compare_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_mcp_des_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_mcp_aes_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_mcp_came_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_mcp_multi2_sys_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  rd_sm:4;
        RBus_UInt32  wr_sm:3;
        RBus_UInt32  res2:10;
        RBus_UInt32  mcp_aes_like_sm:11;
    };
}cp_mcp_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  mcp_top_sm:18;
    };
}cp_mcp_st1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  en_rsa:1;
        RBus_UInt32  en_cp:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:6;
        RBus_UInt32  sram_ctr:5;
        RBus_UInt32  res4:10;
    };
}cp_cp_pwm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  write_en3:1;
        RBus_UInt32  stop:1;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  test_mode:2;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  wait_sec:5;
    };
}cp_rcic_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  write_en7:1;
        RBus_UInt32  valid_7:1;
        RBus_UInt32  write_en6:1;
        RBus_UInt32  valid_6:1;
        RBus_UInt32  write_en5:1;
        RBus_UInt32  valid_5:1;
        RBus_UInt32  write_en4:1;
        RBus_UInt32  valid_4:1;
        RBus_UInt32  write_en3:1;
        RBus_UInt32  valid_3:1;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  valid_2:1;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  valid_1:1;
        RBus_UInt32  write_en0:1;
        RBus_UInt32  valid_0:1;
    };
}cp_rcic_entr_vld_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  entry:3;
        RBus_UInt32  done:1;
    };
}cp_rcic_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adr:32;
    };
}cp_rcic_entr_src_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adr:32;
    };
}cp_rcic_entr_dst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  int_en:1;
    };
}cp_rcic_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  semaphore:1;
    };
}cp_cp_reg_semaphore_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_reg_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_reg_key1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_reg_datain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_reg_dataout_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_reg_iv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  mode:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  endian_swap:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  cw_logic_opsel:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  bcm:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  reg_first:1;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  reg_ende:1;
    };
}cp_cp_reg_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  key_mode:2;
        RBus_UInt32  iv_mode:2;
        RBus_UInt32  input_mode:2;
        RBus_UInt32  output_mode:2;
    };
}cp_cp_reg_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  output_entry:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  input_entry:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  key_entry:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  iv_entry:7;
    };
}cp_cp_reg_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg1:16;
        RBus_UInt32  reg0:16;
    };
}cp_cp_sctch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_nf_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_nf_key1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_nf_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  key_length:2;
        RBus_UInt32  bcm:2;
        RBus_UInt32  cw_entry:7;
        RBus_UInt32  sel:2;
    };
}cp_cp_nf_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  sel:1;
    };
}cp_cp_nf_emmc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_md_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_md_key1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_md_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  key_length:2;
        RBus_UInt32  bcm:2;
        RBus_UInt32  cw_entry:7;
        RBus_UInt32  sel:2;
    };
}cp_cp_md_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  semaphore:1;
    };
}cp_k_cp_reg_semaphore_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_reg_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_reg_key1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_reg_datain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_reg_dataout_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_reg_iv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  mode:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  endian_swap:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  cw_logic_opsel:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  bcm:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  reg_first:1;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  reg_ende:1;
    };
}cp_k_cp_reg_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  key_mode:3;
        RBus_UInt32  iv_mode:2;
        RBus_UInt32  input_mode:2;
        RBus_UInt32  output_mode:2;
    };
}cp_k_cp_reg_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  output_entry:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  input_entry:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  key_entry:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  iv_entry:7;
    };
}cp_k_cp_reg_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_nf_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_nf_key1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_nf_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  key_length:2;
        RBus_UInt32  bcm:2;
        RBus_UInt32  cw_entry:7;
        RBus_UInt32  sel:2;
    };
}cp_k_cp_nf_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_md_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_md_key1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_md_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  key_length:2;
        RBus_UInt32  bcm:2;
        RBus_UInt32  cw_entry:7;
        RBus_UInt32  sel:2;
    };
}cp_k_cp_md_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dbg_sel1:5;
        RBus_UInt32  dbg_sel0:5;
        RBus_UInt32  dbg_en:1;
    };
}cp_cp_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  tst_sel1:5;
        RBus_UInt32  tst_sel0:5;
        RBus_UInt32  tst_en:1;
    };
}cp_cp_tst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_out:32;
    };
}cp_cp_tst2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  en2:1;
        RBus_UInt32  en:1;
    };
}cp_cp_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  done2:1;
        RBus_UInt32  done:1;
    };
}cp_cp_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  fail_group:1;
    };
}cp_cp_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  fail3:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  fail2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  fail1:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  fail0:1;
    };
}cp_cp_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  en2:1;
        RBus_UInt32  en:1;
    };
}cp_cp_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  done2:1;
        RBus_UInt32  done:1;
    };
}cp_cp_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  fail_group:1;
    };
}cp_cp_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  fail3:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  fail2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  fail1:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  fail0:1;
    };
}cp_cp_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  en2:1;
        RBus_UInt32  en:1;
    };
}cp_cp_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  flag2:1;
        RBus_UInt32  flag:1;
    };
}cp_cp_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  rsa_rme:1;
        RBus_UInt32  rsa_rm:4;
        RBus_UInt32  din1_rme:1;
        RBus_UInt32  din1_rm:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  din0_rme:1;
        RBus_UInt32  din0_rm:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  desc_rme:1;
        RBus_UInt32  desc_rm:4;
    };
}cp_cp_sram_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  rsa_ls:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  din1_ls:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  din0_ls:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  desc_ls:1;
    };
}cp_cp_sram_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  start:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  end:7;
    };
}cp_k_cp_scpu_cw_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  scpu_illegal_access:1;
    };
}cp_k_cp_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  scpu_illegal_access_en:1;
    };
}cp_k_cp_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_rsa_x_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_rsa_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_rsa_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_rsa_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  ecc_go:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rsa_go:1;
    };
}cp_rsa_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  bits_num:6;
    };
}cp_rsa_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  ecc_done:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rsa_done:1;
    };
}cp_rsa_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  rsa_clear:1;
    };
}cp_rsa_clear_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1806e410_31_0:32;
    };
}cp_rsa_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  scpu_en:1;
    };
}cp_s_rsa_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  scpu_sel:1;
    };
}cp_s_rsa_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  scpu_st:1;
    };
}cp_s_rsa_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  kcpu_en:1;
    };
}cp_k_rsa_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  kcpu_sel:1;
    };
}cp_k_rsa_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  kcpu_st:1;
    };
}cp_k_rsa_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  on:1;
    };
}cp_k_rsa_security_RBUS;

#else //apply LITTLE_ENDIAN

//======CP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  go:1;
        RBus_UInt32  idle:1;
        RBus_UInt32  swap:1;
        RBus_UInt32  clear:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  arb_mode:1;
        RBus_UInt32  res2:25;
    };
}cp_mcp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_empty:1;
        RBus_UInt32  error:1;
        RBus_UInt32  compare:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  k_ring_empty:1;
        RBus_UInt32  k_compare:1;
        RBus_UInt32  k_error:1;
        RBus_UInt32  res2:22;
    };
}cp_mcp_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_empty_en:1;
        RBus_UInt32  error_en:1;
        RBus_UInt32  compare_en:1;
        RBus_UInt32  res1:28;
    };
}cp_mcp_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcp_round_no:8;
        RBus_UInt32  csa_entropy:2;
        RBus_UInt32  aesh_pad_off:1;
        RBus_UInt32  res1:21;
    };
}cp_mcp_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base:32;
    };
}cp_mcp_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit:32;
    };
}cp_mcp_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rdptr:32;
    };
}cp_mcp_rdptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrptr:32;
    };
}cp_mcp_wrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  count:16;
        RBus_UInt32  res1:16;
    };
}cp_mcp_des_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare:16;
        RBus_UInt32  res1:16;
    };
}cp_mcp_des_compare_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_mcp_des_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_mcp_aes_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_mcp_came_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_mcp_multi2_sys_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  otp_load:1;
        RBus_UInt32  res1:31;
    };
}cp_cp_otp_load_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  go:1;
        RBus_UInt32  idle:1;
        RBus_UInt32  swap:1;
        RBus_UInt32  clear:1;
        RBus_UInt32  res1:27;
    };
}cp_k_mcp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_empty:1;
        RBus_UInt32  error:1;
        RBus_UInt32  compare:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  s_ring_empty:1;
        RBus_UInt32  s_compare:1;
        RBus_UInt32  s_error:1;
        RBus_UInt32  res2:22;
    };
}cp_k_mcp_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_empty_en:1;
        RBus_UInt32  error_en:1;
        RBus_UInt32  compare_en:1;
        RBus_UInt32  res1:28;
    };
}cp_k_mcp_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcp_round_no:8;
        RBus_UInt32  csa_entropy:2;
        RBus_UInt32  aesh_pad_off:1;
        RBus_UInt32  res1:21;
    };
}cp_k_mcp_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base:32;
    };
}cp_k_mcp_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit:32;
    };
}cp_k_mcp_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rdptr:32;
    };
}cp_k_mcp_rdptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrptr:32;
    };
}cp_k_mcp_wrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  count:16;
        RBus_UInt32  res1:16;
    };
}cp_k_mcp_des_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare:16;
        RBus_UInt32  res1:16;
    };
}cp_k_mcp_des_compare_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_mcp_des_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_mcp_aes_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_mcp_came_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_mcp_multi2_sys_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcp_aes_like_sm:11;
        RBus_UInt32  res1:10;
        RBus_UInt32  wr_sm:3;
        RBus_UInt32  rd_sm:4;
        RBus_UInt32  res2:4;
    };
}cp_mcp_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcp_top_sm:18;
        RBus_UInt32  res1:14;
    };
}cp_mcp_st1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  sram_ctr:5;
        RBus_UInt32  res2:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  en_cp:1;
        RBus_UInt32  en_rsa:1;
        RBus_UInt32  res4:8;
    };
}cp_cp_pwm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wait_sec:5;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  test_mode:2;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  stop:1;
        RBus_UInt32  write_en3:1;
        RBus_UInt32  res1:21;
    };
}cp_rcic_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  valid_0:1;
        RBus_UInt32  write_en0:1;
        RBus_UInt32  valid_1:1;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  valid_2:1;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  valid_3:1;
        RBus_UInt32  write_en3:1;
        RBus_UInt32  valid_4:1;
        RBus_UInt32  write_en4:1;
        RBus_UInt32  valid_5:1;
        RBus_UInt32  write_en5:1;
        RBus_UInt32  valid_6:1;
        RBus_UInt32  write_en6:1;
        RBus_UInt32  valid_7:1;
        RBus_UInt32  write_en7:1;
        RBus_UInt32  res1:16;
    };
}cp_rcic_entr_vld_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  done:1;
        RBus_UInt32  entry:3;
        RBus_UInt32  res1:28;
    };
}cp_rcic_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adr:32;
    };
}cp_rcic_entr_src_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adr:32;
    };
}cp_rcic_entr_dst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_en:1;
        RBus_UInt32  res1:31;
    };
}cp_rcic_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  semaphore:1;
        RBus_UInt32  res1:31;
    };
}cp_cp_reg_semaphore_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_reg_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_reg_key1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_reg_datain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_reg_dataout_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_reg_iv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_ende:1;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  reg_first:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  bcm:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cw_logic_opsel:2;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  endian_swap:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mode:4;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  res2:14;
    };
}cp_cp_reg_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  output_mode:2;
        RBus_UInt32  input_mode:2;
        RBus_UInt32  iv_mode:2;
        RBus_UInt32  key_mode:2;
        RBus_UInt32  res1:24;
    };
}cp_cp_reg_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iv_entry:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  key_entry:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  input_entry:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  output_entry:7;
        RBus_UInt32  res4:1;
    };
}cp_cp_reg_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg0:16;
        RBus_UInt32  reg1:16;
    };
}cp_cp_sctch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_nf_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_nf_key1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_nf_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel:2;
        RBus_UInt32  cw_entry:7;
        RBus_UInt32  bcm:2;
        RBus_UInt32  key_length:2;
        RBus_UInt32  res1:19;
    };
}cp_cp_nf_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel:1;
        RBus_UInt32  res1:31;
    };
}cp_cp_nf_emmc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_md_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_md_key1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_cp_md_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel:2;
        RBus_UInt32  cw_entry:7;
        RBus_UInt32  bcm:2;
        RBus_UInt32  key_length:2;
        RBus_UInt32  res1:19;
    };
}cp_cp_md_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  semaphore:1;
        RBus_UInt32  res1:31;
    };
}cp_k_cp_reg_semaphore_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_reg_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_reg_key1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_reg_datain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_reg_dataout_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_reg_iv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_ende:1;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  reg_first:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  bcm:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cw_logic_opsel:2;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  endian_swap:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mode:4;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  res2:14;
    };
}cp_k_cp_reg_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  output_mode:2;
        RBus_UInt32  input_mode:2;
        RBus_UInt32  iv_mode:2;
        RBus_UInt32  key_mode:3;
        RBus_UInt32  res1:23;
    };
}cp_k_cp_reg_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iv_entry:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  key_entry:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  input_entry:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  output_entry:7;
        RBus_UInt32  res4:1;
    };
}cp_k_cp_reg_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_nf_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_nf_key1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_nf_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel:2;
        RBus_UInt32  cw_entry:7;
        RBus_UInt32  bcm:2;
        RBus_UInt32  key_length:2;
        RBus_UInt32  res1:19;
    };
}cp_k_cp_nf_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_md_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_md_key1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_k_cp_md_ini_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel:2;
        RBus_UInt32  cw_entry:7;
        RBus_UInt32  bcm:2;
        RBus_UInt32  key_length:2;
        RBus_UInt32  res1:19;
    };
}cp_k_cp_md_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_en:1;
        RBus_UInt32  dbg_sel0:5;
        RBus_UInt32  dbg_sel1:5;
        RBus_UInt32  res1:21;
    };
}cp_cp_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tst_en:1;
        RBus_UInt32  tst_sel0:5;
        RBus_UInt32  tst_sel1:5;
        RBus_UInt32  res1:21;
    };
}cp_cp_tst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_out:32;
    };
}cp_cp_tst2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en:1;
        RBus_UInt32  en2:1;
        RBus_UInt32  res1:30;
    };
}cp_cp_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  done:1;
        RBus_UInt32  done2:1;
        RBus_UInt32  res1:30;
    };
}cp_cp_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fail_group:1;
        RBus_UInt32  res1:31;
    };
}cp_cp_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fail0:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  fail1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  fail2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  fail3:1;
        RBus_UInt32  res4:19;
    };
}cp_cp_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en:1;
        RBus_UInt32  en2:1;
        RBus_UInt32  res1:30;
    };
}cp_cp_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  done:1;
        RBus_UInt32  done2:1;
        RBus_UInt32  res1:30;
    };
}cp_cp_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fail_group:1;
        RBus_UInt32  res1:31;
    };
}cp_cp_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fail0:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  fail1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  fail2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  fail3:1;
        RBus_UInt32  res4:19;
    };
}cp_cp_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en:1;
        RBus_UInt32  en2:1;
        RBus_UInt32  res1:30;
    };
}cp_cp_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag:1;
        RBus_UInt32  flag2:1;
        RBus_UInt32  res1:30;
    };
}cp_cp_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  desc_rm:4;
        RBus_UInt32  desc_rme:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  din0_rm:4;
        RBus_UInt32  din0_rme:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  din1_rm:4;
        RBus_UInt32  din1_rme:1;
        RBus_UInt32  rsa_rm:4;
        RBus_UInt32  rsa_rme:1;
        RBus_UInt32  res3:6;
    };
}cp_cp_sram_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  desc_ls:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  din0_ls:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  din1_ls:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  rsa_ls:1;
        RBus_UInt32  res4:19;
    };
}cp_cp_sram_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  end:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  start:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:15;
    };
}cp_k_cp_scpu_cw_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_illegal_access:1;
        RBus_UInt32  res1:31;
    };
}cp_k_cp_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_illegal_access_en:1;
        RBus_UInt32  res1:31;
    };
}cp_k_cp_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_rsa_x_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_rsa_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_rsa_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}cp_rsa_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsa_go:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  ecc_go:1;
        RBus_UInt32  res2:27;
    };
}cp_rsa_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bits_num:6;
        RBus_UInt32  res1:26;
    };
}cp_rsa_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsa_done:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  ecc_done:1;
        RBus_UInt32  res2:27;
    };
}cp_rsa_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsa_clear:1;
        RBus_UInt32  res1:31;
    };
}cp_rsa_clear_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1806e410_31_0:32;
    };
}cp_rsa_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_en:1;
        RBus_UInt32  res1:31;
    };
}cp_s_rsa_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_sel:1;
        RBus_UInt32  res1:31;
    };
}cp_s_rsa_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_st:1;
        RBus_UInt32  res1:31;
    };
}cp_s_rsa_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_en:1;
        RBus_UInt32  res1:31;
    };
}cp_k_rsa_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_sel:1;
        RBus_UInt32  res1:31;
    };
}cp_k_rsa_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_st:1;
        RBus_UInt32  res1:31;
    };
}cp_k_rsa_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on:1;
        RBus_UInt32  res1:31;
    };
}cp_k_rsa_security_RBUS;




#endif 


#endif 
