/* Kernel Header file */
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>		/* everything... */
#include <linux/cdev.h>
#include <linux/platform_device.h>
#include <linux/string.h>	/* memset */
#include <linux/uaccess.h>    /* copy_from_user */
#include <linux/slab.h>   /* kmalloc */
#include <rtk_kdriver/RPCDriver.h>   /* register_kernel_rpc, send_rpc_command */
#include <asm/cacheflush.h>
//#include <rtk_kdriver/io.h>
#include <mach/platform.h>

#include "rtk_vo.h"
#include "../scaler_vscdev.h"
#include <tvscalercontrol/scalerdrv/scalerdrv.h> /* Scaler_GetShareMemVirAddr */
#include <tvscalercontrol/scalerdrv/zoom_smoothtoggle_lib.h>
#include <tvscalercontrol/scalerdrv/zoom_smoothtoggle.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scalerdrv/scaler_hdr_ctrl.h>
#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>

#include <rpc/VideoRPC_System.h>
#include <rpc/VideoRPC_System_data.h>
#include <linux/pageremap.h> /* dvr_malloc */
#include <linux/dma-contiguous.h>
#include <rbus/dolby_v_top_reg.h>
#include <rtk_kdriver/rtk_crt.h>
#include <tvscalercontrol/scaler_vbedev.h>
#include <rbus/sb2_reg.h>
#include <rbus/timer_reg.h>
#include <tvscalercontrol/vip/scalerColor_tv006.h>
#include <tvscalercontrol/i3ddma/i3ddma.h>

// for register dump
#include <tvscalercontrol/io/ioregdrv.h>
#undef rtd_outl
#define rtd_outl(x, y)     								IoReg_Write32(x,y)
#undef rtd_inl
#define rtd_inl(x)     									IoReg_Read32(x)
#undef rtd_maskl
#define rtd_maskl(x, y, z)     							IoReg_Mask32(x,y,z)
#undef rtd_setbits
#define rtd_setbits(offset, Mask) rtd_outl(offset, (rtd_inl(offset) | Mask))
#undef rtd_clearbits
#define rtd_clearbits(offset, Mask) rtd_outl(offset, ((rtd_inl(offset) & ~(Mask))))

/* //=================== Hardware semaphore =============== // */
/*
#define SB2_HD_SEM_NEW_5_reg 0xB801A634
extern char moduleName[32];

#define SB2_HD_SEM_NEW_5_reg 0xB801A634
#define Get_HD_SEM_NEW_5() while(!IoReg_Read32(SB2_HD_SEM_NEW_5_reg)){printk("#@# %s wait SB2_HD_SEM_NEW_5_reg ready\n", moduleName); msleep(20);}
#define Set_HD_SEM_NEW_5() IoReg_Write32(SB2_HD_SEM_NEW_5_reg, 0);
*/

/*
//#define Get_HD_SEM_NEW_5() do { while (!rtd_inl(SB2_HD_SEM_NEW_5_reg)); } while (0)
//#define Set_HD_SEM_NEW_5() rtd_outl(SB2_HD_SEM_NEW_5_reg, 0);
*/

/*================= IB =============== */
#define IBU_SEQ_BOUND_2_reg                                 0xb805c068

#define IBU_SEQ_REGION_reg                                  0xb805c084
#define IBU_SEQ_REGION_get_region_2_mode(data)              ((0x00007000&(data))>>12)
#define IBU_SEQ_REGION_get_region_3_mode(data)              ((0x00000070&(data))>>4)

#define MODE_DC1       0x0
#define MODE_DC2       0x1
#define MODE_INTER11   0x2
#define MODE_INTER12   0x4
#define MODE_INTER21   0x5
/*==================================== */
#define VOABS(x)   ((x) >= 0 ? (x) : -(x))

#define IVS_START 4
#define IVS_WIDTH 2

static unsigned char force_change_vo_flag[2] = {FALSE, FALSE}; /* If TRUE also need to set VO change flag */
static struct semaphore VO_InfoSemaphore;
static struct semaphore VO_MemChunkSemaphore;
unsigned char vo_info_change_flag[2] = {FALSE, FALSE};
unsigned char adaptive_stream_vo_update_flag[2] = {FALSE, FALSE}; /* This api is for adaptive vo update */
unsigned char voinfo_flag;
unsigned char vo_same_timing = 0;

#define DIRECT_VO_STOP 0xff

VO_DATA *vodma_data; /* allocated in vo_module_init */

unsigned char photo_vo_overscan_flag;
unsigned int photo_h_total;
unsigned int photo_v_total;

static StructDisplayInfo VO_dispinfo[2];

#ifdef CONFIG_I2RND_ENABLE
extern unsigned char vsc_i2rnd_sub_stage;
#endif

#ifdef CONFIG_HDR_SDR_SEAMLESS
static DEFINE_SPINLOCK(VDEC_SEAMLESS_CHANGE_SPINLOCK);/*Spin lock no context switch. When we need to do change SDR and HDR*/
unsigned char vdec_seamless_change_flag = OFF;//i3ddma format need to change
#endif

static dev_t vo_devno; /* vo device number */
static struct cdev vo_cdev;

int vodev_open(struct inode *inode, struct file *filp)
{
	return 0;
}

ssize_t vodev_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	return 0;
}

ssize_t vodev_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	return 0;
}

int vodev_release(struct inode *inode, struct file *filp)
{
	return 0;
}

long vodev_ioctl(struct file *filp, unsigned int cmd,  unsigned long arg)
{
	int ret = 0;

	if (_IOC_TYPE(cmd) != VO_IOC_MAGIC || _IOC_NR(cmd) > VO_IOC_MAXNR) {
		pr_err("VO: ioctl code = %x is invalid!!!!!!!!!!!!!!!\n", cmd);
		return -ENOTTY;
	}

	pr_info("VO: ioctl code = %x\n", cmd);

	switch (cmd) {
	case VO_IOC_OPEN:
		{
		VO_OPEN_CMD_T data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(VO_OPEN_CMD_T))) {
			ret = -EFAULT;
			pr_err("VO: ioctl code = %d failed!!!!!!!!!!!!!!!\n", VO_IOC_OPEN);
		} else {
			ret = VO_Open((VO_OPEN_CMD_T *)&data);

			if (copy_to_user((void __user *)arg, (const void *)&data, sizeof(VO_OPEN_CMD_T))) {
				ret = -EFAULT;
				pr_err("VO: ioctl code = %d failed!!!!!!!!!!!!!!!\n", VO_IOC_OPEN);
			}
		}
		}
		break;
	case VO_IOC_CONFIG:
		{
		VO_CONFIG_CMD_T data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(VO_CONFIG_CMD_T))) {
			ret = -EFAULT;
			pr_err("VO: ioctl code = %d failed!!!!!!!!!!!!!!!\n", VO_IOC_CONFIG);
		} else {
			ret = VO_Config(data.ch, data.cfg);
		}
		}
		break;
	case VO_IOC_DISPLAYPICTTURE:
		{
		VO_DISPLAY_CMD_T data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(VO_DISPLAY_CMD_T))) {
			ret = -EFAULT;
			pr_err("VO: ioctl code = %d failed!!!!!!!!!!!!!!!\n", VO_IOC_DISPLAYPICTTURE);
		} else {
			ret = VO_DisplayPicture(data.ch, data.image, false);
		}
		}
		break;
	case VO_IOC_REDRAWPICTURE:
		{
		unsigned int data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(unsigned int))) {
			ret = -EFAULT;
			pr_err("VO: ioctl code = %d failed!!!!!!!!!!!!!!!\n", VO_IOC_REDRAWPICTURE);
		} else {
			ret = VO_RedrawPicture((unsigned int)data);
		}
		}
		break;
	case VO_IOC_CLOSE:
		{
		unsigned int data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(unsigned int))) {
			ret = -EFAULT;
			pr_err("VO: ioctl code = %d failed!!!!!!!!!!!!!!!\n", VO_IOC_CLOSE);
		} else {
			ret = VO_Close((unsigned int)data);
		}
		}
		break;
	default:
		pr_err("VO: ioctl code = %d is invalid!!!!!!!!!!!!!!!\n", cmd);
		break;
	}

	return ret;
}

const struct file_operations vo_fops = {
	.owner			=	THIS_MODULE,
	.open			=	vodev_open,
	.release		=	vodev_release,
	.read			=	vodev_read,
	.write			=	vodev_write,
	.unlocked_ioctl	=	vodev_ioctl,
};

static struct class *vo_class;
static struct platform_device *vo_platform_devs;
static struct platform_driver vo_platform_driver = {
	.driver = {
		.name	=	"vodev",
		.bus	=	&platform_bus_type,
	},
};

static char *vo_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}

void vo_module_exit(void)
{
	if ((!vo_platform_devs) /*|| (class_destroy == NULL)*/)
		BUG();

	kfree(vodma_data);
	vodma_data = NULL;

	device_destroy(vo_class, vo_devno);
	cdev_del(&vo_cdev);

	platform_driver_unregister(&vo_platform_driver);
	platform_device_unregister(vo_platform_devs);
	vo_platform_devs = NULL;

	class_destroy(vo_class);
	vo_class = NULL;

	unregister_chrdev_region(vo_devno, 1);

	pr_debug("\n\n\n\n *****************  VO module exit  *********************\n\n\n\n");
}

int vo_module_init(void)
{
	int result;
	int ch = 0;
	long ret = 0;
	unsigned char VoReady;

	VoReady = 1;

	pr_debug("\n\n\n\n *****************  VO module init  *********************\n\n\n\n");

	result = alloc_chrdev_region(&vo_devno, 0, 1, "vodevno");

	if (result != 0) {
		pr_crit("Cannot allocate VO device number\n");
		return result;
	}

	vo_class = class_create(THIS_MODULE, "vodev");
	if (IS_ERR(vo_class)) {
		pr_crit("vo: can not create class...\n");
		result = PTR_ERR(vo_class);
		goto fail_class_create;
	}

	vo_class->devnode = vo_devnode;

	vo_platform_devs = platform_device_register_simple("vodev", -1, NULL, 0);
	if (platform_driver_register(&vo_platform_driver) != 0) {
		pr_crit("vo: can not register platform driver...\n");
		result = -ENOMEM;
		goto fail_platform_driver_register;
	}

	cdev_init(&vo_cdev, &vo_fops);
	result = cdev_add(&vo_cdev, vo_devno, 1);
	if (result < 0) {
		pr_crit("vo: can not add character device...\n");
		goto fail_cdev_init;
	}

	device_create(vo_class, NULL, vo_devno, NULL, "vodev");

	vodma_data = kmalloc(sizeof(VO_DATA), GFP_KERNEL);
	if (!vodma_data) {
		result = -ENOMEM;
		vo_module_exit();   /* fail */
		return result;
	}
	sema_init(&VO_InfoSemaphore, 1);
	sema_init(&VO_MemChunkSemaphore, 1);
	memset(vodma_data, 0, sizeof(VO_DATA));

	memset(&VO_dispinfo[0], 0, sizeof(StructDisplayInfo));
	memset(&VO_dispinfo[1], 0, sizeof(StructDisplayInfo));

	for (ch = 0; ch < VODMA_DEV_NUM; ch++)
		vodma_data[0].vo_state[ch] = VO_STATE_INIT;

	for (ch = 0; ch < VODMA_DEV_NUM; ch++)
		vodma_data[0].avsync[ch] = 1;

	/* register RPC command mapping handler */
#ifdef CONFIG_RTK_KDRV_RPC
	if (register_kernel_rpc(RPC_VCPU_ID_0x110_VO_READY, (FUNC_PTR)rpcVoReady) == 1)
		pr_crit("Register RPC VO_READY failed!\n");

	if (register_kernel_rpc(RPC_VCPU_ID_0x111_VO_NOSIGNAL, (FUNC_PTR)rpcVoNoSignal) == 1)
		pr_crit("Register RPC VO_NOSIGNAL failed!\n");

	if (register_kernel_rpc(RPC_VCPU_ID_0x114_VO_AVSYNC, (FUNC_PTR)rpcVoAVSync) == 1)
		pr_crit("Register RPC VO_AVSYNC failed!\n");

	if (register_kernel_rpc(RPC_VCPU_ID_0x112_HDR_FRAMEINFO, (FUNC_PTR)rpcVoHdrFrameInfo) == 1)
		pr_crit("Register RPC HDR_FRAMEINFO failed!\n");

#endif

#ifdef CONFIG_RTK_KDRV_RPC
	if (send_rpc_command(RPC_VIDEO, VIDEO_RPC_VOUT_ToAgent_VoDriverReady, VoReady, 0, &ret))
		pr_crit("VoReady RPC fail!!\n");
#endif

	pr_debug("VO module_init finish\n");
	return 0; /* Success */

fail_cdev_init:
	platform_driver_unregister(&vo_platform_driver);
fail_platform_driver_register:
	platform_device_unregister(vo_platform_devs);
	vo_platform_devs = NULL;
	class_destroy(vo_class);
fail_class_create:
	vo_class = NULL;
	unregister_chrdev_region(vo_devno, 1);
	return result;
}

module_init(vo_module_init);
module_exit(vo_module_exit);

int VBM_ReturnMemChunk(unsigned long buffer_addr, unsigned long buffer_size)
{
	unsigned long result;
	unsigned int vir_addr, vir_addr_noncache;
	unsigned int phy_addr;
	VIDEO_RPC_VBM_RETURNMEMCHUNK *rpc_data;

	if ((buffer_addr == 0) || (buffer_size == 0))
		return -1;

	pr_debug("[vo] Return to VBM: addr %x, size %x\n", (unsigned int)buffer_addr, (unsigned int)buffer_size);
	down(&VO_MemChunkSemaphore);
	vir_addr = (unsigned int)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_VBM_RETURNMEMCHUNK), GFP_DCU1, (void **)&vir_addr_noncache);
	if (vir_addr) {
		phy_addr = (unsigned int)dvr_to_phys((void *)vir_addr);
		rpc_data = (VIDEO_RPC_VBM_RETURNMEMCHUNK *)vir_addr_noncache;
		rpc_data->memChunkAddr = htonl(buffer_addr);
		rpc_data->memChunkSize = htonl(buffer_size);
#ifdef CONFIG_RTK_KDRV_RPC
		if (send_rpc_command(RPC_VIDEO, VIDEO_RPC_ToAgent_ReturnVBMMemChunk, phy_addr, 0, &result) == RPC_FAIL) {
			pr_err("[vo] RPC BorrowVBMMemChunk fail!!\n");
			dvr_free((void *)vir_addr);
			up(&VO_MemChunkSemaphore);
			return -1;
		}
#endif
		dvr_free((void *)vir_addr);
	}
	up(&VO_MemChunkSemaphore);
	return 0;
}

int VBM_BorrowMemChunk(unsigned long *buffer_addr, unsigned long *buffer_size, UINT32 reqSize)
{
	unsigned long result;
	unsigned int vir_addr, vir_addr_noncache;
	unsigned int phy_addr;
	VIDEO_RPC_VBM_BORROWMEMCHUNK *rpc_data;

	if ((!buffer_addr) || (!buffer_size) || (reqSize == 0)) {
		pr_err("[vo] BorrowVBMMemChunk parameter fail!!\n");
		return -1;
	}

	pr_debug("[vo] Borrow from VBM: request size %d\n", reqSize);
	down(&VO_MemChunkSemaphore);
	vir_addr = (unsigned int)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_VBM_BORROWMEMCHUNK), GFP_DCU1, (void **)&vir_addr_noncache);
	if (vir_addr) {
		memset((void *)vir_addr_noncache, 0, sizeof(VIDEO_RPC_VBM_BORROWMEMCHUNK));
		phy_addr = (unsigned int)dvr_to_phys((void *)vir_addr);
		rpc_data = (VIDEO_RPC_VBM_BORROWMEMCHUNK *)vir_addr_noncache;
		rpc_data->memChunkAddr = 0;
		rpc_data->memChunkSize = 0;
		rpc_data->reqSize = htonl(reqSize);
#ifdef CONFIG_RTK_KDRV_RPC
		if (send_rpc_command(RPC_VIDEO, VIDEO_RPC_ToAgent_BorrowVBMMemChunk, phy_addr, 0, &result) == RPC_FAIL) {
			pr_err("[vo] RPC BorrowVBMMemChunk fail!!\n");
			dvr_free((void *)vir_addr);
			up(&VO_MemChunkSemaphore);
			return -1;
		}
#endif
		*buffer_addr = ntohl(*(unsigned int *)vir_addr_noncache);
		*buffer_size = ntohl(*(unsigned int *)(vir_addr_noncache + sizeof(rpc_data->memChunkAddr)));

		pr_debug("[vo] borrow from VBM: addr %x, size %d\n", (unsigned int)*buffer_addr, (unsigned int)*buffer_size);

		dvr_free((void *)vir_addr);
	}

	if (*buffer_addr == 0) {
		up(&VO_MemChunkSemaphore);
		return -1;
	}

	if (*buffer_size < reqSize) {
		VBM_ReturnMemChunk((unsigned long)(*buffer_addr), (unsigned long)(*buffer_size));
		*buffer_addr = 0;
		*buffer_size = 0;
		up(&VO_MemChunkSemaphore);
		return -1;
	}
	up(&VO_MemChunkSemaphore);
	return 0;
}

void vo_free_hal_buffer(unsigned int ch)
{
	VO_DATA *vo = &vodma_data[0];

	int i = 0;
	for (i = 0; i < VODMA_HALBUF_NUM; i++) {
		if (vo->hal_phy_addr[ch][i]) {
			pr_debug("[vo] free buf: hal_phy_addr[%d][%d]:%x\n", ch, i, (unsigned int)vo->phy_addr[ch][i]);
			VBM_ReturnMemChunk(vo->hal_phy_addr[ch][i], vo->hal_buf_size[ch][i]);
			vo->hal_buf_size[ch][i] = 0;
			vo->hal_phy_addr[ch][i] = 0;
		}
	}
}

int vo_malloc_hal_buffer(unsigned int ch)
{
	VO_DATA *vo = &vodma_data[0];
	int reqSize = 0;
	bool DCUSizeDiff = false;

	vo_free_hal_buffer(ch);

	if (is_platform_KXLP()) {
		DCUSizeDiff = true;
	}

	if (1) {
		if (vo->panel_type[ch] == HAL_VO_PANEL_TYPE_UHD)
			reqSize = PANEL_UHD_WIDTH*2*PANEL_UHD_HEIGHT*3;  /* WIDTH*2 for slide */
		else
			reqSize = PANEL_FHD_WIDTH*2*PANEL_FHD_HEIGHT*3;  /* WIDTH*2 for slide */
		pr_debug("[vo][%s] call VBM_BorrowMemChunk\n", __FUNCTION__);

		int i=0;
		for (i = 0; i < VODMA_HALBUF_NUM; i++) { //if anyone fail, then freee all ch hal buffer
			if (VBM_BorrowMemChunk((unsigned long *)(&vo->hal_phy_addr[ch][i]), (unsigned long *)(&vo->hal_buf_size[ch][i]), reqSize) != 0){
				pr_debug("[vo] VBM_BorrowMemChunk fail free buf: hal_phy_addr[%d][%d]:%x\n", ch, i, (unsigned int)vo->phy_addr[ch][i]);
				vo_free_hal_buffer(ch);
				vo->hal_phy_addr[ch][0] = 0;
				vo->hal_phy_addr[ch][1] = 0;
				vo->hal_buf_size[ch][0] = 0;
				vo->hal_buf_size[ch][1] = 0;
				return -1;
			}
		}

	   return 0;

	}

	return -1;
}

void vo_free_photo_buffer(unsigned int ch)
{
	VO_DATA *vo = &vodma_data[0];
	int i = 0;

	for (i = 0; i < VODMA_BUF_NUM; i++) {
		if (vo->phy_addr[ch][i] && vo->phy_addr[ch][i] != INVALID_VAL) {
			pr_debug("[vo] free buf: phy_addr[%d][%d]:%x\n", ch, i, (unsigned int)vo->phy_addr[ch][i]);

			if (vo->borrow_from_vbm[ch][i])
				VBM_ReturnMemChunk(vo->phy_addr[ch][i], vo->borrow_size[ch][i]);
			else
				pli_free(vo->phy_addr[ch][i]);

			vo->borrow_from_vbm[ch][i] = 0;
			vo->borrow_size[ch][i] = 0;
			vo->phy_addr[ch][i] = 0;
		}
	}
}

int vo_malloc_photo_buffer(unsigned int ch, unsigned long *buffer_addr, unsigned int *buffer_size)
{
	VO_DATA *vo = &vodma_data[0];
	int i = 0;
	int reqSize = 0;
	int getSize = 0;
	bool DCUSizeDiff = false;

	vo_free_photo_buffer(ch);

	if (is_platform_KXLP()) {
		DCUSizeDiff = true;
	}

	if (1) {
		reqSize = buffer_size[0] + buffer_size[1];
		pr_debug("[vo][%s][%d] call VBM_BorrowMemChunk\n", __FUNCTION__, __LINE__);
		if (VBM_BorrowMemChunk((unsigned long *)(&buffer_addr[0]), (unsigned long *)(&getSize), reqSize) == 0) {
			buffer_addr[0] = buffer_addr[0];
			buffer_addr[1] = buffer_addr[0] + buffer_size[0];
			vo->borrow_from_vbm[ch][0] = 1;
			vo->borrow_size[ch][0] = getSize;
			vo->borrow_from_vbm[ch][1] = 1;
			vo->borrow_size[ch][1] = 0;
			return 0;
		} else {
			vo_free_photo_buffer(ch);

			reqSize = buffer_size[0];
			pr_debug("[vo][%s][%d] call VBM_BorrowMemChunk\n", __FUNCTION__, __LINE__);
			if (VBM_BorrowMemChunk((unsigned long *)(&buffer_addr[0]), (unsigned long *)(&getSize), reqSize) == 0) {
				vo->borrow_from_vbm[ch][0] = 1;
				vo->borrow_size[ch][0] = getSize;
			}

			reqSize = buffer_size[1];
			pr_debug("[vo][%s][%d] call VBM_BorrowMemChunk\n", __FUNCTION__, __LINE__);
			if (VBM_BorrowMemChunk((unsigned long *)(&buffer_addr[1]), (unsigned long *)(&getSize), reqSize) == 0) {
				vo->borrow_from_vbm[ch][1] = 1;
				vo->borrow_size[ch][1] = getSize;
			}
		}
	}

	for (i = 0; i < VODMA_BUF_NUM; i++) {
		if (buffer_addr[i] == 0) {
			/* if use mixer plane alpha, no need temp buffer for se alpha blending*/
			if (i == (VODMA_BUF_NUM-1))
				return 0;

			buffer_addr[i] = (unsigned long)pli_malloc(buffer_size[i], ((i == (VODMA_BUF_NUM-1)) ? GFP_DCU1_FIRST : GFP_DCU2_FIRST));
			pr_debug("[vo] malloc buf: phy_addr[%d][%d]:%x, size=%d\n", ch, i, (unsigned int)buffer_addr[i], buffer_size[i]);
			if (buffer_addr[i] == INVALID_VAL) {
				pr_err("[vo] error: malloc memory fail\n");
				if (i == (VODMA_BUF_NUM-1)) {
					buffer_addr[i] = 0;
				} else {
					vo_free_photo_buffer(ch);
					return -1;
				}
			}
		}
	}

	return 0;
}

/**
* @brief Open the video output module.
* @param   ch  [in]    channel port number to connect with display engine
* @param   def [in]    video panel type
* @return if success HAL_VO_STATE_OK, else one of error in HAL_VO_STATE_T.
**/
HAL_VO_STATE_T VO_Open(VO_OPEN_CMD_T *cmd)
{
	VO_DATA *vo = &vodma_data[0];
	unsigned int buf_w, buf_h, buf_size;
	unsigned int ch = cmd->ch;
	HAL_VO_PANEL_TYPE panel_type = cmd->def;

	pr_debug("[vo] VO_Open: ch %d, panel %d\n", ch, (int)panel_type);

	if (ch >= VODMA_DEV_NUM) {
		pr_err("[vo] error: ch %d doesn't exist\n", ch);
		return HAL_VO_STATE_NOT_AVAILABLE;
	}

	if (panel_type >= HAL_VO_PANEL_TYPE_MAX || panel_type <= HAL_VO_PANEL_TYPE_NONE) {
		pr_err("[vo] error: panel_type %d doesn't exist\n", panel_type);
		return HAL_VO_STATE_INVALID_PARAM;
	}

	if (vo->vo_state[ch] == VO_STATE_OPEN || vo->vo_state[ch] == VO_STATE_DISPLAY) {
		pr_err("[vo] error: open already\n");
		set_vo_nosignal_flag(ch, 1);
		vo->panel_type[ch] = panel_type;
		vo->videoPlane[ch].Ddomain_Chroma_fmt = FMT_422;
		vo->alpha_blend[ch] = 255;
		vo->vo_state[ch] = VO_STATE_OPEN;
		vo->buf_idx[ch] = 0;
		// 2 hal_buffer
		cmd->buf_addr[0] = vo->hal_phy_addr[ch][0];
		cmd->buf_addr[1] = vo->hal_phy_addr[ch][1];
		cmd->buf_size= vo->hal_buf_size[ch][0];
		pr_err("[vo]error :setup vo_malloc_hal_buffer: phy_addr[0]:%x,[1]:%x,size =%d\n", cmd->buf_addr[0],cmd->buf_addr[1],cmd->buf_size);
		return HAL_VO_STATE_OK;
	}

	if (panel_type == HAL_VO_PANEL_TYPE_UHD) {
		buf_w = PANEL_UHD_WIDTH * 2;  /* for slide */
		buf_h = PANEL_UHD_HEIGHT;
	} else {
		buf_w = PANEL_FHD_WIDTH * 2;  /* for slide */
		buf_h = PANEL_FHD_HEIGHT;
	}

	buf_w = (((buf_w + 511)>>9)<<9);
	buf_h = (((buf_h + 63)>>6)<<6);
	buf_size = buf_w * buf_h; /* buffer sizef for seq yuv420i */
#if 0
	/* yuv420i */
	vo->buffer_size[ch][0] = (buf_size*2); /* y*2  */
	vo->buffer_size[ch][1] = (buf_size); /* c*2  */
	vo->buffer_size[ch][2] = (buf_size*3/2); /* y&c for tmp pic*/

	if (vo_malloc_photo_buffer(ch, vo->phy_addr[ch], vo->buffer_size[ch]) == -1)
		return HAL_VO_STATE_NOT_AVAILABLE;

	vo->phy_addr_y[ch][0] = vo->phy_addr[ch][0];
	vo->phy_addr_y[ch][1] = vo->phy_addr[ch][0] + buf_size;
	vo->phy_addr_c[ch][0] = vo->phy_addr[ch][1];
	vo->phy_addr_c[ch][1] = vo->phy_addr[ch][1] + (buf_size/2);
#else
	/* yuv444sp */
	vo->buffer_size[ch][0] = (buf_size*3);
	vo->buffer_size[ch][1] = (buf_size*3);
	vo->buffer_size[ch][2] = 0;

//	if (vo_malloc_photo_buffer(ch, vo->phy_addr[ch], vo->buffer_size[ch]) == -1)
//		return HAL_VO_STATE_NOT_AVAILABLE;

	vo->phy_addr_y[ch][0] = vo->phy_addr[ch][0];
	vo->phy_addr_y[ch][1] = vo->phy_addr[ch][1];
	vo->phy_addr_c[ch][0] = vo->phy_addr[ch][0];
	vo->phy_addr_c[ch][1] = vo->phy_addr[ch][1];
#endif


	if (vo->phy_addr[ch][2]) {
		vo->phy_addr_y[ch][2] = vo->phy_addr[ch][2];
		vo->phy_addr_c[ch][2] = vo->phy_addr[ch][2] + buf_size;
	} else {
		vo->phy_addr_y[ch][2] = vo->phy_addr_y[ch][0];
		vo->phy_addr_c[ch][2] = vo->phy_addr_c[ch][0];
	}

	set_vo_nosignal_flag(ch, 1);

	vo->panel_type[ch] = panel_type;

	vo->videoPlane[ch].Ddomain_Chroma_fmt = FMT_422;

	vo->alpha_blend[ch] = 255;

	vo->vo_state[ch] = VO_STATE_OPEN;

	vo->buf_idx[ch] = 0;
// 2 hal_buffer
	if (vo_malloc_hal_buffer(ch) == 0) {
		cmd->buf_addr[0] = vo->hal_phy_addr[ch][0];
		cmd->buf_addr[1] = vo->hal_phy_addr[ch][1];
		cmd->buf_size= vo->hal_buf_size[ch][0];
		pr_debug("[vo]vo_malloc_hal_buffer: phy_addr[0]:%x,[1]:%x,size =%d\n", cmd->buf_addr[0],cmd->buf_addr[1],cmd->buf_size);
	} else {
		cmd->buf_addr[0] = 0;
		cmd->buf_addr[1] = 0;
		cmd->buf_size= 0;
	}


	return HAL_VO_STATE_OK;
}

/**
* @brief Configure the video output
* @param   ch  [in]    channel port number to connect with display engine
* @param   cfg [in]    configuration to set video output
* @return if success HAL_VO_STATE_OK, else one of error in HAL_VO_STATE_T.
**/
/* //static int phaze; */
HAL_VO_STATE_T VO_Config(unsigned int ch, HAL_VO_CFG_T cfg)
{
	VO_DATA *vo = &vodma_data[0];

	pr_debug("[vo] VO_Config: ch %d, type %d, value %d\n", ch, (int)cfg.type, cfg.value.alpha);

	if (ch >= VODMA_DEV_NUM) {
		pr_err("[vo] error: ch %d doesn't exist\n", ch);
		return HAL_VO_STATE_NOT_AVAILABLE;
	}

	if (cfg.type >= HAL_VO_CFG_TYPE_MAX || cfg.type <= HAL_VO_CFG_TYPE_NONE) {
		pr_err("[vo] error: type %d invalid\n", cfg.type);
		return HAL_VO_STATE_INVALID_PARAM;
	}

	switch (cfg.type) {
	case HAL_VO_CFG_TYPE_ALPHA_BLEND:
		if ((cfg.value.alpha > 255) || (cfg.value.alpha < 0)) {
			pr_err("[vo] VO_Config: ch %d, alpha %d invalid\n", ch, (int)cfg.value.alpha);
			return HAL_VO_STATE_INVALID_PARAM;
		}
		vo->alpha_blend[ch] = cfg.value.alpha;

#if 0 /* //change photo alpha linearly */
	int tmp_count = 0;
	int tmp_Alpha = (int)vo->alpha_blend[ch];
	int save_Alpha = (int)vo->alpha_blend[ch];

	if (save_Alpha == 255)
		phaze = -2;
	else if (save_Alpha == 0)
		phaze = 2;
	/* //ROSPrintf("phaze:%d\n",phaze); */
	if ((save_Alpha < 255) && (save_Alpha > 0)) {
		while ((tmp_count < 17)) {
			tmp_Alpha = save_Alpha + (phaze*tmp_count);
			if ((tmp_Alpha <= 0) || (tmp_Alpha >= 255))
				break;
			IoReg_Write32(0xb800c0a4, tmp_Alpha);
			tmp_count = tmp_count + 1;
			msleep(1);
			/* //pr_err("############[pool test]config,alpha_reg:%d###############\n", IoReg_Read32(0xb800c0a4)); */
		}
	} else if (save_Alpha == 0) /* //((save_Alpha == 255 )|| (save_Alpha == 0)) { */
		IoReg_Write32(0xb800c0a4, tmp_Alpha);
	}
#endif

		pr_debug("[vo] VO_Config: ch %d, alpha_blend %d\n", ch, (int)vo->alpha_blend[ch]);
		if (vo->vo_state[ch] == VO_STATE_DISPLAY) {
			Mixer_Alpha(vo->alpha_blend[ch]);
			return HAL_VO_STATE_OK;
		}
		break;
	case HAL_VO_CFG_TYPE_PIXEL_FORMAT:
		if ((cfg.value.pixel_format >= HAL_VO_PIXEL_FORMAT_MAX) || (cfg.value.pixel_format <= HAL_VO_PIXEL_FORMAT_NONE)) {
			pr_err("[vo] VO_Config: ch %d, pixel_format %d doesn't exist\n", ch, (int)cfg.value.pixel_format);
			return HAL_VO_STATE_INVALID_PARAM;
		}
		vo->image[ch].pixel_format = cfg.value.pixel_format;
		pr_debug("[vo] VO_Config: ch %d, pixel_format %d\n", ch, (int)vo->image[ch].pixel_format);
		break;
	default:
		pr_err("[vo] error: type %d doesn't exist\n", cfg.type);
		return HAL_VO_STATE_INVALID_PARAM;
	}

	return HAL_VO_STATE_OK;
}

bool VP_Sequential2Block(UINT32 DC_index, UINT32 seqBufAddr, UINT32 width, UINT32 height, UINT32 pitch, UINT32 x_offset, UINT32 y_offset)
{
	unsigned long result;
	unsigned int vir_addr, vir_addr_noncache;
	unsigned int phy_addr;
	VIDEO_RPC_VP_SEQUENTIAL2BLOCK *rpc_data;

	vir_addr = (unsigned int)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_VP_SEQUENTIAL2BLOCK), GFP_DCU1, (void **)&vir_addr_noncache);
	if (vir_addr) {
		phy_addr = (unsigned int)dvr_to_phys((void *)vir_addr);
		rpc_data = (VIDEO_RPC_VP_SEQUENTIAL2BLOCK *)vir_addr_noncache;
		rpc_data->DC_index = htonl(DC_index);
		rpc_data->seqBufAddr = htonl(seqBufAddr);
		rpc_data->width = htonl(width);
		rpc_data->height = htonl(height);
		rpc_data->pitch = htonl(pitch);
		rpc_data->x_offset = htonl(x_offset);
		rpc_data->y_offset = htonl(y_offset);
#ifdef CONFIG_RTK_KDRV_RPC
		if (send_rpc_command(RPC_VIDEO, VIDEO_RPC_ToAgent_VP_Sequential2Block, phy_addr, 0, &result) == RPC_FAIL) {
			pr_err("[vo] RPC VP_Sequential2Block fail!!\n");
			dvr_free((void *)vir_addr);
			return FALSE;
		}
#endif
		dvr_free((void *)vir_addr);
	}
	return TRUE;
};

bool SE_Alpha(UINT32 src_addrY, UINT32 src_addrC, UINT32 dst_addrY, UINT32 dst_addrC, UINT32 width, UINT32 height, UINT32 constAlpha)
{
	unsigned long result;
	unsigned int vir_addr, vir_addr_noncache;
	unsigned int phy_addr;
	VIDEO_RPC_SE_ALPHA *rpc_data;

	vir_addr = (unsigned int)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_SE_ALPHA), GFP_DCU1, (void **)&vir_addr_noncache);
	if (vir_addr) {
		phy_addr = (unsigned int)dvr_to_phys((void *)vir_addr);
		rpc_data = (VIDEO_RPC_SE_ALPHA *)vir_addr_noncache;
		rpc_data->src_addrY = htonl(src_addrY);
		rpc_data->src_addrC = htonl(src_addrC);
		rpc_data->dst_addrY = htonl(dst_addrY);
		rpc_data->dst_addrC = htonl(dst_addrC);
		rpc_data->width = htonl(width);
		rpc_data->height = htonl(height);
		rpc_data->constAlpha = htonl(constAlpha);
#ifdef CONFIG_RTK_KDRV_RPC
		if (send_rpc_command(RPC_VIDEO, VIDEO_RPC_ToAgent_SE_Alpha, phy_addr, 0, &result) == RPC_FAIL) {
			pr_err("[vo] RPC SE_Alpha fail!!\n");
			dvr_free((void *)vir_addr);
			return FALSE;
		}
#endif
		dvr_free((void *)vir_addr);
	}
	return TRUE;
};

bool Mixer_Alpha(unsigned char alpha)
{
	osdovl_mixer_ctrl2_RBUS mixer_ctrl2;
	osdovl_mixer_layer_sel_RBUS mixer_layer_sel;
	osdovl_osd_db_ctrl_RBUS osd_db_ctrl;
	unsigned char layer;
	osdovl_mixer_c0_plane_alpha1_RBUS mixer_plane_alpha1;
	osdovl_mixer_c0_plane_alpha2_RBUS mixer_plane_alpha2;
	osdovl_mixer_c0_plane_offset_RBUS mixer_plane_offset;
	unsigned int mixer_plane_alpha1_reg;
	unsigned int mixer_plane_alpha2_reg;
	unsigned int mixer_plane_offset_reg;
	int timeout;
	int nloop;

	osd_db_ctrl.regValue = rtd_inl(OSDOVL_OSD_Db_Ctrl_reg);
	osd_db_ctrl.db_load = 0;
	rtd_outl(OSDOVL_OSD_Db_Ctrl_reg, osd_db_ctrl.regValue);

	mixer_ctrl2.regValue = rtd_inl(OSDOVL_Mixer_CTRL2_reg);
	if (mixer_ctrl2.mixer_en == 0) {
		mixer_ctrl2.mixer_en = 1;
		rtd_outl(OSDOVL_Mixer_CTRL2_reg, mixer_ctrl2.regValue);
	}

	mixer_layer_sel.regValue = rtd_inl(OSDOVL_Mixer_layer_sel_reg);
	layer = 255;
	if (mixer_layer_sel.c0_sel == 0) { /* 0:video */
		layer = 0;
		mixer_layer_sel.c0_plane_alpha_en = (alpha == 255) ? 0 : 1;
	} else if (mixer_layer_sel.c1_sel == 0) {
		layer = 1;
		mixer_layer_sel.c1_plane_alpha_en = (alpha == 255) ? 0 : 1;
	} else if (mixer_layer_sel.c2_sel == 0) {
		layer = 2;
		mixer_layer_sel.c2_plane_alpha_en = (alpha == 255) ? 0 : 1;
	} else if (mixer_layer_sel.c3_sel == 0) {
		layer = 3;
		mixer_layer_sel.c3_plane_alpha_en = (alpha == 255) ? 0 : 1;
	}

//no Reserved at mac5p
#if 0
	else if (mixer_layer_sel.c4_sel == 0) {
		layer = 4;
		mixer_layer_sel.c4_plane_alpha_en = (alpha == 255) ? 0 : 1;
	} else if (mixer_layer_sel.c5_sel == 0) {
		layer = 5;
		mixer_layer_sel.c5_plane_alpha_en = (alpha == 255) ? 0 : 1;
	}
#endif

	rtd_outl(OSDOVL_Mixer_layer_sel_reg, mixer_layer_sel.regValue);

	if (layer != 255) {
		mixer_plane_alpha1_reg = OSDOVL_Mixer_c0_plane_alpha1_reg + (layer * 3 * 4);
		mixer_plane_alpha2_reg = OSDOVL_Mixer_c0_plane_alpha2_reg + (layer * 3 * 4);
		mixer_plane_offset_reg = OSDOVL_Mixer_c0_plane_offset_reg + (layer * 3 * 4);

		mixer_plane_alpha1.regValue = rtd_inl(mixer_plane_alpha1_reg);
		mixer_plane_alpha1.plane_alpha_a = 255;
		mixer_plane_alpha1.plane_alpha_r = alpha;
		rtd_outl(mixer_plane_alpha1_reg, mixer_plane_alpha1.regValue);

		mixer_plane_alpha2.regValue = rtd_inl(mixer_plane_alpha2_reg);
		mixer_plane_alpha2.plane_alpha_g = alpha;
		mixer_plane_alpha2.plane_alpha_b = alpha;
		rtd_outl(mixer_plane_alpha2_reg, mixer_plane_alpha2.regValue);

		mixer_plane_offset.regValue = rtd_inl(mixer_plane_offset_reg);
		mixer_plane_offset.plane_offset_a = 0;
		mixer_plane_offset.plane_offset_r = 0;
		mixer_plane_offset.plane_offset_g = 0;
		mixer_plane_offset.plane_offset_b = 0;
		rtd_outl(mixer_plane_offset_reg, mixer_plane_offset.regValue);
	}

	osd_db_ctrl.regValue = rtd_inl(OSDOVL_OSD_Db_Ctrl_reg);
	osd_db_ctrl.db_load = 1;
	rtd_outl(OSDOVL_OSD_Db_Ctrl_reg, osd_db_ctrl.regValue);

	/* make sure alpha == 0 while change picture */
	if (alpha == 0) {
		osd_db_ctrl.regValue = rtd_inl(OSDOVL_OSD_Db_Ctrl_reg);
		timeout = 10;
		nloop = 0;
		while (osd_db_ctrl.db_load && nloop < timeout) {
			nloop++;
			msleep(10);
			osd_db_ctrl.regValue = rtd_inl(OSDOVL_OSD_Db_Ctrl_reg);
		}
	}

	return TRUE;
}

void vodma_DCU_Set(UINT32 index, UINT32 st_addr, UINT32 width, UINT32 offset_x, UINT32 offset_y)
{
	unsigned int dc_misc;
	unsigned int dc_pict_set;
	unsigned int dc_pict_set_offset;
	unsigned int page_size;
	unsigned int width_scale;
	unsigned int page_shift;
	unsigned int init_page;
	unsigned int init_page1, init_page2;
	unsigned int page_offset;
	bool DCUSizeDiff = false;

	width_scale = (width+255)/256;

	/* dcu page size config */
	dc_misc = rtd_inl(DC_SYS_DC_SYS_MISC_reg);
	page_size = DC_SYS_DC_SYS_MISC_get_page_size(dc_misc);
	page_shift = 11 + page_size;
	init_page = st_addr >> page_shift;
	init_page1 = init_page;
	init_page2 = init_page;
	page_offset = (rtd_inl(IBU_SEQ_BOUND_2_reg) >> page_shift);

	if (is_platform_KXLP()) {
		DCUSizeDiff = true;
	}

	 /* ib  enable */
	if (IBU_SEQ_REGION_get_region_2_mode(rtd_inl(IBU_SEQ_REGION_reg)) > MODE_DC2 &&
	    IBU_SEQ_REGION_get_region_3_mode(rtd_inl(IBU_SEQ_REGION_reg)) > MODE_DC2 &&
	    (init_page >= page_offset)) {
		if ((width_scale & 1))
			pr_alert("[vo] width_scale not even: %d\n", width_scale);
		if ((init_page & 1)) {
			pr_err("[vo] init_page not even: %d\n", init_page);
			init_page += 1;
		}
		if ((offset_x & 1)) {
			pr_err("[vo] offset_x not even: %d\n", offset_x);
			offset_x &= ~1;
		}

		init_page1 = init_page;
		init_page2 = init_page;
		if (DCUSizeDiff) {
			init_page1 = (init_page - page_offset);
			init_page2 = (init_page - page_offset);
		}

		width_scale = ((width+511)/512)<<1;

		width_scale >>= 1;
		init_page1 >>= 1;
		init_page2 >>= 1;
		offset_x >>= 1;

		if (DCUSizeDiff)
			init_page1 += page_offset;
	}

	/* // get HW semaphore // */
	while (!*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_1_reg))
		udelay(10);

	dc_pict_set = DC_SYS_DC_PICT_SET_pict_width_scale(width_scale) |
		      DC_SYS_DC_PICT_SET_pict_init_page(init_page1);
	rtd_outl(DC_SYS_DC_PICT_SET_reg, dc_pict_set);

	dc_pict_set_offset = DC_SYS_DC_PICT_SET_OFFSET_pict_set_num(index) |
			     DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_x(offset_x >> 4) |
			     DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_y(offset_y >> 2);
	rtd_outl(DC_SYS_DC_PICT_SET_OFFSET_reg, dc_pict_set_offset);

	dc_pict_set = DC_SYS_DC_PICT_SET_pict_width_scale(width_scale) |
		      DC_SYS_DC_PICT_SET_pict_init_page(init_page2);
//	rtd_outl(DC2_SYS_DC_PICT_SET_reg, dc_pict_set);//no Reserved at mac5p

	dc_pict_set_offset = DC_SYS_DC_PICT_SET_OFFSET_pict_set_num(index) |
			     DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_x(offset_x >> 4) |
			     DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_y(offset_y >> 2);
//	rtd_outl(DC2_SYS_DC_PICT_SET_OFFSET_reg, dc_pict_set_offset);//no Reserved at mac5p

	/* // put HW semaphore // */
	*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_1_reg) = 0;
}

unsigned int Mixer_GetCRC(unsigned int ch, unsigned int stable_count)
{
       VO_DATA *vo = &vodma_data[0];
	osdovl_mixer_crc_sel_RBUS mixer_crc_sel;
	osdovl_mixer_crc_ctrl_RBUS mixer_crc_ctrl;
	unsigned int starttime = 0;
	unsigned int crc = 0;
	unsigned int cnt = 0;
	unsigned int sleeptime = 34;

	if (ch >= VODMA_DEV_NUM) {
		pr_err("[vo] error: ch %d doesn't exist\n", ch);
		return HAL_VO_STATE_NOT_AVAILABLE;
	}

	mixer_crc_sel.regValue = rtd_inl(OSDOVL_Mixer_CRC_Sel_reg);
	mixer_crc_sel.mixer_crc_sel = 0; /* //0 : video_input */
	rtd_outl(OSDOVL_Mixer_CRC_Sel_reg, mixer_crc_sel.regValue);

	mixer_crc_ctrl.regValue = rtd_inl(OSDOVL_Mixer_CRC_Ctrl_reg);
	mixer_crc_ctrl.mixer_crc_cont = 1;
	mixer_crc_ctrl.mixer_crc_start = 1;
	rtd_outl(OSDOVL_Mixer_CRC_Ctrl_reg, mixer_crc_ctrl.regValue);

	starttime = rtd_inl(TIMER_SCPU_CLK90K_LO_reg);
	do {
		if (vo->videoPlane[ch].timemode.FrameRate)
			sleeptime = (1000000 + (vo->videoPlane[ch].timemode.FrameRate - 1)) / vo->videoPlane[ch].timemode.FrameRate;

		msleep(sleeptime);

		if ((cnt == 0) || (crc == rtd_inl(OSDOVL_Mixer_CRC_Result_reg))) {
			crc = rtd_inl(OSDOVL_Mixer_CRC_Result_reg);
			cnt = cnt + 1;
		}
	}
	while ((cnt < stable_count) && (rtd_inl(TIMER_SCPU_CLK90K_LO_reg) - starttime < 90 * 200));
	if (cnt < stable_count)
		pr_err("[vo] get crc timeout !\n");

	mixer_crc_ctrl.regValue = rtd_inl(OSDOVL_Mixer_CRC_Ctrl_reg);
	mixer_crc_ctrl.mixer_crc_start = 0;
	rtd_outl(OSDOVL_Mixer_CRC_Ctrl_reg, mixer_crc_ctrl.regValue);

	return crc;
}

bool Mixer_CheckCRC(unsigned int ch, unsigned int golden)
{
	unsigned int crc = 0;
	unsigned int starttime = 0;
	int ret = true;

	starttime = rtd_inl(TIMER_SCPU_CLK90K_LO_reg);
	do {
		crc = Mixer_GetCRC(ch, 2);
	}
	while ((crc == golden) && (rtd_inl(TIMER_SCPU_CLK90K_LO_reg) - starttime < 90 * 1000));
	if (crc == golden) {
		ret = false;
		pr_err("[vo] check crc timeout !\n");
	}

	return ret;
}

/**
* @brief display intput image
* @param   ch  [in]    channel port number to connect with display engine
* @param   image   [in]    image to display at video
* @return if success HAL_VO_STATE_OK, else one of error in HAL_VO_STATE_T.
**/
HAL_VO_STATE_T VO_DisplayPicture(unsigned int ch, HAL_VO_IMAGE_T image, bool bRedraw)
{
	VO_DATA *vo = &vodma_data[0];
	VO_TIMING timemode;
	int ret = 0;
	int i;
	unsigned int buf_w, buf_h, buf_size;
	unsigned int width, height;
	unsigned char dc_idx_v1_y_curr, dc_idx_v1_c_curr, dc_idx_v1_y_curr2, dc_idx_v1_c_curr2;
	unsigned char dc_idx_v2_y_curr, dc_idx_v2_c_curr, dc_idx_v2_y_curr2, dc_idx_v2_c_curr2;
	unsigned char dc_idx_y_tmp, dc_idx_c_tmp;
	unsigned char dcu_idx_y, dcu_idx_c;
	unsigned char dcu_idx_y_tmp, dcu_idx_c_tmp;
	unsigned char dcu_idx_y_out, dcu_idx_c_out;
	bool bDoAlpha;
	vodma_vodma_reg_db_ctrl_RBUS vodma_reg_db_ctrl;
	unsigned int crc;

	pr_debug("[vo] VO_DisplayPicture: ch %d, image %x, redraw %d\n", ch, (unsigned int)image.buf, bRedraw);

	if (!((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_JPEG && Get_DisplayMode_Port(SLR_MAIN_DISPLAY) == ch) ||
	      (Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_JPEG && Get_DisplayMode_Port(SLR_SUB_DISPLAY) == ch))) {
		pr_err("[vo] error: not correct ch %d, m:%d/%d,s:%d/%d\n", ch, Get_DisplayMode_Src(SLR_MAIN_DISPLAY), Get_DisplayMode_Port(SLR_MAIN_DISPLAY), Get_DisplayMode_Src(SLR_SUB_DISPLAY), Get_DisplayMode_Port(SLR_SUB_DISPLAY));
		return HAL_VO_STATE_OK;
	}

	if (ch >= VODMA_DEV_NUM) {
		pr_err("[vo] error: ch %d doesn't exist\n", ch);
		return HAL_VO_STATE_NOT_AVAILABLE;
	}

	if (vo->vo_state[ch] == VO_STATE_INIT) {
		pr_err("[vo] error: not open yet\n");
		return HAL_VO_STATE_ERROR;
	}

	if (!image.buf) {
		pr_err("[vo] error: image buffer %x doesn't exist\n", (unsigned int)image.buf);
		return HAL_VO_STATE_INVALID_PARAM;
	}

	if (image.pixel_format >= HAL_VO_PIXEL_FORMAT_MAX || image.pixel_format <= HAL_VO_PIXEL_FORMAT_NONE) {
		pr_err("[vo] error: image pixel_format %d doesn't exist\n", image.pixel_format);
		return HAL_VO_STATE_INVALID_PARAM;
	}

	if ((image.pixel_format == HAL_VO_PIXEL_FORMAT_PALETTE) ||
	    (image.pixel_format == HAL_VO_PIXEL_FORMAT_YUV444P) ||
	    (image.pixel_format == HAL_VO_PIXEL_FORMAT_YUV422P) ||
	    (image.pixel_format == HAL_VO_PIXEL_FORMAT_YUV420P) ||
	    (image.pixel_format == HAL_VO_PIXEL_FORMAT_YUV224P) ||
	    (image.pixel_format == HAL_VO_PIXEL_FORMAT_YUV224I)) {
		pr_err("[vo] error: unsupport pixel_format %d\n", image.pixel_format);
		return HAL_VO_STATE_INVALID_PARAM;
	}

	if (image.rect.w <= MIN_VO_WIDTH ||
	    image.rect.h <= MIN_VO_HEIGHT ||
	    image.rect.w > MAX_VO_WIDTH ||
	    image.rect.h > MAX_VO_HEIGHT) {
		pr_err("[vo] error: image rect %d/%d/%d/%d invalid\n", image.rect.x, image.rect.y, image.rect.w, image.rect.h);
		return HAL_VO_STATE_INVALID_PARAM;
	}

	if (vo->alpha_blend[ch] == 0)
		crc = Mixer_GetCRC(ch, 2);

	memcpy(&vo->image[ch], &image, sizeof(HAL_VO_IMAGE_T));
	vo->image[ch].rect.x &= ~1;
	if (image.pixel_format == HAL_VO_PIXEL_FORMAT_YUV444SP)
		vo->image[ch].rect.x &= ~0x1f;

	pr_debug("[vo] image: buf %x\n", (unsigned int)vo->image[ch].buf);
	pr_debug("[vo] image: ofs_y %x\n", (unsigned int)vo->image[ch].ofs_y);
	pr_debug("[vo] image: ofs_uv %x\n", (unsigned int)vo->image[ch].ofs_uv);
	pr_debug("[vo] image: len_buf %d\n", vo->image[ch].len_buf);
	pr_debug("[vo] image: stride %d\n", vo->image[ch].stride);
	pr_debug("[vo] image: rect %d/%d/%d/%d\n", vo->image[ch].rect.x, vo->image[ch].rect.y, vo->image[ch].rect.w, vo->image[ch].rect.h);
	pr_debug("[vo] image: pixel_format %d\n", vo->image[ch].pixel_format);

	if (image.pixel_format == HAL_VO_PIXEL_FORMAT_YUV420I || image.pixel_format == HAL_VO_PIXEL_FORMAT_YUV422I) {
		width = vo->image[ch].stride;
		height = (vo->image[ch].rect.y + vo->image[ch].rect.h);
		buf_w = (((vo->image[ch].stride + 511)>>9)<<9);
		buf_h = ((((vo->image[ch].rect.y + vo->image[ch].rect.h) + 63)>>6)<<6);

		buf_size = buf_w * buf_h; /* buffer sizef for seq yuv420i */
		if ((buf_size*2) > vo->buffer_size[ch][0]) {
			if (image.pixel_format == HAL_VO_PIXEL_FORMAT_YUV420I) {
				vo->buffer_size[ch][0] = (buf_size*2); /* y*2  */
				vo->buffer_size[ch][1] = (buf_size); /* c*2  */
				vo->buffer_size[ch][2] = (buf_size*3/2); /* y&c for tmp pic*/
			} else if (image.pixel_format == HAL_VO_PIXEL_FORMAT_YUV422I) {
				vo->buffer_size[ch][0] = (buf_size*2); /* y*2  */
				vo->buffer_size[ch][1] = (buf_size*2); /* c*2  */
				vo->buffer_size[ch][2] = (buf_size*2); /* y&c for tmp pic*/
			}

			if (vo_malloc_photo_buffer(ch, vo->phy_addr[ch], vo->buffer_size[ch]) == -1)
				return HAL_VO_STATE_NOT_AVAILABLE;

			vo->phy_addr_y[ch][0] = vo->phy_addr[ch][0];
			vo->phy_addr_y[ch][1] = vo->phy_addr[ch][0] + buf_size;
			vo->phy_addr_c[ch][0] = vo->phy_addr[ch][1];
			if (image.pixel_format == HAL_VO_PIXEL_FORMAT_YUV420I)
				vo->phy_addr_c[ch][1] = vo->phy_addr[ch][1] + (buf_size/2);
			else if (image.pixel_format == HAL_VO_PIXEL_FORMAT_YUV422I)
				vo->phy_addr_c[ch][1] = vo->phy_addr[ch][1] + buf_size;

			if (vo->phy_addr[ch][2]) {
				vo->phy_addr_y[ch][2] = vo->phy_addr[ch][2];
				vo->phy_addr_c[ch][2] = vo->phy_addr[ch][2] + buf_size;
			} else {
				vo->phy_addr_y[ch][2] = vo->phy_addr_y[ch][vo->buf_idx[ch]];
				vo->phy_addr_c[ch][2] = vo->phy_addr_c[ch][vo->buf_idx[ch]];
			}
		}
		pr_info("[vo] buf: %d/%d/%d, phy_addr[%d][%d]: %x/%x\n", buf_w, buf_h, buf_size, ch, vo->buf_idx[ch], (unsigned int)vo->phy_addr_y[ch][vo->buf_idx[ch]], (unsigned int)vo->phy_addr_c[ch][vo->buf_idx[ch]]);

		width = (((width + 511)>>9)<<9);
		height = (((height + 63)>>6)<<6);

		dc_idx_v1_y_curr = (in_cma_range(NULL, (unsigned long)(vo->phy_addr_y[0][0] >> PAGE_SHIFT))) ? VP_DC1_IDX_VOUT_V1_Y_CURR : VP_DC_IDX_VOUT_V1_Y_CURR;
		dc_idx_v1_c_curr = (in_cma_range(NULL, (unsigned long)(vo->phy_addr_c[0][0] >> PAGE_SHIFT))) ? VP_DC1_IDX_VOUT_V1_C_CURR : VP_DC_IDX_VOUT_V1_C_CURR;
		dc_idx_v1_y_curr2 = (in_cma_range(NULL, (unsigned long)(vo->phy_addr_y[0][1] >> PAGE_SHIFT))) ? VP_DC1_IDX_VOUT_V1_Y_CURR2 : VP_DC_IDX_VOUT_V1_Y_CURR2;
		dc_idx_v1_c_curr2 = (in_cma_range(NULL, (unsigned long)(vo->phy_addr_c[0][1] >> PAGE_SHIFT))) ? VP_DC1_IDX_VOUT_V1_C_CURR2 : VP_DC_IDX_VOUT_V1_C_CURR2;
		dc_idx_v2_y_curr = (in_cma_range(NULL, (unsigned long)(vo->phy_addr_y[1][0] >> PAGE_SHIFT))) ? VP_DC1_IDX_VOUT_V2_Y_CURR : VP_DC_IDX_VOUT_V2_Y_CURR;
		dc_idx_v2_c_curr = (in_cma_range(NULL, (unsigned long)(vo->phy_addr_c[1][0] >> PAGE_SHIFT))) ? VP_DC1_IDX_VOUT_V2_C_CURR : VP_DC_IDX_VOUT_V2_C_CURR;
		dc_idx_v2_y_curr2 = (in_cma_range(NULL, (unsigned long)(vo->phy_addr_y[1][1] >> PAGE_SHIFT))) ? VP_DC1_IDX_VOUT_V2_Y_CURR2 : VP_DC_IDX_VOUT_V2_Y_CURR2;
		dc_idx_v2_c_curr2 = (in_cma_range(NULL, (unsigned long)(vo->phy_addr_c[1][1] >> PAGE_SHIFT))) ? VP_DC1_IDX_VOUT_V2_C_CURR2 : VP_DC_IDX_VOUT_V2_C_CURR2;
		dc_idx_y_tmp = (in_cma_range(NULL, (unsigned long)(vo->phy_addr_y[ch][(VODMA_BUF_NUM - 1)] >> PAGE_SHIFT))) ? VP_DC1_IDX_VOUT_TMP_Y_CURR : VP_DC_IDX_VOUT_TMP_Y_CURR;
		dc_idx_c_tmp = (in_cma_range(NULL, (unsigned long)(vo->phy_addr_c[ch][(VODMA_BUF_NUM - 1)] >> PAGE_SHIFT))) ? VP_DC1_IDX_VOUT_TMP_C_CURR : VP_DC_IDX_VOUT_TMP_C_CURR;

		dcu_idx_y = ((ch == 0) ? ((vo->buf_idx[0]) ? dc_idx_v1_y_curr2 : dc_idx_v1_y_curr) :
					 ((vo->buf_idx[1]) ? dc_idx_v2_y_curr2 : dc_idx_v2_y_curr));
		dcu_idx_c = ((ch == 0) ? ((vo->buf_idx[0]) ? dc_idx_v1_c_curr2 : dc_idx_v1_c_curr) :
					 ((vo->buf_idx[1]) ? dc_idx_v2_c_curr2 : dc_idx_v2_c_curr));
		vodma_DCU_Set(dcu_idx_y, (vo->phy_addr_y[ch][vo->buf_idx[ch]]), width, 0, 0);
		vodma_DCU_Set(dcu_idx_c, (vo->phy_addr_c[ch][vo->buf_idx[ch]]), width, 0, 0);

		dcu_idx_y_tmp = dc_idx_y_tmp;
		dcu_idx_c_tmp = dc_idx_c_tmp;
		vodma_DCU_Set(dcu_idx_y_tmp, (vo->phy_addr_y[ch][(VODMA_BUF_NUM - 1)]), width, 0, 0);
		vodma_DCU_Set(dcu_idx_c_tmp, (vo->phy_addr_c[ch][(VODMA_BUF_NUM - 1)]), width, 0, 0);

		if (vo->alpha_blend[ch] != 255 && vo->alpha_blend[ch] != 0 && vo->phy_addr[ch][(VODMA_BUF_NUM - 1)])
			bDoAlpha = true;
		else
			bDoAlpha = false;

		/* convert to yuv420i */
		if (bDoAlpha) {
			dcu_idx_y_out = dcu_idx_y_tmp;
			dcu_idx_c_out = dcu_idx_c_tmp;
		} else {
			dcu_idx_y_out = dcu_idx_y;
			dcu_idx_c_out = dcu_idx_c;
		}
		pr_debug("[vo] Sequential2Block: ch %d, dst %x/%x\n", ch,
			 ((bDoAlpha) ? (unsigned int)vo->phy_addr_y[ch][(VODMA_BUF_NUM - 1)] : (unsigned int)vo->phy_addr_y[ch][vo->buf_idx[ch]]),
			 ((bDoAlpha) ? (unsigned int)vo->phy_addr_c[ch][(VODMA_BUF_NUM - 1)] : (unsigned int)vo->phy_addr_c[ch][vo->buf_idx[ch]]));
		VP_Sequential2Block(dcu_idx_y_out, (unsigned int)vo->image[ch].ofs_y, width, height, vo->image[ch].stride, 0, 0);
		if (image.pixel_format == HAL_VO_PIXEL_FORMAT_YUV420I)
			VP_Sequential2Block(dcu_idx_c_out, (unsigned int)(vo->image[ch].ofs_uv), width, (height+1)>>1, vo->image[ch].stride, 0, 0);
		else
			VP_Sequential2Block(dcu_idx_c_out, (unsigned int)(vo->image[ch].ofs_uv), width, height, vo->image[ch].stride, 0, 0);

		/* do alpha */
		if (bDoAlpha) {
			pr_debug("[vo] Alpha: ch %d, alpha %d, src %x/%x, dst %x/%x\n", ch, vo->alpha_blend[ch],
				 (unsigned int)(vo->phy_addr_y[ch][(VODMA_BUF_NUM - 1)]), (unsigned int)(vo->phy_addr_c[ch][(VODMA_BUF_NUM - 1)]),
				 (unsigned int)(vo->phy_addr_y[ch][vo->buf_idx[ch]]), (unsigned int)(vo->phy_addr_c[ch][vo->buf_idx[ch]]));
			for (i = 0; i < width; i += MAX_SE_ALPHA_WIDTH) {
				vodma_DCU_Set(dcu_idx_y_tmp, (vo->phy_addr_y[ch][(VODMA_BUF_NUM - 1)]), width, i, 0);
				vodma_DCU_Set(dcu_idx_c_tmp, (vo->phy_addr_c[ch][(VODMA_BUF_NUM - 1)]), width, i, 0);
				vodma_DCU_Set(dcu_idx_y, (vo->phy_addr_y[ch][vo->buf_idx[ch]]), width, i, 0);
				vodma_DCU_Set(dcu_idx_c, (vo->phy_addr_c[ch][vo->buf_idx[ch]]), width, i, 0);
				SE_Alpha(dcu_idx_y_tmp, dcu_idx_c_tmp, dcu_idx_y, dcu_idx_c, (((width - i) > MAX_SE_ALPHA_WIDTH) ? MAX_SE_ALPHA_WIDTH : (width - i)), height, vo->alpha_blend[ch]);
			}
		}

		if (!bRedraw) {
			vo->displayWin[ch].x = vo->image[ch].rect.x;
			vo->displayWin[ch].y = vo->image[ch].rect.y;
			vo->displayWin[ch].w = vo->image[ch].rect.w;
			vo->displayWin[ch].h = vo->image[ch].rect.h;
		}

		/* set dcu offset */
		vodma_DCU_Set(dcu_idx_y, (vo->phy_addr_y[ch][vo->buf_idx[ch]]), width, 0, 0);
		vodma_DCU_Set(dcu_idx_c, (vo->phy_addr_c[ch][vo->buf_idx[ch]]), width, 0, 0);

		/* //k3l support h-offset up to 8192, no need dcu offset */
		/*
		if (vo->displayWin[ch].x >= 2048) {
			vodma_DCU_Set(dcu_idx_y, (vo->phy_addr_y[ch][vo->buf_idx[ch]]), width, ((vo->displayWin[ch].x>>11)<<11), 0);
			vodma_DCU_Set(dcu_idx_c, (vo->phy_addr_c[ch][vo->buf_idx[ch]]), width, ((vo->displayWin[ch].x>>11)<<11), 0);
			vo->displayWin[ch].x -= ((vo->displayWin[ch].x>>11)<<11);
		}
		*/
	} else {

		vo->displayWin[ch].x = vo->image[ch].rect.x;
		vo->displayWin[ch].y = vo->image[ch].rect.y;
		vo->displayWin[ch].w = vo->image[ch].rect.w;
		vo->displayWin[ch].h = vo->image[ch].rect.h;
	}

	vo->videoPlane[ch].Ddomain_Chroma_fmt = ((vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_RGB) ||
						(vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_BGR) ||
						(vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_ARGB) ||
						(vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_ABGR) ||
						(vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_YUV444P) ||
						(vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_YUV444I) ||
						vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_YUV444SP)
						? FMT_444 : FMT_422;

#ifdef __DOLBY_VTOP_422TO444__
	/* //use v_top to transfer 422to444 */
	vodma_set_dolby_vtop_422to444(vo->videoPlane[ch].Ddomain_Chroma_fmt == FMT_422);
	vo->videoPlane[ch].Ddomain_Chroma_fmt = FMT_444;
#endif

	timemode.HWidth = vodma_SeqWidthAlign(vo->displayWin[ch].w, vo->image[ch].pixel_format);
	timemode.VHeight = vo->displayWin[ch].h;
	timemode.HStartPos = (timemode.HWidth == 3840) ? 320 : ((timemode.HWidth > 3840 && timemode.HWidth <= 4096) ? ((4400 - timemode.HWidth) / 2) : 140);
	timemode.VStartPos = 26;
	timemode.isProg = 1;
	if (photo_vo_overscan_flag) {
		timemode.HTotal = photo_h_total;
		timemode.VTotal = photo_v_total;
	} else {
		timemode.HTotal = timemode.HWidth + (timemode.HStartPos * 2);
		timemode.VTotal = timemode.VHeight + (timemode.VStartPos * 2);
		photo_h_total = timemode.HTotal;
		photo_v_total = timemode.VTotal;
	}
	timemode.FrameRate = 30000;
	timemode.SampleRate = (timemode.HTotal * timemode.VTotal * (timemode.FrameRate / 1000) + 9999) / 10000;

	pr_info("[vo] timemode:\n");
	pr_info("[vo] HStartPos %d\n", timemode.HStartPos);
	pr_info("[vo] VStartPos %d\n", timemode.VStartPos);
	pr_info("[vo] HWidth %d\n", timemode.HWidth);
	pr_info("[vo] VHeight %d\n", timemode.VHeight);
	pr_info("[vo] HTotal %d\n", timemode.HTotal);
	pr_info("[vo] VTotal %d\n", timemode.VTotal);
	pr_info("[vo] isProg %d\n", timemode.isProg);
	pr_info("[vo] FrameRate %d\n", timemode.FrameRate);
	pr_info("[vo] SampleRate %d\n", timemode.SampleRate);

	memcpy(&vo->videoPlane[ch].timemode, &timemode, sizeof(VO_TIMING));

	timemode.HWidth = vo->displayWin[ch].w;
	down(&VO_InfoSemaphore);

	if (!((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_JPEG && Get_DisplayMode_Port(SLR_MAIN_DISPLAY) == ch) ||
	      (Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_JPEG && Get_DisplayMode_Port(SLR_SUB_DISPLAY) == ch))) {
		pr_err("[vo] error: not correct ch %d, m:%d/%d,s:%d/%d\n", ch, Get_DisplayMode_Src(SLR_MAIN_DISPLAY), Get_DisplayMode_Port(SLR_MAIN_DISPLAY), Get_DisplayMode_Src(SLR_SUB_DISPLAY), Get_DisplayMode_Port(SLR_SUB_DISPLAY));
		up(&VO_InfoSemaphore);
		return HAL_VO_STATE_OK;
	}

	vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
	vodma_reg_db_ctrl.vodma_db_rdy = 0;
	vodma_reg_db_ctrl.vodmavsg_db_rdy = 0;
	rtd_outl(VODMA_VODMA_REG_DB_CTRL_reg, vodma_reg_db_ctrl.regValue);

	if ((vo->vo_state[ch] == VO_STATE_OPEN) || (vomda_set_voinfo(ch, &timemode, 1) == S_OK)) {
		timemode.HWidth = vodma_SeqWidthAlign(vo->displayWin[ch].w, vo->image[ch].pixel_format);

		/* reset sensio */
		ret = vodma_set_sensio();

		/* timing gen */
		ret = vodma_set_timinggen(&timemode);

		/* vsync gen */
		ret = vodma_set_vsyncgen(ch, &timemode);

		/* dma */
		ret = vodma_set_dma(ch, &timemode);
		rtd_outl(VODMA_VODMA_V1_V_FLIP_reg, vo->updare_seq_ctrl[ch].DMA_v1_seq_v_flip.regValue);
		rtd_outl(VODMA_VODMA_V1_SEQ_reg, vo->updare_seq_ctrl[ch].DMA_v1_staddr.regValue);

		timemode.HWidth = vo->displayWin[ch].w;
		vomda_set_voinfo(ch, &timemode, 1);
		set_vo_run_smooth_toggle_enable(photo_vo_overscan_flag, SLR_MAIN_DISPLAY);
		Config_VO_Dispinfo(&vo->videoPlane[ch].VOInfo);
		if (force_change_vo_flag[ch])
			force_change_vo_flag[ch] = FALSE;
	} else {
		if (force_change_vo_flag[ch]) {
			pr_debug("\r\n####force_change_vo_flag. set vo_info_change_flag TRUE####\r\n");
			vo_info_change_flag[ch] = TRUE;
			force_change_vo_flag[ch] = FALSE;
		}
	}

	/* dma */
	timemode.HWidth = vodma_SeqWidthAlign(vo->displayWin[ch].w, vo->image[ch].pixel_format);
	ret = vodma_set_dma(ch, &timemode);

	vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
	vodma_reg_db_ctrl.vodma_db_rdy = 1;
	vodma_reg_db_ctrl.vodmavsg_db_rdy = 1;
	rtd_outl(VODMA_VODMA_REG_DB_CTRL_reg, vodma_reg_db_ctrl.regValue);

	up(&VO_InfoSemaphore);

	vo->vo_state[ch] = VO_STATE_DISPLAY;

	vo->buf_idx[ch] = vo->buf_idx[ch] ^ 1;

	/* make sure setting of new picture applied before alpha increase */
	if (vo->alpha_blend[ch] == 0) {
		vodma_waitApply();
		Mixer_CheckCRC(ch, crc);
	}
	return HAL_VO_STATE_OK;
}

/**
* @brief re-flush video output
* @param   ch  [in]    channel port number to connect with display engine
* @return if success HAL_VO_STATE_OK, else one of error in HAL_VO_STATE_T.
**/
HAL_VO_STATE_T VO_RedrawPicture(unsigned int ch)
{
	VO_DATA *vo = &vodma_data[0];
	int ret = 0;

	pr_debug("[vo] VO_RedrawPicture: ch %d\n", ch);

	if (ch >= VODMA_DEV_NUM) {
		pr_err("[vo] error: ch %d doesn't exist\n", ch);
		return HAL_VO_STATE_NOT_AVAILABLE;
	}

	if (vo->vo_state[ch] == VO_STATE_INIT) {
		pr_err("[vo] error: not open yet\n");
		return HAL_VO_STATE_ERROR;
	}

	if (vo->vo_state[ch] == VO_STATE_OPEN) {
		pr_err("[vo] error: not display yet\n");
		return HAL_VO_STATE_ERROR;
	}

	if (!&vo->image[ch]) {
		pr_err("[vo] error: image %x doesn't exist\n", (unsigned int)&vo->image[ch]);
		return HAL_VO_STATE_INVALID_PARAM;
	}

	if (!vo->image[ch].buf) {
		pr_err("[vo] error: image buffer %x doesn't exist\n", (unsigned int)vo->image[ch].buf);
		return HAL_VO_STATE_INVALID_PARAM;
	}

	if (vo->image[ch].pixel_format >= HAL_VO_PIXEL_FORMAT_MAX || vo->image[ch].pixel_format <= HAL_VO_PIXEL_FORMAT_NONE) {
		pr_err("[vo] error: image pixel_format %d doesn't exist\n", vo->image[ch].pixel_format);
		return HAL_VO_STATE_INVALID_PARAM;
	}

	if (vo->image[ch].rect.w <= MIN_VO_WIDTH ||
	    vo->image[ch].rect.h <= MIN_VO_HEIGHT ||
	    vo->image[ch].rect.w > MAX_VO_WIDTH ||
	    vo->image[ch].rect.h > MAX_VO_HEIGHT) {
		pr_err("[vo] error: image rect %d/%d/%d/%d invalid\n", vo->image[ch].rect.x, vo->image[ch].rect.y, vo->image[ch].rect.w, vo->image[ch].rect.h);
		return HAL_VO_STATE_INVALID_PARAM;
	}

	if (get_vo_nosignal_flag(ch))
		return HAL_VO_STATE_OK;

	ret = VO_DisplayPicture(ch, vo->image[ch], true);

	return ret;
}

extern void zoom_photo_smooth_toggle_proc(unsigned char display, StructDisplayInfo *vo_disp);
#define INT_POS 16
HAL_VO_STATE_T vo_SetInputRegion(unsigned int ch, unsigned char display, unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	VO_DATA *vo = &vodma_data[ch];
	unsigned int line_cnt;
	vodma_vodma_line_st_RBUS v1_line_status_reg;
	unsigned int line_check = (vo->videoPlane[ch].timemode.VHeight + vo->videoPlane[ch].timemode.VStartPos - 16) * 3/4;
	unsigned int timeout = 0xfffff;

	pr_debug("[vo] vo_SetInputRegion: ch %d, rect %d/%d/%d/%d\n", ch, x, y, w, h);
	vo->displayWin[ch].x = x & ~1;
	vo->displayWin[ch].y = y;
	vo->displayWin[ch].w = w;
	vo->displayWin[ch].h = h;
	photo_vo_overscan_flag = 1;

	while (timeout) {
		v1_line_status_reg.regValue = rtd_inl(VODMA_VODMA_LINE_ST_reg);
		line_cnt = v1_line_status_reg.line_cnt;
		if ((line_cnt < line_check) && (line_cnt >= INT_POS)) {
			if (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_FRAMESYNC)) {
				if (VO_RedrawPicture(ch) == 0)
					zoom_photo_smooth_toggle_proc(display, Get_VO_Dispinfo(ch));
			} else {
				zoom_photo_smooth_toggle_proc(display, Get_VO_Dispinfo(ch));
			}
			break;
		}
		timeout--;
	}
	photo_vo_overscan_flag = 0;

	return HAL_VO_STATE_OK;
}

/**
* @brief Close the video output module.
* @param   ch  [in]    channel port number to connect with display engine
* @return if success HAL_VO_STATE_OK, else one of error in HAL_VO_STATE_T.
**/
HAL_VO_STATE_T VO_Close(unsigned int ch)
{
	VO_DATA *vo = &vodma_data[ch];

	pr_debug("[vo] VO_Close: ch %d\n", ch);

	if (ch >= VODMA_DEV_NUM) {
		pr_err("[vo] error: ch %d doesn't exist\n", ch);
		return HAL_VO_STATE_NOT_AVAILABLE;
	}

	if (vo->vo_state[ch] == VO_STATE_INIT) {
		pr_err("[vo] error: not open yet\n");
		return HAL_VO_STATE_OK;
	}

	set_vo_nosignal_flag(ch, 1);

	vo->vo_state[ch] = VO_STATE_INIT;

	vo_free_photo_buffer(ch);

	vo_free_hal_buffer(ch);

	return HAL_VO_STATE_OK;
}

int vodma_init_pll(void)
{
	unsigned int nMCode, nNCode, nOCode, regValue, busclk = 0;

	/* enable vodma pll */
	rtd_outl(PLL_REG_SYS_PLL_VODMA2_reg, 0x00000004);  /* PLLVODMA power down, hold reset, output disable */
	rtd_outl(PLL_REG_SYS_PLL_VODMA1_reg, 0x00014613);   /* max 600, set 27*(20+2)/(0+1) = 594MHz */
	rtd_outl(PLL_REG_SYS_PLL_VODMA2_reg, 0x00000005);  /* PLLVODMA power on */
	rtd_outl(PLL_REG_SYS_PLL_VODMA2_reg, 0x00000007);  /* release PLLVODMA reset */
	msleep(1); /* //ScalerTimer_DelayXms(0x10); // wait at least > 150us */
	rtd_outl(PLL_REG_SYS_PLL_VODMA2_reg, 0x00000003);  /* PLLVODMA output enable */

	regValue = rtd_inl(PLL_REG_SYS_PLL_VODMA1_reg);
	nMCode = ((regValue & 0x000ff000)>>12);
	nNCode = ((regValue & 0x00300000)>>20);
	nOCode = ((regValue & 0x00000180)>>7);
	busclk = 27000000*(nMCode+2)/(nNCode+1)/(nOCode+1);
	pr_info("[vo] pll_vodma: %d/%d/%d/%d, %x\n", nMCode, nNCode, nOCode, busclk, rtd_inl(PLL_REG_SYS_PLL_VODMA1_reg));

	return 0;
}

int vodma_reset(void)
{
	/*
	* enable vodma clk
	* reset flow: CLKEN=0 -> RSTN=0 -> CLKEN=1 -> CLKEN=0 -> RSTN=1 -> CLKEN=1
	*/

	enum CRT_CLK clken = CLK_ON;

	CRT_CLK_OnOff(SCALER_VO_1, clken, NULL);

	return 0;
}

int vodma_waitApply(void)
{
	int timeout;
	int nloop;
	vodma_vodma_reg_db_ctrl_RBUS vodma_reg_db_ctrl;

	vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);

	timeout = 30;
	nloop = 0;
	while (vodma_reg_db_ctrl.vodma_db_rdy && nloop < timeout) {
		nloop++;
		msleep(10);
		vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
	}

	if (nloop >= timeout)
		pr_err("[vo] wait Apply timeout !\n");

	return 0;
}

int vodma_disable(void)
{
	vodma_vodma_v1_dcfg_RBUS DMA_v1_dcfg;
	vodma_vodma_clkgen_RBUS clkgen;
	vodma_vodma_pvs0_gen_RBUS pvs0;
	vodma_vodma_reg_db_ctrl_RBUS vodma_reg_db_ctrl;

	/* interrupt disable */
	rtd_outl(VODMA_VODMA_VGIP_INTPOS_reg, 0x0);
	rtd_outl(VODMA_VODMA_VGIP_INTST_reg, 0x7);

	/* vodma_go disable, stop fetch data */
	DMA_v1_dcfg.regValue = rtd_inl(VODMA_VODMA_V1_DCFG_reg);
	DMA_v1_dcfg.vodma_go = 0;
	rtd_outl(VODMA_VODMA_V1_DCFG_reg, DMA_v1_dcfg.regValue);

	vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
	vodma_reg_db_ctrl.vodma_db_rdy = 1;
	rtd_outl(VODMA_VODMA_REG_DB_CTRL_reg, vodma_reg_db_ctrl.regValue);

	vodma_waitApply();

	/* clk disable */
	clkgen.regValue = rtd_inl(VODMA_VODMA_CLKGEN_reg);
	clkgen.vodma_enclk = 0;
	rtd_outl(VODMA_VODMA_CLKGEN_reg, clkgen.regValue);
	pvs0.regValue = rtd_inl(VODMA_VODMA_PVS0_Gen_reg);
	pvs0.en_pvgen = 0;
	rtd_outl(VODMA_VODMA_PVS0_Gen_reg, pvs0.regValue);

	vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
	vodma_reg_db_ctrl.vodmavsg_db_rdy = 1;
	rtd_outl(VODMA_VODMA_REG_DB_CTRL_reg, vodma_reg_db_ctrl.regValue);

	return 0;
}

int vodma_SeqWidthAlign(int width, HAL_VO_PIXEL_FORMAT pxlfmt)
{
	unsigned int width_align = width;
	vodma_vodma_dma_option_RBUS dma_option;

	unsigned int data_bit_width = 8; /* dat bit fixed in 8 bit */
	unsigned char chroma_bit_width = 1;

	dma_option.regValue = rtd_inl(VODMA_VODMA_dma_option_reg);

	if (pxlfmt == HAL_VO_PIXEL_FORMAT_YUV422YUYV)
		chroma_bit_width = 2;
	else if (pxlfmt == HAL_VO_PIXEL_FORMAT_RGB || pxlfmt == HAL_VO_PIXEL_FORMAT_BGR || pxlfmt == HAL_VO_PIXEL_FORMAT_YUV444SP)
		chroma_bit_width = 3;
	else if (pxlfmt == HAL_VO_PIXEL_FORMAT_ARGB || pxlfmt == HAL_VO_PIXEL_FORMAT_ABGR)
		chroma_bit_width = 4;
	else
		chroma_bit_width = 1;

	switch (chroma_bit_width * data_bit_width) {
	case 16:
		if (dma_option.burst_len == 0) /* burst 32x128 bits */
			width_align = ((width + ((1 << 8) - 1)) >> 8) << 8; /* 256 pixel align */
		else
			width_align = ((width + ((1 << 9) - 1)) >> 9) << 9; /* 512 pixel align */
		break;
	/* // dat bit fixed in 8 bit */
	/*
	case 20:
		if (dma_option.burst_len == 0)  //burst 32x128 bits
			width_align = ((width + ((1 << 10) - 1)) >> 10) << 10; // 1024 pixel align
		else
			width_align = ((width + ((1 << 11) - 1)) >> 11) << 11; // 2048 pixel align
		break;
	*/
	case 24:
		if (dma_option.burst_len == 0) /* burst 32x128 bits */
			width_align = ((width + ((1 << 9) - 1)) >> 9) << 9; /* 512 pixel align */
		else
			width_align = ((width + ((1 << 10) - 1)) >> 10) << 10; /* 1024 pixel align */
		break;
	/* // dat bit fixed in 8 bit */
	/*
	case 30:
		if (dma_option.burst_len == 0) //burst 32x128 bits
			width_align = ((width + ((1 << 11) - 1)) >> 11) << 11; // 2048 pixel align
		else
			width_align = ((width + ((1 << 12) - 1)) >> 12) << 12; // 4096 pixel align
		break;
	*/
	case 32:
		if (dma_option.burst_len == 0) /* burst 32x128 bits */
			width_align = ((width + ((1 << 7) - 1)) >> 7) << 7; /* 128 pixel align */
		else
			width_align = ((width + ((1 << 8) - 1)) >> 8) << 8; /* 256 pixel align */
		break;
	default:
		break;
	}

	return width_align;
}

#ifdef __DOLBY_VTOP_422TO444__
void vodma_set_dolby_vtop_422to444(bool bEnable)
{
	dolby_v_top_top_ctl_RBUS top_ctl_reg;
	dolby_v_top_top_d_buf_RBUS top_d_buf_reg;

	top_ctl_reg.regValue = rtd_inl(DOLBY_V_TOP_TOP_CTL_reg);
	top_ctl_reg.en_422to444_1 = (bEnable ? 1 : 0);
	rtd_outl(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue);

	top_d_buf_reg.regValue = rtd_inl(DOLBY_V_TOP_TOP_D_BUF_reg);
	top_d_buf_reg.dolby_double_apply = 1;
	rtd_outl(DOLBY_V_TOP_TOP_D_BUF_reg, top_d_buf_reg.regValue);
}
#endif

int updateVODMASetting(unsigned int ch)
{
	VO_DATA *vo = &vodma_data[0];
	vodma_vodma_reg_db_ctrl_RBUS    vodma_reg_db_ctrl;

	ch = 0;

	if (!((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_JPEG && Get_DisplayMode_Port(SLR_MAIN_DISPLAY) == ch) ||
	      (Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_JPEG && Get_DisplayMode_Port(SLR_SUB_DISPLAY) == ch))) {
		return 0;
	}

	if (ch >= VODMA_DEV_NUM) {
		return 0;
	}

	if (vo->vo_state[ch] == VO_STATE_INIT) {
		return 0;
	}

	if (vo->updare_seq_ctrl[ch].f_update && (rtd_inl(VODMA_VODMA_LINE_ST_reg) >= (vo->videoPlane[ch].timemode.VHeight + vo->videoPlane[ch].timemode.VStartPos))) {

		vo->updare_seq_ctrl[ch].f_update = 0;

		rtd_outl(VODMA_VODMA_V1_V_FLIP_reg, vo->updare_seq_ctrl[ch].DMA_v1_seq_v_flip.regValue);

		rtd_outl(VODMA_VODMA_V1_SEQ_reg, vo->updare_seq_ctrl[ch].DMA_v1_staddr.regValue);

		vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
		vodma_reg_db_ctrl.vodma_db_rdy = 1;
		rtd_outl(VODMA_VODMA_REG_DB_CTRL_reg, vodma_reg_db_ctrl.regValue);
	}

	return 0;
}

int vodma_set_dma(unsigned int ch, VO_TIMING *tmode)
{
	VO_DATA *vo = &vodma_data[0];
	vodma_vodma_reg_db_ctrl_RBUS    vodma_reg_db_ctrl;
	vodma_vodma_v1_dcfg_RBUS        DMA_v1_dcfg;
	vodma_vodma_v1_dsize_RBUS       DMA_v1_dsize;
	vodma_vodma_vd1_ads_RBUS        DMA_v1_YC;
	vodma_vodma_v1_seq_RBUS         DMA_v1_staddr;
	vodma_vodma_v1_blk1_RBUS        DMA_v1_blk1;
	vodma_vodma_v1_blk2_RBUS        DMA_v1_blk2;
	vodma_vodma_v1_blk3_RBUS        DMA_v1_blk3;
	vodma_vodma_v1_blk4_RBUS        DMA_v1_blk4;
	vodma_vodma_v1_blk5_RBUS        DMA_v1_blk5;
	vodma_vodma_v1_v_flip_RBUS      DMA_v1_seq_v_flip;
	vodma_vodma_v1chroma_fmt_RBUS   V1_C_up_fmt;
	vodma_vodma_v1_cu_RBUS          V1_C_up_mode420;
	vodma_vodma_v1422_to_444_RBUS   V1_C_up_mode422;
	vodma_vodma_line_select_RBUS    line_sel;
	vodma_vodma_v1vgip_hact_RBUS    vodma_v1vgip_hact_reg;
	vodma_vodma_quincunx_setting_RBUS quincunx;
	vodma_vodma_dma_option_RBUS     dma_option;
	unsigned char seq_color_swap = 0;
	unsigned char encfmt = 4;
	unsigned char dc_idx_v1_y_curr, dc_idx_v1_c_curr, dc_idx_v1_y_curr2, dc_idx_v1_c_curr2;
	unsigned char dc_idx_v2_y_curr, dc_idx_v2_c_curr, dc_idx_v2_y_curr2, dc_idx_v2_c_curr2;
	unsigned char dcu_idx_y, dcu_idx_c;
	unsigned int luma_x, luma_y, chroma_x, chroma_y;
	unsigned char data_bit_width, chroma_bit_width;
	unsigned int TotalBits;
	unsigned int starttime;

	DMA_v1_dcfg.regValue = rtd_inl(VODMA_VODMA_V1_DCFG_reg);
	DMA_v1_dsize.regValue = rtd_inl(VODMA_VODMA_V1_DSIZE_reg);
	vodma_v1vgip_hact_reg.regValue = rtd_inl(VODMA_VODMA_V1VGIP_HACT_reg);
	DMA_v1_YC.regValue = rtd_inl(VODMA_VODMA_VD1_ADS_reg);
	DMA_v1_staddr.regValue = rtd_inl(VODMA_VODMA_V1_SEQ_reg);
	DMA_v1_blk1.regValue = rtd_inl(VODMA_VODMA_V1_BLK1_reg);
	DMA_v1_blk2.regValue = rtd_inl(VODMA_VODMA_V1_BLK2_reg);
	DMA_v1_blk3.regValue = rtd_inl(VODMA_VODMA_V1_BLK3_reg);
	DMA_v1_blk4.regValue = rtd_inl(VODMA_VODMA_V1_BLK4_reg);
	DMA_v1_blk5.regValue = rtd_inl(VODMA_VODMA_V1_BLK5_reg);
	V1_C_up_fmt.regValue = rtd_inl(VODMA_VODMA_V1CHROMA_FMT_reg);
	V1_C_up_mode420.regValue = rtd_inl(VODMA_VODMA_V1_CU_reg);
	V1_C_up_mode422.regValue = rtd_inl(VODMA_VODMA_V1422_TO_444_reg);
	line_sel.regValue = rtd_inl(VODMA_VODMA_LINE_SELECT_reg);
	quincunx.regValue = rtd_inl(VODMA_VODMA_quincunx_setting_reg);
	dma_option.regValue = rtd_inl(VODMA_VODMA_dma_option_reg);

	vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
	vodma_reg_db_ctrl.vodma_db_rdy = 0;
	rtd_outl(VODMA_VODMA_REG_DB_CTRL_reg, vodma_reg_db_ctrl.regValue);

	if (vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_YUV422YUYV)
		chroma_bit_width = 2;
	else if (vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_RGB || vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_BGR || vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_YUV444SP)
		chroma_bit_width = 3;
	else if (vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_ARGB || vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_ABGR)
		chroma_bit_width = 4;
	else
		chroma_bit_width = 1;

	DMA_v1_dcfg.merge_forward = 0;
	DMA_v1_dcfg.merge_backward = 0;
	DMA_v1_dcfg.pd_switch = 0;
	DMA_v1_dcfg.pd_seq = 0;
	DMA_v1_dcfg.film_condition = 0;

	DMA_v1_dcfg.field_mode = 0;
	DMA_v1_dcfg.field_fw = 0;
	DMA_v1_dcfg.l_flag_fw = 0;
	DMA_v1_dcfg.force_2d_en = 0;
	DMA_v1_dcfg.force_2d_sel = 0;
	DMA_v1_dcfg.dma_auto_mode = 0;

	DMA_v1_dcfg.seq_data_pack_type = 0; /* Sequence Mode v_flip_en only support line base */
	DMA_v1_dcfg.seq_data_width = 0; /* 8 bits*/

	DMA_v1_dcfg.double_chroma = ((vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_YUV420I) || (vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_YUV420P)) ? 1 : 0;
	DMA_v1_dcfg.uv_off = (vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_GRAYSCALE || vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_YUV400 || vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_ALPHAGRAYSCALE) ? 1 : 0;
	DMA_v1_dcfg.pxl_swap_sel = 15;
	DMA_v1_dcfg.keep_go_en = 0;
	DMA_v1_dcfg.dma_state_reset_en = 1;
	DMA_v1_dcfg.v_flip_en = 0;
	DMA_v1_dcfg.chroma_swap_en = 0;
	DMA_v1_dcfg.double_pixel_mode = 0;

	DMA_v1_dcfg.dma_mode = (vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_YUV420I || vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_YUV422I || vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_YUV444I) ? 1 : 0;
	DMA_v1_dcfg.vodma_go = 1;

	if ((tmode->HWidth == 0) || (tmode->VHeight == 0)) {
		pr_err("[vo] invalid w/h[%d/%d]\n", tmode->HWidth, tmode->VHeight);
		return 0;
	}
	DMA_v1_dsize.p_y_len = tmode->HWidth;
	DMA_v1_dsize.p_y_nline = tmode->VHeight;

	dc_idx_v1_y_curr = (in_cma_range(NULL, vo->phy_addr_y[0][0] >> PAGE_SHIFT)) ? VP_DC1_IDX_VOUT_V1_Y_CURR : VP_DC_IDX_VOUT_V1_Y_CURR;
	dc_idx_v1_c_curr = (in_cma_range(NULL, vo->phy_addr_c[0][0] >> PAGE_SHIFT)) ? VP_DC1_IDX_VOUT_V1_C_CURR : VP_DC_IDX_VOUT_V1_C_CURR;
	dc_idx_v1_y_curr2 = (in_cma_range(NULL, vo->phy_addr_y[0][1] >> PAGE_SHIFT)) ? VP_DC1_IDX_VOUT_V1_Y_CURR2 : VP_DC_IDX_VOUT_V1_Y_CURR2;
	dc_idx_v1_c_curr2 = (in_cma_range(NULL, vo->phy_addr_c[0][1] >> PAGE_SHIFT)) ? VP_DC1_IDX_VOUT_V1_C_CURR2 : VP_DC_IDX_VOUT_V1_C_CURR2;
	dc_idx_v2_y_curr = (in_cma_range(NULL, vo->phy_addr_y[1][0] >> PAGE_SHIFT)) ? VP_DC1_IDX_VOUT_V2_Y_CURR : VP_DC_IDX_VOUT_V2_Y_CURR;
	dc_idx_v2_c_curr = (in_cma_range(NULL, vo->phy_addr_c[1][0] >> PAGE_SHIFT)) ? VP_DC1_IDX_VOUT_V2_C_CURR : VP_DC_IDX_VOUT_V2_C_CURR;
	dc_idx_v2_y_curr2 = (in_cma_range(NULL, vo->phy_addr_y[1][1] >> PAGE_SHIFT)) ? VP_DC1_IDX_VOUT_V2_Y_CURR2 : VP_DC_IDX_VOUT_V2_Y_CURR2;
	dc_idx_v2_c_curr2 = (in_cma_range(NULL, vo->phy_addr_c[1][1] >> PAGE_SHIFT)) ? VP_DC1_IDX_VOUT_V2_C_CURR2 : VP_DC_IDX_VOUT_V2_C_CURR2;
	dcu_idx_y = ((vo->buf_idx[ch]) ? ((ch == 0) ? dc_idx_v1_y_curr2 : dc_idx_v2_y_curr2) : ((ch == 0) ? dc_idx_v1_y_curr : dc_idx_v2_y_curr));
	dcu_idx_c = ((vo->buf_idx[ch]) ? ((ch == 0) ? dc_idx_v1_c_curr2 : dc_idx_v2_c_curr2) : ((ch == 0) ? dc_idx_v1_c_curr : dc_idx_v2_c_curr));
	DMA_v1_YC.p_y_ads = dcu_idx_y;
	DMA_v1_YC.p_u_ads = dcu_idx_c;
	DMA_v1_YC.p_v_ads = dcu_idx_c;

	DMA_v1_staddr.st_adr = (((unsigned int)(vo->image[ch].buf + (vo->displayWin[ch].y * vo->image[ch].stride * chroma_bit_width) + (vo->displayWin[ch].x * chroma_bit_width)) & ~0xf)) >> 3;

	luma_x = vo->displayWin[ch].x;
	chroma_x = vo->displayWin[ch].x;
	luma_y = vo->displayWin[ch].y;
	chroma_y = luma_y/2;
	DMA_v1_blk1.y_ha_shift = (luma_x%16);
	DMA_v1_blk4.y_h_offset = (luma_x/16)<<1;
	DMA_v1_blk5.u_h_offset = (chroma_x/16)<<1;
	DMA_v1_blk5.v_h_offset = (chroma_x/16)<<1;
	DMA_v1_blk2.p_y_offset = luma_y;
	DMA_v1_blk2.p_u_offset = chroma_y;
	DMA_v1_blk3.p_v_offset = chroma_y;

	/* workaround for h_offset */
	if (DMA_v1_dcfg.dma_mode && DMA_v1_blk1.y_ha_shift) {
		vodma_v1vgip_hact_reg.h_end = tmode->HStartPos + tmode->HWidth;
		vodma_v1vgip_hact_reg.h_st = tmode->HStartPos - DMA_v1_blk1.y_ha_shift;
		DMA_v1_dsize.p_y_len = tmode->HWidth + DMA_v1_blk1.y_ha_shift;
		DMA_v1_dsize.p_y_nline = tmode->VHeight;
		DMA_v1_blk1.y_ha_shift = 0;
	} else {
		vodma_v1vgip_hact_reg.h_end = tmode->HStartPos + tmode->HWidth;
		vodma_v1vgip_hact_reg.h_st = tmode->HStartPos;
		DMA_v1_dsize.p_y_len = tmode->HWidth;
		DMA_v1_dsize.p_y_nline = tmode->VHeight;
	}

	if (1) { /* yuv444sp slide need line step */
		data_bit_width = (DMA_v1_dcfg.seq_data_width) ? 10 : 8;
		TotalBits = vo->image[ch].stride * data_bit_width * chroma_bit_width;
		DMA_v1_dcfg.v_flip_en = 1;
		DMA_v1_seq_v_flip.regValue = rtd_inl(VODMA_VODMA_V1_V_FLIP_reg);
		DMA_v1_seq_v_flip.line_step = -((TotalBits+127)/128);
	} else {
		DMA_v1_dcfg.v_flip_en = 0;
		DMA_v1_seq_v_flip.line_step = 0;
	}

	V1_C_up_fmt.g_position = 0;
	V1_C_up_fmt.alpha_position = 0;
	switch (vo->image[ch].pixel_format) {
	case HAL_VO_PIXEL_FORMAT_YUV422YUYV:
		seq_color_swap = 2;
#ifdef __DOLBY_VTOP_422TO444__
		encfmt = 3; /* //use v_top to transfer 422to444 */
#else
		encfmt = (vo->videoPlane[ch].Ddomain_Chroma_fmt == FMT_444) ? 2 : 3;
#endif
		break;
	case HAL_VO_PIXEL_FORMAT_RGB:
		seq_color_swap = 0;
		encfmt = 4;
		break;
	case HAL_VO_PIXEL_FORMAT_YUV444SP:
		seq_color_swap = 4;
		encfmt = 4;
		break;
	case HAL_VO_PIXEL_FORMAT_BGR:
		seq_color_swap = 5;
		encfmt = 4;
		break;
	case HAL_VO_PIXEL_FORMAT_ABGR:
		seq_color_swap = 5;
		encfmt = 5;
		break;
	case HAL_VO_PIXEL_FORMAT_YUV420I:
#ifdef __DOLBY_VTOP_422TO444__
		if (DMA_v1_dcfg.double_chroma)
			encfmt = 3; /* //use v_top to transfer 422to444 */
		else
			encfmt = 0; /* //use v_top to transfer 422to444 */
#else
		if (DMA_v1_dcfg.double_chroma)
			encfmt = (vo->videoPlane[ch].Ddomain_Chroma_fmt == FMT_444) ? 2 : 3;
		else
			encfmt = (vo->videoPlane[ch].Ddomain_Chroma_fmt == FMT_444) ? 1 : 0;
#endif
		break;
	case HAL_VO_PIXEL_FORMAT_YUV422I:
#ifdef __DOLBY_VTOP_422TO444__
		encfmt = 3; /* //use v_top to transfer 422to444 */
#else
		encfmt = (vo->videoPlane[ch].Ddomain_Chroma_fmt == FMT_444) ? 2 : 3;
#endif
		break;
	case HAL_VO_PIXEL_FORMAT_ARGB:
	default:
		seq_color_swap = 0;
		encfmt = 5;
		break;
	}
	V1_C_up_fmt.seq_color_swap = seq_color_swap;
	V1_C_up_fmt.encfmt = encfmt;

	V1_C_up_mode420.mode = 0;
	V1_C_up_mode422.fir422_sel = 0;

	line_sel.y1_line_select = 0;
	line_sel.c1_line_select = 0;

	quincunx.regValue = rtd_inl(VODMA_VODMA_quincunx_setting_reg);
	quincunx.hori_drop_en = 0;
	quincunx.quincunx_int_en = 0;

	dma_option.regValue = rtd_inl(VODMA_VODMA_dma_option_reg);
	dma_option.burst_len = 1;
	dma_option.blockmode_sel_c = 0; /* 8bits */
	dma_option.blockmode_sel_y = 0; /* 8bits */
	dma_option.cmd_trans_en = 0;

	if (1) {
		vo->updare_seq_ctrl[ch].DMA_v1_staddr.regValue = DMA_v1_staddr.regValue;
		vo->updare_seq_ctrl[ch].DMA_v1_seq_v_flip.regValue = DMA_v1_seq_v_flip.regValue;
		vo->updare_seq_ctrl[ch].f_update = 1;
	} else {
		rtd_outl(VODMA_VODMA_V1_SEQ_reg, DMA_v1_staddr.regValue);
	}

	rtd_outl(VODMA_VODMA_V1_DCFG_reg, DMA_v1_dcfg.regValue);
	rtd_outl(VODMA_VODMA_V1_DSIZE_reg, DMA_v1_dsize.regValue);
	rtd_outl(VODMA_VODMA_V1VGIP_HACT_reg, vodma_v1vgip_hact_reg.regValue);
	rtd_outl(VODMA_VODMA_VD1_ADS_reg, DMA_v1_YC.regValue);
	rtd_outl(VODMA_VODMA_V1_BLK1_reg, DMA_v1_blk1.regValue);
	rtd_outl(VODMA_VODMA_V1_BLK2_reg, DMA_v1_blk2.regValue);
	rtd_outl(VODMA_VODMA_V1_BLK3_reg, DMA_v1_blk3.regValue);
	rtd_outl(VODMA_VODMA_V1_BLK4_reg, DMA_v1_blk4.regValue);
	rtd_outl(VODMA_VODMA_V1_BLK5_reg, DMA_v1_blk5.regValue);
	rtd_outl(VODMA_VODMA_V1CHROMA_FMT_reg, V1_C_up_fmt.regValue);
	rtd_outl(VODMA_VODMA_V1_CU_reg, V1_C_up_mode420.regValue);
	rtd_outl(VODMA_VODMA_V1422_TO_444_reg, V1_C_up_mode422.regValue);
	rtd_outl(VODMA_VODMA_LINE_SELECT_reg, line_sel.regValue);
	rtd_outl(VODMA_VODMA_quincunx_setting_reg, quincunx.regValue);
	rtd_outl(VODMA_VODMA_dma_option_reg, dma_option.regValue);

	vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
	vodma_reg_db_ctrl.vodma_db_rdy = 1;
	rtd_outl(VODMA_VODMA_REG_DB_CTRL_reg, vodma_reg_db_ctrl.regValue);

	return 0;
}

int vodma_set_timinggen(VO_TIMING *tmode)
{
	vodma_vodma_v1sgen_RBUS         V1_syncGen;
	vodma_vodma_v1int_RBUS          V1_syncGen_mode;
	vodma_vodma_v1vgip_ivs1_RBUS    V1_vgipPos_topIVS;
	vodma_vodma_v1vgip_ivs2_RBUS    V1_vgipPos_botIVS;
	vodma_vodma_v1vgip_ihs_RBUS     V1_vgipPos_IHS;
	vodma_vodma_v1vgip_fd_RBUS      V1_vgipPos_topFld;
	vodma_vodma_v1vgip_fd2_RBUS     V1_vgipPos_botFld;
	vodma_vodma_v1vgip_hact_RBUS    V1_vgipPos_HACT;
	vodma_vodma_v1vgip_vact1_RBUS   V1_vgipPos_topVACT;
	vodma_vodma_v1vgip_vact2_RBUS   V1_vgipPos_botVACT;
	vodma_vodma_v1vgip_hbg_RBUS     V1_vgipPos_HBG;
	vodma_vodma_v1vgip_vbg1_RBUS    V1_vgipPos_topVBG;
	vodma_vodma_v1vgip_vbg2_RBUS    V1_vgipPos_botVBG;
	vodma_vodma_v1vgip_bg_clr_RBUS  V1_vgipPos_BGCLR;
	vodma_vodma_v1vgip_intpos_RBUS  V1_vgipPos_intrpt;

	unsigned int HTotal, VTotal, HActStart, HActEnd, VActStart, VActEnd;

	HTotal		= tmode->HTotal;
	VTotal		= tmode->VTotal;
	HActStart	= tmode->HStartPos;
	HActEnd		= tmode->HStartPos + tmode->HWidth;
	VActStart	= tmode->VStartPos;
	VActEnd		= tmode->VStartPos + tmode->VHeight;

	V1_syncGen.vthr_rst1 = 0;
	V1_syncGen.v_thr = 0xfff;
	V1_syncGen.h_thr = HTotal;

	V1_syncGen_mode.vgip_en = 1;
	V1_syncGen_mode.interlace = !tmode->isProg;
	V1_syncGen_mode.top_fld_indc = 0;
	V1_syncGen_mode.v_thr = VTotal;

	V1_vgipPos_topIVS.v_end = IVS_START + IVS_WIDTH;
	V1_vgipPos_topIVS.v_st = IVS_START;

	V1_vgipPos_botIVS.v_end = IVS_START + IVS_WIDTH;
	V1_vgipPos_botIVS.v_st = IVS_START;

	V1_vgipPos_IHS.h_st = 0;

	V1_vgipPos_topFld.v_end = 0xfff;
	V1_vgipPos_topFld.v_st = 0xfff;

	V1_vgipPos_botFld.v_end = 0xfff;
	V1_vgipPos_botFld.v_st = IVS_START;

	V1_vgipPos_HACT.h_end = HActEnd;
	V1_vgipPos_HACT.h_st = HActStart;

	V1_vgipPos_topVACT.v_end = VActEnd;
	V1_vgipPos_topVACT.v_st = VActStart;

	V1_vgipPos_botVACT.v_end = V1_vgipPos_topVACT.v_end;
	V1_vgipPos_botVACT.v_st = V1_vgipPos_topVACT.v_st;

	V1_vgipPos_HBG.h_end = HActEnd;
	V1_vgipPos_HBG.h_st = HActStart;

	V1_vgipPos_topVBG.v_end = VActEnd;
	V1_vgipPos_topVBG.v_st = VActStart;

	V1_vgipPos_botVBG.v_end = VActEnd;
	V1_vgipPos_botVBG.v_st = VActStart;

	V1_vgipPos_intrpt.v2 = VActEnd;
	V1_vgipPos_intrpt.v1 = VActEnd;

	rtd_outl(VODMA_VODMA_V1SGEN_reg, V1_syncGen.regValue);
	rtd_outl(VODMA_VODMA_V1INT_reg, V1_syncGen_mode.regValue);
	rtd_outl(VODMA_VODMA_V1VGIP_IVS1_reg, V1_vgipPos_topIVS.regValue);
	rtd_outl(VODMA_VODMA_V1VGIP_IVS2_reg, V1_vgipPos_botIVS.regValue);
	rtd_outl(VODMA_VODMA_V1VGIP_IHS_reg, V1_vgipPos_IHS.regValue);
	rtd_outl(VODMA_VODMA_V1VGIP_FD_reg, V1_vgipPos_topFld.regValue);
	rtd_outl(VODMA_VODMA_V1VGIP_FD2_reg, V1_vgipPos_botFld.regValue);
	rtd_outl(VODMA_VODMA_V1VGIP_HACT_reg, V1_vgipPos_HACT.regValue);
	rtd_outl(VODMA_VODMA_V1VGIP_VACT1_reg, V1_vgipPos_topVACT.regValue);
	rtd_outl(VODMA_VODMA_V1VGIP_VACT2_reg, V1_vgipPos_botVACT.regValue);
	rtd_outl(VODMA_VODMA_V1VGIP_HBG_reg, V1_vgipPos_HBG.regValue);
	rtd_outl(VODMA_VODMA_V1VGIP_VBG1_reg, V1_vgipPos_topVBG.regValue);
	rtd_outl(VODMA_VODMA_V1VGIP_VBG2_reg, V1_vgipPos_botVBG.regValue);
	rtd_outl(VODMA_VODMA_V1VGIP_INTPOS_reg, V1_vgipPos_intrpt.regValue);

	return 0;
}

int vodma_set_vsyncgen(unsigned int ch, VO_TIMING *tmode)
{
	VO_DATA *vo = &vodma_data[0];
	vodma_vodma_reg_db_ctrl_RBUS    vodma_reg_db_ctrl;
	vodma_vodma_clkgen_RBUS         clkgen;
	vodma_vodma_pvs_free_RBUS       pvs_free;
	vodma_vodma_pvs_ctrl_RBUS       pvs_ctrl;
	vodma_vodma_pvs0_gen_RBUS       pvs0;
	vodma_vodma_pvs_width_ctrl_RBUS pvs_width_ctrl;

	unsigned int vodmapll, vodmapll0, freerun_clk;
	unsigned int nMCode, nNCode, nOCode, regValue, busclk = 0;
	int div_n = 0;
	int ratio_n_off = 0;

	vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
	vodma_reg_db_ctrl.vodmavsg_db_rdy = 0;
	rtd_outl(VODMA_VODMA_REG_DB_CTRL_reg, vodma_reg_db_ctrl.regValue);

	/* vodma clk gen */
	clkgen.vodma_enclk = 1;
	clkgen.vodma_clk_sel = 0;
	clkgen.vodma_clk_div2_en = !tmode->isProg;
	clkgen.vodma_clk_div_n = 0;
	clkgen.vodma_clk_ratio_n_off = 0;

	switch (clkgen.vodma_clk_sel) {
	case 0:
	default:
		regValue = rtd_inl(PLL_REG_SYS_PLL_VODMA1_reg);
		nMCode = ((regValue & 0x000ff000)>>12);
		nNCode = ((regValue & 0x00300000)>>20);
		nOCode = ((regValue & 0x00000180)>>7);

		busclk = 27000000*(nMCode+2)/(nNCode+1)/(nOCode+1);

		pr_info("PLL_VODMA m: %d, n: %d, o: %d, clk: %d\n", nMCode, nNCode, nOCode, busclk);

		vodmapll = busclk;

		break;
	}
	vodmapll0 = vodmapll;

	if ((vodmapll/2) > (tmode->SampleRate*10000)) {
		div_n = (vodmapll/(tmode->SampleRate*10000))-1;
		vodmapll = vodmapll / (div_n + 1);
		clkgen.vodma_clk_div_n = div_n;

		pr_info("div_n: %d, clk: %d\n", clkgen.vodma_clk_div_n, vodmapll);
	}

	if ((vodmapll/32*31) > (tmode->SampleRate*10000)) {
		ratio_n_off = 32 - (tmode->SampleRate*32/(vodmapll/10000)) - 1;
		vodmapll = (vodmapll/32)*(32 - ratio_n_off);
		clkgen.vodma_clk_ratio_n_off = ratio_n_off;

		pr_info("ratio_n_off: %d, clk: %d\n", clkgen.vodma_clk_ratio_n_off, vodmapll);
	}

	if (clkgen.vodma_clk_div2_en) {
		vodmapll = vodmapll / 2;

		pr_info("div2: %d, clk: %d\n", clkgen.vodma_clk_div2_en, vodmapll);
	}

	vo->videoPlane[ch].vsyncgen_pixel_freq = vodmapll;

	clkgen.gating_src_sel = 0;
	clkgen.en_fifo_full_gate = 0;
	clkgen.en_fifo_empty_gate = 0;

	/* pvs freerun */
	pvs_ctrl.pvs0_free_clk_sel = 0;
	pvs_free.pvs0_free_en = 1;		/* 0: disable(clk from vodma), 1:enable(clk from PCK_CLK) */
	pvs_free.pvs0_free_vs_reset_en = 0;
	pvs_free.pvs0_free_period_update = 1;
	switch (pvs_ctrl.pvs0_free_clk_sel) {
	case 1:
		freerun_clk = vodmapll0;
		break;
	case 0:
	default:
		freerun_clk = 27000000;
		break;
	}
	pvs_free.pvs0_free_period = (freerun_clk / ((int)tmode->FrameRate)) * 1000;  /* vfreq unit 0.001Hz */

	pvs_width_ctrl.pvs0_vs_width = pvs_free.pvs0_free_period / tmode->VTotal;

	pvs_ctrl.pvs0_free_l_flag_en = 0;
	pvs_ctrl.pvs0_free_vs_inv_en = 0;
	pvs_ctrl.pvs0_free_vs_sel = 0;
	pvs_ctrl.mask_one_vs = 0;

	/* pvs0 gen */
	pvs0.en_pvgen = 1;
	pvs0.en_pfgen = 1;
	pvs0.pfgen_inv = 0;
	pvs0.iv_inv_en = 0;
	pvs0.iv_src_sel = 0;
	pvs0.iv2pv_dly = 2;

	rtd_outl(VODMA_VODMA_CLKGEN_reg, clkgen.regValue);
	rtd_outl(VODMA_VODMA_PVS_Free_reg, pvs_free.regValue);
	rtd_outl(VODMA_VODMA_PVS_WIDTH_CTRL_reg, pvs_width_ctrl.regValue);
	rtd_outl(VODMA_VODMA_PVS_CTRL_reg, pvs_ctrl.regValue);
	rtd_outl(VODMA_VODMA_PVS0_Gen_reg, pvs0.regValue);

	vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
	vodma_reg_db_ctrl.vodmavsg_db_rdy = 1;
	rtd_outl(VODMA_VODMA_REG_DB_CTRL_reg, vodma_reg_db_ctrl.regValue);

	pr_info("vodma clkgen = %x/%x\n", clkgen.regValue, rtd_inl(VODMA_VODMA_CLKGEN_reg));
	pr_info("PVS_FREE = %x/%x\n", pvs_free.regValue, rtd_inl(VODMA_VODMA_PVS_Free_reg));
	pr_info("PVS0_GEN = %x/%x\n", pvs0.regValue, rtd_inl(VODMA_VODMA_PVS0_Gen_reg));

	return 0;
}

int vodma_set_sensio(void)
{
	sensio_sensio_ctrl_3_RBUS sensio_ctrl_3;
	sensio_sensio_ctrl_0_RBUS sensio_ctrl_0;

	sensio_ctrl_3.regValue = rtd_inl(SENSIO_Sensio_ctrl_3_reg);
	sensio_ctrl_3.sensio_double_apply = 0;
	sensio_ctrl_3.sensio_double_en = 1;
	rtd_outl(SENSIO_Sensio_ctrl_3_reg, sensio_ctrl_3.regValue);

	sensio_ctrl_0.regValue = rtd_inl(SENSIO_Sensio_ctrl_0_reg);
	sensio_ctrl_0.re_decom_en = 0;
	//sensio_ctrl_0.sensio_en = 0; //no Reserved at mac5p
	rtd_outl(SENSIO_Sensio_ctrl_0_reg, sensio_ctrl_0.regValue);

	sensio_ctrl_3.sensio_double_apply = 1;
	rtd_outl(SENSIO_Sensio_ctrl_3_reg, sensio_ctrl_3.regValue);

	return 0;
}

VODMA_MODE Mode_Decision(unsigned int width, unsigned int height, bool isProg)
{
	if (height > 0 && height <= 484) { /* NTSC */
		if (width > 1920)
			goto resolution_4k2k;
		else if (width > 1280)
			goto resolution_1080;
		else if (width > 720)
			goto resolution_720p;

		return (!isProg) ? VODMA_858x525_720x480_60I : VODMA_858x525_720x480_60P;
	} else if (height > 484 && height <= 576) { /* PAL */
		if (width > 1920)
			goto resolution_4k2k;
		else if (width > 1280)
			goto resolution_1080;
		else if (width > 720)
			goto resolution_720p;

		return (!isProg) ? VODMA_864x625_720x576_50I : VODMA_864x625_720x576_50P;
	} else if (height > 576 && height <= 720) { /* 720P60 */
		if (width > 1920)
			goto resolution_4k2k;
		else if (width > 1280)
			goto resolution_1080;

resolution_720p:
		return VODMA_1650x750_1280x720_60P;
	} else if (height > 720 && height <= 1088) { /* 1080I60 */
		if (width > 1920)
			goto resolution_4k2k;
resolution_1080:
		/* decide mode is 1080i50/1080i60/1080p50/1080p60 by mode and frame_rate variable */
		return (!isProg) ? VODMA_2200x1125_1920x1080_60I : VODMA_2200x1125_1920x1080_60P;
	} else if (height > 1088) {
resolution_4k2k:
		return (!isProg) ? VODMA_4120x2192_3840x2160_30I : VODMA_4120x2192_3840x2160_30P;
	} else {
		pr_err("no suitable timing W(%d) H(%d)\n", width, height);
	}
	return VODMA_DEFAULT_MODE;
}

int vomda_set_voinfo(unsigned int ch, VO_TIMING *timemode, unsigned char source)
{
	VO_DATA *vo = &vodma_data[0];
	SLR_VOINFO VOInfo;
	unsigned char isRGB = 0;

	pr_debug("[vo] vomda_set_voinfo\n");

	memset(&VOInfo, 0, sizeof(SLR_VOINFO));

	isRGB = ((vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_ARGB) ||
		 (vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_ABGR) ||
		 (vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_BGR) ||
		 (vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_RGB));

	VOInfo.plane = VO_VIDEO_PLANE_V1;
	VOInfo.port = ch;
	VOInfo.mode = Mode_Decision(vo->image[ch].rect.w, vo->image[ch].rect.h, timemode->isProg);
	VOInfo.h_total = timemode->HTotal;
	VOInfo.v_total = (timemode->isProg) ? timemode->VTotal : timemode->VTotal/2;
	VOInfo.h_start = timemode->HStartPos;
	VOInfo.v_start = timemode->VStartPos - 2 - 1; /* IVS_START = 2 */
	VOInfo.h_width = timemode->HWidth;
	VOInfo.v_length = timemode->VHeight;
	VOInfo.h_freq = vo->videoPlane[ch].vsyncgen_pixel_freq / timemode->HTotal / 100;
	VOInfo.v_freq = timemode->FrameRate/100;
	VOInfo.pixel_clk = vo->videoPlane[ch].vsyncgen_pixel_freq;
	VOInfo.progressive = timemode->isProg;
	VOInfo.chroma_fmt = vo->videoPlane[ch].Ddomain_Chroma_fmt;
	VOInfo.i_ratio = (vo->image[ch].rect.w && ((vo->image[ch].rect.h*100/vo->image[ch].rect.w) > 65)) ? 1 : 0; /* 0. 16:9, 1. 4:3 //480*100/720=66.67 */
	VOInfo.source = (isRGB) ? 3 : 0; /* 3 for rgb, or just set 0 */
	VOInfo.isJPEG = source;
	VOInfo.vdec_source = VOInfo.isJPEG;
	VOInfo.colorspace = (isRGB);
	VOInfo.mode_3d = 0;
	VOInfo.force2d = 0;
	VOInfo.afd = 8;
	VOInfo.pixelAR_hor = 1;
	VOInfo.pixelAR_ver = 1;
	VOInfo.launcher = 0;
	VOInfo.src_h_wid = vo->image[ch].rect.w;
	VOInfo.src_v_len = vo->image[ch].rect.h;

	pr_info("\nSet Voinfo:\n");
	pr_info("plane=%d\n", VOInfo.plane);
	pr_info("port=%d\n", VOInfo.port);
	pr_info("mode=%d\n", VOInfo.mode);
	pr_info("h_start=%d\n", VOInfo.h_start);
	pr_info("v_start=%d\n", VOInfo.v_start);
	pr_info("h_width=%d\n", VOInfo.h_width);
	pr_info("v_length=%d\n", VOInfo.v_length);
	pr_info("h_total=%d\n", VOInfo.h_total);
	pr_info("v_total=%d\n", VOInfo.v_total);
	pr_info("chroma_fmt=%d\n", VOInfo.chroma_fmt);
	pr_info("progressive=%d\n", VOInfo.progressive);
	pr_info("h_freq=%d\n", VOInfo.h_freq);
	pr_info("v_freq=%d\n", VOInfo.v_freq);
	pr_info("pixel_clk=%d\n", VOInfo.pixel_clk);
	pr_info("i_ratio=%d\n", VOInfo.i_ratio);
	pr_info("source=%d\n", VOInfo.source);
	pr_info("isJPEG=%d\n", VOInfo.isJPEG);
	pr_info("mode_3d=%d\n", VOInfo.mode_3d);
	pr_info("force2d=%d\n", VOInfo.force2d);
	pr_info("afd=%d\n", VOInfo.afd);
	pr_info("HPAR=%d\n", VOInfo.pixelAR_hor);
	pr_info("VPAR=%d\n", VOInfo.pixelAR_ver);
	pr_info("src_h_wid=%d\n", VOInfo.src_h_wid);
	pr_info("src_v_len=%d\n", VOInfo.src_v_len);
	pr_info("rotate=%d\n", VOInfo.screenRotation);
	pr_info("launcher=%d\n", VOInfo.launcher);

	set_zoom_smoothtoggle_vo_hwid(VOInfo.src_h_wid);
	set_zoom_smoothtoggle_vo_vlen(VOInfo.src_v_len);
	if ((get_vo_nosignal_flag(ch) == 0) && (memcmp(&vo->videoPlane[ch].VOInfo, &VOInfo, sizeof(SLR_VOINFO) - (sizeof(SLR_AFD_TYPE) + (sizeof(unsigned int)*4))) == 0)) { /* don't compare voinfo AFD, PixelAR and launcher */
		pr_debug("[vo] enter the same timing\n");
		return S_FAIL;
	}

	memcpy(&vo->videoPlane[ch].VOInfo, &VOInfo, sizeof(SLR_VOINFO));
	memcpy(Scaler_VOInfoPointer(ch), &VOInfo, sizeof(SLR_VOINFO));
	Scaler_DispSetInputInfoByDisp(ch, SLR_INPUT_VO_SOURCE_TYPE, VOInfo.isJPEG);
	set_vo_nosignal_flag(ch, 0);

	return S_OK;
}

struct semaphore *get_vo_infosemaphore(void)
{
	return &VO_InfoSemaphore;
}

unsigned char get_voinfo_flag()
{
	return voinfo_flag;
}

void set_voinfo_flag(unsigned char flag)
{
 	voinfo_flag = flag ;
}

unsigned char get_vo_change_flag(unsigned char ch)
{
	if (ch >= 2) {
		pr_err("[vo] %s error: ch %d doesn't exist\n", __func__, ch);
		ch = 0;
	}
	return vo_info_change_flag[ch];
}

void set_vo_change_flag(unsigned char ch, unsigned char flag)
{
	if (ch >= 2) {
		pr_err("[vo] %s error: ch %d doesn't exist\n", __func__, ch);
		ch = 0;
	}
	vo_info_change_flag[ch] = flag;
}

StructDisplayInfo *Get_VO_Dispinfo(unsigned char ch)
{
	if (ch >= 2) {
		pr_err("[vo] %s error: ch %d doesn't exist\n", __func__, ch);
		ch = 0;
	}
	return &VO_dispinfo[ch];
}

unsigned char get_daptive_stream_vo_update_flag(unsigned char ch)
{
	/* //This is for adaptive stream wait vo update */
	if (ch >= 2) {
		pr_err("[vo] %s error: ch %d doesn't exist\n", __func__, ch);
		ch = 0;
	}
	return adaptive_stream_vo_update_flag[ch];
}

void set_daptive_stream_vo_update_flag(unsigned char ch, unsigned char flag)
{
	/* //This is for adaptive stream wait vo update */
	if (ch >= 2) {
		pr_err("[vo] %s error: ch %d doesn't exist\n", __func__, ch);
		ch = 0;
	}
	adaptive_stream_vo_update_flag[ch] = flag;
}

void Config_VO_Dispinfo(SLR_VOINFO *pVOInfo)
{
	unsigned char ch = pVOInfo->port;
	unsigned char ucMode = 0;
	unsigned char display = VO_get_disp_from_port(ch);

	if (ch >= 2) {
		pr_err("[vo] %s error: ch %d doesn't exist\n", __func__, ch);
		ch = 0;
	}

	/* down(&VO_InfoSemaphore); */
	if (get_vo_run_smooth_toggle_enable(display)||vo_same_timing) {
		vo_same_timing = 0;
	} else {
		vo_info_change_flag[ch] = TRUE;
		pr_debug("\r\n####Config_VO_Dispinfo set vo_info_change_flag TRUE####\r\n");
	}

	memset(&VO_dispinfo[ch], 0, sizeof(StructDisplayInfo));

	/* mode */
	switch (pVOInfo->mode) {
	case VODMA_DEFAULT_MODE:
	case VODMA_858x525_720x480_60I:
		ucMode = _MODE_480I;
		break;
	case VODMA_858x525_720x480_60P:
		ucMode = _MODE_480P;
		break;
	case VODMA_864x625_720x576_50I:
		ucMode = _MODE_576I;
		break;
	case VODMA_864x625_720x576_50P:
		ucMode = _MODE_576P;
		break;
	case VODMA_1980x750_1280x720_50P:
		ucMode = _MODE_720P50;
		break;
	case VODMA_1650x750_1280x720_60P:
		ucMode = _MODE_720P60;
		break;
	case VODMA_2640x1125_1920x1080_50I:
		ucMode = _MODE_1080I25;
		break;
	case VODMA_2200x1125_1920x1080_60I:
		ucMode = _MODE_1080I30;
		break;
	case VODMA_2640x1125_1920x1080_50P:
		ucMode = _MODE_1080P50;
		break;
	case VODMA_2200x1125_1920x1080_60P:
		ucMode = _MODE_1080P60;
		break;
	case VODMA_4120x2192_3840x2160_30I:
		ucMode = _MODE_4k2kI30;
		break;
	case VODMA_4120x2192_3840x2160_30P:
		ucMode = _MODE_4k2kP30;
		break;
	default:
		pr_err("unknown display mode!!!\n");
		break;
	}

	VO_dispinfo[ch].ucMode_Curr = ucMode;
	VO_dispinfo[ch].IPH_ACT_STA_PRE = pVOInfo->h_start;
	VO_dispinfo[ch].IPV_ACT_STA_PRE = pVOInfo->v_start;
	VO_dispinfo[ch].IPH_ACT_WID_PRE = pVOInfo->h_width;
	VO_dispinfo[ch].IPV_ACT_LEN_PRE = pVOInfo->v_length;
	VO_dispinfo[ch].IHTotal = pVOInfo->h_total;
	VO_dispinfo[ch].IVTotal = pVOInfo->v_total;
	VO_dispinfo[ch].disp_status |= (((pVOInfo->chroma_fmt == FMT_444) ? 0 : 1) << 1);
	VO_dispinfo[ch].disp_status |= ((pVOInfo->progressive ? 0 : 1) << 8);
	VO_dispinfo[ch].IHFreq = pVOInfo->h_freq;
	VO_dispinfo[ch].IVFreq = pVOInfo->v_freq;
	VO_dispinfo[ch].IAspectRatio = pVOInfo->i_ratio;
	VO_dispinfo[ch].afd = pVOInfo->afd;
	VO_dispinfo[ch].color_space = (pVOInfo->chroma_fmt == FMT_444) ? ((pVOInfo->source == 3 || pVOInfo->colorspace) ? VODMA_COLOR_RGB : VODMA_COLOR_YUV444) : VODMA_COLOR_YUV422;
	VO_dispinfo[ch].color_depth = 0;
	VO_dispinfo[ch].color_imetry = 0;
	VO_dispinfo[ch].INPUT_ADC_CLOCK  = 0;
	VO_dispinfo[ch].Hsync = 0;
	VO_dispinfo[ch].Vsync = 0;
	VO_dispinfo[ch].Polarity = 0;
	VO_dispinfo[ch].IHCount_PRE = 0;
	VO_dispinfo[ch].IVCount_PRE = 0;
	VO_dispinfo[ch].IHSyncPulseCount = 0;

	pr_info("\nSet VO_Dispinfo[%d]:\n", ch);
	pr_info("ucMode_Curr=%d\n", VO_dispinfo[ch].ucMode_Curr);
	pr_info("IPH_ACT_STA_PRE=%d\n", VO_dispinfo[ch].IPH_ACT_STA_PRE);
	pr_info("IPV_ACT_STA_PRE=%d\n", VO_dispinfo[ch].IPV_ACT_STA_PRE);
	pr_info("IPH_ACT_WID_PRE=%d\n", VO_dispinfo[ch].IPH_ACT_WID_PRE);
	pr_info("IPV_ACT_LEN_PRE=%d\n", VO_dispinfo[ch].IPV_ACT_LEN_PRE);
	pr_info("IHTotal=%d\n", VO_dispinfo[ch].IHTotal);
	pr_info("IVTotal=%d\n", VO_dispinfo[ch].IVTotal);
	pr_info("disp_status.422=%d\n", (VO_dispinfo[ch].disp_status & 0x2)>>1);
	pr_info("disp_status.Interlace=%d\n", (VO_dispinfo[ch].disp_status & 0x100)>>8);
	pr_info("IHFreq=%d\n", VO_dispinfo[ch].IHFreq);
	pr_info("IVFreq=%d\n", VO_dispinfo[ch].IVFreq);
	pr_info("IAspectRatio=%d\n", VO_dispinfo[ch].IAspectRatio);
	pr_info("afd=%d\n", VO_dispinfo[ch].afd);
	pr_info("color_space=%d\n", VO_dispinfo[ch].color_space);
	pr_info("color_depth=%d\n", VO_dispinfo[ch].color_depth);
	pr_info("color_imetry=%d\n", VO_dispinfo[ch].color_imetry);
	pr_info("INPUT_ADC_CLOCK=%d\n", VO_dispinfo[ch].INPUT_ADC_CLOCK);
	pr_info("Hsync=%d\n", VO_dispinfo[ch].Hsync);
	pr_info("Vsync=%d\n", VO_dispinfo[ch].Vsync);
	pr_info("Polarity=%d\n", VO_dispinfo[ch].Polarity);
	pr_info("IHCount_PRE=%d\n", VO_dispinfo[ch].IHCount_PRE);
	pr_info("IVCount_PRE=%d\n", VO_dispinfo[ch].IVCount_PRE);
	pr_info("IHSyncPulseCount=%d\n", VO_dispinfo[ch].IHSyncPulseCount);

	/* up(&VO_InfoSemaphore); */
}

/*extern UINT32 PQModeInfo_flag[5];
extern void dynamic_change_hdr_setting(unsigned char hdr_enable, I3DDMA_COLOR_SPACE_T color_format);*/
extern void set_vdec_securestatus(unsigned char value);
unsigned char vo_framerate_change[MAX_DISP_CHANNEL_NUM];
unsigned char get_vo_frameratechange_enable(unsigned char display)
{
	if (display >= MAX_DISP_CHANNEL_NUM)
		return 0;
	return vo_framerate_change[display];
}

void set_vo_frameratechange_enable(unsigned char enable, unsigned char display)
{
	if (display >= MAX_DISP_CHANNEL_NUM)
		return;
	vo_framerate_change[display] = enable;
}
unsigned int rpcVoReady(unsigned long para1, unsigned long para2)
{
	VO_DATA *vo = &vodma_data[0];
	SLR_VOINFO VOInfo;
	SLR_VOINFO *pVOInfo = NULL;
	unsigned char ch = 0;

	unsigned int i = 0, ulVOInfoItemCount = 0;
	unsigned int *pulTemp;

	unsigned char vo_sm_info;
	unsigned char display;

	pr_debug("[vo] rpcVoReady\n");

	down(&VO_InfoSemaphore); /* Lock VO Semaphore */

	pVOInfo = &VOInfo;

	memcpy(pVOInfo, (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GETVOINFO), sizeof(SLR_VOINFO));

	/* change endian */
	ulVOInfoItemCount = sizeof(SLR_VOINFO) /  sizeof(UINT32);
	pulTemp = (unsigned int *)pVOInfo;
	for (i = 0; i < ulVOInfoItemCount; i++)
		pulTemp[i] = Scaler_ChangeUINT32Endian(pulTemp[i]);

	pr_debug("\nreceive Voinfo:\n");
	pr_debug("plane=%d\n", (int)pVOInfo->plane);
	pr_debug("port=%d\n", (int)pVOInfo->port);
	pr_debug("mode=%d\n", (int)pVOInfo->mode);
	pr_debug("h_start=%d\n", (int)pVOInfo->h_start);
	pr_debug("v_start=%d\n", (int)pVOInfo->v_start);
	pr_debug("h_width=%d\n", (int)pVOInfo->h_width);
	pr_debug("v_length=%d\n", (int)pVOInfo->v_length);
	pr_debug("h_total=%d\n", (int)pVOInfo->h_total);
	pr_debug("v_total=%d\n", (int)pVOInfo->v_total);
	pr_debug("chroma_fmt=%d\n", (int)pVOInfo->chroma_fmt);
	pr_debug("progressive=%d\n", (int)pVOInfo->progressive);
	pr_debug("h_freq=%d\n", (int)pVOInfo->h_freq);
	pr_debug("v_freq=%d\n", (int)pVOInfo->v_freq);
	pr_debug("pixel_clk=%d\n", (int)pVOInfo->pixel_clk);
	pr_debug("i_ratio=%d\n", (int)pVOInfo->i_ratio);
	pr_debug("source=%d\n", (int)pVOInfo->source);
	pr_debug("isJPEG=%d\n", (int)pVOInfo->isJPEG);
	pr_debug("vdec=%d\n", (int)pVOInfo->vdec_source);
	pr_debug("color=%d\n", (int)pVOInfo->colorspace);
	pr_debug("mode_3d=%d\n", (int)pVOInfo->mode_3d);
	pr_debug("force2d=%d\n", (int)pVOInfo->force2d);
	pr_debug("afd=%d\n", (int)pVOInfo->afd);
	pr_debug("HPAR=%d\n", (int)pVOInfo->pixelAR_hor);
	pr_debug("VPAR=%d\n", (int)pVOInfo->pixelAR_ver);
	pr_debug("src_h_wid=%d\n", (int)pVOInfo->src_h_wid);
	pr_debug("src_v_len=%d\n", (int)pVOInfo->src_v_len);
	pr_debug("xvYCC=%d\n", (int)pVOInfo->xvYCC);
	pr_debug("trans_char=%d\n", (int)pVOInfo->transfer_characteristics);
	pr_debug("mt_coeff=%d\n", (int)pVOInfo->matrix_coefficiets);
	pr_debug("full_range=%d\n", (int)pVOInfo->video_full_range_flag);
	pr_debug("c_prim=%d\n", (int)pVOInfo->colour_primaries);
	pr_debug("MaxCLL=%d\n", (int)pVOInfo->MaxCLL);
	pr_debug("MaxFALL=%d\n", (int)pVOInfo->MaxFALL);
	pr_debug("security=%d\n", (int)pVOInfo->security);
	pr_debug("isVP9=%d\n", (int)pVOInfo->isVP9);
	pr_debug("rotate=%d\n", (int)pVOInfo->screenRotation);

	pr_debug("launcher=%d\n", (int)pVOInfo->launcher);

	ch = pVOInfo->port;

	if ((ch == 0) || (ch == 1)) {
		if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC) && (pVOInfo->vdec_source == 0)){
			is_DTV_flag_set(_ENABLE);
			pr_notice("this is DTV source \n");
		}

		if ((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC) && (Get_DisplayMode_Port(SLR_MAIN_DISPLAY) == ch))
			adaptive_stream_vo_update_flag[ch] = TRUE;
		else if ((Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_VDEC) && (Get_DisplayMode_Port(SLR_SUB_DISPLAY) == ch))
			adaptive_stream_vo_update_flag[ch] = TRUE;
	}

	if (!((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC && Get_DisplayMode_Port(SLR_MAIN_DISPLAY) == ch) ||
		(Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_VDEC && Get_DisplayMode_Port(SLR_SUB_DISPLAY) == ch) ||
#ifdef CONFIG_I2RND_ENABLE
		((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_SUB_VO_RPC)) ||
#endif
#ifdef CONFIG_FORCE_RUN_I3DDMA
		(
		#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED ||
		#endif
		get_force_i3ddma_enable(SLR_MAIN_DISPLAY) == true))
#else
	     (
	     #ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	     Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED &&
	     #endif
		 Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI))
#endif
		)
	{
		pr_err("[vo] error: not correct ch %d, m:%d/%d,s:%d/%d\n", ch, Get_DisplayMode_Src(SLR_MAIN_DISPLAY), Get_DisplayMode_Port(SLR_MAIN_DISPLAY), Get_DisplayMode_Src(SLR_SUB_DISPLAY), Get_DisplayMode_Port(SLR_SUB_DISPLAY));
		up(&VO_InfoSemaphore); /* Release VO Semaphore */
		return HAL_VO_STATE_OK;
	}

	if (ch >= 2) {
		pr_err("[vo] %s error: ch %d doesn't exist\n", __func__, ch);
		ch = 0;
	}

	Scaler_DispSetInputInfoByDisp(ch, SLR_INPUT_VO_SOURCE_TYPE, ((pVOInfo->source == 3) ? SOURCE_DIRECTVO : pVOInfo->isJPEG));

	set_vdec_securestatus(pVOInfo->security);
	/* //set_vo_source_type(pVOInfo->source); */
	set_zoom_smoothtoggle_vo_hwid(pVOInfo->src_h_wid);
	set_zoom_smoothtoggle_vo_vlen(pVOInfo->src_v_len);
	set_vo_3d_mode(pVOInfo->mode_3d);
#if 0//def CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
		//if ((pVOInfo->screenRotation == DIRECT_VO_FRAME_ORIENTATION_ROTATE_0) && (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC))
		//	pVOInfo->screenRotation =DIRECT_VO_FRAME_ORIENTATION_ROTATE_180;
		if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC) && ((DIRECT_VO_FRAME_ORIENTATION_ROTATE_90 == pVOInfo->screenRotation) ||(DIRECT_VO_FRAME_ORIENTATION_ROTATE_180 == pVOInfo->screenRotation) ||(DIRECT_VO_FRAME_ORIENTATION_ROTATE_270 == pVOInfo->screenRotation)) )
		{
			//Set_rotate_function(TRUE);
			set_rotate_mode(pVOInfo->screenRotation);
			pr_emerg("get_rotate_mode =%d\n",get_rotate_mode());
		}
		else
		{
			set_rotate_mode(0);
			//Set_rotate_function(FALSE);
		}
#endif
	/* //get VP9 flag */
	set_vo_vp9_flag(ch, pVOInfo->isVP9);

	/* para1 bit4:display; bit3:smooth toggle fail flag;bit2-1:smooth toggle state decide open smooth toggle or not;bit0:curr timing go smooth toggle or not */
	/* para1  bit5:imd_framesync */
	display = (para1>>4)&0x01; pr_notice("rpcVoReady:display:%d\n", display);
	VO_set_disp_to_port(ch, display);

	vo_sm_info = (para1>>1)&0x03; pr_debug("set_vo_open_smooth_toggle_enable:%d\n", vo_sm_info);
	set_vo_open_smooth_toggle_enable(vo_sm_info, display);
	vo_sm_info = para1&0x01; pr_debug("set_vo_run_smooth_toggle_enable:%d\n", vo_sm_info);
	set_vo_run_smooth_toggle_enable(vo_sm_info, display);
	vo_sm_info = (para1>>7)&0x01; pr_debug("frameratechange:%d\n", vo_sm_info);
   	set_vo_frameratechange_enable(vo_sm_info,display);
	vo_sm_info = (para1>>3)&0x01; pr_debug("vo_sm_info:%d\n", vo_sm_info);
    vo_same_timing = (para1>>6)&0x01; pr_debug("vo_same_timing:%d\n", vo_same_timing);
   #ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
	if (vbe_disp_get_adaptivestream_fs_mode()) {
		vo_sm_info = (para1>>5)&0x1; pr_notice("rpcVoReady:fs:%d\n", vo_sm_info);
		set_vo_smooth_toggle_fsmode(vo_sm_info, display);
	}
   #endif

	if (!get_vo_run_smooth_toggle_enable(display)){
		if ((Get_DisplayMode_Src(display) == VSC_INPUTSRC_VDEC)||(Get_DisplayMode_Src(display) == VSC_INPUTSRC_JPEG)){
			set_voinfo_flag(1);
			pr_debug("set_voinfo_flag true\n");
		}else{
			set_voinfo_flag(0);
		}
	}else{
			set_voinfo_flag(0);
	}

	if (vo_sm_info) {
		/* smooth toggle fail,need to restart */
	} else {
#ifdef CONFIG_HDR_SDR_SEAMLESS
		/* don't compare voinfo HDR item and launcher for seamless case @Crixus 20170215*/
		if ((memcmp(&vo->videoPlane[ch].VOInfo, pVOInfo, sizeof(SLR_VOINFO) - (sizeof(SLR_AFD_TYPE) + (sizeof(unsigned int)*9))) == 0))/* don't compare voinfo HDR info, AFD, PixelAR and launcher */
#else
		if ((memcmp(&vo->videoPlane[ch].VOInfo, pVOInfo, sizeof(SLR_VOINFO) - (sizeof(SLR_AFD_TYPE) + (sizeof(unsigned int)*4))) == 0))/* don't compare voinfo AFD, PixelAR and launcher */
#endif
		{
			pr_info("\nenter the same timing\n");
			set_vo_nosignal_flag(ch, 0);
			if (!get_vo_run_smooth_toggle_enable(display) && (((para1>>1)&0x03) == SLR_SMOOTH_TOGGLE_INIT) && (get_vo_smoothtoggle_state(display) == SLR_SMOOTH_TOGGLE_ACTIVE)) {
				set_reset_smooth_toggle_state(_ENABLE, display);
				pr_debug("reset smooth toggle state\n");
			}
			if (force_change_vo_flag[ch]) {
			       if(!rtk_hal_vsc_Getdualdecoder_run()){  /*dual decoder case will change vo port*/
				    vo_info_change_flag[ch] = TRUE;
				    pr_emerg("\r\n####force_change_vo_flag. set vo_info_change_flag TRUE####\r\n");
			        }
				force_change_vo_flag[ch] = FALSE;
			}

                        if ((vsc_get_adaptivestream_flag() == 1) &&(get_vo_smoothtoggle_state(display) != SLR_SMOOTH_TOGGLE_ACTIVE)) {
				vo_info_change_flag[ch] = TRUE;
				 pr_emerg("\r\n####adaptive stream non-active status:set vo_info_change_flag TRUE####\r\n");
			}
			up(&VO_InfoSemaphore); /* Release VO Semaphore */

#ifdef CONFIG_I2RND_ENABLE
			/* //I2rnd run Main in scaler task */
			if ((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_SUB_VO_RPC)) {
				vsc_i2rnd_sub_stage = I2RND_STAGE_TRIGGER_RUN_MAIN;
				printk(KERN_EMERG"[I2RND]@@@@@@@@@@@@I2RND_STAGE_TRIGGER_RUN_MAIN\n");
			}
#endif
//#ifdef CONFIG_HDR_SDR_SEAMLESS
			memcpy(&vo->videoPlane[ch].VOInfo, pVOInfo, sizeof(SLR_VOINFO));
			memcpy(Scaler_VOInfoPointer(ch), pVOInfo, sizeof(SLR_VOINFO));	/* scaler driver would use it */
//#endif
			return 0;
		}
	}
	memcpy(&vo->videoPlane[ch].VOInfo, pVOInfo, sizeof(SLR_VOINFO));
	memcpy(Scaler_VOInfoPointer(ch), pVOInfo, sizeof(SLR_VOINFO));	/* scaler driver would use it */
	set_vo_nosignal_flag(ch, 0);
	Config_VO_Dispinfo(&vo->videoPlane[ch].VOInfo);

	/* //update voinfo immediately for adaptive stream */
	if (vsc_get_adaptivestream_flag() == 1) {
		Scaler_SET_VSCDispinfo_WithVFEDispinfo(display, Get_VO_Dispinfo(ch));
	}

	if (force_change_vo_flag[ch])
		force_change_vo_flag[ch] = FALSE;

	up(&VO_InfoSemaphore); /* Release VO Semaphore */
#if 0	/* move into "Scaler_hdr_setting_SEAMLESS()"*/
	//IoReg_Write32(0xb802e4f4, IoReg_Read32(0xb802e4f4) | ((pVOInfo->transfer_characteristics) << 8));
	static UINT8 pre_transfer_characteristics = 0;
	if (pre_transfer_characteristics != pVOInfo->transfer_characteristics)
	{
		//IoReg_Write32(0xb802e4f4, IoReg_Read32(0xb802e4f4) + 1);
		if (pVOInfo->transfer_characteristics == 16)
		{
			//IoReg_Write32(0xb802e4f4, IoReg_Read32(0xb802e4f4) | 0x00010000);
			PQModeInfo_flag[0] = HAL_VPQ_HDR_MODE_HDR10;
			PQModeInfo_flag[1] = HAL_VPQ_COLORIMETRY_BT2020;
			//dynamic_change_hdr_setting(ON, I3DDMA_COLOR_YUV422);
		}
		else if (pVOInfo->transfer_characteristics == 18)
		{
			//IoReg_Write32(0xb802e4f4, IoReg_Read32(0xb802e4f4) | 0x00020000);
			PQModeInfo_flag[0] = HAL_VPQ_HDR_MODE_HLG;
			PQModeInfo_flag[1] = HAL_VPQ_COLORIMETRY_BT2020;
			//dynamic_change_hdr_setting(ON, I3DDMA_COLOR_YUV422);
		}
		else
		{
			//IoReg_Write32(0xb802e4f4, IoReg_Read32(0xb802e4f4) | 0x00040000);
			//dynamic_change_hdr_setting(OFF, I3DDMA_COLOR_YUV422);
			PQModeInfo_flag[0] = HAL_VPQ_HDR_MODE_SDR;
			PQModeInfo_flag[1] = HAL_VPQ_COLORIMETRY_BT709;
		}
		//pr_emerg("[vo] transfer_characteristics changed. set change_vgip_pq\n");
	}

	pre_transfer_characteristics = pVOInfo->transfer_characteristics;
#endif
#ifdef CONFIG_I2RND_ENABLE
	/* //I2rnd run Main in scaler task */
	if ((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_SUB_VO_RPC)) {
		vsc_i2rnd_sub_stage = I2RND_STAGE_TRIGGER_RUN_MAIN;
		printk(KERN_EMERG"[I2RND]@@@@@@@@@@@@I2RND_STAGE_TRIGGER_RUN_MAIN\n");
	}
#endif
	return 0;
}

unsigned int rpcVoNoSignal(unsigned long para1, unsigned long para2)
{
	pr_debug("[vo] rpcVoNoSignal\n");

	set_vo_nosignal_flag((unsigned int)para1, 1);

	return 0;
}

unsigned char get_vo_nosignal_flag(unsigned int ch)
{
	VO_DATA *vo = &vodma_data[0];

	if (ch >= 2) {
		pr_err("[vo] %s error: ch %d doesn't exist\n", __func__, ch);
		ch = 0;
	}

	return vo->nosignal[ch];
}

void set_vo_nosignal_flag(unsigned int ch, unsigned char flag)
{
	VO_DATA *vo = &vodma_data[0];

	if (ch >= 2) {
		pr_err("[vo] %s error: ch %d doesn't exist\n", __func__, ch);
		return;
	}

	vo->nosignal[ch] = flag;

	pr_debug("[vo] set vo(%d) nosignal: %d\n", ch, vo->nosignal[ch]);
}

unsigned int rpcVoAVSync(unsigned long para1, unsigned long para2)
{
	pr_debug("[vo] rpcVoAVSync\n");

	set_vo_avsync_flag((unsigned int)para1, (unsigned char)para2);

	return 0;
}

unsigned char get_vo_avsync_flag(unsigned int ch)
{
	VO_DATA *vo = &vodma_data[0];

	if (ch >= 2) {
		pr_err("[vo] %s error: ch %d doesn't exist\n", __func__, ch);
		ch = 0;
	}

	return vo->avsync[ch];
}

void set_vo_avsync_flag(unsigned int ch, unsigned char flag)
{
	VO_DATA *vo = &vodma_data[0];

	if (ch >= 2) {
		pr_err("[vo] %s error: ch %d doesn't exist\n", __func__, ch);
		return;
	}

	vo->avsync[ch] = flag;

	pr_debug("[vo] set vo(%d) avsync: %d\n", ch, vo->avsync[ch]);
}

unsigned char vo_run_smoothtoggle[MAX_DISP_CHANNEL_NUM];
unsigned char vo_open_smoothtoggle[MAX_DISP_CHANNEL_NUM];
unsigned char vo_smoothtoggle_fsmode[MAX_DISP_CHANNEL_NUM];
VO_3D_MODE_TYPE vo_3d_mode = VO_2D_MODE;
unsigned char vo_imd_disable[MAX_DISP_CHANNEL_NUM];
unsigned char vo_sequential_mode;
unsigned char vo_reset_sm_state[MAX_DISP_CHANNEL_NUM];
unsigned char vo_disp_port[VODMA_DEV_NUM];
unsigned char vo_vp9_flag[VODMA_DEV_NUM];


void set_vo_vp9_flag(unsigned char ch, unsigned char enable)
{
	if (ch >= VODMA_DEV_NUM) {
		pr_err("[vo]unvalid port\n");
		return;
	}
	vo_vp9_flag[ch] = enable;
}

unsigned char get_vo_vp9_flag(unsigned char ch)
{
	if (ch >= VODMA_DEV_NUM) {
		pr_err("[vo]unvalid port\n");
		return 0;
	}
	return vo_vp9_flag[ch];
}

unsigned char get_reset_smooth_toggle_state(unsigned char display)
{
	if (display >= MAX_DISP_CHANNEL_NUM)
		display = 0;
	return vo_reset_sm_state[display];
}

void set_reset_smooth_toggle_state(unsigned char enable, unsigned char display)
{
	if (display >= MAX_DISP_CHANNEL_NUM)
		display = 0;
	vo_reset_sm_state[display] = enable;
}

unsigned char get_vo_imd_disable(unsigned char display)
{
	if (display >= MAX_DISP_CHANNEL_NUM)
		display = 0;
	return vo_imd_disable[display];
}

void set_vo_imd_disable(unsigned char enable, unsigned char display)
{
	if (display >= MAX_DISP_CHANNEL_NUM)
		display = 0;
	vo_imd_disable[display] = enable;
}

unsigned char get_vo_mode_sequential(void)
{
	return vo_sequential_mode;
}

void set_vo_mode_sequential(unsigned char enable)
{
	vo_sequential_mode = enable;
}

unsigned char VO_get_disp_from_port(unsigned char port)
{
	if (port >= 2)
		port = 0;
	return vo_disp_port[port];
}

void VO_set_disp_to_port(unsigned char port, unsigned char display)
{
	if ((port >= 2) || (display >= MAX_DISP_CHANNEL_NUM)) {
		pr_debug("[wrong]port or display error\n");
		return;
	}
	vo_disp_port[port] = display;
}

unsigned char get_vo_run_smooth_toggle_enable(unsigned char display)
{
	if (display >= MAX_DISP_CHANNEL_NUM)
		display = 0;
	return vo_run_smoothtoggle[display];
}

#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
unsigned char get_vo_smooth_toggle_fsmode(unsigned char display)
{
	if (display >= MAX_DISP_CHANNEL_NUM)
		display = 0;

	return vo_smoothtoggle_fsmode[display];
}

void set_vo_smooth_toggle_fsmode(unsigned char fsmode, unsigned char display)
{
	if (display >= MAX_DISP_CHANNEL_NUM)
		display = 0;
	vo_smoothtoggle_fsmode[display] = fsmode;
}
#endif

void set_vo_run_smooth_toggle_enable(unsigned char enable, unsigned char display)
{
	if (display >= MAX_DISP_CHANNEL_NUM)
		display = 0;
	vo_run_smoothtoggle[display] = enable;
	set_vo_imd_disable(enable, display);
}

unsigned char get_vo_open_smooth_toggle_enable(unsigned char display)
{
	if (display >= MAX_DISP_CHANNEL_NUM)
		display = 0;
	return vo_open_smoothtoggle[display];
}

void set_vo_open_smooth_toggle_enable(unsigned char enable, unsigned char display)
{
	if (display >= MAX_DISP_CHANNEL_NUM)
		display = 0;
	if ((enable >= SLR_SMOOTH_TOGGLE_INIT) && (enable < SLR_SMOOTH_TOGGLE_RELEASE))
		vo_open_smoothtoggle[display] = 1;
	else
		vo_open_smoothtoggle[display] = 0;
}



VO_3D_MODE_TYPE get_vo_3d_mode(void)
{
	return vo_3d_mode;
}

void set_vo_3d_mode(VO_3D_MODE_TYPE mode)
{
	vo_3d_mode = mode;
}

void set_force_change_vo_flag(unsigned char ch, unsigned char flag)
{
	if (ch >= 2) {
		pr_err("[vo] %s error: ch %d doesn't exist\n", __func__, ch);
		ch = 0;
	}
	force_change_vo_flag[ch] = flag;
}

unsigned int rpcVoHdrFrameInfo(unsigned long mode, unsigned long para1)
{
	pr_debug("[DolbyVision] UNKNOWN MODE[%d]\n", (unsigned int)mode);

	return 0;
}

unsigned char get_vo_plane_flag(unsigned char display)
{
	VO_DATA *vo = &vodma_data[0];
	unsigned int ch = (Get_DisplayMode_Port(display));

	if (ch >= 2) {
		pr_err("[vo] %s error: ch %d doesn't exist\n", __func__, ch);
		ch = 0;
	}
	return vo->videoPlane[ch].VOInfo.plane;
}

void enable_vodma_empty_gate(unsigned char plane)
{
	if (plane == VO_VIDEO_PLANE_V1) {
		/* //VO decompress mode don't support empty gate */
		if ((rtd_inl(VODMA_DECOMP_CTRL0_reg) & _BIT0) == 0)
			rtd_maskl(VODMA_VODMA_CLKGEN_reg, ~(_BIT3), _BIT3);
	} else if (plane == VO_VIDEO_PLANE_V2) {
		/* //VO decompress mode don't support empty gate */
		if ((rtd_inl(VODMA2_DECOMP2_CTRL0_reg) & _BIT0) == 0)
			rtd_maskl(VODMA2_VODMA2_CLKGEN_reg, ~(_BIT3), _BIT3);
	}
}

#ifdef CONFIG_HDR_SDR_SEAMLESS
spinlock_t* get_vdec_seamless_change_spinlock(void)
{//this is for vdec_seamless_change_flag protection
	return &VDEC_SEAMLESS_CHANGE_SPINLOCK;
}

void set_vdec_seamless_change_flag(unsigned char TorF)
{
	vdec_seamless_change_flag = TorF;
}

unsigned char get_vdec_seamless_change_flag(void)
{
	return vdec_seamless_change_flag;
}
#endif

