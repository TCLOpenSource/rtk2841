#include "ifd_new.h"

//=================================================================
//Input FIFO
//=================================================================
void drv_ifd_input_filter_sel(bool enable, UINT16 *table)
{
	UINT8 i;
	UINT32 addr_base = VD_IFD_INPUT_108_input_flt_tap_0_1_reg;
	  
	// modified input filter coef.
	for (i = 0; i < (INPUT_FILTER_TABLE_SIZE >> 1); i++) {
		rtd_outl(addr_base + i * 4, table[2 * i] << 16 | table[2 * i + 1]);
	}

	// enable input filter
	rtd_outl(VD_IFD_INPUT_108_input_flt_en_reg, enable);
}

void drv_ifd_input_input_fifo_clear(void)
{
	rtd_outl(VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg, 0x04);
	rtd_outl(VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg, 0x00);
}

void drv_ifd_input_input_fifo_flag_clear(void)
{
	rtd_outl(VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg, 0x18);
	rtd_outl(VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg, 0x00);
}

bool drv_ifd_input_input_fifo_flag_check(void)
{
	//UINT32 status = 0;

	//if (status) return _TRUE;
	return _FALSE;
}

/*
void drv_ifd_input_input_fifo_softreset(bool Enable)
{

	if (Enable)
		rtd_maskl(CRT_SYS_SRST2_reg, ~(_BIT27), 0);
	else
		rtd_maskl(CRT_SYS_SRST2_reg, ~(_BIT27), _BIT27);

}
bool drv_ifd_input_input_fifo_softreset_getinfo(void)
{

	UINT32 status;

	status = (rtd_inl(CRT_SYS_SRST2_reg) >> 27) & 0x1;

	if (status) return _FALSE;

	return _TRUE;

}
*/

//=================================================================
//output Data Gain
//=================================================================

void drv_ifd_set_videopath_output_gain(IFD_VIDEOPATH_OUTPUT_GAIN data_gain)
{
	ifd_108_shape_filter_selection_RBUS shape_filter_selection_rbus_data;

	shape_filter_selection_rbus_data.regValue = rtd_inl(IFD_108_shape_filter_selection_reg);
	shape_filter_selection_rbus_data.data_gain_sel = data_gain;
	rtd_outl(IFD_108_shape_filter_selection_reg, shape_filter_selection_rbus_data.regValue);
}
IFD_VIDEOPATH_OUTPUT_GAIN drv_ifd_set_videopath_output_gain_get_info(void)
{
	ifd_108_shape_filter_selection_RBUS shape_filter_selection_rbus_data;

	shape_filter_selection_rbus_data.regValue = rtd_inl(IFD_108_shape_filter_selection_reg);
	return (IFD_VIDEOPATH_OUTPUT_GAIN)shape_filter_selection_rbus_data.data_gain_sel;
}
//=================================================================
//Shaping
//=================================================================
void drv_ifd_set_shaping_filter(IFD_SHAPING_BW_SEL shaping_bw_sel)
{
	ifd_108_shape_filter_selection_RBUS shape_filter_selection_rbus_data;

	shape_filter_selection_rbus_data.regValue = rtd_inl(IFD_108_shape_filter_selection_reg);
	shape_filter_selection_rbus_data.shaping_bw_sel = shaping_bw_sel;
	rtd_outl(IFD_108_shape_filter_selection_reg, shape_filter_selection_rbus_data.regValue);
}
UINT8 drv_ifd_set_shaping_filter_get_info()
{
	ifd_108_shape_filter_selection_RBUS shape_filter_selection_rbus_data;

	shape_filter_selection_rbus_data.regValue = rtd_inl(IFD_108_shape_filter_selection_reg);
	return shape_filter_selection_rbus_data.shaping_bw_sel;
}
/*=============================================================*/
/**
 * drv_ifd_set_shaping_img
 *
 *
 * @param <shaping_image_sel>
 * @return { void }
 */
void drv_ifd_set_shaping_img(IFD_SHAPING_IMG_SEL shaping_image_sel)
{
	ifd_108_shape_filter_selection_RBUS shape_filter_selection_rbus_data;
	shape_filter_selection_rbus_data.regValue = rtd_inl(IFD_108_shape_filter_selection_reg);
	shape_filter_selection_rbus_data.shaping_image_sel = shaping_image_sel;
	rtd_outl(IFD_108_shape_filter_selection_reg, shape_filter_selection_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_set_shaping_filter_img_get_info
 *
 *
 * @param <void>
 * @return <shaping_image_sel>
 */
bool drv_ifd_set_shaping_filter_img_get_info()
{
	ifd_108_shape_filter_selection_RBUS shape_filter_selection_rbus_data;

	shape_filter_selection_rbus_data.regValue = rtd_inl(IFD_108_shape_filter_selection_reg);
	return shape_filter_selection_rbus_data.shaping_image_sel;

}
/*=============================================================*/
/**
 * drv_ifd_soft_reset
 *
 *
 * @param <reset>
 * @return { void }
 */
void drv_ifd_soft_reset(bool reset)
{
	ifd_108_soft_reset_27_clk_phase_RBUS soft_reset_27_clk_phase_rbus_data;

	soft_reset_27_clk_phase_rbus_data.regValue = rtd_inl(IFD_108_soft_reset_27_clk_phase_reg);
	soft_reset_27_clk_phase_rbus_data.soft_reset = reset;
	rtd_outl(IFD_108_soft_reset_27_clk_phase_reg, soft_reset_27_clk_phase_rbus_data.regValue);
}
bool drv_ifd_soft_reset_get_info(void)
{
	ifd_108_soft_reset_27_clk_phase_RBUS soft_reset_27_clk_phase_rbus_data;

	soft_reset_27_clk_phase_rbus_data.regValue = rtd_inl(IFD_108_soft_reset_27_clk_phase_reg);
	return soft_reset_27_clk_phase_rbus_data.soft_reset;
}
/*=============================================================*/
/**
 * drv_ifd_set_54to27_decimation_enable
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_set_54to27_decimation_enable(bool enable)
{
	ifd_108_decimation_filter_enable_RBUS decimation_filter_enable_rbus_data;

	decimation_filter_enable_rbus_data.regValue = rtd_inl(IFD_108_decimation_filter_enable_reg);
	decimation_filter_enable_rbus_data.decimation_en = enable;
	rtd_outl(IFD_108_decimation_filter_enable_reg, decimation_filter_enable_rbus_data.regValue);
};
/*=============================================================*/
/**
 * drv_ifd_eq_en
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_eq_en(bool enable)
{
	ifd_108_eq_filter_sel_RBUS eq_filter_sel_rbus_data;

	eq_filter_sel_rbus_data.regValue = rtd_inl(IFD_108_eq_filter_sel_reg);
	eq_filter_sel_rbus_data.eq_en = enable;
	rtd_outl(IFD_108_eq_filter_sel_reg, eq_filter_sel_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_eq_en_get_info
 *
 *
 * @param <void>
 * @return { enable }
 */
bool drv_ifd_eq_en_get_info(void)
{
	ifd_108_eq_filter_sel_RBUS eq_filter_sel_rbus_data;

	eq_filter_sel_rbus_data.regValue = rtd_inl(IFD_108_eq_filter_sel_reg);
	return (eq_filter_sel_rbus_data.eq_en);
}
/*=============================================================*/
/**
 * drv_ifd_set_eq_coef
 *
 *
 * @param <table>
 * @return { void }
 */
void drv_ifd_set_eq_coef(UINT16 *table)
{
	ifd_108_eq_filter_sel_RBUS eq_filter_sel_rbus_data;
	UINT32 i;
	bool enable_status;

	eq_filter_sel_rbus_data.regValue = rtd_inl(IFD_108_eq_filter_sel_reg);
	enable_status = eq_filter_sel_rbus_data.eq_en;
	rtd_maskl(IFD_108_output_lpf_modify_en_reg, ~((0x1 << 29) | (0x1 << 24)), ((0x0 << 29) | (0x0 << 24)));

	for (i = 0; i < EQ_TABLE_SIZE; i++) {
		eq_filter_sel_rbus_data.regValue = 0;
		rtd_outl(IFD_108_eq_filter_sel_reg, eq_filter_sel_rbus_data.regValue);
		eq_filter_sel_rbus_data.eq_coe_modify_en = 1;
		eq_filter_sel_rbus_data.eq_coe_tap = i;
		eq_filter_sel_rbus_data.eq_coe = table[i];
		rtd_outl(IFD_108_eq_filter_sel_reg, eq_filter_sel_rbus_data.regValue);
	}
	rtd_maskl(IFD_108_output_lpf_modify_en_reg, ~((0x1 << 29) | (0x1 << 24)), ((0x0 << 29) | (0x1 << 24)));
	rtd_maskl(IFD_108_output_lpf_modify_en_reg, ~((0x1 << 29) | (0x1 << 24)), ((0x1 << 29) | (0x0 << 24)));

	eq_filter_sel_rbus_data.regValue = 0;
	eq_filter_sel_rbus_data.eq_en = enable_status;
	rtd_outl(IFD_108_eq_filter_sel_reg, eq_filter_sel_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_get_eq_coef
 *
 *
 * @param <table>
 * @return { void }
 */
void drv_ifd_get_eq_coef(UINT16 *table)
{
	ifd_108_eq_filter_read_RBUS eq_filter_read_rbus_data;

	UINT32 i;

	eq_filter_read_rbus_data.regValue = 0;

	for (i = 0; i < EQ_TABLE_SIZE; i++) {
		eq_filter_read_rbus_data.eq_coe_read_tap = i;
		rtd_outl(IFD_108_eq_filter_sel_reg, eq_filter_read_rbus_data.regValue);
		eq_filter_read_rbus_data.regValue = rtd_inl(IFD_108_eq_filter_sel_reg);

		table[i] = eq_filter_read_rbus_data.eq_coe_read;
	}

	eq_filter_read_rbus_data.regValue = 0;
	rtd_outl(IFD_108_eq_filter_sel_reg, eq_filter_read_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_get_eq_out_rms
 *
 *
 * @param { void }
 * @return { void }
 */
UINT32 drv_ifd_get_eq_out_rms(void)
{
	ifd_108_eq_out_rms_RBUS eq_out_rms_rbus_data;

	eq_out_rms_rbus_data.regValue = rtd_inl(IFD_108_eq_out_rms_reg);

	return eq_out_rms_rbus_data.eq_out_rms;
}
/*=============================================================*/
/**
 * drv_ifd_set_pos_neg_mod
 *
 *
 * @param <mod_sel>
 * @return { void }
 */
void drv_ifd_set_pos_neg_mod(IFD_MODULATION_SEL mod_sel)
{
	ifd27_mod_sel_RBUS mod_sel_rbus_data;

	mod_sel_rbus_data.regValue = rtd_inl(IFD27_mod_sel_reg);
	mod_sel_rbus_data.mod_sel = mod_sel;
	rtd_outl(IFD27_mod_sel_reg, mod_sel_rbus_data.regValue);
}

/*=============================================================*/
/**
 * drv_ifd_set_video_upsample_lp_sel
 *
 *
 * @param <video_bw_sel>
 * @return { void }
 */
void drv_ifd_set_video_upsample_lp_sel(IFD_UPSAMPLE_LP_SEL sel)
{
	ifd_108_video_bw_sel_RBUS video_bw_sel_rbus_data;

	video_bw_sel_rbus_data.regValue = rtd_inl(IFD_108_video_bw_sel_reg);
	video_bw_sel_rbus_data.video_upsample_lp_sel = sel;
	rtd_outl(IFD_108_video_bw_sel_reg, video_bw_sel_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_set_video_upsample_lp_sel_get_info
 *
 *
 * @param <void>
 * @return { video_bw_sel }
 */
IFD_UPSAMPLE_LP_SEL drv_ifd_set_video_upsample_lp_sel_get_info(void)
{
	ifd_108_video_bw_sel_RBUS video_bw_sel_rbus_data;

	video_bw_sel_rbus_data.regValue = rtd_inl(IFD_108_video_bw_sel_reg);
	return (IFD_UPSAMPLE_LP_SEL)(video_bw_sel_rbus_data.video_upsample_lp_sel);
}
/*=============================================================*/
/**
 * drv_ifd_set_video_lpf_bw_1M
 *
 *
 * @param <enable>
 * @return { void }
 */
void drv_ifd_set_video_lpf_bw_1M(bool enable)
{
	ifd_108_video_bw_sel_RBUS video_bw_sel_rbus_data;

	video_bw_sel_rbus_data.regValue = rtd_inl(IFD_108_video_bw_sel_reg);
	video_bw_sel_rbus_data.output_lpf_1m = enable;
	rtd_outl(IFD_108_video_bw_sel_reg, video_bw_sel_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_get_video_lpf_bw_1M
 *
 *
 * @param <void>
 * @return {enable}
 */
bool drv_ifd_get_video_lpf_bw_1M(void)
{
	ifd_108_video_bw_sel_RBUS video_bw_sel_rbus_data;

	video_bw_sel_rbus_data.regValue = rtd_inl(IFD_108_video_bw_sel_reg);
	return video_bw_sel_rbus_data.output_lpf_1m;
}
/*=============================================================*/
/**
 * drv_ifd_grp_delay_en
 *
 *
 * @param <enable><table>
 * @return { void }
 */
void drv_ifd_grp_delay_en(bool enable,  UINT16 *table)
{
	ifd_108_grp_delay_en_RBUS grp_delay_en_rbus_data;
	UINT32 i;

	for (i = 0; i < GP_BPF_TABLE_SIZE; i++) {
		grp_delay_en_rbus_data.regValue = 0;
		rtd_outl(IFD_108_grp_delay_en_reg, grp_delay_en_rbus_data.regValue);
		grp_delay_en_rbus_data.grp_delay_coe_en = 1;
		grp_delay_en_rbus_data.grp_delay_select_tap = i + 1;
		grp_delay_en_rbus_data.grp_delay_coe_modofy = table[i];
		rtd_outl(IFD_108_grp_delay_en_reg, grp_delay_en_rbus_data.regValue);
	}
	grp_delay_en_rbus_data.regValue = 0;
	rtd_outl(IFD_108_grp_delay_en_reg, grp_delay_en_rbus_data.regValue);
	grp_delay_en_rbus_data.grp_delay_en = enable;
	rtd_outl(IFD_108_grp_delay_en_reg, grp_delay_en_rbus_data.regValue);
}
bool drv_ifd_grp_delay_en_get_info(void)
{
	ifd_108_grp_delay_en_RBUS grp_delay_en_rbus_data;

	grp_delay_en_rbus_data.regValue = rtd_inl(IFD_108_grp_delay_en_reg);
	return grp_delay_en_rbus_data.grp_delay_en;
}
void drv_ifd_video_down_sample_filter_en(bool enable)
{
	ifd_108_dnlpf_tap_RBUS donw_sample_lpf_modify_en_rbus_data;

	donw_sample_lpf_modify_en_rbus_data.regValue = 0;
	donw_sample_lpf_modify_en_rbus_data.dnlpf_en = enable;
	rtd_outl(IFD_108_dnlpf_tap_reg, donw_sample_lpf_modify_en_rbus_data.regValue);
}
bool drv_ifd_video_down_sample_filter_en_get_info(void)
{
	ifd_108_dnlpf_tap_RBUS donw_sample_lpf_modify_en_rbus_data;

	donw_sample_lpf_modify_en_rbus_data.regValue = rtd_inl(IFD_108_dnlpf_tap_reg);

	return donw_sample_lpf_modify_en_rbus_data.dnlpf_en;
}

/*=============================================================*/
/**
 * drv_ifd_video_outputlpf_coef_update
 *
 *
 * @param <enable><table>
 * @return { void }
 */
void drv_ifd_video_outputlpf_coef_update(bool enable,  UINT16 *table)
{
	ifd_108_output_lpf_modify_en_RBUS output_lpf_modify_en_rbus_data;
	UINT32 i;

	if (enable == IFD_ENABLE) {
		for (i = 0; i < OUPUT_LPF_TABLE_SIZE; i++) {
			output_lpf_modify_en_rbus_data.regValue = 0;
			output_lpf_modify_en_rbus_data.output_lpf_vsync_coe_change = IFD_ENABLE;
			rtd_outl(IFD_108_output_lpf_modify_en_reg, output_lpf_modify_en_rbus_data.regValue);
			output_lpf_modify_en_rbus_data.output_lpf_coe_modify_en = 1;
			output_lpf_modify_en_rbus_data.output_lpf_coe_tap = i + 1;
			output_lpf_modify_en_rbus_data.output_lpf_coe = table[i];
			rtd_outl(IFD_108_output_lpf_modify_en_reg, output_lpf_modify_en_rbus_data.regValue);
		}
		output_lpf_modify_en_rbus_data.regValue = 0;
		rtd_outl(IFD_108_output_lpf_modify_en_reg, output_lpf_modify_en_rbus_data.regValue);
		output_lpf_modify_en_rbus_data.output_lpf_vsync_coe_change = IFD_ENABLE;
		rtd_outl(IFD_108_output_lpf_modify_en_reg, output_lpf_modify_en_rbus_data.regValue);
	} else {
		output_lpf_modify_en_rbus_data.regValue = 0;
		rtd_outl(IFD_108_output_lpf_modify_en_reg, output_lpf_modify_en_rbus_data.regValue);
	}
}

//=================================================================
//Clamp
//=================================================================
void drv_ifd_clamp_offset_hold(IFD_CLAMP_OFFSET clamp_offset_hold)
{
	ifd27_clamping_scale_RBUS clamping_scale_rbus_data;

	clamping_scale_rbus_data.regValue = rtd_inl(IFD27_clamping_scale_reg);
	clamping_scale_rbus_data.clamp_offset_hold = clamp_offset_hold;
	rtd_outl(IFD27_clamping_scale_reg, clamping_scale_rbus_data.regValue);
}
IFD_CLAMP_OFFSET drv_ifd_clamp_offset_hold_get_info(void)
{
	ifd27_clamping_scale_RBUS clamping_scale_rbus_data;

	clamping_scale_rbus_data.regValue = rtd_inl(IFD27_clamping_scale_reg);
	return (IFD_CLAMP_OFFSET)clamping_scale_rbus_data.clamp_offset_hold;
}
void drv_ifd_clamp_offset_reset(bool clamping_reset)
{
	ifd27_clamping_scale_RBUS clamping_scale_rbus_data;

	clamping_scale_rbus_data.regValue = rtd_inl(IFD27_clamping_scale_reg);
	clamping_scale_rbus_data.clamping_reset = clamping_reset;
	rtd_outl(IFD27_clamping_scale_reg, clamping_scale_rbus_data.regValue);
}
bool drv_ifd_clamp_offset_reset_get_info(void)
{
	ifd27_clamping_scale_RBUS clamping_scale_rbus_data;

	clamping_scale_rbus_data.regValue = rtd_inl(IFD27_clamping_scale_reg);
	return clamping_scale_rbus_data.clamping_reset;
}
/*=============================================================*/
/**
 * drv_ifd_set_clamping_scale
 *
 *
 * @param <clamping_scale>
 * @return { void }
 */
void drv_ifd_set_clamping_scale(IFD_CLAMP_SCALE clamping_scale)
{
	ifd27_clamping_scale_RBUS clamping_scale_rbus_data;

	clamping_scale_rbus_data.regValue = rtd_inl(IFD27_clamping_scale_reg);
	clamping_scale_rbus_data.clamping_scale = clamping_scale;
	rtd_outl(IFD27_clamping_scale_reg, clamping_scale_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_set_clamping_scale_get_info
 *
 *
 * @param <void>
 * @return { clamping_scale }
 */
IFD_CLAMP_SCALE drv_ifd_set_clamping_scale_get_info(void)
{
	ifd27_clamping_scale_RBUS clamping_scale_rbus_data;

	clamping_scale_rbus_data.regValue = rtd_inl(IFD27_clamping_scale_reg);
	return (IFD_CLAMP_SCALE)(clamping_scale_rbus_data.clamping_scale);
}
/*=============================================================*/
/**
 * drv_ifd_set_clamping_thr_max
 *
 *
 * @param <clamping_thr_max>
 * @return <void>
 */
void drv_ifd_set_clamping_thr_max(UINT16 clamping_thr_max)
{
	ifd27_clamping_thr_max_RBUS clamping_thr_max_rbus_data;

	clamping_thr_max_rbus_data.regValue = rtd_inl(IFD27_clamping_thr_max_reg);
	clamping_thr_max_rbus_data.clamping_thr_max = clamping_thr_max;
	rtd_outl(IFD27_clamping_thr_max_reg, clamping_thr_max_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_set_clamping_thr_max_get_info
 *
 *
 * @param <void>
 * @return <clamping_thr_max>
 */
UINT16 drv_ifd_set_clamping_thr_max_get_info(void)
{
	ifd27_clamping_thr_max_RBUS clamping_thr_max_rbus_data;

	clamping_thr_max_rbus_data.regValue = rtd_inl(IFD27_clamping_thr_max_reg);
	return (clamping_thr_max_rbus_data.clamping_thr_max);


}
/*=============================================================*/
/**
 * drv_ifd_set_clamping_thr_min
 *
 *
 * @param <clamping_thr_min>
 * @return <void>
 */
void drv_ifd_set_clamping_thr_min(UINT16 clamping_thr_min)
{
	ifd27_clamping_thr_min_RBUS clamping_thr_min_rbus_data;

	clamping_thr_min_rbus_data.regValue = rtd_inl(IFD27_clamping_thr_min_reg);
	clamping_thr_min_rbus_data.clamping_thr_min = clamping_thr_min;
	rtd_outl(IFD27_clamping_thr_min_reg, clamping_thr_min_rbus_data.regValue);
}
/*=============================================================*/
/**
 * drv_ifd_set_clamping_thr_min_get_info
 *
 *
 * @param <void>
 * @return <clamping_thr_min>
 */
UINT16 drv_ifd_set_clamping_thr_min_get_info(void)
{
	ifd27_clamping_thr_min_RBUS clamping_thr_min_rbus_data;

	clamping_thr_min_rbus_data.regValue = rtd_inl(IFD27_clamping_thr_min_reg);
	return (clamping_thr_min_rbus_data.clamping_thr_min);


}
/*=============================================================*/
/**
 * drv_ifd_get_clamping_offset_status
 *
 *
 * @param <void>
 * @return <clamping_offset_status>
 */
UINT16 drv_ifd_get_clamping_offset_status(void)
{
	ifd27_offset_RBUS offset_rbus_data;

	offset_rbus_data.regValue = rtd_inl(IFD27_offset_reg);

	return offset_rbus_data.offset_status;
}
/*=============================================================*/
/**
 * drv_ifd_bypass_demod
 *
 *
 * @param <bypass>
 * @return { void }
 */
void drv_ifd_bypass_demod(bool bypass)
{
	ifd_108_adbypassenable_RBUS ad_bypass_enable_rbus_data;

	ad_bypass_enable_rbus_data.regValue = rtd_inl(IFD_108_adbypassenable_reg);
	ad_bypass_enable_rbus_data.bypassad = bypass;
	rtd_outl(IFD_108_adbypassenable_reg , ad_bypass_enable_rbus_data.regValue);
}


/*=============================================================*/
/**
 * drv_ifd_adc_clk_sel
 *
 *
 * @param <clk_rate>
 * @return { void }
 */
void drv_ifd_adc_clk_sel(IFD_CLK_RATE clk_rate, IFD_INPUT_DN_FILTER input_dn_filter)
{
	vd_ifd_input_input_filter_set_RBUS input_filter_set_data;

	input_filter_set_data.regValue = rtd_inl(VD_IFD_INPUT_input_filter_set_reg);

	switch (clk_rate) {
	case IFD_CLK_RATE_108M:
		input_filter_set_data.adc_clk_sel = 1;
		input_filter_set_data.input_dn_filter_sel = input_dn_filter;
		break;
	case IFD_CLK_RATE_54M:
		input_filter_set_data.adc_clk_sel = 0;
		input_filter_set_data.input_dn_filter_sel = 0;
		break;
	case IFD_CLK_RATE_135M:
		input_filter_set_data.adc_clk_sel = 2;
		input_filter_set_data.input_dn_filter_sel = (0x1 << 1 | input_dn_filter);
		break;
	case IFD_CLK_RATE_162M:
		input_filter_set_data.adc_clk_sel = 3;
		input_filter_set_data.input_dn_filter_sel = (0x1 << 2 | input_dn_filter);
		break;
	default:
		break;
	}

	rtd_outl(VD_IFD_INPUT_input_filter_set_reg, input_filter_set_data.regValue);

	drv_ifd_adc_clock(clk_rate);
	//drvif_module_vdc_FIFO_CLK_setting();
}

/*=============================================================*/
/**
 * drv_ifd_adc_clk_sel_get_info
 *
 *
 * @param <void>
 * @return { clk_rate }
 */
IFD_CLK_RATE drv_ifd_adc_clk_sel_get_info(void)
{
	vd_ifd_input_input_filter_set_RBUS input_filter_set_data;
	IFD_CLK_RATE clk_rate;

	input_filter_set_data.regValue = rtd_inl(VD_IFD_INPUT_input_filter_set_reg);

	switch (input_filter_set_data.adc_clk_sel) {
	case 1:
		clk_rate = IFD_CLK_RATE_108M;
		break;
	case 0:
		clk_rate = IFD_CLK_RATE_54M;
		break;
	case 2:
		clk_rate = IFD_CLK_RATE_135M;
		break;
	case 3:
		clk_rate = IFD_CLK_RATE_162M;
		break;
	default:
		clk_rate = IFD_CLK_RATE_108M;
		break;
	}
	return clk_rate;
}
/*=============================================================*/
/**
 * drv_ifd_outputlpf_vsync
 *
 *
 * @param <input_filter_sel>
 * @return { void }
 */
void drv_ifd_outputlpf_vsync(UINT16 start, UINT16 end)
{
	ifd_108_output_lpf_vsync_start_RBUS output_lpf_vsync_start_rbus_data;

	output_lpf_vsync_start_rbus_data.regValue = rtd_inl(IFD_108_output_lpf_vsync_start_reg);
	output_lpf_vsync_start_rbus_data.lpf_vsync_start = start;
	output_lpf_vsync_start_rbus_data.lpf_vsync_end = end;
	rtd_outl(IFD_108_output_lpf_vsync_start_reg, output_lpf_vsync_start_rbus_data.regValue);
}
//=================================================================
//Modulation Type Detection
//=================================================================
void drv_ifd_mtd_reset(bool enable)
{
	ifd_108_mod_detect_update_cntl_RBUS mod_detect_update_cntl_rbus_data;

	mod_detect_update_cntl_rbus_data.regValue = rtd_inl(IFD_108_mod_detect_update_cntl_reg);
	mod_detect_update_cntl_rbus_data.mod_reset = enable;
	rtd_outl(IFD_108_mod_detect_update_cntl_reg, mod_detect_update_cntl_rbus_data.regValue);
}
bool drv_ifd_mtd_reset_get_info(void)
{
	ifd_108_mod_detect_update_cntl_RBUS mod_detect_update_cntl_rbus_data;

	mod_detect_update_cntl_rbus_data.regValue = rtd_inl(IFD_108_mod_detect_update_cntl_reg);

	return mod_detect_update_cntl_rbus_data.mod_reset;
}
void drv_ifd_mtd_set_thr(UINT8 mod_state_thr, UINT16 neg_mod_thr, UINT16 pos_mod_thr)
{
	ifd_108_mod_detect_thr_RBUS mod_detect_thr_rbus_data;

	mod_detect_thr_rbus_data.regValue = rtd_inl(IFD_108_mod_detect_thr_reg);
	mod_detect_thr_rbus_data.mod_state_thr = mod_state_thr;
	mod_detect_thr_rbus_data.neg_mod_thr = neg_mod_thr;
	mod_detect_thr_rbus_data.pos_mod_thr = pos_mod_thr;
	rtd_outl(IFD_108_mod_detect_thr_reg, mod_detect_thr_rbus_data.regValue);
}
IFD_MTD_STATUS drv_ifd_mtd_get_mod_state(void)
{
	ifd_108_mod_detect_state_RBUS mod_detect_state_rbus_data;

	mod_detect_state_rbus_data.regValue = rtd_inl(IFD_108_mod_detect_state_reg);

	return (IFD_MTD_STATUS)mod_detect_state_rbus_data.mod_state;
}
void drv_ifd_mtd_auto_en(bool enable)
{
	ifd_108_mod_detect_auto_RBUS mod_detect_auto_rbus_data;

	mod_detect_auto_rbus_data.regValue = rtd_inl(IFD_108_mod_detect_auto_reg);
	mod_detect_auto_rbus_data.mod_auto_en = enable;
	rtd_outl(IFD_108_mod_detect_auto_reg, mod_detect_auto_rbus_data.regValue);
}
bool drv_ifd_mtd_auto_en_get_info(void)
{
	ifd_108_mod_detect_auto_RBUS mod_detect_auto_rbus_data;

	mod_detect_auto_rbus_data.regValue = rtd_inl(IFD_108_mod_detect_auto_reg);
	return mod_detect_auto_rbus_data.mod_auto_en;
}
//=================================================================
//Interrupt
//=================================================================
void drv_ifd_interrupt_input_fifo_clear(void)
{
	ifd_108_interrupt_mask_en_RBUS interrupt_mask_en_rbus_data;
	ifd_108_interrupt_RBUS	interrupt_read_rbus_data;
	interrupt_mask_en_rbus_data.regValue = rtd_inl(IFD_108_interrupt_mask_en_reg);
	interrupt_read_rbus_data.regValue = rtd_inl(IFD_108_interrupt_reg);
	interrupt_mask_en_rbus_data.regValue = 0xffff & interrupt_mask_en_rbus_data.regValue;
	interrupt_read_rbus_data.input_fifo_int = 0x1;
	rtd_outl(IFD_108_interrupt_mask_en_reg, interrupt_mask_en_rbus_data.regValue);
}
bool drv_ifd_interrupt_input_fifo_status_get_info(void)
{
	ifd_108_interrupt_RBUS	interrupt_read_rbus_data;

	interrupt_read_rbus_data.regValue = rtd_inl(IFD_108_interrupt_reg);
	return interrupt_read_rbus_data.input_fifo_int;
}
//=================================================================
//Simple h
//=================================================================
void drv_ifd_set_simple_h_deb(UINT16 deb)
{
	ifd27_simple_h_cntl_RBUS simple_h_deb_rbus_data;

	simple_h_deb_rbus_data.regValue = rtd_inl(IFD27_simple_h_cntl_reg);
	simple_h_deb_rbus_data.simple_h_deb = deb & 0x1F;
	rtd_outl(IFD27_simple_h_cntl_reg, simple_h_deb_rbus_data.regValue);
}
UINT16 drv_ifd_get_simple_h_deb(void)
{
	ifd27_simple_h_cntl_RBUS simple_h_deb_rbus_data;

	simple_h_deb_rbus_data.regValue = rtd_inl(IFD27_simple_h_cntl_reg);
	return simple_h_deb_rbus_data.simple_h_deb;
}
void drv_ifd_set_simple_h_thd(UINT16 thd)
{
	ifd27_simple_h_cntl_RBUS simple_h_deb_rbus_data;

	simple_h_deb_rbus_data.regValue = rtd_inl(IFD27_simple_h_cntl_reg);
	simple_h_deb_rbus_data.simple_h_thd = thd & 0x1FFF;
	rtd_outl(IFD27_simple_h_cntl_reg, simple_h_deb_rbus_data.regValue);
}
UINT16 drv_ifd_get_simple_h_thd(void)
{
	ifd27_simple_h_cntl_RBUS simple_h_deb_rbus_data;

	simple_h_deb_rbus_data.regValue = rtd_inl(IFD27_simple_h_cntl_reg);
	return simple_h_deb_rbus_data.simple_h_thd;
}
UINT16 drv_ifd_get_simple_h_len_iir(void)
{
	ifd27_simple_h_status_RBUS simple_h_status_rbus_data;

	simple_h_status_rbus_data.regValue = rtd_inl(IFD27_simple_h_status_reg);
	return simple_h_status_rbus_data.simple_h_len_iir;
}
UINT16 drv_ifd_get_simple_h_len(void)
{
	ifd27_simple_h_status_RBUS simple_h_status_rbus_data;

	simple_h_status_rbus_data.regValue = rtd_inl(IFD27_simple_h_status_reg);
	return simple_h_status_rbus_data.simple_h_len;
}
UINT16 drv_ifd_get_noise_status(void)
{
	vdtop_noise_status_RBUS vdtop_noise_status_rbus_data;

	vdtop_noise_status_rbus_data.regValue = rtd_inl(VDTOP_NOISE_STATUS_reg);
	return vdtop_noise_status_rbus_data.status_noise;
}
