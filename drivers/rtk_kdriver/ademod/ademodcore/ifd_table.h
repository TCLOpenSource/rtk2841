

#ifdef __cplusplus
extern "C" {
#endif

#include "tuner_atv_base.h"


	/***Data Types**********************************************************************/
#ifndef UINT8
	typedef unsigned char  UINT8;
#endif
#ifndef UINT16
	typedef unsigned short UINT16;
#endif
#ifndef UINT32
	typedef unsigned int   UINT32;
#endif
#ifndef INT8
typedef  char INT8;
#endif
#ifndef INT16
typedef  short INT16;
#endif
#ifndef INT32
	typedef  int INT32;
#endif
#ifndef BOOL
typedef int BOOL;
//#define BOOL                        bool
#endif

/*
	typedef signed char         INT8;
	typedef unsigned char  UINT8;
	typedef unsigned short UINT16;
	typedef unsigned int   UINT32;
	typedef  int INT32;
*/

#define IFD_TUNER_BAND_MAX 24
#define IFD_TUNER_REG_MAX 4
#define IFD_TUNER_REG_BAND_MAX IFD_TUNER_BAND_MAX*IFD_TUNER_REG_MAX
#define IFD_CR_BPF_TABLE_SIZE 41
#define IFD_OUTPUT_LPF_TABLE_SIZE 96
#define IFD_EQ_TABLE_SIZE (32)
#define IFD_GP_BPF_TABLE_SIZE 34
#define IFD_INPUT_FILTER_TABLE_SIZE 72

	typedef enum _TUNER_ID {
		TUNER_NULL = 0,
		TUNER_NXP_TDA18273,
		TUNER_NXP_TDA18275A,
		TUNER_SILICONLABS_SI2178B,
		TUNER_SILICONLABS_SI2151,
	} TUNER_ID;


	typedef struct {
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

	typedef struct {
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
		bool		CRPower_Lock;
		UINT16 	CRPower_Lock_Thr;
		bool		GRPdelayM_En;
		bool		GRPdelayN_En;
		bool		GRPdelayBG_En;
		bool		GRPdelayDK_En;
		bool		GRPdelayL_En;
		bool		GRPdelayLA_En;
		bool		GRPdelayI_En;
		UINT16	GRPdelayTableM[IFD_GP_BPF_TABLE_SIZE];
		UINT16	GRPdelayTableN[IFD_GP_BPF_TABLE_SIZE];
		UINT16	GRPdelayTableBG[IFD_GP_BPF_TABLE_SIZE];
		UINT16	GRPdelayTableDK[IFD_GP_BPF_TABLE_SIZE];
		UINT16	GRPdelayTableL[IFD_GP_BPF_TABLE_SIZE];
		UINT16	GRPdelayTableLA[IFD_GP_BPF_TABLE_SIZE];
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
		bool		EQ_Table_PAL_DK_En;
		bool		EQ_Table_SECAM_L_En;
		bool		EQ_Table_SECAM_LA_En;
		UINT16	EQ_Table_NTSC[IFD_EQ_TABLE_SIZE];
		UINT16	EQ_Table_PAL_BG[IFD_EQ_TABLE_SIZE];
		UINT16	EQ_Table_PAL_I[IFD_EQ_TABLE_SIZE];
		UINT16	EQ_Table_PAL_DK[IFD_EQ_TABLE_SIZE];
		UINT16	EQ_Table_SECAM_L[IFD_EQ_TABLE_SIZE];
		UINT16	EQ_Table_SECAM_LA[IFD_EQ_TABLE_SIZE];
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
#define GET_ATV_IFD_CRPOWER_LOCK_EN()					stIFDUserData.CRPower_Lock
#define GET_ATV_IFD_CRPOWER_LOCK_THR()					stIFDUserData.CRPower_Lock_Thr
#define GET_ATV_IFD_CRSHIFT_TARGET_FREQ()				stIFDUserData.CRShift_Target_Freq
#define GET_ATV_IFD_GRPDELAYM_EN()                                        stIFDUserData.GRPdelayM_En
#define GET_ATV_IFD_GRPDELAYN_EN()                                        stIFDUserData.GRPdelayN_En
#define GET_ATV_IFD_GRPDELAYBG_EN()                                       stIFDUserData.GRPdelayBG_En
#define GET_ATV_IFD_GRPDELAYDK_EN()                                      stIFDUserData.GRPdelayDK_En
#define GET_ATV_IFD_GRPDELAYL_EN()                                      stIFDUserData.GRPdelayL_En
#define GET_ATV_IFD_GRPDELAYLA_EN()                                      stIFDUserData.GRPdelayLA_En
#define GET_ATV_IFD_GRPDELAYTABLEM()                                      &stIFDUserData.GRPdelayTableM[0]
#define GET_ATV_IFD_GRPDELAYTABLEN()                                      &stIFDUserData.GRPdelayTableN[0]
#define GET_ATV_IFD_GRPDELAYTABLEBG()                                     &stIFDUserData.GRPdelayTableBG[0]
#define GET_ATV_IFD_GRPDELAYTABLEDK()                                    &stIFDUserData.GRPdelayTableDK[0]
#define GET_ATV_IFD_GRPDELAYTABLEL()                                    &stIFDUserData.GRPdelayTableL[0]
#define GET_ATV_IFD_GRPDELAYTABLELA()                                    &stIFDUserData.GRPdelayTableLA[0]
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
#define GET_ATV_IFD_EQ_TABLE_PAL_DK_EN()                                 stIFDUserData.EQ_Table_PAL_DK_En
#define GET_ATV_IFD_EQ_TABLE_SECAM_L_EN()                                 stIFDUserData.EQ_Table_SECAM_L_En
#define GET_ATV_IFD_EQ_TABLE_SECAM_LA_EN()                                 stIFDUserData.EQ_Table_SECAM_LA_En
#define GET_ATV_IFD_EQ_TABLE_NTSC()                                       &stIFDUserData.EQ_Table_NTSC[0]
#define GET_ATV_IFD_EQ_TABLE_PAL_BG()                                     &stIFDUserData.EQ_Table_PAL_BG[0]
#define GET_ATV_IFD_EQ_TABLE_PAL_I()                                      &stIFDUserData.EQ_Table_PAL_I[0]
#define GET_ATV_IFD_EQ_TABLE_PAL_DK()                                    &stIFDUserData.EQ_Table_PAL_DK[0]
#define GET_ATV_IFD_EQ_TABLE_SECAM_L()                                    &stIFDUserData.EQ_Table_SECAM_L[0]
#define GET_ATV_IFD_EQ_TABLE_SECAM_LA()                                    &stIFDUserData.EQ_Table_SECAM_LA[0]
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
#define GET_ATV_TUNER_AGC_POLARITY() ((TUNER_AGCPOLARITY_SEL)stIFDUserData.tunerPara.tunerAGCpolarity)
#define GET_ATV_TUNER_PIF() (stIFDUserData.tunerPara.tunerPIF)
#define GET_ATV_TUNER_TYPE() (stIFDUserData.tunerPara.tunerType)
#define GET_ATV_TUNER_ID() (stIFDUserData.tunerPara.tunerID)




	void drv_ifd_user_data_init(unsigned short  tuner_id);

#ifdef __cplusplus
}
#endif







