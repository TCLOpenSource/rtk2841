/**
* @file ifd.h
*
* @author
* @email
* @date 2007/3/21
* @version 1.0
* @ingroup ifd
*
*/


#ifndef _IFD_FACTORYMODE_H_
#define _IFD_FACTORYMODE_H_


#ifdef __cplusplus
extern "C" {
#endif

#include <tvscalercontrol/frontend/ifd_rtd296x.h>

#ifndef CONFIG_Tuner_Max_NUMBER
#define CONFIG_Tuner_Max_NUMBER 1
#endif
#ifndef _Tuner_MAX_NO
#define _Tuner_MAX_NO CONFIG_Tuner_Max_NUMBER
#endif

#define IFD_TUNER_BAND_MAX 24
#define IFD_TUNER_REG_MAX 4
#define IFD_TUNER_REG_BAND_MAX IFD_TUNER_BAND_MAX*IFD_TUNER_REG_MAX
#define IFD_CR_BPF_TABLE_SIZE 41
#define IFD_OUTPUT_LPF_TABLE_SIZE 96
#define IFD_EQ_TABLE_SIZE (32)
#define IFD_GP_BPF_TABLE_SIZE 34
#define IFD_INPUT_FILTER_TABLE_SIZE 72

typedef struct
{
    UINT16	CrBpf_Table[IFD_CR_BPF_TABLE_SIZE];
} StructCrBpfNew;

typedef struct
{
    UINT8	tunerI2C_ADD;
    UINT32	tunerMinFreq;
    UINT32	tunerVHF_LowFreq;
    UINT32	tunerVHF_HighFreq;
    UINT32	tunerMaxFreq;
    UINT32	tunerPIF;
    UINT32	tunerPIF_MN;
    UINT32 	tunerPIF_B;
    UINT32	tunerPIF_GH;
    UINT32	tunerPIF_I;
    UINT32	tunerPIF_DK;
    UINT32	tunerPIF_L;
    UINT32	tunerPIF_LA;
    UINT32	tunerPIF_SCAN;
    bool		tunerIFType;
    UINT32	tunerRATIOStepSize;
    UINT32	tunerBandFreq[IFD_TUNER_BAND_MAX];
    UINT8	tunerRegisterByte[IFD_TUNER_REG_BAND_MAX];
    UINT8	tunerRegisterByteSearch[IFD_TUNER_REG_BAND_MAX];
    UINT8	tunerRfInputSwitchUsedTag;
    UINT8	tunerRfInputByte;
    UINT8	tunerRfInputLocation;
    UINT8	tunerFLStatusBit;
    UINT8	tunerBandNo;
    UINT8	tunerRegNoPerBand;
    UINT8	tunerUsedTag;
    UINT8	tunerAGCtype;
    UINT8	tunerAGCpolarity;
    UINT8	tunerType;
    UINT32	tunerSpecificTag;
    UINT8	tunerID;
    ATV_TUNER_MODULE *pTuner;
} StructTunerDataType;

typedef struct
{
    UINT32	ifdMagicCode;
    UINT8     ifdAGCPGAMode;
    INT32	ifdAGCFixPGAValue;
    UINT16	AGCVtop[IFD_TUNER_BAND_MAX];
    UINT16	AGC_PGA_MIN[IFD_TUNER_BAND_MAX];
    UINT16	SCANdelay;
    UINT16	SETCHANNELdelay;
    UINT16	CRPhaseInverseThr;
    UINT8	CRinverse_debounce;
    UINT8	CRSt3pgain;
    UINT8	CRSt3igain;
    UINT8	CRSt2pgain;
    UINT8	CRSt2igain;
    UINT8	CRSt0pgain;
    UINT8	CRSt0igain;
    UINT8	CRpgain;
    UINT8	CRigain;
    UINT8	CRlock_err_thd;
    UINT8	CRweight_speed;
    UINT8	CRphasebad_en;
    bool		CRphasebad_en_st4;
    bool		CRphasebad_en_st2;
    bool		CRphasebad_en_st0;
    UINT16	CR_phase_var_st0_thr;
    UINT16	CR_freq_var_st0_thr;
    UINT16	CR_phase_var_st2_thr;
    UINT16	CR_freq_var_vcheck_thr;
    UINT16	CR_freq_var_st2_up_thr;
    UINT16	CR_freq_var_st2_low_thr;
    UINT16	CR_freq_var_st4_thr;
    UINT16	CR_freq_var_st3_thr;
    UINT8	CR_weight_shift_st4_thr;
    UINT8	CR_weight_shift_st2_thr;
    UINT8	CR_weight_shift_st0_thr;
    bool		CR_st2_dn_update_sel;
    UINT32	CRvariance_thr;
    UINT16	CRBpf_Table_MN[IFD_CR_BPF_TABLE_SIZE];
    UINT16 	CRBpf_Table_B[IFD_CR_BPF_TABLE_SIZE];
    UINT16	CRBpf_Table_GH[IFD_CR_BPF_TABLE_SIZE];
    UINT16	CRBpf_Table_I[IFD_CR_BPF_TABLE_SIZE];
    UINT16	CRBpf_Table_DK[IFD_CR_BPF_TABLE_SIZE];
    UINT16	CRBpf_Table_L[IFD_CR_BPF_TABLE_SIZE];
    UINT16	CRBpf_Table_LA[IFD_CR_BPF_TABLE_SIZE];
    UINT16	CRBpf_Table_FMRADIO[IFD_CR_BPF_TABLE_SIZE];
    UINT16	CRBpf_Table_SCAN[IFD_CR_BPF_TABLE_SIZE];
    UINT8	CRInnerLpf_MN;
    UINT8 	CRInnerLpf_BGH;
    UINT8	CRInnerLpf_IDKL;
    UINT8	CRInnerLpf_LA;
    UINT8	CRInnerLpf_SCAN;
    bool		CRShift_en;
    UINT32	CRShift_Target_Freq;
    bool		GRPdelayM_En;
    bool		GRPdelayN_En;
    bool		GRPdelayBG_En;
    bool		GRPdelayDKL_En;
    bool		GRPdelayI_En;
    UINT16	GRPdelayTableM[IFD_GP_BPF_TABLE_SIZE];
    UINT16	GRPdelayTableN[IFD_GP_BPF_TABLE_SIZE];
    UINT16	GRPdelayTableBG[IFD_GP_BPF_TABLE_SIZE];
    UINT16	GRPdelayTableDKL[IFD_GP_BPF_TABLE_SIZE];
    UINT16	GRPdelayTableI[IFD_GP_BPF_TABLE_SIZE];
    bool        InputFltNtsc_En;
    bool        InputFltPalD_En;
    bool		InputFltPalG_En;
    bool		InputFltPalFmRadio_En;
    UINT16   InputFltTableNtsc[IFD_INPUT_FILTER_TABLE_SIZE];
    UINT16   InputFltTablePalD[IFD_INPUT_FILTER_TABLE_SIZE];
    UINT16   InputFltTablePalG[IFD_INPUT_FILTER_TABLE_SIZE];
    UINT16   InputFltTablePalFmRadio[IFD_INPUT_FILTER_TABLE_SIZE];
    UINT16	VideoLpfNTSC[IFD_OUTPUT_LPF_TABLE_SIZE];
    UINT16	VideoLpfPAL_BG[IFD_OUTPUT_LPF_TABLE_SIZE];
    UINT16	VideoLpfPAL_I[IFD_OUTPUT_LPF_TABLE_SIZE];
    UINT16	VideoLpfPAL_DKL[IFD_OUTPUT_LPF_TABLE_SIZE];
    UINT16	VideoLpfSECAM[IFD_OUTPUT_LPF_TABLE_SIZE];
    UINT8     VideoUpsampleLPF_NTSC;
    UINT8     VideoUpsampleLPF_PAL;
    bool		EQ_Table_NTSC_En;
    bool		EQ_Table_PAL_BG_En;
    bool		EQ_Table_PAL_I_En;
    bool		EQ_Table_PAL_DKL_En;
    UINT16	EQ_Table_NTSC[IFD_EQ_TABLE_SIZE];
    UINT16	EQ_Table_PAL_BG[IFD_EQ_TABLE_SIZE];
    UINT16	EQ_Table_PAL_I[IFD_EQ_TABLE_SIZE];
    UINT16	EQ_Table_PAL_DKL[IFD_EQ_TABLE_SIZE];
    UINT16    AGC_rf_max[IFD_TUNER_BAND_MAX];
    UINT16    AGC_rf_min[IFD_TUNER_BAND_MAX];
    UINT16    AGC_krf[IFD_TUNER_BAND_MAX];
    UINT16	AGC_if_max;
    UINT16    AGC_if_min;
    UINT16	AGCloop1_maxtargetNTSC;
    UINT16	AGCloop1_maxtargetPAL;
    UINT16	AGCloop1_maxtargetSECAM;
    UINT16	AGCloop1_difftarget;
    UINT16	AGCloop1_peaktarget;
    bool		AGCloop1_peakforce_en;
    UINT8	AGCloop1_kpgain;
    UINT8	AGCloop1_kigain;
    UINT8	AGCloop1_kpkishift;
    UINT16	AGCloop1_dnsample;
    UINT16	AGCloop1_finednsample;
    UINT8	AGCloop2_kpgain;
    UINT8	AGCloop2_kigain;
    UINT8	AGCloop2_kpshift;
    UINT8	AGCloop2_kishift;
    UINT16	AGCloop2_dnsample;
    UINT16	AGCloop2_finednsample;
    bool 	AGC_RfHasten_en;
    UINT8	AGC_RfHasten_ki;
    UINT16	AGC_RfHasten_cntl;
    UINT16	AGC_RfHasten_thr;
    bool		AGC_SepRfIf_en;
    UINT8	AGC_SepRfIf_IfKp;
    UINT8	AGC_SepRfIf_IfKi;
    UINT16	AGCadapt_fineinterval;
    UINT16	AGCadapt_interval;
    UINT8 	AGCadapt_en;
    UINT16	AGCadapt_incthr;
    UINT16	AGCadapt_mindifftarget;
    UINT16	AGCadapt_minmaxtarget;
    UINT16	AGCadapt_finetargetthr;
    UINT16	AGCadapt_diffcoarsestep;
    UINT16	AGCImpulsive_GateEnd;
    UINT16	AGCImpulsive_DetThr;
    bool		AGCImpulsive_Input;
    bool		AGCImpulsive_MakeEn;
    bool		AGCImpulsive_DetEn;
    UINT8	AGCImpulsive_DetStop;
    UINT16	AGCImpulsive_GateDelay;
    UINT8	AGCHum_Debounce;
    bool		AGCHum_UpdateSel;
    bool		AGCHum_En;
    UINT16	AGCHum_MaxThrOut;
    UINT16	AGCHum_MaxThrIn;
    UINT16	AGCHum_SyncThrOut;
    UINT16	AGCHum_SyncThrIn;
    UINT8	AGCSigmaDeltaDnSel;
    UINT16    AGCDataTarg;
    UINT8	DataGainSel;
    UINT8	CLAMPscale_scanch;
    UINT8	CLAMPscale_setch;
    UINT8	SHAPEfilter_bw;
    UINT8	ADCInput_ShaGain;
    UINT8	ADCInput_FullScale;
    UINT8     ADCInput_clock;
    UINT8     ADCinput_dn_filter_sel;
    UINT8	AFClockthd;
    UINT8     AFC_STAGE_MAX_COUNT;
    UINT8     AFC_Max_Freq;
    StructTunerDataType	tunerPara;
} StructIFDDataType;

extern StructIFDDataType	stIFDUserData;
extern StructIFDDataType	stIFDUserDataArray[_Tuner_MAX_NO];
extern StructIFDDataType	stIFDdefaultUserData;
extern UINT8				gTunerNo;
extern UINT8				gTunerActiveID;
extern StructTunerDataType	gTunerData[_Tuner_MAX_NO];
extern bool                          g_ifd_sw_detect_en;
extern bool				g_ifd_output_CVBS_AMP_compensate_en;
extern bool 				g_ifd_non_std_scan_clamp_adjust_en;
extern IFD_MSG_LEVEL  	g_ifd_msg_level;

// config selection
#define SET_ATV_IFD_SW_DETECT_EN(x) (g_ifd_sw_detect_en=x)
#define SET_ATV_IFD_OUTPUT_CVBS_AMP_COMPENSATE(x) (g_ifd_output_CVBS_AMP_compensate_en=x)
#define SET_ATV_IFD_NON_STD_SCAN_CLAMP_ADJUST(x) (g_ifd_non_std_scan_clamp_adjust_en=x)
//Debug message selection
#define SET_ATV_IFD_DEBUG_MSG_LEVEL(x) (g_ifd_msg_level=x)

#define ATV_IFD_PTUNER stIFDUserData.tunerPara.pTuner

#define GET_ATV_IFD_MAGICCODE()                                        stIFDUserData.ifdMagicCode
#define GET_ATV_IFD_AGCPGAMODE()                                       (IFD_MODE_AGC_PGA_CONFIG)stIFDUserData.ifdAGCPGAMode
#define GET_ATV_IFD_AGCFIXPGAVALUE()                                   (IFD_MODE_AGC_PGA_FIXGAIN_LEVEL)stIFDUserData.ifdAGCFixPGAValue
#define GET_ATV_IFD_AGC_VTOP(x)                                          stIFDUserData.AGCVtop[x]
#define GET_ATV_IFD_AGC_PGA_MIN(x)                                      stIFDUserData.AGC_PGA_MIN[x]
#define GET_ATV_IFD_SCANDELAY()                                           stIFDUserData.SCANdelay
#define GET_ATV_IFD_SETCHANNELDELAY()                                     stIFDUserData.SETCHANNELdelay
#define GET_ATV_IFD_CRPHASEINVERSETHR()                                   stIFDUserData.CRPhaseInverseThr
#define GET_ATV_IFD_CRINVERSE_DEBOUNCE()                                  stIFDUserData.CRinverse_debounce
#define GET_ATV_IFD_CR_ST3_PGAIN()                                          stIFDUserData.CRSt3pgain
#define GET_ATV_IFD_CR_ST3_IGAIN()                                          stIFDUserData.CRSt3igain
#define GET_ATV_IFD_CR_ST2_PGAIN()                                          stIFDUserData.CRSt2pgain
#define GET_ATV_IFD_CR_ST2_IGAIN()                                          stIFDUserData.CRSt2igain
#define GET_ATV_IFD_CR_ST0_PGAIN()                                          stIFDUserData.CRSt0pgain
#define GET_ATV_IFD_CR_ST0_IGAIN()                                          stIFDUserData.CRSt0igain
#define GET_ATV_IFD_CR_PGAIN()                                             stIFDUserData.CRpgain
#define GET_ATV_IFD_CR_IGAIN()                                             stIFDUserData.CRigain
#define GET_ATV_IFD_CR_LOCK_ERR_THD()                                      stIFDUserData.CRlock_err_thd
#define GET_ATV_IFD_CRWEIGHT_SPEED()                                      stIFDUserData.CRweight_speed
#define GET_ATV_IFD_CR_PHASEBAD_EN()                                       stIFDUserData.CRphasebad_en
#define GET_ATV_IFD_CR_PHASEBAD_EN_ST4() (stIFDUserData.CRphasebad_en_st4)
#define GET_ATV_IFD_CR_PHASEBAD_EN_ST2() (stIFDUserData.CRphasebad_en_st2)
#define GET_ATV_IFD_CR_PHASEBAD_EN_ST0() (stIFDUserData.CRphasebad_en_st0)
#define GET_ATV_IFD_CR_PHASE_VAR_ST0_THR()    (stIFDUserData.CR_phase_var_st0_thr   )
#define GET_ATV_IFD_CR_FREQ_VAR_ST0_THR()     (stIFDUserData.CR_freq_var_st0_thr    )
#define GET_ATV_IFD_CR_PHASE_VAR_ST2_THR()    (stIFDUserData.CR_phase_var_st2_thr   )
#define GET_ATV_IFD_CR_FREQ_VAR_VCHECK_THR()  (stIFDUserData.CR_freq_var_vcheck_thr )
#define GET_ATV_IFD_CR_FREQ_VAR_ST2_UP_THR()  (stIFDUserData.CR_freq_var_st2_up_thr )
#define GET_ATV_IFD_CR_FREQ_VAR_ST2_LOW_THR() (stIFDUserData.CR_freq_var_st2_low_thr)
#define GET_ATV_IFD_CR_FREQ_VAR_ST4_THR()     (stIFDUserData.CR_freq_var_st4_thr    )
#define GET_ATV_IFD_CR_FREQ_VAR_ST3_THR()     (stIFDUserData.CR_freq_var_st3_thr    )
#define GET_ATV_IFD_CR_WEIGHT_SHIFT_ST4_THR() (stIFDUserData.CR_weight_shift_st4_thr)
#define GET_ATV_IFD_CR_WEIGHT_SHIFT_ST2_THR() (stIFDUserData.CR_weight_shift_st2_thr)
#define GET_ATV_IFD_CR_WEIGHT_SHIFT_ST0_THR() (stIFDUserData.CR_weight_shift_st0_thr)
#define GET_ATV_IFD_CR_ST2_DN_UPDATE_SEL()    (stIFDUserData.CR_st2_dn_update_sel   )
#define GET_ATV_IFD_CRVARIANCE_THR()                                      stIFDUserData.CRvariance_thr
#define GET_ATV_IFD_CRBPF_TABLE_MN()                                      &stIFDUserData.CRBpf_Table_MN[0]
#define GET_ATV_IFD_CRBPF_TABLE_B()                                       &stIFDUserData.CRBpf_Table_B[0]
#define GET_ATV_IFD_CRBPF_TABLE_GH()                                      &stIFDUserData.CRBpf_Table_GH[0]
#define GET_ATV_IFD_CRBPF_TABLE_I()                                       &stIFDUserData.CRBpf_Table_I[0]
#define GET_ATV_IFD_CRBPF_TABLE_DK()                                      &stIFDUserData.CRBpf_Table_DK[0]
#define GET_ATV_IFD_CRBPF_TABLE_L()                                       &stIFDUserData.CRBpf_Table_L[0]
#define GET_ATV_IFD_CRBPF_TABLE_LA()                                      &stIFDUserData.CRBpf_Table_LA[0]
#define GET_ATV_IFD_CRBPF_TABLE_SCAN()                                    &stIFDUserData.CRBpf_Table_SCAN[0]
#define GET_ATV_IFD_CRINNERLPF_MN()                                       stIFDUserData.CRInnerLpf_MN
#define GET_ATV_IFD_CRINNERLPF_BGH()                                      stIFDUserData.CRInnerLpf_BGH
#define GET_ATV_IFD_CRINNERLPF_IDKL()                                     stIFDUserData.CRInnerLpf_IDKL
#define GET_ATV_IFD_CRINNERLPF_LA()                                       stIFDUserData.CRInnerLpf_LA
#define GET_ATV_IFD_CRINNERLPF_SCAN()                                     stIFDUserData.CRInnerLpf_SCAN
#define GET_ATV_IFD_CRSHIFT_EN()							stIFDUserData.CRShift_en
#define GET_ATV_IFD_CRSHIFT_TARGET_FREQ()				stIFDUserData.CRShift_Target_Freq
#define GET_ATV_IFD_GRPDELAYM_EN()                                        stIFDUserData.GRPdelayM_En
#define GET_ATV_IFD_GRPDELAYN_EN()                                        stIFDUserData.GRPdelayN_En
#define GET_ATV_IFD_GRPDELAYBG_EN()                                       stIFDUserData.GRPdelayBG_En
#define GET_ATV_IFD_GRPDELAYDKL_EN()                                      stIFDUserData.GRPdelayDKL_En
#define GET_ATV_IFD_GRPDELAYTABLEM()                                      &stIFDUserData.GRPdelayTableM[0]
#define GET_ATV_IFD_GRPDELAYTABLEN()                                      &stIFDUserData.GRPdelayTableN[0]
#define GET_ATV_IFD_GRPDELAYTABLEBG()                                     &stIFDUserData.GRPdelayTableBG[0]
#define GET_ATV_IFD_GRPDELAYTABLEDKL()                                    &stIFDUserData.GRPdelayTableDKL[0]
#define GET_ATV_IFD_INPUTFLTNTSC_EN()                                     stIFDUserData.InputFltNtsc_En
#define GET_ATV_IFD_INPUTFLTPALD_EN()                                     stIFDUserData.InputFltPalD_En
#define GET_ATV_IFD_INPUTFLTPALG_EN()                                     stIFDUserData.InputFltPalG_En
#define GET_ATV_IFD_INPUTFLTTABLENTSC()                                   &stIFDUserData.InputFltTableNtsc[0]
#define GET_ATV_IFD_INPUTFLTTABLEPALD()                                   &stIFDUserData.InputFltTablePalD[0]
#define GET_ATV_IFD_INPUTFLTTABLEPALG()                                   &stIFDUserData.InputFltTablePalG[0]
#define GET_ATV_IFD_VIDEOLPFNTSC()                                        &stIFDUserData.VideoLpfNTSC[0]
#define GET_ATV_IFD_VIDEOLPFPAL_BG()                                      &stIFDUserData.VideoLpfPAL_BG[0]
#define GET_ATV_IFD_VIDEOLPFPAL_I()                                       &stIFDUserData.VideoLpfPAL_I[0]
#define GET_ATV_IFD_VIDEOLPFPAL_DKL()                                     &stIFDUserData.VideoLpfPAL_DKL[0]
#define GET_ATV_IFD_VIDEOLPFSECAM()                                       &stIFDUserData.VideoLpfSECAM[0]
#define GET_ATV_IFD_EQ_TABLE_NTSC_EN()                                    stIFDUserData.EQ_Table_NTSC_En
#define GET_ATV_IFD_EQ_TABLE_PAL_BG_EN()                                  stIFDUserData.EQ_Table_PAL_BG_En
#define GET_ATV_IFD_EQ_TABLE_PAL_I_EN()                                   stIFDUserData.EQ_Table_PAL_I_En
#define GET_ATV_IFD_EQ_TABLE_PAL_DKL_EN()                                 stIFDUserData.EQ_Table_PAL_DKL_En
#define GET_ATV_IFD_EQ_TABLE_NTSC()                                       &stIFDUserData.EQ_Table_NTSC[0]
#define GET_ATV_IFD_EQ_TABLE_PAL_BG()                                     &stIFDUserData.EQ_Table_PAL_BG[0]
#define GET_ATV_IFD_EQ_TABLE_PAL_I()                                      &stIFDUserData.EQ_Table_PAL_I[0]
#define GET_ATV_IFD_EQ_TABLE_PAL_DKL()                                    &stIFDUserData.EQ_Table_PAL_DKL[0]
#define GET_ATV_IFD_AGC_RF_MAX(x)                                       stIFDUserData.AGC_rf_max[x]
#define GET_ATV_IFD_AGC_RF_MIN(x)                                       stIFDUserData.AGC_rf_min[x]
#define GET_ATV_IFD_AGC_KRF(x)                                          stIFDUserData.AGC_krf[x]
#define GET_ATV_IFD_AGC_IF_MAX()                                          stIFDUserData.AGC_if_max
#define GET_ATV_IFD_AGC_IF_MIN()                                          stIFDUserData.AGC_if_min
#define GET_ATV_IFD_AGCLOOP1_MAXTARGET_NTSC()                              stIFDUserData.AGCloop1_maxtargetNTSC
#define GET_ATV_IFD_AGCLOOP1_MAXTARGET_PAL()                               stIFDUserData.AGCloop1_maxtargetPAL
#define GET_ATV_IFD_AGCLOOP1_MAXTARGET_SECAM()                             stIFDUserData.AGCloop1_maxtargetSECAM
#define GET_ATV_IFD_AGCLOOP1_DIFFTARGET()                                 stIFDUserData.AGCloop1_difftarget
#define GET_ATV_IFD_AGCLOOP1_PEAKTARGET()                                 stIFDUserData.AGCloop1_peaktarget
#define GET_ATV_IFD_AGCLOOP1_PEAKFORCE_EN()                                 stIFDUserData.AGCloop1_peakforce_en
#define GET_ATV_IFD_AGCLOOP1_KPGAIN()                                     stIFDUserData.AGCloop1_kpgain
#define GET_ATV_IFD_AGCLOOP1_KIGAIN()                                     stIFDUserData.AGCloop1_kigain
#define GET_ATV_IFD_AGCLOOP1_KPKISHIFT()                                  stIFDUserData.AGCloop1_kpkishift
#define GET_ATV_IFD_AGCLOOP1_DNSAMPLE()                                   stIFDUserData.AGCloop1_dnsample
#define GET_ATV_IFD_AGCLOOP1_FINEDNSAMPLE()                               stIFDUserData.AGCloop1_finednsample
#define GET_ATV_IFD_AGCLOOP2_KPGAIN()                                    stIFDUserData.AGCloop2_kpgain
#define GET_ATV_IFD_AGCLOOP2_KIGAIN()                                     stIFDUserData.AGCloop2_kigain
#define GET_ATV_IFD_AGCLOOP2_KPSHIFT()                                    stIFDUserData.AGCloop2_kpshift
#define GET_ATV_IFD_AGCLOOP2_KISHIFT()                                    stIFDUserData.AGCloop2_kishift
#define GET_ATV_IFD_AGCLOOP2_DNSAMPLE()                                   stIFDUserData.AGCloop2_dnsample
#define GET_ATV_IFD_AGCLOOP2_FINEDNSAMPLE()                               stIFDUserData.AGCloop2_finednsample
#define GET_ATV_IFD_AGC_RFHASTEN_EN()                                     stIFDUserData.AGC_RfHasten_en
#define GET_ATV_IFD_AGC_RFHASTEN_KI()                                     stIFDUserData.AGC_RfHasten_ki
#define GET_ATV_IFD_AGC_RFHASTEN_CNTL()                                   stIFDUserData.AGC_RfHasten_cntl
#define GET_ATV_IFD_AGC_RFHASTEN_THR()                                    stIFDUserData.AGC_RfHasten_thr
#define GET_ATV_IFD_AGC_SEPRFIF_EN()                                      stIFDUserData.AGC_SepRfIf_en
#define GET_ATV_IFD_AGC_SEPRFIF_IFKP()                                    stIFDUserData.AGC_SepRfIf_IfKp
#define GET_ATV_IFD_AGC_SEPRFIF_IFKI()                                    stIFDUserData.AGC_SepRfIf_IfKi
#define GET_ATV_IFD_AGCADAPT_FINEINTERVAL()                               stIFDUserData.AGCadapt_fineinterval
#define GET_ATV_IFD_AGCADAPT_INTERVAL()                                   stIFDUserData.AGCadapt_interval
#define GET_ATV_IFD_AGCADAPT_EN()                                         stIFDUserData.AGCadapt_en
#define GET_ATV_IFD_AGCADAPT_INCTHR()                                     stIFDUserData.AGCadapt_incthr
#define GET_ATV_IFD_AGCADAPT_MINDIFFTARGET()                              stIFDUserData.AGCadapt_mindifftarget
#define GET_ATV_IFD_AGCADAPT_MINMAXTARGET()                               stIFDUserData.AGCadapt_minmaxtarget
#define GET_ATV_IFD_AGCADAPT_FINETARGETTHR()                              stIFDUserData.AGCadapt_finetargetthr
#define GET_ATV_IFD_AGCADAPT_DIFFCOARSESTEP()                             stIFDUserData.AGCadapt_diffcoarsestep
#define GET_ATV_IFD_AGCIMPULSIVE_GATEEND()                                stIFDUserData.AGCImpulsive_GateEnd
#define GET_ATV_IFD_AGCIMPULSIVE_DETTHR()                                 stIFDUserData.AGCImpulsive_DetThr
#define GET_ATV_IFD_AGCIMPULSIVE_INPUT()                                  stIFDUserData.AGCImpulsive_Input
#define GET_ATV_IFD_AGCIMPULSIVE_MAKEEN()                                 stIFDUserData.AGCImpulsive_MakeEn
#define GET_ATV_IFD_AGCIMPULSIVE_DETEN()                                  stIFDUserData.AGCImpulsive_DetEn
#define GET_ATV_IFD_AGCIMPULSIVE_DETSTOP()                                stIFDUserData.AGCImpulsive_DetStop
#define GET_ATV_IFD_AGCIMPULSIVE_GATEDELAY()                              stIFDUserData.AGCImpulsive_GateDelay
#define GET_ATV_IFD_AGCHUM_DEBOUNCE()                                     stIFDUserData.AGCHum_Debounce
#define GET_ATV_IFD_AGCHUM_UPDATESEL()                                    stIFDUserData.AGCHum_UpdateSel
#define GET_ATV_IFD_AGCHUM_EN()                                           stIFDUserData.AGCHum_En
#define GET_ATV_IFD_AGCHUM_MAXTHROUT()                                    stIFDUserData.AGCHum_MaxThrOut
#define GET_ATV_IFD_AGCHUM_MAXTHRIN()                                     stIFDUserData.AGCHum_MaxThrIn
#define GET_ATV_IFD_AGCHUM_SYNCTHROUT()                                   stIFDUserData.AGCHum_SyncThrOut
#define GET_ATV_IFD_AGCHUM_SYNCTHRIN()                                    stIFDUserData.AGCHum_SyncThrIn
#define GET_ATV_IFD_AGC_SIGMADELTA_DNSEL()                                  stIFDUserData.AGCSigmaDeltaDnSel
#define GET_ATV_IFD_AGC_DATA_TARG()                                         stIFDUserData.AGCDataTarg
#define GET_ATV_IFD_DATA_GAIN_SEL()                                         stIFDUserData.DataGainSel
#define GET_ATV_IFD_CLAMPSCALE_SCANCH()                                   (IFD_CLAMP_SCALE)stIFDUserData.CLAMPscale_scanch
#define GET_ATV_IFD_CLAMPSCALE_SETCH()                                    (IFD_CLAMP_SCALE)stIFDUserData.CLAMPscale_setch
#define GET_ATV_IFD_SHAPEFILTER_BW()                                      (IFD_SHAPING_BW_SEL)stIFDUserData.SHAPEfilter_bw
#define GET_ATV_IFD_VIDEO_UPSAMPLE_LPF_NTSC() 							  stIFDUserData.VideoUpsampleLPF_NTSC
#define GET_ATV_IFD_VIDEO_UPSAMPLE_LPF_PAL()                              stIFDUserData.VideoUpsampleLPF_PAL
#define GET_ATV_IFD_ADCINPUT_SHAGAIN()                                    stIFDUserData.ADCInput_ShaGain
#define GET_ATV_IFD_ADCINPUT_FULLSCALE()                                  stIFDUserData.ADCInput_FullScale
#define GET_ATV_IFD_ADCINPUT_CLOCK()                                      (IFD_CLK_RATE)stIFDUserData.ADCInput_clock
#define GET_ATV_IFD_ADCINPUT_DN_FILTER_SEL()                              (IFD_INPUT_DN_FILTER)stIFDUserData.ADCinput_dn_filter_sel
#define GET_ATV_IFD_AFCLOCKTHD()                                          stIFDUserData.AFClockthd
#define GET_ATV_IFD_AFC_STAGE_MAX_COUNT()                                 stIFDUserData.AFC_STAGE_MAX_COUNT
#define GET_ATV_IFD_AFC_MAX_FREQ()                                        stIFDUserData.AFC_Max_Freq

// config selection
#define GET_ATV_IFD_SW_DETECT_EN() (g_ifd_sw_detect_en)
#define GET_ATV_IFD_OUTPUT_CVBS_AMP_COMPENSATE() (g_ifd_output_CVBS_AMP_compensate_en)
#define GET_ATV_IFD_NON_STD_SCAN_CLAMP_ADJUST() (g_ifd_non_std_scan_clamp_adjust_en)
// tuner parameter
#define GET_ATV_TUNER_AGC_POLARITY() ((TUNER_AGCPOLARITY_SEL)stIFDUserData.tunerPara.tunerAGCpolarity)
#define GET_ATV_TUNER_BAND_FREQUENCY(band) (stIFDUserData.tunerPara.tunerBandFreq[band])
#define GET_ATV_TUNER_RATIO_STEP_SIZE() (stIFDUserData.tunerPara.tunerRATIOStepSize)
#define GET_ATV_TUNER_PIF() (stIFDUserData.tunerPara.tunerPIF)
#define GET_ATV_TUNER_TYPE() (stIFDUserData.tunerPara.tunerType)
#define GET_ATV_TUNER_ID() (stIFDUserData.tunerPara.tunerID)
//Debug message selection
#define GET_ATV_IFD_DEBUG_MSG_LEVEL() (g_ifd_msg_level)
#if defined(CONFIG_TUNER_MAXLINEAR_MXL601) || defined(CONFIG_TUNER_MAXLINEAR_MXL661)
typedef enum _TUNER_MAXLINEAR_MXL601_INFO
{
    TUNER_INPUT_LEVLE= 0  ,
    TUNER_AtvTunerLockStatus,
    TUNER_AtvOffset,
} TUNER_MAXLINEAR_MXL601_INFO;

typedef enum _TUNER_MAXLINEAR_MXL601_MXL_AGC_TYPE_E
{
    TUNER_IF_AGC_SELF = 0,
    TUNER_IF_AGC_EXTERNAL = 1
} TUNER_MAXLINEAR_MXL601_MXL_AGC_TYPE_E;


typedef enum _TUNER_MAXLINEAR_MXL601_MXL_BW_E
{
    TUNER_ANA_TV_DIG_CABLE_BW_6MHz = 0x00,    /* Analog TV and Digital Cable Mode 6MHz */
    TUNER_ANA_TV_DIG_CABLE_BW_7MHz = 0x01,    /* Analog TV and Digital Cable Mode 7MHz */
    TUNER_ANA_TV_DIG_CABLE_BW_8MHz = 0x02,    /* Analog TV and Digital Cable Mode 8MHz */
} TUNER_MAXLINEAR_MXL601_MXL_BW_E;

int drvif_ifd_factorymode_get_TUNER_MAXLINEAR_MXL601_Information(TUNER_MAXLINEAR_MXL601_INFO mode);
void drvif_ifd_factorymode_set_TUNER_MAXLINEAR_MXL601_IF_Output_Amp(UINT8 value);
UINT8 drvif_ifd_factorymode_get_TUNER_MAXLINEAR_MXL601_IF_Output_Amp_info(void);
void drvif_ifd_factorymode_set_TUNER_MAXLINEAR_MXL601_IF_AGC_TYPE(TUNER_MAXLINEAR_MXL601_MXL_AGC_TYPE_E value);
UINT8 drvif_ifd_factorymode_get_TUNER_MAXLINEAR_MXL601_IF_AGC_TYPE_info(void);
void drvif_ifd_factorymode_set_TUNER_MAXLINEAR_MXL601_BandWidth(TUNER_MAXLINEAR_MXL601_MXL_BW_E value);
UINT8 drvif_ifd_factorymode_get_TUNER_MAXLINEAR_MXL601_BandWidth_info(void);
void drvif_ifd_factorymode_set_TUNER_MAXLINEAR_XTAL_LOAD_CAP(UINT8 value);
UINT8 drvif_ifd_factorymode_get_TUNER_MAXLINEAR_MXL601_XTAL_LOAD_CAP_info(void);
void drvif_ifd_factorymode_set_TUNER_MAXLINEAR_IF_AGC_SET_POINT(UINT8 value);
UINT8 drvif_ifd_factorymode_get_TUNER_MAXLINEAR_MXL601_IF_AGC_SET_POINT_info(void);


#endif


typedef enum stop_auto_scan_point
{
    DISABLE_STOP_AUTO_SCAN_POINT=0,
    Stop_SCAN_Channel_For_PAL,
    Stop_Coarse_lock_For_PAL,
    Stop_Fine_Lock_For_PAL,
    Stop_Auto_Mode_For_PAL,
    Stop_Mode_Error,
    Stop_Audio_Mode,
    Stop_SCAN_Channel_For_NTSC,
    Stop_Coarse_lock_For_NTSC,
    Stop_Fine_Lock_For_NTSC,
    Stop_Auto_Mode_For_NTSC,
} stop_auto_scan_point;

//////////////////////////////////////////////////////////////////////////////////////
//Page 1
//////////////////////////////////////////////////////////////////////////////////////
//Name: cr lock status
//Range: 0/1
//RW type: R
//Unit: None
bool drvif_ifd_factorymode_cr_lock_get_status(void);
//Name: cr offset
//Range: -1000~1000
//RW type: R
//Unit: kHz
INT32 drvif_ifd_factorymode_cr_lock_get_offset(void);
//Name: cr lock freq thr
//Range: 0~1000
//RW type: R/W
//Unit: kHz
void drvif_ifd_factorymode_cr_lock_set_freq_thr(UINT16 freq_thr);
UINT16 drvif_ifd_factorymode_cr_lock_get_freq_thr(void);
//Name: cr lock amp thr
//Range: 0~31
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_lock_set_amp_thr(UINT16 amp_thr);
UINT8 drvif_ifd_factorymode_cr_lock_get_amp_thr(void);
//Name: cr bpf en
//Range: 0:enable 1:disable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_lock_set_bpf_en(bool cr_bpf_en);
UINT8 drvif_ifd_factorymode_cr_lock_get_bpf_en(void);
//Name: cr inner lpf en
//Range: 0:enable 1:disable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_lock_set_innerlpf_en(bool cr_inner_lpf_en);
UINT8 drvif_ifd_factorymode_cr_lock_get_innerlpf_en(void);
//Name: cr inner lpf sel
//Range: 0~4
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_lock_set_innerlpf_sel(UINT8 cr_inner_lpf_sel);
UINT8 drvif_ifd_factorymode_cr_lock_get_innerlpf_sel(void);
//////////////////////////////////////////////////////////////////////////////////////
//Page 2
//////////////////////////////////////////////////////////////////////////////////////
//Name: cr kp
//Range: 0x0~0xF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_kp(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_kp(void);
//Name: cr ki
//Range: 0x0~0xF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_ki(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_ki(void);
//Name: cr st3 kp
//Range: 0x0~0xF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_st3_kp(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_st3_kp(void);
//Name: cr st3 ki
//Range: 0x0~0xF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_st3_ki(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_st3_ki(void);
//Name: cr st2 kp
//Range: 0x0~0xF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_st2_kp(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_st2_kp(void);
//Name: cr st2 ki
//Range: 0x0~0xF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_st2_ki(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_st2_ki(void);
//Name: cr st0 kp
//Range: 0x0~0xF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_st0_kp(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_st0_kp(void);
//Name: cr st0 ki
//Range: 0x0~0xF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_st0_ki(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_st0_ki(void);
//Name: cr st3 dn debounce
//Range: 0x0~0x7
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_st3_dn_debounce(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_st3_dn_debounce(void);
//Name: cr st2 dn debounce
//Range: 0x0~0x7
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_st2_dn_debounce(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_st2_dn_debounce(void);
//Name: cr st2 up debounce
//Range: 0x0~0x7
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_st2_up_debounce(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_st2_up_debounce(void);
//Name: cr st1 dn debounce
//Range: 0x0~0x7
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_st1_dn_debounce(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_st1_dn_debounce(void);
//Name: cr st1 up debounce
//Range: 0x0~0x7
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_st1_up_debounce(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_st1_up_debounce(void);
//Name: cr st0 up debounce
//Range: 0x0~0x7
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_st0_up_debounce(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_st0_up_debounce(void);
//Name: cr phase var st0 thr
//Range: 0x0~0xFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_phasevar_st0_thr(UINT16 setting);
UINT16 drvif_ifd_factorymode_cr_loop_get_cr_phasevar_st0_thr(void);
//Name: cr freq var st0 thr
//Range: 0x0~0xFFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_freqvar_st0_thr(UINT16 setting);
UINT16 drvif_ifd_factorymode_cr_loop_get_cr_freqvar_st0_thr(void);
//Name: cr freq vcheck thr
//Range: 0x0~0xFFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_vcheck_thr(UINT16 setting);
UINT16 drvif_ifd_factorymode_cr_loop_get_cr_vcheck_thr(void);
//Name: cr freq var st2 up thr
//Range: 0x0~0xFFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_freqvar_st2_up_thr(UINT16 setting);
UINT16 drvif_ifd_factorymode_cr_loop_get_cr_freqvar_st2_up_thr(void);
//Name: cr freq var st2 low thr
//Range: 0x0~0xFFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_freqvar_st2_low_thr(UINT16 setting);
UINT16 drvif_ifd_factorymode_cr_loop_get_cr_freqvar_st2_low_thr(void);
//Name: cr phase var st2 thr
//Range: 0x0~0xFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_phasevar_st2_thr(UINT16 setting);
UINT16 drvif_ifd_factorymode_cr_loop_get_cr_phasevar_st2_thr(void);
//Name: cr freq var st3 thr
//Range: 0x0~0xFFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_freqvar_st3_thr(UINT16 setting);
UINT16 drvif_ifd_factorymode_cr_loop_get_cr_freqvar_st3_thr(void);
//Name: cr st2 dn update sel
//Range: 0: freq_error / 1: pahse_error
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_st2_dn_update_sel(bool setting);
bool drvif_ifd_factorymode_cr_loop_get_cr_st2_dn_update_sel(void);
//Name: cr fix state
//Range: 0~3
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_fix_state(UINT8 setting);
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_fix_state(void);
//Name:cr fix state en
//Range: 0: enable / 1: disable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_fix_state_en(bool setting);
bool drvif_ifd_factorymode_cr_loop_get_cr_fix_state_en(void);
//Name:cr state en
//Range: 0: enable / 1: disable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_loop_set_cr_state_en(bool setting);
bool drvif_ifd_factorymode_cr_loop_get_cr_state_en(void);
//Name:cr state
//Range: 0~3
//RW type: R
//Unit: None
UINT8 drvif_ifd_factorymode_cr_loop_get_cr_state(void);
//////////////////////////////////////////////////////////////////////////////////////
//Page 3
//////////////////////////////////////////////////////////////////////////////////////
//Name:cr weighting en
//Range: 0: enable / 1: disable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_other_set_weighting_en(bool enable);
bool drvif_ifd_factorymode_cr_other_get_weighting_en(void);
//Name:cr weighting speed
//Range: 0x0~0x7
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_other_set_weighting_speed(UINT8 cr_weight_speed);
UINT8 drvif_ifd_factorymode_cr_other_get_weighting_speed(void);
//Name:cr auto reset en
//Range: 0: enable / 1: disable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_other_set_autoreset_en(bool enable);
bool drvif_ifd_factorymode_cr_other_get_autoreset_en(void);
//Name:cr phase inverse en
//Range: 0: enable / 1: disable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_other_set_phase_inverse_en(bool enable);
bool drvif_ifd_factorymode_cr_other_get_phase_inverse_en(void);
//Name:cr phase inverse thr
//Range: 0x0000~0x7fff
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_cr_other_set_phase_inverse_thr(UINT16 thr);
UINT16 drvif_ifd_factorymode_cr_other_get_phase_inverse_thr(void);
//////////////////////////////////////////////////////////////////////////////////////
//Page 4
//////////////////////////////////////////////////////////////////////////////////////
//Name:cr phase error mean
//Range: 0x0~0xFFF
//RW type: R
//Unit: None
UINT16 drvif_ifd_factorymode_cr_status_get_phase_error_mean(void);
//Name:cr phase error var
//Range: 0x0~0xFFF
//RW type: R
//Unit: None
UINT16 drvif_ifd_factorymode_cr_status_get_phase_error_var(void);
//Name:cr freq error mean
//Range: 0x0~0xFFF
//RW type: R
//Unit: None
UINT16 drvif_ifd_factorymode_cr_status_get_freq_error_mean(void);
//Name:cr fre	q error var
//Range: 0x0~0xFFF
//RW type: R
//Unit: None
UINT16 drvif_ifd_factorymode_cr_status_get_freq_error_var(void);
//Name:cr sin_sample_d
//Range: 0x0000~0xffff
//RW type: R
//Unit: None
UINT16 drvif_ifd_factorymode_cr_status_get_sine_sample_d(void);
//////////////////////////////////////////////////////////////////////////////////////
//Page 5
//////////////////////////////////////////////////////////////////////////////////////
//Name:down sample enable
//Range: 0: disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_down_sample_lpf_en(bool enable);
bool drvif_ifd_factorymode_video_get_down_sample_lpf_en(void);
//Name:new_down_sample_lpf_sel
//Range: 0~15
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_down_sample_lpf(UINT8 lpf_sel);
UINT8 drvif_ifd_factorymode_video_get_down_sample_lpf(void);

//Name:new_video_lpf_en
//Range: 0: disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_new_video_lpf_en(bool enable);
bool drvif_ifd_factorymode_video_get_new_video_lpf_en(void);
//Name:new_video_lpf_sel
//Range: 0~15
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_new_video_lpf_sel(UINT8 lpf_sel);
UINT8 drvif_ifd_factorymode_video_get_new_video_lpf_sel(void);
//Name:clamp_offset_manual_en
//Range: 0: disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_clamp_offset_manual_en(bool enable);
bool drvif_ifd_factorymode_video_get_clamp_offset_manual_en(void);
//Name:clamp_offset_manual_value
//Range: 0~0x7f
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_clamp_offset_manual_value(UINT8 offset);
UINT8 drvif_ifd_factorymode_video_get_clamp_offset_manual_value(void);
//Name:clamp_offset_scale
//Range: 0~10
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_clamp_offset_scale(UINT8 clamp_scale);
UINT8 drvif_ifd_factorymode_video_get_clamp_offset_scale(void);
//Name:clamp hold
//Range: 0: normal 1: hold
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_clamp_hold(bool hold);
bool drvif_ifd_factorymode_video_get_clamp_hold(void);
//Name:clamp reset
//Range: 0: normal 1: reset
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_clamp_reset(bool reset);
bool drvif_ifd_factorymode_video_get_clamp_reset(void);
//Name:group delay enable
//Range: 0: disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_group_delaye_en(bool enable);
bool drvif_ifd_factorymode_video_get_group_delaye_en(void);
//Name:groupdelay_sel
//Range: 0~15
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_groupdelay_sel(UINT8 sel);
UINT8 drvif_ifd_factorymode_video_get_groupdelay_sel(void);
//Name:modulation type
//Range: 0: postive 1: negtive
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_mod_type(bool mod);
bool drvif_ifd_factorymode_video_get_mod_type(void);
//Name:modulation type detect reset
//Range: 0: normal  1: reset
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_mod_type_detect_reset(bool reset);
bool drvif_ifd_factorymode_video_get_mod_type_detect_reset(void);
//Name:modulation type detect status
//Range: 0~3
//RW type: R
//Unit: None
UINT8 drvif_ifd_factorymode_video_get_mod_type_detect_status(void);
//Name:modulation type auto en
//Range: 0: disable  1: enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_mod_type_auto_en(bool enable);
bool drvif_ifd_factorymode_video_get_mod_type_auto_en(void);
//Name:eq en
//Range: 0: disable  1: enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_eq_en(bool enable);
bool drvif_ifd_factorymode_video_get_eq_en(void);
//Name:eq table sel
//Range: 0~3
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_eq_table_sel(UINT8 sel);
UINT8 drvif_ifd_factorymode_video_get_eq_table_sel(void);
//Name: shaping filer sel
//Range: 0~12
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_shaping_filter_sel(UINT8 sel);
UINT8 drvif_ifd_factorymode_video_get_shaping_filter_sel(void);
//Name: data gain sel
//Range: 0:1x 1:2x 2:4x
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_data_gain_sel(UINT8 sel);
UINT8 drvif_ifd_factorymode_video_get_data_gain_sel(void);
//Name: softreset
//Range: 0:normal 1:reset
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_video_set_srst(bool enable);
bool drvif_ifd_factorymode_video_get_srst(void);
//////////////////////////////////////////////////////////////////////////////////////
//Page 6
//////////////////////////////////////////////////////////////////////////////////////
//Name: audio bpf sel
//Range: 0~12
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_audio_set_bpf_sel(UINT8 filter);
UINT8 drvif_ifd_factorymode_audio_get_bpf_sel(void);
//Name: audio manual gain en
//Range: 0: disable  1: enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_audio_set_manual_gain_en(bool enable);
bool drvif_ifd_factorymode_audio_get_manual_gain_en(void);
//Name: audio manual gain
//Range: 0x00~0x3f
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_audio_set_manual_gain(UINT8 gain);
UINT8 drvif_ifd_factorymode_audio_get_manual_gain(void);
//////////////////////////////////////////////////////////////////////////////////////
//Page 7
//////////////////////////////////////////////////////////////////////////////////////
//Name: agc_lock
//Range: 0: unlocked  1: locked
//RW type: R
//Unit: None
bool drvif_ifd_factorymode_agc_get_lock_status(void);
//Name: agc peak force en
//Range: 0: disable  1: enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_peak_force(bool enable);
bool drvif_ifd_factorymode_agc_get_peak_force(void);
//Name: agc lock thr
//Range: 0x0~0xff
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_lock_thr(UINT8 thr);
UINT8 drvif_ifd_factorymode_agc_get_lock_thr(void);
//Name: agc peak en
//Range: 0: disable  1: enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_peak_en(bool agc_peak_en );
bool drvif_ifd_factorymode_agc_get_peak_en(void);
//Name: agc peak status
//Range: 0~1
//RW type: R
//Unit: None
bool drvif_ifd_factorymode_agc_get_peak_status(void);
//Name: agc fine lock status
//Range: 0: unlocked  1: locked
//RW type: R
//Unit: None
bool drvif_ifd_factorymode_agc_get_fine_lock_status(void);
//Name: agc bpf en
//Range: 0: disable  1: enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_bpf_en(bool enable);
bool drvif_ifd_factorymode_agc_get_bpf_en(void);
//Name: agc mode status
//Range: 0: 2loop  1: 2step
//RW type: R
//Unit: None
UINT8  drvif_ifd_factorymode_agc_get_mode(void);
//Name: agc vtop
//Range: 0x0~0xFFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_vtop(UINT16 agc_vtop );
UINT16 drvif_ifd_factorymode_agc_get_vtop(void);
//Name: agc rf max
//Range: 0x0~0xFFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_rfmax(UINT16 rf_max);
UINT16 drvif_ifd_factorymode_agc_get_rfmax(void);
//Name: agc rf min
//Range: 0x0~0xFFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_rfmin(UINT16 rf_max);
UINT16 drvif_ifd_factorymode_agc_get_rfmin(void);
//Name: agc rf manual en
//Range: 0: disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_rf_manual_en(bool enable);
bool drvif_ifd_factorymode_agc_get_rf_manual_en(void);
//Name: agc rf manual value
//Range: 0~255
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_rf_manual_value(UINT8 rf_gain);
UINT8 drvif_ifd_factorymode_agc_get_rf_manual_value(void);
//Name: agc if manual en
//Range: 0: disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_if_manual_en(bool enable);
bool drvif_ifd_factorymode_agc_get_if_manual_en(void);
//Name: agc if manual value
//Range: 0~255
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_if_manual_value(UINT8 if_gain);
UINT8 drvif_ifd_factorymode_agc_get_if_manual_value(void);
//Name: agc dgain hold en
//Range: 0: disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_dgain_hold_en(bool enable);
bool drvif_ifd_factorymode_agc_get_dgain_hold_en(void);
//Name: agc max target value
//Range: 0~128
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_maxtarget_value(UINT32 gain);
UINT32 drvif_ifd_factorymode_agc_get_maxtarget_value(void);
//Name: agc diff target value
//Range: 0~255
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_difftarget_value(UINT32 gain);
UINT8 drvif_ifd_factorymode_agc_get_difftarget_value(void);
//Name: agc peak target value
//Range: 0~255
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_peaktarget_value(UINT32 gain);
UINT8 drvif_ifd_factorymode_agc_get_peaktarget_value(void);
//Name : agc_targ_val
//Range : 0~0xFFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_set_agc_data_targ(UINT16 targ);
UINT16 drvif_ifd_factorymode_get_agc_data_targ(void);
//////////////////////////////////////////////////////////////////////////////////////
//Page 8
//////////////////////////////////////////////////////////////////////////////////////
//Name: agc loop1 kp
//Range: 0~31
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_loop1_kp(UINT8 agc_kp);
UINT8 drvif_ifd_factorymode_agc_get_loop1_kp(void);
//Name: agc loop1 ki
//Range: 0~15
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_loop1_ki(UINT8 agc_ki);
UINT8 drvif_ifd_factorymode_agc_get_loop1_ki(void);
//Name: agc loop1 pi shift
//Range: 0~31
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_loop1_pishift(UINT8 agc_kpishit);
UINT8 drvif_ifd_factorymode_agc_get_loop1_pishift(void);
//Name: agc loop1 dn sample
//Range: 0~255
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_loop1_dn_sample(UINT8 dn_sample);
UINT8 drvif_ifd_factorymode_agc_get_loop1_dn_sample(void);
//Name: agc loop1 finetune dn sample
//Range: 0~255
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_loop1_finetune_dn_sample(UINT8 dn_sample);
UINT8 drvif_ifd_factorymode_agc_get_loop1_finetune_dn_sample(void);
//Name: agc loop2 kp
//Range: 0~31
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_loop2_kp(UINT8 agc_kp);
UINT8 drvif_ifd_factorymode_agc_get_loop2_kp(void);
//Name: agc loop2 ki
//Range: 0~31
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_loop2_ki(UINT8 agc_ki);
UINT8 drvif_ifd_factorymode_agc_get_loop2_ki(void);
//Name: agc loop2 kpshift
//Range: 0~15
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_loop2_kpshift(UINT8 agc_in_kp_shift);
UINT8 drvif_ifd_factorymode_agc_get_loop2_kpshift(void);
//Name: agc loop2 kishift
//Range: 0~15
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_loop2_kishift(UINT8 agc_in_ki_shift);
UINT8 drvif_ifd_factorymode_agc_get_loop2_kishift(void);
//Name: agc loop2 dn sample
//Range: 0~255
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_loop2_dn_sample(UINT8 dn_sample);
UINT8 drvif_ifd_factorymode_agc_get_loop2_dn_sample(void);
//Name: agc loop2 finetune dn sample
//Range: 0~255
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_loop2_finetune_dn_sample(UINT8 dn_sample);
UINT8 drvif_ifd_factorymode_agc_get_loop2_finetune_dn_sample(void);
//Name: agc slow charge
//Range: 0: disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_slow_charge_en(bool enable);
bool drvif_ifd_factorymode_agc_get_slow_charge_en(void);
//Name: agc rf hasten en
//Range: 0: disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_rfhasten_en(bool enable);
bool drvif_ifd_factorymode_agc_get_rfhasten_en(void);
//Name: agc rf hasten ki
//Range: 0x0~0xf
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_rfhasten_ki(UINT8 ki);
UINT8 drvif_ifd_factorymode_agc_get_rfhasten_ki(void);
//Name: agc rf hasten cntl
//Range: 0x0~0xfff
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_rfhasten_cntl(UINT16 cntl);
UINT16 drvif_ifd_factorymode_agc_get_rfhasten_cntl(void);
//Name: agc rf hasten thr
//Range: 0x0~0xfff
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_rfhasten_thr(UINT16 thr);
UINT16 drvif_ifd_factorymode_agc_get_rfhasten_thr(void);
//Name: agc sep rf if en
//Range: 0: disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_sep_rf_if_en(bool enable);
bool drvif_ifd_factorymode_agc_get_sep_rf_if_en(void);
//Name: agc sep rf if ki
//Range: 0x0~0xf
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_sep_rf_if_ki(UINT8 ki);
UINT8 drvif_ifd_factorymode_agc_get_sep_rf_if_ki(void);
//Name: agc sep rf if kp
//Range: 0x0~0xf
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_sep_rf_if_kp(UINT8 kp);
UINT8 drvif_ifd_factorymode_agc_get_sep_rf_if_kp(void);
//Name: agcadapt_en
//Range: 0: disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_adaptive_en(bool enable);
bool drvif_ifd_factorymode_agc_get_adaptive_en(void);
//Name: adaptive_fineinterval
//Range: 0x000~0xFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_adaptive_fineinterval(UINT16 value);
UINT16 drvif_ifd_factorymode_agc_get_adaptive_fineinterval(void);
//Name: adaptive_interval
//Range: 0x000~0xFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_adaptive_interval(UINT16 value);
UINT16 drvif_ifd_factorymode_agc_get_adaptive_interval(void);
//Name: adaptive_incthr
//Range: 0x000~0xFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_adaptive_incthr(UINT16 value);
UINT16 drvif_ifd_factorymode_agc_get_adaptive_incthr(void);
//Name: adaptive_mindifftarget
//Range: 0x000~0xFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_adaptive_mindifftarget(UINT16 value);
UINT16 drvif_ifd_factorymode_agc_get_adaptive_mindifftarget(void);
//Name: adaptive_minmaxtarget
//Range: 0x000~0xFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_adaptive_minmaxtarget(UINT16 value);
UINT16 drvif_ifd_factorymode_agc_get_adaptive_minmaxtarget(void);
//Name: adaptive_finetarget_thr
//Range: 0x000~0xFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_adaptive_finetarget_thr(UINT16 value);
UINT16 drvif_ifd_factorymode_agc_get_adaptive_finetarget_thr(void);
//Name: adaptive_diffcoarse_step
//Range: 0x000~0xFFF
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_adaptive_diffcoarse_step(UINT16 value);
UINT16 drvif_ifd_factorymode_agc_get_adaptive_diffcoarse_step(void);
//Name: impulsive det en
//Range: 0:disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_impulsive_det_en(bool setting);
bool drvif_ifd_factorymode_agc_get_impulsive_det_en(void);
//Name: impulsive mask en
//Range: 0:disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_impulsive_mask_en(bool setting);
bool drvif_ifd_factorymode_agc_get_impulsive_mask_en(void);
//Name: impulsive input
//Range: 0:dgain out 1:lpf out
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_impulsive_input(bool setting);
bool drvif_ifd_factorymode_agc_get_impulsive_input(void);
//Name: impulsive gate end
//Range: 0x000~0xfff
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_impulsive_gateend(UINT16 setting);
UINT16 drvif_ifd_factorymode_agc_get_impulsive_gateend(void);
//Name: impulsive det thr
//Range: 0x000~0xfff
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_impulsive_detthr(UINT16 setting);
UINT16 drvif_ifd_factorymode_agc_get_impulsive_detthr(void);
//Name: impulsive det stop
//Range: 0x00~0xff
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_impulsive_detstop(UINT8 setting);
UINT8 drvif_ifd_factorymode_agc_get_impulsive_detstop(void);
//Name: impulsive gate delay
//Range: 0x000~0xfff
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_impulsive_gatedelay(UINT16 setting);
UINT16 drvif_ifd_factorymode_agc_get_impulsive_gatedelay(void);
//Name: hum en
//Range: 0:disable 1:enable
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_hum_en(bool setting);
bool drvif_ifd_factorymode_agc_get_hum_en(void);
//Name: hum update sel
//Range: 0:sync level 1:max
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_hum_update_sel(bool setting);
bool drvif_ifd_factorymode_agc_get_hum_update_sel(void);
//Name: hum debounce
//Range: 0x0~0x7
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_hum_debounce(UINT8 setting);
UINT8 drvif_ifd_factorymode_agc_get_hum_debounce(void);
//Name: hum maxthr out
//Range: 0x000~0xfff
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_hum_maxthr_out(UINT16 setting);
UINT16 drvif_ifd_factorymode_agc_get_hum_maxthr_out(void);
//Name: hum maxthr in
//Range: 0x000~0xfff
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_hum_maxthr_in(UINT16 setting);
UINT16 drvif_ifd_factorymode_agc_get_hum_maxthr_in(void);
//Name: hum syncthr out
//Range: 0x000~0xfff
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_hum_syncthr_out(UINT16 setting);
UINT16 drvif_ifd_factorymode_agc_get_hum_syncthr_out(void);
//Name: hum syncthr in
//Range: 0x000~0xfff
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_agc_set_hum_syncthr_in(UINT16 setting);
UINT16 drvif_ifd_factorymode_agc_get_hum_syncthr_in(void);
//Name: hum synclevel var
//Range: 0x000~0xfff
//RW type: R
//Unit: None
UINT16 drvif_ifd_factorymode_agc_get_hum_synclevel_var(void);
//Name: hum synclevel mean
//Range: 0x000~0xfff
//RW type: R
//Unit: None
UINT16 drvif_ifd_factorymode_agc_get_hum_synclevel_mean(void);
//Name: hum max var
//Range: 0x000~0xfff
//RW type: R
//Unit: None
UINT16 drvif_ifd_factorymode_agc_get_hum_max_var(void);
//Name: hum max mean
//Range: 0x000~0xfff
//RW type: R
//Unit: None
UINT16 drvif_ifd_factorymode_agc_get_hum_max_mean(void);
//Name: hum detected
//Range: 0: undetected 1:detected
//RW type: R
//Unit: None
bool drvif_ifd_factorymode_agc_get_hum_detected(void);
//////////////////////////////////////////////////////////////////////////////////////
//Page 9
//////////////////////////////////////////////////////////////////////////////////////
//Name: tuner max num
//Range: 0~10
//RW type: R
//Unit: None
UINT8 drvif_ifd_factorymode_debug_get_tuner_max_num(void);
//Name: tuner id
//Range: 0~[tuner max num]-1
//RW type: R/W
//Unit: None
//Set Tuner ID(0~tuner_max_number-1, ex: tuner_max_number=5, tuner_id=0~4)
void drvif_ifd_factorymode_debug_set_tuner_id(UINT8 tuner_id);
UINT8 drvif_ifd_factorymode_debug_get_tuner_id(char* tuner_name);
//Name: tuner freq
//Range: 0~900000
//RW type: W
//Unit: kHz
void drvif_ifd_factorymode_debug_set_tuner_freq(UINT32 freq);
UINT32 drvif_ifd_factorymode_debug_get_tuner_freq(void);
//Name: tuner bytenum
//Range: 1~9
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_tuner_bytenum(UINT8 byte_num);
UINT8 drvif_ifd_factorymode_debug_get_tuner_bytenum(void);
//Name: tuner byte1
//Range: 0x00~0xff
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_tuner_byte1(UINT8 data);
UINT8 drvif_ifd_factorymode_debug_get_tuner_byte1(void);
//Name: tuner byte2
//Range: 0x00~0xff
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_tuner_byte2(UINT8 data);
UINT8 drvif_ifd_factorymode_debug_get_tuner_byte2(void);
//Name: tuner byte3
//Range: 0x00~0xff
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_tuner_byte3(UINT8 data);
UINT8 drvif_ifd_factorymode_debug_get_tuner_byte3(void);
//Name: tuner byte4
//Range: 0x00~0xff
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_tuner_byte4(UINT8 data);
UINT8 drvif_ifd_factorymode_debug_get_tuner_byte4(void);
//Name: tuner byte5
//Range: 0x00~0xff
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_tuner_byte5(UINT8 data);
UINT8 drvif_ifd_factorymode_debug_get_tuner_byte5(void);
//Name: tuner byte6
//Range: 0x00~0xff
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_tuner_byte6(UINT8 data);
UINT8 drvif_ifd_factorymode_debug_get_tuner_byte6(void);
//Name: tuner byte7
//Range: 0x00~0xff
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_tuner_byte7(UINT8 data);
UINT8 drvif_ifd_factorymode_debug_get_tuner_byte7(void);
//Name: tuner byte8
//Range: 0x00~0xff
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_tuner_byte8(UINT8 data);
UINT8 drvif_ifd_factorymode_debug_get_tuner_byte8(void);
//Name: tuner byte9
//Range: 0x00~0xff
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_tuner_byte9(UINT8 data);
UINT8 drvif_ifd_factorymode_debug_get_tuner_byte9(void);
//Name: tuner byte set
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_tuner_byte_set(void);
//Name: dma mode
//Range: 0x00~0xff
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_dma_mode(IFD_DEBUG_MODE_CONFIG debug_mode);
UINT8 drvif_ifd_factorymode_debug_get_dma_mode(void);
//Name: dma start line en
//Range: enable/disable
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_dma_startline_en(bool enable);
bool drvif_ifd_factorymode_debug_get_dma_startline_en(void);
//Name: dma start line
//Range: 0~1023
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_dma_startline(UINT16 setting);
UINT16 drvif_ifd_factorymode_debug_get_dma_startline(void);
//Name: dma prefix
//Range: <string>
//RW type: R
//Unit: none
void drvif_ifd_factorymode_debug_get_dma_prefix(char* prefix);
//Name: ifagc_pinmux
//Range: 0: GPIO 1: IF AGC
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_debug_set_ifagc_pinmux(bool enable);
bool drvif_ifd_factorymode_debug_get_ifagc_pinmux(void);
//Name: ifagc_padctrl
//Range: 0: ttl 1: open drain
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_debug_set_ifagc_padctrl(bool enable);
bool drvif_ifd_factorymode_debug_get_ifagc_padctrl(void);
//Name: rfagc_pinmux
//Range: 0: GPIO 1: RF AGC
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_debug_set_rfagc_pinmux(bool enable);
bool drvif_ifd_factorymode_debug_get_rfagc_pinmux(void);
//Name: rfagc_padctrl
//Range: 0: ttl 1: open drain
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_debug_set_rfagc_padctrl(bool enable);
bool drvif_ifd_factorymode_debug_get_rfagc_padctrl(void);
//Name: agc sigma delta dnsel
//Range: 0x0~0x4
//RW type: R/W
//Unit: None
void drvif_ifd_factorymode_debug_set_sigma_delta_dnsel(UINT8 dnsel);
UINT8 drvif_ifd_factorymode_debug_get_sigma_delta_dnsel(void);
//Name: intterrupt status
//Range: 0x00000000~0xffffffff
//RW type: R
//Unit: None
UINT32 drvif_ifd_factorymode_debug_get_intterrupt_status(void);
//////////////////////////////////////////////////////////////////////////////////////
//Page 10
//////////////////////////////////////////////////////////////////////////////////////
//Name: turnoff scpu pll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_scpupll(void);
//Name: turnoff acpupll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_acpupll(void);
//Name: turnoff vcpu pll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_vcpupll(void);
//Name: turnoff ddspll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_ddspll(void);
//Name: turnoff vcopll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_vcopll(void);
//Name: turnoff ddrpll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_ddrpll(void);
//Name: turnoff buspll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_buspll(void);
//Name: turnoff hsbuspll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_hsbuspll(void);
//Name: turnoff etnpll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_etnpll(void);
//Name: turnoff gcpupll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_gcpupll(void);
//Name: turnoff audiopll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_audiopll(void);
//Name: turnoff difpll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_difpll(void);
//Name: turnoff dpll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_dpll(void);
//Name: turnoff 27xpll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_27xpll(void);
//Name: turnoff lvds7xpll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_lvds7xpll(void);
//Name: turnoff sysclk
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_sysclk(void);
//Name: turnoff adcpow
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_adcpow(void);
//Name: turnoff adcpll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_adcpll(void);
//Name: turnoff hdmi_videopll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_hdmi_videopll(void);
//Name: turnoff hdmi_audiopll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_hdmi_audiopll(void);
//Name: turnoff usbpll
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_usbpll(void);
//Name: turnoff vipeffect
//Range: 1:active
//RW type: W
//Unit: none
void drvif_ifd_factorymode_debug_set_turnoff_vipeffect(void);
//Name: sw detect timer en
//Range: 0:disable 1:enable
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_swdetect_en(bool enable );
bool drvif_ifd_factorymode_debug_get_swdetect_en(void);
//Name: cvbs_comp_en
//Range: 0:disable 1:enable
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_cvbs_comp(bool enable);
bool drvif_ifd_factorymode_debug_get_cvbs_comp(void);
//Name: scan stop en
//Range: 0:disable 1:enable
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_scan_stop_en(bool enable);
bool drvif_ifd_factorymode_debug_get_scan_stop_en(void);
//Name: scan stop freq
//Range: 0~900000
//RW type: W
//Unit: kHz
void drvif_ifd_factorymode_debug_set_scan_stop_freq(UINT32 freq);
//Name: agc calibration
//Range: 1:active
//RW type: W
//Unit: kHz
void drvif_ifd_factorymode_debug_set_agc_calibration(void);
//Name: debug_msg_level
//Range: IFD_MSG_LEVEL
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_debug_msg_level(IFD_MSG_LEVEL msg_level);
IFD_MSG_LEVEL drvif_ifd_factorymode_debug_get_debug_msg_level(void);



//=====================Debug auto scan========================
//Name: drvif_ifd_factorymode_stop_auto_scan_flag
//Range: stop_auto_scan_point
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_stop_auto_scan_flag(stop_auto_scan_point flag);
//Name: drvif_ifd_factorymode_debug_get_stop_auto_scan_flag
//Range: stop_auto_scan_point
//RW type: R/W
//Unit: none
stop_auto_scan_point drvif_ifd_factorymode_debug_get_stop_auto_scan_flag(void);
//Name: drvif_ifd_factorymode_debug_set_stop_auto_scan_freq
//Range: freq :55250000~900000000
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_set_stop_auto_scan_freq(UINT32 freq);
//Name: drvif_ifd_factorymode_debug_get_stop_auto_scan_freq
//Range: freq :55250000~900000000
//RW type: R/W
//Unit: none
UINT32 drvif_ifd_factorymode_debug_get_stop_auto_scan_freq(void);
//Name: drvif_ifd_factorymode_debug_set_stop_auto_scan_freq
//Range: api_freq :55250000~900000000
//Range:flow_point:stop_auto_scan_point
//Range:factory_setting_point:stop_auto_scan_point
//Range:user_freq :55250000~900000000
//RW type: R/W
//Unit: none
void drvif_ifd_factorymode_debug_stop_auto_scan_flow(stop_auto_scan_point flow_point,stop_auto_scan_point factory_setting_point,UINT32 api_freq,UINT32 user_freq);


//==========================TUNER_SILICONLABS_SI2156 page=============================//

#if defined(CONFIG_TUNER_SILICONLABS_SI2156)||defined(CONFIG_TUNER_SILICONLABS_SI2156_ATV_DTV)||defined(CONFIG_TUNER_SILICONLABS_SI2158)

// Variable Define
typedef enum _TUNER_SILICONLABS_SI2156_INFO
{
    TUNER_INPUT_LEVLE= 0  ,
    TUNER_AtvTunerLockStatus,
    TUNER_AtvOffset,
} TUNER_SILICONLABS_SI2156_INFO;

typedef enum TUNER_SILICONLABS_SI2156_AGC_SPEED
{
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_DEFAULT=0,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_89 =   89,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_105  = 105,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_121=   121,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_137 =  137,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_158 =  158,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_172 =  172,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_185 =  185,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_196 =  196,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_206 =  206,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_216  = 216,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_219 =  219,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_222 =  222,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_248 =  248,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_250 = 250,
    IFD_Si2156_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_251 =  251,
} TUNER_SILICONLABS_SI2156_AGC_SPEED;

typedef enum TUNER_SILICONLABS_SI2156_RF_AGC_TOP
{
    IFD_Si2156_ATV_RF_TOP_PROP_ATV_RF_TOP_DEFAULT    =0,
    IFD_Si2156_ATV_RF_TOP_PROP_ATV_RF_TOP_0DB   = 6,
    IFD_Si2156_ATV_RF_TOP_PROP_ATV_RF_TOP_M1DB =  7,
    IFD_Si2156_ATV_RF_TOP_PROP_ATV_RF_TOP_M2DB =  8,
    IFD_Si2156_ATV_RF_TOP_PROP_ATV_RF_TOP_M4DB  = 10,
    IFD_Si2156_ATV_RF_TOP_PROP_ATV_RF_TOP_M5DB =  11,
    IFD_Si2156_ATV_RF_TOP_PROP_ATV_RF_TOP_M6DB =  12,
    IFD_Si2156_ATV_RF_TOP_PROP_ATV_RF_TOP_M7DB =  13,
    IFD_Si2156_ATV_RF_TOP_PROP_ATV_RF_TOP_M8DB =  14,
    IFD_Si2156_ATV_RF_TOP_PROP_ATV_RF_TOP_M9DB =  15,
} TUNER_SILICONLABS_SI2156_RF_AGC_TOP;

typedef enum TUNER_SILICONLABS_SI2156_IF_PORT_AUXIF_AGC
{
    IFD_Si2156_ATV_CONFIG_IF_PORT_PROP_ATV_AGC_SOURCE_INTERNAL=       0,
    IFD_Si2156_ATV_CONFIG_IF_PORT_PROP_ATV_AGC_SOURCE_AUXIF_AGC_3DB=  2,
} TUNER_SILICONLABS_SI2156_IF_PORT_AUXIF_AGC;

typedef enum TUNER_SILICONLABS_SI2156_Bandwidth
{
    IFD_Si2156_ATV_VIDEO_MODE_PROP_VIDEO_SYS_B=   0,
    IFD_Si2156_ATV_VIDEO_MODE_PROP_VIDEO_SYS_GH = 1,
    IFD_Si2156_ATV_VIDEO_MODE_PROP_VIDEO_SYS_M =  2,
    IFD_Si2156_ATV_VIDEO_MODE_PROP_VIDEO_SYS_N =  3,
    IFD_Si2156_ATV_VIDEO_MODE_PROP_VIDEO_SYS_I  = 4,
    IFD_Si2156_ATV_VIDEO_MODE_PROP_VIDEO_SYS_DK = 5,
    IFD_Si2156_ATV_VIDEO_MODE_PROP_VIDEO_SYS_L  = 6,
    IFD_Si2156_ATV_VIDEO_MODE_PROP_VIDEO_SYS_LP = 7,
} TUNER_SILICONLABS_SI2156_Bandwidth;

typedef enum TUNER_SILICONLABS_SI2156_Bandwidth_CASE
{
    NORNAL_CASE = 0,
    SPECIAL_CASE = 1,
} TUNER_SILICONLABS_SI2156_Bandwidth_CASE;

typedef enum TUNER_SILICONLABS_SI2158_tuner_init_status
{
    IFD_SI2158_TUNER_INIT_OK=1,
    IFD_SI2158_TUNER_INIT_FAIL=0,
} TUNER_SILICONLABS_SI2158_tuner_init_status;

// Function Define
int drvif_ifd_factorymode_get_TUNER_SILICONLABS_SI2156_Information(TUNER_SILICONLABS_SI2156_INFO mode);
void drvif_ifd_factorymode_set_TUNER_SILICONLABS_SI2156_AGC_SPEED(TUNER_SILICONLABS_SI2156_AGC_SPEED agc_speed_value,UINT32 freq);
void drvif_ifd_factorymode_set_TUNER_SILICONLABS_SI2156_RF_AGC_TOP(TUNER_SILICONLABS_SI2156_RF_AGC_TOP rf_agc_top_value,UINT32 freq);
UINT8 drvif_ifd_factorymode_get_TUNER_SILICONLABS_SI2156_AGC_SPEED_info(void);
UINT8 drvif_ifd_factorymode_get_TUNER_SILICONLABS_SI2156_RF_AGC_TOP_info(void);
UINT8 drvif_ifd_factorymode_get_TUNER_SILICONLABS_SI2156_IF_PORT_AUXIF_AGC_info(void);
void drvif_ifd_factorymode_set_TUNER_SILICONLABS_SI2156_IF_PORT_AUXIF_AGC(TUNER_SILICONLABS_SI2156_IF_PORT_AUXIF_AGC if_port_auxif_agc_value);
void drvif_ifd_factorymode_set_TUNER_SILICONLABS_SI2156_Bandwidth(TUNER_SILICONLABS_SI2156_Bandwidth set_tuner_Bandwidth,UINT32 freq );
UINT8 drvif_ifd_factorymode_get_TUNER_SILICONLABS_SI2156_Bandwidth_info(void);
UINT8 drvif_ifd_factorymode_get_TUNER_SILICONLABS_SI2156_IF_Output_Amp_info(void);
void drvif_ifd_factorymodeset_TUNER_SILICONLABS_SI2156_IF_Output_Amp(UINT8 value);
void drvif_ifd_factorymode_set_TUNER_SILICONLABS_SI2156_IF_Output_Amp(UINT8 value);
UINT8 drvif_ifd_get_servicemode_TUNER_SILICONLABS_SI2156_AGC_SPEED_init_value(void);
void drvif_ifd_servicemode_set_TUNER_SILICONLABS_SI2156_Tuner_Bandwidth_B_G(TUNER_SILICONLABS_SI2156_Bandwidth_CASE mode ,UINT32 freq);
UINT8 drvif_ifd_servicemode_get_TUNER_SILICONLABS_SI2156_loop1_dn_sample_default(void);
#ifdef CONFIG_TUNER_SILICONLABS_SI2158
UINT8 drvif_ifd_factorymode_get_TUNER_SILICONLABS_SI2158_tuner_init_status (void);
#endif
#if defined (CONFIG_TUNER_SILICONLABS_SI2156_ATV_DTV)
UINT8 drvif_ifd_factorymode_get_TUNER_SILICONLABS_SI2156_LNA_info(void);
void drvif_ifd_factorymode_set_TUNER_SILICONLABS_SI2156_LNA(bool enable);
#endif
#endif

#if defined(CONFIG_TUNER_SONY_SUTRE232TN)
void drvif_ifd_factorymode_set_SonyTuner_IFoutputvoltage(UINT8 value);
UINT8 drvif_ifd_factorymode_get_SonyTuner_IFoutputvoltage(void);
void drvif_ifd_factorymode_set_SonyTuner_IFGainBalance(UINT8 value);
UINT8 drvif_ifd_factorymode_get_SonyTuner_IFGainBalance(void);
void drvif_ifd_factorymode_set_SonyTuner_BPFfreqOffset(UINT8 value);
UINT8 drvif_ifd_factorymode_get_SonyTuner_BPFfreqOffset(void);
void drvif_ifd_factorymode_set_SonyTuner_IFfreqOffset(UINT8 value);
UINT8 drvif_ifd_factorymode_get_SonyTuner_IFfreqOffset(void);
void drvif_ifd_factorymode_set_SonyTuner_IFBPFBandwidth(UINT8 value);
UINT8 drvif_ifd_factorymode_get_SonyTuner_IFBPFBandwidth(void);
void drvif_ifd_factorymode_set_SonyTuner_Local(UINT8 value);
UINT8 drvif_ifd_factorymode_get_SonyTuner_Local(void);
#endif


#ifdef __cplusplus
}
#endif

#endif



