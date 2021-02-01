/**
 * @file memc_lib.h
 * @brief This header file defines MEMC lib exported apis and data type.
 * @date August.9.2014
 * @version V0.0.2
 * @author Martin/Lixiangjun
 * @par MEMC Library V0.0.2 - Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.2
*/

#ifndef _MEMC_LIB_HEADER_INCLUDE_
#define _MEMC_LIB_HEADER_INCLUDE_

//#include "kw_common.h"
#include "memc_isr/include/kw_type.h"

/*memc isr monitor*/
#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
#define CONFIG_MEMC_ISR_CNT_MAX 400
#define CONFIG_MEMC_IN_ISR_CNT_MAX CONFIG_MEMC_ISR_CNT_MAX
#define CONFIG_MEMC_OUT_ISR_CNT_MAX CONFIG_MEMC_ISR_CNT_MAX
#endif

#ifdef WIN32
#include "regio.h"
#endif

#ifdef DLL_IMPLEMENT
#ifdef __cplusplus
#define DLL_API extern "C" __declspec(dllexport)
#else /* else of __cplusplus*/
#define DLL_API __declspec(dllexport)
#endif /* End of #ifdef __cplusplus */
#else /* else of DLL_IMPLEMENT*/
#ifdef __cplusplus
#define DLL_API extern "C" __declspec(dllimport)
#else /* else of __cplusplus */
#ifdef WIN32
#define DLL_API __declspec(dllimport)
#else /* else of WIN32 */
#define DLL_API
#endif/* End of #ifdef WIN32 */
#endif/* End of #ifdef __cplusplus */
#endif/* End of #ifdef DLL_IMPLEMENT */

#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
#define _ZERO                       0x00
#define _BIT0                       0x01
#define _BIT1                       0x02
#define _BIT2                       0x04
#define _BIT3                       0x08
#define _BIT4                       0x10
#define _BIT5                       0x20
#define _BIT6                       0x40
#define _BIT7                       0x80
#define _BIT8                       0x0100
#define _BIT9                       0x0200
#define _BIT10                      0x0400
#define _BIT11                      0x0800
#define _BIT12                      0x1000
#define _BIT13                      0x2000
#define _BIT14                      0x4000
#define _BIT15                      0x8000
#define _BIT16                      0x10000
#define _BIT17                      0x20000
#define _BIT18                      0x40000
#define _BIT19                      0x80000
#define _BIT20                      0x100000
#define _BIT21                      0x200000
#define _BIT22                      0x400000
#define _BIT23                      0x800000
#define _BIT24                      0x1000000
#define _BIT25                      0x2000000
#define _BIT26                      0x4000000
#define _BIT27                      0x8000000
#define _BIT28                      0x10000000
#define _BIT29                      0x20000000
#define _BIT30                      0x40000000
#define _BIT31                      0x80000000
#endif

/*! MEMC Input signal resolution enum. */
typedef enum
{
	INPUT_1920X1080,					///< 1920X1080 resolution for FPGA Validation
	INPUT_1920X540,						///< 1920X540  resolution for FPGA Validation
	INPUT_3840X2160,					///< 3840x2160 resolution
	INPUT_3840X1080,					///< 3840x1080 resolution, it is 3D input
	INPUT_3840X540,						///< 3840X540 resolution
	INPUT_1920X2160,					///< 1920X2160 resolution
	INPUT_768X480,						///< 768X480 resolution for FPGA Validation
	INPUT_1280X720,						///< 1280X720 resolution for FPGA Validation
	INPUT_RESOLUTION_MAX,
}MEMC_INPUT_RESOLUTION;

/*! MEMC Output signal resolution enum. */
typedef enum
{
	OUTPUT_1920X1080,					///< 1920x1080 resolution for FPGA Validation
	OUTPUT_1920X540,					///< 1920x540  resolution for FPGA Validation
	OUTPUT_3840X2160,					///< 3840x2160 resolution
	OUTPUT_3840X1080,					///< 3840x1080 resolution
	OUTPUT_3840X540, 					///< 3840X540 resolution
	OUTPUT_768X480, 					///< 768X480 resolution for FPGA Validation
	OUTPUT_1280X720, 					///< 1280X720 resolution for FPGA Validation
	OUTPUT_RESOLUTION_MAX,
}MEMC_OUTPUT_RESOLUTION;

/*! MEMC Input signal frame rate enum. */
typedef enum
{
	INPUT_24HZ,							///< input 24Hz
	INPUT_25HZ,							///< input 25Hz
	INPUT_30HZ,							///< input 30Hz
	INPUT_48HZ,							///< input 48Hz
	INPUT_50HZ,							///< input 50Hz
	INPUT_60HZ,							///< input 60Hz
	INPUT_96HZ,							///< input 96Hz
	INPUT_100HZ,						///< input 100Hz
	INPUT_120HZ,						///< input 120Hz
	INPUT_FRAME_MAX,
}MEMC_INPUT_FRAMERATE;

/*! MEMC Output signal frame rate enum. */
typedef enum
{
	OUTPUT_48HZ,						///< output 48Hz
	OUTPUT_50HZ,						///< output 50Hz
	OUTPUT_60HZ,						///< output 60Hz
	OUTPUT_96HZ,						///< output 96Hz
	OUTPUT_100HZ,						///< output 100Hz
	OUTPUT_120HZ,						///< output 120Hz
	OUTPUT_200HZ,						///< output 200Hz
	OUTPUT_240HZ,						///< output 240Hz
	OUTPUT_FRAME_MAX,
	OUTPUT_FRAME_INVALID = 255,
}MEMC_OUTPUT_FRAMERATE;

/*! MEMC Input format enum. */
typedef enum
{
	INPUT_2D,							///< memc input is 2D
	INPUT_3D_SBS,						///< memc input is 3D side by side
	INPUT_3D_TB,						///< memc input is 3D top and bottom
	INPUT_3D_LR,						///< memc input is 3D frame sequential
	INPUT_3D_LBL,						///< memc input is 3D line by line
	INPUT_FORMAT_MAX,
}MEMC_INPUT_FORMAT;

/*! MEMC Output format enum. */
typedef enum
{
	OUTPUT_2D,							///< memc output is 2D
	OUTPUT_3D_SG,						///< memc output is shutter glass 3D
	OUTPUT_3D_PR,						///< memc output is Polarized 3D
	OUTPUT_3D_SG_LLRR,					///< memc output is shutter glass 3D LLRR
	OUTPUT_FORMAT_MAX,
}MEMC_OUTPUT_FORMAT;

/*! MEMC In/Out mode enum. */
typedef enum
{
	MEMC_RGB_IN_VIDEO_OUT,				///< memc RGB in and video output
	MEMC_RGB_IN_PC_OUT,					///< memc RGB in and pc output
	MEMC_YUV_IN_VIDEO_OUT, 				///< memc YUV444 in and video output
	MEMC_YUV_IN_PC_OUT,					///< memc YUV444 in and pc output
	MEMC_INOUT_MODE_MAX,
}MEMC_INOUT_MODE;

/*! MEMC OSD protect enum. */
typedef enum
{
	PROTECT_ON,							///< osd protect function on
	PROTECT_OFF,						///< osd protect function off
}MEMC_OSD_PROTECT;

/*! MEMC mode enum. */
typedef enum
{
	MEMC_SMOOTH,						///< Smooth mode
	MEMC_CLEAR,							///< Clear mode
	MEMC_NORMAL,						///< Normal mode
	MEMC_OFF,							///< Off mode
	MEMC_USER,							///< User mode, can manually set dejudder and deblur level
	MEMC_MODE_MAX,
}MEMC_MODE;

/*! MEMC RIM mode. */
typedef enum
{
	RIM_MODE_0,							///< memc rim mode 0
	RIM_MODE_1,							///< memc rim mode 1
}MEMC_RIM_MODE;

/*! module ID enum */
typedef enum
{
	MODULE_ID_APP,
	MODULE_ID_FRC,
}MODULE_ID;

/*! Define color space mode */
typedef enum
{
	CS_MODE_RGB,			///< RGB mode
	CS_MODE_YUV444,			///< YUV444 mode
	CS_MODE_YUV422			///< YUV222 MODE
}CS_MODE;

/*! MEMC demo mode enum. */
typedef enum
{
	DEMO_MODE_OFF,						///< Demo mode off
	DEMO_MODE_LEFT,						///< Demo mode left memc off, right memc on
	DEMO_MODE_RIGHT,					///< Demo mode left memc on, right memc off
}MEMC_DEMO_MODE;

/*! define Panel timing structure */
typedef struct
{
	MEMC_OUTPUT_FRAMERATE	enOutputFrameRate;	///< Output frame rate
	UINT32					u32Htotal;			///< H total
	UINT32					u32HtotalMax;		///< H total max
	UINT32					u32HtotalMin;		///< H total min
	UINT32					u32Hactive;			///< H active
	UINT32					u32HSWidth;			///< H sync width
	UINT32					u32HSBPorch;		///< H back porch
	UINT32					u32Vtotal;			///< V total
	UINT32					u32VtotalMax;		///< V total max
	UINT32					u32VtotalMin;		///< V total min
	UINT32					u32Vactive;			///< V active
	UINT32					u32VSWidth;			///< V sync width
	UINT32					u32VSBPorch;		///< V back porch
}PANEL_PARA_ST;

/*! SPACE Allocate struct. */
typedef struct
{
	UINT32 	 u32MC0Start;
	UINT32   u32MC1Start;
	UINT32   u32MEStart;
}DM_ADDR_ALLOCATE_ST;



/*! Command List. The command list is for customer SOC use through IIC or uart interface */
typedef enum
{
	// Common command
	CMD_MEMC_LibSetMute						= 0x000,		///< set output mute state
	CMD_MEMC_LibSetVflip					= 0x001,		///< set Vertical flip
	CMD_MEMC_LibSetMuteColor				= 0x002,		///< set mute color
	CMD_MEMC_LibSetOutputLRInverse			= 0x003,		///< set output LR inverse
	CMD_MEMC_LibSetSlaveModeEnable			= 0x004,		///< set slave mode

	CMD_MEMC_LibGetMute						= 0x080,		///< get output mute or unmute
	CMD_MEMC_LibGetVflip					= 0x081,		///< get Vertical flip status
	CMD_MEMC_LibGetVersionInfo				= 0x0F0,		///< get current library version info

	// Input/output settings
	CMD_MEMC_LibSetInOutMode 				= 0x100,		///< set MEMC In out mode
	CMD_MEMC_LibSetInputOutputFormat		= 0x101,		///< set input/output format
	CMD_MEMC_LibSetInputOutputResolution	= 0x102,		///< set input/output resolution
	CMD_MEMC_LibSetInputFrameRate			= 0x103,		///< set input frame rate
	CMD_MEMC_LibSetOutputFrameRate			= 0x104,		///< set output frame rate

	CMD_MEMC_LibGetOutputMode 				= 0x180,		///< get current output mode is Video or PC
	CMD_MEMC_LibGetInputOutputFormat		= 0x181,		///< get current input/output format
	CMD_MEMC_LibGetInputOutputResolution	= 0x182,		///< get current input/output resolution
	CMD_MEMC_LibGetInputFrameRate			= 0x183,		///< get current input frame rate
	CMD_MEMC_LibGetOutputFrameRate			= 0x184,		///< get current output frame rate

	//MEMC settings
	CMD_MEMC_LibSetMEMCMode 				= 0x200,		///<set MEMC mode
	CMD_MEMC_LibSetMEMCDeblurLevel			= 0x201,		///<set MEMC deblur level
	CMD_MEMC_LibSetMEMCDejudderLevel		= 0x202,		///<set MEMC dejudder level
	CMD_MEMC_LibSetRimWindow				= 0x203,		///<set MEMC RIM window
	CMD_MEMC_LibSetRimMode					= 0x204,		///<set MEMC RIM mode

	CMD_MEMC_LibGetMEMCMode					= 0x280,		///<get MEMC mode setting
	CMD_MEMC_LibGetMEMCDeblurLevel			= 0x281,		///<get MEMC deblur level
	CMD_MEMC_LibGetMEMCDejudderLevel		= 0x282,		///<get MEMC dejudder level
	CMD_MEMC_LibGetRimWindow				= 0x283,		///<get MEMC RIM window
	CMD_MEMC_LibGetRimMode					= 0x284,		///<get MEMC RIM mode

	//OSD settings
	CMD_MEMC_LibSetOSDInputOutputFormat 	= 0x800, 		///<set OSD input/output format
	CMD_MEMC_LibSetOSDSize 					= 0x801, 		///<set OSD size
	CMD_MEMC_LibSetOSDPosition 				= 0x802, 		///<set OSD position
	CMD_MEMC_LibSetOSDOnOff 				= 0x803, 		///<set OSD on/off
	CMD_MEMC_LibSetOSDCsMode				= 0x804,		///<set OSD color space

	CMD_MEMC_LibGetOSDInputOutputFormat 	= 0x880, 		///<get OSD input/output format
	CMD_MEMC_LibGetOSDSize 					= 0x881, 		///<get OSD size
	CMD_MEMC_LibGetOSDPosition 				= 0x882, 		///<get OSD position
	CMD_MEMC_LibGetOSDOnOff 				= 0x883, 		///<get OSD on/off
	CMD_MEMC_LibGetOSDCsMode				= 0x884,		///<get OSD color space currently used

	// Panel settings
	CMD_MEMC_LibSetPanelParameters			= 0xA00,		///<set panel parameter
	CMD_MEMC_LibApplyPanelParameters		= 0xA01,		///<apply selected panel parameter by frame rate

	CMD_MEMC_LibGetPanelParameters			= 0xA80,		///<get panel parameter by frame rate
	CMD_MEMC_LibGetCurrentPanelParameters	= 0xA81,		///<get current working panel parameter

	// Misc
	CMD_MEMC_LibSetDebugLevel				= 0xE00,		///<set FRC library debug level
	CMD_MEMC_LibSetDemoWindowEnable			= 0xE10,		///<set demo window on/off
	CMD_MEMC_LibSetDemoWindowMode			= 0xE11,		///<set demo window mode
	CMD_MEMC_LibSetDemoWindowSettings		= 0xE12,		///<set demo window size and position

	CMD_MEMC_LibGetErrorCode				= 0xE80,		///<Readback FRC module error code
	CMD_MEMC_LibGetDebugLevel				= 0xE81,		///<Readback FRC module debug level
	CMD_MEMC_LibGetDemoWindowEnable 		= 0xE90,		///<get demo window on/off
	CMD_MEMC_LibGetDemoWindowMode			= 0xE91,		///<get demo window mode
	CMD_MEMC_LibGetDemoWindowSettings		= 0xE92,		///<get demo window size and position
}CMD_LIST;

/**
 * @brief This function must be invoked when boot up.(boot sequence: MEMC_LibPanel_Init -> MEMC_LibSetPanelParameters -> MEMC_LibInit)
 * @retval VOID
*/
DLL_API VOID MEMC_LibPanel_Init(VOID);

/**
 * @brief This function must be invoked when boot up.(boot sequence: MEMC_LibPanel_Init -> MEMC_LibSetPanelParameters -> MEMC_LibInit)
 * @retval VOID
*/
DLL_API BOOL MEMC_LibInit(VOID);

/**
 * @brief This function must be invoked before MEMC_LibInit();
 * @retval VOID
*/

DLL_API VOID MEMC_LibDMAllocate(UINT32 uiMC0Start, UINT32 uiMC1Start, UINT32 uiMEStart);

/**
 * @brief This function enable/disable memc dm engine
 * @retval VOID
*/
DLL_API VOID MEMC_LibEnableMEMCEngine(BOOL bEnable);
/**
 * @brief This function defines operation during input vsync procedure.
 *
*/
DLL_API VOID MEMC_LibInputVSInterrupt(VOID);

/**
 * @brief This function defines input vsync interrupt enable or not.
 * @param [in] bEnable	   enable or disable the input vsync interrupt
*/
DLL_API VOID MEMC_LibInputVSInterruptEnable(BOOL bEnable);

/**
 * @brief This function defines operation during output VS procedure.
 *
*/
DLL_API VOID MEMC_LibOutputVSInterrupt(VOID);

/**
 * @brief This function defines output vsync interrupt enable or not.
 * @param [in] bEnable	  enable or disable the out hync interrupt
*/
DLL_API VOID MEMC_LibOutputVSInterruptEnable(BOOL bEnable);

/**
 * @brief This function set MEMC in/out mode. (please add almost 25ms mute to avoid garbage)
 * @param [in] emom 		Specify in/out MEMC mode.
 * @param [in] bForce       Whether force to set mode.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
DLL_API BOOL MEMC_LibSetInOutMode(MEMC_INOUT_MODE emom,BOOL bForce);

/**
 * @brief This function returns current MEMC in/out mode.
 * @retval MEMC_INOUT_MODE		enum type value
*/
DLL_API MEMC_INOUT_MODE MEMC_LibGetInOutMode(VOID);

/**
 * @brief This function set input/output use case. (please add almost 25ms mute to avoid garbage)
 * @param [in] emir 		Specify input resolution.
 * @param [in] emor 		Specify output resolution.
 * @param [in] emif 		Specify input MEMC format.
 * @param [in] emof 		Specify output MEMC format.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
DLL_API BOOL MEMC_LibSetInOutUseCase(MEMC_INPUT_RESOLUTION emir, MEMC_OUTPUT_RESOLUTION emor, MEMC_INPUT_FORMAT emif, MEMC_OUTPUT_FORMAT emof);

/**
 * @brief This function get input/output use case. (please add almost 25ms mute to avoid garbage)
 * @param [out] 	pemir 	return current input signal resolution.
 * @param [out] 	pemor 	return current output signal resolution.
 * @param [out] 	pemif 	return current input format mode.
 * @param [out] 	pemof	return current output format mode.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
DLL_API BOOL MEMC_LibGetInOutUseCase(MEMC_INPUT_RESOLUTION *pemir, MEMC_OUTPUT_RESOLUTION *pemor, MEMC_INPUT_FORMAT *pemif, MEMC_OUTPUT_FORMAT *pemof);

/**
 * @brief This function set input/output frame rate.
 * @param [in] emifr 		Specify input frame rate.
 * @param [in] emofr 		Specify output frame rate.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
DLL_API BOOL MEMC_LibSetInOutFrameRate(MEMC_INPUT_FRAMERATE emifr, MEMC_OUTPUT_FRAMERATE emofr);
DLL_API BOOL MEMC_LibSetInputFrameRate(MEMC_INPUT_FRAMERATE emifr);
DLL_API BOOL MEMC_LibSetOutputFrameRate(MEMC_OUTPUT_FRAMERATE emofr);
/**
 * @brief This function get input/output frame rate.
 * @param [out] 	pemifr 	return current input frame rate.
 * @param [out] 	pemofr 	return current output frame rate.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
DLL_API BOOL MEMC_LibGetInOutFrameRate(MEMC_INPUT_FRAMERATE *pemifr, MEMC_OUTPUT_FRAMERATE *pemofr);

/**
 * @brief This function set vertical flip.
 * @param [in] bVflip 		enable or disable vflip.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
DLL_API BOOL MEMC_LibSetVflip(BOOL bVflip);

/**
 * @brief This function get Vflip status.
 * @retval TRUE			vflip is enable
 * @retval FALSE		vflip is disable
*/
DLL_API BOOL MEMC_LibGetVflip(VOID);

/**
 * @brief This function set demo window Enable
 * @param [in] ubyWinID		demo window ID(range 0~7)
 * @param [in] bEnable		enable or disable the demo window
 * @retval TRUE				success
 * @retval FALSE			fail
*/
DLL_API BOOL MEMC_LibSetDemoWindowEnable(UBYTE ubyWinID, BOOL bEnable);

/**
 * @brief This function get demo window Enable
 * @param [in] ubyWinID		demo window ID(range 0~7)
 * @retval TRUE				The demo window is enabled
 * @retval FALSE			The demo window is disabled
*/
DLL_API BOOL MEMC_LibGetDemoWindowEnable(UBYTE ubyWinID);

/**
 * @brief This function set demo window mode
 * @param [in] bMode		demo window mode
 * 						 	0: inside MEMC OFF;
 * 						 	1: outside MEMC OFF
*/
DLL_API VOID MEMC_LibSetDemoWindowMode(BOOL bMode);

/**
 * @brief This function get demo window mode
 * @retval TRUE				inside MEMC OFF
 * @retval FALSE			outside MEMC OFF
*/
DLL_API BOOL MEMC_LibGetDemoWindowMode(VOID);

/**
 * @brief This function set demo window settings
 * @param [in] ubyWinID		Range 0~7
 * @param [in] u32Left		position left
 * @param [in] u32Right		position right
 * @param [in] u32Top 		position top
 * @param [in] u32Bottom 	position bottom
 * @retval TRUE				success
 * @retval FALSE			fail
*/
DLL_API BOOL MEMC_LibSetDemoWindowSettings(UBYTE ubyWinID, UINT32 u32Left, UINT32 u32Right, UINT32 u32Top, UINT32 u32Bottom);

/**
 * @brief This function get demo window settings
 * @param [in] ubyWinID			range 0~7
 * @param [out] *pu32Left		position left
 * @param [out] *pu32Right		position right
 * @param [out] *pu32Top 		position top
 * @param [out] *pu32Bottom 	position bottom
*/
DLL_API VOID MEMC_LibGetDemoWindowSettings(UBYTE ubyWinID, UINT32 *pu32Left, UINT32 *pu32Right, UINT32 *pu32Top, UINT32 *pu32Bottom);

/**
 * @brief This function set MEMC deblur level, when MEMC mode is user mode.
 * @param [in] uiLevel 		Specify memc deblur level (0~16).
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
DLL_API BOOL MEMC_LibSetMEMCDeblurLevel(UINT32 uiLevel);

/**
 * @brief This function get MEMC deblur level.
 * @return Return 		MEMC deblur level currently set.
*/
DLL_API UINT32 MEMC_LibGetMEMCDeblurLevel(VOID);

/**
 * @brief This function set MEMC dejudder level, when MEMC mode is user mode.
 * @param [in] uiLevel		Specify memc dejudder level (0~16).
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
DLL_API BOOL MEMC_LibSetMEMCDejudderLevel(UINT32 uiLevel);

/**
 * @brief This function get MEMC dejudder level.
 * @return Return 		MEMC dejudder level currently set.
*/
DLL_API UINT32 MEMC_LibGetMEMCDejudderLevel(VOID);

/**
 * @brief This function set MEMC fallback level, when MEMC mode is user mode.
 * @param [in] uiLevel		Specify memc fallback level (0~255).
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
DLL_API BOOL MEMC_LibSetMEMCFallbackLevel(UINT32 uiLevel);

/**
 * @brief This function get MEMC fallback level.
 * @return Return 		MEMC fallback level currently set.
*/
DLL_API UINT32 MEMC_LibGetMEMCFallbackLevel(VOID);
/**
 * @brief This function reset MEMC mode.
 * @for STR init
*/
DLL_API VOID MEMC_LibResetMEMCMode(VOID);

/**
 * @brief This function set MEMC mode.
 * @param [in] emm 		Specify MEMC mode.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
DLL_API BOOL MEMC_LibSetMEMCMode(MEMC_MODE emm);

/**
 * @brief This function get MEMC mode.
 * @retval MEMC_MODE enum type currently set.
*/
DLL_API MEMC_MODE MEMC_LibGetMEMCMode(VOID);

/**
 * @brief This function set Cinema mode.
 * @param [in] emm 		Specify CinemaMode(0:disable;1:enable).
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
DLL_API BOOL MEMC_LibSetCinemaMode(UBYTE bEnable);

/**
 * @brief This function get CinemaMode setting.
 * @retval TRUE 			Enable
 * @retval FALSE			Disable
*/
DLL_API UBYTE MEMC_LibGetCinemaMode(VOID);

/**
 * @brief This function set MEMC frame repeat mode.
 * @param [in] bEnable 		true for enable, false for disalbe.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
DLL_API BOOL MEMC_LibSetMEMCFrameRepeatEnable(BOOL bEnable, BOOL bForce);


/**
 * @brief This function set MEMC frame repeat mode.
 * @param [in] bEnable 		true for enable, false for disalbe.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
DLL_API BOOL MEMC_LibSetMEMC_PCModeEnable(BOOL bEnable);

/**
 * @brief This function set MEMC frame repeat mode.
 * @param [in] bEnable 		true for enable, false for disalbe.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
DLL_API BOOL MEMC_LibSetMEMCLowDelayModeEnable(BOOL bEnable);

/**
 * @brief This function get MEMC frame repeat mode.
 * @retval TRUE 			Enable
 * @retval FALSE			Disable
*/
DLL_API BOOL MEMC_LibGetMEMCFrameRepeatEnable(VOID);

/**
 * @brief This function get MEMC frame repeat mode.
 * @retval TRUE 			Enable
 * @retval FALSE			Disable
*/
DLL_API BOOL MEMC_LibGetMEMC_PCModeEnable(VOID);

/**
 * @brief This function get MEMC frame repeat mode.
 * @retval TRUE 			Enable
 * @retval FALSE			Disable
*/
DLL_API BOOL MEMC_LibGetMEMCLowDelayModeEnable(VOID);

/**
 * @brief This function get MEMC frame repeat mode.
 * @retval TRUE 			Enable
 * @retval FALSE			Disable
*/
DLL_API BOOL MEMC_LibGetMEMCLowDelayModeEnable(VOID);
DLL_API VOID MEMC_LibGetVersionInfo(SCHAR *pBuf, UINT32 iLen, MODULE_ID enModID);

/**
 * @brief This function set MEMC output mute or unmute.
 *			This function is mostly used before/after signal change to avoid mess screen.
 * @param [in] bMute		Input mute state want to set
 * @retval VOID
*/
DLL_API VOID MEMC_LibSetMute(BOOL bMute);

/**
 * @brief This function get MEMC output mute state.
 * @retval TRUE 		indicates currently is mute state
 * @retval FALSE		indicates currently is unmute state
*/
DLL_API BOOL MEMC_LibGetMute(VOID);

/**
 * @brief This function set MEMC output mute color
 * @param [in] bREnable		color r enable or not
 * @param [in] bGEnable		color g enable or not
 * @param [in] bBEnable		color b enable or not
*/
DLL_API VOID MEMC_LibSetMuteColor(BOOL bREnable, BOOL bGEnable, BOOL bBEnable);

/**
 * @brief This function set MEMC output LR inverse.
 * @param [in] bEnable		output LR inverse or not
 * @retval VOID
*/
DLL_API VOID MEMC_LibSetOutputLRInverse(BOOL bEnable);

/**
 * @brief This function set panel parameters.
 * @param [in] stPanelPara 			structure for panel parameters
 * @retval TRUE 					indicates success
 * @retval FALSE					indicates fail
*/
DLL_API BOOL MEMC_LibSetPanelParameters(PANEL_PARA_ST *pstPanelPara);

/**
 * @brief This function get panel parameters.
 * @param [in] enOutputFrameRate		which panel parameters will you want to get
 * @param [out] pstPanelPara 			structure for panel parameters
 * @retval TRUE 						indicates success
 * @retval FALSE						indicates fail
*/
DLL_API BOOL MEMC_LibGetPanelParameters(PANEL_PARA_ST *pstPanelPara, MEMC_OUTPUT_FRAMERATE enOutputFrameRate);

/**
 * @brief This function get current panel parameters.
 * @param [out] pstPanelPara 		structure for panel parameters
 * @retval TRUE 					indicates success
 * @retval FALSE					indicates fail
*/
DLL_API BOOL MEMC_LibGetCurrentPanelParameters(PANEL_PARA_ST *pstPanelPara);

/**
 * @brief This function apply panel parameters.
 * @param [in] enOutputFrameRate	which panel parameters will you want to apply
 * @retval TRUE 					indicates success
 * @retval FALSE					indicates fail
*/
DLL_API BOOL MEMC_LibApplyPanelParameters(MEMC_OUTPUT_FRAMERATE enOutputFrameRate);

/**
 * @brief This function set MEMC debug level.
 * @param [in] iLevel Specify library debug level. (range: 1~3)
 *			1: show all print messages.
 *			2: show warning and error messages.
 *			3: show error messages.
 * @retval TRUE 						indicates success
 * @retval FALSE						indicates fail
*/
DLL_API BOOL MEMC_LibSetDebugLevel(UINT32 u32Level);

/**
 * @brief This function get MEMC current debug level.
 * @return Return 	library current debug level.
*/
DLL_API UINT32 MEMC_LibGetDebugLevel(VOID);

/**
 * @brief This function Init Kosd
 * @param [in] None
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
DLL_API BOOL MEMC_LibOSDInit(VOID);
/**
 * @brief This function set OSD input/output use case
 * @param [in] emiRes Specify input Resolution.
 * @param [in] emoRes Specify output Resolution
 * @param [in] emif Specify input format.
 * @param [in] emof Specify output format
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
DLL_API BOOL MEMC_LibSetOSDInOutUseCase(
				MEMC_INPUT_RESOLUTION emiRes,
				MEMC_OUTPUT_RESOLUTION emoRes,
				MEMC_INPUT_FORMAT emif,
				MEMC_OUTPUT_FORMAT emof);
/**
 * @brief This function get input/output format.
 * @param [out] pemiRes return current input resolution
 * @param [out] pemoRes return current output resolution
 * @param [out] pemif return current input format mode.
 * @param [out] pemof return current output format mode.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
DLL_API BOOL MEMC_LibGetOSDInOutUseCase(
			MEMC_INPUT_RESOLUTION *pemiRes,
			MEMC_OUTPUT_RESOLUTION *pemoRes,
			MEMC_INPUT_FORMAT *pemif,
			MEMC_OUTPUT_FORMAT *pemof);

/**
 * @brief This function Set OSD Color Space Mode
 * @param [in] enMode 	Specify color space mode for osd
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
DLL_API BOOL MEMC_LibSetOSDCsMode(CS_MODE enMode);

/**
 * @brief This function Get OSD Color Space Mode
 * @return OSD Color space mode
*/
DLL_API CS_MODE MEMC_LibGetOSDCsMode(VOID);

/**
 * @brief This function Set OSD Vflip Status
 * @param [in] 			bVflip
 * @retval TRUE			success
 * @retval FALSE		failed
*/
DLL_API BOOL MEMC_LibSetOSDVFlip(BOOL bVflip);

/**
 * @brief This function Get OSD Vflip Status
 * @retval TRUE			OSD is Vflip
 * @retval FALSE		OSD is not Vflip
*/
DLL_API BOOL MEMC_LibGetOSDVFlip(VOID);

/**
 * @brief This function set input data mapping
 * @param [in] u32Data_Mapping 	data mapping index(range: 0~5)
 *			0: 012 -> 012
 *			1: 012 -> 021
 *			2: 012 -> 102
 *			3: 012 -> 120
 *			4: 012 -> 201
 *			5: 012 -> 210
 * @retval VOID
*/
DLL_API VOID MEMC_LibSetInputDataMapping(UINT32 u32Data_Mapping);

/**
 * @brief This function get input data mapping
 * @param [in] VOID
 * @retval u32Data_Mapping 		data mapping index(range: 0~5)
*/
DLL_API UINT32 MEMC_LibGetInputDataMapping(VOID);

/**
 * @brief This function set nr data mapping
 * @param [in] u32Data_Mapping 	data mapping index(range: 0~5)
 *			0: 012 -> 012
 *			1: 012 -> 021
 *			2: 012 -> 102
 *			3: 012 -> 120
 *			4: 012 -> 201
 *			5: 012 -> 210
 * @retval VOID
*/
DLL_API VOID MEMC_LibSetNRDataMapping(UINT32 u32Data_Mapping);

/**
 * @brief This function get nr data mapping
 * @param [in] VOID
 * @retval data mapping 		data mapping index(range: 0~5)
*/
DLL_API UINT32 MEMC_LibGetNRDataMapping(VOID);

/**
 * @brief This function set output data mapping
 * @param [in] u32Data_Mapping 	data mapping index(range: 0~5)
 *			0: 012 -> 012
 *			1: 012 -> 021
 *			2: 012 -> 102
 *			3: 012 -> 120
 *			4: 012 -> 201
 *			5: 012 -> 210
 * @retval VOID
*/
DLL_API VOID MEMC_LibSetOutputDataMapping(UINT32 u32Data_Mapping);

/**
 * @brief This function get output data mapping
 * @param [in] VOID
 * @retval data mapping 		data mapping index(range: 0~5)
*/
DLL_API UINT32 MEMC_LibGetOutputDataMapping(VOID);

/**
 * @brief This function set black insert line mode enable
 * @param [in] bEnable		enable or disable black insert line mode
 * @retval VOID
*/
DLL_API VOID MEMC_LibSetBlackInsertLineModeEnable(BOOL bEnable);

/**
 * @brief This function set black insert line mode pattern number
 * @param [in] u32PatternNum  	black insert line mode  pattern number(range: 0~15 stand for 1~16)
 * @retval VOID
*/
DLL_API VOID MEMC_LibSetBlackInsertLineModePatternNum(UINT32 u32PatternNum);

/**
 * @brief This function set black insert line mode L pattern
 * @param [in] u32Pattern		black insert line mode L pattern
 *								(if pattern number = 2, range: 0x0~0x3)
 *                              (if pattern number = 4, range: 0x0~0xF)
 *                              (if pattern number = 8, range: 0x00~0xFF)
 *                              (if pattern number = 16, range: 0x00~0xFFFF)
 * @retval VOID
*/
DLL_API VOID MEMC_LibSetBlackInsertLineModeLPattern(UINT32 u32Pattern);

/**
 * @brief This function set black insert line mode R pattern
 * @param [in] u32Pattern 		black insert line mode R pattern
 * 								(if pattern number = 2, range: 0x0~0x3)
 *                              (if pattern number = 4, range: 0x0~0xF)
 *                              (if pattern number = 8, range: 0x00~0xFF)
 *                              (if pattern number = 16, range: 0x00~0xFFFF)
 * @retval VOID
*/
DLL_API VOID MEMC_LibSetBlackInsertLineModeRPattern(UINT32 u32Pattern);

/**
 * @brief This function set black insert frame mode enable
 * @param [in] bEnable			Enable or disable black insert frame mode
 * @retval VOID
*/
DLL_API VOID MEMC_LibSetBlackInsertFrameModeEnable(BOOL bEnable);

/**
 * @brief This function set MEMC demo mode
 * @param [in] emMode			Specify MEMC demo mode
 * @retval TRUE 				indicates success
 * @retval FALSE				indicates fail
*/
DLL_API BOOL MEMC_LibSetMEMCDemoMode(MEMC_DEMO_MODE emMode);

/**
 * @brief This function get MEMC demo mode
 * @retval MEMC_DEMO_MODE enum type currently set.
*/
DLL_API MEMC_DEMO_MODE MEMC_LibGetMEMCDemoMode(VOID);

DLL_API VOID MEMC_LibForcePhaseTableInit(VOID);
// for debug purpose
#ifdef WIN32
DLL_API BOOL ReadRegSetCallback(ReadRegCallback cb);

DLL_API BOOL WriteRegSetCallback(WriteRegCallback cb);

DLL_API int DebugReadPrintf(char *buf);
#endif


/**
 * @brief This function set RTK hdf
 * @retval VOID
*/
VOID MEMC_SetRTKhdf(VOID);
/**
 * @brief This function set kmv engine enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
void MEMC_LibSetKMVEngineEnable(unsigned char enable);

/**
 * @brief This function get enable status of memc in/out isr
 * @retval BOOL
*/
BOOL MEMC_GetInOutISREnable(VOID);

/**
 * @brief This function set power saving mode on
 * @retval 1		power save on fail
 * @retval 0		power save on success
*/
BOOL MEMC_LibPowerSaveOn(VOID);
/**
 * @brief This function set power saving mode off
 * @retval 1		power save off fail
 * @retval 0		power save off success
*/
BOOL MEMC_LibPowerSaveOff(VOID);
#endif

