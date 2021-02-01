#ifndef __DEMOD_REALTEK_I_DVBS_H__
#define __DEMOD_REALTEK_I_DVBS_H__

#include "demod.h"
#include "demod_rtk_def.h"
/*
#define REALTEK_I_DVBS_MODE            0
#define REALTEK_I_DVBS2_MODE           1
#define REALTEK_I_SPEC_AN_CFO_MODE     2

#define BS_FFT_RESOLUTION            510000
#define CFO_FFT_RESOLUTION           500000
#define TUNER_STEP_TOLERANCE         2000000
#define NULL_SEC_ADDR                0
*/
/*
typedef struct _s_sDvbSLockTimeOut
{
    unsigned int SymbolRateKhz;
    unsigned int TimeOutMs;
}s_sDvbSLockTimeOut;
*/
typedef struct {
    void*                       m_private;
    unsigned char               m_output_freq;
    REG_VALUE_ENTRY*            m_pTunerOptReg;
    unsigned int                m_TunerOptRegCnt;
    TV_SIG_INFO                 m_info;
    unsigned char               m_auto_tune_en;
    unsigned char               m_dvbs_zapping_mode;
    unsigned char               m_dvbs_manual_code_rate;
    unsigned char               m_dvbs_manual_spec_invert;
    unsigned int                m_current_bw;
    unsigned int                m_PreUbc;
    unsigned int                m_AcqTimeOut;
    unsigned int                m_dvbs_snr;
    unsigned int                m_dvbs_pre_coderate;
    unsigned int                m_dvbs_pre_spectrum_inv;

    unsigned short              CapturedSpectrum_dvbs[1024];
    
    unsigned char               m_dvbs_ldr_mode;

    int                         m_dvbs_freq_offset;
    unsigned int                m_carrier_spectrum_len;
    unsigned int                m_carrier_signal_found;
    int                         m_carrier_signal_cfo;
    unsigned int                m_carrier_signal_csr;

    //int (*Activate)(struct sDEMOD *demod, unsigned char force_rst);
    //void (*Destory)(struct sDEMOD *demod);
} REALTEK_I_DVBS;

    void REALTEK_I_DVBS_Constructors(DEMOD* pDemodKernel, unsigned char addr,    unsigned char output_mode, unsigned char output_freq, COMM* pComm);
    void REALTEK_I_DVBS_Destructors(DEMOD* pDemodKernel);

    int REALTEK_I_DVBS_Init(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock);
    int REALTEK_I_DVBS_AcquireSignalEx(DEMOD* pDemodKernel, unsigned char WaitSignalLock, unsigned char  DiseqcCmdCnt, const unsigned char     *pDiseqcCmd);  
    int REALTEK_I_DVBS_GetChannelInfo(DEMOD* pDemodKernel, unsigned char* Modulation, unsigned char* CodeRate, unsigned char* PilotOnOff, unsigned char* Inverse);
    int REALTEK_I_DVBS_ScanSignal(DEMOD* pDemodKernel, long* offset, SCAN_RANGE range);
    int REALTEK_I_DVBS_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys);
    int REALTEK_I_DVBS_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo);
    int REALTEK_I_DVBS_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam);
    int REALTEK_I_DVBS_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode);
    int REALTEK_I_DVBS_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam);
    int REALTEK_I_DVBS_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock);
    int REALTEK_I_DVBS_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
    int REALTEK_I_DVBS_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality);
    int REALTEK_I_DVBS_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset);
    int REALTEK_I_DVBS_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize);
    int REALTEK_I_DVBS_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off);
    int REALTEK_I_DVBS_Activate(DEMOD* pDemodKernel, unsigned char force_rst);
    int REALTEK_I_DVBS_CalDvbSSsi(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS_CalDvbSSqi(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS_AutoTune(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS_InspectSignal(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE sys_type);
    int REALTEK_I_DVBS_SetDiseqcContinue22kOnOff(DEMOD* pDemodKernel, int OnOff);
    int REALTEK_I_DVBS_SetDiseqcCmd(DEMOD* pDemodKernel, unsigned int Length, unsigned char *Data);
    int REALTEK_I_DVBS_SetDiseqcUnModToneBurst(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS_SetDiseqcModToneBurst(DEMOD* pDemodKernel);
    
    int REALTEK_I_DVBS_GetSignalCarrierFrequencyOffset(DEMOD* pDemodKernel, int *SigCfo);
    int REALTEK_I_DVBS_CarrierAnalyzeSpectrum(DEMOD* pDemodKernel, unsigned char *SignalFound, unsigned int InputSigSr, int *SigCfo, unsigned int *SigCsr);
    //void REALTEK_I_DVBS_ReverseArray(unsigned short *pintArray, unsigned int intArraySize);
    int REALTEK_I_DVBS_SpecAnGetSpectrum(DEMOD* pDemodKernel, unsigned int Mode, unsigned short *SpectrumArray, unsigned int *SpectrumLength);
    int REALTEK_I_DVBS_SpecAnGetCp1Cp2(DEMOD* pDemodKernel, unsigned short *SpectrumArray, unsigned int CutTh, unsigned int CutSp, unsigned int CutEp, unsigned int *ReturnCp1, unsigned int *ReturnCp2);
    int REALTEK_I_DVBS_SpecAnCalCfoCsr(DEMOD* pDemodKernel, unsigned int Mode, unsigned int Cp1, unsigned int Cp2, int *SigCfo, unsigned int *SigCsr);
    int REALTEK_I_DVBS_SpecAnSearchMaxMin(DEMOD* pDemodKernel, unsigned short *SpectrumArray, unsigned int Sp, unsigned int Ep, unsigned int *MaxPower, unsigned int *MinPower);
    int REALTEK_I_DVBS_ChangeStandard(DEMOD* pDemodKernel, unsigned int Mode);

    void REALTEK_I_DVBS_Lock(DEMOD* pDemodKernel);
    void REALTEK_I_DVBS_Unlock(DEMOD* pDemodKernel);

#define REALTEK_I_DVBS_DBG(fmt, args...)        rtd_printk_demod(KERN_DEBUG, "DEMO", "DVBS_DEBUG, " fmt, ##args); 
#define REALTEK_I_DVBS_INFO(fmt, args...)      rtd_printk_demod(KERN_INFO, "DEMO", "DVBS_INFO, " fmt, ##args);
#define REALTEK_I_DVBS_WARNING(fmt, args...)   rtd_printk_demod(KERN_WARNING, "DEMO", "DVBS_WARNING, " fmt, ##args);

#endif // __DEMOD_REALTEK_I_DVBS_H__
