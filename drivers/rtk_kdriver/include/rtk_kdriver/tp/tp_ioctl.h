#ifndef __TP_IOCTL_H__
#define __TP_IOCTL_H__

#include <tp/tp_def.h>

#define TP_REG_RW_SIZE              32  /* unit: 4 bytes */

/* Biggest section size */
#define SEC_FILTER_BUFFER_EACH_SIZE (4096)

#define MAX_PID_SETTING             64
#define MAX_SECTION_SETTING         64




/* TP IOC structure */
/* TP APIs */
typedef struct {
        UINT8 tp_id;
} TP_IOC_BASIC_T;

typedef struct {
        UINT8 tp_id;
        TPK_TP_TS_PARAM_T Param;
} TP_IOC_SET_TP_MODE_T;

typedef struct {
        UINT8 tp_id;
        TPK_TP_TS_PARAM_T Param;
} TP_IOC_GET_TP_MODE_T;

typedef struct {
        UINT8 tp_id;
        TPK_TP_STATUS_T tp_status;
} TP_IOC_GET_TP_STATUS_T;

typedef struct {
        UINT8 tp_id;
        UINT8* pPhyAddr;
        UINT8* pVirAddr;
        UINT32 size;
} TP_IOC_SET_TP_RING_BUFF_T;

typedef struct {
        UINT8 tp_id;
        UINT32 BufferSize;
        UINT32 DataSize;
} TP_IOC_GET_TP_BUF_STATUS_T;

typedef struct {
        UINT8 tp_id;
        TPK_TP_STREAM_CTRL_T ctrl;
} TP_IOC_TP_STREAM_CONTROL_T;

typedef struct {
        UINT8 tp_id;
        UINT8* pReadPhyPtr;
        UINT32 ContinueReadSize;
        UINT32 Threshold;
} TP_IOC_TP_READ_DATA_T;

typedef struct {
        UINT8 tp_id;
        UINT8* pReadPhyPtr;
        UINT32 Size;
} TP_IOC_TP_RELEASE_DATA_T;

typedef struct {
        BOOL bIsNew;
        TPK_SEC_DATA_T Sec;
        UINT8 aBuf[SEC_FILTER_BUFFER_EACH_SIZE];
        UINT32 handleId;
} TP_IOC_GET_SECTION_DATA_T;

typedef struct {
        UINT8 tp_id;
        TPK_TP_SOURCE_T tp_src;
        TPK_CAS_TYPE_T casType;
} TP_IOC_TP_SOURCE_T;

typedef struct {
        UINT8 tp_id;
        UINT8 enable;
} TP_IOC_TP_SET_RAW_MODE_T;

typedef struct {
        UINT8 tp_id;
        UINT8 sync_replace;
} TP_IOC_TP_SYNC_REPLACE_T;


/* TPOUT APIs */
typedef struct {
        UINT8 tpout_id;
        TPK_TPOUT_TS_PARAM_T Param;
} TP_IOC_TPOUT_MODE_T;

typedef struct {
        UINT8 tpout_id;
        TPK_TPOUT_SOURCE_T tpout_src;
        TPK_TPOUT_REMUX_PARAM_T *remux_param;
} TP_IOC_TPOUT_DATA_SOURCE_T;

typedef struct {
        UINT8 tpout_id;
        TPK_TPOUT_STREAM_CTRL_T ctrl;
} TP_IOC_TPOUT_STREAM_CONTROL_T;

typedef struct {
        UINT8 tpout_id;
        TPK_TPOUT_STATUS_T tpout_status;
} TP_IOC_GET_TPOUT_STATUS_T;

typedef struct {
        UINT8 tpout_id;
        UINT32 pre_div;
        UINT32 post_div;
} TP_IOC_SET_TPOUT_CLK_T;

/* MTP APIs */
typedef struct {
        UINT8 mtp_id;
        UINT8* pPhyAddr;
        UINT8* pVirAddr;
        UINT32 size;
} TP_IOC_SET_MTP_BUFF_T;

typedef struct {
        UINT8 mtp_id;
        UINT8* pPhyWP;
        UINT32 ContinueWrite;
} TP_IOC_WRITE_MTP_BUFF_T;

typedef struct {
        UINT8 mtp_id;
        UINT8* pWritePtr;
        UINT32 ContinueWriteSize;
        UINT32 WritableSize;
} TP_IOC_GET_MTP_BUF_STATUS_T;

typedef struct {
        UINT8 mtp_id;
        TPK_MTP_STREAM_CTRL_T ctrl;
} TP_IOC_MTP_STREAM_CONTROL_T;

typedef struct {
        UINT8 mtp_id;
        TPK_MTP_STATUS_T mtp_status;
} TP_IOC_GET_MTP_STATUS_T;

typedef struct {
        UINT8 mtp_id;
        MTP_BUFF_FLUSH_MODE_T mode;
} TP_IOC_MTP_FLUSH_T;

/* FRC */
typedef struct {
        UINT8 tp_id;
        UINT8 enable;
} TP_IOC_FRC_ENABLE_T;

typedef struct {
        UINT8 tp_id;
        TPK_FRC_RATE_T rate;
} TP_IOC_FRC_SET_RATE_T;

typedef struct {
        UINT8 tp_id;
        TPK_FRC_PREFIX_T prefix_sel;
        UINT32 meta_data;
} TP_IOC_FRC_SET_PREFIX_T;

/* PID filter */
typedef struct {
        UINT8 tp_id;
        UINT16 usPIDLen;
        TPK_PID_FILTER_PARAM_T PIDParm[MAX_PID_SETTING];
} TP_IOC_PID_FILTER_T;

typedef struct {
        UINT8 tp_id;
        TPK_PID_FILTER_PARAM_T PIDParm;
} TP_IOC_ADD_PID_FILTER_T;

typedef struct {
        UINT8 tp_id;
        UINT16 PID;
} TP_IOC_REMOVE_PID_FILTER_T;

typedef struct {
        UINT8 tp_id;
} TP_IOC_REMOVE_ALL_PID_T;

typedef struct {
        UINT8 tp_id;
        UINT16 PID_Buf_Cnt;
        TPK_PID_FILTER_PARAM_T PIDParm[MAX_PID_PER_TP];
        UINT16 PIDLen;
} TP_IOC_GET_PID_STATUS_T;

typedef struct {
        UINT8 tp_id;
        UINT8  pid_en;
} TP_IOC_SET_PIDEN_T;

/* Section filter */
typedef struct {
        UINT8 tp_id;
        void* pSec_handle;
        TPK_SEC_FILTER_PARAM_T Param;
} TP_IOC_ADD_SECTION_FILTER_T;

typedef struct {
        UINT8 tp_id;
        void* pSec_handle;
} TP_IOC_REMOVE_SECTION_FILTER_T;

typedef struct {
        UINT8 tp_id;
} TP_IOC_REMOVE_ALL_SECTION_T;

typedef struct {
        UINT8 tp_id;
        UINT16 Sec_Buf_cnt;
        TPK_SEC_FILTER_STATUS_T SecStatus[MAX_SEC_COUNT];
        UINT16 usSecLen;
} TP_IOC_GET_SECTION_STATUS_T;

/* PCR tracking */
typedef struct {
        UINT8 tp_id;
        UINT8 On;
        UINT16 PID;
        TPK_PCR_CLK_SRC_T clk_src;
} TP_IOC_PCR_TRACKING_EN_T;

typedef struct {
        UINT8 tp_id;
        long long PCR;
        long long STC;
        long long PCRBase;
        long long STCBase;
} TP_IOC_GET_PCR_TRACKING_T;

typedef struct {
        UINT8 tp_id;
} TP_IOC_RESET_PCR_TRACKING_T;

/* Descrambler APIs */
typedef struct {
        UINT8 tp_id;
        TPK_DESCRAMBLE_ALGORITHM_T algo;
} TP_IOC_DESCRAMBLE_ALGORITHM_T;

typedef struct {
        UINT8 tp_id;
        UINT8 key_set;
        UINT8 key_id;
        UINT8 Key[TPK_MAX_KEY_LENGTH];
        UINT8 IV[TPK_MAX_IV_LENGTH];
} TP_IOC_SET_CW_T;

typedef struct {
        UINT8 tp_id;
        TPK_DESCRAMBLE_MODE_T mode;
} TP_IOC_DESCRAMBLE_CONTROL_T;

typedef struct {
        UINT8 tp_id;
        UINT16 PID;
        UINT8 keytype;
} TP_IOC_SET_ENCRYPTION_T;

/* Start Code APIs */
typedef struct {
        UINT8 tp_id;
        UINT8 enable;
} TP_IOC_STARTCODE_ENABLE_T;

typedef struct {
        UINT8 tp_id;
        UINT16 PID;
} TP_IOC_STARTCODE_SET_PID_T;

typedef struct {
        UINT8 tp_id;
        UINT8* pPhyAddr;
        UINT8* pVirAddr;
        UINT32 size;
} TP_IOC_STARTCODE_SET_BUFFER_T;

typedef struct {
        UINT8 tp_id;
        UINT8* pReadPhyPtr;
        UINT32 ContinueReadSize;
} TP_IOC_STARTCODE_READ_INFO_T;

typedef struct {
        UINT8 tp_id;
        UINT8* pReadPhyPtr;
        UINT32 Size;
} TP_IOC_STARTCODE_RELEASE_INFO_T;


/* TPP APIs */
typedef struct {
        TPK_TPP_ENGINE_T tp_p_id;
} TP_IOC_TPP_BASIC_T;

typedef struct {
        TPK_TPP_ENGINE_T tp_p_id;
        TPK_TPP_TS_PARAM_T  param;
} TP_IOC_TPP_MODE_T;

typedef struct {
        TPK_TPP_ENGINE_T tp_p_id;
        UINT8  pid_en;
} TP_IOC_TPP_SET_PIDEN_T;


typedef struct {
        TPK_TPP_ENGINE_T tp_p_id;
        TPK_TPP_STREAM_CTRL_T ctrl;
} TP_IOC_TPP_STREAM_CONTROL_T;

typedef struct {
        TPK_TPP_ENGINE_T tp_p_id;
        UINT32 BufferSize;
        UINT32 DataSize;
} TP_IOC_GET_TPP_BUF_STATUS_T;

typedef struct {
        TPK_TPP_ENGINE_T tp_p_id;
        UINT8 sync_replace;
} TP_IOC_SET_TPP_SYNC_REPLACE_T;



/* get debug message */
typedef struct {
        UINT8 tp_id;
        UINT64 ErrPkt;
        UINT64 RevPkt;
        UINT64 DropPkt;
} TP_IOC_TRACK_ERR_PACKET_T;

/* TP register RW structure */
typedef struct {
        UADDRESS Reg;
        UINT8 bRegOffset;       /* if 0, Reg is real register address. if 1, Reg is offset only. */
        UINT8 bRead;            /* if 1, read operation. if 1, write operation. */
        UINT32 Len;             /* read length of register (unit : 4 bytes) */
        UADDRESS Data[TP_REG_RW_SIZE];
} TP_REG_RW_T;

typedef struct {

        /* tp */
        UINT32          tp_tf_cntl_reg[MAX_TP_COUNT];
        UINT32     tp_tf_frmcfg_reg[MAX_TP_COUNT];
        UINT32       tp_tf_int_reg[MAX_TP_COUNT];
        UINT32       tp_tf_int_en_reg[MAX_TP_COUNT];
        UINT32       tp_tf_cnt_reg[MAX_TP_COUNT];
        UINT32       tp_tf_drop_reg[MAX_TP_COUNT];
        UINT32       tp_tf_err_reg[MAX_TP_COUNT];

        /* ring buffer */
        UINT32        tp_ring_limit_reg[MAX_TP_BUFFER_COUNT];
        UINT32       tp_ring_base_reg[MAX_TP_BUFFER_COUNT];
        UINT32         tp_ring_rp_reg[MAX_TP_BUFFER_COUNT];
        UINT32         tp_ring_wp_reg[MAX_TP_BUFFER_COUNT];

        /* sync replace */
        UINT32        tp_sync_rplace_reg;

        /* tpout */
        UINT32        tp_tf_out_frmcfg_reg;
        UINT32        tp_out_ctrl_reg;

        /* pcr */
        UINT32        tp_pcr_ctl_reg[MAX_TP_COUNT];

        /* des & tdes */
        UINT32         tp_tp_des_cntl_reg[MAX_TP_COUNT];
        UINT32        tp_key_info_reg[MAX_KEY_COUNT];
        UINT32         tp_key_info2_reg[MAX_KEY_COUNT];


        /* m2m ring buffer */
        UINT32          tp_m2m_ring_limit_reg[MAX_TP_COUNT];
        UINT32       tp_m2m_ring_base_reg[MAX_TP_COUNT];
        UINT32       tp_m2m_ring_rp_reg[MAX_TP_COUNT];
        UINT32       tp_m2m_ring_wp_reg[MAX_TP_COUNT];
        UINT32          tp_m2m_ring_ctrl_reg[MAX_TP_COUNT];

        UINT32        tp_p_m2m_ring_limit_reg[MAX_TP_P_COUNT];
        UINT32         tp_p_m2m_ring_base_reg[MAX_TP_P_COUNT];
        UINT32          tp_p_m2m_ring_rp_reg[MAX_TP_P_COUNT];
        UINT32          tp_p_m2m_ring_wp_reg[MAX_TP_P_COUNT];
        UINT32         tp_p_m2m_ring_ctrl_reg[MAX_TP_P_COUNT];

        /* tp_p */
        UINT32       tp_tf_p_cntl_reg[MAX_TP_P_COUNT];
        UINT32         tp_tf_p_frmcfg_reg[MAX_TP_P_COUNT];
        UINT32        tp_tf_p_int_reg[MAX_TP_P_COUNT];
        UINT32        tp_tf_p_int_en_reg[MAX_TP_P_COUNT];
        UINT32       tp_tf_p_cnt_reg[MAX_TP_P_COUNT];
        UINT32       tp_tf_p_drop_reg[MAX_TP_P_COUNT];

        /* tp_p ring buffer */
        UINT32       tp_p_ring_limit_reg[MAX_TPP_BUFFER_COUNT];
        UINT32        tp_p_ring_base_reg[MAX_TPP_BUFFER_COUNT];
        UINT32         tp_p_ring_rp_reg[MAX_TPP_BUFFER_COUNT];
        UINT32        tp_p_ring_wp_reg[MAX_TPP_BUFFER_COUNT];

        /* tp_p sync replace */
        UINT32       tp_p_sync_rplace_reg;

        /* frame rate control */
        UINT32        prefix_ctrl_reg;
        UINT32         prefix_data1_reg;
        UINT32         prefix_data2_reg;
        UINT32         prefix_data3_reg;
        UINT32       fr_ctrl_reg;

        /* start code search for tp0 & tp1 */
        UINT32       start_code_tp0_reg;
        UINT32        start_code_tp1_reg;
        UINT32         start_code_ctrl_tp0_reg;
        UINT32         start_code_ctrl_tp1_reg;

        /* TPO CLK */
        UINT32     tpout_clk_reg;
} TPK_DUMP_REG_INFO_T;

#define TP_IOC_MAGIC                   't'

#define TP_APIS_START    1
#define TP_TPOUT_START    TP_APIS_START+14
#define TP_MTP_START    TP_TPOUT_START+6
#define TP_FRC_START    TP_MTP_START+6
#define TP_PID_START    TP_FRC_START+3
#define TP_SECTION_START   TP_PID_START+5
#define TP_PCR_START    TP_SECTION_START+5
#define TP_DESCRAMBLER_START  TP_PCR_START+3
#define TP_STARTCODE_START  TP_DESCRAMBLER_START+4
#define TP_CIPLUS_START  TP_STARTCODE_START+6

#define TP_MISC_START    TP_CIPLUS_START+7

/* TP APIs */
#define TP_IOC_INIT                 _IOW(TP_IOC_MAGIC,TP_APIS_START, TP_IOC_BASIC_T*)
#define TP_IOC_UNINIT               _IOW(TP_IOC_MAGIC,TP_APIS_START+1, TP_IOC_BASIC_T*)
#define TP_IOC_SET_TP_MODE          _IOW(TP_IOC_MAGIC,TP_APIS_START+2, TP_IOC_SET_TP_MODE_T*)
#define TP_IOC_GET_TP_MODE       _IOWR(TP_IOC_MAGIC,TP_APIS_START+3, TP_IOC_GET_TP_MODE_T*)
#define TP_IOC_GET_TP_STATUS        _IOWR(TP_IOC_MAGIC,TP_APIS_START+4, TP_IOC_GET_TP_STATUS_T*)
#define TP_IOC_SET_TP_SOURCE        _IOW(TP_IOC_MAGIC,TP_APIS_START+5, TP_IOC_TP_SOURCE_T*)
#define TP_IOC_FLUSH_BUFF           _IOW(TP_IOC_MAGIC,TP_APIS_START+6, TP_IOC_BASIC_T*)
#define TP_IOC_SET_TP_RING_BUFF     _IOW(TP_IOC_MAGIC,TP_APIS_START+7, TP_IOC_SET_TP_RING_BUFF_T*)
#define TP_IOC_GET_TP_BUF_STATUS    _IOWR(TP_IOC_MAGIC,TP_APIS_START+8, TP_IOC_GET_TP_BUF_STATUS_T*)
#define TP_IOC_TP_STREAM_CONTROL    _IOW(TP_IOC_MAGIC,TP_APIS_START+9, TP_IOC_TP_STREAM_CONTROL_T*)
#define TP_IOC_TP_READ_DATA         _IOWR(TP_IOC_MAGIC,TP_APIS_START+10, TP_IOC_TP_READ_DATA_T*)
#define TP_IOC_TP_RELEASE_DATA      _IOW(TP_IOC_MAGIC,TP_APIS_START+11, TP_IOC_TP_RELEASE_DATA_T*)
#define TP_IOC_TP_SET_RAW_MODE      _IOW(TP_IOC_MAGIC,TP_APIS_START+12, TP_IOC_TP_SET_RAW_MODE_T*)
#define TP_IOC_TP_SYNC_REPLACE      _IOW(TP_IOC_MAGIC,TP_APIS_START+13, TP_IOC_TP_SYNC_REPLACE_T*)

/* TPOUT APIs */
#define TP_IOC_SET_TPOUT_MODE        _IOW(TP_IOC_MAGIC,TP_TPOUT_START, TP_IOC_TPOUT_MODE_T*)
#define TP_IOC_GET_TPOUT_MODE        _IOW(TP_IOC_MAGIC,TP_TPOUT_START+1, TP_IOC_TPOUT_MODE_T*)
#define TP_IOC_SET_TPOUT_DATA_SOURCE _IOW(TP_IOC_MAGIC,TP_TPOUT_START+2, TP_IOC_TPOUT_DATA_SOURCE_T*)
#define TP_IOC_TPOUT_STREAM_CONTROL  _IOW(TP_IOC_MAGIC,TP_TPOUT_START+3, TP_IOC_TPOUT_STREAM_CONTROL_T*)
#define TP_IOC_GET_TPOUT_STATUS      _IOWR(TP_IOC_MAGIC,TP_TPOUT_START+4, TP_IOC_GET_TPOUT_STATUS_T*)
#define TP_IOC_SET_TPOUT_CLK         _IOWR(TP_IOC_MAGIC,TP_TPOUT_START+5, TP_IOC_SET_TPOUT_CLK_T*)

/* MTP APIs */
#define TP_IOC_SET_MTP_BUFF             _IOW(TP_IOC_MAGIC,TP_MTP_START, TP_IOC_SET_MTP_BUFF_T*)
#define TP_IOC_WRITE_MTP_BUFF           _IOW(TP_IOC_MAGIC,TP_MTP_START+1, TP_IOC_WRITE_MTP_BUFF_T*)
#define TP_IOC_GET_MTP_BUF_STATUS       _IOWR(TP_IOC_MAGIC,TP_MTP_START+2, TP_IOC_GET_MTP_BUF_STATUS_T*)
#define TP_IOC_MTP_STREAM_CONTROL       _IOW(TP_IOC_MAGIC,TP_MTP_START+3, TP_IOC_MTP_STREAM_CONTROL_T*)
#define TP_IOC_FLUSH_MTP                _IOW(TP_IOC_MAGIC,TP_MTP_START+4, TP_IOC_MTP_FLUSH_T*)
#define TP_IOC_GET_MTP_STATUS           _IOWR(TP_IOC_MAGIC,TP_MTP_START+5, TP_IOC_GET_MTP_STATUS_T*)

/* FRC APIs */
#define TP_IOC_FRC_ENABLE            _IOW(TP_IOC_MAGIC,TP_FRC_START, TP_IOC_FRC_ENABLE_T*)
#define TP_IOC_FRC_SET_RATE         _IOW(TP_IOC_MAGIC,TP_FRC_START+1, TP_IOC_FRC_SET_RATE_T*)
#define TP_IOC_FRC_SET_PREFIX           _IOW(TP_IOC_MAGIC,TP_FRC_START+2, TP_IOC_FRC_SET_PREFIX_T*)

/* PID filter */
#define TP_IOC_ADD_PID_FILTER           _IOW(TP_IOC_MAGIC,TP_PID_START, TP_IOC_PID_FILTER_T*)
#define TP_IOC_REMOVE_PID_FILTER        _IOW(TP_IOC_MAGIC,TP_PID_START+1, TP_IOC_REMOVE_PID_FILTER_T*)
#define TP_IOC_REMOVE_ALL_PID           _IOW(TP_IOC_MAGIC,TP_PID_START+2, TP_IOC_BASIC_T*)
#define TP_IOC_GET_PID_STATUS           _IOWR(TP_IOC_MAGIC,TP_PID_START+3, TP_IOC_PID_FILTER_T*)
#define TP_IOC_SET_PIDEN             _IOW(TP_IOC_MAGIC,TP_PID_START+4, TP_IOC_SET_PIDEN_T*)


/*  Section filter */
#define TP_IOC_ADD_SECTION_FILTER           _IOWR(TP_IOC_MAGIC,TP_SECTION_START, TP_IOC_ADD_SECTION_FILTER_T*)
#define TP_IOC_REMOVE_SECTION_FILTER        _IOW(TP_IOC_MAGIC,TP_SECTION_START+1, TP_IOC_REMOVE_SECTION_FILTER_T*)
#define TP_IOC_REMOVE_ALL_SECTION           _IOW(TP_IOC_MAGIC,TP_SECTION_START+2, TP_IOC_BASIC_T*)
#define TP_IOC_GET_SECTION_STATUS           _IOWR(TP_IOC_MAGIC,TP_SECTION_START+3, TP_IOC_GET_SECTION_STATUS_T*)
#define TP_IOC_GET_SECTION_DATA            _IOWR(TP_IOC_MAGIC,TP_SECTION_START+4, TP_IOC_GET_SECTION_DATA_T*)

/* PCR tracking */
#define TP_IOC_PCR_TRACKING_EN              _IOW(TP_IOC_MAGIC,TP_PCR_START, TP_IOC_PCR_TRACKING_EN_T*)
#define TP_IOC_GET_PCR_TRACKING             _IOWR(TP_IOC_MAGIC,TP_PCR_START+1, TP_IOC_GET_PCR_TRACKING_T*)
#define TP_IOC_RESET_PCR_TRACKING           _IOW(TP_IOC_MAGIC,TP_PCR_START+2, TP_IOC_BASIC_T*)

/* Descrambler APIs */
#define TP_IOC_DESCRAMBLE_ALGORITHM         _IOW(TP_IOC_MAGIC,TP_DESCRAMBLER_START, TP_IOC_DESCRAMBLE_ALGORITHM_T*)
#define TP_IOC_SET_CW                       _IOW(TP_IOC_MAGIC,TP_DESCRAMBLER_START+1, TP_IOC_SET_CW_T*)
#define TP_IOC_DESCRAMBLE_CONTROL           _IOW(TP_IOC_MAGIC,TP_DESCRAMBLER_START+2, TP_IOC_DESCRAMBLE_CONTROL_T*)
#define TP_IOC_SET_ENCRYPTION              _IOW(TP_IOC_MAGIC,TP_DESCRAMBLER_START+3, TP_IOC_SET_ENCRYPTION_T*)

/* Start Code APIs */
#define TP_IOC_STARTCODE_ENABLE          _IOW(TP_IOC_MAGIC,TP_STARTCODE_START, TP_IOC_STARTCODE_ENABLE_T*)
#define TP_IOC_STARTCODE_SET_PID         _IOW(TP_IOC_MAGIC,TP_STARTCODE_START+1, TP_IOC_STARTCODE_SET_PID_T*)
#define TP_IOC_STARTCODE_SET_BUFFER       _IOW(TP_IOC_MAGIC,TP_STARTCODE_START+2, TP_IOC_STARTCODE_SET_BUFFER_T*)
#define TP_IOC_STARTCODE_FLUSH             _IOW(TP_IOC_MAGIC,TP_STARTCODE_START+3, TP_IOC_BASIC_T*)
#define TP_IOC_STARTCODE_READ_INFO        _IOWR(TP_IOC_MAGIC,TP_STARTCODE_START+4, TP_IOC_STARTCODE_READ_INFO_T*)
#define TP_IOC_STARTCODE_RELEASE_INFO       _IOW(TP_IOC_MAGIC,TP_STARTCODE_START+5, TP_IOC_STARTCODE_RELEASE_INFO_T*)

/* TPP APIs */
#define TP_IOC_TPP_SET_MODE          _IOW(TP_IOC_MAGIC,TP_CIPLUS_START, TP_IOC_TPP_MODE_T*)
#define TP_IOC_TPP_GET_MODE          _IOWR(TP_IOC_MAGIC,TP_CIPLUS_START+1, TP_IOC_TPP_MODE_T*)
#define TP_IOC_TPP_SET_PIDEN          _IOW(TP_IOC_MAGIC,TP_CIPLUS_START+2, TP_IOC_TPP_SET_PIDEN_T*)
#define TP_IOC_TPP_STREAM_CONTROL         _IOW(TP_IOC_MAGIC,TP_CIPLUS_START+3, TP_IOC_TPP_STREAM_CONTROL_T*)
#define TP_IOC_GET_TPP_BUF_STATUS       _IOWR(TP_IOC_MAGIC,TP_CIPLUS_START+4, TP_IOC_GET_TPP_BUF_STATUS_T*)
#define TP_IOC_TPP_RINGBUFF_FLUSH        _IOW(TP_IOC_MAGIC,TP_CIPLUS_START+5, TP_IOC_TPP_BASIC_T*)
#define TP_IOC_SET_TPP_SYNC_REPLACE        _IOW(TP_IOC_MAGIC,TP_CIPLUS_START+6, TP_IOC_SET_TPP_SYNC_REPLACE_T*)

/* get debug message */
#define TP_IOC_TRACK_ERR_PACKET             _IOWR(TP_IOC_MAGIC,TP_MISC_START, TP_IOC_TRACK_ERR_PACKET_T*)
#define TP_IOC_READ_WRITE_REG    _IOWR(TP_IOC_MAGIC,TP_MISC_START+1, TP_REG_RW_T*)
#define TP_IOC_GET_HARDWARE_INFO           _IOWR(TP_IOC_MAGIC,TP_MISC_START+2, TPK_HARDWARE_INFO_T*)
#define TP_IOC_DUMP_REG_INFO           _IOWR(TP_IOC_MAGIC,TP_MISC_START+3, TPK_DUMP_REG_INFO_T*)

#endif  /* __TP_IOCTL_H__ */

