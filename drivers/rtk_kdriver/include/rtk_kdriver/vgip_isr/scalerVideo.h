/***************************************************************************
                          scalerVideo.h  -  description
                             -------------------
    begin                : Mon Dec 22 2008
    copyright           : (C) 2008 by hsliao
    email                : hsliao@realtek.com
 ***************************************************************************/

#ifndef __ISR_SCALERVIDEO_H__
#define __ISR_SCALERVIDEO_H__

#include <scalercommon/vipCommon.h>
//COLOR_HISTOGRAM_LEVEL 32         // Y histogram level
//COLOR_HUE_HISTOGRAM_LEVEL 24     // Hue histogram MAX
//COLOR_AutoSat_HISTOGRAM_LEVEL 32 // Sat histogram MAX
//#include "rtd_types.h"
#include <scalercommon/scalerCommon.h>
#include <rbus/vdpq_reg.h>
#include "vgip_isr/scalerVIP.h"

#define CONFIG_DCC_ENABLE 1 // It could be removed in LV.

#define _VIDEO_INDEX	0xb8010000

#ifdef CONFIG_3D_DEBUG // print scaler's debug messages in linux kernel space, open it by make menuconfig
	#define VDCPrint printk
#else
	#define VDCPrint(format,args...)
#endif

#define VD_3D_TABLE_SIZE		30
#define VD_MOTION_STEP		8
#define VD_TOP_NOISE_STATUS 5

#define _TV_NTSC	0
#define _TV_PAL		1
#define _AV_NTSC	2
#define _AV_PAL		3
#define _Table_total	4

#define _ms_0	0	// motion status 0 : still
#define _ms_1	1	// motion status 1
#define _ms_2	2	// motion status 2
#define _ms_3	3	// motion status 3
#define _ms_4	4	// motion status 4
#define _ms_5	5	// motion status 5
#define _ms_6	6	// motion status 6 : motion
#define _ms_total	7

#define VD_MOTION_DIR_UP   1
#define VD_MOTION_DIR_DOWN 0
#define DI_SMD_BIN_NUM 16
#define DI_FMV_BIN_NUM 21

typedef enum _VDC_H_DETECT_MODE {
	VDC_H_DETECT_DEFAULT=0,
	VDC_H_DETECT_VBI_CO_CHANNEL,
} _VDC_H_DETECT_MODE;

typedef enum _VD_STATUS
{
// NO. // Status Name                       // Comment
       // VD statistic related parameters
/* 0*/ VD_STATUS_SLP = 0,
/* 1*/ VD_STATUS_HIFREQ_NOT_SMALL,
/* 2*/ VD_STATUS_HOR_C_CHANGE,
/* 3*/ VD_STATUS_TEMPORAL_SPD_SMALL,
/* 4*/ VD_STATUS_MGHF_FLAG,
/* 5*/ VD_STATUS_NOISE_VARIANCE_MEAN,
/* 6*/ VD_STATUS_NOISE_DENSITY,
/* 7*/ VD_STATUS_NOISE_LARGE_VARIANCE_MEAN,
       // VD firmware special flag
/* 8*/ VD_STATUS_SMD,                       // This flag is TRUE when SMD Flag = TRUE
/* 9*/ VD_STATUS_SMD_STRONG,                // This flag is TRUE when VD SMD Flag = TRUE
/*10*/ VD_STATUS_SMD_IEGSM,                 // Preserved from before
/*11*/ VD_STATUS_MOVING_CAN                 // Preserved from before
} VD_STATUS;

// VD Register control switch
typedef enum _ScalerVideo_RegisterControlSwitch
{
  VD_REG_CTRL_ENABLE = 0,
  VD_REG_CTRL_DISABLE
} ScalerVideo_RegisterControlSwitch;

// VD bitwise operation
typedef enum _ScalerVideo_BitWiseOperationMode
{
  VD_BIT_SET = 0,
  VD_BIT_GET,
} ScalerVideo_BitWiseOperationMode;

// VD Buffer related
typedef enum _ScalerVideo_SetType
{
  VD_APPLY_SET = 0,
  VD_RESET_SET // currently we don't have RESET_SET
} ScalerVideo_SetType;

typedef struct _ScalerVideo_ApplyResetSet
{
  unsigned char SetNum;
  unsigned char SetType;
} ScalerVideo_ApplyResetSet;

typedef enum _ScalerVideo_BufferOperation
{
  VD_BUFFER_CLEAR_BY_ORDER = 0,
  VD_BUFFER_CLEAR_RESET_FIRST,
  VD_BUFFER_CLEAR_RESET_SET,
  VD_BUFFER_CLEAR_APPLY_SET,
  VD_BUFFER_RESET_IDX
} ScalerVideo_BufferOperation;

#define VD_BUFFER_LENGTH 64
typedef struct _ScalerVideo_SetBuffer
{
  // VD apply buffer
  ScalerVideo_ApplyResetSet Buffer[VD_BUFFER_LENGTH];
  unsigned char CurIndex;
} ScalerVideo_SetBuffer;

typedef struct _ScalerVideo_BlackLevelStatus
{
  // information
  unsigned char Contrast;
  unsigned char Brightness;
  unsigned char Hue;
  unsigned char Saturation;
  // parameters offset
  int Offset_SatRatioSum_Bin_05_31;
} ScalerVideo_BlackLevelStatus;

typedef enum _ScalerVideo_MotionDir
{
	DIR_NONE = 0,
	DIR_TO_TOP,
	DIR_TO_BOT,
	DIR_TO_LEFT,
	DIR_TO_RIGHT
} ScalerVideo_MotionDir;

typedef struct _ScalerVideo_MotionVector
{
	ScalerVideo_MotionDir Dir;
	unsigned char Offset;
} ScalerVideo_MotoinVector;

typedef struct _ScalerVideo_DynamicREG
{
    unsigned char DeXC_Enable;
    unsigned char DeXC_Threshold;
    unsigned char ChromaLPF_BandWidth;
    unsigned char Hor_cdiff_threshold_base;
    unsigned char Ver_cdiff_threshold_base;
    unsigned char Directional3D_dir;
    unsigned char Directional3D_bld_ratio;
} ScalerVideo_DynamicREG;

typedef struct _ScalerVideo_DetectionStatus
{
    // source related
    unsigned char   src_is_tv;
    unsigned char  SourceFromSystem;
    unsigned char  VD_Mode; // VDC_MODE_XXXX
    unsigned char  YCSepModeFromSystem;
    unsigned char  YCSepModeFromReg;
    unsigned char  Source;
    // VD statistic
    unsigned int Status_SLP;
    unsigned int Status_HighFreq_not_small;
    unsigned int Status_Hor_C_change;
    unsigned int Status_Temporal_spd_small;
    unsigned char   Status_MGHF_flag;
    unsigned int Noise_Vmm;
    unsigned int Noise_Density;
    unsigned int Noise_meanNxV;
    // motion related
    unsigned char  MotionStatus;
	// frequency offset related
	unsigned char FrequencyOffset;
    // noise status;
    unsigned int NoiseStatus;
    // saturation related
    unsigned char   HighSatFlag_Bin_14_31; // for NTSC
    unsigned char   HighSatFlag_Bin_06_31; // for PAL
    // sat & hue related
    unsigned int Sat_HistogramRatio[COLOR_AutoSat_HISTOGRAM_LEVEL]; // copy from scalerVIP
    unsigned int Hue_Sum;
    unsigned int Hue_HistogramRatio[COLOR_HUE_HISTOGRAM_LEVEL]; // read by scalerVideo
    // SMD related
    unsigned int FMV_BinRatio[DI_FMV_BIN_NUM]; // read by scalerVideo
    unsigned short FMV_LRDiff;
    unsigned int SMD_BinRatio[DI_SMD_BIN_NUM]; // read by scalerVideo
    // Special case flag, some flag hope to merge with scalerVIP DynamicOptimizeSystem
    unsigned char Flag_PAL_DeXC;
    unsigned char Flag_SMD;
    unsigned char Flag_VD_SMD;
    unsigned char Flag_SMD_IEGSM;
    unsigned char Flag_DOS_44;
    unsigned char Flag_DOS_86_91;
    unsigned char Flag_MovingCan;
    unsigned char Flag_SunFlowerRoof;
    unsigned char Flag_PAL_SunFlowerRoof;
    unsigned char Flag_DiagonalEdgeStable;
    unsigned char Flag_DOS_194;
    unsigned char Flag_DOS_4;
    // Dynamic adjust value
    ScalerVideo_DynamicREG DynamicREG;
    // Structure from system
    _system_setting_info* SystemInfoTable;
    _RPC_system_setting_info* RPC_SystemInfoTable;
    _clues* SmartPicClue;
    _RPC_clues* RPC_SmartPicClue;
    SLR_VIP_TABLE* VIPTable;
    ScalerVideo_BlackLevelStatus BlackLevel;
    // Register apply enable
    unsigned char  ApplyEnable;
    unsigned char isRegValueInit;
} ScalerVideo_DetectionStatus;

#define VD_SET_NUM 256
typedef struct _ScalerVideo_DebugInfo
{
    unsigned char PrintTime;
    unsigned char DisableSpecificSetEnable;
    unsigned short DisableSpecificSetNum;
    unsigned short DisableSpecificSetBuffer[VD_SET_NUM];
    unsigned char  DisableSpecificSetBufferIdx;
    unsigned char AutoDisable;
    unsigned char AutoDisable_ApplyBuffer;
    unsigned char LogEnable;
    unsigned char ScanUsedSet;
    unsigned char UsedSet[VD_SET_NUM];
    unsigned char DynamicLogEnable;
    unsigned int DebugValue_1;
    unsigned int DebugValue_2;
    unsigned int DebugValue_3;
    unsigned char OnlyReset;
    unsigned char ExperimentSettingEnable;
    unsigned char isRegValueInit;
    unsigned char PrintTableControlReg;
} ScalerVideo_DebugInfo;

typedef enum _VDPQ_AV_COMMON_APPLY_SET
{
  /*  0*/ AV_COMMON_SETTING_STA = 0,
  /*  1*/ VDPQ_MOTION,				// By motion
  /*  2*/ VDPQ_FORCE_1D_MODE,		// Force VD 1D Mode
  /*  3*/ AV_COMMON_SETTING_END
} VDPQ_AV_COMMON_APPLY_SET;

typedef enum _VDPQ_AV_NTSC_APPLY_SET
{
  /*  0*/ AV_NTSC_SETTING_STA = AV_COMMON_SETTING_END + 1,
  /*  1*/ VDPQ_NTSC_POSTPROC_MF,                    // Postproc. mf ma_cnt0
  /*  2*/ VDPQ_NTSC_POSTPROC_MF_LG,                 // Postproc. mf ma_cnt0
  /*  3*/ VDPQ_NTSC_CHROMA_VLPF_ENABLE,
  /*  4*/ VDPQ_NTSC_POST2DBPF_CDIFF,
  /*  5*/ VDPQ_NTSC_HIGH_SAT_DOTCRAWL_0,
  /*  6*/ VDPQ_NTSC_HIGH_SAT_DOTCRAWL_1,
  /*  7*/ VDPQ_NTSC_HIGH_SAT_DIVERSE_HUE,           // DOS[45], because of Post2DBPF's delay-bug at Post-Proc., use 3D-decoding at flat region and weaker DeXC setting
  /*  8*/ VDPQ_NTSC_HANGING_BED,                    // DOS[2]
  /*  9*/ VDPQ_NTSC_HIGH_SAT_DIVERSE_HUE_DOTCRAWL,  // DOS[45]
  /* 10*/ VDPQ_NTSC_2D3D_JUMP,                      // DOS[44]
  /* 11*/ VDPQ_NTSC_LG_FAST_MOVING_LOW_SAT,         // Fast Moving Low Frequency Object reduct dot-crawl
  /* 12*/ VDPQ_NTSC_LEAF_MAGENTA_GREEN_CIRCLE,      // DOS Leaf Magenta Green Circle
  /* 13*/ VDPQ_NTSC_VPAN_REDUCE_XC,                 // DOS LowSat VPAN Reduce CrossColor
  /* 14*/ VDPQ_NTSC_MOVING_CAN,                     // DOS[75]
  /* 15*/ VDPQ_NTSC_DEXC,                           // DOS Avoid DeXC TNRXC on still low frequency
  /* 16*/ VDPQ_NTSC_SMD_0,
  /* 17*/ VDPQ_NTSC_SMD_1,
  /* 18*/ VDPQ_NTSC_SMD_2,
  /* 19*/ VDPQ_NTSC_SUN_FLOWER_ROOF,                // DOS[5]
  /* 20*/ VDPQ_NTSC_STRONG_VD_SMD,
  /* 21*/ VDPQ_NTSC_SMD_IRON_TOWER,                 // DOS[39]
  /* 22*/ VDPQ_NTSC_MONO_HUE_AVOID_MOTION_BLUR,     // DOS[4][5]
  /* 23*/ VDPQ_NTSC_LOW_SAT_REMOVE_COLOR,
  /* 24*/ VDPQ_NTSC_XC_REDUCE_BY_C_BPF,             // DOS[40] dexc will make color boundary blur, change to use C mid BPF to remove XC
  /* 25*/ VDPQ_NTSC_HIGH_FREQ_LOW_SAT,              // DOS[41] and Multiburst-liked patterns have large DI high freq.
  /* 26*/ VDPQ_NTSC_2D3D_SWITCH,                    // DOS[42] background 2D to 3D convergence speed
  /* 27*/ VDPQ_NTSC_LOW_SAT_STILL,                  // DOS[38]
  /* 28*/ VDPQ_NTSC_DYNAMIC_HIGH_FREQ_LOW_SAT_Y,    // TG45 CZP, Horizontal motion, Y level < 65, keep clear
  /* 29*/ VDPQ_NTSC_DYNAMIC_HIGH_FREQ_LOW_SAT_XC,   // TG45 CZP, Horizontal motion, Y level < 65, remove cross color
  /* 30*/ VDPQ_NTSC_DYNAMIC_DIRECTIONAL_3D,			// DOS[75]
  /* 31*/ AV_NTSC_SETTING_END
} VDPQ_AV_NTSC_APPLY_SET;

typedef enum _VDPQ_AV_PAL_APPLY_SET
{
  /*  0*/ AV_PAL_SETTING_STA = AV_NTSC_SETTING_END + 1,
  /*  1*/ VDPQ_PAL_POSTPROC_MF,                     // Postproc. mf ma_cnt0
  /*  2*/ VDPQ_PAL_POSTPROC_MF_LG,                  // Postproc. mf ma_cnt0
  /*  3*/ VDPQ_PAL_CHROMA_VLPF_ENABLE,
  /*  4*/ VDPQ_PAL_POST2DBPF_CDIFF,                 // Post2DBPF BPFed C diff small threshold
  /*  5*/ VDPQ_PAL_HIGH_SAT_DOTCRAWL_0,
  /*  6*/ VDPQ_PAL_HIGH_SAT_DOTCRAWL_1,
  /*  7*/ VDPQ_PAL_HIGH_SAT_DIVERSE_HUE,            // LG-PAL Thailand dancing woman (High Sat. Scene) because of Post2DBPF's delay-bug at Post-Proc., use 3D-decoding at flat region and weaker DeXC setting
  /*  8*/ VDPQ_PAL_HANGING_BED,                     // PAL DOS[2]
  /*  9*/ VDPQ_PAL_LOW_SAT,                         // change y BPF for PAL low saturation
  /* 10*/ VDPQ_PAL_MOVING_CAN,                      // LG Moving can
  /* 11*/ VDPQ_PAL_DEXC,                            // LG Avoid DeXC TNRXC on still low frequency
  /* 12*/ VDPQ_PAL_SMD_GRASS_BOAT,
  /* 13*/ VDPQ_PAL_SUN_FLOWER_ROOF,                 // DOS#5
  /* 14*/ VDPQ_PAL_IRON_TOWER,                      // DOS#39
  /* 15*/ VDPQ_PAL_HIGH_SAT_DIVERSE_HUE_DOTCRAWL,   // DOS#45, DOS#46, High saturation and diverse hue scene, need a blur y setting to avoid dot crawl
  /* 16*/ VDPQ_PAL_STRONG_VD_SMD,
  /* 17*/ VDPQ_PAL_DOS_CORN_FIELD,					// Special setting for DOS[4] to avoid slow motion blur
  /* 18*/ VDPQ_PAL_DOS_REF4,						// Special setting for DOS[194] Reference #4
  /* 19*/ VDPQ_PAL_LOW_SAT_REMOVE_COLOR,
  /* 20*/ VDPQ_PAL_XC_REDUCE_BY_C_BPF,              // DOS[40] dexc will make color boundary blur, change to use C mid BPF to remove XC
  /* 21*/ VDPQ_PAL_LEAF_MAGENTA_GREEN_CIRCLE,		// DOS LEAF #42 magenta green circle reduce dot-crawl
  /* 22*/ AV_PAL_SETTING_END
} VDPQ_AV_PAL_APPLY_SET;

typedef enum _VDPQ_AV_OTHER_APPLY_SET
{
  /*  0*/ AV_OTHER_SETTING_STA = AV_PAL_SETTING_END + 1,
  /*  1*/ VDPQ_OTHER_POSTPROC_MF,                   // Postproc. mf ma_cnt0
  /*  2*/ VDPQ_OTHER_POSTPROC_MF_LG,                // Postproc. mf ma_cnt0
  /*  3*/ VDPQ_OTHER_CHROMA_VLPF_ENABLE,
  /*  4*/ VDPQ_OTHER_POST2DBPF_CDIFF,
  /*  5*/ VDPQ_OTHER_HIGH_SAT_DOTCRAWL_0,           // High saturation reduce dotcrawl, NTSC443 | PAL60 , can't enable post2DBPF
  /*  6*/ VDPQ_OTHER_HIGH_SAT_DOTCRAWL_1,           // High saturation reduce dotcrawl
  /*  7*/ VDPQ_OTHER_STRONG_VD_SMD,                 // For situation that can apply strong VD SMD setting
  /*  8*/ VDPQ_OTHER_DIA_EDGE_2D3D_JUMP,            // AV, DOS#28, arm edge jump between 2d 3d, result in blur and clear edge
  /*  9*/ VDPQ_OTHER_LOW_SAT_REMOVE_COLOR,          // AV, DOS#151 ~ DOS#153, remove color when black and white character moves
  /* 10*/ AV_OTHER_SETTING_END
} VDPQ_AV_OTHER_APPLY_SET;

typedef enum _VDPQ_TV_COMMON_APPLY_SET
{
  /*  0*/ TV_COMMON_SETTING_STA = AV_OTHER_SETTING_END + 1,
  /*  1*/ VDPQ_ATV_NOISY_SIGNAL,
  /*  2*/ TV_COMMON_SETTING_END
} VDPQ_TV_COMMON_APPLY_SET;

typedef enum _VDPQ_TV_NTSC_APPLY_SET
{
  /*  0*/ TV_NTSC_SETTING_STA = TV_COMMON_SETTING_END + 1,
  /*  1*/ VDPQ_ATV_NTSC_HIGH_SAT_DOTCRAWL_0,
  /*  2*/ VDPQ_ATV_NTSC_HIGH_SAT_DOTCRAWL_1,
  /*  3*/ VDPQ_ATV_NTSC_NOISY_COLOR_EDGE1,
  /*  4*/ VDPQ_ATV_NTSC_NOISY_COLOR_EDGE2,
  /*  5*/ TV_NTSC_SETTING_END
} VDPQ_TV_NTSC_APPLY_SET;

typedef enum _VDPQ_TV_PAL_APPLY_SET
{
  /*  0*/ TV_PAL_SETTING_STA = TV_NTSC_SETTING_END + 1,
  /*  1*/ VDPQ_ATV_PAL_HIGH_SAT_DOTCRAWL_0,
  /*  2*/ VDPQ_ATV_PAL_HIGH_SAT_DOTCRAWL_1,
  /*  3*/ VDPQ_ATV_PAL_FREQ_OFFSET_SMALL,
  /*  4*/ VDPQ_ATV_PAL_FREQ_OFFSET_LARGE,
  /*  5*/ TV_PAL_SETTING_END
} VDPQ_TV_PAL_APPLY_SET;

typedef enum _VDPQ_TV_OTHER_APPLY_SET
{
  /*  0*/ TV_OTHER_SETTING_STA = TV_PAL_SETTING_END + 1,
  /*  1*/ VDPQ_ATV_OTHER_HIGH_SAT_DOTCRAWL_0,             // ATV, PALM/N color bar dot crawl at Y high frequency issue, disable Post2D Y BPF
  /*  2*/ VDPQ_ATV_OTHER_HIGH_SAT_DOTCRAWL_1,
  /*  3*/ TV_OTHER_SETTING_END
} VDPQ_TV_OTHER_APPLY_SET;

typedef enum _VDPQ_VIP_DYNAMIC_OPTIMIZE_SYSTEM_APPLY_SET
{
  /*  0*/ VIP_DYNAMIC_OPTIMIZE_SYSTEM_SETTING_STA = TV_OTHER_SETTING_END + 1,
  /*  1*/ VDPQ_NTSC_VIP_DOS_CB_5_6,
  /*  2*/ VDPQ_NTSC_VIP_DOS_1,
  /*  3*/ VDPQ_NTSC_VIP_DOS_2,
  /*  4*/ VDPQ_NTSC_VIP_DOS_7,
  /*  5*/ VDPQ_NTSC_VIP_DOS_11,
  /*  6*/ VDPQ_NTSC_VIP_DOS_12,
  /*  7*/ VDPQ_NTSC_VIP_DOS_28,
  /*  8*/ VDPQ_NTSC_VIP_DOS_63,
  /*  9*/ VDPQ_NTSC_VIP_DOS_107,
  /* 10*/ VDPQ_NTSC_VIP_DOS_123,
  /* 11*/ VDPQ_NTSC_VIP_DOS_134,
  /* 12*/ VDPQ_NTSC_VIP_DOS_139,
  /* 13*/ VDPQ_NTSC_VIP_DOS_LEAF_72,
  /* 14*/ VDPQ_PAL_VIP_DOS_2,
  /* 15*/ VDPQ_PAL_VIP_DOS_7,
  /* 16*/ VDPQ_PAL_VIP_DOS_11,
  /* 17*/ VDPQ_PAL_VIP_DOS_12,
  /* 18*/ VDPQ_PAL_VIP_DOS_28,
  /* 19*/ VDPQ_PAL_VIP_DOS_63,
  /* 20*/ VDPQ_PAL_VIP_DOS_107,
  /* 21*/ VDPQ_PAL_VIP_DOS_123,
  /* 22*/ VDPQ_PAL_VIP_DOS_134,
  /* 23*/ VDPQ_PAL_VIP_DOS_139,
  /* 24*/ VDPQ_PAL_VIP_DOS_LEAF_74,
  /* 25*/ VIP_DYNAMIC_OPTIMIZE_SYSTEM_SETTING_END
} VDPQ_VIP_DYNAMIC_OPTIMIZE_SYSTEM_APPLY_SET;

typedef enum _VDPQ_NON_VD_REG_APPLY_SET
{
  /*  0*/ NON_VD_REG_SETTING_STA = VIP_DYNAMIC_OPTIMIZE_SYSTEM_SETTING_END + 1,
  /*  1*/ VDPQ_NTSC_DOS_2_TNR_XC,
  /*  2*/ VDPQ_NTSC_TNR_XC,
  /*  3*/ VDPQ_PAL_DOS_2_TNR_XC,
  /*  4*/ VDPQ_PAL_TNR_XC,
  /*  5*/ VDPQ_PAL_TNR_XC_LGTVPALBGE52,
  /*  6*/ NON_VD_REG_SETTING_END
} VDPQ_NON_VD_REG_APPLY_SET;

typedef enum _VDPQ_FUNCTIONAL_APPLY_SET
{
  /*  0*/ FUNCTIONAL_SETTING_STA = NON_VD_REG_SETTING_END + 1,
  /*  1*/ VDPQ_FUNC_INIT_VALUE,             // The case to record the init register value when change source
  /*  2*/ VDPQ_FUNC_RST_ALL,                // The case to assign the default value to register value
  /*  3*/ VDPQ_FUNC_PWR_REDUCTION_PROTECT,  // The case for xnr & MF protection (scalerVideo_Merlin_PowerReductionProtection)
  /*  4*/ VDPQ_FUNC_WRITE_ADAPTIVE_REG_VAL, // The case to write the register value
  /*  5*/ VDPQ_FUNC_AV_EXP,
  /*  6*/ VDPQ_FUNC_ATV_EXP,
  /*  7*/ VDPQ_FUNC_PRINT_TABLE_CONTROL,	// To print the register controlled register default value
  /*  8*/ FUNCTIONAL_SETTING_END,
  /*  9*/ VDPQ_SETTING_TBL_END
} VDPQ_FUNCTIONAL_APPLY_SET;

unsigned char scalerVideo_readMode(void);
unsigned char scalerVideo_V_locke_status(void);
unsigned char scalerVideo_HV_locke_status(void);
unsigned char scalerVideo_NoSignal_status(void);
unsigned char scalerVideo_noiseStatus(void);
unsigned char scalerVideo_Hlock_irq(void);
void scalerVideo_Clean_Hlock_irq(void);
unsigned char scalerVideo_Vlock_irq(void);
void scalerVideo_Clean_Vlock_irq(void);
unsigned char scalerVideo_Clock_irq(void);
void scalerVideo_Clean_Clock_irq(void);
unsigned char scalerVideo_Nosig_irq(void);
void scalerVideo_Clean_Nosig_irq(void);
unsigned char scalerVideo_Mode_irq(void);
void scalerVideo_Clean_Mode_irq(void);
void scalerVideo_Disable_DCrestore(void);
unsigned char scalerVideo_MotionDecision(void);
void scalerVideo_YC3D_Apply(unsigned char MA_motion, unsigned char src_is_tv);
#if 0 // mark for non-used function in kernel, CSFC 20160728
void scaler_3d_talbe_Factory_Mode(unsigned char value);
#endif
void scalerVideo_adaptive3DAdjust(void);
void scalerVideo_FhAdjust(void);
void scalerVideo_getYCSep(unsigned long arg);
void scalerVideo_setYCSep(unsigned long arg);
void scalerVideo_getFh1DFlag(unsigned long arg);
void scalerVideo_getTVCheck3DFlag(unsigned long arg);
void scalerVideo_setTVCheck3DFlag(unsigned long arg);
void scalerVideo_get3DTableIndex(unsigned long arg);
void scalerVideo_set3DTableIndex(unsigned long arg);
void scalerVideo_vdc_H_detect_setting(_VDC_H_DETECT_MODE mode);
unsigned char scalerVideo_GetCurMotionStatus(void);


extern unsigned short PAL_3D_TH_TV_TABLE[][3];
extern unsigned short PALMN_3D_TH_TV_TABLE[][3];
extern unsigned short NTSC_3D_TH_TABLE[][3];
extern unsigned short PAL_3D_TH_TABLE[][3];
extern unsigned int VD_MA_TH_TABLE[_Table_total][_ms_total][3];
#if 0 //frank@1127 reduce code
extern unsigned char  VDC_1D_SET1[];
extern unsigned char  VDC_1D_SET2[];
extern unsigned char  VDC_1D_SET3[];
#endif

//Elsie 20130503
void CUSTOM_VDPostSPNR(void);

void scalerVideo_F4_global_diff_th(unsigned char diff_th_lower_bound, unsigned char diff_th_upper_bound);
void scalerVideo_F4_DC_level_fierce_chang(unsigned char DC_level_fierce_change_th, unsigned char global_diff_offset_dc_fierce_change);
void scalerVideo_SGHF_still_gray_hifreq_th(unsigned char still_gray_hifreq_th);
void scalerVideo_hifreq_offset_ctrl_all(unsigned char hifreq_offset_180, unsigned char hifreq_offset_160, unsigned char hifreq_offset_140,
	unsigned char hifreq_offset_120, unsigned char hifreq_offset_100, unsigned char hifreq_offset_80, unsigned char hifreq_offset_70, unsigned char hifreq_offset_60,
	unsigned char hifreq_offset_50, unsigned char hifreq_offset_40, unsigned char hifreq_offset_30, unsigned char hifreq_offset_20, unsigned char hifreq_offset_10,
	unsigned char hifreq_offset_0);
void scalerVideo_CVBSamp_th_ctrl_all(unsigned char diff_th_multiple_200, unsigned char diff_th_multiple_180, unsigned char diff_th_multiple_160,
	unsigned char diff_th_multiple_140, unsigned char diff_th_multiple_120, unsigned char diff_th_multiple_100, unsigned char diff_th_multiple_80, unsigned char diff_th_multiple_60,
	unsigned char diff_th_multiple_40, unsigned char diff_th_multiple_20, unsigned char diff_th_multiple_10, unsigned char diff_th_multiple_0);
void EXPERIMENT_ADAP_3DTH(unsigned char LEVEL, unsigned char VD_mode);
void scalerVideo_adaptive3D_by_motion_noise(void);
unsigned char scalerVIP_Diverse_Hue_Detector(unsigned short SimilarHue_Cnt_Th_of_1000, unsigned short LowSat_HueSum_Th);

// Willy 20150623
void LG_AV_STYLE(void);
void LG_AV_NTSC(void);
void LG_AV_PAL(void);
void LG_AV_OTHER(void);
void LG_TV_STYLE(void);
void LG_TV_NTSC(void);
void LG_TV_PAL(void);
void LG_TV_OTHER(void);
void scalerVideo_AV_ResetVDSetting_All(void);
void scalerVideo_ATV_ResetVDSetting_All(void);
unsigned char scalerVideo_ResetVDSetting(unsigned char SetNumber);
void scalerVideo_update_motion_count(unsigned char motion, unsigned char threshold );
unsigned char scalerVideo_array_max(unsigned char* array, unsigned char arraySize);
void scalerVideo_EmergencyDirtyFix(void);
unsigned int scalerVideo_BitWiseOperation(unsigned int Input, unsigned char StartIdx, unsigned char EndIdx, unsigned int Value, ScalerVideo_BitWiseOperationMode OP_Mode);
int scalerVideo_SMD_BinRatioSum(int StartIdx, int EndIdx);
int scalerVideo_SAT_BinRatioSum(int StartIdx, int EndIdx);
int scalerVideo_HUE_BinRatioSum(int StartIdx, int EndIdx);
int scalerVideo_ValueSmooth(unsigned int InputTarget, unsigned int InputCurrent, unsigned int InputStep);
void scalerVideo_ClearFormatChangeBitFromKernel(void);
void scalerVideo_RegApplyCtrl(ScalerVideo_RegisterControlSwitch Status);
void scalerVideo_AddSetToBuffer(unsigned char Num, ScalerVideo_SetType Type);
void scalerVideo_BufferOperation(ScalerVideo_BufferOperation Op);
void scalerVideo_UpdateFrequencyOffset(void);
void scalerVideo_UpdateMotionStatus(void);
void scalerVideo_UpdateNoiseStatus(void);
void scalerVideo_UpdateSourceType(void);
void scalerVideo_UpdateYCSeperationMode(void);
void scalerVideo_UpdateSpecialFlag(void);
//------------------------------------------------------
// DYNAMIC CONTROL REGSITER RELATED FUNCTION
void scalerVideo_DynamicAdjustREG(void);
void scalerVideo_Dynamic_DeXC(void);//SCPU2VCPU, CSFC need to check
int scalerVideo_Dynamic_Chroma_LPF(void);
int scalerVideo_Dynamic_Post2DBPF_Strength(int);
int scalerVideo_Dynamic_Directional3D_FirmwareMode(void);
//------------------------------------------------------
void scalerVideo_UpdateDebugInfo(void);
void scalerVideo_UpdateSaturation(void);
void scalerVideo_UpdateHueHistogram(void);
void scalerVideo_UpdateSMDInfo(void);
void scalerVideo_UpdateSpecialTable(void);
void scalerVideo_UpdateBlackLevelOffset(void);
unsigned char scalerVideo_ApplyVDSetting(unsigned int SetNumber);
void scalerVideo_CalculateNoiseStatus(void);
void scalerVideo_Merlin_PowerReductionProtection(void);
void scalerVideo_MFNotch_Ctrl(unsigned char on_off, unsigned char weight, unsigned char FinalAssign);
unsigned int scalerVideo_Get_VD_MiddleWare(unsigned char Status);
void scalerVideo_Update_HUE_SAT(void);
unsigned int VDPQ_rtd_inl(unsigned int offset);
void VDPQ_rtd_outl(unsigned int offset, unsigned int val);
unsigned char AVD_Clock_Flag_detection(void);
#endif



