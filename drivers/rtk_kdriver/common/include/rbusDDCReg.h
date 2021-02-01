#ifndef _RBUS_DDC_REG_H_
#define _RBUS_DDC_REG_H_



#define ST_I2C_CR                                                     0x18061a00
#define ST_I2C_CR_reg_addr                                            "0xb8061a00"
#define ST_I2C_CR_reg                                                 0xb8061a00
#define ST_I2C_CR_inst_addr                                           "0x02C0"
#define ST_I2C_CR_inst                                                0x02C0
#define ST_I2C_CR_cmderr_ie_shift                                     (7)
#define ST_I2C_CR_timeout_en_shift                                    (6)
#define ST_I2C_CR_debounce_mode_shift                                 (4)
#define ST_I2C_CR_timeout_ie_shift                                    (3)
#define ST_I2C_CR_retime_m_shift                                      (0)
#define ST_I2C_CR_cmderr_ie_mask                                      (0x00000080)
#define ST_I2C_CR_timeout_en_mask                                     (0x00000040)
#define ST_I2C_CR_debounce_mode_mask                                  (0x00000030)
#define ST_I2C_CR_timeout_ie_mask                                     (0x00000008)
#define ST_I2C_CR_retime_m_mask                                       (0x00000007)
#define ST_I2C_CR_cmderr_ie(data)                                     (0x00000080&((data)<<7))
#define ST_I2C_CR_timeout_en(data)                                    (0x00000040&((data)<<6))
#define ST_I2C_CR_debounce_mode(data)                                 (0x00000030&((data)<<4))
#define ST_I2C_CR_timeout_ie(data)                                    (0x00000008&((data)<<3))
#define ST_I2C_CR_retime_m(data)                                      (0x00000007&(data))
#define ST_I2C_CR_get_cmderr_ie(data)                                 ((0x00000080&(data))>>7)
#define ST_I2C_CR_get_timeout_en(data)                                ((0x00000040&(data))>>6)
#define ST_I2C_CR_get_debounce_mode(data)                             ((0x00000030&(data))>>4)
#define ST_I2C_CR_get_timeout_ie(data)                                ((0x00000008&(data))>>3)
#define ST_I2C_CR_get_retime_m(data)                                  (0x00000007&(data))


#define ST_I2C_SR                                                     0x18061a04
#define ST_I2C_SR_reg_addr                                            "0xb8061a04"
#define ST_I2C_SR_reg                                                 0xb8061a04
#define ST_I2C_SR_inst_addr                                           "0x02C1"
#define ST_I2C_SR_inst                                                0x02C1
#define ST_I2C_SR_cmderr_shift                                        (7)
#define ST_I2C_SR_finish_shift                                        (4)
#define ST_I2C_SR_timeout_shift                                       (3)
#define ST_I2C_SR_cmderr_mask                                         (0x00000080)
#define ST_I2C_SR_finish_mask                                         (0x00000010)
#define ST_I2C_SR_timeout_mask                                        (0x00000008)
#define ST_I2C_SR_cmderr(data)                                        (0x00000080&((data)<<7))
#define ST_I2C_SR_finish(data)                                        (0x00000010&((data)<<4))
#define ST_I2C_SR_timeout(data)                                       (0x00000008&((data)<<3))
#define ST_I2C_SR_get_cmderr(data)                                    ((0x00000080&(data))>>7)
#define ST_I2C_SR_get_finish(data)                                    ((0x00000010&(data))>>4)
#define ST_I2C_SR_get_timeout(data)                                   ((0x00000008&(data))>>3)


#define ST_I2C_TR                                                     0x18061a08
#define ST_I2C_TR_reg_addr                                            "0xb8061a08"
#define ST_I2C_TR_reg                                                 0xb8061a08
#define ST_I2C_TR_inst_addr                                           "0x02C2"
#define ST_I2C_TR_inst                                                0x02C2
#define ST_I2C_TR_timeout_val_shift                                   (0)
#define ST_I2C_TR_timeout_val_mask                                    (0x000000FF)
#define ST_I2C_TR_timeout_val(data)                                   (0x000000FF&(data))
#define ST_I2C_TR_get_timeout_val(data)                               (0x000000FF&(data))


#define ST_EDID_CR                                                    0x18061a0c
#define ST_EDID_CR_reg_addr                                           "0xb8061a0c"
#define ST_EDID_CR_reg                                                0xb8061a0c
#define ST_EDID_CR_inst_addr                                          "0x02C3"
#define ST_EDID_CR_inst                                               0x02C3
#define ST_EDID_CR_edid_address_shift                                 (5)
#define ST_EDID_CR_finish_int_en_shift                                (4)
#define ST_EDID_CR_ddc1_force_shift                                   (3)
#define ST_EDID_CR_ddc2b_force_shift                                  (2)
#define ST_EDID_CR_edid_srwen_shift                                   (1)
#define ST_EDID_CR_edid_en_shift                                      (0)
#define ST_EDID_CR_edid_address_mask                                  (0x000000E0)
#define ST_EDID_CR_finish_int_en_mask                                 (0x00000010)
#define ST_EDID_CR_ddc1_force_mask                                    (0x00000008)
#define ST_EDID_CR_ddc2b_force_mask                                   (0x00000004)
#define ST_EDID_CR_edid_srwen_mask                                    (0x00000002)
#define ST_EDID_CR_edid_en_mask                                       (0x00000001)
#define ST_EDID_CR_edid_address(data)                                 (0x000000E0&((data)<<5))
#define ST_EDID_CR_finish_int_en(data)                                (0x00000010&((data)<<4))
#define ST_EDID_CR_ddc1_force(data)                                   (0x00000008&((data)<<3))
#define ST_EDID_CR_ddc2b_force(data)                                  (0x00000004&((data)<<2))
#define ST_EDID_CR_edid_srwen(data)                                   (0x00000002&((data)<<1))
#define ST_EDID_CR_edid_en(data)                                      (0x00000001&(data))
#define ST_EDID_CR_get_edid_address(data)                             ((0x000000E0&(data))>>5)
#define ST_EDID_CR_get_finish_int_en(data)                            ((0x00000010&(data))>>4)
#define ST_EDID_CR_get_ddc1_force(data)                               ((0x00000008&(data))>>3)
#define ST_EDID_CR_get_ddc2b_force(data)                              ((0x00000004&(data))>>2)
#define ST_EDID_CR_get_edid_srwen(data)                               ((0x00000002&(data))>>1)
#define ST_EDID_CR_get_edid_en(data)                                  (0x00000001&(data))


#define ST_DDC_VCR                                                    0x18061a10
#define ST_DDC_VCR_reg_addr                                           "0xb8061a10"
#define ST_DDC_VCR_reg                                                0xb8061a10
#define ST_DDC_VCR_inst_addr                                          "0x02C4"
#define ST_DDC_VCR_inst                                               0x02C4
#define ST_DDC_VCR_ddc1_vcount_shift                                  (0)
#define ST_DDC_VCR_ddc1_vcount_mask                                   (0x000000FF)
#define ST_DDC_VCR_ddc1_vcount(data)                                  (0x000000FF&(data))
#define ST_DDC_VCR_get_ddc1_vcount(data)                              (0x000000FF&(data))


#define ST_EDID_IMSWSAR                                               0x18061a14
#define ST_EDID_IMSWSAR_reg_addr                                      "0xb8061a14"
#define ST_EDID_IMSWSAR_reg                                           0xb8061a14
#define ST_EDID_IMSWSAR_inst_addr                                     "0x02C5"
#define ST_EDID_IMSWSAR_inst                                          0x02C5
#define ST_EDID_IMSWSAR_edid_sadr_shift                               (0)
#define ST_EDID_IMSWSAR_edid_sadr_mask                                (0x000000FF)
#define ST_EDID_IMSWSAR_edid_sadr(data)                               (0x000000FF&(data))
#define ST_EDID_IMSWSAR_get_edid_sadr(data)                           (0x000000FF&(data))


#define ST_EDID_IMSWEAR                                               0x18061a18
#define ST_EDID_IMSWEAR_reg_addr                                      "0xb8061a18"
#define ST_EDID_IMSWEAR_reg                                           0xb8061a18
#define ST_EDID_IMSWEAR_inst_addr                                     "0x02C6"
#define ST_EDID_IMSWEAR_inst                                          0x02C6
#define ST_EDID_IMSWEAR_edid_eadr_shift                               (0)
#define ST_EDID_IMSWEAR_edid_eadr_mask                                (0x000000FF)
#define ST_EDID_IMSWEAR_edid_eadr(data)                               (0x000000FF&(data))
#define ST_EDID_IMSWEAR_get_edid_eadr(data)                           (0x000000FF&(data))


#define ST_EDID_IR                                                    0x18061a1c
#define ST_EDID_IR_reg_addr                                           "0xb8061a1c"
#define ST_EDID_IR_reg                                                0xb8061a1c
#define ST_EDID_IR_inst_addr                                          "0x02C7"
#define ST_EDID_IR_inst                                               0x02C7
#define ST_EDID_IR_edidmode_shift                                     (6)
#define ST_EDID_IR_edidsubaddress_shift                               (5)
#define ST_EDID_IR_edidstop_shift                                     (4)
#define ST_EDID_IR_edidsubaddress_ie_shift                            (1)
#define ST_EDID_IR_edidstop_ie_shift                                  (0)
#define ST_EDID_IR_edidmode_mask                                      (0x00000040)
#define ST_EDID_IR_edidsubaddress_mask                                (0x00000020)
#define ST_EDID_IR_edidstop_mask                                      (0x00000010)
#define ST_EDID_IR_edidsubaddress_ie_mask                             (0x00000002)
#define ST_EDID_IR_edidstop_ie_mask                                   (0x00000001)
#define ST_EDID_IR_edidmode(data)                                     (0x00000040&((data)<<6))
#define ST_EDID_IR_edidsubaddress(data)                               (0x00000020&((data)<<5))
#define ST_EDID_IR_edidstop(data)                                     (0x00000010&((data)<<4))
#define ST_EDID_IR_edidsubaddress_ie(data)                            (0x00000002&((data)<<1))
#define ST_EDID_IR_edidstop_ie(data)                                  (0x00000001&(data))
#define ST_EDID_IR_get_edidmode(data)                                 ((0x00000040&(data))>>6)
#define ST_EDID_IR_get_edidsubaddress(data)                           ((0x00000020&(data))>>5)
#define ST_EDID_IR_get_edidstop(data)                                 ((0x00000010&(data))>>4)
#define ST_EDID_IR_get_edidsubaddress_ie(data)                        ((0x00000002&(data))>>1)
#define ST_EDID_IR_get_edidstop_ie(data)                              (0x00000001&(data))


#define ST_DDC_SIR                                                    0x18061a20
#define ST_DDC_SIR_reg_addr                                           "0xb8061a20"
#define ST_DDC_SIR_reg                                                0xb8061a20
#define ST_DDC_SIR_inst_addr                                          "0x02C8"
#define ST_DDC_SIR_inst                                               0x02C8
#define ST_DDC_SIR_edidap_shift                                       (0)
#define ST_DDC_SIR_edidap_mask                                        (0x000000FF)
#define ST_DDC_SIR_edidap(data)                                       (0x000000FF&(data))
#define ST_DDC_SIR_get_edidap(data)                                   (0x000000FF&(data))


#define ST_DDC_SAP                                                    0x18061a24
#define ST_DDC_SAP_reg_addr                                           "0xb8061a24"
#define ST_DDC_SAP_reg                                                0xb8061a24
#define ST_DDC_SAP_inst_addr                                          "0x02C9"
#define ST_DDC_SAP_inst                                               0x02C9
#define ST_DDC_SAP_ediddp_shift                                       (0)
#define ST_DDC_SAP_ediddp_mask                                        (0x000000FF)
#define ST_DDC_SAP_ediddp(data)                                       (0x000000FF&(data))
#define ST_DDC_SAP_get_ediddp(data)                                   (0x000000FF&(data))


#define ST_DDC_BISTCR                                                 0x18061a28
#define ST_DDC_BISTCR_reg_addr                                        "0xb8061a28"
#define ST_DDC_BISTCR_reg                                             0xb8061a28
#define ST_DDC_BISTCR_inst_addr                                       "0x02CA"
#define ST_DDC_BISTCR_inst                                            0x02CA
#define ST_DDC_BISTCR_bist_fail_shift                                 (5)
#define ST_DDC_BISTCR_bist_done_shift                                 (4)
#define ST_DDC_BISTCR_bist_rstn_shift                                 (1)
#define ST_DDC_BISTCR_bist_mode_shift                                 (0)
#define ST_DDC_BISTCR_bist_fail_mask                                  (0x00000020)
#define ST_DDC_BISTCR_bist_done_mask                                  (0x00000010)
#define ST_DDC_BISTCR_bist_rstn_mask                                  (0x00000002)
#define ST_DDC_BISTCR_bist_mode_mask                                  (0x00000001)
#define ST_DDC_BISTCR_bist_fail(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_BISTCR_bist_done(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_BISTCR_bist_rstn(data)                                 (0x00000002&((data)<<1))
#define ST_DDC_BISTCR_bist_mode(data)                                 (0x00000001&(data))
#define ST_DDC_BISTCR_get_bist_fail(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_BISTCR_get_bist_done(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_BISTCR_get_bist_rstn(data)                             ((0x00000002&(data))>>1)
#define ST_DDC_BISTCR_get_bist_mode(data)                             (0x00000001&(data))


#define ST_DDC_SCR                                                    0x18061a2c
#define ST_DDC_SCR_reg_addr                                           "0xb8061a2c"
#define ST_DDC_SCR_reg                                                0xb8061a2c
#define ST_DDC_SCR_inst_addr                                          "0x02CB"
#define ST_DDC_SCR_inst                                               0x02CB
#define ST_DDC_SCR_segpt_latie_shift                                  (7)
#define ST_DDC_SCR_sgid_en_shift                                      (0)
#define ST_DDC_SCR_segpt_latie_mask                                   (0x00000080)
#define ST_DDC_SCR_sgid_en_mask                                       (0x00000001)
#define ST_DDC_SCR_segpt_latie(data)                                  (0x00000080&((data)<<7))
#define ST_DDC_SCR_sgid_en(data)                                      (0x00000001&(data))
#define ST_DDC_SCR_get_segpt_latie(data)                              ((0x00000080&(data))>>7)
#define ST_DDC_SCR_get_sgid_en(data)                                  (0x00000001&(data))


#define ST_DDC_SSAR                                                   0x18061a30
#define ST_DDC_SSAR_reg_addr                                          "0xb8061a30"
#define ST_DDC_SSAR_reg                                               0xb8061a30
#define ST_DDC_SSAR_inst_addr                                         "0x02CC"
#define ST_DDC_SSAR_inst                                              0x02CC
#define ST_DDC_SSAR_sgid_address_shift                                (1)
#define ST_DDC_SSAR_sgid_dtrden_shift                                 (0)
#define ST_DDC_SSAR_sgid_address_mask                                 (0x000000FE)
#define ST_DDC_SSAR_sgid_dtrden_mask                                  (0x00000001)
#define ST_DDC_SSAR_sgid_address(data)                                (0x000000FE&((data)<<1))
#define ST_DDC_SSAR_sgid_dtrden(data)                                 (0x00000001&(data))
#define ST_DDC_SSAR_get_sgid_address(data)                            ((0x000000FE&(data))>>1)
#define ST_DDC_SSAR_get_sgid_dtrden(data)                             (0x00000001&(data))


#define ST_DDC_SPR                                                    0x18061a34
#define ST_DDC_SPR_reg_addr                                           "0xb8061a34"
#define ST_DDC_SPR_reg                                                0xb8061a34
#define ST_DDC_SPR_inst_addr                                          "0x02CD"
#define ST_DDC_SPR_inst                                               0x02CD
#define ST_DDC_SPR_segpt_latched_shift                                (7)
#define ST_DDC_SPR_seg_pt_shift                                       (0)
#define ST_DDC_SPR_segpt_latched_mask                                 (0x00000080)
#define ST_DDC_SPR_seg_pt_mask                                        (0x0000007F)
#define ST_DDC_SPR_segpt_latched(data)                                (0x00000080&((data)<<7))
#define ST_DDC_SPR_seg_pt(data)                                       (0x0000007F&(data))
#define ST_DDC_SPR_get_segpt_latched(data)                            ((0x00000080&(data))>>7)
#define ST_DDC_SPR_get_seg_pt(data)                                   (0x0000007F&(data))


#define ST_DDC_SFCR                                                   0x18061a38
#define ST_DDC_SFCR_reg_addr                                          "0xb8061a38"
#define ST_DDC_SFCR_reg                                               0xb8061a38
#define ST_DDC_SFCR_inst_addr                                         "0x02CE"
#define ST_DDC_SFCR_inst                                              0x02CE
#define ST_DDC_SFCR_special_mode_shift                                (3)
#define ST_DDC_SFCR_doffpt_reset_shift                                (2)
#define ST_DDC_SFCR_diffpt_reset_shift                                (1)
#define ST_DDC_SFCR_ciid_en_shift                                     (0)
#define ST_DDC_SFCR_special_mode_mask                                 (0x00000008)
#define ST_DDC_SFCR_doffpt_reset_mask                                 (0x00000004)
#define ST_DDC_SFCR_diffpt_reset_mask                                 (0x00000002)
#define ST_DDC_SFCR_ciid_en_mask                                      (0x00000001)
#define ST_DDC_SFCR_special_mode(data)                                (0x00000008&((data)<<3))
#define ST_DDC_SFCR_doffpt_reset(data)                                (0x00000004&((data)<<2))
#define ST_DDC_SFCR_diffpt_reset(data)                                (0x00000002&((data)<<1))
#define ST_DDC_SFCR_ciid_en(data)                                     (0x00000001&(data))
#define ST_DDC_SFCR_get_special_mode(data)                            ((0x00000008&(data))>>3)
#define ST_DDC_SFCR_get_doffpt_reset(data)                            ((0x00000004&(data))>>2)
#define ST_DDC_SFCR_get_diffpt_reset(data)                            ((0x00000002&(data))>>1)
#define ST_DDC_SFCR_get_ciid_en(data)                                 (0x00000001&(data))


#define ST_DDC_SFSAR                                                  0x18061a3c
#define ST_DDC_SFSAR_reg_addr                                         "0xb8061a3c"
#define ST_DDC_SFSAR_reg                                              0xb8061a3c
#define ST_DDC_SFSAR_inst_addr                                        "0x02CF"
#define ST_DDC_SFSAR_inst                                             0x02CF
#define ST_DDC_SFSAR_ciid_address_shift                               (1)
#define ST_DDC_SFSAR_cirws_current_shift                              (0)
#define ST_DDC_SFSAR_ciid_address_mask                                (0x000000FE)
#define ST_DDC_SFSAR_cirws_current_mask                               (0x00000001)
#define ST_DDC_SFSAR_ciid_address(data)                               (0x000000FE&((data)<<1))
#define ST_DDC_SFSAR_cirws_current(data)                              (0x00000001&(data))
#define ST_DDC_SFSAR_get_ciid_address(data)                           ((0x000000FE&(data))>>1)
#define ST_DDC_SFSAR_get_cirws_current(data)                          (0x00000001&(data))


#define ST_DDC_SFDR                                                   0x18061a40
#define ST_DDC_SFDR_reg_addr                                          "0xb8061a40"
#define ST_DDC_SFDR_reg                                               0xb8061a40
#define ST_DDC_SFDR_inst_addr                                         "0x02D0"
#define ST_DDC_SFDR_inst                                              0x02D0
#define ST_DDC_SFDR_ciiddp_shift                                      (0)
#define ST_DDC_SFDR_ciiddp_mask                                       (0x000000FF)
#define ST_DDC_SFDR_ciiddp(data)                                      (0x000000FF&(data))
#define ST_DDC_SFDR_get_ciiddp(data)                                  (0x000000FF&(data))


#define ST_DDC_SFBSR                                                  0x18061a44
#define ST_DDC_SFBSR_reg_addr                                         "0xb8061a44"
#define ST_DDC_SFBSR_reg                                              0xb8061a44
#define ST_DDC_SFBSR_inst_addr                                        "0x02D1"
#define ST_DDC_SFBSR_inst                                             0x02D1
#define ST_DDC_SFBSR_cirws_2nd_shift                                  (5)
#define ST_DDC_SFBSR_cirws_1st_shift                                  (4)
#define ST_DDC_SFBSR_cippt_2nd_shift                                  (3)
#define ST_DDC_SFBSR_cispt_2nd_shift                                  (2)
#define ST_DDC_SFBSR_cippt_1st_shift                                  (1)
#define ST_DDC_SFBSR_cispt_1st_shift                                  (0)
#define ST_DDC_SFBSR_cirws_2nd_mask                                   (0x00000020)
#define ST_DDC_SFBSR_cirws_1st_mask                                   (0x00000010)
#define ST_DDC_SFBSR_cippt_2nd_mask                                   (0x00000008)
#define ST_DDC_SFBSR_cispt_2nd_mask                                   (0x00000004)
#define ST_DDC_SFBSR_cippt_1st_mask                                   (0x00000002)
#define ST_DDC_SFBSR_cispt_1st_mask                                   (0x00000001)
#define ST_DDC_SFBSR_cirws_2nd(data)                                  (0x00000020&((data)<<5))
#define ST_DDC_SFBSR_cirws_1st(data)                                  (0x00000010&((data)<<4))
#define ST_DDC_SFBSR_cippt_2nd(data)                                  (0x00000008&((data)<<3))
#define ST_DDC_SFBSR_cispt_2nd(data)                                  (0x00000004&((data)<<2))
#define ST_DDC_SFBSR_cippt_1st(data)                                  (0x00000002&((data)<<1))
#define ST_DDC_SFBSR_cispt_1st(data)                                  (0x00000001&(data))
#define ST_DDC_SFBSR_get_cirws_2nd(data)                              ((0x00000020&(data))>>5)
#define ST_DDC_SFBSR_get_cirws_1st(data)                              ((0x00000010&(data))>>4)
#define ST_DDC_SFBSR_get_cippt_2nd(data)                              ((0x00000008&(data))>>3)
#define ST_DDC_SFBSR_get_cispt_2nd(data)                              ((0x00000004&(data))>>2)
#define ST_DDC_SFBSR_get_cippt_1st(data)                              ((0x00000002&(data))>>1)
#define ST_DDC_SFBSR_get_cispt_1st(data)                              (0x00000001&(data))


#define ST_DDC_SFIBLR                                                 0x18061a48
#define ST_DDC_SFIBLR_reg_addr                                        "0xb8061a48"
#define ST_DDC_SFIBLR_reg                                             0xb8061a48
#define ST_DDC_SFIBLR_inst_addr                                       "0x02D2"
#define ST_DDC_SFIBLR_inst                                            0x02D2
#define ST_DDC_SFIBLR_ffdi_dlen_shift                                 (0)
#define ST_DDC_SFIBLR_ffdi_dlen_mask                                  (0x0000001F)
#define ST_DDC_SFIBLR_ffdi_dlen(data)                                 (0x0000001F&(data))
#define ST_DDC_SFIBLR_get_ffdi_dlen(data)                             (0x0000001F&(data))


#define ST_DDC_SFIBRWPR                                               0x18061a4c
#define ST_DDC_SFIBRWPR_reg_addr                                      "0xb8061a4c"
#define ST_DDC_SFIBRWPR_reg                                           0xb8061a4c
#define ST_DDC_SFIBRWPR_inst_addr                                     "0x02D3"
#define ST_DDC_SFIBRWPR_inst                                          0x02D3
#define ST_DDC_SFIBRWPR_diff_wpt_shift                                (4)
#define ST_DDC_SFIBRWPR_diff_rpt_shift                                (0)
#define ST_DDC_SFIBRWPR_diff_wpt_mask                                 (0x000000F0)
#define ST_DDC_SFIBRWPR_diff_rpt_mask                                 (0x0000000F)
#define ST_DDC_SFIBRWPR_diff_wpt(data)                                (0x000000F0&((data)<<4))
#define ST_DDC_SFIBRWPR_diff_rpt(data)                                (0x0000000F&(data))
#define ST_DDC_SFIBRWPR_get_diff_wpt(data)                            ((0x000000F0&(data))>>4)
#define ST_DDC_SFIBRWPR_get_diff_rpt(data)                            (0x0000000F&(data))


#define ST_DDC_SFIBSWPR                                               0x18061a50
#define ST_DDC_SFIBSWPR_reg_addr                                      "0xb8061a50"
#define ST_DDC_SFIBSWPR_reg                                           0xb8061a50
#define ST_DDC_SFIBSWPR_inst_addr                                     "0x02D4"
#define ST_DDC_SFIBSWPR_inst                                          0x02D4
#define ST_DDC_SFIBSWPR_diffstop_pt_shift                             (0)
#define ST_DDC_SFIBSWPR_diffstop_pt_mask                              (0x0000000F)
#define ST_DDC_SFIBSWPR_diffstop_pt(data)                             (0x0000000F&(data))
#define ST_DDC_SFIBSWPR_get_diffstop_pt(data)                         (0x0000000F&(data))


#define ST_DDC_SFOBSR                                                 0x18061a54
#define ST_DDC_SFOBSR_reg_addr                                        "0xb8061a54"
#define ST_DDC_SFOBSR_reg                                             0xb8061a54
#define ST_DDC_SFOBSR_inst_addr                                       "0x02D5"
#define ST_DDC_SFOBSR_inst                                            0x02D5
#define ST_DDC_SFOBSR_ffdo_dlen_shift                                 (0)
#define ST_DDC_SFOBSR_ffdo_dlen_mask                                  (0x0000001F)
#define ST_DDC_SFOBSR_ffdo_dlen(data)                                 (0x0000001F&(data))
#define ST_DDC_SFOBSR_get_ffdo_dlen(data)                             (0x0000001F&(data))


#define ST_DDC_SFOBRWPR                                               0x18061a58
#define ST_DDC_SFOBRWPR_reg_addr                                      "0xb8061a58"
#define ST_DDC_SFOBRWPR_reg                                           0xb8061a58
#define ST_DDC_SFOBRWPR_inst_addr                                     "0x02D6"
#define ST_DDC_SFOBRWPR_inst                                          0x02D6
#define ST_DDC_SFOBRWPR_doff_wpt_shift                                (4)
#define ST_DDC_SFOBRWPR_doff_rpt_shift                                (0)
#define ST_DDC_SFOBRWPR_doff_wpt_mask                                 (0x000000F0)
#define ST_DDC_SFOBRWPR_doff_rpt_mask                                 (0x0000000F)
#define ST_DDC_SFOBRWPR_doff_wpt(data)                                (0x000000F0&((data)<<4))
#define ST_DDC_SFOBRWPR_doff_rpt(data)                                (0x0000000F&(data))
#define ST_DDC_SFOBRWPR_get_doff_wpt(data)                            ((0x000000F0&(data))>>4)
#define ST_DDC_SFOBRWPR_get_doff_rpt(data)                            (0x0000000F&(data))


#define ST_DDC_SFSR                                                   0x18061a5c
#define ST_DDC_SFSR_reg_addr                                          "0xb8061a5c"
#define ST_DDC_SFSR_reg                                               0xb8061a5c
#define ST_DDC_SFSR_inst_addr                                         "0x02D7"
#define ST_DDC_SFSR_inst                                              0x02D7
#define ST_DDC_SFSR_ffdouf_st_shift                                   (7)
#define ST_DDC_SFSR_ffdiof_st_shift                                   (6)
#define ST_DDC_SFSR_ffdonf_st_shift                                   (5)
#define ST_DDC_SFSR_ffdoet_st_shift                                   (4)
#define ST_DDC_SFSR_ffdifu_st_shift                                   (3)
#define ST_DDC_SFSR_ffdine_st_shift                                   (2)
#define ST_DDC_SFSR_ffdouf_st_mask                                    (0x00000080)
#define ST_DDC_SFSR_ffdiof_st_mask                                    (0x00000040)
#define ST_DDC_SFSR_ffdonf_st_mask                                    (0x00000020)
#define ST_DDC_SFSR_ffdoet_st_mask                                    (0x00000010)
#define ST_DDC_SFSR_ffdifu_st_mask                                    (0x00000008)
#define ST_DDC_SFSR_ffdine_st_mask                                    (0x00000004)
#define ST_DDC_SFSR_ffdouf_st(data)                                   (0x00000080&((data)<<7))
#define ST_DDC_SFSR_ffdiof_st(data)                                   (0x00000040&((data)<<6))
#define ST_DDC_SFSR_ffdonf_st(data)                                   (0x00000020&((data)<<5))
#define ST_DDC_SFSR_ffdoet_st(data)                                   (0x00000010&((data)<<4))
#define ST_DDC_SFSR_ffdifu_st(data)                                   (0x00000008&((data)<<3))
#define ST_DDC_SFSR_ffdine_st(data)                                   (0x00000004&((data)<<2))
#define ST_DDC_SFSR_get_ffdouf_st(data)                               ((0x00000080&(data))>>7)
#define ST_DDC_SFSR_get_ffdiof_st(data)                               ((0x00000040&(data))>>6)
#define ST_DDC_SFSR_get_ffdonf_st(data)                               ((0x00000020&(data))>>5)
#define ST_DDC_SFSR_get_ffdoet_st(data)                               ((0x00000010&(data))>>4)
#define ST_DDC_SFSR_get_ffdifu_st(data)                               ((0x00000008&(data))>>3)
#define ST_DDC_SFSR_get_ffdine_st(data)                               ((0x00000004&(data))>>2)


#define ST_DDC_SFIR                                                   0x18061a60
#define ST_DDC_SFIR_reg_addr                                          "0xb8061a60"
#define ST_DDC_SFIR_reg                                               0xb8061a60
#define ST_DDC_SFIR_inst_addr                                         "0x02D8"
#define ST_DDC_SFIR_inst                                              0x02D8
#define ST_DDC_SFIR_ffdouf_ie_shift                                   (7)
#define ST_DDC_SFIR_ffdiof_ie_shift                                   (6)
#define ST_DDC_SFIR_ffdonf_ie_shift                                   (5)
#define ST_DDC_SFIR_ffdoet_ie_shift                                   (4)
#define ST_DDC_SFIR_ffdifu_ie_shift                                   (3)
#define ST_DDC_SFIR_ffdine_ie_shift                                   (2)
#define ST_DDC_SFIR_cippt_ie_shift                                    (1)
#define ST_DDC_SFIR_cispt_ie_shift                                    (0)
#define ST_DDC_SFIR_ffdouf_ie_mask                                    (0x00000080)
#define ST_DDC_SFIR_ffdiof_ie_mask                                    (0x00000040)
#define ST_DDC_SFIR_ffdonf_ie_mask                                    (0x00000020)
#define ST_DDC_SFIR_ffdoet_ie_mask                                    (0x00000010)
#define ST_DDC_SFIR_ffdifu_ie_mask                                    (0x00000008)
#define ST_DDC_SFIR_ffdine_ie_mask                                    (0x00000004)
#define ST_DDC_SFIR_cippt_ie_mask                                     (0x00000002)
#define ST_DDC_SFIR_cispt_ie_mask                                     (0x00000001)
#define ST_DDC_SFIR_ffdouf_ie(data)                                   (0x00000080&((data)<<7))
#define ST_DDC_SFIR_ffdiof_ie(data)                                   (0x00000040&((data)<<6))
#define ST_DDC_SFIR_ffdonf_ie(data)                                   (0x00000020&((data)<<5))
#define ST_DDC_SFIR_ffdoet_ie(data)                                   (0x00000010&((data)<<4))
#define ST_DDC_SFIR_ffdifu_ie(data)                                   (0x00000008&((data)<<3))
#define ST_DDC_SFIR_ffdine_ie(data)                                   (0x00000004&((data)<<2))
#define ST_DDC_SFIR_cippt_ie(data)                                    (0x00000002&((data)<<1))
#define ST_DDC_SFIR_cispt_ie(data)                                    (0x00000001&(data))
#define ST_DDC_SFIR_get_ffdouf_ie(data)                               ((0x00000080&(data))>>7)
#define ST_DDC_SFIR_get_ffdiof_ie(data)                               ((0x00000040&(data))>>6)
#define ST_DDC_SFIR_get_ffdonf_ie(data)                               ((0x00000020&(data))>>5)
#define ST_DDC_SFIR_get_ffdoet_ie(data)                               ((0x00000010&(data))>>4)
#define ST_DDC_SFIR_get_ffdifu_ie(data)                               ((0x00000008&(data))>>3)
#define ST_DDC_SFIR_get_ffdine_ie(data)                               ((0x00000004&(data))>>2)
#define ST_DDC_SFIR_get_cippt_ie(data)                                ((0x00000002&(data))>>1)
#define ST_DDC_SFIR_get_cispt_ie(data)                                (0x00000001&(data))


#define ST_DDC_FSMS                                                   0x18061a64
#define ST_DDC_FSMS_reg_addr                                          "0xb8061a64"
#define ST_DDC_FSMS_reg                                               0xb8061a64
#define ST_DDC_FSMS_inst_addr                                         "0x02D9"
#define ST_DDC_FSMS_inst                                              0x02D9
#define ST_DDC_FSMS_cmdfsm_st_shift                                   (0)
#define ST_DDC_FSMS_cmdfsm_st_mask                                    (0x000000FF)
#define ST_DDC_FSMS_cmdfsm_st(data)                                   (0x000000FF&(data))
#define ST_DDC_FSMS_get_cmdfsm_st(data)                               (0x000000FF&(data))


#define ST_I2C_CR_2                                                   0x18061b00
#define ST_I2C_CR_2_reg_addr                                          "0xb8061b00"
#define ST_I2C_CR_2_reg                                               0xb8061b00
#define ST_I2C_CR_2_inst_addr                                         "0x0300"
#define ST_I2C_CR_2_inst                                              0x0300
#define ST_I2C_CR_2_cmderr_ie_shift                                   (7)
#define ST_I2C_CR_2_timeout_en_shift                                  (6)
#define ST_I2C_CR_2_debounce_mode_shift                               (4)
#define ST_I2C_CR_2_timeout_ie_shift                                  (3)
#define ST_I2C_CR_2_retime_m_shift                                    (0)
#define ST_I2C_CR_2_cmderr_ie_mask                                    (0x00000080)
#define ST_I2C_CR_2_timeout_en_mask                                   (0x00000040)
#define ST_I2C_CR_2_debounce_mode_mask                                (0x00000030)
#define ST_I2C_CR_2_timeout_ie_mask                                   (0x00000008)
#define ST_I2C_CR_2_retime_m_mask                                     (0x00000007)
#define ST_I2C_CR_2_cmderr_ie(data)                                   (0x00000080&((data)<<7))
#define ST_I2C_CR_2_timeout_en(data)                                  (0x00000040&((data)<<6))
#define ST_I2C_CR_2_debounce_mode(data)                               (0x00000030&((data)<<4))
#define ST_I2C_CR_2_timeout_ie(data)                                  (0x00000008&((data)<<3))
#define ST_I2C_CR_2_retime_m(data)                                    (0x00000007&(data))
#define ST_I2C_CR_2_get_cmderr_ie(data)                               ((0x00000080&(data))>>7)
#define ST_I2C_CR_2_get_timeout_en(data)                              ((0x00000040&(data))>>6)
#define ST_I2C_CR_2_get_debounce_mode(data)                           ((0x00000030&(data))>>4)
#define ST_I2C_CR_2_get_timeout_ie(data)                              ((0x00000008&(data))>>3)
#define ST_I2C_CR_2_get_retime_m(data)                                (0x00000007&(data))


#define ST_I2C_SR_2                                                   0x18061b04
#define ST_I2C_SR_2_reg_addr                                          "0xb8061b04"
#define ST_I2C_SR_2_reg                                               0xb8061b04
#define ST_I2C_SR_2_inst_addr                                         "0x0301"
#define ST_I2C_SR_2_inst                                              0x0301
#define ST_I2C_SR_2_cmderr_shift                                      (7)
#define ST_I2C_SR_2_finish_shift                                      (4)
#define ST_I2C_SR_2_timeout_shift                                     (3)
#define ST_I2C_SR_2_cmderr_mask                                       (0x00000080)
#define ST_I2C_SR_2_finish_mask                                       (0x00000010)
#define ST_I2C_SR_2_timeout_mask                                      (0x00000008)
#define ST_I2C_SR_2_cmderr(data)                                      (0x00000080&((data)<<7))
#define ST_I2C_SR_2_finish(data)                                      (0x00000010&((data)<<4))
#define ST_I2C_SR_2_timeout(data)                                     (0x00000008&((data)<<3))
#define ST_I2C_SR_2_get_cmderr(data)                                  ((0x00000080&(data))>>7)
#define ST_I2C_SR_2_get_finish(data)                                  ((0x00000010&(data))>>4)
#define ST_I2C_SR_2_get_timeout(data)                                 ((0x00000008&(data))>>3)


#define ST_I2C_TR_2                                                   0x18061b08
#define ST_I2C_TR_2_reg_addr                                          "0xb8061b08"
#define ST_I2C_TR_2_reg                                               0xb8061b08
#define ST_I2C_TR_2_inst_addr                                         "0x0302"
#define ST_I2C_TR_2_inst                                              0x0302
#define ST_I2C_TR_2_timeout_val_shift                                 (0)
#define ST_I2C_TR_2_timeout_val_mask                                  (0x000000FF)
#define ST_I2C_TR_2_timeout_val(data)                                 (0x000000FF&(data))
#define ST_I2C_TR_2_get_timeout_val(data)                             (0x000000FF&(data))


#define ST_EDID_CR_2                                                  0x18061b0c
#define ST_EDID_CR_2_reg_addr                                         "0xb8061b0c"
#define ST_EDID_CR_2_reg                                              0xb8061b0c
#define ST_EDID_CR_2_inst_addr                                        "0x0303"
#define ST_EDID_CR_2_inst                                             0x0303
#define ST_EDID_CR_2_edid_address_shift                               (5)
#define ST_EDID_CR_2_finish_int_en_shift                              (4)
#define ST_EDID_CR_2_ddc1_force_shift                                 (3)
#define ST_EDID_CR_2_ddc2b_force_shift                                (2)
#define ST_EDID_CR_2_edid_srwen_shift                                 (1)
#define ST_EDID_CR_2_edid_en_shift                                    (0)
#define ST_EDID_CR_2_edid_address_mask                                (0x000000E0)
#define ST_EDID_CR_2_finish_int_en_mask                               (0x00000010)
#define ST_EDID_CR_2_ddc1_force_mask                                  (0x00000008)
#define ST_EDID_CR_2_ddc2b_force_mask                                 (0x00000004)
#define ST_EDID_CR_2_edid_srwen_mask                                  (0x00000002)
#define ST_EDID_CR_2_edid_en_mask                                     (0x00000001)
#define ST_EDID_CR_2_edid_address(data)                               (0x000000E0&((data)<<5))
#define ST_EDID_CR_2_finish_int_en(data)                              (0x00000010&((data)<<4))
#define ST_EDID_CR_2_ddc1_force(data)                                 (0x00000008&((data)<<3))
#define ST_EDID_CR_2_ddc2b_force(data)                                (0x00000004&((data)<<2))
#define ST_EDID_CR_2_edid_srwen(data)                                 (0x00000002&((data)<<1))
#define ST_EDID_CR_2_edid_en(data)                                    (0x00000001&(data))
#define ST_EDID_CR_2_get_edid_address(data)                           ((0x000000E0&(data))>>5)
#define ST_EDID_CR_2_get_finish_int_en(data)                          ((0x00000010&(data))>>4)
#define ST_EDID_CR_2_get_ddc1_force(data)                             ((0x00000008&(data))>>3)
#define ST_EDID_CR_2_get_ddc2b_force(data)                            ((0x00000004&(data))>>2)
#define ST_EDID_CR_2_get_edid_srwen(data)                             ((0x00000002&(data))>>1)
#define ST_EDID_CR_2_get_edid_en(data)                                (0x00000001&(data))


#define ST_DDC_VCR_2                                                  0x18061b10
#define ST_DDC_VCR_2_reg_addr                                         "0xb8061b10"
#define ST_DDC_VCR_2_reg                                              0xb8061b10
#define ST_DDC_VCR_2_inst_addr                                        "0x0304"
#define ST_DDC_VCR_2_inst                                             0x0304
#define ST_DDC_VCR_2_ddc1_vcount_shift                                (0)
#define ST_DDC_VCR_2_ddc1_vcount_mask                                 (0x000000FF)
#define ST_DDC_VCR_2_ddc1_vcount(data)                                (0x000000FF&(data))
#define ST_DDC_VCR_2_get_ddc1_vcount(data)                            (0x000000FF&(data))


#define ST_EDID_IMSWSAR_2                                             0x18061b14
#define ST_EDID_IMSWSAR_2_reg_addr                                    "0xb8061b14"
#define ST_EDID_IMSWSAR_2_reg                                         0xb8061b14
#define ST_EDID_IMSWSAR_2_inst_addr                                   "0x0305"
#define ST_EDID_IMSWSAR_2_inst                                        0x0305
#define ST_EDID_IMSWSAR_2_edid_sadr_shift                             (0)
#define ST_EDID_IMSWSAR_2_edid_sadr_mask                              (0x000000FF)
#define ST_EDID_IMSWSAR_2_edid_sadr(data)                             (0x000000FF&(data))
#define ST_EDID_IMSWSAR_2_get_edid_sadr(data)                         (0x000000FF&(data))


#define ST_EDID_IMSWEAR_2                                             0x18061b18
#define ST_EDID_IMSWEAR_2_reg_addr                                    "0xb8061b18"
#define ST_EDID_IMSWEAR_2_reg                                         0xb8061b18
#define ST_EDID_IMSWEAR_2_inst_addr                                   "0x0306"
#define ST_EDID_IMSWEAR_2_inst                                        0x0306
#define ST_EDID_IMSWEAR_2_edid_eadr_shift                             (0)
#define ST_EDID_IMSWEAR_2_edid_eadr_mask                              (0x000000FF)
#define ST_EDID_IMSWEAR_2_edid_eadr(data)                             (0x000000FF&(data))
#define ST_EDID_IMSWEAR_2_get_edid_eadr(data)                         (0x000000FF&(data))


#define ST_EDID_IR_2                                                  0x18061b1c
#define ST_EDID_IR_2_reg_addr                                         "0xb8061b1c"
#define ST_EDID_IR_2_reg                                              0xb8061b1c
#define ST_EDID_IR_2_inst_addr                                        "0x0307"
#define ST_EDID_IR_2_inst                                             0x0307
#define ST_EDID_IR_2_edidmode_shift                                   (6)
#define ST_EDID_IR_2_edidsubaddress_shift                             (5)
#define ST_EDID_IR_2_edidstop_shift                                   (4)
#define ST_EDID_IR_2_edidsubaddress_ie_shift                          (1)
#define ST_EDID_IR_2_edidstop_ie_shift                                (0)
#define ST_EDID_IR_2_edidmode_mask                                    (0x00000040)
#define ST_EDID_IR_2_edidsubaddress_mask                              (0x00000020)
#define ST_EDID_IR_2_edidstop_mask                                    (0x00000010)
#define ST_EDID_IR_2_edidsubaddress_ie_mask                           (0x00000002)
#define ST_EDID_IR_2_edidstop_ie_mask                                 (0x00000001)
#define ST_EDID_IR_2_edidmode(data)                                   (0x00000040&((data)<<6))
#define ST_EDID_IR_2_edidsubaddress(data)                             (0x00000020&((data)<<5))
#define ST_EDID_IR_2_edidstop(data)                                   (0x00000010&((data)<<4))
#define ST_EDID_IR_2_edidsubaddress_ie(data)                          (0x00000002&((data)<<1))
#define ST_EDID_IR_2_edidstop_ie(data)                                (0x00000001&(data))
#define ST_EDID_IR_2_get_edidmode(data)                               ((0x00000040&(data))>>6)
#define ST_EDID_IR_2_get_edidsubaddress(data)                         ((0x00000020&(data))>>5)
#define ST_EDID_IR_2_get_edidstop(data)                               ((0x00000010&(data))>>4)
#define ST_EDID_IR_2_get_edidsubaddress_ie(data)                      ((0x00000002&(data))>>1)
#define ST_EDID_IR_2_get_edidstop_ie(data)                            (0x00000001&(data))


#define ST_DDC_SIR_2                                                  0x18061b20
#define ST_DDC_SIR_2_reg_addr                                         "0xb8061b20"
#define ST_DDC_SIR_2_reg                                              0xb8061b20
#define ST_DDC_SIR_2_inst_addr                                        "0x0308"
#define ST_DDC_SIR_2_inst                                             0x0308
#define ST_DDC_SIR_2_edidap_shift                                     (0)
#define ST_DDC_SIR_2_edidap_mask                                      (0x000000FF)
#define ST_DDC_SIR_2_edidap(data)                                     (0x000000FF&(data))
#define ST_DDC_SIR_2_get_edidap(data)                                 (0x000000FF&(data))


#define ST_DDC_SAP_2                                                  0x18061b24
#define ST_DDC_SAP_2_reg_addr                                         "0xb8061b24"
#define ST_DDC_SAP_2_reg                                              0xb8061b24
#define ST_DDC_SAP_2_inst_addr                                        "0x0309"
#define ST_DDC_SAP_2_inst                                             0x0309
#define ST_DDC_SAP_2_ediddp_shift                                     (0)
#define ST_DDC_SAP_2_ediddp_mask                                      (0x000000FF)
#define ST_DDC_SAP_2_ediddp(data)                                     (0x000000FF&(data))
#define ST_DDC_SAP_2_get_ediddp(data)                                 (0x000000FF&(data))


#define ST_DDC_BISTCR_2                                               0x18061b28
#define ST_DDC_BISTCR_2_reg_addr                                      "0xb8061b28"
#define ST_DDC_BISTCR_2_reg                                           0xb8061b28
#define ST_DDC_BISTCR_2_inst_addr                                     "0x030A"
#define ST_DDC_BISTCR_2_inst                                          0x030A
#define ST_DDC_BISTCR_2_bist_fail_shift                               (5)
#define ST_DDC_BISTCR_2_bist_done_shift                               (4)
#define ST_DDC_BISTCR_2_bist_rstn_shift                               (1)
#define ST_DDC_BISTCR_2_bist_mode_shift                               (0)
#define ST_DDC_BISTCR_2_bist_fail_mask                                (0x00000020)
#define ST_DDC_BISTCR_2_bist_done_mask                                (0x00000010)
#define ST_DDC_BISTCR_2_bist_rstn_mask                                (0x00000002)
#define ST_DDC_BISTCR_2_bist_mode_mask                                (0x00000001)
#define ST_DDC_BISTCR_2_bist_fail(data)                               (0x00000020&((data)<<5))
#define ST_DDC_BISTCR_2_bist_done(data)                               (0x00000010&((data)<<4))
#define ST_DDC_BISTCR_2_bist_rstn(data)                               (0x00000002&((data)<<1))
#define ST_DDC_BISTCR_2_bist_mode(data)                               (0x00000001&(data))
#define ST_DDC_BISTCR_2_get_bist_fail(data)                           ((0x00000020&(data))>>5)
#define ST_DDC_BISTCR_2_get_bist_done(data)                           ((0x00000010&(data))>>4)
#define ST_DDC_BISTCR_2_get_bist_rstn(data)                           ((0x00000002&(data))>>1)
#define ST_DDC_BISTCR_2_get_bist_mode(data)                           (0x00000001&(data))


#define ST_DDC_SCR_2                                                  0x18061b2c
#define ST_DDC_SCR_2_reg_addr                                         "0xb8061b2c"
#define ST_DDC_SCR_2_reg                                              0xb8061b2c
#define ST_DDC_SCR_2_inst_addr                                        "0x030B"
#define ST_DDC_SCR_2_inst                                             0x030B
#define ST_DDC_SCR_2_segpt_latie_shift                                (7)
#define ST_DDC_SCR_2_sgid_en_shift                                    (0)
#define ST_DDC_SCR_2_segpt_latie_mask                                 (0x00000080)
#define ST_DDC_SCR_2_sgid_en_mask                                     (0x00000001)
#define ST_DDC_SCR_2_segpt_latie(data)                                (0x00000080&((data)<<7))
#define ST_DDC_SCR_2_sgid_en(data)                                    (0x00000001&(data))
#define ST_DDC_SCR_2_get_segpt_latie(data)                            ((0x00000080&(data))>>7)
#define ST_DDC_SCR_2_get_sgid_en(data)                                (0x00000001&(data))


#define ST_DDC_SSAR_2                                                 0x18061b30
#define ST_DDC_SSAR_2_reg_addr                                        "0xb8061b30"
#define ST_DDC_SSAR_2_reg                                             0xb8061b30
#define ST_DDC_SSAR_2_inst_addr                                       "0x030C"
#define ST_DDC_SSAR_2_inst                                            0x030C
#define ST_DDC_SSAR_2_sgid_address_shift                              (1)
#define ST_DDC_SSAR_2_sgid_dtrden_shift                               (0)
#define ST_DDC_SSAR_2_sgid_address_mask                               (0x000000FE)
#define ST_DDC_SSAR_2_sgid_dtrden_mask                                (0x00000001)
#define ST_DDC_SSAR_2_sgid_address(data)                              (0x000000FE&((data)<<1))
#define ST_DDC_SSAR_2_sgid_dtrden(data)                               (0x00000001&(data))
#define ST_DDC_SSAR_2_get_sgid_address(data)                          ((0x000000FE&(data))>>1)
#define ST_DDC_SSAR_2_get_sgid_dtrden(data)                           (0x00000001&(data))


#define ST_DDC_SPR_2                                                  0x18061b34
#define ST_DDC_SPR_2_reg_addr                                         "0xb8061b34"
#define ST_DDC_SPR_2_reg                                              0xb8061b34
#define ST_DDC_SPR_2_inst_addr                                        "0x030D"
#define ST_DDC_SPR_2_inst                                             0x030D
#define ST_DDC_SPR_2_segpt_latched_shift                              (7)
#define ST_DDC_SPR_2_seg_pt_shift                                     (0)
#define ST_DDC_SPR_2_segpt_latched_mask                               (0x00000080)
#define ST_DDC_SPR_2_seg_pt_mask                                      (0x0000007F)
#define ST_DDC_SPR_2_segpt_latched(data)                              (0x00000080&((data)<<7))
#define ST_DDC_SPR_2_seg_pt(data)                                     (0x0000007F&(data))
#define ST_DDC_SPR_2_get_segpt_latched(data)                          ((0x00000080&(data))>>7)
#define ST_DDC_SPR_2_get_seg_pt(data)                                 (0x0000007F&(data))


#define ST_DDC_SFCR_2                                                 0x18061b38
#define ST_DDC_SFCR_2_reg_addr                                        "0xb8061b38"
#define ST_DDC_SFCR_2_reg                                             0xb8061b38
#define ST_DDC_SFCR_2_inst_addr                                       "0x030E"
#define ST_DDC_SFCR_2_inst                                            0x030E
#define ST_DDC_SFCR_2_special_mode_shift                              (3)
#define ST_DDC_SFCR_2_doffpt_reset_shift                              (2)
#define ST_DDC_SFCR_2_diffpt_reset_shift                              (1)
#define ST_DDC_SFCR_2_ciid_en_shift                                   (0)
#define ST_DDC_SFCR_2_special_mode_mask                               (0x00000008)
#define ST_DDC_SFCR_2_doffpt_reset_mask                               (0x00000004)
#define ST_DDC_SFCR_2_diffpt_reset_mask                               (0x00000002)
#define ST_DDC_SFCR_2_ciid_en_mask                                    (0x00000001)
#define ST_DDC_SFCR_2_special_mode(data)                              (0x00000008&((data)<<3))
#define ST_DDC_SFCR_2_doffpt_reset(data)                              (0x00000004&((data)<<2))
#define ST_DDC_SFCR_2_diffpt_reset(data)                              (0x00000002&((data)<<1))
#define ST_DDC_SFCR_2_ciid_en(data)                                   (0x00000001&(data))
#define ST_DDC_SFCR_2_get_special_mode(data)                          ((0x00000008&(data))>>3)
#define ST_DDC_SFCR_2_get_doffpt_reset(data)                          ((0x00000004&(data))>>2)
#define ST_DDC_SFCR_2_get_diffpt_reset(data)                          ((0x00000002&(data))>>1)
#define ST_DDC_SFCR_2_get_ciid_en(data)                               (0x00000001&(data))


#define ST_DDC_SFSAR_2                                                0x18061b3c
#define ST_DDC_SFSAR_2_reg_addr                                       "0xb8061b3c"
#define ST_DDC_SFSAR_2_reg                                            0xb8061b3c
#define ST_DDC_SFSAR_2_inst_addr                                      "0x030F"
#define ST_DDC_SFSAR_2_inst                                           0x030F
#define ST_DDC_SFSAR_2_ciid_address_shift                             (1)
#define ST_DDC_SFSAR_2_cirws_current_shift                            (0)
#define ST_DDC_SFSAR_2_ciid_address_mask                              (0x000000FE)
#define ST_DDC_SFSAR_2_cirws_current_mask                             (0x00000001)
#define ST_DDC_SFSAR_2_ciid_address(data)                             (0x000000FE&((data)<<1))
#define ST_DDC_SFSAR_2_cirws_current(data)                            (0x00000001&(data))
#define ST_DDC_SFSAR_2_get_ciid_address(data)                         ((0x000000FE&(data))>>1)
#define ST_DDC_SFSAR_2_get_cirws_current(data)                        (0x00000001&(data))


#define ST_DDC_SFDR_2                                                 0x18061b40
#define ST_DDC_SFDR_2_reg_addr                                        "0xb8061b40"
#define ST_DDC_SFDR_2_reg                                             0xb8061b40
#define ST_DDC_SFDR_2_inst_addr                                       "0x0310"
#define ST_DDC_SFDR_2_inst                                            0x0310
#define ST_DDC_SFDR_2_ciiddp_shift                                    (0)
#define ST_DDC_SFDR_2_ciiddp_mask                                     (0x000000FF)
#define ST_DDC_SFDR_2_ciiddp(data)                                    (0x000000FF&(data))
#define ST_DDC_SFDR_2_get_ciiddp(data)                                (0x000000FF&(data))


#define ST_DDC_SFBSR_2                                                0x18061b44
#define ST_DDC_SFBSR_2_reg_addr                                       "0xb8061b44"
#define ST_DDC_SFBSR_2_reg                                            0xb8061b44
#define ST_DDC_SFBSR_2_inst_addr                                      "0x0311"
#define ST_DDC_SFBSR_2_inst                                           0x0311
#define ST_DDC_SFBSR_2_cirws_2nd_shift                                (5)
#define ST_DDC_SFBSR_2_cirws_1st_shift                                (4)
#define ST_DDC_SFBSR_2_cippt_2nd_shift                                (3)
#define ST_DDC_SFBSR_2_cispt_2nd_shift                                (2)
#define ST_DDC_SFBSR_2_cippt_1st_shift                                (1)
#define ST_DDC_SFBSR_2_cispt_1st_shift                                (0)
#define ST_DDC_SFBSR_2_cirws_2nd_mask                                 (0x00000020)
#define ST_DDC_SFBSR_2_cirws_1st_mask                                 (0x00000010)
#define ST_DDC_SFBSR_2_cippt_2nd_mask                                 (0x00000008)
#define ST_DDC_SFBSR_2_cispt_2nd_mask                                 (0x00000004)
#define ST_DDC_SFBSR_2_cippt_1st_mask                                 (0x00000002)
#define ST_DDC_SFBSR_2_cispt_1st_mask                                 (0x00000001)
#define ST_DDC_SFBSR_2_cirws_2nd(data)                                (0x00000020&((data)<<5))
#define ST_DDC_SFBSR_2_cirws_1st(data)                                (0x00000010&((data)<<4))
#define ST_DDC_SFBSR_2_cippt_2nd(data)                                (0x00000008&((data)<<3))
#define ST_DDC_SFBSR_2_cispt_2nd(data)                                (0x00000004&((data)<<2))
#define ST_DDC_SFBSR_2_cippt_1st(data)                                (0x00000002&((data)<<1))
#define ST_DDC_SFBSR_2_cispt_1st(data)                                (0x00000001&(data))
#define ST_DDC_SFBSR_2_get_cirws_2nd(data)                            ((0x00000020&(data))>>5)
#define ST_DDC_SFBSR_2_get_cirws_1st(data)                            ((0x00000010&(data))>>4)
#define ST_DDC_SFBSR_2_get_cippt_2nd(data)                            ((0x00000008&(data))>>3)
#define ST_DDC_SFBSR_2_get_cispt_2nd(data)                            ((0x00000004&(data))>>2)
#define ST_DDC_SFBSR_2_get_cippt_1st(data)                            ((0x00000002&(data))>>1)
#define ST_DDC_SFBSR_2_get_cispt_1st(data)                            (0x00000001&(data))


#define ST_DDC_SFIBLR_2                                               0x18061b48
#define ST_DDC_SFIBLR_2_reg_addr                                      "0xb8061b48"
#define ST_DDC_SFIBLR_2_reg                                           0xb8061b48
#define ST_DDC_SFIBLR_2_inst_addr                                     "0x0312"
#define ST_DDC_SFIBLR_2_inst                                          0x0312
#define ST_DDC_SFIBLR_2_ffdi_dlen_shift                               (0)
#define ST_DDC_SFIBLR_2_ffdi_dlen_mask                                (0x0000001F)
#define ST_DDC_SFIBLR_2_ffdi_dlen(data)                               (0x0000001F&(data))
#define ST_DDC_SFIBLR_2_get_ffdi_dlen(data)                           (0x0000001F&(data))


#define ST_DDC_SFIBRWPR_2                                             0x18061b4c
#define ST_DDC_SFIBRWPR_2_reg_addr                                    "0xb8061b4c"
#define ST_DDC_SFIBRWPR_2_reg                                         0xb8061b4c
#define ST_DDC_SFIBRWPR_2_inst_addr                                   "0x0313"
#define ST_DDC_SFIBRWPR_2_inst                                        0x0313
#define ST_DDC_SFIBRWPR_2_diff_wpt_shift                              (4)
#define ST_DDC_SFIBRWPR_2_diff_rpt_shift                              (0)
#define ST_DDC_SFIBRWPR_2_diff_wpt_mask                               (0x000000F0)
#define ST_DDC_SFIBRWPR_2_diff_rpt_mask                               (0x0000000F)
#define ST_DDC_SFIBRWPR_2_diff_wpt(data)                              (0x000000F0&((data)<<4))
#define ST_DDC_SFIBRWPR_2_diff_rpt(data)                              (0x0000000F&(data))
#define ST_DDC_SFIBRWPR_2_get_diff_wpt(data)                          ((0x000000F0&(data))>>4)
#define ST_DDC_SFIBRWPR_2_get_diff_rpt(data)                          (0x0000000F&(data))


#define ST_DDC_SFIBSWPR_2                                             0x18061b50
#define ST_DDC_SFIBSWPR_2_reg_addr                                    "0xb8061b50"
#define ST_DDC_SFIBSWPR_2_reg                                         0xb8061b50
#define ST_DDC_SFIBSWPR_2_inst_addr                                   "0x0314"
#define ST_DDC_SFIBSWPR_2_inst                                        0x0314
#define ST_DDC_SFIBSWPR_2_diffstop_pt_shift                           (0)
#define ST_DDC_SFIBSWPR_2_diffstop_pt_mask                            (0x0000000F)
#define ST_DDC_SFIBSWPR_2_diffstop_pt(data)                           (0x0000000F&(data))
#define ST_DDC_SFIBSWPR_2_get_diffstop_pt(data)                       (0x0000000F&(data))


#define ST_DDC_SFOBSR_2                                               0x18061b54
#define ST_DDC_SFOBSR_2_reg_addr                                      "0xb8061b54"
#define ST_DDC_SFOBSR_2_reg                                           0xb8061b54
#define ST_DDC_SFOBSR_2_inst_addr                                     "0x0315"
#define ST_DDC_SFOBSR_2_inst                                          0x0315
#define ST_DDC_SFOBSR_2_ffdo_dlen_shift                               (0)
#define ST_DDC_SFOBSR_2_ffdo_dlen_mask                                (0x0000001F)
#define ST_DDC_SFOBSR_2_ffdo_dlen(data)                               (0x0000001F&(data))
#define ST_DDC_SFOBSR_2_get_ffdo_dlen(data)                           (0x0000001F&(data))


#define ST_DDC_SFOBRWPR_2                                             0x18061b58
#define ST_DDC_SFOBRWPR_2_reg_addr                                    "0xb8061b58"
#define ST_DDC_SFOBRWPR_2_reg                                         0xb8061b58
#define ST_DDC_SFOBRWPR_2_inst_addr                                   "0x0316"
#define ST_DDC_SFOBRWPR_2_inst                                        0x0316
#define ST_DDC_SFOBRWPR_2_doff_wpt_shift                              (4)
#define ST_DDC_SFOBRWPR_2_doff_rpt_shift                              (0)
#define ST_DDC_SFOBRWPR_2_doff_wpt_mask                               (0x000000F0)
#define ST_DDC_SFOBRWPR_2_doff_rpt_mask                               (0x0000000F)
#define ST_DDC_SFOBRWPR_2_doff_wpt(data)                              (0x000000F0&((data)<<4))
#define ST_DDC_SFOBRWPR_2_doff_rpt(data)                              (0x0000000F&(data))
#define ST_DDC_SFOBRWPR_2_get_doff_wpt(data)                          ((0x000000F0&(data))>>4)
#define ST_DDC_SFOBRWPR_2_get_doff_rpt(data)                          (0x0000000F&(data))


#define ST_DDC_SFSR_2                                                 0x18061b5c
#define ST_DDC_SFSR_2_reg_addr                                        "0xb8061b5c"
#define ST_DDC_SFSR_2_reg                                             0xb8061b5c
#define ST_DDC_SFSR_2_inst_addr                                       "0x0317"
#define ST_DDC_SFSR_2_inst                                            0x0317
#define ST_DDC_SFSR_2_ffdouf_st_shift                                 (7)
#define ST_DDC_SFSR_2_ffdiof_st_shift                                 (6)
#define ST_DDC_SFSR_2_ffdonf_st_shift                                 (5)
#define ST_DDC_SFSR_2_ffdoet_st_shift                                 (4)
#define ST_DDC_SFSR_2_ffdifu_st_shift                                 (3)
#define ST_DDC_SFSR_2_ffdine_st_shift                                 (2)
#define ST_DDC_SFSR_2_ffdouf_st_mask                                  (0x00000080)
#define ST_DDC_SFSR_2_ffdiof_st_mask                                  (0x00000040)
#define ST_DDC_SFSR_2_ffdonf_st_mask                                  (0x00000020)
#define ST_DDC_SFSR_2_ffdoet_st_mask                                  (0x00000010)
#define ST_DDC_SFSR_2_ffdifu_st_mask                                  (0x00000008)
#define ST_DDC_SFSR_2_ffdine_st_mask                                  (0x00000004)
#define ST_DDC_SFSR_2_ffdouf_st(data)                                 (0x00000080&((data)<<7))
#define ST_DDC_SFSR_2_ffdiof_st(data)                                 (0x00000040&((data)<<6))
#define ST_DDC_SFSR_2_ffdonf_st(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_SFSR_2_ffdoet_st(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_SFSR_2_ffdifu_st(data)                                 (0x00000008&((data)<<3))
#define ST_DDC_SFSR_2_ffdine_st(data)                                 (0x00000004&((data)<<2))
#define ST_DDC_SFSR_2_get_ffdouf_st(data)                             ((0x00000080&(data))>>7)
#define ST_DDC_SFSR_2_get_ffdiof_st(data)                             ((0x00000040&(data))>>6)
#define ST_DDC_SFSR_2_get_ffdonf_st(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_SFSR_2_get_ffdoet_st(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_SFSR_2_get_ffdifu_st(data)                             ((0x00000008&(data))>>3)
#define ST_DDC_SFSR_2_get_ffdine_st(data)                             ((0x00000004&(data))>>2)


#define ST_DDC_SFIR_2                                                 0x18061b60
#define ST_DDC_SFIR_2_reg_addr                                        "0xb8061b60"
#define ST_DDC_SFIR_2_reg                                             0xb8061b60
#define ST_DDC_SFIR_2_inst_addr                                       "0x0318"
#define ST_DDC_SFIR_2_inst                                            0x0318
#define ST_DDC_SFIR_2_ffdouf_ie_shift                                 (7)
#define ST_DDC_SFIR_2_ffdiof_ie_shift                                 (6)
#define ST_DDC_SFIR_2_ffdonf_ie_shift                                 (5)
#define ST_DDC_SFIR_2_ffdoet_ie_shift                                 (4)
#define ST_DDC_SFIR_2_ffdifu_ie_shift                                 (3)
#define ST_DDC_SFIR_2_ffdine_ie_shift                                 (2)
#define ST_DDC_SFIR_2_cippt_ie_shift                                  (1)
#define ST_DDC_SFIR_2_cispt_ie_shift                                  (0)
#define ST_DDC_SFIR_2_ffdouf_ie_mask                                  (0x00000080)
#define ST_DDC_SFIR_2_ffdiof_ie_mask                                  (0x00000040)
#define ST_DDC_SFIR_2_ffdonf_ie_mask                                  (0x00000020)
#define ST_DDC_SFIR_2_ffdoet_ie_mask                                  (0x00000010)
#define ST_DDC_SFIR_2_ffdifu_ie_mask                                  (0x00000008)
#define ST_DDC_SFIR_2_ffdine_ie_mask                                  (0x00000004)
#define ST_DDC_SFIR_2_cippt_ie_mask                                   (0x00000002)
#define ST_DDC_SFIR_2_cispt_ie_mask                                   (0x00000001)
#define ST_DDC_SFIR_2_ffdouf_ie(data)                                 (0x00000080&((data)<<7))
#define ST_DDC_SFIR_2_ffdiof_ie(data)                                 (0x00000040&((data)<<6))
#define ST_DDC_SFIR_2_ffdonf_ie(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_SFIR_2_ffdoet_ie(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_SFIR_2_ffdifu_ie(data)                                 (0x00000008&((data)<<3))
#define ST_DDC_SFIR_2_ffdine_ie(data)                                 (0x00000004&((data)<<2))
#define ST_DDC_SFIR_2_cippt_ie(data)                                  (0x00000002&((data)<<1))
#define ST_DDC_SFIR_2_cispt_ie(data)                                  (0x00000001&(data))
#define ST_DDC_SFIR_2_get_ffdouf_ie(data)                             ((0x00000080&(data))>>7)
#define ST_DDC_SFIR_2_get_ffdiof_ie(data)                             ((0x00000040&(data))>>6)
#define ST_DDC_SFIR_2_get_ffdonf_ie(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_SFIR_2_get_ffdoet_ie(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_SFIR_2_get_ffdifu_ie(data)                             ((0x00000008&(data))>>3)
#define ST_DDC_SFIR_2_get_ffdine_ie(data)                             ((0x00000004&(data))>>2)
#define ST_DDC_SFIR_2_get_cippt_ie(data)                              ((0x00000002&(data))>>1)
#define ST_DDC_SFIR_2_get_cispt_ie(data)                              (0x00000001&(data))


#define ST_DDC_FSMS_2                                                 0x18061b64
#define ST_DDC_FSMS_2_reg_addr                                        "0xb8061b64"
#define ST_DDC_FSMS_2_reg                                             0xb8061b64
#define ST_DDC_FSMS_2_inst_addr                                       "0x0319"
#define ST_DDC_FSMS_2_inst                                            0x0319
#define ST_DDC_FSMS_2_cmdfsm_st_shift                                 (0)
#define ST_DDC_FSMS_2_cmdfsm_st_mask                                  (0x000000FF)
#define ST_DDC_FSMS_2_cmdfsm_st(data)                                 (0x000000FF&(data))
#define ST_DDC_FSMS_2_get_cmdfsm_st(data)                             (0x000000FF&(data))


#define ST_I2C_CR_3                                                   0x18061c00
#define ST_I2C_CR_3_reg_addr                                          "0xb8061c00"
#define ST_I2C_CR_3_reg                                               0xb8061c00
#define ST_I2C_CR_3_inst_addr                                         "0x0340"
#define ST_I2C_CR_3_inst                                              0x0340
#define ST_I2C_CR_3_cmderr_ie_shift                                   (7)
#define ST_I2C_CR_3_timeout_en_shift                                  (6)
#define ST_I2C_CR_3_debounce_mode_shift                               (4)
#define ST_I2C_CR_3_timeout_ie_shift                                  (3)
#define ST_I2C_CR_3_retime_m_shift                                    (0)
#define ST_I2C_CR_3_cmderr_ie_mask                                    (0x00000080)
#define ST_I2C_CR_3_timeout_en_mask                                   (0x00000040)
#define ST_I2C_CR_3_debounce_mode_mask                                (0x00000030)
#define ST_I2C_CR_3_timeout_ie_mask                                   (0x00000008)
#define ST_I2C_CR_3_retime_m_mask                                     (0x00000007)
#define ST_I2C_CR_3_cmderr_ie(data)                                   (0x00000080&((data)<<7))
#define ST_I2C_CR_3_timeout_en(data)                                  (0x00000040&((data)<<6))
#define ST_I2C_CR_3_debounce_mode(data)                               (0x00000030&((data)<<4))
#define ST_I2C_CR_3_timeout_ie(data)                                  (0x00000008&((data)<<3))
#define ST_I2C_CR_3_retime_m(data)                                    (0x00000007&(data))
#define ST_I2C_CR_3_get_cmderr_ie(data)                               ((0x00000080&(data))>>7)
#define ST_I2C_CR_3_get_timeout_en(data)                              ((0x00000040&(data))>>6)
#define ST_I2C_CR_3_get_debounce_mode(data)                           ((0x00000030&(data))>>4)
#define ST_I2C_CR_3_get_timeout_ie(data)                              ((0x00000008&(data))>>3)
#define ST_I2C_CR_3_get_retime_m(data)                                (0x00000007&(data))


#define ST_I2C_SR_3                                                   0x18061c04
#define ST_I2C_SR_3_reg_addr                                          "0xb8061c04"
#define ST_I2C_SR_3_reg                                               0xb8061c04
#define ST_I2C_SR_3_inst_addr                                         "0x0341"
#define ST_I2C_SR_3_inst                                              0x0341
#define ST_I2C_SR_3_cmderr_shift                                      (7)
#define ST_I2C_SR_3_finish_shift                                      (4)
#define ST_I2C_SR_3_timeout_shift                                     (3)
#define ST_I2C_SR_3_cmderr_mask                                       (0x00000080)
#define ST_I2C_SR_3_finish_mask                                       (0x00000010)
#define ST_I2C_SR_3_timeout_mask                                      (0x00000008)
#define ST_I2C_SR_3_cmderr(data)                                      (0x00000080&((data)<<7))
#define ST_I2C_SR_3_finish(data)                                      (0x00000010&((data)<<4))
#define ST_I2C_SR_3_timeout(data)                                     (0x00000008&((data)<<3))
#define ST_I2C_SR_3_get_cmderr(data)                                  ((0x00000080&(data))>>7)
#define ST_I2C_SR_3_get_finish(data)                                  ((0x00000010&(data))>>4)
#define ST_I2C_SR_3_get_timeout(data)                                 ((0x00000008&(data))>>3)


#define ST_I2C_TR_3                                                   0x18061c08
#define ST_I2C_TR_3_reg_addr                                          "0xb8061c08"
#define ST_I2C_TR_3_reg                                               0xb8061c08
#define ST_I2C_TR_3_inst_addr                                         "0x0342"
#define ST_I2C_TR_3_inst                                              0x0342
#define ST_I2C_TR_3_timeout_val_shift                                 (0)
#define ST_I2C_TR_3_timeout_val_mask                                  (0x000000FF)
#define ST_I2C_TR_3_timeout_val(data)                                 (0x000000FF&(data))
#define ST_I2C_TR_3_get_timeout_val(data)                             (0x000000FF&(data))


#define ST_EDID_CR_3                                                  0x18061c0c
#define ST_EDID_CR_3_reg_addr                                         "0xb8061c0c"
#define ST_EDID_CR_3_reg                                              0xb8061c0c
#define ST_EDID_CR_3_inst_addr                                        "0x0343"
#define ST_EDID_CR_3_inst                                             0x0343
#define ST_EDID_CR_3_edid_address_shift                               (5)
#define ST_EDID_CR_3_finish_int_en_shift                              (4)
#define ST_EDID_CR_3_ddc1_force_shift                                 (3)
#define ST_EDID_CR_3_ddc2b_force_shift                                (2)
#define ST_EDID_CR_3_edid_srwen_shift                                 (1)
#define ST_EDID_CR_3_edid_en_shift                                    (0)
#define ST_EDID_CR_3_edid_address_mask                                (0x000000E0)
#define ST_EDID_CR_3_finish_int_en_mask                               (0x00000010)
#define ST_EDID_CR_3_ddc1_force_mask                                  (0x00000008)
#define ST_EDID_CR_3_ddc2b_force_mask                                 (0x00000004)
#define ST_EDID_CR_3_edid_srwen_mask                                  (0x00000002)
#define ST_EDID_CR_3_edid_en_mask                                     (0x00000001)
#define ST_EDID_CR_3_edid_address(data)                               (0x000000E0&((data)<<5))
#define ST_EDID_CR_3_finish_int_en(data)                              (0x00000010&((data)<<4))
#define ST_EDID_CR_3_ddc1_force(data)                                 (0x00000008&((data)<<3))
#define ST_EDID_CR_3_ddc2b_force(data)                                (0x00000004&((data)<<2))
#define ST_EDID_CR_3_edid_srwen(data)                                 (0x00000002&((data)<<1))
#define ST_EDID_CR_3_edid_en(data)                                    (0x00000001&(data))
#define ST_EDID_CR_3_get_edid_address(data)                           ((0x000000E0&(data))>>5)
#define ST_EDID_CR_3_get_finish_int_en(data)                          ((0x00000010&(data))>>4)
#define ST_EDID_CR_3_get_ddc1_force(data)                             ((0x00000008&(data))>>3)
#define ST_EDID_CR_3_get_ddc2b_force(data)                            ((0x00000004&(data))>>2)
#define ST_EDID_CR_3_get_edid_srwen(data)                             ((0x00000002&(data))>>1)
#define ST_EDID_CR_3_get_edid_en(data)                                (0x00000001&(data))


#define ST_DDC_VCR_3                                                  0x18061c10
#define ST_DDC_VCR_3_reg_addr                                         "0xb8061c10"
#define ST_DDC_VCR_3_reg                                              0xb8061c10
#define ST_DDC_VCR_3_inst_addr                                        "0x0344"
#define ST_DDC_VCR_3_inst                                             0x0344
#define ST_DDC_VCR_3_ddc1_vcount_shift                                (0)
#define ST_DDC_VCR_3_ddc1_vcount_mask                                 (0x000000FF)
#define ST_DDC_VCR_3_ddc1_vcount(data)                                (0x000000FF&(data))
#define ST_DDC_VCR_3_get_ddc1_vcount(data)                            (0x000000FF&(data))


#define ST_EDID_IMSWSAR_3                                             0x18061c14
#define ST_EDID_IMSWSAR_3_reg_addr                                    "0xb8061c14"
#define ST_EDID_IMSWSAR_3_reg                                         0xb8061c14
#define ST_EDID_IMSWSAR_3_inst_addr                                   "0x0345"
#define ST_EDID_IMSWSAR_3_inst                                        0x0345
#define ST_EDID_IMSWSAR_3_edid_sadr_shift                             (0)
#define ST_EDID_IMSWSAR_3_edid_sadr_mask                              (0x000000FF)
#define ST_EDID_IMSWSAR_3_edid_sadr(data)                             (0x000000FF&(data))
#define ST_EDID_IMSWSAR_3_get_edid_sadr(data)                         (0x000000FF&(data))


#define ST_EDID_IMSWEAR_3                                             0x18061c18
#define ST_EDID_IMSWEAR_3_reg_addr                                    "0xb8061c18"
#define ST_EDID_IMSWEAR_3_reg                                         0xb8061c18
#define ST_EDID_IMSWEAR_3_inst_addr                                   "0x0346"
#define ST_EDID_IMSWEAR_3_inst                                        0x0346
#define ST_EDID_IMSWEAR_3_edid_eadr_shift                             (0)
#define ST_EDID_IMSWEAR_3_edid_eadr_mask                              (0x000000FF)
#define ST_EDID_IMSWEAR_3_edid_eadr(data)                             (0x000000FF&(data))
#define ST_EDID_IMSWEAR_3_get_edid_eadr(data)                         (0x000000FF&(data))


#define ST_EDID_IR_3                                                  0x18061c1c
#define ST_EDID_IR_3_reg_addr                                         "0xb8061c1c"
#define ST_EDID_IR_3_reg                                              0xb8061c1c
#define ST_EDID_IR_3_inst_addr                                        "0x0347"
#define ST_EDID_IR_3_inst                                             0x0347
#define ST_EDID_IR_3_edidmode_shift                                   (6)
#define ST_EDID_IR_3_edidsubaddress_shift                             (5)
#define ST_EDID_IR_3_edidstop_shift                                   (4)
#define ST_EDID_IR_3_edidsubaddress_ie_shift                          (1)
#define ST_EDID_IR_3_edidstop_ie_shift                                (0)
#define ST_EDID_IR_3_edidmode_mask                                    (0x00000040)
#define ST_EDID_IR_3_edidsubaddress_mask                              (0x00000020)
#define ST_EDID_IR_3_edidstop_mask                                    (0x00000010)
#define ST_EDID_IR_3_edidsubaddress_ie_mask                           (0x00000002)
#define ST_EDID_IR_3_edidstop_ie_mask                                 (0x00000001)
#define ST_EDID_IR_3_edidmode(data)                                   (0x00000040&((data)<<6))
#define ST_EDID_IR_3_edidsubaddress(data)                             (0x00000020&((data)<<5))
#define ST_EDID_IR_3_edidstop(data)                                   (0x00000010&((data)<<4))
#define ST_EDID_IR_3_edidsubaddress_ie(data)                          (0x00000002&((data)<<1))
#define ST_EDID_IR_3_edidstop_ie(data)                                (0x00000001&(data))
#define ST_EDID_IR_3_get_edidmode(data)                               ((0x00000040&(data))>>6)
#define ST_EDID_IR_3_get_edidsubaddress(data)                         ((0x00000020&(data))>>5)
#define ST_EDID_IR_3_get_edidstop(data)                               ((0x00000010&(data))>>4)
#define ST_EDID_IR_3_get_edidsubaddress_ie(data)                      ((0x00000002&(data))>>1)
#define ST_EDID_IR_3_get_edidstop_ie(data)                            (0x00000001&(data))


#define ST_DDC_SIR_3                                                  0x18061c20
#define ST_DDC_SIR_3_reg_addr                                         "0xb8061c20"
#define ST_DDC_SIR_3_reg                                              0xb8061c20
#define ST_DDC_SIR_3_inst_addr                                        "0x0348"
#define ST_DDC_SIR_3_inst                                             0x0348
#define ST_DDC_SIR_3_edidap_shift                                     (0)
#define ST_DDC_SIR_3_edidap_mask                                      (0x000000FF)
#define ST_DDC_SIR_3_edidap(data)                                     (0x000000FF&(data))
#define ST_DDC_SIR_3_get_edidap(data)                                 (0x000000FF&(data))


#define ST_DDC_SAP_3                                                  0x18061c24
#define ST_DDC_SAP_3_reg_addr                                         "0xb8061c24"
#define ST_DDC_SAP_3_reg                                              0xb8061c24
#define ST_DDC_SAP_3_inst_addr                                        "0x0349"
#define ST_DDC_SAP_3_inst                                             0x0349
#define ST_DDC_SAP_3_ediddp_shift                                     (0)
#define ST_DDC_SAP_3_ediddp_mask                                      (0x000000FF)
#define ST_DDC_SAP_3_ediddp(data)                                     (0x000000FF&(data))
#define ST_DDC_SAP_3_get_ediddp(data)                                 (0x000000FF&(data))


#define ST_DDC_BISTCR_3                                               0x18061c28
#define ST_DDC_BISTCR_3_reg_addr                                      "0xb8061c28"
#define ST_DDC_BISTCR_3_reg                                           0xb8061c28
#define ST_DDC_BISTCR_3_inst_addr                                     "0x034A"
#define ST_DDC_BISTCR_3_inst                                          0x034A
#define ST_DDC_BISTCR_3_bist_fail_shift                               (5)
#define ST_DDC_BISTCR_3_bist_done_shift                               (4)
#define ST_DDC_BISTCR_3_bist_rstn_shift                               (1)
#define ST_DDC_BISTCR_3_bist_mode_shift                               (0)
#define ST_DDC_BISTCR_3_bist_fail_mask                                (0x00000020)
#define ST_DDC_BISTCR_3_bist_done_mask                                (0x00000010)
#define ST_DDC_BISTCR_3_bist_rstn_mask                                (0x00000002)
#define ST_DDC_BISTCR_3_bist_mode_mask                                (0x00000001)
#define ST_DDC_BISTCR_3_bist_fail(data)                               (0x00000020&((data)<<5))
#define ST_DDC_BISTCR_3_bist_done(data)                               (0x00000010&((data)<<4))
#define ST_DDC_BISTCR_3_bist_rstn(data)                               (0x00000002&((data)<<1))
#define ST_DDC_BISTCR_3_bist_mode(data)                               (0x00000001&(data))
#define ST_DDC_BISTCR_3_get_bist_fail(data)                           ((0x00000020&(data))>>5)
#define ST_DDC_BISTCR_3_get_bist_done(data)                           ((0x00000010&(data))>>4)
#define ST_DDC_BISTCR_3_get_bist_rstn(data)                           ((0x00000002&(data))>>1)
#define ST_DDC_BISTCR_3_get_bist_mode(data)                           (0x00000001&(data))


#define ST_DDC_SCR_3                                                  0x18061c2c
#define ST_DDC_SCR_3_reg_addr                                         "0xb8061c2c"
#define ST_DDC_SCR_3_reg                                              0xb8061c2c
#define ST_DDC_SCR_3_inst_addr                                        "0x034B"
#define ST_DDC_SCR_3_inst                                             0x034B
#define ST_DDC_SCR_3_segpt_latie_shift                                (7)
#define ST_DDC_SCR_3_sgid_en_shift                                    (0)
#define ST_DDC_SCR_3_segpt_latie_mask                                 (0x00000080)
#define ST_DDC_SCR_3_sgid_en_mask                                     (0x00000001)
#define ST_DDC_SCR_3_segpt_latie(data)                                (0x00000080&((data)<<7))
#define ST_DDC_SCR_3_sgid_en(data)                                    (0x00000001&(data))
#define ST_DDC_SCR_3_get_segpt_latie(data)                            ((0x00000080&(data))>>7)
#define ST_DDC_SCR_3_get_sgid_en(data)                                (0x00000001&(data))


#define ST_DDC_SSAR_3                                                 0x18061c30
#define ST_DDC_SSAR_3_reg_addr                                        "0xb8061c30"
#define ST_DDC_SSAR_3_reg                                             0xb8061c30
#define ST_DDC_SSAR_3_inst_addr                                       "0x034C"
#define ST_DDC_SSAR_3_inst                                            0x034C
#define ST_DDC_SSAR_3_sgid_address_shift                              (1)
#define ST_DDC_SSAR_3_sgid_dtrden_shift                               (0)
#define ST_DDC_SSAR_3_sgid_address_mask                               (0x000000FE)
#define ST_DDC_SSAR_3_sgid_dtrden_mask                                (0x00000001)
#define ST_DDC_SSAR_3_sgid_address(data)                              (0x000000FE&((data)<<1))
#define ST_DDC_SSAR_3_sgid_dtrden(data)                               (0x00000001&(data))
#define ST_DDC_SSAR_3_get_sgid_address(data)                          ((0x000000FE&(data))>>1)
#define ST_DDC_SSAR_3_get_sgid_dtrden(data)                           (0x00000001&(data))


#define ST_DDC_SPR_3                                                  0x18061c34
#define ST_DDC_SPR_3_reg_addr                                         "0xb8061c34"
#define ST_DDC_SPR_3_reg                                              0xb8061c34
#define ST_DDC_SPR_3_inst_addr                                        "0x034D"
#define ST_DDC_SPR_3_inst                                             0x034D
#define ST_DDC_SPR_3_segpt_latched_shift                              (7)
#define ST_DDC_SPR_3_seg_pt_shift                                     (0)
#define ST_DDC_SPR_3_segpt_latched_mask                               (0x00000080)
#define ST_DDC_SPR_3_seg_pt_mask                                      (0x0000007F)
#define ST_DDC_SPR_3_segpt_latched(data)                              (0x00000080&((data)<<7))
#define ST_DDC_SPR_3_seg_pt(data)                                     (0x0000007F&(data))
#define ST_DDC_SPR_3_get_segpt_latched(data)                          ((0x00000080&(data))>>7)
#define ST_DDC_SPR_3_get_seg_pt(data)                                 (0x0000007F&(data))


#define ST_DDC_SFCR_3                                                 0x18061c38
#define ST_DDC_SFCR_3_reg_addr                                        "0xb8061c38"
#define ST_DDC_SFCR_3_reg                                             0xb8061c38
#define ST_DDC_SFCR_3_inst_addr                                       "0x034E"
#define ST_DDC_SFCR_3_inst                                            0x034E
#define ST_DDC_SFCR_3_special_mode_shift                              (3)
#define ST_DDC_SFCR_3_doffpt_reset_shift                              (2)
#define ST_DDC_SFCR_3_diffpt_reset_shift                              (1)
#define ST_DDC_SFCR_3_ciid_en_shift                                   (0)
#define ST_DDC_SFCR_3_special_mode_mask                               (0x00000008)
#define ST_DDC_SFCR_3_doffpt_reset_mask                               (0x00000004)
#define ST_DDC_SFCR_3_diffpt_reset_mask                               (0x00000002)
#define ST_DDC_SFCR_3_ciid_en_mask                                    (0x00000001)
#define ST_DDC_SFCR_3_special_mode(data)                              (0x00000008&((data)<<3))
#define ST_DDC_SFCR_3_doffpt_reset(data)                              (0x00000004&((data)<<2))
#define ST_DDC_SFCR_3_diffpt_reset(data)                              (0x00000002&((data)<<1))
#define ST_DDC_SFCR_3_ciid_en(data)                                   (0x00000001&(data))
#define ST_DDC_SFCR_3_get_special_mode(data)                          ((0x00000008&(data))>>3)
#define ST_DDC_SFCR_3_get_doffpt_reset(data)                          ((0x00000004&(data))>>2)
#define ST_DDC_SFCR_3_get_diffpt_reset(data)                          ((0x00000002&(data))>>1)
#define ST_DDC_SFCR_3_get_ciid_en(data)                               (0x00000001&(data))


#define ST_DDC_SFSAR_3                                                0x18061c3c
#define ST_DDC_SFSAR_3_reg_addr                                       "0xb8061c3c"
#define ST_DDC_SFSAR_3_reg                                            0xb8061c3c
#define ST_DDC_SFSAR_3_inst_addr                                      "0x034F"
#define ST_DDC_SFSAR_3_inst                                           0x034F
#define ST_DDC_SFSAR_3_ciid_address_shift                             (1)
#define ST_DDC_SFSAR_3_cirws_current_shift                            (0)
#define ST_DDC_SFSAR_3_ciid_address_mask                              (0x000000FE)
#define ST_DDC_SFSAR_3_cirws_current_mask                             (0x00000001)
#define ST_DDC_SFSAR_3_ciid_address(data)                             (0x000000FE&((data)<<1))
#define ST_DDC_SFSAR_3_cirws_current(data)                            (0x00000001&(data))
#define ST_DDC_SFSAR_3_get_ciid_address(data)                         ((0x000000FE&(data))>>1)
#define ST_DDC_SFSAR_3_get_cirws_current(data)                        (0x00000001&(data))


#define ST_DDC_SFDR_3                                                 0x18061c40
#define ST_DDC_SFDR_3_reg_addr                                        "0xb8061c40"
#define ST_DDC_SFDR_3_reg                                             0xb8061c40
#define ST_DDC_SFDR_3_inst_addr                                       "0x0350"
#define ST_DDC_SFDR_3_inst                                            0x0350
#define ST_DDC_SFDR_3_ciiddp_shift                                    (0)
#define ST_DDC_SFDR_3_ciiddp_mask                                     (0x000000FF)
#define ST_DDC_SFDR_3_ciiddp(data)                                    (0x000000FF&(data))
#define ST_DDC_SFDR_3_get_ciiddp(data)                                (0x000000FF&(data))


#define ST_DDC_SFBSR_3                                                0x18061c44
#define ST_DDC_SFBSR_3_reg_addr                                       "0xb8061c44"
#define ST_DDC_SFBSR_3_reg                                            0xb8061c44
#define ST_DDC_SFBSR_3_inst_addr                                      "0x0351"
#define ST_DDC_SFBSR_3_inst                                           0x0351
#define ST_DDC_SFBSR_3_cirws_2nd_shift                                (5)
#define ST_DDC_SFBSR_3_cirws_1st_shift                                (4)
#define ST_DDC_SFBSR_3_cippt_2nd_shift                                (3)
#define ST_DDC_SFBSR_3_cispt_2nd_shift                                (2)
#define ST_DDC_SFBSR_3_cippt_1st_shift                                (1)
#define ST_DDC_SFBSR_3_cispt_1st_shift                                (0)
#define ST_DDC_SFBSR_3_cirws_2nd_mask                                 (0x00000020)
#define ST_DDC_SFBSR_3_cirws_1st_mask                                 (0x00000010)
#define ST_DDC_SFBSR_3_cippt_2nd_mask                                 (0x00000008)
#define ST_DDC_SFBSR_3_cispt_2nd_mask                                 (0x00000004)
#define ST_DDC_SFBSR_3_cippt_1st_mask                                 (0x00000002)
#define ST_DDC_SFBSR_3_cispt_1st_mask                                 (0x00000001)
#define ST_DDC_SFBSR_3_cirws_2nd(data)                                (0x00000020&((data)<<5))
#define ST_DDC_SFBSR_3_cirws_1st(data)                                (0x00000010&((data)<<4))
#define ST_DDC_SFBSR_3_cippt_2nd(data)                                (0x00000008&((data)<<3))
#define ST_DDC_SFBSR_3_cispt_2nd(data)                                (0x00000004&((data)<<2))
#define ST_DDC_SFBSR_3_cippt_1st(data)                                (0x00000002&((data)<<1))
#define ST_DDC_SFBSR_3_cispt_1st(data)                                (0x00000001&(data))
#define ST_DDC_SFBSR_3_get_cirws_2nd(data)                            ((0x00000020&(data))>>5)
#define ST_DDC_SFBSR_3_get_cirws_1st(data)                            ((0x00000010&(data))>>4)
#define ST_DDC_SFBSR_3_get_cippt_2nd(data)                            ((0x00000008&(data))>>3)
#define ST_DDC_SFBSR_3_get_cispt_2nd(data)                            ((0x00000004&(data))>>2)
#define ST_DDC_SFBSR_3_get_cippt_1st(data)                            ((0x00000002&(data))>>1)
#define ST_DDC_SFBSR_3_get_cispt_1st(data)                            (0x00000001&(data))


#define ST_DDC_SFIBLR_3                                               0x18061c48
#define ST_DDC_SFIBLR_3_reg_addr                                      "0xb8061c48"
#define ST_DDC_SFIBLR_3_reg                                           0xb8061c48
#define ST_DDC_SFIBLR_3_inst_addr                                     "0x0352"
#define ST_DDC_SFIBLR_3_inst                                          0x0352
#define ST_DDC_SFIBLR_3_ffdi_dlen_shift                               (0)
#define ST_DDC_SFIBLR_3_ffdi_dlen_mask                                (0x0000001F)
#define ST_DDC_SFIBLR_3_ffdi_dlen(data)                               (0x0000001F&(data))
#define ST_DDC_SFIBLR_3_get_ffdi_dlen(data)                           (0x0000001F&(data))


#define ST_DDC_SFIBRWPR_3                                             0x18061c4c
#define ST_DDC_SFIBRWPR_3_reg_addr                                    "0xb8061c4c"
#define ST_DDC_SFIBRWPR_3_reg                                         0xb8061c4c
#define ST_DDC_SFIBRWPR_3_inst_addr                                   "0x0353"
#define ST_DDC_SFIBRWPR_3_inst                                        0x0353
#define ST_DDC_SFIBRWPR_3_diff_wpt_shift                              (4)
#define ST_DDC_SFIBRWPR_3_diff_rpt_shift                              (0)
#define ST_DDC_SFIBRWPR_3_diff_wpt_mask                               (0x000000F0)
#define ST_DDC_SFIBRWPR_3_diff_rpt_mask                               (0x0000000F)
#define ST_DDC_SFIBRWPR_3_diff_wpt(data)                              (0x000000F0&((data)<<4))
#define ST_DDC_SFIBRWPR_3_diff_rpt(data)                              (0x0000000F&(data))
#define ST_DDC_SFIBRWPR_3_get_diff_wpt(data)                          ((0x000000F0&(data))>>4)
#define ST_DDC_SFIBRWPR_3_get_diff_rpt(data)                          (0x0000000F&(data))


#define ST_DDC_SFIBSWPR_3                                             0x18061c50
#define ST_DDC_SFIBSWPR_3_reg_addr                                    "0xb8061c50"
#define ST_DDC_SFIBSWPR_3_reg                                         0xb8061c50
#define ST_DDC_SFIBSWPR_3_inst_addr                                   "0x0354"
#define ST_DDC_SFIBSWPR_3_inst                                        0x0354
#define ST_DDC_SFIBSWPR_3_diffstop_pt_shift                           (0)
#define ST_DDC_SFIBSWPR_3_diffstop_pt_mask                            (0x0000000F)
#define ST_DDC_SFIBSWPR_3_diffstop_pt(data)                           (0x0000000F&(data))
#define ST_DDC_SFIBSWPR_3_get_diffstop_pt(data)                       (0x0000000F&(data))


#define ST_DDC_SFOBSR_3                                               0x18061c54
#define ST_DDC_SFOBSR_3_reg_addr                                      "0xb8061c54"
#define ST_DDC_SFOBSR_3_reg                                           0xb8061c54
#define ST_DDC_SFOBSR_3_inst_addr                                     "0x0355"
#define ST_DDC_SFOBSR_3_inst                                          0x0355
#define ST_DDC_SFOBSR_3_ffdo_dlen_shift                               (0)
#define ST_DDC_SFOBSR_3_ffdo_dlen_mask                                (0x0000001F)
#define ST_DDC_SFOBSR_3_ffdo_dlen(data)                               (0x0000001F&(data))
#define ST_DDC_SFOBSR_3_get_ffdo_dlen(data)                           (0x0000001F&(data))


#define ST_DDC_SFOBRWPR_3                                             0x18061c58
#define ST_DDC_SFOBRWPR_3_reg_addr                                    "0xb8061c58"
#define ST_DDC_SFOBRWPR_3_reg                                         0xb8061c58
#define ST_DDC_SFOBRWPR_3_inst_addr                                   "0x0356"
#define ST_DDC_SFOBRWPR_3_inst                                        0x0356
#define ST_DDC_SFOBRWPR_3_doff_wpt_shift                              (4)
#define ST_DDC_SFOBRWPR_3_doff_rpt_shift                              (0)
#define ST_DDC_SFOBRWPR_3_doff_wpt_mask                               (0x000000F0)
#define ST_DDC_SFOBRWPR_3_doff_rpt_mask                               (0x0000000F)
#define ST_DDC_SFOBRWPR_3_doff_wpt(data)                              (0x000000F0&((data)<<4))
#define ST_DDC_SFOBRWPR_3_doff_rpt(data)                              (0x0000000F&(data))
#define ST_DDC_SFOBRWPR_3_get_doff_wpt(data)                          ((0x000000F0&(data))>>4)
#define ST_DDC_SFOBRWPR_3_get_doff_rpt(data)                          (0x0000000F&(data))


#define ST_DDC_SFSR_3                                                 0x18061c5c
#define ST_DDC_SFSR_3_reg_addr                                        "0xb8061c5c"
#define ST_DDC_SFSR_3_reg                                             0xb8061c5c
#define ST_DDC_SFSR_3_inst_addr                                       "0x0357"
#define ST_DDC_SFSR_3_inst                                            0x0357
#define ST_DDC_SFSR_3_ffdouf_st_shift                                 (7)
#define ST_DDC_SFSR_3_ffdiof_st_shift                                 (6)
#define ST_DDC_SFSR_3_ffdonf_st_shift                                 (5)
#define ST_DDC_SFSR_3_ffdoet_st_shift                                 (4)
#define ST_DDC_SFSR_3_ffdifu_st_shift                                 (3)
#define ST_DDC_SFSR_3_ffdine_st_shift                                 (2)
#define ST_DDC_SFSR_3_ffdouf_st_mask                                  (0x00000080)
#define ST_DDC_SFSR_3_ffdiof_st_mask                                  (0x00000040)
#define ST_DDC_SFSR_3_ffdonf_st_mask                                  (0x00000020)
#define ST_DDC_SFSR_3_ffdoet_st_mask                                  (0x00000010)
#define ST_DDC_SFSR_3_ffdifu_st_mask                                  (0x00000008)
#define ST_DDC_SFSR_3_ffdine_st_mask                                  (0x00000004)
#define ST_DDC_SFSR_3_ffdouf_st(data)                                 (0x00000080&((data)<<7))
#define ST_DDC_SFSR_3_ffdiof_st(data)                                 (0x00000040&((data)<<6))
#define ST_DDC_SFSR_3_ffdonf_st(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_SFSR_3_ffdoet_st(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_SFSR_3_ffdifu_st(data)                                 (0x00000008&((data)<<3))
#define ST_DDC_SFSR_3_ffdine_st(data)                                 (0x00000004&((data)<<2))
#define ST_DDC_SFSR_3_get_ffdouf_st(data)                             ((0x00000080&(data))>>7)
#define ST_DDC_SFSR_3_get_ffdiof_st(data)                             ((0x00000040&(data))>>6)
#define ST_DDC_SFSR_3_get_ffdonf_st(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_SFSR_3_get_ffdoet_st(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_SFSR_3_get_ffdifu_st(data)                             ((0x00000008&(data))>>3)
#define ST_DDC_SFSR_3_get_ffdine_st(data)                             ((0x00000004&(data))>>2)


#define ST_DDC_SFIR_3                                                 0x18061c60
#define ST_DDC_SFIR_3_reg_addr                                        "0xb8061c60"
#define ST_DDC_SFIR_3_reg                                             0xb8061c60
#define ST_DDC_SFIR_3_inst_addr                                       "0x0358"
#define ST_DDC_SFIR_3_inst                                            0x0358
#define ST_DDC_SFIR_3_ffdouf_ie_shift                                 (7)
#define ST_DDC_SFIR_3_ffdiof_ie_shift                                 (6)
#define ST_DDC_SFIR_3_ffdonf_ie_shift                                 (5)
#define ST_DDC_SFIR_3_ffdoet_ie_shift                                 (4)
#define ST_DDC_SFIR_3_ffdifu_ie_shift                                 (3)
#define ST_DDC_SFIR_3_ffdine_ie_shift                                 (2)
#define ST_DDC_SFIR_3_cippt_ie_shift                                  (1)
#define ST_DDC_SFIR_3_cispt_ie_shift                                  (0)
#define ST_DDC_SFIR_3_ffdouf_ie_mask                                  (0x00000080)
#define ST_DDC_SFIR_3_ffdiof_ie_mask                                  (0x00000040)
#define ST_DDC_SFIR_3_ffdonf_ie_mask                                  (0x00000020)
#define ST_DDC_SFIR_3_ffdoet_ie_mask                                  (0x00000010)
#define ST_DDC_SFIR_3_ffdifu_ie_mask                                  (0x00000008)
#define ST_DDC_SFIR_3_ffdine_ie_mask                                  (0x00000004)
#define ST_DDC_SFIR_3_cippt_ie_mask                                   (0x00000002)
#define ST_DDC_SFIR_3_cispt_ie_mask                                   (0x00000001)
#define ST_DDC_SFIR_3_ffdouf_ie(data)                                 (0x00000080&((data)<<7))
#define ST_DDC_SFIR_3_ffdiof_ie(data)                                 (0x00000040&((data)<<6))
#define ST_DDC_SFIR_3_ffdonf_ie(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_SFIR_3_ffdoet_ie(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_SFIR_3_ffdifu_ie(data)                                 (0x00000008&((data)<<3))
#define ST_DDC_SFIR_3_ffdine_ie(data)                                 (0x00000004&((data)<<2))
#define ST_DDC_SFIR_3_cippt_ie(data)                                  (0x00000002&((data)<<1))
#define ST_DDC_SFIR_3_cispt_ie(data)                                  (0x00000001&(data))
#define ST_DDC_SFIR_3_get_ffdouf_ie(data)                             ((0x00000080&(data))>>7)
#define ST_DDC_SFIR_3_get_ffdiof_ie(data)                             ((0x00000040&(data))>>6)
#define ST_DDC_SFIR_3_get_ffdonf_ie(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_SFIR_3_get_ffdoet_ie(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_SFIR_3_get_ffdifu_ie(data)                             ((0x00000008&(data))>>3)
#define ST_DDC_SFIR_3_get_ffdine_ie(data)                             ((0x00000004&(data))>>2)
#define ST_DDC_SFIR_3_get_cippt_ie(data)                              ((0x00000002&(data))>>1)
#define ST_DDC_SFIR_3_get_cispt_ie(data)                              (0x00000001&(data))


#define ST_DDC_FSMS_3                                                 0x18061c64
#define ST_DDC_FSMS_3_reg_addr                                        "0xb8061c64"
#define ST_DDC_FSMS_3_reg                                             0xb8061c64
#define ST_DDC_FSMS_3_inst_addr                                       "0x0359"
#define ST_DDC_FSMS_3_inst                                            0x0359
#define ST_DDC_FSMS_3_cmdfsm_st_shift                                 (0)
#define ST_DDC_FSMS_3_cmdfsm_st_mask                                  (0x000000FF)
#define ST_DDC_FSMS_3_cmdfsm_st(data)                                 (0x000000FF&(data))
#define ST_DDC_FSMS_3_get_cmdfsm_st(data)                             (0x000000FF&(data))


#define ST_I2C_CR_4                                                   0x18061d00
#define ST_I2C_CR_4_reg_addr                                          "0xb8061d00"
#define ST_I2C_CR_4_reg                                               0xb8061d00
#define ST_I2C_CR_4_inst_addr                                         "0x0380"
#define ST_I2C_CR_4_inst                                              0x0380
#define ST_I2C_CR_4_cmderr_ie_shift                                   (7)
#define ST_I2C_CR_4_timeout_en_shift                                  (6)
#define ST_I2C_CR_4_debounce_mode_shift                               (4)
#define ST_I2C_CR_4_timeout_ie_shift                                  (3)
#define ST_I2C_CR_4_retime_m_shift                                    (0)
#define ST_I2C_CR_4_cmderr_ie_mask                                    (0x00000080)
#define ST_I2C_CR_4_timeout_en_mask                                   (0x00000040)
#define ST_I2C_CR_4_debounce_mode_mask                                (0x00000030)
#define ST_I2C_CR_4_timeout_ie_mask                                   (0x00000008)
#define ST_I2C_CR_4_retime_m_mask                                     (0x00000007)
#define ST_I2C_CR_4_cmderr_ie(data)                                   (0x00000080&((data)<<7))
#define ST_I2C_CR_4_timeout_en(data)                                  (0x00000040&((data)<<6))
#define ST_I2C_CR_4_debounce_mode(data)                               (0x00000030&((data)<<4))
#define ST_I2C_CR_4_timeout_ie(data)                                  (0x00000008&((data)<<3))
#define ST_I2C_CR_4_retime_m(data)                                    (0x00000007&(data))
#define ST_I2C_CR_4_get_cmderr_ie(data)                               ((0x00000080&(data))>>7)
#define ST_I2C_CR_4_get_timeout_en(data)                              ((0x00000040&(data))>>6)
#define ST_I2C_CR_4_get_debounce_mode(data)                           ((0x00000030&(data))>>4)
#define ST_I2C_CR_4_get_timeout_ie(data)                              ((0x00000008&(data))>>3)
#define ST_I2C_CR_4_get_retime_m(data)                                (0x00000007&(data))


#define ST_I2C_SR_4                                                   0x18061d04
#define ST_I2C_SR_4_reg_addr                                          "0xb8061d04"
#define ST_I2C_SR_4_reg                                               0xb8061d04
#define ST_I2C_SR_4_inst_addr                                         "0x0381"
#define ST_I2C_SR_4_inst                                              0x0381
#define ST_I2C_SR_4_cmderr_shift                                      (7)
#define ST_I2C_SR_4_finish_shift                                      (4)
#define ST_I2C_SR_4_timeout_shift                                     (3)
#define ST_I2C_SR_4_cmderr_mask                                       (0x00000080)
#define ST_I2C_SR_4_finish_mask                                       (0x00000010)
#define ST_I2C_SR_4_timeout_mask                                      (0x00000008)
#define ST_I2C_SR_4_cmderr(data)                                      (0x00000080&((data)<<7))
#define ST_I2C_SR_4_finish(data)                                      (0x00000010&((data)<<4))
#define ST_I2C_SR_4_timeout(data)                                     (0x00000008&((data)<<3))
#define ST_I2C_SR_4_get_cmderr(data)                                  ((0x00000080&(data))>>7)
#define ST_I2C_SR_4_get_finish(data)                                  ((0x00000010&(data))>>4)
#define ST_I2C_SR_4_get_timeout(data)                                 ((0x00000008&(data))>>3)


#define ST_I2C_TR_4                                                   0x18061d08
#define ST_I2C_TR_4_reg_addr                                          "0xb8061d08"
#define ST_I2C_TR_4_reg                                               0xb8061d08
#define ST_I2C_TR_4_inst_addr                                         "0x0382"
#define ST_I2C_TR_4_inst                                              0x0382
#define ST_I2C_TR_4_timeout_val_shift                                 (0)
#define ST_I2C_TR_4_timeout_val_mask                                  (0x000000FF)
#define ST_I2C_TR_4_timeout_val(data)                                 (0x000000FF&(data))
#define ST_I2C_TR_4_get_timeout_val(data)                             (0x000000FF&(data))


#define ST_EDID_CR_4                                                  0x18061d0c
#define ST_EDID_CR_4_reg_addr                                         "0xb8061d0c"
#define ST_EDID_CR_4_reg                                              0xb8061d0c
#define ST_EDID_CR_4_inst_addr                                        "0x0383"
#define ST_EDID_CR_4_inst                                             0x0383
#define ST_EDID_CR_4_edid_address_shift                               (5)
#define ST_EDID_CR_4_finish_int_en_shift                              (4)
#define ST_EDID_CR_4_ddc1_force_shift                                 (3)
#define ST_EDID_CR_4_ddc2b_force_shift                                (2)
#define ST_EDID_CR_4_edid_srwen_shift                                 (1)
#define ST_EDID_CR_4_edid_en_shift                                    (0)
#define ST_EDID_CR_4_edid_address_mask                                (0x000000E0)
#define ST_EDID_CR_4_finish_int_en_mask                               (0x00000010)
#define ST_EDID_CR_4_ddc1_force_mask                                  (0x00000008)
#define ST_EDID_CR_4_ddc2b_force_mask                                 (0x00000004)
#define ST_EDID_CR_4_edid_srwen_mask                                  (0x00000002)
#define ST_EDID_CR_4_edid_en_mask                                     (0x00000001)
#define ST_EDID_CR_4_edid_address(data)                               (0x000000E0&((data)<<5))
#define ST_EDID_CR_4_finish_int_en(data)                              (0x00000010&((data)<<4))
#define ST_EDID_CR_4_ddc1_force(data)                                 (0x00000008&((data)<<3))
#define ST_EDID_CR_4_ddc2b_force(data)                                (0x00000004&((data)<<2))
#define ST_EDID_CR_4_edid_srwen(data)                                 (0x00000002&((data)<<1))
#define ST_EDID_CR_4_edid_en(data)                                    (0x00000001&(data))
#define ST_EDID_CR_4_get_edid_address(data)                           ((0x000000E0&(data))>>5)
#define ST_EDID_CR_4_get_finish_int_en(data)                          ((0x00000010&(data))>>4)
#define ST_EDID_CR_4_get_ddc1_force(data)                             ((0x00000008&(data))>>3)
#define ST_EDID_CR_4_get_ddc2b_force(data)                            ((0x00000004&(data))>>2)
#define ST_EDID_CR_4_get_edid_srwen(data)                             ((0x00000002&(data))>>1)
#define ST_EDID_CR_4_get_edid_en(data)                                (0x00000001&(data))


#define ST_DDC_VCR_4                                                  0x18061d10
#define ST_DDC_VCR_4_reg_addr                                         "0xb8061d10"
#define ST_DDC_VCR_4_reg                                              0xb8061d10
#define ST_DDC_VCR_4_inst_addr                                        "0x0384"
#define ST_DDC_VCR_4_inst                                             0x0384
#define ST_DDC_VCR_4_ddc1_vcount_shift                                (0)
#define ST_DDC_VCR_4_ddc1_vcount_mask                                 (0x000000FF)
#define ST_DDC_VCR_4_ddc1_vcount(data)                                (0x000000FF&(data))
#define ST_DDC_VCR_4_get_ddc1_vcount(data)                            (0x000000FF&(data))


#define ST_EDID_IMSWSAR_4                                             0x18061d14
#define ST_EDID_IMSWSAR_4_reg_addr                                    "0xb8061d14"
#define ST_EDID_IMSWSAR_4_reg                                         0xb8061d14
#define ST_EDID_IMSWSAR_4_inst_addr                                   "0x0385"
#define ST_EDID_IMSWSAR_4_inst                                        0x0385
#define ST_EDID_IMSWSAR_4_edid_sadr_shift                             (0)
#define ST_EDID_IMSWSAR_4_edid_sadr_mask                              (0x000000FF)
#define ST_EDID_IMSWSAR_4_edid_sadr(data)                             (0x000000FF&(data))
#define ST_EDID_IMSWSAR_4_get_edid_sadr(data)                         (0x000000FF&(data))


#define ST_EDID_IMSWEAR_4                                             0x18061d18
#define ST_EDID_IMSWEAR_4_reg_addr                                    "0xb8061d18"
#define ST_EDID_IMSWEAR_4_reg                                         0xb8061d18
#define ST_EDID_IMSWEAR_4_inst_addr                                   "0x0386"
#define ST_EDID_IMSWEAR_4_inst                                        0x0386
#define ST_EDID_IMSWEAR_4_edid_eadr_shift                             (0)
#define ST_EDID_IMSWEAR_4_edid_eadr_mask                              (0x000000FF)
#define ST_EDID_IMSWEAR_4_edid_eadr(data)                             (0x000000FF&(data))
#define ST_EDID_IMSWEAR_4_get_edid_eadr(data)                         (0x000000FF&(data))


#define ST_EDID_IR_4                                                  0x18061d1c
#define ST_EDID_IR_4_reg_addr                                         "0xb8061d1c"
#define ST_EDID_IR_4_reg                                              0xb8061d1c
#define ST_EDID_IR_4_inst_addr                                        "0x0387"
#define ST_EDID_IR_4_inst                                             0x0387
#define ST_EDID_IR_4_edidmode_shift                                   (6)
#define ST_EDID_IR_4_edidsubaddress_shift                             (5)
#define ST_EDID_IR_4_edidstop_shift                                   (4)
#define ST_EDID_IR_4_edidsubaddress_ie_shift                          (1)
#define ST_EDID_IR_4_edidstop_ie_shift                                (0)
#define ST_EDID_IR_4_edidmode_mask                                    (0x00000040)
#define ST_EDID_IR_4_edidsubaddress_mask                              (0x00000020)
#define ST_EDID_IR_4_edidstop_mask                                    (0x00000010)
#define ST_EDID_IR_4_edidsubaddress_ie_mask                           (0x00000002)
#define ST_EDID_IR_4_edidstop_ie_mask                                 (0x00000001)
#define ST_EDID_IR_4_edidmode(data)                                   (0x00000040&((data)<<6))
#define ST_EDID_IR_4_edidsubaddress(data)                             (0x00000020&((data)<<5))
#define ST_EDID_IR_4_edidstop(data)                                   (0x00000010&((data)<<4))
#define ST_EDID_IR_4_edidsubaddress_ie(data)                          (0x00000002&((data)<<1))
#define ST_EDID_IR_4_edidstop_ie(data)                                (0x00000001&(data))
#define ST_EDID_IR_4_get_edidmode(data)                               ((0x00000040&(data))>>6)
#define ST_EDID_IR_4_get_edidsubaddress(data)                         ((0x00000020&(data))>>5)
#define ST_EDID_IR_4_get_edidstop(data)                               ((0x00000010&(data))>>4)
#define ST_EDID_IR_4_get_edidsubaddress_ie(data)                      ((0x00000002&(data))>>1)
#define ST_EDID_IR_4_get_edidstop_ie(data)                            (0x00000001&(data))


#define ST_DDC_SIR_4                                                  0x18061d20
#define ST_DDC_SIR_4_reg_addr                                         "0xb8061d20"
#define ST_DDC_SIR_4_reg                                              0xb8061d20
#define ST_DDC_SIR_4_inst_addr                                        "0x0388"
#define ST_DDC_SIR_4_inst                                             0x0388
#define ST_DDC_SIR_4_edidap_shift                                     (0)
#define ST_DDC_SIR_4_edidap_mask                                      (0x000000FF)
#define ST_DDC_SIR_4_edidap(data)                                     (0x000000FF&(data))
#define ST_DDC_SIR_4_get_edidap(data)                                 (0x000000FF&(data))


#define ST_DDC_SAP_4                                                  0x18061d24
#define ST_DDC_SAP_4_reg_addr                                         "0xb8061d24"
#define ST_DDC_SAP_4_reg                                              0xb8061d24
#define ST_DDC_SAP_4_inst_addr                                        "0x0389"
#define ST_DDC_SAP_4_inst                                             0x0389
#define ST_DDC_SAP_4_ediddp_shift                                     (0)
#define ST_DDC_SAP_4_ediddp_mask                                      (0x000000FF)
#define ST_DDC_SAP_4_ediddp(data)                                     (0x000000FF&(data))
#define ST_DDC_SAP_4_get_ediddp(data)                                 (0x000000FF&(data))


#define ST_DDC_BISTCR_4                                               0x18061d28
#define ST_DDC_BISTCR_4_reg_addr                                      "0xb8061d28"
#define ST_DDC_BISTCR_4_reg                                           0xb8061d28
#define ST_DDC_BISTCR_4_inst_addr                                     "0x038A"
#define ST_DDC_BISTCR_4_inst                                          0x038A
#define ST_DDC_BISTCR_4_bist_fail_shift                               (5)
#define ST_DDC_BISTCR_4_bist_done_shift                               (4)
#define ST_DDC_BISTCR_4_bist_rstn_shift                               (1)
#define ST_DDC_BISTCR_4_bist_mode_shift                               (0)
#define ST_DDC_BISTCR_4_bist_fail_mask                                (0x00000020)
#define ST_DDC_BISTCR_4_bist_done_mask                                (0x00000010)
#define ST_DDC_BISTCR_4_bist_rstn_mask                                (0x00000002)
#define ST_DDC_BISTCR_4_bist_mode_mask                                (0x00000001)
#define ST_DDC_BISTCR_4_bist_fail(data)                               (0x00000020&((data)<<5))
#define ST_DDC_BISTCR_4_bist_done(data)                               (0x00000010&((data)<<4))
#define ST_DDC_BISTCR_4_bist_rstn(data)                               (0x00000002&((data)<<1))
#define ST_DDC_BISTCR_4_bist_mode(data)                               (0x00000001&(data))
#define ST_DDC_BISTCR_4_get_bist_fail(data)                           ((0x00000020&(data))>>5)
#define ST_DDC_BISTCR_4_get_bist_done(data)                           ((0x00000010&(data))>>4)
#define ST_DDC_BISTCR_4_get_bist_rstn(data)                           ((0x00000002&(data))>>1)
#define ST_DDC_BISTCR_4_get_bist_mode(data)                           (0x00000001&(data))


#define ST_DDC_SCR_4                                                  0x18061d2c
#define ST_DDC_SCR_4_reg_addr                                         "0xb8061d2c"
#define ST_DDC_SCR_4_reg                                              0xb8061d2c
#define ST_DDC_SCR_4_inst_addr                                        "0x038B"
#define ST_DDC_SCR_4_inst                                             0x038B
#define ST_DDC_SCR_4_segpt_latie_shift                                (7)
#define ST_DDC_SCR_4_sgid_en_shift                                    (0)
#define ST_DDC_SCR_4_segpt_latie_mask                                 (0x00000080)
#define ST_DDC_SCR_4_sgid_en_mask                                     (0x00000001)
#define ST_DDC_SCR_4_segpt_latie(data)                                (0x00000080&((data)<<7))
#define ST_DDC_SCR_4_sgid_en(data)                                    (0x00000001&(data))
#define ST_DDC_SCR_4_get_segpt_latie(data)                            ((0x00000080&(data))>>7)
#define ST_DDC_SCR_4_get_sgid_en(data)                                (0x00000001&(data))


#define ST_DDC_SSAR_4                                                 0x18061d30
#define ST_DDC_SSAR_4_reg_addr                                        "0xb8061d30"
#define ST_DDC_SSAR_4_reg                                             0xb8061d30
#define ST_DDC_SSAR_4_inst_addr                                       "0x038C"
#define ST_DDC_SSAR_4_inst                                            0x038C
#define ST_DDC_SSAR_4_sgid_address_shift                              (1)
#define ST_DDC_SSAR_4_sgid_dtrden_shift                               (0)
#define ST_DDC_SSAR_4_sgid_address_mask                               (0x000000FE)
#define ST_DDC_SSAR_4_sgid_dtrden_mask                                (0x00000001)
#define ST_DDC_SSAR_4_sgid_address(data)                              (0x000000FE&((data)<<1))
#define ST_DDC_SSAR_4_sgid_dtrden(data)                               (0x00000001&(data))
#define ST_DDC_SSAR_4_get_sgid_address(data)                          ((0x000000FE&(data))>>1)
#define ST_DDC_SSAR_4_get_sgid_dtrden(data)                           (0x00000001&(data))


#define ST_DDC_SPR_4                                                  0x18061d34
#define ST_DDC_SPR_4_reg_addr                                         "0xb8061d34"
#define ST_DDC_SPR_4_reg                                              0xb8061d34
#define ST_DDC_SPR_4_inst_addr                                        "0x038D"
#define ST_DDC_SPR_4_inst                                             0x038D
#define ST_DDC_SPR_4_segpt_latched_shift                              (7)
#define ST_DDC_SPR_4_seg_pt_shift                                     (0)
#define ST_DDC_SPR_4_segpt_latched_mask                               (0x00000080)
#define ST_DDC_SPR_4_seg_pt_mask                                      (0x0000007F)
#define ST_DDC_SPR_4_segpt_latched(data)                              (0x00000080&((data)<<7))
#define ST_DDC_SPR_4_seg_pt(data)                                     (0x0000007F&(data))
#define ST_DDC_SPR_4_get_segpt_latched(data)                          ((0x00000080&(data))>>7)
#define ST_DDC_SPR_4_get_seg_pt(data)                                 (0x0000007F&(data))


#define ST_DDC_SFCR_4                                                 0x18061d38
#define ST_DDC_SFCR_4_reg_addr                                        "0xb8061d38"
#define ST_DDC_SFCR_4_reg                                             0xb8061d38
#define ST_DDC_SFCR_4_inst_addr                                       "0x038E"
#define ST_DDC_SFCR_4_inst                                            0x038E
#define ST_DDC_SFCR_4_special_mode_shift                              (3)
#define ST_DDC_SFCR_4_doffpt_reset_shift                              (2)
#define ST_DDC_SFCR_4_diffpt_reset_shift                              (1)
#define ST_DDC_SFCR_4_ciid_en_shift                                   (0)
#define ST_DDC_SFCR_4_special_mode_mask                               (0x00000008)
#define ST_DDC_SFCR_4_doffpt_reset_mask                               (0x00000004)
#define ST_DDC_SFCR_4_diffpt_reset_mask                               (0x00000002)
#define ST_DDC_SFCR_4_ciid_en_mask                                    (0x00000001)
#define ST_DDC_SFCR_4_special_mode(data)                              (0x00000008&((data)<<3))
#define ST_DDC_SFCR_4_doffpt_reset(data)                              (0x00000004&((data)<<2))
#define ST_DDC_SFCR_4_diffpt_reset(data)                              (0x00000002&((data)<<1))
#define ST_DDC_SFCR_4_ciid_en(data)                                   (0x00000001&(data))
#define ST_DDC_SFCR_4_get_special_mode(data)                          ((0x00000008&(data))>>3)
#define ST_DDC_SFCR_4_get_doffpt_reset(data)                          ((0x00000004&(data))>>2)
#define ST_DDC_SFCR_4_get_diffpt_reset(data)                          ((0x00000002&(data))>>1)
#define ST_DDC_SFCR_4_get_ciid_en(data)                               (0x00000001&(data))


#define ST_DDC_SFSAR_4                                                0x18061d3c
#define ST_DDC_SFSAR_4_reg_addr                                       "0xb8061d3c"
#define ST_DDC_SFSAR_4_reg                                            0xb8061d3c
#define ST_DDC_SFSAR_4_inst_addr                                      "0x038F"
#define ST_DDC_SFSAR_4_inst                                           0x038F
#define ST_DDC_SFSAR_4_ciid_address_shift                             (1)
#define ST_DDC_SFSAR_4_cirws_current_shift                            (0)
#define ST_DDC_SFSAR_4_ciid_address_mask                              (0x000000FE)
#define ST_DDC_SFSAR_4_cirws_current_mask                             (0x00000001)
#define ST_DDC_SFSAR_4_ciid_address(data)                             (0x000000FE&((data)<<1))
#define ST_DDC_SFSAR_4_cirws_current(data)                            (0x00000001&(data))
#define ST_DDC_SFSAR_4_get_ciid_address(data)                         ((0x000000FE&(data))>>1)
#define ST_DDC_SFSAR_4_get_cirws_current(data)                        (0x00000001&(data))


#define ST_DDC_SFDR_4                                                 0x18061d40
#define ST_DDC_SFDR_4_reg_addr                                        "0xb8061d40"
#define ST_DDC_SFDR_4_reg                                             0xb8061d40
#define ST_DDC_SFDR_4_inst_addr                                       "0x0390"
#define ST_DDC_SFDR_4_inst                                            0x0390
#define ST_DDC_SFDR_4_ciiddp_shift                                    (0)
#define ST_DDC_SFDR_4_ciiddp_mask                                     (0x000000FF)
#define ST_DDC_SFDR_4_ciiddp(data)                                    (0x000000FF&(data))
#define ST_DDC_SFDR_4_get_ciiddp(data)                                (0x000000FF&(data))


#define ST_DDC_SFBSR_4                                                0x18061d44
#define ST_DDC_SFBSR_4_reg_addr                                       "0xb8061d44"
#define ST_DDC_SFBSR_4_reg                                            0xb8061d44
#define ST_DDC_SFBSR_4_inst_addr                                      "0x0391"
#define ST_DDC_SFBSR_4_inst                                           0x0391
#define ST_DDC_SFBSR_4_cirws_2nd_shift                                (5)
#define ST_DDC_SFBSR_4_cirws_1st_shift                                (4)
#define ST_DDC_SFBSR_4_cippt_2nd_shift                                (3)
#define ST_DDC_SFBSR_4_cispt_2nd_shift                                (2)
#define ST_DDC_SFBSR_4_cippt_1st_shift                                (1)
#define ST_DDC_SFBSR_4_cispt_1st_shift                                (0)
#define ST_DDC_SFBSR_4_cirws_2nd_mask                                 (0x00000020)
#define ST_DDC_SFBSR_4_cirws_1st_mask                                 (0x00000010)
#define ST_DDC_SFBSR_4_cippt_2nd_mask                                 (0x00000008)
#define ST_DDC_SFBSR_4_cispt_2nd_mask                                 (0x00000004)
#define ST_DDC_SFBSR_4_cippt_1st_mask                                 (0x00000002)
#define ST_DDC_SFBSR_4_cispt_1st_mask                                 (0x00000001)
#define ST_DDC_SFBSR_4_cirws_2nd(data)                                (0x00000020&((data)<<5))
#define ST_DDC_SFBSR_4_cirws_1st(data)                                (0x00000010&((data)<<4))
#define ST_DDC_SFBSR_4_cippt_2nd(data)                                (0x00000008&((data)<<3))
#define ST_DDC_SFBSR_4_cispt_2nd(data)                                (0x00000004&((data)<<2))
#define ST_DDC_SFBSR_4_cippt_1st(data)                                (0x00000002&((data)<<1))
#define ST_DDC_SFBSR_4_cispt_1st(data)                                (0x00000001&(data))
#define ST_DDC_SFBSR_4_get_cirws_2nd(data)                            ((0x00000020&(data))>>5)
#define ST_DDC_SFBSR_4_get_cirws_1st(data)                            ((0x00000010&(data))>>4)
#define ST_DDC_SFBSR_4_get_cippt_2nd(data)                            ((0x00000008&(data))>>3)
#define ST_DDC_SFBSR_4_get_cispt_2nd(data)                            ((0x00000004&(data))>>2)
#define ST_DDC_SFBSR_4_get_cippt_1st(data)                            ((0x00000002&(data))>>1)
#define ST_DDC_SFBSR_4_get_cispt_1st(data)                            (0x00000001&(data))


#define ST_DDC_SFIBLR_4                                               0x18061d48
#define ST_DDC_SFIBLR_4_reg_addr                                      "0xb8061d48"
#define ST_DDC_SFIBLR_4_reg                                           0xb8061d48
#define ST_DDC_SFIBLR_4_inst_addr                                     "0x0392"
#define ST_DDC_SFIBLR_4_inst                                          0x0392
#define ST_DDC_SFIBLR_4_ffdi_dlen_shift                               (0)
#define ST_DDC_SFIBLR_4_ffdi_dlen_mask                                (0x0000001F)
#define ST_DDC_SFIBLR_4_ffdi_dlen(data)                               (0x0000001F&(data))
#define ST_DDC_SFIBLR_4_get_ffdi_dlen(data)                           (0x0000001F&(data))


#define ST_DDC_SFIBRWPR_4                                             0x18061d4c
#define ST_DDC_SFIBRWPR_4_reg_addr                                    "0xb8061d4c"
#define ST_DDC_SFIBRWPR_4_reg                                         0xb8061d4c
#define ST_DDC_SFIBRWPR_4_inst_addr                                   "0x0393"
#define ST_DDC_SFIBRWPR_4_inst                                        0x0393
#define ST_DDC_SFIBRWPR_4_diff_wpt_shift                              (4)
#define ST_DDC_SFIBRWPR_4_diff_rpt_shift                              (0)
#define ST_DDC_SFIBRWPR_4_diff_wpt_mask                               (0x000000F0)
#define ST_DDC_SFIBRWPR_4_diff_rpt_mask                               (0x0000000F)
#define ST_DDC_SFIBRWPR_4_diff_wpt(data)                              (0x000000F0&((data)<<4))
#define ST_DDC_SFIBRWPR_4_diff_rpt(data)                              (0x0000000F&(data))
#define ST_DDC_SFIBRWPR_4_get_diff_wpt(data)                          ((0x000000F0&(data))>>4)
#define ST_DDC_SFIBRWPR_4_get_diff_rpt(data)                          (0x0000000F&(data))


#define ST_DDC_SFIBSWPR_4                                             0x18061d50
#define ST_DDC_SFIBSWPR_4_reg_addr                                    "0xb8061d50"
#define ST_DDC_SFIBSWPR_4_reg                                         0xb8061d50
#define ST_DDC_SFIBSWPR_4_inst_addr                                   "0x0394"
#define ST_DDC_SFIBSWPR_4_inst                                        0x0394
#define ST_DDC_SFIBSWPR_4_diffstop_pt_shift                           (0)
#define ST_DDC_SFIBSWPR_4_diffstop_pt_mask                            (0x0000000F)
#define ST_DDC_SFIBSWPR_4_diffstop_pt(data)                           (0x0000000F&(data))
#define ST_DDC_SFIBSWPR_4_get_diffstop_pt(data)                       (0x0000000F&(data))


#define ST_DDC_SFOBSR_4                                               0x18061d54
#define ST_DDC_SFOBSR_4_reg_addr                                      "0xb8061d54"
#define ST_DDC_SFOBSR_4_reg                                           0xb8061d54
#define ST_DDC_SFOBSR_4_inst_addr                                     "0x0395"
#define ST_DDC_SFOBSR_4_inst                                          0x0395
#define ST_DDC_SFOBSR_4_ffdo_dlen_shift                               (0)
#define ST_DDC_SFOBSR_4_ffdo_dlen_mask                                (0x0000001F)
#define ST_DDC_SFOBSR_4_ffdo_dlen(data)                               (0x0000001F&(data))
#define ST_DDC_SFOBSR_4_get_ffdo_dlen(data)                           (0x0000001F&(data))


#define ST_DDC_SFOBRWPR_4                                             0x18061d58
#define ST_DDC_SFOBRWPR_4_reg_addr                                    "0xb8061d58"
#define ST_DDC_SFOBRWPR_4_reg                                         0xb8061d58
#define ST_DDC_SFOBRWPR_4_inst_addr                                   "0x0396"
#define ST_DDC_SFOBRWPR_4_inst                                        0x0396
#define ST_DDC_SFOBRWPR_4_doff_wpt_shift                              (4)
#define ST_DDC_SFOBRWPR_4_doff_rpt_shift                              (0)
#define ST_DDC_SFOBRWPR_4_doff_wpt_mask                               (0x000000F0)
#define ST_DDC_SFOBRWPR_4_doff_rpt_mask                               (0x0000000F)
#define ST_DDC_SFOBRWPR_4_doff_wpt(data)                              (0x000000F0&((data)<<4))
#define ST_DDC_SFOBRWPR_4_doff_rpt(data)                              (0x0000000F&(data))
#define ST_DDC_SFOBRWPR_4_get_doff_wpt(data)                          ((0x000000F0&(data))>>4)
#define ST_DDC_SFOBRWPR_4_get_doff_rpt(data)                          (0x0000000F&(data))


#define ST_DDC_SFSR_4                                                 0x18061d5c
#define ST_DDC_SFSR_4_reg_addr                                        "0xb8061d5c"
#define ST_DDC_SFSR_4_reg                                             0xb8061d5c
#define ST_DDC_SFSR_4_inst_addr                                       "0x0397"
#define ST_DDC_SFSR_4_inst                                            0x0397
#define ST_DDC_SFSR_4_ffdouf_st_shift                                 (7)
#define ST_DDC_SFSR_4_ffdiof_st_shift                                 (6)
#define ST_DDC_SFSR_4_ffdonf_st_shift                                 (5)
#define ST_DDC_SFSR_4_ffdoet_st_shift                                 (4)
#define ST_DDC_SFSR_4_ffdifu_st_shift                                 (3)
#define ST_DDC_SFSR_4_ffdine_st_shift                                 (2)
#define ST_DDC_SFSR_4_ffdouf_st_mask                                  (0x00000080)
#define ST_DDC_SFSR_4_ffdiof_st_mask                                  (0x00000040)
#define ST_DDC_SFSR_4_ffdonf_st_mask                                  (0x00000020)
#define ST_DDC_SFSR_4_ffdoet_st_mask                                  (0x00000010)
#define ST_DDC_SFSR_4_ffdifu_st_mask                                  (0x00000008)
#define ST_DDC_SFSR_4_ffdine_st_mask                                  (0x00000004)
#define ST_DDC_SFSR_4_ffdouf_st(data)                                 (0x00000080&((data)<<7))
#define ST_DDC_SFSR_4_ffdiof_st(data)                                 (0x00000040&((data)<<6))
#define ST_DDC_SFSR_4_ffdonf_st(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_SFSR_4_ffdoet_st(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_SFSR_4_ffdifu_st(data)                                 (0x00000008&((data)<<3))
#define ST_DDC_SFSR_4_ffdine_st(data)                                 (0x00000004&((data)<<2))
#define ST_DDC_SFSR_4_get_ffdouf_st(data)                             ((0x00000080&(data))>>7)
#define ST_DDC_SFSR_4_get_ffdiof_st(data)                             ((0x00000040&(data))>>6)
#define ST_DDC_SFSR_4_get_ffdonf_st(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_SFSR_4_get_ffdoet_st(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_SFSR_4_get_ffdifu_st(data)                             ((0x00000008&(data))>>3)
#define ST_DDC_SFSR_4_get_ffdine_st(data)                             ((0x00000004&(data))>>2)


#define ST_DDC_SFIR_4                                                 0x18061d60
#define ST_DDC_SFIR_4_reg_addr                                        "0xb8061d60"
#define ST_DDC_SFIR_4_reg                                             0xb8061d60
#define ST_DDC_SFIR_4_inst_addr                                       "0x0398"
#define ST_DDC_SFIR_4_inst                                            0x0398
#define ST_DDC_SFIR_4_ffdouf_ie_shift                                 (7)
#define ST_DDC_SFIR_4_ffdiof_ie_shift                                 (6)
#define ST_DDC_SFIR_4_ffdonf_ie_shift                                 (5)
#define ST_DDC_SFIR_4_ffdoet_ie_shift                                 (4)
#define ST_DDC_SFIR_4_ffdifu_ie_shift                                 (3)
#define ST_DDC_SFIR_4_ffdine_ie_shift                                 (2)
#define ST_DDC_SFIR_4_cippt_ie_shift                                  (1)
#define ST_DDC_SFIR_4_cispt_ie_shift                                  (0)
#define ST_DDC_SFIR_4_ffdouf_ie_mask                                  (0x00000080)
#define ST_DDC_SFIR_4_ffdiof_ie_mask                                  (0x00000040)
#define ST_DDC_SFIR_4_ffdonf_ie_mask                                  (0x00000020)
#define ST_DDC_SFIR_4_ffdoet_ie_mask                                  (0x00000010)
#define ST_DDC_SFIR_4_ffdifu_ie_mask                                  (0x00000008)
#define ST_DDC_SFIR_4_ffdine_ie_mask                                  (0x00000004)
#define ST_DDC_SFIR_4_cippt_ie_mask                                   (0x00000002)
#define ST_DDC_SFIR_4_cispt_ie_mask                                   (0x00000001)
#define ST_DDC_SFIR_4_ffdouf_ie(data)                                 (0x00000080&((data)<<7))
#define ST_DDC_SFIR_4_ffdiof_ie(data)                                 (0x00000040&((data)<<6))
#define ST_DDC_SFIR_4_ffdonf_ie(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_SFIR_4_ffdoet_ie(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_SFIR_4_ffdifu_ie(data)                                 (0x00000008&((data)<<3))
#define ST_DDC_SFIR_4_ffdine_ie(data)                                 (0x00000004&((data)<<2))
#define ST_DDC_SFIR_4_cippt_ie(data)                                  (0x00000002&((data)<<1))
#define ST_DDC_SFIR_4_cispt_ie(data)                                  (0x00000001&(data))
#define ST_DDC_SFIR_4_get_ffdouf_ie(data)                             ((0x00000080&(data))>>7)
#define ST_DDC_SFIR_4_get_ffdiof_ie(data)                             ((0x00000040&(data))>>6)
#define ST_DDC_SFIR_4_get_ffdonf_ie(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_SFIR_4_get_ffdoet_ie(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_SFIR_4_get_ffdifu_ie(data)                             ((0x00000008&(data))>>3)
#define ST_DDC_SFIR_4_get_ffdine_ie(data)                             ((0x00000004&(data))>>2)
#define ST_DDC_SFIR_4_get_cippt_ie(data)                              ((0x00000002&(data))>>1)
#define ST_DDC_SFIR_4_get_cispt_ie(data)                              (0x00000001&(data))


#define ST_DDC_FSMS_4                                                 0x18061d64
#define ST_DDC_FSMS_4_reg_addr                                        "0xb8061d64"
#define ST_DDC_FSMS_4_reg                                             0xb8061d64
#define ST_DDC_FSMS_4_inst_addr                                       "0x0399"
#define ST_DDC_FSMS_4_inst                                            0x0399
#define ST_DDC_FSMS_4_cmdfsm_st_shift                                 (0)
#define ST_DDC_FSMS_4_cmdfsm_st_mask                                  (0x000000FF)
#define ST_DDC_FSMS_4_cmdfsm_st(data)                                 (0x000000FF&(data))
#define ST_DDC_FSMS_4_get_cmdfsm_st(data)                             (0x000000FF&(data))


#endif	//_RBUS_DDC_REG_H_
