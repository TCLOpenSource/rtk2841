/*
 * kernel/power/main.c - PM subsystem core functionality.
 *
 * Copyright (c) 2003 Patrick Mochel
 * Copyright (c) 2003 Open Source Development Lab
 *
 * This file is released under the GPLv2
 *
 */

#include <linux/export.h>
#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/pm-trace.h>
#include <linux/workqueue.h>
#include <linux/debugfs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>

#include "power.h"

DEFINE_MUTEX(pm_mutex);

#ifdef CONFIG_LG_SNAPSHOT_BOOT
#include <linux/slab.h>

unsigned int snapshot_enable = 0;

// 0 : making, 1 : resume
unsigned int snapshot_status = 0;

static int __init hib_state_set_snapshot(char *p)
{
	snapshot_enable = 1;
	return 0;
}

early_param("snapshot", hib_state_set_snapshot);


unsigned int snapshot_art = 0;
static int __init hib_set_snapshot_art(char *p)
{
        snapshot_art = 1;
        return 0;
}

early_param("snapshot_art", hib_set_snapshot_art);

/* This variable will be set by IOCTL LGSNAP_HIBERNATION  */
unsigned int hibernation_enable = 0;

static ssize_t mode_show(struct kobject *kobj, struct kobj_attribute *attr,
			     char *buf)
{
	extern unsigned int snapshot_enable;
	unsigned char *str;

	if (snapshot_enable == 1) {
		if (snapshot_status == 0)
			str = "making";
		else
			str = "resume";
 	} else {
		str = "cold";
	}

	return sprintf(buf, "%s\n", str);
}

static ssize_t mode_store(struct kobject *kobj, struct kobj_attribute *attr,
			      const char *buf, size_t n)
{
	return n;
}

power_attr(mode);

/* comma separated string */
char *snapshot_dep_parts;

static int show_dep_parts(struct seq_file *m, void *v)
{
	if(snapshot_dep_parts)
		seq_printf(m, "%s\n", snapshot_dep_parts);

	return 0;
}

static ssize_t write_dep_parts(struct file *file, const char __user *buffer,
			     size_t count, loff_t *ppos)
{
	char *prev = snapshot_dep_parts;

	snapshot_dep_parts = kmalloc(count + 1, GFP_KERNEL);
	if (!snapshot_dep_parts)
		return -ENOMEM;
	if (copy_from_user(snapshot_dep_parts, buffer, count)) {
		kfree(snapshot_dep_parts);
		snapshot_dep_parts = prev;
		return -EFAULT;
	}
	snapshot_dep_parts[count-1] = '\0';

	if (prev)
		kfree(prev);

	return count;
}

static int open_dep_parts(struct inode *inode, struct file *file)
{
	return single_open(file, show_dep_parts, NULL);
}

static const struct file_operations dep_parts_fops = {
	.open = open_dep_parts,
	.read = seq_read,
	.llseek = seq_lseek,
	.write = write_dep_parts
};

static int __init proc_snapshot_boot_init(void)
{
	struct proc_dir_entry *snapshot_boot_ProcEntry;
	snapshot_boot_ProcEntry = proc_mkdir("snapshot", NULL);

	if (!proc_create("dep_parts", S_IFREG | S_IRWXUGO, 
		snapshot_boot_ProcEntry, &dep_parts_fops))
		goto remove_dir;

	return 0;
	
remove_dir:
	remove_proc_entry("snapshot_boot", NULL);

	return -1;
}

core_initcall(proc_snapshot_boot_init);
#endif

#ifdef CONFIG_PM_SLEEP

/* Routines for PM-transition notifications */

static BLOCKING_NOTIFIER_HEAD(pm_chain_head);

int register_pm_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&pm_chain_head, nb);
}
EXPORT_SYMBOL_GPL(register_pm_notifier);

int unregister_pm_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_unregister(&pm_chain_head, nb);
}
EXPORT_SYMBOL_GPL(unregister_pm_notifier);

int pm_notifier_call_chain(unsigned long val)
{
	int ret = blocking_notifier_call_chain(&pm_chain_head, val, NULL);

	return notifier_to_errno(ret);
}

/* If set, devices may be suspended and resumed asynchronously. */
int pm_async_enabled = 1;

static ssize_t pm_async_show(struct kobject *kobj, struct kobj_attribute *attr,
			     char *buf)
{
	return sprintf(buf, "%d\n", pm_async_enabled);
}

static ssize_t pm_async_store(struct kobject *kobj, struct kobj_attribute *attr,
			      const char *buf, size_t n)
{
	unsigned long val;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	if (val > 1)
		return -EINVAL;

	pm_async_enabled = val;
	return n;
}

power_attr(pm_async);

/* If set, devices may be resumed by user-layer. */
int pm_userresume_enabled = 1;

static ssize_t pm_userresume_show(struct kobject *kobj, struct kobj_attribute *attr,
			     char *buf)
{
	return dpm_show_userresume_list(buf);
}

static ssize_t pm_userresume_store(struct kobject *kobj, struct kobj_attribute *attr,
			      const char *buf, size_t n)
{
	ssize_t ret;

	if (pm_userresume_enabled) {
		/*
		 * When some devices are resumed by this feature, user-layer application
		 * is already able to be running because all tasks are un-freezed. This
		 * means that user application can enter into suspend again before
		 * user-resume is done.
		 *
		 * In order to avoid the conflict, locking pm_mutex is required to indicate
		 * that "this is not a good time to enter into suspend. Something related
		 * to PM is not done yet.
		 */
		if (!mutex_trylock(&pm_mutex))
			ret = -EBUSY;
		else {
			dpm_resume_user(PMSG_RESUME);
			mutex_unlock(&pm_mutex);

			ret = n;
		}
	}
	else
		ret = -EPERM;

	return ret;
}

power_attr(pm_userresume);

static ssize_t pm_userresume_enable_show(struct kobject *kobj, struct kobj_attribute *attr,
			     char *buf)
{
	return sprintf(buf, "%d\n", pm_userresume_enabled);
}

static ssize_t pm_userresume_enable_store(struct kobject *kobj, struct kobj_attribute *attr,
			      const char *buf, size_t n)
{
	unsigned long val;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	if (val > 2)
		return -EINVAL;

	pm_userresume_enabled = val;
	return n;
}

power_attr(pm_userresume_enable);

#ifdef CONFIG_PM_DEBUG
int pm_test_level = TEST_NONE;

static const char * const pm_tests[__TEST_AFTER_LAST] = {
	[TEST_NONE] = "none",
	[TEST_CORE] = "core",
	[TEST_CPUS] = "processors",
	[TEST_PLATFORM] = "platform",
	[TEST_DEVICES] = "devices",
	[TEST_FREEZER] = "freezer",
};

static ssize_t pm_test_show(struct kobject *kobj, struct kobj_attribute *attr,
				char *buf)
{
	char *s = buf;
	int level;

	for (level = TEST_FIRST; level <= TEST_MAX; level++)
		if (pm_tests[level]) {
			if (level == pm_test_level)
				s += sprintf(s, "[%s] ", pm_tests[level]);
			else
				s += sprintf(s, "%s ", pm_tests[level]);
		}

	if (s != buf)
		/* convert the last space to a newline */
		*(s-1) = '\n';

	return (s - buf);
}

static ssize_t pm_test_store(struct kobject *kobj, struct kobj_attribute *attr,
				const char *buf, size_t n)
{
	const char * const *s;
	int level;
	char *p;
	int len;
	int error = -EINVAL;

#ifdef CONFIG_LG_INSTANT_DENY_PM_TEST
	return -EACCES;
#endif

	p = memchr(buf, '\n', n);
	len = p ? p - buf : n;

	lock_system_sleep();

	level = TEST_FIRST;
	for (s = &pm_tests[level]; level <= TEST_MAX; s++, level++)
		if (*s && len == strlen(*s) && !strncmp(buf, *s, len)) {
			pm_test_level = level;
			error = 0;
			break;
		}

	unlock_system_sleep();

	return error ? error : n;
}

power_attr(pm_test);

static bool pm_rhal_test_enabled = false;
static ssize_t pm_rhal_test_show(struct kobject *kobj, struct kobj_attribute *attr,
				char *buf)
{
        return sprintf(buf, "%d\n", pm_rhal_test_enabled);
}

static ssize_t pm_rhal_test_store(struct kobject *kobj, struct kobj_attribute *attr,
				const char *buf, size_t n)
{
        unsigned long val;

        if (kstrtoul(buf, 10, &val))
                return -EINVAL;

        if (val > 1)
                return -EINVAL;

        pm_rhal_test_enabled = !!val;

        return n;
}

power_attr(pm_rhal_test);

#endif /* CONFIG_PM_DEBUG */



#ifdef CONFIG_DEBUG_FS
static char *suspend_step_name(enum suspend_stat_step step)
{
	switch (step) {
	case SUSPEND_FREEZE:
		return "freeze";
	case SUSPEND_PREPARE:
		return "prepare";
	case SUSPEND_SUSPEND:
		return "suspend";
	case SUSPEND_SUSPEND_NOIRQ:
		return "suspend_noirq";
	case SUSPEND_RESUME_NOIRQ:
		return "resume_noirq";
	case SUSPEND_RESUME:
		return "resume";
	default:
		return "";
	}
}

static int suspend_stats_show(struct seq_file *s, void *unused)
{
	int i, index, last_dev, last_errno, last_step;

	last_dev = suspend_stats.last_failed_dev + REC_FAILED_NUM - 1;
	last_dev %= REC_FAILED_NUM;
	last_errno = suspend_stats.last_failed_errno + REC_FAILED_NUM - 1;
	last_errno %= REC_FAILED_NUM;
	last_step = suspend_stats.last_failed_step + REC_FAILED_NUM - 1;
	last_step %= REC_FAILED_NUM;
	seq_printf(s, "%s: %d\n%s: %d\n%s: %d\n%s: %d\n%s: %d\n"
			"%s: %d\n%s: %d\n%s: %d\n%s: %d\n%s: %d\n",
			"success", suspend_stats.success,
			"fail", suspend_stats.fail,
			"failed_freeze", suspend_stats.failed_freeze,
			"failed_prepare", suspend_stats.failed_prepare,
			"failed_suspend", suspend_stats.failed_suspend,
			"failed_suspend_late",
				suspend_stats.failed_suspend_late,
			"failed_suspend_noirq",
				suspend_stats.failed_suspend_noirq,
			"failed_resume", suspend_stats.failed_resume,
			"failed_resume_early",
				suspend_stats.failed_resume_early,
			"failed_resume_noirq",
				suspend_stats.failed_resume_noirq);
	seq_printf(s,	"failures:\n  last_failed_dev:\t%-s\n",
			suspend_stats.failed_devs[last_dev]);
	for (i = 1; i < REC_FAILED_NUM; i++) {
		index = last_dev + REC_FAILED_NUM - i;
		index %= REC_FAILED_NUM;
		seq_printf(s, "\t\t\t%-s\n",
			suspend_stats.failed_devs[index]);
	}
	seq_printf(s,	"  last_failed_errno:\t%-d\n",
			suspend_stats.errno[last_errno]);
	for (i = 1; i < REC_FAILED_NUM; i++) {
		index = last_errno + REC_FAILED_NUM - i;
		index %= REC_FAILED_NUM;
		seq_printf(s, "\t\t\t%-d\n",
			suspend_stats.errno[index]);
	}
	seq_printf(s,	"  last_failed_step:\t%-s\n",
			suspend_step_name(
				suspend_stats.failed_steps[last_step]));
	for (i = 1; i < REC_FAILED_NUM; i++) {
		index = last_step + REC_FAILED_NUM - i;
		index %= REC_FAILED_NUM;
		seq_printf(s, "\t\t\t%-s\n",
			suspend_step_name(
				suspend_stats.failed_steps[index]));
	}

	return 0;
}

static int suspend_stats_open(struct inode *inode, struct file *file)
{
	return single_open(file, suspend_stats_show, NULL);
}

static const struct file_operations suspend_stats_operations = {
	.open           = suspend_stats_open,
	.read           = seq_read,
	.llseek         = seq_lseek,
	.release        = single_release,
};

static int __init pm_debugfs_init(void)
{
	debugfs_create_file("suspend_stats", S_IFREG | S_IRUGO,
			NULL, NULL, &suspend_stats_operations);
	return 0;
}

late_initcall(pm_debugfs_init);
#endif /* CONFIG_DEBUG_FS */

#endif /* CONFIG_PM_SLEEP */

#ifdef CONFIG_PM_SLEEP_DEBUG
/*
 * pm_print_times: print time taken by devices to suspend and resume.
 *
 * show() returns whether printing of suspend and resume times is enabled.
 * store() accepts 0 or 1.  0 disables printing and 1 enables it.
 */
bool pm_print_times_enabled;

static ssize_t pm_print_times_show(struct kobject *kobj,
				   struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n", pm_print_times_enabled);
}

static ssize_t pm_print_times_store(struct kobject *kobj,
				    struct kobj_attribute *attr,
				    const char *buf, size_t n)
{
	unsigned long val;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	if (val > 1)
		return -EINVAL;

	pm_print_times_enabled = !!val;
	return n;
}

power_attr(pm_print_times);

static inline void pm_print_times_init(void)
{
	pm_print_times_enabled = !!initcall_debug;
}

static ssize_t pm_wakeup_irq_show(struct kobject *kobj,
					struct kobj_attribute *attr,
					char *buf)
{
	return pm_wakeup_irq ? sprintf(buf, "%u\n", pm_wakeup_irq) : -ENODATA;
}

static ssize_t pm_wakeup_irq_store(struct kobject *kobj,
					struct kobj_attribute *attr,
					const char *buf, size_t n)
{
	return -EINVAL;
}
power_attr(pm_wakeup_irq);

#else /* !CONFIG_PM_SLEEP_DEBUG */
static inline void pm_print_times_init(void) {}
#endif /* CONFIG_PM_SLEEP_DEBUG */

struct kobject *power_kobj;

/**
 * state - control system sleep states.
 *
 * show() returns available sleep state labels, which may be "mem", "standby",
 * "freeze" and "disk" (hibernation).  See Documentation/power/states.txt for a
 * description of what they mean.
 *
 * store() accepts one of those strings, translates it into the proper
 * enumerated value, and initiates a suspend transition.
 */
static ssize_t state_show(struct kobject *kobj, struct kobj_attribute *attr,
			  char *buf)
{
	char *s = buf;
#ifdef CONFIG_SUSPEND
	suspend_state_t i;

	for (i = PM_SUSPEND_MIN; i < PM_SUSPEND_MAX; i++)
		if (pm_states[i])
			s += sprintf(s,"%s ", pm_states[i]);

#endif
	if (hibernation_available())
		s += sprintf(s, "disk ");
	if (s != buf)
		/* convert the last space to a newline */
		*(s-1) = '\n';
	return (s - buf);
}

static suspend_state_t decode_state(const char *buf, size_t n)
{
#ifdef CONFIG_SUSPEND
	suspend_state_t state;
#endif
	char *p;
	int len;

	p = memchr(buf, '\n', n);
	len = p ? p - buf : n;

	/* Check hibernation first. */
	if (len == 4 && !strncmp(buf, "disk", len))
		return PM_SUSPEND_MAX;

/*MA6PBU-1378, convert emcu_on into standby pm state*/
#if 1
	if (len == 7 && !strncmp(buf, "emcu_on", len))
		return PM_SUSPEND_STANDBY;
#endif

#ifdef CONFIG_SUSPEND
	for (state = PM_SUSPEND_MIN; state < PM_SUSPEND_MAX; state++) {
		const char *label = pm_states[state];

		if (label && len == strlen(label) && !strncmp(buf, label, len))
			return state;
	}
#endif

	return PM_SUSPEND_ON;
}

#define CONFIG_PM_STR_SUPPORT_EVENT
unsigned int pm_str_evnet_freeze_fail = 0;
#ifdef CONFIG_PM_STR_SUPPORT_EVENT

//[TCL2841-2581] adjust timeout value temporarily for TV030.
#ifdef CONFIG_CUSTOMER_TV030
#define STR_EVENT_SUSPEND_EVENT_READY_TIMEOUT_MS                300000
#else
#define STR_EVENT_SUSPEND_EVENT_READY_TIMEOUT_MS                10000
#endif

#define	STR_EVENT_SUSPEND_STR_MAIN_FLOW_WAIT_TIMEOUT_SEC	5
#define	STR_EVENT_INIT_STATE	0
#define	STR_EVENT_WAIT_SUSPEND_EVENT_STATE	1
#define	STR_EVENT_SUSPEND_EVENT_READY_STATE	2

static DEFINE_SEMAPHORE(str_main_flow_sema);
static DECLARE_WAIT_QUEUE_HEAD(pm_str_event_wait_queue);

static unsigned int pm_str_event_wait_flag = 1;
static unsigned int str_event_state =  STR_EVENT_INIT_STATE;
static unsigned int str_event_log =0;
/*When AP echo enable_force_wait at first, then system will enable force waiting flow 
   that means the STR suspend main flow will wait until STR_Worker issue next suspend_event_ready event.*/
static unsigned int pm_str_event_force_wait = 0;
#endif
void str_event_before_suspend_peration(suspend_state_t state)
{
#ifdef CONFIG_PM_STR_SUPPORT_EVENT
	unsigned long timeout_check = jiffies + HZ*STR_EVENT_SUSPEND_STR_MAIN_FLOW_WAIT_TIMEOUT_SEC;
	if(state == PM_SUSPEND_MEM)
	{
		unsigned int cnt = 1;
		//wait here for STR_Worker issue next wait_suspend_event
		while( (pm_str_event_force_wait == 1) && (str_event_state != STR_EVENT_WAIT_SUSPEND_EVENT_STATE))
		{
			str_event_log |= 0x1;
			if(time_after(jiffies, timeout_check))
			{
				pr_err("STR_NotifyAP : wait timeout (%d sec)\n", STR_EVENT_SUSPEND_STR_MAIN_FLOW_WAIT_TIMEOUT_SEC * cnt);
				timeout_check = jiffies + HZ*STR_EVENT_SUSPEND_STR_MAIN_FLOW_WAIT_TIMEOUT_SEC;
				cnt++;
			}
		}

		pm_str_event_wait_flag = 0;
		wake_up(&pm_str_event_wait_queue);

		//wait here for str event finish, but have timetout value
		if(down_timeout(&str_main_flow_sema, msecs_to_jiffies(STR_EVENT_SUSPEND_EVENT_READY_TIMEOUT_MS)))
		{
			str_event_log |= 0x2;
			str_event_state = STR_EVENT_INIT_STATE;
			pr_err("STR_NotifyAP : Timeout for suspend event ready (%d ms)\n", STR_EVENT_SUSPEND_EVENT_READY_TIMEOUT_MS);
		}
	}
#endif
}

void str_event_after_resume_operation(suspend_state_t state)
{
#ifdef CONFIG_PM_STR_SUPPORT_EVENT
	if(state == PM_SUSPEND_MEM)
	{
		up(&str_main_flow_sema);
		pm_str_event_wait_flag = 1;
	}
#endif
}

#ifdef CONFIG_PM_STR_SUPPORT_EVENT
static ssize_t pm_STR_event_show(struct kobject *kobj,
				      struct kobj_attribute *attr, char *buf)
{
	pr_notice("STR_NotifyAP : Support wait_suspend_event /suspend_event_ready\n");
	pr_notice("STR_NotifyAP : Current event state is (%d)\n", str_event_state);
	pr_notice("STR_NotifyAP : Current force wait is (%d), str_event_log(%d)\n", pm_str_event_force_wait, str_event_log);
	return 0;
}

/*
echo wait_suspend_event > /sys/power/pm_STR_event
echo suspend_event_ready > /sys/power/pm_STR_event
echo enable_force_wait > /sys/power/pm_STR_event
*/
static ssize_t pm_STR_event_store(struct kobject *kobj,
				       struct kobj_attribute *attr,
				       const char *buf, size_t n)
{
	int error = 0;
#ifdef CONFIG_PM_STR_SUPPORT_EVENT
	unsigned int input_state;
	char *p;
	int len;
	p = memchr(buf, '\n', n);
	len = p ? p - buf : n;

	if (len == 18 && !strncmp(buf, "wait_suspend_event", len))
		input_state = STR_EVENT_WAIT_SUSPEND_EVENT_STATE;
	else if(len == 19 && !strncmp(buf, "suspend_event_ready", len))
		input_state = STR_EVENT_SUSPEND_EVENT_READY_STATE;
	else if(len == 17 && !strncmp(buf, "enable_force_wait", len))
	{
		pm_str_event_force_wait = 1;
		pr_err("STR_NotifyAP :  set pm_str_event_force_wait on\n");
		return n;
	}
	else
	{
		str_event_log |= 0x4;
		pr_err("STR_NotifyAP : Not support event(%d)\n", str_event_state);
		error = -EINVAL;
		return error;
	}

	// for state init -> wait_suspend_stae or suspend_event_ready state -> wait_suspend_stae
	if(((str_event_state == STR_EVENT_INIT_STATE) && (input_state == STR_EVENT_WAIT_SUSPEND_EVENT_STATE)))
		//||( (str_event_state == STR_EVENT_SUSPEND_EVENT_READY_STATE) && (input_state == STR_EVENT_WAIT_SUSPEND_EVENT_STATE)))
	{
		if(down_trylock(&str_main_flow_sema) != 0)
		{
			if(pm_str_evnet_freeze_fail)
				while(1); //because freeze fail, wait here for emcu_on on active for enter standby mode
			else	//means str main flow already enter suspend flow, AP should issue this before already run str flow
				panic("STR_NotifyAP : pm_STR_event_store state mismatch(%d/%d/%d)\n", input_state, pm_str_event_force_wait, str_event_log);
		}
	
		str_event_state = STR_EVENT_WAIT_SUSPEND_EVENT_STATE; //means STR_Worker gain sema
		wait_event(pm_str_event_wait_queue, (pm_str_event_wait_flag == 0));//wait here for str main flow start
		pm_str_event_wait_flag = 1;
	}
	else if((str_event_state == STR_EVENT_WAIT_SUSPEND_EVENT_STATE) && (input_state == STR_EVENT_SUSPEND_EVENT_READY_STATE))
	{

		up(&str_main_flow_sema); //wakeup str main flow
		wait_event_freezable(pm_str_event_wait_queue, (pm_str_event_wait_flag == 0));//wait here for after resume
		str_event_state = 	STR_EVENT_INIT_STATE;
	}
	else
	{
		str_event_log |= 0x8;
		pr_err("STR_NotifyAP : Current state is %d, and input state is %d\n", str_event_state, input_state);
		error = -EINVAL;
	}
#endif
	return error;
}
power_attr(pm_STR_event);
#endif


static ssize_t state_store(struct kobject *kobj, struct kobj_attribute *attr,
			   const char *buf, size_t n)
{
	suspend_state_t state;
	int error;

#ifdef CONFIG_LG_SNAPSHOT_DENY_STATE
	return -EACCES;
#endif

#ifdef CONFIG_PM_DEBUG
        if(pm_rhal_test_enabled)
                return -EINVAL;
#endif       

#ifndef CONFIG_CUSTOMER_TV030
	error = pm_autosleep_lock();
	if (error)
		return error;

	if (pm_autosleep_state() > PM_SUSPEND_ON) {
		error = -EBUSY;
		goto out;
	}
#endif

	state = decode_state(buf, n);
	if (state < PM_SUSPEND_MAX)
	{

	/* MAC6RTANDN-260 when issue STR DC off/on with quickly push RC power key (within 3sec),
	the user lazy resume procedure still keep on, cause next STR suspend flow will have EBUSY return,
	then str_event_before_suspend_peration enter twice.
	The second time enter will casue STR_Worker relase from STR_EVENT_SUSPEND_EVENT_READY_STATE,
	then STR main flow gain str_main_flow_sema but later STR_Worker down_trylock fail results in flow mismatch panic.
	So for this case, make sure user resume done before enter str_event_before_suspend_peration. */
		if(mutex_is_locked(&pm_mutex))
		{
			error = -EBUSY;
			goto out;
		}

		str_event_before_suspend_peration(state);
		error = pm_suspend(state);
	}
	else if (state == PM_SUSPEND_MAX)
		error = hibernate();
	else
		error = -EINVAL;

 out:
 #ifndef CONFIG_CUSTOMER_TV030
	pm_autosleep_unlock();
 #endif
	return error ? error : n;
}

power_attr(state);

#ifdef CONFIG_PM_SLEEP
/*
 * The 'wakeup_count' attribute, along with the functions defined in
 * drivers/base/power/wakeup.c, provides a means by which wakeup events can be
 * handled in a non-racy way.
 *
 * If a wakeup event occurs when the system is in a sleep state, it simply is
 * woken up.  In turn, if an event that would wake the system up from a sleep
 * state occurs when it is undergoing a transition to that sleep state, the
 * transition should be aborted.  Moreover, if such an event occurs when the
 * system is in the working state, an attempt to start a transition to the
 * given sleep state should fail during certain period after the detection of
 * the event.  Using the 'state' attribute alone is not sufficient to satisfy
 * these requirements, because a wakeup event may occur exactly when 'state'
 * is being written to and may be delivered to user space right before it is
 * frozen, so the event will remain only partially processed until the system is
 * woken up by another event.  In particular, it won't cause the transition to
 * a sleep state to be aborted.
 *
 * This difficulty may be overcome if user space uses 'wakeup_count' before
 * writing to 'state'.  It first should read from 'wakeup_count' and store
 * the read value.  Then, after carrying out its own preparations for the system
 * transition to a sleep state, it should write the stored value to
 * 'wakeup_count'.  If that fails, at least one wakeup event has occurred since
 * 'wakeup_count' was read and 'state' should not be written to.  Otherwise, it
 * is allowed to write to 'state', but the transition will be aborted if there
 * are any wakeup events detected after 'wakeup_count' was written to.
 */

static ssize_t wakeup_count_show(struct kobject *kobj,
				struct kobj_attribute *attr,
				char *buf)
{
	unsigned int val;

	return pm_get_wakeup_count(&val, true) ?
		sprintf(buf, "%u\n", val) : -EINTR;
}

static ssize_t wakeup_count_store(struct kobject *kobj,
				struct kobj_attribute *attr,
				const char *buf, size_t n)
{
	unsigned int val;
	int error;

	error = pm_autosleep_lock();
	if (error)
		return error;

	if (pm_autosleep_state() > PM_SUSPEND_ON) {
		error = -EBUSY;
		goto out;
	}


/**
* ANDROIDTV-933, skip process wakeup event during suspend flow.
* For android P case, skip wakeup event on pm_wakeup_pending instead of wakeup_count_store.
* Because android P will check wakeup_count_store return value.
* So original method (always return 0 on wakeup_count_store) can't be used.
*/
#if !defined(CONFIG_ANDROID_VERSION) || (CONFIG_ANDROID_VERSION < 9)
	error = 0;
	goto out;
#endif

	error = -EINVAL;
	if (sscanf(buf, "%u", &val) == 1) {
		if (pm_save_wakeup_count(val))
			error = n;
		else
			pm_print_active_wakeup_sources();
	}

 out:
	pm_autosleep_unlock();
	return error;
}

power_attr(wakeup_count);

#ifdef CONFIG_PM_AUTOSLEEP
static ssize_t autosleep_show(struct kobject *kobj,
			      struct kobj_attribute *attr,
			      char *buf)
{
	suspend_state_t state = pm_autosleep_state();

	if (state == PM_SUSPEND_ON)
		return sprintf(buf, "off\n");

#ifdef CONFIG_SUSPEND
	if (state < PM_SUSPEND_MAX)
		return sprintf(buf, "%s\n", pm_states[state] ?
					pm_states[state] : "error");
#endif
#ifdef CONFIG_HIBERNATION
	return sprintf(buf, "disk\n");
#else
	return sprintf(buf, "error");
#endif
}

static ssize_t autosleep_store(struct kobject *kobj,
			       struct kobj_attribute *attr,
			       const char *buf, size_t n)
{
	suspend_state_t state = decode_state(buf, n);
	int error;

	if (state == PM_SUSPEND_ON
	    && strcmp(buf, "off") && strcmp(buf, "off\n"))
		return -EINVAL;

	error = pm_autosleep_set_state(state);
	return error ? error : n;
}

power_attr(autosleep);
#endif /* CONFIG_PM_AUTOSLEEP */

#ifdef CONFIG_PM_WAKELOCKS
static ssize_t wake_lock_show(struct kobject *kobj,
			      struct kobj_attribute *attr,
			      char *buf)
{
	return pm_show_wakelocks(buf, true);
}

static ssize_t wake_lock_store(struct kobject *kobj,
			       struct kobj_attribute *attr,
			       const char *buf, size_t n)
{
	int error = pm_wake_lock(buf);
	return error ? error : n;
}

power_attr(wake_lock);

static ssize_t wake_unlock_show(struct kobject *kobj,
				struct kobj_attribute *attr,
				char *buf)
{
	return pm_show_wakelocks(buf, false);
}

static ssize_t wake_unlock_store(struct kobject *kobj,
				 struct kobj_attribute *attr,
				 const char *buf, size_t n)
{
	int error = pm_wake_unlock(buf);
	return error ? error : n;
}

power_attr(wake_unlock);

#endif /* CONFIG_PM_WAKELOCKS */
#endif /* CONFIG_PM_SLEEP */

#ifdef CONFIG_PM_TRACE
int pm_trace_enabled;

static ssize_t pm_trace_show(struct kobject *kobj, struct kobj_attribute *attr,
			     char *buf)
{
	return sprintf(buf, "%d\n", pm_trace_enabled);
}

static ssize_t
pm_trace_store(struct kobject *kobj, struct kobj_attribute *attr,
	       const char *buf, size_t n)
{
	int val;

	if (sscanf(buf, "%d", &val) == 1) {
		pm_trace_enabled = !!val;
		if (pm_trace_enabled) {
			pr_warn("PM: Enabling pm_trace changes system date and time during resume.\n"
				"PM: Correct system time has to be restored manually after resume.\n");
		}
		return n;
	}
	return -EINVAL;
}

power_attr(pm_trace);

static ssize_t pm_trace_dev_match_show(struct kobject *kobj,
				       struct kobj_attribute *attr,
				       char *buf)
{
	return show_trace_dev_match(buf, PAGE_SIZE);
}

static ssize_t
pm_trace_dev_match_store(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t n)
{
	return -EINVAL;
}

power_attr(pm_trace_dev_match);

#endif /* CONFIG_PM_TRACE */

#ifdef CONFIG_FREEZER
static ssize_t pm_freeze_timeout_show(struct kobject *kobj,
				      struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%u\n", freeze_timeout_msecs);
}

static ssize_t pm_freeze_timeout_store(struct kobject *kobj,
				       struct kobj_attribute *attr,
				       const char *buf, size_t n)
{
	unsigned long val;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	freeze_timeout_msecs = val;
	return n;
}

power_attr(pm_freeze_timeout);

#endif	/* CONFIG_FREEZER*/

static struct attribute * g[] = {
	&state_attr.attr,
#ifdef CONFIG_LG_SNAPSHOT_BOOT
	&mode_attr.attr,
#endif
#ifdef CONFIG_PM_TRACE
	&pm_trace_attr.attr,
	&pm_trace_dev_match_attr.attr,
#endif
#ifdef CONFIG_PM_SLEEP
	&pm_async_attr.attr,
	&pm_userresume_attr.attr,
	&pm_userresume_enable_attr.attr,
	&wakeup_count_attr.attr,
#ifdef CONFIG_PM_AUTOSLEEP
	&autosleep_attr.attr,
#endif
#ifdef CONFIG_PM_WAKELOCKS
	&wake_lock_attr.attr,
	&wake_unlock_attr.attr,
#endif
#ifdef CONFIG_PM_DEBUG
	&pm_test_attr.attr,
	&pm_rhal_test_attr.attr,
#endif
#ifdef CONFIG_PM_SLEEP_DEBUG
	&pm_print_times_attr.attr,
	&pm_wakeup_irq_attr.attr,
#endif
#endif
#ifdef CONFIG_FREEZER
	&pm_freeze_timeout_attr.attr,
#endif
#ifdef CONFIG_PM_STR_SUPPORT_EVENT
	&pm_STR_event_attr.attr,
#endif
	NULL,
};

static struct attribute_group attr_group = {
	.attrs = g,
};

struct workqueue_struct *pm_wq;
EXPORT_SYMBOL_GPL(pm_wq);

static int __init pm_start_workqueue(void)
{
	pm_wq = alloc_workqueue("pm", WQ_FREEZABLE, 0);

	return pm_wq ? 0 : -ENOMEM;
}

static int __init pm_init(void)
{
	int error = pm_start_workqueue();
	if (error)
		return error;
	hibernate_image_size_init();
	hibernate_reserved_size_init();
	power_kobj = kobject_create_and_add("power", NULL);
	if (!power_kobj)
		return -ENOMEM;
	error = sysfs_create_group(power_kobj, &attr_group);
	if (error)
		return error;
	pm_print_times_init();
	return pm_autosleep_init();
}

core_initcall_sync(pm_init);
