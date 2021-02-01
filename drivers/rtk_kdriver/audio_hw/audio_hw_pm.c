#include <linux/kconfig.h>
#include <linux/compiler.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/errno.h>		/* error codes */
#include <linux/types.h>		/* size_t */
#include <linux/delay.h>
#include <linux/device.h>		/* device */
#include <linux/platform_device.h>	/* platform device */
#include <linux/pm.h>			/* power management */

#include <rbus/tv_sb1_ana_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/audio_reg.h>
#include <rbus/sys_reg_reg.h>

#include "audio_hw_port.h"
#include "audio_hw_driver.h"
#include "audio_hw_pm.h"
#include "audio_hw_app.h"
#include "audio_hw_atv.h"

#define __ALOG_SUBTAG "pm"

struct audio_hw_pm {
	struct device *dev;

    int msd_ctrl_word;              // 0xb8006200
    int msd_result;                 // 0xb8006204
    int msd_status;                 // 0xb8006208
    int main_tone_threshold;        // 0xb800620c
    int main_tone_threshold_hd;     // 0xb8006210
    int bw_threshold;               // 0xb8006214
    int main_sub_ratio;             // 0xb8006218
    int msd_second_reg_std;         // 0xb800627c
    int second_main_tone_threshold; // 0xb8006280
    int mode_detect;                // 0xb8006300
    int md_ctrl;                    // 0xb8006310
    int md_status_1;                // 0xb8006314
    int md_status_2;                // 0xb8006318
    int md_status_3;                // 0xb800b31c
    int carrier_freq_deviation_ctrl;// 0xb8006350
    int carrier_phase_delta;        // 0xb8006354
    int am;                         // 0xb8006360
    int btsc_pilot_thres;           // 0xb8006400
    int btsc_sap_thresh;            // 0xb8006408
    int btsc_sap_noise_th;          // 0xb800640c
    int btsc_sap_status;            // 0xb8006414
    int btsc_sap_debounce;          // 0xb8006418
    int btsc_pilot_phase_delta;     // 0xb8006428
    int phase_error_pi_gain;        // 0xb800642c
    int phase_err_threshold;        // 0xb8006430
    int phase_err_threshold2;       // 0xb8006434
    int a2_eiaj_demod;              // 0xb8006450
    int nicam_demod;                // 0xb8006500
    int nicam_dagc_ctrl;            // 0xb8006504
    int nicam_dagc_threshold;       // 0xb8006508
    int nicam_decode_ctrl;          // 0xb8006510
    int nicam_auto_switch;          // 0xb8006518
    int nicam_demod_auto_recovery;  // 0xb800651c
    int sif_agc_eval_cnt;           // 0xb8006180
    int sif_agc2_ctrl;              // 0xb8006190
    int sif_agc3_ctrl;              // 0xb8006198
    int btsc_pilot_status;          // 0xb8006404 
    int eq_tvd_bp1_1;                       // 0xb8006ea0
    int eq_tvd_bp1_2;                       // 0xb8006ea4
    int eq_tvd_bp2_1;                       // 0xb8006ea8
    int eq_tvd_bp2_2;                       // 0xb8006eac
    int eq_tvd_bp_control;                  // 0xb8006eb0
    int eq_tvd_lp;                          // 0xb8006eb8
    int tvdemod_digital_volume_control;     // 0xb800635c 20160728_Add
    int tvdemod_digital_volume_control_2;   // 0xb8006e28 20160728_Add
	int sif_agc_threshold;                  // 0xb8006188 20170208_Add
	int analog_pga;                         // 0xb8006b48
};

void audio_atv_suspend(struct audio_hw_pm *pm);
void audio_atv_resume(struct audio_hw_pm *pm);

struct audio_hw_pm *audio_hw_pm_create(struct device *dev)
{
	struct audio_hw_pm *pm = NULL;

	if (!dev) {
		alog_err("invalid device\n");
		pm = (struct audio_hw_pm *)ERR_PTR(-ENXIO);
		goto exit_error;
	}

	pm = devm_kzalloc(dev, sizeof(struct audio_hw_pm), GFP_KERNEL);
	if (!pm) {
		alog_err("can't allocate pm\n");
		pm = ERR_PTR(-ENOMEM);
		goto exit_error;
	}

	/* keep device */
	pm->dev = dev;

	return pm;

exit_error:
	return pm;
}

void audio_hw_pm_destroy(struct audio_hw_pm *pm)
{
	if (pm)
		pm->dev = NULL;
}

int audio_hw_pm_suspend(struct audio_hw_pm *pm)
{
	struct audio_hw_drvdata *drvdata;

	if (!pm || !pm->dev) {
		alog_err("invalid pm or dev\n");
		return -EINVAL;
	}

	drvdata = dev_get_drvdata(pm->dev);

	/* do suspend below here */
	audio_atv_suspend(pm);

	return 0;
}

int audio_hw_pm_resume(struct audio_hw_pm *pm)
{
	struct audio_hw_drvdata *drvdata;

	if (!pm || !pm->dev) {
		alog_err("invalid pm or dev\n");
		return -EINVAL;
	}

	drvdata = dev_get_drvdata(pm->dev);

	/* do resume below here */
	audio_atv_resume(pm);

	return 0;
}

void audio_atv_suspend(struct audio_hw_pm *pm)
{
    pm->msd_ctrl_word               = Audio_HwpReadRegister(AUDIO_msd_crtl_word_reg);
    pm->msd_result                  = Audio_HwpReadRegister(AUDIO_msd_result_reg);
    pm->msd_status                  = Audio_HwpReadRegister(AUDIO_msd_status_reg);
    pm->main_tone_threshold         = Audio_HwpReadRegister(AUDIO_main_tone_threshold_reg);
    pm->main_tone_threshold_hd      = Audio_HwpReadRegister(AUDIO_main_tone_threshold_hd_reg);
    pm->bw_threshold                = Audio_HwpReadRegister(AUDIO_bw_threshold_reg);
    pm->main_sub_ratio              = Audio_HwpReadRegister(AUDIO_main_sub_ratio_reg);
    pm->msd_second_reg_std          = Audio_HwpReadRegister(AUDIO_msd_second_reg_std_reg);
    pm->second_main_tone_threshold  = Audio_HwpReadRegister(AUDIO_second_main_tone_threshold_reg);
    pm->mode_detect                 = Audio_HwpReadRegister(AUDIO_mode_detect_reg);
    pm->md_ctrl                     = Audio_HwpReadRegister(AUDIO_md_ctrl_reg);
    pm->md_status_1                 = Audio_HwpReadRegister(AUDIO_md_status_1_reg);
    pm->md_status_2                 = Audio_HwpReadRegister(AUDIO_md_status_2_reg);
    pm->md_status_3                 = Audio_HwpReadRegister(AUDIO_md_status_3_reg);
    pm->carrier_freq_deviation_ctrl = Audio_HwpReadRegister(AUDIO_carrier_freq_deviation_ctrl_reg);
    pm->carrier_phase_delta         = Audio_HwpReadRegister(AUDIO_carrier_phase_delta_reg);
    pm->am                          = Audio_HwpReadRegister(AUDIO_am_reg);
    pm->btsc_pilot_thres            = Audio_HwpReadRegister(AUDIO_btsc_pilot_thres_reg);
    pm->btsc_sap_thresh             = Audio_HwpReadRegister(AUDIO_btsc_sap_thresh_reg);
    pm->btsc_sap_noise_th           = Audio_HwpReadRegister(AUDIO_btsc_sap_noise_th_reg);
    pm->btsc_sap_status             = Audio_HwpReadRegister(AUDIO_btsc_sap_status_reg);
    pm->btsc_sap_debounce           = Audio_HwpReadRegister(AUDIO_btsc_sap_debounce_reg);
    pm->btsc_pilot_phase_delta      = Audio_HwpReadRegister(AUDIO_btsc_pilot_phase_delta_reg);
    pm->btsc_pilot_status           = Audio_HwpReadRegister(AUDIO_btsc_pilot_status_reg);
    pm->phase_error_pi_gain         = Audio_HwpReadRegister(AUDIO_phase_error_pi_gain_reg);
    pm->phase_err_threshold         = Audio_HwpReadRegister(AUDIO_phase_err_threshold_reg);
    pm->phase_err_threshold2        = Audio_HwpReadRegister(AUDIO_phase_err_threshold2_reg);
    pm->a2_eiaj_demod               = Audio_HwpReadRegister(AUDIO_a2_eiaj_demod_reg);
    pm->nicam_demod                 = Audio_HwpReadRegister(AUDIO_nicam_demod_reg);
    pm->nicam_dagc_ctrl             = Audio_HwpReadRegister(AUDIO_nicam_dagc_ctrl_reg);
    pm->nicam_dagc_threshold        = Audio_HwpReadRegister(AUDIO_nicam_dagc_threshold_reg);
    pm->nicam_decode_ctrl           = Audio_HwpReadRegister(AUDIO_nicam_decode_ctrl_reg);
    pm->nicam_auto_switch           = Audio_HwpReadRegister(AUDIO_nicam_auto_switch_reg);
    pm->nicam_demod_auto_recovery   = Audio_HwpReadRegister(AUDIO_nicam_demod_auto_recovery_reg);

    pm->sif_agc_eval_cnt            = Audio_HwpReadRegister(AUDIO_sif_agc_eval_cnt_reg);
	pm->sif_agc_threshold           = Audio_HwpReadRegister(AUDIO_sif_agc_threshold_reg);
    pm->sif_agc2_ctrl               = Audio_HwpReadRegister(AUDIO_sif_agc2_ctrl_reg);
    pm->sif_agc3_ctrl               = Audio_HwpReadRegister(AUDIO_sif_agc3_ctrl_reg);
	pm->analog_pga                  = Audio_HwpReadRegister(AUDIO_analog_pga_reg);
	
	pm->eq_tvd_bp1_1                = Audio_HwpReadRegister(AUDIO_EQ_tvd_bp1_1_reg);
    pm->eq_tvd_bp1_2                = Audio_HwpReadRegister(AUDIO_EQ_tvd_bp1_2_reg);
    pm->eq_tvd_bp2_1                = Audio_HwpReadRegister(AUDIO_EQ_tvd_bp2_1_reg);
    pm->eq_tvd_bp2_2                = Audio_HwpReadRegister(AUDIO_EQ_tvd_bp2_2_reg);
    pm->eq_tvd_bp_control           = Audio_HwpReadRegister(AUDIO_EQ_tvd_bp_Control_reg);
    pm->eq_tvd_lp                   = Audio_HwpReadRegister(AUDIO_EQ_tvd_lp_reg);

	// SIF-DVC
    pm->tvdemod_digital_volume_control    = Audio_HwpReadRegister(AUDIO_TVdemod_Digital_Volume_Control_reg);
    pm->tvdemod_digital_volume_control_2  = Audio_HwpReadRegister(AUDIO_TVdemod_Digital_Volume_Control_2_reg);
}

void audio_atv_resume(struct audio_hw_pm *pm)
{
	audio_carrier_freq_deviation_ctrl_RBUS CARRIER_FREQ_DEVIATION_CTRL;
	audio_tvdemod_digital_volume_control_RBUS   TVDEMOD_DIGITAL_VOLUME_CONTROL;
	
    Audio_HwpWriteRegister(AUDIO_msd_crtl_word_reg, pm->msd_ctrl_word);
    Audio_HwpWriteRegister(AUDIO_msd_result_reg, pm->msd_result);
    Audio_HwpWriteRegister(AUDIO_msd_status_reg, pm->msd_status);
    Audio_HwpWriteRegister(AUDIO_main_tone_threshold_reg, pm->main_tone_threshold);
    Audio_HwpWriteRegister(AUDIO_main_tone_threshold_hd_reg, pm->main_tone_threshold_hd);
    Audio_HwpWriteRegister(AUDIO_bw_threshold_reg, pm->bw_threshold);
    Audio_HwpWriteRegister(AUDIO_main_sub_ratio_reg, pm->main_sub_ratio);
    Audio_HwpWriteRegister(AUDIO_msd_second_reg_std_reg, pm->msd_second_reg_std);
    Audio_HwpWriteRegister(AUDIO_second_main_tone_threshold_reg, pm->second_main_tone_threshold);
    Audio_HwpWriteRegister(AUDIO_mode_detect_reg, pm->mode_detect);
    Audio_HwpWriteRegister(AUDIO_md_ctrl_reg, pm->md_ctrl);
    Audio_HwpWriteRegister(AUDIO_md_status_1_reg, pm->md_status_1);
    Audio_HwpWriteRegister(AUDIO_md_status_2_reg, pm->md_status_2);
    Audio_HwpWriteRegister(AUDIO_md_status_3_reg, pm->md_status_3);
    Audio_HwpWriteRegister(AUDIO_carrier_freq_deviation_ctrl_reg, pm->carrier_freq_deviation_ctrl);

	// if external sif path, do sif adc init flow
	CARRIER_FREQ_DEVIATION_CTRL.regValue = pm->carrier_freq_deviation_ctrl;
	if(CARRIER_FREQ_DEVIATION_CTRL.sif_data_source)
		audio_sif_adc_initial_flow();

    Audio_HwpWriteRegister(AUDIO_carrier_phase_delta_reg, pm->carrier_phase_delta);
    Audio_HwpWriteRegister(AUDIO_am_reg, pm->am);
    Audio_HwpWriteRegister(AUDIO_btsc_pilot_thres_reg, pm->btsc_pilot_thres);
    Audio_HwpWriteRegister(AUDIO_btsc_sap_thresh_reg, pm->btsc_sap_thresh);
    Audio_HwpWriteRegister(AUDIO_btsc_sap_noise_th_reg, pm->btsc_sap_noise_th);
    Audio_HwpWriteRegister(AUDIO_btsc_sap_status_reg, pm->btsc_sap_status);
    Audio_HwpWriteRegister(AUDIO_btsc_sap_debounce_reg, pm->btsc_sap_debounce);
    Audio_HwpWriteRegister(AUDIO_btsc_pilot_phase_delta_reg, pm->btsc_pilot_phase_delta);
    Audio_HwpWriteRegister(AUDIO_btsc_pilot_status_reg, pm->btsc_pilot_status);
    Audio_HwpWriteRegister(AUDIO_phase_error_pi_gain_reg, pm->phase_error_pi_gain);
    Audio_HwpWriteRegister(AUDIO_phase_err_threshold_reg, pm->phase_err_threshold);
    Audio_HwpWriteRegister(AUDIO_phase_err_threshold2_reg, pm->phase_err_threshold2);
    Audio_HwpWriteRegister(AUDIO_a2_eiaj_demod_reg, pm->a2_eiaj_demod);
    Audio_HwpWriteRegister(AUDIO_nicam_demod_reg, pm->nicam_demod);
    Audio_HwpWriteRegister(AUDIO_nicam_dagc_ctrl_reg, pm->nicam_dagc_ctrl);
    Audio_HwpWriteRegister(AUDIO_nicam_dagc_threshold_reg, pm->nicam_dagc_threshold);
    Audio_HwpWriteRegister(AUDIO_nicam_decode_ctrl_reg, pm->nicam_decode_ctrl);
    Audio_HwpWriteRegister(AUDIO_nicam_auto_switch_reg, pm->nicam_auto_switch);
    Audio_HwpWriteRegister(AUDIO_nicam_demod_auto_recovery_reg, pm->nicam_demod_auto_recovery);

    Audio_HwpWriteRegister(AUDIO_sif_agc_eval_cnt_reg, pm->sif_agc_eval_cnt);
	Audio_HwpWriteRegister(AUDIO_sif_agc_threshold_reg, pm->sif_agc_threshold);
    Audio_HwpWriteRegister(AUDIO_sif_agc2_ctrl_reg, pm->sif_agc2_ctrl);
    Audio_HwpWriteRegister(AUDIO_sif_agc3_ctrl_reg, pm->sif_agc3_ctrl);
    Audio_HwpWriteRegister(AUDIO_analog_pga_reg, pm->analog_pga);

    Audio_HwpWriteRegister(AUDIO_EQ_tvd_bp1_1_reg, pm->eq_tvd_bp1_1);
    Audio_HwpWriteRegister(AUDIO_EQ_tvd_bp1_2_reg, pm->eq_tvd_bp1_2);
    Audio_HwpWriteRegister(AUDIO_EQ_tvd_bp2_1_reg, pm->eq_tvd_bp2_1);
    Audio_HwpWriteRegister(AUDIO_EQ_tvd_bp2_2_reg, pm->eq_tvd_bp2_2);
    Audio_HwpWriteRegister(AUDIO_EQ_tvd_bp_Control_reg, pm->eq_tvd_bp_control);
    Audio_HwpWriteRegister(AUDIO_EQ_tvd_lp_reg, pm->eq_tvd_lp);	

	// SIF-DVC
    Audio_HwpWriteRegister(AUDIO_TVdemod_Digital_Volume_Control_reg, pm->tvdemod_digital_volume_control);
    Audio_HwpWriteRegister(AUDIO_TVdemod_Digital_Volume_Control_2_reg, pm->tvdemod_digital_volume_control_2);
    TVDEMOD_DIGITAL_VOLUME_CONTROL.regValue = Audio_HwpReadRegister(AUDIO_TVdemod_Digital_Volume_Control_reg);

    TVDEMOD_DIGITAL_VOLUME_CONTROL.dvol_apply_tvd = 1;
    Audio_HwpWriteRegister(AUDIO_TVdemod_Digital_Volume_Control_reg, TVDEMOD_DIGITAL_VOLUME_CONTROL.regValue);
}