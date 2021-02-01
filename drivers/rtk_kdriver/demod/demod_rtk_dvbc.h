#ifndef __DEMOD_REALTEK_I_DVBC_H__
#define __DEMOD_REALTEK_I_DVBC_H__

#include "demod.h"
#include "demod_rtk_def.h"

typedef struct {
	void*                       m_private;
	unsigned char               m_output_freq;
	REG_VALUE_ENTRY*            m_pTunerOptReg;
	unsigned int                m_TunerOptRegCnt;
	TV_SIG_INFO                 m_info;
	unsigned char               m_auto_tune_en;
	unsigned int                m_dvbc_AgcScale;
        unsigned int                m_dvbc_Invert;
	unsigned int                m_dvbc_ext_gain_dis;
        unsigned long               m_acquire_stime;
	unsigned char               m_debug_tool_en;

	//int (*Activate)(struct sDEMOD *demod, unsigned char force_rst);
	//void (*Destory)(struct sDEMOD *demod);
} REALTEK_I_DVBC;




void REALTEK_I_DVBC_Constructors(DEMOD* pDemodKernel, unsigned char addr, 	unsigned char output_mode, unsigned char output_freq, COMM* pComm);
void REALTEK_I_DVBC_Destructors(DEMOD* pDemodKernel);
int REALTEK_I_DVBC_Init(DEMOD* pDemodKernel);
int REALTEK_I_DVBC_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys);
int REALTEK_I_DVBC_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam);
int REALTEK_I_DVBC_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode);
int REALTEK_I_DVBC_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam);
int REALTEK_I_DVBC_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock);
int REALTEK_I_DVBC_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int REALTEK_I_DVBC_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id,	TV_SIG_QUAL* pQuality);
int REALTEK_I_DVBC_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset);
int REALTEK_I_DVBC_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize);
int REALTEK_I_DVBC_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock);
int REALTEK_I_DVBC_ScanSignal(DEMOD* pDemodKernel, long* pOffset, SCAN_RANGE range);
int REALTEK_I_DVBC_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off);
int REALTEK_I_DVBC_AutoTune(DEMOD* pDemodKernel);
int REALTEK_I_DVBC_InspectSignal(DEMOD* pDemodKernel);
int REALTEK_I_DVBC_Activate(DEMOD* pDemodKernel, unsigned char force_rst);
int REALTEK_I_DVBC_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode);
void REALTEK_I_DVBC_Lock(DEMOD* pDemodKernel);
void REALTEK_I_DVBC_Unlock(DEMOD* pDemodKernel);
int REALTEK_I_DVBC_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo);
unsigned int ResetDemodDvbc(DEMOD* pDemodKernel);

#define REALTEK_I_DVBC_DBG(fmt, args...)       rtd_printk_demod(KERN_DEBUG, "DEMO", "DVBC_DEBUG, " fmt, ##args); 
#define REALTEK_I_DVBC_INFO(fmt, args...)       rtd_printk_demod(KERN_INFO, "DEMO", "DVBC_INFO, " fmt, ##args);
#define REALTEK_I_DVBC_WARNING(fmt, args...)    rtd_printk_demod(KERN_WARNING, "DEMO", "DVBC_WARNING, " fmt, ##args);

#endif // __DEMOD_REALTEK_I_DVBC_H__
