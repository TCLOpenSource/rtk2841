#include <linux/kernel.h>
#include <linux/slab.h>
#include "demod_rtk_atv.h"
#include "tv_osal.h"
#include "demod.h"
#include "ifd_new.h"
#include "rbus/ifd_108_reg.h"

#include <tvscalercontrol/vdc/video.h>
#include <demod/demod_rtk_common.h>

extern StructIFDDataType stIFDUserData;
extern bool module_vdc_check_vd_clock(void);
#define NOISE_STATUS_MAX 0xff
#define NOISE_STATUS_MIN 0x2

int init_ctl = 0;

/*----------------------------------------------------------------------
 * Func : Constructors
 *
 * Desc : constructor
 *
 * Parm : device_addr : device address
 *        output_mode : RTK_DEMOD_OUT_IF_SERIAL / RTK_DEMOD_OUT_IF_PARALLEL
 *        output_freq : RTK_DEMOD_OUT_FREQ_6M / RTK_DEMOD_OUT_FREQ_10M
 *        pComm       : hadle of COMM
 *
 * Retn : handle of demod
 *----------------------------------------------------------------------*/
void REALTEK_R_ATV_Constructors(DEMOD* pDemodKernel)
{
	REALTEK_R_ATV* pRealtekAtv;

	pDemodKernel->private_data = kmalloc(sizeof(REALTEK_R_ATV), GFP_KERNEL);
	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);
	
	Demod_Constructors(pDemodKernel);
	
	pDemodKernel->m_id                 = DTV_DEMOD_REALTEK_R_ATV;
	pDemodKernel->m_pTuner             = NULL;
	pDemodKernel->m_Capability         = TV_SYS_TYPE_BGDKIL | TV_SYS_TYPE_MN;
	pDemodKernel->m_if.freq            = 36125000;
	pDemodKernel->m_if.inversion       = 0;
	pDemodKernel->m_if.agc_pola        = 0;
	pDemodKernel->m_tv_sys             = TV_SYS_UNKNOWN;

	pDemodKernel->Init = REALTEK_R_ATV_Init;
	pDemodKernel->Reset = REALTEK_R_ATV_Reset;
	pDemodKernel->SetTVSysEx = REALTEK_R_ATV_SetTVSysEx;
	pDemodKernel->SetTVSys = REALTEK_R_ATV_SetTVSys;
	pDemodKernel->SetTvMode = REALTEK_R_ATV_SetTvMode;
	pDemodKernel->SetMode = REALTEK_R_ATV_SetMode;
	pDemodKernel->GetLockStatus = REALTEK_R_ATV_GetLockStatus;
	pDemodKernel->GetCarrierOffset = REALTEK_R_ATV_GetCarrierOffset;
	pDemodKernel->GetSignalQuality = REALTEK_R_ATV_GetSignalQuality;
	pDemodKernel->AcquireSignal = REALTEK_R_ATV_AcquireSignal;
	pDemodKernel->GetSignalInfo = REALTEK_R_ATV_GetSignalInfo;
	pDemodKernel->GetCapability = Demod_GetCapability;
	pDemodKernel->Suspend = REALTEK_R_ATV_Suspend;
	pDemodKernel->Resume = REALTEK_R_ATV_Resume;
	pDemodKernel->InspectSignal = REALTEK_R_ATV_InspectSignal;
	pDemodKernel->AttachTuner = Demod_AttachTuner;
	pDemodKernel->Lock = REALTEK_R_ATV_Lock;
	pDemodKernel->Unlock = REALTEK_R_ATV_Unlock;

	pDemodKernel->Destory = REALTEK_R_ATV_Destructors;
}

/*----------------------------------------------------------------------
 * Func :Destructors
 *
 * Desc : Destructor of ATV Demod
 *
 * Parm : pDemod : handle of Demod
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void REALTEK_R_ATV_Destructors(DEMOD* pDemodKernel)
{
	REALTEK_R_ATV* pRealtekAtv;

	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);
	kfree(pRealtekAtv);
	//pDemodKernel->Destory(pDemodKernel);
	DEMOD_INFO("REALTEK_RREALTEK_R_ATV_Destructors complete\n");
}


/*----------------------------------------------------------------------
 * Func : Init
 *
 * Desc : Initial
 *
 * Parm : N/A
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATV_Init(DEMOD* pDemodKernel)
{
	REALTEK_R_ATV* pRealtekAtv;
	//TUNER_PARAM Param;
	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);

	DEMOD_INFO("REALTEK_R_ATV_Init()\n");
	pDemodKernel->Lock(pDemodKernel);
	//if (!pDemodKernel->m_pTuner)
		//goto atv_init_err;
	//if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, TV_SYS_BG_PAL, &Param) != TUNER_CTRL_OK)
		//goto atv_init_err;
	//if (!pDemodKernel->m_pTuner)
		//goto atv_init_err;

	//drv_ifd_system_init();
	//drv_ifd_user_data_init(Param.id);

	//drv_ifd_init();
	//drv_ifd_set_adcinput_swing((IFD_ADC_SHAGAIN)stIFDUserData.ADCInput_ShaGain, (IFD_ADC_FULLSCALE)stIFDUserData.ADCInput_FullScale);
	//drv_ifd_adc_clk_sel((IFD_CLK_RATE)stIFDUserData.ADCInput_clock, (IFD_INPUT_DN_FILTER)stIFDUserData.ADCinput_dn_filter_sel);
	//drv_ifd_softreset_set();

	//drv_ifd_agc_mode_set(GET_ATV_IFD_AGCPGAMODE(), GET_ATV_IFD_AGCFIXPGAVALUE());

	//IF_AGC, Ball AC4
	//rtd_maskl(0xb8000800,~(0xff<<24),(0x9C<<24));
	//rtd_maskl(0xb8000800, 0x0fffffff, 0x50000000);

	//rtd_outl(IFD_108M_RF_AGC_LIMIT_VALUE_VADDR, ((GET_ATV_IFD_AGC_RF_MIN(0)<<16) |GET_ATV_IFD_AGC_RF_MAX(0)));
	//rtd_outl(IFD_108M_IF_AGC_MIN_VADDR, ((GET_ATV_IFD_AGC_IF_MAX() << 16) | GET_ATV_IFD_AGC_IF_MIN()));

	pRealtekAtv->m_scan_mode = 0;
	pRealtekAtv->m_scan_step = 0;
	pRealtekAtv->m_scan_aft_en = 0;
	init_ctl = 0;

	pDemodKernel->Unlock(pDemodKernel);

	return TUNER_CTRL_OK;

atv_init_err:
	DEMOD_WARNING("RTK_ATV_Init fail\n");
	return TUNER_CTRL_FAIL;
}

/*----------------------------------------------------------------------
 * Func : Reset
 *
 * Desc : Reset
 *
 * Parm : N/A
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATV_Reset(DEMOD* pDemodKernel)
{
	REALTEK_R_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);
	//drv_ifd_softreset_set();
	return TUNER_CTRL_OK;
}

/*----------------------------------------------------------------------
 * Func : SetTVSys
 *
 * Desc : Set TV System
 *
 * Parm : sys : TV System
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATV_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys)
{
	REALTEK_R_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);
	DEMOD_INFO("REALTEK_R_ATV_SetTVSys()\n");
	pDemodKernel->SetTVSysEx(pDemodKernel, sys, NULL);
	return TUNER_CTRL_OK;
}


int REALTEK_R_ATV_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const	TV_SIG_INFO *pSigInfo)
{
	REALTEK_R_ATV* pRealtekAtv;
	TUNER_PARAM Param = {0};
	StructATVModule stAtvModule;
	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);
	DEMOD_INFO("REALTEK_R_ATV_SetTVSysEx()\n");

	//StructATVModule *pAtvModule = &stAtvModule;
	//memset(pAtvModule,0,sizeof(StructATVModule));

	//stAtvModule.freq = stIFDUserData.tunerPara.tunerMaxFreq;

	pDemodKernel->Lock(pDemodKernel);

	pRealtekAtv->m_scan_mode = 0;
	pRealtekAtv->m_scan_step = 0;
	pRealtekAtv->m_scan_aft_en = 0;

	if (init_ctl == 0) {
		if (pDemodKernel->m_pTuner) {
			if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, TV_SYS_BG_PAL, &Param) == TUNER_CTRL_OK) {
				DEMOD_INFO("Tuner id %d\n", Param.id);
				drv_ifd_user_data_init(Param.id);
			}
		}
		else
			DEMOD_INFO("Get Tuner id fail !id=%d\n", Param.id);
		
		AtvDemodInitialization(RTK_DEMOD_MODE_ATV);
		rtd_maskl(SYS_REG_SYS_CLKSEL_reg, ~(_BIT17), 0);//ATV Input clcok select 1: Video Decoder Clock 0: IF Demod Clock
		drv_ifd_init();
		//drv_ifd_agc_mode_set(GET_ATV_IFD_AGCPGAMODE(), GET_ATV_IFD_AGCFIXPGAVALUE());
		//rtd_outl(IFD_108_if_agc_min_reg, ((GET_ATV_IFD_AGC_IF_MAX() << 16) | GET_ATV_IFD_AGC_IF_MIN()));
		//drv_ifd_set_adcinput_swing((IFD_ADC_SHAGAIN)stIFDUserData.ADCInput_ShaGain, (IFD_ADC_FULLSCALE)stIFDUserData.ADCInput_FullScale);
		//drv_ifd_adc_clk_sel((IFD_CLK_RATE)stIFDUserData.ADCInput_clock, (IFD_INPUT_DN_FILTER)stIFDUserData.ADCinput_dn_filter_sel);
		init_ctl = 1;
	}

	switch (sys) {

	case TV_SYS_BG_PAL :
		stAtvModule.video_mode = ZPAL_60;
		stAtvModule.audio_mode = ATV_SOUND_BG_SYSTEM;
		break;
	case TV_SYS_I_PAL :
		stAtvModule.video_mode = ZPAL_I;
		stAtvModule.audio_mode = ATV_SOUND_I_SYSTEM;
		break;
	case TV_SYS_DK_PAL :
		stAtvModule.video_mode = ZPAL_60;
		stAtvModule.audio_mode = ATV_SOUND_DK_SYSTEM;
		break;
	case TV_SYS_BG_SECAM :
		stAtvModule.video_mode = ZSECAM;
		stAtvModule.audio_mode = ATV_SOUND_BG_SYSTEM;
		break;
	case TV_SYS_DK_SECAM :
		stAtvModule.video_mode = ZSECAM;
		stAtvModule.audio_mode = ATV_SOUND_DK_SYSTEM;
		break;
	case TV_SYS_L_SECAM :
		stAtvModule.video_mode = ZSECAML;
		stAtvModule.audio_mode = ATV_SOUND_L_SYSTEM;
		break;
	case TV_SYS_LL_SECAM :
		stAtvModule.video_mode = ZSECAMLA;
		stAtvModule.audio_mode = ATV_SOUND_LA_SYSTEM;
		break;
	case TV_SYS_M_NTSC :
		stAtvModule.video_mode = ZNTSC;
		stAtvModule.audio_mode = ATV_SOUND_MN_SYSTEM;
		break;
	case TV_SYS_M_PAL :
		stAtvModule.video_mode = ZPAL_M;
		stAtvModule.audio_mode = ATV_SOUND_MN_SYSTEM;
		break;
	case TV_SYS_N_PAL :
		stAtvModule.video_mode = ZPAL_N;
		stAtvModule.audio_mode = ATV_SOUND_MN_SYSTEM;
		break;
	default :
		DEMOD_WARNING("[SetTVSys] UNknow TV system !!!!!! SET TV SYSTEM = PAL DK (DEFAULT)\n");
		stAtvModule.video_mode = ZPAL_60;
		stAtvModule.audio_mode = ATV_SOUND_DK_SYSTEM;
	}

	if (pSigInfo != NULL)
		stAtvModule.scan_mode = pSigInfo->analog.scan_mode;
	else
		stAtvModule.scan_mode = 0;

	DEMOD_INFO("[SetTVSys] pAtvModule->video_mode=%d\n ", stAtvModule.video_mode);
	DEMOD_INFO("[SetTVSys] pAtvModule->audio_mode=%d\n ", stAtvModule.audio_mode);
	DEMOD_INFO("[SetTVSys] pAtvModule->scan_mode=%d\n ", stAtvModule.scan_mode);

	if (stAtvModule.scan_mode == 1)
		pRealtekAtv->m_scan_mode = 1;

	pRealtekAtv->m_scan_step = 0; //reset

	pRealtekAtv->m_sys = sys;


	if (stAtvModule.scan_mode == 1)
		drvif_ifd_set_scanchannel(&stAtvModule);
	else
		drvif_ifd_set_setchannel(&stAtvModule);

	//pRealtekAtv->m_scan_aft_en = pSigInfo->scan_mode_aft_en;
	pRealtekAtv->m_scan_aft_en = 1;

	pDemodKernel->Unlock(pDemodKernel);

	return TUNER_CTRL_OK;
}

int REALTEK_R_ATV_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode)
{
	REALTEK_R_ATV* pRealtekAtv;
	int ret = TUNER_CTRL_FAIL;

	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);


	pDemodKernel->Lock(pDemodKernel);

	DEMOD_INFO("REALTEK_R_ATV_SetTvMode(%d)\n", mode);

	switch (mode) {

	case TV_SYS_TYPE_BGDKIL:
	case TV_SYS_TYPE_MN:

		DEMOD_INFO("REALTEK_R_ATV_SetTVMode\n");
		ret  = pDemodKernel->Init(pDemodKernel);

		if (ret != TUNER_CTRL_OK) {
			DEMOD_INFO("Set REALTEK_R_ATV to ATV mode failed\n");
			goto set_demod_mode_failed;
		}

		break;

	default:
		goto set_demod_mode_failed;
	}

	ret = TUNER_CTRL_OK;
	DEMOD_INFO("Set REALTEK_R_ATV to appointed ATV mode successed\n");

	pDemodKernel->Unlock(pDemodKernel);
	return ret;

	//--------------
set_demod_mode_failed:

	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_FAIL;
}


/*----------------------------------------------------------------------
 * Func : SetMode
 *
 * Desc : Set operation mode of demod
 *
 * Parm : mode : Demod opreation mode
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATV_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode)
{
	REALTEK_R_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);

	switch (mode) {
	default:
	case TV_OP_MODE_NORMAL:
	case TV_OP_MODE_SCANING:

		break;

	case TV_OP_MODE_STANDBY:

		break;
	}
	return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : GetLockStatus
 *
 * Desc : Get Demod Lock Status
 *
 * Parm : pLock : Lock Status
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATV_GetLockStatus(DEMOD* pDemodKernel, unsigned char *pLock)
{
	REALTEK_R_ATV* pRealtekAtv;
	int lock_count = 0, i = 0;

	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);
	//bool res=_FALSE;
	//drv_ifd_set_cr_lock_freq_thr((UINT16)IFD_CR_LOCK_OFFSET_THD_300K);
	//if(drv_ifd_pointer_check() == _FALSE) return _FALSE;

	pDemodKernel->Lock(pDemodKernel);

	if (init_ctl==0) {
		*pLock = 0;
		DEMOD_WARNING("drvif_ifd_get_cr_lock()-->demod not init yet !\n");
		return TUNER_CTRL_OK;
	}

	if (1) {
		for (i = 0; i < 10; i++) {
			if (drv_ifd_get_cr_lock_status()) lock_count++;
			tv_osal_usleep(300);
		}

		if (lock_count > 7) {
			*pLock = 1;
		} else {
			*pLock = 0;
		}
	} else {
		for (i = 0; i < 10; i++) {
			if (drvif_ifd_scan_mode_detect_cr_lock()) lock_count++;
			tv_osal_usleep(300);
		}

		if (lock_count > 7) {
			*pLock = 1;
		} else {
			*pLock = 0;
		}
	}

	DEMOD_INFO("drvif_ifd_get_cr_lock()-->%x\n", * pLock);
	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_OK;

}

/*----------------------------------------------------------------------
 * Func : GetCarrierOffset
 *
 * Desc : Get the carrier offset.
 *
 * Parm : pOffset : carrier frequency offset output (unit : Hz)
 *
 *          Note: the offset value is only valid as demod is on lock stage.
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATV_GetCarrierOffset(DEMOD* pDemodKernel, long *pOffset)
{
	int ret = 0;
	REALTEK_R_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);

	pDemodKernel->Lock(pDemodKernel);
	*pOffset = drv_ifd_get_cr_offset_100hz() * 100;
	if (pRealtekAtv->m_scan_step == 1) {
		//DEMOD_INFO("SHIFT at -1MHz\n");
		*pOffset = *pOffset - 1000000;
	} else if (pRealtekAtv->m_scan_step == 2) {
		//DEMOD_INFO("SHIFT at +1MHz\n");
		*pOffset = *pOffset + 1000000;
	} else if (pRealtekAtv->m_scan_step == 3) {
		//DEMOD_INFO("SHIFT at -1.5MHz\n");
		*pOffset = *pOffset - 1500000;
	} else if (pRealtekAtv->m_scan_step == 4) {
		//DEMOD_INFO("SHIFT at +1.5MHz\n");
		*pOffset = *pOffset + 1500000;
	} else {
		;//DEMOD_INFO("NO SHIFT\n");
	}
	//DEMOD_INFO("GetCarrierOffset= %dHz\n", * pOffset);
	DEMOD_INFO("GetCarrierOffset= %dHz\n", * pOffset);
	pDemodKernel->Unlock(pDemodKernel);

	return ret;
}


/*----------------------------------------------------------------------
 * Func : GetSignalInfo
 *
 * Desc : Get Signal Information
 *
 * Parm : pInfo : Siganl Information
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATV_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO *pInfo)
{
	REALTEK_R_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);
	pInfo->mod = TV_MODULATION_ATV;
	return TUNER_CTRL_OK;
}




/*----------------------------------------------------------------------
 * Func : GetSignalQuality
 *
 * Desc : Get Signal Information
 *
 * Parm : id : Type of Quality Information
 *        pQuality : Siganl Quality
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATV_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL *pQuality)
{
	REALTEK_R_ATV* pRealtekAtv;
	UINT16 noise_status_data;
	unsigned long agc_data;

	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);

	pDemodKernel->Lock(pDemodKernel);

	switch (id) {
	case TV_QUAL_SIGNAL_QUALITY :
		noise_status_data = drvif_ifd_get_noise_status();
		if (noise_status_data >= NOISE_STATUS_MAX)
			pQuality->quality = 0;
		else if (noise_status_data <= NOISE_STATUS_MIN)
			pQuality->quality = 100;
		else {
			noise_status_data = NOISE_STATUS_MAX - noise_status_data;
			pQuality->quality = (noise_status_data * 100) / (NOISE_STATUS_MAX - NOISE_STATUS_MIN + 1);

		}
		break;

	case TV_QUAL_AGC:
		agc_data = drv_ifd_agc_get_if_output();
		pQuality->agc = (agc_data * 100) / 8192;
		break;

	case TV_QUAL_DEMODFWVERSION:
		pQuality->DemodFwVersion = 0x000001;
		break;

	default:
		pDemodKernel->Unlock(pDemodKernel);
		return  TUNER_CTRL_FAIL;
	}

	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_OK;
}



/*----------------------------------------------------------------------
 * Func : AcquireSignal
 *
 * Desc : Reset Demodulator and Acquire Signal.
 *        This function should be called when channel changed.
 *
 * Parm : WaitSignalLock : wait until signal lock
 *          0 : don't wait,
 *          others: wait for signal lock
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATV_AcquireSignal(DEMOD* pDemodKernel, 	unsigned char WaitSignalLock)
{
	unsigned long   stime, stime_start, stime_end;
	unsigned char   lock = 0;
	unsigned long   shift_nco_backup, if_freq_backup;
	REALTEK_R_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);

	//drv_ifd_soft_reset(IFD_ENABLE);
	//drv_ifd_soft_reset(IFD_DISABLE);

	if (!WaitSignalLock) {

		return TUNER_CTRL_OK;
	}

	pDemodKernel->Lock(pDemodKernel);
	stime = tv_osal_time();
	stime_start = stime;

#if 0

	if (0) { //(pRealtekAtv->m_scan_aft_en == 1) {
		shift_nco_backup = drv_ifd_cr_shift_nco_getinfo();
		if_freq_backup = drv_ifd_if_frequency_getinfo();
		pRealtekAtv->m_scan_step = 0;
		//detect IF at 0MHZ
		while ((tv_osal_time() - stime) <= 40) {
			tv_osal_msleep(1);
			pDemodKernel->GetLockStatus(pDemodKernel, &lock);
			DEMOD_INFO("signal lock = %d, time=%d\n", lock, tv_osal_time() - stime);
			if (lock)
				break;
		}

		if (lock) goto atv_detect_end;
		else {
			//retore NCO setting
			drv_ifd_cr_shift_nco(shift_nco_backup);
			pRealtekAtv->m_scan_step = 1;
			drv_ifd_shift_nco(10000);
		}
		//detect IF at -1MHZ
		stime = tv_osal_time();
		while ((tv_osal_time() - stime) <= 15) {
			tv_osal_msleep(1);
			pDemodKernel->GetLockStatus(pDemodKernel, &lock);
			DEMOD_INFO("signal lock = %d, time=%d\n", lock, tv_osal_time() - stime);
			if (lock)
				break;
		}

		if (lock) goto atv_detect_end;
		else {
			//retore NCO setting
			drv_ifd_cr_shift_nco(shift_nco_backup);
			pRealtekAtv->m_scan_step = 2;
			drv_ifd_shift_nco(-10000);
		}
		//detect IF at +1MHZ
		stime = tv_osal_time();
		while ((tv_osal_time() - stime) <= 15) {
			tv_osal_msleep(1);
			pDemodKernel->GetLockStatus(pDemodKernel, &lock);
			DEMOD_INFO("signal lock = %d, time=%d\n", lock, tv_osal_time() - stime);
			if (lock)
				break;
		}

		if (lock) goto atv_detect_end;
		else {
			//retore NCO setting
			drv_ifd_cr_shift_nco(shift_nco_backup);
			pRealtekAtv->m_scan_step = 3;
			drv_ifd_shift_nco(15000);
		}
		//detect IF at -1.5MHZ
		stime = tv_osal_time();
		while ((tv_osal_time() - stime) <= 100) {
			tv_osal_msleep(10);
			pDemodKernel->GetLockStatus(pDemodKernel, &lock);
			DEMOD_INFO("signal lock = %d, time=%d\n", lock, tv_osal_time() - stime);
			if (lock)
				break;
		}
		if (lock) goto atv_detect_end;
		else {
			//retore NCO setting
			drv_ifd_cr_shift_nco(shift_nco_backup);
			pRealtekAtv->m_scan_step = 4;
			drv_ifd_shift_nco(-15000);
		}
		//detect IF at +1.5MHZ
		stime = tv_osal_time();
		while ((tv_osal_time() - stime) <= 100) {
			tv_osal_msleep(10);
			pDemodKernel->GetLockStatus(pDemodKernel, &lock);
			DEMOD_INFO("signal lock = %d, time=%d\n", lock, tv_osal_time() - stime);
			if (lock)
				break;
		}

atv_detect_end:
		stime_end = tv_osal_time();
		DEMOD_INFO("[Final]signal lock = %d, time=%d\n", lock, stime_end - stime_start);
		//retore NCO setting
		//drv_ifd_cr_shift_nco(shift_nco_backup);
		//if (lock==0) pRealtekAtv->m_scan_step =0;//clear
#endif

	if (1) {
		
			while ((tv_osal_time() - stime) <= 60) {
				tv_osal_msleep(5);
			pDemodKernel->GetLockStatus(pDemodKernel, &lock);
			DEMOD_INFO("signal lock = %d, time=%d\n", lock, tv_osal_time() - stime);
			if (lock)
				break;
		}
		
	} else {

		drv_ifd_set_power_diff_cr_lock(1);
		tv_osal_msleep(5);
		while ((tv_osal_time() - stime) <= 50) {
			lock = drvif_ifd_scan_mode_detect_cr_lock();
			if (lock == 1) break;
			tv_osal_msleep(1);
		}
		DEMOD_INFO("signal lock = %d, time=%d\n", lock, tv_osal_time() - stime);
		drv_ifd_set_power_diff_cr_lock(0);

	}


		if (lock) {

			if ((pRealtekAtv->m_sys == TV_SYS_L_SECAM) || (pRealtekAtv->m_sys == TV_SYS_LL_SECAM))
				drv_ifd_clamp_reset(IFD_CLAMP_RESET_POS);
			else
				drv_ifd_clamp_reset(IFD_CLAMP_RESET_NEG);

		}

	pDemodKernel->Unlock(pDemodKernel);
	return (lock) ? TUNER_CTRL_OK : TUNER_CTRL_NO_SIGNAL;
}





/*----------------------------------------------------------------------
 * Func : Suspend
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATV_Suspend(DEMOD* pDemodKernel)
{
	REALTEK_R_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);

	return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : Resume
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATV_Resume(DEMOD* pDemodKernel)
{
	REALTEK_R_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);

	return TUNER_CTRL_OK;

}




/*----------------------------------------------------------------------
 * Func : InspectSignal
 *
 * Desc : Inspect Signal Info (for Debug Purpose)
 *
 * Parm : pBuff : message buffer
 *        BufferSize : size of message buffer
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATV_InspectSignal(DEMOD* pDemodKernel,	char *pBuff, unsigned long BufferSize)
{
#if 0
	bool agc_lock, cr_lock;
	INT32 cr_offset;
	unsigned long agc_data;
	REALTEK_R_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_R_ATV*)(pDemodKernel->private_data);


	pDemodKernel->Lock(pDemodKernel);
	agc_lock = drvif_ifd_get_agc_lock();
	cr_lock =	drv_ifd_get_cr_lock_status();
	cr_offset = drv_ifd_get_cr_offset_100hz() / 10;
	agc_data = (drv_ifd_agc_get_if_output() * 100) / 8192;

	DEMOD_INFO("[RTD2945_ATV] AGC lock=%d, CR lock=%d, cr_offset=%d KHz, IF_agc=%d\n", agc_lock, cr_lock, cr_offset, agc_data);
	pDemodKernel->Unlock(pDemodKernel);
#endif

	return TUNER_CTRL_OK;

}
//ATV function

void drv_ifd_system_init(void)
{
	// need modified Todd
	//g_curr_video_std = 0xff;
	//g_curr_audio_std = 0xff;

	//g_scan_curr_video_std = 0xff;
	//g_scan_curr_audio_std = 0xff;

	//g_afc_ongoing=0;
	//g_afc_stage_count=0;
	//g_afc_curr_freq=0;
	//g_afc_center_freq=0;
	//g_afc_direction=0;
}

void REALTEK_R_ATV_Lock(DEMOD* pDemodKernel)
{
	//mutex_lock(&pDemodKernel->m_lock);
}

void REALTEK_R_ATV_Unlock(DEMOD* pDemodKernel)
{
	//mutex_unlock(&pDemodKernel->m_lock);
}