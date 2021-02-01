#ifndef __DVBT_DEMOD_BASE_H
#define __DVBT_DEMOD_BASE_H

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

// DVBT Demod Module Pre-Definition
typedef struct DVBT_DEMOD_MODULE_TAG DVBT_DEMOD_MODULE;

typedef enum _REALTEK_I_DVBT_QAM_MODE {
	DVBT_QAM_4,				///<   QPSK
	DVBT_QAM_16,			///<   16 QAM
	DVBT_QAM_64				///<   64 QAM
}REALTEK_I_DVBT_QAM_MODE;

typedef enum _REALTEK_I_DEMOD_DVBT_QAM_MODE {
	DVBT_DEMOD_QAM_4 = 0,
	DVBT_DEMOD_QAM_16,
//	DVBT_DEMOD_QAM_32,
	DVBT_DEMOD_QAM_64,
//	DVBT_DEMOD_QAM_128,
//	DVBT_DEMOD_QAM_256,
	DVBT_DEMOD_QAM_OTHER
}_REALTEK_I_DEMOD_DVBT_QAM_MODE;

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
(*DVBT_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

typedef int
(*DVBT_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBT_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBT_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBT_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBT_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*DVBT_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*DVBT_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*DVBT_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*DVBT_DEMOD_FP_ADDR_8BIT_SET_REG_BITS)(
	DVBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBT_DEMOD_FP_ADDR_16BIT_SET_REG_BITS)(
	DVBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBT_DEMOD_FP_ADDR_8BIT_GET_REG_BITS)(
	DVBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*DVBT_DEMOD_FP_ADDR_16BIT_GET_REG_BITS)(
	DVBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*DVBT_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE)(
	DVBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBT_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE)(
	DVBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// Demod Register Access for 8-bit Address
typedef struct {
	DVBT_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE             SetRegPage;
	DVBT_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES            SetRegBytes;
	DVBT_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES            GetRegBytes;
	DVBT_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS        SetRegMaskBits;
	DVBT_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS        GetRegMaskBits;
	DVBT_DEMOD_FP_ADDR_8BIT_SET_REG_BITS             SetRegBits;
	DVBT_DEMOD_FP_ADDR_8BIT_GET_REG_BITS             GetRegBits;
	DVBT_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE   SetRegBitsWithPage;
	DVBT_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE   GetRegBitsWithPage;
}
DVBT_DEMOD_REG_ACCESS_ADDR_8BIT;

// Demod Register Access for 16-bit Address
typedef struct {
	DVBT_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES       SetRegBytes;
	DVBT_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES       GetRegBytes;
	DVBT_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS   SetRegMaskBits;
	DVBT_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS   GetRegMaskBits;
	DVBT_DEMOD_FP_ADDR_16BIT_SET_REG_BITS        SetRegBits;
	DVBT_DEMOD_FP_ADDR_16BIT_GET_REG_BITS        GetRegBits;
}
DVBT_DEMOD_REG_ACCESS_ADDR_16BIT;

typedef void
(*DVBT_DEMOD_FP_GET_DEMOD_TYPE)(
	DVBT_DEMOD_MODULE *pDemod,
	int *pDemodType
);

typedef void
(*DVBT_DEMOD_FP_GET_DEVICE_ADDR)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

typedef void
(*DVBT_DEMOD_FP_GET_CRYSTAL_FREQ_HZ)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

// Demod Common Function Pointer
typedef int
(*DVBT_DEMOD_FP_CHECK_RPU_READY)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

typedef int
(*DVBT_DEMOD_FP_PING_RPU)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

typedef int
(*DVBT_DEMOD_FP_SHUT_DOWN)(
	DVBT_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT_DEMOD_FP_ACTIVATE_CORE)(
	DVBT_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT_DEMOD_FP_DEACTIVATE_CORE)(
	DVBT_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT_DEMOD_FP_SWITCH_TO_BUFFER)(
	DVBT_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT_DEMOD_FP_GET_DEMOD_INFO)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

typedef int
(*DVBT_DEMOD_FP_GET_BUILD_ID)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

typedef int
(*DVBT_DEMOD_FP_DEMOD_CTRL_STOP)(
	DVBT_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT_DEMOD_FP_DEMOD_CTRL_DETECT)(
	DVBT_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT_DEMOD_FP_DEMOD_CTRL_RUN)(
	DVBT_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI)(
	DVBT_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS)(
	DVBT_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS)(
	DVBT_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT_DEMOD_FP_DEMOD_CTRL_SET_AGC)(
	DVBT_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC)(
	DVBT_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS)(
	DVBT_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT_DEMOD_FP_GET_DEMOD_STATUS)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

typedef int
(*DVBT_DEMOD_FP_SET_TUNER_FREQ)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

typedef int
(*DVBT_DEMOD_FP_SET_TUNER_BANDWIDTH)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

typedef int
(*DVBT_DEMOD_FP_SET_TUNER_GRID_BASE)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

typedef int
(*DVBT_DEMOD_FP_SET_TUNER_GRID_INCR)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

typedef int
(*DVBT_DEMOD_FP_SET_NOTCH_FREQ)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

typedef int
(*DVBT_DEMOD_FP_SET_NOTCH_BANDWIDTH)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

typedef int
(*DVBT_DEMOD_FP_GET_ACT_TUNER_FREQ)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

typedef int
(*DVBT_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *ActiveBandwidth
);

typedef int
(*DVBT_DEMOD_FP_GET_ACT_TUNER_GAIN)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerGain
);

typedef int
(*DVBT_DEMOD_FP_GET_ACT_TUNER_RSSI)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerRssi
);

typedef int
(*DVBT_DEMOD_FP_SET_AGC_PARAMS)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int AgcParam,
    unsigned int Index
);

typedef int
(*DVBT_DEMOD_FP_GET_AGC_PARAMS)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *AgcParam,
    unsigned int Index
);

typedef int
(*DVBT_DEMOD_FP_SET_TS_CONFIG)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

typedef int
(*DVBT_DEMOD_FP_SET_TS_CLK_RATE_MARGIN)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int TsClkMargin
);

typedef int
(*DVBT_DEMOD_FP_SET_TS_CLK_RATE_MAX)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int TsClkRateMax
);

typedef int
(*DVBT_DEMOD_FP_GET_DEMOD_LOCK_TIME)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *DemodLockTimeMs
);

typedef int
(*DVBT_DEMOD_FP_SET_XML_TUNER_CFG_OVERRIDE)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
);

typedef int
(*DVBT_DEMOD_FP_SET_XML_TUNER_GAIN_CTRL)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
);

typedef int
(*DVBT_DEMOD_FP_SET_XML_FLAGS)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int Flags
);

typedef int
(*DVBT_DEMOD_FP_SET_XML_IF_FREQ)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
);

typedef int
(*DVBT_DEMOD_FP_SET_XML_PLFT_CFG_OVERRIDE)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
);

typedef int
(*DVBT_DEMOD_FP_SET_XML_IF_CLK)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int IfClk
);

typedef int
(*DVBT_DEMOD_FP_SET_XML_LDPC_CLK)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
);

typedef int
(*DVBT_DEMOD_FP_SET_XML_UCC_CLK)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int UccClk
);

typedef int
(*DVBT_DEMOD_FP_SET_XML_MCU_CLK)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int McuClk
);

typedef int
(*DVBT_DEMOD_FP_SET_VIRTUAL_REGISTER)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int RegVal
);

typedef int
(*DVBT_DEMOD_FP_GET_VIRTUAL_REGISTER)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int *RegVal
);

typedef int
(*DVBT_DEMOD_FP_SET_CTRL_VIRTUAL_REGISTER)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

typedef int
(*DVBT_DEMOD_FP_GET_CTRL_VIRTUAL_REGISTER)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);

// DVBT Specific Function Pointer
typedef int
(*DVBT_DEMOD_FP_SET_DETECT_MASK)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int DetectMask
);

typedef int
(*DVBT_DEMOD_FP_GET_DETECT_MASK)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *DetectMask
);

typedef int
(*DVBT_DEMOD_FP_SET_TUN_FFT)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int TunFft
);

typedef int
(*DVBT_DEMOD_FP_GET_TUN_FFT)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *TunFft
);

typedef int
(*DVBT_DEMOD_FP_SET_TUN_GUARD)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int TunGuard
);

typedef int
(*DVBT_DEMOD_FP_GET_TUN_GUARD)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *TunGuard
);

typedef int
(*DVBT_DEMOD_FP_SET_TUN_MOD)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int TunMod
);

typedef int
(*DVBT_DEMOD_FP_GET_TUN_MOD)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *TunMod
);

typedef int
(*DVBT_DEMOD_FP_SET_TUN_CODE_RATE)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int TunCodeRate
);

typedef int
(*DVBT_DEMOD_FP_GET_TUN_CODE_RATE)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *TunCodeRate
);

typedef int
(*DVBT_DEMOD_FP_SET_TUN_ALPHA)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int TunAlpha
);

typedef int
(*DVBT_DEMOD_FP_GET_TUN_ALPHA)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *TunAlpha
);

typedef int
(*DVBT_DEMOD_FP_SET_TUN_INTERLEAVER)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int TunInterleaver
);

typedef int
(*DVBT_DEMOD_FP_GET_TUN_INTERLEAVER)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *TunInterleaver
);

typedef int
(*DVBT_DEMOD_FP_SET_TUN_HIERARCHICAL)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int TunHierarchical
);

typedef int
(*DVBT_DEMOD_FP_GET_TUN_HIERARCHICAL)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *TunHierarchical
);

typedef int
(*DVBT_DEMOD_FP_SET_TUN_SPECT_INV)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int TunSpectInv
);

typedef int
(*DVBT_DEMOD_FP_GET_TUN_SPECT_INV)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *TunSpectInv
);

typedef int
(*DVBT_DEMOD_FP_SET_CALIB_CTRL_CMD)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int CalibCtrl
);

typedef int
(*DVBT_DEMOD_FP_SET_CALIB_XTAL_OFFSET)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int CalibXtalOffset
);

typedef int
(*DVBT_DEMOD_FP_GET_CALIB_XTAL_OFFSET)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *CalibXtalOffset
);

typedef int
(*DVBT_DEMOD_FP_SET_STAT_CTRL_CMD)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int StatCtrl
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_UPDATA)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatUpdata
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_SSI)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatSsi
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_SNR)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatSnr
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_CARRIER_OFFSET)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatCarrierOffset
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_TS_PKT_COUNT)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatTsPktCount
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_TS_BAD_PKT_COUNT)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatTsBadPktCount
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_TS_BYTE_ERRS)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatTsByteErrs
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_TS_BIT_ERRS)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatTsBitErrs
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_VITERBI_BER)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatViterbiBer
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_TS_SYNC)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatTsSync
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_TPS_SYNC)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatTpsSync
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_IF_AGC_LEVEL)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatIfAgcLevel
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_NUM_REAQC)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatNumReaqc
);

typedef int
(*DVBT_DEMOD_FP_GET_STAT_ACI_DETECT)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *StatAciDetect
);

typedef int
(*DVBT_DEMOD_FP_SET_BER_PERIOD)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int BerPeriod
);

typedef int
(*DVBT_DEMOD_FP_GET_BER_PERIOD)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *BerPeriod
);

typedef int
(*DVBT_DEMOD_FP_GET_BER_UPDATE)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *BerUpdate
);

typedef int
(*DVBT_DEMOD_FP_GET_BER_RS_BER)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *BerRsBer
);

typedef int
(*DVBT_DEMOD_FP_GET_BER_TS_PER)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *BerTsPer
);

typedef int
(*DVBT_DEMOD_FP_GET_BER_SQI)(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *BerSqi
);

typedef int
(*DVBT_DEMOD_FP_GET_IF_AGC_GAIN)(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
);


// DVBT Demod Default I2C Functions for 8-bit Address
int
dvbt_demod_addr_8bit_default_SetRegPage(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

int
dvbt_demod_addr_8bit_default_SetRegBytes(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
dvbt_demod_addr_8bit_default_GetRegBytes(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
dvbt_demod_addr_8bit_default_SetRegMaskBits(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
dvbt_demod_addr_8bit_default_GetRegMaskBits(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
dvbt_demod_addr_8bit_default_SetRegBits(
	DVBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
dvbt_demod_addr_8bit_default_GetRegBits(
	DVBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

int
dvbt_demod_addr_8bit_default_SetRegBitsWithPage(
	DVBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
dvbt_demod_addr_8bit_default_GetRegBitsWithPage(
	DVBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// DVBT Demod Default I2C Functions for 16-bit Address
int
dvbt_demod_addr_16bit_default_SetRegBytes(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
dvbt_demod_addr_16bit_default_GetRegBytes(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
dvbt_demod_addr_16bit_default_SetRegMaskBits(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
dvbt_demod_addr_16bit_default_GetRegMaskBits(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
dvbt_demod_addr_16bit_default_SetRegBits(
	DVBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
dvbt_demod_addr_16bit_default_GetRegBits(
	DVBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// DVBT Demod Default Manipulating Functions
void
dvbt_demod_default_GetDemodType(
	DVBT_DEMOD_MODULE *pDemod,
	int *pDemodType
);

void
dvbt_demod_default_GetDeviceAddr(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

void
dvbt_demod_default_GetCrystalFreqHz(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

// Demod Common Function
int
realtek_i_dvbt_common_CheckRpuReady(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

int
realtek_i_dvbt_common_PingRpu(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

int
realtek_i_dvbt_common_ShutDown(
	DVBT_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt_common_ActivateCore(
	DVBT_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt_common_DeactivateCore(
	DVBT_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt_common_SwitchToBuffer(
	DVBT_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt_common_GetDemodInfo(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

int
realtek_i_dvbt_common_GetBuildId(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

int
realtek_i_dvbt_common_DemodCtrlStopCmd(
	DVBT_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt_common_DemodCtrlDetectCmd(
	DVBT_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt_common_DemodCtrlRunCmd(
	DVBT_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt_common_DemodCtrlUpdateRssiCmd(
	DVBT_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt_common_DemodCtrlResetCountersCmd(
	DVBT_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt_common_DemodCtrlUpdateCountersCmd(
	DVBT_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt_common_DemodCtrlSetAgcCmd(
	DVBT_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt_common_DemodCtrlUpdateAgcCmd(
	DVBT_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt_common_DemodCtrlQueryStatusCmd(
	DVBT_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt_common_GetDemodStatus(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

int
realtek_i_dvbt_common_SetTunerFreqCmd(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

int
realtek_i_dvbt_common_SetTunerBandwidth(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

int
realtek_i_dvbt_common_SetTunerGridBase(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

int
realtek_i_dvbt_common_SetTunerGridIncr(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

int
realtek_i_dvbt_common_SetNotchFreqCmd(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

int
realtek_i_dvbt_common_SetNotchBandwidth(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

int
realtek_i_dvbt_common_GetActiveTunerFreq(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

int
realtek_i_dvbt_common_GetActiveTunerBandwidth(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *ActiveBandwidth
);

int
realtek_i_dvbt_common_GetActiveTunerGain(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerGain
);

int
realtek_i_dvbt_common_GetActiveTunerRssi(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerRssi
);

int
realtek_i_dvbt_common_SetAgcParams(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int AgcParam,
    unsigned int Index
);

int
realtek_i_dvbt_common_GetAgcParams(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *AgcParam,
    unsigned int Index
);

int
realtek_i_dvbt_common_SetTsConfig(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

int
realtek_i_dvbt_common_SetTsClkRateMargin(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int TsClkMargin
);

int
realtek_i_dvbt_common_SetTsClkRateMax(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int TsClkRateMax
);

int
realtek_i_dvbt_common_GetDemodLockTime(
	DVBT_DEMOD_MODULE *pDemod,
    unsigned int *DemodLockTimeMs
);


int
realtek_i_dvbt_common_SetXmlTunerCfgOverride(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
);

int
realtek_i_dvbt_common_SetXmlTunerGainCtrl(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
);

int
realtek_i_dvbt_common_SetXmlFlags(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int Flags
);

int
realtek_i_dvbt_common_SetXmlIfFreq(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
);

int
realtek_i_dvbt_common_SetXmlPlatformCfgOverride(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
);

int
realtek_i_dvbt_common_SetXmlIfClk(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int IfClk
);

int
realtek_i_dvbt_common_SetXmlLdpcClk(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
);

int
realtek_i_dvbt_common_SetXmlUccClk(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int UccClk
);

int
realtek_i_dvbt_common_SetXmlMcuClk(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int McuClk
);

int
realtek_i_dvbt_common_SetVirtualRegister(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int RegVal
);

int
realtek_i_dvbt_common_GetVirtualRegister(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int *RegVal
);

int
realtek_i_dvbt_common_SetCtrlVirtualRegister(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

int
realtek_i_dvbt_common_GetCtrlVirtualRegister(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);

int
realtek_i_dvbt_common_SetHwRegValue(
	unsigned int Addr,
    unsigned int Val
);

int
realtek_i_dvbt_common_GetHwRegValue(
	unsigned int Addr,
    unsigned int *Val
);

// DVBT Demod Module Structure
struct DVBT_DEMOD_MODULE_TAG {
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

	BASE_INTERFACE_MODULE *pBaseInterface;
	I2C_BRIDGE_MODULE *pI2cBridge;

	// Demod I2C Function Pointers
	union {
		DVBT_DEMOD_REG_ACCESS_ADDR_8BIT  Addr8Bit;
		DVBT_DEMOD_REG_ACCESS_ADDR_16BIT Addr16Bit;
	}
	RegAccess;

	// Demod Manipulating Function Pointers
	DVBT_DEMOD_FP_GET_DEMOD_TYPE                GetDemodType;
	DVBT_DEMOD_FP_GET_DEVICE_ADDR               GetDeviceAddr;
	DVBT_DEMOD_FP_GET_CRYSTAL_FREQ_HZ           GetCrystalFreqHz;

    // Common TV Api
    DVBT_DEMOD_FP_CHECK_RPU_READY               CheckRpuReady;
    DVBT_DEMOD_FP_PING_RPU                      PingRpu;
    DVBT_DEMOD_FP_SHUT_DOWN                     ShutDown;
    DVBT_DEMOD_FP_ACTIVATE_CORE                 ActivateCore;
    DVBT_DEMOD_FP_DEACTIVATE_CORE               DeactivateCore;
    DVBT_DEMOD_FP_SWITCH_TO_BUFFER		SwitchToBuffer;
    
    DVBT_DEMOD_FP_GET_DEMOD_INFO                GetDemodInfo;
    DVBT_DEMOD_FP_GET_BUILD_ID                  GetBuildId;
    DVBT_DEMOD_FP_DEMOD_CTRL_STOP               DemodCtrlStop;
    DVBT_DEMOD_FP_DEMOD_CTRL_DETECT             DemodCtrlDetect;
    DVBT_DEMOD_FP_DEMOD_CTRL_RUN                DemodCtrlRun;
    DVBT_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI        DemodCtrlUpdateRssi;
    DVBT_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS     DemodCtrlResetCounters;
    DVBT_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS    DemodCtrlUpdateCounters;
    DVBT_DEMOD_FP_DEMOD_CTRL_SET_AGC            DemodCtrlSetAgc;
    DVBT_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC         DemodCtrlUpdateAgc;
    DVBT_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS       DemodCtrlQueryStatus;
    DVBT_DEMOD_FP_GET_DEMOD_STATUS              GetDemodStatus;

    DVBT_DEMOD_FP_SET_TUNER_FREQ                SetTunerFreq;
    DVBT_DEMOD_FP_SET_TUNER_BANDWIDTH           SetTunerBandwidth;
    DVBT_DEMOD_FP_SET_TUNER_GRID_BASE           SetTunerGridBase;
    DVBT_DEMOD_FP_SET_TUNER_GRID_INCR           SetTunerGridIncr;
    DVBT_DEMOD_FP_SET_NOTCH_FREQ                SetNotchFreq;
    DVBT_DEMOD_FP_SET_NOTCH_BANDWIDTH           SetNotchBandwidth;
    DVBT_DEMOD_FP_GET_ACT_TUNER_FREQ            GetActiveTunerFreq;
    DVBT_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH       GetActiveTunerBandwidth;
    DVBT_DEMOD_FP_GET_ACT_TUNER_GAIN            GetActiveTunerGain;
    DVBT_DEMOD_FP_GET_ACT_TUNER_RSSI            GetActiveTunerRssi;
    DVBT_DEMOD_FP_SET_AGC_PARAMS                SetAgcParams;
    DVBT_DEMOD_FP_GET_AGC_PARAMS                GetAgcParams;
    DVBT_DEMOD_FP_SET_TS_CONFIG                 SetTsConfig;
    DVBT_DEMOD_FP_SET_TS_CLK_RATE_MARGIN        SetTsClkRateMargin;
    DVBT_DEMOD_FP_SET_TS_CLK_RATE_MAX           SetTsClkRateMax;
    DVBT_DEMOD_FP_GET_DEMOD_LOCK_TIME           GetDemodLockTime;
	
    DVBT_DEMOD_FP_SET_XML_TUNER_CFG_OVERRIDE    SetXmlTunerCfgOverride;
    DVBT_DEMOD_FP_SET_XML_TUNER_GAIN_CTRL       SetXmlTunerGainCtrl;
    DVBT_DEMOD_FP_SET_XML_FLAGS                 SetXmlFlags;
    DVBT_DEMOD_FP_SET_XML_IF_FREQ               SetXmlIfFreq;
    DVBT_DEMOD_FP_SET_XML_PLFT_CFG_OVERRIDE     SetXmlPlftCfgOverride;
    DVBT_DEMOD_FP_SET_XML_IF_CLK                SetXmlIfClk;
    DVBT_DEMOD_FP_SET_XML_LDPC_CLK              SetXmlLdpcClk;
    DVBT_DEMOD_FP_SET_XML_UCC_CLK               SetXmlUccClk;
    DVBT_DEMOD_FP_SET_XML_MCU_CLK               SetXmlMcuClk;

    DVBT_DEMOD_FP_SET_VIRTUAL_REGISTER          SetVirtualRegister;
    DVBT_DEMOD_FP_GET_VIRTUAL_REGISTER          GetVirtualRegister;
    DVBT_DEMOD_FP_SET_CTRL_VIRTUAL_REGISTER     SetCtrlVirtualRegister;
    DVBT_DEMOD_FP_GET_CTRL_VIRTUAL_REGISTER     GetCtrlVirtualRegister;
    DVBT_DEMOD_FP_SET_HW_REG_VAL                SetHwRegValue;
    DVBT_DEMOD_FP_GET_HW_REG_VAL                GetHwRegValue;
	
    // DVBT Specific Api
    DVBT_DEMOD_FP_SET_DETECT_MASK                          SetDetectMask;
    DVBT_DEMOD_FP_GET_DETECT_MASK                          GetDetectMask;
    DVBT_DEMOD_FP_SET_TUN_FFT                              SetTunFft;
    DVBT_DEMOD_FP_GET_TUN_FFT                              GetTunFft;
    DVBT_DEMOD_FP_SET_TUN_GUARD                            SetTunGuard;
    DVBT_DEMOD_FP_GET_TUN_GUARD                            GetTunGuard;
    DVBT_DEMOD_FP_SET_TUN_MOD                              SetTunMod;
    DVBT_DEMOD_FP_GET_TUN_MOD                              GetTunMod;
    DVBT_DEMOD_FP_SET_TUN_CODE_RATE                        SetTunCodeRate;
    DVBT_DEMOD_FP_GET_TUN_CODE_RATE                        GetTunCodeRate;
    DVBT_DEMOD_FP_SET_TUN_ALPHA                            SetTunAlpha;
    DVBT_DEMOD_FP_GET_TUN_ALPHA                            GetTunAlpha;
    DVBT_DEMOD_FP_SET_TUN_INTERLEAVER                      SetTunInterleaver;
    DVBT_DEMOD_FP_GET_TUN_INTERLEAVER                      GetTunInterleaver;
    DVBT_DEMOD_FP_SET_TUN_HIERARCHICAL                     SetTunHierarchical;
    DVBT_DEMOD_FP_GET_TUN_HIERARCHICAL                     GetTunHierarchical;
    DVBT_DEMOD_FP_SET_TUN_SPECT_INV                        SetTunSpectInv;
    DVBT_DEMOD_FP_GET_TUN_SPECT_INV                        GetTunSpectInv;
    DVBT_DEMOD_FP_SET_CALIB_CTRL_CMD                       SetCalibCtrlCmd;
    DVBT_DEMOD_FP_SET_CALIB_XTAL_OFFSET                    SetCalibXtalOffset;
    DVBT_DEMOD_FP_GET_CALIB_XTAL_OFFSET                    GetCalibXtalOffset;
    DVBT_DEMOD_FP_SET_STAT_CTRL_CMD                        SetStatCtrlCmd;
    DVBT_DEMOD_FP_GET_STAT_UPDATA                          GetStatUpdata;
    DVBT_DEMOD_FP_GET_STAT_SSI                             GetStatSsi;
    DVBT_DEMOD_FP_GET_STAT_SNR                             GetStatSnr;
    DVBT_DEMOD_FP_GET_STAT_CARRIER_OFFSET                  GetStatCarrierOffset;
    DVBT_DEMOD_FP_GET_STAT_TS_PKT_COUNT                    GetStatTsPktCount;
    DVBT_DEMOD_FP_GET_STAT_TS_BAD_PKT_COUNT                GetStatTsBadPktCount;
    DVBT_DEMOD_FP_GET_STAT_TS_BYTE_ERRS                    GetStatTsByteErrs;
    DVBT_DEMOD_FP_GET_STAT_TS_BIT_ERRS                     GetStatTsBitErrs;
    DVBT_DEMOD_FP_GET_STAT_VITERBI_BER                     GetStatViterbiBer;
    DVBT_DEMOD_FP_GET_STAT_TS_SYNC                         GetStatTsSync;
    DVBT_DEMOD_FP_GET_STAT_TPS_SYNC                        GetStatTpsSync;
    DVBT_DEMOD_FP_GET_STAT_IF_AGC_LEVEL                    GetStatIfAgcLevel;
    DVBT_DEMOD_FP_GET_STAT_NUM_REAQC                       GetStatNumReaqc;
    DVBT_DEMOD_FP_GET_STAT_ACI_DETECT                      GetStatAciDetect;
    DVBT_DEMOD_FP_SET_BER_PERIOD                           SetBerPeriod;
    DVBT_DEMOD_FP_GET_BER_PERIOD                           GetBerPeriod;
    DVBT_DEMOD_FP_GET_BER_UPDATE                           GetBerUpdate;
    DVBT_DEMOD_FP_GET_BER_RS_BER                           GetBerRsBer;
    DVBT_DEMOD_FP_GET_BER_TS_PER                           GetBerTsPer;
    DVBT_DEMOD_FP_GET_BER_SQI                              GetBerSqi;
    DVBT_DEMOD_FP_GET_IF_AGC_GAIN                          GetIfAgcGain;
};

#define REALTEK_I_DVBT_BASE_PRINT_LVL_DBG      0
#define REALTEK_I_DVBT_BASE_PRINT_LVL_INFO     1
#define REALTEK_I_DVBT_BASE_PRINT_LVL_WARNING  2


#ifndef REALTEK_I_DVBT_BASE_PRINT_LVL
#define REALTEK_I_DVBT_BASE_PRINT_LVL          REALTEK_I_DVBT_BASE_PRINT_LVL_INFO
#endif

#define REALTEK_I_DVBT_BASE_DBG(fmt, args...)        rtd_printk(KERN_DEBUG, "DEMO", "DVBT_BASE_DEBUG, " fmt, ##args);
#define REALTEK_I_DVBT_BASE_INFO(fmt, args...)       rtd_printk(KERN_INFO, "DEMO", "DVBT_BASE_INFO, " fmt, ##args);
#define REALTEK_I_DVBT_BASE_WARNING(fmt, args...)    rtd_printk(KERN_WARNING, "DEMO", "DVBT_BASE_WARNING, " fmt, ##args);



#ifdef __cplusplus
}
#endif
#endif
