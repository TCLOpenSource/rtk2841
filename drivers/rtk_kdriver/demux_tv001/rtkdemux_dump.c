#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/dma-mapping.h>
#include <linux/platform_device.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/pageremap.h>
#include "rtkdemux.h"

#include <linux/file.h>
#include <linux/types.h>
#include <linux/unistd.h>
#include <asm/uaccess.h>

/* use IS_ERR(x) to check the (struct file *) */
void DUMP_CreateFile(const char *filename, struct file **handle)
{
	*handle = filp_open(filename, O_RDWR | O_CREAT | O_TRUNC, 0777);
}

void DUMP_CloseFile(struct file *handle)
{
	filp_close(handle, NULL);
}

int DUMP_WriteFile(struct file *handle, char *buffer, unsigned int size, loff_t *pOffset)
{
	int ret = 0;

	if (handle && pOffset) {
		mm_segment_t fs;
		fs = get_fs();
		set_fs(get_ds());    /* set to KERNEL_DS */
		vfs_write(handle, buffer, size, pOffset);
		set_fs(fs);
	}

	return ret;
}

