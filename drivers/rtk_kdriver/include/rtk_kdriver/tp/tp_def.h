#ifndef __TP_DEF_H__
#define __TP_DEF_H__

#include <mach/io.h>
#include <base_types.h>
/*****************************************

      this define file is for tp

******************************************/

#define CAM_SRC_CHANGE_BASE_ON_TP_INPUT_COUNT

#define CHIP_VERSION                              RTD284X_TP

//#define TP_VERIFY_ENABLE

/* define for chip index */
#define RTD294X_TP                                1
#define RTD294X_TP_PLUS                           2
#define RTD299S_TP                                3
#define RTD299O_TP                                4
#define RTD289X_TP                                5
#define RTD284X_TP                                6

/* TP function count */
#define MAX_TPOUT_COUNT                           1
#define MAX_TP_BUFFER_COUNT                       32
#define MAX_TPP_BUFFER_COUNT                      3
#define MAX_PID_FILTER_COUNT                      96
#define MAX_SEC_COUNT                             130
#define MAX_KEY_COUNT                             16    /* actually is 16, it is more save to limit to 12 */
#define MAX_TS_COUNT                              4

#define TP_SPEED_MHZ            250

/* TP mudule support */
#define MAX_TPOUT_MODULE_SUPPORT                  MAX_TPOUT_COUNT
#define MAX_MTP_MODULE_SUPPORT                    MAX_MTP_COUNT
#define MAX_TP_MODULE_SUPPORT                     (MAX_TP_COUNT + MAX_TP_P_COUNT)

/* max pid filter of each TP engine */
#define MAX_PID_PER_TP                            32 /* depend on pid filter count */
#define MAX_SEC_PER_TP                            128
#define MAX_SEC                                   512
#define MAX_FILE_HANDLE_REC                       32
#define MAX_SEC_PER_PID                           64

#define MAX_TPOUT_REMUX_COUNT                     8

/* Used Buffer size define */
#define TP_INFO_PACK_BUFFER_SIZE                  (2048 * 8) // 16KB
#define SECTION_BUFFER_SIZE                       (4096)
//#define TP_START_CODE_PACK_BUFFER_SIZE            (4096 * 8)

/* TP0 buffer index define */
#define TP0_BUFFER_MASS_DATA                      0
#define TP0_BUFFER_INFO_PACK                      1
#define TP0_BUFFER_SECTION_DATA                   0
#define TP0_START_CODE_PACK                       10
/* TP1 buffer index define */
#define TP1_BUFFER_MASS_DATA                      3
#define TP1_BUFFER_INFO_PACK                      4
#define TP1_BUFFER_SECTION_DATA                   3
#define TP1_START_CODE_PACK                       5
/* TP2 buffer index define */
#define TP2_BUFFER_MASS_DATA                      6
#define TP2_BUFFER_INFO_PACK                      7
#define TP2_BUFFER_SECTION_DATA                   6
/* TP3 buffer index define */
#define TP3_BUFFER_MASS_DATA                      8
#define TP3_BUFFER_INFO_PACK                      9
#define TP3_BUFFER_SECTION_DATA                   8

#define MAX_USED_BUFFER_CONNECT                   8
#define TP_BUFFER_MAX_COUNT                       10  /* depend on max of tp0~3's buffer */

#define  TPP_BUFFER_MAX_COUNT                     3

/* pid filter count of each TP engine */
#ifdef TP_VERIFY_ENABLE
#define TP0_PID_FILTER_COUNT                     24
#define TP1_PID_FILTER_COUNT                     24
#define TP2_PID_FILTER_COUNT                     24
#define TP3_PID_FILTER_COUNT                     24
#else
#define TP0_PID_FILTER_COUNT                      32 //31 //33//(MAX_PID_FILTER_COUNT/3)
#define TP1_PID_FILTER_COUNT                      32 //31 //33//(MAX_PID_FILTER_COUNT/3)
#define TP2_PID_FILTER_COUNT                      31 //2 //30//(MAX_PID_FILTER_COUNT/3)
#define TP3_PID_FILTER_COUNT                      1
#endif

/* first pid filter index of each TP engine */
#define TP0_FIRST_PID_FILTER_IDX                  0
#define TP1_FIRST_PID_FILTER_IDX                  TP0_PID_FILTER_COUNT
#define TP2_FIRST_PID_FILTER_IDX                  (TP1_FIRST_PID_FILTER_IDX + TP1_PID_FILTER_COUNT)
#define TP3_FIRST_PID_FILTER_IDX                  (TP2_FIRST_PID_FILTER_IDX + TP2_PID_FILTER_COUNT)

/* section filter count of each TP engine */
#ifdef TP_VERIFY_ENABLE
#define TP0_SEC_FILTER_COUNT                      32
#define TP1_SEC_FILTER_COUNT                      32
#define TP2_SEC_FILTER_COUNT                      32
#define TP3_SEC_FILTER_COUNT                      34
#else
#define TP0_SEC_FILTER_COUNT                      64
#define TP1_SEC_FILTER_COUNT                      32
#define TP2_SEC_FILTER_COUNT                      32
#define TP3_SEC_FILTER_COUNT                      2  /* for CI+1.4, receive Trust SDT from TP3 */
#endif

#define TP_SEC_DATA9_FILTER_SEL_PATTERN_A         0
#define TP_SEC_DATA9_FILTER_SEL_PATTERN_B         1
#define TP_SEC_DATA9_FILTER_SEL_PATTERN_AB        2

#define TP_INFO_PACK                              _ZERO
#define AF0_INFO_PACK                             (_BIT7)
#define AF1_INFO_PACK                             (_BIT7|_BIT6)
#define SEC_INFO_PACK                             _BIT6

#define SEC_INFO_PACK_SEL                         0xc0

#define TAIL_STATUS_SECTION_TRUNCATED             _BIT3
#define TAIL_STATUS_TOO_SHORT_FOR_CRC_CHECK       _BIT2
#define TAIL_STATUS_CRC_STATUS                    (_BIT2|_BIT3)
#define TAIL_STATUS_CRC_STATUS_NO_ERR                           _ZERO
#define TAIL_STATUS_CRC_STATUS_TOO_SHORT_FOR_CRC_CHECK          _BIT2
#define TAIL_STATUS_CRC_STATUS_CRC_ERR                          _BIT3
#define TAIL_STATUS_CRC_STATUS_SECTION_TRUNCATED                (_BIT2|_BIT3)
#define TAIL_STATUS_TEI_ERR                       _BIT1
#define TAIL_STATUS_END_SEEN                      _BIT0

#define HEADER_STATUS_HEADER_ACROSS_TWO_PACKET    _BIT2
#define HEADER_STATUS_NOT_PASS_SECTION_FILTERING  _BIT1
#define HEADER_STATUS_HEADER_SEEN                 _BIT0

/* descramble control reg */
#define DES_CNTL_OFB_DEFAULT                      0
#define DES_CNTL_OFB_KEEP_CLEAR                   1
#define DES_CNTL_OFB_OFB                          2

#define DES_CNTL_CSA_MODE_ORIGINAL                0
#define DES_CNTL_CSA_MODE_1                       1
#define DES_CNTL_CSA_MODE_2                       2

#define DES_CNTL_MULTI2_ALIGN63                   0
#define DES_CNTL_MULTI2_ALIGN0                    1

#define DES_CNTL_MAP_EVEN                         0
#define DES_CNTL_MAP_ODD                          1

#define DES_CNTL_DESMODE_CBC                      0
#define DES_CNTL_DESMODE_ECB                      1

#define DES_CNTL_MODE_DES                         0
#define DES_CNTL_MODE_TDES                        1
#define DES_CNTL_MODE_CSA                         2
#define DES_CNTL_MODE_MULTI2                      3
#define DES_CNTL_MODE_AES128_CBC                  4
#define DES_CNTL_MODE_AES128_RCBC_CS              5
#define DES_CNTL_MODE_CAM                         7

// move from tp_drv_api.h
/* Structure for TP driver API */
#define TPK_MAX_KEY_LENGTH                        32
#define TPK_MAX_IV_LENGTH                         16  /* maximum value of aes_128_cbc  */

#define USER_AP_SAVED_DATA_SIZE                   256 /* 256 bytes buffer saved for user AP */
#define USER_AP_SAVED_DATA_NUM                    8   /* number of user ap buffer */

#define MINIMUM_TP_BUFFER_SIZE                    (4096*8)
#define TP_BUFFER_ALIGNMENT                       376
#define TP_BUFFER_THRESHOLD                       376
#define TP_BUFFER_WITH_FLOW_CTRL_ALIGNMENT        192  /* LCM(192,8) */
#define TP_BUFFER_WITH_FLOW_CTRL_THRESHOLD        192  /* LCM(192,8) */

#define TP_P_BUFFER_ALIGNMENT                     9024 /* LCM(188,192,8) */
#define TP_P_BUFFER_SIZE                          (TP_P_BUFFER_ALIGNMENT * 200) /* LCM(188,192,8) x 200 */
#define TP_P_BUFFER_THRESHOLD                     376
#define TP_P_MONITOR_BUFFER_SIZE                  (TP_P_BUFFER_ALIGNMENT) /* 9024=188*48 =192*47 */

/*  PID filter param */
#define REGARDLESS_OF_FILE_HANDLE                 (void*)0xffffffff
#define SEC_FILTER_FILE_HANDLE                    (void*)0xfffffffe
#define PCR_TRACKING_FILE_HANDLE                  (void*)0xfffffffc
#define MAX_PID_VALUE                             0x1fff

#define INVALID_BUFFER                            _ZERO

#define MASS_DATA_BUFFER_BLOCK_SIZE               188
#define TIME_STAMP_PADDING                        4
#define MASS_DATA_BUFFER_BLOCK_SIZE_WITH_TIME_STAMP (MASS_DATA_BUFFER_BLOCK_SIZE + TIME_STAMP_PADDING)

#define MASS_DATA_BUFFER_RP_CONNECT               3
#define MASS_DATA_BUFFER_RP                       0
#define SECTION_BUFFER_RP                         1
#define DUMP_BUFFER_RP                            2

#define INFO_PACK_BUFFER_BLOCK_SIZE               8
#define INFO_PACK_BUFFER_RP_CONNECT               1
#define INFO_PACK_BUFFER_RP                       0

#define START_CODE_PACK_BUFFER_BLOCK_SIZE         8
#define START_CODE_PACK_BUFFER_RP_CONNECT         1
#define START_CODE_PACK_BUFFER_RP                 0

/* TP CW key select */
#define TP_SETCW_KEYID_EVEN_KEY                   0
#define TP_SETCW_KEYID_ODD_KEY                    1
#define TP_SETCW_KEYID_MULTI2_SYS_KEY             2

#define PROC_READ_BUFFER_SIZE                     256

/*****************************************

   define for tp function enable/disable

******************************************/
#define TP_PCR_USE_IRQ
/*****************************************

   define for type change

******************************************/
#ifdef TP_KERNEL_DRIVER
#define TP_EXTERN   extern
#else
#define TP_EXTERN
#endif

/* support diff arch(arm64 or another) */
#ifdef CONFIG_ARM64
typedef unsigned long UADDRESS;
#else
typedef unsigned int UADDRESS;
#endif

typedef UINT32 REGADDR; // to declare the parameter save regsiter addr

/*****************************************

      Basic operation

******************************************/
#define READ_REG32(addr)                rtd_inl(addr)
#define WRITE_REG32(addr, val)          rtd_outl(addr,val)

/*****************************************

      special type define

******************************************/
typedef unsigned long long          UINT64;     /* !< for unsigned long long (64 bits) */
typedef long long                   INT64;      /* !< for signed long long (64 bits) */

/* TP common type definition */
/***** enum type *****/
typedef enum {
        TP_TPI0 = 0,
        TP_TPI1,
        TP_TPI2,
        TP_TPI_demod,
        MAX_TPI_COUNT,
} TPK_TPI_PIN_T;

typedef enum {
        TP_TP0 = 0,
        TP_TP1,
        TP_TP2,
        TP_TP3,
        MAX_TP_COUNT,
} TPK_TP_ENGINE_T;

typedef enum {
        TP_TP0_MTP = 0,
        TP_TP1_MTP,
        TP_TP2_MTP,
        TP_TP3_MTP,
        TP_TPP0_MTP,
        TP_TPP1_MTP,
        TP_TPP2_MTP,
        MAX_MTP_COUNT,
} TPK_TP_MTP_T;

typedef enum {
        TP_TPP0 = 0,
        TP_TPP1,
        TP_TPP2,
        MAX_TP_P_COUNT,
} TPK_TPP_ENGINE_T;


typedef enum {
        TP_CLK_OFF = 0,
        TP_CLK_ON,
} TPK_TP_CLK_STU_T;

typedef enum {
        byte_188 = 0,
        byte_192 = 1,
        byte_204 = 2
} TPK_TSP_LEN_T;

typedef struct {
        UINT8 inited;
        UADDRESS *pWP;
        UADDRESS *pRP;
} TPK_TP_BUF_RWPTR_T;

/* streaming control */
typedef enum {
        TP_STREAM_STOP = 0,             /* Stop streaming */
        TP_STREAM_START                 /* Start streming */
} TPK_TP_STREAM_CTRL_T;

typedef enum {
        TPP_STREAM_STOP = 0,            /* Stop streaming */
        TPP_STREAM_START,               /* Start streming */
} TPK_TPP_STREAM_CTRL_T;

typedef enum {
        TPOUT_STREAM_STOP = 0,          /* Stop streaming */
        TPOUT_STREAM_START ,            /* Start streming */
} TPK_TPOUT_STREAM_CTRL_T;

typedef enum {
        MTP_STREAM_STOP = 0,            /* Stop streaming */
        MTP_STREAM_START,               /* Start streming */
} TPK_MTP_STREAM_CTRL_T;

/* TP source setting */
typedef enum {
        TS_UNMAPPING = 0,
        MTP,
        Internal_Demod,
        TS_SRC_0,               /* TPI0, support serial/Parallel at merlin2 */
        TS_SRC_1,               /* TPI1, support serial/Parallel at merlin2 */
        TS_SRC_2,               /* TPI2, support serial/Parallel at merlin2 */
        TS_SRC_3,               /* reserved */
        TS_SRC_4,               /* reserved */
        TS_SRC_5,               /* reserved */
        TS_SRC_6                /* reserved */
} TPK_TP_SOURCE_T;

/*  TP out source setting */
typedef enum {
        TPK_TPOUT_UNMAPPING = -1,
        TPK_TP_MTP_TO_TPOUT = 0,
        TPK_TPP_TO_TPOUT,
        TPK_IN_DEMOD_TO_TPOUT,
        TPK_TPI0_TO_TPOUT,
        TPK_TPI1_TO_TPOUT,
        TPK_TPI2_TO_TPOUT,
        TPK_TPI3_TO_TPOUT
} TPK_TPOUT_SOURCE_T;

/* Descramble parameter */
typedef enum {
        TPK_NO_DESCRAMBLE = 0,
        TPK_TSP_LEVEL_DESCRAMBLE,
        TPK_PES_LEVEL_DESCRAMBLE
} TPK_DESCRAMBLE_MODE_T;

typedef enum {
        TPK_DESCRAMBLE_ALGO_NONE = 0,              /* this option only used to record status, do not send this option to TP driver */
        TPK_DESCRAMBLE_ALGO_DES_ECB_CLEAR,         /* DES ECB Mode: used by CI+ (Residual: keep clear) */
        TPK_DESCRAMBLE_ALGO_TDES_ECB_CLEAR,        /* TDES ECB Mode: used by Cable Card (Residual: keep clear) */
        TPK_DESCRAMBLE_ALGO_TDES_CBC_OFB,          /* TDES CBC Mode: used by ATSC (Residual: ofb mode) */
        TPK_DESCRAMBLE_ALGO_CSA,                   /* CSA Mode: used by DVB-C CA (Residual: ?? followed spec) */
        TPK_DESCRAMBLE_ALGO_MULTI2_OFB,            /* Multi2 Mode: used by ARIB CA (Residual: ofb mode) */
        TPK_DESCRAMBLE_ALGO_AES_128_CBC_CLEAR,     /* AES_128_CBC Mode: used by CI+ and Irdeto (Residual: keep clear) */
        TPK_DESCRAMBLE_ALGO_AES_RCBC_CS_CLEAR,     /* AES_128_RCBC CS Mode: used by Irdeto (Residual: keep clear) */
        TPK_DESCRAMBLE_ALGO_CSA2,                  /* CSA Mode: used by DVB-C CA (Residual: ?? followed spec) */
        TPK_DESCRAMBLE_ALGO_CSA_RAW,               /* CSA Mode with non standard key. key = CW (Residual: ?? followed spec) */
        TPK_DESCRAMBLE_ALGO_AES_128_CBC_OFB,       /* AES_128_CBC Mode (Residual: ofb mode) */
        TPK_DESCRAMBLE_ALGO_AES_128_CBC_OFB_ATIS,  /* AES_128_CBC Mode (Residual: ofb mode), for ATIS mode, driver will always set IV to 0 */
        TPK_DESCRAMBLE_ALGO_AES_128_ECB_CLEAR,     /* AES_128_ECB Mode: only support on Mxxxin, not support on rtd294x & rtd294x+ */
        TPK_DESCRAMBLE_ALGO_CAM_ECB_CLEAR,
        TPK_DESCRAMBLE_ALGO_CAM_CBC_CLEAR,
        TPK_DESCRAMBLE_ALGO_CAM_CBC_OFB,
        TPK_DESCRAMBLE_ALGO_MULTI2,
        TPK_DESCRAMBLE_ALGO_MULTI2_CBC,
} TPK_DESCRAMBLE_ALGORITHM_ID_T;

typedef enum {
        TPK_RESIDUAL_ORIGINAL_DEFAULT = 0,
        TPK_RESIDUAL_CLEAR,
        TPK_RESIDUAL_OFB
} TPK_DESCRAMBLE_RESIDUAL_MODE_T;

/* PCR setting */
typedef enum {
        MISC_90KHz = 0,
        TP_PCR_LOCAL_90KHz,
        TP_PCRA_LOCAL_90KHz = TP_PCR_LOCAL_90KHz,
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
        TP_PCRB_LOCAL_90KHz,
#endif
        CLK_SRC_NO_CHANGE,
        TPK_PCR_CLK_SRC_NUM,
} TPK_PCR_CLK_SRC_T;


/* support in rtd294x+ */
typedef enum {
        TPK_TS_PORT_ID_UNMAPPING = 0,
        TPK_TS_PORT_ID_1,
        TPK_TS_PORT_ID_2
} TPK_TS_PORT_ID_T;

/* support in rtd294x+ */
typedef enum {
        TPK_CONNECT_TO_UNMAPPING = 0,
        TPK_CONNECT_TO_TS_PORT_ID_0,    /*  SOURCE_FROM_CAM */
        TPK_CONNECT_TO_TS_IN_MUX,       /*  SOURCE_FROM_DEMOD */
        TPK_CONNECT_TO_MTP              /*  SOURCE_FROM_MTP */
} TPK_TP_MUX_SEL_T;

typedef enum {
        MTP_NOT_CONNECT = 0,
        MTP_TO_TP,
        MTP_TO_TPOUT,
        MTP_TO_TPP
} TPK_MTP_CONNECT_T;


typedef enum {
        MTP_BUFF_FLUSH_TO_BASE = 0,   /* move both RP and WP to BASE */
        MTP_BUFF_FLUSH_TO_RP,         /* move WP to RP */
        MTP_BUFF_FLUSH_TO_WP,         /* move RP to WP */
} MTP_BUFF_FLUSH_MODE_T;

/* Input Port Type      */
typedef enum {
        TPK_PORT_NONE = 0,            /* No Port */
        TPK_PORT_IN_DEMOD0,           /* Input From Internal Demodulator */
        TPK_PORT_IN_DEMOD1,           /* Input From Internal Demodulator */
        TPK_PORT_EXT_INPUT0,          /* SoC EXT Input ( such as External Demodulator or Channel Browser Chip */
        TPK_PORT_EXT_INPUT1,          /* SoC EXT Input ( such as External Demodulator or Channel Browser Chip */
        TPK_PORT_EXT_INPUT2,          /* SoC EXT Input ( such as External Demodulator or Channel Browser Chip */
        TPK_PORT_FROM_MEM,            /* TS Input From Memory */
        TPK_PORT_NUM,

        TPK_PORT_NULL //temp
} TPK_INPUT_PORT_T;

/* Input Type */
typedef enum {
        TPK_INPUT_SERIAL = 0,
        TPK_INPUT_PARALLEL,
        TPK_INPUT_ENABLE,
        TPK_INPUT_DISABLE,
        TPK_INPUT_MEM,
        TPK_INPUT_NUM,

        TPK_INPUT_NULL //temp
} TPK_INPUT_TYPE_T;

/* CAS Type     */
typedef enum {
        TPK_WITHOUT_CAS = 0,
        TPK_WITH_CAS
} TPK_CAS_TYPE_T;

/* FRC Rate Type */
typedef enum {
        TP_FRC_0_25X = 0,       /* 0.25x */
        TP_FRC_0_5X,            /* 0.5x */
        TP_FRC_1X,              /* 1x */
        TP_FRC_2X,              /* 2x */
        TP_FRC_4X,              /* 4x */
        TP_FRC_8X,              /* 8x */
        TP_FRC_16X,             /* 16x */
        TP_FRC_32X              /* 32x */
} TPK_FRC_RATE_T;

/* FRC Prefix Type */
/* TODO: To be modify in Mac6 */
typedef enum {
        TP_FRC_DEBUG_01 = 0,
        TP_FRC_DEBUG_02,
        TP_FRC_META_DATA,
        TP_FRC_NO_PREFIX,
        TP_FRC_KEPP
} TPK_FRC_PREFIX_T;



/***** struct type *****/
typedef struct {
        UINT8 inited;
        UADDRESS BasePhy;
        UINT32   BufSize;
        UADDRESS LimitPhy;
        UADDRESS BaseVir;
        UADDRESS LimitVir;
        UADDRESS RP;
        UADDRESS WP;              /* update by hardware, this may not correct */

        UINT8  bock_size;
        UINT64 buffer_err_cnt;

        /* if mutiple user use this buffer */
        UINT8 RP_Connect_cnt;
        UADDRESS RP_Connect[MAX_USED_BUFFER_CONNECT];
        UINT32 OriBufSize;
} TPK_TP_BUF_T;

typedef struct {
        UINT8 inited;
        UADDRESS BasePhy;
        UADDRESS BaseVir;
        UINT32 BufSize;
        UINT32 Threshold;
        UINT32 Fullness;
} TPK_TPOUT_BUF_T;


typedef struct {
        UINT8 inited;
        UADDRESS BasePhy;
        UINT32 BufSize;
        UADDRESS LimitPhy;
        UADDRESS BaseVir;
        UADDRESS LimitVir;
        UADDRESS RP;              /* update by hardware, this may not correct */
        UADDRESS WP;
} TPK_MTP_BUF_T;

typedef struct {
        UINT8 inited: 1;

        /* TP framer reg */
        UINT8 serial: 1;                /* 0: parallel; 1:serial */
        UINT8 two_bits: 1;              /* 0: parallel or serial; 1: two-bits mode */
        UINT8 data_order: 1;            /* 0: bit 7 is MSB, 1: bit 7 is LSB (used for Parallel TS) */
        UINT8 datapin: 1;               /* 0: MSB First,   1: LSB First (used for Serial TS) */
        UINT8 casType: 1;                               /* 0: without cas, 1: with cas */
        UINT8 sync_byte;                /* default please set to 0x47 */
        TPK_TSP_LEN_T ts_in_tsp_len;    /* 188/192/204 bytes */

        /* TP CTRL reg */
        UINT8 clr_tsp_scrmbl_bit: 1;    /* 1: TP will clean scramble bit if disscramble enabled */

        /* PID filter enable */
        UINT8 pid_filter_en: 1;         /* 0: disable pid filter; 1:enable pid filter */

        UINT8 keep: 1;                  /* 1: keep original first 4 bytes data in front of TSP if input is 192 bytes, 0:replace by prefix */
        UINT8 prefix_en: 1;             /* 1: TP will add 4 bytes timestamp in the front of TSP */
        UINT8 frc_en: 1;                /* 1: TP will check 4 bytes debug info in the front of TSP when file playback */
} TPK_TP_TS_PARAM_T;

typedef struct {
        /* TP framer reg */
        UINT8 serial: 1;                /* 0: parallel; 1:serial */
        UINT8 two_bits: 1;              /* 0: parallel or serial; 1: two-bits mode */
        UINT8 data_order: 1;            /* 0: bit 7 is MSB, 1: bit 7 is LSB (used for Parallel TS) */
        UINT8 datapin: 1;               /* 0: MSB First,   1: LSB First (used for Serial TS) */
        UINT8 sync_byte;                /* default please set to 0x47 */
        TPK_TSP_LEN_T ts_in_tsp_len;    /* 188/192/204 bytes */
        /* PID filter enable */
        UINT8 pid_filter_en: 1;         /* 0: disable pid filter; 1:enable pid filter */
} TPK_TPP_TS_PARAM_T;

/* TP Input Control */
typedef struct {
        UINT8 clk_pol: 1 ;      /* 0:latch on rising edge, 1:latch on falling edge */
        UINT8 sync_pol: 1;      /* 0:active high, 1:active low */
        UINT8 val_pol: 1 ;      /* 0:active high, 1:active low */
} TPK_TP_INPUT_PARAM_T;

/* TP OUT parameter */
typedef struct {
        UINT8 inited: 1;
        UINT8 in_serial: 1;
        UINT8 in_data_order: 1;    /* 0: bit 7 is MSB, 1: bit 7 is LSB (Parallel) */
        UINT8 in_sync_pol: 1;      /* 0: Active High, 1: Active Low */
        UINT8 in_val_pol: 1 ;      /* 0: Active High, 1: Active Low */
        UINT8 in_clk_pol: 1 ;      /* 0: Latch On Rising Edge, 1: Latch On Falling Edge */

        UINT8 out_serial: 1;
        UINT8 out_data_order: 1;    /* 0: bit 7 is MSB, 1: bit 7 is LSB (Parallel) */
        UINT8 out_sync_pol: 1;      /* 0: Active High, 1: Active Low */
        UINT8 out_val_pol: 1 ;      /* 0: Active High, 1: Active Low */
        UINT8 out_clk_pol: 1 ;      /* 0: Latch On Rising Edge, 1: Latch On Falling Edge */
        UINT8 sync_dur: 1 ;     /* Sync signal is 8 bits or 1 bit 0: 1 bit, 1: 8 bit */
} TPK_TPOUT_TS_PARAM_T;

/* PID filter parameter */
typedef struct {
        UINT8   valid: 1;           /* save status, no need to set at input parameter */

        UINT8   DescrambleEn: 1;    /* only working on rtd294x+ (chip must ECO) */
        UINT16  PID;
        UINT8   KeySel;
} TPK_PID_FILTER_PARAM_T;

/* section filter parameter */
typedef struct {
        UINT16  pid;            /* PID of section */
        UINT8*  p_data;         /* start address of section */
        INT32   buf_idx;
        UINT16  len;            /* length of section in byte */
        UINT8   crc_err;        /* crc status */

} TPK_SEC_DATA_T;

typedef struct {
        UINT16  PID;
        UINT8   PosVal[10];
        UINT8   PosMsk[10];
        UINT8   NegVal[10];
        UINT8   NegMsk[10];

        /* TRUE: mask crc error section and do not deliver to upper layer */
        /* FALSE: section filter will deliver section even if CRC is error. And crc error status will be showed in crc_err of TPK_SEC_DATA_T */
        UINT8   crc_en;
        UINT8   one_shoot;          /* only deliver section to upper layer once */
        UINT8   toggle_mode_en;         /* check section table ID LSB, LSB start from 0 or 1 both ok, then this bit has to be toggled then section could deliver */

        INT32 (*Request_buf) (void* pContext, UINT8** ppBuf, UINT16 size); /*  if ret<0, can not get buffer. */
        void (*Complete) (void* pContext, TPK_SEC_DATA_T* pSec);
        void* pContext;
} TPK_SEC_FILTER_PARAM_T;

typedef struct {
        UINT16  PID;
        UINT8   PosVal[10];
        UINT8   PosMsk[10];
        UINT8   NegVal[10];
        UINT8   NegMsk[10];

        /* TRUE: mask crc error section and do not deliver to upper layer */
        /* FALSE: section filter will deliver section even if CRC is error. And crc error status will be showed in crc_err of TPK_SEC_DATA_T */
        UINT8   crc_en;
        UINT8   one_shoot;          /* only deliver section to upper layer once */
        UINT8   toggle_mode_en;         /* check section table ID LSB, LSB start from 0 or 1 both ok, then this bit has to be toggled then section could deliver */

        u32 Request_buf_ptr;
        u32 complete_ptr;
        u32 context_ptr;
} TPK_SEC_FILTER_PARAM_COMPAT_T;

typedef struct {
        TPK_DESCRAMBLE_ALGORITHM_ID_T algo;
        UINT32  round;                        /* used only by multi2, for Japan ISDB-T/ISDB-S, set round to 32 */
} TPK_DESCRAMBLE_ALGORITHM_T;

typedef struct {
        UINT8 pid_filter_num;
        UINT8 sec_filter_num;
} TPK_TP_HARDWARE_INFO_T;

typedef struct {
        UINT32 chip_version;    /* rtd294x:1; rtd294x+:2; rtd299s:3; rtd299o:4; rtd289x:5 */
        UINT8 tp_num;
        UINT8 tpout_num;
        UINT8 mtp_num;
        UINT8 descrambler_num;
        TPK_TP_HARDWARE_INFO_T tp_hareware_info[MAX_TP_MODULE_SUPPORT];
} TPK_HARDWARE_INFO_T;

typedef struct {
        UINT8               v: 1;                      /* valid bit for this pid filter */
        UINT8               si_en: 1;                  /* enable section info pack */
        UINT8               ai_en: 1;
        UINT8               ti_en: 1;                  /* Enable TP Info Pack or Not */
        UINT8               sec_en: 1;                 /* Enable Section Filter or Not */
        UINT8               cc_en: 1;                  /* Continuity Counter check enable */
        UINT8               pid_descramble_disable: 1; /* disable descramble for each pid(0:enable descramble;1: enable descramble for this pid filter) */
        UINT8               pre_des: 1;
        UINT8               local_des_en: 1;
        UINT8               encrypt_tsc_en;
        UINT8               encryption_key;
        UINT8               encryption_en;

        UINT8               sec_idx;
        UINT8               ddr_q;
        UINT8               info_q;
        UINT8               key;                       /* key table index for this pid filter */
        UINT16              pid;

} TPK_PID_REG_PARAM_T;


typedef struct {
        unsigned short              PID;
        unsigned char               PosVal[10];       /* positive value for section filter */
        unsigned char               PosMsk[10];       /* positive mask for section filter */
        unsigned char               NegVal[10];       /* negative value for section filter */
        unsigned char               NegMsk[10];       /* negative mask for section filter */
        unsigned char               crc_en: 1;
        unsigned char               p_d: 1;           /* Pass / Drop if this is the last block and still no matched */
        unsigned char               p_n: 1;           /* Postive / Negative */
        unsigned char               last: 1;          /* Is this is the latest section filter */
        unsigned char               next_sec: 6;      /* who is the next ? */
} TPK_SEC_REG_T;


typedef struct {
        UINT8 pid_sec_cnt;            /* save linked section filter cnt for each PID */
        UINT8 *pSec_buf;              /* section buffer per PID. There is 4KBytes buffer for each PID */
        UINT16  sec_data_cnt;         /* current section buffer collect data count */
        UINT16  sec_expect_len;       /* expect section length */
} TPK_TP_PID_SEC_PARAM_T;


typedef struct {
        UINT8 valid: 1;               /* 1: this section filter is used; 0: this section filter is not used */
        UINT8 first_in_pid: 1;
        UINT8 positive_filter_en: 1;
        UINT8 negative_filter_en: 1;

        UINT16 last_sec_idx;
        UINT16 sec_idx;
        UINT16 pid_idx;
        UINT16 pid_idx_reg;

        /* set from RHAL api */
        UINT8 tp_id;
        TPK_SEC_FILTER_PARAM_T sec_api_setting;
        void* file_handle;

        /* reg save */
        TPK_SEC_REG_T sec_reg;

        /* section deliver counter */
        UINT32 sec_deliver_cnt;

        UINT8 toggle_rec;
} TPK_SEC_FILTER_STATUS_T;


typedef struct {
        UINT8 enable: 1;
        UINT8 Base_Valid: 1;
        UINT8 ClkSrcChange: 1;
        TPK_PCR_CLK_SRC_T clk_src;
        UINT16 PID;
        UINT64 LastPCR;
        UINT64 LastSTC;
        UINT64 PCRBase;     /* valid only 33bits */
        UINT64 STCBase;     /* valid 64 bits */

        UINT64 update_pcr_status_timeout;
        UINT64 old_pcr;
        UINT64 old_stc;
        UINT16 pcr_stc_same_count;
        UINT16 pcr_irq_cnt;

} TPK_PCR_TRACKING_STATUS_T;


typedef struct {
        /* pid filter parameter */
        UINT8 pid_file_handle_cnt[MAX_PID_PER_TP];
        void* file_handle[MAX_PID_PER_TP][MAX_FILE_HANDLE_REC];
        TPK_PID_FILTER_PARAM_T pid_api_setting[MAX_PID_PER_TP];

        /* save sec valid count for each TP */
        UINT16 tp_sec_cnt;

        /* sec filter parameter of each PID */
        TPK_TP_PID_SEC_PARAM_T pid_sec[MAX_PID_PER_TP];

        /* save data counter to calculate flow rate */
        UINT32 tp_mass_data_release_cnt;

        UINT32 ringrate_KB;

        /* PCR tracking */
        TPK_PCR_TRACKING_STATUS_T pcr;
} TPK_TP_PID_STATUS_T;


typedef struct {
        UINT64 pkt;
        UINT64 droppedPkt;
        UINT64 errorPkt;
} TPK_TP_PKT_CNT_T;

typedef struct {
        UINT64 pkt;
        UINT64 droppedPkt;
} TPK_TPP_PKT_CNT_T;

typedef struct {
        UINT8 Inited: 1;
        UINT8 IsMassBufferFull: 1;
        UINT8 IsPktWithTimeStamp: 1;

        TPK_TP_SOURCE_T tp_src;
        TPK_TP_STREAM_CTRL_T tp_stream_status;
        TPK_TP_TS_PARAM_T tp_param;

        /* buffer parameter */
        /* 2016/12/12 add, TP buff flush flag,
           to protect read_data and release_data race condition
           from demux and section thread */
        UINT8 buffer_flush_flag;
        TPK_TP_BUF_T mass_buffer;
        TPK_TP_BUF_T info_pack_buffer;

        TPK_TP_BUF_RWPTR_T Shared_RWPtr;

        TPK_TP_BUF_T start_code_search_buffer;
        TPK_TP_BUF_RWPTR_T Shared_RWPtr_start_code_search;
        UINT8 useTPStartCodeSearch;

        UINT32 threshold;
        UINT32 fullness;

        /* descramble parameter */
        TPK_DESCRAMBLE_ALGORITHM_T desc;
        TPK_DESCRAMBLE_MODE_T desc_mode;

        /* packet count */
        TPK_TP_PKT_CNT_T tp_pkt_cnt;

        UINT32 show_startcode_info_cnt;

        UADDRESS lastWP;
        UADDRESS old_wp;
        UADDRESS now_startcode_parsing_address;
        UADDRESS wp_update_by_startcode;
        UADDRESS timeout_wp;
        UINT32 find_new_start_code;
        struct timeval saved_time;
        UINT64 stc_from_isr;
        UINT64 pcr_from_isr;

        UADDRESS monitor_pvr_rp;
        UADDRESS monitor_pvr_wp;

        UINT64 errPktDiff;
} TPK_TP_STATUS_T;

typedef struct {
        UINT8 Inited: 1;
        TPK_TP_BUF_T mass_buffer;
        TPK_TP_SOURCE_T tpp_src;
        TPK_TPP_TS_PARAM_T tpp_param;
        TPK_TPP_STREAM_CTRL_T tpp_stream_status;
        /* packet count */
        TPK_TPP_PKT_CNT_T tpp_pkt_cnt;
} TPK_TPP_STATUS_T;


typedef struct {
        UINT8 is_connected;
        TPK_TPP_ENGINE_T tpp_id;
        TPK_TP_SOURCE_T tpp_src;
        UINT8 output_sync_byte;         /* for different demux id to output data, sync byte must be changed */
} TPK_TPOUT_REMUX_PARAM_T;

typedef struct {
        UINT8 Inited: 1;
        /* use for rtd294x */
        TPK_TPOUT_SOURCE_T tpout_src;
        /* use for rtd294x+ */
        TPK_TPOUT_REMUX_PARAM_T tpout_remux[MAX_TPOUT_REMUX_COUNT];
        TPK_TPOUT_BUF_T mass_buffer;
        TPK_TPOUT_STREAM_CTRL_T tpout_stream_status;
        TPK_TPOUT_TS_PARAM_T tpout_param;
} TPK_TPOUT_STATUS_T;

typedef struct {
        UINT8 valid: 1;
        TPK_MTP_STREAM_CTRL_T mtp_stream_status;
        TPK_MTP_BUF_T mtp_buf_param;
        TPK_MTP_CONNECT_T mtp_connect_type;

        /* save data counter to calculate flow rate */
        UINT32 mtp_write_data_cnt;
        UINT32 last_timestamp;
        UINT32 timestmp_offset;
        UINT8 first_tsp;

} TPK_MTP_STATUS_T;

typedef struct {
        TPK_DESCRAMBLE_ALGORITHM_T  desc;
} TPK_ALGO_KEYSEL_T;

#endif /* __TP_DEF_H__ */

