#include <linux/kconfig.h>
#include <linux/compiler.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>		/* module */
#include <linux/stat.h>			/* permission */
#include <linux/fs.h>			/* fs */
#include <linux/errno.h>		/* error codes */
#include <linux/types.h>		/* size_t */
#include <linux/fcntl.h>		/* O_ACCMODE */
#include <asm/uaccess.h>		/* copy_*_user */
#include <asm/io.h>			/* io_* */
#include <linux/mutex.h>		/* mutex */
#include <linux/device.h>		/* device */
#include <linux/platform_device.h>	/* platform device */
#include <linux/cdev.h>			/* char device */
#include <linux/pm.h>			/* power management */

#include "audio_hw_port.h"
#include "audio_hw_atv.h"
#include "audio_hw_aio.h"
#include "audio_hw_app.h"
#include "audio_hw_pm.h"
#include "audio_hw_driver.h"
#include "audio_hw_ioctl.h"
#include "audio_hw_factory.h"

#define __ALOG_SUBTAG "driver"

static int audio_hw_open(struct inode *inode, struct file *filp);
static int audio_hw_release(struct inode *inode, struct file *filp);

struct audio_hw_drvdata *audio_driver_data = NULL;

static const char *audio_hw_cmd_str[] = {
	"dumpsif=",			/* AUDIOHW_DBG_CMD_DUMP_SIF */
	//"to be continued="
};

int audio_hw_open(struct inode *inode, struct file *filp)
{
	struct audio_hw_drvdata *drvdata;

	alog_info("open\n");

	drvdata = container_of(inode->i_cdev, struct audio_hw_drvdata, cdev);
	filp->private_data = drvdata;

	return 0;
}

int audio_hw_release(struct inode *inode, struct file *filp)
{
	alog_info("release\n");

	filp->private_data = NULL;

	return 0;
}

int audio_hw_dbg_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
	char str[AUDIO_HW_MAX_CMD_LENGTH] = {0};
	int cmd_index = 0;
	char *cmd_pointer = NULL;
 
	alog_info("dbg write\n"); 

	if (buf == NULL) {
		alog_err("dbg_write:%d buf=%p\n", __LINE__, buf);
		return -EFAULT;
	}
	if (count > AUDIO_HW_MAX_CMD_LENGTH - 1)
		count = AUDIO_HW_MAX_CMD_LENGTH - 1;

	if (copy_from_user(str, buf, AUDIO_HW_MAX_CMD_LENGTH - 1)) {
		alog_info("dbg_write:%d copy_from_user failed! (buf=%p, count=%u)\n",
			__LINE__, buf, count);
		return -EFAULT;
	}

	if (count > 0)
		str[count-1] = '\0';

	for (cmd_index = 0; cmd_index < AUDIO_HW_DBG_CMD_NUMBER; cmd_index++) {
		if (strncmp(str,
				audio_hw_cmd_str[cmd_index],
				strlen(audio_hw_cmd_str[cmd_index])) == 0)
			break;
	}
	alog_info("cmd_index = %d\n", cmd_index);
	if (cmd_index < AUDIO_HW_DBG_CMD_NUMBER) {
		cmd_pointer = &str[strlen(audio_hw_cmd_str[cmd_index])];
	}

	audio_hw_dbg_EXECUTE(cmd_index, &cmd_pointer);

	return count;
}

static struct file_operations audio_hw_fops = {
	.owner		= THIS_MODULE,
	.llseek		= no_llseek,
	.unlocked_ioctl = audio_hw_ioctl,
	.open		= audio_hw_open,
	.release	= audio_hw_release,
	.write		= audio_hw_dbg_write,
};

static char *audio_hw_devnode(struct device *dev, mode_t *mode)
{
	*mode = 0666;
	return NULL;
}

static int audio_hw_pdrv_probe(struct platform_device *pdev)
{
	int ret = 0;

	struct audio_hw_drvdata *drvdata = NULL;

	/*
	 * register character device with dynamic major and minor number.
	 *
	 * get a range of minor numbers to work with, asking for a dynamic
	 * major unless directed otherwise at load time.
	 */
	alog_info("platfom driver probe\n");

	/*
	 * allocate driver data
	 */
	drvdata = devm_kzalloc(&pdev->dev, sizeof(*drvdata), GFP_KERNEL);
	if (!drvdata) {
		alog_err("can't allocate drvdata\n");
		ret = -ENOMEM;
		goto exit_error;
	}

	drvdata->pm = audio_hw_pm_create(&pdev->dev);
	if (IS_ERR(drvdata->pm)) {
		alog_err("can't create pm\n");
		ret = PTR_ERR(drvdata->pm);
		goto exit_error;
	}

	mutex_init(&drvdata->mtx);

	/*
	 * allocate char device
	 */
	ret = alloc_chrdev_region(&drvdata->devt, 0, 1, AUDIO_DEVICE_NAME);
	if (ret < 0) {
		alog_err("can't allocate devt\n");
		goto exit_audio_hw_pm_destroy;
	}

	alog_info("device major %d minor %d\n", MAJOR(drvdata->devt),
		  MINOR(drvdata->devt));

	/*
	 * initialize char device
	 */
	cdev_init(&drvdata->cdev, &audio_hw_fops);
	drvdata->cdev.owner = THIS_MODULE;

	/* add char device */
	ret = cdev_add(&drvdata->cdev, drvdata->devt, 1);
	if (ret) {
		alog_err("can't add cdev: %d\n", ret);
		goto exit_unregister_chrdev_region;
	}

	/*
	 * create class
	 */
	drvdata->cls = class_create(THIS_MODULE, AUDIO_DEVICE_NAME);
	if (IS_ERR(drvdata->cls)) {
		ret = PTR_ERR(drvdata->cls);
		alog_err("can't create class: %d\n", ret);
		goto exit_cdev_del;
	}
	drvdata->cls->devnode = audio_hw_devnode;

	/*
	 * create sysfs node
	 */
	drvdata->clsdev = device_create(drvdata->cls, NULL, drvdata->devt,
					(void*)pdev, AUDIO_DEVICE_NAME);
	if (IS_ERR(drvdata->clsdev)) {
		ret = PTR_ERR(drvdata->clsdev);
		alog_err("can't create device: %d\n", ret);
		goto exit_class_destroy;
	}

	platform_set_drvdata(pdev, (void *)drvdata);

	audio_driver_data = drvdata;
		
	return 0; /* succeed */

exit_class_destroy:
	class_destroy(drvdata->cls);
	drvdata->cls = NULL;

exit_cdev_del:
	cdev_del(&drvdata->cdev);

exit_unregister_chrdev_region:
	unregister_chrdev_region(drvdata->devt, 1);
	drvdata->devt = 0;

exit_audio_hw_pm_destroy:
	audio_hw_pm_destroy(drvdata->pm);

exit_error:
	return ret;
}

static int __exit audio_hw_pdrv_remove(struct platform_device *pdev)
{
	struct audio_hw_drvdata *drvdata;

	drvdata = platform_get_drvdata(pdev);

	if (drvdata && drvdata->cls) {
		if (drvdata->clsdev) {
			device_destroy(drvdata->cls, drvdata->devt);
			drvdata->clsdev = NULL;
		}
		class_destroy(drvdata->cls);
	}

	platform_set_drvdata(pdev, NULL);
	return 0;
}

static int audio_hw_suspend(struct device *dev)
{
	struct audio_hw_drvdata *drvdata;

	alog_info("suspend\n");

	drvdata = dev_get_drvdata(dev);
	if (!drvdata) {
		alog_err("invalid drvdata\n");
		return -EINVAL;
	}

	return audio_hw_pm_suspend(drvdata->pm);
}

static int audio_hw_resume(struct device *dev)
{
	struct audio_hw_drvdata *drvdata;

	alog_info("resume\n");

	drvdata = dev_get_drvdata(dev);
	if (!drvdata) {
		alog_err("invalid drvdata\n");
		return -EINVAL;
	}

	return audio_hw_pm_resume(drvdata->pm);
}

static SIMPLE_DEV_PM_OPS(audio_hw_pm_ops, audio_hw_suspend, audio_hw_resume);

static struct platform_driver audio_hw_pdrv = {
	.probe	= audio_hw_pdrv_probe,
	.remove	= __exit_p(audio_hw_pdrv_remove),
	.driver = {
		.name	= AUDIO_DEVICE_NAME,
		.owner	= THIS_MODULE,
		.bus	= &platform_bus_type,
#if IS_ENABLED(CONFIG_PM_SLEEP)
		.pm	= &audio_hw_pm_ops,
#endif
	},
};

static struct platform_device *audio_hw_pdev = NULL;

static int __init audio_hw_init(void)
{
	int ret = 0;

	/*
	* allocate and register platform device
	*/
	audio_hw_pdev = platform_device_register_simple(
				AUDIO_DEVICE_NAME, PLATFORM_DEVID_NONE,
				NULL, 0);
	if (IS_ERR(audio_hw_pdev)) {
		ret = PTR_ERR(audio_hw_pdev);
		alog_err("can't register platform device %d\n", ret);
		goto exit_error;
	}

	/*
	 * register platform driver
	 */
	ret = platform_driver_register(&audio_hw_pdrv);
	if (ret) {
		alog_warning("can't register platform driver %d\n", ret);
		goto exit_unregister_platform_device;
	}

	return 0; /* succeed */

exit_unregister_platform_device:
	platform_device_unregister(audio_hw_pdev);

exit_error:
	return ret;
}

static void __exit audio_hw_cleanup(void)
{
	struct audio_hw_drvdata *drvdata;

	if (audio_hw_pdev) {
		drvdata = platform_get_drvdata(audio_hw_pdev);
		if (drvdata && drvdata->pm)
			audio_hw_pm_destroy(drvdata->pm);

		platform_device_unregister(audio_hw_pdev);
		audio_hw_pdev = NULL;
	}

	platform_driver_unregister(&audio_hw_pdrv);
}

module_init(audio_hw_init);
module_exit(audio_hw_cleanup);
