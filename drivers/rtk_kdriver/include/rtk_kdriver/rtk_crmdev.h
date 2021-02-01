///////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Realtek Semiconductor Corp.
///////////////////////////////////////////////////////////////////////////////

#ifndef __REALTEK_AE370AF9_ACFA_4491_8D3E_3374174D097C_H__
#define __REALTEK_AE370AF9_ACFA_4491_8D3E_3374174D097C_H__

//
// Please synchronize with rtkhal/hal_src/libkadaptor/src/crm/rtk_crmdev.h
//

#define MAX_REFERENCES_COUNT (16)
#define MAX_PROVIDER_COUNT (32)
#define MAX_REQUIRES_COUNT (8)
#define MAX_FORMAT_COUNT (96)
#define MAX_RECORDS_COUNT (8)
#define MAX_MONITOR_COUNT (8)
#define MAX_CAPABILITY_COUNT (16)

typedef enum _rtk_crmdev_cmd_t {
  RTK_CRMDEV_CMD_NONE,
  RTK_CRMDEV_CMD_RESET,
  RTK_CRMDEV_CMD_SET_NAME,
  RTK_CRMDEV_CMD_ADD_PROVIDER,
  RTK_CRMDEV_CMD_ADD_REFERENCE,
  RTK_CRMDEV_CMD_ADD_FORMAT,
  RTK_CRMDEV_CMD_ADD_REQUIRE,
  RTK_CRMDEV_CMD_ADD_CAPABILITY,
  RTK_CRMDEV_CMD_ACQUIRE_RESOURCE,
  RTK_CRMDEV_CMD_REGISTER_RESOURCE,
  RTK_CRMDEV_CMD_RELEASE_RESOURCE,
  RTK_CRMDEV_CMD_CHECK_SUPPORT,
  RTK_CRMDEV_CMD_CHECK_CAPABILITY,
  RTK_CRMDEV_CMD_WAIT_EVENT,
  RTK_CRMDEV_CMD_CANCEL_EVENT,
  RTK_CRMDEV_CMD_RESPONSE_RECLAIM,
  RTK_CRMDEV_CMD_RESPONSE_PRIORITY,
} rtk_crmdev_cmd_t;

typedef enum _rtk_crmdev_status_t {
  RTK_CRMDEV_STATUS_OK,
  RTK_CRMDEV_STATUS_ERROR,
  RTK_CRMDEV_STATUS_INVALID_CMD,
  RTK_CRMDEV_STATUS_INVALID_UNIQUE_ID,
  RTK_CRMDEV_STATUS_INVALID_RESOURCE,
  RTK_CRMDEV_STATUS_INVALID_XML,
  RTK_CRMDEV_STATUS_NO_RESOURCE,
  RTK_CRMDEV_STATUS_NO_SLOTS,
  RTK_CRMDEV_STATUS_UNSUPPORT,
  RTK_CRMDEV_STATUS_UNIMPLEMENT,
  RTK_CRMDEV_STATUS_CANCEL,
  RTK_CRMDEV_STATUS_RECLAIM,
  RTK_CRMDEV_STATUS_PRIORITY,
} rtk_crmdev_status_t;

typedef enum _rtk_crmdev_codec_type_t {

  /* none */
  RTK_CRMDEV_CODEC_TYPE_NONE = 0x0000,

  /* video */
  RTK_CRMDEV_CODEC_TYPE_VIDEO = 0x1000,
  RTK_CRMDEV_CODEC_TYPE_AVC,
  RTK_CRMDEV_CODEC_TYPE_HEVC,
  RTK_CRMDEV_CODEC_TYPE_MPEG2,
  RTK_CRMDEV_CODEC_TYPE_MPEG4,
  RTK_CRMDEV_CODEC_TYPE_WMV7,
  RTK_CRMDEV_CODEC_TYPE_WMV8,
  RTK_CRMDEV_CODEC_TYPE_WMV9,
  RTK_CRMDEV_CODEC_TYPE_VC1,
  RTK_CRMDEV_CODEC_TYPE_VP6,
  RTK_CRMDEV_CODEC_TYPE_VP8,
  RTK_CRMDEV_CODEC_TYPE_VP9,
  RTK_CRMDEV_CODEC_TYPE_H263,
  RTK_CRMDEV_CODEC_TYPE_RV,
  RTK_CRMDEV_CODEC_TYPE_MJPEG,
  RTK_CRMDEV_CODEC_TYPE_AVS,
  RTK_CRMDEV_CODEC_TYPE_DIVX3,
  RTK_CRMDEV_CODEC_TYPE_DOLBY_VISION,
  RTK_CRMDEV_CODEC_TYPE_JPEG,
  RTK_CRMDEV_CODEC_TYPE_PNG,
  RTK_CRMDEV_CODEC_TYPE_UNKNOWN_VP0,
  RTK_CRMDEV_CODEC_TYPE_UNKNOWN_VP1,
  RTK_CRMDEV_CODEC_TYPE_SOURCE_ATV,
  RTK_CRMDEV_CODEC_TYPE_SOURCE_AV,
  RTK_CRMDEV_CODEC_TYPE_SOURCE_YPP,
  RTK_CRMDEV_CODEC_TYPE_SOURCE_VGA,
  RTK_CRMDEV_CODEC_TYPE_SOURCE_HDMI,
  RTK_CRMDEV_CODEC_TYPE_AVS2,
  RTK_CRMDEV_CODEC_TYPE_DTV_AVC,
  RTK_CRMDEV_CODEC_TYPE_DTV_HEVC,
  RTK_CRMDEV_CODEC_TYPE_DTV_MPEG2,
  RTK_CRMDEV_CODEC_TYPE_DTV_AVS,

  /* audio */
  RTK_CRMDEV_CODEC_TYPE_AUDIO = 0x2000,
  RTK_CRMDEV_CODEC_TYPE_PCM,
  RTK_CRMDEV_CODEC_TYPE_G711MLAW,
  RTK_CRMDEV_CODEC_TYPE_G711ALAW,
  RTK_CRMDEV_CODEC_TYPE_ADPCM,
  RTK_CRMDEV_CODEC_TYPE_G726,
  RTK_CRMDEV_CODEC_TYPE_AAC_LATM,
  RTK_CRMDEV_CODEC_TYPE_AAC_ADTS,
  RTK_CRMDEV_CODEC_TYPE_MP1,
  RTK_CRMDEV_CODEC_TYPE_MP2,
  RTK_CRMDEV_CODEC_TYPE_MP3,
  RTK_CRMDEV_CODEC_TYPE_AMRNB,
  RTK_CRMDEV_CODEC_TYPE_AMRWB,
  RTK_CRMDEV_CODEC_TYPE_AMRWB_PLUS,
  RTK_CRMDEV_CODEC_TYPE_VORBIS,
  RTK_CRMDEV_CODEC_TYPE_OPUS,
  RTK_CRMDEV_CODEC_TYPE_AC3,
  RTK_CRMDEV_CODEC_TYPE_EAC3,
  RTK_CRMDEV_CODEC_TYPE_DTS,
  RTK_CRMDEV_CODEC_TYPE_DTS_HD,
  RTK_CRMDEV_CODEC_TYPE_WMA,
  RTK_CRMDEV_CODEC_TYPE_WMAPRO,
  RTK_CRMDEV_CODEC_TYPE_RA_COOK,
  RTK_CRMDEV_CODEC_TYPE_RA_RA1,
  RTK_CRMDEV_CODEC_TYPE_RA_LSD,
  RTK_CRMDEV_CODEC_TYPE_FLAC,
  RTK_CRMDEV_CODEC_TYPE_DV,
  RTK_CRMDEV_CODEC_TYPE_MLP,
  RTK_CRMDEV_CODEC_TYPE_SILK,
  RTK_CRMDEV_CODEC_TYPE_G729,
  RTK_CRMDEV_CODEC_TYPE_APE,
  RTK_CRMDEV_CODEC_TYPE_ALAC,

} rtk_crmdev_codec_type_t;

typedef enum _rtk_crmdev_core_type_t {
  RTK_CRMDEV_CORE_TYPE_NONE = 0,
  RTK_CRMDEV_CORE_TYPE_IP1 = 1,
  RTK_CRMDEV_CORE_TYPE_IP2 = 2,
} rtk_crmdev_core_type_t;

typedef enum _rtk_crmdev_video_port_t {
  RTK_CRMDEV_VIDEO_PORT_NONE = 0,
  RTK_CRMDEV_VIDEO_PORT_0 = 1,
  RTK_CRMDEV_VIDEO_PORT_1 = 2,
} rtk_crmdev_video_port_t;

typedef enum _rtk_crmdev_audio_port_t {
  RTK_CRMDEV_AUDIO_PORT_NONE = 0,
  RTK_CRMDEV_AUDIO_PORT_0 = 1,
  RTK_CRMDEV_AUDIO_PORT_1 = 2,
} rtk_crmdev_audio_port_t;

typedef enum _rtk_crmdev_mixer_port_t {
  RTK_CRMDEV_MIXER_PORT_NONE = 0,
  RTK_CRMDEV_MIXER_PORT_0 = 1,
  RTK_CRMDEV_MIXER_PORT_1 = 2,
  RTK_CRMDEV_MIXER_PORT_2 = 4,
  RTK_CRMDEV_MIXER_PORT_3 = 8,
  RTK_CRMDEV_MIXER_PORT_4 = 16,
  RTK_CRMDEV_MIXER_PORT_5 = 32,
  RTK_CRMDEV_MIXER_PORT_6 = 64,
  RTK_CRMDEV_MIXER_PORT_7 = 128,
} rtk_crmdev_mixer_port_t;

typedef struct _rtk_crmdev_reference_t rtk_crmdev_reference_t;
typedef struct _rtk_crmdev_provider_t rtk_crmdev_provider_t;
typedef struct _rtk_crmdev_require_t rtk_crmdev_require_t;
typedef struct _rtk_crmdev_format_t rtk_crmdev_format_t;
typedef struct _rtk_crmdev_codec_resource_t rtk_crmdev_codec_resource_t;

struct _rtk_crmdev_reference_t {
  char name[16];
};

struct _rtk_crmdev_provider_t {
  char name[16];
  int32_t capacity;
};

struct _rtk_crmdev_require_t {
  char name[16];
  int32_t cost;
};

struct _rtk_crmdev_format_t {
  char name[16];
  int32_t codec;
  int32_t width;
  int32_t height;
  int32_t fps;
  int32_t encoder;
};

struct _rtk_crmdev_codec_resource_t {
  rtk_crmdev_core_type_t core_type;
  rtk_crmdev_video_port_t video_port;
  rtk_crmdev_audio_port_t audio_port;
  rtk_crmdev_mixer_port_t mixer_port;
  int32_t max_width;
  int32_t max_height;
  int32_t encoder;
  uint32_t reserved[9];
};

typedef struct _rtk_crmdev_codec_info_t {
  int32_t codec;
  int32_t max_width;
  int32_t max_height;
  int32_t fps;
  int32_t encoder;
  int32_t adaptive;
  int32_t try_acquire;
  uint32_t reserved[9];
} rtk_crmdev_codec_info_t;

typedef struct _rtk_crmdev_set_name_t {
  char name[32];
  int32_t unique_id;
} rtk_crmdev_set_name_t;

typedef struct _rtk_crmdev_acquire_resource_t {
  rtk_crmdev_codec_info_t info;
  rtk_crmdev_codec_resource_t resource;
} rtk_crmdev_acquire_resource_t;

typedef struct _rtk_crmdev_register_resource_t {
  int32_t unique_id;
  rtk_crmdev_codec_resource_t resource;
} rtk_crmdev_register_resource_t;

typedef struct _rtk_crmdev_check_support_t {
  rtk_crmdev_codec_info_t info;
} rtk_crmdev_check_support_t;

typedef struct _rtk_crmdev_response_reclaim_t {
  int32_t accept;
} rtk_crmdev_response_reclaim_t;

typedef struct _rtk_crmdev_response_priority_t {
  int32_t priority;
} rtk_crmdev_response_priority_t;

typedef struct _rtk_crmdev_capability_t {
  char name[32];
} rtk_crmdev_capability_t;

typedef union _rtk_crmdev_data_t {
  rtk_crmdev_provider_t add_provider;
  rtk_crmdev_reference_t add_reference;
  rtk_crmdev_require_t add_require;
  rtk_crmdev_format_t add_format;
  rtk_crmdev_capability_t add_capability;
  rtk_crmdev_set_name_t set_name;
  rtk_crmdev_acquire_resource_t acquire_resource;
  rtk_crmdev_register_resource_t register_resource;
  rtk_crmdev_check_support_t check_support;
  rtk_crmdev_capability_t check_capability;
  rtk_crmdev_response_reclaim_t response_reclaim;
  rtk_crmdev_response_priority_t response_priority;
} rtk_crmdev_data_t;

typedef struct _rtk_crmdev_request {
  rtk_crmdev_cmd_t cmd;
  rtk_crmdev_status_t status;
  rtk_crmdev_data_t data;
} rtk_crmdev_request;

#define RTK_CRMMGR_PROC_DIR "rtkcrmmgr"
#define RTK_CRMMGR_DEVICE_PATH "/dev/rtkcrmmgr"
#define RTK_CRMMGR_IOC_MAGIC 'm'
#define RTK_CRMMGR_IOC_REQUEST \
  _IOWR(RTK_CRMMGR_IOC_MAGIC, 5, rtk_crmdev_request)

#endif /* __REALTEK_AE370AF9_ACFA_4491_8D3E_3374174D097C_H__ */
