/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _VIDEORPC_AGENT_DATA_H_RPCGEN
#define _VIDEORPC_AGENT_DATA_H_RPCGEN

#include <RPCBaseDS.h>
#include <VideoRPCBaseDS.h>

struct VIDEO_RPC_ENC_ELEM_GEN_INFO {
	enum ENUM_DVD_VIDEO_ENCODER_OUTPUT_INFO_TYPE infoType;
	u_char videoInputSource;
	u_char encoderType;
	u_char TVSystemFormat;
	u_char videoRCMode;
	int horizontalResolusion;
	u_int video_STD_buffer_size;
	u_int init_STD_buffer_fullness;
	u_int videoBitRate;
	u_char gop_M;
	u_char gop_N;
	u_char numOfGOPsPerVOBU;
};
typedef struct VIDEO_RPC_ENC_ELEM_GEN_INFO VIDEO_RPC_ENC_ELEM_GEN_INFO;

struct VIDEO_RPC_ENC_ELEM_FRAME_INFO {
	enum ENUM_DVD_VIDEO_ENCODER_OUTPUT_INFO_TYPE infoType;
	u_int pictureNumber;
	u_char pictureType;
	u_char topFieldFirst;
	u_char numOfField;
	u_char newScene;
	u_int PTShigh;
	u_int PTSlow;
	u_int DTShigh;
	u_int DTSlow;
	u_int VBIData;
	u_int VBVfullness;
	u_char resumedVideoFrame;
	u_char newVOBUStart;
	u_char KeyFrame;
	u_char AGCDetection;
	u_int CCData;
	u_int CCStatus;
	int frameSize;
};
typedef struct VIDEO_RPC_ENC_ELEM_FRAME_INFO VIDEO_RPC_ENC_ELEM_FRAME_INFO;

struct VIDEO_RPC_ENDOFSTREAM {
	long SP_instanceID;
};
typedef struct VIDEO_RPC_ENDOFSTREAM VIDEO_RPC_ENDOFSTREAM;

struct VIDEO_RPC_DEC_JPEG_INFO {
	long instanceID;
	long destWidth;
	long destHeight;
	long eventID;
	long reserved2;
	long reserved3;
};
typedef struct VIDEO_RPC_DEC_JPEG_INFO VIDEO_RPC_DEC_JPEG_INFO;

struct VIDEO_RPC_DEC_JPEG_CTRL {
	long decodedWidth;
	long decodedHeight;
	long bitstreamEnd;
	long cancel;
	long status;
	long orgJpegWidth;
	long orgJpegHeight;
	long croppedJpegX;
	long croppedJpegY;
	long croppedJpegWidth;
	long croppedJpegHeight;
	enum VIDEO_JPEG_ROTATION orientation;
	long percentage;
	long reserved3;
	long JPEG_CTRL;
	long BITMAP_CTRL;
	long TIFF_CTRL;
	long GIF_CTRL;
	long PNG_CTRL;
	long Format1_CTRL;
	long Format2_CTRL;
	long Format3_CTRL;
	long bitstreamStart;
	long outInstanceID;
	enum VIDEO_IMG_TYPE imgType;
	long pScratchBase;
	long scratchSize;
	long WEBP_CTRL;
	long PSEUDOIMG_CTRL;
};
typedef struct VIDEO_RPC_DEC_JPEG_CTRL VIDEO_RPC_DEC_JPEG_CTRL;

struct VIDEO_RPC_ENC_VBID_WSS_INFO {
	enum ENUM_DVD_VIDEO_ENCODER_OUTPUT_INFO_TYPE infoType;
	enum ENUM_TVD_VIDEO_FORMAT video_format;
	u_int flg_no_signal;
	u_int copy_protected;
	enum VO_VBI_ASPECT_RATIO vbi_aspect_ratio;
};
typedef struct VIDEO_RPC_ENC_VBID_WSS_INFO VIDEO_RPC_ENC_VBID_WSS_INFO;

struct VIDEO_RPC_ENC_PAUSE_INFO {
	enum ENUM_DVD_VIDEO_ENCODER_OUTPUT_INFO_TYPE infoType;
	u_int pausedPTSHigh;
	u_int pausedPTSLow;
	u_int pausedDTSHigh;
	u_int pausedDTSLow;
	u_int resumedPTSHigh;
	u_int resumedPTSLow;
	u_int resumedDTSHigh;
	u_int resumedDTSLow;
	u_char pictureType;
};
typedef struct VIDEO_RPC_ENC_PAUSE_INFO VIDEO_RPC_ENC_PAUSE_INFO;

struct VIDEO_RPC_ENC_AUTOPAUSE_INFO {
	enum ENUM_DVD_VIDEO_ENCODER_OUTPUT_INFO_TYPE infoType;
	u_char isFinish;
};
typedef struct VIDEO_RPC_ENC_AUTOPAUSE_INFO VIDEO_RPC_ENC_AUTOPAUSE_INFO;

struct VIDEO_RPC_DEC_ERROR_INFO {
	long instanceID;
	long errCode;
};
typedef struct VIDEO_RPC_DEC_ERROR_INFO VIDEO_RPC_DEC_ERROR_INFO;

struct VIDEO_RPC_ENC_AUTOPAUSE {
	long instanceID;
	u_char isFinish;
};
typedef struct VIDEO_RPC_ENC_AUTOPAUSE VIDEO_RPC_ENC_AUTOPAUSE;

struct VIDEO_RPC_SCALER_MESSAGE {
	u_int msgType;
	u_int msgSubType;
	u_int msgIntData;
	u_int msgBodyByteSize;
	u_int msgDataPtrAddr;
	u_int isValidate;
	u_int isSmoothtoggle;
};
typedef struct VIDEO_RPC_SCALER_MESSAGE VIDEO_RPC_SCALER_MESSAGE;

struct VIDEO_RPC_DEC_MESSAGE {
	long instanceID;
	long message;
};
typedef struct VIDEO_RPC_DEC_MESSAGE VIDEO_RPC_DEC_MESSAGE;

struct VIDEO_RPC_VOUT_MESSAGE {
	long instanceID;
	long message;
	u_int PTShigh;
	u_int PTSlow;
	u_int reserved1;
	u_int reserved2;
	u_int reserved3;
	u_int reserved4;
};
typedef struct VIDEO_RPC_VOUT_MESSAGE VIDEO_RPC_VOUT_MESSAGE;

struct VIDEO_RPC_TRANSITION_EFFECT_CTRL {
	long cancel;
	long percentage;
	VO_RECTANGLE winStart_A;
	VO_RECTANGLE winEnd_A;
	VO_RECTANGLE winStart_B;
	VO_RECTANGLE winEnd_B;
	long timeForKenBurns;
};
typedef struct VIDEO_RPC_TRANSITION_EFFECT_CTRL VIDEO_RPC_TRANSITION_EFFECT_CTRL;

#endif /* !_VIDEORPC_AGENT_DATA_H_RPCGEN */
