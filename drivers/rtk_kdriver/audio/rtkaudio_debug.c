/*
 * Realtek Audio driver debug utility
 *
 * Copyright (c) 2014 Ivan <ivanlee@realtek.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License.
 *
 * History:
 *
 * 2014-09-23:  Ivan: first version
 */

#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
#include <linux/string.h>

#include <rtk_kdriver/rtkaudio.h>
#include <rtk_kdriver/RPCDriver.h>
#include <linux/pageremap.h>
#include <linux/kthread.h>
#include <linux/err.h>
#include <linux/delay.h>
#include <linux/time.h>

#include <rtk_kdriver/rtkaudio_debug.h>
#include <linux/freezer.h>

//#define PRINT_DUMP_SIZE_AND_TIME

#ifdef PRINT_DUMP_SIZE_AND_TIME
#include <asm/div64.h>
#endif

#define MAX_DUMP_SIZE (512*1024)
#define DMESG_PRINT_MAX (1024)
#define DUMP_FILE_MAX_SIZE (1024*1024)
extern int dump_size_scale;
extern int pr_to_dmesg_en;

#ifdef PRINT_DUMP_SIZE_AND_TIME
unsigned long long rtkaudio_getpts(void)
{
	unsigned long long ret;
	unsigned int ptrlo, ptrhi;

	ptrlo = (unsigned int) rtd_inl(0xB801B690);
	ptrhi = (unsigned int) rtd_inl(0xB801B694);

	ret = ptrlo;
	ret = ret|(((unsigned long long)ptrhi) << 32);

	return ret;
}
#endif

/* Copy from vdec.h for dump audio */
static struct file* file_open(const char* path, int flags, int rights)
{
	struct file* filp = NULL;
	mm_segment_t oldfs;
	int err = 0;

	oldfs = get_fs();
	set_fs(get_ds());

	filp = filp_open(path, flags, rights);
	set_fs(oldfs);

	if(IS_ERR(filp)) {
		err = PTR_ERR(filp);
		return NULL;
	}

	return filp;
}

static void file_close(struct file* file)
{
	filp_close(file, NULL);
}

static int file_write(struct file *file, unsigned long long offset,
	unsigned char *data, uint size)
{

             return size;

	mm_segment_t oldfs;
	int ret;

	oldfs = get_fs();
	set_fs(get_ds());
	ret = vfs_write(file, data, size, &offset);
	set_fs(oldfs);

	return ret;
}

#if 0 /* currently not used */
static int file_read(struct file *file, unsigned long long offset,
	unsigned char *data, uint size)
{
	mm_segment_t oldfs;
	int ret;

	oldfs = get_fs();
	set_fs(get_ds());

	ret = vfs_read(file, data, size, &offset);
	set_fs(oldfs);

	return ret;
}

static int file_sync(struct file* file)
{
	vfs_fsync(file, 0);
	return 0;
}
#endif
/* end of audio dump */

ulong g_p_debug_mem; /* uncached address */
ulong g_p_dump_mem;  /* uncached address */
struct file *f_dump;
ulong g_audio_dump_size = 512*1024;
ulong g_debug_phyaddr;/* physical address */
ulong g_dump_phyaddr; /* physical address */
ulong g_debug_viraddr;/* virtual address */
ulong g_dump_viraddr; /* virtual address */

static struct task_struct *rtkaudio_debug_tsk;
static int rtkaudio_debug_thread(void* arg);
static unsigned long long f_offset;

struct RPC_DBG_MEMORY {
	long audio_fw_version;
};

struct DBG_BUF_HEADER {
	ulong magic;
	ulong size;
	ulong rd;
	ulong wr;
};

static int print_to_dmesg(unsigned char *ptr, uint count)
{
	unsigned char *dmgp, *temp_ptr;
	char *tok;
	uint print_count, write_size, length;

	write_size = 0;
	dmgp = kmalloc(DMESG_PRINT_MAX, GFP_KERNEL);

	if (dmgp == NULL)
		return -1;

	while (count > 0) {
		memset(dmgp, '\0', DMESG_PRINT_MAX);
		if (count > DMESG_PRINT_MAX - 4) {
			memcpy(dmgp, ptr, DMESG_PRINT_MAX - 4);
			temp_ptr = dmgp;

			tok = strsep((char **)&temp_ptr, "\n");

			while (tok != NULL) {
				print_count = strlen(tok);
				tok = strsep((char **)&temp_ptr, "\n");
			}


			if (print_count == (DMESG_PRINT_MAX - 4)) {
				memset(dmgp, '\0', DMESG_PRINT_MAX);
				memcpy(dmgp, ptr, DMESG_PRINT_MAX - 4 - print_count);

				temp_ptr = dmgp;

				tok = strsep((char **)&temp_ptr, "\n");

				while (tok != NULL) {
					length = strlen(tok);
					if ((pr_to_dmesg_en != 0) && (length != 0)) {
						pr_info("%s\n", tok);
					}
					tok = strsep((char **)&temp_ptr, "\n");
				}

				write_size += DMESG_PRINT_MAX - 4;
				count = count - (DMESG_PRINT_MAX - 4);
				ptr = ptr + (DMESG_PRINT_MAX - 4);
			} else {
				memset(dmgp, '\0', DMESG_PRINT_MAX);
				memcpy(dmgp, ptr, DMESG_PRINT_MAX - 4 - print_count);

				temp_ptr = dmgp;

				tok = strsep((char **)&temp_ptr, "\n");

				while (tok != NULL) {
					length = strlen(tok);
					if ((pr_to_dmesg_en != 0) && (length != 0)) {
						pr_info("%s\n", tok);
					}
					tok = strsep((char **)&temp_ptr, "\n");
				}

				write_size += DMESG_PRINT_MAX - 4 - print_count;
				count = count - (DMESG_PRINT_MAX - 4 - print_count);
				ptr = ptr + (DMESG_PRINT_MAX - 4 - print_count);
			}
		} else {
			memcpy(dmgp, ptr, count);
			temp_ptr = dmgp;

			tok = strsep((char **)&temp_ptr, "\n");

			while (tok != NULL) {
				print_count = strlen(tok);
				tok = strsep((char **)&temp_ptr, "\n");
			}

			memset(dmgp, '\0', DMESG_PRINT_MAX);
			memcpy(dmgp, ptr, count - print_count);

			temp_ptr = dmgp;

			tok = strsep((char **)&temp_ptr, "\n");

			while (tok != NULL) {
				length = strlen(tok);
				if ((pr_to_dmesg_en != 0) && (length != 0)) {
					pr_info("%s\n", tok);
				}
				tok = strsep((char **)&temp_ptr, "\n");
			}

			write_size += count - print_count;
			count -= print_count;
			ptr = ptr + print_count;
			break;
		}
	}

	kfree(dmgp);
	return write_size;
}

static void rtkaudio_file_process(void)
{
	uint magic, size, wr, rd;
	unsigned char *wp, *rp, *base, *limit;
	struct DBG_BUF_HEADER *header;
	int ret;

#ifdef PRINT_DUMP_SIZE_AND_TIME
	unsigned long long pre_90K, cur_90K, diff_time;
#endif

	header = (struct DBG_BUF_HEADER *) g_p_dump_mem;
	magic = ntohl(header->magic);
	size  = ntohl(header->size);
	rd = ntohl(header->rd);
	wr = ntohl(header->wr);

	/* make virtual address */
	wp = (unsigned char *)(g_p_dump_mem + wr - g_dump_phyaddr);
	/* make virtual address */
	rp = (unsigned char *)(g_p_dump_mem + rd - g_dump_phyaddr);

	base = (unsigned char *)(g_p_dump_mem + sizeof(struct DBG_BUF_HEADER));
	size -= sizeof(struct DBG_BUF_HEADER);
	limit = base + size;
	if (wp < rp)
		wp = wp + size;

	if (wp > rp) {
		if (wp > limit) {
			if ((limit - rp) > MAX_DUMP_SIZE) {
				ret = print_to_dmesg(rp, MAX_DUMP_SIZE);

				if (ret < 0)
					return ;

#ifdef PRINT_DUMP_SIZE_AND_TIME
				pre_90K = rtkaudio_getpts();
#endif
				file_write(f_dump, f_offset, rp, ret);
				f_offset += ret;

#ifdef PRINT_DUMP_SIZE_AND_TIME
				cur_90K = rtkaudio_getpts();
				diff_time = (cur_90K - pre_90K) * 100;
				do_div(diff_time, 9);
				pr_info("[rtkaudio] diff_time %08lld us, size %08d\n",
					diff_time, ret);
#endif

				header->rd = htonl(rd + ret);
			} else {
				ret = print_to_dmesg(rp, limit - rp);

				if (ret < 0)
					return ;

#ifdef PRINT_DUMP_SIZE_AND_TIME
				pre_90K = rtkaudio_getpts();
#endif

				file_write(f_dump, f_offset, rp, limit - rp);
				f_offset += limit - rp;

#ifdef PRINT_DUMP_SIZE_AND_TIME
				cur_90K = rtkaudio_getpts();
				diff_time = (cur_90K - pre_90K) * 100;
				do_div(diff_time, 9);
				pr_info("[rtkaudio] diff_time %08lld us, size %08d\n",
					diff_time, ret);
#endif

				if ((wp - limit) > MAX_DUMP_SIZE) {
					ret = print_to_dmesg(base, MAX_DUMP_SIZE);

					if (ret < 0) {
						header->rd = htonl(g_dump_phyaddr + sizeof(struct DBG_BUF_HEADER));
						return ;
					}

#ifdef PRINT_DUMP_SIZE_AND_TIME
					pre_90K = rtkaudio_getpts();
#endif

					file_write(f_dump, f_offset, base, ret);
					f_offset += ret;

#ifdef PRINT_DUMP_SIZE_AND_TIME
					cur_90K = rtkaudio_getpts();
					diff_time = (cur_90K - pre_90K) * 100;
					do_div(diff_time, 9);
					pr_info("[rtkaudio] diff_time %08lld us, size %08d\n",
						diff_time, ret);
#endif

					header->rd = htonl(g_dump_phyaddr + sizeof(struct DBG_BUF_HEADER) + ret);
				} else {
					ret = print_to_dmesg(base, wp - limit);

					if (ret < 0) {
						header->rd = htonl(g_dump_phyaddr + sizeof(struct DBG_BUF_HEADER));
						return ;
					}

#ifdef PRINT_DUMP_SIZE_AND_TIME
					pre_90K = rtkaudio_getpts();
#endif

					file_write(f_dump, f_offset, base, ret);
					f_offset += ret;

#ifdef PRINT_DUMP_SIZE_AND_TIME
					cur_90K = rtkaudio_getpts();
					diff_time = (cur_90K - pre_90K) * 100;
					do_div(diff_time, 9);
					pr_info("[rtkaudio] diff_time %08lld us, size %08d\n",
						diff_time, ret);
#endif

					header->rd = htonl(g_dump_phyaddr + sizeof(struct DBG_BUF_HEADER) + ret);
				}
			}
		} else {
			if ((wp - rp) > MAX_DUMP_SIZE) {
				ret = print_to_dmesg(rp, MAX_DUMP_SIZE);

				if (ret < 0)
					return ;

#ifdef PRINT_DUMP_SIZE_AND_TIME
				pre_90K = rtkaudio_getpts();
#endif

				file_write(f_dump, f_offset, rp, ret);
				f_offset += ret;

#ifdef PRINT_DUMP_SIZE_AND_TIME
				cur_90K = rtkaudio_getpts();
				diff_time = (cur_90K - pre_90K) * 100;
				do_div(diff_time, 9);
				pr_info("[rtkaudio] diff_time %08lld us, size %08d\n",
					diff_time, ret);
#endif

				header->rd = htonl(rd + ret);
			} else {
				ret = print_to_dmesg(rp, wp - rp);

				if (ret < 0)
					return ;

#ifdef PRINT_DUMP_SIZE_AND_TIME
				pre_90K = rtkaudio_getpts();
#endif

				file_write(f_dump, f_offset, rp, ret);
				f_offset += ret;

#ifdef PRINT_DUMP_SIZE_AND_TIME
				cur_90K = rtkaudio_getpts();
				diff_time = (cur_90K - pre_90K) * 100;
				do_div(diff_time, 9);
				pr_info("[rtkaudio] diff_time %08lld us, size %08d\n",
					diff_time, ret);
#endif

				header->rd = htonl(rd + ret);
			}
		}
	}
}

static int rtkaudio_debug_thread(void *arg)
{
	for (;;) {
		set_freezable();

		if (kthread_should_stop())
			break;

		if (f_dump != 0)
			rtkaudio_file_process();

		if (dump_size_scale != 0) {
			if (f_offset > (DUMP_FILE_MAX_SIZE * dump_size_scale)) {
				f_offset = 0;
			}
		}

		msleep(50); /* sleep 50 ms */
	}

	pr_debug("break\n");

	return 0;
}

int rtkaudio_dump_enable(uint db_command)
{
	ulong ret = S_OK;

	if (f_dump) {
		pr_debug("[%s %d] stop prev-debugging to start new one\n",
			__func__, __LINE__);
		rtkaudio_dump_disable(DUMP_STOP);
	}

#ifndef CONFIG_ANDROID
	f_dump = file_open((char *)"/tmp/var/log/audio_dump.bin",
		O_TRUNC|O_RDWR|O_CREAT, 0666);
#else
	f_dump = file_open((char *)"/data/data/audio_dump.bin",
		O_TRUNC|O_RDWR|O_CREAT, 0666);
#endif
	if (f_dump == 0) {
		pr_debug("[%s %d] wait file system ready\n", __func__, __LINE__);
		return -1;
	}

	f_offset = 0;

	/* allocate debug memory */
	g_debug_viraddr = (uint)dvr_malloc_uncached_specific(
		sizeof(struct RPC_DBG_MEMORY) + 256, GFP_DCU1, (void **)&g_p_debug_mem);

	if (!g_debug_viraddr) {
		pr_err("[%s %d]alloc debug memory fail\n", __func__, __LINE__);
		return -1;
	}

	g_debug_phyaddr = (uint)dvr_to_phys((void *)g_debug_viraddr);

	if ((g_debug_phyaddr & 0xe0000000) != 0) {
		pr_err("[%s %d]get memory not between 0 ~ 512 MB\n", __func__, __LINE__);
		dvr_free((void *) g_debug_viraddr);
		g_debug_viraddr = 0;
		g_debug_phyaddr = 0;
		g_p_debug_mem = 0;
		return -1;
	}

	if ((f_dump != 0) && (g_audio_dump_size > 0))
	{
		struct DBG_BUF_HEADER *header;
		/* alocate dump memory */
		g_dump_viraddr = (uint)dvr_malloc_uncached_specific(
			g_audio_dump_size, GFP_DCU1, (void **)&g_p_dump_mem);

		if (!g_dump_viraddr) {
			dvr_free((void *)g_debug_viraddr);
			g_debug_phyaddr = g_p_debug_mem = 0;
			g_debug_viraddr = 0;
			pr_err("[%s %d]alloc debug memory fail\n", __func__, __LINE__);
			return -1;
		}
		g_dump_phyaddr = (uint)dvr_to_phys((void *)g_dump_viraddr);

		if ((g_dump_phyaddr & 0xe0000000) != 0) {
			pr_err("[%s %d]get memory not between 0 ~ 512 MB\n", __func__, __LINE__);
			dvr_free((void *) g_debug_viraddr);
			g_debug_viraddr = 0;
			g_debug_phyaddr = 0;
			g_p_debug_mem = 0;
			dvr_free((void *) g_dump_viraddr);
			g_dump_viraddr = 0;
			g_dump_phyaddr = 0;
			g_p_debug_mem = 0;
			return -1;
		}

		/* setup debug dump ring buffer header */
		header = (struct DBG_BUF_HEADER *) g_p_dump_mem;
		header->magic = htonl(0xdeadcafe);
		header->size = htonl(g_audio_dump_size);
		header->rd = htonl(g_dump_phyaddr + sizeof(struct DBG_BUF_HEADER));
		header->wr = htonl(g_dump_phyaddr + sizeof(struct DBG_BUF_HEADER));

		*(ulong *)g_p_debug_mem = htonl(g_dump_phyaddr);

		rtkaudio_debug_tsk = kthread_create(rtkaudio_debug_thread, NULL,
			"rtkaudio_debug_thread");

			if (IS_ERR(rtkaudio_debug_tsk)) {
				rtkaudio_debug_tsk = NULL;
				return -1;
			}
			wake_up_process(rtkaudio_debug_tsk);

		if (send_rpc_command(RPC_AUDIO, RPC_ACPU_DEBUG_DUMP,
			(unsigned long)g_debug_phyaddr, db_command, &ret)) {
			pr_err("rtkaudio: cmd(%d) fail %d\n", db_command, (int)ret);
		}
	}

	return 0;
}

void rtkaudio_dump_disable(uint db_command)
{
	ulong ret = S_OK;

	if (send_rpc_command(RPC_AUDIO,
		RPC_ACPU_DEBUG_DUMP, (ulong)0, db_command, &ret)) {
		pr_err("rtkaudio: cmd(%d) fail %d\n", db_command, (int)ret);
	}
	if (rtkaudio_debug_tsk) {
		ret = kthread_stop(rtkaudio_debug_tsk);
		if (!ret)
			pr_err("rtkaudio debug thread stopped\n");
	}

	if (g_dump_phyaddr) {
		dvr_free((void *) g_dump_viraddr);
		g_p_dump_mem = g_dump_phyaddr = 0;
		g_dump_viraddr = 0;
	}
	if (g_debug_phyaddr) {
		dvr_free((void *) g_debug_viraddr);
		g_p_debug_mem = g_debug_phyaddr = 0;
		g_debug_viraddr = 0;
	}

	if (f_dump)
		file_close(f_dump);

	f_dump = 0;
}

void rtkaudio_send_string(const char* pattern, int length)
{
	ulong ret = S_OK;
	ulong vir_addr;
	ulong phy_addr;
	char *command = NULL;

	vir_addr = (ulong)dvr_malloc_uncached_specific(length+1, GFP_DCU1, (void **)&command);

	if (!vir_addr) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		return;
	}
	phy_addr = (ulong)dvr_to_phys((void *)vir_addr);
	memset((void *)command, '\0', length+1);
	memcpy((void *)command, (void *)pattern, length);

	pr_debug("rtkaudio: send(%s), length(%d)\n", command, length);
	if (send_rpc_command(RPC_AUDIO, RPC_ACPU_DEBUG_COMMAND, phy_addr,
		length, &ret)) {
		pr_err("rtkaudio: send(%s) fail %d\n", pattern, (int)ret);
	}

	dvr_free((void *) vir_addr);
	return;
}
