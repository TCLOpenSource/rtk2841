typedef enum  {
	IFD_VIDEOPATH_OUTPUT_GAIN_1 = 0 ,
	IFD_VIDEOPATH_OUTPUT_GAIN_2 = 1 ,
	IFD_VIDEOPATH_OUTPUT_GAIN_4 = 2 ,
	IFD_VIDEOPATH_OUTPUT_GAIN_ADAPTIVE = 3 ,
} IFD_VIDEOPATH_OUTPUT_GAIN;

typedef enum  {
	IFD_SHAPING_BW_SEL_BYPASS = 0 ,
	IFD_SHAPING_BW_SEL_0P86M,
} IFD_SHAPING_BW_SEL;

typedef enum  {
	IFD_SHAPING_IMG_NEG = 0 ,
	IFD_SHAPING_IMG_POS,
} IFD_SHAPING_IMG_SEL;

typedef enum  {
	IFD_MODULATION_SEL_POS = 0 ,
	IFD_MODULATION_SEL_NEG,
} IFD_MODULATION_SEL;

typedef enum  {
	IFD_VIDEO_BW_SEL_BYPASS = 0x0,
	IFD_VIDEO_BW_SEL_4P1M = 0x1,
	IFD_VIDEO_BW_SEL_4P14M = 0x2,
	IFD_VIDEO_BW_SEL_4P18M = 0x3 ,
	IFD_VIDEO_BW_SEL_4P2M = 0x4,
	IFD_VIDEO_BW_SEL_4P8M = 0x5,
	IFD_VIDEO_BW_SEL_5P1M = 0x6 ,
	IFD_VIDEO_BW_SEL_5P14M = 0x7,
	IFD_VIDEO_BW_SEL_5P16M = 0x8,
	IFD_VIDEO_BW_SEL_5P17M = 0x9,
	IFD_VIDEO_BW_SEL_5P32M = 0xa,
	IFD_VIDEO_BW_SEL_5P5M = 0xb,
	IFD_VIDEO_BW_SEL_5P7M,
	IFD_VIDEO_BW_SEL_5P8M,
	IFD_VIDEO_BW_SEL_6P0M,
	IFD_VIDEO_BW_SEL_6P2M,
} IFD_VIDEO_BW_SEL;

typedef enum  {
	IFD_UPSAMPLE_LP_SEL_BYPASS = 0  ,
	IFD_UPSAMPLE_LP_SEL_NTSC,
	IFD_UPSAMPLE_LP_SEL_NTSC2,
	IFD_UPSAMPLE_LP_SEL_PAL,
} IFD_UPSAMPLE_LP_SEL;

typedef enum  {
	IFD_CLAMP_OFFSET_NORMAL = 0  ,
	IFD_CLAMP_OFFSET_HOLD,
} IFD_CLAMP_OFFSET;

typedef enum  {
	IFD_CLAMP_SCALE_1D256 = 0  ,
	IFD_CLAMP_SCALE_1D128 = 1  ,
	IFD_CLAMP_SCALE_1D64 = 2  ,
	IFD_CLAMP_SCALE_1D32,
	IFD_CLAMP_SCALE_1D16,
	IFD_CLAMP_SCALE_1D8,
	IFD_CLAMP_SCALE_1D4,
	IFD_CLAMP_SCALE_1D2,
	IFD_CLAMP_SCALE_1,
	IFD_CLAMP_SCALE_2,
	IFD_CLAMP_SCALE_4,
} IFD_CLAMP_SCALE;

typedef enum  {
	NOT_DETECT_OVER = 0,
	UNCERTAIN_RESULT,
	POS_MODULATION,
	NEG_MODULATION,
} IFD_MTD_STATUS;

typedef enum  {
	IFD_INPUT_DN_FILTER_108M_HPF = 0  ,
	IFD_INPUT_DN_FILTER_108M_LPF,
	IFD_INPUT_DN_FILTER_135M_BPF,
	IFD_INPUT_DN_FILTER_135M_LPF,
	IFD_INPUT_DN_FILTER_162M_BPF,
	IFD_INPUT_DN_FILTER_162M_LPF,
} IFD_INPUT_DN_FILTER;


//=================================================================
//Input Filter
//=================================================================
void drv_ifd_input_filter_sel(bool enable, UINT16 *table);
void drv_ifd_input_input_fifo_clear(void);
void drv_ifd_input_input_fifo_flag_clear(void);
bool drv_ifd_input_input_fifo_flag_check(void);
//void drv_ifd_input_input_fifo_softreset(bool Enable);
//bool drv_ifd_input_input_fifo_softreset_getinfo(void);



//=================================================================
//Data gain
//=================================================================
void drv_ifd_set_videopath_output_gain(IFD_VIDEOPATH_OUTPUT_GAIN data_gain);
IFD_VIDEOPATH_OUTPUT_GAIN drv_ifd_set_videopath_output_gain_get_info(void);
//=================================================================
//Shaping
//=================================================================
void drv_ifd_set_shaping_filter(IFD_SHAPING_BW_SEL shaping_bw_sel);
UINT8 drv_ifd_set_shaping_filter_get_info(void);
void drv_ifd_set_shaping_img(IFD_SHAPING_IMG_SEL shaping_image_sel);
bool drv_ifd_set_shaping_filter_img_get_info(void);
void drv_ifd_soft_reset(bool reset);
bool drv_ifd_soft_reset_get_info(void);
void drv_ifd_set_54to27_decimation_enable(bool enable);
void drv_ifd_eq_en(bool enable);
bool drv_ifd_eq_en_get_info(void);
void drv_ifd_set_eq_coef(UINT16 *table);
void drv_ifd_get_eq_coef(UINT16 *table);
UINT32 drv_ifd_get_eq_out_rms(void);
void drv_ifd_set_pos_neg_mod(IFD_MODULATION_SEL mod_sel);
void drv_ifd_set_video_upsample_lp_sel(IFD_UPSAMPLE_LP_SEL sel);
IFD_UPSAMPLE_LP_SEL drv_ifd_set_video_upsample_lp_sel_get_info(void);
void drv_ifd_grp_delay_en(bool enable,  UINT16 *table);
bool drv_ifd_grp_delay_en_get_info(void);
void drv_ifd_video_outputlpf_coef_update(bool enable,  UINT16 *table);
void drv_ifd_video_down_sample_filter_en(bool enable);
bool drv_ifd_video_down_sample_filter_en_get_info(void);
//=================================================================
//Clamp
//=================================================================
void drv_ifd_clamp_offset_hold(IFD_CLAMP_OFFSET clamp_offset_hold);
IFD_CLAMP_OFFSET drv_ifd_clamp_offset_hold_get_info(void);
void drv_ifd_clamp_offset_reset(bool clamping_reset);
bool drv_ifd_clamp_offset_reset_get_info(void);
void drv_ifd_set_clamping_scale(IFD_CLAMP_SCALE clamping_scale);
IFD_CLAMP_SCALE drv_ifd_set_clamping_scale_get_info(void);
void drv_ifd_set_clamping_thr_max(UINT16 clamping_thr_max);
UINT16 drv_ifd_set_clamping_thr_max_get_info(void);
void drv_ifd_set_clamping_thr_min(UINT16 clamping_thr_min);
UINT16 drv_ifd_set_clamping_thr_min_get_info(void);
UINT16 drv_ifd_get_clamping_offset_status(void);

void drv_ifd_bypass_demod(bool bypass);
void drv_ifd_adc_clk_sel(IFD_CLK_RATE clk_rate, IFD_INPUT_DN_FILTER input_dn_filter);
IFD_CLK_RATE drv_ifd_adc_clk_sel_get_info(void);
void drv_ifd_outputlpf_vsync(UINT16 start, UINT16 end);


//=================================================================
//Modulation Type Detection
//=================================================================
void drv_ifd_mtd_reset(bool enable);
bool drv_ifd_mtd_reset_get_info(void);
void drv_ifd_mtd_set_thr(UINT8 mod_state_thr, UINT16 neg_mod_thr, UINT16 pos_mod_thr);
IFD_MTD_STATUS drv_ifd_mtd_get_mod_state(void);
void drv_ifd_mtd_auto_en(bool enable);
bool drv_ifd_mtd_auto_en_get_info(void);

//=================================================================
//Interrupt
//=================================================================
void drv_ifd_interrupt_input_fifo_clear(void);
bool drv_ifd_interrupt_input_fifo_status_get_info(void);

//=================================================================
// 1M video lpf
//=================================================================
void drv_ifd_set_video_lpf_bw_1M(bool enable);
bool drv_ifd_get_video_lpf_bw_1M(void);

//=================================================================
//Simple h
//=================================================================
void drv_ifd_set_simple_h_deb(UINT16 deb);
UINT16 drv_ifd_get_simple_h_deb(void);
void drv_ifd_set_simple_h_thd(UINT16 thd);
UINT16 drv_ifd_get_simple_h_thd(void);
UINT16 drv_ifd_get_simple_h_len_iir(void);
UINT16 drv_ifd_get_simple_h_len(void);

/*=====================================================================
*noise status
======================================================================*/
UINT16 drv_ifd_get_noise_status(void);

