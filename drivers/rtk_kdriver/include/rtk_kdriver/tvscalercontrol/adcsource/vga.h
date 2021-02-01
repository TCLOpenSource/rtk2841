#ifndef __VGA_H__
#define __VGA_H__

typedef enum VGA_DETECT_STATE{
	VGA_HVSYNC_STATE = 0,
	VGA_SIGNALTYPE_STATE,
	VGA_OFFLINE_STATE
}VGA_DETECT_STATE;

/*==================== API ================= */
void drvif_vga_auto_table_init(void);
void fw_dvi_frc_setting(void);
void VGA_Detect_SyncType_Init(void);
unsigned char VGA_Detect_SyncTypeMode(void);
void VGA_SyncProc_Init(void);
void VGA_ADCPowerControl(unsigned char on_off);
void VGA_SP_ModeSetting(void);
void VGA_ABL_Enable_Control(unsigned char ctrl);
void VGA_ABL_Margin_Setting(void);
void VGA_Negative_Clamp_DACSource(void);

unsigned char  Scaler_Get_VGA_Support_SOG(void);
unsigned char  Scaler_Get_VGA_Support_Composite_Sync(void);
void VGA_DCRestore_Ctrl(unsigned char enable, ADC_DATA_PATH adc_path );
void VGA_Clamp_Ctrl(unsigned char output_enable, ADC_DATA_PATH adc_path, ADC_SOY_PATH soy_path);
void VGA_SetSOGCompareLevel(unsigned char soy_path, unsigned char value);

/*
 * Add for VGA, rzhen @2017-02-23, START
 */

void VGA_Connect_Setting(void);
unsigned char VGA_SetInput(StructSourceInput *input_pt);
unsigned char VGA_DetectTiming_PadCheck(void);
unsigned char VGA_DetectTiming(void);

void VGA_Setup(void);
void drvif_vga_init_table(void);

unsigned char Scaler_AdjustPCAuto(unsigned char display);
unsigned char Scaler_GetHPosition(void);
unsigned char Scaler_GetVPosition(void);
unsigned char Scaler_GetPhase(void);
unsigned char Scaler_GetClock(void);
unsigned char Scaler_SetHPosition(unsigned char value);	//range 0~100
unsigned char Scaler_SetVPosition(unsigned char value);	//range 0~100
void Scaler_SetPhase(unsigned char value);	//range 0~100
void Scaler_SetClock(unsigned char value);	//range 0~100

unsigned char drvif_adc_auto_config(StructScreenModeInfo *p_screenInfo, unsigned char display);
StructScreenModeInfo* get_vga_auto_data(unsigned int timing_index);
unsigned char check_vga_auto_calib_status(void);//check vga current timing already run auto config or not	



#endif // __VGA_H__

