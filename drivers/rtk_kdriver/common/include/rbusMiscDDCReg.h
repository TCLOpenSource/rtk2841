#ifndef _RBUS_MISC_DDC_REG_H_
#define _RBUS_MISC_DDC_REG_H_


// HDMI USE  cloud modify change addr spec MISC
#define DDC1_I2C_CR                                                     0x18061A00
#define DDC1_I2C_CR_reg_addr                                            "0xb8061A00"
#define DDC1_I2C_CR_reg                                                 0xb8061A00
#define DDC1_I2C_CR_inst_addr                                           "0x02C0"
#define DDC1_I2C_CR_inst                                                0x02C0
#define DDC1_I2C_CR_cmderr_ie_shift                                     (7)
#define DDC1_I2C_CR_timeout_en_shift                                    (6)
#define DDC1_I2C_CR_debounce_mode_shift                                 (4)
#define DDC1_I2C_CR_timeout_ie_shift                                    (3)
#define DDC1_I2C_CR_retime_m_shift                                      (0)
#define DDC1_I2C_CR_cmderr_ie_mask                                      (0x00000080)
#define DDC1_I2C_CR_timeout_en_mask                                     (0x00000040)
#define DDC1_I2C_CR_debounce_mode_mask                                  (0x00000030)
#define DDC1_I2C_CR_timeout_ie_mask                                     (0x00000008)
#define DDC1_I2C_CR_retime_m_mask                                       (0x00000007)
#define DDC1_I2C_CR_cmderr_ie(data)                                     (0x00000080&((data)<<7))
#define DDC1_I2C_CR_timeout_en(data)                                    (0x00000040&((data)<<6))
#define DDC1_I2C_CR_debounce_mode(data)                                 (0x00000030&((data)<<4))
#define DDC1_I2C_CR_timeout_ie(data)                                    (0x00000008&((data)<<3))
#define DDC1_I2C_CR_retime_m(data)                                      (0x00000007&(data))
#define DDC1_I2C_CR_get_cmderr_ie(data)                                 ((0x00000080&(data))>>7)
#define DDC1_I2C_CR_get_timeout_en(data)                                ((0x00000040&(data))>>6)
#define DDC1_I2C_CR_get_debounce_mode(data)                             ((0x00000030&(data))>>4)
#define DDC1_I2C_CR_get_timeout_ie(data)                                ((0x00000008&(data))>>3)
#define DDC1_I2C_CR_get_retime_m(data)                                  (0x00000007&(data))





// HDMI USE   cloud modify change addr spec MISC
#define DDC1_EDID_CR                                                    0x18061A0c
#define DDC1_EDID_CR_reg_addr                                           "0xb8061A0c"
#define DDC1_EDID_CR_reg                                                0xb8061A0c
#define DDC1_EDID_CR_inst_addr                                          "0x02C3"
#define DDC1_EDID_CR_inst                                               0x02C3
#define DDC1_EDID_CR_edid_address_shift                                 (5)
#define DDC1_EDID_CR_finish_int_en_shift                                (4)
#define DDC1_EDID_CR_ddc1_force_shift                                   (3)
#define DDC1_EDID_CR_ddc2b_force_shift                                  (2)
#define DDC1_EDID_CR_edid_srwen_shift                                   (1)
#define DDC1_EDID_CR_edid_en_shift                                      (0)
#define DDC1_EDID_CR_edid_address_mask                                  (0x000000E0)
#define DDC1_EDID_CR_finish_int_en_mask                                 (0x00000010)
#define DDC1_EDID_CR_ddc1_force_mask                                    (0x00000008)
#define DDC1_EDID_CR_ddc2b_force_mask                                   (0x00000004)
#define DDC1_EDID_CR_edid_srwen_mask                                    (0x00000002)
#define DDC1_EDID_CR_edid_en_mask                                       (0x00000001)
#define DDC1_EDID_CR_edid_address(data)                                 (0x000000E0&((data)<<5))
#define DDC1_EDID_CR_finish_int_en(data)                                (0x00000010&((data)<<4))
#define DDC1_EDID_CR_ddc1_force(data)                                   (0x00000008&((data)<<3))
#define DDC1_EDID_CR_ddc2b_force(data)                                  (0x00000004&((data)<<2))
#define DDC1_EDID_CR_edid_srwen(data)                                   (0x00000002&((data)<<1))
#define DDC1_EDID_CR_edid_en(data)                                      (0x00000001&(data))
#define DDC1_EDID_CR_get_edid_address(data)                             ((0x000000E0&(data))>>5)
#define DDC1_EDID_CR_get_finish_int_en(data)                            ((0x00000010&(data))>>4)
#define DDC1_EDID_CR_get_ddc1_force(data)                               ((0x00000008&(data))>>3)
#define DDC1_EDID_CR_get_ddc2b_force(data)                              ((0x00000004&(data))>>2)
#define DDC1_EDID_CR_get_edid_srwen(data)                               ((0x00000002&(data))>>1)
#define DDC1_EDID_CR_get_edid_en(data)                                  (0x00000001&(data))


// HDMI USE    cloud modify change addr spec MISC
#define DDC1_DDC_SIR                                                    0x1806A920
#define DDC1_DDC_SIR_reg_addr                                           "0xb806A920"
#define DDC1_DDC_SIR_reg                                                0xb806A920
#define DDC1_DDC_SIR_inst_addr                                          "0x02C8"
#define DDC1_DDC_SIR_inst                                               0x02C8
#define DDC1_DDC_SIR_edidap_shift                                       (0)
#define DDC1_DDC_SIR_edidap_mask                                        (0x000000FF)
#define DDC1_DDC_SIR_edidap(data)                                       (0x000000FF&(data))
#define DDC1_DDC_SIR_get_edidap(data)                                   (0x000000FF&(data))

//HDMI USE      cloud modify change addr spec MISC
#define DDC1_DDC_SAP                                                    0x1806A924
#define DDC1_DDC_SAP_reg_addr                                           "0xb806A924"
#define DDC1_DDC_SAP_reg                                                0xb806A924
#define DDC1_DDC_SAP_inst_addr                                          "0x02C9"
#define DDC1_DDC_SAP_inst                                               0x02C9
#define DDC1_DDC_SAP_ediddp_shift                                       (0)
#define DDC1_DDC_SAP_ediddp_mask                                        (0x000000FF)
#define DDC1_DDC_SAP_ediddp(data)                                       (0x000000FF&(data))
#define DDC1_DDC_SAP_get_ediddp(data)                                   (0x000000FF&(data))


// CBUS USE  cloud modify change addr spec MISC
//Sirius
/*
#define DDC5_CBUS_DDC_CR                                                     0x1801b300
#define DDC5_CBUS_DDC_reg_addr                                            "0xb801b300"
#define DDC5_CBUS_DDC_reg                                                    0xb801b300
*/
#define DDC5_CBUS_DDC_CR                                                     0x1801bb00
#define DDC5_CBUS_DDC_reg_addr                                            "0xb801bb00"
#define DDC5_CBUS_DDC_reg                                                    0xb801bb00

#define REG_EDID_CTL_OFFSET          0x0c
#define REG_DDC_SIR_OFFSET           0x20
#define REG_DDC_SAP_OFFSET          0x24

#endif	//_RBUS_DDC_REG_H_
