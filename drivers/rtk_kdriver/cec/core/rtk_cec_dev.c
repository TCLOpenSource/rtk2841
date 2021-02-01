/*Copyright (C) 2007-2013 Realtek Semiconductor Corporation.*/
#include <linux/kernel.h>
#include <linux/ioport.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>	/* copy_*_user */

#include "rtk_cec.h"
#include "rtk_cec_dev.h"

#define MAX_CEC_CNT             4
static cec_dev node_list[MAX_CEC_CNT];
static dev_t devno_base;
static struct class *cec_dev_class;

/*------------------------------------------------------------------
 * Func : create_cec_dev_node
 *
 * Desc : create a cec device node
 *
 * Parm : device : handle of cec device
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int create_cec_dev_node(cec_device *device)
{
	int i;
	for (i = 0; i < MAX_CEC_CNT; i++) {
		if (node_list[i].device == NULL) {
		    /*register character device node to system*/
			if (cdev_add(&node_list[i].cdev, devno_base + i, 1) < 0) {
				cec_warn
				    (" register character dev failed\n");
				return -1;
			}

			node_list[i].device = device_create(cec_dev_class,	/* class */
							    NULL,	/* parent */
							    devno_base + i,	/* dev number */
							    device,	/* driver data */
							    "cec-%d",	/* device name */
							    i);	/* device id */

			return 0;
		}
	}

	return -1;
}

/*------------------------------------------------------------------
 * Func : remove_cec_dev_node
 *
 * Desc : remove a cec device node
 *
 * Parm : device : cec device to be unregistered
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
void remove_cec_dev_node(cec_device *device)
{
	int i = 0;

	for (i = 0; i < MAX_CEC_CNT; i++) {
		if (node_list[i].device
		    && dev_get_drvdata(node_list[i].device) == (void *)device) {
			device_destroy(cec_dev_class, devno_base + i);	/* remove device */
			cdev_del(&node_list[i].cdev);
			node_list[i].device = NULL;
			return;
		}
	}
}

/*------------------------------------------------------------------
 * Func : cec_dev_open
 *
 * Desc : open function of cec dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int cec_dev_open(struct inode *inode, struct file *file)
{
	unsigned int i = iminor(inode);
	cec_device *dev;

	if (i >= MAX_CEC_CNT || !node_list[i].device)
		return -ENODEV;

	dev = (cec_device *) dev_get_drvdata(node_list[i].device);

	if (dev) {
		/*cec_driver* drv = (cec_driver*) to_cec_driver(dev->dev.driver);*/
		file->private_data = dev;
		return 0;
	}

	return -ENODEV;
}

/*------------------------------------------------------------------
 * Func : cec_dev_release
 *
 * Desc : release function of cec dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int cec_dev_release(struct inode *inode, struct file *file)
{
	unsigned int i = iminor(inode);
	cec_device *dev;
	cec_driver *drv;

	if (i < MAX_CEC_CNT && node_list[i].device) {
		dev = (cec_device *) dev_get_drvdata(node_list[i].device);
		drv = (cec_driver *) to_cec_driver(dev->dev.driver);
		drv->enable(dev, 0xf0);
	}

	return 0;
}

/*------------------------------------------------------------------
 * Func : cec_dev_ioctl
 *
 * Desc : ioctl function of cec dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
long cec_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{

	cec_device *dev = (cec_device *) file->private_data;
	cec_driver *drv;
	cec_msg msg;
	cm_buff *cmb = NULL;
	int len;
	unsigned short rx_mask;
	unsigned int result;

	if (!dev)
		return -ENODEV;

	drv = (cec_driver *) to_cec_driver(dev->dev.driver);

	switch (cmd) {
	case CEC_ENABLE:
		return drv->enable(dev, (arg) ? 1 : 0);

	case CEC_SET_RX_MASK:	/* broadcast is always available here... */
		return drv->set_rx_mask(dev, (unsigned short)arg | 0x8000);

	case CEC_SET_LOGICAL_ADDRESS:

		rx_mask = (unsigned char)arg;
		if (rx_mask > 0xF) {
			cec_warn("invalid logical address %d\n", rx_mask);
			return -EFAULT;
		}
		rx_mask = (1 << rx_mask);
		return drv->set_rx_mask(dev, rx_mask | 0x8000);

	case CEC_SET_PHYSICAL_ADDRESS:
		return drv->set_physical_addr(dev, (unsigned short)arg);

	case CEC_SEND_MESSAGE:

		if (copy_from_user
		    (&msg, (cec_msg __user *) arg, sizeof(cec_msg)))
			return -EFAULT;
             if(!msg.len)
                    return -EFAULT;
		cmb = alloc_cmb(msg.len);
		if (cmb == NULL)
			return -ENOMEM;

		if (copy_from_user
		    (cmb_put(cmb, msg.len), (unsigned char __user *)msg.buf,
		     msg.len))
			return -EFAULT;

		return drv->xmit(dev, cmb, 0);	/* BLOCK I/O */

	case CEC_RCV_MESSAGE:

		if (copy_from_user
		    (&msg, (cec_msg __user *) arg, sizeof(cec_msg)))
			return -EFAULT;

		cmb = drv->read(dev, (file->f_flags & O_NONBLOCK) ? NONBLOCK : 0);	/* BLOCK I/O */

		if (cmb) {
			if (cmb->len > msg.len) {
				cec_warn
				    ("cec : read message failed, msg size (%d) more than msg buffer size(%d)\n",
				     cmb->len, msg.len);
				kfree_cmb(cmb);
				return -ENOMEM;
			}

			len = cmb->len;

			result =
			    copy_to_user((unsigned char __user *)msg.buf,
					 cmb->data, cmb->len) ? -EFAULT : 0;
			if (result < 0) {
				cec_warn
				    ("cec : read message failed, copy msg to user failed\n");
				kfree_cmb(cmb);
				return result;
			}

			kfree_cmb(cmb);
			return len;
		}

		return -EFAULT;

	case CEC_SET_STANDBY_MODE:

		return drv->set_stanby_mode(dev, (unsigned long)arg);

	case CEC_SET_CEC_VERSION:

		return drv->set_cec_version(dev, (unsigned char)arg);

	case CEC_SET_DEVICE_VENDOR_ID:

		return drv->set_device_vendor_id(dev, (unsigned long)arg);

	case CEC_SET_RETRY_NUM:

		return drv->set_retry_num(dev, (unsigned long)arg);

	default:
		cec_warn("cec : unknown ioctl cmd %08x\n", cmd);
		return -EFAULT;
	}
}

#ifdef CONFIG_COMPAT

/*------------------------------------------------------------------
 * Func : compat_cec_dev_ioctl
 *
 * Desc : ioctl function of cec dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
long compat_cec_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{

	cec_device *dev = (cec_device *) file->private_data;
	cec_driver *drv;
	cec_msg msg;
	cm_buff *cmb = NULL;
	int len;
	unsigned short rx_mask;
	unsigned int result;

	if (!dev)
		return -ENODEV;

	drv = (cec_driver *) to_cec_driver(dev->dev.driver);

	switch (cmd) {
	case CEC_ENABLE:
		return drv->enable(dev, (arg) ? 1 : 0);

	case CEC_SET_RX_MASK:	/* broadcast is always available here... */
		return drv->set_rx_mask(dev, (unsigned short)arg | 0x8000);

	case CEC_SET_LOGICAL_ADDRESS:

		rx_mask = (unsigned char)arg;
		if (rx_mask > 0xF) {
			cec_warn("invalid logical address %d\n", rx_mask);
			return -EFAULT;
		}
		rx_mask = (1 << rx_mask);
		return drv->set_rx_mask(dev, rx_mask | 0x8000);

	case CEC_SET_PHYSICAL_ADDRESS:
		return drv->set_physical_addr(dev, (unsigned short)arg);

	case CEC_SEND_MESSAGE:
	{
		compat_cec_msg cmsg;
		compat_cec_msg __user *user_req = compat_ptr(arg);
		if (copy_from_user
		    (&cmsg, user_req, sizeof(compat_cec_msg)))
			return -EFAULT;
		msg.len = cmsg.len;
		msg.buf = (unsigned char __user *)compat_ptr(cmsg.buf);
		cmb = alloc_cmb(msg.len);
		if (cmb == NULL)
			return -ENOMEM;

		if (copy_from_user
		    (cmb_put(cmb, msg.len), (unsigned char __user *)msg.buf,
		     msg.len))
			return -EFAULT;

		return drv->xmit(dev, cmb, 0);	/* BLOCK I/O */
	}
	case CEC_RCV_MESSAGE:
	{
		compat_cec_msg cmsg;
		compat_cec_msg __user *user_req = compat_ptr(arg);
		if (copy_from_user
		    (&cmsg, user_req, sizeof(compat_cec_msg)))
			return -EFAULT;
		msg.len = cmsg.len;
		msg.buf = (unsigned char __user *)compat_ptr(cmsg.buf);

		cmb = drv->read(dev, (file->f_flags & O_NONBLOCK) ? NONBLOCK : 0);	/* BLOCK I/O */

		if (cmb) {
			if (cmb->len > msg.len) {
				cec_warn
				    (" read message failed, msg size (%d) more than msg buffer size(%d)\n",
				     cmb->len, msg.len);
				kfree_cmb(cmb);
				return -ENOMEM;
			}

			len = cmb->len;

			result =
			    copy_to_user((unsigned char __user *)msg.buf,
					 cmb->data, cmb->len) ? -EFAULT : 0;
			if (result < 0) {
				cec_warn
				    (" read message failed, copy msg to user failed\n");
				kfree_cmb(cmb);
				return result;
			}

			kfree_cmb(cmb);
			return len;
		}

		return -EFAULT;
	}
	case CEC_SET_STANDBY_MODE:

		return drv->set_stanby_mode(dev, (unsigned long)arg);

	case CEC_SET_CEC_VERSION:

		return drv->set_cec_version(dev, (unsigned char)arg);

	case CEC_SET_DEVICE_VENDOR_ID:

		return drv->set_device_vendor_id(dev, (unsigned long)arg);

	case CEC_SET_RETRY_NUM:

		return drv->set_retry_num(dev, (unsigned long)arg);

	default:
		cec_warn(" unknown ioctl cmd %08x\n", cmd);
		return -EFAULT;
	}
}

#endif

static char *cec_devnode(struct device *dev, mode_t *mode)
{
	if(mode)
		*mode = 0666;
	return NULL;
}



static struct file_operations cec_dev_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = cec_dev_ioctl,
	#ifdef CONFIG_COMPAT
	.compat_ioctl = compat_cec_dev_ioctl,
	#endif
	.open = cec_dev_open,
	.release = cec_dev_release,
};

/*------------------------------------------------------------------
 * Func : cec_dev_module_init
 *
 * Desc : cec dev init function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int __init cec_dev_module_init(void)
{
	int i;
	unsigned int result = 0;

	if (alloc_chrdev_region(&devno_base, 0, MAX_CEC_CNT, "cec") != 0)
		return -EFAULT;

	for (i = 0; i < MAX_CEC_CNT; i++) {
		cdev_init(&node_list[i].cdev, &cec_dev_fops);
		node_list[i].device = NULL;
	}

	cec_dev_class = class_create(THIS_MODULE, "cec-dev");	/* create a new class i2c-dev */

	if (IS_ERR(cec_dev_class)) {
		result = PTR_ERR(cec_dev_class);
		goto err_create_class_failed;
	}
	cec_dev_class->devnode = cec_devnode;
	return 0;

err_create_class_failed:
	unregister_chrdev_region(devno_base, MAX_CEC_CNT);
	return result;
}

/*------------------------------------------------------------------
 * Func : cec_dev_module_exit
 *
 * Desc : cec dev module exit function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static void __exit cec_dev_module_exit(void)
{
	int i = 0;

	for (i = 0; i < MAX_CEC_CNT; i++) {
		if (node_list[i].device) {
			remove_cec_dev_node((cec_device *)
					    dev_get_drvdata(node_list
							    [i].device));
		}
	}

	unregister_chrdev_region(devno_base, MAX_CEC_CNT);
	class_destroy(cec_dev_class);
}

module_init(cec_dev_module_init);
module_exit(cec_dev_module_exit);
