/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2009
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for the main function and some initial functions.
 *
 * @author 	$Author: Jennifer $
 * @date 	$Date: 2017/03/16 14:30 $
 * @version 	$Revision: 0.1 $
 * @ingroup 	VIDEO_DECODER
 */

/**
 * @addtogroup vdc
 * @{
 */
#include <tvscalercontrol/vdc/video.h>

#ifdef __cplusplus
extern "C" {
#endif


extern unsigned char vdc_factory_mod_enable;
extern unsigned char vdc_factory_testdma_mode;
extern unsigned char vdc_factory_debugprint;

extern unsigned char drvif_module_vdc_Debug_Print_Get_Value(void);
extern void drvif_module_vdc_Debug_Print_Set(unsigned char On_Off);
extern void drvif_module_vdc_Debug_Print(unsigned char ucInputSrc);
///// VD 0 - DMA ////////////////////////////////////////////////////////////////////////////////////////
extern unsigned char drvif_module_vdc_DMACount_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_DMACount_Factory_Mode(unsigned char count);
extern void drvif_module_vdc_factory_TestDMA_Setting(void);
extern void drvif_module_vdc_factory_debug_get_dma_prefix(char* prefix);
extern unsigned char drvif_module_vdc_factory_TestDMA_mode_Get_info(void);
extern void drvif_module_vdc_factory_TestDMA_mode_select(unsigned char value);
extern void xDumpIFDRawData(unsigned int Length);
extern void xDumpVDRawData(unsigned int Length);
extern unsigned int drvif_module_vdc_factory_TestDMA_Enable(unsigned int Length);
extern unsigned int drvif_module_vdc_factory_IFDDMA_Enable(unsigned int Length);
///// VD 1 - status ////////////////////////////////////////////////////////////////////////////////////////
extern unsigned char drvif_module_vdc_H_Lock_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_V_Lock_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_C_Lock_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_Nosignal_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_Vsync_Cntl_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_NewV_Lock_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_Read_New_Vdetect_Factory_Get_info(void);
extern void drvif_module_vdc_New_Vdetect_setting_Factory_mode(unsigned char value);
extern unsigned char drvif_module_vdc_Read_Vcr_Flag_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_625_Flag_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_625_mode_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_625_mode_setting_Factory_mode(unsigned char value);
extern unsigned char drvif_module_vdc_NoiseStatus_Factory_Mode_Get_info(void);
extern unsigned int drvif_module_vdc_V_1st_line_Factory_Mode_Get_info(void);
extern unsigned int drvif_module_vdc_V_2nd_line_Factory_Mode_Get_info(void);
extern unsigned short drvif_module_vdc_Vline_Freerun_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_FIFO_status_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_3D_Frame_Buffer_Error_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_MV_flag_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_MV_check_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_MV_check_Factory_Mode_Set(unsigned char on_off);
///// VD 2 - clamp ////////////////////////////////////////////////////////////////////////////////////////
extern unsigned char drvif_module_vdc_Read_ClampMode_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_ClampMode_Factory_Mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_clamp_rc_rate_enable_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_clamp_rc_rate_enable_Factory_Mode_Set(unsigned char on_off);
extern unsigned char drvif_module_vdc_clamp_rc_rate_value_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_clamp_rc_rate_value_Factory_Mode_Set(unsigned char ivalue);
extern unsigned char drvif_module_vdc_Vsync_Clamp_mode_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Vsync_Clamp_mode_Factory_Mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_Vsync_Ctrl_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Vsync_Ctrl_Factory_Mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_clamp_delay_Enable_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_clamp_delay_Enable_Factory_mode_set(unsigned char on_off);
extern unsigned char drvif_module_vdc_clamp_delay_value_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_clamp_delay_value_Factory_mode_set(unsigned char ucValue);
///// VD 3 - HVC ////////////////////////////////////////////////////////////////////////////////////////
extern unsigned char drvif_module_vdc_Read_Hstate_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_Hstate_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Hstate_Factory_Mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_Hsync_start_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Hsync_start_Factory_Mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_Read_Vstate_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_Vstate_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Vstate_Factory_Mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_Read_Cstate_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_Cstate_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Cstate_Cactory_Mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_AVG_BURST_MAG_STATUS(void);
extern unsigned char drvif_module_vdc_Auto_Burst_position_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Auto_Burst_position_enable_Factory_Mode_Set(void);
extern unsigned char drvif_module_vdc_user_ckill_mode_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_user_ckill_mode_Factory_Mode(unsigned char mode);
extern unsigned char  drvif_module_vdc_Chroam_Level_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Chroam_Level_Factory_Mode(unsigned char value);
///// VD 4 - Gain ////////////////////////////////////////////////////////////////////////////////////////
extern unsigned short drvif_module_vdc_Dgain_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_Dgain_Write_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Dgain_Write_Factory_Mode(unsigned char value);
extern unsigned char drvif_module_vdc_Fix_Dgain_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Fix_Dgain_Factory_Mode(unsigned char on_off);
extern unsigned short drvif_module_vdc_Cgain_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_Cagc_Write_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Cagc_Write_Factory_Mode(unsigned char value);
extern unsigned char drvif_module_vdc_Fix_Cagc_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Fix_Cagc_Factory_Mode(unsigned char on_off);
extern unsigned int drvif_module_vdc_Hdto_Factory_Mode_Get_info(void);
extern unsigned int drvif_module_vdc_Cdto_Factory_Mode_Get_info(void);
///// VD 5 - Fliter ////////////////////////////////////////////////////////////////////////////////////////
extern unsigned char drvif_module_vdc_27M_Lpf_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_27M_Lpf_Factory_Mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_27M_table_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_27M_table_Factory_Mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_108M_Lpf_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_108M_Lpf_Factory_Mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_secamf_sel_Factory_Get_info(void);
extern void drvif_module_vdc_secamf_sel_Factory_mode_set(unsigned char value);
extern unsigned char drvif_module_vdc_secam2_Factory_Get_info(void);
extern void drvif_module_vdc_secam2_Factory_mode_set(unsigned char value);
extern unsigned char drvif_module_vdc_443358pk_sel_Factory_Get_info(void);
extern void drvif_module_vdc_443358pk_sel_Factory_mode_set(unsigned char value);
extern unsigned char drvif_module_vdc_443power_Factory_Get_info(void);
extern unsigned char drvif_module_vdc_358power_Factory_Get_info(void);
extern unsigned char drvif_module_vdc_443thr_Factory_Get_info(void);
extern void drvif_module_vdc_443thr_Factory_mode_set(unsigned char value);
extern unsigned char drvif_module_vdc_358thr_Factory_Get_info(void);
extern void drvif_module_vdc_358thr_Factory_mode_set(unsigned char value);
///// VD 6 - PQ ////////////////////////////////////////////////////////////////////////////////////////
extern unsigned char drvif_module_vdc_PQ_Bypass_Factory_Get_info(void);
extern void drvif_module_vdc_PQ_Bypass_Factory_mode_set(unsigned char on_off);
extern unsigned char drvif_module_vdc_1D3Dpos_Factory_Get_info(void);
extern void drvif_module_vdc_1D3Dpos_Factory_mode_set(unsigned char value);
extern unsigned char drvif_module_vdc_Read_Contrast_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Contrast_Factory_Mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_Read_Brightness_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Brightness_Factory_Mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_Read_Saturation_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_Saturation_Factory_Mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_YcDelay_Factory_Get_info(void);
extern void drvif_module_vdc_YcDelay_Factory_mode_Set(unsigned char value);
//////////// y1 cb1 cr1 delay enable /////////////////////////////////////////////////////////////////////////////////
extern unsigned char drvif_module_vdc_Y1Delay_Enable_Factory_Get_info(void);
extern void drvif_module_vdc_Y1Delay_Enable_Factory_mode_Set(unsigned char bEnable);
extern unsigned char drvif_module_vdc_Cb1Delay_Enable_Factory_Get_info(void);
extern void drvif_module_vdc_Cb1Delay_Enable_Factory_mode_Set(unsigned char bEnable);
extern unsigned char drvif_module_vdc_Cr1Delay_Enable_Factory_Get_info(void);
extern void drvif_module_vdc_Cr1Delay_Enable_Factory_mode_Set(unsigned char bEnable);
//////////// y1 cb1 cr1 delay value /////////////////////////////////////////////////////////////////////////////////
extern unsigned char drvif_module_vdc_Y1Delay_Value_Factory_Get_info(void);
extern void drvif_module_vdc_Y1Delay_Value_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_Cb1Delay_Value_Factory_Get_info(void);
extern void drvif_module_vdc_Cb1Delay_Value_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_Cr1Delay_Value_Factory_Get_info(void);
extern void drvif_module_vdc_Cr1Delay_Value_Factory_mode_Set(unsigned char value);
//////////// ckill y delay enable and value /////////////////////////////////////////////////////////////////////////////////
extern unsigned char drvif_module_vdc_ckill_YDelay_Enable_Factory_Get_info(void);
extern void drvif_module_vdc_ckill_YDelay_Enable_Factory_mode_Set(unsigned char bEnable);
extern unsigned char drvif_module_vdc_ckill_YDelay_Value_Factory_Get_info(void);
extern void drvif_module_vdc_ckill_YDelay_Value_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_SCART_contrast_Factory_Get_info(void);
extern void drvif_module_vdc_SCART_contrast_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_SCART_brightness_Factory_Get_info(void);
extern void drvif_module_vdc_SCART_brightness_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_SCART_saturationCr_Factory_Get_info(void);
extern void drvif_module_vdc_SCART_saturationCr_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_SCART_saturationCb_Factory_Get_info(void);
extern void drvif_module_vdc_SCART_saturationCb_Factory_mode_Set(unsigned char value);
///// VD 7 - AD_DA ////////////////////////////////////////////////////////////////////////////////////////
extern unsigned char drvif_module_vdc_AVin_Factory_Get_info(void);
extern unsigned char drvif_module_vdc_AVgnd_Factory_Get_info(void);
extern unsigned char drvif_module_vdc_AVout_enable_Factory_Get_info(void);
extern void drvif_module_vdc_AVout_enable_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_AVout_mode_Factory_Get_info(void);
extern void drvif_module_vdc_AVout_mode_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_AVout_delay_Factory_Get_info(void);
extern void drvif_module_vdc_AVout_delay_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_SCART_en_Factory_Get_info(void);
extern void drvif_module_vdc_SCART_en_Factory_mode_Set(unsigned char on_off);
extern unsigned char drvif_module_vdc_SCART_fb_sw_Factory_Get_info(void);
extern void drvif_module_vdc_SCART_fb_sw_Factory_mode_Set(unsigned char on_off);
extern unsigned char drvif_module_vdc_SCART_fb_en_Factory_Get_info(void);
extern void drvif_module_vdc_SCART_fb_en_Factory_mode_Set(unsigned char on_off);
extern unsigned char drvif_module_vdc_SCART_fbgain_en_Factory_Get_info(void);
extern void drvif_module_vdc_SCART_fbgain_en_Factory_mode_Set(unsigned char on_off);
extern unsigned char drvif_module_vdc_SCART_FSW_value_Factory_Get_info(void);
extern unsigned char drvif_module_vdc_rgb_output_en_Factory_Get_info(void);
extern void drvif_module_vdc_rgb_output_en_Factory_mode_Set(unsigned char on_off);
extern unsigned short drvif_module_vdc_Rgain_Factory_Get_info(void);
extern void drvif_module_vdc_Rgain_Factory_mode_Set(unsigned short value);
extern unsigned short drvif_module_vdc_Ggain_Factory_Get_info(void);
extern void drvif_module_vdc_Ggain_Factory_mode_Set(unsigned short value);
extern unsigned short drvif_module_vdc_Bgain_Factory_Get_info(void);
extern void drvif_module_vdc_Bgain_Factory_mode_Set(unsigned short value);
extern unsigned char drvif_module_vdc_Roffset_Factory_Get_info(void);
extern void drvif_module_vdc_Roffset_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_Goffset_Factory_Get_info(void);
extern void drvif_module_vdc_Goffset_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_Boffset_Factory_Get_info(void);
extern void drvif_module_vdc_Boffset_Factory_mode_Set(unsigned char value);
extern void drvif_module_vdc_Scart_calibration_en(void);
///// VD 8 - SECAM ////////////////////////////////////////////////////////////////////////////////////////
extern unsigned char drvif_module_vdc_Read_SECAM_Flag_Factory_Get_info(void);
extern unsigned char drvif_module_vdc_Read_New_SECAM_Flag_Factory_Get_info(void);
extern unsigned char drvif_module_vdc_PreferMode_Factory_Get_info(void);
extern void drvif_module_vdc_PreferMode_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_OldSecamCondi_Factory_Get_info(void);
extern void drvif_module_vdc_OldSecamCondi_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_Secam_Drdb_vlpf_Factory_Get_info(void);
extern void drvif_module_vdc_Secam_Drdb_vlpf_Factory_mode_Set(unsigned char on_off);
extern unsigned char drvif_module_vdc_Secam_FixDTO_Factory_Get_info(void);
extern void drvif_module_vdc_Secam_DrdbFreq_Factory_mode_Set(unsigned char on_off);
extern unsigned char drvif_module_vdc_Secam_DrdbFreq_Factory_Get_info(void);
extern void drvif_module_vdc_Secam_FixDTO_Factory_mode_Set(unsigned char on_off);
extern unsigned char drvif_module_vdc_Secam_Y_en_Factory_Get_info(void);
extern void drvif_module_vdc_Secam_Y_en_Factory_mode_Set(unsigned char on_off);
extern unsigned char drvif_module_vdc_Secam_hpf_Factory_Get_info(void);
extern void drvif_module_vdc_Secam_hpf_Factory_mode_Set(unsigned char hpf_sel);
extern unsigned char drvif_module_vdc_Secam_lpf_Factory_Get_info(void);
extern void drvif_module_vdc_Secam_lpf_Factory_mode_Set(unsigned char lpf_sel);
extern unsigned char drvif_module_vdc_Secam_notch_Factory_Get_info(void);
extern void drvif_module_vdc_Secam_notch_Factory_mode_Set(unsigned char notch_sel);
extern unsigned char drvif_module_vdc_Secam_gp_en_Factory_Get_info(void);
extern void drvif_module_vdc_Secam_gp_en_Factory_mode_Set(unsigned char on_off);
extern unsigned char drvif_module_vdc_Secam_gp_step_Factory_Get_info(void);
extern void drvif_module_vdc_Secam_gp_step_Factory_mode_Set(unsigned char value);
extern unsigned char drvif_module_vdc_Secam_gp_thl_Factory_Get_info(void);
extern void drvif_module_vdc_Secam_gp_thl_Factory_mode_Set(unsigned char value);




//=====================================================================================
extern unsigned char drvif_module_vdc_TV_DCTIeh_Factory_Mode_Get_Value(void);
extern unsigned char drvif_module_vdc_TV_DCTIeh_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_TV_DCTIeh_Factory_Mode(unsigned char mode);
extern void drvif_module_vdc_YcSeparation_Factory_Mode(unsigned char set_mode);
extern unsigned char drvif_module_vdc_YcSeparation_Factory_Mode_Get_info(void);
#if 0 // mark for non-used function in kernel, CSFC 20160728
extern void scaler_3d_talbe_Factory_Mode(unsigned char value);
#endif
extern void drvif_module_vdc_Set3DTableIndex(unsigned char index);
extern unsigned char drvif_module_vdc_Get3DTableIndex(void);
extern void drvif_module_vdc_Set_DCTI_Setting_Factory_Mode(unsigned char level);
extern unsigned char drvif_module_vdc_Set_DCTI_Setting_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_2D_Chroma_Bw_lo_Factory_Mode(unsigned char value);
extern unsigned char drvif_module_vdc_2D_Chroma_Bw_lo_Factory_Mode_Get_info(void);
extern unsigned char drvif_module_vdc_Chroma_Vertical_Lpf_enable_Get_info(void);
extern void drvif_module_vdc_Vsync_Cntl_Factory_Mode(unsigned char value);
extern void drvif_module_vdc_Vsync_Clamp_mode_Factory_Mode(unsigned char value);
extern void drvif_module_vdc_2D_Wide_BPF_Sel_Y_Factory_Mode(unsigned char value);
extern unsigned char drvif_module_vdc_2D_Wide_BPF_Sel_Y_Factory_Get_info(void);
extern void drvif_module_vdc_2D_Narrow_BPF_Sel_Y_Factory_Mode(unsigned char value);
extern unsigned char drvif_module_vdc_2D_Narrow_BPF_Sel_Y_Factory_Get_info(void);
extern void drvif_module_vdc_2D_Wide_BPF_Sel_C_Factory_Mode(unsigned char value);
extern unsigned char drvif_module_vdc_2D_Wide_BPF_Sel_C_Factory_Get_info(void);
extern void drvif_module_vdc_2D_Narrow_BPF_Sel_C_Factory_Mode(unsigned char value);
extern unsigned char drvif_module_vdc_2D_Narrow_BPF_Sel_C_Factory_Get_info(void);
extern void drvif_module_vdc_H2V_Vflag_Remg_thr_Factory_Mode(unsigned char value);
extern unsigned char drvif_module_vdc_H2V_Vflag_Remg_thr_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_H2V_Vflag_Mag_thr_Factory_Mode(unsigned char value);
extern unsigned char drvif_module_vdc_H2V_Vflag_Mag_thr_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_H2V_Vflag_Noise_thr_Factory(unsigned char value);
extern unsigned char drvif_module_vdc_H2V_Vflag_Noise_thr_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_H2V_Vflag_Max_HDY_Factory(unsigned char value);
extern unsigned char drvif_module_vdc_H2V_Vflag_Max_HDY_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_H2V_Vflag_Noise_YADDC_Factory(unsigned char value);
extern unsigned char drvif_module_vdc_H2V_Vflag_Noise_YADDC_Factory_Mode_Get_info(void);
extern void drvif_module_vdc_H2V_Vflag_Blend_Ratio_Factory(unsigned char value);
extern unsigned char drvif_module_vdc_H2V_Vflag_Blend_Ratio_Factory_Get_info(void);

bool drvif_module_vdc_CheckFactoryModEnable(unsigned char enable);
void drvif_module_vdc_SetFactoryModEnable(unsigned char enable);

#ifdef __cplusplus
}
#endif
