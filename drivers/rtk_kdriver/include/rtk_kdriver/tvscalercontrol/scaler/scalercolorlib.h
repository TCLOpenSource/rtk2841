#ifndef __SCALERCOLOR_LIB_H__
#define __SCALERCOLOR_LIB_H__

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


/*******************************************************************************
* Macro
******************************************************************************/
/*#define MID_EXAMPLE(1)*/ /* Debug Message switch */
#define NOT_BY_DISPLAY 							0
#define BY_DISPLAY 								1


/*******************************************************************************
* Constant
******************************************************************************/
/*#define example  100000*/ /* 100Khz */

#define SCALERLIB_PatternColor_OFF		0
#define SCALERLIB_PatternColor_RED		1
#define SCALERLIB_PatternColor_GREEN	2
#define SCALERLIB_PatternColor_BLUE		3
#define SCALERLIB_PatternColor_WHITE	4
#define SCALERLIB_PatternColor_BLACK	5
#define SCALERLIB_PatternColor_COLORBAR	6
#define SCALERLIB_PatternColor_GRAYBAR	7
/*yanger20130114 modify for factory string command>*/
#ifdef CONFIG_ENABLE_COMPAL_LA_FACTORY_STRING_COMMAND
#define SCALERLIB_PatternColor_GRAY_25P	8
#define SCALERLIB_PatternColor_GRAY_50P	9
#endif
/*yanger20130114 modify for factory string command<*/

#define SCALERLIB_PatternColor_DCC_ON	254
#define SCALERLIB_PatternColor_DCC_OFF	255
#ifdef ENABLE_FACTORY_FUNCTIONS_TCL /*hardy20121212*/
#define SCALERLIB_PatternColor_YELLOW	8
#define SCALERLIB_PatternColor_GRAY	9
#endif

#define RTK_PQ_demo_mode	1


/*******************************************************************************
 * Structure
 ******************************************************************************/
/*typedef struct*/
/*{*/
/*} MID_example_Param_t;*/


/*******************************************************************************
* enumeration
******************************************************************************/
/*typedef enum*/
/*{*/
/*    MID_Example_SLEEPING = 0,*/
/*    MID_Example_RUNNING,*/
/*} MID_Example_Status_t;*/

enum _source_TV05_index {
	_SOURCE_INDEX_TV05_VGA,
	_SOURCE_INDEX_TV_NTSC,
	_SOURCE_INDEX_TV_PAL,
	_SOURCE_INDEX_TV_SECAM,
	_SOURCE_INDEX_AVSV_NTSC,
	_SOURCE_INDEX_AVSV_PAL,
	_SOURCE_INDEX_AVSV_SECAM,
	_SOURCE_INDEX_YPBPR_SD,
	_SOURCE_INDEX_YPBPR_HD,
	_SOURCE_INDEX_HDMI_SD,
	_SOURCE_INDEX_HDMI_HD,
	_PCB_SOURCE_TV05_TOTAL_NUM
};


typedef enum _COLOR_CALLBACK_TYPE {

	COLOR_CALLBACK_GET_QUALITY_COEF = 0,
	COLOR_CALLBACK_GET_QUALITY_EXTEND,
	COLOR_CALLBACK_GET_QUALITY_EXTEND2,
	COLOR_CALLBACK_GET_QUALITY_EXTEND3,
	COLOR_CALLBACK_GET_QUALITY_EXTEND4,
	COLOR_CALLBACK_GET_QUALITY_3Dmode,
	COLOR_CALLBACK_GET_COLOR_DATA,
	COLOR_CALLBACK_GET_COLOR_FAC_MODE,
	COLOR_CALLBACK_GET_COLOR_TEMP_DATA,
	COLOR_CALLBACK_GET_COLOR_TEMP_DATA_TSB,
	COLOR_CALLBACK_GET_COLOR_TEMP_LEVEL,
	COLOR_CALLBACK_GET_PICTURE_MODE_DATA,
	COLOR_CALLBACK_GET_DNR_MODE,

	COLOR_CALLBACK_GET_CURPICMODE,
	COLOR_CALLBACK_GET_ICM_BY_TIMING_PICMODE,	/*Elsie 20131224*/

} COLOR_CALLBACK_TYPE;
#if 0
typedef enum _SLR_SLR_ACTIVE_BACKLIGHT {
	SLR_BlackAPL_a_HSCA	= 0,
	SLR_BlackAPL_b_HSCB,
	SLR_BlackAPL_c_HSCC,
	SLR_BlackAPL_d_HSCD,
	SLR_BlackAPL_e_HSCE,
	SLR_BlackAPL_f_HSCF,
	SLR_BlackAPL_g_HSCG,
	SLR_BlackAPL_h_HSCH,
	SLR_BlackAPL_BL_Th1_SABH,
	SLR_BlackAPL_BL_Th1_SABL,
	SLR_BlackAPL_BL_Th2_EABH,
	SLR_BlackAPL_BL_Th2_EABL,
	SLR_BlackAPL_BL_Th3_MLBL,
	SLR_BlackAPL_M_ATAB,
	SLR_BlackAPL_KU_USAB,
	SLR_BlackAPL_KD_DSAB,
	SLR_APL_BL_MAX,
	SLR_APL_BL_MIN,
	SLR_ACTIVE_BACKLIGHT_ALL,
} SLR_ACTIVE_BACKLIGHT;
#endif

typedef enum _MAGIC_FUNCTION_TYPE {
	MAGIC_IN_FUNCTION = 0,
	MAGIC_EXIT_FUNCTION,
} MAGIC_FUNCTION_TYPE;

typedef enum _SLR_MAGIC_TYPE {
	SLR_MAGIC_OFF,
	SLR_MAGIC_STILLDEMO,
	SLR_MAGIC_STILLDEMO_INVERSE,
	SLR_MAGIC_FULLSCREEN,
	SLR_MAGIC_DYNAMICDEMO,
	SLR_MAGIC_MOVE,
	SLR_MAGIC_MOVE_INVERSE,
	SLR_MAGIC_ZOOM,
	SLR_MAGIC_OPTIMIZE,
	SLR_MAGIC_ENHANCE,
} SLR_MAGIC_TYPE;

typedef struct StructMagicPicInfo {
	unsigned char	magic_picture;
	unsigned char	magic_direction;
	unsigned char	magic_step;
	unsigned char	magic_parameter;
	short	magic_XStart;
	short	magic_YStart;
	short	magic_XEnd;
	short	magic_YEnd;
	short	magic_XStartForDynamic;
	short	magic_YStartForDynamic;
	short	magic_XEndForDynamic;
	short	magic_YEndForDynamic;
	int	magic_DISP_WID_OSD;
	unsigned char	pre_magic_pic;
} StructMagicPicInfo;

typedef enum {
	HDMI_CSC_DATA_RANGE_MODE_AUTO = 0x0,
	HDMI_CSC_DATA_RANGE_MODE_FULL,
	HDMI_CSC_DATA_RANGE_MODE_LIMITED,
} HDMI_CSC_DATA_RANGE_MODE_T;

/*******************************************************************************
* Variable
******************************************************************************/
/*static unsigned char gExample = 100000;*/ /* 100K */



/*******************************************************************************
* Program
******************************************************************************/


/*o---------------------------------------------------------------------------o*/
/*o-------------Scalercolor.cpp------------------------------------o*/
/*o---------------------------------------------------------------------------o*/


/*==================== Definitions ================= */


typedef void *(*COLOR_CALLBACK_FUNC1)(VIP_SOURCE_TIMING source_timing);
typedef void *(*COLOR_CALLBACK_FUNC2)(unsigned int pcbSourceIndex, unsigned int timing, unsigned int param);
typedef int (*COLOR_CALLBACK_FUNC3)(void);
typedef unsigned char (*COLOR_CALLBACK_FUNC4)(unsigned char picMode);	/*Elsie 20131224*/
typedef void *(*COLOR_CALLBACK_FUNC5)(VIP_3DSOURCE_TIMING source_timing);

/*USER: Vincent_Lee  DATE: 2011/10/26  TODO: calcu sat by factory data*/
StructColorDataType *fwif_color_get_color_data(unsigned char src_idx, unsigned char timing);
StructColorDataFacModeType *fwif_color_get_color_fac_mode(unsigned char src_idx, unsigned char timing);
StructColorDataFacModeType *fwif_color_get_color_fac_mode_by_picture(unsigned char src_idx, unsigned char timing, unsigned char pic);

void *fwif_color_get_picture_mode_data(unsigned char src_idx, unsigned char value);
unsigned char fwif_color_get_picture_mode(unsigned char src_idx);


UINT8 fwif_vip_Get_Input_DataArrayIndex(UINT8 display);

unsigned char fwif_color_get_backlight(unsigned char src_idx);
void fwif_color_set_backlight(unsigned char src_idx, unsigned char value);
void fwif_color_set_backlight_TPV(unsigned char src_idx, unsigned char value);
unsigned char Scaler_Set_Gamma_level(unsigned char value);
void scaler_set_color_temp_level(SLR_COLORTEMP_LEVEL level);

unsigned char scaler_get_color_temp_level_type(unsigned char src_idx);
SLR_COLORTEMP_DATA *scaler_get_color_tempset(unsigned char src_idx, unsigned char timing);

unsigned char fwif_color_get_color_temp_level_type_using_colortmp(unsigned char colortmp);
void fwif_color_set_color_temp_level_type_using_colortmp(unsigned char colortmp, unsigned char value);

unsigned short fwif_color_get_color_temp_r_type_using_colortmp(unsigned char colortmp);
void fwif_color_set_color_temp_r_type_using_colortmp(unsigned char colortmp, unsigned short value);

unsigned short fwif_color_get_color_temp_g_type_using_colortmp(unsigned char colortmp);
void fwif_color_set_color_temp_g_type_using_colortmp(unsigned char colortmp, unsigned short value);

unsigned short fwif_color_get_color_temp_b_type_using_colortmp(unsigned char colortmp);
void fwif_color_set_color_temp_b_type_using_colortmp(unsigned char colortmp, unsigned short value);

unsigned short fwif_color_get_color_temp_r_offset_using_colortmp(unsigned char colortmp);
void fwif_color_set_color_temp_r_offset_using_colortmp(unsigned char colortmp, unsigned short value);
unsigned short fwif_color_get_color_temp_g_offset_using_colortmp(unsigned char colortmp);
void fwif_color_set_color_temp_g_offset_using_colortmp(unsigned char colortmp, unsigned short value);
unsigned short fwif_color_get_color_temp_b_offset_using_colortmp(unsigned char colortmp);
void fwif_color_set_color_temp_b_offset_using_colortmp(unsigned char colortmp, unsigned short value);




#if (defined (PQ_005_STYLE))/*yuan::20130624*/
unsigned char fwif_color_get_autoNR(unsigned char src_idx);/*yuan20130314::add for Auto_NR by picture mode*/
void fwif_color_set_autoNR(unsigned char src_idx, unsigned char value);
void fwif_color_tsb_set_NR_setting(unsigned char src_idx, unsigned char value);

#endif
unsigned char Scaler_get_i_dcti(void);
void Scaler_set_i_dcti(unsigned char src_idx, unsigned char value);


unsigned char fwif_color_get_MpegNR_Level(unsigned char  src_idx);
void fwif_color_set_MpegNR_Level(unsigned char  src_idx, unsigned char  value);

unsigned char fwif_color_get_MpegNR_H(unsigned char  src_idx);
void fwif_color_set_MpegNR_H(unsigned char  src_idx, unsigned char  value);

unsigned char fwif_color_get_MpegNR_V(unsigned char  src_idx);
void fwif_color_set_MpegNR_V(unsigned char  src_idx, unsigned char  value);

unsigned char fwif_color_get_nrspatial(unsigned char src_idx);
void fwif_color_set_nrspatial(unsigned char src_idx, unsigned char value);

void fwif_color_set_SR_edge_gain(unsigned char src_idx, unsigned char value);
void fwif_color_set_SR_texture_gain(unsigned char src_idx, unsigned char value);
void fwif_color_set_SR_driver(unsigned char item_idx, unsigned char value);

void fwif_color_set_Vertical_NR_driver(unsigned char src_idx, unsigned char value);
void fwif_color_set_HMCNR_driver(unsigned char src_idx, unsigned char value);

void fwif_color_set_HMCNR_blending_driver(unsigned char src_idx, unsigned char value);

unsigned char fwif_color_get_dcc_level(unsigned char src_idx);
void fwif_color_set_dcc_level(unsigned char src_idx, unsigned char value, unsigned char SceneChange);
#if 0
void fwif_color_set_active_backlight_table(unsigned char src_idx, unsigned char item, unsigned char value);
#endif

void fwif_color_set_i_ccoring_driver(unsigned char src_idx, unsigned char value);

void fwif_color_set_d_ccoring_driver(unsigned char src_idx, unsigned char value);

unsigned char fwif_color_get_grid_remove(unsigned char src_idx);
void fwif_color_set_grid_remove(unsigned char src_idx, unsigned char value);

unsigned char fwif_color_get_conti_still_line(unsigned char src_idx);
void fwif_color_set_conti_still_line(unsigned char src_idx, unsigned char value);



unsigned char fwif_color_get_senselight(unsigned char src_idx);
void fwif_color_set_senselight(unsigned char src_idx, unsigned char value);

unsigned char fwif_color_get_spread_spectrum(unsigned char src_idx);
void fwif_color_set_spread_spectrum(unsigned char src_idx, unsigned char value);
void fwif_set_dcr_panasonic_apply(unsigned char value);
unsigned char fwif_get_dcr_panasonic(void);
void fwif_set_dcr_panasonic(unsigned char value);
unsigned char fwif_color_get_vip_debug_mode(unsigned char src_idx);
void fwif_color_set_vip_debug_mode(unsigned char src_idx, unsigned char value);

void *fwif_color_get_cur_picture_mode_data(unsigned char src_idx);

void fwif_set_ColorMatrix(bool value);


/*=========================================================*/


/*==================== Functions ================== */
/*void fwif_color_set_bg_color(unsigned char disp, unsigned char r, unsigned char g, unsigned char b);*/
/*void fwif_color_seticmhuesat(unsigned char display);*/

void fwif_color_setcontrastbrightness(unsigned char display);
#if defined(CONFIG_TTX_TOSHIBA_PATCH)
void fwif_color_setcontrastbrightness_half(unsigned char display, BOOL sRGB_User_Sat_En, BOOL sRGB_User_Sat_Mapping);
#endif


void fwif_color_rtnr_adjust(unsigned char channel, unsigned char osd_level);
/*void fwif_color_TSB_rtnr_y_adjust(unsigned char channel, unsigned char level);*/
void fwif_color_rtnr_of_snr_adjust(unsigned char channel, unsigned char level);
/*void fwif_color_TSB_rtnr_c_adjust(unsigned char channel, unsigned char level);*/
void fwif_color_VD_adjust(unsigned char channel, unsigned char level);

/*rock_rau	20130227 mark not use function*/ /**/
/*void fwif_color_noisereduction_spatial(unsigned char channel, unsigned char level, unsigned char bNoiseReductionMode);*/
void fwif_color_video_quality_handler(void);
void fwif_color_video_3Dmode_quality_handler(void);/*young 3Dtable*/

void fwif_color_sync_rtnr(void);
void fwif_color_sync_dnr(void);
unsigned char fwif_color_reg_callback1(COLOR_CALLBACK_TYPE type, COLOR_CALLBACK_FUNC1 cbFunc);
unsigned char fwif_color_reg_callback2(COLOR_CALLBACK_TYPE type, COLOR_CALLBACK_FUNC2 cbFunc);
unsigned char fwif_color_reg_callback3(COLOR_CALLBACK_TYPE type, COLOR_CALLBACK_FUNC3 cbFunc);
unsigned char fwif_color_reg_callback4(COLOR_CALLBACK_TYPE type, COLOR_CALLBACK_FUNC4 cbFunc);	/*Elsie 20131224*/
unsigned char fwif_color_reg_callback5(COLOR_CALLBACK_TYPE type, COLOR_CALLBACK_FUNC5 cbFunc);/*young 3Dtable*/
/*char fwif_color_isUSBSource(void);*/

unsigned char drvif_color_regRtnrycTable(unsigned int *ptr);    /*20100817 added by Leo Chen*/

void fwif_ByPass_IDomainToMem(void); /* adc dump*/

#if 0
#ifdef OPEN_CELL_PANEL
UINT32 drvif_ODTable(UINT32 *ptr);    /*young vippanel*/
UINT32 drvif_OD_disable(void);
void drvif_ODEnable(void);
#endif
#else
UINT32 drvif_ODTable(UINT32 *ptr);    /*young vippanel*/
#endif

int fwif_color_get_cur_picMode(void); /* return PICTURE_MODE*/
unsigned char fwif_vip_HDR10_check(unsigned char display, unsigned char input_src_type);
unsigned char fwif_vip_DolbyHDR_check(unsigned char display, unsigned char input_src_type);
unsigned char fwif_vip_source_check(unsigned char display, unsigned char callmode);
unsigned char fwif_vip_3Dsource_check(unsigned char display, unsigned char callmode);/*young 3Dtable*/
void *fwif_color_get_VIP_Extend2_CoefArray(unsigned char src_idx);
#if 0
VIP_QUALITY_Extend3_Coef *fwif_color_get_VIP_Extend3_CoefArray(unsigned char src_idx);
VIP_QUALITY_3Dmode_Coef *fwif_color_get_VIP_3Dmode_CoefArray(unsigned char src_idx);/*young 3Dtable*/
VIP_QUALITY_Extend4_Coef *fwif_color_get_VIP_Extend4_CoefArray(unsigned char src_idx);
#endif

UINT16 COsdCtrlGet_R_Drive_RDRV(void);
UINT16 COsdCtrlGet_G_Drive_GDRV(void);
UINT16 COsdCtrlGet_B_Drive_BDRV(void);

void COsdCtrlSet_R_Drive_RDRV(UINT16  Message);
void COsdCtrlSet_G_Drive_GDRV(UINT16  Message);
void COsdCtrlSet_B_Drive_BDRV(UINT16  Message);

/*RGB cutoff base on 512 for cool, RGB offset = RGB cutoff + 512*/
INT8 COsdCtrlGet_R_CUTOFF_RCUT(void);
void COsdCtrlSet_R_CUTOFF_RCUT(UINT16  Message);
INT8 COsdCtrlGet_G_CUTOFF_GCUT(void);
void COsdCtrlSet_G_CUTOFF_GCUT(UINT16  Message);
INT8 COsdCtrlGet_B_CUTOFF_BCUT(void);
void COsdCtrlSet_B_CUTOFF_BCUT(UINT16  Message);

/*RGB drive offset for Natural*/
/*RGB drive for natural = RGB drive for cool + RGB drive offset for Natural*/
INT8 COsdCtrlGet_R_Drive_Offset_Natural_RDON(void);
void COsdCtrlSet_R_Drive_Offset_Natural_RDON(UINT16  Message);
INT8 COsdCtrlGet_G_Drive_Offset_Natural_GDON(void);
void COsdCtrlSet_G_Drive_Offset_Natural_GDON(UINT16  Message);
INT8 COsdCtrlGet_B_Drive_Offset_Natural_BDON(void);
void COsdCtrlSet_B_Drive_Offset_Natural_BDON(UINT16  Message);

/*RGB cutoff for natural = RGB cutoff for cool + RGB cutoff offset for natural*/
INT8 COsdCtrlGet_R_CUTOFF_Offset_Natural_RCON(void);
void COsdCtrlSet_R_CUTOFF_Offset_Natural_RCON(UINT16  Message);
INT8 COsdCtrlGet_G_CUTOFF_Offset_Natural_GCON(void);
void COsdCtrlSet_G_CUTOFF_Offset_Natural_GCON(UINT16  Message);
INT8 COsdCtrlGet_B_CUTOFF_Offset_Natural_BCON(void);
void COsdCtrlSet_B_CUTOFF_Offset_Natural_BCON(UINT16  Message);

/*RGB drive offset for Warm*/
/*RGB drive for Warm = RGB drive for cool + RGB drive offset for Warm*/
INT8 COsdCtrlGet_R_Drive_Offset_Warm_RDOW(void);
void COsdCtrlSet_R_Drive_Offset_Warm_RDOW(UINT16  Message);
INT8 COsdCtrlGet_G_Drive_Offset_Warm_GDOW(void);
void COsdCtrlSet_G_Drive_Offset_Warm_GDOW(UINT16  Message);
INT8 COsdCtrlGet_B_Drive_Offset_Warm_BDOW(void);
void COsdCtrlSet_B_Drive_Offset_Warm_BDOW(UINT16  Message);

/*RGB cutoff for Warm = RGB cutoff for cool + RGB cutoff offset for Warm*/
INT8 COsdCtrlGet_R_CUTOFF_Offset_Warm_RCOW(void);
void COsdCtrlSet_R_CUTOFF_Offset_Warm_RCOW(UINT16  Message);
INT8 COsdCtrlGet_G_CUTOFF_Offset_Warm_GCOW(void);
void COsdCtrlSet_G_CUTOFF_Offset_Warm_GCOW(UINT16  Message);
INT8 COsdCtrlGet_B_CUTOFF_Offset_Warm_BCOW(void);
void COsdCtrlSet_B_CUTOFF_Offset_Warm_BCOW(UINT16  Message);


void drvif_color_auto_timer_BrightnessBoost(void);
void drvif_color_VIP_Hist_Upadte(void);

void  Scaler_icm_enhancement(unsigned char value);
void  Scaler_ChannelColourSet(signed char value);

/*===add for haier 20111210 by lichun zhao======*/
#if defined(TV013UI_1) || defined(BUILD_TV013_1_ATV)
void fwif_set_color_management(unsigned char mode);
#endif


void fwif_color_3DPQ_enhance(unsigned char enable);


void Scaler_set_correcionBit1_duty_Debug(unsigned char value);

/*===================================================================================== */ /*DCC CSFC 20140127*/
/*              DCC*/

/*o---About histogram ----o*/
unsigned int Scaler_VIP_Hist_Upadte(void);

/*o--- source table----o*/
unsigned char Scaler_GetDCC_Table(void);
void Scaler_SetDCC_Table(unsigned char value);

/*o--- picture mode----o*/
unsigned char Scaler_GetDCC_Mode(void);
unsigned char  Scaler_SetDCC_Mode(unsigned char value);
unsigned char Scaler_SetDCC_HAL_FreshContrast(unsigned char display , unsigned char uDCMode, UINT32 pstData);


/*o--- table cync. to video ---oo*/
unsigned char Scaler_Get_DCC_Boundary_Check_Table(void);
void Scaler_Set_DCC_Boundary_Check_Table(unsigned char value);
unsigned char Scaler_Get_DCC_Level_and_Blend_Coef_Table(void);
void Scaler_Set_DCC_Level_and_Blend_Coef_Table(unsigned char value);
void Scaler_Set_DCC_hist_adjust_table(unsigned char value);
unsigned char Scaler_Get_DCC_hist_adjust_table(void);
unsigned char Scaler_Get_DCC_database_Table(void);
void Scaler_Set_DCC_database_Table(unsigned char value);
unsigned char Scaler_Get_DCC_UserCurve_Table(void);
void Scaler_Set_DCC_UserCurve_Table(unsigned char value);
unsigned char Scaler_Get_DCC_AdaptCtrl_Level_Table(void);
void Scaler_Set_DCC_AdaptCtrl_Level_Table(unsigned char value);
unsigned char Scaler_Get_DCC_Picture_Mode_Weight(void);
void Scaler_Set_DCC_Picture_Mode_Weight(int value);

/*o---sync. level and coef base  to video ---o*/
unsigned char Scaler_GetDCL_W(void);
void Scaler_SetDCL_W(int value);
unsigned char Scaler_GetDCL_B(void);
void Scaler_SetDCC_B_extend(int value);
unsigned char Scaler_GetDCC_W_extend(void);
void Scaler_SetDCL_B(int value);
unsigned char Scaler_GetDCC_B_extend(void);
void Scaler_SetDCC_W_extend(int value);
unsigned char Scaler_Get_DCC_DelayTime(void);
void Scaler_Set_DCC_DelayTime(unsigned char flag);
unsigned char Scaler_Get_DCC_Step(void);
void Scaler_Set_DCC_Step(unsigned char flag);

/*o--- sync. table coef. that is non-adaptive table base API to video ---o*/
unsigned char Scaler_Get_Dcc_histogram_gain(unsigned char bin_num);
void Scaler_Set_Dcc_histogram_gain(unsigned char bin_num, unsigned char value, unsigned char SceneChange);
unsigned char Scaler_Get_Dcc_histogram_offset(unsigned char bin_num);
void Scaler_Set_Dcc_histogram_offset(unsigned char bin_num, unsigned char value, unsigned char SceneChange);
unsigned char Scaler_Get_Dcc_histogram_limit(unsigned char bin_num);
void Scaler_Set_Dcc_histogram_limit(unsigned char bin_num, unsigned char value, unsigned char SceneChange);

/*o--- non-adaptive table coef sync. when table change---o*/
void Scaler_set_dcc_sync_histogram_adjust_table(unsigned char src_idx, unsigned char Tabel_sel);/*for histogram adjus table*/

void Scaler_set_dcc_Sync_DCC_AP_Level(unsigned char src_idx, unsigned char Tabel_sel, unsigned char Mode_sel);/* for  DCC_Table change*/
void Scaler_set_dcc_Sync_DCC_Video_Driver_Level(unsigned char src_idx);/*for DCC DCC_Table change*/

UINT32 Scaler_get_DCC_AdapCtrl_Current_Mean(void);
UINT32 Scaler_get_DCC_AdapCtrl_Current_Dev(void);
VIP_DCC_AdaptCtrl_Level_Table *Scaler_get_DCC_AdapCtrl_Table(void);
unsigned char Scaler_get_DCC_AdapCtrl_DCC_Level(void);
BOOL Scaler_set_DCC_AdapCtrl_DCC_Level(UINT8 value);
unsigned char Scaler_get_DCC_AdapCtrl_Cubic_index(void);
BOOL Scaler_set_DCC_AdapCtrl_Cubic_index(UINT8 value);
unsigned char Scaler_get_DCC_AdapCtrl_Cubic_low(void);
BOOL Scaler_set_DCC_AdapCtrl_Cubic_low(UINT8 value);
unsigned char Scaler_get_DCC_AdapCtrl_Cubic_high(void);
BOOL Scaler_set_DCC_AdapCtrl_Cubic_high(UINT8 value);


/*o--- sync. table coef. that is adaptive by vide fw ---o*/

#if 0
/* mark those API, because control method change to tool control*/
unsigned char Scaler_GetDccLevel(void);
void Scaler_SetDccLevel(unsigned char value, unsigned char SceneChange);
unsigned char Scaler_GetDCC_Shigh(void);
void Scaler_SetDCC_Shigh(int value);
unsigned char Scaler_GetDCC_Slow(void);
void Scaler_SetDCC_Slow(int value);
unsigned char Scaler_GetDCC_Sindex(void);
void Scaler_SetDCC_Sindex(int value);
#endif

/*===================================================================================== */ /*DCC CSFC 20140128*/

/*===================================================================================== */ /*ConBri CSFC 20140128*/
#ifdef OSD_FOUR_LEVEL_MAPPING_ENABLE
unsigned char Scaler_GetFacBrightness(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100,
	unsigned char *retval_25, unsigned char *retval_75);
unsigned char Scaler_SetFacBrightness(unsigned char val_0, unsigned char val_50, unsigned char val_100,
	unsigned char val_25, unsigned char val_75);
unsigned char Scaler_GetFacContrast(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100,
	unsigned char *retval_25, unsigned char *retval_75);
unsigned char Scaler_SetFacContrast(unsigned char val_0, unsigned char val_50, unsigned char val_100,
	unsigned char val_25, unsigned char val_75);
#else
unsigned char Scaler_GetFacBrightness(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100);
unsigned char Scaler_SetFacBrightness(unsigned char val_0, unsigned char val_50, unsigned char val_100);
unsigned char Scaler_GetFacContrast(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100);
unsigned char Scaler_SetFacContrast(unsigned char val_0, unsigned char val_50, unsigned char val_100);
#endif

/* for tv 020 030*/
unsigned char Scaler_OsdMapToRegValue_Contrast(unsigned char display , unsigned char value);
unsigned char Scaler_OsdMapToRegValue_Brightness(unsigned char display , unsigned char value);

/*===================================================================================== */ /*ConBri CSFC 20140128*/

/*======================================================== hue /sat*/
unsigned char Scaler_GetIntensity(void);
void Scaler_SetIntensity(unsigned char value);

/* for tv 020 030*/
unsigned char Scaler_OsdMapToRegValue_Saturation(unsigned char display , unsigned char value);
unsigned char Scaler_OsdMapToRegValue_Hue(unsigned char display , unsigned char value);

#ifdef OSD_FOUR_LEVEL_MAPPING_ENABLE
unsigned char Scaler_GetFacSaturation(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100,
	unsigned char *retval_25, unsigned char *retval_75);
unsigned char Scaler_SetFacSaturation(unsigned char val_0, unsigned char val_50, unsigned char val_100,
	unsigned char val_25, unsigned char val_75);
unsigned char Scaler_GetFacHue(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100,
	unsigned char *retval_25, unsigned char *retval_75);
unsigned char Scaler_SetFacHue(unsigned char val_0, unsigned char val_50, unsigned char val_100,
	unsigned char val_25, unsigned char val_75);
#else
unsigned char Scaler_GetFacSaturation(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100);
unsigned char Scaler_SetFacSaturation(unsigned char val_0, unsigned char val_50, unsigned char val_100);
unsigned char Scaler_GetFacHue(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100);
unsigned char Scaler_SetFacHue(unsigned char val_0, unsigned char val_50, unsigned char val_100);
#endif

/*===================================================================================== */ /*PictureMode CSFC 20140128*/
/*void Scaler_SetPictureInfo(SCALER_DISP_CHANNEL display, SLR_PICTURE_INFO infoList, unsigned char value);*/
/*unsigned char Scaler_GetPictureInfo(SCALER_DISP_CHANNEL display, SLR_PICTURE_INFO  infoList);*/

void Scaler_ResetPictureQuality(SCALER_DISP_CHANNEL display);
/*void *Scaler_get_cur_picture_mode_data(unsigned char src_idx);*/
/*void *Scaler_get_picture_mode_data(unsigned char src_idx, unsigned char value);*/

void Scaler_RefreshPictureMode(void);

/*===================================================================================== */ /*ColorTemp CSFC 20140128*/
unsigned short Scaler_get_color_temp_r_type_using_colortmp(unsigned char colortmp);
void Scaler_set_color_temp_r_type_using_colortmp(unsigned char colortmp, unsigned short value);

unsigned short Scaler_get_color_temp_g_type_using_colortmp(unsigned char colortmp);
void Scaler_set_color_temp_g_type_using_colortmp(unsigned char colortmp, unsigned short value);

unsigned short Scaler_get_color_temp_b_type_using_colortmp(unsigned char colortmp);
void Scaler_set_color_temp_b_type_using_colortmp(unsigned char colortmp, unsigned short value);

unsigned short Scaler_get_color_temp_r_offset_using_colortmp(unsigned char colortmp);
void Scaler_set_color_temp_r_offset_using_colortmp(unsigned char colortmp, unsigned short value);
unsigned short Scaler_get_color_temp_g_offset_using_colortmp(unsigned char colortmp);
void Scaler_set_color_temp_g_offset_using_colortmp(unsigned char colortmp, unsigned short value);
unsigned short Scaler_get_color_temp_b_offset_using_colortmp(unsigned char colortmp);
void Scaler_set_color_temp_b_offset_using_colortmp(unsigned char colortmp, unsigned short value);

unsigned short Scaler_get_color_temp_r_type(unsigned char src_idx);
void Scaler_set_color_temp_r_type(unsigned char src_idx, unsigned short value);

unsigned short Scaler_get_color_temp_g_type(unsigned char src_idx);
void Scaler_set_color_temp_g_type(unsigned char src_idx, unsigned short value);

unsigned short Scaler_get_color_temp_b_type(unsigned char src_idx);
void Scaler_set_color_temp_b_type(unsigned char src_idx, unsigned short value);

unsigned short Scaler_get_color_temp_r_offset(unsigned char src_idx);
void Scaler_set_color_temp_r_offset(unsigned char src_idx, unsigned short value);
unsigned short Scaler_get_color_temp_g_offset(unsigned char src_idx);
void Scaler_set_color_temp_g_offset(unsigned char src_idx, unsigned short value);
unsigned short Scaler_get_color_temp_b_offset(unsigned char src_idx);
void Scaler_set_color_temp_b_offset(unsigned char src_idx, unsigned short value);

/*===================================================================================== */ /*ColorTemp CSFC 20140128*/


void Scaler_set_picmode_init_value(unsigned char item_index, unsigned short value);
int Scaler_set_picmode_init_sendRPC(void);


/*O================================================*/
/*O================================================*/
/*O================================================*/
unsigned short Scaler_GetICMTable(void);/* csfanchiang, 20101101*/

void Scaler_SetICMTable(unsigned char value);/* csfanchiang, 20101101*/

void Scaler_set_ICM_table_by_VipTable(void);


/*rock_rau	20130227 mark not use function*/ /**/
/*void Scaler_SetNRSpatial(unsigned char value);					*/ /*range 0~16*/
/*void Scaler_SetNoiseEstimation(unsigned char mode);			*/ /*range 0~1*/


/*void Scaler_SetDccMode(unsigned char value);*/


void Scaler_SetICMenhancement(unsigned char value);
unsigned char Scaler_GetGammaDebug(void);  /*add by Diane*/
void Scaler_SetGammaDebug(unsigned char value);						/*range 0~10  */ /*add by Diane*/
unsigned char Scaler_GetNormalWarm_80IRE(SLR_COLORTEMP_LEVEL colorTemp, int channel); /*add by Diane*/
unsigned char Scaler_GetNormalWarm_20IRE(SLR_COLORTEMP_LEVEL colorTemp, int channel);/*add by Diane*/
unsigned char Scaler_GetGainRed(void);   /*add by Diane*/
unsigned char Scaler_GetGainGreen(void);   /*add by Diane*/
unsigned char Scaler_GetGainBlue(void);   /*add by Diane*/
unsigned char Scaler_GetCenterRed(void);   /*add by Diane*/
unsigned char Scaler_GetCenterGreen(void);   /*add by Diane*/
unsigned char Scaler_GetCenterBlue(void);   /*add by Diane*/
unsigned char Scaler_GetInternalPattern(void);  /*add by Diane*/
void  Scaler_SetGainRed(unsigned char value);                                              /* range 0~255  */ /*add by Diane*/
void Scaler_SetGainGreen(unsigned char value);                                              /* range 0~255  */ /*add by Diane*/
void Scaler_SetGainBlue(unsigned char value);                                              /* range 0~255  */ /*add by Diane*/
void Scaler_SetCenterRed(unsigned char value);                                              /* range 0~255  */ /*add by Diane*/
void Scaler_SetCenterGreen(unsigned char value);                                              /* range 0~255  */ /*add by Diane*/
void Scaler_SetCenterBlue(unsigned char value);                                              /* range 0~255  */ /*add by Diane*/
void Scaler_SetInternalPattern(unsigned char value);						/*range 0~1  */ /*add by Diane*/

/*ravi_li add*/
#if defined BUILD_TV005_2
void Scaler_Set3DColorMatrix(BASECOLORADJ *colortable);
BASECOLORADJ *Scaler_Get3DColorMatrix(void);
#endif
/*end ravi_li*/

void scaler_set_PQA_Input_table(unsigned char value);
void scaler_set_PQA_table(unsigned char value);
unsigned char scaler_get_PQA_Input_table(void);
unsigned char scaler_get_PQA_table(void);

void Scaler_SetTableNRSpatial(unsigned char value);
unsigned char Scaler_GetTableNRSpatial(void);

unsigned char  Scaler_GetDNR_table(void);
/*void Scaler_SetDNR_table(unsigned char value, unsigned char calledByOSD=CALLED_NOT_BY_OSD);	*/ /* move "DNR table select info" to system_info_struct and replace by PQA table, elieli*/

void Scaler_SetDNR(unsigned char value);
unsigned char Scaler_GetDNR(void);
void Scaler_SetMPEGNR(unsigned char value, unsigned char calledByOSD);
unsigned char Scaler_GetMPEGNR(void);
DRV_RTNR_General_ctrl *Scaler_GetRTNR_General(void);
void Scaler_SetRTNR_Y(unsigned char value);
unsigned char Scaler_GetRTNR_Y(void);
void Scaler_SetRTNR_C(unsigned char value);
unsigned char Scaler_GetRTNR_C(void);
void Scaler_SetNRSpatialY(unsigned char value);
unsigned char Scaler_GetNRSpatialY(void);
void Scaler_SetNRSpatialC(unsigned char value);
unsigned char Scaler_GetNRSpatialC(void);
void Scaler_SetMpegNR_H(unsigned char value);
unsigned char Scaler_GetMpegNR_H(void);
void Scaler_SetMpegNR_V(unsigned char value);
unsigned char Scaler_GetMpegNR_V(void);
void Scaler_SetNRTemporal(unsigned char value);
unsigned char Scaler_GetNRTemporal(void);

#if defined (PQ_005_STYLE)
void Scaler_SetAutoNR(unsigned char value);
unsigned char Scaler_GetAutoNR(void);
#endif

void Scaler_OPC_Auto_Backlight_Adjust(void);

unsigned char drvif_vd_3d_ntsc_table(unsigned char *ptr);
unsigned char drvif_vd_3d_pal_table(unsigned char *ptr);
/*[option]*/
/*rock_rau	20130227 mark not use function*/ /**/
/*unsigned char Scaler_GetNRSpatial(void);*/
void Scaler_SetFacPatternColor(unsigned char val);

#ifdef ENABLE_SPEED_UP_SLR_DISPLAY_ON_FLOW
void Scaler_ResetPictureMode(void);
void Scaler_EnablePictureModeReset(void);
#endif

unsigned char Scaler_GetFacPatternColor(void);

void Scaler_SetNewRTNR_SAD_Mix_Weight(unsigned char value);

void Scaler_SetAutoMAFlag(unsigned char flag);
void Scaler_Set_Open_Cell_Panel_UseOD(unsigned char flag);
void Scaler_Set_YC2D3D(unsigned char flag);
void Scaler_Set_ChannelColourSet(char flag);
void Scaler_Set_ColorMatrix(bool flag);

unsigned char Scaler_Get_NrAvgcount(void);  /*yuan1024*/
void Scaler_SetAutoMA(unsigned char Flag, unsigned char value, unsigned char sendRPC_flag);	/*Elsie 20131210*/





/*o===========================================================o*/
/*o=================== Enginner Menu Start ===================o*/
/*o===========================================================o*/

unsigned char Scaler_GetScaleDOWNH(void);
void Scaler_SetScaleDOWNH(unsigned char value);					/*range 0~17*/
unsigned char Scaler_GetScaleDOWNV(void);
void Scaler_SetScaleDOWNV(unsigned char value);					/*range 0~17*/

unsigned char Scaler_GetScaleDOWNVTable(void);
void Scaler_SetScaleDOWNVTable(unsigned char value);				/*range 0~7*/
unsigned short Scaler_GetH8Scaling(void);
void Scaler_SetH8Scaling(unsigned char value);
unsigned char Scaler_GetPacificNewIntra(void);
void Scaler_SetPacificNewIntra(unsigned char value);
unsigned short Scaler_GetICcoring(void);
void Scaler_SetICcoring(unsigned char value);
unsigned short Scaler_GetDCcoring(void);
void Scaler_SetDCcoring(unsigned char value);
unsigned char Scaler_GetVertical_NR(void);
void Scaler_SetVertical_NR(unsigned char value);
unsigned char Scaler_GetIESM(void); /*Lydia*/
void Scaler_SetIESM(unsigned char value);
unsigned char Scaler_GetIESM_Chaos(void);
void Scaler_SetIESM_Chaos(unsigned char value);
unsigned char Scaler_GetIESM_Top2Diff(void);
void Scaler_SetIESM_Top2Diff(unsigned char value);
unsigned char Scaler_GetIESM_Edge(void);
void Scaler_SetIESM_Edge(unsigned char value);
unsigned char Scaler_GetIESM_CRCT(void);
void Scaler_SetIESM_CRCT(unsigned char value);
unsigned char Scaler_GetIESM_Exten(void);
void Scaler_SetIESM_Exten(unsigned char value);
unsigned char Scaler_GetHMCNR(void);
void Scaler_SetHMCNR(unsigned char value);
unsigned char Scaler_GetHMCNR_blending(void);
void Scaler_SetHMCNR_blending(unsigned char value);
unsigned char Scaler_GetMBPeaking(void);
void Scaler_SetMBPeaking(unsigned char value);					/*range 0~40*/
unsigned short Scaler_GetSharpnessVerticalGain(void);
void Scaler_SetSharpnessVerticalGain(unsigned char value);
unsigned char Scaler_GetSKIPIR_Islet(void);
void Scaler_SetSKIPIR_Islet(unsigned char value);
unsigned short  Scaler_Getharpness2Dpk_Seg(void);
void Scaler_SetSharpness2Dpk_Seg(unsigned char value);
unsigned short  Scaler_GetSharpness2Dpk_Tex_Detect(void);
void Scaler_SetSharpness2Dpk_Tex_Detect(unsigned char value);
unsigned char Scaler_GetMADI_BTR(void);
void Scaler_SetMADI_BTR(unsigned char value);
unsigned char Scaler_GetMADI_BER(void);
void Scaler_SetMADI_BER(unsigned char value);
unsigned char Scaler_GetGridRemove(void);
void Scaler_SetGridRemove(unsigned char value);
unsigned char Scaler_GetContiStillLine(void);
void Scaler_SetContiStillLine(unsigned char value);

void Scaler_Set_TVAutoNR_Mode(unsigned char flag);
unsigned char Scaler_GetAutoMA1Flag(void);
void Scaler_SetAutoMA1Flag(unsigned char flag);
unsigned char Scaler_GetAutoMA2Flag(void);
void Scaler_SetAutoMA2Flag(unsigned char flag);
unsigned char Scaler_GetAutoMA3Flag(void);
void Scaler_SetAutoMA3Flag(unsigned char flag);
unsigned char Scaler_GetAutoMA4Flag(void);
void Scaler_SetAutoMA4Flag(unsigned char flag);
unsigned char Scaler_GetAutoMA5Flag(void);
void Scaler_SetAutoMA5Flag(unsigned char flag);
unsigned char Scaler_GetAutoMA6Flag(void);
void Scaler_SetAutoMA6Flag(unsigned char flag);
unsigned char Scaler_GetAutoMAFlag(void);
void Scaler_SetAutoMA_Flag(void);
unsigned char Scaler_GetAutoMA_VD_3D(void);
void Scaler_SetAutoMA_VD_3D(unsigned char flag);
/*unsigned char Scaler_Get_NR_style(void);*/
void Scaler_Set_NR_style(unsigned char flag, unsigned char calledByOSD);
unsigned char Scaler_GetDNR_log(void);
void Scaler_SetDNR_log(unsigned char flag);
unsigned char Scaler_GetRTNR_log(void);
void Scaler_SetRTNR_log(unsigned char flag);
unsigned char Scaler_GetSNR_log(void);
void Scaler_SetSNR_log(unsigned char flag);
unsigned char Scaler_GetINR_log(void);
void Scaler_SetINR_log(unsigned char flag);
unsigned char Scaler_Get_DEBUG_AUTO_NR(void);
void Scaler_Set_DEBUG_AUTO_NR(unsigned char flag);
unsigned char Scaler_Get_DEBUG_VD_NOISE(void);
void Scaler_Set_DEBUG_VD_NOISE(unsigned char flag);
unsigned char Scaler_Get_DEBUG_RTNR_MAD(void);
void Scaler_Set_DEBUG_RTNR_MAD(unsigned char flag);
unsigned char Scaler_Get_DEBUG_HISTOGRAM_MEAN(void);
void Scaler_Set_DEBUG_HISTOGRAM_MEAN(unsigned char flag);

void Scaler_SetVIP_Dbg_Msg(unsigned char flag);
unsigned char Scaler_Get_TVAutoNR_Mode(void);
unsigned char Scaler_GetVIP_Dbg_Msg(void);

/*NR_log*/
INT8 COsdCtrlGet_DNR_log(void);
void COsdCtrlSet_DNR_log(UINT16  Message);
INT8 COsdCtrlGet_RTNR_log(void);
void COsdCtrlSet_RTNR_log(UINT16  Message);
INT8 COsdCtrlGet_SNR_log(void);
void COsdCtrlSet_SNR_log(UINT16  Message);
INT8 COsdCtrlGet_INR_log(void);
void COsdCtrlSet_INR_log(UINT16  Message);
INT8 COsdCtrlGet_MPEGNR_log(void);
void COsdCtrlSet_MPEGNR_log(UINT16  Message);


/*AUTO_NR_DEBUG*/
INT8 COsdCtrlGet_DEBUG_AUTO_NR(void);
void COsdCtrlSet_DEBUG_AUTO_NR(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_VD_NOISE(void);
void COsdCtrlSet_DEBUG_VD_NOISE(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_RTNR_MAD(void);
void COsdCtrlSet_DEBUG_RTNR_MAD(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_HISTOGRAM_MEAN(void);
void COsdCtrlSet_DEBUG_HISTOGRAM_MEAN(UINT16  Message);

/*o===========================================================o*/
/*o=================== Enginner Menu End =====================o*/
/*o===========================================================o*/


/*o===========================================================o*/
/*o==================== OSD MENU Start =======================o*/
/*o===========================================================o*/




/*
void Scaler_GetFacBrightness(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100);
void Scaler_GetFacContrast(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100);
void Scaler_GetFacSaturation(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100);
void Scaler_SetFacSaturation(unsigned char val_0, unsigned char val_50, unsigned char val_100);
void Scaler_GetFacHue(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100);
void Scaler_SetFacHue(unsigned char val_0, unsigned char val_50, unsigned char val_100);
*/

#ifdef OSD_FOUR_LEVEL_MAPPING_ENABLE
unsigned char Scaler_GetFacSharpness(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100,
	unsigned char *retval_25, unsigned char *retval_75);
unsigned char Scaler_SetFacSharpness(unsigned char val_0, unsigned char val_50, unsigned char val_100,
	unsigned char val_25, unsigned char val_75);
unsigned char Scaler_GetFacBacklight(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100,
	unsigned char *retval_25, unsigned char *retval_75);
unsigned char Scaler_SetFacBacklight(unsigned char val_0, unsigned char val_50, unsigned char val_100,
	unsigned char val_25, unsigned char val_75);
#else
unsigned char Scaler_GetFacSharpness(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100);
unsigned char Scaler_SetFacSharpness(unsigned char val_0, unsigned char val_50, unsigned char val_100);
unsigned char Scaler_GetFacBacklight(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100);
unsigned char Scaler_SetFacBacklight(unsigned char val_0, unsigned char val_50, unsigned char val_100);
#endif
/*o===========================================================o*/
/*o==================== OSD MENU End = =======================o*/
/*o===========================================================o*/


#if 0  /* sirius not used*/

void Scaler_SetSceneMode(unsigned char level);				/*range 0~4*/

unsigned short  Scaler_color_GetTwoD_peaking_AdaptiveCtrl(void);

void Scaler_color_SetTwoD_peaking_AdaptiveCtrl(unsigned char value);

unsigned char Scaler_color_GetDCDI(void);

void Scaler_color_SetDCDI(unsigned char mode);

unsigned char Scaler_GetChrommaErr(void);
void Scaler_SetChrommaErr(unsigned char value);					/*range 0~8*/

unsigned char Scaler_color_GetVIP_Debug_Mode(void);
void Scaler_color_SetVIP_Debug_Mode(unsigned char value);

unsigned char Scaler_GetHist(void);
void Scaler_SetHist(unsigned char mode);

unsigned char Scaler_Get_NrAvgcount(void);
void Scaler_Set_NrAvgcount(unsigned char flag);/*yuan1024*/

#if defined (PQ_005_STYLE)
/*20130706 added by Diane for Dynamic Peaking Display*/
unsigned char Scaler_Get_RTNR_MAD_count_Y_sum_avg(void);
unsigned char Scaler_Get_DCC_Histogram_Mean_value(void);
void Scaler_Get_Dynamic_Peaking_Value_Display(unsigned char value[3]);
#endif

/*PQ Enable_DEBUG*/
INT8 COsdCtrlGet_DEBUG_DCTI_EN(void);
void COsdCtrlSet_DEBUG_DCTI_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_SHARP_EN(void);
void COsdCtrlSet_DEBUG_SHARP_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_EDGE_SMOOTH_EN(void);
void COsdCtrlSet_DEBUG_EDGE_SMOOTH_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_DCC_EN(void);
void COsdCtrlSet_DEBUG_DCC_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_ICM_EN(void);
void COsdCtrlSet_DEBUG_ICM_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_SRGB_EN(void);
void COsdCtrlSet_DEBUG_SRGB_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_GAMMA_EN(void);
void COsdCtrlSet_DEBUG_GAMMA_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_DITHER_EN(void);
void COsdCtrlSet_DEBUG_DITHER_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_DCR_EN(void);
void COsdCtrlSet_DEBUG_DCR_EN(UINT16  Message);
#if defined(IS_TV05_STYLE_PICTUREMODE)
#if defined (BUILD_TV005_1_ISDB)
INT8 COsdCtrlGet_DEBUG_DCR_OFFSET(void);
void COsdCtrlSet_DEBUG_DCR_OFFSET(UINT16  Message);
#endif
INT8 COsdCtrlGet_DEBUG_MEGA_DCR_EN(void);
void COsdCtrlSet_DEBUG_MEGA_DCR_EN(UINT16  Message);
INT16 COsdCtrlGet_DEBUG_MEGA_DCR_COUNT(void);
void COsdCtrlSet_DEBUG_MEGA_DCR_COUNT(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_MEGA_DCR_WEIGHT(void);
void COsdCtrlSet_DEBUG_MEGA_DCR_WEIGHT(UINT16  Message);
#endif


#endif


/* for load quality handle*/

void Scaler_Get_Display_info(unsigned char *display, unsigned char *src_idx);

void Scaler_VIP_IP_init(unsigned char Vip_source);

void Scaler_VIP_MEMC_init(unsigned char Vip_source);

void Scaler_VIP_Project_ID_init(void);

unsigned char Scaler_GetMA_Chroma_Error(void);

void Scaler_SetMA_Chroma_Error(unsigned char value);

unsigned char Scaler_GetMA_Chroma_Error_En_From_vipTable(void);

unsigned char Scaler_GetMADI_HMC(void);

void Scaler_SetMADI_HMC(unsigned char value);

unsigned char Scaler_GetMADI_HME(void);

void Scaler_SetMADI_HME(unsigned char value);

unsigned char Scaler_GetMADI_PAN(void);

void Scaler_SetMADI_PAN(unsigned char value);

unsigned char Scaler_GetNew_UVC(void);

void Scaler_SetNew_UVC(unsigned char value);

unsigned char Scaler_GetDLti(void);

void Scaler_SetDLti(unsigned char value);						/*range 0~10*/

unsigned char Scaler_GetDCti(void);

void Scaler_SetDCti(unsigned char value);						/*range 0~10*/

unsigned char Scaler_GetIDLti(void);

void Scaler_SetIDLti(unsigned char value);

unsigned char Scaler_GetIDCti(void);

void Scaler_SetIDCti(unsigned char value);

unsigned char Scaler_GetVDCti(void);

void Scaler_SetVDCti(unsigned char value);

void Scaler_SetVDCti_LPF(unsigned char value);
unsigned char Scaler_GetVDCti_LPF(void);

unsigned char Scaler_GetColor_UV_Delay_Enable(void);

void Scaler_SetColor_UV_Delay_Enable(unsigned char on_off);

unsigned char Scaler_GetColor_UV_Delay(void);

void Scaler_SetColor_UV_Delay(unsigned char value);
void Scaler_SetColor_UV_Delay_TOP(unsigned char value);



unsigned char Scaler_GetFilm_Mode(void);

void Scaler_SetFilm_Mode(unsigned char value);

void Scaler_SetFilmonoff(unsigned char value);

void Scaler_SetFilm_Setting(void);


unsigned char Scaler_GetIntra(void);

void Scaler_SetIntra(unsigned char value);	/*range 0~11*/

unsigned char Scaler_GetMADI(void);

void Scaler_SetMADI(unsigned char value);
void Scaler_SetMADI_INIT(void);

#if 0
unsigned char Scaler_GetTNRXC(void);
void Scaler_SetTNRXC(unsigned char value);
unsigned char Scaler_GetTNRXC_Mk2(void);
void Scaler_SetTNRXC_Mk2(unsigned char value);
unsigned char fwif_color_get_tnrxc_mk2(unsigned char src_idx);
void fwif_color_set_tnrxc_mk2(unsigned char src_idx, unsigned char value);

#else
unsigned char Scaler_GetTNRXC_Ctrl(void);
void Scaler_SetTNRXC_Ctrl(unsigned char value);

unsigned char Scaler_GetTNRXC_MK2(void);
void Scaler_SetTNRXC_MK2(unsigned char value);

void Scaler_SetTNRXC(unsigned char value);
#endif

void Scaler_SetDataFormatHandler(void);

unsigned char Scaler_get_YUV2RGB(void);

void Scaler_set_YUV2RGB(unsigned char which_table, unsigned char drvSkip_Flag_coefByY, unsigned char drvSkip_Flag_uvOffset);
#if 0
unsigned char Scaler_get_YUV2RGB_COEF_BY_Y(void);

void Scaler_set_YUV2RGB_COEF_BY_Y(unsigned char which_table, unsigned char drvSkip_Flag);

unsigned char Scaler_get_YUV2RGB_UV_OFFSET_BY_Y(void);

void Scaler_set_YUV2RGB_UV_OFFSET_BY_Y(unsigned char which_table, unsigned char drvSkip_Flag);
#endif
/*signed char Scaler_GetCrossColor(void);*/

/*void Scaler_SetCrossColor(unsigned char value);*/ /*range 0~2*/



void Scaler_module_vdc_SetConBriHueSat_Table(unsigned char value);
unsigned char Scaler_module_vdc_GetConBriHueSat_Table(void);



unsigned char Scaler_get_ICM_table(void);

void Scaler_set_ICM_table(unsigned char value, unsigned char drvSkip_Flag);

unsigned char Scaler_GetGamma(void);

void Scaler_SetGamma(unsigned char value);/*range 0~3*/

unsigned char Scaler_GetSindex(void);

unsigned char Scaler_SetSindex(unsigned short value);/*range 0~32*/

unsigned char Scaler_GetSlow(void);

unsigned char Scaler_SetSlow(unsigned short value);	/*range 0~20*/

unsigned char Scaler_GetShigh(void);

unsigned char Scaler_SetShigh(unsigned short value);/*range 0~20*/

void Scaler_SetGamma_for_Handler(unsigned char gamma,
															unsigned char s_gamma_index,
															unsigned char s_gamma_low,
															unsigned char s_gamma_high, unsigned char drvSkip_Flag);

unsigned char Scaler_Get_blue_stretch(void);

void Scaler_set_blue_stretch(unsigned char table);

unsigned short Scaler_GetSharpnessTable(void);

void Scaler_SetSharpnessTable(unsigned char value);

unsigned short Scaler_GetCDSTable(void);

void Scaler_SetCDSTable(unsigned char value);

unsigned short Scaler_GetEGSM_postshp_level(void);

void Scaler_SetEGSM_postshp_level(unsigned char value);

unsigned char Scaler_GetEMF_Mk2(void);

void Scaler_SetEMF_Mk2(unsigned char value);

unsigned char Scaler_GetSKIPIR_Ring(void);

void Scaler_SetSKIPIR_Ring(unsigned char value);

unsigned char Scaler_GetSKIPIR_Dnoise(void);

void Scaler_SetSKIPIR_Dnoise(unsigned char value);

unsigned short Scaler_GetskipirdnoiseTable(void);/* csfanchiang, 20101006*/

void Scaler_SetskipirdnoiseTable(unsigned char value);/* csfanchiang, 20101006*/

unsigned char Scaler_Get_DCC_Color_Independent_Table(void);

void Scaler_Set_DCC_Color_Independent_Table(unsigned char value);

unsigned char Scaler_Get_DCC_chroma_compensation_Table(void);

void Scaler_Set_DCC_chroma_compensation_Table(unsigned char value);

unsigned char Scaler_get_Adaptive_Gamma(void);

void Scaler_set_Adaptive_Gamma(unsigned char value);

/*unsigned char Scaler_Get_DCC_Style(void);*/

/*void Scaler_Set_DCC_Style(unsigned char value, unsigned char calledByOSD);*/

unsigned char Scaler_GetRTNR_Noise_Measure(void);

void Scaler_SetRTNR_Noise_Measure(unsigned char value);

unsigned char Scaler_GetScaleUPH(void);

void Scaler_SetScaleUPH(unsigned char value);

unsigned char Scaler_GetScaleUPH_8tap(void);

void Scaler_SetScaleUPH_8tap(unsigned char value);

unsigned char Scaler_GetScaleUPV(void);

void Scaler_SetScaleUPV(unsigned char value);
void Scaler_SetScaleUP_YCHV(unsigned char HY, unsigned char VY, unsigned char HC, unsigned char VC);
void Scaler_GetScaleUP_YCHV(unsigned char *pHY,unsigned char *pVY,unsigned char *pHC,unsigned char *pVC);

unsigned char Scaler_GetScaleUPDir(void);

void Scaler_SetScaleUPDir(unsigned char value);/*range 0~19*/

unsigned char Scaler_GetScaleUPDir_Weighting(void);

void Scaler_SetScaleUPDir_Weighting(unsigned char value);/*range 0~9*/

unsigned char Scaler_GetScalePK(void);

void Scaler_SetScalePK(unsigned char value);					/*range 0~10*/

unsigned short Scaler_GetSUPKType(void);

void Scaler_SetSUPKType(unsigned char value);

unsigned short Scaler_GetUnsharpMask(void);

void Scaler_SetUnsharpMask(unsigned char value);



unsigned char Scaler_get_egsm_postshp_table(void);

void Scaler_set_egsm_postshp_table(unsigned char value);

unsigned char Scaler_getdESM(void);

void Scaler_setdESM(unsigned char value);

unsigned char Scaler_getiESM(void);

void Scaler_setiESM(unsigned char value);

void Scaler_set_SuperResolution_init_table(unsigned char value);

unsigned char Scaler_GetSR_edge_gain(void);

void Scaler_SetSR_edge_gain(unsigned char value);

unsigned char Scaler_GetSR_texture_gain(void);

void Scaler_SetSR_texture_gain(unsigned char value);

unsigned char Scaler_GetScaleDOWNHTable(void);

void Scaler_SetScaleDOWNHTable(unsigned char value);/*range 0~7*/

unsigned char Scaler_GetScaleDOWN444To422(void);
void Scaler_SetScaleDOWN444To422(unsigned char value);/*range 0~17*/

//void Scaler_SetScaleUP_TwoStep(unsigned char value);
//unsigned char Scaler_GetScaleUP_TwoStep(void);

void Scaler_SetScaleUPV_6tap(unsigned char value);
unsigned char Scaler_GetScaleUPV_6tap(void);

unsigned short Scaler_GetDeRing(void);

void Scaler_SetDeRing(unsigned short value);

unsigned char Scaler_GetDiSmd(void);
void Scaler_SetDiSmd(unsigned char value);

void Scaler_SetScaleOSD_Sharpness(unsigned char value);
unsigned char Scaler_GetScaleOSD_Sharpness(void);

unsigned char Scaler_Debug_Get_UserCurveDCC_Curve_Select(void);
unsigned char Scaler_Debug_Get_HIST_MEAN_VALUE(void);
unsigned char Scaler_Debug_Get_Pure_Color_Flag(void);
unsigned char Scaler_Debug_Get_Skin_Tone_Found_Flag(void);
unsigned char Scaler_Debug_Get_UserCurveDCC_Curve_Weighting(void);
unsigned char Scaler_Debug_Get_UserCurveDCC_Curve_Weighting_Skin(void);

void Scaler_Debug_Set_UserCurveDCC_Curve_Select(unsigned char value);
void Scaler_Debug_Set_UserCurveDCC_Curve_Apply(unsigned char value);
void Scaler_Debug_Set_UserCurveDCC_Curve_Weighting(unsigned char value);
void Scaler_Debug_Set_UserCurveDCC_Curve_Weighting_Skin(unsigned char value);

void Scaler_set_pq_dir_path(char *path, char *patch_path);
unsigned char Scaler_get_average_luma(unsigned char *val);
unsigned char Scaler_get_luma_level_distribution(unsigned short *luma_distribution, unsigned char size);
unsigned char Scaler_get_Y_Total_Hist_Cnt_distribution(UINT8 MODE, UINT8 size, unsigned int *Y_Hist_distr_cnt);

void Scaler_SetDcrMode(unsigned char value);
unsigned char Scaler_GetDcrMode(void);
unsigned char Scaler_SetOSDBacklight2VIP(unsigned char value);
void Scaler_set_DCR_Enable(UINT8 value);
UINT8 Scaler_get_DCR_Enable(void);
void Scaler_Get_color_access_TVStatus_DisplayInfo(unsigned int *VIP_Access_Memory_DisplayInfo_Table);

#ifdef LocalDimming
void Scaler_SetLocalDimmingEnable(unsigned char enable);
void Scaler_GetLocalDimmingEnable(void);
void Scaler_SetLocalDimmingTable(unsigned char TableIdx);
void Scaler_GetLocalDimmingTable(void);
void Scaler_fwif_color_set_LocalDimming_table(unsigned char src_idx, unsigned char TableIdx);
#endif
unsigned char Scaler_GetLocalContrastEnable(void);
void Scaler_SetLocalContrastEnable(unsigned char enable);
unsigned char Scaler_GetLocalContrastTable(void);
void Scaler_SetLocalContrastTable(unsigned char TableIdx);
void Scaler_fwif_color_set_LocalContrast_table(unsigned char src_idx, unsigned char TableIdx);

#if 0/*def RTICE2AP_DEBUG_TOOL_ENABLE, */ /*change flow to scalerThread_rtice2AP.h for PQ tool share memory access*/
int rtice_get_vip_table(unsigned int id, unsigned short size, unsigned char *num_type, unsigned char *buf);
int rtice_set_vip_table(unsigned int id, unsigned short size, unsigned char *buf);
int rtice_set_IdxTable2Buff(unsigned short mode, unsigned short size, unsigned char *num_type, unsigned char *buf);	/*return idx table size*/
#endif

#if 0 //jyyang20161215 // Dstat is remoived since mac5
int Scaler_GetRGBPixelInfo(RGB_pixel_info *data);
#endif
void Scaler_Init_ColorLib_customer_share_memory_struct(void);

void Scaler_color_handler(void);

void Scaler_AllocateODMem(void);
void Scaler_ReleaseODMem(void);
unsigned int Scaler_GetODMem(void);

void fwif_color_video_quality_handler_customization(void);
void Scaler_SetPictureMode(unsigned char level);

unsigned char Scaler_GetPictureMode(void);

unsigned char Scaler_GetContrast(void);

void Scaler_SetContrast(unsigned char value);				/*range 0~100*/

unsigned char Scaler_GetBrightness(void);

void Scaler_SetBrightness(unsigned char value);				/*range 0~100*/

unsigned char Scaler_GetSaturation(void);

void Scaler_SetSaturation(unsigned char value);    /*range 0~100*/

unsigned char Scaler_GetHue(void);

void Scaler_SetHue(unsigned char value);        /*range 0~100*/

unsigned char Scaler_GetSharpness(void);

void Scaler_SetSharpness(unsigned char value);

unsigned char Scaler_SetBackLight(unsigned char value);

unsigned char Scaler_GetBacklight(void);

SLR_COLORTEMP_LEVEL Scaler_GetColorTemp(void);

void Scaler_SetColorTemp(SLR_COLORTEMP_LEVEL level);

unsigned char Scaler_PipGetSubBrightness(void);

/**
 * Scaler_PipSetSubBrightness
 * set the brightness level of sub channel
 *
 * @param { value:0~100}
 * @return { }
 *
 */
void Scaler_PipSetSubBrightness(unsigned char value);

/**
 * Scaler_PipGetSubContrast
 * set the contrast level of sub channel
 *
 * @param { }
 * @return { TRUE/FALSE }
 *
 */
unsigned char Scaler_PipGetSubContrast(void);

/**
 * Scaler_PipSetSubContrast
 * set the contrast level of sub channel
 *
 * @param { value:0~100  }
 * @return { }
 *
 */
void Scaler_PipSetSubContrast(unsigned char value);
void Scaler_Load_VipTable_Custom(void *ptr);

UINT8 Scaler_Get_DI_Force_2D_Enable(void);
void Scaler_Set_DI_Force_2D_Enable(UINT8 ucEnable);
UINT8 Scaler_Enter_DI_Force_2D_Condition(UINT8 ucDisplay);

unsigned short Scaler_GetMAG_H_Region_Start(void);
unsigned short Scaler_GetMAG_H_Region_End(void);
unsigned short Scaler_GetMAG_H_Region_Width(void);
unsigned short Scaler_GetMAG_V_Region_Start(void);
unsigned short Scaler_GetMAG_V_Region_End(void);
unsigned short Scaler_GetMAG_V_Region_Len(void);

/*=======================for magic picture======================*/
void Scaler_SetMagicPicture(SLR_MAGIC_TYPE level);
void mScalerSetMAG(void);
void Scaler_MagicSaturation(unsigned char display, unsigned char MagicMode);
void mScalerMagicPictureCtrlForDynamic(void);
void Scaler_MoveMagicPictureForStill(unsigned int timerId, void *msg);
/*=======================for magic picture end======================*/

unsigned char Scaler_getDI_SMD_en(unsigned char source);

void Scaler_color_copy_scalerinfo_to_vip(unsigned char display);
void Scaler_color_print_scalerinfo(void);

void Scaler_SetFacPatternColor(unsigned char val);

void Scaler_SetMagicPicture_demo_reset(unsigned char level);
unsigned char Scaler_GetMagicPicture_demo_reset(void);

//for VIP table check
void Scaler_checkVIPTable(void);

void Scaler_Set3dLUT(UINT8 TableIdx);
unsigned char Scaler_Get3dLUT(void);

unsigned char fwif_vip_increase_DI_water_lv(void);
void Scaler_LGE_HDR10_Enable(unsigned char enable);
void Scaler_SetHDR_BlackLevel(unsigned char blk_lv);

void drvif_TV006_HDR10_init(void);
void Scaler_set_HDR10_Enable(unsigned char* enable);
void Scaler_LGE_ONEKEY_HDR10_Enable(unsigned char enable);
void Scaler_LGE_ONEKEY_BBC_Enable(unsigned char enable);
void drvif_TV006_SET_HDR_mode(UINT32* modeinfo);
#ifdef CONFIG_HDR_SDR_SEAMLESS
void drvif_TV006_SET_HDR_mode_Seamless(UINT32* modeinfo);
void Scaler_LGE_HDR10_Enable_Seamless(unsigned char enable);
void Scaler_set_HDR10_Enable_Seamless(unsigned char* enable);
#endif
void Scaler_LGE_ONEKEY_SDR2HDR_Enable(unsigned char enable);


void Scaler_color_set_HDR_DEMO_Mode_ON(void);
void Scaler_color_set_HDR_DEMO_Mode_OFF(void);

void Scaler_color_set_m_nowSource(unsigned char value);
unsigned char Scaler_color_get_m_nowSource(void);

void vpq_PQ_setting_check(char *item_name, unsigned int *PQ_check_error);
void vpq_PQ_check_timming(char *item_name, unsigned int *PQ_check_error);

unsigned char  Scaler_Set_I_De_XC(unsigned char value);
unsigned char Scaler_Get_I_De_XC(void);
unsigned char Scaler_Set_I_De_XC_by_viptable(void);

#if 0 // I-decontour not implemented in Mac5p, 20161219 jimmy
unsigned char  Scaler_Set_I_De_Contour(unsigned char value);
#endif
#ifdef MAC5_NO_RGBW
void  Scaler_Set_BOE_RGBW(int w_rate);
#endif
unsigned char  Scaler_Set_SLD(unsigned char value);
void Scaler_color_colorwrite_Output_InvOutput_gamma(unsigned char value);
unsigned char Scaler_Get_Output_InvOutput_gamma(void);

void set_HDR10_DM_setting(void);

#ifdef CONFIG_ENABLE_SCALER_DRIVER_BASE

#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
void Scaler_Share_Memory_Access_VIP_TABLE_Custom_Struct(unsigned long arg);
#endif

#else

#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
void Scaler_Share_Memory_Access_VIP_TABLE_Custom_Struct(unsigned long arg);
#endif

#endif
unsigned char Scaler_IamLC_DemoFunction(unsigned char mode);
unsigned char Scaler_GetIamLC_DemoFunction(void);

#ifdef CONFIG_HDR_SDR_SEAMLESS
void Scaler_hdr_setting_SEAMLESS(unsigned char hdr_enable);
#endif

void fwif_color_vsc_to_scaler_src_mapping(unsigned char vsc_src, unsigned char *p_scaler_src_type, unsigned char *p_scaler_src_form);
unsigned char fwif_color_get_cur_input_timing_mode(unsigned char display);

char Scaler_color_Set_PQ_ByPass_Lv(unsigned char table_idx);
char Scaler_color_Get_PQ_ByPass_Lv(void);

char Scaler_color_Get_HDR10_OETF_ByMaxCLL_ByPanelLuminance(unsigned short *OETF_TBL);

void Scaler_color_Set_HDR_AutoRun(unsigned char nEnable);
unsigned char Scaler_color_Get_HDR_AutoRun(void);

void Scaler_color_HDRIP_AutoRun(void);
void Scaler_color_HDRInfo_Update(UINT32* modeinfo);
void Scaler_color_HDRIP_AutoRun_sRGB(void);
void Scaler_color_HDRInfo_Update_sRGB(UINT32* modeinfo);

void Scaler_color_set_pq_src_idx(unsigned char src_idx);
unsigned char Scaler_color_get_pq_src_idx(void);

HDMI_CSC_DATA_RANGE_MODE_T Scaler_GetHDMI_CSC_DataRange_Mode(void);
void Scaler_SetHDMI_CSC_DataRange_Mode(HDMI_CSC_DATA_RANGE_MODE_T value);
void Scaler_recheck_sharpness_table(void);
unsigned char Scaler_Get_CinemaMode_PQ(void);
void Scaler_Set_CinemaMode_PQ(unsigned char mode);
bool Scaler_Init_OD(void);
unsigned char Scaler_Get_OD_Bits(void);
unsigned char Scaler_Set_OD_Bits(unsigned char bits);
unsigned char Scaler_Get_OD_Enable(void);
unsigned char Scaler_OD_Test(unsigned char en);
void Scaler_Set_PicMode_VIP_src(unsigned char src);
void Scaler_Check_VIP_src_resync_flag(void);
unsigned char Scaler_Get_VIP_src_resync_flag(void);
void Scaler_Set_PQ_table_bin_En(unsigned char en);
unsigned char Scaler_Get_PQ_table_bin_En(void);
unsigned char Scaler_SetBackLightMappingRange(unsigned int uiMax,unsigned int uiMin,unsigned int actMax,unsigned int actMin,unsigned char increaseMode);
unsigned char Scaler_GetBackLightMappingRange(unsigned int *uiMax,unsigned int *uiMin,unsigned int *actMax,unsigned int *actMin, unsigned char *increaseMode);
unsigned char Scaler_Get_DCR_Backlight(void);
unsigned char  Scaler_Set_VIP_HANDLER_RESET(void);
unsigned char Scaler_Set_OD_Bit_By_XML(void);

void Scaler_color_get_LC_Blight_dat(unsigned int *ptr_out);
void Scaler_color_get_LC_His_dat(unsigned int *plc_out);
void Scaler_color_set_DDomain3DLUT_gamma_by_colorspace(UINT8 colorspace_index);
UINT8 Scaler_color_get_colorspace_index(void);
void Scaler_SetCDSTable_by_Sharpness(unsigned char value);


#ifdef __cplusplus
}
#endif

#endif /* __SCALER_LIB_H__*/

