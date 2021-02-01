#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

#include <linux/kernel.h>	/* DBG_PRINT() */
#include <linux/slab.h>	/* kmalloc() */
#include <linux/fs.h>	/* everything... */
#include <linux/errno.h>	/* error codes */
#include <linux/types.h>	/* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>	/* O_ACCMODE */
#include <linux/seq_file.h>
#include <linux/cdev.h>

//#include <asm/system.h>	/* cli(), *_flags */
#include <asm/uaccess.h>	/* copy_*_user */
#include <asm/io.h>
#include <linux/sched.h>

#include <asm/irq.h>
#include <linux/signal.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#include <mach/platform.h>
#include <linux/platform_device.h>
#include <mach/system.h>
#include <linux/delay.h>

#include "rtk_ice_ap_driver.h"
#include "../core/rtk_ice-debug.h"
#include "../core/rtk_ice-aux.h"
#include "../core/rtk_ice.h"

MODULE_AUTHOR("Kevin_Wang");
MODULE_LICENSE("Dual BSD/GPL");

#define RTICE2AP_DEBUG

#ifdef  RTICE2AP_DEBUG
/*#define DBG_PRINT(s, args...) printk(s, ## args)*/
#define DBG_PRINT(s, args...)  RTICE_DEBUG(s, ## args)
#else
#define DBG_PRINT(s, args...)
#endif

#define DRV_NAME		"rtice2ap"

static const char  drv_name [] = DRV_NAME;

int rtice_major   = RTICE_MAJOR;
int rtice_minor   = 0 ;
int rtice_nr_devs = RTICE_NR_DEVS;

module_param(rtice_major, int, S_IRUGO);
module_param(rtice_minor, int, S_IRUGO);
module_param(rtice_nr_devs, int, S_IRUGO);

static struct class *rtice_class;


//For Linux 3.7
#ifndef VM_RESERVED
#define  VM_RESERVED   (VM_DONTEXPAND | VM_DONTDUMP)
#endif

ap_data *kern_ap = NULL;
ap_param *kern_param = NULL;

struct cdev rtice_cdev;

static DECLARE_WAIT_QUEUE_HEAD (ap_wait);
enum RTICE_AP_STATUS ap_status = NO_CMD;

int rtice_open(struct inode *inode, struct file *filp)
{
	DBG_PRINT("platform device rtice2ap opened!\n");
	return 0;
}

int rtice_release(struct inode *inode, struct file *filp)
{
	DBG_PRINT("platform device rtice2ap released!\n");
	return 0;
}


char wakeup_ap(unsigned int timeoutMs)
{
	while((ap_status != NO_CMD) && timeoutMs--){
		msleep(1);
	}
	if(ap_status == NO_CMD){
		ap_status = RTICE_REC_CMD;
		wake_up(&ap_wait);
		return TRUE;
	}
	return FALSE;
}

ssize_t rtice_read(struct file *filp, char __user *buf, size_t count,\
			loff_t *f_pos)
{
	ap_status = NO_CMD;
	if(wait_event_interruptible(ap_wait,(ap_status == RTICE_REC_CMD)) !=0){
		DBG_PRINT("read:wait event interrupted!\n");
		return -1;
	}
	if(rtice_read_status == DEV_READ_CMD){
		if(count != sizeof(ap_data)){
			DBG_PRINT(\
		"[rtice2ap]read cmd error:correct num:%d error num:%d\n",\
							sizeof(ap_data),count);
			goto read_error;
		}
		if(copy_to_user(buf,(void *)kern_ap,sizeof(ap_data))){
			DBG_PRINT("read:copy to user error!\n");
			goto read_error;
		}
	}else if(rtice_read_status == DEV_READ_CMD_EX){
		if(count != sizeof(ap_param)){
			DBG_PRINT(\
		"[rtice2ap]ex-read cmd error:correct num:%d  error num:%d\n",\
							sizeof(ap_param),count);
			goto read_error;
		}
		if(copy_to_user(buf,(void *)kern_param,sizeof(ap_param))){
			DBG_PRINT("ex-read:copy to user error!\n");
			goto read_error;
		}
	}else if(rtice_read_status == DEV_READ_DATA){
		if(count != rtice_data_size){
			DBG_PRINT(\
		"[rtice2ap]read data error:correct num:%d  error num:%d\n",\
							sizeof(ap_data),count);
			goto read_error;
		}
		if(!rtice_ap_buffer || \
			copy_to_user(buf,(void *)rtice_ap_buffer,count)){
			DBG_PRINT("read:copy to user error!\n");
			goto read_error;
		}
	}else{
		goto read_error;
	}
	rtice_read_status = DEV_READ_SUCCEED;
	return count;
read_error:
	rtice_read_status = DEV_READ_ERROR;
	return -1;
}

ssize_t rtice_write(struct file *filp, const char __user *buf,\
			size_t count, loff_t *f_pos)
{
	unsigned char buffer[sizeof(ap_param)];
/*	int i = 0;*/
	unsigned int timeoutMs = 10;/*10ms*/

	if(count == sizeof(ap_data) || count == sizeof(ap_param) ){
		/*return read data or param*/
		if(copy_from_user(buffer,buf,count)){
			DBG_PRINT("[rtice2ap]write:copy from user error!\n");
			goto write_error;
		}
		if(count == sizeof(ap_data)  && \
			memcmp((char *)buffer,\
				(char *)kern_ap,sizeof(ap_data)-1) == 0){
			/*return ap_data*/
			memcpy((char *)kern_ap,(char *)buffer,sizeof(ap_data));
		}else if(count == sizeof(ap_param) && \
			memcmp((char *)buffer,\
				(char *)kern_param,sizeof(ap_param)-1) == 0){
			/*return ap_param*/
			memcpy((char *)kern_param,\
				(char *)buffer,sizeof(ap_param));
		}else if(rtice_data_size == count && rtice_ap_buffer){
			/*return data*/
			memcpy((char *)rtice_ap_buffer,(char *)buffer,count);
		}else{
			goto write_error;
		}
	}else if(count == rtice_data_size){/*read data*/
		if(!rtice_ap_buffer || \
			copy_from_user((void *)rtice_ap_buffer,buf,count)){
			DBG_PRINT("[rtice2ap]write:copy from user error!\n");
				goto write_error;
		}
	}else{/*read error*/
		DBG_PRINT("[rtice2ap]write:size is wrong!\n");
		goto write_error;
	}
	rtice_write_status = DEV_WRITE_SUCCEED;
	if(wakeup_kernel(timeoutMs) == FALSE){
		goto write_error;
	}
	return count;
write_error:
	rtice_write_status = DEV_WRITE_ERROR;
	wakeup_kernel(timeoutMs);
	return -1;
}

long rtice_ioctl(struct file *filp,unsigned int cmd, unsigned long arg)
{
	return 0;
}

loff_t rtice_llseek(struct file *filp, loff_t off, int whence)
{
	return -EINVAL ;
}

static struct platform_device *rtice_platform_devs;

static struct platform_driver rtice_device_driver = {
	.driver = {
		.name = (char *)drv_name,
		.bus = &platform_bus_type,
	},
};

struct file_operations rtice_fops = {
	.owner = THIS_MODULE,
	.llseek = rtice_llseek,
	.read = rtice_read,
	.write = rtice_write,
	.unlocked_ioctl = rtice_ioctl,
	.open = rtice_open,
	.release = rtice_release,
};

static char *rtice_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}

void rtice_cleanup_module(void)
{
	dev_t devno = MKDEV(rtice_major, rtice_minor);
	DBG_PRINT(KERN_INFO "rtice clean module rtice_major = %d\n", \
								rtice_major);
	device_destroy(rtice_class, MKDEV(rtice_major, 0));
	class_destroy(rtice_class);
	/* device driver removal */
	if(rtice_platform_devs) {
		platform_device_unregister(rtice_platform_devs);
	}
	if(kern_ap)
		kfree(kern_ap);
	if(kern_param)
		kfree(kern_param);
	platform_driver_unregister(&rtice_device_driver);
	/* cleanup_module is never called if registering failed */
	unregister_chrdev_region(devno, rtice_nr_devs);
}

int rtice_init_module(void)
{
	int result;
	int err;
	int devno;
	dev_t dev = 0;

	printk("\n\n\n\n**********rtice2ap init module*************\n\n\n\n");
	if(rtice_major){
		dev = MKDEV(rtice_major, rtice_minor);
		result = register_chrdev_region(dev,rtice_nr_devs,"rtice2ap");
	}else{
		result = alloc_chrdev_region(&dev, rtice_minor, \
						rtice_nr_devs,"rtice2ap");
		rtice_major = MAJOR(dev);
	}
	if(result < 0){
		DBG_PRINT(KERN_WARNING "rtice2ap: can't get major %d\n", \
								rtice_major);
		return result;
	}
	printk("rtice2ap init module major number = %d\n", rtice_major);
	rtice_class = class_create(THIS_MODULE, "rtice2ap");
	if (IS_ERR(rtice_class))
		return PTR_ERR(rtice_class);
	rtice_class->devnode = rtice_devnode;
	rtice_platform_devs = platform_device_register_simple("rtice2ap", \
								-1, NULL, 0);
	if((result = platform_driver_register(&rtice_device_driver)) != 0){
		platform_device_unregister(rtice_platform_devs);
		rtice_platform_devs = NULL;
		return result;
	}
	devno = MKDEV(rtice_major, rtice_minor);
	cdev_init(&rtice_cdev, &rtice_fops);
	rtice_cdev.owner = THIS_MODULE;
	rtice_cdev.ops = &rtice_fops;
	err = cdev_add (&rtice_cdev, devno, 1);
	if (err){
		DBG_PRINT(KERN_NOTICE "Error %d adding rtice2ap!\n", err);
	}
	device_create(rtice_class,NULL,MKDEV(rtice_major,0),NULL,"rtice2ap0");
	dev = MKDEV(rtice_major, rtice_minor + rtice_nr_devs);
	if((kern_ap = (ap_data *)kmalloc(sizeof(ap_data),GFP_KERNEL)) == NULL){
		DBG_PRINT("malloc ap_data fail!\n");
		return -1;
	}
	memset(kern_ap, 0, sizeof(ap_data));
	if((kern_param = (ap_param *)kmalloc(sizeof(ap_param),GFP_KERNEL)) == \
									NULL){
		DBG_PRINT("malloc kern_param fail!\n");
		return -1;
	}
	memset(kern_param, 0, sizeof(ap_param));

	return 0;
}

module_init(rtice_init_module);
module_exit(rtice_cleanup_module);
