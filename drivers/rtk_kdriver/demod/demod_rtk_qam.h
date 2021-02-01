#ifndef __DEMOD_REALTEK_I_QAM_H__
#define __DEMOD_REALTEK_I_QAM_H__

#include "demod.h"
#include "demod_rtk_def.h"


typedef struct {
	void*                       m_private;
	unsigned char               m_output_freq;
	REG_VALUE_ENTRY*            m_pTunerOptReg;
	unsigned int                m_TunerOptRegCnt;
	unsigned char               m_low_snr_detect;
	unsigned char               m_low_snr_recover;
    unsigned char               m_auto_tune_en;
	unsigned int				m_qam_AgcScale;
	unsigned int                m_qam_Invert;
	unsigned int				m_qam_ext_gain_dis;

	//int (*Activate)(struct sDEMOD *demod, unsigned char force_rst);
	//void (*Destory)(struct sDEMOD *demod);
} REALTEK_I_QAM;

void REALTEK_I_QAM_Constructors(DEMOD* pDemodKernel, unsigned char addr, 	unsigned char output_mode, unsigned char output_freq, COMM* pComm);
void REALTEK_I_QAM_Destructors(DEMOD* pDemodKernel);
int REALTEK_I_QAM_Init(DEMOD* pDemodKernel);
int REALTEK_I_QAM_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys);
int REALTEK_I_QAM_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam);
int REALTEK_I_QAM_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode);
int REALTEK_I_QAM_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam);
int REALTEK_I_QAM_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock);
int REALTEK_I_QAM_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int REALTEK_I_QAM_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id,	TV_SIG_QUAL* pQuality);
int REALTEK_I_QAM_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset);
int REALTEK_I_QAM_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize);
int REALTEK_I_QAM_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock);
int REALTEK_I_QAM_ScanSignal(DEMOD* pDemodKernel, long* pOffset, SCAN_RANGE range);
int REALTEK_I_QAM_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off);
int REALTEK_I_QAM_AutoTune(DEMOD* pDemodKernel);
int REALTEK_I_QAM_InspectSignal(DEMOD* pDemodKernel);
int REALTEK_I_QAM_Activate(DEMOD* pDemodKernel, unsigned char force_rst);
int REALTEK_I_QAM_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode);
void REALTEK_I_QAM_Lock(DEMOD* pDemodKernel);
void REALTEK_I_QAM_Unlock(DEMOD* pDemodKernel);
int REALTEK_I_QAM_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo);

#define REALTEK_I_QAM_DBG(fmt, args...)         rtd_printk_demod(KERN_DEBUG, "DEMO", "QAM_DEBUG, " fmt, ##args);
#define REALTEK_I_QAM_INFO(fmt, args...)       rtd_printk_demod(KERN_INFO, "DEMO", "QAM_INFO, " fmt, ##args);
#define REALTEK_I_QAM_WARNING(fmt, args...)    rtd_printk_demod(KERN_WARNING, "DEMO", "QAM_WARNING, " fmt, ##args);

#endif // __DEMOD_REALTEK_I_QAM_H__
