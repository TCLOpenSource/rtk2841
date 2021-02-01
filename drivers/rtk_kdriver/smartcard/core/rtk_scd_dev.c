#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include "rtk_scd.h"
#include "rtk_scd_dev.h"

#define MAX_SCD_CNT     2
static scd_dev node_list[MAX_SCD_CNT];
static dev_t devno_base;
static struct class *scd_dev_class;

/*------------------------------------------------------------------
 * Func : create_scd_dev_node
 *
 * Desc : create a scd device node
 *
 * Parm : device : handle of scd device
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int create_scd_dev_node(scd_device *device)
{
	int i;

	for (i = 0; i < MAX_SCD_CNT; i++) {
		if (node_list[i].device == NULL) {
			if (cdev_add(&node_list[i].cdev, devno_base + i, 1) < 0) {
				SC_ERR
				    ("scd warning : register character dev failed\n");
				return -1;
			}

			node_list[i].device = device_create(scd_dev_class,	/* class */
							    NULL,	/* parent */
							    devno_base + i,	/* dev number */
							    device,	/*driver data */
							    "scd-%d",	/* device name */
							    i);	/*device id; */

			return 0;
		}
	}

	return -1;
}

/*------------------------------------------------------------------
 * Func : remove_scd_dev_node
 *
 * Desc : remove a scd device node
 *
 * Parm : device : scd device to be unregistered
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
void remove_scd_dev_node(scd_device *device)
{
	int i = 0;

	for (i = 0; i < MAX_SCD_CNT; i++) {
		if (node_list[i].device
		    && dev_get_drvdata(node_list[i].device) == (void *)device) {
			device_destroy(scd_dev_class, devno_base + i);	/* remove device */
			cdev_del(&node_list[i].cdev);
			node_list[i].device = NULL;
			return;
		}
	}
}

/*------------------------------------------------------------------
 * Func : scd_dev_open
 *
 * Desc : open function of scd dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int scd_dev_open(struct inode *inode, struct file *file)
{
	unsigned int i = iminor(inode);
	scd_device *dev = NULL;

	if (i>=MAX_SCD_CNT||!node_list[i].device)
		return -ENODEV;

	dev = (scd_device *) dev_get_drvdata(node_list[i].device);

	if (dev) {
		scd_driver *drv = (scd_driver *) to_scd_driver(dev->dev.driver);
		file->private_data = dev;
		drv->enable(dev, 1);
		return 0;
	}

	return -ENODEV;
}

/*------------------------------------------------------------------
 * Func : scd_dev_release
 *
 * Desc : release function of scd dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int scd_dev_release(struct inode *inode, struct file *file)
{
	scd_device *dev = (scd_device *) file->private_data;

	if (dev) {
		scd_driver *drv = (scd_driver *) to_scd_driver(dev->dev.driver);
		drv->enable(dev, 0);
	}

	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_dev_read
 *
 * Desc : read function of scd dev
 *
 * Parm : file  : context of file
 *        buff  : rx buffer addr
 *        size  : rx buffer size
 *        ofst  : read offset
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
ssize_t scd_dev_read(struct file *file,
		     char __user *buff, size_t size, loff_t *ofst)
{
	scd_device *dev = (scd_device *) file->private_data;
	scd_driver *drv = (scd_driver *) to_scd_driver(dev->dev.driver);
	unsigned char tmp[512];
	int ret;

	if (size > sizeof(tmp))
		size = sizeof(tmp);

	ret = drv->read(dev, tmp, size, 100);	/*maximum wait 100 ms */

	if (ret > 0) {
		if (copy_to_user((unsigned char __user *)buff, tmp, ret) < 0) {
			SC_ERR
			    ("read message failed, copy to user failed\n");
			return -EFAULT;
		}
	}

	return ret;
}

/*------------------------------------------------------------------
 * Func : scd_dev_write
 *
 * Desc : write function of scd dev
 *
 * Parm : file  : context of file
 *        buff  : tx buffer addr
 *        size  : tx buffer size
 *        ofst  : write offset
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
ssize_t scd_dev_write(struct file *file,
		      const char __user *buff, size_t size, loff_t *ofst)
{
	scd_device *dev = (scd_device *) file->private_data;
	scd_driver *drv = (scd_driver *) to_scd_driver(dev->dev.driver);
	unsigned char tmp[512];

	if (copy_from_user(tmp, (unsigned char __user *)buff, size)) {
		SC_ERR("write message failed, copy data from user space failed\n");
		return -EFAULT;
	}

	return drv->xmit(dev, tmp, size);
}

/*------------------------------------------------------------------
 * Func : scd_dev_exchange_data
 *
 * Desc : exchange data between smartcard and ifd
 *
 * Parm : file  : context of file, smartcard transcation
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/

static
int scd_dev_exchange_data(struct file *file, sc_transcation *p_trans)
{
	scd_device *dev = (scd_device *) file->private_data;
	scd_driver *drv = (scd_driver *) to_scd_driver(dev->dev.driver);
	unsigned long expire_time;
	int rx_len = 0;

	if (p_trans == NULL) {
		SC_ERR("exchange data failed, null p_trans\n");
		return -EFAULT;
	}

	SC_DBG("scd_dev_exchange_data : tx_len=%d, rx_len=%d, timeout=%d\n",
	       p_trans->tx_len, p_trans->rx_len, p_trans->timeout);

	expire_time = jiffies + msecs_to_jiffies(p_trans->timeout);

	if (p_trans->tx_data && p_trans->tx_len) {
		int ret = scd_dev_write(file, p_trans->tx_data, p_trans->tx_len, 0);	/* where this write is a blocking call */
		if (ret < 0)
			return ret;
	}

	if (p_trans->rx_buff && p_trans->rx_len) {
		unsigned char tmp[512];
		int len = p_trans->rx_len;

		while (len) {
			int ret;

			ret =
			    drv->read(dev, tmp,
				      (len > sizeof(tmp)) ? sizeof(tmp) : len,
				      time_before(jiffies,
						  expire_time) ? expire_time -
				      jiffies : 0);

			if (ret < 0)
				return ret;	/* error */

			if (ret > 0) {
				if (copy_to_user
				    ((unsigned char __user *)
				     &p_trans->rx_buff[rx_len], tmp, ret) < 0) {
					SC_ERR
					    ("read message failed, copy to user failed\n");
					return -EFAULT;
				}

				rx_len += ret;
				len -= ret;
			}

			if (time_after(jiffies, expire_time))
				break;
		}
	}

	return rx_len;
}

#ifdef CONFIG_COMPAT

/*------------------------------------------------------------------
 * Func : compat_scd_dev_exchange_data
 *
 * Desc : exchange data between smartcard and ifd
 *
 * Parm : file  : context of file, smartcard transcation
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/

static
int compat_scd_dev_exchange_data(struct file *file, compat_sc_transcation *p_trans)
{
	scd_device *dev = (scd_device *) file->private_data;
	scd_driver *drv = (scd_driver *) to_scd_driver(dev->dev.driver);
	unsigned long expire_time;
	int rx_len = 0;

	if (p_trans == NULL) {
		SC_ERR("exchange data failed, null p_trans\n");
		return -EFAULT;
	}

	SC_DBG("scd_dev_exchange_data : tx_len=%d, rx_len=%d, timeout=%d\n",
	       p_trans->tx_len, p_trans->rx_len, p_trans->timeout);

	expire_time = jiffies + msecs_to_jiffies(p_trans->timeout);

	if (compat_ptr(p_trans->tx_data) && p_trans->tx_len) {
		int ret = scd_dev_write(file, compat_ptr(p_trans->tx_data) , p_trans->tx_len, 0);	/* where this write is a blocking call */
		if (ret < 0)
			return ret;
	}

	if (compat_ptr(p_trans->rx_buff) && p_trans->rx_len) {
		unsigned char tmp[512];
		int len = p_trans->rx_len;

		while (len) {
			int ret;

			ret =
			    drv->read(dev, tmp,
				      (len > sizeof(tmp)) ? sizeof(tmp) : len,
				      time_before(jiffies,
						  expire_time) ? expire_time -
				      jiffies : 0);

			if (ret < 0)
				return ret;	/* error */

			if (ret > 0) {
				if (copy_to_user
				    ((unsigned char __user *)
				     &compat_ptr(p_trans->rx_buff)[rx_len], tmp, ret) < 0) {
					SC_ERR
					    ("read message failed, copy to user failed\n");
					return -EFAULT;
				}

				rx_len += ret;
				len -= ret;
			}

			if (time_after(jiffies, expire_time))
				break;
		}
	}

	return rx_len;
}


#endif

/*------------------------------------------------------------------
 * Func : scd_dev_abort_exchange_data
 *
 * Desc : terminate all pended IO requests
 *
 * Parm : file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int scd_dev_abort_exchange_data(struct file *file)
{
	scd_device *dev = (scd_device *) file->private_data;
	scd_driver *drv = (scd_driver *) to_scd_driver(dev->dev.driver);

	if (drv->abort)
		drv->abort(dev);

	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_dev_ioctl
 *
 * Desc : ioctl function of scd dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
long scd_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	scd_device *dev = (scd_device *) file->private_data;
	scd_driver *drv;
	scd_atr atr;
	scd_atr *p_atr;
	sc_msg_buff buff;
	sc_transcation trans;
	int i;
	scd_param param;
	scd_ifd_param ifd_param;
	int ret;
       unsigned long long interface_value;
	if (!dev)
		return -ENODEV;

	drv = (scd_driver *) to_scd_driver(dev->dev.driver);

	switch (cmd) {
	case SCD_SETPARAM:

		if (copy_from_user
		    (&ifd_param, (scd_ifd_param __user *) arg,
		     sizeof(ifd_param)))
			return -EFAULT;

		ret = drv->set_param(dev, SC_PARAM_CLOCK, ifd_param.clk);
		ret |= drv->set_param(dev, SC_PARAM_ETU, ifd_param.etu);
		return ret;

	case SCD_GETPARAM:

		if (drv->get_param(dev, SC_PARAM_CLOCK, &ifd_param.clk) < 0)
			return -EFAULT;

		if (drv->get_param(dev, SC_PARAM_ETU, &ifd_param.etu) < 0)
			return -EFAULT;

		return copy_to_user((scd_ifd_param __user *) arg, &ifd_param,
				    sizeof(ifd_param));

	case SCD_SETPARAM_EX:

		if (copy_from_user
		    (&param, (scd_param __user *) arg, sizeof(param)))
			return -EFAULT;

		return drv->set_param(dev, param.id, param.val);

	case SCD_GETPARAM_EX:

		if (copy_from_user
		    (&param, (scd_param __user *) arg, sizeof(param)))
			return -EFAULT;

		if (drv->get_param(dev, param.id, &param.val) < 0)
			return -EFAULT;

		return copy_to_user((scd_param __user *) arg, &param,
				    sizeof(param));

	case SCD_ACTIVE:
		return drv->activate(dev);
	case SCD_DEACTIVE:
		return drv->deactivate(dev);
	case SCD_RESET:
		return drv->reset(dev);
	case SCD_GET_CARD_STATUS:
		return drv->get_card_status(dev);
	case SCD_POLL_CARD_STATUS_CHANGE:
		return drv->poll_card_status(dev);
	case SCD_GET_ATR:

		if (drv->get_atr(dev, &atr))
			return -1;

		p_atr = (scd_atr *) arg;

		put_user(atr.length, &p_atr->length);

		for (i = 0; i < atr.length; i++)
			put_user(atr.data[i], &p_atr->data[i]);

		return 0;

	case SCD_READ:

		if (copy_from_user
		    (&buff, (sc_msg_buff __user *) arg, sizeof(sc_msg_buff)))
			return -EFAULT;

		return scd_dev_read(file, buff.p_data, buff.length, 0);

	case SCD_WRITE:

		if (copy_from_user
		    (&buff, (sc_msg_buff __user *) arg, sizeof(sc_msg_buff)))
			return -EFAULT;

		return scd_dev_write(file, buff.p_data, buff.length, 0);

	case SCD_DATA_EXCHANGE:

		if (copy_from_user
		    (&trans, (sc_transcation __user *) arg,
		     sizeof(sc_transcation)))
			return -EFAULT;

		return scd_dev_exchange_data(file, &trans);

	case SCD_ABORT_DATA_EXCHANGE:

		return scd_dev_abort_exchange_data(file);
		
	case SCD_GETINTERFACE_VAL:
	
             drv->get_interface_value(dev,&interface_value);
	      return copy_to_user(( unsigned long long __user *) arg, &interface_value,
			    sizeof(unsigned long long));

	default:
		return -EFAULT;
	}

	return 0;
}

#ifdef CONFIG_COMPAT

/*------------------------------------------------------------------
 * Func : compat_scd_dev_ioctl
 *
 * Desc : ioctl function of scd dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
long compat_scd_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	scd_device *dev = (scd_device *) file->private_data;
	scd_driver *drv;
	scd_atr atr;
	scd_atr *p_atr;
	compat_sc_msg_buff buff;
	compat_sc_transcation trans;
	int i;
	compat_scd_param param;
	compat_scd_ifd_param ifd_param;
	int ret;

	if (!dev)
		return -ENODEV;

	drv = (scd_driver *) to_scd_driver(dev->dev.driver);

	switch (cmd) {
	case COMPAT_SCD_SETPARAM:
		if (copy_from_user
		    (&ifd_param, (compat_scd_ifd_param __user *) arg,
		     sizeof(ifd_param)))
			return -EFAULT;

		ret = drv->set_param(dev, SC_PARAM_CLOCK, ifd_param.clk);
		ret |= drv->set_param(dev, SC_PARAM_ETU, ifd_param.etu);
		return ret;

	case COMPAT_SCD_GETPARAM:

		if (drv->get_param(dev, SC_PARAM_CLOCK, &ifd_param.clk) < 0)
			return -EFAULT;

		if (drv->get_param(dev, SC_PARAM_ETU, &ifd_param.etu) < 0)
			return -EFAULT;

		return copy_to_user((compat_scd_ifd_param __user *) arg, &ifd_param,
				    sizeof(ifd_param));

	case COMPAT_SCD_SETPARAM_EX:

		if (copy_from_user
		    (&param, (compat_scd_param __user *) arg, sizeof(param)))
			return -EFAULT;

		return drv->set_param(dev, param.id, param.val);

	case COMPAT_SCD_GETPARAM_EX:

		if (copy_from_user
		    (&param, (compat_scd_param __user *) arg, sizeof(param)))
			return -EFAULT;

		if (drv->get_param(dev, param.id, &param.val) < 0)
			return -EFAULT;

		return copy_to_user((compat_scd_param __user *) arg, &param,
				    sizeof(param));

	case COMPAT_SCD_ACTIVE:
		return drv->activate(dev);
	case COMPAT_SCD_DEACTIVE:
		return drv->deactivate(dev);
	case COMPAT_SCD_RESET:
		return drv->reset(dev);
	case COMPAT_SCD_GET_CARD_STATUS:
		return drv->get_card_status(dev);
	case COMPAT_SCD_POLL_CARD_STATUS_CHANGE:
		return drv->poll_card_status(dev);
	case COMPAT_SCD_GET_ATR:

		if (drv->get_atr(dev, &atr))
			return -1;

		p_atr = (scd_atr *) arg;

		put_user(atr.length, &p_atr->length);

		for (i = 0; i < atr.length; i++)
			put_user(atr.data[i], &p_atr->data[i]);

		return 0;

	case COMPAT_SCD_READ:

		if (copy_from_user
		    (&buff, (compat_sc_msg_buff __user *) arg, sizeof(compat_sc_msg_buff)))
			return -EFAULT;

		return scd_dev_read(file, compat_ptr(buff.p_data), buff.length, 0);

	case COMPAT_SCD_WRITE:

		if (copy_from_user
		    (&buff, (compat_sc_msg_buff __user *) arg, sizeof(compat_sc_msg_buff)))
			return -EFAULT;

		return scd_dev_write(file, compat_ptr(buff.p_data), buff.length, 0);

	case COMPAT_SCD_DATA_EXCHANGE:

		if (copy_from_user
		    (&trans, (compat_sc_transcation __user *) arg,
		     sizeof(compat_sc_transcation)))
			return -EFAULT;

		return compat_scd_dev_exchange_data(file, &trans);

	case COMPAT_SCD_ABORT_DATA_EXCHANGE:

		return scd_dev_abort_exchange_data(file);

	case SCD_KER_PRINT:
	{
		unsigned char logBuf[256];
		logBuf[255] = 0;
		if (copy_from_user((void *)logBuf, (const void __user *)arg, 255)) {
			ret = -EFAULT;
			SC_WARNING("ioctl SDC_KER_PRINT failed !!!!!!!!!!!!!!!\n");
		}
		else {
			SC_PRINTK("%s", logBuf);
			ret = 0;
		}
		break;
	}
	default:
		return -EFAULT;
	}

	return 0;
}

#endif

static struct file_operations scd_dev_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = scd_dev_ioctl,
	.open = scd_dev_open,
	.read = scd_dev_read,
	.write = scd_dev_write,
	.release = scd_dev_release,
#ifdef CONFIG_COMPAT
	.compat_ioctl = compat_scd_dev_ioctl,
#endif
};

/*------------------------------------------------------------------
 * Func : scd_dev_module_init
 *
 * Desc : scd dev init function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int __init scd_dev_module_init(void)
{
	int i;

	if (alloc_chrdev_region(&devno_base, 0, MAX_SCD_CNT, "smartcard") != 0)
		return -EFAULT;

	scd_dev_class = class_create(THIS_MODULE, "scd-dev");

	for (i = 0; i < MAX_SCD_CNT; i++) {
		cdev_init(&node_list[i].cdev, &scd_dev_fops);
		node_list[i].device = NULL;
	}

	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_dev_module_exit
 *
 * Desc : scd dev module exit function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
void __exit scd_dev_module_exit(void)
{
	int i = 0;

	for (i = 0; i < MAX_SCD_CNT; i++) {
		if (node_list[i].device)
			remove_scd_dev_node((scd_device *)
					    dev_get_drvdata(node_list
							    [i].device));
	}

	unregister_chrdev_region(devno_base, MAX_SCD_CNT);

	class_destroy(scd_dev_class);
}
