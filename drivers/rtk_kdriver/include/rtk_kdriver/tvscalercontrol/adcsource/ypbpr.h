#ifndef __YPBPR_H__
#define __YPBPR_H__

#ifdef __cplusplus
extern "C" {
#endif

//#include <rtd_types.h>
//#include <tvscalercontrol/scaler/source.h>
#define Mode_Table_Init_Index 0xff
#define AutoSOY_Calibration_Fast_Flow//Soy calibration Fast FLOW Will add

#define CLAMP_TO_BLACK          0
#define CLAMP_TO_MIDDLE        1
#define CLAMP_TO_SYNC            2
#define Y_CLAMP_METHOD      CLAMP_TO_BLACK

// 0x1802_0010[16] : Online Auto SOY ADC clock select
// 0: CK108M
// 1: YPbPr ADC clock (Set by APLL)
#define AUTO_SOY_CLK_CK108M			0
#define AUTO_SOY_CLK_YPBPR_ADC_CLK	1
#define SP_AUTO_SOY_CLK_INIT_SRC	AUTO_SOY_CLK_YPBPR_ADC_CLK
#define SP_AUTO_SOY_CLK_SRC		AUTO_SOY_CLK_YPBPR_ADC_CLK

#define SP_AUTO_SOY_CLK_SEL_INIT_STATE		0
#define SP_AUTO_SOY_CLK_SEL_NORMAL_STATE	1


#if (SP_AUTO_SOY_CLK_SRC == AUTO_SOY_CLK_CK108M)
#define AUTO_SOY_COMPARE_LEVEL			0x08
#define AUTO_SOY_DEB_VALID				0x0F
#define AUTO_SOY_DEB_UPDATE				0x0F
#define AUTO_SOY_COMPARE_LEVEL_OFFSET	0x03
#define AUTO_SOY_MAX_LEVEL_HB				0x38//will fix 20140411	Sirius	High boundary //0x32
#define AUTO_SOY_MAX_LEVEL_LB				0x05
#define AUTO_SOY_MIN_LEVEL_HB				0x28

#define AUTO_SOY_MIN_LEVEL_LB				0x05


#define AUTO_SOY_TRIGGER_DETECT_WIN		0x2710
#define AUTO_SOY_DET_ABNORMAL_LEVEL		0x28

// 0xb8020300[6], Compare level update option
// 0: Compare level update to the same value of DC leve
// 1: Compare level update reference to previous compare level
#define _COMPARE_LEVEL_REF_PREVIOUS_VALUE		0
#define _COMPARE_LEVEL_REF_SAME_VALUE	1
#define COMPARE_LEVEL_UPDATE_OPTION			_COMPARE_LEVEL_REF_PREVIOUS_VALUE

// 0xb8020300[5:4], Compare level update mode
// 0: Compare level update to the same value of DC leve
// 1: Compare level update reference to previous compare level
#define _UPDATE_MODE_0		0 // 00:normal
#define _UPDATE_MODE_1		1 // 01:1/2 of sync DC_level(i)-DC_level(i-1)
#define _UPDATE_MODE_2		2 // 01:1/4 of sync DC_level(i)-DC_level(i-1)
#define _UPDATE_MODE_4		3 // 10:1/8 of sync DC_level(i)-DC_level(i-1)
#define COMPARE_LEVEL_UPDATE_MODE		_UPDATE_MODE_0

// 0xb8020300[3:1], Moving average LPF mode select
// apply value = ( 2^COMPARE_LEVEL_MA_MODE ) taps
#define COMPARE_LEVEL_MA_MODE		3
// 0x1802_0308[20:16], Seek Max level window select
// 0x1802_0308[12:8], Seek Min level window select
// 0x1802_0308[5:0], Minimum difference threshold to update compare level
#define COMPARE_LEVEL_SEEK_MAX_WINDOW	0x10	//mac, mag use mac's setup
#define COMPARE_LEVEL_SEEK_MIN_WINDOW	0x10
#define COMPARE_LEVEL_SEEK_MIN_DIFF		0x05	//darwin
#define COMPARE_LEVEL_SEEK_MIN_DIFF		0x00 // 0x05	//mac, mag use mac's setup

// 0xb802030c[2:0], DC level detect mode select
#define _DC_OUT_MODE_0		0 // (Max+Min)/2, sets DC level to half of sync tip
#define _DC_OUT_MODE_1		1 // Max
#define _DC_OUT_MODE_2		2 // Min
#define _DC_OUT_MODE_4		4 // (Max+Min)/2 +(Max-Min)/4, sets DC level to 3/4 height of sync tip
#define _DC_OUT_MODE_5		5 // (Max+Min)/2 - (Max-Min)/4, sets DC level to 1/4 height of sync tip
#define DC_OUT_MODE_SEL	_DC_OUT_MODE_0 //_DC_OUT_MODE_5

#else //#if (SP_AUTO_SOY_CLK_SRC == AUTO_SOY_CLK_CK108M)

//#define AUTO_SOY_COMPARE_LEVEL				0x08	//darwin
#define AUTO_SOY_COMPARE_LEVEL				0x09	//mac, mag use mac's setup
#define AUTO_SOY_DEB_VALID					0x0F
#define AUTO_SOY_DEB_UPDATE					0x0F
//#define AUTO_SOY_COMPARE_LEVEL_OFFSET		0x02	//darwin
#define AUTO_SOY_COMPARE_LEVEL_OFFSET		0x03	//mac, mag use mac's setup
//#define AUTO_SOY_MAX_LEVEL_HB					0x32	//darwin
#define AUTO_SOY_MAX_LEVEL_HB					0x38//will fix 20140411	Sirius	High boundary //0x32	//mac, mag use mac's setup
#define AUTO_SOY_MAX_LEVEL_LB					0x05
#define AUTO_SOY_MIN_LEVEL_HB					0x28
//#define AUTO_SOY_MIN_LEVEL_LB					0x05
#define AUTO_SOY_MIN_LEVEL_LB					0x00
#define AUTO_SOY_TRIGGER_DETECT_WIN			0x2710
//#define AUTO_SOY_DET_ABNORMAL_LEVEL			0x28	//darwin
#define AUTO_SOY_DET_ABNORMAL_LEVEL			0x30	//mac, mag use mac's setup

// 0xb8020300[6], Compare level update option
// 0: Compare level update reference to previous compare level
// 1: Compare level update to the same value of DC level
#define _COMPARE_LEVEL_REF_PREVIOUS_VALUE		0
#define _COMPARE_LEVEL_REF_SAME_VALUE	1
#define COMPARE_LEVEL_UPDATE_OPTION			_COMPARE_LEVEL_REF_PREVIOUS_VALUE

// 0xb8020300[5:4], Compare level update mode
// 0: Compare level update to the same value of DC leve
// 1: Compare level update reference to previous compare level
#define _UPDATE_MODE_0		0 // 00:normal
#define _UPDATE_MODE_1		1 // 01:1/2 of sync DC_level(i)-DC_level(i-1)
#define _UPDATE_MODE_2		2 // 01:1/4 of sync DC_level(i)-DC_level(i-1)
#define _UPDATE_MODE_4		3 // 10:1/8 of sync DC_level(i)-DC_level(i-1)
#define COMPARE_LEVEL_UPDATE_MODE		_UPDATE_MODE_0

// 0xb8020300[3:1], Moving average LPF mode select
// apply value = ( 2^COMPARE_LEVEL_MA_MODE ) taps
#define COMPARE_LEVEL_MA_MODE		2

// 0x1802_0308[20:16], Seek Max level window select
// 0x1802_0308[12:8], Seek Min level window select
// 0x1802_0308[5:0], Minimum difference threshold to update compare level
#define COMPARE_LEVEL_SEEK_MAX_WINDOW	0x10 //0x10 //0x10 	//( modify from 0x1f to 0x10, avoid 1080p occur problem , trigger max level, may ic bug)
#define COMPARE_LEVEL_SEEK_MIN_WINDOW	0x10
//#define COMPARE_LEVEL_SEEK_MIN_DIFF		0x05	//darwin
#define COMPARE_LEVEL_SEEK_MIN_DIFF		0x00 // 0x05	//mac, mag use mac's setup

//#define COMPARE_LEVEL_NORMAL_SD_SEEK_MAX_WINDOW	0x08	//darwin
#define COMPARE_LEVEL_NORMAL_576I_SEEK_MAX_WINDOW	0x04	//Brandon fine tune for MSPG3233 576i
#define COMPARE_LEVEL_NORMAL_SD_SEEK_MAX_WINDOW	0x04	//mac, mag use mac's setup
#define COMPARE_LEVEL_NORMAL_SD_SEEK_MIN_WINDOW	0x10
#define COMPARE_LEVEL_NORMAL_SD_SEEK_MIN_DIFF		0x05

//#define COMPARE_LEVEL_NORMAL_HD_SEEK_MAX_WINDOW	0x10	//darwin
#define COMPARE_LEVEL_NORMAL_HD_SEEK_MAX_WINDOW	0x08	//mac, mag use mac's setup
#define COMPARE_LEVEL_NORMAL_HD_SEEK_MIN_WINDOW	0x10
#define COMPARE_LEVEL_NORMAL_SEEK_MIN_DIFF		0x05
#define COMPARE_LEVEL_NORMAL_1080_SEEK_MIN_DIFF		0x04

// 0xb802030c[2:0], DC level detect mode select
#define _DC_OUT_MODE_0		0 // (Max+Min)/2, sets DC level to half of sync tip
#define _DC_OUT_MODE_1		1 // Max
#define _DC_OUT_MODE_2		2 // Min
#define _DC_OUT_MODE_4		4 // (Max+Min)/2 +(Max-Min)/4, sets DC level to 3/4 height of sync tip
#define _DC_OUT_MODE_5		5 // (Max+Min)/2 - (Max-Min)/4, sets DC level to 1/4 height of sync tip
#define DC_OUT_MODE_SEL	_DC_OUT_MODE_0  //chengying modify for atlantic ic, because ic internal dc level is higher than usual

#endif //#if (SP_AUTO_SOY_CLK_SRC == AUTO_SOY_CLK_CK108M)

#define CLAMP_Y      0
#define CLAMP_NY    1
#define CLAMP_ALL	2

//disable auto soy function
#define SOY_CH0_MANUAL_COMPARE_LEVEL		0x12
#define SOY_CH1_MANUAL_COMPARE_LEVEL		0x12

//enable auto soy function
#define SOY_CH0_COMPARE_LEVEL		0x1E
#define SOY_CH1_COMPARE_LEVEL		0x1E

//ADC_CLAMP_CTRL0, SOY0 input MUX select
#define ADC_SOY_MUX_B0		0x7
#define ADC_SOY_MUX_G0		0x8
#define ADC_SOY_MUX_R0		0x9
#define ADC_SOY_MUX_B1		0xa
#define ADC_SOY_MUX_G1		0xb
#define ADC_SOY_MUX_R1		0xc
#define ADC_SOY_MUX_B2		0xd
#define ADC_SOY_MUX_G2		0xe
#define ADC_SOY_MUX_R2		0xf

#define ADC_UP_DOWN_CLAMP 1

#define _ENABLE 									1
#define _DISABLE									0
#define rtdf_setBits								IoReg_SetBits
#define rtdf_clearBits								IoReg_ClearBits
#define _MAIN_DISPLAY							SLR_MAIN_DISPLAY

typedef enum YPBPR_TABLE_TYPE{
	YPBPR_SCREENMODE,
	YPBPR_GAINOFFSET,
	YPBPR_VGAHPOS
}YPBPR_TABLE_TYPE;

typedef enum YPBPR_DETECT_STATE{
	YPBPR_SOY_STATE = 0,
	YPBPR_SIGNALTYPE_STATE,
	YPBPR_OFFLINE_STATE
}YPBPR_DETECT_STATE;

void YPbPr_SetPhase(unsigned char display, unsigned char phase, unsigned char uc64phase_limited);  //forster modified 071211
void YPbPr_ABL_SETTING_ON(unsigned int  CurModeIdx);
void YPbPr_ABL_SETTING_OFF(void);
void YPbPr_ABL_Margin_Setting(void);
void YPbPr_Setup(void);
void YPbPr_SetClampPulse(unsigned char sync_indicator, unsigned char Yclamp_start, unsigned char Yclamp_end, unsigned char nYclamp_start, unsigned char nYclamp_end,unsigned char select);
unsigned char YPbPr_DetectTiming_PadCheck(void);
void YPbPr_AutoSOY(void); // CSW+ 0961031 YPbPr auto SOY
unsigned char YPbPr_AutoSOY_Detect(void); // CSW+ 0980730 YPbPr auto SOY auto level detecct
void YPbPr_SetSOY_ADC_ClockSel(StructDisplayInfo * p_dispinfo, unsigned char state);

void YPbPr_DCRestore_Ctrl(unsigned char enable, ADC_DATA_PATH adc_path );
void YPbPr_Clamp_Ctrl(  unsigned char output_enable, ADC_DATA_PATH  adc_path, ADC_SOY_PATH soy_path);
void YPbPr_SetSOYCompareLevel(unsigned char soy_path, unsigned char value);
void YPbPr_ADCPowerControl(unsigned char on_off);

unsigned char  Scaler_Get_YPbPr_Auto_Soy_Enable(void);
void  Scaler_Set_YPbPr_Auto_Soy_Enable(unsigned char ucEnable);
void YPbPr_Connect_Setting(void);
void YPbPr_Negative_Clamp_DACSource(void);
unsigned char YPbPr_SetInput(StructSourceInput *input_pt);
unsigned char YPbPr_DetectTiming(void);
void YPbPr_DetectFail_NoSignal_Handler(void);
void YPbPr_DetectFail_Invalid_Handler(void);
void YPbPr_Power_ADCRGB(unsigned char enable);
unsigned char YPbPr_Check_DDS_Status(void); // Check DDS error or not. For check signal
unsigned char YPbPr_Small_Signal_precheck(void);
unsigned char YPbPr_Small_Signal_Check(void);
void YPbPr_SyncProc_TimingModeSetting(unsigned int CurModeIdx);
void YPbPr_Signal_Lock_Check(void);
unsigned char check_macrovision(unsigned int timing);
unsigned char macrovision_480i_setting(void);
unsigned char auto_phase_flow_bypass(void);
void set_auto_phase_flow_bypass_flag(unsigned char flag);

#ifdef AutoSOY_Calibration_Fast_Flow
void YPbPr_AutoSOY_Calibration_Fast(void);
#else
void YPbPr_AutoSOY_Calibration(void);
#endif

#ifdef __cplusplus
}
#endif

#endif //__YPBPR_H__

