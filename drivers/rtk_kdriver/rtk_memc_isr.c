//Copyright (C) 2007-2013 Realtek Semiconductor Corporation.
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#include <linux/cdev.h>
#include <linux/platform_device.h>
#include <linux/fs.h>
#include <asm/io.h>
#include <asm/uaccess.h>
#include <mach/rtk_log.h>

#include "memc_isr/scalerMEMC.h"

static int memc_isr_suspend(struct platform_device *dev, pm_message_t state);
static int memc_isr_resume(struct platform_device *dev);

static struct platform_device *memc_isr_platform_devs = NULL;
static struct platform_driver memc_isr_platform_driver = {
#ifdef CONFIG_PM
        .suspend                = memc_isr_suspend,
        .resume                 = memc_isr_resume,
#endif
        .driver = {
                .name           = "memc_isr",
                .bus            = &platform_bus_type,
        },
};

static int memc_isr_suspend(struct platform_device *dev, pm_message_t state)
{
        printk(KERN_NOTICE "Before [MEMC_ISR] suspend\n");

	memc_suspend();

	// disable interrupt
	unsigned int u32_interrupt_reg = 0;
	//reg_kmc_int_en
	u32_interrupt_reg = rtd_inl(0xB8099018);//MC_TOP__REG_KMC_IN_INT_SEL_ADDR
	u32_interrupt_reg &= 0xf0ffffff;
	rtd_outl(0xB8099018, u32_interrupt_reg);//MC_TOP__REG_KMC_IN_INT_SEL_ADDR

	//reg_post_int_en
	u32_interrupt_reg = rtd_inl(0xB809D008);//KPOST_TOP__REG_POST_INT_SOURCE_SEL_ADDR
	u32_interrupt_reg &= 0xfffffe1f;
	rtd_outl(0xB809D008, u32_interrupt_reg);//KPOST_TOP__REG_POST_INT_SOURCE_SEL_ADDR

        return 0;
}

static int memc_isr_resume(struct platform_device *dev)
{

	printk(KERN_NOTICE "After [MEMC_ISR] resume\n");

	 // disable route to VCPU1
	rtd_outl(SYS_REG_INT_CTRL_MEMC_reg, BIT(SYS_REG_INT_CTRL_MEMC_memc_int_vcpu_routing_en_shift));
        // disable route to VCPU2
	rtd_outl(SYS_REG_INT_CTRL_MEMC_reg, BIT(SYS_REG_INT_CTRL_MEMC_memc_int_vcpu2_routing_en_shift));
        // enable route to SCPU
	rtd_outl(SYS_REG_INT_CTRL_MEMC_reg, BIT(SYS_REG_INT_CTRL_MEMC_memc_int_scpu_routing_en_shift) | BIT(SYS_REG_INT_CTRL_MEMC_write_data_shift));

        return 0;
}

irqreturn_t memc_isr(int irq, void *dev_id)
{
	#ifdef CONFIG_HW_SUPPORT_MEMC
	Scaler_MEMC_ISR();
	#endif
	return IRQ_HANDLED;
}

static int __init memc_isr_init_irq(void)
{
	/* Request IRQ */
	if(request_irq(IRQ_MEMC,
                   memc_isr,
                   IRQF_SHARED,
                   "MEMC ISR",
                   (void *)memc_isr_platform_devs))
	{
		pr_err("memc_isr: cannot register IRQ %d\n", IRQ_MEMC);
		return -ENXIO;
	}

	//setup IRQ route and enable IRQ
	// disable route to VCPU1
	rtd_outl(SYS_REG_INT_CTRL_MEMC_reg, BIT(SYS_REG_INT_CTRL_MEMC_memc_int_vcpu_routing_en_shift));
	// disable route to VCPU2
	rtd_outl(SYS_REG_INT_CTRL_MEMC_reg, BIT(SYS_REG_INT_CTRL_MEMC_memc_int_vcpu2_routing_en_shift));
	// enable route to SCPU
	rtd_outl(SYS_REG_INT_CTRL_MEMC_reg, BIT(SYS_REG_INT_CTRL_MEMC_memc_int_scpu_routing_en_shift) | BIT(SYS_REG_INT_CTRL_MEMC_write_data_shift));
	// enable MEMC interrupt
	//??

	pr_info("memc_isr: register IRQ %d\n", IRQ_MEMC);

	return 0;
}

static int __init memc_isr_init_module(void)
{
	int result;
	memc_isr_platform_devs = platform_device_register_simple("memc_isr", -1, NULL, 0);
        if (platform_driver_register(&memc_isr_platform_driver) != 0) {
                printk("memc_isr: can not register platform driver...\n");
                result = -EINVAL;
                return result;
        }
	result = memc_isr_init_irq();
	if (result < 0) {
		pr_err("memc_isr: can not register irq...\n");
		return result;
	}

	return 0;
}

void memc_isr_exit_module(void)
{
	free_irq(IRQ_MEMC, (void *)memc_isr);
}

module_init(memc_isr_init_module);
module_exit(memc_isr_exit_module);
