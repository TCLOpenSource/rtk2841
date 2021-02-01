/*Copyright (C) 2007-2013 Realtek Semiconductor Corporation.*/
#ifndef __RTK_DISEQC_DEV_H__
#define __RTK_DISEQC_DEV_H__

#include <linux/cdev.h>
#include "rtk_diseqc_data_buff.h"
#include "rtk_diseqc.h"


typedef struct {
	unsigned char len;
	unsigned char *buf;
} diseqc_msg;

#ifdef CONFIG_COMPAT
typedef struct {
	unsigned int buf;
	unsigned char len;
} compat_diseqc_msg;

#endif

typedef struct {
	struct cdev cdev;
	struct device *device;
} diseqc_dev;

extern int create_diseqc_dev_node(diseqc_device *dev);
extern void remove_diseqc_dev_node(diseqc_device *dev);

#define DISEQC_IOC_MAGIC  'd'
#define DISEQC_IOCR_22K_SET                 _IOW(DISEQC_IOC_MAGIC,  0, int)
#define DISEQC_IOCR_CMD_SET                 _IOW(DISEQC_IOC_MAGIC,  1, diseqc_msg)
#define DISEQC_IOCR_MOD_TONE_BURST_SET      _IOW(DISEQC_IOC_MAGIC,  2, int)
#define DISEQC_IOCR_UNMOD_TONE_BURST_SET    _IOW(DISEQC_IOC_MAGIC,  3, int)
#define DISEQC_IOCR_TONE_BURST_SET          _IOW(DISEQC_IOC_MAGIC,  4, int)

#define DISEQC_IOC_MAXNR  5
#endif
