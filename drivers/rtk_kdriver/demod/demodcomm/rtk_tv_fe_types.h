/***************************************************************************************************
  File        : tv_fe_types.h
  Description : type definitions for TV Frontend Control
  Author      : Kevin Wang (kevin_wang@realtek.com.tw)
****************************************************************************************************
    Update List :
----------------------------------------------------------------------------------------------------
    1.0b    |   20080721    | Modify SEC_FILTER_PARAM - Add Complete & pContext fof Section Data Delivery
----------------------------------------------------------------------------------------------------
    2.0     |   20080804    | Modify Return Value of Section Complete callback
            |               |     return sec_data
***************************************************************************************************/
#ifndef __TV_FE_TYPES_H__
#define __TV_FE_TYPES_H__

//#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef FALSE
#      define  FALSE   (0)
#endif

// Constants
#define TUNER_CTRL_OK               (0)
#define TUNER_CTRL_FAIL             (-1)
#define TUNER_CTRL_ENODEV           (-2)
#define TUNER_CTRL_BUFFER_FULL      (-3)
#define TUNER_CTRL_NO_SIGNAL        (-4)
#define TUNER_CTRL_SYNC_LOCK	    (-5)
#define TUNER_CTRL_FUNC_NOT_FINISH	    (-6)

#define DTV_SIGNAL_LOCK           1
#define DTV_SIGNAL_NOT_LOCK       0

#define DTV_BANDWIDTH_6M          6
#define DTV_BANDWIDTH_7M          7
#define DTV_BANDWIDTH_8M          8

enum {
	DTV_STREAM_START = 0,       // Start streming
	DTV_STREAM_STOP,            // Stop streaming
	DTV_STREAM_FLUSH,           // Flush all data in the buffer
	DTV_STREAM_MUTE,            // mute TS output (In this mode, all data will be ingored)
	DTV_STREAM_UNMUTE,          // mute TS output
	DTV_STREAM_CTRL_MAX,
};

#define TV_UPDATE_INTERVAL_INFINITY   0


/////////////////////////////////////////////////////
// Operation Mode
/////////////////////////////////////////////////////
typedef enum {
	TV_OP_MODE_NORMAL,
	TV_OP_MODE_SCANING,
	TV_OP_MODE_STANDBY,
	TV_OP_MODE_ATV_NORMAL,
	TV_OP_MODE_TP_ONLY,     // disalbe any frontned access except tp
} TV_OP_MODE;

/////////////////////////////////////////////////////
// Frontend Status
/////////////////////////////////////////////////////
typedef enum {
	FRONTEND_STATE_IDEL,
	FRONTEND_STATE_STANDBY,
	FRONTEND_STATE_UNLOCK,
	FRONTEND_STATE_LOCKED,
	FRONTEND_STATE_SCANNING,
} FRONTEND_STATE;

/////////////////////////////////////////////////////
// TV System
/////////////////////////////////////////////////////
typedef enum {
	// unknown
	TV_SYS_UNKNOWN,

	TV_SYS_ANALOG_SYS_MIN,
	// PAL
	TV_SYS_BG_PAL,
	TV_SYS_I_PAL,
	TV_SYS_DK_PAL,
	TV_SYS_BG_SECAM,
	TV_SYS_DK_SECAM,
	TV_SYS_L_SECAM,
	TV_SYS_LL_SECAM,

	// NTSC
	TV_SYS_M_NTSC,
	TV_SYS_M_PAL,
	TV_SYS_N_PAL, /* 10 */
	TV_SYS_ANALOG_SYS_MAX,

	//===========================
	// Digital Tv Standard Start
	//===========================
	TV_SYS_DIG_SYS_MIN,

	// DVB
	TV_SYS_DVBT_6M,
	TV_SYS_DVBT_7M,
	TV_SYS_DVBT_8M,

	TV_SYS_DVBC_6M,
	TV_SYS_DVBC_7M,
	TV_SYS_DVBC_8M,

	TV_SYS_DVBT2_1D7M,
	TV_SYS_DVBT2_5M,
	TV_SYS_DVBT2_6M,
	TV_SYS_DVBT2_7M, /* 20 */
	TV_SYS_DVBT2_8M,

	TV_SYS_DVBT2_1D7M_PLP,
	TV_SYS_DVBT2_5M_PLP,
	TV_SYS_DVBT2_6M_PLP,
	TV_SYS_DVBT2_7M_PLP,
	TV_SYS_DVBT2_8M_PLP,

	TV_SYS_AUTOSCAN_6M,
	TV_SYS_AUTOSCAN_7M,
	TV_SYS_AUTOSCAN_8M,

	TV_SYS_DVBS,
	TV_SYS_DVBS2, /* 30 */
	TV_SYS_AUTO_SATELLITE,

	// ATSC
	TV_SYS_ATSC,
	TV_SYS_OPENCABLE_64,
	TV_SYS_OPENCABLE_256,

	// DTMB
	TV_SYS_DTMB,
	TV_SYS_DTMB_6M,
	TV_SYS_DTMB_8M,

	// ISDB_T
	TV_SYS_ISDBT_6M,
	TV_SYS_ISDBT_7M,
	TV_SYS_ISDBT_8M,

	// ISDB-S
	TV_SYS_ISDBS_6M,

	// ABS
	TV_SYS_ABS_S,

	TV_SYS_DIG_SYS_MAX,
	//===========================
	// Digital Tv Standard END....
	//===========================

	// pseudo TV systems
	TV_SYS_FILE,
	TV_SYS_MMTS,
	TV_SYS_RTSP,
	TV_SYS_CURRENT,             // current tv system
	TV_SYS_MAX_NUM

} TV_SYSTEM;

#define IsRawTSSys(x)           ((x >= TV_SYS_FILE)     && (x <= TV_SYS_MMTS))
#define IsAnalogSys(x)          ((x >= TV_SYS_ANALOG_SYS_MIN) && (x <= TV_SYS_ANALOG_SYS_MAX))
#define IsDigitalSys(x)         ((x > TV_SYS_DIG_SYS_MIN)  && (x < TV_SYS_DIG_SYS_MAX))
#define IsDvbSys(x)             ((x >= TV_SYS_DVBT_6M)  && (x <= TV_SYS_DVBC_8M))
#define IsDvbtSys(x)            ((x >= TV_SYS_DVBT_6M)  && (x <= TV_SYS_DVBT_8M))
#define IsDvbt2Sys(x)           ((x >= TV_SYS_DVBT2_1D7M) && (x <= TV_SYS_AUTOSCAN_8M))
#define IsDvbtEx(x)           ((x >= TV_SYS_AUTOSCAN_6M) && (x <= TV_SYS_AUTOSCAN_8M))
#define IsDvbcSys(x)            ((x >= TV_SYS_DVBC_6M)  && (x <= TV_SYS_DVBC_8M))
#define IsDvbsSys(x)            (x == TV_SYS_DVBS)
#define IsDvbs2Sys(x)           ((x >= TV_SYS_DVBS2) && (x <= TV_SYS_AUTO_SATELLITE))
#define IsAbssSys(x)            (x == TV_SYS_ABS_S)
#define IsDtmbSys(x)           ((x >= TV_SYS_DTMB) && (x <= TV_SYS_DTMB_8M))
#define IsAtscSys(x)            (x == TV_SYS_ATSC)
#define IsIsdbtSys(x)           ((x >= TV_SYS_ISDBT_6M) && (x <= TV_SYS_ISDBT_8M))
#define IsOpenCableSys(x)       ((x >= TV_SYS_OPENCABLE_64)    && (x <= TV_SYS_OPENCABLE_256))
#define IsMNSys(x)              ((x >= TV_SYS_M_NTSC)  && (x <= TV_SYS_N_PAL))
#define IsRTSPSys(x)            (x == TV_SYS_RTSP)

#define IsDigitalSysType(x)          ((x == TV_SYS_TYPE_ABS_S) || (x <= TV_SYS_TYPE_DVBS2) ||(x == TV_SYS_TYPE_DVBS)||(x == TV_SYS_TYPE_DVBT2)||(x == TV_SYS_TYPE_DVBT)||(x == TV_SYS_TYPE_DVBC)||(x == TV_SYS_TYPE_DTMB)||(x == TV_SYS_TYPE_ATSC)||(x == TV_SYS_TYPE_OPENCABLE)||(x == TV_SYS_TYPE_ISDBT)||(x == TV_SYS_TYPE_ISDBS)  )
#define IsAnalogSysType(x)         ((x == TV_SYS_TYPE_BGDKIL)  || (x == TV_SYS_TYPE_MN))

typedef enum {
	TV_SYS_TYPE_RAW_TS      = 0x80000000,
	TV_SYS_TYPE_RTSP        = 0x40000000,
	TV_SYS_TYPE_ABS_S       = 0x08000000,
	TV_SYS_TYPE_DVBS2       = 0x04000000,
	TV_SYS_TYPE_DVBS        = 0x02000000,
	TV_SYS_TYPE_DVBT2       = 0x01000000,
	TV_SYS_TYPE_DVBT        = 0x00800000,
	TV_SYS_TYPE_DVBC        = 0x00400000,
	TV_SYS_TYPE_DTMB        = 0x00200000,
	TV_SYS_TYPE_ATSC        = 0x00008000,
	TV_SYS_TYPE_OPENCABLE   = 0x00004000,
	TV_SYS_TYPE_ISDBT       = 0x00000800,
	TV_SYS_TYPE_ISDBS       = 0x00000400,
	TV_SYS_TYPE_BGDKIL      = 0x00000080,
	TV_SYS_TYPE_MN          = 0x00000040,
	TV_SYS_TYPE_UNKNOWN = 0x00000000,
	TV_SYS_TYPE_AUTOSCAN = 0x00000001,

} TV_SYSTEM_TYPE;


/////////////////////////////////////////////////////
// System Modulation
/////////////////////////////////////////////////////
enum TV_MODULATION_E {
	TV_MODULATION_UNKNOWN,
	TV_MODULATION_NONE,
	TV_MODULATION_VSB,
	TV_MODULATION_OFDM,
	TV_MODULATION_PSK,
	TV_MODULATION_QAM,
	TV_MODULATION_DVBC_QAM,
	TV_MODULATION_DTMB_OFDM,
	TV_MODULATION_DVBT2_OFDM,        // T2OFDM
	TV_MODULATION_DVBS,
	TV_MODULATION_DVBS2,
	TV_MODULATION_ISDBT,            // ISDB-T
	TV_MODULATION_ISDBS,				  // ISDB-S
	TV_MODULATION_ABSS,             // ABS-S
	TV_MODULATION_RTSP,
	TV_MODULATION_ATV,
};


//------------------------------------------------
//  COFDM (used by DVB-T/ISDBT)
//------------------------------------------------

enum {
	HIERARCHY_MODE_HIGH = 0,
	HIERARCHY_MODE_LOW  = 0xff,
};


enum {
	OFDM_CONST_BPSK	= 0,
	OFDM_CONST_DQPSK	= 1,
	OFDM_CONST_4  =  4,
	OFDM_CONST_16 = 16,
	OFDM_CONST_32 = 32,
	OFDM_CONST_64 = 64,
	OFDM_CONST_128 = 128,
	OFDM_CONST_256 = 256,
};

enum {
	OFDM_ALPHA_0  =  0,
	OFDM_ALPHA_1  =  1,
	OFDM_ALPHA_2  =  2,
	OFDM_ALPHA_4  =  4,
};

enum {
	OFDM_GI_1_32  =  32,
	OFDM_GI_1_16  =  16,
	OFDM_GI_1_8   =  8,
	OFDM_GI_1_4   =  4,
	OFDM_GI_1_128   =  128,
	OFDM_GI_19_128   =  129,
	OFDM_GI_19_256   =  200,
};

enum {
	OFDM_FFT_1K   =  1,
	OFDM_FFT_2K   =  2,
	OFDM_FFT_4K   =  4,
	OFDM_FFT_8K   =  8,
	OFDM_FFT_16K   =  16,
	OFDM_FFT_32K   =  32,
};

enum {
	OFDM_CODE_RATE_1_2 = 0x12,
	OFDM_CODE_RATE_2_3 = 0x23,
	OFDM_CODE_RATE_3_4 = 0x34,
	OFDM_CODE_RATE_3_5 = 0x35,
	OFDM_CODE_RATE_4_5 = 0x45,
	OFDM_CODE_RATE_5_6 = 0x56,
	OFDM_CODE_RATE_7_8 = 0x78
};

enum {
	OFDM_BW_1p7M  =  1700000,
	OFDM_BW_5M = 5000000,
	OFDM_BW_6M = 6000000,
	OFDM_BW_7M = 7000000,
	OFDM_BW_8M = 8000000
};

// Interleaving length
enum {
	OFDM_INTERLEAVING_LEN_0 = 1,
	OFDM_INTERLEAVING_LEN_1 = 2,
	OFDM_INTERLEAVING_LEN_2 = 4,
	OFDM_INTERLEAVING_LEN_4 = 8,
	OFDM_INTERLEAVING_LEN_8,
	OFDM_INTERLEAVING_LEN_16,
};

//------------------------------------------------
//  DVB-T2
//------------------------------------------------

enum {
	DVBT2_L1_CONST_BPSK	= 0,
	DVBT2_L1_CONST_DQPSK	= 1,
	DVBT2_L1_CONST_QPSK	=  4,
	DVBT2_L1_CONST_16 	= 16,
	DVBT2_L1_CONST_64 	= 64,
};

enum {
	DVBT2_BASE_SISO = 0,
	DVBT2_BASE_MISO = 1,
	DVBT2_NON_DVBT2 = 2,
	DVBT2_LITE_SISO = 3,
	DVBT2_LITE_MISO = 4,
};//S1Signalling

enum {
	DVBT2_PAPR_NONE = 0,
	DVBT2_PAPR_ACE = 1,
	DVBT2_PAPR_TR = 2,
	DVBT2_PAPR_TR_ACE = 3,
};//PAPR

enum {
	DVBT2_PROFILE_BASE = 0,
	DVBT2_PROFILE_LITE = 1,
	DVBT2_PROFILE_ANY = 2,
};//T2 profile

//------------------------------------------------
//  DVBS2 (used by DVB-S / DVB-S2)
//------------------------------------------------

// constellations : number of PSK
enum {
	DVBS2_QPSK = 0,
	DVBS2_8PSK,
	DVBS2_16PSK,
	DVBS2_32PSK
};

enum {
	DVBS2_CR_1_2 = 0,
	DVBS2_CR_2_3,
	DVBS2_CR_3_4,
	DVBS2_CR_5_6,
	DVBS2_CR_7_8,
	DVBS2_CR_3_5,
	DVBS2_CR_4_5,
	DVBS2_CR_8_9,
	DVBS2_CR_9_10
};

enum {
	DVBS2_ROLL_OFF_35 = 0,
	DVBS2_ROLL_OFF_20,
	DVBS2_ROLL_OFF_25,
};

enum {
	DVBS2_PILOT_EN   =   0,
	DVBS2_PILOT_DIS   =   1,
};

enum {
	DVBS2_SPEC_NORMAL   =   0,
	DVBS2_SPEC_INVERSE   =   1,
};


//------------------------------------------------
//  QAM (used by DVB-C / ATSC)
//------------------------------------------------

// constellations : number of QAM
enum {
	QAM_CONST_4    =    4,      // QPSK
	QAM_CONST_16   =   16,
	QAM_CONST_32   =   32,
	QAM_CONST_64   =   64,
	QAM_CONST_128  =  128,
	QAM_CONST_256  =  256,
	QAM_CONST_512  =  512,
	QAM_CONST_1024 = 1024,
	QAM_CONST_AUTO = 1234,
};

// alpha rate : roll of factor
enum {
	QAM_ALPHA_12   =   12,
	QAM_ALPHA_13   =   13,
	QAM_ALPHA_15   =   15,
	QAM_ALPHA_18   =   18,
	QAM_ALPHA_20   =   20,
};

enum {
	QAM_SPEC_NORMAL   =   0,
	QAM_SPEC_INVERSE  =  1,
};

//------------------------------------------------
//  DTMB-OFDM (used by DTMB)
//------------------------------------------------
typedef enum {
	DTMB_OFDM_CARRIER_SINGLE,
	DTMB_OFDM_CARRIER_MULTI,

	DTMB_OFDM_CARRIER_INVALID
} DTMB_OFDM_CARRIER_MODE;

typedef enum {
	DTMB_OFDM_TIM_240,
	DTMB_OFDM_TIM_720,

	DTMB_OFDM_TIM_INVALID,
} DTMB_OFDM_TIME_INTERLEAVER_MODE_E;

// Forward Error Correction Rate (or Convolutional Rate)
typedef enum {
	DTMB_OFDM_FEC_4_OVER_10,  // 0.4
	DTMB_OFDM_FEC_6_OVER_10,  // 0.6
	DTMB_OFDM_FEC_8_OVER_10,  // 0.8

	DTMB_OFDM_FEC_INVALID
} DTMB_OFDM_FEC_RATE_E;

typedef enum {
	DTMB_OFDM_QAM_4_NR,
	DTMB_OFDM_QAM_4,
	DTMB_OFDM_QAM_16,
	DTMB_OFDM_QAM_32,
	DTMB_OFDM_QAM_64,

	DTMB_OFDM_QAM_INVALID
} DTMB_OFDM_CONSTELLATION_E;

// Pseudo-random Noise
typedef enum {
	DTMB_OFDM_PN_420,
	DTMB_OFDM_PN_595,
	DTMB_OFDM_PN_945,

	DTMB_OFDM_PN_INVALID
} DTMB_OFDM_PSEUDO_NOISE_E;

typedef enum {
	DTMB_OFDM_PN_SEQ_CONSTANT,
	DTMB_OFDM_PN_SEQ_VARIABLE,

	DTMB_OFDM_PN_SEQ_INVALID
} DTMB_OFDM_PSEUDO_NOISE_SEQUENCE_E;

/////////////////////////////////////////////////////
// TS_PARAM
// TS information
/////////////////////////////////////////////////////
typedef struct {
	unsigned char mode;
	unsigned char data_order : 1;   // 0 : bit 7 is MSB, 1 : bit 7 is LSB (Parallel)
	unsigned char datapin  : 1;     // 0 : MSB First,   1 : LSB First (Serial)
	unsigned char err_pol  : 1;     // 0 : Active High, 1 : Active Low
	unsigned char sync_pol : 1;     // 0 : Active High, 1 : Active Low
	unsigned char val_pol  : 1;     // 0 : Active High, 1 : Active Low
	unsigned char clk_pol  : 1;     // 0 : Latch On Rising Edge, 1 : Latch On Falling Edge
	unsigned char internal_demod_input : 1;  // used to enable internal demod input
	unsigned char strength_mode;
	unsigned char tsOutEn : 1;
} TS_PARAM;


enum {
	PARALLEL_MODE   = 0,
	SERIAL_MODE     = 1,
	MEMORY_MODE     = 2,
	USB_MODE        = 3,
};

enum {
	MSB_FIRST       = 0,
	LSB_FIRST       = 1
};

enum {
	MSB_D7          = 0,
	MSB_D0          = 1
};

enum {
	ACTIVE_HIGH     = 0,
	ACTIVE_LOW      = 1
};

enum {
	RISING_EDGE     = 0,
	FALLING_EDGE    = 1
};

enum {
	STRENGTH_NORMAL     = 0,
	STRENGTH_STRONG    = 1
};

typedef enum {
	LOOP_THROUGH_OFF = 0,
	LOOP_THROUGH_ON,
	LOOP_THROUGH_ON_HG,
} LOOP_THROUGH_MODE;

typedef enum {
	CLOCK_OUTPUT_DISABLE = 0,
	CLOCK_OUTPUT_ENABLE,
} CLOCK_OUTPUT_MODE;



/////////////////////////////////////////////////////
// TUNER_PARAM
// afc information
/////////////////////////////////////////////////////
typedef enum {
	TV_AFC_UNLOCK  = -1,
	TV_AFC_LOW     =  0,
	TV_AFC_OPTIMAL =  1,
	TV_AFC_HIGH    =  2
} TV_AFC;


typedef enum {
	REALTEKALL,
	MAC6
} IC_NAME;


typedef struct {
	unsigned short  id;
	TV_SYSTEM       std;
	unsigned long   step_freq;
	unsigned long   if_freq;
	unsigned char   if_inversion;
	unsigned char   if_agc_pola;       // postive agc gain, 1: postive, 0:negative
	unsigned long   min_freq;
	unsigned long   max_freq;
	unsigned long   lowband_midband_limit_freq;  // The limit frequency (in Hz) between low-band and mid-band.
	unsigned long   midband_highband_limit_freq; // The limit frequency (in Hz) between mid-band and high-band.
} TUNER_PARAM;


typedef struct {
	unsigned long   freq;               // frequency (Hz)
	unsigned char   inversion;          // inversion
	unsigned char   agc_pola;       // postive agc gain, 1: postive, 0:negative
} IF_PARAM;


typedef struct {
	unsigned char iq_pola;
	unsigned char adc_mode;
	unsigned char agc_pola;
} IQ_PARAM;

/////////////////////////////////////////////////////
// LNB Param
/////////////////////////////////////////////////////

#define LNB_SUPPORT             // flag to indicate LNB Support

typedef enum {
	LNB_MODE_OFF,
	LNB_MODE_13V,
	LNB_MODE_18V,
	LNB_MODE_13V_WITH_22K_BURST,
	LNB_MODE_18V_WITH_22K_BURST,
	LNB_MODE_MAX,
} LNB_MODE;


/////////////////////////////////////////////////////
// Blind Scan Param
/////////////////////////////////////////////////////

#define BLIND_SCAN_SUPPORT             // flag to indicate LNB Support

typedef struct {

	unsigned long   type;           // TV_SYSTEM_TYPE

	unsigned long   min_freq;       // start freq (in Hz)
	unsigned long   max_freq;       // stop  freq (in Hz)

	union {
		// type == TV_SYS_TYPE_DVBS || TV_SYS_TYPE_DVBS2
		struct {
			unsigned long   min_symb;   // minimum symbol rate (in symbols)
			unsigned long   max_symb;   // maximum symbol rate (in symbols)
			LNB_MODE        lnb_mode;   // lnb mode
		} dvb_sx;
	};

} BLIND_SCAN_PARAM;

/////////////////////////////////////////////////////
// FE_PARAM
// afc information
/////////////////////////////////////////////////////

typedef enum TV_MODULATION_E TV_MODULATION;

#define SC_AUTO_OFST         (0xFFFFFFFF)
#define SC_WAIT_FOREVER      (0xFFFFFFFF)

typedef enum {
	SCAN_RANGE_NONE,
	SCAN_RANGE_1_6,
	SCAN_RANGE_2_6,
	SCAN_RANGE_3_6,
	SCAN_RANGE_MAX,
} SCAN_RANGE;

#define SC_RANGE_0           SCAN_RANGE_NONE        // 0 no offset
#define SC_RANGE_1_6         SCAN_RANGE_1_6         // 0 +/- 166.67KHz
#define SC_RANGE_1_3         SCAN_RANGE_2_6         // 0 +/- 166.67KHz +/- 300KHz
#define SC_RANGE_1_2         SCAN_RANGE_3_6         // 0 +/- 166.67KHz +/- 300KHz +/- 500KHz

typedef enum {
	CH_NORMAL_MODE,
	CH_SCAN_MODE,
	CH_UNKNOW,
} CH_MODE;

typedef	struct {
	unsigned char   demod_param_en;
	unsigned long   if_freq;               /* if frequency (Hz) */
	unsigned char   if_inversion;       /* 0: if non_inversion 1:if inversion */
	unsigned char   agc_pola;       /* postive agc gain, 0: postive, 1:negative */
} TUN_DEMOD_PARA;

typedef struct
{
	unsigned int	PIF[9];
	unsigned int	StepSize;
}TUNER_TABLE_PARAM;

typedef union {
	TV_MODULATION       mod;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/

		unsigned char   level;      // it should be 8 or 16
	} vsb;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/

		unsigned short  constellation;
	} psk;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/

		unsigned int   bandwidth;
		unsigned char   hierarchy;
		unsigned short  constellation;
		unsigned char   alpha;
		unsigned char   code_rate_hp;
		unsigned char   code_rate_lp;
		unsigned char   guard_interval;
		unsigned char   fft_mode;
		unsigned int  cell_ID;
		unsigned char  bSpectrumInv;
		unsigned char  bProfileHP;

	} ofdm;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/

		unsigned short   constellation;
		unsigned char    spectrum_inverse;
	} qam;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/

		unsigned short   constellation;
		unsigned long    symbol_rate;
		unsigned char    alpha;
		unsigned char    spectrum_inverse;
	} dvbc_qam;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/

		DTMB_OFDM_TIME_INTERLEAVER_MODE_E      tim;
		DTMB_OFDM_CARRIER_MODE                 carrier_mode;
		unsigned int guard_interval;

		struct {
			DTMB_OFDM_PSEUDO_NOISE_E           mode;
			DTMB_OFDM_PSEUDO_NOISE_SEQUENCE_E  seq;
		} pn;

		struct {
			DTMB_OFDM_FEC_RATE_E               rate;
			DTMB_OFDM_CONSTELLATION_E          constellation;
		} fec;

		unsigned int usrData;  // used to store device specific or user-defined data
	} dtmb_ofdm;



	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/

		unsigned long    symbol_rate;
		unsigned char    zapping_mode;
		unsigned char    modulation;
		unsigned char    code_rate;
		unsigned char    pilot_onoff;
		unsigned char    spec_invert;
		LNB_MODE         lnb_mode;
		unsigned char 	 DiseqcCmdCnt;
		unsigned char 	 DiseqcCmd[64];
		unsigned char 	 IsBlindsearch;
		unsigned long    freq_khz;
	} dvbs;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/

		unsigned long    symbol_rate;
		unsigned char    spectrum_inv: 1;
		LNB_MODE         lnb_mode;
	} abss;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/

		unsigned int   bandwidth;
		unsigned char   hierarchy;
		unsigned short  constellation;
		unsigned char   alpha;
		unsigned char   code_rate_hp;
		unsigned char   code_rate_lp;
		unsigned char   guard_interval;
		unsigned char   fft_mode;
		unsigned char    plp_cnt;
		unsigned char    plp[256];
		int plp_type[256];
		int plp_select;
		unsigned char profile;
		unsigned char fec_type;
		unsigned int cell_ID;
		unsigned char  bSpectrumInv;
		unsigned char  bProfileHP;

	} dvbt2_ofdm;

	struct {
		unsigned char bwExt;
		unsigned char s1;
		unsigned char s2;
		unsigned char fftMode;
		unsigned char gi;
		unsigned char papr;
		unsigned char mod;
		unsigned char code_rate;
		unsigned char pp;
		unsigned char version;
		int cell_ID;
	} dvbt2_L1pre;

	struct {
		unsigned long fefLength;
	} dvbt2_L1post;

	struct {
		unsigned char   tx_id_availability;
		unsigned int    cell_id;
		unsigned int    network_id;
		unsigned int    t2_system_id;
	} dvbt2_TXID;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/

		unsigned long    segment_num;
		unsigned long    subchannel_num;
		unsigned int trans_mode;
		unsigned int guard_interval;
		unsigned char  bSpectrumInv;

		struct isdbt_layer {
			unsigned int    segment_num;
			unsigned short constellation;
			unsigned char 	code_rate;
			unsigned int    time_intlv;

		} layer[3];
	} isdbt;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/

		unsigned long       symbol_rate;
		LNB_MODE            lnb_mode;
		unsigned short      ts_id;
	} isdbs;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/

	} analog;

	struct {
		TV_MODULATION       mod;
		char*            fname;
	} ts_file;

	struct {
		TV_MODULATION       mod;

		char*            pVirtualAddr;
		char*            PhyAddr;
		unsigned long    Size;
	} m2m;

	struct {
		TV_MODULATION       mod;

		int              port;
		char             addr[16];	//IPV4
	} rtsp;

} TV_SIG_INFO;


typedef struct {
	unsigned long   snr;
	unsigned long           ber;
	unsigned long           per;
	unsigned char	iter;
	unsigned long   	ucblocks;
	unsigned char   	strength;
	unsigned char   	quality;
	signed long 	rflevel;
	unsigned long	     dbuvPower;
	unsigned long   	agc;
	unsigned char       nosig;
	unsigned char       trlock;
	unsigned char       inner;

	struct {
		unsigned long ber_num;
		unsigned long ber_den;
	} layer_ber;

	struct {
		unsigned long per_num;
		unsigned long per_den;
	} layer_per;

	unsigned int DemodFwVersion;
	unsigned char   emergency_flag;
} TV_SIG_QUAL;


typedef struct {
	unsigned int   IcName;
	unsigned int   IcVersion;
	unsigned int   PGAMode;
	unsigned int   PGAGain;
	unsigned int   IfPathType;
} TV_DEMOD_INFO;

typedef enum {
	TV_QUAL_SNR,
	TV_QUAL_BEC,            // Bit error count
	TV_QUAL_BER,            // BER
	TV_QUAL_BER_L1,         // BER for ISDB-T LayerA/ DVB-T HP
	TV_QUAL_BER_L2,         // BER for ISDB-T LayerB/ DVB-T LP
	TV_QUAL_BER_L3,         // BER for ISDB-T LayerC
	TV_QUAL_PEC,            // packet error count
	TV_QUAL_PER,            // PER
	TV_QUAL_PER_L1,         // PER for ISDB-T LayerA/ DVB-T HP
	TV_QUAL_PER_L2,         // PER for ISDB-T LayerB/ DVB-T LP
	TV_QUAL_PER_L3,         // PER for ISDB-T LayerC
	TV_QUAL_ITER,
	TV_QUAL_UCBLOCKS,
	TV_QUAL_SIGNAL_STRENGTH,
	TV_QUAL_SIGNAL_QUALITY,
	TV_QUAL_SIGNAL_POWER,
	TV_QUAL_AGC,
	TV_QUAL_NOSIG,
	TV_QUAL_INNERLOCK,
	TV_QUAL_DEMODFWVERSION,
	TV_QUAL_EMERGENCY_FLAG,
	TV_QUAL_CUSTOMER_LG,

} ENUM_TV_QUAL;

/////////////////////////////////////// DISEQC Command ////////////////////////////////////////////
//#ifdef DISEQC_SUPPORT_EN

typedef enum {
	DISEQC_TONE_MODE_A,
	DISEQC_TONE_MODE_B,
	DISEQC_TONE_MODE_MAX,
} DISEQC_TONE_MODE;

//#endif

/////////////////////////////////////// Extra Command ////////////////////////////////////////////

#ifdef DEVICE_ATTR_EN

typedef struct {
	char*     name;           // name of the attribute
	char      mode;           // mode of attribute
	char*     desc;           // desc
	void*     own;            // owner of the attribute

#define DEV_ATTR_CAP_RD         0x1
#define DEV_ATTR_CAP_WR         0x2
#define DEV_ATTR_CAP_RW        (DEV_ATTR_CAP_RD | DEV_ATTR_CAP_WR)
	unsigned long   id;

} DEV_ATTR;

#define __ATTR(name,mode,desc, id)     { (char*)#name, mode, (char*) desc, NULL, (unsigned long) id }
#define __ATTR_RO(name, desc, id)      { (char*)#name, DEV_ATTR_CAP_RD, (char*) desc, NULL, (unsigned long) id }
#define __ATTR_WR(name, desc, id)      { (char*)#name, DEV_ATTR_CAP_WR, (char*) desc, NULL, (unsigned long) id }
#define __ATTR_RW(name, desc, id)      { (char*)#name, DEV_ATTR_CAP_RW, (char*) desc, NULL, (unsigned long) id }
#define __ATTR_NULL()                  { NULL,  0, 0, 0, 0 }

#define DEVICE_ATTR(name, mode, desc, id) \
    static DEV_ATTR dev_attr_##name = __ATTR(name, mode, desc, id)

#define DEV_ATTR_RO(name, desc, id)        DEVICE_ATTR(name, DEV_ATTR_CAP_RD, desc, id)
#define DEV_ATTR_WR(name, desc, id)        DEVICE_ATTR(name, DEV_ATTR_CAP_WR, desc, id)
#define DEV_ATTR_RW(name, desc, id)        DEVICE_ATTR(name, DEV_ATTR_CAP_RW, desc, id)


class Device
{
public:

	Device()
	{
		m_pAttrList  = NULL;     // AttributeList
		m_AttrCounts = 0;
	}

	virtual ~Device() {}

protected:
	DEV_ATTR*       m_pAttrList;
	int             m_AttrCounts;

public:

	virtual int EnumAttr(int ofst, DEV_ATTR* pAttr)
	{
		if (ofst >= m_AttrCounts)
			return TUNER_CTRL_FAIL;

		*pAttr = *(m_pAttrList + ofst);

		return TUNER_CTRL_OK;
	}

	virtual int ShowAttr(const DEV_ATTR* pAttr, char* pBuff, unsigned int BuffLen)
	{
		return TUNER_CTRL_FAIL;
	}

	virtual int StoreAttr(const DEV_ATTR* pAttr, const char* pBuff, unsigned int BuffLen)
	{
		return TUNER_CTRL_FAIL;
	}
};

#endif // __DEVICE_ATTR_EN__


/////////////////////////////////////// FE Command ////////////////////////////////////////////

typedef enum {
	// Please Add your command over here...
	TV_FECTL_INSPECT_SIGNAL,

	// Defined by Libar
	TV_FECTL_LIBAR_TUNER_INIT,
	TV_FECTL_LIBAR_TUNER_RESET,
	TV_FECTL_LIBAR_SHOW_STATUS_MIN_DVB_T,
	TV_FECTL_LIBAR_SHOW_STATUS_MIN_ATSC,

} ENUM_TV_FECTL;






// lgms_kimsuyoung_20090522, TUNER_JIG_ANDY
typedef struct {
	unsigned char       chip_id;
	int                 frq_cnt;        //center freq.
	unsigned char       frq_lock;   // =>1 ;lock
	unsigned int        bandwith;

	unsigned char       snr_cal;        // Quality(0~100%)
	unsigned char       ifagc_cal;  // Strength(0~100%)

	union {
		unsigned short  reg;
		struct {                    // low bit first
			unsigned short  fft     : 2;    // 1,0
			unsigned short  gi      : 2;    // 3,2
			unsigned short  lp      : 3;    // 6,,4
			unsigned short  hp      : 3;    // 9,,7
			unsigned short  hier    : 3;    //12,,10
			unsigned short  constel     : 2;    //14,13
			unsigned short  valid   : 1;    //15
		} bit;
	} TPS;

	int             frq_offset;
	unsigned short  agc_gain;       // 14bit
	unsigned char       snr;
	unsigned short  rs_ubc;
	unsigned int        ubc_total;          // ubc total


	unsigned int         rs_err_cnt;
	unsigned int         rs_err_per;
	unsigned int         vit_out_ber;       // Viterbi_output_BER
	unsigned int         vit_err_cnt;
	unsigned int         vit_err_per;
	unsigned int         vit_inp_ber;       // Viterbi_input_BER

	union {
		unsigned char   reg;
		struct {                    // low bit first
			unsigned char   agc     : 1;    // No/Yes
			unsigned char   sym     : 1;
			unsigned char   ofdm    : 1;    // No/Yes
			unsigned char   tps     : 1;
			unsigned char   res     : 1;    // No/Yes
			unsigned char   fec     : 1;
			unsigned char   full    : 1;    // No/Yes
			unsigned char   si      : 1;
		} bit;
	} STATUS0;                                                  //Data 5

} TU_JIG_STATUS;


typedef struct {
	unsigned char       status003;
	int                 frq_cnt;    //center freq.
	unsigned char       frq_lock;   // =>1 ;lock
	unsigned char       op_mode;    // 64QAM/256QAM/VSB

	unsigned char       snr_cal;    // Quality(0~100%)
	unsigned char       ifagc_cal;  // Strength(0~100%)
	unsigned long               ber;

	int                 frq_offset;
	short               ifacc;
	unsigned short      packet_err; //FEC Packet Error Counter(50c,50d)
	unsigned char       snr_raw;

	unsigned char       lock_cr;
	unsigned char       lock_tr;
	unsigned char       lock_viterbi;
	unsigned char       lock_fec;
	unsigned char       lock_mpeg;
	unsigned char       lock_sync;

} TU_JIG_STATUS_ATSC;


#ifdef __cplusplus
}
#endif

#endif  //__TV_FE_TYPES_H__
