/*
 * xhci-plat.c - xHCI host controller driver platform Bus Glue.
 *
 * Copyright (C) 2012 Texas Instruments Incorporated - http://www.ti.com
 * Author: Sebastian Andrzej Siewior <bigeasy@linutronix.de>
 *
 * A lot of code borrowed from the Linux xHCI driver.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 */

#include <linux/clk.h>
#include <linux/dma-mapping.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/usb/phy.h>
#include <linux/slab.h>
#include <linux/usb/xhci_pdriver.h>
#include <linux/acpi.h>

#if defined(CONFIG_USER_INITCALL_USB) && !defined(MODULE)
#include <linux/fs.h>
#include <linux/file.h>
#include <asm/uaccess.h>
#endif

#include "xhci.h"
#include "xhci-mvebu.h"
#include "xhci-rcar.h"

#include <rbus/usb_reg.h> /* for U3 wrapper register define */
#include <rbus/sb2_reg.h>
#ifdef CONFIG_RTK_KDRIVER_SUPPORT
#include <rtk_kdriver/rtk_crt.h>
#include <rtk_kdriver/rtk_gpio.h>
#else
#include <mach/rtk_crt.h>
#include <mach/rtk_gpio.h>
#endif
#include <mach/platform.h>
#include "xhci.h"
#include "../core/usb.h"
#include "xhci-plat-rtd289x-config.h"

#define USB_PHY_DELAY	25

#define xhci_plat_dbg(fmt, args...)           pr_debug("[xhci] dbg, " fmt, ## args)
#define xhci_plat_info(fmt, args...)          pr_info("[xhci] info, " fmt, ## args)
#define xhci_plat_warn(fmt, args...)          pr_warn("[xhci] warn, " fmt, ## args)

struct platform_device *xhci_platform_dev = NULL;
static struct hc_driver __read_mostly xhci_plat_hc_driver;

static int xhci_plat_setup(struct usb_hcd *hcd);
static int xhci_plat_start(struct usb_hcd *hcd);

#define CONFIG_USB_PORT_CHECK

#ifdef CONFIG_USB_PORT_CHECK
static bool poll_check_suspend = true;
#define USB_HUB_CHECK_TIME	500
#define USB_PORT_ERR_CHECK_TIME	200

#define BLACKDEV_TIMEOUT 5

static unsigned long blackDeviceCNT = 0;
static struct timer_list xhci_hub_check_timer;
static unsigned int u3_delayed_vbus_on = 0;
static unsigned int u3_port_reset_hang = 0;
static unsigned int u3_port_reset_hang_count = 0;
static unsigned int u3_port_recovery_cnt = 0;
static unsigned int u2_port_reset_hang = 0;
static unsigned int u2_port_reset_hang_count = 0;
static unsigned int xhci_hub_polling_check_running = 0;

#define U3_PORTSC                   0xb8050460   // In K3L the company
#define U3_COMPANY_U2_PORTSC        0xb8050450   // In K3L the company

#define CONFIG_RTK_U3D		(0x1 << 8)

static unsigned int xhci_control_flag = 0;
#define NO_RESTORE_U3_PHY       (0x1)
#define NO_RESTORE_U2_PHY       (0x1<<1)
#define NO_U3_PORT_AUTO_RECOVER (0x1<<2)
#define NO_U3_SUPER_SPEED_PORT	(0x1<<3)

#ifdef CONFIG_USB_TYPE_C
static int type_c_dev_id, type_c_irq;
static bool registered_type_c_irq = false;
#endif /* CONFIG_USB_TYPE_C */

//-----------------------------------------------------------------
// Platform Config
//-----------------------------------------------------------------
XHCI_RTD289X_CONFIG		xhci_config;

#define platform_has_u3_port()	((xhci_config.u3_port_disabled==0) ? 1 : 0)
	
	
//-----------------------------------------------------------------
// Port VBUS Control
//-----------------------------------------------------------------

const char* _xhci_port_name(XHCI_PORT_ID pid)
{
	switch(pid)	{
	case XHCI_U2_PORT1: return "U2 Port1";
	case XHCI_U2_PORT2: return "U2 Port2";
	case XHCI_U2_PORT3: return "U2 Port3";
	case XHCI_U2_PORT4: return "U2 Port4";
	case XHCI_U3_PORT:  return "U3 Port1";
	default:		return "Unknown port";
	}
}

XHCI_PORT_GPIO* _xhci_get_vbus_gpio(XHCI_PORT_ID pid)
{
	if (pid >= XHCI_MAX_PORT) {
		xhci_plat_warn("get vbus gpio failed, invalid port id - %d\n", pid);
		return NULL;
	}

	return (xhci_config.port_config[pid].vbus.enable) ? &xhci_config.port_config[pid].vbus : NULL;
}

int _xhci_gpio_control(XHCI_PORT_GPIO gpio, unsigned int on)
{
	if (gpio.enable) {
		if (gpio.polarity==0)	// negative
			on = (on) ? 0 : 1;
		rtk_gpio_output(gpio.gid, on);		
		rtk_gpio_set_dir(gpio.gid, 1);			// set gpio to output mode
	}
	return 0;
}

int _xhci_port_vbus_control(XHCI_PORT_ID pid, unsigned int on)
{
	XHCI_PORT_GPIO* p_gpio = _xhci_get_vbus_gpio(pid);				
	if (p_gpio)	{
		xhci_plat_warn("set %s port vbus %s\n", _xhci_port_name(pid), (on) ? "ON" : "OFF");			
		_xhci_gpio_control(*p_gpio, on);				
	}	
	return 0;
}

int _xhci_port_vbus_status(XHCI_PORT_ID pid)
{
	XHCI_PORT_GPIO* p_gpio = _xhci_get_vbus_gpio(pid);
	if (p_gpio) {
		int val = rtk_gpio_input(p_gpio->gid);
		if (p_gpio->polarity==0)
			val = (val) ? 0 : 1;
		return val;
	}
	return -1;
}

#define U3PortVBusControl(on)	_xhci_port_vbus_control(XHCI_U3_PORT, on)
#define U3PortVBusStatus()		_xhci_port_vbus_status(XHCI_U3_PORT)

static int isU3portHSmode( void )
{
	// USB_HMAC_CTR0_reg[8]: host_u3_port_disable
	if (rtd_inl(HMAC_CTR0_reg) & CONFIG_RTK_U3D)
		return 1;

	return 0;
}

static void U3PortVBusToggle(void )
{
	if(!isU3portHSmode()) {		
		U3PortVBusControl(0);
		mdelay(50);
		U3PortVBusControl(1);
	}
}

void enable_vbus_power(void)
{
	_xhci_port_vbus_control(XHCI_U2_PORT1, 1);
	_xhci_port_vbus_control(XHCI_U2_PORT2, 1);
	_xhci_port_vbus_control(XHCI_U2_PORT3, 1);
	_xhci_port_vbus_control(XHCI_U2_PORT4, 1);
	_xhci_port_vbus_control(XHCI_U3_PORT,  1);
}

void p3_mode_control(int enable)
{
	if (enable)
		rtd_maskl(0xb80582c0, ~(1<<17), 1<<17);
	else
		rtd_maskl(0xb80582c0, ~(1<<17), 0);
}

static bool is_usb_clk_on(void)
{
	return (rtd_inl(SYS_REG_SYS_CLKEN2_reg) & SYS_REG_SYS_CLKEN2_clken_usb_mask);
}

#if defined(CONFIG_USER_INITCALL_USB) && !defined(MODULE)
#define BUF_SIZE 2
static int get_user_initcall_status(void)
{
	mm_segment_t oldfs;
	struct file *fp;
	int ret;
	char buf[BUF_SIZE];

	oldfs = get_fs();
	set_fs(KERNEL_DS);

	fp = filp_open("/proc/usercalls", O_RDONLY, 0);
	if (!fp) {
		ret = -ENOENT;
		goto out;
	}
	if (fp->f_op && fp->f_op->read) {
		fp->f_op->read(fp, buf, BUF_SIZE, &fp->f_pos);
		buf[1] = '\0';
		if(kstrtol(buf, 10, &ret))
			ret = -EINVAL;
	} else {
		ret = -ENOSYS;
	}
	filp_close(fp, NULL);
out:
	set_fs(oldfs);
	return ret;
}
#endif
//-----------------------------------------------------------------
// MDIO API : function below is used for USB3.0 Phy register access
//-----------------------------------------------------------------


/*-----------------------------------------------
 * Func : mdio_write
 *
 * Desc : write mdio 
 *
 * Parm : phy_addr : phy register
 *        reg_addr : register addr
 *        val : mdio control value
 *
 * Retn : N/A
 *-----------------------------------------------*/
static void mdio_write(
    unsigned char           phy_addr,
    unsigned char           reg_addr,
    unsigned short          val
    )
{
    xhci_plat_dbg("mdio_wr(pg_%d, reg_%02x)=0x%04x\n", phy_addr, reg_addr, val);

    rtd_outl(MDIO_CTR_reg, MDIO_CTR_data(val) |
                           MDIO_CTR_phy_addr(phy_addr) |
                           MDIO_CTR_phy_reg_addr(reg_addr) |
                           MDIO_CTR_mclk_rate(3) |      // clk_sys/4
                           MDIO_CTR_mdio_rdwr(1));

    do {
        udelay(USB_PHY_DELAY);
    } while((rtd_inl(MDIO_CTR_reg) & MDIO_CTR_mdio_busy_mask)); // wait busy done
}

/*-----------------------------------------------
 * Func : mdio_read
 *
 * Desc : read mdio 
 *
 * Parm : phy_addr : phy register
 *        reg_addr : register addr
 *        val : mdio control value
 *
 * Retn : read value
 *-----------------------------------------------*/
static unsigned short mdio_read(
    unsigned char       phy_addr,
    unsigned char       reg_addr
    )
{
    unsigned long ctrl = MDIO_CTR_phy_addr(phy_addr) |
                         MDIO_CTR_phy_reg_addr(reg_addr) |
                         MDIO_CTR_mclk_rate(3) |
                         MDIO_CTR_mdio_rdwr(0);

    //pr_debug("mdio_ctrl=%08lx\n", ctrl);
    rtd_outl(MDIO_CTR_reg, ctrl);
    do {
        udelay(USB_PHY_DELAY);
    } while((rtd_inl(MDIO_CTR_reg) & MDIO_CTR_mdio_busy_mask)); // wait busy done
    return rtd_inl(MDIO_CTR_reg) >> 16;
}



extern unsigned long xhci_irq_count;


#define CRC_SRC_NONE        0x0
#define CRC_SRC_U3_PORT     0x1
#define CRC_SRC_U2_PORT0_0  0x3
#define CRC_SRC_U2_PORT0    0x4
#define CRC_SRC_U2_PORT1    0x5
#define CRC_SRC_U2_PORT2    0x6
#define CRC_SRC_U2_PORT3    0x7

const char* xhci_crc_error_src(unsigned char id)
{
    switch(id) {
    case CRC_SRC_NONE:  return "none";
    case CRC_SRC_U3_PORT:  return "U3 Port";
    case CRC_SRC_U2_PORT0_0: return "U2 Port0-0";
    case CRC_SRC_U2_PORT0: return "U2 Port0";
    case CRC_SRC_U2_PORT1: return "U2 Port1";
    case CRC_SRC_U2_PORT2: return "U2 Port2";
    case CRC_SRC_U2_PORT3: return "U2 Port3";
    default:
        return "Unknonw";
    }
}

int _xhci_get_port_status_str(char* ptr, int count)
{
	unsigned long val;	
	int n = 0;
	int len = 0;
	
	if (platform_has_u3_port())
	{			
		n = scnprintf(ptr, count, "[USB][XHCI] CMD=%03x, STS=%04x, U2 Port{STS=%x, %x, %x, %x}, U3 Port{STS=%x, Link=%04x, PWR=%d, Recovery=%lu}, irq_cnt=%u\n",
    		rtd_inl(0xb8050020), rtd_inl(0xb8050024),
    		rtd_inl(0xb8050420), rtd_inl(0xb8050430), rtd_inl(0xb8050440),
    		rtd_inl(0xb8050450), rtd_inl(0xb8050460), rtd_inl(0xb8050468),
    		U3PortVBusStatus(),
    		u3_port_recovery_cnt, 
    		xhci_irq_count);
	}
	else
	{	
		n = scnprintf(ptr, count, "[USB][XHCI] CMD=%03x, STS=%04x, U2 Port{STS=%x, %x, %x, %x}, irq_cnt=%u\n",
    		rtd_inl(0xb8050020), rtd_inl(0xb8050024),
    		rtd_inl(0xb8050420), rtd_inl(0xb8050430), rtd_inl(0xb8050440), rtd_inl(0xb8050450),
    		xhci_irq_count);
	}
	
	ptr += n;
	len += n;
	count -= n;	
	
	val = rtd_inl(CRC_CNT_1_reg);
	if (CRC_CNT_1_get_Crc_cnt_en(val))
	{
		n = scnprintf(ptr, count, "[USB][XHCI] CRC_CNT_1=(%08lx) { SRC=%s, ERR=%lu, Total=%lu }\n",
			val,
			xhci_crc_error_src(CRC_CNT_1_get_Crc_cnt_sel(val)),
			CRC_CNT_1_get_Crc_err_cnt(val),
			rtd_inl(CRC_CNT_2_reg));

        ptr   += n;
		count -= n;
		len += n;
	}
	
	return len;
}

void dump_port_status_ex(unsigned char warn)
{
	char buff[1024];    
    
    _xhci_get_port_status_str(buff, sizeof(buff));	

    if (warn)
    	xhci_plat_warn("%s", buff);
    else
        xhci_plat_dbg("%s", buff);
}

#define dump_port_status()      dump_port_status_ex(0)


static void xhci_reset_u3_port(void)
{
	xhci_plat_info("xhci_reset_u3_port, (U3 Port HS mode=%d)\n", isU3portHSmode());

	if(!isU3portHSmode())
		U3PortVBusControl(0);

	rtd_clearbits(U3_PORTSC, PORT_POWER);
	rtd_clearbits(U3_COMPANY_U2_PORTSC, PORT_POWER);
	udelay(10);
	rtd_setbits(U3_PORTSC, PORT_POWER | PORT_CSC);    // set port power and clear CSC
	rtd_setbits(U3_COMPANY_U2_PORTSC, PORT_POWER | PORT_CSC);    // set port power and clear CSC
	xhci_plat_info("xhci_reset_u3_port, reset U3/U2 port (U3 Status=%08X, U2 Status=%08X)\n",
	rtd_inl(U3_PORTSC), rtd_inl(U3_COMPANY_U2_PORTSC));
	mdelay(50);

	if(!isU3portHSmode())
		U3PortVBusControl(1);

	dump_port_status_ex(1);
}


static void xhci_hub_polling_check(unsigned int arg)
{
	unsigned long regVal;
	unsigned int polling_interval = USB_HUB_CHECK_TIME;
	int i;

	if (!is_usb_clk_on()|| poll_check_suspend || xhci_hub_polling_check_running)               // enter suspend mode
		return;

	if (isU3portHSmode()) {
		blackDeviceCNT++;
		if(blackDeviceCNT > BLACKDEV_TIMEOUT) {
			rtd_clearbits(USB_TMP_0_reg,(0x1<<8));
			blackDeviceCNT = 0;
		}
		goto restart_timer;
	}

	xhci_hub_polling_check_running = 1;

	if (u3_delayed_vbus_on) {
		U3PortVBusControl(1);
		u3_delayed_vbus_on = 0;
	}

	dump_port_status();

	if (platform_has_u3_port()==0 || (xhci_control_flag & NO_U3_PORT_AUTO_RECOVER))   // skip auto recover
	    goto restart_timer;

#if 1
	/*------------- check U3 Port --------------------
	In K2L, the U3 port is connected to both an U3
	phy and an U2 Phy (Port 2).

	The status below is the normal case
	1) disconnected : U3 = 2A0, U2 = 2A0
	2) SS device connected : U3 = 1203, U2 = 2A0
	3) HS device connected : U3 =  2A0, U2 = e03
	4) HS device connected : U3 =  2A0, U2 = 603
	5) U3 hub connected    : U3 = 1203, U2 = e03

	However, there is some special case the need to be handled
	6) U3 port disabled    : U3 = 290 (PLS=SS.Disabled), U2 is connected
	Might caused by U3 unexceptly disconnection.
	The HC uses U2 to reconnect it automatically.

		that also can be divided into 2 case
		a) U2 is not disabled (PE=1)
		In this case, the U2 work normally.
		We have nothing to do .

		b) U2 is disabled (PLS=0x7 Disabled)
		In this case, the U2 is abnormal too
		we need to fix it by toggling the VBus.

	7) U3 port is in SS.Inactive. We do Warm Port Reset to enter RxDetect
	-------------------------------------------------*/
	// case 6: U3 Port is disabled for some reason (except we use debug_control interface to disable U3. "no_u3_super_speed_port=1")
	if (((rtd_inl(U3_PORTSC) & PORT_PLS_MASK) == XDEV_DISABLE) && !(xhci_control_flag & NO_U3_SUPER_SPEED_PORT))
	{
		rtd_clearbits(U3_PORTSC, PORT_POWER);
		rtd_setbits(U3_PORTSC, PORT_POWER);

		xhci_plat_warn("%s : u3 port disabled, toogle port state (%08X -> %08X), cnt=%d\n",
			__FUNCTION__,
			regVal,
			rtd_inl(U3_PORTSC),
			u3_port_recovery_cnt);
		u3_port_recovery_cnt++;
	}

	// case 6-b : device detected by U2 port 2, but u2 port 2 is in disabled state
	//          and the U3 port has no device detected
	//          (that means the U3 port is routed to U2 phy,
	if(((rtd_inl(U3_PORTSC) & (PORT_CONNECT|PORT_PE))==0) &&
	   ((rtd_inl(U3_COMPANY_U2_PORTSC) & PORT_PLS_MASK)==XDEV_POOLING) &&   // Port 2 enter disable state
	   ((rtd_inl(U3_COMPANY_U2_PORTSC) & PORT_CONNECT)==PORT_CONNECT))
	{
		u3_port_reset_hang++;
		polling_interval = USB_PORT_ERR_CHECK_TIME;

		dump_port_status_ex(1);

		xhci_plat_warn("%s : u3 port reset hanged=%u, U3PORT=%08X, U2PORT=%08X\n",
			    __FUNCTION__, u3_port_reset_hang, rtd_inl(U3_PORTSC), rtd_inl(U3_COMPANY_U2_PORTSC));

		if (u3_port_reset_hang >= (1500/polling_interval))
		{
			u3_port_reset_hang_count++;
			u3_port_recovery_cnt++;

			xhci_plat_warn("%s : u3 port reset hanged count=%d, do Vbus toogle\n",
				__FUNCTION__, u3_port_reset_hang_count);

			xhci_reset_u3_port();
			u3_port_reset_hang = 0;
		}
	}
	// case 7: U3 port is in SS.Inactive. We do Warm Port Reset to enter RxDetect
	else if (((rtd_inl(U3_PORTSC) & PORT_PLS_MASK)) == XDEV_INACTIVE)
	{
		u3_port_reset_hang++;
		polling_interval = USB_PORT_ERR_CHECK_TIME;

		dump_port_status_ex(1);

		xhci_plat_warn("%s : u3 port reset hanged=%u, U3PORT=%08X \n",
			    __FUNCTION__, u3_port_reset_hang, rtd_inl(U3_PORTSC));
		if (u3_port_reset_hang >= (1500/polling_interval))
		{
			u3_port_reset_hang_count++;
			u3_port_recovery_cnt++;

			xhci_plat_warn("%s : u3 port reset hanged count=%d, U3 is in Inactive, do Warm Port Reset\n",
				__FUNCTION__, u3_port_reset_hang_count);

			rtd_setbits(U3_PORTSC, PORT_WR); // Issue a Warm Port Reset

			u3_port_reset_hang = 0;
		}
	}
	else
		u3_port_reset_hang = 0;

#endif

	/*------------- check U3 connection status --------------------
	The b8058164 [10:9] (GDBGLTSSM[10:9] refs to DWC_USB3 spec) is another way to detect the U3 device connection
	This value will be 0 if HW detected the U3 signal.
	--------------------------------------------------------------*/
	if((rtd_inl(0xb8058164) & (0x3 << 9)) == (0 << 9)) { //check usb3 device plug in connector

		//--------------------------------------------------------------------------
		// U3 device is not detected by the Hub driver.
		// but the U3 port status is under one of the following condition
		// PLS = PORTSC[5:8]
		//   0x1203 : PLS = 0x00 (U0)
		//   0x340  : PLS = 0x10 (compliance test mode)
		//   0x300  : PLS = 0x08 (U3 Recovery mode)
		//--------------------------------------------------------------------------
		regVal = rtd_inl(U3_PORTSC);

		if(((regVal == 0x1203) ||   // Connected correctly
		    (regVal == 0x340)  ||   // compliance test mode
		    (regVal == 0x300)) &&   // U3 Recovery mode
		    (usb3_device_plugin == 0))
		{
			U3PortCnt++;

			//if(usb3_device_resume == 1)
			//{
			//	U3PortCnt = 0;
			//}

			polling_interval = USB_PORT_ERR_CHECK_TIME; // change to smaller polling interval

			if(U3PortCnt >= (2000/polling_interval)) {
				dump_port_status_ex(1);
				xhci_plat_warn("usb3_device_plugin=%d U3PortCnt=%d portstatus=%#x\n", usb3_device_plugin, U3PortCnt, regVal);
				switch (regVal) {
					case 0x340 : // exit compliance test mode
					case 0x1203 :
						rtd_clearbits(U3_PORTSC, PORT_POWER);
						rtd_setbits(U3_PORTSC, PORT_POWER);
						U3PortVBusToggle();
						break;
					default :
						U3PortVBusToggle();
						break;
				}
				U3PortCnt = 0;
				xhci_plat_warn("vbus reset device\n");
				goto restart_timer;
			}
		}

		//--------------------------------------------------------------------------
		// neither U3 nor U2 detected the device
		//--------------------------------------------------------------------------
		if (((rtd_inl(U3_PORTSC) & PORT_PLS_MASK) == XDEV_POOLING) &&
		    ((rtd_inl(U3_COMPANY_U2_PORTSC) & PORT_CONNECT) == 0))
		{
			xhci_plat_warn("usb3_device_plugin=%d port_check_count=%d \n",
			                usb3_device_plugin, port_check_count);

			++port_check_count;
			polling_interval = USB_PORT_ERR_CHECK_TIME; // change to smaller polling interval

			/*------------- check U3 connection status --------------------
			 usb3_device_plugin is a global variable that defined in usb/core/hub.c
			 that is used to ident2ify the system detected the U3 device on the Root Hub
			 or not.
			--------------------------------------------------------------*/
			if (usb3_device_plugin)
			{
				if (port_check_count >=(2000/polling_interval)) // toggle vbus after 3 sec
				{
					mdio_write(0x1, 0x02, 0x0013);
					U3PortVBusToggle();
					port_check_count = 0;
					xhci_plat_warn("vbus reset device1");
				}
			}
			else
			{
				if (port_check_count >=(1500/polling_interval)) // toggle vbus after 2 sec
				{
					mdio_write(0x1, 0x02, 0x0013);
					xhci_plat_warn("[before reset vbus] %08x=%x, %08x=%x\n",
					            U3_PORTSC,
					            rtd_inl(U3_PORTSC),
					            U3_COMPANY_U2_PORTSC,
					            rtd_inl(U3_COMPANY_U2_PORTSC));

					U3PortVBusToggle();

					port_check_count = 0;
					usb3_device_plugin = 0;
					xhci_plat_warn("vbus reset device\n");
					xhci_plat_warn("[after reset vbus] %08x=%x, %08x=%x",
					    U3_PORTSC,
					    rtd_inl(U3_PORTSC),
					    U3_COMPANY_U2_PORTSC,
					    rtd_inl(U3_COMPANY_U2_PORTSC));
				}
			}
		}
		else
			port_check_count = 0;
	}
	else
		port_check_count = 0;

	/*------------- check each U2 connection status --------------------
	 * If U2 PORTSC.PLS equal to "ee1", we need to do port reset to recover
	--------------------------------------------------------------*/
	for (i = 0; i < (sizeof(u2_portsc_regs) / sizeof(*u2_portsc_regs)); i++)
	{
		regVal = rtd_inl(u2_portsc_regs[i]);
		if ((regVal & PORT_CONNECT) && !(regVal & PORT_PE))
		{
			u2_port_reset_hang++;
			if (u2_port_reset_hang >= (1500/USB_PORT_ERR_CHECK_TIME))
			{
				rtd_setbits(u2_portsc_regs[i], PORT_RESET);
				u2_port_reset_hang = 0;
				u2_port_reset_hang_count++;
				xhci_plat_warn("U2-%d portsc=0x%x, do port reset=%d. cnt=%d \n", i+1, regVal, u2_port_reset_hang_count);
			}
		}
	}

restart_timer:
	xhci_hub_polling_check_running = 0;
	mod_timer(&xhci_hub_check_timer, jiffies + msecs_to_jiffies(USB_HUB_CHECK_TIME));
}



/*------------------------------------------------------------
 * Func : xhci_check_port_status
 * Desc : Check USB Port Status or not
 * Parm : N/A
 * Retn : 0 : success,
 *        others : someting wrong, need more check later
 *------------------------------------------------------------*/
void xhci_check_port_status(void )
{
	if (platform_has_u3_port())
	{
		// case 1 : U3 Port is Disabled
		if (((rtd_inl(U3_PORTSC) & PORT_PLS_MASK)==XDEV_DISABLE) && !(xhci_control_flag&NO_U3_SUPER_SPEED_PORT))
			goto err_det;
	
		// case 2 : U2 Port 2 is Disabled
		if(((rtd_inl(U3_PORTSC) & (PORT_CONNECT|PORT_PE))==0) &&
			((rtd_inl(U3_COMPANY_U2_PORTSC) & PORT_PLS_MASK)==XDEV_POOLING) &&   // Port 2 enter disable state
			((rtd_inl(U3_COMPANY_U2_PORTSC) & PORT_CONNECT)==PORT_CONNECT))
			goto err_det;
	}
    return ;

err_det :
    xhci_plat_warn("xhci_check_port_status failed, run hub polling check\n");
    xhci_hub_polling_check(0);
}

#endif


#if defined(CONFIG_USER_INITCALL_USB) && !defined(MODULE)
static const struct xhci_driver_overrides xhci_plat_overrides = {
#else
static const struct xhci_driver_overrides xhci_plat_overrides __initconst = {
#endif
	.extra_priv_size = sizeof(struct xhci_hcd),
	.reset = xhci_plat_setup,
	.start = xhci_plat_start,
};


/*-----------------------------------------------------------------
 * U2 Phy Setting API
 * The USB2 Phy registers can be accessed by UTMI interface.
 *-----------------------------------------------------------------*/
static const unsigned long usb2_phy_config_reg[4] =
{
    HMAC_HOST_xhci_USB2PHYCFG0,
    HMAC_HOST_xhci_USB2PHYCFG1,
    HMAC_HOST_xhci_USB2PHYCFG2,
    HMAC_HOST_xhci_USB2PHYCFG3
};
static const unsigned long usb2_phy_vendor_ctrl_reg[4] =
{
	HMAC_HOST_xhci_GUSB2PHYACC0,
	HMAC_HOST_xhci_GUSB2PHYACC1,
	HMAC_HOST_xhci_GUSB2PHYACC2,
	HMAC_HOST_xhci_GUSB2PHYACC3
};


/*-----------------------------------------------
 * Func : _get_usb2_phy
 *
 * Desc : read usb2 phy register with UTMI
 *
 * Parm : port1     : port index (1~4)
 *        phy_reg   : phy register address
 *
 * Retn : others : phy register value
 *        -1 : failed
 *-----------------------------------------------*/
static int _get_usb2_phy(int port1, int phy_reg)
{
	int phy_value;
	unsigned long addr;

	if(port1 > 4 || port1 < 1) {
		xhci_plat_warn("get_usb2_phy failed, invalid port - %d\n", port1);
		return -1;
	}

	if (phy_reg < 0xe0 || phy_reg > 0xf7) {
		xhci_plat_warn("get_usb2_phy failed, invalid phy_reg 0x%x\n", phy_reg);
		return -1;
	}

	addr = usb2_phy_vendor_ctrl_reg[port1-1];

	rtd_outl(addr, 0x02000000 | (phy_reg & 0x0f) << 8 )  ;
	udelay(USB_PHY_DELAY);

	rtd_outl(addr, 0x02000000 | (phy_reg & 0xd0) << 4 )  ;
	udelay(USB_PHY_DELAY);

	phy_value = rtd_inl(addr) & 0xff;

	return (phy_value & 0xff);
}



/*-----------------------------------------------
 * Func : _set_usb2_phy
 *
 * Desc : set usb2 phy register with UTMI
 *
 * Parm : port1     : port index (1~4)
 *        phy_reg   : phy register address
 *        phy_value : phy register value
 *
 * Retn : 0 : successed,
 *       -1 : failed
 *-----------------------------------------------*/
static int _set_usb2_phy(int port1, int phy_reg, int phy_value) {
	int value;
	unsigned long addr;

	if(port1 > 4 || port1 < 1) {
		xhci_plat_warn("set_usb2_phy failed, invalid port - %d\n", port1);
		return -1;
	}

	if (phy_reg < 0xe0 || phy_reg > 0xf7) {
		xhci_plat_warn("get_usb2_phy failed, invalid phy_reg 0x%x\n", phy_reg);
		return -1;
	}

	addr = usb2_phy_vendor_ctrl_reg[port1-1];

	do {
        // write value
        rtd_outl(VSTATUS0_OUT_reg, VSTATUS0_OUT_p3_vstatus_out(phy_value) |
                                   VSTATUS0_OUT_p2_vstatus_out(phy_value) |
                                   VSTATUS0_OUT_p1_vstatus_out(phy_value) |
                                   VSTATUS0_OUT_p0_vstatus_out(phy_value));

		udelay(USB_PHY_DELAY);

		rtd_outl( addr , 0x02000000 | (phy_reg & 0x0f) << 8 );
		udelay(USB_PHY_DELAY);

		rtd_outl( addr , 0x02000000 | (phy_reg & 0xf0) << 4 );
		udelay(USB_PHY_DELAY);

		value = _get_usb2_phy(port1, phy_reg);

        xhci_plat_dbg("set_usb2_phy, port %d phy_reg 0x%.2x set 0x%x get 0x%x\n",
                    port1, phy_reg, phy_value & 0xff, value);

	} while (0); /* just write once */


	return value;
}



/*-----------------------------------------------
 * Func : _usb2_load_phy_setting
 *
 * Desc : load usb2 phy setting
 *
 * Parm : port1 : port index (1~4)
 *        p_reg : register list
 *        n_reg : register value
 *
 * Retn : N/A
 *-----------------------------------------------*/
void _usb2_load_phy_setting(
    unsigned char       port1,
    U2_PHY_REGISTER*    p_reg,
    unsigned int        n_reg
    )
{
    while(n_reg--)
    {
        _set_usb2_phy(port1, p_reg->addr, p_reg->val);
        p_reg++;
    }
}


/*-----------------------------------------------
 * Func : xhci_usb2_phy_init
 *
 * Desc : load usb2 phy setting
 *
 * Parm : port1 : port index (1~4)
 *        p_reg : register list
 *        n_reg : register value
 *
 * Retn : N/A
 *-----------------------------------------------*/
void xhci_usb2_phy_init(void)
{
    int i;

    xhci_plat_info("---- xhci_usb2_phy_init start ---\n");

    for (i=0; i<U2_PHY_CONFIG_COUNT; i++)
    {
            _usb2_load_phy_setting(i+1,
                    u2_phy_config[i].p_reg_table,
                    u2_phy_config[i].n_reg);
    }

    xhci_plat_info("---- xhci_usb2_phy_init complete ---\n");
}




/*-----------------------------------------------
 * Func : usb2_phy_restore
 *
 * Desc : resrote part of the phys setting phy setting
 *
 * Parm : port1 : port index (1~4)
 *        p_reg : register list
 *        n_reg : register value
 *
 * Retn : N/A
 *-----------------------------------------------*/
void usb2_phy_restore(int portnum)
{
	return;
}
EXPORT_SYMBOL_GPL(usb2_phy_restore);


int set_usb2_phy_reg(
	unsigned char       phy,
	unsigned char       page,
	unsigned char       addr,
	unsigned char       val)
{
	if (phy<1 || phy > 4)
	{
		pr_warn("set_u2_phy_reg failed, invalid phy id - %d\n", phy);
		return -1;
	}

	if (page > 3)
	{
		pr_warn("set_u2_phy_reg failed, invalid page - %d\n", page);
		return -1;
	}

	_set_usb2_phy(phy, 0xF4, (page<<5) | 0x9b);  // bit [6:5] : page select = page
	_set_usb2_phy(phy, addr, val);
	_set_usb2_phy(phy, 0xF4, 0x9b);  // bit [6:5] : page select = 0
	return 0;
}

int get_usb2_phy_reg(
	unsigned char       phy,
	unsigned char       page,
	unsigned char       addr
	)
{
	int ret;

	if (phy<1 || phy > 4)
	{
		pr_warn("set_u2_phy_reg failed, invalid phy id - %d\n", phy);
		return -1;
	}

	if (page > 3)
	{
		pr_warn("set_u2_phy_reg failed, invalid page - %d\n", page);
		return -1;
	}

	_set_usb2_phy(phy, 0xF4, (page<<5) | 0x9b);  // bit [6:5] : page select = page
	ret = _get_usb2_phy(phy, addr);
	_set_usb2_phy(phy, 0xF4, 0x9b);  // bit [6:5] : page select = 0

	return ret;
}


/*-----------------------------------------------
 * Func : xhci_usb3_phy_init
 *
 * Desc : init usb 3 phy
 *
 * Parm : N/A
 *
 * Retn : N/A
 *-----------------------------------------------*/
void xhci_usb3_phy_init(void)
{
    int i;

    xhci_plat_info("---- xhci_usb3_phy_init start ---\n");

	// Disable p3 mode. Enter p2 mode
	p3_mode_control(0);

	// Hold U3 Pipe reset
    rtd_outl(USB3_PHY_PIPE_reg, USB3_PHY_PIPE_reset_pipe3_p0(1));

    for (i=0; i < U3_PHY_SETTING_SIZE; i++)
    {
        mdio_write(xhci_u3_phy_config[i].page,
                   xhci_u3_phy_config[i].reg,
                   xhci_u3_phy_config[i].val);
    }

	// Release U3 Pipe reset
    rtd_outl(USB3_PHY_PIPE_reg, USB3_PHY_PIPE_reset_pipe3_p0(0));
	udelay(10 * USB_PHY_DELAY);

	mdio_write(0x0, 0x09, 0x325c); // set bit 9 : 1 -> 0 -> 0 will trigger one time calibration
	mdio_write(0x0, 0x09, 0x305c);
	mdio_write(0x0, 0x09, 0x325c);

	// Open PHY power
	rtd_outl(ANA_PHY0_reg, 0xe);	//////USB3_ANA_PHY//Open analog phy for usb3.0
	udelay(USB_PHY_DELAY);

    xhci_plat_info("---- xhci_usb3_phy_init complete ---\n");
}

EXPORT_SYMBOL_GPL(xhci_usb3_phy_init);




void usb3_phy_restore(void)
{
	return;
}

EXPORT_SYMBOL_GPL(usb3_phy_restore);


/*-----------------------------------------------
 * Func : xhci_usb_phy_setting
 *
 * Desc : set usb phy parameter
 *
 * Parm : N/A
 *
 * Retn : N/A
 *-----------------------------------------------*/

static void xhci_usb_phy_setting(void)
{
    unsigned long i, tmp, U2PortPara, U2PortPara2;

    for(i = 0; i <= 3; i++)
    {
        if(rtd_inl(0xb80380bc) & 0x1 || rtd_inl(0xb8038110) & 0x1)
        {
            U2PortPara =  (rtd_inl(0xb80380bc) >>(16+i*4))&0xF;
            U2PortPara2 = (rtd_inl(0xb8038110) >>(16+i*4))&0xF;
            U2PortPara |= U2PortPara2;

            xhci_plat_dbg("U2Port %d Parameter1 = 0x%x\n", i, U2PortPara);
            tmp = get_usb2_phy_reg(i+1,0x0, 0xe7);
            set_usb2_phy_reg(i+1, 0x0, 0xe7, ((U2PortPara<<4) |((~(tmp & 0xF0 ))& tmp )));
            xhci_plat_dbg("U2Port %d Read page 0 0xE7 = 0x%x\n", i, get_usb2_phy_reg(i+1,0x0, 0xe7));

        }

        if(rtd_inl(0xb80380c0)&0x1 || rtd_inl(0xb8038114)&0x1)
        {
            U2PortPara =  (rtd_inl(0xb80380c0) >>(16+i*4))&0xF;
            U2PortPara2 = (rtd_inl(0xb8038114) >>(16+i*4))&0xF;
            U2PortPara |= U2PortPara2;

            xhci_plat_dbg("U2Port %d Parameter2 = 0x%x\n", i, U2PortPara);

            tmp = get_usb2_phy_reg(i+1,0x0, 0xe4);
            set_usb2_phy_reg(i+1, 0x0, 0xe4, ((U2PortPara<<4) |((~(tmp & 0xF0 ))& tmp )));
            xhci_plat_dbg("U2Port %d Read page 0 0xE4 = 0x%x\n", i, get_usb2_phy_reg(i+1,0x0, 0xe4));
        }

    }

    for(i = 0; i <= 3; i++)
        xhci_plat_dbg("U2Port %d Read page 0 0xE7 = 0x%x\n", i, get_usb2_phy_reg(i+1,0x0, 0xe7));

    for(i = 0; i <= 3; i++)
        xhci_plat_dbg("U2Port %d Read page 0 0xE4 = 0x%x\n", i, get_usb2_phy_reg(i+1,0x0, 0xe4));


}
/*-----------------------------------------------
 * Func : xhci_usb_mac_init
 *
 * Desc : init usb mac
 *
 * Parm : N/A
 *
 * Retn : N/A
 *-----------------------------------------------*/
void xhci_usb_mac_init(void)
{
	// pull reset signal of U2 P0~P3
	rtd_outl(USB2_PHY_UTMI_reg, USB2_PHY_UTMI_reset_utmi_p0_mask |
					USB2_PHY_UTMI_reset_utmi_p1_mask |
					USB2_PHY_UTMI_reset_utmi_p2_mask |
					USB2_PHY_UTMI_reset_utmi_p3_mask);
	udelay(USB_PHY_DELAY);

	// release reset signal
	rtd_outl(USB2_PHY_UTMI_reg, 0);
	udelay(USB_PHY_DELAY);

	//USB3.0 avoid no UTMI clock //避免2.0被關掉，而導致沒clock餵給usb 3.0 (clock 從2.0餵給3.0)
	rtd_outl(USB_TMP_1_reg, USB_TMP_1_test_reg_1(1));
	udelay(USB_PHY_DELAY);


	//USB2 POW gating bit[3:0]P0~P3
	rtd_outl(ANA_PHY1_reg,  ANA_PHY1_usb2_pow_gating_p3(1)|
							ANA_PHY1_usb2_pow_gating_p2(1)|
							ANA_PHY1_usb2_pow_gating_p1(1)|
							ANA_PHY1_usb2_pow_gating_p0(1));
	udelay(USB_PHY_DELAY);



	// Disable auto-suspend
	//2. set the Synopsys data book GUSB2PHYCFG[6]=0 	Suspend USB2.0 HS/FS/LS PHY (SusPHY)
	//rtd_maskl(0xb8058200,0xffffffbf,0x00000000)
	rtd_outl(HMAC_HOST_xhci_USB2PHYCFG0, 0x00001408);
	rtd_outl(HMAC_HOST_xhci_USB2PHYCFG1, 0x00001408);
	rtd_outl(HMAC_HOST_xhci_USB2PHYCFG2, 0x00001408);
	rtd_outl(HMAC_HOST_xhci_USB2PHYCFG3, 0x00001408);

	// K3L needs disable Multi-request. Do not mark this!!!
	xhci_plat_dbg("disable multi request, bit[1]\n");
	xhci_plat_dbg("WRAP_CTR_reg= 0x%x\n", rtd_inl(WRAP_CTR_reg));
	rtd_outl(WRAP_CTR_reg , rtd_inl(WRAP_CTR_reg) | (0x1 << 1));
	xhci_plat_dbg("WRAP_CTR_reg= 0x%x\n", rtd_inl(WRAP_CTR_reg));
}

#ifdef CONFIG_USB_TYPE_C
static unsigned char current_plugin_direction = 0x0;
static void type_c_mux_select_ex(void)
{
	unsigned char plugin_direction;

	// 需讀取0xb805A144,去判斷///
	// 正插 bit[13:12] = 11, bit[5:4] = 01
	// 反差 bit[13:12] = 01, bit[5:4] = 11
	// 沒接Device bit[13:12] = 11, bit[5:4] = 11
	plugin_direction = (((rtd_inl(TC_MUX_reg) >> 12) & 0x3) << 2) | ((rtd_inl(TC_MUX_reg) >> 4) & 0x3);
	if (plugin_direction == current_plugin_direction)
		return;

	current_plugin_direction = plugin_direction;
	xhci_plat_info("[TYPE C] plugin_direction=0x%x. TC_MUX_reg=0x%x \n", plugin_direction, rtd_inl(TC_MUX_reg));
	switch (plugin_direction)
	{
		case 0xD:
			// 判斷出正插，改切Mux for TX1,RX1
			mdio_write(0x1, 0x14, 0x008b); // 008b bit[8] = 0  --> close switch
			mdio_write(0x1, 0x14, 0x008b); // 008b bit[12] = 0  --> RX1
			mdio_write(0x1, 0x18, 0x008b); // 008b bit[8] = 0 --> TX1
			mdio_write(0x1, 0x14, 0x018b); // 018b bit[8] = 1 --> open switch
			xhci_plat_info("[TYPE C] plugin direction is [forward]");
			break;
		case 0x7:
			// 判斷出反插，改切Mux for TX2,RX2
			mdio_write(0x1, 0x14, 0x008b); // 008b bit[8] = 0  --> close switch
			mdio_write(0x1, 0x14, 0x108b); // 108b bit[12] = 1  --> RX2
			mdio_write(0x1, 0x18, 0x018b); // 018b bit[8] = 1 --> TX2
			mdio_write(0x1, 0x14, 0x118b); // 118b bit[8] = 1  --> open switch
			xhci_plat_info("[TYPE C] type c plugin direction is [reverse]");
			break;
		case 0xF: // no device
			xhci_plat_info("[TYPE C] No device");
			break;
	}
	xhci_plat_dbg("[TYPE C] 340c = 0x%08x\n", mdio_read(0x1, 0x14));
	xhci_plat_dbg("[TYPE C] 380c = 0x%08x\n", mdio_read(0x1, 0x18));
}


static irqreturn_t type_c_mux_select_handler(int irq, void *dev_id, struct pt_regs *regs)
{
	if (dev_id != &type_c_dev_id)
		return IRQ_NONE;

	type_c_mux_select_ex();
	// clear CC1_flag & CC2_flag (reference: Merlin2-DesignSpec-USB::10.70)
	rtd_maskl(TC_CCDET_reg, ~(0x3<<30), 0);
	udelay(USB_PHY_DELAY);
	return IRQ_HANDLED;
}
#endif /* CONFIG_USB_TYPE_C */

static void u3_mux_select_ex(void)
{
	// 判斷出U3接頭，改切Mux for TX1,RX2
	mdio_write(0x1, 0x14, 0x008b); // 008b bit[8] = 0  --> close switch
	mdio_write(0x1, 0x14, 0x108b); // 108b bit[12] = 1  --> RX2
	mdio_write(0x1, 0x18, 0x008b); // 008b bit[8] = 0 --> TX1;
	mdio_write(0x1, 0x14, 0x1100); // 1100 bit[8] = 1  --> open switch
}

// type C mux setting.
// mode: Type c 正插 TX1  RX1
//		 Type c 反插 TX2  RX2
//		 U3		     TX1  RX2 (Currently)
static void usb3_type_c_mux_select(void)
{
#ifdef CONFIG_USB_TYPE_C
	bool is_type_c = false;
	/////判斷接頭，先切成device mode////
	mdio_write(0x1, 0x14, 0x0003);
	mdio_write(0x1, 0x11, 0x77bc);
	mdio_write(0x1, 0x15, 0x77bc);
	mdio_write(0x1, 0x14, 0x001b);
	mdio_write(0x1, 0x18, 0x001b);

//////////////////////////////////////////////真正開始判斷接頭//////////////////////////////
	// Disable interrupt output enable
	rtd_outl(TC_CCDET_reg, 0x22c58000);

	// Check bit[13:12]. All 0 is type c. TBD with HW
	switch (((rtd_inl(TC_MUX_reg)>>12) & 0x3))
	{
		case 0x0: // type c
			xhci_plat_info("Is type c\n");
			is_type_c = true;
			break;
		default:
			xhci_plat_info("unknow type: 0x%x. Force to U3\n", ((rtd_inl(TC_MUX_reg)>>12) & 0x3));
		case 0x3: // U3
			xhci_plat_info("Is U3\n");
			break;
	}

	//切回Host mode and 掛上Rp////
	mdio_write(0x1, 0x11, 0x77bf);
	mdio_write(0x1, 0x15, 0x77bf);
	mdio_write(0x1, 0x14, 0x008b);
	mdio_write(0x1, 0x18, 0x008b);

	if (is_type_c)
	{
		if (registered_type_c_irq)
			// enable de-bouding count enable,enable interrupt output enable,前面有開了
			rtd_outl(TC_CCDET_reg, 0x22C58040);
		type_c_mux_select_ex();
	}
	else
		u3_mux_select_ex();

#else   // U3 (default)
	u3_mux_select_ex();
#endif /* CONFIG_USB_TYPE_C */
	// Enable p3 mode
	p3_mode_control(1);
	xhci_plat_info("---------------  %s  complete ----------------\n", __func__);
}


static void xhci_plat_quirks(struct device *dev, struct xhci_hcd *xhci)
{
	/*
	 * As of now platform drivers don't provide MSI support so we ensure
	 * here that the generic code does not try to make a pci_dev from our
	 * dev struct in order to setup MSI
	 */
	xhci->quirks |= XHCI_BROKEN_MSI;
}

/* called during probe() after chip reset completes */
static int xhci_plat_setup(struct usb_hcd *hcd)
{
	struct device_node *of_node = hcd->self.controller->of_node;
	int ret;

	if (of_device_is_compatible(of_node, "renesas,xhci-r8a7790") ||
	    of_device_is_compatible(of_node, "renesas,xhci-r8a7791")) {
		ret = xhci_rcar_init_quirk(hcd);
		if (ret)
			return ret;
	}

	return xhci_gen_setup(hcd, xhci_plat_quirks);
}

static int xhci_plat_start(struct usb_hcd *hcd)
{
	struct device_node *of_node = hcd->self.controller->of_node;

	if (of_device_is_compatible(of_node, "renesas,xhci-r8a7790") ||
	    of_device_is_compatible(of_node, "renesas,xhci-r8a7791"))
		xhci_rcar_start(hcd);

	return xhci_run(hcd);
}

void disable_u3_phy(void)
{
	//關：(0xb805a0c4,0x0))
	//開：(0xb805a0c4,0xe))
	xhci_plat_warn("Disable U3 Phy\n");
	rtd_outl(0xb805a0c4, 0);
	rtd_outl(0xb800010C, 0x3<<1);	// 	
}


/*-----------------------------------------------
 * Func : xhci_load_config
 *
 * Desc : load configuration of xhci hcd
 *
 * Parm : N/A
 *
 * Retn : 0 : siccessed
 *-----------------------------------------------*/
static int xhci_load_config(void)
{		
	//----- for TV001 (Demo bpard) ------	
	memset(&xhci_config, 0, sizeof(xhci_config));		// reset to default value	
	xhci_config.u3_port_disabled = 0;
	xhci_config.company_u2_port = 1;	    // company u3 port = u2 port 1
	xhci_config.type_c_en = 0;
	
#ifdef CONFIG_CUSTOMER_TV006
	if (1)
	{
		if ((get_platform() == PLATFORM_KXLP) || (get_platform() == PLATFORM_KXLPP))
			xhci_config.u3_port_disabled = 1;
		else
			xhci_config.u3_port_disabled = 0;
		xhci_config.company_u2_port = 3;
		xhci_config.type_c_en = 0;
		
		XHCI_SET_PORT_VBUS_CFG(xhci_config.port_config[XHCI_U2_PORT1], 1, 1, MIS_GPIO, 78);
		XHCI_SET_PORT_VBUS_CFG(xhci_config.port_config[XHCI_U2_PORT2], 1, 1, MIS_GPIO, 79);
		XHCI_SET_PORT_VBUS_CFG(xhci_config.port_config[XHCI_U2_PORT3], 1, 1, MIS_GPIO, 80);
		XHCI_SET_PORT_VBUS_CFG(xhci_config.port_config[XHCI_U3_PORT], 1, 1, MIS_GPIO, 80);	
		
#if 0     // TODO : PinMux Setup
		rtd_outl(0xb8000850,0x0f0f0f0f0);	// Set MISC GPIO PinMux
		rtd_outl(0xb801bd08,0x0001C000);	// Set MISC GPIO DIR
		rtd_outl(0xb801bd20,0x0001C000);	// Set MISC GPIO Output
#endif		
		return 0;
	}
#endif		

	return 0;
}

#ifdef CONFIG_USB_XHCI_PLATFORM_SYSFS
int xhci_plat_rtd289x_create_sysfs_files(void* hc_data);
int xhci_plat_rtd289x_remove_sysfs_files(void* hc_data);
#else
#define xhci_plat_rtd289x_create_sysfs_files(hc_data)  ()
#define xhci_plat_rtd289x_remove_sysfs_files(hc_data)  ()
#endif

static int usb_hw_init(void)
{
	xhci_load_config();		// load xhci hc configurations

	CRT_CLK_OnOff(USB, CLK_ON, NULL);

	xhci_usb_mac_init();
	xhci_usb3_phy_init();
	xhci_usb2_phy_init();
	xhci_usb_phy_setting();

	usb3_type_c_mux_select();

	//avoid usb2.0 port enable and can't occur disconnect////XHCI RESET -> 填值-->XHCI RUN
	rtd_outl(0xb8050020,0x00000002);
	udelay(USB_PHY_DELAY);
	rtd_outl(0xb8050058,0x00000040);    // This register defines runtime xHC configuration parameters//設定64device///Operational Base+ (38h)//driver 初始設定 (因為無driver 測試用)
	rtd_outl(0xb8050020,0x00000001);    // 0xb8050020 -> 0x00000001 (default 00000000) xHCI run     ///driver 初始設定 (因為無driver,測試用，建議放入driver)
	udelay(USB_PHY_DELAY);

	return 0;
}

static int xhci_plat_probe(struct platform_device *pdev)
{
	struct device_node	*node = pdev->dev.of_node;
	struct usb_xhci_pdata	*pdata = dev_get_platdata(&pdev->dev);
	const struct hc_driver	*driver;
	struct xhci_hcd		*xhci;
	struct resource         *res;
	struct usb_hcd		*hcd;
	struct clk              *clk;
	int			ret;
	int			irq;

	if (!is_usb_clk_on())
		usb_hw_init();

#ifdef CONFIG_USB_TYPE_C
	type_c_irq = platform_get_irq(pdev, 0);
	ret = request_irq(type_c_irq, type_c_mux_select_handler, IRQF_SHARED, "typec", &type_c_dev_id);
	if (ret)
		xhci_plat_warn("[TYPE C] ret=%d Request irq:%d fail, cannot detect direction while pluging into type c device! \n", ret,  irq);
	else
		registered_type_c_irq = true;
#endif

	if (usb_disabled())
		return -ENODEV;

	driver = &xhci_plat_hc_driver;

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return -ENODEV;

	/* Try to set 64-bit DMA first */
	if (WARN_ON(!pdev->dev.dma_mask))
		/* Platform did not initialize dma_mask */
		ret = dma_coerce_mask_and_coherent(&pdev->dev,
						   DMA_BIT_MASK(64));
	else
		ret = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64));

	/* If seting 64-bit DMA mask fails, fall back to 32-bit DMA mask */
	if (ret) {
		ret = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
		if (ret)
			return ret;
	}

	hcd = usb_create_hcd(driver, &pdev->dev, dev_name(&pdev->dev));
	if (!hcd)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	hcd->regs = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(hcd->regs)) {
		ret = PTR_ERR(hcd->regs);
		goto put_hcd;
	}

	hcd->rsrc_start = res->start;
	hcd->rsrc_len = resource_size(res);
#ifndef CONFIG_ARM64  // for ARM64, always use mapped IO address
	hcd->regs = hcd->rsrc_start;
#endif

	/*
	 * Not all platforms have a clk so it is not an error if the
	 * clock does not exists.
	 */
#if 0 //mark.tseng common original code
	clk = devm_clk_get(&pdev->dev, NULL);
	if (!IS_ERR(clk)) {
		ret = clk_prepare_enable(clk);
		if (ret)
			goto put_hcd;
	}

	if (of_device_is_compatible(pdev->dev.of_node,
				    "marvell,armada-375-xhci") ||
	    of_device_is_compatible(pdev->dev.of_node,
				    "marvell,armada-380-xhci")) {
		ret = xhci_mvebu_mbus_init_quirk(pdev);
		if (ret)
			goto disable_clk;
	}
#endif


	device_wakeup_enable(hcd->self.controller);

	xhci = hcd_to_xhci(hcd);
	xhci->clk = clk;
	xhci->main_hcd = hcd;
	xhci->shared_hcd = usb_create_shared_hcd(driver, &pdev->dev,
			dev_name(&pdev->dev), hcd);
	if (!xhci->shared_hcd) {
		ret = -ENOMEM;
		goto disable_clk;
	}

	if ((node && of_property_read_bool(node, "usb3-lpm-capable")) ||
			(pdata && pdata->usb3_lpm_capable))
		xhci->quirks |= XHCI_LPM_SUPPORT;

	if (HCC_MAX_PSA(xhci->hcc_params) >= 4)
		xhci->shared_hcd->can_do_streams = 1;

	hcd->usb_phy = devm_usb_get_phy_by_phandle(&pdev->dev, "usb-phy", 0);
	if (IS_ERR(hcd->usb_phy)) {
		ret = PTR_ERR(hcd->usb_phy);
		if (ret == -EPROBE_DEFER)
			goto put_usb3_hcd;
		hcd->usb_phy = NULL;
	} else {
		ret = usb_phy_init(hcd->usb_phy);
		if (ret)
			goto put_usb3_hcd;
	}

	ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
	if (ret)
		goto disable_usb_phy;

	ret = usb_add_hcd(xhci->shared_hcd, irq, IRQF_SHARED);
	if (ret)
		goto dealloc_usb2_hcd;
#ifdef CONFIG_USB_PORT_CHECK
	setup_timer(&xhci_hub_check_timer, xhci_hub_polling_check, 0);
	mod_timer(&xhci_hub_check_timer, jiffies + msecs_to_jiffies(USB_HUB_CHECK_TIME));
	poll_check_suspend = false;
#endif

	xhci_plat_rtd289x_create_sysfs_files(xhci);
    enable_vbus_power();  // No need to do this in linux driver;
    
	/* Disable U3 PHY is the system doesn't use U3 Port.
	 * Note: 	 
	 * disable u3 phy should be called after usb_add_hcd
	 * because the xhci driver will access U3 port status 
	 * register in this function. we should disable it 
	 * after the function completed
	 */
	if (platform_has_u3_port()==0)
		disable_u3_phy();

	xhci_platform_dev = pdev;

#ifdef CONFIG_ARCH_RTK289X
	device_enable_async_suspend(&pdev->dev);
#endif

	return 0;


dealloc_usb2_hcd:
	usb_remove_hcd(hcd);

disable_usb_phy:
	usb_phy_shutdown(hcd->usb_phy);

put_usb3_hcd:
	usb_put_hcd(xhci->shared_hcd);

disable_clk:
	if (!IS_ERR(clk))
		clk_disable_unprepare(clk);

put_hcd:
	usb_put_hcd(hcd);

	return ret;
}

static int xhci_plat_remove(struct platform_device *dev)
{
	struct usb_hcd	*hcd = platform_get_drvdata(dev);
	struct xhci_hcd	*xhci = hcd_to_xhci(hcd);
	struct clk *clk = xhci->clk;

#ifdef CONFIG_USB_PORT_CHECK
	poll_check_suspend = true;
	del_timer_sync(&xhci_hub_check_timer);
	usb3_device_plugin = 0;
	port_check_count = 0;
	U3PortCnt = 0;
#endif
	xhci_plat_rtd289x_remove_sysfs_files(xhci);

	usb_remove_hcd(xhci->shared_hcd);
	usb_phy_shutdown(hcd->usb_phy);

	usb_remove_hcd(hcd);
	usb_put_hcd(xhci->shared_hcd);

	if (!IS_ERR(clk))
		clk_disable_unprepare(clk);
	usb_put_hcd(hcd);

#ifdef CONFIG_USB_TYPE_C
	// disable TC_CCDET_reg[6]: CC_det_irq_en to prevent HW interrupt
	rtd_maskl(TC_CCDET_reg, ~(0x1<<6), 0);
	free_irq(type_c_irq, &type_c_dev_id);
#endif
	xhci_platform_dev = NULL;
	return 0;
}

#ifdef CONFIG_PM_SLEEP

static int xhci_rtk_pm_freeze(struct device *dev)
{
	struct usb_hcd *hcd = dev_get_drvdata(dev);
	struct xhci_hcd *xhci = hcd_to_xhci(hcd);
	int ret = 0;

	xhci_plat_info("=================== xhci_rtk_pm_freeze ================\n");

#ifdef CONFIG_USB_PORT_CHECK
	poll_check_suspend = true;
	del_timer_sync(&xhci_hub_check_timer);
	usb3_device_plugin = 0;
	port_check_count = 0;
	U3PortCnt = 0;
#endif

#ifdef CONFIG_USB_TYPE_C
	// disable TC_CCDET_reg[6]: CC_det_irq_en to prevent HW interrupt
	rtd_maskl(TC_CCDET_reg, ~(0x1<<6), 0);
#endif

	xhci_suspend(xhci, device_may_wakeup(dev));

	return ret;
}

static int xhci_rtk_pm_thaw(struct device *dev)
{
	struct usb_hcd *hcd = dev_get_drvdata(dev);
	struct xhci_hcd	*xhci = hcd_to_xhci(hcd);

	xhci_plat_info("=================== xhci_rtk_pm_thaw ================\n");
#ifdef CONFIG_USB_TYPE_C
	if (registered_type_c_irq)
		// enable TC_CCDET_reg[6]: CC_det_irq_en to get HW interrupt
		rtd_maskl(TC_CCDET_reg, ~(0x1<<6), (0x1<<6));
#endif

	xhci_resume(xhci, false);

#ifdef CONFIG_USB_PORT_CHECK
	usb3_device_resume = 1;
	mod_timer(&xhci_hub_check_timer, jiffies + msecs_to_jiffies(USB_HUB_CHECK_TIME));
	poll_check_suspend = false;
#endif

	return 0;
}

static int xhci_rtk_pm_suspend(struct device *dev)
{
	struct usb_hcd	*hcd = dev_get_drvdata(dev);
	struct xhci_hcd	*xhci = hcd_to_xhci(hcd);
	int ret = 0;
	xhci_plat_info("=================== xhci_rtk_pm_suspend ================\n");

#ifdef CONFIG_USB_PORT_CHECK
	poll_check_suspend = true;
	del_timer_sync(&xhci_hub_check_timer);
	usb3_device_plugin = 0;
	port_check_count = 0;
	U3PortCnt = 0;
#endif
#ifdef CONFIG_USB_TYPE_C
	// disable TC_CCDET_reg[6]: CC_det_irq_en to prevent HW interrupt
	rtd_maskl(TC_CCDET_reg, ~(0x1<<6), 0);
#endif
	xhci_suspend(xhci, device_may_wakeup(dev));

	return ret;
}

static int xhci_rtk_pm_resume(struct device *dev)
{
	struct usb_hcd	*hcd = dev_get_drvdata(dev);
	struct xhci_hcd	*xhci = hcd_to_xhci(hcd);

	xhci_plat_info("=================== xhci_rtk_pm_resume ================\n");

	usb_hw_init();

	// Turn on Vbus here.
	U3PortVBusControl(1);

	xhci_resume(xhci, true);

	udelay(USB_PHY_DELAY);

	/* Disable U3 PHY if the system doesn't use U3 Port.
	 * Note:
	 * disable u3 phy should be called after xhci_resume
	 * because the xhci driver will access U3 port status
	 * register in this function. we should disable it
	 * after the function completed
	 */
	if (platform_has_u3_port()==0)
		disable_u3_phy();

#ifdef CONFIG_USB_PORT_CHECK
	usb3_device_resume = 1;
	mod_timer(&xhci_hub_check_timer, jiffies + msecs_to_jiffies(USB_HUB_CHECK_TIME));
	poll_check_suspend = false;
#endif
	return 0;
}

static int xhci_rtk_pm_resume_noirq(struct device *dev)
{
	struct usb_hcd	*hcd = dev_get_drvdata(dev);
	struct xhci_hcd	*xhci = hcd_to_xhci(hcd);

	xhci_plat_info("=================== xhci_rtk_pm_resume_noirq ================\n");

	return 0;
}

static int xhci_rtk_pm_suspend_noirq(struct device *dev)
{
	struct usb_hcd	*hcd = dev_get_drvdata(dev);
	struct xhci_hcd	*xhci = hcd_to_xhci(hcd);

	xhci_plat_info("=================== xhci_rtk_pm_suspend_noirq ================\n");

	CRT_CLK_OnOff(USB, CLK_OFF, NULL);
	U3PortVBusControl(0);
	return 0;
}

static struct dev_pm_ops const xhci_plat_pm_ops = {
       .suspend		= xhci_rtk_pm_suspend,
	   .suspend_noirq = xhci_rtk_pm_suspend_noirq,
       .resume		= xhci_rtk_pm_resume,
       .freeze		= xhci_rtk_pm_freeze,
       .thaw		= xhci_rtk_pm_thaw,
       .poweroff	= xhci_rtk_pm_suspend,
       .restore		= xhci_rtk_pm_resume,
};

#if 0 // mark.tseng common original driver code
static const struct dev_pm_ops xhci_plat_pm_ops = {
	SET_SYSTEM_SLEEP_PM_OPS(xhci_plat_suspend, xhci_plat_resume)
};
#endif

#define DEV_PM_OPS	(&xhci_plat_pm_ops)
#else
#define DEV_PM_OPS	NULL
#endif /* CONFIG_PM */


#ifdef CONFIG_OF
static const struct of_device_id usb_xhci_of_match[] = {
	{ .compatible = "generic-xhci" },
	{ .compatible = "xhci-platform" },
	{ .compatible = "realtek,xhci-hcd" },
	{ .compatible = "marvell,armada-375-xhci"},
	{ .compatible = "marvell,armada-380-xhci"},
	{ .compatible = "renesas,xhci-r8a7790"},
	{ .compatible = "renesas,xhci-r8a7791"},
	{ },
};
MODULE_DEVICE_TABLE(of, usb_xhci_of_match);
#endif

static const struct acpi_device_id usb_xhci_acpi_match[] = {
	/* XHCI-compliant USB Controller */
	{ "PNP0D10", },
	{ }
};
MODULE_DEVICE_TABLE(acpi, usb_xhci_acpi_match);

static struct platform_driver usb_xhci_driver = {
	.probe	= xhci_plat_probe,
	.remove	= xhci_plat_remove,
	.driver	= {
		.name = "xhci-hcd",
		.pm = DEV_PM_OPS,
		.of_match_table = of_match_ptr(usb_xhci_of_match),
		.acpi_match_table = ACPI_PTR(usb_xhci_acpi_match),
	},
};
MODULE_ALIAS("platform:xhci-hcd");

static int xhci_plat_init(void)
{
	xhci_init_driver(&xhci_plat_hc_driver, &xhci_plat_overrides);
	return platform_driver_register(&usb_xhci_driver);
}

#if defined(CONFIG_USER_INITCALL_USB) && !defined(MODULE)
user_initcall_grp("USB", xhci_plat_init);
module_init(usb_hw_init);
#else
module_init(xhci_plat_init);
#endif

static void __exit xhci_plat_exit(void)
{
	platform_driver_unregister(&usb_xhci_driver);
}
module_exit(xhci_plat_exit);

MODULE_DESCRIPTION("xHCI Platform Host Controller Driver");
MODULE_LICENSE("GPL");


#ifdef CONFIG_USB_XHCI_PLATFORM_SYSFS


//===========================================================================
// For : xhci control and debug interface
//===========================================================================


static ssize_t show_u2_phy_config(
	struct device*              dev,
	struct device_attribute*    attr,
	char*                       buf
	)
{
	int  n;
	int  count = PAGE_SIZE;
	char *ptr = buf;
	int  i = 0;
	int  ret;
	unsigned int phy_id;

	if (sscanf(attr->attr.name, "u2_phy%d_config", &phy_id)!=1 || phy_id < 1 || phy_id > 4)
	{
		pr_warn("show_u2_phy_config failed, get phy id failed\n");
		return 0;
	}

	for (i =0; i< sizeof(u2_phy_reg_table)/sizeof(U2_PHY_REG) ; i++)
	{
		ret = get_usb2_phy_reg(phy_id,
				u2_phy_reg_table[i].page,
				u2_phy_reg_table[i].addr);

		if (ret<0)
			continue;

		n = scnprintf(ptr, count, "%X-%02X = 0x%02X | ",
				u2_phy_reg_table[i].page,
				u2_phy_reg_table[i].addr,
				ret);
		ptr   += n;
		count -= n;

		switch (u2_phy_reg_table[i].page)
		{
		case 0:
			switch(u2_phy_reg_table[i].addr)
			{
			case 0xE0:
				n = scnprintf(ptr, count, "z0_adjust[5:2]=%x",
					(ret >> 2) & 0xF);
				ptr   += n;
				count -= n;
				break;

			case 0xE4:
				n = scnprintf(ptr, count, "disconnect_level[7:4]=%x, tx_swing[3:0]=%x",
								(ret>>4) & 0xF, ret & 0xF);
				ptr   += n;
				count -= n;
				break;

			case 0xE6:
				n = scnprintf(ptr, count, "LF_mode_tx_slew_rate[2]=%x, rx_gain_boost[1:0]=%x",
								(ret>>2) & 0x1, ret & 0x3);
				ptr   += n;
				count -= n;
				break;

			case 0xE7:
				n = scnprintf(ptr, count, "squalsh_level[7:4]=%x",
								(ret>>4) & 0xF);
				ptr   += n;
				count -= n;
				break;
			case 0xF0:
				n = scnprintf(ptr, count, "discon_enable[7]=%x",
								(ret>>7) & 0x1);
				ptr   += n;
				count -= n;
				break;

			case 0xF1:
				n = scnprintf(ptr, count, "tx_delay[2:1]=%x",
								(ret>>1) & 0x3);
				ptr   += n;
				count -= n;
				break;
			}
			break;

		case 1:

			if (u2_phy_reg_table[i].addr==0xE1)
			{
				n = scnprintf(ptr, count, "slew_rate[6:4]=%x",
					(ret >> 4) & 7);
				ptr   += n;
				count -= n;
			}
			break;
		}

		n = scnprintf(ptr, count, "\n");
		ptr   += n;
		count -= n;
	}

	return ptr - buf;
}


static ssize_t store_u2_phy_config(
	struct device*	dev,
	struct device_attribute *attr,
	const char *	buf,
	size_t			count)
{
	unsigned int phy_id;
	unsigned int page;
	unsigned int addr;
	unsigned int val;

	if (sscanf(attr->attr.name, "u2_phy%d_config", &phy_id)!=1 || phy_id < 1 || phy_id > 4)
	{
		pr_warn("show_u2_phy_config failed, get phy id failed\n");
		goto end_proc;
	}

	if (sscanf(buf, "%x-%x=%x\n", &page, &addr, &val)==3)
	{
		if ((addr>=0xE0 && addr<=0xE7 && page <2) ||
			(addr>=0xF0 && addr<=0xF7 && page==0))
		{
			set_usb2_phy_reg(phy_id, page, addr, val);
		}
		else
		{
			pr_warn("store_u2_phy_config failed, invalid register address\n");
			goto end_proc;
		}
	}
	else
	{
		pr_warn("store_u2_phy_config failed, unknown command - %s\n", buf);
	}

end_proc:
	return count;
}

static DEVICE_ATTR(u2_phy1_config, 0644, show_u2_phy_config, store_u2_phy_config);
static DEVICE_ATTR(u2_phy2_config, 0644, show_u2_phy_config, store_u2_phy_config);
static DEVICE_ATTR(u2_phy3_config, 0644, show_u2_phy_config, store_u2_phy_config);
static DEVICE_ATTR(u2_phy4_config, 0644, show_u2_phy_config, store_u2_phy_config);



//===========================================================================
// Func : xhci_plat_create_sysfs_files
//===========================================================================
//



static ssize_t show_u3_phy1_config(
    struct device*              dev,
    struct device_attribute*    attr,
    char*                       buf
    )
{
	int  count = PAGE_SIZE;
	char *ptr = buf;
	int  i;
	int  n;

	for (i=0; i<=0x30; i++)
	{
		unsigned short val = mdio_read(i>>5, i&0x1F);
		n = scnprintf(ptr, count, "%d-%02X = 0x%04X | ",
				i>>5, i&0x1F, val);
		ptr   += n;
		count -= n;

		switch (i)
		{
		case 0x1:
			n =	scnprintf(ptr, count, "rx_ki[8:6]=%x, rx_kp[5:1]=%x\n",
				(val>>6)&0x7, (val>>1)&0xF);
			break;

		case 0x4:
			n =	scnprintf(ptr, count, "ssc_en[13]=%x\n",
				(val>>13)&0x1);
			break;

		case 0xa:
			n =	scnprintf(ptr, count, "rx_eq_gain[8:7]=%x\n",
				(val>>7)&0x3);
			break;

		case 0x19:
			n =	scnprintf(ptr, count, "rx_eq[15:11]=%x\n",
				(val>>11)&0x1F);
			break;

		case 0x20:
			n =	scnprintf(ptr, count, "tx_amp[3:0]=%x\n",
				(val>>0)&0xF);
			break;

		case 0x21:
			n =	scnprintf(ptr, count, "tx_deemp[15:12]=%x, tx_deemp_1[7:4]=%x\n",
				(val>>12)&0xF, (val>>4)&0xF);
			break;

		case 0x22:
			n =	scnprintf(ptr, count, "tx_deemp_en[15:6]=%x\n",
				(val>>6)&0x3FF);
			break;

		case 0x26:
			n =	scnprintf(ptr, count, "rx_eq_dc_gain[1:0]=%x\n",
				val	& 0x3);
			break;

		default:
			n =	scnprintf(ptr, count, "\n");
			break;
		}
		ptr   += n;
		count -= n;
	}

	return ptr - buf;
}

static ssize_t store_u3_phy1_config(
	struct device*	dev,
	struct device_attribute *attr,
	const char *	buf,
	size_t 		count)
{
	unsigned int page;
	unsigned int addr;
	unsigned int val;

	//pr_debug("store_xhci_config : buff=%s, count=%d, attr.name=%s, (busnum=%d)\n", buf, count, attr->attr.name, xhci_to_hcd(xhci)->self.busnum);

	if (sscanf(buf, "%x-%x=%x\n", &page, &addr, &val)==3)
	{
		//pr_debug("page = %d, addr=%02x, val=%02x\n", page, addr, val);
		mdio_write(page, addr, val);
	}
	else
	{
		pr_warn("store_u3_phy1_config failed, unknown command - %s\n", buf);
	}

	return count;
}

static DEVICE_ATTR(u3_phy1_config, 0644, show_u3_phy1_config, store_u3_phy1_config);


//===========================================================================
// Func : show_xhci_port_status
//===========================================================================
static ssize_t show_xhci_get_port_status_str(
	struct device*              dev,
	struct device_attribute*    attr,
	char*                       buf
	)
{		
	return _xhci_get_port_status_str(buf, PAGE_SIZE);
}



static DEVICE_ATTR(port_status, 0444, show_xhci_get_port_status_str, NULL);




//===========================================================================
// Func : show_xhci_debug_control
//===========================================================================
static ssize_t show_xhci_debug_control(
    struct device*              dev,
    struct device_attribute*    attr,
    char*                       buf
    )
{
	XHCI_PORT_GPIO* p_gpio;
	int  n;
	int	 count = PAGE_SIZE;
	char *ptr = buf;

	n = scnprintf(ptr, count, "no_u3_port_auto_recover=%x\n", (xhci_control_flag & NO_U3_PORT_AUTO_RECOVER) ? 1 : 0);
	ptr   += n;
	count -= n;

	n = scnprintf(ptr, count, "no_restore_u3_phy=%x\n", (xhci_control_flag & NO_RESTORE_U3_PHY) ? 1 : 0);
	ptr   += n;
	count -= n;

	n = scnprintf(ptr, count, "no_restore_u2_phy=%x\n", (xhci_control_flag & NO_RESTORE_U2_PHY) ? 1 : 0);
	ptr   += n;
	count -= n;

	n = scnprintf(ptr, count, "no_u3_super_speed_port=%x\n", (xhci_control_flag & NO_U3_SUPER_SPEED_PORT) ? 1 : 0);
	ptr   += n;
	count -= n;

	p_gpio = _xhci_get_vbus_gpio(XHCI_U3_PORT);

	if (p_gpio) {
		n = scnprintf(ptr, count, "u3_port_vbus_pin=%s_%d\n",
		        gpio_type(gpio_group(p_gpio->gid)),
		        gpio_idx(p_gpio->gid));
		ptr   += n;
		count -= n;			
	}
	else {
		n = scnprintf(ptr, count, "u3_port_vbus_pin=n/a\n");
		ptr   += n;
		count -= n;			
	}
	
	n = scnprintf(ptr, count, "u3_port_vbus=%d\n", U3PortVBusStatus());
	ptr   += n;
	count -= n;	

	n = scnprintf(ptr, count, "compliance_mode=%x\n", ((rtd_inl(HMAC_HOST_xhci_portsc_usb3_start_reg) == 0x0A010340) && (rtd_inl(MDIO_CTR_reg) == 0xA03E1d0d)) ? 1 : 0);
	pr_warn("rtd_inl(0x%x) = 0x%x, rtd_inl(0x%x) = 0x%x\n", HMAC_HOST_xhci_portsc_usb3_start_reg, rtd_inl(HMAC_HOST_xhci_portsc_usb3_start_reg), MDIO_CTR_reg, rtd_inl(MDIO_CTR_reg));
	ptr   += n;
	count -= n;

	n = scnprintf(ptr, count, "crc_src=%x (%s)\n",
	    CRC_CNT_1_get_Crc_cnt_sel(rtd_inl(CRC_CNT_1_reg)),
	    xhci_crc_error_src(CRC_CNT_1_get_Crc_cnt_sel(rtd_inl(CRC_CNT_1_reg))));
	ptr   += n;
	count -= n;

#if defined(CONFIG_USER_INITCALL_USB) && !defined(MODULE)
	n = scnprintf(ptr, count, "user_initcalls=%d\n", get_user_initcall_status());
	ptr   += n;
	count -= n;
#endif

	return ptr - buf;
}


static ssize_t store_xhci_debug_control(struct device *dev,
			       struct device_attribute *attr,
			       const char *buf, size_t count)
{
	int val;

	if (sscanf(buf, "no_restore_u3_phy=%x\n", &val)==1)
	{
        if (val)
            xhci_control_flag |= NO_RESTORE_U3_PHY;
        else
            xhci_control_flag &= ~NO_RESTORE_U3_PHY;
	}
	else if (sscanf(buf, "no_u3_port_auto_recover=%x\n", &val)==1)
	{
        if (val)
            xhci_control_flag |= NO_U3_PORT_AUTO_RECOVER;
        else
            xhci_control_flag &= ~NO_U3_PORT_AUTO_RECOVER;
	}
	else if (sscanf(buf, "no_restore_u2_phy=%x\n", &val)==1)
	{
        if (val)
            xhci_control_flag |= NO_RESTORE_U2_PHY;
        else
            xhci_control_flag &= ~NO_RESTORE_U2_PHY;
	}
	else if (sscanf(buf, "no_u3_super_speed_port=%x\n", &val) == 1)
	{
		if (val)
		{
            xhci_control_flag |= NO_U3_SUPER_SPEED_PORT;
			rtd_clearbits(U3_PORTSC, PORT_POWER); // disable U3 port power
		}
		else
		{
            xhci_control_flag &= ~NO_U3_SUPER_SPEED_PORT;
			rtd_setbits(U3_PORTSC, PORT_POWER); // enable U3 port power
		}
	}
	else if (sscanf(buf, "compliance_mode=%x\n", &val)==1)
	{
		if (val) {
			rtd_outl(HMAC_HOST_xhci_portsc_usb3_start_reg, 0x0A010340);
			udelay(USB_PHY_DELAY);
			mdio_write(0x0, 0x1d, 0xA03E);  /* for BER off */
			pr_warn("Please insert SMA Cable.....\n");
		} else {
			pr_warn("Need to restart xhci to exit compliance mode\n");
		}
	}
	else if (sscanf(buf, "crc_src=%x\n", &val)==1)
	{
		switch(val) {
		case CRC_SRC_NONE:
			rtd_outl(CRC_CNT_1_reg, 0);
			break;
		case CRC_SRC_U3_PORT:
		case CRC_SRC_U2_PORT0_0:
		case CRC_SRC_U2_PORT0:
		case CRC_SRC_U2_PORT1:
		case CRC_SRC_U2_PORT2:
		case CRC_SRC_U2_PORT3:
			rtd_outl(CRC_CNT_1_reg, CRC_CNT_1_Crc_cnt_sel(val) |
						CRC_CNT_1_Crc_cnt_rst(1) |
						CRC_CNT_1_Crc_cnt_en(1));

			rtd_outl(CRC_CNT_1_reg, CRC_CNT_1_Crc_cnt_sel(val) |
						CRC_CNT_1_Crc_cnt_rst(0) |
						CRC_CNT_1_Crc_cnt_en(1));
			xhci_plat_info("crc_src=%d (%s)\n", val, xhci_crc_error_src(val));
			break;

		default:
			pr_warn("crc_src to restart xhci to exit compliance mode\n");
		}
	}
	else
	{
		pr_warn("store_xhci_debug_control failed, unknown command - %s\n", buf);
	}
	return count;
}

static DEVICE_ATTR(debug_control, 0644, show_xhci_debug_control, store_xhci_debug_control);


static int xhci_sysfs_ready = 0;

//===========================================================================
// Func : xhci_plat_create_sysfs_files
//===========================================================================
int xhci_plat_rtd289x_create_sysfs_files(void* hc_data)
{
	struct xhci_hcd *xhci = (struct xhci_hcd *) hc_data;
	struct device *controller = xhci_to_hcd(xhci)->self.controller;

	if (xhci_sysfs_ready)
	    return 0;

	device_create_file(controller, &dev_attr_u2_phy1_config);
	device_create_file(controller, &dev_attr_u2_phy2_config);
	device_create_file(controller, &dev_attr_u2_phy3_config);
	device_create_file(controller, &dev_attr_u2_phy4_config);
	device_create_file(controller, &dev_attr_u3_phy1_config);
	device_create_file(controller, &dev_attr_port_status);
	device_create_file(controller, &dev_attr_debug_control);
	xhci_sysfs_ready = 1;
	return 0;
}

int xhci_plat_rtd289x_remove_sysfs_files(void* hc_data)
{
	struct xhci_hcd *xhci = (struct xhci_hcd *) hc_data;
	struct device *controller = xhci_to_hcd(xhci)->self.controller;

	if (!xhci_sysfs_ready)
	    return 0;

	device_remove_file(controller, &dev_attr_u2_phy1_config);
	device_remove_file(controller, &dev_attr_u2_phy2_config);
	device_remove_file(controller, &dev_attr_u2_phy3_config);
	device_remove_file(controller, &dev_attr_u2_phy4_config);
	device_remove_file(controller, &dev_attr_u3_phy1_config);
	device_remove_file(controller, &dev_attr_port_status);
	device_remove_file(controller, &dev_attr_debug_control);
	xhci_sysfs_ready = 0;
	return 0;
}

#endif

struct platform_device *get_hci_platform_device(void)
{
	return xhci_platform_dev;
}
EXPORT_SYMBOL(get_hci_platform_device);
