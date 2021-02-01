/*Copyright (C) 2007-2013 Realtek Semiconductor Corporation.*/
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include "rtk_diseqc.h"

#ifdef CONFIG_RTK_KDRV_DISEQC_CHARDEV
#include "rtk_diseqc_dev.h"
#endif

/*------------------------------------------------------------------
 * Func : diseqc_bus_match
 *
 * Desc : diseqc dev exit function
 *
 * Parm : dev    : device
 *        driver : driver
 *
 * Retn : 1 : device & driver matched, 0 : device & driver not matched
 *------------------------------------------------------------------*/
int diseqc_bus_match(struct device *dev, struct device_driver *drv)
{
	/*diseqc bus have no idea to match device & driver, return 1 to pass all*/
	return 1;
}

/* cyhuang (2011/11/24) +++ */
#ifdef CONFIG_PM
/*------------------------------------------------------------------
 * Func : diseqc_bus_pm_suspend_noirq
 *
 * Desc : suspend diseqc dev
 *
 * Parm : dev    : device to be suspend
 *
 * Retn : 0
 *------------------------------------------------------------------*/
static int diseqc_bus_pm_suspend_noirq(struct device *dev)
{
	diseqc_device *p_dev = to_diseqc_device(dev);
	diseqc_driver *p_drv = to_diseqc_driver(dev->driver);
	return (p_drv->suspend) ? p_drv->suspend(p_dev) : 0;
}

/*------------------------------------------------------------------
 * Func : diseqc_bus_pm_resume_noirq
 *
 * Desc : resume diseqc bus
 *
 * Parm : dev    : device to be resumed
 *
 * Retn : 0
 *------------------------------------------------------------------*/
static int diseqc_bus_pm_resume_noirq(struct device *dev)
{
	diseqc_device *p_dev = to_diseqc_device(dev);
	diseqc_driver *p_drv = to_diseqc_driver(dev->driver);
	return (p_drv->resume) ? p_drv->resume(p_dev) : 0;
}

static const struct dev_pm_ops diseqc_bus_pm_ops = {
	.suspend_noirq = diseqc_bus_pm_suspend_noirq,
	.resume_noirq = diseqc_bus_pm_resume_noirq,
#ifdef CONFIG_HIBERNATION
	.freeze_noirq = diseqc_bus_pm_suspend_noirq,
	.thaw_noirq = diseqc_bus_pm_resume_noirq,
	.poweroff_noirq = diseqc_bus_pm_suspend_noirq,
	.restore_noirq = diseqc_bus_pm_resume_noirq,
#endif
};

#endif /* CONFIG_PM */


struct bus_type diseqc_bus_type = {
	.name = "diseqc",
	.match = diseqc_bus_match,

#ifdef CONFIG_PM
	.pm = &diseqc_bus_pm_ops,
#endif

};

/*------------------------------------------------------------------
 * Func : register_diseqc_device
 *
 * Desc : register diseqc device
 *
 * Parm : device    : diseqc device to be registered
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void diseqc_device_release(struct device *dev)
{
	diseqc_device *p_dev = to_diseqc_device(dev);

	diseqc_warn("diseqc dev %s released\n", p_dev->name);
}

/*////////////////////////////////////////////////////////////////////////////
//                                                                          //
//                            diseqc_device                                    //
//                                                                          //
////////////////////////////////////////////////////////////////////////////*/

static int diseqc_device_count;

/*------------------------------------------------------------------
 * Func : register_diseqc_device
 *
 * Desc : register diseqc device
 *
 * Parm : device    : diseqc device to be registered
 *
 * Retn : 0
 *------------------------------------------------------------------*/
int register_diseqc_device(diseqc_device *device)
{
	struct device *dev = &device->dev;

	diseqc_warn("register diseqc device '%s' (%p) to diseqc%d\n", device->name, dev,
	       diseqc_device_count);

	dev_set_name(dev, "diseqc%d", diseqc_device_count++);

	dev->bus = &diseqc_bus_type;

	dev->release = diseqc_device_release;

	return device_register(dev);
}

/*------------------------------------------------------------------
 * Func : unregister_diseqc_device
 *
 * Desc : unregister diseqc device
 *
 * Parm : device : diseqc device to be unregistered
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void unregister_diseqc_device(diseqc_device *device)
{
	device_unregister(&device->dev);
}

/*////////////////////////////////////////////////////////////////////////////
//                                                                          //
//                            diseqc_driver                                    //
//                                                                          //
////////////////////////////////////////////////////////////////////////////*/

/*------------------------------------------------------------------
 * Func : diseqc_drv_probe
 *
 * Desc : probe diseqc device
 *
 * Parm : dev : diseqc device to be probed
 *
 * Retn : 0 : if supportted, others : failed
 *------------------------------------------------------------------*/
int diseqc_drv_probe(struct device *dev)
{
	diseqc_device *p_dev = to_diseqc_device(dev);
	diseqc_driver *p_drv = to_diseqc_driver(dev->driver);
	diseqc_warn("probe : diseqc_dev '%s' (%p), diseqc_drv '%s' (%p)\n", p_dev->name,
	       dev, p_drv->name, dev->driver);

	if (!p_drv->probe)
		return -ENODEV;

	if (p_drv->probe(p_dev) == 0) {
#ifdef CONFIG_RTK_KDRV_diseqc_CHARDEV
		create_diseqc_dev_node(p_dev);
#endif
		return 0;
	}

	return -ENODEV;
}

/*------------------------------------------------------------------
 * Func : diseqc_drv_remove
 *
 * Desc : this function was used to inform that a diseqc device has been
 *        removed
 *
 * Parm : dev : diseqc device to be removed
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int diseqc_drv_remove(struct device *dev)
{
	diseqc_device *p_dev = to_diseqc_device(dev);
	diseqc_driver *p_drv = to_diseqc_driver(dev->driver);

	diseqc_warn("remove diseqc_dev '%s'\n", p_dev->name);

	if (p_drv->remove)
		p_drv->remove(p_dev);

#ifdef CONFIG_RTK_KDRV_diseqc_CHARDEV
	remove_diseqc_dev_node(p_dev);
#endif

	return 0;
}

/*------------------------------------------------------------------
 * Func : diseqc_drv_shutdown
 *
 * Desc : this function was used to short down a diseqc device
 *
 * Parm : dev : diseqc device to be shut down
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
void diseqc_drv_shutdown(struct device *dev)
{
	diseqc_device *p_dev = to_diseqc_device(dev);
	diseqc_driver *p_drv = to_diseqc_driver(dev->driver);

	diseqc_warn("shutdown diseqc_dev '%s'\n", p_dev->name);

	if (p_drv->enable)
		p_drv->enable(p_dev, 0);
}

/*------------------------------------------------------------------
 * Func : diseqc_drv_suspend
 *
 * Desc : this function was used to suspend a diseqc device
 *
 * Parm : dev : diseqc device to be suspend
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int diseqc_drv_suspend(struct device *dev, pm_message_t state)
{
	diseqc_device *p_dev = to_diseqc_device(dev);
	diseqc_driver *p_drv = to_diseqc_driver(dev->driver);

	diseqc_warn("suspend diseqc_dev '%s'\n", p_dev->name);
	return (p_drv->suspend) ? p_drv->suspend(p_dev) : 0;
}

/*------------------------------------------------------------------
 * Func : diseqc_drv_resume
 *
 * Desc : this function was used to resume a diseqc device
 *
 * Parm : dev : diseqc device to be suspend
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int diseqc_drv_resume(struct device *dev)
{
	diseqc_device *p_dev = to_diseqc_device(dev);
	diseqc_driver *p_drv = to_diseqc_driver(dev->driver);

	diseqc_warn("resume diseqc_dev '%s'\n", p_dev->name);

	return (p_drv->resume) ? p_drv->resume(p_dev) : 0;
}

/*------------------------------------------------------------------
 * Func : register_diseqc_driver
 *
 * Desc : register diseqc device driver
 *
 * Parm : driver    : diseqc device driver to be registered
 *
 * Retn : 0
 *------------------------------------------------------------------*/
int register_diseqc_driver(diseqc_driver *driver)
{
	struct device_driver *drv = &driver->drv;

	drv->name = driver->name;
	drv->bus = &diseqc_bus_type;
	drv->probe = diseqc_drv_probe;
	drv->remove = diseqc_drv_remove;
	drv->shutdown = diseqc_drv_shutdown;
	drv->suspend = diseqc_drv_suspend;
	drv->resume = diseqc_drv_resume;

	diseqc_warn("register diseqc driver '%s' (%p)\n", drv->name, drv);

	return driver_register(drv);
}

/*------------------------------------------------------------------
 * Func : unregister_diseqc_driver
 *
 * Desc : unregister diseqc driver
 *
 * Parm : driver : diseqc driver to be unregistered
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void unregister_diseqc_driver(diseqc_driver *driver)
{
	struct device_driver *drv = &driver->drv;
	diseqc_warn("unregister diseqc driver '%s' (%p)\n", drv->name, &driver->drv);
	driver_unregister(&driver->drv);
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
static int __init diseqc_core_init(void)
{
	diseqc_warn("%s, register diseqc_bus %p\n", __FUNCTION__, &diseqc_bus_type);

	return bus_register(&diseqc_bus_type);	/* register diseqc bus type */
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
static void __exit diseqc_core_exit(void)
{
	bus_unregister(&diseqc_bus_type);	/* unregister diseqc bus */
}

module_init(diseqc_core_init);
module_exit(diseqc_core_exit);

EXPORT_SYMBOL(register_diseqc_device);
EXPORT_SYMBOL(unregister_diseqc_device);
EXPORT_SYMBOL(register_diseqc_driver);
EXPORT_SYMBOL(unregister_diseqc_driver);
