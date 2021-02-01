#include <linux/kconfig.h>
#include <linux/compiler.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/stat.h>			/* permission */
#include <linux/fs.h>			/* fs, ioctl */
#include <linux/errno.h>		/* error codes */
#include <linux/types.h>		/* size_t */
#include <linux/fcntl.h>		/* O_ACCMODE */
#include <asm/uaccess.h>		/* copy_*_user */
#include <linux/mutex.h>		/* mutex */
#include <linux/device.h>		/* device */
#include <linux/cdev.h>			/* char device */

#include "audio_hw_port.h"
#include "audio_hw_atv.h"
#include "audio_hw_aio.h"
#include "audio_hw_app.h"
#include "audio_hw_driver.h"
#include "audio_hw_ioctl.h"

#define __ALOG_SUBTAG "ioctl"

#define data_from_user(d, arg) do { \
	if (copy_from_user((void *)&d, arg, sizeof(d))) { \
		alog_err("copy_from_user() failed\n"); \
		return -EFAULT; \
	} \
} while(0)

#define data_to_user(d, arg) do { \
	if (copy_to_user(arg, (void *)&d, sizeof(d))) { \
		alog_err("copy_to_user() failed\n"); \
		return -EFAULT; \
	} \
} while(0)

static long atv_enable_auto_change_std_flag(void __user *arg)
{
	int d;

	data_from_user(d, arg);
	Audio_AtvEnableAutoChangeStdFlag(d);
	return 0;
}

static long atv_auto_change_to_mono(void __user *arg)
{
	int d;

	data_from_user(d, arg);
	Audio_AtvAutoChange2Mono(d);
	return 0;
}

static long atv_set_sound_std(void __user *arg)
{
	ATV_SET_SOUND_STD_T d;

	data_from_user(d, arg);
	if (Audio_AtvSetSoundStd(d.main_system, d.sound_std))
		return -ENOTTY;
	return 0;
}

static long atv_set_play_channel(void __user *arg)
{
	ATV_SET_PLAY_CHANNEL_T d;

	data_from_user(d, arg);
	if (Audio_AtvSetPlayChannel(d.l_sel, d.r_sel))
		return -ENOTTY;
	return 0;
}

static long atv_set_sound_select(void __user *arg)
{
	ATV_SOUND_SEL d;

	data_from_user(d, arg);
	if (Audio_AtvSetSoundSelect(d))
		return -ENOTTY;
	return 0;
}

static long atv_set_mts_priority(void __user *arg)
{
	ATV_MTS_PRIORITY d;

	data_from_user(d, arg);
	if (Audio_AtvSetMtsPriority(d))
		return -ENOTTY;
	return 0;
}

static long atv_get_sound_std(void __user *arg)
{
	ATV_SOUND_INFO d;

	data_from_user(d, arg);
	if (Audio_AtvGetSoundStd(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long atv_scan_sound_std(void __user *arg)
{
	ATV_SCAN_SOUND_STD_T d;

	data_from_user(d, arg);
	if (Audio_AtvScanSoundStd(&d.sound_std, d.flag))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long atv_scan_sound_std_fmradio(void __user *arg)
{
	ATV_SCAN_SOUND_STD_FMRADIO_T d;

	data_from_user(d, arg);
	if (Audio_AtvScanSoundStd_FMRadio(&d.sound_std, &d.carrier_info))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long atv_set_area(void __user *arg)
{
	ATV_FIELD_AREA d;

	data_from_user(d, arg);
	Audio_AtvSetArea(d);
	return 0;
}

static long atv_set_data_src(void __user *arg)
{
	ATV_DATA_SRC d;

	data_from_user(d, arg);
	Audio_AtvSetDataSrc(d);
	return 0;
}

static long atv_get_mn_status(void __user *arg)
{
	ATV_GET_MN_STATUS_T d;

	data_from_user(d, arg);
	if (Audio_AtvGetMNStatus(&d.status, &d.energy))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long atv_hwp_add_sif_init(void __user *arg)
{
	ATV_CFG d;

	data_from_user(d, arg);
	if (Audio_HwpAADSIFInit(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long atv_hwp_cur_sif_type(void __user *arg)
{
	ATV_AUDIO_SIF_TYPE_T d;

	data_from_user(d, arg);
	Audio_HwpCurSifType(d);
	return 0;
}

static long atv_set_deviation_method(void __user *arg)
{
	ATV_DEV_METHOD d;

	data_from_user(d, arg);
	Audio_AtvSetDeviationMethod(d);
	return 0;
}

static long atv_enable_auto_change_sound_mode_flag(void __user *arg)
{
	int d;

	data_from_user(d, arg);
	Audio_AtvEnableAutoChangeSoundModeFlag(d);
	return 0;
}

static long atv_init(void __user *arg)
{
	ATV_CFG d;

	data_from_user(d, arg);
	if (Audio_AtvInit(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long atv_hwp_aad_sif_finalize(void)
{
	if (Audio_HwpAADSIFFinalize())
		return -ENOTTY;

	return 0;
}

static long atv_enter_atv_source(void)
{
	Audio_AtvEnterAtvSource();
	return 0;
}

static long atv_clean_atv_source_data(void)
{
	Audio_AtvCleanTVSourceData();
	return 0;
}

static long atv_hwp_sif_enable_mute_pb(void __user *arg)
{
	bool d;

	data_from_user(d, arg);
	Audio_HwpSIFEnableMutePB(d);
	return 0;
}

static long atv_hwp_sif_enable_mute_ts(void __user *arg)
{
	bool d;

	data_from_user(d, arg);
	Audio_HwpSIFEnableMuteTS(d);
	return 0;
}

static long atv_get_current_detect_update(void __user *arg)
{
	int d;

	data_from_user(d, arg);
	if (Audio_AtvGetCurrentDetectUpdate(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long atv_set_audio_in_handle(void __user *arg)
{
	long d;

	data_from_user(d, arg);
	Audio_AtvSetAudioInHandle(d);
	return 0;
}

static long atv_set_sub_audio_in_handle(void __user *arg)
{
	long d;

	data_from_user(d, arg);
	Audio_AtvSetSubAudioInHandle(d);
	return 0;
}

static long atv_hwp_set_decoder_input_mute(void __user *arg)
{
	bool d;

	data_from_user(d, arg);
	Audio_HwpSetDecoderInputMute(d);
	return 0;
}

static long atv_hwp_set_sif_data_source(void __user *arg)
{
	SIF_INPUT_SOURCE d;

	data_from_user(d, arg);
	Audio_HwpSetSIFDataSource(d);
	return 0;
}

static long atv_set_dev_on_off(void __user *arg)
{
	bool d;

	data_from_user(d, arg);
	Audio_AtvSetDevOnOff(d);
	return 0;
}

static long atv_set_dev_bandwidth(void __user *arg)
{
	ATV_SET_DEV_BANDWIDTH_T d;

	data_from_user(d, arg);
	Audio_AtvSetDevBandWidth(d.bw_sel, d.sub_bw_sel);
	return 0;
}

static long atv_set_fm_out_down_gain(void __user *arg)
{
	int d;

	data_from_user(d, arg);
	Audio_AtvSetFMoutDownGain(d);
	return 0;
}

static long atv_hwp_set_channel_change(void)
{
	Audio_HwpSetChannelChange();
	return 0;
}

static long atv_hwp_set_band_delay(void)
{
	Audio_HwpSetBandDelay();
	return 0;
}

static long atv_hwp_set_atv_audio_band(void __user *arg)
{
	ATV_HWP_SET_ATV_AUDIO_BAND_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetAtvAudioBand(d.sif_source, d.atv_main_system))
		return -ENOTTY;
	return 0;
}

static long atv_hwp_sif_get_main_tone_snr(void __user *arg)
{
	ATV_HWP_SIF_GET_MAIN_TONE_SNR_T d;

	data_from_user(d, arg);

	if (Audio_HwpSIFGetMainToneSNR(d.main_sys, &d.hw_detected_main_sys, &d.hw_detected_sound_std, &d.pToneSNR))
		return -ENOTTY;
	
	data_to_user(d, arg);
	return 0;
}

static long atv_hwp_sif_check_nicam_digital(void __user *arg)
{
	int d;

	data_from_user(d, arg);
	Audio_HwpSIFCheckNicamDigital(&d);
	data_to_user(d, arg);
	return 0;
}

static long atv_hwp_sif_detected_sound_standard(void __user *arg)
{
	ATV_SOUND_STD d;

	data_from_user(d, arg);
	Audio_HwpSIFDetectedSoundStandard(&d);
	data_to_user(d, arg);
	return 0;
}

static long atv_set_a2_sound_select(void __user *arg)
{
	ATV_SET_A2_SOUND_SELECT_T d;

	data_from_user(d, arg);
	Audio_AtvSetA2SoundSelect(d.play_stereo, d.dual_lang_index);
	return 0;
}

static long atv_set_nicom_sound_select(void __user *arg)
{
	ATV_SET_NICAM_SOUND_SELECT_T d;

	data_from_user(d, arg);
	Audio_AtvSetNICAMSoundSelect(d.nicam_digital, d.dual_lang_index);
	return 0;
}

static long atv_set_btsc_sound_select(void __user *arg)
{
	ATV_SET_BTSC_SOUND_SELECT_T d;

	data_from_user(d, arg);
	Audio_AtvSetBTSCSoundSelect(d.play_stereo, d.play_sap);
	return 0;
}

static long atv_force_sound_sel(void __user *arg)
{
	bool d;

	data_from_user(d, arg);
	Audio_AtvForceSoundSel(d);
	return 0;
}

static long atv_hwp_sif_set_a2_stereo_dual_th(void __user *arg)
{
	uint32_t d;

	data_from_user(d, arg);
	Audio_HwpSIFSetA2StereoDualTH(d);
	return 0;
}

static long atv_hwp_sif_set_nicam_th(void __user *arg)
{
	ATV_HWP_SIF_SET_NICAM_TH_T d;

	data_from_user(d, arg);
	Audio_HwpSIFSetNicamTH(d.hi_th, d.lo_th);
	return 0;
}

static long atv_hwp_sif_get_a2_stereo_dual_th(void __user *arg)
{
	uint32_t d;

	data_from_user(d, arg);
	Audio_HwpSIFGetA2StereoDualTH(&d);
	data_to_user(d, arg);
	return 0;
}

static long atv_hwp_sif_get_nicam_th(void __user *arg)
{
	ATV_HWP_SIF_GET_NICAM_TH_T d;

	data_from_user(d, arg);
	Audio_HwpSIFGetNicamTH(&d.hi_th, &d.lo_th);
	data_to_user(d, arg);
	return 0;
}

static long atv_pause_tv_std_detection(void __user *arg)
{
	bool d;

	data_from_user(d, arg);
	Audio_AtvPauseTVStdDetection(d);
	return 0;
}

static long atv_get_nicam_signal_stable(void __user *arg)
{
	int d;

	d = Audio_AtvGetNicamSignalStable();
	data_to_user(d, arg);
	return 0;
}

static long atv_hwp_sif_get_source(void __user *arg)
{
	SIF_INPUT_SOURCE d;

	data_from_user(d, arg);
	Audio_HwpSIFGetSource(&d);
	data_to_user(d, arg);
	return 0;
}

static long atv_hwp_sif_get_dev_bandwidth(void __user *arg)
{
	A2_BW_SEL_T d;

	data_from_user(d, arg);
	Audio_HwpSIFGetDevBandwidth(&d);
	data_to_user(d, arg);
	return 0;
}

static long atv_hwp_sif_get_band_setup(void __user *arg)
{
	uint32_t d;

	data_from_user(d, arg);
	Audio_HwpSIFGetBandSetup(&d);
	data_to_user(d, arg);
	return 0;
}

static long atv_hwp_sif_get_mode_setup(void __user *arg)
{
	ATV_SOUND_STD d;

	data_from_user(d, arg);
	Audio_HwpSIFGetModeSetup(&d);
	data_to_user(d, arg);
	return 0;
}

static long atv_enter_set_channel(void)
{
	Audio_AtvEnterSetChannel();
	return 0;
}

static long atv_finish_set_channel(void)
{
	Audio_AtvFinishSetChannel();
	return 0;
}

static long atv_get_mode_mute(void __user *arg)
{
	int d;

	d = Audio_AtvGetModeMute();
	data_to_user(d, arg);
	return 0;
}

static long atv_set_internal_decoder_0_fail(void __user *arg)
{
	int d;

	data_from_user(d, arg);

	if (Audio_AtvSetInternalDecoder0Fail(d))
		return -ENOTTY;
	return 0;
}

static long atv_set_internal_decoder_1_fail(void __user *arg)
{
	int d;

	data_from_user(d, arg);

	if (Audio_AtvSetInternalDecoder1Fail(d))
		return -ENOTTY;
	return 0;
}

static long atv_start_decoding(void)
{
	Audio_AtvStartDecoding();
	return 0;
}

static long atv_stop_decoding(void)
{
	Audio_AtvStopDecoding();
	return 0;
}

static long atv_reg_mute_callback(void __user *arg)
{
	ATV_REG_MUTE_CALLBACK_T d;

	data_from_user(d, arg);
	Audio_AtvRegMuteCallback(d.decindex, d.pfnCallBack);
	return 0;
}

static long atv_set_audio_hw_config(void __user *arg)
{
	int d;

	data_from_user(d, arg);
	Audio_SetAudioHWConfig(d);
	return 0;
}

static long atv_change_tv_deviation_config(void __user *arg)
{
	uint32_t d;

	data_from_user(d, arg);
	Audio_AtvChangeTvDeviationConfig(d);
	return 0;
}

static long atv_config_no_signal_need_to_mute(void __user *arg)
{
	uint32_t d;

	data_from_user(d, arg);
	Audio_AtvConfigNoSignalNeed2Mute(d);
	return 0;
}

static long atv_enter_auto_scan(void __user *arg)
{
	Audio_AtvEnterAutoScan();
	return 0;
}

static long atv_exit_auto_scan(void __user *arg)
{
	Audio_AtvExitAutoScan();
	return 0;
}

static long atv_force_first_time_mono_sound_flag(void __user *arg)
{
	int d;

	data_from_user(d, arg);
	Audio_AtvForceFirstTimeMonoSoundFlag(d);
	return 0;
}

static long atv_force_not_mute(void __user *arg)
{
	ATVFORCENOTMUTE_PB_TS d;

	data_from_user(d, arg);
	Audio_AtvForceNotmute(d);
	return 0;
}

static long atv_get_a2_sound_select(void __user *arg)
{
	ATV_A2_SEL d;

	data_from_user(d, arg);

	if (Audio_AtvGetA2SoundSelect(&d))
		return -ENOTTY;

	data_to_user(d, arg);	
	return 0;
}

static long atv_get_nicam_sound_select(void __user *arg)
{
	ATV_NICAM_SEL d;

	data_from_user(d, arg);

	if (Audio_AtvGetNicamSoundSelect(&d))
		return -ENOTTY;

	data_to_user(d, arg);	
	return 0;
}


static long atv_get_btsc_mts_select(void __user *arg)
{
	uint32_t d;

	data_from_user(d, arg);

	if (Audio_AtvGetBtscMtsSelect(&d))
		return -ENOTTY;

	data_to_user(d, arg);	
	return 0;
}

static long atv_get_sound_system(void __user *arg)
{
	ATV_SOUND_STD_MAIN_SYSTEM d;

	d = Audio_AtvGetSoundSystem();

	data_to_user(d, arg);	
	return 0;
}

static long atv_is_tv_ready(void __user *arg)
{
	uint32_t d;

	d = Audio_AtvIsTvReady();

	data_to_user(d, arg);	
	return 0;
}

static long atv_nicam_auto_recovery_flag(void __user *arg)
{
	int  d;

	data_from_user(d, arg);
	Audio_AtvNicamAutoRecoveryFlag(d);
	return 0;
}

static long atv_set_sound_system(void __user *arg)
{
	DRV_ATV_SOUND_SYSTEM d;

	data_from_user(d, arg);
	Audio_AtvSetSoundSystem(d);
	return 0;
}

static long atv_start_to_normal_process(void __user *arg)
{
	Audio_AtvStart2NormalProcess();
	return 0;
}

static long atv_status_change_callback_fn_config(void __user *arg)
{
	FP_AUDIOSTATUSCHANGE d;

	data_from_user(d, arg);
	Audio_AtvStatusChageCallBackfnConfig(d);
	return 0;
}

static long atv_set_audio_bp(void __user *arg)
{
	ATV_AUDIO_BP_SEL d;

	data_from_user(d, arg);
	audio_ifd_set_audio_bp(d);
	return 0;
}

static long atv_ioctl_Audio_Hw_SetFmRadioMode(void __user *arg)
{
	AUDIO_ATV_FM_RADIO_MODE d;

	data_from_user(d, arg);
	Audio_Hw_SetFmRadioMode(d);
	return 0;
}

static long atv_auto_verify_set_path(void __user *arg)
{
	Audio_Auto_Verify_Set_Path();
	return 0;
}

static long atv_set_scan_std_flag(void __user *arg)
{
	bool d;

	data_from_user(d, arg);
	Audio_Hw_Set_Scan_Std_Flag(d);
	return 0;
}

static long atv_ioctl_Audio_Hw_SetStdFwPriority(void __user *arg)
{
	uint16_t d;

	data_from_user(d, arg);
	Audio_AtvSetFwPriority(d);
	return 0;
}

static long audio_hw_atv_ioctl_handler(unsigned int cmd, void __user *arg)
{
	long ret = 0;

	if (_IOC_NR(cmd) >= AUDIO_IOC_ATV_MAXNR) {
		alog_err("cmd nr overflow\n");
		return -ENOIOCTLCMD;
	}

	switch (cmd) {
	case AUDIO_IOC_ATV_ENABLE_AUTO_CHANGE_STD_FLAG:
		ret = atv_enable_auto_change_std_flag(arg);
		break;
	case AUDIO_IOC_ATV_AUTO_CHANGE_TO_MONO:
		ret = atv_auto_change_to_mono(arg);
		break;
	case AUDIO_IOC_ATV_SET_SOUND_STD:
		ret = atv_set_sound_std(arg);
		break;
	case AUDIO_IOC_ATV_SET_PLAY_CHANNEL:
		ret = atv_set_play_channel(arg);
		break;
	case AUDIO_IOC_ATV_SET_SOUND_SELECT:
		ret = atv_set_sound_select(arg);
		break;
	case AUDIO_IOC_ATV_SET_MTS_PRIORITY:
		ret = atv_set_mts_priority(arg);
		break;
	case AUDIO_IOC_ATV_GET_SOUND_STD:
		ret = atv_get_sound_std(arg);
		break;
	case AUDIO_IOC_ATV_SCAN_SOUND_STD:
		ret = atv_scan_sound_std(arg);
		break;
	case AUDIO_IOC_ATV_SCAN_SOUND_STD_FMRADIO:
		ret = atv_scan_sound_std_fmradio(arg);
		break;
	case AUDIO_IOC_ATV_SET_AREA:
		ret = atv_set_area(arg);
		break;
	case AUDIO_IOC_ATV_SET_DATA_SRC:
		ret = atv_set_data_src(arg);
		break;
	case AUDIO_IOC_ATV_GET_MN_STATUS:
		ret = atv_get_mn_status(arg);
		break;
	case AUDIO_IOC_ATV_HWP_AAD_SIF_INIT:
		ret = atv_hwp_add_sif_init(arg);
		break;
	case AUDIO_IOC_ATV_HWP_CUR_SIF_TYPE:
		ret = atv_hwp_cur_sif_type(arg);
		break;
	case AUDIO_IOC_ATV_SET_DEVIATION_METHOD:
		ret = atv_set_deviation_method(arg);
		break;
	case AUDIO_IOC_ATV_ENABLE_AUTO_CHANGE_SOUND_MODE_FLAG:
		ret = atv_enable_auto_change_sound_mode_flag(arg);
		break;
	case AUDIO_IOC_ATV_INIT:
		ret = atv_init(arg);
		break;
	case AUDIO_IOC_ATV_HWP_AAD_SIF_FINALIZE:
		ret = atv_hwp_aad_sif_finalize();
		break;
	case AUDIO_IOC_ATV_ENTER_ATV_SOURCE:
		ret = atv_enter_atv_source();
		break;
	case AUDIO_IOC_ATV_CLEAN_TV_SOURCE_DATA:
		ret = atv_clean_atv_source_data();
		break;
	case AUDIO_IOC_ATV_HWP_SIF_ENABLE_MUTE_PB:
		ret = atv_hwp_sif_enable_mute_pb(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SIF_ENABLE_MUTE_TS:
		ret = atv_hwp_sif_enable_mute_ts(arg);
		break;
	case AUDIO_IOC_ATV_GET_CURRENT_DETECT_UPDATE:
		ret = atv_get_current_detect_update(arg);
		break;
	case AUDIO_IOC_ATV_SET_AUDIO_IN_HANDLE:
		ret = atv_set_audio_in_handle(arg);
		break;
	case AUDIO_IOC_ATV_SET_SUB_AUDIO_IN_HANDLE:
		ret = atv_set_sub_audio_in_handle(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SET_DECODER_INPUT_MUTE:
		ret = atv_hwp_set_decoder_input_mute(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SET_SIF_DATA_SOURCE:
		ret = atv_hwp_set_sif_data_source(arg);
		break;
	case AUDIO_IOC_ATV_SET_DEV_ON_OFF:
		ret = atv_set_dev_on_off(arg);
		break;
	case AUDIO_IOC_ATV_SET_DEV_BANDWIDTH:
		ret = atv_set_dev_bandwidth(arg);
		break;
	case AUDIO_IOC_ATV_SET_FM_OUT_DOWN_GAIN:
		ret = atv_set_fm_out_down_gain(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SET_CHANNEL_CHANGE:
		ret = atv_hwp_set_channel_change();
		break;
	case AUDIO_IOC_ATV_HWP_SET_BAND_DELAY:
		ret = atv_hwp_set_band_delay();
		break;
	case AUDIO_IOC_ATV_HWP_SET_ATV_AUDIO_BAND:
		ret = atv_hwp_set_atv_audio_band(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SIF_GET_MAIN_TONE_SNR:
		ret = atv_hwp_sif_get_main_tone_snr(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SIF_CHECK_NICAM_DIGITAL:
		ret = atv_hwp_sif_check_nicam_digital(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SIF_DETECTED_SOUND_STANDARD:
		ret = atv_hwp_sif_detected_sound_standard(arg);
		break;
	case AUDIO_IOC_ATV_SET_A2_SOUND_SELECT:
		ret = atv_set_a2_sound_select(arg);
		break;
	case AUDIO_IOC_ATV_SET_NICAM_SOUND_SELECT:
		ret = atv_set_nicom_sound_select(arg);
		break;
	case AUDIO_IOC_ATV_SET_BTSC_SOUND_SELECT:
		ret = atv_set_btsc_sound_select(arg);
		break;
	case AUDIO_IOC_ATV_FORCE_SOUND_SEL:
		ret = atv_force_sound_sel(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SIF_SET_A2_STEREO_DUAL_TH:
		ret = atv_hwp_sif_set_a2_stereo_dual_th(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SIF_SET_NICAM_TH:
		ret = atv_hwp_sif_set_nicam_th(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SIF_GET_A2_STEREO_DUAL_TH:
		ret = atv_hwp_sif_get_a2_stereo_dual_th(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SIF_GET_NICAM_TH:
		ret = atv_hwp_sif_get_nicam_th(arg);
		break;
	case AUDIO_IOC_ATV_PAUSE_TV_STD_DETECTION:
		ret = atv_pause_tv_std_detection(arg);
		break;
	case AUDIO_IOC_ATV_GET_NICAM_SIGNAL_STABLE:
		ret = atv_get_nicam_signal_stable(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SIF_GET_SOURCE:
		ret = atv_hwp_sif_get_source(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SIF_GET_DEV_BANDWIDTH:
		ret = atv_hwp_sif_get_dev_bandwidth(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SIF_GET_BAND_SETUP:
		ret = atv_hwp_sif_get_band_setup(arg);
		break;
	case AUDIO_IOC_ATV_HWP_SIF_GET_MODE_SETUP:
		ret = atv_hwp_sif_get_mode_setup(arg);
		break;
	case AUDIO_IOC_ATV_ENTER_SET_CHANNEL:
		ret = atv_enter_set_channel();
		break;
	case AUDIO_IOC_ATV_FINISH_SET_CHANNEL:
		ret = atv_finish_set_channel();
		break;
	case AUDIO_IOC_ATV_GET_MODE_MUTE:
		ret = atv_get_mode_mute(arg);
		break;
	case AUDIO_IOC_ATV_SET_INTERNAL_DECODER_0_FAIL:
		ret = atv_set_internal_decoder_0_fail(arg);
		break;
	case AUDIO_IOC_ATV_SET_INTERNAL_DECODER_1_FAIL:
		ret = atv_set_internal_decoder_1_fail(arg);
		break;
	case AUDIO_IOC_ATV_START_DECODING:
		ret = atv_start_decoding();
		break;
	case AUDIO_IOC_ATV_STOP_DECODING:
		ret = atv_stop_decoding();
		break;
	case AUDIO_IOC_ATV_REG_MUTE_CALLBACK:
		ret = atv_reg_mute_callback(arg);
		break;
	case AUDIO_IOC_ATV_SET_AUDIO_HW_CONFIG:
		ret = atv_set_audio_hw_config(arg);
	case AUDIO_IOC_ATV_CHANGE_TV_DEVIATION_CONFIG:
		ret = atv_change_tv_deviation_config(arg);
		break;
	case AUDIO_IOC_ATV_CONFIG_NO_SIGNAL_NEED_TO_MUTE:
		ret = atv_config_no_signal_need_to_mute(arg);
		break;
	case AUDIO_IOC_ATV_ENTER_AUTO_SCAN:
		ret = atv_enter_auto_scan(arg);
		break;
	case AUDIO_IOC_ATV_EXIT_AUTO_SCAN:
		ret = atv_exit_auto_scan(arg);
		break;
	case AUDIO_IOC_ATV_FORCE_FIRST_TIME_MONO_SOUND_FLAG:
		ret = atv_force_first_time_mono_sound_flag(arg);
		break;
	case AUDIO_IOC_ATV_FORCE_NOT_MUTE:
		ret = atv_force_not_mute(arg);
		break;
	case AUDIO_IOC_ATV_GET_A2_SOUND_SELECT:
		ret = atv_get_a2_sound_select(arg);
		break;
	case AUDIO_IOC_ATV_GET_NICAM_SOUND_SELECT:
		ret = atv_get_nicam_sound_select(arg);
		break;
	case AUDIO_IOC_ATV_GET_BTSC_MTS_SELECT:
		ret = atv_get_btsc_mts_select(arg);
		break;
	case AUDIO_IOC_ATV_GET_SOUND_SYSTEM:
		ret = atv_get_sound_system(arg);
		break;
	case AUDIO_IOC_ATV_IS_TV_READY:
		ret = atv_is_tv_ready(arg);
		break;
	case AUDIO_IOC_ATV_NICAM_AUTO_RECOVERY_FLAG:
		ret = atv_nicam_auto_recovery_flag(arg);
		break;
	case AUDIO_IOC_ATV_SET_SOUND_SYSTEM:
		ret = atv_set_sound_system(arg);
		break;
	case AUDIO_IOC_ATV_START_TO_NORMAL_PROCESS:
		ret = atv_start_to_normal_process(arg);
		break;
	case AUDIO_IOC_ATV_STATUS_CHANGE_CALLBACK_FN_CONFIG:
		ret = atv_status_change_callback_fn_config(arg);
		break;
	case AUDIO_IOC_ATV_SET_AUDIO_BP:
		ret = atv_set_audio_bp(arg);
		break;
	case AUDIO_IOC_ATV_SET_FM_RADIO_MODE:
		ret = atv_ioctl_Audio_Hw_SetFmRadioMode(arg);
		break;
	case AUDIO_IOC_ATV_VERIFY_SET_PATH:
		ret = atv_auto_verify_set_path(arg);
		break;
	case AUDIO_IOC_ATV_SET_SCAN_STD_FLAG:
		atv_set_scan_std_flag(arg);
		break;
	case AUDIO_IOC_ATV_SET_STD_FW_PRIORITY:
		ret = atv_ioctl_Audio_Hw_SetStdFwPriority(arg);
		break;
	default:
		ret = -ENOIOCTLCMD;
		break;
	}

	return ret;
}

static long app_hwp_set_mute(void __user *arg)
{
	APP_HWP_SET_MUTE_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetMute(d.para, d.ch_id, d.mute_id))
		return -ENOTTY;
	return 0;
}

static long app_hwp_set_mute_ts(void __user *arg)
{
	APP_HWP_SET_MUTE_TS_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetMuteTS(d.para, d.ch_id, d.mute_id))
		return -ENOTTY;
	return 0;
}

static long app_hwp_set_volume(void __user *arg)
{
	APP_HWP_SET_VOLUME_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetVolume(d.ch_id, d.vol))
		return -ENOTTY;
	return 0;
}

static long app_hwp_set_volume_ts(void __user *arg)
{
	APP_HWP_SET_VOLUME_TS_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetVolumeTS(d.ch_id, d.vol))
		return -ENOTTY;
	return 0;
}

static long app_hwp_set_balance_lr(void __user *arg)
{
	int32_t d;

	data_from_user(d, arg);
	if (Audio_HwpSetBalance(d, APP_BALANCE_CH_ID_CH01))
		return -ENOTTY;
	return 0;
}

static long app_hwp_set_balance_ts(void __user *arg)
{
	int32_t d;

	data_from_user(d, arg);
	if (Audio_HwpSetBalanceTS(d))
		return -ENOTTY;
	return 0;
}

static long app_hwp_set_avc(void __user *arg)
{
	APP_HWP_APP_HWP_SET_AVC_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetAVC(d.para, &d.p_cfg_avc))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_avc2(void __user *arg)
{
	APP_HWP_APP_HWP_SET_AVC2_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetAVC2(d.para, &d.p_cfg_avc2))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_prescale(void __user *arg)
{
	APP_HWP_PRESCALE_T d;

	data_from_user(d, arg);
	Audio_HwpPrescale(d.vol, d.ch_id);
	return 0;
}

static long app_hwp_set_spatial_effect(void __user *arg)
{
	APP_HWP_SET_SPATIAL_EFFECT_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetSpatialEffect(d.para, &d.p_cfg_se))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_bass_value(void __user *arg)
{
	APP_HWP_SET_BASS_VALUE_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetBassValue(d.para, &d.p_val_bass))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_treble_value(void __user *arg)
{
	APP_HWP_SET_TREBLE_VALUE_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetTrebleValue(d.para, &d.p_val_treble))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_treble2_value(void __user *arg)
{
	APP_HWP_SET_TREBLE2_VALUE_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetTreble2Value(d.para, &d.p_val_treble2))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_treble2_value_48k(void __user *arg)
{
	APP_HWP_SET_TREBLE2_VALUE_48K_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetTreble2Value_48K(d.para, &d.p_val_treble2_48k))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_eq_parameter(void __user *arg)
{
	APP_HWP_SET_EQ_PARAMETER_T d;

	data_from_user(d, arg);
	if (d.band_id == APP_EQ_ALL_HPF_BAND1)
	{
		if (Audio_HwpSetEQParameter(d.band_id, d.eq_coef))
		return -ENOTTY;
	}else{
		if (Audio_HwpSetEQ_Smooth_H0(d.band_id, d.eq_coef))
		return -ENOTTY;
	}
	return 0;
}

static long app_hwp_set_loud_parameter(void __user *arg)
{
	APP_HWP_SET_LOUD_PARAMETER_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetLoud_Smooth_H0(d.band_id, d.loud_coef))
		return -ENOTTY;
	return 0;
}

static long app_hwp_write_eq_control_enable(void __user *arg)
{
	APP_HWP_WRITE_EQ_CTRL_EN_T d;

	data_from_user(d, arg);
	if (Audio_HwpWriteEQControlEnable(d.band_id, &d.enable))
		return -ENOTTY;
	return 0;
}

static long app_hwp_write_loud_control_enable(void __user *arg)
{
	APP_HWP_WRITE_LOUD_CTRL_EN_T d;

	data_from_user(d, arg);
	if (Audio_HwpWriteLoudControlEnable(d.band_id, &d.enable))
		return -ENOTTY;
	return 0;
}

static long app_hwp_read_eq_control_enable(void __user *arg)
{
	uint32_t d;

	data_from_user(d, arg);
	
	if (Audio_HwpReadEQControlEnable(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_read_loud_control_enable(void __user *arg)
{
	uint32_t d;

	data_from_user(d, arg);
	if (Audio_HwpReadLoudControlEnable(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_eq_loud_value_change_mode(void __user *arg)
{
	APP_EQ_LOUD_VALUE_CHANGE_MODE d;

	data_from_user(d, arg);
	if (Audio_HwpSetEQLoudValue_Change_Mode(d))
		return -ENOTTY;
	return 0;
}

static long app_hwp_set_dvc_value_change_mode(void __user *arg)
{
	APP_DVC_VALUE_CHANGE_MODE d;

	data_from_user(d, arg);
	if (Audio_HwpSetDVCValue_Change_Mode(d))
		return -ENOTTY;
	return 0;
}

static long app_factory_disable_hw_pp(void __user *arg)
{
	Audio_FactoryDisableHwPp();
	return 0;
}

static long app_factory_enable_hw_pp(void __user *arg)
{
	Audio_FactoryEnableHwPp();
	return 0;
}

static long app_hwp_set_bass_coef(void __user *arg)
{
	static APP_BASS_CFG  d; //Maximum size of kernel stack is 4k bytes.(e.g. APP_EQ_CFG is 13k bytes)
							//If return structure is larger than 4k, it has stack overflow risk and making system crash.
							//Solution: using static value to replace stack.
							//(The safer way is malloc a memory block to pass EQ table from user.)

	data_from_user(d, arg);
	if (Audio_HwpSetBassCoef(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_bass_coef_48k(void __user *arg)
{
	static APP_BASS_48K_CFG  d; //Maximum size of kernel stack is 4k bytes.(e.g. APP_EQ_CFG is 13k bytes)
							//If return structure is larger than 4k, it has stack overflow risk and making system crash.
							//Solution: using static value to replace stack.
							//(The safer way is malloc a memory block to pass EQ table from user.)

	data_from_user(d, arg);
	if (Audio_HwpSetBassCoef_48K(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}


static long app_hwp_set_bass_value_48k(void __user *arg)
{
	APP_HWP_SET_BASS_VALUE_48K_T  d;

	data_from_user(d, arg);
	if (Audio_HwpSetBassValue_48K(d.para, &d.p_val_bass_48k))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_eq_coef(void __user *arg)
{
	static APP_EQ_CFG  d; //Maximum size of kernel stack is 4k bytes.(e.g. APP_EQ_CFG is 13k bytes)
						  //If return structure is larger than 4k, it has stack overflow risk and making system crash.
						  //Solution: using static value to replace stack.
						  //(The safer way is malloc a memory block to pass EQ table from user.)

	data_from_user(d, arg);
	if (Audio_HwpSetEQCoef(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_eq_coef_48k(void __user *arg)
{
	static APP_EQ_48K_CFG  d; //Maximum size of kernel stack is 4k bytes.(e.g. APP_EQ_CFG is 13k bytes)
						  //If return structure is larger than 4k, it has stack overflow risk and making system crash.
						  //Solution: using static value to replace stack.
						  //(The safer way is malloc a memory block to pass EQ table from user.)

	data_from_user(d, arg);
	if (Audio_HwpSetEQCoef_48K(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_eq_value(void __user *arg)
{
	APP_HWP_SET_EQ_VALUE_T  d;

	data_from_user(d, arg);
	if (Audio_HwpSetEQValue(d.para, &d.p_val_eq))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_eq_value_48k(void __user *arg)
{
	APP_HWP_SET_EQ_VALUE_48K_T  d;

	data_from_user(d, arg);
	if (Audio_HwpSetEQValue_48K(d.band_enable, &d.p_val_eq_48k))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_treble_coef(void __user *arg)
{
	static APP_TREBLE_CFG   d; //Maximum size of kernel stack is 4k bytes.(e.g. APP_EQ_CFG is 13k bytes)
							   //If return structure is larger than 4k, it has stack overflow risk and making system crash.
							   //Solution: using static value to replace stack.
							   //(The safer way is malloc a memory block to pass EQ table from user.)

	data_from_user(d, arg);
	if (Audio_HwpSetTrebleCoef(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_treble_coef_48k(void __user *arg)
{
	static APP_TREBLE_48K_CFG   d; //Maximum size of kernel stack is 4k bytes.(e.g. APP_EQ_CFG is 13k bytes)
							   //If return structure is larger than 4k, it has stack overflow risk and making system crash.
							   //Solution: using static value to replace stack.
							   //(The safer way is malloc a memory block to pass EQ table from user.)

	data_from_user(d, arg);
	if (Audio_HwpSetTrebleCoef_48K(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_treble_value_48k(void __user *arg)
{
	APP_HWP_SET_TREBLE_VALUE_48K_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetTrebleValue_48K(d.para, &d.p_val_treble_48k))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_treble2_coef(void __user *arg)
{
	static APP_TREBLE_CFG   d; //Maximum size of kernel stack is 4k bytes.(e.g. APP_EQ_CFG is 13k bytes)
							   //If return structure is larger than 4k, it has stack overflow risk and making system crash.
							   //Solution: using static value to replace stack.
							   //(The safer way is malloc a memory block to pass EQ table from user.)

	data_from_user(d, arg);
	if (Audio_HwpSetTreble2Coef(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_treble2_coef_48k(void __user *arg)
{
	static APP_TREBLE_48K_CFG   d; //Maximum size of kernel stack is 4k bytes.(e.g. APP_EQ_CFG is 13k bytes)
							   //If return structure is larger than 4k, it has stack overflow risk and making system crash.
							   //Solution: using static value to replace stack.
							   //(The safer way is malloc a memory block to pass EQ table from user.)

	data_from_user(d, arg);
	if (Audio_HwpSetTreble2Coef_48K(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}


static long app_hwp_get_max_eq_band_num(void __user *arg)
{
	int32_t d;

	if (Audio_HwpGetMaxEQBandNum(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long app_hwp_set_balance_ch(void __user *arg)
{
	APP_HWP_SET_BALANCE_T d;

	data_from_user(d, arg);
	if (Audio_HwpSetBalance(d.Balance, d.Channel))
		return -ENOTTY;

	return 0;
}

static long audio_hw_app_ioctl_handler(unsigned int cmd, void __user *arg)
{
	long ret = 0;

	if (_IOC_NR(cmd) >= AUDIO_IOC_APP_MAXNR) {
		alog_err("cmd nr overflow\n");
		return -ENOIOCTLCMD;
	}

	switch (cmd) {
	case AUDIO_IOC_APP_HWP_SET_MUTE:
		ret = app_hwp_set_mute(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_MUTE_TS:
		ret = app_hwp_set_mute_ts(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_VOLUME:
		ret = app_hwp_set_volume(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_VOLUME_TS:
		ret = app_hwp_set_volume_ts(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_BALANCE_LR:
		ret = app_hwp_set_balance_lr(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_BALANCE_TS:
		ret = app_hwp_set_balance_ts(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_AVC:
		ret = app_hwp_set_avc(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_AVC2:
		ret = app_hwp_set_avc2(arg);
		break;
	case AUDIO_IOC_APP_HWP_PRESCALE:
		ret = app_hwp_prescale(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_SPATIAL_EFFECT:
		ret = app_hwp_set_spatial_effect(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_BASS_COEF:
		ret = app_hwp_set_bass_coef(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_BASS_COEF_48K:
		ret = app_hwp_set_bass_coef_48k(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_BASS_VALUE:
		ret = app_hwp_set_bass_value(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_BASS_VALUE_48K:
		ret = app_hwp_set_bass_value_48k(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_TREBLE_COEF:
		ret = app_hwp_set_treble_coef(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_TREBLE_COEF_48K:
		ret = app_hwp_set_treble_coef_48k(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_TREBLE_VALUE:
		ret = app_hwp_set_treble_value(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_TREBLE_VALUE_48K:
		ret = app_hwp_set_treble_value_48k(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_TREBLE2_COEF:
		ret = app_hwp_set_treble2_coef(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_TREBLE2_COEF_48K:
		ret = app_hwp_set_treble2_coef_48k(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_TREBLE2_VALUE:
		ret = app_hwp_set_treble2_value(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_TREBLE2_VALUE_48K:
		ret = app_hwp_set_treble2_value_48k(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_EQ_PARAMETER:
		ret = app_hwp_set_eq_parameter(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_LOUD_PARAMETER:
		ret = app_hwp_set_loud_parameter(arg);
		break;
	case AUDIO_IOC_APP_HWP_WRITE_EQ_CONTROL_ENABLE:
		ret = app_hwp_write_eq_control_enable(arg);
		break;
	case AUDIO_IOC_APP_HWP_WRITE_LOUD_CONTROL_ENABLE:
		ret = app_hwp_write_loud_control_enable(arg);
		break;
	case AUDIO_IOC_APP_HWP_READ_EQ_CONTROL_ENABLE:
		ret = app_hwp_read_eq_control_enable(arg);
		break;
	case AUDIO_IOC_APP_HWP_READ_LOUD_CONTROL_ENABLE:
		ret = app_hwp_read_loud_control_enable(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_EQ_LOUD_VALUE_CHANGE_MODE:
		ret = app_hwp_set_eq_loud_value_change_mode(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_DVC_VALUE_CHANGE_MODE:
		ret = app_hwp_set_dvc_value_change_mode(arg);
		break;
	case AUDIO_IOC_APP_FACTORY_DISABLE_HW_PP:
		ret = app_factory_disable_hw_pp(arg);
		break;
	case AUDIO_IOC_APP_FACTORY_ENABLE_HW_PP:
		ret = app_factory_enable_hw_pp(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_EQ_COEF:
		ret = app_hwp_set_eq_coef(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_EQ_COEF_48K:
		ret = app_hwp_set_eq_coef_48k(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_EQ_VALUE:
		ret = app_hwp_set_eq_value(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_EQ_VALUE_48K:
		ret = app_hwp_set_eq_value_48k(arg);
		break;
	case AUDIO_IOC_APP_HWP_GET_MAX_EQ_BAND_NUM:
		ret = app_hwp_get_max_eq_band_num(arg);
		break;
	case AUDIO_IOC_APP_HWP_SET_BALANCE:
		ret = app_hwp_set_balance_ch(arg);
		break;
	default:
		ret = -ENOIOCTLCMD;
		break;
	}

	return ret;
}

static long aio_get_path_src(void __user *arg)
{
	AIO_PATH_CFG d;

	data_from_user(d, arg);
	if (Audio_AioGetPathSrc(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long aio_init(void __user *arg)
{
	ATV_CFG d;

	data_from_user(d, arg);
	if (Audio_AioInit(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long aio_deinit(void __user *arg)
{
	if (Audio_AioDeInit())
		return -ENOTTY;
	return 0;
}

static long aio_mute_spdif(void __user *arg)
{
	bool d;

	data_from_user(d, arg);
	if (Audio_AioMute_SPDIF(d))
		return -ENOTTY;
	return 0;
}

static long aio_hw_aq_init(void __user *arg)
{
	ATV_CFG d;

	data_from_user(d, arg);
	if (Audio_HW_AQ_Init(&d))
		return -ENOTTY;

	data_to_user(d, arg);
	return 0;
}

static long aio_hw_aq_deinit(void __user *arg)
{
	if (Audio_HW_AQ_DeInit())
		return -ENOTTY;
	return 0;
}

static long aio_set_opt_src_spdif(void __user *arg)
{
	AIO_SPDIFO_SRC d;

	data_from_user(d, arg);
	if (Audio_AioSetOptSrc_SPDIF(d))
		return -ENOTTY;
	return 0;
}

static long aio_cfg_opt_src_headphone(void __user *arg)
{
	AIO_HEADPHONE_CFG d;

	data_from_user(d, arg);
	if (Audio_AioCfgOptSrc_Headphone(d))
		return -ENOTTY;
	return 0;
}

static long aio_set_mute(void __user *arg)
{
	AIO_SET_MUTE_T d;

	data_from_user(d, arg);
	if (Audio_AioSetMute(d.para, d.ch_id, d.mute_by_who))
		return -ENOTTY;
	return 0;
}

static long aio_dio_set_opt_channel_all(void __user *arg)
{
	DIO_OPT_CHANNEL d;

	data_from_user(d, arg);
	if (Audio_DIOSetOptChannel_ALL(d))
		return -ENOTTY;
	return 0;
}

static long aio_set_opt_src_i2s(void __user *arg)
{
	AIO_I2SO_SRC d;

	data_from_user(d, arg);
	if (Audio_AioSetOptSrc_I2S(d))
		return -ENOTTY;
	return 0;
}

static long audio_hw_aio_ioctl_handler(unsigned int cmd, void __user *arg)
{
	long ret = 0;

	if (_IOC_NR(cmd) >= AUDIO_IOC_AIO_MAXNR) {
		alog_err("cmd nr overflow\n");
		return -ENOIOCTLCMD;
	}

	switch (cmd) {
	case AUDIO_IOC_AIO_GET_PATH_SRC:
		ret = aio_get_path_src(arg);
		break;
	case AUDIO_IOC_AIO_INIT:
		ret = aio_init(arg);
		break;
	case AUDIO_IOC_AIO_DEINIT:
		ret = aio_deinit(arg);
		break;
	case AUDIO_IOC_AIO_MUTE_SPDIF:
		ret = aio_mute_spdif(arg);
		break;
	case AUDIO_IOC_AIO_HW_AQ_INIT:
		ret = aio_hw_aq_init(arg);
		break;
	case AUDIO_IOC_AIO_HW_AQ_DEINIT:
		ret = aio_hw_aq_deinit(arg);
		break;
	case AUDIO_IOC_AIO_SET_OPT_SRC_SPDIF:
		ret = aio_set_opt_src_spdif(arg);
		break;
	case AUDIO_IOC_AIO_CFG_OPT_SRC_HEADPHONE:
		ret = aio_cfg_opt_src_headphone(arg);
		break;
	case AUDIO_IOC_AIO_SET_MUTE:
		ret = aio_set_mute(arg);
		break;
	case AUDIO_IOC_AIO_DIO_SET_OPT_CHANNEL_ALL:
		ret = aio_dio_set_opt_channel_all(arg);
		break;
	case AUDIO_IOC_AIO_SET_OPT_SRC_I2S:
		ret = aio_set_opt_src_i2s(arg);
		break;
	default:
		ret = -ENOIOCTLCMD;
		break;
	}

	return ret;
}

long audio_hw_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	struct audio_hw_drvdata *drvdata = NULL;
	void __user *uarg = (void __user *)arg;
	int ret = 0;

	alog_debug("ioctl cmd %x[%c,%d] with arg %08lx\n", cmd,
		  (char)_IOC_TYPE(cmd), _IOC_NR(cmd), arg);

	drvdata = (struct audio_hw_drvdata *)filp->private_data;
	if (!drvdata) {
		alog_err("null drvdata\n");
		ret = -EFAULT;
		goto exit_error;
	}

	if (mutex_lock_interruptible(&drvdata->mtx)) {
		alog_warning("interrupted, no mutex held\n");
		ret = -ERESTARTSYS;
		goto exit_error;
	}

	switch (_IOC_TYPE(cmd)) {
	case AUDIO_IOC_ATV_MAGIC:
		ret = audio_hw_atv_ioctl_handler(cmd, uarg);
		break;
	case AUDIO_IOC_APP_MAGIC:
		ret = audio_hw_app_ioctl_handler(cmd, uarg);
		break;
	case AUDIO_IOC_AIO_MAGIC:
		ret = audio_hw_aio_ioctl_handler(cmd, uarg);
		break;
	default:
		ret = -ENOIOCTLCMD;
		break;
	}

	if (ret)
		goto exit_mutex_unlock;

	mutex_unlock(&drvdata->mtx);
	return 0;

exit_mutex_unlock:
	mutex_unlock(&drvdata->mtx);
exit_error:
	alog_err("ioctl failed with %d cmd %x (%c, %d)\n", ret, cmd,
		 (char)_IOC_TYPE(cmd), _IOC_NR(cmd));
	return ret;
}

