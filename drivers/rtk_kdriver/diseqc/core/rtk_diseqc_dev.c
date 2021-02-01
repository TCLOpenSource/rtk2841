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

#include <rtk_kdriver/rtk_diseqc.h>
#include "rtk_diseqc.h"
#include "rtk_diseqc_dev.h"

#define MAX_DISEQC_CNT             1
static diseqc_dev node_list[MAX_DISEQC_CNT];
static dev_t devno_base;
static struct class *diseqc_dev_class;
Diseqc_Func diseqc_ops;
/*------------------------------------------------------------------
 * Func : create_diseqc_dev_node
 *
 * Desc : create a diseqc device node
 *
 * Parm : device : handle of diseqc device
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int create_diseqc_dev_node(diseqc_device *device)
{
	int i;
	for (i = 0; i < MAX_DISEQC_CNT; i++) {
		if (node_list[i].device == NULL) {
		    /*register character device node to system*/
			if (cdev_add(&node_list[i].cdev, devno_base + i, 1) < 0) {
				diseqc_warn
				    (" register character dev failed\n");
				return -1;
			}

			node_list[i].device = device_create(diseqc_dev_class,	/* class */
							    NULL,	/* parent */
							    devno_base + i,	/* dev number */
							    device,	/* driver data */
							    "diseqc-%d",	/* device name */
							    i);	/* device id */

			return 0;
		}
	}

	return -1;
}

/*------------------------------------------------------------------
 * Func : remove_diseqc_dev_node
 *
 * Desc : remove a diseqc device node
 *
 * Parm : device : diseqc device to be unregistered
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
void remove_diseqc_dev_node(diseqc_device *device)
{
	int i = 0;

	for (i = 0; i < MAX_DISEQC_CNT; i++) {
		if (node_list[i].device
		    && dev_get_drvdata(node_list[i].device) == (void *)device) {
			device_destroy(diseqc_dev_class, devno_base + i);	/* remove device */
			cdev_del(&node_list[i].cdev);
			node_list[i].device = NULL;
			return;
		}
	}
}

/*------------------------------------------------------------------
 * Func : diseqc_dev_open
 *
 * Desc : open function of diseqc dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int diseqc_dev_open(struct inode *inode, struct file *file)
{
	unsigned int i = iminor(inode);
	diseqc_device *dev;

	if (!node_list[i].device)
		return -ENODEV;

	dev = (diseqc_device *) dev_get_drvdata(node_list[i].device);

	if (dev) {
		/*cec_driver* drv = (cec_driver*) to_cec_driver(dev->dev.driver);*/
		file->private_data = dev;
		return 0;
	}

	return -ENODEV;
}

/*------------------------------------------------------------------
 * Func : diseqc_dev_release
 *
 * Desc : release function of diseqc dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int diseqc_dev_release(struct inode *inode, struct file *file)
{
	unsigned int i = iminor(inode);
	diseqc_device *dev;
	diseqc_driver *drv;

	if (node_list[i].device) {
		dev = (diseqc_device *) dev_get_drvdata(node_list[i].device);
		drv = (diseqc_driver *) to_diseqc_driver(dev->dev.driver);
		drv->enable(dev, 0xf0);
	}

	return 0;
}

/*------------------------------------------------------------------
 * Func : diseqc_dev_ioctl
 *
 * Desc : ioctl function of diseqc dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
long diseqc_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{

	diseqc_device *dev = (diseqc_device *) file->private_data;
	diseqc_driver *drv = (diseqc_driver *) to_diseqc_driver(dev->dev.driver);
	diseqc_msg msg;
	diseqc_data_buff *ddb = NULL;

	int err = 0;
	int len = 0;
	int retval = 0;
	unsigned short rx_mask;
	unsigned int result;

	if (!dev)
		return -ENODEV;

	if ((_IOC_TYPE(cmd) != DISEQC_IOC_MAGIC) ||
		(_IOC_NR(cmd) > DISEQC_IOC_MAXNR))
		return -ENOTTY;

	 if (_IOC_DIR(cmd) & _IOC_READ)
		 err =	!access_ok(VERIFY_WRITE, (void __user *)arg,
				_IOC_SIZE(cmd));
	else if (_IOC_DIR(cmd) & _IOC_WRITE)
		err =	!access_ok(VERIFY_READ, (void __user *)arg,
				_IOC_SIZE(cmd));

	if (err)
		return -EFAULT;

	if (!capable(CAP_SYS_ADMIN)) 
		return -EPERM;

	switch (cmd) {
	case DISEQC_IOCR_22K_SET:
	{
		int on_off = DISEQC_OFF;
		if(copy_from_user((void *)&on_off, (const void __user *)arg, sizeof(int)))
		{
			diseqc_err("%s copy_from_user 22K continuous failed\n", __func__);
			retval = -EFAULT;
		}
		else
		{
			if(drv->set_22k_on_off(on_off) < 0)
			{
				 diseqc_err("%s set 22K continuous failed\n", __func__);
                 retval = -EFAULT;
			}
		}
		break;
	}
	case DISEQC_IOCR_CMD_SET:
	{
		if(copy_from_user((void *)&msg, (const void __user *)arg, sizeof(diseqc_msg)))
		{
			diseqc_err("%s copy_from_user command failed\n", __func__);
			retval = -EFAULT;
		}
		else
		{
			if(drv->set_diseqc_cmd(msg.len , msg.buf) < 0)
			{
				 diseqc_err("%s set diseqc command failed\n", __func__);
	             retval = -EFAULT;
			}
		}
		break;
	}
	case DISEQC_IOCR_MOD_TONE_BURST_SET:
	{
		if(drv->set_mod_tone_burst() < 0)
		{
			diseqc_err("%s set diseqc mode tone burst failed\n", __func__);
            retval = -EFAULT;
		}

		break;
	}
	case DISEQC_IOCR_UNMOD_TONE_BURST_SET:
	{
		if(drv->set_unmod_tone_burst() < 0)
		{
			diseqc_err("%s set diseqc unmode tone burst failed\n", __func__);
			retval = -EFAULT;
		}
		break;
	}
	case DISEQC_IOCR_TONE_BURST_SET: 
	{
		int tone_mode = TONE_MODE_A;
		if(copy_from_user((void *)&tone_mode, (const void __user *)arg, sizeof(int)))
		{
			diseqc_err("%s copy_from_user tone mode failed\n", __func__);
			retval = -EFAULT;
		}
		else
		{
			if(drv->set_tone_burst(tone_mode) < 0)
			{
				diseqc_err("%s set diseqc tone burst failed\n", __func__);
	            retval = -EFAULT;
			}
		}
		break;
	}
	default:
		diseqc_warn(" unknown ioctl cmd %08x\n", cmd);
		retval =  -EFAULT;
		break;
	}
	return retval;
}

#ifdef CONFIG_COMPAT

/*------------------------------------------------------------------
 * Func : compat_diseqc_dev_ioctl
 *
 * Desc : ioctl function of diseqc dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
long compat_diseqc_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{

	diseqc_device *dev = (diseqc_device *) file->private_data;
	diseqc_driver *drv = (diseqc_driver *) to_diseqc_driver(dev->dev.driver);
	diseqc_msg msg;
	diseqc_data_buff *ddb = NULL;

	int err = 0;
	int len = 0;
	int retval = 0;
	unsigned short rx_mask;
	unsigned int result;

	if (!dev)
		return -ENODEV;

	if ((_IOC_TYPE(cmd) != DISEQC_IOC_MAGIC) ||
		(_IOC_NR(cmd) > DISEQC_IOC_MAXNR))
		return -ENOTTY;

	 if (_IOC_DIR(cmd) & _IOC_READ)
		 err =	!access_ok(VERIFY_WRITE, (void __user *)arg,
				_IOC_SIZE(cmd));
	else if (_IOC_DIR(cmd) & _IOC_WRITE)
		err =	!access_ok(VERIFY_READ, (void __user *)arg,
				_IOC_SIZE(cmd));

	if (err)
		return -EFAULT;

	if (!capable(CAP_SYS_ADMIN)) 
		return -EPERM;

	switch (cmd) {
	case DISEQC_IOCR_22K_SET:
	{
		int on_off = DISEQC_OFF;
		if(copy_from_user((void *)&on_off, (const void __user *)arg, sizeof(int)))
		{
			diseqc_err("%s copy_from_user 22K continuous failed\n", __func__);
			retval = -EFAULT;
		}
		else
		{
			if(drv->set_22k_on_off(on_off) < 0)
			{
				 diseqc_err("%s set 22K continuous failed\n", __func__);
                 retval = -EFAULT;
			}
		}
		break;
	}
	case DISEQC_IOCR_CMD_SET:
	{
		if(copy_from_user((void *)&msg, (const void __user *)arg, sizeof(diseqc_msg)))
		{
			diseqc_err("%s copy_from_user command failed\n", __func__);
			retval = -EFAULT;
		}
		else
		{
			if(drv->set_diseqc_cmd(msg.len , msg.buf) < 0)
			{
				 diseqc_err("%s set diseqc command failed\n", __func__);
	             retval = -EFAULT;
			}
		}
		break;
	}
	case DISEQC_IOCR_MOD_TONE_BURST_SET:
	{
		if(drv->set_mod_tone_burst() < 0)
		{
			diseqc_err("%s set diseqc mode tone burst failed\n", __func__);
            retval = -EFAULT;
		}

		break;
	}
	case DISEQC_IOCR_UNMOD_TONE_BURST_SET:
	{
		if(drv->set_unmod_tone_burst() < 0)
		{
			diseqc_err("%s set diseqc unmode tone burst failed\n", __func__);
			retval = -EFAULT;
		}
		break;
	}
	case DISEQC_IOCR_TONE_BURST_SET: 
	{
		int tone_mode = TONE_MODE_A;
		if(copy_from_user((void *)&tone_mode, (const void __user *)arg, sizeof(int)))
		{
			diseqc_err("%s copy_from_user tone mode failed\n", __func__);
			retval = -EFAULT;
		}
		else
		{
			if(drv->set_tone_burst(tone_mode) < 0)
			{
				diseqc_err("%s set diseqc tone burst failed\n", __func__);
	            retval = -EFAULT;
			}
		}
		break;
	}
	default:
		diseqc_warn(" unknown ioctl cmd %08x\n", cmd);
		retval =  -EFAULT;
		break;
	}
	return retval;
}

#endif

static struct file_operations diseqc_dev_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = diseqc_dev_ioctl,
	#ifdef CONFIG_COMPAT
	.compat_ioctl = compat_diseqc_dev_ioctl,
	#endif
	.open = diseqc_dev_open,
	.release = diseqc_dev_release,
};

int parser_cmd(const char *buf, int len,unsigned char *data)
{
	char* const delim = " ";
	char *token, *cur;
	cur = buf;
	int i = 0;
	while (token = strsep(&cur, delim)) {
		if(i >= 3)
		{
			 data[i-3] = (unsigned char)simple_strtol( token,NULL,16);
		}	
		i++;
	}
	if(i-3 == len)
		return SUCCESS;
	else
		return FAIL;
}

void SetEnvelopMode(int en)
{
    if(en == DISEQC_PULSE_MODE){
        DISEQC_INFO("Set Diseqc Pulse mode\n");
		RTK_SetEnvelopMode(en);
    } 
    else if(en == DISEQC_ENVELOP_MODE){
        DISEQC_INFO("Set Diseqc Envelop mode\n");
		RTK_SetEnvelopMode(en);
    }
	else{
        DISEQC_ERROR("Set Diseqc Envelop mode failed\n");
    }
}

void SetContinue22k(int on_off)
{
	if(on_off == DISEQC_OFF){
		DISEQC_INFO("Set Diseqc OFF\n");
		DISEQC_INFO("Execute RTK_SetContinue22kOnOff\n");
		RTK_SetContinue22kOnOff(on_off);
	}
	else if(on_off == DISEQC_ON){
		DISEQC_INFO("Set Diseqc ON\n");
		DISEQC_INFO("Execute RTK_SetContinue22kOnOff\n");
		RTK_SetContinue22kOnOff(on_off);
	}
	else{
		DISEQC_ERROR("Set Diseqc Continue 22K ON/OFF param failed\n");
	}
}

void SetToneBurst(int tone_mode)
{
	if(tone_mode == TONE_MODE_A){
		DISEQC_INFO("Set Diseqc Tone Mode A\n");
		DISEQC_INFO("Execute RTK_SetToneBurst\n");
		RTK_SetToneBurst(tone_mode);
	}
	else if(tone_mode == TONE_MODE_B){
		DISEQC_INFO("Set Diseqc Tone Mode B\n");
		DISEQC_INFO("Execute RTK_SetToneBurst\n");
		RTK_SetToneBurst(tone_mode);
	}
	else{
		DISEQC_ERROR("Set Diseqc Tone Burst param failed\n");
	}
}


ssize_t rtk_diseqc_show_param(struct device *dev,
                            struct device_attribute *attr, char *buf)
{
	int ret = 0;
	return ret;
}

ssize_t rtk_diseqc_store_param(struct device *dev,
                           struct device_attribute *attr,
                           const char *buf, size_t count)
{
	int ret = FAIL;
	int ops_mode;
	int tone_mode;
	int on_off;
	int Env_en;
	int len;
	char cmd1[6];
	char cmd2[3];
	unsigned char data[4] = {0};
	sscanf(buf, "%6s%3s\n", &cmd1, &cmd2);
	if (strcmp(cmd1, "22k") == 0) {
		if (strcmp(cmd2, "get") == 0) {
			DISEQC_INFO("RTK_SetContinue22kOnOff()=>0:DISEQC_OFF 1:DISEQC_ON\n");
			ret = SUCCESS;
		}
		else if(strcmp(cmd2, "set") == 0) {
			sscanf(buf, "%6s%3s%d\n", &cmd1, &cmd2, &on_off);
			SetContinue22k(on_off);
			ret = SUCCESS;
		}
	}
	else if(strcmp(cmd1, "cmd") == 0) {
		if (strcmp(cmd2, "get") == 0) {
			DISEQC_INFO("RTK_SetDiseqcCmd()=> DataLength Data\n");	
			ret = SUCCESS;
		}
		else if (strcmp(cmd2, "set") == 0) {
			DISEQC_INFO("Execute RTK_SetDiseqcCmd()\n");
			sscanf(buf, "%6s%3s%d\n", &cmd1, &cmd2, &len);
			if(parser_cmd(buf,len,data) == SUCCESS)	{
				DISEQC_INFO("buf:%s\n",buf);
				RTK_SetDiseqcCmd(len,data);
				ret = SUCCESS;
			}
			else{
				DISEQC_ERROR("Set Diseqc Command param format invalid\n");
			}	
		}
	}
	else if (strcmp(cmd1, "unmod") == 0) {
		if (strcmp(cmd2, "get") == 0) {
			DISEQC_INFO("RTK_SetUnModToneBurst()=>No Input Parameter\n");	
			ret = SUCCESS;	
		}
		else if(strcmp(cmd2, "set") == 0) {
			DISEQC_INFO("Execute RTK_SetUnModToneBurst\n");
			RTK_SetUnModToneBurst();
			ret = SUCCESS;
		}
	}
	else if (strcmp(cmd1, "mod") == 0) {
		if (strcmp(cmd2, "get") == 0) {
			DISEQC_INFO("RTK_SetModToneBurst()=>No Input Parameter\n");
			ret = SUCCESS;
		}
		else if(strcmp(cmd2, "set") == 0) {
			DISEQC_INFO("Execute RTK_SetModToneBurst\n");
			RTK_SetModToneBurst();
			ret = SUCCESS;
		}
	}
	else if(strcmp(cmd1,"env") == 0) {
		if (strcmp(cmd2, "get") == 0){
			ret = SUCCESS;
		}
		else if(strcmp(cmd2,"set") == 0) {
			sscanf(buf, "%6s%3s%d\n", &cmd1, &cmd2, &Env_en);
			RTK_SetEnvelopMode(Env_en);
			ret = SUCCESS;
		}
	}
	else if (strcmp(cmd1, "all") == 0) {
		if (strcmp(cmd2, "get") == 0) {
			DISEQC_INFO("RTK_SetToneBurst()=>0:TONE_MODE_A 1:TONE_MODE_B\n");
			ret = SUCCESS;
		}
		else if(strcmp(cmd2, "set") == 0) {
			sscanf(buf, "%6s%3s%d\n", &cmd1, &cmd2,&tone_mode);
			SetToneBurst(tone_mode);
			ret = SUCCESS;
		}
	}

	if(ret == FAIL)
	{
		DISEQC_ERROR("Diseqc Command Format Failed\n");
	}	
	
	return count;
}

DEVICE_ATTR(diseqc_func, S_IWUSR | S_IWGRP | S_IRUGO, rtk_diseqc_show_param,
		            rtk_diseqc_store_param);

static int register_diseqc_cdev(Diseqc_Func *ops)
{
	dev_t dev;
	int ret;
	ret = alloc_chrdev_region(&dev, 0, 1, "diseqc");
	if (ret) {
		DISEQC_ERROR("can't alloc chrdev\n");
		return ret;
	}

	ops->diseqc_dev_major = MAJOR(dev);
	ops->diseqc_dev_minor = MINOR(dev);

	ops->device_this = device_create(diseqc_dev_class, NULL, MKDEV(ops->diseqc_dev_major, ops->diseqc_dev_minor), NULL, "rtk_diseqc");
	ret = device_create_file(ops->device_this,&dev_attr_diseqc_func);

	DISEQC_INFO("register chrdev(%d,%d) success.\n", ops->diseqc_dev_major, ops->diseqc_dev_minor);
	return 0;
}

/*------------------------------------------------------------------
 * Func : diseqc_dev_module_init
 *
 * Desc : diseqc dev init function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int __init diseqc_dev_module_init(void)
{
	int i;
	unsigned int result = 0;

	if (alloc_chrdev_region(&devno_base, 0, MAX_DISEQC_CNT, "diseqc") != 0)
		return -EFAULT;

	for (i = 0; i < MAX_DISEQC_CNT ; i++) {
		cdev_init(&node_list[i].cdev, &diseqc_dev_fops);
		node_list[i].device = NULL;
	}

	diseqc_dev_class = class_create(THIS_MODULE, "diseqc-dev");	/* create a new class i2c-dev */

	if (IS_ERR(diseqc_dev_class)) {
		result = PTR_ERR(diseqc_dev_class);
		goto err_create_class_failed;
	}

    register_diseqc_cdev(&diseqc_ops);
	return 0;

err_create_class_failed:
	unregister_chrdev_region(devno_base, MAX_DISEQC_CNT);
	return result;
}

/*------------------------------------------------------------------
 * Func : diseqc_dev_module_exit
 *
 * Desc : diseqc dev module exit function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static void __exit diseqc_dev_module_exit(void)
{
	int i = 0;

	for (i = 0; i < MAX_DISEQC_CNT; i++) {
		if (node_list[i].device) {
			remove_diseqc_dev_node((diseqc_device *)
					    dev_get_drvdata(node_list
							    [i].device));
		}
	}

	unregister_chrdev_region(devno_base, MAX_DISEQC_CNT);
	class_destroy(diseqc_dev_class);
}

module_init(diseqc_dev_module_init);
module_exit(diseqc_dev_module_exit);
