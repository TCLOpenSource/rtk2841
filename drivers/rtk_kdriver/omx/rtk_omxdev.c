///////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Realtek Semiconductor Corp.
///////////////////////////////////////////////////////////////////////////////

#include <generated/autoconf.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/gfp.h>
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

#include <rpc_common.h>

#include <rtk_kdriver/rtk_omxdev.h>

//////////////////////////////////////////////////////////////////////////////
// internal structures
///////////////////////////////////////////////////////////////////////////////

#define MAX_CLOCK_COUNT (8)
#define INVALID_GROUP_ID (-1U)

typedef struct _rtk_omxdev_client_t {
  //
  uint32_t group;
} rtk_omxdev_client_t;

typedef struct _rtk_omxdev_clock_t {
  REFCLOCK *refclock;
  ulong phyaddr;
  uint32_t group;
  uint32_t num_client;
  uint64_t time;
} __attribute__((__aligned__(256))) rtk_omxdev_clock_t;

typedef struct _rtk_omxdev_context_t {
  rtk_omxdev_clock_t clocks[MAX_CLOCK_COUNT];
} rtk_omxdev_context_t;

static DEFINE_MUTEX(_device_lock);
static rtk_omxdev_context_t *_device_context = NULL;

static uint64_t rtk_omxdev_get_monotonic_time(void) {
  struct timespec ts;
  getrawmonotonic(&ts);
  return (1000000ULL * ts.tv_sec) + (ts.tv_nsec / 1000);
}

static int rtk_omxdev_clock_compare(const void *lhs, const void *rhs) {
  rtk_omxdev_clock_t *l = *((rtk_omxdev_clock_t **)lhs);
  rtk_omxdev_clock_t *r = *((rtk_omxdev_clock_t **)rhs);

  if (l->time < r->time) {
    return -1;
  } else if (l->time > r->time) {
    return 1;
  } else {
    return 0;
  }
}

static void rtk_omxdev_clock_acquire_lock(rtk_omxdev_client_t *client,
                                          rtk_omxdev_request_t *req) {
  size_t i = 0;
  size_t clock_count = 0;
  rtk_omxdev_clock_t *clock = NULL;
  rtk_omxdev_clock_t *clocks[MAX_CLOCK_COUNT];
  rtk_omxdev_clock_acquire_t *param = &req->data.clock_acquire;

  if (client->group != INVALID_GROUP_ID) {
    pr_err("[omx] acquire : client already has clock\n");
    req->status = RTK_OMXDEV_STATUS_ERROR;
    return;
  }

  if (param->group == INVALID_GROUP_ID) {
    pr_err("[omx] acquire : invalid group id\n");
    req->status = RTK_OMXDEV_STATUS_ERROR;
    return;
  }

  for (i = 0; i < MAX_CLOCK_COUNT; i++) {
    clock = &_device_context->clocks[i];
    if (clock->group == param->group) {
      if (clock->num_client == 0) {
        BUG();
      }
      break;
    } else if (clock->group == INVALID_GROUP_ID) {
      if (clock->num_client != 0) {
        BUG();
      }
      clocks[clock_count++] = clock;
    }
  }

  // not found
  if (i == MAX_CLOCK_COUNT) {
    if (clock_count == 0) {
      pr_err("[omx] acquire : no clock available\n");
      req->status = RTK_OMXDEV_STATUS_ERROR;
      return;
    }
    // sort by acquire_time
    sort(clocks, clock_count, sizeof(rtk_omxdev_clock_t *),
         &rtk_omxdev_clock_compare, NULL);
    clock = clocks[0];
    param->first = 1;
  } else {
    param->first = 0;
  }

  client->group = param->group;
  clock->group = param->group;
  clock->num_client++;
  clock->time = rtk_omxdev_get_monotonic_time();
  param->phyaddr = clock->phyaddr;
  req->status = RTK_OMXDEV_STATUS_OK;

  pr_info("[omx] %p acquire clock %08lx %08x %02u\n", client, clock->phyaddr,
          clock->group, clock->num_client);
}

static void rtk_omxdev_clock_release_lock(rtk_omxdev_client_t *client,
                                          rtk_omxdev_request_t *req) {
  uint32_t i;
  if (client->group != INVALID_GROUP_ID) {
    for (i = 0; i < MAX_CLOCK_COUNT; i++) {
      rtk_omxdev_clock_t *clock = &_device_context->clocks[i];
      if (clock->group == client->group) {
        pr_info("[omx] %p release clock %08lx %08x %02u\n", client,
                clock->phyaddr, clock->group, clock->num_client);
        if (clock->num_client == 0) {
          BUG();
        }
        clock->num_client--;
        if (clock->num_client == 0) {
          clock->group = INVALID_GROUP_ID;
        }
        break;
      }
    }
    client->group = INVALID_GROUP_ID;
  }
  if (req) {
    req->status = RTK_OMXDEV_STATUS_OK;
  }
}

static bool rtk_omxdev_client_create(struct file *filp) {
  rtk_omxdev_client_t *client = NULL;
  client = kzalloc(sizeof(*client), GFP_KERNEL);
  if (client) {
    client->group = INVALID_GROUP_ID;
  }
  filp->private_data = client;
  pr_info("[omx] create : %p\n", client);
  return client ? true : false;
}

static void rtk_omxdev_client_release(struct file *filp) {
  rtk_omxdev_client_t *client = NULL;
  if (filp && filp->private_data) {
    client = (rtk_omxdev_client_t *)filp->private_data;
    mutex_lock(&_device_lock);
    rtk_omxdev_clock_release_lock(client, NULL);
    mutex_unlock(&_device_lock);
    kfree(client);
    filp->private_data = NULL;
    pr_info("[omx] release : %p\n", client);
  }
}

static void rtk_omxdev_context_finalize_l(void) {
  size_t i;
  if (_device_context) {
    for (i = 0; i < MAX_CLOCK_COUNT; i++) {
      rtk_omxdev_clock_t *clock = &_device_context->clocks[i];
      if (clock->refclock) {
        dvr_free(clock->refclock);
        pr_info("[omx] finalize refclock %u %08lx\n", i, clock->phyaddr);
        clock->refclock = NULL;
      }
    }
    pr_info("[omx] finalize context %p\n", _device_context);
    kfree((void *)_device_context);
    _device_context = NULL;
  }
}

static int rtk_omxdev_context_create(void) {
  size_t i;

  mutex_lock(&_device_lock);
  _device_context = kzalloc(sizeof(*_device_context), GFP_KERNEL);
  if (!_device_context) {
    pr_err("[omx] failure to create content");
    goto error_create_device_context;
  }
  for (i = 0; i < MAX_CLOCK_COUNT; i++) {
    rtk_omxdev_clock_t *clock = &_device_context->clocks[i];
    clock->refclock = (REFCLOCK *)dvr_malloc_specific(4096, GFP_DCU1);
    if (!clock->refclock) {
      pr_err("[omx] failure to refclock");
      goto error_create_refclock;
    }
    clock->phyaddr = dvr_to_phys((void *)clock->refclock);
    clock->group = INVALID_GROUP_ID;
    clock->num_client = 0U;
    clock->time = 0U;
    pr_info("[omx] create clock %u %08lx\n", i, clock->phyaddr);
  }
  mutex_unlock(&_device_lock);

  return 0;

error_create_refclock:

  rtk_omxdev_context_finalize_l();

error_create_device_context:

  mutex_unlock(&_device_lock);

  return -ENOMEM;
}

static void rtk_omxdev_context_finalize(void) {
  mutex_lock(&_device_lock);
  rtk_omxdev_context_finalize_l();
  mutex_unlock(&_device_lock);
}

static void rtk_omxdev_proc_dump(const rtk_omxdev_context_t *context,
                                 struct seq_file *m) {
  size_t i = 0;
  mutex_lock(&_device_lock);
  for (i = 0; i < MAX_CLOCK_COUNT; i++) {
    const rtk_omxdev_clock_t *clock = &context->clocks[i];
    seq_printf(m, "[%02u] %08lx %08x %02u %llu\n", i, clock->phyaddr,
               clock->group, clock->num_client, clock->time);
  }
  mutex_unlock(&_device_lock);
}

static long _rtk_omxdev_ioctl_clock_acquire(rtk_omxdev_client_t *client,
                                            rtk_omxdev_request_t *req) {
  mutex_lock(&_device_lock);
  rtk_omxdev_clock_acquire_lock(client, req);
  mutex_unlock(&_device_lock);
  return 0;
}

static long _rtk_omxdev_ioctl_clock_release(rtk_omxdev_client_t *client,
                                            rtk_omxdev_request_t *req) {
  mutex_lock(&_device_lock);
  rtk_omxdev_clock_release_lock(client, req);
  mutex_unlock(&_device_lock);
  return 0;
}

static long _rtk_omxdev_ioctl_unknown(rtk_omxdev_client_t *client,
                                      rtk_omxdev_request_t *req) {
  req->status = RTK_OMXDEV_STATUS_INVALID_CMD;
  pr_err("[omx] ioctl    : invalid command %d\n", req->cmd);
  return 0;
}

static long _rtk_omxdev_unlocked_ioctl(struct file *filp, unsigned int cmd,
                                       unsigned long arg) {
  rtk_omxdev_client_t *client = (rtk_omxdev_client_t *)filp->private_data;
  rtk_omxdev_request_t req;
  long ret = 0;

  if (cmd == RTK_OMXDEC_IOC_REQUEST) {
    if (copy_from_user(&req, (void __user *)arg, sizeof(req))) {
      return -EFAULT;
    }
    switch (req.cmd) {
      case RTK_OMXDEV_CMD_CLOCK_ACQUIRE:
        ret = _rtk_omxdev_ioctl_clock_acquire(client, &req);
        break;
      case RTK_OMXDEV_CMD_CLOCK_RELEASE:
        ret = _rtk_omxdev_ioctl_clock_release(client, &req);
        break;
      default:
        ret = _rtk_omxdev_ioctl_unknown(client, &req);
        break;
    }
    if (!ret) {
      if (copy_to_user((void __user *)arg, &req, sizeof(req))) {
        return -EFAULT;
      }
    } else {
      pr_warning("[omx] ioctl    : %p command %d, ret %ld\n", client, req.cmd,
                 ret);
    }
  }
  return ret;
}

static int rtk_omxdev_open(struct inode *inode, struct file *filp) {
  if (!rtk_omxdev_client_create(filp)) {
    return -ENOMEM;
  }
  return 0;
}

static int rtk_omxdev_release(struct inode *inode, struct file *filp) {
  rtk_omxdev_client_release(filp);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
// proc filesystem
///////////////////////////////////////////////////////////////////////////////

static int rtk_omxdev_proc_status_show(struct seq_file *m, void *v) {
  rtk_omxdev_proc_dump(_device_context, m);
  return 0;
}

static int rtk_omxdev_proc_status_open(struct inode *inode, struct file *file) {
  return single_open(file, rtk_omxdev_proc_status_show, NULL);
}

struct proc_dir_entry *rtk_omxdev_proc_dir = NULL;
struct proc_dir_entry *rtk_omxdev_proc_entry = NULL;

static const struct file_operations rtk_omxdev_proc_status_fops = {
    .owner = THIS_MODULE,
    .open = rtk_omxdev_proc_status_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = single_release,
};

static int rtk_omxdev_proc_init(void) {
  if (rtk_omxdev_proc_dir == NULL && rtk_omxdev_proc_entry == NULL) {
    rtk_omxdev_proc_dir = proc_mkdir(RTK_OMXDEC_PROC_DIR, NULL);
    if (rtk_omxdev_proc_dir == NULL) {
      pr_err("[omx] failure to create proc dir (%s)\n", RTK_OMXDEC_PROC_DIR);
      goto error_proc_mkdir;
    }
    rtk_omxdev_proc_entry = proc_create("status", 0666, rtk_omxdev_proc_dir,
                                        &rtk_omxdev_proc_status_fops);
    if (rtk_omxdev_proc_entry == NULL) {
      pr_err("[omx] failure to create proc log entry\n");
      goto error_proc_create_log;
    }
  }

  return 0;

error_proc_create_log:

  proc_remove(rtk_omxdev_proc_dir);
  rtk_omxdev_proc_dir = NULL;

error_proc_mkdir:

  return -ENOMEM;
}

static void rtk_omxdev_proc_exit(void) {
  if (rtk_omxdev_proc_entry) {
    proc_remove(rtk_omxdev_proc_entry);
    rtk_omxdev_proc_entry = NULL;
  }
  if (rtk_omxdev_proc_dir) {
    proc_remove(rtk_omxdev_proc_dir);
    rtk_omxdev_proc_dir = NULL;
  }
}

static const struct file_operations rtk_omxdev_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = _rtk_omxdev_unlocked_ioctl,
    .open = rtk_omxdev_open,
    .release = rtk_omxdev_release,
};

static struct miscdevice rtk_omxdev_miscdev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "rtkomx",
    .fops = &rtk_omxdev_fops,
    .mode = 0666,
};

static int __init rtk_omxdev_init(void) {
  int ret = 0;

  ret = rtk_omxdev_context_create();
  if (ret) {
    pr_err("[omx] failure to allocate context\n");
    return ret;
  }
  ret = misc_register(&rtk_omxdev_miscdev);
  if (ret) {
    pr_err("[omx] failure to misc_register\n");
    return ret;
  }
  ret = rtk_omxdev_proc_init();
  if (ret) {
    pr_err("[omx] failure to rtk_omxdev_proc_init\n");
    return ret;
  }

  pr_info("[omx] init\n");

  return ret;
}

static void __exit rtk_omxdev_exit(void) {
  rtk_omxdev_proc_exit();
  misc_deregister(&rtk_omxdev_miscdev);
  rtk_omxdev_context_finalize();
  pr_info("[omx] exit\n");
}

module_init(rtk_omxdev_init);
module_exit(rtk_omxdev_exit);
MODULE_LICENSE("GPL");
