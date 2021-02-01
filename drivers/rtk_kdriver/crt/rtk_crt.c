/*
 *  linux/arch/arm/mach-rtd299s/rtk_crt.c
 *
 *  Copyright (C) 2015 Realtek
 *  All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/delay.h>
#include <linux/printk.h>
#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/spinlock.h>
#include <linux/platform_device.h>
#include <linux/hardirq.h>
#include <asm/uaccess.h>

#include <rbus/sb2_reg.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/plletn_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/stb_reg.h>
#include <rbus/usb_top_reg.h>
#include <mach/system.h>
//#include <mach/io.h>
#include <rtk_kdriver/rtk_crt.h>

#include <tvscalercontrol/vdc/video.h>
#include <rbus/vdtop_reg.h>

/* rtk_crt char device variable */
int crt_major 		= CRT_MAJOR;
int crt_minor 		= 0;
int crt_nr_devs 	= CRT_NR_DEVS;
dev_t crt_devnum;
static struct class *crt_class;
static struct kobject *crt_kobj;
struct cdev crt_cdev;
spinlock_t crt_lock;
char moduleName[32];
char lastModuleName[32];

static unsigned int register_addr, register_val = 0;
static unsigned int register_password = 0;
static struct device *crt_device;
static struct platform_device *crt_platform_devs;

#define func_trace()    printk("%s:%d:%s\n", __FILE__, __LINE__, __FUNCTION__)

unsigned int rtd_hwsem_user[1];

/* Notice: this API is semantically diff from hw_semaphore_try_lock.
* return 1: get lock
* return 0: not get lock.
*/
int rtd_hwsem_1_trylock(void)
{
	int ret;
	ret =  (*(unsigned int volatile *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_4_reg));
#if !defined (RTD_SWSEM_DEBUG_DISABLE)
	if (ret == 1)
		rtd_hwsem_user[0] = __builtin_return_address(0);
#endif //#if !defined (RTD_SWSEM_DEBUG_DISABLE)

	return ret;
}


void rtd_hwsem_1_lock(void)
{
	while (!rtd_hwsem_1_trylock()) {
		udelay(1);
	}
	rtd_hwsem_user[0] = __builtin_return_address(0);
}

void rtd_hwsem_1_unlock(void)
{
	*(unsigned int volatile *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_4_reg) = 0;
#if !defined (RTD_SWSEM_DEBUG_DISABLE)
	rtd_hwsem_user[0] = 0;
#endif //#if !defined (RTD_SWSEM_DEBUG_DISABLE)
	dsb(sy);

}

#if !defined (SB2_SHADOW_1)
#error "need define a dummy register for SW semaphore"
#endif
#define RD_SWSEM_REG          SB2_SHADOW_1_reg

DEFINE_SPINLOCK(pll27x3_lock); 
DEFINE_SPINLOCK(avdin_lock); 

unsigned int rtd_swsem_user[32];
int rtd_swsem_debug;  //sysctl used 

int rtd_swsem_debug_func(void)
{
	int i;
	for(i=0; i<32; i++) {
		printk(KERN_EMERG "user: %pF \n", rtd_swsem_user[i]);
	}

	return 0;
}

/**
   return 0: unlocked.
   return 1: get lock
**/
inline int rtd_crt_swsem_trylock(int bit)
{
          int swsem;
          int ret;

          if (!rtd_hwsem_1_trylock())
                    return 0;

          swsem = rtd_inl(RD_SWSEM_REG) & bit;
          if (swsem != 0) {
                    ret = 0;
                    goto bad;
          }

          rtd_setbits(RD_SWSEM_REG, bit); // lock
#if !defined (RTD_SWSEM_DEBUG_DISABLE)
	  rtd_swsem_user[__builtin_ctz(bit)] = __builtin_return_address(0);
#endif //#if !defined (RTD_SWSEM_DEBUG_DISABLE)
	  
          ret = 1;
bad:
          rtd_hwsem_1_unlock();

          return ret;
}

void rtd_crt_swsem_lock(int bit)
{
          int retry = 0;

          while (!rtd_crt_swsem_trylock(bit)) {
#if !defined (RTD_SWSEM_DEBUG_DISABLE)		  
		  if (retry++ == 0x100000) {
			  rtd_swsem_debug_func();
		  }
#endif //#if !defined (RTD_SWSEM_DEBUG_DISABLE)		  
          }
	  rtd_swsem_user[__builtin_ctz(bit)] = __builtin_return_address(0);
}

void rtd_crt_swsem_unlock(int bit)
{
          rtd_hwsem_1_lock();

          rtd_clearbits(RD_SWSEM_REG, bit); //
	  
#if !defined (RTD_SWSEM_DEBUG_DISABLE)
	  rtd_swsem_user[__builtin_ctz(bit)] = 0;
#endif //#if !defined (RTD_SWSEM_DEBUG_DISABLE)

          rtd_hwsem_1_unlock();
}


#if 0
inline void vdc_hw_semaphore_lock(void)
{
	unsigned char ucTime = 0;
	/* 0xb801a624 */
	while (!*(unsigned int volatile *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_1_reg)) {
		if (ucTime == 0) {
			ucTime ++;
			pr_err("#@# %s wait SB2_HD_SEM_NEW_1_reg ready\n", moduleName);
			pr_err("#@# last %s used SB2_HD_SEM_NEW_1_reg semaphore\n", lastModuleName);
		}
//		udelay(20);
	}
}

inline unsigned char vdc_hw_semaphore_try_lock(void)
{
	/* 0xb801a624 */
	if (!*(unsigned int volatile *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_1_reg)) {
		pr_err("#@# %s SB2_HD_SEM_NEW_1_reg try lock, return FAIL\n", moduleName);
		return 0;	// _FAIL
	}
	return 1;	// _SUCCESS
}


inline void vdc_hw_semaphore_unlock(void)
{
	/* 0xb801a624 */
	*(unsigned int volatile *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_1_reg) = 0;
//	udelay(10);
}
#endif //#if 0

void hw_semaphore_try_lock(void)
{
#if 0
	while (!*(unsigned int volatile *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_5_reg)) {
		pr_err("#@# %s wait SB2_HD_SEM_NEW_5_reg ready\n", moduleName);
		pr_err("#@# last %s used SB2_HD_SEM_NEW_5_reg semaphore\n", lastModuleName);
		mdelay(20);
	}
#endif
}

void hw_semaphore_unlock(void)
{
#if 0
	*(unsigned int volatile *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_5_reg) = 0;
	udelay(10);
#endif
}

#if 0
static void rtd_part_outl(unsigned int reg_addr, unsigned int endBit, unsigned int startBit, unsigned int value)
{
	unsigned int X,A,result;
	X=(1<<(endBit-startBit+1))-1;
	A=rtd_inl(reg_addr);
	result = (A & (~(X<<startBit))) | (value<<startBit);
	rtd_outl(reg_addr,result);
}
#endif

int APLL_ADC_clock(enum CRT_CLK clken)
{
	if (CLK_ON == clken) {
		if (((rtd_inl(SYS_REG_SYS_SRST1_reg)&SYS_REG_SYS_SRST1_rstn_apll_adc_mask) != 0) &&
			((rtd_inl(SYS_REG_SYS_CLKEN1_reg)&SYS_REG_SYS_CLKEN1_clken_apll_adc_mask) != 0))
			return CRT_SUCCESS;
	}

	hw_semaphore_try_lock();
	if (CLK_ON == clken) {
		if (((rtd_inl(SYS_REG_SYS_SRST1_reg)&SYS_REG_SYS_SRST1_rstn_apll_adc_mask) == 0) ||
			((rtd_inl(SYS_REG_SYS_CLKEN1_reg)&SYS_REG_SYS_CLKEN1_clken_apll_adc_mask) == 0)) {
			rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_apll_adc_mask | SYS_REG_SYS_SRST1_write_data_mask);
			rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_apll_adc_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
		}
	}
	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

#ifdef CONFIG_USB
int USB_CriticalRegister(enum CRT_CLK clken, void *private_data)
{
	int usb_version = (int)private_data;

	if (!usb_version)
		return CRT_FAIL;

	hw_semaphore_try_lock();
#define USB_PHY_DELAY	100
	if (CLK_ON == clken) {
		switch (usb_version) {
		case 2:
			// disable interrupt
			rtd_outl(SYS_REG_INT_CTRL_SCPU_reg,
					SYS_REG_INT_CTRL_SCPU_usb2_int_scpu_routing_en_mask |
					SYS_REG_INT_CTRL_SCPU_write_data(0));
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
			rtd_outl(SYS_REG_INT_CTRL_SCPU_2_reg,
					SYS_REG_INT_CTRL_SCPU_2_usb2_ex_int_scpu_routing_en_mask |
					SYS_REG_INT_CTRL_SCPU_2_write_data(0));
#endif
			/*---------------------------------------------------
			* shutdown sequence :
			*  1. mac clock off
			*  2. not release mac reset
			*  3. not release phy reset
			*---------------------------------------------------*/
			// clock off : USB MAC
			rtd_outl(SYS_REG_SYS_CLKEN2_reg,
						SYS_REG_SYS_CLKEN2_clken_usb2_mask |
						SYS_REG_SYS_CLKEN2_write_data(0));
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
			rtd_outl(SYS_REG_SYS_CLKEN2_reg,
						SYS_REG_SYS_CLKEN2_clken_usb2_ex_mask |
						SYS_REG_SYS_CLKEN2_write_data(0));
#endif
			udelay(USB_PHY_DELAY);

			// not release mac reset
			rtd_outl(SYS_REG_SYS_SRST2_reg,
						SYS_REG_SYS_SRST2_rstn_usb2_mask |
						SYS_REG_SYS_SRST2_write_data(0));
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
			rtd_outl(SYS_REG_SYS_SRST2_reg,
						SYS_REG_SYS_SRST2_rstn_usb2_ex_mask |
						SYS_REG_SYS_SRST2_write_data(0));
#endif
			udelay(USB_PHY_DELAY);

			// not release phy reset
			rtd_outl(SYS_REG_SYS_SRST3_reg,
						SYS_REG_SYS_SRST3_rstn_usb2_phy_p0_mask |
						SYS_REG_SYS_SRST3_rstn_usb2_phy_p1_mask |
						SYS_REG_SYS_SRST3_write_data(0));
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
			rtd_outl(SYS_REG_SYS_SRST3_reg,
						SYS_REG_SYS_SRST3_rstn_usb2_phy_p2_mask |
						SYS_REG_SYS_SRST3_write_data(0));
#endif
			udelay(USB_PHY_DELAY);

			/*---------------------------------------------------
			* init sequence :
			*  1. mac reset release
			*  2. mac clock on
			*---------------------------------------------------*/

			// Release USB MAC Reset
			rtd_outl(SYS_REG_SYS_SRST2_reg,
						SYS_REG_SYS_SRST2_rstn_usb2_mask |
						SYS_REG_SYS_SRST2_write_data(1));
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
			rtd_outl(SYS_REG_SYS_SRST2_reg,
						SYS_REG_SYS_SRST2_rstn_usb2_ex_mask |
						SYS_REG_SYS_SRST2_write_data(1));
#endif
			udelay(USB_PHY_DELAY);

			// clock on : USB MAC
			rtd_outl(SYS_REG_SYS_CLKEN2_reg,
						SYS_REG_SYS_CLKEN2_clken_usb2_mask |
						SYS_REG_SYS_CLKEN2_write_data(1));
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
			rtd_outl(SYS_REG_SYS_CLKEN2_reg,
						SYS_REG_SYS_CLKEN2_clken_usb2_ex_mask |
						SYS_REG_SYS_CLKEN2_write_data(1));
#endif
			udelay(USB_PHY_DELAY);

			// enable interrupt
			rtd_outl(SYS_REG_INT_CTRL_SCPU_reg,
					SYS_REG_INT_CTRL_SCPU_usb2_int_scpu_routing_en_mask |
					SYS_REG_INT_CTRL_SCPU_write_data(1));
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
			rtd_outl(SYS_REG_INT_CTRL_SCPU_2_reg,
					SYS_REG_INT_CTRL_SCPU_2_usb2_ex_int_scpu_routing_en_mask |
					SYS_REG_INT_CTRL_SCPU_2_write_data(1));
#endif

			udelay(USB_PHY_DELAY);
			break;
		default:
			hw_semaphore_unlock();
			return CRT_FAIL;
		}
	} else {
		switch (usb_version) {
		case 2:
			// disable interrupt
			rtd_outl(SYS_REG_INT_CTRL_SCPU_reg,
					SYS_REG_INT_CTRL_SCPU_usb2_int_scpu_routing_en_mask |
					SYS_REG_INT_CTRL_SCPU_write_data(0));
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
			rtd_outl(SYS_REG_INT_CTRL_SCPU_2_reg,
					SYS_REG_INT_CTRL_SCPU_2_usb2_ex_int_scpu_routing_en_mask |
					SYS_REG_INT_CTRL_SCPU_2_write_data(0));
#endif
			udelay(USB_PHY_DELAY);

			/*---------------------------------------------------
			* shutdown sequence :
			*  1. mac clock off
			*  2. not release mac reset
			*  3. not release phy reset
			*---------------------------------------------------*/

			// clock off : USB MAC
			rtd_outl(SYS_REG_SYS_CLKEN2_reg,
						SYS_REG_SYS_CLKEN2_clken_usb2_mask |
						SYS_REG_SYS_CLKEN2_write_data(0));
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
			rtd_outl(SYS_REG_SYS_CLKEN2_reg,
						SYS_REG_SYS_CLKEN2_clken_usb2_ex_mask |
						SYS_REG_SYS_CLKEN2_write_data(0));
#endif
			udelay(USB_PHY_DELAY);

			// not release mac reset
			rtd_outl(SYS_REG_SYS_SRST2_reg,
						SYS_REG_SYS_SRST2_rstn_usb2_mask |
						SYS_REG_SYS_SRST2_write_data(0));
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
			rtd_outl(SYS_REG_SYS_SRST2_reg,
						SYS_REG_SYS_SRST2_rstn_usb2_ex_mask |
						SYS_REG_SYS_SRST2_write_data(0));
#endif
			udelay(USB_PHY_DELAY);

			// not release phy reset
			rtd_outl(SYS_REG_SYS_SRST3_reg,
						SYS_REG_SYS_SRST3_rstn_usb2_phy_p0_mask |
						SYS_REG_SYS_SRST3_rstn_usb2_phy_p1_mask |
						SYS_REG_SYS_SRST3_write_data(0));
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
			rtd_outl(SYS_REG_SYS_SRST3_reg,
						SYS_REG_SYS_SRST3_rstn_usb2_phy_p2_mask |
						SYS_REG_SYS_SRST3_write_data(0));
#endif
			udelay(USB_PHY_DELAY);
			break;
		default:
			hw_semaphore_unlock();
			return CRT_FAIL;
		}
	}
#undef USB_PHY_DELAY
	hw_semaphore_unlock();
	return CRT_SUCCESS;
}
#endif

int IrDA_CriticalRegister(enum CRT_CLK clken, void *private_data)
{
	hw_semaphore_try_lock();

	if (clken == CLK_ON) {
		/* HW mode */
		rtd_outl(STB_ST_CLKEN1_reg, BIT(STB_ST_CLKEN1_clken_irda_shift));   //clken_irda:0
		rtd_outl(STB_ST_SRST1_reg, BIT(STB_ST_SRST1_rstn_irda_shift));    //RSTN_irda:0
		rtd_outl(STB_ST_CLKEN1_reg, BIT(STB_ST_CLKEN1_clken_irda_shift) | STB_ST_CLKEN1_write_data_mask);   	//clken_irda:1
		rtd_outl(STB_ST_CLKEN1_reg, BIT(STB_ST_CLKEN1_clken_irda_shift));   //clken_irda:0
		rtd_outl(STB_ST_SRST1_reg, BIT(STB_ST_SRST1_rstn_irda_shift) | STB_ST_SRST1_write_data_mask);    	//RSTN_irda:1
		rtd_outl(STB_ST_CLKEN1_reg, BIT(STB_ST_CLKEN1_clken_irda_shift) | STB_ST_CLKEN1_write_data_mask);   	//clken_irda:1
		rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_iso_misc_shift) | STB_ST_CLKEN0_write_data_mask); // ISO_MISC clock
		rtd_outl(STB_ST_SRST0_reg, BIT(STB_ST_SRST0_rstn_iso_misc_shift) | STB_ST_SRST0_write_data_mask);  // ISO_MISC reset

		/* RAW mode */
		rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_irda_off_shift));   //clken_irda_off:0
		rtd_outl(STB_ST_SRST0_reg, BIT(STB_ST_SRST0_rstn_irda_off_shift));    //RSTN_irda_off:0
		rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_irda_off_shift) | STB_ST_CLKEN0_write_data_mask);   	//clken_irda_off:1
		rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_irda_off_shift));   //clken_irda_off:0
		rtd_outl(STB_ST_SRST0_reg, BIT(STB_ST_SRST0_rstn_irda_off_shift) | STB_ST_SRST0_write_data_mask);    	//RSTN_irda_off:1
		rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_irda_off_shift) | STB_ST_CLKEN0_write_data_mask);   	//clken_irda_off:1
		rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_iso_misc_off_shift) | STB_ST_CLKEN0_write_data_mask); // ISO_MISC_OFF clock
		rtd_outl(STB_ST_SRST0_reg, BIT(STB_ST_SRST0_rstn_iso_misc_off_shift) | STB_ST_SRST0_write_data_mask);  // ISO_MISC_OFF reset
	} else {
		/* HW mode */
		rtd_outl(STB_ST_SRST1_reg, BIT(STB_ST_SRST1_rstn_irda_shift) | STB_ST_SRST1_write_data_mask);  // ISO_MISC_IRDA reset
		/* RAW mode */
		rtd_outl(STB_ST_SRST0_reg, BIT(STB_ST_SRST0_rstn_irda_off_shift) | STB_ST_SRST0_write_data_mask);  // ISO_MISC_OFF reset
	}

	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int I2C_CriticalRegister(enum CRT_CLK clken , void *private_data)
{
	int i2c_phy = *(int *)private_data;

	hw_semaphore_try_lock();

	if (clken == CLK_ON) {
		if (i2c_phy & BIT(0)) {
			rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_i2c0_off_shift));
			rtd_outl(STB_ST_SRST0_reg, BIT(STB_ST_SRST0_rstn_i2c0_off_shift));
			rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_i2c0_off_shift)| BIT(STB_ST_CLKEN0_write_data_shift));
			rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_i2c0_off_shift));
			rtd_outl(STB_ST_SRST0_reg, BIT(STB_ST_SRST0_rstn_i2c0_off_shift)| BIT(STB_ST_SRST0_write_data_shift));
			rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_i2c0_off_shift)| BIT(STB_ST_CLKEN0_write_data_shift));
		}
		if (i2c_phy & BIT(1)) {
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c1_shift));
			rtd_outl(SYS_REG_SYS_SRST2_reg, BIT(SYS_REG_SYS_SRST2_rstn_i2c1_shift));
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c1_shift)| BIT(SYS_REG_SYS_CLKEN2_write_data_shift));
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c1_shift));
			rtd_outl(SYS_REG_SYS_SRST2_reg, BIT(SYS_REG_SYS_SRST2_rstn_i2c1_shift)| BIT(SYS_REG_SYS_SRST2_write_data_shift));
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c1_shift)| BIT(SYS_REG_SYS_CLKEN2_write_data_shift));
		}
		if (i2c_phy & BIT(2)) {
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c2_shift));
			rtd_outl(SYS_REG_SYS_SRST2_reg, BIT(SYS_REG_SYS_SRST2_rstn_i2c2_shift));
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c2_shift) | BIT(SYS_REG_SYS_CLKEN2_write_data_shift));
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c2_shift));
			rtd_outl(SYS_REG_SYS_SRST2_reg, BIT(SYS_REG_SYS_SRST2_rstn_i2c2_shift) | BIT(SYS_REG_SYS_SRST2_write_data_shift));
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c2_shift) | BIT(SYS_REG_SYS_CLKEN2_write_data_shift));
		}
		if (i2c_phy & BIT(3)) {
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c3_shift));
			rtd_outl(SYS_REG_SYS_SRST2_reg, BIT(SYS_REG_SYS_SRST2_rstn_i2c3_shift));
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c3_shift) | BIT(SYS_REG_SYS_CLKEN2_write_data_shift));
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c3_shift));
			rtd_outl(SYS_REG_SYS_SRST2_reg, BIT(SYS_REG_SYS_SRST2_rstn_i2c3_shift) | BIT(SYS_REG_SYS_SRST2_write_data_shift));
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c3_shift) | BIT(SYS_REG_SYS_CLKEN2_write_data_shift));
		}
		if (i2c_phy & BIT(4)) {
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c4_shift));
			rtd_outl(SYS_REG_SYS_SRST2_reg, BIT(SYS_REG_SYS_SRST2_rstn_i2c4_shift));
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c4_shift) | BIT(SYS_REG_SYS_CLKEN2_write_data_shift));
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c4_shift));
			rtd_outl(SYS_REG_SYS_SRST2_reg, BIT(SYS_REG_SYS_SRST2_rstn_i2c4_shift) | BIT(SYS_REG_SYS_SRST2_write_data_shift));
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c4_shift) | BIT(SYS_REG_SYS_CLKEN2_write_data_shift));
		}
		if (i2c_phy & BIT(5)) {
			rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_i2c5_off_shift));
			rtd_outl(STB_ST_SRST0_reg, BIT(STB_ST_SRST0_rstn_i2c5_off_shift));
			rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_i2c5_off_shift) | BIT(STB_ST_CLKEN0_write_data_shift));
			rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_i2c5_off_shift));
			rtd_outl(STB_ST_SRST0_reg, BIT(STB_ST_SRST0_rstn_i2c5_off_shift) | BIT(STB_ST_SRST0_write_data_shift));
			rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_i2c5_off_shift) | BIT(STB_ST_CLKEN0_write_data_shift));
		}

	} else {
		if (i2c_phy & BIT(0))
			rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_i2c0_off_shift));

		if (i2c_phy & BIT(1))
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c1_shift));

		if (i2c_phy & BIT(2))
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c2_shift));

		if (i2c_phy & BIT(3))
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c3_shift));

		if (i2c_phy & BIT(4))
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_i2c4_shift));

		if (i2c_phy & BIT(5))
			rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_i2c5_off_shift));
	}

	hw_semaphore_unlock();

	return CRT_SUCCESS;
}





int UART_CriticalRegister(enum CRT_CLK clken, void *private_data)
{

	int systemConsole = 0;

	if (private_data) {
		systemConsole = *(int *)private_data;
	} else {
		pr_warn(" UART_CriticalRegister without parivate_data parameter\n");
	}

	hw_semaphore_try_lock();
	switch (systemConsole) {
	case 1:
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_uart1_shift));
		rtd_outl(SYS_REG_SYS_SRST2_reg, SYS_REG_SYS_SRST2_rstn_uart1_mask);
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_uart1_shift) | SYS_REG_SYS_CLKEN2_write_data_mask);
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_uart1_shift));
		rtd_outl(SYS_REG_SYS_SRST2_reg, SYS_REG_SYS_SRST2_rstn_uart1_mask | SYS_REG_SYS_SRST2_write_data_mask);
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_uart1_shift) | SYS_REG_SYS_CLKEN2_write_data_mask);
		rtd_clearbits(SYS_REG_SYS_CLKSEL_reg, BIT(0));	 // set uart1 to 98MHz
		rtd_maskl(PLL27X_REG_SYS_PLL_AUD3_reg, 0xfffffff2, BIT(3));
		break;
	default:
		hw_semaphore_unlock();
		return CRT_FAIL;

	}
	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int SE_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {

		rtd_outl(SYS_REG_SYS_SRST1_reg, BIT(SYS_REG_SYS_SRST1_rstn_se_shift));
		udelay(10);

		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_se_shift) | SYS_REG_SYS_CLKEN1_write_data_mask);
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_se2_shift) | SYS_REG_SYS_CLKEN1_write_data_mask);
		udelay(10);

		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_se_shift));
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_se2_shift));
		udelay(10);

		rtd_outl(SYS_REG_SYS_SRST1_reg, BIT(SYS_REG_SYS_SRST1_rstn_se_shift));
		udelay(10);

		rtd_outl(SYS_REG_SYS_SRST1_reg, BIT(SYS_REG_SYS_SRST1_rstn_se_shift) | SYS_REG_SYS_SRST1_write_data_mask);
		udelay(10);

		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_se_shift) | SYS_REG_SYS_CLKEN1_write_data_mask);
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_se2_shift) | SYS_REG_SYS_CLKEN1_write_data_mask);
		udelay(10);
	} else {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_se_shift));
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_se2_shift));
		rtd_outl(SYS_REG_SYS_SRST1_reg, BIT(SYS_REG_SYS_SRST1_rstn_se_shift));
		udelay(10);
	}
	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int NAND_CriticalRegister(enum CRT_CLK clken, void *private_data)
{

	struct NF_CLK_INFO *p_nf_clk = (struct NF_CLK_INFO *)private_data;

	hw_semaphore_try_lock();

	if (p_nf_clk == NULL) {
		//setting nf clk on/off
		if (clken == CLK_ON) {
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_nf_mask | SYS_REG_SYS_CLKEN2_write_data_mask);
		} else {
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_nf_mask);
		}
	} else {
		if (p_nf_clk->clk_set_or_get == NF_CLK_SET) {
			//setting nf_clksel
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_nf_mask);
			rtd_outl(SYS_REG_SYS_CLKDIV_reg, (rtd_inl(SYS_REG_SYS_CLKDIV_reg) & (~SYS_REG_SYS_CLKDIV_nf_clksel_mask)) | SYS_REG_SYS_CLKDIV_nf_clksel(p_nf_clk->nf_clksel));
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_nf_mask | SYS_REG_SYS_CLKEN2_write_data_mask);
		} else {
			//getting current nf clk info
			p_nf_clk->clk_is_on = SYS_REG_SYS_CLKEN2_get_clken_nf(rtd_inl(SYS_REG_SYS_CLKEN2_reg));
			if (p_nf_clk->clk_is_on == 1) {
				//getting current nf_clksel info
				p_nf_clk->nf_clksel = SYS_REG_SYS_CLKDIV_get_nf_clksel(rtd_inl(SYS_REG_SYS_CLKDIV_reg));
			}
		}
	}

	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int MD_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();

	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_md_shift));
		rtd_outl(SYS_REG_SYS_SRST1_reg, BIT(SYS_REG_SYS_SRST1_rstn_md_shift));
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_md_shift) | SYS_REG_SYS_CLKEN1_write_data_mask);
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_md_shift));
		rtd_outl(SYS_REG_SYS_SRST1_reg, BIT(SYS_REG_SYS_SRST1_rstn_md_shift) | SYS_REG_SYS_SRST1_write_data_mask);
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_md_shift) | SYS_REG_SYS_CLKEN1_write_data_mask);
	} else {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_md_shift));
	}

	hw_semaphore_unlock();
	return CRT_SUCCESS;
}
int DOLBY_HDR_CriticalRegister(enum CRT_CLK clken, void *private_data)
{

	hw_semaphore_try_lock();

	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_dolby_comp_shift)|BIT(SYS_REG_SYS_CLKEN1_clken_dolby_dm_shift)| SYS_REG_SYS_CLKEN1_write_data_mask);
	} else {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_dolby_comp_shift)|BIT(SYS_REG_SYS_CLKEN1_clken_dolby_dm_shift));
	}

	hw_semaphore_unlock();
	return CRT_SUCCESS;
}
int GPU_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();

	if (clken == CLK_ON) {

		//disable GPU SRST0 RESET (bit usage changed)
		//rtd_setbits(SYS_REG_SYS_SRST0_reg, BIT(19));
		//udelay(10);

		//reg = SysReadHWReg((void *)SYS_REG_BASE, SYS_REG_GPU_SRST0_OFFSET) | (
		//SysWriteHWReg((void *)SYS_REG_BASE, SYS_REG_GPU_SRST0_OFFSET, reg);
		//OSWaitus(100);
		//enable GPU CLK
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_3d_gde_shift) | SYS_REG_SYS_CLKEN1_write_data_mask);
		udelay(10);

		//reg = SysReadHWReg((void *)SYS_REG_BASE, SYS_REG_GPU_CLK_OFFSET) | (_B
		//SysWriteHWReg((void *)SYS_REG_BASE, SYS_REG_GPU_CLK_OFFSET, reg);
		//OSWaitus(100);

		//disable GPU RESET
		rtd_outl(SYS_REG_SYS_SRST1_reg, BIT(SYS_REG_SYS_SRST1_rstn_3d_gde_shift) | SYS_REG_SYS_SRST1_write_data_mask);
		udelay(10);
		//reg = SysReadHWReg((void *)SYS_REG_BASE, SYS_REG_GPU_RESET_OFFSET) |
		//SysWriteHWReg((void *)SYS_REG_BASE, SYS_REG_GPU_RESET_OFFSET, reg);
		//OSWaitus(100);
        //printk("func=%s line=%d SYS_CLKEN1_reg=%x SYS_SRST1_reg=%x \n",__FUNCTION__,__LINE__,rtd_inl(SYS_REG_SYS_CLKEN1_reg),rtd_inl(SYS_REG_SYS_SRST1_reg));
		
		rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, SYS_REG_INT_CTRL_SCPU_gpu_int_scpu_routing_en_mask | SYS_REG_INT_CTRL_SCPU_write_data(1));
		
	} else if (clken == CLK_OFF) {
		//do nothing
	}

	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int PWM_CriticalRegister(enum CRT_CLK clken, void *private_data)
{

	int pwm_type = *(int *)private_data;
	hw_semaphore_try_lock();

	if (clken == CLK_ON) {
		if (pwm_type == 0) {
			/*iso*/
 			rtd_outl(STB_ST_CLKEN0_reg,
 						BIT(STB_ST_CLKEN0_clken_pwm_shift) | STB_ST_CLKEN0_write_data_mask);
			rtd_outl(STB_ST_CLKEN0_reg,
						BIT(STB_ST_CLKEN0_clken_pwm_shift));
			rtd_outl(STB_ST_SRST0_reg,
						BIT(STB_ST_SRST0_rstn_pwm_shift));
			rtd_outl(STB_ST_SRST0_reg,
						BIT(STB_ST_SRST0_rstn_pwm_shift) | STB_ST_SRST0_write_data_mask);
			rtd_outl(STB_ST_CLKEN0_reg,
						BIT(STB_ST_CLKEN0_clken_pwm_shift) | STB_ST_CLKEN0_write_data_mask);
		} else {
			/*misc*/
			rtd_outl(SYS_REG_SYS_CLKEN2_reg,
						BIT(SYS_REG_SYS_CLKEN2_clken_pwm_shift) | SYS_REG_SYS_CLKEN2_write_data_mask);
			rtd_outl(SYS_REG_SYS_CLKEN2_reg,
						BIT(SYS_REG_SYS_CLKEN2_clken_pwm_shift));
			rtd_outl(SYS_REG_SYS_SRST2_reg,
						BIT(SYS_REG_SYS_SRST2_rstn_pwm_shift));
			rtd_outl(SYS_REG_SYS_SRST2_reg,
						BIT(SYS_REG_SYS_SRST2_rstn_pwm_shift) | SYS_REG_SYS_SRST2_write_data_mask);
			rtd_outl(SYS_REG_SYS_CLKEN2_reg,
						BIT(SYS_REG_SYS_CLKEN2_clken_pwm_shift) | SYS_REG_SYS_CLKEN2_write_data_mask);
		}

	} else {
		if (pwm_type == 0) {
			rtd_outl(STB_ST_CLKEN0_reg,
						  BIT(STB_ST_CLKEN0_clken_pwm_shift));
			rtd_outl(STB_ST_SRST0_reg,
						  BIT(STB_ST_SRST0_rstn_pwm_shift));
		} else {
			rtd_outl(SYS_REG_SYS_CLKEN2_reg,
						  BIT(SYS_REG_SYS_CLKEN2_clken_pwm_shift));
			rtd_outl(SYS_REG_SYS_SRST2_reg,
						  BIT(SYS_REG_SYS_SRST2_rstn_pwm_shift));
		}
	}
	hw_semaphore_unlock();
	return CRT_SUCCESS;
}
int PCMCIA_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_pcmcia_shift));	/* disable clock */
		udelay(10);
		rtd_outl(SYS_REG_SYS_SRST2_reg, BIT(SYS_REG_SYS_SRST2_rstn_pcmcia_shift));	/* assert pcmcia */
		udelay(10);
		rtd_outl(SYS_REG_SYS_SRST2_reg, BIT(SYS_REG_SYS_SRST2_rstn_pcmcia_shift) | BIT(SYS_REG_SYS_SRST2_write_data_shift)); 	/* deassert pcmcia */
		udelay(10);
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_pcmcia_shift) | BIT(SYS_REG_SYS_CLKEN2_write_data_shift));
	} else {
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_pcmcia_shift));	/* disable clock  */
	}
	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int CEC_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(STB_ST_CLKEN1_reg, BIT(STB_ST_CLKEN1_clken_cec_shift));
		udelay(10);
		rtd_outl(STB_ST_SRST1_reg, BIT(STB_ST_SRST1_rstn_cec_shift));
		udelay(10);
		rtd_outl(STB_ST_SRST1_reg, BIT(STB_ST_SRST1_rstn_cec_shift) | BIT(STB_ST_SRST1_write_data_shift));
		udelay(10);
		rtd_outl(STB_ST_CLKEN1_reg, BIT(STB_ST_CLKEN1_clken_cec_shift) |BIT(STB_ST_CLKEN1_write_data_shift));
		udelay(10);
	} else {
		
	}
	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int LSADC_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(STB_ST_CLKEN1_reg, BIT(STB_ST_CLKEN1_clken_lsadc_shift));
		udelay(10);
		rtd_outl(STB_ST_SRST1_reg, BIT(STB_ST_SRST1_rstn_lsadc_shift));
		udelay(10);
		rtd_outl(STB_ST_SRST1_reg, BIT(STB_ST_SRST1_rstn_lsadc_shift) | BIT(STB_ST_SRST1_write_data_shift));
		udelay(10);
		rtd_outl(STB_ST_CLKEN1_reg, BIT(STB_ST_CLKEN1_clken_lsadc_shift) |BIT(STB_ST_CLKEN1_write_data_shift));
		udelay(10);
	} else {
		rtd_outl(STB_ST_CLKEN1_reg, BIT(STB_ST_CLKEN1_clken_lsadc_shift));	/* disable clock  */
	}
	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int GPIO_CriticalRegister(enum CRT_CLK clken)
{        
	hw_semaphore_try_lock();	
	if (clken == CLK_ON) {	    	    			   
#if (0) 
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_gpio_mask | SYS_REG_SYS_CLKEN2_write_data(1));        
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_gpio_mask | SYS_REG_SYS_CLKEN2_write_data(0));		   		   		           
		rtd_outl(SYS_REG_SYS_SRST2_reg,  SYS_REG_SYS_SRST2_rstn_gpio_mask | SYS_REG_SYS_CLKEN2_write_data(0));   // do reset		
		rtd_outl(SYS_REG_SYS_SRST2_reg,  SYS_REG_SYS_SRST2_rstn_gpio_mask | SYS_REG_SYS_CLKEN2_write_data(1));   // release reset		
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_gpio_mask | SYS_REG_SYS_CLKEN2_write_data(1));		   		           
#endif
		rtd_outl(STB_ST_CLKEN0_reg, STB_ST_CLKEN0_clken_iso_misc_mask | STB_ST_CLKEN0_write_data(1)); // ISO_MISC clock		
		rtd_outl(STB_ST_SRST0_reg,  STB_ST_SRST0_rstn_iso_misc_mask | STB_ST_SRST0_get_write_data(1));  // release ISO_MISC reset
	} else {

	}
	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int EMMC_CriticalRegister(enum CRT_CLK clken, void *private_data)
{

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {

		rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_emmc_shift));
		rtd_outl(SYS_REG_SYS_SRST2_reg, BIT(SYS_REG_SYS_SRST2_rstn_emmc_shift));
		udelay(10);
		rtd_outl(SYS_REG_SYS_SRST2_reg, BIT(SYS_REG_SYS_SRST2_rstn_emmc_shift) | SYS_REG_SYS_SRST2_rstn_emmc_mask);
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_emmc_shift) | SYS_REG_SYS_CLKEN2_write_data_mask);

	} else {
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, BIT(SYS_REG_SYS_CLKEN2_clken_emmc_shift));
		rtd_outl(SYS_REG_SYS_SRST2_reg, BIT(SYS_REG_SYS_SRST2_rstn_emmc_shift));
	}
	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int SDIO_CriticalRegister(enum CRT_CLK clken, void *private_data)
{

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {

		rtd_outl(SYS_REG_SYS_CLKEN3_reg, BIT(SYS_REG_SYS_CLKEN3_clken_sd_shift));
		rtd_outl(SYS_REG_SYS_SRST3_reg, BIT(SYS_REG_SYS_SRST3_rstn_sd_shift));
		udelay(10);
		rtd_outl(SYS_REG_SYS_SRST3_reg, BIT(SYS_REG_SYS_SRST3_rstn_sd_shift) | SYS_REG_SYS_SRST3_write_data_mask);
		rtd_outl(SYS_REG_SYS_CLKEN3_reg, BIT(SYS_REG_SYS_CLKEN3_clken_sd_shift) | SYS_REG_SYS_CLKEN3_write_data_mask);

		/* enable interrupt */
		rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, BIT(SYS_REG_INT_CTRL_SCPU_sd_int_scpu_routing_en_shift) | SYS_REG_INT_CTRL_SCPU_write_data(1));
		udelay(10);

	} else {
		rtd_outl(SYS_REG_SYS_CLKEN3_reg, BIT(SYS_REG_SYS_CLKEN3_clken_sd_shift));
		rtd_outl(SYS_REG_SYS_SRST3_reg, BIT(SYS_REG_SYS_SRST3_rstn_sd_shift));

		/* disable interrupt */
		rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, BIT(SYS_REG_INT_CTRL_SCPU_sd_int_scpu_routing_en_shift) | SYS_REG_INT_CTRL_SCPU_write_data(0));
		rtd_outl(SYS_REG_INT_CTRL_KCPU_reg, BIT(SYS_REG_INT_CTRL_KCPU_sd_int_kcpu_routing_en_shift) | SYS_REG_INT_CTRL_KCPU_write_data(0));
		udelay(10);
	}
	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int SMC_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_sc_mask);   /* Disable Clock */
		udelay(100);
		rtd_outl(SYS_REG_SYS_SRST2_reg, SYS_REG_SYS_SRST2_rstn_sc_mask);   /*HW Reset*/
		udelay(100);
		rtd_outl(SYS_REG_SYS_SRST2_reg, SYS_REG_SYS_SRST2_rstn_sc_mask | SYS_REG_SYS_SRST2_write_data_mask);     /* HW Reset*/
		udelay(100);
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_sc_mask | SYS_REG_SYS_CLKEN2_write_data_mask);     /* Enable Clock*/
	} else {
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_sc_mask);   /* Disable Clock */
	}
	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int CP_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();

	if (clken == CLK_ON) {
		/* CLKEN = "0" -> RSTN = "0" -> RSTN = "1" -> CLKEN = "1" */
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_cp_shift));
		udelay(10);
		rtd_outl(SYS_REG_SYS_SRST1_reg, BIT(SYS_REG_SYS_SRST1_rstn_cp_shift));
		udelay(10);
		rtd_outl(SYS_REG_SYS_SRST1_reg, BIT(SYS_REG_SYS_SRST1_rstn_cp_shift) | SYS_REG_SYS_SRST1_write_data_mask);
		udelay(10);
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_cp_shift) | SYS_REG_SYS_CLKEN1_write_data_mask);
		udelay(10);
	} else {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_cp_shift));
		udelay(10);
	}

	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int TP_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();

	if (clken == CLK_ON) {

		/*  External Reset TP (0: reset ; 1: normal) */
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_tp_mask);
		udelay(100);

		/* enable TP clock */
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_tp_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
		udelay(100);

		/*  External Reset TP */
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_tp_mask | SYS_REG_SYS_SRST1_write_data_mask);
		udelay(100);

	} else {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_tp_mask);
	}

	hw_semaphore_unlock();
	return CRT_SUCCESS;
}



int TPOUT_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();

	if (clken == CLK_ON) {
		/* enable TPOUT clock */
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_tp_div_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
		udelay(100);
	} else {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_tp_div_mask);
	}

	hw_semaphore_unlock();
	return CRT_SUCCESS;
}



int MHL_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();

	if (clken == CLK_ON) {
		/* Module Clock & Reset Enable */
		rtd_outl(SYS_REG_SYS_SRST1_reg,
				  (SYS_REG_SYS_SRST1_rstn_hdmi_mask |
				   SYS_REG_SYS_SRST1_rstn_vodma_mask |
				   SYS_REG_SYS_SRST1_write_data_mask));

		/* STANDBY Module Clock & Reset Enable */
		rtd_outl(STB_ST_SRST1_reg,
					(STB_ST_SRST1_rstn_cbus_mask |
					STB_ST_SRST1_rstn_alu_mask |
					STB_ST_SRST1_write_data_mask));

		rtd_outl(STB_ST_CLKEN1_reg,
					(STB_ST_CLKEN1_clken_cbus_mask |
					STB_ST_CLKEN1_clken_alu_mask |
					STB_ST_CLKEN1_write_data_mask));

		rtd_maskl(STB_ALU_IE_reg, ~STB_ALU_IE_stie_cbus_mask, STB_ALU_IE_stie_cbus_mask);  /* enable STB_ALU_IE interrupt enable*/
		rtd_outl(STB_ALU_IP_reg, STB_ALU_IP_stip_cbus_mask);  /* clear pending flag of cbus*/
	} else {
		/* do nothing */
	}

	hw_semaphore_unlock();
	return CRT_SUCCESS;
}

int HDMI_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();

	if (clken == CLK_ON) {
		/* HDMI & APLL &cbus & off measure */
		rtd_outl(SYS_REG_SYS_SRST1_reg,
					(SYS_REG_SYS_SRST1_rstn_hdmi_mask |
					SYS_REG_SYS_SRST1_rstn_apll_adc_mask |
					SYS_REG_SYS_SRST1_rstn_offms_mask |
					SYS_REG_SYS_SRST1_rstn_cbus_mask |
					SYS_REG_SYS_SRST1_write_data_mask));

		rtd_outl(SYS_REG_SYS_CLKEN1_reg,
					(SYS_REG_SYS_CLKEN1_clken_hdmi_mask |
					SYS_REG_SYS_CLKEN1_clken_apll_adc_mask |
					SYS_REG_SYS_CLKEN1_clken_offms_mask |
					SYS_REG_SYS_CLKEN1_clken_cbus_mask |
					SYS_REG_SYS_CLKEN1_write_data_mask));
		/* DDC */
		rtd_outl(SYS_REG_SYS_SRST3_reg, SYS_REG_SYS_SRST3_rstn_ddc_mask | SYS_REG_SYS_SRST3_write_data_mask);
		rtd_outl(SYS_REG_SYS_CLKEN3_reg, SYS_REG_SYS_CLKEN3_clken_ddc_mask | SYS_REG_SYS_CLKEN3_write_data_mask);
	} else {
		/* HDMI & APLL &cbus & off measure */
		rtd_outl(SYS_REG_SYS_SRST1_reg,
					(SYS_REG_SYS_SRST1_rstn_hdmi_mask |
					SYS_REG_SYS_SRST1_rstn_apll_adc_mask |
					SYS_REG_SYS_SRST1_rstn_offms_mask |
					SYS_REG_SYS_SRST1_rstn_cbus_mask));

		rtd_outl(SYS_REG_SYS_CLKEN1_reg,
					(SYS_REG_SYS_CLKEN1_clken_hdmi_mask |
					SYS_REG_SYS_CLKEN1_clken_apll_adc_mask |
					SYS_REG_SYS_CLKEN1_clken_offms_mask |
					SYS_REG_SYS_CLKEN1_clken_cbus_mask));
		/* DDC */
		rtd_outl(SYS_REG_SYS_SRST3_reg, SYS_REG_SYS_SRST3_rstn_ddc_mask);
		rtd_outl(SYS_REG_SYS_CLKEN3_reg, SYS_REG_SYS_CLKEN3_clken_ddc_mask);
	}

	hw_semaphore_unlock();
	return CRT_SUCCESS;
}


int GDMA_CriticalRegister(enum CRT_CLK clken, void *private_data)
{
	int src_type = -1;

	if (private_data)
		src_type = *(int *)private_data;
	else
		pr_warn(" GDMA_CriticalRegister without parivate_data parameter\n");


	hw_semaphore_try_lock();

	if (clken == CLK_ON) {

		if (src_type == 0) {	/* enable/disable clken_disp_gdma */
			rtd_outl(SYS_REG_SYS_DISPCLKSEL_reg, rtd_inl(SYS_REG_SYS_DISPCLKSEL_reg) |
					 SYS_REG_SYS_DISPCLKSEL_clken_disp_gdma(1));
		}
	} else {
		if (src_type == 0) {
			rtd_outl(SYS_REG_SYS_DISPCLKSEL_reg, rtd_inl(SYS_REG_SYS_DISPCLKSEL_reg) & ~SYS_REG_SYS_DISPCLKSEL_clken_disp_gdma_mask);
		}
	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}
int VBI_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_SRST1_reg, BIT(SYS_REG_SYS_SRST1_rstn_vbis0_shift) | SYS_REG_SYS_SRST1_write_data_mask);
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_vbis0_shift) | SYS_REG_SYS_CLKEN1_write_data_mask);
		udelay(10);
	} else {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, BIT(SYS_REG_SYS_CLKEN1_clken_vbis0_shift));
		rtd_outl(SYS_REG_SYS_SRST1_reg, BIT(SYS_REG_SYS_SRST1_rstn_vbis0_shift));
		udelay(10);
	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int ETH_CriticalRegister(enum CRT_CLK clken, void *private_data)
{
	int wol_mode = *(int *)private_data;
	int count = 0;

	hw_semaphore_try_lock();

	if (clken == CLK_ON && wol_mode == 0) {
		/* Enable SCPU ETN interrupt and disable KCPU ETN interrupt */
		rtd_outl(SYS_REG_INT_CTRL_KCPU_reg, SYS_REG_INT_CTRL_KCPU_etn_int_kcpu_routing_en_mask);
		rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, SYS_REG_INT_CTRL_SCPU_etn_int_scpu_routing_en_mask | SYS_REG_INT_CTRL_SCPU_write_data_mask);
	}
	else if(clken == CLK_ON && wol_mode == 1) {
		/* GETN_RSTN_MASK bit[30]=0 */
		rtd_clearbits(STB_ST_CTRL0_reg, STB_ST_CTRL0_etn_rstn_mask_mask);
		/* GETN RBUS & GETN clock */
		rtd_outl(STB_ST_CLKEN0_reg, STB_ST_CLKEN0_clken_etn_rbus_mask | STB_ST_CLKEN0_clken_etn_mask | STB_ST_CLKEN0_write_data_mask); // CLKEN_GETN_RBUS bit[11]=1,CLKEN_GETN bit[8]=1
		rtd_outl(STB_ST_SRST0_reg, STB_ST_SRST0_rstn_etn_mask | STB_ST_SRST0_write_data_mask); // RSTN_GETN_bit[8]=1

		rtd_outl(PLLETN_GETN_CLKEN_reg, PLLETN_GETN_CLKEN_clken_getn_mac_mask | PLLETN_GETN_CLKEN_clken_getn_sys_mask);  //CLKEN_GETN_MAC bit[2] = 0, CLKEN_GETN_SYS[1] = 0
		rtd_outl(STB_ST_CLKEN0_reg, STB_ST_CLKEN0_clken_etn_rbus_mask | STB_ST_CLKEN0_clken_etn_mask); // CLKEN_GETN_RBUS bit[11]=0,CLKEN_GETN bit[8]=0
		rtd_outl(STB_ST_SRST0_reg, STB_ST_SRST0_rstn_etn_mask); //RSTN_GETN bit[8] = 0
		rtd_outl(STB_ST_SRST0_reg, STB_ST_SRST0_rstn_etn_mask | STB_ST_SRST0_write_data_mask);  // RSTN_GETN bit[8] = 1
		rtd_outl(STB_ST_CLKEN0_reg, STB_ST_CLKEN0_clken_etn_rbus_mask | STB_ST_CLKEN0_clken_etn_mask | STB_ST_CLKEN0_write_data_mask); // CLKEN_GETN_RBUS bit[11]=1,CLKEN_GETN bit[8]=1

		/* PLL ETN */
		rtd_outl(PLLETN_GETN_RST_reg, PLLETN_GETN_RST_rstn_getn_sys_mask | PLLETN_GETN_RST_rstn_getn_mac_mask | PLLETN_GETN_RST_rstn_getn_phy_mask | PLLETN_GETN_RST_write_data_mask);  //RSTN_GETN_PHY bit[3] = 1, RSTN_GETN_MAC bit[2] = 1, RSTN_GETN_SYS[1] = 1
		rtd_outl(PLLETN_GETN_CLKEN_reg, PLLETN_GETN_CLKEN_clken_getn_mac_mask | PLLETN_GETN_CLKEN_clken_getn_sys_mask | PLLETN_GETN_CLKEN_write_data_mask);  //CLKEN_GETN_MAC bit[2] = 1, CLKEN_GETN_SYS[1] = 1
		rtd_outl(PLLETN_SYS_PLL_ETN1_reg, PLLETN_SYS_PLL_ETN1_plletn_pow_mask | PLLETN_SYS_PLL_ETN1_plletn_powldo_mask);  //plletn_pow bit[23] = 1, plletn_powldo bit[22] = 1

		/* Check init_autoload_done = 1 */
		while(!(rtd_inl(PLLETN_INIT_AUTOLOAD_DONE_reg) & PLLETN_INIT_AUTOLOAD_DONE_init_autoload_done_mask) && count < 500) {    // wait plletn init done
			mdelay(1);
			count++;
		}
		if(count == 500) {
			pr_warn("[ETH] initdone failed!(%08x)\n", rtd_inl(PLLETN_INIT_AUTOLOAD_DONE_reg));
			return CRT_FAIL;
		}
	}
	else if(clken == CLK_OFF && wol_mode == 1) {
		rtd_setbits(STB_ST_CTRL0_reg, BIT(STB_ST_CTRL0_etn_rstn_mask_shift));
		rtd_outl(PLLETN_GETN_CLKEN_reg, BIT(PLLETN_GETN_CLKEN_clken_getn_sys_shift));
		rtd_outl(PLLETN_GETN_RST_reg, BIT(PLLETN_GETN_RST_rstn_getn_sys_shift));
		rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_etn_rbus_shift));
	}
	else {
		/* disable interrupt */
		rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, SYS_REG_INT_CTRL_SCPU_etn_int_scpu_routing_en_mask);
	}

	hw_semaphore_unlock();
	return CRT_SUCCESS;
}


int DiseqC_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		//---------------------------------------------
		// Enable Demod Clock / Reset
		// Note : DiseqC has dependency issue with DEMOD
		//        so we have to enable demod first
		//---------------------------------------------
		hw_semaphore_unlock();
		DDEMOD_CriticalRegister(CLK_ON);
		hw_semaphore_try_lock();
		//-------------------------
		rtd_outl(SYS_REG_SYS_SRST0_reg,SYS_REG_SYS_SRST0_rstn_diseqc(1)|
                                       SYS_REG_SYS_SRST0_write_data(1));
		udelay(50);	
		rtd_outl(SYS_REG_SYS_CLKEN0_reg,SYS_REG_SYS_CLKEN0_clken_diseqc(1)|
                                        SYS_REG_SYS_CLKEN0_get_write_data(1));
		udelay(10);
	} else {
		rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_diseqc_mask);
		udelay(50);	
		rtd_outl(SYS_REG_SYS_SRST0_reg,  SYS_REG_SYS_SRST0_rstn_diseqc_mask);
		udelay(10);
	}

	hw_semaphore_unlock();

	return CRT_SUCCESS;
}


int ADEMOD_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	//common.c : AtvDemodPowerControl
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_if_demod(1) | SYS_REG_SYS_SRST1_write_data(1));
		rtd_outl(SYS_REG_SYS_SRST2_reg, SYS_REG_SYS_SRST2_rstn_atvin2(1) | SYS_REG_SYS_SRST2_rstn_atvin(1) | SYS_REG_SYS_SRST2_rstn_if_demod_logic(1) | SYS_REG_SYS_SRST2_write_data(1));
		udelay(50);
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_if_demod(1) | SYS_REG_SYS_CLKEN1_write_data(1)); // enable demod clock
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_atvin_ifd(1) | SYS_REG_SYS_CLKEN2_write_data(1));
		udelay(50);
		// path to ifd
		//rtd_clearbits(SYS_REG_SYS_CLKSEL_reg, BIT(SYS_REG_SYS_CLKSEL_atvin_clk_sel_shift));//Don't need to set when clk en = 0
		//udelay(10);
	} else {
	
	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int DDEMOD_CriticalRegister(enum CRT_CLK clken)
{	
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
        rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_dtv_demod(1) | SYS_REG_SYS_CLKEN2_write_data(1));//for dtv_demod
        rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_dtv_demod(1) | SYS_REG_SYS_CLKEN2_write_data(0));
        rtd_outl(SYS_REG_SYS_SRST2_reg, SYS_REG_SYS_SRST2_rstn_dtv_demod(1) | SYS_REG_SYS_SRST2_write_data(1));
        udelay(50);
        rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_dtv_demod(1) | SYS_REG_SYS_CLKEN2_write_data(1));

        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_img_demod_wrap(1) | SYS_REG_SYS_CLKEN0_write_data(1));//for img_demod_wrap
        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_img_demod_wrap(1) | SYS_REG_SYS_CLKEN0_write_data(0));
        rtd_outl(SYS_REG_SYS_SRST0_reg, SYS_REG_SYS_SRST0_rstn_img_demod_wrap(1) | SYS_REG_SYS_SRST0_write_data(1));
        udelay(50);
        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_img_demod_wrap(1) | SYS_REG_SYS_CLKEN0_write_data(1));

        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_dtv_frontend(1) | SYS_REG_SYS_CLKEN0_write_data(1));//for dtv_frontend
        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_dtv_frontend(1) | SYS_REG_SYS_CLKEN0_write_data(0));
        rtd_outl(SYS_REG_SYS_SRST0_reg, SYS_REG_SYS_SRST0_rstn_dtv_frontend(1) | SYS_REG_SYS_SRST0_write_data(1));
        udelay(50);
        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_dtv_frontend(1) | SYS_REG_SYS_CLKEN0_write_data(1));
        udelay(50);

	} else {
        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_img_demod(1) | SYS_REG_SYS_CLKEN0_write_data(0)); //for img_demod, disable clk and reset
        rtd_outl(SYS_REG_SYS_SRST0_reg, SYS_REG_SYS_SRST0_rstn_img_demod(1) | SYS_REG_SYS_SRST0_write_data(0));

        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_img_demod_wrap(1) | SYS_REG_SYS_CLKEN0_write_data(0)); //for img_demod_wrap, disable clk and reset
        rtd_outl(SYS_REG_SYS_SRST0_reg, SYS_REG_SYS_SRST0_rstn_img_demod_wrap(1) | SYS_REG_SYS_SRST0_write_data(0));

        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_hdic(1) | SYS_REG_SYS_CLKEN0_clken_dtv_frontend(1) | SYS_REG_SYS_CLKEN0_write_data(0)); //for hdic_demod, dtv_frontend, disable clk and reset
        rtd_outl(SYS_REG_SYS_SRST0_reg, SYS_REG_SYS_SRST0_rstn_hdic_apb(1) | SYS_REG_SYS_SRST0_rstn_hdic_axi(1) | SYS_REG_SYS_SRST0_rstn_hdic(1) | SYS_REG_SYS_SRST0_rstn_dtv_frontend(1) | SYS_REG_SYS_SRST0_rstn_rtk_demod(1) | SYS_REG_SYS_SRST0_write_data(0));

        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_rtk_demod(1) | SYS_REG_SYS_CLKEN0_write_data(0)); //for rtk_demod, disable clk and reset
        rtd_outl(SYS_REG_SYS_SRST0_reg, SYS_REG_SYS_SRST0_rstn_rtk_demod(1) | SYS_REG_SYS_SRST0_write_data(0));

        rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_dtv_demod(1) | SYS_REG_SYS_CLKEN2_write_data(0)); //for dtv_demod, disable clk and reset
        rtd_outl(SYS_REG_SYS_SRST2_reg, SYS_REG_SYS_SRST2_rstn_dtv_demod(1) | SYS_REG_SYS_SRST2_write_data(0));
        udelay(10);
	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int DDEMOD_ADC_EN_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_ifadc(1) | SYS_REG_SYS_SRST1_write_data(1));
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_ifadc(1) | SYS_REG_SYS_CLKEN1_write_data(1)); // enable ifadc clock
	} else {
	
	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int DDEMOD_IMG_EN_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_img_demod(1) | SYS_REG_SYS_CLKEN0_write_data(1));
        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_img_demod(1) | SYS_REG_SYS_CLKEN0_write_data(0));
		rtd_outl(SYS_REG_SYS_SRST0_reg, SYS_REG_SYS_SRST0_rstn_img_demod(1) | SYS_REG_SYS_SRST0_write_data(1));
		udelay(50);
		rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_img_demod(1) | SYS_REG_SYS_CLKEN0_write_data(1));
		udelay(50);
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int DDEMOD_HDIC_EN_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_hdic(1) | SYS_REG_SYS_CLKEN0_write_data(1));
        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_hdic(1) | SYS_REG_SYS_CLKEN0_write_data(0));
		rtd_outl(SYS_REG_SYS_SRST0_reg, SYS_REG_SYS_SRST0_rstn_hdic_apb(1) | SYS_REG_SYS_SRST0_rstn_hdic_axi(1) | SYS_REG_SYS_SRST0_rstn_hdic(1) | SYS_REG_SYS_SRST0_write_data(1));
		rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_hdic(1) | SYS_REG_SYS_CLKEN0_write_data(1));
		udelay(50);
	} else {
	
	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int DDEMOD_RTK_EN_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_rtk_demod(1) | SYS_REG_SYS_CLKEN0_write_data(1));
        rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_rtk_demod(1) | SYS_REG_SYS_CLKEN0_write_data(0));
		rtd_outl(SYS_REG_SYS_SRST0_reg, SYS_REG_SYS_SRST0_rstn_rtk_demod(1) | SYS_REG_SYS_SRST0_write_data(1));
		mdelay(5);
		rtd_outl(SYS_REG_SYS_CLKEN0_reg, SYS_REG_SYS_CLKEN0_clken_rtk_demod(1) | SYS_REG_SYS_CLKEN0_write_data(1));
		mdelay(5);
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int ADC_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_SRST1_reg,
			SYS_REG_SYS_SRST1_rstn_apll_adc_mask |
			SYS_REG_SYS_SRST1_rstn_dispi_mask |
			SYS_REG_SYS_SRST1_write_data_mask); 	/* Reset release in APLL_ADC&I/M domain */
		udelay(100);//wait apll stable
		rtd_outl(SYS_REG_SYS_CLKEN1_reg,
			SYS_REG_SYS_CLKEN1_clken_apll_adc_mask |
			SYS_REG_SYS_CLKEN1_clken_dispi_mask |
			SYS_REG_SYS_CLKEN1_write_data_mask); /* APLL_ADC  & I/M domain CRT on */
	} else {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_apll_adc_mask); /* APLL_ADC CRT off */
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_apll_adc_mask); 	/* APLL_ADC CRT off */
	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}


int Auto_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_SRST1_reg,
			SYS_REG_SYS_SRST1_rstn_apll_adc_mask |
			SYS_REG_SYS_SRST1_rstn_dispi_mask |
			SYS_REG_SYS_SRST1_write_data_mask); 	/* Reset release in APLL_ADC&I/M domain */
		udelay(100);//wait apll stable
		rtd_outl(SYS_REG_SYS_CLKEN1_reg,
			SYS_REG_SYS_CLKEN1_clken_apll_adc_mask |
			SYS_REG_SYS_CLKEN1_clken_dispi_mask |
			SYS_REG_SYS_CLKEN1_write_data_mask); /* APLL_ADC  & I/M domain CRT on */
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}


int Auto2_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_SRST1_reg,
			SYS_REG_SYS_SRST1_rstn_apll_adc_mask |
			SYS_REG_SYS_SRST1_rstn_dispi_mask |
			SYS_REG_SYS_SRST1_write_data_mask); 	/* Reset release in APLL_ADC&I/M domain */
		udelay(100);//wait apll stable
		rtd_outl(SYS_REG_SYS_CLKEN1_reg,
			SYS_REG_SYS_CLKEN1_clken_apll_adc_mask |
			SYS_REG_SYS_CLKEN1_clken_dispi_mask |
			SYS_REG_SYS_CLKEN1_write_data_mask); /* APLL_ADC  & I/M domain CRT on */
	} else {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_apll_adc_mask); /* APLL_ADC CRT off */
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_apll_adc_mask); 	/* Reset  in I/M domain */
	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}



int VO_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_vodma_mask);
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_vodma_mask);
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_vodma_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_vodma_mask);
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_vodma_mask | SYS_REG_SYS_SRST1_write_data_mask);
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_vodma_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int VFEDEV_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		// Enable offline measure clock
		// 0xb8000104
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_offms_mask | SYS_REG_SYS_SRST1_write_data_mask);

		// 0xb8000114
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_offms_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}


int TVE1_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {

#if 1//for ma3 LGE project

		//check[22]CLKEN_VDEC
		if (!(rtd_inl(SYS_REG_SYS_CLKEN1_reg) & SYS_REG_SYS_CLKEN1_clken_vdec_mask)) {
			rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_vdec_mask | SYS_REG_SYS_SRST1_write_data_mask); //[22]RSTN_VDEC
			rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_vdec_mask | SYS_REG_SYS_CLKEN1_write_data_mask); //[22]CLKEN_VDEC
		}

		//check [11]RSTN_APLL_ADC
		if (!(rtd_inl(SYS_REG_SYS_CLKEN1_reg) & SYS_REG_SYS_CLKEN1_clken_apll_adc_mask)) {
			rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_apll_adc_mask | SYS_REG_SYS_SRST1_write_data_mask); //[11]RSTN_APLL_ADC
			rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_apll_adc_mask | SYS_REG_SYS_CLKEN1_write_data_mask); //[11]CLKEN_APLL_ADC
		}

		//check [27]RSTN_ATVIN2[26]RSTN_ATVIN
		if (!(rtd_inl(SYS_REG_SYS_CLKEN2_reg) & SYS_REG_SYS_CLKEN2_clken_atvin_vd_mask)) {
			rtd_outl(SYS_REG_SYS_SRST2_reg,
				SYS_REG_SYS_SRST2_rstn_atvin_mask |
				SYS_REG_SYS_SRST2_rstn_atvin2_mask |
				SYS_REG_SYS_SRST2_write_data_mask); //[27]RSTN_ATVIN2[26]RSTN_ATVIN
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_atvin_vd_mask | SYS_REG_SYS_CLKEN2_write_data_mask); //[27]CLKEN_ATVIN_VD
		}

		//check [26]CLKEN_ATVIN_IFD
		if (!(rtd_inl(SYS_REG_SYS_CLKEN2_reg) & SYS_REG_SYS_CLKEN2_clken_atvin_ifd_mask)) {
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_atvin_ifd_mask | SYS_REG_SYS_CLKEN2_write_data_mask); //[26]CLKEN_ATVIN_IFD
		}

		//check [15]CLKEN_IFADC
		if (!(rtd_inl(SYS_REG_SYS_CLKEN1_reg) & SYS_REG_SYS_CLKEN1_clken_ifadc_mask)) {
			rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_ifadc_mask | SYS_REG_SYS_SRST1_write_data_mask); //[15]RSTN_IFADC
			rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_ifadc_mask | SYS_REG_SYS_CLKEN1_write_data_mask); //[15]CLKEN_IFADC
		}

		//check [23]CLKEN_IF_DEMOD
		if (!(rtd_inl(SYS_REG_SYS_CLKEN1_reg) & SYS_REG_SYS_CLKEN1_clken_if_demod_mask)) {
			rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_if_demod_mask | SYS_REG_SYS_CLKEN1_write_data_mask); //[23]CLKEN_IF_DEMOD
		}

		rtd_maskl(SYS_REG_SYS_CLKSEL_reg, 0xFFFCFFFF, 0x00020000); //[17]ATVIN_CLK_SEL] = 0x1, 0x0: IFD, 0x1: VD [16]ATVIN_VD_CLK_SEL = 0x0, 0x0: 108MHz 0x1: 27MHz

#else
		rtd_maskl(CRT_SYS_SRST1_VADDR, 0xFF9FF7FF, 0x00600800); //[22]RSTN_VDEC[21]RSTN_VDEC2[11]RSTN_APLL_ADC
		rtd_maskl(CRT_SYS_SRST2_VADDR, 0xF3FFFFFF, 0x0C000000); //[27]RSTN_ATVIN2[26]RSTN_ATVIN
		rtd_maskl(CRT_SYS_CLKEN1_VADDR, 0xFFBFF7FF, 0x00400800); //[22]CLKEN_VDEC[11]CLKEN_APLL_ADC
		rtd_maskl(CRT_SYS_CLKEN2_VADDR, 0xFFBFFFFF, 0x00400000); //[27]CLKEN_ATVIN_VD
		rtd_maskl(CRT_SYS_CLKSEL_VADDR, 0xFFFCFFFF, 0x00020000); //[17]ATVIN_CLK_SEL] = 0x1, 0x0: IFD, 0x1: VD [16]ATVIN_VD_CLK_SEL = 0x0, 0x0: 108MHz 0x1: 27MHz

		rtd_maskl(CRT_SYS_SRST1_VADDR, 0xFffF7fFF, 0x00008000); //[15]RSTN_IFADC
		rtd_maskl(CRT_SYS_CLKEN2_VADDR, 0xFbfFFfFF, 0x04000000); //[26]CLKEN_ATVIN_IFD

		rtd_maskl(CRT_SYS_SRST2_VADDR, 0xF3fFFfFF, 0x0c000000); //[26]RSTN_ATVIN ,[27]RSTN_ATVIN2
		rtd_maskl(CRT_SYS_CLKEN1_VADDR, 0xFF7fFFFF, 0x00800000); //[23]CLKEN_IF_DEMOD
		rtd_maskl(CRT_SYS_CLKEN1_VADDR, 0xFFff7FFF, 0x00008000); //[15]CLKEN_IFADC
		//not to disable ATV @ Crixus 20141106
		//rtd_maskl(CRT_SYS_CLKSEL_VADDR,0xFFFCFFFF,0x00000000);
#endif

#if 0//Pll27x setting in bootcode
		//initialize clk 27x domain for VD
		////PLL27x Clock : 108M
		//	rtd_maskl(PLL27X_REG_SYS_PLL_27X1_reg,0xFFFFFFE0,0x0000000E);//432MHzPLL27X_M[6:0] = 0x0E
		rtd_maskl(PLL27X_REG_SYS_PLL_27X1_reg, 0xFFFFFFE0, 0x0000000A); //324MHzPLL27X_M[6:0] = 0x0A

		rtd_maskl(PLL27X_REG_SYS_PLL_27X2_reg, 0xFFFFFFFF, 0x00000000); // do nothing
		//	rtd_maskl(PLL27X_REG_SYS_PLL_27X4_reg,0xFDFC0FFF,0x0201F000);//[25]PLL_L2H_CML_POW [17:16]PLL27X_CK108M_DIV = 0x1, divide by 4 (use when VCO=432MHz) [15:14]PLL27X_YPPADC_CKO_SEL = 0x3,YPPADC clock outpu 11:108M [13]PLL27X_YPPADC_CKO_EN[12]PLL27X_YPPADC_CK54M_EN
		rtd_maskl(PLL27X_REG_SYS_PLL_27X4_reg, 0xFDFC0FFF, 0x0202F000); //[25]PLL_L2H_CML_POW [17:16]PLL27X_CK108M_DIV = 0x2, divide by 4 (use when VCO=432MHz) [15:14]PLL27X_YPPADC_CKO_SEL = 0x3,YPPADC clock outpu 11:108M [13]PLL27X_YPPADC_CKO_EN[12]PLL27X_YPPADC_CK54M_EN

		rtd_maskl(PLL27X_REG_SYS_PLL_27X3_reg, 0x00000000, 0x00000000); //Power off and rst PLL27x
		rtd_maskl(PLL27X_REG_SYS_PLL_27X3_reg, 0x00000000, 0x00000017); //Power on PLL27x [4]PLL27X_PS_EN[3]PLL27X_PS_DIV2[2]PLL27X_VCORSTB[1]PLL27X_RSTB[0]PLL27X_POW
		mdelay(5);
#endif

		//tve reset
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_tve_mask | SYS_REG_SYS_SRST1_write_data_mask); //[26]RSTN_TVE
		//tve clock enable - digital
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_tve_mask | SYS_REG_SYS_CLKEN1_write_data_mask); //[26]CLKEN_TVE
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int TVE2_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_tve_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
	} else {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_tve_mask);
	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int TVE3_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		//tve clock disable - digital
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_tve_mask); //[26]CLKEN_TVE
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int TVE4_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_tve_mask | SYS_REG_SYS_SRST1_write_data_mask);
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int TVE5_CriticalRegister(enum CRT_CLK clken)
{

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		//check[22]CLKEN_VDEC
		if (!(rtd_inl(SYS_REG_SYS_CLKEN1_reg) & SYS_REG_SYS_CLKEN1_clken_vdec_mask)) {
			rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_vdec_mask | SYS_REG_SYS_SRST1_write_data_mask); //[22]RSTN_VDEC
			rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_vdec_mask | SYS_REG_SYS_CLKEN1_write_data_mask); //[22]CLKEN_VDEC
		}

		//check [11]RSTN_APLL_ADC
		if (!(rtd_inl(SYS_REG_SYS_CLKEN1_reg) & SYS_REG_SYS_CLKEN1_clken_apll_adc_mask)) {
			rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_apll_adc_mask | SYS_REG_SYS_SRST1_write_data_mask); //[11]RSTN_APLL_ADC
			rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_apll_adc_mask | SYS_REG_SYS_CLKEN1_write_data_mask); //[11]CLKEN_APLL_ADC
		}

		//check [27]RSTN_ATVIN2[26]RSTN_ATVIN
		if (!(rtd_inl(SYS_REG_SYS_CLKEN2_reg) & SYS_REG_SYS_CLKEN2_clken_atvin_vd_mask)) {
			rtd_outl(SYS_REG_SYS_SRST2_reg,
				SYS_REG_SYS_SRST2_rstn_atvin_mask |
				SYS_REG_SYS_SRST2_rstn_atvin2_mask |
				SYS_REG_SYS_SRST2_write_data_mask); //[27]RSTN_ATVIN2[26]RSTN_ATVIN
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_atvin_vd_mask | SYS_REG_SYS_CLKEN2_write_data_mask); //[27]CLKEN_ATVIN_VD
		}

		//check [26]CLKEN_ATVIN_IFD
		if (!(rtd_inl(SYS_REG_SYS_CLKEN2_reg) & SYS_REG_SYS_CLKEN2_clken_atvin_ifd_mask)) {
			rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_atvin_ifd_mask | SYS_REG_SYS_CLKEN2_write_data_mask); //[26]CLKEN_ATVIN_IFD
		}

		//check [15]CLKEN_IFADC
		if (!(rtd_inl(SYS_REG_SYS_CLKEN1_reg) & SYS_REG_SYS_CLKEN1_clken_ifadc_mask)) {
			rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_ifadc_mask | SYS_REG_SYS_SRST1_write_data_mask); //[15]RSTN_IFADC
			rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_ifadc_mask | SYS_REG_SYS_CLKEN1_write_data_mask); //[15]CLKEN_IFADC
		}

		//check [23]CLKEN_IF_DEMOD
		if (!(rtd_inl(SYS_REG_SYS_CLKEN1_reg) & SYS_REG_SYS_CLKEN1_clken_if_demod_mask)) {
			rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_if_demod_mask | SYS_REG_SYS_CLKEN1_write_data_mask); //[23]CLKEN_IF_DEMOD
		}

		rtd_maskl(SYS_REG_SYS_CLKSEL_reg, 0xFFFCFFFF, 0x00020000); //[17]ATVIN_CLK_SEL] = 0x1, 0x0: IFD, 0x1: VD [16]ATVIN_VD_CLK_SEL = 0x0, 0x0: 108MHz 0x1: 27MHz

#if 0//Pll27x setting in bootcode
		//initialize clk 27x domain for VD
		////PLL27x Clock : 108M
		//	rtd_maskl(PLL27X_REG_SYS_PLL_27X1_reg,0xFFFFFFE0,0x0000000E);//432MHzPLL27X_M[6:0] = 0x0E
		rtd_maskl(PLL27X_REG_SYS_PLL_27X1_reg, 0xFFFFFFE0, 0x0000000A); //432MHzPLL27X_M[6:0] = 0x0A
		rtd_maskl(PLL27X_REG_SYS_PLL_27X2_reg, 0xFFFFFFFF, 0x00000000); // do nothing
		//	rtd_maskl(PLL27X_REG_SYS_PLL_27X4_reg,0xFDFC0FFF,0x0201F000);//[25]PLL_L2H_CML_POW [17:16]PLL27X_CK108M_DIV = 0x1, divide by 4 (use when VCO=432MHz) [15:14]PLL27X_YPPADC_CKO_SEL = 0x3,YPPADC clock outpu 11:108M [13]PLL27X_YPPADC_CKO_EN[12]PLL27X_YPPADC_CK54M_EN
		rtd_maskl(PLL27X_REG_SYS_PLL_27X4_reg, 0xFDFC0FFF, 0x0202F000); //[25]PLL_L2H_CML_POW [17:16]PLL27X_CK108M_DIV = 0x2, divide by 4 (use when VCO=432MHz) [15:14]PLL27X_YPPADC_CKO_SEL = 0x3,YPPADC clock outpu 11:108M [13]PLL27X_YPPADC_CKO_EN[12]PLL27X_YPPADC_CK54M_EN
		rtd_maskl(PLL27X_REG_SYS_PLL_27X3_reg, 0x00000000, 0x00000000); //Power off and rst PLL27x
		rtd_maskl(PLL27X_REG_SYS_PLL_27X3_reg, 0x00000000, 0x00000017); //Power on PLL27x [4]PLL27X_PS_EN[3]PLL27X_PS_DIV2[2]PLL27X_VCORSTB[1]PLL27X_RSTB[0]PLL27X_POW
		//ScalerTimer_DelayXms(5);
		mdelay(5);
#endif
		//tve reset
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_tve_mask | SYS_REG_SYS_SRST1_write_data_mask); //[26]RSTN_TVE
		//tve clock enable - digital
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_tve_mask | SYS_REG_SYS_CLKEN1_write_data_mask); //[26]CLKEN_TVE

	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int VDC1_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		/*004DC:[25]PLL_L2H_CML_POW[13]PLL27X_YPPADC_CKO_EN[8]PLL27X_IFADC_CKO_EN*/
		pll27x_reg_sys_pll_27x4_RBUS sys_pll_27x4_reg; 
		sys_pll_27x4_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X4_reg);
		sys_pll_27x4_reg.pll_l2h_cml_pow = 1;
		sys_pll_27x4_reg.pll27x_yppadc_cko_en = 1;
		sys_pll_27x4_reg.pll27x_ifadc_cko_en = 1;
		rtd_outl(PLL27X_REG_SYS_PLL_27X4_reg, sys_pll_27x4_reg.regValue);

		/* 0_0104: [22]RSTN_VDEC[21]RSTN_VDEC2[15]RSTN_IFADC for vdac[11]RSTN_APLL_ADC */
		/* 0_0108: [27]RSTN_ATVIN2[26]RSTN_ATVIN */
		rtd_outl(SYS_REG_SYS_SRST1_reg,
			SYS_REG_SYS_SRST1_rstn_vdec_mask |
			SYS_REG_SYS_SRST1_rstn_vdec2_mask |
			SYS_REG_SYS_SRST1_rstn_ifadc_mask |
			SYS_REG_SYS_SRST1_rstn_apll_adc_mask |
			SYS_REG_SYS_SRST1_write_data_mask);
		rtd_outl(SYS_REG_SYS_SRST2_reg,
			SYS_REG_SYS_SRST2_rstn_atvin_mask |
			SYS_REG_SYS_SRST2_rstn_atvin2_mask |
			SYS_REG_SYS_SRST2_write_data_mask);

		/* 0_0114: [22]CLKEN_VDEC[15]CLKEN_IFADC for vdac[11]CLKEN_APLL_ADC */
		/* 0_0118: [27]CLKEN_ATVIN_VD[26]CLKEN_ATVIN_IFD for vd_ifd_inuput */
		rtd_outl(SYS_REG_SYS_CLKEN1_reg,
			SYS_REG_SYS_CLKEN1_clken_vdec_mask |
			SYS_REG_SYS_CLKEN1_clken_ifadc_mask |
			SYS_REG_SYS_CLKEN1_clken_apll_adc_mask |
			SYS_REG_SYS_CLKEN1_write_data_mask);
		rtd_outl(SYS_REG_SYS_CLKEN2_reg,
			SYS_REG_SYS_CLKEN2_clken_atvin_vd_mask |
			SYS_REG_SYS_CLKEN2_clken_atvin_ifd_mask |
			SYS_REG_SYS_CLKEN2_write_data_mask);
		#if 0
		/*vd reset*/
		rtd_outl(SYS_REG_SYS_SRST1_reg,
			SYS_REG_SYS_SRST1_rstn_vdec_mask |
			SYS_REG_SYS_SRST1_rstn_vdec2_mask);
		mdelay(5);
		rtd_outl(SYS_REG_SYS_SRST1_reg,
			SYS_REG_SYS_SRST1_rstn_vdec_mask |
			SYS_REG_SYS_SRST1_rstn_vdec2_mask |
			SYS_REG_SYS_SRST1_write_data_mask);
		#endif 
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int VDC2_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_vdec_mask);
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int VDC3_CriticalRegister(enum CRT_CLK clken, void *private_data)
{
	pll27x_reg_sys_pll_27x3_RBUS sys_pll_27x3_reg;	/* 0_04d8 */
	pll27x_reg_sys_pll_27x4_RBUS sys_pll_27x4_reg;	/* 0_04dc */

	unsigned char ucRet = true;

	//hw_semaphore_try_lock();
	if (clken == CLK_ON) {

#if 0
		printk(KERN_EMERG "0xb8000204=%x\n", rtd_inl(0xb8000204));

		printk(KERN_EMERG "0xb8000104=%x\n", rtd_inl(0xb8000104));
		printk(KERN_EMERG "0xb8000108=%x\n", rtd_inl(0xb8000108));
		printk(KERN_EMERG "0xb800010c=%x\n", rtd_inl(0xb800010c));
		printk(KERN_EMERG "0xb8000110=%x\n", rtd_inl(0xb8000110));
		printk(KERN_EMERG "0xb8000114=%x\n", rtd_inl(0xb8000114));
		printk(KERN_EMERG "0xb8000118=%x\n", rtd_inl(0xb8000118));
		printk(KERN_EMERG "0xb800011c=%x\n", rtd_inl(0xb800011c));

		printk(KERN_EMERG "0xb80004d4=%x\n", rtd_inl(0xb80004d4));
		printk(KERN_EMERG "0xb80004d8=%x\n", rtd_inl(0xb80004d8));
#endif

		sys_pll_27x3_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X3_reg);
		sys_pll_27x4_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X4_reg);

		if (sys_pll_27x3_reg.pll27x_pow == 1 &&
			sys_pll_27x3_reg.pll27x_rstb == 1 &&
			sys_pll_27x3_reg.pll27x_vcorstb == 1 &&
			sys_pll_27x3_reg.pll27x_ps_en == 1 &&
			/* sys_pll_27x4_reg.pll27x_yppadc_cko_en == 1 && */
			/* sys_pll_27x4_reg.pll27x_yppadc_cko_sel == 3 && */
			sys_pll_27x4_reg.pll_l2h_cml_pow == 1) {

			ucRet = true;

			//hw_semaphore_unlock();
			return CRT_SUCCESS;
		} else {
			ucRet = false;

		}
	} else {

	}

	*(int *)private_data = ucRet;

	//hw_semaphore_unlock();

	return CRT_SUCCESS;
}
int VDC4_CriticalRegister(enum CRT_CLK clken, void *private_data)
{

#if 0//Pll27x setting in bootcode
	pll27x_reg_sys_pll_27x1_RBUS sys_pll_27x1_reg;	/* 0_04d0 */
	pll27x_reg_sys_pll_27x2_RBUS sys_pll_27x2_reg;	/* 0_04d4 */
	pll27x_reg_sys_pll_27x3_RBUS sys_pll_27x3_reg;	/* 0_04d8 */
	pll27x_reg_sys_pll_27x4_RBUS sys_pll_27x4_reg;	/* 0_04dc */

	int freq = *(int *)private_data;

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		sys_pll_27x1_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X1_reg);
		sys_pll_27x2_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X2_reg);
		sys_pll_27x3_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X3_reg);
		sys_pll_27x4_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X4_reg);

		switch (freq) {
		case VDC_PLL27x_CLK_540M:
			sys_pll_27x1_reg.pll27x_m = 0x12;
			sys_pll_27x2_reg.pll27x_ps_54m_delay = 0x3;
			break;
		default:
		case VDC_PLL27x_CLK_432M:
			sys_pll_27x1_reg.pll27x_m = 0x0e;
			sys_pll_27x2_reg.pll27x_ps_54m_delay = 0x2;
			break;
		case VDC_PLL27x_CLK_324M:
			sys_pll_27x1_reg.pll27x_m = 0x0a;
			sys_pll_27x2_reg.pll27x_ps_54m_delay = 0x0;
			break;
		case VDC_PLL27x_CLK_648M:
			sys_pll_27x1_reg.pll27x_m = 0x16;
			sys_pll_27x2_reg.pll27x_ps_54m_delay = 0x1;
			break;
		}
		sys_pll_27x1_reg.pll27x_n = 0;
		sys_pll_27x4_reg.pll27x_yppadc_cko_en = 1;
		sys_pll_27x4_reg.pll27x_yppadc_cko_sel = 3; /* 108M */
		sys_pll_27x4_reg.pll27x_ck108m_div = freq;
		sys_pll_27x4_reg.pll_l2h_cml_pow = 1;
		rtd_outl(PLL27X_REG_SYS_PLL_27X1_reg, sys_pll_27x1_reg.regValue);
		rtd_outl(PLL27X_REG_SYS_PLL_27X2_reg, sys_pll_27x2_reg.regValue);
		rtd_outl(PLL27X_REG_SYS_PLL_27X4_reg, sys_pll_27x4_reg.regValue);
#if 0 //frank@0813 mark below code avoid VDC register Rbustimeout
		/* 0_04d8: [4]PLL27X_PS_EN[2]PLL27X_VCORSTB[1]PLL27X_RSTB[0]PLL27X_POW
			=> set 0, reset first */
		sys_pll_27x3_reg.pll27x_pow = 0;
		sys_pll_27x3_reg.pll27x_rstb = 0;
		sys_pll_27x3_reg.pll27x_vcorstb = 0;
		sys_pll_27x3_reg.pll27x_ps_en = 0;
		rtdf_outl(PLL27X_REG_SYS_PLL_27X3_reg, sys_pll_27x3_reg.regValue);
#endif
		/* power on pll 27x */
		sys_pll_27x3_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X3_reg);
		/* 0_04d8: [4]PLL27X_PS_EN[2]PLL27X_VCORSTB[1]PLL27X_RSTB[0]PLL27X_POW
			=> set 1, Power on! */
		sys_pll_27x3_reg.pll27x_pow = 1;
		sys_pll_27x3_reg.pll27x_rstb = 1;
		sys_pll_27x3_reg.pll27x_vcorstb = 1;
		sys_pll_27x3_reg.pll27x_ps_en = 1;
		rtd_outl(PLL27X_REG_SYS_PLL_27X3_reg, sys_pll_27x3_reg.regValue);

	} else {

	}
	hw_semaphore_unlock();
#endif
	return CRT_SUCCESS;
}
int VDC5_CriticalRegister(enum CRT_CLK clken, void *private_data)
{
	unsigned int regValue;

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X1_reg);
		*((unsigned int *)private_data) = regValue;
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}


int VDC6_CriticalRegister(enum CRT_CLK clken, void *private_data)
{
	//pll27x_reg_sys_pll_27x3_RBUS sys_pll_27x3_reg;	/* 0_04d8 */
	vdtop_misc_control_RBUS misc_control_reg;	/* 9764 */
	unsigned int clkReg = *(unsigned int *)private_data;

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		//sys_pll_27x3_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X3_reg);
		//sys_pll_27x3_reg.pll27x_ps_div2 = 0;

		misc_control_reg.regValue = rtd_inl(VDTOP_MISC_CONTROL_reg);
		switch (clkReg) {
		case VDC_PLL27x_CLK_648M:
			//sys_pll_27x3_reg.pll27x_ps_div2 = 1;
			misc_control_reg.swallow_freq_sel = 2;
			break;
		default:
		case VDC_PLL27x_CLK_540M:
			misc_control_reg.swallow_freq_sel = 1;
			break;
		case VDC_PLL27x_CLK_432M:
			misc_control_reg.swallow_freq_sel = 0;
			break;
		case VDC_PLL27x_CLK_324M:
			misc_control_reg.swallow_freq_sel = 2;
			break;
		}
		rtd_outl(VDTOP_MISC_CONTROL_reg, misc_control_reg.regValue);
		//rtd_outl(PLL27X_REG_SYS_PLL_27X3_reg, sys_pll_27x3_reg.regValue);
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}
int VDC7_CriticalRegister(enum CRT_CLK clken)
{
	/* b800_0104[21] */
	sys_reg_sys_srst1_RBUS sys_srst1_reg;

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		/* sw reset for video decoder */
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_vdec2_mask);
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}
int VDC8_CriticalRegister(enum CRT_CLK clken)
{
	/* b800_0104[21] */
	sys_reg_sys_srst1_RBUS sys_srst1_reg;

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_vdec2_mask | SYS_REG_SYS_SRST1_write_data_mask);
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}


int VDC9_CriticalRegister(enum CRT_CLK clken, void *private_data)
{
	sys_reg_sys_srst1_RBUS sys_srst1_reg;		/* 0_0104 */
	unsigned char ucRet = true;

	//hw_semaphore_try_lock();
	if (clken == CLK_ON) {

		sys_srst1_reg.regValue = rtd_inl(SYS_REG_SYS_SRST1_reg);

#if 0
		printk(KERN_EMERG "0xb8000204=%x\n", rtd_inl(0xb8000204));

		printk(KERN_EMERG "0xb8000104=%x\n", rtd_inl(0xb8000104));
		printk(KERN_EMERG "0xb8000108=%x\n", rtd_inl(0xb8000108));
		printk(KERN_EMERG "0xb800010c=%x\n", rtd_inl(0xb800010c));
		printk(KERN_EMERG "0xb8000110=%x\n", rtd_inl(0xb8000110));
		printk(KERN_EMERG "0xb8000114=%x\n", rtd_inl(0xb8000114));
		printk(KERN_EMERG "0xb8000118=%x\n", rtd_inl(0xb8000118));
		printk(KERN_EMERG "0xb800011c=%x\n", rtd_inl(0xb800011c));

		printk(KERN_EMERG "0xb80004d4=%x\n", rtd_inl(0xb80004d4));
		printk(KERN_EMERG "0xb80004d8=%x\n", rtd_inl(0xb80004d8));
#endif


		/* 0_0104: [22]RSTN_VDEC[21]RSTN_VDEC2[15]RSTN_IFADC for vdac[11]RSTN_APLL_ADC */
		if (sys_srst1_reg.rstn_vdec == 1 &&
			sys_srst1_reg.rstn_vdec2 == 1 &&
			sys_srst1_reg.rstn_ifadc == 1 &&
			sys_srst1_reg.rstn_apll_adc == 1) {

			ucRet = true;

			//hw_semaphore_unlock();
			return CRT_SUCCESS;
		}
		// VD clock is not setted, set it.
		else {
			ucRet = false;
		}
	} else {

	}

	*(int *)private_data = ucRet;

	//hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int VDC10_CriticalRegister(enum CRT_CLK clken)
{	/* softreset for video decoder */
//	int flag_pll27x3;
	int flag_avdin;
	
	/* b800_0104[21] */

	// Set AVD_SW_Reset_used = 1
//	RTD_SWSEM_27x3_LOCK(flag_pll27x3);  //to gurantee PLL27x3 clock source.
	RTD_SWSEM_AVDIN_LOCK(flag_avdin); //to avoid downstream access AVDIN clock domain.

	hw_semaphore_try_lock();

	// Disable reset bit
	rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_vdec2_mask);
	mdelay(1);
	// Enable Reset bit
	rtd_outl(SYS_REG_SYS_SRST1_reg, SYS_REG_SYS_SRST1_rstn_vdec2_mask | SYS_REG_SYS_SRST1_write_data_mask);

	hw_semaphore_unlock();

	//Clear AVD_SW_Reset_used = 0
	RTD_SWSEM_AVDIN_UNLOCK(flag_avdin); //to allow downstream access AVDIN clock domain.
//	RTD_SWSEM_27x3_UNLOCK(flag_pll27x3);  //free for PLL27x3 clock source operation.

	return CRT_SUCCESS;
}


int VDCInput2_CriticalRegister(enum CRT_CLK clken)
{
	pll27x_reg_sys_pll_27x4_RBUS sys_pll_27x4_reg; 		/* 0_04dc */

	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		sys_pll_27x4_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X4_reg);
		sys_pll_27x4_reg.pll27x_yppadc_ck54m_en = 0x1;		/* 0_04dc[12] enable 54M */
		rtd_outl(PLL27X_REG_SYS_PLL_27X4_reg, sys_pll_27x4_reg.regValue);
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}
int VDCInput3_CriticalRegister(enum CRT_CLK clken)
{
	pll27x_reg_sys_pll_27x4_RBUS sys_pll_27x4_reg; /* 0_04dc */
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		sys_pll_27x4_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X4_reg);
		sys_pll_27x4_reg.pll27x_yppadc_ck54m_en = 0x0;	/* 0_04dc[12] disable 54M */
		rtd_outl(PLL27X_REG_SYS_PLL_27X4_reg, sys_pll_27x4_reg.regValue);
	} else {

	}
	hw_semaphore_unlock();

	return CRT_SUCCESS;
}

int Thermal_CriticalRegister(enum CRT_CLK clken)
{
	hw_semaphore_try_lock();
	if (clken == CLK_ON) {
		rtd_outl(SYS_REG_SYS_SRST2_reg, SYS_REG_SYS_SRST2_rstn_tm_mask | SYS_REG_SYS_SRST2_write_data_mask);//release thermal rst
		rtd_outl(SYS_REG_SYS_CLKEN2_reg, SYS_REG_SYS_CLKEN2_clken_tm_mask | SYS_REG_SYS_CLKEN2_write_data_mask);//enable thermal clk
	} else {
	}
	hw_semaphore_unlock();
	return CRT_SUCCESS;

}

void CRT_CLK_OnOff(enum CRT_MODULE module_ip, enum CRT_CLK clken, void *private_data)
{

	unsigned long flags;

	spin_lock_irqsave(&crt_lock, flags);
	CRT_CLK_ModuleName(module_ip);

	switch (module_ip) {
#ifdef CONFIG_USB
	case USB:
		if (USB_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("USB CRT setting fail\n");
		}
		break;
#endif
	case IrDA:
		if (IrDA_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("IrDA CRT setting fail\n");
		}
		break;

	case I2C:
		if (I2C_CriticalRegister(clken , private_data) == CRT_FAIL) {
			pr_warn("I2C CRT setting fail\n");
		}
		break;

	case UART:
		if (UART_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("UART CRT setting fail\n");
		}
		break;

	case SE:
		if (SE_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("SE CRT setting fail\n");
		}
		break;

	case NAND:
		if (NAND_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("NAND CRT setting fail\n");
		}
		break;

	case MD:
		if (MD_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("MD CRT setting fail\n");
		}
		break;
	case PCMCIA:
		if (PCMCIA_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("PCMCIA CRT setting fail\n");
		}
		break;

	case GPIO:
		if (GPIO_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("GPIO CRT setting fail\n");
		}
		break;

	case PWM:
		if (PWM_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("PWM CRT setting fail\n");
		}
		break;

	case EMMC:
		if (EMMC_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("EMMC CRT setting fail\n");
		}
		break;

	case SDIO:
		if (SDIO_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("SDIO CRT setting fail\n");
		}
		break;

	case SMC:
		if (SMC_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("SMC CRT setting fail\n");
		}
		break;

	case CP:
		if (CP_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("CP CRT setting fail\n");
		}
		break;

	case TP:
		if (TP_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("TP CRT setting fail\n");
		}
		break;

        case TPOUT:
                if (TPOUT_CriticalRegister(clken) == CRT_FAIL) {
                        pr_warn("TPOUT CRT setting fail\n");
                }
                break;

	case MHL:
		if (MHL_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("MHL CRT setting fail\n");
		}
		break;

	case HDMI:
		if (HDMI_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("HDMI CRT setting fail\n");
		}
		break;

	case GDMA:
		if (GDMA_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("GDMA CRT setting fail\n");
		}
		break;
	case VBI:
		if (VBI_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("VBI CRT setting fail\n");
		}
		break;
	case ETH:
		if (ETH_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("ETH CRT setting fail\n");
		}
		break;
	case DISEQC:
		if (DiseqC_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("DiseqC CRT setting fail\n");
		}
		break;
	case LSADC:
		if (LSADC_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("LSADC CRT setting fail\n");
		}
		break;
	case CEC:
		if (CEC_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("CEC CRT setting fail\n");
		}
		break;
	case ANADEMOD:
		if (ADEMOD_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("ANADEMOD CRT setting fail\n");
		}
		break;
	case DIGDEMOD:
		if (DDEMOD_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("DIGDEMOD CRT setting fail\n");
		}
		break;
	case DIGDEMOD_ADC_EN:
		if (DDEMOD_ADC_EN_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("DEMOD_ADC_EN CRT setting fail\n");
		}
		break;
	case DIGDEMOD_IMG_EN:
		if (DDEMOD_IMG_EN_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("DIGDEMOD_IMG_EN CRT setting fail\n");
		}
		break;
	case DIGDEMOD_HDIC_EN:
		if (DDEMOD_HDIC_EN_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("DIGDEMOD_HDIC_EN CRT setting fail\n");
		}
		break;
	case DIGDEMOD_RTK_EN:
		if (DDEMOD_RTK_EN_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("DIGDEMOD_RTK_EN CRT setting fail\n");
		}
		break;

	case SCALER_ADC_CLK_1:
		if (ADC_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("ADC CRT setting fail\n");
		}
		break;

	case SCALER_VFEDEV_1:
		if (VFEDEV_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("VFEDEV CRT setting fail\n");
		}
		break;
	
	case SCALER_AUTO_CLK_1:
		if (Auto_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("Auto 1 CRT setting fail\n");
		}
		break;
		
	case SCALER_AUTO_CLK_2:
		if (Auto2_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("Auto 2 CRT setting fail\n");
		}
		break;

	case SCALER_VO_1:
		if (VO_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("VO CRT setting fail\n");
		}
		break;
	case SCALER_TVE_1:
		if (TVE1_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("TVE 1 CRT setting fail\n");
		}
		break;
	case SCALER_TVE_2:
		if (TVE2_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("TVE 2 CRT setting fail\n");
		}
		break;
	case SCALER_TVE_3:
		if (TVE3_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("TVE 3 CRT setting fail\n");
		}
		break;
	case SCALER_TVE_4:
		if (TVE4_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("TVE 4 CRT setting fail\n");
		}
		break;
	case SCALER_TVE_5:
		if (TVE5_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("TVE 5 CRT setting fail\n");
		}
		break;
	case SCALER_VDC_1:
		if (VDC1_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("VDC 1 CRT setting fail\n");
		}
		break;
	case SCALER_VDC_2:
		if (VDC2_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("VDC 2 CRT setting fail\n");
		}
		break;
	case SCALER_VDC_3:
		if (VDC3_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("VDC 3 CRT setting fail\n");
		}
		break;
	case SCALER_VDC_4:
		if (VDC4_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("VDC 4 CRT setting fail\n");
		}
		break;
	case SCALER_VDC_5:
		if (VDC5_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("VDC 5 CRT setting fail\n");
		}
		break;
	case SCALER_VDC_6:
		if (VDC6_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("VDC 6 CRT setting fail\n");
		}
		break;
	case SCALER_VDC_7:
		if (VDC7_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("VDC 7 CRT setting fail\n");
		}
		break;
	case SCALER_VDC_8:
		if (VDC8_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("VDC 8 CRT setting fail\n");
		}
		break;

	case SCALER_VDC_9:
		if (VDC9_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("VDC 9 CRT setting fail\n");
		}
		break;

	case SCALER_VDC_10:
		if (VDC10_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("VDC 10 CRT setting fail\n");
		}
		break;

	case SCALER_VDC_INPUT_2:
		if (VDCInput2_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("VDC_INPUT 2 CRT setting fail\n");
		}
		break;
	case SCALER_VDC_INPUT_3:
		if (VDCInput3_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("VDC INPUT 3 CRT setting fail\n");
		}
		break;
		
	case GPU:
		if (GPU_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("GPU CRT setting fail\n");
		}
		break;
	case DOLBY_HDR:
		if (DOLBY_HDR_CriticalRegister(clken, private_data) == CRT_FAIL) {
			pr_warn("GPU CRT setting fail\n");
		}
		break;		
	case THERMAL_SENSOR:
		if (Thermal_CriticalRegister(clken) == CRT_FAIL) {
			pr_warn("Thermal CRT setting fail\n");
		}
		break;
	default:
		/* not in module list call BUS() to stop system */
		BUG();
		break;
	}

	spin_unlock_irqrestore(&crt_lock, flags);
}
EXPORT_SYMBOL(CRT_CLK_OnOff);

char * CRT_CLK_ModuleName(enum CRT_MODULE module_ip)
{

	strncpy(lastModuleName, moduleName, sizeof(lastModuleName));
	memset(moduleName, 0, sizeof(moduleName));
	switch (module_ip) {

	case USB:
		strncpy(moduleName, "USB", 3);
		break;

	case IrDA:
		strncpy(moduleName, "IrDA", 4);
		break;

	case I2C:
		strncpy(moduleName, "I2C", 3);
		break;

	case UART:
		strncpy(moduleName, "UART", 4);
		break;

	case SE:
		strncpy(moduleName, "SE", 2);
		break;

	case NAND:
		strncpy(moduleName, "NAND", 4);
		break;

	case MD:
		strncpy(moduleName, "MD", 2);
		break;

	case PCMCIA:
		strncpy(moduleName, "PCMCIA", 6);
		break;

	case GPIO:
		strncpy(moduleName, "GPIO", 4);
		break;

	case PWM:
		strncpy(moduleName, "PWM", 3);
		break;

	case EMMC:
		strncpy(moduleName, "EMMC", 4);
		break;

	case SDIO:
		strncpy(moduleName, "SDIO", 4);
		break;

	case SMC:
		strncpy(moduleName, "SMC", 3);
		break;

	case CP:
		strncpy(moduleName, "CP", 2);
		break;

	case TP:
		strncpy(moduleName, "TP", 2);
		break;

	case GDMA:
		strncpy(moduleName, "GDMA", 4);
		break;

	case VBI:
		strncpy(moduleName, "VBI", 3);
		break;

	case ETH:
		strncpy(moduleName, "ETH", 3);
		break;

	case ANADEMOD:
		strncpy(moduleName, "ANADEMOD", 7);
		break;

	case DIGDEMOD:
		strncpy(moduleName, "DIGDEMOD", 7);
		break;

	//====scaler=========
	case SCALER_ADC_CLK_1:
		strncpy(moduleName, "SCALER_ADC_CLK_1", 17);
		break;


	case SCALER_AUTO_CLK_1:
		strncpy(moduleName, "SCALER_AUTO_CLK_1", 18);
		break;


	case SCALER_AUTO_CLK_2:
		strncpy(moduleName, "SCALER_AUTO_CLK_2", 18);
		break;

	case SCALER_VFEDEV_1:
		strncpy(moduleName, "SCALER_VFEDEV_1", 16);
		break;


	case SCALER_TVE_1:
		strncpy(moduleName, "SCALER_TVE_1", 12);
		break;

	case SCALER_TVE_2:
		strncpy(moduleName, "SCALER_TVE_2", 12);
		break;


	case SCALER_TVE_3:
		strncpy(moduleName, "SCALER_TVE_3", 12);
		break;

	case SCALER_TVE_4:
		strncpy(moduleName, "SCALER_TVE_4", 12);
		break;

	case SCALER_TVE_5:
		strncpy(moduleName, "SCALER_TVE_5", 12);
		break;

	case SCALER_VDC_1:
		strncpy(moduleName, "SCALER_VDC_1", 12);
		break;

	case SCALER_VDC_2:
		strncpy(moduleName, "SCALER_VDC_2", 12);
		break;

	case SCALER_VDC_3:
		strncpy(moduleName, "SCALER_VDC_3", 12);
		break;

	case SCALER_VDC_4:
		strncpy(moduleName, "SCALER_VDC_4", 12);
		break;

	case SCALER_VDC_5:
		strncpy(moduleName, "SCALER_VDC_5", 12);
		break;

	case SCALER_VDC_6:
		strncpy(moduleName, "SCALER_VDC_6", 12);
		break;

	case SCALER_VDC_7:
		strncpy(moduleName, "SCALER_VDC_7", 12);
		break;

	case SCALER_VDC_8:
		strncpy(moduleName, "SCALER_VDC_8", 12);
		break;

	case SCALER_VDC_9:
		strncpy(moduleName, "SCALER_VDC_9", 12);
		break;

	case SCALER_VDC_10:
		strncpy(moduleName, "SCALER_VDC_10", 13);
		break;

	case SCALER_VDC_INPUT_1:
		strncpy(moduleName, "SCALER_VDC_INPUT_1", 18);
		break;

	case SCALER_VDC_INPUT_2:
		strncpy(moduleName, "SCALER_VDC_INPUT_2", 18);
		break;


	case SCALER_VDC_INPUT_3:
		strncpy(moduleName, "SCALER_VDC_INPUT_3", 18);
		break;

	case SCALER_VO_1:
		strncpy(moduleName, "SCALER_VO_1", 11);
		break;

	case THERMAL_SENSOR:
		strncpy(moduleName, "Thermal", 8);
		break;


	default:
		/* not in module list call BUS() to stop system */
		snprintf(moduleName,sizeof(moduleName)-1,"HEX: %x",module_ip);
		break;
	}

	return moduleName;
}


/* reg info : bits-width, regName */
typedef struct reg_info {
	int bit_width;
	char regName[32];
} regInfo;

regInfo crt_sys_srst_0_reg[] = {
	{1, "RSTN_Ib_sb1"},
	{1, "RSTN_Ib_sb2"},
	{1, "RSTN_Ib_sb3"},
	{1, "RSTN_Ib_ve"},
	{1, "RSTN_Ib_ve2"},
	{1, "RSTN_Ib_vp9"},
	{1, "RSTN_Ib_tvsb1"},
	{1, "RSTN_ND"},
	{1, "RSTN_AKL"},
	{1, "RSTN_DSC"},
	{1, "RSTN_SCE"},
	{1, "RSTN_KT"},
	{1, "RSTN_Ib_gpu"},
	{1, "RSTN_KCPU"},
	{1, "RSTN_VDE2"},
	{1, "RSTN_VE2_P2"},
	{1, "RSTN_VE2"},
	{1, "RSTN_VCPU2"},
	{1, "RSTN_VP9"},
	{1, "RSTN_ACPU"},
	{1, "RSTN_Ib_tvsb2"},
	{1, "RSTN_Ib_tvsb3"},
	{1, "RSTN_Ib_tvsb4"},
	{1, "RSTN_Ib_tvsb5"},
	{1, "RSTN_SCPU_WRAP"},
	{1, "RSTN_VDE"},
	{1, "RSTN_VE_P2"},
	{1, "RSTN_VE"},
	{1, "RSTN_VCPU"},
	{1, "RSTN_AE"},
	{1, "RSTN_SCPU"},
	{1, "RSTN_PLLREG"},
};

regInfo crt_sys_srst_1_reg[] = {
	{1, "RSTN_TVSB1"},
	{1, "RSTN_TVSB2"},
	{1, "RSTN_TVSB3"},
	{1, "RSTN_TVSB4"},
	{1, "RSTN_TVSB5"},
	{1, "RSTN_TVE"},
	{1, "RSTN_DCPHY"},
	{1, "RSTN_DCU"},
	{1, "RSTN_IF_DEMOD"},
	{1, "RSTN_VDEC"},
	{1, "RSTN_VDEC2"},
	{1, "RSTN_VBIS0"},
	{1, "RSTN_AUDIO2_DAC"},
	{1, "RSTN_AUDIO_ADC"},
	{1, "RSTN_AUDIO_DAC"},
	{1, "RSTN_AUDIO"},
	{1, "RSTN_IFADC"},
	{1, "RSTN_CBUS"},
	{1, "RSTN_OFFMS"},
	{1, "RSTN_ME"},
	{1, "RSTN_APLL_ADC"},
	{1, "RSTN_HDMI"},
	{1, "RSTN_HDMITX"},
	{1, "RSTN_TP"},
	{1, "RSTN_CP"},
	{1, "RSTN_MD"},
	{1, "RSTN_SE"},
	{1, "Reserved"},
	{1, "RSTN_3D_GDE"},
	{1, "RSTN_VODMA"},
	{1, "RSTN_DISPIM"},
	{1, "RSTN_DISP"},
};

regInfo crt_sys_srst_2_reg[] = {
	{2, "Reserved"},
	{1, "Reserved"},
	{1, "RSTN_TM"},
	{1, "RSTN_ATVIN2"},
	{1, "RSTN_ATVIN"},
	{2, "Dummy"},
	{1, "RSTN_EMMC"},
	{1, "Reserved"},
	{1, "RSTN_BISTREG"},
	{2, "Dummy"},
	{1, "RSTN_USB"},
	{1, "RSTN_OTG"},
	{1, "Reserved"},
	{2, "Dummy"},
	{1, "RSTN_IRTX"},
	{1, "RSTN_PADMUX"},
	{1, "RSTN_DTV_DEMOD"},
	{1, "RSTN_MISC"},
	{1, "RSTN_PWM"},
	{1, "RSTN_UART1"},
	{1, "RSTN_UART2"},
	{1, "RSTN_SC1"},
	{1, "RSTN_GPIO"},
	{1, "RSTN_I2C1"},
	{1, "RSTN_I2C2"},
	{1, "RSTN_NF"},
	{1, "RSTN_SC"},
	{1, "RSTN_PC"},
};

regInfo crt_sys_srst_3_reg[] = {
	{6, "Reserved"},
	{1, "RSTN_DCPHY2"},
	{1, "RSTN_DCU2"},
	{6, "Reserved"},
	{1, "RSTN_DDC"},
	{1, "RSTN_SD"},
	{3, "Reserved"},
	{1, "RSTN_HDMITX_PLL"},
	{4, "Reserved"},
	{1, "RSTN_USB2_PHY_P3"},
	{1, "RSTN_USB2_PHY_P2"},
	{1, "RSTN_USB2_PHY_P1"},
	{1, "RSTN_USB2_PHY_P0"},
	{2, "Reserved"},
	{1, "RSTN_USB3_MDIO_P0"},
	{1, "RSTN_USB3_PHY_P0"},
};

regInfo crt_sys_clken_0_reg[] = {
	{2, "Reserved"},
	{1, "Reserved"},
	{1, "Reserved"},
	{1, "Reserved"},
	{1, "Reserved"},
	{1, "Reserved"},
	{1, "Reserved"},
	{1, "CLKEN_AKL"},
	{1, "CLKEN_DSC"},
	{1, "CLKEN_SCE"},
	{1, "CLKEN_KT"},
	{1, "Reserved"},
	{1, "CLKEN_KCPU"},
	{1, "Reserved"},
	{1, "CLKEN_VE2_P2"},
	{1, "CLKEN_VE2"},
	{1, "CLKEN_VCPU2"},
	{1, "CLKEN_VP9"},
	{1, "CLKEN_ACPU"},
	{1, "Reserved"},
	{1, "Reserved"},
	{3, "Reserved"},
	{1, "Reserved"},
	{1, "CLKEN_VE_P2"},
	{1, "CLKEN_VE"},
	{1, "CLKEN_VCPU"},
	{1, "CLKEN_SCPU_WRAP"},
	{1, "CLKEN_SCPU"},
	{1, "CLKEN_PLLREG"},
};

regInfo crt_sys_clken_1_reg[] = {
	{1, "CLKEN_TVSB1"},
	{1, "CLKEN_TVSB2"},
	{1, "CLKEN_TVSB3"},
	{1, "CLKEN_TVSB4"},
	{1, "CLKEN_TVSB5"},
	{1, "CLKEN_TVE"},
	{1, "CLKEN_DCPHY"},
	{1, "CLKEN_DCU"},
	{1, "CLKEN_IF_DEMOD"},
	{1, "CLKEN_VDEC"},
	{1, "CLKEN_SE2"},
	{1, "CLKEN_VBIS0"},
	{2, "Dummy"},
	{1, "CLKEN_AUDIO_PRE512FS"},
	{1, "CLKEN_AUDIO"},
	{1, "CLKEN_IFADC"},
	{1, "CLKEN_CBUS"},
	{1, "CLKEN_OFFMS"},
	{1, "CLKEN_ME"},
	{1, "CLKEN_APLL_ADC"},
	{1, "CLKEN_HDMI"},
	{1, "CLKEN_HDMITX"},
	{1, "CLKEN_TP"},
	{1, "CLKEN_CP"},
	{1, "CLKEN_MD"},
	{1, "CLKEN_SE"},
	{1, "CLKEN_TP_DIV"},
	{1, "CLKEN_3D_GDE"},
	{1, "CLKEN_VODMA"},
	{1, "CLKEN_DISPIM"},
	{1, "CLKEN_DISP"},
};

regInfo crt_sys_clken_2_reg[] = {
	{3, "Reserved"},
	{1, "CLKEN_TM"},
	{1, "CLKEN_ATVIN_VD"},
	{1, "CLKEN_ATVIN_IFD"},
	{2, "Dummy"},
	{1, "CLKEN_EMMC"},
	{1, "CLKEN_EFUSE"},
	{1, "CLKEN_BISTREG"},
	{1, "Reserved"},
	{1, "Reserved"},
	{1, "CLKEN_USB"},
	{1, "CLKEN_OTG"},
	{1, "Reserved"},
	{1, "CLKEN_AUDIO2_512FS"},
	{1, "Dummy"},
	{1, "CLKEN_IRTX"},
	{1, "CLKEN_PADMUX"},
	{1, "CLKEN_DTV_DEMOD"},
	{1, "CLKEN_MISC"},
	{1, "CLKEN_PWM"},
	{1, "CLKEN_UART1"},
	{1, "CLKEN_UART2"},
	{1, "CLKEN_SC1"},
	{1, "CLKEN_GPIO"},
	{1, "CLKEN_I2C1"},
	{1, "CLKEN_I2C2"},
	{1, "CLKEN_NF"},
	{1, "CLKEN_SC"},
	{1, "CLKEN_PC"},
};

regInfo crt_sys_clken_3_reg[] = {
	{6, "Reserved"},
	{1, "CLKEN_DCPHY2"},
	{1, "CLKEN_DCU2"},
	{6, "Reserved"},
	{1, "CLKEN_DDC"},
	{1, "CLKEN_SD"},
	{8, "Reserved"},
	{1, "Clken_audio2_dma_r_512fs"},
	{1, "Clken_audio_dma_r_512fs"},
	{1, "Clken_audio_da1_256fs"},
	{1, "Clken_audio_da1_128fs"},
	{1, "Clken_audio_da0_256fs"},
	{1, "Clken_audio_da0_128fs"},
	{1, "Clken_audio_ad_256fs"},
	{1, "Clken_audio_ad_128fs"},
};

#define SYS_REG_SYS_SRST_0_SIZE 	(sizeof(crt_sys_srst_0_reg) / sizeof(struct reg_info))
#define SYS_REG_SYS_SRST_1_SIZE 	(sizeof(crt_sys_srst_1_reg) / sizeof(struct reg_info))
#define SYS_REG_SYS_SRST_2_SIZE 	(sizeof(crt_sys_srst_2_reg) / sizeof(struct reg_info))
#define SYS_REG_SYS_SRST_3_SIZE 	(sizeof(crt_sys_srst_3_reg) / sizeof(struct reg_info))
#define SYS_REG_SYS_CLKEN_0_SIZE 	(sizeof(crt_sys_clken_0_reg) / sizeof(struct reg_info))
#define SYS_REG_SYS_CLKEN_1_SIZE 	(sizeof(crt_sys_clken_1_reg) / sizeof(struct reg_info))
#define SYS_REG_SYS_CLKEN_2_SIZE 	(sizeof(crt_sys_clken_2_reg) / sizeof(struct reg_info))
#define SYS_REG_SYS_CLKEN_3_SIZE 	(sizeof(crt_sys_clken_3_reg) / sizeof(struct reg_info))

unsigned int getBitMask(unsigned int bit, unsigned int width)
{
	unsigned int retMask = 0;
	int i;

	for (i = bit; i <= (bit + width - 1) ; i++) {
		retMask += (1 << i);
	}

	pr_debug("bit %02d, width = %d,  Mask = 0x%08X \n", bit, width,  retMask);
	return retMask;
}

static ssize_t crt_reg_show(unsigned regAddr, regInfo *regData, unsigned int regSize, char *buf)
{
	char regInfoString[1024];
	char *pregInfoString = regInfoString;
	int regInfoStringCount, index, bitCount = 32;
	unsigned int regVal, bitmask, lowbit;

	hw_semaphore_try_lock();
	regVal = rtd_inl(regAddr);
	hw_semaphore_unlock();
	regInfoStringCount = sprintf(pregInfoString, "===== (0x%08X) = (0x%08X) ===== \n", regAddr, regVal);
	pregInfoString += regInfoStringCount;

	for (index = 0; index < regSize; index++) {
		if ((regData + index)->bit_width > 1) {
			lowbit = bitCount - (regData + index)->bit_width;
			bitmask = getBitMask(lowbit, (regData + index)->bit_width);
			regInfoStringCount = sprintf(pregInfoString, "%s\t[%d:%d] = 0x%X\n", (regData + index)->regName , --bitCount, lowbit, ((regVal & bitmask) >> lowbit));
			pregInfoString += regInfoStringCount;
			bitCount = lowbit;
		} else {
			bitCount--;
			bitmask = getBitMask(bitCount, (regData + index)->bit_width);
			regInfoStringCount = sprintf(pregInfoString, "%s\t[%d] = 0x%X\n", (regData + index)->regName, bitCount, ((regVal & bitmask) >> bitCount));
			pregInfoString += regInfoStringCount;
		}
	}

	return sprintf(buf, "%s\n", regInfoString);
}

static ssize_t crt_sys_srst_0_show(struct kobject *kobj, struct kobj_attribute *attr,
								   char *buf)
{
	char regInfoString[1024] = {0};

	//fix me later by ben
	//crt_reg_show(SYS_REG_SYS_SRST0_reg, crt_sys_srst_0_reg, SYS_REG_SYS_SRST_0_SIZE, regInfoString);

	return sprintf(buf, "%s\n", regInfoString);
}

static ssize_t crt_sys_srst_1_show(struct kobject *kobj, struct kobj_attribute *attr,
								   char *buf)
{
	char regInfoString[1024] = {0};

	//fix me later by ben
	//crt_reg_show(SYS_REG_SYS_SRST1_reg, crt_sys_srst_1_reg, SYS_REG_SYS_SRST_1_SIZE, regInfoString);

	return sprintf(buf, "%s\n", regInfoString);
}

static ssize_t crt_sys_srst_2_show(struct kobject *kobj, struct kobj_attribute *attr,
								   char *buf)
{
	char regInfoString[1024] = {0};

	//fix me later by ben
	//crt_reg_show(SYS_REG_SYS_SRST2_reg, crt_sys_srst_2_reg, SYS_REG_SYS_SRST_2_SIZE, regInfoString);

	return sprintf(buf, "%s\n", regInfoString);
}


static ssize_t crt_sys_srst_3_show(struct kobject *kobj, struct kobj_attribute *attr,
								   char *buf)
{
	char regInfoString[1024] = {0};

	//fix me later by ben
	//crt_reg_show(SYS_REG_SYS_SRST3_reg, crt_sys_srst_3_reg, SYS_REG_SYS_SRST_3_SIZE, regInfoString);

	return sprintf(buf, "%s\n", regInfoString);
}

static ssize_t crt_sys_clken_0_show(struct kobject *kobj, struct kobj_attribute *attr,
									char *buf)
{
	char regInfoString[1024] = {0};

	//fix me later by ben
	//crt_reg_show(SYS_REG_SYS_CLKEN0_reg, crt_sys_clken_0_reg, SYS_REG_SYS_CLKEN_0_SIZE, regInfoString);

	return sprintf(buf, "%s\n", regInfoString);
}

static ssize_t crt_sys_clken_1_show(struct kobject *kobj, struct kobj_attribute *attr,
									char *buf)
{
	char regInfoString[1024] = {0};

	//fix me later by ben
	//crt_reg_show(SYS_REG_SYS_CLKEN1_reg, crt_sys_clken_1_reg, SYS_REG_SYS_CLKEN_1_SIZE, regInfoString);

	return sprintf(buf, "%s\n", regInfoString);
}

static ssize_t crt_sys_clken_2_show(struct kobject *kobj, struct kobj_attribute *attr,
									char *buf)
{
	char regInfoString[1024] = {0};

	//fix me later by ben
	//crt_reg_show(SYS_REG_SYS_CLKEN2_reg, crt_sys_clken_2_reg, SYS_REG_SYS_CLKEN_2_SIZE, regInfoString);

	return sprintf(buf, "%s\n", regInfoString);
}

static ssize_t crt_sys_clken_3_show(struct kobject *kobj, struct kobj_attribute *attr,
									char *buf)
{
	char regInfoString[1024] = {0};

	//fix me later by ben
	//crt_reg_show(SYS_REG_SYS_CLKEN3_reg, crt_sys_clken_3_reg, SYS_REG_SYS_CLKEN_3_SIZE, regInfoString);

	return sprintf(buf, "%s\n", regInfoString);
}

static ssize_t crt_show(struct kobject *kobj, struct kobj_attribute *attr,
						char *buf)
{
#if 0	//fix me later by ben.

	char regInfoString[1024];
	char *pregInfoString = regInfoString;
	int regInfoStringCount;
	unsigned int regVal, regIndex;

	hw_semaphore_try_lock();
	/* SYS_REG_SYS_SRST register */
	for (regIndex = SYS_REG_SYS_SRST0_reg; regIndex <= SYS_REG_SYS_SRST3_reg ; regIndex += 4) {
		regVal = rtd_inl(regIndex);
		regInfoStringCount = sprintf(pregInfoString, "===== RSTN (0x%08X) = (0x%08X) ===== \n", regIndex, regVal);
		pregInfoString += regInfoStringCount;
	}

	/* SYS_REG_SYS_CLKEN register */
	for (regIndex = SYS_REG_SYS_CLKEN0_reg; regIndex <= SYS_REG_SYS_CLKEN3_reg ; regIndex += 4) {
		regVal = rtd_inl(regIndex);
		regInfoStringCount = sprintf(pregInfoString, "===== CLK_EN (0x%08X) = 0x%08X ===== \n", regIndex, regVal);
		pregInfoString += regInfoStringCount;
	}
	hw_semaphore_unlock();

	return sprintf(buf, "%s\n", regInfoString);
#endif
	return 0;
}

static ssize_t crt_register_show(struct kobject *kobj, struct kobj_attribute *attr,
								 char *buf)
{
	if (register_password == 0) {
		return sprintf(buf, "enter register address access password\n");
	} else if ((register_addr < 0xb8000000)) {
		return sprintf(buf, "wrong register address 0x%08X\n", register_addr);
	}

	return sprintf(buf, "reg addr = 0x%08X , val = 0x%08X\n", register_addr, rtd_inl(register_addr));
}

static ssize_t crt_register_store(struct kobject *kobj, struct kobj_attribute *attr,
								  const char *buf, size_t count)
{

	sscanf(buf, "0x%08X 0x%08X", &register_addr, &register_val);

	if (register_addr == 0x1234abcd)
		register_password = 1;

	if (register_addr == 0xabcd1234)
		register_password = 0;

	if ((register_password == 1) && (register_val != 0)) {
		rtd_outl(register_addr, register_val);
		register_val = 0;
	}


	return count;
}


static struct kobj_attribute crt_status_attribute =
	__ATTR(crt_status, 0444, crt_show, NULL);
static struct kobj_attribute crt_sys_srst_0_attribute =
	__ATTR(crt_sys_srst_0, 0444, crt_sys_srst_0_show, NULL);
static struct kobj_attribute crt_sys_srst_1_attribute =
	__ATTR(crt_sys_srst_1, 0444, crt_sys_srst_1_show, NULL);
static struct kobj_attribute crt_sys_srst_2_attribute =
	__ATTR(crt_sys_srst_2, 0444, crt_sys_srst_2_show, NULL);
static struct kobj_attribute crt_sys_srst_3_attribute =
	__ATTR(crt_sys_srst_3, 0444, crt_sys_srst_3_show, NULL);
static struct kobj_attribute crt_sys_clken_0_attribute =
	__ATTR(crt_sys_clken_0, 0444, crt_sys_clken_0_show, NULL);
static struct kobj_attribute crt_sys_clken_1_attribute =
	__ATTR(crt_sys_clken_1, 0444, crt_sys_clken_1_show, NULL);
static struct kobj_attribute crt_sys_clken_2_attribute =
	__ATTR(crt_sys_clken_2, 0444, crt_sys_clken_2_show, NULL);
static struct kobj_attribute crt_sys_clken_3_attribute =
	__ATTR(crt_sys_clken_3, 0444, crt_sys_clken_3_show, NULL);
static struct kobj_attribute crt_register =
/*	__ATTR(register, 0666, crt_register_show, crt_register_store); // fix compile error */
__ATTR(register, 0444, crt_register_show, crt_register_store);


static struct attribute *attrs[] = {
	&crt_status_attribute.attr,
	&crt_sys_srst_0_attribute.attr,
	&crt_sys_srst_1_attribute.attr,
	&crt_sys_srst_2_attribute.attr,
	&crt_sys_srst_3_attribute.attr,
	&crt_sys_clken_0_attribute.attr,
	&crt_sys_clken_1_attribute.attr,
	&crt_sys_clken_2_attribute.attr,
	&crt_sys_clken_3_attribute.attr,
	&crt_register.attr,
	NULL,	/* need to NULL terminate the list of attributes */
};

static struct attribute_group attr_group = {
	.attrs = attrs,
};

/* CRT char device file operation session */
long crt_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{

	int retval = 0;
	/* no user space ioctl  */
#if 0
	unsigned long flags;
	crt_clk_onoff_cmd CLK_OnOff_CMD;

	switch (cmd) {
	case CRT_IOC_CLK_ONOFF:
		retval = copy_from_user((void *)&CLK_OnOff_CMD, (const void __user *)arg, sizeof(crt_clk_onoff_cmd)) ?  -EFAULT : 0;
		if (CLK_OnOff_CMD.private_data == NULL) {
			CRT_CLK_OnOff(CLK_OnOff_CMD.module_ip, CLK_OnOff_CMD.clken, NULL);
		} else {
			CRT_CLK_OnOff(CLK_OnOff_CMD.module_ip, CLK_OnOff_CMD.clken, CLK_OnOff_CMD.private_data);
		}

		pr_debug("CRT : module %s, CLK %s\n", CRT_CLK_ModuleName(CLK_OnOff_CMD.module_ip), (CLK_OnOff_CMD.clken) ? "OFF" : "ON");
		break;
	default:
		pr_err("CRT : wrong ioctl cmd\n");
	}
#endif
	return retval;
}


int crt_open(struct inode *inode, struct file *filp)
{
	return 0;
}

int crt_release(struct inode *inode, struct file *filp)
{
	return 0;
}

/* CRT file operation */
struct file_operations crt_fops = {
read:
	NULL,
write:
	NULL,
unlocked_ioctl:
	crt_ioctl,
open:
	crt_open,
release:
	crt_release,
};

/* set /dev/crt mode to 0666  */
static char *crt_devnode(struct device *dev, mode_t *mode)
{
	if (mode)
		*mode = 0666;
	return NULL;
}


#ifdef CONFIG_PM
static int crt_suspend(struct platform_device *dev, pm_message_t state)
{
	pr_debug("crt_suspend\n");
	return 0;
}
static int crt_resume(struct platform_device *dev)
{
	pr_debug("crt_resume\n");
	return 0;
}
#endif

static struct platform_driver crt_platform_driver = {
#ifdef CONFIG_PM
	.suspend    = crt_suspend,
	.resume     = crt_resume,
#endif
	. driver = {
		.name       = "crt",
		.bus        = &platform_bus_type,
	} ,
} ;


static int __init crt_module_init(void)
{
	int retval;

	crt_kobj = kobject_create_and_add("crt", NULL);
	if (!crt_kobj)
		return -ENOMEM;

	retval = sysfs_create_group(crt_kobj, &attr_group);
	if (retval)
		kobject_put(crt_kobj);


	/* register device to get major and minor number */
	if (crt_major) {
		crt_devnum = MKDEV(crt_major, crt_minor);
		retval = register_chrdev_region(crt_devnum, crt_nr_devs, "crt");
	} else {
		retval = alloc_chrdev_region(&crt_devnum, crt_minor, crt_nr_devs, "crt");
		crt_major = MAJOR(crt_devnum);
	}
	if (retval < 0) {
		pr_warn("CRT : can't get major %d\n", crt_major);
		return retval;
	}

	/* create device node by udev API */
	crt_class = class_create(THIS_MODULE, "crt");
	if (IS_ERR(crt_class)) {
		return PTR_ERR(crt_class);
	}
	crt_class->devnode = crt_devnode;
	crt_device = device_create(crt_class, NULL, crt_devnum, NULL, "crt");
	pr_info("CRT module init, major number = %d, device name = %s \n", crt_major, dev_name(crt_device));

	/* cdev API to register file operation */
	cdev_init(&crt_cdev, &crt_fops);
	crt_cdev.owner = THIS_MODULE;
	crt_cdev.ops = &crt_fops;
	retval = cdev_add(&crt_cdev, crt_devnum , 1);
	if (retval) {
		pr_err("Error %d adding char_reg_setup_cdev", retval);
	}

	crt_platform_devs = platform_device_register_simple("crt", -1, NULL, 0);
	/* pr_info("CRT platform device name %s\n", dev_name(&crt_platform_devs->dev)); */

	if (platform_driver_register(&crt_platform_driver) != 0) {
		platform_device_unregister(crt_platform_devs);
		crt_platform_devs = NULL;
		pr_warn("crt platform driver register fail\n");
		return retval;
	}

	spin_lock_init(&crt_lock);
	memset(moduleName, 0, sizeof(moduleName));
	memset(lastModuleName, 0, sizeof(lastModuleName));

	return retval;
}

static void __exit crt_module_exit(void)
{
	if (crt_platform_devs)
		platform_device_unregister(crt_platform_devs);

	platform_driver_unregister(&crt_platform_driver);

	kobject_put(crt_kobj);
	device_destroy(crt_class, crt_devnum);
	class_destroy(crt_class);
	unregister_chrdev_region(crt_devnum, crt_nr_devs);

}

module_init(crt_module_init);
module_exit(crt_module_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mark Tseng <mark.tseng@realtek.com>");
