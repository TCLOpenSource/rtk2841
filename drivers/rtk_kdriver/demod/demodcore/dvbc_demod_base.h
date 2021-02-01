#ifndef __DVBC_DEMOD_BASE_H
#define __DVBC_DEMOD_BASE_H

#include "foundation.h"

#ifdef __cplusplus
extern "C" {
#endif

#if 0
// Common Register Index
#define TV_REG_API_ID                           0
#define TV_REG_DEMOD_ID                         1
#define TV_REG_BUILD_ID                         2
#define TV_REG_CONTROL                          3   //Cmd Reg
#define TV_REG_STATE                            4
#define TV_REG_TUNER_FREQ                       5   //Cmd Reg
#define TV_REG_TUNER_BW                         6
#define TV_REG_TUNER_GRID_BASE                  7
#define TV_REG_TUNER_GRID_INCR                  8
#define TV_REG_NOTCH_FREQ                       9   //Cmd Reg
#define TV_REG_NOTCH_BW                         10
#define TV_REG_ACTIVE_TUNER_FREQ                11
#define TV_REG_ACTIVE_TUNER_BW                  12
#define TV_REG_ACTIVE_TUNER_GAIN                13
#define TV_REG_ACTIVE_TUNER_RSSI                14
#define TV_REG_AGC_PARAMS                       15
#define TV_REG_TSO_CONFIG                       16
#define TV_REG_TSO_CLK_RATE_MARGIN              17
#define TV_REG_TSO_CLK_RATE_MAX                 18
#define TV_REG_DEBUG_VECTOR_OP_SEL              19  //Cmd Reg
#define TV_REG_DEBUG_VECTOR_OP_PARAMS           20
#define TV_REG_DEBUG_VECTOR_TRANSFER_LEN        21
#define TV_REG_DEBUG_VECTOR_BUFF_PTR            22
#define TV_REG_DEBUG_VECTOR_BUFF_SIZE           23
#define TV_REG_ENSIGMA_SDK_LOGGING              24  //Cmd Reg
#define TV_REG_ENSIGMA_SDK_BUFF_PTR             25
#define TV_REG_ENSIGMA_SDK_BUFF_SIZE            26
#define TV_REG_LOCK_TIME                        27
#define TV_REG_TUNER_CFG_OVERRIDE               28
#define TV_REG_PFM_SET_IF_GAIN_CTRL             29
#define TV_REG_PFM_FLAGS                        30
#define TV_REG_PFM_IF_FREQ                      31
#define TV_REG_PFM_OVERRIDE                     32
#define TV_REG_PFM_IF_CLK_FREQUENCY             33
#define TV_REG_PFM_LDPC_CLK_FREQUENCY           34
#define TV_REG_PFM_UCC_CLK_FREQUENCY            35
#define TV_REG_PFM_MCU_CLK_FREQUENCY            36
#endif

// Common Register Setting
#define REALTEK_I_NOTCH_EN                                       0
#define REALTEK_I_NOTCH_FREQ                                     500000000
#define REALTEK_I_NOTCH_BW                                       1 //0~87
#define REALTEK_I_TS_DIS_MASK                                    0x00000001
#define REALTEK_I_TS_SERIAL_MASK                                 0x00000002
#define REALTEK_I_TS_CLK_PHASE_INV_MASK                          0x00000004
#define REALTEK_I_TS_PACKETS_188_MASK                            0x00000008
#define REALTEK_I_TS_CLOCK_GATE_MASK   0x00000020

// DVBC Demod Module Pre-Definition
typedef struct DVBC_DEMOD_MODULE_TAG DVBC_DEMOD_MODULE;

typedef enum _REALTEK_I_DVBC_QAM_MODE {
	DVBC_QAM_4,					///<   QPSK
	DVBC_QAM_16,				///<   16 QAM
	DVBC_QAM_32,				///<   32 QAM
	DVBC_QAM_64,				///<   64 QAM
	DVBC_QAM_128,				///<   128 QAM
	DVBC_QAM_256,				///<   256 QAM
	DVBC_QAM_512,				///<   512 QAM
	DVBC_QAM_1024,				///<   1024 QAM
	DVBC_QAM_AUTO
}REALTEK_I_DVBC_QAM_MODE;

typedef enum _REALTEK_I_DEMOD_DVBC_QAM_MODE {
	DVBC_DEMOD_QAM_16 = 0,
	DVBC_DEMOD_QAM_32,
	DVBC_DEMOD_QAM_64,
	DVBC_DEMOD_QAM_128,
	DVBC_DEMOD_QAM_256,
	DVBC_DEMOD_QAM_OTHER
}_REALTEK_I_DEMOD_DVBC_QAM_MODE;

typedef enum _REALTEK_I_DEMOD_TYPE{
    UCC_STANDARD_NOT_SIGNALLED = 0,
    UCC_STANDARD_DVBT,
    UCC_STANDARD_DVBH,
    UCC_STANDARD_ISDBT_1SEG,
    UCC_STANDARD_ISDBT_3SEG,
    UCC_STANDARD_ISDBT_13SEG,
    UCC_STANDARD_DAB,
    UCC_STANDARD_FM,
    UCC_STANDARD_ATSC,
    UCC_STANDARD_DVBC,
    UCC_STANDARD_J83B,
    UCC_STANDARD_ISDBC,
    UCC_STANDARD_DVBT2,
    UCC_STANDARD_DVBS,
    UCC_STANDARD_DVBS2,
    UCC_STANDARD_ISDBS,
    UCC_STANDARD_GB206,
    UCC_STANDARD_ATV,
    UCC_STANDARD_DVBC_ISDBC
}REALTEK_I_DEMOD_TYPE;

typedef enum _REALTEK_I_DEMOD_CTRL{
    TV_CMD_NULL = 0,
    TV_CMD_STOP,
    TV_CMD_DETECT,
    TV_CMD_RUN,
    TV_CMD_UPDATE_RSSI,
    TV_CMD_RESET_COUNTERS,
    TV_CMD_UPDATE_COUNTERS,
    TV_CMD_SET_AGC,
    TV_CMD_UPDATE_AGC,
    TV_CMD_QUERY_STATUS,
}REALTEK_I_DEMOD_CTRL;

typedef int
(*DVBC_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

typedef int
(*DVBC_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBC_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBC_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBC_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBC_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*DVBC_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*DVBC_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*DVBC_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*DVBC_DEMOD_FP_ADDR_8BIT_SET_REG_BITS)(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBC_DEMOD_FP_ADDR_16BIT_SET_REG_BITS)(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBC_DEMOD_FP_ADDR_8BIT_GET_REG_BITS)(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*DVBC_DEMOD_FP_ADDR_16BIT_GET_REG_BITS)(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*DVBC_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE)(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBC_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE)(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// Demod Register Access for 8-bit Address
typedef struct {
	DVBC_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE             SetRegPage;
	DVBC_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES            SetRegBytes;
	DVBC_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES            GetRegBytes;
	DVBC_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS        SetRegMaskBits;
	DVBC_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS        GetRegMaskBits;
	DVBC_DEMOD_FP_ADDR_8BIT_SET_REG_BITS             SetRegBits;
	DVBC_DEMOD_FP_ADDR_8BIT_GET_REG_BITS             GetRegBits;
	DVBC_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE   SetRegBitsWithPage;
	DVBC_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE   GetRegBitsWithPage;
}
DVBC_DEMOD_REG_ACCESS_ADDR_8BIT;

// Demod Register Access for 16-bit Address
typedef struct {
	DVBC_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES       SetRegBytes;
	DVBC_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES       GetRegBytes;
	DVBC_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS   SetRegMaskBits;
	DVBC_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS   GetRegMaskBits;
	DVBC_DEMOD_FP_ADDR_16BIT_SET_REG_BITS        SetRegBits;
	DVBC_DEMOD_FP_ADDR_16BIT_GET_REG_BITS        GetRegBits;
}
DVBC_DEMOD_REG_ACCESS_ADDR_16BIT;

typedef void
(*DVBC_DEMOD_FP_GET_DEMOD_TYPE)(
	DVBC_DEMOD_MODULE *pDemod,
	int *pDemodType
);

typedef void
(*DVBC_DEMOD_FP_GET_DEVICE_ADDR)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

typedef void
(*DVBC_DEMOD_FP_GET_CRYSTAL_FREQ_HZ)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

// Demod Common Function Pointer
typedef int
(*DVBC_DEMOD_FP_CHECK_RPU_READY)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

typedef int
(*DVBC_DEMOD_FP_PING_RPU)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

typedef int
(*DVBC_DEMOD_FP_SHUT_DOWN)(
	DVBC_DEMOD_MODULE *pDemod
);

typedef int
(*DVBC_DEMOD_FP_ACTIVATE_CORE)(
	DVBC_DEMOD_MODULE *pDemod
);

typedef int
(*DVBC_DEMOD_FP_DEACTIVATE_CORE)(
	DVBC_DEMOD_MODULE *pDemod
);

typedef int
(*DVBC_DEMOD_FP_SWITCH_TO_BUFFER)(
	DVBC_DEMOD_MODULE *pDemod
);

typedef int
(*DVBC_DEMOD_FP_GET_DEMOD_INFO)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

typedef int
(*DVBC_DEMOD_FP_GET_BUILD_ID)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

typedef int
(*DVBC_DEMOD_FP_DEMOD_CTRL_STOP)(
	DVBC_DEMOD_MODULE *pDemod
);

typedef int
(*DVBC_DEMOD_FP_DEMOD_CTRL_DETECT)(
	DVBC_DEMOD_MODULE *pDemod
);

typedef int
(*DVBC_DEMOD_FP_DEMOD_CTRL_RUN)(
	DVBC_DEMOD_MODULE *pDemod
);

typedef int
(*DVBC_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI)(
	DVBC_DEMOD_MODULE *pDemod
);

typedef int
(*DVBC_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS)(
	DVBC_DEMOD_MODULE *pDemod
);

typedef int
(*DVBC_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS)(
	DVBC_DEMOD_MODULE *pDemod
);

typedef int
(*DVBC_DEMOD_FP_DEMOD_CTRL_SET_AGC)(
	DVBC_DEMOD_MODULE *pDemod
);

typedef int
(*DVBC_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC)(
	DVBC_DEMOD_MODULE *pDemod
);

typedef int
(*DVBC_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS)(
	DVBC_DEMOD_MODULE *pDemod
);

typedef int
(*DVBC_DEMOD_FP_GET_DEMOD_STATUS)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

typedef int
(*DVBC_DEMOD_FP_SET_TUNER_FREQ)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

typedef int
(*DVBC_DEMOD_FP_SET_TUNER_BANDWIDTH)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

typedef int
(*DVBC_DEMOD_FP_SET_TUNER_GRID_BASE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

typedef int
(*DVBC_DEMOD_FP_SET_TUNER_GRID_INCR)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

typedef int
(*DVBC_DEMOD_FP_SET_NOTCH_FREQ)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

typedef int
(*DVBC_DEMOD_FP_SET_NOTCH_BANDWIDTH)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

typedef int
(*DVBC_DEMOD_FP_GET_ACT_TUNER_FREQ)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

typedef int
(*DVBC_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH)(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int *ActiveBandwidth
);

typedef int
(*DVBC_DEMOD_FP_GET_ACT_TUNER_GAIN)(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerGain
);

typedef int
(*DVBC_DEMOD_FP_GET_ACT_TUNER_RSSI)(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerRssi
);

typedef int
(*DVBC_DEMOD_FP_SET_AGC_PARAMS)(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int AgcParam,
    unsigned int Index
);

typedef int
(*DVBC_DEMOD_FP_GET_AGC_PARAMS)(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int *AgcParam,
    unsigned int Index
);

typedef int
(*DVBC_DEMOD_FP_SET_TS_CONFIG)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

typedef int
(*DVBC_DEMOD_FP_SET_TS_CLK_RATE_MARGIN)(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int TsClkMargin
);

typedef int
(*DVBC_DEMOD_FP_SET_TS_CLK_RATE_MAX)(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int TsClkRateMax
);

typedef int
(*DVBC_DEMOD_FP_GET_DEMOD_LOCK_TIME)(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int *DemodLockTimeMs
);

typedef int
(*DVBC_DEMOD_FP_SET_XML_TUNER_CFG_OVERRIDE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
);

typedef int
(*DVBC_DEMOD_FP_SET_XML_TUNER_GAIN_CTRL)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
);

typedef int
(*DVBC_DEMOD_FP_SET_XML_FLAGS)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int Flags
);

typedef int
(*DVBC_DEMOD_FP_SET_XML_IF_FREQ)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
);

typedef int
(*DVBC_DEMOD_FP_SET_XML_PLFT_CFG_OVERRIDE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
);

typedef int
(*DVBC_DEMOD_FP_SET_XML_IF_CLK)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int IfClk
);

typedef int
(*DVBC_DEMOD_FP_SET_XML_LDPC_CLK)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
);

typedef int
(*DVBC_DEMOD_FP_SET_XML_UCC_CLK)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int UccClk
);

typedef int
(*DVBC_DEMOD_FP_SET_XML_MCU_CLK)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int McuClk
);

typedef int
(*DVBC_DEMOD_FP_SET_VIRTUAL_REGISTER)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int RegVal
);

typedef int
(*DVBC_DEMOD_FP_GET_VIRTUAL_REGISTER)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int *RegVal
);

typedef int
(*DVBC_DEMOD_FP_SET_CTRL_VIRTUAL_REGISTER)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

typedef int
(*DVBC_DEMOD_FP_GET_CTRL_VIRTUAL_REGISTER)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);

typedef int
(*DVBC_DEMOD_FP_SET_HW_REG_VAL)(
	unsigned int Addr,
    unsigned int Val
);

typedef int
(*DVBC_DEMOD_FP_GET_HW_REG_VAL)(
	unsigned int Addr,
    unsigned int *Val
);


// DVBC Specific Function Pointer
typedef int
(*DVBC_DEMOD_FP_GET_SYSTEM_STATE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SystemState
);

typedef int
(*DVBC_DEMOD_FP_GET_COURSE_CARRIER_SYNC_SUB_STATE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SyncSubState
);

typedef int
(*DVBC_DEMOD_FP_GET_EQ_ADAPT_SUB_STATE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EqAdaptState
);

typedef int
(*DVBC_DEMOD_FP_GET_IS_NO_SIG)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *IsSignalFound
);

typedef int
(*DVBC_DEMOD_FP_GET_MON_SYMBOL_RATE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MonSymbolRate
);

typedef int
(*DVBC_DEMOD_FP_GET_MON_CARRIER_FREQ)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MonCarrierFreq
);

typedef int
(*DVBC_DEMOD_FP_GET_MON_QAM_SIZE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MonQamSize
);

typedef int
(*DVBC_DEMOD_FP_GET_MON_SPECTRUM_INV)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MonSpecInv
);

typedef int
(*DVBC_DEMOD_FP_GET_ACQ_TIME)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *AcqTime
);

typedef int
(*DVBC_DEMOD_FP_SET_ACQ_TIMER_RST)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int AcqTimerReset
);

typedef int
(*DVBC_DEMOD_FP_GET_ACQ_TIMER_RST)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *AcqTimerReset
);

typedef int
(*DVBC_DEMOD_FP_GET_EQ_OUTPUT_SNR)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EqOutSnr
);

typedef int
(*DVBC_DEMOD_FP_GET_TS_PKT_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *TsPacketNumber
);

typedef int
(*DVBC_DEMOD_FP_GET_BAD_PKT_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadPacketNumber
);

typedef int
(*DVBC_DEMOD_FP_GET_BYTE_ERR_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *ByteErrorNumber
);

typedef int
(*DVBC_DEMOD_FP_GET_BIT_ERR_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BitErrorNumber
);

typedef int
(*DVBC_DEMOD_FP_SET_BER_AVE_LEN)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BerAveLength
);

typedef int
(*DVBC_DEMOD_FP_GET_BER_AVE_LEN)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BerAveLength
);

typedef int
(*DVBC_DEMOD_FP_GET_RS_AVE_BER)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *RsBer
);

typedef int
(*DVBC_DEMOD_FP_GET_RS_AVE_PER)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *RsPer
);

typedef int
(*DVBC_DEMOD_FP_GET_EQ_AVE_SNR)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EqSnr
);

typedef int
(*DVBC_DEMOD_FP_SET_FAIL_CNT_RST)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int FailCntRst
);

typedef int
(*DVBC_DEMOD_FP_GET_FAIL_CNT_RST)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *FailCntRst
);

typedef int
(*DVBC_DEMOD_FP_GET_COAST_SYMBOL_TIMING_FAIL_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *CourseSymbolFailNum
);

typedef int
(*DVBC_DEMOD_FP_GET_FINE_SYMBIL_TIMING_FAIL_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *FineSymbolFailNum
);

typedef int
(*DVBC_DEMOD_FP_GET_CARRIER_SYNC_FAIL_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *CarrierSyncFailNum
);

typedef int
(*DVBC_DEMOD_FP_GET_QAM_SEARCH_FAIL_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *QamSearchFailNum
);

typedef int
(*DVBC_DEMOD_FP_GET_SPECTRUM_INV_SEARCH_FAIL_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SpecInvSearchFailNum
);

typedef int
(*DVBC_DEMOD_FP_GET_UN_SUPPORT_TS_RATE_FAIL_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *UnSuppTsRateFailNum
);

typedef int
(*DVBC_DEMOD_FP_GET_PER_FAIL_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *PerFailNum
);

typedef int
(*DVBC_DEMOD_FP_GET_SIG_DROP_FAIL_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SignalDropFailNum
);

typedef int
(*DVBC_DEMOD_FP_GET_LAST_FAIL_CASE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *LastFailCase
);

typedef int
(*DVBC_DEMOD_FP_SET_EN_QAM_SEARCH)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int EnQamSearch
);

typedef int
(*DVBC_DEMOD_FP_GET_EN_QAM_SEARCH)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EnQamSearch
);

typedef int
(*DVBC_DEMOD_FP_SET_FIX_QAM_SIZE)(
	DVBC_DEMOD_MODULE *pDemod,
	int QamMode
);

typedef int
(*DVBC_DEMOD_FP_GET_FIX_QAM_SIZE)(
	DVBC_DEMOD_MODULE *pDemod,
	int *QamMode
);

typedef int
(*DVBC_DEMOD_FP_SET_QAM_SEARCH_LIST)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int QamSearchList
);

typedef int
(*DVBC_DEMOD_FP_GET_QAM_SEARCH_LIST)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *QamSearchList
);

typedef int
(*DVBC_DEMOD_FP_SET_SR_SEARCH_MODE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int SrSearchMode
);

typedef int
(*DVBC_DEMOD_FP_GET_SR_SEARCH_MODE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SrSearchMode
);

typedef int
(*DVBC_DEMOD_FP_SET_FIX_SR)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int FixSymbolRate
);

typedef int
(*DVBC_DEMOD_FP_GET_FIX_SR)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *FixSymbolRate
);

typedef int
(*DVBC_DEMOD_FP_SET_SR_LIST)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int ListIndex,
	unsigned int ListSymbolRate
);

typedef int
(*DVBC_DEMOD_FP_GET_SR_LIST)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int ListIndex,
	unsigned int *ListSymbolRate
);

typedef int
(*DVBC_DEMOD_FP_SET_MIN_SR)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int MinSymbolRate
);

typedef int
(*DVBC_DEMOD_FP_GET_MIN_SR)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MinSymbolRate
);

typedef int
(*DVBC_DEMOD_FP_SET_MAX_SR)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int MaxSymbolRate
);

typedef int
(*DVBC_DEMOD_FP_GET_MAX_SR)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MaxSymbolRate
);

typedef int
(*DVBC_DEMOD_FP_SET_EN_SPECTRUM_INV_SEARCH)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int EnSpecInvSearch
);

typedef int
(*DVBC_DEMOD_FP_GET_EN_SPECTRUM_INV_SEARCH)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EnSpecInvSearch
);

typedef int
(*DVBC_DEMOD_FP_SET_FIX_SPECTRUM_MODE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int FixSpecInvMode
);

typedef int
(*DVBC_DEMOD_FP_GET_FIX_SPECTRUM_MODE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *FixSpecInvMode
);

typedef int
(*DVBC_DEMOD_FP_SET_BAD_PKT_BYTE_ERR_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BadPktByteErrNum
);

typedef int
(*DVBC_DEMOD_FP_GET_BAD_PKT_BYTE_ERR_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadPktByteErrNum
);

typedef int
(*DVBC_DEMOD_FP_SET_BAD_PKT_BIT_ERR_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BadPktBitErrNum
);

typedef int
(*DVBC_DEMOD_FP_GET_BAD_PKT_BIT_ERR_NUM)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadPktBitErrNum
);

typedef int
(*DVBC_DEMOD_FP_SET_BAD_SET_BAD_PKT_PERCENTAGE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BadSetBadPktPercentage
);

typedef int
(*DVBC_DEMOD_FP_GET_BAD_SET_BAD_PKT_PERCENTAGE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadSetBadPktPercentage
);

typedef int
(*DVBC_DEMOD_FP_SET_FAIL_ERR_RATE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BadSetBadPktPercentage
);

typedef int
(*DVBC_DEMOD_FP_GET_FAIL_ERR_RATE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadSetBadPktPercentage
);

typedef int
(*DVBC_DEMOD_FP_SET_PHASE_TRACK_LOOP_GAIN)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int QamMode,
	unsigned int PhaseTrackLoopGain
);

typedef int
(*DVBC_DEMOD_FP_GET_PHASE_TRACK_LOOP_GAIN)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int QamMode,
	unsigned int *PhaseTrackLoopGain
);

typedef int
(*DVBC_DEMOD_FP_SET_DAGC_POWER)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int DagcPower
);

typedef int
(*DVBC_DEMOD_FP_GET_DAGC_POWER)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *DagcPower
);

typedef int
(*DVBC_DEMOD_FP_SET_EQ_UPDATE_RATE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int EqUpdateRate
);

typedef int
(*DVBC_DEMOD_FP_GET_EQ_UPDATE_RATE)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EqUpdateRate
);

typedef int
(*DVBC_DEMOD_FP_GET_SIGNAL_SSI)(
	DVBC_DEMOD_MODULE *pDemod,
	int rf_level,
	unsigned char *ssi
);

typedef int
(*DVBC_DEMOD_FP_GET_SIGNAL_SQI)(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char *sqi
);

typedef int
(*DVBC_DEMOD_FP_UPDATE_FUNCTION)(
	DVBC_DEMOD_MODULE *pDemod
);

/// REALTEK_I DVBC extra module alias
typedef struct REALTEK_I_DVBC_EXTRA_MODULE REALTEK_I_DVBC_EXTRA_MODULE;

// REALTEK_I DVBC extra module
struct REALTEK_I_DVBC_EXTRA_MODULE {
	// Variables
	int ConfigMode;
	int ReAcquireCount;
};

// DVBC Demod Default I2C Functions for 8-bit Address
int
dvbc_demod_addr_8bit_default_SetRegPage(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

int
dvbc_demod_addr_8bit_default_SetRegBytes(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
dvbc_demod_addr_8bit_default_GetRegBytes(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
dvbc_demod_addr_8bit_default_SetRegMaskBits(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
dvbc_demod_addr_8bit_default_GetRegMaskBits(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
dvbc_demod_addr_8bit_default_SetRegBits(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
dvbc_demod_addr_8bit_default_GetRegBits(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

int
dvbc_demod_addr_8bit_default_SetRegBitsWithPage(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
dvbc_demod_addr_8bit_default_GetRegBitsWithPage(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// DVBC Demod Default I2C Functions for 16-bit Address
int
dvbc_demod_addr_16bit_default_SetRegBytes(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
dvbc_demod_addr_16bit_default_GetRegBytes(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
dvbc_demod_addr_16bit_default_SetRegMaskBits(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
dvbc_demod_addr_16bit_default_GetRegMaskBits(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
dvbc_demod_addr_16bit_default_SetRegBits(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
dvbc_demod_addr_16bit_default_GetRegBits(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// DVBC Demod Default Manipulating Functions
void
dvbc_demod_default_GetDemodType(
	DVBC_DEMOD_MODULE *pDemod,
	int *pDemodType
);

void
dvbc_demod_default_GetDeviceAddr(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

void
dvbc_demod_default_GetCrystalFreqHz(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

// Demod Common Function
int
realtek_i_dvbc_common_CheckRpuReady(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

int
realtek_i_dvbc_common_PingRpu(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

int
realtek_i_dvbc_common_ShutDown(
	DVBC_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbc_common_ActivateCore(
	DVBC_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbc_common_DeactivateCore(
	DVBC_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbc_common_SwitchToBuffer(
	DVBC_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbc_common_GetDemodInfo(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

int
realtek_i_dvbc_common_GetBuildId(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

int
realtek_i_dvbc_common_DemodCtrlStopCmd(
	DVBC_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbc_common_DemodCtrlDetectCmd(
	DVBC_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbc_common_DemodCtrlRunCmd(
	DVBC_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbc_common_DemodCtrlUpdateRssiCmd(
	DVBC_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbc_common_DemodCtrlResetCountersCmd(
	DVBC_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbc_common_DemodCtrlUpdateCountersCmd(
	DVBC_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbc_common_DemodCtrlSetAgcCmd(
	DVBC_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbc_common_DemodCtrlUpdateAgcCmd(
	DVBC_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbc_common_DemodCtrlQueryStatusCmd(
	DVBC_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbc_common_GetDemodStatus(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

int
realtek_i_dvbc_common_SetTunerFreqCmd(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

int
realtek_i_dvbc_common_SetTunerBandwidth(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

int
realtek_i_dvbc_common_SetTunerGridBase(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

int
realtek_i_dvbc_common_SetTunerGridIncr(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

int
realtek_i_dvbc_common_SetNotchFreqCmd(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

int
realtek_i_dvbc_common_SetNotchBandwidth(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

int
realtek_i_dvbc_common_GetActiveTunerFreq(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

int
realtek_i_dvbc_common_GetActiveTunerBandwidth(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int *ActiveBandwidth
);

int
realtek_i_dvbc_common_GetActiveTunerGain(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerGain
);

int
realtek_i_dvbc_common_GetActiveTunerRssi(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerRssi
);

int
realtek_i_dvbc_common_SetAgcParams(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int AgcParam,
    unsigned int Index
);

int
realtek_i_dvbc_common_GetAgcParams(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int *AgcParam,
    unsigned int Index
);

int
realtek_i_dvbc_common_SetTsConfig(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

int
realtek_i_dvbc_common_SetTsClkRateMargin(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int TsClkMargin
);

int
realtek_i_dvbc_common_SetTsClkRateMax(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int TsClkRateMax
);

int
realtek_i_dvbc_common_GetDemodLockTime(
	DVBC_DEMOD_MODULE *pDemod,
    unsigned int *DemodLockTimeMs
);

int
realtek_i_dvbc_common_SetHwRegValue(
	unsigned int Addr,
    unsigned int Val
);

int
realtek_i_dvbc_common_GetHwRegValue(
	unsigned int Addr,
    unsigned int *Val
);

int
realtek_i_dvbc_common_SetXmlTunerCfgOverride(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
);

int
realtek_i_dvbc_common_SetXmlTunerGainCtrl(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
);

int
realtek_i_dvbc_common_SetXmlFlags(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int Flags
);

int
realtek_i_dvbc_common_SetXmlIfFreq(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
);

int
realtek_i_dvbc_common_SetXmlPlatformCfgOverride(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
);

int
realtek_i_dvbc_common_SetXmlIfClk(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int IfClk
);

int
realtek_i_dvbc_common_SetXmlLdpcClk(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
);

int
realtek_i_dvbc_common_SetXmlUccClk(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int UccClk
);

int
realtek_i_dvbc_common_SetXmlMcuClk(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int McuClk
);

int
realtek_i_dvbc_common_SetVirtualRegister(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int RegVal
);

int
realtek_i_dvbc_common_GetVirtualRegister(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int *RegVal
);

int
realtek_i_dvbc_common_SetCtrlVirtualRegister(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

int
realtek_i_dvbc_common_GetCtrlVirtualRegister(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);


// DVBC Demod Module Structure
struct DVBC_DEMOD_MODULE_TAG {
	// Private Variables
	int           DemodType;
	unsigned char DeviceAddr;
	unsigned long CrystalFreqHz;
	int           TsInterfaceMode;

	int           QamMode;
	unsigned long SymbolRateHz;
	int           AlphaMode;
	unsigned long IfFreqHz;
	int           SpectrumMode;
    unsigned long TunerFreqHz;//Hz
    //REALTEK_I_TV_SYSTEM DemodSystem;

	int           IsQamModeSet;
	int           IsSymbolRateHzSet;
	int           IsAlphaModeSet;
	int           IsIfFreqHzSet;
	int           IsSpectrumModeSet;
	
	union {										
		REALTEK_I_DVBC_EXTRA_MODULE  RealtekIDvbc;
	}
	Extra;
	
	BASE_INTERFACE_MODULE *pBaseInterface;
	I2C_BRIDGE_MODULE *pI2cBridge;

	// Demod I2C Function Pointers
	union {
		DVBC_DEMOD_REG_ACCESS_ADDR_8BIT  Addr8Bit;
		DVBC_DEMOD_REG_ACCESS_ADDR_16BIT Addr16Bit;
	}
	RegAccess;

	// Demod Manipulating Function Pointers
	DVBC_DEMOD_FP_GET_DEMOD_TYPE                GetDemodType;
	DVBC_DEMOD_FP_GET_DEVICE_ADDR               GetDeviceAddr;
	DVBC_DEMOD_FP_GET_CRYSTAL_FREQ_HZ           GetCrystalFreqHz;

    // Common TV Api
    DVBC_DEMOD_FP_CHECK_RPU_READY               CheckRpuReady;
    DVBC_DEMOD_FP_PING_RPU                      PingRpu;
    DVBC_DEMOD_FP_SHUT_DOWN                     ShutDown;
    DVBC_DEMOD_FP_ACTIVATE_CORE                 ActivateCore;
    DVBC_DEMOD_FP_DEACTIVATE_CORE               DeactivateCore;
    DVBC_DEMOD_FP_SWITCH_TO_BUFFER		SwitchToBuffer;
    
    DVBC_DEMOD_FP_GET_DEMOD_INFO                GetDemodInfo;
    DVBC_DEMOD_FP_GET_BUILD_ID                  GetBuildId;
    DVBC_DEMOD_FP_DEMOD_CTRL_STOP               DemodCtrlStop;
    DVBC_DEMOD_FP_DEMOD_CTRL_DETECT             DemodCtrlDetect;
    DVBC_DEMOD_FP_DEMOD_CTRL_RUN                DemodCtrlRun;
    DVBC_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI        DemodCtrlUpdateRssi;
    DVBC_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS     DemodCtrlResetCounters;
    DVBC_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS    DemodCtrlUpdateCounters;
    DVBC_DEMOD_FP_DEMOD_CTRL_SET_AGC            DemodCtrlSetAgc;
    DVBC_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC         DemodCtrlUpdateAgc;
    DVBC_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS       DemodCtrlQueryStatus;
    DVBC_DEMOD_FP_GET_DEMOD_STATUS              GetDemodStatus;

    DVBC_DEMOD_FP_SET_TUNER_FREQ                SetTunerFreq;
    DVBC_DEMOD_FP_SET_TUNER_BANDWIDTH           SetTunerBandwidth;
    DVBC_DEMOD_FP_SET_TUNER_GRID_BASE           SetTunerGridBase;
    DVBC_DEMOD_FP_SET_TUNER_GRID_INCR           SetTunerGridIncr;
    DVBC_DEMOD_FP_SET_NOTCH_FREQ                SetNotchFreq;
    DVBC_DEMOD_FP_SET_NOTCH_BANDWIDTH           SetNotchBandwidth;
    DVBC_DEMOD_FP_GET_ACT_TUNER_FREQ            GetActiveTunerFreq;
    DVBC_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH       GetActiveTunerBandwidth;
    DVBC_DEMOD_FP_GET_ACT_TUNER_GAIN            GetActiveTunerGain;
    DVBC_DEMOD_FP_GET_ACT_TUNER_RSSI            GetActiveTunerRssi;
    DVBC_DEMOD_FP_SET_AGC_PARAMS                SetAgcParams;
    DVBC_DEMOD_FP_GET_AGC_PARAMS                GetAgcParams;
    DVBC_DEMOD_FP_SET_TS_CONFIG                 SetTsConfig;
    DVBC_DEMOD_FP_SET_TS_CLK_RATE_MARGIN        SetTsClkRateMargin;
    DVBC_DEMOD_FP_SET_TS_CLK_RATE_MAX           SetTsClkRateMax;
    DVBC_DEMOD_FP_GET_DEMOD_LOCK_TIME           GetDemodLockTime;
    DVBC_DEMOD_FP_SET_XML_TUNER_CFG_OVERRIDE    SetXmlTunerCfgOverride;
    DVBC_DEMOD_FP_SET_XML_TUNER_GAIN_CTRL       SetXmlTunerGainCtrl;
    DVBC_DEMOD_FP_SET_XML_FLAGS                 SetXmlFlags;
    DVBC_DEMOD_FP_SET_XML_IF_FREQ               SetXmlIfFreq;
    DVBC_DEMOD_FP_SET_XML_PLFT_CFG_OVERRIDE     SetXmlPlftCfgOverride;
    DVBC_DEMOD_FP_SET_XML_IF_CLK                SetXmlIfClk;
    DVBC_DEMOD_FP_SET_XML_LDPC_CLK              SetXmlLdpcClk;
    DVBC_DEMOD_FP_SET_XML_UCC_CLK               SetXmlUccClk;
    DVBC_DEMOD_FP_SET_XML_MCU_CLK               SetXmlMcuClk;
    DVBC_DEMOD_FP_SET_VIRTUAL_REGISTER          SetVirtualRegister;
    DVBC_DEMOD_FP_GET_VIRTUAL_REGISTER          GetVirtualRegister;
    DVBC_DEMOD_FP_SET_CTRL_VIRTUAL_REGISTER     SetCtrlVirtualRegister;
    DVBC_DEMOD_FP_GET_CTRL_VIRTUAL_REGISTER     GetCtrlVirtualRegister;
    DVBC_DEMOD_FP_SET_HW_REG_VAL                SetHwRegValue;
    DVBC_DEMOD_FP_GET_HW_REG_VAL                GetHwRegValue;

    // DVBC Specific Api
    DVBC_DEMOD_FP_GET_SYSTEM_STATE                      GetSystemState;
    DVBC_DEMOD_FP_GET_COURSE_CARRIER_SYNC_SUB_STATE     GetCoarseCarrierSyncSubState;
    DVBC_DEMOD_FP_GET_EQ_ADAPT_SUB_STATE                GetEqAdaptationSubState;
    DVBC_DEMOD_FP_GET_IS_NO_SIG                         GetIsNoSignal;
    DVBC_DEMOD_FP_GET_MON_SYMBOL_RATE                   GetMonitorSymbolRate;
    DVBC_DEMOD_FP_GET_MON_CARRIER_FREQ                  GetMonitorCarrierFrequency;
    DVBC_DEMOD_FP_GET_MON_QAM_SIZE                      GetMonitorQamSize;
    DVBC_DEMOD_FP_GET_MON_SPECTRUM_INV                  GetMonitorSpectrumInversion;
    DVBC_DEMOD_FP_GET_ACQ_TIME                          GetAcquisitionTime;
    DVBC_DEMOD_FP_SET_ACQ_TIMER_RST                     SetAcquisitionTimerReset;
    DVBC_DEMOD_FP_GET_ACQ_TIMER_RST                     GetAcquisitionTimerReset;
    DVBC_DEMOD_FP_GET_EQ_OUTPUT_SNR                     GetEqOutputSnr;
    DVBC_DEMOD_FP_GET_TS_PKT_NUM                        GetTsPacketNumber;
    DVBC_DEMOD_FP_GET_BAD_PKT_NUM                       GetBadPacketNumber;
    DVBC_DEMOD_FP_GET_BYTE_ERR_NUM                      GetByteErrorNumber;
    DVBC_DEMOD_FP_GET_BIT_ERR_NUM                       GetBitErrorNumber;
    DVBC_DEMOD_FP_SET_BER_AVE_LEN                       SetBerAveLength;
    DVBC_DEMOD_FP_GET_BER_AVE_LEN                       GetBerAveLength;
    DVBC_DEMOD_FP_GET_RS_AVE_BER                        GetRsAveBer;
    DVBC_DEMOD_FP_GET_RS_AVE_PER                        GetRsAvePer;
    DVBC_DEMOD_FP_GET_EQ_AVE_SNR                        GetEqAveSnr;
    DVBC_DEMOD_FP_SET_FAIL_CNT_RST                      SetFailCounterReset;
    DVBC_DEMOD_FP_GET_FAIL_CNT_RST                      GetFailCounterReset;
    DVBC_DEMOD_FP_GET_COAST_SYMBOL_TIMING_FAIL_NUM     GetCoastSymbolTimingFailNumber;
    DVBC_DEMOD_FP_GET_FINE_SYMBIL_TIMING_FAIL_NUM       GetFineSymbolTimingFailNumber;
    DVBC_DEMOD_FP_GET_CARRIER_SYNC_FAIL_NUM             GetCarrierSyncFailNumber;
    DVBC_DEMOD_FP_GET_QAM_SEARCH_FAIL_NUM               GetQamSearchFailNumber;
    DVBC_DEMOD_FP_GET_SPECTRUM_INV_SEARCH_FAIL_NUM      GetSpectrumInversionSearchFailNumber;
    DVBC_DEMOD_FP_GET_UN_SUPPORT_TS_RATE_FAIL_NUM       GetUnSupportTsRateFailNumber;
    DVBC_DEMOD_FP_GET_PER_FAIL_NUM                      GetPerFailNumber;
    DVBC_DEMOD_FP_GET_SIG_DROP_FAIL_NUM                 GetSignalDropoutFailNumber;
    DVBC_DEMOD_FP_GET_LAST_FAIL_CASE                    GetLastFailCase;
    DVBC_DEMOD_FP_SET_EN_QAM_SEARCH                     SetEnableQamSearch;
    DVBC_DEMOD_FP_GET_EN_QAM_SEARCH                     GetEnableQamSearch;
    DVBC_DEMOD_FP_SET_FIX_QAM_SIZE                      SetFixQamSize;
    DVBC_DEMOD_FP_GET_FIX_QAM_SIZE                      GetFixQamSize;
    DVBC_DEMOD_FP_SET_QAM_SEARCH_LIST                   SetQamSearchList;
    DVBC_DEMOD_FP_GET_QAM_SEARCH_LIST                   GetQamSearchList;
    DVBC_DEMOD_FP_SET_SR_SEARCH_MODE                    SetSymbolRateSearchMode;
    DVBC_DEMOD_FP_GET_SR_SEARCH_MODE                    GetSymbolRateSearchMode;
    DVBC_DEMOD_FP_SET_FIX_SR                            SetFixSymbolRate;
    DVBC_DEMOD_FP_GET_FIX_SR                            GetFixSymbolRate;
    DVBC_DEMOD_FP_SET_SR_LIST                           SetSymbolRateList;
    DVBC_DEMOD_FP_GET_SR_LIST                           GetSymbolRateList;
    DVBC_DEMOD_FP_SET_MIN_SR                            SetMinSymbolRate;
    DVBC_DEMOD_FP_GET_MIN_SR                            GetMinSymbolRate;
    DVBC_DEMOD_FP_SET_MAX_SR                            SetMaxSymbolRate;
    DVBC_DEMOD_FP_GET_MAX_SR                            GetMaxSymbolRate;
    DVBC_DEMOD_FP_SET_EN_SPECTRUM_INV_SEARCH            SetEnableSpectrumInversionSearch;
    DVBC_DEMOD_FP_GET_EN_SPECTRUM_INV_SEARCH            GetEnableSpectrumInversionSearch;
    DVBC_DEMOD_FP_SET_FIX_SPECTRUM_MODE                 SetFixSpectrumInverseMode;
    DVBC_DEMOD_FP_GET_FIX_SPECTRUM_MODE                 GetFixSpectrumInverseMode;
    DVBC_DEMOD_FP_SET_BAD_PKT_BYTE_ERR_NUM              SetBadPacketByteErrorNumber;
    DVBC_DEMOD_FP_GET_BAD_PKT_BYTE_ERR_NUM              GetBadPacketByteErrorNumber;
    DVBC_DEMOD_FP_SET_BAD_PKT_BIT_ERR_NUM               SetBadPacketBitErrorNumber;
    DVBC_DEMOD_FP_GET_BAD_PKT_BIT_ERR_NUM               GetBadPacketBitErrorNumber;
    DVBC_DEMOD_FP_SET_BAD_SET_BAD_PKT_PERCENTAGE        SetBadSetBadPacketPercentage;
    DVBC_DEMOD_FP_GET_BAD_SET_BAD_PKT_PERCENTAGE        GetBadSetBadPacketPercentage;
    DVBC_DEMOD_FP_SET_FAIL_ERR_RATE                     SetFailErrorRate;
    DVBC_DEMOD_FP_GET_FAIL_ERR_RATE                     GetFailErrorRate;
    DVBC_DEMOD_FP_SET_PHASE_TRACK_LOOP_GAIN             SetPhaseTrackerLoopGain;
    DVBC_DEMOD_FP_GET_PHASE_TRACK_LOOP_GAIN             GetPhaseTrackerLoopGain;
    DVBC_DEMOD_FP_SET_DAGC_POWER                        SetDagcPower;
    DVBC_DEMOD_FP_GET_DAGC_POWER                        GetDagcPower;
    DVBC_DEMOD_FP_SET_EQ_UPDATE_RATE                    SetEqUpdateRate;
    DVBC_DEMOD_FP_GET_EQ_UPDATE_RATE                    GetEqUpdateRate;
    DVBC_DEMOD_FP_GET_SIGNAL_SSI				GetSignalSSI;
    DVBC_DEMOD_FP_GET_SIGNAL_SQI				GetSignalSQI;
    DVBC_DEMOD_FP_UPDATE_FUNCTION				UpdateFunction;
};

#define REALTEK_I_DVBC_BASE_PRINT_LVL_DBG      0
#define REALTEK_I_DVBC_BASE_PRINT_LVL_INFO     1
#define REALTEK_I_DVBC_BASE_PRINT_LVL_WARNING  2


#ifndef REALTEK_I_DVBC_BASE_PRINT_LVL
#define REALTEK_I_DVBC_BASE_PRINT_LVL          REALTEK_I_DVBC_BASE_PRINT_LVL_INFO
#endif

#define REALTEK_I_DVBC_BASE_DBG(fmt, args...)         rtd_printk(KERN_DEBUG, "DEMO", "DVBC_BASE_DEBUG, " fmt, ##args);
#define REALTEK_I_DVBC_BASE_INFO(fmt, args...)       rtd_printk(KERN_INFO, "DEMO", "DVBC_BASE_INFO, " fmt, ##args);
#define REALTEK_I_DVBC_BASE_WARNING(fmt, args...)    rtd_printk(KERN_WARNING, "DEMO", "DVBC_BASE_WARNING, " fmt, ##args);


#ifdef __cplusplus
}
#endif
#endif
