/**
 * @file memc_type.h
 * @brief This header file defines memc data type.
 * @date Septempber.3.2014
 * @version V0.0.1
 * @author MartinYan
 * @par KW type trace V0.0.1 - Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#include "memc_isr/include/kw_type.h"

#ifndef _MEMC_TYPE_HEADER_
#define _MEMC_TYPE_HEADER_

/*! Input signal resolution enum. */
typedef enum 
{
	INPUT_RESOLUTION_1920X1080,					///< 1920X1080 resolution
	INPUT_RESOLUTION_1920X540,					///< 1920X540  resolution
	INPUT_RESOLUTION_3840X2160,					///< 3840x2160 resolution
	INPUT_RESOLUTION_3840X1080,					///< 3840x2160 resolution
	INPUT_RESOLUTION_3840X540,					///< 3840X540 resolution
	INPUT_RESOLUTION_1920X2160,					///< 1920X2160 resolutio
	INPUT_RESOLUTION_768X480,					///< 768x480 resolution
	INPUT_RESOLUTION_1280X720,					///< 1280x720 resolution
	
	INPUT_RESOLUTION_INVALID	= 0xFF,
}INPUT_RESOLUTION;

/*! Output signal resolution enum. */
typedef enum 
{
	OUTPUT_RESOLUTION_1920X1080,				///< 1920x1080 resolution
	OUTPUT_RESOLUTION_1920X540,					///< 1920x540  resolution
	OUTPUT_RESOLUTION_3840X2160,				///< 3840x2160 resolution
	OUTPUT_RESOLUTION_3840X1080,				///< 3840x1080 resolution
	OUTPUT_RESOLUTION_3840X540,					///< 3840X540 resolution
	OUTPUT_RESOLUTION_768X480,					///< 768x480 resolution
	OUTPUT_RESOLUTION_1280X720,					///< 1280x720 resolution
	
	OUTPUT_RESOLUTION_INVALID	= 0xFF,
}OUTPUT_RESOLUTION;

/*! Input signal frame rate enum. */
typedef enum 
{
	INPUT_FRAMERATE_24HZ,						///< input 24Hz
	INPUT_FRAMERATE_25HZ,						///< input 25Hz
	INPUT_FRAMERATE_30HZ,						///< input 30Hz

	INPUT_FRAMERATE_48HZ,						///< input 48Hz
	INPUT_FRAMERATE_50HZ,						///< input 50Hz
	INPUT_FRAMERATE_60HZ,						///< input 60Hz
	INPUT_FRAMERATE_96HZ,						///< input 96Hz	
	INPUT_FRAMERATE_100HZ,						///< input 100Hz
	INPUT_FRAMERATE_120HZ,						///< input 120Hz

	INPUT_FRAMERATE_INVALID		= 0xFF,
}INPUT_FRAMERATE;

/*! Output signal frame rate enum. */
typedef enum 
{	
	OUTPUT_FRAMERATE_48HZ,						///< output 48Hz
	OUTPUT_FRAMERATE_50HZ,						///< output 50Hz
	OUTPUT_FRAMERATE_60HZ,						///< output 60Hz
	OUTPUT_FRAMERATE_96HZ,						///< output 96Hz
	OUTPUT_FRAMERATE_100HZ,						///< output 100Hz
	OUTPUT_FRAMERATE_120HZ,						///< output 120Hz
	OUTPUT_FRAMERATE_200HZ,						///< output 200Hz
	OUTPUT_FRAMERATE_240HZ,						///< output 240Hz
	
	OUTPUT_FRAMERATE_MAX,
	OUTPUT_FRAMERATE_INVALID	= 0xFF,
}OUTPUT_FRAMERATE;

/*! Input format enum. */
typedef enum 
{
	INPUT_FORMAT_2D,							///< memc input is 2D
	INPUT_FORMAT_3D_SBS,						///< memc input is 3D SBS
	INPUT_FORMAT_3D_TB,							///< memc input is 3D TB
	INPUT_FORMAT_3D_LR,							///< memc input is 3D LR
	INPUT_FORMAT_3D_LBL,						///< memc input is 3D LBL

	INPUT_FORMAT_INVALID		= 0xFF,
}INPUT_FORMAT;

/*! Output format enum. */
typedef enum 
{
	OUTPUT_FORMAT_2D,							///< memc output is 2D
	OUTPUT_FORMAT_3D_SG,						///< memc output is 3DSG
	OUTPUT_FORMAT_3D_PR,						///< memc output is 3DPR
	OUTPUT_FORMAT_3D_SG_LLRR,					///< memc output is 3DSG LLRR

	OUTPUT_FORMAT_INVALID		= 0xFF,
}OUTPUT_FORMAT;

/*! Output mode enum. */
typedef enum 
{
	RGB_IN_VIDEO_OUT,							///< memc RGB in and video output
	RGB_IN_PC_OUT,								///< memc RGB in and pc output
	YUV_IN_VIDEO_OUT, 							///< memc YUV444 in and video output
	YUV_IN_PC_OUT,								///< memc YUV444 in and pc output
	INOUT_MODE_INVALID			= 0xFF,
}INOUT_MODE;

/*! define timing structure */
typedef struct
{
	UINT32					u32HTotal;			///< H total
	UINT32					u32HActive;			///< H active
	UINT32					u32HSWidth;			///< H sync width
	UINT32					u32HSBPorch;		///< H sync backporch
	UINT32					u32VTotal;			///< V total
	UINT32					u32VActive;			///< V active
	UINT32					u32VSWidth;			///< V sync width
	UINT32					u32VSBPorch;		///< V sync backporch
}TIMING_PARA_ST;

/*! MEMC mode enum. */
typedef enum 
{
	MEMC_MODE_SMOOTH,							///< Smooth mode
	MEMC_MODE_CLEAR,							///< Clear mode
	MEMC_MODE_NORMAL,							///< Normal mode
	MEMC_MODE_OFF,								///< Off mode
	MEMC_MODE_USER,								///< User mode, can manually set dejudder and deblur level
}MEMC_MODE_EN;

/*! MEMC RIM mode. */
typedef enum 
{
	MEMC_RIM_MODE_0,						///< memc rim mode 0
	MEMC_RIM_MODE_1,						///< memc rim mode 1
}RIM_MODE;

/*! Post horizontal scaler ratio. */
typedef enum 
{
	POST_HSC_BYPASS	= 1,
	POST_HSC_X2		= 2,
	POST_HSC_X4		= 4,
}POST_SCALER_RATIO_H;

/*! Post vertical scaler ratio. */
typedef enum 
{
	POST_VSC_BYPASS	= 1,
	POST_VSC_X2		= 2,
	POST_VSC_X4		= 4,
}POST_SCALER_RATIO_V;

/*! define Panel timing structure */
typedef struct 
{
	OUTPUT_FRAMERATE	enOutputFrameRate;	// Output frame rate
	UINT32				u32Htotal;			// H total
	UINT32				u32HtotalMax;		// H total max
	UINT32				u32HtotalMin;		// H total min
	UINT32				u32Hactive;			// H active
	UINT32				u32HSWidth;			// H sync width
	UINT32				u32HSBPorch;		// H back porch
	UINT32				u32Vtotal;			// V total
	UINT32				u32VtotalMax;		// V total max
	UINT32				u32VtotalMin;		// V total min
	UINT32				u32Vactive;			// V active
	UINT32				u32VSWidth;			// V sync width
	UINT32				u32VSBPorch;		// V back porch
}PANEL_PARAMETERS_ST;

/*! define Panel data structure */
typedef struct 
{
	UINT32				u32ID;					// ID
	UINT32				u32Version;				// Version
	UINT32				b2Type		:2;			// 0:2D,1:SG,2:PR
	UINT32				b2TXBitNum	:2;			// 0:8 bit,1:10 bit,2:12 bit
	UINT32				b2TXMode	:2;			// 0:VESA,1:JEIDA
	UINT32				reserve     :26;		// reserve
	UINT32				u32PanelPara_Idx;		// panel parameters idx
	PANEL_PARAMETERS_ST	stPanelParamertes[OUTPUT_FRAMERATE_MAX];	// Panel parameters
}PANEL_DATA_ST;

/*! Sample Format. */
typedef enum
{
	SAMPLE_FORMAT_444,
	SAMPLE_FORMAT_422,
	SAMPLE_FORMAT_MAX
}CS_SAMPLE_FORMAT;

/*! CSC Mode*/
typedef enum
{
	CSC_MODE_RGB_YUV_601_FULL,
	CSC_MODE_YUV_RGB_601_FULL,
	CSC_MODE_RGB_YUV_709_FULL,
	CSC_MODE_YUV_RGB_709_FULL,
	CSC_MODE_RGB_YUV_601_LIMIT,
	CSC_MODE_YUV_RGB_601_LIMIT,
	CSC_MODE_RGB_YUV_709_LIMIT,
	CSC_MODE_YUV_RGB_709_LIMIT,
	CSC_MODE_USER_DEFINE,
}CSC_MODE;

/*! CSC Mode*/
typedef enum
{
	INT_TYPE_HSYNC = 0,
	INT_TYPE_VSYNC,
	INT_TYPE_ABNORMAL,
}INT_TYPE;

/*! DM Buff address*/
typedef struct
{
	UINT32 u32StartAddress;
	UINT32 u32EndAddress;
}DM_BUF_ADDRESS;

/*!MC DM Address Struct*/
typedef struct 
{
	DM_BUF_ADDRESS stBuf_HF_0;
	DM_BUF_ADDRESS stBuf_HF_1;
	DM_BUF_ADDRESS stBuf_HF_2;
	DM_BUF_ADDRESS stBuf_HF_3;
	DM_BUF_ADDRESS stBuf_HF_4;
	DM_BUF_ADDRESS stBuf_HF_5;
	DM_BUF_ADDRESS stBuf_HF_6;
	DM_BUF_ADDRESS stBuf_HF_7;
	
	DM_BUF_ADDRESS stBuf_LF_0;
	DM_BUF_ADDRESS stBuf_LF_1;
	DM_BUF_ADDRESS stBuf_LF_2;
	DM_BUF_ADDRESS stBuf_LF_3;
	DM_BUF_ADDRESS stBuf_LF_4;
	DM_BUF_ADDRESS stBuf_LF_5;
	DM_BUF_ADDRESS stBuf_LF_6;
	DM_BUF_ADDRESS stBuf_LF_7;
	
	UINT32 		   u32LineOffset;
	UINT32		   u32LROffset;
}MC_DM_ADDRESS_ST;

/*!ME DM Address Struct*/
typedef struct 
{
	DM_BUF_ADDRESS stBuf_00_0;
	DM_BUF_ADDRESS stBuf_00_1;
	DM_BUF_ADDRESS stBuf_00_2;
	DM_BUF_ADDRESS stBuf_00_3;
	DM_BUF_ADDRESS stBuf_00_4;
	DM_BUF_ADDRESS stBuf_00_5;
	UINT32 		   u32Buf_00_LineOffset;
	UINT32		   u32Buf_00_LROffset;

	DM_BUF_ADDRESS stBuf_08_0;
	DM_BUF_ADDRESS stBuf_08_1;
	UINT32 		   u32Buf_08_LineOffset;

	DM_BUF_ADDRESS stBuf_10_0;
	DM_BUF_ADDRESS stBuf_10_1;
	UINT32 		   u32Buf_10_LineOffset;

	DM_BUF_ADDRESS stBuf_12_0;
	DM_BUF_ADDRESS stBuf_12_1;
	UINT32 		   u32Buf_12_LineOffset;
	
	DM_BUF_ADDRESS stBuf_14_0;
	DM_BUF_ADDRESS stBuf_14_1;
	UINT32 		   u32Buf_14_LineOffset;
}ME_DM_ADDRESS_ST;

/*!MV DM Address Struct*/
typedef struct 
{
	DM_BUF_ADDRESS stBuf_01_0;
	UINT32 		   u32Buf_01_LineOffset;
	UINT32		   u32Buf_01_LROffset;
	
	DM_BUF_ADDRESS stBuf_02_0;
	UINT32 		   u32Buf_02_LineOffset;
	UINT32		   u32Buf_02_LROffset;

	DM_BUF_ADDRESS stBuf_04_0;
	DM_BUF_ADDRESS stBuf_04_1;
	DM_BUF_ADDRESS stBuf_04_2;
	UINT32 		   u32Buf_04_LineOffset;
	UINT32		   u32Buf_04_LROffset;
	
	DM_BUF_ADDRESS stBuf_05_0;
	DM_BUF_ADDRESS stBuf_05_1;
	UINT32 		   u32Buf_05_LineOffset;
	UINT32		   u32Buf_05_LROffset;	

	DM_BUF_ADDRESS stBuf_12_0;
	DM_BUF_ADDRESS stBuf_12_1;
	DM_BUF_ADDRESS stBuf_12_2;
	DM_BUF_ADDRESS stBuf_12_3;
	DM_BUF_ADDRESS stBuf_12_4;
	DM_BUF_ADDRESS stBuf_12_5;
	DM_BUF_ADDRESS stBuf_12_6;
	DM_BUF_ADDRESS stBuf_12_7;
	UINT32 		   u32Buf_12_LineOffset;
	UINT32		   u32Buf_12_LROffset;	
}MV_DM_ADDRESS_ST;

#endif /*! End of #ifndef _REAL_TYPE_HEADER_ */

