/*
 * i2c-algo-rtk.c: i2c driver algorithms for Realtek rtk DVR
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License version 2 as published by the Free Software Foundation.
 *
 * Copyright (C) 2005 Chih-pin Wu <wucp@realtek.com.tw>
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/errno.h>
#include <linux/i2c-dev.h>
#include <linux/proc_fs.h>
#include <linux/i2c-algo-rtk.h>


/*------------------------------------------------------------------
 * Func : rtk_xfer
 * Desc :
 * Parm : adapter : i2c adapter
 * Retn :
 *------------------------------------------------------------------*/
static int rtk_xfer(struct i2c_adapter *i2c_adap, struct i2c_msg *msgs, int num)
{
	i2c_rtk_algo* p_alog = (i2c_rtk_algo*) i2c_adap->algo_data;
	return p_alog->masterXfer(p_alog->dev_id, msgs, num);
}


/*------------------------------------------------------------------
 * Func : rtk_func
 * Desc :
 * Parm : adapter : i2c adapter
 * Retn :
 *------------------------------------------------------------------*/
static u32 rtk_func(struct i2c_adapter *adap)
{
	return I2C_FUNC_SMBUS_EMUL;
}


static struct i2c_algorithm rtk_algo = {
	.master_xfer		= rtk_xfer,
	.functionality		= rtk_func,
};



/*------------------------------------------------------------------
 * Func : i2c_rtk_add_bus
 * Desc : add an rtk i2c adapter onto i2c bus
 * Parm : adapter : i2c adapter
 * Retn :
 *------------------------------------------------------------------*/
int i2c_rtk_add_bus(struct i2c_adapter *adap)
{
	adap->algo = &rtk_algo;
	return i2c_add_adapter(adap);
}



/*------------------------------------------------------------------
 * Func : i2c_rtk_add_bus
 * Desc : delete an rtk i2c adapter from i2c bus
 * Parm : adapter : i2c adapter
 * Retn :
 *------------------------------------------------------------------*/
int i2c_rtk_del_bus(struct i2c_adapter *adap)
{
	i2c_del_adapter(adap);
	return 0;
}


EXPORT_SYMBOL(i2c_rtk_add_bus);
EXPORT_SYMBOL(i2c_rtk_del_bus);

MODULE_AUTHOR("Kevin Wang <kevin_wang@realtek.com>");
MODULE_DESCRIPTION("I2C-Bus rtk algorithm");
MODULE_LICENSE("GPL");
