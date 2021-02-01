#ifndef __PANEL_API_H__
#define __PANEL_API_H__

#ifdef __cplusplus
extern "C" {
#endif

//#include <rtd_types.h>
//#include <Platform_Lib/panel/panel.h>
#include <panelConfigParameter.h>
//#include <Platform_Lib/panel/panelCustomIndex.h>

//#include <rbus/scaler/rbusLDSPIReg.h>
//#include <rbus/scaler/ld_interface_def.h>

typedef enum {
	LD_CMO_MODE = 0,
	LD_LGD_MODE,
	LD_AS_MODE,
	LD_FORBIDDEN
}LD_MODE;

typedef enum {
	LD_WRITE_MODE_NOT_FOLLOW_VSYNC = 0,
	LD_WRITE_MODE_FOLLOW_VSYNC
}LD_WRITE_MODE;


void ld_Init(void);
int ld_Write(unsigned int* data, unsigned int length,LD_WRITE_MODE mode);
unsigned int ld_Read(unsigned int addr);


extern UINT32 LVDS_4_PORT_MAPPING_TABLE[24];

void Panel_InitParameter(PANEL_CONFIG_PARAMETER *parameter);

#ifdef ENABLE_FACTORY_PARTITION
bool Panel_GetDefaultParameter(PANEL_CONFIG_PARAMETER *parameter);
PANEL_CONFIG_PARAMETER* Panel_GetPanelConfigParameter();
#endif

//#ifdef ENABLE_FACTORY_PANEL_SETTING
//void Panel_SyncDefaultParameter();
//PANEL_CONFIG_PARAMETER* Panel_GetPanelConfigParameter();
//#endif

unsigned char GET_DISPLAY_2K1K_OUTPUT_ENABLE(void);

unsigned char Get_DISPLAY_2k1k_output_mode_status(void);

unsigned char Get_DISPLAY_2K1K_windows_mode(void);	 // 2k1k window display 4k2k resolution

unsigned int Get_DISPLAY_PORT(void) ;

unsigned int Get_DISPLAY_COLOR_BITS(void);

unsigned int Get_DISPLAY_EVEN_RSV1_BIT(void);

unsigned int Get_DISPLAY_ODD_RSV1_BIT(void);

unsigned int Get_DISPLAY_BITMAPPING_TABLE(void);


unsigned int Get_DISPLAY_PORTAB_SWAP(void) ;

unsigned int Get_DISPLAY_RED_BLUE_SWAP(void);

unsigned int Get_DISPLAY_MSB_LSB_SWAP(void);

unsigned int Get_DISPLAY_SKEW_DATA_OUTPUT(void);

//#if defined(TV003_ADTV)
void Panel_TurnOn_Backlight(void);

void Panel_TurnOff_Backlight(void);
//#endif

unsigned int Get_DISPLAY_OUTPUT_INVERSE(void);

//unsigned int Get_DISPLAY_CLOCK_DELAY();

unsigned int Get_DISPLAY_VERTICAL_SYNC_NORMAL(void) ;

unsigned int Get_DISPLAY_HORIZONTAL_SYNC_NORMAL(void) ;

unsigned int Get_DISPLAY_RATIO_4X3(void);
unsigned int Get_DISPLAY_CLOCK_INVERSE(void);
unsigned int Get_DISPLAY_CLOCK_MAX(void) ;
unsigned int Get_DISPLAY_CLOCK_MIN(void);

unsigned int Get_DISPLAY_REFRESH_RATE(void) ;
unsigned int Get_DISPLAY_CLOCK_TYPICAL(void);

unsigned int Get_DISP_HORIZONTAL_TOTAL(void) ;


unsigned int Get_DISP_VERTICAL_TOTAL(void);


unsigned int Get_DISP_HSYNC_WIDTH(void) ;

unsigned int Get_DISP_VSYNC_LENGTH(void);

unsigned int Get_DISP_DEN_STA_HPOS(void) ;
unsigned int Get_DISP_DEN_END_HPOS(void);
unsigned int Get_DISP_DEN_STA_VPOS(void) ;

unsigned int Get_DISP_DEN_END_VPOS(void) ;



/*
 * Display active window setup
 */
unsigned int Get_DISP_ACT_STA_HPOS(void) ;

unsigned int Get_DISP_ACT_END_HPOS_PRE(void);

unsigned int Get_DISP_ACT_END_HPOS(void) ;

unsigned int Get_DISP_ACT_STA_VPOS(void) ;
unsigned int Get_DISP_ACT_END_VPOS(void) ;

unsigned int Get_DISP_HSYNC_LASTLINE(void) ;

unsigned int Get_DISP_DCLK_DELAY(void) ;


unsigned int Get_DISP_ACT_STA_BIOS(void);

unsigned int Get_DEFAULT_DPLL_M_DIVIDER(void)	;

unsigned int Get_DEFAULT_DPLL_N_DIVIDER(void)	;

unsigned int Get_DISPLAY_CLOCK_TYPICAL(void);

unsigned int Get_PANEL_TO_LVDS_ON_ms(void);


unsigned int Get_LVDS_TO_LIGHT_ON_ms(void);


unsigned int Get_LIGHT_TO_LDVS_OFF_ms(void);


unsigned int Get_LVDS_TO_PANEL_OFF_ms(void);


unsigned int Get_PANEL_OFF_TO_ON_ms(void);

unsigned int Get_PANEL_FIX_LAST_LINE_ENABLE(void);
unsigned int Get_PANEL_FIX_LAST_LINE_4X_ENABLE(void);
unsigned char Get_PANEL_VFLIP_ENABLE(void);
unsigned char Get_PANEL_PICASSO_ENABLE(void);
unsigned char Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE(void);
unsigned char Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE(void);
unsigned char Get_PANEL_3D_PR_OUTPUT_LR_SWAP(void);
unsigned char Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE(void);
unsigned char Get_PANEL_3D_SG_24HZ_OUTPUT_FHD_ENABLE(void);
unsigned char Get_PANEL_SCALER_2D_3D_CVT_HWSHIFT_ENABLE(void);
unsigned char Set_PANEL_3D_PIN(int enable);
unsigned char Get_PANEL_3D_PANEL_TYPE(void);
unsigned int Get_PANEL_DISP_VERTICAL_TOTAL_50Hz_MIN(void);
unsigned int Get_PANEL_DISP_VERTICAL_TOTAL_50Hz_MAX(void);
unsigned int Get_PANEL_DISP_VERTICAL_TOTAL_60Hz_MIN(void);
unsigned int Get_PANEL_DISP_VERTICAL_TOTAL_60Hz_MAX(void);

unsigned char Get_OD_MODE(void);
unsigned char Get_OD_GAIN(void);
unsigned char Get_OD_BITMODE(void);
unsigned char Get_OD_COMP_MODE(void);
unsigned char Get_PCID_ENABEL(void);
unsigned char Get_OD_ENABEL(void);

unsigned int Get_DISPLAY_PORT_CONFIG1(void);

unsigned int Get_DISPLAY_PORT_CONFIG2(void);

unsigned int Get_DISPLAY_SR_MODE(void);

unsigned int Get_DISPLAY_SR_PIXEL_MODE(void);

unsigned int Get_DISPLAY_SFG_SEG_NUM(void);

unsigned int Get_DISPLAY_SFG_PORT_NUM(void);

unsigned int Get_DISPLAY_PANEL_TYPE(void);

unsigned int Get_DISPLAY_PANEL_CUSTOM_INDEX(void);

unsigned char Get_PANEL_3D_PR_TO_SG_OUTPUT_FRC_ENABLE(void);

void Panel_2k1k_table_sel(UINT8 table);

unsigned char Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES(void);
unsigned char Get_PANEL_TYPE_IS_VBY1_OUTPUT_4K2K_SERIES(void);
unsigned char Get_PANEL_3D_TIMING_TYPE(void);
unsigned char Get_PANEL_TYPE_IS_USED_TCON_CONTROL(void);
unsigned char Get_DISPLAY_Is_Dynamic_DisplayTiming(void);
unsigned int Get_DISPLAY_PANEL_OLED_TYPE(void);
unsigned int Get_DISPLAY_PANEL_MPLUS_RGBW(void);
unsigned int Get_DISPLAY_PANEL_BOW_RGBW(void);
unsigned short Get_PANEL_BACKLIGHT_PWM_FREQ(void);

//	backlight API

typedef enum _BACKLIGHT_MODE{
	BACKLIGHT_USER,
	BACKLIGHT_DCR,
	BACKLIGHT_OPC,
}BACKLIGHT_MODE;

typedef enum _DISPLAY_SR_MODE{
	SR_H2_V2=0,
	SR_H1_V2,
	SR_H2_V1,
	SR_BYPASS,
}DISPLAY_SR_MODE;

typedef enum _DISPLAY_PIXEL_MODE{
	PIXEL_MODE_1_PIXEL=0,
	PIXEL_MODE_2_PIXEL,
	PIXEL_MODE_4_PIXEL,
}DISPLAY_PIXEL_MODE;

typedef enum{
    _INPUT_2K_1K = 0,
    _INPUT_4K_1K,
    _INPUT_4K_2K,
    _INPUT_UNDEFINE,
} MILLET_I2C_INPUT_FORMAT;

typedef enum{
    _BACKLIGHT_STR_CTRL_MODE_BY_KERNEL = 0,
    _BACKLIGHT_STR_CTRL_MODE_BY_AP,
} _BACKLIGHT_STR_CTRL_MODE;

void Panel_Set_STR_BackLight_Ctrl_Mode(unsigned char enable);
unsigned char Panel_Get_STR_BackLight_Ctrl_Mode(void);
unsigned char Panel_SetBackLightMode(unsigned char enable);
unsigned char Panel_SetPanelOnOff(unsigned char enable);
unsigned char Panel_SetBackLightLevel(BACKLIGHT_MODE mode,unsigned int level);
unsigned int Panel_GetBackLightLevel(void); // yf 20110704
unsigned char FAC_SetBackLightLevel(unsigned int level);
#if defined (BUILD_TV030_2)
unsigned char Panel_SetNatureLightBackLightLevel(unsigned int level);
#endif
/**
 * Panel_SetBackLightRange
 * mapping uiMax to actMax,uiMin to actMin,and use uiStep as step size when use Panel_SetBackLightLevel
 *
 * @param {uiMax : 0~255,default 100}
 * @param {uiMin : 0~255,default 0}
 * @param {uiMax : 0~255,default 255}
 * @param {uiMin : 0~255,default 0}
 * @return {TRUE/FALSE }
 *
 */
unsigned char Panel_SetBackLightMappingRange(unsigned int uiMax,unsigned int uiMin,unsigned int actMax,unsigned int actMin, unsigned char increaseMode);
unsigned char Panel_GetBackLightMappingRange(unsigned int *uiMax,unsigned int *uiMin,unsigned int *actMax,unsigned int *actMin, unsigned char *increaseMode);

void Panel_SetPwmDutyCbFunc(void (*callback)(UINT8 value));
void Panel_InitCbFunc(void (*callback)( void)); // skyworth yf 20111125
void Panel_TconControlCbFunc(void (*callback)(MILLET_I2C_INPUT_FORMAT)); // skyworth yf 20111125


void Panel_TurnOff(void);

void Panel_TurnOn(void);

typedef struct _PANEL_EX_SETTING {
	UINT8 *panelID;
	UINT8 *panelSetFileName;
	UINT8 *panelColorFileName;
}PANEL_EX_SETTING;

typedef struct _PANEL_EX_ALL_SETTING {
	int panelIDcount;
	int currentPanelID;
	PANEL_EX_SETTING *list;
}PANEL_EX_ALL_SETTING;

typedef enum {
	P_LVDS_2K1K_NO_DEFINED =0,
	P_IWATT7018_LG_42_SFK1=4,
	P_IWATT7018_LG_47_SFK1 =5
}LVDS_2K1K_PANEL_INDEX; //LVDS 2K1K PANEL_CUSTOM_INDEX;

typedef struct _STRUCT_PANEL_2K1K_COMMON_SETTING{
	UINT8     disp_2k1k_port;
	UINT32   disp_2k1k_clock_max;
	UINT32   disp_2k1k_clock_min;
	UINT32   disp_2k1k_clock_typical;
	UINT16   disp_2k1k_horizontal_total;
	UINT16   disp_2k1k_vertical_total;
	UINT16   disp_2k1k_vertical_total_50hz_min;
	UINT16   disp_2k1k_vertical_total_50hz_max;
	UINT16   disp_2k1k_vertical_total_60hz_min;
	UINT16   disp_2k1k_vertical_total_60hz_max;

	UINT16 disp_2k1k_hsync_width;
	UINT16 disp_2k1k_vsync_length;
	UINT16 disp_2k1k_den_sta_hpos;
	UINT16 disp_2k1k_den_end_hpos;
	UINT16 disp_2k1k_den_sta_vpos;
	UINT16 disp_2k1k_den_end_vpos;
	UINT16 disp_2k1k_act_sta_hpos;
	UINT16 disp_2k1k_act_end_hpos;
	UINT16 disp_2k1k_act_sta_vpos;
	UINT16 disp_2k1k_act_end_vpos;
	UINT16 disp_2k1k_hsync_lastline;
	UINT32 disp_2k1k_port_config1;
	UINT32 disp_2k1k_port_config2;
}STRUCT_PANEL_2K1K_COMMON_SETTING;
typedef enum {
	P_LVDS_2K1K,				//VDS output 2k1k timing only
	P_VBY1_4K2K,				//V By 1	 output 4k2k timing only
	P_LVDS_4K_2K_BOOTCODE_2K,	//LVDS output 4k2k and 2k1k timing, bootcode use 2k1k120
	P_LVDS_4K_2K_BOOTCODE_4K,	//LVDS output 4k2k and 2k1k timing, bootcode use 4k2k30
	P_EPI_TYPE,
	P_LVDS_TO_HDMI,
	P_DISP_TO_TVOX,
	P_MINI_LVDS,
	P_VBY1_TO_LVDS,
	P_VBY1_TO_HDMI,
	P_VBY1_TO_LVDS_2K,
	P_LVDS_2K1K_300MHZ,
	P_RESERVED
}PANEL_TYPE;
typedef enum {
	PANNEL_DYNAMIC_TABLE_DEFAULT_M3 = 0,
	PANNEL_DYNAMIC_TABLE_PA168,
	PANNEL_DYNAMIC_TABLE_M3_P1032,
	PANNEL_DYNAMIC_TABLE_INX8903,
	PANNEL_DYNAMIC_TABLE_M4,
	PANNEL_DYNAMIC_TABLE_MAX
}PANEL_DYNAMIC_PARAMETER_TABLE_INDEX;	//PANEL_CUSTOM_INDEX;
typedef enum {
	VBY_ONE_PANEL_INX8903_4K2K_600M_1S_8L,
	VBY_ONE_PANEL_LG_4K2K_600M_1S_8L,
	VBY_ONE_PANEL_CHINASTAR_4K2K_600M_2S_8L,
	VBY_ONE_PANEL_LG_4K2K_120HZ_1S_16L,
	VBY_ONE_PANEL_LG_4K2K_120HZ_4S_16L,
	VBY_ONE_PANEL_innolux_4K2K_600M_1S_8L,

	/* 4k2k30 / 2k1k120 dynamic output timing series*/
	DYNAMIC_OUTPUT_PANEL_SERIES_BEGIN=0x20,
	P_M3_CMI_55,		// Millet3 + CMI 55" 4k2k panel
	P_M3_CMI_55_P1032,	// Millet3 + Skyworth CMI 55" 4k2k panel
	P_SKY_V420DK1_LS1,
	P_SKY_V500DK2_LS1,
	VBY_ONE_PANEL_INX8903_4K2K_VBY1,
	VBY_ONE_PANEL_INX8901_4K2K_VBY1,		// Millet4
	VBY_ONE_PANEL_INX8922_4K2K_VBY1,
	P_M4_Default_4k2k,
	P_M4_Default_2k1k,
	P_PA168_AU_55,
	DYNAMIC_OUTPUT_PANEL_SERIES_MAX=0x60,

	P_EPI_LG_47_ART5,
	P_EPI_LG_43_4K2K,
	P_EPI_LG_49_4K2K,
	P_EPI_LG_65_4K2K,
	/* MPLUS RGBW IP*/
	P_EPI_LG_MPLUS_RGBW_PANEL_BEGIN=0x81,
	P_EPI_LG_LC430DGG_UHD60_12LANE,	
	P_EPI_LG_LC430EGG_UHD60_6LANE,
	P_EPI_LG_LC550EGG_UHD60_6LANE,
	P_EPI_LG_LC490EGG_UHD60_6LANE,
	P_EPI_LG_MPLUS_RGBW_PANEL_MAX=0xA0,
	/* BOE RGBW IP*/
	P_CEDS_LG_BOE_RGBW_PANEL_BEGIN=0xA1,	
	P_CEDS_LG_HV430QUB_UHD60_12LANE,
	P_CEDS_LG_HV490QUB_UHD60_12LANE,
	P_CEDS_LG_HV550QUB_UHD60_12LANE,
	P_CEDS_LG_BOE_RGBW_PANEL_MAX=0xB0, 
}PANEL_CUSTOM_INDEX;	//PANEL_CUSTOM_INDEX;
typedef enum {
	_3D_TIMING_2K1K_60,
	_3D_TIMING_2K05K120,
	_3D_TIMING_2K05K240,
	_3D_TIMING_2K1K_120,
	_3D_TIMING_2K1K_240,
	_3D_TIMING_4K1K_120,
	_3D_TIMING_4K05K_240,
	_3D_TIMING_4K1K_240,
	_3D_TIMING_4K2K_120,
}PANEL_3D_TIMING_INDEX;

//USER: Vincent_Lee  DATE: 2012/4/28  TODO: Add TCON for open cell panel
void Panel_Tcon_Init(void);
//USER: Vincent_Lee  DATE_2012_5_18  TODO: Add soft I2C for Gamma IC control (BUF_16821)
void Panel_Gamma_Init(void);
//void Panel_SetBackLightBlock(bool YesNo);
UINT8 Panel_LVDS_To_Hdmi_Converter_Parameter(void);

void Panel_releaseParameter(void);
unsigned char Get_MEMC_Enable_Dynamic(void);

typedef struct _STRUCT_PANEL_SPECIAL_SETTING{
	UINT16 VTypPeriod60Hz;	/** panel Vertical Period for NTSC*/
	UINT8 VSyncWidth60Hz;	/** panel Vertical Sync Width for NTSC*/
	UINT8 VBackPorch60Hz;	/** panel Vertical Back Porch for NTSC*/
	UINT8 HSyncWidth60Hz;	/** panel Horizontal Sync Width for NTSC*/
	UINT8 HBackPorch60Hz;	/** panel Horizontal Back Porch for NTSC*/
	UINT16 VTypPeriod50Hz;	/** panel Vertical Period for PAL*/
	UINT8 VSyncWidth50Hz;	/** panel Vertical Sync Width for PAL*/
	UINT8 VBackPorch50Hz;	/** panel Vertical Back Porch for PAL*/
	UINT8 HSyncWidth50Hz;	/** panel Horizontal Sync Width for PAL*/
	UINT8 HBackPorch50Hz;	/** panel Horizontal Back Porch for PAL*/
	UINT16 VTypPeriod48Hz;	/** panel Vertical Period for 48Hz*/
	UINT8 VSyncWidth48Hz;	/** panel Vertical Sync Width for 48Hz*/
	UINT8 VBackPorch48Hz;	/** panel Vertical Back Porch for 48Hz*/
	UINT8 HSyncWidth48Hz;	/** panel Horizontal Sync Width for 48Hz*/
	UINT8 HBackPorch48Hz;	/** panel Horizontal Back Porch for 48Hz*/
}STRUCT_PANEL_SPECIAL_SETTING;

#ifdef __cplusplus
}
#endif

#endif // __PANEL_API_H__
