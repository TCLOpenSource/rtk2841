/*
 * Realtek Audio driver
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
#include <linux/proc_fs.h>

#include <rtk_kdriver/rtkaudio.h>
#include <rtk_kdriver/RPCDriver.h>
#include <linux/pageremap.h>

#include <linux/delay.h>
#include <linux/kthread.h>

#include <mach/io.h>
#include <rtk_kdriver/rtkaudio_debug.h>

#include <linux/dma-mapping.h>
#include <sound/rtk_snd.h>


#ifdef CONFIG_HIBERNATION
#include <linux/pm.h>
#endif

#ifdef CONFIG_PM
static int rtkaudio_suspend(struct platform_device *dev, pm_message_t state);
static int rtkaudio_resume(struct platform_device *dev);
#endif

#ifdef CONFIG_LG_SNAPSHOT_BOOT
extern unsigned int snapshot_enable;
#endif

#ifdef CONFIG_HIBERNATION
static int rtkaudio_std_suspend(struct device *dev);
static int rtkaudio_std_resume(struct device *dev);
static int rtkaudio_str_suspend(struct device *dev);
static int rtkaudio_str_resume(struct device *dev);

static const struct dev_pm_ops rtkaudio_pm_ops = {
	.freeze		= rtkaudio_std_suspend,
	.thaw		= rtkaudio_std_resume,
	.poweroff	= rtkaudio_std_suspend,
	.restore	= rtkaudio_std_resume,
	.suspend	= rtkaudio_str_suspend,
	.resume		= rtkaudio_str_resume,
};
#endif

static BLOCKING_NOTIFIER_HEAD(rtkaudio_chain_head);

static int rtkaudio_major = RTKAUDIO_MAJOR;
static int rtkaudio_minor = RTKAUDIO_MINOR;

module_param(rtkaudio_major, int, S_IRUGO);
module_param(rtkaudio_minor, int, S_IRUGO);

static struct class *rtkaudio_class;
static struct cdev rtkaudio_cdev;
static struct platform_device *rtkaudio_platform_devs;
static struct platform_driver rtkaudio_device_driver = {
#ifdef CONFIG_PM
	.suspend		= rtkaudio_suspend,
	.resume			= rtkaudio_resume,
#endif
	.driver = {
		.name		= "rtkaudio",
		.bus		= &platform_bus_type,
#ifdef CONFIG_HIBERNATION
		.pm 		= &rtkaudio_pm_ops,
#endif
	},
};

/* for retry defaul dump audio log */
static struct task_struct *rtkaudio_enable_tsk;
static int rtkaudio_enable_thread(void* arg);

/* for record remote malloc memory info */
static struct list_head remote_malloc_info_head;
static DEFINE_SEMAPHORE(buffer_list_sem);

/* for record rtkaudio alloc info */
static struct list_head rtkaudio_alloc_head;
static DEFINE_SEMAPHORE(rtkaudio_alloc_sem);

/* for open info */
static struct list_head rtkaudio_open_info_head;
static DEFINE_SEMAPHORE(rtkaudio_open_info_list_sem);

/* for proc entry */
struct proc_dir_entry *rtkaudio_proc_dir;
struct proc_dir_entry *rtkaudio_proc_entry;

/* RTKAudio control status */
typedef enum {
	RESOURCE_STATUS,
	MAIN_FLOW_STATUS,
	SUB_FLOW_STATUS,
	AIN_STATUS,
	SE_STATUS,
	AIN_AGENT_STATUS,
	PPAO_AGENT_STATUS,
	DECODER_STATUS,
	MAIN_DECODER_STATUS,
	ALSA_DEV_INFO,
	GST_DEBUG_INFO,
	VIRTUALX_CMD_INFO,
	MAX_CONTROL_NUM,
} RTKAUDIO_CONTROL_TYPE;

#define MAX_CONNECT_NUM (10)
#define MAX_RESOURCE_NUM (34)
#define MAX_SE_INPUT_NUM (3)
#define MAX_AIN_ADC_PIN (9)

/* from AUDIO_SW_DBG_REG_1_VADDR need check */
#ifndef AUDIO_SW_DBG_REG_1_VADDR
#define AUDIO_SW_DBG_REG_1_VADDR (0xb8006074)
#ifndef GST_SHARED_REGISTER
#define GST_SHARED_REGISTER AUDIO_SW_DBG_REG_1_VADDR
#endif
#endif

#ifndef AUDIO_SW_DBG_REG_2_VADDR
#define AUDIO_SW_DBG_REG_2_VADDR (0xb8006078)
#endif

#ifndef AUDIO_LR_DIGITAL_VOLUME_CONTROL_VADDR
#define AUDIO_LR_DIGITAL_VOLUME_CONTROL_VADDR (0xb80067bc)
#endif

#ifndef AUDIO_CSW_DIGITAL_VOLUME_CONTROL_VADDR
#define AUDIO_CSW_DIGITAL_VOLUME_CONTROL_VADDR (0xb80067c0)
#endif

#ifndef AUDIO_LSRS_DIGITAL_VOLUME_CONTROL_VADDR
#define AUDIO_LSRS_DIGITAL_VOLUME_CONTROL_VADDR (0xb80067c4)
#endif

#ifndef AUDIO_LRRR_DIGITAL_VOLUME_CONTROL_2_VADDR
#define AUDIO_LRRR_DIGITAL_VOLUME_CONTROL_2_VADDR (0xb8006908)
#endif

struct audio_resource_status {
	char name[12];
	int connect_status[MAX_CONNECT_NUM];
	int input_res_id[MAX_CONNECT_NUM];
	int output_res_id[MAX_CONNECT_NUM];
	int num_of_output;
	int num_of_input;
	int max_of_input;
};
static struct audio_resource_status resource_st[MAX_RESOURCE_NUM];
static DEFINE_SEMAPHORE(resource_sem);
static void show_resource(struct audio_resource_status *res_st);

struct connection {
	struct list_head list;
	int head_id;
	int tail_id;
};
struct resource_t {
	struct list_head list;
	int res_id;
};

struct audio_flow_status {
	unsigned char is_ain_exist;
	int ain_2_dex_id;
	unsigned char is_sub_ain_exist;
	int sub_ain_2_dex_id;
	unsigned char is_dec0_exist;
	unsigned char is_dec1_exist;
	unsigned char is_enc_exist;
	unsigned char is_scartout_bypass;
	int dec_2_scart_id;
	int main_dec_id;
	unsigned char is_system_output;
	unsigned char is_dtv0;
	unsigned char is_dtv1;
	unsigned char is_ppao_exist;
	unsigned char is_sub_ppao_exist;
};
static struct audio_flow_status main_flow_st;
static struct audio_flow_status sub_flow_st;
static DEFINE_SEMAPHORE(main_flow_sem);
static DEFINE_SEMAPHORE(sub_flow_sem);

struct audio_ain_status {
	int ain_pin_status[MAX_AIN_ADC_PIN];
};
static struct audio_ain_status ain_st;
static DEFINE_SEMAPHORE(ain_sem);

struct audio_se_status {
	int se_pin_status;
};
static struct audio_se_status se_st[MAX_SE_INPUT_NUM];
static DEFINE_SEMAPHORE(se_sem);

#define MAX_AIN_INST_NUM 2
struct audio_ain_agent_status {
	int instance_index;
	int instance_list[MAX_AIN_INST_NUM];
};
static struct audio_ain_agent_status ain_agent_st;
static DEFINE_SEMAPHORE(ain_agent_sem);

struct audio_ppao_agent_status {
	int pp_agent_id;
	int ao_agent_id;
	int pin_count;
	int focud_id;
};
static struct audio_ppao_agent_status ppao_agent_st;
static DEFINE_SEMAPHORE(ppao_agent_sem);

#define MAX_CH (8)
#define DEC_NUM (2)
struct audio_dec_status {
	int dec_mute;
	int dec_delay;
	int dec_vol[MAX_CH];
};
static struct audio_dec_status decoder_st[DEC_NUM];
static DEFINE_SEMAPHORE(decoder_st_sem);

#define MAINDEC_INFO_NUM (8)
struct main_dec_status {
	/*
		info[0]: Main Decoder Number(0 or 1)
		info[1]: OMX Decoder exit(0 or 1)
		info[2]: OMX Decoder used port (0 or 1)
		info[3]: OMX Decoder used pp pin id
		info[4 ~ 7]: reserved
	*/
	long info[MAINDEC_INFO_NUM];
};
static struct main_dec_status main_dec_st;
static DEFINE_SEMAPHORE(main_dec_st_sem);

struct alsasink_device_info {
	int card;
	int device;
};
static struct alsasink_device_info alsa_info;
static DEFINE_SEMAPHORE(alsa_info_sem);

static DEFINE_SEMAPHORE(gst_debug_info_sem);

struct gst_refc_list *gst_refc_info;
int pr_to_dmesg_en;
int dump_size_scale;

char AudioGITHASH[8];

static DEFINE_SEMAPHORE(virtualx_cmd_sem);

static void control_status_init(void);

struct device* get_rtkaudio_device_ptr(void)
{
	return &(rtkaudio_platform_devs->dev);
}

extern bool reserve_boot_memory;

static int rtkaudio_enable_thread(void *arg)
{
	int ret = 0;
	int count = 0;

#if (defined(CONFIG_LG_SNAPSHOT_BOOT) && defined(CONFIG_CUSTOMER_TV006))
	if (snapshot_enable == 1)
	{
		unsigned long timeout = jiffies + HZ * 30; //30 seconds
		bool is_timeout = false;
		// waiting for saving image finish, this patch is used to prevent migration failure
		while (reserve_boot_memory) {
			msleep(10);
			if (time_before(jiffies, timeout) == 0) {
				is_timeout = true;
				break;
			}
		}

		if (is_timeout)
			BUG();

		control_status_init();

		/* send REMOTE MELLOC ENABLE RPC to Audio FW */
		if (send_rpc_command(RPC_AUDIO,
			RPC_ACPU_IS_REMOTE_MALLOC_ENABLE,
			REMOTE_MALLOC_ENABLE, 0, &ret)) {
			pr_err("rtkaudio: RPC fail %ld\n", ret);
		}

		if (ret != S_OK)
		pr_err("rtkaudio: RPC is not S_OK %ld\n", ret);
	}
#endif

#if 0
	for (;;) {
		ret = rtkaudio_dump_enable(DUMP_LOG);

		if (ret < 0) {
			pr_debug("wait to enable audio dump file, retry...\n");
			msleep(1000); /* sleep 1s */
			count++;
		} else if (ret == 0){
			break;
		}

		if (count == 10) {
			pr_err("wait enable audio dump file timeout\n");
			break;
		}
	}
	pr_debug("enable audio dump file!!!\n");
#endif

	do_exit(0);
	return 0;
}

static void show_output(int head_id,
			struct audio_resource_status *res_st,
			int connect_level,
			char line[128])
{
	int num_of_output = 0;
	int i, j;
	char tmp_string[20];
	if (connect_level > MAX_RESOURCE_NUM) {
		/* Error handler */
		rtkaudio_must_print("%s\n", line);
		rtkaudio_must_print("connect_level is over MAX resource number\n");
		memset(line, 0, 128*sizeof(char));
		return;
	}
	if (res_st[head_id].num_of_output == 0) {
		/* End of a connection */
		rtkaudio_must_print("%s\n", line);
		memset(line, 0, 128*sizeof(char));
		return;
	}

	for (i = 0; i < MAX_CONNECT_NUM; i++) {
		if (res_st[head_id].output_res_id[i] == 0xff)
			continue;
		if (num_of_output > 0) {
			for (j = 0; j < connect_level; j++)
				strcat(line, "              ");
			sprintf(tmp_string, " |- %10s",
				res_st[res_st[head_id].output_res_id[i]].name);
			strcat(line, tmp_string);
			memset(tmp_string, 0, sizeof(tmp_string));
			show_output(res_st[head_id].output_res_id[i],
					res_st, connect_level+1, line);
		} else {
			sprintf(tmp_string, " -- %10s",
				res_st[res_st[head_id].output_res_id[i]].name);
			strcat(line, tmp_string);
			memset(tmp_string, 0, sizeof(tmp_string));
			show_output(res_st[head_id].output_res_id[i],
					res_st, connect_level+1, line);
		}
		num_of_output++;
	}
}

char *status_name[] = {
	"Close",
	"Open",
	"Connect",
	"DisCnnt",
	"Stop",
	"Pause",
	"Run",
	"Unknown",
};

static void show_resource(struct audio_resource_status *res_st)
{
	int i, j;
	char status_line[128];
	char tmp_string[32];
	struct list_head open_list = LIST_HEAD_INIT(open_list);
	struct list_head flow_head_list = LIST_HEAD_INIT(flow_head_list);
	struct list_head connect_list = LIST_HEAD_INIT(connect_list);
	struct resource_t *res, *tmp_res;
	struct connection *connect, *tmp_cnt;

	for (i = 0; i < MAX_RESOURCE_NUM; i++) {
		int input_num = 0;
		if ((res_st[i].connect_status[0] == 0) &&
			(res_st[i].num_of_input + res_st[i].num_of_output == 0))
			continue;
		res = (struct resource_t*) kmalloc(sizeof(struct resource_t), GFP_KERNEL);
		res->res_id = i;
		list_add(&res->list, &open_list);
		for (j = 0; j < MAX_CONNECT_NUM; j++) {
			if (res_st[i].input_res_id[j] == 0xff)
				continue;
			connect = (struct connection*) kmalloc(sizeof(struct connection), GFP_KERNEL);
			connect->head_id = res_st[i].input_res_id[j];
			connect->tail_id = i;
			list_add(&connect->list, &connect_list);
			input_num++;
		}
		if (input_num == 0 && res_st[i].num_of_output > 0) {
			res = (struct resource_t*) kmalloc(sizeof(struct resource_t), GFP_KERNEL);
			res->res_id = i;
			list_add(&res->list, &flow_head_list);
		}
	}

	rtkaudio_must_print("\nExists Resources:");
	list_for_each_entry_reverse(res, &open_list, list) {
		int status_id = 0;
		for (j = 0; j < MAX_CONNECT_NUM; j++)
			if (res_st[res->res_id].connect_status[j] > 0) {
				status_id = res_st[res->res_id].connect_status[j];
				break;
			}
		rtkaudio_must_print("%s is %s\n", res_st[res->res_id].name,
				status_name[status_id]);
	}
	rtkaudio_must_print("\n");

	/* pr_warn("Connections:\n");
	list_for_each_entry_reverse(connect, &connect_list, list) {
		pr_warn("%10s -> %10s\n", res_st[connect->head_id].name,
					    res_st[connect->tail_id].name);
	} */

	list_for_each_entry_reverse(res, &flow_head_list, list) {
		rtkaudio_must_print("======Flow :======\n");
		memset(status_line, 0, sizeof(status_line));
		sprintf(tmp_string, ">>> %10s", res_st[res->res_id].name);
		strcat(status_line, tmp_string);
		show_output(res->res_id, res_st, 1, status_line);
		rtkaudio_must_print("==================\n");
	}

	list_for_each_entry_safe(res, tmp_res, &open_list, list) {
		list_del(&res->list);
		kfree(res);
	}
	list_for_each_entry_safe(res, tmp_res, &flow_head_list, list) {
		list_del(&res->list);
		kfree(res);
	}
	list_for_each_entry_safe(connect, tmp_cnt, &connect_list, list) {
		list_del(&connect->list);
		kfree(connect);
	}
}

void show_dec_status(struct audio_dec_status dec_st)
{
	int i, prev_vol = 0;
	int db, mdb;
	pr_warn("DEC Mute: %s\n", dec_st.dec_mute == 1? "Mute":"UnMute");
	for (i = 0; i < MAX_CH; i++) {
		int dvol = (int)dec_st.dec_vol[i];
		if (prev_vol == dvol)
			continue;
		db = (dvol - 389)/4;
		mdb = (abs(dvol - 389)%4)*25;
		if (dvol >= 386 && dvol < 389) {
			rtkaudio_must_print("DEC volume ch%d: %d (-%d.%d) dB\n",
				i, dvol, db, mdb);
		} else {
			rtkaudio_must_print("DEC volume ch%d: %d (%d.%d) dB\n",
				i, dvol, db, mdb);
		}
		prev_vol = dvol;
	}
	rtkaudio_must_print("DEC delay time: %d ms\n", dec_st.dec_delay);
}
/* End of audio resource status */

static void show_main_decoder_status(void) {
	int i;

	for(i = 0; i < MAINDEC_INFO_NUM; i++) {
		pr_err("main dec st [%d] %ld\n", i, main_dec_st.info[i]);
	}
}

int register_rtkaudio_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&rtkaudio_chain_head, nb);
}
EXPORT_SYMBOL_GPL(register_rtkaudio_notifier);

int unregister_rtkaudio_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_unregister(&rtkaudio_chain_head, nb);
}
EXPORT_SYMBOL_GPL(unregister_rtkaudio_notifier);

int rtkaudio_notifier_call_chain(unsigned long val)
{
	int ret;

	ret = blocking_notifier_call_chain(&rtkaudio_chain_head, val, NULL);
	if (ret == NOTIFY_BAD)
		ret = -EINVAL;
	else
		ret = 0;

	return ret;
}

#ifdef CONFIG_PM
static int rtkaudio_suspend(struct platform_device *dev, pm_message_t state)
{
	unsigned long ret = S_OK;

	rtkaudio_notifier_call_chain(RTKAUDIO_SUSPEND);
	rtkaudio_notifier_call_chain(RTKAUDIO_RESET_PREPARE);
	pr_info("rtkaudio: receive supend command\n");
	/* todo resetav_lock(1); */
#ifdef CONFIG_HIBERNATION
	if ((state.event != PM_EVENT_SUSPEND) || (in_suspend))
		pr_info("rtkaudio: ignore suspend\n");
	else
#endif

	/* send REMOTE MELLOC DISABLE RPC to Audio FW */
	if (send_rpc_command(RPC_AUDIO,
		RPC_ACPU_IS_REMOTE_MALLOC_ENABLE,
		REMOTE_MALLOC_DISABLE, 0, &ret)) {
		pr_err("rtkaudio: RPC fail %ld\n", ret);
	}

	if (ret != S_OK)
		pr_err("rtkaudio: RPC is not S_OK %ld\n", ret);

	return 0;
}

extern struct device* get_avcpu_device_ptr(void);

static int rtkaudio_resume(struct platform_device *dev)
{
	unsigned long phy_addr;
	unsigned long ret = S_OK;

	pr_err("Before rtkaudio_resume\n");
	device_pm_wait_for_dev(&(dev->dev), get_avcpu_device_ptr());

	/* todo resetav_unlock(1); */
	pr_info("rtkaudio: receive resume command\n");
	rtkaudio_notifier_call_chain(RTKAUDIO_RESET_DONE);
	rtkaudio_notifier_call_chain(RTKAUDIO_RESUME);

	phy_addr = (unsigned long)dvr_to_phys((void*) gst_refc_info);
	pr_info ("rtkaudio vir_addr %x, phy_addr %x\n", gst_refc_info, phy_addr);
	pr_info ("rtkaudio read reg %x\n", rtd_inl(GST_SHARED_REGISTER));
	rtd_outl(GST_SHARED_REGISTER, (unsigned long) phy_addr);
	pr_info ("rtkaudio read reg after write %x\n", rtd_inl(GST_SHARED_REGISTER));
	/* send REMOTE MELLOC ENABLE RPC to Audio FW */
	if (send_rpc_command(RPC_AUDIO,
		RPC_ACPU_IS_REMOTE_MALLOC_ENABLE,
		REMOTE_MALLOC_ENABLE, 0, &ret)) {
		pr_err("rtkaudio: RPC fail %ld\n", ret);
	}

	if (ret != S_OK)
		pr_err("rtkaudio: RPC is not S_OK %ld\n", ret);

	return 0;
}
#endif

#ifdef CONFIG_HIBERNATION
static int rtkaudio_std_suspend(struct device *dev)
{
	unsigned long ret = S_OK;

	rtkaudio_notifier_call_chain(RTKAUDIO_SUSPEND);
	rtkaudio_notifier_call_chain(RTKAUDIO_RESET_PREPARE);
	pr_info("rtkaudio: receive supend command\n");

	return 0;
}

static int rtkaudio_std_resume(struct device *dev)
{
	unsigned long phy_addr;
	unsigned long ret = S_OK;

	pr_err("Before rtkaudio_resume\n");
	device_pm_wait_for_dev(dev, get_avcpu_device_ptr());

	/* todo resetav_unlock(1); */
	pr_info("rtkaudio: receive resume command\n");
	rtkaudio_notifier_call_chain(RTKAUDIO_RESET_DONE);
	rtkaudio_notifier_call_chain(RTKAUDIO_RESUME);

#ifdef CONFIG_LG_SNAPSHOT_BOOT
	if (snapshot_enable == 0)
#endif
	{
		control_status_init();

		/* send REMOTE MELLOC ENABLE RPC to Audio FW */
		if (send_rpc_command(RPC_AUDIO,
			RPC_ACPU_IS_REMOTE_MALLOC_ENABLE,
			REMOTE_MALLOC_ENABLE, 0, &ret)) {
			pr_err("rtkaudio: RPC fail %ld\n", ret);
		}

		if (ret != S_OK)
			pr_err("rtkaudio: RPC is not S_OK %ld\n", ret);
	}

#if (defined(CONFIG_LG_SNAPSHOT_BOOT) && defined(CONFIG_CUSTOMER_TV006))
	rtkaudio_enable_tsk = kthread_create(rtkaudio_enable_thread, NULL,
			"rtkaudio_enable_thread");
	if (IS_ERR(rtkaudio_enable_tsk)) {
		rtkaudio_enable_tsk = NULL;
		return -1;
	}
	wake_up_process(rtkaudio_enable_tsk);
#endif
	return 0;
}

static int rtkaudio_str_suspend(struct device *dev)
{
	unsigned long ret = S_OK;
	pr_info("rtkaudio: roni receive supend command\n");

	rtkaudio_notifier_call_chain(RTKAUDIO_SUSPEND);
	rtkaudio_notifier_call_chain(RTKAUDIO_RESET_PREPARE);
	pr_info("rtkaudio: receive supend command\n");
	/* todo resetav_lock(1); */

#if	0//def CONFIG_HIBERNATION
	if ((state.event != PM_EVENT_SUSPEND) || (in_suspend))
		pr_info("rtkaudio: ignore suspend\n");
	else
#endif

	/* send REMOTE MELLOC DISABLE RPC to Audio FW */

	if (send_rpc_command(RPC_AUDIO,
		RPC_ACPU_IS_REMOTE_MALLOC_ENABLE,
		REMOTE_MALLOC_DISABLE, 0, &ret)) {
		pr_err("rtkaudio: RPC fail %ld\n", ret);
	}

	if (ret != S_OK)
		pr_err("rtkaudio: RPC is not S_OK %ld\n", ret);

	return 0;
}


static int rtkaudio_str_resume(struct device *dev)
{
	unsigned long phy_addr;
	unsigned long ret = S_OK;

	pr_debug("Before rtkaudio_resume roni \n");

	device_pm_wait_for_dev(dev, get_avcpu_device_ptr());


	/* todo resetav_unlock(1); */

	pr_info("rtkaudio: receive resume command\n");
	rtkaudio_notifier_call_chain(RTKAUDIO_RESET_DONE);
	rtkaudio_notifier_call_chain(RTKAUDIO_RESUME);

	phy_addr = (unsigned long)dvr_to_phys((void*) gst_refc_info);
	pr_info ("rtkaudio vir_addr %x, phy_addr %x\n", gst_refc_info, phy_addr);

	rtd_outl(GST_SHARED_REGISTER, (unsigned long) phy_addr);
	pr_info ("rtkaudio read reg after write %x\n", rtd_inl(GST_SHARED_REGISTER));
	/* send REMOTE MELLOC ENABLE RPC to Audio FW */

	if (send_rpc_command(RPC_AUDIO,
		RPC_ACPU_IS_REMOTE_MALLOC_ENABLE,
		REMOTE_MALLOC_ENABLE, 0, &ret)) {
		pr_err("rtkaudio: RPC fail %ld\n", ret);
	}

	if (ret != S_OK)
		pr_err("rtkaudio: RPC is not S_OK %ld\n", ret);

	return 0;
}

#endif

void rtkaudio_fw_remote_malloc_summary(struct ret_info *info)
{
	unsigned long sum_request, sum_malloc;
	struct list_head *list;
	struct buffer_info *buf_info;

	sum_malloc = 0;
	sum_request = 0;

	down(&buffer_list_sem);
	list_for_each(list, &remote_malloc_info_head) {
		buf_info = list_entry(list, struct buffer_info, buffer_list);
		pr_debug("vir_addr %lx, phy_addr %lx\n",
			buf_info->vir_addr, buf_info->phy_addr);
		pr_debug("request_size %lx, malloc_size %lx\n",
			buf_info->request_size, buf_info->malloc_size);
		sum_request += buf_info->request_size;
		sum_malloc += buf_info->malloc_size;
	}
	up(&buffer_list_sem);

	pr_debug("sum_malloc %ld, sum_request %ld\n", sum_malloc, sum_request);

	if (info == NULL)
		return;

	info->private_info[0] = sum_request;
	info->private_info[1] = sum_malloc;
}

void rtkaudio_print_buffer_info(void)
{
	struct list_head *list;
	struct buffer_info *buf_info;

	down(&buffer_list_sem);
	list_for_each(list, &remote_malloc_info_head) {
		buf_info = list_entry(list, struct buffer_info, buffer_list);
		pr_debug("vir_addr %lx, phy_addr %lx\n",
			buf_info->vir_addr, buf_info->phy_addr);
		pr_debug("request_size %lx, malloc_size %lx\n",
			buf_info->request_size, buf_info->malloc_size);
	}
	up(&buffer_list_sem);
}

/* RPC handler function */
unsigned long rtkaudio_remote_malloc(unsigned long para1, unsigned long para2)
{
	unsigned long vir_addr;
	unsigned long phy_addr;
	struct buffer_info *buf_info;

	pr_debug("rtkaudio_remote_malloc(%lx/%lx)\n", para1, para2);

	vir_addr = (unsigned long)dvr_malloc_specific(para1, GFP_DCU1);
	if (vir_addr == NULL) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		return -ENOMEM;
	}

	phy_addr = (unsigned long)dvr_to_phys((void*)vir_addr);
	if (phy_addr == NULL) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		if (vir_addr) {
			dvr_free(vir_addr);
		}
		return -ENOMEM;
	}

	if ((phy_addr & 0xe0000000) != 0) {
		pr_err("[%s %d]get memory not between 0 ~ 512 MB\n", __func__, __LINE__);
		if (vir_addr) {
			dvr_free(vir_addr);
		}
		return -ENOMEM;
	}

	buf_info = kmalloc(sizeof(struct buffer_info), GFP_KERNEL);
	if (buf_info == NULL) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		if (vir_addr) {
			dvr_free(vir_addr);
		}
		return -ENOMEM;
	}

	INIT_LIST_HEAD(&buf_info->buffer_list);

	buf_info->vir_addr = vir_addr;
	buf_info->phy_addr = phy_addr;
	buf_info->request_size = para1;
	buf_info->malloc_size = PAGE_ALIGN(para1);

	pr_debug("rtkaudio_remote_malloc addr (%lx,%lx)\n", phy_addr, vir_addr);
	down(&buffer_list_sem);
	list_add(&buf_info->buffer_list, &remote_malloc_info_head);
	up(&buffer_list_sem);
	return phy_addr;
}

/* RPC handler function */
unsigned long rtkaudio_remote_free(unsigned long para1, unsigned long para2)
{
	unsigned long vir_addr = NULL;
	struct list_head *del_list;
	struct buffer_info *buf_info = NULL;

	pr_debug("rtkaudio_remote_free(%lx/%lx)\n", para1, para2);

	down(&buffer_list_sem);
	list_for_each(del_list, &remote_malloc_info_head) {
		buf_info = list_entry(del_list,
			struct buffer_info,
			buffer_list);
		if (buf_info->phy_addr == para1) {
			vir_addr = buf_info->vir_addr;
			list_del(del_list);
			break;
		}
	}
	up(&buffer_list_sem);

	if (vir_addr != NULL)
		dvr_free((void *)vir_addr);

	if (buf_info != NULL)
		kfree(buf_info);

	return 0;
}

int rtkaudio_alloc(int size)
{
	unsigned int vir_addr;
	unsigned int phy_addr;
	struct buffer_info *buf_info;

	vir_addr = (unsigned int)dvr_malloc_specific(size, GFP_DCU1);
	if (vir_addr == NULL) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		return -ENOMEM;
	}

	phy_addr = (unsigned int)dvr_to_phys((void *)vir_addr);
	if (!phy_addr) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		if (vir_addr) {
			dvr_free(vir_addr);
		}
		return -ENOMEM;
	}

	if ((phy_addr & 0xe0000000) != 0) {
		pr_err("[%s %d]get memory not between 0 ~ 512 MB\n", __func__, __LINE__);
		if (vir_addr) {
			dvr_free(vir_addr);
		}
		return -ENOMEM;
	}

	buf_info = kmalloc(sizeof(struct buffer_info), GFP_KERNEL);
	if (buf_info == NULL) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		if (vir_addr) {
			dvr_free(vir_addr);
		}
		return -ENOMEM;
	}

	buf_info->vir_addr = vir_addr;
	buf_info->phy_addr = phy_addr;
	buf_info->request_size = size;
	buf_info->malloc_size = PAGE_ALIGN(size);
	buf_info->task_pid = task_tgid_nr(current);
	pr_debug("Alloc (p:%x,v:%x) for pid(%d)\n",
		phy_addr, vir_addr, task_tgid_nr(current));

	down(&rtkaudio_alloc_sem);
	list_add(&buf_info->buffer_list, &rtkaudio_alloc_head);
	up(&rtkaudio_alloc_sem);

	return phy_addr;
}

int rtkaudio_free(unsigned int phy_addr)
{
	unsigned int vir_addr;
	struct buffer_info *buf_info;

	vir_addr = 0xFFFFFFFF;
	down(&rtkaudio_alloc_sem);
	list_for_each_entry(buf_info, &rtkaudio_alloc_head, buffer_list)
	{
		if (buf_info->phy_addr == phy_addr &&
			buf_info->task_pid == task_tgid_nr(current)) {
			vir_addr = buf_info->vir_addr;
			list_del(&buf_info->buffer_list);
			kfree(buf_info);
			break;
		}
	}
	up(&rtkaudio_alloc_sem);

	if (vir_addr == 0xFFFFFFFF) {
		pr_err("[rtkaudio] %x doesn't in memory list\n", phy_addr);
		return 0;
	}

	dvr_free((void *)vir_addr);
	return 0;
}

void rtkaudio_free_by_process(unsigned long process_id)
{
	struct buffer_info *buf_info, *tmp_buf_info;

	down(&rtkaudio_alloc_sem);
	list_for_each_entry_safe(buf_info, tmp_buf_info,
		&rtkaudio_alloc_head, buffer_list)
	{
		if (buf_info->task_pid == process_id) {
			list_del(&buf_info->buffer_list);
			dvr_free((void *)buf_info->vir_addr);
			kfree(buf_info);
		}
	}
	up(&rtkaudio_alloc_sem);
}

void rtkaudio_user_alloc_summary(struct ret_info *info)
{
	unsigned long sum_request, sum_malloc;
	struct buffer_info *buf_info;
	struct buffer_info *b;
	struct list_head pid_list = LIST_HEAD_INIT(pid_list);

	sum_malloc = sum_request = 0;

	down(&rtkaudio_alloc_sem);
	list_for_each_entry(buf_info, &rtkaudio_alloc_head, buffer_list)
	{
		pr_debug("pid(%d) : malloc %d, request %d\n",
			(int)buf_info->task_pid,
			(int)buf_info->malloc_size,
			(int)buf_info->request_size);

		if (list_empty(&pid_list)) {
			b = kmalloc(sizeof(struct buffer_info), GFP_KERNEL);
			b->task_pid = buf_info->task_pid;
			b->request_size = b->malloc_size = 0;
			list_add(&b->buffer_list, &pid_list);
		} else {
			int pid_exist = false;
			list_for_each_entry(b, &pid_list, buffer_list)
			{
				if (b->task_pid == buf_info->task_pid) {
					pid_exist = true;
					break;
				}
			}
			if (pid_exist == false) {
				b = kmalloc(sizeof(struct buffer_info),
					GFP_KERNEL);
				b->task_pid = buf_info->task_pid;
				b->request_size = b->malloc_size = 0;
				list_add(&b->buffer_list, &pid_list);
			}
		}
		b->request_size += buf_info->request_size;
		b->malloc_size += buf_info->malloc_size;
	}
	up(&rtkaudio_alloc_sem);
	list_for_each_entry_safe(b, buf_info, &pid_list, buffer_list)
	{
		pr_debug("pid(%d) : sum_malloc %d, sum_request %d\n",
			(int)b->task_pid,
			(int)b->malloc_size,
			(int)b->request_size);
		sum_request += b->request_size;
		sum_malloc  += b->malloc_size;
		list_del(&b->buffer_list);
		kfree(b);
	}

	pr_debug("sum_malloc %ld, sum_request %ld\n", sum_malloc, sum_request);

	if (info == NULL)
		return;

	info->private_info[0] = sum_request;
	info->private_info[1] = sum_malloc;
}

/* RPC handler function */
unsigned long rtkaudio_free_user_mem(unsigned long para1, unsigned long para2)
{
	pr_debug("rtkaudio_free_user_mem(%lx/%lx)\n", para1, para2);
	rtkaudio_user_alloc_summary(NULL);
	rtkaudio_free_by_process(para1);
	rtkaudio_user_alloc_summary(NULL);
	return 0;
}

static void control_status_init(void)
{
	int i;
	unsigned long vir_addr;
	unsigned long phy_addr;

	ain_agent_st.instance_index = 0;
	for(i = 0; i < MAX_AIN_INST_NUM; i++)
		ain_agent_st.instance_list[0] = -1;

	ppao_agent_st.pp_agent_id = -1;
	ppao_agent_st.ao_agent_id = -1;
	ppao_agent_st.focud_id    = 0;
	ppao_agent_st.pin_count   = 0;

	for(i = 0; i < MAINDEC_INFO_NUM; i++)
		main_dec_st.info[i] = -1;

	alsa_info.card = 0;
	alsa_info.device = 0;

	vir_addr = (unsigned long)dvr_malloc_specific(4096, GFP_DCU1);
	if (vir_addr == NULL) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		return -ENOMEM;
	}

	phy_addr = (unsigned long)dvr_to_phys((void*)vir_addr);
	if (phy_addr == NULL) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		if (vir_addr) {
			dvr_free(vir_addr);
		}
		return;
	}

	gst_refc_info = (struct gst_refc_list *) vir_addr;
	rtd_outl(GST_SHARED_REGISTER, (unsigned long) phy_addr);

	gst_refc_info->size = refc_info_size;
	gst_refc_info->index = 0;

	for(i = 0; i < gst_refc_info->size; i++) {
		gst_refc_info->info[i].phy_addr = -1;
		gst_refc_info->info[i].pid = -1;
		gst_refc_info->info[i].port = -1;
	}
}

int read_register_by_type(AUDIO_REGISTER_ACCESS_T *info)
{
	int value = -1;

	switch(info->reg_type) {
		case LR_DIGITAL_VOLUME_CONTROL_STATUS:
			value = rtd_inl(AUDIO_LR_DIGITAL_VOLUME_CONTROL_VADDR);
			break;
		case CSW_DIGITAL_VOLUME_CONTROL_STATUS:
			value = rtd_inl(AUDIO_CSW_DIGITAL_VOLUME_CONTROL_VADDR);
			break;
		case LSRS_DIGITAL_VOLUME_CONTROL_STATUS:
			value = rtd_inl(AUDIO_LSRS_DIGITAL_VOLUME_CONTROL_VADDR);
			break;
		case LRRR_DIGITAL_VOLUME_CONTROL_STATUS:
			value = rtd_inl(AUDIO_LRRR_DIGITAL_VOLUME_CONTROL_2_VADDR);
			break;
		case GST_CLOCK:
			value = rtd_inl(GST_SHARED_REGISTER);
			break;
		case AMIXER_STATUS:
			value = rtd_inl(AUDIO_SW_DBG_REG_2_VADDR);
			break;
		case DEBUG_REGISTER:
			value = rtd_inl(info->reg_value);
			pr_err("[rtkaudio] debug read register value %x\n", value);
			break;
		default:
			pr_err("[rtkaudio] unsupport read register type %d\n", info->reg_type);
			break;
	}

	return value;
}

void write_register_by_type(AUDIO_REGISTER_ACCESS_T *info) {
	switch(info->reg_type) {
		case DEBUG_REGISTER:
			rtd_outl(info->reg_value, info->data);
			pr_info("[rtkaudio] debug write register value %x\n", info->reg_value);
			break;
		default:
			pr_err("[rtkaudio] unsupport write register type %d\n", info->reg_type);
			break;
	}
}

int rtkaudio_open(struct inode *inode, struct file *filp)
{
	if (!filp->private_data) {
		struct list_head *list;
		struct rtkaudio_open_list *open_info;
		struct rtkaudio_open_list *info_list;

		down(&rtkaudio_open_info_list_sem);
		list_for_each(list, &rtkaudio_open_info_head) {
			open_info =
				list_entry(list, struct rtkaudio_open_list, open_list);

			if (open_info == NULL) {
				pr_warn("[%s] open info is NULL return here %x\n", __func__, open_info);
				up(&rtkaudio_open_info_list_sem);
				return 0;
			}

			if (open_info->pid == current->tgid) {
				up(&rtkaudio_open_info_list_sem);
				return 0;
			}
		}
		up(&rtkaudio_open_info_list_sem);

		info_list =
			kmalloc(sizeof(struct rtkaudio_open_list), GFP_KERNEL);

		if (info_list == NULL) {
			pr_err("%s: failed to allocate rtkaudio_open_list\n", __func__);
			return -ENOMEM;
		}

		INIT_LIST_HEAD(&info_list->open_list);
		info_list->pid = current->tgid;
		info_list->info.gst_open = 0;
		info_list->info.decoded_size = 0llu;
		info_list->info.undecoded_size = 0llu;
		down(&rtkaudio_open_info_list_sem);
		list_add(&info_list->open_list, &rtkaudio_open_info_head);
		up(&rtkaudio_open_info_list_sem);
		filp->private_data = info_list;
	}
	return 0;
}

int rtkaudio_release(struct inode *inode, struct file *filp)
{
	if (filp->private_data) {
		struct rtkaudio_open_list *info_list = filp->private_data;
		struct list_head *del_list;
		struct rtkaudio_open_list *open_info_list;

		down(&rtkaudio_open_info_list_sem);
		list_for_each(del_list, &rtkaudio_open_info_head) {
			open_info_list =
				list_entry(del_list, struct rtkaudio_open_list, open_list);
			if (open_info_list->pid == info_list->pid) {
				list_del(del_list);
				kfree(open_info_list);
				break;
			}
		}
		up(&rtkaudio_open_info_list_sem);
	}
	return 0;
}

long rtkaudio_send_audio_config(AUDIO_CONFIG_COMMAND_RTKAUDIO * cmd)
{
	long ret = S_OK;
	ulong dvr_addr;
	ulong phy_addr;
	char *command = NULL;
       int i;

	AUDIO_CONFIG_COMMAND_RTKAUDIO *vir_audioConfig, *phy_audioConfig;
	long *vir_res, *phy_res;

	dvr_addr = (ulong)dvr_malloc_uncached_specific(4096, GFP_DCU1, (void **)&vir_audioConfig);

	if (!dvr_addr) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		return 0;
	}
	phy_addr = (ulong)dvr_to_phys((void *)dvr_addr);

	//pr_debug("rtkaudio_send_audio_config: msg_id=%d\n",cmd->msg_id);

	vir_audioConfig->msg_id = htonl(cmd->msg_id);

	for (i=0;i<15;i++) {
		vir_audioConfig->value[i] = htonl(cmd->value[i]);
	}

	phy_res = ((phy_addr+ sizeof(AUDIO_CONFIG_COMMAND_RTKAUDIO) + 8) &0xFFFFFFFC);
	vir_res = (((long)vir_audioConfig+ sizeof(AUDIO_CONFIG_COMMAND_RTKAUDIO) + 8) &0xFFFFFFFC);

	if (send_rpc_command(RPC_AUDIO, ENUM_KERNEL_RPC_AUDIO_CONFIG, phy_addr,
		phy_res, &ret)) {
		pr_err("rtkaudio: send(%s %d) fail %d\n", __FUNCTION__, cmd->msg_id, (int)ret);
		dvr_free((void *) dvr_addr);
		return 0;
	}
	//pr_info("phy_res=%x,vir_res=%x,  *vir_res=%d\n", phy_res, vir_res, *vir_res);
	//pr_info("phy_addr=%x,vir_audioConfig=%x,  \n", phy_res, vir_audioConfig);

	for (i=0;i<15;i++) {
		cmd->value[i] = ntohl(vir_audioConfig->value[i]);
	}
	ret = ntohl(*vir_res);

	dvr_free((void *) dvr_addr);
	return ret;
}


static long ioctl_set(struct cntl_info info, void *addr, int size)
{
	if (info.size != size) {
		pr_err("size error: (%x) <> (%x)\n", info.size, size);
		return -EFAULT;
	}

	if (copy_from_user(addr, (const void __user *)info.addr, size))
		return -EFAULT;

	return 0;
}

static long ioctl_get(struct cntl_info info, void *addr, int size)
{
	if (info.size != size) {
		pr_err("size error: (%x) <> (%x)\n", info.size, size);
		return -EFAULT;
	}

	if (copy_to_user((void __user *)info.addr, (const void*)addr, size))
		return -EFAULT;

	return 0;
}

long rtkaudio_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int ret = 0;

	pr_debug("rtkaudio: receive ioctl(cmd:0x%08x, arg:0x%08lx)\n",
		cmd, arg);

	switch (cmd) {
	case RTKAUDIO_IOC_INIT:
		blocking_notifier_call_chain(&rtkaudio_chain_head,
			RTKAUDIO_RESET_PREPARE, NULL);
		pr_debug("RTKAUDIO_IOC_INIT\n");
		blocking_notifier_call_chain(&rtkaudio_chain_head,
			RTKAUDIO_RESET_DONE, NULL);
		break;
	case RTKAUDIO_IOC_DEINIT:
		pr_debug("RTKAUDIO_IOCTL_DEINIT\n");
		break;
	case RTKAUDIO_IOC_OPEN:
		pr_debug("RTKAUDIO_IOCTL_OPEN\n");
		break;
	case RTKAUDIO_IOC_CLOSE:
		pr_debug("RTKAUDIO_IOCTL_CLOSE\n");
		break;
	case RTKAUDIO_IOC_CONNECT:
		pr_debug("RTKAUDIO_IOCTL_CONNECT\n");
		break;
	case RTKAUDIO_IOC_SET:
	{
		struct cntl_info info;
		pr_debug("RTKAUDIO_IOCTL_SET\n");
		if (copy_from_user((void*)&info, (const void __user*)arg, sizeof(info))) {
			ret = -EFAULT;
		}
		switch(info.resource_type) {
		case RESOURCE_STATUS:
			down(&resource_sem);
			ret = ioctl_set(info, &resource_st, sizeof(resource_st));
			up(&resource_sem);
			break;
		case MAIN_FLOW_STATUS:
			down(&main_flow_sem);
			ret = ioctl_set(info, &main_flow_st, sizeof(main_flow_st));
			up(&main_flow_sem);
			break;
		case SUB_FLOW_STATUS:
			down(&sub_flow_sem);
			ret = ioctl_set(info, &sub_flow_st, sizeof(sub_flow_st));
			up(&sub_flow_sem);
			break;
		case AIN_STATUS:
			down(&ain_sem);
			ret = ioctl_set(info, &ain_st, sizeof(ain_st));
			up(&ain_sem);
			break;
		case SE_STATUS:
			down(&se_sem);
			ret = ioctl_set(info, &se_st, sizeof(se_st));
			up(&se_sem);
			break;
		case AIN_AGENT_STATUS:
			down(&ain_agent_sem);
			ret = ioctl_set(info, &ain_agent_st, sizeof(ain_agent_st));
			up(&ain_agent_sem);
			break;
		case PPAO_AGENT_STATUS:
			down(&ppao_agent_sem);
			ret = ioctl_set(info, &ppao_agent_st, sizeof(ppao_agent_st));
			up(&ppao_agent_sem);
			break;
		case DECODER_STATUS:
			down(&decoder_st_sem);
			ret = ioctl_set(info, &decoder_st, sizeof(decoder_st));
			up(&decoder_st_sem);
			break;
		case MAIN_DECODER_STATUS:
			down(&main_dec_st_sem);
			ret = ioctl_set(info, &main_dec_st, sizeof(main_dec_st));
			up(&main_dec_st_sem);
			break;
		case ALSA_DEV_INFO:
			down(&alsa_info_sem);
			ret = ioctl_set(info, &alsa_info, sizeof(alsa_info));
			up(&alsa_info_sem);
			break;
		case GST_DEBUG_INFO:
		{
			struct gst_info gstinfo;
			struct list_head *list;
			struct rtkaudio_open_list *info_list;

			if (copy_from_user(&gstinfo, (const void __user *) info.addr,
				sizeof(struct gst_info))) {
				break;
			}

			down(&gst_debug_info_sem);
			down(&rtkaudio_open_info_list_sem);

			list_for_each(list, &rtkaudio_open_info_head) {
				info_list = list_entry(list, struct rtkaudio_open_list, open_list);
				if (info_list->pid == current->tgid) {
					info_list->info.gst_open = gstinfo.gst_open;
					info_list->info.decoded_size = gstinfo.decoded_size;
					info_list->info.undecoded_size = gstinfo.undecoded_size;
				}
			}

			up(&rtkaudio_open_info_list_sem);
			up(&gst_debug_info_sem);
			break;
		}
        case VIRTUALX_CMD_INFO:
        {
            dma_addr_t dat;
            void *p;
            struct RPC_PRI_PARAM *cmd, *cmd_audio;
            struct RPC_PRI_RET *res, *res_audio;

            virtualx_cmd_info virx_cmd;
            int *pSetting;
            int i;

            pr_debug("[Virtual X] %s\n", __func__);

            if (info.size != sizeof(virtualx_cmd_info))
            {
                ret = -EFAULT;
                break;
            }

			if (copy_from_user(&virx_cmd, (const void __user *) info.addr, info.size))
            {
                ret = -EFAULT;
				break;
			}

            p = dma_alloc_coherent(NULL, 4096, &dat, GFP_ATOMIC);
            if (!p) {
                pr_err("[Virtual X] %d alloc memory fail\n", __LINE__);
                ret = -ENOMEM;
                break;
            }

            down(&virtualx_cmd_sem);

            cmd = p;
            res = (struct RPC_PRI_RET *) ((((unsigned long)p +
                    sizeof(struct RPC_PRI_PARAM)+sizeof(virtualx_cmd_info)+8) & 0xFFFFFFFC));

            cmd_audio = (struct RPC_PRI_PARAM *)(dat|0xa0000000);
            res_audio = (struct RPC_PRI_RET *)
                            ((((unsigned long)(dat|0xa0000000) +
                            sizeof(struct RPC_PRI_PARAM)+sizeof(virtualx_cmd_info)+8) & 0xFFFFFFFC));

            memset(cmd, 0, sizeof(struct RPC_PRI_PARAM)+sizeof(virtualx_cmd_info));

            cmd->instance_id = htonl(0);
            cmd->type = htonl(ENUM_PRIVATEINFO_AUDIO_HANDLE_VIRTUAL_X_PARAM);
            cmd->pri_info[0] = htonl(virx_cmd.type);
            cmd->pri_info[1] = htonl(virx_cmd.size);

            pSetting = &cmd->pri_info[2];
            //memcpy(pSetting, &virx_cmd.data[0], virx_cmd.size);
            for (i = 0; i < virx_cmd.size/sizeof(unsigned int); i++)
            {
                pSetting[i] = htonl(virx_cmd.data[i]);
            }

            if (send_rpc_command(RPC_AUDIO,
                ENUM_KERNEL_RPC_PRIVATEINFO,
                (unsigned int) cmd_audio,
                (unsigned int) res_audio, &ret))
            {
                pr_err("[Virtual X] %s %d RPC fail %ld\n", __func__, __LINE__, ret);
                ret = -EFAULT;
            }

            if (ret != S_OK)
            {
                pr_err("[Virtual X] %s %d RPC is not S_OK %ld\n", __func__, __LINE__, ret);
                ret = -EFAULT;
            }

            virx_cmd.result= htonl(res->pri_info[0]);

            pSetting = &res->pri_info[2];
            for (i = 0; i < virx_cmd.size/sizeof(unsigned int); i++)
            {
                virx_cmd.data[i]= htonl(pSetting[i]);
            }

            up(&virtualx_cmd_sem);

            dma_free_coherent(NULL, 4096, p, dat);

			if (copy_to_user((void __user *) info.addr, &virx_cmd, info.size))
            {
				ret = -EFAULT;
			}

            break;
        }
		default:
			ret = -EFAULT;
		}
		break;
	}
	case RTKAUDIO_IOC_GET:
	{
		struct cntl_info info;
		pr_debug("RTKAUDIO_IOCTL_GET\n");
		if (copy_from_user((void*)&info, (const void __user*)arg, sizeof(info))) {
			ret = -EFAULT;
		}
		switch(info.resource_type) {
		case RESOURCE_STATUS:
			down(&resource_sem);
			ret = ioctl_get(info, &resource_st, sizeof(resource_st));
			up(&resource_sem);
			break;
		case MAIN_FLOW_STATUS:
			down(&main_flow_sem);
			ret = ioctl_get(info, &main_flow_st, sizeof(main_flow_st));
			up(&main_flow_sem);
			break;
		case SUB_FLOW_STATUS:
			down(&sub_flow_sem);
			ret = ioctl_get(info, &sub_flow_st, sizeof(sub_flow_st));
			up(&sub_flow_sem);
			break;
		case AIN_STATUS:
			down(&ain_sem);
			ret = ioctl_get(info, &ain_st, sizeof(ain_st));
			up(&ain_sem);
			break;
		case SE_STATUS:
			down(&se_sem);
			ret = ioctl_get(info, &se_st, sizeof(se_st));
			up(&se_sem);
			break;
		case AIN_AGENT_STATUS:
			down(&ain_agent_sem);
			ret = ioctl_get(info, &ain_agent_st, sizeof(ain_agent_st));
			up(&ain_agent_sem);
			break;
		case PPAO_AGENT_STATUS:
			down(&ppao_agent_sem);
			ret = ioctl_get(info, &ppao_agent_st, sizeof(ppao_agent_st));
			up(&ppao_agent_sem);
			break;
		case DECODER_STATUS:
			down(&decoder_st_sem);
			ret = ioctl_get(info, &decoder_st, sizeof(decoder_st));
			up(&decoder_st_sem);
			break;
		case MAIN_DECODER_STATUS:
			down(&main_dec_st_sem);
			ret = ioctl_get(info, &main_dec_st, sizeof(main_dec_st));
			up(&main_dec_st_sem);
			break;
		case ALSA_DEV_INFO:
			down(&alsa_info_sem);
			ret = ioctl_get(info, &alsa_info, sizeof(alsa_info));
			up(&alsa_info_sem);
			break;
		case GST_DEBUG_INFO:
		{
			struct gst_info gstinfo;
			struct list_head *list;
			struct rtkaudio_open_list *info_list;

			down(&gst_debug_info_sem);
			down(&rtkaudio_open_info_list_sem);

			list_for_each(list, &rtkaudio_open_info_head) {
				info_list = list_entry(list, struct rtkaudio_open_list, open_list);
				if (info_list->pid == current->tgid) {
					gstinfo.gst_open = info_list->info.gst_open;
					gstinfo.decoded_size = info_list->info.decoded_size;
					gstinfo.undecoded_size = info_list->info.undecoded_size;
				}
			}

			up(&rtkaudio_open_info_list_sem);
			up(&gst_debug_info_sem);

			if (copy_to_user((void __user *) info.addr, &gstinfo,
				sizeof(struct gst_info))) {
				ret = -EFAULT;
			}

			break;
		}
        case VIRTUALX_CMD_INFO:
        {
            dma_addr_t dat;
            void *p;
            struct RPC_PRI_PARAM *cmd, *cmd_audio;
            struct RPC_PRI_RET *res, *res_audio;

            virtualx_cmd_info virx_cmd;
            int *pSetting;
            int i;

            pr_debug("[Virtual X] %s\n", __func__);

            if (info.size != sizeof(virtualx_cmd_info))
            {
                ret = -EFAULT;
                break;
            }

			if (copy_from_user(&virx_cmd, (const void __user *) info.addr, info.size))
            {
                ret = -EFAULT;
				break;
			}

            p = dma_alloc_coherent(NULL, 4096, &dat, GFP_ATOMIC);
            if (!p) {
                pr_err("[Virtual X] %d alloc memory fail\n", __LINE__);
                ret = -ENOMEM;
                break;
            }

            down(&virtualx_cmd_sem);

            cmd = p;
            res = (struct RPC_PRI_RET *) ((((unsigned long)p +
                    sizeof(struct RPC_PRI_PARAM)+sizeof(virtualx_cmd_info)+8) & 0xFFFFFFFC));

            cmd_audio = (struct RPC_PRI_PARAM *)(dat|0xa0000000);
            res_audio = (struct RPC_PRI_RET *)
                            ((((unsigned long)(dat|0xa0000000) +
                            sizeof(struct RPC_PRI_PARAM)+sizeof(virtualx_cmd_info)+8) & 0xFFFFFFFC));

            memset(cmd, 0, sizeof(struct RPC_PRI_PARAM)+sizeof(virtualx_cmd_info));

            cmd->instance_id = htonl(0);
            cmd->type = htonl(ENUM_PRIVATEINFO_AUDIO_HANDLE_VIRTUAL_X_PARAM);
            cmd->pri_info[0] = htonl(virx_cmd.type);
            cmd->pri_info[1] = htonl(virx_cmd.size);

            pSetting = &cmd->pri_info[2];
            //memcpy(pSetting, &virx_cmd.data[0], virx_cmd.size);
            for (i = 0; i < virx_cmd.size/sizeof(unsigned int); i++)
            {
                pSetting[i] = htonl(virx_cmd.data[i]);
            }

            if (send_rpc_command(RPC_AUDIO,
                ENUM_KERNEL_RPC_PRIVATEINFO,
                (unsigned int) cmd_audio,
                (unsigned int) res_audio, &ret))
            {
                pr_err("[Virtual X] %s %d RPC fail %ld\n", __func__, __LINE__, ret);
                ret = -EFAULT;
            }

            if (ret != S_OK)
            {
                pr_err("[Virtual X] %s %d RPC is not S_OK %ld\n", __func__, __LINE__, ret);
                ret = -EFAULT;
            }

            virx_cmd.result= htonl(res->pri_info[0]);

            pSetting = &res->pri_info[2];
            for (i = 0; i < virx_cmd.size/sizeof(unsigned int); i++)
            {
                virx_cmd.data[i]= htonl(pSetting[i]);
            }

            up(&virtualx_cmd_sem);

            dma_free_coherent(NULL, 4096, p, dat);

			if (copy_to_user((void __user *) info.addr, &virx_cmd, info.size))
            {
				ret = -EFAULT;
			}

            break;
        }
		default:
			ret = -EFAULT;
		}
		break;
	}
	case RTKAUDIO_IOC_GET_ALL:
		pr_debug("RTKAUDIO_IOCTL_GET_ALL\n");
		break;
	case RTKAUDIO_IOC_FW_REMOTE_MALLOC_SUM:
	{
		struct ret_info *ret_s;
		struct ret_info __user *_ret_s = (struct ret_info *)arg;

		pr_debug("RTKAUDIO_IOC_FW_REMOTE_MALLOC_SUM\n");

		ret_s = kmalloc(sizeof(struct ret_info), GFP_KERNEL);

		if (ret_s == NULL) {
			pr_err ("[rtkaudio] malloc memory failed, %d\n", __LINE__);
			break;
		}

		rtkaudio_fw_remote_malloc_summary(ret_s);

		if (copy_to_user(_ret_s, ret_s, sizeof(struct ret_info)))
			ret = -EFAULT;

		kfree(ret_s);
		break;
	}
	case RTKAUDIO_IOC_ALLOC:
		pr_debug("RTKAUDIO_IOCTL_ALLOC\n");
		ret = rtkaudio_alloc(arg);
		break;
	case RTKAUDIO_IOC_FREE:
		pr_debug("RTKAUDIO_IOCTL_FREE\n");
		ret = rtkaudio_free(arg);
		break;
	case RTKAUDIO_IOC_ALLOC_SUM:
	{
		struct ret_info *ret_info;
		struct ret_info __user *_ret_info = (struct ret_info *)arg;

		pr_debug("RTKAUDIO_IOCTL_ALLOC_SUM\n");

		ret_info = kmalloc(sizeof(struct ret_info), GFP_KERNEL);
		if (ret_info == NULL) {
			pr_err ("[rtkaudio] malloc memory failed, %d\n", __LINE__);
			break;
		}

		rtkaudio_user_alloc_summary(ret_info);

		if (copy_to_user(_ret_info, ret_info, sizeof(struct ret_info)))
			ret = -EFAULT;

		kfree(ret_info);
		break;
	}
	case RTKAUDIO_IOC_AUDIO_CONFIG:
	{
		AUDIO_CONFIG_COMMAND_RTKAUDIO info;
		if (copy_from_user((void*)&info, (const void __user*)arg, sizeof(info))) {
			ret = -EFAULT;
			return ret;
		}
		ret = rtkaudio_send_audio_config(&info);
              if (ret != S_OK) {
			ret = -EFAULT;
              }
		if (copy_to_user((const void __user*)arg, (void*)&info, sizeof(info))) {
			ret = -EFAULT;
		}
		break;
	}
	case RTKAUDIO_IOC_READ_REG:
	{
		AUDIO_REGISTER_ACCESS_T info;

		if (copy_from_user((void*)&info, (const void __user*)arg, sizeof(info))) {
			ret = -EFAULT;
			return ret;
		}

		ret = read_register_by_type(&info);
		break;
	}
	case RTKAUDIO_IOC_WRITE_REG:
	{
		AUDIO_REGISTER_ACCESS_T info;

		if (copy_from_user((void*)&info, (const void __user*)arg, sizeof(info))) {
			ret = -EFAULT;
			return ret;
		}

		write_register_by_type(&info);
		break;
	}
	default:
		pr_info("rtkaudio: unknown ioctl(0x%08x)\n", cmd);
		break;
	};

	return ret;
}

void rtkaudio_help(void)
{
	pr_warn(" echo f > /dev/rtkaudio        ## print audio f/w alloc memory summary\n");
	pr_warn(" echo u > /dev/rtkaudio        ## print user space alloc memory summary\n");
	pr_warn(" echo dno > /dev/rtkaudio      ## debug: stop write debug file\n");
	pr_warn(" echo dlg > /dev/rtkaudio      ## debug: write audio log to file\n");
	/* pr_warn(" echo dpf > /dev/rtkaudio      ## debug: write pp focus data to file\n"); */
	/* pr_warn(" echo dop > /dev/rtkaudio      ## debug: write ao pcm data to file\n"); */
	/* pr_warn(" echo dor > /dev/rtkaudio      ## debug: write ao raw data to file\n"); */
	/* pr_warn(" echo d n > /dev/rtkaudio      ## debug: write self-define to file, 4 < n <= 9\n"); */
	pr_warn(" echo fw@ [s] > /dev/rtkaudio  ## debug: send a string [s] to f/w\n");
	pr_warn(" echo show res > /dev/rtkaudio ## print audio resource status\n");
	pr_warn(" echo show dec > /dev/rtkaudio ## print audio decoder status\n");
	pr_warn(" echo show main > /dev/rtkaudio ## print main decoder status\n");
}



ssize_t rtkaudio_write(struct file *filp,
	const char *buf, size_t count, loff_t *f_pos)
{
	long ret = count;
	char cmd_buf[100] = {0};

	pr_debug("%s(): count=%d, buf=0x%08lx\n", __func__, count, (long)buf);

	if (count >= 100)
		return -EFAULT;

	if (copy_from_user(cmd_buf, buf, count)){
		ret = -EFAULT;
	}

	if ((cmd_buf[0] == 'f') && (count == 2)) {
		pr_notice("\n=== rtkaudio: show f/w memory usage ===\n");
		rtkaudio_fw_remote_malloc_summary(NULL);
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'u') && (count == 2)) {
		pr_notice("\n=== rtkaudio: show usr memory usage ===\n");
		rtkaudio_user_alloc_summary(NULL);
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'd') && (count == 4)) {
		pr_notice("\n=== rtkaudio: debugging ===============\n");
		if((cmd_buf[1] == 'l') && (cmd_buf[2] == 'g'))
			rtkaudio_dump_enable(DUMP_LOG);
		else if ((cmd_buf[1] == 'p') && (cmd_buf[2] == 'f'))
			rtkaudio_dump_enable(DUMP_PP_FOCUS);
		else if ((cmd_buf[1] == 'o') && (cmd_buf[2] == 'p'))
			rtkaudio_dump_enable(DUMP_AO_PCM);
		else if ((cmd_buf[1] == 'o') && (cmd_buf[2] == 'r'))
			rtkaudio_dump_enable(DUMP_AO_RAW);
		else if ((cmd_buf[1] == ' ') && (simple_strtol(&cmd_buf[2], NULL, 10) > 4))
			rtkaudio_dump_enable(simple_strtol(&cmd_buf[2], NULL, 10));
		else if ((cmd_buf[1] == 'n') && (cmd_buf[2] == 'o'))
			rtkaudio_dump_disable(DUMP_STOP);
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'h') && (count == 2)) {
		pr_notice("\n=== rtkaudio write usage: =============\n");
		rtkaudio_help();
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'f') && (cmd_buf[1] == 'w') && (cmd_buf[2] == '@')) {
		pr_debug("\n=== rtkaudio: send debug string: =============\n");
		rtkaudio_send_string(&cmd_buf[4], (count-4)-1);
		pr_debug("\n=======================================\n");
	} else if ((cmd_buf[0] == 's') && (cmd_buf[1] == 'h') &&
			(cmd_buf[2] == 'o') && (cmd_buf[3] == 'w')) {
		if ((cmd_buf[5] == 'r') && (cmd_buf[6] == 'e') && (cmd_buf[7] == 's')) {
			show_resource(resource_st);
		} else if ((cmd_buf[5] == 'd') && (cmd_buf[6] == 'e') && (cmd_buf[7] == 'c')) {
			int i;
			for (i = 0; i < DEC_NUM; i++) {
				pr_warn("\n Decoder%d:\n", i);
				show_dec_status(decoder_st[i]);
			}
		} else if ((cmd_buf[5] == 'm') && (cmd_buf[6] == 'a') &&
			(cmd_buf[7] == 'i') && (cmd_buf[8] == 'n')) {
			show_main_decoder_status();
		} else if ((cmd_buf[5] == 'a') && (cmd_buf[6] == 'l') &&
			(cmd_buf[7] == 's') && (cmd_buf[8] == 'a')) {
			int i;
			pr_err("alsa card %d, alsa device %d\n", alsa_info.card, alsa_info.device);
			pr_err("gst refclock info %x, Register value %x\n", gst_refc_info, rtd_inl(GST_SHARED_REGISTER));
			pr_err("size %d, index %d\n", gst_refc_info->size, gst_refc_info->index);
			for (i = 0; i < refc_info_size; i++) {
				pr_err("clock addr %x, pid %d\n", gst_refc_info->info[i].phy_addr,
					gst_refc_info->info[i].pid);
			}
			pr_err("alsa card %d, alsa device %d\n",
				alsa_info.card, alsa_info.device);
		} else if ((cmd_buf[5] == 'g') && (cmd_buf[6] == 's') &&
			(cmd_buf[7] == 't') && (cmd_buf[8] == 'i') &&
			(cmd_buf[9] == 'n') && (cmd_buf[10] == 'f') &&
			(cmd_buf[11] == 'o')) {
				struct list_head *list;
				struct rtkaudio_open_list *open_info;

				down(&rtkaudio_open_info_list_sem);
				pr_err("rtkaudio_open_info_head %x\n", &rtkaudio_open_info_head);
				list_for_each(list, &rtkaudio_open_info_head) {
					open_info =
						list_entry(list, struct rtkaudio_open_list, open_list);
					pr_err("list %x, pid %d\n", list, open_info->pid);
				}
				up(&rtkaudio_open_info_list_sem);
		}
	} else if ((cmd_buf[0] == 'a') && (cmd_buf[1] == 'l') &&
			(cmd_buf[2] == 's') && (cmd_buf[3] == 'a')) {
		if ((cmd_buf[4] == 'c') && (cmd_buf[5] == 'a') &&
			(cmd_buf[6] == 'r') && (cmd_buf[7] == 'd')) {
			if ((int) cmd_buf[9] > 47 && (int) cmd_buf[9] < 56)
				alsa_info.card = (int) cmd_buf[9] - 48;
		} else if ((cmd_buf[4] == 'd') && (cmd_buf[5] == 'e') &&
			(cmd_buf[6] == 'v')) {
			if ((int) cmd_buf[8] > 47 && (int) cmd_buf[8] < 56)
				alsa_info.device = (int) cmd_buf[8] - 48;
		} else if ((cmd_buf[4] == 's') && (cmd_buf[5] == 'c') &&
			(cmd_buf[6] == 'a') && (cmd_buf[7] == 'n')) {
			alsa_info.card = 255;
		}
	} else if ((cmd_buf[0] == 'p') && (cmd_buf[1] == 'r') &&
			   (cmd_buf[2] == 'd') && (cmd_buf[3] == 'm') &&
			   (cmd_buf[4] == 'g') && (count == 8)) {
		if (cmd_buf[6] == '0')
			pr_to_dmesg_en = 0;
		else if (cmd_buf[6] == '1')
			pr_to_dmesg_en = 1;
	} else if ((cmd_buf[0] == 'd') && (cmd_buf[1] == 's') &&
			   (cmd_buf[2] == 'i') && (cmd_buf[3] == 'z') &&
			   (cmd_buf[4] == 'e') && (count == 8)) {
		if ((int) cmd_buf[6] > 47 && (int) cmd_buf[6] < 56)
			dump_size_scale = (int) cmd_buf[6] - 48;
		pr_err("dump_size_scale %d\n", dump_size_scale);
	} else if ((cmd_buf[0] == 'r') && (cmd_buf[1] == 'd') &&
			   (cmd_buf[2] == 'r') && (cmd_buf[3] == 'e') &&
			   (cmd_buf[4] == 'g')) {
		AUDIO_REGISTER_ACCESS_T info;
		char *ptr;
		char *endptr;

		ptr = cmd_buf+6;
		info.reg_type = DEBUG_REGISTER;
		info.reg_value = simple_strtol(ptr, &endptr, 16);

		pr_err("[rtkaudio] dbg read reg %x\n", info.reg_value);

		read_register_by_type(&info);
	} else if ((cmd_buf[0] == 'w') && (cmd_buf[1] == 't') &&
			   (cmd_buf[2] == 'r') && (cmd_buf[3] == 'e') &&
			   (cmd_buf[4] == 'g')) {
		AUDIO_REGISTER_ACCESS_T info;
		char *ptr;
		char *endptr;

		ptr = cmd_buf+6;
		info.reg_type = DEBUG_REGISTER;
		info.reg_value = simple_strtol(ptr, &endptr, 16);

		ptr = endptr+1;
		info.data = simple_strtol(ptr, &endptr, 16);

		pr_err("[rtkaudio] dbg write reg %x, value %x\n", info.reg_value, info.data);
		write_register_by_type(&info);
	} else {
		pr_notice("%s\n", cmd_buf);
	}

	return ret;
}

const struct file_operations rtkaudio_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = rtkaudio_ioctl,
	.write = rtkaudio_write,
	.open = rtkaudio_open,
	.release = rtkaudio_release,
};

static int rtkaudio_proc_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
	struct list_head *list;
	struct rtkaudio_open_list *info_list;
	char *str = kmalloc(4096, GFP_KERNEL);
	int len, total = 0;

	if (str == NULL) {
		pr_err ("[rtkaudio] malloc memory failed, %d\n", __LINE__);
		return 0;
	}

	len = sprintf(str, "gst_debug_info:\n");
	total += len;

	down(&rtkaudio_open_info_list_sem);
	list_for_each(list, &rtkaudio_open_info_head) {
		info_list = list_entry(list, struct rtkaudio_open_list, open_list);
		if (info_list->info.gst_open) {
			len = sprintf(str + total, "pid = %d\n", info_list->pid);
			total += len;
			len = sprintf(str + total, "undecoded_size = %llu\n",
				info_list->info.undecoded_size);
			total += len;
			len = sprintf(str + total, "decoded_size = %llu\n",
				info_list->info.decoded_size);
			total += len;
		}
	}
	up(&rtkaudio_open_info_list_sem);

	if (copy_to_user(buf, str, total)) {
		pr_err("rtkaudio:%d Copy proc data to user space failed\n", __LINE__);
		kfree(str);
		return 0;
	}

	if (*ppos == 0)
		*ppos += total;
	else
		total = 0;

	kfree(str);
	return total;
}

static const struct file_operations rtkaudio_proc_fops = {
	.owner = THIS_MODULE,
	.read = rtkaudio_proc_read,
};

static void rtkaudio_debug_proc_init(void)
{
	if (rtkaudio_proc_dir == NULL && rtkaudio_proc_entry == NULL) {
		rtkaudio_proc_dir = proc_mkdir(RTKAUDIO_PROC_DIR , NULL);

		if (rtkaudio_proc_dir != NULL) {
			rtkaudio_proc_entry =
				proc_create(RTKAUDIO_PROC_ENTRY, 0666,
					rtkaudio_proc_dir, &rtkaudio_proc_fops);

			if (rtkaudio_proc_entry == NULL) {
				proc_remove(rtkaudio_proc_dir);
				rtkaudio_proc_dir = NULL;
				pr_err("failed to get proc entry for %s/%s\n", RTKAUDIO_PROC_DIR, RTKAUDIO_PROC_ENTRY);
				return;
			}
		} else {
			pr_err("create rtkaudio dir proc entry (%s) failed\n",
				RTKAUDIO_PROC_DIR);
			return;
		}
	}
}

static void rtkaudio_debug_proc_uninit(void)
{
	if (rtkaudio_proc_entry) {
		proc_remove(rtkaudio_proc_entry);
		rtkaudio_proc_entry = NULL;
	}

	if (rtkaudio_proc_dir) {
		proc_remove(rtkaudio_proc_dir);
		rtkaudio_proc_dir = NULL;
	}
}

static char *rtkaudio_devnode(struct device *dev, mode_t *mode)
{
	*mode = 0666;
	return NULL;
}

static int rtkaudio_init(void)
{
	int result;
	unsigned long vir_addr = 0;
	unsigned long phy_addr = 0;
	dev_t dev = 0;
	unsigned long ret = S_OK;
	rtkaudio_class = NULL;
	rtkaudio_platform_devs = NULL;

	pr_info("rtkaudio: audio driver for Realtek TV Platform\n");

	if (rtkaudio_major) {
		dev = MKDEV(RTKAUDIO_MAJOR, 0);
		result = register_chrdev_region(dev, 1, "rtkaudio");
	} else {
		result = alloc_chrdev_region(&dev,
			rtkaudio_minor, 1, "rtkaudio");
		rtkaudio_major = MAJOR(dev);
	}
	if (result < 0) {
		pr_info("rtkaudio: can not get chrdev region...\n");
		return result;
	}

	rtkaudio_class = class_create(THIS_MODULE, "rtkaudio");
	if (IS_ERR(rtkaudio_class)) {
		pr_info("rtkaudio: can not create class...\n");
		result = PTR_ERR(rtkaudio_class);
		goto fail_class_create;
	}

	rtkaudio_class->devnode = rtkaudio_devnode;

	rtkaudio_platform_devs =
		platform_device_register_simple("rtkaudio", -1, NULL, 0);

	if (platform_driver_register(&rtkaudio_device_driver) != 0) {
		pr_info("rtkaudio: can not register platform driver...\n");
		result = -EINVAL;
		goto fail_platform_driver_register;
	}

	cdev_init(&rtkaudio_cdev, &rtkaudio_fops);
	rtkaudio_cdev.owner = THIS_MODULE;
	rtkaudio_cdev.ops = &rtkaudio_fops;
	result = cdev_add(&rtkaudio_cdev, dev, 1);
	if (result < 0) {
		pr_info("rtkaudio: can not add character device...\n");
		goto fail_cdev_init;
	}
	device_create(rtkaudio_class, NULL, dev, NULL, "rtkaudio");


	device_enable_async_suspend(&(rtkaudio_platform_devs->dev));

	INIT_LIST_HEAD(&remote_malloc_info_head);
	INIT_LIST_HEAD(&rtkaudio_alloc_head);
	INIT_LIST_HEAD(&rtkaudio_open_info_head);

	if (register_kernel_rpc(RPC_ACPU_REMOTE_MALLOC,
		rtkaudio_remote_malloc) == 1)
		pr_err("Register rtkaudio_remote_malloc failed!\n");
	if (register_kernel_rpc(RPC_ACPU_REMOTE_FREE,
		rtkaudio_remote_free) == 1)
		pr_err("Register rtkaudio_remote_free failed!\n");
	if (register_kernel_rpc(RPC_ACPU_FREE_USER_MEM,
		rtkaudio_free_user_mem) == 1)
		pr_err("Register rtkaudio_free_user_mem failed!\n");

	pr_info("rtkaudio: send REMOTE MELLOC ENABLE RPC\n");

	/******************** get audio version ********************/
	memset(AudioGITHASH, 0, 8);

	vir_addr = (unsigned long)dvr_malloc_specific(4096, GFP_DCU1);

	if ((void*)vir_addr == NULL) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		return -ENOMEM;
	}

	phy_addr = (unsigned long)dvr_to_phys((void*)vir_addr);
	if ((void*)phy_addr == NULL) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		if (vir_addr) {
			dvr_free((void*)vir_addr);
		}
		return -ENOMEM;
	}

	if ((phy_addr & 0xe0000000) != 0) {
		pr_err("[%s %d]get memory not between 0 ~ 512 MB\n", __func__, __LINE__);
		if (vir_addr) {
			dvr_free((void*)vir_addr);
		}
		return -ENOMEM;
	}
	/*************************************************************/

#if (defined(CONFIG_LG_SNAPSHOT_BOOT) && defined(CONFIG_CUSTOMER_TV006))
	if (snapshot_enable == 0) {
		/* send REMOTE MELLOC ENABLE RPC to Audio FW */
		if (send_rpc_command(RPC_AUDIO,
			RPC_ACPU_IS_REMOTE_MALLOC_ENABLE,
			REMOTE_MALLOC_ENABLE, phy_addr, &ret)) {
			pr_err("rtkaudio: REMOTE_MALLOC_ENABLE RPC fail %ld\n", ret);
		}

		rtkaudio_enable_tsk = kthread_create(rtkaudio_enable_thread, NULL,
				"rtkaudio_enable_thread");
		if (IS_ERR(rtkaudio_enable_tsk)) {
			rtkaudio_enable_tsk = NULL;
			return -1;
		}
		wake_up_process(rtkaudio_enable_tsk);
		control_status_init();
	}
#else
	/* send REMOTE MELLOC ENABLE RPC to Audio FW */
	if (send_rpc_command(RPC_AUDIO,
		RPC_ACPU_IS_REMOTE_MALLOC_ENABLE,
		REMOTE_MALLOC_ENABLE, phy_addr, &ret)) {
		pr_err("rtkaudio: REMOTE_MALLOC_ENABLE RPC fail %ld\n", ret);
	}

	rtkaudio_enable_tsk = kthread_create(rtkaudio_enable_thread, NULL,
			"rtkaudio_enable_thread");
	if (IS_ERR(rtkaudio_enable_tsk)) {
		rtkaudio_enable_tsk = NULL;
		return -1;
	}
	wake_up_process(rtkaudio_enable_tsk);
	control_status_init();
#endif

	/******************** get audio version ********************/
	memcpy(AudioGITHASH, (char *)vir_addr, 7);
	AudioGITHASH[7] = 0;
	dvr_free((void *) vir_addr);
	/***********************************************************/

	rtkaudio_proc_dir = NULL;
	rtkaudio_proc_entry = NULL;

	rtkaudio_debug_proc_init();

	/* enable print ADSP log to dmesg at init */
	pr_to_dmesg_en = 0;

	/* set dump log file init size to 1MB */
	dump_size_scale = 1;

	if (ret != S_OK)
		pr_err("rtkaudio: REMOTE_MALLOC_ENABLE RPC is not S_OK %ld\n", ret);

	return 0;

fail_cdev_init:
	platform_driver_unregister(&rtkaudio_device_driver);
fail_platform_driver_register:
	platform_device_unregister(rtkaudio_platform_devs);
	rtkaudio_platform_devs = NULL;
	class_destroy(rtkaudio_class);
fail_class_create:
	rtkaudio_class = NULL;
	unregister_chrdev_region(dev, 1);
	return result;
}

static void rtkaudio_exit(void)
{
	dev_t dev = MKDEV(rtkaudio_major, rtkaudio_minor);
	rtkaudio_debug_proc_uninit();

	if (rtkaudio_platform_devs == NULL)
		BUG();

	device_destroy(rtkaudio_class, dev);
	cdev_del(&rtkaudio_cdev);

	platform_driver_unregister(&rtkaudio_device_driver);
	platform_device_unregister(rtkaudio_platform_devs);
	rtkaudio_platform_devs = NULL;

	class_destroy(rtkaudio_class);
	rtkaudio_class = NULL;

	unregister_chrdev_region(dev, 1);
}

late_initcall(rtkaudio_init);
module_exit(rtkaudio_exit);
