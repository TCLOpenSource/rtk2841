/**
* @file Mac5-DesignSpec-SD
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SD_ALL_TOP_REG_H_
#define _RBUS_SD_ALL_TOP_REG_H_

#include "rbus_types.h"



//  SD_ALL_TOP Register Address
#define  SD_ALL_TOP_SD_CONFIGURE1                                                0x18010C00
#define  SD_ALL_TOP_SD_CONFIGURE1_reg_addr                                       "0xB8010C00"
#define  SD_ALL_TOP_SD_CONFIGURE1_reg                                            0xB8010C00
#define  SD_ALL_TOP_SD_CONFIGURE1_inst_addr                                      "0x0000"
#define  set_SD_ALL_TOP_SD_CONFIGURE1_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_CONFIGURE1_reg)=data)
#define  get_SD_ALL_TOP_SD_CONFIGURE1_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_CONFIGURE1_reg))
#define  SD_ALL_TOP_SD_CONFIGURE1_initialmode_shift                              (7)
#define  SD_ALL_TOP_SD_CONFIGURE1_clockdivider_shift                             (6)
#define  SD_ALL_TOP_SD_CONFIGURE1_sd30_async_fifo_rst_n_shift                    (4)
#define  SD_ALL_TOP_SD_CONFIGURE1_modeselection_shift                            (2)
#define  SD_ALL_TOP_SD_CONFIGURE1_buswidth_shift                                 (0)
#define  SD_ALL_TOP_SD_CONFIGURE1_initialmode_mask                               (0x00000080)
#define  SD_ALL_TOP_SD_CONFIGURE1_clockdivider_mask                              (0x00000040)
#define  SD_ALL_TOP_SD_CONFIGURE1_sd30_async_fifo_rst_n_mask                     (0x00000010)
#define  SD_ALL_TOP_SD_CONFIGURE1_modeselection_mask                             (0x0000000C)
#define  SD_ALL_TOP_SD_CONFIGURE1_buswidth_mask                                  (0x00000003)
#define  SD_ALL_TOP_SD_CONFIGURE1_initialmode(data)                              (0x00000080&((data)<<7))
#define  SD_ALL_TOP_SD_CONFIGURE1_clockdivider(data)                             (0x00000040&((data)<<6))
#define  SD_ALL_TOP_SD_CONFIGURE1_sd30_async_fifo_rst_n(data)                    (0x00000010&((data)<<4))
#define  SD_ALL_TOP_SD_CONFIGURE1_modeselection(data)                            (0x0000000C&((data)<<2))
#define  SD_ALL_TOP_SD_CONFIGURE1_buswidth(data)                                 (0x00000003&(data))
#define  SD_ALL_TOP_SD_CONFIGURE1_get_initialmode(data)                          ((0x00000080&(data))>>7)
#define  SD_ALL_TOP_SD_CONFIGURE1_get_clockdivider(data)                         ((0x00000040&(data))>>6)
#define  SD_ALL_TOP_SD_CONFIGURE1_get_sd30_async_fifo_rst_n(data)                ((0x00000010&(data))>>4)
#define  SD_ALL_TOP_SD_CONFIGURE1_get_modeselection(data)                        ((0x0000000C&(data))>>2)
#define  SD_ALL_TOP_SD_CONFIGURE1_get_buswidth(data)                             (0x00000003&(data))

#define  SD_ALL_TOP_SD_CONFIGURE2                                                0x18010C04
#define  SD_ALL_TOP_SD_CONFIGURE2_reg_addr                                       "0xB8010C04"
#define  SD_ALL_TOP_SD_CONFIGURE2_reg                                            0xB8010C04
#define  SD_ALL_TOP_SD_CONFIGURE2_inst_addr                                      "0x0001"
#define  set_SD_ALL_TOP_SD_CONFIGURE2_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_CONFIGURE2_reg)=data)
#define  get_SD_ALL_TOP_SD_CONFIGURE2_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_CONFIGURE2_reg))
#define  SD_ALL_TOP_SD_CONFIGURE2_crc7calculationenable_shift                    (7)
#define  SD_ALL_TOP_SD_CONFIGURE2_crc16checkenable_shift                         (6)
#define  SD_ALL_TOP_SD_CONFIGURE2_waitwritecrcstatustimeoutenable_shift          (5)
#define  SD_ALL_TOP_SD_CONFIGURE2_ignorewritecrcerrorenable_shift                (4)
#define  SD_ALL_TOP_SD_CONFIGURE2_waitbusyendenable_shift                        (3)
#define  SD_ALL_TOP_SD_CONFIGURE2_crc7checkenable_shift                          (2)
#define  SD_ALL_TOP_SD_CONFIGURE2_responsetypeconfigure_shift                    (0)
#define  SD_ALL_TOP_SD_CONFIGURE2_crc7calculationenable_mask                     (0x00000080)
#define  SD_ALL_TOP_SD_CONFIGURE2_crc16checkenable_mask                          (0x00000040)
#define  SD_ALL_TOP_SD_CONFIGURE2_waitwritecrcstatustimeoutenable_mask           (0x00000020)
#define  SD_ALL_TOP_SD_CONFIGURE2_ignorewritecrcerrorenable_mask                 (0x00000010)
#define  SD_ALL_TOP_SD_CONFIGURE2_waitbusyendenable_mask                         (0x00000008)
#define  SD_ALL_TOP_SD_CONFIGURE2_crc7checkenable_mask                           (0x00000004)
#define  SD_ALL_TOP_SD_CONFIGURE2_responsetypeconfigure_mask                     (0x00000003)
#define  SD_ALL_TOP_SD_CONFIGURE2_crc7calculationenable(data)                    (0x00000080&((data)<<7))
#define  SD_ALL_TOP_SD_CONFIGURE2_crc16checkenable(data)                         (0x00000040&((data)<<6))
#define  SD_ALL_TOP_SD_CONFIGURE2_waitwritecrcstatustimeoutenable(data)          (0x00000020&((data)<<5))
#define  SD_ALL_TOP_SD_CONFIGURE2_ignorewritecrcerrorenable(data)                (0x00000010&((data)<<4))
#define  SD_ALL_TOP_SD_CONFIGURE2_waitbusyendenable(data)                        (0x00000008&((data)<<3))
#define  SD_ALL_TOP_SD_CONFIGURE2_crc7checkenable(data)                          (0x00000004&((data)<<2))
#define  SD_ALL_TOP_SD_CONFIGURE2_responsetypeconfigure(data)                    (0x00000003&(data))
#define  SD_ALL_TOP_SD_CONFIGURE2_get_crc7calculationenable(data)                ((0x00000080&(data))>>7)
#define  SD_ALL_TOP_SD_CONFIGURE2_get_crc16checkenable(data)                     ((0x00000040&(data))>>6)
#define  SD_ALL_TOP_SD_CONFIGURE2_get_waitwritecrcstatustimeoutenable(data)      ((0x00000020&(data))>>5)
#define  SD_ALL_TOP_SD_CONFIGURE2_get_ignorewritecrcerrorenable(data)            ((0x00000010&(data))>>4)
#define  SD_ALL_TOP_SD_CONFIGURE2_get_waitbusyendenable(data)                    ((0x00000008&(data))>>3)
#define  SD_ALL_TOP_SD_CONFIGURE2_get_crc7checkenable(data)                      ((0x00000004&(data))>>2)
#define  SD_ALL_TOP_SD_CONFIGURE2_get_responsetypeconfigure(data)                (0x00000003&(data))

#define  SD_ALL_TOP_SD_CONFIGURE3                                                0x18010C08
#define  SD_ALL_TOP_SD_CONFIGURE3_reg_addr                                       "0xB8010C08"
#define  SD_ALL_TOP_SD_CONFIGURE3_reg                                            0xB8010C08
#define  SD_ALL_TOP_SD_CONFIGURE3_inst_addr                                      "0x0002"
#define  set_SD_ALL_TOP_SD_CONFIGURE3_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_CONFIGURE3_reg)=data)
#define  get_SD_ALL_TOP_SD_CONFIGURE3_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_CONFIGURE3_reg))
#define  SD_ALL_TOP_SD_CONFIGURE3_sd_dummy_reg0_shift                            (1)
#define  SD_ALL_TOP_SD_CONFIGURE3_sdcmdresponsetimeoutenable_shift               (0)
#define  SD_ALL_TOP_SD_CONFIGURE3_sd_dummy_reg0_mask                             (0x000000FE)
#define  SD_ALL_TOP_SD_CONFIGURE3_sdcmdresponsetimeoutenable_mask                (0x00000001)
#define  SD_ALL_TOP_SD_CONFIGURE3_sd_dummy_reg0(data)                            (0x000000FE&((data)<<1))
#define  SD_ALL_TOP_SD_CONFIGURE3_sdcmdresponsetimeoutenable(data)               (0x00000001&(data))
#define  SD_ALL_TOP_SD_CONFIGURE3_get_sd_dummy_reg0(data)                        ((0x000000FE&(data))>>1)
#define  SD_ALL_TOP_SD_CONFIGURE3_get_sdcmdresponsetimeoutenable(data)           (0x00000001&(data))

#define  SD_ALL_TOP_SD_STATUS                                                    0x18010C0C
#define  SD_ALL_TOP_SD_STATUS_reg_addr                                           "0xB8010C0C"
#define  SD_ALL_TOP_SD_STATUS_reg                                                0xB8010C0C
#define  SD_ALL_TOP_SD_STATUS_inst_addr                                          "0x0003"
#define  set_SD_ALL_TOP_SD_STATUS_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_SD_STATUS_reg)=data)
#define  get_SD_ALL_TOP_SD_STATUS_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_SD_STATUS_reg))
#define  SD_ALL_TOP_SD_STATUS_crc7error_shift                                    (7)
#define  SD_ALL_TOP_SD_STATUS_crc16error_shift                                   (6)
#define  SD_ALL_TOP_SD_STATUS_writecrcerror_shift                                (5)
#define  SD_ALL_TOP_SD_STATUS_statusofwritecrc_shift                             (2)
#define  SD_ALL_TOP_SD_STATUS_getwritecrcstatustime_outerror_shift               (1)
#define  SD_ALL_TOP_SD_STATUS_sdtuningpatterncompareerror_shift                  (0)
#define  SD_ALL_TOP_SD_STATUS_crc7error_mask                                     (0x00000080)
#define  SD_ALL_TOP_SD_STATUS_crc16error_mask                                    (0x00000040)
#define  SD_ALL_TOP_SD_STATUS_writecrcerror_mask                                 (0x00000020)
#define  SD_ALL_TOP_SD_STATUS_statusofwritecrc_mask                              (0x0000001C)
#define  SD_ALL_TOP_SD_STATUS_getwritecrcstatustime_outerror_mask                (0x00000002)
#define  SD_ALL_TOP_SD_STATUS_sdtuningpatterncompareerror_mask                   (0x00000001)
#define  SD_ALL_TOP_SD_STATUS_crc7error(data)                                    (0x00000080&((data)<<7))
#define  SD_ALL_TOP_SD_STATUS_crc16error(data)                                   (0x00000040&((data)<<6))
#define  SD_ALL_TOP_SD_STATUS_writecrcerror(data)                                (0x00000020&((data)<<5))
#define  SD_ALL_TOP_SD_STATUS_statusofwritecrc(data)                             (0x0000001C&((data)<<2))
#define  SD_ALL_TOP_SD_STATUS_getwritecrcstatustime_outerror(data)               (0x00000002&((data)<<1))
#define  SD_ALL_TOP_SD_STATUS_sdtuningpatterncompareerror(data)                  (0x00000001&(data))
#define  SD_ALL_TOP_SD_STATUS_get_crc7error(data)                                ((0x00000080&(data))>>7)
#define  SD_ALL_TOP_SD_STATUS_get_crc16error(data)                               ((0x00000040&(data))>>6)
#define  SD_ALL_TOP_SD_STATUS_get_writecrcerror(data)                            ((0x00000020&(data))>>5)
#define  SD_ALL_TOP_SD_STATUS_get_statusofwritecrc(data)                         ((0x0000001C&(data))>>2)
#define  SD_ALL_TOP_SD_STATUS_get_getwritecrcstatustime_outerror(data)           ((0x00000002&(data))>>1)
#define  SD_ALL_TOP_SD_STATUS_get_sdtuningpatterncompareerror(data)              (0x00000001&(data))

#define  SD_ALL_TOP_SD_STATUS2                                                   0x18010C10
#define  SD_ALL_TOP_SD_STATUS2_reg_addr                                          "0xB8010C10"
#define  SD_ALL_TOP_SD_STATUS2_reg                                               0xB8010C10
#define  SD_ALL_TOP_SD_STATUS2_inst_addr                                         "0x0004"
#define  set_SD_ALL_TOP_SD_STATUS2_reg(data)                                     (*((volatile unsigned int*)SD_ALL_TOP_SD_STATUS2_reg)=data)
#define  get_SD_ALL_TOP_SD_STATUS2_reg                                           (*((volatile unsigned int*)SD_ALL_TOP_SD_STATUS2_reg))
#define  SD_ALL_TOP_SD_STATUS2_sdcmdresponsetimeouterror_shift                   (0)
#define  SD_ALL_TOP_SD_STATUS2_sdcmdresponsetimeouterror_mask                    (0x00000001)
#define  SD_ALL_TOP_SD_STATUS2_sdcmdresponsetimeouterror(data)                   (0x00000001&(data))
#define  SD_ALL_TOP_SD_STATUS2_get_sdcmdresponsetimeouterror(data)               (0x00000001&(data))

#define  SD_ALL_TOP_SD_BUS_STATUS                                                0x18010C14
#define  SD_ALL_TOP_SD_BUS_STATUS_reg_addr                                       "0xB8010C14"
#define  SD_ALL_TOP_SD_BUS_STATUS_reg                                            0xB8010C14
#define  SD_ALL_TOP_SD_BUS_STATUS_inst_addr                                      "0x0005"
#define  set_SD_ALL_TOP_SD_BUS_STATUS_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_BUS_STATUS_reg)=data)
#define  get_SD_ALL_TOP_SD_BUS_STATUS_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_BUS_STATUS_reg))
#define  SD_ALL_TOP_SD_BUS_STATUS_sd_clktoggleenable_shift                       (7)
#define  SD_ALL_TOP_SD_BUS_STATUS_stopsd_clktogglingwhennocmdordatatransfer_shift (6)
#define  SD_ALL_TOP_SD_BUS_STATUS_dat3dat0_shift                                 (1)
#define  SD_ALL_TOP_SD_BUS_STATUS_cmd_shift                                      (0)
#define  SD_ALL_TOP_SD_BUS_STATUS_sd_clktoggleenable_mask                        (0x00000080)
#define  SD_ALL_TOP_SD_BUS_STATUS_stopsd_clktogglingwhennocmdordatatransfer_mask (0x00000040)
#define  SD_ALL_TOP_SD_BUS_STATUS_dat3dat0_mask                                  (0x0000001E)
#define  SD_ALL_TOP_SD_BUS_STATUS_cmd_mask                                       (0x00000001)
#define  SD_ALL_TOP_SD_BUS_STATUS_sd_clktoggleenable(data)                       (0x00000080&((data)<<7))
#define  SD_ALL_TOP_SD_BUS_STATUS_stopsd_clktogglingwhennocmdordatatransfer(data) (0x00000040&((data)<<6))
#define  SD_ALL_TOP_SD_BUS_STATUS_dat3dat0(data)                                 (0x0000001E&((data)<<1))
#define  SD_ALL_TOP_SD_BUS_STATUS_cmd(data)                                      (0x00000001&(data))
#define  SD_ALL_TOP_SD_BUS_STATUS_get_sd_clktoggleenable(data)                   ((0x00000080&(data))>>7)
#define  SD_ALL_TOP_SD_BUS_STATUS_get_stopsd_clktogglingwhennocmdordatatransfer(data) ((0x00000040&(data))>>6)
#define  SD_ALL_TOP_SD_BUS_STATUS_get_dat3dat0(data)                             ((0x0000001E&(data))>>1)
#define  SD_ALL_TOP_SD_BUS_STATUS_get_cmd(data)                                  (0x00000001&(data))

#define  SD_ALL_TOP_SD_CMD_CODE                                                  0x18010C18
#define  SD_ALL_TOP_SD_CMD_CODE_reg_addr                                         "0xB8010C18"
#define  SD_ALL_TOP_SD_CMD_CODE_reg                                              0xB8010C18
#define  SD_ALL_TOP_SD_CMD_CODE_inst_addr                                        "0x0006"
#define  set_SD_ALL_TOP_SD_CMD_CODE_reg(data)                                    (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD_CODE_reg)=data)
#define  get_SD_ALL_TOP_SD_CMD_CODE_reg                                          (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD_CODE_reg))
#define  SD_ALL_TOP_SD_CMD_CODE_sd_dummy_reg1_shift                              (0)
#define  SD_ALL_TOP_SD_CMD_CODE_sd_dummy_reg1_mask                               (0x0000007F)
#define  SD_ALL_TOP_SD_CMD_CODE_sd_dummy_reg1(data)                              (0x0000007F&(data))
#define  SD_ALL_TOP_SD_CMD_CODE_get_sd_dummy_reg1(data)                          (0x0000007F&(data))

#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL                                          0x18010C1C
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_reg_addr                                 "0xB8010C1C"
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_reg                                      0xB8010C1C
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_inst_addr                                "0x0007"
#define  set_SD_ALL_TOP_SD_SAMPLE_POINT_CTL_reg(data)                            (*((volatile unsigned int*)SD_ALL_TOP_SD_SAMPLE_POINT_CTL_reg)=data)
#define  get_SD_ALL_TOP_SD_SAMPLE_POINT_CTL_reg                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_SAMPLE_POINT_CTL_reg))
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointtypeforddrdat_shift           (7)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointselectionforddrdat_shift      (6)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointtypeforddrcmd_shift           (5)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointselectionforddrcmd_shift      (4)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointselectionforsd20cmdordata_shift (3)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointtypeforddrdat_mask            (0x00000080)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointselectionforddrdat_mask       (0x00000040)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointtypeforddrcmd_mask            (0x00000020)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointselectionforddrcmd_mask       (0x00000010)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointselectionforsd20cmdordata_mask (0x00000008)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointtypeforddrdat(data)           (0x00000080&((data)<<7))
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointselectionforddrdat(data)      (0x00000040&((data)<<6))
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointtypeforddrcmd(data)           (0x00000020&((data)<<5))
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointselectionforddrcmd(data)      (0x00000010&((data)<<4))
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_samplepointselectionforsd20cmdordata(data) (0x00000008&((data)<<3))
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_get_samplepointtypeforddrdat(data)       ((0x00000080&(data))>>7)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_get_samplepointselectionforddrdat(data)  ((0x00000040&(data))>>6)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_get_samplepointtypeforddrcmd(data)       ((0x00000020&(data))>>5)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_get_samplepointselectionforddrcmd(data)  ((0x00000010&(data))>>4)
#define  SD_ALL_TOP_SD_SAMPLE_POINT_CTL_get_samplepointselectionforsd20cmdordata(data) ((0x00000008&(data))>>3)

#define  SD_ALL_TOP_SD_PUSH_POINT_CTL                                            0x18010C20
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_reg_addr                                   "0xB8010C20"
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_reg                                        0xB8010C20
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_inst_addr                                  "0x0008"
#define  set_SD_ALL_TOP_SD_PUSH_POINT_CTL_reg(data)                              (*((volatile unsigned int*)SD_ALL_TOP_SD_PUSH_POINT_CTL_reg)=data)
#define  get_SD_ALL_TOP_SD_PUSH_POINT_CTL_reg                                    (*((volatile unsigned int*)SD_ALL_TOP_SD_PUSH_POINT_CTL_reg))
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_pushpointselectiontypeforddrcmdordat_shift (7)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_pushpointselectionforddrmodedat_shift      (6)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_pushpointselectionforddrmodecmd_shift      (5)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_pushpointselectionforsd20modecmdordata_shift (4)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_choosesamplingedgeofpclktosampledpclk_shift (3)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_choosesdclkpolaritysolutionforddrmode_shift (1)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_sdclkpolarityswap_shift                    (0)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_pushpointselectiontypeforddrcmdordat_mask  (0x00000080)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_pushpointselectionforddrmodedat_mask       (0x00000040)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_pushpointselectionforddrmodecmd_mask       (0x00000020)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_pushpointselectionforsd20modecmdordata_mask (0x00000010)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_choosesamplingedgeofpclktosampledpclk_mask (0x00000008)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_choosesdclkpolaritysolutionforddrmode_mask (0x00000006)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_sdclkpolarityswap_mask                     (0x00000001)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_pushpointselectiontypeforddrcmdordat(data) (0x00000080&((data)<<7))
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_pushpointselectionforddrmodedat(data)      (0x00000040&((data)<<6))
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_pushpointselectionforddrmodecmd(data)      (0x00000020&((data)<<5))
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_pushpointselectionforsd20modecmdordata(data) (0x00000010&((data)<<4))
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_choosesamplingedgeofpclktosampledpclk(data) (0x00000008&((data)<<3))
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_choosesdclkpolaritysolutionforddrmode(data) (0x00000006&((data)<<1))
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_sdclkpolarityswap(data)                    (0x00000001&(data))
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_get_pushpointselectiontypeforddrcmdordat(data) ((0x00000080&(data))>>7)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_get_pushpointselectionforddrmodedat(data)  ((0x00000040&(data))>>6)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_get_pushpointselectionforddrmodecmd(data)  ((0x00000020&(data))>>5)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_get_pushpointselectionforsd20modecmdordata(data) ((0x00000010&(data))>>4)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_get_choosesamplingedgeofpclktosampledpclk(data) ((0x00000008&(data))>>3)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_get_choosesdclkpolaritysolutionforddrmode(data) ((0x00000006&(data))>>1)
#define  SD_ALL_TOP_SD_PUSH_POINT_CTL_get_sdclkpolarityswap(data)                (0x00000001&(data))

#define  SD_ALL_TOP_SD_CMD0                                                      0x18010C24
#define  SD_ALL_TOP_SD_CMD0_reg_addr                                             "0xB8010C24"
#define  SD_ALL_TOP_SD_CMD0_reg                                                  0xB8010C24
#define  SD_ALL_TOP_SD_CMD0_inst_addr                                            "0x0009"
#define  set_SD_ALL_TOP_SD_CMD0_reg(data)                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD0_reg)=data)
#define  get_SD_ALL_TOP_SD_CMD0_reg                                              (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD0_reg))
#define  SD_ALL_TOP_SD_CMD0_command_7_0orresponsedata_7_0_shift                  (0)
#define  SD_ALL_TOP_SD_CMD0_command_7_0orresponsedata_7_0_mask                   (0x000000FF)
#define  SD_ALL_TOP_SD_CMD0_command_7_0orresponsedata_7_0(data)                  (0x000000FF&(data))
#define  SD_ALL_TOP_SD_CMD0_get_command_7_0orresponsedata_7_0(data)              (0x000000FF&(data))

#define  SD_ALL_TOP_SD_CMD1                                                      0x18010C28
#define  SD_ALL_TOP_SD_CMD1_reg_addr                                             "0xB8010C28"
#define  SD_ALL_TOP_SD_CMD1_reg                                                  0xB8010C28
#define  SD_ALL_TOP_SD_CMD1_inst_addr                                            "0x000A"
#define  set_SD_ALL_TOP_SD_CMD1_reg(data)                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD1_reg)=data)
#define  get_SD_ALL_TOP_SD_CMD1_reg                                              (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD1_reg))
#define  SD_ALL_TOP_SD_CMD1_command_15_8orresponsedata_15_8_shift                (0)
#define  SD_ALL_TOP_SD_CMD1_command_15_8orresponsedata_15_8_mask                 (0x000000FF)
#define  SD_ALL_TOP_SD_CMD1_command_15_8orresponsedata_15_8(data)                (0x000000FF&(data))
#define  SD_ALL_TOP_SD_CMD1_get_command_15_8orresponsedata_15_8(data)            (0x000000FF&(data))

#define  SD_ALL_TOP_SD_CMD2                                                      0x18010C2C
#define  SD_ALL_TOP_SD_CMD2_reg_addr                                             "0xB8010C2C"
#define  SD_ALL_TOP_SD_CMD2_reg                                                  0xB8010C2C
#define  SD_ALL_TOP_SD_CMD2_inst_addr                                            "0x000B"
#define  set_SD_ALL_TOP_SD_CMD2_reg(data)                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD2_reg)=data)
#define  get_SD_ALL_TOP_SD_CMD2_reg                                              (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD2_reg))
#define  SD_ALL_TOP_SD_CMD2_command_23_16orresponsedata_23_16_shift              (0)
#define  SD_ALL_TOP_SD_CMD2_command_23_16orresponsedata_23_16_mask               (0x000000FF)
#define  SD_ALL_TOP_SD_CMD2_command_23_16orresponsedata_23_16(data)              (0x000000FF&(data))
#define  SD_ALL_TOP_SD_CMD2_get_command_23_16orresponsedata_23_16(data)          (0x000000FF&(data))

#define  SD_ALL_TOP_SD_CMD3                                                      0x18010C30
#define  SD_ALL_TOP_SD_CMD3_reg_addr                                             "0xB8010C30"
#define  SD_ALL_TOP_SD_CMD3_reg                                                  0xB8010C30
#define  SD_ALL_TOP_SD_CMD3_inst_addr                                            "0x000C"
#define  set_SD_ALL_TOP_SD_CMD3_reg(data)                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD3_reg)=data)
#define  get_SD_ALL_TOP_SD_CMD3_reg                                              (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD3_reg))
#define  SD_ALL_TOP_SD_CMD3_command_31_24orresponsedata_31_24_shift              (0)
#define  SD_ALL_TOP_SD_CMD3_command_31_24orresponsedata_31_24_mask               (0x000000FF)
#define  SD_ALL_TOP_SD_CMD3_command_31_24orresponsedata_31_24(data)              (0x000000FF&(data))
#define  SD_ALL_TOP_SD_CMD3_get_command_31_24orresponsedata_31_24(data)          (0x000000FF&(data))

#define  SD_ALL_TOP_SD_CMD4                                                      0x18010C34
#define  SD_ALL_TOP_SD_CMD4_reg_addr                                             "0xB8010C34"
#define  SD_ALL_TOP_SD_CMD4_reg                                                  0xB8010C34
#define  SD_ALL_TOP_SD_CMD4_inst_addr                                            "0x000D"
#define  set_SD_ALL_TOP_SD_CMD4_reg(data)                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD4_reg)=data)
#define  get_SD_ALL_TOP_SD_CMD4_reg                                              (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD4_reg))
#define  SD_ALL_TOP_SD_CMD4_command_39_32orresponsedata_39_32_shift              (0)
#define  SD_ALL_TOP_SD_CMD4_command_39_32orresponsedata_39_32_mask               (0x000000FF)
#define  SD_ALL_TOP_SD_CMD4_command_39_32orresponsedata_39_32(data)              (0x000000FF&(data))
#define  SD_ALL_TOP_SD_CMD4_get_command_39_32orresponsedata_39_32(data)          (0x000000FF&(data))

#define  SD_ALL_TOP_SD_CMD5                                                      0x18010C38
#define  SD_ALL_TOP_SD_CMD5_reg_addr                                             "0xB8010C38"
#define  SD_ALL_TOP_SD_CMD5_reg                                                  0xB8010C38
#define  SD_ALL_TOP_SD_CMD5_inst_addr                                            "0x000E"
#define  set_SD_ALL_TOP_SD_CMD5_reg(data)                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD5_reg)=data)
#define  get_SD_ALL_TOP_SD_CMD5_reg                                              (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD5_reg))
#define  SD_ALL_TOP_SD_CMD5_command_47_40orresponsedata_47_40_shift              (0)
#define  SD_ALL_TOP_SD_CMD5_command_47_40orresponsedata_47_40_mask               (0x000000FF)
#define  SD_ALL_TOP_SD_CMD5_command_47_40orresponsedata_47_40(data)              (0x000000FF&(data))
#define  SD_ALL_TOP_SD_CMD5_get_command_47_40orresponsedata_47_40(data)          (0x000000FF&(data))

#define  SD_ALL_TOP_SD_BYTE_CNT_L                                                0x18010C3C
#define  SD_ALL_TOP_SD_BYTE_CNT_L_reg_addr                                       "0xB8010C3C"
#define  SD_ALL_TOP_SD_BYTE_CNT_L_reg                                            0xB8010C3C
#define  SD_ALL_TOP_SD_BYTE_CNT_L_inst_addr                                      "0x000F"
#define  set_SD_ALL_TOP_SD_BYTE_CNT_L_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_BYTE_CNT_L_reg)=data)
#define  get_SD_ALL_TOP_SD_BYTE_CNT_L_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_BYTE_CNT_L_reg))
#define  SD_ALL_TOP_SD_BYTE_CNT_L_bytecount_7_0_shift                            (0)
#define  SD_ALL_TOP_SD_BYTE_CNT_L_bytecount_7_0_mask                             (0x000000FF)
#define  SD_ALL_TOP_SD_BYTE_CNT_L_bytecount_7_0(data)                            (0x000000FF&(data))
#define  SD_ALL_TOP_SD_BYTE_CNT_L_get_bytecount_7_0(data)                        (0x000000FF&(data))

#define  SD_ALL_TOP_SD_BYTE_CNT_H                                                0x18010C40
#define  SD_ALL_TOP_SD_BYTE_CNT_H_reg_addr                                       "0xB8010C40"
#define  SD_ALL_TOP_SD_BYTE_CNT_H_reg                                            0xB8010C40
#define  SD_ALL_TOP_SD_BYTE_CNT_H_inst_addr                                      "0x0010"
#define  set_SD_ALL_TOP_SD_BYTE_CNT_H_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_BYTE_CNT_H_reg)=data)
#define  get_SD_ALL_TOP_SD_BYTE_CNT_H_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_BYTE_CNT_H_reg))
#define  SD_ALL_TOP_SD_BYTE_CNT_H_bytecount_10_8_shift                           (0)
#define  SD_ALL_TOP_SD_BYTE_CNT_H_bytecount_10_8_mask                            (0x00000007)
#define  SD_ALL_TOP_SD_BYTE_CNT_H_bytecount_10_8(data)                           (0x00000007&(data))
#define  SD_ALL_TOP_SD_BYTE_CNT_H_get_bytecount_10_8(data)                       (0x00000007&(data))

#define  SD_ALL_TOP_SD_BLOCK_CNT_L                                               0x18010C44
#define  SD_ALL_TOP_SD_BLOCK_CNT_L_reg_addr                                      "0xB8010C44"
#define  SD_ALL_TOP_SD_BLOCK_CNT_L_reg                                           0xB8010C44
#define  SD_ALL_TOP_SD_BLOCK_CNT_L_inst_addr                                     "0x0011"
#define  set_SD_ALL_TOP_SD_BLOCK_CNT_L_reg(data)                                 (*((volatile unsigned int*)SD_ALL_TOP_SD_BLOCK_CNT_L_reg)=data)
#define  get_SD_ALL_TOP_SD_BLOCK_CNT_L_reg                                       (*((volatile unsigned int*)SD_ALL_TOP_SD_BLOCK_CNT_L_reg))
#define  SD_ALL_TOP_SD_BLOCK_CNT_L_blockcount_7_0_shift                          (0)
#define  SD_ALL_TOP_SD_BLOCK_CNT_L_blockcount_7_0_mask                           (0x000000FF)
#define  SD_ALL_TOP_SD_BLOCK_CNT_L_blockcount_7_0(data)                          (0x000000FF&(data))
#define  SD_ALL_TOP_SD_BLOCK_CNT_L_get_blockcount_7_0(data)                      (0x000000FF&(data))

#define  SD_ALL_TOP_SD_BLOCK_CNT_H                                               0x18010C48
#define  SD_ALL_TOP_SD_BLOCK_CNT_H_reg_addr                                      "0xB8010C48"
#define  SD_ALL_TOP_SD_BLOCK_CNT_H_reg                                           0xB8010C48
#define  SD_ALL_TOP_SD_BLOCK_CNT_H_inst_addr                                     "0x0012"
#define  set_SD_ALL_TOP_SD_BLOCK_CNT_H_reg(data)                                 (*((volatile unsigned int*)SD_ALL_TOP_SD_BLOCK_CNT_H_reg)=data)
#define  get_SD_ALL_TOP_SD_BLOCK_CNT_H_reg                                       (*((volatile unsigned int*)SD_ALL_TOP_SD_BLOCK_CNT_H_reg))
#define  SD_ALL_TOP_SD_BLOCK_CNT_H_blockcount_14_8_shift                         (0)
#define  SD_ALL_TOP_SD_BLOCK_CNT_H_blockcount_14_8_mask                          (0x000000FF)
#define  SD_ALL_TOP_SD_BLOCK_CNT_H_blockcount_14_8(data)                         (0x000000FF&(data))
#define  SD_ALL_TOP_SD_BLOCK_CNT_H_get_blockcount_14_8(data)                     (0x000000FF&(data))

#define  SD_ALL_TOP_SD_TRANSFER                                                  0x18010C4C
#define  SD_ALL_TOP_SD_TRANSFER_reg_addr                                         "0xB8010C4C"
#define  SD_ALL_TOP_SD_TRANSFER_reg                                              0xB8010C4C
#define  SD_ALL_TOP_SD_TRANSFER_inst_addr                                        "0x0013"
#define  set_SD_ALL_TOP_SD_TRANSFER_reg(data)                                    (*((volatile unsigned int*)SD_ALL_TOP_SD_TRANSFER_reg)=data)
#define  get_SD_ALL_TOP_SD_TRANSFER_reg                                          (*((volatile unsigned int*)SD_ALL_TOP_SD_TRANSFER_reg))
#define  SD_ALL_TOP_SD_TRANSFER_start_shift                                      (7)
#define  SD_ALL_TOP_SD_TRANSFER_end_shift                                        (6)
#define  SD_ALL_TOP_SD_TRANSFER_statusofsdcardmodulestatemachine_shift           (5)
#define  SD_ALL_TOP_SD_TRANSFER_errorbit_shift                                   (4)
#define  SD_ALL_TOP_SD_TRANSFER_commandcode_shift                                (0)
#define  SD_ALL_TOP_SD_TRANSFER_start_mask                                       (0x00000080)
#define  SD_ALL_TOP_SD_TRANSFER_end_mask                                         (0x00000040)
#define  SD_ALL_TOP_SD_TRANSFER_statusofsdcardmodulestatemachine_mask            (0x00000020)
#define  SD_ALL_TOP_SD_TRANSFER_errorbit_mask                                    (0x00000010)
#define  SD_ALL_TOP_SD_TRANSFER_commandcode_mask                                 (0x0000000F)
#define  SD_ALL_TOP_SD_TRANSFER_start(data)                                      (0x00000080&((data)<<7))
#define  SD_ALL_TOP_SD_TRANSFER_end(data)                                        (0x00000040&((data)<<6))
#define  SD_ALL_TOP_SD_TRANSFER_statusofsdcardmodulestatemachine(data)           (0x00000020&((data)<<5))
#define  SD_ALL_TOP_SD_TRANSFER_errorbit(data)                                   (0x00000010&((data)<<4))
#define  SD_ALL_TOP_SD_TRANSFER_commandcode(data)                                (0x0000000F&(data))
#define  SD_ALL_TOP_SD_TRANSFER_get_start(data)                                  ((0x00000080&(data))>>7)
#define  SD_ALL_TOP_SD_TRANSFER_get_end(data)                                    ((0x00000040&(data))>>6)
#define  SD_ALL_TOP_SD_TRANSFER_get_statusofsdcardmodulestatemachine(data)       ((0x00000020&(data))>>5)
#define  SD_ALL_TOP_SD_TRANSFER_get_errorbit(data)                               ((0x00000010&(data))>>4)
#define  SD_ALL_TOP_SD_TRANSFER_get_commandcode(data)                            (0x0000000F&(data))

#define  SD_ALL_TOP_SD_DDR_CHK_START                                             0x18010C50
#define  SD_ALL_TOP_SD_DDR_CHK_START_reg_addr                                    "0xB8010C50"
#define  SD_ALL_TOP_SD_DDR_CHK_START_reg                                         0xB8010C50
#define  SD_ALL_TOP_SD_DDR_CHK_START_inst_addr                                   "0x0014"
#define  set_SD_ALL_TOP_SD_DDR_CHK_START_reg(data)                               (*((volatile unsigned int*)SD_ALL_TOP_SD_DDR_CHK_START_reg)=data)
#define  get_SD_ALL_TOP_SD_DDR_CHK_START_reg                                     (*((volatile unsigned int*)SD_ALL_TOP_SD_DDR_CHK_START_reg))
#define  SD_ALL_TOP_SD_DDR_CHK_START_detect_ddr_cmdodd_start_biterrorflag_shift  (7)
#define  SD_ALL_TOP_SD_DDR_CHK_START_forcecmd1_shift                             (6)
#define  SD_ALL_TOP_SD_DDR_CHK_START_forcecmd0_shift                             (5)
#define  SD_ALL_TOP_SD_DDR_CHK_START_cmdstartbit_shift                           (4)
#define  SD_ALL_TOP_SD_DDR_CHK_START_detect_ddr_data_odd_start_biterrorflag_shift (3)
#define  SD_ALL_TOP_SD_DDR_CHK_START_forcedata1_shift                            (2)
#define  SD_ALL_TOP_SD_DDR_CHK_START_forcedata0_shift                            (1)
#define  SD_ALL_TOP_SD_DDR_CHK_START_datastartbit_shift                          (0)
#define  SD_ALL_TOP_SD_DDR_CHK_START_detect_ddr_cmdodd_start_biterrorflag_mask   (0x00000080)
#define  SD_ALL_TOP_SD_DDR_CHK_START_forcecmd1_mask                              (0x00000040)
#define  SD_ALL_TOP_SD_DDR_CHK_START_forcecmd0_mask                              (0x00000020)
#define  SD_ALL_TOP_SD_DDR_CHK_START_cmdstartbit_mask                            (0x00000010)
#define  SD_ALL_TOP_SD_DDR_CHK_START_detect_ddr_data_odd_start_biterrorflag_mask (0x00000008)
#define  SD_ALL_TOP_SD_DDR_CHK_START_forcedata1_mask                             (0x00000004)
#define  SD_ALL_TOP_SD_DDR_CHK_START_forcedata0_mask                             (0x00000002)
#define  SD_ALL_TOP_SD_DDR_CHK_START_datastartbit_mask                           (0x00000001)
#define  SD_ALL_TOP_SD_DDR_CHK_START_detect_ddr_cmdodd_start_biterrorflag(data)  (0x00000080&((data)<<7))
#define  SD_ALL_TOP_SD_DDR_CHK_START_forcecmd1(data)                             (0x00000040&((data)<<6))
#define  SD_ALL_TOP_SD_DDR_CHK_START_forcecmd0(data)                             (0x00000020&((data)<<5))
#define  SD_ALL_TOP_SD_DDR_CHK_START_cmdstartbit(data)                           (0x00000010&((data)<<4))
#define  SD_ALL_TOP_SD_DDR_CHK_START_detect_ddr_data_odd_start_biterrorflag(data) (0x00000008&((data)<<3))
#define  SD_ALL_TOP_SD_DDR_CHK_START_forcedata1(data)                            (0x00000004&((data)<<2))
#define  SD_ALL_TOP_SD_DDR_CHK_START_forcedata0(data)                            (0x00000002&((data)<<1))
#define  SD_ALL_TOP_SD_DDR_CHK_START_datastartbit(data)                          (0x00000001&(data))
#define  SD_ALL_TOP_SD_DDR_CHK_START_get_detect_ddr_cmdodd_start_biterrorflag(data) ((0x00000080&(data))>>7)
#define  SD_ALL_TOP_SD_DDR_CHK_START_get_forcecmd1(data)                         ((0x00000040&(data))>>6)
#define  SD_ALL_TOP_SD_DDR_CHK_START_get_forcecmd0(data)                         ((0x00000020&(data))>>5)
#define  SD_ALL_TOP_SD_DDR_CHK_START_get_cmdstartbit(data)                       ((0x00000010&(data))>>4)
#define  SD_ALL_TOP_SD_DDR_CHK_START_get_detect_ddr_data_odd_start_biterrorflag(data) ((0x00000008&(data))>>3)
#define  SD_ALL_TOP_SD_DDR_CHK_START_get_forcedata1(data)                        ((0x00000004&(data))>>2)
#define  SD_ALL_TOP_SD_DDR_CHK_START_get_forcedata0(data)                        ((0x00000002&(data))>>1)
#define  SD_ALL_TOP_SD_DDR_CHK_START_get_datastartbit(data)                      (0x00000001&(data))

#define  SD_ALL_TOP_SD_CMD_STATE                                                 0x18010C54
#define  SD_ALL_TOP_SD_CMD_STATE_reg_addr                                        "0xB8010C54"
#define  SD_ALL_TOP_SD_CMD_STATE_reg                                             0xB8010C54
#define  SD_ALL_TOP_SD_CMD_STATE_inst_addr                                       "0x0015"
#define  set_SD_ALL_TOP_SD_CMD_STATE_reg(data)                                   (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD_STATE_reg)=data)
#define  get_SD_ALL_TOP_SD_CMD_STATE_reg                                         (*((volatile unsigned int*)SD_ALL_TOP_SD_CMD_STATE_reg))
#define  SD_ALL_TOP_SD_CMD_STATE_cmdstatemachineidle_shift                       (7)
#define  SD_ALL_TOP_SD_CMD_STATE_cmdstatemachine_shift                           (0)
#define  SD_ALL_TOP_SD_CMD_STATE_cmdstatemachineidle_mask                        (0x00000080)
#define  SD_ALL_TOP_SD_CMD_STATE_cmdstatemachine_mask                            (0x0000000F)
#define  SD_ALL_TOP_SD_CMD_STATE_cmdstatemachineidle(data)                       (0x00000080&((data)<<7))
#define  SD_ALL_TOP_SD_CMD_STATE_cmdstatemachine(data)                           (0x0000000F&(data))
#define  SD_ALL_TOP_SD_CMD_STATE_get_cmdstatemachineidle(data)                   ((0x00000080&(data))>>7)
#define  SD_ALL_TOP_SD_CMD_STATE_get_cmdstatemachine(data)                       (0x0000000F&(data))

#define  SD_ALL_TOP_SD_DATA_STATE                                                0x18010C58
#define  SD_ALL_TOP_SD_DATA_STATE_reg_addr                                       "0xB8010C58"
#define  SD_ALL_TOP_SD_DATA_STATE_reg                                            0xB8010C58
#define  SD_ALL_TOP_SD_DATA_STATE_inst_addr                                      "0x0016"
#define  set_SD_ALL_TOP_SD_DATA_STATE_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_DATA_STATE_reg)=data)
#define  get_SD_ALL_TOP_SD_DATA_STATE_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_DATA_STATE_reg))
#define  SD_ALL_TOP_SD_DATA_STATE_datastatemachineidle_shift                     (7)
#define  SD_ALL_TOP_SD_DATA_STATE_datastatemachine_shift                         (0)
#define  SD_ALL_TOP_SD_DATA_STATE_datastatemachineidle_mask                      (0x00000080)
#define  SD_ALL_TOP_SD_DATA_STATE_datastatemachine_mask                          (0x0000000F)
#define  SD_ALL_TOP_SD_DATA_STATE_datastatemachineidle(data)                     (0x00000080&((data)<<7))
#define  SD_ALL_TOP_SD_DATA_STATE_datastatemachine(data)                         (0x0000000F&(data))
#define  SD_ALL_TOP_SD_DATA_STATE_get_datastatemachineidle(data)                 ((0x00000080&(data))>>7)
#define  SD_ALL_TOP_SD_DATA_STATE_get_datastatemachine(data)                     (0x0000000F&(data))

#define  SD_ALL_TOP_SD_BUS_TA_TIME                                               0x18010C5C
#define  SD_ALL_TOP_SD_BUS_TA_TIME_reg_addr                                      "0xB8010C5C"
#define  SD_ALL_TOP_SD_BUS_TA_TIME_reg                                           0xB8010C5C
#define  SD_ALL_TOP_SD_BUS_TA_TIME_inst_addr                                     "0x0017"
#define  set_SD_ALL_TOP_SD_BUS_TA_TIME_reg(data)                                 (*((volatile unsigned int*)SD_ALL_TOP_SD_BUS_TA_TIME_reg)=data)
#define  get_SD_ALL_TOP_SD_BUS_TA_TIME_reg                                       (*((volatile unsigned int*)SD_ALL_TOP_SD_BUS_TA_TIME_reg))
#define  SD_ALL_TOP_SD_BUS_TA_TIME_turn_aroundtimeenable_shift                   (3)
#define  SD_ALL_TOP_SD_BUS_TA_TIME_bus_ta_time_shift                             (0)
#define  SD_ALL_TOP_SD_BUS_TA_TIME_turn_aroundtimeenable_mask                    (0x00000008)
#define  SD_ALL_TOP_SD_BUS_TA_TIME_bus_ta_time_mask                              (0x00000007)
#define  SD_ALL_TOP_SD_BUS_TA_TIME_turn_aroundtimeenable(data)                   (0x00000008&((data)<<3))
#define  SD_ALL_TOP_SD_BUS_TA_TIME_bus_ta_time(data)                             (0x00000007&(data))
#define  SD_ALL_TOP_SD_BUS_TA_TIME_get_turn_aroundtimeenable(data)               ((0x00000008&(data))>>3)
#define  SD_ALL_TOP_SD_BUS_TA_TIME_get_bus_ta_time(data)                         (0x00000007&(data))

#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG                                            0x18010C60
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_reg_addr                                   "0xB8010C60"
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_reg                                        0xB8010C60
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_inst_addr                                  "0x0018"
#define  set_SD_ALL_TOP_SD_STOP_SDCLK_CFG_reg(data)                              (*((volatile unsigned int*)SD_ALL_TOP_SD_STOP_SDCLK_CFG_reg)=data)
#define  get_SD_ALL_TOP_SD_STOP_SDCLK_CFG_reg                                    (*((volatile unsigned int*)SD_ALL_TOP_SD_STOP_SDCLK_CFG_reg))
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stopsd20sdclkconfigurationenable_shift     (5)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stop_sd20clk_cfg_1_shift                   (4)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stop_sd20clk_cfg_0_shift                   (3)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stopsd30sdclkconfigurationenable_shift     (2)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stop_sd30clk_cfg_1_shift                   (1)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stop_sd30clk_cfg_0_shift                   (0)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stopsd20sdclkconfigurationenable_mask      (0x00000020)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stop_sd20clk_cfg_1_mask                    (0x00000010)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stop_sd20clk_cfg_0_mask                    (0x00000008)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stopsd30sdclkconfigurationenable_mask      (0x00000004)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stop_sd30clk_cfg_1_mask                    (0x00000002)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stop_sd30clk_cfg_0_mask                    (0x00000001)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stopsd20sdclkconfigurationenable(data)     (0x00000020&((data)<<5))
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stop_sd20clk_cfg_1(data)                   (0x00000010&((data)<<4))
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stop_sd20clk_cfg_0(data)                   (0x00000008&((data)<<3))
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stopsd30sdclkconfigurationenable(data)     (0x00000004&((data)<<2))
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stop_sd30clk_cfg_1(data)                   (0x00000002&((data)<<1))
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_stop_sd30clk_cfg_0(data)                   (0x00000001&(data))
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_get_stopsd20sdclkconfigurationenable(data) ((0x00000020&(data))>>5)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_get_stop_sd20clk_cfg_1(data)               ((0x00000010&(data))>>4)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_get_stop_sd20clk_cfg_0(data)               ((0x00000008&(data))>>3)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_get_stopsd30sdclkconfigurationenable(data) ((0x00000004&(data))>>2)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_get_stop_sd30clk_cfg_1(data)               ((0x00000002&(data))>>1)
#define  SD_ALL_TOP_SD_STOP_SDCLK_CFG_get_stop_sd30clk_cfg_0(data)               (0x00000001&(data))

#define  SD_ALL_TOP_SD_AUTO_RST_FIFO                                             0x18010C64
#define  SD_ALL_TOP_SD_AUTO_RST_FIFO_reg_addr                                    "0xB8010C64"
#define  SD_ALL_TOP_SD_AUTO_RST_FIFO_reg                                         0xB8010C64
#define  SD_ALL_TOP_SD_AUTO_RST_FIFO_inst_addr                                   "0x0019"
#define  set_SD_ALL_TOP_SD_AUTO_RST_FIFO_reg(data)                               (*((volatile unsigned int*)SD_ALL_TOP_SD_AUTO_RST_FIFO_reg)=data)
#define  get_SD_ALL_TOP_SD_AUTO_RST_FIFO_reg                                     (*((volatile unsigned int*)SD_ALL_TOP_SD_AUTO_RST_FIFO_reg))
#define  SD_ALL_TOP_SD_AUTO_RST_FIFO_auto_reset_fifoenable_shift                 (0)
#define  SD_ALL_TOP_SD_AUTO_RST_FIFO_auto_reset_fifoenable_mask                  (0x00000001)
#define  SD_ALL_TOP_SD_AUTO_RST_FIFO_auto_reset_fifoenable(data)                 (0x00000001&(data))
#define  SD_ALL_TOP_SD_AUTO_RST_FIFO_get_auto_reset_fifoenable(data)             (0x00000001&(data))

#define  SD_ALL_TOP_SD_RW_STOP_CTL                                               0x18010C78
#define  SD_ALL_TOP_SD_RW_STOP_CTL_reg_addr                                      "0xB8010C78"
#define  SD_ALL_TOP_SD_RW_STOP_CTL_reg                                           0xB8010C78
#define  SD_ALL_TOP_SD_RW_STOP_CTL_inst_addr                                     "0x001A"
#define  set_SD_ALL_TOP_SD_RW_STOP_CTL_reg(data)                                 (*((volatile unsigned int*)SD_ALL_TOP_SD_RW_STOP_CTL_reg)=data)
#define  get_SD_ALL_TOP_SD_RW_STOP_CTL_reg                                       (*((volatile unsigned int*)SD_ALL_TOP_SD_RW_STOP_CTL_reg))
#define  SD_ALL_TOP_SD_RW_STOP_CTL_sdinfinitemode_shift                          (2)
#define  SD_ALL_TOP_SD_RW_STOP_CTL_sdcontrollerbusy_shift                        (1)
#define  SD_ALL_TOP_SD_RW_STOP_CTL_sdcontrollerstop_shift                        (0)
#define  SD_ALL_TOP_SD_RW_STOP_CTL_sdinfinitemode_mask                           (0x00000004)
#define  SD_ALL_TOP_SD_RW_STOP_CTL_sdcontrollerbusy_mask                         (0x00000002)
#define  SD_ALL_TOP_SD_RW_STOP_CTL_sdcontrollerstop_mask                         (0x00000001)
#define  SD_ALL_TOP_SD_RW_STOP_CTL_sdinfinitemode(data)                          (0x00000004&((data)<<2))
#define  SD_ALL_TOP_SD_RW_STOP_CTL_sdcontrollerbusy(data)                        (0x00000002&((data)<<1))
#define  SD_ALL_TOP_SD_RW_STOP_CTL_sdcontrollerstop(data)                        (0x00000001&(data))
#define  SD_ALL_TOP_SD_RW_STOP_CTL_get_sdinfinitemode(data)                      ((0x00000004&(data))>>2)
#define  SD_ALL_TOP_SD_RW_STOP_CTL_get_sdcontrollerbusy(data)                    ((0x00000002&(data))>>1)
#define  SD_ALL_TOP_SD_RW_STOP_CTL_get_sdcontrollerstop(data)                    (0x00000001&(data))

#define  SD_ALL_TOP_SD_DUMMY_3                                                   0x18010C7C
#define  SD_ALL_TOP_SD_DUMMY_3_reg_addr                                          "0xB8010C7C"
#define  SD_ALL_TOP_SD_DUMMY_3_reg                                               0xB8010C7C
#define  SD_ALL_TOP_SD_DUMMY_3_inst_addr                                         "0x001B"
#define  set_SD_ALL_TOP_SD_DUMMY_3_reg(data)                                     (*((volatile unsigned int*)SD_ALL_TOP_SD_DUMMY_3_reg)=data)
#define  get_SD_ALL_TOP_SD_DUMMY_3_reg                                           (*((volatile unsigned int*)SD_ALL_TOP_SD_DUMMY_3_reg))
#define  SD_ALL_TOP_SD_DUMMY_3_sd_dummy_3_shift                                  (2)
#define  SD_ALL_TOP_SD_DUMMY_3_sd_dummy_3_mask                                   (0x000000FC)
#define  SD_ALL_TOP_SD_DUMMY_3_sd_dummy_3(data)                                  (0x000000FC&((data)<<2))
#define  SD_ALL_TOP_SD_DUMMY_3_get_sd_dummy_3(data)                              ((0x000000FC&(data))>>2)

#define  SD_ALL_TOP_SD_ADDR_L                                                    0x18010C80
#define  SD_ALL_TOP_SD_ADDR_L_reg_addr                                           "0xB8010C80"
#define  SD_ALL_TOP_SD_ADDR_L_reg                                                0xB8010C80
#define  SD_ALL_TOP_SD_ADDR_L_inst_addr                                          "0x001C"
#define  set_SD_ALL_TOP_SD_ADDR_L_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_SD_ADDR_L_reg)=data)
#define  get_SD_ALL_TOP_SD_ADDR_L_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_SD_ADDR_L_reg))
#define  SD_ALL_TOP_SD_ADDR_L_sd_address_7_0_shift                               (0)
#define  SD_ALL_TOP_SD_ADDR_L_sd_address_7_0_mask                                (0x000000FF)
#define  SD_ALL_TOP_SD_ADDR_L_sd_address_7_0(data)                               (0x000000FF&(data))
#define  SD_ALL_TOP_SD_ADDR_L_get_sd_address_7_0(data)                           (0x000000FF&(data))

#define  SD_ALL_TOP_SD_ADDR_H                                                    0x18010C84
#define  SD_ALL_TOP_SD_ADDR_H_reg_addr                                           "0xB8010C84"
#define  SD_ALL_TOP_SD_ADDR_H_reg                                                0xB8010C84
#define  SD_ALL_TOP_SD_ADDR_H_inst_addr                                          "0x001D"
#define  set_SD_ALL_TOP_SD_ADDR_H_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_SD_ADDR_H_reg)=data)
#define  get_SD_ALL_TOP_SD_ADDR_H_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_SD_ADDR_H_reg))
#define  SD_ALL_TOP_SD_ADDR_H_sd_address_15_8_shift                              (0)
#define  SD_ALL_TOP_SD_ADDR_H_sd_address_15_8_mask                               (0x000000FF)
#define  SD_ALL_TOP_SD_ADDR_H_sd_address_15_8(data)                              (0x000000FF&(data))
#define  SD_ALL_TOP_SD_ADDR_H_get_sd_address_15_8(data)                          (0x000000FF&(data))

#define  SD_ALL_TOP_SD_START_ADDR_0                                              0x18010C88
#define  SD_ALL_TOP_SD_START_ADDR_0_reg_addr                                     "0xB8010C88"
#define  SD_ALL_TOP_SD_START_ADDR_0_reg                                          0xB8010C88
#define  SD_ALL_TOP_SD_START_ADDR_0_inst_addr                                    "0x001E"
#define  set_SD_ALL_TOP_SD_START_ADDR_0_reg(data)                                (*((volatile unsigned int*)SD_ALL_TOP_SD_START_ADDR_0_reg)=data)
#define  get_SD_ALL_TOP_SD_START_ADDR_0_reg                                      (*((volatile unsigned int*)SD_ALL_TOP_SD_START_ADDR_0_reg))
#define  SD_ALL_TOP_SD_START_ADDR_0_sd_start_addr_7_0_shift                      (0)
#define  SD_ALL_TOP_SD_START_ADDR_0_sd_start_addr_7_0_mask                       (0x000000FF)
#define  SD_ALL_TOP_SD_START_ADDR_0_sd_start_addr_7_0(data)                      (0x000000FF&(data))
#define  SD_ALL_TOP_SD_START_ADDR_0_get_sd_start_addr_7_0(data)                  (0x000000FF&(data))

#define  SD_ALL_TOP_SD_START_ADDR_1                                              0x18010C8C
#define  SD_ALL_TOP_SD_START_ADDR_1_reg_addr                                     "0xB8010C8C"
#define  SD_ALL_TOP_SD_START_ADDR_1_reg                                          0xB8010C8C
#define  SD_ALL_TOP_SD_START_ADDR_1_inst_addr                                    "0x001F"
#define  set_SD_ALL_TOP_SD_START_ADDR_1_reg(data)                                (*((volatile unsigned int*)SD_ALL_TOP_SD_START_ADDR_1_reg)=data)
#define  get_SD_ALL_TOP_SD_START_ADDR_1_reg                                      (*((volatile unsigned int*)SD_ALL_TOP_SD_START_ADDR_1_reg))
#define  SD_ALL_TOP_SD_START_ADDR_1_sd_start_addr_15_8_shift                     (0)
#define  SD_ALL_TOP_SD_START_ADDR_1_sd_start_addr_15_8_mask                      (0x000000FF)
#define  SD_ALL_TOP_SD_START_ADDR_1_sd_start_addr_15_8(data)                     (0x000000FF&(data))
#define  SD_ALL_TOP_SD_START_ADDR_1_get_sd_start_addr_15_8(data)                 (0x000000FF&(data))

#define  SD_ALL_TOP_SD_START_ADDR_2                                              0x18010C90
#define  SD_ALL_TOP_SD_START_ADDR_2_reg_addr                                     "0xB8010C90"
#define  SD_ALL_TOP_SD_START_ADDR_2_reg                                          0xB8010C90
#define  SD_ALL_TOP_SD_START_ADDR_2_inst_addr                                    "0x0020"
#define  set_SD_ALL_TOP_SD_START_ADDR_2_reg(data)                                (*((volatile unsigned int*)SD_ALL_TOP_SD_START_ADDR_2_reg)=data)
#define  get_SD_ALL_TOP_SD_START_ADDR_2_reg                                      (*((volatile unsigned int*)SD_ALL_TOP_SD_START_ADDR_2_reg))
#define  SD_ALL_TOP_SD_START_ADDR_2_sd_start_addr_23_16_shift                    (0)
#define  SD_ALL_TOP_SD_START_ADDR_2_sd_start_addr_23_16_mask                     (0x000000FF)
#define  SD_ALL_TOP_SD_START_ADDR_2_sd_start_addr_23_16(data)                    (0x000000FF&(data))
#define  SD_ALL_TOP_SD_START_ADDR_2_get_sd_start_addr_23_16(data)                (0x000000FF&(data))

#define  SD_ALL_TOP_SD_START_ADDR_3                                              0x18010C94
#define  SD_ALL_TOP_SD_START_ADDR_3_reg_addr                                     "0xB8010C94"
#define  SD_ALL_TOP_SD_START_ADDR_3_reg                                          0xB8010C94
#define  SD_ALL_TOP_SD_START_ADDR_3_inst_addr                                    "0x0021"
#define  set_SD_ALL_TOP_SD_START_ADDR_3_reg(data)                                (*((volatile unsigned int*)SD_ALL_TOP_SD_START_ADDR_3_reg)=data)
#define  get_SD_ALL_TOP_SD_START_ADDR_3_reg                                      (*((volatile unsigned int*)SD_ALL_TOP_SD_START_ADDR_3_reg))
#define  SD_ALL_TOP_SD_START_ADDR_3_sd_start_addr_31_24_shift                    (0)
#define  SD_ALL_TOP_SD_START_ADDR_3_sd_start_addr_31_24_mask                     (0x000000FF)
#define  SD_ALL_TOP_SD_START_ADDR_3_sd_start_addr_31_24(data)                    (0x000000FF&(data))
#define  SD_ALL_TOP_SD_START_ADDR_3_get_sd_start_addr_31_24(data)                (0x000000FF&(data))

#define  SD_ALL_TOP_SD_RSP_MASK_1                                                0x18010C98
#define  SD_ALL_TOP_SD_RSP_MASK_1_reg_addr                                       "0xB8010C98"
#define  SD_ALL_TOP_SD_RSP_MASK_1_reg                                            0xB8010C98
#define  SD_ALL_TOP_SD_RSP_MASK_1_inst_addr                                      "0x0022"
#define  set_SD_ALL_TOP_SD_RSP_MASK_1_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_MASK_1_reg)=data)
#define  get_SD_ALL_TOP_SD_RSP_MASK_1_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_MASK_1_reg))
#define  SD_ALL_TOP_SD_RSP_MASK_1_sd_rsp_mask_7_0_shift                          (0)
#define  SD_ALL_TOP_SD_RSP_MASK_1_sd_rsp_mask_7_0_mask                           (0x000000FF)
#define  SD_ALL_TOP_SD_RSP_MASK_1_sd_rsp_mask_7_0(data)                          (0x000000FF&(data))
#define  SD_ALL_TOP_SD_RSP_MASK_1_get_sd_rsp_mask_7_0(data)                      (0x000000FF&(data))

#define  SD_ALL_TOP_SD_RSP_MASK_2                                                0x18010CA0
#define  SD_ALL_TOP_SD_RSP_MASK_2_reg_addr                                       "0xB8010CA0"
#define  SD_ALL_TOP_SD_RSP_MASK_2_reg                                            0xB8010CA0
#define  SD_ALL_TOP_SD_RSP_MASK_2_inst_addr                                      "0x0023"
#define  set_SD_ALL_TOP_SD_RSP_MASK_2_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_MASK_2_reg)=data)
#define  get_SD_ALL_TOP_SD_RSP_MASK_2_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_MASK_2_reg))
#define  SD_ALL_TOP_SD_RSP_MASK_2_sd_rsp_mask_15_8_shift                         (0)
#define  SD_ALL_TOP_SD_RSP_MASK_2_sd_rsp_mask_15_8_mask                          (0x000000FF)
#define  SD_ALL_TOP_SD_RSP_MASK_2_sd_rsp_mask_15_8(data)                         (0x000000FF&(data))
#define  SD_ALL_TOP_SD_RSP_MASK_2_get_sd_rsp_mask_15_8(data)                     (0x000000FF&(data))

#define  SD_ALL_TOP_SD_RSP_MASK_3                                                0x18010CA4
#define  SD_ALL_TOP_SD_RSP_MASK_3_reg_addr                                       "0xB8010CA4"
#define  SD_ALL_TOP_SD_RSP_MASK_3_reg                                            0xB8010CA4
#define  SD_ALL_TOP_SD_RSP_MASK_3_inst_addr                                      "0x0024"
#define  set_SD_ALL_TOP_SD_RSP_MASK_3_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_MASK_3_reg)=data)
#define  get_SD_ALL_TOP_SD_RSP_MASK_3_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_MASK_3_reg))
#define  SD_ALL_TOP_SD_RSP_MASK_3_sd_rsp_mask_23_16_shift                        (0)
#define  SD_ALL_TOP_SD_RSP_MASK_3_sd_rsp_mask_23_16_mask                         (0x000000FF)
#define  SD_ALL_TOP_SD_RSP_MASK_3_sd_rsp_mask_23_16(data)                        (0x000000FF&(data))
#define  SD_ALL_TOP_SD_RSP_MASK_3_get_sd_rsp_mask_23_16(data)                    (0x000000FF&(data))

#define  SD_ALL_TOP_SD_RSP_MASK_4                                                0x18010CA8
#define  SD_ALL_TOP_SD_RSP_MASK_4_reg_addr                                       "0xB8010CA8"
#define  SD_ALL_TOP_SD_RSP_MASK_4_reg                                            0xB8010CA8
#define  SD_ALL_TOP_SD_RSP_MASK_4_inst_addr                                      "0x0025"
#define  set_SD_ALL_TOP_SD_RSP_MASK_4_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_MASK_4_reg)=data)
#define  get_SD_ALL_TOP_SD_RSP_MASK_4_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_MASK_4_reg))
#define  SD_ALL_TOP_SD_RSP_MASK_4_sd_rsp_mask_31_24_shift                        (0)
#define  SD_ALL_TOP_SD_RSP_MASK_4_sd_rsp_mask_31_24_mask                         (0x000000FF)
#define  SD_ALL_TOP_SD_RSP_MASK_4_sd_rsp_mask_31_24(data)                        (0x000000FF&(data))
#define  SD_ALL_TOP_SD_RSP_MASK_4_get_sd_rsp_mask_31_24(data)                    (0x000000FF&(data))

#define  SD_ALL_TOP_SD_RSP_DATA_1                                                0x18010CAC
#define  SD_ALL_TOP_SD_RSP_DATA_1_reg_addr                                       "0xB8010CAC"
#define  SD_ALL_TOP_SD_RSP_DATA_1_reg                                            0xB8010CAC
#define  SD_ALL_TOP_SD_RSP_DATA_1_inst_addr                                      "0x0026"
#define  set_SD_ALL_TOP_SD_RSP_DATA_1_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_DATA_1_reg)=data)
#define  get_SD_ALL_TOP_SD_RSP_DATA_1_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_DATA_1_reg))
#define  SD_ALL_TOP_SD_RSP_DATA_1_sd_rsp_data_7_0_shift                          (0)
#define  SD_ALL_TOP_SD_RSP_DATA_1_sd_rsp_data_7_0_mask                           (0x000000FF)
#define  SD_ALL_TOP_SD_RSP_DATA_1_sd_rsp_data_7_0(data)                          (0x000000FF&(data))
#define  SD_ALL_TOP_SD_RSP_DATA_1_get_sd_rsp_data_7_0(data)                      (0x000000FF&(data))

#define  SD_ALL_TOP_SD_RSP_DATA_2                                                0x18010CB0
#define  SD_ALL_TOP_SD_RSP_DATA_2_reg_addr                                       "0xB8010CB0"
#define  SD_ALL_TOP_SD_RSP_DATA_2_reg                                            0xB8010CB0
#define  SD_ALL_TOP_SD_RSP_DATA_2_inst_addr                                      "0x0027"
#define  set_SD_ALL_TOP_SD_RSP_DATA_2_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_DATA_2_reg)=data)
#define  get_SD_ALL_TOP_SD_RSP_DATA_2_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_DATA_2_reg))
#define  SD_ALL_TOP_SD_RSP_DATA_2_sd_rsp_data_15_8_shift                         (0)
#define  SD_ALL_TOP_SD_RSP_DATA_2_sd_rsp_data_15_8_mask                          (0x000000FF)
#define  SD_ALL_TOP_SD_RSP_DATA_2_sd_rsp_data_15_8(data)                         (0x000000FF&(data))
#define  SD_ALL_TOP_SD_RSP_DATA_2_get_sd_rsp_data_15_8(data)                     (0x000000FF&(data))

#define  SD_ALL_TOP_SD_RSP_DATA_3                                                0x18010CB4
#define  SD_ALL_TOP_SD_RSP_DATA_3_reg_addr                                       "0xB8010CB4"
#define  SD_ALL_TOP_SD_RSP_DATA_3_reg                                            0xB8010CB4
#define  SD_ALL_TOP_SD_RSP_DATA_3_inst_addr                                      "0x0028"
#define  set_SD_ALL_TOP_SD_RSP_DATA_3_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_DATA_3_reg)=data)
#define  get_SD_ALL_TOP_SD_RSP_DATA_3_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_DATA_3_reg))
#define  SD_ALL_TOP_SD_RSP_DATA_3_sd_rsp_data_23_16_shift                        (0)
#define  SD_ALL_TOP_SD_RSP_DATA_3_sd_rsp_data_23_16_mask                         (0x000000FF)
#define  SD_ALL_TOP_SD_RSP_DATA_3_sd_rsp_data_23_16(data)                        (0x000000FF&(data))
#define  SD_ALL_TOP_SD_RSP_DATA_3_get_sd_rsp_data_23_16(data)                    (0x000000FF&(data))

#define  SD_ALL_TOP_SD_RSP_DATA_4                                                0x18010CB8
#define  SD_ALL_TOP_SD_RSP_DATA_4_reg_addr                                       "0xB8010CB8"
#define  SD_ALL_TOP_SD_RSP_DATA_4_reg                                            0xB8010CB8
#define  SD_ALL_TOP_SD_RSP_DATA_4_inst_addr                                      "0x0029"
#define  set_SD_ALL_TOP_SD_RSP_DATA_4_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_DATA_4_reg)=data)
#define  get_SD_ALL_TOP_SD_RSP_DATA_4_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_SD_RSP_DATA_4_reg))
#define  SD_ALL_TOP_SD_RSP_DATA_4_sd_rsp_data_31_24_shift                        (0)
#define  SD_ALL_TOP_SD_RSP_DATA_4_sd_rsp_data_31_24_mask                         (0x000000FF)
#define  SD_ALL_TOP_SD_RSP_DATA_4_sd_rsp_data_31_24(data)                        (0x000000FF&(data))
#define  SD_ALL_TOP_SD_RSP_DATA_4_get_sd_rsp_data_31_24(data)                    (0x000000FF&(data))

#define  SD_ALL_TOP_SD_WR_DELAY                                                  0x18010CBC
#define  SD_ALL_TOP_SD_WR_DELAY_reg_addr                                         "0xB8010CBC"
#define  SD_ALL_TOP_SD_WR_DELAY_reg                                              0xB8010CBC
#define  SD_ALL_TOP_SD_WR_DELAY_inst_addr                                        "0x002A"
#define  set_SD_ALL_TOP_SD_WR_DELAY_reg(data)                                    (*((volatile unsigned int*)SD_ALL_TOP_SD_WR_DELAY_reg)=data)
#define  get_SD_ALL_TOP_SD_WR_DELAY_reg                                          (*((volatile unsigned int*)SD_ALL_TOP_SD_WR_DELAY_reg))
#define  SD_ALL_TOP_SD_WR_DELAY_sd_write_delay_shift                             (0)
#define  SD_ALL_TOP_SD_WR_DELAY_sd_write_delay_mask                              (0x0000000F)
#define  SD_ALL_TOP_SD_WR_DELAY_sd_write_delay(data)                             (0x0000000F&(data))
#define  SD_ALL_TOP_SD_WR_DELAY_get_sd_write_delay(data)                         (0x0000000F&(data))

#define  SD_ALL_TOP_SD_RD_DELAY                                                  0x18010CC0
#define  SD_ALL_TOP_SD_RD_DELAY_reg_addr                                         "0xB8010CC0"
#define  SD_ALL_TOP_SD_RD_DELAY_reg                                              0xB8010CC0
#define  SD_ALL_TOP_SD_RD_DELAY_inst_addr                                        "0x002B"
#define  set_SD_ALL_TOP_SD_RD_DELAY_reg(data)                                    (*((volatile unsigned int*)SD_ALL_TOP_SD_RD_DELAY_reg)=data)
#define  get_SD_ALL_TOP_SD_RD_DELAY_reg                                          (*((volatile unsigned int*)SD_ALL_TOP_SD_RD_DELAY_reg))
#define  SD_ALL_TOP_SD_RD_DELAY_sd_read_delay_shift                              (0)
#define  SD_ALL_TOP_SD_RD_DELAY_sd_read_delay_mask                               (0x0000000F)
#define  SD_ALL_TOP_SD_RD_DELAY_sd_read_delay(data)                              (0x0000000F&(data))
#define  SD_ALL_TOP_SD_RD_DELAY_get_sd_read_delay(data)                          (0x0000000F&(data))

#define  SD_ALL_TOP_cr_dma_ptr_status                                            0x18010CD0
#define  SD_ALL_TOP_cr_dma_ptr_status_reg_addr                                   "0xB8010CD0"
#define  SD_ALL_TOP_cr_dma_ptr_status_reg                                        0xB8010CD0
#define  SD_ALL_TOP_cr_dma_ptr_status_inst_addr                                  "0x002C"
#define  set_SD_ALL_TOP_cr_dma_ptr_status_reg(data)                              (*((volatile unsigned int*)SD_ALL_TOP_cr_dma_ptr_status_reg)=data)
#define  get_SD_ALL_TOP_cr_dma_ptr_status_reg                                    (*((volatile unsigned int*)SD_ALL_TOP_cr_dma_ptr_status_reg))
#define  SD_ALL_TOP_cr_dma_ptr_status_dma_out_index_shift                        (16)
#define  SD_ALL_TOP_cr_dma_ptr_status_dma_in_index_shift                         (0)
#define  SD_ALL_TOP_cr_dma_ptr_status_dma_out_index_mask                         (0x003F0000)
#define  SD_ALL_TOP_cr_dma_ptr_status_dma_in_index_mask                          (0x0000003F)
#define  SD_ALL_TOP_cr_dma_ptr_status_dma_out_index(data)                        (0x003F0000&((data)<<16))
#define  SD_ALL_TOP_cr_dma_ptr_status_dma_in_index(data)                         (0x0000003F&(data))
#define  SD_ALL_TOP_cr_dma_ptr_status_get_dma_out_index(data)                    ((0x003F0000&(data))>>16)
#define  SD_ALL_TOP_cr_dma_ptr_status_get_dma_in_index(data)                     (0x0000003F&(data))

#define  SD_ALL_TOP_cr_dma_in_addr                                               0x18010CD4
#define  SD_ALL_TOP_cr_dma_in_addr_reg_addr                                      "0xB8010CD4"
#define  SD_ALL_TOP_cr_dma_in_addr_reg                                           0xB8010CD4
#define  SD_ALL_TOP_cr_dma_in_addr_inst_addr                                     "0x002D"
#define  set_SD_ALL_TOP_cr_dma_in_addr_reg(data)                                 (*((volatile unsigned int*)SD_ALL_TOP_cr_dma_in_addr_reg)=data)
#define  get_SD_ALL_TOP_cr_dma_in_addr_reg                                       (*((volatile unsigned int*)SD_ALL_TOP_cr_dma_in_addr_reg))
#define  SD_ALL_TOP_cr_dma_in_addr_dma_in_addr_shift                             (3)
#define  SD_ALL_TOP_cr_dma_in_addr_dma_in_addr_mask                              (0xFFFFFFF8)
#define  SD_ALL_TOP_cr_dma_in_addr_dma_in_addr(data)                             (0xFFFFFFF8&((data)<<3))
#define  SD_ALL_TOP_cr_dma_in_addr_get_dma_in_addr(data)                         ((0xFFFFFFF8&(data))>>3)

#define  SD_ALL_TOP_cr_dma_out_addr                                              0x18010CD8
#define  SD_ALL_TOP_cr_dma_out_addr_reg_addr                                     "0xB8010CD8"
#define  SD_ALL_TOP_cr_dma_out_addr_reg                                          0xB8010CD8
#define  SD_ALL_TOP_cr_dma_out_addr_inst_addr                                    "0x002E"
#define  set_SD_ALL_TOP_cr_dma_out_addr_reg(data)                                (*((volatile unsigned int*)SD_ALL_TOP_cr_dma_out_addr_reg)=data)
#define  get_SD_ALL_TOP_cr_dma_out_addr_reg                                      (*((volatile unsigned int*)SD_ALL_TOP_cr_dma_out_addr_reg))
#define  SD_ALL_TOP_cr_dma_out_addr_dma_out_addr_shift                           (3)
#define  SD_ALL_TOP_cr_dma_out_addr_dma_out_addr_mask                            (0xFFFFFFF8)
#define  SD_ALL_TOP_cr_dma_out_addr_dma_out_addr(data)                           (0xFFFFFFF8&((data)<<3))
#define  SD_ALL_TOP_cr_dma_out_addr_get_dma_out_addr(data)                       ((0xFFFFFFF8&(data))>>3)

#define  SD_ALL_TOP_cr_int_status                                                0x18010CDC
#define  SD_ALL_TOP_cr_int_status_reg_addr                                       "0xB8010CDC"
#define  SD_ALL_TOP_cr_int_status_reg                                            0xB8010CDC
#define  SD_ALL_TOP_cr_int_status_inst_addr                                      "0x002F"
#define  set_SD_ALL_TOP_cr_int_status_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_cr_int_status_reg)=data)
#define  get_SD_ALL_TOP_cr_int_status_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_cr_int_status_reg))
#define  SD_ALL_TOP_cr_int_status_stop_by_kcpu_force_shift                       (6)
#define  SD_ALL_TOP_cr_int_status_write_protection_shift                         (5)
#define  SD_ALL_TOP_cr_int_status_card_detection_shift                           (4)
#define  SD_ALL_TOP_cr_int_status_decode_error_shift                             (2)
#define  SD_ALL_TOP_cr_int_status_decode_finish_shift                            (1)
#define  SD_ALL_TOP_cr_int_status_card_status_change_shift                       (0)
#define  SD_ALL_TOP_cr_int_status_stop_by_kcpu_force_mask                        (0x00000040)
#define  SD_ALL_TOP_cr_int_status_write_protection_mask                          (0x00000020)
#define  SD_ALL_TOP_cr_int_status_card_detection_mask                            (0x00000010)
#define  SD_ALL_TOP_cr_int_status_decode_error_mask                              (0x00000004)
#define  SD_ALL_TOP_cr_int_status_decode_finish_mask                             (0x00000002)
#define  SD_ALL_TOP_cr_int_status_card_status_change_mask                        (0x00000001)
#define  SD_ALL_TOP_cr_int_status_stop_by_kcpu_force(data)                       (0x00000040&((data)<<6))
#define  SD_ALL_TOP_cr_int_status_write_protection(data)                         (0x00000020&((data)<<5))
#define  SD_ALL_TOP_cr_int_status_card_detection(data)                           (0x00000010&((data)<<4))
#define  SD_ALL_TOP_cr_int_status_decode_error(data)                             (0x00000004&((data)<<2))
#define  SD_ALL_TOP_cr_int_status_decode_finish(data)                            (0x00000002&((data)<<1))
#define  SD_ALL_TOP_cr_int_status_card_status_change(data)                       (0x00000001&(data))
#define  SD_ALL_TOP_cr_int_status_get_stop_by_kcpu_force(data)                   ((0x00000040&(data))>>6)
#define  SD_ALL_TOP_cr_int_status_get_write_protection(data)                     ((0x00000020&(data))>>5)
#define  SD_ALL_TOP_cr_int_status_get_card_detection(data)                       ((0x00000010&(data))>>4)
#define  SD_ALL_TOP_cr_int_status_get_decode_error(data)                         ((0x00000004&(data))>>2)
#define  SD_ALL_TOP_cr_int_status_get_decode_finish(data)                        ((0x00000002&(data))>>1)
#define  SD_ALL_TOP_cr_int_status_get_card_status_change(data)                   (0x00000001&(data))

#define  SD_ALL_TOP_cr_int_mask                                                  0x18010CE0
#define  SD_ALL_TOP_cr_int_mask_reg_addr                                         "0xB8010CE0"
#define  SD_ALL_TOP_cr_int_mask_reg                                              0xB8010CE0
#define  SD_ALL_TOP_cr_int_mask_inst_addr                                        "0x0030"
#define  set_SD_ALL_TOP_cr_int_mask_reg(data)                                    (*((volatile unsigned int*)SD_ALL_TOP_cr_int_mask_reg)=data)
#define  get_SD_ALL_TOP_cr_int_mask_reg                                          (*((volatile unsigned int*)SD_ALL_TOP_cr_int_mask_reg))
#define  SD_ALL_TOP_cr_int_mask_card_detection_intmask_shift                     (3)
#define  SD_ALL_TOP_cr_int_mask_decode_error_mask_shift                          (2)
#define  SD_ALL_TOP_cr_int_mask_decode_finish_mask_shift                         (1)
#define  SD_ALL_TOP_cr_int_mask_card_status_change_mask_shift                    (0)
#define  SD_ALL_TOP_cr_int_mask_card_detection_intmask_mask                      (0x00000008)
#define  SD_ALL_TOP_cr_int_mask_decode_error_mask_mask                           (0x00000004)
#define  SD_ALL_TOP_cr_int_mask_decode_finish_mask_mask                          (0x00000002)
#define  SD_ALL_TOP_cr_int_mask_card_status_change_mask_mask                     (0x00000001)
#define  SD_ALL_TOP_cr_int_mask_card_detection_intmask(data)                     (0x00000008&((data)<<3))
#define  SD_ALL_TOP_cr_int_mask_decode_error_mask(data)                          (0x00000004&((data)<<2))
#define  SD_ALL_TOP_cr_int_mask_decode_finish_mask(data)                         (0x00000002&((data)<<1))
#define  SD_ALL_TOP_cr_int_mask_card_status_change_mask(data)                    (0x00000001&(data))
#define  SD_ALL_TOP_cr_int_mask_get_card_detection_intmask(data)                 ((0x00000008&(data))>>3)
#define  SD_ALL_TOP_cr_int_mask_get_decode_error_mask(data)                      ((0x00000004&(data))>>2)
#define  SD_ALL_TOP_cr_int_mask_get_decode_finish_mask(data)                     ((0x00000002&(data))>>1)
#define  SD_ALL_TOP_cr_int_mask_get_card_status_change_mask(data)                (0x00000001&(data))

#define  SD_ALL_TOP_cr_reg_mode_ctrl                                             0x18010CE4
#define  SD_ALL_TOP_cr_reg_mode_ctrl_reg_addr                                    "0xB8010CE4"
#define  SD_ALL_TOP_cr_reg_mode_ctrl_reg                                         0xB8010CE4
#define  SD_ALL_TOP_cr_reg_mode_ctrl_inst_addr                                   "0x0031"
#define  set_SD_ALL_TOP_cr_reg_mode_ctrl_reg(data)                               (*((volatile unsigned int*)SD_ALL_TOP_cr_reg_mode_ctrl_reg)=data)
#define  get_SD_ALL_TOP_cr_reg_mode_ctrl_reg                                     (*((volatile unsigned int*)SD_ALL_TOP_cr_reg_mode_ctrl_reg))
#define  SD_ALL_TOP_cr_reg_mode_ctrl_reg_stop_shift                              (3)
#define  SD_ALL_TOP_cr_reg_mode_ctrl_reg_stop_mask                               (0x00000008)
#define  SD_ALL_TOP_cr_reg_mode_ctrl_reg_stop(data)                              (0x00000008&((data)<<3))
#define  SD_ALL_TOP_cr_reg_mode_ctrl_get_reg_stop(data)                          ((0x00000008&(data))>>3)

#define  SD_ALL_TOP_cr_des_mode_ctrl                                             0x18010CE8
#define  SD_ALL_TOP_cr_des_mode_ctrl_reg_addr                                    "0xB8010CE8"
#define  SD_ALL_TOP_cr_des_mode_ctrl_reg                                         0xB8010CE8
#define  SD_ALL_TOP_cr_des_mode_ctrl_inst_addr                                   "0x0032"
#define  set_SD_ALL_TOP_cr_des_mode_ctrl_reg(data)                               (*((volatile unsigned int*)SD_ALL_TOP_cr_des_mode_ctrl_reg)=data)
#define  get_SD_ALL_TOP_cr_des_mode_ctrl_reg                                     (*((volatile unsigned int*)SD_ALL_TOP_cr_des_mode_ctrl_reg))
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_addr_auto_inc_shift                     (10)
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_sw_hs_enable_shift                      (9)
#define  SD_ALL_TOP_cr_des_mode_ctrl_rd_des_cmd_wr_port_shift                    (8)
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_stop_shift                              (7)
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_mode_len_shift                          (3)
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_mode_en_shift                           (0)
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_addr_auto_inc_mask                      (0x00000400)
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_sw_hs_enable_mask                       (0x00000200)
#define  SD_ALL_TOP_cr_des_mode_ctrl_rd_des_cmd_wr_port_mask                     (0x00000100)
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_stop_mask                               (0x00000080)
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_mode_len_mask                           (0x00000078)
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_mode_en_mask                            (0x00000001)
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_addr_auto_inc(data)                     (0x00000400&((data)<<10))
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_sw_hs_enable(data)                      (0x00000200&((data)<<9))
#define  SD_ALL_TOP_cr_des_mode_ctrl_rd_des_cmd_wr_port(data)                    (0x00000100&((data)<<8))
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_stop(data)                              (0x00000080&((data)<<7))
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_mode_len(data)                          (0x00000078&((data)<<3))
#define  SD_ALL_TOP_cr_des_mode_ctrl_des_mode_en(data)                           (0x00000001&(data))
#define  SD_ALL_TOP_cr_des_mode_ctrl_get_des_addr_auto_inc(data)                 ((0x00000400&(data))>>10)
#define  SD_ALL_TOP_cr_des_mode_ctrl_get_des_sw_hs_enable(data)                  ((0x00000200&(data))>>9)
#define  SD_ALL_TOP_cr_des_mode_ctrl_get_rd_des_cmd_wr_port(data)                ((0x00000100&(data))>>8)
#define  SD_ALL_TOP_cr_des_mode_ctrl_get_des_stop(data)                          ((0x00000080&(data))>>7)
#define  SD_ALL_TOP_cr_des_mode_ctrl_get_des_mode_len(data)                      ((0x00000078&(data))>>3)
#define  SD_ALL_TOP_cr_des_mode_ctrl_get_des_mode_en(data)                       (0x00000001&(data))

#define  SD_ALL_TOP_des_cmd_wr_port                                              0x18010CEC
#define  SD_ALL_TOP_des_cmd_wr_port_reg_addr                                     "0xB8010CEC"
#define  SD_ALL_TOP_des_cmd_wr_port_reg                                          0xB8010CEC
#define  SD_ALL_TOP_des_cmd_wr_port_inst_addr                                    "0x0033"
#define  set_SD_ALL_TOP_des_cmd_wr_port_reg(data)                                (*((volatile unsigned int*)SD_ALL_TOP_des_cmd_wr_port_reg)=data)
#define  get_SD_ALL_TOP_des_cmd_wr_port_reg                                      (*((volatile unsigned int*)SD_ALL_TOP_des_cmd_wr_port_reg))
#define  SD_ALL_TOP_des_cmd_wr_port_des_command_shift                            (0)
#define  SD_ALL_TOP_des_cmd_wr_port_des_command_mask                             (0xFFFFFFFF)
#define  SD_ALL_TOP_des_cmd_wr_port_des_command(data)                            (0xFFFFFFFF&(data))
#define  SD_ALL_TOP_des_cmd_wr_port_get_des_command(data)                        (0xFFFFFFFF&(data))

#define  SD_ALL_TOP_CR_BIST_0                                                    0x18010CF0
#define  SD_ALL_TOP_CR_BIST_0_reg_addr                                           "0xB8010CF0"
#define  SD_ALL_TOP_CR_BIST_0_reg                                                0xB8010CF0
#define  SD_ALL_TOP_CR_BIST_0_inst_addr                                          "0x0034"
#define  set_SD_ALL_TOP_CR_BIST_0_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_0_reg)=data)
#define  get_SD_ALL_TOP_CR_BIST_0_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_0_reg))
#define  SD_ALL_TOP_CR_BIST_0_bist_rstn_shift                                    (0)
#define  SD_ALL_TOP_CR_BIST_0_bist_rstn_mask                                     (0x00000001)
#define  SD_ALL_TOP_CR_BIST_0_bist_rstn(data)                                    (0x00000001&(data))
#define  SD_ALL_TOP_CR_BIST_0_get_bist_rstn(data)                                (0x00000001&(data))

#define  SD_ALL_TOP_CR_BIST_1                                                    0x18010CF4
#define  SD_ALL_TOP_CR_BIST_1_reg_addr                                           "0xB8010CF4"
#define  SD_ALL_TOP_CR_BIST_1_reg                                                0xB8010CF4
#define  SD_ALL_TOP_CR_BIST_1_inst_addr                                          "0x0035"
#define  set_SD_ALL_TOP_CR_BIST_1_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_1_reg)=data)
#define  get_SD_ALL_TOP_CR_BIST_1_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_1_reg))
#define  SD_ALL_TOP_CR_BIST_1_rma_0_shift                                        (6)
#define  SD_ALL_TOP_CR_BIST_1_rmea_0_shift                                       (5)
#define  SD_ALL_TOP_CR_BIST_1_rmb_0_shift                                        (1)
#define  SD_ALL_TOP_CR_BIST_1_rmeb_0_shift                                       (0)
#define  SD_ALL_TOP_CR_BIST_1_rma_0_mask                                         (0x000003C0)
#define  SD_ALL_TOP_CR_BIST_1_rmea_0_mask                                        (0x00000020)
#define  SD_ALL_TOP_CR_BIST_1_rmb_0_mask                                         (0x0000001E)
#define  SD_ALL_TOP_CR_BIST_1_rmeb_0_mask                                        (0x00000001)
#define  SD_ALL_TOP_CR_BIST_1_rma_0(data)                                        (0x000003C0&((data)<<6))
#define  SD_ALL_TOP_CR_BIST_1_rmea_0(data)                                       (0x00000020&((data)<<5))
#define  SD_ALL_TOP_CR_BIST_1_rmb_0(data)                                        (0x0000001E&((data)<<1))
#define  SD_ALL_TOP_CR_BIST_1_rmeb_0(data)                                       (0x00000001&(data))
#define  SD_ALL_TOP_CR_BIST_1_get_rma_0(data)                                    ((0x000003C0&(data))>>6)
#define  SD_ALL_TOP_CR_BIST_1_get_rmea_0(data)                                   ((0x00000020&(data))>>5)
#define  SD_ALL_TOP_CR_BIST_1_get_rmb_0(data)                                    ((0x0000001E&(data))>>1)
#define  SD_ALL_TOP_CR_BIST_1_get_rmeb_0(data)                                   (0x00000001&(data))

#define  SD_ALL_TOP_CR_BIST_MODE                                                 0x18010CF8
#define  SD_ALL_TOP_CR_BIST_MODE_reg_addr                                        "0xB8010CF8"
#define  SD_ALL_TOP_CR_BIST_MODE_reg                                             0xB8010CF8
#define  SD_ALL_TOP_CR_BIST_MODE_inst_addr                                       "0x0036"
#define  set_SD_ALL_TOP_CR_BIST_MODE_reg(data)                                   (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_MODE_reg)=data)
#define  get_SD_ALL_TOP_CR_BIST_MODE_reg                                         (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_MODE_reg))
#define  SD_ALL_TOP_CR_BIST_MODE_bist_mode_0_shift                               (0)
#define  SD_ALL_TOP_CR_BIST_MODE_bist_mode_0_mask                                (0x00000001)
#define  SD_ALL_TOP_CR_BIST_MODE_bist_mode_0(data)                               (0x00000001&(data))
#define  SD_ALL_TOP_CR_BIST_MODE_get_bist_mode_0(data)                           (0x00000001&(data))

#define  SD_ALL_TOP_CR_BIST_DONE                                                 0x18010CFC
#define  SD_ALL_TOP_CR_BIST_DONE_reg_addr                                        "0xB8010CFC"
#define  SD_ALL_TOP_CR_BIST_DONE_reg                                             0xB8010CFC
#define  SD_ALL_TOP_CR_BIST_DONE_inst_addr                                       "0x0037"
#define  set_SD_ALL_TOP_CR_BIST_DONE_reg(data)                                   (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_DONE_reg)=data)
#define  get_SD_ALL_TOP_CR_BIST_DONE_reg                                         (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_DONE_reg))
#define  SD_ALL_TOP_CR_BIST_DONE_bist_done_0_shift                               (0)
#define  SD_ALL_TOP_CR_BIST_DONE_bist_done_0_mask                                (0x00000001)
#define  SD_ALL_TOP_CR_BIST_DONE_bist_done_0(data)                               (0x00000001&(data))
#define  SD_ALL_TOP_CR_BIST_DONE_get_bist_done_0(data)                           (0x00000001&(data))

#define  SD_ALL_TOP_CR_BIST_FAIL                                                 0x18010D00
#define  SD_ALL_TOP_CR_BIST_FAIL_reg_addr                                        "0xB8010D00"
#define  SD_ALL_TOP_CR_BIST_FAIL_reg                                             0xB8010D00
#define  SD_ALL_TOP_CR_BIST_FAIL_inst_addr                                       "0x0038"
#define  set_SD_ALL_TOP_CR_BIST_FAIL_reg(data)                                   (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_FAIL_reg)=data)
#define  get_SD_ALL_TOP_CR_BIST_FAIL_reg                                         (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_FAIL_reg))
#define  SD_ALL_TOP_CR_BIST_FAIL_bist_fail_0_shift                               (0)
#define  SD_ALL_TOP_CR_BIST_FAIL_bist_fail_0_mask                                (0x00000001)
#define  SD_ALL_TOP_CR_BIST_FAIL_bist_fail_0(data)                               (0x00000001&(data))
#define  SD_ALL_TOP_CR_BIST_FAIL_get_bist_fail_0(data)                           (0x00000001&(data))

#define  SD_ALL_TOP_CR_BIST_DRF_MODE                                             0x18010D04
#define  SD_ALL_TOP_CR_BIST_DRF_MODE_reg_addr                                    "0xB8010D04"
#define  SD_ALL_TOP_CR_BIST_DRF_MODE_reg                                         0xB8010D04
#define  SD_ALL_TOP_CR_BIST_DRF_MODE_inst_addr                                   "0x0039"
#define  set_SD_ALL_TOP_CR_BIST_DRF_MODE_reg(data)                               (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_DRF_MODE_reg)=data)
#define  get_SD_ALL_TOP_CR_BIST_DRF_MODE_reg                                     (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_DRF_MODE_reg))
#define  SD_ALL_TOP_CR_BIST_DRF_MODE_drf_modeofmbist_0_shift                     (0)
#define  SD_ALL_TOP_CR_BIST_DRF_MODE_drf_modeofmbist_0_mask                      (0x00000001)
#define  SD_ALL_TOP_CR_BIST_DRF_MODE_drf_modeofmbist_0(data)                     (0x00000001&(data))
#define  SD_ALL_TOP_CR_BIST_DRF_MODE_get_drf_modeofmbist_0(data)                 (0x00000001&(data))

#define  SD_ALL_TOP_CR_BIST_DRF_RESUME                                           0x18010D08
#define  SD_ALL_TOP_CR_BIST_DRF_RESUME_reg_addr                                  "0xB8010D08"
#define  SD_ALL_TOP_CR_BIST_DRF_RESUME_reg                                       0xB8010D08
#define  SD_ALL_TOP_CR_BIST_DRF_RESUME_inst_addr                                 "0x003A"
#define  set_SD_ALL_TOP_CR_BIST_DRF_RESUME_reg(data)                             (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_DRF_RESUME_reg)=data)
#define  get_SD_ALL_TOP_CR_BIST_DRF_RESUME_reg                                   (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_DRF_RESUME_reg))
#define  SD_ALL_TOP_CR_BIST_DRF_RESUME_drf_resumeofmbist_0_shift                 (0)
#define  SD_ALL_TOP_CR_BIST_DRF_RESUME_drf_resumeofmbist_0_mask                  (0x00000001)
#define  SD_ALL_TOP_CR_BIST_DRF_RESUME_drf_resumeofmbist_0(data)                 (0x00000001&(data))
#define  SD_ALL_TOP_CR_BIST_DRF_RESUME_get_drf_resumeofmbist_0(data)             (0x00000001&(data))

#define  SD_ALL_TOP_CR_BIST_DRF_DONE                                             0x18010D0C
#define  SD_ALL_TOP_CR_BIST_DRF_DONE_reg_addr                                    "0xB8010D0C"
#define  SD_ALL_TOP_CR_BIST_DRF_DONE_reg                                         0xB8010D0C
#define  SD_ALL_TOP_CR_BIST_DRF_DONE_inst_addr                                   "0x003B"
#define  set_SD_ALL_TOP_CR_BIST_DRF_DONE_reg(data)                               (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_DRF_DONE_reg)=data)
#define  get_SD_ALL_TOP_CR_BIST_DRF_DONE_reg                                     (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_DRF_DONE_reg))
#define  SD_ALL_TOP_CR_BIST_DRF_DONE_drf_doneofmbist_0_shift                     (0)
#define  SD_ALL_TOP_CR_BIST_DRF_DONE_drf_doneofmbist_0_mask                      (0x00000001)
#define  SD_ALL_TOP_CR_BIST_DRF_DONE_drf_doneofmbist_0(data)                     (0x00000001&(data))
#define  SD_ALL_TOP_CR_BIST_DRF_DONE_get_drf_doneofmbist_0(data)                 (0x00000001&(data))

#define  SD_ALL_TOP_CR_BIST_DRF_PAUSE                                            0x18010D10
#define  SD_ALL_TOP_CR_BIST_DRF_PAUSE_reg_addr                                   "0xB8010D10"
#define  SD_ALL_TOP_CR_BIST_DRF_PAUSE_reg                                        0xB8010D10
#define  SD_ALL_TOP_CR_BIST_DRF_PAUSE_inst_addr                                  "0x003C"
#define  set_SD_ALL_TOP_CR_BIST_DRF_PAUSE_reg(data)                              (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_DRF_PAUSE_reg)=data)
#define  get_SD_ALL_TOP_CR_BIST_DRF_PAUSE_reg                                    (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_DRF_PAUSE_reg))
#define  SD_ALL_TOP_CR_BIST_DRF_PAUSE_drf_pauseofmbist_0_shift                   (0)
#define  SD_ALL_TOP_CR_BIST_DRF_PAUSE_drf_pauseofmbist_0_mask                    (0x00000001)
#define  SD_ALL_TOP_CR_BIST_DRF_PAUSE_drf_pauseofmbist_0(data)                   (0x00000001&(data))
#define  SD_ALL_TOP_CR_BIST_DRF_PAUSE_get_drf_pauseofmbist_0(data)               (0x00000001&(data))

#define  SD_ALL_TOP_CR_BIST_DRF_FAIL                                             0x18010D14
#define  SD_ALL_TOP_CR_BIST_DRF_FAIL_reg_addr                                    "0xB8010D14"
#define  SD_ALL_TOP_CR_BIST_DRF_FAIL_reg                                         0xB8010D14
#define  SD_ALL_TOP_CR_BIST_DRF_FAIL_inst_addr                                   "0x003D"
#define  set_SD_ALL_TOP_CR_BIST_DRF_FAIL_reg(data)                               (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_DRF_FAIL_reg)=data)
#define  get_SD_ALL_TOP_CR_BIST_DRF_FAIL_reg                                     (*((volatile unsigned int*)SD_ALL_TOP_CR_BIST_DRF_FAIL_reg))
#define  SD_ALL_TOP_CR_BIST_DRF_FAIL_drf_failofmbist_0_shift                     (0)
#define  SD_ALL_TOP_CR_BIST_DRF_FAIL_drf_failofmbist_0_mask                      (0x00000001)
#define  SD_ALL_TOP_CR_BIST_DRF_FAIL_drf_failofmbist_0(data)                     (0x00000001&(data))
#define  SD_ALL_TOP_CR_BIST_DRF_FAIL_get_drf_failofmbist_0(data)                 (0x00000001&(data))

#define  SD_ALL_TOP_CR_CTRL                                                      0x18010D18
#define  SD_ALL_TOP_CR_CTRL_reg_addr                                             "0xB8010D18"
#define  SD_ALL_TOP_CR_CTRL_reg                                                  0xB8010D18
#define  SD_ALL_TOP_CR_CTRL_inst_addr                                            "0x003E"
#define  set_SD_ALL_TOP_CR_CTRL_reg(data)                                        (*((volatile unsigned int*)SD_ALL_TOP_CR_CTRL_reg)=data)
#define  get_SD_ALL_TOP_CR_CTRL_reg                                              (*((volatile unsigned int*)SD_ALL_TOP_CR_CTRL_reg))
#define  SD_ALL_TOP_CR_CTRL_dummy_28_24_shift                                    (24)
#define  SD_ALL_TOP_CR_CTRL_asic_dbg_sel_shift                                   (20)
#define  SD_ALL_TOP_CR_CTRL_dbg_sel_shift                                        (12)
#define  SD_ALL_TOP_CR_CTRL_wrap_dbg_sel_shift                                   (6)
#define  SD_ALL_TOP_CR_CTRL_map_sel_shift                                        (5)
#define  SD_ALL_TOP_CR_CTRL_xfer_dir_shift                                       (4)
#define  SD_ALL_TOP_CR_CTRL_boot_from_cr_shift                                   (3)
#define  SD_ALL_TOP_CR_CTRL_buff_timing_shift                                    (1)
#define  SD_ALL_TOP_CR_CTRL_cp_en_shift                                          (0)
#define  SD_ALL_TOP_CR_CTRL_dummy_28_24_mask                                     (0x1F000000)
#define  SD_ALL_TOP_CR_CTRL_asic_dbg_sel_mask                                    (0x00F00000)
#define  SD_ALL_TOP_CR_CTRL_dbg_sel_mask                                         (0x000FF000)
#define  SD_ALL_TOP_CR_CTRL_wrap_dbg_sel_mask                                    (0x00000FC0)
#define  SD_ALL_TOP_CR_CTRL_map_sel_mask                                         (0x00000020)
#define  SD_ALL_TOP_CR_CTRL_xfer_dir_mask                                        (0x00000010)
#define  SD_ALL_TOP_CR_CTRL_boot_from_cr_mask                                    (0x00000008)
#define  SD_ALL_TOP_CR_CTRL_buff_timing_mask                                     (0x00000006)
#define  SD_ALL_TOP_CR_CTRL_cp_en_mask                                           (0x00000001)
#define  SD_ALL_TOP_CR_CTRL_dummy_28_24(data)                                    (0x1F000000&((data)<<24))
#define  SD_ALL_TOP_CR_CTRL_asic_dbg_sel(data)                                   (0x00F00000&((data)<<20))
#define  SD_ALL_TOP_CR_CTRL_dbg_sel(data)                                        (0x000FF000&((data)<<12))
#define  SD_ALL_TOP_CR_CTRL_wrap_dbg_sel(data)                                   (0x00000FC0&((data)<<6))
#define  SD_ALL_TOP_CR_CTRL_map_sel(data)                                        (0x00000020&((data)<<5))
#define  SD_ALL_TOP_CR_CTRL_xfer_dir(data)                                       (0x00000010&((data)<<4))
#define  SD_ALL_TOP_CR_CTRL_boot_from_cr(data)                                   (0x00000008&((data)<<3))
#define  SD_ALL_TOP_CR_CTRL_buff_timing(data)                                    (0x00000006&((data)<<1))
#define  SD_ALL_TOP_CR_CTRL_cp_en(data)                                          (0x00000001&(data))
#define  SD_ALL_TOP_CR_CTRL_get_dummy_28_24(data)                                ((0x1F000000&(data))>>24)
#define  SD_ALL_TOP_CR_CTRL_get_asic_dbg_sel(data)                               ((0x00F00000&(data))>>20)
#define  SD_ALL_TOP_CR_CTRL_get_dbg_sel(data)                                    ((0x000FF000&(data))>>12)
#define  SD_ALL_TOP_CR_CTRL_get_wrap_dbg_sel(data)                               ((0x00000FC0&(data))>>6)
#define  SD_ALL_TOP_CR_CTRL_get_map_sel(data)                                    ((0x00000020&(data))>>5)
#define  SD_ALL_TOP_CR_CTRL_get_xfer_dir(data)                                   ((0x00000010&(data))>>4)
#define  SD_ALL_TOP_CR_CTRL_get_boot_from_cr(data)                               ((0x00000008&(data))>>3)
#define  SD_ALL_TOP_CR_CTRL_get_buff_timing(data)                                ((0x00000006&(data))>>1)
#define  SD_ALL_TOP_CR_CTRL_get_cp_en(data)                                      (0x00000001&(data))

#define  SD_ALL_TOP_ARB_STS                                                      0x18010D1C
#define  SD_ALL_TOP_ARB_STS_reg_addr                                             "0xB8010D1C"
#define  SD_ALL_TOP_ARB_STS_reg                                                  0xB8010D1C
#define  SD_ALL_TOP_ARB_STS_inst_addr                                            "0x003F"
#define  set_SD_ALL_TOP_ARB_STS_reg(data)                                        (*((volatile unsigned int*)SD_ALL_TOP_ARB_STS_reg)=data)
#define  get_SD_ALL_TOP_ARB_STS_reg                                              (*((volatile unsigned int*)SD_ALL_TOP_ARB_STS_reg))
#define  SD_ALL_TOP_ARB_STS_arb_sts_shift                                        (0)
#define  SD_ALL_TOP_ARB_STS_arb_sts_mask                                         (0x000000FF)
#define  SD_ALL_TOP_ARB_STS_arb_sts(data)                                        (0x000000FF&(data))
#define  SD_ALL_TOP_ARB_STS_get_arb_sts(data)                                    (0x000000FF&(data))

#define  SD_ALL_TOP_SRAM_DATA                                                    0x18010D20
#define  SD_ALL_TOP_SRAM_DATA_reg_addr                                           "0xB8010D20"
#define  SD_ALL_TOP_SRAM_DATA_reg                                                0xB8010D20
#define  SD_ALL_TOP_SRAM_DATA_inst_addr                                          "0x0040"
#define  set_SD_ALL_TOP_SRAM_DATA_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_SRAM_DATA_reg)=data)
#define  get_SD_ALL_TOP_SRAM_DATA_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_SRAM_DATA_reg))
#define  SD_ALL_TOP_SRAM_DATA_data_shift                                         (0)
#define  SD_ALL_TOP_SRAM_DATA_data_mask                                          (0xFFFFFFFF)
#define  SD_ALL_TOP_SRAM_DATA_data(data)                                         (0xFFFFFFFF&(data))
#define  SD_ALL_TOP_SRAM_DATA_get_data(data)                                     (0xFFFFFFFF&(data))

#define  SD_ALL_TOP_CLK_PHASE_SEL                                                0x18010D24
#define  SD_ALL_TOP_CLK_PHASE_SEL_reg_addr                                       "0xB8010D24"
#define  SD_ALL_TOP_CLK_PHASE_SEL_reg                                            0xB8010D24
#define  SD_ALL_TOP_CLK_PHASE_SEL_inst_addr                                      "0x0041"
#define  set_SD_ALL_TOP_CLK_PHASE_SEL_reg(data)                                  (*((volatile unsigned int*)SD_ALL_TOP_CLK_PHASE_SEL_reg)=data)
#define  get_SD_ALL_TOP_CLK_PHASE_SEL_reg                                        (*((volatile unsigned int*)SD_ALL_TOP_CLK_PHASE_SEL_reg))
#define  SD_ALL_TOP_CLK_PHASE_SEL_push_phase_sel_shift                           (16)
#define  SD_ALL_TOP_CLK_PHASE_SEL_samp_phase_sel_shift                           (0)
#define  SD_ALL_TOP_CLK_PHASE_SEL_push_phase_sel_mask                            (0x00FF0000)
#define  SD_ALL_TOP_CLK_PHASE_SEL_samp_phase_sel_mask                            (0x0000FFFF)
#define  SD_ALL_TOP_CLK_PHASE_SEL_push_phase_sel(data)                           (0x00FF0000&((data)<<16))
#define  SD_ALL_TOP_CLK_PHASE_SEL_samp_phase_sel(data)                           (0x0000FFFF&(data))
#define  SD_ALL_TOP_CLK_PHASE_SEL_get_push_phase_sel(data)                       ((0x00FF0000&(data))>>16)
#define  SD_ALL_TOP_CLK_PHASE_SEL_get_samp_phase_sel(data)                       (0x0000FFFF&(data))

#define  SD_ALL_TOP_RSP_17B_0                                                    0x18010D28
#define  SD_ALL_TOP_RSP_17B_0_reg_addr                                           "0xB8010D28"
#define  SD_ALL_TOP_RSP_17B_0_reg                                                0xB8010D28
#define  SD_ALL_TOP_RSP_17B_0_inst_addr                                          "0x0042"
#define  set_SD_ALL_TOP_RSP_17B_0_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_0_reg)=data)
#define  get_SD_ALL_TOP_RSP_17B_0_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_0_reg))
#define  SD_ALL_TOP_RSP_17B_0_rsp_buf_0_shift                                    (0)
#define  SD_ALL_TOP_RSP_17B_0_rsp_buf_0_mask                                     (0x0000FFFF)
#define  SD_ALL_TOP_RSP_17B_0_rsp_buf_0(data)                                    (0x0000FFFF&(data))
#define  SD_ALL_TOP_RSP_17B_0_get_rsp_buf_0(data)                                (0x0000FFFF&(data))

#define  SD_ALL_TOP_RSP_17B_1                                                    0x18010D2C
#define  SD_ALL_TOP_RSP_17B_1_reg_addr                                           "0xB8010D2C"
#define  SD_ALL_TOP_RSP_17B_1_reg                                                0xB8010D2C
#define  SD_ALL_TOP_RSP_17B_1_inst_addr                                          "0x0043"
#define  set_SD_ALL_TOP_RSP_17B_1_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_1_reg)=data)
#define  get_SD_ALL_TOP_RSP_17B_1_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_1_reg))
#define  SD_ALL_TOP_RSP_17B_1_rsp_buf_1_shift                                    (0)
#define  SD_ALL_TOP_RSP_17B_1_rsp_buf_1_mask                                     (0x0000FFFF)
#define  SD_ALL_TOP_RSP_17B_1_rsp_buf_1(data)                                    (0x0000FFFF&(data))
#define  SD_ALL_TOP_RSP_17B_1_get_rsp_buf_1(data)                                (0x0000FFFF&(data))

#define  SD_ALL_TOP_RSP_17B_2                                                    0x18010D30
#define  SD_ALL_TOP_RSP_17B_2_reg_addr                                           "0xB8010D30"
#define  SD_ALL_TOP_RSP_17B_2_reg                                                0xB8010D30
#define  SD_ALL_TOP_RSP_17B_2_inst_addr                                          "0x0044"
#define  set_SD_ALL_TOP_RSP_17B_2_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_2_reg)=data)
#define  get_SD_ALL_TOP_RSP_17B_2_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_2_reg))
#define  SD_ALL_TOP_RSP_17B_2_rsp_buf_2_shift                                    (0)
#define  SD_ALL_TOP_RSP_17B_2_rsp_buf_2_mask                                     (0x0000FFFF)
#define  SD_ALL_TOP_RSP_17B_2_rsp_buf_2(data)                                    (0x0000FFFF&(data))
#define  SD_ALL_TOP_RSP_17B_2_get_rsp_buf_2(data)                                (0x0000FFFF&(data))

#define  SD_ALL_TOP_RSP_17B_3                                                    0x18010D34
#define  SD_ALL_TOP_RSP_17B_3_reg_addr                                           "0xB8010D34"
#define  SD_ALL_TOP_RSP_17B_3_reg                                                0xB8010D34
#define  SD_ALL_TOP_RSP_17B_3_inst_addr                                          "0x0045"
#define  set_SD_ALL_TOP_RSP_17B_3_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_3_reg)=data)
#define  get_SD_ALL_TOP_RSP_17B_3_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_3_reg))
#define  SD_ALL_TOP_RSP_17B_3_rsp_buf_3_shift                                    (0)
#define  SD_ALL_TOP_RSP_17B_3_rsp_buf_3_mask                                     (0x0000FFFF)
#define  SD_ALL_TOP_RSP_17B_3_rsp_buf_3(data)                                    (0x0000FFFF&(data))
#define  SD_ALL_TOP_RSP_17B_3_get_rsp_buf_3(data)                                (0x0000FFFF&(data))

#define  SD_ALL_TOP_RSP_17B_4                                                    0x18010D38
#define  SD_ALL_TOP_RSP_17B_4_reg_addr                                           "0xB8010D38"
#define  SD_ALL_TOP_RSP_17B_4_reg                                                0xB8010D38
#define  SD_ALL_TOP_RSP_17B_4_inst_addr                                          "0x0046"
#define  set_SD_ALL_TOP_RSP_17B_4_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_4_reg)=data)
#define  get_SD_ALL_TOP_RSP_17B_4_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_4_reg))
#define  SD_ALL_TOP_RSP_17B_4_rsp_buf_4_shift                                    (0)
#define  SD_ALL_TOP_RSP_17B_4_rsp_buf_4_mask                                     (0x0000FFFF)
#define  SD_ALL_TOP_RSP_17B_4_rsp_buf_4(data)                                    (0x0000FFFF&(data))
#define  SD_ALL_TOP_RSP_17B_4_get_rsp_buf_4(data)                                (0x0000FFFF&(data))

#define  SD_ALL_TOP_RSP_17B_5                                                    0x18010D3C
#define  SD_ALL_TOP_RSP_17B_5_reg_addr                                           "0xB8010D3C"
#define  SD_ALL_TOP_RSP_17B_5_reg                                                0xB8010D3C
#define  SD_ALL_TOP_RSP_17B_5_inst_addr                                          "0x0047"
#define  set_SD_ALL_TOP_RSP_17B_5_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_5_reg)=data)
#define  get_SD_ALL_TOP_RSP_17B_5_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_5_reg))
#define  SD_ALL_TOP_RSP_17B_5_rsp_buf_5_shift                                    (0)
#define  SD_ALL_TOP_RSP_17B_5_rsp_buf_5_mask                                     (0x0000FFFF)
#define  SD_ALL_TOP_RSP_17B_5_rsp_buf_5(data)                                    (0x0000FFFF&(data))
#define  SD_ALL_TOP_RSP_17B_5_get_rsp_buf_5(data)                                (0x0000FFFF&(data))

#define  SD_ALL_TOP_RSP_17B_6                                                    0x18010D40
#define  SD_ALL_TOP_RSP_17B_6_reg_addr                                           "0xB8010D40"
#define  SD_ALL_TOP_RSP_17B_6_reg                                                0xB8010D40
#define  SD_ALL_TOP_RSP_17B_6_inst_addr                                          "0x0048"
#define  set_SD_ALL_TOP_RSP_17B_6_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_6_reg)=data)
#define  get_SD_ALL_TOP_RSP_17B_6_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_6_reg))
#define  SD_ALL_TOP_RSP_17B_6_rsp_buf_6_shift                                    (0)
#define  SD_ALL_TOP_RSP_17B_6_rsp_buf_6_mask                                     (0x0000FFFF)
#define  SD_ALL_TOP_RSP_17B_6_rsp_buf_6(data)                                    (0x0000FFFF&(data))
#define  SD_ALL_TOP_RSP_17B_6_get_rsp_buf_6(data)                                (0x0000FFFF&(data))

#define  SD_ALL_TOP_RSP_17B_7                                                    0x18010D44
#define  SD_ALL_TOP_RSP_17B_7_reg_addr                                           "0xB8010D44"
#define  SD_ALL_TOP_RSP_17B_7_reg                                                0xB8010D44
#define  SD_ALL_TOP_RSP_17B_7_inst_addr                                          "0x0049"
#define  set_SD_ALL_TOP_RSP_17B_7_reg(data)                                      (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_7_reg)=data)
#define  get_SD_ALL_TOP_RSP_17B_7_reg                                            (*((volatile unsigned int*)SD_ALL_TOP_RSP_17B_7_reg))
#define  SD_ALL_TOP_RSP_17B_7_rsp_buf_7_shift                                    (0)
#define  SD_ALL_TOP_RSP_17B_7_rsp_buf_7_mask                                     (0x0000FFFF)
#define  SD_ALL_TOP_RSP_17B_7_rsp_buf_7(data)                                    (0x0000FFFF&(data))
#define  SD_ALL_TOP_RSP_17B_7_get_rsp_buf_7(data)                                (0x0000FFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SD_ALL_TOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  initialmode:1;
        RBus_UInt32  clockdivider:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  sd30_async_fifo_rst_n:1;
        RBus_UInt32  modeselection:2;
        RBus_UInt32  buswidth:2;
    };
}sd_all_top_sd_configure1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  crc7calculationenable:1;
        RBus_UInt32  crc16checkenable:1;
        RBus_UInt32  waitwritecrcstatustimeoutenable:1;
        RBus_UInt32  ignorewritecrcerrorenable:1;
        RBus_UInt32  waitbusyendenable:1;
        RBus_UInt32  crc7checkenable:1;
        RBus_UInt32  responsetypeconfigure:2;
    };
}sd_all_top_sd_configure2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_dummy_reg0:7;
        RBus_UInt32  sdcmdresponsetimeoutenable:1;
    };
}sd_all_top_sd_configure3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  crc7error:1;
        RBus_UInt32  crc16error:1;
        RBus_UInt32  writecrcerror:1;
        RBus_UInt32  statusofwritecrc:3;
        RBus_UInt32  getwritecrcstatustime_outerror:1;
        RBus_UInt32  sdtuningpatterncompareerror:1;
    };
}sd_all_top_sd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  sdcmdresponsetimeouterror:1;
    };
}sd_all_top_sd_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_clktoggleenable:1;
        RBus_UInt32  stopsd_clktogglingwhennocmdordatatransfer:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dat3dat0:4;
        RBus_UInt32  cmd:1;
    };
}sd_all_top_sd_bus_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  res2:1;
        RBus_UInt32  sd_dummy_reg1:7;
    };
}sd_all_top_sd_cmd_code_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  samplepointtypeforddrdat:1;
        RBus_UInt32  samplepointselectionforddrdat:1;
        RBus_UInt32  samplepointtypeforddrcmd:1;
        RBus_UInt32  samplepointselectionforddrcmd:1;
        RBus_UInt32  samplepointselectionforsd20cmdordata:1;
        RBus_UInt32  res2:3;
    };
}sd_all_top_sd_sample_point_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pushpointselectiontypeforddrcmdordat:1;
        RBus_UInt32  pushpointselectionforddrmodedat:1;
        RBus_UInt32  pushpointselectionforddrmodecmd:1;
        RBus_UInt32  pushpointselectionforsd20modecmdordata:1;
        RBus_UInt32  choosesamplingedgeofpclktosampledpclk:1;
        RBus_UInt32  choosesdclkpolaritysolutionforddrmode:2;
        RBus_UInt32  sdclkpolarityswap:1;
    };
}sd_all_top_sd_push_point_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  command_7_0orresponsedata_7_0:8;
    };
}sd_all_top_sd_cmd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  command_15_8orresponsedata_15_8:8;
    };
}sd_all_top_sd_cmd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  command_23_16orresponsedata_23_16:8;
    };
}sd_all_top_sd_cmd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  command_31_24orresponsedata_31_24:8;
    };
}sd_all_top_sd_cmd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  command_39_32orresponsedata_39_32:8;
    };
}sd_all_top_sd_cmd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  command_47_40orresponsedata_47_40:8;
    };
}sd_all_top_sd_cmd5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bytecount_7_0:8;
    };
}sd_all_top_sd_byte_cnt_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  bytecount_10_8:3;
    };
}sd_all_top_sd_byte_cnt_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  blockcount_7_0:8;
    };
}sd_all_top_sd_block_cnt_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  blockcount_14_8:8;
    };
}sd_all_top_sd_block_cnt_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  start:1;
        RBus_UInt32  end:1;
        RBus_UInt32  statusofsdcardmodulestatemachine:1;
        RBus_UInt32  errorbit:1;
        RBus_UInt32  commandcode:4;
    };
}sd_all_top_sd_transfer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  detect_ddr_cmdodd_start_biterrorflag:1;
        RBus_UInt32  forcecmd1:1;
        RBus_UInt32  forcecmd0:1;
        RBus_UInt32  cmdstartbit:1;
        RBus_UInt32  detect_ddr_data_odd_start_biterrorflag:1;
        RBus_UInt32  forcedata1:1;
        RBus_UInt32  forcedata0:1;
        RBus_UInt32  datastartbit:1;
    };
}sd_all_top_sd_ddr_chk_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cmdstatemachineidle:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cmdstatemachine:4;
    };
}sd_all_top_sd_cmd_state_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  datastatemachineidle:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  datastatemachine:4;
    };
}sd_all_top_sd_data_state_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  turn_aroundtimeenable:1;
        RBus_UInt32  bus_ta_time:3;
    };
}sd_all_top_sd_bus_ta_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  stopsd20sdclkconfigurationenable:1;
        RBus_UInt32  stop_sd20clk_cfg_1:1;
        RBus_UInt32  stop_sd20clk_cfg_0:1;
        RBus_UInt32  stopsd30sdclkconfigurationenable:1;
        RBus_UInt32  stop_sd30clk_cfg_1:1;
        RBus_UInt32  stop_sd30clk_cfg_0:1;
    };
}sd_all_top_sd_stop_sdclk_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  auto_reset_fifoenable:1;
    };
}sd_all_top_sd_auto_rst_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  sdinfinitemode:1;
        RBus_UInt32  sdcontrollerbusy:1;
        RBus_UInt32  sdcontrollerstop:1;
    };
}sd_all_top_sd_rw_stop_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_dummy_3:6;
        RBus_UInt32  res2:2;
    };
}sd_all_top_sd_dummy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_address_7_0:8;
    };
}sd_all_top_sd_addr_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_address_15_8:8;
    };
}sd_all_top_sd_addr_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_start_addr_7_0:8;
    };
}sd_all_top_sd_start_addr_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_start_addr_15_8:8;
    };
}sd_all_top_sd_start_addr_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_start_addr_23_16:8;
    };
}sd_all_top_sd_start_addr_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_start_addr_31_24:8;
    };
}sd_all_top_sd_start_addr_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_rsp_mask_7_0:8;
    };
}sd_all_top_sd_rsp_mask_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_rsp_mask_15_8:8;
    };
}sd_all_top_sd_rsp_mask_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_rsp_mask_23_16:8;
    };
}sd_all_top_sd_rsp_mask_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_rsp_mask_31_24:8;
    };
}sd_all_top_sd_rsp_mask_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_rsp_data_7_0:8;
    };
}sd_all_top_sd_rsp_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_rsp_data_15_8:8;
    };
}sd_all_top_sd_rsp_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_rsp_data_23_16:8;
    };
}sd_all_top_sd_rsp_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sd_rsp_data_31_24:8;
    };
}sd_all_top_sd_rsp_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  sd_write_delay:4;
    };
}sd_all_top_sd_wr_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  sd_read_delay:4;
    };
}sd_all_top_sd_rd_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dma_out_index:6;
        RBus_UInt32  res2:10;
        RBus_UInt32  dma_in_index:6;
    };
}sd_all_top_cr_dma_ptr_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_in_addr:29;
        RBus_UInt32  res1:3;
    };
}sd_all_top_cr_dma_in_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_out_addr:29;
        RBus_UInt32  res1:3;
    };
}sd_all_top_cr_dma_out_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  stop_by_kcpu_force:1;
        RBus_UInt32  write_protection:1;
        RBus_UInt32  card_detection:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  decode_error:1;
        RBus_UInt32  decode_finish:1;
        RBus_UInt32  card_status_change:1;
    };
}sd_all_top_cr_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  res2:2;
        RBus_UInt32  card_detection_intmask:1;
        RBus_UInt32  decode_error_mask:1;
        RBus_UInt32  decode_finish_mask:1;
        RBus_UInt32  card_status_change_mask:1;
    };
}sd_all_top_cr_int_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  reg_stop:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
    };
}sd_all_top_cr_reg_mode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  des_addr_auto_inc:1;
        RBus_UInt32  des_sw_hs_enable:1;
        RBus_UInt32  rd_des_cmd_wr_port:1;
        RBus_UInt32  des_stop:1;
        RBus_UInt32  des_mode_len:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  des_mode_en:1;
    };
}sd_all_top_cr_des_mode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  des_command:32;
    };
}sd_all_top_des_cmd_wr_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_rstn:1;
    };
}sd_all_top_cr_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  rma_0:4;
        RBus_UInt32  rmea_0:1;
        RBus_UInt32  rmb_0:4;
        RBus_UInt32  rmeb_0:1;
    };
}sd_all_top_cr_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_mode_0:1;
    };
}sd_all_top_cr_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_done_0:1;
    };
}sd_all_top_cr_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_fail_0:1;
    };
}sd_all_top_cr_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_modeofmbist_0:1;
    };
}sd_all_top_cr_bist_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_resumeofmbist_0:1;
    };
}sd_all_top_cr_bist_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_doneofmbist_0:1;
    };
}sd_all_top_cr_bist_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_pauseofmbist_0:1;
    };
}sd_all_top_cr_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_failofmbist_0:1;
    };
}sd_all_top_cr_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dummy18010d18_28_24:5;
        RBus_UInt32  asic_dbg_sel:4;
        RBus_UInt32  dbg_sel:8;
        RBus_UInt32  wrap_dbg_sel:6;
        RBus_UInt32  map_sel:1;
        RBus_UInt32  xfer_dir:1;
        RBus_UInt32  boot_from_cr:1;
        RBus_UInt32  buff_timing:2;
        RBus_UInt32  cp_en:1;
    };
}sd_all_top_cr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  arb_sts:8;
    };
}sd_all_top_arb_sts_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}sd_all_top_sram_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  push_phase_sel:8;
        RBus_UInt32  samp_phase_sel:16;
    };
}sd_all_top_clk_phase_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rsp_buf_0:16;
    };
}sd_all_top_rsp_17b_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rsp_buf_1:16;
    };
}sd_all_top_rsp_17b_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rsp_buf_2:16;
    };
}sd_all_top_rsp_17b_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rsp_buf_3:16;
    };
}sd_all_top_rsp_17b_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rsp_buf_4:16;
    };
}sd_all_top_rsp_17b_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rsp_buf_5:16;
    };
}sd_all_top_rsp_17b_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rsp_buf_6:16;
    };
}sd_all_top_rsp_17b_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rsp_buf_7:16;
    };
}sd_all_top_rsp_17b_7_RBUS;

#else //apply LITTLE_ENDIAN

//======SD_ALL_TOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buswidth:2;
        RBus_UInt32  modeselection:2;
        RBus_UInt32  sd30_async_fifo_rst_n:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  clockdivider:1;
        RBus_UInt32  initialmode:1;
        RBus_UInt32  res2:24;
    };
}sd_all_top_sd_configure1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  responsetypeconfigure:2;
        RBus_UInt32  crc7checkenable:1;
        RBus_UInt32  waitbusyendenable:1;
        RBus_UInt32  ignorewritecrcerrorenable:1;
        RBus_UInt32  waitwritecrcstatustimeoutenable:1;
        RBus_UInt32  crc16checkenable:1;
        RBus_UInt32  crc7calculationenable:1;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_configure2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sdcmdresponsetimeoutenable:1;
        RBus_UInt32  sd_dummy_reg0:7;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_configure3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sdtuningpatterncompareerror:1;
        RBus_UInt32  getwritecrcstatustime_outerror:1;
        RBus_UInt32  statusofwritecrc:3;
        RBus_UInt32  writecrcerror:1;
        RBus_UInt32  crc16error:1;
        RBus_UInt32  crc7error:1;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sdcmdresponsetimeouterror:1;
        RBus_UInt32  res1:31;
    };
}sd_all_top_sd_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd:1;
        RBus_UInt32  dat3dat0:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  stopsd_clktogglingwhennocmdordatatransfer:1;
        RBus_UInt32  sd_clktoggleenable:1;
        RBus_UInt32  res2:24;
    };
}sd_all_top_sd_bus_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_dummy_reg1:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:24;
    };
}sd_all_top_sd_cmd_code_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  samplepointselectionforsd20cmdordata:1;
        RBus_UInt32  samplepointselectionforddrcmd:1;
        RBus_UInt32  samplepointtypeforddrcmd:1;
        RBus_UInt32  samplepointselectionforddrdat:1;
        RBus_UInt32  samplepointtypeforddrdat:1;
        RBus_UInt32  res2:24;
    };
}sd_all_top_sd_sample_point_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sdclkpolarityswap:1;
        RBus_UInt32  choosesdclkpolaritysolutionforddrmode:2;
        RBus_UInt32  choosesamplingedgeofpclktosampledpclk:1;
        RBus_UInt32  pushpointselectionforsd20modecmdordata:1;
        RBus_UInt32  pushpointselectionforddrmodecmd:1;
        RBus_UInt32  pushpointselectionforddrmodedat:1;
        RBus_UInt32  pushpointselectiontypeforddrcmdordat:1;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_push_point_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  command_7_0orresponsedata_7_0:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_cmd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  command_15_8orresponsedata_15_8:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_cmd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  command_23_16orresponsedata_23_16:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_cmd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  command_31_24orresponsedata_31_24:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_cmd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  command_39_32orresponsedata_39_32:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_cmd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  command_47_40orresponsedata_47_40:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_cmd5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bytecount_7_0:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_byte_cnt_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bytecount_10_8:3;
        RBus_UInt32  res1:29;
    };
}sd_all_top_sd_byte_cnt_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blockcount_7_0:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_block_cnt_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blockcount_14_8:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_block_cnt_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  commandcode:4;
        RBus_UInt32  errorbit:1;
        RBus_UInt32  statusofsdcardmodulestatemachine:1;
        RBus_UInt32  end:1;
        RBus_UInt32  start:1;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_transfer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  datastartbit:1;
        RBus_UInt32  forcedata0:1;
        RBus_UInt32  forcedata1:1;
        RBus_UInt32  detect_ddr_data_odd_start_biterrorflag:1;
        RBus_UInt32  cmdstartbit:1;
        RBus_UInt32  forcecmd0:1;
        RBus_UInt32  forcecmd1:1;
        RBus_UInt32  detect_ddr_cmdodd_start_biterrorflag:1;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_ddr_chk_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmdstatemachine:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  cmdstatemachineidle:1;
        RBus_UInt32  res2:24;
    };
}sd_all_top_sd_cmd_state_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  datastatemachine:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  datastatemachineidle:1;
        RBus_UInt32  res2:24;
    };
}sd_all_top_sd_data_state_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bus_ta_time:3;
        RBus_UInt32  turn_aroundtimeenable:1;
        RBus_UInt32  res1:28;
    };
}sd_all_top_sd_bus_ta_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stop_sd30clk_cfg_0:1;
        RBus_UInt32  stop_sd30clk_cfg_1:1;
        RBus_UInt32  stopsd30sdclkconfigurationenable:1;
        RBus_UInt32  stop_sd20clk_cfg_0:1;
        RBus_UInt32  stop_sd20clk_cfg_1:1;
        RBus_UInt32  stopsd20sdclkconfigurationenable:1;
        RBus_UInt32  res1:26;
    };
}sd_all_top_sd_stop_sdclk_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_reset_fifoenable:1;
        RBus_UInt32  res1:31;
    };
}sd_all_top_sd_auto_rst_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sdcontrollerstop:1;
        RBus_UInt32  sdcontrollerbusy:1;
        RBus_UInt32  sdinfinitemode:1;
        RBus_UInt32  res1:29;
    };
}sd_all_top_sd_rw_stop_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  sd_dummy_3:6;
        RBus_UInt32  res2:24;
    };
}sd_all_top_sd_dummy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_address_7_0:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_addr_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_address_15_8:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_addr_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_start_addr_7_0:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_start_addr_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_start_addr_15_8:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_start_addr_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_start_addr_23_16:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_start_addr_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_start_addr_31_24:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_start_addr_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_rsp_mask_7_0:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_rsp_mask_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_rsp_mask_15_8:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_rsp_mask_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_rsp_mask_23_16:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_rsp_mask_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_rsp_mask_31_24:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_rsp_mask_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_rsp_data_7_0:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_rsp_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_rsp_data_15_8:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_rsp_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_rsp_data_23_16:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_rsp_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_rsp_data_31_24:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_sd_rsp_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_write_delay:4;
        RBus_UInt32  res1:28;
    };
}sd_all_top_sd_wr_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sd_read_delay:4;
        RBus_UInt32  res1:28;
    };
}sd_all_top_sd_rd_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_in_index:6;
        RBus_UInt32  res1:10;
        RBus_UInt32  dma_out_index:6;
        RBus_UInt32  res2:10;
    };
}sd_all_top_cr_dma_ptr_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_in_addr:29;
    };
}sd_all_top_cr_dma_in_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_out_addr:29;
    };
}sd_all_top_cr_dma_out_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  card_status_change:1;
        RBus_UInt32  decode_finish:1;
        RBus_UInt32  decode_error:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  card_detection:1;
        RBus_UInt32  write_protection:1;
        RBus_UInt32  stop_by_kcpu_force:1;
        RBus_UInt32  res2:25;
    };
}sd_all_top_cr_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  card_status_change_mask:1;
        RBus_UInt32  decode_finish_mask:1;
        RBus_UInt32  decode_error_mask:1;
        RBus_UInt32  card_detection_intmask:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:26;
    };
}sd_all_top_cr_int_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_stop:1;
        RBus_UInt32  res4:28;
    };
}sd_all_top_cr_reg_mode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  des_mode_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  des_mode_len:4;
        RBus_UInt32  des_stop:1;
        RBus_UInt32  rd_des_cmd_wr_port:1;
        RBus_UInt32  des_sw_hs_enable:1;
        RBus_UInt32  des_addr_auto_inc:1;
        RBus_UInt32  res3:21;
    };
}sd_all_top_cr_des_mode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  des_command:32;
    };
}sd_all_top_des_cmd_wr_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_rstn:1;
        RBus_UInt32  res1:31;
    };
}sd_all_top_cr_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rmeb_0:1;
        RBus_UInt32  rmb_0:4;
        RBus_UInt32  rmea_0:1;
        RBus_UInt32  rma_0:4;
        RBus_UInt32  res1:22;
    };
}sd_all_top_cr_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mode_0:1;
        RBus_UInt32  res1:31;
    };
}sd_all_top_cr_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_done_0:1;
        RBus_UInt32  res1:31;
    };
}sd_all_top_cr_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  res1:31;
    };
}sd_all_top_cr_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_modeofmbist_0:1;
        RBus_UInt32  res1:31;
    };
}sd_all_top_cr_bist_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_resumeofmbist_0:1;
        RBus_UInt32  res1:31;
    };
}sd_all_top_cr_bist_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_doneofmbist_0:1;
        RBus_UInt32  res1:31;
    };
}sd_all_top_cr_bist_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_pauseofmbist_0:1;
        RBus_UInt32  res1:31;
    };
}sd_all_top_cr_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_failofmbist_0:1;
        RBus_UInt32  res1:31;
    };
}sd_all_top_cr_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_en:1;
        RBus_UInt32  buff_timing:2;
        RBus_UInt32  boot_from_cr:1;
        RBus_UInt32  xfer_dir:1;
        RBus_UInt32  map_sel:1;
        RBus_UInt32  wrap_dbg_sel:6;
        RBus_UInt32  dbg_sel:8;
        RBus_UInt32  asic_dbg_sel:4;
        RBus_UInt32  dummy18010d18_28_24:5;
        RBus_UInt32  res1:3;
    };
}sd_all_top_cr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  arb_sts:8;
        RBus_UInt32  res1:24;
    };
}sd_all_top_arb_sts_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}sd_all_top_sram_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  samp_phase_sel:16;
        RBus_UInt32  push_phase_sel:8;
        RBus_UInt32  res1:8;
    };
}sd_all_top_clk_phase_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsp_buf_0:16;
        RBus_UInt32  res1:16;
    };
}sd_all_top_rsp_17b_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsp_buf_1:16;
        RBus_UInt32  res1:16;
    };
}sd_all_top_rsp_17b_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsp_buf_2:16;
        RBus_UInt32  res1:16;
    };
}sd_all_top_rsp_17b_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsp_buf_3:16;
        RBus_UInt32  res1:16;
    };
}sd_all_top_rsp_17b_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsp_buf_4:16;
        RBus_UInt32  res1:16;
    };
}sd_all_top_rsp_17b_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsp_buf_5:16;
        RBus_UInt32  res1:16;
    };
}sd_all_top_rsp_17b_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsp_buf_6:16;
        RBus_UInt32  res1:16;
    };
}sd_all_top_rsp_17b_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsp_buf_7:16;
        RBus_UInt32  res1:16;
    };
}sd_all_top_rsp_17b_7_RBUS;




#endif 


#endif 
