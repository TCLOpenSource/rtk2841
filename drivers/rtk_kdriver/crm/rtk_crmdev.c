///////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Realtek Semiconductor Corp.
///////////////////////////////////////////////////////////////////////////////

#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/pageremap.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/seq_file.h>
#include <linux/slab.h>
#include <linux/sort.h>
#include <linux/stat.h>
#include <linux/uaccess.h>
#include <linux/wait.h>
#include <linux/freezer.h>

#include <rtk_kdriver/rtk_crmdev.h>

///////////////////////////////////////////////////////////////////////////////
// internal structures
///////////////////////////////////////////////////////////////////////////////

typedef struct _resource_record_t resource_record_t;
typedef struct _resource_client_t resource_client_t;
typedef struct _resource_provider_t resource_provider_t;
typedef struct _resource_require_t resource_require_t;
typedef struct _resource_format_t resource_format_t;
typedef struct _resource_capability_t resource_capability_t;

typedef enum _resource_client_state {
  RESOURCE_CLIENT_STATUS_CANCEL = 0,
  RESOURCE_CLIENT_STATUS_RECLAIM,
  RESOURCE_CLIENT_STATUS_RECLAIM_ACCEPT,
  RESOURCE_CLIENT_STATUS_RECLAIM_REJECT,
  RESOURCE_CLIENT_STATUS_RECLAIM_CLOSE,
  RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY,
  RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY_DONE,
  RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY_CLOSE,
} resource_client_state;

struct _resource_client_t {
  /* reference count */
  struct kref refcount;
  /* specific the list */
  struct list_head list;

  /* basic properties */
  char name[44];
  int32_t unique_id;
  int32_t priority;

  /* event handler */
  wait_queue_head_t event_wait;
  unsigned long state;

  /*reclaim status*/
  bool is_reclaiming;
};

struct _resource_record_t {
  /* Specific the sequence number of record */
  uint32_t seqnum;
  /* Specific if this record is used */
  bool used;
  /* Specific the cost of record */
  int32_t cost;
  /* Specific the acquire time of record */
  uint64_t acquire_time;
  /* Specific the parent provider */
  resource_provider_t *provider;
  /* Specific the acquire client info */
  resource_client_t *owner;
  /* Specific the monitor client infos */
  resource_client_t *monitors[MAX_MONITOR_COUNT];
};

struct _resource_provider_t {
  /* Specific the name of provider */
  char name[16];
  /* Specific the capacity of provider */
  int32_t capacity;
  /* Specific the priority if this provider should be acquire first */
  int32_t acquire_priority;
  /* The size is zero if the provider is group */
  resource_record_t records[MAX_RECORDS_COUNT];
  /* The size is zero if the provider is leaf. pointer to other
   * resource_provider */
  resource_provider_t *references[MAX_REFERENCES_COUNT];
  size_t reference_count;
};

struct _resource_require_t {
  /* Specific the cost of require */
  int32_t cost;
  /* Specific the parent provider */
  resource_provider_t *provider;
};

struct _resource_format_t {
  char name[16];
  int32_t codec;
  int32_t width;
  int32_t height;
  int32_t fps;
  int32_t encoder;
  resource_require_t requires[MAX_REQUIRES_COUNT];
  size_t require_count;
};

struct _resource_capability_t {
  char name[32];
};

typedef struct _resource_table_t {
  resource_provider_t providers[MAX_PROVIDER_COUNT];
  uint32_t provider_count;
  resource_format_t formats[MAX_FORMAT_COUNT];
  uint32_t format_count;
  resource_capability_t capability[MAX_FORMAT_COUNT];
  uint32_t capability_count;
  char buffer[128];
} resource_table_t;

typedef enum _resource_find_target_t {
  RESOURCE_FIND_TARGET_OWNER,
  RESOURCE_FIND_TARGET_MONITOR,
} resource_find_target_t;

static DEFINE_MUTEX(_acquire_lock);
static DEFINE_MUTEX(_table_lock);
static LIST_HEAD(_client_list);
static resource_table_t *_device_table = NULL;

///////////////////////////////////////////////////////////////////////////////
// declare functions
///////////////////////////////////////////////////////////////////////////////

static void _resource_service_release_lock_table(resource_client_t *client,
                                                 rtk_crmdev_request *req);
static inline const char *_resource_provider_get_name(
    const resource_provider_t *provider);

static bool _resource_provider_is_name(const resource_provider_t *provider,
                                       const char *name);

static inline bool _resource_provider_is_group(
    const resource_provider_t *provider);

static bool _resource_provider_contain_unique_id(
    resource_provider_t *provider, int32_t unique_id,
    resource_record_t **target_record, size_t *target_count);

static inline bool _resource_provider_is_leaf(
    const resource_provider_t *provider);

static inline bool _resource_provider_is_group(
    const resource_provider_t *provider);

static bool _resource_provider_contain_client(
    const resource_provider_t *provider, const resource_client_t *client,
    resource_find_target_t target, const resource_record_t **target_record,
    size_t *target_count);

static inline bool _resource_record_is_used(const resource_record_t *record);

static bool _resource_record_contain_monitor(const resource_record_t *record,
                                             const resource_client_t *client);

///////////////////////////////////////////////////////////////////////////////
// codec info
///////////////////////////////////////////////////////////////////////////////

static const char *_codec_type_to_name(int32_t codec_type) {
  switch (codec_type) {
    case RTK_CRMDEV_CODEC_TYPE_VIDEO:
      return "video";
    case RTK_CRMDEV_CODEC_TYPE_AVC:
      return "avc";
    case RTK_CRMDEV_CODEC_TYPE_HEVC:
      return "hevc";
    case RTK_CRMDEV_CODEC_TYPE_MPEG2:
      return "mpeg2";
    case RTK_CRMDEV_CODEC_TYPE_MPEG4:
      return "mpeg4";
    case RTK_CRMDEV_CODEC_TYPE_WMV7:
      return "wmv7";
    case RTK_CRMDEV_CODEC_TYPE_WMV8:
      return "wmv8";
    case RTK_CRMDEV_CODEC_TYPE_WMV9:
      return "wmv9";
    case RTK_CRMDEV_CODEC_TYPE_VC1:
      return "vc1";
    case RTK_CRMDEV_CODEC_TYPE_VP6:
      return "vp6";
    case RTK_CRMDEV_CODEC_TYPE_VP8:
      return "vp8";
    case RTK_CRMDEV_CODEC_TYPE_VP9:
      return "vp9";
    case RTK_CRMDEV_CODEC_TYPE_H263:
      return "h263";
    case RTK_CRMDEV_CODEC_TYPE_RV:
      return "rv";
    case RTK_CRMDEV_CODEC_TYPE_MJPEG:
      return "mjpeg";
    case RTK_CRMDEV_CODEC_TYPE_AVS:
      return "avs";
    case RTK_CRMDEV_CODEC_TYPE_DIVX3:
      return "divx3";
    case RTK_CRMDEV_CODEC_TYPE_DOLBY_VISION:
      return "dolby_vision";
    case RTK_CRMDEV_CODEC_TYPE_JPEG:
      return "jpeg";
    case RTK_CRMDEV_CODEC_TYPE_PNG:
      return "png";
    case RTK_CRMDEV_CODEC_TYPE_UNKNOWN_VP0:
      return "unknown_vp0";
    case RTK_CRMDEV_CODEC_TYPE_UNKNOWN_VP1:
      return "unknown_vp1";
    case RTK_CRMDEV_CODEC_TYPE_SOURCE_ATV:
      return "source_atv";
    case RTK_CRMDEV_CODEC_TYPE_SOURCE_AV:
      return "source_av";
    case RTK_CRMDEV_CODEC_TYPE_SOURCE_YPP:
      return "source_ypp";
    case RTK_CRMDEV_CODEC_TYPE_SOURCE_VGA:
      return "source_vga";
    case RTK_CRMDEV_CODEC_TYPE_SOURCE_HDMI:
      return "source_hdmi";
    case RTK_CRMDEV_CODEC_TYPE_AVS2:
      return "avs2";
    case RTK_CRMDEV_CODEC_TYPE_DTV_AVC:
      return "dtv_avc";
    case RTK_CRMDEV_CODEC_TYPE_DTV_HEVC:
      return "dtv_hevc";
    case RTK_CRMDEV_CODEC_TYPE_DTV_MPEG2:
      return "dtv_mpeg2";
    case RTK_CRMDEV_CODEC_TYPE_DTV_AVS:
      return "dtv_avs";
    case RTK_CRMDEV_CODEC_TYPE_AUDIO:
      return "audio";
    case RTK_CRMDEV_CODEC_TYPE_PCM:
      return "pcm";
    case RTK_CRMDEV_CODEC_TYPE_G711MLAW:
      return "g711mlaw";
    case RTK_CRMDEV_CODEC_TYPE_G711ALAW:
      return "g711alaw";
    case RTK_CRMDEV_CODEC_TYPE_ADPCM:
      return "adpcm";
    case RTK_CRMDEV_CODEC_TYPE_G726:
      return "g726";
    case RTK_CRMDEV_CODEC_TYPE_AAC_LATM:
      return "aac_latm";
    case RTK_CRMDEV_CODEC_TYPE_AAC_ADTS:
      return "aac_adts";
    case RTK_CRMDEV_CODEC_TYPE_MP1:
      return "mp1";
    case RTK_CRMDEV_CODEC_TYPE_MP2:
      return "mp2";
    case RTK_CRMDEV_CODEC_TYPE_MP3:
      return "mp3";
    case RTK_CRMDEV_CODEC_TYPE_AMRNB:
      return "amrnb";
    case RTK_CRMDEV_CODEC_TYPE_AMRWB:
      return "amrwb";
    case RTK_CRMDEV_CODEC_TYPE_AMRWB_PLUS:
      return "amrwb_plus";
    case RTK_CRMDEV_CODEC_TYPE_VORBIS:
      return "vorbis";
    case RTK_CRMDEV_CODEC_TYPE_OPUS:
      return "opus";
    case RTK_CRMDEV_CODEC_TYPE_AC3:
      return "ac3";
    case RTK_CRMDEV_CODEC_TYPE_EAC3:
      return "eac3";
    case RTK_CRMDEV_CODEC_TYPE_DTS:
      return "dts";
    case RTK_CRMDEV_CODEC_TYPE_DTS_HD:
      return "dts_hd";
    case RTK_CRMDEV_CODEC_TYPE_WMA:
      return "wma";
    case RTK_CRMDEV_CODEC_TYPE_WMAPRO:
      return "wmapro";
    case RTK_CRMDEV_CODEC_TYPE_RA_COOK:
      return "ra_cook";
    case RTK_CRMDEV_CODEC_TYPE_RA_RA1:
      return "ra_ra1";
    case RTK_CRMDEV_CODEC_TYPE_RA_LSD:
      return "ra_lsd";
    case RTK_CRMDEV_CODEC_TYPE_FLAC:
      return "flac";
    case RTK_CRMDEV_CODEC_TYPE_DV:
      return "dv";
    case RTK_CRMDEV_CODEC_TYPE_MLP:
      return "mlp";
    case RTK_CRMDEV_CODEC_TYPE_SILK:
      return "silk";
    case RTK_CRMDEV_CODEC_TYPE_G729:
      return "g729";
    case RTK_CRMDEV_CODEC_TYPE_APE:
      return "ape";
    case RTK_CRMDEV_CODEC_TYPE_ALAC:
      return "alac";
    default:
      return "none";
  }
}

static inline bool _codec_info_is_video(const rtk_crmdev_codec_info_t *info) {
  return ((info->codec & RTK_CRMDEV_CODEC_TYPE_VIDEO) ? true : false);
}

static inline bool _codec_info_is_audio(const rtk_crmdev_codec_info_t *info) {
  return ((info->codec & RTK_CRMDEV_CODEC_TYPE_AUDIO) ? true : false);
}

static const char *_codec_info_to_string(const rtk_crmdev_codec_info_t *info) {
  const char *codec_name = _codec_type_to_name(info->codec);
  const char *encoder = info->encoder ? "encoder" : "decoder";
  const char *adaptive = info->encoder ? "adaptive" : "static";
  if (_codec_info_is_video(info)) {
    snprintf(_device_table->buffer, sizeof(_device_table->buffer),
             "codec-info: %s %s %s %dx%dx%d tryAcquire %d", codec_name, encoder, adaptive,
             info->max_width, info->max_height, info->fps, info->try_acquire);
  } else if (_codec_info_is_audio(info)) {
    snprintf(_device_table->buffer, sizeof(_device_table->buffer),
             "codec-info: %s %s", codec_name, encoder);
  } else {
    snprintf(_device_table->buffer, sizeof(_device_table->buffer),
             "codec-info: unknown");
  }
  return _device_table->buffer;
}

///////////////////////////////////////////////////////////////////////////////
// codec resource
///////////////////////////////////////////////////////////////////////////////

/* void CodecResource::setMemberFromName(const Vector<String8>& names) */
static void _codec_resource_set_from_providers(
    rtk_crmdev_codec_resource_t *resource,
    const resource_provider_t **providers, size_t provider_count) {
  size_t i = 0;
  const resource_provider_t *provider = NULL;

  resource->core_type = RTK_CRMDEV_CORE_TYPE_NONE;
  resource->audio_port = RTK_CRMDEV_AUDIO_PORT_NONE;
  resource->video_port = RTK_CRMDEV_VIDEO_PORT_NONE;
  resource->mixer_port = RTK_CRMDEV_MIXER_PORT_NONE;

  for (i = 0; i < provider_count; i++) {
    provider = providers[i];
    if (!strncmp(provider->name, "ip1", sizeof(provider->name))) {
      resource->core_type |= RTK_CRMDEV_CORE_TYPE_IP1;
    } else if (!strncmp(provider->name, "ip2", sizeof(provider->name))) {
      resource->core_type |= RTK_CRMDEV_CORE_TYPE_IP2;
    } else if (!strncmp(provider->name, "adp0", sizeof(provider->name))) {
      resource->audio_port = RTK_CRMDEV_AUDIO_PORT_0;
    } else if (!strncmp(provider->name, "adp1", sizeof(provider->name))) {
      resource->audio_port = RTK_CRMDEV_AUDIO_PORT_1;
    } else if (!strncmp(provider->name, "aep0", sizeof(provider->name))) {
      resource->audio_port = RTK_CRMDEV_AUDIO_PORT_0;
    } else if (!strncmp(provider->name, "aep1", sizeof(provider->name))) {
      resource->audio_port = RTK_CRMDEV_AUDIO_PORT_1;
    } else if (!strncmp(provider->name, "vdp0", sizeof(provider->name))) {
      resource->video_port = RTK_CRMDEV_VIDEO_PORT_0;
    } else if (!strncmp(provider->name, "vdp1", sizeof(provider->name))) {
      resource->video_port = RTK_CRMDEV_VIDEO_PORT_1;
    } else if (!strncmp(provider->name, "vep0", sizeof(provider->name))) {
      resource->video_port = RTK_CRMDEV_VIDEO_PORT_0;
    } else if (!strncmp(provider->name, "vep1", sizeof(provider->name))) {
      resource->video_port = RTK_CRMDEV_VIDEO_PORT_1;
    } else if (!strncmp(provider->name, "amp1", sizeof(provider->name))) {
      resource->mixer_port = RTK_CRMDEV_MIXER_PORT_1;
    } else if (!strncmp(provider->name, "amp2", sizeof(provider->name))) {
      resource->mixer_port = RTK_CRMDEV_MIXER_PORT_2;
    } else if (!strncmp(provider->name, "amp3", sizeof(provider->name))) {
      resource->mixer_port = RTK_CRMDEV_MIXER_PORT_3;
    } else if (!strncmp(provider->name, "amp4", sizeof(provider->name))) {
      resource->mixer_port = RTK_CRMDEV_MIXER_PORT_4;
    } else if (!strncmp(provider->name, "amp5", sizeof(provider->name))) {
      resource->mixer_port = RTK_CRMDEV_MIXER_PORT_5;
    } else if (!strncmp(provider->name, "amp6", sizeof(provider->name))) {
      resource->mixer_port = RTK_CRMDEV_MIXER_PORT_6;
    } else if (!strncmp(provider->name, "amp7", sizeof(provider->name))) {
      resource->mixer_port = RTK_CRMDEV_MIXER_PORT_7;
    }
  }
}

/* void CodecResource::getNameFromMember(Vector<String8> &names,
                                      const Vector<String8> &internals) */
static void _codec_resource_get_providers(
    const rtk_crmdev_codec_resource_t *resource, int32_t unique_id,
    resource_provider_t **providers, size_t *provider_count) {
  size_t i = 0;
  resource_provider_t *provider = NULL;

  for (i = 0; i < _device_table->provider_count; i++) {
    provider = &_device_table->providers[i];
    if (_resource_provider_is_group(provider)) {
      continue;
    }
    if (_resource_provider_contain_unique_id(provider, unique_id, NULL, NULL)) {
      if (_resource_provider_is_name(provider, "ip1")) {
        if (resource->core_type & RTK_CRMDEV_CORE_TYPE_IP1) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "ip2")) {
        if (resource->core_type & RTK_CRMDEV_CORE_TYPE_IP2) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "adp0")) {
        if (resource->audio_port & RTK_CRMDEV_AUDIO_PORT_0) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "adp1")) {
        if (resource->audio_port & RTK_CRMDEV_AUDIO_PORT_1) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "aep0")) {
        if (resource->audio_port & RTK_CRMDEV_AUDIO_PORT_0) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "aep1")) {
        if (resource->audio_port & RTK_CRMDEV_AUDIO_PORT_1) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "vdp0")) {
        if (resource->video_port & RTK_CRMDEV_VIDEO_PORT_0) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "vdp1")) {
        if (resource->video_port & RTK_CRMDEV_VIDEO_PORT_1) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "vep0")) {
        if (resource->video_port & RTK_CRMDEV_VIDEO_PORT_0) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "vep1")) {
        if (resource->video_port & RTK_CRMDEV_VIDEO_PORT_1) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "amp1")) {
        if (resource->mixer_port & RTK_CRMDEV_MIXER_PORT_1) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "amp2")) {
        if (resource->mixer_port & RTK_CRMDEV_MIXER_PORT_2) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "amp3")) {
        if (resource->mixer_port & RTK_CRMDEV_MIXER_PORT_3) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "amp4")) {
        if (resource->mixer_port & RTK_CRMDEV_MIXER_PORT_4) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "amp5")) {
        if (resource->mixer_port & RTK_CRMDEV_MIXER_PORT_5) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "amp6")) {
        if (resource->mixer_port & RTK_CRMDEV_MIXER_PORT_6) {
          providers[(*provider_count)++] = provider;
        }
      } else if (_resource_provider_is_name(provider, "amp7")) {
        if (resource->mixer_port & RTK_CRMDEV_MIXER_PORT_7) {
          providers[(*provider_count)++] = provider;
        }
      }
    }
  }
}

static const char *_codec_resource_to_string(
    const rtk_crmdev_codec_resource_t *resource) {
  snprintf(
      _device_table->buffer, sizeof(_device_table->buffer),
      "codec-resource %s (ip %04x) (vp %04x) (ap %04x) (mp %04x) (w %d) (h "
      "%d)",
      resource->encoder ? "encoder" : "decoder", resource->core_type,
      resource->video_port, resource->audio_port, resource->mixer_port,
      resource->max_width, resource->max_height);
  return _device_table->buffer;
}

///////////////////////////////////////////////////////////////////////////////
// resource client
///////////////////////////////////////////////////////////////////////////////

static uint32_t _client_seqnum = 0;

static inline const char *_resource_client_get_name(
    const resource_client_t *client) {
  return client->name;
}

static inline bool _resource_client_is_equal(const resource_client_t *l,
                                             const resource_client_t *r) {
  return l->unique_id == r->unique_id ? true : false;
}

static inline bool _resource_client_is_unique_id(const resource_client_t *l,
                                                 int32_t unique_id) {
  return l->unique_id == unique_id ? true : false;
}

static inline const char *_resource_client_get_state_name(
    const resource_client_t *client) {
  if (test_bit(RESOURCE_CLIENT_STATUS_CANCEL, &client->state)) {
    return "cancel";
  } else if (test_bit(RESOURCE_CLIENT_STATUS_RECLAIM, &client->state)) {
    return "reclaim";
  } else if (test_bit(RESOURCE_CLIENT_STATUS_RECLAIM_ACCEPT, &client->state)) {
    return "reclaim-accept";
  } else if (test_bit(RESOURCE_CLIENT_STATUS_RECLAIM_REJECT, &client->state)) {
    return "reclaim-reject";
  } else if (test_bit(RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY, &client->state)) {
    return "update-priority";
  } else if (test_bit(RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY_DONE,
                      &client->state)) {
    return "update-priority-done";
  } else {
    return "unknown";
  }
}

static void _resource_client_wake_event(resource_client_t *client,
                                        unsigned long nr) {
  set_bit(nr, &client->state);
  pr_debug("[crmmgr] events   : %s wake up with %s status\n",
          _resource_client_get_name(client),
          _resource_client_get_state_name(client));
  wake_up_interruptible(&client->event_wait);
}

/* invoke by kref_put */
static void _resource_client_finalize(struct kref *ref) {
  resource_client_t *client = container_of(ref, resource_client_t, refcount);
  pr_debug("[crmmgr] finalize : %s %p\n", _resource_client_get_name(client),
          client);
  kfree(client);
}

static inline resource_client_t *_resource_client_ref(
    resource_client_t *client) {
  if (client) {
    kref_get(&client->refcount);
  }
  return client;
}

static inline void _resource_client_unref(resource_client_t *client) {
  if (client) {
    kref_put(&client->refcount, _resource_client_finalize);
  }
}

static bool _resource_client_create(struct file *filp) {
  resource_client_t *client = NULL;
  client = kzalloc(sizeof(resource_client_t), GFP_KERNEL);
  if (client) {
    kref_init(&client->refcount);
    INIT_LIST_HEAD(&client->list);
    init_waitqueue_head(&client->event_wait);
    client->state = 0;
    client->priority = S32_MAX;
    client->is_reclaiming = 0;
    mutex_lock(&_table_lock);
    client->unique_id = ++_client_seqnum;
    list_add(&client->list, &_client_list);
    mutex_unlock(&_table_lock);
  }
  filp->private_data = client;
  pr_debug("[crmmgr] open     : %p %p\n", client, filp);
  return client ? true : false;
}

static void _resource_client_release(struct file *filp) {
  if (filp && filp->private_data) {
    resource_client_t *curr, *next;
    resource_client_t *client = (resource_client_t *)filp->private_data;
    mutex_lock(&_table_lock);
    client->priority = S32_MAX;
    _resource_service_release_lock_table(client, NULL);
    list_for_each_entry_safe(curr, next, &_client_list, list) {
      if (_resource_client_is_equal(curr, client)) {
        list_del(&curr->list);
      }
    }
    if (test_and_clear_bit(RESOURCE_CLIENT_STATUS_RECLAIM_CLOSE,
                           &client->state)) {
      pr_debug("[crmmgr] events   : %s response reclaim close\n",
              _resource_client_get_name(client));
      _resource_client_wake_event(client,
                                  RESOURCE_CLIENT_STATUS_RECLAIM_ACCEPT);
    }
    if (test_and_clear_bit(RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY_CLOSE,
                           &client->state)) {
      pr_debug("[crmmgr] events   : %s response update priority close\n",
              _resource_client_get_name(client));
      _resource_client_wake_event(client,
                                  RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY_DONE);
    }
    mutex_unlock(&_table_lock);
    pr_debug("[crmmgr] release  : %s %p %p\n", _resource_client_get_name(client),
            client, filp);
    _resource_client_unref(client);
    filp->private_data = NULL;
  }
}

/*
 * get the priority for this client. The highest priority will be reclaim
 * first
 */
static inline int32_t _resource_client_get_priority(resource_client_t *client) {
  return client->priority;
}

/*
 * bool CodecClientInfo::reclaim(bool force)
 *
 * It will unlock the resource table, and need to check the resource table
 * again
 * after this operation.
 *
 * return
 *   -EINTR : when has pending signal
 *   -ERESTARTSYS : restart syscall
 *   -ENOMEM : reject reclaim
 */
static int _resource_client_reclaim(resource_client_t *client, bool force) {
  if(client->is_reclaiming == 1) {
      pr_err("[crmmgr] reclaim  : %s is already in reclaim process, just return reject\n",
          _resource_client_get_name(client));
      return -ENOMEM;;
  }

  int ret = 0;
  client->is_reclaiming = 1;
  _resource_client_wake_event(client, RESOURCE_CLIENT_STATUS_RECLAIM);

  pr_err("[crmmgr] events   : %s wait to reclaim response\n",
          _resource_client_get_name(client));

  /* specific if need to send reclaim when close */
  set_bit(RESOURCE_CLIENT_STATUS_RECLAIM_CLOSE, &client->state);

  mutex_unlock(&_table_lock);
  ret = wait_event_freezable(
      client->event_wait,
      test_bit(RESOURCE_CLIENT_STATUS_RECLAIM_ACCEPT, &client->state) ||
          test_bit(RESOURCE_CLIENT_STATUS_RECLAIM_REJECT, &client->state));
  mutex_lock(&_table_lock);

  clear_bit(RESOURCE_CLIENT_STATUS_RECLAIM_CLOSE, &client->state);

  if (unlikely(ret)) {
    if (signal_pending(current)) {
      pr_warning("[crmmgr] events   : %s caught pending signal when reclaim\n",
                 _resource_client_get_name(client));
      return -EINTR;
    }
    return -ERESTARTSYS;
  } else {
    if (test_and_clear_bit(RESOURCE_CLIENT_STATUS_RECLAIM_ACCEPT,
                           &client->state)) {
      return 0;
    } else if (test_and_clear_bit(RESOURCE_CLIENT_STATUS_RECLAIM_REJECT,
                                  &client->state)) {
      return -ENOMEM;
    } else {
      BUG();
    }
  }

  return ret;
}

/*
 * update the priority.
 *
 * It will unlock the resource table, and need to check the resource table
 * again
 * after this operation.
 */
static int _resource_client_update_priority(resource_client_t *client) {
  int ret = 0;

  _resource_client_wake_event(client, RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY);

  pr_debug("[crmmgr] events   : %s wait to update priority\n",
          _resource_client_get_name(client));

  /* specific if need to send update priority when close */
  set_bit(RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY_CLOSE, &client->state);

  mutex_unlock(&_table_lock);
  ret = wait_event_freezable(
      client->event_wait,
      test_bit(RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY_DONE, &client->state));
  mutex_lock(&_table_lock);

  clear_bit(RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY_CLOSE, &client->state);

  if (unlikely(ret)) {
    if (signal_pending(current)) {
      pr_warning(
          "[crmmgr] events   : %s caught pending signal when update "
          "priority\n",
          _resource_client_get_name(client));
      return -EINTR;
    }
    return -ERESTARTSYS;
  } else {
    if (test_and_clear_bit(RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY_DONE,
                           &client->state)) {
      return 0;
    } else {
      BUG();
    }
  }

  return ret;
}

static bool _resource_client_is_monitor(resource_provider_t *provider,
                                       resource_client_t *client) {
  size_t i = 0;
  size_t size = 0;

  /* group provider */
  if (_resource_provider_is_group(provider)) {
    pr_err("[crmmgr] release.error call release on group provider");
    return false;
  }

  /* leaf provider */
  size = MAX_RECORDS_COUNT;
  for (i = 0; i < size; i++) {
    resource_record_t *record = &provider->records[i];
    if (_resource_record_is_used(record)) {
      bool found = false;
      if (_resource_record_contain_monitor(record, client)) {
        found = true;
      }
      if (found) {
        return true;
      }
    }
  }

  return false;
}

///////////////////////////////////////////////////////////////////////////////
// resource record
///////////////////////////////////////////////////////////////////////////////

static inline bool _resource_record_is_used(const resource_record_t *record) {
  return record->used;
}

static inline void _resource_record_clear(resource_record_t *record) {
  record->used = false;
}

static inline uint64_t _resource_record_get_acquire_time(
    const resource_record_t *record) {
  return record->acquire_time;
}

static inline int32_t _resource_record_get_cost(
    const resource_record_t *record) {
  return record->cost;
}

static const char *_resource_record_get_name(const resource_record_t *record) {
  snprintf(_device_table->buffer, sizeof(_device_table->buffer), "record-%08x",
           record->seqnum);
  return _device_table->buffer;
}

static bool _resource_record_has_monitor_space(
    const resource_record_t *record) {
  size_t i = 0;
  size_t size = 0;

  /* check monitors */
  size = MAX_MONITOR_COUNT;
  for (i = 0; i < size; i++) {
    if (!record->monitors[i]) {
      return true;
    }
  }
  return false;
}

static bool _resource_record_add_monitor(resource_record_t *record,
                                         resource_client_t *client) {
  size_t i = 0;
  size_t size = 0;

  /* check monitors */
  size = MAX_MONITOR_COUNT;
  for (i = 0; i < size; i++) {
    if (!record->monitors[i]) {
      record->monitors[i] = client;
      return true;
    }
  }
  return false;
}

/* bool CodecResourceRecord::empty() const */
static bool _resource_record_is_empty(const resource_record_t *record) {
  size_t i = 0;
  size_t size = 0;

  /* check owner */
  if (record->owner != NULL) {
    return false;
  }

  /* check monitors */
  size = MAX_MONITOR_COUNT;
  for (i = 0; i < size; i++) {
    if (record->monitors[i]) {
      return false;
    }
  }
  return true;
}

/* int32_t CodecResourceRecord::priority() */
static int32_t _resource_record_get_priority(const resource_record_t *record) {
  if (record->owner) {
    return _resource_client_get_priority(record->owner);
  } else {
    return S32_MAX;
  }
}

/* void CodecResourceRecord::clear_owner(sp<CodecClientInfo>* output) */
static void _resource_record_clear_owner(resource_record_t *record,
                                         const resource_client_t *client) {
  if (record != NULL && record->owner &&
      _resource_client_is_equal(record->owner, client)) {
    pr_debug("[crmmgr] release  : %s owner was remove from %s (%s %d)\n",
            _resource_client_get_name(client),
            _resource_record_get_name(record),
            _resource_provider_get_name(record->provider), record->cost);
    record->owner = NULL;
  }
}

/*bool CodecResourceRecord::remove(const wp<IBinder> &binder,
                                 sp<CodecClientInfo> *output) */
static void _resource_record_clear_monitor(resource_record_t *record,
                                           const resource_client_t *client) {
  size_t i = 0;
  size_t size = MAX_MONITOR_COUNT;
  for (i = 0; i < size; i++) {
    resource_client_t *monitor = record->monitors[i];
    if (monitor && _resource_client_is_equal(monitor, client)) {
      pr_debug("[crmmgr] release  : %s monitor was remove from %s (%s %d)\n",
              _resource_client_get_name(client),
              _resource_record_get_name(record),
              _resource_provider_get_name(record->provider), record->cost);
      record->monitors[i] = NULL;
      break;
    }
  }
}

/* bool CodecResourceRecord::equal(const wp<IBinder>& binder,
                                int32_t uniqueId) const */
static bool _resource_record_contain_owner(const resource_record_t *record,
                                           const resource_client_t *client) {
  if (record->owner != NULL) {
    return _resource_client_is_equal(record->owner, client);
  } else {
    return false;
  }
}

/* bool CodecResourceRecord::equal(nt32_t uniqueId) const */
static bool _resource_record_contain_unique_id(const resource_record_t *record,
                                               int32_t unique_id) {
  if (record->owner != NULL) {
    return _resource_client_is_unique_id(record->owner, unique_id);
  } else {
    return false;
  }
}

/* bool CodecResourceRecord::contain(const sp<CodecClientInfo>& info) const */
static bool _resource_record_contain_monitor(const resource_record_t *record,
                                             const resource_client_t *client) {
  size_t i = 0;
  size_t size = MAX_MONITOR_COUNT;

  for (i = 0; i < size; i++) {
    resource_client_t *monitor = record->monitors[i];
    if (monitor && _resource_client_is_equal(monitor, client)) {
      return true;
    }
  }
  return false;
}

/*int CodecResourceSortedRecordVector::do_compare(const void *lhs,
                                                const void *rhs) const*/
static int _resource_record_reclaim_priority_compare(const void *lhs,
                                                     const void *rhs) {
  resource_record_t *l = *((resource_record_t **)lhs);
  resource_record_t *r = *((resource_record_t **)rhs);

  int32_t lprio = _resource_record_get_priority(l);
  int32_t rprio = _resource_record_get_priority(r);

  pr_debug("[crmmgr] compare: %s %d %d %llu\n", _resource_record_get_name(l),
          lprio, l->cost, l->acquire_time);
  pr_debug("[crmmgr] compare: %s %d %d %llu\n", _resource_record_get_name(r),
          rprio, r->cost, r->acquire_time);

  /* check resource client priority */
  if (lprio < rprio) {
    return 1;
  } else if (lprio > rprio) {
    return -1;
  } else {
    /* check the acquire time */
    if (l->acquire_time < r->acquire_time) {
      return -1;
    } else if (l->acquire_time > r->acquire_time) {
      return 1;
    } else {
      return 0;
    }
  }
}

/* peek the top client, and ref it */
static resource_client_t *_resource_record_peek_monitor(
    resource_record_t *record) {
  size_t i = 0;
  size_t size = MAX_MONITOR_COUNT;
  resource_client_t *client = NULL;
  if (_resource_record_is_used(record)) {
    for (i = 0; i < size; i++) {
      client = record->monitors[i];
      if (client) {
        return _resource_client_ref(client);
      }
    }
  }
  return NULL;
}

/* peek the owner client, and ref it */
static resource_client_t *_resource_record_peek_owner(
    resource_record_t *record) {
  if (_resource_record_is_used(record)) {
    if (record->owner) {
      return _resource_client_ref(record->owner);
    }
  }
  return NULL;
}

/*
 * bool CodecResourceRecord::reclaim(Mutex &lock, bool force)
 *
 * return
 *   -EINTR : when has pending signal
 *   -ERESTARTSYS : restart sys
 *   -ENOMEM : reject reclaim
 */
static int _resource_record_reclaim(resource_record_t *record, bool force) {
  int ret = 0;
  int monitor_reclaim = 0;
  int i, j;
  resource_client_t *client;

  /* reclaim monitor */
  while ((ret == 0) && (client = _resource_record_peek_monitor(record))) {
    pr_err("[crmmgr] reclaim  : %s monitor is reclaiming for %s (%s %d)\n",
            _resource_client_get_name(client),
            _resource_record_get_name(record),
            _resource_provider_get_name(record->provider), record->cost);
    ret |= _resource_client_reclaim(client, force);
    client->is_reclaiming = 0;
    monitor_reclaim = 1; //indicate moniter has already reclaimed
    pr_err("[crmmgr] reclaim  : %s monitor was %s\n",
            _resource_client_get_name(client),
            (ret ? "rejected" : "reclaimed"));
    _resource_client_unref(client);
  }

  /* we need to check the resource which moniter register and check if need to reclaim*/
  if(!monitor_reclaim && (client = _resource_record_peek_owner(record))) {
    for (i = 0; i < _device_table->provider_count; i++) {
      const resource_provider_t *provider = &_device_table->providers[i];
      if (_resource_provider_is_leaf(provider)) {
        size_t record_count = 0;
        const resource_record_t *records[MAX_REFERENCES_COUNT];
        if (_resource_provider_contain_client(provider, client,
                                              RESOURCE_FIND_TARGET_OWNER,
                                              records, &record_count)) {
          for (j = 0; j < record_count; j++) {
            resource_client_t *monitor_client;
            const resource_record_t *monitor_record = records[j];
            pr_err("[crmmgr] reclaim  : check record %s\n", _resource_provider_get_name(monitor_record->provider));
            if(monitor_client = _resource_record_peek_monitor(monitor_record)){
              pr_err("[crmmgr] reclaim  : %s monitor found %s \n",
                _resource_client_get_name(monitor_client),
                _resource_provider_get_name(monitor_record->provider));
              pr_err("[crmmgr] reclaim  : %s monitor is reclaiming for %s (%s %d)\n",
                      _resource_client_get_name(monitor_client),
                      _resource_record_get_name(monitor_record),
                      _resource_provider_get_name(monitor_record->provider), monitor_record->cost);
              ret |= _resource_client_reclaim(monitor_client, force);
              monitor_client->is_reclaiming = 0;
              monitor_reclaim = 1; //indicate moniter has already reclaimed
              pr_err("[crmmgr] reclaim  : %s monitor was %s\n",
                      _resource_client_get_name(monitor_client),
                      (ret ? "rejected" : "reclaimed"));
              _resource_client_unref(monitor_client);
              break;
            }
          }
        }
      }
      if(monitor_reclaim == 1)
        break;
    }
  }

  /* reclaim owner */
  if ((ret == 0) && (client = _resource_record_peek_owner(record))) {
    pr_err("[crmmgr] reclaim  : %s owner is reclaiming for %s (%s %d)\n",
            _resource_client_get_name(client),
            _resource_record_get_name(record),
            _resource_provider_get_name(record->provider), record->cost);
    ret |= _resource_client_reclaim(client, force);
    client->is_reclaiming = 0;
    pr_err("[crmmgr] reclaim  : %s owner was %s\n",
            _resource_client_get_name(client),
            (ret ? "rejected" : "reclaimed"));
    _resource_client_unref(client);
  }

  return ret;
}

static int _resource_record_update_priority(resource_record_t *record) {
  int ret = 0;
  resource_client_t *client;

  /* update reclaim priority for owner */
  if ((client = _resource_record_peek_owner(record))) {
    pr_debug("[crmmgr] priority : %s owner is updating priority\n",
            _resource_client_get_name(client));
    ret |= _resource_client_update_priority(client);
    pr_debug("[crmmgr] priority : %s owner has priority %d\n",
            _resource_client_get_name(client),
            _resource_client_get_priority(client));
    _resource_client_unref(client);
  }

  return ret;
}

///////////////////////////////////////////////////////////////////////////////
// resource provider
///////////////////////////////////////////////////////////////////////////////

static inline const char *_resource_provider_get_name(
    const resource_provider_t *provider) {
  return provider->name;
}

static bool _resource_provider_is_name(const resource_provider_t *provider,
                                       const char *name) {
  return strncmp(provider->name, name, sizeof(provider->name)) ? false : true;
}

/* bool CodecResourceProvider::isLeaf () const */
static inline bool _resource_provider_is_leaf(
    const resource_provider_t *provider) {
  return provider->reference_count == 0 ? true : false;
}

/* bool CodecResourceProvider::isGroup () const */
static inline bool _resource_provider_is_group(
    const resource_provider_t *provider) {
  return provider->reference_count > 0 ? true : false;
}

/* int32_t CodecResourceProvider::getCost() const */
static int32_t _resource_provider_get_cost(
    const resource_provider_t *provider) {
  int32_t value = 0;
  size_t i = 0;
  size_t size = 0;
  const resource_record_t *record = NULL;

  /* group provider */
  for (i = 0; i < provider->reference_count; i++) {
    value += _resource_provider_get_cost(provider->references[i]);
  }

  /* leaf provider */
  size = MAX_RECORDS_COUNT;
  for (i = 0; i < size; i++) {
    record = &provider->records[i];
    if (_resource_record_is_used(record)) {
      value += record->cost;
    }
  }

  return value;
}

/* int32_t CodecResourceProvider::getCapacity () const */
static int32_t _resource_provider_get_capacity(
    const resource_provider_t *provider) {
  size_t i = 0;
  int32_t value = 0;

  /* group provider */

  for (i = 0; i < provider->reference_count; i++) {
    value += _resource_provider_get_capacity(provider->references[i]);
  }

  /* leaf provider */

  value += provider->capacity;

  return value;
}

/* int32_t CodecResourceProvider::available (int32_t cost) */
static int32_t _resource_provider_available(const resource_provider_t *provider,
                                            int32_t cost) {
  return (_resource_provider_get_capacity(provider) -
          (_resource_provider_get_cost(provider) + cost));
}

/* bool CodecResourceProvider::setAcquirePriority (int32_t priority) */
static bool _resource_provider_set_acquire_priority(
    resource_provider_t *provider, int32_t priority) {
  if (_resource_provider_is_group(provider)) {
    BUG();
    return false;
  }

  provider->acquire_priority = priority;

  if (priority) {
    pr_warn("[crmmgr] acquire  : set acquire priority %d in %s\n", priority,
            _resource_provider_get_name(provider));
  }

  return true;
}

/* int32_t CodecResourceProvider::getAcquirePriority () const */
static int32_t _resource_provider_get_acquire_priority(
    resource_provider_t *provider) {
  if (_resource_provider_is_group(provider)) {
    BUG();
    return 0;
  }

  return provider->acquire_priority;
}

/* int32_t CodecResourceProvider::getAcquirePriority () const */
static int32_t _resource_provider_get_record_count(
    resource_provider_t *provider) {
  size_t i = 0;
  size_t size = 0;
  int32_t count = 0;
  /* group provider */
  if (_resource_provider_is_group(provider)) {
    BUG();
    return 0;
  }
  size = MAX_RECORDS_COUNT;
  for (i = 0; i < size; i++) {
    if (_resource_record_is_used(&provider->records[i])) {
      count++;
    }
  }
  return count;
}

/*bool CodecResourceProvider::contain(const sp<CodecClientInfo> &info,
                                    CodecResourceFindTarget target,
                                    sp<CodecResourceRecord> &record) */
static bool _resource_provider_contain_client(
    const resource_provider_t *provider, const resource_client_t *client,
    resource_find_target_t target, const resource_record_t **target_record,
    size_t *target_count) {
  size_t i = 0;
  size_t size = 0;
  const resource_record_t *record = NULL;
  bool found = false;

  if (provider->reference_count > 0) {
    BUG();
  } else {
    /* leaf provider */
    size = MAX_RECORDS_COUNT;
    for (i = 0; i < size; i++) {
      record = &provider->records[i];
      if (_resource_record_is_used(record)) {
        if (target == RESOURCE_FIND_TARGET_OWNER) {
          if (_resource_record_contain_owner(record, client)) {
            if (target_record && target_count) {
              target_record[(*target_count)++] = record;
            }
            found = true;
          }
        } else if (target == RESOURCE_FIND_TARGET_MONITOR) {
          if (_resource_record_contain_monitor(record, client)) {
            if (target_record && target_count) {
              target_record[(*target_count)++] = record;
            }
            found = true;
          }
        }
      }
    }
  }

  return found;
}

/* bool CodecResourceTable::contain (int32_t uniqueId) */
static bool _resource_provider_contain_unique_id(
    resource_provider_t *provider, int32_t unique_id,
    resource_record_t **target_record, size_t *target_count) {
  size_t i = 0;
  size_t size = 0;
  resource_record_t *record = NULL;
  bool found = false;

  if (provider->reference_count > 0) {
    BUG();
  } else {
    /* leaf provider */
    size = MAX_RECORDS_COUNT;
    for (i = 0; i < size; i++) {
      record = &provider->records[i];
      if (_resource_record_is_used(record)) {
        if (_resource_record_contain_unique_id(record, unique_id)) {
          if (target_record && target_count) {
            target_record[(*target_count)++] = record;
          }
          found = true;
        }
      }
    }
  }

  return found;
}

/* int64_t CodecResourceProvider::getMinimalAcquireTime() */
static uint64_t _resource_provider_get_acquire_time(
    resource_provider_t *provider) {
  /* the minimal acquire time */
  int64_t time = 0;
  uint64_t value = U64_MAX;
  size_t size = 0;
  size_t i = 0;
  resource_record_t *record = NULL;

  /* group provider */
  size = provider->reference_count;
  for (i = 0; i < size; i++) {
    time = _resource_provider_get_acquire_time(provider->references[i]);
    if (time < value) {
      value = time;
    }
  }

  /* leaf provider */
  size = MAX_RECORDS_COUNT;
  for (i = 0; i < size; i++) {
    record = &provider->records[i];
    if (_resource_record_is_used(record)) {
      time = _resource_record_get_acquire_time(record);
      if (time < value) {
        value = time;
      }
    }
  }

  return value;
}

/* int32_t CodecResourceProvider::getMaximalPriority () */
static int32_t _resource_provider_get_maximal_reclaim_priority(
    resource_provider_t *provider) {
  int32_t priority = 0;
  int64_t value = 0;
  size_t size = 0;
  size_t i = 0;
  resource_record_t *record = NULL;

  /* group provider */
  size = provider->reference_count;
  for (i = 0; i < size; i++) {
    priority = _resource_provider_get_maximal_reclaim_priority(
        provider->references[i]);
    if (priority > value) {
      value = priority;
    }
  }

  /* leaf provider */
  size = MAX_RECORDS_COUNT;
  for (i = 0; i < size; i++) {
    record = &provider->records[i];
    if (_resource_record_is_used(record)) {
      priority = _resource_record_get_priority(record);
      if (priority > value) {
        value = priority;
      }
    }
  }

  return value;
}

/* int CodecResourceAcquireSortedVector::do_compare (const void * lhs, const
 * void * rhs) const */
static int _resource_provider_acquire_priority_compare(const void *lhs,
                                                       const void *rhs) {
  resource_provider_t *l = *((resource_provider_t **)lhs);
  resource_provider_t *r = *((resource_provider_t **)rhs);

  int32_t lacqu = _resource_provider_get_acquire_priority(l);
  int32_t racqu = _resource_provider_get_acquire_priority(r);

  int32_t lsize = _resource_provider_get_record_count(l);
  int32_t rsize = _resource_provider_get_record_count(r);

  pr_debug("[crmmgr] compare  : (%s) aprio: %d records: %d\n",
          _resource_provider_get_name(l), lacqu, lsize);
  pr_debug("[crmmgr] compare  : (%s) aprio: %d records: %d\n",
          _resource_provider_get_name(r), racqu, rsize);

  if (_resource_provider_is_group(l)) {
    pr_debug("[crmmgr] the l-provider is group: %s\n",
            _resource_provider_get_name(l));
  }

  if (_resource_provider_is_group(r)) {
    pr_debug("[crmmgr] the r-provider is group: %s\n",
            _resource_provider_get_name(r));
  }

  /* 1. check record first, prefer no record provider */
  /* 2. check acquire priority */
  if (lsize == 0 && rsize != 0) {
    return -1;
  } else if (lsize != 0 && rsize == 0) {
    return 1;
  } else if (lacqu < racqu) {
    return 1;
  } else if (lacqu > racqu) {
    return -1;
  } else {
    return -1;
  }
}

/* int CodecResourceSortedProviderVector::do_compare(const void *lhs,
                                                  const void *rhs) const */
static int _resource_provider_reclaim_priority_compare(const void *lhs,
                                                       const void *rhs) {
  resource_provider_t *l = *((resource_provider_t **)lhs);
  resource_provider_t *r = *((resource_provider_t **)rhs);

  int32_t lavail = _resource_provider_available(l, 0);
  int32_t ravail = _resource_provider_available(r, 0);
  int32_t lprio = _resource_provider_get_maximal_reclaim_priority(l);
  int32_t rprio = _resource_provider_get_maximal_reclaim_priority(r);
  uint64_t ltime = _resource_provider_get_acquire_time(l);
  uint64_t rtime = _resource_provider_get_acquire_time(r);

  pr_debug("[crmmgr] compare  : %s avail: %d prio: %d acqtime: %llu\n",
          _resource_provider_get_name(l), lavail, lprio, ltime);
  pr_debug("[crmmgr] compare  : %s avail: %d prio: %d acqtime: %llu\n",
          _resource_provider_get_name(r), ravail, rprio, rtime);

  /* 1. check available */
  if (lavail < ravail) {
    return 1;
  } else if (lavail > ravail) {
    return -1;
  } else {
    /* 2. check processinfo priority */
    if (lprio < rprio) {
      return 1;
    } else if (lprio > rprio) {
      return -1;
    } else {
      /* 3. check acquire time */
      if (ltime < rtime) {
        return -1;
      } else if (ltime > rtime) {
        return 1;
      } else {
        return 0;
      }
    }
  }

  return 0;
}

static uint64_t _resource_get_monotonic_time(void) {
  struct timespec ts;
  getrawmonotonic(&ts);
  return (1000000ULL * ts.tv_sec) + (ts.tv_nsec / 1000);
}

/* CodecResourceRecord (const sp<CodecResourceProvider> & provider, const
 * sp<CodecClientInfo> & info, int32_t cost); */
static bool _resource_provider_add_record(resource_provider_t *provider,
                                          resource_client_t *client,
                                          int32_t cost) {
  size_t i = 0;
  size_t size = 0;
  resource_record_t *record = NULL;
  static uint32_t _record_seqnum = 0;

  /* find a unused record slot */
  size = MAX_RECORDS_COUNT;
  for (i = 0; i < size; i++) {
    if (!_resource_record_is_used(&provider->records[i])) {
      record = &provider->records[i];
      break;
    }
  }

  if (!record) {
    pr_err("[crmmgr] record is full in %s provider",
           _resource_provider_get_name(provider));
    return false;
  }

  /* fill record with new information */
  record->seqnum = ++_record_seqnum;
  record->cost = cost;
  record->used = true;
  record->acquire_time = _resource_get_monotonic_time();
  record->provider = provider;
  record->owner = client;

  size = MAX_MONITOR_COUNT;
  for (i = 0; i < size; i++) {
    record->monitors[i] = NULL;
  }

  pr_debug("[crmmgr] acquire  : %s owner was insert into %s (%s %d)\n",
          _resource_client_get_name(client), _resource_record_get_name(record),
          _resource_provider_get_name(provider), cost);

  return true;
}

/* bool CodecResourceProvider::acquire(
    const sp<CodecClientInfo> &client, int32_t cost,
    Vector<sp<CodecResourceProvider>> &providers) */
static bool _resource_provider_acquire(resource_provider_t *provider,
                                       resource_client_t *client, int32_t cost,
                                       resource_provider_t **provider_queue,
                                       size_t *provider_queue_count) {
  size_t i = 0;
  int32_t capacity = 0;
  int32_t consume = 0;

  pr_debug("[crmmgr] acquire  : %s acquire (%s %d)\n",
          _resource_client_get_name(client),
          _resource_provider_get_name(provider), cost);

  if (_resource_provider_available(provider, cost) < 0) {
    return false;
  }

  if (provider->reference_count > 0) {
    /* sort providers by acquire priority */
    resource_provider_t *references[MAX_REFERENCES_COUNT];
    for (i = 0; i < provider->reference_count; i++) {
      references[i] = provider->references[i];
    }
    sort(references, provider->reference_count, sizeof(resource_provider_t *),
         &_resource_provider_acquire_priority_compare, NULL);

    /* group provider */
    for (i = 0; i < provider->reference_count && cost > 0; i++) {
      capacity = _resource_provider_get_capacity(references[i]) -
                 _resource_provider_get_cost(references[i]);
      if (capacity <= 0) {
        continue;
      }
      consume = ((cost < capacity) ? cost : capacity);
      if (_resource_provider_acquire(references[i], client, consume,
                                     provider_queue, provider_queue_count)) {
        cost -= consume;
      }
    }
    if (cost > 0) {
      pr_err("[crmmgr] resource table is confused at %s\n", __func__);
      return false;
    }
  } else {
    /* leaf provider */
    capacity = provider->capacity;
    consume = ((cost < capacity) ? cost : capacity);
    if (!_resource_provider_add_record(provider, client, consume)) {
      pr_err("[crmmgr] record is full in %s provider\n",
             _resource_provider_get_name(provider));
      return false;
    }
    cost -= consume;
    /* add to return provider queue */
    provider_queue[(*provider_queue_count)++] = provider;
  }

  return true;
}

/*
 * update the reclaim priority
 *
 * return
 *   -EINTR : when has pending signal
 *   -ERESTARTSYS : restart system
 *
 */
static int _resource_provider_update_reclaim_priority(
    resource_provider_t *provider) {
  int ret = 0;
  size_t i = 0;

  if (provider->reference_count > 0) {
    /* group provider */
    resource_provider_t *references[MAX_REFERENCES_COUNT];
    for (i = 0; i < provider->reference_count; i++) {
      references[i] = provider->references[i];
    }

    /* update priority for each reference provider */
    for (i = 0; i < provider->reference_count; i++) {
      ret = _resource_provider_update_reclaim_priority(references[i]);
      if (ret == 0) {
      } else if (ret == -ERESTARTSYS || ret == -EINTR) {
        return ret;
      } else {
        BUG();
      }
    }

  } else {
    /* leaf provider */
    resource_record_t *records[MAX_RECORDS_COUNT];
    size_t record_count = 0;
    for (i = 0; i < MAX_RECORDS_COUNT; i++) {
      if (_resource_record_is_used(&provider->records[i])) {
        records[record_count++] = &provider->records[i];
      }
    }

    /* update priority for each record */
    pr_debug("[crmmgr] reclaim  : updating reclaim priority (%s)\n",
            _resource_provider_get_name(provider));
    for (i = 0; i < record_count; i++) {
      ret = _resource_record_update_priority(records[i]);
      if (ret == 0) {
      } else if (ret == -ERESTARTSYS || ret == -EINTR) {
        return ret;
      } else {
        BUG();
      }
    }
    pr_debug("[crmmgr] reclaim  : updated reclaim priority (%s)\n",
            _resource_provider_get_name(provider));
  }

  return 0;
}

/*
 * bool CodecResourceProvider::reclaim(Mutex &lock, int32_t cost)
 *
 * return
 *   -EINTR : when has pending signal
 *   -ERESTARTSYS : restart system
 *   -ENOMEM : when reject
 *
 */
static int _resource_provider_reclaim(resource_provider_t *provider,
                                      int32_t cost,
                                      bool update_reclaim_priority) {
  int ret = 0;
  size_t i = 0;
  int32_t capacity = 0;
  int32_t consume = 0;

  if (_resource_provider_available(provider, cost) >= 0) {
    pr_err("[crmmgr] reclaim  : %s is available\n",
            _resource_provider_get_name(provider));
    return 0;
  }

  pr_err("[crmmgr] reclaim  : reclaiming (%s %d)\n",
          _resource_provider_get_name(provider), cost);

  if (update_reclaim_priority) {
    _resource_provider_update_reclaim_priority(provider);
    /* it need to check again after unlock table in update_reclaim_priority */
    if (_resource_provider_available(provider, cost) >= 0) {
      pr_debug("[crmmgr] reclaim  : %s is available after update priority\n",
              _resource_provider_get_name(provider));
      return 0;
    }
  }

  if (provider->reference_count > 0) {
    /* group provider, sort references by reclaim priority */
    resource_provider_t *references[MAX_REFERENCES_COUNT];
    for (i = 0; i < provider->reference_count; i++) {
      references[i] = provider->references[i];
    }
    sort(references, provider->reference_count, sizeof(resource_provider_t *),
         &_resource_provider_reclaim_priority_compare, NULL);

    /* reclaim for each reference */
    for (i = 0; i < provider->reference_count && cost > 0; i++) {
      capacity = _resource_provider_get_capacity(references[i]);
      consume = ((cost < capacity) ? cost : capacity);
      ret = _resource_provider_reclaim(references[i], consume, false);
      if (ret == 0) {
        cost -= consume;
      } else if (ret == -ERESTARTSYS || ret == -EINTR) {
        return ret;
      } else if (ret == -ENOMEM) {
      } else {
        BUG();
      }
    }
    if (cost > 0) {
      return -ENOMEM;
    }
  } else {
    /* leaf provider, sort records by reclaim priority */
    resource_record_t *records[MAX_RECORDS_COUNT];
    size_t record_count = 0;
    for (i = 0; i < MAX_RECORDS_COUNT; i++) {
      if (_resource_record_is_used(&provider->records[i])) {
        records[record_count++] = &provider->records[i];
      }
    }
    sort(records, record_count, sizeof(resource_record_t *),
         &_resource_record_reclaim_priority_compare, NULL);
    capacity = provider->capacity;
    consume = ((cost < capacity) ? cost : capacity);

    /* reclaim for each record */
    for (i = 0; i < record_count && cost > 0; i++) {
      ret = _resource_record_reclaim(records[i], false);
      if (ret == 0) {
        cost -= consume;
      } else if (ret == -ERESTARTSYS || ret == -EINTR) {
        return ret;
      } else if (ret == -ENOMEM) {
      } else {
        BUG();
      }
    }
    if (cost > 0) {
      return -ENOMEM;
    }
  }

  return 0;
}

/* bool CodecResourceProvider::release (const wp<IBinder> & binder, int32_t
 * uniqueId) */
static bool _resource_provider_release(resource_provider_t *provider,
                                       resource_client_t *client) {
  size_t i = 0;
  size_t size = 0;

  /* group provider */
  if (_resource_provider_is_group(provider)) {
    pr_err("[crmmgr] release.error call release on group provider");
    return false;
  }

  /* leaf provider */

  size = MAX_RECORDS_COUNT;

  for (i = 0; i < size; i++) {
    resource_record_t *record = &provider->records[i];
    if (_resource_record_is_used(record)) {
      bool found = false;
      if (_resource_record_contain_owner(record, client)) {
        _resource_record_clear_owner(record, client);
        found = true;
      } else if (_resource_record_contain_monitor(record, client)) {
        _resource_record_clear_monitor(record, client);
        found = true;
      }
      if (found) {
        if (_resource_record_is_empty(record)) {
          _resource_record_clear(record);
        }
        return true;
      }
    }
  }

  return false;
}

///////////////////////////////////////////////////////////////////////////////
// resource require
///////////////////////////////////////////////////////////////////////////////

/* bool CodecResourceRequire::available () */
static bool _resource_require_is_available(const resource_require_t *require) {
  if (_resource_provider_available(require->provider, require->cost) >= 0) {
    return true;
  } else {
    return false;
  }
}

/*
 * bool CodecResourceRequire::reclaim (Mutex & lock)
 *
 * return
 *   -EINTR : when has pending signal
 *   -ERESTARTSYS : restart sys
 *   -ENOMEM : when reject
 *
 */
static int _resource_require_reclaim(resource_require_t *require) {
  return _resource_provider_reclaim(require->provider, require->cost, true);
}

/*
bool CodecResourceRequire::acquire(
    const sp<CodecClientInfo> &client,
    Vector<sp<CodecResourceProvider>> &providers) */
static bool _resource_require_acquire(resource_require_t *require,
                                      resource_client_t *client,
                                      resource_provider_t **provider_queue,
                                      size_t *provider_queue_count) {
  return _resource_provider_acquire(require->provider, client, require->cost,
                                    provider_queue, provider_queue_count);
}

///////////////////////////////////////////////////////////////////////////////
// resource format
///////////////////////////////////////////////////////////////////////////////

static inline bool _resource_format_is_video(const resource_format_t *format) {
  return ((format->codec & RTK_CRMDEV_CODEC_TYPE_VIDEO) ? true : false);
}

static inline bool _resource_format_is_audio(const resource_format_t *format) {
  return ((format->codec & RTK_CRMDEV_CODEC_TYPE_AUDIO) ? true : false);
}

static inline const char *_resource_format_get_name(
    const resource_format_t *format) {
  return format->name;
}

/* String8 CodecResourceFormat::toString() const */
static const char *_resource_format_to_string(const resource_format_t *format) {
  if (_resource_format_is_video(format)) {
    snprintf(_device_table->buffer, sizeof(_device_table->buffer),
             "%s (%04x) %s %04dx%04dx%05d", _codec_type_to_name(format->codec),
             format->codec, format->encoder ? "encoder" : "decoder",
             format->width, format->height, format->fps);
  } else if (_resource_format_is_audio(format)) {
    snprintf(_device_table->buffer, sizeof(_device_table->buffer),
             "%s (%04x) %s", _codec_type_to_name(format->codec), format->codec,
             format->encoder ? "encoder" : "decoder");
  } else {
    snprintf(_device_table->buffer, sizeof(_device_table->buffer), "unknown");
  }
  return _device_table->buffer;

#if 0
  size_t size = 0;
  size_t i = 0;
  size = mRequires.size();
  for (i = 0; i < size; i++) {
    result.appendFormat("(%s) ", mRequires.valueAt(i)->toString().string());
  }
#endif
}

/* bool CodecResourceFormat::available () const */
static bool _resource_format_is_available(const resource_format_t *format) {
  size_t i = 0;
  for (i = 0; i < format->require_count; i++) {
    if (!_resource_require_is_available(&format->requires[i])) {
      return false;
    }
  }
  return true;
}

/* bool CodecResourceFormat::match (const sp<CodecInfo> & info) const */
static bool _resource_format_match(const resource_format_t *format,
                                   const rtk_crmdev_codec_info_t *info) {
  uint64_t f_score;
  uint64_t i_score;

  if (format->codec != info->codec) {
    return false;
  }

  if (format->encoder != info->encoder) {
    return false;
  }

  if (format->width == 0 && format->height == 0) {
    return true;
  }

  f_score = (uint64_t)format->width * format->height;
  i_score = (uint64_t)info->max_width * info->max_height;

  if (f_score >= i_score) {
    f_score *= (format->fps / 1000);
    i_score *= (info->fps / 1000);
    if (f_score >= i_score) {
      return true;
    }
  }

  return false;
}

/*bool CodecResourceFormat::acquire (
        const sp<CodecClientInfo> & client,
        const sp<CodecInfo> & info, sp<CodecResource> & resource)*/
static bool _resource_format_acquire(resource_format_t *format,
                                     resource_client_t *client,
                                     const rtk_crmdev_codec_info_t *info,
                                     rtk_crmdev_codec_resource_t *resource) {
  size_t i = 0;
  size_t provider_count = 0;
  resource_provider_t *providers[MAX_PROVIDER_COUNT];

  pr_err("[crmmgr] acquire  : %s acquire format %s\n",
          _resource_client_get_name(client),
          _resource_format_to_string(format));

  /* check all of requires */
  if (!_resource_format_is_available(format)) {
    pr_err("[crmmgr] acquire  : no resource available, need reclaim for %s\n", _resource_format_to_string(format));
    return false;
  }

  /* acqurie resource for each require */
  for (i = 0; i < format->require_count; i++) {
    if (!_resource_require_acquire(&format->requires[i], client, providers,
                                   &provider_count)) {
      pr_err("[crmmgr] resource table is confused at %s\n", __func__);
      return false;
    }
  }

  /* fill resource mask */
  _codec_resource_set_from_providers(
      resource, (const resource_provider_t **)providers, provider_count);

  if (_codec_info_is_video(info)) {
    if (info->adaptive) {
      resource->max_width = format->width;
      resource->max_height = format->height;
    } else {
      resource->max_width = info->max_width;
      resource->max_height = info->max_height;
    }
  }
  resource->encoder = format->encoder;

  return true;
}

/*
 * bool CodecResourceFormat::reclaim(Mutex &lock)
 *
 * return
 *   -EINTR : when has pending signal
 *   -ERESTARTSYS : restart sys
 *   -ENOMEM : when reject
 *
 */
static int _resource_format_reclaim(resource_format_t *format) {
  int ret = 0;
  size_t i = 0;
  for (i = 0; i < format->require_count; i++) {
    resource_require_t *require = &format->requires[i];
    if (_resource_require_is_available(require)) {
      pr_debug("[crmmgr] reclaim  : (%s %d) is available\n",
              _resource_provider_get_name(require->provider), require->cost);
    } else {
      ret = _resource_require_reclaim(require);
      if (ret) {
        break;
      }
    }
  }
  return ret;
}

///////////////////////////////////////////////////////////////////////////////
// resource table
///////////////////////////////////////////////////////////////////////////////

static bool _resource_table_match(resource_table_t *table,
                                  const rtk_crmdev_codec_info_t *info,
                                  const char *in_capability,
                                  resource_format_t **out_match_formats,
                                  uint32_t *out_match_count) {
  ssize_t i = 0;
  uint32_t format_count = table->format_count;
  uint32_t capability_count = table->capability_count;
  uint32_t match_count = 0;
  resource_format_t *format = NULL;
  resource_capability_t *capability = NULL;

  if(in_capability) {
    if(capability_count <= 0) {
      pr_err("[crmmgr] capability     : capability_count %d is not vaild\n", capability_count);
    } else {
      for (i = capability_count - 1; i >= 0; i--) {
        capability = &table->capability[i];
        if (strcmp(in_capability, capability->name) == 0) {
          match_count++;
          break;
        }
      }
    }
  } else {
    if (info->adaptive) {
      for (i = format_count - 1; i >= 0; i--) {
        format = &table->formats[i];
        if (_resource_format_match(format, info)) {
          if (out_match_formats) {
            out_match_formats[match_count] = format;
          }
          match_count++;
          break;
        }
      }
    } else {
      for (i = 0; i < format_count; i++) {
        format = &table->formats[i];
        if (_resource_format_match(format, info)) {
          if (out_match_formats) {
            out_match_formats[match_count] = format;
          }
          match_count++;
        }
      }
    }
  }

  if (out_match_count) {
    (*out_match_count) = match_count;
  }

  return match_count ? true : false;
}

static void _resource_table_reset_acquire_priority(resource_table_t *table) {
  size_t i = 0;
  for (i = 0; i < table->provider_count; i++) {
    resource_provider_t *provider = &table->providers[i];
    if (_resource_provider_is_leaf(provider)) {
      _resource_provider_set_acquire_priority(provider, 0);
    }
  }
}

/* bool CodecResourceTable::contain(const sp<CodecClientInfo> &client,
                                 CodecResourceFindTarget target) */
static bool _resource_table_contain_client(const resource_table_t *table,
                                           const resource_client_t *client,
                                           resource_find_target_t target) {
  size_t i = 0;

  for (i = 0; i < table->provider_count; i++) {
    const resource_provider_t *provider = &table->providers[i];
    if (_resource_provider_is_leaf(provider)) {
      if (_resource_provider_contain_client(provider, client, target, NULL,
                                            NULL)) {
        return true;
      }
    }
  }
  return false;
}

/* bool CodecResourceTable::contain (int32_t uniqueId) */
static bool _resource_table_contain_unique_id(resource_table_t *table,
                                              int32_t unique_id,
                                              resource_client_t **client) {
  size_t i = 0;

  for (i = 0; i < table->provider_count; i++) {
    resource_provider_t *provider = &table->providers[i];
    if (_resource_provider_is_leaf(provider)) {
      resource_record_t *records[MAX_RECORDS_COUNT];
      size_t record_count = 0;
      if (_resource_provider_contain_unique_id(provider, unique_id, records,
                                               &record_count)) {
        if (record_count > 0 && client) {
          (*client) = records[0]->owner;
        }
        return true;
      }
    }
  }
  return false;
}

static void _resource_table_dump(resource_table_t *table, struct seq_file *m) {
  size_t i = 0, j = 0;
  int32_t cost = 0;
  int32_t capacity = 0;
  int32_t available = 0;
  const char *name = NULL;
  resource_client_t *client = NULL;

  /* dump capability */
  seq_printf(m, "\ncapability:\n\n");
  for (i = 0; i < table->capability_count; i++) {
    resource_capability_t *capability = &table->capability[i];
    seq_printf(m, "%-16s\n", capability->name);
  }

  /* dump providers */
  seq_printf(m, "\nleaf providers:\n\n");
  for (i = 0; i < table->provider_count; i++) {
    resource_provider_t *provider = &table->providers[i];
    if (_resource_provider_is_leaf(provider)) {
      name = _resource_provider_get_name(provider);
      cost = _resource_provider_get_cost(provider);
      capacity = _resource_provider_get_capacity(provider);
      available = capacity - cost;
      seq_printf(m, "%-16s (%03d %03d %03d)\n", name, capacity, cost,
                 available);
    }
  }

  seq_printf(m, "\ngroup providers:\n\n");
  for (i = 0; i < table->provider_count; i++) {
    resource_provider_t *provider = &table->providers[i];
    if (_resource_provider_is_group(provider)) {
      name = _resource_provider_get_name(provider);
      cost = _resource_provider_get_cost(provider);
      capacity = _resource_provider_get_capacity(provider);
      available = capacity - cost;
      seq_printf(m, "%-16s (%03d %03d %03d) ", name, capacity, cost, available);
      for (j = 0; j < provider->reference_count; j++) {
        resource_provider_t *reference = provider->references[j];
        if (_resource_provider_is_leaf(reference)) {
          name = _resource_provider_get_name(reference);
          cost = _resource_provider_get_cost(reference);
          capacity = _resource_provider_get_capacity(reference);
          available = capacity - cost;
          seq_printf(m, "(%s %03d %03d %03d) ", name, capacity, cost,
                     available);
        }
      }
      seq_printf(m, "\n");
    }
  }

  /* dump formats */

  seq_printf(m, "\nformats:\n\n");
  for (i = 0; i < table->format_count; i++) {
    const resource_format_t *format = &table->formats[i];
    if (_resource_format_is_video(format)) {
      seq_printf(m, "%-16s (%04x) %s %05d %05d %07d ",
                 _codec_type_to_name(format->codec), format->codec,
                 format->encoder ? "encoder" : "decoder", format->width,
                 format->height, format->fps);
    } else if (_resource_format_is_audio(format)) {
      seq_printf(m, "%-16s (%04x) %s                     ",
                 _codec_type_to_name(format->codec), format->codec,
                 format->encoder ? "encoder" : "decoder");
    } else {
      seq_printf(m, "unknown ");
    }

    for (j = 0; j < format->require_count; j++) {
      const resource_require_t *require = &format->requires[j];
      seq_printf(m, "(%s %03d) ",
                 _resource_provider_get_name(require->provider), require->cost);
    }

    seq_printf(m, "\n");
  }

  /* dump clients */
  seq_printf(m, "\nclients:\n\n");
  list_for_each_entry(client, &_client_list, list) {
    seq_printf(m, "%08x (%s): ", client->unique_id,
               _resource_client_get_name(client));
    for (i = 0; i < table->provider_count; i++) {
      const resource_provider_t *provider = &table->providers[i];
      if (_resource_provider_is_leaf(provider)) {
        size_t record_count = 0;
        const resource_record_t *records[MAX_REFERENCES_COUNT];
        if (_resource_provider_contain_client(provider, client,
                                              RESOURCE_FIND_TARGET_OWNER,
                                              records, &record_count)) {
          for (j = 0; j < record_count; j++) {
            const resource_record_t *record = records[j];
            name = _resource_provider_get_name(record->provider);
            seq_printf(m, "(%s %03d %llu) ", name, record->cost,
                       record->acquire_time);
          }
        }
      }
    }
    seq_printf(m, "\n\n");
  }
}

static resource_provider_t *_resource_table_find_provider_by_name(
    const char *name) {
  size_t i;
  resource_provider_t *provider = NULL;
  if (name) {
    for (i = 0; i < _device_table->provider_count; i++) {
      provider = &_device_table->providers[i];
      if (_resource_provider_is_name(provider, name)) {
        break;
      }
    }
  }
  return provider;
}

static void _resource_table_add_provider(rtk_crmdev_request *req) {
  rtk_crmdev_provider_t *item = &req->data.add_provider;
  resource_provider_t *provider = NULL;
  if (_device_table->provider_count < MAX_PROVIDER_COUNT) {
    provider = &_device_table->providers[_device_table->provider_count];
    memset(provider, 0, sizeof(*provider));

    strlcpy(provider->name, item->name, sizeof(provider->name));
    provider->capacity = item->capacity;
    provider->acquire_priority = INT_MAX;
    _device_table->provider_count++;
    pr_debug("[crmmgr] init     : add %s\n",
            _resource_provider_get_name(provider));
    req->status = RTK_CRMDEV_STATUS_OK;
  } else {
    pr_err("[crmmgr] init     : provider count is exceeded %u\n",
           MAX_PROVIDER_COUNT);
    req->status = RTK_CRMDEV_STATUS_INVALID_XML;
  }
}

static void _resource_table_add_reference(rtk_crmdev_request *req) {
  rtk_crmdev_reference_t *item = &req->data.add_reference;
  resource_provider_t *provider = NULL;
  resource_provider_t *reference = NULL;
  if (_device_table->provider_count > 0) {
    provider = &_device_table->providers[_device_table->provider_count - 1];
    if (provider->reference_count < MAX_REFERENCES_COUNT) {
      reference = _resource_table_find_provider_by_name(item->name);
      if (reference) {
        pr_debug("[crmmgr] init     : add %s %s\n",
                _resource_provider_get_name(provider),
                _resource_provider_get_name(reference));
        provider->references[provider->reference_count] = reference;
        provider->reference_count++;
        req->status = RTK_CRMDEV_STATUS_OK;
      } else {
        pr_err("[crmmgr] init     : no provider %s found\n", item->name);
        req->status = RTK_CRMDEV_STATUS_INVALID_XML;
      }
    } else {
      pr_err("[crmmgr] init     : %s reference count is exceeded %u\n",
             _resource_provider_get_name(provider), MAX_REFERENCES_COUNT);
      req->status = RTK_CRMDEV_STATUS_INVALID_XML;
    }
  } else {
    pr_err("[crmmgr] init     : no provider available\n");
    req->status = RTK_CRMDEV_STATUS_INVALID_XML;
  }
}

static void _resource_table_add_format(rtk_crmdev_request *req) {
  resource_format_t *format;
  rtk_crmdev_format_t *item = &req->data.add_format;
  if (_device_table->format_count < MAX_FORMAT_COUNT) {
    format = &_device_table->formats[_device_table->format_count];
    memset(format, 0, sizeof(*format));

    strlcpy(format->name, item->name, sizeof(format->name));
    format->codec = item->codec;
    format->width = item->width;
    format->height = item->height;
    format->fps = item->fps;
    format->encoder = item->encoder;
    format->require_count = 0;
    _device_table->format_count++;
    pr_debug("[crmmgr] init     : add %s\n", _resource_format_to_string(format));
    req->status = RTK_CRMDEV_STATUS_OK;
  } else {
    pr_err("[crmmgr] init     : format count is exceeded %u\n",
           MAX_PROVIDER_COUNT);
    req->status = RTK_CRMDEV_STATUS_INVALID_XML;
  }
}

static void _resource_table_add_require(rtk_crmdev_request *req) {
  rtk_crmdev_require_t *item = &req->data.add_require;
  resource_provider_t *provider = NULL;
  resource_format_t *format = NULL;
  if (_device_table->format_count > 0) {
    format = &_device_table->formats[_device_table->format_count - 1];
    if (format->require_count < MAX_REQUIRES_COUNT) {
      provider = _resource_table_find_provider_by_name(item->name);
      if (provider) {
        pr_debug("[crmmgr] init     : add %s format require (%s %d)\n",
                _resource_format_get_name(format),
                _resource_provider_get_name(provider), item->cost);
        format->requires[format->require_count].provider = provider;
        format->requires[format->require_count].cost = item->cost;
        format->require_count++;
        req->status = RTK_CRMDEV_STATUS_OK;
      } else {
        pr_err("[crmmgr] init     : no provider %s found\n", item->name);
        req->status = RTK_CRMDEV_STATUS_INVALID_XML;
      }
    } else {
      pr_err("[crmmgr] init     : %s require count is exceeded %u\n",
             _resource_format_get_name(format), MAX_REQUIRES_COUNT);
      req->status = RTK_CRMDEV_STATUS_INVALID_XML;
    }
  } else {
    pr_err("[crmmgr] init     : no format available\n");
    req->status = RTK_CRMDEV_STATUS_INVALID_XML;
  }
}

static void _resource_table_add_capability(rtk_crmdev_request *req) {
  resource_capability_t *capability;
  rtk_crmdev_capability_t *item = &req->data.add_capability;
  if (_device_table->capability_count < MAX_CAPABILITY_COUNT) {
    capability = &_device_table->capability[_device_table->capability_count];
    memset(capability, 0, sizeof(*capability));

    strlcpy(capability->name, item->name, sizeof(capability->name));
    _device_table->capability_count++;
    req->status = RTK_CRMDEV_STATUS_OK;
  } else {
    pr_err("[crmmgr] init     : capability count is exceeded %u\n",
           MAX_CAPABILITY_COUNT);
    req->status = RTK_CRMDEV_STATUS_INVALID_XML;
  }
}

///////////////////////////////////////////////////////////////////////////////
// resource service
///////////////////////////////////////////////////////////////////////////////

/* status_t CodecResourceService::isSupported(
        const sp<CodecClientInfo> & client, const sp<CodecInfo> & info) */
static void _resource_service_check_support_lock_table(
    resource_client_t *client, rtk_crmdev_request *req) {
  rtk_crmdev_codec_info_t *info = &req->data.check_support.info;

  /* check if the the codec info was supported */
  if (_resource_table_match(_device_table, info, NULL, NULL, NULL)) {
    req->status = RTK_CRMDEV_STATUS_OK;
  } else {
    req->status = RTK_CRMDEV_STATUS_UNSUPPORT;
  }

  pr_err("[crmmgr] support  : %s check %s is %s",
          _resource_client_get_name(client), _codec_info_to_string(info),
          req->status == RTK_CRMDEV_STATUS_OK ? "support" : "unsupport");
}

/* RHAL_CRM_STATUS RHAL_CRM_ClientCheckCapability(
    RHAL_CRM_CLIENT pHandle, const char* pszCapability) */
static void _resource_service_check_capability_lock_table(
    resource_client_t *client, rtk_crmdev_request *req) {
  char *capability = req->data.check_capability.name;

  /* check if the the capability was supported */
  if (_resource_table_match(_device_table, NULL, capability, NULL, NULL)) {
    req->status = RTK_CRMDEV_STATUS_OK;
  } else {
    req->status = RTK_CRMDEV_STATUS_UNSUPPORT;
  }

  pr_err("[crmmgr] capability  : %s check %s is %s",
          _resource_client_get_name(client), capability,
          req->status == RTK_CRMDEV_STATUS_OK ? "support" : "unsupport");
}

/* status_t CodecResourceService::releaseResource (const
 * sp<ICodecResourceClient> & client) */
static void _resource_service_release_lock_table(resource_client_t *client,
                                                 rtk_crmdev_request *req) {
  size_t i = 0, j = 0;
  int ret = 0;
  int is_monitor = 0;
  int monitor_reclaim = 0;

  /* check if the client is monitor */
  for (i = 0; i < _device_table->provider_count; i++) {
    resource_provider_t *provider = &_device_table->providers[i];
    if (_resource_provider_is_leaf(provider)) {
      if(_resource_client_is_monitor(provider, client)) {
        pr_err("[crmmgr] release  : %s is monitor, release directly\n", _resource_client_get_name(client));
        is_monitor = 1;
        break;
      }
    }
  }

  /* we need to reclaim the resource which moniter register */
  if(!is_monitor) {
    pr_err("[crmmgr] release  : %s check if the resources have registed monitor to reclaim\n", _resource_client_get_name(client));
    for (i = 0; i < _device_table->provider_count; i++) {
      const resource_provider_t *provider = &_device_table->providers[i];
      if (_resource_provider_is_leaf(provider)) {
        size_t record_count = 0;
        const resource_record_t *records[MAX_REFERENCES_COUNT];
        if (_resource_provider_contain_client(provider, client,
                                              RESOURCE_FIND_TARGET_OWNER,
                                              records, &record_count)) {
          for (j = 0; j < record_count; j++) {
            resource_client_t *monitor_client;
            const resource_record_t *monitor_record = records[j];
            pr_err("[crmmgr] reclaim  : check record %s\n", _resource_provider_get_name(monitor_record->provider));
            if(monitor_client = _resource_record_peek_monitor(monitor_record)){
              pr_err("[crmmgr] reclaim  : %s monitor found %s \n",
                _resource_client_get_name(monitor_client),
                _resource_provider_get_name(monitor_record->provider));
              pr_err("[crmmgr] reclaim  : %s monitor is reclaiming for %s (%s %d)\n",
                      _resource_client_get_name(monitor_client),
                      _resource_record_get_name(monitor_record),
                      _resource_provider_get_name(monitor_record->provider), monitor_record->cost);
              ret |= _resource_client_reclaim(monitor_client, false);
              monitor_client->is_reclaiming = 0;
              monitor_reclaim = 1; //indicate moniter has already reclaimed
              pr_err("[crmmgr] reclaim  : %s monitor was %s\n",
                      _resource_client_get_name(monitor_client),
                      (ret ? "rejected" : "reclaimed"));
              _resource_client_unref(monitor_client);
              break;
            }
          }
        }
      }
      if(monitor_reclaim == 1)
        break;
    }
    if(!monitor_reclaim)
      pr_err("[crmmgr] release  : %s no registed monitor found, just release client\n", _resource_client_get_name(client));
  }

  for (i = 0; i < _device_table->provider_count; i++) {
    resource_provider_t *provider = &_device_table->providers[i];
    if (_resource_provider_is_leaf(provider)) {
      _resource_provider_release(provider, client);
    }
  }
  if (req) {
    req->status = RTK_CRMDEV_STATUS_OK;
  }
}

static int _resource_service__acquire_lock_table(resource_client_t *client,
                                                 rtk_crmdev_request *req) {
  rtk_crmdev_codec_info_t *info = &req->data.acquire_resource.info;
  rtk_crmdev_codec_resource_t *resource = &req->data.acquire_resource.resource;
  resource_format_t *match_formats[MAX_FORMAT_COUNT];
  uint32_t match_count = 0;
  size_t i = 0, j = 0;
  int ret = 0;

  /* clear resource first */
  memset(resource, 0, sizeof(*resource));

  /* check if the the codec info was supported */
  if (!_resource_table_match(_device_table, info, NULL, match_formats,
                             &match_count)) {
    pr_err("[crmmgr] acquire  : %s acquire %s is not support",
           _resource_client_get_name(client), _codec_info_to_string(info));
    req->status = RTK_CRMDEV_STATUS_UNSUPPORT;
    return 0;
  } else {
    pr_err("[crmmgr] acquire  : %s acquire %s match_count %d\n",
            _resource_client_get_name(client), _codec_info_to_string(info), match_count);
  }

  for (i = 0; i < match_count; i++) {
    resource_format_t *format = match_formats[i];
    pr_err("[crmmgr] acquire  : %s match format %s, avail %d\n",
            _resource_client_get_name(client),
            _resource_format_to_string(format),
            _resource_format_is_available(format));
  }

  /* reset the acquire priority */
  _resource_table_reset_acquire_priority(_device_table);

  /* find if the client was already acquire resource */
  if (_resource_table_contain_client(_device_table, client,
                                     RESOURCE_FIND_TARGET_OWNER)) {
    resource_provider_t *providers[MAX_PROVIDER_COUNT];
    size_t provider_count = 0;

    pr_err("[crmmgr] acquire  : %s acquire again\n",
            _resource_client_get_name(client));

    for (i = 0; i < _device_table->provider_count; i++) {
      resource_provider_t *provider = &_device_table->providers[i];
      if (_resource_provider_is_leaf(provider)) {
        size_t record_count = 0;
        resource_record_t *records[MAX_RECORDS_COUNT];
        if (_resource_provider_contain_client(
                provider, client, RESOURCE_FIND_TARGET_OWNER,
                (const resource_record_t **)records, &record_count)) {
          providers[provider_count++] = provider;
          for (j = 0; j < record_count; j++) {
            resource_record_t *record = records[j];
            pr_err("[crmmgr] acquire  : %s owner has %s (%s %d)\n",
                    _resource_client_get_name(client),
                    _resource_record_get_name(record),
                    _resource_provider_get_name(provider),
                    _resource_record_get_cost(record));
          }
        }
      }
    }

    /* release resource first */
    _resource_service_release_lock_table(client, NULL);

    /* adjust the acquire priority */
    for (i = 0; i < provider_count; i++) {
      resource_provider_t *provider = providers[i];
      if (_resource_provider_is_leaf(provider)) {
        _resource_provider_set_acquire_priority(provider, 1);
      } else {
        BUG();
      }
    }

  } else {
    pr_err("[crmmgr] acquire  : %s acquire first\n",
            _resource_client_get_name(client));
  }

  for (i = 0; i < match_count; i++) {
    if (_resource_format_acquire(match_formats[i], client, info, resource)) {
      pr_err("[crmmgr] acquire  : %s acquire success %s\n",
              _resource_client_get_name(client),
              _codec_resource_to_string(resource));
      req->status = RTK_CRMDEV_STATUS_OK;
      return 0;
    }
  }

  if(info->try_acquire == 1){
    //no resource available at try_acquire situation
    //so just return RTK_CRMDEV_STATUS_NO_RESOURCE
    req->status = RTK_CRMDEV_STATUS_NO_RESOURCE;
    pr_err("[crmmgr] try_acquire  : %s acquire failure, no resource available\n",
            _resource_client_get_name(client));
    return 0;
  }else {
    //if try_acquire equal to 1, we don't need to reclaim any resource
    //see more detail at function RHAL_CRM_ClientTryAcquireResource
    for (i = 0; i < match_count; i++) {
      resource_format_t *format = match_formats[i];
      ret = _resource_format_reclaim(format);
      if (ret == 0) {
        if (_resource_format_acquire(format, client, info, resource)) {
          pr_err("[crmmgr] acquire  : %s acquire success %s\n",
                  _resource_client_get_name(client),
                  _codec_resource_to_string(resource));
          req->status = RTK_CRMDEV_STATUS_OK;
          break;
        } else {
          pr_err("[crmmgr] resource table is confused at %s\n", __func__);
          break;
        }
      } else if (ret == -ERESTARTSYS || ret == -EINTR) {
        return ret;
      } else if (ret == -ENOMEM) {
      } else {
        BUG();
      }
    }
  }

  if (ret == -ENOMEM) {
    req->status = RTK_CRMDEV_STATUS_NO_RESOURCE;
    pr_err("[crmmgr] acquire  : %s acquire failure, no resource available\n",
            _resource_client_get_name(client));
    ret = 0;
  }

  return 0;
}

static int _resource_service__acquire_lock_acquire(resource_client_t *client,
                                                   rtk_crmdev_request *req) {
  int ret = 0;
  mutex_lock(&_table_lock);
  ret = _resource_service__acquire_lock_table(client, req);
  mutex_unlock(&_table_lock);
  return ret;
}

static int _resource_service_register_lock_table(resource_client_t *client,
                                                 rtk_crmdev_request *req) {
  int32_t unique_id = req->data.register_resource.unique_id;
  rtk_crmdev_codec_resource_t *resource = &req->data.register_resource.resource;
  resource_client_t *target_client = NULL;
  resource_provider_t *providers[MAX_PROVIDER_COUNT];
  resource_record_t *records[MAX_RECORDS_COUNT];
  size_t provider_count = 0;
  size_t record_count = 0;
  size_t i = 0, j = 0;

  if (!_resource_table_contain_unique_id(_device_table, unique_id,
                                         &target_client)) {
    pr_err("[crmmgr] register : %s does not contain unique id %08x",
           _resource_client_get_name(client), unique_id);
    req->status = RTK_CRMDEV_STATUS_INVALID_UNIQUE_ID;
  }

  /* find if the client was already register resource */
  if (_resource_table_contain_client(_device_table, client,
                                     RESOURCE_FIND_TARGET_MONITOR)) {
    pr_debug("[crmmgr] register : %s register again %s for %08x\n",
            _resource_client_get_name(client),
            _codec_resource_to_string(resource), unique_id);

    _resource_service_release_lock_table(client, NULL);

  } else {
    pr_debug("[crmmgr] register : %s register first %s for %08x\n",
            _resource_client_get_name(client),
            _codec_resource_to_string(resource), unique_id);
  }

  _codec_resource_get_providers(resource, unique_id, providers,
                                &provider_count);

  /* if there are no providers that found in resource */
  if (provider_count == 0) {
    pr_err("[crmmgr] register : %s register invalid\n",
           _resource_client_get_name(client));
    req->status = RTK_CRMDEV_STATUS_INVALID_RESOURCE;
    return 0;
  }

  req->status = RTK_CRMDEV_STATUS_OK;

  /* check conditions */
  for (i = 0; i < provider_count; i++) {
    resource_provider_t *provider = providers[i];
    if (_resource_provider_is_group(provider)) {
      BUG();
    }
    record_count = 0;
    if (_resource_provider_contain_unique_id(provider, unique_id, records,
                                             &record_count)) {
      if (record_count == 0) {
        BUG();
      }
      for (j = 0; j < record_count; j++) {
        resource_record_t *record = records[j];
        if (_resource_record_contain_monitor(record, client)) {
          BUG();
        }
        if (!_resource_record_has_monitor_space(record)) {
          pr_err(
              "[crmmgr] register : %s (%s) of %s does not has monitor slots\n",
              _resource_record_get_name(record),
              _resource_provider_get_name(provider),
              _resource_client_get_name(target_client));
          req->status = RTK_CRMDEV_STATUS_NO_SLOTS;
        }
      }

    } else {
      pr_err("[crmmgr] register : %s does not has (%s)\n",
             _resource_client_get_name(target_client),
             _resource_provider_get_name(provider));
      req->status = RTK_CRMDEV_STATUS_INVALID_RESOURCE;
    }
  }

  if (req->status != RTK_CRMDEV_STATUS_OK) {
    return 0;
  }

  /* batch to insert monitor actually */
  for (i = 0; i < provider_count; i++) {
    resource_provider_t *provider = providers[i];
    record_count = 0;
    if (_resource_provider_contain_unique_id(provider, unique_id, records,
                                             &record_count)) {
      for (j = 0; j < record_count; j++) {
        resource_record_t *record = records[j];
        if (_resource_record_add_monitor(record, client)) {
          pr_debug(
              "[crmmgr] register : %s monitor was insert into in %s (%s) "
              "for %s\n",
              _resource_client_get_name(client),
              _resource_record_get_name(record),
              _resource_provider_get_name(provider),
              _resource_client_get_name(target_client));
        } else {
          BUG();
        }
      }
    }
  }
  return 0;
}

static int _resource_service_register_lock_acquire(resource_client_t *client,
                                                   rtk_crmdev_request *req) {
  int ret = 0;
  mutex_lock(&_table_lock);
  ret = _resource_service_register_lock_table(client, req);
  mutex_unlock(&_table_lock);
  return ret;
}

static void _resource_service_dump(struct seq_file *m) {
  mutex_lock(&_table_lock);
  _resource_table_dump(_device_table, m);
  mutex_unlock(&_table_lock);
}

///////////////////////////////////////////////////////////////////////////////
// public interface
///////////////////////////////////////////////////////////////////////////////

static long _rtk_crmmgr_ioctl_reset(resource_client_t *client,
                                    rtk_crmdev_request *req) {
  resource_client_t *curr = NULL;
  uint32_t count = 0;
  mutex_lock(&_table_lock);
  list_for_each_entry(curr, &_client_list, list) { count++; }
  if (count == 1) {
    memset(_device_table, 0, sizeof(*_device_table));
    pr_err("[crmmgr] init     : table reset success\n");
    req->status = RTK_CRMDEV_STATUS_OK;
  } else {
    pr_err("[crmmgr] init     : table reset failure, use by %u instance\n",
           count);
    req->status = RTK_CRMDEV_STATUS_ERROR;
  }
  mutex_unlock(&_table_lock);

  return 0;
}

static long _rtk_crmmgr_ioctl_add_provider(resource_client_t *client,
                                           rtk_crmdev_request *req) {
  mutex_lock(&_table_lock);
  _resource_table_add_provider(req);
  mutex_unlock(&_table_lock);

  return 0;
}

static long _rtk_crmmgr_ioctl_add_reference(resource_client_t *client,
                                            rtk_crmdev_request *req) {
  mutex_lock(&_table_lock);
  _resource_table_add_reference(req);
  mutex_unlock(&_table_lock);

  return 0;
}

static long _rtk_crmmgr_ioctl_add_format(resource_client_t *client,
                                         rtk_crmdev_request *req) {
  mutex_lock(&_table_lock);
  _resource_table_add_format(req);
  mutex_unlock(&_table_lock);

  return 0;
}

static long _rtk_crmmgr_ioctl_add_require(resource_client_t *client,
                                          rtk_crmdev_request *req) {
  mutex_lock(&_table_lock);
  _resource_table_add_require(req);
  mutex_unlock(&_table_lock);

  return 0;
}

static long _rtk_crmmgr_ioctl_add_capability(resource_client_t *client,
                                         rtk_crmdev_request *req) {
  mutex_lock(&_table_lock);
  _resource_table_add_capability(req);
  mutex_unlock(&_table_lock);

  return 0;
}


static long _rtk_crmmgr_ioctl_wait_event(resource_client_t *client,
                                         rtk_crmdev_request *req) {
  int ret = 0;

  pr_err("[crmmgr] events   : %s wait event\n",
          _resource_client_get_name(client));

  ret = wait_event_freezable(
      client->event_wait,
      test_bit(RESOURCE_CLIENT_STATUS_CANCEL, &client->state) ||
          test_bit(RESOURCE_CLIENT_STATUS_RECLAIM, &client->state) ||
          test_bit(RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY, &client->state));
  if (ret) {
    if (signal_pending(current)) {
      pr_warning("[crmmgr] events   : %s caught pending signal when wait\n",
                 _resource_client_get_name(client));
      return -EINTR;
    }
    return -ERESTARTSYS;
  }

  pr_err("[crmmgr] events   : %s process %s\n",
          _resource_client_get_name(client),
          _resource_client_get_state_name(client));

  if (test_and_clear_bit(RESOURCE_CLIENT_STATUS_CANCEL, &client->state)) {
    req->status = RTK_CRMDEV_STATUS_CANCEL;
  } else if (test_and_clear_bit(RESOURCE_CLIENT_STATUS_RECLAIM,
                                &client->state)) {
    req->status = RTK_CRMDEV_STATUS_RECLAIM;
  } else if (test_and_clear_bit(RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY,
                                &client->state)) {
    req->status = RTK_CRMDEV_STATUS_PRIORITY;
  } else {
    BUG();
  }

  return ret;
}

static long _rtk_crmmgr_ioctl_release_resource(resource_client_t *client,
                                               rtk_crmdev_request *req) {
  pr_err("[crmmgr] release  : %s\n", _resource_client_get_name(client));

  mutex_lock(&_table_lock);
  _resource_service_release_lock_table(client, req);
  mutex_unlock(&_table_lock);

  return 0;
}

static long _rtk_crmmgr_ioctl_acquire_resource(resource_client_t *client,
                                               rtk_crmdev_request *req) {
  int ret = 0;
  pr_err("[crmmgr] acquire  : %s\n", _resource_client_get_name(client));

  mutex_lock(&_acquire_lock);
  ret = _resource_service__acquire_lock_acquire(client, req);
  mutex_unlock(&_acquire_lock);

  return ret;
}

static long _rtk_crmmgr_ioctl_register_resource(resource_client_t *client,
                                                rtk_crmdev_request *req) {
  int ret = 0;
  pr_err("[crmmgr] register : %s\n", _resource_client_get_name(client));

  mutex_lock(&_acquire_lock);
  ret = _resource_service_register_lock_acquire(client, req);
  mutex_unlock(&_acquire_lock);

  return ret;
}

static long _rtk_crmmgr_ioctl_check_support(resource_client_t *client,
                                            rtk_crmdev_request *req) {
  pr_err("[crmmgr] support  : %s\n", _resource_client_get_name(client));

  mutex_lock(&_table_lock);
  _resource_service_check_support_lock_table(client, req);
  mutex_unlock(&_table_lock);

  return 0;
}

static long _rtk_crmmgr_ioctl_check_capability(resource_client_t *client,
                                            rtk_crmdev_request *req) {
  pr_err("[crmmgr] capability  : %s\n", _resource_client_get_name(client));

  mutex_lock(&_table_lock);
  _resource_service_check_capability_lock_table(client, req);
  mutex_unlock(&_table_lock);

  return 0;
}

static long _rtk_crmmgr_ioctl_set_name(resource_client_t *client,
                                       rtk_crmdev_request *req) {
  snprintf(client->name, sizeof(client->name), "%s-%08x",
           req->data.set_name.name, client->unique_id);
  pr_debug("[crmmgr] create   : %s %p\n", client->name, client);
  req->data.set_name.unique_id = client->unique_id;
  req->status = RTK_CRMDEV_STATUS_OK;
  return 0;
}

static long _rtk_crmmgr_ioctl_cancel_event(resource_client_t *client,
                                           rtk_crmdev_request *req) {
  pr_debug("[crmmgr] events   : %s cancel event\n",
          _resource_client_get_name(client));
  _resource_client_wake_event(client, RESOURCE_CLIENT_STATUS_CANCEL);
  req->status = RTK_CRMDEV_STATUS_OK;
  return 0;
}

static long _rtk_crmmgr_ioctl_response_reclaim(resource_client_t *client,
                                               rtk_crmdev_request *req) {
  if (req->data.response_reclaim.accept) {
    pr_err("[crmmgr] events   : %s response reclaim accept\n",
            _resource_client_get_name(client));
    _resource_client_wake_event(client, RESOURCE_CLIENT_STATUS_RECLAIM_ACCEPT);
  } else {
    pr_err("[crmmgr] events   : %s response reclaim reject\n",
            _resource_client_get_name(client));
    _resource_client_wake_event(client, RESOURCE_CLIENT_STATUS_RECLAIM_REJECT);
  }
  req->status = RTK_CRMDEV_STATUS_OK;
  return 0;
}

static long _rtk_crmmgr_ioctl_response_priority(resource_client_t *client,
                                                rtk_crmdev_request *req) {
  pr_debug("[crmmgr] events   : %s response priority\n",
          _resource_client_get_name(client));
  client->priority = req->data.response_priority.priority;
  _resource_client_wake_event(client,
                              RESOURCE_CLIENT_STATUS_UPDATE_PRIORITY_DONE);
  req->status = RTK_CRMDEV_STATUS_OK;
  return 0;
}

static long _rtk_crmmgr_ioctl_unknown(resource_client_t *client,
                                      rtk_crmdev_request *req) {
  req->status = RTK_CRMDEV_STATUS_INVALID_CMD;
  pr_err("[crmmgr] ioctl    : invalid command %d\n", req->cmd);
  return 0;
}

static long _rtk_crmmgr_unlocked_ioctl(struct file *filp, unsigned int cmd,
                                       unsigned long arg) {
  resource_client_t *client = (resource_client_t *)filp->private_data;
  rtk_crmdev_request req;
  long ret = 0;

  if (cmd == RTK_CRMMGR_IOC_REQUEST) {
    if (copy_from_user(&req, (void __user *)arg, sizeof(req))) {
      return -EFAULT;
    }
    switch (req.cmd) {
      case RTK_CRMDEV_CMD_RESET:
        ret = _rtk_crmmgr_ioctl_reset(client, &req);
        break;
      case RTK_CRMDEV_CMD_ADD_PROVIDER:
        ret = _rtk_crmmgr_ioctl_add_provider(client, &req);
        break;
      case RTK_CRMDEV_CMD_ADD_REFERENCE:
        ret = _rtk_crmmgr_ioctl_add_reference(client, &req);
        break;
      case RTK_CRMDEV_CMD_ADD_FORMAT:
        ret = _rtk_crmmgr_ioctl_add_format(client, &req);
        break;
      case RTK_CRMDEV_CMD_ADD_REQUIRE:
        ret = _rtk_crmmgr_ioctl_add_require(client, &req);
        break;
      case RTK_CRMDEV_CMD_ADD_CAPABILITY:
        ret = _rtk_crmmgr_ioctl_add_capability(client, &req);
        break;
      case RTK_CRMDEV_CMD_SET_NAME:
        ret = _rtk_crmmgr_ioctl_set_name(client, &req);
        break;
      case RTK_CRMDEV_CMD_ACQUIRE_RESOURCE:
        ret = _rtk_crmmgr_ioctl_acquire_resource(client, &req);
        break;
      case RTK_CRMDEV_CMD_REGISTER_RESOURCE:
        ret = _rtk_crmmgr_ioctl_register_resource(client, &req);
        break;
      case RTK_CRMDEV_CMD_RELEASE_RESOURCE:
        ret = _rtk_crmmgr_ioctl_release_resource(client, &req);
        break;
      case RTK_CRMDEV_CMD_CHECK_SUPPORT:
        ret = _rtk_crmmgr_ioctl_check_support(client, &req);
        break;
      case RTK_CRMDEV_CMD_CHECK_CAPABILITY:
        ret = _rtk_crmmgr_ioctl_check_capability(client, &req);
        break;
      case RTK_CRMDEV_CMD_WAIT_EVENT:
        ret = _rtk_crmmgr_ioctl_wait_event(client, &req);
        break;
      case RTK_CRMDEV_CMD_CANCEL_EVENT:
        ret = _rtk_crmmgr_ioctl_cancel_event(client, &req);
        break;
      case RTK_CRMDEV_CMD_RESPONSE_RECLAIM:
        ret = _rtk_crmmgr_ioctl_response_reclaim(client, &req);
        break;
      case RTK_CRMDEV_CMD_RESPONSE_PRIORITY:
        ret = _rtk_crmmgr_ioctl_response_priority(client, &req);
        break;
      default:
        ret = _rtk_crmmgr_ioctl_unknown(client, &req);
        break;
    }
    if (!ret) {
      if (copy_to_user((void __user *)arg, &req, sizeof(req))) {
        return -EFAULT;
      }
    } else {
      pr_warning("[crmmgr] ioctl    : %s command %d, ret %ld\n",
                 _resource_client_get_name(client), req.cmd, ret);
    }
  }
  return ret;
}

static int rtk_crmmgr_open(struct inode *inode, struct file *filp) {
  if (!_resource_client_create(filp)) {
    return -ENOMEM;
  }
  return 0;
}

static int rtk_crmmgr_release(struct inode *inode, struct file *filp) {
  _resource_client_release(filp);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
// proc filesystem
///////////////////////////////////////////////////////////////////////////////

static int rtk_crmmgr_proc_status_show(struct seq_file *m, void *v) {
  _resource_service_dump(m);
  return 0;
}

static int rtk_crmmgr_proc_status_open(struct inode *inode, struct file *file) {
  return single_open(file, rtk_crmmgr_proc_status_show, NULL);
}

struct proc_dir_entry *_proc_dir = NULL;
struct proc_dir_entry *_proc_entry = NULL;

static const struct file_operations rtk_crmmgr_proc_status_fops = {
    .owner = THIS_MODULE,
    .open = rtk_crmmgr_proc_status_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = single_release,
};

static int rtk_crmmgr_proc_init(void) {
  if (_proc_dir == NULL && _proc_entry == NULL) {
    _proc_dir = proc_mkdir(RTK_CRMMGR_PROC_DIR, NULL);
    if (_proc_dir == NULL) {
      pr_err("[crmmgr] failure to create proc dir (%s)\n", RTK_CRMMGR_PROC_DIR);
      goto error_proc_mkdir;
    }
    _proc_entry =
        proc_create("status", 0666, _proc_dir, &rtk_crmmgr_proc_status_fops);
    if (_proc_entry == NULL) {
      pr_err("[crmmgr] failure to create proc log entry\n");
      goto error_proc_create_log;
    }
  }

  return 0;

error_proc_create_log:

  proc_remove(_proc_dir);
  _proc_dir = NULL;

error_proc_mkdir:

  return -ENOMEM;
}

static void rtk_crmmgr_proc_exit(void) {
  if (_proc_entry) {
    proc_remove(_proc_entry);
    _proc_entry = NULL;
  }
  if (_proc_dir) {
    proc_remove(_proc_dir);
    _proc_dir = NULL;
  }
}

static const struct file_operations rtk_crmmgr_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = _rtk_crmmgr_unlocked_ioctl,
    .open = rtk_crmmgr_open,
    .release = rtk_crmmgr_release,
};

static struct miscdevice rtk_crmmgr_miscdev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "rtkcrmmgr",
    .fops = &rtk_crmmgr_fops,
    .mode = 0666,
};

static int __init rtk_crmmgr_init(void) {
  int ret = 0;
  pr_debug("[crmmgr] init\n");
  _device_table = kzalloc(sizeof(*_device_table), GFP_KERNEL);
  if (!_device_table) {
    pr_err("[crmmgr] failure to allocate resource table\n");
    return -ENOMEM;
  }
  ret = misc_register(&rtk_crmmgr_miscdev);
  if (ret) {
    pr_err("[crmmgr] failure to misc_register\n");
    return ret;
  }
  ret = rtk_crmmgr_proc_init();
  if (ret) {
    pr_err("[crmmgr] failure to rtk_crmmgr_proc_init\n");
    return ret;
  }
  return ret;
}

static void __exit rtk_crmmgr_exit(void) {
  pr_debug("[crmmgr] exit\n");
  rtk_crmmgr_proc_exit();
  misc_deregister(&rtk_crmmgr_miscdev);
  if (_device_table) {
    kfree(_device_table);
    _device_table = NULL;
  }
}

module_init(rtk_crmmgr_init);
module_exit(rtk_crmmgr_exit);
MODULE_LICENSE("GPL");
