#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <rtk_kdriver/rtk_semaphore.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/export.h>
#include <linux/debugfs.h>
#include <linux/sysfs.h>

#define rtksemaphore_attr(_name) \
static struct kobj_attribute _name##_attr = {   \
        .attr   = {                             \
                .name = __stringify(_name),     \
                .mode = 0644,                   \
        },                                      \
        .show   = _name##_show,                 \
        .store  = _name##_store,                \
}

struct kobject *sema_kobj;
#define MTH 9

static struct task_struct *brook_tsk[MTH];
static int kbrook(void *arg);
int data=0;
int retry = 0;
struct timer_list sema_timer;

#define isnumber(c)      (c>=0x30 && c<=0x39)
#define isalphabet(c)    (c>=0x41 && c<=0x5A) || (c>=0x61 && c<=0x7A)
#define isalnum(c)       (isnumber(c) || isalphabet(c))

char* __find_next_str(char* str)
{
    char* end = str + strlen(str);

    while(str < end) {
        if (isalnum(*str)) // is alphabet or number
            return str;
        str++;
    }

    return NULL;
}


static int parse_sema_test_cmd(int size, int lock, const char * buffer)
{
	char* cmd = __find_next_str((char*)buffer + size);
	if (cmd == NULL) {
        	RTK_SEM_ERR("set rtk_sema failed, unknown command - %s\n", cmd);
        	return -1;
    	}
	if ( strncmp(cmd, "sw", 2 ) == 0)
	{
		if (lock == 1)
			rtd_swsem_lock(SEMA_HW_SEM_0_SCPU_2);
		else if ( lock == 2 )
			return rtd_swsem_trylock(SEMA_HW_SEM_0_SCPU_2);
		else
			rtd_swsem_unlock(SEMA_HW_SEM_0_SCPU_2);
		return 2;
	}
	else if ( strncmp(cmd, "hw", 2 ) == 0)
	{
		if (lock == 1)
			rtd_hwsem_lock(SEMA_HW_SEM_0_SCPU_2);
		else if ( lock == 2 )
                        return rtd_hwsem_trylock(SEMA_HW_SEM_0_SCPU_2);
                else
                        rtd_hwsem_unlock(SEMA_HW_SEM_0_SCPU_2);
		return 1;
	}
}

static int kbrook(void *arg)
{
    unsigned int timeout;
    int d = (int) arg;
    int retry=0;

	int ht;

    for(;;) {
        if (kthread_should_stop()) break;

        while ( (ht = rtd_swsem_trylock( SEMA_HW_SEM_0_SCPU_2 | d<<4)) != 1 ) {
                udelay(10);
		retry++;
        }

        data++;
        if ( retry > 50 )
                printk("%s(): thread%d [%d]   UUID ---[%x] RETRY ---[%d]\n", __FUNCTION__, d, data, SEMA_HW_SEM_0_SCPU_2 | d<<4, retry);
        retry = 0;
        udelay(10);
        rtd_swsem_unlock( SEMA_HW_SEM_0_SCPU_2 | d<<4);

    }
    printk("break\n");
    do_exit(0);
    return 0;
}

static int timer_do(unsigned long data)
{
	struct task_struct *p = (struct task_struct *)data;
	RTK_SEM_INFO("Timer for lock semaphore\n");
	send_sig(SIGINT, p, 0);
	del_timer(&sema_timer);
}

static ssize_t semaphore_test_show(struct kobject *kobj, struct kobj_attribute *attr,
                          char *buf)
{

}

static ssize_t semaphore_test_store(struct kobject *kobj, struct kobj_attribute *attr,
                           const char *buf, size_t n)
{
	int mode = 0,i;
	if ( !strncmp(buf, "lock", 4) )
        {
                RTK_SEM_INFO("lock semaphore\n");
		if ( (mode = parse_sema_test_cmd(4, 1, buf)) < 0)
			goto END_TEST;
		dump_sem_data();
        }
        else if ( !strncmp(buf, "unlock", 6) )
        {
                RTK_SEM_INFO("unlock semaphore\n");
                if ( (mode = parse_sema_test_cmd(6, 0, buf)) < 0)
                        goto END_TEST;
		dump_sem_data();
        }
	else if ( !strncmp(buf, "trylock", 7) )
        {
                RTK_SEM_INFO("trylock semaphore\n");
                if ( (mode = parse_sema_test_cmd(7, 2, buf)) < 0)
                        goto END_TEST;
		RTK_SEM_INFO("Trylock semaphore [%d]\n", mode);
                dump_sem_data();
        }
	else if ( !strncmp(buf, "thread", 6) )
	{
		for( i=0;i<MTH;i++ )    {
			RTK_SEM_INFO("Create KTHREAD %d\n", i);
			brook_tsk[i] = kthread_create(kbrook, i, "brook");
			if (IS_ERR(brook_tsk[i])) {
				PTR_ERR(brook_tsk[i]);
				goto END_TEST;
			}
                }
		for( i=0;i<MTH;i++ )    {
			wake_up_process(brook_tsk[i]);
		}
	}
	else if ( !strncmp(buf, "verify", 6) )
	{
		int error = 0;
		init_timer(&sema_timer);
		sema_timer.function = timer_do;

                // basic test
                while ( (i = rtd_swsem_trylock(SEMA_HW_SEM_0_SCPU_2)) != 1)
                {
                        if ( signal_pending(current) )
                        {
                                error++;
                                break;
                        }
                }
                rtd_swsem_unlock(SEMA_HW_SEM_0_SCPU_2);

		rtd_swsem_lock(SEMA_HW_SEM_0_SCPU_2);
		rtd_swsem_unlock(SEMA_HW_SEM_0_SCPU_2);

		if ( error )
		{
			RTK_SEM_INFO("TEST semaphore Error\n");
			goto END_TEST;
		}
		// fail case 1
		sema_timer.data = (unsigned long) current;
		sema_timer.expires = jiffies + HZ*8;
		add_timer(&sema_timer);
		rtd_swsem_lock(SEMA_HW_SEM_0_SCPU_2);
		rtd_swsem_lock(SEMA_HW_SEM_0_SCPU_2);
		rtd_swsem_unlock(SEMA_HW_SEM_0_SCPU_2);
		// fail case 2
		rtd_swsem_unlock(SEMA_HW_SEM_0_SCPU_2);
		rtd_swsem_unlock(SEMA_HW_SEM_0_SCPU_2);

	}

END_TEST:
	RTK_SEM_INFO("END TEST semaphore\n");
	return n;
}
rtksemaphore_attr(semaphore_test);

static struct attribute * gg[] = {
        &semaphore_test_attr.attr,
        NULL,
};

static struct attribute_group sema_group = {
        .attrs = gg,
};

static int __init rtk_semaphore_init(void)
{
	printk(KERN_INFO "Hello, rtk_semaphore\n");

	int error;
        sema_kobj = kobject_create_and_add("rtksemaphore", NULL);
        if (!sema_kobj)
                return -ENOMEM;
        error = sysfs_create_group(sema_kobj, &sema_group);
        if (error)
                return error;

	return 0;
}

static void __exit rtk_semaphore_exit(void)
{
	printk(KERN_INFO "Goodbye, rtk_semaphore\n");
}

module_init(rtk_semaphore_init);
module_exit(rtk_semaphore_exit);
