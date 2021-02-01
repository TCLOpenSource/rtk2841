#ifndef __SCALER_EYEGUARD_H__
#define __SCALER_EYEGUARD_H___

typedef enum {
	_WEG_VERY_DARK_STATE = 0,
	_WEG_DARK_STATE,
	_WEG_NORMAL_STATE,
	_WEG_LIGHT_STATE,
	_WEG_VERY_LIGHT_STATE,
	_WEG_STATE_MAX,
} WATCHING_EG_STATE;

typedef enum
{
	_LS_ISL29003_Command_Enable = 0,
	_LS_ISL29003_Command_adcPD,
	_LS_ISL29003_Command_Timing_Mode,
	_LS_ISL29003_Command_Mode,
	_LS_ISL29003_Command_width,
	_LS_ISL29003_Control_ext_mode,
	_LS_ISL29003_Control_test_mode,
	_LS_ISL29003_Control_int_flag,
	_LS_ISL29003_Control_gain,
	_LS_ISL29003_Control_int_persist,
	_LS_ISL29003_Read_Lux_Value
}LS_ISL29003_COMMAND;

typedef UINT32(*LIGHT_SENSOR_OPERATION_FUNCTION)(LS_ISL29003_COMMAND index, UINT16 Value);
#ifdef BUILD_TV013_1 //add shangbr
void  Scaler_Get_OPC_Energy_Value(int value);
void Scaler_Get_OPC_Energy_Step(int step);
void Set_OPC_PictureMode(unsigned char Flg);
unsigned char Get_OPC_PictureMode(void);
void Scaler_OPC_Launcher_Enable(unsigned char ucEnable);
#endif
#endif
