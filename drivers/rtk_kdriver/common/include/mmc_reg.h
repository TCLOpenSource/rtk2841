/**************************************************************
// Spec Version                  : 0.9
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2013/12/5 16:43:43
***************************************************************/


#ifndef _CR_REG_H_INCLUDED_
#define _CR_REG_H_INCLUDED_
#ifdef  _CR_USE_STRUCT

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     InitialMode:1;
unsigned int     ClockDivider:1;
unsigned int     reserved_1:1;
unsigned int     SD30_Async_FIFO_Rst_n:1;
unsigned int     ModeSelection:2;
unsigned int     BusWidth:2;
}SD_CONFIGURE1;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     CRC7CalculationEnable:1;
unsigned int     CRC16CheckEnable:1;
unsigned int     WaitWriteCRCStatusTimeOutEnable:1;
unsigned int     IgnoreWriteCRCErrorEnable:1;
unsigned int     WaitBusyEndEnable:1;
unsigned int     CRC7CheckEnable:1;
unsigned int     ResponseTypeConfigure:2;
}SD_CONFIGURE2;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     Sd_dummy_reg0:7;
unsigned int     SDCMD:1;
}SD_CONFIGURE3;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     CRC7Error:1;
unsigned int     CRC16Error:1;
unsigned int     WriteCRCError:1;
unsigned int     StatusOfWriteCRC:3;
unsigned int     GetWriteCRCStatusTime_outError:1;
unsigned int     SDTuningPatternCompareError:1;
}SD_STATUS;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     SDCMDResponseTimeoutError:1;
}SD_STATUS2;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_CLKToggleEnable:1;
unsigned int     StopSD_CLKtogglingwhennocmdordatatransfer:1;
unsigned int     reserved_1:1;
unsigned int     DAT3DAT0:4;
unsigned int     CMD:1;
}SD_BUS_STATUS;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     sd_dummy_reg1:8;
}SD_CMD_CODE;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SamplePointTypeforDDRDAT:1;
unsigned int     SamplePointSelectionforDDRDAT:1;
unsigned int     SamplePointTypeforDDRCMD:1;
unsigned int     SamplePointSelectionforDDRCMD:1;
unsigned int     SamplePointSelectionforSD20CMDorDATA:1;
unsigned int     reserved_1:3;
}SD_SAMPLE_POINT_CTL;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     PushPointSelectionTypeforDDRCMDorDAT:1;
unsigned int     PushPointSelectionforDDRmodeDAT:1;
unsigned int     PushPointSelectionforDDRmodeCMD:1;
unsigned int     PushPointSelectionforSD20modeCMDorDATA:1;
unsigned int     ChoosesamplingedgeofPCLKtosampleDPCLK:1;
unsigned int     chooseSDCLKPolaritysolutionforDDRmode:2;
unsigned int     SDCLKPolaritySwap:1;
}SD_PUSH_POINT_CTL;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     Command70orResponseData70:8;
}SD_CMD0;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     Command158orResponseData158:8;
}SD_CMD1;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     Command2316orResponseData2316:8;
}SD_CMD2;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     Command3124orResponseData3124:8;
}SD_CMD3;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     Command3932orResponseData3932:8;
}SD_CMD4;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     Command4740orResponseData4740:8;
}SD_CMD5;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     ByteCount70:8;
}SD_BYTE_CNT_L;

typedef struct
{
unsigned int     reserved_0:29;
unsigned int     ByteCount108:3;
}SD_BYTE_CNT_H;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     BlockCount70:8;
}SD_BLOCK_CNT_L;

typedef struct
{
unsigned int     reserved_0:25;
unsigned int     BlockCount148:7;
}SD_BLOCK_CNT_H;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     Start:1;
unsigned int     End:1;
unsigned int     StatusofSDcardmodulestatemachine:1;
unsigned int     ErrorBit:1;
unsigned int     CommandCode:4;
}SD_TRANSFER;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     Detect_ddr_cmd:1;
unsigned int     Forcecmd1:1;
unsigned int     Forcecmd0:1;
unsigned int     CMDStartbit:1;
unsigned int     Detect_ddr_data_:1;
unsigned int     Forcedata1:1;
unsigned int     Forcedata0:1;
unsigned int     DataStartbit:1;
}SD_DDR_CHK_START;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     CMDStateMachineidle:1;
unsigned int     reserved_1:3;
unsigned int     CMDStateMachine:4;
}SD_CMD_STATE;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     DATAStateMachineidle:1;
unsigned int     reserved_1:3;
unsigned int     DATAStateMachine:4;
}SD_DATA_STATE;

typedef struct
{
unsigned int     reserved_0:28;
unsigned int     Turn_AroundTimeenable:1;
unsigned int     Bus_TA_Time:3;
}SD_BUS_TA_TIME;

typedef struct
{
unsigned int     reserved_0:26;
unsigned int     STOPSD20SDCLKconfigurationenable:1;
unsigned int     STOP_SD20CLK_CFG1:1;
unsigned int     STOP_SD20CLK_CFG0:1;
unsigned int     STOPSD30SDCLKconfigurationenable:1;
unsigned int     STOP_SD30CLK_CFG1:1;
unsigned int     STOP_SD30CLK_CFG0:1;
}SD_STOP_SDCLK_CFG;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     Auto_Reset_FIFOenable:1;
}SD_AUTO_RST_FIFO;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     AD_DAT70:8;
}SD_DAT_PAD;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_DUMMY_4:8;
}SD_DUMMY_4;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_DUMMY_5:8;
}SD_DUMMY_5;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD30DATODutyEnable:1;
unsigned int     SD30DATODelayDisable:3;
unsigned int     SD30CMDODutyEnable:1;
unsigned int     SD30CMDODelayDisable:3;
}SD_DUTY_CTL;

typedef struct
{
unsigned int     reserved_0:29;
unsigned int     SDInfiniteMode:1;
unsigned int     SDcontrollerbusy:1;
unsigned int     SDcontrollerstop:1;
}SD_RW_STOP_CTL;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_DUMMY_3:8;
}SD_DUMMY_3;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_address70:8;
}SD_ADDR_L;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_address158:8;
}SD_ADDR_H;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_start_addr70:8;
}SD_START_ADDR_0;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_start_addr158:8;
}SD_START_ADDR_1;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_start_addr2316:8;
}SD_START_ADDR_2;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_start_addr3124:8;
}SD_START_ADDR_3;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_rsp_mask70:8;
}SD_RSP_MASK_1;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_rsp_mask158:8;
}SD_RSP_MASK_2;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_rsp_mask2316:8;
}SD_RSP_MASK_3;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_rsp_mask3124:8;
}SD_RSP_MASK_4;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_rsp_data70:8;
}SD_RSP_DATA_1;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_rsp_data158:8;
}SD_RSP_DATA_2;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_rsp_data2316:8;
}SD_RSP_DATA_3;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SD_rsp_data3124:8;
}SD_RSP_DATA_4;

typedef struct
{
unsigned int     reserved_0:28;
unsigned int     SD_write_delay:4;
}SD_WR_DELAY;

typedef struct
{
unsigned int     reserved_0:28;
unsigned int     SD_read_delay:4;
}SD_RD_DELAY;

typedef struct
{
unsigned int     reserved_0:10;
unsigned int     dma_out_index:6;
unsigned int     reserved_1:10;
unsigned int     dma_in_index:6;
}CR_DMA_PTR_STATUS;

typedef struct
{
unsigned int     dma_in_addr:29;
unsigned int     reserved_0:3;
}CR_DMA_IN_ADDR;

typedef struct
{
unsigned int     dma_out_addr:29;
unsigned int     reserved_0:3;
}CR_DMA_OUT_ADDR;

typedef struct
{
unsigned int     reserved_0:26;
unsigned int     write_protection:1;
unsigned int     card_detection:1;
unsigned int     reserved:1;
unsigned int     decode_error:1;
unsigned int     decode_finish:1;
unsigned int     card_status_change:1;
}CR_INT_STATUS;

typedef struct
{
unsigned int     reserved_0:26;
unsigned int     reserved_1:2;
unsigned int     Card_detection_intmask:1;
unsigned int     decode_error_mask:1;
unsigned int     decode_finish_mask:1;
unsigned int     card_status_change_mask:1;
}CR_INT_MASK;

typedef struct
{
unsigned int     reserved_0:28;
unsigned int     reg_stop:1;
unsigned int     reserved_1:1;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
}CR_REG_MODE_CTRL;

typedef struct
{
unsigned int     reserved_0:21;
unsigned int     des_addr_auto_inc:1;
unsigned int     des_sw_hs_enable:1;
unsigned int     rd_des_cmd_wr_port:1;
unsigned int     des_stop:1;
unsigned int     des_mode_len:4;
unsigned int     reserved_1:1;
unsigned int     reserved_2:1;
unsigned int     des_mode_en:1;
}CR_DES_MODE_CTRL;

typedef struct
{
unsigned int     des_command:32;
}DES_CMD_WR_PORT;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     BIST_RSTN:1;
}CR_BIST_0;

typedef struct
{
unsigned int     reserved_0:22;
unsigned int     RMA_0:4;
unsigned int     RMEA_0:1;
unsigned int     RMB_0:4;
unsigned int     RMEB_0:1;
}CR_BIST_1;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     BIST_MODE_0:1;
}CR_BIST_MODE;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     BIST_DONE_0:1;
}CR_BIST_DONE;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     BIST_FAIL_0:1;
}CR_BIST_FAIL;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     DRF_MODEofMBIST_0:1;
}CR_BIST_DRF_MODE;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     DRF_RESUMEofMBIST_0:1;
}CR_BIST_DRF_RESUME;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     DRF_DONEofMBIST_0:1;
}CR_BIST_DRF_DONE;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     DRF_PAUSEofMBIST_0:1;
}CR_BIST_DRF_PAUSE;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     DRF_FAILofMBIST_0:1;
}CR_BIST_DRF_FAIL;

typedef struct
{
unsigned int     reserved_0:3;
unsigned int     Dummy:5;
unsigned int     Asic_dbg_sel:4;
unsigned int     Dbg_sel:8;
unsigned int     Wrap_dbg_sel:6;
unsigned int     Map_sel:1;
unsigned int     Xfer_dir:1;
unsigned int     Boot_from_cr:1;
unsigned int     Buff_timing:2;
unsigned int     CP_en:1;
}CR_CTRL;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     ARB_STS:8;
}ARB_STS;

typedef struct
{
unsigned int     DATA:32;
}SRAM_DATA;

typedef struct
{
unsigned int     push_phase_sel:16;
unsigned int     samp_phase_sel:16;
}CLK_PHASE_SEL;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     RSP_buf_0:16;
}RSP_17B_0;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     RSP_buf_1:16;
}RSP_17B_1;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     RSP_buf_2:16;
}RSP_17B_2;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     RSP_buf_3:16;
}RSP_17B_3;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     RSP_buf_4:16;
}RSP_17B_4;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     RSP_buf_5:16;
}RSP_17B_5;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     RSP_buf_6:16;
}RSP_17B_6;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     RSP_buf_7:16;
}RSP_17B_7;

typedef struct
{
unsigned int     reserved_0:30;
unsigned int     pr_en:1;
unsigned int     k_cpu_sel:1;
}KCPU_SEL;

typedef struct
{
unsigned int     Paddr_start:32;
}PADDR_START;

typedef struct
{
unsigned int     Paddr_end:32;
}PADDR_END;

typedef struct
{
unsigned int     reserved_0:29;
unsigned int     decode_error_k:1;
unsigned int     decode_finish_k:1;
unsigned int     reserved_1:1;
}CR_INT_STATUS_K;

typedef struct
{
unsigned int     reserved_0:29;
unsigned int     decode_error_mask:1;
unsigned int     decode_finish_mask:1;
unsigned int     reserved_1:1;
}CR_INT_MASK_K;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     s_cpu_sel:1;
}SCPU_SEL;

typedef struct
{
unsigned int     reserved_0:30;
unsigned int     cpu_st:2;
}CPU_ST;

#endif


/* Register Definition */
//#define SD_CONFIGURE1                                                                0x18010800
#define SD_CONFIGURE1_reg_addr                                                       "0x18010800"
#define SD_CONFIGURE1_reg                                                            0x18010800
#define set_SD_CONFIGURE1_reg(data) \
                    (*((volatile unsigned int*) SD_CONFIGURE1_reg)=data)
#define get_SD_CONFIGURE1_reg \
                    (*((volatile unsigned int*) SD_CONFIGURE1_reg))
#define SD_CONFIGURE1_inst_adr                                                       "0x0000"
#define SD_CONFIGURE1_inst                                                           0x0000
#define SD_CONFIGURE1_InitialMode_shift                                              (7)
#define SD_CONFIGURE1_InitialMode_mask                                               (0x00000080)
#define SD_CONFIGURE1_InitialMode(data)                                              (0x00000080&((data)<<7))
#define SD_CONFIGURE1_InitialMode_src(data)                                          ((0x00000080&(data))>>7)
#define SD_CONFIGURE1_get_InitialMode(data)                                          ((0x00000080&(data))>>7)
#define SD_CONFIGURE1_ClockDivider_shift                                             (6)
#define SD_CONFIGURE1_ClockDivider_mask                                              (0x00000040)
#define SD_CONFIGURE1_ClockDivider(data)                                             (0x00000040&((data)<<6))
#define SD_CONFIGURE1_ClockDivider_src(data)                                         ((0x00000040&(data))>>6)
#define SD_CONFIGURE1_get_ClockDivider(data)                                         ((0x00000040&(data))>>6)
#define SD_CONFIGURE1_SD30_Async_FIFO_Rst_n_shift                                    (4)
#define SD_CONFIGURE1_SD30_Async_FIFO_Rst_n_mask                                     (0x00000010)
#define SD_CONFIGURE1_SD30_Async_FIFO_Rst_n(data)                                    (0x00000010&((data)<<4))
#define SD_CONFIGURE1_SD30_Async_FIFO_Rst_n_src(data)                                ((0x00000010&(data))>>4)
#define SD_CONFIGURE1_get_SD30_Async_FIFO_Rst_n(data)                                ((0x00000010&(data))>>4)
#define SD_CONFIGURE1_ModeSelection_shift                                            (2)
#define SD_CONFIGURE1_ModeSelection_mask                                             (0x0000000C)
#define SD_CONFIGURE1_ModeSelection(data)                                            (0x0000000C&((data)<<2))
#define SD_CONFIGURE1_ModeSelection_src(data)                                        ((0x0000000C&(data))>>2)
#define SD_CONFIGURE1_get_ModeSelection(data)                                        ((0x0000000C&(data))>>2)
#define SD_CONFIGURE1_BusWidth_shift                                                 (0)
#define SD_CONFIGURE1_BusWidth_mask                                                  (0x00000003)
#define SD_CONFIGURE1_BusWidth(data)                                                 (0x00000003&((data)<<0))
#define SD_CONFIGURE1_BusWidth_src(data)                                             ((0x00000003&(data))>>0)
#define SD_CONFIGURE1_get_BusWidth(data)                                             ((0x00000003&(data))>>0)


//#define SD_CONFIGURE2                                                                0x18010804
#define SD_CONFIGURE2_reg_addr                                                       "0x18010804"
#define SD_CONFIGURE2_reg                                                            0x18010804
#define set_SD_CONFIGURE2_reg(data) \
                    (*((volatile unsigned int*) SD_CONFIGURE2_reg)=data)
#define get_SD_CONFIGURE2_reg \
                    (*((volatile unsigned int*) SD_CONFIGURE2_reg))
#define SD_CONFIGURE2_inst_adr                                                       "0x0001"
#define SD_CONFIGURE2_inst                                                           0x0001
#define SD_CONFIGURE2_CRC7CalculationEnable_shift                                    (7)
#define SD_CONFIGURE2_CRC7CalculationEnable_mask                                     (0x00000080)
#define SD_CONFIGURE2_CRC7CalculationEnable(data)                                    (0x00000080&((data)<<7))
#define SD_CONFIGURE2_CRC7CalculationEnable_src(data)                                ((0x00000080&(data))>>7)
#define SD_CONFIGURE2_get_CRC7CalculationEnable(data)                                ((0x00000080&(data))>>7)
#define SD_CONFIGURE2_CRC16CheckEnable_shift                                         (6)
#define SD_CONFIGURE2_CRC16CheckEnable_mask                                          (0x00000040)
#define SD_CONFIGURE2_CRC16CheckEnable(data)                                         (0x00000040&((data)<<6))
#define SD_CONFIGURE2_CRC16CheckEnable_src(data)                                     ((0x00000040&(data))>>6)
#define SD_CONFIGURE2_get_CRC16CheckEnable(data)                                     ((0x00000040&(data))>>6)
#define SD_CONFIGURE2_WaitWriteCRCStatusTimeOutEnable_shift                          (5)
#define SD_CONFIGURE2_WaitWriteCRCStatusTimeOutEnable_mask                           (0x00000020)
#define SD_CONFIGURE2_WaitWriteCRCStatusTimeOutEnable(data)                          (0x00000020&((data)<<5))
#define SD_CONFIGURE2_WaitWriteCRCStatusTimeOutEnable_src(data)                      ((0x00000020&(data))>>5)
#define SD_CONFIGURE2_get_WaitWriteCRCStatusTimeOutEnable(data)                      ((0x00000020&(data))>>5)
#define SD_CONFIGURE2_IgnoreWriteCRCErrorEnable_shift                                (4)
#define SD_CONFIGURE2_IgnoreWriteCRCErrorEnable_mask                                 (0x00000010)
#define SD_CONFIGURE2_IgnoreWriteCRCErrorEnable(data)                                (0x00000010&((data)<<4))
#define SD_CONFIGURE2_IgnoreWriteCRCErrorEnable_src(data)                            ((0x00000010&(data))>>4)
#define SD_CONFIGURE2_get_IgnoreWriteCRCErrorEnable(data)                            ((0x00000010&(data))>>4)
#define SD_CONFIGURE2_WaitBusyEndEnable_shift                                        (3)
#define SD_CONFIGURE2_WaitBusyEndEnable_mask                                         (0x00000008)
#define SD_CONFIGURE2_WaitBusyEndEnable(data)                                        (0x00000008&((data)<<3))
#define SD_CONFIGURE2_WaitBusyEndEnable_src(data)                                    ((0x00000008&(data))>>3)
#define SD_CONFIGURE2_get_WaitBusyEndEnable(data)                                    ((0x00000008&(data))>>3)
#define SD_CONFIGURE2_CRC7CheckEnable_shift                                          (2)
#define SD_CONFIGURE2_CRC7CheckEnable_mask                                           (0x00000004)
#define SD_CONFIGURE2_CRC7CheckEnable(data)                                          (0x00000004&((data)<<2))
#define SD_CONFIGURE2_CRC7CheckEnable_src(data)                                      ((0x00000004&(data))>>2)
#define SD_CONFIGURE2_get_CRC7CheckEnable(data)                                      ((0x00000004&(data))>>2)
#define SD_CONFIGURE2_ResponseTypeConfigure_shift                                    (0)
#define SD_CONFIGURE2_ResponseTypeConfigure_mask                                     (0x00000003)
#define SD_CONFIGURE2_ResponseTypeConfigure(data)                                    (0x00000003&((data)<<0))
#define SD_CONFIGURE2_ResponseTypeConfigure_src(data)                                ((0x00000003&(data))>>0)
#define SD_CONFIGURE2_get_ResponseTypeConfigure(data)                                ((0x00000003&(data))>>0)


//#define SD_CONFIGURE3                                                                0x18010808
#define SD_CONFIGURE3_reg_addr                                                       "0x18010808"
#define SD_CONFIGURE3_reg                                                            0x18010808
#define set_SD_CONFIGURE3_reg(data) \
                    (*((volatile unsigned int*) SD_CONFIGURE3_reg)=data)
#define get_SD_CONFIGURE3_reg \
                    (*((volatile unsigned int*) SD_CONFIGURE3_reg))
#define SD_CONFIGURE3_inst_adr                                                       "0x0002"
#define SD_CONFIGURE3_inst                                                           0x0002
#define SD_CONFIGURE3_Sd_dummy_reg0_shift                                            (1)
#define SD_CONFIGURE3_Sd_dummy_reg0_mask                                             (0x000000FE)
#define SD_CONFIGURE3_Sd_dummy_reg0(data)                                            (0x000000FE&((data)<<1))
#define SD_CONFIGURE3_Sd_dummy_reg0_src(data)                                        ((0x000000FE&(data))>>1)
#define SD_CONFIGURE3_get_Sd_dummy_reg0(data)                                        ((0x000000FE&(data))>>1)
#define SD_CONFIGURE3_SDCMD_shift                                                    (0)
#define SD_CONFIGURE3_SDCMD_mask                                                     (0x00000001)
#define SD_CONFIGURE3_SDCMD(data)                                                    (0x00000001&((data)<<0))
#define SD_CONFIGURE3_SDCMD_src(data)                                                ((0x00000001&(data))>>0)
#define SD_CONFIGURE3_get_SDCMD(data)                                                ((0x00000001&(data))>>0)


//#define SD_STATUS                                                                    0x1801080C
#define SD_STATUS_reg_addr                                                           "0x1801080C"
#define SD_STATUS_reg                                                                0x1801080C
#define set_SD_STATUS_reg(data) \
                    (*((volatile unsigned int*) SD_STATUS_reg)=data)
#define get_SD_STATUS_reg \
                    (*((volatile unsigned int*) SD_STATUS_reg))
#define SD_STATUS_inst_adr                                                           "0x0003"
#define SD_STATUS_inst                                                               0x0003
#define SD_STATUS_CRC7Error_shift                                                    (7)
#define SD_STATUS_CRC7Error_mask                                                     (0x00000080)
#define SD_STATUS_CRC7Error(data)                                                    (0x00000080&((data)<<7))
#define SD_STATUS_CRC7Error_src(data)                                                ((0x00000080&(data))>>7)
#define SD_STATUS_get_CRC7Error(data)                                                ((0x00000080&(data))>>7)
#define SD_STATUS_CRC16Error_shift                                                   (6)
#define SD_STATUS_CRC16Error_mask                                                    (0x00000040)
#define SD_STATUS_CRC16Error(data)                                                   (0x00000040&((data)<<6))
#define SD_STATUS_CRC16Error_src(data)                                               ((0x00000040&(data))>>6)
#define SD_STATUS_get_CRC16Error(data)                                               ((0x00000040&(data))>>6)
#define SD_STATUS_WriteCRCError_shift                                                (5)
#define SD_STATUS_WriteCRCError_mask                                                 (0x00000020)
#define SD_STATUS_WriteCRCError(data)                                                (0x00000020&((data)<<5))
#define SD_STATUS_WriteCRCError_src(data)                                            ((0x00000020&(data))>>5)
#define SD_STATUS_get_WriteCRCError(data)                                            ((0x00000020&(data))>>5)
#define SD_STATUS_StatusOfWriteCRC_shift                                             (2)
#define SD_STATUS_StatusOfWriteCRC_mask                                              (0x0000001C)
#define SD_STATUS_StatusOfWriteCRC(data)                                             (0x0000001C&((data)<<2))
#define SD_STATUS_StatusOfWriteCRC_src(data)                                         ((0x0000001C&(data))>>2)
#define SD_STATUS_get_StatusOfWriteCRC(data)                                         ((0x0000001C&(data))>>2)
#define SD_STATUS_GetWriteCRCStatusTime_outError_shift                               (1)
#define SD_STATUS_GetWriteCRCStatusTime_outError_mask                                (0x00000002)
#define SD_STATUS_GetWriteCRCStatusTime_outError(data)                               (0x00000002&((data)<<1))
#define SD_STATUS_GetWriteCRCStatusTime_outError_src(data)                           ((0x00000002&(data))>>1)
#define SD_STATUS_get_GetWriteCRCStatusTime_outError(data)                           ((0x00000002&(data))>>1)
#define SD_STATUS_SDTuningPatternCompareError_shift                                  (0)
#define SD_STATUS_SDTuningPatternCompareError_mask                                   (0x00000001)
#define SD_STATUS_SDTuningPatternCompareError(data)                                  (0x00000001&((data)<<0))
#define SD_STATUS_SDTuningPatternCompareError_src(data)                              ((0x00000001&(data))>>0)
#define SD_STATUS_get_SDTuningPatternCompareError(data)                              ((0x00000001&(data))>>0)


//#define SD_STATUS2                                                                   0x18010810
#define SD_STATUS2_reg_addr                                                          "0x18010810"
#define SD_STATUS2_reg                                                               0x18010810
#define set_SD_STATUS2_reg(data) \
                    (*((volatile unsigned int*) SD_STATUS2_reg)=data)
#define get_SD_STATUS2_reg \
                    (*((volatile unsigned int*) SD_STATUS2_reg))
#define SD_STATUS2_inst_adr                                                          "0x0004"
#define SD_STATUS2_inst                                                              0x0004
#define SD_STATUS2_SDCMDResponseTimeoutError_shift                                   (0)
#define SD_STATUS2_SDCMDResponseTimeoutError_mask                                    (0x00000001)
#define SD_STATUS2_SDCMDResponseTimeoutError(data)                                   (0x00000001&((data)<<0))
#define SD_STATUS2_SDCMDResponseTimeoutError_src(data)                               ((0x00000001&(data))>>0)
#define SD_STATUS2_get_SDCMDResponseTimeoutError(data)                               ((0x00000001&(data))>>0)


//#define SD_BUS_STATUS                                                                0x18010814
#define SD_BUS_STATUS_reg_addr                                                       "0x18010814"
#define SD_BUS_STATUS_reg                                                            0x18010814
#define set_SD_BUS_STATUS_reg(data) \
                    (*((volatile unsigned int*) SD_BUS_STATUS_reg)=data)
#define get_SD_BUS_STATUS_reg \
                    (*((volatile unsigned int*) SD_BUS_STATUS_reg))
#define SD_BUS_STATUS_inst_adr                                                       "0x0005"
#define SD_BUS_STATUS_inst                                                           0x0005
#define SD_BUS_STATUS_SD_CLKToggleEnable_shift                                       (7)
#define SD_BUS_STATUS_SD_CLKToggleEnable_mask                                        (0x00000080)
#define SD_BUS_STATUS_SD_CLKToggleEnable(data)                                       (0x00000080&((data)<<7))
#define SD_BUS_STATUS_SD_CLKToggleEnable_src(data)                                   ((0x00000080&(data))>>7)
#define SD_BUS_STATUS_get_SD_CLKToggleEnable(data)                                   ((0x00000080&(data))>>7)
#define SD_BUS_STATUS_StopSD_CLKtogglingwhennocmdordatatransfer_shift                (6)
#define SD_BUS_STATUS_StopSD_CLKtogglingwhennocmdordatatransfer_mask                 (0x00000040)
#define SD_BUS_STATUS_StopSD_CLKtogglingwhennocmdordatatransfer(data)                (0x00000040&((data)<<6))
#define SD_BUS_STATUS_StopSD_CLKtogglingwhennocmdordatatransfer_src(data)            ((0x00000040&(data))>>6)
#define SD_BUS_STATUS_get_StopSD_CLKtogglingwhennocmdordatatransfer(data)            ((0x00000040&(data))>>6)
#define SD_BUS_STATUS_DAT3DAT0_shift                                                 (1)
#define SD_BUS_STATUS_DAT3DAT0_mask                                                  (0x0000001E)
#define SD_BUS_STATUS_DAT3DAT0(data)                                                 (0x0000001E&((data)<<1))
#define SD_BUS_STATUS_DAT3DAT0_src(data)                                             ((0x0000001E&(data))>>1)
#define SD_BUS_STATUS_get_DAT3DAT0(data)                                             ((0x0000001E&(data))>>1)
#define SD_BUS_STATUS_CMD_shift                                                      (0)
#define SD_BUS_STATUS_CMD_mask                                                       (0x00000001)
#define SD_BUS_STATUS_CMD(data)                                                      (0x00000001&((data)<<0))
#define SD_BUS_STATUS_CMD_src(data)                                                  ((0x00000001&(data))>>0)
#define SD_BUS_STATUS_get_CMD(data)                                                  ((0x00000001&(data))>>0)


//#define SD_CMD_CODE                                                                  0x18010818
#define SD_CMD_CODE_reg_addr                                                         "0x18010818"
#define SD_CMD_CODE_reg                                                              0x18010818
#define set_SD_CMD_CODE_reg(data) \
                    (*((volatile unsigned int*) SD_CMD_CODE_reg)=data)
#define get_SD_CMD_CODE_reg \
                    (*((volatile unsigned int*) SD_CMD_CODE_reg))
#define SD_CMD_CODE_inst_adr                                                         "0x0006"
#define SD_CMD_CODE_inst                                                             0x0006
#define SD_CMD_CODE_sd_dummy_reg1_shift                                              (0)
#define SD_CMD_CODE_sd_dummy_reg1_mask                                               (0x000000FF)
#define SD_CMD_CODE_sd_dummy_reg1(data)                                              (0x000000FF&((data)<<0))
#define SD_CMD_CODE_sd_dummy_reg1_src(data)                                          ((0x000000FF&(data))>>0)
#define SD_CMD_CODE_get_sd_dummy_reg1(data)                                          ((0x000000FF&(data))>>0)


//#define SD_SAMPLE_POINT_CTL                                                          0x1801081C
#define SD_SAMPLE_POINT_CTL_reg_addr                                                 "0x1801081C"
#define SD_SAMPLE_POINT_CTL_reg                                                      0x1801081C
#define set_SD_SAMPLE_POINT_CTL_reg(data) \
                    (*((volatile unsigned int*) SD_SAMPLE_POINT_CTL_reg)=data)
#define get_SD_SAMPLE_POINT_CTL_reg \
                    (*((volatile unsigned int*) SD_SAMPLE_POINT_CTL_reg))
#define SD_SAMPLE_POINT_CTL_inst_adr                                                 "0x0007"
#define SD_SAMPLE_POINT_CTL_inst                                                     0x0007
#define SD_SAMPLE_POINT_CTL_SamplePointTypeforDDRDAT_shift                           (7)
#define SD_SAMPLE_POINT_CTL_SamplePointTypeforDDRDAT_mask                            (0x00000080)
#define SD_SAMPLE_POINT_CTL_SamplePointTypeforDDRDAT(data)                           (0x00000080&((data)<<7))
#define SD_SAMPLE_POINT_CTL_SamplePointTypeforDDRDAT_src(data)                       ((0x00000080&(data))>>7)
#define SD_SAMPLE_POINT_CTL_get_SamplePointTypeforDDRDAT(data)                       ((0x00000080&(data))>>7)
#define SD_SAMPLE_POINT_CTL_SamplePointSelectionforDDRDAT_shift                      (6)
#define SD_SAMPLE_POINT_CTL_SamplePointSelectionforDDRDAT_mask                       (0x00000040)
#define SD_SAMPLE_POINT_CTL_SamplePointSelectionforDDRDAT(data)                      (0x00000040&((data)<<6))
#define SD_SAMPLE_POINT_CTL_SamplePointSelectionforDDRDAT_src(data)                  ((0x00000040&(data))>>6)
#define SD_SAMPLE_POINT_CTL_get_SamplePointSelectionforDDRDAT(data)                  ((0x00000040&(data))>>6)
#define SD_SAMPLE_POINT_CTL_SamplePointTypeforDDRCMD_shift                           (5)
#define SD_SAMPLE_POINT_CTL_SamplePointTypeforDDRCMD_mask                            (0x00000020)
#define SD_SAMPLE_POINT_CTL_SamplePointTypeforDDRCMD(data)                           (0x00000020&((data)<<5))
#define SD_SAMPLE_POINT_CTL_SamplePointTypeforDDRCMD_src(data)                       ((0x00000020&(data))>>5)
#define SD_SAMPLE_POINT_CTL_get_SamplePointTypeforDDRCMD(data)                       ((0x00000020&(data))>>5)
#define SD_SAMPLE_POINT_CTL_SamplePointSelectionforDDRCMD_shift                      (4)
#define SD_SAMPLE_POINT_CTL_SamplePointSelectionforDDRCMD_mask                       (0x00000010)
#define SD_SAMPLE_POINT_CTL_SamplePointSelectionforDDRCMD(data)                      (0x00000010&((data)<<4))
#define SD_SAMPLE_POINT_CTL_SamplePointSelectionforDDRCMD_src(data)                  ((0x00000010&(data))>>4)
#define SD_SAMPLE_POINT_CTL_get_SamplePointSelectionforDDRCMD(data)                  ((0x00000010&(data))>>4)
#define SD_SAMPLE_POINT_CTL_SamplePointSelectionforSD20CMDorDATA_shift               (3)
#define SD_SAMPLE_POINT_CTL_SamplePointSelectionforSD20CMDorDATA_mask                (0x00000008)
#define SD_SAMPLE_POINT_CTL_SamplePointSelectionforSD20CMDorDATA(data)               (0x00000008&((data)<<3))
#define SD_SAMPLE_POINT_CTL_SamplePointSelectionforSD20CMDorDATA_src(data)           ((0x00000008&(data))>>3)
#define SD_SAMPLE_POINT_CTL_get_SamplePointSelectionforSD20CMDorDATA(data)           ((0x00000008&(data))>>3)


//#define SD_PUSH_POINT_CTL                                                            0x18010820
#define SD_PUSH_POINT_CTL_reg_addr                                                   "0x18010820"
#define SD_PUSH_POINT_CTL_reg                                                        0x18010820
#define set_SD_PUSH_POINT_CTL_reg(data) \
                    (*((volatile unsigned int*) SD_PUSH_POINT_CTL_reg)=data)
#define get_SD_PUSH_POINT_CTL_reg \
                    (*((volatile unsigned int*) SD_PUSH_POINT_CTL_reg))
#define SD_PUSH_POINT_CTL_inst_adr                                                   "0x0008"
#define SD_PUSH_POINT_CTL_inst                                                       0x0008
#define SD_PUSH_POINT_CTL_PushPointSelectionTypeforDDRCMDorDAT_shift                 (7)
#define SD_PUSH_POINT_CTL_PushPointSelectionTypeforDDRCMDorDAT_mask                  (0x00000080)
#define SD_PUSH_POINT_CTL_PushPointSelectionTypeforDDRCMDorDAT(data)                 (0x00000080&((data)<<7))
#define SD_PUSH_POINT_CTL_PushPointSelectionTypeforDDRCMDorDAT_src(data)             ((0x00000080&(data))>>7)
#define SD_PUSH_POINT_CTL_get_PushPointSelectionTypeforDDRCMDorDAT(data)             ((0x00000080&(data))>>7)
#define SD_PUSH_POINT_CTL_PushPointSelectionforDDRmodeDAT_shift                      (6)
#define SD_PUSH_POINT_CTL_PushPointSelectionforDDRmodeDAT_mask                       (0x00000040)
#define SD_PUSH_POINT_CTL_PushPointSelectionforDDRmodeDAT(data)                      (0x00000040&((data)<<6))
#define SD_PUSH_POINT_CTL_PushPointSelectionforDDRmodeDAT_src(data)                  ((0x00000040&(data))>>6)
#define SD_PUSH_POINT_CTL_get_PushPointSelectionforDDRmodeDAT(data)                  ((0x00000040&(data))>>6)
#define SD_PUSH_POINT_CTL_PushPointSelectionforDDRmodeCMD_shift                      (5)
#define SD_PUSH_POINT_CTL_PushPointSelectionforDDRmodeCMD_mask                       (0x00000020)
#define SD_PUSH_POINT_CTL_PushPointSelectionforDDRmodeCMD(data)                      (0x00000020&((data)<<5))
#define SD_PUSH_POINT_CTL_PushPointSelectionforDDRmodeCMD_src(data)                  ((0x00000020&(data))>>5)
#define SD_PUSH_POINT_CTL_get_PushPointSelectionforDDRmodeCMD(data)                  ((0x00000020&(data))>>5)
#define SD_PUSH_POINT_CTL_PushPointSelectionforSD20modeCMDorDATA_shift               (4)
#define SD_PUSH_POINT_CTL_PushPointSelectionforSD20modeCMDorDATA_mask                (0x00000010)
#define SD_PUSH_POINT_CTL_PushPointSelectionforSD20modeCMDorDATA(data)               (0x00000010&((data)<<4))
#define SD_PUSH_POINT_CTL_PushPointSelectionforSD20modeCMDorDATA_src(data)           ((0x00000010&(data))>>4)
#define SD_PUSH_POINT_CTL_get_PushPointSelectionforSD20modeCMDorDATA(data)           ((0x00000010&(data))>>4)
#define SD_PUSH_POINT_CTL_ChoosesamplingedgeofPCLKtosampleDPCLK_shift                (3)
#define SD_PUSH_POINT_CTL_ChoosesamplingedgeofPCLKtosampleDPCLK_mask                 (0x00000008)
#define SD_PUSH_POINT_CTL_ChoosesamplingedgeofPCLKtosampleDPCLK(data)                (0x00000008&((data)<<3))
#define SD_PUSH_POINT_CTL_ChoosesamplingedgeofPCLKtosampleDPCLK_src(data)            ((0x00000008&(data))>>3)
#define SD_PUSH_POINT_CTL_get_ChoosesamplingedgeofPCLKtosampleDPCLK(data)            ((0x00000008&(data))>>3)
#define SD_PUSH_POINT_CTL_chooseSDCLKPolaritysolutionforDDRmode_shift                (1)
#define SD_PUSH_POINT_CTL_chooseSDCLKPolaritysolutionforDDRmode_mask                 (0x00000006)
#define SD_PUSH_POINT_CTL_chooseSDCLKPolaritysolutionforDDRmode(data)                (0x00000006&((data)<<1))
#define SD_PUSH_POINT_CTL_chooseSDCLKPolaritysolutionforDDRmode_src(data)            ((0x00000006&(data))>>1)
#define SD_PUSH_POINT_CTL_get_chooseSDCLKPolaritysolutionforDDRmode(data)            ((0x00000006&(data))>>1)
#define SD_PUSH_POINT_CTL_SDCLKPolaritySwap_shift                                    (0)
#define SD_PUSH_POINT_CTL_SDCLKPolaritySwap_mask                                     (0x00000001)
#define SD_PUSH_POINT_CTL_SDCLKPolaritySwap(data)                                    (0x00000001&((data)<<0))
#define SD_PUSH_POINT_CTL_SDCLKPolaritySwap_src(data)                                ((0x00000001&(data))>>0)
#define SD_PUSH_POINT_CTL_get_SDCLKPolaritySwap(data)                                ((0x00000001&(data))>>0)


//#define SD_CMD0                                                                      0x18010824
#define SD_CMD0_reg_addr                                                             "0x18010824"
#define SD_CMD0_reg                                                                  0x18010824
#define set_SD_CMD0_reg(data) \
                    (*((volatile unsigned int*) SD_CMD0_reg)=data)
#define get_SD_CMD0_reg \
                    (*((volatile unsigned int*) SD_CMD0_reg))
#define SD_CMD0_inst_adr                                                             "0x0009"
#define SD_CMD0_inst                                                                 0x0009
#define SD_CMD0_Command70orResponseData70_shift                                      (0)
#define SD_CMD0_Command70orResponseData70_mask                                       (0x000000FF)
#define SD_CMD0_Command70orResponseData70(data)                                      (0x000000FF&((data)<<0))
#define SD_CMD0_Command70orResponseData70_src(data)                                  ((0x000000FF&(data))>>0)
#define SD_CMD0_get_Command70orResponseData70(data)                                  ((0x000000FF&(data))>>0)


//#define SD_CMD1                                                                      0x18010828
#define SD_CMD1_reg_addr                                                             "0x18010828"
#define SD_CMD1_reg                                                                  0x18010828
#define set_SD_CMD1_reg(data) \
                    (*((volatile unsigned int*) SD_CMD1_reg)=data)
#define get_SD_CMD1_reg \
                    (*((volatile unsigned int*) SD_CMD1_reg))
#define SD_CMD1_inst_adr                                                             "0x000A"
#define SD_CMD1_inst                                                                 0x000A
#define SD_CMD1_Command158orResponseData158_shift                                    (0)
#define SD_CMD1_Command158orResponseData158_mask                                     (0x000000FF)
#define SD_CMD1_Command158orResponseData158(data)                                    (0x000000FF&((data)<<0))
#define SD_CMD1_Command158orResponseData158_src(data)                                ((0x000000FF&(data))>>0)
#define SD_CMD1_get_Command158orResponseData158(data)                                ((0x000000FF&(data))>>0)


//#define SD_CMD2                                                                      0x1801082C
#define SD_CMD2_reg_addr                                                             "0x1801082C"
#define SD_CMD2_reg                                                                  0x1801082C
#define set_SD_CMD2_reg(data)   (*((volatile unsigned int*) SD_CMD2_reg)=data)
#define get_SD_CMD2_reg   (*((volatile unsigned int*) SD_CMD2_reg))
#define SD_CMD2_inst_adr                                                             "0x000B"
#define SD_CMD2_inst                                                                 0x000B
#define SD_CMD2_Command2316orResponseData2316_shift                                  (0)
#define SD_CMD2_Command2316orResponseData2316_mask                                   (0x000000FF)
#define SD_CMD2_Command2316orResponseData2316(data)                                  (0x000000FF&((data)<<0))
#define SD_CMD2_Command2316orResponseData2316_src(data)                              ((0x000000FF&(data))>>0)
#define SD_CMD2_get_Command2316orResponseData2316(data)                              ((0x000000FF&(data))>>0)


//#define SD_CMD3                                                                      0x18010830
#define SD_CMD3_reg_addr                                                             "0x18010830"
#define SD_CMD3_reg                                                                  0x18010830
#define set_SD_CMD3_reg(data)   (*((volatile unsigned int*) SD_CMD3_reg)=data)
#define get_SD_CMD3_reg   (*((volatile unsigned int*) SD_CMD3_reg))
#define SD_CMD3_inst_adr                                                             "0x000C"
#define SD_CMD3_inst                                                                 0x000C
#define SD_CMD3_Command3124orResponseData3124_shift                                  (0)
#define SD_CMD3_Command3124orResponseData3124_mask                                   (0x000000FF)
#define SD_CMD3_Command3124orResponseData3124(data)                                  (0x000000FF&((data)<<0))
#define SD_CMD3_Command3124orResponseData3124_src(data)                              ((0x000000FF&(data))>>0)
#define SD_CMD3_get_Command3124orResponseData3124(data)                              ((0x000000FF&(data))>>0)


//#define SD_CMD4                                                                      0x18010834
#define SD_CMD4_reg_addr                                                             "0x18010834"
#define SD_CMD4_reg                                                                  0x18010834
#define set_SD_CMD4_reg(data)   (*((volatile unsigned int*) SD_CMD4_reg)=data)
#define get_SD_CMD4_reg   (*((volatile unsigned int*) SD_CMD4_reg))
#define SD_CMD4_inst_adr                                                             "0x000D"
#define SD_CMD4_inst                                                                 0x000D
#define SD_CMD4_Command3932orResponseData3932_shift                                  (0)
#define SD_CMD4_Command3932orResponseData3932_mask                                   (0x000000FF)
#define SD_CMD4_Command3932orResponseData3932(data)                                  (0x000000FF&((data)<<0))
#define SD_CMD4_Command3932orResponseData3932_src(data)                              ((0x000000FF&(data))>>0)
#define SD_CMD4_get_Command3932orResponseData3932(data)                              ((0x000000FF&(data))>>0)


//#define SD_CMD5                                                                      0x18010838
#define SD_CMD5_reg_addr                                                             "0x18010838"
#define SD_CMD5_reg                                                                  0x18010838
#define set_SD_CMD5_reg(data)   (*((volatile unsigned int*) SD_CMD5_reg)=data)
#define get_SD_CMD5_reg   (*((volatile unsigned int*) SD_CMD5_reg))
#define SD_CMD5_inst_adr                                                             "0x000E"
#define SD_CMD5_inst                                                                 0x000E
#define SD_CMD5_Command4740orResponseData4740_shift                                  (0)
#define SD_CMD5_Command4740orResponseData4740_mask                                   (0x000000FF)
#define SD_CMD5_Command4740orResponseData4740(data)                                  (0x000000FF&((data)<<0))
#define SD_CMD5_Command4740orResponseData4740_src(data)                              ((0x000000FF&(data))>>0)
#define SD_CMD5_get_Command4740orResponseData4740(data)                              ((0x000000FF&(data))>>0)


//#define SD_BYTE_CNT_L                                                                0x1801083C
#define SD_BYTE_CNT_L_reg_addr                                                       "0x1801083C"
#define SD_BYTE_CNT_L_reg                                                            0x1801083C
#define set_SD_BYTE_CNT_L_reg(data)   (*((volatile unsigned int*) SD_BYTE_CNT_L_reg)=data)
#define get_SD_BYTE_CNT_L_reg   (*((volatile unsigned int*) SD_BYTE_CNT_L_reg))
#define SD_BYTE_CNT_L_inst_adr                                                       "0x000F"
#define SD_BYTE_CNT_L_inst                                                           0x000F
#define SD_BYTE_CNT_L_ByteCount70_shift                                              (0)
#define SD_BYTE_CNT_L_ByteCount70_mask                                               (0x000000FF)
#define SD_BYTE_CNT_L_ByteCount70(data)                                              (0x000000FF&((data)<<0))
#define SD_BYTE_CNT_L_ByteCount70_src(data)                                          ((0x000000FF&(data))>>0)
#define SD_BYTE_CNT_L_get_ByteCount70(data)                                          ((0x000000FF&(data))>>0)


//#define SD_BYTE_CNT_H                                                                0x18010840
#define SD_BYTE_CNT_H_reg_addr                                                       "0x18010840"
#define SD_BYTE_CNT_H_reg                                                            0x18010840
#define set_SD_BYTE_CNT_H_reg(data)   (*((volatile unsigned int*) SD_BYTE_CNT_H_reg)=data)
#define get_SD_BYTE_CNT_H_reg   (*((volatile unsigned int*) SD_BYTE_CNT_H_reg))
#define SD_BYTE_CNT_H_inst_adr                                                       "0x0010"
#define SD_BYTE_CNT_H_inst                                                           0x0010
#define SD_BYTE_CNT_H_ByteCount108_shift                                             (0)
#define SD_BYTE_CNT_H_ByteCount108_mask                                              (0x00000007)
#define SD_BYTE_CNT_H_ByteCount108(data)                                             (0x00000007&((data)<<0))
#define SD_BYTE_CNT_H_ByteCount108_src(data)                                         ((0x00000007&(data))>>0)
#define SD_BYTE_CNT_H_get_ByteCount108(data)                                         ((0x00000007&(data))>>0)


//#define SD_BLOCK_CNT_L                                                               0x18010844
#define SD_BLOCK_CNT_L_reg_addr                                                      "0x18010844"
#define SD_BLOCK_CNT_L_reg                                                           0x18010844
#define set_SD_BLOCK_CNT_L_reg(data)   (*((volatile unsigned int*) SD_BLOCK_CNT_L_reg)=data)
#define get_SD_BLOCK_CNT_L_reg   (*((volatile unsigned int*) SD_BLOCK_CNT_L_reg))
#define SD_BLOCK_CNT_L_inst_adr                                                      "0x0011"
#define SD_BLOCK_CNT_L_inst                                                          0x0011
#define SD_BLOCK_CNT_L_BlockCount70_shift                                            (0)
#define SD_BLOCK_CNT_L_BlockCount70_mask                                             (0x000000FF)
#define SD_BLOCK_CNT_L_BlockCount70(data)                                            (0x000000FF&((data)<<0))
#define SD_BLOCK_CNT_L_BlockCount70_src(data)                                        ((0x000000FF&(data))>>0)
#define SD_BLOCK_CNT_L_get_BlockCount70(data)                                        ((0x000000FF&(data))>>0)


//#define SD_BLOCK_CNT_H                                                               0x18010848
#define SD_BLOCK_CNT_H_reg_addr                                                      "0x18010848"
#define SD_BLOCK_CNT_H_reg                                                           0x18010848
#define set_SD_BLOCK_CNT_H_reg(data)   (*((volatile unsigned int*) SD_BLOCK_CNT_H_reg)=data)
#define get_SD_BLOCK_CNT_H_reg   (*((volatile unsigned int*) SD_BLOCK_CNT_H_reg))
#define SD_BLOCK_CNT_H_inst_adr                                                      "0x0012"
#define SD_BLOCK_CNT_H_inst                                                          0x0012
#define SD_BLOCK_CNT_H_BlockCount148_shift                                           (0)
#define SD_BLOCK_CNT_H_BlockCount148_mask                                            (0x0000007F)
#define SD_BLOCK_CNT_H_BlockCount148(data)                                           (0x0000007F&((data)<<0))
#define SD_BLOCK_CNT_H_BlockCount148_src(data)                                       ((0x0000007F&(data))>>0)
#define SD_BLOCK_CNT_H_get_BlockCount148(data)                                       ((0x0000007F&(data))>>0)


//#define SD_TRANSFER                                                                  0x1801084C
#define SD_TRANSFER_reg_addr                                                         "0x1801084C"
#define SD_TRANSFER_reg                                                              0x1801084C
#define set_SD_TRANSFER_reg(data)   (*((volatile unsigned int*) SD_TRANSFER_reg)=data)
#define get_SD_TRANSFER_reg   (*((volatile unsigned int*) SD_TRANSFER_reg))
#define SD_TRANSFER_inst_adr                                                         "0x0013"
#define SD_TRANSFER_inst                                                             0x0013
#define SD_TRANSFER_Start_shift                                                      (7)
#define SD_TRANSFER_Start_mask                                                       (0x00000080)
#define SD_TRANSFER_Start(data)                                                      (0x00000080&((data)<<7))
#define SD_TRANSFER_Start_src(data)                                                  ((0x00000080&(data))>>7)
#define SD_TRANSFER_get_Start(data)                                                  ((0x00000080&(data))>>7)
#define SD_TRANSFER_End_shift                                                        (6)
#define SD_TRANSFER_End_mask                                                         (0x00000040)
#define SD_TRANSFER_End(data)                                                        (0x00000040&((data)<<6))
#define SD_TRANSFER_End_src(data)                                                    ((0x00000040&(data))>>6)
#define SD_TRANSFER_get_End(data)                                                    ((0x00000040&(data))>>6)
#define SD_TRANSFER_StatusofSDcardmodulestatemachine_shift                           (5)
#define SD_TRANSFER_StatusofSDcardmodulestatemachine_mask                            (0x00000020)
#define SD_TRANSFER_StatusofSDcardmodulestatemachine(data)                           (0x00000020&((data)<<5))
#define SD_TRANSFER_StatusofSDcardmodulestatemachine_src(data)                       ((0x00000020&(data))>>5)
#define SD_TRANSFER_get_StatusofSDcardmodulestatemachine(data)                       ((0x00000020&(data))>>5)
#define SD_TRANSFER_ErrorBit_shift                                                   (4)
#define SD_TRANSFER_ErrorBit_mask                                                    (0x00000010)
#define SD_TRANSFER_ErrorBit(data)                                                   (0x00000010&((data)<<4))
#define SD_TRANSFER_ErrorBit_src(data)                                               ((0x00000010&(data))>>4)
#define SD_TRANSFER_get_ErrorBit(data)                                               ((0x00000010&(data))>>4)
#define SD_TRANSFER_CommandCode_shift                                                (0)
#define SD_TRANSFER_CommandCode_mask                                                 (0x0000000F)
#define SD_TRANSFER_CommandCode(data)                                                (0x0000000F&((data)<<0))
#define SD_TRANSFER_CommandCode_src(data)                                            ((0x0000000F&(data))>>0)
#define SD_TRANSFER_get_CommandCode(data)                                            ((0x0000000F&(data))>>0)


//#define SD_DDR_CHK_START                                                             0x18010850
#define SD_DDR_CHK_START_reg_addr                                                    "0x18010850"
#define SD_DDR_CHK_START_reg                                                         0x18010850
#define set_SD_DDR_CHK_START_reg(data)   (*((volatile unsigned int*) SD_DDR_CHK_START_reg)=data)
#define get_SD_DDR_CHK_START_reg   (*((volatile unsigned int*) SD_DDR_CHK_START_reg))
#define SD_DDR_CHK_START_inst_adr                                                    "0x0014"
#define SD_DDR_CHK_START_inst                                                        0x0014
#define SD_DDR_CHK_START_Detect_ddr_cmd_shift                                        (7)
#define SD_DDR_CHK_START_Detect_ddr_cmd_mask                                         (0x00000080)
#define SD_DDR_CHK_START_Detect_ddr_cmd(data)                                        (0x00000080&((data)<<7))
#define SD_DDR_CHK_START_Detect_ddr_cmd_src(data)                                    ((0x00000080&(data))>>7)
#define SD_DDR_CHK_START_get_Detect_ddr_cmd(data)                                    ((0x00000080&(data))>>7)
#define SD_DDR_CHK_START_Forcecmd1_shift                                             (6)
#define SD_DDR_CHK_START_Forcecmd1_mask                                              (0x00000040)
#define SD_DDR_CHK_START_Forcecmd1(data)                                             (0x00000040&((data)<<6))
#define SD_DDR_CHK_START_Forcecmd1_src(data)                                         ((0x00000040&(data))>>6)
#define SD_DDR_CHK_START_get_Forcecmd1(data)                                         ((0x00000040&(data))>>6)
#define SD_DDR_CHK_START_Forcecmd0_shift                                             (5)
#define SD_DDR_CHK_START_Forcecmd0_mask                                              (0x00000020)
#define SD_DDR_CHK_START_Forcecmd0(data)                                             (0x00000020&((data)<<5))
#define SD_DDR_CHK_START_Forcecmd0_src(data)                                         ((0x00000020&(data))>>5)
#define SD_DDR_CHK_START_get_Forcecmd0(data)                                         ((0x00000020&(data))>>5)
#define SD_DDR_CHK_START_CMDStartbit_shift                                           (4)
#define SD_DDR_CHK_START_CMDStartbit_mask                                            (0x00000010)
#define SD_DDR_CHK_START_CMDStartbit(data)                                           (0x00000010&((data)<<4))
#define SD_DDR_CHK_START_CMDStartbit_src(data)                                       ((0x00000010&(data))>>4)
#define SD_DDR_CHK_START_get_CMDStartbit(data)                                       ((0x00000010&(data))>>4)
#define SD_DDR_CHK_START_Detect_ddr_data__shift                                      (3)
#define SD_DDR_CHK_START_Detect_ddr_data__mask                                       (0x00000008)
#define SD_DDR_CHK_START_Detect_ddr_data_(data)                                      (0x00000008&((data)<<3))
#define SD_DDR_CHK_START_Detect_ddr_data__src(data)                                  ((0x00000008&(data))>>3)
#define SD_DDR_CHK_START_get_Detect_ddr_data_(data)                                  ((0x00000008&(data))>>3)
#define SD_DDR_CHK_START_Forcedata1_shift                                            (2)
#define SD_DDR_CHK_START_Forcedata1_mask                                             (0x00000004)
#define SD_DDR_CHK_START_Forcedata1(data)                                            (0x00000004&((data)<<2))
#define SD_DDR_CHK_START_Forcedata1_src(data)                                        ((0x00000004&(data))>>2)
#define SD_DDR_CHK_START_get_Forcedata1(data)                                        ((0x00000004&(data))>>2)
#define SD_DDR_CHK_START_Forcedata0_shift                                            (1)
#define SD_DDR_CHK_START_Forcedata0_mask                                             (0x00000002)
#define SD_DDR_CHK_START_Forcedata0(data)                                            (0x00000002&((data)<<1))
#define SD_DDR_CHK_START_Forcedata0_src(data)                                        ((0x00000002&(data))>>1)
#define SD_DDR_CHK_START_get_Forcedata0(data)                                        ((0x00000002&(data))>>1)
#define SD_DDR_CHK_START_DataStartbit_shift                                          (0)
#define SD_DDR_CHK_START_DataStartbit_mask                                           (0x00000001)
#define SD_DDR_CHK_START_DataStartbit(data)                                          (0x00000001&((data)<<0))
#define SD_DDR_CHK_START_DataStartbit_src(data)                                      ((0x00000001&(data))>>0)
#define SD_DDR_CHK_START_get_DataStartbit(data)                                      ((0x00000001&(data))>>0)


//#define SD_CMD_STATE                                                                 0x18010854
#define SD_CMD_STATE_reg_addr                                                        "0x18010854"
#define SD_CMD_STATE_reg                                                             0x18010854
#define set_SD_CMD_STATE_reg(data)   (*((volatile unsigned int*) SD_CMD_STATE_reg)=data)
#define get_SD_CMD_STATE_reg   (*((volatile unsigned int*) SD_CMD_STATE_reg))
#define SD_CMD_STATE_inst_adr                                                        "0x0015"
#define SD_CMD_STATE_inst                                                            0x0015
#define SD_CMD_STATE_CMDStateMachineidle_shift                                       (7)
#define SD_CMD_STATE_CMDStateMachineidle_mask                                        (0x00000080)
#define SD_CMD_STATE_CMDStateMachineidle(data)                                       (0x00000080&((data)<<7))
#define SD_CMD_STATE_CMDStateMachineidle_src(data)                                   ((0x00000080&(data))>>7)
#define SD_CMD_STATE_get_CMDStateMachineidle(data)                                   ((0x00000080&(data))>>7)
#define SD_CMD_STATE_CMDStateMachine_shift                                           (0)
#define SD_CMD_STATE_CMDStateMachine_mask                                            (0x0000000F)
#define SD_CMD_STATE_CMDStateMachine(data)                                           (0x0000000F&((data)<<0))
#define SD_CMD_STATE_CMDStateMachine_src(data)                                       ((0x0000000F&(data))>>0)
#define SD_CMD_STATE_get_CMDStateMachine(data)                                       ((0x0000000F&(data))>>0)


//#define SD_DATA_STATE                                                                0x18010858
#define SD_DATA_STATE_reg_addr                                                       "0x18010858"
#define SD_DATA_STATE_reg                                                            0x18010858
#define set_SD_DATA_STATE_reg(data)   (*((volatile unsigned int*) SD_DATA_STATE_reg)=data)
#define get_SD_DATA_STATE_reg   (*((volatile unsigned int*) SD_DATA_STATE_reg))
#define SD_DATA_STATE_inst_adr                                                       "0x0016"
#define SD_DATA_STATE_inst                                                           0x0016
#define SD_DATA_STATE_DATAStateMachineidle_shift                                     (7)
#define SD_DATA_STATE_DATAStateMachineidle_mask                                      (0x00000080)
#define SD_DATA_STATE_DATAStateMachineidle(data)                                     (0x00000080&((data)<<7))
#define SD_DATA_STATE_DATAStateMachineidle_src(data)                                 ((0x00000080&(data))>>7)
#define SD_DATA_STATE_get_DATAStateMachineidle(data)                                 ((0x00000080&(data))>>7)
#define SD_DATA_STATE_DATAStateMachine_shift                                         (0)
#define SD_DATA_STATE_DATAStateMachine_mask                                          (0x0000000F)
#define SD_DATA_STATE_DATAStateMachine(data)                                         (0x0000000F&((data)<<0))
#define SD_DATA_STATE_DATAStateMachine_src(data)                                     ((0x0000000F&(data))>>0)
#define SD_DATA_STATE_get_DATAStateMachine(data)                                     ((0x0000000F&(data))>>0)


//#define SD_BUS_TA_TIME                                                               0x1801085C
#define SD_BUS_TA_TIME_reg_addr                                                      "0x1801085C"
#define SD_BUS_TA_TIME_reg                                                           0x1801085C
#define set_SD_BUS_TA_TIME_reg(data)   (*((volatile unsigned int*) SD_BUS_TA_TIME_reg)=data)
#define get_SD_BUS_TA_TIME_reg   (*((volatile unsigned int*) SD_BUS_TA_TIME_reg))
#define SD_BUS_TA_TIME_inst_adr                                                      "0x0017"
#define SD_BUS_TA_TIME_inst                                                          0x0017
#define SD_BUS_TA_TIME_Turn_AroundTimeenable_shift                                   (3)
#define SD_BUS_TA_TIME_Turn_AroundTimeenable_mask                                    (0x00000008)
#define SD_BUS_TA_TIME_Turn_AroundTimeenable(data)                                   (0x00000008&((data)<<3))
#define SD_BUS_TA_TIME_Turn_AroundTimeenable_src(data)                               ((0x00000008&(data))>>3)
#define SD_BUS_TA_TIME_get_Turn_AroundTimeenable(data)                               ((0x00000008&(data))>>3)
#define SD_BUS_TA_TIME_Bus_TA_Time_shift                                             (0)
#define SD_BUS_TA_TIME_Bus_TA_Time_mask                                              (0x00000007)
#define SD_BUS_TA_TIME_Bus_TA_Time(data)                                             (0x00000007&((data)<<0))
#define SD_BUS_TA_TIME_Bus_TA_Time_src(data)                                         ((0x00000007&(data))>>0)
#define SD_BUS_TA_TIME_get_Bus_TA_Time(data)                                         ((0x00000007&(data))>>0)


//#define SD_STOP_SDCLK_CFG                                                            0x18010860
#define SD_STOP_SDCLK_CFG_reg_addr                                                   "0x18010860"
#define SD_STOP_SDCLK_CFG_reg                                                        0x18010860
#define set_SD_STOP_SDCLK_CFG_reg(data)   (*((volatile unsigned int*) SD_STOP_SDCLK_CFG_reg)=data)
#define get_SD_STOP_SDCLK_CFG_reg   (*((volatile unsigned int*) SD_STOP_SDCLK_CFG_reg))
#define SD_STOP_SDCLK_CFG_inst_adr                                                   "0x0018"
#define SD_STOP_SDCLK_CFG_inst                                                       0x0018
#define SD_STOP_SDCLK_CFG_STOPSD20SDCLKconfigurationenable_shift                     (5)
#define SD_STOP_SDCLK_CFG_STOPSD20SDCLKconfigurationenable_mask                      (0x00000020)
#define SD_STOP_SDCLK_CFG_STOPSD20SDCLKconfigurationenable(data)                     (0x00000020&((data)<<5))
#define SD_STOP_SDCLK_CFG_STOPSD20SDCLKconfigurationenable_src(data)                 ((0x00000020&(data))>>5)
#define SD_STOP_SDCLK_CFG_get_STOPSD20SDCLKconfigurationenable(data)                 ((0x00000020&(data))>>5)
#define SD_STOP_SDCLK_CFG_STOP_SD20CLK_CFG1_shift                                    (4)
#define SD_STOP_SDCLK_CFG_STOP_SD20CLK_CFG1_mask                                     (0x00000010)
#define SD_STOP_SDCLK_CFG_STOP_SD20CLK_CFG1(data)                                    (0x00000010&((data)<<4))
#define SD_STOP_SDCLK_CFG_STOP_SD20CLK_CFG1_src(data)                                ((0x00000010&(data))>>4)
#define SD_STOP_SDCLK_CFG_get_STOP_SD20CLK_CFG1(data)                                ((0x00000010&(data))>>4)
#define SD_STOP_SDCLK_CFG_STOP_SD20CLK_CFG0_shift                                    (3)
#define SD_STOP_SDCLK_CFG_STOP_SD20CLK_CFG0_mask                                     (0x00000008)
#define SD_STOP_SDCLK_CFG_STOP_SD20CLK_CFG0(data)                                    (0x00000008&((data)<<3))
#define SD_STOP_SDCLK_CFG_STOP_SD20CLK_CFG0_src(data)                                ((0x00000008&(data))>>3)
#define SD_STOP_SDCLK_CFG_get_STOP_SD20CLK_CFG0(data)                                ((0x00000008&(data))>>3)
#define SD_STOP_SDCLK_CFG_STOPSD30SDCLKconfigurationenable_shift                     (2)
#define SD_STOP_SDCLK_CFG_STOPSD30SDCLKconfigurationenable_mask                      (0x00000004)
#define SD_STOP_SDCLK_CFG_STOPSD30SDCLKconfigurationenable(data)                     (0x00000004&((data)<<2))
#define SD_STOP_SDCLK_CFG_STOPSD30SDCLKconfigurationenable_src(data)                 ((0x00000004&(data))>>2)
#define SD_STOP_SDCLK_CFG_get_STOPSD30SDCLKconfigurationenable(data)                 ((0x00000004&(data))>>2)
#define SD_STOP_SDCLK_CFG_STOP_SD30CLK_CFG1_shift                                    (1)
#define SD_STOP_SDCLK_CFG_STOP_SD30CLK_CFG1_mask                                     (0x00000002)
#define SD_STOP_SDCLK_CFG_STOP_SD30CLK_CFG1(data)                                    (0x00000002&((data)<<1))
#define SD_STOP_SDCLK_CFG_STOP_SD30CLK_CFG1_src(data)                                ((0x00000002&(data))>>1)
#define SD_STOP_SDCLK_CFG_get_STOP_SD30CLK_CFG1(data)                                ((0x00000002&(data))>>1)
#define SD_STOP_SDCLK_CFG_STOP_SD30CLK_CFG0_shift                                    (0)
#define SD_STOP_SDCLK_CFG_STOP_SD30CLK_CFG0_mask                                     (0x00000001)
#define SD_STOP_SDCLK_CFG_STOP_SD30CLK_CFG0(data)                                    (0x00000001&((data)<<0))
#define SD_STOP_SDCLK_CFG_STOP_SD30CLK_CFG0_src(data)                                ((0x00000001&(data))>>0)
#define SD_STOP_SDCLK_CFG_get_STOP_SD30CLK_CFG0(data)                                ((0x00000001&(data))>>0)


//#define SD_AUTO_RST_FIFO                                                             0x18010864
#define SD_AUTO_RST_FIFO_reg_addr                                                    "0x18010864"
#define SD_AUTO_RST_FIFO_reg                                                         0x18010864
#define set_SD_AUTO_RST_FIFO_reg(data)   (*((volatile unsigned int*) SD_AUTO_RST_FIFO_reg)=data)
#define get_SD_AUTO_RST_FIFO_reg   (*((volatile unsigned int*) SD_AUTO_RST_FIFO_reg))
#define SD_AUTO_RST_FIFO_inst_adr                                                    "0x0019"
#define SD_AUTO_RST_FIFO_inst                                                        0x0019
#define SD_AUTO_RST_FIFO_Auto_Reset_FIFOenable_shift                                 (0)
#define SD_AUTO_RST_FIFO_Auto_Reset_FIFOenable_mask                                  (0x00000001)
#define SD_AUTO_RST_FIFO_Auto_Reset_FIFOenable(data)                                 (0x00000001&((data)<<0))
#define SD_AUTO_RST_FIFO_Auto_Reset_FIFOenable_src(data)                             ((0x00000001&(data))>>0)
#define SD_AUTO_RST_FIFO_get_Auto_Reset_FIFOenable(data)                             ((0x00000001&(data))>>0)


//#define SD_DAT_PAD                                                                   0x18010868
#define SD_DAT_PAD_reg_addr                                                          "0x18010868"
#define SD_DAT_PAD_reg                                                               0x18010868
#define set_SD_DAT_PAD_reg(data)   (*((volatile unsigned int*) SD_DAT_PAD_reg)=data)
#define get_SD_DAT_PAD_reg   (*((volatile unsigned int*) SD_DAT_PAD_reg))
#define SD_DAT_PAD_inst_adr                                                          "0x001A"
#define SD_DAT_PAD_inst                                                              0x001A
#define SD_DAT_PAD_AD_DAT70_shift                                                    (0)
#define SD_DAT_PAD_AD_DAT70_mask                                                     (0x000000FF)
#define SD_DAT_PAD_AD_DAT70(data)                                                    (0x000000FF&((data)<<0))
#define SD_DAT_PAD_AD_DAT70_src(data)                                                ((0x000000FF&(data))>>0)
#define SD_DAT_PAD_get_AD_DAT70(data)                                                ((0x000000FF&(data))>>0)


//#define SD_DUMMY_4                                                                   0x1801086C
#define SD_DUMMY_4_reg_addr                                                          "0x1801086C"
#define SD_DUMMY_4_reg                                                               0x1801086C
#define set_SD_DUMMY_4_reg(data)   (*((volatile unsigned int*) SD_DUMMY_4_reg)=data)
#define get_SD_DUMMY_4_reg   (*((volatile unsigned int*) SD_DUMMY_4_reg))
#define SD_DUMMY_4_inst_adr                                                          "0x001B"
#define SD_DUMMY_4_inst                                                              0x001B
#define SD_DUMMY_4_SD_DUMMY_4_shift                                                  (0)
#define SD_DUMMY_4_SD_DUMMY_4_mask                                                   (0x000000FF)
#define SD_DUMMY_4_SD_DUMMY_4(data)                                                  (0x000000FF&((data)<<0))
#define SD_DUMMY_4_SD_DUMMY_4_src(data)                                              ((0x000000FF&(data))>>0)
#define SD_DUMMY_4_get_SD_DUMMY_4(data)                                              ((0x000000FF&(data))>>0)


//#define SD_DUMMY_5                                                                   0x18010870
#define SD_DUMMY_5_reg_addr                                                          "0x18010870"
#define SD_DUMMY_5_reg                                                               0x18010870
#define set_SD_DUMMY_5_reg(data)   (*((volatile unsigned int*) SD_DUMMY_5_reg)=data)
#define get_SD_DUMMY_5_reg   (*((volatile unsigned int*) SD_DUMMY_5_reg))
#define SD_DUMMY_5_inst_adr                                                          "0x001C"
#define SD_DUMMY_5_inst                                                              0x001C
#define SD_DUMMY_5_SD_DUMMY_5_shift                                                  (0)
#define SD_DUMMY_5_SD_DUMMY_5_mask                                                   (0x000000FF)
#define SD_DUMMY_5_SD_DUMMY_5(data)                                                  (0x000000FF&((data)<<0))
#define SD_DUMMY_5_SD_DUMMY_5_src(data)                                              ((0x000000FF&(data))>>0)
#define SD_DUMMY_5_get_SD_DUMMY_5(data)                                              ((0x000000FF&(data))>>0)


//#define SD_DUTY_CTL                                                                  0x18010874
#define SD_DUTY_CTL_reg_addr                                                         "0x18010874"
#define SD_DUTY_CTL_reg                                                              0x18010874
#define set_SD_DUTY_CTL_reg(data)   (*((volatile unsigned int*) SD_DUTY_CTL_reg)=data)
#define get_SD_DUTY_CTL_reg   (*((volatile unsigned int*) SD_DUTY_CTL_reg))
#define SD_DUTY_CTL_inst_adr                                                         "0x001D"
#define SD_DUTY_CTL_inst                                                             0x001D
#define SD_DUTY_CTL_SD30DATODutyEnable_shift                                         (7)
#define SD_DUTY_CTL_SD30DATODutyEnable_mask                                          (0x00000080)
#define SD_DUTY_CTL_SD30DATODutyEnable(data)                                         (0x00000080&((data)<<7))
#define SD_DUTY_CTL_SD30DATODutyEnable_src(data)                                     ((0x00000080&(data))>>7)
#define SD_DUTY_CTL_get_SD30DATODutyEnable(data)                                     ((0x00000080&(data))>>7)
#define SD_DUTY_CTL_SD30DATODelayDisable_shift                                       (4)
#define SD_DUTY_CTL_SD30DATODelayDisable_mask                                        (0x00000070)
#define SD_DUTY_CTL_SD30DATODelayDisable(data)                                       (0x00000070&((data)<<4))
#define SD_DUTY_CTL_SD30DATODelayDisable_src(data)                                   ((0x00000070&(data))>>4)
#define SD_DUTY_CTL_get_SD30DATODelayDisable(data)                                   ((0x00000070&(data))>>4)
#define SD_DUTY_CTL_SD30CMDODutyEnable_shift                                         (3)
#define SD_DUTY_CTL_SD30CMDODutyEnable_mask                                          (0x00000008)
#define SD_DUTY_CTL_SD30CMDODutyEnable(data)                                         (0x00000008&((data)<<3))
#define SD_DUTY_CTL_SD30CMDODutyEnable_src(data)                                     ((0x00000008&(data))>>3)
#define SD_DUTY_CTL_get_SD30CMDODutyEnable(data)                                     ((0x00000008&(data))>>3)
#define SD_DUTY_CTL_SD30CMDODelayDisable_shift                                       (0)
#define SD_DUTY_CTL_SD30CMDODelayDisable_mask                                        (0x00000007)
#define SD_DUTY_CTL_SD30CMDODelayDisable(data)                                       (0x00000007&((data)<<0))
#define SD_DUTY_CTL_SD30CMDODelayDisable_src(data)                                   ((0x00000007&(data))>>0)
#define SD_DUTY_CTL_get_SD30CMDODelayDisable(data)                                   ((0x00000007&(data))>>0)


//#define SD_RW_STOP_CTL                                                               0x18010878
#define SD_RW_STOP_CTL_reg_addr                                                      "0x18010878"
#define SD_RW_STOP_CTL_reg                                                           0x18010878
#define set_SD_RW_STOP_CTL_reg(data)   (*((volatile unsigned int*) SD_RW_STOP_CTL_reg)=data)
#define get_SD_RW_STOP_CTL_reg   (*((volatile unsigned int*) SD_RW_STOP_CTL_reg))
#define SD_RW_STOP_CTL_inst_adr                                                      "0x001E"
#define SD_RW_STOP_CTL_inst                                                          0x001E
#define SD_RW_STOP_CTL_SDInfiniteMode_shift                                          (2)
#define SD_RW_STOP_CTL_SDInfiniteMode_mask                                           (0x00000004)
#define SD_RW_STOP_CTL_SDInfiniteMode(data)                                          (0x00000004&((data)<<2))
#define SD_RW_STOP_CTL_SDInfiniteMode_src(data)                                      ((0x00000004&(data))>>2)
#define SD_RW_STOP_CTL_get_SDInfiniteMode(data)                                      ((0x00000004&(data))>>2)
#define SD_RW_STOP_CTL_SDcontrollerbusy_shift                                        (1)
#define SD_RW_STOP_CTL_SDcontrollerbusy_mask                                         (0x00000002)
#define SD_RW_STOP_CTL_SDcontrollerbusy(data)                                        (0x00000002&((data)<<1))
#define SD_RW_STOP_CTL_SDcontrollerbusy_src(data)                                    ((0x00000002&(data))>>1)
#define SD_RW_STOP_CTL_get_SDcontrollerbusy(data)                                    ((0x00000002&(data))>>1)
#define SD_RW_STOP_CTL_SDcontrollerstop_shift                                        (0)
#define SD_RW_STOP_CTL_SDcontrollerstop_mask                                         (0x00000001)
#define SD_RW_STOP_CTL_SDcontrollerstop(data)                                        (0x00000001&((data)<<0))
#define SD_RW_STOP_CTL_SDcontrollerstop_src(data)                                    ((0x00000001&(data))>>0)
#define SD_RW_STOP_CTL_get_SDcontrollerstop(data)                                    ((0x00000001&(data))>>0)


//#define SD_DUMMY_3                                                                   0x1801087C
#define SD_DUMMY_3_reg_addr                                                          "0x1801087C"
#define SD_DUMMY_3_reg                                                               0x1801087C
#define set_SD_DUMMY_3_reg(data)   (*((volatile unsigned int*) SD_DUMMY_3_reg)=data)
#define get_SD_DUMMY_3_reg   (*((volatile unsigned int*) SD_DUMMY_3_reg))
#define SD_DUMMY_3_inst_adr                                                          "0x001F"
#define SD_DUMMY_3_inst                                                              0x001F
#define SD_DUMMY_3_SD_DUMMY_3_shift                                                  (0)
#define SD_DUMMY_3_SD_DUMMY_3_mask                                                   (0x000000FF)
#define SD_DUMMY_3_SD_DUMMY_3(data)                                                  (0x000000FF&((data)<<0))
#define SD_DUMMY_3_SD_DUMMY_3_src(data)                                              ((0x000000FF&(data))>>0)
#define SD_DUMMY_3_get_SD_DUMMY_3(data)                                              ((0x000000FF&(data))>>0)


//#define SD_ADDR_L                                                                    0x18010880
#define SD_ADDR_L_reg_addr                                                           "0x18010880"
#define SD_ADDR_L_reg                                                                0x18010880
#define set_SD_ADDR_L_reg(data)   (*((volatile unsigned int*) SD_ADDR_L_reg)=data)
#define get_SD_ADDR_L_reg   (*((volatile unsigned int*) SD_ADDR_L_reg))
#define SD_ADDR_L_inst_adr                                                           "0x0020"
#define SD_ADDR_L_inst                                                               0x0020
#define SD_ADDR_L_SD_address70_shift                                                 (0)
#define SD_ADDR_L_SD_address70_mask                                                  (0x000000FF)
#define SD_ADDR_L_SD_address70(data)                                                 (0x000000FF&((data)<<0))
#define SD_ADDR_L_SD_address70_src(data)                                             ((0x000000FF&(data))>>0)
#define SD_ADDR_L_get_SD_address70(data)                                             ((0x000000FF&(data))>>0)


//#define SD_ADDR_H                                                                    0x18010884
#define SD_ADDR_H_reg_addr                                                           "0x18010884"
#define SD_ADDR_H_reg                                                                0x18010884
#define set_SD_ADDR_H_reg(data)   (*((volatile unsigned int*) SD_ADDR_H_reg)=data)
#define get_SD_ADDR_H_reg   (*((volatile unsigned int*) SD_ADDR_H_reg))
#define SD_ADDR_H_inst_adr                                                           "0x0021"
#define SD_ADDR_H_inst                                                               0x0021
#define SD_ADDR_H_SD_address158_shift                                                (0)
#define SD_ADDR_H_SD_address158_mask                                                 (0x000000FF)
#define SD_ADDR_H_SD_address158(data)                                                (0x000000FF&((data)<<0))
#define SD_ADDR_H_SD_address158_src(data)                                            ((0x000000FF&(data))>>0)
#define SD_ADDR_H_get_SD_address158(data)                                            ((0x000000FF&(data))>>0)


//#define SD_START_ADDR_0                                                              0x18010888
#define SD_START_ADDR_0_reg_addr                                                     "0x18010888"
#define SD_START_ADDR_0_reg                                                          0x18010888
#define set_SD_START_ADDR_0_reg(data)   (*((volatile unsigned int*) SD_START_ADDR_0_reg)=data)
#define get_SD_START_ADDR_0_reg   (*((volatile unsigned int*) SD_START_ADDR_0_reg))
#define SD_START_ADDR_0_inst_adr                                                     "0x0022"
#define SD_START_ADDR_0_inst                                                         0x0022
#define SD_START_ADDR_0_SD_start_addr70_shift                                        (0)
#define SD_START_ADDR_0_SD_start_addr70_mask                                         (0x000000FF)
#define SD_START_ADDR_0_SD_start_addr70(data)                                        (0x000000FF&((data)<<0))
#define SD_START_ADDR_0_SD_start_addr70_src(data)                                    ((0x000000FF&(data))>>0)
#define SD_START_ADDR_0_get_SD_start_addr70(data)                                    ((0x000000FF&(data))>>0)


//#define SD_START_ADDR_1                                                              0x1801088C
#define SD_START_ADDR_1_reg_addr                                                     "0x1801088C"
#define SD_START_ADDR_1_reg                                                          0x1801088C
#define set_SD_START_ADDR_1_reg(data)   (*((volatile unsigned int*) SD_START_ADDR_1_reg)=data)
#define get_SD_START_ADDR_1_reg   (*((volatile unsigned int*) SD_START_ADDR_1_reg))
#define SD_START_ADDR_1_inst_adr                                                     "0x0023"
#define SD_START_ADDR_1_inst                                                         0x0023
#define SD_START_ADDR_1_SD_start_addr158_shift                                       (0)
#define SD_START_ADDR_1_SD_start_addr158_mask                                        (0x000000FF)
#define SD_START_ADDR_1_SD_start_addr158(data)                                       (0x000000FF&((data)<<0))
#define SD_START_ADDR_1_SD_start_addr158_src(data)                                   ((0x000000FF&(data))>>0)
#define SD_START_ADDR_1_get_SD_start_addr158(data)                                   ((0x000000FF&(data))>>0)


//#define SD_START_ADDR_2                                                              0x18010890
#define SD_START_ADDR_2_reg_addr                                                     "0x18010890"
#define SD_START_ADDR_2_reg                                                          0x18010890
#define set_SD_START_ADDR_2_reg(data)   (*((volatile unsigned int*) SD_START_ADDR_2_reg)=data)
#define get_SD_START_ADDR_2_reg   (*((volatile unsigned int*) SD_START_ADDR_2_reg))
#define SD_START_ADDR_2_inst_adr                                                     "0x0024"
#define SD_START_ADDR_2_inst                                                         0x0024
#define SD_START_ADDR_2_SD_start_addr2316_shift                                      (0)
#define SD_START_ADDR_2_SD_start_addr2316_mask                                       (0x000000FF)
#define SD_START_ADDR_2_SD_start_addr2316(data)                                      (0x000000FF&((data)<<0))
#define SD_START_ADDR_2_SD_start_addr2316_src(data)                                  ((0x000000FF&(data))>>0)
#define SD_START_ADDR_2_get_SD_start_addr2316(data)                                  ((0x000000FF&(data))>>0)


//#define SD_START_ADDR_3                                                              0x18010894
#define SD_START_ADDR_3_reg_addr                                                     "0x18010894"
#define SD_START_ADDR_3_reg                                                          0x18010894
#define set_SD_START_ADDR_3_reg(data)   (*((volatile unsigned int*) SD_START_ADDR_3_reg)=data)
#define get_SD_START_ADDR_3_reg   (*((volatile unsigned int*) SD_START_ADDR_3_reg))
#define SD_START_ADDR_3_inst_adr                                                     "0x0025"
#define SD_START_ADDR_3_inst                                                         0x0025
#define SD_START_ADDR_3_SD_start_addr3124_shift                                      (0)
#define SD_START_ADDR_3_SD_start_addr3124_mask                                       (0x000000FF)
#define SD_START_ADDR_3_SD_start_addr3124(data)                                      (0x000000FF&((data)<<0))
#define SD_START_ADDR_3_SD_start_addr3124_src(data)                                  ((0x000000FF&(data))>>0)
#define SD_START_ADDR_3_get_SD_start_addr3124(data)                                  ((0x000000FF&(data))>>0)


//#define SD_RSP_MASK_1                                                                0x18010898
#define SD_RSP_MASK_1_reg_addr                                                       "0x18010898"
#define SD_RSP_MASK_1_reg                                                            0x18010898
#define set_SD_RSP_MASK_1_reg(data)   (*((volatile unsigned int*) SD_RSP_MASK_1_reg)=data)
#define get_SD_RSP_MASK_1_reg   (*((volatile unsigned int*) SD_RSP_MASK_1_reg))
#define SD_RSP_MASK_1_inst_adr                                                       "0x0026"
#define SD_RSP_MASK_1_inst                                                           0x0026
#define SD_RSP_MASK_1_SD_rsp_mask70_shift                                            (0)
#define SD_RSP_MASK_1_SD_rsp_mask70_mask                                             (0x000000FF)
#define SD_RSP_MASK_1_SD_rsp_mask70(data)                                            (0x000000FF&((data)<<0))
#define SD_RSP_MASK_1_SD_rsp_mask70_src(data)                                        ((0x000000FF&(data))>>0)
#define SD_RSP_MASK_1_get_SD_rsp_mask70(data)                                        ((0x000000FF&(data))>>0)


//#define SD_RSP_MASK_2                                                                0x180108A0
#define SD_RSP_MASK_2_reg_addr                                                       "0x180108A0"
#define SD_RSP_MASK_2_reg                                                            0x180108A0
#define set_SD_RSP_MASK_2_reg(data)   (*((volatile unsigned int*) SD_RSP_MASK_2_reg)=data)
#define get_SD_RSP_MASK_2_reg   (*((volatile unsigned int*) SD_RSP_MASK_2_reg))
#define SD_RSP_MASK_2_inst_adr                                                       "0x0028"
#define SD_RSP_MASK_2_inst                                                           0x0028
#define SD_RSP_MASK_2_SD_rsp_mask158_shift                                           (0)
#define SD_RSP_MASK_2_SD_rsp_mask158_mask                                            (0x000000FF)
#define SD_RSP_MASK_2_SD_rsp_mask158(data)                                           (0x000000FF&((data)<<0))
#define SD_RSP_MASK_2_SD_rsp_mask158_src(data)                                       ((0x000000FF&(data))>>0)
#define SD_RSP_MASK_2_get_SD_rsp_mask158(data)                                       ((0x000000FF&(data))>>0)


//#define SD_RSP_MASK_3                                                                0x180108A4
#define SD_RSP_MASK_3_reg_addr                                                       "0x180108A4"
#define SD_RSP_MASK_3_reg                                                            0x180108A4
#define set_SD_RSP_MASK_3_reg(data)   (*((volatile unsigned int*) SD_RSP_MASK_3_reg)=data)
#define get_SD_RSP_MASK_3_reg   (*((volatile unsigned int*) SD_RSP_MASK_3_reg))
#define SD_RSP_MASK_3_inst_adr                                                       "0x0029"
#define SD_RSP_MASK_3_inst                                                           0x0029
#define SD_RSP_MASK_3_SD_rsp_mask2316_shift                                          (0)
#define SD_RSP_MASK_3_SD_rsp_mask2316_mask                                           (0x000000FF)
#define SD_RSP_MASK_3_SD_rsp_mask2316(data)                                          (0x000000FF&((data)<<0))
#define SD_RSP_MASK_3_SD_rsp_mask2316_src(data)                                      ((0x000000FF&(data))>>0)
#define SD_RSP_MASK_3_get_SD_rsp_mask2316(data)                                      ((0x000000FF&(data))>>0)


//#define SD_RSP_MASK_4                                                                0x180108A8
#define SD_RSP_MASK_4_reg_addr                                                       "0x180108A8"
#define SD_RSP_MASK_4_reg                                                            0x180108A8
#define set_SD_RSP_MASK_4_reg(data)   (*((volatile unsigned int*) SD_RSP_MASK_4_reg)=data)
#define get_SD_RSP_MASK_4_reg   (*((volatile unsigned int*) SD_RSP_MASK_4_reg))
#define SD_RSP_MASK_4_inst_adr                                                       "0x002A"
#define SD_RSP_MASK_4_inst                                                           0x002A
#define SD_RSP_MASK_4_SD_rsp_mask3124_shift                                          (0)
#define SD_RSP_MASK_4_SD_rsp_mask3124_mask                                           (0x000000FF)
#define SD_RSP_MASK_4_SD_rsp_mask3124(data)                                          (0x000000FF&((data)<<0))
#define SD_RSP_MASK_4_SD_rsp_mask3124_src(data)                                      ((0x000000FF&(data))>>0)
#define SD_RSP_MASK_4_get_SD_rsp_mask3124(data)                                      ((0x000000FF&(data))>>0)


//#define SD_RSP_DATA_1                                                                0x180108AC
#define SD_RSP_DATA_1_reg_addr                                                       "0x180108AC"
#define SD_RSP_DATA_1_reg                                                            0x180108AC
#define set_SD_RSP_DATA_1_reg(data)   (*((volatile unsigned int*) SD_RSP_DATA_1_reg)=data)
#define get_SD_RSP_DATA_1_reg   (*((volatile unsigned int*) SD_RSP_DATA_1_reg))
#define SD_RSP_DATA_1_inst_adr                                                       "0x002B"
#define SD_RSP_DATA_1_inst                                                           0x002B
#define SD_RSP_DATA_1_SD_rsp_data70_shift                                            (0)
#define SD_RSP_DATA_1_SD_rsp_data70_mask                                             (0x000000FF)
#define SD_RSP_DATA_1_SD_rsp_data70(data)                                            (0x000000FF&((data)<<0))
#define SD_RSP_DATA_1_SD_rsp_data70_src(data)                                        ((0x000000FF&(data))>>0)
#define SD_RSP_DATA_1_get_SD_rsp_data70(data)                                        ((0x000000FF&(data))>>0)


//#define SD_RSP_DATA_2                                                                0x180108B0
#define SD_RSP_DATA_2_reg_addr                                                       "0x180108B0"
#define SD_RSP_DATA_2_reg                                                            0x180108B0
#define set_SD_RSP_DATA_2_reg(data)   (*((volatile unsigned int*) SD_RSP_DATA_2_reg)=data)
#define get_SD_RSP_DATA_2_reg   (*((volatile unsigned int*) SD_RSP_DATA_2_reg))
#define SD_RSP_DATA_2_inst_adr                                                       "0x002C"
#define SD_RSP_DATA_2_inst                                                           0x002C
#define SD_RSP_DATA_2_SD_rsp_data158_shift                                           (0)
#define SD_RSP_DATA_2_SD_rsp_data158_mask                                            (0x000000FF)
#define SD_RSP_DATA_2_SD_rsp_data158(data)                                           (0x000000FF&((data)<<0))
#define SD_RSP_DATA_2_SD_rsp_data158_src(data)                                       ((0x000000FF&(data))>>0)
#define SD_RSP_DATA_2_get_SD_rsp_data158(data)                                       ((0x000000FF&(data))>>0)


//#define SD_RSP_DATA_3                                                                0x180108B4
#define SD_RSP_DATA_3_reg_addr                                                       "0x180108B4"
#define SD_RSP_DATA_3_reg                                                            0x180108B4
#define set_SD_RSP_DATA_3_reg(data)   (*((volatile unsigned int*) SD_RSP_DATA_3_reg)=data)
#define get_SD_RSP_DATA_3_reg   (*((volatile unsigned int*) SD_RSP_DATA_3_reg))
#define SD_RSP_DATA_3_inst_adr                                                       "0x002D"
#define SD_RSP_DATA_3_inst                                                           0x002D
#define SD_RSP_DATA_3_SD_rsp_data2316_shift                                          (0)
#define SD_RSP_DATA_3_SD_rsp_data2316_mask                                           (0x000000FF)
#define SD_RSP_DATA_3_SD_rsp_data2316(data)                                          (0x000000FF&((data)<<0))
#define SD_RSP_DATA_3_SD_rsp_data2316_src(data)                                      ((0x000000FF&(data))>>0)
#define SD_RSP_DATA_3_get_SD_rsp_data2316(data)                                      ((0x000000FF&(data))>>0)


//#define SD_RSP_DATA_4                                                                0x180108B8
#define SD_RSP_DATA_4_reg_addr                                                       "0x180108B8"
#define SD_RSP_DATA_4_reg                                                            0x180108B8
#define set_SD_RSP_DATA_4_reg(data)   (*((volatile unsigned int*) SD_RSP_DATA_4_reg)=data)
#define get_SD_RSP_DATA_4_reg   (*((volatile unsigned int*) SD_RSP_DATA_4_reg))
#define SD_RSP_DATA_4_inst_adr                                                       "0x002E"
#define SD_RSP_DATA_4_inst                                                           0x002E
#define SD_RSP_DATA_4_SD_rsp_data3124_shift                                          (0)
#define SD_RSP_DATA_4_SD_rsp_data3124_mask                                           (0x000000FF)
#define SD_RSP_DATA_4_SD_rsp_data3124(data)                                          (0x000000FF&((data)<<0))
#define SD_RSP_DATA_4_SD_rsp_data3124_src(data)                                      ((0x000000FF&(data))>>0)
#define SD_RSP_DATA_4_get_SD_rsp_data3124(data)                                      ((0x000000FF&(data))>>0)


//#define SD_WR_DELAY                                                                  0x180108BC
#define SD_WR_DELAY_reg_addr                                                         "0x180108BC"
#define SD_WR_DELAY_reg                                                              0x180108BC
#define set_SD_WR_DELAY_reg(data)   (*((volatile unsigned int*) SD_WR_DELAY_reg)=data)
#define get_SD_WR_DELAY_reg   (*((volatile unsigned int*) SD_WR_DELAY_reg))
#define SD_WR_DELAY_inst_adr                                                         "0x002F"
#define SD_WR_DELAY_inst                                                             0x002F
#define SD_WR_DELAY_SD_write_delay_shift                                             (0)
#define SD_WR_DELAY_SD_write_delay_mask                                              (0x0000000F)
#define SD_WR_DELAY_SD_write_delay(data)                                             (0x0000000F&((data)<<0))
#define SD_WR_DELAY_SD_write_delay_src(data)                                         ((0x0000000F&(data))>>0)
#define SD_WR_DELAY_get_SD_write_delay(data)                                         ((0x0000000F&(data))>>0)


//#define SD_RD_DELAY                                                                  0x180108C0
#define SD_RD_DELAY_reg_addr                                                         "0x180108C0"
#define SD_RD_DELAY_reg                                                              0x180108C0
#define set_SD_RD_DELAY_reg(data)   (*((volatile unsigned int*) SD_RD_DELAY_reg)=data)
#define get_SD_RD_DELAY_reg   (*((volatile unsigned int*) SD_RD_DELAY_reg))
#define SD_RD_DELAY_inst_adr                                                         "0x0030"
#define SD_RD_DELAY_inst                                                             0x0030
#define SD_RD_DELAY_SD_read_delay_shift                                              (0)
#define SD_RD_DELAY_SD_read_delay_mask                                               (0x0000000F)
#define SD_RD_DELAY_SD_read_delay(data)                                              (0x0000000F&((data)<<0))
#define SD_RD_DELAY_SD_read_delay_src(data)                                          ((0x0000000F&(data))>>0)
#define SD_RD_DELAY_get_SD_read_delay(data)                                          ((0x0000000F&(data))>>0)


//#define CR_DMA_PTR_STATUS                                                            0x180108D0
#define CR_DMA_PTR_STATUS_reg_addr                                                   "0x180108D0"
#define CR_DMA_PTR_STATUS_reg                                                        0x180108D0
#define set_CR_DMA_PTR_STATUS_reg(data)   (*((volatile unsigned int*) CR_DMA_PTR_STATUS_reg)=data)
#define get_CR_DMA_PTR_STATUS_reg   (*((volatile unsigned int*) CR_DMA_PTR_STATUS_reg))
#define CR_DMA_PTR_STATUS_inst_adr                                                   "0x0034"
#define CR_DMA_PTR_STATUS_inst                                                       0x0034
#define CR_DMA_PTR_STATUS_dma_out_index_shift                                        (16)
#define CR_DMA_PTR_STATUS_dma_out_index_mask                                         (0x003F0000)
#define CR_DMA_PTR_STATUS_dma_out_index(data)                                        (0x003F0000&((data)<<16))
#define CR_DMA_PTR_STATUS_dma_out_index_src(data)                                    ((0x003F0000&(data))>>16)
#define CR_DMA_PTR_STATUS_get_dma_out_index(data)                                    ((0x003F0000&(data))>>16)
#define CR_DMA_PTR_STATUS_dma_in_index_shift                                         (0)
#define CR_DMA_PTR_STATUS_dma_in_index_mask                                          (0x0000003F)
#define CR_DMA_PTR_STATUS_dma_in_index(data)                                         (0x0000003F&((data)<<0))
#define CR_DMA_PTR_STATUS_dma_in_index_src(data)                                     ((0x0000003F&(data))>>0)
#define CR_DMA_PTR_STATUS_get_dma_in_index(data)                                     ((0x0000003F&(data))>>0)


//#define CR_DMA_IN_ADDR                                                               0x180108D4
#define CR_DMA_IN_ADDR_reg_addr                                                      "0x180108D4"
#define CR_DMA_IN_ADDR_reg                                                           0x180108D4
#define set_CR_DMA_IN_ADDR_reg(data)   (*((volatile unsigned int*) CR_DMA_IN_ADDR_reg)=data)
#define get_CR_DMA_IN_ADDR_reg   (*((volatile unsigned int*) CR_DMA_IN_ADDR_reg))
#define CR_DMA_IN_ADDR_inst_adr                                                      "0x0035"
#define CR_DMA_IN_ADDR_inst                                                          0x0035
#define CR_DMA_IN_ADDR_dma_in_addr_shift                                             (3)
#define CR_DMA_IN_ADDR_dma_in_addr_mask                                              (0xFFFFFFF8)
#define CR_DMA_IN_ADDR_dma_in_addr(data)                                             (0xFFFFFFF8&((data)<<3))
#define CR_DMA_IN_ADDR_dma_in_addr_src(data)                                         ((0xFFFFFFF8&(data))>>3)
#define CR_DMA_IN_ADDR_get_dma_in_addr(data)                                         ((0xFFFFFFF8&(data))>>3)


//#define CR_DMA_OUT_ADDR                                                              0x180108D8
#define CR_DMA_OUT_ADDR_reg_addr                                                     "0x180108D8"
#define CR_DMA_OUT_ADDR_reg                                                          0x180108D8
#define set_CR_DMA_OUT_ADDR_reg(data)   (*((volatile unsigned int*) CR_DMA_OUT_ADDR_reg)=data)
#define get_CR_DMA_OUT_ADDR_reg   (*((volatile unsigned int*) CR_DMA_OUT_ADDR_reg))
#define CR_DMA_OUT_ADDR_inst_adr                                                     "0x0036"
#define CR_DMA_OUT_ADDR_inst                                                         0x0036
#define CR_DMA_OUT_ADDR_dma_out_addr_shift                                           (3)
#define CR_DMA_OUT_ADDR_dma_out_addr_mask                                            (0xFFFFFFF8)
#define CR_DMA_OUT_ADDR_dma_out_addr(data)                                           (0xFFFFFFF8&((data)<<3))
#define CR_DMA_OUT_ADDR_dma_out_addr_src(data)                                       ((0xFFFFFFF8&(data))>>3)
#define CR_DMA_OUT_ADDR_get_dma_out_addr(data)                                       ((0xFFFFFFF8&(data))>>3)


//#define CR_INT_STATUS                                                                0x180108DC
#define CR_INT_STATUS_reg_addr                                                       "0x180108DC"
#define CR_INT_STATUS_reg                                                            0x180108DC
#define set_CR_INT_STATUS_reg(data)   (*((volatile unsigned int*) CR_INT_STATUS_reg)=data)
#define get_CR_INT_STATUS_reg   (*((volatile unsigned int*) CR_INT_STATUS_reg))
#define CR_INT_STATUS_inst_adr                                                       "0x0037"
#define CR_INT_STATUS_inst                                                           0x0037
#define CR_INT_STATUS_write_protection_shift                                         (5)
#define CR_INT_STATUS_write_protection_mask                                          (0x00000020)
#define CR_INT_STATUS_write_protection(data)                                         (0x00000020&((data)<<5))
#define CR_INT_STATUS_write_protection_src(data)                                     ((0x00000020&(data))>>5)
#define CR_INT_STATUS_get_write_protection(data)                                     ((0x00000020&(data))>>5)
#define CR_INT_STATUS_card_detection_shift                                           (4)
#define CR_INT_STATUS_card_detection_mask                                            (0x00000010)
#define CR_INT_STATUS_card_detection(data)                                           (0x00000010&((data)<<4))
#define CR_INT_STATUS_card_detection_src(data)                                       ((0x00000010&(data))>>4)
#define CR_INT_STATUS_get_card_detection(data)                                       ((0x00000010&(data))>>4)
#define CR_INT_STATUS_reserved_shift                                                 (3)
#define CR_INT_STATUS_reserved_mask                                                  (0x00000008)
#define CR_INT_STATUS_reserved(data)                                                 (0x00000008&((data)<<3))
#define CR_INT_STATUS_reserved_src(data)                                             ((0x00000008&(data))>>3)
#define CR_INT_STATUS_get_reserved(data)                                             ((0x00000008&(data))>>3)
#define CR_INT_STATUS_decode_error_shift                                             (2)
#define CR_INT_STATUS_decode_error_mask                                              (0x00000004)
#define CR_INT_STATUS_decode_error(data)                                             (0x00000004&((data)<<2))
#define CR_INT_STATUS_decode_error_src(data)                                         ((0x00000004&(data))>>2)
#define CR_INT_STATUS_get_decode_error(data)                                         ((0x00000004&(data))>>2)
#define CR_INT_STATUS_decode_finish_shift                                            (1)
#define CR_INT_STATUS_decode_finish_mask                                             (0x00000002)
#define CR_INT_STATUS_decode_finish(data)                                            (0x00000002&((data)<<1))
#define CR_INT_STATUS_decode_finish_src(data)                                        ((0x00000002&(data))>>1)
#define CR_INT_STATUS_get_decode_finish(data)                                        ((0x00000002&(data))>>1)
#define CR_INT_STATUS_card_status_change_shift                                       (0)
#define CR_INT_STATUS_card_status_change_mask                                        (0x00000001)
#define CR_INT_STATUS_card_status_change(data)                                       (0x00000001&((data)<<0))
#define CR_INT_STATUS_card_status_change_src(data)                                   ((0x00000001&(data))>>0)
#define CR_INT_STATUS_get_card_status_change(data)                                   ((0x00000001&(data))>>0)


//#define CR_INT_MASK                                                                  0x180108E0
#define CR_INT_MASK_reg_addr                                                         "0x180108E0"
#define CR_INT_MASK_reg                                                              0x180108E0
#define set_CR_INT_MASK_reg(data)   (*((volatile unsigned int*) CR_INT_MASK_reg)=data)
#define get_CR_INT_MASK_reg   (*((volatile unsigned int*) CR_INT_MASK_reg))
#define CR_INT_MASK_inst_adr                                                         "0x0038"
#define CR_INT_MASK_inst                                                             0x0038
#define CR_INT_MASK_Card_detection_intmask_shift                                     (3)
#define CR_INT_MASK_Card_detection_intmask_mask                                      (0x00000008)
#define CR_INT_MASK_Card_detection_intmask(data)                                     (0x00000008&((data)<<3))
#define CR_INT_MASK_Card_detection_intmask_src(data)                                 ((0x00000008&(data))>>3)
#define CR_INT_MASK_get_Card_detection_intmask(data)                                 ((0x00000008&(data))>>3)
#define CR_INT_MASK_decode_error_mask_shift                                          (2)
#define CR_INT_MASK_decode_error_mask_mask                                           (0x00000004)
#define CR_INT_MASK_decode_error_mask(data)                                          (0x00000004&((data)<<2))
#define CR_INT_MASK_decode_error_mask_src(data)                                      ((0x00000004&(data))>>2)
#define CR_INT_MASK_get_decode_error_mask(data)                                      ((0x00000004&(data))>>2)
#define CR_INT_MASK_decode_finish_mask_shift                                         (1)
#define CR_INT_MASK_decode_finish_mask_mask                                          (0x00000002)
#define CR_INT_MASK_decode_finish_mask(data)                                         (0x00000002&((data)<<1))
#define CR_INT_MASK_decode_finish_mask_src(data)                                     ((0x00000002&(data))>>1)
#define CR_INT_MASK_get_decode_finish_mask(data)                                     ((0x00000002&(data))>>1)
#define CR_INT_MASK_card_status_change_mask_shift                                    (0)
#define CR_INT_MASK_card_status_change_mask_mask                                     (0x00000001)
#define CR_INT_MASK_card_status_change_mask(data)                                    (0x00000001&((data)<<0))
#define CR_INT_MASK_card_status_change_mask_src(data)                                ((0x00000001&(data))>>0)
#define CR_INT_MASK_get_card_status_change_mask(data)                                ((0x00000001&(data))>>0)


//#define CR_REG_MODE_CTRL                                                             0x180108E4
#define CR_REG_MODE_CTRL_reg_addr                                                    "0x180108E4"
#define CR_REG_MODE_CTRL_reg                                                         0x180108E4
#define set_CR_REG_MODE_CTRL_reg(data)   (*((volatile unsigned int*) CR_REG_MODE_CTRL_reg)=data)
#define get_CR_REG_MODE_CTRL_reg   (*((volatile unsigned int*) CR_REG_MODE_CTRL_reg))
#define CR_REG_MODE_CTRL_inst_adr                                                    "0x0039"
#define CR_REG_MODE_CTRL_inst                                                        0x0039
#define CR_REG_MODE_CTRL_reg_stop_shift                                              (3)
#define CR_REG_MODE_CTRL_reg_stop_mask                                               (0x00000008)
#define CR_REG_MODE_CTRL_reg_stop(data)                                              (0x00000008&((data)<<3))
#define CR_REG_MODE_CTRL_reg_stop_src(data)                                          ((0x00000008&(data))>>3)
#define CR_REG_MODE_CTRL_get_reg_stop(data)                                          ((0x00000008&(data))>>3)


//#define CR_DES_MODE_CTRL                                                             0x180108E8
#define CR_DES_MODE_CTRL_reg_addr                                                    "0x180108E8"
#define CR_DES_MODE_CTRL_reg                                                         0x180108E8
#define set_CR_DES_MODE_CTRL_reg(data)   (*((volatile unsigned int*) CR_DES_MODE_CTRL_reg)=data)
#define get_CR_DES_MODE_CTRL_reg   (*((volatile unsigned int*) CR_DES_MODE_CTRL_reg))
#define CR_DES_MODE_CTRL_inst_adr                                                    "0x003A"
#define CR_DES_MODE_CTRL_inst                                                        0x003A
#define CR_DES_MODE_CTRL_des_addr_auto_inc_shift                                     (10)
#define CR_DES_MODE_CTRL_des_addr_auto_inc_mask                                      (0x00000400)
#define CR_DES_MODE_CTRL_des_addr_auto_inc(data)                                     (0x00000400&((data)<<10))
#define CR_DES_MODE_CTRL_des_addr_auto_inc_src(data)                                 ((0x00000400&(data))>>10)
#define CR_DES_MODE_CTRL_get_des_addr_auto_inc(data)                                 ((0x00000400&(data))>>10)
#define CR_DES_MODE_CTRL_des_sw_hs_enable_shift                                      (9)
#define CR_DES_MODE_CTRL_des_sw_hs_enable_mask                                       (0x00000200)
#define CR_DES_MODE_CTRL_des_sw_hs_enable(data)                                      (0x00000200&((data)<<9))
#define CR_DES_MODE_CTRL_des_sw_hs_enable_src(data)                                  ((0x00000200&(data))>>9)
#define CR_DES_MODE_CTRL_get_des_sw_hs_enable(data)                                  ((0x00000200&(data))>>9)
#define CR_DES_MODE_CTRL_rd_des_cmd_wr_port_shift                                    (8)
#define CR_DES_MODE_CTRL_rd_des_cmd_wr_port_mask                                     (0x00000100)
#define CR_DES_MODE_CTRL_rd_des_cmd_wr_port(data)                                    (0x00000100&((data)<<8))
#define CR_DES_MODE_CTRL_rd_des_cmd_wr_port_src(data)                                ((0x00000100&(data))>>8)
#define CR_DES_MODE_CTRL_get_rd_des_cmd_wr_port(data)                                ((0x00000100&(data))>>8)
#define CR_DES_MODE_CTRL_des_stop_shift                                              (7)
#define CR_DES_MODE_CTRL_des_stop_mask                                               (0x00000080)
#define CR_DES_MODE_CTRL_des_stop(data)                                              (0x00000080&((data)<<7))
#define CR_DES_MODE_CTRL_des_stop_src(data)                                          ((0x00000080&(data))>>7)
#define CR_DES_MODE_CTRL_get_des_stop(data)                                          ((0x00000080&(data))>>7)
#define CR_DES_MODE_CTRL_des_mode_len_shift                                          (3)
#define CR_DES_MODE_CTRL_des_mode_len_mask                                           (0x00000078)
#define CR_DES_MODE_CTRL_des_mode_len(data)                                          (0x00000078&((data)<<3))
#define CR_DES_MODE_CTRL_des_mode_len_src(data)                                      ((0x00000078&(data))>>3)
#define CR_DES_MODE_CTRL_get_des_mode_len(data)                                      ((0x00000078&(data))>>3)
#define CR_DES_MODE_CTRL_des_mode_en_shift                                           (0)
#define CR_DES_MODE_CTRL_des_mode_en_mask                                            (0x00000001)
#define CR_DES_MODE_CTRL_des_mode_en(data)                                           (0x00000001&((data)<<0))
#define CR_DES_MODE_CTRL_des_mode_en_src(data)                                       ((0x00000001&(data))>>0)
#define CR_DES_MODE_CTRL_get_des_mode_en(data)                                       ((0x00000001&(data))>>0)


//#define DES_CMD_WR_PORT                                                              0x180108EC
#define DES_CMD_WR_PORT_reg_addr                                                     "0x180108EC"
#define DES_CMD_WR_PORT_reg                                                          0x180108EC
#define set_DES_CMD_WR_PORT_reg(data)   (*((volatile unsigned int*) DES_CMD_WR_PORT_reg)=data)
#define get_DES_CMD_WR_PORT_reg   (*((volatile unsigned int*) DES_CMD_WR_PORT_reg))
#define DES_CMD_WR_PORT_inst_adr                                                     "0x003B"
#define DES_CMD_WR_PORT_inst                                                         0x003B
#define DES_CMD_WR_PORT_des_command_shift                                            (0)
#define DES_CMD_WR_PORT_des_command_mask                                             (0xFFFFFFFF)
#define DES_CMD_WR_PORT_des_command(data)                                            (0xFFFFFFFF&((data)<<0))
#define DES_CMD_WR_PORT_des_command_src(data)                                        ((0xFFFFFFFF&(data))>>0)
#define DES_CMD_WR_PORT_get_des_command(data)                                        ((0xFFFFFFFF&(data))>>0)


//#define CR_BIST_0                                                                    0x180108F0
#define CR_BIST_0_reg_addr                                                           "0x180108F0"
#define CR_BIST_0_reg                                                                0x180108F0
#define set_CR_BIST_0_reg(data)   (*((volatile unsigned int*) CR_BIST_0_reg)=data)
#define get_CR_BIST_0_reg   (*((volatile unsigned int*) CR_BIST_0_reg))
#define CR_BIST_0_inst_adr                                                           "0x003C"
#define CR_BIST_0_inst                                                               0x003C
#define CR_BIST_0_BIST_RSTN_shift                                                    (0)
#define CR_BIST_0_BIST_RSTN_mask                                                     (0x00000001)
#define CR_BIST_0_BIST_RSTN(data)                                                    (0x00000001&((data)<<0))
#define CR_BIST_0_BIST_RSTN_src(data)                                                ((0x00000001&(data))>>0)
#define CR_BIST_0_get_BIST_RSTN(data)                                                ((0x00000001&(data))>>0)


//#define CR_BIST_1                                                                    0x180108F4
#define CR_BIST_1_reg_addr                                                           "0x180108F4"
#define CR_BIST_1_reg                                                                0x180108F4
#define set_CR_BIST_1_reg(data)   (*((volatile unsigned int*) CR_BIST_1_reg)=data)
#define get_CR_BIST_1_reg   (*((volatile unsigned int*) CR_BIST_1_reg))
#define CR_BIST_1_inst_adr                                                           "0x003D"
#define CR_BIST_1_inst                                                               0x003D
#define CR_BIST_1_RMA_0_shift                                                        (6)
#define CR_BIST_1_RMA_0_mask                                                         (0x000003C0)
#define CR_BIST_1_RMA_0(data)                                                        (0x000003C0&((data)<<6))
#define CR_BIST_1_RMA_0_src(data)                                                    ((0x000003C0&(data))>>6)
#define CR_BIST_1_get_RMA_0(data)                                                    ((0x000003C0&(data))>>6)
#define CR_BIST_1_RMEA_0_shift                                                       (5)
#define CR_BIST_1_RMEA_0_mask                                                        (0x00000020)
#define CR_BIST_1_RMEA_0(data)                                                       (0x00000020&((data)<<5))
#define CR_BIST_1_RMEA_0_src(data)                                                   ((0x00000020&(data))>>5)
#define CR_BIST_1_get_RMEA_0(data)                                                   ((0x00000020&(data))>>5)
#define CR_BIST_1_RMB_0_shift                                                        (1)
#define CR_BIST_1_RMB_0_mask                                                         (0x0000001E)
#define CR_BIST_1_RMB_0(data)                                                        (0x0000001E&((data)<<1))
#define CR_BIST_1_RMB_0_src(data)                                                    ((0x0000001E&(data))>>1)
#define CR_BIST_1_get_RMB_0(data)                                                    ((0x0000001E&(data))>>1)
#define CR_BIST_1_RMEB_0_shift                                                       (0)
#define CR_BIST_1_RMEB_0_mask                                                        (0x00000001)
#define CR_BIST_1_RMEB_0(data)                                                       (0x00000001&((data)<<0))
#define CR_BIST_1_RMEB_0_src(data)                                                   ((0x00000001&(data))>>0)
#define CR_BIST_1_get_RMEB_0(data)                                                   ((0x00000001&(data))>>0)


//#define CR_BIST_MODE                                                                 0x180108F8
#define CR_BIST_MODE_reg_addr                                                        "0x180108F8"
#define CR_BIST_MODE_reg                                                             0x180108F8
#define set_CR_BIST_MODE_reg(data)   (*((volatile unsigned int*) CR_BIST_MODE_reg)=data)
#define get_CR_BIST_MODE_reg   (*((volatile unsigned int*) CR_BIST_MODE_reg))
#define CR_BIST_MODE_inst_adr                                                        "0x003E"
#define CR_BIST_MODE_inst                                                            0x003E
#define CR_BIST_MODE_BIST_MODE_0_shift                                               (0)
#define CR_BIST_MODE_BIST_MODE_0_mask                                                (0x00000001)
#define CR_BIST_MODE_BIST_MODE_0(data)                                               (0x00000001&((data)<<0))
#define CR_BIST_MODE_BIST_MODE_0_src(data)                                           ((0x00000001&(data))>>0)
#define CR_BIST_MODE_get_BIST_MODE_0(data)                                           ((0x00000001&(data))>>0)


//#define CR_BIST_DONE                                                                 0x180108FC
#define CR_BIST_DONE_reg_addr                                                        "0x180108FC"
#define CR_BIST_DONE_reg                                                             0x180108FC
#define set_CR_BIST_DONE_reg(data)   (*((volatile unsigned int*) CR_BIST_DONE_reg)=data)
#define get_CR_BIST_DONE_reg   (*((volatile unsigned int*) CR_BIST_DONE_reg))
#define CR_BIST_DONE_inst_adr                                                        "0x003F"
#define CR_BIST_DONE_inst                                                            0x003F
#define CR_BIST_DONE_BIST_DONE_0_shift                                               (0)
#define CR_BIST_DONE_BIST_DONE_0_mask                                                (0x00000001)
#define CR_BIST_DONE_BIST_DONE_0(data)                                               (0x00000001&((data)<<0))
#define CR_BIST_DONE_BIST_DONE_0_src(data)                                           ((0x00000001&(data))>>0)
#define CR_BIST_DONE_get_BIST_DONE_0(data)                                           ((0x00000001&(data))>>0)


//#define CR_BIST_FAIL                                                                 0x18010900
#define CR_BIST_FAIL_reg_addr                                                        "0x18010900"
#define CR_BIST_FAIL_reg                                                             0x18010900
#define set_CR_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CR_BIST_FAIL_reg)=data)
#define get_CR_BIST_FAIL_reg   (*((volatile unsigned int*) CR_BIST_FAIL_reg))
#define CR_BIST_FAIL_inst_adr                                                        "0x0040"
#define CR_BIST_FAIL_inst                                                            0x0040
#define CR_BIST_FAIL_BIST_FAIL_0_shift                                               (0)
#define CR_BIST_FAIL_BIST_FAIL_0_mask                                                (0x00000001)
#define CR_BIST_FAIL_BIST_FAIL_0(data)                                               (0x00000001&((data)<<0))
#define CR_BIST_FAIL_BIST_FAIL_0_src(data)                                           ((0x00000001&(data))>>0)
#define CR_BIST_FAIL_get_BIST_FAIL_0(data)                                           ((0x00000001&(data))>>0)


//#define CR_BIST_DRF_MODE                                                             0x18010904
#define CR_BIST_DRF_MODE_reg_addr                                                    "0x18010904"
#define CR_BIST_DRF_MODE_reg                                                         0x18010904
#define set_CR_BIST_DRF_MODE_reg(data)   (*((volatile unsigned int*) CR_BIST_DRF_MODE_reg)=data)
#define get_CR_BIST_DRF_MODE_reg   (*((volatile unsigned int*) CR_BIST_DRF_MODE_reg))
#define CR_BIST_DRF_MODE_inst_adr                                                    "0x0041"
#define CR_BIST_DRF_MODE_inst                                                        0x0041
#define CR_BIST_DRF_MODE_DRF_MODEofMBIST_0_shift                                     (0)
#define CR_BIST_DRF_MODE_DRF_MODEofMBIST_0_mask                                      (0x00000001)
#define CR_BIST_DRF_MODE_DRF_MODEofMBIST_0(data)                                     (0x00000001&((data)<<0))
#define CR_BIST_DRF_MODE_DRF_MODEofMBIST_0_src(data)                                 ((0x00000001&(data))>>0)
#define CR_BIST_DRF_MODE_get_DRF_MODEofMBIST_0(data)                                 ((0x00000001&(data))>>0)


//#define CR_BIST_DRF_RESUME                                                           0x18010908
#define CR_BIST_DRF_RESUME_reg_addr                                                  "0x18010908"
#define CR_BIST_DRF_RESUME_reg                                                       0x18010908
#define set_CR_BIST_DRF_RESUME_reg(data)   (*((volatile unsigned int*) CR_BIST_DRF_RESUME_reg)=data)
#define get_CR_BIST_DRF_RESUME_reg   (*((volatile unsigned int*) CR_BIST_DRF_RESUME_reg))
#define CR_BIST_DRF_RESUME_inst_adr                                                  "0x0042"
#define CR_BIST_DRF_RESUME_inst                                                      0x0042
#define CR_BIST_DRF_RESUME_DRF_RESUMEofMBIST_0_shift                                 (0)
#define CR_BIST_DRF_RESUME_DRF_RESUMEofMBIST_0_mask                                  (0x00000001)
#define CR_BIST_DRF_RESUME_DRF_RESUMEofMBIST_0(data)                                 (0x00000001&((data)<<0))
#define CR_BIST_DRF_RESUME_DRF_RESUMEofMBIST_0_src(data)                             ((0x00000001&(data))>>0)
#define CR_BIST_DRF_RESUME_get_DRF_RESUMEofMBIST_0(data)                             ((0x00000001&(data))>>0)


//#define CR_BIST_DRF_DONE                                                             0x1801090C
#define CR_BIST_DRF_DONE_reg_addr                                                    "0x1801090C"
#define CR_BIST_DRF_DONE_reg                                                         0x1801090C
#define set_CR_BIST_DRF_DONE_reg(data)   (*((volatile unsigned int*) CR_BIST_DRF_DONE_reg)=data)
#define get_CR_BIST_DRF_DONE_reg   (*((volatile unsigned int*) CR_BIST_DRF_DONE_reg))
#define CR_BIST_DRF_DONE_inst_adr                                                    "0x0043"
#define CR_BIST_DRF_DONE_inst                                                        0x0043
#define CR_BIST_DRF_DONE_DRF_DONEofMBIST_0_shift                                     (0)
#define CR_BIST_DRF_DONE_DRF_DONEofMBIST_0_mask                                      (0x00000001)
#define CR_BIST_DRF_DONE_DRF_DONEofMBIST_0(data)                                     (0x00000001&((data)<<0))
#define CR_BIST_DRF_DONE_DRF_DONEofMBIST_0_src(data)                                 ((0x00000001&(data))>>0)
#define CR_BIST_DRF_DONE_get_DRF_DONEofMBIST_0(data)                                 ((0x00000001&(data))>>0)


//#define CR_BIST_DRF_PAUSE                                                            0x18010910
#define CR_BIST_DRF_PAUSE_reg_addr                                                   "0x18010910"
#define CR_BIST_DRF_PAUSE_reg                                                        0x18010910
#define set_CR_BIST_DRF_PAUSE_reg(data)   (*((volatile unsigned int*) CR_BIST_DRF_PAUSE_reg)=data)
#define get_CR_BIST_DRF_PAUSE_reg   (*((volatile unsigned int*) CR_BIST_DRF_PAUSE_reg))
#define CR_BIST_DRF_PAUSE_inst_adr                                                   "0x0044"
#define CR_BIST_DRF_PAUSE_inst                                                       0x0044
#define CR_BIST_DRF_PAUSE_DRF_PAUSEofMBIST_0_shift                                   (0)
#define CR_BIST_DRF_PAUSE_DRF_PAUSEofMBIST_0_mask                                    (0x00000001)
#define CR_BIST_DRF_PAUSE_DRF_PAUSEofMBIST_0(data)                                   (0x00000001&((data)<<0))
#define CR_BIST_DRF_PAUSE_DRF_PAUSEofMBIST_0_src(data)                               ((0x00000001&(data))>>0)
#define CR_BIST_DRF_PAUSE_get_DRF_PAUSEofMBIST_0(data)                               ((0x00000001&(data))>>0)


//#define CR_BIST_DRF_FAIL                                                             0x18010914
#define CR_BIST_DRF_FAIL_reg_addr                                                    "0x18010914"
#define CR_BIST_DRF_FAIL_reg                                                         0x18010914
#define set_CR_BIST_DRF_FAIL_reg(data)   (*((volatile unsigned int*) CR_BIST_DRF_FAIL_reg)=data)
#define get_CR_BIST_DRF_FAIL_reg   (*((volatile unsigned int*) CR_BIST_DRF_FAIL_reg))
#define CR_BIST_DRF_FAIL_inst_adr                                                    "0x0045"
#define CR_BIST_DRF_FAIL_inst                                                        0x0045
#define CR_BIST_DRF_FAIL_DRF_FAILofMBIST_0_shift                                     (0)
#define CR_BIST_DRF_FAIL_DRF_FAILofMBIST_0_mask                                      (0x00000001)
#define CR_BIST_DRF_FAIL_DRF_FAILofMBIST_0(data)                                     (0x00000001&((data)<<0))
#define CR_BIST_DRF_FAIL_DRF_FAILofMBIST_0_src(data)                                 ((0x00000001&(data))>>0)
#define CR_BIST_DRF_FAIL_get_DRF_FAILofMBIST_0(data)                                 ((0x00000001&(data))>>0)


//#define CR_CTRL                                                                      0x18010918
#define CR_CTRL_reg_addr                                                             "0x18010918"
#define CR_CTRL_reg                                                                  0x18010918
#define set_CR_CTRL_reg(data)   (*((volatile unsigned int*) CR_CTRL_reg)=data)
#define get_CR_CTRL_reg   (*((volatile unsigned int*) CR_CTRL_reg))
#define CR_CTRL_inst_adr                                                             "0x0046"
#define CR_CTRL_inst                                                                 0x0046
#define CR_CTRL_Dummy_shift                                                          (24)
#define CR_CTRL_Dummy_mask                                                           (0x1F000000)
#define CR_CTRL_Dummy(data)                                                          (0x1F000000&((data)<<24))
#define CR_CTRL_Dummy_src(data)                                                      ((0x1F000000&(data))>>24)
#define CR_CTRL_get_Dummy(data)                                                      ((0x1F000000&(data))>>24)
#define CR_CTRL_Asic_dbg_sel_shift                                                   (20)
#define CR_CTRL_Asic_dbg_sel_mask                                                    (0x00F00000)
#define CR_CTRL_Asic_dbg_sel(data)                                                   (0x00F00000&((data)<<20))
#define CR_CTRL_Asic_dbg_sel_src(data)                                               ((0x00F00000&(data))>>20)
#define CR_CTRL_get_Asic_dbg_sel(data)                                               ((0x00F00000&(data))>>20)
#define CR_CTRL_Dbg_sel_shift                                                        (12)
#define CR_CTRL_Dbg_sel_mask                                                         (0x000FF000)
#define CR_CTRL_Dbg_sel(data)                                                        (0x000FF000&((data)<<12))
#define CR_CTRL_Dbg_sel_src(data)                                                    ((0x000FF000&(data))>>12)
#define CR_CTRL_get_Dbg_sel(data)                                                    ((0x000FF000&(data))>>12)
#define CR_CTRL_Wrap_dbg_sel_shift                                                   (6)
#define CR_CTRL_Wrap_dbg_sel_mask                                                    (0x00000FC0)
#define CR_CTRL_Wrap_dbg_sel(data)                                                   (0x00000FC0&((data)<<6))
#define CR_CTRL_Wrap_dbg_sel_src(data)                                               ((0x00000FC0&(data))>>6)
#define CR_CTRL_get_Wrap_dbg_sel(data)                                               ((0x00000FC0&(data))>>6)
#define CR_CTRL_Map_sel_shift                                                        (5)
#define CR_CTRL_Map_sel_mask                                                         (0x00000020)
#define CR_CTRL_Map_sel(data)                                                        (0x00000020&((data)<<5))
#define CR_CTRL_Map_sel_src(data)                                                    ((0x00000020&(data))>>5)
#define CR_CTRL_get_Map_sel(data)                                                    ((0x00000020&(data))>>5)
#define CR_CTRL_Xfer_dir_shift                                                       (4)
#define CR_CTRL_Xfer_dir_mask                                                        (0x00000010)
#define CR_CTRL_Xfer_dir(data)                                                       (0x00000010&((data)<<4))
#define CR_CTRL_Xfer_dir_src(data)                                                   ((0x00000010&(data))>>4)
#define CR_CTRL_get_Xfer_dir(data)                                                   ((0x00000010&(data))>>4)
#define CR_CTRL_Boot_from_cr_shift                                                   (3)
#define CR_CTRL_Boot_from_cr_mask                                                    (0x00000008)
#define CR_CTRL_Boot_from_cr(data)                                                   (0x00000008&((data)<<3))
#define CR_CTRL_Boot_from_cr_src(data)                                               ((0x00000008&(data))>>3)
#define CR_CTRL_get_Boot_from_cr(data)                                               ((0x00000008&(data))>>3)
#define CR_CTRL_Buff_timing_shift                                                    (1)
#define CR_CTRL_Buff_timing_mask                                                     (0x00000006)
#define CR_CTRL_Buff_timing(data)                                                    (0x00000006&((data)<<1))
#define CR_CTRL_Buff_timing_src(data)                                                ((0x00000006&(data))>>1)
#define CR_CTRL_get_Buff_timing(data)                                                ((0x00000006&(data))>>1)
#define CR_CTRL_CP_en_shift                                                          (0)
#define CR_CTRL_CP_en_mask                                                           (0x00000001)
#define CR_CTRL_CP_en(data)                                                          (0x00000001&((data)<<0))
#define CR_CTRL_CP_en_src(data)                                                      ((0x00000001&(data))>>0)
#define CR_CTRL_get_CP_en(data)                                                      ((0x00000001&(data))>>0)


//#define ARB_STS                                                                      0x1801091C
#define ARB_STS_reg_addr                                                             "0x1801091C"
#define ARB_STS_reg                                                                  0x1801091C
#define set_ARB_STS_reg(data)   (*((volatile unsigned int*) ARB_STS_reg)=data)
#define get_ARB_STS_reg   (*((volatile unsigned int*) ARB_STS_reg))
#define ARB_STS_inst_adr                                                             "0x0047"
#define ARB_STS_inst                                                                 0x0047
#define ARB_STS_ARB_STS_shift                                                        (0)
#define ARB_STS_ARB_STS_mask                                                         (0x000000FF)
#define ARB_STS_ARB_STS(data)                                                        (0x000000FF&((data)<<0))
#define ARB_STS_ARB_STS_src(data)                                                    ((0x000000FF&(data))>>0)
#define ARB_STS_get_ARB_STS(data)                                                    ((0x000000FF&(data))>>0)


//#define SRAM_DATA                                                                    0x18010920
#define SRAM_DATA_reg_addr                                                           "0x18010920"
#define SRAM_DATA_reg                                                                0x18010920
#define set_SRAM_DATA_reg(data)   (*((volatile unsigned int*) SRAM_DATA_reg)=data)
#define get_SRAM_DATA_reg   (*((volatile unsigned int*) SRAM_DATA_reg))
#define SRAM_DATA_inst_adr                                                           "0x0048"
#define SRAM_DATA_inst                                                               0x0048
#define SRAM_DATA_DATA_shift                                                         (0)
#define SRAM_DATA_DATA_mask                                                          (0xFFFFFFFF)
#define SRAM_DATA_DATA(data)                                                         (0xFFFFFFFF&((data)<<0))
#define SRAM_DATA_DATA_src(data)                                                     ((0xFFFFFFFF&(data))>>0)
#define SRAM_DATA_get_DATA(data)                                                     ((0xFFFFFFFF&(data))>>0)


//#define CLK_PHASE_SEL                                                                0x18010924
#define CLK_PHASE_SEL_reg_addr                                                       "0x18010924"
#define CLK_PHASE_SEL_reg                                                            0x18010924
#define set_CLK_PHASE_SEL_reg(data)   (*((volatile unsigned int*) CLK_PHASE_SEL_reg)=data)
#define get_CLK_PHASE_SEL_reg   (*((volatile unsigned int*) CLK_PHASE_SEL_reg))
#define CLK_PHASE_SEL_inst_adr                                                       "0x0049"
#define CLK_PHASE_SEL_inst                                                           0x0049
#define CLK_PHASE_SEL_push_phase_sel_shift                                           (16)
#define CLK_PHASE_SEL_push_phase_sel_mask                                            (0xFFFF0000)
#define CLK_PHASE_SEL_push_phase_sel(data)                                           (0xFFFF0000&((data)<<16))
#define CLK_PHASE_SEL_push_phase_sel_src(data)                                       ((0xFFFF0000&(data))>>16)
#define CLK_PHASE_SEL_get_push_phase_sel(data)                                       ((0xFFFF0000&(data))>>16)
#define CLK_PHASE_SEL_samp_phase_sel_shift                                           (0)
#define CLK_PHASE_SEL_samp_phase_sel_mask                                            (0x0000FFFF)
#define CLK_PHASE_SEL_samp_phase_sel(data)                                           (0x0000FFFF&((data)<<0))
#define CLK_PHASE_SEL_samp_phase_sel_src(data)                                       ((0x0000FFFF&(data))>>0)
#define CLK_PHASE_SEL_get_samp_phase_sel(data)                                       ((0x0000FFFF&(data))>>0)


//#define RSP_17B_0                                                                    0x18010928
#define RSP_17B_0_reg_addr                                                           "0x18010928"
#define RSP_17B_0_reg                                                                0x18010928
#define set_RSP_17B_0_reg(data)   (*((volatile unsigned int*) RSP_17B_0_reg)=data)
#define get_RSP_17B_0_reg   (*((volatile unsigned int*) RSP_17B_0_reg))
#define RSP_17B_0_inst_adr                                                           "0x004A"
#define RSP_17B_0_inst                                                               0x004A
#define RSP_17B_0_RSP_buf_0_shift                                                    (0)
#define RSP_17B_0_RSP_buf_0_mask                                                     (0x0000FFFF)
#define RSP_17B_0_RSP_buf_0(data)                                                    (0x0000FFFF&((data)<<0))
#define RSP_17B_0_RSP_buf_0_src(data)                                                ((0x0000FFFF&(data))>>0)
#define RSP_17B_0_get_RSP_buf_0(data)                                                ((0x0000FFFF&(data))>>0)


//#define RSP_17B_1                                                                    0x1801092C
#define RSP_17B_1_reg_addr                                                           "0x1801092C"
#define RSP_17B_1_reg                                                                0x1801092C
#define set_RSP_17B_1_reg(data)   (*((volatile unsigned int*) RSP_17B_1_reg)=data)
#define get_RSP_17B_1_reg   (*((volatile unsigned int*) RSP_17B_1_reg))
#define RSP_17B_1_inst_adr                                                           "0x004B"
#define RSP_17B_1_inst                                                               0x004B
#define RSP_17B_1_RSP_buf_1_shift                                                    (0)
#define RSP_17B_1_RSP_buf_1_mask                                                     (0x0000FFFF)
#define RSP_17B_1_RSP_buf_1(data)                                                    (0x0000FFFF&((data)<<0))
#define RSP_17B_1_RSP_buf_1_src(data)                                                ((0x0000FFFF&(data))>>0)
#define RSP_17B_1_get_RSP_buf_1(data)                                                ((0x0000FFFF&(data))>>0)


//#define RSP_17B_2                                                                    0x18010930
#define RSP_17B_2_reg_addr                                                           "0x18010930"
#define RSP_17B_2_reg                                                                0x18010930
#define set_RSP_17B_2_reg(data)   (*((volatile unsigned int*) RSP_17B_2_reg)=data)
#define get_RSP_17B_2_reg   (*((volatile unsigned int*) RSP_17B_2_reg))
#define RSP_17B_2_inst_adr                                                           "0x004C"
#define RSP_17B_2_inst                                                               0x004C
#define RSP_17B_2_RSP_buf_2_shift                                                    (0)
#define RSP_17B_2_RSP_buf_2_mask                                                     (0x0000FFFF)
#define RSP_17B_2_RSP_buf_2(data)                                                    (0x0000FFFF&((data)<<0))
#define RSP_17B_2_RSP_buf_2_src(data)                                                ((0x0000FFFF&(data))>>0)
#define RSP_17B_2_get_RSP_buf_2(data)                                                ((0x0000FFFF&(data))>>0)


//#define RSP_17B_3                                                                    0x18010934
#define RSP_17B_3_reg_addr                                                           "0x18010934"
#define RSP_17B_3_reg                                                                0x18010934
#define set_RSP_17B_3_reg(data)   (*((volatile unsigned int*) RSP_17B_3_reg)=data)
#define get_RSP_17B_3_reg   (*((volatile unsigned int*) RSP_17B_3_reg))
#define RSP_17B_3_inst_adr                                                           "0x004D"
#define RSP_17B_3_inst                                                               0x004D
#define RSP_17B_3_RSP_buf_3_shift                                                    (0)
#define RSP_17B_3_RSP_buf_3_mask                                                     (0x0000FFFF)
#define RSP_17B_3_RSP_buf_3(data)                                                    (0x0000FFFF&((data)<<0))
#define RSP_17B_3_RSP_buf_3_src(data)                                                ((0x0000FFFF&(data))>>0)
#define RSP_17B_3_get_RSP_buf_3(data)                                                ((0x0000FFFF&(data))>>0)


//#define RSP_17B_4                                                                    0x18010938
#define RSP_17B_4_reg_addr                                                           "0x18010938"
#define RSP_17B_4_reg                                                                0x18010938
#define set_RSP_17B_4_reg(data)   (*((volatile unsigned int*) RSP_17B_4_reg)=data)
#define get_RSP_17B_4_reg   (*((volatile unsigned int*) RSP_17B_4_reg))
#define RSP_17B_4_inst_adr                                                           "0x004E"
#define RSP_17B_4_inst                                                               0x004E
#define RSP_17B_4_RSP_buf_4_shift                                                    (0)
#define RSP_17B_4_RSP_buf_4_mask                                                     (0x0000FFFF)
#define RSP_17B_4_RSP_buf_4(data)                                                    (0x0000FFFF&((data)<<0))
#define RSP_17B_4_RSP_buf_4_src(data)                                                ((0x0000FFFF&(data))>>0)
#define RSP_17B_4_get_RSP_buf_4(data)                                                ((0x0000FFFF&(data))>>0)


//#define RSP_17B_5                                                                    0x1801093C
#define RSP_17B_5_reg_addr                                                           "0x1801093C"
#define RSP_17B_5_reg                                                                0x1801093C
#define set_RSP_17B_5_reg(data)   (*((volatile unsigned int*) RSP_17B_5_reg)=data)
#define get_RSP_17B_5_reg   (*((volatile unsigned int*) RSP_17B_5_reg))
#define RSP_17B_5_inst_adr                                                           "0x004F"
#define RSP_17B_5_inst                                                               0x004F
#define RSP_17B_5_RSP_buf_5_shift                                                    (0)
#define RSP_17B_5_RSP_buf_5_mask                                                     (0x0000FFFF)
#define RSP_17B_5_RSP_buf_5(data)                                                    (0x0000FFFF&((data)<<0))
#define RSP_17B_5_RSP_buf_5_src(data)                                                ((0x0000FFFF&(data))>>0)
#define RSP_17B_5_get_RSP_buf_5(data)                                                ((0x0000FFFF&(data))>>0)


//#define RSP_17B_6                                                                    0x18010940
#define RSP_17B_6_reg_addr                                                           "0x18010940"
#define RSP_17B_6_reg                                                                0x18010940
#define set_RSP_17B_6_reg(data)   (*((volatile unsigned int*) RSP_17B_6_reg)=data)
#define get_RSP_17B_6_reg   (*((volatile unsigned int*) RSP_17B_6_reg))
#define RSP_17B_6_inst_adr                                                           "0x0050"
#define RSP_17B_6_inst                                                               0x0050
#define RSP_17B_6_RSP_buf_6_shift                                                    (0)
#define RSP_17B_6_RSP_buf_6_mask                                                     (0x0000FFFF)
#define RSP_17B_6_RSP_buf_6(data)                                                    (0x0000FFFF&((data)<<0))
#define RSP_17B_6_RSP_buf_6_src(data)                                                ((0x0000FFFF&(data))>>0)
#define RSP_17B_6_get_RSP_buf_6(data)                                                ((0x0000FFFF&(data))>>0)


//#define RSP_17B_7                                                                    0x18010944
#define RSP_17B_7_reg_addr                                                           "0x18010944"
#define RSP_17B_7_reg                                                                0x18010944
#define set_RSP_17B_7_reg(data)   (*((volatile unsigned int*) RSP_17B_7_reg)=data)
#define get_RSP_17B_7_reg   (*((volatile unsigned int*) RSP_17B_7_reg))
#define RSP_17B_7_inst_adr                                                           "0x0051"
#define RSP_17B_7_inst                                                               0x0051
#define RSP_17B_7_RSP_buf_7_shift                                                    (0)
#define RSP_17B_7_RSP_buf_7_mask                                                     (0x0000FFFF)
#define RSP_17B_7_RSP_buf_7(data)                                                    (0x0000FFFF&((data)<<0))
#define RSP_17B_7_RSP_buf_7_src(data)                                                ((0x0000FFFF&(data))>>0)
#define RSP_17B_7_get_RSP_buf_7(data)                                                ((0x0000FFFF&(data))>>0)


//#define KCPU_SEL                                                                     0x18010948
#define KCPU_SEL_reg_addr                                                            "0x18010948"
#define KCPU_SEL_reg                                                                 0x18010948
#define set_KCPU_SEL_reg(data)   (*((volatile unsigned int*) KCPU_SEL_reg)=data)
#define get_KCPU_SEL_reg   (*((volatile unsigned int*) KCPU_SEL_reg))
#define KCPU_SEL_inst_adr                                                            "0x0052"
#define KCPU_SEL_inst                                                                0x0052
#define KCPU_SEL_pr_en_shift                                                         (1)
#define KCPU_SEL_pr_en_mask                                                          (0x00000002)
#define KCPU_SEL_pr_en(data)                                                         (0x00000002&((data)<<1))
#define KCPU_SEL_pr_en_src(data)                                                     ((0x00000002&(data))>>1)
#define KCPU_SEL_get_pr_en(data)                                                     ((0x00000002&(data))>>1)
#define KCPU_SEL_k_cpu_sel_shift                                                     (0)
#define KCPU_SEL_k_cpu_sel_mask                                                      (0x00000001)
#define KCPU_SEL_k_cpu_sel(data)                                                     (0x00000001&((data)<<0))
#define KCPU_SEL_k_cpu_sel_src(data)                                                 ((0x00000001&(data))>>0)
#define KCPU_SEL_get_k_cpu_sel(data)                                                 ((0x00000001&(data))>>0)


//#define PADDR_START                                                                  0x1801094C
#define PADDR_START_reg_addr                                                         "0x1801094C"
#define PADDR_START_reg                                                              0x1801094C
#define set_PADDR_START_reg(data)   (*((volatile unsigned int*) PADDR_START_reg)=data)
#define get_PADDR_START_reg   (*((volatile unsigned int*) PADDR_START_reg))
#define PADDR_START_inst_adr                                                         "0x0053"
#define PADDR_START_inst                                                             0x0053
#define PADDR_START_Paddr_start_shift                                                (0)
#define PADDR_START_Paddr_start_mask                                                 (0xFFFFFFFF)
#define PADDR_START_Paddr_start(data)                                                (0xFFFFFFFF&((data)<<0))
#define PADDR_START_Paddr_start_src(data)                                            ((0xFFFFFFFF&(data))>>0)
#define PADDR_START_get_Paddr_start(data)                                            ((0xFFFFFFFF&(data))>>0)


//#define PADDR_END                                                                    0x18010950
#define PADDR_END_reg_addr                                                           "0x18010950"
#define PADDR_END_reg                                                                0x18010950
#define set_PADDR_END_reg(data)   (*((volatile unsigned int*) PADDR_END_reg)=data)
#define get_PADDR_END_reg   (*((volatile unsigned int*) PADDR_END_reg))
#define PADDR_END_inst_adr                                                           "0x0054"
#define PADDR_END_inst                                                               0x0054
#define PADDR_END_Paddr_end_shift                                                    (0)
#define PADDR_END_Paddr_end_mask                                                     (0xFFFFFFFF)
#define PADDR_END_Paddr_end(data)                                                    (0xFFFFFFFF&((data)<<0))
#define PADDR_END_Paddr_end_src(data)                                                ((0xFFFFFFFF&(data))>>0)
#define PADDR_END_get_Paddr_end(data)                                                ((0xFFFFFFFF&(data))>>0)


//#define CR_INT_STATUS_K                                                              0x18010954
#define CR_INT_STATUS_K_reg_addr                                                     "0x18010954"
#define CR_INT_STATUS_K_reg                                                          0x18010954
#define set_CR_INT_STATUS_K_reg(data)   (*((volatile unsigned int*) CR_INT_STATUS_K_reg)=data)
#define get_CR_INT_STATUS_K_reg   (*((volatile unsigned int*) CR_INT_STATUS_K_reg))
#define CR_INT_STATUS_K_inst_adr                                                     "0x0055"
#define CR_INT_STATUS_K_inst                                                         0x0055
#define CR_INT_STATUS_K_decode_error_k_shift                                         (2)
#define CR_INT_STATUS_K_decode_error_k_mask                                          (0x00000004)
#define CR_INT_STATUS_K_decode_error_k(data)                                         (0x00000004&((data)<<2))
#define CR_INT_STATUS_K_decode_error_k_src(data)                                     ((0x00000004&(data))>>2)
#define CR_INT_STATUS_K_get_decode_error_k(data)                                     ((0x00000004&(data))>>2)
#define CR_INT_STATUS_K_decode_finish_k_shift                                        (1)
#define CR_INT_STATUS_K_decode_finish_k_mask                                         (0x00000002)
#define CR_INT_STATUS_K_decode_finish_k(data)                                        (0x00000002&((data)<<1))
#define CR_INT_STATUS_K_decode_finish_k_src(data)                                    ((0x00000002&(data))>>1)
#define CR_INT_STATUS_K_get_decode_finish_k(data)                                    ((0x00000002&(data))>>1)


//#define CR_INT_MASK_K                                                                0x18010958
#define CR_INT_MASK_K_reg_addr                                                       "0x18010958"
#define CR_INT_MASK_K_reg                                                            0x18010958
#define set_CR_INT_MASK_K_reg(data)   (*((volatile unsigned int*) CR_INT_MASK_K_reg)=data)
#define get_CR_INT_MASK_K_reg   (*((volatile unsigned int*) CR_INT_MASK_K_reg))
#define CR_INT_MASK_K_inst_adr                                                       "0x0056"
#define CR_INT_MASK_K_inst                                                           0x0056
#define CR_INT_MASK_K_decode_error_mask_shift                                        (2)
#define CR_INT_MASK_K_decode_error_mask_mask                                         (0x00000004)
#define CR_INT_MASK_K_decode_error_mask(data)                                        (0x00000004&((data)<<2))
#define CR_INT_MASK_K_decode_error_mask_src(data)                                    ((0x00000004&(data))>>2)
#define CR_INT_MASK_K_get_decode_error_mask(data)                                    ((0x00000004&(data))>>2)
#define CR_INT_MASK_K_decode_finish_mask_shift                                       (1)
#define CR_INT_MASK_K_decode_finish_mask_mask                                        (0x00000002)
#define CR_INT_MASK_K_decode_finish_mask(data)                                       (0x00000002&((data)<<1))
#define CR_INT_MASK_K_decode_finish_mask_src(data)                                   ((0x00000002&(data))>>1)
#define CR_INT_MASK_K_get_decode_finish_mask(data)                                   ((0x00000002&(data))>>1)


//#define SCPU_SEL                                                                     0x18010960
#define SCPU_SEL_reg_addr                                                            "0x18010960"
#define SCPU_SEL_reg                                                                 0x18010960
#define set_SCPU_SEL_reg(data)   (*((volatile unsigned int*) SCPU_SEL_reg)=data)
#define get_SCPU_SEL_reg   (*((volatile unsigned int*) SCPU_SEL_reg))
#define SCPU_SEL_inst_adr                                                            "0x0058"
#define SCPU_SEL_inst                                                                0x0058
#define SCPU_SEL_s_cpu_sel_shift                                                     (0)
#define SCPU_SEL_s_cpu_sel_mask                                                      (0x00000001)
#define SCPU_SEL_s_cpu_sel(data)                                                     (0x00000001&((data)<<0))
#define SCPU_SEL_s_cpu_sel_src(data)                                                 ((0x00000001&(data))>>0)
#define SCPU_SEL_get_s_cpu_sel(data)                                                 ((0x00000001&(data))>>0)


//#define CPU_ST                                                                       0x18010964
#define CPU_ST_reg_addr                                                              "0x18010964"
#define CPU_ST_reg                                                                   0x18010964
#define set_CPU_ST_reg(data)   (*((volatile unsigned int*) CPU_ST_reg)=data)
#define get_CPU_ST_reg   (*((volatile unsigned int*) CPU_ST_reg))
#define CPU_ST_inst_adr                                                              "0x0059"
#define CPU_ST_inst                                                                  0x0059
#define CPU_ST_cpu_st_shift                                                          (0)
#define CPU_ST_cpu_st_mask                                                           (0x00000003)
#define CPU_ST_cpu_st(data)                                                          (0x00000003&((data)<<0))
#define CPU_ST_cpu_st_src(data)                                                      ((0x00000003&(data))>>0)
#define CPU_ST_get_cpu_st(data)                                                      ((0x00000003&(data))>>0)

/* Register Definition (head only) */
#define SD_CONFIGURE1               (0x000UL)     //0xb8010800
#define SD_CONFIGURE2               (0x004UL)     //0xb8010804
#define SD_CONFIGURE3               (0x008UL)     //0xb8010808
#define SD_STATUS                   (0x00CUL)     //0xb801080C
#define SD_STATUS2                  (0x010UL)     //0xb8010810
#define SD_BUS_STATUS               (0x014UL)     //0xb8010814
#define SD_CMD_CODE                 (0x018UL)     //0xb8010818
#define SD_SAMPLE_POINT_CTL         (0x01CUL)     //0xb801081C
#define SD_PUSH_POINT_CTL           (0x020UL)     //0xb8010820
#define SD_CMD0                     (0x024UL)     //0xb8010824
#define SD_CMD1                     (0x028UL)     //0xb8010828
#define SD_CMD2                     (0x02CUL)     //0xb801082C
#define SD_CMD3                     (0x030UL)     //0xb8010830
#define SD_CMD4                     (0x034UL)     //0xb8010834
#define SD_CMD5                     (0x038UL)     //0xb8010838
#define SD_BYTE_CNT_L               (0x03CUL)     //0xb801083C
#define SD_BYTE_CNT_H               (0x040UL)     //0xb8010840
#define SD_BLOCK_CNT_L              (0x044UL)     //0xb8010844
#define SD_BLOCK_CNT_H              (0x048UL)     //0xb8010848
#define SD_TRANSFER                 (0x04CUL)     //0xb801084C
#define SD_DDR_CHK_START            (0x050UL)     //0xb8010850
#define SD_CMD_STATE                (0x054UL)     //0xb8010854
#define SD_DATA_STATE               (0x058UL)     //0xb8010858
#define SD_BUS_TA_TIME              (0x05CUL)     //0xb801085C
#define SD_STOP_SDCLK_CFG           (0x060UL)     //0xb8010860
#define SD_AUTO_RST_FIFO            (0x064UL)     //0xb8010864
#define SD_DAT_PAD                  (0x068UL)     //0xb8010868
#define SD_DUMMY_4                  (0x06CUL)     //0xb801086C
#define SD_DUMMY_5                  (0x070UL)     //0xb8010870
#define SD_DUTY_CTL                 (0x074UL)     //0xb8010874
#define SD_RW_STOP_CTL              (0x078UL)     //0xb8010878
#define SD_DUMMY_3                  (0x07CUL)     //0xb801087C
#define SD_ADDR_L                   (0x080UL)     //0xb8010880
#define SD_ADDR_H                   (0x084UL)     //0xb8010884
#define SD_START_ADDR_0             (0x088UL)     //0xb8010888
#define SD_START_ADDR_1             (0x08CUL)     //0xb801088C
#define SD_START_ADDR_2             (0x090UL)     //0xb8010890
#define SD_START_ADDR_3             (0x094UL)     //0xb8010894
#define SD_RSP_MASK_1               (0x098UL)     //0xb8010898
#define SD_RSP_MASK_2               (0x0A0UL)     //0xb80108A0
#define SD_RSP_MASK_3               (0x0A4UL)     //0xb80108A4
#define SD_RSP_MASK_4               (0x0A8UL)     //0xb80108A8
#define SD_RSP_DATA_1               (0x0ACUL)     //0xb80108AC
#define SD_RSP_DATA_2               (0x0B0UL)     //0xb80108B0
#define SD_RSP_DATA_3               (0x0B4UL)     //0xb80108B4
#define SD_RSP_DATA_4               (0x0B8UL)     //0xb80108B8
#define SD_WR_DELAY                 (0x0BCUL)     //0xb80108BC
#define SD_RD_DELAY                 (0x0C0UL)     //0xb80108C0
#define CR_DMA_PTR_STATUS           (0x0D0UL)     //0xb80108D0
#define CR_DMA_IN_ADDR              (0x0D4UL)     //0xb80108D4
#define CR_DMA_OUT_ADDR             (0x0D8UL)     //0xb80108D8
#define CR_INT_STATUS               (0x0DCUL)     //0xb80108DC
#define CR_INT_MASK                 (0x0E0UL)     //0xb80108E0
#define CR_REG_MODE_CTRL            (0x0E4UL)     //0xb80108E4
#define CR_DES_MODE_CTRL            (0x0E8UL)     //0xb80108E8
#define DES_CMD_WR_PORT             (0x0ECUL)     //0xb80108EC
#define CR_BIST_0                   (0x0F0UL)     //0xb80108F0
#define CR_BIST_1                   (0x0F4UL)     //0xb80108F4
#define CR_BIST_MODE                (0x0F8UL)     //0xb80108F8
#define CR_BIST_DONE                (0x0FCUL)     //0xb80108FC
#define CR_BIST_FAIL                (0x100UL)     //0xb8010900
#define CR_BIST_DRF_MODE            (0x104UL)     //0xb8010904
#define CR_BIST_DRF_RESUME          (0x108UL)     //0xb8010908
#define CR_BIST_DRF_DONE            (0x10CUL)     //0xb801090C
#define CR_BIST_DRF_PAUSE           (0x110UL)     //0xb8010910
#define CR_BIST_DRF_FAIL            (0x114UL)     //0xb8010914
#define CR_CTRL                     (0x118UL)     //0xb8010918
#define ARB_STS                     (0x11CUL)     //0xb801091C
#define SRAM_DATA                   (0x120UL)     //0xb8010920
#define CLK_PHASE_SEL               (0x124UL)     //0xb8010924
#define RSP_17B_0                   (0x128UL)     //0xb8010928
#define RSP_17B_1                   (0x12CUL)     //0xb801092C
#define RSP_17B_2                   (0x130UL)     //0xb8010930
#define RSP_17B_3                   (0x134UL)     //0xb8010934
#define RSP_17B_4                   (0x138UL)     //0xb8010938
#define RSP_17B_5                   (0x13CUL)     //0xb801093C
#define RSP_17B_6                   (0x140UL)     //0xb8010940
#define RSP_17B_7                   (0x144UL)     //0xb8010944
#define KCPU_SEL                    (0x148UL)     //0xb8010948
#define PADDR_START                 (0x14CUL)     //0xb801094C
#define PADDR_END                   (0x150UL)     //0xb8010950
#define CR_INT_STATUS_K             (0x154UL)     //0xb8010954
#define CR_INT_MASK_K               (0x158UL)     //0xb8010958
#define KCPU_ST                     (0x15CUL)     //0xb801095C
#define SCPU_SEL                    (0x170UL)     //0xb8010970
#define CPU_ST                      (0x174UL)     //0xb8010974
#define CR_INT_STATUS_FREE          (0x178UL)     //0xb8010978
#define PIN_CTRL                    (0x17CUL)     //0xb801097C

/* extra define */
#define CR_CARD_RESP6_0             SD_CMD0       //0xb8010824
#define CR_CARD_RESP6_1             SD_CMD1       //0xb8010828
#define CR_CARD_RESP6_2             SD_CMD2       //0xb801082C
#define CR_CARD_RESP6_3             SD_CMD3       //0xb8010830
#define CR_CARD_RESP6_4             SD_CMD4       //0xb8010834
#define CR_CARD_RESP6_5             SD_CMD5       //0xb8010838

/* register item define */
// SD_CONFIGURE1 0xb8010800
#define CLOCK_DIV_SHT               (6)
#define MASK_CLOCK_DIV              (0x3UL<<CLOCK_DIV_SHT)
#define CLOCK_DIV_NON               (0x0UL<<CLOCK_DIV_SHT)
#define CLOCK_DIV_256               (0x3UL<<CLOCK_DIV_SHT)
#define CLOCK_DIV_128               (0x2UL<<CLOCK_DIV_SHT)
#define SD30_ASYNC_FIFO_RST_N       (4)
#define Mode_SEL_SHT                (2)
#define MASK_Mode_SEL               (0x03UL<<Mode_SEL_SHT)
#define Mode_SEL_SD20               (0x00UL<<Mode_SEL_SHT)
#define Mode_SEL_DDR                (0x01UL<<Mode_SEL_SHT)
#define Mode_SEL_SD30               (0x02UL<<Mode_SEL_SHT)
#define MASK_BUS_WIDTH              (0x00000003UL)
#define BUS_WIDTH_1                 (0x00000000UL)
#define BUS_WIDTH_4                 (0x00000001UL)
#define BUS_WIDTH_8                 (0x00000002UL)

// SD_CONFIGURE2 0xb8010804
#define CRC7_CAL_DIS                (0x01UL<<7)
#define CRC16_CAL_DIS               (0x01UL<<6)
#define WAIT_WRT_CRC_TIMEOUT_EN     (0x01UL<<5)
#define IGNORE_WRT_CRC_ERR_EN       (0x01UL<<4)
#define WAIT_BUSY_EN                (0x01UL<<3)
#define CRC7_CHK_DIS                (0x01UL<<2)
#define RESP_TYPE_SHT               (0x00UL)
#define MASK_RESP_TYPE              (0x03UL<<RESP_TYPE_SHT)
#define RESP_TYPE_NON               (0x00UL<<RESP_TYPE_SHT)
#define RESP_TYPE_6B                (0x01UL<<RESP_TYPE_SHT)
#define RESP_TYPE_17B               (0x02UL<<RESP_TYPE_SHT)

// SD_CONFIGURE3 0xb8010808
#define DUMMY_REG0_SHT              (1)
#define MASK_DUMMY_REG0             (0xFEUL<<DUMMY_REG0_SHT)
#define CMD_RESP_TIMEOUT_EN         (0x01UL)

// SD_STATUS 0xb801080C
#define CRC7_STATUS                 (0x01UL<<7)
#define CRC16_STATUS                (0x01UL<<6)
#define WRT_ERR_BIT                 (0x01UL<<5)
#define WRT_ERR_STA_SHT             (2)
#define MASK_WRT_ERR_STA            (0x00000007UL<<WRT_ERR_STA_SHT)
#define WRT_STA_ACCEPT              (0x02UL<<WRT_ERR_STA_SHT)
#define WRT_STA_REJECT_CRC_ERR      (0x05UL<<WRT_ERR_STA_SHT)
#define WRT_STA_REJECT_WRT_ERR      (0x07UL<<WRT_ERR_STA_SHT)
#define WRT_CRC_TIMEOUT_ERR         (0x01UL<<1)
#define PATTERN_COMPARE_ERR         (0x01UL<<0)
#define MASK_SD_STAT_ERR            (CRC7_STATUS|CRC16_STATUS|WRT_ERR_BIT|WRT_CRC_TIMEOUT_ERR|PATTERN_COMPARE_ERR)

// SD_STATUS2 0xb8010810
#define RESP_TIMEOUT_ERR            (0x01UL<<0)

// SD_BUS_STATUS 0xb8010814
#define CLK_TOGGLE_EN               (0x01UL<<7)
#define CLK_TOGGLE_DIS_WHEN_ACT     (0x01UL<<6)
#define DAT3_LEVEL                  (0x01UL<<4)
#define DAT2_LEVEL                  (0x01UL<<3)
#define DAT1_LEVEL                  (0x01UL<<2)
#define DAT0_LEVEL                  (0x01UL<<1)
#define CMD_LEVEL                   (0x01UL<<0)

//SD_CMD_CODE          0xb8010818
#define DUMMY_REG1_SHT              (0)
#define MASK_DUMMY_REG1             (0xFEUL<<DUMMY_REG1_SHT)


//SD_SAMPLE_POINT_CTL  0xb801081C
#define SAMPLE_PT_TYP_DDR_DAT       (0x01UL<<7)
#define SAMPLE_PT_SEL_DDR_DAT       (0x01UL<<6)
#define SAMPLE_PT_TYP_DDR_CMD       (0x01UL<<5)
#define SAMPLE_PT_SEL_DDR_CMD       (0x01UL<<4)
#define SAMPLE_PT_SEL_SD20          (0x01UL<<3)

//SD_PUSH_POINT_CTL    0xb8010820
#define PUSH_PT_SEL_TYPE_DDR        (0x01UL<<7)
#define CMD_OR_DAT                  (0x01UL<<6)
#define PUSH_PT_SEL_DDR_DAT         (0x01UL<<5)
#define PUSH_PT_SEL_DDR_CMD         (0x01UL<<4)
#define PUSH_PT_SEL_SD20            (0x01UL<<3)
#define CLK_SOLUTION_DDR_SHT        (1)
#define MASK_CLK_SOLUTION_DDR       (0x03UL<<CLK_SOLUTION_DDR_SHT)
#define ANALOG_SOLUTION             (0x00UL<<CLK_SOLUTION_DDR_SHT)
#define DRIVER_SOLUTION             (0x02UL<<CLK_SOLUTION_DDR_SHT)
#define PROHIBITED                  (0x03UL<<CLK_SOLUTION_DDR_SHT)
#define CLK_SWAP                    (0x01UL<<0)

//SD_TRANSFER          0xb801084C
#define START_EN                    (0x01UL<<7)
#define END_STATE                   (0x01UL<<6)
#define STATE_MACH_IDLE             (0x01UL<<5)
#define ERR_BIT                     (0x01UL<<4)

#define CMD_CODE_SHT                (0)
#define MASK_CMD_CODE               (0x0F<<CMD_CODE_SHT)
#define SD_NORMALWRITE              (0x00<<CMD_CODE_SHT)
#define SD_AUTOWRITE3               (0x01<<CMD_CODE_SHT)
#define SD_AUTOWRITE4               (0x02<<CMD_CODE_SHT)
#define SD_AUTOREAD3                (0x05<<CMD_CODE_SHT)
#define SD_AUTOREAD4                (0x06<<CMD_CODE_SHT)
#define SD_SENDCMDGETRSP            (0x08<<CMD_CODE_SHT)
#define SD_AUTOWRITE1               (0x09<<CMD_CODE_SHT)
#define SD_AUTOWRITE2               (0x0A<<CMD_CODE_SHT)
#define SD_NORMALREAD               (0x0C<<CMD_CODE_SHT)
#define SD_AUTOREAD1                (0x0D<<CMD_CODE_SHT)
#define SD_AUTOREAD2                (0x0E<<CMD_CODE_SHT)
#define SD_TUNING                   (0x0F<<CMD_CODE_SHT)
#define SD_CMD_UNKNOW               (0xFF<<CMD_CODE_SHT)

//SD_DDR_CHK_START     0xb8010850
#define DET_CMD_ERR                 (0x01UL<<7)
#define FORCE_CMD1                  (0x01UL<<6)
#define FORCE_CMD0                  (0x01UL<<5)
#define CMD_START_BIT               (0x01UL<<4)
#define DET_DATA_ERR                (0x01UL<<3)
#define FORCE_DATA1                 (0x01UL<<2)
#define FORCE_DATA0                 (0x01UL<<1)
#define DATA_START_BIT              (0x01UL<<0)

//SD_CMD_STATE         0xb8010854
#define CMD_STATE_MACH_IDLE         (0x01UL<<7)
#define CMD_STATE_MACH_SHT          (0)
#define MASK_CMD_STATE_MACH         (0x0fUL<<CMD_STATE_MACH_SHT)
#define CMD_STA_MACH_IDLE           (0x00UL<<CMD_STATE_MACH_SHT)
#define CMD_STA_MACH_INIT           (0x08UL<<CMD_STATE_MACH_SHT)
#define CMD_STA_MACH_TX             (0x09UL<<CMD_STATE_MACH_SHT)
#define CMD_STA_MACH_TXCRC          (0x0aUL<<CMD_STATE_MACH_SHT)
#define CMD_STA_MACH_TXE            (0x0bUL<<CMD_STATE_MACH_SHT)
#define CMD_STA_MACH_WAIT           (0x01UL<<CMD_STATE_MACH_SHT)
#define CMD_STA_MACH_RX             (0x02UL<<CMD_STATE_MACH_SHT)
#define CMD_STA_MACH_RXCEC          (0x03UL<<CMD_STATE_MACH_SHT)
#define CMD_STA_MACH_RXE            (0x04UL<<CMD_STATE_MACH_SHT)
#define CMD_STA_MACH_END            (0x05UL<<CMD_STATE_MACH_SHT)
#define CMD_STA_MACH_BUSY           (0x0dUL<<CMD_STATE_MACH_SHT)

//SD_DATA_STATE        0xb8010858
#define DATA_STATE_MACH_IDLE        (0x01UL<<7)
#define DATA_STATE_MACH_SHT         (0)
#define MASK_DATA_STATE_MACH        (0x0fUL<<CMD_STATE_MACH_SHT)
#define DATA_STA_MACH_IDLE          (0x00UL<<CMD_STATE_MACH_SHT)
#define DATA_STA_MACH_INIT          (0x08UL<<CMD_STATE_MACH_SHT)
#define DATA_STA_MACH_TX            (0x09UL<<CMD_STATE_MACH_SHT)
#define DATA_STA_MACH_TXCRC         (0x0aUL<<CMD_STATE_MACH_SHT)
#define DATA_STA_MACH_TXE           (0x0bUL<<CMD_STATE_MACH_SHT)
#define DATA_STA_MACH_WAIT          (0x01UL<<CMD_STATE_MACH_SHT)
#define DATA_STA_MACH_RX            (0x02UL<<CMD_STATE_MACH_SHT)
#define DATA_STA_MACH_RXCEC         (0x03UL<<CMD_STATE_MACH_SHT)
#define DATA_STA_MACH_RXE           (0x04UL<<CMD_STATE_MACH_SHT)
#define DATA_STA_MACH_END           (0x05UL<<CMD_STATE_MACH_SHT)
#define DATA_STA_MACH_BUSY          (0x0dUL<<CMD_STATE_MACH_SHT)

//SD_BUS_TA_TIME       0xb801085C
#define TURN_AROUND_TIME_EN         (0x01UL<<3)
#define BUS_TA_TIME_SHT             (0)
#define MASK_TA_TIME                (0x07UL<<BUS_TA_TIME_SHT)

//SD_STOP_SDCLK_CFG    0xb8010860
#define STOP_SD20_CLK_CFG_EN        (0x01UL<<5)
#define STOP_SD20_CLK_CFG1          (0x01UL<<4)
#define STOP_SD20_CLK_CFG0          (0x01UL<<3)
#define STOP_SD30_CLK_CFG_EN        (0x01UL<<2)
#define STOP_SD30_CLK_CFG1          (0x01UL<<1)
#define STOP_SD30_CLK_CFG0          (0x01UL<<0)

//SD_AUTO_RST_FIFO     0xb8010864
#define AUTO_RST_FIFO_EN            (0x01UL<<0)

//SD_DAT_PAD           0xb8010868
#define AUTO_RST_FIFO_EN            (0x01UL<<0)

//SD_RW_STOP_CTL       0xb8010878
#define INFINITE_MODE_EN            (0x01UL<<2)
#define CONTROLLER_BUSY             (0x01UL<<1)
#define CONTROLLER_STOP             (0x01UL<<0)

//SD_WR_DELAY          0xb80108BC
#define WRITE_DELAY_SHT             (0)
#define MASK_WRITE_DELAY            (0x0fUL<<WRITE_DELAY_SHT)

//SD_RD_DELAY          0xb80108C0
#define READ_DELAY_SHT              (0)
#define MASK_READ_DELAY             (0x0fUL<<READ_DELAY_SHT)

//CR_DMA_PTR_STATUS    0xb80108D0
#define DMA_OUT_IDX_SHT             (16)
#define MASK_DMA_OUT_IDX            (0x3F<<DMA_OUT_IDX_SHT)
#define DMA_IN_IDX_SHT              (0)
#define MASK_DMA_IN_IDX             (0x3F<<DMA_IN_IDX_SHT)

//CR_INT_STATUS        0xb80108DC
#define RTKCR_INT_STOP_BY_KCPU      (0x01UL<<6)
#define RTKCR_INT_WRT_PROTEC        (0x01UL<<5)
#define RTKCR_INT_CARD_DETEC        (0x01UL<<4)
#define RTKCR_INT_DECODE_ERROR      (0x01UL<<2)
#define RTKCR_INT_DECODE_FINISH     (0x01UL<<1)
#define RTKCR_INT_STATUS_CHANGE     (0x01UL<<0)

#define RTKCR_INT_DEC_STA      (RTKCR_INT_DECODE_ERROR|RTKCR_INT_DECODE_FINISH)
#define RTKCR_INT_CARD_STA     (RTKCR_INT_CARD_DETEC|RTKCR_INT_STATUS_CHANGE)
#define RTKCR_INT_ALL_STA      (RTKCR_INT_DEC_STA|RTKCR_INT_CARD_STA)


//CR_INT_MASK          0xb80108E0
#define RTKCR_CARD_DET_MASK         (0x01UL<<3)
#define RTKCR_DECODE_ERR_MASK       (0x01UL<<2)
#define RTKCR_DECODE_FINISH_MASK    (0x01UL<<1)
#define RTKCR_CARD_STATUS_MASK      (0x01UL<<0)

#define RTKCR_INT_DEC_MASK      (RTKCR_DECODE_ERR_MASK|RTKCR_DECODE_FINISH_MASK)
#define RTKCR_INT_CARD_MASK     (RTKCR_CARD_DET_MASK|RTKCR_CARD_STATUS_MASK)
#define RTKCR_INT_ALL_MASK      ( RTKCR_INT_DEC_MASK|RTKCR_INT_CARD_MASK)

//CR_REG_MODE_CTRL     0xb80108E4
#define REG_STOP                    (0x01UL<<3)

//CR_CTRL              0xb8010918
#define ASIC_DBG_SEL_SHT            (24)
#define MASK_ASIC_DBG_SEL           (0x0fUL<<ASIC_DBG_SEL_SHT)
#define DBG_SEL_SHT                 (12)
#define MASK_DBG_SEL                (0xffUL<<DBG_SEL_SHT)
#define WRAP_DBG_SEL_SHT            (6)
#define MASK_WRAP_DBG_SEL           (0x03fUL<<WRAP_DBG_SEL_SHT)
#define MAP_SEL                     (0x01fUL<<5)     // data=0x12345678; 0: 0x8765,0x4321; 1:0x5678,0x1234
#define MASK_XFER_DIR               (0x01UL<<4)
#define DIR_READ                    (0x01UL<<4)
#define DIR_WRITE                   (0x00UL<<4)
#define BOOT_FROM_CR                (0x01UL<<3)
#define BUFF_TIMING_SHT             (1)
#define MASK_BUFF_TIMING            (0x03UL<<BUFF_TIMING_SHT)   //if value bigger the delay longer
#define BUFF_TIMING_0               (0x00UL<<BUFF_TIMING_SHT)
#define BUFF_TIMING_1               (0x01UL<<BUFF_TIMING_SHT)
#define BUFF_TIMING_2               (0x02UL<<BUFF_TIMING_SHT)
#define BUFF_TIMING_3               (0x03UL<<BUFF_TIMING_SHT)
#define CP_EN                       (0x01UL)

//CLK_PHASE_SEL        0xb8010924
#define PUSH_PHASE_SEL_SHT          (16)
#define MASK_PUSH_PHASE_SEL         (0xffUL<<PUSH_PHASE_SEL_SHT)
#define SAMP_PHASE_SEL_SHT          (0)
#define MASK_SAMP_PHASE_SEL         (0xffUL<<SAMP_PHASE_SEL_SHT)

//KCPU_SEL             0xb8010948
#define KCPU_LOCK_SRAM_MODE         (0x01UL<<3)
#define KCPU_FORCE_EN               (0x01UL<<2)
#define PR_CHK_EN                   (0x01UL<<1)
#define K_CPU_SEL                   (0x01UL<<0)

//CR_INT_STATUS_K      0xb8010954
#define INT_PR_HIT_K                (0x01UL<<3)
#define INT_DECODE_ERR_K            (0x01UL<<2)
#define INT_DECODE_FINISH_K         (0x01UL<<1)

//CR_INT_MASK_K        0xb8010958
#define PR_HIT_MASK_K               (0x01UL<<3)
#define DECODE_ERR_MASK_K           (0x01UL<<2)
#define DECODE_FINISH_MASK_K        (0x01UL<<1)

//KCPU_ST              0xb801095C
#define K_CPU_ST_SHT                (0)
#define MASK_K_CPU_ST               (0x03UL<<K_CPU_ST_SHT)

//SCPU_SEL             0xb8010970
#define S_CPU_SEL                   (0x01UL<<0)

//CPU_ST               0xb8010974
#define S_CPU_ST_SHT                (0)
#define MASK_S_CPU_ST               (0x03UL<<S_CPU_ST_SHT)
#define S_CPU_ST                    (0x01UL<<0)

//CR_INT_STATUS_FREE   0xb8010978
#define INT_STOP_BY_KCPU_FREE       (0x01UL<<6)
#define INT_WRT_PROTEC_FREE         (0x01UL<<5)
#define INT_CARD_DETEC_FREE         (0x01UL<<4)
#define INT_DECODE_ERROR_FREE       (0x01UL<<2)
#define INT_DECODE_FINISH_FREE      (0x01UL<<1)
#define INT_STATUS_CHANGE_FREE      (0x01UL<<0)

//PIN_CTRL             0xb801097C
#define CLK_INV                     (0x01UL<<16)
#define SEL_TAB_SHT                 (11)
#define MASK_SEL_TAB                (0x1fUL<<SEL_TAB_SHT)
#define SOURCE_SEL                  (0x01UL<<10)
#define PAD_PHASE_SEL_SHT           (0)
#define MASK_PAD_PHASE_SEL          (0xff<PAD_PHASE_SEL_SHT)
#define PAD_PHASE_DELAY0            (0x01<<7)
#define PAD_PHASE_DELAY1            (0x01<<6)
#define PAD_PHASE_DELAY2            (0x01<<5)
#define PAD_PHASE_DELAY3            (0x01<<4)
#define PAD_PHASE_DELAY4            (0x01<<3)
#define PAD_PHASE_DELAY5            (0x01<<2)
#define PAD_PHASE_DELAY6            (0x01<<1)
#define PAD_PHASE_DELAY7            (0x01<<0)

#endif



