#include "ifd_new.h"

//=================================================================
/**
 * drv_ifd_set_cr_bpf_coef
 *
 *
 * @param <cr_bpf_en><table>
 * @return { void }
 */
void drv_ifd_set_cr_bpf_coef(bool cr_bpf_en, UINT16 *table)
{
	ifd_108_cr_bpf_sel_RBUS cr_bpf_sel_rbus_data;
	UINT32 i;

	cr_bpf_sel_rbus_data.regValue = rtd_inl(IFD_108_cr_bpf_sel_reg);
	cr_bpf_sel_rbus_data.cr_bpf_en = 0;
	rtd_outl(IFD_108_cr_bpf_sel_reg, cr_bpf_sel_rbus_data.regValue);
	for (i = 0; i < CR_BPF_TABLE_SIZE; i++) {
		//cr_bpf_sel_rbus_data.regValue = 0;
		//rtd_outl(IFD_108_CR_BPF_SEL_reg, cr_bpf_sel_rbus_data.regValue);
		cr_bpf_sel_rbus_data.cr_bpf_coe_modify_en = 1;
		cr_bpf_sel_rbus_data.cr_bpf_coe_tap = i;
		cr_bpf_sel_rbus_data.cr_bpf_coe = table[i];
		rtd_outl(IFD_108_cr_bpf_sel_reg, cr_bpf_sel_rbus_data.regValue);
	}
	cr_bpf_sel_rbus_data.cr_bpf_coe_modify_en = 0;
	cr_bpf_sel_rbus_data.cr_bpf_coe_tap = 0;
	cr_bpf_sel_rbus_data.cr_bpf_coe = 0;
	rtd_outl(IFD_108_cr_bpf_sel_reg, cr_bpf_sel_rbus_data.regValue);
	drv_ifd_cr_bpf_en(cr_bpf_en);
	// drv_ifd_cr_inner_lpf_en(cr_bpf_en);
}
/*=============================================================*/
/**
 * drv_ifd_cr_bpf_en
 *
 *
 * @param <cr_bpf_en>
 * @return { void }
 */
void drv_ifd_cr_bpf_en(bool cr_bpf_en)
{
	ifd_108_cr_bpf_sel_RBUS cr_bpf_sel_rbus_data;
	cr_bpf_sel_rbus_data.regValue = rtd_inl(IFD_108_cr_bpf_sel_reg);
	cr_bpf_sel_rbus_data.cr_delay = 6;	//default
	cr_bpf_sel_rbus_data.cr_bpf_en = cr_bpf_en;
	rtd_outl(IFD_108_cr_bpf_sel_reg, cr_bpf_sel_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_cr_bpf_en_get_info
 *
 *
 * @param <void>
 * @return { cr_bpf_en }
 */
UINT8 drv_ifd_cr_bpf_en_get_info(void)
{
	ifd_108_cr_bpf_sel_RBUS cr_bpf_sel_rbus_data;

	cr_bpf_sel_rbus_data.regValue = rtd_inl(IFD_108_cr_bpf_sel_reg);
	return (cr_bpf_sel_rbus_data.cr_bpf_en);
}

/*=============================================================*/
/**
 * drv_ifd_cr_inner_lpf_en
 *
 *
 * @param <cr_inner_lpf_en>
 * @return { void }
 */
void drv_ifd_cr_inner_lpf_en(bool cr_inner_lpf_en)
{
	ifd_108_cr_bpf_sel_RBUS cr_bpf_sel_rbus_data;

	cr_bpf_sel_rbus_data.regValue = rtd_inl(IFD_108_cr_bpf_sel_reg);
	cr_bpf_sel_rbus_data.cr_inner_lpf_en = cr_inner_lpf_en;
	rtd_outl(IFD_108_cr_bpf_sel_reg, cr_bpf_sel_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_cr_inner_lpf_en_get_info
 *
 *
 * @param <void>
 * @return { cr_inner_lpf_en }
 */
UINT8 drv_ifd_cr_inner_lpf_en_get_info(void)
{
	ifd_108_cr_bpf_sel_RBUS cr_bpf_sel_rbus_data;

	cr_bpf_sel_rbus_data.regValue = rtd_inl(IFD_108_cr_bpf_sel_reg);
	return (cr_bpf_sel_rbus_data.cr_inner_lpf_en);
}
void drv_ifd_cr_loop_filter_kp_st3(UINT8 cr_pgain)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	cr_pgain_rbus_data.cr_st4_kp = cr_pgain;
	rtd_outl(IFD_108_cr_pgain_reg, cr_pgain_rbus_data.regValue);
}
UINT8 drv_ifd_cr_loop_filter_kp_st3_get_info(void)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	return cr_pgain_rbus_data.cr_st4_kp;
}
void drv_ifd_cr_loop_filter_ki_st3(UINT8 cr_igain)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	cr_pgain_rbus_data.cr_st4_ki = cr_igain;
	rtd_outl(IFD_108_cr_pgain_reg, cr_pgain_rbus_data.regValue);
}
UINT8 drv_ifd_cr_loop_filter_ki_st3_get_info(void)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	return cr_pgain_rbus_data.cr_st4_ki;
}
void drv_ifd_cr_loop_filter_kp_st2(UINT8 cr_pgain)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	cr_pgain_rbus_data.cr_st2_kp = cr_pgain;
	rtd_outl(IFD_108_cr_pgain_reg, cr_pgain_rbus_data.regValue);
}
UINT8 drv_ifd_cr_loop_filter_kp_st2_get_info(void)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	return cr_pgain_rbus_data.cr_st2_kp;
}

void drv_ifd_cr_loop_filter_ki_st2(UINT8 cr_igain)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	cr_pgain_rbus_data.cr_st2_ki = cr_igain;
	rtd_outl(IFD_108_cr_pgain_reg, cr_pgain_rbus_data.regValue);
}
UINT8 drv_ifd_cr_loop_filter_ki_st2_get_info(void)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	return cr_pgain_rbus_data.cr_st2_ki;
}

void drv_ifd_cr_loop_filter_kp_st0(UINT8 cr_pgain)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	cr_pgain_rbus_data.cr_st0_kp = cr_pgain;
	rtd_outl(IFD_108_cr_pgain_reg, cr_pgain_rbus_data.regValue);
}
UINT8 drv_ifd_cr_loop_filter_kp_st0_get_info(void)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	return cr_pgain_rbus_data.cr_st0_kp;
}

void drv_ifd_cr_loop_filter_ki_st0(UINT8 cr_igain)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	cr_pgain_rbus_data.cr_st0_ki = cr_igain;
	rtd_outl(IFD_108_cr_pgain_reg, cr_pgain_rbus_data.regValue);
}
UINT8 drv_ifd_cr_loop_filter_ki_st0_get_info(void)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	return cr_pgain_rbus_data.cr_st0_ki;
}

void drv_ifd_cr_loop_filter_kp(UINT8 cr_pgain)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	cr_pgain_rbus_data.cr_pgain = cr_pgain;
	rtd_outl(IFD_108_cr_pgain_reg, cr_pgain_rbus_data.regValue);
}
UINT8 drv_ifd_cr_kp_get_info(void)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	return (cr_pgain_rbus_data.cr_pgain);
}
void drv_ifd_cr_loop_filter_ki(UINT8 cr_igain)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	cr_pgain_rbus_data.cr_igain = cr_igain;
	rtd_outl(IFD_108_cr_pgain_reg, cr_pgain_rbus_data.regValue);
}
UINT8 drv_ifd_cr_ki_get_info(void)
{
	ifd_108_cr_pgain_RBUS cr_pgain_rbus_data;

	cr_pgain_rbus_data.regValue = rtd_inl(IFD_108_cr_pgain_reg);
	return (cr_pgain_rbus_data.cr_igain);
}
/*=============================================================*/
/**
 * drv_ifd_set_cr_lock_freq_thr
 *
 *
 * @param <thr>
 * @return <void>
 */
void drv_ifd_set_cr_lock_freq_thr(UINT16 thr)
{
	ifd_108_cr_lock_RBUS cr_lock_rbus_data;

	cr_lock_rbus_data.regValue = rtd_inl(IFD_108_cr_lock_reg);
	cr_lock_rbus_data.cr_lock_freq_thr = thr & 0xFFF;
	if (thr == 0xfff)
		cr_lock_rbus_data.cr_lock_with_freq = 0;
	else
		cr_lock_rbus_data.cr_lock_with_freq = 1;
	rtd_outl(IFD_108_cr_lock_reg, cr_lock_rbus_data.regValue);

}
/*=============================================================*/
/**
 * drv_ifd_get_cr_lock_freq_thr
 *
 *
 * @param <void>
 * @return <thr>
 */
UINT16 drv_ifd_get_cr_lock_freq_thr(void)
{
	ifd_108_cr_lock_RBUS cr_lock_rbus_data;

	cr_lock_rbus_data.regValue = rtd_inl(IFD_108_cr_lock_reg);

	return cr_lock_rbus_data.cr_lock_freq_thr;
}
/*=============================================================*/
/**
 * drv_ifd_set_cr_lock_with_freq
 *
 *
 * @param <enable>
 * @return <void>
 */
void drv_ifd_set_cr_lock_with_freq(bool enable)
{
	ifd_108_cr_lock_RBUS cr_lock_rbus_data;

	cr_lock_rbus_data.regValue = rtd_inl(IFD_108_cr_lock_reg);
	cr_lock_rbus_data.cr_lock_with_freq = enable;
	rtd_outl(IFD_108_cr_lock_reg, cr_lock_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_set_cr_lock_with_hsync
 *
 *
 * @param <enable>
 * @return <void>
 */
void drv_ifd_set_cr_lock_with_hsync(bool enable)
{
	ifd_108_cr_lock_RBUS cr_lock_rbus_data;

	cr_lock_rbus_data.regValue = rtd_inl(IFD_108_cr_lock_reg);
	cr_lock_rbus_data.cr_lock_with_hsync = enable;
	rtd_outl(IFD_108_cr_lock_reg, cr_lock_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_get_cr_cos_sampler_avg
 *
 *
 * @param <void>
 * @return <cos_sampler_avg>
 */
UINT8 drv_ifd_get_cr_cos_sampler_avg()
{

	ifd_108_cr_lock_RBUS cr_lock_rbus_data;

	cr_lock_rbus_data.regValue = rtd_inl(IFD_108_cr_lock_reg);

	return (UINT8)cr_lock_rbus_data.cr_lock_ref;
}
/*=============================================================*/
/**
 * drv_ifd_get_cr_lock_status
 *
 *
 * @param <void>
 * @return <lock_status>
 */
bool drv_ifd_get_cr_lock_status()
{
#if 1
	ifd_108_cr_lock_RBUS cr_lock_rbus_data;

	cr_lock_rbus_data.regValue = rtd_inl(IFD_108_cr_lock_reg);

	return cr_lock_rbus_data.cr_lock;
#else
	bool  cr_double_lock = 0;
	cr_double_lock = drvif_ifd_scan_mode_detect_cr_lock();
	if (cr_double_lock == 1)
		return 1;
	else
		return 0;


#endif
}
/*=============================================================*/
/**
 * drv_ifd_set_cr_nco
 *
 *
 * @param <para>
 * @return { void }
 */
void drv_ifd_set_cr_nco(bool enable, UINT32 para)
{
	ifd_108_cr_nco_fix_data_RBUS cr_nco_fix_data_rbus;

	cr_nco_fix_data_rbus.regValue = rtd_inl(IFD_108_cr_nco_fix_data_reg);
	cr_nco_fix_data_rbus.cr_ncoerr_en = enable;
	cr_nco_fix_data_rbus.cr_nco_fix_data = para & 0xFFFFF;
	rtd_outl(IFD_108_cr_nco_fix_data_reg, cr_nco_fix_data_rbus.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_get_cr_nco
 *
 *
 * @param  { void }
 * @return  <para>
 */
UINT32 drv_ifd_get_cr_nco(void)
{
	ifd_108_cr_nco_fix_data_RBUS cr_nco_fix_data_rbus;

	cr_nco_fix_data_rbus.regValue = rtd_inl(IFD_108_cr_nco_fix_data_reg);
	return (cr_nco_fix_data_rbus.cr_nco_fix_data & 0xFFFFF);
}

/*=============================================================*/
/**
 * drv_ifd_get_cr_freq_offset
 *
 *
 * @param <void>
 * @return <cr_freq_offset>
 */
UINT32 drv_ifd_get_cr_freq_offset(void)
{
	ifd_108_cr_freq_status_RBUS cr_freq_status_rbus_data;

	cr_freq_status_rbus_data.regValue = rtd_inl(IFD_108_cr_freq_status_reg);

	return cr_freq_status_rbus_data.cr_freq_status;
}
/*=============================================================*/
/**
 * drv_ifd_set_cr_weighting_en
 *
 *
 * @param <cr_weight_en>
 * @return { void }
 */
void drv_ifd_set_cr_weighting_en(bool cr_weight_en)
{
	ifd_108_cr_weight_en_RBUS cr_weight_en_rbus_data;

	cr_weight_en_rbus_data.regValue = rtd_inl(IFD_108_cr_weight_en_reg);
	cr_weight_en_rbus_data.cr_weighting_en = cr_weight_en;
	rtd_outl(IFD_108_cr_weight_en_reg, cr_weight_en_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_cr_weighting_en_get_info
 *
 *
 * @param <void>
 * @return { cr_weight_en }
 */
UINT8 drv_ifd_cr_weighting_en_get_info(void)
{
	ifd_108_cr_weight_en_RBUS cr_weight_en_rbus_data;

	cr_weight_en_rbus_data.regValue = rtd_inl(IFD_108_cr_weight_en_reg);
	return (cr_weight_en_rbus_data.cr_weighting_en);
}

/*=============================================================*/
/**
 * drv_ifd_set_cr_weighting_settings
 *
 *
 * @param <cr_weighting_cr_lock_dis><cr_weight_max_decrease><cr_weight_shift>
 * @return { void }
 */
void drv_ifd_set_cr_weighting_settings(IFD_CR_WEIGHT_CR_LOCK cr_weighting_cr_lock_dis, IFD_CR_WEIGHT_MAX_DECREASE cr_weight_max_decrease, IFD_CR_WEIGHT_SHIFT cr_weight_shift)
{
	ifd_108_cr_weight_en_RBUS cr_weight_en_rbus_data;

	cr_weight_en_rbus_data.regValue = rtd_inl(IFD_108_cr_weight_en_reg);
	cr_weight_en_rbus_data.cr_weighting_cr_lock_dis = cr_weighting_cr_lock_dis;
	cr_weight_en_rbus_data.cr_weight_max_decrease = cr_weight_max_decrease;
	cr_weight_en_rbus_data.cr_weight_shift = cr_weight_shift;
	rtd_outl(IFD_108_cr_weight_en_reg, cr_weight_en_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_set_cr_weighting_speed
 *
 *
 * @param <cr_weight_max_decrease>
 * @return { void }
 */
void drv_ifd_set_cr_weighting_speed(IFD_CR_WEIGHT_MAX_DECREASE cr_weight_max_decrease)
{
	ifd_108_cr_weight_en_RBUS cr_weight_en_rbus_data;

	cr_weight_en_rbus_data.regValue = rtd_inl(IFD_108_cr_weight_en_reg);
	cr_weight_en_rbus_data.cr_weight_max_decrease = cr_weight_max_decrease;
	rtd_outl(IFD_108_cr_weight_en_reg, cr_weight_en_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_set_cr_weighting_speed_get_info
 *
 *
 * @param <void>
 * @return { cr_weight_max_decrease }
 */
UINT8 drv_ifd_set_cr_weighting_speed_get_info(void)
{
	ifd_108_cr_weight_en_RBUS cr_weight_en_rbus_data;

	cr_weight_en_rbus_data.regValue = rtd_inl(IFD_108_cr_weight_en_reg);
	return (cr_weight_en_rbus_data.cr_weight_max_decrease);
}
/*=============================================================*/
/**
 * drv_ifd_get_cr_sin_sample_d
 *
 *
 * @param {void}
 * @return <sin_sample_d>
 */
UINT16 drv_ifd_get_cr_sin_sample_d(void)
{
	ifd_108_cr_sine_part_inner_lpf_RBUS cr_sine_part_inner_lpf_rbus_data;

	cr_sine_part_inner_lpf_rbus_data.regValue = rtd_inl(IFD_108_cr_sine_part_inner_lpf_reg);

	return (UINT16)cr_sine_part_inner_lpf_rbus_data.sin_sample_d;
}
/*=============================================================*/
/**
 * drv_ifd_set_cr_inner_lpf_sel
 *
 *
 * @param <inner_lpf_sel>
 * @return { void }
 */
void drv_ifd_set_cr_inner_lpf_sel(IFD_CR_INNER_LPF inner_lpf_sel)
{
	ifd_108_cr_bpf_sel_RBUS cr_sine_part_inner_lpf_rbus_data;

	cr_sine_part_inner_lpf_rbus_data.regValue = rtd_inl(IFD_108_cr_bpf_sel_reg);
	cr_sine_part_inner_lpf_rbus_data.cr_inner_lpf_sel = inner_lpf_sel;

	rtd_outl(IFD_108_cr_bpf_sel_reg, cr_sine_part_inner_lpf_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_get_cr_inner_lpf_sel
 *
 *
 * @param { void }
 * @return  <inner_lpf_sel>
 */
IFD_CR_INNER_LPF drv_ifd_get_cr_inner_lpf_sel(void)
{
	ifd_108_cr_bpf_sel_RBUS cr_sine_part_inner_lpf_rbus_data;

	cr_sine_part_inner_lpf_rbus_data.regValue = rtd_inl(IFD_108_cr_bpf_sel_reg);

	return (IFD_CR_INNER_LPF)cr_sine_part_inner_lpf_rbus_data.cr_inner_lpf_sel;
}
/*=============================================================*/
/**
 * drv_ifd_cr_error_thd
 *
 *
 * @param <err_thd>
 * @return { void }
 */
void drv_ifd_cr_error_thd(UINT8 err_thd)
{
	ifd_108_cr_lock_thd_RBUS cr_lock_thd_rbus_data;

	cr_lock_thd_rbus_data.regValue = rtd_inl(IFD_108_cr_lock_thd_reg);
	cr_lock_thd_rbus_data.cr_lock_thd = err_thd;
	rtd_outl(IFD_108_cr_lock_thd_reg, cr_lock_thd_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_cr_error_thd_get_info
 *
 *
 * @param <void>
 * @return { err_thd }
 */
UINT8 drv_ifd_cr_error_thd_get_info(void)
{
	ifd_108_cr_lock_thd_RBUS cr_lock_thd_rbus_data;

	cr_lock_thd_rbus_data.regValue = rtd_inl(IFD_108_cr_lock_thd_reg);
	return (cr_lock_thd_rbus_data.cr_lock_thd);
}
/*=============================================================*/
/**
 * drv_ifd_cr_auto_reset_en
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_cr_auto_reset_en(bool enable)
{
	ifd_108_cr_auto_reset_en_RBUS cr_auto_reset_en_rbus_data;

	cr_auto_reset_en_rbus_data.regValue = rtd_inl(IFD_108_cr_auto_reset_en_reg);
	cr_auto_reset_en_rbus_data.cr_auto_reset_en = enable;
	rtd_outl(IFD_108_cr_auto_reset_en_reg, cr_auto_reset_en_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_cr_auto_reset_en_get_info
 *
 *
 * @param <void>
 * @return { enable }
 */
bool drv_ifd_cr_auto_reset_en_get_info(void)
{
	ifd_108_cr_auto_reset_en_RBUS cr_auto_reset_en_rbus_data;

	cr_auto_reset_en_rbus_data.regValue = rtd_inl(IFD_108_cr_auto_reset_en_reg);
	return (cr_auto_reset_en_rbus_data.cr_auto_reset_en);
}
//=================================================================
//CR Phase Inverse
//=================================================================
void drv_ifd_cr_phase_inverse_en(bool enable)
{
	ifd_108_cr_phase_inverse_RBUS cr_phase_inverse_rbus_data;

	cr_phase_inverse_rbus_data.regValue = rtd_inl(IFD_108_cr_phase_inverse_reg);
	cr_phase_inverse_rbus_data.cr_phase_inverse_en = enable;
	rtd_outl(IFD_108_cr_phase_inverse_reg, cr_phase_inverse_rbus_data.regValue);
}
bool drv_ifd_cr_phase_inverse_en_get_info(void)
{
	ifd_108_cr_phase_inverse_RBUS cr_phase_inverse_rbus_data;

	cr_phase_inverse_rbus_data.regValue = rtd_inl(IFD_108_cr_phase_inverse_reg);
	return (cr_phase_inverse_rbus_data.cr_phase_inverse_en);
}
void drv_ifd_cr_phase_inverse_thr(UINT16 thr)
{
	ifd_108_cr_phase_inverse_RBUS cr_phase_inverse_rbus_data;

	cr_phase_inverse_rbus_data.regValue = rtd_inl(IFD_108_cr_phase_inverse_reg);
	cr_phase_inverse_rbus_data.cr_phase_inverse_thr = thr;
	rtd_outl(IFD_108_cr_phase_inverse_reg, cr_phase_inverse_rbus_data.regValue);
}
UINT16 drv_ifd_cr_phase_inverse_thr_get_info(void)
{
	ifd_108_cr_phase_inverse_RBUS cr_phase_inverse_rbus_data;

	cr_phase_inverse_rbus_data.regValue = rtd_inl(IFD_108_cr_phase_inverse_reg);
	return (cr_phase_inverse_rbus_data.cr_phase_inverse_thr);
}
void drv_ifd_cr_phase_inverse_st4_en(bool enable)
{
	ifd_108_cr_phase_inverse_RBUS cr_phase_inverse_rbus_data;

	cr_phase_inverse_rbus_data.regValue = rtd_inl(IFD_108_cr_phase_inverse_reg);
	cr_phase_inverse_rbus_data.cr_phase_inverse_en_st4 = enable;
	rtd_outl(IFD_108_cr_phase_inverse_reg, cr_phase_inverse_rbus_data.regValue);
}
bool drv_ifd_cr_phase_inverse_st4_en_get_info(void)
{
	ifd_108_cr_phase_inverse_RBUS cr_phase_inverse_rbus_data;

	cr_phase_inverse_rbus_data.regValue = rtd_inl(IFD_108_cr_phase_inverse_reg);
	return (cr_phase_inverse_rbus_data.cr_phase_inverse_en_st4);
}
void drv_ifd_cr_phase_inverse_st2_en(bool enable)
{
	ifd_108_cr_phase_inverse_RBUS cr_phase_inverse_rbus_data;

	cr_phase_inverse_rbus_data.regValue = rtd_inl(IFD_108_cr_phase_inverse_reg);
	cr_phase_inverse_rbus_data.cr_phase_inverse_en_st2 = enable;
	rtd_outl(IFD_108_cr_phase_inverse_reg, cr_phase_inverse_rbus_data.regValue);
}
bool drv_ifd_cr_phase_inverse_st2_en_get_info(void)
{
	ifd_108_cr_phase_inverse_RBUS cr_phase_inverse_rbus_data;

	cr_phase_inverse_rbus_data.regValue = rtd_inl(IFD_108_cr_phase_inverse_reg);
	return (cr_phase_inverse_rbus_data.cr_phase_inverse_en_st2);
}
void drv_ifd_cr_phase_inverse_st0_en(bool enable)
{
	ifd_108_cr_phase_inverse_RBUS cr_phase_inverse_rbus_data;

	cr_phase_inverse_rbus_data.regValue = rtd_inl(IFD_108_cr_phase_inverse_reg);
	cr_phase_inverse_rbus_data.cr_phase_inverse_en_st0 = enable;
	rtd_outl(IFD_108_cr_phase_inverse_reg, cr_phase_inverse_rbus_data.regValue);
}
bool drv_ifd_cr_phase_inverse_st0_en_get_info(void)
{
	ifd_108_cr_phase_inverse_RBUS cr_phase_inverse_rbus_data;

	cr_phase_inverse_rbus_data.regValue = rtd_inl(IFD_108_cr_phase_inverse_reg);
	return (cr_phase_inverse_rbus_data.cr_phase_inverse_en_st0);
}
//=================================================================
//CR Phase Error Avg
//=================================================================
UINT16 drv_ifd_cr_phase_error_mean_get_info(void)
{
	ifd_108_cr_phase_error_avg_status_RBUS cr_phase_error_avg_status_rbus_data;

	cr_phase_error_avg_status_rbus_data.regValue = rtd_inl(IFD_108_cr_phase_error_avg_status_reg);

	return (UINT16)(cr_phase_error_avg_status_rbus_data.cr_phase_error_mean);
}
UINT16 drv_ifd_cr_phase_error_var_get_info(void)
{
	ifd_108_cr_phase_error_avg_status_RBUS cr_phase_error_avg_status_rbus_data;

	cr_phase_error_avg_status_rbus_data.regValue = rtd_inl(IFD_108_cr_phase_error_avg_status_reg);

	return (UINT16)(cr_phase_error_avg_status_rbus_data.cr_phase_error_var);
}
//=================================================================
//CR Freq Error Avg
//=================================================================
UINT16 drv_ifd_cr_freq_error_mean_get_info(void)
{
	ifd_108_cr_freq_error_avg_status_RBUS cr_freq_error_avg_status_rbus_data;

	cr_freq_error_avg_status_rbus_data.regValue = rtd_inl(IFD_108_cr_freq_error_avg_status_reg);

	return (UINT16)(cr_freq_error_avg_status_rbus_data.cr_freq_error_mean);
}
UINT16 drv_ifd_cr_freq_error_var_get_info(void)
{
	ifd_108_cr_freq_error_avg_status_RBUS cr_freq_error_avg_status_rbus_data;

	cr_freq_error_avg_status_rbus_data.regValue = rtd_inl(IFD_108_cr_freq_error_avg_status_reg);

	return (UINT16)(cr_freq_error_avg_status_rbus_data.cr_freq_error_var);
}
//=================================================================
//CR State
//=================================================================
void drv_ifd_cr_st3_dn_debounce(UINT8 setting)
{
	ifd_108_cr_state_debounce_RBUS cr_state_debounce_rbus_data;

	cr_state_debounce_rbus_data.regValue = rtd_inl(IFD_108_cr_state_debounce_reg);
	cr_state_debounce_rbus_data.cr_st3_dn_debounce = setting;

	rtd_outl(IFD_108_cr_state_debounce_reg, cr_state_debounce_rbus_data.regValue);
}
UINT8 drv_ifd_cr_st3_dn_debounce_get_info(void)
{
	ifd_108_cr_state_debounce_RBUS cr_state_debounce_rbus_data;

	cr_state_debounce_rbus_data.regValue = rtd_inl(IFD_108_cr_state_debounce_reg);
	return cr_state_debounce_rbus_data.cr_st3_dn_debounce;
}
void drv_ifd_cr_st2_dn_debounce(UINT8 setting)
{
	ifd_108_cr_state_debounce_RBUS cr_state_debounce_rbus_data;

	cr_state_debounce_rbus_data.regValue = rtd_inl(IFD_108_cr_state_debounce_reg);
	cr_state_debounce_rbus_data.cr_st2_dn_debounce = setting;

	rtd_outl(IFD_108_cr_state_debounce_reg, cr_state_debounce_rbus_data.regValue);
}
UINT8 drv_ifd_cr_st2_dn_debounce_get_info(void)
{
	ifd_108_cr_state_debounce_RBUS cr_state_debounce_rbus_data;

	cr_state_debounce_rbus_data.regValue = rtd_inl(IFD_108_cr_state_debounce_reg);
	return cr_state_debounce_rbus_data.cr_st2_dn_debounce;
}
void drv_ifd_cr_st2_up_debounce(UINT8 setting)
{
	ifd_108_cr_state_debounce_RBUS cr_state_debounce_rbus_data;

	cr_state_debounce_rbus_data.regValue = rtd_inl(IFD_108_cr_state_debounce_reg);
	cr_state_debounce_rbus_data.cr_st2_up_debounce = setting;

	rtd_outl(IFD_108_cr_state_debounce_reg, cr_state_debounce_rbus_data.regValue);
}
UINT8 drv_ifd_cr_st2_up_debounce_get_info(void)
{
	ifd_108_cr_state_debounce_RBUS cr_state_debounce_rbus_data;

	cr_state_debounce_rbus_data.regValue = rtd_inl(IFD_108_cr_state_debounce_reg);
	return cr_state_debounce_rbus_data.cr_st2_up_debounce;
}
void drv_ifd_cr_st1_dn_debounce(UINT8 setting)
{
	ifd_108_cr_state_debounce_RBUS cr_state_debounce_rbus_data;

	cr_state_debounce_rbus_data.regValue = rtd_inl(IFD_108_cr_state_debounce_reg);
	cr_state_debounce_rbus_data.cr_st1_dn_debounce = setting;

	rtd_outl(IFD_108_cr_state_debounce_reg, cr_state_debounce_rbus_data.regValue);
}
UINT8 drv_ifd_cr_st1_dn_debounce_get_info(void)
{
	ifd_108_cr_state_debounce_RBUS cr_state_debounce_rbus_data;

	cr_state_debounce_rbus_data.regValue = rtd_inl(IFD_108_cr_state_debounce_reg);
	return cr_state_debounce_rbus_data.cr_st1_dn_debounce;
}
void drv_ifd_cr_st1_up_debounce(UINT8 setting)
{
	ifd_108_cr_state_debounce_RBUS cr_state_debounce_rbus_data;

	cr_state_debounce_rbus_data.regValue = rtd_inl(IFD_108_cr_state_debounce_reg);
	cr_state_debounce_rbus_data.cr_st1_up_debounce = setting;

	rtd_outl(IFD_108_cr_state_debounce_reg, cr_state_debounce_rbus_data.regValue);
}
UINT8 drv_ifd_cr_st1_up_debounce_get_info(void)
{
	ifd_108_cr_state_debounce_RBUS cr_state_debounce_rbus_data;

	cr_state_debounce_rbus_data.regValue = rtd_inl(IFD_108_cr_state_debounce_reg);
	return cr_state_debounce_rbus_data.cr_st1_up_debounce;
}
void drv_ifd_cr_st0_up_debounce(UINT8 setting)
{
	ifd_108_cr_state_debounce_RBUS cr_state_debounce_rbus_data;

	cr_state_debounce_rbus_data.regValue = rtd_inl(IFD_108_cr_state_debounce_reg);
	cr_state_debounce_rbus_data.cr_st0_up_debounce = setting;

	rtd_outl(IFD_108_cr_state_debounce_reg, cr_state_debounce_rbus_data.regValue);
}
UINT8 drv_ifd_cr_st0_up_debounce_get_info(void)
{
	ifd_108_cr_state_debounce_RBUS cr_state_debounce_rbus_data;

	cr_state_debounce_rbus_data.regValue = rtd_inl(IFD_108_cr_state_debounce_reg);
	return cr_state_debounce_rbus_data.cr_st0_up_debounce;
}
void drv_ifd_cr_st0_phase_var_thr(UINT16 setting)
{
	ifd_108_cr_state_thr1_RBUS cr_state_thr1_rbus_data;

	cr_state_thr1_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr1_reg);
	cr_state_thr1_rbus_data.cr_phase_var_st0_thr = setting;

	rtd_outl(IFD_108_cr_state_thr1_reg, cr_state_thr1_rbus_data.regValue);
}
UINT16 drv_ifd_cr_st0_phase_var_thr_get_info(void)
{
	ifd_108_cr_state_thr1_RBUS cr_state_thr1_rbus_data;

	cr_state_thr1_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr1_reg);
	return cr_state_thr1_rbus_data.cr_phase_var_st0_thr;
}
void drv_ifd_cr_st0_freq_var_thr(UINT16 setting)
{
	ifd_108_cr_state_thr1_RBUS cr_state_thr1_rbus_data;

	cr_state_thr1_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr1_reg);
	cr_state_thr1_rbus_data.cr_freq_var_st0_thr = setting;

	rtd_outl(IFD_108_cr_state_thr1_reg, cr_state_thr1_rbus_data.regValue);
}
UINT16 drv_ifd_cr_st0_freq_var_thr_get_info(void)
{
	ifd_108_cr_state_thr1_RBUS cr_state_thr1_rbus_data;

	cr_state_thr1_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr1_reg);
	return cr_state_thr1_rbus_data.cr_freq_var_st0_thr;
}
void drv_ifd_cr_vcheck_freq_var_thr(UINT16 setting)
{
	ifd_108_cr_state_thr2_RBUS cr_state_thr2_rbus_data;

	cr_state_thr2_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr2_reg);
	cr_state_thr2_rbus_data.cr_freq_varvcheck_thr = setting;

	rtd_outl(IFD_108_cr_state_thr2_reg, cr_state_thr2_rbus_data.regValue);
}
UINT16 drv_ifd_cr_vcheck_freq_var_thr_get_info(void)
{
	ifd_108_cr_state_thr2_RBUS cr_state_thr2_rbus_data;

	cr_state_thr2_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr2_reg);
	return cr_state_thr2_rbus_data.cr_freq_varvcheck_thr;
}
void drv_ifd_cr_st2_freq_var_up_thr(UINT16 setting)
{
	ifd_108_cr_state_thr3_RBUS cr_state_thr3_rbus_data;

	cr_state_thr3_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr3_reg);
	cr_state_thr3_rbus_data.cr_freq_var_st2_up_thr = setting;

	rtd_outl(IFD_108_cr_state_thr3_reg, cr_state_thr3_rbus_data.regValue);
}
UINT16 drv_ifd_cr_st2_freq_var_up_thr_get_info(void)
{
	ifd_108_cr_state_thr3_RBUS cr_state_thr3_rbus_data;

	cr_state_thr3_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr3_reg);
	return cr_state_thr3_rbus_data.cr_freq_var_st2_up_thr;
}
void drv_ifd_cr_st2_freq_var_low_thr(UINT16 setting)
{
	ifd_108_cr_state_thr3_RBUS cr_state_thr3_rbus_data;

	cr_state_thr3_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr3_reg);
	cr_state_thr3_rbus_data.cr_freq_var_st2_low_thr = setting;

	rtd_outl(IFD_108_cr_state_thr3_reg, cr_state_thr3_rbus_data.regValue);
}
UINT16 drv_ifd_cr_st2_freq_var_low_thr_get_info(void)
{
	ifd_108_cr_state_thr3_RBUS cr_state_thr3_rbus_data;

	cr_state_thr3_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr3_reg);
	return cr_state_thr3_rbus_data.cr_freq_var_st2_low_thr;
}
void drv_ifd_cr_st2_phase_var_thr(UINT16 setting)
{
	ifd_108_cr_state_thr2_RBUS cr_state_thr4_rbus_data;

	cr_state_thr4_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr2_reg);
	cr_state_thr4_rbus_data.cr_phase_var_st2_thr = setting;

	rtd_outl(IFD_108_cr_state_thr2_reg, cr_state_thr4_rbus_data.regValue);
}
UINT16 drv_ifd_cr_st2_phase_var_thr_get_info(void)
{
	ifd_108_cr_state_thr2_RBUS cr_state_thr4_rbus_data;

	cr_state_thr4_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr2_reg);
	return cr_state_thr4_rbus_data.cr_phase_var_st2_thr;
}
void drv_ifd_cr_st4_freq_var_thr(UINT16 setting)
{
	ifd_108_cr_state_thr4_RBUS cr_state_thr4_rbus_data;

	cr_state_thr4_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr4_reg);
	cr_state_thr4_rbus_data.cr_freq_var_st4_thr = setting;

	rtd_outl(IFD_108_cr_state_thr4_reg, cr_state_thr4_rbus_data.regValue);
}
UINT16 drv_ifd_cr_st4_freq_var_thr_get_info(void)
{
	ifd_108_cr_state_thr4_RBUS cr_state_thr4_rbus_data;

	cr_state_thr4_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr4_reg);
	return cr_state_thr4_rbus_data.cr_freq_var_st4_thr;
}
void drv_ifd_cr_st3_freq_var_thr(UINT16 setting)
{
	ifd_108_cr_state_thr4_RBUS cr_state_thr4_rbus_data;

	cr_state_thr4_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr4_reg);
	cr_state_thr4_rbus_data.cr_freq_var_st3_thr = setting;

	rtd_outl(IFD_108_cr_state_thr4_reg, cr_state_thr4_rbus_data.regValue);
}
UINT16 drv_ifd_cr_st3_freq_var_thr_get_info(void)
{
	ifd_108_cr_state_thr4_RBUS cr_state_thr4_rbus_data;

	cr_state_thr4_rbus_data.regValue = rtd_inl(IFD_108_cr_state_thr4_reg);
	return cr_state_thr4_rbus_data.cr_freq_var_st3_thr;
}
void drv_ifd_cr_st2_dn_update_sel(bool sel)
{
	ifd_108_cr_state_cntl_RBUS cr_state_cntl_rbus_data;

	cr_state_cntl_rbus_data.regValue = rtd_inl(IFD_108_cr_state_cntl_reg);
	cr_state_cntl_rbus_data.cr_st2_dn_update_sel = sel;

	rtd_outl(IFD_108_cr_state_cntl_reg, cr_state_cntl_rbus_data.regValue);
}
bool drv_ifd_cr_st2_dn_update_sel_get_info(void)
{
	ifd_108_cr_state_cntl_RBUS cr_state_cntl_rbus_data;

	cr_state_cntl_rbus_data.regValue = rtd_inl(IFD_108_cr_state_cntl_reg);

	return (bool)cr_state_cntl_rbus_data.cr_st2_dn_update_sel;
}
void drv_ifd_cr_fix_state(UINT8 state)
{
	ifd_108_cr_state_cntl_RBUS cr_state_cntl_rbus_data;

	cr_state_cntl_rbus_data.regValue = rtd_inl(IFD_108_cr_state_cntl_reg);
	cr_state_cntl_rbus_data.cr_fix_state = state;

	rtd_outl(IFD_108_cr_state_cntl_reg, cr_state_cntl_rbus_data.regValue);
}
UINT8 drv_ifd_cr_fix_state_get_info(void)
{
	ifd_108_cr_state_cntl_RBUS cr_state_cntl_rbus_data;

	cr_state_cntl_rbus_data.regValue = rtd_inl(IFD_108_cr_state_cntl_reg);

	return (UINT8)cr_state_cntl_rbus_data.cr_fix_state;
}
void drv_ifd_cr_fix_state_en(bool enable)
{
	ifd_108_cr_state_cntl_RBUS cr_state_cntl_rbus_data;

	cr_state_cntl_rbus_data.regValue = rtd_inl(IFD_108_cr_state_cntl_reg);
	cr_state_cntl_rbus_data.cr_state_fix_en = enable;

	rtd_outl(IFD_108_cr_state_cntl_reg, cr_state_cntl_rbus_data.regValue);
}
bool drv_ifd_cr_fix_state_en_get_info(void)
{
	ifd_108_cr_state_cntl_RBUS cr_state_cntl_rbus_data;

	cr_state_cntl_rbus_data.regValue = rtd_inl(IFD_108_cr_state_cntl_reg);

	return cr_state_cntl_rbus_data.cr_state_fix_en;
}
void drv_ifd_cr_state_en(bool enable)
{
	ifd_108_cr_state_cntl_RBUS cr_state_cntl_rbus_data;

	cr_state_cntl_rbus_data.regValue = rtd_inl(IFD_108_cr_state_cntl_reg);
	cr_state_cntl_rbus_data.cr_state_en = enable;

	rtd_outl(IFD_108_cr_state_cntl_reg, cr_state_cntl_rbus_data.regValue);
}
bool drv_ifd_cr_state_en_get_info(void)
{
	ifd_108_cr_state_cntl_RBUS cr_state_cntl_rbus_data;

	cr_state_cntl_rbus_data.regValue = rtd_inl(IFD_108_cr_state_cntl_reg);

	return cr_state_cntl_rbus_data.cr_state_en;
}
UINT8 drv_ifd_cr_state_status_get_info(void)
{
	ifd_108_cr_state_read_RBUS cr_state_read_rbus_data;

	cr_state_read_rbus_data.regValue = rtd_inl(IFD_108_cr_state_read_reg);

	return (UINT8)(cr_state_read_rbus_data.cr_state);
}
void drv_ifd_cr_vsync(UINT16 start, UINT16 end)
{
	ifd_108_cr_vsync_start_RBUS cr_vsync_start_rbus_data;

	cr_vsync_start_rbus_data.regValue = rtd_inl(IFD_108_cr_vsync_start_reg);
	cr_vsync_start_rbus_data.cr_vsync_start = start;
	cr_vsync_start_rbus_data.cr_vsync_end = end;
	rtd_outl(IFD_108_cr_vsync_start_reg, cr_vsync_start_rbus_data.regValue);
}
//=================================================================
//CR Shift
//=================================================================
void drv_ifd_cr_fm_en(bool setting)
{
	ifd_108_cr_shift_en_RBUS cr_shift_en_rbus_data;

	cr_shift_en_rbus_data.regValue = rtd_inl(IFD_108_cr_shift_en_reg);
	cr_shift_en_rbus_data.cr_fm_en = setting;
	rtd_outl(IFD_108_cr_shift_en_reg, cr_shift_en_rbus_data.regValue);
}
void drv_ifd_cr_shift_en(bool setting)
{
	ifd_108_cr_shift_en_RBUS cr_shift_en_rbus_data;

	cr_shift_en_rbus_data.regValue = rtd_inl(IFD_108_cr_shift_en_reg);
	cr_shift_en_rbus_data.cr_shift_en = setting;
	rtd_outl(IFD_108_cr_shift_en_reg, cr_shift_en_rbus_data.regValue);
}
void drv_ifd_cr_shift_polar(IFD_CR_SHIFT_POLAR setting)
{
	ifd_108_cr_shift_en_RBUS cr_shift_en_rbus_data;

	cr_shift_en_rbus_data.regValue = rtd_inl(IFD_108_cr_shift_en_reg);
	cr_shift_en_rbus_data.cr_shift_polar = setting;
	rtd_outl(IFD_108_cr_shift_en_reg, cr_shift_en_rbus_data.regValue);
}
void drv_ifd_cr_shift_nco(UINT32 setting)
{
	ifd_108_cr_shift_en_RBUS cr_shift_en_rbus_data;

	cr_shift_en_rbus_data.regValue = rtd_inl(IFD_108_cr_shift_en_reg);
	cr_shift_en_rbus_data.cr_shift_nco_offset = setting;
	rtd_outl(IFD_108_cr_shift_en_reg, cr_shift_en_rbus_data.regValue);
}
UINT32 drv_ifd_cr_shift_nco_getinfo(void)
{
	ifd_108_cr_shift_en_RBUS cr_shift_en_rbus_data;

	cr_shift_en_rbus_data.regValue = rtd_inl(IFD_108_cr_shift_en_reg);
	return (UINT32)cr_shift_en_rbus_data.cr_shift_nco_offset;
}

bool drv_ifd_cr_shift_en_getinfo(void)
{
	ifd_108_cr_shift_en_RBUS cr_shift_en_rbus_data;

	cr_shift_en_rbus_data.regValue = rtd_inl(IFD_108_cr_shift_en_reg);
	return (bool)cr_shift_en_rbus_data.cr_shift_en;
}

//=================================================================
//CR input power
//=================================================================
void drv_ifd_set_power_diff_cr_lock(bool enable)
{
	ifd_108_input_power_cr_lock_RBUS cr_power_lock_rbus_data;

	cr_power_lock_rbus_data.regValue = rtd_inl(IFD_108_input_power_cr_lock_reg);
	cr_power_lock_rbus_data.cr_lock_power_diff_en = enable;
	rtd_outl(IFD_108_input_power_cr_lock_reg, cr_power_lock_rbus_data.regValue);
}
bool drv_ifd_get_power_diff_cr_lock(void)
{
	ifd_108_input_power_cr_lock_RBUS cr_power_lock_rbus_data;

	cr_power_lock_rbus_data.regValue = rtd_inl(IFD_108_input_power_cr_lock_reg);
	return cr_power_lock_rbus_data.cr_lock_power_diff_en;
}
void drv_ifd_set_power_diff_cr_lock_thr(UINT16 thr)
{
	ifd_108_input_power_cr_lock_RBUS cr_power_lock_rbus_data;

	cr_power_lock_rbus_data.regValue = rtd_inl(IFD_108_input_power_cr_lock_reg);
	cr_power_lock_rbus_data.cr_lock_power_diff_thr = thr & 0xFFFF;
	rtd_outl(IFD_108_input_power_cr_lock_reg, cr_power_lock_rbus_data.regValue);
}
UINT16 drv_ifd_get_power_diff_cr_lock_thr(void)
{
	ifd_108_input_power_cr_lock_RBUS cr_power_lock_rbus_data;

	cr_power_lock_rbus_data.regValue = rtd_inl(IFD_108_input_power_cr_lock_reg);
	return cr_power_lock_rbus_data.cr_lock_power_diff_thr;
}
UINT16 drv_ifd_get_cr_input_power_diff(void)
{
	ifd_108_input_power_min_diff_RBUS cr_input_power_diff_rbus_data;

	cr_input_power_diff_rbus_data.regValue = rtd_inl(IFD_108_input_power_min_diff_reg);
	return cr_input_power_diff_rbus_data.input_power_min_diff;
}
bool drv_ifd_get_cr_input_power_done_status(void)
{
	ifd_108_input_power_done_RBUS cr_input_power_done_rbus_data;

	cr_input_power_done_rbus_data.regValue = rtd_inl(IFD_108_input_power_done_reg);
	return cr_input_power_done_rbus_data.input_power_detect_done;
}

