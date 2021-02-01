#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/syscalls.h> 
#include <linux/file.h> 
#include <linux/fs.h>
#include <linux/fcntl.h> 
#include <asm/uaccess.h> 
#include <linux/time.h>

#include "audio_hw_log.h"

#define ALOG_CHK_FILE_DEF		("/usr/local/etc/audio_lib.txt")
#define ALOG_CHK_FILE_WEBOS		("/home/audio_lib.txt")

static bool is_alog_chk_init = false;
static bool is_alog_chk_enable = false;

static int is_file_exist(char *filename)
{
	int fd = -1;
	mm_segment_t old_fs;

	if (!filename)
		return 0;

	old_fs = get_fs();
	set_fs(KERNEL_DS);

	fd = sys_open(filename, O_RDONLY, 0);
	if (fd >= 0)
		sys_close(fd);

	set_fs(old_fs);

	return (fd >= 0 ? 1 : 0);
}

bool alog_chk_enable(void)
{
	if (!is_alog_chk_init) {
		is_alog_chk_enable = false;
		if (is_file_exist(ALOG_CHK_FILE_DEF) ||
		    is_file_exist(ALOG_CHK_FILE_WEBOS)) {
			is_alog_chk_enable = true;
		}
		is_alog_chk_init = true;
	}
	return is_alog_chk_enable;
}

struct timeval alog_chk_gettimeofday(void)
{
	struct timeval t;

	do_gettimeofday(&t);

	return t;
}
