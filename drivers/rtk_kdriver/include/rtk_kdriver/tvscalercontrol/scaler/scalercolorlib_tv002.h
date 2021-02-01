#ifndef __SCALERCOLOR_LIB_TV002_H__
#define __SCALERCOLOR_LIB_TV002_H__

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
#include <scalercommon/vipRPCCommon.h>


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


/*******************************************************************************
* enumeration
******************************************************************************/


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
typedef enum _VIP_Project_Style_TV002{
	Project_TV002_OFF = 0, /* is not TV002 style*/
	Project_TV002_Style_1,
	Project_TV002_Style_2,

	VIP_Project_Style_TV002_MAX,

}VIP_Project_Style_TV002;

// id pattern TV002
typedef enum _ID_ITEM_TV002 {
	ID_Radio_TV002 =0,
	ID_FaceArtifactNoise_TV002,
	ID_Raining_0_TV002,
	ID_Raining_1_TV002,
	ID_Snow_TV002,
	ID_BlueArcBridge_TV002,
	ID_DarkScene_Road_Lamp_TV002,
	ID_MonoScope_TV002,
	ID_Tunnel_TV002,
	ID_RockMountain_TV002,
	ID_QtechBamboo_TV002,
	//ID_TempleZooming_TV002,
	//ID_DarkWheelNoise_TV002,
	//ID_BrightnessDarkness_11_TV002,
	//ID_TestChart_06_07_TV002,
	//ID_BlackWomenFace,
	//ID_OsceanWave_TV002,
	ID_WaterfallStair_TV002,
	ID_MovingClockTower_TV002,
	ID_MovingPTG_Mono_TV002,
	ID_MovingCircle_TV002,
	ID_MovingRoof_TV002,

	ID_ITEM_TV002_MAX,

}ID_ITEM_TV002;
#if 0
typedef struct _ID_CTRL_TV002 {
	unsigned short ID_Flag;
	unsigned short Y_th;
	unsigned short Hue_th;
	unsigned short Sat_th;
	unsigned short Y_Hist_Ratio[TV006_VPQ_chrm_bin];
	unsigned short Hue_Hist_Ratio[COLOR_HUE_HISTOGRAM_LEVEL];
	unsigned short Sat_Hist_Raio[COLOR_AutoSat_HISTOGRAM_LEVEL];
} ID_CTRL_TV002;
#endif
/*=========================================================*/


/*==================== Functions ================== */
SLR_VIP_TABLE_CUSTOM_TV002* Scaler_get_tv002_Custom_struct(void);
void Scaler_set_Intelligent_Picture_Enable(unsigned char En_flag);
unsigned char Scaler_get_Intelligent_Picture_Enable(void);
void Scaler_set_Intelligent_Picture_Optimisation(unsigned char Level);
unsigned char Scaler_get_Intelligent_Picture_Optimisation(void);
void Scaler_set_Intelligent_Picture_Signal_Level_Indicator_ONOFF(unsigned char En_Flag);
unsigned char Scaler_Intelligent_Picture_get_Signal_Level_Indicator_ONOFF(void);
unsigned char Scaler_Intelligent_Picture_get_Intelligent_Picture_Signal_Level(void);
VIP_MAGIC_GAMMA_Function* Scaler_get_Magic_Gamma(void);
void Scaler_set_BP_initial(VIP_SOURCE_TIMING VIP_SrcTiming, PICTURE_MODE Pic_Mode);
 unsigned char Scaler_get_LiveColor(void);
void Scaler_set_LiveColor(unsigned char level_index);
unsigned char Scaler_get_Clarity_RealityCreation(void);
void Scaler_set_Clarity_RealityCreation(unsigned char level);
unsigned char Scaler_get_Clarity_Resolution(void);
void Scaler_set_Clarity_Resolution(unsigned char level);
unsigned char Scaler_get_Clarity_Mastered4K(void);
void Scaler_set_Clarity_Mastered4K(unsigned char level);
char Scaler_Get_Set_Black_Level_TV002(unsigned char value, unsigned char isSet_Flag);
char Scaler_Get_Set_Reality_Creation_TV002(unsigned char value, unsigned char isSet_Flag);
char Scaler_Get_Set_Resolution_TV002(unsigned char value, unsigned char isSet_Flag);
char Scaler_Get_Set_Black_Corrector_TV002(unsigned char value, unsigned char isSet_Flag);
char Scaler_Get_Set_Black_Adjust_TV002(unsigned char value, unsigned char isSet_Flag);
char Scaler_Get_Set_LED_Motion_Mode_TV002(unsigned char value, unsigned char isSet_Flag);

unsigned char Scaler_access_Project_TV002_Style(unsigned char isSet_Flag, unsigned char TV002_style_Mode);
unsigned char Scaler_get_DBC_blacklight_Value_TV002(void);
char Scaler_set_DBC_UI_blacklight_Value_TV002(unsigned char value);
char Scaler_set_DBC_POWER_Saving_Mode_TV002(unsigned char value);
char Scaler_set_UI_Picture_Mode_TV002(unsigned char value);

unsigned short Scaler_scalerVIP_DBC_get_APL_TV002(SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, _system_setting_info* system_info_structure_table, _clues *SmartPic_clue, unsigned int MA_print_count);
unsigned char Scaler_scalerVIP_DBC_BASIC_BLIGHT_Cal_TV002(SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, _system_setting_info* system_info_structure_table, unsigned int MA_print_count);
unsigned char Scaler_scalerVIP_DBC_DBC_Cal_TV002(SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, _system_setting_info* system_info_structure_table, _clues *SmartPic_clue, unsigned int MA_print_count);
unsigned char Scaler_scalerVIP_DBC_Y_Max_Cal_TV002(_clues *SmartPic_clue, unsigned int MA_print_count);
unsigned char Scaler_scalerVIP_DBC_BackLight_Cal_TV002(SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, _system_setting_info* system_info_structure_table, _clues *SmartPic_clue, unsigned int MA_print_count);
void Scaler_scalerVIP_DBC_CTRL_TV002(SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, _system_setting_info* system_info_structure_table, _clues *SmartPic_clue, unsigned int MA_print_count);
unsigned char Scaler_scalerVIP_DBC_LUT_TV002(SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, unsigned char APL, unsigned char Dev, unsigned int MA_print_count);
unsigned char Scaler_scalerVIP_DBC_Smooth_TV002(unsigned char DBC, SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, _system_setting_info* system_info_structure_table, _clues *SmartPic_clue, unsigned int MA_print_count);
char Scaler_scalerVIP_DBC_DCC_S_High_Compensation_TV002(SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, unsigned char APL, unsigned char Dev, unsigned char power_saving_mode, unsigned int MA_print_count);

void Scaler_scalerVIP_ZERO_D_CTRL_TV002(SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, _system_setting_info* system_info_structure_table, _clues *SmartPic_clue, unsigned int MA_print_count);

/*BP*/
unsigned short Scaler_scalerVIP_Brightness_Plus_Cal_Gain_By_TBL_TV002(SLR_VIP_TABLE* vipTBL_shareMem, _clues* SmartPic_clue, _system_setting_info* sysInfo_TBL, SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, unsigned char APL, unsigned int MA_print_count);
unsigned short Scaler_scalerVIP_Brightness_Plus_Cal_OverSat_Protect_Gain_TV002(unsigned short BP_Gain, SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, _clues* SmartPic_clue, unsigned int MA_print_count);
unsigned short Scaler_scalerVIP_Brightness_Plus_Smooth_Gain_Cal_TV002(unsigned short BP_Gain, SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, unsigned int MA_print_count);
short Scaler_scalerVIP_Brightness_Plus_Smooth_Offset_Cal_TV002(short RGB_Offset, SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, unsigned int MA_print_count);
short Scaler_scalerVIP_Brightness_Plus_Compensation_RGB_Offset_Cal_TV002(unsigned short BP_Gain, unsigned short APL, SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, _system_setting_info* sysInfo_TBL, unsigned int MA_print_count);
void Scaler_scalerVIP_Brightness_Plus_Function_TV002(SLR_VIP_TABLE* vipTBL_shareMem, _clues* SmartPic_clue, _system_setting_info* sysInfo_TBL, SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, unsigned int MA_print_count);
void Scaler_scalerVIP_Set_YUV2RGB_By_Brightness_Plus_TV002(unsigned short BP_Gain, short BP_Offset, _system_setting_info* sysInfo_TBL, SLR_VIP_TABLE_CUSTOM_TV002 *vipCustomTBL_ShareMem, unsigned int MA_print_count);

void Scaler_scalerVIP_set_sharpness_level_Directly_TV002(DRV_Sharpness_Level *ptr);
unsigned char Scaler_scalerVIP_Access_sharpness_level_TBL_TV002(DRV_Sharpness_Level *ptr, unsigned char isSet_Flag);

void Scaler_scalerVIP_ID_TV002(SLR_VIP_TABLE* ShareMem_VIP_TBL, _RPC_clues* RPC_SmartPic_clue, _clues* SmartPic_clue, _RPC_system_setting_info* RPC_system_infoTBL, _system_setting_info* system_infoTBL, unsigned int MA_print_count);
void Scaler_scalerVIP_ID_Apply_TV002(SLR_VIP_TABLE* ShareMem_VIP_TBL, _RPC_system_setting_info* RPC_system_infoTBL, _system_setting_info* system_infoTBL, _clues* SmartPic_clue, unsigned int MA_print_count);
void Scaler_scalerVIP_ID_Apply_PQA_LV_TV002(SLR_VIP_TABLE* ShareMem_VIP_TBL, _RPC_system_setting_info* RPC_system_infoTBL, _system_setting_info* system_infoTBL, _clues* SmartPic_clue, unsigned int MA_print_count);
void Scaler_scalerVIP_ID_Apply_2dPeaking_TV002(SLR_VIP_TABLE* ShareMem_VIP_TBL, _RPC_system_setting_info* RPC_system_infoTBL, _system_setting_info* system_infoTBL, _clues* SmartPic_clue, unsigned int MA_print_count);
void Scaler_scalerVIP_ID_Apply_DI_TV002(SLR_VIP_TABLE* ShareMem_VIP_TBL, _RPC_system_setting_info* RPC_system_infoTBL, _system_setting_info* system_infoTBL, _clues* SmartPic_clue, unsigned int MA_print_count);

void Scaler_scalerVIP_compute_level_I_002_RTNR2_tv002(SLR_VIP_TABLE* vipTable_shareMem, _clues* SmartPic_clue, _system_setting_info* system_info_structure_table, unsigned int MA_print_count);
void Scaler_scalerVIP_compute_level_I_002_RTNR0_tv002(SLR_VIP_TABLE* vipTable_shareMem, _clues* SmartPic_clue, _system_setting_info* system_info_structure_table, unsigned int MA_print_count);

#ifdef __cplusplus
}
#endif

#endif /* __SCALER_LIB_H__*/

