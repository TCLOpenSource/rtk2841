#ifndef __TP_REG_CTRL_H__
#define __TP_REG_CTRL_H__

#include <tp/tp_def.h>

#define BYTE3(x)        ((x>>24) & 0xFF)
#define BYTE2(x)        ((x>>16) & 0xFF)
#define BYTE1(x)        ((x>> 8) & 0xFF)
#define BYTE0(x)        (x       & 0xFF)

#define BUFFER_WRITE_MASK_LIMIT _BIT3
#define BUFFER_WRITE_MASK_BASE  _BIT2
#define BUFFER_WRITE_MASK_RP    _BIT1
#define BUFFER_WRITE_MASK_WP    _BIT0
#define BUFFER_WRITE_MASK_NONE  _ZERO
#define BUFFER_WRITE_MASK_ALL  (BUFFER_WRITE_MASK_LIMIT | BUFFER_WRITE_MASK_BASE | BUFFER_WRITE_MASK_RP | BUFFER_WRITE_MASK_WP)

#define BUF_SEL_MASS_DATA   _BIT0
#define BUF_SEL_INFO_PACK   _BIT1
#define BUF_SEL_SECTION     _BIT2
#define BYTE_TO_LONG(w, x, y, z) ((w<<24)+(x<<16)+(y<<8)+z)

#define PID_NO_UPDATE         0
#define PID_UPDATE_PARAM      1
#define PID_ADD               2

#define SECTION_ASM_TIMEOUT     1      /* wait 1 ms */
#define TP_DBG_TIMEOUT          1      /* wait 1 ms */

#define TPK_CW_LENGTH           8

/* TP buffer flag */
#define TP_BUFFER_MASS_DATA     0
#define TP_BUFFER_SECTION       1
#define TP_BUFFER_INFO_PACK     2
#define TP_BUFFER_STARTCODE     3


#define FORMAT_TP_INFO         0x00
#define FORMAT_AF_INFO         0x01
#define FORMAT_SEC_INFO        0x02
#define FORMAT_UNKNOWN_INFO    0xFF

#define FORMAT_PES_INFO        0x80     /* for RTD299X */
#define FORMAT_PTS_INFO        0x81     /* for RTD299X */
#define FORMAT_DTS_INFO        0x82     /* for RTD299X */

#define FORMAT_AF_INFO1        0x11     /* AF1 INFO that with High 32 bits STC */
#define FORMAT_SEC_INFO_V2     0x12     /* for RTD294X that with version 2 sec info pack */

#define SEC_CRC_CORRECT     0
#define SEC_CRC_ERR         1
#define SEC_NO_CRC_CHECK    2

#define INT_ADF_PCR_IN      _BIT4

#define STC_PCR_TOLERANCE 5000

#ifdef CAM_SRC_CHANGE_BASE_ON_TP_INPUT_COUNT
#define TPINPUT_MONITOR_TPID         TP_TP3
#endif


#define CHECK_MAX_TPI_COUNT(tpi)    \
{ \
        if(tpi >= MAX_TPI_COUNT) \
        { \
                TP_WARNING("bad parameter, tpi=%u\n", tpi); \
                return TPK_BAD_PARAMETER; \
        } \
}

#define CHECK_MAX_TP_COUNT(tp_id)    \
{ \
        if(tp_id >= MAX_TP_COUNT) \
        { \
                TP_WARNING("bad parameter, tp_id=%u\n", tp_id); \
                return TPK_BAD_PARAMETER; \
        } \
}

#define CHECK_MAX_TPP_COUNT(tpp_id)    \
{ \
        if(tpp_id >= MAX_TP_P_COUNT) \
        { \
                TP_WARNING("bad parameter, tpp_id=%u\n", tpp_id); \
                return TPK_BAD_PARAMETER; \
        } \
}

#define CHECK_MAX_KEY_COUNT(cnt)    \
{ \
        if(cnt >= MAX_KEY_COUNT) \
        { \
                TP_WARNING("bad parameter, key_set=%u\n",cnt); \
                return TPK_BAD_PARAMETER; \
        } \
}


#define CHECK_MTP_IS_START(id)    \
{ \
        if(pTp_drv->mtp[id].mtp_stream_status !=MTP_STREAM_START)    \
        {   \
                udelay(10);     \
                _tp_unlock();   \
                TP_WARNING("mtp_id[%u] stream did not start yet\n", id); \
                return TPK_NOT_SET; \
        }   \
}

#define CHECK_MTP_BUF_VALID(mtp_id)    \
{ \
        if(pTp_drv->mtp[mtp_id].valid != 1)   \
        {   \
                _tp_unlock();   \
                TP_WARNING("mtp_id[%u] does not set buffer yet\n", mtp_id);  \
                return TPK_NOT_SET; \
        }   \
}

#define CHECK_MTP_ID(mtp_id)    \
{ \
        if(mtp_id >= MAX_MTP_COUNT) \
        { \
                TP_WARNING("bad parameter, mtp_id=%u\n", mtp_id); \
                return TPK_BAD_PARAMETER; \
        } \
}


#define CHECK_MAX_TPOUT_COUNT(tpout_id)    \
{ \
        if(tpout_id >= MAX_TPOUT_COUNT) \
        { \
                TP_WARNING("bad parameter, tpout_id=%u\n", tpout_id); \
                return TPK_BAD_PARAMETER; \
        } \
}



#define CHECK_MAX_TP_COUNT_RT_VOID(id)    \
{ \
        if(id >= MAX_TP_COUNT) \
        { \
                TP_WARNING("bad parameter, tp_id=%u\n", id); \
                return ; \
        } \
}

#define CHECK_MAX_TP_COUNT_RT_NULL(id)    \
{ \
        if(id >= MAX_TP_COUNT) \
        { \
                TP_WARNING("bad parameter, tp_id=%u\n", id); \
                return NULL; \
        } \
}

#define RESET_SECTION_ASSEMBLE_BUF(P_SEC)    \
{ \
        P_SEC->sec_data_cnt   = 0;      \
        P_SEC->sec_expect_len = 0;    \
}

#define GET_BUFF_SIZE(buf_param)            (buf_param.Limit - buf_param.Base)
#define GET_BUFF_DATA_SIZE(buf_param)       ((buf_param.RP > buf_param.WP) ? (buf_param.Limit - buf_param.RP) :  (buf_param.WP - buf_param.RP))
#define GET_BUFF_DATA_ALL_SIZE(buf_param)   ((buf_param.RP > buf_param.WP) ? ((buf_param.Limit - buf_param.RP)+(buf_param.WP-buf_param.Base)) :  (buf_param.WP - buf_param.RP))
#define CHECK_RD_BUF_STATUS(result)         ((result==TPK_SUCCESS)||(result==TPK_BUFFER_FULL))
#define CHECK_RD_BUF_STATUS_ERR(result)     ((result!=TPK_SUCCESS)&&(result!=TPK_BUFFER_FULL))

#define TP_GET_TIME_CNT(time_cnt, new_t, saved_t) \
        time_cnt = (new_t.tv_sec >= saved_t.tv_sec) ? \
                   ((new_t.tv_sec - saved_t.tv_sec) * 1000) : \
                   ((new_t.tv_sec + (0xffffffff - saved_t.tv_sec)) * 1000); \
        time_cnt += ((new_t.tv_usec - saved_t.tv_usec) / 1000)


#define CHECK_MAX_TS_COUNT(id)    \
{ \
        if(id >= MAX_TS_COUNT) \
        { \
                TP_WARNING("bad parameter, ts_id=%u\n",id); \
                return TPK_BAD_PARAMETER; \
        } \
}

#define CHECK_MAX_TP_P_COUNT(tp_p_id)    \
{ \
        if(tp_p_id >= MAX_TP_P_COUNT) \
        { \
                TP_WARNING("bad parameter, tp_p_id=%u\n", tp_p_id); \
                return TPK_BAD_PARAMETER; \
        } \
}

#define CHECK_MAX_BUFFER_COUNT(buf_idx)    \
{ \
        if(buf_idx > TP_BUFFER_MAX_COUNT) \
        { \
                TP_WARNING("bad parameter, buf_idx=%u\n", buf_idx); \
                return TPK_BAD_PARAMETER; \
        } \
}

#define CHECK_MAX_BUFFER_COUNT_RT_VOID(buf_idx)    \
{ \
        if(buf_idx > TP_BUFFER_MAX_COUNT) \
        { \
                TP_WARNING("bad parameter, buf_idx=%u\n", buf_idx); \
                return; \
        } \
}

#define CHECK_TPP_MAX_BUFFER_COUNT(buf_idx)    \
{ \
        if(buf_idx > TPP_BUFFER_MAX_COUNT) \
        { \
                TP_WARNING("bad parameter, buf_idx=%u\n", buf_idx); \
                return TPK_BAD_PARAMETER; \
        } \
}

#define CHECK_MAX_PID_FILTER_COUNT(pid_idx)    \
{ \
        if(pid_idx >= MAX_PID_FILTER_COUNT) \
        { \
                TP_WARNING("pid_idx=%u not support\n", pid_idx); \
                return TPK_BAD_PARAMETER; \
        } \
}

#define CHECK_MAX_PID_PER_FILTER_COUNT(pid_idx)    \
{ \
        if(pid_idx >= MAX_PID_PER_TP) \
        { \
                TP_WARNING("pid_idx=%u not support of per TP\n", pid_idx); \
                return TPK_BAD_PARAMETER; \
        } \
}


#define CHECK_MAX_SEC_FILTER_COUNT(sec_idx)    \
{ \
        if(sec_idx >= MAX_SEC_COUNT) \
        { \
                TP_WARNING("sec_idx (%u) over limitation (%u)\n", sec_idx, MAX_SEC_COUNT); \
                return TPK_BAD_PARAMETER; \
        } \
}


/* enum value */
typedef enum {
        RP_FLUSH_TO_BASE = 0,   /* move both RP and WP to BASE */
        RP_FLUSH_TO_WP,         /* move RP to WP */
} RP_FLUSH_MODE_T;

/* structure */
typedef struct {
        UADDRESS           Limit;
        UADDRESS           Base;
        UADDRESS           RP;
        UADDRESS           WP;
} TP_BUFFER_PARAM_T;

typedef struct {
        UINT8 format;
        UADDRESS pointer_vir;
        UADDRESS pointer_phy;
        UADDRESS tsp_hdr_vir;
        UADDRESS tsp_hdr_phy;
        UINT16 PID;
        UINT8 pid_idx_reg;
        UINT8 pid_idx;
        UINT8 section_length;   /*  sub section length */
        UINT8 tail_status;
        UINT8 header_status;
        UINT8 match_id;         /* matched section index.  it's not correct in rtd294x+ (MSB 2 bits is missing), do not use this field */
} SEC_INFO_T;



typedef struct {
        UINT8 serial: 1;                /* 0:parallel, 1:serial */
        UINT8 data_order: 1;            /* 0:MSB(bit7), 1:LSB(bit0), e.g. 0x47='b01000111 or 'b11100010 */
        UINT8 datapin: 1;               /* 0:LSB(D0), 1:LSB(D7) */

        UINT8 sync_byte;                /* default:0x47 */
        TPK_TSP_LEN_T packet_size;
} TP_INPUT_INTERFACE_PARAM_T;


typedef struct TP_REGISTER {
        char name[32];
        unsigned int address;
} TP_REGISTER;

/* basic function */
void Tp_Write_Data_Reg_Write(UADDRESS reg, UINT32 data);
INT32 Tp_SetTpCtrlReg(TPK_TP_ENGINE_T tp_id, UINT32 bit_sel, UINT8 data);
UINT32 BYTES_TO_LONG(UINT8* pData, UINT8 Len);


/* init function */
void Tp_Rst_Ring_Buffer_Avail(void);
void Tp_Rst_Ring_Buffer_Full(void);
void Tp_Clean_Ring_Buffer_Reg(void);
void Tp_Clean_PID_Filter_Reg(void);
void Tp_Clean_Section_Filter_Reg(void);
void Tp_Clean_Packet_Count_Reg(void);
void Tp_GlobalHardwareReset(void);
INT32 Tp_rst(TPK_TP_ENGINE_T tp_id);
INT32 Tp_init(TPK_TP_ENGINE_T tp_id);
INT32 Tp_uninit(TPK_TP_ENGINE_T tp_id);
INT32 Tp_ResetCounter(TPK_TP_ENGINE_T tp_id);

/* TP ENG */
INT32 Tp_ENG_FrameEnable( TPK_TP_ENGINE_T tp_id, BOOL enable );
INT32 Tp_ENG_SetInputInterface( TPK_TP_ENGINE_T tp_id, TP_INPUT_INTERFACE_PARAM_T tp_if_param );
INT32 Tp_ENG_TwoBitsModeEnable( TPK_TP_ENGINE_T tp_id, BOOL enable );
INT32 Tp_ENG_RawModeEnable( TPK_TP_ENGINE_T tp_id, BOOL enable);
INT32 Tp_ENG_SetSyncReplace( TPK_TP_ENGINE_T tp_id, UINT8 sync_byte );

/* TP setting function */
INT32 Tp_SetInputPol(TPK_TPI_PIN_T tpi, TPK_TP_INPUT_PARAM_T pol);


/* ring buffer control */
UINT8* Tp_Buf_Vir_to_Phy(TPK_TP_ENGINE_T tp_id, UINT8 buffer_flag, UINT8* pVirAddr);
UINT8* Tp_Buf_Phy_to_Vir(TPK_TP_ENGINE_T tp_id, UINT8 buffer_flag, UINT8* pPhyAddr);
INT32 Tp_Set_Buffer(UINT8 buf_idx, TP_BUFFER_PARAM_T param, UINT8 write_mask);
INT32 Tp_Get_Buffer(UINT8 buf_idx, TP_BUFFER_PARAM_T* param);
INT32 Tp_Set_Buffer_Avail_status(UINT8 buf_idx, UINT8 data);
INT32 Tp_Set_Buffer_Full_status(UINT8 buf_idx, UINT8 data);
INT32 Tp_Get_Buffer_Full_status(UINT8 buf_idx, UINT8* data);
INT32 Tp_Set_Buffer_Avail_int_En(UINT8 buf_idx, UINT8 Enable);
INT32 Tp_Set_Buffer_Avail_int_En(UINT8 buf_idx, UINT8 Enable);
INT32 Tp_flush_Buf(TPK_TP_ENGINE_T tp_id, UINT8 stop_stream_before_flush, UINT32 buffer_sel);
INT32 Tpp_Get_Buffer(UINT8 buf_idx, TP_BUFFER_PARAM_T* param);
UINT32 Tp_Check_WP_Alignment(UINT8 buf_idx, UINT32 block_size);
void Tp_Update_Buffer_RP(TPK_TP_ENGINE_T tp_id, UINT8 buf_idx, TPK_TP_BUF_T *pBuf_status);
INT32 TP_ReadData(TPK_TP_ENGINE_T tp_id, UINT8** ppReadPhyPtr, UINT32* pContinueReadSize, UINT32 Threshold, UINT8 buffer_flag);
INT32 TP_ReleaseData(TPK_TP_ENGINE_T tp_id, UINT8* pReadPhyPtr, UINT32 Size, UINT8 buffer_flag);

/* MTP control */
INT32 Tp_SetMemoryMode(TPK_TP_ENGINE_T tp_id, UINT8 Mem_mode_en);
INT32 Tp_Get_MTP_Buffer(TPK_TP_MTP_T mtp_id, TP_BUFFER_PARAM_T* param);
INT32 TP_MTPStreamControl(TPK_TP_MTP_T mtp_id, TPK_MTP_STREAM_CTRL_T ctrl);

/* pid filter control */
INT32 Tp_SetPidParam(UINT16 pid_idx, TPK_PID_REG_PARAM_T Param);
INT32 Tp_GetPidParam(UINT16 pid_idx, TPK_PID_REG_PARAM_T* pParam);

INT32 Tp_Remove_PID(TPK_TP_ENGINE_T tp_id, UINT16 pid_idx);
INT32 Tp_AddPIDFilter( TPK_TP_ENGINE_T tp_id, TPK_PID_FILTER_PARAM_T PIDParm, void* file_handle);
INT32 Tp_RemovePIDFilter( TPK_TP_ENGINE_T tp_id, UINT16 PID,  void* file_handle);
INT32 Tp_Get_MaxPID_Cnt(TPK_TP_ENGINE_T tp_id, UINT16 *pMax_PID_Cnt);
INT32 Tp_Dump_PID_filter_Status(TPK_TP_ENGINE_T tp_id, UINT16 pid_idx);
INT32 Tp_Cmd_Dump_PID_filter_Status(TPK_TP_ENGINE_T tp_id, char *buffer);
TPK_SEC_REG_T Tp_Cmd_Dump_Section_filter_Status(char *buffer, UINT32 sec_idx);

/* section filter control */
INT32 Tp_Get_MaxSec_Cnt(TPK_TP_ENGINE_T tp_id, UINT16 *pMax_Sec_Cnt);
INT32 Tp_SetSecParam(UINT16 sec_idx, TPK_SEC_REG_T sec_reg);
INT32 Tp_GetPID_FirstSecFilter(TPK_TP_ENGINE_T tp_id, UINT16 PID, UINT16 *pSec_idx);
INT32 Tp_GetPID_LastSecFilter(TPK_TP_ENGINE_T tp_id, UINT16 PID, UINT16 *pSec_idx);
INT32 Tp_AddSecFilter(TPK_TP_ENGINE_T tp_id, TPK_SEC_FILTER_PARAM_T Param, void* file_handle, void** ppSec_handle);
INT32 Tp_RemoveSectionFilter(TPK_TP_ENGINE_T tp_id, void* pSec_handle);
INT32 section_assemble_thread_start_stop(UINT8 thread_en);
INT32 tp_dbg_thread_start_stop(UINT8 enable);
INT32 Tp_Dump_Section_List(TPK_TP_ENGINE_T tp_id, UINT16 pid_idx);

/* PCR tracking */
INT32 Tp_ResetPCRStatus(TPK_TP_ENGINE_T tp_id);
INT32 Tp_PCRTrackingEnable(TPK_TP_ENGINE_T tp_id, UINT8 On, UINT16 PID, TPK_PCR_CLK_SRC_T clk_src);
INT32 Tp_GetPCRTrackingStatus(TPK_TP_ENGINE_T tp_id, UINT64* pPCR, UINT64* pSTC, UINT64* pPCRBase, UINT64* pSTCBase);
INT32 Tp_UpdatePCRTrackingStatus(TPK_TP_ENGINE_T tp_id);

/* Descramble API */
INT32 TP_SetCW( TPK_TP_ENGINE_T tp_id, UINT8 id, UINT8 ofst, UINT32 cw_h, UINT32 cw_l);
UINT32 BYTES_TO_LONG(UINT8* pData, UINT8 Len);

/* FRC API */
INT32 Tp_FRC_Enable( TPK_TP_ENGINE_T tp_id, BOOL enable );
INT32 Tp_FRC_SetRate( TPK_TP_ENGINE_T tp_id, TPK_FRC_RATE_T rate );
INT32 Tp_FRC_SetPrefix( TPK_TP_ENGINE_T tp_id, TPK_FRC_PREFIX_T prefix_sel, UINT32 meta_data);

/* TPO  API */
INT32 Tp_TPO_Init(UINT8 tpout_id);
INT32 Tp_TPO_GetClkRate( INT32 * tpo_clk_rate );
INT32 Tp_TPO_SetClkDiv( UINT32 pre_div, UINT32 post_div );
INT32 Tp_TPO_GetClkDiv(UINT32 *pre_div, UINT32 *post_div);
INT32 Tp_TPO_SetMode(UINT8 tpout_id, TPK_TPOUT_TS_PARAM_T   Param);
INT32 Tp_TPO_GetMode(UINT8 tpout_id, TPK_TPOUT_TS_PARAM_T *pParam);
INT32 Tp_TPO_SetDataSource(TPK_TP_SOURCE_T src_type);
INT32 Tp_TPO_StreamControl( UINT8 tpout_id, TPK_TPOUT_STREAM_CTRL_T ctrl);



INT32 Tp_Update_PIDFilter_predes( TPK_TP_ENGINE_T tp_id,  UINT8 predes_value);

INT32 Tp_is_SupportPatternSearch( TPK_TP_ENGINE_T tp_id);
INT32 Tp_SetPatternSearchPID( TPK_TP_ENGINE_T tp_id, UINT16 PID);
INT32 Tp_SetPatternSearchEnable( TPK_TP_ENGINE_T tp_id, UINT8 enable_value);
INT32 Tp_SetPatternSearchInfoBuffer( TPK_TP_ENGINE_T tp_id, UINT8* pPhyAddr, UINT8* pVirAddr, UINT32 size, UINT8* pSharedRP, UINT8* pSharedWP);
INT32 Tp_FlushPatternSearch( TPK_TP_ENGINE_T tp_id);

/* debug function */
INT32 Tp_TrackErrorPacket( TPK_TP_ENGINE_T tp_id, UINT64 *pPkt, UINT64 *pDropPkt, UINT64 *pErrPkt);
INT32 Tp_DumpTPRegister(char *str);
INT32 TP_DisplayTPFramerInformation(TPK_TP_ENGINE_T tp_id);

INT32 Tp_GetTpCtrlReg(TPK_TP_ENGINE_T tp_id, UINT32 *data);
INT32 Tp_GetTpFrmReg(TPK_TP_ENGINE_T tp_id, UINT32 *data);



UINT32 Tp_Get_MTPFrameControlStatus(TPK_TP_ENGINE_T tp_id, UINT8 *fr_status);
UINT32 Tp_Get_PrefixStatus(TPK_TP_ENGINE_T tp_id, UINT8 *keep, UINT8 *prefix_sel);
INT32 Tp_SetPIDEncryption( TPK_TP_ENGINE_T tp_id, UINT16 PID, UINT8 keytype);


/* TPP */
INT32 Tp_TPP_Init(TPK_TPP_ENGINE_T tpp_id);
INT32 Tp_TPP_SetCtrlReg(TPK_TPP_ENGINE_T tpp_id, UINT32 bit_sel, UINT8 data);
INT32 Tp_TPP_GetCtrlReg(TPK_TPP_ENGINE_T tpp_id, UINT32 *data);
INT32 Tp_TPP_SetFrmReg(TPK_TPP_ENGINE_T tpp_id, UINT32 data);
INT32 Tp_TPP_GetFrmReg(TPK_TPP_ENGINE_T tpp_id, UINT32 *data);
INT32 Tp_TPP_MassBuffInit(TPK_TPP_ENGINE_T tpp_id);
void  Tp_TPP_CheckRingBuffer(void);
INT32 Tp_TPP_FlushBuf(TPK_TPP_ENGINE_T tpp_id);
INT32 Tp_TPP_ResetCounter(TPK_TPP_ENGINE_T tpp_id);
INT32 Tp_TPP_SetSyncReplace(TPK_TPP_ENGINE_T tpp_id, UINT8 sync_byte );
INT32 Tp_TPP_SetDataSource(TPK_TPP_ENGINE_T tpp_id, TPK_TP_SOURCE_T remux_src);
INT32 Tp_TPP_TrackErrorPacket( TPK_TPP_ENGINE_T tpp_id, UINT64 *pPkt, UINT64 *pDropPkt);
INT32 Tp_TPP_TPOutControl(TPK_TPP_ENGINE_T tpp_id, UINT8 on );
#ifdef CAM_SRC_CHANGE_BASE_ON_TP_INPUT_COUNT
INT32 TP_TPInput_Monitor_Init(TPK_TP_ENGINE_T tp_id);
INT32 TP_TPInput_Monitor_Uninit(TPK_TP_ENGINE_T tp_id);
#endif







#endif      /*  __TP_REG_CTRL_H__ */

