///////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Realtek Semiconductor Corp.
///////////////////////////////////////////////////////////////////////////////

#ifndef __REALTEK_3413F315_02CC_4EE3_9F39_E68DF4D75C6F_H__
#define __REALTEK_3413F315_02CC_4EE3_9F39_E68DF4D75C6F_H__

typedef enum _rtk_omxdev_cmd_t {
  RTK_OMXDEV_CMD_NONE,
  RTK_OMXDEV_CMD_CLOCK_ACQUIRE,
  RTK_OMXDEV_CMD_CLOCK_RELEASE,
} rtk_omxdev_cmd_t;

typedef enum _rtk_omxdev_status_t {
  RTK_OMXDEV_STATUS_OK,
  RTK_OMXDEV_STATUS_ERROR,
  RTK_OMXDEV_STATUS_INVALID_CMD,
} rtk_omxdev_status_t;

typedef struct _rtk_omxdev_clock_acquire_t {
  unsigned int group;
  unsigned long phyaddr;
  unsigned int first;
} rtk_omxdev_clock_acquire_t;

typedef union _rtk_omxdev_data_t {
  rtk_omxdev_clock_acquire_t clock_acquire;
} rtk_omxdev_data_t;

typedef struct _rtk_omxdev_request_t {
  rtk_omxdev_cmd_t cmd;
  rtk_omxdev_status_t status;
  rtk_omxdev_data_t data;
} rtk_omxdev_request_t;

#define RTK_OMXDEC_PROC_DIR "rtkomx"
#define RTK_OMXDEC_DEVICE_PATH "/dev/rtkomx"
#define RTK_OMXDEC_IOC_MAGIC 'o'
#define RTK_OMXDEC_IOC_REQUEST \
  _IOWR(RTK_OMXDEC_IOC_MAGIC, 1, rtk_omxdev_request_t)

#endif /* __REALTEK_3413F315_02CC_4EE3_9F39_E68DF4D75C6F_H__ */
