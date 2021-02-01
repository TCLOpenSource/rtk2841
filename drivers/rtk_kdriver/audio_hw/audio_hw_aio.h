#ifndef AUDIO_HW_AIO_H
#define AUDIO_HW_AIO_H

#include <linux/types.h>

#define AIO_OK				(0)
#define AIO_ERROR			(0x80000000)
#define AIO_ERR_CODE_AIO		(0x00010000)
#define AIO_ERR_CODE_APP		(0x00020000)
#define AIO_ERR_CODE_ATV		(0x00030000)

#define AIO_ERR_AIO_INVALID_OPEN	((AIO_ERR_CODE_AIO) | 0x0101)
#define AIO_ERR_AIO_INVALID_CLOSE	((AIO_ERR_CODE_AIO) | 0x0102)
#define AIO_ERR_AIO_AVC_THD		((AIO_ERR_CODE_AIO) | 0x0103)
#define AIO_ERR_AIO_AVC_ATK_TIME	((AIO_ERR_CODE_AIO) | 0x0104)
#define AIO_ERR_AIO_AVC_REL_TIME	((AIO_ERR_CODE_AIO) | 0x0105)
#define AIO_ERR_AIO_NR_THD		((AIO_ERR_CODE_AIO) | 0x0106)
#define AIO_ERR_AIO_NR_CHK_TIME		((AIO_ERR_CODE_AIO) | 0x0107)
#define AIO_ERR_AIO_NR_ACT_TIME		((AIO_ERR_CODE_AIO) | 0x0108)

#define AIO_ENABLE			(1)
#define AIO_DISABLE			(0)

#define AIO_BBADC_MAX_GAIN		(0x37)
#define AIO_BBADC_MIN_GAIN		(0x00)
#define AIO_BBADC_0DB_GAIN		(0x27)

#define AIO_PEAK_DETECT_PERIOD_US	(20*1000)	// 20ms
#define AIO_PEAK_DETECT_PERIOD_MS	(20)		// 20ms
#define AIO_PEAK_DETECT_TIME_20MS	(20*1000/AIO_PEAK_DETECT_PERIOD_US)
#define AIO_PEAK_DETECT_TIME_100MS	(100*1000/AIO_PEAK_DETECT_PERIOD_US)
#define AIO_PEAK_DETECT_TIME_200MS	(AIO_PEAK_DETECT_TIME_100MS*2)
#define AIO_PEAK_DETECT_TIME_500MS	(AIO_PEAK_DETECT_TIME_100MS*5)
#define AIO_PEAK_DETECT_TIME_1SEC	(1000*1000/AIO_PEAK_DETECT_PERIOD_US)
#define AIO_PEAK_DETECT_TIME_2SEC	(AIO_PEAK_DETECT_TIME_1SEC*2)
#define AIO_PEAK_DETECT_TIME_5SEC	(AIO_PEAK_DETECT_TIME_1SEC*5)
#define AIO_PEAK_DETECT_TIME_1MIN	(AIO_PEAK_DETECT_TIME_1SEC*60)
#define AIO_PEAK_DETECT_MUTE_THD	AIO_PEAK_DETECT_TIME_1SEC

#define AIO_PEAK_MAG_TAB_SIZE		121

#define AIO_OPT_AVC_THD_MAX		0
#define AIO_OPT_AVC_THD_MIN		(AIO_PEAK_MAG_TAB_SIZE - 1)
#define AIO_OPT_AVC_THD_MHELFDB		1
#define AIO_OPT_AVC_THD_M1DB		2
#define AIO_OPT_AVC_THD_M3DB		(AIO_OPT_AVC_THD_M1DB*3)
#define AIO_OPT_AVC_THD_M6DB		(AIO_OPT_AVC_THD_M1DB*6)
#define AIO_OPT_AVC_THD_M9DB		(AIO_OPT_AVC_THD_M1DB*9)
#define AIO_OPT_AVC_THD_M12DB		(AIO_OPT_AVC_THD_M1DB*12)

#define AIO_OPT_AVC_MAX_ATK_MS		30000		// 30 second
#define AIO_OPT_AVC_MIN_ATK_MS		20			// original setting is 60, linmc@20120629,sync tpv sw avc setting
#define AIO_OPT_AVC_MAX_REL_MS		30000		// 30 second
#define AIO_OPT_AVC_MIN_REL_MS		60

#define AIO_IPT_NR_MAX_CHK_MS		30000		// 30 second
#define AIO_IPT_NR_MIN_CHK_MS		60
#define AIO_IPT_NR_MAX_ACT_MS		30000		// 30 second
#define AIO_IPT_NR_MIN_ACT_MS		60

#define AIO_HDMI_STATE_PCM_MASK		(1<<0)
#define AIO_HDMI_STATE_PCM_LPCM		(0<<0)
#define AIO_HDMI_STATE_PCM_NONPCM	(1<<0)
#define AIO_HDMI_STATE_HBR_MASK		(1<<1)
#define AIO_HDMI_STATE_HBR_OFF		(0<<1)
#define AIO_HDMI_STATE_HBR_ON		(1<<1)
#define AIO_HDMI_STATE_OPT_MASK		(1<<2)
#define AIO_HDMI_STATE_OPT_OFF		(0<<2)
#define AIO_HDMI_STATE_OPT_ON		(1<<2)
#define AIO_HDMI_STATE_ERR_MASK		(1<<3)
#define AIO_HDMI_STATE_ERR_CLEAR	(0<<3)
#define AIO_HDMI_STATE_ERR_SET		(1<<3)

// for K3L get IC version API
#define STB_SC_VerID_reg		0xb8060000
#define VERSION_A_REG_CODE		0x64560000
#define VERSION_B_REG_CODE		0x64560001

// System-related -------------------//
typedef enum {
	AIO_PATH_ID_PB,
	AIO_PATH_ID_TS
} AIO_PATH_ID;

typedef enum {
	AIO_FIFO_ID_CH12,
	AIO_FIFO_ID_CH34,
	AIO_FIFO_ID_CH45,
	AIO_FIFO_ID_CH78,
} AIO_FIFO_ID;

typedef enum {
	AIO_FIFO_SEL_ATV	= 0x00,	// real input, mapping to register bit-setting
	AIO_FIFO_SEL_BBADC	= 0x01,	// real input, mapping to register bit-setting
	AIO_FIFO_SEL_SPDIF	= 0x02,	// real input, mapping to register bit-setting
	AIO_FIFO_SEL_BBADC2	= 0x03,	// Sreal input, mapping to register bit-setting
	AIO_FIFO_SEL_I2S_CH12	= 0x04,	// real input, mapping to register bit-setting
	AIO_FIFO_SEL_I2S_CH34	= 0x05,	// real input, mapping to register bit-setting
	AIO_FIFO_SEL_I2S_CH56	= 0x06,	// real input, mapping to register bit-setting
	AIO_FIFO_SEL_I2S_CH78	= 0x07,	// real input, mapping to register bit-setting
} AIO_FIFO_SEL;

typedef enum {
	// bit-mapping setting
	AIO_CH_ID_L	= (0x1<<0),
	AIO_CH_ID_R	= (0x1<<1),
	AIO_CH_ID_ALL	= 0x03
} AIO_CH_ID;

typedef enum {
	AIO_PATH_SRC_ATV		= 0x00,	// real input, mapping to register bit-setting
	AIO_PATH_SRC_BBADC		= 0x01,	// real input, mapping to register bit-setting
	AIO_PATH_SRC_SPDIF		= 0x02,	// real input, mapping to register bit-setting
	AIO_PATH_SRC_BIT_3		= 0x03,	// SRC_PCM is NOT available in AT
	AIO_PATH_SRC_I2S_CH12		= 0x04,	// real input, mapping to register bit-setting
	AIO_PATH_SRC_I2S_CH34		= 0x05,	// real input, mapping to register bit-setting
	AIO_PATH_SRC_I2S_CH56		= 0x06,	// real input, mapping to register bit-setting
	AIO_PATH_SRC_I2S_CH78		= 0x07,	// real input, mapping to register bit-setting
	AIO_PATH_SRC_ATV_NICAM		= 0x08,	// shared input(ATV), affect clk setting
	AIO_PATH_SRC_ATV_HDEV		= 0x09,	// shared input(ATV), affect clk setting
	AIO_PATH_SRC_DTV		= 0x10,	// pseudo input, affect clk setting
	AIO_PATH_SRC_FILE		= 0x20,	// pseudo input, affect clk setting
	AIO_PATH_SRC_BBADC_KARAOKE	= 0x40,	// pseudo input, affect clk setting
	AIO_PATH_SRC_UNKNOWN		= 0xFF
} AIO_PATH_SRC;

typedef enum {
	AIO_DATA_IS_PCM,
	AIO_DATA_IS_NONPCM
} AIO_DATA_TYPE;

// Update BB Power
typedef enum {
	// identical to the order in 'Audio_AioSetAnalogPower' register's field
	// bit0~2 reserve
	AIO_POW_LO		= 1<<0,		// LineOut
	AIO_POW_AIO2		= 1<<1,		// AIO2
	AIO_POW_AIO1		= 1<<2,		// AIO1
	AIO_POW_HPO		= 1<<3,		// HPO
	AIO_POW_DF2SE_DAC0	= 1<<4,		// DF2SE DAC0
	AIO_POW_DF2SE_DAC1	= 1<<5,		// DF2SE DAC1
	AIO_POW_VREF		= 1<<6,		// VREF
	AIO_POW_MBIAS		= 1<<7,		// MBIAS
	AIO_POW_BBDAC0		= 1<<8,		// BB DAC0
	AIO_POW_BBDAC1		= 1<<9,		// BB DAC1
	AIO_POW_BBADC		= 1<<10,	// BB ADC
	AIO_POW_ADCFE		= 1<<11,	// ADCFE
	AIO_POW_BBADC2		= 1<<12,	// BB ADC2
	AIO_POW_ADCFE2		= 1<<13,	// ADCFE2
} AIO_ANA_POWER;

typedef struct {
	AIO_PATH_ID id;
	AIO_PATH_SRC src[4];
} AIO_PATH_CFG;

typedef enum {
	AIO_PEAK_SRC_ATV			= 0x0,
	AIO_PEAK_SRC_BBADC			= 0x1,
	AIO_PEAK_SRC_SPDIF			= 0x2,
	AIO_PEAK_SRC_I2S			= 0x4,
	//Frank 20140718 Add for Mac3
	AIO_PEAK_SRC_BEFORE_AVC2		= 0x5,
	AIO_PEAK_SRC_AFTER_AVC2			= 0x6,
	AIO_PEAK_SRC_SUBWOOFER_BEFORE_DVC	= 0x7,
	AIO_PEAK_SRC_SUBWOOFER_AFTER_DVC	= 0x8,
	//others hw_ts ch0/1
} AIO_PEAK_SRC;

// BBADC-related --------------------//
typedef enum {
	// identical to the order in (AUDIO_IO_ANALOG_FRONTEND_MUTE_VADDR) register's field
	// bit-mapping setting
	AIO_BBADC_MUTE_ALL = 0x00FF,
	AIO_BBADC_AIN4     = (0x1<<0),
	AIO_BBADC_AIN3     = (0x1<<1),
	AIO_BBADC_AIN2     = (0x1<<2),
	AIO_BBADC_AIN1     = (0x1<<3),
	AIO_BBADC_AIO      = (0x1<<4),
	AIO_BBADC_UNKNOWN  = (0x1<<5 | 0x1<<6 | 0x1<<7 | 0x1<<8)
} AIO_BBADC_SRC;

typedef enum {
	// identical to the order in (AUDIO_IO_ANALOG_MIXER_MUTE_VADDR) register's field
	// bit-mapping setting
	AIO_WIREIN_MUTE_ALL = 0x03,
	AIO_WIREIN_AIN1     = 1<<0,
	AIO_WIREIN_AIN2     = 1<<1,
	AIO_WIREIN_BBADC    = 1<<2
} AIO_WIREIN_SRC;

typedef enum {
	AIO_MONOIN_IN      = 0x0,
	AIO_MONOIN_OUT_T   = 0x1,
	AIO_MONOIN_STEREO  = 0x2,
//	AIO_MONOIN_UNKNOWN = 0x3
} AIO_MONOIN_SRC;

// BIG_ENDIAN
typedef struct {
	// identical to the order in (AUDIO_IO_ADC_VOLUME_GAIN_CONTROL_VADDR) register's field
	unsigned smute_left_avol_1_en:1;
	unsigned res1:1;
	unsigned avol_1_in_left_gain:6;
	unsigned smute_right_avol_1_en:1;
	unsigned res2:1;
	unsigned avol_1_in_right_gain:6;
	unsigned soft_volume_ctrl_avol:4;
	unsigned res3:12;
} AIO_BBADC_CFG;

// I2S-related ----------------------//
typedef enum {
	// identical to the order in register's field
	AIO_I2SI_IN       = 0x0,
	AIO_I2SI_HDMI     = 0x1,
	AIO_I2SI_LOOPBACK = 0x2,
	AIO_I2SI_DISABLE  = 0x3
} AIO_I2SI_SRC;

typedef enum {
	// identical to the order in register's field
	AIO_I2SI_SYNC_NORMAL  = 0x0,
	AIO_I2SI_SYNC_LEFT    = 0x1,
	AIO_I2SI_SYNC_RGHT    = 0x2,
//	AIO_I2SI_SYNC_NORMAL2 = 0x3
} AIO_I2SI_SYNC;

typedef enum {
	// identical to the order in register's field
	AIO_I2SI_SLAVE  = 0x0,
	AIO_I2SI_MASTER = 0x1
} AIO_I2SI_MODE;

typedef enum {
	AIO_I2SI_ID_PRI,
	AIO_I2SI_ID_SEC,
	AIO_I2SI_PLL_DVR
} AIO_I2SI_ID;

typedef struct {
	unsigned resvd:26;
	unsigned src_sel:2;		// refer to the definition of AIO_I2SI_SRC
	unsigned sync_type:2;		// refer to the definition of AIO_I2SI_SYNC
	unsigned mode_sel:1;		// refer to the definition of AIO_I2SI_MODE
	unsigned update_src_only:1;	// update src_sel only and keep others in default value.
} AIO_I2SI_CFG;

typedef enum {
	// identical to the order in register's field
	AIO_I2SO_MCLK_128FS   = 0x0,
	AIO_I2SO_MCLK_256FS   = 0x1,
	AIO_I2SO_MCLK_512FS   = 0x2,
	AIO_I2SO_MCLK_DISABLE = 0x3
} AIO_I2SO_MCLK;

typedef enum {
	// identical to the order in register's field
	AIO_I2SO_FIFO      = 0x0,
	AIO_I2SO_IN_SLAVE  = 0x1,
	AIO_I2SO_HDMI      = 0x2,
	AIO_I2SO_IN_MASTER = 0x3,
	AIO_I2SO_DISABLE   = 0x4
} AIO_I2SO_SRC;

typedef struct {
	AIO_I2SO_SRC src_sel;
	AIO_I2SO_MCLK mclk_sel;
	AIO_PATH_ID source_sel;
	int32_t isFixVolume;
	int32_t update_src_only;
} AIO_I2SO_CFG;

// SPDIF-related --------------------//
typedef enum {
	// identical to the order in register's field
	AIO_SPDIFI_IN       = 0x0,
	AIO_SPDIFI_HDMI     = 0x1,
	AIO_SPDIFI_LOOPBACK = 0x2,
	AIO_SPDIFI_DISABLE  = 0x3
} AIO_SPDIFI_SRC;

typedef enum {
	// identical to the order in register's field
	AIO_SPDIFI_REQ_NO  = 0x0,
	AIO_SPDIFI_REQ_YES = 0x1
} AIO_SPDIFI_REQ_TYPE;

typedef struct {
	unsigned resvd:28;
	unsigned src_sel:2;		// refer to the definition of AIO_SPDIFI_SRC
	unsigned req_after_lock:1;	// [0,1] = [No,Yes]
	unsigned update_src_only:1;	// keep default look&debounce parameter and update src_sel only.
} AIO_SPDIFI_CFG;

typedef enum {
	// identical to the order in (AUDIO_IO_SPDIF_OUT_ADDR) register's field
	AIO_SPDIFO_FIFO,
	AIO_SPDIFO_IN,
	AIO_SPDIFO_HDMI,
	AIO_SPDIFO_DISABLE
} AIO_SPDIFO_SRC;

typedef enum{ //for pcm source select
	AIO_SPDIFO_FIFO_SEL_PB,
	AIO_SPDIFO_FIFO_SEL_TS
} AIO_SPDIFO_FIFO_SEL;

typedef struct {
	AIO_SPDIFO_SRC	src_sel;
	AIO_PATH_ID		source_sel;
	int32_t			isFixVolume;
} AIO_SPDIFO_CFG;

// PCM-related ----------------------//
typedef enum {
	// identical to the order in register's field
	AIO_PCM_8BITS  = 0x0,
	AIO_PCM_12BITS = 0x1,
	AIO_PCM_16BITS = 0x2,
	AIO_PCM_20BITS = 0x3,
	AIO_PCM_24BITS = 0x4,
	AIO_PCM_28BITS = 0x5,
	AIO_PCM_32BITS = 0x6
} AIO_PCM_BITS;

typedef enum {
	// identical to the order in register's field
	AIO_PCM_SYNC_TYPE_A = 0x0,
	AIO_PCM_SYNC_TYPE_B = 0x1
} AIO_PCM_SYNC;

typedef enum {
	// identical to the order in register's field
	AIO_PCM_SCLK_NEG = 0x0,
	AIO_PCM_SCLK_POS = 0x1
} AIO_PCM_SCLK;

typedef enum {
	// identical to the order in register's field
	AIO_PCMI_MODE_SLAVE  = 0x0,
	AIO_PCMI_MODE_MASTER = 0x1
} AIO_PCMI_MODE;

typedef enum {
	// identical to the order in register's field
	AIO_PCMI_MONO   = 0x0,
	AIO_PCMI_STEREO = 0x1
} AIO_PCMI_SOUND;

typedef enum {
	// identical to the order in register's field
	AIO_PCMI_EXT     = 0x0,
	AIO_PCMI_INT     = 0x1,
	AIO_PCMI_DISABLE = 0x2
	//AIO_PCMI_DISABLE2 = 0x3
} AIO_PCMI_SRC;

typedef struct {
	unsigned resvd:22;
	unsigned update_src_only:1;
	unsigned src_sel:2;
	unsigned pcm_width:3;
	unsigned mode_sel:1;
	unsigned sync_mode:1;
	unsigned sclk_polarity:1;
	unsigned sound_mode:1;
} AIO_PCMI_CFG;

typedef enum {
	// identical to the order in register's field
	AIO_PCMO_MCLK_128FS,
	AIO_PCMO_MCLK_256FS,
	AIO_PCMO_MCLK_512FS,
	AIO_PCMO_MCLK_DISABLE
} AIO_PCMO_MCLK;

typedef enum {
	// identical to the order in register's field
	AIO_PCMO_FIFO      = 0x0,
	AIO_PCMO_IN_SLAVE  = 0x1,
	AIO_PCMO_IN_MSATER = 0x2,
	AIO_PCMO_DISABLE   = 0x3
} AIO_PCMO_SRC;

typedef enum {
	// identical to the order in (AUDIO_SPDIF_OUT_VADDR) register's field
	AIO_SPDIF_PCM_PB_BF_AVC1,
	AIO_SPDIF_PCM_PB_BF_AVC2,
	AIO_SPDIF_PCM_PB_AF_AVC2,
	AIO_SPDIF_PCM_TS_AF_DVC,
	AIO_SPDIF_PCM_PB_NONPCM,
	AIO_SPDIF_PCM_TS_NONPCM
} AIO_SPDIF_PCM_SRC;

typedef enum {
	// identical to the order in (AUDIO_I2S_OUT_VADDR) register's field
	AIO_I2S_PCM_PB_BF_AVC1,
	AIO_I2S_PCM_PB_BF_AVC2,
	AIO_I2S_PCM_PB_AF_AVC2,
	AIO_I2S_PCM_TS_AF_DVC
} AIO_I2S_PCM_SRC;

typedef enum {
	// identical to the order in (AUDIO_DAC0_1_SRC_SEL_VADDR) register's field
	AIO_DAC0_PCM_PB_BF_AVC1,
	AIO_DAC0_PCM_PB_BF_AVC2,
	AIO_DAC0_PCM_PB_AF_AVC1,
	AIO_DAC0_PCM_PB_AF_AVC2,
	AIO_DAC0_PCM_PB_CH23_AF_AVC2,
	AIO_DAC0_PCM_PB_CH45_AF_AVC2,
	AIO_DAC0_PCM_PB_CH67_AF_AVC2,
	AIO_DAC0_PCM_TS_BF_DVC,
	AIO_DAC0_PCM_TS_AF_DVC,
	AIO_DAC0_CH01_OF_AO_HDMI_8CH_PCM,
	AIO_DAC0_CH23_OF_AO_HDMI_8CH_PCM,
	AIO_DAC0_CH45_OF_AO_HDMI_8CH_PCM,
	AIO_DAC0_CH67_OF_AO_HDMI_8CH_PCM
}AIO_DAC0_PCM_SRC;

typedef enum {
	// identical to the order in (AUDIO_DAC0_1_SRC_SEL_VADDR) register's field
	AIO_DAC1_PCM_PB_BF_AVC1,
	AIO_DAC1_PCM_PB_BF_AVC2,
	AIO_DAC1_PCM_PB_AF_AVC1,
	AIO_DAC1_PCM_PB_AF_AVC2,
	AIO_DAC1_PCM_PB_CH23_AF_AVC2,
	AIO_DAC1_PCM_PB_CH45_AF_AVC2,
	AIO_DAC1_PCM_PB_CH67_AF_AVC2,
	AIO_DAC1_PCM_TS_BF_DVC,
	AIO_DAC1_PCM_TS_AF_DVC,
	AIO_DAC1_CH01_OF_AO_HDMI_8CH_PCM,
	AIO_DAC1_CH23_OF_AO_HDMI_8CH_PCM,
	AIO_DAC1_CH45_OF_AO_HDMI_8CH_PCM,
	AIO_DAC1_CH67_OF_AO_HDMI_8CH_PCM
} AIO_DAC1_PCM_SRC;

typedef struct {
	unsigned resvd:22;
	unsigned update_src_only:1;
	unsigned src_sel:2;
	unsigned pcm_width:3;
	unsigned mode_sel:1;
	unsigned sclk_polarity:1;
	unsigned mclk_sel:2;
} AIO_PCMO_CFG;

// DAC/HP-related -------------------//
typedef enum {
	// HPout source select--
	// bit-mapping setting, total bit18~bit24
	// bit18: DAC0 / bit19: DAC1 / bit20: ADCFE1 /bit21: ADCFE2
	AIO_HP_MUTE_ALL   = 0x3f,
	AIO_HP_PB_DAC0    = 1<<0,
	AIO_HP_PB_DAC1    = 1<<1,
	AIO_HP_ADCFE1     = 1<<2,
	AIO_HP_ADCFE2     = 1<<3,
	AIO_HP_rsd        = 7<<4,
} AIO_HP_SRC;

typedef enum {
	// AIO1 source select--
	// bit-mapping setting, total bit0~bit5
	// bit0: DAC0 / bit1: DAC1 / bit2: ADCFE1 /bit3: ADCFE2
	AIO_AIO1_MUTE_ALL   = 0x3f,
	AIO_AIO1_PB_DAC0    = 1<<0,
	AIO_AIO1_PB_DAC1    = 1<<1,
	AIO_AIO1_ADCFE1     = 1<<2,
	AIO_AIO1_ADCFE2     = 1<<3,
	AIO_AIO1_rsd        = 3<<4,
} AIO_AIO1_SRC;

typedef enum {
	// AIO2 source select--
	// bit-mapping setting, total bit0~bit5
	// bit6: DAC0 / bit7: DAC1 / bit8: ADCFE1 /bit9: ADCFE2
	AIO_AIO2_MUTE_ALL   = 0x3f<<6,
	AIO_AIO2_PB_DAC0    = 1<<6,
	AIO_AIO2_PB_DAC1    = 1<<7,
	AIO_AIO2_ADCFE1     = 1<<8,
	AIO_AIO2_ADCFE2     = 1<<9,
	AIO_AIO2_rsd        = 3<<10,
} AIO_AIO2_SRC;

typedef enum {
	// LO(AIO) source select--
	// bit-mapping setting, total bit12~bit17
	// bit12: DAC0 / bit13: DAC1 / bit14: ADCFE1 /bit15: ADCFE2
	AIO_LO_MUTE_ALL   = 0x3f<<12,
	AIO_LO_PB_DAC0    = 1<<12,
	AIO_LO_PB_DAC1    = 1<<13,
	AIO_LO_ADCFE1     = 1<<14,
	AIO_LO_ADCFE2     = 1<<15,
	AIO_LO_rsd        = 3<<16,
} AIO_LO_SRC;

typedef enum {
	// identical to the order in (AUDIO_ANALOG_IN_OUT_SEL_VADDR) register's field
	// bit-mapping setting
	AIO_WIREOUT_MUTE_ALL = 0x07,
	AIO_WIREOUT_PB_DAC   = 1<<0,
	AIO_WIREOUT_WIREIN   = 1<<1,
	AIO_WIREOUT_TS_DAC   = 1<<2
} AIO_WIREOUT_SRC;

typedef enum {
	// identical to the order in (AUDIO_IO_ANALOG_AIO_MASTER_HPOUT_LINEOUT_VADDR) register's field
	// bit-mapping setting
	AIO_DACMIX_MUTE_ALL = 0x02,
	AIO_DACMIX_AMIX_1   = 1<<1,
} AIO_DACMIX_SRC;

typedef enum {
	// identical to the order in (AUDIO_ANALOG_OUT_COPY_SWAP_VADDR) register's field
	// Clayton 2013/5/22
	// change setting (this ic is different with previous ic setting)
	AIO_OPT_CHANNEL_R_TO_L  = 0x0,
	AIO_OPT_CHANNEL_STEREO  = 0x1,
	AIO_OPT_CHANNEL_LR_SWAP = 0x2,
	AIO_OPT_CHANNEL_L_TO_R  = 0x3
} AIO_OPT_CHANNEL;

typedef enum {
	// Clayton 2014/1/5
	DIO_OPT_CHANNEL_STEREO  = 0x0,	// ch0=L ; ch1=R
	DIO_OPT_CHANNEL_L_TO_R  = 0x1,	// ch0=L ; ch1=L
	DIO_OPT_CHANNEL_R_TO_L 	= 0x2,	// ch0=R ; ch1=R
	DIO_OPT_CHANNEL_LR_SWAP = 0x3	// ch0=R ; ch1=L
} DIO_OPT_CHANNEL;

#define DIO_I2S_CH_01	0x1
#define DIO_I2S_CH_23	0x2
#define DIO_I2S_CH_45	0x4
#define DIO_I2S_CH_67	0x8

typedef struct {
	uint32_t isFixVol;		// 0: headphone is vol-path, 1: headphone is fix-vol-path
} AIO_HEADPHONE_CFG;

// S/W-related ----------------------//
typedef struct {
	AIO_PEAK_SRC detectsrc;		// onley A, B need , Version C do not need to set source
	uint32_t restflag;		// 1 to reset
	uint32_t threshold;
	uint32_t chk_ms;		// ms per step, time base is 20 ms and min. value is 60 ms
	uint32_t act_ms;		// must be multiple of check_ms
	uint32_t iptsrc_unmute;		// bit-field of AIO_PATH_SRC, bit value = 1 means to unmute when just change source to this source
	int32_t nr_attenuation;
	uint32_t nr_damp_range;
} AIO_NR_CFG;

typedef struct {
	AIO_PEAK_SRC detectsrc;		// version C have effect
	uint32_t restflag;		// 1 to reset
	uint32_t threshold;
	uint32_t atk_ms;		// ms per step, time base is 20 ms and min. value is 60 ms
	uint32_t rel_ms;		// must be multiple of atk_ms
} AIO_AVC_CFG;

typedef enum {
	AIO_AMPMUTE_APP		= 0x0,
	AIO_AMPMUTE_ASE		= 0x1,
	AIO_AMPMUTE_HEADPHONE	= 0x2, // Mute:with hp, Un-mute:without hp
	AIO_AMPMUTE_POWERSAVING	= 0x3, // Mute:power-saving mode, Un-mute:power-on mode
	AIO_AMPMUTE_UNKNOWN	= 0x4,
} AIO_AMPMUTE_ID;

typedef enum {
	AIO_ADCVOL1_3_0DB_At	= 0x25, //-3db
	AIO_ADCVOL1_1_5DB_At	= 0x26, // -1.5db
	AIO_ADCVOL1_0_0DB	= 0x27, // 0db
	AIO_ADCVOL1_1_5DB	= 0x28,// 1.5db
	AIO_ADCVOL1_3_0DB	= 0x29,// 3.0 db
} AIO_ADCVOL1_ID;

typedef enum {
	VERSION_A = 0,
	VERSION_B,
	VERSION_C,
	VERSION_D,
	VERSION_E,
	VERSION_F
} AUDIO_ICVERSION;

//Clayton 2013/10/18
// ADC ASRC Gain setting
typedef enum {
	AIO_AD_ASRC_GAIN_HW_Default = 0x17, //HW default, HW spec list 0dB (Real -4.5dB)
	AIO_AD_ASRC_GAIN_HW_Compensate = 0x1D // HW spec list +4.5dB (Real 0dB), Prefer to compensate the default difference
} AIO_AD_ASRC_GAIN;

//Clayton 2014/5/28
// ADC ASRC "Compensate" Gain setting
typedef enum {
	AIO_AD_COMP_GAIN_0DB = 0, 		//HW default, 0dB
	AIO_AD_COMP_GAIN_1DB,			// +1dB
	AIO_AD_COMP_GAIN_2DB,			// +2dB
	AIO_AD_COMP_GAIN_MINUS_0P25DB,	// -0.25dB
	AIO_AD_COMP_GAIN_MINUS_0P5DB,	// -0.5dB
	AIO_AD_COMP_GAIN_MINUS_0P75DB,	// -0.75dB
	AIO_AD_COMP_GAIN_MINUS_1DB,		// -1dB
	AIO_AD_COMP_GAIN_MINUS_1P5DB	// -1.5dB
} AIO_AD_COMP_GAIN;

//Clayton 2013/11/7
// Capless Line driver output swing select
typedef enum {
	AIO_LINEDRIVER_1VRMS		= 0x0,	//Gsel = 0dB
	AIO_LINEDRIVER_2VRMS		= 0x1,	//Gsel = 6dB @ DAC1 to CLLO ; Suggested to use this one for 2Vrms
	AIO_LINEDRIVER_2VRMS_DAC0	= 0x2	//Gsel = 6dB @ DAC0 to CLLO ; Special use
} AIO_LINEDRIVER_OUTPUT;

typedef enum {
	AIO_DAC_GAIN_DEFAULT	= 0x57,	//HW Default setting
	AIO_DAC_GAIN_CLLO_2Vrms	= 0x56	//slightly shrink gain (-0.75dB) due to performance
} AIO_DAC_GAIN;

/**
 * @param <para>	{ AIO_ENABLE/AIO_DISABLE }
 * @param <ch_id>	{ AIO_CH_ID_L/AIO_CH_ID_R/AIO_CH_ID_ALL )
 */
typedef void (*MUTE_AMP)(bool para, uint32_t ch_id);

/**
 * @param <para>	{ AIO_ENABLE/AIO_DISABLE }
 * @param <mute_id>	{ RT_AUDIO_BLOCK_RC........ }
 */
typedef void (*MUTE_SPDIF_OUT)(bool para, uint32_t mute_id);

/**
 * @param <para>	{ AIO_ENABLE/AIO_DISABLE }
 */
typedef int32_t (*MUTE_AV_OUT)(bool para);

/**
 * Read AIO register 
 *  
 * @param <addr>	{ register address } 
 * @return		{ register value } 
 * @ingroup lib_audio
 */
unsigned int AIO_ReadRegister(unsigned int addr);

/**
 * Write AIO register 
 *  
 * @param <addr>	{ register address } 
 * @param <value>	{ data value } 
 * @return		{ } 
 * @ingroup lib_audio
 */
void AIO_WriteRegister(unsigned int addr, unsigned int value);

/**
 * Get audio input source info. (backup by library)
 *
 * @param <p_path_cfg>	{ refer to struct of AIO_PATH_CFG }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioGetPathSrc(AIO_PATH_CFG *p_path_cfg);

/**
 * Select BBADC input source.
 * This function is usually used with YPbPr/VGA/CVBS/S-Video sources
 *
 * @param <src>	{ AIO_BBADC_AIO1 | BBADC_AIO2 | ..., refer to audio_aio.h }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetIptSrc_BBADC(AIO_BBADC_SRC src);

/**
 * Select I2S_IN_Primary input source.
 * This function is usually used with HDMI source
 *
 * @param <src>	{ AIO_I2SI_IN / AIO_I2SI_HDMI / AIO_I2S_LOOPBCK / AIO_I2S_DISABLE }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetIptSrc_I2SPri(AIO_I2SI_SRC src);

/**
 * Get I2S_IN_Primary source info.
 *
 * @param <p_i2s_src>	{ AIO_I2SI_IN / AIO_I2SI_HDMI / AIO_I2S_LOOPBCK / AIO_I2S_DISABLE }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioGetIptSrc_I2SPri(AIO_I2SI_SRC *p_i2s_src);

/**
 * Tell audio driver if HDMI-IN is HBR mode.
 * This function is only used with HDMI source
 *
 * @param <para>	{ TRUE / FALSE }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetIptSrc_HdmiHBR(bool para);

/**
 * Tell audio library/driver if HDMI-IN ever disable its output
 * This function is only used with HDMI source, clear by audio library
 *
 * @param <para>	{ TRUE / FALSE }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetIptSrc_HdmiState(uint32_t new_state, uint32_t mask);
int32_t Audio_AioGetIptSrc_HdmiState(uint32_t *p_state);

/**
 * Select SPDIF_IN input source.
 * This function is usually used with HDMI source
 *
 * @param <src>	{ AIO_SPDIFI_IN / AIO_SPDIFI_HDMI / AIO_SPDIFI_LOOPBACK / AIO_SPDIFI_DISABLE }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetIptSrc_SPDIF(AIO_SPDIFI_SRC src);

/**
 * Get SPDIF_IN source info.
 *
 * @param <p_spdif_src>	{ AIO_SPDIFI_IN / AIO_SPDIFI_HDMI / AIO_SPDIFI_LOOPBACK / AIO_SPDIFI_DISABLE }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioGetIptSrc_SPDIF(AIO_SPDIFI_SRC *p_spdif_src);

/**
 * Select Wire1 input source.
 *
 * @param <src>	{ AIO_WIREIN_AIN1 | AIO_WIREIN_AIN2 | AIO_WIREIN_MONOIN | AIO_WIREIN_BBADC }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetIptSrc_Wire1(uint32_t mix_src);

/**
 * Select Wire2 input source.
 *
 * @param <src>	{ AIO_WIREIN_AIN1 | AIO_WIREIN_AIN2 | AIO_WIREIN_MONOIN | AIO_WIREIN_BBADC }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetIptSrc_Wire2(uint32_t mix_src);

/**
 * Setup BBADC input source.
 *
 * @param <p_cfg_bbadc>	{ pointer of BBADC control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioCfgIptSrc_BBADC(AIO_BBADC_CFG *p_cfg_bbadc);

/**
 * Setup I2S_IN_Primary input source.
 *
 * @param <p_cfg_i2s>	{ pointer of I2S_IN control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioCfgIptSrc_I2SPri(AIO_I2SI_CFG *p_cfg_i2s);

/**
 * Setup SPDIF_IN input source.
 *
 * @param <p_cfg_spdif>	{ pointer of SPDIF_IN control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioCfgIptSrc_SPDIF(AIO_SPDIFI_CFG *p_cfg_spdif);

/**
 * Get DAC0 pcm source.
 *
 * @param <p_dac0_sel>	{ AIO_DAC0_PCM_PB_BF_AVC1 |
 *                        AIO_DAC0_PCM_PB_BF_AVC2 |
 *                        AIO_DAC0_PCM_PB_AF_AVC2 |
 *                        AIO_DAC0_PCM_TS_AF_DVC }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioGetPcmSrc_DAC0(AIO_DAC0_PCM_SRC *p_dac0_sel);

/**
 * Get DAC1 pcm source.
 *
 * @param <p_dac1_sel>	{ AIO_DAC1_PCM_PB_BF_AVC1 |
                          AIO_DAC1_PCM_PB_BF_AVC2 |
                          AIO_DAC1_PCM_PB_AF_AVC2 |
                          AIO_DAC1_PCM_TS_BF_DVC  |
                          AIO_DAC1_PCM_TS_AF_DVC  }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioGetPcmSrc_DAC1(AIO_DAC1_PCM_SRC *p_dac1_sel);

/**
 * Select I2S_OUT source.
 *
 * @param <src>	{ AIO_I2SO_FIFO / AIO_I2SO_IN_SLAVE / AIO_I2SO_IN_MASTER / AIO_I2SO_IN_HDMI / AIO_I2SO_DISABLE }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptSrc_I2S(AIO_I2SO_SRC src);

/**
 * Get I2S_OUT source info.
 *
 * @param <p_i2s_src>	{ AIO_I2SO_FIFO / AIO_I2SO_IN_SLAVE / AIO_I2SO_IN_MASTER / AIO_I2SO_IN_HDMI / AIO_I2SO_DISABLE }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioGetOptSrc_I2S(AIO_I2SO_SRC *p_i2s_src);

/**
 * Select SPDIF_OUT source.
 *
 * @param <src>	{ AIO_SPDIFO_FIFO / AIO_SPDIFO_IN / AIO_SPDIFO_HDMI / AIO_SPDIFO_DISABLE }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptSrc_SPDIF(AIO_SPDIFO_SRC src);

/**
 * Get SPDIF_OUT source info.
 *
 * @param <p_spdif_src>	{ AIO_SPDIFO_FIFO / AIO_SPDIFO_IN / AIO_SPDIFO_HDMI / AIO_SPDIFO_DISABLE }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioGetOptSrc_SPDIF(AIO_SPDIFO_SRC *p_spdif_src);

/**
 * Config Headphone output
 *
 * @param <hp_cfg>	{}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioCfgOptSrc_Headphone(AIO_HEADPHONE_CFG hp_cfg);

/**
 * Auther: Wu Yi-Chiao
 * Date: 2013/6/6
 * Select AIO output source.
 *
 * @param <src>	{ AIO_AIO_MUTE_ALL | AIO_AIO_ADCFE | AIO_AIO_PB_DAC / AIO_AIO_TS_DAC}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptSrc_AIO(AIO_AIO2_SRC mix_src);

/**
 * Auther: Wu Yi-Chiao
 * Date: 2013/6/6
 * Select LO(AIO) output source.
 *
 * @param <src>	{ AIO_LO_MUTE_ALL | AIO_LO_ADCFE | AIO_LO_PB_DAC / AIO_LO_TS_DAC}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptSrc_Lineout(AIO_LO_SRC mix_src);

/**
 * Mute/Unmute SPDIF output.
 *
 * @param <para>	{ AIO_ENABLE / AIO_DISABLE }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioMute_SPDIF(bool para);

/**
 * Select Headphone output channel configuration.
 *
 * @param <sel>	{ AIO_OPT_CHANNEL_R_TO_L |AIO_OPT_CHANNEL_STEREO | AIO_OPT_CHANNEL_LR_SWAP | AIO_OPT_CHANNEL_L_TO_R}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
#ifdef MERLIN_SEIES
int32_t Audio_AioSetOptChannel_Headphone(AIO_OPT_CHANNEL sel);

/**
 * Select AIO output channel configuration.
 *
 * @param <sel>	{ AIO_OPT_CHANNEL_STEREO | AIO_OPT_CHANNEL_L_TO_R | AIO_OPT_CHANNEL_R_TO_L }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptChannel_AIO1(AIO_OPT_CHANNEL sel);
/**
 * Select AIO output channel configuration.
 *
 * @param <sel>	{ AIO_OPT_CHANNEL_STEREO | AIO_OPT_CHANNEL_L_TO_R | AIO_OPT_CHANNEL_R_TO_L }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptChannel_AIO2(AIO_OPT_CHANNEL sel);
#endif
/**
 * Select Lineout output channel configuration.
 *
 * @param <sel>	{ AIO_OPT_CHANNEL_STEREO | AIO_OPT_CHANNEL_L_TO_R | AIO_OPT_CHANNEL_R_TO_L }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptChannel_Lineout(AIO_OPT_CHANNEL sel);

/**
 * Select DAC0 configuration.
 *
 * @param <sel>	{ DIO_OPT_CHANNEL_STEREO |DIO_OPT_CHANNEL_L_TO_R | DIO_OPT_CHANNEL_R_TO_L | DIO_OPT_CHANNEL_LR_SWAP}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_DIOSetOptChannel_DAC0(DIO_OPT_CHANNEL sel);

/**
 * Select DAC1 configuration.
 *
 * @param <sel>	{ DIO_OPT_CHANNEL_STEREO |DIO_OPT_CHANNEL_L_TO_R | DIO_OPT_CHANNEL_R_TO_L | DIO_OPT_CHANNEL_LR_SWAP}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_DIOSetOptChannel_DAC1(DIO_OPT_CHANNEL sel);

/**
 * Select I2S out configuration.
 *
 * @param <sel>	{ DIO_OPT_CHANNEL_STEREO |DIO_OPT_CHANNEL_L_TO_R | DIO_OPT_CHANNEL_R_TO_L | DIO_OPT_CHANNEL_LR_SWAP}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_DIOSetOptChannel_I2S(DIO_OPT_CHANNEL sel, uint16_t ch_sel);

/**
 * Select SPDIF out configuration.
 *
 * @param <sel>	{ DIO_OPT_CHANNEL_STEREO |DIO_OPT_CHANNEL_L_TO_R | DIO_OPT_CHANNEL_R_TO_L | DIO_OPT_CHANNEL_LR_SWAP}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_DIOSetOptChannel_SPDIF(DIO_OPT_CHANNEL sel);

/**
 * Select DAC0/DAC1/I2S out/SPDIF out configuration.
 *
 * @param <sel>	{ DIO_OPT_CHANNEL_STEREO |DIO_OPT_CHANNEL_L_TO_R | DIO_OPT_CHANNEL_R_TO_L | DIO_OPT_CHANNEL_LR_SWAP}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_DIOSetOptChannel_ALL(DIO_OPT_CHANNEL sel);

/**
 * Mute/Unmute Headphone(Amp) output.
 *
 * @param <para>	{ AIO_ENABLE / AIO_DISABLE }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioMute_Headphone(bool para);

/**
 * Mute/Unmute Capless Lineout output.
 *
 * @param <para>	{ AIO_ENABLE / AIO_DISABLE }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioMute_CLLO(bool para);

/**
 * Mute/Unmute AIO output.
 *
 * @param <para>	{ AIO_ENABLE / AIO_DISABLE }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioMute_AIO(bool para);

/**
 * Mute/Unmute AIO output.
 *
 * @param <para>	{ AIO_ENABLE / AIO_DISABLE }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioMute_Lineout(bool para);

/**
 * Set BBADC volume1
 * range from -58.5dB to +24dB , 1.5dB per step
 * [-58.5dB ~ 0dB ~ +24dB] = [ 0x00 ~ 0x27 ~ 0x37 ]
 *
 * @param <l_gain>	{ volume of left channel }
 * @param <r_gain>	{ volume of right channel }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetBBADCVol1(AIO_ADCVOL1_ID l_gain, AIO_ADCVOL1_ID r_gain);

/**
 * Enable/Disable LasVegas Audio Analog Modules
 *
 * @param <para>		{ AIO_ENABLE / AIO_DISABLE }
 * @param <module_idx>	{ AIO_POW_XXX, refer to audio_aio.h }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetAnalogPower(bool para, uint32_t module_idx);

/**
 * Configure LasVegas Audio Interface before using them.
 * This function maybe recall afer resuming from power-saving mode.
 * If the sequence of resuming from power-saving is the same with system-power-on,
 * this function can be replaced by audio_AioInit().
 *
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioConfig(void);

/**
 * Init. LasVegas Audio Interface
 *
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioInit(ATV_CFG *p_atv_cfg);

/**
 * DeInit. LasVegas Audio Interface
 * call this function before into power-save/power-down mode.
 *
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioDeInit(void);

/**
 * Enable/Disable Swap Input L/R Channel
 *
 * @param <para>		{ AIO_ENABLE / AIO_DISABLE }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSwapIptChannel_LR(bool para);

/**
 * Enable/Disable print peak detect result
 * @param <para>		{ AIO_ENABLE / AIO_DISABLE }
 * @ingroup lib_audio
 */
void Audio_AioEnablePrintPeakDetect(uint32_t isEnable);

/**
 * register Amp Mute callback function for audio library
 * @param <para>		{ callback function name }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetMuteAmpFunc(MUTE_AMP p_func);

/**
 * Determine Mute/Unmute Amp
 *
 * @param <para>	 	{ enable/disable }
 * @param <ch_id>		{ AIO_CH_ID_L/AIO_CH_ID_R/AIO_CH_ID_ALL )
 * @param <mute_by_who>	{ AIO_AMPMUTE_ID )
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetMute(int32_t para, uint32_t ch_id, AIO_AMPMUTE_ID mute_by_who);

/**
 * Determine Get IC version
 *
 * @return				{ VERSION_A or VERSION_B or others }
 * @ingroup lib_audio
 */
AUDIO_ICVERSION Audio_GetIcVersion(void);

/**
 * register Spdif Out Mute callback function for audio library
 *
 * @param <para>		{ callback function name }
 * @ingroup lib_audio
 */
void Audio_AioMuteSpdifOutFuncRegister(MUTE_SPDIF_OUT p_func);

int32_t Audio_AioSetSpdifOutMute(bool para, uint32_t mute_id);

/** 
 * Call this API to compensate the HW default gain difference of ADC 
 *  
 * @ingroup lib_audio 
 */
void Audio_AioADCGainCompensate(void);

/**
 * register AV Out Mute callback function for audio library
 *
 * @param <para>		{ callback function name }
 * @ingroup lib_audio
 */
void Audio_AioMuteAVOutFuncRegister(MUTE_AV_OUT p_func);

int32_t Audio_AioSetAVOutMute(bool para);

int32_t Audio_AioSemInit(void);
void Audio_AioSemDeInit(void);

int32_t Audio_HW_AQ_Init(ATV_CFG *p_atv_cfg);
int32_t Audio_HW_AQ_DeInit(void);

uint32_t isEQOverflow(void);
uint32_t isLoudnessOverflow(void);

#endif

