/**
* @file rbusISO_MISC_DDC4Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ISO_MISC_DDC4_REG_H_
#define _RBUS_ISO_MISC_DDC4_REG_H_

#include "rbus_types.h"



//  ISO_MISC_DDC4 Register Address
#define  ISO_MISC_DDC4_I2C_CR                                                    0x18061300
#define  ISO_MISC_DDC4_I2C_CR_reg_addr                                           "0xB8061300"
#define  ISO_MISC_DDC4_I2C_CR_reg                                                0xB8061300
#define  ISO_MISC_DDC4_I2C_CR_inst_addr                                          "0x0000"
#define  set_ISO_MISC_DDC4_I2C_CR_reg(data)                                      (*((volatile unsigned int*)ISO_MISC_DDC4_I2C_CR_reg)=data)
#define  get_ISO_MISC_DDC4_I2C_CR_reg                                            (*((volatile unsigned int*)ISO_MISC_DDC4_I2C_CR_reg))
#define  ISO_MISC_DDC4_I2C_CR_cmderr_ie_shift                                    (7)
#define  ISO_MISC_DDC4_I2C_CR_timeout_en_shift                                   (6)
#define  ISO_MISC_DDC4_I2C_CR_debounce_mode_shift                                (4)
#define  ISO_MISC_DDC4_I2C_CR_timeout_ie_shift                                   (3)
#define  ISO_MISC_DDC4_I2C_CR_retime_m_shift                                     (0)
#define  ISO_MISC_DDC4_I2C_CR_cmderr_ie_mask                                     (0x00000080)
#define  ISO_MISC_DDC4_I2C_CR_timeout_en_mask                                    (0x00000040)
#define  ISO_MISC_DDC4_I2C_CR_debounce_mode_mask                                 (0x00000030)
#define  ISO_MISC_DDC4_I2C_CR_timeout_ie_mask                                    (0x00000008)
#define  ISO_MISC_DDC4_I2C_CR_retime_m_mask                                      (0x00000007)
#define  ISO_MISC_DDC4_I2C_CR_cmderr_ie(data)                                    (0x00000080&((data)<<7))
#define  ISO_MISC_DDC4_I2C_CR_timeout_en(data)                                   (0x00000040&((data)<<6))
#define  ISO_MISC_DDC4_I2C_CR_debounce_mode(data)                                (0x00000030&((data)<<4))
#define  ISO_MISC_DDC4_I2C_CR_timeout_ie(data)                                   (0x00000008&((data)<<3))
#define  ISO_MISC_DDC4_I2C_CR_retime_m(data)                                     (0x00000007&(data))
#define  ISO_MISC_DDC4_I2C_CR_get_cmderr_ie(data)                                ((0x00000080&(data))>>7)
#define  ISO_MISC_DDC4_I2C_CR_get_timeout_en(data)                               ((0x00000040&(data))>>6)
#define  ISO_MISC_DDC4_I2C_CR_get_debounce_mode(data)                            ((0x00000030&(data))>>4)
#define  ISO_MISC_DDC4_I2C_CR_get_timeout_ie(data)                               ((0x00000008&(data))>>3)
#define  ISO_MISC_DDC4_I2C_CR_get_retime_m(data)                                 (0x00000007&(data))

#define  ISO_MISC_DDC4_I2C_SR1                                                   0x18061304
#define  ISO_MISC_DDC4_I2C_SR1_reg_addr                                          "0xB8061304"
#define  ISO_MISC_DDC4_I2C_SR1_reg                                               0xB8061304
#define  ISO_MISC_DDC4_I2C_SR1_inst_addr                                         "0x0001"
#define  set_ISO_MISC_DDC4_I2C_SR1_reg(data)                                     (*((volatile unsigned int*)ISO_MISC_DDC4_I2C_SR1_reg)=data)
#define  get_ISO_MISC_DDC4_I2C_SR1_reg                                           (*((volatile unsigned int*)ISO_MISC_DDC4_I2C_SR1_reg))
#define  ISO_MISC_DDC4_I2C_SR1_cmderr_shift                                      (7)
#define  ISO_MISC_DDC4_I2C_SR1_finish_shift                                      (4)
#define  ISO_MISC_DDC4_I2C_SR1_timeout_shift                                     (3)
#define  ISO_MISC_DDC4_I2C_SR1_cmderr_mask                                       (0x00000080)
#define  ISO_MISC_DDC4_I2C_SR1_finish_mask                                       (0x00000010)
#define  ISO_MISC_DDC4_I2C_SR1_timeout_mask                                      (0x00000008)
#define  ISO_MISC_DDC4_I2C_SR1_cmderr(data)                                      (0x00000080&((data)<<7))
#define  ISO_MISC_DDC4_I2C_SR1_finish(data)                                      (0x00000010&((data)<<4))
#define  ISO_MISC_DDC4_I2C_SR1_timeout(data)                                     (0x00000008&((data)<<3))
#define  ISO_MISC_DDC4_I2C_SR1_get_cmderr(data)                                  ((0x00000080&(data))>>7)
#define  ISO_MISC_DDC4_I2C_SR1_get_finish(data)                                  ((0x00000010&(data))>>4)
#define  ISO_MISC_DDC4_I2C_SR1_get_timeout(data)                                 ((0x00000008&(data))>>3)

#define  ISO_MISC_DDC4_I2C_TR                                                    0x18061308
#define  ISO_MISC_DDC4_I2C_TR_reg_addr                                           "0xB8061308"
#define  ISO_MISC_DDC4_I2C_TR_reg                                                0xB8061308
#define  ISO_MISC_DDC4_I2C_TR_inst_addr                                          "0x0002"
#define  set_ISO_MISC_DDC4_I2C_TR_reg(data)                                      (*((volatile unsigned int*)ISO_MISC_DDC4_I2C_TR_reg)=data)
#define  get_ISO_MISC_DDC4_I2C_TR_reg                                            (*((volatile unsigned int*)ISO_MISC_DDC4_I2C_TR_reg))
#define  ISO_MISC_DDC4_I2C_TR_timeout_val_shift                                  (0)
#define  ISO_MISC_DDC4_I2C_TR_timeout_val_mask                                   (0x000000FF)
#define  ISO_MISC_DDC4_I2C_TR_timeout_val(data)                                  (0x000000FF&(data))
#define  ISO_MISC_DDC4_I2C_TR_get_timeout_val(data)                              (0x000000FF&(data))

#define  ISO_MISC_DDC4_EDID_CR                                                   0x1806130C
#define  ISO_MISC_DDC4_EDID_CR_reg_addr                                          "0xB806130C"
#define  ISO_MISC_DDC4_EDID_CR_reg                                               0xB806130C
#define  ISO_MISC_DDC4_EDID_CR_inst_addr                                         "0x0003"
#define  set_ISO_MISC_DDC4_EDID_CR_reg(data)                                     (*((volatile unsigned int*)ISO_MISC_DDC4_EDID_CR_reg)=data)
#define  get_ISO_MISC_DDC4_EDID_CR_reg                                           (*((volatile unsigned int*)ISO_MISC_DDC4_EDID_CR_reg))
#define  ISO_MISC_DDC4_EDID_CR_edid_address_shift                                (5)
#define  ISO_MISC_DDC4_EDID_CR_finish_int_en_shift                               (4)
#define  ISO_MISC_DDC4_EDID_CR_edid_srwen_shift                                  (1)
#define  ISO_MISC_DDC4_EDID_CR_edid_en_shift                                     (0)
#define  ISO_MISC_DDC4_EDID_CR_edid_address_mask                                 (0x000000E0)
#define  ISO_MISC_DDC4_EDID_CR_finish_int_en_mask                                (0x00000010)
#define  ISO_MISC_DDC4_EDID_CR_edid_srwen_mask                                   (0x00000002)
#define  ISO_MISC_DDC4_EDID_CR_edid_en_mask                                      (0x00000001)
#define  ISO_MISC_DDC4_EDID_CR_edid_address(data)                                (0x000000E0&((data)<<5))
#define  ISO_MISC_DDC4_EDID_CR_finish_int_en(data)                               (0x00000010&((data)<<4))
#define  ISO_MISC_DDC4_EDID_CR_edid_srwen(data)                                  (0x00000002&((data)<<1))
#define  ISO_MISC_DDC4_EDID_CR_edid_en(data)                                     (0x00000001&(data))
#define  ISO_MISC_DDC4_EDID_CR_get_edid_address(data)                            ((0x000000E0&(data))>>5)
#define  ISO_MISC_DDC4_EDID_CR_get_finish_int_en(data)                           ((0x00000010&(data))>>4)
#define  ISO_MISC_DDC4_EDID_CR_get_edid_srwen(data)                              ((0x00000002&(data))>>1)
#define  ISO_MISC_DDC4_EDID_CR_get_edid_en(data)                                 (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_VCR                                                   0x18061310
#define  ISO_MISC_DDC4_DDC_VCR_reg_addr                                          "0xB8061310"
#define  ISO_MISC_DDC4_DDC_VCR_reg                                               0xB8061310
#define  ISO_MISC_DDC4_DDC_VCR_inst_addr                                         "0x0004"
#define  set_ISO_MISC_DDC4_DDC_VCR_reg(data)                                     (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_VCR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_VCR_reg                                           (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_VCR_reg))
#define  ISO_MISC_DDC4_DDC_VCR_dummy_7_0_shift                                   (0)
#define  ISO_MISC_DDC4_DDC_VCR_dummy_7_0_mask                                    (0x000000FF)
#define  ISO_MISC_DDC4_DDC_VCR_dummy_7_0(data)                                   (0x000000FF&(data))
#define  ISO_MISC_DDC4_DDC_VCR_get_dummy_7_0(data)                               (0x000000FF&(data))

#define  ISO_MISC_DDC4_EDID_IMSWSAR                                              0x18061314
#define  ISO_MISC_DDC4_EDID_IMSWSAR_reg_addr                                     "0xB8061314"
#define  ISO_MISC_DDC4_EDID_IMSWSAR_reg                                          0xB8061314
#define  ISO_MISC_DDC4_EDID_IMSWSAR_inst_addr                                    "0x0005"
#define  set_ISO_MISC_DDC4_EDID_IMSWSAR_reg(data)                                (*((volatile unsigned int*)ISO_MISC_DDC4_EDID_IMSWSAR_reg)=data)
#define  get_ISO_MISC_DDC4_EDID_IMSWSAR_reg                                      (*((volatile unsigned int*)ISO_MISC_DDC4_EDID_IMSWSAR_reg))
#define  ISO_MISC_DDC4_EDID_IMSWSAR_edid_sadr_shift                              (0)
#define  ISO_MISC_DDC4_EDID_IMSWSAR_edid_sadr_mask                               (0x000000FF)
#define  ISO_MISC_DDC4_EDID_IMSWSAR_edid_sadr(data)                              (0x000000FF&(data))
#define  ISO_MISC_DDC4_EDID_IMSWSAR_get_edid_sadr(data)                          (0x000000FF&(data))

#define  ISO_MISC_DDC4_EDID_IMSWEAR                                              0x18061318
#define  ISO_MISC_DDC4_EDID_IMSWEAR_reg_addr                                     "0xB8061318"
#define  ISO_MISC_DDC4_EDID_IMSWEAR_reg                                          0xB8061318
#define  ISO_MISC_DDC4_EDID_IMSWEAR_inst_addr                                    "0x0006"
#define  set_ISO_MISC_DDC4_EDID_IMSWEAR_reg(data)                                (*((volatile unsigned int*)ISO_MISC_DDC4_EDID_IMSWEAR_reg)=data)
#define  get_ISO_MISC_DDC4_EDID_IMSWEAR_reg                                      (*((volatile unsigned int*)ISO_MISC_DDC4_EDID_IMSWEAR_reg))
#define  ISO_MISC_DDC4_EDID_IMSWEAR_edid_eadr_shift                              (0)
#define  ISO_MISC_DDC4_EDID_IMSWEAR_edid_eadr_mask                               (0x000000FF)
#define  ISO_MISC_DDC4_EDID_IMSWEAR_edid_eadr(data)                              (0x000000FF&(data))
#define  ISO_MISC_DDC4_EDID_IMSWEAR_get_edid_eadr(data)                          (0x000000FF&(data))

#define  ISO_MISC_DDC4_EDID_IR                                                   0x1806131C
#define  ISO_MISC_DDC4_EDID_IR_reg_addr                                          "0xB806131C"
#define  ISO_MISC_DDC4_EDID_IR_reg                                               0xB806131C
#define  ISO_MISC_DDC4_EDID_IR_inst_addr                                         "0x0007"
#define  set_ISO_MISC_DDC4_EDID_IR_reg(data)                                     (*((volatile unsigned int*)ISO_MISC_DDC4_EDID_IR_reg)=data)
#define  get_ISO_MISC_DDC4_EDID_IR_reg                                           (*((volatile unsigned int*)ISO_MISC_DDC4_EDID_IR_reg))
#define  ISO_MISC_DDC4_EDID_IR_edidmode_shift                                    (6)
#define  ISO_MISC_DDC4_EDID_IR_edidsubaddress_shift                              (5)
#define  ISO_MISC_DDC4_EDID_IR_edidstop_shift                                    (4)
#define  ISO_MISC_DDC4_EDID_IR_i2c_m_rd_st_ie_shift                              (3)
#define  ISO_MISC_DDC4_EDID_IR_i2c_m_rd_sp_ie_shift                              (2)
#define  ISO_MISC_DDC4_EDID_IR_edidsubaddress_ie_shift                           (1)
#define  ISO_MISC_DDC4_EDID_IR_edidstop_ie_shift                                 (0)
#define  ISO_MISC_DDC4_EDID_IR_edidmode_mask                                     (0x00000040)
#define  ISO_MISC_DDC4_EDID_IR_edidsubaddress_mask                               (0x00000020)
#define  ISO_MISC_DDC4_EDID_IR_edidstop_mask                                     (0x00000010)
#define  ISO_MISC_DDC4_EDID_IR_i2c_m_rd_st_ie_mask                               (0x00000008)
#define  ISO_MISC_DDC4_EDID_IR_i2c_m_rd_sp_ie_mask                               (0x00000004)
#define  ISO_MISC_DDC4_EDID_IR_edidsubaddress_ie_mask                            (0x00000002)
#define  ISO_MISC_DDC4_EDID_IR_edidstop_ie_mask                                  (0x00000001)
#define  ISO_MISC_DDC4_EDID_IR_edidmode(data)                                    (0x00000040&((data)<<6))
#define  ISO_MISC_DDC4_EDID_IR_edidsubaddress(data)                              (0x00000020&((data)<<5))
#define  ISO_MISC_DDC4_EDID_IR_edidstop(data)                                    (0x00000010&((data)<<4))
#define  ISO_MISC_DDC4_EDID_IR_i2c_m_rd_st_ie(data)                              (0x00000008&((data)<<3))
#define  ISO_MISC_DDC4_EDID_IR_i2c_m_rd_sp_ie(data)                              (0x00000004&((data)<<2))
#define  ISO_MISC_DDC4_EDID_IR_edidsubaddress_ie(data)                           (0x00000002&((data)<<1))
#define  ISO_MISC_DDC4_EDID_IR_edidstop_ie(data)                                 (0x00000001&(data))
#define  ISO_MISC_DDC4_EDID_IR_get_edidmode(data)                                ((0x00000040&(data))>>6)
#define  ISO_MISC_DDC4_EDID_IR_get_edidsubaddress(data)                          ((0x00000020&(data))>>5)
#define  ISO_MISC_DDC4_EDID_IR_get_edidstop(data)                                ((0x00000010&(data))>>4)
#define  ISO_MISC_DDC4_EDID_IR_get_i2c_m_rd_st_ie(data)                          ((0x00000008&(data))>>3)
#define  ISO_MISC_DDC4_EDID_IR_get_i2c_m_rd_sp_ie(data)                          ((0x00000004&(data))>>2)
#define  ISO_MISC_DDC4_EDID_IR_get_edidsubaddress_ie(data)                       ((0x00000002&(data))>>1)
#define  ISO_MISC_DDC4_EDID_IR_get_edidstop_ie(data)                             (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_SIR                                                   0x18061320
#define  ISO_MISC_DDC4_DDC_SIR_reg_addr                                          "0xB8061320"
#define  ISO_MISC_DDC4_DDC_SIR_reg                                               0xB8061320
#define  ISO_MISC_DDC4_DDC_SIR_inst_addr                                         "0x0008"
#define  set_ISO_MISC_DDC4_DDC_SIR_reg(data)                                     (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SIR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SIR_reg                                           (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SIR_reg))
#define  ISO_MISC_DDC4_DDC_SIR_edidap_shift                                      (0)
#define  ISO_MISC_DDC4_DDC_SIR_edidap_mask                                       (0x000001FF)
#define  ISO_MISC_DDC4_DDC_SIR_edidap(data)                                      (0x000001FF&(data))
#define  ISO_MISC_DDC4_DDC_SIR_get_edidap(data)                                  (0x000001FF&(data))

#define  ISO_MISC_DDC4_DDC_SAP                                                   0x18061324
#define  ISO_MISC_DDC4_DDC_SAP_reg_addr                                          "0xB8061324"
#define  ISO_MISC_DDC4_DDC_SAP_reg                                               0xB8061324
#define  ISO_MISC_DDC4_DDC_SAP_inst_addr                                         "0x0009"
#define  set_ISO_MISC_DDC4_DDC_SAP_reg(data)                                     (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SAP_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SAP_reg                                           (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SAP_reg))
#define  ISO_MISC_DDC4_DDC_SAP_ediddp_shift                                      (0)
#define  ISO_MISC_DDC4_DDC_SAP_ediddp_mask                                       (0x000000FF)
#define  ISO_MISC_DDC4_DDC_SAP_ediddp(data)                                      (0x000000FF&(data))
#define  ISO_MISC_DDC4_DDC_SAP_get_ediddp(data)                                  (0x000000FF&(data))

#define  ISO_MISC_DDC4_DDC_BISTCR                                                0x18061328
#define  ISO_MISC_DDC4_DDC_BISTCR_reg_addr                                       "0xB8061328"
#define  ISO_MISC_DDC4_DDC_BISTCR_reg                                            0xB8061328
#define  ISO_MISC_DDC4_DDC_BISTCR_inst_addr                                      "0x000A"
#define  set_ISO_MISC_DDC4_DDC_BISTCR_reg(data)                                  (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_BISTCR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_BISTCR_reg                                        (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_BISTCR_reg))
#define  ISO_MISC_DDC4_DDC_BISTCR_ddc_bist_rstn_shift                            (5)
#define  ISO_MISC_DDC4_DDC_BISTCR_ddc_bist_rme_shift                             (4)
#define  ISO_MISC_DDC4_DDC_BISTCR_ddc_bist_rm_shift                              (0)
#define  ISO_MISC_DDC4_DDC_BISTCR_ddc_bist_rstn_mask                             (0x00000020)
#define  ISO_MISC_DDC4_DDC_BISTCR_ddc_bist_rme_mask                              (0x00000010)
#define  ISO_MISC_DDC4_DDC_BISTCR_ddc_bist_rm_mask                               (0x0000000F)
#define  ISO_MISC_DDC4_DDC_BISTCR_ddc_bist_rstn(data)                            (0x00000020&((data)<<5))
#define  ISO_MISC_DDC4_DDC_BISTCR_ddc_bist_rme(data)                             (0x00000010&((data)<<4))
#define  ISO_MISC_DDC4_DDC_BISTCR_ddc_bist_rm(data)                              (0x0000000F&(data))
#define  ISO_MISC_DDC4_DDC_BISTCR_get_ddc_bist_rstn(data)                        ((0x00000020&(data))>>5)
#define  ISO_MISC_DDC4_DDC_BISTCR_get_ddc_bist_rme(data)                         ((0x00000010&(data))>>4)
#define  ISO_MISC_DDC4_DDC_BISTCR_get_ddc_bist_rm(data)                          (0x0000000F&(data))

#define  ISO_MISC_DDC4_DDC_SCR                                                   0x1806132C
#define  ISO_MISC_DDC4_DDC_SCR_reg_addr                                          "0xB806132C"
#define  ISO_MISC_DDC4_DDC_SCR_reg                                               0xB806132C
#define  ISO_MISC_DDC4_DDC_SCR_inst_addr                                         "0x000B"
#define  set_ISO_MISC_DDC4_DDC_SCR_reg(data)                                     (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SCR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SCR_reg                                           (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SCR_reg))
#define  ISO_MISC_DDC4_DDC_SCR_segpt_latie_shift                                 (7)
#define  ISO_MISC_DDC4_DDC_SCR_dataoutputdelay_sel_shift                         (4)
#define  ISO_MISC_DDC4_DDC_SCR_i2c_m_rd_st_sts_shift                             (2)
#define  ISO_MISC_DDC4_DDC_SCR_i2c_m_rd_sp_sts_shift                             (1)
#define  ISO_MISC_DDC4_DDC_SCR_sgid_en_shift                                     (0)
#define  ISO_MISC_DDC4_DDC_SCR_segpt_latie_mask                                  (0x00000080)
#define  ISO_MISC_DDC4_DDC_SCR_dataoutputdelay_sel_mask                          (0x00000070)
#define  ISO_MISC_DDC4_DDC_SCR_i2c_m_rd_st_sts_mask                              (0x00000004)
#define  ISO_MISC_DDC4_DDC_SCR_i2c_m_rd_sp_sts_mask                              (0x00000002)
#define  ISO_MISC_DDC4_DDC_SCR_sgid_en_mask                                      (0x00000001)
#define  ISO_MISC_DDC4_DDC_SCR_segpt_latie(data)                                 (0x00000080&((data)<<7))
#define  ISO_MISC_DDC4_DDC_SCR_dataoutputdelay_sel(data)                         (0x00000070&((data)<<4))
#define  ISO_MISC_DDC4_DDC_SCR_i2c_m_rd_st_sts(data)                             (0x00000004&((data)<<2))
#define  ISO_MISC_DDC4_DDC_SCR_i2c_m_rd_sp_sts(data)                             (0x00000002&((data)<<1))
#define  ISO_MISC_DDC4_DDC_SCR_sgid_en(data)                                     (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_SCR_get_segpt_latie(data)                             ((0x00000080&(data))>>7)
#define  ISO_MISC_DDC4_DDC_SCR_get_dataoutputdelay_sel(data)                     ((0x00000070&(data))>>4)
#define  ISO_MISC_DDC4_DDC_SCR_get_i2c_m_rd_st_sts(data)                         ((0x00000004&(data))>>2)
#define  ISO_MISC_DDC4_DDC_SCR_get_i2c_m_rd_sp_sts(data)                         ((0x00000002&(data))>>1)
#define  ISO_MISC_DDC4_DDC_SCR_get_sgid_en(data)                                 (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_SSAR                                                  0x18061330
#define  ISO_MISC_DDC4_DDC_SSAR_reg_addr                                         "0xB8061330"
#define  ISO_MISC_DDC4_DDC_SSAR_reg                                              0xB8061330
#define  ISO_MISC_DDC4_DDC_SSAR_inst_addr                                        "0x000C"
#define  set_ISO_MISC_DDC4_DDC_SSAR_reg(data)                                    (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SSAR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SSAR_reg                                          (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SSAR_reg))
#define  ISO_MISC_DDC4_DDC_SSAR_sgid_address_shift                               (1)
#define  ISO_MISC_DDC4_DDC_SSAR_sgid_dtrden_shift                                (0)
#define  ISO_MISC_DDC4_DDC_SSAR_sgid_address_mask                                (0x000000FE)
#define  ISO_MISC_DDC4_DDC_SSAR_sgid_dtrden_mask                                 (0x00000001)
#define  ISO_MISC_DDC4_DDC_SSAR_sgid_address(data)                               (0x000000FE&((data)<<1))
#define  ISO_MISC_DDC4_DDC_SSAR_sgid_dtrden(data)                                (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_SSAR_get_sgid_address(data)                           ((0x000000FE&(data))>>1)
#define  ISO_MISC_DDC4_DDC_SSAR_get_sgid_dtrden(data)                            (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_SPR                                                   0x18061334
#define  ISO_MISC_DDC4_DDC_SPR_reg_addr                                          "0xB8061334"
#define  ISO_MISC_DDC4_DDC_SPR_reg                                               0xB8061334
#define  ISO_MISC_DDC4_DDC_SPR_inst_addr                                         "0x000D"
#define  set_ISO_MISC_DDC4_DDC_SPR_reg(data)                                     (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SPR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SPR_reg                                           (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SPR_reg))
#define  ISO_MISC_DDC4_DDC_SPR_segpt_latched_shift                               (7)
#define  ISO_MISC_DDC4_DDC_SPR_seg_pt_shift                                      (0)
#define  ISO_MISC_DDC4_DDC_SPR_segpt_latched_mask                                (0x00000080)
#define  ISO_MISC_DDC4_DDC_SPR_seg_pt_mask                                       (0x0000007F)
#define  ISO_MISC_DDC4_DDC_SPR_segpt_latched(data)                               (0x00000080&((data)<<7))
#define  ISO_MISC_DDC4_DDC_SPR_seg_pt(data)                                      (0x0000007F&(data))
#define  ISO_MISC_DDC4_DDC_SPR_get_segpt_latched(data)                           ((0x00000080&(data))>>7)
#define  ISO_MISC_DDC4_DDC_SPR_get_seg_pt(data)                                  (0x0000007F&(data))

#define  ISO_MISC_DDC4_DDC_SFCR                                                  0x18061338
#define  ISO_MISC_DDC4_DDC_SFCR_reg_addr                                         "0xB8061338"
#define  ISO_MISC_DDC4_DDC_SFCR_reg                                              0xB8061338
#define  ISO_MISC_DDC4_DDC_SFCR_inst_addr                                        "0x000E"
#define  set_ISO_MISC_DDC4_DDC_SFCR_reg(data)                                    (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFCR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SFCR_reg                                          (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFCR_reg))
#define  ISO_MISC_DDC4_DDC_SFCR_special_mode_shift                               (3)
#define  ISO_MISC_DDC4_DDC_SFCR_doffpt_reset_shift                               (2)
#define  ISO_MISC_DDC4_DDC_SFCR_diffpt_reset_shift                               (1)
#define  ISO_MISC_DDC4_DDC_SFCR_ciid_en_shift                                    (0)
#define  ISO_MISC_DDC4_DDC_SFCR_special_mode_mask                                (0x00000008)
#define  ISO_MISC_DDC4_DDC_SFCR_doffpt_reset_mask                                (0x00000004)
#define  ISO_MISC_DDC4_DDC_SFCR_diffpt_reset_mask                                (0x00000002)
#define  ISO_MISC_DDC4_DDC_SFCR_ciid_en_mask                                     (0x00000001)
#define  ISO_MISC_DDC4_DDC_SFCR_special_mode(data)                               (0x00000008&((data)<<3))
#define  ISO_MISC_DDC4_DDC_SFCR_doffpt_reset(data)                               (0x00000004&((data)<<2))
#define  ISO_MISC_DDC4_DDC_SFCR_diffpt_reset(data)                               (0x00000002&((data)<<1))
#define  ISO_MISC_DDC4_DDC_SFCR_ciid_en(data)                                    (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_SFCR_get_special_mode(data)                           ((0x00000008&(data))>>3)
#define  ISO_MISC_DDC4_DDC_SFCR_get_doffpt_reset(data)                           ((0x00000004&(data))>>2)
#define  ISO_MISC_DDC4_DDC_SFCR_get_diffpt_reset(data)                           ((0x00000002&(data))>>1)
#define  ISO_MISC_DDC4_DDC_SFCR_get_ciid_en(data)                                (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_SFSAR                                                 0x1806133C
#define  ISO_MISC_DDC4_DDC_SFSAR_reg_addr                                        "0xB806133C"
#define  ISO_MISC_DDC4_DDC_SFSAR_reg                                             0xB806133C
#define  ISO_MISC_DDC4_DDC_SFSAR_inst_addr                                       "0x000F"
#define  set_ISO_MISC_DDC4_DDC_SFSAR_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFSAR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SFSAR_reg                                         (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFSAR_reg))
#define  ISO_MISC_DDC4_DDC_SFSAR_ciid_address_shift                              (1)
#define  ISO_MISC_DDC4_DDC_SFSAR_cirws_current_shift                             (0)
#define  ISO_MISC_DDC4_DDC_SFSAR_ciid_address_mask                               (0x000000FE)
#define  ISO_MISC_DDC4_DDC_SFSAR_cirws_current_mask                              (0x00000001)
#define  ISO_MISC_DDC4_DDC_SFSAR_ciid_address(data)                              (0x000000FE&((data)<<1))
#define  ISO_MISC_DDC4_DDC_SFSAR_cirws_current(data)                             (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_SFSAR_get_ciid_address(data)                          ((0x000000FE&(data))>>1)
#define  ISO_MISC_DDC4_DDC_SFSAR_get_cirws_current(data)                         (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_SFDR                                                  0x18061340
#define  ISO_MISC_DDC4_DDC_SFDR_reg_addr                                         "0xB8061340"
#define  ISO_MISC_DDC4_DDC_SFDR_reg                                              0xB8061340
#define  ISO_MISC_DDC4_DDC_SFDR_inst_addr                                        "0x0010"
#define  set_ISO_MISC_DDC4_DDC_SFDR_reg(data)                                    (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFDR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SFDR_reg                                          (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFDR_reg))
#define  ISO_MISC_DDC4_DDC_SFDR_ciiddp_shift                                     (0)
#define  ISO_MISC_DDC4_DDC_SFDR_ciiddp_mask                                      (0x000000FF)
#define  ISO_MISC_DDC4_DDC_SFDR_ciiddp(data)                                     (0x000000FF&(data))
#define  ISO_MISC_DDC4_DDC_SFDR_get_ciiddp(data)                                 (0x000000FF&(data))

#define  ISO_MISC_DDC4_DDC_SFBSR                                                 0x18061344
#define  ISO_MISC_DDC4_DDC_SFBSR_reg_addr                                        "0xB8061344"
#define  ISO_MISC_DDC4_DDC_SFBSR_reg                                             0xB8061344
#define  ISO_MISC_DDC4_DDC_SFBSR_inst_addr                                       "0x0011"
#define  set_ISO_MISC_DDC4_DDC_SFBSR_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFBSR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SFBSR_reg                                         (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFBSR_reg))
#define  ISO_MISC_DDC4_DDC_SFBSR_cirws_2nd_shift                                 (5)
#define  ISO_MISC_DDC4_DDC_SFBSR_cirws_1st_shift                                 (4)
#define  ISO_MISC_DDC4_DDC_SFBSR_cippt_2nd_shift                                 (3)
#define  ISO_MISC_DDC4_DDC_SFBSR_cispt_2nd_shift                                 (2)
#define  ISO_MISC_DDC4_DDC_SFBSR_cippt_1st_shift                                 (1)
#define  ISO_MISC_DDC4_DDC_SFBSR_cispt_1st_shift                                 (0)
#define  ISO_MISC_DDC4_DDC_SFBSR_cirws_2nd_mask                                  (0x00000020)
#define  ISO_MISC_DDC4_DDC_SFBSR_cirws_1st_mask                                  (0x00000010)
#define  ISO_MISC_DDC4_DDC_SFBSR_cippt_2nd_mask                                  (0x00000008)
#define  ISO_MISC_DDC4_DDC_SFBSR_cispt_2nd_mask                                  (0x00000004)
#define  ISO_MISC_DDC4_DDC_SFBSR_cippt_1st_mask                                  (0x00000002)
#define  ISO_MISC_DDC4_DDC_SFBSR_cispt_1st_mask                                  (0x00000001)
#define  ISO_MISC_DDC4_DDC_SFBSR_cirws_2nd(data)                                 (0x00000020&((data)<<5))
#define  ISO_MISC_DDC4_DDC_SFBSR_cirws_1st(data)                                 (0x00000010&((data)<<4))
#define  ISO_MISC_DDC4_DDC_SFBSR_cippt_2nd(data)                                 (0x00000008&((data)<<3))
#define  ISO_MISC_DDC4_DDC_SFBSR_cispt_2nd(data)                                 (0x00000004&((data)<<2))
#define  ISO_MISC_DDC4_DDC_SFBSR_cippt_1st(data)                                 (0x00000002&((data)<<1))
#define  ISO_MISC_DDC4_DDC_SFBSR_cispt_1st(data)                                 (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_SFBSR_get_cirws_2nd(data)                             ((0x00000020&(data))>>5)
#define  ISO_MISC_DDC4_DDC_SFBSR_get_cirws_1st(data)                             ((0x00000010&(data))>>4)
#define  ISO_MISC_DDC4_DDC_SFBSR_get_cippt_2nd(data)                             ((0x00000008&(data))>>3)
#define  ISO_MISC_DDC4_DDC_SFBSR_get_cispt_2nd(data)                             ((0x00000004&(data))>>2)
#define  ISO_MISC_DDC4_DDC_SFBSR_get_cippt_1st(data)                             ((0x00000002&(data))>>1)
#define  ISO_MISC_DDC4_DDC_SFBSR_get_cispt_1st(data)                             (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_SFIBLR                                                0x18061348
#define  ISO_MISC_DDC4_DDC_SFIBLR_reg_addr                                       "0xB8061348"
#define  ISO_MISC_DDC4_DDC_SFIBLR_reg                                            0xB8061348
#define  ISO_MISC_DDC4_DDC_SFIBLR_inst_addr                                      "0x0012"
#define  set_ISO_MISC_DDC4_DDC_SFIBLR_reg(data)                                  (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFIBLR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SFIBLR_reg                                        (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFIBLR_reg))
#define  ISO_MISC_DDC4_DDC_SFIBLR_ffdi_dlen_shift                                (0)
#define  ISO_MISC_DDC4_DDC_SFIBLR_ffdi_dlen_mask                                 (0x0000001F)
#define  ISO_MISC_DDC4_DDC_SFIBLR_ffdi_dlen(data)                                (0x0000001F&(data))
#define  ISO_MISC_DDC4_DDC_SFIBLR_get_ffdi_dlen(data)                            (0x0000001F&(data))

#define  ISO_MISC_DDC4_DDC_SFIBRWPR                                              0x1806134C
#define  ISO_MISC_DDC4_DDC_SFIBRWPR_reg_addr                                     "0xB806134C"
#define  ISO_MISC_DDC4_DDC_SFIBRWPR_reg                                          0xB806134C
#define  ISO_MISC_DDC4_DDC_SFIBRWPR_inst_addr                                    "0x0013"
#define  set_ISO_MISC_DDC4_DDC_SFIBRWPR_reg(data)                                (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFIBRWPR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SFIBRWPR_reg                                      (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFIBRWPR_reg))
#define  ISO_MISC_DDC4_DDC_SFIBRWPR_diff_wpt_shift                               (4)
#define  ISO_MISC_DDC4_DDC_SFIBRWPR_diff_rpt_shift                               (0)
#define  ISO_MISC_DDC4_DDC_SFIBRWPR_diff_wpt_mask                                (0x000000F0)
#define  ISO_MISC_DDC4_DDC_SFIBRWPR_diff_rpt_mask                                (0x0000000F)
#define  ISO_MISC_DDC4_DDC_SFIBRWPR_diff_wpt(data)                               (0x000000F0&((data)<<4))
#define  ISO_MISC_DDC4_DDC_SFIBRWPR_diff_rpt(data)                               (0x0000000F&(data))
#define  ISO_MISC_DDC4_DDC_SFIBRWPR_get_diff_wpt(data)                           ((0x000000F0&(data))>>4)
#define  ISO_MISC_DDC4_DDC_SFIBRWPR_get_diff_rpt(data)                           (0x0000000F&(data))

#define  ISO_MISC_DDC4_DDC_SFIBSWPR                                              0x18061350
#define  ISO_MISC_DDC4_DDC_SFIBSWPR_reg_addr                                     "0xB8061350"
#define  ISO_MISC_DDC4_DDC_SFIBSWPR_reg                                          0xB8061350
#define  ISO_MISC_DDC4_DDC_SFIBSWPR_inst_addr                                    "0x0014"
#define  set_ISO_MISC_DDC4_DDC_SFIBSWPR_reg(data)                                (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFIBSWPR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SFIBSWPR_reg                                      (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFIBSWPR_reg))
#define  ISO_MISC_DDC4_DDC_SFIBSWPR_diffstop_pt_shift                            (0)
#define  ISO_MISC_DDC4_DDC_SFIBSWPR_diffstop_pt_mask                             (0x0000000F)
#define  ISO_MISC_DDC4_DDC_SFIBSWPR_diffstop_pt(data)                            (0x0000000F&(data))
#define  ISO_MISC_DDC4_DDC_SFIBSWPR_get_diffstop_pt(data)                        (0x0000000F&(data))

#define  ISO_MISC_DDC4_DDC_SFOBSR                                                0x18061354
#define  ISO_MISC_DDC4_DDC_SFOBSR_reg_addr                                       "0xB8061354"
#define  ISO_MISC_DDC4_DDC_SFOBSR_reg                                            0xB8061354
#define  ISO_MISC_DDC4_DDC_SFOBSR_inst_addr                                      "0x0015"
#define  set_ISO_MISC_DDC4_DDC_SFOBSR_reg(data)                                  (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFOBSR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SFOBSR_reg                                        (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFOBSR_reg))
#define  ISO_MISC_DDC4_DDC_SFOBSR_ffdo_dlen_shift                                (0)
#define  ISO_MISC_DDC4_DDC_SFOBSR_ffdo_dlen_mask                                 (0x0000001F)
#define  ISO_MISC_DDC4_DDC_SFOBSR_ffdo_dlen(data)                                (0x0000001F&(data))
#define  ISO_MISC_DDC4_DDC_SFOBSR_get_ffdo_dlen(data)                            (0x0000001F&(data))

#define  ISO_MISC_DDC4_DDC_SFOBRWPR                                              0x18061358
#define  ISO_MISC_DDC4_DDC_SFOBRWPR_reg_addr                                     "0xB8061358"
#define  ISO_MISC_DDC4_DDC_SFOBRWPR_reg                                          0xB8061358
#define  ISO_MISC_DDC4_DDC_SFOBRWPR_inst_addr                                    "0x0016"
#define  set_ISO_MISC_DDC4_DDC_SFOBRWPR_reg(data)                                (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFOBRWPR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SFOBRWPR_reg                                      (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFOBRWPR_reg))
#define  ISO_MISC_DDC4_DDC_SFOBRWPR_doff_wpt_shift                               (4)
#define  ISO_MISC_DDC4_DDC_SFOBRWPR_doff_rpt_shift                               (0)
#define  ISO_MISC_DDC4_DDC_SFOBRWPR_doff_wpt_mask                                (0x000000F0)
#define  ISO_MISC_DDC4_DDC_SFOBRWPR_doff_rpt_mask                                (0x0000000F)
#define  ISO_MISC_DDC4_DDC_SFOBRWPR_doff_wpt(data)                               (0x000000F0&((data)<<4))
#define  ISO_MISC_DDC4_DDC_SFOBRWPR_doff_rpt(data)                               (0x0000000F&(data))
#define  ISO_MISC_DDC4_DDC_SFOBRWPR_get_doff_wpt(data)                           ((0x000000F0&(data))>>4)
#define  ISO_MISC_DDC4_DDC_SFOBRWPR_get_doff_rpt(data)                           (0x0000000F&(data))

#define  ISO_MISC_DDC4_DDC_SFSR                                                  0x1806135C
#define  ISO_MISC_DDC4_DDC_SFSR_reg_addr                                         "0xB806135C"
#define  ISO_MISC_DDC4_DDC_SFSR_reg                                              0xB806135C
#define  ISO_MISC_DDC4_DDC_SFSR_inst_addr                                        "0x0017"
#define  set_ISO_MISC_DDC4_DDC_SFSR_reg(data)                                    (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFSR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SFSR_reg                                          (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFSR_reg))
#define  ISO_MISC_DDC4_DDC_SFSR_ffdouf_st_shift                                  (7)
#define  ISO_MISC_DDC4_DDC_SFSR_ffdiof_st_shift                                  (6)
#define  ISO_MISC_DDC4_DDC_SFSR_ffdonf_st_shift                                  (5)
#define  ISO_MISC_DDC4_DDC_SFSR_ffdoet_st_shift                                  (4)
#define  ISO_MISC_DDC4_DDC_SFSR_ffdifu_st_shift                                  (3)
#define  ISO_MISC_DDC4_DDC_SFSR_ffdine_st_shift                                  (2)
#define  ISO_MISC_DDC4_DDC_SFSR_ffdouf_st_mask                                   (0x00000080)
#define  ISO_MISC_DDC4_DDC_SFSR_ffdiof_st_mask                                   (0x00000040)
#define  ISO_MISC_DDC4_DDC_SFSR_ffdonf_st_mask                                   (0x00000020)
#define  ISO_MISC_DDC4_DDC_SFSR_ffdoet_st_mask                                   (0x00000010)
#define  ISO_MISC_DDC4_DDC_SFSR_ffdifu_st_mask                                   (0x00000008)
#define  ISO_MISC_DDC4_DDC_SFSR_ffdine_st_mask                                   (0x00000004)
#define  ISO_MISC_DDC4_DDC_SFSR_ffdouf_st(data)                                  (0x00000080&((data)<<7))
#define  ISO_MISC_DDC4_DDC_SFSR_ffdiof_st(data)                                  (0x00000040&((data)<<6))
#define  ISO_MISC_DDC4_DDC_SFSR_ffdonf_st(data)                                  (0x00000020&((data)<<5))
#define  ISO_MISC_DDC4_DDC_SFSR_ffdoet_st(data)                                  (0x00000010&((data)<<4))
#define  ISO_MISC_DDC4_DDC_SFSR_ffdifu_st(data)                                  (0x00000008&((data)<<3))
#define  ISO_MISC_DDC4_DDC_SFSR_ffdine_st(data)                                  (0x00000004&((data)<<2))
#define  ISO_MISC_DDC4_DDC_SFSR_get_ffdouf_st(data)                              ((0x00000080&(data))>>7)
#define  ISO_MISC_DDC4_DDC_SFSR_get_ffdiof_st(data)                              ((0x00000040&(data))>>6)
#define  ISO_MISC_DDC4_DDC_SFSR_get_ffdonf_st(data)                              ((0x00000020&(data))>>5)
#define  ISO_MISC_DDC4_DDC_SFSR_get_ffdoet_st(data)                              ((0x00000010&(data))>>4)
#define  ISO_MISC_DDC4_DDC_SFSR_get_ffdifu_st(data)                              ((0x00000008&(data))>>3)
#define  ISO_MISC_DDC4_DDC_SFSR_get_ffdine_st(data)                              ((0x00000004&(data))>>2)

#define  ISO_MISC_DDC4_DDC_SFIR                                                  0x18061360
#define  ISO_MISC_DDC4_DDC_SFIR_reg_addr                                         "0xB8061360"
#define  ISO_MISC_DDC4_DDC_SFIR_reg                                              0xB8061360
#define  ISO_MISC_DDC4_DDC_SFIR_inst_addr                                        "0x0018"
#define  set_ISO_MISC_DDC4_DDC_SFIR_reg(data)                                    (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFIR_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_SFIR_reg                                          (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_SFIR_reg))
#define  ISO_MISC_DDC4_DDC_SFIR_ffdouf_ie_shift                                  (7)
#define  ISO_MISC_DDC4_DDC_SFIR_ffdiof_ie_shift                                  (6)
#define  ISO_MISC_DDC4_DDC_SFIR_ffdonf_ie_shift                                  (5)
#define  ISO_MISC_DDC4_DDC_SFIR_ffdoet_ie_shift                                  (4)
#define  ISO_MISC_DDC4_DDC_SFIR_ffdifu_ie_shift                                  (3)
#define  ISO_MISC_DDC4_DDC_SFIR_ffdine_ie_shift                                  (2)
#define  ISO_MISC_DDC4_DDC_SFIR_cippt_ie_shift                                   (1)
#define  ISO_MISC_DDC4_DDC_SFIR_cispt_ie_shift                                   (0)
#define  ISO_MISC_DDC4_DDC_SFIR_ffdouf_ie_mask                                   (0x00000080)
#define  ISO_MISC_DDC4_DDC_SFIR_ffdiof_ie_mask                                   (0x00000040)
#define  ISO_MISC_DDC4_DDC_SFIR_ffdonf_ie_mask                                   (0x00000020)
#define  ISO_MISC_DDC4_DDC_SFIR_ffdoet_ie_mask                                   (0x00000010)
#define  ISO_MISC_DDC4_DDC_SFIR_ffdifu_ie_mask                                   (0x00000008)
#define  ISO_MISC_DDC4_DDC_SFIR_ffdine_ie_mask                                   (0x00000004)
#define  ISO_MISC_DDC4_DDC_SFIR_cippt_ie_mask                                    (0x00000002)
#define  ISO_MISC_DDC4_DDC_SFIR_cispt_ie_mask                                    (0x00000001)
#define  ISO_MISC_DDC4_DDC_SFIR_ffdouf_ie(data)                                  (0x00000080&((data)<<7))
#define  ISO_MISC_DDC4_DDC_SFIR_ffdiof_ie(data)                                  (0x00000040&((data)<<6))
#define  ISO_MISC_DDC4_DDC_SFIR_ffdonf_ie(data)                                  (0x00000020&((data)<<5))
#define  ISO_MISC_DDC4_DDC_SFIR_ffdoet_ie(data)                                  (0x00000010&((data)<<4))
#define  ISO_MISC_DDC4_DDC_SFIR_ffdifu_ie(data)                                  (0x00000008&((data)<<3))
#define  ISO_MISC_DDC4_DDC_SFIR_ffdine_ie(data)                                  (0x00000004&((data)<<2))
#define  ISO_MISC_DDC4_DDC_SFIR_cippt_ie(data)                                   (0x00000002&((data)<<1))
#define  ISO_MISC_DDC4_DDC_SFIR_cispt_ie(data)                                   (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_SFIR_get_ffdouf_ie(data)                              ((0x00000080&(data))>>7)
#define  ISO_MISC_DDC4_DDC_SFIR_get_ffdiof_ie(data)                              ((0x00000040&(data))>>6)
#define  ISO_MISC_DDC4_DDC_SFIR_get_ffdonf_ie(data)                              ((0x00000020&(data))>>5)
#define  ISO_MISC_DDC4_DDC_SFIR_get_ffdoet_ie(data)                              ((0x00000010&(data))>>4)
#define  ISO_MISC_DDC4_DDC_SFIR_get_ffdifu_ie(data)                              ((0x00000008&(data))>>3)
#define  ISO_MISC_DDC4_DDC_SFIR_get_ffdine_ie(data)                              ((0x00000004&(data))>>2)
#define  ISO_MISC_DDC4_DDC_SFIR_get_cippt_ie(data)                               ((0x00000002&(data))>>1)
#define  ISO_MISC_DDC4_DDC_SFIR_get_cispt_ie(data)                               (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_FSMS                                                  0x18061364
#define  ISO_MISC_DDC4_DDC_FSMS_reg_addr                                         "0xB8061364"
#define  ISO_MISC_DDC4_DDC_FSMS_reg                                              0xB8061364
#define  ISO_MISC_DDC4_DDC_FSMS_inst_addr                                        "0x0019"
#define  set_ISO_MISC_DDC4_DDC_FSMS_reg(data)                                    (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_FSMS_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_FSMS_reg                                          (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_FSMS_reg))
#define  ISO_MISC_DDC4_DDC_FSMS_cmdfsm_st_shift                                  (0)
#define  ISO_MISC_DDC4_DDC_FSMS_cmdfsm_st_mask                                   (0x000000FF)
#define  ISO_MISC_DDC4_DDC_FSMS_cmdfsm_st(data)                                  (0x000000FF&(data))
#define  ISO_MISC_DDC4_DDC_FSMS_get_cmdfsm_st(data)                              (0x000000FF&(data))

#define  ISO_MISC_DDC4_DDC_Dummy                                                 0x18061368
#define  ISO_MISC_DDC4_DDC_Dummy_reg_addr                                        "0xB8061368"
#define  ISO_MISC_DDC4_DDC_Dummy_reg                                             0xB8061368
#define  ISO_MISC_DDC4_DDC_Dummy_inst_addr                                       "0x001A"
#define  set_ISO_MISC_DDC4_DDC_Dummy_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_Dummy_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_Dummy_reg                                         (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_Dummy_reg))
#define  ISO_MISC_DDC4_DDC_Dummy_dummy_7_1_shift                                 (1)
#define  ISO_MISC_DDC4_DDC_Dummy_ls_0_shift                                      (0)
#define  ISO_MISC_DDC4_DDC_Dummy_dummy_7_1_mask                                  (0x000000FE)
#define  ISO_MISC_DDC4_DDC_Dummy_ls_0_mask                                       (0x00000001)
#define  ISO_MISC_DDC4_DDC_Dummy_dummy_7_1(data)                                 (0x000000FE&((data)<<1))
#define  ISO_MISC_DDC4_DDC_Dummy_ls_0(data)                                      (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_Dummy_get_dummy_7_1(data)                             ((0x000000FE&(data))>>1)
#define  ISO_MISC_DDC4_DDC_Dummy_get_ls_0(data)                                  (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN                                 0x18061370
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_reg_addr                        "0xB8061370"
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_reg                             0xB8061370
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_inst_addr                       "0x001B"
#define  set_ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_reg(data)                   (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_reg                         (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_reg))
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_start_irq_en_shift              (1)
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_stop_irq_en_shift               (0)
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_start_irq_en_mask               (0x00000002)
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_stop_irq_en_mask                (0x00000001)
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_start_irq_en(data)              (0x00000002&((data)<<1))
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_stop_irq_en(data)               (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_get_start_irq_en(data)          ((0x00000002&(data))>>1)
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_IRQ_EN_get_stop_irq_en(data)           (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX                                    0x18061374
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_reg_addr                           "0xB8061374"
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_reg                                0xB8061374
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_inst_addr                          "0x001C"
#define  set_ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_reg(data)                      (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_reg                            (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_reg))
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_start_shift                        (1)
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_stop_shift                         (0)
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_start_mask                         (0x00000002)
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_stop_mask                          (0x00000001)
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_start(data)                        (0x00000002&((data)<<1))
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_stop(data)                         (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_get_start(data)                    ((0x00000002&(data))>>1)
#define  ISO_MISC_DDC4_DDC_EDID_SRAM_READ_AUX_get_stop(data)                     (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_BIST_MODE                                             0x18061378
#define  ISO_MISC_DDC4_DDC_BIST_MODE_reg_addr                                    "0xB8061378"
#define  ISO_MISC_DDC4_DDC_BIST_MODE_reg                                         0xB8061378
#define  ISO_MISC_DDC4_DDC_BIST_MODE_inst_addr                                   "0x001D"
#define  set_ISO_MISC_DDC4_DDC_BIST_MODE_reg(data)                               (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_BIST_MODE_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_BIST_MODE_reg                                     (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_BIST_MODE_reg))
#define  ISO_MISC_DDC4_DDC_BIST_MODE_ddc_bist_mode_shift                         (0)
#define  ISO_MISC_DDC4_DDC_BIST_MODE_ddc_bist_mode_mask                          (0x00000001)
#define  ISO_MISC_DDC4_DDC_BIST_MODE_ddc_bist_mode(data)                         (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_BIST_MODE_get_ddc_bist_mode(data)                     (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_BIST_DONE                                             0x1806137C
#define  ISO_MISC_DDC4_DDC_BIST_DONE_reg_addr                                    "0xB806137C"
#define  ISO_MISC_DDC4_DDC_BIST_DONE_reg                                         0xB806137C
#define  ISO_MISC_DDC4_DDC_BIST_DONE_inst_addr                                   "0x001E"
#define  set_ISO_MISC_DDC4_DDC_BIST_DONE_reg(data)                               (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_BIST_DONE_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_BIST_DONE_reg                                     (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_BIST_DONE_reg))
#define  ISO_MISC_DDC4_DDC_BIST_DONE_ddc_bist_done_shift                         (0)
#define  ISO_MISC_DDC4_DDC_BIST_DONE_ddc_bist_done_mask                          (0x00000001)
#define  ISO_MISC_DDC4_DDC_BIST_DONE_ddc_bist_done(data)                         (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_BIST_DONE_get_ddc_bist_done(data)                     (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_BIST_FAIL                                             0x18061380
#define  ISO_MISC_DDC4_DDC_BIST_FAIL_reg_addr                                    "0xB8061380"
#define  ISO_MISC_DDC4_DDC_BIST_FAIL_reg                                         0xB8061380
#define  ISO_MISC_DDC4_DDC_BIST_FAIL_inst_addr                                   "0x001F"
#define  set_ISO_MISC_DDC4_DDC_BIST_FAIL_reg(data)                               (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_BIST_FAIL_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_BIST_FAIL_reg                                     (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_BIST_FAIL_reg))
#define  ISO_MISC_DDC4_DDC_BIST_FAIL_ddc_bist_fail_shift                         (0)
#define  ISO_MISC_DDC4_DDC_BIST_FAIL_ddc_bist_fail_mask                          (0x00000001)
#define  ISO_MISC_DDC4_DDC_BIST_FAIL_ddc_bist_fail(data)                         (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_BIST_FAIL_get_ddc_bist_fail(data)                     (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_DRF_MODE                                              0x18061384
#define  ISO_MISC_DDC4_DDC_DRF_MODE_reg_addr                                     "0xB8061384"
#define  ISO_MISC_DDC4_DDC_DRF_MODE_reg                                          0xB8061384
#define  ISO_MISC_DDC4_DDC_DRF_MODE_inst_addr                                    "0x0020"
#define  set_ISO_MISC_DDC4_DDC_DRF_MODE_reg(data)                                (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_DRF_MODE_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_DRF_MODE_reg                                      (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_DRF_MODE_reg))
#define  ISO_MISC_DDC4_DDC_DRF_MODE_ddc_drf_mode_shift                           (0)
#define  ISO_MISC_DDC4_DDC_DRF_MODE_ddc_drf_mode_mask                            (0x00000001)
#define  ISO_MISC_DDC4_DDC_DRF_MODE_ddc_drf_mode(data)                           (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_DRF_MODE_get_ddc_drf_mode(data)                       (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_DRF_RESUME                                            0x18061388
#define  ISO_MISC_DDC4_DDC_DRF_RESUME_reg_addr                                   "0xB8061388"
#define  ISO_MISC_DDC4_DDC_DRF_RESUME_reg                                        0xB8061388
#define  ISO_MISC_DDC4_DDC_DRF_RESUME_inst_addr                                  "0x0021"
#define  set_ISO_MISC_DDC4_DDC_DRF_RESUME_reg(data)                              (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_DRF_RESUME_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_DRF_RESUME_reg                                    (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_DRF_RESUME_reg))
#define  ISO_MISC_DDC4_DDC_DRF_RESUME_ddc_drf_resume_shift                       (0)
#define  ISO_MISC_DDC4_DDC_DRF_RESUME_ddc_drf_resume_mask                        (0x00000001)
#define  ISO_MISC_DDC4_DDC_DRF_RESUME_ddc_drf_resume(data)                       (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_DRF_RESUME_get_ddc_drf_resume(data)                   (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_DRF_DONE                                              0x1806138C
#define  ISO_MISC_DDC4_DDC_DRF_DONE_reg_addr                                     "0xB806138C"
#define  ISO_MISC_DDC4_DDC_DRF_DONE_reg                                          0xB806138C
#define  ISO_MISC_DDC4_DDC_DRF_DONE_inst_addr                                    "0x0022"
#define  set_ISO_MISC_DDC4_DDC_DRF_DONE_reg(data)                                (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_DRF_DONE_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_DRF_DONE_reg                                      (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_DRF_DONE_reg))
#define  ISO_MISC_DDC4_DDC_DRF_DONE_ddc_drf_done_shift                           (0)
#define  ISO_MISC_DDC4_DDC_DRF_DONE_ddc_drf_done_mask                            (0x00000001)
#define  ISO_MISC_DDC4_DDC_DRF_DONE_ddc_drf_done(data)                           (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_DRF_DONE_get_ddc_drf_done(data)                       (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_DRF_PAUSE                                             0x18061390
#define  ISO_MISC_DDC4_DDC_DRF_PAUSE_reg_addr                                    "0xB8061390"
#define  ISO_MISC_DDC4_DDC_DRF_PAUSE_reg                                         0xB8061390
#define  ISO_MISC_DDC4_DDC_DRF_PAUSE_inst_addr                                   "0x0023"
#define  set_ISO_MISC_DDC4_DDC_DRF_PAUSE_reg(data)                               (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_DRF_PAUSE_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_DRF_PAUSE_reg                                     (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_DRF_PAUSE_reg))
#define  ISO_MISC_DDC4_DDC_DRF_PAUSE_ddc_drf_pause_shift                         (0)
#define  ISO_MISC_DDC4_DDC_DRF_PAUSE_ddc_drf_pause_mask                          (0x00000001)
#define  ISO_MISC_DDC4_DDC_DRF_PAUSE_ddc_drf_pause(data)                         (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_DRF_PAUSE_get_ddc_drf_pause(data)                     (0x00000001&(data))

#define  ISO_MISC_DDC4_DDC_DRF_FAIL                                              0x18061394
#define  ISO_MISC_DDC4_DDC_DRF_FAIL_reg_addr                                     "0xB8061394"
#define  ISO_MISC_DDC4_DDC_DRF_FAIL_reg                                          0xB8061394
#define  ISO_MISC_DDC4_DDC_DRF_FAIL_inst_addr                                    "0x0024"
#define  set_ISO_MISC_DDC4_DDC_DRF_FAIL_reg(data)                                (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_DRF_FAIL_reg)=data)
#define  get_ISO_MISC_DDC4_DDC_DRF_FAIL_reg                                      (*((volatile unsigned int*)ISO_MISC_DDC4_DDC_DRF_FAIL_reg))
#define  ISO_MISC_DDC4_DDC_DRF_FAIL_ddc_drf_fail_shift                           (0)
#define  ISO_MISC_DDC4_DDC_DRF_FAIL_ddc_drf_fail_mask                            (0x00000001)
#define  ISO_MISC_DDC4_DDC_DRF_FAIL_ddc_drf_fail(data)                           (0x00000001&(data))
#define  ISO_MISC_DDC4_DDC_DRF_FAIL_get_ddc_drf_fail(data)                       (0x00000001&(data))

#define  ISO_MISC_DDC4_CMDERR_SOURCE                                             0x18061398
#define  ISO_MISC_DDC4_CMDERR_SOURCE_reg_addr                                    "0xB8061398"
#define  ISO_MISC_DDC4_CMDERR_SOURCE_reg                                         0xB8061398
#define  ISO_MISC_DDC4_CMDERR_SOURCE_inst_addr                                   "0x0025"
#define  set_ISO_MISC_DDC4_CMDERR_SOURCE_reg(data)                               (*((volatile unsigned int*)ISO_MISC_DDC4_CMDERR_SOURCE_reg)=data)
#define  get_ISO_MISC_DDC4_CMDERR_SOURCE_reg                                     (*((volatile unsigned int*)ISO_MISC_DDC4_CMDERR_SOURCE_reg))
#define  ISO_MISC_DDC4_CMDERR_SOURCE_read_stop_shift                             (3)
#define  ISO_MISC_DDC4_CMDERR_SOURCE_read_ack_stop_shift                         (2)
#define  ISO_MISC_DDC4_CMDERR_SOURCE_write_data_lost_shift                       (1)
#define  ISO_MISC_DDC4_CMDERR_SOURCE_slv_addr_lost_shift                         (0)
#define  ISO_MISC_DDC4_CMDERR_SOURCE_read_stop_mask                              (0x00000008)
#define  ISO_MISC_DDC4_CMDERR_SOURCE_read_ack_stop_mask                          (0x00000004)
#define  ISO_MISC_DDC4_CMDERR_SOURCE_write_data_lost_mask                        (0x00000002)
#define  ISO_MISC_DDC4_CMDERR_SOURCE_slv_addr_lost_mask                          (0x00000001)
#define  ISO_MISC_DDC4_CMDERR_SOURCE_read_stop(data)                             (0x00000008&((data)<<3))
#define  ISO_MISC_DDC4_CMDERR_SOURCE_read_ack_stop(data)                         (0x00000004&((data)<<2))
#define  ISO_MISC_DDC4_CMDERR_SOURCE_write_data_lost(data)                       (0x00000002&((data)<<1))
#define  ISO_MISC_DDC4_CMDERR_SOURCE_slv_addr_lost(data)                         (0x00000001&(data))
#define  ISO_MISC_DDC4_CMDERR_SOURCE_get_read_stop(data)                         ((0x00000008&(data))>>3)
#define  ISO_MISC_DDC4_CMDERR_SOURCE_get_read_ack_stop(data)                     ((0x00000004&(data))>>2)
#define  ISO_MISC_DDC4_CMDERR_SOURCE_get_write_data_lost(data)                   ((0x00000002&(data))>>1)
#define  ISO_MISC_DDC4_CMDERR_SOURCE_get_slv_addr_lost(data)                     (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ISO_MISC_DDC4 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cmderr_ie:1;
        RBus_UInt32  timeout_en:1;
        RBus_UInt32  debounce_mode:2;
        RBus_UInt32  timeout_ie:1;
        RBus_UInt32  retime_m:3;
    };
}iso_misc_ddc4_i2c_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cmderr:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  finish:1;
        RBus_UInt32  timeout:1;
        RBus_UInt32  res3:3;
    };
}iso_misc_ddc4_i2c_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  timeout_val:8;
    };
}iso_misc_ddc4_i2c_tr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  edid_address:3;
        RBus_UInt32  finish_int_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  edid_srwen:1;
        RBus_UInt32  edid_en:1;
    };
}iso_misc_ddc4_edid_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18061310_7_0:8;
    };
}iso_misc_ddc4_ddc_vcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  edid_sadr:8;
    };
}iso_misc_ddc4_edid_imswsar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  edid_eadr:8;
    };
}iso_misc_ddc4_edid_imswear_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  edidmode:1;
        RBus_UInt32  edidsubaddress:1;
        RBus_UInt32  edidstop:1;
        RBus_UInt32  i2c_m_rd_st_ie:1;
        RBus_UInt32  i2c_m_rd_sp_ie:1;
        RBus_UInt32  edidsubaddress_ie:1;
        RBus_UInt32  edidstop_ie:1;
    };
}iso_misc_ddc4_edid_ir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  edidap:9;
    };
}iso_misc_ddc4_ddc_sir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ediddp:8;
    };
}iso_misc_ddc4_ddc_sap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ddc_bist_rstn:1;
        RBus_UInt32  ddc_bist_rme:1;
        RBus_UInt32  ddc_bist_rm:4;
    };
}iso_misc_ddc4_ddc_bistcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  segpt_latie:1;
        RBus_UInt32  dataoutputdelay_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  i2c_m_rd_st_sts:1;
        RBus_UInt32  i2c_m_rd_sp_sts:1;
        RBus_UInt32  sgid_en:1;
    };
}iso_misc_ddc4_ddc_scr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sgid_address:7;
        RBus_UInt32  sgid_dtrden:1;
    };
}iso_misc_ddc4_ddc_ssar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  segpt_latched:1;
        RBus_UInt32  seg_pt:7;
    };
}iso_misc_ddc4_ddc_spr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  special_mode:1;
        RBus_UInt32  doffpt_reset:1;
        RBus_UInt32  diffpt_reset:1;
        RBus_UInt32  ciid_en:1;
    };
}iso_misc_ddc4_ddc_sfcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ciid_address:7;
        RBus_UInt32  cirws_current:1;
    };
}iso_misc_ddc4_ddc_sfsar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ciiddp:8;
    };
}iso_misc_ddc4_ddc_sfdr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  cirws_2nd:1;
        RBus_UInt32  cirws_1st:1;
        RBus_UInt32  cippt_2nd:1;
        RBus_UInt32  cispt_2nd:1;
        RBus_UInt32  cippt_1st:1;
        RBus_UInt32  cispt_1st:1;
    };
}iso_misc_ddc4_ddc_sfbsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  ffdi_dlen:5;
    };
}iso_misc_ddc4_ddc_sfiblr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  diff_wpt:4;
        RBus_UInt32  diff_rpt:4;
    };
}iso_misc_ddc4_ddc_sfibrwpr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  diffstop_pt:4;
    };
}iso_misc_ddc4_ddc_sfibswpr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  ffdo_dlen:5;
    };
}iso_misc_ddc4_ddc_sfobsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  doff_wpt:4;
        RBus_UInt32  doff_rpt:4;
    };
}iso_misc_ddc4_ddc_sfobrwpr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ffdouf_st:1;
        RBus_UInt32  ffdiof_st:1;
        RBus_UInt32  ffdonf_st:1;
        RBus_UInt32  ffdoet_st:1;
        RBus_UInt32  ffdifu_st:1;
        RBus_UInt32  ffdine_st:1;
        RBus_UInt32  res2:2;
    };
}iso_misc_ddc4_ddc_sfsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ffdouf_ie:1;
        RBus_UInt32  ffdiof_ie:1;
        RBus_UInt32  ffdonf_ie:1;
        RBus_UInt32  ffdoet_ie:1;
        RBus_UInt32  ffdifu_ie:1;
        RBus_UInt32  ffdine_ie:1;
        RBus_UInt32  cippt_ie:1;
        RBus_UInt32  cispt_ie:1;
    };
}iso_misc_ddc4_ddc_sfir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cmdfsm_st:8;
    };
}iso_misc_ddc4_ddc_fsms_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18061368_7_1:7;
        RBus_UInt32  ls_0:1;
    };
}iso_misc_ddc4_ddc_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  start_irq_en:1;
        RBus_UInt32  stop_irq_en:1;
    };
}iso_misc_ddc4_ddc_edid_sram_read_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  start:1;
        RBus_UInt32  stop:1;
    };
}iso_misc_ddc4_ddc_edid_sram_read_aux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ddc_bist_mode:1;
    };
}iso_misc_ddc4_ddc_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ddc_bist_done:1;
    };
}iso_misc_ddc4_ddc_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ddc_bist_fail:1;
    };
}iso_misc_ddc4_ddc_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ddc_drf_mode:1;
    };
}iso_misc_ddc4_ddc_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ddc_drf_resume:1;
    };
}iso_misc_ddc4_ddc_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ddc_drf_done:1;
    };
}iso_misc_ddc4_ddc_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ddc_drf_pause:1;
    };
}iso_misc_ddc4_ddc_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ddc_drf_fail:1;
    };
}iso_misc_ddc4_ddc_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  read_stop:1;
        RBus_UInt32  read_ack_stop:1;
        RBus_UInt32  write_data_lost:1;
        RBus_UInt32  slv_addr_lost:1;
    };
}iso_misc_ddc4_cmderr_source_RBUS;

#else //apply LITTLE_ENDIAN

//======ISO_MISC_DDC4 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  retime_m:3;
        RBus_UInt32  timeout_ie:1;
        RBus_UInt32  debounce_mode:2;
        RBus_UInt32  timeout_en:1;
        RBus_UInt32  cmderr_ie:1;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_i2c_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  timeout:1;
        RBus_UInt32  finish:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cmderr:1;
        RBus_UInt32  res3:24;
    };
}iso_misc_ddc4_i2c_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timeout_val:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_i2c_tr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edid_en:1;
        RBus_UInt32  edid_srwen:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  finish_int_en:1;
        RBus_UInt32  edid_address:3;
        RBus_UInt32  res3:24;
    };
}iso_misc_ddc4_edid_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18061310_7_0:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_ddc_vcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edid_sadr:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_edid_imswsar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edid_eadr:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_edid_imswear_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edidstop_ie:1;
        RBus_UInt32  edidsubaddress_ie:1;
        RBus_UInt32  i2c_m_rd_sp_ie:1;
        RBus_UInt32  i2c_m_rd_st_ie:1;
        RBus_UInt32  edidstop:1;
        RBus_UInt32  edidsubaddress:1;
        RBus_UInt32  edidmode:1;
        RBus_UInt32  res1:25;
    };
}iso_misc_ddc4_edid_ir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edidap:9;
        RBus_UInt32  res1:23;
    };
}iso_misc_ddc4_ddc_sir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ediddp:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_ddc_sap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_bist_rm:4;
        RBus_UInt32  ddc_bist_rme:1;
        RBus_UInt32  ddc_bist_rstn:1;
        RBus_UInt32  res1:26;
    };
}iso_misc_ddc4_ddc_bistcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sgid_en:1;
        RBus_UInt32  i2c_m_rd_sp_sts:1;
        RBus_UInt32  i2c_m_rd_st_sts:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dataoutputdelay_sel:3;
        RBus_UInt32  segpt_latie:1;
        RBus_UInt32  res2:24;
    };
}iso_misc_ddc4_ddc_scr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sgid_dtrden:1;
        RBus_UInt32  sgid_address:7;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_ddc_ssar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg_pt:7;
        RBus_UInt32  segpt_latched:1;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_ddc_spr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ciid_en:1;
        RBus_UInt32  diffpt_reset:1;
        RBus_UInt32  doffpt_reset:1;
        RBus_UInt32  special_mode:1;
        RBus_UInt32  res1:28;
    };
}iso_misc_ddc4_ddc_sfcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cirws_current:1;
        RBus_UInt32  ciid_address:7;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_ddc_sfsar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ciiddp:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_ddc_sfdr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cispt_1st:1;
        RBus_UInt32  cippt_1st:1;
        RBus_UInt32  cispt_2nd:1;
        RBus_UInt32  cippt_2nd:1;
        RBus_UInt32  cirws_1st:1;
        RBus_UInt32  cirws_2nd:1;
        RBus_UInt32  res1:26;
    };
}iso_misc_ddc4_ddc_sfbsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ffdi_dlen:5;
        RBus_UInt32  res1:27;
    };
}iso_misc_ddc4_ddc_sfiblr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_rpt:4;
        RBus_UInt32  diff_wpt:4;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_ddc_sfibrwpr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diffstop_pt:4;
        RBus_UInt32  res1:28;
    };
}iso_misc_ddc4_ddc_sfibswpr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ffdo_dlen:5;
        RBus_UInt32  res1:27;
    };
}iso_misc_ddc4_ddc_sfobsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  doff_rpt:4;
        RBus_UInt32  doff_wpt:4;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_ddc_sfobrwpr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ffdine_st:1;
        RBus_UInt32  ffdifu_st:1;
        RBus_UInt32  ffdoet_st:1;
        RBus_UInt32  ffdonf_st:1;
        RBus_UInt32  ffdiof_st:1;
        RBus_UInt32  ffdouf_st:1;
        RBus_UInt32  res2:24;
    };
}iso_misc_ddc4_ddc_sfsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cispt_ie:1;
        RBus_UInt32  cippt_ie:1;
        RBus_UInt32  ffdine_ie:1;
        RBus_UInt32  ffdifu_ie:1;
        RBus_UInt32  ffdoet_ie:1;
        RBus_UInt32  ffdonf_ie:1;
        RBus_UInt32  ffdiof_ie:1;
        RBus_UInt32  ffdouf_ie:1;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_ddc_sfir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdfsm_st:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_ddc_fsms_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_0:1;
        RBus_UInt32  dummy18061368_7:7;
        RBus_UInt32  res1:24;
    };
}iso_misc_ddc4_ddc_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stop_irq_en:1;
        RBus_UInt32  start_irq_en:1;
        RBus_UInt32  res1:30;
    };
}iso_misc_ddc4_ddc_edid_sram_read_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stop:1;
        RBus_UInt32  start:1;
        RBus_UInt32  res1:30;
    };
}iso_misc_ddc4_ddc_edid_sram_read_aux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_bist_mode:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_ddc4_ddc_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_bist_done:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_ddc4_ddc_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_bist_fail:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_ddc4_ddc_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_drf_mode:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_ddc4_ddc_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_drf_resume:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_ddc4_ddc_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_drf_done:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_ddc4_ddc_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_drf_pause:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_ddc4_ddc_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_drf_fail:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_ddc4_ddc_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  slv_addr_lost:1;
        RBus_UInt32  write_data_lost:1;
        RBus_UInt32  read_ack_stop:1;
        RBus_UInt32  read_stop:1;
        RBus_UInt32  res1:28;
    };
}iso_misc_ddc4_cmderr_source_RBUS;




#endif 


#endif 
