#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>
#include <linux/jiffies.h>
#include <linux/delay.h>
#include <asm/io.h>

#include <linux/pageremap.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include "rtk_scd_debug.h"

struct proc_dir_entry * smc_proc_dir = NULL;
struct proc_dir_entry * smc_proc_entry = NULL;
unsigned char smc_log_onoff=1;
unsigned char apdu_onoff=0;

static const char* cmd_str[SMC_PROC_COUNT] = {
	SMC_PROC_PARAM_DEBUG_ON,
       SMC_PROC_PARAM_DEBUG_OFF,
       SMC_PROC_PARAM_ON_APDU,
       SMC_PROC_PARAM_OFF_APDU,

};

static int smc_proc_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
	unsigned char str[128];
	unsigned int i;
	if(buf == NULL)
	{
		SC_WARNING("buf=%p\n",buf);
		return -EFAULT;
	}

	if (count > 128) /* procfs write and read has PAGE_SIZE limit */
		count = 128;

	if (copy_from_user(str, buf, count))
	{
		SC_ERR("copy_from_user failed! (buf=%p, count=%u)\n",buf,count);
		return -EFAULT;
	}

	str[count-1] = '\0';
       for(i=0;i<SMC_PROC_COUNT;i++)
	{
		if (strncmp(str, cmd_str[i],strlen(cmd_str[i]))==0)
			break;
	}
       if(i>=SMC_PROC_COUNT)
   	{
	     SC_ERR( "[SMC] Cannot find your command: \"%s\"\n", str);
		 return -EINVAL;
	 }
	if(i==SMC_PROC_DEBUG_ON)
	{
	    smc_log_onoff=1;
           SC_PRINT_AWAYS( "[SMC] smart card log on!\n ");
	}
	else if(i==SMC_PROC_DEBUG_OFF)
	{
	    smc_log_onoff=0;
           SC_PRINT_AWAYS( "[SMC] smart card log off!\n ");
	}
	else if(i==SMC_PROC_ON_APDU)
	{
           apdu_onoff=1;
	    SC_PRINT_AWAYS( "[SMC] turn on print rtx!\n ");	   
	}
	else if(i==SMC_PROC_OFF_APDU)
	{
           apdu_onoff=0;
           SC_PRINT_AWAYS( "[SMC] turn off print rtx!\n ");
	  
	}
     return 1;
}

static int smc_proc_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
	char *str = "SMC kernel driver debug message\n";
	int len = strlen(str);
	if(copy_to_user(buf, str, len))
	{
		SC_ERR("Copy proc data to user space failed\n");
		return 0;
	}

	if (*ppos == 0)
		*ppos += len;
	else
		len = 0;
	return len;
}

static const struct file_operations smc_proc_fops =
{
	.owner = THIS_MODULE,
	.write  = smc_proc_write,
	.read  = smc_proc_read,
};

unsigned int create_smc_controller(void)
{
		if((smc_proc_dir == NULL)&&(smc_proc_entry == NULL))
		{
			smc_proc_dir = proc_mkdir(SMC_PROC_DIR , NULL);

			if (smc_proc_dir==NULL)
			{
				SC_ERR("create rhal_smc dir proc entry (%s) failed\n",SMC_PROC_DIR);
			}
			else
			{
				smc_proc_entry = proc_create(SMC_PROC_ENTRY, 0666, smc_proc_dir, &smc_proc_fops);
				if(smc_proc_entry==NULL)
				{
					SC_ERR("failed to get proc entry for %s/%s \n",SMC_PROC_DIR,SMC_PROC_ENTRY);
				}
			}
		}
		return 0;
}

EXPORT_SYMBOL(create_smc_controller);

