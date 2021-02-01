#ifndef __SCALER_ADC_H__
#define __SCALER_ADC_H__
//#define NEED_SELFAWB/*For do self calibration*/
void ADC_Open(void);
void ADC_Close(void);
unsigned char ADC_Connect(int srcType, unsigned short srcinput);
void ADC_CRT_Setting(unsigned char enable);
void ADC_Power_Control(unsigned char on_off);
void ADC_Initial_Setting(void);
void ADC_ABL_Setting_Off(void);
void ADC_Initial(void);
StructDisplayInfo * Get_ADC_Dispinfo(void);
ModeInformationType * Get_ADC_Timinginfo(void);
void ADC_OnlineMeasureError_Handler(int srcType);
void ADC_VSC_Setting(int src);
void ADC_Reset_TimingInfo(void);
unsigned short Get_ADC_PhaseValue(void);
void Set_ADC_PhaseValue(unsigned short phasevalue);
void ADC_Disable_AHS_SMT_Power(void);
unsigned char decide_adc_standby_mode(void);
void adc_standby_mode(unsigned char enable);
#ifdef CONFIG_PM
void ADC_Suspend(void);
void ADC_Resume(void);
#endif


#endif
