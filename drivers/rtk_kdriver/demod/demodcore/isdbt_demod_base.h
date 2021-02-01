#ifndef __ISDBT_DEMOD_BASE_H
#define __ISDBT_DEMOD_BASE_H

#include "foundation.h"

#ifdef __cplusplus
extern "C" {
#endif

// Bandwidth modes
#define ISDBT_BANDWIDTH_NONE   -1
enum ISDBT_BANDWIDTH_MODE {
	ISDBT_BANDWIDTH_6MHZ,
	ISDBT_BANDWIDTH_7MHZ,
	ISDBT_BANDWIDTH_8MHZ,
};
#define ISDBT_BANDWIDTH_MODE_NUM   3


// Hierarchical layer
enum ISDBT_HIERARCHICAL_LAYER_INDEX {
	ISDBT_HIERARCHICAL_LAYER_A,
	ISDBT_HIERARCHICAL_LAYER_B,
	ISDBT_HIERARCHICAL_LAYER_C,
};
#define ISDBT_HIERARCHICAL_LAYER_INDEX_NUM   3


// Constellation
enum ISDBT_CONSTELLATION_MODE {
	ISDBT_CONSTELLATION_DQPSK = 0,
	ISDBT_CONSTELLATION_QPSK = 1,
	ISDBT_CONSTELLATION_16QAM = 2,
	ISDBT_CONSTELLATION_64QAM = 3,
};
#define ISDBT_CONSTELLATION_MODE_NUM   4


// Code rate
enum ISDBT_CODE_RATE_MODE {
	ISDBT_CODE_RATE_1_OVER_2 = 0,
	ISDBT_CODE_RATE_2_OVER_3 = 1,
	ISDBT_CODE_RATE_3_OVER_4 = 2,
	ISDBT_CODE_RATE_5_OVER_6 = 3,
	ISDBT_CODE_RATE_7_OVER_8 = 4,
};
#define ISDBT_CODE_RATE_MODE_NUM   5


// Interleaving length
enum ISDBT_INTERLEAVING_LEN_MODE {
	ISDBT_INTERLEAVING_LEN_0 = 0,
	ISDBT_INTERLEAVING_LEN_1 = 1,
	ISDBT_INTERLEAVING_LEN_2 = 2,
	ISDBT_INTERLEAVING_LEN_4 = 4,
	ISDBT_INTERLEAVING_LEN_8,
	ISDBT_INTERLEAVING_LEN_16,
};
#define ISDBT_INTERLEAVING_LEN_MODE_NUM   6


// Segment number
enum ISDBT_SEGMENT_NUM {
	ISDBT_SEGMENT_NUM_1  = 1,
	ISDBT_SEGMENT_NUM_3  = 3,
	ISDBT_SEGMENT_NUM_13 = 13,
};


// Guard interval
enum ISDBT_GUARD_INTERVAL_MODE {
	ISDBT_GUARD_INTERVAL_1_OVER_32 = 3,
	ISDBT_GUARD_INTERVAL_1_OVER_16 = 2,
	ISDBT_GUARD_INTERVAL_1_OVER_8 =1 ,
	ISDBT_GUARD_INTERVAL_1_OVER_4 = 0,
};
#define ISDBT_GUARD_INTERVAL_MODE_NUM   4


// FFT mode
enum ISDBT_FFT_MODE_MODE {
	ISDBT_FFT_MODE_2K = 0,
	ISDBT_FFT_MODE_4K = 1,
	ISDBT_FFT_MODE_8K = 2,
};
#define ISDBT_FFT_MODE_NUM   3



// Common Register Setting
#define REALTEK_I_NOTCH_EN                                       0
#define REALTEK_I_NOTCH_FREQ                                     500000000
#define REALTEK_I_NOTCH_BW                                       1 //0~87
#define REALTEK_I_TS_DIS_MASK                                    0x00000001
#define REALTEK_I_TS_SERIAL_MASK                                 0x00000002
#define REALTEK_I_TS_CLK_PHASE_INV_MASK                          0x00000004
#define REALTEK_I_TS_PACKETS_188_MASK                            0x00000008
#define REALTEK_I_TS_CLOCK_GATE_MASK   0x00000020

// ISDBT Demod Module Pre-Definition
typedef struct ISDBT_DEMOD_MODULE_TAG ISDBT_DEMOD_MODULE;

typedef enum _REALTEK_I_ISDBT_QAM_MODE {
	ISDBT_QAM_4,				///<   QPSK
	ISDBT_DQPSK_8,				///<    DQPSK
	ISDBT_QAM_16,				///<   16 QAM
	ISDBT_QAM_64				///<   64 QAM
}REALTEK_I_ISDBT_QAM_MODE;

typedef enum _REALTEK_I_IMG_DEMOD_ISDBT_QAM_MODE {
    ISDBT_DEMOD_QAM_4 = 0,
    ISDBT_DEMOD_QAM_8, 
    ISDBT_DEMOD_QAM_16, 
    ISDBT_DEMOD_QAM_64
}_REALTEK_I_IMG_DEMOD_ISDBT_QAM_MODE;

typedef enum _REALTEK_I_DEMOD_TYPE{
    UCC_STANDARD_NOT_SIGNALLED = 0,
    UCC_STANDARD_ISDBT,
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
    UCC_STANDARD_DVBT,
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
(*ISDBT_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_8BIT_SET_REG_BITS)(
	ISDBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_16BIT_SET_REG_BITS)(
	ISDBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_8BIT_GET_REG_BITS)(
	ISDBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_16BIT_GET_REG_BITS)(
	ISDBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE)(
	ISDBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*ISDBT_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE)(
	ISDBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// Demod Register Access for 8-bit Address
typedef struct {
	ISDBT_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE             SetRegPage;
	ISDBT_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES            SetRegBytes;
	ISDBT_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES            GetRegBytes;
	ISDBT_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS        SetRegMaskBits;
	ISDBT_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS        GetRegMaskBits;
	ISDBT_DEMOD_FP_ADDR_8BIT_SET_REG_BITS             SetRegBits;
	ISDBT_DEMOD_FP_ADDR_8BIT_GET_REG_BITS             GetRegBits;
	ISDBT_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE   SetRegBitsWithPage;
	ISDBT_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE   GetRegBitsWithPage;
}
ISDBT_DEMOD_REG_ACCESS_ADDR_8BIT;

// Demod Register Access for 16-bit Address
typedef struct {
	ISDBT_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES       SetRegBytes;
	ISDBT_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES       GetRegBytes;
	ISDBT_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS   SetRegMaskBits;
	ISDBT_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS   GetRegMaskBits;
	ISDBT_DEMOD_FP_ADDR_16BIT_SET_REG_BITS        SetRegBits;
	ISDBT_DEMOD_FP_ADDR_16BIT_GET_REG_BITS        GetRegBits;
}
ISDBT_DEMOD_REG_ACCESS_ADDR_16BIT;

typedef void
(*ISDBT_DEMOD_FP_GET_DEMOD_TYPE)(
	ISDBT_DEMOD_MODULE *pDemod,
	int *pDemodType
);

typedef void
(*ISDBT_DEMOD_FP_GET_DEVICE_ADDR)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

typedef void
(*ISDBT_DEMOD_FP_GET_CRYSTAL_FREQ_HZ)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

// Demod Common Function Pointer
typedef int
(*ISDBT_DEMOD_FP_CHECK_RPU_READY)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

typedef int
(*ISDBT_DEMOD_FP_PING_RPU)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

typedef int
(*ISDBT_DEMOD_FP_SHUT_DOWN)(
	ISDBT_DEMOD_MODULE *pDemod
);

typedef int
(*ISDBT_DEMOD_FP_ACTIVATE_CORE)(
	ISDBT_DEMOD_MODULE *pDemod
);

typedef int
(*ISDBT_DEMOD_FP_DEACTIVATE_CORE)(
	ISDBT_DEMOD_MODULE *pDemod
);

typedef int
(*ISDBT_DEMOD_FP_SWITCH_TO_BUFFER)(
	ISDBT_DEMOD_MODULE *pDemod
);

typedef int
(*ISDBT_DEMOD_FP_GET_DEMOD_INFO)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

typedef int
(*ISDBT_DEMOD_FP_GET_BUILD_ID)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

typedef int
(*ISDBT_DEMOD_FP_DEMOD_CTRL_STOP)(
	ISDBT_DEMOD_MODULE *pDemod
);

typedef int
(*ISDBT_DEMOD_FP_DEMOD_CTRL_DETECT)(
	ISDBT_DEMOD_MODULE *pDemod
);

typedef int
(*ISDBT_DEMOD_FP_DEMOD_CTRL_RUN)(
	ISDBT_DEMOD_MODULE *pDemod
);

typedef int
(*ISDBT_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI)(
	ISDBT_DEMOD_MODULE *pDemod
);

typedef int
(*ISDBT_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS)(
	ISDBT_DEMOD_MODULE *pDemod
);

typedef int
(*ISDBT_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS)(
	ISDBT_DEMOD_MODULE *pDemod
);

typedef int
(*ISDBT_DEMOD_FP_DEMOD_CTRL_SET_AGC)(
	ISDBT_DEMOD_MODULE *pDemod
);

typedef int
(*ISDBT_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC)(
	ISDBT_DEMOD_MODULE *pDemod
);

typedef int
(*ISDBT_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS)(
	ISDBT_DEMOD_MODULE *pDemod
);

typedef int
(*ISDBT_DEMOD_FP_GET_DEMOD_STATUS)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUNER_FREQ)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUNER_BANDWIDTH)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUNER_GRID_BASE)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUNER_GRID_INCR)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

typedef int
(*ISDBT_DEMOD_FP_SET_NOTCH_FREQ)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

typedef int
(*ISDBT_DEMOD_FP_SET_NOTCH_BANDWIDTH)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

typedef int
(*ISDBT_DEMOD_FP_GET_ACT_TUNER_FREQ)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

typedef int
(*ISDBT_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH)(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int *ActiveBandwidth
);

typedef int
(*ISDBT_DEMOD_FP_GET_ACT_TUNER_GAIN)(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerGain
);

typedef int
(*ISDBT_DEMOD_FP_GET_ACT_TUNER_RSSI)(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerRssi
);

typedef int
(*ISDBT_DEMOD_FP_SET_AGC_PARAMS)(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int AgcParam,
    unsigned int Index
);

typedef int
(*ISDBT_DEMOD_FP_GET_AGC_PARAMS)(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int *AgcParam,
    unsigned int Index
);

typedef int
(*ISDBT_DEMOD_FP_SET_TS_CONFIG)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

typedef int
(*ISDBT_DEMOD_FP_SET_TS_CLK_RATE_MARGIN)(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int TsClkMargin
);

typedef int
(*ISDBT_DEMOD_FP_SET_TS_CLK_RATE_MAX)(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int TsClkRateMax
);

typedef int
(*ISDBT_DEMOD_FP_GET_DEMOD_LOCK_TIME)(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int *DemodLockTimeMs
);

typedef int
(*ISDBT_DEMOD_FP_SET_XML_TUNER_CFG_OVERRIDE)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
);

typedef int
(*ISDBT_DEMOD_FP_SET_XML_TUNER_GAIN_CTRL)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
);

typedef int
(*ISDBT_DEMOD_FP_SET_XML_FLAGS)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int Flags
);

typedef int
(*ISDBT_DEMOD_FP_SET_XML_IF_FREQ)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
);

typedef int
(*ISDBT_DEMOD_FP_SET_XML_PLFT_CFG_OVERRIDE)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
);

typedef int
(*ISDBT_DEMOD_FP_SET_XML_IF_CLK)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int IfClk
);

typedef int
(*ISDBT_DEMOD_FP_SET_XML_LDPC_CLK)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
);

typedef int
(*ISDBT_DEMOD_FP_SET_XML_UCC_CLK)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int UccClk
);

typedef int
(*ISDBT_DEMOD_FP_SET_XML_MCU_CLK)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int McuClk
);

typedef int
(*ISDBT_DEMOD_FP_SET_VIRTUAL_REGISTER)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int RegVal
);

typedef int
(*ISDBT_DEMOD_FP_GET_VIRTUAL_REGISTER)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int *RegVal
);



// ISDBT Specific Function Pointer
typedef int
(*ISDBT_DEMOD_FP_SET_TUN_CTRL_CMD)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunCtrl
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_SUB_CH)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunSubCh
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_SUB_CH)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSubCh
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_PARITAL)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunParital
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_PARITAL)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunParital
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_MODE)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunMode
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_MODE)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunMode
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_GUARD)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunGuard
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_GUARD)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunGuard
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_MODE_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunModeA
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_MODE_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunModeA
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_CODE_RATE_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunCodeRateA
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_CODE_RATE_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRateA
);  

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_INTERLEAVEL_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunInterleaverA
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_INTERLEAVEL_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunInterleaverA
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_SEGS_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunSegsA
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_SEGS_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSegsA
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_MODE_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunModeB
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_MODE_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunModeB
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_CODE_RATE_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunCodeRateB
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_CODE_RATE_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRateB
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_INTERLEAVEL_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunInterleaverB
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_INTERLEAVEL_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunInterleaverB
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_SEGS_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunSegsB
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_SEGS_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSegsB
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_MODE_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunModeC
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_MODE_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunModeC
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_CODE_RATE_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunCodeRateC
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_CODE_RATE_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRateC
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_INTERLEAVEL_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunInterleaverC
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_INTERLEAVEL_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunInterleaverC
);

typedef int
(*ISDBT_DEMOD_FP_SET_TUN_SEGS_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunSegsC
);

typedef int
(*ISDBT_DEMOD_FP_GET_TUN_SEGS_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSegsC
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_EAF)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegEaf
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_TS_PKT_COUNT_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsPktCountA
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_TS_BAD_PKT_COUNT_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBadPktCountA
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_TS_BYTE_ERRS_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsByteErrsA
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_TS_BIT_ERRS_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBitErrsA
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_VITERBI_BER_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatViterbiBerA
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_TS_PKT_COUNT_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsPktCountB
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_TS_BAD_PKT_COUNT_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBadPktCountB
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_TS_BYTE_ERRS_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsByteErrsB
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_TS_BIT_ERRS_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBitErrsB
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_VITERBI_BER_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatViterbiBerB
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_TS_PKT_COUNT_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsPktCountC
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_TS_BAD_PKT_COUNT_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBadPktCountC
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_TS_BYTE_ERRS_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsByteErrsC
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_TS_BIT_ERRS_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBitErrsC
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_VITERBI_BER_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatViterbiBerC
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_NUM_REACQ)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatNumReaqc
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_SNR)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatSnr
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_CARRIER_ACQUISITION_OFFSET)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatCarrierAcquisitionOffset
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_CARRIER_TRACKING_OFFSET)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatCarrireTrackingOffset
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_STAT_IF_AGC_LEVEL)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatIfAgcLevel
);


typedef int
(*ISDBT_DEMOD_FP_SET_REG_BER_PERIOD)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int RegBerPeriod
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_BER_PERIOD)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerPeriod
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_BER_UPDATE)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerUpdate
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_BER_RS_BER_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerRsBerA
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_BER_TS_PER_A)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerTsPerA
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_BER_RS_BER_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerRsBerB
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_BER_TS_PER_B)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerTsPerB
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_BER_RS_BER_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerRsBerC
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_BER_TS_PER_C)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerTsPerC
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_DEMOD_FAILURE_CODE)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegFailureCode
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_DEMOD_FAILURE_COUNT_PER_TIMEOUT)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegFailureCountPerTimeout
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_DEMOD_FAILURE_COUNT_OTHER)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegFailureCountOther
);

typedef int
(*ISDBT_DEMOD_FP_GET_REG_TMCC_GOOD_DECODE_COUNT)(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegTmccGoodDecodeCount
);

// ISDBT Demod Default I2C Functions for 8-bit Address
int
ISDBT_DEMOD_addr_8bit_default_SetRegPage(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

int
ISDBT_DEMOD_addr_8bit_default_SetRegBytes(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
ISDBT_DEMOD_addr_8bit_default_GetRegBytes(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
ISDBT_DEMOD_addr_8bit_default_SetRegMaskBits(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
ISDBT_DEMOD_addr_8bit_default_GetRegMaskBits(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
ISDBT_DEMOD_addr_8bit_default_SetRegBits(
	ISDBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
ISDBT_DEMOD_addr_8bit_default_GetRegBits(
	ISDBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

int
ISDBT_DEMOD_addr_8bit_default_SetRegBitsWithPage(
	ISDBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
ISDBT_DEMOD_addr_8bit_default_GetRegBitsWithPage(
	ISDBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// ISDBT Demod Default I2C Functions for 16-bit Address
int
ISDBT_DEMOD_addr_16bit_default_SetRegBytes(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
ISDBT_DEMOD_addr_16bit_default_GetRegBytes(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
ISDBT_DEMOD_addr_16bit_default_SetRegMaskBits(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
ISDBT_DEMOD_addr_16bit_default_GetRegMaskBits(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
ISDBT_DEMOD_addr_16bit_default_SetRegBits(
	ISDBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
ISDBT_DEMOD_addr_16bit_default_GetRegBits(
	ISDBT_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// ISDBT Demod Default Manipulating Functions
void
ISDBT_DEMOD_default_GetDemodType(
	ISDBT_DEMOD_MODULE *pDemod,
	int *pDemodType
);

void
ISDBT_DEMOD_default_GetDeviceAddr(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

void
ISDBT_DEMOD_default_GetCrystalFreqHz(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

// Demod Common Function
int
realtek_i_isdbt_common_CheckRpuReady(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

int
realtek_i_isdbt_common_PingRpu(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

int
realtek_i_isdbt_common_ShutDown(
	ISDBT_DEMOD_MODULE *pDemod
);

int
realtek_i_isdbt_common_ActivateCore(
	ISDBT_DEMOD_MODULE *pDemod
);

int
realtek_i_isdbt_common_DeactivateCore(
	ISDBT_DEMOD_MODULE *pDemod
);

int
realtek_i_isdbt_common_SwitchToBuffer(
	ISDBT_DEMOD_MODULE *pDemod
);

int
realtek_i_isdbt_common_GetDemodInfo(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

int
realtek_i_isdbt_common_GetBuildId(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

int
realtek_i_isdbt_common_DemodCtrlStopCmd(
	ISDBT_DEMOD_MODULE *pDemod
);

int
realtek_i_isdbt_common_DemodCtrlDetectCmd(
	ISDBT_DEMOD_MODULE *pDemod
);

int
realtek_i_isdbt_common_DemodCtrlRunCmd(
	ISDBT_DEMOD_MODULE *pDemod
);

int
realtek_i_isdbt_common_DemodCtrlUpdateRssiCmd(
	ISDBT_DEMOD_MODULE *pDemod
);

int
realtek_i_isdbt_common_DemodCtrlResetCountersCmd(
	ISDBT_DEMOD_MODULE *pDemod
);

int
realtek_i_isdbt_common_DemodCtrlUpdateCountersCmd(
	ISDBT_DEMOD_MODULE *pDemod
);

int
realtek_i_isdbt_common_DemodCtrlSetAgcCmd(
	ISDBT_DEMOD_MODULE *pDemod
);

int
realtek_i_isdbt_common_DemodCtrlUpdateAgcCmd(
	ISDBT_DEMOD_MODULE *pDemod
);

int
realtek_i_isdbt_common_DemodCtrlQueryStatusCmd(
	ISDBT_DEMOD_MODULE *pDemod
);

int
realtek_i_isdbt_common_GetDemodStatus(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

int
realtek_i_isdbt_common_SetTunerFreqCmd(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

int
realtek_i_isdbt_common_SetTunerBandwidth(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

int
realtek_i_isdbt_common_SetTunerGridBase(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

int
realtek_i_isdbt_common_SetTunerGridIncr(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

int
realtek_i_isdbt_common_SetNotchFreqCmd(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

int
realtek_i_isdbt_common_SetNotchBandwidth(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

int
realtek_i_isdbt_common_GetActiveTunerFreq(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

int
realtek_i_isdbt_common_GetActiveTunerBandwidth(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int *ActiveBandwidth
);

int
realtek_i_isdbt_common_GetActiveTunerGain(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerGain
);

int
realtek_i_isdbt_common_GetActiveTunerRssi(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerRssi
);

int
realtek_i_isdbt_common_SetAgcParams(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int AgcParam,
    unsigned int Index
);

int
realtek_i_isdbt_common_GetAgcParams(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int *AgcParam,
    unsigned int Index
);

int
realtek_i_isdbt_common_SetTsConfig(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

int
realtek_i_isdbt_common_SetTsClkRateMargin(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int TsClkMargin
);

int
realtek_i_isdbt_common_SetTsClkRateMax(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int TsClkRateMax
);

int
realtek_i_isdbt_common_GetDemodLockTime(
	ISDBT_DEMOD_MODULE *pDemod,
    unsigned int *DemodLockTimeMs
);

int
realtek_i_isdbt_common_SetXmlTunerCfgOverride(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
);

int
realtek_i_isdbt_common_SetXmlTunerGainCtrl(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
);

int
realtek_i_isdbt_common_SetXmlFlags(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int Flags
);

int
realtek_i_isdbt_common_SetXmlIfFreq(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
);

int
realtek_i_isdbt_common_SetXmlPlatformCfgOverride(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
);

int
realtek_i_isdbt_common_SetXmlIfClk(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int IfClk
);

int
realtek_i_isdbt_common_SetXmlLdpcClk(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
);

int
realtek_i_isdbt_common_SetXmlUccClk(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int UccClk
);

int
realtek_i_isdbt_common_SetXmlMcuClk(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int McuClk
);

int
realtek_i_isdbt_common_SetVirtualRegister(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int RegVal
);

int
realtek_i_isdbt_common_GetVirtualRegister(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int *RegVal
);

// ISDBT Demod Module Structure
struct ISDBT_DEMOD_MODULE_TAG {
	// Private Variables
	int           DemodType;
	unsigned char DeviceAddr;
	unsigned long CrystalFreqHz;
	int           TsInterfaceMode;
	unsigned long IfFreqHz;
	int           SpectrumMode;
    
	int           QamMode;
 	int           BandwidthMode;
	unsigned char SegmentNum;
	unsigned char SubChannelNum;
	int           AlphaMode;
    unsigned long TunerFreqHz;//Hz
 
	int           IsQamModeSet;
	int           IsSymbolRateHzSet;
	int           IsAlphaModeSet;
	int           IsIfFreqHzSet;
	int           IsSpectrumModeSet;
	
	int           IsBandwidthModeSet;
	int           IsSegmentNumSet;
	int           IsSubChannelNumSet;

	BASE_INTERFACE_MODULE *pBaseInterface;
	I2C_BRIDGE_MODULE *pI2cBridge;

	// Demod I2C Function Pointers
	union {
		ISDBT_DEMOD_REG_ACCESS_ADDR_8BIT  Addr8Bit;
		ISDBT_DEMOD_REG_ACCESS_ADDR_16BIT Addr16Bit;
	}
	RegAccess;

	// Demod Manipulating Function Pointers
	ISDBT_DEMOD_FP_GET_DEMOD_TYPE                GetDemodType;
	ISDBT_DEMOD_FP_GET_DEVICE_ADDR               GetDeviceAddr;
	ISDBT_DEMOD_FP_GET_CRYSTAL_FREQ_HZ           GetCrystalFreqHz;

    // Common TV Api
    ISDBT_DEMOD_FP_CHECK_RPU_READY               CheckRpuReady;
    ISDBT_DEMOD_FP_PING_RPU                      PingRpu;
    ISDBT_DEMOD_FP_SHUT_DOWN                     ShutDown;
    ISDBT_DEMOD_FP_ACTIVATE_CORE                 ActivateCore;
    ISDBT_DEMOD_FP_DEACTIVATE_CORE               DeactivateCore;
    
    ISDBT_DEMOD_FP_GET_DEMOD_INFO                GetDemodInfo;
    ISDBT_DEMOD_FP_GET_BUILD_ID                  GetBuildId;
    ISDBT_DEMOD_FP_DEMOD_CTRL_STOP               DemodCtrlStop;
    ISDBT_DEMOD_FP_DEMOD_CTRL_DETECT             DemodCtrlDetect;
    ISDBT_DEMOD_FP_DEMOD_CTRL_RUN                DemodCtrlRun;
    ISDBT_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI        DemodCtrlUpdateRssi;
    ISDBT_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS     DemodCtrlResetCounters;
    ISDBT_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS    DemodCtrlUpdateCounters;
    ISDBT_DEMOD_FP_DEMOD_CTRL_SET_AGC            DemodCtrlSetAgc;
    ISDBT_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC         DemodCtrlUpdateAgc;
    ISDBT_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS       DemodCtrlQueryStatus;
    ISDBT_DEMOD_FP_GET_DEMOD_STATUS              GetDemodStatus;

    ISDBT_DEMOD_FP_SET_TUNER_FREQ                SetTunerFreq;
    ISDBT_DEMOD_FP_SET_TUNER_BANDWIDTH           SetTunerBandwidth;
    ISDBT_DEMOD_FP_SET_TUNER_GRID_BASE           SetTunerGridBase;
    ISDBT_DEMOD_FP_SET_TUNER_GRID_INCR           SetTunerGridIncr;
    ISDBT_DEMOD_FP_SET_NOTCH_FREQ                SetNotchFreq;
    ISDBT_DEMOD_FP_SET_NOTCH_BANDWIDTH           SetNotchBandwidth;
    ISDBT_DEMOD_FP_GET_ACT_TUNER_FREQ            GetActiveTunerFreq;
    ISDBT_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH       GetActiveTunerBandwidth;
    ISDBT_DEMOD_FP_GET_ACT_TUNER_GAIN            GetActiveTunerGain;
    ISDBT_DEMOD_FP_GET_ACT_TUNER_RSSI            GetActiveTunerRssi;
    ISDBT_DEMOD_FP_SET_AGC_PARAMS                SetAgcParams;
    ISDBT_DEMOD_FP_GET_AGC_PARAMS                GetAgcParams;
    ISDBT_DEMOD_FP_SET_TS_CONFIG                 SetTsConfig;
    ISDBT_DEMOD_FP_SET_TS_CLK_RATE_MARGIN        SetTsClkRateMargin;
    ISDBT_DEMOD_FP_SET_TS_CLK_RATE_MAX           SetTsClkRateMax;
    ISDBT_DEMOD_FP_GET_DEMOD_LOCK_TIME           GetDemodLockTime;
    ISDBT_DEMOD_FP_SET_XML_TUNER_CFG_OVERRIDE       SetXmlTunerCfgOverride;
    ISDBT_DEMOD_FP_SET_XML_TUNER_GAIN_CTRL          SetXmlTunerGainCtrl;
    ISDBT_DEMOD_FP_SET_XML_FLAGS                    SetXmlFlags;
    ISDBT_DEMOD_FP_SET_XML_IF_FREQ                  SetXmlIfFreq;
    ISDBT_DEMOD_FP_SET_XML_PLFT_CFG_OVERRIDE        SetXmlPlftCfgOverride;
    ISDBT_DEMOD_FP_SET_XML_IF_CLK                   SetXmlIfClk;
    ISDBT_DEMOD_FP_SET_XML_LDPC_CLK                 SetXmlLdpcClk;
    ISDBT_DEMOD_FP_SET_XML_UCC_CLK                  SetXmlUccClk;
    ISDBT_DEMOD_FP_SET_XML_MCU_CLK                  SetXmlMcuClk;
    ISDBT_DEMOD_FP_SET_VIRTUAL_REGISTER             SetVirtualRegister;
    ISDBT_DEMOD_FP_GET_VIRTUAL_REGISTER             GetVirtualRegister;
    ISDBT_DEMOD_FP_SWITCH_TO_BUFFER              SwitchToBuffer;

    // ISDBT Specific Api
    ISDBT_DEMOD_FP_SET_TUN_CTRL_CMD              SetTunCtrlCmd;                
    ISDBT_DEMOD_FP_SET_TUN_SUB_CH                SetTunSubCh;                      
    ISDBT_DEMOD_FP_GET_TUN_SUB_CH                GetTunSubCh;
    ISDBT_DEMOD_FP_SET_TUN_PARITAL               SetTunParital;                                                 
    ISDBT_DEMOD_FP_GET_TUN_PARITAL               GetTunParital;                                                 
    ISDBT_DEMOD_FP_SET_TUN_MODE                  SetTunMode;
    ISDBT_DEMOD_FP_GET_TUN_MODE                  GetTunMode;
    ISDBT_DEMOD_FP_SET_TUN_GUARD                 SetTunGuard;
    ISDBT_DEMOD_FP_GET_TUN_GUARD                 GetTunGuard;
    ISDBT_DEMOD_FP_SET_TUN_MODE_A                SetTunModeA;
    ISDBT_DEMOD_FP_GET_TUN_MODE_A                GetTunModeA;
    ISDBT_DEMOD_FP_SET_TUN_CODE_RATE_A           SetTunCodeRateA;
    ISDBT_DEMOD_FP_GET_TUN_CODE_RATE_A           GetTunCodeRateA;
    ISDBT_DEMOD_FP_SET_TUN_INTERLEAVEL_A         SetTunInterleaverA;
    ISDBT_DEMOD_FP_GET_TUN_INTERLEAVEL_A         GetTunInterleaverA;
    ISDBT_DEMOD_FP_SET_TUN_SEGS_A                SetTunSegsA;
    ISDBT_DEMOD_FP_GET_TUN_SEGS_A                GetTunSegsA;
    ISDBT_DEMOD_FP_SET_TUN_MODE_B                SetTunModeB;
    ISDBT_DEMOD_FP_GET_TUN_MODE_B                GetTunModeB;
    ISDBT_DEMOD_FP_SET_TUN_CODE_RATE_B           SetTunCodeRateB;
    ISDBT_DEMOD_FP_GET_TUN_CODE_RATE_B           GetTunCodeRateB;
    ISDBT_DEMOD_FP_SET_TUN_INTERLEAVEL_B         SetTunInterleaverB;
    ISDBT_DEMOD_FP_GET_TUN_INTERLEAVEL_B         GetTunInterleaverB;
    ISDBT_DEMOD_FP_SET_TUN_SEGS_B                SetTunSegsB;
    ISDBT_DEMOD_FP_GET_TUN_SEGS_B                GetTunSegsB;
    ISDBT_DEMOD_FP_SET_TUN_MODE_C                SetTunModeC;
    ISDBT_DEMOD_FP_GET_TUN_MODE_C                GetTunModeC;
    ISDBT_DEMOD_FP_SET_TUN_CODE_RATE_C           SetTunCodeRateC;
    ISDBT_DEMOD_FP_GET_TUN_CODE_RATE_C           GetTunCodeRateC;
    ISDBT_DEMOD_FP_SET_TUN_INTERLEAVEL_C         SetTunInterleaverC;
    ISDBT_DEMOD_FP_GET_TUN_INTERLEAVEL_C         GetTunInterleaverC;
    ISDBT_DEMOD_FP_SET_TUN_SEGS_C                SetTunSegsC;
    ISDBT_DEMOD_FP_GET_TUN_SEGS_C                GetTunSegsC;
    
    ISDBT_DEMOD_FP_GET_REG_EAF                   GetRegEaf;

    ISDBT_DEMOD_FP_GET_REG_STAT_TS_PKT_COUNT_A   GetRegStatTsPktCountA;
    ISDBT_DEMOD_FP_GET_REG_STAT_TS_BAD_PKT_COUNT_A  GetRegStatTsBadPktCountA;
    ISDBT_DEMOD_FP_GET_REG_STAT_TS_BYTE_ERRS_A      GetRegStatTsByteErrsA;
    ISDBT_DEMOD_FP_GET_REG_STAT_TS_BIT_ERRS_A    GetRegStatTsBitErrsA;
    ISDBT_DEMOD_FP_GET_REG_STAT_VITERBI_BER_A    GetRegStatViterbiBerA;
    ISDBT_DEMOD_FP_GET_REG_STAT_TS_PKT_COUNT_B   GetRegStatTsPktCountB;
    ISDBT_DEMOD_FP_GET_REG_STAT_TS_BAD_PKT_COUNT_B  GetRegStatTsBadPktCountB;
    ISDBT_DEMOD_FP_GET_REG_STAT_TS_BYTE_ERRS_B      GetRegStatTsByteErrsB;
    ISDBT_DEMOD_FP_GET_REG_STAT_TS_BIT_ERRS_B    GetRegStatTsBitErrsB;
    ISDBT_DEMOD_FP_GET_REG_STAT_VITERBI_BER_B    GetRegStatViterbiBerB;
    ISDBT_DEMOD_FP_GET_REG_STAT_TS_PKT_COUNT_C   GetRegStatTsPktCountC;
    ISDBT_DEMOD_FP_GET_REG_STAT_TS_BAD_PKT_COUNT_C  GetRegStatTsBadPktCountC;
    ISDBT_DEMOD_FP_GET_REG_STAT_TS_BYTE_ERRS_C      GetRegStatTsByteErrsC;
    ISDBT_DEMOD_FP_GET_REG_STAT_TS_BIT_ERRS_C    GetRegStatTsBitErrsC;
    ISDBT_DEMOD_FP_GET_REG_STAT_VITERBI_BER_C    GetRegStatViterbiBerC;
    ISDBT_DEMOD_FP_GET_REG_STAT_NUM_REACQ        GetRegStatNumReaqc;
    ISDBT_DEMOD_FP_GET_REG_STAT_SNR              GetRegStatSnr;
    ISDBT_DEMOD_FP_GET_REG_STAT_CARRIER_ACQUISITION_OFFSET   GetRegStatCarrierAcquisitionOffset;
    ISDBT_DEMOD_FP_GET_REG_STAT_CARRIER_TRACKING_OFFSET      GetRegStatCarrierTrackingOffset;
    ISDBT_DEMOD_FP_GET_REG_STAT_IF_AGC_LEVEL     GetRegStatIfAgcLevel;

    ISDBT_DEMOD_FP_SET_REG_BER_PERIOD            SetRegBerPeriod;
    ISDBT_DEMOD_FP_GET_REG_BER_PERIOD            GetRegBerPeriod;
    ISDBT_DEMOD_FP_GET_REG_BER_UPDATE            GetRegBerUpdate;
    ISDBT_DEMOD_FP_GET_REG_BER_RS_BER_A          GetRegBerRsBerA;
    ISDBT_DEMOD_FP_GET_REG_BER_TS_PER_A          GetRegBerTsPerA;
    ISDBT_DEMOD_FP_GET_REG_BER_RS_BER_B          GetRegBerRsBerB;
    ISDBT_DEMOD_FP_GET_REG_BER_TS_PER_B          GetRegBerTsPerB;
    ISDBT_DEMOD_FP_GET_REG_BER_RS_BER_C          GetRegBerRsBerC;
    ISDBT_DEMOD_FP_GET_REG_BER_TS_PER_C          GetRegBerTsPerC;

    ISDBT_DEMOD_FP_GET_REG_DEMOD_FAILURE_CODE	 GetRegDemodFailureCode;
    ISDBT_DEMOD_FP_GET_REG_DEMOD_FAILURE_COUNT_PER_TIMEOUT 	GetRegDemodFailureCountPerTimeout;
    ISDBT_DEMOD_FP_GET_REG_DEMOD_FAILURE_COUNT_OTHER 		GetRegDemodFailureCountOther;
    ISDBT_DEMOD_FP_GET_REG_TMCC_GOOD_DECODE_COUNT               GetRegTmccGoodDecodeCount;
	
};

#define REALTEK_I_ISDBT_BASE_PRINT_LVL_DBG      0
#define REALTEK_I_ISDBT_BASE_PRINT_LVL_INFO     1
#define REALTEK_I_ISDBT_BASE_PRINT_LVL_WARNING  2


#ifndef REALTEK_I_ISDBT_BASE_PRINT_LVL
#define REALTEK_I_ISDBT_BASE_PRINT_LVL          REALTEK_I_ISDBT_BASE_PRINT_LVL_INFO
#endif

#define REALTEK_I_ISDBT_BASE_DBG(fmt, args...)       rtd_printk(KERN_DEBUG, "DEMO", "ISDBT_BASE_DEBUG, " fmt, ##args);
#define REALTEK_I_ISDBT_BASE_INFO(fmt, args...)        rtd_printk(KERN_INFO, "DEMO", "ISDBT_BASE_INFO, " fmt, ##args);
#define REALTEK_I_ISDBT_BASE_WARNING(fmt, args...)    rtd_printk(KERN_WARNING, "DEMO", "ISDBT_BASE_WARNING, " fmt, ##args);

#ifdef __cplusplus
}
#endif
#endif
