typedef enum  {
	IFD_AGC_MODE_2LOOP = 0,
	IFD_AGC_MODE_2STEP,
} IFD_AGC_MODE;

typedef enum  {
	IFD_AGC_IMPULSIVE_DET_INPUT_DGAINOUT = 0  ,
	IFD_AGC_IMPULSIVE_DET_INPUT_LPFOUT,
} IFD_AGC_IMPULSIVE_DET_INPUT;

typedef enum  {
	IFD_AGC_HUM_UPDATE_SEL_SYNCLEVEL = 0  ,
	IFD_AGC_HUM_UPDATE_SEL_MAX,
} IFD_AGC_HUM_UPDATE_SEL;

typedef enum  {
	IFD_AGC_PADCTRL_TTL = 0  ,
	IFD_AGC_PADCTRL_OPENDRAIN,
} IFD_AGC_PADCTRL;

typedef enum  {
	IFD_AGC_INPUT_POWER_MODE_SEQUENTIAL = 0,
	IFD_AGC_INPUT_POWER_MODE_SCAN,
} IFD_AGC_INPUT_POWER_MODE;

/*=============================================================*/
/**
 * drv_ifd_agc_dgain_en
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_agc_dgain_en(bool enable);
/*=============================================================*/
/**
 * drv_ifd_agc_dgain_en
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_agc_agc_rf_en(bool enable);
/*=============================================================*/
/**
 * drv_ifd_agc_loop1_fine_tune_en
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_agc_loop1_fine_tune_en(bool enable);
/*=============================================================*/
/**
 * drv_ifd_agc_loop1_fine_tune_en_get_info
 *
 *
 * @param <void>
 * @return { enable }
 */
bool drv_ifd_agc_loop1_fine_tune_en_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_bpf_en
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_agc_bpf_en(bool enable);
/*=============================================================*/
/**
 * drv_ifd_agc_bpf_en_get_info
 *
 *
 * @param <void>
 * @return { enable }
 */
bool drv_ifd_agc_bpf_en_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_set_slow_charge_en_for_max
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_set_slow_charge_en_for_max(bool enable);
/*=============================================================*/
/**
 * drv_ifd_get_slow_charge_en_for_max
 *
 *
 * @param <void>
 * @return { enable }
 */
bool drv_ifd_get_slow_charge_en_for_max(void);
/*=============================================================*/
/**
 * drv_ifd_set_slow_charge_en_for_peak
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_set_slow_charge_en_for_peak(bool enable);
/*=============================================================*/
/**
 * drv_ifd_get_slow_charge_en_for_max
 *
 *
 * @param <void>
 * @return { enable }
 */
bool drv_ifd_get_slow_charge_en_for_peak(void);
/*=============================================================*/
/**
 * drv_ifd_agc_diff_targ
 *
 *
 * @param <agc_diff_targ>
 * @return { void }
 */
void drv_ifd_agc_diff_targ(UINT16 agc_diff_targ);
/*=============================================================*/
/**
 * drv_ifd_agc_diff_target_get_info
 *
 *
 * @param <void>
 * @return { agc_diff_targ }
 */
UINT16  drv_ifd_agc_diff_target_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_loop1_pos_en
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_agc_loop1_pos_en(bool enable);
/*=============================================================*/
/**
 * drv_ifd_agc_pos_en_get_info
 *
 *
 * @param <void>
 * @return { bool }
 */
bool drv_ifd_agc_pos_en_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_data_targ
 *
 *
 * @param <agc_data_targ>
 * @return { void }
 */
void drv_ifd_agc_data_target(UINT16 agc_data_targ);
/*=============================================================*/
/**
 * drv_ifd_agc_data_targ_get_info
 *
 *
 * @param <void>
 * @return { agc_data_targ }
 */
UINT16 drv_ifd_agc_data_target_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_targ_val
 *
 *
 * @param <agc_targ_val>
 * @return { void }
 */
void drv_ifd_agc_targ_val(UINT16 agc_targ_val);
/*=============================================================*/
/**
 * drv_ifd_agc_targ_val_get_info
 *
 *
 * @param <void>
 * @return { agc_targ_val }
 */
UINT16 drv_ifd_agc_targ_val_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_out_inv
 *
 *
 * @param <agc_out_inv_rf><agc_out_inv_if>
 * @return { void }
 */
void drv_ifd_agc_out_inv(bool agc_out_inv_rf, bool agc_out_inv_if);
/*=============================================================*/
/**
 * drv_ifd_agc_polar_inv
 *
 *
 * @param <agc_polar_inv_rf><agc_polar_inv_if>
 * @return { void }
 */
void drv_ifd_agc_polar_inv(bool agc_inv);

/*=============================================================*/
/**
 * drv_ifd_agc_if_manual_en
 *
 *
 * @param <agc_if_manu_en>
 * @return { void }
 */
void drv_ifd_agc_if_manual_en(bool agc_if_manu_en);
/*=============================================================*/
/**
 * drv_ifd_agc_if_manual_en_get_info
 *
 *
 * @param <void>
 * @return { agc_if_manu_en }
 */
UINT16 drv_ifd_agc_if_manual_en_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_if_manual_gain
 *
 *
 * @param <agc_if_manu_value>
 * @return { void }
 */
void drv_ifd_agc_if_manual_gain(UINT16 agc_if_manu_value);
/*=============================================================*/
/**
 * drv_ifd_agc_if_manual_gain_get_info
 *
 *
 * @param <void>
 * @return { agc_if_manu_value }
 */
UINT16 drv_ifd_agc_if_manual_gain_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_rf_manual_en
 *
 *
 * @param <agc_rf_manu_en>
 * @return { void }
 */
void drv_ifd_agc_rf_manual_en(bool agc_rf_manu_en);
/*=============================================================*/
/**
 * drv_ifd_agc_rf_manual_en_get_info
 *
 *
 * @param <void>
 * @return { agc_rf_manu_en }
 */
bool drv_ifd_agc_rf_manual_en_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_manual_rf_gain
 *
 *
 * @param <agc_rf_manu_value>
 * @return { void }
 */
void drv_ifd_agc_manual_rf_gain(UINT16 agc_rf_manu_value);
/*=============================================================*/
/**
 * drv_ifd_agc_manual_rf_gain
 *
 *
 * @param <void>
 * @return { agc_rf_manu_value }
 */
UINT16 drv_ifd_agc_manual_rf_gain_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_manual_en
 *
 *
 * @param <agc_rf_manu_en><agc_rf_manu_value>
 * @return { void }
 */
void drv_ifd_agc_manual_en(bool agc_manual_en, UINT16 agc_manual_value);
/*=============================================================*/
/**
 * drv_ifd_agc_loop1_kp_settings
 *
 *
 * @param <agc_kp>
 * @return { void }
 */
void drv_ifd_agc_loop1_kp_settings(UINT8 agc_kp);
/*=============================================================*/
/**
 * drv_ifd_agc_loop1_ki_settings
 *
 *
 * @param <agc_ki>
 * @return { void }
 */
void drv_ifd_agc_loop1_ki_settings(UINT8 agc_ki);
/*=============================================================*/
/**
 * drv_ifd_agc_loop1_pishift_settings
 *
 *
 * @param <agc_kpd_add_method_shift>
 * @return { void }
 */
void drv_ifd_agc_loop1_pishift_settings(UINT8 agc_kpd_add_method_shift);

/*=============================================================*/
/**
 * drv_ifd_get_agc_loop1_kp_settings
 *
 *
 * @param <void>
 * @return <agc_kp>
 */
UINT8 drv_ifd_get_agc_loop1_kp_settings(void);
/*=============================================================*/
/**
 * drv_ifd_get_agc_loop1_ki_settings
 *
 *
 * @param <void>
 * @return <agc_ki >
 */
UINT8 drv_ifd_get_agc_loop1_ki_settings(void);
/*=============================================================*/
/**
 * drv_ifd_get_agc_loop1_pishift_settings
 *
 *
 * @param <void>
 * @return <agc_kpd_add_method_shift >
 */
UINT8 drv_ifd_get_agc_loop1_pishift_settings(void);
/*=============================================================*/
/**
 * drv_ifd_agc_rf_max
 *
 *
 * @param <rf_max>
 * @return <void >
 */
void drv_ifd_agc_rf_max(UINT16 rf_max);
/*=============================================================*/
/**
 * drv_ifd_agc_rf_max_get_info
 *
 *
 * @param <void>
 * @return <rf_max >
 */
UINT16 drv_ifd_agc_rf_max_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_rf_min
 *
 *
 * @param <rf_min>
 * @return <void >
 */
void drv_ifd_agc_rf_min(UINT16 rf_min);
/*=============================================================*/
/**
 * drv_ifd_agc_rf_min_get_info
 *
 *
 * @param <void>
 * @return <rf_min >
 */
UINT16 drv_ifd_agc_rf_min_get_info(void);
void drv_ifd_agc_lock_thr(UINT8 thr);
UINT8 drv_ifd_agc_lock_thr_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_get_loop1_lock
 *
 *
 * @param <void>
 * @return <lock_status>
 */
bool drv_ifd_agc_get_loop1_lock(void);
/*=============================================================*/
/**
 * drv_ifd_agc_get_loop1_fine_lock
 *
 *
 * @param <void>
 * @return <fine_lock_status>
 */
bool drv_ifd_agc_get_loop1_fine_lock(void);
/*=============================================================*/
/**
 * drv_ifd_agc_get_loop1_peak_status
 *
 *
 * @param <void>
 * @return <peak_status>
 */
bool drv_ifd_agc_get_loop1_peak_status(void);
/*=============================================================*/
/**
 * drv_ifd_agc_loop1_peak_en
 *
 *
 * @param <agc_peak_en>
 * @return { void }
 */
void drv_ifd_agc_loop1_peak_en(bool agc_peak_en);
/*=============================================================*/
/**
 * drv_ifd_get_agc_loop1_peak_en
 *
 *
 * @param <void>
 * @return <agc_peak_en>
 */
bool drv_ifd_get_agc_loop1_peak_en(void);
/*=============================================================*/
/**
 * drv_ifd_get_agc_loop1_peak_force
 *
 *
 * @param <void>
 * @return <agc_loop1_peak_force_en>
 */
bool drv_ifd_get_agc_loop1_peak_force(void);
/*=============================================================*/
/**
 * drv_ifd_set_agc_loop1_peak_force
 *
 *
 * @param <agc_loop1_peak_force_en>
 * @return <void >
 */
void drv_ifd_set_agc_loop1_peak_force(bool enable);
void drv_ifd_set_agc_loop2_peak_force(bool enable);
/*=============================================================*/
/**
 * drv_ifd_agc_peak_target
 *
 *
 * @param <agc_peak_value>
 * @return { void }
 */

void drv_ifd_agc_peak_target(UINT16 agc_peak_value);
/*=============================================================*/
/**
 * drv_ifd_agc_peak_target_get_info
 *
 *
 * @param <void>
 * @return { agc_peak_value }
 */
UINT16  drv_ifd_agc_peak_target_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_get_loop1_err0
 *
 *
 * @param <void>
 * @return <agc_err>
 */
UINT16 drv_ifd_agc_get_loop1_err0(void);
UINT16 drv_ifd_agc_get_loop1_peak_error(void);
/*=============================================================*/
/**
 * drv_ifd_agc_get_if_output
 *
 *
 * @param <void>
 * @return <agc_if_mode>
 */
UINT16 drv_ifd_agc_get_if_output(void);
/*=============================================================*/
/**
 * drv_ifd_agc_acc3_get_info
 *
 *
 * @param <void>
 * @return <agc_acc3>
 */
UINT16 drv_ifd_agc_acc3_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_get_rf_output
 *
 *
 * @param <void>
 * @return <agc_rf_mode>
 */
UINT16 drv_ifd_agc_get_rf_output(void);
/*=============================================================*/
/**
 * drv_ifd_agc_pga_manual_en
 *
 *
 * @param <agc_pga_fix_en><agc_pga_fix>
 * @return { void }
 */
void drv_ifd_agc_pga_manual_en(bool agc_pga_fix_en, UINT16 agc_pga_fix);
/*=============================================================*/
/**
 * drv_ifd_agc_pga_manual_en_get_info
 *
 *
 * @param { void }
 * @return { agc_pga_fix_en }
 */
bool drv_ifd_agc_pga_manual_en_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_pga_manual_index_get_info
 *
 *
 * @param { void }
 * @return { index_output }
 */
UINT8 drv_ifd_agc_pga_manual_index_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_sep_rf_if_en
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_agc_sep_rf_if_en(bool enable);
/*=============================================================*/
/**
 * drv_ifd_set_agc_if_kp
 *
 *
 * @param <agc_if_kp>
 * @return { void }
 */
void drv_ifd_set_agc_if_kp(UINT8 if_kp);
/*=============================================================*/
/**
 * drv_ifd_set_agc_if_ki
 *
 *
 * @param <agc_if_ki>
 * @return { void }
 */
void drv_ifd_set_agc_if_ki(UINT8 if_ki);
/*=============================================================*/
/**
 * drv_ifd_agc_vtop
 *
 *
 * @param <agc_vtop>
 * @return { void }
 */
void drv_ifd_agc_vtop(UINT32 agc_vtop);
/*=============================================================*/
/**
 * drv_ifd_get_agc_vtop
 *
 *
 * @param <void>
 * @return <agc_vtop>
 */
UINT32 drv_ifd_get_agc_vtop(void);
/*=============================================================*/
/**
 * drv_ifd_agc_krf
 *
 *
 * @param <agc_krf>
 * @return { void }
 */
void drv_ifd_agc_krf(UINT32 agc_krf);
/*=============================================================*/
/**
 * drv_ifd_get_agc_krf
 *
 *
 * @param <void>
 * @return <agc_krf>
 */
UINT32 drv_ifd_get_agc_krf(void);
/*=============================================================*/
/**
 * drv_ifd_agc_get_pga_code
 *
 *
 * @param <void>
 * @return <pga_set_read>
 */
UINT16 drv_ifd_agc_get_pga_code(void);
/*=============================================================*/
/**
 * drv_ifd_agc_pga_index_get_info
 *
 *
 * @param { void }
 * @return { index_output }
 */
UINT8 drv_ifd_agc_pga_index_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_hold
 *
 *
 * @param <agc_loop2_hold>
 * @return { void }
 */
void drv_ifd_agc_loop2_hold(bool agc_loop2_hold);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_hold_get_info
 *
 *
 * @param <void>
 * @return { agc_loop2_hold }
 */
bool drv_ifd_agc_loop2_hold_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_loop2_agcin_kpki_settings
 *
 *
 * @param <agc_in_kp><agc_in_ki><agc_in_kp_shift><agc_in_ki_shift>
 * @return { void }
 */
void drv_ifd_loop2_agcin_kpki_settings(UINT8 agc_in_kp, UINT8 agc_in_ki, UINT8 agc_in_kp_shift, UINT8 agc_in_ki_shift);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_kp_settings
 *
 *
 * @param <agc_in_kp>
 * @return { void }
 */
void drv_ifd_agc_loop2_kp_settings(UINT8 agc_in_kp);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_kp_settings_get_info
 *
 *
 * @param <void>
 * @return { agc_in_kp }
 */
UINT8 drv_ifd_agc_loop2_kp_settings_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_ki_settings
 *
 *
 * @param <agc_in_ki>
 * @return { void }
 */
void drv_ifd_agc_loop2_ki_settings(UINT8 agc_in_ki);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_ki_settings_get_info
 *
 *
 * @param <void>
 * @return { agc_in_ki }
 */
UINT8 drv_ifd_agc_loop2_ki_settings_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_kishift_settings
 *
 *
 * @param <agc_in_ki_shift>
 * @return { void }
 */
void drv_ifd_agc_loop2_kishift_settings(UINT8 agc_in_ki_shift);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_kishift_settings_get_info
 *
 *
 * @param <void>
 * @return { agc_in_ki_shift }
 */
UINT8 drv_ifd_agc_loop2_kishift_settings_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_kpshift_settings
 *
 *
 * @param <agc_in_kp_shift>
 * @return { void }
 */
void drv_ifd_agc_loop2_kpshift_settings(UINT8 agc_in_kp_shift);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_kpshift_settings_get_info
 *
 *
 * @param <void>
 * @return { agc_in_kp_shift }
 */
UINT8 drv_ifd_agc_loop2_kpshift_settings_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_dgain_boundary
 *
 *
 * @param <agc_in_max><agc_in_min>
 * @return { void }
 */
void drv_ifd_agc_dgain_boundary(UINT16 agc_in_max, UINT16 agc_in_min);

UINT16 drv_ifd_agc_get_loop2_max_out(void);

/*=============================================================*/
/**
 * drv_ifd_agc_get_loop2_err
 *
 *
 * @param {void}
 * @return  <loop2_err>
 */
UINT16 drv_ifd_agc_get_loop2_err(void);
/*=============================================================*/
/**
 * drv_ifd_agc_get_loop1_dgain_output
 *
 *
 * @param {void}
 * @return  <agc_inner1>
 */
UINT16 drv_ifd_agc_get_loop1_dgain_output(void);
/*=============================================================*/
/**
 * drv_ifd_agc_get_loop2_dgain_output
 *
 *
 * @param {void}
 * @return  <agc_inner2>
 */
UINT16 drv_ifd_agc_get_loop2_dgain_output(void);
/*=============================================================*/
/**
 * drv_ifd_agc_adaptive_peak2_en
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_agc_adaptive_peak2_en(bool enable);
/*=============================================================*/
/**
 * drv_ifd_agc_get_loop2_peak_status
 *
 *
 * @param {void}
 * @return  <agc_peak2_status>
 */
bool drv_ifd_agc_get_loop2_peak_status(void);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_peak_en
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_agc_loop2_peak_en(bool enable);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_peak_cnt
 *
 *
 * @param <agc_peak2_cnt>
 * @return { void }
 */
void drv_ifd_agc_loop2_peak_cnt(UINT16 agc_peak2_cnt);
/*=============================================================*/
/**
 * drv_ifd_get_agc_loop2_peak_en
 *
 *
 * @param <void>
 * @return <agc_peak2_en>
 */
bool drv_ifd_get_agc_loop2_peak_en(void);
/*=============================================================*/
/**
 * drv_ifd_agc_get_loop2_peak_error
 *
 *
 * @param {void}
 * @return  <error>
 */
UINT16 drv_ifd_agc_get_loop2_peak_error(void);
/*=============================================================*/
/**
 * drv_ifd_agc_get_loop2_peak_max
 *
 *
 * @param {void}
 * @return  <max>
 */
UINT16 drv_ifd_agc_get_loop2_peak_max(void);
/*=============================================================*/
/**
 * drv_ifd_agc_get_loop2_max_out
 *
 *
 * @param {void}
 * @return  <max>
 */
UINT16 drv_ifd_agc_get_loop2_max_out(void);
/*=============================================================*/
/**
 * drv_ifd_agc_2step_en
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_agc_2step_en(bool enable);
/*=============================================================*/
/**
 * drv_ifd_get_agc_2step_en
 *
 *
 * @param <void>
 * @return <enable>
 */
bool drv_ifd_get_agc_2step_en(void);
/*=============================================================*/
/**
 * drv_ifd_agc_dgain_up_dn_step
 *
 *
 * @param <agc_dgain_up_step><agc_dgain_down_step>
 * @return { void }
 */
void drv_ifd_agc_dgain_up_dn_step(UINT16 agc_dgain_up_step, UINT16 agc_dgain_down_step);
/*=============================================================*/
/**
 * drv_ifd_agc_dgain_up_dn_boundary
 *
 *
 * @param <agc_dgain_low_thr><agc_dgain_up_thr>
 * @return { void }
 */
void drv_ifd_agc_dgain_up_dn_boundary(UINT16 agc_dgain_low_thr, UINT16 agc_dgain_up_thr);
/*=============================================================*/
/**
 * drv_ifd_agc_2step_pga_step
 *
 *
 * @param <agc_step_num_pga>
 * @return { void }
 */
void drv_ifd_agc_2step_pga_step(UINT8 agc_step_num_pga);
/*=============================================================*/
/**
 * drv_ifd_agc_2step_pga_step_get_info
 *
 *
 * @param <void>
 * @return { agc_step_num_pga }
 */
UINT8 drv_ifd_agc_2step_pga_step_get_info(void);	// Patch 20100304,irene
/*=============================================================*/
/**
 * drv_ifd_agc_2step_pga_minimum
 *
 *
 * @param <agc_dgain_min_pga>
 * @return { void }
 */
void drv_ifd_agc_2step_pga_minimum(UINT32 agc_dgain_min_pga);
/*=============================================================*/
/**
 * drv_ifd_agc_2step_pga_minimum_get_info
 *
 *
 * @param <void>
 * @return < agc_dgain_min_pga >
 */
UINT32 drv_ifd_agc_2step_pga_minimum_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_mode_sel
 *
 *
 * @param <agc_mode>
 * @return { void }
 */
void drv_ifd_agc_mode_sel(IFD_AGC_MODE agc_mode);
/*=============================================================*/
/**
 * drv_ifd_get_agc_mode_sel
 *
 *
 * @param <void>
 * @return <agc_mode>
 */
IFD_AGC_MODE drv_ifd_get_agc_mode_sel(void);
/*=============================================================*/
/**
 * drv_ifd_agc_vsync_start1
 *
 *
 * @param <start><end>
 * @return { void }
 */
void drv_ifd_agc_vsync_start1(UINT16 start, UINT16 end);
/*=============================================================*/
/**
 * drv_ifd_agc_hsync_start1
 *
 *
 * @param <start><end>
 * @return { void }
 */
void drv_ifd_agc_hsync_start1(UINT16 start, UINT16 end);
/*=============================================================*/
/**
 * drv_ifd_agc_loop1_finetune_dn_sample
 *
 *
 * @param <dn_sample>
 * @return { void }
 */
void drv_ifd_agc_loop1_finetune_dn_sample(UINT16 dn_sample);
/*=============================================================*/
/**
 * drv_ifd_agc_loop1_finetune_dn_sample_get_info
 *
 *
 * @param <void>
 * @return { dn_sample }
 */
UINT16 drv_ifd_agc_loop1_finetune_dn_sample_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_finetune_dn_sample
 *
 *
 * @param <dn_sample>
 * @return { void }
 */
void drv_ifd_agc_loop2_finetune_dn_sample(UINT16 dn_sample);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_finetune_dn_sample_get_info
 *
 *
 * @param <void>
 * @return { dn_sample }
 */
UINT16 drv_ifd_agc_loop2_finetune_dn_sample_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_loop1_dn_sample
 *
 *
 * @param <dnsample>
 * @return { void }
 */
void drv_ifd_agc_loop1_dn_sample(UINT16 dnsample);
/*=============================================================*/
/**
 * drv_ifd_agc_loop1_dn_sample_get_info
 *
 *
 * @param <void>
 * @return { dnsample }
 */
UINT16 drv_ifd_agc_loop1_dn_sample_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_dn_sample
 *
 *
 * @param <dnsample>
 * @return { void }
 */
void drv_ifd_agc_loop2_dn_sample(UINT16 dnsample);
/*=============================================================*/
/**
 * drv_ifd_agc_loop2_dn_sample_get_info
 *
 *
 * @param <void>
 * @return { dnsample }
 */
UINT16 drv_ifd_agc_loop2_dn_sample_get_info(void);
/*=============================================================*/
/**
 * drv_ifd_rf_full_get_info
 *
 *
 * @param <void>
 * @return { dnsample }
 */
bool drv_ifd_rf_full_get_info(void);
//=================================================================
//AGC Rf Hasten
//=================================================================
void drv_ifd_agc_set_rf_hasten_en(bool enable);
bool drv_ifd_agc_get_rf_hasten_en(void);
void drv_ifd_agc_set_rf_hasten_ki(UINT8 ki);
UINT8 drv_ifd_agc_get_rf_hasten_ki(void);
void drv_ifd_agc_set_rf_hasten_max_cntl(UINT16 max_cntl);
UINT16 drv_ifd_agc_get_rf_hasten_max_cntl(void);
void drv_ifd_agc_set_rf_hasten_thr(UINT16 thr);
UINT16 drv_ifd_agc_get_rf_hasten_thr(void);
//=================================================================
//AGC Sep Rf If
//=================================================================
void drv_ifd_agc_set_sep_rf_if_en(bool enable);
bool drv_ifd_agc_get_sep_rf_if_en(void);
void drv_ifd_agc_set_sep_rf_if_ki(UINT8 ki);
UINT8 drv_ifd_agc_get_sep_rf_if_ki(void);
void drv_ifd_agc_set_sep_rf_if_kpi(UINT8 kp);
UINT8 drv_ifd_agc_get_sep_rf_if_kp(void);
//=================================================================
//AGC Gain Average Control
//=================================================================
void drv_ifd_agc_average_control(UINT16 interval, bool sel, UINT8 length);
void drv_ifd_agc_average_get_status(UINT16 *var, UINT16 *mean);
//=================================================================
//AGC Adaptive Target Control
//=================================================================
void drv_ifd_agc_adaptivetarget_fine_interval(UINT16 setting);
UINT16 drv_ifd_agc_adaptivetarget_fine_interval_get_info(void);
void drv_ifd_agc_adaptivetarget_interval(UINT16 setting);
UINT16 drv_ifd_agc_adaptivetarget_interval_get_info(void);
void drv_ifd_agc_adaptivetarget_en(bool enable);
bool drv_ifd_agc_adaptivetarget_en_get_info(void);
void drv_ifd_agc_adaptivetarget_inc_thr(UINT16 setting);
UINT16 drv_ifd_agc_adaptivetarget_inc_thr_get_info(void);
void drv_ifd_agc_adaptivetarget_min_difftarg(UINT16 setting);
UINT16 drv_ifd_agc_adaptivetarget_min_difftarg_get_info(void);
void drv_ifd_agc_adaptivetarget_min_targ(UINT16 setting);
UINT16 drv_ifd_agc_adaptivetarget_min_targ_get_info(void);
void drv_ifd_agc_adaptivetarget_fine_targthr(UINT16 setting);
UINT16 drv_ifd_agc_adaptivetarget_fine_targthr_get_info(void);
void drv_ifd_agc_adaptivetarget_diff_coarsestep(UINT16 setting);
UINT16 drv_ifd_agc_adaptivetarget_diff_coarsestep_get_info(void);
UINT16 drv_ifd_agc_adaptivetarget_get_difftarget_status(void);
UINT16 drv_ifd_agc_adaptivetarget_get_target_status(void);
//=================================================================
//AGC Impulsive Gate
//=================================================================
void drv_ifd_agc_impulsive_gate_end(UINT16 setting);
UINT16 drv_ifd_agc_impulsive_gate_end_get_info(void);
void drv_ifd_agc_impulsive_det_thr(UINT16 setting);
UINT16 drv_ifd_agc_impulsive_det_thr_get_info(void);
void drv_ifd_agc_impulsive_det_input_sel(IFD_AGC_IMPULSIVE_DET_INPUT setting);
IFD_AGC_IMPULSIVE_DET_INPUT drv_ifd_agc_impulsive_det_input_sel_get_info(void);
void drv_ifd_agc_impulsive_mask_en(bool setting);
bool drv_ifd_agc_impulsive_mask_en_get_info(void);
void drv_ifd_agc_impulsive_det_en(bool setting);
bool drv_ifd_agc_impulsive_det_en_get_info(void);
void drv_ifd_agc_impulsive_det_stop(UINT8 setting);
UINT8 drv_ifd_agc_impulsive_det_stop_get_info(void);
void drv_ifd_agc_impulsive_gate_delay(UINT16 setting);
UINT16 drv_ifd_agc_impulsive_gate_delay_get_info(void);
UINT16 drv_ifd_agc_impulsive_detected_get_info(void);
//=================================================================
//AGC Hum Ctrl
//=================================================================
UINT16 drv_ifd_agc_synclevel_var_get_info(void);
UINT16 drv_ifd_agc_synclevel_mean_get_info(void);
UINT16 drv_ifd_agc_max_var_get_info(void);
UINT16 drv_ifd_agc_max_mean_get_info(void);
bool drv_ifd_agc_hum_detected_get_info(void);
void drv_ifd_agc_hum_debounce(UINT8 setting);
UINT8 drv_ifd_agc_hum_debounce_get_info(void);
void drv_ifd_agc_hum_update_sel(IFD_AGC_HUM_UPDATE_SEL setting);
IFD_AGC_HUM_UPDATE_SEL drv_ifd_agc_hum_update_sel_get_info(void);
void drv_ifd_agc_hum_en(bool setting);
bool drv_ifd_agc_hum_en_get_info(void);
void drv_ifd_agc_hum_max_thr_out(UINT16 setting);
UINT16 drv_ifd_agc_hum_max_thr_out_get_info(void);
void drv_ifd_agc_hum_max_thr_in(UINT16 setting);
UINT16 drv_ifd_agc_hum_max_thr_in_get_info(void);
void drv_ifd_agc_hum_synclevel_thr_out(UINT16 setting);
UINT16 drv_ifd_agc_hum_synclevel_thr_out_get_info(void);
void drv_ifd_agc_hum_synclevel_thr_in(UINT16 setting);
UINT16 drv_ifd_agc_hum_synclevel_thr_in_get_info(void);
//=================================================================
//AGC Sigma Delta
//=================================================================
void drv_ifd_agc_rfagc_padctrl(IFD_AGC_PADCTRL setting);
IFD_AGC_PADCTRL drv_ifd_agc_rfagc_padctrl_get_info(void);
void drv_ifd_agc_ifagc_padctrl(IFD_AGC_PADCTRL setting);
IFD_AGC_PADCTRL drv_ifd_agc_ifagc_padctrl_get_info(void);
void drv_ifd_agc_sigma_delta_dnsel(UINT8 setting);
UINT8 drv_ifd_agc_sigma_delta_dnsel_get_info(void);

//=================================================================
//Auto PGA MIN
//=================================================================
void drv_ifd_agc_auto_pga_min_en(bool enable);
UINT8 drv_ifd_agc_lsadc_out_peak_value_get_info(void);
//=================================================================
//RSSI output
//=================================================================
UINT8 drv_ifd_agc_lsadc_out_get_info(void);
//=================================================================
//Input Power Detect
//=================================================================
void drv_ifd_agc_inputpower_mode(bool setting);
void drv_ifd_agc_inputpower_modulation_sel(bool setting);
void drv_ifd_agc_inputpower_cal_reset(bool setting);
void drv_ifd_agc_inputpower_pc_sel(bool setting);
void drv_ifd_agc_inputpower_sequentialmode_detect_freq(UINT32 *freq, UINT8 adc_clk_mhz);
void drv_ifd_agc_inputpower_scanmode_detect_freq(UINT32 *freq, UINT8 adc_clk_mhz);
void drv_ifd_agc_inputpower_scanmode_offset(UINT8 setting);
bool drv_ifd_agc_inputpower_detect_result(UINT32 *result);
#if 0
//=================================================================
//RF recoder
//=================================================================
void drv_ifd_agc_rf_record_en(bool enable);
bool drv_ifd_agc_rf_record_en_get_info(void);
void drv_ifd_agc_rf_record_len(UINT8 len);
void drv_ifd_agc_rf_record_get_info(UINT16 *table);
#endif


