#ifndef ZOOM_SMOOTHTOGGLE_LIB_H_
#define ZOOM_SMOOTHTOGGLE_LIB_H_

#include "tvscalercontrol/scaler/scalerstruct.h"
#include "tvscalercontrol/scalerdrv/scalerdisplay.h"//uint8


void Set_vo_smoothtoggle_changeratio_flag2(unsigned char enable, unsigned char display);

//void Set_zoom_smoothtoggle_changeratio_flag(unsigned char enable);
//unsigned char Get_zoom_smoothtoggle_changeratio_flag(void);
void set_zoom_smoothtoggle_vo_hwid(unsigned int hwid);
unsigned int get_zoom_smoothtoggle_vo_hwid(unsigned char display);
void set_zoom_smoothtoggle_vo_vlen(unsigned int vlen);
unsigned int get_zoom_smoothtoggle_vo_vlen(unsigned char display);


unsigned char get_zoom_reset_double_state(unsigned char display);
void set_zoom_reset_double_state(unsigned char enable,unsigned char display);



//other scalerlib
void set_mainsubonpr_fuc(unsigned char value);
unsigned char get_mainsubonpr_fuc(void);
UINT8 Scaler_Get_EnterFRC_LastLine_DHtotal_Adjust_Enable_Flag(void);
void Scaler_Set_EnterFRC_LastLine_DHtotal_Adjust_Enable_Flag(UINT8 ucEnable);
ENUM_TVD_INPUT_FORMAT Scaler_Get_2D_VodmaIndex(void);

VO_VIDEO_PLANE Scaler_Get_2D_VoPlane(void);
VO_VIDEO_PLANE Scaler_Get_3D_VoPlane(void);

typedef enum _DISPLAY_DATA_SMOOTH_TOGGLE{
	SLR_DISPLAY_DEFAULT=0,  //go default flow for data frc and data fs
	SLR_DISPLAY_DATA_FRC,  //all go data frc
	SLR_DISPLAY_DATA_FRAME_SYNC,  //all go data fs
	SLR_DISPLAY_DATA_FS_NO_MEMORY,  //all go data fs and not  go di
	SLR_DISPLAY_DATA_FS_AND_CUSTOM_MODE,  //full panel go data fs,custom mode go data frc
	SLR_DISPLAY_DATA_FRC_FS_4K2K,  //2k1k go frc,4k2k go fs
}DISPLAY_DATA_SMOOTH_TOGGLE;

typedef enum _SOURCE_INFO_SMOOTH_TOGGLE
{
	SLR_SMOOTH_TOGGLE_NONE=0,
	SLR_SMOOTH_TOGGLE_INIT=1,
	SLR_SMOOTH_TOGGLE_ACTIVE,
	SLR_SMOOTH_TOGGLE_RELEASE,
}SOURCE_INFO_SMOOTH_TOGGLE;

//void Set_vo_smoothtoggle_timingchange_flag(unsigned char enable);
unsigned char Get_vo_smoothtoggle_timingchange_flag(unsigned char display);
//void Set_vo_smoothtoggle_changeratio_flag(unsigned char enable);
unsigned char Get_vo_smoothtoggle_changeratio_flag(unsigned char display);
void set_vo_smoothtoggle_state(SOURCE_INFO_SMOOTH_TOGGLE state, unsigned char display,unsigned char plane);
SOURCE_INFO_SMOOTH_TOGGLE get_vo_smoothtoggle_state(unsigned char display);
void vo_force_data_mode_set_enable(DISPLAY_DATA_SMOOTH_TOGGLE enable, unsigned char display);
DISPLAY_DATA_SMOOTH_TOGGLE vo_force_data_mode_get_enable(unsigned char display);
void smooth_toggle_state_info_rpc(unsigned char display);
void Smoothtoggle_sendVOupdate_flag(VO_VIDEO_PLANE plane,unsigned char flag);
void vgip_ratio_send_info(unsigned char hratio,unsigned char vratio,short h_start,short h_width,short v_start,short v_length);
void panel_parameter_send_info(void);
void smooth_toggle_update_scaler_info(void);
void Check_smooth_toggle_update_flag(unsigned char display);
void Share_Memory_Set_Scaler_Run_Flag(unsigned char enable);
void vo_smoothtoggle_memory_alloc(unsigned char display);
unsigned char smoothtoggle_vo_force_data_mode_set(int title);
unsigned char Get_vo_smoothtoggle_scaler_enable(void);
void Set_vo_smoothtoggle_scaler_enable(unsigned char enable);
void Set_direct_vo_smoothtoggle_enable(unsigned char enable,DISPLAY_DATA_SMOOTH_TOGGLE data_pach, unsigned char display,unsigned char plane);
void Set_direct_vo_stop_smoothtoggle(void);
void zoom_setcropflag(unsigned char enable);
unsigned char zoom_getcropflag(void);
void zoom_setdispflag(unsigned char enable);
unsigned char zoom_getdispflag(void);
void Set_send_panel_para_flag(unsigned char flag);
#ifdef CONFIG_MDOMAIN_RESERVED_MEMORY
void send_memory_mapping_for_adaptive_streaming(void);
#endif
void vodma_smoothtoggle_reset(unsigned char display,unsigned char plane);
void smooth_toggle_disconnect(unsigned char display,unsigned char plane);
void clear_imd_smooth_toggle_clk_time2switch_en(unsigned char display);


#endif
