#ifndef __DEMOD_REALTEK_H_DTMB_HANDLE_H__
#define __DEMOD_REALTEK_H_DTMB_HANDLE_H__

//#include "demod_hd2311_def.h"
#include "demod_rtk_def.h"
#include "demod_rtk_dtmb_priv.h"


typedef struct {

	void*                       m_private;
	unsigned char               m_output_freq;
	REG_VALUE_ENTRY*            m_pTunerOptReg;
	unsigned int                m_TunerOptRegCnt;
	unsigned char               m_low_snr_detect;
	unsigned char               m_low_snr_recover;
	unsigned char               m_auto_tune_enable;
    unsigned char               m_auto_tune_reset;

	//int (*Activate)(struct sDEMOD *demod, unsigned char force_rst);
	//void (*Destory)(struct sDEMOD *demod);
} REALTEK_H_DTMB;



void REALTEK_H_DTMB_Constructors(DEMOD* pDemodKernel, unsigned char addr, 	unsigned char output_mode, unsigned char output_freq, COMM* pComm);
void REALTEK_H_DTMB_Destructors(DEMOD* pDemodKernel);

    
int REALTEK_H_DTMB_Init(DEMOD* pDemodKernel);
int REALTEK_H_DTMB_Reset(DEMOD* pDemodKernel);
int REALTEK_H_DTMB_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock);                         

int REALTEK_H_DTMB_ScanSignal(DEMOD* pDemodKernel, long* offset, SCAN_RANGE range);

int REALTEK_H_DTMB_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys);
int REALTEK_H_DTMB_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO*  pSigInfo);

int REALTEK_H_DTMB_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam);

int REALTEK_H_DTMB_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam);

int REALTEK_H_DTMB_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock);

int REALTEK_H_DTMB_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);    

int REALTEK_H_DTMB_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality);                      

int REALTEK_H_DTMB_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off);    

int REALTEK_H_DTMB_InspectSignal(DEMOD* pDemodKernel);

int REALTEK_H_DTMB_AutoTune(DEMOD* pDemodKernel);

int REALTEK_H_DTMB_Activate(DEMOD* pDemodKernel, unsigned char force_rst);

int REALTEK_H_DTMB_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode);

int REALTEK_H_DTMB_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset);

int REALTEK_H_DTMB_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode);

void REALTEK_H_DTMB_Lock(DEMOD* pDemodKernel);
void REALTEK_H_DTMB_Unlock(DEMOD* pDemodKernel);

#define REALTEK_H_DTMB_DBG(fmt, args...)         rtd_printk_demod(KERN_DEBUG, "DEMO","Dtmb Debug, " fmt, ##args);
#define REALTEK_H_DTMB_INFO(fmt, args...)        rtd_printk_demod(KERN_INFO, "DEMO","Dtmb Info, " fmt, ##args);
#define REALTEK_H_DTMB_WARNING(fmt, args...)     rtd_printk_demod(KERN_WARNING, "DEMO","Dtmb Warning, " fmt, ##args);

							 
#endif // __DEMOD_REALTEK_H_HD2311_DTMB_HANDLE_H__

