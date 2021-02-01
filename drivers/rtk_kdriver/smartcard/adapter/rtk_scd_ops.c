/* ------------------------------------------------------------------------
   scd_rtd299x.c  scd driver for Realtek Neptune/rtd299x
   -------------------------------------------------------------------------
    Copyright (C) 2008 Kevin Wang <kevin_wang@realtek.com.tw>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
----------------------------------------------------------------------------
Update List :
----------------------------------------------------------------------------
    1.0     |   20090312    |   Kevin Wang  | 1) create phase
----------------------------------------------------------------------------*/
#include <linux/kernel.h>
#include <linux/ioport.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/jiffies.h>
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <asm/io.h>

#ifdef CONFIG_CUSTOMER_TV006
#include <rtk_kdriver/rtk_lg_board.h>
#endif

#include "rtk_scd_debug.h"
#include "rtk_scd_priv.h"



MODULE_LICENSE("GPL");

/*------------------------------------------------------------------
 * Func : ops_probe
 *
 * Desc : probe a scd device
 *
 * Parm : dev
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
static
int ops_probe(scd_device *dev)
{
	scd *p_scd;

	if ((dev->id & 0xFFFFFFFC) != 0x12830000)
		return -ENODEV;

	p_scd = scd_open((dev->id & 0x3));

	if (p_scd == NULL)
		return -ENOMEM;

	scd_set_drvdata(dev, p_scd);	/*attach it to the scd_device*/
	return 0;
}

/*------------------------------------------------------------------
 * Func : ops_remove
 *
 * Desc : this function will be invoked when a smart card device which
 *        associated with this driver has been removed
 *
 * Parm : dev : smart card device to be removed
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
static
void ops_remove(scd_device *dev)
{
	scd_close((scd *) scd_get_drvdata(dev));
}

/*------------------------------------------------------------------
 * Func : ops_enable
 *
 * Desc : enable IFD
 *
 * Parm : dev    : ifd device
 *        on_off : 0      : disable IFD
 *        others : enable IFD
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
static
int ops_enable(scd_device *dev, unsigned char on_off)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	return scd_enable(p_this, on_off);
}

/*------------------------------------------------------------------
 * Func : ops_suspend
 *
 * Desc : suspend IFD
 *
 * Parm : dev    : ifd device
 *------------------------------------------------------------------*/
static
int ops_suspend(scd_device *dev)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	return scd_suspend(p_this);
}

/*------------------------------------------------------------------
 * Func : ops_resume
 *
 * Desc : suspend IFD
 *
 * Parm : dev    : ifd device
 *------------------------------------------------------------------*/
static
int ops_resume(scd_device *dev)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	return scd_resume(p_this);
}

/*------------------------------------------------------------------
 * Func : ops_set_param
 *
 * Desc : set param of IFD
 *
 * Parm : dev
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
static
int ops_set_param(scd_device *dev, unsigned long id, unsigned long val)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	int ret = SC_SUCCESS;

	switch (id) {
	case SC_PARAM_VCC_LVL:
		ret = scd_set_vcc_lvl(p_this, (SC_VCC_LVL) val);
		break;

	case SC_PARAM_CLOCK:
		ret = scd_set_clock(p_this, (unsigned long)val);
		break;

	case SC_PARAM_ETU:
		ret = scd_set_etu(p_this, (unsigned long)val);
		break;

	case SC_PARAM_CONV:
		ret = scd_set_convention(p_this, (SC_CONV) val);
		break;

	case SC_PARAM_PARITY:
		ret = scd_set_parity(p_this, (unsigned char)val);
		break;

	case SC_PARAM_GUARD_INTERVAL:
		ret = scd_set_guard_interval(p_this, val);
		break;

	default:
		ret = SC_FAIL;
	}

	return ret;
}

/*------------------------------------------------------------------
 * Func : ops_get_param
 *
 * Desc : get param of IFD
 *
 * Parm : dev
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
static
int ops_get_param(scd_device *dev, unsigned long id, unsigned long *p_val)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	int ret = SC_SUCCESS;

	switch (id) {
	case SC_PARAM_VCC_LVL:
		ret = scd_get_vcc_lvl(p_this, (SC_VCC_LVL *) p_val);
		break;

	case SC_PARAM_CLOCK:
		ret = scd_get_clock(p_this, p_val);
		break;

	case SC_PARAM_ETU:
		ret = scd_get_etu(p_this, p_val);
		break;

	case SC_PARAM_CONV:
		ret = scd_get_convention(p_this, (SC_CONV *) p_val);
		break;

	case SC_PARAM_PARITY:
		ret = scd_get_parity(p_this, (SC_PARITY *) p_val);
		break;

	case SC_PARAM_GUARD_INTERVAL:
		ret = scd_get_guard_interval(p_this, p_val);
		break;

	default:
		ret = SC_FAIL;
	}

	return ret;
}

/*------------------------------------------------------------------
 * Func : ops_activate
 *
 * Desc : activate ICC via reset procedure
 *
 * Parm : dev
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
static
int ops_activate(scd_device *dev)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	return scd_activate(p_this);
}

/*------------------------------------------------------------------
 * Func : ops_deactivate
 *
 * Desc : deactivate icc
 *
 * Parm : dev
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
static
int ops_deactivate(scd_device *dev)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	return scd_deactivate(p_this);
}

/*------------------------------------------------------------------
 * Func : ops_reset
 *
 * Desc : reset a scd device
 *
 * Parm : dev
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
static
int ops_reset(scd_device *dev)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	return scd_reset(p_this);
}

/*------------------------------------------------------------------
 * Func : ops_get_atr
 *
 * Desc : get atr from a scd device
 *
 * Parm : dev
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
static
int ops_get_atr(scd_device *dev, scd_atr *p_atr)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	return scd_get_atr(p_this, p_atr);
}

/*------------------------------------------------------------------
 * Func : ops_get_card_status
 *
 * Desc : get card status of IFD
 *
 * Parm : dev
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
static
int ops_get_card_status(scd_device *dev)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	return scd_get_card_status(p_this);
}

/*------------------------------------------------------------------
 * Func : ops_poll_card_status
 *
 * Desc : poll card status
 *
 * Parm : dev  :
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
static
int ops_poll_card_status(scd_device *dev)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	return scd_poll_card_status(p_this);
}

/*------------------------------------------------------------------
 * Func : ops_xmit
 *
 * Desc : xmit data via smart card bus
 *
 * Parm : dev  :
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
static
int ops_xmit(scd_device *dev, unsigned char *p_data, unsigned int len)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	return scd_xmit(p_this, p_data, len);
}

/*------------------------------------------------------------------
 * Func : ops_read
 *
 * Desc : read data via smart card bus
 *
 * Parm : dev  :
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
static
int ops_read(scd_device *dev, unsigned char *p_data, unsigned int len,
	     unsigned long timeout)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	return scd_read(p_this, p_data, len, timeout);
}

/*------------------------------------------------------------------
 * Func : ops_read
 *
 * Desc : read data via smart card bus
 *
 * Parm : dev  :
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
static
int ops_abort(scd_device *dev)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
	return scd_abort(p_this);
}

static scd_device scd_controller[2] = {
	{
	 .id = ID_SCD(0),
	 .name = "realtek_scd_0"},
#if 0
	{
	 .id = ID_MARS_SCD(1),
	 .name = "realtek_scd_1"},
#endif
};

static
int  ops_interface_value(scd_device *dev,unsigned long long *interface_value)
{
	scd *p_this = (scd *) scd_get_drvdata(dev);
      *interface_value=scd_interface_value(p_this);
	return 0;
}


static scd_driver realtek_scd_driver = {
	.name = "realtek_scd",
	.probe = ops_probe,
	.remove = ops_remove,
	.suspend = ops_suspend,
	.resume = ops_resume,
	.enable = ops_enable,
	.set_param = ops_set_param,
	.get_param = ops_get_param,
	.activate = ops_activate,
	.deactivate = ops_deactivate,
	.reset = ops_reset,
	.get_atr = ops_get_atr,
	.get_card_status = ops_get_card_status,
	.poll_card_status = ops_poll_card_status,
	.xmit = ops_xmit,
	.read = ops_read,
	.abort = ops_abort,
	.get_interface_value=ops_interface_value,
};

/*------------------------------------------------------------------
 * Func : scd_module_init
 *
 * Desc : init smart card interface driver
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int __init scd_module_init(void)
{
	SC_INFO("realtek scd module init\n");

       create_smc_controller();

#ifdef CONFIG_CUSTOMER_TV006

	SC_WARNING( "%s isPcbWithSmc = %d \n" , __func__ , isPcbWithSmc()   );
	if( 0 == isPcbWithSmc() ){
		SC_WARNING("this pcb is not japan type , smart card is not needed \n");
		SC_WARNING("this pcb is not japan type , smart card is not needed \n");
		SC_WARNING("this pcb is not japan type , smart card is not needed \n");
		SC_WARNING("this pcb is not japan type , smart card is not needed \n");
		SC_WARNING("this pcb is not japan type , smart card is not needed \n");
		return -EFAULT;
	}
#endif

	if (register_scd_driver(&realtek_scd_driver) != 0)
		return -EFAULT;

	register_scd_device(&scd_controller[0]);	/* register scd device*/
#if 0
	register_scd_device(&scd_controller[1]);	/*register scd device*/
#endif
	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_module_exit
 *
 * Desc : uninit smart card interface driver
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static void __exit scd_module_exit(void)
{
	unregister_scd_device(&scd_controller[0]);
#if 0
	unregister_scd_device(&scd_controller[1]);
#endif
	unregister_scd_driver(&realtek_scd_driver);
}

module_init(scd_module_init);
module_exit(scd_module_exit);
