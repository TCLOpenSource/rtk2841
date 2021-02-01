#ifndef _HAL_VT_H_
#define _HAL_VT_H_
/*-----------------------------------------------------------------------------
	Definition of struct for IO ctrl cmd(all parameters include in the same struct)
------------------------------------------------------------------------------*/

/**
 * @brief This enumeration describes the supported number of plane corresponding to plane type of video frame buffer.
 */
typedef enum
{
	KADP_VT_VIDEO_FRAME_BUFFER_PLANE_INTERLEAVED = 1,
	KADP_VT_VIDEO_FRAME_BUFFER_PLANE_SEMI_PLANAR,
	KADP_VT_VIDEO_FRAME_BUFFER_PLANE_PLANAR
} KADP_VT_VIDEO_FRAME_BUFFER_PLANE_NUMBER_T;

/**
 * @brief This enumeration describes the supported pixel format of video frame buffer.
 */
typedef enum
{
	KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_PLANAR = 0,
	KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_SEMI_PLANAR,
	KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_INTERLEAVED,
	KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_PLANAR,
	KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_SEMI_PLANAR,
	KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_INTERLEAVED,
	KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_PLANAR,
	KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_SEMI_PLANAR,
	KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_INTERLEAVED,
	KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_RGB,
	KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_ARGB
} KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T;

/**
 * @brief This enumeration describes the supported video window.
 */
typedef enum
{
	KADP_VT_VIDEO_INVALID_WINDOW = -1,
	KADP_VT_VIDEO_WINDOW_0 = 0,
	KADP_VT_VIDEO_WINDOW_1 = 1,
	KADP_VT_VIDEO_WINDOW_2 = 2
} KADP_VT_VIDEO_WINDOW_TYPE_T;

/**
 * @brief This enumeration describes flags for state of video frame output device setting.
 */
typedef enum
{
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_NOFX 			= 0x00000000,
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_ENABLED 			= 0x00000001,
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FREEZED			= 0x00000002,
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_APPLIED_PQ		= 0x00000004,
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FRAMERATE_DIVIDE	= 0x00000010
} KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FLAGS_T;

/**
 * @brief This enumeration describes the dump location of video memory.
 */
typedef enum
{
	KADP_VT_SCALER_OUTPUT = 0,
	KADP_VT_DISPLAY_OUTPUT,
	KADP_VT_OSDVIDEO_OUTPUT
} KADP_VT_DUMP_LOCATION_TYPE_T;

/**
 * @brief This enumeration describes the type of video.
 */
typedef enum
{
	KADP_VT_VIDEO_INTERLACED	= 0,
	KADP_VT_VIDEO_PROGRESSIVE
} KADP_VT_VIDEO_TYPE_T;
	
/**
 * @brief This enumeration describes the supported video window.
 */
typedef enum
{
	RTK_VT_VIDEO_INVALID_WINDOW = -1,
	RTK_VT_VIDEO_WINDOW_0 = 0,
	RTK_VT_VIDEO_WINDOW_1 = 1,
	RTK_VT_VIDEO_WINDOW_2 = 2
} RTK_VT_VIDEO_WINDOW_TYPE_T;

/**
 * @brief This structure describes a rectangle specified by a point and a dimension.
 */
typedef struct
{
	unsigned short	x;
	unsigned short	y;
	unsigned short	w;
	unsigned short	h;
} KADP_VT_RECT_T;

/**
 * @brief This structure describes the capability of video device.
 */
typedef struct
{
	unsigned int	numOfVideoWindow;
} KADP_VT_DEVICE_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the capability of video frame buffer.
 */
typedef struct
{
	unsigned int numOfVideoFrameBuffer;
	KADP_VT_VIDEO_FRAME_BUFFER_PLANE_NUMBER_T numOfPlane;
} KADP_VT_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the capability of video frame output device.
 */
typedef struct
{
	unsigned char	bSupportedControlEnabled;
	unsigned char	bSupportedControlFreezed;
	unsigned char	bSupportedControlFramerateDivide;
	unsigned char	bSupportedControlPQ;
} KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the limitation of video frame output device.
 */
typedef struct {
	KADP_VT_RECT_T 	maxResolution;
	unsigned char	bLeftTopAlign;
	unsigned char	bSupportInputVideoDeInterlacing;
	unsigned char	bSupportDisplayVideoDeInterlacing;
	unsigned char	bSupportScaleUp;
	unsigned int	scaleUpLimitWidth;
	unsigned int	scaleUpLimitHeight;
	unsigned char	bSupportScaleDown;
	unsigned int	scaleDownLimitWidth;
	unsigned int	scaleDownLimitHeight;
} KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_LIMITATION_INFO_T;

/**
 * @brief This structure describes the constant property of video frame buffer.
 * These member values are unique properties of video frame buffer. it is not able to be changed.
 */
typedef struct
{
	KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T pixelFormat;
	unsigned int	stride;
	unsigned int	width;
	unsigned int	height;
	unsigned int	ppPhysicalAddress0;
	unsigned int	ppPhysicalAddress1;
	unsigned int	ppPhysicalAddress2;
	unsigned int	ppPhysicalAddress3;
	unsigned int	ppPhysicalAddress4;
	unsigned int	vfbbuffernumber; //supporting of continuous capture feature in WebOS 4.0
} KADP_VT_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T;

/**
 * @brief This structure describes state information of video frame output device.
 */
typedef struct
{
	unsigned char	bEnabled;
	unsigned char	bFreezed;
	unsigned char	bAppliedPQ;
	unsigned int	framerateDivide;
} KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T;

/**
 * @brief This structure describes information of input video.
 */
typedef struct {
	KADP_VT_VIDEO_TYPE_T			type;
	KADP_VT_RECT_T				region;
	unsigned char				bIs3DVideo;
} KADP_VT_INPUT_VIDEO_INFO_T;

/**
 * @brief This structure describes information of output video.
 */
typedef struct {
	KADP_VT_VIDEO_TYPE_T			type;
	KADP_VT_RECT_T				maxRegion;
	KADP_VT_RECT_T				activeRegion;
} KADP_VT_OUTPUT_VIDEO_INFO_T;

/**
 * @brief This structure describes output information of video frame output device.
 */
typedef struct {
	unsigned int	stride;
	KADP_VT_RECT_T	maxRegion;
	KADP_VT_RECT_T	activeRegion;
} KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_OUTPUT_INFO_T;

/**
 * @brief This structure describes information of captured video frame
 * 		This legacy structure will be used to support legacy chipset. (M14, H13)
 * 		Then this legacy structure is not used from latest chip (H15, LM15U).
 */
typedef struct
{
	KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T pixelFormat;
	unsigned short	stride;
	unsigned short	width;
	unsigned short	height;
	unsigned char	*pVideoFrameAddress[3];
} KADP_VT_LEGACY_VIDEO_FRAME_INFO_T;

#if 0
/**
 * @brief This enumeration describes the supported number of plane corresponding to plane type of video frame buffer.
 */
typedef enum
{
	RTK_VT_VIDEO_FRAME_BUFFER_PLANE_INTERLEAVED = 1,
	RTK_VT_VIDEO_FRAME_BUFFER_PLANE_SEMI_PLANAR,
	RTK_VT_VIDEO_FRAME_BUFFER_PLANE_PLANAR
} RTK_VT_VIDEO_FRAME_BUFFER_PLANE_NUMBER_T;

/**
 * @brief This enumeration describes the supported pixel format of video frame buffer.
 */
typedef enum
{
	RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_PLANAR = 0,
	RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_SEMI_PLANAR,
	RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_INTERLEAVED,
	RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_PLANAR,
	RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_SEMI_PLANAR,
	RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_INTERLEAVED,
	RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_PLANAR,
	RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_SEMI_PLANAR,
	RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_INTERLEAVED,
	RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_RGB,
	RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_ARGB
} RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T;

/**
 * @brief This enumeration describes flags for state of video frame output device setting.
 */
typedef enum
{
	RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_NOFX 			= 0x00000000,
	RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_ENABLED 			= 0x00000001,
	RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FREEZED			= 0x00000002,
	RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_APPLIED_PQ		= 0x00000004,
	RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FRAMERATE_DIVIDE	= 0x00000010
} RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FLAGS_T;

/**
 * @brief This enumeration describes the dump location of video memory.
 */
typedef enum
{
	RTK_VT_SCALER_OUTPUT = 0,
	RTK_VT_DISPLAY_OUTPUT
} RTK_VT_DUMP_LOCATION_TYPE_T;

/**
 * @brief This enumeration describes the type of video.
 */
typedef enum
{
	RTK_VT_VIDEO_INTERLACED	= 0,
	RTK_VT_VIDEO_PROGRESSIVE
} RTK_VT_VIDEO_TYPE_T;

/**
 * @brief This structure describes a rectangle specified by a point and a dimension.
 */
typedef struct
{
	unsigned short	x;
	unsigned short	y;
	unsigned short	w;
	unsigned short	h;
} RTK_VT_RECT_T;

/**
 * @brief This structure describes the capability of video device.
 */
typedef struct
{
	unsigned int	numOfVideoWindow;
} RTK_VT_DEVICE_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the capability of video frame buffer.
 */
typedef struct
{
	unsigned int numOfVideoFrameBuffer;
	RTK_VT_VIDEO_FRAME_BUFFER_PLANE_NUMBER_T numOfPlane;
} RTK_VT_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the capability of video frame output device.
 */
typedef struct
{
	unsigned char	bSupportedControlEnabled;
	unsigned char	bSupportedControlFreezed;
	unsigned char	bSupportedControlFramerateDivide;
	unsigned char	bSupportedControlPQ;
} RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the limitation of video frame output device.
 */
typedef struct {
	RTK_VT_RECT_T 	maxResolution;
	unsigned char	bLeftTopAlign;
	unsigned char	bSupportInputVideoDeInterlacing;
	unsigned char	bSupportDisplayVideoDeInterlacing;
	unsigned char	bSupportScaleUp;
	unsigned int	scaleUpLimitWidth;
	unsigned int	scaleUpLimitHeight;
	unsigned char	bSupportScaleDown;
	unsigned int	scaleDownLimitWidth;
	unsigned int	scaleDownLimitHeight;
} RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_LIMITATION_INFO_T;

/**
 * @brief This structure describes the constant property of video frame buffer.
 * These member values are unique properties of video frame buffer. it is not able to be changed.
 */
typedef struct
{
	RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T pixelFormat;
	unsigned int	stride;
	unsigned int	width;
	unsigned int	height;
	unsigned int	ppPhysicalAddress0;
	unsigned int	ppPhysicalAddress1;
	unsigned int	ppPhysicalAddress2;
	unsigned int	ppPhysicalAddress3;
	unsigned int	ppPhysicalAddress4;
	unsigned int	vfbbuffernumber;
} RTK_VT_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T;

/**
 * @brief This structure describes state information of video frame output device.
 */
typedef struct
{
	unsigned char	bEnabled;
	unsigned char	bFreezed;
	unsigned char	bAppliedPQ;
	unsigned int	framerateDivide;
} RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T;

/**
 * @brief This structure describes information of input video.
 */
typedef struct {
	RTK_VT_VIDEO_TYPE_T			type;
	RTK_VT_RECT_T				region;
	unsigned char				bIs3DVideo;
} RTK_VT_INPUT_VIDEO_INFO_T;

/**
 * @brief This structure describes information of output video.
 */
typedef struct {
	RTK_VT_VIDEO_TYPE_T			type;
	RTK_VT_RECT_T				maxRegion;
	RTK_VT_RECT_T				activeRegion;
} RTK_VT_OUTPUT_VIDEO_INFO_T;

/**
 * @brief This structure describes output information of video frame output device.
 */
typedef struct {
	unsigned int	stride;
	RTK_VT_RECT_T	maxRegion;
	RTK_VT_RECT_T	activeRegion;
} RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_OUTPUT_INFO_T;

/**
 * @brief This structure describes information of captured video frame
 * 		This legacy structure will be used to support legacy chipset. (M14, H13)
 * 		Then this legacy structure is not used from latest chip (H15, LM15U).
 */
typedef struct
{
	RTK_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T pixelFormat;
	unsigned short	stride;
	unsigned short	width;
	unsigned short	height;
	unsigned char	*pVideoFrameAddress[3];
} RTK_VT_LEGACY_VIDEO_FRAME_INFO_T;

/**
 * @brief This structure describes property information of video frame output device.
 */
typedef struct
{
	RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T stateInfo;
	unsigned int framerate;
	RTK_VT_DUMP_LOCATION_TYPE_T dumpLocation;
	RTK_VT_RECT_T outputRegion;
	unsigned char bBlockState;
} RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T;
#endif

/*-----------------------------------------------------------------------------
	Definition of struct for IO ctrl cmd(all parameters include in the same struct)
------------------------------------------------------------------------------*/
/*
VT_IOC_GET_VFB_CAPABILITY
*/
typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T vfbCapInfo;
}KADP_VT_VFB_CAPINFO_T;

/*
VT_IOC_GET_VFOD_CAPABILITY
*/
typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_CAPABILITY_INFO_T vfodCapInfo;
}KADP_VT_VFOD_CAPINFO_T;

/*
VT_IOC_GET_VFOD_LIMITATION
*/
typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_LIMITATION_INFO_T vfodlimitationInfo;
}KADP_VT_VFOD_LIMITATIONINFO_T;

/*
VT_IOC_GET_ALLVFB_PROPERTY

*/
typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T vfbProInfo;
}KADP_VT_VFB_PROPERTY_T;

/*
VT_IOC_GET_VFB_INDEX
*/
typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	unsigned int IndexCurVFB;
}KADP_VT_GET_VFBINDEX_T;

/*
VT_IOC_GET_VFOD_STATE
*/
typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T VFODstate;
}KADP_VT_VFOD_GET_STATEINFO_T;

/*
VT_IOC_SET_VFOD_STATE
*/
typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FLAGS_T vfodStateFlag;
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T VFODstate;
}KADP_VT_VFOD_SET_STATEINFO_T;


/*
VT_IOC_GET_VFOD_FRAMERATE
*/
typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	unsigned int framerate;
}KADP_VT_VFOD_GET_FRAMERATE_T;

typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_DUMP_LOCATION_TYPE_T DumpLocation;
}KADP_VT_VFOD_GET_DUMPLOCATION_T;

typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_DUMP_LOCATION_TYPE_T DumpLocation;
}KADP_VT_VFOD_SET_DUMPLOCATION_T;

typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_DUMP_LOCATION_TYPE_T DumpLocation;
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_OUTPUT_INFO_T OutputInfo;
}KADP_VT_VFOD_GET_OUTPUTINFO_T;

typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_DUMP_LOCATION_TYPE_T DumpLocation;
	KADP_VT_RECT_T OutputRegion;
}KADP_VT_VFOD_SET_OUTPUTREGION_T;

typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_INPUT_VIDEO_INFO_T InputVideoInfo;
}KADP_VT_GET_INPUTVIDEOINFO_T;

typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_OUTPUT_VIDEO_INFO_T OutputVideoInfo;
}KADP_VT_GET_OUTPUTVIDEOINFO_T;

typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	unsigned char bOnOff;
}KADP_VT_GET_VIDEOMUTESTATUS_T;

typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	unsigned char IsSecureVideo;
}KADP_VT_GET_VFBSVSTATE_T;

typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	unsigned char bBlockState;
}KADP_VT_GET_VFODBLOCKSTATE_T;

typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	unsigned char bBlockState;
}KADP_VT_SET_VFODBLOCKSTATE_T;

//Evance@20160622- google hangout start
typedef struct
{
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T stateInfo;
	unsigned int framerate;
	KADP_VT_DUMP_LOCATION_TYPE_T dumpLocation;
	KADP_VT_RECT_T outputRegion;
	unsigned char bBlockState;
} KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T;


typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T VideoFrameOutputDeviceProperty;
}KADP_VT_GET_VFODProperty_T;

typedef struct
{
	KADP_VT_VIDEO_WINDOW_TYPE_T wid;
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T VideoFrameOutputDeviceProperty;
}KADP_VT_SET_VFODProperty_T;

typedef struct
{
	bool enable;
	KADP_VT_RECT_T OutputRegion;
	unsigned long phyaddr;
	unsigned int	width;
	unsigned int	height;	
}KADP_VT_ROWDATA_SHOW_ONSUBDISP_T;

#if 0
/*-----------------------------------------------------------------------------
	Definition of struct for IO ctrl cmd(all parameters include in the same struct)
------------------------------------------------------------------------------*/
/*
VT_IOC_GET_VFB_CAPABILITY
*/
typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	RTK_VT_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T vfbCapInfo;
}VT_VFB_CAPINFO_T;

/*
VT_IOC_GET_VFOD_CAPABILITY
*/
typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_CAPABILITY_INFO_T vfodCapInfo;
}VT_VFOD_CAPINFO_T;

/*
VT_IOC_GET_VFOD_LIMITATION
*/
typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_LIMITATION_INFO_T vfodlimitationInfo;
}VT_VFOD_LIMITATIONINFO_T;

/*
VT_IOC_GET_ALLVFB_PROPERTY

*/
typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	RTK_VT_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T vfbProInfo;
}VT_VFB_PROPERTY_T;

/*
VT_IOC_GET_VFB_INDEX
*/
typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	unsigned int IndexCurVFB;
}VT_GET_VFBINDEX_T;

/*
VT_IOC_GET_VFOD_STATE
*/
typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T VFODstate;
}VT_VFOD_GET_STATEINFO_T;

/*
VT_IOC_SET_VFOD_STATE
*/
typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FLAGS_T vfodStateFlag;
	RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T VFODstate;
}VT_VFOD_SET_STATEINFO_T;


/*
VT_IOC_GET_VFOD_FRAMERATE
*/
typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	unsigned int framerate;
}VT_VFOD_GET_FRAMERATE_T;

typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	RTK_VT_DUMP_LOCATION_TYPE_T DumpLocation;
}VT_VFOD_GET_DUMPLOCATION_T;

typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	RTK_VT_DUMP_LOCATION_TYPE_T DumpLocation;
}VT_VFOD_SET_DUMPLOCATION_T;

typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	RTK_VT_DUMP_LOCATION_TYPE_T DumpLocation;
	RTK_VT_VIDEO_FRAME_OUTPUT_DEVICE_OUTPUT_INFO_T OutputInfo;
}VT_VFOD_GET_OUTPUTINFO_T;

typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	RTK_VT_DUMP_LOCATION_TYPE_T DumpLocation;
	RTK_VT_RECT_T OutputRegion;
}VT_VFOD_SET_OUTPUTREGION_T;

typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	RTK_VT_INPUT_VIDEO_INFO_T InputVideoInfo;
}VT_GET_INPUTVIDEOINFO_T;

typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	RTK_VT_OUTPUT_VIDEO_INFO_T OutputVideoInfo;
}VT_GET_OUTPUTVIDEOINFO_T;

typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	unsigned char bOnOff;
}VT_GET_VIDEOMUTESTATUS_T;

typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	unsigned char IsSecureVideo;
}VT_GET_VFBSVSTATE_T;

typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	unsigned char bBlockState;
}VT_GET_VFODBLOCKSTATE_T;

typedef struct
{
	RTK_VT_VIDEO_WINDOW_TYPE_T wid;
	unsigned char bBlockState;
}VT_SET_VFODBLOCKSTATE_T;

typedef struct
{
	unsigned int i3ddmavi_bufferindex1;
	unsigned int i3ddmavi_bufferindex2;
}VT_I3DDMAVI_BUFFERINDEX;
#endif

typedef struct {
	unsigned char *uncache;
	void *cache;
	unsigned long phyaddr;
	unsigned int size;
	unsigned int getsize;
} VT_CAPTURE_BUFFER_T;

typedef struct {
	VT_CAPTURE_BUFFER_T cap_buffer[5];
} VT_CAPTURE_CTRL_T;

typedef enum _VT_CAP_SRC{
	VT_CAP_SRC_VIDEO_NOPQ,
	VT_CAP_SRC_VIDEO_PQ,
	VT_CAP_SRC_VIDEO_OSD
}VT_CAP_SRC;

typedef enum _VT_CAP_MODE{
	VT_CAP_MODE_SEQ,
	VT_CAP_MODE_BLOCK
}VT_CAP_MODE;

typedef enum _VT_CAP_FMT{
	VT_CAP_RGB888,
	VT_CAP_ARGB8888,
	VT_CAP_ABGR8888,
	VT_CAP_NV12,
	VT_CAP_NV16
}VT_CAP_FMT;

typedef struct {
	unsigned char enable;
	VT_CAP_SRC capSrc;
	VT_CAP_MODE capMode;
	unsigned int capWid;
	unsigned int capLen;
}VT_CUR_CAPTURE_INFO;
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

/*-----------------------------------------------------------------------------
	System call
------------------------------------------------------------------------------*/
#define VT_DEVICE_NUM								   1
#define VT_DEVICE_NAME								"vivtdev"
#define VT_IOC_MAGIC								  't'

#define VT_MAJOR 0   /* dynamic major by default */
#define VT_NR_DEVS 1    /* se0 through se3 */

//index range
//0 ~ 255
#define VT_IOC_START_INDEX 0
enum vt_ioc_idx
{
	VT_IOC_IDX_0 = VT_IOC_START_INDEX,//0
	VT_IOC_IDX_1,
	VT_IOC_IDX_2,
	VT_IOC_IDX_3,
	VT_IOC_IDX_4,
	VT_IOC_IDX_5,
	VT_IOC_IDX_6,
	VT_IOC_IDX_7,
	VT_IOC_IDX_8,
	VT_IOC_IDX_9,
	VT_IOC_IDX_10,
	VT_IOC_IDX_11,
	VT_IOC_IDX_12,
	VT_IOC_IDX_13,
	VT_IOC_IDX_14,
	VT_IOC_IDX_15,
	VT_IOC_IDX_16,
	VT_IOC_IDX_17,
	VT_IOC_IDX_18,
	VT_IOC_IDX_19,
	VT_IOC_IDX_20,
	VT_IOC_IDX_21,
	VT_IOC_IDX_22,
	VT_IOC_IDX_23,
	VT_IOC_IDX_24,
	VT_IOC_IDX_25,
	VT_IOC_IDX_26,
	VT_IOC_MAXNR,
};

#define VT_IOC_INIT										_IO(VT_IOC_MAGIC,  VT_IOC_IDX_1)
#define VT_IOC_FINALIZE									_IO(VT_IOC_MAGIC,  VT_IOC_IDX_2)
#define VT_IOC_GET_DEVICE_CAPABILITY					_IOR(VT_IOC_MAGIC, VT_IOC_IDX_3, unsigned int)
#define VT_IOC_GET_VFB_CAPABILITY						_IOR(VT_IOC_MAGIC, VT_IOC_IDX_4, KADP_VT_VFB_CAPINFO_T)
#define VT_IOC_GET_VFOD_CAPABILITY						_IOR(VT_IOC_MAGIC, VT_IOC_IDX_5, KADP_VT_VFOD_CAPINFO_T)
#define VT_IOC_GET_VFOD_LIMITATION						_IOR(VT_IOC_MAGIC, VT_IOC_IDX_6, KADP_VT_VFOD_CAPINFO_T)
#define VT_IOC_GET_ALLVFB_PROPERTY						_IOR(VT_IOC_MAGIC, VT_IOC_IDX_7, KADP_VT_VFB_PROPERTY_T)
#define VT_IOC_GET_VFB_INDEX							_IOR(VT_IOC_MAGIC, VT_IOC_IDX_8, KADP_VT_GET_VFBINDEX_T)
#define VT_IOC_GET_VFOD_STATE							_IOR(VT_IOC_MAGIC, VT_IOC_IDX_9, KADP_VT_VFOD_GET_STATEINFO_T)
#define VT_IOC_SET_VFOD_STATE							_IOW(VT_IOC_MAGIC, VT_IOC_IDX_10, KADP_VT_VFOD_SET_STATEINFO_T)
#define VT_IOC_GET_VFOD_FRAMERATE						_IOR(VT_IOC_MAGIC, VT_IOC_IDX_11, KADP_VT_VFOD_GET_FRAMERATE_T)
#define VT_IOC_GET_VFOD_DUMPLOCATION					_IOR(VT_IOC_MAGIC, VT_IOC_IDX_12, KADP_VT_VFOD_GET_DUMPLOCATION_T)
#define VT_IOC_SET_VFOD_DUMPLOCATION					_IOW(VT_IOC_MAGIC, VT_IOC_IDX_13, KADP_VT_VFOD_SET_DUMPLOCATION_T)
#define VT_IOC_GET_VFOD_OUTPUTINFO						_IOR(VT_IOC_MAGIC, VT_IOC_IDX_14, KADP_VT_VFOD_GET_OUTPUTINFO_T)
#define VT_IOC_SET_VFOD_OUTPUTREGION					_IOW(VT_IOC_MAGIC, VT_IOC_IDX_15, KADP_VT_VFOD_SET_OUTPUTREGION_T)
#define VT_IOC_WAIT_VSYNC								_IOW(VT_IOC_MAGIC, VT_IOC_IDX_16, RTK_VT_VIDEO_WINDOW_TYPE_T)
#define VT_IOC_GET_INPUTVIDEOINFO						_IOR(VT_IOC_MAGIC, VT_IOC_IDX_17, KADP_VT_GET_INPUTVIDEOINFO_T)
#define VT_IOC_GET_OUTPUTVIDEOINFO						_IOR(VT_IOC_MAGIC, VT_IOC_IDX_18, KADP_VT_GET_OUTPUTVIDEOINFO_T)
#define VT_IOC_GET_VIDEOMUTESTATUS						_IOR(VT_IOC_MAGIC, VT_IOC_IDX_19, KADP_VT_GET_VIDEOMUTESTATUS_T)
#define VT_IOC_GET_VFB_SVSTATE							_IOR(VT_IOC_MAGIC, VT_IOC_IDX_20, KADP_VT_GET_VFBSVSTATE_T)
#define VT_IOC_GET_VFOD_BLOCKSTATE						_IOR(VT_IOC_MAGIC, VT_IOC_IDX_21, KADP_VT_GET_VFODBLOCKSTATE_T)
#define VT_IOC_SET_VFOD_BLOCKSTATE						_IOR(VT_IOC_MAGIC, VT_IOC_IDX_22, KADP_VT_SET_VFODBLOCKSTATE_T)
#define VT_IOC_VFB_DATASHOW_ONSUBDISP					_IOR(VT_IOC_MAGIC, VT_IOC_IDX_23, unsigned char)

#define VT_IOC_INITEX									_IOR(VT_IOC_MAGIC, VT_IOC_IDX_24, unsigned int)
#define VT_IOC_SET_PIXEL_FORMAT						_IOW(VT_IOC_MAGIC, VT_IOC_IDX_25, unsigned int)
#define VT_IOC_ROWDATA_SHOW_ONSUBDISP					_IOW(VT_IOC_MAGIC, VT_IOC_IDX_26, KADP_VT_ROWDATA_SHOW_ONSUBDISP_T)
#endif

