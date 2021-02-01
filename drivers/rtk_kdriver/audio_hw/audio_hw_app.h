#ifndef AUDIO_HW_APP_H
#define AUDIO_HW_APP_H

#define USR_MUTE_NUM			0	/* if AP want more mute_by_who, increase this number */
#define LIB_MUTE_NUM			6
#define VOL_MUTE_ID			(USR_MUTE_NUM + 0)
#define BAL_MUTE_ID			(USR_MUTE_NUM + 1)
#define AIO_MUTE_ID			(USR_MUTE_NUM + 2)
#define ATV_MUTE_ID			(USR_MUTE_NUM + 3)
#define AP_MUTE_ID			(USR_MUTE_NUM + 4)
#define ROS_MUTE_ID			(USR_MUTE_NUM + 5)
#define APP_MUTE_NUM			(USR_MUTE_NUM + LIB_MUTE_NUM)

#define APP_VOL_0DB			0
#define APP_VOL_STEP_MIN		1
#define APP_VOL_STEP_1DB		8				// 0.125dB per step
#define APP_MAX_VOL			((47)*APP_VOL_STEP_1DB)		// (+47.875dB)
#define APP_MIN_VOL			(-72*APP_VOL_STEP_1DB)		// (-72dB)
#define APP_MAX_BAL			(50*APP_VOL_STEP_1DB)
#define APP_MIN_BAL			(-50*APP_VOL_STEP_1DB)

#define APP_LOUD_COEF_NUM		21
#define APP_LOUD_SR_NUM			3	//support 32k\44k\48k

#define APP_EQ_SR_NUM			3	//support 32k\44k\48k
#define APP_EQ_COEF_NUM			21
#define APP_EQ_BAND_NUM			16

#define APP_EQ_BAND_MAX_NUM		16	// define for HwpGetFreqEQ max band number
#define APP_EQ_BAND_MAX			16	// LPF+14BPF+HPF
#define APP_EQ_BAND_ID0			0	// LPF
#define APP_EQ_BAND_ID1			1	// BPF1
#define APP_EQ_BAND_ID2			2	// BPF2
#define APP_EQ_BAND_ID3			3	// BPF3
#define APP_EQ_BAND_ID4			4	// BPF4
#define APP_EQ_BAND_ID5			5	// BPF5
#define APP_EQ_BAND_ID6			6	// BPF6
#define APP_EQ_BAND_ID7			7	// BPF7
#define APP_EQ_BAND_ID8			8	// BPF8
#define APP_EQ_BAND_ID9			9	// BPF9
#define APP_EQ_BAND_ID10		10	// BPF10
#define APP_EQ_BAND_ID11		11	// BPF11
#define APP_EQ_BAND_ID12		12	// BPF12
#define APP_EQ_BAND_ID13		13	// BPF13
#define APP_EQ_BAND_ID14		14	// BPF14
#define APP_EQ_BAND_ID15		15	// HPF

#define APP_EQ_BASS_BAND_ID		(APP_EQ_BAND_NUM+2)	// the bass index for HwpGetFreqEQ rpc
#define APP_EQ_TREBLE_BAND_ID		(APP_EQ_BAND_NUM+3)	// the treble index for HwpGetFreqEQ rpc
#define APP_EQ_TREBLE2_BAND_ID		(APP_EQ_BAND_NUM+4)	// the treble2 index for HwpGetFreqEQ rpc

#define APP_LOUD_BAND_NUM		3
#define APP_LOUD_BAND_ID0		0
#define APP_LOUD_BAND_ID1		1
#define APP_LOUD_BAND_ID2		2
#define APP_BASS_BAND_ID		APP_LOUD_BAND_ID0
#define APP_TREBLE_BAND_ID		APP_LOUD_BAND_ID1
#define APP_TREBLE2_BAND_ID		APP_LOUD_BAND_ID2

#define APP_EQ_TYPE_ID			0
#define APP_BASS_TYPE_ID		1
#define APP_TREBLE_TYPE_ID		2
#define APP_TREBLE2_TYPE_ID		3

#define APP_FREQ_EQ_LPF_TYPE		0
#define APP_FREQ_EQ_BPF_TYPE		1
#define APP_FREQ_EQ_HPF_TYPE		2

#define APP_MONI_CH_MASK		0x30
#define APP_MONI_CHANNEL_NUM		2
#define APP_MONI_SPECTRUM_NUM		256

#define AIO_ERR_APP_INVALID_VOL		((AIO_ERR_CODE_APP) | 0x0101)
#define AIO_ERR_APP_INVALID_MUTE	((AIO_ERR_CODE_APP) | 0x0201)
#define AIO_ERR_APP_INVALID_AVC		((AIO_ERR_CODE_APP) | 0x0301)
#define AIO_ERR_APP_INVALID_EQ_COEF	((AIO_ERR_CODE_APP) | 0x0401)
#define AIO_ERR_APP_INVALID_EQ_VOL	((AIO_ERR_CODE_APP) | 0x0402)
#define AIO_ERR_APP_INVALID_TREBLE_COEF	((AIO_ERR_CODE_APP) | 0x0403)
#define AIO_ERR_APP_INVALID_TREBLE_VOL	((AIO_ERR_CODE_APP) | 0x0404)
#define AIO_ERR_APP_INVALID_BASS_COEF	((AIO_ERR_CODE_APP) | 0x0405)
#define AIO_ERR_APP_INVALID_BASS_VOL	((AIO_ERR_CODE_APP) | 0x0406)
#define AIO_ERR_APP_INVALID_SPK_COMP	((AIO_ERR_CODE_APP) | 0x0407)
#define AIO_ERR_APP_INVALID_SPATIAL	((AIO_ERR_CODE_APP) | 0x0501)
#define AIO_ERR_APP_INVALID_BEEPER	((AIO_ERR_CODE_APP) | 0x0601)

typedef enum {
	APP_ID_CAPABILITY		= 0,
	// bit-mapping setting
	// [ 0:15] for HWP
	APP_ID_HWP_AVC			= (0x1 << 0),
	APP_ID_HWP_TREBLE		= (0x1 << 1),
	APP_ID_HWP_BASS			= (0x1 << 2),
	APP_ID_HWP_EQ			= (0x1 << 3),
	APP_ID_HWP_SPK_COMP		= (0x1 << 4),
	APP_ID_HWP_SPL_EFFECT		= (0x1 << 5),
	APP_ID_HWP_AVC2			= (0x1 << 6),
	APP_ID_HWP_7			= (0x1 << 7),
	APP_ID_HWP_8			= (0x1 << 8),
	APP_ID_HWP_9			= (0x1 << 9),
	APP_ID_HWP_10			= (0x1 << 10),
	APP_ID_HWP_11			= (0x1 << 11),
	APP_ID_HWP_12			= (0x1 << 12),
	APP_ID_HWP_13			= (0x1 << 13),
	APP_ID_HWP_14			= (0x1 << 14),
	APP_ID_HWP_15			= (0x1 << 15),
	// [16:31] for SWP
	APP_ID_SWP_SRS_TSXT		= (0x1 << 16),
	APP_ID_SWP_SRS_WOW		= (0x1 << 17),
	APP_ID_SWP_BBE_SOUND		= (0x1 << 18),
	APP_ID_SWP_RTK_RVB		= (0x1 << 19),
	APP_ID_SWP_RTK_SURROUND		= (0x1 << 20),
	APP_ID_SWP_MONITOR		= (0x1 << 21),
	APP_ID_SWP_22			= (0x1 << 22),
	APP_ID_SWP_23			= (0x1 << 23),
	APP_ID_SWP_24			= (0x1 << 24),
	APP_ID_SWP_25			= (0x1 << 25),
	APP_ID_SWP_26			= (0x1 << 26),
	APP_ID_SWP_27			= (0x1 << 27),
	APP_ID_SWP_28			= (0x1 << 28),
	APP_ID_SWP_29			= (0x1 << 29),
	APP_ID_SWP_30			= (0x1 << 30),
	APP_ID_SWP_31			= (0x1 << 31),
} APP_ID;

typedef enum {
     // bit-mapping setting
	APP_CH_ID_L		= (0x1 << 0), //ch0
	APP_CH_ID_R		= (0x1 << 1), //ch1
	APP_CH_ID_LS	= 0xFE, // Dummy
	APP_CH_ID_RS	= 0xFD, // Dummy
	APP_CH_ID_C		= 0xFC, // Dummy
	APP_CH_ID_SW	= 0xFB, // Dummy
	APP_CH_ID_SSL	= (0x1 << 6),
	APP_CH_ID_SSR	= (0x1 << 7),
	// new CH_ID define
	APP_CH_ID_CH0	= (0x1 << 0), //ch0
	APP_CH_ID_CH1	= (0x1 << 1), //ch1
	APP_CH_ID_CH2	= (0x1 << 2), //ch2
	APP_CH_ID_CH3	= (0x1 << 3), //ch3
	APP_CH_ID_CH4	= (0x1 << 4), //ch4
	APP_CH_ID_CH5	= (0x1 << 5), //ch5
	APP_CH_ID_CH6	= (0x1 << 6),
	APP_CH_ID_CH7	= (0x1 << 7),
    APP_CH_ID_ALL	= 0xFF,
} APP_CH_ID;

typedef enum {
	// bit-mapping setting
	APP_BALANCE_CH_ID_CH01		= (0x1 << 0),   //ch01
	APP_BALANCE_CH_ID_CH23		= (0x1 << 1),   //ch23
	APP_BALANCE_CH_ID_CH45		= (0x1 << 2),   //ch45
	APP_BALANCE_CH_ID_CH67		= (0x1 << 3),
	APP_BALANCE_CH_ID_ALL			= 0xFF,
} APP_BALANCE_CH_ID;

typedef enum {
	// bit-mapping setting
	APP_ADC_CH_ID_L			= (0x1 << 0),   //ch0
	APP_ADC_CH_ID_R			= (0x1 << 1),   //ch1
} APP_ADC_CH_ID;

typedef enum {
	// bit-mapping setting
	APP_DAC_CH_ID_L			= (0x1 << 0),   //ch0
	APP_DAC_CH_ID_R			= (0x1 << 1),   //ch1
} APP_DAC_CH_ID;

// H/W-AVC related -------------------------
typedef enum {
	APP_AVC_NOISE_THD_NONE 		= 0,
	APP_AVC_NOISE_THD_M90DB		= 1,
	APP_AVC_NOISE_THD_M84DB		= 2,
	APP_AVC_NOISE_THD_M78DB		= 4,
	APP_AVC_NOISE_THD_M72DB		= 8,
	APP_AVC_NOISE_THD_M66DB		= 16,
	APP_AVC_NOISE_THD_M60DB		= 32,
	APP_AVC_NOISE_THD_M54DB		= 64,
	APP_AVC_NOISE_THD_M48DB		= 128,
	APP_AVC_NOISE_THD_M42DB		= 256,
	APP_AVC_NOISE_THD_M36DB		= 511,      // prevent overflow
} APP_AVC_NOISE_THD;

typedef enum {
	APP_AVC_SIGNAL_LVL_RSVD		= 0,
	APP_AVC_SIGNAL_LVL_M42DB	= 1,
	APP_AVC_SIGNAL_LVL_M36DB	= 2,
	APP_AVC_SIGNAL_LVL_M33DB	= 3,        // 32.6dB
	APP_AVC_SIGNAL_LVL_M30DB	= 4,
	APP_AVC_SIGNAL_LVL_M27DB	= 6,        // 26.6dB
	APP_AVC_SIGNAL_LVL_M25DB	= 7,        // 25.24db
	APP_AVC_SIGNAL_LVL_M24DB	= 8,
	APP_AVC_SIGNAL_LVL_M23DB	= 9,        // 23.06db
	APP_AVC_SIGNAL_LVL_M21DB	= 11,       // 21.3dB
	APP_AVC_SIGNAL_LVL_M18DB	= 16,
	APP_AVC_SIGNAL_LVL_M15DB	= 23,       // 14.9dB
	APP_AVC_SIGNAL_LVL_M12DB	= 32,
	APP_AVC_SIGNAL_LVL_M9DB		= 46,       // 8.9dB
	APP_AVC_SIGNAL_LVL_M6DB		= 64,
	APP_AVC_SIGNAL_LVL_M3DB		= 91,       // 3dB
} APP_AVC_SIGNAL_LVL;

typedef enum {
	APP_AVC_NOISE_GAIN_M6DB,
	APP_AVC_NOISE_GAIN_M12DB,
	APP_AVC_NOISE_GAIN_M18DB,
	APP_AVC_NOISE_GAIN_M24DB
} APP_AVC_NOISE_GAIN;

typedef enum {
	APP_AVC_STEP_GAIN_1P000DB,
	APP_AVC_STEP_GAIN_0P500DB,
	APP_AVC_STEP_GAIN_0P250DB,
	APP_AVC_STEP_GAIN_0P125DB
} APP_AVC_STEP_GAIN;

typedef enum {
	APP_AVC_LPF_COEF_12,        // The slowest
	APP_AVC_LPF_COEF_10,
	APP_AVC_LPF_COEF_8,
	APP_AVC_LPF_COEF_6,
	APP_AVC_LPF_COEF_4,
	APP_AVC_LPF_COEF_2,     // The fastest
} APP_AVC_LPF_COEF;

typedef enum {
	APP_DIST_LPF_COEF_12,       // The slowest
	APP_DIST_LPF_COEF_10,
	APP_DIST_LPF_COEF_8,
	APP_DIST_LPF_COEF_6,        // The fastest
} APP_DIST_LPF_COEF;

typedef enum {
	Disable_path = 0,
	PB_path = 1,
	TS_path = 2,
	PB_TS_path	= 3
} APP_AUDIO_PATH;

typedef struct {
	// identical to the order in register's field
	unsigned vol_detect:2;
	unsigned noise_gain:2;      // refer to enum of APP_AVC_NOISE_GAIN
	unsigned noise_thd:8;
	uint32_t level_max;
	uint32_t level_min;
	unsigned step_up:2;     // refer to enum of APP_AVC_STEP_GAIN
	unsigned step_down:2;       // refer to enum of APP_AVC_STEP_GAIN

	// identical to the order in register's field
	unsigned thd_cnt:10;
	unsigned win_zcross:10;
	unsigned win_moniter:10;

	// identical to the order in register's field
	unsigned avc_vol_amplif_enable:1;
	unsigned avc1_coef:3;
	uint32_t avc_small_level_max;
	uint32_t avc_small_level_min;
	unsigned avc_small_down_db:2;
	unsigned avc_small_up_db:2;
	unsigned avc_small_cnt_thre:8;

	// identical to the order in register's field
	unsigned avc_lower_step_mag_thre:8;
	unsigned avc_amplif_step_mag_thre:8;
	uint32_t avc_small_level:16;

	// identical to the order in register's field  <AVC_gain_step_control_0>
	unsigned avc_lower_step_cnt_low_thre:8;
	unsigned avc_lower_step_cnt_hi_thre:8;
	unsigned avc_amplif_step_cnt_low_thre:8;
	unsigned avc_amplif_step_cnt_hi_thre:8;

	// identical to the order in register's field  <AVC_gain_step_control_1>
	unsigned reserved:24;
	unsigned avc_down_db_fine:2;
	unsigned avc_up_db_fine:2;
	unsigned avc_small_down_db_fine:2;
	unsigned avc_small_up_db_fine:2;
} APP_AVC_CFG;

typedef struct {
	// identical to the order in register's field
	unsigned res1:1;
	unsigned avc2_vol_amplif_enable:1;
	unsigned avc2_lpf_coef:3;
	unsigned avc2_vol_detect:2;
	unsigned fast_recov_ctrl:1;
	unsigned slow_up_db:2;
	unsigned fast_up_db:2;
	unsigned down_db:2;
	unsigned avc2_noise_gain:2;     // refer to enum of APP_AVC_NOISE_GAIN
	unsigned avc2_noise_thre:16;

	// identical to the order in register's field
	unsigned avc2_cnt_thre:10;
	unsigned avc2_zc_win:10;
	unsigned avc2_mon_win:10;

	// identical to the order in register's field
	unsigned avc2_noise_thre_hi:16;
	unsigned recov_win_max:8;
	unsigned recov_win_min:8;

	// identical to the order in register's field
	uint32_t avc2_level_max:16;
	uint32_t avc2_level_min:16;

	// identical to the order in register's field  <AVC2_Control_5_ch01 >
	unsigned res3:10;
	unsigned slow_up_db_fine:2;
	unsigned fast_up_db_fine:2;
	unsigned down_db_fine:2;
	unsigned avc2_small_up_db_fine:2;
	unsigned avc2_small_down_db_fine:2;
	unsigned avc2_small_up_db:2;
	unsigned avc2_small_down_db:2;
	unsigned avc2_small_cnt_thre:8;

	// identical to the order in register's field
	uint32_t avc2_small_level_max:16;
	uint32_t avc2_small_level_min:16;

	// identical to the order in register's field
	uint32_t res4:1;
	uint32_t avc2_small_level:31;
} APP_AVC2_CFG;

typedef struct {
	// identical to the order in register's field
	unsigned res1:1;
	unsigned drc_vol_amplif_enable:1;
	unsigned drc_lpf_coef:3;
	unsigned drc_vol_detect:2;
	unsigned drc_fast_recov_ctrl:1;
	unsigned drc_slow_up_db:2;
	unsigned drc_fast_up_db:2;
	unsigned drc_down_db:2;
	unsigned drc_noise_gain:2;
	unsigned drc_noise_thre:16;

	// identical to the order in register's field
	unsigned drc_cnt_thre:10;
	unsigned drc_zc_win:10;
	unsigned drc_mon_win:10;

	// identical to the order in register's field
	unsigned drc_noise_thre_hi:16;
	unsigned drc_recov_win_max:8;
	unsigned drc_recov_win_min:8;

	// identical to the order in register's field
	uint32_t drc_level_max:16;
	uint32_t drc_level_min:16;

	// identical to the order in register's field
	unsigned res3:10;
	unsigned drc_slow_up_db_fine:2;
	unsigned drc_fast_up_db_fine:2;
	unsigned drc_down_db_fine:2;
	unsigned drc_small_up_db_fine:2;
	unsigned drc_small_down_db_fine:2;
	unsigned drc_small_up_db:2;
	unsigned drc_small_down_db:2;
	unsigned drc_small_cnt_thre:8;

	// identical to the order in register's field
	uint32_t drc_small_level_max:16;
	uint32_t drc_small_level_min:16;

	// identical to the order in register's field
	uint32_t res4:1;
	uint32_t drc_small_level:31;
} APP_DRC_CFG;

typedef struct {
	// identical to the order in register's field
	unsigned res1:1;
	unsigned drc_lpf_vol_amplif_enable:1;
	unsigned drc_lpf_coef:3;
	unsigned drc_lpf_vol_detect:2;
	unsigned drc_lpf_fast_recov_ctrl:1;
	unsigned drc_lpf_slow_up_db:2;
	unsigned drc_lpf_fast_up_db:2;
	unsigned drc_lpf_down_db:2;
	unsigned drc_lpf_noise_gain:2;
	unsigned drc_lpf_noise_thre:16;

	// identical to the order in register's field
	unsigned drc_lpf_cnt_thre:10;
	unsigned drc_lpf_zc_win:10;
	unsigned drc_lpf_mon_win:10;

	// identical to the order in register's field
	unsigned drc_lpf_noise_thre_hi:16;
	unsigned drc_lpf_recov_win_max:8;
	unsigned drc_lpf_recov_win_min:8;

	// identical to the order in register's field
	uint32_t drc_lpf_level_max:16;
	uint32_t drc_lpf_level_min:16;

	// identical to the order in register's field
	unsigned res3:10;
	unsigned  drc_lpf_slow_up_db_fine:2;
	unsigned  drc_lpf_fast_up_db_fine:2;
	unsigned  drc_lpf_down_db_fine:2;
	unsigned  drc_lpf_small_up_db_fine:2;
	unsigned  drc_lpf_small_down_db_fine:2;
	unsigned  drc_lpf_small_up_db:2;
	unsigned  drc_lpf_small_down_db:2;
	unsigned drc_lpf_small_cnt_thre:8;

	// identical to the order in register's field
	uint32_t drc_lpf_small_level_max:16;
	uint32_t drc_lpf_small_level_min:16;

	// identical to the order in register's field
	uint32_t res4:1;
	uint32_t drc_lpf_small_level:31;
} APP_DRC_LPF_CFG;

typedef struct {
	// identical to the order in register's field
	uint32_t dist_vol_detect:2;
	uint32_t dist_coef:3;
	uint32_t dist_high_thre:8;
	uint32_t dist_low_thre:8;
	uint32_t dist_down_db:2;
	uint32_t dist_up_db:2;
	uint32_t dist_cnt_thre:8;
	uint32_t dist_zc_win:12;
	uint32_t dist_mon_win:12;
} APP_DIST_CTRL_CFG;

// H/W-EQ related --------------------------
typedef struct {
	int32_t val;        // range from mix_val to max_val
	int32_t max_val;    // fill the possible max. value of above band values , must be multiple of 6.
	int32_t min_val;    // always equal to -max_val
} APP_TREBLE_VAL;

typedef struct {
	int32_t val;            // range from mix_val to max_val
	int32_t max_val;        // fill the possible max. value of above band values , must be multiple of 6.
	int32_t min_val;        // always equal to -max_val
} APP_BASS_VAL;

typedef struct {
	int32_t val[APP_EQ_BAND_NUM];
	int32_t max_val;        // fill the possible max. value of above band values , must be multiple of 6.
	int32_t min_val;        // always equal to -max_val
} APP_EQ_VAL;

typedef struct {
	int32_t val[9];         // pseudo-9-band value
	int32_t max_val;        // fill the possible max. value of above band values , must be multiple of 6.
	int32_t min_val;        // always equal to -max_val
} APP_9BAND_EQ_VAL;

typedef struct {
	int16_t	a1;
	int16_t	a2;
	int16_t	h0;
} APP_EQ_COEF;

typedef struct {
	int32_t valid_mask;
	int32_t	bw[APP_EQ_BAND_MAX_NUM];
	int32_t	fc[APP_EQ_BAND_MAX_NUM];
	int32_t	gain[APP_EQ_BAND_MAX_NUM];
	int8_t	type[APP_EQ_BAND_MAX_NUM];  // 0,1,2 = LPF,BPF,HPF
} AUDIO_EQ_INFO;

typedef struct {
	// 9 sample-rate(8k,11k,12k,16k,22k,24k,32k,44k,48k) * 1 band * 13 value
	APP_EQ_COEF	coef[APP_LOUD_SR_NUM][APP_LOUD_COEF_NUM];
} APP_TREBLE_CFG;

typedef struct {
	// 9 sample-rate(8k,11k,12k,16k,22k,24k,32k,44k,48k) * 1 band * 13 value
	APP_EQ_COEF	coef[APP_LOUD_SR_NUM][APP_LOUD_COEF_NUM];
} APP_BASS_CFG;

typedef struct {
	// 3 sample-rate(32k,44k,48k) * 6 bands * 13 value
	APP_EQ_COEF	coef[APP_EQ_SR_NUM][APP_EQ_BAND_NUM][APP_EQ_COEF_NUM];
} APP_EQ_CFG;

// Add new typedef for new API of EQ/Bass/Treble/Treble2 related function
typedef struct {
	// Only 1 sample-rate(48k) * 1 band * 21 value
	APP_EQ_COEF	coef[APP_LOUD_COEF_NUM];
} APP_TREBLE_48K_CFG;

typedef struct {
	// Only 1 sample-rate(48k) * 1 band * 21 value
	APP_EQ_COEF	coef[APP_LOUD_COEF_NUM];
} APP_BASS_48K_CFG;

typedef struct {
	// Only 1 sample-rate(48k) * 9 bands * 21 value
	APP_EQ_COEF	coef[APP_EQ_BAND_NUM][APP_EQ_COEF_NUM];
} APP_EQ_48K_CFG;

typedef struct {
	// no matter which sample-rate, 9 bands *(13*13) value
	APP_EQ_COEF coef[9][APP_EQ_COEF_NUM][APP_EQ_COEF_NUM];
} APP_9BAND_EQ_CFG;

typedef struct {
	// 9 sample-rate(8k,11k,12k,16k,22k,24k,32k,44k,48k) * 6 bands
	APP_EQ_COEF	coef[APP_EQ_SR_NUM][APP_EQ_BAND_NUM];
} APP_SPK_CFG;

// H/W-SE related --------------------------
typedef enum {
	APP_SE_M2S_L1 = 0x01F0,
	APP_SE_M2S_L2 = 0x0160,
	APP_SE_M2S_L3 = 0x0120,
	APP_SE_M2S_L4 = 0x0100
} APP_SE_M2S_LEVEL;

typedef enum {
	APP_SE_SPL_L1 = 0x003F,
	APP_SE_SPL_L2 = 0x007F,
	APP_SE_SPL_L3 = 0x00DE,
	APP_SE_SPL_L4 = 0x0100
} APP_SE_SPL_LEVEL;

typedef struct {
	// identical to the order in register's field
	unsigned resvd1:17;
	unsigned apf_en:1;
	unsigned psb_en:1;
	unsigned seb_en:1;
	unsigned sel_l:1;
	unsigned sel_r:1;
	unsigned resvd2:1;
	unsigned apf_coef:9;

	// identical to the order in register's field
	unsigned resvd3:7;
	unsigned depth1:9;
	unsigned resvd4:7;
	unsigned depth2:9;
} APP_SE_CFG;

// H/W-Beeper related ----------------------
typedef struct {
	uint16_t freq;       // Hz
	uint8_t vol;        // att. =  vol*(-3 dB)
	uint8_t mode;       // [0,1] = [pulse mode , continue mode]
	uint8_t mute;       //
	uint16_t duration;   // ms , if mode == pulse, this value must be multiple of 125
} APP_BEEP_CFG;

// H/W-VOL related -------------------------
typedef enum {
	APP_DVOL_ID_USR    = 0,
	APP_DVOL_ID_ATV    = 1,
	APP_DVOL_ID_AIO    = 2,
	APP_DVOL_ID_AIO_NR = 3,
	APP_DVOL_ID_NUM    = 4
} APP_DVOL_ID;

typedef enum {
	APP_DVOL_MODE_NORMAL        = 0,
	APP_DVOL_MODE_ZERO_CROSS    = 1,
	APP_DVOL_MODE_SOFT_RAMP     = 2,
	APP_DVOL_MODE_ZERO_AND_SOFT = 3
} APP_DVOL_MODE;

typedef enum {
	APP_DVOL_ZCTO_1024x1,
	APP_DVOL_ZCTO_1024x2,
	APP_DVOL_ZCTO_1024x4,
	APP_DVOL_ZCTO_1024x8,
	APP_DVOL_ZCTO_1024x16,
	APP_DVOL_ZCTO_1024x32,
	APP_DVOL_ZCTO_1024x64,
	APP_DVOL_ZCTO_1024x128,
} APP_DVOL_ZERO_TIMEOUT;

typedef enum {
	APP_DVOL_RAMP_STEP_1_DIV_8_DB,
	APP_DVOL_RAMP_STEP_2_DIV_8_DB,
	APP_DVOL_RAMP_STEP_4_DIV_8_DB,
	APP_DVOL_RAMP_STEP_8_DIV_8_DB,
} APP_DVOL_RAMP_STEP;

typedef enum {
	APP_MUTE_ZCTO_1024x1,
	APP_MUTE_ZCTO_1024x2,
	APP_MUTE_ZCTO_1024x4,
	APP_MUTE_ZCTO_1024x8,
	APP_MUTE_ZCTO_1024x16,
	APP_MUTE_ZCTO_1024x32,
	APP_MUTE_ZCTO_1024x64,
	APP_MUTE_ZCTO_1024x128,
} APP_MUTE_ZERO_TIMEOUT;

typedef enum {
	APP_MUTE_RAMP_STEP_1_DIV_8_DB,
	APP_MUTE_RAMP_STEP_2_DIV_8_DB,
	APP_MUTE_RAMP_STEP_4_DIV_8_DB,
	APP_MUTE_RAMP_STEP_8_DIV_8_DB,
} APP_MUTE_RAMP_STEP;

typedef struct {
	unsigned resvd1:10;
	unsigned mode:2;
	unsigned zero_thd:5;
	unsigned zero_timeout:3;
	unsigned ramp_step:2;
	unsigned delay_time:10;
} APP_DVOL_CFG;

typedef struct {
	unsigned resvd1:16;
	unsigned on_off:1;
	unsigned zero_timeout:3;
	unsigned ramp_step:2;
	unsigned delay_time:10;
} APP_MUTE_CFG;

// S/W PP-related --------------------------
typedef struct {
	// common use
	uint32_t type;       // surround version ID
	uint32_t lp_gain;    // para for Context Spliter
	uint32_t hp_gain;    // para for Context Spliter
	uint32_t atk_t;      // para for Context Spliter
	uint32_t rel_t;      // para for Context Spliter
	uint32_t gain_thd;   // para for Context Spliter
			     // RealBass
	uint8_t bass_cfg;
	uint8_t bass_harm_th;
	uint8_t bass_harm_tb;
	uint8_t bass_gain_idx;

	// RealTalk
	uint8_t talk_cfg;
	uint8_t talk_gain_idx;

	// RealLive
	uint8_t live_cfg;
	uint8_t live_gain_idx;
} APP_SURD_CFG;

typedef	struct {
	int32_t ModeType;
	int32_t TruBassGain;
	int32_t TruBassSize;
	int32_t FocusGain;
	int32_t InputGain;
	int32_t IsTSXTEnable;
	int32_t IsHeadphoneMode;
	int32_t IsTruBassEnable;
	int32_t IsFocusEnable;
	int32_t DefinitionGain;     // for HD upgrade version only
	int32_t IsDefEnable;        // for HD upgrade version only
	int32_t Volume_compensate;
} APP_TSXT_CFG;

typedef	struct {
	int Enable_Sys;        /* Input is True or False for enable system */
	int StopBandFreq_Sys;  /* Input from 80 to 320, Default is 160 for BassBack speaker Stopband */
	int HarmonicGain;      /* Input from -40 to 0 for BassBack strength */
	int vb_enable;

	/* Bass control  */
	int Sys_EnhanceFreq;   /* Input from 120 to 600 for TruBass Boost enhance High frequency */
	int Tru_StopbandFreq;  /* Input from 80 to 320, Default is 160 for TruBass Boost Low frequency */
	int Set_BassGain;      /* form 0 to 10 dB for TruBass Boost magnitude */
} APP_BASSBACK_TV_CFG;

// Add BassBack Config for AQ TOOL update AQ Data via USB
typedef struct {
	int pp_bassback_ena;
	APP_BASSBACK_TV_CFG bassback_tv_config;
} APP_BASSBACK_CFG;

typedef	struct {
	int  Enable_Sys;        /* Input 琌 True ┪ False硂琌北╰参秨闽 */
	int  StopBandFreq_Sys;  /* Input  琌 80 ~ 320 计, Default 160硂琌北 BassBack 斥  Stopband */
	int  HarmonicGain;      /* Input  琌  -40  ~  0 硂琌ノㄓ北 BassBack 眏 */
	int  SubHarmonicGain;   /* Input  琌  -40  ~  0 硂琌稬秸ゑ耕 harmonic  */
	int  TreHarmonicGain;   /* Input  琌  -40  ~  0 硂琌稬秸ゑ耕蔼 harmonic  */
	int  vb_enable;
	//	int MixEnable;

	/*Bass 北  */
	int  Sys_EnhanceFreq;   /* Input  琌 120 ~ 600 计硂琌北 TruBass Boost 程蔼繵瞯场 */
	int  Tru_StopbandFreq;  /* Input  琌 80 ~ 320 计, Default 160硂琌北 TruBass Boost 繵场だ */
	int  Set_BassGain;      /*  0 ~  10 dB 硂琌北 TruBass Boost  */

	/*High-Pass-Filter*/
	int Enable_HPF;        /* Input 琌 True ┪ False硂琌北 HPF 秨闽 */
	int  StopBandFreq_HPF;  /* Input  琌 80 ~ 320 计, Default 160硂琌北 HPF  Stopband碞琌耾奔﹍癟腹絛瞅 */

	/*PeakFilter */
	int  Enable_PF;         /* ON/OFF of peakfilter */
	int  Gain_PF; /* Gain(dB)*100: 琌 -3000 ~ 1000 计 */
	int  CenterFreq_PF; /* 100~10000 */
	int  BandWidth_PF;  /* 10~3000 */
} APP_BASSBACK_PCBU_CFG;

typedef enum {
	// identical to the order in register's field
	APP_EQ_LOUD_VALUE_DIRECT = 0x0,  // Direct change EQ Para, more stable
	APP_EQ_LOUD_VALUE_STEP = 0x1,      // Step by step changing EQ Para, less pop but has risk of unstability
} APP_EQ_LOUD_VALUE_CHANGE_MODE;

typedef enum {
	// identical to the order in register's field
	APP_DVC_VALUE_DIRECT  = 0x1,	// Direct change mode
	APP_DVC_VALUE_STEP = 0x0		// normal mode
}APP_DVC_VALUE_CHANGE_MODE;

typedef enum {
	APP_MONI_1CH         = 0x10,
	APP_MONI_1CH_BAND16  = 0x11,
	APP_MONI_1CH_BAND32  = 0x12,
	APP_MONI_1CH_BAND64  = 0x13,
	APP_MONI_1CH_BANDALL = 0x14,
	APP_MONI_2CH         = 0x20,
	APP_MONI_2CH_BAND16  = 0x21,
	APP_MONI_2CH_BAND32  = 0x22,
	APP_MONI_2CH_BAND64  = 0x23,
	APP_MONI_2CH_BANDALL = 0x24,
} APP_MONI_MODE;

typedef struct {
	uint32_t vol[APP_MONI_CHANNEL_NUM];
	uint32_t spectrum[APP_MONI_CHANNEL_NUM][APP_MONI_SPECTRUM_NUM];
} APP_MONI_INFO;

typedef enum {
	APP_INFO_MUTE	= 0x0,
} APP_GET_INFO;

typedef enum {
	APP_EQ_SAMPLE_FREQ_32K = 32000,
	APP_EQ_SAMPLE_FREQ_44K = 44100,
	APP_EQ_SAMPLE_FREQ_48K	 = 48000,
	APP_EQ_SAMPLE_FREQ_96K = 96000,
	APP_EQ_SAMPLE_FREQ_88K = 88200,
	APP_EQ_SAMPLE_FREQ_176K = 176000,
	APP_EQ_SAMPLE_FREQ_192K = 192000,
} APP_EQ_SAMPLE_FREQ;

typedef enum {
	APP_EQ_HPF_SLOPE_20DB = 0,
	APP_EQ_HPF_SLOPE_40DB = 1,
} APP_EQ_HPF_SLOPE;

typedef enum {
	APP_EQ_ALL_LPF_BAND1 = 0,
	APP_EQ_ALL_BPF_BAND1 = 1,
	APP_EQ_ALL_BPF_BAND2 = 2,
	APP_EQ_ALL_BPF_BAND3 = 3,
	APP_EQ_ALL_BPF_BAND4 = 4,
	APP_EQ_ALL_BPF_BAND5 = 5,
	APP_EQ_ALL_BPF_BAND6 = 6,
	APP_EQ_ALL_BPF_BAND7 = 7,
	APP_EQ_ALL_BPF_BAND8 = 8,
	APP_EQ_ALL_BPF_BAND9 = 9,
	APP_EQ_ALL_BPF_BAND10 = 10,
	APP_EQ_ALL_BPF_BAND11 = 11,
	APP_EQ_ALL_BPF_BAND12 = 12,
	APP_EQ_ALL_BPF_BAND13 = 13,
	APP_EQ_ALL_BPF_BAND14 = 14,
	APP_EQ_ALL_HPF_BAND1 = 15,
} APP_EQ_ALL_BAND;

typedef enum {
	APP_LOUD_ALL_LPF_BAND1 = 0,
	APP_LOUD_ALL_BPF_BAND1 = 1,
	APP_LOUD_ALL_BPF_BAND2 = 2,
} APP_LOUD_ALL_BAND;

typedef enum {
	APP_EQ_BPF_BAND1 = 1,
	APP_EQ_BPF_BAND2 = 2,
	APP_EQ_BPF_BAND3 = 3,
	APP_EQ_BPF_BAND4 = 4,
	APP_EQ_BPF_BAND5 = 5,
	APP_EQ_BPF_BAND6 = 6,
	APP_EQ_BPF_BAND7 = 7,
	APP_EQ_BPF_BAND8 = 8,
	APP_EQ_BPF_BAND9 = 9,
	APP_EQ_BPF_BAND10 = 10,
	APP_EQ_BPF_BAND11 = 11,
	APP_EQ_BPF_BAND12 = 12,
	APP_EQ_BPF_BAND13 = 13,
	APP_EQ_BPF_BAND14 = 14,
} APP_EQ_BPF_BAND;

typedef enum {
	APP_LOUD_BPF_BAND1 = 1,
	APP_LOUD_BPF_BAND2 = 2,
} APP_LOUD_BPF_BAND;

/**
 * Set L/R channel balance setting
 * if (balance > 0) means that L channel will be attenuated.
 * if (balance < 0) means that R channel will be attenuated.
 * attenuation level is 1 dB per step.
 *
 * @param <balance>	{ range from APP_MIN_BAL ~ APP_MAX_BAL }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
//int32_t Audio_HwpSetBalanceLR(int32_t  balance);
/**
 * Set L/R channel balance setting ( Time-Shift path )
 * if (balance > 0) means that L channel will be attenuated.
 * if (balance < 0) means that R channel will be attenuated.
 * attenuation level is 0.125 dB per step.
 *
 * @param <balance>	{ range from APP_MIN_BAL ~ APP_MAX_BAL }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetBalanceTS(int32_t balance);

int32_t Audio_HwpSetBalance(int32_t  Balance, APP_BALANCE_CH_ID Channel);

void Audio_HwpPrescale(int vol, int ch_id);

/**
 * Set Digital Volume ( Playback path )
 *
 * @param <ch_id>	{ APP_CH_ID_L | APP_CH_ID_R | ... ,refer to audio_app.h }
 * @param <vol>		{ range from APP_MIN_VOL ~ APP_MAX_VOL }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetVolume(uint32_t ch_id, int32_t vol);

/**
 * Set Digital Volume ( Playback path )
 * this function is for audio library internal use only
 *
 * @param <ch_id>	{ APP_CH_ID_L | APP_CH_ID_R | ... ,refer to audio_app.h }
 * @param <vol>		{ range from APP_MIN_VOL ~ APP_MAX_VOL }
 * @param <comp_id> { APP_DVOL_ID_XXX ,refer to audio_app.h }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetVolumeCompensation(uint32_t ch_id, int32_t vol, uint32_t comp_id);

/**
 * Set Digital Volume ( Time-Shift path )
 *
 * @param <ch_id>	{ APP_CH_ID_L | APP_CH_ID_R | ... ,refer to audio_app.h }
 * @param <vol>		{ range from APP_MIN_VOL ~ APP_MAX_VOL }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetVolumeTS(uint32_t ch_id, int32_t vol);

/**
 * Mute/Unmute output ( Playback path )
 *
 * @param <para>	{ AIO_ENABLE/AIO_DISABLE }
 * @param <ch_id>	{ APP_CH_ID_L | APP_CH_ID_R | ... ,refer to audio_app.h }
 * @param <mute_id>	{ mute_by_who id , now support id 0~4 }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetMute(bool para, uint32_t ch_id, uint32_t mute_id);

/**
 * Mute/Unmute output ( Time-Shift path )
 *
 * @param <para>	{ AIO_ENABLE/AIO_DISABLE }
 * @param <ch_id>	{ APP_CH_ID_L | APP_CH_ID_R | ... ,refer to audio_app.h }
 * @param <mute_id>	{ mute_by_who id , now support id 0~4 }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetMuteTS(bool para, uint32_t ch_id, uint32_t mute_id);

/**
 * Get library/driver mute status( Playback path )
 *
 * @param <ch_id>		{ APP_CH_ID_L | APP_CH_ID_R | ... ,refer to audio_app.h }
 * @param <p_status>	{ TRUE / FALSE }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpGetMuteStatus(uint32_t ch_id, uint32_t *p_status);

/**
 * Get library/driver mute status( Time-Shift path )
 *
 * @param <ch_id>		{ APP_CH_ID_L | APP_CH_ID_R | ... ,refer to audio_app.h }
 * @param <p_status>	{ TRUE / FALSE }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpGetMuteStatusTS(uint32_t ch_id, uint32_t *p_status);

/**
 * Setup Digital Volume ( Playback path )
 *
 * @param <p_cfg_dvol>	{ pointer of DVOL control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpCfgVolume(APP_DVOL_CFG *p_cfg_dvol);

/**
 * Setup Digital Volume ( Time-Shift path )
 *
 * @param <p_cfg_dvol>	{ pointer of DVOL control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpCfgVolumeTS(APP_DVOL_CFG *p_cfg_dvol);

/**
 * Setup Digital Mute ( Playback path )
 *
 * @param <p_cfg_dvol>	{ pointer of DVOL control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpCfgMute(APP_MUTE_CFG *p_cfg_mute);

/**
 * Setup Digital Mute ( Time-Shift path )
 *
 * @param <p_cfg_dvol>	{ pointer of DVOL control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpCfgMuteTS(APP_MUTE_CFG *p_cfg_mute);

/**
 * Mute/Unmute output ( Playback path )
 * This API is for multi-thread purpose. Audio Library user should use Audio_HwpSetMute()
 * instead of this one.
 *
 * @param <para>	{ AIO_ENABLE/AIO_DISABLE }
 * @param <ch_id>	{ APP_CH_ID_L | APP_CH_ID_R | ... ,refer to audio_app.h }
 * @param <mute_id>	{ mute_by_who id )
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetMuteInternal(bool para, uint32_t ch_id, uint32_t mute_id);

/**
 * Mute/Unmute output ( Time-Shift path )
 * This API is for multi-thread purpose. Audio Library user should use Audio_HwpSetMute()
 * instead of this one.
 *
 * @param <para>	{ AIO_ENABLE/AIO_DISABLE }
 * @param <ch_id>	{ APP_CH_ID_L | APP_CH_ID_R | ... ,refer to audio_app.h }
 * @param <mute_id>	{ mute_by_who id )
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetMuteInternalTS(bool para, uint32_t ch_id, uint32_t mute_id);

/**
 * Calibrate AD DA gain
 *
 * @param <para>		{NULL }
 * @return				{ NULL }
 */
void Audio_HwpCalibrateADDA(void);

/**
 * Setup H/W Auto Volume Control
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <p_cfg_avc>	{ pointer of AVC control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetAVC(bool para, APP_AVC_CFG *p_cfg_avc);

/**
 * Setup H/W Auto Volume Control2
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <p_cfg_avc>	{ pointer of AVC2 control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetAVC2(bool para, APP_AVC2_CFG *p_cfg_avc);

/**
 * Enable DRC function
 *
 * @param <enable>		{TRUE: enable DRC 2band (lowband, highband)}
 */
int32_t Audio_HwpEnableTwoBandDRC(bool enable, APP_DRC_LPF_CFG *p_cfg_drc_lpf,
				 APP_DRC_CFG *p_cfg_drc);

/**
 * Setup H/W Distortion Control
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <p_cfg_dist>	{ pointer of Distortion control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetDistortionCtrl(bool para, APP_DIST_CTRL_CFG *p_cfg_dist);

/**
 * Setup H/W Treble values
 *
 * @param <p_val_treble>	{ pointer of a set of treble value }
 * @return					{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetTrebleValue(bool para, APP_TREBLE_VAL *p_val_treble);

/**
 * Setup H/W Treble values
 *
 * @param <p_val_treble>	{ pointer of a set of treble value }
 * @return					{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetTrebleValue_48K(bool para, APP_TREBLE_VAL *p_val_treble);

/**
 * Setup H/W Treble coefficients
 *
 * @param <para>			{ AIO_ENABLE/AIO_DISABLE }
 * @param <p_cfg_treble>	{ pointer of Treble-Band control block }
 * @return					{ AIO_OK or AIO_ERROR_CODE }
 * @note
 *    This function is mutual with Speaker Compensation.
 *
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetTrebleCoef(APP_TREBLE_CFG *p_cfg_treble);

/**
 * Setup H/W Treble coefficients
 *
 * @param <para>			{ AIO_ENABLE/AIO_DISABLE }
 * @param <p_cfg_treble>	{ pointer of Treble-Band control block }
 * @return					{ AIO_OK or AIO_ERROR_CODE }
 * @note
 *    This function is mutual with Speaker Compensation.
 *
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetTrebleCoef_48K(APP_TREBLE_48K_CFG *p_cfg_treble);

/**
 * Setup H/W Treble values
 *
 * @param <p_val_treble>	{ pointer of a set of treble value }
 * @return					{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetTreble2Value(bool para, APP_TREBLE_VAL *p_val_treble);

/**
 * Setup H/W Treble values
 *
 * @param <p_val_treble>	{ pointer of a set of treble value }
 * @return					{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetTreble2Value_48K(bool para, APP_TREBLE_VAL *p_val_treble);

/**
 * Setup H/W Treble coefficients
 *
 * @param <para>			{ AIO_ENABLE/AIO_DISABLE }
 * @param <p_cfg_treble>	{ pointer of Treble-Band control block }
 * @return					{ AIO_OK or AIO_ERROR_CODE }
 * @note
 *    This function is mutual with Speaker Compensation.
 *
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetTreble2Coef(APP_TREBLE_CFG *p_cfg_treble);

/**
 * Setup H/W Treble coefficients
 *
 * @param <para>			{ AIO_ENABLE/AIO_DISABLE }
 * @param <p_cfg_treble>	{ pointer of Treble-Band control block }
 * @return					{ AIO_OK or AIO_ERROR_CODE }
 * @note
 *    This function is mutual with Speaker Compensation.
 *
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetTreble2Coef_48K(APP_TREBLE_48K_CFG *p_cfg_treble);

/**
 * Setup H/W Bass values
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <p_val_bass>	{ pointer of a set of bass value }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetBassValue(bool para, APP_BASS_VAL *p_val_bass);

/**
 * Setup H/W Bass values
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <p_val_bass>	{ pointer of a set of bass value }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetBassValue_48K(bool para, APP_BASS_VAL *p_val_bass);

/**
 * Setup H/W Bass coefficients
 *
 * @param <p_cfg_bass>	{ pointer of Bass-Band control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @note
 *    This function is mutual with Speaker Compensation.
 *
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetBassCoef(APP_BASS_CFG *p_cfg_bass);

/**
 * Setup H/W Bass coefficients
 *
 * @param <p_cfg_bass>	{ pointer of Bass-Band control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @note
 *    This function is mutual with Speaker Compensation.
 *
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetBassCoef_48K(APP_BASS_48K_CFG *p_cfg_bass);

int32_t Audio_HwpSetEQLoudValue_Change_Mode(APP_EQ_LOUD_VALUE_CHANGE_MODE eqmode);

// ryanliao 2017/3/14 for googleTV init flow
int32_t Audio_HwpSetDVCValue_Change_Mode(APP_DVC_VALUE_CHANGE_MODE dvcmode);

/**
 * Setup H/W Equalizer values
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <p_val_eq>	{ pointer of a set of EQ value }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetEQValue(bool para, APP_EQ_VAL *p_val_eq);

/**
 * Setup H/W Equalizer values
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <p_val_eq>	{ pointer of a set of EQ value }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetEQValue_48K(uint32_t Band_enable, APP_EQ_VAL *p_val_eq);

/**
 * Setup H/W Equalizer coefficients
 *
 * @param <p_cfg_eq>	{ pointer of EQ-Band control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetEQCoef(APP_EQ_CFG *p_cfg_eq);

/**
 * Setup H/W Equalizer coefficients
 *
 * @param <p_cfg_eq>	{ pointer of EQ-Band control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetEQCoef_48K(APP_EQ_48K_CFG *p_cfg_eq);

/**
 * Setup Speaker Compensation
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetSpeakerCompensation(bool para);

/**
 * Setup H/W Spatial Effect
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <p_cfg_avc>	{ pointer of SE control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetSpatialEffect(bool para, APP_SE_CFG *p_cfg_se);

#ifdef USE_SW_SOUND_SURROUND
/**
 * Setup SRS-TrusurroundHD effect
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <type_id>		{ version or sub-type for TSHD }
 * @param <p_cfg_tsxt>	{ pointer of TSHD control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_SwpSetSRS_TrusurroundHD(bool para, APP_TSXT_CFG *pTSXT);

/**
 * Setup SRS-WOW effect
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <type_id>		{ version or sub-type for WOW }
 * @param <p_cfg_wow>	{ pointer of WOW control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_SwpSetSRS_WOW(bool para, uint32_t type_id, void *p_cfg_wow);

/**
 * Setup BBE effect
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <type_id>		{ version or sub-type for BBE }
 * @param <p_cfg_bbe>	{ pointer of BBE control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_SwpSetBBE(bool para, uint32_t type_id, void *p_cfg_bbe);

/**
 * Setup Reverb effect
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <type_id>		{ version or sub-type for RVB }
 * @param <p_cfg_rvb>	{ pointer of RVB control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_SwpSetRVB(bool para, uint32_t type_id, void *p_cfg_rvb);

/**
 * Setup Realtek Surround effect
 *
 * @param <para>			{ AIO_ENABLE/AIO_DISABLE }
 * @param <type_id>			{ version or sub-type for RTSURD }
 * @param <p_cfg_resurd>	{ pointer of RTSURD control block }
 * @return					{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_SwpSetRTSURD(bool para, uint32_t type_id, void *p_cfg_rtsurd);

/**
 * Enable/Disable Monitor
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_SwpSetMonitor(bool para);

/**
 * Query the result of Monitor
 *
 * @param <p_moni_info>	{ result of query }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_SwpGetMonitorInfo(APP_MONI_MODE mode, APP_MONI_INFO *p_moni_info);
#endif

/**
 * Get the Capability/Compatibility of HWP and SWP
 *
 * @param <id>		{ APP_ID refer to audio_app.h }
 * @param <list>	{ APP_ID refer to audio_app.h }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 *
 */
int32_t Audio_AppGetCapability(APP_ID id, uint32_t *p_list);

/**
 * Setup Speaker Compensation coefficients
 *
 * @param <p_cfg_spk>	{ pointer of Speaker Compensation control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_HwpSetSpeakerCompensationCoef(APP_SPK_CFG *p_cfg_spk);

/**
 * Init. LasVegas Audio PostProcessing
 *
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AppInit(void);

/**
 * DeInit. LasVegas Audio PostProcessing
 *
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AppDeInit(void);

/**
 * Get Audio Interface info
 *
 * @param <info>		{ which info }
 * @return				{  }
 * @ingroup lib_audio
 */
uint32_t Audio_AppGetInfo(APP_GET_INFO info);

/**
 * Enable / disable print debug message
 *
 *
 * @ingroup lib_audio
 */
void Audio_AppEnablePrintf(uint32_t isEnable);

/**
 * Setup max output level (DAC0 limiter)
 *

 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <maxLevelThresdhold>	{ threshold of output level }
 * @ingroup lib_audio
 *  W= V*V / R

 *  ex speaker max W =  8W , R = 8, V of Amp ==> 8
 *   amp is 21 db (according to pcb ) ,  21= 20* log(11.22 ) ==> 11.22 
 *   V of IC's output   = 8/11.22 = 0.71 V
 *   IC  define  0x7FFFFFFF means 1 V , 0.71V * 0x7FFFFFFF  (0x80000000)  = 0x5AE1 47AE
 *   threshold is 0.71V(0x5AE1 47AE) >> 24   = 0x5A , so thredhold is set 0x5A or (0x5A -1)
 */
void  Audio_HwpSetLimitOuptut(bool para, uint32_t maxLevelThresdhold);

/**
 * disable all hpp effect for factory
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <maxLevelThresdhold>	{ threshold of output level }
 * @ingroup lib_audio
 */
void  Audio_FactoryDisableHwPp(void);

/**
 * disable all spp effect for factory
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <maxLevelThresdhold>	{ threshold of output level }
 * @ingroup lib_audio
 */
void  Audio_FactoryEnableHwPp(void);

/**
 * enable all spp effect for factory
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <maxLevelThresdhold>	{ threshold of output level }
 * @ingroup lib_audio
 */
void  Audio_FactoryDisableSwPp(void);

/**
 * select avc parameter for factory
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <maxLevelThresdhold>	{ threshold of output level }
 * @ingroup lib_audio
 */
void  Audio_FactoryAVC(bool enable, uint32_t value);

/**
 * Mute/Unmute Spdif output
 *
 * @param <para>	{ AIO_ENABLE/AIO_DISABLE }
 * @param <mute_id>	{ mute_by_who id )
 * @ingroup lib_audio
 */
void Audio_HwpSetSpdifOut_Mute(bool para, uint32_t mute_id);

int32_t Audio_HwpSetEQCoef_9Band(APP_9BAND_EQ_CFG *p_cfg_eq_9band);
int32_t Audio_HwpSetEQValue_9Band(bool para, APP_9BAND_EQ_VAL *p_val_eq_9band);
void  Audio_EnableCompensateAudioOutput(uint32_t isEnable, APP_AUDIO_PATH path);

#ifdef USE_SW_SOUND_SURROUND
int32_t Audio_SwpSetBassBack(bool para, APP_BASSBACK_TV_CFG *pBass);
int32_t Audio_SwpSetBassBack_PCBU(bool para, APP_BASSBACK_PCBU_CFG *pBass);
int32_t Audio_SwpSetBassBackGain(uint32_t bassGain);
int32_t Audio_SwpSetBassBack_PCBU(bool para, APP_BASSBACK_PCBU_CFG *pBass);
#endif

unsigned int Audio_HwpReadRegister(unsigned int addr);
void Audio_HwpWriteRegister(unsigned int addr, unsigned int value);
int32_t Audio_SwpSetASFEnable(int on_off);
int32_t Audio_SwpSetASFVolume(unsigned int volume);
int32_t Audio_SwpSetASFBalance(int balance);
int32_t Audio_AppSemInit(void);
void  Audio_AppSemDeInit(void);
void Audio_AtvSetDuring_ChageStatusFlag(uint8_t ucFlag);
uint8_t Audio_AtvGetDuring_ChageStatusFlag(void);
int32_t Audio_GetMuteID_PB(void);
int32_t Audio_GetMuteID_TS(void);
void CleanEQLoudnessOverflow(void);

int32_t Audio_HwpSetEQ_Smooth_H0(APP_EQ_ALL_BAND band_id, APP_EQ_COEF eq_coef);
int32_t Audio_HwpSetLoud_Smooth_H0(APP_LOUD_ALL_BAND band_id, APP_EQ_COEF loud_coef);

int32_t Audio_HwpSetEQParameter(APP_EQ_ALL_BAND band_id, APP_EQ_COEF eq_coef);
int32_t Audio_HwpSetLoudParameter(APP_LOUD_ALL_BAND band_id, APP_EQ_COEF loud_coef);
int32_t Audio_HwpWriteEQControlEnable(APP_EQ_ALL_BAND band_id, bool eq_enable);
int32_t Audio_HwpWriteLoudControlEnable(APP_LOUD_ALL_BAND band_id, bool loud_enable);
int32_t Audio_HwpReadEQControlEnable(uint32_t *p_eq_ctrl_reg);
int32_t Audio_HwpReadLoudControlEnable(uint32_t *p_loud_ctrl_reg);
int32_t Audio_HwpGetMaxEQBandNum(int32_t *eq_band);
		
#endif

