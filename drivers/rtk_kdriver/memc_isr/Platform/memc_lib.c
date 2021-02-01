/**
 * @file memc_lib.c
 * @brief This file implements all memc exported api.
 * @date August.24.2014
 * @version V0.0.1
 * @author Lixiangjun
 * @par MEMC Library V0.0.1 - Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#ifdef WIN32
#define DLL_IMPLEMENT
#endif

#if 0//#ifdef RTK_MEMC
#include <string.h>

#include <stdio.h>
#include <stdlib.h>

#include <../../../common/rtio.h>
#endif

#include "memc_isr/Common/kw_common.h"
#include "memc_isr/Common/kw_uart.h"
#include "memc_isr/include/memc_lib.h"
#include "memc_isr/Common/kw_debug.h"

#include "memc_isr/MID/mid_memc.h"
#include "memc_isr/MID/mid_mode.h"
#include "memc_isr/MID/mid_dm.h"
#include "memc_isr/MID/mid_sys.h"
#include "memc_isr/MID/mid_crtc.h"
#include "memc_isr/MID/mid_misc.h"
#include "memc_isr/MID/mid_ambl.h"
#include "memc_isr/HAL/hal_hdf.h"
#include "memc_isr/HAL/hal_mc.h"

#include "memc_isr/include/PQLAPI.h"
#include "memc_isr/Platform/version.h"

#include "memc_isr/PQL/PQLPlatformDefs.h"
#include "memc_isr/PQL/PQLContext.h"
#include "memc_isr/Driver/regio.h"

#include "rtk_vgip_isr.h"
#include "io.h"

#ifndef CONFIG_RTK_KDEV_VGIP_INTERRUPT
#include <scalercommon/vipCommon.h>
#include <scalercommon/scalerCommon.h>
#include <scalercommon/scalerDrvCommon.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#endif

#include <scalercommon/vipCommon.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>

/* ! add for VS debug purpose */
#ifdef WIN32
#include "regio.h"
#include <stdlib.h>
#include <string.h>
#endif

//#include "drv_i2c.h"

/*! Default debug level of this module */
#define DEFAULT_DBG_LEVEL	DBG_WARNING


//temp for debug
#define REAL_CHIP

/*! define mode data structure */
typedef struct
{
	MEMC_INOUT_MODE			enInOutMode;			///< APP inout mode enum
	MEMC_INPUT_FORMAT		enInputFormat;			///< APP input format
	MEMC_OUTPUT_FORMAT		enOutputFormat;			///< APP output format
	MEMC_INPUT_RESOLUTION	enInputRes;				///< APP input resolution
	MEMC_OUTPUT_RESOLUTION	enOutputRes;			///< APP output resolution
	MEMC_INPUT_FRAMERATE	enInputFrameRate;		///< APP input frame rate
	MEMC_OUTPUT_FRAMERATE	enOutputFrameRate;		///< APP output frame rate
	BOOL					bVflip;					///< APP vflip
}MODE_DATA_ST;

/*! define memc data structure */
typedef struct
{
	MEMC_MODE				enMemcMode;				///< APP memc mode
	BOOL					bFrameRepeat;			///< APP frame repeat mode
	BOOL					bFrameRepeat_QRPC;			///< APP frame repeat mode
	BOOL					bPCMode;			///< APP PC mode
	BOOL					bPCMode_QRPC;			///< APP PC mode
	BOOL					bLowDelay;			///< APP low delay mode
	BOOL					bLowDelay_QRPC;			///< APP low delay mode
	UINT32					uiDeblurLevel;			///< APP memc deblur level
	UINT32					uiDejudderLevel;		///< APP memc dejudder level
	UINT32					uiFallbackLevel;		///< APP memc fallback level
	UINT32					uiTop;					///< APP rim window top
	UINT32					uiBottom;				///< APP rim window bottom
	UINT32					uiLeft;					///< APP rim window left
	UINT32					uiRight;				///< APP rim window right
}MEMC_DATA_ST;

/*! define sys data structure */
typedef struct
{
	BOOL					bMute;					///< APP mute state
	MEMC_DEMO_MODE			enDemoMode;				///< APP demo mode
}SYS_DATA_ST;

/*! define app data structure */
typedef struct
{
	MODE_DATA_ST			stModeData;				///< APP mode data
	MEMC_DATA_ST			stMEMCData;				///< APP memc data
	SYS_DATA_ST				stSysData;				///< APP system data
	UINT32					uiVer;					///< structure version
	SINT32					iMEMCDbgLevel;			///< APP Debug level variable define
	SINT32					iErrCode;				///< APP error code
	BOOL					bSyncCMD;				///< CMD work sync mode, TRUE sync, FALSE async
	BOOL 					bCtrcSlaveMode;			///< APP CRTC Slave Mode
	UBYTE					bCinemaMode;			///< Cinema Mode, related to stMEMCData.enMemcMode
	UBYTE					bCinemaModeUpdateFR;	///< Cinema Mode, final update frame rate
}MEMC_APP_DATA_ST;

typedef struct
{
	BOOL 	bSRC_VO;	///< ScalerVIP status
	BOOL 	bHDR_Chg;	///< ScalerVIP status
	UINT16	mBrightness;	///< ScalerVIP status
	UINT16  mContrast;		///< ScalerVIP status
	SINT16 	mSpeed;		///< ScalerVIP status
	BOOL	bZoomAction;	///< ScalerVIP status
	BOOL      bShiftAction;	///< ScalerVIP status
	UINT16	source_type;
	UBYTE	mVOSeek;	///< VO Status
	UINT16	MEMCMode;	///< MEMC mode
	UBYTE     mDarkLevel; ///< Hist dark level
	BOOL	Hist_SC_flg;
	UBYTE	mSoccer_holdfrm;
	BOOL	PictureMode_Chg;
	BOOL	bVIP_Still;	// from RTNR MAD Y counter info
	UBYTE	m_MiraCast;	///< m_MiraCast Status
}MEMC_SCALER_VIP_INFO;

/*! Global variable section */
static MEMC_APP_DATA_ST		gstAppData = {
											{
												MEMC_INOUT_MODE_MAX,		///< APP inout mode enum
												INPUT_FORMAT_MAX, 			///< APP input format
												OUTPUT_FORMAT_MAX, 			///< APP output format
												INPUT_RESOLUTION_MAX,		///< APP input resolution
												OUTPUT_RESOLUTION_MAX, 		///< APP output resolution
												INPUT_FRAME_MAX, 			///< APP input frame rate
												OUTPUT_FRAME_MAX, 			///< APP output frame rate
												0, 							///< APP vflip
											},	///< Mode data
											{
												MEMC_MODE_MAX, 				///< APP memc mode
												FALSE,						///< APP frame repeat mode
												FALSE,						///< APP frame repeat mode Q
												FALSE,						///< APP PC mode
												FALSE,						///< APP PC mode Q
												FALSE,						///< APP low delay mode
												FALSE,						///< APP low delay mode Q
												0,						///< APP memc deblur level
												0,						///< APP memc dejudder level
												0,						///< APP memc fallback level
												0x10, 						///< APP rim window top
												0x2150, 					///< APP rim window bottom
												0, 							///< APP rim window left
												3840,						///< APP rim window right
											},	///< MEMC data
											{
												FALSE,						///< APP mute state
												DEMO_MODE_OFF,				///< APP demo mode
											},	///< Sys data
											0x01000000, 					///< structure version
											DEFAULT_DBG_LEVEL, 				///< APP Debug level variable define
											0, 								///< APP error code
											FALSE,							///< CMD work sync mode, TRUE sync, FALSE async
											TRUE,							///< APP CRTC Slave Mode
											FALSE							///< Cinema Mode, related to stMEMCData.enMemcMode
										};				///< app data

static MEMC_SCALER_VIP_INFO	gstScalerVIPInfo = {0};

static PANEL_DATA_ST	gstPanelData;					///< Panel data
static ME_DM_ADDRESS_ST gstMEDMAddr;
static MV_DM_ADDRESS_ST gstMVDMAddr;
static MC_DM_ADDRESS_ST gstMCDMAddr;

static DM_ADDR_ALLOCATE_ST gstDMAddrAllocate = {0};

static UINT32 u32OutIntCount = 0;
static UBYTE  InputVSXral_FrameRepeatMode = 0;
static UBYTE  InputVSXral_PCMode = 0;

static unsigned char g_memc_ivsync_cnt = 0;

static UBYTE Ready_For_SetMCBlendMode = 1;

extern void Scaler_MEMC_SetInitFlag(unsigned char val);
extern unsigned char Scaler_MEMC_GetInitFlag(void);

#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
extern MEMC_SCALER_VIP_INFO scalerVIP_Get_Info_fromScaler(void);
#endif
#ifndef CONFIG_RTK_KDEV_VGIP_INTERRUPT
extern int VO_Get_ChannelSpeed(void);
extern unsigned char DIRECT_VO_GetFirstFrameAfterSeek(void);
#endif

VOID MEMC_LibGetScalerVIPInfo(VOID);
VOID MEMC_LibInputVSXral(VOID);

// for debug purpose to get printf info
#ifdef WIN32
static int iBufSize = 1024;
static char *pRead = NULL;
static char *pWrite = NULL;

static char *pgPrintBuf = NULL;

static VOID InitPrintLoopBuffer()
{
	pgPrintBuf = (char *)malloc(iBufSize);
	pRead = pgPrintBuf;
	pWrite = pgPrintBuf;
}

static VOID PrintfBufFill(char ch)
{
	if (pWrite >= (pgPrintBuf + iBufSize))
	{
		pWrite = pgPrintBuf;
	}

	*pWrite = ch;
	pWrite++;
}

VOID InitPrintf(VOID)
{
	InitPrintLoopBuffer();
	kw_SetPrintfCallback(PrintfBufFill);
}

int DebugReadPrintf(char *buf)
{
	int iLen = 0;
	char *pEnd = NULL;

	if (pRead < pWrite)
	{
		pEnd = pWrite;
	}
	else if (pRead > pWrite)
	{
		pEnd = pgPrintBuf + iBufSize;
	}
	else
	{
		// read is at same place as write, no more data
		// just return
		return 0;
	}

	iLen = pEnd - pRead;
	if (iLen == 0)
		return iLen;

	strncpy(buf, pRead, iLen);
	pRead += iLen;
	if (pRead >= pgPrintBuf + iBufSize)
		pRead = pgPrintBuf;

	return iLen;
}
#endif

#ifndef REAL_CHIP	//FPGA
#define ME_START_ADDR 0
#else
#define ME_START_ADDR 0x30000000
#endif

#define MV_START_ADDR gstMEDMAddr.stBuf_14_1.u32StartAddress + 0x5000
//#define MC_START_ADDR gstMVDMAddr.stBuf_12_7.u32StartAddress + gstMVDMAddr.u32Buf_12_LROffset * 2

#ifndef REAL_CHIP	//FPGA
#define PC_MODE_KMC_LR_OFFSET_ADDR 0x010E0000
#define PC_MODE_KMC_LINE_OFFSET_ADDR 0x4000

#define VD_MODE_KMC_LR_OFFSET_ADDR 0x00CA8000
#define VD_MODE_KMC_LINE_OFFSET_ADDR 0x3000
#else
#define PC_MODE_KMC_LR_OFFSET_ADDR 0x00438000
#define PC_MODE_KMC_LINE_OFFSET_ADDR 0x2000

#define VD_MODE_KMC_LR_OFFSET_ADDR 0x002C4C00
#define VD_MODE_KMC_LINE_OFFSET_ADDR 0x1500
#endif

/*! MEMC Library exported api list */
/**
 * @brief This function must be invoked when boot up.(boot sequence: MEMC_LibDMAllocate -> MEMC_LibInit)
*/
VOID MEMC_LibDMAllocate(UINT32 uiMC0Start, UINT32 uiMC1Start, UINT32 uiMEStart)
{
	gstDMAddrAllocate.u32MC0Start = uiMC0Start;
	gstDMAddrAllocate.u32MC1Start = uiMC1Start;
	gstDMAddrAllocate.u32MEStart = uiMEStart;
}


static VOID _MEMC_LibSetMEDMAddress(UINT32 u32MEStartAddr)
{
	gstMEDMAddr.u32Buf_00_LineOffset = 0x3C0;
	gstMEDMAddr.u32Buf_00_LROffset = 0x80000;
	gstMEDMAddr.stBuf_00_0.u32StartAddress = u32MEStartAddr;
	gstMEDMAddr.stBuf_00_1.u32StartAddress = gstMEDMAddr.stBuf_00_0.u32StartAddress + gstMEDMAddr.u32Buf_00_LROffset * 2;
	gstMEDMAddr.stBuf_00_2.u32StartAddress = gstMEDMAddr.stBuf_00_1.u32StartAddress + gstMEDMAddr.u32Buf_00_LROffset * 2;
	gstMEDMAddr.stBuf_00_3.u32StartAddress = gstMEDMAddr.stBuf_00_2.u32StartAddress + gstMEDMAddr.u32Buf_00_LROffset * 2;
	gstMEDMAddr.stBuf_00_4.u32StartAddress = gstMEDMAddr.stBuf_00_3.u32StartAddress + gstMEDMAddr.u32Buf_00_LROffset * 2;
	gstMEDMAddr.stBuf_00_5.u32StartAddress = gstMEDMAddr.stBuf_00_4.u32StartAddress + gstMEDMAddr.u32Buf_00_LROffset * 2;

	gstMEDMAddr.u32Buf_08_LineOffset = 0x3C0;
	gstMEDMAddr.stBuf_08_0.u32StartAddress = gstMEDMAddr.stBuf_00_5.u32StartAddress + gstMEDMAddr.u32Buf_00_LROffset * 2;
	gstMEDMAddr.stBuf_08_1.u32StartAddress = gstMEDMAddr.stBuf_08_0.u32StartAddress;

	gstMEDMAddr.u32Buf_10_LineOffset = 0x1E0;
	gstMEDMAddr.stBuf_10_0.u32StartAddress = gstMEDMAddr.stBuf_08_1.u32StartAddress + 0x80000;
	gstMEDMAddr.stBuf_10_1.u32StartAddress = gstMEDMAddr.stBuf_10_0.u32StartAddress;

	gstMEDMAddr.u32Buf_12_LineOffset = 0x80;
	gstMEDMAddr.stBuf_12_0.u32StartAddress = gstMEDMAddr.stBuf_10_0.u32StartAddress + 0x40000;
	gstMEDMAddr.stBuf_12_1.u32StartAddress = gstMEDMAddr.stBuf_12_0.u32StartAddress;

	gstMEDMAddr.u32Buf_14_LineOffset = 0x80;
	gstMEDMAddr.stBuf_14_0.u32StartAddress = gstMEDMAddr.stBuf_12_1.u32StartAddress + 0x11000;
	gstMEDMAddr.stBuf_14_1.u32StartAddress = gstMEDMAddr.stBuf_14_0.u32StartAddress;

	Mid_DM_SetKMEStartAddress(&gstMEDMAddr);
	Mid_DM_SetKMEOffsetAddress(&gstMEDMAddr);
}

static VOID _MEMC_LibSetMVDMAddress(UINT32 u32MVStartAddr)
{
	gstMVDMAddr.u32Buf_01_LineOffset = 0x300;
	gstMVDMAddr.u32Buf_01_LROffset = 0x10000;	//0x20000
	gstMVDMAddr.stBuf_01_0.u32StartAddress = u32MVStartAddr;

	gstMVDMAddr.u32Buf_02_LineOffset = 0x500;
	gstMVDMAddr.u32Buf_02_LROffset = 0x15800;	//0x2C000
	gstMVDMAddr.stBuf_02_0.u32StartAddress = gstMVDMAddr.stBuf_01_0.u32StartAddress + gstMVDMAddr.u32Buf_01_LROffset * 2;

	gstMVDMAddr.u32Buf_04_LineOffset = 0x400;
	gstMVDMAddr.u32Buf_04_LROffset = 0x11000;	// 0x22000
	gstMVDMAddr.stBuf_04_0.u32StartAddress = gstMVDMAddr.stBuf_02_0.u32StartAddress + gstMVDMAddr.u32Buf_02_LROffset * 2;
	gstMVDMAddr.stBuf_04_1.u32StartAddress = gstMVDMAddr.stBuf_04_0.u32StartAddress + gstMVDMAddr.u32Buf_04_LROffset * 2;
	gstMVDMAddr.stBuf_04_2.u32StartAddress = gstMVDMAddr.stBuf_04_1.u32StartAddress + gstMVDMAddr.u32Buf_04_LROffset * 2;

	gstMVDMAddr.u32Buf_05_LineOffset = 0x800;
	gstMVDMAddr.u32Buf_05_LROffset = 0x22000;	//0x44000
	gstMVDMAddr.stBuf_05_0.u32StartAddress = gstMVDMAddr.stBuf_04_2.u32StartAddress + gstMVDMAddr.u32Buf_04_LROffset * 2;
	gstMVDMAddr.stBuf_05_1.u32StartAddress = gstMVDMAddr.stBuf_05_0.u32StartAddress + gstMVDMAddr.u32Buf_05_LROffset * 2;

	gstMVDMAddr.u32Buf_12_LineOffset = 0x1E0;
	gstMVDMAddr.u32Buf_12_LROffset = 0x20000;
	gstMVDMAddr.stBuf_12_0.u32StartAddress = gstMVDMAddr.stBuf_05_1.u32StartAddress + gstMVDMAddr.u32Buf_05_LROffset * 2;
	gstMVDMAddr.stBuf_12_1.u32StartAddress = gstMVDMAddr.stBuf_12_0.u32StartAddress + gstMVDMAddr.u32Buf_12_LROffset * 2;
	gstMVDMAddr.stBuf_12_2.u32StartAddress = gstMVDMAddr.stBuf_12_1.u32StartAddress + gstMVDMAddr.u32Buf_12_LROffset * 2;
	gstMVDMAddr.stBuf_12_3.u32StartAddress = gstMVDMAddr.stBuf_12_2.u32StartAddress + gstMVDMAddr.u32Buf_12_LROffset * 2;
	gstMVDMAddr.stBuf_12_4.u32StartAddress = gstMVDMAddr.stBuf_12_3.u32StartAddress + gstMVDMAddr.u32Buf_12_LROffset * 2;
	gstMVDMAddr.stBuf_12_5.u32StartAddress = gstMVDMAddr.stBuf_12_4.u32StartAddress + gstMVDMAddr.u32Buf_12_LROffset * 2;
#ifdef REAL_CHIP
	gstMVDMAddr.stBuf_12_6.u32StartAddress = gstMVDMAddr.stBuf_12_5.u32StartAddress;
	gstMVDMAddr.stBuf_12_7.u32StartAddress = gstMVDMAddr.stBuf_12_5.u32StartAddress;
#else
	gstMVDMAddr.stBuf_12_6.u32StartAddress = gstMVDMAddr.stBuf_12_5.u32StartAddress + gstMVDMAddr.u32Buf_12_LROffset * 2;
	gstMVDMAddr.stBuf_12_7.u32StartAddress = gstMVDMAddr.stBuf_12_6.u32StartAddress + gstMVDMAddr.u32Buf_12_LROffset * 2;
#endif

	Mid_DM_SetKMVStartAddress(&gstMVDMAddr);
	Mid_DM_SetKMVOffsetAddress(&gstMVDMAddr);
}

static VOID _MEMC_LibSetMCDMAddress(UINT32 u32MCStartAddr)
{
	if((gstAppData.stModeData.enInOutMode == MEMC_RGB_IN_VIDEO_OUT) ||
		(gstAppData.stModeData.enInOutMode == MEMC_YUV_IN_VIDEO_OUT))
	{
		gstMCDMAddr.stBuf_HF_0.u32StartAddress = u32MCStartAddr;
		gstMCDMAddr.stBuf_HF_1.u32StartAddress = gstMCDMAddr.stBuf_HF_0.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_HF_2.u32StartAddress = gstMCDMAddr.stBuf_HF_1.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_HF_3.u32StartAddress = gstMCDMAddr.stBuf_HF_2.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_HF_4.u32StartAddress = gstMCDMAddr.stBuf_HF_3.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_HF_5.u32StartAddress = gstMCDMAddr.stBuf_HF_4.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
#ifdef REAL_CHIP
		gstMCDMAddr.stBuf_HF_6.u32StartAddress = gstMCDMAddr.stBuf_HF_5.u32StartAddress;
		gstMCDMAddr.stBuf_HF_7.u32StartAddress = gstMCDMAddr.stBuf_HF_5.u32StartAddress;
#else
		gstMCDMAddr.stBuf_HF_6.u32StartAddress = gstMCDMAddr.stBuf_HF_5.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_HF_7.u32StartAddress = gstMCDMAddr.stBuf_HF_6.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
#endif
		gstMCDMAddr.stBuf_LF_0.u32StartAddress = gstMCDMAddr.stBuf_HF_7.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_LF_1.u32StartAddress = gstMCDMAddr.stBuf_LF_0.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_LF_2.u32StartAddress = gstMCDMAddr.stBuf_LF_1.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_LF_3.u32StartAddress = gstMCDMAddr.stBuf_LF_2.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_LF_4.u32StartAddress = gstMCDMAddr.stBuf_LF_3.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_LF_5.u32StartAddress = gstMCDMAddr.stBuf_LF_4.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
#ifdef REAL_CHIP
		gstMCDMAddr.stBuf_LF_6.u32StartAddress = gstMCDMAddr.stBuf_LF_5.u32StartAddress;
		gstMCDMAddr.stBuf_LF_7.u32StartAddress = gstMCDMAddr.stBuf_LF_5.u32StartAddress;
#else
		gstMCDMAddr.stBuf_LF_6.u32StartAddress = gstMCDMAddr.stBuf_LF_5.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_LF_7.u32StartAddress = gstMCDMAddr.stBuf_LF_6.u32StartAddress + VD_MODE_KMC_LR_OFFSET_ADDR * 2;
#endif
		gstMCDMAddr.u32LineOffset = VD_MODE_KMC_LINE_OFFSET_ADDR;
		gstMCDMAddr.u32LROffset = VD_MODE_KMC_LR_OFFSET_ADDR;
	}
	else
	{
		gstMCDMAddr.stBuf_HF_0.u32StartAddress = u32MCStartAddr;
		gstMCDMAddr.stBuf_HF_1.u32StartAddress = gstMCDMAddr.stBuf_HF_0.u32StartAddress + PC_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_HF_2.u32StartAddress = gstMCDMAddr.stBuf_HF_1.u32StartAddress + PC_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_HF_3.u32StartAddress = gstMCDMAddr.stBuf_HF_2.u32StartAddress;
		gstMCDMAddr.stBuf_HF_4.u32StartAddress = gstMCDMAddr.stBuf_HF_3.u32StartAddress;
		gstMCDMAddr.stBuf_HF_5.u32StartAddress = gstMCDMAddr.stBuf_HF_4.u32StartAddress;
		gstMCDMAddr.stBuf_HF_6.u32StartAddress = gstMCDMAddr.stBuf_HF_5.u32StartAddress;
		gstMCDMAddr.stBuf_HF_7.u32StartAddress = gstMCDMAddr.stBuf_HF_6.u32StartAddress;

		gstMCDMAddr.stBuf_LF_0.u32StartAddress = gstMCDMAddr.stBuf_HF_5.u32StartAddress + PC_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_LF_1.u32StartAddress = gstMCDMAddr.stBuf_LF_0.u32StartAddress + PC_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_LF_2.u32StartAddress = gstMCDMAddr.stBuf_LF_1.u32StartAddress + PC_MODE_KMC_LR_OFFSET_ADDR * 2;
		gstMCDMAddr.stBuf_LF_3.u32StartAddress = gstMCDMAddr.stBuf_LF_2.u32StartAddress;
		gstMCDMAddr.stBuf_LF_4.u32StartAddress = gstMCDMAddr.stBuf_LF_3.u32StartAddress;
		gstMCDMAddr.stBuf_LF_5.u32StartAddress = gstMCDMAddr.stBuf_LF_4.u32StartAddress;
		gstMCDMAddr.stBuf_LF_6.u32StartAddress = gstMCDMAddr.stBuf_LF_5.u32StartAddress;
		gstMCDMAddr.stBuf_LF_7.u32StartAddress = gstMCDMAddr.stBuf_LF_6.u32StartAddress;

		gstMCDMAddr.u32LineOffset = PC_MODE_KMC_LINE_OFFSET_ADDR;
		gstMCDMAddr.u32LROffset = PC_MODE_KMC_LR_OFFSET_ADDR;
	}

	Mid_DM_SetKMCStartAddress(&gstMCDMAddr);
	Mid_DM_SetKMCOffsetAddress(gstMCDMAddr.u32LineOffset, gstMCDMAddr.u32LROffset);

	if(Scaler_MEMC_GetInitFlag() == 0){
		Mid_DM_SetKMCEngineEnable(TRUE);
		MEMC_LibSetMEMCFrameRepeatEnable((gstAppData.stMEMCData.enMemcMode==MEMC_OFF ||gstAppData.stMEMCData.enMemcMode==MEMC_MODE_MAX), 1);
	}
}

/**
 * @brief This function must be invoked when boot up.(boot sequence: MEMC_LibPanel_Init -> MEMC_LibSetPanelParameters -> MEMC_LibInit)
 * @retval VOID
*/
VOID MEMC_LibPanel_Init(VOID)
{
	UINT16 u16Idx = 0;
#ifndef REAL_CHIP	// FPGA
	PANEL_PARA_ST stPanel_Para;
#endif
	for(u16Idx = 0; u16Idx < OUTPUT_FRAMERATE_MAX; u16Idx++)
	{
		gstPanelData.stPanelParamertes[u16Idx].enOutputFrameRate = OUTPUT_FRAMERATE_INVALID;
	}
#ifndef REAL_CHIP	// FPGA
	stPanel_Para.enOutputFrameRate = OUTPUT_120HZ;
	stPanel_Para.u32Htotal = 2200;
	stPanel_Para.u32HtotalMax = 2400;
	stPanel_Para.u32HtotalMin = 2000;
	stPanel_Para.u32Hactive = 1920;
	stPanel_Para.u32HSWidth = 64;
	stPanel_Para.u32HSBPorch = 168;
	stPanel_Para.u32Vtotal = 1125;
	stPanel_Para.u32VtotalMax = 1150;
	stPanel_Para.u32VtotalMin = 1100;
	stPanel_Para.u32Vactive = 1080;
	stPanel_Para.u32VSWidth = 8;
	stPanel_Para.u32VSBPorch = 35;

	MEMC_LibSetPanelParameters(&stPanel_Para);

	stPanel_Para.enOutputFrameRate = OUTPUT_60HZ;
	stPanel_Para.u32Htotal = 4400;
	stPanel_Para.u32HtotalMax = 4800;
	stPanel_Para.u32HtotalMin = 4000;
	stPanel_Para.u32Hactive = 3840;
	stPanel_Para.u32HSWidth = 64;
	stPanel_Para.u32HSBPorch = 168;
	stPanel_Para.u32Vtotal = 1125;
	stPanel_Para.u32VtotalMax = 1150;
	stPanel_Para.u32VtotalMin = 1100;
	stPanel_Para.u32Vactive = 1080;
	stPanel_Para.u32VSWidth = 8;
	stPanel_Para.u32VSBPorch = 35;

	MEMC_LibSetPanelParameters(&stPanel_Para);

#endif
}

/*! MEMC Library exported api list */
/**
 * @brief This function must be invoked when boot up.(boot sequence: MEMC_LibPanel_Init -> MEMC_LibSetPanelParameters -> MEMC_LibInit)
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL MEMC_LibInit(VOID)
{
	BOOL	bRet = TRUE;
	SCHAR 	scBuf[60];

#ifdef WIN32
	InitPrintf();
#endif
	MEMC_LibGetVersionInfo(scBuf, 60, MODULE_ID_APP);
	//LogPrintf(DBG_MSG,"%s\r\n", scBuf);
	MEMC_LibGetVersionInfo(scBuf, 60, MODULE_ID_FRC);
	//LogPrintf(DBG_MSG,"%s\r\n", scBuf);
	//LogPrintf(DBG_MSG, "MEMC lib init...\r\n");
	/* Load app data */
	// do later
	/* Load default table */
#ifdef REAL_CHIP	// real chip
        #ifdef USE_LOAD_HDF
	HAL_HDF_Load();
	#else
	#include "memc_isr/include/hdf.tbl"
        #endif
	MEMC_SetRTKhdf();
#endif
	/* Init FRC library */
	PQL_Init();
	MEMC_LibSetInOutFrameRate(INPUT_60HZ, OUTPUT_60HZ);
#ifndef REAL_CHIP	// FPGA
	MEMC_LibPanel_Init();
#endif

	_MEMC_LibSetMEDMAddress(gstDMAddrAllocate.u32MEStart);
	_MEMC_LibSetMVDMAddress(MV_START_ADDR);

	MEMC_LibSetInOutMode(MEMC_RGB_IN_VIDEO_OUT,TRUE);
#ifdef REAL_CHIP	// real chip
	MEMC_LibSetInOutUseCase(INPUT_3840X2160, OUTPUT_3840X2160, INPUT_2D, OUTPUT_2D);
#else
	MEMC_LibSetInOutUseCase(INPUT_1920X1080, OUTPUT_1920X1080, INPUT_2D, OUTPUT_2D);
#endif

#ifdef REAL_CHIP	// real chip
	// Use mute sync
	Mid_MISC_SetUseMuteSyncEnable(TRUE);
	// Enable mute detect
	Mid_MISC_SetMuteDetectEnable(TRUE);
#endif
	// Enable in/out Hsync interrupt
	Mid_MISC_SetInINTEnable(INT_TYPE_HSYNC, FALSE);
	Mid_MISC_SetOutINTEnable(INT_TYPE_HSYNC, FALSE);
	// Enable in/out Vsync interrupt
	//Mid_MISC_SetInINTEnable(INT_TYPE_VSYNC, TRUE);
	//Mid_MISC_SetOutINTEnable(INT_TYPE_VSYNC, TRUE);
	MEMC_LibSetMEMCMode(MEMC_NORMAL);

	return bRet;
}

/**
 * @brief This function must be last invoked api. No api should be invoked after library deinit. This function deinit MEMC library stack.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL MEMC_LibDeInit(VOID)
{
	BOOL	bRet = TRUE;

	//bRet = Drv_IIC_Close();
	return bRet;
}

/**
 * @brief This function defines operation during input HS SINT32errupt procedure. Must be invoked after input HS SINT32errupt happened.
 *
*/
VOID MEMC_LibInputHSInterrupt(VOID)
{
}

/**
 * @brief This function defines input hsync interrput line num.
 * @param [in] u32LineNum	   Specify hsync interrupt line num.
 *
*/
VOID MEMC_LibInputHSInterruptLineNum(UINT32 u32LineNum)
{
	Mid_MISC_SetInINTHnum(u32LineNum);
}

/**
 * @brief This function defines input hsync interrput enable or not.
 * @param [in] bEnable		enable or disable the input hync interrupt
 *
*/
VOID MEMC_LibInputHSInterruptEnable(BOOL bEnable)
{
	Mid_MISC_SetInINTEnable(INT_TYPE_HSYNC, bEnable);
}

/**
 * @brief This function defines operation during input vsync procedure.
 *
*/
#ifdef CONFIG_MEMC_ISR_CNT_MAX

typedef enum{
	MONITOR_STATUS_NORMAL = 0,
	MONITOR_STATUS_ERROR
}ENUM_MEMC_MONITOR_STATUS;

static ENUM_MEMC_MONITOR_STATUS g_memc_in_status = MONITOR_STATUS_NORMAL;
static ENUM_MEMC_MONITOR_STATUS g_memc_out_status = MONITOR_STATUS_NORMAL;
static int64_t s_memc_in_dis_tm = 0;
static int64_t s_memc_out_dis_tm = 0;
extern int64_t MEMC_GetPTS(void);
static int g_memc_mear_cnt = 0;
static void start_tm_mear(void)
{
	#ifdef CONFIG_HW_SUPPORT_MEMC
	unsigned int v = 0;
	/*enable kmc measure*/
	v = rtd_inl(0xb8099018);
	v = (v & 0xfff80007) | 0x4078;//en =1,sel=7,vtotal=0x80
	rtd_outl(0xb8099018,v);
	/*enable kpost measure*/
	v = rtd_inl(0xb809d004);
	v = (v & 0x0000ffff) | 0x080f0000;//en =1,sel=7,vtotal=0x80
	rtd_outl(0xb809d004,v);
	if(g_memc_mear_cnt < 0)
		g_memc_mear_cnt = 0;
	g_memc_mear_cnt++;
	#endif
}

static void stop_tm_mear(void)
{
	#ifdef CONFIG_HW_SUPPORT_MEMC
	unsigned int v = 0,sKmcTotalH = 0,sKmcActH = 0,sKmcTotalV = 0,sKmcActV = 0,sPostTotalH = 0,sPostActH = 0,sPostTotalV = 0,sPostActV = 0;

	if(g_memc_mear_cnt <= 0){
		g_memc_mear_cnt = 0;
		return;
	}
	/*read measure result*/
	rtd_outl(0xb8099018,rtd_inl(0xb8099018) & ~_BIT6);
	v = rtd_inl(0xb80990f4);
	sKmcActH = v & 0xfff;
	sKmcActV = (v >> 12) & 0xfff;
	v = rtd_inl(0xb80990f8);
	sKmcTotalH = v & 0xfff;
	sKmcTotalV = (v >> 12) & 0xfff;
	rtd_outl(0xb809d004,rtd_inl(0xb809d004) & ~_BIT19);
	v = rtd_inl(0xb809d0ec);
	sPostActH = v & 0xfff;
	sPostActV = (v >> 12) & 0xfff;
	v = rtd_inl(0xb809d0f0);
	sPostTotalH = v & 0xfff;
	sPostTotalV = (v >> 12) & 0xfff;
	/*print timing measure*/
	LogPrintf(DBG_WARNING,"Timing[in:Act(V=%d,H=%d),Total(V=%d,H=%d);out:Act(V=%d,H=%d),Total(V=%d,H=%d)]\n",\
		sKmcActV,sKmcActH,sKmcTotalV,sKmcTotalH,sPostActV,sPostActH,sPostTotalV,sPostTotalH);
	g_memc_mear_cnt--;
	#endif
}

static void print_monitor_debug(int fInIsr)
{
	if(fInIsr){
		LogPrintf(DBG_WARNING,"==============In ISR Debug info==============\n");
	}else{
		LogPrintf(DBG_WARNING,"==============Out ISR Debug info==============\n");
	}
	/*dtg settings*/
	LogPrintf(DBG_WARNING,"DTG[Master:V=0x%08x,H=0x%08x;UZU:V=0x%08x,H=0x%08x;MEMC:V=0x%08x,H=0x%08x]\n",\
			rtd_inl(0xb8028014),rtd_inl(0xb802800c),\
			rtd_inl(0xb8028504),rtd_inl(0xb8028508),\
			rtd_inl(0xb8028604),rtd_inl(0xb8028608));
	LogPrintf(DBG_WARNING,"DTG[0xB8028000=0x%08x,0xB8028248=0x%08x]\n",rtd_inl(0xB8028000),rtd_inl(0xb8028248));
	/*memc interrupt*/
	LogPrintf(DBG_WARNING,"ISR[0xB8099018=0x%08x,0xB809d008=0x%08x,0xB80991f4=0x%08x,0xb80990f8=0x%08x,0xb809d0f0=0x%08x]\n",\
				rtd_inl(0xB8099018),rtd_inl(0xB809d008),rtd_inl(0xB80991f4),rtd_inl(0xb80990f8),rtd_inl(0xb809d0f0));
	LogPrintf(DBG_WARNING,"FrameRate[in=%d,out=%d]\n",rtd_inl(0xB80282e4),rtd_inl(0xB80282ec));
}
#endif
VOID MEMC_LibInputVSInterrupt(VOID)
{

#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
//====================================================
	unsigned int time1,time2,time3, time_stamp;
	static unsigned int time1s_set=0;
	static unsigned int time1s_start=0;
	static unsigned int time1s_end=0;
	static unsigned int time1s_cnt=0;
	static unsigned int exe_count=0;
	static unsigned int exe_count_out=0;
	static unsigned int time_stamp_pre = 0;

	unsigned int reg_value = 0;
	reg_value = rtd_inl(0xb802e4f8);

	if((reg_value & BIT(31))){
		time1 = rtd_inl(0xB801B6A8);
		if(time1s_set==0) {
			time1s_start = time1;
			time1s_set=1;
			time1s_cnt=0;
		}
		time1s_end = rtd_inl(0xB801B6A8);
	}
//====================================================
#endif
	//LogPrintf(DBG_MSG, "In vs interrupt\r\n");
	if(Mid_MISC_GetInINTStatus(INT_TYPE_VSYNC))
	{
		//LogPrintf(DBG_MSG,"IV\n");
		Mid_MISC_IntINTLock(INT_TYPE_VSYNC);
#ifndef debug_MEMC_ISR
		if(Mid_MISC_GetInINTEnable(INT_TYPE_VSYNC)){
			MEMC_LibInputVSXral();
			MEMC_LibGetScalerVIPInfo();
			PQL_InputInterrupt_Proc(0);
		}
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
		if((reg_value & BIT(31))){
			do{
				time3=rtd_inl(0xB801B6A8);
			}while((time3-time1)<=5);
		}
#endif

#endif

		Mid_MISC_IntINTUnLock(INT_TYPE_VSYNC);
		Mid_MISC_IntINTCLear(INT_TYPE_VSYNC);
#ifdef CONFIG_MEMC_ISR_CNT_MAX
		if(Mid_MISC_GetInINTEnable(INT_TYPE_VSYNC)){
			static unsigned int sEnterCnt = 0;
			static int64_t sLastPts_1s = 0;
			int64_t currentPts = MEMC_GetPTS();

			sEnterCnt++;
			if(currentPts < sLastPts_1s){
				sLastPts_1s = currentPts;
				sEnterCnt = 0;
			}
			if(currentPts - sLastPts_1s > 90090){
				//LogPrintf(DBG_WARNING,"in(cnt:%d,%d,%d)'\n", sEnterCnt,g_memc_in_status,g_memc_out_status);
				if(sEnterCnt >= CONFIG_MEMC_IN_ISR_CNT_MAX){
					g_memc_in_status = MONITOR_STATUS_ERROR;
					LogPrintf(DBG_WARNING,"[Warning]Enter 'MEMC_LibInputVSInterrupt' Count:[%d/s]\n", sEnterCnt);
					/*start time measure*/
					start_tm_mear();
					/*print debug infomation*/
					print_monitor_debug(1);
					/*disable isr*/
					Mid_MISC_SetInINTEnable(INT_TYPE_VSYNC,FALSE);
					s_memc_in_dis_tm = currentPts;
				}else{
					g_memc_in_status = MONITOR_STATUS_NORMAL;
				}
				sLastPts_1s = currentPts;
				sEnterCnt = 0;
			}
			if(g_memc_out_status == MONITOR_STATUS_ERROR){
				/*stop time measre and print tm info*/
				if(currentPts - s_memc_out_dis_tm > 3003)
					stop_tm_mear();
				/*resume isr while current flow is not at dc off*/
				if(currentPts - s_memc_out_dis_tm > 90090){
					Mid_MISC_SetOutINTEnable(INT_TYPE_VSYNC,TRUE);
					g_memc_out_status = MONITOR_STATUS_NORMAL;
					LogPrintf(DBG_WARNING,"Enable out isr.\n");
				}
			}
		}
#endif
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
if((reg_value & BIT(31))){

	//====================================================
	time2=rtd_inl(0xB801B6A8);
	time_stamp = rtd_inl(0xB801B6A8);
	if((exe_count%300==0)) {
		printk("[Input]MEMC timestamp %d(%d - %d)\n",(time_stamp - time_stamp_pre),time_stamp,time_stamp_pre);
		printk("[Input]MEMC flow time %d\n",time2-time1);
		exe_count = 0;
	}
	time_stamp_pre = time_stamp;
}
	//====================================================
#endif
	}

#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
if((reg_value & BIT(31))){

	//====================================================
	if((time1s_end-time1s_start)>=90000) {
		printk("[Input]MEMC isr %d times(%d CLK)\n",time1s_cnt, (time1s_end-time1s_start));
		time1s_set=0;
	}
}
#endif


}

/**
 * @brief This function defines input vsync interrupt enable or not.
 * @param [in] bEnable	   enable or disable the input vsync interrupt
*/
VOID MEMC_LibInputVSInterruptEnable(BOOL bEnable)
{
	Mid_MISC_SetInINTEnable(INT_TYPE_VSYNC, bEnable);
}

/**
 * @brief This function defines operation during output HS SINT32errupt procedure.
 *
*/
VOID MEMC_LibOutpuHSInterrupt(VOID)
{
}

/**
 * @brief This function defines output hsync interrupt line num.
 * @param [in] u32LineNum	   Specify hsync interrupt line num.
*/
VOID MEMC_LibOutpuHSInterruptLineNum(UINT32 u32LineNum)
{
	Mid_MISC_SetOutINTHnum(u32LineNum);
}

/**
 * @brief This function defines output hsync interrupt enable or not.
 * @param [in] bEnable	   enable or disable the out hync interrupt
*/
VOID MEMC_LibOutpuHSInterruptEnable(BOOL bEnable)
{
	Mid_MISC_SetOutINTEnable(INT_TYPE_HSYNC, bEnable);
}

//static UINT32 gu32VspllLockCount = 0;
/**
 * @brief This function defines operation during output VS procedure.
 *
*/
VOID MEMC_LibOutputVSInterrupt(VOID)
{
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	//====================================================
		unsigned int time1,time2, time3, time_stamp;
		static unsigned int time1s_set=0;
		static unsigned int time1s_start=0;
		static unsigned int time1s_end=0;
		static unsigned int time1s_cnt=0;
		static unsigned int exe_count=0;
		static unsigned int exe_count_out=0;
		static unsigned int time_stamp_pre = 0;

		unsigned int reg_value = 0;
		reg_value = rtd_inl(0xb802e4f8);

		if((reg_value & BIT(31))){
			time_stamp=rtd_inl(0xB801B6A8);
			time1 = rtd_inl(0xB801B6A8);
			if(time1s_set==0) {
				time1s_start = time1;
				time1s_set=1;
				time1s_cnt=0;
			}
			time1s_end = rtd_inl(0xB801B6A8);
		}
	//====================================================
#endif


	//LogPrintf(DBG_MSG, "Out vs interrupt\r\n");
	if(Mid_MISC_GetOutINTStatus(INT_TYPE_VSYNC))
	{
		//LogPrintf(DBG_MSG,"OV\n");
		Mid_MISC_OutINTLock(INT_TYPE_VSYNC);
#ifndef debug_MEMC_ISR
		if(Mid_MISC_GetInINTEnable(INT_TYPE_VSYNC) && Mid_MISC_GetOutINTEnable(INT_TYPE_VSYNC)){
			u32OutIntCount++;
			if(u32OutIntCount == 1)
			{
				PQL_oneFifth_OutputInterrupt_Proc(0);
				PQL_OutputInterrupt_Proc(0);
			}
			else if(u32OutIntCount == 2)
			{
				PQL_oneFifth_OutputInterrupt_Proc(1);
				PQL_OutputInterrupt_Proc(1);
			}
			else if(u32OutIntCount == 3)
			{
				PQL_oneFifth_OutputInterrupt_Proc(2);
				PQL_OutputInterrupt_Proc(2);
			}
			else if(u32OutIntCount == 4)
			{
				PQL_oneFifth_OutputInterrupt_Proc(3);
				PQL_OutputInterrupt_Proc(3);
			}
			else if(u32OutIntCount == 5)
			{
				PQL_oneFifth_OutputInterrupt_Proc(4);
				PQL_OutputInterrupt_Proc(4);
				u32OutIntCount = 0;
			}
			else // for quickstart or STR reason, must confirm u32OutIntCount is less than 5, LearnRPG@20151010
			{
				u32OutIntCount = 0;
			}
			//PQL_OutputInterrupt_Proc();
		}
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
		if((reg_value & BIT(31))){
			do{
				time3=rtd_inl(0xB801B6A8);
			}while((time3-time1)<=5);
		}
#endif


#endif
		Mid_MISC_OutINTUnLock(INT_TYPE_VSYNC);
		Mid_MISC_OutINTCLear(INT_TYPE_VSYNC);
#ifdef CONFIG_MEMC_ISR_CNT_MAX
		if(Mid_MISC_GetOutINTEnable(INT_TYPE_VSYNC)){
			static unsigned int sEnterCnt = 0;
			static int64_t sLastPts_1s = 0;
			int64_t currentPts = MEMC_GetPTS();

			sEnterCnt++;
			if(currentPts < sLastPts_1s){
				sLastPts_1s = currentPts;
				sEnterCnt = 0;
			}
			if(currentPts - sLastPts_1s > 90090){
				//LogPrintf(DBG_WARNING,"out(cnt:%d,%d,%d)'\n", sEnterCnt,g_memc_in_status,g_memc_out_status);
				if(sEnterCnt >= CONFIG_MEMC_OUT_ISR_CNT_MAX){
					/*start time measure*/
					start_tm_mear();
					g_memc_out_status = MONITOR_STATUS_ERROR;
					LogPrintf(DBG_WARNING,"[Warning]Enter 'MEMC_LibOutputVSInterrupt' Count:[%d/s]\n", sEnterCnt);
					/*print debug infomation*/
					print_monitor_debug(0);
					/*disable isr*/
					Mid_MISC_SetOutINTEnable(INT_TYPE_VSYNC,FALSE);
					s_memc_out_dis_tm = currentPts;
				}else{
					g_memc_out_status = MONITOR_STATUS_NORMAL;
				}
				sLastPts_1s = currentPts;
				sEnterCnt = 0;
			}
			if(g_memc_in_status == MONITOR_STATUS_ERROR){
				/*stop time measre and print tm info*/
				if(currentPts - s_memc_in_dis_tm > 3003)
					stop_tm_mear();
				/*resume isr while current flow is not at dc off*/
				if(currentPts - s_memc_in_dis_tm > 90090){
					Mid_MISC_SetInINTEnable(INT_TYPE_VSYNC,TRUE);
					g_memc_in_status = MONITOR_STATUS_NORMAL;
					LogPrintf(DBG_WARNING,"Enable in isr.\n");
				}
			}
		}
#endif
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	//====================================================
if((reg_value & BIT(31))){
	time2=rtd_inl(0xB801B6A8);
	if(exe_count%300==0) {
		printk("[Output]MEMC timestamp %d(%d - %d)\n",(time_stamp - time_stamp_pre),time_stamp,time_stamp_pre);
		printk("[Output]MEMC flow time %d\n",time2-time1);
		exe_count = 0;
	}
	time_stamp_pre = time_stamp;
}
	//====================================================
#endif
	}

#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
if((reg_value & BIT(31))){
//====================================================
	if((time1s_end-time1s_start)>=90000) {
		printk("[Output]MEMC isr %d times(%d CLK)\n",time1s_cnt, (time1s_end-time1s_start));
		time1s_set=0;
	}
}
//====================================================
#endif


}

/**
 * @brief This function defines output vsync interrupt enable or not.
 * @param [in] bEnable	  enable or disable the out hync interrupt
*/
VOID MEMC_LibOutputVSInterruptEnable(BOOL bEnable)
{
	Mid_MISC_SetOutINTEnable(INT_TYPE_VSYNC, bEnable);
}

/**
 * @brief This function defines operation during Abnormal SINT32errupt procedure. Must be invoked after Abnormal SINT32errupt happened.
 *
*/
VOID MEMC_LibAbnormalInterrupt(VOID)
{
}

/**
 * @brief This function defines abnormal interrupt enable or not.
 * @param [in] bEnable	 enable or disable the abnormal interrupt
*/
VOID MEMC_LibAbnormalInterruptEnable(BOOL bEnable)
{
	Mid_MISC_SetInINTEnable(INT_TYPE_ABNORMAL, bEnable);
}

/**
 * @brief This function set MEMC in/out mode. (please add almost 25ms mute to avoid garbage)
 * @param [in] emom 		Specify in/out MEMC mode.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL MEMC_LibSetInOutMode(MEMC_INOUT_MODE emom,BOOL bForce)
{
	_PQL_Command Command;
	if(bForce == TRUE || emom != gstAppData.stModeData.enInOutMode)
	{
		gstAppData.stModeData.enInOutMode = emom;

		Mid_Mode_SetInOutMode((INOUT_MODE)emom);
		Mid_Mode_SetMCBlend((INOUT_MODE)emom);
		Mid_Mode_ForceLBMCIdx((INOUT_MODE)emom, (OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);

		Mid_DM_SetKMCEngineEnable(FALSE);
		_MEMC_LibSetMCDMAddress(gstDMAddrAllocate.u32MC0Start);
		Mid_DM_SetKMCEndAddress(&gstMCDMAddr);
		Mid_DM_SetKMCEngineEnable(TRUE);

		Mid_DM_SetKMEEngineEnable(TRUE,
								  (INOUT_MODE)emom,
								  (INPUT_FORMAT)gstAppData.stModeData.enInputFormat,
								  (OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);

		if((emom == MEMC_RGB_IN_VIDEO_OUT) || (emom == MEMC_YUV_IN_VIDEO_OUT))
		{
			Command._output_mode = _PQL_OUT_VIDEO_MODE;
		}
		else
		{
			Command._output_mode = _PQL_OUT_PC_MODE;
		}
		PQL_Command(PQL_CMD_OUTPUT_MODE, &Command);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 * @brief This function returns current MEMC In/Out mode.
 * @retval MEMC_INOUT_MODE		enum type value
*/
MEMC_INOUT_MODE MEMC_LibGetInOutMode(VOID)
{
	return (gstAppData.stModeData.enInOutMode);
}

/**
 * @brief This function set input/output format.
 * @param [in] emif 		Specify input format.
 * @param [in] emof 		Specify output format.
 * @param [in] bForce 		force to change the format or not.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
static BOOL _MEMC_LibSetInOutUseCase(MEMC_INPUT_RESOLUTION emir, MEMC_OUTPUT_RESOLUTION emor,
												MEMC_INPUT_FORMAT emif, MEMC_OUTPUT_FORMAT emof, BOOL bForce)
{
	BOOL	bRet = FALSE;
	PANEL_PARA_ST stPanelPara;
	PANEL_PARAMETERS_ST stPanelParamertes;
	_PQL_Command Command;
	MEMC_OUTPUT_FORMAT emOutput_Format;
	UBYTE u8_in_me1_pix_sft = 0;
	UBYTE u8_in_me1_blk_sft = 0;
	UBYTE u8_in_me2_pix_sft = 0;
	UBYTE u8_in_me2_blk_sft = 0;

	if(!bForce)
	{
		if ((emir == gstAppData.stModeData.enInputRes) && (emor == gstAppData.stModeData.enOutputRes) &&
			(emif == gstAppData.stModeData.enInputFormat) && (emof == gstAppData.stModeData.enOutputFormat))
		{
			LogPrintf(DBG_WARNING, "*****************Same use case*****************\r\n");
			return FALSE;
		}
	}

	emOutput_Format = emof;

	if(emof == OUTPUT_3D_SG_LLRR)
	{
		emof = OUTPUT_3D_SG;
	}
	bRet = Mid_Mode_UpdateParameters((INPUT_RESOLUTION)emir, (OUTPUT_RESOLUTION)emor, (INPUT_FORMAT)emif, (OUTPUT_FORMAT)emof);

	if(!bRet)
	{
		LogPrintf(DBG_ERROR, "*****************Invalid use case*****************\r\n");

		LogPrintf(DBG_ERROR, "MEMC lib set in/out resolution = %d / %d\r\n", (UINT32)emir, (UINT32)emor);
		LogPrintf(DBG_ERROR, "MEMC lib set in/out format = %d / %d\r\n",(UINT32)emif, (UINT32)emof);

		return FALSE;
	}
	else
	{
		LogPrintf(DBG_MSG, "******************Valid use case******************\r\n");

		LogPrintf(DBG_MSG, "MEMC lib set in/out resolution = %d / %d\r\n", (UINT32)emir, (UINT32)emor);
		LogPrintf(DBG_MSG, "MEMC lib set in/out format = %d / %d\r\n",(UINT32)emif, (UINT32)emof);
	}

	Mid_Mode_Set_InputTimingParameters((INPUT_RESOLUTION)emir);
	Mid_Mode_Set_OutputTimingParameters((OUTPUT_RESOLUTION)emor);
	Mid_Mode_Set_VideoPath((INPUT_RESOLUTION)emir,
							(OUTPUT_RESOLUTION)emor,
							(INPUT_FORMAT)emif,
							(OUTPUT_FORMAT)emof,
							gstAppData.stModeData.bVflip);

	Mid_Mode_GetMEMCModuleSft(&u8_in_me1_pix_sft,&u8_in_me1_blk_sft,&u8_in_me2_pix_sft,&u8_in_me2_blk_sft);
	Mid_MEMC_SetMEMCModuleRatio(u8_in_me1_pix_sft,u8_in_me1_blk_sft,u8_in_me2_pix_sft,u8_in_me2_blk_sft);

	gstAppData.stModeData.enInputRes = emir;
	gstAppData.stModeData.enOutputRes = emor;
	gstAppData.stModeData.enInputFormat = emif;
	gstAppData.stModeData.enOutputFormat = emOutput_Format;

	Mid_Mode_LastLineEnable(gstAppData.stModeData.bVflip, (INPUT_FORMAT)emif, (OUTPUT_FORMAT)emof);

	if((gstAppData.stModeData.enOutputFrameRate == OUTPUT_50HZ) ||
		(gstAppData.stModeData.enOutputFrameRate == OUTPUT_60HZ))
	{
		Mid_Mode_SetMEWorkMode(0);	// 1:2
		Mid_Mode_SetPPFVIDX(0, (OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);
	}
	else
	{
		Mid_Mode_SetMEWorkMode(1);	// 1:1
		Mid_Mode_SetPPFVIDX(1, (OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);
	}

	Mid_Mode_ForceLBMCIdx((INOUT_MODE)gstAppData.stModeData.enInOutMode, (OUTPUT_FORMAT)emof);

	Mid_DM_SetKMEEngineEnable(FALSE,
							 (INOUT_MODE)gstAppData.stModeData.enInOutMode,
							 (INPUT_FORMAT)emif, (OUTPUT_FORMAT)emof);
	Mid_DM_SetKMVEngineEnable(FALSE);
	Mid_DM_SetKMCEngineEnable(FALSE);

	if(emif == INPUT_3D_SBS)
	{
		Mid_DM_SetKMCOffsetAddress(gstMCDMAddr.u32LineOffset / 2, gstMCDMAddr.u32LROffset);
	}
	else
	{
		Mid_DM_SetKMCOffsetAddress(gstMCDMAddr.u32LineOffset, gstMCDMAddr.u32LROffset);
	}

	Mid_DM_SetKMEEndAddress(&gstMEDMAddr);
	Mid_DM_SetKMVEndAddress(&gstMVDMAddr);
	Mid_DM_SetKMCEndAddress(&gstMCDMAddr);

	Mid_DM_SetKMEEngineEnable(TRUE,
							 (INOUT_MODE)gstAppData.stModeData.enInOutMode,
							 (INPUT_FORMAT)emif, (OUTPUT_FORMAT)emof);
	Mid_DM_SetKMVEngineEnable(TRUE);
	Mid_DM_SetKMCEngineEnable(TRUE);

	bRet = MEMC_LibGetCurrentPanelParameters(&stPanelPara);

	if(bRet)
	{
		stPanelParamertes.enOutputFrameRate = (OUTPUT_FRAMERATE)stPanelPara.enOutputFrameRate;
		stPanelParamertes.u32Htotal = stPanelPara.u32Htotal;
		stPanelParamertes.u32HtotalMax = stPanelPara.u32HtotalMax;
		stPanelParamertes.u32HtotalMin = stPanelPara.u32HtotalMin;
		stPanelParamertes.u32Hactive = stPanelPara.u32Hactive;
		stPanelParamertes.u32HSWidth = stPanelPara.u32HSWidth;
		stPanelParamertes.u32HSBPorch = stPanelPara.u32HSBPorch;
		stPanelParamertes.u32Vtotal = stPanelPara.u32Vtotal;
		stPanelParamertes.u32VtotalMax = stPanelPara.u32VtotalMax;
		stPanelParamertes.u32VtotalMin = stPanelPara.u32VtotalMin;
		stPanelParamertes.u32Vactive = stPanelPara.u32Vactive;
		stPanelParamertes.u32VSWidth = stPanelPara.u32VSWidth;
		stPanelParamertes.u32VSBPorch = stPanelPara.u32VSBPorch;

		Mid_CRTC_SetFRCTiming((OUTPUT_FORMAT)emof, stPanelParamertes);
		Mid_CRTC_SetPanelTiming((OUTPUT_FORMAT)emof, stPanelParamertes);
	}

#ifndef REAL_CHIP	// FPGA
	Mid_CRTC_SetLbmcTrigDly((OUTPUT_RESOLUTION)emor);
#endif

	if(gstAppData.stModeData.enOutputFormat == OUTPUT_3D_SG)
	{
		Mid_CRTC_Set3DLR(TRUE, 1, 1);
		Mid_Mode_SetME3DLR(FALSE, 0, 0);
	}
	else if(gstAppData.stModeData.enOutputFormat == OUTPUT_3D_SG_LLRR)
	{
		Mid_CRTC_Set3DLR(TRUE, 3, 3);
		Mid_Mode_SetME3DLR(TRUE, 4, 3);
	}
	else
	{
		Mid_CRTC_Set3DLR(FALSE, 0, 0);
		Mid_Mode_SetME3DLR(FALSE, 0, 0);
	}
	bRet = Mid_CRTC_SetN2M((INPUT_FRAMERATE)gstAppData.stModeData.enInputFrameRate,
							(OUTPUT_FRAMERATE)gstAppData.stModeData.enOutputFrameRate,
							(INPUT_FORMAT)gstAppData.stModeData.enInputFormat,
							(OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);

	Command._input_resolution = (PQL_INPUT_RESOLUTION)emir;
	PQL_Command(PQL_CMD_INPUT_RESOLUTION, &Command);
	Command._output_resolution = (PQL_OUTPUT_RESOLUTION)emor;
	PQL_Command(PQL_CMD_OUTPUT_RESOLUTION, &Command);
	Command._input_3dFormat = (PQL_INPUT_3D_FORMAT)emif;
	PQL_Command(PQL_CMD_INPUT_FORMAT, &Command);
	Command._output_3dFormat = (PQL_OUTPUT_3D_FORMAT)emOutput_Format;
	PQL_Command(PQL_CMD_OUTPUT_FORMAT, &Command);

	return bRet;
}

/**
 * @brief This function set input/output use case. (please add almost 25ms mute to avoid garbage)
 * @param [in] emir 		Specify input resolution.
 * @param [in] emor 		Specify output resolution.
 * @param [in] emif 		Specify input MEMC format.
 * @param [in] emof 		Specify output MEMC format.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL MEMC_LibSetInOutUseCase(MEMC_INPUT_RESOLUTION emir, MEMC_OUTPUT_RESOLUTION emor, MEMC_INPUT_FORMAT emif, MEMC_OUTPUT_FORMAT emof)
{
	return _MEMC_LibSetInOutUseCase(emir, emor, emif, emof, FALSE);
}

/**
 * @brief This function get input/output use case. (please add almost 25ms mute to avoid garbage)
 * @param [out] 	pemir 	return current input signal resolution.
 * @param [out] 	pemor 	return current output signal resolution.
 * @param [out] 	pemif 	return current input format mode.
 * @param [out] 	pemof	return current output format mode.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL MEMC_LibGetInOutUseCase(MEMC_INPUT_RESOLUTION *pemir, MEMC_OUTPUT_RESOLUTION *pemor, MEMC_INPUT_FORMAT *pemif, MEMC_OUTPUT_FORMAT *pemof)
{
	if (pemir == NULL || pemor == NULL || pemif == NULL || pemof == NULL)
	{
		return FALSE;
	}

	*pemir = gstAppData.stModeData.enInputRes;
	*pemor = gstAppData.stModeData.enOutputRes;
	*pemif = gstAppData.stModeData.enInputFormat;
	*pemof = gstAppData.stModeData.enOutputFormat;
	return TRUE;
}

/**
 * @brief This function set input/output frame rate.
 * @param [in] emifr 		Specify input frame rate.
 * @param [in] emofr 		Specify output frame rate.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL MEMC_LibSetInOutFrameRate(MEMC_INPUT_FRAMERATE emifr, MEMC_OUTPUT_FRAMERATE emofr)
{
	BOOL bRet = TRUE;
	_PQL_Command Command;

	if((gstAppData.stModeData.enInputFrameRate != emifr) || (gstAppData.stModeData.enOutputFrameRate != emofr))
	{
		Mid_CRTC_SetN2M((INPUT_FRAMERATE)emifr,(OUTPUT_FRAMERATE)emofr,
						(INPUT_FORMAT)gstAppData.stModeData.enInputFormat,
						(OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);
	}
	else
	{
		bRet = FALSE;
	}

	if(gstAppData.stModeData.enInputFrameRate != emifr)
	{
		gstAppData.stModeData.enInputFrameRate = emifr;
		LogPrintf(DBG_MSG, "MEMC Lib set input frame rate =  %d\r\n", emifr);
		Command._input_frameRate = (PQL_INPUT_FRAME_RATE)emifr;
		PQL_Command(PQL_CMD_INPUT_FRAME_RATE, &Command);
	}
	if(gstAppData.stModeData.enOutputFrameRate != emofr)
	{
		gstAppData.stModeData.enOutputFrameRate = emofr;
		LogPrintf(DBG_MSG, "MEMC Lib set output frame rate =  %d\r\n", emofr);
		MEMC_LibApplyPanelParameters(gstAppData.stModeData.enOutputFrameRate);
		Command._output_frameRate = (PQL_OUTPUT_FRAME_RATE)emofr;
		PQL_Command(PQL_CMD_OUTPUT_FRAME_RATE, &Command);

		if((gstAppData.stModeData.enOutputFrameRate == OUTPUT_50HZ) ||
			(gstAppData.stModeData.enOutputFrameRate == OUTPUT_60HZ))
		{
#ifndef REAL_CHIP	// FPGA
			Mid_Mode_SetTOPA2PortEnable(TRUE);
#endif
			Mid_Mode_SetMEWorkMode(0);	// 1:2
			Mid_Mode_SetPPFVIDX(0, (OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);
			Mid_Mode_SetDMPFVPPFVInterval(0x60);
		}
		else
		{
#ifndef REAL_CHIP	// FPGA
			Mid_Mode_SetTOPA2PortEnable(FALSE);
#endif
			Mid_Mode_SetMEWorkMode(1);	// 1:1
			Mid_Mode_SetPPFVIDX(1, (OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);
			Mid_Mode_SetDMPFVPPFVInterval(0x30);
		}
	}

	return bRet;
}

BOOL MEMC_LibSetInputFrameRate(MEMC_INPUT_FRAMERATE emifr)
{
	BOOL bRet = TRUE;
	_PQL_Command Command;

	if(gstAppData.stModeData.enInputFrameRate != emifr)
	{
		Mid_CRTC_SetN2M(emifr,(OUTPUT_FRAMERATE)gstAppData.stModeData.enOutputFrameRate,
						(INPUT_FORMAT)gstAppData.stModeData.enInputFormat,
						(OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);
	}
	else
	{
		bRet = FALSE;
	}

	if(gstAppData.stModeData.enInputFrameRate != emifr)
	{
		gstAppData.stModeData.enInputFrameRate = emifr;
		LogPrintf(DBG_MSG, "MEMC Lib set input frame rate =  %d\r\n", emifr);
		Command._input_frameRate = (PQL_INPUT_FRAME_RATE)emifr;
		PQL_Command(PQL_CMD_INPUT_FRAME_RATE, &Command);
	}

	return bRet;

}

BOOL MEMC_LibSetOutputFrameRate(MEMC_OUTPUT_FRAMERATE emofr)
{	BOOL bRet = TRUE;
	_PQL_Command Command;

	if(gstAppData.stModeData.enOutputFrameRate != emofr)
	{
		Mid_CRTC_SetN2M((INPUT_FRAMERATE)gstAppData.stModeData.enInputFrameRate, emofr,
						(INPUT_FORMAT)gstAppData.stModeData.enInputFormat,
						(OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);
	}
	else
	{
		bRet = FALSE;
	}
	if(gstAppData.stModeData.enOutputFrameRate != emofr)
	{
		gstAppData.stModeData.enOutputFrameRate = emofr;
		LogPrintf(DBG_MSG, "MEMC Lib set output frame rate =  %d\r\n", emofr);
		MEMC_LibApplyPanelParameters(gstAppData.stModeData.enOutputFrameRate);
		Command._output_frameRate = (PQL_OUTPUT_FRAME_RATE)emofr;
		PQL_Command(PQL_CMD_OUTPUT_FRAME_RATE, &Command);

		if((gstAppData.stModeData.enOutputFrameRate == OUTPUT_50HZ) ||
			(gstAppData.stModeData.enOutputFrameRate == OUTPUT_60HZ))
		{
#ifndef REAL_CHIP	// FPGA
			Mid_Mode_SetTOPA2PortEnable(TRUE);
#endif
			Mid_Mode_SetMEWorkMode(0);	// 1:2
			Mid_Mode_SetPPFVIDX(0, (OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);
			Mid_Mode_SetDMPFVPPFVInterval(0x60);
		}
		else
		{
#ifndef REAL_CHIP	// FPGA
			Mid_Mode_SetTOPA2PortEnable(FALSE);
#endif
			Mid_Mode_SetMEWorkMode(1);	// 1:1
			Mid_Mode_SetPPFVIDX(1, (OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);
			Mid_Mode_SetDMPFVPPFVInterval(0x30);
		}
	}

	return bRet;

}


/**
 * @brief This function get input/output frame rate.
 * @param [out] 	pemifr 	return current input frame rate.
 * @param [out] 	pemofr 	return current output frame rate.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL MEMC_LibGetInOutFrameRate(MEMC_INPUT_FRAMERATE *pemifr, MEMC_OUTPUT_FRAMERATE *pemofr)
{
	if (pemifr == NULL || pemofr == NULL)
	{
		return FALSE;
	}

	*pemifr = gstAppData.stModeData.enInputFrameRate;
	*pemofr = gstAppData.stModeData.enOutputFrameRate;
	return TRUE;
}

/**
 * @brief This function set vertical flip.
 * @param [in] bVflip 		enable or disable vflip.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL MEMC_LibSetVflip(BOOL bVflip)
{
	if(gstAppData.stModeData.bVflip != bVflip)
	{
		gstAppData.stModeData.bVflip = bVflip;
#if 0
		Mid_DM_SetKMEEngineEnable(FALSE,
								  (INOUT_MODE)gstAppData.stModeData.enInOutMode,
								  (INPUT_FORMAT)gstAppData.stModeData.enInputFormat,
								  (OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);
		Mid_DM_SetKMVEngineEnable(FALSE);
		Mid_DM_SetKMCEngineEnable(FALSE);

		Mid_DM_SetKMEEndAddress(&gstMEDMAddr);
		Mid_DM_SetKMVEndAddress(&gstMVDMAddr);
		Mid_DM_SetKMCEndAddress(&gstMCDMAddr);

		Mid_DM_SetKMEEngineEnable(TRUE,
								  (INOUT_MODE)gstAppData.stModeData.enInOutMode,
								  (INPUT_FORMAT)gstAppData.stModeData.enInputFormat,
								  (OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);
		Mid_DM_SetKMVEngineEnable(TRUE);
		Mid_DM_SetKMCEngineEnable(TRUE);
#endif
		Mid_Mode_LastLineEnable(gstAppData.stModeData.bVflip,
								(INPUT_FORMAT)gstAppData.stModeData.enInputFormat,
								(OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);
		Mid_Mode_SetVFlip(gstAppData.stModeData.bVflip, (OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 * @brief This function get Vflip status.
 * @retval TRUE			vflip is enable
 * @retval FALSE		vflip is disable
*/
BOOL MEMC_LibGetVflip(VOID)
{
	return (gstAppData.stModeData.bVflip);
}

/**
 * @brief This function set demo window Enable
 * @param [in] ubyWinID		demo window ID(range 0~7)
 * @param [in] bEnable		enable or disable the demo window
 * @retval TRUE				success
 * @retval FALSE			fail
*/
BOOL MEMC_LibSetDemoWindowEnable(UBYTE ubyWinID, BOOL bEnable)
{
	return (Mid_MISC_SetDemoWindowEnable(ubyWinID, bEnable));
}

/**
 * @brief This function get demo window Enable
 * @param [in] ubyWinID		demo window ID(range 0~7)
 * @retval TRUE				The demo window is enabled
 * @retval FALSE			The demo window is disabled
*/
BOOL MEMC_LibGetDemoWindowEnable(UBYTE ubyWinID)
{
	return(Mid_MISC_GetDemoWindowEnable(ubyWinID));
}

/**
 * @brief This function set demo window mode
 * @param [in] bMode		demo window mode
 * 							FALSE: inside MEMC OFF
 * 							TRUE: outside MEMC OFF
*/
VOID MEMC_LibSetDemoWindowMode(BOOL bMode)
{
	Mid_MISC_SetDemoWindowMode(bMode);
}

/**
 * @brief This function get demo window mode
 * @retval FALSE			inside MEMC OFF
 * @retval TRUE				outside MEMC OFF
*/
BOOL MEMC_LibGetDemoWindowMode(VOID)
{
	return(Mid_MISC_GetDemoWindowMode());
}

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
BOOL MEMC_LibSetDemoWindowSettings(UBYTE ubyWinID, UINT32 u32Left, UINT32 u32Right, UINT32 u32Top, UINT32 u32Bottom)
{
	return Mid_MISC_SetDemoWindowSettings(ubyWinID, u32Left, u32Right, u32Top, u32Bottom);
}

/**
 * @brief This function get demo window settings
 * @param [in] ubyWinID			range 0~7
 * @param [out] *pu32Left		position left
 * @param [out] *pu32Right		position right
 * @param [out] *pu32Top 		position top
 * @param [out] *pu32Bottom 	position bottom
*/
VOID MEMC_LibGetDemoWindowSettings(UBYTE ubyWinID, UINT32 *pu32Left, UINT32 *pu32Right, UINT32 *pu32Top, UINT32 *pu32Bottom)
{
	Mid_MISC_GetDemoWindowSettings(ubyWinID, pu32Left, pu32Right, pu32Top, pu32Bottom);
}

/**
 * @brief This function set MEMC deblur level, when MEMC mode is user mode.
 * @param [in] uiLevel 		Specify memc deblur level (0~16).
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL MEMC_LibSetMEMCDeblurLevel(UINT32 uiLevel)
{
	if(gstAppData.stMEMCData.uiDeblurLevel != uiLevel)
	{
		if(gstAppData.stMEMCData.enMemcMode == MEMC_USER)
		{
			//LogPrintf(DBG_MSG, "MEMC lib set deblur level = %d\r\n", uiLevel);
			gstAppData.stMEMCData.uiDeblurLevel = uiLevel;
			return (Mid_MEMC_SetMEMCDeblurLevel((UINT16)gstAppData.stMEMCData.uiDeblurLevel));
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

/**
 * @brief This function get MEMC deblur level.
 * @return Return 		MEMC deblur level currently set.
*/
UINT32 MEMC_LibGetMEMCDeblurLevel(VOID)
{
	return gstAppData.stMEMCData.uiDeblurLevel;
}

/**
* @brief This function set MEMC dejudder level, when MEMC mode is user mode.
 * @param [in] uiLevel		Specify memc dejudder level (0~16).
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL MEMC_LibSetMEMCDejudderLevel(UINT32 uiLevel)
{
	if(gstAppData.stMEMCData.uiDejudderLevel != uiLevel)
	{
		if(gstAppData.stMEMCData.enMemcMode == MEMC_USER)
		{
			//LogPrintf(DBG_MSG, "MEMC lib set dejudder level = %d\r\n", uiLevel);
			gstAppData.stMEMCData.uiDejudderLevel = uiLevel;
			return (Mid_MEMC_SetMEMCDejudderLevel((UINT16)gstAppData.stMEMCData.uiDejudderLevel));
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

/**
 * @brief This function get MEMC dejudder level.
 * @return Return 		MEMC dejudder level currently set.
*/
UINT32 MEMC_LibGetMEMCDejudderLevel(VOID)
{
	return (gstAppData.stMEMCData.uiDejudderLevel);
}

/**
 * @brief This function reset MEMC mode.
 * @for STR init
*/
VOID MEMC_LibResetMEMCMode(VOID)
{
	gstAppData.stMEMCData.enMemcMode = MEMC_MODE_MAX;
	LogPrintf(DBG_MSG, "memc mode reset to %d!!!\r\n", gstAppData.stMEMCData.enMemcMode);
}
/**
* @brief This function set MEMC fallback level, when MEMC mode is user mode.
 * @param [in] uiLevel		Specify memc fallback level (0~255).
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL MEMC_LibSetMEMCFallbackLevel(UINT32 uiLevel)
{
	if(gstAppData.stMEMCData.uiFallbackLevel != uiLevel)
	{
		if(gstAppData.stMEMCData.enMemcMode == MEMC_USER)
		{
			LogPrintf(DBG_MSG, "MEMC lib set fallback level = %d\r\n", uiLevel);
			gstAppData.stMEMCData.uiFallbackLevel = uiLevel;
			return (Mid_MEMC_SetMEMCFBLevel((UINT16)gstAppData.stMEMCData.uiFallbackLevel));
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

/**
 * @brief This function get MEMC fallback level.
 * @return Return 		MEMC fallback level currently set.
*/
UINT32 MEMC_LibGetMEMCFallbackLevel(VOID)
{
	return (gstAppData.stMEMCData.uiFallbackLevel);
}

/**
 * @brief This function set MEMC mode.
 * @param [in] emm 			Specify MEMC mode.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL MEMC_LibSetMEMCMode(MEMC_MODE emm)
{
	_PQL_Command PQLCommand;

	if(gstAppData.stMEMCData.enMemcMode != emm)
	{
		LogPrintf(DBG_MSG, "MEMC lib set memc mode = %d\r\n", emm);
		gstAppData.stMEMCData.enMemcMode = emm;

		PQLCommand.u3_memcMode = emm;
		PQL_Command(PQL_CMD_MEMC_MODE, &PQLCommand);

		if(emm == MEMC_SMOOTH)
		{
			gstAppData.stMEMCData.uiDejudderLevel = 128;
			gstAppData.stMEMCData.uiDeblurLevel = 128;
			gstAppData.stMEMCData.uiFallbackLevel = 80;
		}
		else if(emm == MEMC_CLEAR)
		{
			gstAppData.stMEMCData.uiDejudderLevel = 94;
			gstAppData.stMEMCData.uiDeblurLevel = 94;
			gstAppData.stMEMCData.uiFallbackLevel = 48;
		}
		else if(emm == MEMC_NORMAL)
		{
			gstAppData.stMEMCData.uiDejudderLevel = 16;
			gstAppData.stMEMCData.uiDeblurLevel = 8;
			gstAppData.stMEMCData.uiFallbackLevel = 64;
		}
		else if(emm == MEMC_OFF)
		{
			gstAppData.stMEMCData.uiDejudderLevel = 0;
			gstAppData.stMEMCData.uiDeblurLevel = 0;
			gstAppData.stMEMCData.uiFallbackLevel = 0;
		}
		else if(emm == MEMC_USER)
		{
		}
		else
		{
			return FALSE;
		}

		if(emm != MEMC_USER)
		{
			Mid_MEMC_SetMEMCDejudderLevel((UINT16)gstAppData.stMEMCData.uiDejudderLevel);
			Mid_MEMC_SetMEMCDeblurLevel((UINT16)gstAppData.stMEMCData.uiDeblurLevel);
			Mid_MEMC_SetMEMCFBLevel((UINT16)gstAppData.stMEMCData.uiFallbackLevel);
		}

		if(emm == MEMC_CLEAR || emm == MEMC_USER)
			PQLCommand.u1_osd_force_mode = 1;
		else
			PQLCommand.u1_osd_force_mode = 0;
		PQL_Command(PQL_CMD_OSD_FORCE_MODE, &PQLCommand);

		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 * @brief This function get MEMC mode setting.
 * @retval MEMC_MODE enum type currently set.
*/
MEMC_MODE MEMC_LibGetMEMCMode(VOID)
{
	return (gstAppData.stMEMCData.enMemcMode);
}

/**
 * @brief This function set Cinema mode.
 * @param [in] emm 		Specify CinemaMode(0:disable;1:enable).
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL MEMC_LibSetCinemaMode(UBYTE bEnable)
{
	LogPrintf(DBG_MSG, "[Cinema]in = %d, gst = %d\r\n", bEnable, gstAppData.bCinemaMode);

	if(gstAppData.bCinemaMode != bEnable || gstAppData.bCinemaModeUpdateFR != gstAppData.stModeData.enInputFrameRate)
	{
		gstAppData.bCinemaMode = bEnable;
		gstAppData.bCinemaModeUpdateFR = gstAppData.stModeData.enInputFrameRate;
		Mid_MEMC_SetPullDownMode((INPUT_FRAMERATE)gstAppData.stModeData.enInputFrameRate, \
								(OUTPUT_FRAMERATE)gstAppData.stModeData.enOutputFrameRate, \
								(UBYTE)(gstAppData.stMEMCData.enMemcMode != MEMC_OFF && gstAppData.stMEMCData.enMemcMode != MEMC_MODE_MAX), \
								(UBYTE)gstAppData.bCinemaMode);

		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 * @brief This function get CinemaMode setting.
 * @retval TRUE 			Enable
 * @retval FALSE			Disable
*/
UBYTE MEMC_LibGetCinemaMode(VOID)
{
	return (gstAppData.bCinemaMode);
}

/**
 * @brief This function set MEMC frame repeat mode.
 * @param [in] bEnable 		true for enable, false for disalbe.
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL MEMC_LibSetMEMCFrameRepeatEnable(BOOL bEnable, BOOL bForce)
{
	LogPrintf(DBG_MSG, "[RepeatMode]memcM=%d,bEn=%d, bF=%d (%d,%d)\r\n", gstAppData.stMEMCData.enMemcMode, bEnable, bForce,
		gstAppData.stMEMCData.bFrameRepeat, gstAppData.stMEMCData.bFrameRepeat_QRPC);

	/*Force to set target mode(bEnable) while current flow is changing status*/
	if(gstAppData.stMEMCData.bFrameRepeat != gstAppData.stMEMCData.bFrameRepeat_QRPC)
        	bForce = TRUE;

	if(bForce)// force repeatmode
	{
		gstAppData.stMEMCData.bFrameRepeat = (!bEnable);
		gstAppData.stMEMCData.bFrameRepeat_QRPC = bEnable;

		return TRUE;
	}

	gstAppData.stMEMCData.bFrameRepeat_QRPC = gstAppData.stMEMCData.bFrameRepeat;

	if(gstAppData.stMEMCData.bFrameRepeat != bEnable)
	{
		gstAppData.stMEMCData.bFrameRepeat_QRPC = bEnable;

		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL MEMC_LibSetMEMC_PCModeEnable(BOOL bEnable)
{
	gstAppData.stMEMCData.bPCMode_QRPC = gstAppData.stMEMCData.bPCMode;

	if(gstAppData.stMEMCData.bPCMode!= bEnable)
	{
		gstAppData.stMEMCData.bPCMode_QRPC = bEnable;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL MEMC_LibSetMEMCLowDelayModeEnable(BOOL bEnable)
{
	gstAppData.stMEMCData.bLowDelay_QRPC = gstAppData.stMEMCData.bLowDelay;

	if(gstAppData.stMEMCData.bLowDelay!= bEnable)
	{
		gstAppData.stMEMCData.bLowDelay_QRPC = bEnable;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 * @brief This function get MEMC frame repeat mode.
 * @retval TRUE 			Enable
 * @retval FALSE			Disable
*/
BOOL MEMC_LibGetMEMCFrameRepeatEnable(VOID)
{
	return (gstAppData.stMEMCData.bFrameRepeat);
}

BOOL MEMC_LibGetMEMCLowDelayModeEnable(VOID)
{
	return (gstAppData.stMEMCData.bLowDelay);
}

BOOL MEMC_LibGetMEMC_PCModeEnable(VOID)
{
	return (gstAppData.stMEMCData.bPCMode);
}

/**
 * @brief This function returns current library version info. The version format is like "V0.0.1 SVN: 1232 2015.01.30 16:01:19".
 * @param [out] pBuf		Buffer to save version info.
 * @param [in] iLen			Buffer length(iLen <= 128 bytes)
 * @param [in] enModID		Module ID want to get version
*/
#define VER_MAX_LENGTH	128
VOID MEMC_LibGetVersionInfo(SCHAR *pBuf, UINT32 uiLen, MODULE_ID enModID)
{
	UINT32	uiRealLen = 0;
	SCHAR scBuf[VER_MAX_LENGTH];
	_PQL_Request PQL_Req;
	UINT32 i = 0;
	/* check input parameter */
	if ((pBuf != NULL) && (uiLen > 0) && (uiLen <= VER_MAX_LENGTH))
	{
		switch (enModID)
		{
			case MODULE_ID_APP:
				for(i = 0; i < VER_MAX_LENGTH; i++)
				{
					scBuf[i] = ' ';
				}

				// get real length to avoid buffer overflow
				uiRealLen = kw_strlen(APP_VERSION) + kw_strlen(SVNVER) + 1;
				uiLen = uiRealLen > uiLen ? uiLen : uiRealLen;

				// copy string
				kw_strcpy(scBuf, APP_VERSION, kw_strlen(APP_VERSION), 0);
				kw_strcat(scBuf, VER_MAX_LENGTH, " ");
				kw_strcat(scBuf, VER_MAX_LENGTH, SVNVER);
				for(i = 0; i < uiLen; i++)
				{
					*pBuf = scBuf[i];
					pBuf++;
				}
				//LogPrintf(DBG_MSG,"pBuf_APP = %s\r\n", *pBuf);
				break;

			case MODULE_ID_FRC:
				PQL_Request(PQL_VER, &PQL_Req);

				// get real length to avoid buffer overflow
				uiRealLen = kw_strlen(PQL_Req._Version);
				uiLen = uiRealLen > uiLen ? uiLen : uiRealLen;

				for(i = 0; i < uiLen; i++)
				{
					*pBuf = PQL_Req._Version[i];
					pBuf++;
				}
				//LogPrintf(DBG_MSG,"pBuf_FRC = %s\r\n", *pBuf);
				break;

			default:
				break;
		}
	}
}

/**
 * @brief This function set MEMC output mute or unmute.
 *			This function is mostly used before/after signal change to avoid mess screen.
 * @param [in] bMute		Input mute state want to set
 * @retval VOID
*/
VOID MEMC_LibSetMute(BOOL bMute)
{
	if(gstAppData.stSysData.bMute != bMute)
	{
		gstAppData.stSysData.bMute = bMute;
		Mid_Sys_SetMute(bMute);
	}
}

/**
 * @brief This function get MEMC output mute state.
 * @retval TRUE 		indicates currently is mute state
 * @retval FALSE		indicates currently is unmute state
*/
BOOL MEMC_LibGetMute(VOID)
{
	return gstAppData.stSysData.bMute;
}

/**
 * @brief This function set MEMC output mute color
 * @param [in] bREnable		color r enable or not
 * @param [in] bGEnable		color g enable or not
 * @param [in] bBEnable		color b enable or not
*/
VOID MEMC_LibSetMuteColor(BOOL bREnable, BOOL bGEnable, BOOL bBEnable)
{
	Mid_Sys_SetMuteColor(bREnable, bGEnable, bBEnable);
}

/**
 * @brief This function set MEMC output LR inverse.
 * @param [in] bEnable		output LR inverse or not
 * @retval VOID
*/
VOID MEMC_LibSetOutputLRInverse(BOOL bEnable)
{
	_PQL_Command Command;

	if(gstAppData.stModeData.enOutputFormat == OUTPUT_FORMAT_3D_PR)
	{
		Mid_MISC_SetPROutLRInverse(bEnable);
	}
	else if(gstAppData.stModeData.enOutputFormat == OUTPUT_FORMAT_3D_SG)
	{
		//Mid_MISC_SetSGOutLRInverse(bEnable);
		Command.u1_LR_swap = (UBYTE)bEnable;
		PQL_Command(PQL_CMD_LR_SWAP, &Command);
	}
}

/**
 * @brief This function set MEMC slave mode enable
 * @param [in] bEnable		Slave mode enable or not
 * @retval VOID
*/
VOID MEMC_LibSetSlaveModeEnable(BOOL bEnable)
{
	Mid_CRTC_SetSlaveModeEnable(bEnable);
}

/**
 * @brief This function set MEMC RIM window. The rim window defines out black region while on film scene.
 * @param [in] uiTop		rim window position left
 * @param [in] uiBottom	rim window position right
 * @param [in] uiLeft 		rim window position top
 * @param [in]u iRight	rim window position bottom
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail
*/
BOOL MEMC_LibSetRimWindow(UINT32 uiTop, UINT32 uiBottom, UINT32 uiLeft, UINT32 uiRight)
{
	if (uiTop != gstAppData.stMEMCData.uiTop || uiBottom != gstAppData.stMEMCData.uiBottom ||
		uiLeft != gstAppData.stMEMCData.uiLeft || uiRight != gstAppData.stMEMCData.uiRight)
	{
		gstAppData.stMEMCData.uiTop = uiTop;
		gstAppData.stMEMCData.uiBottom = uiBottom;
		gstAppData.stMEMCData.uiLeft = uiLeft;
		gstAppData.stMEMCData.uiRight = uiRight;
		return (Mid_MEMC_SetRimWindow(uiTop, uiBottom, uiLeft, uiRight));
	}
	else
	{
		return FALSE;
	}
}

/**
 * @brief This function get MEMC RIM window.
 * @param [out] *puiTop			return rim position left
 * @param [out] *puiBottom		return rim position right
 * @param [out] *puiLeft 		return rim  position top
 * @param [out] *puiRight		return rim position bottom
 * @retval TRUE 				indicates success
 * @retval FALSE				indicates fail
*/
BOOL MEMC_LibGetRimWindow(UINT32 *puiTop, UINT32 *puiBottom, UINT32 *puiLeft, UINT32 *puiRight)
{
	BOOL	bRet = FALSE;

	if (puiTop != NULL && puiBottom != NULL && puiLeft != NULL && puiRight != NULL)
	{
		*puiTop = gstAppData.stMEMCData.uiTop;
		*puiBottom = gstAppData.stMEMCData.uiBottom;
		*puiLeft = gstAppData.stMEMCData.uiLeft;
		*puiRight= gstAppData.stMEMCData.uiRight;
	}

	return bRet;
}

/**
 * @brief This function set panel parameters.
 * @param [in] stPanelPara 		structure for panel parameters
 * @retval TRUE 				indicates success
 * @retval FALSE				indicates fail
*/
BOOL MEMC_LibSetPanelParameters(PANEL_PARA_ST *pstPanelPara)
{
	UINT16 u16Idx = 0;
	for(u16Idx = 0; u16Idx < OUTPUT_FRAME_MAX; u16Idx++)
	{
		if(((gstPanelData.stPanelParamertes[u16Idx].enOutputFrameRate != OUTPUT_FRAMERATE_INVALID) &&
		   (gstPanelData.stPanelParamertes[u16Idx].enOutputFrameRate == pstPanelPara->enOutputFrameRate)) ||
		   (gstPanelData.stPanelParamertes[u16Idx].enOutputFrameRate == OUTPUT_FRAMERATE_INVALID))
		{
			LogPrintf(DBG_MSG, "MEMC lib set panel parameters = %d\r\n", (UINT32)pstPanelPara->enOutputFrameRate);

			gstPanelData.stPanelParamertes[u16Idx].enOutputFrameRate = (OUTPUT_FRAMERATE)pstPanelPara->enOutputFrameRate;
			gstPanelData.stPanelParamertes[u16Idx].u32Htotal = pstPanelPara->u32Htotal;
			gstPanelData.stPanelParamertes[u16Idx].u32HtotalMax = pstPanelPara->u32HtotalMax;
			gstPanelData.stPanelParamertes[u16Idx].u32HtotalMin = pstPanelPara->u32HtotalMin;
			gstPanelData.stPanelParamertes[u16Idx].u32Hactive = pstPanelPara->u32Hactive;
			gstPanelData.stPanelParamertes[u16Idx].u32HSWidth = pstPanelPara->u32HSWidth;
			gstPanelData.stPanelParamertes[u16Idx].u32HSBPorch = pstPanelPara->u32HSBPorch;
			gstPanelData.stPanelParamertes[u16Idx].u32Vtotal = pstPanelPara->u32Vtotal;
			gstPanelData.stPanelParamertes[u16Idx].u32VtotalMax = pstPanelPara->u32VtotalMax;
			gstPanelData.stPanelParamertes[u16Idx].u32VtotalMin = pstPanelPara->u32VtotalMin;
			gstPanelData.stPanelParamertes[u16Idx].u32Vactive = pstPanelPara->u32Vactive;
			gstPanelData.stPanelParamertes[u16Idx].u32VSWidth = pstPanelPara->u32VSWidth;
			gstPanelData.stPanelParamertes[u16Idx].u32VSBPorch = pstPanelPara->u32VSBPorch;

			return TRUE;
		}
	}
	LogPrintf(DBG_ERROR, "MEMC lib set panel parameters fail!\r\n");
	return FALSE;
}

/**
 * @brief This function get panel parameters.
 * @param [in] enOutputFrameRate		which panel parameters will you want to get
 * @param [out] pstPanelPara 			structure for panel parameters
 * @retval TRUE 						indicates success
 * @retval FALSE						indicates fail
*/
BOOL MEMC_LibGetPanelParameters(PANEL_PARA_ST *pstPanelPara, MEMC_OUTPUT_FRAMERATE enOutputFrameRate)
{
	UINT16 u16Idx = 0;
	for(u16Idx = 0; u16Idx < OUTPUT_FRAMERATE_MAX; u16Idx++)
	{
		if(gstPanelData.stPanelParamertes[u16Idx].enOutputFrameRate == enOutputFrameRate)
		{
			LogPrintf(DBG_MSG, "MEMC lib get panel parameters = %d\r\n", (UINT32)gstPanelData.stPanelParamertes[u16Idx].enOutputFrameRate);

			pstPanelPara->enOutputFrameRate = (MEMC_OUTPUT_FRAMERATE)gstPanelData.stPanelParamertes[u16Idx].enOutputFrameRate;
			pstPanelPara->u32Htotal = gstPanelData.stPanelParamertes[u16Idx].u32Htotal;
			pstPanelPara->u32HtotalMax = gstPanelData.stPanelParamertes[u16Idx].u32HtotalMax;
			pstPanelPara->u32HtotalMin = gstPanelData.stPanelParamertes[u16Idx].u32HtotalMin;
			pstPanelPara->u32Hactive = gstPanelData.stPanelParamertes[u16Idx].u32Hactive;
			pstPanelPara->u32HSWidth = gstPanelData.stPanelParamertes[u16Idx].u32HSWidth;
			pstPanelPara->u32HSBPorch = gstPanelData.stPanelParamertes[u16Idx].u32HSBPorch;
			pstPanelPara->u32Vtotal = gstPanelData.stPanelParamertes[u16Idx].u32Vtotal;
			pstPanelPara->u32VtotalMax = gstPanelData.stPanelParamertes[u16Idx].u32VtotalMax;
			pstPanelPara->u32VtotalMin = gstPanelData.stPanelParamertes[u16Idx].u32VtotalMin;
			pstPanelPara->u32Vactive = gstPanelData.stPanelParamertes[u16Idx].u32Vactive;
			pstPanelPara->u32VSWidth = gstPanelData.stPanelParamertes[u16Idx].u32VSWidth;
			pstPanelPara->u32VSBPorch = gstPanelData.stPanelParamertes[u16Idx].u32VSBPorch;

			return TRUE;
		}
	}
	LogPrintf(DBG_ERROR, "MEMC lib get panel parameters fail!\r\n");
	return FALSE;
}

/**
 * @brief This function get current panel parameters.
 * @param [out] pstPanelPara 		structure for panel parameters
 * @retval TRUE 					indicates success
 * @retval FALSE					indicates fail
*/
BOOL MEMC_LibGetCurrentPanelParameters(PANEL_PARA_ST *pstPanelPara)
{
	UINT16 u16Idx = 0;
	for(u16Idx = 0; u16Idx < OUTPUT_FRAMERATE_MAX; u16Idx++)
	{
		if(gstPanelData.stPanelParamertes[u16Idx].enOutputFrameRate == (OUTPUT_FRAMERATE)gstAppData.stModeData.enOutputFrameRate)
		{
			LogPrintf(DBG_MSG, "MEMC lib get current panel parameters = %d\r\n", (UINT32)gstPanelData.stPanelParamertes[u16Idx].enOutputFrameRate);

			pstPanelPara->enOutputFrameRate = (MEMC_OUTPUT_FRAMERATE)gstPanelData.stPanelParamertes[u16Idx].enOutputFrameRate;
			pstPanelPara->u32Htotal = gstPanelData.stPanelParamertes[u16Idx].u32Htotal;
			pstPanelPara->u32HtotalMax = gstPanelData.stPanelParamertes[u16Idx].u32HtotalMax;
			pstPanelPara->u32HtotalMin = gstPanelData.stPanelParamertes[u16Idx].u32HtotalMin;
			pstPanelPara->u32Hactive = gstPanelData.stPanelParamertes[u16Idx].u32Hactive;
			pstPanelPara->u32HSWidth = gstPanelData.stPanelParamertes[u16Idx].u32HSWidth;
			pstPanelPara->u32HSBPorch = gstPanelData.stPanelParamertes[u16Idx].u32HSBPorch;
			pstPanelPara->u32Vtotal = gstPanelData.stPanelParamertes[u16Idx].u32Vtotal;
			pstPanelPara->u32VtotalMax = gstPanelData.stPanelParamertes[u16Idx].u32VtotalMax;
			pstPanelPara->u32VtotalMin = gstPanelData.stPanelParamertes[u16Idx].u32VtotalMin;
			pstPanelPara->u32Vactive = gstPanelData.stPanelParamertes[u16Idx].u32Vactive;
			pstPanelPara->u32VSWidth = gstPanelData.stPanelParamertes[u16Idx].u32VSWidth;
			pstPanelPara->u32VSBPorch = gstPanelData.stPanelParamertes[u16Idx].u32VSBPorch;

			return TRUE;
		}
	}
	LogPrintf(DBG_ERROR, "MEMC lib get current panel parameters fail!\r\n");
	return FALSE;
}

/**
 * @brief This function apply panel parameters.
 * @param [in] enOutputFrameRate		which panel parameters will you want to apply
 * @retval TRUE 						indicates success
 * @retval FALSE						indicates fail
*/
BOOL MEMC_LibApplyPanelParameters(MEMC_OUTPUT_FRAMERATE enOutputFrameRate)
{
	PANEL_PARA_ST stPanelPara;
	PANEL_PARAMETERS_ST stPanelParamertes;
	if(MEMC_LibGetPanelParameters(&stPanelPara, enOutputFrameRate))
	{
		LogPrintf(DBG_MSG, "MEMC lib apply panel parameters = %d\r\n", (UINT32)stPanelPara.enOutputFrameRate);

		stPanelParamertes.enOutputFrameRate = (OUTPUT_FRAMERATE)stPanelPara.enOutputFrameRate;
		stPanelParamertes.u32Htotal = stPanelPara.u32Htotal;
		stPanelParamertes.u32HtotalMax = stPanelPara.u32HtotalMax;
		stPanelParamertes.u32HtotalMin = stPanelPara.u32HtotalMin;
		stPanelParamertes.u32Hactive = stPanelPara.u32Hactive;
		stPanelParamertes.u32HSWidth = stPanelPara.u32HSWidth;
		stPanelParamertes.u32HSBPorch = stPanelPara.u32HSBPorch;
		stPanelParamertes.u32Vtotal = stPanelPara.u32Vtotal;
		stPanelParamertes.u32VtotalMax = stPanelPara.u32VtotalMax;
		stPanelParamertes.u32VtotalMin = stPanelPara.u32VtotalMin;
		stPanelParamertes.u32Vactive = stPanelPara.u32Vactive;
		stPanelParamertes.u32VSWidth = stPanelPara.u32VSWidth;
		stPanelParamertes.u32VSBPorch = stPanelPara.u32VSBPorch;
		Mid_CRTC_SetFRCTiming((OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat, stPanelParamertes);
		Mid_CRTC_SetPanelTiming((OUTPUT_FORMAT)gstAppData.stModeData.enOutputFormat, stPanelParamertes);
		return TRUE;
	}
	else
	{
		LogPrintf(DBG_ERROR, "MEMC lib apply panel parameters failed!\r\n");
		return FALSE;
	}
}

/**
 * @brief This function get MEMC library error code.
 * @return  return 	error code.
*/
UINT32 MEMC_LibGetErrorCode(VOID)
{
	return gstAppData.iErrCode;
}

/**
 * @brief This function set MEMC debug level.
 * @param [in] iLevel Specify library debug level. (range: 1~3)
 *			1: show all print messages.
 *			2: show warning and error messages.
 *			3: show error messages.
 * @retval TRUE 						indicates success
 * @retval FALSE						indicates fail
*/
BOOL MEMC_LibSetDebugLevel(UINT32 u32Level)
{
	if(u32Level != MEMC_LibGetDebugLevel())
	{
		COM_SetDebugLevel(u32Level);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 * @brief This function get MEMC current debug level.
 * @return Return 	library current debug level.
*/
UINT32 MEMC_LibGetDebugLevel(VOID)
{
	return COM_GetDebugLevel();
}

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
VOID MEMC_LibSetInputDataMapping(UINT32 u32Data_Mapping)
{
	Mid_MISC_SetInputDataMapping(u32Data_Mapping);
}

/**
 * @brief This function get input data mapping
 * @param [in] VOID
 * @retval u32Data_Mapping 		data mapping index(range: 0~5)
*/
UINT32 MEMC_LibGetInputDataMapping(VOID)
{
	return (Mid_MISC_GetInputDataMapping());
}

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
VOID MEMC_LibSetNRDataMapping(UINT32 u32Data_Mapping)
{
	Mid_MISC_SetNRDataMapping(u32Data_Mapping);
}

/**
 * @brief This function get nr data mapping
 * @param [in] VOID
 * @retval data mapping 		data mapping index(range: 0~5)
*/
UINT32 MEMC_LibGetNRDataMapping(VOID)
{
	return (Mid_MISC_GetNRDataMapping());
}

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
VOID MEMC_LibSetOutputDataMapping(UINT32 u32Data_Mapping)
{
	Mid_MISC_SetOutputDataMapping(u32Data_Mapping);
}

/**
 * @brief This function get output data mapping
 * @param [in] VOID
 * @retval data mapping 		data mapping index(range: 0~5)
*/
UINT32 MEMC_LibGetOutputDataMapping(VOID)
{
	return (Mid_MISC_GetOutputDataMapping());
}

/**
 * @brief This function set black insert line mode enable
 * @param [in] bEnable		enable or disable black insert line mode
 * @retval VOID
*/
VOID MEMC_LibSetBlackInsertLineModeEnable(BOOL bEnable)
{
	Mid_MISC_SetBlackInsertLineModeEnable(bEnable);
}

/**
 * @brief This function set black insert line mode pattern number
 * @param [in] u32PatternNum  	black insert line mode  pattern number(range: 0~15 stand for 1~16)
 * @retval VOID
*/
VOID MEMC_LibSetBlackInsertLineModePatternNum(UINT32 u32PatternNum)
{
	Mid_MISC_SetBlackInsertLineModePatternNum(u32PatternNum);
}

/**
 * @brief This function set black insert line mode L pattern
 * @param [in] u32Pattern		black insert line mode L pattern
 *								(if pattern number = 2, range: 0x0~0x3)
 *                              (if pattern number = 4, range: 0x0~0xF)
 *                              (if pattern number = 8, range: 0x00~0xFF)
 *                              (if pattern number = 16, range: 0x00~0xFFFF)
 * @retval VOID
*/
VOID MEMC_LibSetBlackInsertLineModeLPattern(UINT32 u32Pattern)
{
	Mid_MISC_SetBlackInsertLineModeLPattern(u32Pattern);
}

/**
 * @brief This function set black insert line mode R pattern
 * @param [in] u32Pattern 		black insert line mode R pattern
 * 								(if pattern number = 2, range: 0x0~0x3)
 *                              (if pattern number = 4, range: 0x0~0xF)
 *                              (if pattern number = 8, range: 0x00~0xFF)
 *                              (if pattern number = 16, range: 0x00~0xFFFF)
 * @retval VOID
*/
VOID MEMC_LibSetBlackInsertLineModeRPattern(UINT32 u32Pattern)
{
	Mid_MISC_SetBlackInsertLineModeRPattern(u32Pattern);
}

/**
 * @brief This function set black insert frame mode enable
 * @param [in] bEnable			Enable or disable black insert frame mode
 * @retval VOID
*/
VOID MEMC_LibSetBlackInsertFrameModeEnable(BOOL bEnable)
{
	_PQL_Command Command;

	if(gstAppData.stModeData.enOutputFormat != OUTPUT_3D_SG)
	{
		return;
	}
	Command.u1_InsertBlack = (UBYTE)bEnable;
	PQL_Command(PQL_CMD_INSERT_BLACK, &Command);
	Mid_MISC_SetBlackInsertFrameModeEnable(bEnable);
}

#define SPLITBAR_WIDTH	14	// make sure even
/**
 * @brief This function set MEMC demo mode
 * @param [in] emMode			Specify MEMC demo mode
 * @retval TRUE 				indicates success
 * @retval FALSE				indicates fail
*/
BOOL MEMC_LibSetMEMCDemoMode(MEMC_DEMO_MODE emMode)
{
	if(gstAppData.stSysData.enDemoMode != emMode)
	{
		if(gstAppData.stModeData.enOutputRes == OUTPUT_1920X1080)
		{
			Mid_MISC_SetPostCursorPosition(959 - (SPLITBAR_WIDTH / 2), 1081);
			Mid_MISC_SetDemoWindowSettings(0, 0, 959, 0, 1079);
		}
		else if(gstAppData.stModeData.enOutputRes == OUTPUT_3840X2160)
		{
			Mid_MISC_SetPostCursorPosition(1919 - (SPLITBAR_WIDTH / 2), 2161);
			Mid_MISC_SetDemoWindowSettings(0, 0, 1919, 0, 2159);
		}
		else if(gstAppData.stModeData.enOutputRes == OUTPUT_3840X1080)
		{
			Mid_MISC_SetPostCursorPosition(1919 - (SPLITBAR_WIDTH / 2), 1081);
			Mid_MISC_SetDemoWindowSettings(0, 0, 1919, 0, 1079);
		}

		Mid_MISC_SetPostCursorWidth(SPLITBAR_WIDTH);
		Mid_MISC_SetPostCursorColor(0);
		Mid_MISC_SetPostCursorEnable((emMode == DEMO_MODE_OFF)?FALSE:TRUE);
		Mid_MISC_SetPostCursorShow((emMode == DEMO_MODE_OFF)?FALSE:TRUE);

		if(emMode == DEMO_MODE_LEFT)
		{
			Mid_MISC_SetDemoWindowMode(FALSE);
		}
		else if(emMode == DEMO_MODE_RIGHT)
		{
			Mid_MISC_SetDemoWindowMode(TRUE);
		}

		Mid_Mode_SetPTZeroType1((emMode == DEMO_MODE_OFF)?3:1);
		Mid_MISC_SetDemoWindowEnable(0, (emMode == DEMO_MODE_OFF)?FALSE:TRUE);

		gstAppData.stSysData.enDemoMode = emMode;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 * @brief This function set MEMC demo mode
 * @retval MEMC_DEMO_MODE enum type currently set.
*/
MEMC_DEMO_MODE MEMC_LibGetMEMCDemoMode(VOID)
{
	return gstAppData.stSysData.enDemoMode;
}

VOID MEMC_LibForcePhaseTableInit(VOID)
{
	PQL_PhaseTable_Init();
}

extern int PictureMode_flg;
VOID MEMC_LibGetScalerVIPInfo(VOID)
{
	_PQL_Info Info;
	MEMC_SCALER_VIP_INFO	curScalerVIPInfo;

#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
	curScalerVIPInfo = scalerVIP_Get_Info_fromScaler();
#else
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_system_info_structure_table == NULL || VIP_RPC_system_info_structure_table ==NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	curScalerVIPInfo.bHDR_Chg = (VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status == 3)? 1:0;
	curScalerVIPInfo.bSRC_VO = (VIP_system_info_structure_table->Input_src_Type == _SRC_VO)? 1:0;
	curScalerVIPInfo.mContrast = (Scaler_ChangeUINT16Endian(VIP_system_info_structure_table->OSD_Info.Contrast_Gain))& 0xffff;
	curScalerVIPInfo.mBrightness = (Scaler_ChangeUINT16Endian(VIP_system_info_structure_table->OSD_Info.Brightness_Gain)) & 0xffff;
	curScalerVIPInfo.source_type = (VIP_RPC_system_info_structure_table->VIP_source);
	curScalerVIPInfo.PictureMode_Chg = PictureMode_flg;
	if(PictureMode_flg == 1)
		PictureMode_flg = 0;
#endif

	if(curScalerVIPInfo.bSRC_VO != gstScalerVIPInfo.bSRC_VO)
	{
		gstScalerVIPInfo.bSRC_VO = curScalerVIPInfo.bSRC_VO;
		Info.u1_SRC_VO = curScalerVIPInfo.bSRC_VO;
		PQL_Info(PQL_INFO_SRC_VO, &Info);
	}

	if(curScalerVIPInfo.bHDR_Chg!= gstScalerVIPInfo.bHDR_Chg)
	{
		gstScalerVIPInfo.bHDR_Chg = curScalerVIPInfo.bHDR_Chg;
		Info.u1_HDR_Chg = curScalerVIPInfo.bHDR_Chg;
		PQL_Info(PQL_INFO_HDR_CHG, &Info);
	}

	if(curScalerVIPInfo.mBrightness!= gstScalerVIPInfo.mBrightness)
	{
		gstScalerVIPInfo.mBrightness = curScalerVIPInfo.mBrightness;
		Info.u16_mBrightness = curScalerVIPInfo.mBrightness;
		PQL_Info(PQL_INFO_BRIGHTNESS, &Info);

	}

	if(curScalerVIPInfo.mContrast!= gstScalerVIPInfo.mContrast)
	{
		gstScalerVIPInfo.mContrast = curScalerVIPInfo.mContrast;
		Info.u16_mContrast = curScalerVIPInfo.mContrast;
		PQL_Info(PQL_INFO_CONTRAST, &Info);

	}

#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	int mSpeed = 256;
	_RPC_clues* RPC_SmartPic_clue = NULL ;
	RPC_SmartPic_clue  = (_RPC_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_SMARTPIC_CLUS);
	if( RPC_SmartPic_clue==NULL){
		return;
	} else {

		mSpeed = RPC_SmartPic_clue->MEMC_VCPU_setting_info.vo_channel_speed;
		curScalerVIPInfo.mSpeed = (short)Scaler_ChangeUINT32Endian(mSpeed);
		if(curScalerVIPInfo.mSpeed!= gstScalerVIPInfo.mSpeed)
		{
			gstScalerVIPInfo.mSpeed = curScalerVIPInfo.mSpeed;
			Info.s16_mSpeed = curScalerVIPInfo.mSpeed;
		PQL_Info(PQL_INFO_SPEED, &Info);

		}

		int m_voseek = 0;
		m_voseek = RPC_SmartPic_clue->MEMC_VCPU_setting_info.m_VOSeek;
		curScalerVIPInfo.mVOSeek = m_voseek;
		if(curScalerVIPInfo.mVOSeek!= gstScalerVIPInfo.mVOSeek){
			gstScalerVIPInfo.mVOSeek = curScalerVIPInfo.mVOSeek;
			Info.u1_mVOSeek = curScalerVIPInfo.mVOSeek;
			PQL_Info(PQL_INFO_VOSEEK, &Info);
			//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 0, 7, gstScalerVIPInfo.mVOSeek);
		}

		int m_miracast = 0;
		m_miracast = RPC_SmartPic_clue->MEMC_VCPU_setting_info.m_MiraCast;
		curScalerVIPInfo.m_MiraCast = m_miracast;
		if(curScalerVIPInfo.m_MiraCast!= gstScalerVIPInfo.m_MiraCast){
			gstScalerVIPInfo.m_MiraCast = curScalerVIPInfo.m_MiraCast;
			Info.u1_mMiraCast= curScalerVIPInfo.m_MiraCast;
			PQL_Info(PQL_INFO_MIRACAST, &Info);
		}

	}

#else

	curScalerVIPInfo.mSpeed = VO_Get_ChannelSpeed();
	if(curScalerVIPInfo.mSpeed!= gstScalerVIPInfo.mSpeed)
	{
		gstScalerVIPInfo.mSpeed = curScalerVIPInfo.mSpeed;
		Info.s16_mSpeed = curScalerVIPInfo.mSpeed;
		PQL_Info(PQL_INFO_SPEED, &Info);

	}

	curScalerVIPInfo.mVOSeek= DIRECT_VO_GetFirstFrameAfterSeek();
	if(curScalerVIPInfo.mVOSeek!= gstScalerVIPInfo.mVOSeek){
		gstScalerVIPInfo.mVOSeek = curScalerVIPInfo.mVOSeek;
		Info.u1_mVOSeek = curScalerVIPInfo.mVOSeek;
		PQL_Info(PQL_INFO_VOSEEK, &Info);
		//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 0, 7, gstScalerVIPInfo.mVOSeek);
	}

#endif

#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
#ifndef CONFIG_RTK_KDEV_VGIP_INTERRUPT
	curScalerVIPInfo.bZoomAction = (RPC_SmartPic_clue->MEMC_VCPU_setting_info.bZoomAction);
	curScalerVIPInfo.bShiftAction = (RPC_SmartPic_clue->MEMC_VCPU_setting_info.bShiftAction);
#endif
#endif

	if(curScalerVIPInfo.bZoomAction!= gstScalerVIPInfo.bZoomAction)
	{
		gstScalerVIPInfo.bZoomAction = curScalerVIPInfo.bZoomAction;
		Info.u1_ZoomAction = curScalerVIPInfo.bZoomAction;
		PQL_Info(PQL_INFO_ZOOM, &Info);

	}

	if(curScalerVIPInfo.bShiftAction!= gstScalerVIPInfo.bShiftAction)
	{
		gstScalerVIPInfo.bShiftAction = curScalerVIPInfo.bShiftAction;
		Info.u1_ShiftAction = curScalerVIPInfo.bShiftAction;
		PQL_Info(PQL_INFO_SHIFT, &Info);

	}

	if(curScalerVIPInfo.source_type != gstScalerVIPInfo.source_type){
		gstScalerVIPInfo.source_type = curScalerVIPInfo.source_type;
		Info.u16_source_type = curScalerVIPInfo.source_type;
		PQL_Info(PQL_INFO_SOURCE_TYPE, &Info);
	}

	curScalerVIPInfo.MEMCMode = gstAppData.stMEMCData.enMemcMode;
	if(curScalerVIPInfo.MEMCMode!= gstScalerVIPInfo.MEMCMode){
		gstScalerVIPInfo.MEMCMode = curScalerVIPInfo.MEMCMode;
		Info.u16_MEMCMode = curScalerVIPInfo.MEMCMode;
		PQL_Info(PQL_INFO_MEMC_MODE, &Info);
	}

	if(curScalerVIPInfo.mDarkLevel != gstScalerVIPInfo.mDarkLevel){
		gstScalerVIPInfo.mDarkLevel = curScalerVIPInfo.mDarkLevel;
		Info.u8_mDarkLevel= curScalerVIPInfo.mDarkLevel;
		PQL_Info(PQL_INFO_DARKLEVEL, &Info);
	}

	if(curScalerVIPInfo.Hist_SC_flg!= gstScalerVIPInfo.Hist_SC_flg){
		gstScalerVIPInfo.Hist_SC_flg= curScalerVIPInfo.Hist_SC_flg;
		Info.u1_hist_sc_flg= curScalerVIPInfo.Hist_SC_flg;
		PQL_Info(PQL_INFO_HIST_SC, &Info);
	}

	if(curScalerVIPInfo.mSoccer_holdfrm != gstScalerVIPInfo.mSoccer_holdfrm){
		gstScalerVIPInfo.mSoccer_holdfrm = curScalerVIPInfo.mSoccer_holdfrm;
		Info.u8_mSoccer_holdfrm= curScalerVIPInfo.mSoccer_holdfrm;
		PQL_Info(PQL_INFO_SOCCER_Patch, &Info);
	}

	//PictureMode_Chg
	if(curScalerVIPInfo.PictureMode_Chg != gstScalerVIPInfo.PictureMode_Chg){
		gstScalerVIPInfo.PictureMode_Chg = curScalerVIPInfo.PictureMode_Chg;
		Info.u1_PictureMode_Chg= curScalerVIPInfo.PictureMode_Chg;
		PQL_Info(PQL_INFO_PICTUREMODE_CHG, &Info);
	}

	if(curScalerVIPInfo.bVIP_Still != gstScalerVIPInfo.bVIP_Still){
		gstScalerVIPInfo.bVIP_Still = curScalerVIPInfo.bVIP_Still;
		Info.u1_mVIP_Still= curScalerVIPInfo.bVIP_Still;
		PQL_Info(PQL_INFO_VIP_STILL, &Info);
	}
}

VOID MEMC_MidSetPCOff(VOID)
{
	MEMC_MODE motion = gstAppData.stMEMCData.enMemcMode;

	if(motion == MEMC_OFF || motion >= MEMC_MODE_MAX){
		MEMC_LibSetMEMCFrameRepeatEnable(1, 1);
	}
	else{
		MEMC_LibSetMEMCFrameRepeatEnable(0, 1);
	}
}

VOID MEMC_LibInputVSXral(VOID)
{
	_PQL_Command PQLCommand;

	//ac off->on, dma enable 2 vsync delay than slavemode=1.
	//default mastermode=1, change to dtg timing when slavemode=1, wait until stable.
	//do not move into outvsync => need to act in lower framerate.
	//only valid when ac off->on

//	const	_PQLCONTEXT	*s_pContext = GetPQLContext();
//	PQL_INPUT_FRAME_RATE u8_inFrameRate = s_pContext->_external_data._input_frameRate;
//	PQL_OUTPUT_FRAME_RATE u8_outFrameRate = s_pContext->_external_data._output_frameRate;

	if(Scaler_MEMC_GetInitFlag()==1){
		g_memc_ivsync_cnt++;
		if(g_memc_ivsync_cnt>=3){
			g_memc_ivsync_cnt = 0;
			MEMC_LibSetMEMCFrameRepeatEnable((gstAppData.stMEMCData.enMemcMode==MEMC_OFF ||gstAppData.stMEMCData.enMemcMode==MEMC_MODE_MAX), 1);
			Scaler_MEMC_SetInitFlag(0);
		}
		LogPrintf(DBG_MSG, "[MEMC]AC ON INIT!!!(trig=%d,vscnt=%d,mode=%d)\r\n", Scaler_MEMC_GetInitFlag(), g_memc_ivsync_cnt,gstAppData.stMEMCData.enMemcMode);
		return;
	}

	if((gstAppData.stMEMCData.bFrameRepeat != gstAppData.stMEMCData.bFrameRepeat_QRPC))
	{
		Mid_Mode_SetMEMCFrameRepeatEnable(gstAppData.stMEMCData.bFrameRepeat_QRPC, &Ready_For_SetMCBlendMode);
		gstAppData.stMEMCData.bFrameRepeat = gstAppData.stMEMCData.bFrameRepeat_QRPC;
		InputVSXral_FrameRepeatMode = (gstAppData.stMEMCData.bFrameRepeat == FALSE)? 5:0;
	} else {

		if( (Ready_For_SetMCBlendMode == 0) && Mid_Mode_GetMC_DMA_Ready_flag()== 1){
			Mid_Mode_SetMEMCFrameRepeatEnable(gstAppData.stMEMCData.bFrameRepeat_QRPC, &Ready_For_SetMCBlendMode);
		}
	}


	if(InputVSXral_FrameRepeatMode > 0 && (!gstAppData.stMEMCData.bFrameRepeat))
	{
		InputVSXral_FrameRepeatMode--;
		PQLCommand.u8_InputVSXral_FrameRepeatMode = InputVSXral_FrameRepeatMode;
		PQL_Command(PQL_CMD_INPUTVSXRAL_FRAMEREPEAT_MODE, &PQLCommand);
	}
	else
		InputVSXral_FrameRepeatMode = 0;


	if(gstAppData.stMEMCData.bLowDelay != gstAppData.stMEMCData.bLowDelay_QRPC)
	{
		//Mid_Mode_SetMEMCFrameRepeatEnable(gstAppData.stMEMCData.bLowDelay_QRPC);
		gstAppData.stMEMCData.bLowDelay = gstAppData.stMEMCData.bLowDelay_QRPC;

		PQLCommand.u1_lowDelayMode = gstAppData.stMEMCData.bLowDelay;
		PQL_Command(PQL_CMD_LOWDELAYMODE, &PQLCommand);
		/*/
		if((gstAppData.stMEMCData.bLowDelay) && ((u8_inFrameRate == _PQL_IN_50HZ && u8_outFrameRate == _PQL_OUT_50HZ) || (u8_inFrameRate == _PQL_IN_60HZ && u8_outFrameRate == _PQL_OUT_60HZ)))
			rtdf_clearBits(0xb809d504, _BIT19);
		else
			rtdf_setBits(0xb809d504, _BIT19);
		if((gstAppData.stMEMCData.bLowDelay) && (u8_inFrameRate == _PQL_IN_25HZ && u8_outFrameRate == _PQL_OUT_50HZ))
			rtdf_setBits(0xb8028640, _BIT25);
		else
			rtdf_clearBits(0xb8028640, _BIT25);
		if((gstAppData.stMEMCData.bLowDelay) && (u8_inFrameRate == _PQL_IN_24HZ && u8_outFrameRate == _PQL_OUT_60HZ))
			rtdf_setBits(0xb8028640, _BIT26);
		else
			rtdf_clearBits(0xb8028640, _BIT26);
		/*/
	}

 	if(gstAppData.stMEMCData.bPCMode != gstAppData.stMEMCData.bPCMode_QRPC)
 	{
 		gstAppData.stMEMCData.bPCMode = gstAppData.stMEMCData.bPCMode_QRPC;
		//first to 7th frame: just mute, 8th to 18th frame: change out mode and fill buffer
		InputVSXral_PCMode = 18;
		MEMC_LibSetMuteColor(FALSE, FALSE, FALSE);// force black
		MEMC_LibSetMute(TRUE);
	}

	//change output mode
	if(InputVSXral_PCMode == 11)
	{
		if(gstAppData.stMEMCData.bPCMode == TRUE)
		{
			MEMC_LibSetInOutMode(MEMC_RGB_IN_PC_OUT,FALSE);
		}
		else
		{
			MEMC_LibSetInOutMode(MEMC_RGB_IN_VIDEO_OUT,FALSE);
			MEMC_MidSetPCOff();
		}

 		Mid_Mode_SetMEMC_PCModeEnable(gstAppData.stMEMCData.bPCMode);
 	}
	else if(InputVSXral_PCMode == 1)
	{
		MEMC_LibSetMute(FALSE);
	}

	if(InputVSXral_PCMode > 0)
 	{
		InputVSXral_PCMode--;
 	}
}

#ifdef WIN32
BOOL ReadRegSetCallback(ReadRegCallback cb)
{
	return RegIOReadRegSetCallback(cb);
}

BOOL WriteRegSetCallback(WriteRegCallback cb)
{
	return RegIOWriteRegSetCallback(cb);
}
#endif

VOID MEMC_SetRTKhdf(VOID)
{
//----------------kmc_top(0x00)----------------
	// for repeat pattern
	WriteRegister(FRC_TOP__kmc_top__reg_vhdtl_h_th_ADDR, 0, 9, 0x20);//reg_vhdtl_h_th
	WriteRegister(FRC_TOP__kmc_top__reg_vhdtl_v_th_ADDR, 10, 19, 0x20);//reg_vhdtl_v_th

//----------------MC(0x06)----------------
	WriteRegister(FRC_TOP__MC__reg_mc_show_scene_chg_ADDR, 28, 28, 0x0);

//----------------KPOST_TOP(0x40)----------------
	WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_enable_0_ADDR, 24, 27, 0x0);

//----------------CRTC1(0x41)----------------
	//WriteRegister(FRC_TOP__CRTC1__reg_crtc1_dec_vtrig_dly_ADDR, 6, 18, 0x80);//strange judder

//----------------PQL_0(0x45)----------------
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 0, 0, 0x1);//u1_zoom_detect_en
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 1, 1, 0x1);//u1_mc2_var_lpf_wrt_en

	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 5, 5, 0x1);//u1_LightSword_en
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 6, 6, 0x1);//u1_patch_casino_en
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 7, 7, 0x1);//u1_BigAPLDiff_en
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 8, 8, 0x1);//u1_casino_RP_DetCtrl
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 9, 9, 0x0);//u1_FB_pan_apply_en
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 10, 10, 0x0);//u1_FB_cross_apply_en
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 11, 11, 0x1);//u1_patch_soccer_en
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 12, 12, 0x1);//u1_fastmotion_det_en
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 13, 13, 0x1);//u1_localfb_wrt_en
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 14, 14, 0x1); // u1_scCtrl_wrt_en;
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 15, 15, 0x1);// u1_MECand_wrt_en;
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 16, 16, 0x1);// u1_MECandPnt_wrt_en;
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 17, 17, 0x1);// u1_GMV_wrt_en;
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 18, 18, 0x1);// u1_MEScan_wrt_en;
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 19, 19, 0x1);// u1_MEUpdStgh_wrt_en;
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 20, 20, 0x1);// u1_logoCtrl_wrt_en;
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 21, 21, 0x1);// u1_lg_UXN_patch_en;
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 23, 23, 0x1);// u1_patch_highFreq_en;
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 24, 24, 0x1);// u8_EPG_apply;
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 25, 25, 0x1);// u1_MEacdcBld_wrt_en;
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 26, 26, 0x1);// u1_simple_scene_en;
	WriteRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 27, 27, 0x1);// u1_special_scfb_en;


	WriteRegister(FRC_TOP__PQL_0__pql_scAls_fadeInOut_en_ADDR, 0, 0, 0x1); //u1_fadeInOut_en
	WriteRegister(FRC_TOP__PQL_0__pql_dynME_ac_dc_bld_apl_holdfrm_ADDR, 0, 7, 0xC); //u6_dynME_ac_dc_bld_apl_holdfrm
//----------------PQL_1(0x46)----------------
	WriteRegister(FRC_TOP__PQL_1__pql_film_det_bypass_ADDR, 28, 28, 0x1); //u1_BadEditSlowOut_En
	WriteRegister(FRC_TOP__PQL_1__pql_film_det_bypass_ADDR, 29, 29, 0x1); //u1_QuickSwitch_En
	WriteRegister(KIWI_REG(FRC_TOP__PQL_1__pql_film_quit_sml_mot_wgt), 0x5);
	WriteRegister(KIWI_REG(FRC_TOP__PQL_1__pql_film_enter_22_cnt_gain), 0x2);
	WriteRegister(KIWI_REG(FRC_TOP__PQL_1__pql_film_enter_32_cnt_gain), 0x2);
	WriteRegister(KIWI_REG(FRC_TOP__PQL_1__pql_film_enter_else_cnt_gain), 0x2);
	WriteRegister(KIWI_REG(FRC_TOP__PQL_1__pql_film_quit_prd_th), 0x8);

	WriteRegister(FRC_TOP__PQL_1__pql_wr_dyn_me_acdc_bld_wrt_en_ADDR, 7, 7, 0x1); //u1_dynME_acdcBld_wrt_en (for fade in/out)

	//--start--mixmode setting, set here first, move to hdf.h&hdf.tbl if they are stable.
	WriteRegister(KIWI_REG(FRC_TOP__PQL_1__pql_film_mix_mode_det_en), 0x1);
	WriteRegister(KIWI_REG(FRC_TOP__PQL_1__pql_film_mix_mode_rgn5_en), 0x1);
	WriteRegister(KIWI_REG(FRC_TOP__PQL_1__pql_film_mix_mode_enter_cnt_th), 0xE);
	WriteRegister(KIWI_REG(FRC_TOP__PQL_1__pql_film_mix_mode_rgn_move_min_mot), 0x220);
	WriteRegister(KIWI_REG(FRC_TOP__PQL_1__pql_film_mix_mode_rgn_move_mot_wgt), 0xA);
	//--end--mixmode setting
	WriteRegister(FRC_TOP__PQL_1__pql_film_det_bypass_ADDR, 26, 26, 0x1);//u1_powerSaving_en
	WriteRegister(FRC_TOP__PQL_1__pql_film_det_bypass_ADDR, 27, 27, 0x1);//u1_RepeatPattern_en

	WriteRegister(KIWI_REG(FRC_TOP__PQL_1__pql_rb_ctrl_dummy_b0), 0x5f32);// UXN Patch


//----------------KME_ME1_TOP1(0x35)----------------
	WriteRegister(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_me1_hold_cnt_ADDR, 0, 7, 0x1);
	WriteRegister(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_me2_hold_cnt_ADDR, 8, 15, 0x1);

//----------------KME_IPME(0x2c)----------------
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_5region1_v0),  0x4);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_5region1_v1),  0x58);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_5region2_v0),  0x1bc);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_5region2_v1),  0x20d);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_5region3_h0),  0x2);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_5region3_h1),  0x60);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_5region4_h0),  0x140);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_5region4_h1),  0x1d4);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_5region5_h0),  0xb0);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_5region5_h1),  0x137);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_5region5_v0),  0x32);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_5region5_v1),  0x1b0);

	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_h0), 0x2);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_h1), 0x60);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_h2), 0xd0);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_h3), 0x140);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_h4), 0x1d4);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_v0), 0x4);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_v1), 0x58);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_v2), 0x1bc);
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_v3), 0x20d);



}

void MEMC_LibSetKMVEngineEnable(unsigned char enable)
{
	Mid_DM_SetKMVEngineEnable(enable);
}

BOOL MEMC_GetInOutISREnable(VOID)
{
	return Mid_MISC_GetInINTEnable(INT_TYPE_VSYNC) && Mid_MISC_GetOutINTEnable(INT_TYPE_VSYNC);
}

UINT32 sram_ipme1, sram_lbme, sram_lbme2, sram_me1_vbuf, sram_me2_vbuf, sram_logo, sram_me, sram_dehalo;
UINT32 me1, me2, in_isr, out_isr, dehalo, candn;
BOOL MEMC_LibPowerSaveOn(VOID)
{

	UINT32 powerSaving_en = 0;
	ReadRegister(FRC_TOP__PQL_1__pql_film_det_bypass_ADDR, 26, 26, &powerSaving_en);

	if(powerSaving_en)
	{
		const _PQLCONTEXT *s_pContext = GetPQLContext();
		_PQL_Command PQLCommand;

		if(s_pContext->_output_filmDetectctrl.u8_cur_cadence_Id[_FILM_ALL]!=_CAD_VIDEO){
			return 1;
		}

		WriteRegister(FRC_TOP__PQL_0__pql_pql_onefifth_intp_en_ADDR, 29, 31, 0x0);

		{// save current status ----------------------------------------------------

			//SRAM LS Setting
			ReadRegister(FRC_TOP__KME_IPME1__reg_kme_ipme_sram_ls_en_ADDR, 25, 26, &sram_ipme1);
			ReadRegister(FRC_TOP__KME_LBME_TOP__reg_kme_lbme_sram_ls_en_ADDR, 22, 23, &sram_lbme);
			ReadRegister(FRC_TOP__KME_ME2_LBME_TOP__reg_me2_lbme_sram_ls_en_ADDR, 20, 21, &sram_lbme2);
			ReadRegister(FRC_TOP__KME_VBUF_TOP__reg_kme_vbuf_sram_ls_en_ADDR, 22, 23, &sram_me1_vbuf);
			ReadRegister(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_sram_ls_en_ADDR, 17, 18, &sram_me2_vbuf);
			ReadRegister(FRC_TOP__KME_LOGO2__reg_kme_logo_sram_ls_en_ADDR, 22, 23, &sram_logo);
			ReadRegister(FRC_TOP__KME_DM_TOP0__reg_kme_sram_ls_en_ADDR, 10, 11, &sram_me);
			ReadRegister(FRC_TOP__KME_DEHALO__reg_dh_sram_ls_ADDR, 25, 25, &sram_dehalo);

			//set me1/me2 vbuf state machine don't work, reduce cand num
			ReadRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_en_ADDR, 0, 15, &me1);
			ReadRegister(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_en_ADDR, 8, 8, &me2);

			//disable dehalo
			ReadRegister(FRC_TOP__KME_DEHALO__reg_dh_en_ADDR, 0, 0, &dehalo);

			//reduce cand num
			ReadRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_cand0_en_ADDR, 0, 14, &candn);

			//disable memc isr en
			//ReadRegister(FRC_TOP__kmc_top__reg_kmc_int_en_ADDR, 24, 27, &in_isr);
			ReadRegister(FRC_TOP__KPOST_TOP__reg_post_int_en_ADDR, 5, 8, &out_isr);
		}

		{// do power save ----------------------------------------------------

			//SRAM LS Setting
			WriteRegister(FRC_TOP__KME_IPME1__reg_kme_ipme_sram_ls_en_ADDR, 25, 26, 0x2);
			WriteRegister(FRC_TOP__KME_LBME_TOP__reg_kme_lbme_sram_ls_en_ADDR, 22, 23, 0x2);
			WriteRegister(FRC_TOP__KME_ME2_LBME_TOP__reg_me2_lbme_sram_ls_en_ADDR, 20, 21, 0x2);
			WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_kme_vbuf_sram_ls_en_ADDR, 22, 23, 0x2);
			WriteRegister(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_sram_ls_en_ADDR, 17, 18, 0x2);
			WriteRegister(FRC_TOP__KME_LOGO2__reg_kme_logo_sram_ls_en_ADDR, 22, 23, 0x2);
			WriteRegister(FRC_TOP__KME_DM_TOP0__reg_kme_sram_ls_en_ADDR, 10, 11, 0x2);
			WriteRegister(FRC_TOP__KME_DEHALO__reg_dh_sram_ls_ADDR, 25, 25, 0x1);

			//set me1/me2 vbuf state machine don't work, reduce cand num
			WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_en_ADDR, 0, 15, 0x0);
			WriteRegister(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_en_ADDR, 8, 8, 0x0);

			//disable dehalo
			WriteRegister(FRC_TOP__KME_DEHALO__reg_dh_en_ADDR, 0, 0, 0x0);//to here ng

			//reduce cand num
			WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_cand0_en_ADDR, 0, 14, 0x0);

			//disable memc isr en
			//WriteRegister(FRC_TOP__kmc_top__reg_kmc_int_en_ADDR, 24, 27, 0x0);
			WriteRegister(FRC_TOP__KPOST_TOP__reg_post_int_en_ADDR, 5, 8, 0x0);
		}

		PQLCommand.u1_powerSaving = 1;
		PQL_Command(PQL_CMD_POWERSAVING, &PQLCommand);

		WriteRegister(FRC_TOP__PQL_0__pql_pql_onefifth_intp_en_ADDR, 29, 31, 0x7);

		return 0;
	}
	else
	{
		return 1;
	}
}

BOOL MEMC_LibPowerSaveOff(VOID)
{


	UINT32 powerSaving_en = 0;
	ReadRegister(FRC_TOP__PQL_1__pql_film_det_bypass_ADDR, 26, 26, &powerSaving_en);

	if(powerSaving_en)
	{
		const _PQLCONTEXT *s_pContext = GetPQLContext();
		_PQL_Command PQLCommand;

		if(s_pContext->_output_filmDetectctrl.u8_cur_cadence_Id[_FILM_ALL]!=_CAD_VIDEO){
			return 1;
		}

		WriteRegister(FRC_TOP__PQL_0__pql_pql_onefifth_intp_en_ADDR, 29, 31, 0x0);

		{// disable power save ----------------------------------------------------

			//SRAM LS Setting
			WriteRegister(FRC_TOP__KME_IPME1__reg_kme_ipme_sram_ls_en_ADDR, 25, 26, sram_ipme1);
			WriteRegister(FRC_TOP__KME_LBME_TOP__reg_kme_lbme_sram_ls_en_ADDR, 22, 23, sram_lbme);
			WriteRegister(FRC_TOP__KME_ME2_LBME_TOP__reg_me2_lbme_sram_ls_en_ADDR, 20, 21, sram_lbme2);
			WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_kme_vbuf_sram_ls_en_ADDR, 22, 23, sram_me1_vbuf);
			WriteRegister(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_sram_ls_en_ADDR, 17, 18, sram_me2_vbuf);
			WriteRegister(FRC_TOP__KME_LOGO2__reg_kme_logo_sram_ls_en_ADDR, 22, 23, sram_logo);
			WriteRegister(FRC_TOP__KME_DM_TOP0__reg_kme_sram_ls_en_ADDR, 10, 11, sram_me);
			WriteRegister(FRC_TOP__KME_DEHALO__reg_dh_sram_ls_ADDR, 25, 25, sram_dehalo);

			//set me1/me2 vbuf state machine don't work, reduce cand num
			WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_en_ADDR, 0, 15, me1);
			WriteRegister(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_en_ADDR, 8, 8, me2);

			//disable dehalo
			WriteRegister(FRC_TOP__KME_DEHALO__reg_dh_en_ADDR, 0, 0, dehalo);

			//reduce cand num
			WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_cand0_en_ADDR, 0, 14, candn);

			//disable memc isr en
			//WriteRegister(FRC_TOP__kmc_top__reg_kmc_int_en_ADDR, 24, 27, in_isr);
			WriteRegister(FRC_TOP__KPOST_TOP__reg_post_int_en_ADDR, 5, 8, out_isr);
		}

		PQLCommand.u1_powerSaving = 0;
		PQL_Command(PQL_CMD_POWERSAVING, &PQLCommand);

		WriteRegister(FRC_TOP__PQL_0__pql_pql_onefifth_intp_en_ADDR, 29, 31, 0x7);

		return 0;
	}
	else
	{
		return 1;
	}
}

