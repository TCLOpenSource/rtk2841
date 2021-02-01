#include <linux/syscalls.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <mach/io.h>

#define RNG_RETURN3		0xB800182C
#define RNG_RESULTR		0xB8001838

unsigned int get_rtk_rng(void)
{
	unsigned int rtn;

	while ((rtd_inl(RNG_RETURN3) & 0x1)==0) ;

	rtn = rtd_inl(RNG_RESULTR);

	return rtn;
}

int rng_open(struct inode *inode, struct file *file)
{
	return 0;
}

int rng_release(struct inode *inode, struct file *file)
{
	return 0;
}

ssize_t rng_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	unsigned int random_number = 0;

	random_number = get_rtk_rng();

	if(copy_to_user(buf, &random_number, 4))
		return -EFAULT;

	return 4;
}

static struct file_operations rng_fops = {
	.owner		= THIS_MODULE,
	.open		= rng_open,
	.read		= rng_read,
	.release	= rng_release,
};

static struct miscdevice rng_miscdev = {
	MISC_DYNAMIC_MINOR,
	"rtk_rng",
	&rng_fops
};

int __init rng_module_init(void)
{
	if (misc_register(&rng_miscdev)) {
		pr_warning("[RNG]:rng_module_init failed - register misc device failed\n");
		return -ENODEV;
	}

	return 0;
}

static void __exit rng_module_exit(void)
{
	misc_deregister(&rng_miscdev);
}

module_init(rng_module_init);
module_exit(rng_module_exit);
MODULE_LICENSE("GPL");
