#ifndef __SCALER_AVDCTRL_VD
#define  __SCALER_AVDCTRL_VD

extern void Check_PLL27X_Settings(void);
extern void AVD_Memory_Allocate(void);
extern void AVD_Memory_Free(void);
void VDTimer(unsigned long arg);
extern void VD_recheck_625flag_loop(unsigned char *flag);
extern char Scaler_AVD_Timer_Init(void);
extern void Scaler_AVD_Timer_Delete(void);
extern void Scaler_AVD_ClearTiming(void);
extern unsigned char Scaler_AVD_Break_DetectTiming(void);
extern void Scaler_AVD_Set_DetTiming_In_AutoScan_Flag(unsigned char a_ucFlag);
extern unsigned char Scaler_AVD_DetectTiming(void);
void Scaler_AVD_Set_Scart_Mode(void);
extern void AVD_Suspend(void);
extern void AVD_Resume(void);



#endif

