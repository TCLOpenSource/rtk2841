#ifndef _SCALER_HDR_RPC_H
#define _SCALER_HDR_RPC_H

#include <linux/types.h>
#include <rtd_types.h>


#define VIDEO_RPC_DOLBY_VISION_HDMI_Set_Detect_Enable 11010
#define VIDEO_RPC_DOLBY_VISION_HDMI_Get_Detect_Info 11020
#define VIDEO_RPC_DOLBY_VISION_HDMI_Set_Display_Enable 11030



struct DOLBY_VISION_CAPTURE_BUFFER_T {
	u_long uncacheAddr;
	u_long cacheAddr;
	u_long phyaddr;
	u_int size;
};
typedef struct DOLBY_VISION_CAPTURE_BUFFER_T DOLBY_VISION_CAPTURE_BUFFER_T;

struct DOLBY_VISION_CAPTURE_INFO {
	DOLBY_VISION_CAPTURE_BUFFER_T bufAddr_md[2];
	DOLBY_VISION_CAPTURE_BUFFER_T bufAddr_video[2];
	DOLBY_VISION_CAPTURE_BUFFER_T bufAddr_graph[2];
};
typedef struct DOLBY_VISION_CAPTURE_INFO DOLBY_VISION_CAPTURE_INFO;

struct VIDEO_RPC_DOLBY_VISION_HDMI_SET_DETECT_ENABLE {
	long instanceID;
	long detect_en;
	long display_en;
	DOLBY_VISION_CAPTURE_INFO capInfo;
};
typedef struct VIDEO_RPC_DOLBY_VISION_HDMI_SET_DETECT_ENABLE VIDEO_RPC_DOLBY_VISION_HDMI_SET_DETECT_ENABLE;

struct VIDEO_RPC_DOLBY_VISION_HDMI_GET_DETECT_INFO {
	long instanceID;
	long detect_ret;
};
typedef struct VIDEO_RPC_DOLBY_VISION_HDMI_GET_DETECT_INFO VIDEO_RPC_DOLBY_VISION_HDMI_GET_DETECT_INFO;

struct VIDEO_RPC_DOLBY_VISION_HDMI_SET_DISPLAY_ENABLE {
	long instanceID;
	long display_en;
};
typedef struct VIDEO_RPC_DOLBY_VISION_HDMI_SET_DISPLAY_ENABLE VIDEO_RPC_DOLBY_VISION_HDMI_SET_DISPLAY_ENABLE;

int Scaler_HDR_vrpc_DolbyVision_Hdmi_SetDetectEnable(VIDEO_RPC_DOLBY_VISION_HDMI_SET_DETECT_ENABLE *pSetDetectInfo);
int Scaler_HDR_vrpc_DolbyVision_Hdmi_Get_Detect_Info(VIDEO_RPC_DOLBY_VISION_HDMI_GET_DETECT_INFO *pGetDetectInfo);
int Scaler_HDR_vrpc_DolbyVision_Hdmi_SetDisplayEnable(VIDEO_RPC_DOLBY_VISION_HDMI_SET_DISPLAY_ENABLE *pSetDisplayInfo);

#endif
