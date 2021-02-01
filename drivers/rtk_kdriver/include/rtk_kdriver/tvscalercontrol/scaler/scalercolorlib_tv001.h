#ifndef __SCALERCOLOR_LIB_TV001_H__
#define __SCALERCOLOR_LIB_TV001_H__

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Header include
******************************************************************************/


#include <tvscalercontrol/vip/icm.h>
#include <tvscalercontrol/scaler/source.h>
#include <tvscalercontrol/scaler/vipinclude.h>
#include <tvscalercontrol/vip/color.h>
#include <tvscalercontrol/vip/scalerColor.h>


/*******************************************************************************
* Macro
******************************************************************************/



/*******************************************************************************
* Constant
******************************************************************************/
/*#define example  100000*/ /* 100Khz */




/*******************************************************************************
 * Structure
 ******************************************************************************/
/*typedef struct*/
/*{*/
/*} MID_example_Param_t;*/


typedef struct
{
    unsigned int redGain;
    unsigned int greenGain;
    unsigned int blueGain;
    unsigned int redOffset;
    unsigned int greenOffset;
    unsigned int blueOffset;
}TV010_COLOR_TEMP_DATA_S;


typedef struct
{
    unsigned int min;
    unsigned int max;
}TV010_MEMC_RANGE_S;


/*******************************************************************************
* enumeration
******************************************************************************/
typedef enum
{
    TV010_COLORTEMP_NATURE = 0,
    TV010_COLORTEMP_COOL,
    TV010_COLORTEMP_WARM,
    TV010_COLORTEMP_USER,

    TV010_COLORTEMP_MAX
}TV010_COLORTEMP_E;
typedef enum
{
    TV010_LEVEL_OFF = 0,
    TV010_LEVEL_LOW,
    TV010_LEVEL_MID,
    TV010_LEVEL_HIGH,
    TV010_LEVEL_AUTO,

    TV010_LEVEL_MAX
}TV010_LEVEL_E;
typedef enum
{
    TV010_DEMOLEVEL_OFF = 0,
    TV010_DEMOLEVEL_ON,
    TV010_DEMOLEVEL_DEMO,

    TV010_DEMOLEVEL_MAX
}TV010_DEMOLEVEL_E;
typedef enum
{
    TV010_DEMO_DBDR = 0,
    TV010_DEMO_NR,
    TV010_DEMO_SHARPNESS,
    TV010_DEMO_DCI,
    TV010_DEMO_WCG,
    TV010_DEMO_MEMC,
    TV010_DEMO_COLOR,
    TV010_DEMO_SR,
    TV010_DEMO_ALL,
    TV010_DEMO_HDR,
    TV010_DEMO_SDR_TO_HDR,

    TV010_DEMO_MAX
}TV010_DEMO_MODE_E;
typedef enum
{
     TV010_PQ_MODULE_FMD = 0,
     TV010_PQ_MODULE_NR,
     TV010_PQ_MODULE_DB,
     TV010_PQ_MODULE_DR,
     TV010_PQ_MODULE_HSHARPNESS,
     TV010_PQ_MODULE_SHARPNESS,
     TV010_PQ_MODULE_CCCL,
     TV010_PQ_MODULE_COLOR_CORING,
     TV010_PQ_MODULE_BLUE_STRETCH,
     TV010_PQ_MODULE_GAMMA,
     TV010_PQ_MODULE_DBC,
     TV010_PQ_MODULE_DCI,
     TV010_PQ_MODULE_COLOR,
     TV010_PQ_MODULE_ES,
     TV010_PQ_MODULE_SR,
     TV010_PQ_MODULE_FRC,
     TV010_PQ_MODULE_WCG,
     TV010_PQ_MODULE_ALL,

     TV010_PQ_MODULE_MAX
}TV010_PQ_MODULE_E;

typedef enum
{
    TV010_HDR_TYPE_SDR,        /**< SDR*/
    TV010_HDR_TYPE_HDR10,  /**< HDR10 */
    TV010_HDR_TYPE_DOLBY_HDR,  /**< DOLBY  VISION */
    TV010_HDR_TYPE_SDR_TO_HDR, /**< SDR to HDR */

    TV010_HDR_TYPE_MAX,
}TV010_HDR_TYPE_E;


typedef enum {
	
	TV030_LINEAR,
	TV030_NONLINEAR,

	TV030_RATIO_TYPE_BUTT,
}TV030_RATIO_TYPE_E;


typedef enum
{
    TV010_LDM_DEMO_RIGHT_SCREEN          = 0,    /**<right */
    TV010_LDM_DEMO_LEFT_SCREEN           = 1,    /**<left */
    TV010_LDM_DEMO_TOP_SCREEN            = 2,    /**<top */
    TV010_LDM_DEMO_BOTTOM_SCREEN         = 3,    /**<bottom */
    TV010_LDM_DEMO_WHITE_SCREEN          = 4,    /**<white */
    TV010_LDM_DEMO_RIGHT_WHITE_SCREEN    = 5,    /**<right white */
    TV010_LDM_DEMO_LEFT_WHITE_SCREEN     = 6,    /**<left white */
    TV010_LDM_DEMO_TOP_WHITE_SCREEN      = 7,    /**<top white */
    TV010_LDM_DEMO_BOTTOM_WHITE_SCREEN   = 8,    /**<bottom white */
    TV010_LDM_DEMO_HORSELIGHT            = 9,    /**<LDM type is HORSELIGHT */
    TV010_LDM_DEMO_OFF                   = 10,   /**<LDM type is off */

    TV010_LDM_DEMO_MAX

}TV010_LOCALDIMMING_DEMO_MODE_E;

typedef enum
{
    TV010_SDR_ICM_STD,
    TV010_SDR_ICM_VIVID,
    TV010_SDR_ICM_GENTLE,
    TV010_HDR_ICM_STD,
    TV010_HDR_ICM_VIVID,
    TV010_HDR_ICM_GENTLE,
    TV010_SDR_ICM_RESERVED1,
    TV010_SDR_ICM_RESERVED2,
    TV010_SDR_ICM_RESERVED3,

    TV010_PQ_ICM_MAX,
}TV010_ICM_TABLE_INDEXE_E;

typedef struct _RTK_TableSize_Gamma {
	unsigned short nTableSize;	
	unsigned short pu16Gamma_r[256];
	unsigned short pu16Gamma_g[256];
	unsigned short pu16Gamma_b[256];
		
} RTK_TableSize_Gamma;

typedef struct _SCREEN_PIXEL_INFO
{
	UINT16 h_sta;
	UINT16 h_end;
	UINT16 v_sta;
	UINT16 v_end;

	UINT32 r_sum;
	UINT32 g_sum;
	UINT32 b_sum;
} SCREEN_PIXEL_INFO;

typedef struct _SCALER_DISPLAY_DATA
{
	unsigned short h_sta;
	unsigned short h_end;
	unsigned short v_sta;
	unsigned short v_end;

} SCALER_DISPLAY_DATA;



typedef struct _YuvUV2RGB_Original {
	unsigned short k_11;
	unsigned short k_12;
	unsigned short k_13;
	unsigned short k_22;
	unsigned short k_23;
	unsigned short k_32;
	unsigned short k_33;

	unsigned short r_offset;
	unsigned short g_offset;
	unsigned short b_offset;
	
	//unsigned char bt_2020;
	//unsigned short k_132;
	//unsigned short k_322;
} YuvUV2RGB_Original;


typedef enum
{
	PQ_DEMO_2K_TO_4K = 0,
	PQ_DEMO_MEMC,
	PQ_DEMO_COLOR_ANALYSIS,
	PQ_DEMO_COLOR_ENHANCE,
	PQ_DEMO_HDR_SIDE_BY_SIDE,
	PQ_DEMO_HDR_DYNAMIC,
	PQ_DEMO_HDR_ON_OFF,
	PQ_DEMO_GAMUT_CTRL,
	PQ_DEMO_COLOR_REDUCTION,
	PQ_DEMO_LUMA_CTRL,
	PQ_DEMO_SDR2HDR,

    //=============
    PQ_SDR_ALGORITHM, //=11
    PQ_HDR_ALGORITHM,
    PQ_HDR_ALGORITHM_PASS,
   //============================== 
           
	PQ_DEMO_MAX
}Light_Window_forDemo_E;

 typedef struct _BRIGHTNESS_LUT_OETF {
	 unsigned short 	un16_length;		 
	 unsigned short 	pf_LUT[256];			 
 }BRIGHTNESS_LUT_OETF;

typedef enum{
	RED = 0,			///<?色??索引
	GREEN,		///<?色??索引
	BLUE,		///<?色??索引
	YELLOW,		///<?色??索引
	CYAN,		///<青色??索引
	MAGENTA,		///<品???索引
	FLESH_TONE,	///<?色??索引

	colorindex_MAX
} VPQ_COLORSPACE_INDEX;

typedef struct _RTK_VPQ_COLORSPACE {
	unsigned char u8Mode ;
	unsigned char color[3] ;
	VPQ_COLORSPACE_INDEX index;
} RTK_VPQ_COLORSPACE;

typedef struct  _RTK_VPQ_COLORSPACE_BASIC{
	UINT8 red;
	UINT8 green;
	UINT8 blue;
}RTK_VPQ_COLORSPACE_BASIC;

typedef struct _RTK_VPQ_COLORSPACE_INDEX{	
	RTK_VPQ_COLORSPACE_BASIC CS_CUSTOM_RED;
	RTK_VPQ_COLORSPACE_BASIC CS_CUSTOM_GREEN;
	RTK_VPQ_COLORSPACE_BASIC CS_CUSTOM_BLUE;
	RTK_VPQ_COLORSPACE_BASIC CS_CUSTOM_YELLOW;
	RTK_VPQ_COLORSPACE_BASIC CS_CUSTOM_CYAN;
	RTK_VPQ_COLORSPACE_BASIC CS_CUSTOM_MAGENTA;
	RTK_VPQ_COLORSPACE_BASIC CS_CUSTOM_FLESH_TONE;	
	UINT8 mode;
} RTK_VPQ_COLORSPACE_INDEX;


 typedef struct {	 
 	unsigned int	 un16_CIE_x;  	 
	unsigned int	 un16_CIE_y;   
}RTK_VPQ_COLOUR_GAMUT_POINT_T;  

 typedef struct {	 
 	RTK_VPQ_COLOUR_GAMUT_POINT_T	 primary_r; 		 
	RTK_VPQ_COLOUR_GAMUT_POINT_T	 primary_g; 		 
	RTK_VPQ_COLOUR_GAMUT_POINT_T	 primary_b; 	 	 
	RTK_VPQ_COLOUR_GAMUT_POINT_T	 primary_wihte;  	
	//nsigned short un16_max_luminance;							
	//nsigned short un16_min_luminance;						 
}RTK_VPQ_PANEL_DATA_T;

typedef enum{  	
		PQ_MODE_BYPASS=0,    	
		PQ_MODE_NORMAL,      	
		PQ_MODE_xvycc,       	
		PQ_MODE_HDR,         	
		PQ_MODE_SDR2HDR,   	
		PQ_MODE_FOOTBALL,   	
		PQ_MODE_DOLBY,    	
		PQ_MODE_FILM,       	
		PQ_MODE_DCIP3,     	
		PQ_MODE_ENHANCE_WIDE,    	
		PQ_MODE_HDR_ENHANCE_WIDE, 
		PQ_MODE_SHOP_DEMO,
		PQ_MODE_MAX = 0xff,
}RTK_VPQ_MODE_TYPE_TV030;


/*******************************************************************************
* Variable
******************************************************************************/
/*static unsigned char gExample = 100000;*/ /* 100K */

//extern Scaler_ICM_Block_Adj icm_block_adj;

/*******************************************************************************
* Program
******************************************************************************/


/*o---------------------------------------------------------------------------o*/
/*o-------------Scalercolor.cpp------------------------------------o*/
/*o---------------------------------------------------------------------------o*/


/*==================== Definitions ================= */



/*=========================================================*/


/*==================== Functions ================== */




/*o===========================================================o*/
/*o==================== OSD MENU Start =======================o*/
/*o===========================================================o*/
unsigned int Scaler_GetColorTemp_level_type(TV010_COLORTEMP_E * colorTemp);
void Scaler_SetColorTemp_level_type(TV010_COLORTEMP_E colorTemp);
unsigned int Scaler_GetColorTempData(TV010_COLOR_TEMP_DATA_S *colorTemp);
void Scaler_SetColorTempData(TV010_COLOR_TEMP_DATA_S *colorTemp);
unsigned int Scaler_GetDeRinging_level(TV010_LEVEL_E *drLevel);
void Scaler_SetDeRinging_level(TV010_LEVEL_E drLevel);
unsigned int Scaler_GetSRLevel(TV010_DEMOLEVEL_E *srLevel);
void Scaler_SetSRLevel(TV010_DEMOLEVEL_E srLevel);
unsigned int Scaler_GetColorGainLevel(TV010_LEVEL_E *colorGain);
void Scaler_SetColorGainLevel(unsigned int icmIndex);
unsigned int Scaler_GetFleshToneLevel(TV010_LEVEL_E *fleshtone);
void Scaler_SetFleshToneLevel(TV010_LEVEL_E fleshtone);
void fwif_color_icm_set_block_para(TV010_LEVEL_E fleshtone);


/*o===========================================================o*/
/*o==================== OSD MENU End = =======================o*/
/*o===========================================================o*/
/*o===========================================================o*/
/*o==================== DemoMode Start =======================o*/
/*o===========================================================o*/

void Scaler_SetDemoMode(TV010_DEMO_MODE_E demoMode,unsigned char onOff);

/*o===========================================================o*/
/*o==================== DemoMode End = =======================o*/
/*o===========================================================o*/


unsigned int Scaler_GetODLevel(unsigned int *level);
void Scaler_SetODReadEnable(unsigned char enable);
unsigned int Scaler_GetGammaNum(unsigned int *number);
void Scaler_Set_Software_Gamma(unsigned char gammaIndex);
void Scaler_SetBlackPatternOutput(unsigned char isBlackPattern);
void Scaler_SetWhitePatternOutput(unsigned char isWhitePattern);
unsigned int Scaler_GetPQModule(TV010_PQ_MODULE_E pqModule,unsigned char * onOff);
void Scaler_SetPQModule(TV010_PQ_MODULE_E pqModule,unsigned char onOff);

unsigned int Scaler_GetSDR2HDR(unsigned char * onOff);
void Scaler_SetSDR2HDR(unsigned char onOff);
unsigned int Scaler_GetHdr10Enable(unsigned char * bEnable);
void Scaler_SetHdr10Enable(unsigned char bEnable);
unsigned int Scaler_GetDOLBYHDREnable(unsigned char * bEnable);
void Scaler_SetDOLBYHDREnable(unsigned char bEnable);
unsigned int Scaler_GetSrcHdrInfo(unsigned int * pGammaType);
unsigned int Scaler_GetHdrType(TV010_HDR_TYPE_E * pHdrType);
void Scaler_SetPanoramaType(TV030_RATIO_TYPE_E ratio);


/*==================== Localdimming ================== */

unsigned int Scaler_GetCurrentPanelSupportLocaldimming(unsigned char *support);

void Scaler_SetLocalDimmingDemoMode(unsigned char mode);
unsigned int Scaler_GetLocalDimmingDemoMode(TV010_LOCALDIMMING_DEMO_MODE_E *demoMode);
void Scaler_SetLocalDimmingSpiEnable(unsigned char bEnable);


/*==================== MEMC ================== */

unsigned int Scaler_GetMemcEnable(unsigned char * bEnable);
unsigned int Scaler_GetMemcRange(TV010_MEMC_RANGE_S *range);
void Scaler_SetMemcLevel(TV010_LEVEL_E level);
void Scaler_setSR(unsigned char onOff);



/*========================================= */
void fwif_color_gamma_encode_TableSize(RTK_TableSize_Gamma *pData);
unsigned char Scaler_Get_LC_blk_hnum(void);
unsigned char Scaler_Get_LC_blk_vnum(void);
UINT8 fwif_color_get_DM2_HDR_histogram_TV030(UINT32* HDR_info);
UINT8 fwif_color_get_DM_HDR10_enable_TV030(void);
unsigned char Scaler_Get_LD_Enable(void);
void Scaler_Set_Partten4AutoGamma(unsigned char  Enable, unsigned short  r_Val,unsigned short  g_Val,unsigned short  b_Val);
void Scaler_Set_Partten4AutoGamma_mute(unsigned char mute_flag, unsigned char display_flag,SCALER_DISPLAY_DATA* sdp_info);
void Scaler_Get_ScreenPixel_info(SCREEN_PIXEL_INFO* sp_info);
void Scaler_Set_hdmi_provider_type(unsigned char mode);
void fwif_color_set_cinema_mode_en_TV030(unsigned char bEn);
unsigned char fwif_color_get_cinema_mode_en_TV030(void);
void Scaler_SetLight_Window_forDemo(Light_Window_forDemo_E demoMode, unsigned char onoff);
void Scaler_SetBrightness_LUT_OETF(unsigned short *Out_T , BRIGHTNESS_LUT_OETF *pData);
void Scaler_Set_ColorSpace_InvGamma_sRGB(unsigned char onoff);
void Scaler_SetOETF2Gamma(BRIGHTNESS_LUT_OETF *pData);
void Scaler_Set_PictureMode_PQsetting(RTK_VPQ_MODE_TYPE_TV030 mode);
unsigned char Scaler_Get_ADV_API_LEVEL_TBL_Idx(VIP_SOURCE_TIMING VIP_SrcTiming, VIP_ADV_API_LEVEL API_Level);
char Scaler_get_sGamma(void);
void Scaler_set_sGamma(char level_index);
unsigned char Scaler_get_BLE(void);
void Scaler_set_BLE(unsigned char level_index);
unsigned char Scaler_get_dcc_table_by_source(unsigned char table_mode);

void Scaler_Set_ColorSpace_D_3dlutTBL(RTK_VPQ_COLORSPACE_INDEX *ColoSpace_T);
char fwif_OSDMapToLUTValue(unsigned char value);
void fwif_color_cal_D_3DLUT_Tbl(UINT8 axis);

#ifdef __cplusplus
}
#endif

#endif /* __SCALER_LIB_H__*/

