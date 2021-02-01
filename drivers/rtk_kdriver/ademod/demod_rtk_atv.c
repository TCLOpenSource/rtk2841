#include <linux/kernel.h>
#include <linux/slab.h>
#include "demod_rtk_atv.h"
#include "tv_osal.h"
#include "ademod.h"
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
void REALTEK_ATV_Constructors(ADEMOD* pADemodKernel)
{
	REALTEK_ATV* pRealtekAtv;

	pADemodKernel->private_data = kmalloc(sizeof(REALTEK_ATV), GFP_KERNEL);
	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);

	ADemod_Constructors(pADemodKernel);

	pADemodKernel->m_id                 = DTV_ADEMOD_REALTEK;
	pADemodKernel->m_pTuner             = NULL;
	pADemodKernel->m_Capability         = TV_SYS_TYPE_BGDKIL | TV_SYS_TYPE_MN;
	pADemodKernel->m_if.freq            = 36125000;
	pADemodKernel->m_if.inversion       = 0;
	pADemodKernel->m_if.agc_pola        = 0;
	pADemodKernel->m_tv_sys             = TV_SYS_UNKNOWN;

	pADemodKernel->Init = REALTEK_ATV_Init;
	pADemodKernel->Reset = REALTEK_ATV_Reset;
	pADemodKernel->SetTVSysEx = REALTEK_ATV_SetTVSysEx;
	pADemodKernel->SetTVSys = REALTEK_ATV_SetTVSys;
	pADemodKernel->SetTvMode = REALTEK_ATV_SetTvMode;
	pADemodKernel->SetMode = REALTEK_ATV_SetMode;
	pADemodKernel->GetLockStatus = REALTEK_ATV_GetLockStatus;
	pADemodKernel->GetCarrierOffset = REALTEK_ATV_GetCarrierOffset;
	pADemodKernel->GetSignalQuality = REALTEK_ATV_GetSignalQuality;
	pADemodKernel->AcquireSignal = REALTEK_ATV_AcquireSignal;
	pADemodKernel->GetSignalInfo = REALTEK_ATV_GetSignalInfo;
	pADemodKernel->GetCapability = ADemod_GetCapability;
	pADemodKernel->Suspend = REALTEK_ATV_Suspend;
	pADemodKernel->Resume = REALTEK_ATV_Resume;
	pADemodKernel->InspectSignal = REALTEK_ATV_InspectSignal;
	pADemodKernel->AttachTuner = ADemod_AttachTuner;
	pADemodKernel->Lock = ADemod_Lock;
	pADemodKernel->Unlock = ADemod_Unlock;

	pRealtekAtv->Destory = REALTEK_ATV_Destructors;
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
void REALTEK_ATV_Destructors(ADEMOD* pADemodKernel)
{
	REALTEK_ATV* pRealtekAtv;

	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);
	kfree(pRealtekAtv);
	pADemodKernel->Destory(pADemodKernel);
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
int REALTEK_ATV_Init(ADEMOD* pADemodKernel)
{
	REALTEK_ATV* pRealtekAtv;
	TUNER_PARAM Param;
	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);

	ADEMOD_INFO("REALTEK_ATV_Init()\n");
	pADemodKernel->Lock(pADemodKernel);
	if (!pADemodKernel->m_pTuner)
		goto atv_init_err;
	if (pADemodKernel->m_pTuner->GetParam(pADemodKernel->m_pTuner, TV_SYS_BG_PAL, &Param) != TUNER_CTRL_OK)
		goto atv_init_err;
	if (!pADemodKernel->m_pTuner)
		goto atv_init_err;

	//drv_ifd_system_init();
	drv_ifd_user_data_init(Param.id);

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

	pADemodKernel->Unlock(pADemodKernel);

	return TUNER_CTRL_OK;

atv_init_err:
	ADEMOD_WARNING("RTK_ATV_Init fail\n");
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
int REALTEK_ATV_Reset(ADEMOD* pADemodKernel)
{
	REALTEK_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);
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
int REALTEK_ATV_SetTVSys(ADEMOD* pADemodKernel, TV_SYSTEM sys)
{
	REALTEK_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);
	ADEMOD_INFO("REALTEK_ATV_SetTVSys()\n");
	pADemodKernel->SetTVSysEx(pADemodKernel, sys, NULL);
	return TUNER_CTRL_OK;
}


int REALTEK_ATV_SetTVSysEx(ADEMOD* pADemodKernel, TV_SYSTEM sys, const	TV_SIG_INFO *pSigInfo)
{
	REALTEK_ATV* pRealtekAtv;
	StructATVModule stAtvModule;
	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);
	ADEMOD_INFO("REALTEK_ATV_SetTVSysEx()\n");

	//StructATVModule *pAtvModule = &stAtvModule;
	//memset(pAtvModule,0,sizeof(StructATVModule));

	stAtvModule.freq = stIFDUserData.tunerPara.tunerMaxFreq;

	pADemodKernel->Lock(pADemodKernel);

	pRealtekAtv->m_scan_mode = 0;
	pRealtekAtv->m_scan_step = 0;
	pRealtekAtv->m_scan_aft_en = 0;

	if (init_ctl == 0) {
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
		ADEMOD_WARNING("[SetTVSys] UNknow TV system !!!!!! SET TV SYSTEM = PAL DK (DEFAULT)\n");
		stAtvModule.video_mode = ZPAL_60;
		stAtvModule.audio_mode = ATV_SOUND_DK_SYSTEM;
	}

	if (pSigInfo != NULL)
		stAtvModule.scan_mode = pSigInfo->analog.scan_mode;
	else
		stAtvModule.scan_mode = 0;

	ADEMOD_INFO("[SetTVSys] pAtvModule->video_mode=%d\n ", stAtvModule.video_mode);
	ADEMOD_INFO("[SetTVSys] pAtvModule->audio_mode=%d\n ", stAtvModule.audio_mode);
	ADEMOD_INFO("[SetTVSys] pAtvModule->scan_mode=%d\n ", stAtvModule.scan_mode);

	if (stAtvModule.scan_mode == 1)
		pRealtekAtv->m_scan_mode = 1;

	pRealtekAtv->m_scan_step = 0; //reset

	pRealtekAtv->m_sys = sys;

	if (stAtvModule.scan_mode == 1) {
		drvif_ifd_set_scanchannel(&stAtvModule);
		/* Set scan flag */
		drvif_module_vdc_set_scan_flag(TRUE);
		drvif_module_vdc_set_int_auto_scan_flag(TRUE);
		/* Clear channel change flag */
		drvif_module_vdc_set_ch_change_flag(FALSE);
	} else {
		drvif_ifd_set_setchannel(&stAtvModule);
		/* Clear scan flag */
		drvif_module_vdc_set_scan_flag(FALSE);
		drvif_module_vdc_set_int_auto_scan_flag(FALSE);
		/* Set channel change flag */
		drvif_module_vdc_set_ch_change_flag(TRUE);
	}

	//pRealtekAtv->m_scan_aft_en = pSigInfo->scan_mode_aft_en;
	pRealtekAtv->m_scan_aft_en = 1;

	pADemodKernel->Unlock(pADemodKernel);

	return TUNER_CTRL_OK;
}

int REALTEK_ATV_SetTvMode(ADEMOD* pADemodKernel, TV_SYSTEM_TYPE mode)
{
	REALTEK_ATV* pRealtekAtv;
	int ret = TUNER_CTRL_FAIL;

	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);


	pADemodKernel->Lock(pADemodKernel);

	ADEMOD_INFO("REALTEK_ATV_SetTvMode(%d)\n", mode);

	switch (mode) {

	case TV_SYS_TYPE_BGDKIL:
	case TV_SYS_TYPE_MN:

		ADEMOD_INFO("REALTEK_ATV_SetTVMode\n");
		ret  = pADemodKernel->Init(pADemodKernel);

		if (ret != TUNER_CTRL_OK) {
			ADEMOD_INFO("Set REALTEK_ATV to ATV mode failed\n");
			goto set_demod_mode_failed;
		}

		break;

	default:
		goto set_demod_mode_failed;
	}

	ret = TUNER_CTRL_OK;
	ADEMOD_INFO("Set REALTEK_ATV to appointed ATV mode successed\n");

	pADemodKernel->Unlock(pADemodKernel);
	return ret;

	//--------------
set_demod_mode_failed:

	pADemodKernel->Unlock(pADemodKernel);
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
int REALTEK_ATV_SetMode(ADEMOD* pADemodKernel, TV_OP_MODE mode)
{
	REALTEK_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);

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
int REALTEK_ATV_GetLockStatus(ADEMOD* pADemodKernel, unsigned char *pLock)
{
	REALTEK_ATV* pRealtekAtv;
	int lock_count = 0, i = 0;

	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);
	//bool res=_FALSE;
	//drv_ifd_set_cr_lock_freq_thr((UINT16)IFD_CR_LOCK_OFFSET_THD_300K);
	//if(drv_ifd_pointer_check() == _FALSE) return _FALSE;

	pADemodKernel->Lock(pADemodKernel);

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

	ADEMOD_INFO("drvif_ifd_get_cr_lock()-->%x\n", * pLock);
	pADemodKernel->Unlock(pADemodKernel);
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
int REALTEK_ATV_GetCarrierOffset(ADEMOD* pADemodKernel, long *pOffset)
{
	int ret = 0;
	REALTEK_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);

	pADemodKernel->Lock(pADemodKernel);
	*pOffset = drv_ifd_get_cr_offset_100hz() * 100;
	if (pRealtekAtv->m_scan_step == 1) {
		//ADEMOD_INFO("SHIFT at -1MHz\n");
		*pOffset = *pOffset - 1000000;
	} else if (pRealtekAtv->m_scan_step == 2) {
		//ADEMOD_INFO("SHIFT at +1MHz\n");
		*pOffset = *pOffset + 1000000;
	} else if (pRealtekAtv->m_scan_step == 3) {
		//ADEMOD_INFO("SHIFT at -1.5MHz\n");
		*pOffset = *pOffset - 1500000;
	} else if (pRealtekAtv->m_scan_step == 4) {
		//ADEMOD_INFO("SHIFT at +1.5MHz\n");
		*pOffset = *pOffset + 1500000;
	} else {
		;//ADEMOD_INFO("NO SHIFT\n");
	}
	//ADEMOD_INFO("GetCarrierOffset= %dHz\n", * pOffset);
	ADEMOD_INFO("GetCarrierOffset= %dHz\n", * pOffset);
	pADemodKernel->Unlock(pADemodKernel);

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
int REALTEK_ATV_GetSignalInfo(ADEMOD* pADemodKernel, TV_SIG_INFO *pInfo)
{
	REALTEK_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);
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
int REALTEK_ATV_GetSignalQuality(ADEMOD* pADemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL *pQuality)
{
	REALTEK_ATV* pRealtekAtv;
	UINT16 noise_status_data;
	unsigned long agc_data;

	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);

	pADemodKernel->Lock(pADemodKernel);

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
		pADemodKernel->Unlock(pADemodKernel);
		return  TUNER_CTRL_FAIL;
	}

	pADemodKernel->Unlock(pADemodKernel);
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
int REALTEK_ATV_AcquireSignal(ADEMOD* pADemodKernel, 	unsigned char WaitSignalLock)
{
	unsigned long   stime, stime_start, stime_end;
	unsigned char   lock = 0;
	unsigned long   shift_nco_backup, if_freq_backup;
	REALTEK_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);

	drv_ifd_soft_reset(IFD_ENABLE);
	drv_ifd_soft_reset(IFD_DISABLE);

	if (!WaitSignalLock) {

		return TUNER_CTRL_OK;
	}

	pADemodKernel->Lock(pADemodKernel);
	stime = tv_osal_time();
	stime_start = stime;

	if (0) { //(pRealtekAtv->m_scan_aft_en == 1) {
		shift_nco_backup = drv_ifd_cr_shift_nco_getinfo();
		if_freq_backup = drv_ifd_if_frequency_getinfo();
		pRealtekAtv->m_scan_step = 0;
		//detect IF at 0MHZ
		while ((tv_osal_time() - stime) <= 40) {
			tv_osal_msleep(1);
			pADemodKernel->GetLockStatus(pADemodKernel, &lock);
			ADEMOD_INFO("signal lock = %d, time=%d\n", lock, tv_osal_time() - stime);
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
			pADemodKernel->GetLockStatus(pADemodKernel, &lock);
			ADEMOD_INFO("signal lock = %d, time=%d\n", lock, tv_osal_time() - stime);
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
			pADemodKernel->GetLockStatus(pADemodKernel, &lock);
			ADEMOD_INFO("signal lock = %d, time=%d\n", lock, tv_osal_time() - stime);
			if (lock)
				break;
		}
#if 0
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
			pADemodKernel->GetLockStatus(pADemodKernel, &lock);
			ADEMOD_INFO("signal lock = %d, time=%d\n", lock, tv_osal_time() - stime);
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
			pADemodKernel->GetLockStatus(pADemodKernel, &lock);
			ADEMOD_INFO("signal lock = %d, time=%d\n", lock, tv_osal_time() - stime);
			if (lock)
				break;
		}
#endif

atv_detect_end:
		stime_end = tv_osal_time();
		ADEMOD_INFO("[Final]signal lock = %d, time=%d\n", lock, stime_end - stime_start);
		//retore NCO setting
		//drv_ifd_cr_shift_nco(shift_nco_backup);
		//if (lock==0) pRealtekAtv->m_scan_step =0;//clear
	} else {


		drv_ifd_set_power_diff_cr_lock(1);
		tv_osal_msleep(5);
		while ((tv_osal_time() - stime) <= 50) {
			lock = drvif_ifd_scan_mode_detect_cr_lock();
			if (lock == 1) break;
			tv_osal_msleep(1);
		}
		ADEMOD_INFO("signal lock = %d, time=%d\n", lock, tv_osal_time() - stime);
		drv_ifd_set_power_diff_cr_lock(0);

	}


	pADemodKernel->Unlock(pADemodKernel);
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
int REALTEK_ATV_Suspend(ADEMOD* pADemodKernel)
{
	REALTEK_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);

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
int REALTEK_ATV_Resume(ADEMOD* pADemodKernel)
{
	REALTEK_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);

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
int REALTEK_ATV_InspectSignal(ADEMOD* pADemodKernel,	char *pBuff, unsigned long BufferSize)
{
#if 0
	bool agc_lock, cr_lock;
	INT32 cr_offset;
	unsigned long agc_data;
	REALTEK_ATV* pRealtekAtv;
	pRealtekAtv = (REALTEK_ATV*)(pADemodKernel->private_data);


	pADemodKernel->Lock(pADemodKernel);
	agc_lock = drvif_ifd_get_agc_lock();
	cr_lock =	drv_ifd_get_cr_lock_status();
	cr_offset = drv_ifd_get_cr_offset_100hz() / 10;
	agc_data = (drv_ifd_agc_get_if_output() * 100) / 8192;

	ADEMOD_INFO("[RTD2945_ATV] AGC lock=%d, CR lock=%d, cr_offset=%d KHz, IF_agc=%d\n", agc_lock, cr_lock, cr_offset, agc_data);
	pADemodKernel->Unlock(pADemodKernel);
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

