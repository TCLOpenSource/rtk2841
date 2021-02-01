#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/kfifo.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <asm/uaccess.h>
#include <linux/platform_device.h>
#include "rtk_ice.h"
#include "rtk_ice-aux.h"
 static struct kfifo rx_fifo;
extern int rtice_port;

/*-----------------------------------------------------------------------
 * File Operations
 *----------------------------------------------------------------------*/
int rtice_dev_open(struct inode *inode, struct file *file)
{
	return 0;
}

int rtice_dev_release(struct inode *inode, struct file *file)
{
	return 0;
}

ssize_t rtice_dev_read(struct file * file, char __user * data, size_t len,
			  loff_t * ofst)
{
	int out_len = 0;
	int ret = kfifo_to_user(&rx_fifo, data, len, &out_len);
	return (ret == 0) ? out_len : ret;
}

ssize_t rtice_dev_write(struct file * file, const char __user * data,
			   size_t len, loff_t * ofst)
{
	unsigned char buff[256];
	if (len > sizeof(buff))
		return -1;
	if (copy_from_user(buff, data, len))
		return -1;
	kfifo_reset(&rx_fifo);
	rtice_input(buff, len);
	return 0;
}

static struct file_operations rtice_dev_fops = \
{ 
	.owner = THIS_MODULE, 
	.read = rtice_dev_read, 
	.write = rtice_dev_write, 
	.open = rtice_dev_open, 
	.release = rtice_dev_release,
};

ssize_t rtice_show_param(struct device *dev,struct device_attribute*attr,\
								char *buf)
{
	printk("[RTICE-%s]\n", __func__);
	if (strncmp(attr->attr.name, "rtice_uartnumber", 16) == 0)
		sprintf(buf, "%d\n", rtice_port);
	return 1;
}

ssize_t rtice_set_param(struct device * dev, struct device_attribute * attr,\
			    const char *buf, size_t count)
{
	int iPortNumber = 0;
	if (strncmp(attr->attr.name, "rtice_uartnumber", 16) == 0) {
		if (sscanf(buf, "%d\n", &iPortNumber) == 1) {
			if (iPortNumber >= 0 && iPortNumber <= 3) {
				printk("[RTICE-%s]Chang Rtice port to %d\n",\
					__func__, iPortNumber);
				rtice_port = iPortNumber;
			}
		}
	}
	
	return 1;
}

DEVICE_ATTR(rtice_uartnumber, S_IWUSR | S_IWGRP | S_IRUSR | S_IRGRP, rtice_show_param,
		rtice_set_param);
static struct miscdevice rtice_dev_miscdev = \
{ 
	MISC_DYNAMIC_MINOR, 
	"rtice", 
	&rtice_dev_fops
};

int __init rtice_dev_module_init(void)
{
	int ret = 0;
	if (kfifo_alloc(&rx_fifo, 1024, GFP_KERNEL) < 0)
		return -ENOMEM;
	if (misc_register(&rtice_dev_miscdev)){
		printk("rtice_dev_module_init failed\n");
		ret = -ENODEV;
	}
	device_create_file(rtice_dev_miscdev.this_device,\
					&dev_attr_rtice_uartnumber);
	return ret;
}

static void __exit rtice_dev_module_exit(void)
{
	misc_deregister(&rtice_dev_miscdev);
} 

module_init(rtice_dev_module_init);
module_exit(rtice_dev_module_exit);
MODULE_AUTHOR("Kevin Wang, Realtek Semiconductor");
MODULE_LICENSE("GPL");
