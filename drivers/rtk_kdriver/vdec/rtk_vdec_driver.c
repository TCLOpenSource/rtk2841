#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
#include <linux/string.h>
#include <linux/proc_fs.h>

#include <rbus/cabac_p2_reg.h>
#include <rbus/codeblkreg_reg.h>
#include <rbus/dc_sys_reg.h>
#include <rbus/seg_reg.h>
#include <rbus/mvdblk_reg.h>
#include <rbus/rl_reg.h>
#include <rbus/predblk_reg.h>
#include <rbus/deblk_reg.h>
#include <rbus/sao_reg.h>
#include <rbus/cmprs_reg.h>

#include <rtk_kdriver/rtk_vdec.h>
#include "rtk_vdec_internal.h"
#include "rtk_vdec_svp.h"
#include <mach/rtk_platform.h>
#include <mach/system.h>
#include <rtk_kdriver/RPCDriver.h>
#include <linux/dma-mapping.h> /* dma_alloc_coherent */
#include <linux/pageremap.h>
#include <linux/kthread.h>
#include <linux/err.h> /* IS_ERR() PTR_ERR() */
#include <linux/delay.h>
#include <linux/time.h>
#include <linux/auth.h>
#ifdef CONFIG_LG_SNAPSHOT_BOOT
#include <linux/suspend.h>
#endif
#include <linux/freezer.h>
#include <rtk_dc_mt.h>

//#define SUPPORT_VCPU2_VERSION

/* SB2 monitor */
typedef struct sb2_dbg_param {
        int set_id; // which set to be use,range 1-8
        unsigned int cpu_flag[7]; // which cpu type to be set,0:all 1:a v:2 s:3 v2:4 k:5
        unsigned int start; // dbg start address,phy addr
        unsigned int end; // dbg end address,phy addr
        unsigned char operation; // the main operation of sb2 cmd,0:monitor 1:clear
        unsigned char rw;  // read & write monitor flag
        unsigned char str; // STR support flag
        unsigned int bit_mask; // bit mask param
} sb2_dbg_param;
extern int sb2_dbg_monitor (sb2_dbg_param *pParam);
extern int sb2_dbg_clear (sb2_dbg_param *pParam);

int rtkvdec_free(unsigned int phy_addr);
int rtkvdec_alloc(int size);

#if 0
/*[WOSQRTK-4745]fix logo garbage.*/
#include <rtk_kdriver/gal/rtk_gdma_export.h>
/*[WOSQRTK-6662]fix logo dealy time.*/
#include "tvscalercontrol/panel/panelapi.h"
bool bstoplogo_gdma = false;
extern int is_RTD_K2L(void);
#endif

#ifdef CONFIG_HIBERNATION
static int rtkvdec_suspend(struct device *dev);
static int rtkvdec_resume(struct device *dev);
#endif

#ifdef CONFIG_LG_SNAPSHOT_BOOT
extern unsigned int snapshot_enable;
#endif

static BLOCKING_NOTIFIER_HEAD(rtkvdec_chain_head);

static struct device *rtkvdec_device;
static struct class *rtkvdec_class = NULL;
static struct cdev rtkvdec_cdev;
static struct platform_device *rtkvdec_platform_devs = NULL;

static const struct dev_pm_ops rtkvdec_pm_ops = {
#ifdef CONFIG_HIBERNATION
	.freeze 	= rtkvdec_suspend,
	.thaw   	= rtkvdec_resume,
	.poweroff       = rtkvdec_suspend,
	.restore	= rtkvdec_resume,
#endif
};

static struct platform_driver rtkvdec_device_driver = {
	.driver = {
		.name   = "rtkvdec",
		.bus    = &platform_bus_type,
#ifdef CONFIG_PM
		.pm     = &rtkvdec_pm_ops,
#endif
	},
};

int rtkvdec_major =   RTKVDEC_MAJOR;
int rtkvdec_minor =   0;
int VideoCreatDone  = 0 ;
int VideoCreatDone2 = 0 ;
int VideoCreatFinish = 0 ;
unsigned char VideoGITHASH[8];
VDEC_VBM_MEM_LIST VMM_Memory[RTKVDEC_MAX_VMM_MEM_NUM] ;
unsigned long VMM_total = 0;
unsigned long VMM_start = 0;
unsigned long EncoderMemAddr  = 0;
unsigned int EncoderMemState = 0;
unsigned int notify_rtkvdec_release_pov = 0 ;

/* for record video fw remote malloc memory info */
static struct list_head vfw_remote_malloc_info_head;
static DEFINE_SEMAPHORE(vfw_buffer_list_sem);
static struct list_head vfw_remote_malloc_info_specific_head;
static DEFINE_SEMAPHORE(vfw_buffer_list_specific_sem);

/* for debug : dump video f/w log */
unsigned long g_pVideoDebugMemory[2] = {0,0} ;
unsigned long g_pVideoDumpMemory[2] = {0,0} ;
VDEC_DBG_STRUCT dbg_config[2];
struct file *file_videoDump[2] = {0,0} ;
unsigned long debugMemPhyAddr[2] ;
unsigned long debugMemVirtAddr[2] ;
unsigned long g_videoDumpMemPhyAddr[2] ;
unsigned long g_videoDumpMemVirtAddr[2] ;

static struct task_struct *rtkvdec_debug_tsk;
static int data;
static int rtkvdec_debug_thread(void *arg);

static struct task_struct *rtkvdec_debug_check_tsk;
static int rtkvdec_debug_check_data;
static int rtkvdec_debug_check_thread(void *arg);

static unsigned long long f_offset[2] = {0,0} ;
#define RTKVDEC_DUMP_FILE_MAX_SIZE (1024*1024)
int rtkvdec_dump_size_scale;
int rtkvdec_pr_to_dmesg_en;
#define DMESG_PRINT_MAX (1024)

/* for debug : dump es to file */
VDEC_DVR_MALLOC_STRUCT g_pDumpES_Send ;
VDEC_DVR_MALLOC_STRUCT g_pDumpES ;
VDEC_DBG_STRUCT DumpES_Config;
struct file *file_DumpES = 0 ;
static struct task_struct *rtkvdec_dumpes_tsk;
static int rtkvdec_dumpes_thread(void *arg);
static unsigned long long f_offset_dumpes = 0 ;

/* for send video create rpc */
static struct task_struct *rtkvdec_vcreate_tsk = NULL;
static int data2;
static int rtkvdec_vcreate_thread(void *arg);

/* for gstreamer frame info */
static struct list_head gst_frame_info_head;
static DEFINE_SEMAPHORE(gst_frame_info_list_sem);

/* for SVP memory manage */
VDEC_SVPMEM_LIST svp_Memory[RTKVDEC_MAX_SVPMEM_NUM] ;
static DEFINE_SEMAPHORE(svp_memory_sem);

/* for VBM memory manage */
VDEC_VBM_MEM_LIST VBM_Memory[RTKVDEC_MAX_VBM_MEM_NUM] ;
unsigned long VBM_total = 0;
unsigned long VBM_start = 0;
static DEFINE_SEMAPHORE(vbm_memory_sem);

/* for VEProt memory manage */
unsigned long VEProt_total = 0;
unsigned long VEProt_start = 0;
unsigned int  VEProt_gobs = 0;
unsigned int  VEProt_usage = 0;
VDEC_VEPROT_MEM_LIST VEProt_list[RTKVDEC_MAX_VEPROT_MEM_NUM];
static DEFINE_SEMAPHORE(veprot_memory_sem);

/* for Inband cobuf manage */
VDEC_SVPMEM_LIST IBBuf[RTKVDEC_MAX_IBBUF_NUM] ;

#define IBBUF_DEBUG_SB2_ID 7
#define IBBUF_DEBUG_SB2_CNT 2
static unsigned int ibbuf_debug_en = 0;
VDEC_SVPMEM_LIST IBBuf_dbg[RTKVDEC_MAX_IBBUF_NUM] ;
static DEFINE_SEMAPHORE(IBBuf_sem);

/* for record rtkvdec alloc info */
static struct list_head rtkvdec_alloc_head;
static DEFINE_SEMAPHORE(rtkvdec_alloc_sem);
static unsigned int rtkdev_free_flow_check = 0 ;

/* for debug : shared memory */
unsigned long SharedMemAddr ;
unsigned long SharedMemPhyAddr ;
unsigned long SharedMemVirtAddr ;
unsigned long vcpu1_is_crash = 0 ;

#if 0
//set tvb4 prority for OSD2 [WOSQRTK-4745]fix logo garbage
unsigned int org_tvb4_pro_1=0;
unsigned int org_tvb4_pro_2=0;
#define TVSB4_PRIORITY_VALUE 0x00000010
#include <rbus/rbus-DesignSpec-DC_SYSReg.h>
#include <rbus/rbus-DesignSpec-DC2_SYSReg.h>
#endif

void memory_debug_protect(unsigned int idx, unsigned int addr, unsigned int size)
{
	sb2_dbg_param sb2_dbg;

	if (idx >= IBBUF_DEBUG_SB2_CNT) {
		return;
	}

	memset((void *)&sb2_dbg, 0, sizeof(sb2_dbg_param));
	sb2_dbg.set_id = IBBUF_DEBUG_SB2_ID + idx;
	sb2_dbg.cpu_flag[0] = 1;
	sb2_dbg.cpu_flag[1] = 1;
	sb2_dbg.cpu_flag[2] = 1;
	sb2_dbg.cpu_flag[3] = 1;
	sb2_dbg.cpu_flag[4] = 1;
	sb2_dbg.cpu_flag[5] = 1;
	sb2_dbg.cpu_flag[6] = 1;
	sb2_dbg.start = addr;
	sb2_dbg.end = addr + size - 1;
	sb2_dbg.operation = 0;
	sb2_dbg.rw = 0; /* RW_FLAG_RW */
	sb2_dbg.str = 0; /* STR_FLAG_DFT == STR_FLAG_YES */
	sb2_dbg_monitor(&sb2_dbg);
}

void memory_debug_unprotect(unsigned int idx)
{
	sb2_dbg_param sb2_dbg;

	if (idx >= IBBUF_DEBUG_SB2_CNT) {
		return;
	}

	memset((void *)&sb2_dbg, 0, sizeof(sb2_dbg_param));
	sb2_dbg.set_id = IBBUF_DEBUG_SB2_ID + idx;
	sb2_dbg.str = 0; /* STR_FLAG_DFT == STR_FLAG_YES */
	sb2_dbg_clear(&sb2_dbg);
}

int register_rtkvdec_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&rtkvdec_chain_head, nb);
}
EXPORT_SYMBOL_GPL(register_rtkvdec_notifier);

int unregister_rtkvdec_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_unregister(&rtkvdec_chain_head, nb);
}
EXPORT_SYMBOL_GPL(unregister_rtkvdec_notifier);

int rtkvdec_notifier_call_chain(unsigned long val)
{
	int ret;

	ret = blocking_notifier_call_chain(&rtkvdec_chain_head, val, NULL);
	if (ret == NOTIFY_BAD)
		ret = -EINVAL;
	else
		ret = 0;

	return ret;
}

#ifdef CONFIG_HIBERNATION
static int rtkvdec_suspend(struct device *dev)
{
	rtkvdec_notifier_call_chain(RTKVDEC_SUSPEND);
	rtkvdec_notifier_call_chain(RTKVDEC_RESET_PREPARE);
	pr_info("rtkvdec: receive supend command\n");
	/* todo resetav_lock(1); */

	return 0;
}

extern struct device* get_avcpu_device_ptr(void);

static int rtkvdec_resume(struct device *dev)
{
	pr_err("Before rtkvdec_resume\n");
	device_pm_wait_for_dev(dev, get_avcpu_device_ptr());

	/* todo resetav_unlock(1); */
	pr_info("rtkvdec: receive resume command\n");
	rtkvdec_notifier_call_chain(RTKVDEC_RESET_DONE);
	rtkvdec_notifier_call_chain(RTKVDEC_RESUME);

	if(rtkvdec_vcreate_tsk != NULL)
		wake_up_process(rtkvdec_vcreate_tsk);

	return 0;
}
#endif

void rtkvdec_fw_remote_malloc_summary(ret_info_t *info) {
	unsigned long sum_request, sum_malloc;
	struct list_head *list;
	buffer_info_t *buf_info;
	int i = 0 ;

	memory_info_t *mem_info;

	sum_malloc = 0;
	sum_request = 0;

	pr_notice("\nVBM chunk:\n");
	for (i = 0; i < RTKVDEC_MAX_VBM_MEM_NUM; i++) {
		pr_notice("VBM chunk[%d]%d %lx %x\n", i, VBM_Memory[i].used, VBM_Memory[i].addr, VBM_Memory[i].size);
	}

	down(&vfw_buffer_list_sem);

	pr_notice("\nDCU1:\n");
	list_for_each(list, &vfw_remote_malloc_info_head) {
		buf_info = list_entry(list, buffer_info_t, buffer_list);
		pr_notice("vir_addr %lx, phy_addr %lx, request_size %lx, malloc_size %lx\n", buf_info->vir_addr, buf_info->phy_addr, buf_info->request_size, buf_info->malloc_size);
		sum_request += buf_info->request_size;
		sum_malloc += buf_info->malloc_size;
	}
	up(&vfw_buffer_list_sem);

	pr_notice("\nsum_malloc %ld, sum_request %ld\n", sum_malloc, sum_request);

	pr_notice("\nDCU2:\n");
	down(&vfw_buffer_list_specific_sem);
	list_for_each(list, &vfw_remote_malloc_info_specific_head) {
		mem_info = list_entry(list, memory_info_t, memory_list);
		if (mem_info->dcu == RTKVDEC_DCU2) {
			pr_notice("phy_addr %lx, alloc_size %lx\n", mem_info->phy_addr, mem_info->malloc_size);
		}
	}
	pr_notice("\nDCU1:\n");
	list_for_each(list, &vfw_remote_malloc_info_specific_head) {
		mem_info = list_entry(list, memory_info_t, memory_list);
		if (mem_info->dcu == RTKVDEC_DCU1) {
			pr_notice("phy_addr %lx, alloc_size %lx\n", mem_info->phy_addr, mem_info->malloc_size);
		}
	}
	pr_notice("\nVEPROT_ALLOC:\n");
	if (VEProt_total != 0) {
		pr_notice("VEProt start %lx, total %lx, gobs %d, mask %x\n", VEProt_start, VEProt_total, VEProt_gobs, VEProt_usage);
		for (i = 0; i < RTKVDEC_MAX_VEPROT_MEM_NUM; i++) {
			if (VEProt_list[i].addr)
				pr_notice("[%d]%x %lx %x\n", i, VEProt_list[i].mask, VEProt_list[i].addr, VEProt_list[i].size);
		}
	}
	else {
		list_for_each(list, &vfw_remote_malloc_info_specific_head) {
			mem_info = list_entry(list, memory_info_t, memory_list);
			if (mem_info->dcu == RTKVDEC_VEPROT_ALLOC) {
				pr_notice("phy_addr %lx, alloc_size %lx\n", mem_info->phy_addr, mem_info->malloc_size);
			}
		}
	}
	up(&vfw_buffer_list_specific_sem);

	pr_notice("\nVideoCreatMemAddr:\n") ;
	for (i = 0; i < RTKVDEC_MAX_VMM_MEM_NUM; i++) {
		pr_notice("VMM chunk[%d]%d %lx %x\n", i, VMM_Memory[i].used, VMM_Memory[i].addr, VMM_Memory[i].size);
	}

	pr_notice("\nEncoderMemAddr:\n") ;
	pr_notice("phy_addr %lx, state %d\n", EncoderMemAddr, EncoderMemState);

	if (info == NULL) return;

	info->private_info[0] = sum_request;
	info->private_info[1] = sum_malloc;
}

unsigned int rtkvdec_remote_malloc(unsigned long para1, unsigned long para2)
{
	unsigned long vir_addr = 0 , vir_addr_noncache = 0 ;
	unsigned long phy_addr = 0 ;
	unsigned int i;
	buffer_info_t *buf_info;
	size_t size ;

	pr_debug("Inside rtkvdec_remote_malloc(%x/%x)\n", (unsigned int)para1, (unsigned int)para2);

	if (para1 & 0x80000000) {
		size = para1 & 0x7fffffff;
		if (VBM_total >= size) {
			for (i = 0; i < RTKVDEC_MAX_VBM_MEM_NUM; i++) {
				if ( VBM_Memory[i].used == 0 ) {
					phy_addr = VBM_Memory[i].addr = (i == 0)? VBM_start : VBM_Memory[i-1].addr + VBM_Memory[i-1].size ;
					VBM_Memory[i].size = size ;
					VBM_Memory[i].used = 1 ;
					VBM_total -= size ;
					return phy_addr ;
				}
			}
		}
		if (!phy_addr) {
			pr_err("[%s %d]alloc VBM fail %x\n", __func__, __LINE__, (unsigned int)para1);
			pr_err("\nVBM chunk:\n");
			for (i = 0; i < RTKVDEC_MAX_VBM_MEM_NUM; i++) {
				pr_err("VBM chunk[%d]%d %lx %x\n", i, VBM_Memory[i].used, VBM_Memory[i].addr, VBM_Memory[i].size);
			}
			BUG();
			return 0;
		}
	}
	else {
		if (!vir_addr) {
			vir_addr = (unsigned long)dvr_malloc_uncached_specific(para1 & 0x7fffffff, GFP_DCU1, (void **)&vir_addr_noncache);
		}
		phy_addr = (unsigned long)dvr_to_phys((void*)vir_addr);
	}

	if (!phy_addr) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		return 0;
	}

	buf_info = (buffer_info_t *)kmalloc(sizeof(buffer_info_t), GFP_KERNEL);
	INIT_LIST_HEAD(&buf_info->buffer_list);

	buf_info->vir_addr = vir_addr;
	buf_info->phy_addr = phy_addr;
	buf_info->request_size = para1;
	buf_info->malloc_size = PAGE_ALIGN(para1);

	if ((phy_addr & 0xe0000000) != 0)
		pr_err("[%s %d]get memory not between 0 ~ 512 MB\n", __func__, __LINE__);

	pr_debug("dvr_malloc_uncached_specific addr %lx\n", phy_addr);

	down(&vfw_buffer_list_sem);
	list_add(&buf_info->buffer_list, &vfw_remote_malloc_info_head);
	up(&vfw_buffer_list_sem);

	phy_addr = phy_addr | 0x80000000 ;
	return phy_addr;
}

unsigned int rtkvdec_remote_free(unsigned long para1, unsigned long para2)
{
	unsigned long vir_addr ;
	struct list_head *del_list;
	buffer_info_t *buf_info;
	int free_OK = 0 ;

	int i = 0;

	pr_debug("Inside rtkvdec_remote_free(%x/%x)\n", (unsigned int)para1, (unsigned int)para2);

	for (i = 0; i < RTKVDEC_MAX_VBM_MEM_NUM ; i++) {
		if (para1 == VBM_Memory[i].addr) {
			VBM_total += VBM_Memory[i].size ;
			VBM_Memory[i].addr =
			VBM_Memory[i].size =
			VBM_Memory[i].used = 0 ;
			return 0;
		}
	}

	down(&vfw_buffer_list_sem);
	list_for_each(del_list, &vfw_remote_malloc_info_head) {
		buf_info = list_entry(del_list, buffer_info_t, buffer_list);
		if (buf_info->phy_addr == para1) {
			vir_addr = buf_info->vir_addr;
			list_del(del_list);
			kfree(buf_info);
			dvr_free((void *)vir_addr);
			free_OK = 1 ;
			break;
		}
	}
	up(&vfw_buffer_list_sem);

	if (!free_OK) {
		pr_err("rtkvdec_remote_free : not found!!!(%x)\n", (unsigned int)para1);
		rtkvdec_fw_remote_malloc_summary(NULL);
	}

	return 0;
}

unsigned long rtkvdec_veprot_alloc(unsigned long alloc_size)
{
	int i, min, max, last_i ;
	unsigned int blocks = 0 ;
	unsigned int block_mask = 0 ;
	unsigned long phy_addr = 0 ;

	blocks = ((alloc_size + RTKVDEC_VEPROT_BLOCK_SIZE - 1) & (~(RTKVDEC_VEPROT_BLOCK_SIZE - 1))) / RTKVDEC_VEPROT_BLOCK_SIZE ;
	block_mask = (1 << blocks) - 1 ;
	min = 255 ;
	max = last_i = -1 ;

	down(&veprot_memory_sem);
	if (alloc_size < 0x500000) {
		for (i = 0; i < (VEProt_gobs - blocks + 1) ; i++)
			if (0 == (VEProt_usage & (block_mask << i)))
			    min = (min < i)? min : i ;

		if (min != 255)
			last_i = min ;
	}
	else {
		for (i = 0; i < (VEProt_gobs - blocks + 1) ; i++)
			if (0 == (VEProt_usage & (block_mask << i)))
			    max = (max > i)? max : i ;

		if (max != -1)
			last_i = max ;
	}

	if (last_i == -1) {
		pr_err("[%s %d] no free memory! show status :\n", __func__, __LINE__);
		pr_err("VEProt start %lx, total %lx, gobs %d, mask %x\n", VEProt_start, VEProt_total, VEProt_gobs, VEProt_usage);
		for (i = 0; i < RTKVDEC_MAX_VEPROT_MEM_NUM; i++) {
			if (VEProt_list[i].addr)
				pr_err("[%d]%x %lx %x\n", i, VEProt_list[i].mask, VEProt_list[i].addr, VEProt_list[i].size);
		}
		up(&veprot_memory_sem);
		return 0 ;
	}

	for (i = 0; i < RTKVDEC_MAX_VEPROT_MEM_NUM ; i++){
		if (VEProt_list[i].addr == 0) {
			VEProt_list[i].mask = block_mask << last_i ;
			VEProt_list[i].addr = phy_addr = VEProt_start + last_i * RTKVDEC_VEPROT_BLOCK_SIZE ;
			VEProt_list[i].size = alloc_size ;
			VEProt_usage |= VEProt_list[i].mask ;
			break ;
		}
	}

	up(&veprot_memory_sem);
	return phy_addr ;
}

unsigned long rtkvdec_veprot_free(unsigned long addr)
{
	int i ;
	down(&veprot_memory_sem);
	for (i = 0; i < RTKVDEC_MAX_VEPROT_MEM_NUM ; i++){
		if (VEProt_list[i].addr == addr) {
			VEProt_usage &= ~VEProt_list[i].mask ;
			VEProt_list[i].mask =
			VEProt_list[i].addr =
			VEProt_list[i].size = 0 ;
			break ;
		}
	}
	up(&veprot_memory_sem);
	return 0 ;
}

unsigned int rtkvdec_remote_malloc_specific(unsigned long para1, unsigned long para2)
{
	unsigned long phy_addr = 0 ;
	unsigned int i;
	memory_info_t *mem_info;
	unsigned int DCU = 0;
	size_t size ;

	pr_debug("Inside rtkvdec_remote_malloc_specific(%x/%x)\n", (unsigned int)para1, (unsigned int)para2);

	if (para1 == RTKVDEC_VCREATE_ALLOC) {
		size = (para2 + 0x3FF) & ~0x3FF ;
		if (VMM_total >= para2) {
			for (i = 0; i < RTKVDEC_MAX_VMM_MEM_NUM; i++) {
				if ( VMM_Memory[i].used == 0 ) {
					phy_addr = VMM_Memory[i].addr = (i == 0)? VMM_start : VMM_Memory[i-1].addr + VMM_Memory[i-1].size ;
					VMM_Memory[i].size = size ;
					VMM_Memory[i].used = 1 ;
					VMM_total -= size ;
					return phy_addr ;
				}
			}
		}
		if (!phy_addr) {
			pr_err("[%s %d]alloc VMM fail %x\n", __func__, __LINE__, (unsigned int)para2);
			pr_err("\nVBM chunk:\n");
			for (i = 0; i < RTKVDEC_MAX_VMM_MEM_NUM; i++) {
				pr_err("VMM chunk[%d]%d %lx %x\n", i, VMM_Memory[i].used, VMM_Memory[i].addr, VMM_Memory[i].size);
			}
			BUG();
			return 0;
		}
	}
	else if (para1 == RTKVDEC_ENCODER_ALLOC) {
		if (para2 <= 0x80000) {
			if(EncoderMemAddr && EncoderMemState == 0) {
				phy_addr = EncoderMemAddr ;
				EncoderMemState = 1 ;
			}
			else {
				pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
				return 0 ;
			}
		}
		else {
			pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
			return 0 ;
		}
	}
	else {
		if (para1 == RTKVDEC_DCU1 || para1 == RTKVDEC_DCU1_FIRST) {
			phy_addr = pli_malloc(para2, GFP_DCU1);
			if (phy_addr == INVALID_VAL && para1 == RTKVDEC_DCU1) {
				pr_warn("[%s %d]alloc DCU1 memory fail\n", __func__, __LINE__);
				return 0;
			}
			else if (phy_addr == INVALID_VAL) {
				pr_warn("[%s %d]alloc DCU1 memory fail, alloc DCU2\n", __func__, __LINE__);
				phy_addr = pli_malloc(para2, GFP_DCU2);
				if (phy_addr == INVALID_VAL) {
					pr_warn("[%s %d]alloc DCU2 memory fail\n", __func__, __LINE__);
					return 0;
				}
				DCU = RTKVDEC_DCU2 ;
			}
			else
				DCU = RTKVDEC_DCU1 ;
		}
		else if (para1 == RTKVDEC_DCU2 || para1 == RTKVDEC_DCU2_FIRST) {
			phy_addr = pli_malloc(para2, GFP_DCU2);
			if (phy_addr == INVALID_VAL && para1 == RTKVDEC_DCU2) {
				pr_warn("[%s %d]alloc DCU2 memory fail\n", __func__, __LINE__);
				return 0;
			}
			else if (phy_addr == INVALID_VAL) {
				pr_warn("[%s %d]alloc DCU2 memory fail, alloc DCU1\n", __func__, __LINE__);
				phy_addr = pli_malloc(para2, GFP_DCU1);
				if (phy_addr == INVALID_VAL) {
					pr_warn("[%s %d]alloc DCU1 memory fail\n", __func__, __LINE__);
					return 0;
				}
				DCU = RTKVDEC_DCU1 ;
			}
			else
				DCU = RTKVDEC_DCU2 ;
		}
		else if (para1 == RTKVDEC_VEPROT_ALLOC) {
			if (VEProt_total != 0) {
				/* allocate from carved out */
				if(VEProt_total < para2) {
					pr_err("[%s %d]alloc size(%lx) > VEProt_total(%lx)!\n", __func__, __LINE__, para2, VEProt_total);
					return 0;
				}
				if(0 == (phy_addr = rtkvdec_veprot_alloc(para2))) {
					pr_err("[%s %d]alloc veport memory fail\n", __func__, __LINE__);
					return 0;
				}
				return phy_addr ;
			}
			else {
				phy_addr = pli_malloc(para2, GFP_DCU2);

				if (phy_addr == INVALID_VAL) {
					pr_err("[%s %d]alloc DCU2 memory fail\n", __func__, __LINE__);
					return 0;
				}
				else
					DCU = RTKVDEC_VEPROT_ALLOC ;
				/* need add protect */
			}
		}

		mem_info = (memory_info_t *)kmalloc(sizeof(memory_info_t), GFP_KERNEL);
		INIT_LIST_HEAD(&mem_info->memory_list);

		mem_info->dcu = DCU;
		mem_info->phy_addr = phy_addr;
		mem_info->request_size = para2;
		mem_info->malloc_size = PAGE_ALIGN(para2);

		pr_debug("pli_malloc addr %lx\n", phy_addr);

		down(&vfw_buffer_list_specific_sem);
		list_add(&mem_info->memory_list, &vfw_remote_malloc_info_specific_head);
		up(&vfw_buffer_list_specific_sem);
	}

	return phy_addr;
}

unsigned int rtkvdec_remote_free_specific(unsigned long para1, unsigned long para2)
{
	struct list_head *del_list;
	memory_info_t *mem_info;
	int free_OK = 0 ;
	int i = 0;

	pr_debug("Inside rtkvdec_remote_free(%x/%x)\n", (unsigned int)para1, (unsigned int)para2);

	for (i = 0; i < RTKVDEC_MAX_VMM_MEM_NUM ; i++) {
		if (para1 == VMM_Memory[i].addr) {
			VMM_total += VMM_Memory[i].size ;
			VMM_Memory[i].addr =
			VMM_Memory[i].size =
			VMM_Memory[i].used = 0 ;
			return 0;
		}
	}

	if (para1 == EncoderMemAddr) {
		EncoderMemState = 0;
		return 0;
	}

	if (VEProt_total != 0 && para1 >= VEProt_start && para1 < (VEProt_start + VEProt_total) ) {
		/* free from carved out */
		rtkvdec_veprot_free(para1);
		return 0;
	}

	down(&vfw_buffer_list_specific_sem);
	list_for_each(del_list, &vfw_remote_malloc_info_specific_head) {
		mem_info = list_entry(del_list, memory_info_t, memory_list);
		if (mem_info->phy_addr == para1) {
			if (mem_info->dcu == RTKVDEC_VEPROT_ALLOC) {
				/* need remove protect */
			}
			list_del(del_list);
			kfree(mem_info);
			pli_free(para1);
			free_OK = 1 ;
			break;
		}
	}
	up(&vfw_buffer_list_specific_sem);

	if (!free_OK) {
		pr_err("rtkvdec_remote_free_specific : not found!!!(%x)\n", (unsigned int)para1);
		rtkvdec_fw_remote_malloc_summary(NULL);
	}

	return 0;
}

void rtkvdec_show_kstate(void)
{
	int i ;
	for (i = 0; i < RTKVDEC_MAX_SVPMEM_NUM; i++) {
		pr_err("svp_Memory[%d] : addr(%x) size(%x)\n", i, svp_Memory[i].addr, svp_Memory[i].size);
		pr_err("                 pid(%d) used(%d) u_8M(%d) u12M(%d) u16M(%d) Prot(%d)\n", svp_Memory[i].pid, svp_Memory[i].used, svp_Memory[i].used_8M, svp_Memory[i].used_12M, svp_Memory[i].used_16M, svp_Memory[i].protected);
	}
	pr_notice("\n");
	for (i = 0; i < RTKVDEC_MAX_IBBUF_NUM; i++) {
		pr_err("IBBuf[%d]%d %d %x %x\n", i, IBBuf[i].pid, IBBuf[i].used, IBBuf[i].addr, IBBuf[i].size);
		pr_err("  dbg[%d]%d %d %x %x\n", i, IBBuf_dbg[i].pid, IBBuf_dbg[i].used, IBBuf_dbg[i].addr, IBBuf_dbg[i].size);
	}
}

int rtkvdec_cobuffer_alloc(VDEC_COBUF_TYPE type, int port)
{
	int addr = 0 ;
	int i ;

	switch(type)
	{
		case VDEC_SVP_BUF:
		{
			down(&svp_memory_sem);
			if (svp_Memory[0].used == 0 && svp_Memory[0].addr != 0 && svp_Memory[1].used == 0 && svp_Memory[1].addr != 0) {
				addr = svp_Memory[0].addr ;
				svp_Memory[0].pid = svp_Memory[1].pid = port ;
				svp_Memory[0].used = svp_Memory[1].used = 1 ;
				svp_Memory[0].used_8M = 1 ;
			}
			else if (svp_Memory[2].used == 0 && svp_Memory[2].addr != 0 && svp_Memory[3].used == 0 && svp_Memory[3].addr != 0) {
				addr = svp_Memory[2].addr ;
				svp_Memory[2].pid = svp_Memory[3].pid = port ;
				svp_Memory[2].used = svp_Memory[3].used = 1 ;
				svp_Memory[2].used_8M = 1 ;
			}
			else if (svp_Memory[1].used == 0 && svp_Memory[1].addr != 0 && svp_Memory[2].used == 0 && svp_Memory[2].addr != 0) {
				addr = svp_Memory[1].addr ;
				svp_Memory[1].pid = svp_Memory[2].pid = port ;
				svp_Memory[1].used = svp_Memory[2].used = 1 ;
				svp_Memory[1].used_8M = 1 ;
			}
			up(&svp_memory_sem);

			if (addr == 0) {
				pr_err("rtkvdec : no free SVP Memory!!!\n");
			}
			break;
		}
		case VDEC_INBAND_BUF:
		{
			down(&IBBuf_sem);
			for (i = 0; i < RTKVDEC_MAX_IBBUF_NUM; i++) {
				if (IBBuf[i].used == 0 && IBBuf[i].addr != 0) {
					addr = IBBuf[i].addr ;
					IBBuf[i].pid = port ;
					IBBuf[i].used = 1 ;
					if (ibbuf_debug_en && IBBuf_dbg[i].used == 0 && IBBuf_dbg[i].addr == 0) {
						IBBuf_dbg[i].addr = rtkvdec_alloc(4096);
						IBBuf_dbg[i].size = 4096 ;
						IBBuf_dbg[i].pid = port ;
						IBBuf_dbg[i].used = 1 ;
						memory_debug_protect(i, IBBuf_dbg[i].addr, 4096);
						pr_notice("rtkvdec: alloc IB debug mem 0x%x\n", IBBuf_dbg[i].addr);
					}
					break ;
				}
			}
			up(&IBBuf_sem);

			if (i == RTKVDEC_MAX_IBBUF_NUM && addr == 0) {
				pr_err("rtkvdec : no free IB Buffer!!!\n");
			}
			break;
		}
		default:
		{
			pr_debug("rtkvdec_cobuffer_alloc: unknown COBUF type(%d)\n", type);
			break;
		}
	}
	return addr ;
}

int rtkvdec_cobuffer_free(VDEC_COBUF_TYPE type, unsigned int phy_addr)
{
	int i ;
	switch(type)
	{
		case VDEC_SVP_BUF:
		{
			down(&svp_memory_sem);
			for (i = 0; i < RTKVDEC_MAX_SVPMEM_NUM; i++) {
				if (svp_Memory[i].addr == phy_addr) {
					svp_Memory[i].used = 0 ;
					svp_Memory[i].pid = 0 ;
					if (svp_Memory[i].protected == 1) {
						if (rtkvdec_svp_disable_cpb_protection(svp_Memory[i].addr, svp_Memory[i].size) != 0) {
							pr_err("rtkvdec: failed to disable cpb protection\n");
						}
						svp_Memory[i].protected = 0;
					}
					if (svp_Memory[i].used_8M && i < 3) {
						svp_Memory[i].used_8M = 0 ;
						svp_Memory[i+1].used = 0 ;
						svp_Memory[i+1].pid = 0 ;
					}
					break ;
				}
			}
			up(&svp_memory_sem);
			break;
		}
		case VDEC_INBAND_BUF:
		{
			down(&IBBuf_sem);
			for (i = 0; i < RTKVDEC_MAX_IBBUF_NUM; i++) {
				if (IBBuf[i].addr == phy_addr) {
					IBBuf[i].used = 0 ;
					IBBuf[i].pid = 0 ;
					if (IBBuf_dbg[i].used && IBBuf_dbg[i].addr != 0) {
						pr_notice("rtkvdec: free IB debug mem 0x%x\n", IBBuf_dbg[i].addr);
						memory_debug_unprotect(i);
						rtkvdec_free(IBBuf_dbg[i].addr);
						IBBuf_dbg[i].addr = 0 ;
						IBBuf_dbg[i].size = 0 ;
						IBBuf_dbg[i].used = 0 ;
						IBBuf_dbg[i].pid = 0 ;
					}
					break ;
				}
			}
			up(&IBBuf_sem);
			break ;
		}
		default:
		{
			pr_debug("rtkvdec_cobuffer_free: unknown COBUF type(%d)\n", type);
			break;
		}
	}

	return 0 ;
}

void rtkvdec_SVP_memory_init(void)
{
	int i;
	unsigned int size = 0 ;
	unsigned int addr = 0 ;

	size = (unsigned int)carvedout_buf_query(CARVEDOUT_VDEC_RINGBUF, (void *)&addr) ;
	pr_notice("rtkvdec_SVP_memory_init %x %x\n", addr, size);
	if (addr == 0 || size == 0) {
		pr_err("[%s %d] ERR : %x %x\n", __func__, __LINE__, addr, size);
		BUG();
	}

	for (i = 0; i < RTKVDEC_MAX_SVPMEM_NUM; i++) {
		svp_Memory[i].pid  = 0 ;
		svp_Memory[i].used = 0 ;
		svp_Memory[i].addr = 0 ;
		svp_Memory[i].size = 0 ;
	}

	for (i = 0; i < RTKVDEC_MAX_SVPMEM_NUM; i++) {
		if (size >= RTKVDEC_SVPMEM_SIZE_4M) {
			svp_Memory[i].addr = addr ;
			svp_Memory[i].size = RTKVDEC_SVPMEM_SIZE_4M ;
			size -= RTKVDEC_SVPMEM_SIZE_4M ;
			addr += RTKVDEC_SVPMEM_SIZE_4M ;
		}
		else if (size != 0) {
			svp_Memory[i].addr = addr ;
			svp_Memory[i].size = size ;
			size = 0 ;
			addr += size ;
		}
	}
}

void rtkvdec_VMM_memory_init(void)
{
	int i;

	for (i = 0; i < RTKVDEC_MAX_VMM_MEM_NUM; i++) {
		VMM_Memory[i].used = 0 ;
		VMM_Memory[i].addr = 0 ;
		VMM_Memory[i].size = 0 ;
	}

#ifdef SUPPORT_VCPU2_VERSION
	VMM_total = 0x800000 ;
#else
	VMM_total = 0x300000 ;
#endif
	VMM_start = rtkvdec_remote_malloc(VMM_total, 0x90ABCDEF) ;
	pr_notice("rtkvdec_VMM_memory_init %lx %lx\n", VMM_start, VMM_total);
	if (VMM_start == 0) {
		pr_err("[%s %d] ERR : %lx %lx\n", __func__, __LINE__, VMM_start, VMM_total);
		BUG();
	}
}

void rtkvdec_VBM_memory_init(void)
{
	int i;
	unsigned int tmp ;

	for (i = 0; i < RTKVDEC_MAX_VBM_MEM_NUM; i++) {
		VBM_Memory[i].used = 0 ;
		VBM_Memory[i].addr = 0 ;
		VBM_Memory[i].size = 0 ;
	}

	VBM_total = (unsigned int)carvedout_buf_query(CARVEDOUT_VDEC_VBM, (void *)&VBM_start) ;
#ifdef CONFIG_LG_SNAPSHOT_BOOT
	register_cma_forbidden_region(__phys_to_pfn(VDEC_BUFFER_START), VBM_total);
#endif
	pr_notice("rtkvdec_VBM_memory_init %lx %lx\n", VBM_start, VBM_total);
	if (VBM_start == 0 || VBM_total == 0) {
		pr_err("[%s %d] ERR : %lx %lx\n", __func__, __LINE__, VBM_start, VBM_total);
		BUG();
	}
	/******************** get Video version ********************/
	tmp = rtd_inl(RTKVDEC_DUMMY_VBM_SIZE);
	snprintf(VideoGITHASH, 8, "%x", tmp);
	pr_notice("Video FW Version %s\n", VideoGITHASH);
	/***********************************************************/
	rtd_outl(RTKVDEC_DUMMY_VBM_SIZE, htonl( 0xBEAD0000 | VBM_total>>20));
}

void rtkvdec_VEProt_memory_init(void)
{
	int i;
	unsigned long _size = 0 ;
	VEProt_total = 0 ; //(unsigned int)carvedout_buf_query(CARVEDOUT_VDEC_VBM, (void *)&VEProt_start) ;

	pr_notice("rtkvdec_VEProt_memory_init %lx %lx\n", VEProt_start, VEProt_total);
	if (VEProt_start == 0 || VEProt_total == 0) {
		pr_err("[%s %d] no carved out VEProt memory!\n", __func__, __LINE__);
		return ;
	}

	for (i = 0; i < RTKVDEC_MAX_VEPROT_MEM_NUM; i++) {
		VEProt_list[i].mask = 0 ;
		VEProt_list[i].addr = 0 ;
		VEProt_list[i].size = 0 ;
	}

	_size = VEProt_total ;
	for (i = 0; i < 32; i++) {
		if (_size < RTKVDEC_VEPROT_BLOCK_SIZE)
		    break ;
		VEProt_gobs++;
		_size -= RTKVDEC_VEPROT_BLOCK_SIZE ;
	}
}

void rtkvdec_InbandBuf_init(void)
{
	int i ;

	for (i = 0; i < RTKVDEC_MAX_IBBUF_NUM; i++) {
		IBBuf[i].pid  = 0 ;
		IBBuf[i].used = 0 ;
		IBBuf[i].addr = 0 ;
		IBBuf[i].size = 0 ;
	}

	IBBuf[0].addr = rtkvdec_remote_malloc(RTKVDEC_IBBUF_SIZE * RTKVDEC_MAX_IBBUF_NUM, 0x90ABCDEF) & 0x7fffffff;
	if (!IBBuf[0].addr) {
		pr_err("rtkvdec : allocate InbandBuf fail!!!\n");
		return ;
	}

	IBBuf[0].size = RTKVDEC_IBBUF_SIZE ;
	for (i = 1 ; i < RTKVDEC_MAX_IBBUF_NUM ; i++) {
		IBBuf[i].addr = IBBuf[i-1].addr + RTKVDEC_IBBUF_SIZE ;
		IBBuf[i].size = RTKVDEC_IBBUF_SIZE ;
	}
}

void rtkvdec_dump_videofw_data(void)
{
	struct file *filePtr = 0 ;
	unsigned long start_addr = 0x1ac00000 ;
	unsigned long end_addr   = 0x1ad30000 ;
	unsigned long vir_addr ;
	unsigned char LogBuf[128] ;
	unsigned int  size, i, cnt ;
	unsigned long long f_offset = 0 ;

#ifdef CONFIG_ARM64
	return ;
#endif

#ifndef CONFIG_ANDROID
	filePtr = file_open("/tmp/var/log/video_fw_data.bin", O_TRUNC | O_RDWR | O_CREAT,0) ;
#else
	filePtr = file_open("/data/data/video_fw_data.bin", O_TRUNC | O_RDWR | O_CREAT,0) ;
#endif
	if (filePtr == 0) {
		pr_err("[%s %d]open file fail\n",__FUNCTION__,__LINE__);
		return ;
	}

	cnt = (end_addr - start_addr) >> 4 ;
	for (i = 0 ; i < cnt; i++) {
		memset(LogBuf, 0, 128);
		vir_addr = (unsigned long)phys_to_virt((phys_addr_t)start_addr);
		snprintf((char *)LogBuf, 128, "%lx: %x %x %x %x\n", start_addr | 0x80000000
			, ntohl(*(unsigned long *)vir_addr), ntohl(*(unsigned long *)(vir_addr+4))
			, ntohl(*(unsigned long *)(vir_addr+8)), ntohl(*(unsigned long *)(vir_addr+12)));
		size = strlen(LogBuf) ;
		file_write(filePtr, f_offset, LogBuf, strlen(LogBuf)) ;
		f_offset += size ;
		start_addr += 16 ;
	}

	if (filePtr)
		file_close(filePtr) ;
	filePtr = 0 ;
#ifndef CONFIG_ANDROID
	pr_notice("rtkvdec_dump_videofw_data: check /tmp/var/log/video_fw_data.bin\n") ;
#else
	pr_notice("rtkvdec_dump_videofw_data: check /data/data/video_fw_data.bin\n") ;
#endif
}

void rtkvdec_dump_esbuf(void)
{
	struct file *filePtr = 0 ;
	RINGBUFFER_HEADER ringBuf_H ;
	unsigned char *wrPtr, *rdPtr, *basePtr, *limitPtr ;
	unsigned int size, i ;
	unsigned long long f_offset = 0 ;

	for (i = 0; i < RTKVDEC_MAX_SVPMEM_NUM; i++) {
		memset((void *)&ringBuf_H, 0, sizeof(RINGBUFFER_HEADER));
		if (svp_Memory[i].pid != 0 && svp_Memory[i].used != 0) {
			rtkvdec_user_alloc_query(&ringBuf_H, svp_Memory[i].pid, 64, svp_Memory[i].addr);
			if (ringBuf_H.beginAddr == 0) {
				pr_err("[%s %d] beginAddr is NULL!!\n",__FUNCTION__,__LINE__);
				continue;
			}

			if (i == 0) filePtr = file_open("/tmp/var/log/video_esbuf1.bin", O_TRUNC | O_RDWR | O_CREAT,0) ;
			else        filePtr = file_open("/tmp/var/log/video_esbuf2.bin", O_TRUNC | O_RDWR | O_CREAT,0) ;

			if (filePtr == 0) {
				pr_err("[%s %d]open %d file fail\n",__FUNCTION__,__LINE__, i);
				return ;
			}

			size = ringBuf_H.size ;
			basePtr = dvr_remap_uncached_memory(ringBuf_H.beginAddr, size, __builtin_return_address(0));
			wrPtr = basePtr + (ringBuf_H.writePtr - ringBuf_H.beginAddr) ;
			rdPtr = basePtr + (ringBuf_H.readPtr[0] - ringBuf_H.beginAddr) ;
			limitPtr = basePtr + size;
			pr_notice("Ptr w(%x) r(%x) b(%x) l(%x)\n", (unsigned int)wrPtr, (unsigned int)rdPtr, (unsigned int)basePtr, (unsigned int)limitPtr);

			if (wrPtr < rdPtr) {
				wrPtr = wrPtr + size ;
			}

			if (wrPtr > rdPtr) {
				if (wrPtr > limitPtr) {
					file_write(filePtr, f_offset, rdPtr, limitPtr - rdPtr) ;
					f_offset += limitPtr -rdPtr ;
					file_write(filePtr, f_offset, basePtr, wrPtr - limitPtr) ;
					f_offset += wrPtr - limitPtr ;

				}
				else {
					file_write(filePtr, f_offset, rdPtr, wrPtr - rdPtr) ;
					f_offset += wrPtr - rdPtr ;
				}
			}

			dvr_unmap_memory((void *)basePtr, size);

			if (filePtr)
				file_close(filePtr) ;
			filePtr = 0 ;
			f_offset = 0 ;
			pr_notice("rtkvdec_dump_esbuf: check /tmp/var/log/video_esbuf%d.bin\n", i+1) ;
		}
	}
}

static void rtkvdec_print_to_dmesg(unsigned char *ptr, uint count)
{
	unsigned char *dmgp = NULL, *temp_ptr;
	char *tok;
	uint print_count;

	dmgp = kmalloc(DMESG_PRINT_MAX, GFP_KERNEL);
	if (!dmgp) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		return ;
	}

	while (count > 0) {
		memset(dmgp, '\0', DMESG_PRINT_MAX);
		if (count > (DMESG_PRINT_MAX - 64)) {
			memcpy(dmgp, ptr, DMESG_PRINT_MAX - 64);
			temp_ptr = dmgp;

			tok = strsep((char **)&temp_ptr, "\n");

			while (tok != NULL) {
				print_count = strlen(tok);
				tok = strsep((char **)&temp_ptr, "\n");
			}

			if (print_count == DMESG_PRINT_MAX - 64) {
				memcpy(dmgp, ptr, DMESG_PRINT_MAX - 64);
				temp_ptr = dmgp;

				tok = strsep((char **)&temp_ptr, "\n");

				while (tok != NULL) {
					pr_info("3.(%d) %s\n", count, tok);
					tok = strsep((char **)&temp_ptr, "\n");
				}

				count = count - (DMESG_PRINT_MAX - 64);
				ptr = ptr + (DMESG_PRINT_MAX - 64);
			}
			else {
				memset(dmgp, '\0', DMESG_PRINT_MAX);
				memcpy(dmgp, ptr, DMESG_PRINT_MAX - 64 - print_count);

				temp_ptr = dmgp;

				tok = strsep((char **)&temp_ptr, "\n");

				while (tok != NULL) {
					pr_info("1.(%d) %s\n", count, tok);
					tok = strsep((char **)&temp_ptr, "\n");
				}

				count = count - (DMESG_PRINT_MAX - 64 - print_count);
				ptr = ptr + (DMESG_PRINT_MAX - 64 - print_count);
			}
		} else {
			memcpy(dmgp, ptr, count);
			temp_ptr = dmgp;

			tok = strsep((char **)&temp_ptr, "\n");

			while (tok != NULL) {
				print_count = strlen(tok);
				pr_info("2.(%d) %s\n", count, tok);
				tok = strsep((char **)&temp_ptr, "\n");
			}

			count = 0;
			ptr = ptr + count;
		}
	}

	kfree(dmgp);
}

static int rtkvdec_debug_check_thread(void *arg)
{
	VDEC_SHARE_MEM_STRUCT show_shmem ;

	for (;;) {
		set_freezable();

		if (kthread_should_stop()) break;
		if (SharedMemAddr && !vcpu1_is_crash) {
			memcpy((void *)&show_shmem, (void *)SharedMemAddr, sizeof(VDEC_SHARE_MEM_STRUCT));
			if (show_shmem.video_is_crash) {
				rtkvdec_dump_videofw_data() ;
				rtkvdec_dump_esbuf() ;
				vcpu1_is_crash = 1 ;
			}
		}

		msleep(200); /* sleep 10 ms */
	}
	return 0;
}

static int rtkvdec_debug_thread(void *arg)
{
	unsigned long magic, size, wr, rd;
	unsigned char *wrPtr, *rdPtr, *basePtr, *limitPtr;
	VDEC_SHARE_MEM_STRUCT show_shmem ;
	int i ;

	for (;;) {
		set_freezable();

		if (kthread_should_stop()) break;
		for (i = 0; i < 2; i++) {
			if (file_videoDump[i] != 0 && g_pVideoDumpMemory[i] != 0 && g_videoDumpMemPhyAddr[i] != 0 && dbg_config[i].enable) {
				DEBUG_BUFFER_HEADER *header;
				header = (DEBUG_BUFFER_HEADER*) g_pVideoDumpMemory[i];
				magic = ntohl(header->magic) ;
				size  = ntohl(header->size) ;
				rd    = ntohl(header->rd) ;
				wr    = ntohl(header->wr) ;
				wrPtr = (unsigned char *)(g_pVideoDumpMemory[i] + wr - g_videoDumpMemPhyAddr[i]); /* make virtual address */
				rdPtr = (unsigned char *)(g_pVideoDumpMemory[i] + rd - g_videoDumpMemPhyAddr[i]); /* make virtual address */
				basePtr  = (unsigned char *)(g_pVideoDumpMemory[i] + sizeof(DEBUG_BUFFER_HEADER));
				size -= sizeof(DEBUG_BUFFER_HEADER);
				limitPtr = basePtr+ size;

				/*
				pr_debug("Header %x, m=%x size=%x r(%x) w(%x)\n", (unsigned int)header, magic, size, rd, wr);
				pr_debug("Ptr w(%x) r(%x) b(%x) l(%x)\n", wrPtr, rdPtr, basePtr, limitPtr);
				*/

				if (wrPtr < rdPtr) {
					wrPtr = wrPtr + size;
				}

				if (wrPtr > rdPtr) {
					if (wrPtr > limitPtr) {
						if (limitPtr - rdPtr > DUMP_GET_MAX_SZIE) {
							file_write(file_videoDump[i], f_offset[i], rdPtr, DUMP_GET_MAX_SZIE) ;
							f_offset[i] += DUMP_GET_MAX_SZIE ;

							if (rtkvdec_pr_to_dmesg_en != 0)
								rtkvdec_print_to_dmesg(rdPtr, DUMP_GET_MAX_SZIE);

							header->rd = htonl(rd + DUMP_GET_MAX_SZIE) ;
						}
						else {
							file_write(file_videoDump[i], f_offset[i], rdPtr, limitPtr -rdPtr) ;

							if (rtkvdec_pr_to_dmesg_en != 0)
								rtkvdec_print_to_dmesg(rdPtr, limitPtr - rdPtr);

							f_offset[i] += limitPtr -rdPtr ;

							if (wrPtr - limitPtr > DUMP_GET_MAX_SZIE) {
								file_write(file_videoDump[i], f_offset[i], basePtr, DUMP_GET_MAX_SZIE) ;

								if (rtkvdec_pr_to_dmesg_en != 0)
									rtkvdec_print_to_dmesg(basePtr, DUMP_GET_MAX_SZIE);

								f_offset[i] += DUMP_GET_MAX_SZIE ;

								header->rd = htonl(g_videoDumpMemPhyAddr[i] + sizeof(DEBUG_BUFFER_HEADER) + DUMP_GET_MAX_SZIE) ;
							}
							else {
								file_write(file_videoDump[i], f_offset[i], basePtr, wrPtr - limitPtr) ;

								if (rtkvdec_pr_to_dmesg_en != 0)
									rtkvdec_print_to_dmesg(basePtr, wrPtr - limitPtr);

								f_offset[i] += wrPtr - limitPtr ;

								header->rd = htonl(g_videoDumpMemPhyAddr[i] + sizeof(DEBUG_BUFFER_HEADER) + (wrPtr - limitPtr)) ;
							}
						}
					}
					else {
						if (wrPtr - rdPtr > DUMP_GET_MAX_SZIE) {
							file_write(file_videoDump[i], f_offset[i], rdPtr, DUMP_GET_MAX_SZIE) ;
							f_offset[i] += DUMP_GET_MAX_SZIE ;

							if (rtkvdec_pr_to_dmesg_en != 0)
								rtkvdec_print_to_dmesg(rdPtr, DUMP_GET_MAX_SZIE);

							header->rd = htonl(rd + DUMP_GET_MAX_SZIE) ;
						}
						else {
							file_write(file_videoDump[i], f_offset[i], rdPtr, wrPtr - rdPtr) ;
							f_offset[i] += wrPtr - rdPtr ;

							if (rtkvdec_pr_to_dmesg_en != 0)
								rtkvdec_print_to_dmesg(rdPtr, wrPtr - rdPtr);

							header->rd = htonl(rd + (wrPtr - rdPtr)) ;
						}
					}
				}
			}

			if (rtkvdec_dump_size_scale != 0) {
				if (f_offset[i] > (RTKVDEC_DUMP_FILE_MAX_SIZE * rtkvdec_dump_size_scale)) {
					f_offset[i] = 0;
				}
			}

			if (SharedMemAddr && !vcpu1_is_crash) {
				memcpy((void *)&show_shmem, (void *)SharedMemAddr, sizeof(VDEC_SHARE_MEM_STRUCT));
				if (show_shmem.video_is_crash) {
					rtkvdec_dump_videofw_data() ;
					rtkvdec_dump_esbuf() ;
					vcpu1_is_crash = 1 ;
				}
			}

			msleep(50); /* sleep 10 ms */
		}
	}

	/* pr_debug("rtkvdec_debug_thread break\n"); */

	return 0;
}

void rtkvdec_dump_init(void)
{
#ifndef CONFIG_ANDROID
	unsigned char default_file_name [27] = "/tmp/var/log/video_dump.bin" ;
	unsigned char default_file_name2[28] = "/tmp/var/log/video_dump2.bin" ;
	unsigned char default_file_name3[21] = "/tmp/video_dumpes.bin" ;
#else
	unsigned char default_file_name [25] = "/data/data/video_dump.bin" ;
	unsigned char default_file_name2[26] = "/data/data/video_dump2.bin" ;
	unsigned char default_file_name3[27] = "/data/data/video_dumpes.bin" ;
#endif
	int i ;

#ifdef SUPPORT_VCPU2_VERSION
	for (i = 0; i < 2; i++) {
#else
	for (i = 0; i < 1; i++) {
#endif
		dbg_config[i].enable = 0 ;
		dbg_config[i].mem_size = DUMP_MEMORY_SIZE ;
#ifndef CONFIG_ANDROID
		memset((void *)dbg_config[i].file_name, '\0', FILE_NAME_SIZE );
		memcpy((void *)dbg_config[i].file_name, (i == 0) ? (void *)default_file_name : (void *)default_file_name2, ( (i == 0) ? 27 : 28));
#else
		memset((void *)dbg_config[i].file_name, '\0', ( (i == 0) ? 25 : 26) + 1 );
		memcpy((void *)dbg_config[i].file_name, (i == 0) ? (void *)default_file_name : (void *)default_file_name2, ( (i == 0) ? 25 : 26));
#endif
	}

	/* set dump log file init size to 1MB */
	rtkvdec_dump_size_scale = 1;

	/* disable print VDSP log to dmesg at init */
	rtkvdec_pr_to_dmesg_en = 0;

	DumpES_Config.enable = 0 ;
	DumpES_Config.mem_size = DUMP_ES_SIZE ;
#ifndef CONFIG_ANDROID
	memset((void *)DumpES_Config.file_name, '\0', FILE_NAME_SIZE );
	memcpy((void *)DumpES_Config.file_name, (void *)default_file_name3, 21);
#else
	memset((void *)DumpES_Config.file_name, '\0', 27 + 1 );
	memcpy((void *)DumpES_Config.file_name, (void *)default_file_name3, 27);
#endif

	g_pDumpES.Memory = g_pDumpES.PhyAddr = g_pDumpES.VirtAddr = 0 ;
	g_pDumpES_Send.Memory = g_pDumpES_Send.PhyAddr = g_pDumpES_Send.VirtAddr = 0 ;
}

int rtkvdec_dump_enable(void)
{
	unsigned long return_value ;
	int i ;

	unsigned long vir_addr ;
	DEBUG_BUFFER_HEADER *header;

#ifdef SUPPORT_VCPU2_VERSION
	for (i = 0; i < 2; i++) {
#else
	for (i = 0; i < 1; i++) {
#endif
		if (dbg_config[i].enable) {
			pr_notice("rtkvdec: dbg dump already enable!\n");
			return 0 ;
		}

		file_videoDump[i] = file_open((char *)(dbg_config[i].file_name), O_TRUNC | O_RDWR | O_CREAT,0) ;
		if (file_videoDump[i] == 0) {
			pr_debug("[%s %d]open log file fail\n",__FUNCTION__,__LINE__);
			return -ENOMEM;
		}

		/* allocate debug memory */
		vir_addr = (unsigned long)dvr_malloc_uncached(sizeof(VIDEO_RPC_DEBUG_MEMORY)+256, (void **)&g_pVideoDebugMemory[i]);
		if (!vir_addr) {
			pr_err("[%s %d]alloc debug memory fail\n",__FUNCTION__,__LINE__);
			return -ENOMEM;
		}
		debugMemPhyAddr[i] = (unsigned long)dvr_to_phys((void*)vir_addr);
		debugMemVirtAddr[i] = vir_addr ;
		pr_notice("Alloc DBGME v(%lx) p(%lx) vn(%lx)\n"
		, vir_addr, debugMemPhyAddr[i], g_pVideoDebugMemory[i]);


		if ((file_videoDump[i] != 0) && (dbg_config[i].mem_size > 0)) {
			/* alocate dump memory */
			vir_addr = (unsigned long)dvr_malloc_uncached(dbg_config[i].mem_size, (void **)&g_pVideoDumpMemory[i]);
			if (!vir_addr) {
				vir_addr = debugMemVirtAddr[i];
				dvr_free((void*)vir_addr);
				pr_err("[%s %d]alloc debug memory fail\n",__FUNCTION__,__LINE__);
				return -ENOMEM;
			}
			g_videoDumpMemPhyAddr[i] = (unsigned long)dvr_to_phys((void*)vir_addr);
			g_videoDumpMemVirtAddr[i] = vir_addr ;

			pr_notice("Alloc DUMPME v(%lx) p(%lx) vn(%lx)\n"
			, vir_addr, g_videoDumpMemPhyAddr[i], g_pVideoDumpMemory[i]);

			/* setup debug dump ring buffer header */
			header = (DEBUG_BUFFER_HEADER*) g_pVideoDumpMemory[i];
			header->magic = htonl(0xdeadcafe) ;
			header->size = htonl(dbg_config[i].mem_size) ;
			header->rd = htonl(g_videoDumpMemPhyAddr[i] + sizeof(DEBUG_BUFFER_HEADER)) ;
			header->wr = htonl(g_videoDumpMemPhyAddr[i] + sizeof(DEBUG_BUFFER_HEADER)) ;

			*(unsigned long *)g_pVideoDebugMemory[i] = htonl(g_videoDumpMemPhyAddr[i]) ;

			pr_notice("Header %x, m=%lx size=%lx r(%lx) w(%lx)\n"
			, (unsigned int)header, header->magic, header->size, header->rd, header->wr);
		}
		else {
			pr_notice("rtkvdec: no allocate debug dump ring buffer!\n");
			return 0 ;
		}
	}

	rtkvdec_debug_tsk = kthread_create(rtkvdec_debug_thread, &data, "rtkvdec_debug_thread");
	if (IS_ERR(rtkvdec_debug_tsk)) {
		rtkvdec_debug_tsk = NULL;
		return -1 ;
	}
	wake_up_process(rtkvdec_debug_tsk);

	if (send_rpc_command(RPC_VIDEO, RPCCMD_VIDEO_SETDEBUGMEMORY, (unsigned long)debugMemPhyAddr[0], 0, &return_value))
		pr_debug("rtkvdec: RPCCMD_VIDEO_SETDEBUGMEMORY fail %ld\n", return_value);
#ifdef SUPPORT_VCPU2_VERSION
	if (send_rpc_command(RPC_VIDEO2, RPCCMD_VIDEO_SETDEBUGMEMORY, (unsigned long)debugMemPhyAddr[1], 0, &return_value))
		pr_debug("rtkvdec: V2 RPCCMD_VIDEO_SETDEBUGMEMORY fail %ld\n", return_value);
#endif

	dbg_config[0].enable = 1 ;
	dbg_config[1].enable = 1 ;

	return 0 ;
}

void rtkvdec_dump_disable(void)
{
	unsigned long return_value ;
	int ret = 0;
	int i ;
	unsigned long vir_addr ;
	DEBUG_BUFFER_HEADER *header;

#ifdef SUPPORT_VCPU2_VERSION
	for (i = 0; i < 2; i++) {
#else
	for (i = 0; i < 1; i++) {
#endif
		if (!dbg_config[i].enable) {
			pr_notice("rtkvdec: dbg dump not enable!\n");
			return ;
		}

		dbg_config[i].enable = 0 ;
		/* setup debug dump ring buffer header */
		header = (DEBUG_BUFFER_HEADER*) g_pVideoDumpMemory[i];
		header->magic = htonl(0xdeadcafe) ;
		header->size = htonl(16) ;
		header->rd = htonl(g_videoDumpMemPhyAddr[i] + sizeof(DEBUG_BUFFER_HEADER)) ;
		header->wr = htonl(g_videoDumpMemPhyAddr[i] + sizeof(DEBUG_BUFFER_HEADER)) ;
		*(unsigned long *)g_pVideoDebugMemory[i] = htonl(g_videoDumpMemPhyAddr[i]) ;
	}

	if (send_rpc_command(RPC_VIDEO, RPCCMD_VIDEO_SETDEBUGMEMORY, (unsigned long)debugMemPhyAddr[0], 0, &return_value))
		pr_debug("rtkvdec: RPCCMD_VIDEO_SETDEBUGMEMORY fail %ld\n", return_value);
#ifdef SUPPORT_VCPU2_VERSION
	if (send_rpc_command(RPC_VIDEO2, RPCCMD_VIDEO_SETDEBUGMEMORY, (unsigned long)debugMemPhyAddr[1], 0, &return_value))
		pr_debug("rtkvdec: V2 RPCCMD_VIDEO_SETDEBUGMEMORY fail %ld\n", return_value);
#endif

	ret = kthread_stop(rtkvdec_debug_tsk);
	if (!ret)
		pr_debug("rtkvdec debug thread stopped\n");

#ifdef SUPPORT_VCPU2_VERSION
	for (i = 0; i < 2; i++) {
#else
	for (i = 0; i < 1; i++) {
#endif
		f_offset[i] = 0 ;
		if (g_videoDumpMemPhyAddr[i]) {
			vir_addr = g_videoDumpMemVirtAddr[i];
			dvr_free((void*)vir_addr);
			g_pVideoDumpMemory[i] = g_videoDumpMemPhyAddr[i] = g_videoDumpMemVirtAddr[i] = 0 ;
		}

		if (debugMemPhyAddr[i]) {
			vir_addr = debugMemVirtAddr[i];
			dvr_free((void*)vir_addr);
			g_pVideoDebugMemory[i] = debugMemPhyAddr[i] = debugMemVirtAddr[i] = 0 ;
		}

		if (file_videoDump[i])
			file_close(file_videoDump[i]) ;
		file_videoDump[i] = 0 ;
	}
}

static int rtkvdec_dumpes_thread(void *arg)
{
	unsigned long magic, size, wr, rd;
	unsigned char *wrPtr, *rdPtr, *basePtr, *limitPtr;

	for (;;) {
		if (kthread_should_stop()) break;
		if (file_DumpES != 0 && DumpES_Config.enable) {
			DEBUG_BUFFER_HEADER *header;
			header = (DEBUG_BUFFER_HEADER*) g_pDumpES.Memory;
			magic = ntohl(header->magic) ;
			size  = ntohl(header->size) ;
			rd    = ntohl(header->rd) ;
			wr    = ntohl(header->wr) ;
			wrPtr = (unsigned char *)(g_pDumpES.Memory + wr - g_pDumpES.PhyAddr); /* make virtual address */
			rdPtr = (unsigned char *)(g_pDumpES.Memory + rd - g_pDumpES.PhyAddr); /* make virtual address */
			basePtr  = (unsigned char *)(g_pDumpES.Memory + sizeof(DEBUG_BUFFER_HEADER));
			size -= sizeof(DEBUG_BUFFER_HEADER);
			limitPtr = basePtr+ size;

			/*
			pr_debug("Header %x, m=%lx size=%lx r(%lx) w(%lx)\n", (unsigned int)header, magic, size, rd, wr);
			pr_debug("Ptr w(%lx) r(%lx) b(%lx) l(%lx)\n", wrPtr, rdPtr, basePtr, limitPtr);
			*/

			if (wrPtr < rdPtr) {
				wrPtr = wrPtr + size;
			}

			if (wrPtr > rdPtr) {
				if (wrPtr > limitPtr) {
					file_write(file_DumpES, f_offset_dumpes, rdPtr, limitPtr -rdPtr) ;
					f_offset_dumpes += limitPtr -rdPtr ;
					file_write(file_DumpES, f_offset_dumpes, basePtr, wrPtr - limitPtr) ;
					f_offset_dumpes += wrPtr - limitPtr ;
				}
				else {
					file_write(file_DumpES, f_offset_dumpes, rdPtr, wrPtr - rdPtr) ;
					f_offset_dumpes += wrPtr - rdPtr ;
				}
				header->rd = htonl(wr) ;
			}
		}

		msleep(25); /* sleep 10 ms */
	}

	/* pr_debug("rtkvdec_dumpes_thread break\n"); */

	return 0;
}

int rtkvdec_dumpes_enable(const char *pattern, int length)
{
	unsigned long return_value ;
	DEBUG_BUFFER_HEADER *header;
	unsigned long vir_addr ;

	if (length > FILE_NAME_SIZE - 1) {
		pr_warn("rtkvdec: file name is too long(<%d).\n", FILE_NAME_SIZE - 1);
		return 0;
	}
	else if (length > 0) {
		memset((void *)DumpES_Config.file_name, '\0', length+1);
		memcpy((void *)DumpES_Config.file_name, (void *)pattern, length);
	}

	pr_notice("rtkvdec: dumpes_file_name(%s)\n", DumpES_Config.file_name);

	if (DumpES_Config.enable) {
		pr_notice("rtkvdec: es dump already enable!\n");
		return 0 ;
	}

	file_DumpES = file_open((char *)(DumpES_Config.file_name), O_TRUNC | O_RDWR | O_CREAT,0) ;
	if (file_DumpES == 0) {
		pr_err("[%s %d]open log file fail\n",__FUNCTION__,__LINE__);
		return -ENOMEM;
	}

	/* allocate debug memory */
	vir_addr = (unsigned long)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_DEBUG_MEMORY)+256, GFP_DCU1, (void **)(&g_pDumpES_Send.Memory));
	if (!vir_addr) {
		pr_err("[%s %d]alloc debug memory fail\n",__FUNCTION__,__LINE__);
		return -ENOMEM;
	}
	g_pDumpES_Send.PhyAddr = (unsigned long)dvr_to_phys((void*)vir_addr);
	g_pDumpES_Send.VirtAddr = vir_addr ;
	pr_notice("Alloc DESME v(%lx) p(%lx) vn(%lx)\n"
	, vir_addr, g_pDumpES_Send.PhyAddr, g_pDumpES_Send.Memory);


	if ((file_DumpES != 0) && (DumpES_Config.mem_size > 0)) {
		/* alocate dump memory */
		vir_addr = (unsigned long)dvr_malloc_uncached_specific(DumpES_Config.mem_size, GFP_DCU1, (void **)(&g_pDumpES.Memory));
		if (!vir_addr) {
			vir_addr = g_pDumpES_Send.VirtAddr ;
			dvr_free((void*)vir_addr);
			pr_err("[%s %d]alloc debug memory fail\n",__FUNCTION__,__LINE__);
			return -ENOMEM;
		}
		g_pDumpES.PhyAddr = (unsigned long)dvr_to_phys((void*)vir_addr);
		g_pDumpES.VirtAddr = vir_addr ;

		pr_notice("Alloc DUMPESME v(%lx) p(%lx) vn(%lx)\n"
		, vir_addr, g_pDumpES.PhyAddr, g_pDumpES.Memory);

		/* setup dump es ring buffer header */
		header = (DEBUG_BUFFER_HEADER*) g_pDumpES.Memory;
		header->magic = htonl(0xdeadcafe) ;
		header->size = htonl(DumpES_Config.mem_size) ;
		header->rd = htonl(g_pDumpES.PhyAddr + sizeof(DEBUG_BUFFER_HEADER)) ;
		header->wr = htonl(g_pDumpES.PhyAddr + sizeof(DEBUG_BUFFER_HEADER)) ;

		*(unsigned long *)g_pDumpES_Send.Memory = htonl(g_pDumpES.PhyAddr) ;

		pr_notice("Header %x, m=%lx size=%lx r(%lx) w(%lx)\n"
		, (unsigned int)header, header->magic, header->size, header->rd, header->wr);
	}
	else {
		pr_notice("rtkvdec: no allocate debug dump ring buffer!\n");
		return 0 ;
	}

	rtkvdec_dumpes_tsk = kthread_create(rtkvdec_dumpes_thread, &data, "rtkvdec_dumpes_thread");
	if (IS_ERR(rtkvdec_dumpes_tsk)) {
		rtkvdec_dumpes_tsk = NULL;
		return -1 ;
	}
	wake_up_process(rtkvdec_dumpes_tsk);

	if (send_rpc_command(RPC_VIDEO, RPC_VCPU_SET_DUMPES_MEMORY, (unsigned long)g_pDumpES_Send.PhyAddr, 0, &return_value))
		pr_debug("rtkvdec: RPC_VCPU_SET_DUMPES_MEMORY fail %ld\n", return_value);

	DumpES_Config.enable = 1 ;

	return 0 ;
}

void rtkvdec_dumpes_disable(void)
{
	unsigned long return_value ;
	int ret = 0;
	unsigned long vir_addr ;
	DEBUG_BUFFER_HEADER *header;

	if (!DumpES_Config.enable) {
		pr_notice("rtkvdec: es dump not enable!\n");
		return ;
	}

	DumpES_Config.enable = 0 ;
	/* setup debug dump ring buffer header */
	header = (DEBUG_BUFFER_HEADER*) g_pDumpES.Memory;
	header->magic = htonl(0xdeadcafe) ;
	header->size = htonl(16) ;
	header->rd = htonl(g_pDumpES.PhyAddr + sizeof(DEBUG_BUFFER_HEADER)) ;
	header->wr = htonl(g_pDumpES.PhyAddr + sizeof(DEBUG_BUFFER_HEADER)) ;
	*(unsigned long *)g_pDumpES_Send.Memory = htonl(g_pDumpES.PhyAddr) ;


	if (send_rpc_command(RPC_VIDEO, RPC_VCPU_SET_DUMPES_MEMORY, (unsigned long)g_pDumpES_Send.PhyAddr, 0, &return_value))
		pr_debug("rtkvdec: RPC_VCPU_SET_DUMPES_MEMORY fail %ld\n", return_value);

	ret = kthread_stop(rtkvdec_dumpes_tsk);
	if (!ret)
		pr_debug("rtkvdec dumpes thread stopped\n");

	f_offset_dumpes = 0 ;
	if (g_pDumpES.PhyAddr) {
		vir_addr = g_pDumpES.VirtAddr;
		dvr_free((void*)vir_addr);
		g_pDumpES.Memory = g_pDumpES.PhyAddr = g_pDumpES.VirtAddr = 0 ;
	}

	if (g_pDumpES_Send.PhyAddr) {
		vir_addr = g_pDumpES_Send.VirtAddr;
		dvr_free((void*)vir_addr);
		g_pDumpES_Send.Memory = g_pDumpES_Send.PhyAddr = g_pDumpES_Send.VirtAddr = 0 ;
	}

	if (file_DumpES)
		file_close(file_DumpES) ;
	file_DumpES = 0 ;

}

extern bool reserve_boot_memory;

static int rtkvdec_vcreate_thread(void *arg)
{
	unsigned long return_value ;
	unsigned long ret=S_OK;
#if !defined(CONFIG_ARM64) && !defined(CONFIG_REALTEK_LOGBUF)
	int ret2 = 0;
	int count = 0;
#endif
	dma_addr_t dat;
	VIDEO_INIT_DATA *init, *init_addr ;
	void *p;

#ifdef CONFIG_LG_SNAPSHOT_BOOT
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
	}
#endif
	pr_debug("rtkvdec: init\n");

	p = dma_alloc_coherent(rtkvdec_device, 4096, &dat, GFP_KERNEL);
	if (!p) {
		pr_err("[%s %d]alloc INIT memory fail\n",__FUNCTION__,__LINE__);
		return -ENOMEM;
	}
	pr_err("[%s %d]alloc :%p\n",__FUNCTION__,__LINE__,p);

	init = (VIDEO_INIT_DATA *)p ;
	init->boardType = htonl(0) ; /* use this para to do kernel/fw video create handshake*/
	init_addr = (VIDEO_INIT_DATA *)(dat|0xa0000000);

	// KWarning: checked ok by a0945150@realtek.com
	for (;;) {
		ret = send_rpc_command(RPC_VIDEO, RPCCMD_VIDEO_CREATE, (unsigned int)init_addr, 0, &return_value) ;

		if (!ret) {
			if (ntohl(init->boardType) == 0) {
				VideoCreatDone = 1 ;
				pr_debug("rtkvdec: RPCCMD_VIDEO_CREATE success %d\n", (unsigned int)ret);
				break ;
			}
			else { //video fw in pov
				while (!notify_rtkvdec_release_pov) {
					msleep(200); // sleep 10 ms
				}
				notify_rtkvdec_release_pov = 0 ;
			}
		}

		msleep(100); /* sleep 10 ms */
	}

#ifdef SUPPORT_VCPU2_VERSION
	init->boardType = htonl(0) ; /*use this para to do kernel/fw video create handshake */

	for (;;) {
		ret = send_rpc_command(RPC_VIDEO2, RPCCMD_VIDEO_CREATE, (unsigned int)init_addr, 0, &return_value) ;

		if (!ret && ntohl(init->boardType) == 0) {
			VideoCreatDone2 = 1 ;
			pr_debug("rtkvdec: RPCCMD_VIDEO_CREATE V2 success %ld\n", ret);
			break ;
		}

		msleep(100); /* sleep 10 ms */
	}
#endif

	dma_free_coherent(rtkvdec_device, 4096, p, dat);
	pr_debug("rtkvdec_vcreate_thread end\n");

#if !defined(CONFIG_ARM64) && !defined(CONFIG_REALTEK_LOGBUF)
	for (;;) {
		ret2 = rtkvdec_dump_enable();

		if (ret2 < 0) {
			pr_debug("wait to enable video dump file, retry...\n");
			msleep(1000); /* sleep 1s */
			count++;
		} else if (ret2 == 0){
			break;
		}

		if (count == 10) {
			pr_err("wait enable video dump file timeout\n");
			break;
		}
	}
#endif

#if !defined(CONFIG_ARM64)
	rtkvdec_send_sharedmemory();
#endif
	VideoCreatFinish = 1 ;
	return 0;
}

void rtkvdec_send_sharedmemory()
{
	unsigned long return_value ;

	SharedMemVirtAddr = (unsigned long)dvr_malloc_uncached_specific(sizeof(VDEC_SHARE_MEM_STRUCT), GFP_DCU1, (void **)(&SharedMemAddr));
	if (!SharedMemVirtAddr) {
		pr_err("[%s %d]alloc string memory fail\n",__FUNCTION__,__LINE__);
		return;
	}
	SharedMemPhyAddr = (unsigned long)dvr_to_phys((void *)SharedMemVirtAddr);

	memset((void *)SharedMemAddr, '\0', sizeof(VDEC_SHARE_MEM_STRUCT));
	pr_notice("rtkvdec: sharedmemory %lx %lx %lx\n", SharedMemVirtAddr, SharedMemAddr, SharedMemPhyAddr);

	if (send_rpc_command(RPC_VIDEO, RPC_VCPU_SET_SHARED_MEMORY, SharedMemPhyAddr, 0, &return_value))
		pr_debug("rtkvdec: RPC_VCPU_SET_SHARED_MEMORY fail %ld\n", return_value);

#if defined(CONFIG_REALTEK_LOGBUF)
	rtkvdec_debug_check_tsk = kthread_create(rtkvdec_debug_check_thread, &rtkvdec_debug_check_data, "rtkvdec_debug_check_thread");
	if (IS_ERR(rtkvdec_debug_check_tsk)) {
		rtkvdec_debug_check_tsk = NULL;
		return ;
	}
	wake_up_process(rtkvdec_debug_check_tsk);
#endif

	return;
}

void rtkvdec_show_sharedmemory(void)
{
	VDEC_SHARE_MEM_STRUCT show_shmem ;
	int i;

#ifdef CONFIG_ARM64
	return ;
#endif

	pr_notice("rtkvdec_user_alloc_summary %d %ld\n", rtkdev_free_flow_check, vcpu1_is_crash);

	if (!SharedMemAddr) return ;

	memcpy((void *)&show_shmem, (void *)SharedMemAddr, sizeof(VDEC_SHARE_MEM_STRUCT));

	pr_notice("record video fw isr :\n");
	pr_notice("last %d\n", ntohl(show_shmem.now));
	for (i = 0; i < 10; i++) {
		pr_notice("%d: v%d %x/%x, %x/%x\n", i, ntohl(show_shmem.isr_vector[i]), ntohl(show_shmem.isr[i]), ntohl(show_shmem.isr_done[i]), ntohl(show_shmem.isr_in_time[i]), ntohl(show_shmem.isr_out_time[i]));
	}
}

void rtkvdec_show_calltrace(void)
{
	VDEC_SHARE_MEM_STRUCT *show_shmem ;

#ifdef CONFIG_ARM64
	return ;
#endif

	if (!SharedMemAddr) return ;

	show_shmem = (VDEC_SHARE_MEM_STRUCT *)SharedMemAddr ;
	show_shmem->show_ct_no_crash = 1 ;
	rtd_outl(0xB801A008, 0x5); //SB2 Vint
	/* pr_notice("rtkvdec_show_calltrace %x %x\n", show_shmem->show_ct_no_crash, *((volatile unsigned int *) 0xB801A008)); */
}

int rtkvdec_alloc(int size)
{
	unsigned int vir_addr;
	unsigned int phy_addr;
	struct buffer_info *buf_info;

	vir_addr = (unsigned int)dvr_malloc_specific(size, GFP_DCU1);
	phy_addr = (unsigned int)dvr_to_phys((void *)vir_addr);

	if (!phy_addr) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		return 0;
	}

	if ((phy_addr & 0xe0000000) != 0)
		pr_err("[%s %d]get memory not between 0 ~ 512 MB\n", __func__, __LINE__);

	buf_info = kmalloc(sizeof(struct buffer_info), GFP_KERNEL);
	buf_info->vir_addr = vir_addr;
	buf_info->phy_addr = phy_addr;
	buf_info->request_size = size;
	buf_info->malloc_size = PAGE_ALIGN(size);
	buf_info->task_pid = task_tgid_nr(current);
	pr_debug("Alloc (p:%x,v:%x) for pid(%d)\n",
		phy_addr, vir_addr, task_tgid_nr(current));

	down(&rtkvdec_alloc_sem);
	list_add(&buf_info->buffer_list, &rtkvdec_alloc_head);
	up(&rtkvdec_alloc_sem);

	return phy_addr;
}

int rtkvdec_free(unsigned int phy_addr)
{
	unsigned int vir_addr=0;
	struct buffer_info *buf_info;
	struct siginfo    sinfo;    /* signal information */
	pid_t  pid;                   /* user program process id */
	struct task_struct *task;

	memset(&sinfo, 0, sizeof(struct siginfo));
	sinfo.si_signo = SIGSEGV;    // Config the signals: SIGIO
	sinfo.si_code  = -1;         //__SI_RT

	if (phy_addr == 0) {
		pr_err("[%s %d] Error!! phyaddr %x\n", __func__, __LINE__, phy_addr);
		pid = task_tgid_nr(current);
		task = find_task_by_vpid (pid);
		if (task == NULL) {
			printk ("Cannot find pid from user program\r\n");
			return 0;
		}
		/* send SIGIO to the user program */
		send_sig_info (SIGSEGV, &sinfo, task); /* Send signal to user program */
		return 0 ;
	}

	down(&rtkvdec_alloc_sem);
	list_for_each_entry(buf_info, &rtkvdec_alloc_head, buffer_list)
	{
		if (buf_info->phy_addr == phy_addr) {
			vir_addr = buf_info->vir_addr;
			list_del(&buf_info->buffer_list);
			kfree(buf_info);
			break;
		}
	}
	up(&rtkvdec_alloc_sem);

	if (vir_addr != 0) {
		dvr_free((void *)vir_addr);
	}
	else {
		pr_err("[%s %d] Error!! no find phyaddr %x\n", __func__, __LINE__, phy_addr);
		pid = task_tgid_nr(current);
		task = find_task_by_vpid (pid);
		if (task == NULL) {
			printk ("Cannot find pid from user program\r\n");
			return 0;
		}
		/* send SIGIO to the user program */
		send_sig_info (SIGSEGV, &sinfo, task); /* Send signal to user program */
	}

	return 0;
}

void rtkvdec_user_alloc_query(RINGBUFFER_HEADER *ringBuf_H, unsigned int pid, unsigned int size, unsigned long phy_addr )
{
	struct buffer_info *buf_info;
	RINGBUFFER_HEADER *RBH = 0 ;

	down(&rtkvdec_alloc_sem);
	list_for_each_entry(buf_info, &rtkvdec_alloc_head, buffer_list)
	{
		if (buf_info->task_pid == pid && buf_info->request_size <= size) {
			RBH = (RINGBUFFER_HEADER *)buf_info->vir_addr ;
			if (ntohl(RBH->beginAddr) == phy_addr) {
				pr_notice("start %x, size %x, w %x, R %x\n"
					, ntohl(RBH->beginAddr), ntohl(RBH->size)
					, ntohl(RBH->writePtr ), ntohl(RBH->readPtr[0]));
				ringBuf_H->beginAddr  = ntohl(RBH->beginAddr) ;
				ringBuf_H->size       = ntohl(RBH->size) ;
				ringBuf_H->writePtr   = ntohl(RBH->writePtr) ;
				ringBuf_H->readPtr[0] = ntohl(RBH->readPtr[0]) ;
				up(&rtkvdec_alloc_sem);
				return ;
			}
		}
	}
	up(&rtkvdec_alloc_sem);
}

void rtkvdec_user_alloc_summary(struct ret_info *info)
{
	unsigned long sum_request, sum_malloc;
	struct buffer_info *buf_info;
	struct buffer_info *b;
	struct list_head pid_list = LIST_HEAD_INIT(pid_list);

	sum_malloc = sum_request = 0;

	down(&rtkvdec_alloc_sem);
	pr_notice("rtkvdec_user_alloc_summary %d\n", rtkdev_free_flow_check);
	list_for_each_entry(buf_info, &rtkvdec_alloc_head, buffer_list)
	{
		pr_notice("pid(%d) : vir_addr %x, phy_addr %x, malloc %d, request %d\n",
			(int)buf_info->task_pid,
			(int)buf_info->vir_addr,
			(int)buf_info->phy_addr,
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
	up(&rtkvdec_alloc_sem);
	list_for_each_entry_safe(b, buf_info, &pid_list, buffer_list)
	{
		pr_notice("pid(%d) : sum_malloc %d, sum_request %d\n",
			(int)b->task_pid,
			(int)b->malloc_size,
			(int)b->request_size);
		sum_request += b->request_size;
		sum_malloc  += b->malloc_size;
		list_del(&b->buffer_list);
		kfree(b);
	}

	pr_notice("sum_malloc %ld, sum_request %ld\n", sum_malloc, sum_request);

	if (info == NULL)
		return;

	info->private_info[0] = sum_request;
	info->private_info[1] = sum_malloc;
}

void rtkvdec_free_by_process(unsigned long process_id)
{
	struct buffer_info *buf_info, *tmp_buf_info;
	struct task_struct *task;
	int i, svp_free_size = 0;

	down(&svp_memory_sem);
	for (i = 0; i < RTKVDEC_MAX_SVPMEM_NUM; i++) {
		if (svp_Memory[i].pid == process_id) {
			if (svp_Memory[i].protected) {
				svp_free_size = svp_Memory[i].used_8M ? RTKVDEC_SVPMEM_SIZE_8M :
								svp_Memory[i].used_12M ? RTKVDEC_SVPMEM_SIZE_12M :
								svp_Memory[i].used_16M ? RTKVDEC_SVPMEM_SIZE_16M : RTKVDEC_SVPMEM_SIZE_4M ;
				if (rtkvdec_svp_disable_cpb_protection(svp_Memory[i].addr, svp_free_size) != 0) {
					pr_err("rtkvdec: failed to disable cpb protection\n");
				}
				svp_Memory[i].protected = 0;
			}
			svp_Memory[i].used = 0 ;
			svp_Memory[i].pid = 0 ;
			if (svp_Memory[i].used_8M && i < 3) {
				svp_Memory[i].used_8M = 0 ;
				svp_Memory[i+1].used = 0 ;
				svp_Memory[i+1].pid = 0 ;
			}
			if (svp_Memory[i].used_12M && i < 2) {
				svp_Memory[i].used_12M = 0 ;
				svp_Memory[i+1].used = svp_Memory[i+2].used = 0 ;
				svp_Memory[i+1].pid = svp_Memory[i+2].pid = 0 ;
			}
			if (svp_Memory[i].used_16M && i < 1) {
				svp_Memory[i].used_16M = 0 ;
				svp_Memory[i+1].used = svp_Memory[i+2].used = svp_Memory[i+3].used = 0 ;
				svp_Memory[i+1].pid = svp_Memory[i+2].pid = svp_Memory[i+3].pid = 0 ;
			}
		}
	}
	up(&svp_memory_sem);

	down(&IBBuf_sem);
	for (i = 0; i < RTKVDEC_MAX_IBBUF_NUM; i++) {
		if (IBBuf[i].pid == process_id) {
			IBBuf[i].used = 0 ;
			IBBuf[i].pid = 0 ;
		}
		if (IBBuf_dbg[i].used && IBBuf_dbg[i].addr != 0 && IBBuf_dbg[i].pid == process_id) {
			pr_notice("rtkvdec: free IB debug mem 0x%x\n", IBBuf_dbg[i].addr);
			memory_debug_unprotect(i);
			rtkvdec_free(IBBuf_dbg[i].addr);
			IBBuf_dbg[i].addr = 0 ;
			IBBuf_dbg[i].size = 0 ;
			IBBuf_dbg[i].used = 0 ;
			IBBuf_dbg[i].pid = 0 ;
		}
	}
	up(&IBBuf_sem);

	down(&rtkvdec_alloc_sem);
	rtkdev_free_flow_check = 1 ;
	list_for_each_entry_safe(buf_info, tmp_buf_info,
		&rtkvdec_alloc_head, buffer_list)
	{
		if (buf_info->task_pid == process_id) {
			rtkdev_free_flow_check = 2 ;
			list_del(&buf_info->buffer_list);
			rtkdev_free_flow_check = 3 ;
			dvr_free((void *)buf_info->vir_addr);
			rtkdev_free_flow_check = 4 ;
			kfree(buf_info);
		}
		else {
			task = pid_task(find_vpid(buf_info->task_pid), PIDTYPE_PID);
			if(task == NULL) {
				list_del(&buf_info->buffer_list);
				rtkdev_free_flow_check = 5 ;
				dvr_free((void *)buf_info->vir_addr);
				rtkdev_free_flow_check = 6 ;
				kfree(buf_info);
			}
		}
	}
	rtkdev_free_flow_check = 0 ;
	up(&rtkvdec_alloc_sem);
}

/* RPC handler function */
unsigned long rtkvdec_free_user_mem(unsigned long para1, unsigned long para2)
{
	pr_debug("rtkvdec_free_user_mem(%lx/%lx)\n", para1, para2);
	/* rtkvdec_user_alloc_summary(NULL); */
	if (para2 == 0x1) {
#ifdef CONFIG_RTK_KDRV_DV
		extern int DV_ForceSTOP(unsigned long process_id);
		DV_ForceSTOP(para1);
#endif
		rtkvdec_free_by_process(para1);
	}
	/* rtkvdec_user_alloc_summary(NULL); */
	return 0;
}

long rtkvdec_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	unsigned long return_value ;
	int ret = 0;

	pr_debug("rtkvdec: receive ioctl(cmd:0x%08x, arg:0x%08x)\n", cmd, (unsigned int)arg);
	switch (cmd) {
		case VDEC_IOC_INIT:
		{
			/* fix bug : ANDROIDTV-865 */
			break;

			pr_debug("rtkvdec: init\n");
			if (!VideoCreatDone) {
				dma_addr_t dat;
				void *p;
				VIDEO_INIT_DATA *init, *init_addr ;
				p = dma_alloc_coherent(rtkvdec_device, 4096, &dat, GFP_KERNEL);
				if (!p) {
					pr_err("[%s %d]alloc INIT memory fail\n",__FUNCTION__,__LINE__);
					return -ENOMEM;
				}

				init = (VIDEO_INIT_DATA *)p ;
				init->boardType = htonl(0) ;
				init_addr = (VIDEO_INIT_DATA *)(dat|0xa0000000);

				if ((ret = send_rpc_command(RPC_VIDEO, RPCCMD_VIDEO_CREATE, (unsigned int)init_addr, 0, &return_value))) {
					pr_debug("rtkvdec: RPCCMD_VIDEO_CREATE V1 fail %d\n", ret);
				}
				else {
					VideoCreatDone = 1 ;
					pr_debug("rtkvdec: RPCCMD_VIDEO_CREATE V1 success %d\n", ret);

#ifdef SUPPORT_VCPU2_VERSION
					init->boardType = htonl(0) ;
					if ((ret = send_rpc_command(RPC_VIDEO2, RPCCMD_VIDEO_CREATE, (unsigned int)init_addr, 0, &return_value))) {
						pr_debug("rtkvdec: RPCCMD_VIDEO_CREATE V2 fail %d\n", ret);
					}
					else {
						VideoCreatDone2 = 1 ;
						pr_debug("rtkvdec: RPCCMD_VIDEO_CREATE V2 success %d\n", ret);
					}
#endif
				}

				dma_free_coherent(rtkvdec_device, 4096, p, dat);
			}
#ifdef SUPPORT_VCPU2_VERSION
			else if (!VideoCreatDone2) {
				dma_addr_t dat;
				void *p;
				VIDEO_INIT_DATA *init, *init_addr ;
				p = dma_alloc_coherent(rtkvdec_device, 4096, &dat, GFP_KERNEL);
				if (!p) {
					pr_debug("[%s %d]alloc INIT memory fail\n",__FUNCTION__,__LINE__);
					return -ENOMEM;
				}

				init = (VIDEO_INIT_DATA *)p ;
				init->boardType = htonl(0) ;
				init_addr = (VIDEO_INIT_DATA *)(dat|0xa0000000);

				if ((ret = send_rpc_command(RPC_VIDEO2, RPCCMD_VIDEO_CREATE, (unsigned int)init_addr, 0, &return_value))) {
					pr_debug("rtkvdec: RPCCMD_VIDEO_CREATE V2 fail %d\n", ret);
				}
				else {
					VideoCreatDone2 = 1 ;
					pr_debug("rtkvdec: RPCCMD_VIDEO_CREATE V2 success %d\n", ret);
				}

				dma_free_coherent(rtkvdec_device, 4096, p, dat);
			}
#endif
			else {
				pr_debug("rtkvdec: video create already done!\n");
			}

			break;
		}

		case VDEC_IOC_DEINIT:
		{
			/* pr_debug("rtkvdec: deinit\n"); */
			break;
		}

		case VDEC_IOC_OPEN:
		{
			/* pr_debug("rtkvdec: open\n"); */
			VDEC_FLOW_CMD_T vdec_cmd ;
			if (copy_from_user((void *)&vdec_cmd, (const void __user *)arg, sizeof(vdec_cmd))) {
				ret = -EFAULT;
				pr_err("rtkvdec ioctl code=VDEC_IOC_OPEN failed!!!!!!!!!!!!!!!\n");
				goto out;
			}
			/*
			send_rpc_command
			*/
			vdec_cmd.handle = 0x43211234 ;
			/* pr_debug("rtkvdec: %d %x\n", vdec_cmd.filterType, vdec_cmd.handle); */
			if (copy_to_user((void __user *)arg, (void *)&vdec_cmd, sizeof(vdec_cmd))) {
				ret = -EFAULT;
				goto out;
			}
			break;
		}

		case VDEC_IOC_CLOSE:
		{
			/* pr_debug("rtkvdec: close\n"); */
			VDEC_FLOW_CMD_T vdec_cmd ;
			if (copy_from_user((void *)&vdec_cmd, (const void __user *)arg, sizeof(vdec_cmd))) {
				ret = -EFAULT;
				pr_err("rtkvdec ioctl code=VDEC_IOC_CLOSE failed!!!!!!!!!!!!!!!\n");
				goto out;
			}
			/*
			send_rpc_command
			*/
			break;
		}

		case VDEC_IOC_PLAY:
		{
			/* pr_debug("rtkvdec: play\n"); */
			VDEC_FLOW_CMD_T vdec_cmd ;
			if (copy_from_user((void *)&vdec_cmd, (const void __user *)arg, sizeof(vdec_cmd))) {
				ret = -EFAULT;
				pr_err("rtkvdec ioctl code=VDEC_IOC_PALY failed!!!!!!!!!!!!!!!\n");
				goto out;
			}
			/*
			send_rpc_command
			*/
			break;
		}

		case VDEC_IOC_PAUSE:
		{
			/* pr_debug("*****************  rtkvdec pause  *********************\n"); */
			break;
		}

		case VDEC_IOC_FLUSH:
		{
			/* pr_debug("rtkvdec: flush\n"); */
			VDEC_FLOW_CMD_T vdec_cmd ;
			if (copy_from_user((void *)&vdec_cmd, (const void __user *)arg, sizeof(vdec_cmd))) {
				ret = -EFAULT;
				pr_err("rtkvdec ioctl code=VDEC_IOC_FLUSH failed!!!!!!!!!!!!!!!\n");
				goto out;
			}
			/*
			send_rpc_command
			*/
			break;
		}

		case VDEC_IOC_STOP:
		{
			/* pr_debug("rtkvdec: stop\n"); */
			VDEC_FLOW_CMD_T vdec_cmd ;
			if (copy_from_user((void *)&vdec_cmd, (const void __user *)arg, sizeof(vdec_cmd))) {
				ret = -EFAULT;
				pr_err("rtkvdec ioctl code=VDEC_IOC_STOP failed!!!!!!!!!!!!!!!\n");
				goto out;
			}
			/*
			send_rpc_command
			*/
			break;
		}

		case VDEC_IOC_CONNECT:
		{
			/* pr_debug("rtkvdec: connect\n"); */
			VDEC_FLOW_CMD_T vdec_cmd ;
			if (copy_from_user((void *)&vdec_cmd, (const void __user *)arg, sizeof(vdec_cmd))) {
				ret = -EFAULT;
				pr_err("rtkvdec ioctl code=VDEC_IOC_CONNECT failed!!!!!!!!!!!!!!!\n");
				goto out;
			}
			/*
			send_rpc_command
			*/
			break;
		}

		case VDEC_IOC_SET:
		{
			/* pr_debug("rtkvdec: set\n"); */
			VDEC_SET_CMD_T vdec_cmd;
			if (copy_from_user((void *)&vdec_cmd, (const void __user *)arg, sizeof(vdec_cmd))) {
				ret = -EFAULT;
				pr_err("rtkvdec ioctl code=VDEC_IOC_SET failed!!!!!!!!!!!!!!!\n");
				goto out;
			}
			/*
			send_rpc_command
			*/
			break;
		}

		case VDEC_IOC_GET:
		{
			/* pr_debug("*****************  rtkvdec get  *********************\n"); */
			break;
		}

		case VDEC_IOC_ENVDBG:
		{
			break ;
		}

		case VDEC_IOC_DISVDBG:
		{
			break ;
		}

		case VDEC_IOC_FRAMEINFO:
		{
			/* pr_debug("rtkvdec: frame info\n"); */
			VDEC_FRAMEINFO_STRUCT frame_info;

			struct list_head *del_list;
			VDEC_FRAMEINFO_LIST *buf_info_list;
			if (copy_from_user((void *)&frame_info, (const void __user *)arg, sizeof(VDEC_FRAMEINFO_STRUCT))) {
				ret = -EFAULT;
				pr_err("rtkvdec ioctl code=VDEC_IOC_FRAMEINFO failed!!!!!!!!!!!!!!!\n");
				goto out;
			}

			down(&gst_frame_info_list_sem);
			list_for_each(del_list, &gst_frame_info_head) {
				buf_info_list = list_entry(del_list, VDEC_FRAMEINFO_LIST, buffer_list);
				if (buf_info_list->frame_info.pid == frame_info.pid) {
					VDEC_FRAMEINFO_STRUCT *buf_info = &buf_info_list->frame_info ;
					buf_info->frame_dropped = frame_info.frame_dropped ;
					buf_info->frame_displaying = frame_info.frame_displaying ;
					buf_info->frame_matched = frame_info.frame_matched ;
					buf_info->frame_freerun = frame_info.frame_freerun ;
					break;
				}
			}
			up(&gst_frame_info_list_sem);
			/* pr_debug("rtkvdec : path %s msize %x\n", dbg_config.file_name, dbg_config.mem_size); */

			break ;
		}

		case VDEC_IOC_ALLOCSVPMP:
		case VDEC_IOC_ALLOCSVPM:
		{
			/* pr_debug("rtkvdec: allocate SVP memory\n"); */
			VDEC_SVPMEM_STRUCT svpmem ;
			int i ;
			if (copy_from_user((void *)&svpmem, (const void __user *)arg, sizeof(VDEC_SVPMEM_STRUCT))) {
				ret = -EFAULT;
				pr_err("rtkvdec ioctl code=VDEC_IOC_FREESVPM failed!!!!!!!!!!!!!!!\n");
				goto out;
			}

			svpmem.addr = 0 ;
			down(&svp_memory_sem);
			if (svpmem.size == RTKVDEC_SVPMEM_SIZE_4M ) {
				/*alloc 1st or 4th first*/
				if (svp_Memory[0].used == 0 && svp_Memory[0].addr != 0) {
					svpmem.addr = svp_Memory[0].addr ;
					svp_Memory[0].pid = svpmem.pid ;
					svp_Memory[0].used = 1 ;
					i = 0;
				}
				else if (svp_Memory[3].used == 0 && svp_Memory[3].addr != 0) {
					svpmem.addr = svp_Memory[3].addr ;
					svp_Memory[3].pid = svpmem.pid ;
					svp_Memory[3].used = 1 ;
					i = 3;
				}
				else if (svp_Memory[1].used == 0 && svp_Memory[1].addr != 0) {
					svpmem.addr = svp_Memory[1].addr ;
					svp_Memory[1].pid = svpmem.pid ;
					svp_Memory[1].used = 1 ;
					i = 1;
				}
				else if (svp_Memory[2].used == 0 && svp_Memory[2].addr != 0) {
					svpmem.addr = svp_Memory[2].addr ;
					svp_Memory[2].pid = svpmem.pid ;
					svp_Memory[2].used = 1 ;
					i = 2;
				}
			}
			else if (svpmem.size == RTKVDEC_SVPMEM_SIZE_8M ) {
				if (svp_Memory[0].used == 0 && svp_Memory[0].addr != 0 && svp_Memory[1].used == 0 && svp_Memory[1].addr != 0) {
					svpmem.addr = svp_Memory[0].addr ;
					svp_Memory[0].pid = svp_Memory[1].pid = svpmem.pid ;
					svp_Memory[0].used = svp_Memory[1].used = 1 ;
					svp_Memory[0].used_8M = 1 ;
					i = 0;
				}
				else if (svp_Memory[2].used == 0 && svp_Memory[2].addr != 0 && svp_Memory[3].used == 0 && svp_Memory[3].addr != 0) {
					svpmem.addr = svp_Memory[2].addr ;
					svp_Memory[2].pid = svp_Memory[3].pid = svpmem.pid ;
					svp_Memory[2].used = svp_Memory[3].used = 1 ;
					svp_Memory[2].used_8M = 1 ;
					i = 2;
				}
				else if (svp_Memory[1].used == 0 && svp_Memory[1].addr != 0 && svp_Memory[2].used == 0 && svp_Memory[2].addr != 0) {
					svpmem.addr = svp_Memory[1].addr ;
					svp_Memory[1].pid = svp_Memory[2].pid = svpmem.pid ;
					svp_Memory[1].used = svp_Memory[2].used = 1 ;
					svp_Memory[1].used_8M = 1 ;
					i = 1;
				}
			}
			else if (svpmem.size == RTKVDEC_SVPMEM_SIZE_12M ) {
				if (svp_Memory[0].used == 0 && svp_Memory[0].addr != 0 && svp_Memory[1].used == 0 && svp_Memory[1].addr != 0 && svp_Memory[2].used == 0 && svp_Memory[2].addr != 0) {
					svpmem.addr = svp_Memory[0].addr ;
					svp_Memory[0].pid = svp_Memory[1].pid = svp_Memory[2].pid = svpmem.pid ;
					svp_Memory[0].used = svp_Memory[1].used = svp_Memory[2].used = 1 ;
					svp_Memory[0].used_12M = 1 ;
					i = 0;
				}
				else if (svp_Memory[1].used == 0 && svp_Memory[1].addr != 0 && svp_Memory[2].used == 0 && svp_Memory[2].addr != 0 && svp_Memory[3].used == 0 && svp_Memory[3].addr != 0) {
					svpmem.addr = svp_Memory[1].addr ;
					svp_Memory[1].pid = svp_Memory[2].pid = svp_Memory[3].pid = svpmem.pid ;
					svp_Memory[1].used = svp_Memory[2].used = svp_Memory[3].used = 1 ;
					svp_Memory[1].used_12M = 1 ;
					i = 1;
				}
			}
			else if (svpmem.size == RTKVDEC_SVPMEM_SIZE_16M ) {
				if (svp_Memory[0].used == 0 && svp_Memory[0].addr != 0 && svp_Memory[1].used == 0 && svp_Memory[1].addr != 0 && svp_Memory[2].used == 0 && svp_Memory[2].addr != 0 && svp_Memory[3].used == 0 && svp_Memory[3].addr != 0) {
					svpmem.addr = svp_Memory[0].addr ;
					svp_Memory[0].pid = svp_Memory[1].pid = svp_Memory[2].pid = svp_Memory[3].pid = svpmem.pid ;
					svp_Memory[0].used = svp_Memory[1].used = svp_Memory[2].used = svp_Memory[3].used = 1 ;
					svp_Memory[0].used_16M = 1 ;
					i = 0;
				}
			}
			else {
				pr_err("rtkvdec : invalid allocate size %x!!!\n", svpmem.size);
			}
			up(&svp_memory_sem);

			if (svpmem.addr == 0) {
				pr_err("rtkvdec : no free SVP Memory!!!\n");
				rtkvdec_show_kstate();
				ret = -EFAULT;
				goto out;
			}

			if (cmd == VDEC_IOC_ALLOCSVPMP) {
				if (rtkvdec_svp_enable_cpb_protection(svp_Memory[i].addr, svpmem.size) != 0) {
					pr_err("rtkvdec : failed to enable cpb protection\n");
				}
				svp_Memory[i].protected = 1;
				pr_debug("rtkvdec : enable_cpb_protection(%d) addr %x SIZE %d \n", i, svp_Memory[i].addr, svpmem.size);
			}

			if (copy_to_user((void __user *)arg, (void *)&svpmem, sizeof(VDEC_SVPMEM_STRUCT))) {
				ret = -EFAULT;
				goto out;
			}
			break;
		}
		case VDEC_IOC_FREESVPM:
		{
			/* pr_debug("rtkvdec: free SVP memory\n"); */
			VDEC_SVPMEM_STRUCT svpmem ;
			int i, svp_free_size = 0 ;

			if (copy_from_user((void *)&svpmem, (const void __user *)arg, sizeof(VDEC_SVPMEM_STRUCT))) {
				ret = -EFAULT;
				pr_err("rtkvdec ioctl code=VDEC_IOC_FREESVPM failed!!!!!!!!!!!!!!!\n");
				goto out;
			}

			down(&svp_memory_sem);
			for (i = 0; i < RTKVDEC_MAX_SVPMEM_NUM; i++) {
				if (svp_Memory[i].addr == svpmem.addr) {
					if (svp_Memory[i].protected) {
						svp_free_size = svp_Memory[i].used_8M ? RTKVDEC_SVPMEM_SIZE_8M :
										svp_Memory[i].used_12M ? RTKVDEC_SVPMEM_SIZE_12M :
										svp_Memory[i].used_16M ? RTKVDEC_SVPMEM_SIZE_16M : RTKVDEC_SVPMEM_SIZE_4M ;
						if (rtkvdec_svp_disable_cpb_protection(svp_Memory[i].addr, svp_free_size) != 0) {
							pr_err("rtkvdec: failed to disable cpb protection\n");
						}
						svp_Memory[i].protected = 0;
					}
					svp_Memory[i].used = 0 ;
					svp_Memory[i].pid = 0 ;
					if (svp_Memory[i].used_8M && i < 3) {
						svp_Memory[i].used_8M = 0 ;
						svp_Memory[i+1].used = 0 ;
						svp_Memory[i+1].pid = 0 ;
					}
					if (svp_Memory[i].used_12M && i < 2) {
						svp_Memory[i].used_12M = 0 ;
						svp_Memory[i+1].used = svp_Memory[i+2].used = 0 ;
						svp_Memory[i+1].pid = svp_Memory[i+2].pid = 0 ;
					}
					if (svp_Memory[i].used_16M && i < 1) {
						svp_Memory[i].used_16M = 0 ;
						svp_Memory[i+1].used = svp_Memory[i+2].used = svp_Memory[i+3].used = 0 ;
						svp_Memory[i+1].pid = svp_Memory[i+2].pid = svp_Memory[i+3].pid = 0 ;
					}
					break ;
				}
			}
			up(&svp_memory_sem);
			break;
		}

		case VDEC_IOC_ALLOC_IBBUF:
		{
			/* pr_debug("rtkvdec: allocate IBBUF\n"); */
			VDEC_SVPMEM_STRUCT IBBuf ;
			if (copy_from_user((void *)&IBBuf, (const void __user *)arg, sizeof(VDEC_SVPMEM_STRUCT))) {
				ret = -EFAULT;
				pr_err("rtkvdec ioctl code=VDEC_IOC_ALLOC_IBBUF failed!!!!!!!!!!!!!!!\n");
				goto out;
			}

			IBBuf.addr = 0 ;
			IBBuf.addr = rtkvdec_cobuffer_alloc(VDEC_INBAND_BUF, IBBuf.pid) ;

			if (copy_to_user((void __user *)arg, (void *)&IBBuf, sizeof(VDEC_SVPMEM_STRUCT))) {
				ret = -EFAULT;
				goto out;
			}
			break;
		}

		case VDEC_IOC_FREE_IBBUF:
		{
			/* pr_debug("rtkvdec: free IBBUF\n"); */
			VDEC_SVPMEM_STRUCT IBBuf ;
			if (copy_from_user((void *)&IBBuf, (const void __user *)arg, sizeof(VDEC_SVPMEM_STRUCT))) {
				ret = -EFAULT;
				pr_err("rtkvdec ioctl code=VDEC_IOC_FREE_IBBUF failed!!!!!!!!!!!!!!!\n");
				goto out;
			}

			rtkvdec_cobuffer_free(VDEC_INBAND_BUF, IBBuf.addr) ;

			break;
		}

		case VDEC_IOC_ALLOC:
		{
			pr_debug("rtkvdec: VDEC_IOC_ALLOC\n");
			ret = rtkvdec_alloc(arg);
			break;
		}

		case VDEC_IOC_FREE:
		{
			pr_debug("rtkvdec: VDEC_IOC_FREE\n");
			ret = rtkvdec_free(arg);
			break;
		}

		case VDEC_IOC_HALLOG:
		{
			unsigned char g_HalLogBuf[128];
			pr_debug("rtkvdec: VDEC_IOC_HALLOG %lx\n", arg);
			memset(g_HalLogBuf, 0, 128);
			if (copy_from_user((void *)g_HalLogBuf, (const void __user *)arg, 128)) {
				ret = -EFAULT;
				pr_err("rtkvdec ioctl code=VDEC_IOC_HALLOG failed!!!!!!!!!!!!!!!\n");
				goto out;
			}
			pr_info("%s\n", g_HalLogBuf);
			break;
		}

		case VDEC_IOC_QVCDONE:
		{
			pr_debug("rtkvdec: VDEC_IOC_QVCDONE %d\n", VideoCreatFinish);
			ret = VideoCreatFinish ;
			break;
		}

		default:
		{
			pr_debug("rtkvdec: unknown ioctl(0x%08x)\n", cmd);
			break;
		}
	};

	out:
	return ret;
}

int rtkvdec_open(struct inode *inode, struct file *filp)
{
	VDEC_FRAMEINFO_STRUCT *frame_info ;
	if (!filp->private_data) {
		VDEC_FRAMEINFO_LIST *frame_info_list = kmalloc(sizeof(VDEC_FRAMEINFO_LIST), GFP_KERNEL);
		if (frame_info_list == NULL) {
			pr_err("%s: failed to allocate VDEC_FRAMEINFO_LIST\n", __func__);
			return -ENOMEM;
		}
		INIT_LIST_HEAD(&frame_info_list->buffer_list);
		frame_info = &frame_info_list->frame_info ;
		frame_info->pid = current->tgid ;
		frame_info->frame_dropped =
		frame_info->frame_displaying =
		frame_info->frame_matched =
		frame_info->frame_freerun = 0 ;
		down(&gst_frame_info_list_sem) ;
		list_add(&frame_info_list->buffer_list, &gst_frame_info_head) ;
		up(&gst_frame_info_list_sem) ;
		filp->private_data = frame_info_list ;
	}
	return 0 ;
}

int rtkvdec_release(struct inode *inode, struct file *filp)
{
	if (filp->private_data) {
		VDEC_FRAMEINFO_LIST *frame_info_list = filp->private_data;
		struct list_head *del_list;
		VDEC_FRAMEINFO_LIST *buf_info_list;
		VDEC_FRAMEINFO_STRUCT *frame_info = &frame_info_list->frame_info ;

		int find = 0 ;
		down(&gst_frame_info_list_sem);
		list_for_each(del_list, &gst_frame_info_head) {
			buf_info_list = list_entry(del_list, VDEC_FRAMEINFO_LIST, buffer_list);
			if (frame_info_list == buf_info_list && buf_info_list->frame_info.pid == frame_info->pid) {
				find = 1 ;
				break;
			}
		}

		if (find) list_del(del_list);
		up(&gst_frame_info_list_sem);

		if (find) kfree(buf_info_list);
	}
	else {
		pr_warn("rtkvdec_release: filp->private_data is null!!\n");
	}
	return 0 ;
}

#define DCMT_ADDR_SIZE 6
    unsigned int DCMT_ADDCMD_ADDR[DCMT_ADDR_SIZE][2]={
        {DC_SYS_DC_MT_ADDCMD_HI_0_reg,DC_SYS_DC_MT_ADDCMD_LO_0_reg},
        {DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg,DC_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg},
        {DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_reg,DC_SYS_DC_MT_ADDCMD_LO_SYS3_0_reg},
        {DC_SYS_DC_MTEX_ADDCMD_HI0_0_reg,DC_SYS_DC_MTEX_ADDCMD_LO_0_reg},
        {DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_reg,DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_reg},
        {DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_reg,DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_reg},
    };


static void rtkvdec_DCMTCallbackFunction(void)
{
    unsigned int addcmd_lo_addr=0;
    unsigned int addcmd_hi_addr=0;
    unsigned int addcmd_lo2=0;
    unsigned int addcmd_hi=0;
    unsigned int isBlockMode=0xffff;
    int i=0, count=0;

    //check trash module
    if(!isDcmtTrap("SB2_VCPU"))
    {
        printk(KERN_ERR "not SB2_VCPU module!\n");
        return;
    }
/*
    Get BlockMode or Sequence mode
*/
    for(i=0 ;i<4 ; i++)
    {
        for(count=0 ;count<DCMT_ADDR_SIZE ;count++)
        {
            addcmd_hi_addr=DCMT_ADDCMD_ADDR[count][0];
            addcmd_lo_addr=DCMT_ADDCMD_ADDR[count][1];
            addcmd_lo2=rtd_inl(addcmd_lo_addr + (i<<2));
            addcmd_hi=rtd_inl(addcmd_hi_addr + (i<<2));
            if( addcmd_hi & (1 << 22) )//ever_trap bit: Indicate if ever trap.
            {
                 isBlockMode=addcmd_lo2 &0x0001;
                 i=4;//break other loop
                 break;
            }
        }
    }
    if(0xffff==isBlockMode)
        {
        pr_err("[VDEC]DCMT Error to get block mode or not\n");
        return;
    }
    //check block mode or sequence mode

    pr_err( "====VE DCMT reg dump isBlockMode=0x%x with addcmd=0x%x====\n",isBlockMode,addcmd_lo2);
    if(isBlockMode)//sequence mode
    {
        pr_err("[VDEC]DCMT block mode no message for now\n");
    }
    else
    {
        pr_err( "====VE DCMT reg dump=====\n");
           pr_err( "====VE CODEBLKREG     =====\n");
            pr_err( "====CODEBLKREG_Base reg:%x, value=%x     \n",CODEBLKREG_ve_bsbase_reg,rtd_inl(CODEBLKREG_ve_bsbase_reg));
            pr_err( "====CODEBLKREG_Limit reg:%x, value=%x     \n",CODEBLKREG_ve_bslimit_reg,rtd_inl(CODEBLKREG_ve_bslimit_reg));
            pr_err( "====CODEBLKREG_Wptr reg:%x,  value=%x     \n",CODEBLKREG_ve_bswrptr_reg,rtd_inl(CODEBLKREG_ve_bswrptr_reg));
            pr_err( "====CODEBLKREG_Rptr reg:%x, value=%x    \n",CODEBLKREG_ve_bscurptr_reg,rtd_inl(CODEBLKREG_ve_bscurptr_reg));
            pr_err( "====CODEBLKREG_BSPTR reg:%x, value=%x    \n",CODEBLKREG_ve_decbsptr_reg,rtd_inl(CODEBLKREG_ve_decbsptr_reg));
            pr_err( "========================\n");
            pr_err( "====VE CABAC_P2_NDB =====\n");
            pr_err( "====CABAC_P2_NDB_CNTL reg:%x, value=%x     \n",CABAC_P2_p2_ndb_ctl_reg,rtd_inl(CABAC_P2_p2_ndb_ctl_reg));
            pr_err( "====P2_NDB_Base reg:%x, value=%x     \n",CABAC_P2_ndb_cabac_base_reg,rtd_inl(CABAC_P2_ndb_cabac_base_reg));
            pr_err( "====P2_NDB_Limit reg:%x, value=%x     \n",CABAC_P2_ndb_cabac_limit_reg,rtd_inl(CABAC_P2_ndb_cabac_limit_reg));
            pr_err("====P2_NDB_Wptr reg:%x, value=%x     \n",CABAC_P2_ndb_cabac_wptr_reg,rtd_inl(CABAC_P2_ndb_cabac_wptr_reg));
            pr_err("====P2_NDB_Rptr reg:%x, value=%x     \n",CABAC_P2_ndb_cabac_rptr_reg,rtd_inl(CABAC_P2_ndb_cabac_rptr_reg));
            pr_err( "====VE CODEBLKREG_CAVLC_NDB =====\n");
            pr_err( "====CAVLC_NDB_Base reg:%x, value=%x     \n",CODEBLKREG_ndb_cavlc_base_reg,rtd_inl(CODEBLKREG_ndb_cavlc_base_reg));
            pr_err( "====CAVLC_NDB_Limit reg:%x, value=%x     \n",CODEBLKREG_ndb_cavlc_limit_reg,rtd_inl(CODEBLKREG_ndb_cavlc_limit_reg));
            pr_err("====CAVLC_NDB_Wptr reg:%x, value=%x     \n",CODEBLKREG_ndb_cavlc_wptr_reg,rtd_inl(CODEBLKREG_ndb_cavlc_wptr_reg));
            pr_err("====CAVLC_NDB_Rptr reg:%x, value=%x     \n",CODEBLKREG_ndb_cavlc_rptr_reg,rtd_inl(CODEBLKREG_ndb_cavlc_rptr_reg));
            pr_err( "========================\n");
            pr_err("====VE CABAC_P2_P2=====\n");
            pr_err("====P2_INT_STATUS reg%x, value= 0x%x   \n",   CABAC_P2_cabacp2_int_status_reg,rtd_inl(CABAC_P2_cabacp2_int_status_reg));
            pr_err( "====P2_INT_EN reg%x, value= 0x%x   \n",            CABAC_P2_cabacp2_int_en_reg,  rtd_inl(CABAC_P2_cabacp2_int_en_reg));
            pr_err("====P2_WFIFO_BASE   reg%x, value= 0x%x   \n", CABAC_P2_p2_wfifo_base_reg, rtd_inl(CABAC_P2_p2_wfifo_base_reg));
            pr_err("====P2_WFIFO_LIMIT  reg%x, value= 0x%x   \n",CABAC_P2_p2_wfifo_limit_reg, rtd_inl(CABAC_P2_p2_wfifo_limit_reg));
            pr_err("====P2_WFIFO_WPTR   reg%x, value= 0x%x   \n", CABAC_P2_p2_wfifo_wptr_reg, rtd_inl(CABAC_P2_p2_wfifo_wptr_reg));
            pr_err("====P2_WFIFO_RPTR   reg%x, value= 0x%x   \n",CABAC_P2_p2_wfifo_rptr_reg,  rtd_inl(CABAC_P2_p2_wfifo_rptr_reg));
            pr_err( "========================\n");
            pr_err("====P2_RFIFO_BASE   reg%x, value= 0x%x   \n",   CABAC_P2_p2_rfifo_base_reg, rtd_inl(CABAC_P2_p2_rfifo_base_reg));
            pr_err("====P2_RFIFO_LIMIT  reg%x, value= 0x%x   \n",  CABAC_P2_p2_rfifo_limit_reg, rtd_inl(CABAC_P2_p2_rfifo_limit_reg));
            pr_err("====P2_RFIFO_WPTR   reg%x, value= 0x%x   \n", CABAC_P2_p2_rfifo_wptr_reg, rtd_inl(CABAC_P2_p2_rfifo_wptr_reg));
            pr_err("====P2_RFIFO_RPTR   reg%x, value= 0x%x   \n",  CABAC_P2_p2_rfifo_rptr_reg,  rtd_inl(CABAC_P2_p2_rfifo_rptr_reg));
            pr_err("====P2_RFIFO_BSPTR  reg%x, value= 0x%x   \n", CABAC_P2_p2_rfifo_decbsptr_reg, rtd_inl(CABAC_P2_p2_rfifo_decbsptr_reg));
            pr_err("========================\n");
            pr_err("====SEG TBCMD  reg%x, value= 0x%x   \n", SEG_tbcmd_reg, rtd_inl(SEG_tbcmd_reg));
            pr_err("====SEG SLCCFG  reg%x, value= 0x%x   \n", SEG_slccfg_reg, rtd_inl(SEG_slccfg_reg));
            pr_err("========================\n");
            pr_err("====MVDBLK H264CO1  reg%x, value= 0x%x   \n", MVDBLK_h264co1_reg, rtd_inl(MVDBLK_h264co1_reg));
            pr_err("====MVDBLK H264CO2  reg%x, value= 0x%x   \n", MVDBLK_h264co2_reg, rtd_inl(MVDBLK_h264co2_reg));
            pr_err("====MVDBLK H264NH1  reg%x, value= 0x%x   \n", MVDBLK_h264nh1_reg, rtd_inl(MVDBLK_h264nh1_reg));
            pr_err("====MVDBLK H264NH2  reg%x, value= 0x%x   \n", MVDBLK_h264nh2_reg, rtd_inl(MVDBLK_h264nh2_reg));
            pr_err("====MVDBLK HEVCSAO  reg%x, value= 0x%x   \n", MVDBLK_hevcsao_reg, rtd_inl(MVDBLK_hevcsao_reg));
            pr_err("====MVDBLK HEVCSAO1  reg%x, value= 0x%x   \n", MVDBLK_hevcsao1_reg, rtd_inl(MVDBLK_hevcsao1_reg));
            pr_err("========================\n");
            pr_err("====RL_hdr_str_addr_lu_0  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_0_reg, rtd_inl(RL_hdr_str_addr_lu_0_reg));
            pr_err("====RL_hdr_str_addr_lu_1  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_1_reg, rtd_inl(RL_hdr_str_addr_lu_1_reg));
            pr_err("====RL_hdr_str_addr_lu_2  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_2_reg, rtd_inl(RL_hdr_str_addr_lu_2_reg));
            pr_err("====RL_hdr_str_addr_lu_3  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_3_reg, rtd_inl(RL_hdr_str_addr_lu_3_reg));
            pr_err("====RL_hdr_str_addr_lu_4  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_4_reg, rtd_inl(RL_hdr_str_addr_lu_4_reg));
            pr_err("====RL_hdr_str_addr_lu_5  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_5_reg, rtd_inl(RL_hdr_str_addr_lu_5_reg));
            pr_err("====RL_hdr_str_addr_lu_6  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_6_reg, rtd_inl(RL_hdr_str_addr_lu_6_reg));
            pr_err("====RL_hdr_str_addr_lu_7  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_7_reg, rtd_inl(RL_hdr_str_addr_lu_7_reg));
            pr_err("====RL_hdr_str_addr_lu_8  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_8_reg, rtd_inl(RL_hdr_str_addr_lu_8_reg));
            pr_err("====RL_hdr_str_addr_lu_9  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_9_reg, rtd_inl(RL_hdr_str_addr_lu_9_reg));
            pr_err("====RL_hdr_str_addr_lu_10  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_10_reg, rtd_inl(RL_hdr_str_addr_lu_10_reg));
            pr_err("====RL_hdr_str_addr_lu_11  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_11_reg, rtd_inl(RL_hdr_str_addr_lu_11_reg));
            pr_err("====RL_hdr_str_addr_lu_12  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_12_reg, rtd_inl(RL_hdr_str_addr_lu_12_reg));
            pr_err("====RL_hdr_str_addr_lu_13  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_13_reg, rtd_inl(RL_hdr_str_addr_lu_13_reg));
            pr_err("====RL_hdr_str_addr_lu_14  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_14_reg, rtd_inl(RL_hdr_str_addr_lu_14_reg));
            pr_err("====RL_hdr_str_addr_lu_15  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_15_reg, rtd_inl(RL_hdr_str_addr_lu_15_reg));
            pr_err("====RL_hdr_str_addr_lu_16  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_16_reg, rtd_inl(RL_hdr_str_addr_lu_16_reg));
            pr_err("====RL_hdr_str_addr_lu_17  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_17_reg, rtd_inl(RL_hdr_str_addr_lu_17_reg));
            pr_err("====RL_hdr_str_addr_lu_18  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_18_reg, rtd_inl(RL_hdr_str_addr_lu_18_reg));
            pr_err("====RL_hdr_str_addr_lu_19  reg%x, value= 0x%x   \n", RL_hdr_str_addr_lu_19_reg, rtd_inl(RL_hdr_str_addr_lu_19_reg));
            pr_err("========================\n");
            pr_err("====RL_hdr_str_addr_ch_0  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_0_reg, rtd_inl(RL_hdr_str_addr_ch_0_reg));
            pr_err("====RL_hdr_str_addr_ch_1  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_1_reg, rtd_inl(RL_hdr_str_addr_ch_1_reg));
            pr_err("====RL_hdr_str_addr_ch_2  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_2_reg, rtd_inl(RL_hdr_str_addr_ch_2_reg));
            pr_err("====RL_hdr_str_addr_ch_3  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_3_reg, rtd_inl(RL_hdr_str_addr_ch_3_reg));
            pr_err("====RL_hdr_str_addr_ch_4  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_4_reg, rtd_inl(RL_hdr_str_addr_ch_4_reg));
            pr_err("====RL_hdr_str_addr_ch_5  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_5_reg, rtd_inl(RL_hdr_str_addr_ch_5_reg));
            pr_err("====RL_hdr_str_addr_ch_6  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_6_reg, rtd_inl(RL_hdr_str_addr_ch_6_reg));
            pr_err("====RL_hdr_str_addr_ch_7  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_7_reg, rtd_inl(RL_hdr_str_addr_ch_7_reg));
            pr_err("====RL_hdr_str_addr_ch_8  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_8_reg, rtd_inl(RL_hdr_str_addr_ch_8_reg));
            pr_err("====RL_hdr_str_addr_ch_9  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_9_reg, rtd_inl(RL_hdr_str_addr_ch_9_reg));
            pr_err("====RL_hdr_str_addr_ch_10  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_10_reg, rtd_inl(RL_hdr_str_addr_ch_10_reg));
            pr_err("====RL_hdr_str_addr_ch_11  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_11_reg, rtd_inl(RL_hdr_str_addr_ch_11_reg));
            pr_err("====RL_hdr_str_addr_ch_12  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_12_reg, rtd_inl(RL_hdr_str_addr_ch_12_reg));
            pr_err("====RL_hdr_str_addr_ch_13  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_13_reg, rtd_inl(RL_hdr_str_addr_ch_13_reg));
            pr_err("====RL_hdr_str_addr_ch_14  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_14_reg, rtd_inl(RL_hdr_str_addr_ch_14_reg));
            pr_err("====RL_hdr_str_addr_ch_15  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_15_reg, rtd_inl(RL_hdr_str_addr_ch_15_reg));
            pr_err("====RL_hdr_str_addr_ch_16  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_16_reg, rtd_inl(RL_hdr_str_addr_ch_16_reg));
            pr_err("====RL_hdr_str_addr_ch_17  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_17_reg, rtd_inl(RL_hdr_str_addr_ch_17_reg));
            pr_err("====RL_hdr_str_addr_ch_18  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_18_reg, rtd_inl(RL_hdr_str_addr_ch_18_reg));
            pr_err("====RL_hdr_str_addr_ch_19  reg%x, value= 0x%x   \n", RL_hdr_str_addr_ch_19_reg, rtd_inl(RL_hdr_str_addr_ch_19_reg));
            pr_err("========================\n");
            pr_err("====Pred BLK SDMAADDR  reg%x, value= 0x%x   \n", PREDBLK_SDMAADR_reg, rtd_inl(PREDBLK_SDMAADR_reg));
            pr_err("====Pred BLK DMAMSB   reg%x, value= 0x%x   \n", PREDBLK_DMAMSB_reg, rtd_inl(PREDBLK_DMAMSB_reg));
            pr_err("====DEBLK SDMAADDR  reg%x, value= 0x%x   \n", DEBLK_SDMAADR_reg, rtd_inl(DEBLK_SDMAADR_reg));
            //pr_err("====SAO DMAMSB   reg%x, value= 0x%x   \n", SAO_SAO_DMA_reg, rtd_inl(SAO_SAO_DMA_reg));
            pr_err("====CMPRS HDAADDR_0  reg%x, value= 0x%x   \n", CMPRS_HDMAADR_0_reg, rtd_inl(CMPRS_HDMAADR_0_reg));
            pr_err("====CMPRS HDAADDR_1   reg%x, value= 0x%x   \n", CMPRS_HDMAADR_1_reg, rtd_inl(CMPRS_HDMAADR_1_reg));
            pr_err("========================\n");
    }
}

void rtkvdec_help(void)
{
	pr_notice(" echo f > /dev/rtkvdec          ## print video f/w alloc memory summary\n");
	pr_notice(" echo sdf@ [s] > /dev/rtkvdec   ## debug: set string [s] as dump file name\n");
	pr_notice(" echo dlg > /dev/rtkvdec        ## debug: enable write video fw log to file\n");
	pr_notice(" echo dno > /dev/rtkvdec        ## debug: disable write video fw log to file\n");
	pr_notice(" echo des_en [s] > /dev/rtkvdec ## debug: enable dump es to file[S]\n");
	pr_notice(" echo des_di	 > /dev/rtkvdec    ## debug: disable dump es to file\n");
	pr_notice(" echo fw@ [s] > /dev/rtkvdec    ## debug: send a string [s] to f/w\n");
	pr_notice(" echo fw1@ [s] > /dev/rtkvdec   ## debug: send a string [s] to f/w(VCPU1)\n");
	pr_notice(" echo fw2@ [s] > /dev/rtkvdec   ## debug: send a string [s] to f/w(VCPU2)\n");
}

void rtkvdec_set_dump_file(const char *pattern, int length)
{
	if (length > FILE_NAME_SIZE - 2) {
		pr_warn("rtkvdec: file name is too long(<%d).\n", FILE_NAME_SIZE - 1);
		return;
	}

	memset((void *)dbg_config[0].file_name, '\0', length+1);
	memcpy((void *)dbg_config[0].file_name, (void *)pattern, length);
	memset((void *)dbg_config[1].file_name, '\0', length+2);
	memset((void *)dbg_config[1].file_name, '2', length+1);
	memcpy((void *)dbg_config[1].file_name, (void *)pattern, length);
	pr_notice("rtkvdec: dump_file_name(%s)\n", dbg_config[0].file_name);
	pr_notice("rtkvdec: dump_file_name(%s)\n", dbg_config[1].file_name);
	return;
}

void rtkvdec_send_string(const char *pattern, int length, int send_to)
{
	unsigned long ret = S_OK;
	unsigned long vir_addr;
	unsigned long phy_addr;
	char *command = NULL;

	vir_addr = (unsigned long)dvr_malloc_uncached_specific(length+1, GFP_DCU1, (void **)&command);
	if (!vir_addr) {
		pr_err("[%s %d]alloc string memory fail\n",__FUNCTION__,__LINE__);
		return;
	}
	phy_addr = (unsigned long)dvr_to_phys((void *)vir_addr);
	memset((void *)command, '\0', length+1);
	memcpy((void *)command, (void *)pattern, length);

	pr_debug("rtkvdec: debug string(%s), length(%d)\n", command, length);
	if (send_to & 0x1)
		if (send_rpc_command(RPC_VIDEO, RPC_VCPU_DEBUG_COMMAND, phy_addr, length, &ret))
			pr_err("rtkvdec: debug string(%s) fail %d\n", pattern, (int)ret);
#ifdef SUPPORT_VCPU2_VERSION
	if (send_to & 0x2)
		if (send_rpc_command(RPC_VIDEO2, RPC_VCPU_DEBUG_COMMAND, phy_addr, length, &ret))
			pr_err("rtkvdec: V2 debug string(%s) fail %d\n", pattern, (int)ret);
#endif

	dvr_free((void *)vir_addr);
	return;
}

void rtkvdec_vtm_state()
{
	char cmd_buf[10] = "vtms";
	rtkvdec_send_string(cmd_buf, 4, 0x1);
}

ssize_t rtkvdec_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
	long ret = count;
	char cmd_buf[100] = {0};

	pr_debug("%s(): count=%d, buf=0x%08lx\n", __func__, count, (long)buf);

	if (count >= 100)
		return -EFAULT;

	if (copy_from_user(cmd_buf, buf, count)) {
		ret = -EFAULT;
	}

	if ((cmd_buf[0] == 'f') && (count == 2)) {
		pr_notice("\n=== rtkvdec: show f/w memory usage ===\n");
		rtkvdec_fw_remote_malloc_summary(NULL);
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'u') && (count == 2)) {
		pr_notice("\n=== rtkvdec: show usr memory usage ===\n");
		rtkvdec_user_alloc_summary(NULL);
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 's') && (count == 2)) {
		pr_notice("\n=== rtkvdec show kernel state: ==============\n");
		rtkvdec_show_kstate();
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'h') && (count == 2)) {
		pr_notice("\n=== rtkvdec write usage: ==============\n");
		rtkvdec_help();
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'd') && (count == 2)) {
		pr_notice("\n=== rtkvdec debug: ==============\n");
		rtkvdec_show_sharedmemory();
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'd') && (cmd_buf[1] == 'u') && (cmd_buf[2] == 'm') && (cmd_buf[3] == 'p') && (count == 5)) {
		pr_notice("\n=== rtkvdec dump video fw data: ==============\n");
		rtkvdec_dump_videofw_data();
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'd') && (cmd_buf[1] == 'u') && (cmd_buf[2] == 'm') && (cmd_buf[3] == 'p') && (cmd_buf[4] == 'e') && (cmd_buf[5] == 's') && (count == 7)) {
		pr_notice("\n=== rtkvdec dump esbuf: ==============\n");
		rtkvdec_dump_esbuf();
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 's') && (cmd_buf[1] == 't') && (cmd_buf[2] == 'a') && (cmd_buf[3] == 'c') && (cmd_buf[4] == 'k') && (count == 6)) {
		pr_notice("\n=== rtkvdec calltrace: ==============\n");
		rtkvdec_show_calltrace();
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 's') && (cmd_buf[1] == 'd') && (cmd_buf[2] == 'f') && (cmd_buf[3] == '@')) {
		pr_notice("\n=== rtkvdec: set dump file name: =============\n");
		rtkvdec_set_dump_file(&cmd_buf[5], (count-5)-1);
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'd') && (cmd_buf[1] == 'l') && (cmd_buf[2] == 'g')) {
		if (count == 4) {
		}
		else if ((int) cmd_buf[4] > 47 && (int) cmd_buf[4] < 56 && (count == 6)) {
			rtkvdec_dump_size_scale = (int) cmd_buf[4] - 48;
		}
		pr_notice("rtkvdec_dump_size_scale %d MB\n", rtkvdec_dump_size_scale);
		pr_notice("\n=== rtkvdec: enable dump video fw log =============\n");
		rtkvdec_dump_enable();
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'd') && (cmd_buf[1] == 'n') && (cmd_buf[2] == 'o') && (count == 4)) {
		pr_notice("\n=== rtkvdec: disable dump video fw log =============\n");
		rtkvdec_dump_disable();
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'd') && (cmd_buf[1] == 'e') && (cmd_buf[2] == 's') && (cmd_buf[3] == '_')) {
		if ((cmd_buf[4] == 'e') && (cmd_buf[5] == 'n')) {
			pr_notice("\n=== rtkvdec: enable dump es =============\n");
			rtkvdec_dumpes_enable(&cmd_buf[7], (count-7)-1);
			pr_notice("\n=======================================\n");
		}
		else if ((cmd_buf[4] == 'd') && (cmd_buf[5] == 'i')) {
			pr_notice("\n=== rtkvdec: disable dump es =============\n");
			rtkvdec_dumpes_disable();
			pr_notice("\n=======================================\n");
		}
		else {
			pr_notice("%s\n", cmd_buf);
		}
	} else if ((cmd_buf[0] == 'p') && (cmd_buf[1] == 'r') &&
			   (cmd_buf[2] == 'd') && (cmd_buf[3] == 'm') &&
			   (cmd_buf[4] == 'g') && (count == 8)) {
		if (cmd_buf[6] == '0')
			rtkvdec_pr_to_dmesg_en = 0;
		else if (cmd_buf[6] == '1')
			rtkvdec_pr_to_dmesg_en = 1;
	} else if ((count == 8) && /* "ibdbg 1\n", "ibdbg 0\n" */
		(cmd_buf[0] == 'i') && (cmd_buf[1] == 'b') && (cmd_buf[2] == 'd') &&
		(cmd_buf[3] == 'b') && (cmd_buf[4] == 'g') && (cmd_buf[5] == ' ')) {
		ibbuf_debug_en = cmd_buf[6] == '1' ? 1 : 0;
		pr_notice("\n=== rtkvdec: enable ib debug===========\n");
		pr_notice("inband debug = %d\n", ibbuf_debug_en);
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'f') && (cmd_buf[1] == 'w') && (cmd_buf[2] == '@')) {
		pr_notice("\n=== rtkvdec: send debug string: =============\n");
		rtkvdec_send_string(&cmd_buf[4], (count-4)-1, 0x3);
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'f') && (cmd_buf[1] == 'w') && (cmd_buf[2] == '1') && (cmd_buf[3] == '@')) {
		pr_notice("\n=== rtkvdec: send debug string: =============\n");
		rtkvdec_send_string(&cmd_buf[5], (count-5)-1, 0x1);
		pr_notice("\n=======================================\n");
	} else if ((cmd_buf[0] == 'f') && (cmd_buf[1] == 'w') && (cmd_buf[2] == '2') && (cmd_buf[3] == '@')) {
		pr_notice("\n=== rtkvdec: send debug string: =============\n");
		rtkvdec_send_string(&cmd_buf[5], (count-5)-1, 0x2);
		pr_notice("\n=======================================\n");
	} else {
		pr_notice("%s\n", cmd_buf);
	}

	return ret;
}

static int rtkvdec_proc_read( struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
	char *str = kmalloc(4096, GFP_KERNEL);
	struct list_head *del_list;
	VDEC_FRAMEINFO_LIST *buf_info_list;
	VDEC_FRAMEINFO_STRUCT *buf_info ;
	int len, total = 0 ;
	len = sprintf(str, "frame_info\n");
	total += len ;

	down(&gst_frame_info_list_sem);
	list_for_each(del_list, &gst_frame_info_head) {
		buf_info_list = list_entry(del_list, VDEC_FRAMEINFO_LIST, buffer_list);
		buf_info = &buf_info_list->frame_info ;
		len = sprintf(str + total, "pid=%d\n", buf_info->pid);
		total += len ;
		len = sprintf(str + total, "frame_dropped=%d\n", buf_info->frame_dropped);
		total += len ;
		len = sprintf(str + total, "frame_displaying=%d\n", buf_info->frame_displaying);
		total += len ;
		len = sprintf(str + total, "frame_matched=%d\n", buf_info->frame_matched);
		total += len ;
		len = sprintf(str + total, "frame_freerun=%d\n\n", buf_info->frame_freerun);
		total += len ;
	}
	up(&gst_frame_info_list_sem);

	if (copy_to_user(buf, str, total)) {
		pr_err("rtkvdec_debug:%d Copy proc data to user space failed\n", __LINE__);
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

static const struct file_operations rtkvdec_proc_fops = {
	.owner = THIS_MODULE,
	.read = rtkvdec_proc_read,
};

struct proc_dir_entry *rtkvdec_proc_dir;
struct proc_dir_entry *rtkvdec_proc_entry;

bool rtkvdec_debug_proc_init(void)
{
	if (rtkvdec_proc_dir == NULL && rtkvdec_proc_entry == NULL) {
		rtkvdec_proc_dir = proc_mkdir(RTKVDEC_PROC_DIR , NULL);

		if (rtkvdec_proc_dir != NULL) {
			rtkvdec_proc_entry =
				proc_create(RTKVDEC_PROC_ENTRY, 0666,
					rtkvdec_proc_dir, &rtkvdec_proc_fops);

			if (rtkvdec_proc_entry == NULL) {
				proc_remove(rtkvdec_proc_dir);
				rtkvdec_proc_dir = NULL;
				pr_err("failed to get proc entry for %s/%s\n", RTKVDEC_PROC_DIR, RTKVDEC_PROC_ENTRY);
				return false;
			}
		} else {
			pr_err("create rtkvdec dir proc entry (%s) failed\n",
				RTKVDEC_PROC_DIR);
			return false;
		}
	}

	return true;
}

bool rtkvdec_debug_proc_uninit(void)
{
	if (rtkvdec_proc_entry) {
		proc_remove(rtkvdec_proc_entry);
		rtkvdec_proc_entry = NULL;
	}

	if (rtkvdec_proc_dir) {
		proc_remove(rtkvdec_proc_dir);
		rtkvdec_proc_dir = NULL;
	}
	return true;
}

struct file_operations rtkvdec_fops = {
	.owner  		= THIS_MODULE,
	.unlocked_ioctl 	= rtkvdec_ioctl,
	.write  		= rtkvdec_write,
	.open   		= rtkvdec_open,
	.release		= rtkvdec_release,
};

static char *rtkvdec_devnode(struct device *dev, mode_t *mode)
{
	*mode = 0666;
	return NULL;
}

DCMT_DEBUG_INFO_DECLARE(DCMT_VDEC,rtkvdec_DCMTCallbackFunction);
//DCMT_DEBUG_INFO_UNREGISTER(DCMT_VDEC,rtkvdec_DCMTCallbackFunction);

static int rtkvdec_init(void)
{
	int result;
	dev_t dev = 0;

	pr_notice("\n\n\n\n *****************  rtkvdec init module  *********************\n\n\n\n");
	if (rtkvdec_major) {
		dev = MKDEV(rtkvdec_major, rtkvdec_minor);
		result = register_chrdev_region(dev, 1, "rtkvdec");
	} else {
		result = alloc_chrdev_region(&dev, rtkvdec_minor, 1, "rtkvdec");
		rtkvdec_major = MAJOR(dev);
	}

	if (result < 0) {
		pr_debug("rtkvdec: can not get chrdev region...\n");
		return result;
	}

        DCMT_DEBUG_INFO_REGISTER(DCMT_VDEC,rtkvdec_DCMTCallbackFunction);

	/* pr_debug("rtkvdec init module major number = %d\n", rtkvdec_major); */

	rtkvdec_class = class_create(THIS_MODULE, "rtkvdec");
	if (IS_ERR(rtkvdec_class)) {
		pr_debug("rtkvdec: can not create class...\n");
		result = PTR_ERR(rtkvdec_class);
		goto fail_class_create;
	}

	rtkvdec_class->devnode = rtkvdec_devnode ;

	rtkvdec_platform_devs = platform_device_register_simple("rtkvdec", -1, NULL, 0);
	if (platform_driver_register(&rtkvdec_device_driver) != 0) {
		pr_debug("rtkvdec: can not register platform driver...\n");
		result = -EINVAL;
		goto fail_platform_driver_register;
	}

	cdev_init(&rtkvdec_cdev, &rtkvdec_fops);
	rtkvdec_cdev.owner = THIS_MODULE;
	rtkvdec_cdev.ops = &rtkvdec_fops;
	result = cdev_add(&rtkvdec_cdev, dev, 1);
	if (result < 0) {
		pr_debug("rtkvdec: can not add character device...\n");
		goto fail_cdev_init;
	}
	rtkvdec_device = device_create(rtkvdec_class, NULL, dev, NULL, "rtkvdec");

	rtkvdec_device->dma_mask = &rtkvdec_device->coherent_dma_mask;
	if(dma_set_mask(rtkvdec_device, DMA_BIT_MASK(32))) {
		pr_err("DMA not supported\n");
	}

#ifdef CONFIG_ARM64
	arch_setup_dma_ops(rtkvdec_device, 0, 0, NULL, false);
#endif

	INIT_LIST_HEAD(&vfw_remote_malloc_info_head);
	INIT_LIST_HEAD(&vfw_remote_malloc_info_specific_head);
	INIT_LIST_HEAD(&gst_frame_info_head);
	INIT_LIST_HEAD(&rtkvdec_alloc_head);

	/* register RPC command ID 0 mapping handler */
	if (register_kernel_rpc(RPC_VCPU_ID_0x102_rtkvdec_remote_malloc, (FUNC_PTR)rtkvdec_remote_malloc) == 1)
		pr_debug("Register rtkvdec_remote_malloc failed!\n");
	if (register_kernel_rpc(RPC_VCPU_ID_0x103_rtkvdec_remote_free, (FUNC_PTR)rtkvdec_remote_free) == 1)
		pr_debug("Register rtkvdec_remote_free failed!\n");
	if (register_kernel_rpc(RPC_VCPU_ID_0x106_rtkvdec_remote_malloc_specific, (FUNC_PTR)rtkvdec_remote_malloc_specific) == 1)
		pr_debug("Register rtkvdec_remote_malloc_specific failed!\n");
	if (register_kernel_rpc(RPC_VCPU_ID_0x107_rtkvdec_remote_free_specific, (FUNC_PTR)rtkvdec_remote_free_specific) == 1)
		pr_debug("Register rtkvdec_remote_free_specific failed!\n");
	if (register_kernel_rpc(RPC_VCPU_FREE_USER_MEM, rtkvdec_free_user_mem) == 1)
		pr_debug("Register rtkvdec_RPC_VCPU_FREE_USER_MEM failed!\n");

	rtkvdec_dump_init() ;
	rtkvdec_VMM_memory_init();

	EncoderMemAddr = rtkvdec_remote_malloc(0x80000, 0x90ABCDEF) ;
	if (!EncoderMemAddr) {
		goto fail_cdev_init;
	}
	EncoderMemState = 0 ;

	rtkvdec_vcreate_tsk = kthread_create(rtkvdec_vcreate_thread, &data2, "rtkvdec_vcreate_thread");
	if (IS_ERR(rtkvdec_vcreate_tsk)) {
		result = PTR_ERR(rtkvdec_vcreate_tsk);
		rtkvdec_vcreate_tsk = NULL;
		goto fail_cdev_init;
	}

	rtkvdec_debug_proc_init();
	rtkvdec_SVP_memory_init();
	rtkvdec_VBM_memory_init();
	rtkvdec_VEProt_memory_init();
	rtkvdec_InbandBuf_init();

#ifdef CONFIG_LG_SNAPSHOT_BOOT
	if(snapshot_enable == 0)
		wake_up_process(rtkvdec_vcreate_tsk);
#else
	wake_up_process(rtkvdec_vcreate_tsk);
#endif

#if 0
	/*[WOSQRTK-4745]fix logo garbage.*/ /*[WOSQRTK-6662]increase logo dealy.*/
	if((bstoplogo_gdma == false) && (is_RTD_K2L() == 0) && Get_DISPLAY_PANEL_CUSTOM_INDEX() != VBY_ONE_PANEL_innolux_4K2K_600M_1S_8L )
	{
		bstoplogo_gdma = true;
		GDMA_ConfigOSDxMixerEnableNoDelay(GDMA_PLANE_OSD2,0);
	}
	else if((bstoplogo_gdma == false) && (is_RTD_K2L() == 0) && (Get_DISPLAY_PANEL_CUSTOM_INDEX() == VBY_ONE_PANEL_innolux_4K2K_600M_1S_8L ) )
	{
		bstoplogo_gdma = true;
		//set tvb4 prority for OSD2 [WOSQRTK-4745]fix logo garbage
		org_tvb4_pro_1 = rtd_inl(DC_PRIORITY_CTRLB_VADDR);
		org_tvb4_pro_2 = rtd_inl(DC2_PRIORITY_CTRLB_VADDR);
		rtd_outl(DC_PRIORITY_CTRLB_VADDR,TVSB4_PRIORITY_VALUE);
		rtd_outl(DC2_PRIORITY_CTRLB_VADDR,TVSB4_PRIORITY_VALUE);
	}
#endif

	return 0;

fail_cdev_init:
	platform_driver_unregister(&rtkvdec_device_driver);
fail_platform_driver_register:
	platform_device_unregister(rtkvdec_platform_devs);
	rtkvdec_platform_devs = NULL;
	class_destroy(rtkvdec_class);
fail_class_create:
	rtkvdec_class = NULL;
	unregister_chrdev_region(dev, 1);
	return result;
}

static void rtkvdec_exit(void)
{
	int i ;
	dev_t dev ;
	rtkvdec_debug_proc_uninit() ;

	if (VMM_start) {
		rtkvdec_remote_free(VMM_start, 0x90ABCDEF);
		for (i = 0; i < RTKVDEC_MAX_VMM_MEM_NUM; i++) {
			VMM_Memory[i].used = 0 ;
			VMM_Memory[i].addr = 0 ;
			VMM_Memory[i].size = 0 ;
		}
		VMM_start = VMM_total = 0 ;
	}

	dev = MKDEV(rtkvdec_major, rtkvdec_minor);

	/* if ((rtkvdec_platform_devs == NULL) || (class_destroy == NULL)) ?? */
	if ((rtkvdec_platform_devs == NULL) || (rtkvdec_class == NULL))
		BUG();

	device_destroy(rtkvdec_class, dev);
	cdev_del(&rtkvdec_cdev);

	platform_driver_unregister(&rtkvdec_device_driver);
	platform_device_unregister(rtkvdec_platform_devs);
	rtkvdec_platform_devs = NULL;

	class_destroy(rtkvdec_class);
	rtkvdec_class = NULL;
           DCMT_DEBUG_INFO_UNREGISTER(DCMT_VDEC,rtkvdec_DCMTCallbackFunction);

	unregister_chrdev_region(dev, 1);
}

late_initcall(rtkvdec_init);
module_exit(rtkvdec_exit);
