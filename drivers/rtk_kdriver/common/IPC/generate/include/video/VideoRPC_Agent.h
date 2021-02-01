/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _VIDEORPC_AGENT_H_RPCGEN
#define _VIDEORPC_AGENT_H_RPCGEN

#include <rt/misc/RPCstruct.h>

#include "VideoRPC_Agent_data.h"

#ifdef __cplusplus
extern "C" {
#endif

#define printf(str)

#include <RPCBaseDS.h>
#include <VideoRPCBaseDS.h>

#define VIDEO_AGENT 300
#define VERSION 0

struct REG_STRUCT * VIDEO_AGENT_0_register(struct REG_STRUCT *rnode);

#if defined(__STDC__) || defined(__cplusplus)
#define VIDEO_RPC_ENC_ToSystem_EndOfStream 1
extern  HRESULT * VIDEO_RPC_ENC_ToSystem_EndOfStream_0(long *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_ENC_ToSystem_EndOfStream_0_svc(long *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_ToSystem_EndOfStream 2
extern  HRESULT * VIDEO_RPC_ToSystem_EndOfStream_0(VIDEO_RPC_ENDOFSTREAM *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_ToSystem_EndOfStream_0_svc(VIDEO_RPC_ENDOFSTREAM *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_ToSystem_Deliver_GenInfo 3
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_GenInfo_0(long *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_GenInfo_0_svc(long *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_ToSystem_Deliver_FrameInfo 4
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_FrameInfo_0(long *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_FrameInfo_0_svc(long *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_JPEG_ToSystem_EndOfDecSeg 5
extern  HRESULT * VIDEO_RPC_JPEG_ToSystem_EndOfDecSeg_0(VIDEO_RPC_DEC_JPEG_INFO *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_JPEG_ToSystem_EndOfDecSeg_0_svc(VIDEO_RPC_DEC_JPEG_INFO *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_ToSystem_Deliver_WSSInfo 6
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_WSSInfo_0(long *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_WSSInfo_0_svc(long *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_ToSystem_Deliver_PauseInfo 7
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_PauseInfo_0(long *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_PauseInfo_0_svc(long *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_DEC_ToSystem_FatalError 8
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_FatalError_0(VIDEO_RPC_DEC_ERROR_INFO *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_FatalError_0_svc(VIDEO_RPC_DEC_ERROR_INFO *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_ToSystem_ScaleModeSCART 9
extern  HRESULT * VIDEO_RPC_ToSystem_ScaleModeSCART_0(long *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_ToSystem_ScaleModeSCART_0_svc(long *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_ToSystem_Deliver_AutoPauseInfo 10
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_AutoPauseInfo_0(VIDEO_RPC_ENC_AUTOPAUSE *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_AutoPauseInfo_0_svc(VIDEO_RPC_ENC_AUTOPAUSE *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_ToSystem_VideoHaltDone 11
extern  HRESULT * VIDEO_RPC_ToSystem_VideoHaltDone_0(long *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_ToSystem_VideoHaltDone_0_svc(long *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_ToSystem_SendScalerMsg 12
extern  HRESULT * VIDEO_RPC_ToSystem_SendScalerMsg_0(VIDEO_RPC_SCALER_MESSAGE *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_ToSystem_SendScalerMsg_0_svc(VIDEO_RPC_SCALER_MESSAGE *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_ToSystem_DecoderMessage 15
extern  HRESULT * VIDEO_RPC_ToSystem_DecoderMessage_0(VIDEO_RPC_DEC_MESSAGE *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_ToSystem_DecoderMessage_0_svc(VIDEO_RPC_DEC_MESSAGE *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_ToSystem_VoutMessage 17
extern  HRESULT * VIDEO_RPC_ToSystem_VoutMessage_0(VIDEO_RPC_VOUT_MESSAGE *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_ToSystem_VoutMessage_0_svc(VIDEO_RPC_VOUT_MESSAGE *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_DEC_ToSystem_Deliver_FrameInfo 18
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_Deliver_FrameInfo_0(VIDEO_RPC_DEC_FRAME_INFO *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_Deliver_FrameInfo_0_svc(VIDEO_RPC_DEC_FRAME_INFO *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_DEC_ToSystem_Deliver_PicInfo 19
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_Deliver_PicInfo_0(VIDEO_RPC_DEC_PIC_INFO *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_Deliver_PicInfo_0_svc(VIDEO_RPC_DEC_PIC_INFO *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_DEC_ToSystem_Deliver_MediaInfo 20
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_Deliver_MediaInfo_0(VIDEO_RPC_DEC_MEDIA_INFO *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_Deliver_MediaInfo_0_svc(VIDEO_RPC_DEC_MEDIA_INFO *, RPC_STRUCT *, HRESULT *);
#define VIDEO_RPC_ToSystem_KernelRPC 30
extern  HRESULT * VIDEO_RPC_ToSystem_KernelRPC_0(VIDEO_RPC_TO_KERNEL_PARAMETER *, CLNT_STRUCT *);
extern  HRESULT * VIDEO_RPC_ToSystem_KernelRPC_0_svc(VIDEO_RPC_TO_KERNEL_PARAMETER *, RPC_STRUCT *, HRESULT *);

#else /* K&R C */
#define VIDEO_RPC_ENC_ToSystem_EndOfStream 1
extern  HRESULT * VIDEO_RPC_ENC_ToSystem_EndOfStream_0();
extern  HRESULT * VIDEO_RPC_ENC_ToSystem_EndOfStream_0_svc();
#define VIDEO_RPC_ToSystem_EndOfStream 2
extern  HRESULT * VIDEO_RPC_ToSystem_EndOfStream_0();
extern  HRESULT * VIDEO_RPC_ToSystem_EndOfStream_0_svc();
#define VIDEO_RPC_ToSystem_Deliver_GenInfo 3
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_GenInfo_0();
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_GenInfo_0_svc();
#define VIDEO_RPC_ToSystem_Deliver_FrameInfo 4
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_FrameInfo_0();
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_FrameInfo_0_svc();
#define VIDEO_RPC_JPEG_ToSystem_EndOfDecSeg 5
extern  HRESULT * VIDEO_RPC_JPEG_ToSystem_EndOfDecSeg_0();
extern  HRESULT * VIDEO_RPC_JPEG_ToSystem_EndOfDecSeg_0_svc();
#define VIDEO_RPC_ToSystem_Deliver_WSSInfo 6
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_WSSInfo_0();
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_WSSInfo_0_svc();
#define VIDEO_RPC_ToSystem_Deliver_PauseInfo 7
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_PauseInfo_0();
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_PauseInfo_0_svc();
#define VIDEO_RPC_DEC_ToSystem_FatalError 8
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_FatalError_0();
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_FatalError_0_svc();
#define VIDEO_RPC_ToSystem_ScaleModeSCART 9
extern  HRESULT * VIDEO_RPC_ToSystem_ScaleModeSCART_0();
extern  HRESULT * VIDEO_RPC_ToSystem_ScaleModeSCART_0_svc();
#define VIDEO_RPC_ToSystem_Deliver_AutoPauseInfo 10
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_AutoPauseInfo_0();
extern  HRESULT * VIDEO_RPC_ToSystem_Deliver_AutoPauseInfo_0_svc();
#define VIDEO_RPC_ToSystem_VideoHaltDone 11
extern  HRESULT * VIDEO_RPC_ToSystem_VideoHaltDone_0();
extern  HRESULT * VIDEO_RPC_ToSystem_VideoHaltDone_0_svc();
#define VIDEO_RPC_ToSystem_SendScalerMsg 12
extern  HRESULT * VIDEO_RPC_ToSystem_SendScalerMsg_0();
extern  HRESULT * VIDEO_RPC_ToSystem_SendScalerMsg_0_svc();
#define VIDEO_RPC_ToSystem_DecoderMessage 15
extern  HRESULT * VIDEO_RPC_ToSystem_DecoderMessage_0();
extern  HRESULT * VIDEO_RPC_ToSystem_DecoderMessage_0_svc();
#define VIDEO_RPC_ToSystem_VoutMessage 17
extern  HRESULT * VIDEO_RPC_ToSystem_VoutMessage_0();
extern  HRESULT * VIDEO_RPC_ToSystem_VoutMessage_0_svc();
#define VIDEO_RPC_DEC_ToSystem_Deliver_FrameInfo 18
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_Deliver_FrameInfo_0();
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_Deliver_FrameInfo_0_svc();
#define VIDEO_RPC_DEC_ToSystem_Deliver_PicInfo 19
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_Deliver_PicInfo_0();
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_Deliver_PicInfo_0_svc();
#define VIDEO_RPC_DEC_ToSystem_Deliver_MediaInfo 20
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_Deliver_MediaInfo_0();
extern  HRESULT * VIDEO_RPC_DEC_ToSystem_Deliver_MediaInfo_0_svc();
#define VIDEO_RPC_ToSystem_KernelRPC 30
extern  HRESULT * VIDEO_RPC_ToSystem_KernelRPC_0();
extern  HRESULT * VIDEO_RPC_ToSystem_KernelRPC_0_svc();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_VIDEO_RPC_SUBPIC_INFO (XDR *, VIDEO_RPC_SUBPIC_INFO*);
extern  bool_t xdr_VIDEO_RPC_ENC_ELEM_GEN_INFO (XDR *, VIDEO_RPC_ENC_ELEM_GEN_INFO*);
extern  bool_t xdr_VIDEO_RPC_ENC_ELEM_FRAME_INFO (XDR *, VIDEO_RPC_ENC_ELEM_FRAME_INFO*);
extern  bool_t xdr_VIDEO_RPC_ENDOFSTREAM (XDR *, VIDEO_RPC_ENDOFSTREAM*);
extern  bool_t xdr_VIDEO_RPC_DEC_JPEG_INFO (XDR *, VIDEO_RPC_DEC_JPEG_INFO*);
extern  bool_t xdr_VIDEO_RPC_DEC_JPEG_CTRL (XDR *, VIDEO_RPC_DEC_JPEG_CTRL*);
extern  bool_t xdr_VIDEO_RPC_ENC_VBID_WSS_INFO (XDR *, VIDEO_RPC_ENC_VBID_WSS_INFO*);
extern  bool_t xdr_VIDEO_RPC_ENC_PAUSE_INFO (XDR *, VIDEO_RPC_ENC_PAUSE_INFO*);
extern  bool_t xdr_VIDEO_RPC_ENC_AUTOPAUSE_INFO (XDR *, VIDEO_RPC_ENC_AUTOPAUSE_INFO*);
extern  bool_t xdr_VIDEO_RPC_DEC_ERROR_INFO (XDR *, VIDEO_RPC_DEC_ERROR_INFO*);
extern  bool_t xdr_VIDEO_RPC_ENC_AUTOPAUSE (XDR *, VIDEO_RPC_ENC_AUTOPAUSE*);
extern  bool_t xdr_VIDEO_DEC_FRM_MSG (XDR *, VIDEO_DEC_FRM_MSG*);
extern  bool_t xdr_VIDEO_DEC_PIC_MSG (XDR *, VIDEO_DEC_PIC_MSG*);
extern  bool_t xdr_VIDEO_RPC_SCALER_MESSAGE (XDR *, VIDEO_RPC_SCALER_MESSAGE*);
extern  bool_t xdr_VIDEO_RPC_DEC_MESSAGE (XDR *, VIDEO_RPC_DEC_MESSAGE*);
extern  bool_t xdr_VIDEO_RPC_VOUT_MESSAGE (XDR *, VIDEO_RPC_VOUT_MESSAGE*);
extern  bool_t xdr_VIDEO_RPC_DEC_FRAME_INFO (XDR *, VIDEO_RPC_DEC_FRAME_INFO*);
extern  bool_t xdr_VIDEO_RPC_DEC_PIC_INFO (XDR *, VIDEO_RPC_DEC_PIC_INFO*);
extern  bool_t xdr_VIDEO_RPC_DEC_MEDIA_INFO (XDR *, VIDEO_RPC_DEC_MEDIA_INFO*);
extern  bool_t xdr_VIDEO_RPC_TO_KERNEL_PARAMETER (XDR *, VIDEO_RPC_TO_KERNEL_PARAMETER*);
extern  bool_t xdr_VIDEO_RPC_TRANSITION_EFFECT_CTRL (XDR *, VIDEO_RPC_TRANSITION_EFFECT_CTRL*);

#else /* K&R C */
extern bool_t xdr_VIDEO_RPC_SUBPIC_INFO ();
extern bool_t xdr_VIDEO_RPC_ENC_ELEM_GEN_INFO ();
extern bool_t xdr_VIDEO_RPC_ENC_ELEM_FRAME_INFO ();
extern bool_t xdr_VIDEO_RPC_ENDOFSTREAM ();
extern bool_t xdr_VIDEO_RPC_DEC_JPEG_INFO ();
extern bool_t xdr_VIDEO_RPC_DEC_JPEG_CTRL ();
extern bool_t xdr_VIDEO_RPC_ENC_VBID_WSS_INFO ();
extern bool_t xdr_VIDEO_RPC_ENC_PAUSE_INFO ();
extern bool_t xdr_VIDEO_RPC_ENC_AUTOPAUSE_INFO ();
extern bool_t xdr_VIDEO_RPC_DEC_ERROR_INFO ();
extern bool_t xdr_VIDEO_RPC_ENC_AUTOPAUSE ();
extern bool_t xdr_VIDEO_DEC_FRM_MSG ();
extern bool_t xdr_VIDEO_DEC_PIC_MSG ();
extern bool_t xdr_VIDEO_RPC_SCALER_MESSAGE ();
extern bool_t xdr_VIDEO_RPC_DEC_MESSAGE ();
extern bool_t xdr_VIDEO_RPC_VOUT_MESSAGE ();
extern bool_t xdr_VIDEO_RPC_DEC_FRAME_INFO ();
extern bool_t xdr_VIDEO_RPC_DEC_PIC_INFO ();
extern bool_t xdr_VIDEO_RPC_DEC_MEDIA_INFO ();
extern bool_t xdr_VIDEO_RPC_TO_KERNEL_PARAMETER ();
extern bool_t xdr_VIDEO_RPC_TRANSITION_EFFECT_CTRL ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_VIDEORPC_AGENT_H_RPCGEN */
