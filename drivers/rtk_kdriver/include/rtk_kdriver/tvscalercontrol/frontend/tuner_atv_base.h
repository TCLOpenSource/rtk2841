#ifndef _TUNER_ATV_BASE_H
#define _TUNER_ATV_BASE_H

#ifdef __cplusplus
extern "C" {
#endif


#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/delay.h>



#define YES 1
#define NO 0

#ifndef UINT8
typedef  unsigned char UINT8;
#endif
#ifndef UINT16
typedef  unsigned short UINT16;
#endif
#ifndef UINT32
typedef  unsigned int UINT32;
#endif
#ifndef INT8
typedef  char INT8;
#endif
#ifndef INT16
typedef  short INT16;
#endif
#ifndef INT32
typedef  int INT32;
#endif
#ifndef BOOL
typedef int BOOL;
#endif

typedef struct ATV_TUNER_MODULE_TAG ATV_TUNER_MODULE;
typedef struct SYS_MODULE_TAG SYS_MODULE;
typedef struct I2C_MODULE_TAG I2C_MODULE;

typedef enum {
	I2C_NOADDR=0,
	I2C_ADDR_8=1,
	I2C_ADDR_16=2,
	I2C_CMD_CONTINUE=3, // the i2c command continual sending
} I2C_ADDR_TYPE;

typedef enum TUNER_INPUT_SEL {
        TUNER_INPUT_SEL_CATV = 0,
	 TUNER_INPUT_SEL_AIR = 1,
}TUNER_INPUT_SEL;

typedef enum TV_SCAN_FLOW_TYPE {
        TV_SCAN_FLOW_TYPE_ATV_DTV_indep = 0, // scan all RF freq (40M ~ 900M) in ATV mode, then scan all RF freq in DTV mode
	 TV_SCAN_FLOW_TYPE_ADAD = 1, // scan alternativlye between ATV and DTV per frequency
}TV_SCAN_FLOW_TYPE;

typedef enum {
	TUNER_ATV_VIDEO_MODE_NTSC=0,
	TUNER_ATV_VIDEO_MODE_PAL=1,
	TUNER_ATV_VIDEO_MODE_SECAM,
	TUNER_ATV_VIDEO_MODE_SECAMLA,
	TUNER_ATV_VIDEO_MODE_FM_RADIO,
	TUNER_ATV_VIDEO_MODE_SCAN=0xfe,
	TUNER_ATV_VIDEO_MODE_UNKNOWN=0xff,
} TUNER_ATV_VIDEO_MODE;

typedef enum {
	TUNER_ATV_AUDIO_MODE_MN=0,
	TUNER_ATV_AUDIO_MODE_B=1,
	TUNER_ATV_AUDIO_MODE_GH,
	TUNER_ATV_AUDIO_MODE_I,
	TUNER_ATV_AUDIO_MODE_DK,
	TUNER_ATV_AUDIO_MODE_L,
	TUNER_ATV_AUDIO_MODE_LA,
	TUNER_ATV_AUDIO_MODE_FM_RADIO,
	TUNER_ATV_AUDIO_MODE_UNKNOWN=0xff,
} TUNER_ATV_AUDIO_MODE;
//Function pointer definition
//*******************************************************
//
// Tuner function
//
//*******************************************************
typedef void
(*ATV_TUNER_FP_GET_TUNER_TYPE)(
	ATV_TUNER_MODULE *pTuner,
	UINT8 *pTunerType
	);
typedef void
(*ATV_TUNER_FP_GET_DEVICE_ADDR)(
	ATV_TUNER_MODULE *pTuner,
	UINT8 *pDeviceAddr
	);
typedef UINT8
(*ATV_TUNER_FP_INITIALIZE)(
	ATV_TUNER_MODULE *pTuner
	);
typedef UINT8
(*ATV_TUNER_FP_SET_RF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	UINT32 RfFreqHz
	);
typedef UINT8
(*ATV_TUNER_FP_GET_RF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	UINT32 *pRfFreqHz
	);
typedef UINT8
(*ATV_TUNER_FP_SET_RF_FREQ_SEARCH_HZ)(
	ATV_TUNER_MODULE *pTuner,
	UINT32 RfFreqHz
	);
typedef UINT8
(*ATV_TUNER_FP_GET_RF_FREQ_SEARCH_HZ)(
	ATV_TUNER_MODULE *pTuner,
	UINT32 *pRfFreqHz
	);
typedef UINT8
(*ATV_TUNER_FP_SET_RF_FREQ_AFC_HZ)(
	ATV_TUNER_MODULE *pTuner,
	UINT32 RfFreqHz
	);

typedef UINT8
(*ATV_TUNER_FP_GET_IF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	UINT32 *pIfFreqHz
	);
typedef UINT8
(*ATV_TUNER_FP_GET_DIVER_RATIO)(
	ATV_TUNER_MODULE *pTuner,
	UINT32 RfFreqHz,
	UINT16 *DiverRatio
	);
typedef UINT8
(*ATV_TUNER_FP_GET_RATIO_IN_STEPSIZE)(
	ATV_TUNER_MODULE *pTuner,
	UINT16 *RatioInStepSize
	);
typedef UINT8
(*ATV_TUNER_FP_CHECK_BAND)(
	ATV_TUNER_MODULE *pTuner,
	UINT32 RfFreqHz,
	UINT8 *Band
	);
typedef UINT8
(*ATV_TUNER_FP_SET_STD_MODE)(
	ATV_TUNER_MODULE *pTuner,
	TUNER_ATV_VIDEO_MODE video_mode,
	TUNER_ATV_AUDIO_MODE audio_mode
	);
typedef UINT8
(*ATV_TUNER_FP_GET_STD_MODE)(
	ATV_TUNER_MODULE *pTuner,
	TUNER_ATV_VIDEO_MODE* video_mode,
	TUNER_ATV_AUDIO_MODE* audio_mode
	);
typedef void
(*ATV_TUNER_FP_SET_RF_FINE_TUNE)(
	INT32 finetune_step
	);
typedef void
(*ATV_TUNER_FP_GET_RF_FINE_TUNE)(
	INT32 *finetune_step
	);
//*******************************************************
//
// I2C function
//
//*******************************************************
typedef UINT8
(*I2C_FP_WRITE)(
	I2C_MODULE *pI2CModule,
	UINT8 *pWriteArray
	);
typedef UINT8
(*I2C_FP_READ)(
	I2C_MODULE *pI2CModule, 
	UINT8 *pReadArray);

//*******************************************************
//
// System function
//
//*******************************************************
#if 0
typedef void
(*TIMER_FP_DELAY_MS)(
	UINT16 ms
	);

#else
typedef bool
(*TIMER_FP_DELAY_MS)(
	UINT32 ms
	);
#endif


struct I2C_MODULE_TAG
{
	UINT8 master_id;
	UINT8 device_id;
	UINT16 slave_addr;
	UINT8 len;
	UINT8 addrtype;//0: no addr 1: 8bit 2:16bit

	//I2C interface function
	I2C_FP_WRITE i2c_write;
	I2C_FP_READ i2c_read;
};


struct SYS_MODULE_TAG
{
	//System function
	TIMER_FP_DELAY_MS timer_delay_ms;
};





//Tuner definition

////////////////////////////////////////////////////////////////////////////////////////////////
//
// NXP TDA18272
//
////////////////////////////////////////////////////////////////////////////////////////////////

// TDA18272 extra module
typedef struct TDA18272_EXTRA_MODULE_TAG TDA18272_EXTRA_MODULE;

#if 0
// TDA18272 bandwidth mode setting function pointer
typedef int
(*TDA18272_FP_SET_STANDARD_BANDWIDTH_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int StandardBandwidthMode
	);

// TDA18272 bandwidth mode getting function pointer
typedef int
(*TDA18272_FP_GET_STANDARD_BANDWIDTH_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pStandardBandwidthMode
	);
#endif
// TDA18272 power mode setting function pointer
typedef int
(*TDA18272_FP_SET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int PowerMode
	);

// TDA18272 power mode getting function pointer
typedef int
(*TDA18272_FP_GET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pPowerMode
	);

// TDA18272 IF frequency getting function pointer
typedef int
(*TDA18272_FP_GET_IF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	unsigned long *pIfFreqHz
	);

// TDA18272 extra module
struct TDA18272_EXTRA_MODULE_TAG
{
	// TDA18272 extra variables
	unsigned long CrystalFreqHz;
	int UnitNo;
	int IfOutputVppMode;
	int StandardBandwidthMode;
	int IsStandardBandwidthModeSet;
	int PowerMode;
	int IsPowerModeSet;

	// TDA18272 extra function pointers
	//TDA18272_FP_SET_STANDARD_BANDWIDTH_MODE   SetStandardBandwidthMode;
	//TDA18272_FP_GET_STANDARD_BANDWIDTH_MODE   GetStandardBandwidthMode;
	TDA18272_FP_SET_POWER_MODE                SetPowerMode;
	TDA18272_FP_GET_POWER_MODE                GetPowerMode;
	TDA18272_FP_GET_IF_FREQ_HZ                GetIfFreqHz;
};
////////////////////////////////////////////////////////////////////////////////////////////////
//
// NXP TDA18273
//
////////////////////////////////////////////////////////////////////////////////////////////////

// TDA18273 extra module
typedef struct TDA18273_EXTRA_MODULE_TAG TDA18273_EXTRA_MODULE;

// TDA18273 power mode setting function pointer
typedef int
(*TDA18273_FP_SET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int PowerMode
	);

// TDA18273 power mode getting function pointer
typedef int
(*TDA18273_FP_GET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pPowerMode
	);

// TDA18273 IF frequency getting function pointer
typedef int
(*TDA18273_FP_GET_IF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	unsigned long *pIfFreqHz
	);

// TDA18273 extra module
struct TDA18273_EXTRA_MODULE_TAG
{
	// TDA18273 extra variables
	unsigned long CrystalFreqHz;
	int UnitNo;
	int IfOutputVppMode;
	int StandardMode;
	int IsStandardModeSet;
	int PowerMode;
	int IsPowerModeSet;

	// TDA18273 extra function pointers
	TDA18273_FP_SET_POWER_MODE                SetPowerMode;
	TDA18273_FP_GET_POWER_MODE                GetPowerMode;
	TDA18273_FP_GET_IF_FREQ_HZ                GetIfFreqHz;
};
////////////////////////////////////////////////////////////////////////////////////////////////
//
// NXP TDA18274
//
////////////////////////////////////////////////////////////////////////////////////////////////

// TDA18274 extra module
typedef struct TDA18274_EXTRA_MODULE_TAG TDA18274_EXTRA_MODULE;

// TDA18274 power mode setting function pointer
typedef int
(*TDA18274_FP_SET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int PowerMode
	);

// TDA18274 power mode getting function pointer
typedef int
(*TDA18274_FP_GET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pPowerMode
	);

// TDA18274 IF frequency getting function pointer
typedef int
(*TDA18274_FP_GET_IF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	unsigned long *pIfFreqHz
	);

// TDA18274 extra module
struct TDA18274_EXTRA_MODULE_TAG
{
	// TDA18274 extra variables
	unsigned long CrystalFreqHz;
	int UnitNo;
	int IfOutputVppMode;
	int StandardMode;
	int IsStandardModeSet;
	int PowerMode;
	int IsPowerModeSet;

	// TDA18274 extra function pointers
	TDA18274_FP_SET_POWER_MODE                SetPowerMode;
	TDA18274_FP_GET_POWER_MODE                GetPowerMode;
	TDA18274_FP_GET_IF_FREQ_HZ                GetIfFreqHz;
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// NXP TDA18275
//
////////////////////////////////////////////////////////////////////////////////////////////////

// TDA18275 extra module
typedef struct TDA18275_EXTRA_MODULE_TAG TDA18275_EXTRA_MODULE;

// TDA18274 power mode setting function pointer
typedef int
(*TDA18275_FP_SET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int PowerMode
	);

// TDA18275 power mode getting function pointer
typedef int
(*TDA18275_FP_GET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pPowerMode
	);

// TDA18275 IF frequency getting function pointer
typedef int
(*TDA18275_FP_GET_IF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	unsigned long *pIfFreqHz
	);

// TDA18275 extra module
struct TDA18275_EXTRA_MODULE_TAG
{
	// TDA18275 extra variables
	unsigned long CrystalFreqHz;
	int UnitNo;
	int IfOutputVppMode;
	int StandardMode;
	int IsStandardModeSet;
	int PowerMode;
	int IsPowerModeSet;

	// TDA18275 extra function pointers
	TDA18275_FP_SET_POWER_MODE                SetPowerMode;
	TDA18275_FP_GET_POWER_MODE                GetPowerMode;
	TDA18275_FP_GET_IF_FREQ_HZ                GetIfFreqHz;
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// NXP TDA18275A
//
////////////////////////////////////////////////////////////////////////////////////////////////

// TDA18275A extra module
typedef struct TDA18275A_EXTRA_MODULE_TAG TDA18275A_EXTRA_MODULE;

// TDA18275A power mode setting function pointer
typedef int
(*TDA18275A_FP_SET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int PowerMode
	);

// TDA18275A power mode getting function pointer
typedef int
(*TDA18275A_FP_GET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pPowerMode
	);

// TDA18275A IF frequency getting function pointer
typedef int
(*TDA18275A_FP_GET_IF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	unsigned long *pIfFreqHz
	);

// TDA18275A extra module
struct TDA18275A_EXTRA_MODULE_TAG
{
	// TDA18275A extra variables
	unsigned long CrystalFreqHz;
	int UnitNo;
	int IfOutputVppMode;
	int StandardMode;
	int IsStandardModeSet;
	int PowerMode;
	int IsPowerModeSet;

	// TDA18275A extra function pointers
	TDA18275A_FP_SET_POWER_MODE                SetPowerMode;
	TDA18275A_FP_GET_POWER_MODE                GetPowerMode;
	TDA18275A_FP_GET_IF_FREQ_HZ                GetIfFreqHz;
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// FRESCO FM2150
//
////////////////////////////////////////////////////////////////////////////////////////////////

// FM2150 extra module
typedef struct FM2150_EXTRA_MODULE_TAG FM2150_EXTRA_MODULE;

// FM2150 power mode setting function pointer
typedef int
(*FM2150_FP_SET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int PowerMode
	);

// FM2150 power mode getting function pointer
typedef int
(*FM2150_FP_GET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pPowerMode
	);

// FM2150 IF frequency getting function pointer
typedef int
(*FM2150_FP_GET_IF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	unsigned long *pIfFreqHz
	);

// FM2150 extra module
struct FM2150_EXTRA_MODULE_TAG
{
	// FM2150 extra variables
	unsigned long CrystalFreqHz;
	int UnitNo;
	int IfOutputVppMode;
	int StandardMode;
	int IsStandardModeSet;
	int PowerMode;
	int IsPowerModeSet;

	// FM2150 extra function pointers
	FM2150_FP_SET_POWER_MODE                SetPowerMode;
	FM2150_FP_GET_POWER_MODE                GetPowerMode;
	FM2150_FP_GET_IF_FREQ_HZ                GetIfFreqHz;
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// MAXLINEAR_MXL601
//
////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct MXL601_EXTRA_MODULE_TAG MXL601_EXTRA_MODULE;

// MXL301RF extra module

typedef void 
(*MXL601_FP_GET_RF_STREGTH)(
	ATV_TUNER_MODULE *pTuner,
	int *TuneComplete, 
	INT32*InputLevel, 
	int *AtvTunerLockStatus,
	int *AtvTuneragcLockStatus,
	INT32 *AtvOffset
);

typedef void 
(*MXL601_FP_SET_ATV_IF_AGC_TYPE)(
	ATV_TUNER_MODULE *pTuner,
	UINT8 if_agc_type
);

typedef int  
(*MXL601_FP_GET_ATV_IF_AGC_TYPE)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandardif_agc_type
);

typedef void 
(*MXL601_FP_SET_ATV_IF_OUTPUT_AMP)(
	ATV_TUNER_MODULE *pTuner,
	UINT8 if_output_amp_value
);

typedef int  
(*MXL601_FP_GET_ATV_IF_OUTPUT_AMP)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandardAmpValue
);


typedef void 
(*MXL601_FP_SET_ATV_BandWidth)(
	ATV_TUNER_MODULE *pTuner,
	UINT8 if_BandWidth
);

typedef int  
(*MXL601_FP_GET_ATV_BandWidth)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandard_BandWidth
);


typedef void 
(*MXL601_FP_SET_ATV_xtal_load_cap)(
	ATV_TUNER_MODULE *pTuner,
	UINT8 if_xtal_load_cap_value
);

typedef int  
(*MXL601_FP_GET_ATV_xtal_load_cap)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandard_if_xtal_load_cap_value
);

typedef void 
(*MXL601_FP_SET_ATV_agc_set_point)(
	ATV_TUNER_MODULE *pTuner,
	UINT8 if_agc_set_point_value
);

typedef int  
(*MXL601_FP_GET_ATV_agc_set_point)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandard_if_agc_set_point
);




struct MXL601_EXTRA_MODULE_TAG
{
	// MXL601 extra variables
	UINT8 if_output_amp_value;
	UINT8 if_agc_type;
	int pStandardAmpValue;
	int pStandard_BandWidth;
	int pStandardif_agc_type;
	UINT8 if_BandWidth;
	// MXL601 extra function pointers
	MXL601_FP_GET_RF_STREGTH  GetRfStregth; 
	MXL601_FP_SET_ATV_IF_OUTPUT_AMP		SetATVIFPOUTPUTAMP;
	MXL601_FP_GET_ATV_IF_OUTPUT_AMP 	GetATVIFPOUTPUTAMP;
	MXL601_FP_SET_ATV_IF_AGC_TYPE		SetATVIFAGCTYPE;
	MXL601_FP_GET_ATV_IF_AGC_TYPE		GetATVIFAGCTYPE;
	MXL601_FP_SET_ATV_BandWidth			SetATVIFBW;
	MXL601_FP_GET_ATV_BandWidth			GetATVIFBW;	
	MXL601_FP_SET_ATV_xtal_load_cap		SetATVXTALcap;
	MXL601_FP_GET_ATV_xtal_load_cap		GetATVXTALcap;
	MXL601_FP_SET_ATV_agc_set_point		SetATVAGCSETPOINT;
	MXL601_FP_GET_ATV_agc_set_point		GetATVAGCSETPOINT;

	
	
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// MAXLINEAR_MXL661
//
////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct MXL661_EXTRA_MODULE_TAG MXL661_EXTRA_MODULE;

// MXL301RF extra module

typedef void 
(*MXL661_FP_GET_RF_STREGTH)(
	ATV_TUNER_MODULE *pTuner,
	int *TuneComplete, 
	INT32*InputLevel, 
	int *AtvTunerLockStatus,
	int *AtvTuneragcLockStatus,
	INT32 *AtvOffset
);

typedef void 
(*MXL661_FP_SET_ATV_IF_AGC_TYPE)(
	ATV_TUNER_MODULE *pTuner,
	UINT8 if_agc_type
);

typedef int  
(*MXL661_FP_GET_ATV_IF_AGC_TYPE)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandardif_agc_type
);

typedef void 
(*MXL661_FP_SET_ATV_IF_OUTPUT_AMP)(
	ATV_TUNER_MODULE *pTuner,
	UINT8 if_output_amp_value
);

typedef int  
(*MXL661_FP_GET_ATV_IF_OUTPUT_AMP)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandardAmpValue
);


typedef void 
(*MXL661_FP_SET_ATV_BandWidth)(
	ATV_TUNER_MODULE *pTuner,
	UINT8 if_BandWidth
);

typedef int  
(*MXL661_FP_GET_ATV_BandWidth)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandard_BandWidth
);


typedef void 
(*MXL661_FP_SET_ATV_xtal_load_cap)(
	ATV_TUNER_MODULE *pTuner,
	UINT8 if_xtal_load_cap_value
);

typedef int  
(*MXL661_FP_GET_ATV_xtal_load_cap)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandard_if_xtal_load_cap_value
);

typedef void 
(*MXL661_FP_SET_ATV_agc_set_point)(
	ATV_TUNER_MODULE *pTuner,
	UINT8 if_agc_set_point_value
);

typedef int  
(*MXL661_FP_GET_ATV_agc_set_point)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandard_if_agc_set_point
);




struct MXL661_EXTRA_MODULE_TAG
{
	// MXL661 extra variables
	UINT8 if_output_amp_value;
	UINT8 if_agc_type;
	int pStandardAmpValue;
	int pStandard_BandWidth;
	int pStandardif_agc_type;
	UINT8 if_BandWidth;
	// MXL661 extra function pointers
	MXL661_FP_GET_RF_STREGTH  GetRfStregth; 
	MXL661_FP_SET_ATV_IF_OUTPUT_AMP		SetATVIFPOUTPUTAMP;
	MXL661_FP_GET_ATV_IF_OUTPUT_AMP 	GetATVIFPOUTPUTAMP;
	MXL661_FP_SET_ATV_IF_AGC_TYPE		SetATVIFAGCTYPE;
	MXL661_FP_GET_ATV_IF_AGC_TYPE		GetATVIFAGCTYPE;
	MXL661_FP_SET_ATV_BandWidth			SetATVIFBW;
	MXL661_FP_GET_ATV_BandWidth			GetATVIFBW;	
	MXL661_FP_SET_ATV_xtal_load_cap		SetATVXTALcap;
	MXL661_FP_GET_ATV_xtal_load_cap		GetATVXTALcap;
	MXL661_FP_SET_ATV_agc_set_point		SetATVAGCSETPOINT;
	MXL661_FP_GET_ATV_agc_set_point		GetATVAGCSETPOINT;

	
	
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// Entropic EN402X
//
////////////////////////////////////////////////////////////////////////////////////////////////

// EN402X extra module
typedef struct EN402X_EXTRA_MODULE_TAG EN402X_EXTRA_MODULE;

// EN402X power mode setting function pointer
typedef int
(*EN402X_FP_SET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int PowerMode
	);

// EN402X power mode getting function pointer
typedef int
(*EN402X_FP_GET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pPowerMode
	);

// EN402X IF frequency getting function pointer
typedef int
(*EN402X_FP_GET_IF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	unsigned long *pIfFreqHz
	);

// EN402X extra module
struct EN402X_EXTRA_MODULE_TAG
{
	// EN402X extra variables
	unsigned long CrystalFreqHz;
	int UnitNo;
	int IfOutputVppMode;
	int StandardBandwidthMode;
	int IsStandardBandwidthModeSet;
	int PowerMode;
	int IsPowerModeSet;

	// EN402X extra function pointers
	EN402X_FP_SET_POWER_MODE                SetPowerMode;
	EN402X_FP_GET_POWER_MODE                GetPowerMode;
	EN402X_FP_GET_IF_FREQ_HZ                GetIfFreqHz;
};
////////////////////////////////////////////////////////////////////////////////////////////////
//
// SILICONLABS SI2151
//
////////////////////////////////////////////////////////////////////////////////////////////////

// SI2151 extra module
typedef struct SI2151_EXTRA_MODULE_TAG SI2151_EXTRA_MODULE;

// SI2151 bandwidth mode setting function pointer
typedef UINT8
(*SI2151_FP_SET_STANDARD_MODE)(
	ATV_TUNER_MODULE *pTuner,
	TUNER_ATV_VIDEO_MODE video_mode, 
	TUNER_ATV_AUDIO_MODE audio_mode
	);

// SI2151 bandwidth mode getting function pointer
typedef int
(*SI2151_FP_GET_STANDARD_BANDWIDTH_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pStandardBandwidthMode
	);

typedef void
(*SI2151_FP_SET_STANDARD_BANDWIDTH_MODE)(
	UINT8 set_bandwidth
	);

// SI2151 power mode setting function pointer
typedef int
(*SI2151_FP_SET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int PowerMode
	);

// SI2151 power mode getting function pointer
typedef int
(*SI2151_FP_GET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pPowerMode
	);

// SI2151 IF frequency getting function pointer
typedef int
(*SI2151_FP_GET_IF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	unsigned long *pIfFreqHz
	);

typedef void 
(*SI2151_FP_GET_RF_STREGTH)(
	int *TuneComplete, 
	int *InputLevel, 
	int *AtvTunerLockStatus, 
	int *AtvOffset);

typedef void 
(*SI2151_FP_SET_LNA_ONOFF)(
	bool enable);

typedef int
(*SI2151_FP_GET_ATV_AGC_SPEED)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandardAGCSPEED);

typedef void 
(*SI2151_FP_SET_ATV_AGC_SPEED)(
	UINT8 agc_speed_mode);

typedef void 
(*SI2151_FP_SET_ATV_RF_AGC_TOP)(
	UINT8 rf_agc_top_mode);

typedef  int 
(*SI2151_FP_GET_ATV_RF_AGC_TOP)(
	ATV_TUNER_MODULE *pTuner, int *pStandardRFTOP);

typedef void 
(*SI2151_FP_SET_ATV_IF_PORT_AUXIF_AGC)(
	UINT8 if_port_auxif_agc_mode);

typedef int  
(*SI2151_FP_GET_ATV_IF_PORT_AUXIF_AGC)(
ATV_TUNER_MODULE *pTuner, int *pStandardAUXIFAGC);

typedef void 
(*SI2151_FP_SET_ATV_IF_OUTPUT_AMP)(
	UINT8 if_output_amp_value);

typedef int  
(*SI2151_FP_GET_ATV_IF_OUTPUT_AMP)(
ATV_TUNER_MODULE *pTuner, int *pStandardAmpValue);

typedef void 
(*SI2151_FP_SET_ATV_AFC_ENABLE)(
	bool enable);

typedef int  
(*SI2151_FP_GET_ATV_AFC_ENABLE)(
bool *enable);

typedef int
(*SI2151_FP_GET_ATV_TUNER_INIT_RESULT)(
	ATV_TUNER_MODULE *pTuner, 
	int *pTuner_Init_Result);

// SI2151 extra module
struct SI2151_EXTRA_MODULE_TAG
{
	// SI2151 extra variables
	unsigned long CrystalFreqHz;
	int UnitNo;
	int IfOutputVppMode;
	int StandardBandwidthMode;
	UINT8 set_bandwidth;
	int IsStandardBandwidthModeSet;
	int PowerMode;
	int IsPowerModeSet;
	int video_mode; 
	int audio_mode;
	UINT8 agc_speed_mode;
	int pStandardAGCSPEED;
	UINT8 rf_agc_top_mode;
	int pStandardRFTOP;
	UINT8 if_port_auxif_agc_mode;
	int pStandardAUXIFAGC;
	UINT8 if_output_amp_value;
	int pStandardAmpValue;
	// SI2151 extra function pointers
	SI2151_FP_SET_STANDARD_MODE   SetStandardMode;
	SI2151_FP_GET_STANDARD_BANDWIDTH_MODE   GetStandardBandwidthMode;
	SI2151_FP_SET_STANDARD_BANDWIDTH_MODE   SetStandardBandwidthMode;
	SI2151_FP_SET_POWER_MODE                SetPowerMode;
	SI2151_FP_GET_POWER_MODE                GetPowerMode;
	SI2151_FP_GET_RF_STREGTH		  GetRfStregth;
	SI2151_FP_SET_LNA_ONOFF				SetLNAOnOff;
	SI2151_FP_SET_ATV_AGC_SPEED	SetATVAgcSpeed;
	SI2151_FP_GET_ATV_AGC_SPEED	GetATVAgcSpeed;
	SI2151_FP_SET_ATV_RF_AGC_TOP       SetATVRFAgcTop;
	SI2151_FP_GET_ATV_RF_AGC_TOP       GetATVRFAgcTop;
	SI2151_FP_SET_ATV_IF_PORT_AUXIF_AGC	 SetATVIFPAUXIFAGC;
	SI2151_FP_GET_ATV_IF_PORT_AUXIF_AGC GetATVIFPAUXIFAGC;
	SI2151_FP_SET_ATV_IF_OUTPUT_AMP		SetATVIFPOUTPUTAMP;
	SI2151_FP_GET_ATV_IF_OUTPUT_AMP 	GetATVIFPOUTPUTAMP;
	SI2151_FP_SET_ATV_AFC_ENABLE		SetATVAfcEnable;
	SI2151_FP_GET_ATV_AFC_ENABLE 		GetATVAfcEnable;
	SI2151_FP_GET_ATV_TUNER_INIT_RESULT GetATVTunerInitResult;
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// SILICONLABS SI2156
//
////////////////////////////////////////////////////////////////////////////////////////////////

// SI2156 extra module
typedef struct SI2156_EXTRA_MODULE_TAG SI2156_EXTRA_MODULE;

// SI2156 bandwidth mode setting function pointer
typedef UINT8
(*SI2156_FP_SET_STANDARD_MODE)(
	ATV_TUNER_MODULE *pTuner,
	TUNER_ATV_VIDEO_MODE video_mode, 
	TUNER_ATV_AUDIO_MODE audio_mode
	);

// SI2156 bandwidth mode getting function pointer
typedef int
(*SI2156_FP_GET_STANDARD_BANDWIDTH_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pStandardBandwidthMode
	);

// SI2156 bandwidth mode setting function pointer
typedef void
(*SI2156_FP_SET_STANDARD_BANDWIDTH_MODE)(
	UINT8 set_bandwidth
	);

// SI2156 tuner standard mode setting function pointer
typedef void
(*SI2156_FP_SET_TUNER_STANDARD_BG)(
	UINT8 set_bandwidth,
	UINT32 RfFreqKHz
	);

// SI2156 power mode setting function pointer
typedef int
(*SI2156_FP_SET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int PowerMode
	);

// SI2156 power mode getting function pointer
typedef int
(*SI2156_FP_GET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pPowerMode
	);

// SI2156 IF frequency getting function pointer
typedef int
(*SI2156_FP_GET_IF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	unsigned long *pIfFreqHz
	);

typedef void 
(*SI2156_FP_GET_RF_STREGTH)(
	int *TuneComplete, 
	int *InputLevel, 
	int *AtvTunerLockStatus, 
	int *AtvOffset);

typedef void 
(*SI2156_FP_SET_LNA_ONOFF)(
	bool enable);

typedef int 
(*SI2156_FP_GET_LNA_ONOFF)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandardLNA);

typedef int
(*SI2156_FP_GET_ATV_AGC_SPEED)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandardAGCSPEED);

typedef void 
(*SI2156_FP_SET_ATV_AGC_SPEED)(
	UINT8 agc_speed_mode);

typedef void 
(*SI2156_FP_SET_ATV_RF_AGC_TOP)(
	UINT8 rf_agc_top_mode);

typedef  int 
(*SI2156_FP_GET_ATV_RF_AGC_TOP)(
	ATV_TUNER_MODULE *pTuner, int *pStandardRFTOP);

typedef void 
(*SI2156_FP_SET_ATV_IF_PORT_AUXIF_AGC)(
	UINT8 if_port_auxif_agc_mode);

typedef int  
(*SI2156_FP_GET_ATV_IF_PORT_AUXIF_AGC)(
ATV_TUNER_MODULE *pTuner, int *pStandardAUXIFAGC);

typedef void 
(*SI2156_FP_SET_ATV_IF_OUTPUT_AMP)(
	UINT8 if_output_amp_value);

typedef int  
(*SI2156_FP_GET_ATV_IF_OUTPUT_AMP)(
ATV_TUNER_MODULE *pTuner, int *pStandardAmpValue);

typedef void 
(*SI2156_FP_SET_ATV_AFC_ENABLE)(
	bool enable);

typedef int  
(*SI2156_FP_GET_ATV_AFC_ENABLE)(
bool *enable);

// SI2156 extra module
struct SI2156_EXTRA_MODULE_TAG
{
	// SI2156 extra variables
	unsigned long CrystalFreqHz;
	int UnitNo;
	int IfOutputVppMode;
	int StandardBandwidthMode;
	UINT8 set_bandwidth;
	int IsStandardBandwidthModeSet;
	int PowerMode;
	int IsPowerModeSet;
	int video_mode; 
	int audio_mode;
	UINT8 agc_speed_mode;
	int pStandardAGCSPEED;
	UINT8 rf_agc_top_mode;
	int pStandardRFTOP;
	UINT8 if_port_auxif_agc_mode;
	int pStandardAUXIFAGC;
	UINT8 if_output_amp_value;
	int pStandardAmpValue;
	// SI2156 extra function pointers
	SI2156_FP_SET_STANDARD_MODE   SetStandardMode;
	SI2156_FP_GET_STANDARD_BANDWIDTH_MODE   GetStandardBandwidthMode;
	SI2156_FP_SET_STANDARD_BANDWIDTH_MODE   SetStandardBandwidthMode;
	SI2156_FP_SET_TUNER_STANDARD_BG    SetTunerStandard_BG;
	SI2156_FP_SET_POWER_MODE                SetPowerMode;
	SI2156_FP_GET_POWER_MODE                GetPowerMode;
	SI2156_FP_GET_RF_STREGTH		  GetRfStregth;
	SI2156_FP_SET_LNA_ONOFF				SetLNAOnOff;
	SI2156_FP_GET_LNA_ONOFF				GetLNAOnOff;
	SI2156_FP_SET_ATV_AGC_SPEED	SetATVAgcSpeed;
	SI2156_FP_GET_ATV_AGC_SPEED	GetATVAgcSpeed;
	SI2156_FP_SET_ATV_RF_AGC_TOP       SetATVRFAgcTop;
	SI2156_FP_GET_ATV_RF_AGC_TOP       GetATVRFAgcTop;
	SI2156_FP_SET_ATV_IF_PORT_AUXIF_AGC	 SetATVIFPAUXIFAGC;
	SI2156_FP_GET_ATV_IF_PORT_AUXIF_AGC GetATVIFPAUXIFAGC;
	SI2156_FP_SET_ATV_IF_OUTPUT_AMP		SetATVIFPOUTPUTAMP;
	SI2156_FP_GET_ATV_IF_OUTPUT_AMP 	GetATVIFPOUTPUTAMP;
	SI2156_FP_SET_ATV_AFC_ENABLE		SetATVAfcEnable;
	SI2156_FP_GET_ATV_AFC_ENABLE 		GetATVAfcEnable;
};
////////////////////////////////////////////////////////////////////////////////////////////////
//
// SILICONLABS SI2157
//
////////////////////////////////////////////////////////////////////////////////////////////////

// SI2157 extra module
typedef struct SI2157_EXTRA_MODULE_TAG SI2157_EXTRA_MODULE;

// SI2157 bandwidth mode setting function pointer
typedef UINT8
(*SI2157_FP_SET_STANDARD_MODE)(
	ATV_TUNER_MODULE *pTuner,
	TUNER_ATV_VIDEO_MODE video_mode, 
	TUNER_ATV_AUDIO_MODE audio_mode
	);

// SI2157 bandwidth mode getting function pointer
typedef int
(*SI2157_FP_GET_STANDARD_BANDWIDTH_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pStandardBandwidthMode
	);

typedef void
(*SI2157_FP_SET_STANDARD_BANDWIDTH_MODE)(
	UINT8 set_bandwidth
	);

// SI2157 power mode setting function pointer
typedef int
(*SI2157_FP_SET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int PowerMode
	);

// SI2157 power mode getting function pointer
typedef int
(*SI2157_FP_GET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pPowerMode
	);

// SI2157 IF frequency getting function pointer
typedef int
(*SI2157_FP_GET_IF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	unsigned long *pIfFreqHz
	);

typedef void 
(*SI2157_FP_GET_RF_STREGTH)(
	int *TuneComplete, 
	int *InputLevel, 
	int *AtvTunerLockStatus, 
	int *AtvOffset);

typedef void 
(*SI2157_FP_SET_LNA_ONOFF)(
	bool enable);

typedef int
(*SI2157_FP_GET_ATV_AGC_SPEED)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandardAGCSPEED);

typedef void 
(*SI2157_FP_SET_ATV_AGC_SPEED)(
	UINT8 agc_speed_mode);

typedef void 
(*SI2157_FP_SET_ATV_RF_AGC_TOP)(
	UINT8 rf_agc_top_mode);

typedef  int 
(*SI2157_FP_GET_ATV_RF_AGC_TOP)(
	ATV_TUNER_MODULE *pTuner, int *pStandardRFTOP);

typedef void 
(*SI2157_FP_SET_ATV_IF_PORT_AUXIF_AGC)(
	UINT8 if_port_auxif_agc_mode);

typedef int  
(*SI2157_FP_GET_ATV_IF_PORT_AUXIF_AGC)(
ATV_TUNER_MODULE *pTuner, int *pStandardAUXIFAGC);

typedef void 
(*SI2157_FP_SET_ATV_IF_OUTPUT_AMP)(
	UINT8 if_output_amp_value);

typedef int  
(*SI2157_FP_GET_ATV_IF_OUTPUT_AMP)(
ATV_TUNER_MODULE *pTuner, int *pStandardAmpValue);

typedef void 
(*SI2157_FP_SET_ATV_AFC_ENABLE)(
	bool enable);

typedef int  
(*SI2157_FP_GET_ATV_AFC_ENABLE)(
bool *enable);

typedef int
(*SI2157_FP_GET_ATV_TUNER_INIT_RESULT)(
	ATV_TUNER_MODULE *pTuner, 
	int *pTuner_Init_Result);

// SI2157 extra module
struct SI2157_EXTRA_MODULE_TAG
{
	// SI2157 extra variables
	unsigned long CrystalFreqHz;
	int UnitNo;
	int IfOutputVppMode;
	int StandardBandwidthMode;
	UINT8 set_bandwidth;
	int IsStandardBandwidthModeSet;
	int PowerMode;
	int IsPowerModeSet;
	int video_mode; 
	int audio_mode;
	UINT8 agc_speed_mode;
	int pStandardAGCSPEED;
	UINT8 rf_agc_top_mode;
	int pStandardRFTOP;
	UINT8 if_port_auxif_agc_mode;
	int pStandardAUXIFAGC;
	UINT8 if_output_amp_value;
	int pStandardAmpValue;
	// SI2157 extra function pointers
	SI2157_FP_SET_STANDARD_MODE   SetStandardMode;
	SI2157_FP_GET_STANDARD_BANDWIDTH_MODE   GetStandardBandwidthMode;
	SI2157_FP_SET_STANDARD_BANDWIDTH_MODE   SetStandardBandwidthMode;
	SI2157_FP_SET_POWER_MODE                SetPowerMode;
	SI2157_FP_GET_POWER_MODE                GetPowerMode;
	SI2157_FP_GET_RF_STREGTH		  GetRfStregth;
	SI2157_FP_SET_LNA_ONOFF				SetLNAOnOff;
	SI2157_FP_SET_ATV_AGC_SPEED	SetATVAgcSpeed;
	SI2157_FP_GET_ATV_AGC_SPEED	GetATVAgcSpeed;
	SI2157_FP_SET_ATV_RF_AGC_TOP       SetATVRFAgcTop;
	SI2157_FP_GET_ATV_RF_AGC_TOP       GetATVRFAgcTop;
	SI2157_FP_SET_ATV_IF_PORT_AUXIF_AGC	 SetATVIFPAUXIFAGC;
	SI2157_FP_GET_ATV_IF_PORT_AUXIF_AGC GetATVIFPAUXIFAGC;
	SI2157_FP_SET_ATV_IF_OUTPUT_AMP		SetATVIFPOUTPUTAMP;
	SI2157_FP_GET_ATV_IF_OUTPUT_AMP 	GetATVIFPOUTPUTAMP;
	SI2157_FP_SET_ATV_AFC_ENABLE		SetATVAfcEnable;
	SI2157_FP_GET_ATV_AFC_ENABLE 		GetATVAfcEnable;
	SI2157_FP_GET_ATV_TUNER_INIT_RESULT GetATVTunerInitResult;
};
////////////////////////////////////////////////////////////////////////////////////////////////
//
// SILICONLABS SI2158
//
////////////////////////////////////////////////////////////////////////////////////////////////

// SI2158 extra module
typedef struct SI2158_EXTRA_MODULE_TAG SI2158_EXTRA_MODULE;

// SI2158 bandwidth mode setting function pointer
typedef UINT8
(*SI2158_FP_SET_STANDARD_MODE)(
	ATV_TUNER_MODULE *pTuner,
	TUNER_ATV_VIDEO_MODE video_mode, 
	TUNER_ATV_AUDIO_MODE audio_mode
	);

// SI2158 bandwidth mode getting function pointer
typedef int
(*SI2158_FP_GET_STANDARD_BANDWIDTH_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pStandardBandwidthMode
	);

typedef void
(*SI2158_FP_SET_STANDARD_BANDWIDTH_MODE)(
	UINT8 set_bandwidth
	);

// SI2158 power mode setting function pointer
typedef int
(*SI2158_FP_SET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int PowerMode
	);

// SI2158 power mode getting function pointer
typedef int
(*SI2158_FP_GET_POWER_MODE)(
	ATV_TUNER_MODULE *pTuner,
	int *pPowerMode
	);

// SI2158 IF frequency getting function pointer
typedef int
(*SI2158_FP_GET_IF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	unsigned long *pIfFreqHz
	);

typedef void 
(*SI2158_FP_GET_RF_STREGTH)(
	int *TuneComplete, 
	int *InputLevel, 
	int *AtvTunerLockStatus, 
	int *AtvOffset);

typedef void 
(*SI2158_FP_SET_LNA_ONOFF)(
	bool enable);

typedef int
(*SI2158_FP_GET_ATV_AGC_SPEED)(
	ATV_TUNER_MODULE *pTuner, 
	int *pStandardAGCSPEED);

typedef void 
(*SI2158_FP_SET_ATV_AGC_SPEED)(
	UINT8 agc_speed_mode);

typedef void 
(*SI2158_FP_SET_ATV_RF_AGC_TOP)(
	UINT8 rf_agc_top_mode);

typedef  int 
(*SI2158_FP_GET_ATV_RF_AGC_TOP)(
	ATV_TUNER_MODULE *pTuner, int *pStandardRFTOP);

typedef void 
(*SI2158_FP_SET_ATV_IF_PORT_AUXIF_AGC)(
	UINT8 if_port_auxif_agc_mode);

typedef int  
(*SI2158_FP_GET_ATV_IF_PORT_AUXIF_AGC)(
ATV_TUNER_MODULE *pTuner, int *pStandardAUXIFAGC);

typedef void 
(*SI2158_FP_SET_ATV_IF_OUTPUT_AMP)(
	UINT8 if_output_amp_value);

typedef int  
(*SI2158_FP_GET_ATV_IF_OUTPUT_AMP)(
ATV_TUNER_MODULE *pTuner, int *pStandardAmpValue);

typedef void 
(*SI2158_FP_SET_ATV_AFC_ENABLE)(
	bool enable);

typedef int  
(*SI2158_FP_GET_ATV_AFC_ENABLE)(
bool *enable);

typedef int
(*SI2158_FP_GET_ATV_TUNER_INIT_RESULT)(
	ATV_TUNER_MODULE *pTuner, 
	int *pTuner_Init_Result);

// SI2158 extra module
struct SI2158_EXTRA_MODULE_TAG
{
	// SI2158 extra variables
	unsigned long CrystalFreqHz;
	int UnitNo;
	int IfOutputVppMode;
	int StandardBandwidthMode;
	UINT8 set_bandwidth;
	int IsStandardBandwidthModeSet;
	int PowerMode;
	int IsPowerModeSet;
	int video_mode; 
	int audio_mode;
	UINT8 agc_speed_mode;
	int pStandardAGCSPEED;
	UINT8 rf_agc_top_mode;
	int pStandardRFTOP;
	UINT8 if_port_auxif_agc_mode;
	int pStandardAUXIFAGC;
	UINT8 if_output_amp_value;
	int pStandardAmpValue;
	// SI2158 extra function pointers
	SI2158_FP_SET_STANDARD_MODE   SetStandardMode;
	SI2158_FP_GET_STANDARD_BANDWIDTH_MODE   GetStandardBandwidthMode;
	SI2158_FP_SET_STANDARD_BANDWIDTH_MODE   SetStandardBandwidthMode;
	SI2158_FP_SET_POWER_MODE                SetPowerMode;
	SI2158_FP_GET_POWER_MODE                GetPowerMode;
	SI2158_FP_GET_RF_STREGTH		  GetRfStregth;
	SI2158_FP_SET_LNA_ONOFF				SetLNAOnOff;
	SI2158_FP_SET_ATV_AGC_SPEED	SetATVAgcSpeed;
	SI2158_FP_GET_ATV_AGC_SPEED	GetATVAgcSpeed;
	SI2158_FP_SET_ATV_RF_AGC_TOP       SetATVRFAgcTop;
	SI2158_FP_GET_ATV_RF_AGC_TOP       GetATVRFAgcTop;
	SI2158_FP_SET_ATV_IF_PORT_AUXIF_AGC	 SetATVIFPAUXIFAGC;
	SI2158_FP_GET_ATV_IF_PORT_AUXIF_AGC GetATVIFPAUXIFAGC;
	SI2158_FP_SET_ATV_IF_OUTPUT_AMP		SetATVIFPOUTPUTAMP;
	SI2158_FP_GET_ATV_IF_OUTPUT_AMP 	GetATVIFPOUTPUTAMP;
	SI2158_FP_SET_ATV_AFC_ENABLE		SetATVAfcEnable;
	SI2158_FP_GET_ATV_AFC_ENABLE 		GetATVAfcEnable;
	SI2158_FP_GET_ATV_TUNER_INIT_RESULT GetATVTunerInitResult;
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// RAFAEL R620D
//
////////////////////////////////////////////////////////////////////////////////////////////////
// R620D extra module
typedef struct R620D_EXTRA_MODULE_TAG R620D_EXTRA_MODULE;

// R620D extra module
struct R620D_EXTRA_MODULE_TAG
{
	
};


////////////////////////////////////////////////////////////////////////////////////////////////
//
// RAFAEL R828
//
////////////////////////////////////////////////////////////////////////////////////////////////
// R828 extra module
typedef struct R828_EXTRA_MODULE_TAG R828_EXTRA_MODULE;

// R828 extra module
struct R828_EXTRA_MODULE_TAG
{
	
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// RAFAEL R840
//
////////////////////////////////////////////////////////////////////////////////////////////////
// R840 extra module
typedef struct R840_EXTRA_MODULE_TAG R840_EXTRA_MODULE;

// R840 extra module
struct R840_EXTRA_MODULE_TAG
{
	
};





////////////////////////////////////////////////////////////////////////////////////////////////
//
// FITICOMM FC0014
//
////////////////////////////////////////////////////////////////////////////////////////////////
// FC0014 extra module
typedef struct FC0014_EXTRA_MODULE_TAG FC0014_EXTRA_MODULE;

// FC0014 extra module
struct FC0014_EXTRA_MODULE_TAG
{
	unsigned long CrystalFreqHz;
	int UnitNo;
	int StandardBandwidthMode;
	int IsStandardBandwidthModeSet;
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// SONY RX22X
//
////////////////////////////////////////////////////////////////////////////////////////////////
// RX22X extra module
typedef struct RX22X_EXTRA_MODULE_TAG RX22X_EXTRA_MODULE;

// RX22X extra module
struct RX22X_EXTRA_MODULE_TAG
{
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// SONY RX23X
//
////////////////////////////////////////////////////////////////////////////////////////////////
// RX23X extra module
typedef struct RX23X_EXTRA_MODULE_TAG RX23X_EXTRA_MODULE;

typedef UINT8 
(*RX23X_FP_SET_LNA_ONOFF)(
	bool enable);

typedef void 
(*RX23X_FP_GET_LNA_ONOFF)(
	bool *enable);

typedef void 
(*RX23X_FP_GET_RF_STREGTH)(
	int *InputLevel);

typedef UINT8 
(*RX23X_FP_SET_OUTLMT)(
	UINT8 outlmt);

typedef void 
(*RX23X_FP_GET_OUTLMT)(
	UINT8 *outlmt);

typedef UINT8 
(*RX23X_FP_SET_IF_BPF_GC)(
	UINT8 bpfgc);

typedef void 
(*RX23X_FP_GET_IF_BPF_GC)(
	UINT8 *bpfgc);

typedef UINT8 
(*RX23X_FP_SET_IF_BPF_F0)(
	UINT8 bpffo);

typedef void 
(*RX23X_FP_GET_IF_BPF_F0)(
	UINT8 *bpffo);

typedef UINT8 
(*RX23X_FP_SET_FIF_OFFSET)(
	UINT8 iffo);

typedef void 
(*RX23X_FP_GET_FIF_OFFSET)(
	UINT8 *iffo);

typedef UINT8 
(*RX23X_FP_SET_BW_OFFSET)(
	UINT8 bwo);

typedef void 
(*RX23X_FP_GET_BW_OFFSET)(
	UINT8 *bwo);

typedef UINT8 
(*RX23X_FP_SET_IS_LOWERLOCAL)(
	UINT8 lowerlocal);

typedef void 
(*RX23X_FP_GET_IS_LOWERLOCAL)(
	UINT8 *lowerlocal);

typedef void 
(*RX23X_FP_DUMP_TUNER_RIGISTER)(
	void);

// RX23X extra module
struct RX23X_EXTRA_MODULE_TAG
{
	RX23X_FP_SET_LNA_ONOFF				SetLNAOnOff;
	RX23X_FP_GET_LNA_ONOFF				GetLNAOnOff;
	RX23X_FP_GET_RF_STREGTH			GetRfStregth;
	RX23X_FP_SET_OUTLMT				SetIFoutputvoltage;
	RX23X_FP_GET_OUTLMT				GetIFoutputvoltage;
	RX23X_FP_SET_IF_BPF_GC    			SetIFGainBalance;
	RX23X_FP_GET_IF_BPF_GC				GetIFGainBalance;
	RX23X_FP_SET_IF_BPF_F0				SetBPFfreqOffset;
	RX23X_FP_GET_IF_BPF_F0				GetBPFfreqOffset;
	RX23X_FP_SET_FIF_OFFSET				SetIFfreqOffset;
	RX23X_FP_GET_FIF_OFFSET				GetIFfreqOffset;
	RX23X_FP_SET_BW_OFFSET				SetIFBPFBandwidth;
	RX23X_FP_GET_BW_OFFSET				GetIFBPFBandwidth;
	RX23X_FP_SET_IS_LOWERLOCAL			SetLocal;
	RX23X_FP_GET_IS_LOWERLOCAL			GetLocal;
	RX23X_FP_DUMP_TUNER_RIGISTER		DumpTunerRegister;
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// RF TUNER
//
////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct RFTUNER_EXTRA_MODULE_TAG RFTUNER_EXTRA_MODULE;

#if 0
typedef UINT8
(*RFTUNER_FP_GET_IF_FREQ_HZ)(
	ATV_TUNER_MODULE *pTuner,
	UINT32 *pIfFreqHz
	);
typedef UINT8
(*RFTUNER_FP_GET_DIVER_RATIO)(
	ATV_TUNER_MODULE *pTuner,
	UINT32 RfFreqHz,
	UINT16 *DiverRatio
	);
typedef UINT8
(*RFTUNER_FP_GET_RATIO_IN_STEPSIZE)(
	ATV_TUNER_MODULE *pTuner,
	UINT16 *RatioInStepSize
	);
typedef UINT8
(*RFTUNER_FP_CHECK_BAND)(
	ATV_TUNER_MODULE *pTuner,
	UINT32 RfFreqHz,
	UINT8 *Band
	);
#endif
// RFTUNER extra module
struct RFTUNER_EXTRA_MODULE_TAG
{
	// RFTUNER extra variables

	// RFTUNER extra function pointers
	#if 0
	RFTUNER_FP_GET_IF_FREQ_HZ			GetIfFreqHz;
	RFTUNER_FP_GET_DIVER_RATIO			GeDiverRatio;
	RFTUNER_FP_GET_RATIO_IN_STEPSIZE	GetRatioInStepSize;
	RFTUNER_FP_CHECK_BAND				CheckBand;
	#endif
};



////////////////////////////////////////////////////////////////////////////////////////////////
//
// TV_FRONTEND_CONTROL TUNER
//
////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct TV_FRONTEND_CTRL_MODULE_TAG  TV_FRONTEND_CTRL_MODULE;

struct TV_FRONTEND_CTRL_MODULE_TAG
{	
	UINT8  Id;
	UINT8  CurrentStandard;	
};

////////////////////////////////////////////////////////////////////////////////////////////////

struct ATV_TUNER_MODULE_TAG
{
	// Private variables
	UINT8   TunerType;									///<   Tuner type
	UINT8   DeviceAddr;									///<   Tuner I2C device address
	UINT32  RfFreqHz;										///<   Tuner RF frequency in Hz
	UINT8   IsRfFreqHzSet;											///<   Tuner RF frequency in Hz (setting status)
	UINT32 RfFreqHz_Max;
	UINT32 RfFreqHz_Min;
	TUNER_INPUT_SEL RfInput_Sel;
	UINT8 video_mode;
	UINT8 audio_mode;
	
	union														///<   Tuner extra module used by driving module
	{
		RFTUNER_EXTRA_MODULE    rf_tuner;	
		TDA18272_EXTRA_MODULE    Tda18272;
		TDA18273_EXTRA_MODULE    Tda18273;
		TDA18274_EXTRA_MODULE    Tda18274;
		TDA18275_EXTRA_MODULE    Tda18275;
		TDA18275A_EXTRA_MODULE    Tda18275a;
		MXL601_EXTRA_MODULE	mxl601;
		MXL661_EXTRA_MODULE	mxl661;
		EN402X_EXTRA_MODULE	En402x;
		FM2150_EXTRA_MODULE Fm2150;
		SI2151_EXTRA_MODULE Si2151;
		SI2156_EXTRA_MODULE Si2156;
		SI2157_EXTRA_MODULE Si2157;
		SI2158_EXTRA_MODULE Si2158;
		R620D_EXTRA_MODULE R620d;
		R828_EXTRA_MODULE R828;
		R840_EXTRA_MODULE R840;
		FC0014_EXTRA_MODULE Fc0014;
		RX22X_EXTRA_MODULE Rx22x;
		RX23X_EXTRA_MODULE Rx23x;
		TV_FRONTEND_CTRL_MODULE TvFrontendCtrl;
	}
	Extra;
	
	SYS_MODULE *pSysModule;						///<   Base interface module
	I2C_MODULE *pI2cModule;								///<   I2C bridge module

	// Tuner manipulating functions
	ATV_TUNER_FP_GET_TUNER_TYPE    GetTunerType;				///<   Tuner type getting function pointer
	ATV_TUNER_FP_GET_DEVICE_ADDR   GetDeviceAddr;				///<   Tuner I2C device address getting function pointer

	ATV_TUNER_FP_INITIALIZE        Initialize;					///<   Tuner initializing function pointer
	ATV_TUNER_FP_SET_RF_FREQ_HZ    SetRfFreqHz;					///<   Tuner RF frequency setting function pointer
	ATV_TUNER_FP_GET_RF_FREQ_HZ    GetRfFreqHz;					///<   Tuner RF frequency getting function pointer
	ATV_TUNER_FP_SET_RF_FREQ_SEARCH_HZ SetRfFreqSearchHz;
	ATV_TUNER_FP_GET_RF_FREQ_SEARCH_HZ    GetRfFreqSearchHz;	
	ATV_TUNER_FP_SET_RF_FREQ_AFC_HZ SetRfFreqAfcHz;
	ATV_TUNER_FP_SET_STD_MODE    SetStandardMode;
	ATV_TUNER_FP_GET_STD_MODE    GetStandardMode;
	ATV_TUNER_FP_SET_RF_FINE_TUNE    SetRfFreqFineTune;					///<   Tuner RF frequency setting function pointer
	ATV_TUNER_FP_GET_RF_FINE_TUNE    GetRfFreqFineTune;					///<   Tuner RF frequency getting function pointer

	ATV_TUNER_FP_GET_IF_FREQ_HZ			GetIfFreqHz;
	ATV_TUNER_FP_GET_DIVER_RATIO			GeDiverRatio;
	ATV_TUNER_FP_GET_RATIO_IN_STEPSIZE	GetRatioInStepSize;
	ATV_TUNER_FP_CHECK_BAND				CheckBand;
	

	
};



#ifdef __cplusplus
}
#endif

#endif





















