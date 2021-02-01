typedef enum  {
	IFD_CR_WEIGHT_CR_LOCK_ENABLE = 0 ,
	IFD_CR_WEIGHT_CR_LOCK_DISABLE,
} IFD_CR_WEIGHT_CR_LOCK;

typedef enum  {
	IFD_CR_WEIGHT_MAX_DECREASE_1CYCLE = 0 ,
	IFD_CR_WEIGHT_MAX_DECREASE_4CYCLE,
	IFD_CR_WEIGHT_MAX_DECREASE_8CYCLE,
	IFD_CR_WEIGHT_MAX_DECREASE_16CYCLE,
	IFD_CR_WEIGHT_MAX_DECREASE_32CYCLE,
	IFD_CR_WEIGHT_MAX_DECREASE_64CYCLE,
	IFD_CR_WEIGHT_MAX_DECREASE_128CYCLE,
	IFD_CR_WEIGHT_MAX_DECREASE_256CYCLE,
	IFD_CR_WEIGHT_MAX_DECREASE_512CYCLE,
	IFD_CR_WEIGHT_MAX_DECREASE_1024CYCLE,
} IFD_CR_WEIGHT_MAX_DECREASE;

typedef enum  {
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_0BIT = 0 ,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_1BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_2BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_3BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_4BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_5BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_6BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_7BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_8BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_9BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_10BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_11BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_12BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_13BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_14BIT,
	IFD_CR_WEIGHT_MAX_SHIFT_RIGHT_15BIT,
} IFD_CR_WEIGHT_SHIFT;

typedef enum  {
	IFD_CR_INNER_LPF_6ORDER = 0 ,
	IFD_CR_INNER_LPF_4ORDER = 1 ,
} IFD_CR_INNER_LPF;

typedef enum  {
	IFD_CR_SHIFT_POLAR_POS = 0 ,
	IFD_CR_SHIFT_POLAR_NEG = 1 ,
} IFD_CR_SHIFT_POLAR;
//=================================================================
/**
 * drv_ifd_set_cr_bpf_coef
 *
 *
 * @param <cr_bpf_en><table>
 * @return { void }
 */
void drv_ifd_set_cr_bpf_coef(bool cr_bpf_en, UINT16 *table);
/*=============================================================*/
/**
 * drv_ifd_cr_bpf_en
 *
 *
 * @param <cr_bpf_en>
 * @return { void }
 */
void drv_ifd_cr_bpf_en(bool cr_bpf_en);
/*=============================================================*/
/**
 * drv_ifd_cr_bpf_en_get_info
 *
 *
 * @param <void>
 * @return { cr_bpf_en }
 */
UINT8 drv_ifd_cr_bpf_en_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_cr_inner_lpf_en
 *
 *
 * @param <cr_inner_lpf_en>
 * @return { void }
 */
void drv_ifd_cr_inner_lpf_en(bool cr_inner_lpf_en);
/*=============================================================*/
/**
 * drv_ifd_cr_inner_lpf_en_get_info
 *
 *
 * @param <void>
 * @return { cr_inner_lpf_en }
 */
UINT8 drv_ifd_cr_inner_lpf_en_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_cr_loop_filter_kp_st3
 *
 *
 * @param <cr_pgain>
 * @return { void }
 */
void drv_ifd_cr_loop_filter_kp_st3(UINT8 cr_pgain);
UINT8 drv_ifd_cr_loop_filter_kp_st3_get_info(void);
void drv_ifd_cr_loop_filter_ki_st3(UINT8 cr_igain);
UINT8 drv_ifd_cr_loop_filter_ki_st3_get_info(void);
void drv_ifd_cr_loop_filter_kp_st2(UINT8 cr_pgain);
UINT8 drv_ifd_cr_loop_filter_kp_st2_get_info(void);
void drv_ifd_cr_loop_filter_ki_st2(UINT8 cr_igain);
UINT8 drv_ifd_cr_loop_filter_ki_st2_get_info(void);
void drv_ifd_cr_loop_filter_kp_st0(UINT8 cr_pgain);
UINT8 drv_ifd_cr_loop_filter_kp_st0_get_info(void);
void drv_ifd_cr_loop_filter_ki_st0(UINT8 cr_igain);
UINT8 drv_ifd_cr_loop_filter_ki_st0_get_info(void);
void drv_ifd_cr_loop_filter_kp(UINT8 cr_pgain);
UINT8 drv_ifd_cr_kp_get_info(void);
void drv_ifd_cr_loop_filter_ki(UINT8 cr_igain);
UINT8 drv_ifd_cr_ki_get_info(void);

/*=============================================================*/
/**
 * drv_ifd_get_cr_lock_status
 *
 *
 * @param <void>
 * @return <lock_status>
 */
bool drv_ifd_get_cr_lock_status(void);
/*=============================================================*/
/**
 * drv_ifd_set_cr_lock_freq_thr
 *
 *
 * @param <thr>
 * @return <void>
 */
void drv_ifd_set_cr_lock_freq_thr(UINT16 thr);
UINT16 drv_ifd_get_cr_lock_freq_thr(void);
/*=============================================================*/
/**
 * drv_ifd_set_cr_lock_with_freq
 *
 *
 * @param <enable>
 * @return <void>
 */
void drv_ifd_set_cr_lock_with_freq(bool enable);
/*=============================================================*/
/**
 * drv_ifd_set_cr_lock_with_hsync
 *
 *
 * @param <enable>
 * @return <void>
 */
void drv_ifd_set_cr_lock_with_hsync(bool enable);
/*=============================================================*/
/**
 * drv_ifd_get_cr_cos_sampler_avg
 *
 *
 * @param <void>
 * @return <cos_sampler_avg>
 */
UINT8 drv_ifd_get_cr_cos_sampler_avg(void);
/*=============================================================*/
/**
 * drv_ifd_set_cr_nco
 *
 *
 * @param <enable><para>
 * @return { void }
 */
void drv_ifd_set_cr_nco(bool enable, UINT32 para);
/*=============================================================*/
/**
 * drv_ifd_get_cr_nco
 *
 *
 * @param  { void }
 * @return  <para>
 */
UINT32 drv_ifd_get_cr_nco(void);
/*=============================================================*/
/**
 * drv_ifd_get_cr_freq_offset
 *
 *
 * @param <void>
 * @return <cr_freq_offset>
 */
UINT32 drv_ifd_get_cr_freq_offset(void);
/*=============================================================*/
/**
 * drv_ifd_set_cr_weighting_en
 *
 *
 * @param <cr_weight_en>
 * @return { void }
 */
void drv_ifd_set_cr_weighting_en(bool cr_weight_en);
/*=============================================================*/
/**
 * drv_ifd_cr_weighting_en_get_info
 *
 *
 * @param <void>
 * @return { cr_weight_en }
 */
UINT8 drv_ifd_cr_weighting_en_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_set_cr_weighting_settings
 *
 *
 * @param <cr_weighting_cr_lock_dis><cr_weight_max_decrease><cr_weight_shift>
 * @return { void }
 */
void drv_ifd_set_cr_weighting_settings(IFD_CR_WEIGHT_CR_LOCK cr_weighting_cr_lock_dis, IFD_CR_WEIGHT_MAX_DECREASE cr_weight_max_decrease, IFD_CR_WEIGHT_SHIFT cr_weight_shift);
/*=============================================================*/
/**
 * drv_ifd_set_cr_weighting_speed
 *
 *
 * @param <cr_weight_max_decrease>
 * @return { void }
 */
void drv_ifd_set_cr_weighting_speed(IFD_CR_WEIGHT_MAX_DECREASE cr_weight_max_decrease);
/*=============================================================*/
/**
 * drv_ifd_set_cr_weighting_speed_get_info
 *
 *
 * @param <void>
 * @return { cr_weight_max_decrease }
 */
UINT8 drv_ifd_set_cr_weighting_speed_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_get_cr_sin_sample_d
 *
 *
 * @param {void}
 * @return <sin_sample_d>
 */
UINT16 drv_ifd_get_cr_sin_sample_d(void);
/*=============================================================*/
/**
 * drv_ifd_set_cr_inner_lpf_sel
 *
 *
 * @param <inner_lpf_sel>
 * @return { void }
 */
void drv_ifd_set_cr_inner_lpf_sel(IFD_CR_INNER_LPF inner_lpf_sel);
IFD_CR_INNER_LPF drv_ifd_get_cr_inner_lpf_sel(void);
/*=============================================================*/
/**
 * drv_ifd_cr_error_thd
 *
 *
 * @param <err_thd>
 * @return { void }
 */
void drv_ifd_cr_error_thd(UINT8 err_thd);
/*=============================================================*/
/**
 * drv_ifd_cr_error_thd_get_info
 *
 *
 * @param <void>
 * @return { err_thd }
 */
UINT8 drv_ifd_cr_error_thd_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_cr_auto_reset_en
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_cr_auto_reset_en(bool enable);
/*=============================================================*/
/**
 * drv_ifd_cr_auto_reset_en_get_info
 *
 *
 * @param <void>
 * @return { enable }
 */
bool drv_ifd_cr_auto_reset_en_get_info(void);
//=================================================================
//CR Phase Inverse
//=================================================================
void drv_ifd_cr_phase_inverse_en(bool enable);
bool drv_ifd_cr_phase_inverse_en_get_info(void);
void drv_ifd_cr_phase_inverse_thr(UINT16 thr);
UINT16 drv_ifd_cr_phase_inverse_thr_get_info(void);
void drv_ifd_cr_phase_inverse_st4_en(bool enable);
bool drv_ifd_cr_phase_inverse_st4_en_get_info(void);
void drv_ifd_cr_phase_inverse_st2_en(bool enable);
bool drv_ifd_cr_phase_inverse_st2_en_get_info(void);
void drv_ifd_cr_phase_inverse_st0_en(bool enable);
bool drv_ifd_cr_phase_inverse_st0_en_get_info(void);
//=================================================================
//CR Phase Error Avg
//=================================================================
UINT16 drv_ifd_cr_phase_error_mean_get_info(void);
UINT16 drv_ifd_cr_phase_error_var_get_info(void);
//=================================================================
//CR Freq Error Avg
//=================================================================
UINT16 drv_ifd_cr_freq_error_mean_get_info(void);
UINT16 drv_ifd_cr_freq_error_var_get_info(void);
//=================================================================
//CR State
//=================================================================
void drv_ifd_cr_st3_dn_debounce(UINT8 setting);
UINT8 drv_ifd_cr_st3_dn_debounce_get_info(void);
void drv_ifd_cr_st2_dn_debounce(UINT8 setting);
UINT8 drv_ifd_cr_st2_dn_debounce_get_info(void);
void drv_ifd_cr_st2_up_debounce(UINT8 setting);
UINT8 drv_ifd_cr_st2_up_debounce_get_info(void);
void drv_ifd_cr_st1_dn_debounce(UINT8 setting);
UINT8 drv_ifd_cr_st1_dn_debounce_get_info(void);
void drv_ifd_cr_st1_up_debounce(UINT8 setting);
UINT8 drv_ifd_cr_st1_up_debounce_get_info(void);
void drv_ifd_cr_st0_up_debounce(UINT8 setting);
UINT8 drv_ifd_cr_st0_up_debounce_get_info(void);
void drv_ifd_cr_st0_phase_var_thr(UINT16 setting);
UINT16 drv_ifd_cr_st0_phase_var_thr_get_info(void);
void drv_ifd_cr_st0_freq_var_thr(UINT16 setting);
UINT16 drv_ifd_cr_st0_freq_var_thr_get_info(void);
void drv_ifd_cr_vcheck_freq_var_thr(UINT16 setting);
UINT16 drv_ifd_cr_vcheck_freq_var_thr_get_info(void);
void drv_ifd_cr_st2_freq_var_up_thr(UINT16 setting);
UINT16 drv_ifd_cr_st2_freq_var_up_thr_get_info(void);
void drv_ifd_cr_st2_freq_var_low_thr(UINT16 setting);
UINT16 drv_ifd_cr_st2_freq_var_low_thr_get_info(void);
void drv_ifd_cr_st2_phase_var_thr(UINT16 setting);
UINT16 drv_ifd_cr_st2_phase_var_thr_get_info(void);
void drv_ifd_cr_st4_freq_var_thr(UINT16 setting);
UINT16 drv_ifd_cr_st4_freq_var_thr_get_info(void);
void drv_ifd_cr_st3_freq_var_thr(UINT16 setting);
UINT16 drv_ifd_cr_st3_freq_var_thr_get_info(void);
void drv_ifd_cr_st2_dn_update_sel(bool sel);
bool drv_ifd_cr_st2_dn_update_sel_get_info(void);
void drv_ifd_cr_fix_state(UINT8 state);
UINT8 drv_ifd_cr_fix_state_get_info(void);
void drv_ifd_cr_fix_state_en(bool enable);
bool drv_ifd_cr_fix_state_en_get_info(void);
void drv_ifd_cr_state_en(bool enable);
bool drv_ifd_cr_state_en_get_info(void);
UINT8 drv_ifd_cr_state_status_get_info(void);
void drv_ifd_cr_vsync(UINT16 start, UINT16 end);
//=================================================================
//CR Shift
//=================================================================
void drv_ifd_cr_fm_en(bool setting);
void drv_ifd_cr_shift_en(bool setting);
void drv_ifd_cr_shift_polar(IFD_CR_SHIFT_POLAR setting);
void drv_ifd_cr_shift_nco(UINT32 setting);
UINT32 drv_ifd_cr_shift_nco_getinfo(void);
bool drv_ifd_cr_shift_en_getinfo(void);
//=================================================================
//CR input power
//=================================================================
void drv_ifd_set_power_diff_cr_lock(bool enable);
bool drv_ifd_get_power_diff_cr_lock(void);
void drv_ifd_set_power_diff_cr_lock_thr(UINT16 thr);
UINT16 drv_ifd_get_power_diff_cr_lock_thr(void);
UINT16 drv_ifd_get_cr_input_power_diff(void);
bool drv_ifd_get_cr_input_power_done_status(void);