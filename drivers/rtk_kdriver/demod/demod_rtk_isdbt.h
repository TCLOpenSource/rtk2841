#ifndef __DEMOD_REALTEK_I_ISDBT_HANDLE_H__
#define __DEMOD_REALTEK_I_ISDBT_HANDLE_H__

#include "demod.h"
#include "demod_rtk_def.h"



typedef struct {
	void*                       m_private;
	unsigned char               m_output_freq;
	TV_SIG_INFO                 m_SigInfo;
	REG_VALUE_ENTRY*            m_pTunerOptReg;
	unsigned int                m_TunerOptRegCnt;
	unsigned char               m_low_snr_detect;
	unsigned char               m_low_snr_recover;
	unsigned char               m_auto_tune_enable;
	unsigned int                m_current_bw;
	unsigned int                m_PreUbc;
	unsigned int                m_AgcScale;
	unsigned int                m_Invert;
	unsigned int		     	m_ext_gain_dis;	   

	//int (*Activate)(struct sDEMOD *demod, unsigned char force_rst);
	//void (*Destory)(struct sDEMOD *demod);
} REALTEK_I_ISDB;

void REALTEK_I_ISDBT_Constructors(DEMOD* pDemodKernel, unsigned char addr, 	unsigned char output_mode, unsigned char output_freq, COMM* pComm);
void REALTEK_I_ISDBT_Destructors(DEMOD* pDemodKernel);
int REALTEK_I_ISDBT_Init(DEMOD* pDemodKernel);
int REALTEK_I_ISDBT_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys);
int REALTEK_I_ISDBT_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam);
int REALTEK_I_ISDBT_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode);
int REALTEK_I_ISDBT_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam);
int REALTEK_I_ISDBT_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock);
int REALTEK_I_ISDBT_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int REALTEK_I_ISDBT_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id,	TV_SIG_QUAL* pQuality);
int REALTEK_I_ISDBT_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset);
int REALTEK_I_ISDBT_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize);
int REALTEK_I_ISDBT_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock);
int REALTEK_I_ISDBT_ScanSignal(DEMOD* pDemodKernel, long* pOffset, SCAN_RANGE range);
int REALTEK_I_ISDBT_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off);
int REALTEK_I_ISDBT_AutoTune(DEMOD* pDemodKernel);
int REALTEK_I_ISDBT_InspectSignal(DEMOD* pDemodKernel);
int REALTEK_I_ISDBT_Activate(DEMOD* pDemodKernel, unsigned char force_rst);
int REALTEK_I_ISDBT_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode);
void REALTEK_I_ISDBT_Lock(DEMOD* pDemodKernel);
void REALTEK_I_ISDBT_Unlock(DEMOD* pDemodKernel);
int REALTEK_I_ISDBT_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo);
int REALTEK_I_ISDBT_GetSegmentNum(DEMOD* pDemodKernel, int layerIndex, unsigned char* pNum);
unsigned int ResetDemod(DEMOD* pDemodKernel);

unsigned int IMGConstel2Rtk(unsigned int constel);
unsigned int IMGCoderate2Rtk(unsigned int coderate);
unsigned int IMGTimeintlv2Rtk(unsigned int timeintlv);
int REALTEK_I_ISDBT_CalSsi(DEMOD* pDemodKernel, int Prec);

#define REALTEK_I_ISDBT_DBG(fmt, args...)      rtd_printk_demod(KERN_DEBUG, "DEMO", "ISDBT_DEBUG, " fmt, ##args);
#define REALTEK_I_ISDBT_INFO(fmt, args...)      rtd_printk_demod(KERN_INFO, "DEMO", "ISDBT_INFO, " fmt, ##args);
#define REALTEK_I_ISDBT_WARNING(fmt, args...)      rtd_printk_demod(KERN_WARNING, "DEMO", "ISDBT_WARNING, " fmt, ##args);


#endif // __DEMOD_REALTEK_I_ISDBT_HANDLE_H__
