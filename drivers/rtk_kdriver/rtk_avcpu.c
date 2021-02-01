#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
#include <linux/console.h>
#include <linux/printk.h>

#include "rtk_avcpu.h"
#include <rtk_kdriver/rtk_avcpu_export.h>
#include <rtk_kdriver/RPCDriver.h>
#include <mach/io.h>
#include <rbus/stb_reg.h>

#include <base_types.h>
#include <linux/delay.h>

#define AVCPU_SUSPEND_RESUME_TIMEOUT_SEC 2
#define HEADER_OFFSET         0x2000000
#define EMMC_BLOCK_SIZE       (PAGE_SIZE / 8)

#define av_be32_to_cpu(x)  do {x = htonl((x));} while(0)

#define DEVICE_EMMC             1

#ifdef CONFIG_PM
static int avcpu_suspend(struct platform_device *dev, pm_message_t state);
static int avcpu_resume(struct platform_device *dev);
#endif

extern void serial8250_emergency_resume(void);
static BLOCKING_NOTIFIER_HEAD(avcpu_chain_head);

int stravnoreload = 1;

static struct class *avcpu_class = NULL;
static struct cdev avcpu_cdev;
static struct platform_device *avcpu_platform_devs = NULL;
static struct platform_driver avcpu_device_driver = {
#ifdef CONFIG_PM
	.suspend		= avcpu_suspend,
	.resume			= avcpu_resume,
#endif
	.driver = {
		.name		= "avcpu",
		.bus		= &platform_bus_type,
	},
};

struct device* get_avcpu_device_ptr(void)
{
	return &(avcpu_platform_devs->dev);
}

int register_avcpu_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&avcpu_chain_head, nb);
}
EXPORT_SYMBOL_GPL(register_avcpu_notifier);

int unregister_avcpu_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_unregister(&avcpu_chain_head, nb);
}
EXPORT_SYMBOL_GPL(unregister_avcpu_notifier);

int avcpu_notifier_call_chain(unsigned long val)
{
	return (blocking_notifier_call_chain(&avcpu_chain_head, val, NULL) == NOTIFY_BAD) ? -EINVAL : 0;
}

int resetav_lock(int is_suspend)
{
	printk("### reset audio & video ###\n");

	// get hw semaphore...
	// rtd_inl(0xb801a000);

	return 0;
}

int resetav_unlock(int is_suspend)
{
	// put hw semaphore...
	// rtd_outl(0xb801a000, 0);

	return 0;
}

#ifdef CONFIG_PM

static int invalidate_status_flag(void)
{
	dmac_inv_range(phys_to_virt(ACPU_STATUS_FLAG_ADDRESS),phys_to_virt(ACPU_STATUS_FLAG_ADDRESS+0x4));
	outer_inv_range(ACPU_STATUS_FLAG_ADDRESS, ACPU_STATUS_FLAG_ADDRESS+0x4);

#ifdef CONFIG_RTK_KDRV_SUPPORT_ACPU2
	dmac_inv_range(phys_to_virt(ACPU2_STATUS_FLAG_ADDRESS),phys_to_virt(ACPU2_STATUS_FLAG_ADDRESS+0x4));
	outer_inv_range(ACPU2_STATUS_FLAG_ADDRESS, ACPU2_STATUS_FLAG_ADDRESS+0x4);
#endif

	dmac_inv_range(phys_to_virt(VCPU_STATUS_FLAG_ADDRESS),phys_to_virt(VCPU_STATUS_FLAG_ADDRESS+0x4));
	outer_inv_range(VCPU_STATUS_FLAG_ADDRESS, VCPU_STATUS_FLAG_ADDRESS+0x4);

#ifdef CONFIG_RTK_KDRV_SUPPORT_VCPU2
	dmac_inv_range(phys_to_virt(VCPU2_STATUS_FLAG_ADDRESS),phys_to_virt(VCPU2_STATUS_FLAG_ADDRESS+0x4));
	outer_inv_range(VCPU2_STATUS_FLAG_ADDRESS, VCPU2_STATUS_FLAG_ADDRESS+0x4);
#endif

	return 0;
}
static int flush_status_flag(void)
{
	dmac_flush_range(phys_to_virt(ACPU_STATUS_FLAG_ADDRESS),phys_to_virt(ACPU_STATUS_FLAG_ADDRESS+0x4));
	outer_flush_range(ACPU_STATUS_FLAG_ADDRESS, ACPU_STATUS_FLAG_ADDRESS+0x4);

#ifdef CONFIG_RTK_KDRV_SUPPORT_ACPU2
	dmac_flush_range(phys_to_virt(ACPU2_STATUS_FLAG_ADDRESS),phys_to_virt(ACPU2_STATUS_FLAG_ADDRESS+0x4));
	outer_flush_range(ACPU2_STATUS_FLAG_ADDRESS, ACPU2_STATUS_FLAG_ADDRESS+0x4);
#endif

	dmac_flush_range(phys_to_virt(VCPU_STATUS_FLAG_ADDRESS),phys_to_virt(VCPU_STATUS_FLAG_ADDRESS+0x4));
	outer_flush_range(VCPU_STATUS_FLAG_ADDRESS, VCPU_STATUS_FLAG_ADDRESS+0x4);

#ifdef CONFIG_RTK_KDRV_SUPPORT_VCPU2
	dmac_flush_range(phys_to_virt(VCPU2_STATUS_FLAG_ADDRESS),phys_to_virt(VCPU2_STATUS_FLAG_ADDRESS+0x4));
	outer_flush_range(VCPU2_STATUS_FLAG_ADDRESS, VCPU2_STATUS_FLAG_ADDRESS+0x4);
#endif

	return 0;
}

void force_console_enable(void)
{
	console_loglevel = 7;
	serial8250_emergency_resume();
	resume_console();
}

static int avcpu_notify_suspend(void)
{
	int ret;
	unsigned long context;
	unsigned long timeout = jiffies + HZ*AVCPU_SUSPEND_RESUME_TIMEOUT_SEC;
	int wait_flag = 0, check_flag = 0;


	/* Clear AV CPU resume status*/
	*((volatile int *)phys_to_virt(AVCPU_STATUS_FLAG_STD_ADDR)) = 0x0;
	dmac_flush_range(phys_to_virt(AVCPU_STATUS_FLAG_STD_ADDR),phys_to_virt(AVCPU_STATUS_FLAG_STD_ADDR+0x4));
	outer_flush_range(AVCPU_STATUS_FLAG_STD_ADDR, AVCPU_STATUS_FLAG_STD_ADDR+0x4);

	/*Clear status flag*/
	*((volatile int *)phys_to_virt(ACPU_STATUS_FLAG_ADDRESS)) |= 0x03000000;
#ifdef CONFIG_RTK_KDRV_SUPPORT_ACPU2
	*((volatile int *)phys_to_virt(ACPU2_STATUS_FLAG_ADDRESS)) |= 0x0C000000;
#endif
	*((volatile int *)phys_to_virt(VCPU_STATUS_FLAG_ADDRESS)) |= 0x03000000;
#ifdef CONFIG_RTK_KDRV_SUPPORT_VCPU2
	*((volatile int *)phys_to_virt(VCPU2_STATUS_FLAG_ADDRESS)) |= 0x03000000;
#endif
	flush_status_flag();


	//reset the highest temperature value
	rtd_maskl(STB_WDOG_DATA14_reg,0xFF00FFFF,0x0);

	rtd_outl(STB_WDOG_DATA14_reg, rtd_inl(STB_WDOG_DATA14_reg) | 0xF0000000); //set bit31-28;

	printk(KERN_NOTICE "[AVCPU] avcpu_notify_suspend\n");

#ifdef CONFIG_RTK_KDRV_RPC
	ret = send_krpc(RPC_AUDIO, KRPC_PROCEDUREID_ROS, 0, ENUM_KERNEL_RPC_SUSPEND, 0, 0, &context);
	if( ret != RPC_OK)
	{
		printk(KERN_ERR "send rpc suspend AUDIO Error\n");
	}

	ret = send_krpc(RPC_VIDEO, KRPC_PROCEDUREID_ROS, 0, ENUM_KERNEL_RPC_SUSPEND, 0, 0, &context);
	if( ret != RPC_OK)
	{
		printk(KERN_ERR "send rpc suspend  VIDEO Error\n");
	}
#ifdef CONFIG_RTK_KDRV_SUPPORT_VCPU2
	ret = send_krpc(RPC_VIDEO2, KRPC_PROCEDUREID_ROS, 0, ENUM_KERNEL_RPC_SUSPEND, 0, 0, &context);
	if( ret != RPC_OK)
	{
		printk(KERN_ERR "send rpc suspend  VIDEO2 Error\n");
	}
#endif
#endif

	while(time_before(jiffies, timeout))
	{

		invalidate_status_flag();

		if (((*((volatile int *)phys_to_virt(ACPU_STATUS_FLAG_ADDRESS))) & 0x03000000) == 0)
		{
			wait_flag |= 1;
		}else {
		}
#ifdef CONFIG_RTK_KDRV_SUPPORT_ACPU2
		if (((*(volatile int *)phys_to_virt(ACPU2_STATUS_FLAG_ADDRESS)) & 0x0C000000) == 0)
		{
			wait_flag |= 8;
		}
		else {
		}
#endif
		if ((((*((volatile int *)phys_to_virt(VCPU_STATUS_FLAG_ADDRESS))) & 0x03000000) == 0)
			|| ((rtd_inl(STB_WDOG_DATA14_reg)&0xC0000000) ==0x0))
		{
			wait_flag |= 2;
		}
#ifdef CONFIG_RTK_KDRV_SUPPORT_VCPU2
		if ((((*((volatile int *)phys_to_virt(VCPU2_STATUS_FLAG_ADDRESS))) & 0x03000000) == 0)
			|| ((rtd_inl(STB_WDOG_DATA14_reg)&0x30000000) ==0x0))
		{
			wait_flag |= 4;
		}
#endif
		if((wait_flag & AVCPU_FLAG) == AVCPU_FLAG)
			break;
	}

	/*Clear SCPU STR status flag for AVCPU reference*/
	*((volatile int *)phys_to_virt(SCPU_STR_STATUS_FLAG_ADDR)) = SCPU_STR_STATUS_SUSPEND_CLEAR;
	dmac_flush_range(phys_to_virt(SCPU_STR_STATUS_FLAG_ADDR),phys_to_virt(SCPU_STR_STATUS_FLAG_ADDR+0x4));
	outer_flush_range(SCPU_STR_STATUS_FLAG_ADDR, SCPU_STR_STATUS_FLAG_ADDR+0x4);

	if(!(wait_flag & 0x1)) {
		printk(KERN_ERR "AUDIO 1 SUSPEND FAIL!! %x\n", *((volatile int *)phys_to_virt(ACPU_STATUS_FLAG_ADDRESS)));
	}

#ifdef CONFIG_RTK_KDRV_SUPPORT_ACPU2
	if(!(wait_flag & 0x8)) {
		printk(KERN_ERR "AUDIO 2 SUSPEND FAIL!! %x\n", *((volatile int *)phys_to_virt(ACPU2_STATUS_FLAG_ADDRESS)));
	}
#endif

	if(!(wait_flag & 0x2)) {
		printk(KERN_ERR "VIDEO SUSPEND FAIL!! %x\n", *((volatile int *)phys_to_virt(VCPU_STATUS_FLAG_ADDRESS)));
	}

#ifdef CONFIG_RTK_KDRV_SUPPORT_VCPU2
	if(!(wait_flag & 0x4)) {
		printk(KERN_ERR "VIDEO2 SUSPEND FAIL!! %x\n", *((volatile int *)phys_to_virt(VCPU2_STATUS_FLAG_ADDRESS)));
	}
#endif

        if(wait_flag != AVCPU_FLAG)
	{
		force_console_enable();
		panic("[AVCPU] Suspend fail(%x/%x)\n", wait_flag, rtd_inl(STB_WDOG_DATA14_reg));

	}
	return ((wait_flag == AVCPU_FLAG) ? 0: -1);
}

#ifdef CONFIG_SUPPORT_DEMOD
extern struct device* get_rtkdemod_device_ptr(void);
#endif

#define _RETRY_  (5)
static int avcpu_notify_resume(struct device *dev)
{
	int ret = 0, check_flag =0;
	unsigned long timeout = jiffies + HZ*AVCPU_SUSPEND_RESUME_TIMEOUT_SEC;
	int wait_flag = 0;
	int acpufail_check_flag = 0;
	
	printk(KERN_NOTICE "[AVCPU] avcpu_notify_resume\n");

	/* notify AV CPU resume, for STD make image then resume case*/
	*((volatile int *)phys_to_virt(AVCPU_STATUS_FLAG_STD_ADDR)) = 0x03000000;
	dmac_flush_range(phys_to_virt(AVCPU_STATUS_FLAG_STD_ADDR),phys_to_virt(AVCPU_STATUS_FLAG_STD_ADDR+0x4));
	outer_flush_range(AVCPU_STATUS_FLAG_STD_ADDR, AVCPU_STATUS_FLAG_STD_ADDR+0x4);

#ifdef CONFIG_SUPPORT_DEMOD
	device_pm_wait_for_dev(dev, get_rtkdemod_device_ptr());
#endif

again:	
	wait_flag = 0;
	while(time_before(jiffies, timeout))
	{
		invalidate_status_flag();

		if ((*((volatile int *)phys_to_virt(ACPU_STATUS_FLAG_ADDRESS)) & 0x03000000) == 0x03000000)
			wait_flag |= 1;

#ifdef CONFIG_RTK_KDRV_SUPPORT_ACPU2
		if ((*((volatile int *)phys_to_virt(ACPU2_STATUS_FLAG_ADDRESS)) & 0x0C000000) == 0x0C000000)
			wait_flag |= 8;
#endif

		if(((*((volatile int *)phys_to_virt(VCPU_STATUS_FLAG_ADDRESS)) & 0x03000000) == 0x03000000)
			||((rtd_inl(STB_WDOG_DATA14_reg)&0xC0000000) ==0xC0000000))
		{
			wait_flag |= 2;
		}

#ifdef CONFIG_RTK_KDRV_SUPPORT_VCPU2
		if(((*((volatile int *)phys_to_virt(VCPU2_STATUS_FLAG_ADDRESS)) & 0x03000000) == 0x03000000)
			||((rtd_inl(STB_WDOG_DATA14_reg)&0x30000000) ==0x30000000))
		{
			wait_flag |= 4;
		}
#endif

		if((wait_flag & AVCPU_FLAG) == AVCPU_FLAG)
			break;
	}

	if(!(wait_flag & 0x1))
	{

		printk(KERN_ERR "AUDIO 1 RESUME FAIL!! %x", *((volatile int *)phys_to_virt(ACPU_STATUS_FLAG_ADDRESS)));

#if 0 //test for futhure  
		if ( acpufail_check_flag < (_RETRY_ -1) ) //do not reset at last time.
		{
			rtd_outl(0xB8000100, _BIT12 | _BIT10 | _BIT2);
			rtd_outl(0xB8000104, _BIT19 | _BIT18 | _BIT17);
			rtd_outl(0xB8000110, _BIT12 | _BIT0);
			rtd_outl(0xB8000114, _BIT17 | _BIT0);
			rtd_outl(0xB8000118, _BIT15 | _BIT0);
			rtd_outl(0xB800011C, _BIT9 | _BIT8 | _BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
			rtd_outl(0xB8000110, _BIT12);
			rtd_outl(0xB8000114, _BIT17);
			rtd_outl(0xB8000118, _BIT15);
			rtd_outl(0xB800011C, _BIT9 | _BIT8 | _BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1);
			rtd_outl(0xB8000100, _BIT12 | _BIT10 | _BIT2);
			rtd_outl(0xB8000104, _BIT19 | _BIT18 | _BIT17);
			udelay(10);
			rtd_outl(0xB8000100, _BIT12 | _BIT10 | _BIT2 | _BIT0);
			rtd_outl(0xB8000104, _BIT19 | _BIT18 | _BIT17 | _BIT0);
			udelay(10);
			rtd_outl(0xB8000110, _BIT12 | _BIT0);
			rtd_outl(0xB8000114, _BIT17 | _BIT0);
			rtd_outl(0xB8000118, _BIT15 | _BIT0);
			rtd_outl(0xB800011C, _BIT9 | _BIT8 | _BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
			wait_flag |= 1;
			acpufail_check_flag++;
		}
		else
		{
			acpufail_check_flag = 0;
			printk(KERN_ERR "AUDIO fail over Five times!! [%x]\n", check_flag);
		}
#endif
		ret = -1;
	}

#ifdef CONFIG_RTK_KDRV_SUPPORT_ACPU2
	if(!(wait_flag & 0x8))
	{
		printk(KERN_ERR "AUDIO 2 RESUME FAIL!! %x", *((volatile int *)phys_to_virt(ACPU2_STATUS_FLAG_ADDRESS)));
		ret = -1;
	}
#endif

	if(!(wait_flag & 0x2))
	{
		printk(KERN_ERR "VIDEO RESUME FAIL!! %x", *((volatile int *)phys_to_virt(VCPU_STATUS_FLAG_ADDRESS)));
		ret = -1;
	}

#ifdef CONFIG_RTK_KDRV_SUPPORT_VCPU2
	if(!(wait_flag & 0x4))
	{
		printk(KERN_ERR "VIDEO2 RESUME FAIL!! %x", *((volatile int *)phys_to_virt(VCPU2_STATUS_FLAG_ADDRESS)));
		ret = -1;
	}
#endif

#if 0 //test for futhure  
	if ((wait_flag != 0xf)  &&
	    (acpufail_check_flag < _RETRY_))
		goto again;
#endif		
	/* Clear AV CPU resume status*/
	*((volatile int *)phys_to_virt(AVCPU_STATUS_FLAG_STD_ADDR)) = 0x0;
	dmac_flush_range(phys_to_virt(AVCPU_STATUS_FLAG_STD_ADDR),phys_to_virt(AVCPU_STATUS_FLAG_STD_ADDR+0x4));
	outer_flush_range(AVCPU_STATUS_FLAG_STD_ADDR, AVCPU_STATUS_FLAG_STD_ADDR+0x4);

	if(wait_flag != AVCPU_FLAG)
	{
		force_console_enable();
		panic("[AVCPU] Resume fail(%x/%x)\n", wait_flag, rtd_inl(STB_WDOG_DATA14_reg));

	}
	return ((wait_flag == AVCPU_FLAG) ? 0: -1);
}
#ifdef CONFIG_RTK_KDRV_AUDIO
struct device* get_rtkaudio_device_ptr(void);
#endif

static int avcpu_suspend(struct platform_device *dev, pm_message_t state)
{
	printk(KERN_NOTICE "Before [AVCPU] suspend\n");
#ifdef CONFIG_RTK_KDRV_AUDIO
	device_pm_wait_for_dev(&(dev->dev), get_rtkaudio_device_ptr());
#endif
	printk(KERN_NOTICE "[AVCPU] suspend (%d)\n", stravnoreload);

	if(stravnoreload == 1)
		avcpu_notify_suspend();

	avcpu_notifier_call_chain(AVCPU_SUSPEND);
	avcpu_notifier_call_chain(AVCPU_RESET_PREPARE);

	if(stravnoreload == 0)
	{
		resetav_lock(1);
		load_av_image(NULL, 0, NULL, 0, NULL, 0);
	}

	return 0;
}

static int avcpu_resume(struct platform_device *dev)
{
	printk(KERN_NOTICE "[AVCPU] resume (%d)\n", stravnoreload);

	if(stravnoreload == 0)
		resetav_unlock(1);

	avcpu_notifier_call_chain(AVCPU_RESET_DONE);
	avcpu_notifier_call_chain(AVCPU_RESUME);

	if(stravnoreload == 1)
		avcpu_notify_resume((struct device *)dev);

	return 0;
}
#endif

long avcpu_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	resetav_struct rs;
	int ret = 0;

	switch (cmd) {
	case AVCPU_IOCTRESET:
		ret = copy_from_user(&rs, (void *)arg, sizeof(rs));
		if (!ret) {
			blocking_notifier_call_chain(&avcpu_chain_head, AVCPU_RESET_PREPARE, NULL);

			if(stravnoreload == 0)
				load_av_image(rs.audio_image, rs.audio_start, rs.video_image_1, rs.video_start_1, rs.video_image_2, rs.video_start_2);
			blocking_notifier_call_chain(&avcpu_chain_head, AVCPU_RESET_DONE, NULL);
		}
		break;
	};

	return ret;
}

struct file_operations avcpu_fops = {
	.owner                  = THIS_MODULE,
	.unlocked_ioctl         = avcpu_ioctl,
};

static char *avcpu_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}

static unsigned int get_device_type(void)
{
	return DEVICE_EMMC;
}

static int load_av_from_file(int cpu, char *load_file, unsigned int load_addr)
{
	struct file *file;
	int file_size;

	printk("avcpu: load cpu %d from file %s to %x...\n", cpu, load_file, load_addr);
	file = filp_open(load_file, O_RDONLY, 0444);
	if (IS_ERR(file))
		return PTR_ERR(file);
	file_size = file->f_path.dentry->d_inode->i_size;
	printk("file: %p size: %d \n", file, file_size);
	if (kernel_read(file, 0, (char *)load_addr, file_size) != file_size)
		BUG();
	filp_close(file, 0);

	switch (cpu) {
	case AUDIO_CPU:
		*((unsigned long *)AUDIO_ENTRY_ADDR) = htonl(load_addr);
		printk("audio entry value: %08lx \n", *((unsigned long *)AUDIO_ENTRY_ADDR));
		break;
	case VIDEO_CPU_1:
		*((unsigned long *)VIDEO_ENTRY_ADDR_1) = htonl(load_addr);
		printk("video 1 entry value: %08lx \n", *((unsigned long *)VIDEO_ENTRY_ADDR_1));
		break;
	case VIDEO_CPU_2:
		*((unsigned long *)VIDEO_ENTRY_ADDR_2) = htonl(load_addr);
		printk("video 2 entry value: %08lx \n", *((unsigned long *)VIDEO_ENTRY_ADDR_2));
		break;
	default:
		printk("avcpu: unknown cpu...\n");
		return -ENODEV;
	}

	// flush the data cache...
#ifdef CONFIG_MIPS
	data_cache_flush(load_addr, file_size);
#endif

	return 0;
}

extern int mmc_fast_read(unsigned int, unsigned int, unsigned char *);

static int read_emmc_data(unsigned int blk_offset, size_t size, void *buf)
{
	int ret = 0;

	size = (size + (EMMC_BLOCK_SIZE -1)) & ~(EMMC_BLOCK_SIZE - 1);
	pr_info("avcpu: %s offset: %x, size: %lx, buf: %p \n", __func__, blk_offset, size / EMMC_BLOCK_SIZE, buf);
#ifdef CONFIG_MMC_RTKEMMC_PLUS
	ret = mmc_fast_read(blk_offset, size / EMMC_BLOCK_SIZE, buf);
#else
	panic("Please enable mmc support !!\n");
#endif
	return ret;
}

unsigned long mips_to_arm(unsigned long addr)
{
	return (unsigned long)__va(addr & 0x1fffffff);
}

int load_av_from_emmc(char *audio_image, unsigned int audio_start, 
	char *video_image_1, unsigned int video_start_1, char *video_image_2, unsigned int video_start_2)
{
	fw_desc_table_v1_t *fw_desc_table_v1;
	fw_desc_entry_v1_t *fw_entry;
	fw_desc_entry_v1_t *audio_fw_entry = NULL;
	fw_desc_entry_v1_t *video_fw_entry_1 = NULL;
	fw_desc_entry_v1_t *video_fw_entry_2 = NULL;
	part_desc_entry_v1_t *part_entry;
	unsigned int part_count;
	unsigned long header_buffer = 0;
	int i, ret = 0;

	header_buffer = __get_free_page(GFP_KERNEL);
	if (!header_buffer) {
		pr_info("avcpu: can not allocate enough memory...\n");
		return -ENOMEM;
	}

	ret = read_emmc_data(HEADER_OFFSET / EMMC_BLOCK_SIZE, PAGE_SIZE, (void *)header_buffer);
	if (ret < 0)
		goto out;

	fw_desc_table_v1 = (fw_desc_table_v1_t*)header_buffer;
	printk("avcpu: fw_desc_table_v1->signature = %s \n", fw_desc_table_v1->signature);
	printk("avcpu: fw_desc_table_v1->version = 0x%x \n", fw_desc_table_v1->version);

//	av_be32_to_cpu(fw_desc_table_v1->checksum);
//	av_be32_to_cpu(fw_desc_table_v1->paddings);
//	av_be32_to_cpu(fw_desc_table_v1->part_list_len);
//	av_be32_to_cpu(fw_desc_table_v1->fw_list_len);
	printk("avcpu: fw_desc_table_v1->part_list_len = 0x%x \n", fw_desc_table_v1->part_list_len);
	printk("avcpu: fw_desc_table_v1->fw_list_len = 0x%x \n", fw_desc_table_v1->fw_list_len);
	if (fw_desc_table_v1->part_list_len == 0 || fw_desc_table_v1->fw_list_len == 0) {
		printk("avcpu: No Audio/Video firmware found...\n");
		goto out;
	}

	part_count = fw_desc_table_v1->part_list_len / sizeof(part_desc_entry_v1_t);
	part_entry = (part_desc_entry_v1_t *)((unsigned long)fw_desc_table_v1 + sizeof(fw_desc_table_v1_t));
	fw_entry = (fw_desc_entry_v1_t *)((unsigned long)fw_desc_table_v1 + 
			sizeof(fw_desc_table_v1_t) + fw_desc_table_v1->part_list_len);
	printk("avcpu: fw_desc_table_v1 = 0x%p\n", fw_desc_table_v1);
	printk("avcpu: part_entry = 0x%p\n", part_entry);
	printk("avcpu: part_count = 0x%x\n", part_count);
	printk("avcpu: fw_entry = 0x%p\n", fw_entry);

	for (i = 0; i < (int)part_entry[0].fw_count; i++) {
		fw_desc_entry_v1_t *entry;
		switch (fw_desc_table_v1->version) {
			case 0x01:
				entry = (fw_desc_entry_v1_t *)((u8 *)fw_entry + i * sizeof(fw_desc_entry_v1_t));
				break;
			case 0x11:
				entry = (fw_desc_entry_v1_t *)((u8 *)fw_entry + i * sizeof(fw_desc_entry_v11_t));
				break;
			case 0x21:
				entry = (fw_desc_entry_v1_t *)((u8 *)fw_entry + i * sizeof(fw_desc_entry_v21_t));
				break;
			default:
				continue;
		}

//		av_be32_to_cpu(entry->version);
//		av_be32_to_cpu(entry->offset);
//		av_be32_to_cpu(entry->length);
//		av_be32_to_cpu(entry->paddings);
//		av_be32_to_cpu(entry->checksum);
//		av_be32_to_cpu(entry->target_addr);

		switch (entry->type) {
			case FW_TYPE_AUDIO:
				audio_fw_entry = entry;
				printk("avcpu: Audio FW found: %p \n", audio_fw_entry);
				break;
			case FW_TYPE_VIDEO:
				video_fw_entry_1 = entry;
				printk("avcpu: Video FW 1 found: %p \n", video_fw_entry_1);
				break;
			case FW_TYPE_VIDEO_2:
				video_fw_entry_2 = entry;
				printk("avcpu: Video FW 2 found: %p \n", video_fw_entry_2);
				break;
			case FW_TYPE_RESERVED:
			default:
				printk("avcpu: FW type, 0x%x \n", entry->type);
				break;
		}
	}

	if (audio_image) {
		if ((ret = load_av_from_file(AUDIO_CPU, audio_image, audio_start))) {
			printk("avcpu: load audio image error %d...\n", ret);
			goto out;
		}
	} else {
		if (audio_fw_entry == NULL) {
			printk("avcpu: can not find audio firmware from NAND flash...\n");
			ret = -ENODEV;
			goto out;
		}
		audio_fw_entry->target_addr = 0x81600000;
		printk("avcpu: audio_fw_entry->offset = 0x%x \n", audio_fw_entry->offset);
		printk("avcpu: audio_fw_entry->length = 0x%x \n", audio_fw_entry->length);
		printk("avcpu: audio_fw_entry->target_addr = 0x%x \n", audio_fw_entry->target_addr);

		// currently we only support align access...
		if (audio_fw_entry->offset & (EMMC_BLOCK_SIZE - 1))
			BUG();

		*((unsigned long *)AUDIO_ENTRY_ADDR) = htonl(audio_fw_entry->target_addr);
		printk("audio entry value: %08lx \n", *((unsigned long *)AUDIO_ENTRY_ADDR));

		audio_fw_entry->target_addr = mips_to_arm(audio_fw_entry->target_addr);
		ret = read_emmc_data(audio_fw_entry->offset / EMMC_BLOCK_SIZE, 
				audio_fw_entry->length, (void *)audio_fw_entry->target_addr);
		if (ret < 0)
			goto out;
		printk("ret: %lx length: %x \n", ret * EMMC_BLOCK_SIZE, audio_fw_entry->length);

		// flush the data cache...
//#ifdef CONFIG_MIPS
//		data_cache_flush(audio_fw_entry->target_addr, audio_fw_entry->length);
//#endif
	}

	if (video_image_1) {
		if ((ret = load_av_from_file(VIDEO_CPU_1, video_image_1, video_start_1))) {
			printk("avcpu: load video image 1 error %d...\n", ret);
			goto out;
		}
	} else {
		if (video_fw_entry_1 == NULL) {
			printk("avcpu: can not find video firmware 1 from NAND flash...\n");
			ret = -ENODEV;
			goto out;
		}
		video_fw_entry_1->target_addr = 0x81a00000;
		printk("avcpu: video_fw_entry_1->offset = 0x%x \n", video_fw_entry_1->offset);
		printk("avcpu: video_fw_entry_1->length = 0x%x \n", video_fw_entry_1->length);
		printk("avcpu: video_fw_entry_1->target_addr = 0x%x \n", video_fw_entry_1->target_addr);
		
		// currently we only support align access...
		if (video_fw_entry_1->offset & (EMMC_BLOCK_SIZE - 1))
			BUG();

		*((unsigned long *)VIDEO_ENTRY_ADDR_1) = htonl(video_fw_entry_1->target_addr);
		printk("video entry 1 value: %08lx \n", *((unsigned long *)VIDEO_ENTRY_ADDR_1));

		video_fw_entry_1->target_addr = mips_to_arm(video_fw_entry_1->target_addr);
		ret = read_emmc_data(video_fw_entry_1->offset / EMMC_BLOCK_SIZE, 
				video_fw_entry_1->length, (void *)video_fw_entry_1->target_addr);
		if (ret < 0)
			goto out;
		printk("ret: %lx length: %x \n", ret * EMMC_BLOCK_SIZE, video_fw_entry_1->length);

		// flush the data cache...
//#ifdef CONFIG_MIPS
//		data_cache_flush(video_fw_entry->target_addr, video_fw_entry->length);
//#endif
	}

	if (video_image_2) {
		if ((ret = load_av_from_file(VIDEO_CPU_2, video_image_2, video_start_2))) {
			printk("avcpu: load video image 2 error %d...\n", ret);
			goto out;
		}
	} else {
		if (video_fw_entry_2 == NULL) {
			printk("avcpu: can not find video firmware 2 from NAND flash...\n");
			ret = -ENODEV;
			goto out;
		}
		video_fw_entry_2->target_addr = 0x81e00000;
		printk("avcpu: video_fw_entry_2->offset = 0x%x \n", video_fw_entry_2->offset);
		printk("avcpu: video_fw_entry_2->length = 0x%x \n", video_fw_entry_2->length);
		printk("avcpu: video_fw_entry_2->target_addr = 0x%x \n", video_fw_entry_2->target_addr);
		
//		// currently we only support align access...
		if (video_fw_entry_2->offset & (EMMC_BLOCK_SIZE - 1))
			BUG();

		*((unsigned long *)VIDEO_ENTRY_ADDR_2) = htonl(video_fw_entry_2->target_addr);
		printk("video entry 2 value: %08lx \n", *((unsigned long *)VIDEO_ENTRY_ADDR_2));

		video_fw_entry_2->target_addr = mips_to_arm(video_fw_entry_2->target_addr);
		ret = read_emmc_data(video_fw_entry_2->offset / EMMC_BLOCK_SIZE, 
				video_fw_entry_2->length, (void *)video_fw_entry_2->target_addr);
		if (ret < 0)
			goto out;
		printk("ret: %lx length: %x \n", ret * EMMC_BLOCK_SIZE, video_fw_entry_2->length);

//		// flush the data cache...
//#ifdef CONFIG_MIPS
//		data_cache_flush(video_fw_entry->target_addr, video_fw_entry->length);
//#endif
	}

out:
	free_page(header_buffer);

	return ret;
}

int load_av_image(char *audio_image, unsigned int audio_start, 
	char *video_image_1, unsigned int video_start_1, char *video_image_2, unsigned int video_start_2)
{
	unsigned int flash_type;
	int ret;

	flash_type = get_device_type();
	printk("avcpu: flash_type: %d \n", flash_type);

	// load firmware image
	if ((audio_image != 0) && (video_image_1 != 0) && (video_image_2 != 0)) {
		if ((ret = load_av_from_file(AUDIO_CPU, audio_image, audio_start)))
			printk("avcpu: load audio image error %d...\n", ret);
		if ((ret = load_av_from_file(VIDEO_CPU_1, video_image_1, video_start_1)))
			printk("avcpu: load video image 1 error %d...\n", ret);
		if ((ret = load_av_from_file(0, video_image_2, video_start_2)))
			printk("avcpu: load video image 2 error %d...\n", ret);
	} else if (flash_type == DEVICE_EMMC) {
		load_av_from_emmc(audio_image, audio_start, video_image_1, video_start_1, video_image_2, video_start_2);
	} else {
		printk("avcpu: unsupported operation...\n");
		BUG();
	}

	// sync the a/v header info
	dmac_flush_range((void *)PAGE_OFFSET, (void *)(PAGE_OFFSET + PAGE_SIZE));
	outer_flush_range(0, 0 + PAGE_SIZE);

	return 0;
}

static int avcpu_init(void)
{
	int result;
	dev_t dev = MKDEV(AVCPU_MAJOR, 0);

	printk(KERN_NOTICE "avcpu: audio & video cpu driver for Realtek Media Processors(2015/08/18)\n");

	result = register_chrdev_region(dev, 1, "avcpu");
	if (result < 0) {
		printk("avcpu: can not get chrdev region...\n");
		return result;
	}

	avcpu_class = class_create(THIS_MODULE, "avcpu");
	if (IS_ERR(avcpu_class)) {
		printk("avcpu: can not create class...\n");
		result = PTR_ERR(avcpu_class);
		goto fail_class_create;
	}

	avcpu_class->devnode = avcpu_devnode;

	avcpu_platform_devs = platform_device_register_simple("avcpu", -1, NULL, 0);
	if (platform_driver_register(&avcpu_device_driver) != 0) {
		printk("avcpu: can not register platform driver...\n");
		result = -EINVAL;
		goto fail_platform_driver_register;
	}

	cdev_init(&avcpu_cdev, &avcpu_fops);
	avcpu_cdev.owner = THIS_MODULE;
	avcpu_cdev.ops = &avcpu_fops;
	result = cdev_add(&avcpu_cdev, dev, 1);
	if (result < 0) {
		printk("avcpu: can not add character device...\n");
		goto fail_cdev_init;
	}
	device_create(avcpu_class, NULL, dev, NULL, "avcpu");

	/* [[KTASKWBS-1065] Make AVCPU resume run at asynchronous for parallel resume time*/
	device_enable_async_suspend(&(avcpu_platform_devs->dev));

	return 0;

fail_cdev_init:
	platform_driver_unregister(&avcpu_device_driver);
fail_platform_driver_register:
	platform_device_unregister(avcpu_platform_devs);
	avcpu_platform_devs = NULL;
	class_destroy(avcpu_class);
fail_class_create:
	avcpu_class = NULL;
	unregister_chrdev_region(dev, 1);
	return result;
}

static void avcpu_exit(void)
{
	dev_t dev = MKDEV(AVCPU_MAJOR, 0);

	if ((avcpu_platform_devs == NULL) || (avcpu_class == NULL))
		BUG();

	device_destroy(avcpu_class, dev);
	cdev_del(&avcpu_cdev);

	platform_driver_unregister(&avcpu_device_driver);
	platform_device_unregister(avcpu_platform_devs);
	avcpu_platform_devs = NULL;

	class_destroy(avcpu_class);
	avcpu_class = NULL;

	unregister_chrdev_region(dev, 1);
}

static int __init setup_av_ctrl(char *cmdline)
{
	printk("Enable use STR AV NOT Reload\n");
	stravnoreload = 1;
	return 0;

}

early_param("stravnoreload", setup_av_ctrl);

module_init(avcpu_init);
module_exit(avcpu_exit);
