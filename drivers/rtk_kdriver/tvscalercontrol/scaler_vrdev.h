#ifndef _HAL_VR_H_
#define _HAL_VR_H_
/*-----------------------------------------------------------------------------
	Definition of struct for IO ctrl cmd(all parameters include in the same struct)
------------------------------------------------------------------------------*/

/**
 * @brief This enumeration describes the supported number of plane corresponding to plane type of video frame buffer.
 */
typedef enum
{
	KADP_VR_VIDEO_FRAME_BUFFER_PLANE_INTERLEAVED = 1,
	KADP_VR_VIDEO_FRAME_BUFFER_PLANE_SEMI_PLANAR,
	KADP_VR_VIDEO_FRAME_BUFFER_PLANE_PLANAR
} KADP_VR_VIDEO_FRAME_BUFFER_PLANE_NUMBER_T;

/**
 * @brief This enumeration describes the supported pixel format of video frame buffer.
 */
typedef enum
{
	KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_PLANAR = 0,
	KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_SEMI_PLANAR,
	KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_INTERLEAVED,
	KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_PLANAR,
	KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_SEMI_PLANAR,
	KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_INTERLEAVED,
	KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_PLANAR,
	KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_SEMI_PLANAR,
	KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_INTERLEAVED,
	KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_RGB,
	KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_ARGB
} KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T;

/**
 * @brief This enumeration describes the supported video window.
 */
typedef enum
{
	KADP_VR_VIDEO_INVALID_WINDOW = -1,
	KADP_VR_VIDEO_WINDOW_0 = 0,
	KADP_VR_VIDEO_WINDOW_1 = 1,
	KADP_VR_VIDEO_WINDOW_2 = 2
} KADP_VR_VIDEO_WINDOW_TYPE_T;

/**
 * @brief This enumeration describes flags for state of video frame output device setting.
 */
typedef enum
{
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_NOFX 			= 0x00000000,
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_ENABLED 			= 0x00000001,
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FREEZED			= 0x00000002,
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_APPLIED_PQ		= 0x00000004,
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FRAMERATE_DIVIDE	= 0x00000010
} KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FLAGS_T;

/**
 * @brief This enumeration describes the dump location of video memory.
 */
typedef enum
{
	KADP_VR_SCALER_OUTPUT = 0,
	KADP_VR_DISPLAY_OUTPUT,
	KADP_VR_OSDVIDEO_OUTPUT
} KADP_VR_DUMP_LOCATION_TYPE_T;

/**
 * @brief This enumeration describes the type of video.
 */
typedef enum
{
	KADP_VR_VIDEO_INTERLACED	= 0,
	KADP_VR_VIDEO_PROGRESSIVE
} KADP_VR_VIDEO_TYPE_T;
	
/**
 * @brief This enumeration describes the supported video window.
 */
typedef enum
{
	RTK_VR_VIDEO_INVALID_WINDOW = -1,
	RTK_VR_VIDEO_WINDOW_0 = 0,
	RTK_VR_VIDEO_WINDOW_1 = 1,
	RTK_VR_VIDEO_WINDOW_2 = 2
} RTK_VR_VIDEO_WINDOW_TYPE_T;

/**
 * @brief This structure describes a rectangle specified by a point and a dimension.
 */
typedef struct
{
	unsigned short	x;
	unsigned short	y;
	unsigned short	w;
	unsigned short	h;
} KADP_VR_RECT_T;

/**
 * @brief This structure describes the capability of video device.
 */
typedef struct
{
	unsigned int	numOfVideoWindow;
} KADP_VR_DEVICE_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the capability of video frame buffer.
 */
typedef struct
{
	unsigned int numOfVideoFrameBuffer;
	KADP_VR_VIDEO_FRAME_BUFFER_PLANE_NUMBER_T numOfPlane;
} KADP_VR_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the capability of video frame output device.
 */
typedef struct
{
	unsigned char	bSupportedControlEnabled;
	unsigned char	bSupportedControlFreezed;
	unsigned char	bSupportedControlFramerateDivide;
	unsigned char	bSupportedControlPQ;
} KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the limitation of video frame output device.
 */
typedef struct {
	KADP_VR_RECT_T 	maxResolution;
	unsigned char	bLeftTopAlign;
	unsigned char	bSupportInputVideoDeInterlacing;
	unsigned char	bSupportDisplayVideoDeInterlacing;
	unsigned char	bSupportScaleUp;
	unsigned int	scaleUpLimitWidth;
	unsigned int	scaleUpLimitHeight;
	unsigned char	bSupportScaleDown;
	unsigned int	scaleDownLimitWidth;
	unsigned int	scaleDownLimitHeight;
} KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_LIMITATION_INFO_T;

/**
 * @brief This structure describes the constant property of video frame buffer.
 * These member values are unique properties of video frame buffer. it is not able to be changed.
 */
typedef struct
{
	KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T pixelFormat;
	unsigned int	stride;
	unsigned int	width;
	unsigned int	height;
	unsigned int	ppPhysicalAddress0;
	unsigned int	ppPhysicalAddress1;
	unsigned int	ppPhysicalAddress2;
	unsigned int	ppPhysicalAddress3;
	unsigned int	ppPhysicalAddress4;
	unsigned int	vfbbuffernumber; //supporting of continuous capture feature in WebOS 4.0
} KADP_VR_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T;

/**
 * @brief This structure describes state information of video frame output device.
 */
typedef struct
{
	unsigned char	bEnabled;
	unsigned char	bFreezed;
	unsigned char	bAppliedPQ;
	unsigned int	framerateDivide;
} KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T;

/**
 * @brief This structure describes information of input video.
 */
typedef struct {
	KADP_VR_VIDEO_TYPE_T			type;
	KADP_VR_RECT_T				region;
	unsigned char				bIs3DVideo;
} KADP_VR_INPUT_VIDEO_INFO_T;

/**
 * @brief This structure describes information of output video.
 */
typedef struct {
	KADP_VR_VIDEO_TYPE_T			type;
	KADP_VR_RECT_T				maxRegion;
	KADP_VR_RECT_T				activeRegion;
} KADP_VR_OUTPUT_VIDEO_INFO_T;

/**
 * @brief This structure describes output information of video frame output device.
 */
typedef struct {
	unsigned int	stride;
	KADP_VR_RECT_T	maxRegion;
	KADP_VR_RECT_T	activeRegion;
} KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_OUTPUT_INFO_T;

/**
 * @brief This structure describes information of captured video frame
 * 		This legacy structure will be used to support legacy chipset. (M14, H13)
 * 		Then this legacy structure is not used from latest chip (H15, LM15U).
 */
typedef struct
{
	KADP_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T pixelFormat;
	unsigned short	stride;
	unsigned short	width;
	unsigned short	height;
	unsigned char	*pVideoFrameAddress[3];
} KADP_VR_LEGACY_VIDEO_FRAME_INFO_T;

#if 0
/**
 * @brief This enumeration describes the supported number of plane corresponding to plane type of video frame buffer.
 */
typedef enum
{
	RTK_VR_VIDEO_FRAME_BUFFER_PLANE_INTERLEAVED = 1,
	RTK_VR_VIDEO_FRAME_BUFFER_PLANE_SEMI_PLANAR,
	RTK_VR_VIDEO_FRAME_BUFFER_PLANE_PLANAR
} RTK_VR_VIDEO_FRAME_BUFFER_PLANE_NUMBER_T;

/**
 * @brief This enumeration describes the supported pixel format of video frame buffer.
 */
typedef enum
{
	RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_PLANAR = 0,
	RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_SEMI_PLANAR,
	RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_INTERLEAVED,
	RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_PLANAR,
	RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_SEMI_PLANAR,
	RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_INTERLEAVED,
	RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_PLANAR,
	RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_SEMI_PLANAR,
	RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_INTERLEAVED,
	RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_RGB,
	RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_ARGB
} RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T;

/**
 * @brief This enumeration describes flags for state of video frame output device setting.
 */
typedef enum
{
	RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_NOFX 			= 0x00000000,
	RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_ENABLED 			= 0x00000001,
	RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FREEZED			= 0x00000002,
	RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_APPLIED_PQ		= 0x00000004,
	RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FRAMERATE_DIVIDE	= 0x00000010
} RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FLAGS_T;

/**
 * @brief This enumeration describes the dump location of video memory.
 */
typedef enum
{
	RTK_VR_SCALER_OUTPUT = 0,
	RTK_VR_DISPLAY_OUTPUT
} RTK_VR_DUMP_LOCATION_TYPE_T;

/**
 * @brief This enumeration describes the type of video.
 */
typedef enum
{
	RTK_VR_VIDEO_INTERLACED	= 0,
	RTK_VR_VIDEO_PROGRESSIVE
} RTK_VR_VIDEO_TYPE_T;

/**
 * @brief This structure describes a rectangle specified by a point and a dimension.
 */
typedef struct
{
	unsigned short	x;
	unsigned short	y;
	unsigned short	w;
	unsigned short	h;
} RTK_VR_RECT_T;

/**
 * @brief This structure describes the capability of video device.
 */
typedef struct
{
	unsigned int	numOfVideoWindow;
} RTK_VR_DEVICE_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the capability of video frame buffer.
 */
typedef struct
{
	unsigned int numOfVideoFrameBuffer;
	RTK_VR_VIDEO_FRAME_BUFFER_PLANE_NUMBER_T numOfPlane;
} RTK_VR_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the capability of video frame output device.
 */
typedef struct
{
	unsigned char	bSupportedControlEnabled;
	unsigned char	bSupportedControlFreezed;
	unsigned char	bSupportedControlFramerateDivide;
	unsigned char	bSupportedControlPQ;
} RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the limitation of video frame output device.
 */
typedef struct {
	RTK_VR_RECT_T 	maxResolution;
	unsigned char	bLeftTopAlign;
	unsigned char	bSupportInputVideoDeInterlacing;
	unsigned char	bSupportDisplayVideoDeInterlacing;
	unsigned char	bSupportScaleUp;
	unsigned int	scaleUpLimitWidth;
	unsigned int	scaleUpLimitHeight;
	unsigned char	bSupportScaleDown;
	unsigned int	scaleDownLimitWidth;
	unsigned int	scaleDownLimitHeight;
} RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_LIMITATION_INFO_T;

/**
 * @brief This structure describes the constant property of video frame buffer.
 * These member values are unique properties of video frame buffer. it is not able to be changed.
 */
typedef struct
{
	RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T pixelFormat;
	unsigned int	stride;
	unsigned int	width;
	unsigned int	height;
	unsigned int	ppPhysicalAddress0;
	unsigned int	ppPhysicalAddress1;
	unsigned int	ppPhysicalAddress2;
	unsigned int	ppPhysicalAddress3;
	unsigned int	ppPhysicalAddress4;
	unsigned int	vfbbuffernumber;
} RTK_VR_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T;

/**
 * @brief This structure describes state information of video frame output device.
 */
typedef struct
{
	unsigned char	bEnabled;
	unsigned char	bFreezed;
	unsigned char	bAppliedPQ;
	unsigned int	framerateDivide;
} RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T;

/**
 * @brief This structure describes information of input video.
 */
typedef struct {
	RTK_VR_VIDEO_TYPE_T			type;
	RTK_VR_RECT_T				region;
	unsigned char				bIs3DVideo;
} RTK_VR_INPUT_VIDEO_INFO_T;

/**
 * @brief This structure describes information of output video.
 */
typedef struct {
	RTK_VR_VIDEO_TYPE_T			type;
	RTK_VR_RECT_T				maxRegion;
	RTK_VR_RECT_T				activeRegion;
} RTK_VR_OUTPUT_VIDEO_INFO_T;

/**
 * @brief This structure describes output information of video frame output device.
 */
typedef struct {
	unsigned int	stride;
	RTK_VR_RECT_T	maxRegion;
	RTK_VR_RECT_T	activeRegion;
} RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_OUTPUT_INFO_T;

/**
 * @brief This structure describes information of captured video frame
 * 		This legacy structure will be used to support legacy chipset. (M14, H13)
 * 		Then this legacy structure is not used from latest chip (H15, LM15U).
 */
typedef struct
{
	RTK_VR_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T pixelFormat;
	unsigned short	stride;
	unsigned short	width;
	unsigned short	height;
	unsigned char	*pVideoFrameAddress[3];
} RTK_VR_LEGACY_VIDEO_FRAME_INFO_T;

/**
 * @brief This structure describes property information of video frame output device.
 */
typedef struct
{
	RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T stateInfo;
	unsigned int framerate;
	RTK_VR_DUMP_LOCATION_TYPE_T dumpLocation;
	RTK_VR_RECT_T outputRegion;
	unsigned char bBlockState;
} RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T;
#endif

/*-----------------------------------------------------------------------------
	Definition of struct for IO ctrl cmd(all parameters include in the same struct)
------------------------------------------------------------------------------*/
/*
VR_IOC_GET_VFB_CAPABILITY
*/
typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T vfbCapInfo;
}KADP_VR_VFB_CAPINFO_T;

/*
VR_IOC_GET_VFOD_CAPABILITY
*/
typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_CAPABILITY_INFO_T vfodCapInfo;
}KADP_VR_VFOD_CAPINFO_T;

/*
VR_IOC_GET_VFOD_LIMITATION
*/
typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_LIMITATION_INFO_T vfodlimitationInfo;
}KADP_VR_VFOD_LIMITATIONINFO_T;

/*
VR_IOC_GET_ALLVFB_PROPERTY

*/
typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T vfbProInfo;
}KADP_VR_VFB_PROPERTY_T;

/*
VR_IOC_GET_VFB_INDEX
*/
typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	unsigned int IndexCurVFB;
}KADP_VR_GET_VFBINDEX_T;

/*
VR_IOC_GET_VFOD_STATE
*/
typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T VFODstate;
}KADP_VR_VFOD_GET_STATEINFO_T;

/*
VR_IOC_SET_VFOD_STATE
*/
typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FLAGS_T vfodStateFlag;
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T VFODstate;
}KADP_VR_VFOD_SET_STATEINFO_T;


/*
VR_IOC_GET_VFOD_FRAMERATE
*/
typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	unsigned int framerate;
}KADP_VR_VFOD_GET_FRAMERATE_T;

typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_DUMP_LOCATION_TYPE_T DumpLocation;
}KADP_VR_VFOD_GET_DUMPLOCATION_T;

typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_DUMP_LOCATION_TYPE_T DumpLocation;
}KADP_VR_VFOD_SET_DUMPLOCATION_T;

typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_DUMP_LOCATION_TYPE_T DumpLocation;
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_OUTPUT_INFO_T OutputInfo;
}KADP_VR_VFOD_GET_OUTPUTINFO_T;

typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_DUMP_LOCATION_TYPE_T DumpLocation;
	KADP_VR_RECT_T OutputRegion;
}KADP_VR_VFOD_SET_OUTPUTREGION_T;

typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_INPUT_VIDEO_INFO_T InputVideoInfo;
}KADP_VR_GET_INPUTVIDEOINFO_T;

typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_OUTPUT_VIDEO_INFO_T OutputVideoInfo;
}KADP_VR_GET_OUTPUTVIDEOINFO_T;

typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	unsigned char bOnOff;
}KADP_VR_GET_VIDEOMUTESTATUS_T;

typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	unsigned char IsSecureVideo;
}KADP_VR_GET_VFBSVSTATE_T;

typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	unsigned char bBlockState;
}KADP_VR_GET_VFODBLOCKSTATE_T;

typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	unsigned char bBlockState;
}KADP_VR_SET_VFODBLOCKSTATE_T;

//Evance@20160622- google hangout start
typedef struct
{
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T stateInfo;
	unsigned int framerate;
	KADP_VR_DUMP_LOCATION_TYPE_T dumpLocation;
	KADP_VR_RECT_T outputRegion;
	unsigned char bBlockState;
} KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T;


typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T VideoFrameOutputDeviceProperty;
}KADP_VR_GET_VFODProperty_T;

typedef struct
{
	KADP_VR_VIDEO_WINDOW_TYPE_T wid;
	KADP_VR_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T VideoFrameOutputDeviceProperty;
}KADP_VR_SET_VFODProperty_T;

typedef struct
{
	bool enable;
	KADP_VR_RECT_T OutputRegion;
	unsigned long phyaddr;
	unsigned int	width;
	unsigned int	height;	
}KADP_VR_ROWDATA_SHOW_ONSUBDISP_T;

#if 0
/*-----------------------------------------------------------------------------
	Definition of struct for IO ctrl cmd(all parameters include in the same struct)
------------------------------------------------------------------------------*/
/*
VR_IOC_GET_VFB_CAPABILITY
*/
typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	RTK_VR_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T vfbCapInfo;
}VR_VFB_CAPINFO_T;

/*
VR_IOC_GET_VFOD_CAPABILITY
*/
typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_CAPABILITY_INFO_T vfodCapInfo;
}VR_VFOD_CAPINFO_T;

/*
VR_IOC_GET_VFOD_LIMITATION
*/
typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_LIMITATION_INFO_T vfodlimitationInfo;
}VR_VFOD_LIMITATIONINFO_T;

/*
VR_IOC_GET_ALLVFB_PROPERTY

*/
typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	RTK_VR_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T vfbProInfo;
}VR_VFB_PROPERTY_T;

/*
VR_IOC_GET_VFB_INDEX
*/
typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	unsigned int IndexCurVFB;
}VR_GET_VFBINDEX_T;

/*
VR_IOC_GET_VFOD_STATE
*/
typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T VFODstate;
}VR_VFOD_GET_STATEINFO_T;

/*
VR_IOC_SET_VFOD_STATE
*/
typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FLAGS_T vfodStateFlag;
	RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T VFODstate;
}VR_VFOD_SET_STATEINFO_T;


/*
VR_IOC_GET_VFOD_FRAMERATE
*/
typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	unsigned int framerate;
}VR_VFOD_GET_FRAMERATE_T;

typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	RTK_VR_DUMP_LOCATION_TYPE_T DumpLocation;
}VR_VFOD_GET_DUMPLOCATION_T;

typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	RTK_VR_DUMP_LOCATION_TYPE_T DumpLocation;
}VR_VFOD_SET_DUMPLOCATION_T;

typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	RTK_VR_DUMP_LOCATION_TYPE_T DumpLocation;
	RTK_VR_VIDEO_FRAME_OUTPUT_DEVICE_OUTPUT_INFO_T OutputInfo;
}VR_VFOD_GET_OUTPUTINFO_T;

typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	RTK_VR_DUMP_LOCATION_TYPE_T DumpLocation;
	RTK_VR_RECT_T OutputRegion;
}VR_VFOD_SET_OUTPUTREGION_T;

typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	RTK_VR_INPUT_VIDEO_INFO_T InputVideoInfo;
}VR_GET_INPUTVIDEOINFO_T;

typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	RTK_VR_OUTPUT_VIDEO_INFO_T OutputVideoInfo;
}VR_GET_OUTPUTVIDEOINFO_T;

typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	unsigned char bOnOff;
}VR_GET_VIDEOMUTESTATUS_T;

typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	unsigned char IsSecureVideo;
}VR_GET_VFBSVSTATE_T;

typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	unsigned char bBlockState;
}VR_GET_VFODBLOCKSTATE_T;

typedef struct
{
	RTK_VR_VIDEO_WINDOW_TYPE_T wid;
	unsigned char bBlockState;
}VR_SET_VFODBLOCKSTATE_T;

typedef struct
{
	unsigned int i3ddmavi_bufferindex1;
	unsigned int i3ddmavi_bufferindex2;
}VR_I3DDMAVI_BUFFERINDEX;
#endif

typedef struct {
	unsigned char *uncache;
	void *cache;
	unsigned long phyaddr;
	unsigned int size;
	unsigned int getsize;
} VR_CAPTURE_BUFFER_T;

typedef struct {
	VR_CAPTURE_BUFFER_T cap_buffer[5];
} VR_CAPTURE_CTRL_T;

typedef enum _VR_CAP_SRC{
	VR_CAP_SRC_VIDEO_NOPQ,
	VR_CAP_SRC_VIDEO_PQ,
	VR_CAP_SRC_VIDEO_OSD
}VR_CAP_SRC;

typedef enum _VR_CAP_MODE{
	VR_CAP_MODE_SEQ,
	VR_CAP_MODE_BLOCK
}VR_CAP_MODE;

typedef enum _VR_CAP_FMT{
	VR_CAP_RGB888,
	VR_CAP_ARGB8888,
	VR_CAP_ABGR8888,
	VR_CAP_NV12,
	VR_CAP_NV16
}VR_CAP_FMT;

typedef struct {
	unsigned char enable;
	VR_CAP_SRC capSrc;
	VR_CAP_MODE capMode;
	unsigned int capWid;
	unsigned int capLen;
}VR_CUR_CAPTURE_INFO;
/*-----------------------------------------------------------------------------
	rpc struct
------------------------------------------------------------------------------*/
typedef struct{
	UINT32 SwModeEnable;
	UINT32 buffernumber;
	UINT32 cap_buffer[5];
	UINT32 cap_format;
	UINT32 cap_width;
	UINT32 cap_length;
}DC2H_SWMODE_STRUCT_T;

typedef enum _VR_DISPD_I3DDMACAP_SRC{
	I3DDMACAP_SRC_UZU,
	I3DDMACAP_SRC_YUV2RGB,
	I3DDMACAP_SRC_SUBTITLE,
	I3DDMACAP_SRC_OSD,
	I3DDMACAP_SRC_DITHER,
	I3DDMACAP_SRC_UZU_SUB,
	I3DDMACAP_SRC_MEMC_MUX
}VR_DISPD_I3DDMACAP_SRC;

/*-----------------------------------------------------------------------------
	System call
------------------------------------------------------------------------------*/
#define VR_DEVICE_NUM								   1
#define VR_DEVICE_NAME								"vivrdev"
#define VR_IOC_MAGIC								  'r'

#define VR_MAJOR 0   /* dynamic major by default */
#define VR_NR_DEVS 1    /* se0 through se3 */

//index range
//0 ~ 255
#define VR_IOC_START_INDEX 0
enum vt_ioc_idx
{
	VR_IOC_IDX_0 = VR_IOC_START_INDEX,//0
	VR_IOC_IDX_1,
	VR_IOC_IDX_2,
	VR_IOC_IDX_3,
	VR_IOC_IDX_4,
	VR_IOC_IDX_5,
	VR_IOC_IDX_6,
	VR_IOC_IDX_7,
	VR_IOC_IDX_8,
	VR_IOC_IDX_9,
	VR_IOC_IDX_10,
	VR_IOC_IDX_11,
	VR_IOC_IDX_12,
	VR_IOC_IDX_13,
	VR_IOC_IDX_14,
	VR_IOC_IDX_15,
	VR_IOC_IDX_16,
	VR_IOC_IDX_17,
	VR_IOC_IDX_18,
	VR_IOC_IDX_19,
	VR_IOC_IDX_20,
	VR_IOC_IDX_21,
	VR_IOC_IDX_22,
	VR_IOC_IDX_23,
	VR_IOC_IDX_24,
	VR_IOC_IDX_25,
	VR_IOC_IDX_26,
	VR_IOC_MAXNR,
};

#define VR_IOC_INIT										_IO(VR_IOC_MAGIC,  VR_IOC_IDX_1)
#define VR_IOC_FINALIZE									_IO(VR_IOC_MAGIC,  VR_IOC_IDX_2)
#define VR_IOC_GET_DEVICE_CAPABILITY					_IOR(VR_IOC_MAGIC, VR_IOC_IDX_3, unsigned int)
#define VR_IOC_GET_VFB_CAPABILITY						_IOR(VR_IOC_MAGIC, VR_IOC_IDX_4, KADP_VR_VFB_CAPINFO_T)
#define VR_IOC_GET_VFOD_CAPABILITY						_IOR(VR_IOC_MAGIC, VR_IOC_IDX_5, KADP_VR_VFOD_CAPINFO_T)
#define VR_IOC_GET_VFOD_LIMITATION						_IOR(VR_IOC_MAGIC, VR_IOC_IDX_6, KADP_VR_VFOD_CAPINFO_T)
#define VR_IOC_GET_ALLVFB_PROPERTY						_IOR(VR_IOC_MAGIC, VR_IOC_IDX_7, KADP_VR_VFB_PROPERTY_T)
#define VR_IOC_GET_VFB_INDEX							_IOR(VR_IOC_MAGIC, VR_IOC_IDX_8, KADP_VR_GET_VFBINDEX_T)
#define VR_IOC_GET_VFOD_STATE							_IOR(VR_IOC_MAGIC, VR_IOC_IDX_9, KADP_VR_VFOD_GET_STATEINFO_T)
#define VR_IOC_SET_VFOD_STATE							_IOW(VR_IOC_MAGIC, VR_IOC_IDX_10, KADP_VR_VFOD_SET_STATEINFO_T)
#define VR_IOC_GET_VFOD_FRAMERATE						_IOR(VR_IOC_MAGIC, VR_IOC_IDX_11, KADP_VR_VFOD_GET_FRAMERATE_T)
#define VR_IOC_GET_VFOD_DUMPLOCATION					_IOR(VR_IOC_MAGIC, VR_IOC_IDX_12, KADP_VR_VFOD_GET_DUMPLOCATION_T)
#define VR_IOC_SET_VFOD_DUMPLOCATION					_IOW(VR_IOC_MAGIC, VR_IOC_IDX_13, KADP_VR_VFOD_SET_DUMPLOCATION_T)
#define VR_IOC_GET_VFOD_OUTPUTINFO						_IOR(VR_IOC_MAGIC, VR_IOC_IDX_14, KADP_VR_VFOD_GET_OUTPUTINFO_T)
#define VR_IOC_SET_VFOD_OUTPUTREGION					_IOW(VR_IOC_MAGIC, VR_IOC_IDX_15, KADP_VR_VFOD_SET_OUTPUTREGION_T)
#define VR_IOC_WAIT_VSYNC								_IOW(VR_IOC_MAGIC, VR_IOC_IDX_16, RTK_VR_VIDEO_WINDOW_TYPE_T)
#define VR_IOC_GET_INPUTVIDEOINFO						_IOR(VR_IOC_MAGIC, VR_IOC_IDX_17, KADP_VR_GET_INPUTVIDEOINFO_T)
#define VR_IOC_GET_OUTPUTVIDEOINFO						_IOR(VR_IOC_MAGIC, VR_IOC_IDX_18, KADP_VR_GET_OUTPUTVIDEOINFO_T)
#define VR_IOC_GET_VIDEOMUTESTATUS						_IOR(VR_IOC_MAGIC, VR_IOC_IDX_19, KADP_VR_GET_VIDEOMUTESTATUS_T)
#define VR_IOC_GET_VFB_SVSTATE							_IOR(VR_IOC_MAGIC, VR_IOC_IDX_20, KADP_VR_GET_VFBSVSTATE_T)
#define VR_IOC_GET_VFOD_BLOCKSTATE						_IOR(VR_IOC_MAGIC, VR_IOC_IDX_21, KADP_VR_GET_VFODBLOCKSTATE_T)
#define VR_IOC_SET_VFOD_BLOCKSTATE						_IOR(VR_IOC_MAGIC, VR_IOC_IDX_22, KADP_VR_SET_VFODBLOCKSTATE_T)
#define VR_IOC_VFB_DATASHOW_ONSUBDISP					_IOR(VR_IOC_MAGIC, VR_IOC_IDX_23, unsigned char)

#define VR_IOC_INITEX									_IOR(VR_IOC_MAGIC, VR_IOC_IDX_24, unsigned int)
#define VR_IOC_SET_PIXEL_FORMAT						_IOW(VR_IOC_MAGIC, VR_IOC_IDX_25, unsigned int)
#define VR_IOC_ROWDATA_SHOW_ONSUBDISP					_IOW(VR_IOC_MAGIC, VR_IOC_IDX_26, KADP_VR_ROWDATA_SHOW_ONSUBDISP_T)
#endif

