/**
* @file rbusISO_I2C5Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ISO_I2C5_REG_H_
#define _RBUS_ISO_I2C5_REG_H_

#include "rbus_types.h"



//  ISO_I2C5 Register Address
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL                                            0x18062700
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_reg_addr                                   "0xB8062700"
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_reg                                        0xB8062700
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_inst_addr                                  "0x0000"
#define  set_ISO_I2C5_I2C5_GPIO_MODE_CTRL_reg(data)                              (*((volatile unsigned int*)ISO_I2C5_I2C5_GPIO_MODE_CTRL_reg)=data)
#define  get_ISO_I2C5_I2C5_GPIO_MODE_CTRL_reg                                    (*((volatile unsigned int*)ISO_I2C5_I2C5_GPIO_MODE_CTRL_reg))
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_debounce_mode_shift                        (3)
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_ic_gpio_sel_shift                          (2)
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_ic_gpio_sda_shift                          (1)
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_ic_gpio_scl_shift                          (0)
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_debounce_mode_mask                         (0x00000018)
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_ic_gpio_sel_mask                           (0x00000004)
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_ic_gpio_sda_mask                           (0x00000002)
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_ic_gpio_scl_mask                           (0x00000001)
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_debounce_mode(data)                        (0x00000018&((data)<<3))
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_ic_gpio_sel(data)                          (0x00000004&((data)<<2))
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_ic_gpio_sda(data)                          (0x00000002&((data)<<1))
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_ic_gpio_scl(data)                          (0x00000001&(data))
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_get_debounce_mode(data)                    ((0x00000018&(data))>>3)
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_get_ic_gpio_sel(data)                      ((0x00000004&(data))>>2)
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_get_ic_gpio_sda(data)                      ((0x00000002&(data))>>1)
#define  ISO_I2C5_I2C5_GPIO_MODE_CTRL_get_ic_gpio_scl(data)                      (0x00000001&(data))

#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL                                       0x18062704
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_reg_addr                              "0xB8062704"
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_reg                                   0xB8062704
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_inst_addr                             "0x0001"
#define  set_ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_reg(data)                         (*((volatile unsigned int*)ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_reg)=data)
#define  get_ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_reg                               (*((volatile unsigned int*)ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_reg))
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_ic_guard_interval_int_en_shift        (4)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_ic_guard_interval_delay_sel_shift     (1)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_ic_guard_interval_en_shift            (0)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_ic_guard_interval_int_en_mask         (0x00000010)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_ic_guard_interval_delay_sel_mask      (0x0000000E)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_ic_guard_interval_en_mask             (0x00000001)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_ic_guard_interval_int_en(data)        (0x00000010&((data)<<4))
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_ic_guard_interval_delay_sel(data)     (0x0000000E&((data)<<1))
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_ic_guard_interval_en(data)            (0x00000001&(data))
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_get_ic_guard_interval_int_en(data)    ((0x00000010&(data))>>4)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_get_ic_guard_interval_delay_sel(data) ((0x0000000E&(data))>>1)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_CTRL_get_ic_guard_interval_en(data)        (0x00000001&(data))

#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS                                     0x18062708
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_reg_addr                            "0xB8062708"
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_reg                                 0xB8062708
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_inst_addr                           "0x0002"
#define  set_ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_reg(data)                       (*((volatile unsigned int*)ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_reg)=data)
#define  get_ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_reg                             (*((volatile unsigned int*)ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_reg))
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_gpi_ic_gpio_sda_shift               (2)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_gpi_ic_gpio_scl_shift               (1)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_ic_guard_interval_status_shift      (0)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_gpi_ic_gpio_sda_mask                (0x00000004)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_gpi_ic_gpio_scl_mask                (0x00000002)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_ic_guard_interval_status_mask       (0x00000001)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_gpi_ic_gpio_sda(data)               (0x00000004&((data)<<2))
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_gpi_ic_gpio_scl(data)               (0x00000002&((data)<<1))
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_ic_guard_interval_status(data)      (0x00000001&(data))
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_get_gpi_ic_gpio_sda(data)           ((0x00000004&(data))>>2)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_get_gpi_ic_gpio_scl(data)           ((0x00000002&(data))>>1)
#define  ISO_I2C5_I2C6_GUARD_INTERVAL_STATUS_get_ic_guard_interval_status(data)  (0x00000001&(data))

#define  ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL                                     0x1806270C
#define  ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_reg_addr                            "0xB806270C"
#define  ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_reg                                 0xB806270C
#define  ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_inst_addr                           "0x0003"
#define  set_ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_reg(data)                       (*((volatile unsigned int*)ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_reg)=data)
#define  get_ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_reg                             (*((volatile unsigned int*)ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_reg))
#define  ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_databitdelayenable_shift            (15)
#define  ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_databitdelaysel_shift               (0)
#define  ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_databitdelayenable_mask             (0x00008000)
#define  ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_databitdelaysel_mask                (0x000000FF)
#define  ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_databitdelayenable(data)            (0x00008000&((data)<<15))
#define  ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_databitdelaysel(data)               (0x000000FF&(data))
#define  ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_get_databitdelayenable(data)        ((0x00008000&(data))>>15)
#define  ISO_I2C5_I2C5_SDA_OUTPUT_DELAY_CTRL_get_databitdelaysel(data)           (0x000000FF&(data))

#define  ISO_I2C5_IC5_CON                                                        0x18062800
#define  ISO_I2C5_IC5_CON_reg_addr                                               "0xB8062800"
#define  ISO_I2C5_IC5_CON_reg                                                    0xB8062800
#define  ISO_I2C5_IC5_CON_inst_addr                                              "0x0004"
#define  set_ISO_I2C5_IC5_CON_reg(data)                                          (*((volatile unsigned int*)ISO_I2C5_IC5_CON_reg)=data)
#define  get_ISO_I2C5_IC5_CON_reg                                                (*((volatile unsigned int*)ISO_I2C5_IC5_CON_reg))
#define  ISO_I2C5_IC5_CON_ic_slave_disable_shift                                 (6)
#define  ISO_I2C5_IC5_CON_ic_restart_en_shift                                    (5)
#define  ISO_I2C5_IC5_CON_ic_10bitaddr_master_shift                              (4)
#define  ISO_I2C5_IC5_CON_ic_10bitaddr_slave_shift                               (3)
#define  ISO_I2C5_IC5_CON_speed_shift                                            (1)
#define  ISO_I2C5_IC5_CON_master_mode_shift                                      (0)
#define  ISO_I2C5_IC5_CON_ic_slave_disable_mask                                  (0x00000040)
#define  ISO_I2C5_IC5_CON_ic_restart_en_mask                                     (0x00000020)
#define  ISO_I2C5_IC5_CON_ic_10bitaddr_master_mask                               (0x00000010)
#define  ISO_I2C5_IC5_CON_ic_10bitaddr_slave_mask                                (0x00000008)
#define  ISO_I2C5_IC5_CON_speed_mask                                             (0x00000006)
#define  ISO_I2C5_IC5_CON_master_mode_mask                                       (0x00000001)
#define  ISO_I2C5_IC5_CON_ic_slave_disable(data)                                 (0x00000040&((data)<<6))
#define  ISO_I2C5_IC5_CON_ic_restart_en(data)                                    (0x00000020&((data)<<5))
#define  ISO_I2C5_IC5_CON_ic_10bitaddr_master(data)                              (0x00000010&((data)<<4))
#define  ISO_I2C5_IC5_CON_ic_10bitaddr_slave(data)                               (0x00000008&((data)<<3))
#define  ISO_I2C5_IC5_CON_speed(data)                                            (0x00000006&((data)<<1))
#define  ISO_I2C5_IC5_CON_master_mode(data)                                      (0x00000001&(data))
#define  ISO_I2C5_IC5_CON_get_ic_slave_disable(data)                             ((0x00000040&(data))>>6)
#define  ISO_I2C5_IC5_CON_get_ic_restart_en(data)                                ((0x00000020&(data))>>5)
#define  ISO_I2C5_IC5_CON_get_ic_10bitaddr_master(data)                          ((0x00000010&(data))>>4)
#define  ISO_I2C5_IC5_CON_get_ic_10bitaddr_slave(data)                           ((0x00000008&(data))>>3)
#define  ISO_I2C5_IC5_CON_get_speed(data)                                        ((0x00000006&(data))>>1)
#define  ISO_I2C5_IC5_CON_get_master_mode(data)                                  (0x00000001&(data))

#define  ISO_I2C5_IC5_TAR                                                        0x18062804
#define  ISO_I2C5_IC5_TAR_reg_addr                                               "0xB8062804"
#define  ISO_I2C5_IC5_TAR_reg                                                    0xB8062804
#define  ISO_I2C5_IC5_TAR_inst_addr                                              "0x0005"
#define  set_ISO_I2C5_IC5_TAR_reg(data)                                          (*((volatile unsigned int*)ISO_I2C5_IC5_TAR_reg)=data)
#define  get_ISO_I2C5_IC5_TAR_reg                                                (*((volatile unsigned int*)ISO_I2C5_IC5_TAR_reg))
#define  ISO_I2C5_IC5_TAR_ic_10bitaddr_master_shift                              (12)
#define  ISO_I2C5_IC5_TAR_special_shift                                          (11)
#define  ISO_I2C5_IC5_TAR_gc_or_start_shift                                      (10)
#define  ISO_I2C5_IC5_TAR_ic_tar_shift                                           (0)
#define  ISO_I2C5_IC5_TAR_ic_10bitaddr_master_mask                               (0x00001000)
#define  ISO_I2C5_IC5_TAR_special_mask                                           (0x00000800)
#define  ISO_I2C5_IC5_TAR_gc_or_start_mask                                       (0x00000400)
#define  ISO_I2C5_IC5_TAR_ic_tar_mask                                            (0x000003FF)
#define  ISO_I2C5_IC5_TAR_ic_10bitaddr_master(data)                              (0x00001000&((data)<<12))
#define  ISO_I2C5_IC5_TAR_special(data)                                          (0x00000800&((data)<<11))
#define  ISO_I2C5_IC5_TAR_gc_or_start(data)                                      (0x00000400&((data)<<10))
#define  ISO_I2C5_IC5_TAR_ic_tar(data)                                           (0x000003FF&(data))
#define  ISO_I2C5_IC5_TAR_get_ic_10bitaddr_master(data)                          ((0x00001000&(data))>>12)
#define  ISO_I2C5_IC5_TAR_get_special(data)                                      ((0x00000800&(data))>>11)
#define  ISO_I2C5_IC5_TAR_get_gc_or_start(data)                                  ((0x00000400&(data))>>10)
#define  ISO_I2C5_IC5_TAR_get_ic_tar(data)                                       (0x000003FF&(data))

#define  ISO_I2C5_IC5_SAR                                                        0x18062808
#define  ISO_I2C5_IC5_SAR_reg_addr                                               "0xB8062808"
#define  ISO_I2C5_IC5_SAR_reg                                                    0xB8062808
#define  ISO_I2C5_IC5_SAR_inst_addr                                              "0x0006"
#define  set_ISO_I2C5_IC5_SAR_reg(data)                                          (*((volatile unsigned int*)ISO_I2C5_IC5_SAR_reg)=data)
#define  get_ISO_I2C5_IC5_SAR_reg                                                (*((volatile unsigned int*)ISO_I2C5_IC5_SAR_reg))
#define  ISO_I2C5_IC5_SAR_ic_sar_shift                                           (0)
#define  ISO_I2C5_IC5_SAR_ic_sar_mask                                            (0x000003FF)
#define  ISO_I2C5_IC5_SAR_ic_sar(data)                                           (0x000003FF&(data))
#define  ISO_I2C5_IC5_SAR_get_ic_sar(data)                                       (0x000003FF&(data))

#define  ISO_I2C5_IC5_HS_MADDR                                                   0x1806280C
#define  ISO_I2C5_IC5_HS_MADDR_reg_addr                                          "0xB806280C"
#define  ISO_I2C5_IC5_HS_MADDR_reg                                               0xB806280C
#define  ISO_I2C5_IC5_HS_MADDR_inst_addr                                         "0x0007"
#define  set_ISO_I2C5_IC5_HS_MADDR_reg(data)                                     (*((volatile unsigned int*)ISO_I2C5_IC5_HS_MADDR_reg)=data)
#define  get_ISO_I2C5_IC5_HS_MADDR_reg                                           (*((volatile unsigned int*)ISO_I2C5_IC5_HS_MADDR_reg))
#define  ISO_I2C5_IC5_HS_MADDR_ic_hs_mar_shift                                   (0)
#define  ISO_I2C5_IC5_HS_MADDR_ic_hs_mar_mask                                    (0x00000007)
#define  ISO_I2C5_IC5_HS_MADDR_ic_hs_mar(data)                                   (0x00000007&(data))
#define  ISO_I2C5_IC5_HS_MADDR_get_ic_hs_mar(data)                               (0x00000007&(data))

#define  ISO_I2C5_IC5_DATA_CMD                                                   0x18062810
#define  ISO_I2C5_IC5_DATA_CMD_reg_addr                                          "0xB8062810"
#define  ISO_I2C5_IC5_DATA_CMD_reg                                               0xB8062810
#define  ISO_I2C5_IC5_DATA_CMD_inst_addr                                         "0x0008"
#define  set_ISO_I2C5_IC5_DATA_CMD_reg(data)                                     (*((volatile unsigned int*)ISO_I2C5_IC5_DATA_CMD_reg)=data)
#define  get_ISO_I2C5_IC5_DATA_CMD_reg                                           (*((volatile unsigned int*)ISO_I2C5_IC5_DATA_CMD_reg))
#define  ISO_I2C5_IC5_DATA_CMD_restart_shift                                     (10)
#define  ISO_I2C5_IC5_DATA_CMD_stop_shift                                        (9)
#define  ISO_I2C5_IC5_DATA_CMD_cmd_shift                                         (8)
#define  ISO_I2C5_IC5_DATA_CMD_dat_shift                                         (0)
#define  ISO_I2C5_IC5_DATA_CMD_restart_mask                                      (0x00000400)
#define  ISO_I2C5_IC5_DATA_CMD_stop_mask                                         (0x00000200)
#define  ISO_I2C5_IC5_DATA_CMD_cmd_mask                                          (0x00000100)
#define  ISO_I2C5_IC5_DATA_CMD_dat_mask                                          (0x000000FF)
#define  ISO_I2C5_IC5_DATA_CMD_restart(data)                                     (0x00000400&((data)<<10))
#define  ISO_I2C5_IC5_DATA_CMD_stop(data)                                        (0x00000200&((data)<<9))
#define  ISO_I2C5_IC5_DATA_CMD_cmd(data)                                         (0x00000100&((data)<<8))
#define  ISO_I2C5_IC5_DATA_CMD_dat(data)                                         (0x000000FF&(data))
#define  ISO_I2C5_IC5_DATA_CMD_get_restart(data)                                 ((0x00000400&(data))>>10)
#define  ISO_I2C5_IC5_DATA_CMD_get_stop(data)                                    ((0x00000200&(data))>>9)
#define  ISO_I2C5_IC5_DATA_CMD_get_cmd(data)                                     ((0x00000100&(data))>>8)
#define  ISO_I2C5_IC5_DATA_CMD_get_dat(data)                                     (0x000000FF&(data))

#define  ISO_I2C5_IC5_SS_SCL_HCNT                                                0x18062814
#define  ISO_I2C5_IC5_SS_SCL_HCNT_reg_addr                                       "0xB8062814"
#define  ISO_I2C5_IC5_SS_SCL_HCNT_reg                                            0xB8062814
#define  ISO_I2C5_IC5_SS_SCL_HCNT_inst_addr                                      "0x0009"
#define  set_ISO_I2C5_IC5_SS_SCL_HCNT_reg(data)                                  (*((volatile unsigned int*)ISO_I2C5_IC5_SS_SCL_HCNT_reg)=data)
#define  get_ISO_I2C5_IC5_SS_SCL_HCNT_reg                                        (*((volatile unsigned int*)ISO_I2C5_IC5_SS_SCL_HCNT_reg))
#define  ISO_I2C5_IC5_SS_SCL_HCNT_ic_ss_scl_hcnt_shift                           (0)
#define  ISO_I2C5_IC5_SS_SCL_HCNT_ic_ss_scl_hcnt_mask                            (0x0000FFFF)
#define  ISO_I2C5_IC5_SS_SCL_HCNT_ic_ss_scl_hcnt(data)                           (0x0000FFFF&(data))
#define  ISO_I2C5_IC5_SS_SCL_HCNT_get_ic_ss_scl_hcnt(data)                       (0x0000FFFF&(data))

#define  ISO_I2C5_IC5_SS_SCL_LCNT                                                0x18062818
#define  ISO_I2C5_IC5_SS_SCL_LCNT_reg_addr                                       "0xB8062818"
#define  ISO_I2C5_IC5_SS_SCL_LCNT_reg                                            0xB8062818
#define  ISO_I2C5_IC5_SS_SCL_LCNT_inst_addr                                      "0x000A"
#define  set_ISO_I2C5_IC5_SS_SCL_LCNT_reg(data)                                  (*((volatile unsigned int*)ISO_I2C5_IC5_SS_SCL_LCNT_reg)=data)
#define  get_ISO_I2C5_IC5_SS_SCL_LCNT_reg                                        (*((volatile unsigned int*)ISO_I2C5_IC5_SS_SCL_LCNT_reg))
#define  ISO_I2C5_IC5_SS_SCL_LCNT_ic_ss_scl_lcnt_shift                           (0)
#define  ISO_I2C5_IC5_SS_SCL_LCNT_ic_ss_scl_lcnt_mask                            (0x0000FFFF)
#define  ISO_I2C5_IC5_SS_SCL_LCNT_ic_ss_scl_lcnt(data)                           (0x0000FFFF&(data))
#define  ISO_I2C5_IC5_SS_SCL_LCNT_get_ic_ss_scl_lcnt(data)                       (0x0000FFFF&(data))

#define  ISO_I2C5_IC5_FS_SCL_HCNT                                                0x1806281C
#define  ISO_I2C5_IC5_FS_SCL_HCNT_reg_addr                                       "0xB806281C"
#define  ISO_I2C5_IC5_FS_SCL_HCNT_reg                                            0xB806281C
#define  ISO_I2C5_IC5_FS_SCL_HCNT_inst_addr                                      "0x000B"
#define  set_ISO_I2C5_IC5_FS_SCL_HCNT_reg(data)                                  (*((volatile unsigned int*)ISO_I2C5_IC5_FS_SCL_HCNT_reg)=data)
#define  get_ISO_I2C5_IC5_FS_SCL_HCNT_reg                                        (*((volatile unsigned int*)ISO_I2C5_IC5_FS_SCL_HCNT_reg))
#define  ISO_I2C5_IC5_FS_SCL_HCNT_ic_fs_scl_hcnt_shift                           (0)
#define  ISO_I2C5_IC5_FS_SCL_HCNT_ic_fs_scl_hcnt_mask                            (0x0000FFFF)
#define  ISO_I2C5_IC5_FS_SCL_HCNT_ic_fs_scl_hcnt(data)                           (0x0000FFFF&(data))
#define  ISO_I2C5_IC5_FS_SCL_HCNT_get_ic_fs_scl_hcnt(data)                       (0x0000FFFF&(data))

#define  ISO_I2C5_IC5_FS_SCL_LCNT                                                0x18062820
#define  ISO_I2C5_IC5_FS_SCL_LCNT_reg_addr                                       "0xB8062820"
#define  ISO_I2C5_IC5_FS_SCL_LCNT_reg                                            0xB8062820
#define  ISO_I2C5_IC5_FS_SCL_LCNT_inst_addr                                      "0x000C"
#define  set_ISO_I2C5_IC5_FS_SCL_LCNT_reg(data)                                  (*((volatile unsigned int*)ISO_I2C5_IC5_FS_SCL_LCNT_reg)=data)
#define  get_ISO_I2C5_IC5_FS_SCL_LCNT_reg                                        (*((volatile unsigned int*)ISO_I2C5_IC5_FS_SCL_LCNT_reg))
#define  ISO_I2C5_IC5_FS_SCL_LCNT_ic_fs_scl_lcnt_shift                           (0)
#define  ISO_I2C5_IC5_FS_SCL_LCNT_ic_fs_scl_lcnt_mask                            (0x0000FFFF)
#define  ISO_I2C5_IC5_FS_SCL_LCNT_ic_fs_scl_lcnt(data)                           (0x0000FFFF&(data))
#define  ISO_I2C5_IC5_FS_SCL_LCNT_get_ic_fs_scl_lcnt(data)                       (0x0000FFFF&(data))

#define  ISO_I2C5_IC5_HS_SCL_HCNT                                                0x18062824
#define  ISO_I2C5_IC5_HS_SCL_HCNT_reg_addr                                       "0xB8062824"
#define  ISO_I2C5_IC5_HS_SCL_HCNT_reg                                            0xB8062824
#define  ISO_I2C5_IC5_HS_SCL_HCNT_inst_addr                                      "0x000D"
#define  set_ISO_I2C5_IC5_HS_SCL_HCNT_reg(data)                                  (*((volatile unsigned int*)ISO_I2C5_IC5_HS_SCL_HCNT_reg)=data)
#define  get_ISO_I2C5_IC5_HS_SCL_HCNT_reg                                        (*((volatile unsigned int*)ISO_I2C5_IC5_HS_SCL_HCNT_reg))
#define  ISO_I2C5_IC5_HS_SCL_HCNT_ic_hs_scl_hcnt_shift                           (0)
#define  ISO_I2C5_IC5_HS_SCL_HCNT_ic_hs_scl_hcnt_mask                            (0x0000FFFF)
#define  ISO_I2C5_IC5_HS_SCL_HCNT_ic_hs_scl_hcnt(data)                           (0x0000FFFF&(data))
#define  ISO_I2C5_IC5_HS_SCL_HCNT_get_ic_hs_scl_hcnt(data)                       (0x0000FFFF&(data))

#define  ISO_I2C5_IC5_HS_SCL_LCNT                                                0x18062828
#define  ISO_I2C5_IC5_HS_SCL_LCNT_reg_addr                                       "0xB8062828"
#define  ISO_I2C5_IC5_HS_SCL_LCNT_reg                                            0xB8062828
#define  ISO_I2C5_IC5_HS_SCL_LCNT_inst_addr                                      "0x000E"
#define  set_ISO_I2C5_IC5_HS_SCL_LCNT_reg(data)                                  (*((volatile unsigned int*)ISO_I2C5_IC5_HS_SCL_LCNT_reg)=data)
#define  get_ISO_I2C5_IC5_HS_SCL_LCNT_reg                                        (*((volatile unsigned int*)ISO_I2C5_IC5_HS_SCL_LCNT_reg))
#define  ISO_I2C5_IC5_HS_SCL_LCNT_ic_ss_scl_lcnt_shift                           (0)
#define  ISO_I2C5_IC5_HS_SCL_LCNT_ic_ss_scl_lcnt_mask                            (0x0000FFFF)
#define  ISO_I2C5_IC5_HS_SCL_LCNT_ic_ss_scl_lcnt(data)                           (0x0000FFFF&(data))
#define  ISO_I2C5_IC5_HS_SCL_LCNT_get_ic_ss_scl_lcnt(data)                       (0x0000FFFF&(data))

#define  ISO_I2C5_IC5_INTR_STAT                                                  0x1806282C
#define  ISO_I2C5_IC5_INTR_STAT_reg_addr                                         "0xB806282C"
#define  ISO_I2C5_IC5_INTR_STAT_reg                                              0xB806282C
#define  ISO_I2C5_IC5_INTR_STAT_inst_addr                                        "0x000F"
#define  set_ISO_I2C5_IC5_INTR_STAT_reg(data)                                    (*((volatile unsigned int*)ISO_I2C5_IC5_INTR_STAT_reg)=data)
#define  get_ISO_I2C5_IC5_INTR_STAT_reg                                          (*((volatile unsigned int*)ISO_I2C5_IC5_INTR_STAT_reg))
#define  ISO_I2C5_IC5_INTR_STAT_r_gen_call_shift                                 (11)
#define  ISO_I2C5_IC5_INTR_STAT_r_start_det_shift                                (10)
#define  ISO_I2C5_IC5_INTR_STAT_r_stop_det_shift                                 (9)
#define  ISO_I2C5_IC5_INTR_STAT_r_activity_shift                                 (8)
#define  ISO_I2C5_IC5_INTR_STAT_r_rx_done_shift                                  (7)
#define  ISO_I2C5_IC5_INTR_STAT_r_tx_abrt_shift                                  (6)
#define  ISO_I2C5_IC5_INTR_STAT_r_rd_req_shift                                   (5)
#define  ISO_I2C5_IC5_INTR_STAT_r_tx_empty_shift                                 (4)
#define  ISO_I2C5_IC5_INTR_STAT_r_tx_over_shift                                  (3)
#define  ISO_I2C5_IC5_INTR_STAT_r_rx_full_shift                                  (2)
#define  ISO_I2C5_IC5_INTR_STAT_r_rx_over_shift                                  (1)
#define  ISO_I2C5_IC5_INTR_STAT_r_rx_under_shift                                 (0)
#define  ISO_I2C5_IC5_INTR_STAT_r_gen_call_mask                                  (0x00000800)
#define  ISO_I2C5_IC5_INTR_STAT_r_start_det_mask                                 (0x00000400)
#define  ISO_I2C5_IC5_INTR_STAT_r_stop_det_mask                                  (0x00000200)
#define  ISO_I2C5_IC5_INTR_STAT_r_activity_mask                                  (0x00000100)
#define  ISO_I2C5_IC5_INTR_STAT_r_rx_done_mask                                   (0x00000080)
#define  ISO_I2C5_IC5_INTR_STAT_r_tx_abrt_mask                                   (0x00000040)
#define  ISO_I2C5_IC5_INTR_STAT_r_rd_req_mask                                    (0x00000020)
#define  ISO_I2C5_IC5_INTR_STAT_r_tx_empty_mask                                  (0x00000010)
#define  ISO_I2C5_IC5_INTR_STAT_r_tx_over_mask                                   (0x00000008)
#define  ISO_I2C5_IC5_INTR_STAT_r_rx_full_mask                                   (0x00000004)
#define  ISO_I2C5_IC5_INTR_STAT_r_rx_over_mask                                   (0x00000002)
#define  ISO_I2C5_IC5_INTR_STAT_r_rx_under_mask                                  (0x00000001)
#define  ISO_I2C5_IC5_INTR_STAT_r_gen_call(data)                                 (0x00000800&((data)<<11))
#define  ISO_I2C5_IC5_INTR_STAT_r_start_det(data)                                (0x00000400&((data)<<10))
#define  ISO_I2C5_IC5_INTR_STAT_r_stop_det(data)                                 (0x00000200&((data)<<9))
#define  ISO_I2C5_IC5_INTR_STAT_r_activity(data)                                 (0x00000100&((data)<<8))
#define  ISO_I2C5_IC5_INTR_STAT_r_rx_done(data)                                  (0x00000080&((data)<<7))
#define  ISO_I2C5_IC5_INTR_STAT_r_tx_abrt(data)                                  (0x00000040&((data)<<6))
#define  ISO_I2C5_IC5_INTR_STAT_r_rd_req(data)                                   (0x00000020&((data)<<5))
#define  ISO_I2C5_IC5_INTR_STAT_r_tx_empty(data)                                 (0x00000010&((data)<<4))
#define  ISO_I2C5_IC5_INTR_STAT_r_tx_over(data)                                  (0x00000008&((data)<<3))
#define  ISO_I2C5_IC5_INTR_STAT_r_rx_full(data)                                  (0x00000004&((data)<<2))
#define  ISO_I2C5_IC5_INTR_STAT_r_rx_over(data)                                  (0x00000002&((data)<<1))
#define  ISO_I2C5_IC5_INTR_STAT_r_rx_under(data)                                 (0x00000001&(data))
#define  ISO_I2C5_IC5_INTR_STAT_get_r_gen_call(data)                             ((0x00000800&(data))>>11)
#define  ISO_I2C5_IC5_INTR_STAT_get_r_start_det(data)                            ((0x00000400&(data))>>10)
#define  ISO_I2C5_IC5_INTR_STAT_get_r_stop_det(data)                             ((0x00000200&(data))>>9)
#define  ISO_I2C5_IC5_INTR_STAT_get_r_activity(data)                             ((0x00000100&(data))>>8)
#define  ISO_I2C5_IC5_INTR_STAT_get_r_rx_done(data)                              ((0x00000080&(data))>>7)
#define  ISO_I2C5_IC5_INTR_STAT_get_r_tx_abrt(data)                              ((0x00000040&(data))>>6)
#define  ISO_I2C5_IC5_INTR_STAT_get_r_rd_req(data)                               ((0x00000020&(data))>>5)
#define  ISO_I2C5_IC5_INTR_STAT_get_r_tx_empty(data)                             ((0x00000010&(data))>>4)
#define  ISO_I2C5_IC5_INTR_STAT_get_r_tx_over(data)                              ((0x00000008&(data))>>3)
#define  ISO_I2C5_IC5_INTR_STAT_get_r_rx_full(data)                              ((0x00000004&(data))>>2)
#define  ISO_I2C5_IC5_INTR_STAT_get_r_rx_over(data)                              ((0x00000002&(data))>>1)
#define  ISO_I2C5_IC5_INTR_STAT_get_r_rx_under(data)                             (0x00000001&(data))

#define  ISO_I2C5_IC5_INTR_MASK                                                  0x18062830
#define  ISO_I2C5_IC5_INTR_MASK_reg_addr                                         "0xB8062830"
#define  ISO_I2C5_IC5_INTR_MASK_reg                                              0xB8062830
#define  ISO_I2C5_IC5_INTR_MASK_inst_addr                                        "0x0010"
#define  set_ISO_I2C5_IC5_INTR_MASK_reg(data)                                    (*((volatile unsigned int*)ISO_I2C5_IC5_INTR_MASK_reg)=data)
#define  get_ISO_I2C5_IC5_INTR_MASK_reg                                          (*((volatile unsigned int*)ISO_I2C5_IC5_INTR_MASK_reg))
#define  ISO_I2C5_IC5_INTR_MASK_m_gen_call_shift                                 (11)
#define  ISO_I2C5_IC5_INTR_MASK_m_start_det_shift                                (10)
#define  ISO_I2C5_IC5_INTR_MASK_m_stop_det_shift                                 (9)
#define  ISO_I2C5_IC5_INTR_MASK_m_activity_shift                                 (8)
#define  ISO_I2C5_IC5_INTR_MASK_m_rx_done_shift                                  (7)
#define  ISO_I2C5_IC5_INTR_MASK_m_tx_abrt_shift                                  (6)
#define  ISO_I2C5_IC5_INTR_MASK_m_rd_req_shift                                   (5)
#define  ISO_I2C5_IC5_INTR_MASK_m_tx_empty_shift                                 (4)
#define  ISO_I2C5_IC5_INTR_MASK_m_tx_over_shift                                  (3)
#define  ISO_I2C5_IC5_INTR_MASK_m_rx_full_shift                                  (2)
#define  ISO_I2C5_IC5_INTR_MASK_m_rx_over_shift                                  (1)
#define  ISO_I2C5_IC5_INTR_MASK_m_rx_under_shift                                 (0)
#define  ISO_I2C5_IC5_INTR_MASK_m_gen_call_mask                                  (0x00000800)
#define  ISO_I2C5_IC5_INTR_MASK_m_start_det_mask                                 (0x00000400)
#define  ISO_I2C5_IC5_INTR_MASK_m_stop_det_mask                                  (0x00000200)
#define  ISO_I2C5_IC5_INTR_MASK_m_activity_mask                                  (0x00000100)
#define  ISO_I2C5_IC5_INTR_MASK_m_rx_done_mask                                   (0x00000080)
#define  ISO_I2C5_IC5_INTR_MASK_m_tx_abrt_mask                                   (0x00000040)
#define  ISO_I2C5_IC5_INTR_MASK_m_rd_req_mask                                    (0x00000020)
#define  ISO_I2C5_IC5_INTR_MASK_m_tx_empty_mask                                  (0x00000010)
#define  ISO_I2C5_IC5_INTR_MASK_m_tx_over_mask                                   (0x00000008)
#define  ISO_I2C5_IC5_INTR_MASK_m_rx_full_mask                                   (0x00000004)
#define  ISO_I2C5_IC5_INTR_MASK_m_rx_over_mask                                   (0x00000002)
#define  ISO_I2C5_IC5_INTR_MASK_m_rx_under_mask                                  (0x00000001)
#define  ISO_I2C5_IC5_INTR_MASK_m_gen_call(data)                                 (0x00000800&((data)<<11))
#define  ISO_I2C5_IC5_INTR_MASK_m_start_det(data)                                (0x00000400&((data)<<10))
#define  ISO_I2C5_IC5_INTR_MASK_m_stop_det(data)                                 (0x00000200&((data)<<9))
#define  ISO_I2C5_IC5_INTR_MASK_m_activity(data)                                 (0x00000100&((data)<<8))
#define  ISO_I2C5_IC5_INTR_MASK_m_rx_done(data)                                  (0x00000080&((data)<<7))
#define  ISO_I2C5_IC5_INTR_MASK_m_tx_abrt(data)                                  (0x00000040&((data)<<6))
#define  ISO_I2C5_IC5_INTR_MASK_m_rd_req(data)                                   (0x00000020&((data)<<5))
#define  ISO_I2C5_IC5_INTR_MASK_m_tx_empty(data)                                 (0x00000010&((data)<<4))
#define  ISO_I2C5_IC5_INTR_MASK_m_tx_over(data)                                  (0x00000008&((data)<<3))
#define  ISO_I2C5_IC5_INTR_MASK_m_rx_full(data)                                  (0x00000004&((data)<<2))
#define  ISO_I2C5_IC5_INTR_MASK_m_rx_over(data)                                  (0x00000002&((data)<<1))
#define  ISO_I2C5_IC5_INTR_MASK_m_rx_under(data)                                 (0x00000001&(data))
#define  ISO_I2C5_IC5_INTR_MASK_get_m_gen_call(data)                             ((0x00000800&(data))>>11)
#define  ISO_I2C5_IC5_INTR_MASK_get_m_start_det(data)                            ((0x00000400&(data))>>10)
#define  ISO_I2C5_IC5_INTR_MASK_get_m_stop_det(data)                             ((0x00000200&(data))>>9)
#define  ISO_I2C5_IC5_INTR_MASK_get_m_activity(data)                             ((0x00000100&(data))>>8)
#define  ISO_I2C5_IC5_INTR_MASK_get_m_rx_done(data)                              ((0x00000080&(data))>>7)
#define  ISO_I2C5_IC5_INTR_MASK_get_m_tx_abrt(data)                              ((0x00000040&(data))>>6)
#define  ISO_I2C5_IC5_INTR_MASK_get_m_rd_req(data)                               ((0x00000020&(data))>>5)
#define  ISO_I2C5_IC5_INTR_MASK_get_m_tx_empty(data)                             ((0x00000010&(data))>>4)
#define  ISO_I2C5_IC5_INTR_MASK_get_m_tx_over(data)                              ((0x00000008&(data))>>3)
#define  ISO_I2C5_IC5_INTR_MASK_get_m_rx_full(data)                              ((0x00000004&(data))>>2)
#define  ISO_I2C5_IC5_INTR_MASK_get_m_rx_over(data)                              ((0x00000002&(data))>>1)
#define  ISO_I2C5_IC5_INTR_MASK_get_m_rx_under(data)                             (0x00000001&(data))

#define  ISO_I2C5_IC5_RAW_INTR_STAT                                              0x18062834
#define  ISO_I2C5_IC5_RAW_INTR_STAT_reg_addr                                     "0xB8062834"
#define  ISO_I2C5_IC5_RAW_INTR_STAT_reg                                          0xB8062834
#define  ISO_I2C5_IC5_RAW_INTR_STAT_inst_addr                                    "0x0011"
#define  set_ISO_I2C5_IC5_RAW_INTR_STAT_reg(data)                                (*((volatile unsigned int*)ISO_I2C5_IC5_RAW_INTR_STAT_reg)=data)
#define  get_ISO_I2C5_IC5_RAW_INTR_STAT_reg                                      (*((volatile unsigned int*)ISO_I2C5_IC5_RAW_INTR_STAT_reg))
#define  ISO_I2C5_IC5_RAW_INTR_STAT_gen_call_shift                               (11)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_start_det_shift                              (10)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_stop_det_shift                               (9)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_activity_shift                               (8)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rx_done_shift                                (7)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_tx_abrt_shift                                (6)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rd_req_shift                                 (5)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_tx_empty_shift                               (4)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_tx_over_shift                                (3)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rx_full_shift                                (2)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rx_over_shift                                (1)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rx_under_shift                               (0)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_gen_call_mask                                (0x00000800)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_start_det_mask                               (0x00000400)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_stop_det_mask                                (0x00000200)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_activity_mask                                (0x00000100)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rx_done_mask                                 (0x00000080)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_tx_abrt_mask                                 (0x00000040)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rd_req_mask                                  (0x00000020)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_tx_empty_mask                                (0x00000010)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_tx_over_mask                                 (0x00000008)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rx_full_mask                                 (0x00000004)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rx_over_mask                                 (0x00000002)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rx_under_mask                                (0x00000001)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_gen_call(data)                               (0x00000800&((data)<<11))
#define  ISO_I2C5_IC5_RAW_INTR_STAT_start_det(data)                              (0x00000400&((data)<<10))
#define  ISO_I2C5_IC5_RAW_INTR_STAT_stop_det(data)                               (0x00000200&((data)<<9))
#define  ISO_I2C5_IC5_RAW_INTR_STAT_activity(data)                               (0x00000100&((data)<<8))
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rx_done(data)                                (0x00000080&((data)<<7))
#define  ISO_I2C5_IC5_RAW_INTR_STAT_tx_abrt(data)                                (0x00000040&((data)<<6))
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rd_req(data)                                 (0x00000020&((data)<<5))
#define  ISO_I2C5_IC5_RAW_INTR_STAT_tx_empty(data)                               (0x00000010&((data)<<4))
#define  ISO_I2C5_IC5_RAW_INTR_STAT_tx_over(data)                                (0x00000008&((data)<<3))
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rx_full(data)                                (0x00000004&((data)<<2))
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rx_over(data)                                (0x00000002&((data)<<1))
#define  ISO_I2C5_IC5_RAW_INTR_STAT_rx_under(data)                               (0x00000001&(data))
#define  ISO_I2C5_IC5_RAW_INTR_STAT_get_gen_call(data)                           ((0x00000800&(data))>>11)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_get_start_det(data)                          ((0x00000400&(data))>>10)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_get_stop_det(data)                           ((0x00000200&(data))>>9)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_get_activity(data)                           ((0x00000100&(data))>>8)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_get_rx_done(data)                            ((0x00000080&(data))>>7)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_get_tx_abrt(data)                            ((0x00000040&(data))>>6)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_get_rd_req(data)                             ((0x00000020&(data))>>5)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_get_tx_empty(data)                           ((0x00000010&(data))>>4)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_get_tx_over(data)                            ((0x00000008&(data))>>3)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_get_rx_full(data)                            ((0x00000004&(data))>>2)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_get_rx_over(data)                            ((0x00000002&(data))>>1)
#define  ISO_I2C5_IC5_RAW_INTR_STAT_get_rx_under(data)                           (0x00000001&(data))

#define  ISO_I2C5_IC5_RX_TL                                                      0x18062838
#define  ISO_I2C5_IC5_RX_TL_reg_addr                                             "0xB8062838"
#define  ISO_I2C5_IC5_RX_TL_reg                                                  0xB8062838
#define  ISO_I2C5_IC5_RX_TL_inst_addr                                            "0x0012"
#define  set_ISO_I2C5_IC5_RX_TL_reg(data)                                        (*((volatile unsigned int*)ISO_I2C5_IC5_RX_TL_reg)=data)
#define  get_ISO_I2C5_IC5_RX_TL_reg                                              (*((volatile unsigned int*)ISO_I2C5_IC5_RX_TL_reg))
#define  ISO_I2C5_IC5_RX_TL_rx_tl_shift                                          (0)
#define  ISO_I2C5_IC5_RX_TL_rx_tl_mask                                           (0x000000FF)
#define  ISO_I2C5_IC5_RX_TL_rx_tl(data)                                          (0x000000FF&(data))
#define  ISO_I2C5_IC5_RX_TL_get_rx_tl(data)                                      (0x000000FF&(data))

#define  ISO_I2C5_IC5_TX_TL                                                      0x1806283C
#define  ISO_I2C5_IC5_TX_TL_reg_addr                                             "0xB806283C"
#define  ISO_I2C5_IC5_TX_TL_reg                                                  0xB806283C
#define  ISO_I2C5_IC5_TX_TL_inst_addr                                            "0x0013"
#define  set_ISO_I2C5_IC5_TX_TL_reg(data)                                        (*((volatile unsigned int*)ISO_I2C5_IC5_TX_TL_reg)=data)
#define  get_ISO_I2C5_IC5_TX_TL_reg                                              (*((volatile unsigned int*)ISO_I2C5_IC5_TX_TL_reg))
#define  ISO_I2C5_IC5_TX_TL_tx_tl_shift                                          (0)
#define  ISO_I2C5_IC5_TX_TL_tx_tl_mask                                           (0x000000FF)
#define  ISO_I2C5_IC5_TX_TL_tx_tl(data)                                          (0x000000FF&(data))
#define  ISO_I2C5_IC5_TX_TL_get_tx_tl(data)                                      (0x000000FF&(data))

#define  ISO_I2C5_IC5_CLR_INTR                                                   0x18062840
#define  ISO_I2C5_IC5_CLR_INTR_reg_addr                                          "0xB8062840"
#define  ISO_I2C5_IC5_CLR_INTR_reg                                               0xB8062840
#define  ISO_I2C5_IC5_CLR_INTR_inst_addr                                         "0x0014"
#define  set_ISO_I2C5_IC5_CLR_INTR_reg(data)                                     (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_INTR_reg)=data)
#define  get_ISO_I2C5_IC5_CLR_INTR_reg                                           (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_INTR_reg))
#define  ISO_I2C5_IC5_CLR_INTR_clr_intr_shift                                    (0)
#define  ISO_I2C5_IC5_CLR_INTR_clr_intr_mask                                     (0x00000001)
#define  ISO_I2C5_IC5_CLR_INTR_clr_intr(data)                                    (0x00000001&(data))
#define  ISO_I2C5_IC5_CLR_INTR_get_clr_intr(data)                                (0x00000001&(data))

#define  ISO_I2C5_IC5_CLR_RX_UNDER                                               0x18062844
#define  ISO_I2C5_IC5_CLR_RX_UNDER_reg_addr                                      "0xB8062844"
#define  ISO_I2C5_IC5_CLR_RX_UNDER_reg                                           0xB8062844
#define  ISO_I2C5_IC5_CLR_RX_UNDER_inst_addr                                     "0x0015"
#define  set_ISO_I2C5_IC5_CLR_RX_UNDER_reg(data)                                 (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_RX_UNDER_reg)=data)
#define  get_ISO_I2C5_IC5_CLR_RX_UNDER_reg                                       (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_RX_UNDER_reg))
#define  ISO_I2C5_IC5_CLR_RX_UNDER_clr_rx_under_shift                            (0)
#define  ISO_I2C5_IC5_CLR_RX_UNDER_clr_rx_under_mask                             (0x00000001)
#define  ISO_I2C5_IC5_CLR_RX_UNDER_clr_rx_under(data)                            (0x00000001&(data))
#define  ISO_I2C5_IC5_CLR_RX_UNDER_get_clr_rx_under(data)                        (0x00000001&(data))

#define  ISO_I2C5_IC5_CLR_RX_OVER                                                0x18062848
#define  ISO_I2C5_IC5_CLR_RX_OVER_reg_addr                                       "0xB8062848"
#define  ISO_I2C5_IC5_CLR_RX_OVER_reg                                            0xB8062848
#define  ISO_I2C5_IC5_CLR_RX_OVER_inst_addr                                      "0x0016"
#define  set_ISO_I2C5_IC5_CLR_RX_OVER_reg(data)                                  (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_RX_OVER_reg)=data)
#define  get_ISO_I2C5_IC5_CLR_RX_OVER_reg                                        (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_RX_OVER_reg))
#define  ISO_I2C5_IC5_CLR_RX_OVER_clr_rx_over_shift                              (0)
#define  ISO_I2C5_IC5_CLR_RX_OVER_clr_rx_over_mask                               (0x00000001)
#define  ISO_I2C5_IC5_CLR_RX_OVER_clr_rx_over(data)                              (0x00000001&(data))
#define  ISO_I2C5_IC5_CLR_RX_OVER_get_clr_rx_over(data)                          (0x00000001&(data))

#define  ISO_I2C5_IC5_CLR_TX_OVER                                                0x1806284C
#define  ISO_I2C5_IC5_CLR_TX_OVER_reg_addr                                       "0xB806284C"
#define  ISO_I2C5_IC5_CLR_TX_OVER_reg                                            0xB806284C
#define  ISO_I2C5_IC5_CLR_TX_OVER_inst_addr                                      "0x0017"
#define  set_ISO_I2C5_IC5_CLR_TX_OVER_reg(data)                                  (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_TX_OVER_reg)=data)
#define  get_ISO_I2C5_IC5_CLR_TX_OVER_reg                                        (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_TX_OVER_reg))
#define  ISO_I2C5_IC5_CLR_TX_OVER_clr_tx_over_shift                              (0)
#define  ISO_I2C5_IC5_CLR_TX_OVER_clr_tx_over_mask                               (0x00000001)
#define  ISO_I2C5_IC5_CLR_TX_OVER_clr_tx_over(data)                              (0x00000001&(data))
#define  ISO_I2C5_IC5_CLR_TX_OVER_get_clr_tx_over(data)                          (0x00000001&(data))

#define  ISO_I2C5_IC5_CLR_RD_REQ                                                 0x18062850
#define  ISO_I2C5_IC5_CLR_RD_REQ_reg_addr                                        "0xB8062850"
#define  ISO_I2C5_IC5_CLR_RD_REQ_reg                                             0xB8062850
#define  ISO_I2C5_IC5_CLR_RD_REQ_inst_addr                                       "0x0018"
#define  set_ISO_I2C5_IC5_CLR_RD_REQ_reg(data)                                   (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_RD_REQ_reg)=data)
#define  get_ISO_I2C5_IC5_CLR_RD_REQ_reg                                         (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_RD_REQ_reg))
#define  ISO_I2C5_IC5_CLR_RD_REQ_clr_rd_req_shift                                (0)
#define  ISO_I2C5_IC5_CLR_RD_REQ_clr_rd_req_mask                                 (0x00000001)
#define  ISO_I2C5_IC5_CLR_RD_REQ_clr_rd_req(data)                                (0x00000001&(data))
#define  ISO_I2C5_IC5_CLR_RD_REQ_get_clr_rd_req(data)                            (0x00000001&(data))

#define  ISO_I2C5_IC5_CLR_TX_ABRT                                                0x18062854
#define  ISO_I2C5_IC5_CLR_TX_ABRT_reg_addr                                       "0xB8062854"
#define  ISO_I2C5_IC5_CLR_TX_ABRT_reg                                            0xB8062854
#define  ISO_I2C5_IC5_CLR_TX_ABRT_inst_addr                                      "0x0019"
#define  set_ISO_I2C5_IC5_CLR_TX_ABRT_reg(data)                                  (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_TX_ABRT_reg)=data)
#define  get_ISO_I2C5_IC5_CLR_TX_ABRT_reg                                        (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_TX_ABRT_reg))
#define  ISO_I2C5_IC5_CLR_TX_ABRT_clr_tx_abrt_shift                              (0)
#define  ISO_I2C5_IC5_CLR_TX_ABRT_clr_tx_abrt_mask                               (0x00000001)
#define  ISO_I2C5_IC5_CLR_TX_ABRT_clr_tx_abrt(data)                              (0x00000001&(data))
#define  ISO_I2C5_IC5_CLR_TX_ABRT_get_clr_tx_abrt(data)                          (0x00000001&(data))

#define  ISO_I2C5_IC5_CLR_RX_DONE                                                0x18062858
#define  ISO_I2C5_IC5_CLR_RX_DONE_reg_addr                                       "0xB8062858"
#define  ISO_I2C5_IC5_CLR_RX_DONE_reg                                            0xB8062858
#define  ISO_I2C5_IC5_CLR_RX_DONE_inst_addr                                      "0x001A"
#define  set_ISO_I2C5_IC5_CLR_RX_DONE_reg(data)                                  (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_RX_DONE_reg)=data)
#define  get_ISO_I2C5_IC5_CLR_RX_DONE_reg                                        (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_RX_DONE_reg))
#define  ISO_I2C5_IC5_CLR_RX_DONE_clr_rx_done_shift                              (0)
#define  ISO_I2C5_IC5_CLR_RX_DONE_clr_rx_done_mask                               (0x00000001)
#define  ISO_I2C5_IC5_CLR_RX_DONE_clr_rx_done(data)                              (0x00000001&(data))
#define  ISO_I2C5_IC5_CLR_RX_DONE_get_clr_rx_done(data)                          (0x00000001&(data))

#define  ISO_I2C5_IC5_CLR_ACTIVITY                                               0x1806285C
#define  ISO_I2C5_IC5_CLR_ACTIVITY_reg_addr                                      "0xB806285C"
#define  ISO_I2C5_IC5_CLR_ACTIVITY_reg                                           0xB806285C
#define  ISO_I2C5_IC5_CLR_ACTIVITY_inst_addr                                     "0x001B"
#define  set_ISO_I2C5_IC5_CLR_ACTIVITY_reg(data)                                 (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_ACTIVITY_reg)=data)
#define  get_ISO_I2C5_IC5_CLR_ACTIVITY_reg                                       (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_ACTIVITY_reg))
#define  ISO_I2C5_IC5_CLR_ACTIVITY_clr_activity_shift                            (0)
#define  ISO_I2C5_IC5_CLR_ACTIVITY_clr_activity_mask                             (0x00000001)
#define  ISO_I2C5_IC5_CLR_ACTIVITY_clr_activity(data)                            (0x00000001&(data))
#define  ISO_I2C5_IC5_CLR_ACTIVITY_get_clr_activity(data)                        (0x00000001&(data))

#define  ISO_I2C5_IC5_CLR_STOP_DET                                               0x18062860
#define  ISO_I2C5_IC5_CLR_STOP_DET_reg_addr                                      "0xB8062860"
#define  ISO_I2C5_IC5_CLR_STOP_DET_reg                                           0xB8062860
#define  ISO_I2C5_IC5_CLR_STOP_DET_inst_addr                                     "0x001C"
#define  set_ISO_I2C5_IC5_CLR_STOP_DET_reg(data)                                 (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_STOP_DET_reg)=data)
#define  get_ISO_I2C5_IC5_CLR_STOP_DET_reg                                       (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_STOP_DET_reg))
#define  ISO_I2C5_IC5_CLR_STOP_DET_clr_stop_det_shift                            (0)
#define  ISO_I2C5_IC5_CLR_STOP_DET_clr_stop_det_mask                             (0x00000001)
#define  ISO_I2C5_IC5_CLR_STOP_DET_clr_stop_det(data)                            (0x00000001&(data))
#define  ISO_I2C5_IC5_CLR_STOP_DET_get_clr_stop_det(data)                        (0x00000001&(data))

#define  ISO_I2C5_IC5_CLR_START_DET                                              0x18062864
#define  ISO_I2C5_IC5_CLR_START_DET_reg_addr                                     "0xB8062864"
#define  ISO_I2C5_IC5_CLR_START_DET_reg                                          0xB8062864
#define  ISO_I2C5_IC5_CLR_START_DET_inst_addr                                    "0x001D"
#define  set_ISO_I2C5_IC5_CLR_START_DET_reg(data)                                (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_START_DET_reg)=data)
#define  get_ISO_I2C5_IC5_CLR_START_DET_reg                                      (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_START_DET_reg))
#define  ISO_I2C5_IC5_CLR_START_DET_clr_start_det_shift                          (0)
#define  ISO_I2C5_IC5_CLR_START_DET_clr_start_det_mask                           (0x00000001)
#define  ISO_I2C5_IC5_CLR_START_DET_clr_start_det(data)                          (0x00000001&(data))
#define  ISO_I2C5_IC5_CLR_START_DET_get_clr_start_det(data)                      (0x00000001&(data))

#define  ISO_I2C5_IC5_CLR_GEN_CALL                                               0x18062868
#define  ISO_I2C5_IC5_CLR_GEN_CALL_reg_addr                                      "0xB8062868"
#define  ISO_I2C5_IC5_CLR_GEN_CALL_reg                                           0xB8062868
#define  ISO_I2C5_IC5_CLR_GEN_CALL_inst_addr                                     "0x001E"
#define  set_ISO_I2C5_IC5_CLR_GEN_CALL_reg(data)                                 (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_GEN_CALL_reg)=data)
#define  get_ISO_I2C5_IC5_CLR_GEN_CALL_reg                                       (*((volatile unsigned int*)ISO_I2C5_IC5_CLR_GEN_CALL_reg))
#define  ISO_I2C5_IC5_CLR_GEN_CALL_clr_gen_call_shift                            (0)
#define  ISO_I2C5_IC5_CLR_GEN_CALL_clr_gen_call_mask                             (0x00000001)
#define  ISO_I2C5_IC5_CLR_GEN_CALL_clr_gen_call(data)                            (0x00000001&(data))
#define  ISO_I2C5_IC5_CLR_GEN_CALL_get_clr_gen_call(data)                        (0x00000001&(data))

#define  ISO_I2C5_IC5_ENABLE                                                     0x1806286C
#define  ISO_I2C5_IC5_ENABLE_reg_addr                                            "0xB806286C"
#define  ISO_I2C5_IC5_ENABLE_reg                                                 0xB806286C
#define  ISO_I2C5_IC5_ENABLE_inst_addr                                           "0x001F"
#define  set_ISO_I2C5_IC5_ENABLE_reg(data)                                       (*((volatile unsigned int*)ISO_I2C5_IC5_ENABLE_reg)=data)
#define  get_ISO_I2C5_IC5_ENABLE_reg                                             (*((volatile unsigned int*)ISO_I2C5_IC5_ENABLE_reg))
#define  ISO_I2C5_IC5_ENABLE_enable_shift                                        (0)
#define  ISO_I2C5_IC5_ENABLE_enable_mask                                         (0x00000001)
#define  ISO_I2C5_IC5_ENABLE_enable(data)                                        (0x00000001&(data))
#define  ISO_I2C5_IC5_ENABLE_get_enable(data)                                    (0x00000001&(data))

#define  ISO_I2C5_IC5_STATUS                                                     0x18062870
#define  ISO_I2C5_IC5_STATUS_reg_addr                                            "0xB8062870"
#define  ISO_I2C5_IC5_STATUS_reg                                                 0xB8062870
#define  ISO_I2C5_IC5_STATUS_inst_addr                                           "0x0020"
#define  set_ISO_I2C5_IC5_STATUS_reg(data)                                       (*((volatile unsigned int*)ISO_I2C5_IC5_STATUS_reg)=data)
#define  get_ISO_I2C5_IC5_STATUS_reg                                             (*((volatile unsigned int*)ISO_I2C5_IC5_STATUS_reg))
#define  ISO_I2C5_IC5_STATUS_slv_activity_shift                                  (6)
#define  ISO_I2C5_IC5_STATUS_mst_activity_shift                                  (5)
#define  ISO_I2C5_IC5_STATUS_rff_shift                                           (4)
#define  ISO_I2C5_IC5_STATUS_rfne_shift                                          (3)
#define  ISO_I2C5_IC5_STATUS_tfe_shift                                           (2)
#define  ISO_I2C5_IC5_STATUS_tfnf_shift                                          (1)
#define  ISO_I2C5_IC5_STATUS_activity_shift                                      (0)
#define  ISO_I2C5_IC5_STATUS_slv_activity_mask                                   (0x00000040)
#define  ISO_I2C5_IC5_STATUS_mst_activity_mask                                   (0x00000020)
#define  ISO_I2C5_IC5_STATUS_rff_mask                                            (0x00000010)
#define  ISO_I2C5_IC5_STATUS_rfne_mask                                           (0x00000008)
#define  ISO_I2C5_IC5_STATUS_tfe_mask                                            (0x00000004)
#define  ISO_I2C5_IC5_STATUS_tfnf_mask                                           (0x00000002)
#define  ISO_I2C5_IC5_STATUS_activity_mask                                       (0x00000001)
#define  ISO_I2C5_IC5_STATUS_slv_activity(data)                                  (0x00000040&((data)<<6))
#define  ISO_I2C5_IC5_STATUS_mst_activity(data)                                  (0x00000020&((data)<<5))
#define  ISO_I2C5_IC5_STATUS_rff(data)                                           (0x00000010&((data)<<4))
#define  ISO_I2C5_IC5_STATUS_rfne(data)                                          (0x00000008&((data)<<3))
#define  ISO_I2C5_IC5_STATUS_tfe(data)                                           (0x00000004&((data)<<2))
#define  ISO_I2C5_IC5_STATUS_tfnf(data)                                          (0x00000002&((data)<<1))
#define  ISO_I2C5_IC5_STATUS_activity(data)                                      (0x00000001&(data))
#define  ISO_I2C5_IC5_STATUS_get_slv_activity(data)                              ((0x00000040&(data))>>6)
#define  ISO_I2C5_IC5_STATUS_get_mst_activity(data)                              ((0x00000020&(data))>>5)
#define  ISO_I2C5_IC5_STATUS_get_rff(data)                                       ((0x00000010&(data))>>4)
#define  ISO_I2C5_IC5_STATUS_get_rfne(data)                                      ((0x00000008&(data))>>3)
#define  ISO_I2C5_IC5_STATUS_get_tfe(data)                                       ((0x00000004&(data))>>2)
#define  ISO_I2C5_IC5_STATUS_get_tfnf(data)                                      ((0x00000002&(data))>>1)
#define  ISO_I2C5_IC5_STATUS_get_activity(data)                                  (0x00000001&(data))

#define  ISO_I2C5_IC5_TXFLR                                                      0x18062874
#define  ISO_I2C5_IC5_TXFLR_reg_addr                                             "0xB8062874"
#define  ISO_I2C5_IC5_TXFLR_reg                                                  0xB8062874
#define  ISO_I2C5_IC5_TXFLR_inst_addr                                            "0x0021"
#define  set_ISO_I2C5_IC5_TXFLR_reg(data)                                        (*((volatile unsigned int*)ISO_I2C5_IC5_TXFLR_reg)=data)
#define  get_ISO_I2C5_IC5_TXFLR_reg                                              (*((volatile unsigned int*)ISO_I2C5_IC5_TXFLR_reg))
#define  ISO_I2C5_IC5_TXFLR_txflr_shift                                          (0)
#define  ISO_I2C5_IC5_TXFLR_txflr_mask                                           (0x0000000F)
#define  ISO_I2C5_IC5_TXFLR_txflr(data)                                          (0x0000000F&(data))
#define  ISO_I2C5_IC5_TXFLR_get_txflr(data)                                      (0x0000000F&(data))

#define  ISO_I2C5_IC5_RXFLR                                                      0x18062878
#define  ISO_I2C5_IC5_RXFLR_reg_addr                                             "0xB8062878"
#define  ISO_I2C5_IC5_RXFLR_reg                                                  0xB8062878
#define  ISO_I2C5_IC5_RXFLR_inst_addr                                            "0x0022"
#define  set_ISO_I2C5_IC5_RXFLR_reg(data)                                        (*((volatile unsigned int*)ISO_I2C5_IC5_RXFLR_reg)=data)
#define  get_ISO_I2C5_IC5_RXFLR_reg                                              (*((volatile unsigned int*)ISO_I2C5_IC5_RXFLR_reg))
#define  ISO_I2C5_IC5_RXFLR_rxflr_shift                                          (0)
#define  ISO_I2C5_IC5_RXFLR_rxflr_mask                                           (0x0000000F)
#define  ISO_I2C5_IC5_RXFLR_rxflr(data)                                          (0x0000000F&(data))
#define  ISO_I2C5_IC5_RXFLR_get_rxflr(data)                                      (0x0000000F&(data))

#define  ISO_I2C5_IC5_SDA_HOLD                                                   0x1806287C
#define  ISO_I2C5_IC5_SDA_HOLD_reg_addr                                          "0xB806287C"
#define  ISO_I2C5_IC5_SDA_HOLD_reg                                               0xB806287C
#define  ISO_I2C5_IC5_SDA_HOLD_inst_addr                                         "0x0023"
#define  set_ISO_I2C5_IC5_SDA_HOLD_reg(data)                                     (*((volatile unsigned int*)ISO_I2C5_IC5_SDA_HOLD_reg)=data)
#define  get_ISO_I2C5_IC5_SDA_HOLD_reg                                           (*((volatile unsigned int*)ISO_I2C5_IC5_SDA_HOLD_reg))
#define  ISO_I2C5_IC5_SDA_HOLD_ic_sda_hold_shift                                 (0)
#define  ISO_I2C5_IC5_SDA_HOLD_ic_sda_hold_mask                                  (0x0000FFFF)
#define  ISO_I2C5_IC5_SDA_HOLD_ic_sda_hold(data)                                 (0x0000FFFF&(data))
#define  ISO_I2C5_IC5_SDA_HOLD_get_ic_sda_hold(data)                             (0x0000FFFF&(data))

#define  ISO_I2C5_IC5_TX_ABRT_SOURCE                                             0x18062880
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_reg_addr                                    "0xB8062880"
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_reg                                         0xB8062880
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_inst_addr                                   "0x0024"
#define  set_ISO_I2C5_IC5_TX_ABRT_SOURCE_reg(data)                               (*((volatile unsigned int*)ISO_I2C5_IC5_TX_ABRT_SOURCE_reg)=data)
#define  get_ISO_I2C5_IC5_TX_ABRT_SOURCE_reg                                     (*((volatile unsigned int*)ISO_I2C5_IC5_TX_ABRT_SOURCE_reg))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_slvrd_intx_shift                       (15)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_slv_arblost_shift                      (14)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_slvflush_txfifo_shift                  (13)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_arb_lost_shift                              (12)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_arb_master_dis_shift                        (11)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_10b_rd_norstrt_shift                   (10)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_sbyte_norstrt_shift                    (9)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_hs_norstrt_shift                       (8)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_sbyte_ackdet_shift                     (7)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_hs_ackdet_shift                        (6)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_gcall_read_shift                       (5)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_gcall_noack_shift                      (4)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_txdata_noack_shift                     (3)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_10addr2_noack_shift                    (2)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_10addr1_noack_shift                    (1)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_7b_addr_noack_shift                    (0)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_slvrd_intx_mask                        (0x00008000)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_slv_arblost_mask                       (0x00004000)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_slvflush_txfifo_mask                   (0x00002000)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_arb_lost_mask                               (0x00001000)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_arb_master_dis_mask                         (0x00000800)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_10b_rd_norstrt_mask                    (0x00000400)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_sbyte_norstrt_mask                     (0x00000200)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_hs_norstrt_mask                        (0x00000100)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_sbyte_ackdet_mask                      (0x00000080)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_hs_ackdet_mask                         (0x00000040)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_gcall_read_mask                        (0x00000020)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_gcall_noack_mask                       (0x00000010)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_txdata_noack_mask                      (0x00000008)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_10addr2_noack_mask                     (0x00000004)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_10addr1_noack_mask                     (0x00000002)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_7b_addr_noack_mask                     (0x00000001)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_slvrd_intx(data)                       (0x00008000&((data)<<15))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_slv_arblost(data)                      (0x00004000&((data)<<14))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_slvflush_txfifo(data)                  (0x00002000&((data)<<13))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_arb_lost(data)                              (0x00001000&((data)<<12))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_arb_master_dis(data)                        (0x00000800&((data)<<11))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_10b_rd_norstrt(data)                   (0x00000400&((data)<<10))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_sbyte_norstrt(data)                    (0x00000200&((data)<<9))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_hs_norstrt(data)                       (0x00000100&((data)<<8))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_sbyte_ackdet(data)                     (0x00000080&((data)<<7))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_hs_ackdet(data)                        (0x00000040&((data)<<6))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_gcall_read(data)                       (0x00000020&((data)<<5))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_gcall_noack(data)                      (0x00000010&((data)<<4))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_txdata_noack(data)                     (0x00000008&((data)<<3))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_10addr2_noack(data)                    (0x00000004&((data)<<2))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_10addr1_noack(data)                    (0x00000002&((data)<<1))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_abrt_7b_addr_noack(data)                    (0x00000001&(data))
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_slvrd_intx(data)                   ((0x00008000&(data))>>15)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_slv_arblost(data)                  ((0x00004000&(data))>>14)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_slvflush_txfifo(data)              ((0x00002000&(data))>>13)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_arb_lost(data)                          ((0x00001000&(data))>>12)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_arb_master_dis(data)                    ((0x00000800&(data))>>11)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_10b_rd_norstrt(data)               ((0x00000400&(data))>>10)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_sbyte_norstrt(data)                ((0x00000200&(data))>>9)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_hs_norstrt(data)                   ((0x00000100&(data))>>8)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_sbyte_ackdet(data)                 ((0x00000080&(data))>>7)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_hs_ackdet(data)                    ((0x00000040&(data))>>6)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_gcall_read(data)                   ((0x00000020&(data))>>5)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_gcall_noack(data)                  ((0x00000010&(data))>>4)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_txdata_noack(data)                 ((0x00000008&(data))>>3)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_10addr2_noack(data)                ((0x00000004&(data))>>2)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_10addr1_noack(data)                ((0x00000002&(data))>>1)
#define  ISO_I2C5_IC5_TX_ABRT_SOURCE_get_abrt_7b_addr_noack(data)                (0x00000001&(data))

#define  ISO_I2C5_IC5_SLV_DATA_NACK_ONLY                                         0x18062884
#define  ISO_I2C5_IC5_SLV_DATA_NACK_ONLY_reg_addr                                "0xB8062884"
#define  ISO_I2C5_IC5_SLV_DATA_NACK_ONLY_reg                                     0xB8062884
#define  ISO_I2C5_IC5_SLV_DATA_NACK_ONLY_inst_addr                               "0x0025"
#define  set_ISO_I2C5_IC5_SLV_DATA_NACK_ONLY_reg(data)                           (*((volatile unsigned int*)ISO_I2C5_IC5_SLV_DATA_NACK_ONLY_reg)=data)
#define  get_ISO_I2C5_IC5_SLV_DATA_NACK_ONLY_reg                                 (*((volatile unsigned int*)ISO_I2C5_IC5_SLV_DATA_NACK_ONLY_reg))
#define  ISO_I2C5_IC5_SLV_DATA_NACK_ONLY_nack_shift                              (0)
#define  ISO_I2C5_IC5_SLV_DATA_NACK_ONLY_nack_mask                               (0x00000001)
#define  ISO_I2C5_IC5_SLV_DATA_NACK_ONLY_nack(data)                              (0x00000001&(data))
#define  ISO_I2C5_IC5_SLV_DATA_NACK_ONLY_get_nack(data)                          (0x00000001&(data))

#define  ISO_I2C5_IC5_SDA_SETUP                                                  0x18062894
#define  ISO_I2C5_IC5_SDA_SETUP_reg_addr                                         "0xB8062894"
#define  ISO_I2C5_IC5_SDA_SETUP_reg                                              0xB8062894
#define  ISO_I2C5_IC5_SDA_SETUP_inst_addr                                        "0x0026"
#define  set_ISO_I2C5_IC5_SDA_SETUP_reg(data)                                    (*((volatile unsigned int*)ISO_I2C5_IC5_SDA_SETUP_reg)=data)
#define  get_ISO_I2C5_IC5_SDA_SETUP_reg                                          (*((volatile unsigned int*)ISO_I2C5_IC5_SDA_SETUP_reg))
#define  ISO_I2C5_IC5_SDA_SETUP_sda_setup_shift                                  (0)
#define  ISO_I2C5_IC5_SDA_SETUP_sda_setup_mask                                   (0x000000FF)
#define  ISO_I2C5_IC5_SDA_SETUP_sda_setup(data)                                  (0x000000FF&(data))
#define  ISO_I2C5_IC5_SDA_SETUP_get_sda_setup(data)                              (0x000000FF&(data))

#define  ISO_I2C5_IC5_ACK_GENERAL_CALL                                           0x18062898
#define  ISO_I2C5_IC5_ACK_GENERAL_CALL_reg_addr                                  "0xB8062898"
#define  ISO_I2C5_IC5_ACK_GENERAL_CALL_reg                                       0xB8062898
#define  ISO_I2C5_IC5_ACK_GENERAL_CALL_inst_addr                                 "0x0027"
#define  set_ISO_I2C5_IC5_ACK_GENERAL_CALL_reg(data)                             (*((volatile unsigned int*)ISO_I2C5_IC5_ACK_GENERAL_CALL_reg)=data)
#define  get_ISO_I2C5_IC5_ACK_GENERAL_CALL_reg                                   (*((volatile unsigned int*)ISO_I2C5_IC5_ACK_GENERAL_CALL_reg))
#define  ISO_I2C5_IC5_ACK_GENERAL_CALL_ack_gen_call_shift                        (0)
#define  ISO_I2C5_IC5_ACK_GENERAL_CALL_ack_gen_call_mask                         (0x00000001)
#define  ISO_I2C5_IC5_ACK_GENERAL_CALL_ack_gen_call(data)                        (0x00000001&(data))
#define  ISO_I2C5_IC5_ACK_GENERAL_CALL_get_ack_gen_call(data)                    (0x00000001&(data))

#define  ISO_I2C5_IC5_ENABLE_STATUS                                              0x1806289C
#define  ISO_I2C5_IC5_ENABLE_STATUS_reg_addr                                     "0xB806289C"
#define  ISO_I2C5_IC5_ENABLE_STATUS_reg                                          0xB806289C
#define  ISO_I2C5_IC5_ENABLE_STATUS_inst_addr                                    "0x0028"
#define  set_ISO_I2C5_IC5_ENABLE_STATUS_reg(data)                                (*((volatile unsigned int*)ISO_I2C5_IC5_ENABLE_STATUS_reg)=data)
#define  get_ISO_I2C5_IC5_ENABLE_STATUS_reg                                      (*((volatile unsigned int*)ISO_I2C5_IC5_ENABLE_STATUS_reg))
#define  ISO_I2C5_IC5_ENABLE_STATUS_slv_rx_data_lost_shift                       (2)
#define  ISO_I2C5_IC5_ENABLE_STATUS_slv_disabled_while_busy_shift                (1)
#define  ISO_I2C5_IC5_ENABLE_STATUS_ic_en_shift                                  (0)
#define  ISO_I2C5_IC5_ENABLE_STATUS_slv_rx_data_lost_mask                        (0x00000004)
#define  ISO_I2C5_IC5_ENABLE_STATUS_slv_disabled_while_busy_mask                 (0x00000002)
#define  ISO_I2C5_IC5_ENABLE_STATUS_ic_en_mask                                   (0x00000001)
#define  ISO_I2C5_IC5_ENABLE_STATUS_slv_rx_data_lost(data)                       (0x00000004&((data)<<2))
#define  ISO_I2C5_IC5_ENABLE_STATUS_slv_disabled_while_busy(data)                (0x00000002&((data)<<1))
#define  ISO_I2C5_IC5_ENABLE_STATUS_ic_en(data)                                  (0x00000001&(data))
#define  ISO_I2C5_IC5_ENABLE_STATUS_get_slv_rx_data_lost(data)                   ((0x00000004&(data))>>2)
#define  ISO_I2C5_IC5_ENABLE_STATUS_get_slv_disabled_while_busy(data)            ((0x00000002&(data))>>1)
#define  ISO_I2C5_IC5_ENABLE_STATUS_get_ic_en(data)                              (0x00000001&(data))

#define  ISO_I2C5_IC5_COMP_PARAM_1                                               0x180628F4
#define  ISO_I2C5_IC5_COMP_PARAM_1_reg_addr                                      "0xB80628F4"
#define  ISO_I2C5_IC5_COMP_PARAM_1_reg                                           0xB80628F4
#define  ISO_I2C5_IC5_COMP_PARAM_1_inst_addr                                     "0x0029"
#define  set_ISO_I2C5_IC5_COMP_PARAM_1_reg(data)                                 (*((volatile unsigned int*)ISO_I2C5_IC5_COMP_PARAM_1_reg)=data)
#define  get_ISO_I2C5_IC5_COMP_PARAM_1_reg                                       (*((volatile unsigned int*)ISO_I2C5_IC5_COMP_PARAM_1_reg))
#define  ISO_I2C5_IC5_COMP_PARAM_1_tx_buffer_depth_shift                         (16)
#define  ISO_I2C5_IC5_COMP_PARAM_1_rx_buffer_depth_shift                         (8)
#define  ISO_I2C5_IC5_COMP_PARAM_1_add_encoded_params_shift                      (7)
#define  ISO_I2C5_IC5_COMP_PARAM_1_has_dma_shift                                 (6)
#define  ISO_I2C5_IC5_COMP_PARAM_1_intr_io_shift                                 (5)
#define  ISO_I2C5_IC5_COMP_PARAM_1_hc_count_values_shift                         (4)
#define  ISO_I2C5_IC5_COMP_PARAM_1_max_speed_mode_shift                          (2)
#define  ISO_I2C5_IC5_COMP_PARAM_1_apb_data_width_shift                          (0)
#define  ISO_I2C5_IC5_COMP_PARAM_1_tx_buffer_depth_mask                          (0x00FF0000)
#define  ISO_I2C5_IC5_COMP_PARAM_1_rx_buffer_depth_mask                          (0x0000FF00)
#define  ISO_I2C5_IC5_COMP_PARAM_1_add_encoded_params_mask                       (0x00000080)
#define  ISO_I2C5_IC5_COMP_PARAM_1_has_dma_mask                                  (0x00000040)
#define  ISO_I2C5_IC5_COMP_PARAM_1_intr_io_mask                                  (0x00000020)
#define  ISO_I2C5_IC5_COMP_PARAM_1_hc_count_values_mask                          (0x00000010)
#define  ISO_I2C5_IC5_COMP_PARAM_1_max_speed_mode_mask                           (0x0000000C)
#define  ISO_I2C5_IC5_COMP_PARAM_1_apb_data_width_mask                           (0x00000003)
#define  ISO_I2C5_IC5_COMP_PARAM_1_tx_buffer_depth(data)                         (0x00FF0000&((data)<<16))
#define  ISO_I2C5_IC5_COMP_PARAM_1_rx_buffer_depth(data)                         (0x0000FF00&((data)<<8))
#define  ISO_I2C5_IC5_COMP_PARAM_1_add_encoded_params(data)                      (0x00000080&((data)<<7))
#define  ISO_I2C5_IC5_COMP_PARAM_1_has_dma(data)                                 (0x00000040&((data)<<6))
#define  ISO_I2C5_IC5_COMP_PARAM_1_intr_io(data)                                 (0x00000020&((data)<<5))
#define  ISO_I2C5_IC5_COMP_PARAM_1_hc_count_values(data)                         (0x00000010&((data)<<4))
#define  ISO_I2C5_IC5_COMP_PARAM_1_max_speed_mode(data)                          (0x0000000C&((data)<<2))
#define  ISO_I2C5_IC5_COMP_PARAM_1_apb_data_width(data)                          (0x00000003&(data))
#define  ISO_I2C5_IC5_COMP_PARAM_1_get_tx_buffer_depth(data)                     ((0x00FF0000&(data))>>16)
#define  ISO_I2C5_IC5_COMP_PARAM_1_get_rx_buffer_depth(data)                     ((0x0000FF00&(data))>>8)
#define  ISO_I2C5_IC5_COMP_PARAM_1_get_add_encoded_params(data)                  ((0x00000080&(data))>>7)
#define  ISO_I2C5_IC5_COMP_PARAM_1_get_has_dma(data)                             ((0x00000040&(data))>>6)
#define  ISO_I2C5_IC5_COMP_PARAM_1_get_intr_io(data)                             ((0x00000020&(data))>>5)
#define  ISO_I2C5_IC5_COMP_PARAM_1_get_hc_count_values(data)                     ((0x00000010&(data))>>4)
#define  ISO_I2C5_IC5_COMP_PARAM_1_get_max_speed_mode(data)                      ((0x0000000C&(data))>>2)
#define  ISO_I2C5_IC5_COMP_PARAM_1_get_apb_data_width(data)                      (0x00000003&(data))

#define  ISO_I2C5_IC5_COMP_VERSION                                               0x180628F8
#define  ISO_I2C5_IC5_COMP_VERSION_reg_addr                                      "0xB80628F8"
#define  ISO_I2C5_IC5_COMP_VERSION_reg                                           0xB80628F8
#define  ISO_I2C5_IC5_COMP_VERSION_inst_addr                                     "0x002A"
#define  set_ISO_I2C5_IC5_COMP_VERSION_reg(data)                                 (*((volatile unsigned int*)ISO_I2C5_IC5_COMP_VERSION_reg)=data)
#define  get_ISO_I2C5_IC5_COMP_VERSION_reg                                       (*((volatile unsigned int*)ISO_I2C5_IC5_COMP_VERSION_reg))
#define  ISO_I2C5_IC5_COMP_VERSION_ic_comp_version_shift                         (0)
#define  ISO_I2C5_IC5_COMP_VERSION_ic_comp_version_mask                          (0xFFFFFFFF)
#define  ISO_I2C5_IC5_COMP_VERSION_ic_comp_version(data)                         (0xFFFFFFFF&(data))
#define  ISO_I2C5_IC5_COMP_VERSION_get_ic_comp_version(data)                     (0xFFFFFFFF&(data))

#define  ISO_I2C5_IC5_COMP_TYPE                                                  0x180628FC
#define  ISO_I2C5_IC5_COMP_TYPE_reg_addr                                         "0xB80628FC"
#define  ISO_I2C5_IC5_COMP_TYPE_reg                                              0xB80628FC
#define  ISO_I2C5_IC5_COMP_TYPE_inst_addr                                        "0x002B"
#define  set_ISO_I2C5_IC5_COMP_TYPE_reg(data)                                    (*((volatile unsigned int*)ISO_I2C5_IC5_COMP_TYPE_reg)=data)
#define  get_ISO_I2C5_IC5_COMP_TYPE_reg                                          (*((volatile unsigned int*)ISO_I2C5_IC5_COMP_TYPE_reg))
#define  ISO_I2C5_IC5_COMP_TYPE_ic_comp_type_shift                               (0)
#define  ISO_I2C5_IC5_COMP_TYPE_ic_comp_type_mask                                (0xFFFFFFFF)
#define  ISO_I2C5_IC5_COMP_TYPE_ic_comp_type(data)                               (0xFFFFFFFF&(data))
#define  ISO_I2C5_IC5_COMP_TYPE_get_ic_comp_type(data)                           (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ISO_I2C5 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  res2:14;
        RBus_UInt32  debounce_mode:2;
        RBus_UInt32  ic_gpio_sel:1;
        RBus_UInt32  ic_gpio_sda:1;
        RBus_UInt32  ic_gpio_scl:1;
    };
}iso_i2c5_i2c5_gpio_mode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  res2:16;
        RBus_UInt32  ic_guard_interval_int_en:1;
        RBus_UInt32  ic_guard_interval_delay_sel:3;
        RBus_UInt32  ic_guard_interval_en:1;
    };
}iso_i2c5_i2c6_guard_interval_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  res2:14;
        RBus_UInt32  gpi_ic_gpio_sda:1;
        RBus_UInt32  gpi_ic_gpio_scl:1;
        RBus_UInt32  ic_guard_interval_status:1;
    };
}iso_i2c5_i2c6_guard_interval_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  res3:8;
        RBus_UInt32  databitdelayenable:1;
        RBus_UInt32  res4:7;
        RBus_UInt32  databitdelaysel:8;
    };
}iso_i2c5_i2c5_sda_output_delay_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ic_slave_disable:1;
        RBus_UInt32  ic_restart_en:1;
        RBus_UInt32  ic_10bitaddr_master:1;
        RBus_UInt32  ic_10bitaddr_slave:1;
        RBus_UInt32  speed:2;
        RBus_UInt32  master_mode:1;
    };
}iso_i2c5_ic5_con_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  ic_10bitaddr_master:1;
        RBus_UInt32  special:1;
        RBus_UInt32  gc_or_start:1;
        RBus_UInt32  ic_tar:10;
    };
}iso_i2c5_ic5_tar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  ic_sar:10;
    };
}iso_i2c5_ic5_sar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ic_hs_mar:3;
    };
}iso_i2c5_ic5_hs_maddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  restart:1;
        RBus_UInt32  stop:1;
        RBus_UInt32  cmd:1;
        RBus_UInt32  dat:8;
    };
}iso_i2c5_ic5_data_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ic_ss_scl_hcnt:16;
    };
}iso_i2c5_ic5_ss_scl_hcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ic_ss_scl_lcnt:16;
    };
}iso_i2c5_ic5_ss_scl_lcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ic_fs_scl_hcnt:16;
    };
}iso_i2c5_ic5_fs_scl_hcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ic_fs_scl_lcnt:16;
    };
}iso_i2c5_ic5_fs_scl_lcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ic_hs_scl_hcnt:16;
    };
}iso_i2c5_ic5_hs_scl_hcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ic_ss_scl_lcnt:16;
    };
}iso_i2c5_ic5_hs_scl_lcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  r_gen_call:1;
        RBus_UInt32  r_start_det:1;
        RBus_UInt32  r_stop_det:1;
        RBus_UInt32  r_activity:1;
        RBus_UInt32  r_rx_done:1;
        RBus_UInt32  r_tx_abrt:1;
        RBus_UInt32  r_rd_req:1;
        RBus_UInt32  r_tx_empty:1;
        RBus_UInt32  r_tx_over:1;
        RBus_UInt32  r_rx_full:1;
        RBus_UInt32  r_rx_over:1;
        RBus_UInt32  r_rx_under:1;
    };
}iso_i2c5_ic5_intr_stat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  m_gen_call:1;
        RBus_UInt32  m_start_det:1;
        RBus_UInt32  m_stop_det:1;
        RBus_UInt32  m_activity:1;
        RBus_UInt32  m_rx_done:1;
        RBus_UInt32  m_tx_abrt:1;
        RBus_UInt32  m_rd_req:1;
        RBus_UInt32  m_tx_empty:1;
        RBus_UInt32  m_tx_over:1;
        RBus_UInt32  m_rx_full:1;
        RBus_UInt32  m_rx_over:1;
        RBus_UInt32  m_rx_under:1;
    };
}iso_i2c5_ic5_intr_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  gen_call:1;
        RBus_UInt32  start_det:1;
        RBus_UInt32  stop_det:1;
        RBus_UInt32  activity:1;
        RBus_UInt32  rx_done:1;
        RBus_UInt32  tx_abrt:1;
        RBus_UInt32  rd_req:1;
        RBus_UInt32  tx_empty:1;
        RBus_UInt32  tx_over:1;
        RBus_UInt32  rx_full:1;
        RBus_UInt32  rx_over:1;
        RBus_UInt32  rx_under:1;
    };
}iso_i2c5_ic5_raw_intr_stat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rx_tl:8;
    };
}iso_i2c5_ic5_rx_tl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tx_tl:8;
    };
}iso_i2c5_ic5_tx_tl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clr_intr:1;
    };
}iso_i2c5_ic5_clr_intr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clr_rx_under:1;
    };
}iso_i2c5_ic5_clr_rx_under_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clr_rx_over:1;
    };
}iso_i2c5_ic5_clr_rx_over_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clr_tx_over:1;
    };
}iso_i2c5_ic5_clr_tx_over_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clr_rd_req:1;
    };
}iso_i2c5_ic5_clr_rd_req_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clr_tx_abrt:1;
    };
}iso_i2c5_ic5_clr_tx_abrt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clr_rx_done:1;
    };
}iso_i2c5_ic5_clr_rx_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clr_activity:1;
    };
}iso_i2c5_ic5_clr_activity_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clr_stop_det:1;
    };
}iso_i2c5_ic5_clr_stop_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clr_start_det:1;
    };
}iso_i2c5_ic5_clr_start_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clr_gen_call:1;
    };
}iso_i2c5_ic5_clr_gen_call_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  enable:1;
    };
}iso_i2c5_ic5_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  slv_activity:1;
        RBus_UInt32  mst_activity:1;
        RBus_UInt32  rff:1;
        RBus_UInt32  rfne:1;
        RBus_UInt32  tfe:1;
        RBus_UInt32  tfnf:1;
        RBus_UInt32  activity:1;
    };
}iso_i2c5_ic5_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  txflr:4;
    };
}iso_i2c5_ic5_txflr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  rxflr:4;
    };
}iso_i2c5_ic5_rxflr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ic_sda_hold:16;
    };
}iso_i2c5_ic5_sda_hold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  abrt_slvrd_intx:1;
        RBus_UInt32  abrt_slv_arblost:1;
        RBus_UInt32  abrt_slvflush_txfifo:1;
        RBus_UInt32  arb_lost:1;
        RBus_UInt32  arb_master_dis:1;
        RBus_UInt32  abrt_10b_rd_norstrt:1;
        RBus_UInt32  abrt_sbyte_norstrt:1;
        RBus_UInt32  abrt_hs_norstrt:1;
        RBus_UInt32  abrt_sbyte_ackdet:1;
        RBus_UInt32  abrt_hs_ackdet:1;
        RBus_UInt32  abrt_gcall_read:1;
        RBus_UInt32  abrt_gcall_noack:1;
        RBus_UInt32  abrt_txdata_noack:1;
        RBus_UInt32  abrt_10addr2_noack:1;
        RBus_UInt32  abrt_10addr1_noack:1;
        RBus_UInt32  abrt_7b_addr_noack:1;
    };
}iso_i2c5_ic5_tx_abrt_source_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  nack:1;
    };
}iso_i2c5_ic5_slv_data_nack_only_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sda_setup:8;
    };
}iso_i2c5_ic5_sda_setup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ack_gen_call:1;
    };
}iso_i2c5_ic5_ack_general_call_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  slv_rx_data_lost:1;
        RBus_UInt32  slv_disabled_while_busy:1;
        RBus_UInt32  ic_en:1;
    };
}iso_i2c5_ic5_enable_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tx_buffer_depth:8;
        RBus_UInt32  rx_buffer_depth:8;
        RBus_UInt32  add_encoded_params:1;
        RBus_UInt32  has_dma:1;
        RBus_UInt32  intr_io:1;
        RBus_UInt32  hc_count_values:1;
        RBus_UInt32  max_speed_mode:2;
        RBus_UInt32  apb_data_width:2;
    };
}iso_i2c5_ic5_comp_param_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_comp_version:32;
    };
}iso_i2c5_ic5_comp_version_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_comp_type:32;
    };
}iso_i2c5_ic5_comp_type_RBUS;

#else //apply LITTLE_ENDIAN

//======ISO_I2C5 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_gpio_scl:1;
        RBus_UInt32  ic_gpio_sda:1;
        RBus_UInt32  ic_gpio_sel:1;
        RBus_UInt32  debounce_mode:2;
        RBus_UInt32  res1:14;
        RBus_UInt32  res2:13;
    };
}iso_i2c5_i2c5_gpio_mode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_guard_interval_en:1;
        RBus_UInt32  ic_guard_interval_delay_sel:3;
        RBus_UInt32  ic_guard_interval_int_en:1;
        RBus_UInt32  res1:16;
        RBus_UInt32  res2:11;
    };
}iso_i2c5_i2c6_guard_interval_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_guard_interval_status:1;
        RBus_UInt32  gpi_ic_gpio_scl:1;
        RBus_UInt32  gpi_ic_gpio_sda:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  res2:15;
    };
}iso_i2c5_i2c6_guard_interval_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  databitdelaysel:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  databitdelayenable:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  res3:7;
        RBus_UInt32  res4:1;
    };
}iso_i2c5_i2c5_sda_output_delay_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  master_mode:1;
        RBus_UInt32  speed:2;
        RBus_UInt32  ic_10bitaddr_slave:1;
        RBus_UInt32  ic_10bitaddr_master:1;
        RBus_UInt32  ic_restart_en:1;
        RBus_UInt32  ic_slave_disable:1;
        RBus_UInt32  res1:25;
    };
}iso_i2c5_ic5_con_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_tar:10;
        RBus_UInt32  gc_or_start:1;
        RBus_UInt32  special:1;
        RBus_UInt32  ic_10bitaddr_master:1;
        RBus_UInt32  res1:19;
    };
}iso_i2c5_ic5_tar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_sar:10;
        RBus_UInt32  res1:22;
    };
}iso_i2c5_ic5_sar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_hs_mar:3;
        RBus_UInt32  res1:29;
    };
}iso_i2c5_ic5_hs_maddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:8;
        RBus_UInt32  cmd:1;
        RBus_UInt32  stop:1;
        RBus_UInt32  restart:1;
        RBus_UInt32  res1:21;
    };
}iso_i2c5_ic5_data_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_ss_scl_hcnt:16;
        RBus_UInt32  res1:16;
    };
}iso_i2c5_ic5_ss_scl_hcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_ss_scl_lcnt:16;
        RBus_UInt32  res1:16;
    };
}iso_i2c5_ic5_ss_scl_lcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_fs_scl_hcnt:16;
        RBus_UInt32  res1:16;
    };
}iso_i2c5_ic5_fs_scl_hcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_fs_scl_lcnt:16;
        RBus_UInt32  res1:16;
    };
}iso_i2c5_ic5_fs_scl_lcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_hs_scl_hcnt:16;
        RBus_UInt32  res1:16;
    };
}iso_i2c5_ic5_hs_scl_hcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_ss_scl_lcnt:16;
        RBus_UInt32  res1:16;
    };
}iso_i2c5_ic5_hs_scl_lcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_rx_under:1;
        RBus_UInt32  r_rx_over:1;
        RBus_UInt32  r_rx_full:1;
        RBus_UInt32  r_tx_over:1;
        RBus_UInt32  r_tx_empty:1;
        RBus_UInt32  r_rd_req:1;
        RBus_UInt32  r_tx_abrt:1;
        RBus_UInt32  r_rx_done:1;
        RBus_UInt32  r_activity:1;
        RBus_UInt32  r_stop_det:1;
        RBus_UInt32  r_start_det:1;
        RBus_UInt32  r_gen_call:1;
        RBus_UInt32  res1:20;
    };
}iso_i2c5_ic5_intr_stat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_rx_under:1;
        RBus_UInt32  m_rx_over:1;
        RBus_UInt32  m_rx_full:1;
        RBus_UInt32  m_tx_over:1;
        RBus_UInt32  m_tx_empty:1;
        RBus_UInt32  m_rd_req:1;
        RBus_UInt32  m_tx_abrt:1;
        RBus_UInt32  m_rx_done:1;
        RBus_UInt32  m_activity:1;
        RBus_UInt32  m_stop_det:1;
        RBus_UInt32  m_start_det:1;
        RBus_UInt32  m_gen_call:1;
        RBus_UInt32  res1:20;
    };
}iso_i2c5_ic5_intr_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_under:1;
        RBus_UInt32  rx_over:1;
        RBus_UInt32  rx_full:1;
        RBus_UInt32  tx_over:1;
        RBus_UInt32  tx_empty:1;
        RBus_UInt32  rd_req:1;
        RBus_UInt32  tx_abrt:1;
        RBus_UInt32  rx_done:1;
        RBus_UInt32  activity:1;
        RBus_UInt32  stop_det:1;
        RBus_UInt32  start_det:1;
        RBus_UInt32  gen_call:1;
        RBus_UInt32  res1:20;
    };
}iso_i2c5_ic5_raw_intr_stat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_tl:8;
        RBus_UInt32  res1:24;
    };
}iso_i2c5_ic5_rx_tl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_tl:8;
        RBus_UInt32  res1:24;
    };
}iso_i2c5_ic5_tx_tl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clr_intr:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_clr_intr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clr_rx_under:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_clr_rx_under_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clr_rx_over:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_clr_rx_over_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clr_tx_over:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_clr_tx_over_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clr_rd_req:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_clr_rd_req_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clr_tx_abrt:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_clr_tx_abrt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clr_rx_done:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_clr_rx_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clr_activity:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_clr_activity_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clr_stop_det:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_clr_stop_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clr_start_det:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_clr_start_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clr_gen_call:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_clr_gen_call_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  activity:1;
        RBus_UInt32  tfnf:1;
        RBus_UInt32  tfe:1;
        RBus_UInt32  rfne:1;
        RBus_UInt32  rff:1;
        RBus_UInt32  mst_activity:1;
        RBus_UInt32  slv_activity:1;
        RBus_UInt32  res1:25;
    };
}iso_i2c5_ic5_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txflr:4;
        RBus_UInt32  res1:28;
    };
}iso_i2c5_ic5_txflr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxflr:4;
        RBus_UInt32  res1:28;
    };
}iso_i2c5_ic5_rxflr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_sda_hold:16;
        RBus_UInt32  res1:16;
    };
}iso_i2c5_ic5_sda_hold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abrt_7b_addr_noack:1;
        RBus_UInt32  abrt_10addr1_noack:1;
        RBus_UInt32  abrt_10addr2_noack:1;
        RBus_UInt32  abrt_txdata_noack:1;
        RBus_UInt32  abrt_gcall_noack:1;
        RBus_UInt32  abrt_gcall_read:1;
        RBus_UInt32  abrt_hs_ackdet:1;
        RBus_UInt32  abrt_sbyte_ackdet:1;
        RBus_UInt32  abrt_hs_norstrt:1;
        RBus_UInt32  abrt_sbyte_norstrt:1;
        RBus_UInt32  abrt_10b_rd_norstrt:1;
        RBus_UInt32  arb_master_dis:1;
        RBus_UInt32  arb_lost:1;
        RBus_UInt32  abrt_slvflush_txfifo:1;
        RBus_UInt32  abrt_slv_arblost:1;
        RBus_UInt32  abrt_slvrd_intx:1;
        RBus_UInt32  res1:16;
    };
}iso_i2c5_ic5_tx_abrt_source_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nack:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_slv_data_nack_only_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sda_setup:8;
        RBus_UInt32  res1:24;
    };
}iso_i2c5_ic5_sda_setup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ack_gen_call:1;
        RBus_UInt32  res1:31;
    };
}iso_i2c5_ic5_ack_general_call_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_en:1;
        RBus_UInt32  slv_disabled_while_busy:1;
        RBus_UInt32  slv_rx_data_lost:1;
        RBus_UInt32  res1:29;
    };
}iso_i2c5_ic5_enable_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apb_data_width:2;
        RBus_UInt32  max_speed_mode:2;
        RBus_UInt32  hc_count_values:1;
        RBus_UInt32  intr_io:1;
        RBus_UInt32  has_dma:1;
        RBus_UInt32  add_encoded_params:1;
        RBus_UInt32  rx_buffer_depth:8;
        RBus_UInt32  tx_buffer_depth:8;
        RBus_UInt32  res1:8;
    };
}iso_i2c5_ic5_comp_param_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_comp_version:32;
    };
}iso_i2c5_ic5_comp_version_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_comp_type:32;
    };
}iso_i2c5_ic5_comp_type_RBUS;




#endif 


#endif 
