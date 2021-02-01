/* ------------------------------------------------------------------------- */
/* i2c-rtk.c i2c-hw access for Realtek rtk DVR I2C                       */
/* ------------------------------------------------------------------------- */
/*   Copyright (C) 2005 Chih-pin Wu <wucp@realtek.com.tw>

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
    Version 1.0 written by wucp@realtek.com.tw
    Version 2.0 modified by Frank Ting(frank.ting@realtek.com.tw)(2007/06/21)
-------------------------------------------------------------------------
    1.4     |   20081016    | Multiple I2C Support
-------------------------------------------------------------------------
    1.5     |   20090423    | Add Suspen/Resume Feature
-------------------------------------------------------------------------*/
#include <linux/kernel.h>
#include <linux/ioport.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/pci.h>
#include <linux/wait.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/list.h>
#include <asm/io.h>
#include <asm/irq.h>
#include <asm/delay.h>
#include "i2c-rtk-slave.h"
#include <linux/i2c-algo-rtk.h>
#include "i2c-rtk-priv.h"
#include "i2c-rtk.h"
#define I2C_PHY_CHANNEL_DEMOD_USE 0
#if defined(CONFIG_ARCH_RTK299O) || defined(CONFIG_ARCH_RTK293x)
#include <rbus/crt_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <rbus/sb2_reg.h>
#elif defined(CONFIG_ARCH_RTK289X)
#include <rbus/sys_reg_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <rbus/sb2_reg.h>
#else
	//#include <rbus/crt_reg.h>
	#ifdef CONFIG_RTK_KDRIVER_SUPPORT
	#include <rtk_kdriver/rtk_crt.h>
	#else
	#include <mach/rtk_crt.h>
	#endif
#endif


#ifdef CONFIG_RTK_KDRIVER_SUPPORT
#include <rtk_kdriver/rtk_crt.h>


#else
#include <rbus/stb_reg.h>
#include <mach/irqs.h>
#include <mach/rtk_crt.h>

#endif

#ifdef CONFIG_ARM64
extern u32 gic_irq_find_mapping(u32 hwirq);
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)	gic_irq_find_mapping(hwirq)
#else
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)	(hwirq)
#endif

static int m_I2CPowerCnt = 0 ;
static struct mutex m_I2CPower_mutex;


static void hw_i2c_semaphore_try_lock(rtk_i2c *p_this)
{
	#if defined(CONFIG_ARCH_RTK299O) || defined(CONFIG_ARCH_RTK289X)
	if(p_this->id == 2)
	{
		while (!*(unsigned int volatile *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_2_reg)) {
			I2C_INFO("#@# i2c wait SB2_HD_SEM_NEW_2_reg ready\n");
			msleep(20);
		}
	}
	#endif
}

static void hw_i2c_semaphore_unlock(rtk_i2c *p_this)
{
	#if defined(CONFIG_ARCH_RTK299O)||defined(CONFIG_ARCH_RTK289X)
	if(p_this->id == 2)
		*(unsigned int volatile *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_2_reg) = 0;
	#endif
}


void i2c_power(int state)
{
	int i2c_phy = 0xFFFFFFFF; //BIT(0)|BIT(1)|BIT(2)|BIT(3);
	if (state == 1) {
		I2C_WARNING("power on\n");
		CRT_CLK_OnOff(I2C, CLK_ON, &i2c_phy);
#if (defined(CONFIG_ARCH_RTK299O) || defined(CONFIG_ARCH_RTK293x))&&!defined(CONFIG_ARCH_RTK289X)
		rtd_setbits(0xb806022c,0x08000000);//I2C_ctrl_en
#elif defined(CONFIG_ARCH_RTK284X)
		rtd_setbits(0xb80008D8,0x00010000);//I2C_ctrl_en
#endif
	}else{
		I2C_WARNING("power off\n");
		CRT_CLK_OnOff(I2C, CLK_OFF, &i2c_phy);
	}


}

/*------------------------------------------------------------------
 * Func : i2c_rtk_xfer
 * Desc : start i2c xfer (read/write)
 * Parm : p_msg : i2c messages
 * Retn : 0 success, otherwise fail
 *------------------------------------------------------------------*/
void i2c_rtk_dump_msg(const struct i2c_msg *p_msg)
{
	I2C_WARNING("msg->addr  = %02x (shifted-%02x)\n", p_msg->addr, (p_msg->addr<<1));
	I2C_WARNING("msg->flags = %04x\n", p_msg->flags);
	I2C_WARNING("msg->len   = %d  \n", p_msg->len);
	I2C_WARNING("msg->buf   = %p  \n", p_msg->buf);
}

#define IsReadMsg(x)        (x.flags & I2C_M_RD)
#define IsGPIORW(x)         (x.flags & I2C_GPIO_RW)
#define IsSameTarget(x,y)   ((x.addr == y.addr) && !((x.flags ^ y.flags) & (~I2C_M_RD)))

/*------------------------------------------------------------------
 * Func : i2c_rtk_xfer
 *
 * Desc : start i2c xfer (read/write)
 *
 * Parm : adapter : i2c adapter
 *        msgs    : i2c messages
 *        num     : nessage counter
 *
 * Retn : 0 success, otherwise fail
 *------------------------------------------------------------------*/
static int i2c_rtk_xfer(void *dev_id, struct i2c_msg *msgs, int num)
{
	#define SET_INTERNAL_DEMOD_1200HZ 0
	rtk_i2c_adapter *p_adp = (rtk_i2c_adapter *) dev_id;
	rtk_i2c *p_this = (rtk_i2c *) p_adp->p_phy;
	int ret = 0;
	int i;
	unsigned char tempLevel=1;

	if(msgs == NULL)
		return -1;

	LockrtkI2CPhy(p_this);
	hw_i2c_semaphore_try_lock(p_this);
	//baker
	#if defined(CONFIG_ARCH_RTK299S)
	if(msgs[0].addr == 0x12)
	{
		rtd_clearbits(0xb80008BC, BIT(7));

	}
	else
	#endif
	{
		if((p_this->disable_switch_port ==0 ))
		{
			#if SET_INTERNAL_DEMOD_1200HZ
			if((msgs[0].addr != 0x12)||(p_this->id!=0))
			#endif
			{
				#if defined(CONFIG_ARCH_RTK299O)
					// this is just for 2990 phy3 src0 patch
					if((p_this->id==3)&&(p_adp->port==0))
					{
						APLL_ADC_clock(CLK_ON);
						rtd_setbits(0xb800086c,0x00000003);// GPI_EN
						rtd_clearbits(0xb8020064,0x00000800);//VSYNC_PD
						rtd_setbits(0xb8020064,0x00001000);//VSYNC_PU
					}
				#endif
				if (p_adp->port >= 0 && p_this->set_port(p_this, p_adp->port) < 0)
				{
					hw_i2c_semaphore_unlock(p_this);
		UnlockrtkI2CPhy(p_this);
		return -EACCES;
                     	}
			}
		}
	}

	for (i = 0; i < num; i++) {
		ret = p_this->set_tar(p_this, msgs[i].addr, ADDR_MODE_7BITS);

		if (ret < 0)
			goto err_occur;

		switch (msgs[i].flags & I2C_M_SPEED_MASK)
		{
		case I2C_M_FAST_SPEED:
			p_this->set_spd(p_this, p_adp->spd << 2);
			break;
		case I2C_M_HIGH_SPEED:
				#if SET_INTERNAL_DEMOD_1200HZ
				if((msgs[i].addr == 0x12)&&(p_this->id==0))
					p_this->set_spd(p_this, 1200);
				else
				#endif
			p_this->set_spd(p_this, p_adp->spd << 3);
			break;
		case I2C_M_LOW_SPEED:
			p_this->set_spd(p_this, p_adp->spd >> 1);
			break;
		default:
		case I2C_M_NORMAL_SPEED:
			p_this->set_spd(p_this, p_adp->spd);
			break;
		}

		p_this->set_guard_interval(p_this,
					   (msgs[i].
					    flags & I2C_M_NO_GUARD_TIME) ? 0 :
					   1000);


		switch (msgs[i].flags & I2C_M_HW_DELAY_MASK) {
		case I2C_M_400US_DELAY:
			p_this->set_hw_guard_interval(p_this, 400);
			break;
		case I2C_M_600US_DELAY:
			p_this->set_hw_guard_interval(p_this, 600);
			break;
		case I2C_M_800US_DELAY:
			p_this->set_hw_guard_interval(p_this, 800);
			break;
		case I2C_M_1000US_DELAY:
			p_this->set_hw_guard_interval(p_this, 1000);
			break;
		case I2C_M_2000US_DELAY:
			p_this->set_hw_guard_interval(p_this, 2000);
			break;
		default:
			p_this->set_hw_guard_interval(p_this, 0);
		};

		if (IsReadMsg(msgs[i])) {
			if (IsGPIORW(msgs[i]))
				ret =
				    p_this->gpio_read(p_this, NULL, 0,
						      msgs[i].buf, msgs[i].len);
			else
				ret =
				    p_this->read(p_this, NULL, 0, msgs[i].buf,
						 msgs[i].len);
		} else {
			if ((i < (num - 1)) && IsReadMsg(msgs[i + 1])
			    && IsSameTarget(msgs[i], msgs[i + 1])) {

				if (IsGPIORW(msgs[i]))
					ret =
					    p_this->gpio_read(p_this,
							      msgs[i].buf,
							      msgs[i].len,
							      msgs[i + 1].buf,
							      msgs[i + 1].len);
				else
					ret =
					    p_this->read(p_this, msgs[i].buf,
							 msgs[i].len,
							 msgs[i + 1].buf,
							 msgs[i + 1].len);
				i++;
			} else {

				if (IsGPIORW(msgs[i]))
					ret =
					    p_this->gpio_write(p_this,
							       msgs[i].buf,
							       msgs[i].len,
							       (i ==
								(num -
								 1)) ? WAIT_STOP
							       : NON_STOP);
				else
					ret =
					    p_this->write(p_this, msgs[i].buf,
							  msgs[i].len,
							  (i ==
							   (num -
							    1)) ? WAIT_STOP :
							  NON_STOP);
			}
		}

		if (ret < 0)
			goto err_occur;
	}

	#if defined(CONFIG_ARCH_RTK299S)
	if(msgs[0].addr == 0x12)
	{
		rtd_setbits(0xb80008BC, BIT(7));
	}
	else
	#endif
	{

		if (p_adp->port >= 0)
		{
			#if defined(CONFIG_ARCH_RTK299O)
			if((p_this->id==2)&&(p_adp->port==0))
			{
                                                pr_notice("rtk_pinmux_set (HDDC0,USERDEF)");
				rtk_pinmux_set(HDDC0,USERDEF);
			}
			else
		p_this->unset_port(p_this, p_adp->port);
			#else
			p_this->unset_port(p_this, p_adp->port);
			#endif
		}
	}
	hw_i2c_semaphore_unlock(p_this);
	UnlockrtkI2CPhy(p_this);

	return i;


err_occur:

	#if defined(CONFIG_ARCH_RTK299S)
	if(msgs[0].addr == 0x12)
	{
		rtd_setbits(0xb80008BC, BIT(7));
	}
	else
	#endif
	{
		if (p_adp->port >= 0)
		{
			#if defined(CONFIG_ARCH_RTK299O)
			if((p_this->id==2)&&(p_adp->port==0))
			{
                                                        pr_notice("rtk_pinmux_set (HDDC0,USERDEF)");
				rtk_pinmux_set(HDDC0,USERDEF);
			}
			else
		p_this->unset_port(p_this, p_adp->port);
			#else
			p_this->unset_port(p_this, p_adp->port);
			#endif
		}
	}

	#if defined(CONFIG_ARCH_RTK299O)||defined(CONFIG_ARCH_RTK289X) // this is just for patch test
	{
		if((ret == -ETIMEOUT) && (p_this->disable_auto_recovery == 0) )
		{
			I2C_CONDITION_WARNING(1,p_this,"[ch_%d] Xfer fail - TIMEOUT, I2C start recovery,isr_en =%x ,isr=%x \n",
				p_this->id,GET_IC_ISR_EN(p_this),GET_IC_ISR(p_this));
			int i2c_phy = BIT(p_this->id);
			CRT_CLK_OnOff(I2C, CLK_OFF, &i2c_phy);
			mdelay(50);
			CRT_CLK_OnOff(I2C, CLK_ON, &i2c_phy);
		}
	}
	#endif
	hw_i2c_semaphore_unlock(p_this);
	UnlockrtkI2CPhy(p_this);



	switch (ret) {
	case -ECMDSPLIT:
		I2C_CONDITION_WARNING(tempLevel,p_this,"-----------------------------------------\n");
		I2C_CONDITION_WARNING(tempLevel,p_this,"[ch_%d] Xfer fail - MSG SPLIT , message transfer not complete,(index:%d/total:%d)\n",
				p_this->id, i,num);
		break;

	case -ETXABORT:

		if((p_this->get_tx_abort_reason(p_this)& 0x0000001F)!= 0)
		{
			tempLevel=2;
		}
		I2C_CONDITION_WARNING(tempLevel,p_this,"-----------------------------------------\n");
		I2C_CONDITION_WARNING(tempLevel,p_this,"[ch_%d] Xfer fail - TXABORT (index:%d/total:%d), Reason=%04x\n",
		       p_this->id, i, num, p_this->get_tx_abort_reason(p_this));
		if(tempLevel==2)
		{
			I2C_CONDITION_WARNING(2,p_this,"Xfer fail - No ACK \n");
		}
		break;

	case -ETIMEOUT:
		I2C_CONDITION_WARNING(tempLevel,p_this,"-----------------------------------------\n");
		I2C_CONDITION_WARNING(tempLevel,p_this,"[ch_%d] Xfer fail - TIMEOUT, I2C bus start bit fail,(index:%d/total:%d)\n",
				p_this->id, i,num);

		break;

	case -EILLEGALMSG:
		I2C_CONDITION_WARNING(tempLevel,p_this,"-----------------------------------------\n");
		I2C_CONDITION_WARNING(tempLevel,p_this,"[ch_%d] Xfer fail - ILLEGAL MSG (index:%d/total:%d)\n", p_this->id,
		       i, num);
		break;

	case -EADDROVERRANGE:
		I2C_CONDITION_WARNING(tempLevel,p_this,"-----------------------------------------\n");
		I2C_CONDITION_WARNING(tempLevel,p_this,"[ch_%d] Xfer fail - ADDRESS OUT OF RANGE (index:%d/total:%d)\n",
		       p_this->id, i, num);
		break;

	default:
		I2C_CONDITION_WARNING(tempLevel,p_this,"-----------------------------------------\n");
		I2C_CONDITION_WARNING(tempLevel,p_this,"[ch_%d] Xfer fail - Unkonwn Return Value (index:%d/total:%d)\n",
		       p_this->id, i, num);
		break;
	}

	if(p_this->i2c_loglevel >= tempLevel)
	i2c_rtk_dump_msg(&msgs[i]);


	I2C_CONDITION_WARNING(tempLevel,p_this,"-----------------------------------------\n");

	ret = -EACCES;
	return ret;
}

/*------------------------------------------------------------------
 * Func : i2c_rtk_set_speed
 *
 * Desc : set speed of rtk i2c
 *
 * Parm : dev_id : i2c adapter
 *        KHz    : speed of i2c adapter
 *
 * Retn : 0 success, otherwise fail
 *------------------------------------------------------------------*/
static int i2c_rtk_set_speed(void *dev_id, int KHz)
{
	rtk_i2c_adapter *p_adp = (rtk_i2c_adapter *) dev_id;

	if (p_adp) {
		if (KHz > 400)
			KHz = 400;

		if (KHz < 50)
			KHz = 50;

		p_adp->spd = KHz;
		return 0;
	}

	return -1;
}





#ifdef CONFIG_PM

#define rtk_I2C_NAME          "rtk_I2C"

static int rtk_i2c_probe(struct device *dev)
{
	struct platform_device *pdev = to_platform_device(dev);
	return strncmp(pdev->name, rtk_I2C_NAME, strlen(rtk_I2C_NAME));
}

static int rtk_i2c_remove(struct device *dev)
{

	return 0;
}

static void rtk_i2c_shutdown(struct device *dev)
{

}

extern struct device* get_rtkdemod_device_ptr(void);
#if defined(CONFIG_ARCH_RTK299O)
extern unsigned char demod_suspend_done;      // TRUE: suspend complete / FALSE: resume  complete
#endif
unsigned char i2c_resume_done = 1;            // TRUE: resume  complete / FALSE: suspend complete

static int rtk_i2c_pm_suspend(struct device *dev)
{


	struct platform_device *pdev = to_platform_device(dev);

	rtk_i2c *p_this = ((rtk_i2c_adapter *) pdev->id)->p_phy;

	I2C_INFO("rtk_i2c_pm_suspend before\n");
	#if defined(CONFIG_ARCH_RTK299O)
	/* Make sure demod suspend first.*/
	unsigned long timeout = jiffies + HZ;
        do {
                if ( demod_suspend_done )
                        break;
        } while ( time_before(jiffies, timeout) );
	#endif
	LockrtkI2CPhy(p_this);
	p_this->suspend(p_this);
	UnlockrtkI2CPhy(p_this);

	mutex_lock(&m_I2CPower_mutex);

	m_I2CPowerCnt --;
	if(m_I2CPowerCnt == 0)
	{
		int i2c_phy = 0xFFFFFFFF; //BIT(0)|BIT(1)|BIT(2)|BIT(3);
		CRT_CLK_OnOff(I2C, CLK_OFF, &i2c_phy);
	}

	mutex_unlock(&m_I2CPower_mutex);

	i2c_resume_done = 0;
	return 0;
}

static int rtk_i2c_pm_resume(struct device *dev)
{

	struct platform_device *pdev = to_platform_device(dev);
	rtk_i2c *p_this = ((rtk_i2c_adapter *) pdev->id)->p_phy;

	mutex_lock(&m_I2CPower_mutex);

	if(m_I2CPowerCnt == 0)
	{
		int i2c_phy = 0xFFFFFFFF; //BIT(0)|BIT(1)|BIT(2)|BIT(3);
		CRT_CLK_OnOff(I2C, CLK_ON, &i2c_phy);
	}
	m_I2CPowerCnt ++;

#if defined(CONFIG_ARCH_RTK299O)&& !defined(CONFIG_ARCH_RTK289X)
	if(!(rtd_inl(0xb806022c) & 0x08000000))
		rtd_setbits(0xb806022c,0x08000000);//I2C_ctrl_en
#endif
	mutex_unlock(&m_I2CPower_mutex);

	LockrtkI2CPhy(p_this);
	p_this->resume(p_this);
	UnlockrtkI2CPhy(p_this);

	i2c_resume_done = 1;
	return 0;
}

static const struct dev_pm_ops rtk_i2c_pm_ops = {
	.suspend_late = rtk_i2c_pm_suspend, //[KTASKWBS-1065]
	.resume_early = rtk_i2c_pm_resume,
#ifdef CONFIG_HIBERNATION
	.freeze_late = rtk_i2c_pm_suspend,
	.thaw_early = rtk_i2c_pm_resume,
	.poweroff_late = rtk_i2c_pm_suspend,
	.restore_early = rtk_i2c_pm_resume,
#endif
};

static struct platform_driver rtk_i2c_platform_drv = {
	.driver = {
		   .name = rtk_I2C_NAME,
		   .bus = &platform_bus_type,
		   .probe = rtk_i2c_probe,
		   .remove = rtk_i2c_remove,
		   .shutdown = rtk_i2c_shutdown,
		   .pm = &rtk_i2c_pm_ops,
		   }
};

#endif





ssize_t rtk_i2c_show_param(struct device *dev, struct device_attribute *attr,
			     char *buf)
{
	struct i2c_adapter *p_adap = to_i2c_adapter(dev);
	rtk_i2c_adapter *p_vadp =
	    container_of(p_adap, rtk_i2c_adapter, adap);
	rtk_i2c *p_this = (rtk_i2c *) p_vadp->p_phy;
	int ret = 0;

	if (p_this) {
		LockrtkI2CPhy(p_this);

		if (strncmp(attr->attr.name, "speed", 5) == 0)
			ret = sprintf(buf, "%d\n", p_vadp->spd);
		else if (strncmp(attr->attr.name, "bus_status", 10) == 0) {
			buf[0] = p_this->get_bus_status(p_this) ? 1 : 0;
			ret = 1;

		}
		else if (strncmp(attr->attr.name, "disable_switch_port", strlen("disable_switch_port")) == 0)
		{
			ret = sprintf(buf, "%d\n", p_this->disable_switch_port);
		}
		else if (strncmp(attr->attr.name, "port", strlen("port")) == 0)
		{
			ret = sprintf(buf, "%d\n", p_vadp->port);
		}
		else if (strncmp(attr->attr.name, "fixed_speed", strlen("fixed_speed")) == 0)
		{
			ret = sprintf(buf, "%d\n", p_this->fixed_speed);
		}
		else if (strncmp(attr->attr.name, "i2c_loglevel", strlen("i2c_loglevel")) == 0)
		{
			ret = sprintf(buf, "%d\n", p_this->i2c_loglevel);
		}
		UnlockrtkI2CPhy(p_this);
	}

	return ret;
}

ssize_t rtk_i2c_set_param(struct device * dev, struct device_attribute * attr,
			    const char *buf, size_t count)
{
	struct i2c_adapter *p_adap = to_i2c_adapter(dev);
	rtk_i2c_adapter *p_vadp =
	    container_of(p_adap, rtk_i2c_adapter, adap);
	rtk_i2c *p_this = (rtk_i2c *) p_vadp->p_phy;
	int val=0;
	int val2=0;
	if (p_this) {
		LockrtkI2CPhy(p_this);

		if (strncmp(attr->attr.name, "speed", 5) == 0) {
			if (sscanf(buf, "%d\n", &val) == 1)
				i2c_rtk_set_speed(p_vadp, val);
		}

		if (strncmp(attr->attr.name, "bus_jam_recover", 15) == 0) {
			val = 0;
			sscanf(buf, "%d\n", &val);
			if (val || p_this->get_bus_status(p_this))
				p_this->do_bus_jame_recover(p_this);
		}

		if(strncmp(attr->attr.name, "disable_switch_port", strlen("disable_switch_port")) == 0)
		{
			if(sscanf(buf,"%d\n", &val)==1)
			{
				if(val == 0)
					p_this->disable_switch_port = 0 ;
				else
					p_this->disable_switch_port = 1;
			}
		}

		if(strncmp(attr->attr.name, "port", strlen("port")) == 0)
		{
			if(sscanf(buf,"%d\n", &val)==1)
			{
				p_vadp->port = val;
			}
		}

		if(strncmp(attr->attr.name, "run_read", strlen("run_read")) == 0)
		{
			int ret;
			ret=sscanf(buf,"%x,%x\n", &val,&val2);
			if(ret>0)
			{
				unsigned char buf[2]={0};
				unsigned char send_buf[2]={0};
				I2C_WARNING("get run_read is %x ; %x \n",val,val2);

				p_this->set_port(p_this, p_vadp->port);
				p_this->set_tar(p_this, val>>1, ADDR_MODE_7BITS);
				if(ret==1)
				{
					p_this->read(p_this, NULL, 0,buf,1);
				}
				else
				{
					send_buf[0]=val2;
					p_this->read(p_this, send_buf, 1,buf,1);
				}
				p_this->unset_port(p_this, p_vadp->port);
				//i2c_master_recv_ex(p_this->id, val >> 1,NULL,0,buf,1);
				I2C_WARNING("reason is %x \n",p_this->get_tx_abort_reason(p_this));
				I2C_WARNING("read data is %x \n",buf[0]);

			}
		}

		if(strncmp(attr->attr.name, "i2c_loglevel", strlen("i2c_loglevel")) == 0)
		{
			if(sscanf(buf,"%d\n", &val)==1)
			{
				p_this->i2c_loglevel = val ;
			}
		}

		if(strncmp(attr->attr.name, "polling_mode", strlen("polling_mode")) == 0)
		{
			if(sscanf(buf,"%d\n", &val)==1)
			{
				I2C_WARNING("get polling mode  is %x \n",val);
				if(val == 0)
					p_this->polling_mode= 0 ;
				else
					p_this->polling_mode = 1;
			}
		}

		if(strncmp(attr->attr.name, "recovery", strlen("recovery")) == 0)
		{
			if(sscanf(buf,"%d\n", &val)==1)
			{
				I2C_WARNING("get recovery  is %x \n",val);
				if(val != 0)
				{
					#ifdef CONFIG_I2C_RTK_BUS_JAM_RECOVER

					//rtk_i2c_bus_jam_recover_proc(p_this);
					//msleep(50);
					#endif
				}
			}
		}


		if(strncmp(attr->attr.name, "reset_clock", strlen("reset_clock")) == 0)
		{
			if(sscanf(buf,"%d\n", &val)==1)
			{
				I2C_WARNING("get reset_clock  is %x \n",val);
				if(val != 0)
				{
					int i2c_phy = BIT(p_this->id);
					CRT_CLK_OnOff(I2C, CLK_OFF, &i2c_phy);
					mdelay(50);
					CRT_CLK_OnOff(I2C, CLK_ON, &i2c_phy);
				}
			}
		}

		if(strncmp(attr->attr.name, "disable_auto_recovery", strlen("disable_auto_recovery")) == 0)
		{
			if(sscanf(buf,"%d\n", &val)==1)
			{
				I2C_WARNING("get disable_auto_recovery mode  is %x \n",val);
				if(val == 0)
					p_this->disable_auto_recovery = 0 ;
				else
					p_this->disable_auto_recovery = 1;
			}
		}

		if(strncmp(attr->attr.name, "fixed_speed", strlen("fixed_speed")) == 0)
		{
			if(sscanf(buf,"%d\n", &val)==1)
			{
				I2C_WARNING("get fixed_speed is %d \n",val);
				if(val == 0)
					p_this->fixed_speed = 0;
				else
					p_this->fixed_speed = 1;
			}
		}

		UnlockrtkI2CPhy(p_this);
	}

	return count;
}
DEVICE_ATTR(fixed_speed, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
	    rtk_i2c_show_param, rtk_i2c_set_param);
DEVICE_ATTR(disable_auto_recovery, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
	    rtk_i2c_show_param, rtk_i2c_set_param);
DEVICE_ATTR(polling_mode, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
	    rtk_i2c_show_param, rtk_i2c_set_param);
DEVICE_ATTR(recovery, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
	    rtk_i2c_show_param, rtk_i2c_set_param);
DEVICE_ATTR(reset_clock, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
	    rtk_i2c_show_param, rtk_i2c_set_param);
DEVICE_ATTR(i2c_loglevel, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
	    rtk_i2c_show_param, rtk_i2c_set_param);
DEVICE_ATTR(run_read, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
	    rtk_i2c_show_param, rtk_i2c_set_param);
DEVICE_ATTR(port, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
	    rtk_i2c_show_param, rtk_i2c_set_param);
DEVICE_ATTR(disable_switch_port, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
	    rtk_i2c_show_param, rtk_i2c_set_param);
DEVICE_ATTR(speed, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
	    rtk_i2c_show_param, rtk_i2c_set_param);
DEVICE_ATTR(bus_status, S_IRUSR | S_IRGRP | S_IROTH, rtk_i2c_show_param,
	    rtk_i2c_set_param);
DEVICE_ATTR(bus_jam_recover, S_IWUSR | S_IWGRP, rtk_i2c_show_param,
	    rtk_i2c_set_param);


struct device *i2c_port_dev_demod_use = 0;

static void set_i2c_device_ptr_demod_use(struct device* dev)
{
       i2c_port_dev_demod_use = dev;
}

struct device* get_i2c_device_ptr_demod_use(void)
{
       return i2c_port_dev_demod_use;
}



/*------------------------------------------------------------------
 * Func : i2c_rtk_register_adapter
 *
 * Desc : register i2c_adapeter
 *
 * Parm : p_phy       : pointer of i2c phy
 *
 * Retn : 0 : success, others failed
 *------------------------------------------------------------------*/
static int
__init i2c_rtk_register_adapter(rtk_i2c * p_phy, int port)
{
	rtk_i2c_adapter *p_adp =
	    kmalloc(sizeof(rtk_i2c_adapter), GFP_KERNEL);

	if (p_adp) {
		memset(p_adp, 0, sizeof(rtk_i2c_adapter));


		p_adp->adap.owner = THIS_MODULE;
		p_adp->adap.class = I2C_CLASS_HWMON;
		sprintf(p_adp->adap.name, "%s I2C %d bus", p_phy->model_name,
			p_phy->id);
		p_adp->adap.algo_data = &p_adp->algo;


		p_adp->algo.dev_id = (void *)p_adp;
		p_adp->algo.masterXfer = i2c_rtk_xfer;
		p_adp->algo.set_speed = i2c_rtk_set_speed;
		p_adp->p_phy = p_phy;
		p_adp->port = port;
		p_adp->spd = 100;

#ifdef CONFIG_PM
		p_adp->p_dev =
		    platform_device_register_simple(rtk_I2C_NAME,
						    (unsigned int)p_adp, NULL,
						    0);
		I2C_INFO( "%s , name = %s, id = %x\n", __func__,
		       p_adp->p_dev->name, p_adp->p_dev->id);

		/* [[KTASKWBS-1065] Make i2c resume run at asynchronous for parallel resume time*/
		//device_enable_async_suspend(&(p_adp->p_dev->dev));

		if(p_phy->id == I2C_PHY_CHANNEL_DEMOD_USE)
		{
			//device_enable_async_suspend(&(p_adp->p_dev->dev));
			set_i2c_device_ptr_demod_use(&(p_adp->p_dev->dev));
		}
#endif


		i2c_rtk_add_bus(&p_adp->adap);


		INIT_LIST_HEAD(&p_adp->list);

		list_add_tail(&p_adp->list, &rtk_i2c_list);
		device_create_file(&p_adp->adap.dev, &dev_attr_fixed_speed);
		device_create_file(&p_adp->adap.dev, &dev_attr_disable_auto_recovery);
		device_create_file(&p_adp->adap.dev, &dev_attr_polling_mode);
		device_create_file(&p_adp->adap.dev, &dev_attr_recovery);
		device_create_file(&p_adp->adap.dev, &dev_attr_reset_clock);
		device_create_file(&p_adp->adap.dev, &dev_attr_i2c_loglevel);
		device_create_file(&p_adp->adap.dev, &dev_attr_run_read);
		device_create_file(&p_adp->adap.dev, &dev_attr_port);
		device_create_file(&p_adp->adap.dev, &dev_attr_disable_switch_port);
		device_create_file(&p_adp->adap.dev, &dev_attr_speed);
		device_create_file(&p_adp->adap.dev, &dev_attr_bus_status);
		device_create_file(&p_adp->adap.dev, &dev_attr_bus_jam_recover);
	}

	return (p_adp) ? 0 : -1;
}

/*------------------------------------------------------------------
 * Func : i2c_rtk_unregister_adapter
 *
 * Desc : remove rtk i2c adapeter
 *
 * Parm : p_adap      : rtk_i2c_adapter data structure
 *
 * Retn : 0 : success, others failed
 *------------------------------------------------------------------*/
static
void i2c_rtk_unregister_adapter(rtk_i2c_adapter * p_adap)
{
	i2c_rtk_algo *p_algo = NULL;

	if (p_adap) {
		list_del(&p_adap->list);

		p_algo = (i2c_rtk_algo *) p_adap->adap.algo_data;

		device_remove_file(&p_adap->adap.dev, &dev_attr_fixed_speed);
		device_remove_file(&p_adap->adap.dev, &dev_attr_disable_auto_recovery);
		device_remove_file(&p_adap->adap.dev, &dev_attr_polling_mode);
		device_remove_file(&p_adap->adap.dev, &dev_attr_recovery);
		device_remove_file(&p_adap->adap.dev, &dev_attr_reset_clock);
		device_remove_file(&p_adap->adap.dev, &dev_attr_i2c_loglevel);
		device_remove_file(&p_adap->adap.dev, &dev_attr_run_read);
		device_remove_file(&p_adap->adap.dev, &dev_attr_port);
		device_remove_file(&p_adap->adap.dev, &dev_attr_disable_switch_port);
		device_remove_file(&p_adap->adap.dev, &dev_attr_speed);
		device_remove_file(&p_adap->adap.dev, &dev_attr_bus_status);
		device_remove_file(&p_adap->adap.dev,
				   &dev_attr_bus_jam_recover);

		i2c_rtk_del_bus(&p_adap->adap);

		destroy_rtk_i2c_handle(p_adap->p_phy);

#ifdef CONFIG_PM
		if (p_adap->p_dev)
			platform_device_unregister(p_adap->p_dev);
#endif
		kfree(p_adap);
	}
}

/*------------------------------------------------------------------
 * Func : parse_i2c_config
 *
 * Desc : get config for I2C0/I2C1
 *
 * Parm : id : I2C id
 *
 * Retn : 0 success, otherwise fail
 *------------------------------------------------------------------*/
int __init parse_i2c_config(char *config_str,
			    rtk_i2c_adapter_config * p_config,
			    unsigned char config_count)
{
	char buff[256];
	int n_config = 0;
	int i;

	if (config_str == NULL)
		return 0;

	memset(buff, 0, sizeof(buff));

	strncpy(buff, config_str, sizeof(buff));

	config_str = buff;

	for (i = 0; i < sizeof(buff); i++) {
		if (buff[i] == ',')
			buff[i] = ' ';
	}



	while (n_config < config_count) {
		char cfg[32];
		int val[2];
		memset(cfg, 0, 32);

		if (sscanf(config_str, "%s ", cfg) == 0)
			break;



		if (sscanf(cfg, "P%dS%d", &val[0], &val[1]) == 2) {
			p_config->mode = I2C_MODE;
			p_config->i2c.phy_id = (unsigned char)val[0];
			p_config->i2c.port_id = (char)val[1];
			n_config++;
		} else if (sscanf(cfg, "%u:%u", &val[0], &val[1]) == 2) {
			p_config->mode = G2C_MODE;
			p_config->g2c.sda = rtk_gpio_id(MIS_GPIO, val[0]);
			p_config->g2c.scl = rtk_gpio_id(MIS_GPIO, val[1]);
			n_config++;
		} else {
			I2C_WARNING("unknown config %s, ignore it , Line%d\n",
			       cfg, __LINE__);
			continue;
		}

		config_str += strlen(cfg) + 1;
		p_config++;
	}

	return n_config;
}

#ifdef CONFIG_REALTEK_PCBMGR
/*------------------------------------------------------------------
 * Func : load_i2c_config_from_pcb_mgr
 *
 * Desc : get config for i2c setting form pcb manager
 *
 * Parm : id : I2C id
 *
 * Retn : 0 success, otherwise fail
 *------------------------------------------------------------------*/
int __init load_i2c_config_from_pcb_mgr(rtk_i2c_adapter_config * p_config,
					unsigned char config_count)
{
	unsigned long long i2c_config = 0;
	int adapter_count = 0;
	char name[16] = { 0 };
	int i = 0;
	for (i = 0; i < config_count; i++) {
		sprintf(name, "I2C_PORT_%d", i);
		if (pcb_mgr_get_enum_info_byname(name, &i2c_config) == 0) {
			if (GET_I2C_TYPE(i2c_config) == PCB_I2C_TYPE_HW_I2C) {
				p_config[adapter_count].mode = I2C_MODE;
				p_config[adapter_count].i2c.phy_id =
				    GET_HW_I2C_PHY(i2c_config);

				if (GET_HW_I2C_SRC(i2c_config) ==
				    PCB_I2C_SUB_SRC_ANY)
					p_config[adapter_count].i2c.port_id =
					    -1;
				else
					p_config[adapter_count].i2c.port_id =
					    GET_HW_I2C_SRC(i2c_config);
				I2C_WARNING
				    ("Get PCB_ENUM I2C_PORT_%d I2C Mode Config phy_id=%d port_id = %d\n",
				     i, p_config[adapter_count].i2c.phy_id,
				     p_config[adapter_count].i2c.port_id);
			} else {
				p_config[adapter_count].mode = G2C_MODE;

				if (GET_PIN_TYPE(GET_GPIO_I2C_SDA(i2c_config))
				    == PCB_PIN_TYPE_ISO_GPIO)
					p_config[adapter_count].g2c.sda =
					    rtk_gpio_id(ISO_GPIO,
							  GET_PIN_INDEX
							  (GET_GPIO_I2C_SDA
							   (i2c_config)));
				else
					p_config[adapter_count].g2c.sda =
					    rtk_gpio_id(MIS_GPIO,
							  GET_PIN_INDEX
							  (GET_GPIO_I2C_SDA
							   (i2c_config)));

				if (GET_PIN_TYPE(GET_GPIO_I2C_SCL(i2c_config))
				    == PCB_PIN_TYPE_ISO_GPIO)
					p_config[adapter_count].g2c.scl =
					    rtk_gpio_id(ISO_GPIO,
							  GET_PIN_INDEX
							  (GET_GPIO_I2C_SCL
							   (i2c_config)));
				else
					p_config[adapter_count].g2c.scl =
					    rtk_gpio_id(MIS_GPIO,
							  GET_PIN_INDEX
							  (GET_GPIO_I2C_SCL
							   (i2c_config)));
				I2C_WARNING
				    ("Get PCB_ENUM I2C_PORT_%d G2C Mode Config SDA=%d SCL = %d\n",
				     i, p_config[adapter_count].g2c.sda,
				     p_config[adapter_count].g2c.scl);
			}

			adapter_count++;
		}
	}
	return adapter_count;
}

#endif

/*------------------------------------------------------------------
 * Func : load_i2c_config
 *
 * Desc : load i2c config
 *
 * Parm : id : I2C id
 *
 * Retn : 0 success, otherwise fail
 *------------------------------------------------------------------*/
int __init load_i2c_config(rtk_i2c_adapter_config * p_config,
			   unsigned char config_count)
{
	unsigned char adapter_count = 0;
	int i = 0;

#ifdef CONFIG_REALTEK_PCBMGR
	if (adapter_count == 0)
		adapter_count =
		    load_i2c_config_from_pcb_mgr(p_config, config_count);
#endif

	if (adapter_count == 0) {
		I2C_WARNING( "[I2C] Find No I2C info in PCB_ENUM.\n");
		adapter_count = get_rtk_i2c_phy_count();

		if (adapter_count > config_count)
			adapter_count = config_count;

		for (i = 0; i < adapter_count; i++) {
			p_config[i].mode = I2C_MODE;
			p_config[i].i2c.phy_id = i;
			p_config[i].i2c.port_id = -1;
			I2C_WARNING( "[I2C] Config I2C_MODE phy_id=%d port_id = %d\n",
			       p_config[i].i2c.phy_id, p_config[i].i2c.port_id);
		}
	}

	return adapter_count;
}

rtk_i2c *find_rtk_i2c_by_id(unsigned char id)
{
	rtk_i2c_adapter *cur = NULL;
	rtk_i2c_adapter *next = NULL;

	list_for_each_entry_safe(cur, next, &rtk_i2c_list, list) {
		if (cur->p_phy->id == id)
			return cur->p_phy;
	}

	return NULL;
}

int rtk_i2c_register_slave_driver(unsigned char id,
				    rtk_i2c_slave_driver * p_drv)
{
	rtk_i2c *phy = find_rtk_i2c_by_id(id);
	rtk_i2c_slave_ops ops = {
		.handle_command = p_drv->handle_command,
		.read_data = p_drv->read_data,
	};

	if (phy) {
		phy->set_sar(phy, p_drv->sar, ADDR_MODE_7BITS);
		return phy->register_slave_ops(phy, &ops, p_drv->private_data);
	}

	I2C_WARNING
	    ("rtk_i2c_register_slave_driver failed, can't find adapter %d\n",
	     id);
	return -1;
}

void rtk_i2c_unregister_slave_driver(unsigned char id,
				       rtk_i2c_slave_driver * p_drv)
{
	rtk_i2c *phy = find_rtk_i2c_by_id(id);

	if (phy)
		phy->register_slave_ops(phy, NULL, 0);
	else
		I2C_WARNING
			("rtk_i2c_unregister_slave_driver failed, can't find adapter %d\n",
		     id);
}

int rtk_i2c_slave_enable(unsigned char id, unsigned char on)
{
	rtk_i2c *phy = find_rtk_i2c_by_id(id);

	if (phy == NULL)
		I2C_WARNING( "rtk_i2c_slave_enable failed, can't find adapter %d\n",
		       id);

	return (phy) ? phy->slave_mode_enable(phy, on) : -1;
}

/*------------------------------------------------------------------
 * Func : i2c_rtk_module_init
 *
 * Desc : init rtk i2c module
 *
 * Parm : N/A
 *
 * Retn : 0 success, otherwise fail
 *------------------------------------------------------------------*/
static int
__init i2c_rtk_module_init(void)
{
	rtk_i2c_adapter_config adapter_config[MAX_I2C_ADAPTER] = { {0} };
	unsigned char adapter_count = 0;
	int i = 0;
	rtk_i2c *p_this = NULL;

	i2c_power(1);
	//baker
	//uart 1 need src, we can't switch this.
	//rtd_maskl(0xb8060218, 0xffffff0f, 0x000000f0);
	//rtd_maskl(0xb806021C, 0x0fffffff, 0xf0000000);

	adapter_count = load_i2c_config(adapter_config, MAX_I2C_ADAPTER);
	m_I2CPowerCnt = adapter_count;
	mutex_init(&m_I2CPower_mutex);

	for (i = 0; i < adapter_count; i++) {
		if (adapter_config[i].mode == I2C_MODE) {
			I2C_WARNING( "[ch_%d]: id =%d, port =%d\n",
				adapter_config[i].i2c.phy_id,
				adapter_config[i].i2c.port_id);
			if ((adapter_config[i].i2c.phy_id == 0)||(adapter_config[i].i2c.phy_id == 5))
			{
				p_this =
				    create_rtk_i2c_handle(adapter_config[i].
							    i2c.phy_id,
							    rtk_MASTER_7BIT_ADDR,
							    ADDR_MODE_7BITS,
							    SPD_MODE_SS,
							    IRQ_GET_KERNEL_IRQ_NUM(IRQ_CEC));
			}
			else
			{
				p_this =
				    create_rtk_i2c_handle(adapter_config[i].
							    i2c.phy_id,
							    rtk_MASTER_7BIT_ADDR,
							    ADDR_MODE_7BITS,
							    SPD_MODE_SS,
							    IRQ_GET_KERNEL_IRQ_NUM(IRQ_MISC));
				#if defined(CONFIG_ARCH_RTK299O)
				// this is just for 2990 phy3 src0 patch
				if((adapter_config[i].i2c.phy_id==3)&&(adapter_config[i].i2c.port_id==0))
				{
					APLL_ADC_clock(CLK_ON);
					rtd_setbits(0xb800086c,0x00000003);// GPI_EN
					rtd_clearbits(0xb8020064,0x00000800);//VSYNC_PD
					rtd_setbits(0xb8020064,0x00001000);//VSYNC_PU
				}
				#endif

				#if defined(CONFIG_ARCH_RTK289X)
				
				if((adapter_config[i].i2c.phy_id==4)&&(adapter_config[i].i2c.port_id==0))
				{
					rtd_setbits(0xb8000814,0x18); // GPI_EN
				}
				#endif
			}
			if (p_this == NULL)
				continue;
			I2C_WARNING( "[ch_%d] open successed, reference cnt=%d\n",
			       adapter_config[i].i2c.phy_id,
			       atomic_read(&p_this->ref_cnt));

			if (p_this->init(p_this) < 0
			    || i2c_rtk_register_adapter(p_this,
							  adapter_config[i].i2c.
							  port_id) < 0)
				destroy_rtk_i2c_handle(p_this);
		} else {
			I2C_WARNING( "[ch_%d], mode=g2c, sda=%d, scl=%d\n", i,
			       adapter_config[i].g2c.sda,
			       adapter_config[i].g2c.scl);
			p_this =
			    create_rtk_g2c_handle(i,
						    adapter_config[i].g2c.sda,
						    adapter_config[i].g2c.scl);

			if (p_this == NULL)
				continue;

			if (p_this->init(p_this) < 0
			    || i2c_rtk_register_adapter(p_this, -1) < 0)
				destroy_rtk_i2c_handle(p_this);
		}
	}

#ifdef CONFIG_PM
	platform_driver_register(&rtk_i2c_platform_drv);
#endif

	return 0;
}

/*------------------------------------------------------------------
 * Func : i2c_rtk_module_exit
 *
 * Desc : exit rtk i2c module
 *
 * Parm : N/A
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
static void
__exit i2c_rtk_module_exit(void)
{
	rtk_i2c_adapter *cur = NULL;
	rtk_i2c_adapter *next = NULL;

	list_for_each_entry_safe(cur, next, &rtk_i2c_list, list) {
		i2c_rtk_unregister_adapter(cur);
	}

	mutex_destroy(&m_I2CPower_mutex);

#ifdef CONFIG_PM
	platform_driver_unregister(&rtk_i2c_platform_drv);
#endif
}

MODULE_AUTHOR("Kevin-Wang <kevin_wang@realtek.com.tw>");
MODULE_DESCRIPTION("I2C-Bus adapter routines for Realtek rtk/Neptune DVR");
MODULE_LICENSE("GPL");

module_init(i2c_rtk_module_init);
module_exit(i2c_rtk_module_exit);
