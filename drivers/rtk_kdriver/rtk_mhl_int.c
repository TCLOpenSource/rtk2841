#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/delay.h>

#include <linux/kernel.h>	/* DBG_PRINT() */
#include <linux/slab.h>		/* kmalloc() */
#include <linux/fs.h>		/* everything... */
#include <linux/errno.h>	/* error codes */
#include <linux/types.h>	/* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>	/* O_ACCMODE */
#include <linux/seq_file.h>
#include <linux/cdev.h>
#include <linux/kfifo.h>
#include <linux/poll.h>
#include <linux/wait.h>
#include <linux/jiffies.h>
#include <linux/device.h>
/*for linux 2.6.34*/
#include <linux/platform_device.h>
#include <linux/freezer.h>
#include <linux/device.h>
#include <rbus/iso_misc_off_reg.h>
#include <rbus/crt_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <rbus/stb_reg.h>

//#include <asm/system.h>		/* cli(), *_flags */
#include <asm/uaccess.h>	/* copy_*_user */
#include <asm/io.h>
#include <linux/sched.h>
#include <linux/time.h>

#include <asm/irq.h>
#include <linux/signal.h>
#include <linux/interrupt.h>

#include <asm/bitops.h>		/* bit operations */
#include "emcu.h"

#include <mach/pcbMgr.h>

#include <rbus/rbusMHLCbus.h>
#include <rbus/rbusHDMIReg.h>
#include <linux/miscdevice.h>
#include <mach/rtk_crt.h>

#define MHL_CTS_2p2_BUG 0
extern int pcb_mgr_get_enum_info_byname(char *enum_name, unsigned long long *value);
static int pcb_get_enum_value(char *pin_name, unsigned long long *value)
{
	int err = 0;

	if (pcb_mgr_get_enum_info_byname(pin_name, value))
	{
		//printk("[GPIO][%s]- get enum error.\n", __func__);
		return -1;
	}
	return err;
}
int get_support_mhl_circuit(void)
{
              unsigned long long id = 0;
	if (pcb_get_enum_value("PIN_MHL_CABLE_DETECT", &id) ==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
#define SUPPORT_MHL     	  get_support_mhl_circuit()

static  unsigned char _mhl_state;
static const char  drv_name[] = "mhl";
#ifdef CONFIG_PM
static int mhl_suspend(struct device *p_dev);
static int mhl_resume(struct device *p_dev);

static struct platform_device *mhl_devs = NULL;

static const struct dev_pm_ops mhl_pm_ops = {
	.suspend    = mhl_suspend,
	.resume     = mhl_resume,
};

static struct platform_driver mhl_driver = {
	.driver = {
		.name         = (char *)drv_name,
		.bus          = &platform_bus_type,
#ifdef CONFIG_PM
		.pm           = &mhl_pm_ops,
#endif
	},
};

#endif /*CONFIG_PM*/

/*-----------------------------------------------------------------------------------
 * File Operations
 *------------------------------------------------------------------------------------*/

int MHL_open(struct inode *inode, struct file *file)
{
	return 0;
}

int MHL_release(struct inode *inode, struct file *file)
{
	return 0;
}

ssize_t MHL_write(struct file *file,
		  const char __user *buff, size_t size, loff_t *ofst)
{
	if (size > sizeof(_mhl_state))
		return -ENOMEM;

	if (copy_from_user(_mhl_state, (void __user *)buff, sizeof(_mhl_state)))
		return -1;

	printk("MHL_write to AP ISR =1 \n");

	return 0;
}

ssize_t MHL_read(struct file *file,
		 char __user *buff, size_t size, loff_t *ofst)
{
	if (size < sizeof(_mhl_state))
		return -ENOMEM;

	if (copy_to_user((void __user *)buff, _mhl_state, sizeof(_mhl_state)))
		return -1;

	return sizeof(_mhl_state);
}

static struct file_operations MHL_fops = {
	.owner = THIS_MODULE,
	.read = MHL_read,
	.write = MHL_write,
	.open = MHL_open,
	.release = MHL_release,
};

/*
/////////////////////////////////////////////////////////////////////////
// module Init
/////////////////////////////////////////////////////////////////////////
*/

static struct miscdevice MHL_miscdev = {
	MISC_DYNAMIC_MINOR,
	"MHL",
	&MHL_fops
};

/*
//--------------------------------------------------
// Description  : detect discovery pulse & wake up pulse by interrupt
// Input Value  : None
// Output Value : None
//--------------------------------------------------
*/
void mhl_int_MHLCBUS_ISR(void)
{
	unsigned long long value = 0;

	/* check disconnected state*/
	if ((rtd_inl(CBUS_PMM_CBUS_STANDBY_04_reg)&(CBUS_PMM_CBUS_STANDBY_04_disconn_irq_en_mask|CBUS_PMM_CBUS_STANDBY_04_cbus_disconn_mask)) == (CBUS_PMM_CBUS_STANDBY_04_disconn_irq_en_mask|CBUS_PMM_CBUS_STANDBY_04_cbus_disconn_mask)) {
		if (pcb_mgr_get_enum_info_byname("PCB_MHL_CHANNEL", &value)) {
			printk("[GPIO][%s]- get PCB_MHL_CHANNEL error. Need to set MHL channel correctly.\n", __func__);
		} else {
			if (value == 1) {
				rtd_maskl(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg, ~(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_b(1<<value)), 0);/*Z0 resister*/
				rtd_maskl(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg, ~(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z100_en(1<<value)), 0);
			else if (value == 2) {
				rtd_maskl(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg, ~(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_b(1<<value)), 0);/*Z0 resister*/
				rtd_maskl(DFE_HDMI_RX_PHY_P2_Z0POW_reg, ~(DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z100_en_mask), 0);
			} else {
				rtd_maskl(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg, ~(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_b(1<<0)), 0);/*Z0 resister*/
				rtd_maskl(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg, ~(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z100_en(1<<0)), 0);
			}
		}

		rtd_maskl(CBUS_PMM_CBUS_STANDBY_04_reg, ~(CBUS_PMM_CBUS_STANDBY_04_disconn_irq_en_mask | CBUS_PMM_CBUS_STANDBY_04_cbus_disconn_mask), (0));
		rtd_maskl(CBUS_PMM_CBUS_STANDBY_08_reg, ~(CBUS_PMM_CBUS_STANDBY_08_goto_sink1_mask), (CBUS_PMM_CBUS_STANDBY_08_goto_sink1_mask));
		rtd_maskl(CBUS_PMM_CBUS_STANDBY_02_reg, ~(CBUS_PMM_CBUS_STANDBY_02_dis_deb_lv_mask), CBUS_PMM_CBUS_STANDBY_02_dis_deb_lv(4));

		rtd_maskl(CBUS_PMM_CBUS_STANDBY_00_reg, ~(CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask | CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask), (CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask|CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask));

		printk(KERN_ALERT"[ISR] Cbus disconnected occurs=%d!!\n", (unsigned int)value);
	}
}
/* Module Functions */

static irqreturn_t MHL_interrupt_handler(int irq, void *dev_id)
{
	irqreturn_t retValue = IRQ_NONE;

	if (rtd_inl(STB_ALU_IP_reg) & STB_ALU_IP_stip_cbus_mask) {
		mhl_int_MHLCBUS_ISR();
		rtd_outl(STB_ALU_IP_reg, STB_ALU_IP_stip_cbus_mask);	/*clear pending flag of cbus*/
		retValue = IRQ_HANDLED;
	}

	return retValue;

}

int MHL_init_module(void)
{
	int result = 0;

             if(SUPPORT_MHL==0)
             {
                 printk(KERN_EMERG "NO support MHL\n");
                 return -1;
             }

	printk(KERN_ALERT "[linux][CBUS] MHL_init_module[Mc5]\n");


	CRT_CLK_OnOff(MHL, CLK_ON, NULL);

	rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, SYS_REG_INT_CTRL_SCPU_standby_cbus_int_scpu_routing_en_mask | SYS_REG_INT_CTRL_SCPU_write_data(1));

	/* Request IRQ */
	if (request_irq(IRQ_CEC,
			MHL_interrupt_handler,
			IRQF_SHARED, "CBUS_IR", MHL_interrupt_handler)) {
		printk(KERN_ERR "[linux]CBUS: cannot register IRQ %d\n",
		       IRQ_CEC);
		return -EIO;	/* FAil ! */
	}
	printk(KERN_ERR "[linux]CBUS: register sucess!!! IRQ %d\n", IRQ_CEC);

	if (misc_register(&MHL_miscdev))
		return -1;

#ifdef CONFIG_PM
	mhl_devs = platform_device_register_simple((char *)drv_name, -1, NULL, 0);
	result = platform_driver_register(&mhl_driver);
	if ((result) != 0) {
		printk(KERN_EMERG "Can't register mhl device driver...\n");
		platform_device_unregister(mhl_devs);
		mhl_devs = NULL;
		return result;
	}
#endif

	return 0;	/* succeed ! */

}
void MHL_cleanup_module(void)
{
             if(SUPPORT_MHL==0)
             {
                 printk(KERN_EMERG "NO support MHL\n");
                 return -1;
             }

	rtd_maskl(STB_ALU_IE_reg, ~STB_ALU_IE_stie_cbus_mask, 0);  /* STB_ALU_IE interrupt enable*/
	rtd_maskl(STB_ALU_IP_reg, ~STB_ALU_IP_stip_cbus_mask, 0);  /* clear pending flag of cbus*/
	rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, SYS_REG_INT_CTRL_SCPU_standby_cbus_int_scpu_routing_en_mask);

	/*rtd_maskl(CBUS_MSC_07_reg,~(CBUS_MSC_07_get_id_irq_en_mask), 0);*/

	printk(KERN_ALERT "[linux][CBUS] MHL_cleanup_module\n");

	misc_deregister(&MHL_miscdev);

	if (mhl_devs) {
		platform_device_unregister(mhl_devs);
	}

	platform_driver_unregister(&mhl_driver);

}

#if MHL_CTS_2p2_BUG
static irqreturn_t CBUS_interrupt_handler(int irq, void *dev_id)
{
	uint32_t regValue;

	regValue = rtd_inl(CBUS_MSC_06_reg);
	if (regValue & CBUS_MSC_06_get_id_irq_mask) {
		rtd_maskl(CBUS_MSC_07_reg, ~CBUS_MSC_07_get_id_irq_en_mask, 0);
		rtd_maskl(CBUS_DDC_02_reg, ~(CBUS_DDC_02_mcuddc_en_mask|CBUS_DDC_02_ddc_cmd_event_mask|CBUS_DDC_02_ddc_data_event_mask), CBUS_DDC_02_mcuddc_en_mask);
		printk(KERN_ALERT"\n \n [linux][CBUS_LOG]GET vender ID occur!!(irq0=%d)\n\n", irq);
		return IRQ_HANDLED;
	}

	return IRQ_NONE;
}

int CBUS_Command_init_module(void)
{

	printk(KERN_ALERT "[linux][CBUS] CBUS_Command_init_module\n");

	if (request_irq(IRQ_DDOMAIN,
			CBUS_interrupt_handler,
			IRQF_SHARED, "IRQ_DDOMAIN", CBUS_interrupt_handler)) {
		printk(KERN_ERR "[linux]CBUS: cannot register IRQ %d\n",
		       IRQ_DDOMAIN);
		return -EIO;	/* FAil ! */
	}
	printk(KERN_ERR "[linux]CBUS: register sucess!!! IRQ %d\n", IRQ_DDOMAIN);

	rtd_maskl(CBUS_MSC_07_reg, ~(CBUS_MSC_07_get_id_irq_en_mask), CBUS_MSC_07_get_id_irq_en_mask);
	return 0;	/* succeed ! */

}

void CBUS_Command_cleanup_module(void)
{
	rtd_maskl(CBUS_MSC_07_reg, ~(CBUS_MSC_07_get_id_irq_en_mask), 0);
}

#endif

#ifdef CONFIG_PM
static int mhl_suspend(struct device *p_dev)
{
	printk("func=%s line=%d \n", __FUNCTION__, __LINE__);

	return 0;
}

static int mhl_resume(struct device *p_dev)
{
	printk("func=%s line=%d \n", __FUNCTION__, __LINE__);

              if(SUPPORT_MHL)
	CRT_CLK_OnOff(MHL, CLK_ON, NULL);

	return 0;
}
#endif

/* Register Macros */

module_init(MHL_init_module);
module_exit(MHL_cleanup_module);

#if MHL_CTS_2p2_BUG
module_init(CBUS_Command_init_module);
module_exit(CBUS_Command_cleanup_module);
#endif

