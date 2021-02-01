#ifndef AUDIO_HW_ATV_H
#define AUDIO_HW_ATV_H

#include <linux/types.h>

#define ATV_OK					(0)
#define ATV_ERR_NOT_IMPLEMENTED			(-1)

#define IFD_BP_SEL_BYPASS			(0x00<<4)
#define IFD_BP_SEL_4P5MHZ_200K			(0x01<<4)
#define IFD_BP_SEL_4P5MHZ_540K			(0x02<<4)
#define IFD_BP_SEL_4P5MHZ_400K			(0x03<<4)
#define IFD_BP_SEL_5P30MHZ_6P7MHZ		(0x04<<4)
#define IFD_BP_SEL_5P25MHZ_6P75MHZ		(0x05<<4)
#define IFD_BP_SEL_5P2MHZ_6P8MHZ		(0x06<<4)
#define IFD_BP_SEL_6P5MHZ_200K			(0x07<<4)
#define IFD_BP_SEL_6P5MHZ_300K			(0x08<<4)
#define IFD_BP_SEL_6P5MHZ_400K			(0x09<<4)
#define IFD_BP_SEL_4P5MHZ_688K			(0x0a<<4)
#define IFD_BP_SEL_4P5MHZ_600K			(0x0b<<4)
#define IFD_BP_SEL_4P5MHZ_450K			(0x0c<<4)
#define IFD_BP_SEL_6P126MHZ_2P021MHZ		(0x10<<4)
#define IFD_BP_SEL_6P126MHZ_2P012MHZ		(0x11<<4)
#define IFD_BP_SEL_6P126MHZ_2P003MHZ		(0x12<<4)
#define IFD_BP_SEL_6P126MHZ_1P987MHZ		(0x13<<4)
#define IFD_BP_SEL_6P126MHZ_1P862MHZ		(0x14<<4)
#define IFD_BP_SEL_6P126MHZ_1P853MHZ		(0x15<<4)
#define IFD_BP_SEL_6P126MHZ_1P838MHZ		(0x16<<4)
#define IFD_BP_SEL_4P5MHZ_1MHZ			(0x17<<4)
#define IFD_BP_SEL_4P5MHZ_1P4MHZ		(0x18<<4)
#define IFD_BP_SEL_MASK_BITS			(0xff<<4)
#define IFD_LP_SEL_BYPASS			(0x0<<0)
#define IFD_LP_SEL_NTSC				(0x1<<0)
#define IFD_LP_SEL_PAL				(0x2<<0)
#define IFD_LP_SEL_MASK_BITS			(0x3<<0)

#define IFD_AIN_SEL_SIFPGA			(0x0<<0)
#define IFD_AIN_SEL_IFDPGA			(0x1<<0)
#define IFD_AIN_SEL_BYPASS_DIF			(0x2<<0)
#define IFD_AIN_SEL_HIZ				(0x3<<0)
#define IFD_AIN_SEL_MASK_BITS			(0x3<<0)

#define IFD_ADC_CK_FOR_SIF			(0x0<<7)	/* 24.576MHZ */
#define IFD_ADC_CK_FOR_IFD			(0x1<<7)	/* 54MHZ */
#define IFD_ADC_CK_MASK_BIT			(0x1<<7)

#define ATV_FW_SCAN_MAG_THRES			(0x400)		/* according to dragon's experience */
#define ATV_FW_SCAN_TICK_DEBOUNCE_LEVEL		(4)
#define ATV_FW_SCAN_NOISE_CNT_LEVEL		(2)

#define ATV_FW_SCAN_FREQ_OFFSET			(400)
#define ATV_FW_SCAN_FREQ_STEP			(50)
#define ATV_FW_SCAN_FREQ_RANGE			(2*ATV_FW_SCAN_FREQ_OFFSET/ATV_FW_SCAN_FREQ_STEP)

#define ATV_ENABLE				(1)
#define ATV_DISABLE				(0)

/* 
 * AIO-INIT-FLAG
 * APP-INIT-FLAG
 * ATV-INIT-FLAG
 */ 
/* bit0 - bit6, bit-mapping */
#define ATV_INIT_SUPPORT_STD_MASK		(0x2F<<0)
#define ATV_INIT_SUPPORT_STD_BTSC		(0x01<<0)
#define ATV_INIT_SUPPORT_STD_A2M		(0x01<<1)
#define ATV_INIT_SUPPORT_STD_BG			(0x01<<2)
#define ATV_INIT_SUPPORT_STD_DK			(0x01<<3)
#define ATV_INIT_SUPPORT_STD_L			(0x01<<4)
#define ATV_INIT_SUPPORT_STD_I			(0x01<<5)
#define ATV_INIT_SUPPORT_STD_NICAM		(0x01<<6)
#define ATV_INIT_SUPPORT_STD_ALL		(0x3F<<0)
/* bit7 - bit8 */
#define ATV_INIT_DEV_M_MASK			(0x03<<7)
#define ATV_INIT_DEV_M_NORMAL			(0x00<<7)
#define ATV_INIT_DEV_M_HIGH			(0x01<<7)
#define ATV_INIT_DEV_M_SUPER			(0x02<<7)
#define ATV_INIT_DEV_M_ULTRA			(0x03<<7)
/* bit9 - bit10 */
#define ATV_INIT_DEV_BGDKI_MASK			(0x03<<9)
#define ATV_INIT_DEV_BGDKI_NORMAL		(0x00<<9)	/* 100 */
#define ATV_INIT_DEV_BGDKI_HIGH			(0x01<<9)	/* 200 */
#define ATV_INIT_DEV_BGDKI_SUPER		(0x02<<9)	/* 300 */
#define ATV_INIT_DEV_BGDKI_ULTRA		(0x03<<9)	/* 600 */
/* bit11 */
#define ATV_INIT_HDEV_CARRIER_DETECT		(0x01<<11)
/* bit12 - bit13 */
#define ATV_INIT_FREQ_SHIFT_MASK		(0x03<<12)
#define ATV_INIT_FREQ_SHIFT_DISABLE		(0x00<<12)
#define ATV_INIT_FREQ_SHIFT_150K		(0x01<<12)
#define ATV_INIT_FREQ_SHIFT_300K		(0x02<<12)
#define ATV_INIT_FREQ_SHIFT_500K		(0x03<<12)
/* bit14 */
#define ATV_INIT_SOUND_MODE_AUTO_DETECT		(0x01<<14)
/* bit15 */
#define ATV_INIT_SOUND_MODE_BGDKI_VOL_COMP	(0x01<<15)
/* bit16 */
#define ATV_INIT_SOUND_MODE_M_VOL_COMP		(0x01<<16)
/* bit17 */
#define ATV_INIT_SOUND_STD_AUTO_SCAN		(0x01<<17)
/* bit18 */
#define ATV_INIT_SOUND_STD_HW_DETECT		(0x01<<18)
/* bit19 - bit22 */
#define ATV_INIT_ADAPATIVE_SC1_THD_4P5MHZ	(0x01<<19)
#define ATV_INIT_ADAPATIVE_SC1_THD_5P5MHZ	(0x01<<20)
#define ATV_INIT_ADAPATIVE_SC1_THD_6P0MHZ	(0x01<<21)
#define ATV_INIT_ADAPATIVE_SC1_THD_6P5MHZ	(0x01<<22)
/* bit23 */
#define ATV_INIT_DATA_SOURCE_MASK		(0x01<<23)
#define ATV_INIT_DATA_SOURCE_IFD		(0x00<<23)
#define ATV_INIT_DATA_SOURCE_SIF		(0x01<<23)
/* bit24 - bit25 */
#define ATV_INIT_DEV_NICAM_BGDKI_MASK		(0x03<<24)
#define ATV_INIT_DEV_NICAM_BGDKI_NORMAL		(0x00<<24)	/* 100k */
#define ATV_INIT_DEV_NICAM_BGDKI_HIGH		(0x01<<24)	/* 200k */
#define ATV_INIT_DEV_NICAM_BGDKI_SUPER		(0x02<<24)	/* 300k */
/* bit26 - bit27 */
#define ATV_INIT_DEV_A2_BGDK_MASK		(0x03<<26)
#define ATV_INIT_DEV_A2_BGDK_NORMAL		(0x00<<26)	/* 100k */
#define ATV_INIT_DEV_A2_BGDK_HIGH		(0x01<<26)	/* 150k */
#define ATV_INIT_DEV_A2_BGDK_SUPER		(0x02<<26)	/* 200k */
/* bit28 - bit29 */
#define ATV_INIT_DEV_A2_M_MASK			(0x03<<28)
#define ATV_INIT_DEV_A2_M_NORMAL		(0x00<<28)	/* 70k */
#define ATV_INIT_DEV_A2_M_HIGH			(0x01<<28)	/* 100k */
#define ATV_INIT_DEV_A2_M_SUPER			(0x02<<28)	/* 150k */
/* bit30, reserved */
/* bit31 */
#define ATV_INIT_BTSC_LANG_SELECT		(0x01<<31)

/* M MONO & BTSC */
#define ATV_INIT_DEV_M_MASK_CONFIG		(0x03<<7)
#define ATV_INIT_DEV_M_NORMAL_CONFIG		(0x01<<7)	/* Nomal = +-100k for BTSC / 50k for MN MONO */
#define ATV_INIT_DEV_M_HIGH_CONFIG		(0x02<<7)	/* High = +-150k for BTSC / 100k for MN MONO */
#define ATV_INIT_DEV_M_SUPER_CONFIG		(0x03<<7)	/* Super = +-200k for BTSC / 150k for MN MONO */

/* BG/DK/I MONO */
#define ATV_INIT_DEV_BGDKI_MASK_CONFIG		(0x07<<9)
#define ATV_INIT_DEV_BGDKI_NORMAL_CONFIG	(0x01<<9)	/* Nomal = +-100k */
#define ATV_INIT_DEV_BGDKI_HIGH_CONFIG		(0x02<<9)	/* High = +-200k */
#define ATV_INIT_DEV_BGDKI_SUPER_CONFIG		(0x03<<9)	/* Super = +-300k */

/* BG/DK/I NICAM */
#define ATV_INIT_DEV_NICAM_BGDKI_MASK_CONFIG	(0x03<<24)
#define ATV_INIT_DEV_NICAM_BGDKI_NORMAL_CONFIG	(0x01<<24)	/* Nomal = +-100k */
#define ATV_INIT_DEV_NICAM_BGDKI_HIGH_CONFIG	(0x02<<24)	/* High = +-200k */
#define ATV_INIT_DEV_NICAM_BGDKI_SUPER_CONFIG	(0x03<<24)	/* Super = +-300k */

/* BG/DK A2 */
#define ATV_INIT_DEV_A2_BGDK_MASK_CONFIG	(0x03<<26)
#define ATV_INIT_DEV_A2_BGDK_NORMAL_CONFIG	(0x01<<26)	/* Nomal = +-100k */
#define ATV_INIT_DEV_A2_BGDK_HIGH_CONFIG	(0x02<<26)	/* High = +-150k */
#define ATV_INIT_DEV_A2_BGDK_SUPER_CONFIG	(0x03<<26)	/* Super = +-200k */

/* MN A2 */
#define ATV_INIT_DEV_A2_M_MASK_CONFIG		(0x03<<28)
#define ATV_INIT_DEV_A2_M_NORMAL_CONFIG		(0x01<<26)	/* Nomal = +-70k */
#define ATV_INIT_DEV_A2_M_HIGH_CONFIG		(0x02<<26)	/* High = +-100k */
#define ATV_INIT_DEV_A2_M_SUPER_CONFIG		(0x03<<26)	/* Super = +-150k */

#define ATV_SIF_EQ_BAND_NUM			(3)		/* SIF_LP, SIF_BP1, SIF_BP2 */
#define ATV_SIF_EQ_BAND_NUM_MAX			(3)		/* SIF_LP, SIF_BP1, SIF_BP2 */

typedef enum {
	/* bit-mapping setting */
	ATV_CH_ID_L	= (0x1 << 0),
	ATV_CH_ID_R	= (0x1 << 1),
	ATV_CH_ID_LS	= (0x1 << 2),	/* ch2 */
	ATV_CH_ID_RS	= (0x1 << 3),	/* ch3 */
	ATV_CH_ID_C	= (0x1 << 4),	/* ch4 */
	ATV_CH_ID_SW	= (0x1 << 5),	/* ch5 */
	ATV_CH_ID_ALL	= (0xFF),
} ATV_CH_ID;

typedef enum {
	ATV_DATA_SRC_IFD,
	ATV_DATA_SRC_SIF
} ATV_DATA_SRC;

/* 
 * Audio Tv Std have 16 format
 * ATV_SOUND_STD_MN_MONO ~ ATV_SOUND_STD_NICAM_I
 *
 * 5 Main Syteem BG , DK , L , I , MN
 * 
 * |--------------------|-----------------------|---------------|
 * | main stytem        | main tone position    | audio format  |
 * |--------------------|-----------------------|---------------|
 * | MN                 | 4.5 MHz               | MN_MONO       |
 * |--------------------|-----------------------|---------------|
 * | MN                 | 4.5 MHz               | BYSC          |
 * |--------------------|-----------------------|---------------|
 * | MN                 | 4.5 MHz               | EIAJ          |
 * |--------------------|-----------------------|---------------|
 * | MN                 | 4.5 MHz               | A2M           |
 * |--------------------|-----------------------|---------------|
 * | BG                 | 5.5 MHz               | BG_MONO       |
 * |--------------------|-----------------------|---------------|
 * | BG                 | 5.5 MHz               | A2_BG         |
 * |--------------------|-----------------------|---------------|
 * | BG                 | 5.5 MHz               | NICAM_BG      |
 * |--------------------|-----------------------|---------------|
 * | DK                 | 6.5 MHz               | DK_MONO       |
 * |--------------------|-----------------------|---------------|
 * | DK                 | 6.5 MHz               | A2_DK1~A2_DK3 |
 * |--------------------|-----------------------|---------------|
 * | DK                 | 6.5 MHz               | NICAM_DK      |
 * |--------------------|-----------------------|---------------|
 * | L                  | 6.5 MHz               | AM_MONO       |
 * |--------------------|-----------------------|---------------|
 * | L                  | 6.5 MHz               | NICAM_L       |
 * |--------------------|-----------------------|---------------|
 * | I                  | 6.0 MHz               | FM_MONO_NO_I  |
 * |--------------------|-----------------------|---------------|
 * | I                  | 6.0 MHz               | NICAM_I       |
 * |--------------------|-----------------------|---------------|
 * | Chian Style        | Only support Mono System              |
 * |--------------------|-----------------------|---------------|
 */

/* For AVD check */
typedef union {
	unsigned int regValue;
	struct {
		unsigned int  sb2_arch:32;
	};
} Audio_sb2_arch_reg_RBUS;

typedef enum {
	/* identical to the order in register's field */
	ATV_SOUND_STD_MN_MONO		= 0x00,
	ATV_SOUND_STD_BTSC		= 0x01,
	ATV_SOUND_STD_A2_M		= 0x02,
	ATV_SOUND_STD_EIAJ		= 0x03,
	ATV_SOUND_STD_BG_MONO		= 0x04,
	ATV_SOUND_STD_A2_BG		= 0x05,
	ATV_SOUND_STD_NICAM_BG		= 0x06,
	ATV_SOUND_STD_DK_MONO		= 0x07,
	ATV_SOUND_STD_A2_DK1		= 0x08,
	ATV_SOUND_STD_A2_DK2		= 0x09,
	ATV_SOUND_STD_A2_DK3		= 0x0A,
	ATV_SOUND_STD_NICAM_DK		= 0x0B,
	ATV_SOUND_STD_AM_MONO		= 0x0C,
	ATV_SOUND_STD_NICAM_L		= 0x0D,
	ATV_SOUND_STD_FM_MONO_NO_I	= 0x0E,
	ATV_SOUND_STD_NICAM_I		= 0x0F,
	ATV_SOUND_STD_UNKNOWN		= 0x1F,
	ATV_SOUND_STD_AUTO		= 0x7F,	/* f/w only */
} ATV_SOUND_STD;

typedef enum {
	ATV_SOUND_DK_SYSTEM		= 0,
	ATV_SOUND_I_SYSTEM		= 1,
	ATV_SOUND_BG_SYSTEM		= 2,
	ATV_SOUND_MN_SYSTEM		= 3,
	ATV_SOUND_L_SYSTEM		= 4,
	ATV_SOUND_LA_SYSTEM		= 5,
	ATV_SOUND_UNKNOWN_SYSTEM	= 6,
	ATV_SOUND_AUTO_SYSTEM		= 7,
} ATV_SOUND_STD_MAIN_SYSTEM;

typedef enum {
	DRV_ATV_SOUND_SYSTEM_UNKNOWN	= 0,
	DRV_ATV_SOUND_SYSTEM_DK		= 1,
	DRV_ATV_SOUND_SYSTEM_I		= 2,
	DRV_ATV_SOUND_SYSTEM_BG		= 3,
	DRV_ATV_SOUND_SYSTEM_MN		= 4,
	DRV_ATV_SOUND_SYSTEM_L		= 5,
	DRV_ATV_SOUND_SYSTEM_LA		= 6,
	DRV_ATV_SOUND_SYSTEM_A2BG	= 7,
	DRV_ATV_SOUND_SYSTEM_A2DK1	= 8,
	DRV_ATV_SOUND_SYSTEM_A2DK2	= 9,
	DRV_ATV_SOUND_SYSTEM_A2DK3	= 10,
	DRV_ATV_SOUND_SYSTEM_AUTO	= 11,
} DRV_ATV_SOUND_SYSTEM;

typedef enum {
	ATV_SOUND_MODE_MONO		= 0,
	ATV_SOUND_MODE_STEREO		= 1,
	ATV_SOUND_MODE_DUAL		= 2,
	ATV_SOUND_MODE_SAP_MONO		= 3,
	ATV_SOUND_MODE_SAP_STEREO	= 4,
	ATV_SOUND_MODE_AUTO		= 5,
} ATV_SOUND_MODE;

typedef enum {
	/* identical to the order in register's field */
	ATV_SOUND_MODE_NICAM_STEREO	= 0,
	ATV_SOUND_MODE_NICAM_DUAL	= 2,
	ATV_SOUND_MODE_NICAM_MONO	= 4,
	ATV_SOUND_MODE_NICAM_DATA	= 6,
	ATV_SOUND_MODE_NICAM_NOISY	= 7,	/* s/w only */
} ATV_SOUND_MODE_NICAM;

typedef enum {
	ATV_SOUND_SEL_FMAM		= 0,
	ATV_SOUND_SEL_STEREO_AB		= 1,
	ATV_SOUND_SEL_STEREO_A		= 2,
	ATV_SOUND_SEL_STEREO_B		= 3
} ATV_SOUND_SEL;

typedef enum {
	ATV_BTSC_MTS_SEL_MONO		= 0,
	ATV_BTSC_MTS_SEL_STEREO		= 1,
	ATV_BTSC_MTS_SEL_SAP		= 2,
	ATV_BTSC_MTS_SEL_L_MONO_R_SAP	= 3,
} ATV_BTSC_MTS_SEL;

typedef enum {
	ATV_NICAM_SEL_ANA_MONO		= 0,
	ATV_NICAM_SEL_DIG_MONO		= 1,
	ATV_NICAM_SEL_DIG_STEREO	= 2,
	ATV_NICAM_SEL_DIG_LANGA		= 3,
	ATV_NICAM_SEL_DIG_LANGB		= 4,
	ATV_NICAM_SEL_DIG_LANGAB	= 5,
} ATV_NICAM_SEL;

typedef enum {
	ATV_A2_SEL_MONO			= 0,
	ATV_A2_SEL_STEREO		= 1,
	ATV_A2_SEL_LANGA		= 2,
	ATV_A2_SEL_LANGB		= 3,
	ATV_A2_SEL_LANGAB		= 4,
} ATV_A2_SEL;

typedef enum {
	ATV_PLAY_CH_SEL_L		= 0,
	ATV_PLAY_CH_SEL_R		= 1,
	ATV_PLAY_CH_SEL_L_ADD_R		= 2,
	ATV_PLAY_CH_SEL_L_SUB_R		= 3,
} ATV_PLAY_CH_SEL;

typedef enum {
	ATV_MTS_PRIO_BTSC		= 0,
	ATV_MTS_PRIO_EIAJ		= 1,
	ATV_MTS_PRIO_MONO		= 2,
	ATV_MTS_PRIO_DK			= 3,
	ATV_MTS_PRIO_L			= 4,
} ATV_MTS_PRIORITY;

typedef enum {
	/* identical to the order in register's field */
	ATV_MN_PRIO_BTSC		= 0,
	ATV_MN_PRIO_EIAJ		= 1,
	ATV_MN_PRIO_MONO1		= 2,
	ATV_MN_PRIO_MONO2		= 3,
} ATV_MN_PRIO;

typedef enum {
	/* identical to the order in register's field */
	ATV_DKL_PRIO_DK			= 0,
	ATV_DKL_PRIO_L			= 1
} ATV_DKL_PRIO;

typedef enum {
	ATV_SOUND_SELECT_MONO		= 0,
	ATV_SOUND_SELECT_STEREO		= 1,
	ATV_SOUND_SELECT_LANGA		= 2,
	ATV_SOUND_SELECT_LANGB		= 3,
	/*	ATV_SOUND_SELECT_MONO_DIGITAL, */
	ATV_SOUND_SELECT_LANGAB,
	ATV_SOUND_SELECT_SAP,
} ATV_SOUND_SELECT;

typedef enum {
	ATV_MAIN_STD_MONO		= 0,
	ATV_MAIN_STD_NICAM		= 1,
	ATV_MAIN_STD_A2			= 2,
	ATV_MAIN_STD_BTSC		= 3,
	ATV_MAIN_STD_UNKNOW		= 4,
} ATV_MAIN_STD_TYPE;

typedef enum {
	ATV_TASK_STOP			= 0,	/* stop status */
	ATV_TASK_RUN			= 1,	/* run status */
	ATV_TASK_PAUSE			= 2,	/* pasue status */
} ATV_TASK_STATUS;

/* 
 * Audio define 4 main system
 * a :: Mono system (China, Sourth Africa )
 * b::  Nicam  system (Euro)
 * c::  A2  system (Euro)
 * d::  BTSC system (USA)
 */

/* 
 * Sound Mode have 3 type  Mono , Stereo , dual.  The BTSC system may be add
 * sub Channel (SAP)
 */

/* 
 * Sound select is used to select which sound to  be played. So the setting of
 * sound select is according to sound mode
 */

/* 
 * the relation about sound select and sound mode::
 *
 * |--------------------|------------------------------------------------------|
 * | Sound mode         | Sound Select                                         |
 * |--------------------|------------------------------------------------------|
 * | Mono               | 1. Mono                                              |
 * |--------------------|------------------------------------------------------|
 * | Stereo             | 1. Mono (special case , new L (R) = mix (old L and   |
 * |                    |    old R))                                           |
 * |                    | 2. Stereo (L Channel and R Channel is different,     |
 * |                    |    ex :: L is  400 HZ , R is 1K Hz)                  |
 * |--------------------|------------------------------------------------------|
 * | Dual               | 1. Language A                                        |
 * |                    | 2. Language B                                        |
 * |                    | 3. LanguageA+B (special case , L is language A,      |
 * |                    |    R is language B)                                  |
 * |--------------------|------------------------------------------------------|
 *
 * Mono system sound select,
 * |--------------------|------------------------------------------------------|
 * | Sound mode         | Sound Select                                         |
 * |--------------------|------------------------------------------------------|
 * | Mono               | 1. Mono                                              |
 * |--------------------|------------------------------------------------------|
 * 
 * A2 system sound select,
 * |--------------------|------------------------------------------------------|
 * | Sound mode         | Sound Select                                         |
 * |--------------------|------------------------------------------------------|
 * | Mono               | 1. Mono                                              |
 * |--------------------|------------------------------------------------------|
 * | Stereo             | 1. Mono                                              |
 * |                    | 2. Stereo                                            |
 * |--------------------|------------------------------------------------------|
 * | Dual               | 1. Language A                                        |
 * |                    | 2. Language B                                        |
 * |                    | 3. LanguageA+B (special case , L is language A,      |
 * |                    |    R is language B)                                  |
 * |--------------------|------------------------------------------------------|
 * 
 * BTSC  system sound select,
 * |--------------------|------------------------------------------------------|
 * | Sound mode         | Sound Select                                         |
 * |--------------------|------------------------------------------------------|
 * | Mono               | 1) Mono                                              |
 * |--------------------|------------------------------------------------------|
 * | Stereo             | 1. Mono                                              |
 * |                    | 2. Stereo                                            |
 * |--------------------|------------------------------------------------------|
 * | Mono+Sap           | 1. Mono                                              |
 * |                    | 2. Sap                                               |
 * |--------------------|------------------------------------------------------|
 * | Stereo+Sap         | 1. Mono                                              |
 * |                    | 2. Stereo                                            |
 * |                    | 3. Sap                                               |
 * |--------------------|------------------------------------------------------|
 */

/*
 * Nicam system have 2 sound, one is Analog part , the other is Digital part,
 * and the analog sound mode is always mono.
 * The digital part have 3 sound mode (mono, stereo, dual).
 */

/* 
 * Nicam system sound select,
 * |--------------------|------------------------------------------------------|
 * | Sound mode         | Sound Select                                         |
 * |--------------------|------------------------------------------------------|
 * | Aanog Mono +       | 1. Ananlog Mono                                      |
 * | Digital Mono       | 2. Digital Mono                                      |
 * |--------------------|------------------------------------------------------|
 * | Aanog Mono +       | 1. Ananlog Mono                                      |
 * | Digital Stereo     | 2. Digital Stereo                                    |
 * |--------------------|------------------------------------------------------|
 * | Aanog Mono +       | 1. Ananlog Mono                                      |
 * | Digital Dual       | 2. Digital language A                                |
 * |                    | 3. Digital language B                                |
 * |                    | 4. Digital language A+B (special case)               |
 * |--------------------|------------------------------------------------------|
 *  
 */

/* 
 * |------------|----------------------------------------|---------------------|
 * | BROADCAST  | AUDIO_ATVSETBTSCSOUNDSELECT            | OUTPUT              |
 * | SIGNAL     |---------------------|------------------|                     |
 * |            | ISPREFERPLAYSTEREO  | ISPREFERPLAYSAP  |                     |
 * |------------|---------------------|------------------|---------------------|
 * | MONO       | 0                   | 0                | MONO                |
 * |            |---------------------|------------------|---------------------|
 * |            | 0                   | 1                | MONO                |
 * |            |---------------------|------------------|---------------------|
 * |            | 1                   | 0                | MONO                |
 * |            |---------------------|------------------|---------------------|
 * |            | 1                   | 1                | MONO                |
 * |------------|---------------------|------------------|---------------------|
 * | STEREO     | 0                   | 0                | MONO(L+R*MIX)       |
 * |            |---------------------|------------------|---------------------|
 * |            | 0                   | 1                | MONO(L+R*MIX)       |
 * |            |---------------------|------------------|---------------------|
 * |            | 1                   | 0                | STEREO              |
 * |            |---------------------|------------------|---------------------|
 * |            | 1                   | 1                | STEREO              |
 * |------------|---------------------|------------------|---------------------|
 * | MONO +     | 0                   | 0                | MONO                |
 * | SAP        |---------------------|------------------|---------------------|
 * |            | 0                   | 1                | SAP                 |
 * |            |---------------------|------------------|---------------------|
 * |            | 1                   | 0                | MONO                |
 * |            |---------------------|------------------|---------------------|
 * |            | 1                   | 1                | SAP                 |
 * |------------|---------------------|------------------|---------------------|
 * | STEREO +   | 0                   | 0                | MONO(L+R*MIX)       |
 * | SAP        |---------------------|------------------|---------------------|
 * |            | 0                   | 1                | SAP                 |
 * |            |---------------------|------------------|---------------------|
 * |            | 1                   | 0                | STEREO              |
 * |            |---------------------|------------------|---------------------|
 * |            | 1                   | 1                | SAP                 |
 * |------------|---------------------|------------------|---------------------| 
 */

/* 
 * |------------|------------------------------------------|-------------------|
 * | BROADCAST  | AUDIO_ATVSETA2SOUNDSELECT                | OUTPUT            |
 * | SIGNAL     |--------------------|---------------------|                   |
 * |            | ISPREFERPLAYSTEREO | PREFERDUALLANGINDEX |                   |
 * |------------|--------------------|---------------------|-------------------|
 * | MONO       | 0                  | 0                   | MONO              |
 * |            |--------------------|---------------------|-------------------|
 * |            | 0                  | 1                   | MONO              |
 * |            |--------------------|---------------------|-------------------|
 * |            | 1                  | 0                   | MONO              |
 * |            |--------------------|---------------------|-------------------|
 * |            | 1                  | 1                   | MONO              |
 * |------------|--------------------|---------------------|-------------------|
 * | STEREO     | 0                  | 0                   | MONO(L+R MIX)     |
 * |            |--------------------|---------------------|-------------------|
 * |            | 0                  | 1                   | MONO(L+R MIX)     |
 * |            |--------------------|---------------------|-------------------|
 * |            | 1                  | 0                   | STEREO            |
 * |            |--------------------|---------------------|-------------------|
 * |            | 1                  | 1                   | STEREO            |
 * |------------|--------------------|---------------------|-------------------|
 * | DUAL       | 0                  | 0                   | LANGUAGE 0        |
 * |            |--------------------|---------------------|-------------------|
 * |            | 0                  | 1                   | LANGUAGE 1        |
 * |            |--------------------|---------------------|-------------------|
 * |            | 1                  | 0                   | LANGUAGE 0        |
 * |            |--------------------|---------------------|-------------------|
 * |            | 1                  | 1                   | LANGUAGE 1        |
 * |------------|--------------------|---------------------|-------------------|
 */

/* 
 * |------------|--------------------------------------------|-----------------|
 * | BROADCAST  | AUDIO_ATVSETNICAMSOUNDSELECT               | OUTPUT          |
 * | SIGNAL     |----------------------|---------------------|                 |
 * |            | ISPREFERNICAMDIGITAL | PREFERDUALLANGINDEX |                 |
 * |------------|----------------------|---------------------|-----------------|
 * | MONO       | 0                    | 0                   | ANALOG MONO     |
 * |            |----------------------|---------------------|-----------------|
 * |            | 0                    | 1                   | ANALOG MONO     |
 * |            |----------------------|---------------------|-----------------|
 * |            | 1                    | 0                   | DIGITAL MONO    |
 * |            |----------------------|---------------------|-----------------|
 * |            | 1                    | 1                   | DIGITAL MONO    |
 * |------------|----------------------|---------------------|-----------------|
 * | STEREO     | 0                    | 0                   | ANALOG MONO     |
 * |            |----------------------|---------------------|-----------------|
 * |            | 0                    | 1                   | ANALOG MONO     |
 * |            |----------------------|---------------------|-----------------|
 * |            | 1                    | 0                   | DIGITAL STEREO  |
 * |            |----------------------|---------------------|-----------------|
 * |            | 1                    | 1                   | DIGITAL STEREO  |
 * |------------|----------------------|---------------------|-----------------|
 * | DUAL       | 0                    | 0                   | ANALOG MONO     |
 * |            |----------------------|---------------------|-----------------|
 * |            | 0                    | 1                   | ANALOG MONO     |
 * |            |----------------------|---------------------|-----------------|
 * |            | 1                    | 0                   | DIGITAL         |
 * |            |                      |                     | LANGUAGE 0      |
 * |            |----------------------|---------------------|-----------------|
 * |            | 1                    | 1                   | DIGITAL         |
 * |            |                      |                     | LANGUAGE*1      |
 * |------------|----------------------|---------------------|-----------------|
 */

typedef struct {
	uint8_t isNicamSystem;			/* is current std nicam system */
	uint8_t isPlayDigital;			/* is current setting playing nicam digital part or analog part */
	uint8_t isNicamhiErrorRate;
	ATV_SOUND_SELECT current_select;	/* current select */
	ATV_SOUND_STD sound_std;
	ATV_SOUND_MODE ana_soundmode;
	ATV_SOUND_MODE dig_soundmode;
	ATV_MAIN_STD_TYPE std_type;		/* mono or btsc or a2 or nicam */
} ATV_SOUND_INFO;

typedef struct {
	uint8_t Carrier_shif_value;
	uint8_t Carrier_deviation;
} ATV_Carrier_INFO;

typedef enum {
	/* bit-mapping */
	ATV_SCAN_OPT_HW_AUTO	= (1 << 0),
	ATV_SCAN_OPT_FRQ_OFFSET	= (1 << 1),
	ATV_SCAN_OPT_2ND_PHASE	= (1 << 2),
	ATV_DEV_OPT_HIGH	= (1 << 3),
	ATV_DEV_OPT_ULTRA1	= (1 << 4),
	ATV_DEV_OPT_AUTO	= (1 << 5),
} ATV_MSD_OPT;

typedef struct {
	int std;
	int hdev_mode;
	int scan_mode;		/* [0, 1, 2] = [normal, frq_offset, 2nd_phase] */
	int scan_coef;
} ATV_SCAN_STD;

typedef enum {
	ATV_HW_SCAN_FRQ_OFFSET_M50K,
	ATV_HW_SCAN_FRQ_OFFSET_P50K,
	ATV_HW_SCAN_FRQ_OFFSET_M100K,
	ATV_HW_SCAN_FRQ_OFFSET_P100K,
	ATV_HW_SCAN_FRQ_OFFSET_M150K,
	ATV_HW_SCAN_FRQ_OFFSET_P150K,
	ATV_HW_SCAN_FRQ_OFFSET_M200K,
	ATV_HW_SCAN_FRQ_OFFSET_P200K,
} ATV_HW_SCAN_FRQ_OFFSET;

typedef enum {
	/* identical to the order in register's field */
	ATV_PHASE_DELTA_M50K	= 0x00,
	ATV_PHASE_DELTA_P50K	= 0x01,
	ATV_PHASE_DELTA_M100K	= 0x02,
	ATV_PHASE_DELTA_P100K	= 0x03,
	ATV_PHASE_DELTA_M150K	= 0x04,
	ATV_PHASE_DELTA_P150K	= 0x05,
	ATV_PHASE_DELTA_M200K	= 0x06,
	ATV_PHASE_DELTA_P200K	= 0x07,
} ATV_PHASE_DELTA;

typedef enum {
	/* identical to the order in register's field */
	ATV_A2_BW_SEL_50KHZ	= 0x00,
	ATV_A2_BW_SEL_70KHZ	= 0x01,
	ATV_A2_BW_SEL_100KHZ	= 0x02,
	ATV_A2_BW_SEL_150KHZ	= 0x03,
} ATV_A2_BW_SEL;

typedef enum {
	/* identical to the order in register's field */
	ATV_A2_SUB_BW_SEL_50KHZ		= 0x00,
	ATV_A2_SUB_BW_SEL_70KHZ		= 0x01,
	ATV_A2_SUB_BW_SEL_100KHZ	= 0x02,
	ATV_A2_SUB_BW_SEL_150KHZ	= 0x03,
} ATV_SUB_A2_BW_SEL;

typedef enum {
	/* identical to the order in register's field */
	ATV_A2_DEBOUNCE_NON	= 0x00,
	ATV_A2_DEBOUNCE_0P5S	= 0x01,
	ATV_A2_DEBOUNCE_1P0S	= 0x02,
	ATV_A2_DEBOUNCE_1P5S	= 0x03,
	ATV_A2_DEBOUNCE_2P0S	= 0x03,
} ATV_A2_DEBOUNCE_TIME;


typedef enum {
	/* identical to the order in register's field */
	ATV_DEEMPHASIS_50US	= 0x00,
	ATV_DEEMPHASIS_75US	= 0x01,
	ATV_DEEMPHASIS_DISABLE	= 0x02,
} ATV_DEEMPHASIS_TIME;

typedef enum {
	/* identical to the order in register's field */
	ATV_FM1_DEVIATION_16KHZ		= 0x00,
	ATV_FM1_DEVIATION_25KHZ		= 0x01,
	ATV_FM1_DEVIATION_28KHZ		= 0x02,
	ATV_FM1_DEVIATION_50KHZ		= 0x03,
	ATV_FM1_DEVIATION_100KHZ	= 0x04,
	ATV_FM1_DEVIATION_150KHZ	= 0x05,
	ATV_FM1_DEVIATION_180KHZ	= 0x06,
} ATV_FM1_DEVIATION_GAIN;

typedef enum {
	/* identical to the order in register's field */
	ATV_FM2_DEVIATION_18KHZ		= 0x00,
	ATV_FM2_DEVIATION_25KHZ		= 0x01,
	ATV_FM2_DEVIATION_28KHZ		= 0x02,
	ATV_FM2_DEVIATION_50KHZ		= 0x03,
	ATV_FM2_DEVIATION_100KHZ	= 0x04,
	ATV_FM2_DEVIATION_150KHZ	= 0x05,
	ATV_FM2_DEVIATION_180KHZ	= 0x06,
} ATV_FM2_DEVIATION_GAIN;

typedef enum {
	/* identical to the order in register's field */
	ATV_EIAJ_DEVIATION_10KHZ	= 0x00,
	ATV_EIAJ_DEVIATION_20KHZ	= 0x01,
} ATV_EIAJ_DEVIATION;

typedef enum {
	/* identical to the order in register's field */
	ATV_AM_PRESCALE_0DB	= 0x00,
	ATV_AM_PRESCALE_6DB	= 0x01,
	ATV_AM_PRESCALE_12DB	= 0x02,
	ATV_AM_PRESCALE_18DB	= 0x03,
} ATV_AM_PRESCALE;

typedef enum {
	/* identical to the order in register's field */
	ATV_NICAM_BW_250KHZ	= 0x00,
	ATV_NICAM_BW_350KHZ	= 0x01,
} ATV_NICAM_BW;

typedef enum {
	/* identical to the order in register's field */
	ATV_SCAN_FRQ_OFFSET_M50K	= 0x00,
	ATV_SCAN_FRQ_OFFSET_P50K	= 0x01,
	ATV_SCAN_FRQ_OFFSET_M100K	= 0x02,
	ATV_SCAN_FRQ_OFFSET_P100K	= 0x03,
	ATV_SCAN_FRQ_OFFSET_M150K	= 0x04,
	ATV_SCAN_FRQ_OFFSET_P150K	= 0x05,
	ATV_SCAN_FRQ_OFFSET_M200K	= 0x06,
	ATV_SCAN_FRQ_OFFSET_P200K	= 0x07,
} ATV_SCAN_FRQ_OFFSET;

typedef enum {
	/* identical to the order in register's field */
	ATV_MODE_HI_TH_1P25T	= 0x00,
	ATV_MODE_HI_TH_1P50T	= 0x01,
	ATV_MODE_HI_TH_2P00T	= 0x02,
	ATV_MODE_HI_TH_2P50T	= 0x03,
} ATV_MODE_HI_TH;

typedef enum {
	/* identical to the order in register's field */
	ATV_MODE_LO_TH_1P00T	= 0x00,
	ATV_MODE_LO_TH_1P25T	= 0x01,
	ATV_MODE_LO_TH_1P50T	= 0x02,
	ATV_MODE_LO_TH_2P00T	= 0x03,
}ATV_MODE_LO_TH;

/* Dummy for Mac2 */
typedef enum {
	/* identical to the order in register's field */
	ATV_MODE_ACCU_16	= 0x00,
	ATV_MODE_ACCU_32	= 0x01,
	ATV_MODE_ACCU_64	= 0x02,
	ATV_MODE_ACCU_128	= 0x03
} ATV_MODE_ACCU;

typedef enum {
	/* identical to the order in register's field */
	ATV_LPF_COEF_SEL_12 = 0x00,	/* The fast */
	ATV_LPF_COEF_SEL_14 = 0x01,
	ATV_LPF_COEF_SEL_16 = 0x02,
	ATV_LPF_COEF_SEL_18 = 0x03,	/* the most stable coef for A2 sound mode detect */
} ATV_LPF_COEF_SEL;

typedef enum {
	/* identical to the order in register's field */
	ATV_MODE_MAX_TH_0	= 0x0,		/* Lower Max_TH, A2 MD is hard to switch to MONO */
	ATV_MODE_MAX_TH_1500	= 0x1500,	/* Lower Max_TH, A2 MD is hard to switch to MONO */
	ATV_MODE_MAX_TH_2000	= 0x2000,
	ATV_MODE_MAX_TH_2500	= 0x2500,	/* Lower Max_TH, A2 MD is hard to switch to MONO */
	ATV_MODE_MAX_TH_3000	= 0x3000,
	ATV_MODE_MAX_TH_3500	= 0x3500,
	ATV_MODE_MAX_TH_4500	= 0x4500,	/* Old setting */
	ATV_MODE_MAX_TH_6500	= 0x6500,	/* Higher Max_TH, A2 MD is hard to switch to Stereo/Dual */
	ATV_MODE_MAX_TH_8000	= 0x8000,	/* Higher Max_TH, A2 MD is hard to switch to Stereo/Dual */
} ATV_MODE_MAX_TH;

typedef enum {
	ATV_PILOT_PHASE_DELTA_PAL_MN	= 0xA6AAAAA,
	ATV_PILOT_PHASE_DELTA_Others	= 0xA7D44F3,
	ATV_PILOT_PHASE_DELTA_FM_RADIO 	= 0x0CAAAAAB,
} ATV_PILOT_PHASE_DELTA;

typedef enum {
	ATV_FW_SCAN_SC1_M	= 4500,
	ATV_FW_SCAN_SC1_DK	= 6500,
	ATV_FW_SCAN_SC1_BG	= 5500,
	ATV_FW_SCAN_SC1_I	= 6000,
	ATV_FW_SCAN_SC1_L	= 6500,
} ATV_FW_SCAN_SC1;

typedef enum {
	ATV_FW_SCAN_SC2_M		= 4724,
	ATV_FW_SCAN_SC2_DK1		= 6257,
	ATV_FW_SCAN_SC2_DK2		= 6742,
	ATV_FW_SCAN_SC2_DK3		= 6742,
	ATV_FW_SCAN_SC2_BG		= 5742,
	ATV_FW_SCAN_SC2_NICAM_I		= 6552,
	ATV_FW_SCAN_SC2_NICAM_BGDKL	= 5850,
} ATV_FW_SCAN_SC2;

typedef struct {
	unsigned char debounce_cnt;
	unsigned char hi_threshold;
	unsigned char lo_threshold;
	unsigned char accu_num;
} ATV_MODE_TAB;

typedef struct {
	unsigned char lpf_coef_sel;
	unsigned char lpf_coef_sel_lock;
	unsigned char hi_threshold;
	unsigned char lo_threshold;
	unsigned int debounce_time;
	int schmitt_window;
	int max_threshold;
	unsigned int fw_debounce;
} ATV_A2_TH_TAB;

typedef struct {
	unsigned resvd:18;
	unsigned nicam_psf:1;
	unsigned eiaj_sub:1;
	unsigned a2_bw_sel:2;
	unsigned de_emphasis:2;
	unsigned fm1_dev_gain:3;
	unsigned fm2_dev_gain:3;
	unsigned hw_am_prescale:2;
} ATV_PSDE_TAB;

typedef enum {
	ATV_FW_SCAN_OFFSET_P500K	= (0x01 << 0),
	ATV_FW_SCAN_OFFSET_P400K	= (0x01 << 1),
	ATV_FW_SCAN_OFFSET_P300K	= (0x01 << 2),
	ATV_FW_SCAN_OFFSET_P200K	= (0x01 << 3),
	ATV_FW_SCAN_OFFSET_P100K	= (0x01 << 4),
	ATV_FW_SCAN_OFFSET_ZERO		= (0x01 << 5),
	ATV_FW_SCAN_OFFSET_M100K	= (0x01 << 6),
	ATV_FW_SCAN_OFFSET_M200K	= (0x01 << 7),
	ATV_FW_SCAN_OFFSET_M300K	= (0x01 << 8),
	ATV_FW_SCAN_OFFSET_M400K	= (0x01 << 9),
	ATV_FW_SCAN_OFFSET_M500K	= (0x01 << 10),
} ATV_FW_SCAN_OFFSET;

typedef enum {
	AI_FW_SCAN_FREQ_M	= 4500,
	AI_FW_SCAN_FREQ_DK	= 6500,
	AI_FW_SCAN_FREQ_BG	= 5500,
	AI_FW_SCAN_FREQ_I	= 6000,
	AI_FW_SCAN_FREQ_L	= 6000,
} AI_FW_SCAN_FREQ;

typedef enum {
	ATV_STATUS_CHANGE_CHANNEL_STDANDARD_CHANGE,
	ATV_STATUS_DETECTED_STDANDARD_CHANGE,
	ATV_STATUS_SOUNDMODE_CHANGE,
	ATV_STATUS_NICAM_WEAK_SIGNAL,
	ATV_STATUS_NICAM_RECOVERY,
	ATV_STATUS_CHANGE_CHANNEL_STDANDARD_CHANGE_MSG_CLEAR,
	ATV_STATUS_DETECTED_STDANDARD_CHANGE_MSG_CLEAR,
	ATV_STATUS_SOUNDMODE_CHANGE_MSG_CLEAR,
	ATV_STATUS_NICAM_WEAK_SIGNAL_MSG_CLEAR,
	ATV_STATUS_NICAM_RECOVERY_MSG_CLEAR,
	ATV_STATUS_FIRSTTIME_SOUNDMODE,
	ATV_STATUS_DETECTED_STDANDARD_CHANGE_READY
} ATV_STATUS_CHANGE;

typedef struct {
	/* BTSC system */
	int32_t m_vol_comp_btsc_sap;
	int32_t m_vol_comp_btsc_stereo;
	int32_t m_vol_comp_btsc_mono;
	uint32_t m_btsc_pilot_threshold_high;
	uint32_t m_btsc_pilot_threshold_low;
	uint32_t m_btsc_sap_threshold_high;
	uint32_t m_btsc_sap_threshold_low;
	uint32_t m_btsc_sap_noise_threshold_high;
	uint32_t m_btsc_sap_noise_threshold_low;
	/* other systems */
	int32_t	m_vol_comp_mn_dual;
	int32_t	m_vol_comp_mn_stereo;
	int32_t	m_vol_comp_mn_mono;
} ATV_CFG;

typedef struct {
	int32_t SIF_4p5;
	int32_t SIF_4p28;
	int32_t SIF_4p72;
	int32_t SIF_5p5;
	int32_t SIF_5p25;
	int32_t SIF_5p74;
	int32_t SIF_5p85;
	int32_t SIF_6p0;
	int32_t SIF_6p25;
	int32_t SIF_6p5;
	int32_t SIF_6p552;
	int32_t SIF_6p74;
} ATV_SIF_TONE_T;

typedef enum {
	/* identical to the order in register's field */
	ATV_SUB_3_32	= 0x200,	/* 3/32 */
	ATV_SUB_3_64	= 0x100,	/* 3/64 */
	ATV_SUB_1_32	= 0x50,		/* 1/32 */
	ATV_SUB_4_64	= 0x400,	/* 4/64 */
	ATV_SUB_5_64	= 0x500,	/* 5/64 */
} ATV_SUB_TONE_RATIO;

/*
 * choose fw/hw scan ratio
 */
typedef enum {
	/* identical to the order in register's field */
	ATV_FW_SCAN_FW_ONLY	= 0x0,	/* fw scan only */
	ATV_FW_SCAN_FW_2_HW_1	= 0x1,	/* 1 hw_scan between two fw_scan */
	ATV_FW_SCAN_FW_2_HW_2	= 0x2,	/* 2 hw_scan between two fw_scan */
	ATV_FW_SCAN_FW_2_HW_3	= 0x3,	/* 3 hw_scan between two fw_scan */
	ATV_FW_SCAN_FW_2_HW_4	= 0x4,	/* 4 hw_scan between two fw_scan */
	ATV_FW_SCAN_FW_2_HW_5	= 0x5,	/* 5 hw_scan between two fw_scan */
	ATV_FW_SCAN_FW_2_HW_6	= 0x6,	/* 6 hw_scan between two fw_scan */
	ATV_FW_SCAN_HW_ONLY	= 0x7,	/* hw_scan only */
} ATV_FW_SCAN_FREQ;

/*
 * sif dvc status
 */
typedef enum {
	ATV_HW_IDLE_STATE			= 0x0,
	ATV_HW_FADE_OUT_STATE		= 0x1,
	ATV_HW_FADE_IN_STATE			= 0x2,
	ATV_HW_FADE_OUT_DONE_STATE	= 0x3,
	ATV_HW_UNKNOW_STATE		= 0x4,
} ATV_HW_SIF_DVC_STATE;

/* 
 * Add for ATV Mute selection for PB or TS path
 */
typedef enum {
	/* identical to the order in register's field */
	ATV_PATH_IS_PB		= 0x1,
	ATV_PATH_IS_TS		= 0x2,
	ATV_PATH_IS_PB_TS	= 0x3
} ATV_PATH_PB_TS;

/* 
 * Force not mute for ATV related action 
 * (Set sound std/sound select/no signal...)
 */
typedef enum {
	/* identical to the order in register's field */
	ATVFORCENOTMUTE_IS_PB		= 0x1,
	ATVFORCENOTMUTE_IS_TS		= 0x2,
	ATVFORCENOTMUTE_IS_PB_TS	= 0x3,
	ATVFORCENOTMUTE_IS_NONE		= 0x4
} ATVFORCENOTMUTE_PB_TS;

/* 
 * Supply the audio carrier shift value
 */
typedef enum {
	/* identical to the order in register's field */
	ATV_CARRIER_SHIFT_VALUE_NO_SHIFT	= 0x0,	/* Carrier no shift or over detecting range. */
	ATV_CARRIER_SHIFT_VALUE_MINUS_50K	= 0x1,	/* Carrier shift -50kHz */
	ATV_CARRIER_SHIFT_VALUE_PLUS_50K	= 0x2,	/* Carrier shift +50kHz */
	ATV_CARRIER_SHIFT_VALUE_MINUS_100K	= 0x3,	/* Carrier shift -100kHz */
	ATV_CARRIER_SHIFT_VALUE_PLUS_100K	= 0x4,	/* Carrier shift +100kHz */
	ATV_CARRIER_SHIFT_VALUE_MINUS_150K	= 0x5,	/* Carrier shift -150kHz */
	ATV_CARRIER_SHIFT_VALUE_PLUS_150K	= 0x6,	/* Carrier shift +150kHz */
	ATV_CARRIER_SHIFT_VALUE_MINUS_200K	= 0x7,	/* Carrier shift -200kHz */
	ATV_CARRIER_SHIFT_VALUE_PLUS_200K	= 0x8,	/* Carrier shift +200kHz */
	ATV_CARRIER_SHIFT_VALUE_MINUS_250K	= 0x9,	/* Carrier shift -250kHz */
	ATV_CARRIER_SHIFT_VALUE_PLUS_250K	= 0xA,	/* Carrier shift +250kHz */
	ATV_CARRIER_SHIFT_VALUE_MINUS_300K	= 0xB,	/* Carrier shift -300kHz */
	ATV_CARRIER_SHIFT_VALUE_PLUS_300K	= 0xC 	/* Carrier shift +300kHz */
} ATV_CARRIER_SHIFT_VALUE;

/* 
 * Supply the audio carrier deviation value
 */
typedef enum {
	/* identical to the order in register's field */
	ATV_CARRIER_DEVIATION_50K	= 0x1,	/* Carrier deviation +/-50kHz */
	ATV_CARRIER_DEVIATION_100K	= 0x2,	/* Carrier deviation +/-100kHz */
	ATV_CARRIER_DEVIATION_150K	= 0x3,	/* Carrier deviation +/-150kHz */
	ATV_CARRIER_DEVIATION_200K	= 0x4,	/* Carrier deviation +/-200kHz */
	ATV_CARRIER_DEVIATION_250K	= 0x5,	/* Carrier deviation +/-250kHz */
	ATV_CARRIER_DEVIATION_300K	= 0x6,	/* Carrier deviation +/-300kHz */
} ATV_CARRIER_DEVIATION;

typedef enum {
	BANDWIDTH_HDV0_120KHZ = 0,
	BANDWIDTH_HDV0_170KHZ,
	BANDWIDTH_HDV0_240KHZ,
	BANDWIDTH_HDV0_370KHZ,
	BANDWIDTH_HDV1_240KHZ,
	BANDWIDTH_HDV1_340KHZ,
	BANDWIDTH_HDV1_480KHZ,
	BANDWIDTH_HDV1_740KHZ,
} A2_BW_SEL_T;

typedef enum  {
	AUDIO_BP_SEL_BYPASS		= 0,
	AUDIO_BP_SEL_4P300M_4P700M	= 1,
	AUDIO_BP_SEL_3P960M_5P040M	= 2,
	AUDIO_BP_SEL_4P100M_4P900M	= 3,
	AUDIO_BP_SEL_5P300M_6P700M	= 4,
	AUDIO_BP_SEL_5P250M_6P750M	= 5,
	AUDIO_BP_SEL_5P200M_6P800M	= 6,
	AUDIO_BP_SEL_6P300M_6P700M	= 7,
	AUDIO_BP_SEL_6P200M_6P800M	= 8, /* DK */
	AUDIO_BP_SEL_6P100M_6P900M	= 9,
	AUDIO_BP_SEL_4P090M_4P780M	= 10,
	AUDIO_BP_SEL_4P180M_4P780M	= 11,
	AUDIO_BP_SEL_4P210M_4P750M	= 12,
	AUDIO_BP_SEL_5P115M_7P136M	= 16, /* 0x10 */
	AUDIO_BP_SEL_5P120M_7P132M	= 17, /* 0x11 */
	AUDIO_BP_SEL_5P124M_7P127M	= 18, /* 0x12 */
	AUDIO_BP_SEL_5P132M_7P119M	= 19, /* 0x13 */
	AUDIO_BP_SEL_5P170M_7P032M	= 20, /* 0x14 */
	AUDIO_BP_SEL_5P174M_7P027M	= 21, /* 0x15 */
	AUDIO_BP_SEL_5P182M_7P020M	= 22, /* 0x16 BG/I/L */
	AUDIO_BP_SEL_4P000M_5P000M	= 23, /* 0x17 MN */
	AUDIO_BP_SEL_3P800M_5P200M	= 24, /* 0x18 */
	AUDIO_BP_SEL_4P300M_5P300M	= 25,
	AUDIO_BP_SEL_5P300M_7P300M	= 26,
	AUDIO_BP_SEL_HPF_4P300M		= 27,
	AUDIO_BP_SEL_HPF_5P300M		= 28,
} AUDIO_BP_SEL;

typedef enum {
	SIF_FROM_IFDEMOD	= 0x0,
	SIF_FROM_SIF_ADC	= 0x1,
} SIF_INPUT_SOURCE;

/*
 * ATV AUDIO Country Type
 */
typedef enum {
	ATV_AUDIO_SIF_TYPE_NONE		= 0x0000,	/* INIT TYPE : NONE */
	ATV_AUDIO_SIF_ATSC_SELECT	= 0x0001,	/* INIT TYPE : TV Systems for A2 enabled in default ATSC system */
	ATV_AUDIO_SIF_KOREA_A2_SELECT	= 0x0002,	/* INIT TYPE : TV Systems for A2 enabled in Korea A2 system */
	ATV_AUDIO_SIF_BTSC_SELECT	= 0x0004,	/* INIT TYPE : TV Systems for BTSC enabled in ATSC(CO, CF) or DVB(Taiwan) system */
	ATV_AUDIO_SIF_BTSC_BR_SELECT	= 0x0008,	/* INIT TYPE : TV Systems for BTSC enabled in ATSC(Brazil) system */
	ATV_AUDIO_SIF_BTSC_US_SELECT	= 0x0010,	/* INIT TYPE : TV Systems for BTSC enabled in ATSC(US) system */
	ATV_AUDIO_SIF_DVB_SELECT 	= 0x0020,	/* INIT TYPE : TV Systems for EU in default DVB system */
	ATV_AUDIO_SIF_DVB_ID_SELECT	= 0x0040,	/* INIT TYPE : TV Systems for ID(Indonesia) in DVB(PAL B/G) system */
	ATV_AUDIO_SIF_DVB_IN_SELECT	= 0x0080,	/* INIT TYPE : TV Systems for IN(India) in DVB(PAL B) system */
	ATV_AUDIO_SIF_DVB_CN_SELECT	= 0x0100,	/* INIT TYPE : TV Systems for CN(China, Hong Kone) in DVB system */
	ATV_AUDIO_SIF_DVB_AJJA_SELECT	= 0x0200,	/* INIT TYPE : TV Systems for AJ(Asia JooDong), JA(JooAang Asia) in DVB system */
	ATV_AUDIO_SIF_TYPE_MAX		= 0x0FFF,	/* INIT TYPE : MAX */
} ATV_AUDIO_SIF_TYPE_T;

typedef  enum {
	ATV_DEV_CHANGE_BY_SOUND_STD,
	ATV_DEV_CHANGE_BY_USER
} ATV_DEV_METHOD;

typedef enum {
	ATV_AREA_GEN,	/* general area */
	ATV_AREA_RMD,
	ATV_AREA_IND,
	ATV_AREA_NUM
} ATV_FIELD_AREA;

typedef enum {
	ATV_AUDIO_BP_SEL_BYPASS		= 0,
	ATV_AUDIO_BP_SEL_4P300M_4P700M	= 1,
	ATV_AUDIO_BP_SEL_3P960M_5P040M	= 2,
	ATV_AUDIO_BP_SEL_4P100M_4P900M	= 3,
	ATV_AUDIO_BP_SEL_5P300M_6P700M	= 4,
	ATV_AUDIO_BP_SEL_5P250M_6P750M	= 5,
	ATV_AUDIO_BP_SEL_5P200M_6P800M	= 6,
	ATV_AUDIO_BP_SEL_6P300M_6P700M	= 7,
	ATV_AUDIO_BP_SEL_6P200M_6P800M	= 8,
	ATV_AUDIO_BP_SEL_6P100M_6P900M	= 9,
	ATV_AUDIO_BP_SEL_4P090M_4P780M	= 10,
	ATV_AUDIO_BP_SEL_4P180M_4P780M	= 11,
	ATV_AUDIO_BP_SEL_4P210M_4P750M	= 12,
	ATV_AUDIO_BP_SEL_5P115M_7P136M	= 16,	/* 0x10 */
	ATV_AUDIO_BP_SEL_5P120M_7P132M	= 17,	/* 0x11 */
	ATV_AUDIO_BP_SEL_5P124M_7P127M	= 18,	/* 0x12 */
	ATV_AUDIO_BP_SEL_5P132M_7P119M	= 19,	/* 0x13 */
	ATV_AUDIO_BP_SEL_5P170M_7P032M	= 20,	/* 0x14 */
	ATV_AUDIO_BP_SEL_5P174M_7P027M	= 21,	/* 0x15 */
	ATV_AUDIO_BP_SEL_5P182M_7P020M	= 22,	/* 0x16 */
	ATV_AUDIO_BP_SEL_4P000M_5P000M	= 23,	/* 0x17 */
	ATV_AUDIO_BP_SEL_3P800M_5P200M	= 24,	/* 0x18 */
	ATV_AUDIO_BP_SEL_4P300M_5P300M	= 25,
	ATV_AUDIO_BP_SEL_5P300M_7P300M	= 26,
	ATV_AUDIO_BP_SEL_HPF_4P300M	= 27,
	ATV_AUDIO_BP_SEL_HPF_5P300M	= 28,
} ATV_AUDIO_BP_SEL;

typedef enum {
	ATV_AUDIO_UPSAMPLE_LP_SEL_BYPASS	= 0,
	ATV_AUDIO_UPSAMPLE_LP_SEL_PAL		= 2,
} ATV_AUDIO_UPSAMPLE_LP_SEL;

typedef struct {
	uint16_t a1;
	uint16_t a2;
	uint16_t h0;
} ATV_SIF_EQ_COEF;

typedef struct {
	uint16_t ATV_SIF_EQ_BAND_ENABLE;
	ATV_SIF_EQ_COEF	coef[ATV_SIF_EQ_BAND_NUM];	/* 3 bands */
} ATV_SIF_EQ_48K_CFG;

typedef void (*FP_AUDIOSTATUSCHANGE)(ATV_STATUS_CHANGE status);

enum ENUM_AUDIO_IPT_SRC {
	AUDIO_IPT_SRC_ATV = 0x0,
	AUDIO_IPT_SRC_BBADC = 0x1,
	AUDIO_IPT_SRC_SPDIF = 0x2,
	AUDIO_IPT_SRC_BIT_3 = 0x3,
	AUDIO_IPT_SRC_I2S_PRI_CH12 = 0x4,
	AUDIO_IPT_SRC_I2S_PRI_CH34 = 0x5,
	AUDIO_IPT_SRC_I2S_PRI_CH56 = 0x6,
	AUDIO_IPT_SRC_I2S_PRI_CH78 = 0x7,
	AUDIO_IPT_SRC_I2S_SEC_CH12 = 0x8,
	AUDIO_IPT_SRC_ATV_NICAM = 0x9,
	AUDIO_IPT_SRC_ATV_HDEV = 0xa,
	AUDIO_IPT_SRC_DTV = 0x10,
	AUDIO_IPT_SRC_FILE = 0x20,
	AUDIO_IPT_SRC_UNKNOWN = 0xFF,
};

typedef enum{
	AUDIO_ATV_FM_RADIO_STOP = 0,
	AUDIO_ATV_FM_RADIO_SCAN,
	AUDIO_ATV_FM_RADIO_PLAY,
} AUDIO_ATV_FM_RADIO_MODE;

typedef enum ENUM_AUDIO_IPT_SRC ENUM_AUDIO_IPT_SRC;

void Audio_AtvEnableAutoChangeStdFlag(int enable);

/**
 * Select ATV Sound Standard
 *
 * @param <main_system>	{ ATV_SOUND_XXX_SYSTEM , refer to audio_atv.h, to limit valid std at auto detect case }
 * @param <sound_std>	{ ATV_SOUND_STD_XXX , refer to audio_atv.h }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvSetSoundStd(ATV_SOUND_STD_MAIN_SYSTEM main_system, ATV_SOUND_STD sound_std);

/**
 * Select ATV play channel
 * this function only affect the data into post-processing,
 * it cannot control the ATV audio decoder.
 *
 * @param <sound_sel>	{ ATV_PLAY_CH_SEL_XXX , refer to audio_atv.h }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvSetPlayChannel(ATV_PLAY_CH_SEL l_sel, ATV_PLAY_CH_SEL r_sel);

/**
 * Select ATV Sound/Language
 *
 * @param <sound_sel>	{ ATV_SOUND_SEL_XXX , refer to audio_atv.h }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvSetSoundSelect(ATV_SOUND_SEL sound_sel);

/**
 * Get ATV BTSC Sound/Language Select(last S/W backup)
 *
 * @param <p_mts_sel>	{ ATV_BTSC_MTS_SEL_XXX , refer to audio_atv.h }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvGetBtscMtsSelect(uint32_t *p_mts_sel);

/** Select ATV Sound Mode 
 *
 * @param <sound_mode>	{ ATV_SOUND_MODE_XXX , refer to audio_atv.h }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvSetSoundMode(ATV_SOUND_MODE sound_mode);

/**
 * Get ATV Sound Mode
 *
 * @param <p_sound_mode>	{ ATV_SOUND_MODE_XXX , refer to audio_atv.h }
 * @return			{ void }
 * @ingroup lib_audio
 */
int32_t Audio_AtvGetSoundMode(uint32_t *p_sound_mode);

/**
 * Select ATV MTS Priority
 *
 * @param <mts_prio>	{ ATV_MTS_PRIO_XXX , refer to audio_atv.h }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvSetMtsPriority(ATV_MTS_PRIORITY mts_prio);

/**
 * Query current ATV Sound Standard
 *
 * @param <p_sound_std>	{ current Sound Standard }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvGetSoundStd(ATV_SOUND_INFO *p_sound_info);

/**
 * Scan/Find current ATV Sound Standard
 *
 * @param <p_sound_std>	{ result of scanning }
 * @prarm <flag>	{ options for scanning }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvScanSoundStd(ATV_SOUND_STD *p_sound_std, uint32_t flag);

/** 
 * Add new API for RF radio auto scan Audio tone is always fixed
 * at 4.5MHz
 */
int32_t Audio_AtvScanSoundStd_FMRadio(ATV_SOUND_STD *p_sound_std, ATV_Carrier_INFO *p_ATV_Carrier_INFO);

void Audio_AtvSetArea(ATV_FIELD_AREA area);

/**
 * select IF-ADC data source
 *
 * @param <para>	{ ATV_DATA_SRC_IFD/ATV_DATA_SRC_SIF }
 * @return		{ void }
 * @ingroup drv_aio
 */
void Audio_AtvSetDataSrc(ATV_DATA_SRC para);

/**
 * get M/N standard status
 *
 * @param <p_status>	{ result of M/N standard status}
 * @param <p_energy>	{ result of M/N standard energy}
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvGetMNStatus(int32_t *p_status, int32_t *p_energy);

/**
 * Enable/Disable F/W Scanning
 * This function can suspend/resume F/W scanning when FREQ_SHIFT is enabled.
 * When calling Audio_AtvSetSoundStd, F/W Scaning is enabled automatically.
 *
 * @param <para>	{ AIO_ENABLE/AIO_DISABLE }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvSetFwScanCarrierFreqOffset(uint32_t para);

/**
 * Init. LasVegas ATV Audio
 *
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvInit(ATV_CFG *p_cfg);

/**
 * DeInit. LasVegas ATV Audio
 *
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvDeInit(void);

/**
 * prepare to enter auto scan status
 * 
 * @ingroup lib_audio
 */
void Audio_AtvEnterAutoScan(void);

/**
 * finish auto scan status
 * 
 * @ingroup lib_audio
 */
void Audio_AtvExitAutoScan(void);

/**
 * clean TV use internel data
 * 
 * @ingroup lib_audio
 */
void Audio_AtvCleanTVSourceData(void);

/**
 * check if audio set new std is finish
 * 
 * @return	{ 1 or 0 }
 * @ingroup lib_audio
 */
uint32_t Audio_AtvIsTvReady(void);

void Audio_AtvStartDecoding(void);

void Audio_AtvStopDecoding(void);

/**
 * prepare to enter atv source
 * 
 * @ingroup lib_audio
 */
void Audio_AtvEnterAtvSource(void);

/**
 * Get ATV A2 Sound/Language Select(last S/W backup)
 *
 * @param <p_mts_sel>	{ ATV_A2_SEL_XXX , refer to audio_atv.h }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvGetA2SoundSelect(ATV_A2_SEL *p_sel);

/**
 * Get ATV Nicam Sound/Language Select(last S/W backup)
 *
 * @param <p_mts_sel>	{ ATV_A2_XXX , refer to audio_atv.h }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AtvGetNicamSoundSelect(ATV_NICAM_SEL *p_sel);

ATV_SOUND_STD_MAIN_SYSTEM Audio_AtvGetDetectMainSystem(void);

/**
 * enable / disable print sw freq scan
 * 
 * @return
 * @ingroup lib_audio
 */
void Audio_AtvEnablePrintSWScan(uint32_t isEnable);

void Audio_AtvEnableTVPrint(uint32_t isEnable);

/**
 * enable / disable auto change std to mono system for China style
 * 
 * @return
 * @ingroup lib_audio
 */
void Audio_AtvAutoChange2Mono(int enable);

/**
 *  change std to mono system for China style
 * 
 * @return
 * @ingroup lib_audio
 */
ATV_SOUND_STD Audio_AtvConvert2MonoStd(ATV_SOUND_STD std);

/**
 *   ifd finish init flag
 * 
 * @return
 * @ingroup lib_audio
 */
void Audio_AtvIFDInitFinish(void);

void Audio_AtvResetIFDInitFlag(void);

/**
 *   change ifd finish  flag
 * 
 * @return
 * @ingroup lib_audio
 */
void Audio_AtvResetIFDInitFlag(void);

/**
 * change auto scan flag 
 *
 * @return
 * @ingroup lib_audio
 */
void Audio_AtvSetLowTresholdFlag(int isEnable);

/**
 * paues atv tv standard auto detection
 * 
 * @param is_pause If treu, pause the detection. Otherwise, 
 *                 restore to the old state of detection
 *                 process.
 * @return 
 * @ingroup lib_audio
 */
void Audio_AtvPauseTVStdDetection(bool is_pause);
int Audio_AtvGetModeMute(void);
int Audio_AtvSetInternalDecoder0Fail(int is_mute);
int Audio_AtvSetInternalDecoder1Fail(int is_mute);

void Audio_AtvSetAudioInHandle(long instanceID);
void Audio_AtvSetSubAudioInHandle(long instanceID);

void Audio_AtvSetTVFlag(uint32_t mask, uint32_t newSetting);

void Audio_AtvStart2NormalProcessSoundMode(int isEnable);

void Audio_AtvForceFirstTimeMonoSoundFlag(int isEnable);

void Audio_AtvForceSoundSel(bool flag);

void Audio_AtvNicamAutoRecoveryFlag(int isEnable);

void Audio_AtvEnableAutoChangeSoundModeFlag(int isEnable);

void Audio_AtvChangeTvDeviationConfig(uint32_t setting);

void Audio_AtvSetBTSCSoundSelect(uint32_t isPreferPlayStereo, uint32_t  isPreferPlaySap);

void Audio_AtvSetA2SoundSelect(uint32_t isPreferPlayStereo, uint32_t  preferDualLangIndex);

void Audio_AtvSetNICAMSoundSelect(uint32_t isPreferNicamDigital, uint32_t  preferDualLangIndex);

void Audio_AtvStatusChageCallBackfnConfig(FP_AUDIOSTATUSCHANGE f_ptr);

void Audio_AtvStart2NormalProcess(void);

void Audio_AtvSetNicamErrorRateThreshold(int Upperbound, int Lowbound);

void Audio_AtvSetNicamErrorRateDebounce(int MaxDebounce);

int Audio_AtvGetNicamSignalStable(void);

void Audio_AtvSetDeviationMethod(ATV_DEV_METHOD dev_method);

void Audio_AtvSetDevBandWidth(A2_BW_SEL_T bw_sel, A2_BW_SEL_T sub_bw_sel);

void Audio_AtvSetFMoutDownGain(int para);

void Audio_AtvSetAMoutDownGain(int para);

void Audio_AtvSetAMWideBW(int para);

void Audio_AtvSetHWMute(int32_t para, uint32_t ch_id);

void  Audio_AtvEnterSetChannel(void);

void  Audio_AtvFinishSetChannel(void);

void  Audio_AtvConfigNoSignalNeed2Mute(uint32_t isNeed2Mute);

void Audio_AtvSetBTSCSoundChangeDebounce(int SOUNDCHANGEMAX, int SOUNDCHANGEMIN);

void Audio_AtvChangebtscpilotphasedelta(ATV_PILOT_PHASE_DELTA data);

/* add to change sub tone ratio */
void Audio_AtvChangeTvSubRatio(ATV_SUB_TONE_RATIO ratio);

void Audio_AtvPathIs(ATV_PATH_PB_TS atvpath);

void Audio_AtvForceNotmute(ATVFORCENOTMUTE_PB_TS atvforcenotmute);

uint32_t AtvIsNicamSystem(ATV_SOUND_STD std);

void AtvGetNicamHhwSoundMode(ATV_SOUND_MODE *p_sound_info);

uint32_t AtvIsBTSCSystem(ATV_SOUND_STD std);

void AtvGetHwBtscsSoundMode(ATV_SOUND_MODE *p_sound_info);

uint32_t AtvIsA2System(ATV_SOUND_STD std);

void AtvGetA2HwSoundMode(ATV_SOUND_MODE *p_sound_info, bool check_pilot);

void Audio_AtvSetSoundSystem(DRV_ATV_SOUND_SYSTEM AtvAudioSoundSystem);

ATV_SOUND_STD_MAIN_SYSTEM Audio_AtvGetSoundSystem(void);

void Audio_HwpSetSIFDataSource(SIF_INPUT_SOURCE sif_input_source);

void Audio_HwpSIFSetA2StereoDualTH(uint32_t a2_th);

void Audio_HwpSIFGetA2StereoDualTH(uint32_t *a2_th);

void Audio_HwpSIFSetNicamTH(uint8_t hi_th, uint8_t lo_th);

void Audio_HwpSIFGetNicamTH(uint8_t *hi_th, uint8_t *lo_th);

void Audio_HwpSIFGetMainToneMag(ATV_SOUND_STD_MAIN_SYSTEM main_sys, int32_t *pToneMag);

int32_t Audio_HwpSIFGetMainToneSNR(ATV_SOUND_STD_MAIN_SYSTEM main_sys, ATV_SOUND_STD_MAIN_SYSTEM *p_hw_detected_main_sys, ATV_SOUND_STD *p_hw_detected_sound_std, uint32_t *pToneSNR);

void Audio_HwpSIFGetA2DKSubToneMag(ATV_SOUND_STD soundstd, int32_t *pToneMag);

void Audio_HwpSIFCheckNicamDigital(int *exist_flag);

void Audio_HwpSIFDetectedSoundSystem(ATV_SOUND_STD_MAIN_SYSTEM *detected_main_sys);

void Audio_HwpSIFDetectedSoundStandard(ATV_SOUND_STD *detected_sound_std);

void Audio_HwpSIFEnableMutePB(bool Mute_en);

void Audio_HwpSIFEnableMuteTS(bool Mute_en);

int32_t Audio_HwpAADSIFInit(ATV_CFG *p_cfg);

int32_t Audio_HwpAADSIFFinalize(void);

int32_t Audio_HwpSetAtvAudioBand(SIF_INPUT_SOURCE sif_source, ATV_SOUND_STD_MAIN_SYSTEM atv_main_system);

/* Add for Debug Menu, Get Hw setting */
void Audio_HwpSIFGetSource(SIF_INPUT_SOURCE *sif_source);

void Audio_HwpSIFGetDevBandwidth(A2_BW_SEL_T  *deviation_bw);

void Audio_HwpSIFGetBandSetup(uint32_t *bp_sel);

void Audio_HwpSIFGetModeSetup(ATV_SOUND_STD *sound_std);

void Audio_HwpSetChannelChange(void);		/* for external demo */

void Audio_HwpSetBandDelay(void);

void Audio_HwpCurSifType(ATV_AUDIO_SIF_TYPE_T eSifType);

void Audio_HwpSetDecoderInputMute(bool bOnOff);

void Audio_AtvSetDevOnOff(bool bOnOff);

typedef bool (*pfnMuteHandling)(bool IsMute);

void Audio_PrintSemBacktrace(void);

void Audio_AtvRegMuteCallback(int decindex, pfnMuteHandling pfnCallBack);

void Audio_AtvTaskSemPost(const char *msg);

void Audio_AtvTaskSemWait(const char *msg);

void audio_ifd_set_audio_bp(ATV_AUDIO_BP_SEL audio_bp_sel);

uint8_t audio_ifd_get_audio_bp_info(void);

void audio_ifd_audio_gain_en(bool enable);

bool audio_ifd_audio_gain_en_get_info(void);

void audio_ifd_audio_gain_manual(uint16_t gain);

uint16_t audio_ifd_audio_gain_manual_get_info(void);

uint16_t audio_ifd_audio_gain_status(void);

void audio_ifd_audio_output_div2(bool enable);

void Audio_HwpSetVolume_SIF(int32_t vol);

int audio_drv_set_sif_eq_coef_48K(ATV_SIF_EQ_48K_CFG *p_eq_cfg);

int32_t Audio_HwpSetSIFEQCoef_48K(ATV_SIF_EQ_48K_CFG *p_cfg_eq);

int32_t Audio_HwpSetSIFEQValue_48K(ATV_SIF_EQ_48K_CFG *p_val_eq);

uint32_t isSIFEQOverflow(void);

void CleanSIFEQOverflow(void);

void AIO_WriteMask(uint32_t address, uint32_t val);

int32_t AUDIO_SIF_SetBandSetup(ATV_AUDIO_SIF_TYPE_T eSifType, ATV_SOUND_STD_MAIN_SYSTEM sifBand);

int32_t Audio_AtvGetCurrentDetectUpdate(int *isComplete);

int32_t Audio_SetAudioHWConfig(int32_t config);

void audio_sif_adc_initial_flow(void);

void Audio_Hw_SetFmRadioMode(AUDIO_ATV_FM_RADIO_MODE Enable);
AUDIO_ATV_FM_RADIO_MODE ATV_GetFmRadioMode(void);

void Audio_Auto_Verify_Set_Path(void);

void Audio_Hw_Set_Scan_Std_Flag(bool Flag);
bool ATV_Get_Scan_Std_Flag(void);
void Audio_AtvSetFwPriority(uint16_t Priority);
uint16_t AtvGetFwPriority(void);

#endif
