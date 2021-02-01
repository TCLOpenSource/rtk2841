/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * This file contains platform-related defines for Realtek boards.
 *
 * Copyright (C) 2010 by Chien-An Lin <colin@realtek.com.tw>
 */


#ifndef _MACH_PLATFORM_H
#define _MACH_PLATFORM_H

//#define CONFIG_REALTEK_SHOW_STACK

#define AES_CCMP_LEN		571
#define SYSTEM_PARAMETERS_LEN	960 // 1~6
#define MMC_PARAM_LEN	700
#define MODEL_CONFIG_LEN	64	// Originally this value is 20 for libra 10bytes config and now we support 32byes for customer extra use
#define SIGNATURE_LEN		129
#define AES_IMG_KEY_LEN		16
#define RSA_KEY_MODULUS_LEN	128
#define _PRIV_LEN		1024
#define _CUSTOM_PARAM_LEN	4096
#if defined(CONFIG_REALTEK_PCBMGR)
 #ifdef CONFIG_CUSTOMER_TV010
   #define PANEL_PARAMETER_LEN     256 //for TV010
 #elif defined(CONFIG_CUSTOMER_TV030)
   #define PANEL_PARAMETER_LEN     150
 #else
#define PANEL_PARAMETER_LEN     129
 #endif
#define PCB_ENUM_PARAMETER_LEN  5120
#define PCB_ENUM_PARAMETER_LEVEL  50
#endif

// for tv006 : debugMode
#define DEBUG_LEVEL 3
#define EVENT_LEVEL 4
#define RELEASE_LEVEL 5

typedef struct {
	int mode;		// 0: NTSC, 1: PAL
	int size;
	int color[4];
} logo_info_struct;

/* The format of "bootrev" is like "0001.0203.4567". The second two bytes of it stands for board id, and the upper half byte of board id stands for CPU id */
typedef enum {
	realtek_299x_qa_board				= 0x000700,
	realtek_299x_demo_ab_board			= 0x000701,
	realtek_299x_demo_c_4ddr_1g_board	= 0x000702,
	realtek_299x_demo_c_4ddr_2g_board	= 0x000703,
	realtek_299x_demo_d_4ddr_2g_board	= 0x000704,
	realtek_299x_demo_e_2ddr_512m_board	= 0x000705,
	C10_2995_v1_board					= 0x100700,
	C05_2993_l4300_board				= 0x050700,
	realtek_294x_demo_board				= 0x000900,
#if 0
	realtek_mk_board		=0x1,
	realtek_1261_demo_board		=0x2,		/* first demo board */
	realtek_1281_demo_board		=0x4,		/* little blue */
	realtek_mk2_board		=0x5,		/* little white */
	realtek_photoviewer_board	=0x7,
	realtek_avhdd_demo_board	=0x8,		/* little yellow */
	realtek_pvr_demo_board		=0x9,
	realtek_pvrbox_demo_board	=0xA,
	realtek_avhdd2_demo_board	=0xB,		/* little yellow 2 */
	realtek_pvrbox_pc_demo_board	=0xC,		/* little yellow 2 with PC install */
	realtek_1071_avhdd_mk_demo_board	=0xD,	/* 1071 AVHDD MK Demo Board */
	realtek_1261_avhdd_hdd25_demo_board	=0xE,	/* 1261 2.5" AVHDD Demo Board */
	realtek_neptune_qa_board	=0x0101,
	realtek_neptuneB_qa_board	=0x1101,
	realtek_neptune_demo_board	=0x0102,
	realtek_neptuneB_demo_board	=0x1102,
	realtek_1282_neptuneB_qa_board	=0x1103, /* 1282 Neptune B, QA Board. */
	realtek_1282_neptuneB_demo_board	=0x1104, /* 1282 Neptune B, DEMO board. */
	realtek_1262_neptuneB_pc_install_demo_board	=0x1105, /* 1262 Neptune B, DEMO board with PC install. */
	realtek_1262_neptuneB_mk_board	=0x1106, /* 1262 Neptune B, MK board. */
	realtek_1262_neptuneB_avhdd_ewha10_mk_board	=0x1107, /* 1262 Neptune B, AVHDD Ewha 1.0 MK board. */
	realtek_1283_mars_qa_board	=0x0200, /* 1283 Mars, QA board. */
	C01_avhdd_board			=0x10001,
	C01_1262_avhdd_board		=0x11101, /* 1262 Neptune AVHDD Board. */
	C01_photoviewer_board		=0x10007,
	C02_avhdd_board			=0x20008,
	C02_1262_Neptune_avhdd_board	=0x21101,
	C03_pvr_8m_board		=0x30001,
	C03_pvr_board			=0x30009,
	C03_pvr2_board			=0x3000B,
	C04_pvr_board			=0x40009,
	C04_pvr2_board			=0x4000B,
	C05_pvrbox_board		=0x5000A,
	C05_pvrbox2_board		=0x50001,
	C06_pvr_board			=0x60009,
	C07_avhdd_board			=0x70001, //AVHDD with J-Micron SATA.
	C07_pvrbox_board		=0x7000a, //PVR-BOX with PC Install.
	C07_pvrbox2_board		=0x7000b, //PVR-BOX without PC Install.
	C08_pvr_board			=0x80009,
	C09_pvrbox_board		=0x90001,
	C09_pvrbox2_board		=0x90002,
	C0A_pvr_board			=0xa0001, //2MB NOR and 128MB+ NAND.Behavior is the same with C0003.B000b
	C0B_dvr_board			=0xb1101, //Neptune 1282 DVR Demo Board.
	C0C_avhdd_board			=0xc0001,
	C0D_pvr_board			=0xd0001,	//8 MB PVR Module.
	C0E_dvr_board			=0xe0001,	//1281 2MB DVR (little blue).
	C0F_1061_avhdd_hdd35_board	=0xf0001,	//1061 AVHDD with 3.5" HDD.
	C0F_1061_avhdd_board		=0xf0002,	//1061 AVHDD without HDD.
	C0F_1262_avhdd_hdd35_board	=0xf1101,	//1262 AVHDD with 3.5" HDD.
	C0F_1262_avhdd_hdd25_board	=0xf1102,	//1262 AVHDD with 2.5" HDD.
	C10_1071_avhdd_board		=0x100001,	//1071 AVHDD
#endif
} board_id_t;

/* The format of "bootrev" is like "0001.0203.4567". The first two byte of it stands for company id */
typedef enum {
	company_realtek	= 0x00,
	company_alpha	= 0x01,
	company_C02		= 0x02,
	company_C03		= 0x03,
	company_C04		= 0x04,
	company_C05		= 0x05,
	company_C06		= 0x06,
	company_C07		= 0x07,
	company_C08		= 0x08,
	company_C09		= 0x09,
	/* skip 0x0a ~ 0x0f */
	company_C10		= 0x10,
	company_C11 	= 0x11,
	company_C12 	= 0x12,
	company_C13 	= 0x13,
	company_C14 	= 0x14,
	company_C15 	= 0x15,
	company_C16 	= 0x16,
	company_C17 	= 0x17,
	company_C18 	= 0x18,
	company_C19 	= 0x19,
	/* skip 0x1a ~ 0x1f */
	company_C20 	= 0x20,
} company_id_t;

/* Defines of CPU ID */
typedef enum {
	realtek_299x_cpu	= 0x07,
	realtek_298x_cpu	= 0x08,
	realtek_294x_cpu	= 0x09,
} cpu_id_t;

typedef enum {
	PAL,
	NTSC,
} tv_encoding_system_t;

typedef struct {
	board_id_t		board_id;
	company_id_t	company_id;
	cpu_id_t		cpu_id;
	char			kernel_source_code_info[64];
	char			bootloader_version[32];
	char			ethaddr[20];			/* Ethernet Mac address */
	int				ethtype;			/* Ethernet type. 0 for 100M; 1 for 1G */
	char			usb_param[20];			/* USB parameter */
	char			usb1_param[20];			/* USB parameter */
	char			usb2_param[20];			/* USB parameter */
	unsigned char	AES_CCMP[AES_CCMP_LEN];		/* maximum size 113. The last one may be '\0' */
	int				AES_CCMP_len;			/* The stored length of the binary data in AES_CCMP[] */
#if defined(CONFIG_REALTEK_PCBMGR)
	unsigned char	panel_parameter[PANEL_PARAMETER_LEN];		/* maximum size 113. The last one may be '\0' */
	int				panel_parameter_len;			/* The stored length of the binary data in AES_CCMP[] */
	char			pcb_enum_parameter[PCB_ENUM_PARAMETER_LEN];
	int				pcb_enum_parameter_len;
	char			pcb_st_enum_parameter[PCB_ENUM_PARAMETER_LEN];
	int				pcb_st_enum_parameter_len;
#endif
	int				update_mode;
	char			system_parameters[SYSTEM_PARAMETERS_LEN];
	char			mmc_param[MMC_PARAM_LEN];
	tv_encoding_system_t	tv_encoding_system;
	char			signature[SIGNATURE_LEN];
	unsigned char	modelconfig[MODEL_CONFIG_LEN];
	int				modelconfig_len;
	int				secure_boot;
	char			AES_IMG_KEY[AES_IMG_KEY_LEN];
	char			RSA_KEY_MODULUS[RSA_KEY_MODULUS_LEN];
	char			_priv_[_PRIV_LEN];
	char			_custom_param_[_CUSTOM_PARAM_LEN];
	unsigned short	rtc_base_date_year;	/* The base year of RTC passed from bootloader. The default is 2005 */
#ifdef CONFIG_REALTEK_POWER_CUT
	int   power_cut_load;
#endif
    int   enable_dvs;
#ifdef CONFIG_REALTEK_SCHED_LOG
	/* schedule log in kernel */
	int    sched_log_time_duration; //default 10s, use timer to stop log, set it will trigger log start and stop
	int   sched_log_file_start; // cat it will start to log file
	int   sched_log_file_stop;
	int   sched_log_size; //default 6M
	short  sched_log_event_number;
	char  sched_log_name[120]; //default /tmp/usb/sda/sda1
#endif
	int   apk_boost_mode; // For the apk boost mode.
        char  androidboot[20];
} platform_info_t;

extern platform_info_t platform_info;
extern int *_prom_envp;

extern void prom_init(void);

//check apk boost mode scpu frq level.
int platform_get_dvfs(void);
int is_platform_reset_freq(void);
void clear_platform_reset_freq(void);
//check apk boost mode scpu frq level.


#define VERSION_A			0
#define VERSION_B			1
#define VERSION_C			2
unsigned int get_ic_version(void);

// Return the revision number of Venus/Neptune/Mars/Jupiter... CPUs
static inline int cpu_rev_num(void) {
	return (platform_info.cpu_id&0xf0)>>4;
}

int is_platform_KXLP(void);
int platform_get_dvfs(void); /* 2 or 4 DVFS set setting from boot code */
int is_platform_dvs_enable(void); /* true will set dvs automatically */
typedef enum {
	bcasON,
	bcasOFF,
	bcasUNKNOWN
} bcas_info_t;
#endif /* !(_MACH_PLATFORM_H) */


