#include <linux/uaccess.h>
#include <linux/proc_fs.h>

#define MAX_USER_CALLS  32
extern struct user_initcall_param __user_initcall_start[];
extern struct user_initcall_param __user_initcall_end[];
static struct user_initcall_param usercalls[MAX_USER_CALLS] = {{NULL, NULL},};
static int usercalls_stat;

unsigned int nouserinit;
EXPORT_SYMBOL(nouserinit);

static int __init set_nouserinit(char *str)
{
	nouserinit = 1;
	return 0;
}
early_param("nouserinit", set_nouserinit);

static void do_user_initcalls(const char *p_group)
{
	int i;
	struct user_initcall_param *user_init;

	for (i = 0; i < MAX_USER_CALLS; i++) {
		char *msg = NULL;
		char msgbuf[40];
		int result;

		user_init = &usercalls[i];

		if (user_init->fn == NULL ||  user_init->name == NULL)
			break;

		if (strcmp(p_group, "1") != 0
			&& strcmp(user_init->name, p_group) != 0)
			continue;

		if (initcall_debug)
			pr_debug("Calling user_initcall %ps group : %s\n",
				user_init->fn, user_init->name);

		result = user_init->fn();
		if (result && result != -ENODEV && initcall_debug) {
			sprintf(msgbuf, "error code %d", result);
			msg = msgbuf;
		}
		if (irqs_disabled()) {
			msg = "disabled interrupts";
			local_irq_enable();
		}
		if (msg) {
			pr_err("user_initcall at %ps,group : %s %s\n",
				user_init->fn, user_init->name, msg);
		}
	}
}

/*
 * Execute user_initcalls here by writing /proc/usercalls.
 * proc read/write for /proc/usercalls
 */
static int proc_read_usercalls(struct file *file, char __user *buf,
				size_t size, loff_t *ppos)
{
	size_t len;
	char kbuf[10];

	if (*ppos > 0)
		return 0;

	len = sprintf(kbuf, "%d\n", usercalls_stat);
	if (copy_to_user(buf, kbuf, len))
		return -EFAULT;
	*ppos += len;
	return len;
}

static int proc_write_usercalls(struct file *file, const char __user *buffer,
	size_t count, loff_t *ppos)
{
	char kbuf[16];

	if (count == 0 || count >= 16 || copy_from_user(kbuf, buffer, count))
			return  -EFAULT;

	kbuf[count] = '\0';
	if (kbuf[count - 1] == '\n') kbuf[count - 1] = '\0';

	if (usercalls_stat == 0 && strlen(kbuf) > 0) {
		do_user_initcalls(kbuf);
		if (strcmp(kbuf, "1") == 0)
			usercalls_stat = 1;
	}
	return count;
}


static const struct file_operations proc_usercalls_fops = {
	.read	= proc_read_usercalls,
	.write	= proc_write_usercalls
};

static int __init do_user_initcalls_setup(void)
{
	int num_calls = 0;
	struct user_initcall_param *user_init;

	/* Initialize user initcalls */
	for (user_init = __user_initcall_start; user_init < __user_initcall_end
		&& num_calls < MAX_USER_CALLS; user_init++) {
		if (initcall_debug)
			pr_debug("Adding user_initcall[%d] 0x%p, group %s\n",
				num_calls, user_init->fn, user_init->name);
		usercalls[num_calls].fn = user_init->fn;
		usercalls[num_calls].name = user_init->name;
		num_calls++;
	}

	if (nouserinit) {
		pr_info("nouserinit=%d\n", nouserinit);
		do_user_initcalls("1");
		usercalls_stat = 1;
	}
	/*
	 * create procfs file for usercalls.
	 */
	if (!proc_create("usercalls", 0666, NULL, &proc_usercalls_fops)) {
		pr_err("Error: unable to make proc usercalls.\n");
		return -1;
	}
	printk("do_user_initcalls_setup\n");
	return 0;
}

device_initcall(do_user_initcalls_setup);
