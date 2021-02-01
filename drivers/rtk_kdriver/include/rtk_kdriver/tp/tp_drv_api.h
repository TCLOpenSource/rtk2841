#ifndef __TP_DRV_API_H__
#define __TP_DRV_API_H__

#define TP_KERNEL_DRIVER

/* function parameter input/output comment */
#define IN
#define OUT
#define IN_OUT

/* define return code */
#define TPK_SUCCESS                 0
#define TPK_FAIL                    -1
#define TPK_BUFFER_FULL             -2
#define TPK_BUFFER_UNALIGNMENT      -3
#define TPK_BUFFER_EMPTY            -4
#define TPK_BAD_PARAMETER           -5
#define TPK_TIMEOUT                 -6
#define TPK_NOT_ENOUGH_RESOURCE     -7
#define TPK_NOT_SUPPORT             -8
#define TPK_NOT_INIT                -9
#define TPK_RESOURCE_CONFLICT       -10
#define TPK_BUFFER_UNDER_THRESHOLD  -11
#define TPK_ERROR_HANDEL            -12
#define TPK_NOT_SET                 -13
#define TPK_DATA_OUT_OF_RANGE       -14
#define TPK_SECTION_DATA_ERROR      -15

/* TP driver interface */
/* TP APIs */
TP_EXTERN INT32 RHAL_TPInit(IN TPK_TP_ENGINE_T tp_id);
TP_EXTERN INT32 RHAL_TPUninit(IN TPK_TP_ENGINE_T tp_id);
TP_EXTERN INT32 RHAL_SetTPMode(IN TPK_TP_ENGINE_T tp_id, IN TPK_TP_TS_PARAM_T Param);
TP_EXTERN INT32 RHAL_SetTPSource(IN TPK_TP_ENGINE_T tp_id, IN TPK_TP_SOURCE_T tp_src, IN TPK_CAS_TYPE_T casType);
TP_EXTERN INT32 RHAL_TPFlushBuffer(IN TPK_TP_ENGINE_T tp_id);
TP_EXTERN INT32 RHAL_SetTPRingBuffer(IN TPK_TP_ENGINE_T tp_id, IN UINT8* pPhyAddr, IN UINT8* pVirAddr, IN UINT32 size);
TP_EXTERN INT32 RHAL_DumpTPRingBuffer(IN TPK_TP_ENGINE_T tp_id, IN UINT8 enable, IN UINT8* pSharedRP, IN UINT8* pSharedWP);
TP_EXTERN INT32 RHAL_GetTPBufferStatus(IN TPK_TP_ENGINE_T tp_id, OUT UINT32* pBufferSize, OUT UINT32* pDataSize);
TP_EXTERN INT32 RHAL_TPStreamControl(IN TPK_TP_ENGINE_T tp_id, IN TPK_TP_STREAM_CTRL_T ctrl);
TP_EXTERN INT32 RHAL_TPReadData(IN TPK_TP_ENGINE_T tp_id, OUT UINT8** ppReadPhyPtr, OUT UINT32 * pContinueReadSize, IN UINT32 Threshold);
TP_EXTERN INT32 RHAL_TPReleaseData(IN TPK_TP_ENGINE_T tp_id, IN UINT8* pReadPhyPtr, IN UINT32 Size);
TP_EXTERN INT32 RHAL_SetInputSourcePol(IN TPK_TPI_PIN_T tpi, IN TPK_TP_INPUT_PARAM_T pol);

/* TPOUT APIs */
TP_EXTERN INT32 RHAL_TPOUTSetMode(IN UINT8 tpout_id, IN TPK_TPOUT_TS_PARAM_T Param);
TP_EXTERN INT32 RHAL_TPOUTGetMode(IN UINT8 tpout_id, IN TPK_TPOUT_TS_PARAM_T *pParam);
TP_EXTERN INT32 RHAL_TPOUTSetDataSource(IN UINT8 tpout_id, IN TPK_TPOUT_SOURCE_T tpout_src, TPK_TPOUT_REMUX_PARAM_T *remux_param);
TP_EXTERN INT32 RHAL_TPOUTStreamControl(IN UINT8 tpout_id, IN TPK_TPOUT_STREAM_CTRL_T ctrl);
TP_EXTERN INT32 RHAL_TPOUTClockSpeed(IN UINT8 tpout_id, IN UINT32 pre_div, IN UINT32 post_div);

/* MTP APIs */
TP_EXTERN INT32 RHAL_SetMTPBuffer(IN TPK_TP_MTP_T mtp_id, IN UINT8* pPhyAddr, IN UINT8* pVirAddr, IN UINT32 size);
TP_EXTERN INT32 RHAL_WriteMTPBuffer(IN TPK_TP_MTP_T mtp_id, IN UINT8* pPhyWP, IN UINT32 ContinueWrite);
TP_EXTERN INT32 RHAL_GetMTPBufferStatus(IN TPK_TP_MTP_T mtp_id, OUT UINT8** ppWritePhyPtr, OUT UINT32* pContinueWriteSize, OUT UINT32* pWritableSize);
TP_EXTERN INT32 RHAL_MTPStreamControl(IN TPK_TP_MTP_T mtp_id, IN TPK_MTP_STREAM_CTRL_T ctrl);
TP_EXTERN INT32 RHAL_MTPFlushBuffer(IN TPK_TP_MTP_T mtp_id, IN MTP_BUFF_FLUSH_MODE_T mode);
TP_EXTERN INT32 RHAL_MTPFrameControl(IN TPK_TP_MTP_T mtp_id, IN UINT8 enable);

/* TPP APIs */
TP_EXTERN INT32 RHAL_SetTPPMode(IN TPK_TPP_ENGINE_T tpp_id, IN TPK_TPP_TS_PARAM_T Param);
TP_EXTERN INT32 RHAL_GetTPPMode(IN TPK_TPP_ENGINE_T tpp_id, OUT TPK_TPP_TS_PARAM_T *pParam);
TP_EXTERN INT32 RHAL_TPPStreamControl(IN TPK_TPP_ENGINE_T tpp_id, IN TPK_TPP_STREAM_CTRL_T ctrl);
TP_EXTERN INT32 RHAL_GetTPPBufferStatus(IN TPK_TPP_ENGINE_T tpp_id, OUT UINT32 * pBufferSize, OUT UINT32 * pDataSize);
TP_EXTERN INT32 RHAL_TPPFlushBuffer(IN TPK_TPP_ENGINE_T tpp_id);
TP_EXTERN INT32 RHAL_EnableTPPPIDFilter(IN TPK_TPP_ENGINE_T tpp_id, IN UINT8 on);

/* PID filter APIs */
TP_EXTERN INT32 RHAL_AddPIDFilter(IN TPK_TP_ENGINE_T tp_id, IN TPK_PID_FILTER_PARAM_T PIDParm, IN void* file_handle);
TP_EXTERN INT32 RHAL_RemovePIDFilter(IN TPK_TP_ENGINE_T tp_id, IN UINT16 PID, IN void* file_handle);
/* For RHAL_RemoveAllPIDFilters(), if file_handle=REGARDLESS_OF_FILE_HANDLE, it will remove all of PID filter regardless of file_handle control */
TP_EXTERN INT32  RHAL_RemoveAllPIDFilters(IN TPK_TP_ENGINE_T tp_id, IN void* file_handle);
TP_EXTERN INT32 RHAL_GetPIDFilterStatus(IN TPK_TP_ENGINE_T tp_id, IN UINT16 PID_Buf_Cnt, OUT TPK_PID_FILTER_PARAM_T* pPIDParm, OUT UINT16* pPIDLen);
TP_EXTERN INT32 RHAL_EnablePIDFilter(IN TPK_TP_ENGINE_T tp_id, IN UINT8 on);


/* Section filter APIs */
TP_EXTERN INT32 RHAL_AddSectionFilter(IN TPK_TP_ENGINE_T tp_id, IN  TPK_SEC_FILTER_PARAM_T Param, IN void* file_handle, OUT void** ppSec_handle);
TP_EXTERN INT32 RHAL_RemoveSectionFilter(IN TPK_TP_ENGINE_T tp_id, IN void* pSec_handle);
/* For RHAL_RemoveAllSectionFilters(), if file_handle=REGARDLESS_OF_FILE_HANDLE, it will remove all of Section filter regardless of file_handle control */
TP_EXTERN INT32 RHAL_RemoveAllSectionFilters(IN TPK_TP_ENGINE_T tp_id, IN void* file_handle);
TP_EXTERN INT32 RHAL_GetSectionFilterStatus(IN TPK_TP_ENGINE_T tp_id, IN UINT16 Sec_Buf_cnt, OUT TPK_SEC_FILTER_STATUS_T* pSecStatus, OUT UINT16* usSecLen);

/* PCR tracking */
/* tracking disable:  MISC_90KHz */
/* tracking enable:  TP_LOCAL_90KHz */
TP_EXTERN INT32 RHAL_PCRTrackingEnable(IN TPK_TP_ENGINE_T tp_id, IN UINT8 On, IN UINT16 PID, IN TPK_PCR_CLK_SRC_T clk_src);
TP_EXTERN INT32 RHAL_GetPCRTrackingStatus(IN TPK_TP_ENGINE_T tp_id, OUT UINT64* pPCR, OUT UINT64* pSTC, OUT UINT64* pPCRBase, OUT UINT64* pSTCBase);
TP_EXTERN INT32 RHAL_ResetPCRTrackingStatus(IN TPK_TP_ENGINE_T tp_id);

/* Descrambler APIs */
TP_EXTERN INT32 RHAL_SetDescrambleAlgorithm(IN TPK_TP_ENGINE_T tp_id, IN TPK_DESCRAMBLE_ALGORITHM_T algo);

/* Start Code Search */
TP_EXTERN INT32 RHAL_SetTPPatternSearchInfoBuffer(IN UINT8 tp_id, IN UINT8* pPhyAddr, IN UINT8* pVirAddr, IN UINT32 size, IN UINT8* pSharedRP, IN UINT8* pSharedWP);
TP_EXTERN INT32 RHAL_SetTPPatternSearchPID(IN UINT8 tp_id, IN UINT16 PID);

/* Debug */
INT32 RHAL_DumpTPRegister(char *str);

/******************************************************
   Multi2 set key flow:
   1. set system key:
   (1) key_id = TP_SETCW_KEYID_MULTI2_SYS_KEY
   (2) system key field into Key[TPK_MAX_KEY_LENGTH] (32 bytes)
   RHAL_SetCW(tp_id, KeySel, TP_SETCW_KEYID_MULTI2_SYS_KEY, system_key,dummy_IV); --  IV don't care, but please don't input NULL pointer

   2. set "CBC  key+even" key
   (1) key_id = TP_SETCW_KEYID_EVEN_KEY
   (2) CBC  key field into IV[TPK_MAX_IV_LENGTH] (8 bytes)
   (3) even key field into Key[TPK_MAX_KEY_LENGTH] (8 byte)
   RHAL_SetCW(tp_id, KeySel, TP_SETCW_KEYID_EVEN_KEY,even_key,cbc_key);

   3. set "CBC  key+odd" key
   (1) key_id = TP_SETCW_KEYID_ODD_KEY
   (2) CBC  key field into IV[TPK_MAX_IV_LENGTH] (8 bytes)
   (3) odd key field into Key[TPK_MAX_KEY_LENGTH] (8 byte)
   RHAL_SetCW(tp_id, KeySel, TP_SETCW_KEYID_ODD_KEY,odd_key,cbc_key);

   Other descramble algorithm set key flow:
   1. set even key + IV
   (1) key_id = TP_SETCW_KEYID_EVEN_KEY
   (2) even IV field into IV[TPK_MAX_IV_LENGTH] (maximun 16 bytes)
   (3) even key field into Key[TPK_MAX_KEY_LENGTH] (maximun 32 bytes)
   RHAL_SetCW(tp_id, KeySel, TP_SETCW_KEYID_EVEN_KEY, even_key,even_iv);

   2. set odd key + IV
   (1) key_id = TP_SETCW_KEYID_ODD_KEY
   (2) odd IV field into IV[TPK_MAX_IV_LENGTH] (maximun 16 bytes)
   (3) odd key field into Key[TPK_MAX_KEY_LENGTH] (maximun 32 bytes)
   RHAL_SetCW(tp_id, KeySel, TP_SETCW_KEYID_ODD_KEY, even_key,even_iv);
******************************************************/


/*      Parm : key_set   : key set */
/*             key_id    : key id (0: even key and iv, 1 : odd key & iv, 2 : system key (for multi 2 only)) */
/*             Key       : key value */
/*             IV        : intial value */
TP_EXTERN INT32 RHAL_SetCW(IN TPK_TP_ENGINE_T tp_id, IN UINT8 KeySel, IN UINT8 key_id, IN UINT8 Key[TPK_MAX_KEY_LENGTH], IN UINT8 IV[TPK_MAX_IV_LENGTH]);
TP_EXTERN INT32 RHAL_DescrambleControl(IN TPK_TP_ENGINE_T tp_id, IN TPK_DESCRAMBLE_MODE_T mode);


/* get debug message */
TP_EXTERN INT32 RHAL_TrackErrorPacket(IN TPK_TP_ENGINE_T tp_id, OUT UINT32 *pErrPkt, OUT UINT32 *pRevPkt, OUT UINT32 *pDropPkt);
TP_EXTERN INT32 RHAL_TPDbgRecTSData(IN TPK_TP_ENGINE_T tp_id, IN UINT8 enable, IN UINT8* path);

/* hardware info and status for AP */
TP_EXTERN INT32 RHAL_GetHardwareInfo(OUT TPK_HARDWARE_INFO_T *pTpHardwareInfo);
TP_EXTERN INT32 RHAL_GetTpStatus(IN TPK_TP_ENGINE_T tp_id, OUT TPK_TP_STATUS_T *pTpStatus);
TP_EXTERN INT32 RHAL_GetMtpStatus(IN UINT8 mtp_id, OUT TPK_MTP_STATUS_T *pMtpStatus);
TP_EXTERN INT32 RHAL_GetTpoutStatus(IN UINT8 tpout_id, OUT TPK_TPOUT_STATUS_T *pTpoutStatus);

/* Extend function */
TP_EXTERN INT32 RHAL_GetTPSource(TPK_INPUT_PORT_T portType);
TP_EXTERN INT32 RHAL_SetTPHardwareReset(UINT8 restore_value);
TP_EXTERN INT32  RHAL_SetPIDDescrambleAlgorithm(UINT8 key_sel, TPK_DESCRAMBLE_ALGORITHM_T     algo);
TP_EXTERN INT32 RHAL_FreePIDDescrambleAlgorithm(void);

INT32 RHAL_DisplayTPFramerInformation(TPK_TP_ENGINE_T tp_id);

#endif /* __TP_DRV_API_H__ */

