#include <generated/autoconf.h>

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>	/* DBG_PRINT() */
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/hw_breakpoint.h>

//#include <asm/system.h>		/* cli(), *_flags */
#include <asm/uaccess.h>	/* copy_*_user */
#include <asm/ioctl.h>
#include <asm/irq.h>
#include <asm/bitops.h>		/* bit operations */
#include <asm/hw_breakpoint.h>


/* Module Variables */
/*
 * Our parameters which can be set at load time.
 */

//#define DEV_DEBUG
#define VENUS_WATCH_MAJOR			235
#define VENUS_WATCH_MINOR			0
#define VENUS_WATCH_NAME			"venus_watch"

//int watch_major = VENUS_WATCH_MAJOR;
int watch_major = 0; // dynamic
int watch_minor = VENUS_WATCH_MINOR;

typedef struct {
	unsigned long		addr;
	unsigned long		prot;
} watch_struct;

#define WATCH_IOC_MAGIC				'j'
#define WATCH_IOQGETASID			_IO(WATCH_IOC_MAGIC, 1)
#define WATCH_IOSSETWATCH			_IOW(WATCH_IOC_MAGIC, 2, watch_struct)
#define WATCH_IOTCLRWATCH			_IO(WATCH_IOC_MAGIC, 3)


static DECLARE_WAIT_QUEUE_HEAD(venus_watch_read_wait);

extern unsigned int read_wb_reg(int n);

// kernel space test
//#define KERNEL_SPACE_ADDR_TEST 1
#ifdef KERNEL_SPACE_ADDR_TEST
int mytest=0;
#endif

/* Major Number + Minor Number */
static struct class *venus_watch_class;

MODULE_AUTHOR("I-Chieh Hsu, Realtek Semiconductor");
MODULE_LICENSE("Dual BSD/GPL");

/*
 * from include/uapi/linux/hw_breakpoint.h
 * len: HW_BREAKPOINT_LEN_1, HW_BREAKPOINT_LEN_2, HW_BREAKPOINT_LEN_4, HW_BREAKPOINT_LEN_8.
 * type: HW_BREAKPOINT_R, HW_BREAKPOINT_W, HW_BREAKPOINT_RW.
 */
int set_watch_point(unsigned long addr, unsigned long prot)
{
	int ret = 0;
	struct arch_hw_breakpoint info[1];
	unsigned int alignment_mask = 0x3;
	int len = HW_BREAKPOINT_LEN_4;

	memset(info, 0, sizeof(struct arch_hw_breakpoint));

	info->ctrl.mismatch = 0;
	info->ctrl.privilege = ARM_BREAKPOINT_USER | ARM_BREAKPOINT_PRIV;
	info->ctrl.enabled = 1;

	/* Type */
	switch (prot) {
	case HW_BREAKPOINT_X:
		pr_debug("non support breakpoint\n");
		break;
	case HW_BREAKPOINT_R:
		info->ctrl.type = ARM_BREAKPOINT_LOAD;
		break;
	case HW_BREAKPOINT_W:
		info->ctrl.type = ARM_BREAKPOINT_STORE;
		break;
	case HW_BREAKPOINT_RW:
		info->ctrl.type = ARM_BREAKPOINT_LOAD | ARM_BREAKPOINT_STORE;
		break;
	default:
		pr_debug("no support watchpoint type, assert!\n");
		break;
	}

	/* Len */
	switch (len) {
	case HW_BREAKPOINT_LEN_1:
		info->ctrl.len = ARM_BREAKPOINT_LEN_1;
		break;
	case HW_BREAKPOINT_LEN_2:
		info->ctrl.len = ARM_BREAKPOINT_LEN_2;
		break;
	case HW_BREAKPOINT_LEN_4:
		info->ctrl.len = ARM_BREAKPOINT_LEN_4;
		break;
	case HW_BREAKPOINT_LEN_8:
	default:
		pr_debug("no support watchpoint len, assert!\n");
		break;
	}

	info->address = addr & ~alignment_mask;

	pr_debug("set_watch_point ctrl.en=%x, privilege=%x, type=%x, len=%x, mismatch=%x\n", 
		   info->ctrl.enabled, info->ctrl.privilege, info->ctrl.type, info->ctrl.len, info->ctrl.mismatch);
	pr_debug("set_watch_point addr=%x, ctrl=%x\n", info->address, encode_ctrl_reg(info->ctrl));

	ret = arch_install_hw_breakpoint1(info);

	return ret;
}
EXPORT_SYMBOL(set_watch_point);

int clr_watch_point(void)
{
	struct arch_hw_breakpoint info[1];

	memset(info, 0, sizeof(struct arch_hw_breakpoint));
	info->ctrl.type = ARM_BREAKPOINT_LOAD | ARM_BREAKPOINT_STORE;

	arch_uninstall_hw_breakpoint1(info);

	return 0;
}
EXPORT_SYMBOL(clr_watch_point);


/* Module Functions */

int venus_watch_release(struct inode *inode, struct file *filp)
{
	//clr_watch_point();
	return 0;
}

long venus_watch_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	watch_struct ws;
	int ret = 0;
	unsigned val;

	switch (cmd) {
		case WATCH_IOQGETASID:
			asm volatile("mrc 14, 0, %0, cr0, cr0, 7" : "=r" (val)); //WCR
			pr_debug("get WCR= %x\n", val);

			asm volatile("mrc 14, 0, %0, cr0, cr0, 6" : "=r" (val)); //WVR
			pr_debug("get WVR= %x\n", val);

			break;
		case WATCH_IOSSETWATCH:
			ret = copy_from_user(&ws, (void *)arg, sizeof(ws));

			if (!ret) {
        #ifdef KERNEL_SPACE_ADDR_TEST
				pr_debug("addr=%p, prot=%lx\n", &mytest, ws.prot);
				set_watch_point((unsigned long)&mytest, ws.prot);
        #else
				pr_debug("addr=%lx, prot=%lx\n", ws.addr, ws.prot);
				set_watch_point(ws.addr, ws.prot);
        #endif
			}

        #ifdef KERNEL_SPACE_ADDR_TEST
			mytest = 2; // kernel space test
        #endif
			break;
		case WATCH_IOTCLRWATCH:
			clr_watch_point();
			break;
		default:
			return -ENOIOCTLCMD;
	}

	return ret;
}

struct file_operations venus_watch_fops = {
	.owner =	THIS_MODULE,
	.unlocked_ioctl =	venus_watch_ioctl,
	.release =	venus_watch_release,
};

static char *venus_watch_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}

int venus_watch_init_module(void) {
	int result;

	result = register_chrdev(watch_major, VENUS_WATCH_NAME, &venus_watch_fops);
	if (result < 0) {
		pr_err("watchpoint: can not register (%d %d)...\n", watch_major, watch_minor);
		return result;
	}

	if (watch_major == 0)
		watch_major = result;  // dynamic
	pr_info("venus watch major number: %d\n", watch_major);

	venus_watch_class = class_create(THIS_MODULE, "venus_watch");
	if (IS_ERR(venus_watch_class))
		return PTR_ERR(venus_watch_class);

	venus_watch_class->devnode = venus_watch_devnode;
	device_create(venus_watch_class, NULL, MKDEV(watch_major, watch_minor), NULL, "watch");

	return result;
}

void venus_watch_cleanup_module(void) {
	device_destroy(venus_watch_class, MKDEV(watch_major, watch_minor));
	class_destroy(venus_watch_class);
	unregister_chrdev(watch_major, VENUS_WATCH_NAME);
}

/* Register Macros */

module_init(venus_watch_init_module);
module_exit(venus_watch_cleanup_module);
