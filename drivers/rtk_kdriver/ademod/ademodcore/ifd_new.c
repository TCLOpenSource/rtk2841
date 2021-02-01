
#include "ifd_new.h"
#include "tvscalercontrol/scalerdrv/scalerdrv.h"

extern StructIFDDataType stIFDUserData;

//*****Print Debug*******
IFD_MSG_LEVEL IFD_XDATA g_ifd_msg_level = (IFD_MSG_LEVEL)(IFD_MSG_NONE);
//******Non-standard  Detect ****
bool IFD_XDATA g_ifd_release_flag = _FALSE;
//******Non-standard  Detect ****
bool IFD_XDATA g_ifd_sw_detect_en = IFD_ENABLE;
//*********Scan clamp speed adjust ***
bool IFD_XDATA g_ifd_non_std_scan_clamp_adjust_en = IFD_DISABLE;
//****** Output  CVBS AMP Compensate *******
bool IFD_XDATA g_ifd_output_CVBS_AMP_compensate_en = IFD_DISABLE;
//*****Scan, Set ch and Auto mode*******


void drv_ifd_init(void)
{
	UINT32 curTunerIFVal = 0;

	// ///////////////////////////////////////////////////////////////////
	// Analog
	// ///////////////////////////////////////////////////////////////////
	//CRT_CLK_OnOff(ANADEMOD, CLK_ON, NULL);
	//move to demod_merlin2_atv.c : AtvDemodInitialization
	//drv_ifd_power_on(IFD_ENABLE);
	//drv_ifd_adc_clock_init_162M();
	drv_ifd_analog_preset();

	// g_ifd_release_flag=_FALSE;

	curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_DK;
	drv_ifd_set_adcinput_swing((IFD_ADC_SHAGAIN)stIFDUserData.ADCInput_ShaGain, (IFD_ADC_FULLSCALE)stIFDUserData.ADCInput_FullScale);
	// drv_ifd_adc_clk_sel((IFD_CLK_RATE)stIFDUserData.ADCInput_clock,
	// (IFD_INPUT_DN_FILTER)stIFDUserData.ADCinput_dn_filter_sel);
	// drv_ifd_softreset_set();

	// ///////////////////////////////////////////////////////////////////
	// Input Filter
	// ///////////////////////////////////////////////////////////////////
	drv_ifd_input_filter_sel(stIFDUserData.InputFltPalD_En, &stIFDUserData.InputFltTablePalD[0]);
	drv_ifd_adc_clk_sel((IFD_CLK_RATE)stIFDUserData.ADCInput_clock, (IFD_INPUT_DN_FILTER)stIFDUserData.ADCinput_dn_filter_sel);

	// ///////////////////////////////////////////////////////////////////
	// CR
	// ///////////////////////////////////////////////////////////////////
	// Cr Bpf Coef.
	drv_ifd_cr_inner_lpf_en(IFD_ENABLE);
	drv_ifd_set_cr_bpf_coef(IFD_ENABLE, &stIFDUserData.CRBpf_Table_DK[0]);
	// Cr Lock
	drv_ifd_set_cr_lock_freq_thr(IFD_CR_LOCK_OFFSET_THD_550K);
	drv_ifd_set_cr_lock_with_freq(IFD_ENABLE);
	drv_ifd_set_cr_lock_with_hsync(IFD_ENABLE);
	drv_ifd_set_cr_nco(IFD_ENABLE,
					   drv_ifd_cal_nco(curTunerIFVal,
									   GET_ATV_IFD_CRSHIFT_EN()));
	rtd_maskl(IFD_108_cr_freq_sat_reg, ~((UINT32) 0x1FFFF),
			  IFD_CR_OFFSET_SAT);
	drv_ifd_set_cr_weighting_settings(IFD_CR_WEIGHT_CR_LOCK_ENABLE,
									  IFD_CR_WEIGHT_MAX_DECREASE_512CYCLE,
									  IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_1BIT);
	drv_ifd_set_cr_weighting_en(IFD_ENABLE);
	drv_ifd_cr_error_thd(GET_ATV_IFD_CR_LOCK_ERR_THD());
	drv_ifd_cr_auto_reset_en(IFD_ENABLE);
	drv_ifd_cr_phase_inverse_en(GET_ATV_IFD_CR_PHASEBAD_EN());
	drv_ifd_cr_phase_inverse_st4_en(GET_ATV_IFD_CR_PHASEBAD_EN_ST4());
	drv_ifd_cr_phase_inverse_st2_en(GET_ATV_IFD_CR_PHASEBAD_EN_ST2());
	drv_ifd_cr_phase_inverse_st0_en(GET_ATV_IFD_CR_PHASEBAD_EN_ST0());

	// Cr State
	drv_ifd_cr_loop_filter_kp_st3(GET_ATV_IFD_CR_ST3_PGAIN());
	drv_ifd_cr_loop_filter_ki_st3(GET_ATV_IFD_CR_ST3_IGAIN());
	drv_ifd_cr_loop_filter_kp_st2(GET_ATV_IFD_CR_ST2_PGAIN());
	drv_ifd_cr_loop_filter_ki_st2(GET_ATV_IFD_CR_ST2_IGAIN());
	drv_ifd_cr_loop_filter_kp_st0(GET_ATV_IFD_CR_ST0_PGAIN());
	drv_ifd_cr_loop_filter_ki_st0(GET_ATV_IFD_CR_ST0_IGAIN());
	drv_ifd_cr_loop_filter_kp(GET_ATV_IFD_CR_PGAIN());
	drv_ifd_cr_loop_filter_ki(GET_ATV_IFD_CR_IGAIN());
	drv_ifd_cr_st3_dn_debounce(0x2);
	drv_ifd_cr_st2_dn_debounce(0x2);
	drv_ifd_cr_st2_up_debounce(0x2);
	drv_ifd_cr_st1_dn_debounce(0x2);
	drv_ifd_cr_st1_up_debounce(0x2);
	drv_ifd_cr_st0_up_debounce(0x2);
	drv_ifd_cr_st0_phase_var_thr(GET_ATV_IFD_CR_PHASE_VAR_ST0_THR());
	drv_ifd_cr_st0_freq_var_thr(GET_ATV_IFD_CR_FREQ_VAR_ST0_THR());
	drv_ifd_cr_st2_phase_var_thr(GET_ATV_IFD_CR_PHASE_VAR_ST2_THR());
	drv_ifd_cr_vcheck_freq_var_thr(GET_ATV_IFD_CR_FREQ_VAR_VCHECK_THR());
	drv_ifd_cr_st2_freq_var_up_thr(GET_ATV_IFD_CR_FREQ_VAR_ST2_UP_THR());
	drv_ifd_cr_st2_freq_var_low_thr(GET_ATV_IFD_CR_FREQ_VAR_ST2_LOW_THR());
	drv_ifd_cr_st4_freq_var_thr(GET_ATV_IFD_CR_FREQ_VAR_ST4_THR());
	drv_ifd_cr_st3_freq_var_thr(GET_ATV_IFD_CR_FREQ_VAR_ST3_THR());
	rtd_outl(IFD_108_cr_state_weight_shift_reg,
			 (GET_ATV_IFD_CR_WEIGHT_SHIFT_ST4_THR() << 8) |
			 (GET_ATV_IFD_CR_WEIGHT_SHIFT_ST2_THR() << 4) |
			 (GET_ATV_IFD_CR_WEIGHT_SHIFT_ST0_THR()));
	rtd_outl(IFD_108_cr_phase_error_avg_set_reg, 0x00040040);	// Modify CR
	// state
	// setting
	// for
	// Non-standard
	// signal,
	// bit24,
	// bit20.
	rtd_outl(IFD_108_cr_freq_error_avg_set_reg, 0x08140040);
	// cr vsync
	drv_ifd_cr_vsync(IFD_CR_VSYNC_START_PAL, IFD_CR_VSYNC_END_PAL);

	// need to confirm->cr phase error avg

	rtd_outl(IFD_108_cr_data_gain_en_reg, 0x1); //Enable cr input mult. Data gain

	// ///////////////////////////////////////////////////////////////////
	// Shaping filter
	// ///////////////////////////////////////////////////////////////////
	drv_ifd_set_shaping_filter(GET_ATV_IFD_SHAPEFILTER_BW());
	drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
	// rtd_maskl(IFD_POWER_CAL_reg, ~(_BIT8), _BIT8); //Reset
	// need to confirm->power cal for shap

	// ///////////////////////////////////////////////////////////////////
	// Data gain
	// ///////////////////////////////////////////////////////////////////
	drv_ifd_set_videopath_output_gain((IFD_VIDEOPATH_OUTPUT_GAIN)
									  GET_ATV_IFD_DATA_GAIN_SEL());
	// need to confirm->data gain mask thd
	// need to confirm->data gain mask enable

	// ///////////////////////////////////////////////////////////////////
	// Clamping
	// ///////////////////////////////////////////////////////////////////
	drv_ifd_set_clamping_scale(IFD_CLAMP_SCALE_1D4);
	drv_ifd_set_clamping_thr_max(IFD_CLAMP_MAX_THD);
	drv_ifd_set_clamping_thr_min(IFD_CLAMP_MIN_THD);
	rtd_outl(IFD27_vclamp_in_min_sat_reg, 0x00001e00);

	// ///////////////////////////////////////////////////////////////////
	// Video output
	// ///////////////////////////////////////////////////////////////////
	drv_ifd_outputlpf_vsync(IFD_OUTPUTLPF_VSYNC_START_PAL,
							IFD_OUTPUTLPF_VSYNC_END_PAL);
	drv_ifd_set_54to27_decimation_enable(IFD_ENABLE);
	drv_ifd_set_video_upsample_lp_sel((IFD_UPSAMPLE_LP_SEL) GET_ATV_IFD_VIDEO_UPSAMPLE_LPF_PAL());	// IFD_UPSAMPLE_LP_SEL_PAL
	drv_ifd_video_outputlpf_coef_update(IFD_ENABLE,
										&stIFDUserData.VideoLpfPAL_DKL[0]);
	//drv_ifd_audio_output_div2(IFD_ENABLE);
	// ///////////////////////////////////////////////////////////////////
	// AGC
	// ///////////////////////////////////////////////////////////////////
	drv_ifd_agc_mode_set(GET_ATV_IFD_AGCPGAMODE(),
						 GET_ATV_IFD_AGCFIXPGAVALUE());

	rtd_outl(IFD_108_agc_enable_sel_reg, 0x0000009E);	// filter not yet
	// ready disable
	// first
	rtd_maskl(IFD_108_agc_max_countforcoarsemode_agc_cntl1_reg,
			  ~((UINT32) 0xFFF), IFD_UNLOCK_MAX_DEC_CNT);
	rtd_maskl(IFD_108_agc_max_countforfinelockmode_agc_cntl2_reg,
			  ~((UINT32) 0xFFF), IFD_UNLOCK_MAX_DEC_CNT);
	drv_ifd_set_slow_charge_en_for_max(IFD_ENABLE);
	drv_ifd_set_slow_charge_en_for_peak(IFD_ENABLE);
	drv_ifd_agc_diff_targ(GET_ATV_IFD_AGCLOOP1_DIFFTARGET());
	rtd_outl(IFD_108_agc_max_countforfinelockmode_agc_cntl2_reg,
			 GET_ATV_IFD_AGCLOOP1_DNSAMPLE() << 4);
	drv_ifd_agc_targ_val(GET_ATV_IFD_AGCLOOP1_MAXTARGET_PAL());

	rtd_outl(IFD_108_agc_cntl_sel_reg, 0x0);
	drv_ifd_agc_polarity(GET_ATV_TUNER_AGC_POLARITY());
	rtd_outl(IFD_108_ki_val_reg, 0x0);
	drv_ifd_agc_loop1_kp_settings(GET_ATV_IFD_AGCLOOP1_KPGAIN());
	drv_ifd_agc_loop1_ki_settings(GET_ATV_IFD_AGCLOOP1_KIGAIN());
	drv_ifd_agc_loop1_pishift_settings(GET_ATV_IFD_AGCLOOP1_KPKISHIFT());
	rtd_outl(IFD_108_rf_agc_limit_value_reg,
			 ((GET_ATV_IFD_AGC_RF_MIN(0) << 16) |
			  GET_ATV_IFD_AGC_RF_MAX(0)));
	rtd_outl(IFD_108_if_agc_min_reg,
			 ((GET_ATV_IFD_AGC_IF_MAX() << 16) | GET_ATV_IFD_AGC_IF_MIN()));
	rtd_outl(IFD_108_agc_lock_th_reg,
			 ((IFD_LOOP1_AGC_LOCK_OUT_THD << 8) |
			  IFD_LOOP1_AGC_LOCK_IN_THD));
	drv_ifd_agc_hsync_start1(IFD_VSmode1_Hstart_PAL, IFD_VSmode1_Hend_PAL);
	drv_ifd_agc_vsync_start1(IFD_VSmode1_Vstart_PAL, IFD_VSmode1_Vend_PAL);

	rtd_outl(IFD_108_agc_peak_detect_reg, (IFD_PEAK_DEC_CNT & 0xfff));
	drv_ifd_agc_loop2_peak_cnt(IFD_PEAK2_DEC_CNT);
	drv_ifd_set_agc_loop1_peak_force(GET_ATV_IFD_AGCLOOP1_PEAKFORCE_EN());
	drv_ifd_agc_loop1_peak_en(IFD_ENABLE);
	drv_ifd_agc_loop2_peak_en(IFD_ENABLE);
	drv_ifd_agc_peak_target(GET_ATV_IFD_AGCLOOP1_PEAKTARGET());
	drv_ifd_agc_krf(IFD_AGC_KRF);
	rtd_outl(IFD_108_agc_linebase_ctl_reg, 0x00000070);
	rtd_outl(IFD_108_agc_max2_cnt_1_reg,
			 ((IFD_UNLOCK_MAX2_DEC_CNT << 12) | IFD_LOCK_MAX2_DEC_CNT));
	drv_ifd_loop2_agcin_kpki_settings(GET_ATV_IFD_AGCLOOP2_KPGAIN(),
									  GET_ATV_IFD_AGCLOOP2_KIGAIN(),
									  GET_ATV_IFD_AGCLOOP2_KPSHIFT(),
									  GET_ATV_IFD_AGCLOOP2_KISHIFT());
	rtd_outl(IFD_108_agc_max2_limit_cnt_1_reg, 0x0000FFF0);

	drv_ifd_agc_loop2_dn_sample(GET_ATV_IFD_AGCLOOP2_DNSAMPLE());
	drv_ifd_agc_dgain_up_dn_boundary(IFD_AGC_2STEP_DGAIN_LOW_THD,
									 IFD_AGC_2STEP_DGAIN_HIGH_THD);
	// Carol //rtd_outl(IFD_108_agc_dgain_to_pga_reg, 0x20401388);
	drv_ifd_agc_2step_pga_step(IFD_AGC_2STEP_PGA_STEP);
	drv_ifd_agc_vtop(GET_ATV_IFD_AGC_VTOP(0));
	drv_ifd_agc_2step_pga_minimum(GET_ATV_IFD_AGC_PGA_MIN(0));
	drv_ifd_agc_loop1_finetune_dn_sample(GET_ATV_IFD_AGCLOOP1_FINEDNSAMPLE
										 ());
	drv_ifd_agc_loop2_finetune_dn_sample(GET_ATV_IFD_AGCLOOP2_FINEDNSAMPLE
										 ());
	rtd_outl(IFD_108_agc_enable_sel_reg, 0x000000FE);

	drv_ifd_agc_rfagc_padctrl(IFD_AGC_PADCTRL_OPENDRAIN);
	drv_ifd_agc_ifagc_padctrl(IFD_AGC_PADCTRL_TTL);
	drv_ifd_agc_sigma_delta_dnsel(GET_ATV_IFD_AGC_SIGMADELTA_DNSEL());

	// Rf Agc Hasten
	rtd_outl(IFD_108_agc_rf_hasten_reg,
			 (GET_ATV_IFD_AGC_RFHASTEN_EN() << 28) |
			 (GET_ATV_IFD_AGC_RFHASTEN_KI() << 24) |
			 (GET_ATV_IFD_AGC_RFHASTEN_CNTL() << 12) |
			 GET_ATV_IFD_AGC_RFHASTEN_THR());
	// Agc Sep Rf If
	rtd_outl(IFD_108_agc_sep_rf_if_reg,
			 (GET_ATV_IFD_AGC_SEPRFIF_EN() << 12) |
			 (GET_ATV_IFD_AGC_SEPRFIF_IFKP() << 4) |
			 GET_ATV_IFD_AGC_SEPRFIF_IFKI());
	// Adaptive Gain Target
	drv_ifd_agc_adaptivetarget_fine_interval
	(GET_ATV_IFD_AGCADAPT_FINEINTERVAL());
	drv_ifd_agc_adaptivetarget_interval(GET_ATV_IFD_AGCADAPT_INTERVAL());
	drv_ifd_agc_adaptivetarget_en(IFD_ENABLE);
	drv_ifd_agc_adaptivetarget_inc_thr(GET_ATV_IFD_AGCADAPT_INCTHR());
	drv_ifd_agc_adaptivetarget_min_difftarg
	(GET_ATV_IFD_AGCADAPT_MINDIFFTARGET());
	drv_ifd_agc_adaptivetarget_min_targ(GET_ATV_IFD_AGCADAPT_MINMAXTARGET
										());
	drv_ifd_agc_adaptivetarget_fine_targthr
	(GET_ATV_IFD_AGCADAPT_FINEINTERVAL());
	drv_ifd_agc_adaptivetarget_diff_coarsestep
	(GET_ATV_IFD_AGCADAPT_DIFFCOARSESTEP());
	// CR power lock register
	rtd_maskl(IFD_108_input_power_ctrl_reg, ~_BIT0, 0);
	rtd_maskl(IFD_108_input_power_ctrl_reg, 0xfffffcff, 0x00);
	rtd_maskl(IFD_108_input_power_ctrl_reg, 0xffffff8f, 0x20);
	drv_ifd_set_power_diff_cr_lock_thr(GET_ATV_IFD_CRPOWER_LOCK_THR());
	// Simple h
	drv_ifd_set_simple_h_deb(0x1F);
	drv_ifd_set_simple_h_thd(0x100);

	// Debug Init
	// drvif_ifd_dma_data((IFD_DEBUG_MODE_CONFIG)FIFO_OUT);
}

//=================================================================

/**
 * drv_ifd_agc_mode_set
 *
 *
 * @param <ifdAGCmode><pga_fix_value>
 * @return { void }
 */
void
drv_ifd_agc_mode_set(IFD_MODE_AGC_PGA_CONFIG ifd_agc_mode,
					 IFD_MODE_AGC_PGA_FIXGAIN_LEVEL pga_fix_value)
{
	switch (ifd_agc_mode) {
	case IFD_AGC_DOUBLE_NOIFAMP_PGA:
	case IFD_AGC_2STEP_NOIFAMP_PGA:
	case IFD_AGC_DOUBLE_IFAMP_FIXPGA:
	default:
		drv_ifd_adc_input_sel(IFD_ADC_INPUT_SEL_IFPGA);
		break;
	case IFD_AGC_DOUBLE_IFAMP_NOPGA:
	case IFD_AGC_2STEP_IFAMP_NOPGA:
		drv_ifd_adc_input_sel(IFD_ADC_INPUT_SEL_BYPASS);
		break;
	}
	switch (ifd_agc_mode) {
	case IFD_AGC_DOUBLE_NOIFAMP_PGA:
	case IFD_AGC_DOUBLE_IFAMP_NOPGA:
	case IFD_AGC_DOUBLE_IFAMP_FIXPGA:
		drv_ifd_agc_mode_sel(IFD_AGC_MODE_2LOOP);
		break;
	case IFD_AGC_2STEP_IFAMP_NOPGA:
	case IFD_AGC_2STEP_NOIFAMP_PGA:
	default:
		drv_ifd_agc_mode_sel(IFD_AGC_MODE_2STEP);
		break;
	}
	if (ifd_agc_mode == IFD_AGC_DOUBLE_IFAMP_FIXPGA) {
		if (pga_fix_value <= IFD_MODE_AGC_PGA_FIXGAIN_LEVEL_2P5DB) {
			switch (pga_fix_value) {
			case -1:
				drv_ifd_adc_pga_gain_fix(IFD_ENABLE, IFD_ADC_PGAFIX_CTRL_2_5DB);
				break;
			case -2:
				drv_ifd_adc_pga_gain_fix(IFD_ENABLE, IFD_ADC_PGAFIX_CTRL_N1DB);
				break;
			case -3:
				drv_ifd_adc_pga_gain_fix(IFD_ENABLE, IFD_ADC_PGAFIX_CTRL_N2DB);
				break;
			case -4:
				drv_ifd_adc_pga_gain_fix(IFD_ENABLE, IFD_ADC_PGAFIX_CTRL_N3DB);
				break;
			case -5:
				drv_ifd_adc_pga_gain_fix(IFD_ENABLE, IFD_ADC_PGAFIX_CTRL_N4DB);
				break;
			case -6:
				drv_ifd_adc_pga_gain_fix(IFD_ENABLE, IFD_ADC_PGAFIX_CTRL_N5DB);
				break;
			case -7:
				drv_ifd_adc_pga_gain_fix(IFD_ENABLE, IFD_ADC_PGAFIX_CTRL_N6DB);
				break;
			case -8:
				drv_ifd_adc_pga_gain_fix(IFD_ENABLE, IFD_ADC_PGAFIX_CTRL_N7DB);
				break;
			default:
				drv_ifd_adc_pga_gain_fix(IFD_ENABLE, IFD_ADC_PGAFIX_CTRL_2_5DB);
			}
			drv_ifd_agc_pga_manual_en(IFD_ENABLE, 0x00);
		} else {
			drv_ifd_adc_pga_gain_fix(IFD_DISABLE,
									 IFD_ADC_PGAFIX_CTRL_FROM_DIGITAL);
			drv_ifd_agc_pga_manual_en(IFD_ENABLE, pga_fix_value);
		}
	} else {
		drv_ifd_adc_pga_gain_fix(IFD_DISABLE,
								 IFD_ADC_PGAFIX_CTRL_FROM_DIGITAL);
		drv_ifd_agc_pga_manual_en(IFD_DISABLE, 0x00);
	}
	return;
}

void drv_ifd_agc_polarity(TUNER_AGCPOLARITY_SEL polarity)
{
	switch (polarity) {
	default:
	case TUNER_RF_POS_IF_POS:
		drv_ifd_agc_polar_inv(IFD_DISABLE);
		break;
	case TUNER_RF_POS_IF_NONE:
		drv_ifd_agc_polar_inv(IFD_DISABLE);
		break;
	case TUNER_RF_POS_IF_NEG:	// set rf, if individually
		drv_ifd_agc_out_inv(IFD_DISABLE, IFD_ENABLE);
		break;
	case TUNER_RF_NONE_IF_POS:
		drv_ifd_agc_polar_inv(IFD_DISABLE);
		break;
	case TUNER_RF_NONE_IF_NONE:
		drv_ifd_agc_polar_inv(IFD_DISABLE);
		break;
	case TUNER_RF_NONE_IF_NEG:	// polarity inverse
		drv_ifd_agc_polar_inv(IFD_ENABLE);
		break;
	case TUNER_RF_NEG_IF_POS:	// set rf, if individually
		drv_ifd_agc_out_inv(IFD_ENABLE, IFD_DISABLE);
		break;
	case TUNER_RF_NEG_IF_NONE:	// polarity inverse
		drv_ifd_agc_polar_inv(IFD_ENABLE);
		break;
	case TUNER_RF_NEG_IF_NEG:	// polarity inverse
		drv_ifd_agc_polar_inv(IFD_ENABLE);
		break;
	}
}

void drvif_ifd_set_scanchannel(StructATVModule *pAtvModule)
{
	UINT8 clamp_rst_flag = 0;
	bool CH_mode;

	CH_mode = 1;		// scan_mode
	IFD_DEBUG_MSG(IFD_MSG_INFO, "drvif_ifd_set_scanchannel(%x, %x)\n",
				  (UINT32) pAtvModule->video_mode,
				  (UINT32) pAtvModule->audio_mode);

	// ///////////////////////////////////////////////////////////////////
	// Step1. Disable some setting used in display channel.
	// ///////////////////////////////////////////////////////////////////
	drv_ifd_specific_function_enable(IFD_DISABLE);
	drv_ifd_mtd_reset(IFD_ENABLE);
	drv_ifd_sw_detect_cancel(0xf);
	drv_ifd_agc_peak_target(GET_ATV_IFD_AGCLOOP1_PEAKTARGET());	// reset AGC
	// peak
	// target

	// ///////////////////////////////////////////////////////////////////
	// Step1. Set Color Standar Mode
	// ///////////////////////////////////////////////////////////////////
	// Normal rf tuner : set video only @input video mode change
	// Lif tuner: set video mode@input video mode change, or audio mode change

	switch (pAtvModule->video_mode) {
	case ZNTSC:
	case ZNTSC_50:
		if (pAtvModule->audio_mode == ATV_SOUND_DK_SYSTEM)
			drv_ifd_set_video_ntsc_dk(CH_mode);
		else
			drv_ifd_set_video_ntsc(CH_mode);
		break;
	case ZNTSC_443:
		drv_ifd_set_video_pal(CH_mode);
		break;
	case ZPAL_N:
		drv_ifd_set_video_ntsc(CH_mode);
		break;
	case ZPAL_M:
		drv_ifd_set_video_ntsc(CH_mode);
		break;
	case ZPAL_I:
		drv_ifd_set_video_pal(CH_mode);
		break;
	case ZSECAM:
		drv_ifd_set_video_pal(CH_mode);
		break;
	case ZSECAML:
		drv_ifd_set_video_secaml(CH_mode);
		clamp_rst_flag = 1;
		break;
	case ZSECAMLA:
		drv_ifd_set_video_secamla(CH_mode);
		clamp_rst_flag = 1;
		break;
	case ZPAL_60:
		drv_ifd_set_video_pal(CH_mode);
		break;
	default:
		drv_ifd_set_video_pal(CH_mode);
		break;
	}

	ScalerTimer_DelayXms(20);
	if (g_ifd_non_std_scan_clamp_adjust_en == IFD_ENABLE)
		drv_ifd_set_clamping_scale(GET_ATV_IFD_CLAMPSCALE_SETCH());
	else if (drv_ifd_set_clamping_scale_get_info() !=
			 GET_ATV_IFD_CLAMPSCALE_SCANCH())
		drv_ifd_set_clamping_scale(GET_ATV_IFD_CLAMPSCALE_SCANCH());

	if ((pAtvModule->video_mode == ZSECAML)
		|| ((pAtvModule->video_mode == ZSECAMLA)))
		drv_ifd_clamp_reset(IFD_CLAMP_RESET_POS);
	else
		drv_ifd_clamp_reset(IFD_CLAMP_RESET_NEG);

	ScalerTimer_DelayXms(5);	// frank@0430 Change busy delay to save time
	drv_ifd_mtd_reset(IFD_DISABLE);

}

extern unsigned char OutpuLocalDimmingPatMode;

//=================================================================

/**
 * drvif_ifd_set_setchannel
 *
 *
 * @param <video_mode>
 * @return { void }
 */
void drvif_ifd_set_setchannel(StructATVModule *pAtvModule)
{
	bool CH_mode;
	CH_mode = 0;		// normal_mode

	if (OutpuLocalDimmingPatMode == TRUE)
		return;

	IFD_DEBUG_MSG(IFD_MSG_INFO, "drvif_ifd_set_setchannel(%x, %x, %d)\n",
				  (UINT32) pAtvModule->video_mode,
				  (UINT32) pAtvModule->audio_mode,
				  (UINT32) pAtvModule->freq);
	IFD_DEBUG_MSG(IFD_MSG_INFO, "!!!DISPLAY_MODE_FRC!!!\n");
	drivf_scaler_reset_freerun();
	drv_ifd_specific_function_enable(IFD_DISABLE);
	drv_ifd_sw_detect_cancel(0x1);
	rtd_maskl(IFD27_clamping_scale_reg, ~_BIT4, _BIT4);
	drv_ifd_agc_peak_target(GET_ATV_IFD_AGCLOOP1_PEAKTARGET());	// reset AGC
	// peak
	// target

	// ///////////////////////////////////////////////////////////////////
	// Step1. Disable some setting
	// ///////////////////////////////////////////////////////////////////
#ifdef IFD_TEST_DMA
	drv_ifd_adc_clk_sel((IFD_CLK_RATE) GET_ATV_IFD_ADCINPUT_CLOCK(),
						(IFD_INPUT_DN_FILTER)
						GET_ATV_IFD_ADCINPUT_DN_FILTER_SEL());
	ScalerTimer_DelayXms(10);
	// clear adc and input fifo
	drv_ifd_interrupt_input_fifo_clear();
	drv_ifd_input_input_fifo_clear();
	drv_ifd_input_input_fifo_flag_clear();
#else
	if (GET_ATV_TUNER_TYPE() == TUNER_LOW_IF) {
		if (((pAtvModule->freq < 162300000)
			 && (pAtvModule->freq > 157000000))
			|| ((pAtvModule->freq < 324300000)
				&& (pAtvModule->freq > 319000000))
			|| ((pAtvModule->freq < 486300000)
				&& (pAtvModule->freq > 481000000))
			|| ((pAtvModule->freq < 648300000)
				&& (pAtvModule->freq > 643000000))
			|| ((pAtvModule->freq < 810300000)
				&& (pAtvModule->freq > 805000000))) {
			if ((drv_ifd_adc_clk_sel_get_info() != IFD_CLK_RATE_135M) || ((rtd_inl(PLL27X_REG_SYS_PLL_27X4_reg) & 0x0100) != 0x0100)) {
				IFD_DEBUG_MSG(IFD_MSG_INFO,
							  "Freq=%lu; IFD ADC CLOCK=135MHz\n",
							  pAtvModule->freq);
				drv_ifd_adc_clk_sel((IFD_CLK_RATE)
									IFD_CLK_RATE_135M,
									(IFD_INPUT_DN_FILTER)
									IFD_INPUT_DN_FILTER_135M_LPF);
				ScalerTimer_DelayXms(10);
				// clear adc and input fifo
				drv_ifd_interrupt_input_fifo_clear();
				drv_ifd_input_input_fifo_clear();
				drv_ifd_input_input_fifo_flag_clear();
			}
		} else {
			if ((drv_ifd_adc_clk_sel_get_info() !=
				 GET_ATV_IFD_ADCINPUT_CLOCK()) || ((rtd_inl(PLL27X_REG_SYS_PLL_27X4_reg) & 0x0100) != 0x0100)) {
				IFD_DEBUG_MSG(IFD_MSG_INFO,
							  "Freq=%lu; IFD ADC CLOCK=DEFAULT\n",
							  pAtvModule->freq);
				drv_ifd_adc_clk_sel((IFD_CLK_RATE)
									GET_ATV_IFD_ADCINPUT_CLOCK
									(), (IFD_INPUT_DN_FILTER)
									GET_ATV_IFD_ADCINPUT_DN_FILTER_SEL
									());
				ScalerTimer_DelayXms(10);
				// clear adc and input fifo
				drv_ifd_interrupt_input_fifo_clear();
				drv_ifd_input_input_fifo_clear();
				drv_ifd_input_input_fifo_flag_clear();
			}
		}
	}
#endif

	// Normal rf tuner : set video only @input video mode change
	// Lif tuner: set video mode@input video mode change, or audio mode change
	// if(((stIFDUserData.tunerPara.tunerType!=TUNER_NORMAL)&&((ori_video_mode!=pAtvModule->video_mode)||(ori_audio_mode!=pAtvModule->audio_mode))
	// )
	// ||((stIFDUserData.tunerPara.tunerType==TUNER_NORMAL)&&(ori_video_mode!=pAtvModule->video_mode)
	// ))
	{
		switch (pAtvModule->video_mode) {
		// IFD_DEBUG_MSG(IFD_MSG_SETCH, "pAtvModule->video_mode=%d\n",
		// (UINT32)pAtvModule->video_mode);
		case ZNTSC:
		case ZNTSC_50:
			if (pAtvModule->audio_mode == ATV_SOUND_DK_SYSTEM) {
				drv_ifd_set_video_ntsc_dk(CH_mode);
			} else {
				drv_ifd_set_video_ntsc(CH_mode);
			}
			break;
		case ZNTSC_443:
			drv_ifd_set_video_pal(CH_mode);
			break;
		case ZPAL_N:
			drv_ifd_set_video_ntsc(CH_mode);
			break;
		case ZPAL_M:
			drv_ifd_set_video_ntsc(CH_mode);
			break;
		case ZPAL_I:
		default:	// frank@0629 add for auto mode
			drv_ifd_set_video_pal(CH_mode);
			break;
		case ZSECAM:
			drv_ifd_set_video_pal(CH_mode);
			break;
		case ZSECAML:
		case ZPAL_L:
			drv_ifd_set_video_secaml(CH_mode);
			break;
		case ZSECAMLA:
			drv_ifd_set_video_secamla(CH_mode);
			break;
		case ZPAL_60: {
			drv_ifd_set_video_pal(CH_mode);
		}
		break;
			// case ZFM_RADIO:
			// drv_ifd_set_video_fm_radio(CH_mode);
			// break;
		}
	}
	// ///////////////////////////////////////////////////////////////////
	// Step6. Set Clamp Scale
	// ///////////////////////////////////////////////////////////////////
	if (drv_ifd_set_clamping_scale_get_info() !=
		GET_ATV_IFD_CLAMPSCALE_SETCH())
		drv_ifd_set_clamping_scale(GET_ATV_IFD_CLAMPSCALE_SETCH());

	if ((pAtvModule->video_mode == ZSECAML)
		|| ((pAtvModule->video_mode == ZSECAMLA)))
		drv_ifd_clamp_reset(IFD_CLAMP_RESET_POS);
	else
		drv_ifd_clamp_reset(IFD_CLAMP_RESET_NEG);

	// ///////////////////////////////////////////////////////////////////
	// Step1. Set group delay
	// ///////////////////////////////////////////////////////////////////
	if (pAtvModule->video_mode != ZFM_RADIO)
		drvif_ifd_group_delay_mode((ATV_SOUND_STD_MAIN_SYSTEM)
								   pAtvModule->audio_mode, pAtvModule->video_mode);

	// ///////////////////////////////////////////////////////////////////
	// Step2. Delay
	// ///////////////////////////////////////////////////////////////////
	ScalerTimer_DelayXms(GET_ATV_IFD_SETCHANNELDELAY());

	// ///////////////////////////////////////////////////////////////////
	// Step3. enable some setting
	// ///////////////////////////////////////////////////////////////////
#if 1				// #ifdef
	// ENABLE_IFD_PATCH_SUPPORT_GREEN_PATTERN
	drv_ifd_cr_state_en(IFD_ENABLE);//WOSLQEVENT-69564//(IFD_DISABLE);
	drv_ifd_cr_phase_inverse_en(IFD_ENABLE);
#else
	if (pAtvModule->video_mode != ZFM_RADIO)
		drv_ifd_specific_function_enable(IFD_ENABLE);
#endif
	//if (pAtvModule->video_mode != ZFM_RADIO)
	//	drv_ifd_set_cr_lock_freq_thr((UINT16)
	//				     IFD_CR_LOCK_OFFSET_THD_550K);
	//else
	//	drv_ifd_set_cr_lock_freq_thr((UINT16)
	//				     IFD_CR_LOCK_OFFSET_THD_DISABLE);
	drv_ifd_agc_average_control(0x14, 1, 1);

	rtd_maskl(IFD27_clamping_scale_reg, ~_BIT4, 0);
	// DEBUG ONLY
#ifdef IFD_TEST_DMA		// Test DMA

	ADEMOD_INFO("Wait for Signal Stable");
	for (UINT32 dma_i = 0; dma_i < 2000; dma_i++) {
		ADEMOD_INFO(".");
		ScalerTimer_DelayXms(1);
	}
	ADEMOD_INFO("\n");
	drvif_ifd_dma_data(FIFO_OUT);
	drvif_ifd_factorymode_debug_set_dma_mode(FIFO_OUT);
	drvif_module_vdc_factory_IFDDMA_Enable(/* 100000 */ 0x00400000);
#else
	// if(pAtvModule->video_mode!=ZFM_RADIO)
	// IFD_ReactiveTimerEvent(SLRTIMER_IFD_SW_DETECT, 30,
	// drv_ifd_sw_detect_active);
#endif

}

void drv_ifd_specific_function_enable(bool enable)
{
	// Cr State
	drv_ifd_cr_state_en(enable);
	// Cr phase inverse enable
	drv_ifd_cr_phase_inverse_en(enable);
	// Agc Hasten

}

void drv_ifd_sw_detect_cancel(UINT8 agc_speed)
{
	// IFD_ScalerTimer_CancelTimerEvent(SLRTIMER_IFD_SW_DETECT);
	if (drv_ifd_soft_reset_get_info() == IFD_ENABLE) {
		IFD_DEBUG_MSG(IFD_MSG_OTHERS,
					  "!!!!!!!!!!!!IFD reset release!!!!!!!!!!!\n");
		drv_ifd_soft_reset(IFD_DISABLE);
	}
	// reset
	// g_ifd_sw_detect_cnt = 0;
	// g_ifd_sw_detect_cycle_cnt = 0;
	drv_ifd_agc_loop2_dn_sample(agc_speed);
	// drv_ifd_agc_2step_pga_step(IFD_AGC_2STEP_PGA_STEP);

	rtd_maskl(IFD27_clamping_scale_reg, ~_BIT4, 0);
	// drvif_module_vdc_set_Killgate(VDC_kg_off);
	drv_ifd_agc_adaptivetarget_inc_thr(GET_ATV_IFD_AGCADAPT_INCTHR());

}

void drv_ifd_set_video_ntsc(bool scan_mode)
{
	UINT32 curTunerIFVal = 0;

	if (scan_mode) {
		curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_MN;
		IFD_DEBUG_MSG(IFD_MSG_SCANCH, "curTunerIFVal=%d\n",
					  (UINT32) curTunerIFVal);

		if (curTunerIFVal < 270000) {
			if (stIFDUserData.tunerPara.tunerIFType ==
				TUNER_IF_TYPE_NEG)
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
			else
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
		} else {
			if (stIFDUserData.tunerPara.tunerIFType ==
				TUNER_IF_TYPE_NEG)
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
			else
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
		}
		drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)
									 stIFDUserData.CRInnerLpf_MN);
		drv_ifd_set_cr_bpf_coef(IFD_ENABLE,
								&stIFDUserData.CRBpf_Table_MN[0]);
		drv_ifd_set_cr_nco(IFD_ENABLE,
						   drv_ifd_cal_nco(curTunerIFVal,
										   GET_ATV_IFD_CRSHIFT_EN()));
		drvif_ifd_set_scan_mode_detect_cr_lock(curTunerIFVal);
	} else {
		curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_MN;
		IFD_DEBUG_MSG(IFD_MSG_SETCH, "curTunerIFVal=%d\n",
					  (UINT32) curTunerIFVal);

		if (curTunerIFVal < 270000) {
			if (stIFDUserData.tunerPara.tunerIFType ==
				TUNER_IF_TYPE_NEG)
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
			else
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
		} else {
			if (stIFDUserData.tunerPara.tunerIFType ==
				TUNER_IF_TYPE_NEG)
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
			else
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
		}
		drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)
									 stIFDUserData.CRInnerLpf_MN);
		drv_ifd_set_cr_bpf_coef(IFD_ENABLE,
								&stIFDUserData.CRBpf_Table_MN[0]);
		drv_ifd_set_cr_nco(IFD_ENABLE,
						   drv_ifd_cal_nco(curTunerIFVal,
										   GET_ATV_IFD_CRSHIFT_EN()));
	}

	drv_ifd_input_filter_sel(stIFDUserData.InputFltNtsc_En,
							 &stIFDUserData.InputFltTableNtsc[0]);
	drv_ifd_outputlpf_vsync(IFD_OUTPUTLPF_VSYNC_START_NTSC,
							IFD_OUTPUTLPF_VSYNC_END_NTSC);
	// ives
	drv_ifd_video_outputlpf_coef_update(IFD_ENABLE,
										&stIFDUserData.VideoLpfNTSC[0]);

	drv_ifd_set_video_upsample_lp_sel((IFD_UPSAMPLE_LP_SEL) GET_ATV_IFD_VIDEO_UPSAMPLE_LPF_NTSC());	/* IFD_UPSAMPLE_LP_SEL_NTSC
													 */
	drv_ifd_set_shaping_filter(GET_ATV_IFD_SHAPEFILTER_BW());
	drv_ifd_set_pos_neg_mod(IFD_MODULATION_SEL_NEG);
	drv_ifd_cr_vsync(IFD_CR_VSYNC_START_NTSC, IFD_CR_VSYNC_END_NTSC);	// cr
	// vsync
	drv_ifd_set_cr_weighting_en(IFD_ENABLE);
	drv_ifd_cr_loop_filter_kp(GET_ATV_IFD_CR_PGAIN());
	drv_ifd_cr_loop_filter_ki(GET_ATV_IFD_CR_IGAIN());

	if (scan_mode) {
		drv_ifd_eq_en(0);
		// drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_NTSC[0]);
	} else {
		drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_NTSC[0]);
		drv_ifd_eq_en(1);
	}

	drv_ifd_agc_loop1_pos_en(IFD_DISABLE);
	drv_ifd_agc_targ_val(GET_ATV_IFD_AGCLOOP1_MAXTARGET_NTSC());
	drv_ifd_agc_data_target(GET_ATV_IFD_AGC_DATA_TARG());
	drv_ifd_mtd_set_thr(0x7, GET_ATV_IFD_AGC_DATA_TARG() >> 1,
						(GET_ATV_IFD_AGC_DATA_TARG() >> 1) - 0x30);
	drv_ifd_agc_hsync_start1(IFD_VSmode1_Hstart_NTSC,
							 IFD_VSmode1_Hend_NTSC);
	drv_ifd_agc_vsync_start1(IFD_VSmode1_Vstart_NTSC, IFD_VSmode1_Vend_NTSC);	// irene
	// ok//
	// irene
	// has
	// to
	// check
	// why
	// w/o
	// vsync_start2/hsync_start2
	rtd_outl(IFD_108_agc_enable_sel_reg, 0x000000FE);	// agc enable
	drv_ifd_agc_loop1_fine_tune_en(IFD_DISABLE);
	drv_ifd_set_agc_loop1_peak_force(GET_ATV_IFD_AGCLOOP1_PEAKFORCE_EN());
	drv_ifd_set_agc_loop2_peak_force(IFD_DISABLE);
	drv_ifd_agc_loop1_kp_settings(GET_ATV_IFD_AGCLOOP1_KPGAIN());
	drv_ifd_agc_loop1_ki_settings(GET_ATV_IFD_AGCLOOP1_KIGAIN());
	drv_ifd_agc_loop1_pishift_settings(GET_ATV_IFD_AGCLOOP1_KPKISHIFT());
}

void drv_ifd_set_video_ntsc_dk(bool scan_mode)
{
	UINT32 curTunerIFVal = 0;

	if (scan_mode) {
		curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_SCAN;
		IFD_DEBUG_MSG(IFD_MSG_SCANCH, "curTunerIFVal=%d\n",
					  (UINT32) curTunerIFVal);

		if (curTunerIFVal < 270000) {
			if (stIFDUserData.tunerPara.tunerIFType ==
				TUNER_IF_TYPE_NEG)
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
			else
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
		} else {
			if (stIFDUserData.tunerPara.tunerIFType ==
				TUNER_IF_TYPE_NEG)
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
			else
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
		}
		drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)
									 stIFDUserData.CRInnerLpf_SCAN);
		drv_ifd_set_cr_bpf_coef(IFD_ENABLE,
								&stIFDUserData.CRBpf_Table_SCAN[0]);
		drv_ifd_set_cr_nco(IFD_ENABLE,
						   drv_ifd_cal_nco(curTunerIFVal,
										   GET_ATV_IFD_CRSHIFT_EN()));
		drvif_ifd_set_scan_mode_detect_cr_lock(curTunerIFVal);
	} else {
		curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_DK;
		IFD_DEBUG_MSG(IFD_MSG_SETCH, "curTunerIFVal=%d\n",
					  (UINT32) curTunerIFVal);

		if (curTunerIFVal < 270000) {
			if (stIFDUserData.tunerPara.tunerIFType ==
				TUNER_IF_TYPE_NEG)
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
			else
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
		} else {
			if (stIFDUserData.tunerPara.tunerIFType ==
				TUNER_IF_TYPE_NEG)
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
			else
				drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
		}
		drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)
									 stIFDUserData.CRInnerLpf_IDKL);
		drv_ifd_set_cr_bpf_coef(IFD_ENABLE,
								&stIFDUserData.CRBpf_Table_DK[0]);
		drv_ifd_set_cr_nco(IFD_ENABLE,
						   drv_ifd_cal_nco(curTunerIFVal,
										   GET_ATV_IFD_CRSHIFT_EN()));
	}
	drv_ifd_input_filter_sel(stIFDUserData.InputFltPalD_En,
							 &stIFDUserData.InputFltTablePalD[0]);
	drv_ifd_outputlpf_vsync(IFD_OUTPUTLPF_VSYNC_START_NTSC,
							IFD_OUTPUTLPF_VSYNC_END_NTSC);
	drv_ifd_video_outputlpf_coef_update(IFD_ENABLE,
										&stIFDUserData.VideoLpfNTSC[0]);
	drv_ifd_set_video_upsample_lp_sel((IFD_UPSAMPLE_LP_SEL) GET_ATV_IFD_VIDEO_UPSAMPLE_LPF_NTSC());	/* IFD_UPSAMPLE_LP_SEL_NTSC
													 */
	drv_ifd_set_shaping_filter(GET_ATV_IFD_SHAPEFILTER_BW());
	drv_ifd_set_pos_neg_mod(IFD_MODULATION_SEL_NEG);
	drv_ifd_cr_vsync(IFD_CR_VSYNC_START_NTSC, IFD_CR_VSYNC_END_NTSC);	// cr
	// vsync
	drv_ifd_set_cr_weighting_en(IFD_ENABLE);
	drv_ifd_cr_loop_filter_kp(GET_ATV_IFD_CR_PGAIN());
	drv_ifd_cr_loop_filter_ki(GET_ATV_IFD_CR_IGAIN());
	if (scan_mode) {
		drv_ifd_eq_en(0);
	} else {
		drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_NTSC[0]);
		drv_ifd_eq_en(1);
	}

	drv_ifd_agc_loop1_pos_en(IFD_DISABLE);
	drv_ifd_agc_targ_val(GET_ATV_IFD_AGCLOOP1_MAXTARGET_NTSC());
	drv_ifd_agc_data_target(GET_ATV_IFD_AGC_DATA_TARG());
	drv_ifd_mtd_set_thr(0x7, GET_ATV_IFD_AGC_DATA_TARG() >> 1,
						(GET_ATV_IFD_AGC_DATA_TARG() >> 1) - 0x30);
	drv_ifd_agc_hsync_start1(IFD_VSmode1_Hstart_NTSC,
							 IFD_VSmode1_Hend_NTSC);
	drv_ifd_agc_vsync_start1(IFD_VSmode1_Vstart_NTSC, IFD_VSmode1_Vend_NTSC);	// irene
	// ok//
	// irene
	// has
	// to
	// check
	// why
	// w/o
	// vsync_start2/hsync_start2
	rtd_outl(IFD_108_agc_enable_sel_reg, 0x000000FE);	// agc enable
	drv_ifd_agc_loop1_fine_tune_en(IFD_DISABLE);
	drv_ifd_set_agc_loop1_peak_force(GET_ATV_IFD_AGCLOOP1_PEAKFORCE_EN());
	drv_ifd_set_agc_loop2_peak_force(IFD_DISABLE);
	drv_ifd_agc_loop1_kp_settings(GET_ATV_IFD_AGCLOOP1_KPGAIN());
	drv_ifd_agc_loop1_ki_settings(GET_ATV_IFD_AGCLOOP1_KIGAIN());
	drv_ifd_agc_loop1_pishift_settings(GET_ATV_IFD_AGCLOOP1_KPKISHIFT());
}

//=================================================================

/**
 * drv_ifd_set_video_pal
 *
 *
 * @param <mode>
 * @return {void}
 */
void drv_ifd_set_video_pal(bool scan_mode)
{
	UINT32 curTunerIFVal = 0;

	if (scan_mode) {
		curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_SCAN;
		IFD_DEBUG_MSG(IFD_MSG_SCANCH, "curTunerIFVal=%d\n",
					  (UINT32) curTunerIFVal);
		drv_ifd_set_cr_bpf_coef(IFD_ENABLE,
								&stIFDUserData.CRBpf_Table_SCAN[0]);
		drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)
									 stIFDUserData.CRInnerLpf_SCAN);
		drvif_ifd_set_scan_mode_detect_cr_lock(curTunerIFVal);
	} else {
		curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_DK;
		IFD_DEBUG_MSG(IFD_MSG_SETCH, "curTunerIFVal=%d\n",
					  (UINT32) curTunerIFVal);
		drv_ifd_set_cr_bpf_coef(IFD_ENABLE,
								&stIFDUserData.CRBpf_Table_DK[0]);
		drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)
									 stIFDUserData.CRInnerLpf_IDKL);
	}

	drv_ifd_outputlpf_vsync(IFD_OUTPUTLPF_VSYNC_START_PAL,
							IFD_OUTPUTLPF_VSYNC_END_PAL);
	drv_ifd_cr_vsync(IFD_CR_VSYNC_START_PAL, IFD_CR_VSYNC_END_PAL);	// cr
	// vsync
	drv_ifd_set_cr_nco(IFD_ENABLE,
					   drv_ifd_cal_nco(curTunerIFVal,
									   GET_ATV_IFD_CRSHIFT_EN()));

	if (scan_mode) {
		drv_ifd_eq_en(0);
		// drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_PAL_DK[0]);
	} else {
		drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_PAL_DK[0]);
		drv_ifd_eq_en(1);
	}
	drv_ifd_set_shaping_filter(GET_ATV_IFD_SHAPEFILTER_BW());

	if (stIFDUserData.tunerPara.tunerIFType == TUNER_IF_TYPE_NEG) {
		if (curTunerIFVal < 270000)
			drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
		else
			drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
	} else {
		if (curTunerIFVal < 270000)
			drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
		else
			drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
	}
	drv_ifd_input_filter_sel(stIFDUserData.InputFltPalD_En,
							 &stIFDUserData.InputFltTablePalD[0]);
	drv_ifd_set_pos_neg_mod(IFD_MODULATION_SEL_NEG);
	drv_ifd_video_outputlpf_coef_update(IFD_ENABLE,
										&stIFDUserData.VideoLpfPAL_BG[0]);
	drv_ifd_set_video_upsample_lp_sel((IFD_UPSAMPLE_LP_SEL) GET_ATV_IFD_VIDEO_UPSAMPLE_LPF_PAL());	// IFD_UPSAMPLE_LP_SEL_PAL
	drv_ifd_agc_loop1_pos_en(IFD_DISABLE);
	drv_ifd_agc_hsync_start1(IFD_VSmode1_Hstart_PAL, IFD_VSmode1_Hend_PAL);
	drv_ifd_agc_vsync_start1(IFD_VSmode1_Vstart_PAL, IFD_VSmode1_Vend_PAL);
	drv_ifd_agc_targ_val(GET_ATV_IFD_AGCLOOP1_MAXTARGET_PAL());
	drv_ifd_agc_data_target(GET_ATV_IFD_AGC_DATA_TARG());
	drv_ifd_mtd_set_thr(0x7, GET_ATV_IFD_AGC_DATA_TARG() >> 1,
						(GET_ATV_IFD_AGC_DATA_TARG() >> 1) - 0x30);
	rtd_outl(IFD_108_agc_enable_sel_reg, 0x000000FE);
	drv_ifd_agc_loop1_fine_tune_en(IFD_DISABLE);
	drv_ifd_set_cr_weighting_en(IFD_ENABLE);
	drv_ifd_cr_loop_filter_kp(GET_ATV_IFD_CR_PGAIN());
	drv_ifd_cr_loop_filter_ki(GET_ATV_IFD_CR_IGAIN());
	drv_ifd_set_agc_loop1_peak_force(GET_ATV_IFD_AGCLOOP1_PEAKFORCE_EN());
	drv_ifd_set_agc_loop2_peak_force(IFD_DISABLE);
	drv_ifd_agc_loop1_kp_settings(GET_ATV_IFD_AGCLOOP1_KPGAIN());
	drv_ifd_agc_loop1_ki_settings(GET_ATV_IFD_AGCLOOP1_KIGAIN());
	drv_ifd_agc_loop1_pishift_settings(GET_ATV_IFD_AGCLOOP1_KPKISHIFT());

}

//=================================================================

/**
 * drv_ifd_set_video_secaml
 *
 *
 * @param {void}
 * @return {void}
 */
void drv_ifd_set_video_secaml(bool scan_mode)
{
	UINT32 curTunerIFVal = 0;

	curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_L;
	IFD_DEBUG_MSG(IFD_MSG_SCANCH, "curTunerIFVal=%d\n",
				  (UINT32) curTunerIFVal);
	IFD_DEBUG_MSG(IFD_MSG_SETCH, "curTunerIFVal=%d\n",
				  (UINT32) curTunerIFVal);

	if (curTunerIFVal < 270000) {
		drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)
									 stIFDUserData.CRInnerLpf_IDKL);
	} else {
	}

	// if(scan_mode)
	drvif_ifd_set_scan_mode_detect_cr_lock(curTunerIFVal);

	// #ifdef CONFIG_IFD_CRBPF_NEW
	drv_ifd_input_filter_sel(stIFDUserData.InputFltPalD_En,
							 &stIFDUserData.InputFltTablePalD[0]);
	drv_ifd_outputlpf_vsync(IFD_OUTPUTLPF_VSYNC_START_SECAM,
							IFD_OUTPUTLPF_VSYNC_END_SECAM);
	drv_ifd_set_cr_bpf_coef(IFD_ENABLE, &stIFDUserData.CRBpf_Table_L[0]
							/*
							   stCrBpfArray[g_curIFMapIdx].CrBpf_Table */
						   );
	// #else
	// Set CR BPF according by PIF.
	// drv_ifd_initdata_by_tuner_if();
	// drv_ifd_set_cr_bpf_coef(IFD_ENABLE,
	// stCrBpfArray[g_curIFMapIdx].CrBpf_Table);
	// #endif
	// Set CR nco according by PIF.
	drv_ifd_set_cr_nco(IFD_ENABLE,
					   drv_ifd_cal_nco(curTunerIFVal,
									   GET_ATV_IFD_CRSHIFT_EN()));
	drv_ifd_cr_vsync(IFD_CR_VSYNC_START_SECAM, IFD_CR_VSYNC_END_SECAM);	// cr
	// vsync
	drv_ifd_eq_en(0);

	drv_ifd_set_shaping_filter(GET_ATV_IFD_SHAPEFILTER_BW());

	if (stIFDUserData.tunerPara.tunerIFType == TUNER_IF_TYPE_NEG) {
		if (curTunerIFVal < 270000)
			drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
		else
			drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
	} else {
		if (curTunerIFVal < 270000)
			drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
		else
			drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
	}
	drv_ifd_set_pos_neg_mod(IFD_MODULATION_SEL_POS);
	// #ifdef CONFIG_OUTPUTLPF_COEF_MODIFY_USE
	drv_ifd_video_outputlpf_coef_update(IFD_ENABLE,
										&stIFDUserData.VideoLpfSECAM[0]);
	// #else
	// #endif
	drv_ifd_set_video_upsample_lp_sel((IFD_UPSAMPLE_LP_SEL) GET_ATV_IFD_VIDEO_UPSAMPLE_LPF_PAL());	/* IFD_UPSAMPLE_LP_SEL_PAL
													 */
	drv_ifd_agc_loop1_pos_en(IFD_ENABLE);
	// drv_ifd_agc_loop2_pos_en(IFD_ENABLE); // irene have to check
	drv_ifd_agc_hsync_start1(IFD_VSmode1_Hstart_SECAM,
							 IFD_VSmode1_Hend_SECAM);
	drv_ifd_agc_vsync_start1(IFD_VSmode1_Vstart_SECAM,
							 IFD_VSmode1_Vend_SECAM);
	drv_ifd_agc_targ_val(GET_ATV_IFD_AGCLOOP1_MAXTARGET_SECAM());
	drv_ifd_agc_data_target(GET_ATV_IFD_AGC_DATA_TARG());
	drv_ifd_mtd_set_thr(0x7, GET_ATV_IFD_AGC_DATA_TARG() >> 1,
						(GET_ATV_IFD_AGC_DATA_TARG() >> 1) - 0x30);
	// drv_ifd_agc_loop2_target(GET_ATV_IFD_AGCLOOP2_MAXTARGET_SECAM());
	// drv_ifd_agc_hsync_start2(IFD_VSmode2_Hstart_SECAM,
	// IFD_VSmode2_Hend_SECAM);
	// drv_ifd_agc_vsync_start2(IFD_VSmode2_Vstart_SECAM,
	// IFD_VSmode2_Vend_SECAM);
	drv_ifd_agc_loop1_fine_tune_en(IFD_ENABLE);
	// drv_ifd_agc_loop2_fine_tune_en(IFD_ENABLE);
	drv_ifd_set_cr_weighting_en(IFD_ENABLE);
	drv_ifd_cr_loop_filter_kp(GET_ATV_IFD_CR_PGAIN());
	drv_ifd_cr_loop_filter_ki(GET_ATV_IFD_CR_IGAIN());
	drv_ifd_set_agc_loop1_peak_force(GET_ATV_IFD_AGCLOOP1_PEAKFORCE_EN());
	drv_ifd_set_agc_loop2_peak_force(IFD_DISABLE);
	drv_ifd_agc_loop1_kp_settings(GET_ATV_IFD_AGCLOOP1_KPGAIN());
	drv_ifd_agc_loop1_ki_settings(GET_ATV_IFD_AGCLOOP1_KIGAIN());
	drv_ifd_agc_loop1_pishift_settings(GET_ATV_IFD_AGCLOOP1_KPKISHIFT());
}

//=================================================================

/**
 * drv_ifd_set_video_secamla
 *
 *
 * @param {void}
 * @return {void}
 */
void drv_ifd_set_video_secamla(bool scan_mode)
{
	UINT32 curTunerIFVal = 0;

	curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_LA;
	IFD_DEBUG_MSG(IFD_MSG_SCANCH, "curTunerIFVal=%d\n",
				  (UINT32) curTunerIFVal);
	IFD_DEBUG_MSG(IFD_MSG_SETCH, "curTunerIFVal=%d\n",
				  (UINT32) curTunerIFVal);

	if (curTunerIFVal < 270000)
		drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)
									 stIFDUserData.CRInnerLpf_LA);

	// if(scan_mode)
	drvif_ifd_set_scan_mode_detect_cr_lock(curTunerIFVal);

	drv_ifd_input_filter_sel(stIFDUserData.InputFltPalD_En,
							 &stIFDUserData.InputFltTablePalD[0]);
	drv_ifd_outputlpf_vsync(IFD_OUTPUTLPF_VSYNC_START_SECAM,
							IFD_OUTPUTLPF_VSYNC_END_SECAM);
	drv_ifd_set_cr_bpf_coef(IFD_ENABLE, &stIFDUserData.CRBpf_Table_LA[0]
							/*
							   stCrBpfArray_SECAMLA[g_curIFMapIdx].CrBpf_Table
							 */
						   );
	drv_ifd_set_cr_nco(IFD_ENABLE,
					   drv_ifd_cal_nco(curTunerIFVal,
									   GET_ATV_IFD_CRSHIFT_EN()));
	drv_ifd_cr_vsync(IFD_CR_VSYNC_START_SECAM, IFD_CR_VSYNC_END_SECAM);	// cr
	// vsync
	drv_ifd_eq_en(0);

	drv_ifd_set_shaping_filter(GET_ATV_IFD_SHAPEFILTER_BW());

	if (stIFDUserData.tunerPara.tunerIFType == TUNER_IF_TYPE_POS) {
		if (curTunerIFVal < 270000)
			drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
		else
			drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
	} else {
		if (curTunerIFVal < 270000)
			drv_ifd_set_shaping_img(IFD_SHAPING_IMG_NEG);
		else
			drv_ifd_set_shaping_img(IFD_SHAPING_IMG_POS);
	}
	drv_ifd_set_pos_neg_mod(IFD_MODULATION_SEL_POS);
	drv_ifd_video_outputlpf_coef_update(IFD_ENABLE,
										&stIFDUserData.VideoLpfSECAM[0]);
	drv_ifd_set_video_upsample_lp_sel((IFD_UPSAMPLE_LP_SEL) GET_ATV_IFD_VIDEO_UPSAMPLE_LPF_PAL());	/* IFD_UPSAMPLE_LP_SEL_PAL
													 */
	drv_ifd_agc_diff_targ(GET_ATV_IFD_AGCLOOP1_DIFFTARGET());
	drv_ifd_agc_loop1_pos_en(IFD_ENABLE);
	drv_ifd_agc_hsync_start1(IFD_VSmode1_Hstart_SECAM,
							 IFD_VSmode1_Hend_SECAM);
	drv_ifd_agc_vsync_start1(IFD_VSmode1_Vstart_SECAM,
							 IFD_VSmode1_Vend_SECAM);
	drv_ifd_agc_targ_val(GET_ATV_IFD_AGCLOOP1_MAXTARGET_SECAM());
	drv_ifd_agc_data_target(GET_ATV_IFD_AGC_DATA_TARG());
	drv_ifd_mtd_set_thr(0x7, GET_ATV_IFD_AGC_DATA_TARG() >> 1,
						(GET_ATV_IFD_AGC_DATA_TARG() >> 1) - 0x30);
	drv_ifd_agc_loop1_fine_tune_en(IFD_ENABLE);
	drv_ifd_set_cr_weighting_en(IFD_ENABLE);
	drv_ifd_cr_loop_filter_kp(GET_ATV_IFD_CR_PGAIN());
	drv_ifd_cr_loop_filter_ki(GET_ATV_IFD_CR_IGAIN());
	drv_ifd_set_agc_loop1_peak_force(GET_ATV_IFD_AGCLOOP1_PEAKFORCE_EN());
	drv_ifd_set_agc_loop2_peak_force(IFD_DISABLE);
	drv_ifd_agc_loop1_kp_settings(GET_ATV_IFD_AGCLOOP1_KPGAIN());
	drv_ifd_agc_loop1_ki_settings(GET_ATV_IFD_AGCLOOP1_KIGAIN());
	drv_ifd_agc_loop1_pishift_settings(GET_ATV_IFD_AGCLOOP1_KPKISHIFT());

}

void drv_ifd_clamp_reset(IFD_CLAMP_RESET_POLARITY polarity)
{
	if (polarity == IFD_CLAMP_RESET_POS) {
		drv_ifd_set_clamping_thr_max(IFD_CLAMP_MID_THD_POS);
		drv_ifd_set_clamping_thr_min(IFD_CLAMP_MID_THD_POS);
		ScalerTimer_DelayXms(1);	// frank@0430 Change busy delay to save time
		drv_ifd_clamp_offset_hold(IFD_CLAMP_OFFSET_HOLD);
		ScalerTimer_DelayXms(1);	// frank@0430 Change busy delay to save time
		drv_ifd_clamp_offset_hold(IFD_CLAMP_OFFSET_NORMAL);
		drv_ifd_set_clamping_thr_max(IFD_CLAMP_MAX_THD);
		drv_ifd_set_clamping_thr_min(IFD_CLAMP_MIN_THD);
	} else {
		drv_ifd_set_clamping_thr_max(IFD_CLAMP_MID_THD_NEG);
		drv_ifd_set_clamping_thr_min(IFD_CLAMP_MID_THD_NEG);
		ScalerTimer_DelayXms(1);	// frank@0430 Change busy delay to save time
		drv_ifd_clamp_offset_hold(IFD_CLAMP_OFFSET_HOLD);
		ScalerTimer_DelayXms(1);	// frank@0430 Change busy delay to save time
		drv_ifd_clamp_offset_hold(IFD_CLAMP_OFFSET_NORMAL);
		drv_ifd_set_clamping_thr_max(IFD_CLAMP_MAX_THD);
		drv_ifd_set_clamping_thr_min(IFD_CLAMP_MIN_THD);
	}

}

void drvif_ifd_group_delay_mode(ATV_SOUND_STD_MAIN_SYSTEM mode, UINT32 VD_MODE)
{
	UINT32 curTunerIFVal = 0;
	IFD_DEBUG_MSG(IFD_MSG_INFO, "drvif_ifd_group_delay_mode(=%x)\n", (UINT32) mode);
	switch (mode) {
	case ATV_SOUND_BG_SYSTEM:
		switch (VD_MODE) {
		default:
			if (GET_ATV_TUNER_TYPE() == TUNER_LOW_IF) {
				drv_ifd_set_cr_bpf_coef(IFD_ENABLE,
										&stIFDUserData.
										CRBpf_Table_B[0]);
				drv_ifd_set_cr_nco(IFD_ENABLE,
								   drv_ifd_cal_nco
								   (stIFDUserData.tunerPara.tunerPIF_B,
									GET_ATV_IFD_CRSHIFT_EN()));
				curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_B;
			}
			drv_ifd_grp_delay_en(stIFDUserData.GRPdelayBG_En, &stIFDUserData.GRPdelayTableBG[0]);	// drv_ifd_group_delay_coe_table(GET_ATV_IFD_GRPDEALY_BG());
			drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)
										 stIFDUserData.CRInnerLpf_BGH);
			// IVES
			drv_ifd_video_outputlpf_coef_update(IFD_ENABLE,
												&stIFDUserData.
												VideoLpfPAL_BG[0]);
			drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_PAL_BG[0]);
			drv_ifd_eq_en(stIFDUserData.EQ_Table_PAL_BG_En);
			drv_ifd_input_filter_sel(stIFDUserData.InputFltPalG_En, &stIFDUserData.InputFltTablePalG[0]);	// 7HMz
			break;

		case  ZSECAM:
			if (GET_ATV_TUNER_TYPE() == TUNER_LOW_IF) {
				drv_ifd_set_cr_bpf_coef(IFD_ENABLE,
										&stIFDUserData.CRBpf_Table_B[0]);
				drv_ifd_set_cr_nco(IFD_ENABLE,
								   drv_ifd_cal_nco(stIFDUserData.tunerPara.tunerPIF_B,
												   GET_ATV_IFD_CRSHIFT_EN()));
			}
			curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_B;
			drv_ifd_grp_delay_en(stIFDUserData.GRPdelayBG_En, &stIFDUserData.GRPdelayTableBG[0]);	// drv_ifd_group_delay_coe_table(GET_ATV_IFD_GRPDEALY_BG());
			drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)stIFDUserData.CRInnerLpf_BGH);
			// IVES
			drv_ifd_video_outputlpf_coef_update(IFD_ENABLE,
												&stIFDUserData.VideoLpfPAL_BG[0]);
			drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_PAL_BG[0]);
			drv_ifd_eq_en(stIFDUserData.EQ_Table_PAL_BG_En);
			drv_ifd_input_filter_sel(stIFDUserData.InputFltPalG_En, &stIFDUserData.InputFltTablePalG[0]);	// 7HMz
			break;



		}
		break;
	case ATV_SOUND_I_SYSTEM:
		if (GET_ATV_TUNER_TYPE() == TUNER_LOW_IF) {
			drv_ifd_set_cr_bpf_coef(IFD_ENABLE,
									&stIFDUserData.
									CRBpf_Table_I[0]);
			drv_ifd_set_cr_nco(IFD_ENABLE,
							   drv_ifd_cal_nco
							   (stIFDUserData.tunerPara.tunerPIF_I,
								GET_ATV_IFD_CRSHIFT_EN()));
			curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_I;
		}
		drv_ifd_grp_delay_en(stIFDUserData.GRPdelayI_En, &stIFDUserData.GRPdelayTableI[0]);	// drv_ifd_group_delay_coe_table(GET_ATV_IFD_GRPDEALY_DKL());
		drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)
									 stIFDUserData.CRInnerLpf_IDKL);
		// IVES
		drv_ifd_video_outputlpf_coef_update(IFD_ENABLE,
											&stIFDUserData.
											VideoLpfPAL_I[0]);
		drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_PAL_I[0]);
		drv_ifd_eq_en(stIFDUserData.EQ_Table_PAL_I_En);
		drv_ifd_input_filter_sel(stIFDUserData.InputFltPalD_En, &stIFDUserData.InputFltTablePalD[0]);	// 8HMz

		break;
	case ATV_SOUND_DK_SYSTEM:
		switch (VD_MODE) {
		default:
			if (GET_ATV_TUNER_TYPE() == TUNER_LOW_IF) {
				drv_ifd_set_cr_bpf_coef(IFD_ENABLE,
										&stIFDUserData.
										CRBpf_Table_DK[0]);
				drv_ifd_set_cr_nco(IFD_ENABLE,
								   drv_ifd_cal_nco
								   (stIFDUserData.tunerPara.tunerPIF_DK,
									GET_ATV_IFD_CRSHIFT_EN()));
				curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_DK;
			}
			drv_ifd_grp_delay_en(stIFDUserData.GRPdelayDK_En, &stIFDUserData.GRPdelayTableDK[0]);	// drv_ifd_group_delay_coe_table(GET_ATV_IFD_GRPDEALY_DKL());
			drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)
										 stIFDUserData.CRInnerLpf_IDKL);
			// IVES
			drv_ifd_video_outputlpf_coef_update(IFD_ENABLE,
												&stIFDUserData.
												VideoLpfPAL_DKL[0]);
			drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_PAL_DK[0]);
			drv_ifd_eq_en(stIFDUserData.EQ_Table_PAL_DK_En);
			drv_ifd_input_filter_sel(stIFDUserData.InputFltPalD_En, &stIFDUserData.InputFltTablePalD[0]);	// 8HMz

		case ZPAL_60:
			if (GET_ATV_TUNER_TYPE() == TUNER_LOW_IF) {
				drv_ifd_set_cr_nco(IFD_ENABLE,
								   drv_ifd_cal_nco
								   (stIFDUserData.tunerPara.tunerPIF_DK,
									GET_ATV_IFD_CRSHIFT_EN()));
				drv_ifd_set_cr_bpf_coef(IFD_ENABLE, &stIFDUserData.CRBpf_Table_DK[0]);
				curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_DK;
			}
			drv_ifd_grp_delay_en(stIFDUserData.GRPdelayDK_En,  &stIFDUserData.GRPdelayTableDK[0]); //drv_ifd_group_delay_coe_table(GET_ATV_IFD_GRPDEALY_DKL());
			drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)stIFDUserData.CRInnerLpf_IDKL);
			drv_ifd_video_outputlpf_coef_update(IFD_ENABLE, &stIFDUserData.VideoLpfPAL_DKL[0]);
			drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_PAL_DK[0]);
			drv_ifd_eq_en(stIFDUserData.EQ_Table_PAL_DK_En);
			drv_ifd_input_filter_sel(stIFDUserData.InputFltPalD_En, &stIFDUserData.InputFltTablePalD[0]);//8HMz
			break;
		case ZSECAM:
			if (GET_ATV_TUNER_TYPE() == TUNER_LOW_IF) {
				drv_ifd_set_cr_bpf_coef(IFD_ENABLE,
										&stIFDUserData.
										CRBpf_Table_DK[0]);
				drv_ifd_set_cr_nco(IFD_ENABLE,
								   drv_ifd_cal_nco
								   (stIFDUserData.tunerPara.tunerPIF_DK,
									GET_ATV_IFD_CRSHIFT_EN()));
				curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_DK;
			}
			drv_ifd_grp_delay_en(stIFDUserData.GRPdelayDK_En, &stIFDUserData.GRPdelayTableDK[0]);	// drv_ifd_group_delay_coe_table(GET_ATV_IFD_GRPDEALY_DKL());
			drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)
										 stIFDUserData.CRInnerLpf_IDKL);
			// IVES
			drv_ifd_video_outputlpf_coef_update(IFD_ENABLE,
												&stIFDUserData.
												VideoLpfPAL_DKL[0]);
			drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_PAL_DK[0]);
			drv_ifd_eq_en(stIFDUserData.EQ_Table_PAL_DK_En);
			drv_ifd_input_filter_sel(stIFDUserData.InputFltPalD_En, &stIFDUserData.InputFltTablePalD[0]);	// 8HMz
			break;


		}
		break;
	case ATV_SOUND_MN_SYSTEM:
		if (GET_ATV_TUNER_TYPE() == TUNER_LOW_IF) {
			drv_ifd_set_cr_bpf_coef(IFD_ENABLE,
									&stIFDUserData.
									CRBpf_Table_MN[0]);
			drv_ifd_set_cr_nco(IFD_ENABLE,
							   drv_ifd_cal_nco
							   (stIFDUserData.tunerPara.tunerPIF_MN,
								GET_ATV_IFD_CRSHIFT_EN()));
			curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_MN;
		}
		drv_ifd_grp_delay_en(stIFDUserData.GRPdelayM_En,
							 &stIFDUserData.GRPdelayTableM[0]);
		drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)
									 stIFDUserData.CRInnerLpf_MN);
		drv_ifd_video_outputlpf_coef_update(IFD_ENABLE,
											&stIFDUserData.
											VideoLpfNTSC[0]);
		drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_NTSC[0]);
		drv_ifd_eq_en(stIFDUserData.EQ_Table_NTSC_En);
		drv_ifd_input_filter_sel(stIFDUserData.InputFltNtsc_En, &stIFDUserData.InputFltTableNtsc[0]);	// 6HMz
		break;
	case ATV_SOUND_L_SYSTEM:

		switch (VD_MODE) {
		case ZSECAML:
		case ZPAL_L:
			if (GET_ATV_TUNER_TYPE() == TUNER_LOW_IF) {
				drv_ifd_set_cr_nco(IFD_ENABLE,
								   drv_ifd_cal_nco
								   (stIFDUserData.tunerPara.tunerPIF_L,
									GET_ATV_IFD_CRSHIFT_EN()));

				drv_ifd_set_cr_bpf_coef(IFD_ENABLE, &stIFDUserData.CRBpf_Table_L[0]);
				curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_L;
			}
			drv_ifd_grp_delay_en(stIFDUserData.GRPdelayL_En,  &stIFDUserData.GRPdelayTableL[0]); ////drv_ifd_group_delay_coe_table(GET_ATV_IFD_GRPDEALY_DKL());
			drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)stIFDUserData.CRInnerLpf_IDKL);
			drv_ifd_video_outputlpf_coef_update(IFD_ENABLE, &stIFDUserData.VideoLpfSECAM[0]);
			drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_SECAM_L[0]);
			drv_ifd_eq_en(stIFDUserData.EQ_Table_SECAM_L_En);
			drv_ifd_input_filter_sel(stIFDUserData.InputFltPalD_En, &stIFDUserData.InputFltTablePalD[0]);//8HMz
			break;


		}
		break;

	case ATV_SOUND_LA_SYSTEM:


		if (GET_ATV_TUNER_TYPE() == TUNER_LOW_IF) {
			drv_ifd_set_cr_nco(IFD_ENABLE,
							   drv_ifd_cal_nco
							   (stIFDUserData.tunerPara.tunerPIF_LA,
								GET_ATV_IFD_CRSHIFT_EN()));
			drv_ifd_set_cr_bpf_coef(IFD_ENABLE, &stIFDUserData.CRBpf_Table_LA[0]);
			curTunerIFVal = stIFDUserData.tunerPara.tunerPIF_LA;

		}
		drv_ifd_grp_delay_en(stIFDUserData.GRPdelayLA_En,  &stIFDUserData.GRPdelayTableLA[0]); //drv_ifd_group_delay_coe_table(GET_ATV_IFD_GRPDEALY_DKL());
		drv_ifd_set_cr_inner_lpf_sel((IFD_CR_INNER_LPF)stIFDUserData.CRInnerLpf_IDKL);
		drv_ifd_video_outputlpf_coef_update(IFD_ENABLE, &stIFDUserData.VideoLpfSECAM[0]);
		drv_ifd_set_eq_coef(&stIFDUserData.EQ_Table_SECAM_LA[0]);
		drv_ifd_eq_en(stIFDUserData.EQ_Table_SECAM_LA_En);
		drv_ifd_input_filter_sel(stIFDUserData.InputFltPalD_En, &stIFDUserData.InputFltTablePalD[0]);//8HMz
		break;

	default:
		IFD_DEBUG_MSG(IFD_MSG_INFO, "drvif_ifd_group_delay_mode unknow =%x \n", (UINT32) mode);


	}

	drvif_ifd_set_scan_mode_detect_cr_lock(curTunerIFVal);
}

UINT32 drv_ifd_cal_nco(UINT32 pif_freq, bool cr_shift_enable)
{
	UINT32 nco_value = 0, pif_shit = 0, pif_shit_nco = 0;

	if (cr_shift_enable == IFD_ENABLE) {
		// disable CR shift
		drv_ifd_cr_shift_en(IFD_DISABLE);
		drv_ifd_cr_fm_en(IFD_DISABLE);

		if (pif_freq > 270000) {
			pif_freq = 540000 - pif_freq;
		}

		if (pif_freq >= GET_ATV_IFD_CRSHIFT_TARGET_FREQ()) {
			nco_value = ((UINT32)(pif_freq) / 100);
			nco_value <<= 20;
			nco_value = nco_value / 5400;
		} else {
			// shift LIF to 16M
			pif_shit = GET_ATV_IFD_CRSHIFT_TARGET_FREQ() - pif_freq;
			pif_shit_nco = ((UINT32)(pif_shit) / 100);
			pif_shit_nco <<= 20;
			pif_shit_nco = pif_shit_nco / 5400;
			nco_value =
				((UINT32)(GET_ATV_IFD_CRSHIFT_TARGET_FREQ()) /
				 100);
			nco_value <<= 20;
			nco_value = nco_value / 5400;
			drv_ifd_cr_shift_nco(pif_shit_nco);
			drv_ifd_cr_shift_polar(IFD_CR_SHIFT_POLAR_POS);
			drv_ifd_cr_shift_en(IFD_ENABLE);
		}
	} else {
		if (pif_freq > 270000) {
			pif_freq = 540000 - pif_freq;
		}
		nco_value = ((UINT32)(pif_freq) / 100);
		nco_value <<= 20;
		nco_value = nco_value / 5400;
		drv_ifd_cr_shift_en(IFD_DISABLE);
	}
	return ((UINT32)(nco_value & 0x0fffff));

}

void drv_ifd_shift_nco(INT32 pif_freq_shift)
{
	UINT32 shift_en_backup = 0;
	UINT32 pif_freq_backup = 0, pif_freq = 0, pif_shit = 0;
	UINT32 nco_value = 0, pif_shit_nco = 0;

	shift_en_backup = drv_ifd_cr_shift_en_getinfo();
	pif_freq_backup = drv_ifd_if_frequency_getinfo();
	pif_freq = pif_freq_backup + pif_freq_shift;

	if (shift_en_backup == IFD_ENABLE) {
		// disable CR shift
		drv_ifd_cr_shift_en(IFD_DISABLE);
		drv_ifd_cr_fm_en(IFD_DISABLE);

		if (pif_freq > 270000) {
			pif_freq = 540000 - pif_freq;
		}

		if (pif_freq >= GET_ATV_IFD_CRSHIFT_TARGET_FREQ()) {
			nco_value = ((UINT32)(pif_freq) / 100);
			nco_value <<= 20;
			nco_value = nco_value / 5400;
		} else {
			// shift LIF to 16M
			pif_shit = GET_ATV_IFD_CRSHIFT_TARGET_FREQ() - pif_freq;
			pif_shit_nco = ((UINT32)(pif_shit) / 100);
			pif_shit_nco <<= 20;
			pif_shit_nco = pif_shit_nco / 5400;
			nco_value =
				((UINT32)(GET_ATV_IFD_CRSHIFT_TARGET_FREQ()) /
				 100);
			nco_value <<= 20;
			nco_value = nco_value / 5400;
			drv_ifd_cr_shift_nco(pif_shit_nco);
			drv_ifd_cr_shift_polar(IFD_CR_SHIFT_POLAR_POS);
			drv_ifd_cr_shift_en(IFD_ENABLE);
		}
	} else {
		if (pif_freq > 270000) {
			pif_freq = 540000 - pif_freq;
		}
		nco_value = ((UINT32)(pif_freq) / 100);
		nco_value <<= 20;
		nco_value = nco_value / 5400;
		drv_ifd_cr_shift_en(IFD_DISABLE);
	}
}

UINT32 drv_ifd_if_frequency_getinfo(void)
{
	UINT32 shift_nco = 0, pif_freq = 0, pif_shit = 0;

	shift_nco = drv_ifd_cr_shift_nco_getinfo();
	pif_shit = shift_nco * 5400;
	pif_shit = pif_shit >> 20;
	pif_shit = pif_shit * 100;
	pif_freq = GET_ATV_IFD_CRSHIFT_TARGET_FREQ() - pif_shit;
	return pif_freq;
}

INT32 drv_ifd_get_cr_offset_100hz()	// drvif
{
	UINT32 ifd_offset = 0;
	INT32 shift_freq;
	INT32 divider_offset = 0;

	// IFD_DEBUG_MSG(IFD_MSG_SCANCH, "drv_ifd_get_cr_offset_100hz()\n");

	ifd_offset = drv_ifd_get_cr_freq_offset();
	ifd_offset = ifd_offset >> 8;

	if (ifd_offset > 2048) {
		shift_freq = -(((4096 - ifd_offset) * 54000) >> 16);	// kHz
		shift_freq = -shift_freq;
		divider_offset = shift_freq * 10;
	} else {
		shift_freq = (ifd_offset * 54000) >> 16;	// kHz
		shift_freq = -shift_freq;
		divider_offset = shift_freq * 10;
	}

	return divider_offset;

}

bool drvif_ifd_get_agc_lock()
{
	return drv_ifd_agc_get_loop1_lock();
}
UINT16 drvif_ifd_get_noise_status()
{
	return drv_ifd_get_noise_status();
}
//=================================================================
/**
 * drvif_ifd_scan_mode_detect_cr_lock_init(void)
 *
 *the initial setting of cr power detect
 *
 * @param <detect_value><usnum>
 * @return None
 */

void drvif_ifd_set_scan_mode_detect_cr_lock(UINT32 curr_tuner_if_freq)
{
	UINT8 get_ifd_adc_clock, nco_count;
	UINT32 ifd_adc_clock = 0;
	UINT32 if_nco = 0;
	UINT32  tuner_if_freq = 0;
	UINT32 noise_point[8];
	UINT32  if_noise_point[8];

	get_ifd_adc_clock = GET_ATV_IFD_ADCINPUT_CLOCK();
	switch (get_ifd_adc_clock) {
	case IFD_CLK_RATE_108M:
		ifd_adc_clock = 108;
		break;
	case IFD_CLK_RATE_54M:
		ifd_adc_clock = 54;
		break;
	case IFD_CLK_RATE_135M:
		ifd_adc_clock = 135;
		break;
	case IFD_CLK_RATE_162M:
		ifd_adc_clock = 162;
		break;
	}
	ifd_adc_clock = ifd_adc_clock * 1000;
	tuner_if_freq = curr_tuner_if_freq / 10;
	if_nco = ((tuner_if_freq * 65536) / ifd_adc_clock);

	IFD_DEBUG_MSG(IFD_MSG_SCANCH, "[CR_Power]ifd_adc_clock(%d)\n", ifd_adc_clock);
	IFD_DEBUG_MSG(IFD_MSG_SCANCH, "[CR_Power]curr_tuner_if_freq(%d)\n", curr_tuner_if_freq);
	IFD_DEBUG_MSG(IFD_MSG_SCANCH, "[CR_Power]tuner_if_freq(%d)\n", tuner_if_freq);
	IFD_DEBUG_MSG(IFD_MSG_SCANCH, "[CR_Power]if_nco(%x)\n", if_nco);

	rtd_outl(IFD_108_nco_if_reg, ((if_nco << 16) | 0x0));

	//set reference tone position
	if_noise_point[0] = +1000; //if freq + 1000 (kHz)
	if_noise_point[1] = +1300;
	if_noise_point[2] = +1500;
	if_noise_point[3] = +1700;
	if_noise_point[4] = +2000;
	if_noise_point[5] = +2300;
	if_noise_point[6] = +2500;
	if_noise_point[7] = +2700;

	for (nco_count = 0; nco_count <= 7; nco_count++) {
		noise_point[nco_count] = (((tuner_if_freq + if_noise_point[nco_count]) * 65536) / ifd_adc_clock);
		IFD_DEBUG_MSG(IFD_MSG_SCANCH, "[CR_Power]if_noise_point[%d](%x)\n", nco_count, noise_point[nco_count]);
	}

	//set reference tone nco
	rtd_outl(IFD_108_nco_sequential1_reg, ((noise_point[1] << 16) | (noise_point[0])));
	rtd_outl(IFD_108_nco_sequential2_reg, ((noise_point[3] << 16) | (noise_point[2])));
	rtd_outl(IFD_108_nco_sequential3_reg, ((noise_point[5] << 16) | (noise_point[4])));
	rtd_outl(IFD_108_nco_sequential4_reg, ((noise_point[7] << 16) | (noise_point[6])));

}
//=================================================================
/**
 * drvif_ifd_scan_mode_detect_cr_lock(UINT8 mode)
 *
 *for the auto scan flow for improve the cr lock
 *
 * @param <detect_value><usnum>
 * @return {1:lock ,0:unlock}
 */

UINT8 drvif_ifd_scan_mode_detect_cr_lock(void) //Use only for scan mode
{
	ifd_108_cr_lock_RBUS cr_lock_rbus_data;


	if (GET_ATV_IFD_CRPOWER_LOCK_EN()) {
		drv_ifd_set_power_diff_cr_lock(GET_ATV_IFD_CRPOWER_LOCK_EN());

		ScalerTimer_DelayXms(10);
		cr_lock_rbus_data.regValue = rtd_inl(IFD_108_cr_lock_reg);
		if (cr_lock_rbus_data.cr_lock == 1) {
			IFD_DEBUG_MSG(IFD_MSG_SETCH, "[CR_Power]input_power_detect_done=(%d)\n", drv_ifd_get_cr_input_power_done_status());
			IFD_DEBUG_MSG(IFD_MSG_SETCH, "[CR_Power]cr lock power=(%d)\n", drv_ifd_get_cr_input_power_diff());
			drv_ifd_set_power_diff_cr_lock(IFD_DISABLE);
			return 1;
		} else {
			IFD_DEBUG_MSG(IFD_MSG_SETCH, "[CR_Power]input_power_detect_done=(%d)\n", drv_ifd_get_cr_input_power_done_status());
			IFD_DEBUG_MSG(IFD_MSG_SETCH, "[CR_Power]cr unlock power=(%d)\n", drv_ifd_get_cr_input_power_diff());
			drv_ifd_set_power_diff_cr_lock(IFD_DISABLE);
			return 0;
		}
	}
	IFD_DEBUG_MSG(IFD_MSG_SETCH, "[CR_Power]   cr detect lock fail \n");
	return 1;
}
