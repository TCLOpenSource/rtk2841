#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/kernel.h>   /* DBG_PRINT()    */
#include <linux/slab.h>     /* kmalloc()      */
#include <linux/fs.h>       /* everything...  */
#include <linux/errno.h>    /* error codes    */
#include <linux/types.h>    /* size_t         */
#include <linux/cdev.h>
#include <linux/dma-mapping.h>
#include <linux/uaccess.h>    /* copy_*_user    */
#include <linux/jiffies.h>
#include <linux/interrupt.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/pageremap.h>
#include <linux/random.h>
#include <linux/pageremap.h>
#include <linux/proc_fs.h>
#include <linux/kthread.h>  /* for threads */
#include <linux/time.h>   /* for using jiffies */
#include <asm/barrier.h> /*dsb()*/
#include <asm/cacheflush.h>

/*[WOSQRTK-6662]fix logo dealy time.*/
#include "tvscalercontrol/panel/panelapi.h"

#include <mach/irqs.h>
#include <mach/platform.h>
#include <mach/system.h>

#include <rbus/sb2_reg.h>

#include <rbus/sfg_reg.h>
#include <rbus/ppoverlay_reg.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <rbus/stb_reg.h>
#include <rbus/sys_reg_reg.h> /* rtk interrupt*/

#include <rtk_crt.h>
#include <panelConfigParameter.h>

#include <rbus/gdma_reg.h>
#include <gal/rtk_gdma_driver.h>
#include <gal/rtk_gdma_scale_coef.h>
#include <gal/rtk_osdcomp_driver.h>
#include <tvscalercontrol/panel/panelapi.h>

#include "osd_dump_agent.h"
/*need sema.*/
//static int osd_dump_state = 0;
#define  GDMA_GAMMA 0
#include "rtk_kadp_se.h"

#define DRV_NAME	"gdma"

#include <mach/rtk_log.h>
#define TAG_NAME "GDMA"


#ifdef CONFIG_PM
static int gdma_suspend(struct device *p_dev);
static int gdma_resume(struct device *p_dev);
//add by fox for gfx std
//
#ifdef CONFIG_HIBERNATION
static int gdma_suspend_std(struct device *p_dev);
static int gdma_resume_std(struct device *p_dev);
#endif
#endif

/*will be updated in gdma_init func */
static unsigned long gdma_total_ddr_size = 0x60000000;

int gdma_major = GDMA_MAJOR;
int gdma_minor = 0;
int gdma_nr_devs = GDMA_NR_DEVS;
#ifdef CONFIG_HIBERNATION
extern int in_suspend;
#endif
#ifdef CONFIG_LG_SNAPSHOT_BOOT
extern bool reserve_boot_memory;
#endif

int flag_gdma_resume_std=0;

/* from offline process */
extern volatile unsigned int gActiveOffPlane;
#if defined(CONFIG_CUSTOMER_TV006) && defined(CONFIG_SUPPORT_SCALER)
extern void vbe_disp_early_resume(void);
#endif
//RTK mark for netfix
int enable_osd1osd3mixerorder = 1; 


int gContext = -1;
static struct class *gdma_class;
gdma_dev *gdma_devices;          /* allocated in gdma_init_module */
#if defined(CONFIG_ARM64)
unsigned long gdma_dev_addr = 0;
#else
unsigned int gdma_dev_addr = 0;
#endif
short GDMA_coef_4t8p_ratio_swap_[GDMA_NUM_COEFF_RATIOS][4][4];

#ifdef TRIPLE_BUFFER_SEMAPHORE
int gSEMAPHORE_MAX = 1;
int gSemaphore[GDMA_PLANE_MAXNUM];
#endif

static const char  drv_name[] = DRV_NAME;

#if defined(CONFIG_RTK_KDRV_GAL)
//add by fox for gfx std
extern int GAL_MEM_ADDR_START;
extern int GAL_MEM_SIZE;

unsigned int gal_std_save_dvr_phy = 0;
unsigned int gal_std_save_dvr_ptr = 0;
//add by fox for gfx std
#define GFX_SPECIAL_SIZE 256*256
#define GFX_NUM_MAX 200
#define GFX_CURSOR_SIZE 4*1024*1024
typedef struct {
	unsigned int width;
	unsigned int height;
	unsigned int phyAddr;
	unsigned int virtAddr;
	unsigned int to_phyAddr;
	unsigned int to_virtAddr;
	unsigned int size;
} RtgfxRecord;

extern RtgfxRecord gfx_data[];

extern unsigned int total_size;
extern unsigned int total_index;

/*For free logo flow, add those extern func*/


bool bstoplogo =false;
static int logo_dalay_init_bool_1=0;
static int logo_do_dvr_reclaim=0;
#define INNOLUX_LOGO_TIME_DELAY_VALUE (1*HZ)
#define INNOLUX_LOGO_TIME_DELAY_VALUE_1 (HZ/10*4)
#else
extern phys_addr_t __initdata reserved_dvr_start;
extern phys_addr_t __initdata reserved_dvr_size;
extern phys_addr_t __initdata reserved_last_image_start;
extern phys_addr_t __initdata reserved_last_image_size;
#endif

extern void do_dvr_reclaim(int cmd);

#ifdef CONFIG_PM
static struct platform_device *gdma_devs;

static const struct dev_pm_ops gdma_pm_ops = {
	.suspend    = gdma_suspend,
	.resume     = gdma_resume,
#ifdef CONFIG_HIBERNATION
	.freeze     = gdma_suspend_std,
	.thaw       = gdma_resume_std,
	.poweroff   = gdma_suspend_std,
	.restore    = gdma_resume_std,
#endif
};

static struct platform_driver gdma_driver = {
	.driver = {
		.name         = (char *)drv_name,
		.bus          = &platform_bus_type,
#ifdef CONFIG_PM
		.pm           = &gdma_pm_ops,
#endif
	},
};
#endif /* CONFIG_PM */

#if defined(CONFIG_REALTEK_PCBMGR)
extern platform_info_t platform_info;
#endif

/* for OSD shift function */
CONFIG_OSDSHIFT_STRUCT g_osdshift_ctrl;
struct proc_dir_entry *rtkgdma_proc_dir=0;
struct proc_dir_entry *rtkgdma_proc_entry=0;
#define RTKGDMA_PROC_DIR "rtkgdma"
#define RTKGDMA_PROC_ENTRY "dbg"

#define RTKGDMA_MAX_CMD_LENGTH (256)

bool GDMA_init_debug_proc(void);
void GDMA_uninit_debug_proc(void);
static inline bool rtkgdma_dbg_parse_value(char *cmd_pointer, long long *parsed_data);
static inline void rtkgdma_dbg_EXECUTE(const int cmd_index, char **cmd_pointer);

static const char *rtkgdma_cmd_str[] = {
	"h_shift=",		/* GDMA_DBG_CMD_SET_H_SHIFT */
	"v_shift=",		/* GDMA_DBG_CMD_SET_V_SHIFT */
	"osd_dp=",		/* GDMA_DBG_CMD_OSD_DUMP    */
	"osd_dp_ex=",		/* GDMA_DBG_CMD_OSD_DUMP_EX    */
	"osd_drop=",
	"osd_pattern=",
	"osd_vflip=",
	"osd_ctrl=",
	"osd_swap=",
	"osd_cap2mem=",
	"osd_info=",
	"osd_get_info=",
	"osd_ctrl_en=",
};

#if defined(CONFIG_RTK_KDRV_DC_MEMORY_TRASH_DETCTER)
#include <rtk_dc_mt.h>
#include <rbus/dc_sys_reg.h>
static void osd_debug_info(void);
DCMT_DEBUG_INFO_DECLARE(osd_mdscpu,osd_debug_info);
//for ANDROIDTV-305 test
static void osd_debug_info(void)
{
	dcmt_trap_info trap_info;
	unsigned int osd_rbase = GDMA_OSD1_CTRL_reg;
	char osd_msg[256] = {0};
#if defined(CONFIG_ARM64)
	volatile unsigned long wi_addr;
#else
	volatile unsigned int wi_addr;
#endif

	if(isDcmtTrap("TVSB4_OSD1")) {
		osd_rbase = GDMA_OSD1_CTRL_reg;
		snprintf(osd_msg, 256,"[OSD1]Trash:");
	}else if(isDcmtTrap("TVSB4_OSD2")) {
		osd_rbase = GDMA_OSD2_CTRL_reg;
		snprintf(osd_msg, 256,"[OSD2]Trash:");
	}else if(isDcmtTrap("TVSB4_OSD3")) {
		osd_rbase = GDMA_OSD3_CTRL_reg;
		snprintf(osd_msg, 256,"[OSD3]Trash:");
	}else{
		/*do nothing, shall we need printk ?*/
		printk(KERN_ERR"NOT OSDx module.\n");
		return;
	}
	/*get dcmt trap information (include trash_addr,module_id,rw_type)*/
	get_dcmt_trap_info(&trap_info);
	printk(KERN_ERR"=============%s=============\n",osd_msg);
	printk(KERN_ERR"\t%s=%08x\n",GDMA_UPDATE_reg_addr,
		rtd_inl(GDMA_UPDATE_reg));
	printk(KERN_ERR"\t%s=%08x\n",GDMA_CTRL_reg_addr,
		rtd_inl(GDMA_CTRL_reg));
	printk(KERN_ERR"\t======================================\n");
	printk(KERN_ERR"\t%08x=%08x\n",osd_rbase, rtd_inl(osd_rbase));
	printk(KERN_ERR"\t%08x=%08x\n",osd_rbase+0x4, rtd_inl(osd_rbase+0x4));
	printk(KERN_ERR"\t%08x=%08x\n",osd_rbase+0x8, rtd_inl(osd_rbase+0x8));
	printk(KERN_ERR"\t%08x=%08x\n",osd_rbase+0xc, rtd_inl(osd_rbase+0xc));
	printk(KERN_ERR"\t%08x=%08x\n",osd_rbase+0x10, rtd_inl(osd_rbase+0x10));

	if(rtd_inl(osd_rbase+0x10)) {
#if defined(CONFIG_ARM64)
		wi_addr = (volatile unsigned long)phys_to_virt(rtd_inl(osd_rbase+0x10));
		printk(KERN_ERR"\tsurface_addr=%lx\n",*((volatile unsigned long*)(wi_addr)+6));
#else
		wi_addr = (volatile unsigned int)phys_to_virt(rtd_inl(osd_rbase+0x10));
		printk(KERN_ERR"\tsurface_addr=%08x\n",*((volatile unsigned int*)(wi_addr)+6));
#endif
	}
	printk(KERN_ERR"======================================\n");
        return;
}
#endif
/*
 * 1. save current OSD buffer
 * 2. GDMA display this buffer and reject all update from AP
 *
 * st[3:0]: 0:disable,  1:enable
 * st[7:4]: 1:OSD1, 2:OSD2, 3:OSD3
 *
 * gdrop_counter is for drop GDMA_ReceivePicture
 *
 */
static int gdrop_counter =0;
static unsigned int gdrop_counter_phy =0;
static unsigned int* gdrop_counter_vir =0;

static void OSD_Freeze(unsigned int st) {
#if defined(CONFIG_RTK_KDRV_SE)
	KGAL_SURFACE_INFO_T src;
	KGAL_SURFACE_INFO_T dst;
	KGAL_RECT_T rect;
	KGAL_BLIT_FLAGS_T flags = KGAL_BLIT_NOFX;
	KGAL_BLIT_SETTINGS_T settings;
#if defined(CONFIG_ARM64)
	volatile unsigned long wi_addr;
#else
	volatile unsigned int wi_addr;
#endif
	unsigned int osd_rbase = 0;


	settings.srcBlend = KGAL_BLEND_ONE;
	settings.dstBlend = KGAL_BLEND_ZERO;

	if((st>>4 &0xf) == 0x1){
		osd_rbase = GDMA_OSD1_CTRL_reg+0x10;
	}else if((st>>4 &0xf) == 0x2){
		osd_rbase = GDMA_OSD2_CTRL_reg+0x10;
	}else if((st>>4 &0xf) == 0x3){
		osd_rbase = GDMA_OSD3_CTRL_reg+0x10;
	}else if((st&0xf) == 0xf) {
		gdrop_counter = (int)((st>>4)&0xfffffff);
		printk(KERN_ERR"[%s]OSD%d drop cnt %d\n",__func__, (st>>4 &0xf), gdrop_counter);
	}else{
		return;
	}

	if((st&0xf) == 1) {
		gdrop_counter = -1;
		msleep(16);
		if(rtd_inl(osd_rbase)) {
#if defined(CONFIG_ARM64)
			wi_addr = (volatile unsigned long)phys_to_virt(rtd_inl(osd_rbase));
			src.physicalAddress = (unsigned int)*((volatile unsigned long*)(wi_addr)+6);
#else
			wi_addr = (volatile unsigned int)phys_to_virt(rtd_inl(osd_rbase));
			src.physicalAddress = *((volatile unsigned int*)(wi_addr)+6);
#endif
			src.pitch = dst.pitch = 1920*4;
			src.bpp = dst.bpp = 32;
			src.width = dst.width = 1920;
			src.height = dst.height = 1090;
			src.pixelFormat = dst.pixelFormat = KGAL_PIXEL_FORMAT_ARGB;
			rect.x = 0;
			rect.y = 0;
			rect.w = 1920;
			rect.h = 1090;
		}else{
			gdrop_counter = 0;
			return;
		}
		if(gdrop_counter_vir == NULL) {
			gdrop_counter_vir = (unsigned int*)dvr_malloc_specific(1920*1090*4, GFP_DCU2_FIRST);
			if(gdrop_counter_vir == NULL) {
				printk(KERN_ERR"%s,fail! get memory fail.\n",__func__);
				gdrop_counter = 0;
				return;
			}
			gdrop_counter_phy = dvr_to_phys(gdrop_counter_vir);
		}
		dst.physicalAddress = gdrop_counter_phy;

		KGAL_Blit(&src, &rect, &dst, 0,0, &flags, &settings);
		printk(KERN_ERR"[%s]OSD%d Freeze\n",__func__, (st>>4 &0xf));
		msleep(5);
		/*debug, don't care finish*/
		*((volatile unsigned int*)(wi_addr)+6) = gdrop_counter_phy;
		return;
	}else if((st&0xf) == 0) {
		gdrop_counter = 0;
		printk(KERN_ERR"[%s]OSD%d unFreeze\n",__func__, (st>>4 &0xf));
		/*if this func is not for debug,  add sleep here*/
		if(gdrop_counter_vir) {
			dvr_free((void*)(gdrop_counter_vir));
			gdrop_counter_vir = NULL;
			gdrop_counter_phy = 0;
		}
	}
#endif
}
/*
 * OSD pattern
 * we have to save the info from GDAM_receivePicture,
 * if disable osd, we have update the last info.
 * 1. create 1290*720 surface,
 * 2. GAL draw color
 * 3. display
 */

static int gosdpattern =0;
static unsigned int gosdpattern_phy =0;
static unsigned int* gosdpattern_vir =0;
static PICTURE_LAYERS_OBJECT glastinfo;

static void OSD_Pattern(KADP_HAL_GAL_CTRL_T* pat) {
#if defined(CONFIG_RTK_KDRV_SE)
	KGAL_SURFACE_INFO_T src;
	KGAL_RECT_T rect;
	KGAL_DRAW_FLAGS_T flags = KGAL_DRAW_NOFX;
	KGAL_DRAW_SETTINGS_T settings;
	PICTURE_LAYERS_OBJECT *patlayer;
	GDMA_PICTURE_OBJECT *picObj;
	osd_planealpha_ar osdcmp_plane_ar;
	osd_planealpha_gb osdcmp_plane_gb;
	gdma_dev *gdma = &gdma_devices[0];
	VO_RECTANGLE disp_res;
	osdcmp_plane_ar.plane_alpha_r = 0xff;
	osdcmp_plane_ar.plane_alpha_a = 0xff;
	osdcmp_plane_gb.plane_alpha_b = 0xff;
	osdcmp_plane_gb.plane_alpha_g = 0xff;
	getDispSize(&disp_res);
	settings.srcBlend = KGAL_BLEND_ONE;
	settings.dstBlend = KGAL_BLEND_ZERO;

	if(pat->en == 0) {
		/*update last*/
		printk(KERN_ERR"%s %d,%d,%08x\n",
				__func__, pat->en, pat->osdn, pat->clr);
		gosdpattern = 0;
		GDMA_ReceivePicture(&glastinfo);
		msleep(16);
		if(gosdpattern_vir) {
			dvr_free((void*)(gosdpattern_vir));
			gosdpattern_vir = NULL;
			gosdpattern_phy = 0;
		}
	}else if(pat->en == 1) {
		if(gosdpattern_vir == NULL) {
			gosdpattern_vir = (unsigned int*)dvr_malloc_specific(1280*724, GFP_DCU1_FIRST);
			if(gosdpattern_vir == NULL) {
				printk(KERN_ERR"%s,fail! get memory fail.\n",__func__);
				return;
			}
			gosdpattern_phy = dvr_to_phys(gosdpattern_vir);
		}


		printk(KERN_ERR"%s get addr=%08x  \n", __func__, gosdpattern_phy);
		gosdpattern = 1;

		src.physicalAddress = gosdpattern_phy;
		src.pitch = 1280*4;
		src.bpp = 32;
		src.width = 1280;
		src.height = 724/4;
		src.pixelFormat = KGAL_PIXEL_FORMAT_ARGB;
		rect.x = 0;
		rect.y = 0;
		rect.w = 1280;
		rect.h = 724/4;
		KGAL_FillRectangle(&src, &rect, 0, &flags, &settings);
		msleep(2);

		patlayer =(PICTURE_LAYERS_OBJECT*)(gosdpattern_vir + 1280*720/4);
		//ARGB -> ABGR
		*(gdma->OSD_CLUT[0]) = (pat->clr&0xff000000) |
			(pat->clr&0xff0000) >>16 |
			(pat->clr&0xff00)|
			(pat->clr&0xff) << 16 ;
		printk(KERN_ERR"LUT8 addr = %p\n",gdma->OSD_CLUT[0]);
		picObj = &patlayer->layer[0].normal[0];
		picObj->format = VO_OSD_COLOR_FORMAT_8BIT;
		picObj->plane = (VO_GRAPHIC_PLANE)(pat->osdn&0x3?pat->osdn&0x3:1);
		patlayer->layer[0].onlineOrder = C0;
		patlayer->layer_num = 1;
		patlayer->layer[0].normal_num = 1;
		picObj->src_type = SRC_NORMAL;
		picObj->alpha = (pat->clr >> 24) &0xff;
		picObj->width = 1280;
		picObj->height = 720;
		picObj->address = gosdpattern_phy;
		picObj->pitch = 1280;
		picObj->layer_used = 1;

		picObj->plane_ar = osdcmp_plane_ar;
		picObj->plane_gb = osdcmp_plane_gb;
		picObj->show = 1;
		picObj->paletteformat = 1; /* rgba format */
		picObj->syncInfo.syncstamp = 0;
		picObj->scale_factor = 1;

		picObj->dst_width = disp_res.width;
		picObj->dst_height = disp_res.height;
		GDMA_ReceivePicture(patlayer);

	}
#endif
}

static int OSD_debug_vflip(unsigned int en) {
	gdma_dev *gdma = &gdma_devices[0];
	int osdn=1;
	unsigned int offset = 0x100;
	unsigned int regbase = GDMA_OSD1_CTRL_reg;
	GDMA_WIN* winfo = NULL;

	//GDMA_WIN* winfo_rotate = NULL;
	//GDMA_PIC_DATA *pic = NULL;

	if(gdma->ctrl.enableVFlip == en){
		//printk(KERN_ERR"[OSD]VFlip = %s\n",en?"Enable":"Disable");
		return 0;
	}
	gdma->ctrl.enableVFlip = en;
	printk(KERN_ERR"[OSD]change VFlip = %s\n",en?"Enable":"Disable");
	if(en)
		rtd_setbits(SFG_SFG_CTRL_0_reg,SFG_SFG_CTRL_0_h_flip_en_mask);
	else
		rtd_clearbits(SFG_SFG_CTRL_0_reg,SFG_SFG_CTRL_0_h_flip_en_mask);

	/* progdone all OSDs that has win info */
	for(osdn=1;osdn < GDMA_PLANE_MAXNUM;osdn++) {
		if(rtd_inl(regbase)&GDMA_OSD1_CTRL_osd1_en_mask &&
			rtd_inl(regbase+0x10)) {
			if(en) {
				rtd_setbits(regbase,GDMA_OSD1_CTRL_rotate_mask |
					GDMA_OSD1_CTRL_osd1_en_mask |
					GDMA_OSD1_CTRL_write_data_mask);
			}else {

				rtd_outl(regbase,GDMA_OSD1_CTRL_rotate_mask);
			}

			winfo = (GDMA_WIN*)phys_to_virt(rtd_inl(regbase+0x10));
			if(winfo->attr.IMGcompress) {
				//FBDC...
			}else{
				//pic = gdma->pic[osdn-1] + ((gdma->picQwr[osdn-1] -1) & (GDMA_MAX_PIC_Q_SIZE - 1));
				//winfo_rotate = &pic->OSDwin;
				//memcpy(winfo_rotate, winfo,sizeof(GDMA_WIN));

				//printk(KERN_ERR"old winfo = %p new is %p\n",winfo,winfo_rotate );
				if(en) {
					//winfo_rotate->top_addr +=winfo->pitch*winfo->winWH.height;
					winfo->top_addr +=winfo->pitch*winfo->winWH.height;
				}else {
					//winfo_rotate->top_addr -=winfo->pitch*winfo->winWH.height;
					winfo->top_addr -=winfo->pitch*winfo->winWH.height;
				}

				GDMA_Update(gdma, 1);
				//if(winfo_rotate->top_addr == winfo->top_addr)
				//	rtd_outl(regbase+0x10,GDMA_OSD1_WI_addr(virt_to_phys(winfo)));
				//else
				//	rtd_outl(regbase+0x10,GDMA_OSD1_WI_addr(virt_to_phys(winfo_rotate)));
				//gdma->picQwr[osdn-1] +=1;
			}
		}
		regbase +=offset;
	}
	rtd_outl(GDMA_CTRL_reg, 0xf);
	return 0;
}

/*============================================================
 *	inline func
*/

static void gdma_to_dump(void) {
#if 0
	unsigned int offset = 0;
	int ret=-1;
	if(osd_dump_state == -1 || (GDMA_DISPLAY_PLANE)osd_dump_state >= GDMA_PLANE_MAXNUM ){
		return;
	}

	if ((GDMA_DISPLAY_PLANE)osd_dump_state == GDMA_PLANE_OSD2)
		offset = 0x100;
	else if ((GDMA_DISPLAY_PLANE)osd_dump_state == GDMA_PLANE_OSD3)
		offset = 0x200;


	if(osd_dump_state) {
		volatile unsigned int *ptr;
		volatile unsigned int addr_tmp;
		osd_dmem_info pinfo;
		if(rtd_inl(GDMA_OSD1_WI_reg+offset)) {
			addr_tmp = (unsigned int)phys_to_virt(rtd_inl(GDMA_OSD1_WI_reg+offset));
			ptr = (unsigned int *)addr_tmp;
			ptr += 6;
			pinfo.src_phyaddr = *ptr;
			pinfo.pitch = 1280*4;
			ret = osd_dump_agent_add_task_to_queue(&pinfo);
			if(ret)
				osd_dump_state = -1;
		}
	}
#endif
}

static void gdma_config_fbc(void) {
#if 0
	online_RBUS online_reg;
	dma_swap_RBUS dma_swap_reg;

	/* balance with tv_sb3 and tv_sb4 */
	/* 1st: FBDC DMA for OSD1/4, but OSD2. OSD2 just for mouse */
	online_reg.regValue = rtd_inl(GDMA_ONLINE_reg);
	online_reg.set_osd1_fbdc1_use_2nd_dma = 0;  /*  tv_sb4 */
	online_reg.set_osd1_fbdc2_use_2nd_dma = 0;  /*  tv_sb4 */
	online_reg.set_osd1_fbdc3_use_2nd_dma = 0;  /*  tv_sb4 */
	online_reg.set_osd2_fbdc1_use_2nd_dma = 0;  /*  tv_sb4 */
	online_reg.set_osd2_fbdc2_use_2nd_dma = 0;  /*  tv_sb4 */
	online_reg.set_osd2_fbdc3_use_2nd_dma = 0;  /*  tv_sb4 */
	online_reg.set_osd3_fbdc1_use_2nd_dma = 1;  /*  tv_sb3 */
	online_reg.set_osd3_fbdc2_use_2nd_dma = 1;  /*  tv_sb3 */
	online_reg.set_osd3_fbdc3_use_2nd_dma = 1;  /*  tv_sb3 */
	/* 2nd: online/offline DMA */
	/*  online use offline DMA
	online_reg.set_osd4_online_use_offline_dma = 1; */
	rtd_outl(GDMA_ONLINE_reg, online_reg.regValue);

	/* for FBDC dma swap */
	dma_swap_reg.regValue = rtd_inl(GDMA_DMA_SWAP_reg);
	dma_swap_reg.fbdc1_1b = 1;
	dma_swap_reg.fbdc1_2b = 1;
	dma_swap_reg.fbdc1_4b = 1;
	dma_swap_reg.fbdc1_8b = 1;
	dma_swap_reg.fbdc2_1b = 1;
	dma_swap_reg.fbdc2_2b = 1;
	dma_swap_reg.fbdc2_4b = 1;
	dma_swap_reg.fbdc2_8b = 1;
	rtd_outl(GDMA_DMA_SWAP_reg, dma_swap_reg.regValue);
#endif
}

static void gdma_config_line_buffer(void) {
	line_buffer_sta_RBUS line_buffer_sta_reg;
	line_buffer_size_RBUS line_buffer_size_reg;
	line_buffer_end_RBUS line_buffer_end_reg;

	/* OSD_SR switch */
	line_buffer_end_reg.regValue = rtd_inl(GDMA_line_buffer_end_reg);
	line_buffer_end_reg.osdsr1_switch_to = GDMA_PLANE_OSD1;
	line_buffer_end_reg.osdsr2_switch_to = GDMA_PLANE_OSD3;
	rtd_outl(GDMA_line_buffer_end_reg, line_buffer_end_reg.regValue);

	/* line buffer setting */
	line_buffer_sta_reg.regValue = rtd_inl(GDMA_line_buffer_sta_reg);
	line_buffer_size_reg.regValue = rtd_inl(GDMA_line_buffer_size_reg);

	line_buffer_sta_reg.l4 = 0;
	line_buffer_sta_reg.l5 = 1;
	line_buffer_size_reg.l4 = 1;
	line_buffer_size_reg.l5 = 1;
	rtd_outl(GDMA_line_buffer_sta_reg, line_buffer_sta_reg.regValue);
	rtd_outl(GDMA_line_buffer_size_reg, line_buffer_size_reg.regValue);

}

static void gdma_config_mid_blend(void) {
	mid_blend_RBUS mid_blend_reg;
	osdovl_mixer_b1_RBUS mixer_bx_reg;
	osdovl_osd_db_ctrl_RBUS osd_db_ctrl_reg;

	/* mid-blend order */
	mid_blend_reg.regValue = rtd_inl(GDMA_mid_blend_reg);
	mid_blend_reg.c0_sel = GDMA_PLANE_OSD1;
	mid_blend_reg.c1_sel = GDMA_PLANE_OSD2;
	mid_blend_reg.c2_sel = GDMA_PLANE_OSD3;
	rtd_outl(GDMA_mid_blend_reg, mid_blend_reg.regValue);

	/* mixer blend factor & mid-blend blend factor & offline blend factor */
	mixer_bx_reg.k1 = 0xc;
	mixer_bx_reg.k2 = 0x3;
	mixer_bx_reg.k3 = 0x2d;
	mixer_bx_reg.k4 = 0x3;
	rtd_outl(OSDOVL_Mixer_b1_reg, mixer_bx_reg.regValue);
	rtd_outl(OSDOVL_Mixer_b2_reg, mixer_bx_reg.regValue);
	rtd_outl(OSDOVL_Mixer_b3_reg, mixer_bx_reg.regValue);

	rtd_outl(GDMA_mid_blend_b1_reg, mixer_bx_reg.regValue);
	rtd_outl(GDMA_mid_blend_b2_reg, mixer_bx_reg.regValue);
	mixer_bx_reg.k1 = 0x1;
	mixer_bx_reg.k2 = 0x4;
	mixer_bx_reg.k3 = 0x1;
	mixer_bx_reg.k4 = 0x4;
	rtd_outl(OSDOVL_Mixer_b3_reg, mixer_bx_reg.regValue);

	/* mixer double buffer */
	osd_db_ctrl_reg.regValue = rtd_inl(OSDOVL_OSD_Db_Ctrl_reg);
	osd_db_ctrl_reg.db_read = 1;	/* 1: see rbus setting temporarily, 0: see HW latch now  */
	osd_db_ctrl_reg.db_en = 1;
	osd_db_ctrl_reg.db_load = 1;
	rtd_outl(OSDOVL_OSD_Db_Ctrl_reg, osd_db_ctrl_reg.regValue);

}


static bool osd_shift_proc(void) {
	/*apply current OSD display*/
	GDMA_WIN *win;
	gdma_dev *gdma = &gdma_devices[0];

	if (g_osdshift_ctrl.plane == VO_GRAPHIC_OSD1)
		win = (GDMA_WIN *)phys_to_virt(rtd_inl(GDMA_OSD1_WI_reg));
	else if (g_osdshift_ctrl.plane == VO_GRAPHIC_OSD2)
		win = (GDMA_WIN *)phys_to_virt(rtd_inl(GDMA_OSD2_WI_reg));
	else if (g_osdshift_ctrl.plane == VO_GRAPHIC_OSD3)
		win = (GDMA_WIN *)phys_to_virt(rtd_inl(GDMA_OSD3_WI_reg));
	else {
		/*add printk*/
		memset(&g_osdshift_ctrl, 0x00, sizeof(CONFIG_OSDSHIFT_STRUCT));
		return false;
	}

	win = (GDMA_WIN *)phys_to_virt(rtd_inl(GDMA_OSD1_WI_reg));

	if (win == 0 || gdma == 0) {
		/*add printk*/
		return false;
	}

	down(&gdma->sem_receive);

	if (win->attr.IMGcompress == 0) {
		if (g_osdshift_ctrl.shift_h_enable) {
			win->winWH.width -= abs(g_osdshift_ctrl.h_shift_pixel);
			if (g_osdshift_ctrl.h_shift_pixel > 0)	// shift right
				win->winXY.x += g_osdshift_ctrl.h_shift_pixel;
			else	// shift left
				win->objOffset.objXoffset += abs(g_osdshift_ctrl.h_shift_pixel);
		}
		if (g_osdshift_ctrl.shift_v_enable) {
			win->winWH.height -= abs(g_osdshift_ctrl.v_shift_pixel);
			if (g_osdshift_ctrl.v_shift_pixel > 0)	// shift down
				win->winXY.y += g_osdshift_ctrl.v_shift_pixel;
			else	// shift up
				win->objOffset.objYoffset += abs(g_osdshift_ctrl.v_shift_pixel);
		}
	} else {

		if (g_osdshift_ctrl.shift_h_enable) {
			if (win->fbdc_attr.fbdc_1st_en) {
				win->fbdc1_xy_pixel.x_pic_pixel -= abs(g_osdshift_ctrl.h_shift_pixel);
				if (g_osdshift_ctrl.h_shift_pixel > 0)	// shift right
					win->fbdc1_preblend_xy_sta.x_sta += g_osdshift_ctrl.h_shift_pixel;
				else	// shift left
					win->fbdc1_xy_sta.x_sta += abs(g_osdshift_ctrl.h_shift_pixel);
			}
			if (win->fbdc_attr.fbdc_2nd_en) {
				win->fbdc2_xy_pixel.x_pic_pixel -= abs(g_osdshift_ctrl.h_shift_pixel);
				if (g_osdshift_ctrl.h_shift_pixel > 0)	// shift right
					win->fbdc2_preblend_xy_sta.x_sta += g_osdshift_ctrl.h_shift_pixel;
				else	// shift left
					win->fbdc2_xy_sta.x_sta += abs(g_osdshift_ctrl.h_shift_pixel);
			}
			if (win->fbdc_attr.fbdc_3rd_en) {
				win->fbdc3_xy_pixel.x_pic_pixel -= abs(g_osdshift_ctrl.h_shift_pixel);
				if (g_osdshift_ctrl.h_shift_pixel > 0)	// shift right
					win->fbdc3_preblend_xy_sta.x_sta += g_osdshift_ctrl.h_shift_pixel;
				else	// shift left
					win->fbdc3_xy_sta.x_sta += abs(g_osdshift_ctrl.h_shift_pixel);
			}
		}
		if (g_osdshift_ctrl.shift_v_enable) {
			if (win->fbdc_attr.fbdc_1st_en) {
				win->fbdc1_xy_pixel.y_pic_pixel -= abs(g_osdshift_ctrl.v_shift_pixel);
				if (g_osdshift_ctrl.v_shift_pixel > 0)	// shift down
					win->fbdc1_preblend_xy_sta.y_sta += g_osdshift_ctrl.v_shift_pixel;
				else	// shift up
					win->fbdc1_xy_sta.y_sta += abs(g_osdshift_ctrl.v_shift_pixel);
			}
			if (win->fbdc_attr.fbdc_2nd_en) {
				win->fbdc2_xy_pixel.y_pic_pixel -= abs(g_osdshift_ctrl.v_shift_pixel);
				if (g_osdshift_ctrl.v_shift_pixel > 0)	// shift down
					win->fbdc2_preblend_xy_sta.y_sta += g_osdshift_ctrl.v_shift_pixel;
				else	// shift up
					win->fbdc2_xy_sta.y_sta += abs(g_osdshift_ctrl.v_shift_pixel);
			}
			if (win->fbdc_attr.fbdc_3rd_en) {
				win->fbdc3_xy_pixel.y_pic_pixel -= abs(g_osdshift_ctrl.v_shift_pixel);
				if (g_osdshift_ctrl.v_shift_pixel > 0)	// shift down
					win->fbdc3_preblend_xy_sta.y_sta += g_osdshift_ctrl.v_shift_pixel;
				else	// shift up
					win->fbdc3_xy_sta.y_sta += abs(g_osdshift_ctrl.v_shift_pixel);
			}
		}
	}

#if !defined(CONFIG_ARM64)
	flush_cache_all();
#endif
	up(&gdma->sem_receive);
	GDMA_OSD1OnTop(true);

	return true;
}

/*
 * a.k.a  OSD dump
 * if type == 0, dump one frame to file
 * if type == 1, stretch dump 25 frames to file .
 */
int gdma_osd_writedump(unsigned int type, unsigned int osdn, osd_dmem_info* pinfo,osd_dmem_info* pinfo_stch) {
	//gdma_dev *gdma = &gdma_devices[0];
	unsigned int offset = 0x100;
	unsigned int regbase = GDMA_OSD1_CTRL_reg;
	GDMA_WIN* winfo = NULL;
	int cntw = 0;
	int cnth = 0;
	osd_dmem_info dinfo;
	unsigned int mixercrc = 0;
	unsigned int timeoutcnt=0;

	regbase += (osdn-1)*offset;

	if(rtd_inl(regbase)&GDMA_OSD1_CTRL_osd1_en_mask &&
		rtd_inl(regbase+0x10)) {
		winfo = (GDMA_WIN*)phys_to_virt(rtd_inl(regbase+0x10));
	}else{
		printk(KERN_ERR"OSD-%d is empty\n",osdn);
		return -1;
	}
#if 0
	/*need to handle compression data?*/
	if(winfo->attr.type != 0x7){
		printk(KERN_ERR"OSD-%d isn't ARGB8888\n",osdn);
		return -1;
	}
#endif


	pinfo->src_phyaddr = winfo->top_addr;

	pinfo->x = 0;
	pinfo->y = 0;
	pinfo->w = winfo->winWH.width;
	pinfo->h = winfo->winWH.height;
	pinfo->pitch = winfo->pitch;

	if(pinfo->dst_phyaddr == 0){
		pinfo->viraddr = (unsigned char*)dvr_malloc_specific(winfo->pitch*winfo->winWH.height+0x36 , GFP_DCU1_FIRST);
		if(pinfo->viraddr == 0) {
			printk(KERN_ERR"%s,fail! get memory fail.\n",__func__);
			return -1;
		}else{
			pinfo->dst_phyaddr = dvr_to_phys(pinfo->viraddr);
		}
	}

	if(!pinfo->fname)
		snprintf(pinfo->fname, 128,"%s/dump_%08d.bmp",pinfo->fnamebase, rtd_inl(0xB801B690));

	if(type == 0) {
		osd_deme_cpy(pinfo);
	}else{
		dinfo.x = 0;
		dinfo.y = 0;
		dinfo.w = winfo->winWH.width/5;
		dinfo.h = winfo->winWH.height/5;
		dinfo.pitch = winfo->pitch;
		rtd_outl(OSDOVL_Mixer_CRC_Sel_reg, osdn);
		rtd_outl(OSDOVL_Mixer_CRC_Ctrl_reg, 0x7);
		mixercrc = rtd_inl(OSDOVL_Mixer_CRC_Result_reg);

		for(cnth=0;cnth <5;cnth++) {
			dinfo.y = (winfo->winWH.height/5)*cnth;
			for(cntw=0;cntw <5;cntw++) {
				dinfo.x = (winfo->winWH.width/5)*cntw;
				while(rtd_inl(OSDOVL_Mixer_CRC_Result_reg) == mixercrc) {
					msleep(1);
					timeoutcnt++;
					if(timeoutcnt >=16) {
						timeoutcnt=0;
						break;
				}
				}
				winfo = (GDMA_WIN*)phys_to_virt(rtd_inl(regbase+0x10));
				pinfo->src_phyaddr = winfo->top_addr;
				osd_deme_stch_cpy(pinfo,&dinfo);
				mixercrc = rtd_inl(OSDOVL_Mixer_CRC_Result_reg);
				printk(KERN_ERR"CRC change..%08x\n",mixercrc);
			}

		}
	}
	osd_deme_write_file(pinfo);
	printk(KERN_INFO"%s , dump osd=%d, path = %s\n",
		__func__, osdn, pinfo->fname);
	if(pinfo->viraddr)
	dvr_free((void*)(pinfo->viraddr));
	pinfo->viraddr = NULL;
	return 0;
}

/*
 * a.k.a  OSD dump to mem
 */
int gdma_osd_dmp2mem(KADP_HAL_GAL_CTRL_T *data) {
#if defined(CONFIG_RTK_KDRV_SE)
	KGAL_SURFACE_INFO_T src_sf;
	KGAL_RECT_T src_rect;
	KGAL_SURFACE_INFO_T dst_sf;
	KGAL_RECT_T dst_rect;
	KGAL_BLIT_FLAGS_T flags = KGAL_BLIT_NOFX;
	KGAL_BLIT_SETTINGS_T settings;
	unsigned int regbase = GDMA_OSD1_CTRL_reg;
	GDMA_WIN* winfo = NULL;
	regbase += ((data->osdn-1)*0x100);

	memset(&src_sf, 0, sizeof(KGAL_SURFACE_INFO_T));
	memset(&dst_sf, 0, sizeof(KGAL_SURFACE_INFO_T));
	memset(&src_rect, 0, sizeof(KGAL_RECT_T));
	memset(&dst_rect, 0, sizeof(KGAL_RECT_T));

	settings.srcBlend = KGAL_BLEND_ONE;
	settings.dstBlend = KGAL_BLEND_ZERO;

	if(rtd_inl(regbase)&GDMA_OSD1_CTRL_osd1_en_mask &&
		rtd_inl(regbase+0x10)) {
		winfo = (GDMA_WIN*)phys_to_virt(rtd_inl(regbase+0x10));
	}else{
		printk(KERN_ERR"OSD-%d is empty\n",data->osdn);
		return -1;
	}
	if(winfo->attr.type != 0x7){
		printk(KERN_ERR"OSD-%d isn't ARGB8888\n",data->osdn);
		return -1;
	}
	if((data->capinfo.x + data->capinfo.w >winfo->winWH.width) ||
		(data->capinfo.y + data->capinfo.h >winfo->winWH.height)){

		printk(KERN_ERR"[%s]cap out of range ,surface=[%d,%d], cap=[%d,%d,%d,%d]\n",
			__func__,winfo->winWH.width ,winfo->winWH.height,
			data->capinfo.x, data->capinfo.y ,
			data->capinfo.w, data->capinfo.h);
		return -1;
	}

	src_sf.physicalAddress = winfo->top_addr;
	src_sf.pitch = winfo->pitch;
	src_sf.bpp = 32;
	src_sf.width = winfo->winWH.width;
	src_sf.height = winfo->winWH.height;
	src_sf.pixelFormat = KGAL_PIXEL_FORMAT_ARGB;


	dst_sf.physicalAddress = data->stchinfo.phyaddr;
	dst_sf.pitch = data->stchinfo.pitch;
	dst_sf.width = data->stchinfo.w;
	dst_sf.height = data->stchinfo.h;
	if(data->stchinfo.fmt == KGAL_PIXEL_FORMAT_ARGB) {
		dst_sf.bpp = 32;
		dst_sf.pixelFormat = KGAL_PIXEL_FORMAT_ARGB;
	}else if(data->stchinfo.fmt == KGAL_PIXEL_FORMAT_RGB888){
		dst_sf.bpp = 24;
		dst_sf.pixelFormat = KGAL_PIXEL_FORMAT_RGB888;
	}else{
		printk(KERN_ERR"[%s]error!, unsupport FMT = %d\n",__func__, data->stchinfo.fmt);
		return -1;
	}


	src_rect.x=data->capinfo.x;
	src_rect.y=data->capinfo.y;
	src_rect.w=data->capinfo.w;
	src_rect.h=data->capinfo.h;

	dst_rect.x=data->stchinfo.x;
	dst_rect.y=data->stchinfo.y;
	dst_rect.w=data->stchinfo.w;
	dst_rect.h=data->stchinfo.h;

	KGAL_StretchBlit(&src_sf,&src_rect,&dst_sf,&dst_rect,
		&flags,&settings);

#endif
	return 0;
}

static int gdma_osd_winfo_dump(void) {
	unsigned int offset = 0x100;
	unsigned int regbase = GDMA_OSD1_CTRL_reg;
	unsigned int regvalue = 0;
	int osdn = 1;
	GDMA_WIN* winfo = NULL;
	VO_RECTANGLE res;
	getDispSize(&res);
	printk(KERN_ERR"====panel info : [%d*%d]\n",res.width,res.height);

	for(osdn=1;osdn<GDMA_PLANE_MAXNUM;osdn++) {
		winfo = NULL;
		regbase += (osdn-1)*offset;
		regvalue = rtd_inl(regbase+0x10);
		if(regvalue)
			winfo = (GDMA_WIN*)phys_to_virt(regvalue);
		if(winfo == NULL) {
			printk(KERN_ERR"\n====OSD-%d is None\n\n",osdn);
			continue;
		}
		regvalue =rtd_inl(regbase);
		printk(KERN_ERR"====OSD-%d info===\n",osdn);
		printk(KERN_ERR"Enable = %d, VFlip = %d\n",
			GDMA_OSD1_CTRL_get_osd1_en(regvalue)?1:0,
			GDMA_OSD1_CTRL_get_rotate(regvalue)?1:0);
		printk(KERN_ERR"winfo addr= (%p)\n", winfo);
		printk(KERN_ERR"winfo canvas= (%d,%d,%d,%d), offsetXY=(%d,%d)\n",
			winfo->winXY.x,winfo->winXY.y,
			winfo->winWH.width,winfo->winWH.height,
			winfo->objOffset.objXoffset,winfo->objOffset.objYoffset);
		printk(KERN_ERR"winfo pitch= (%d) addr=%08x\n",
			winfo->pitch,winfo->top_addr);
		printk(KERN_ERR"Format=%x Compress = %d\n",
			winfo->attr.type,
			winfo->attr.IMGcompress?1:0);
	}


	if(OSD_SR_1_Scaleup_Ctrl1_get_h_zoom_en(rtd_inl(OSD_SR_1_Scaleup_Ctrl1_reg))) {
		printk(KERN_ERR"\n====OSDSR-1 : X=%d, W=%d\n",
		OSD_SR_1_H_Location_Ctrl_get_osd_h_sta(rtd_inl(OSD_SR_1_H_Location_Ctrl_reg)),
		OSD_SR_1_H_Location_Ctrl_get_osd_width(rtd_inl(OSD_SR_1_H_Location_Ctrl_reg)));
	}

	if(OSD_SR_1_Scaleup_Ctrl0_get_v_zoom_en(rtd_inl(OSD_SR_1_Scaleup_Ctrl0_reg))) {
		printk(KERN_ERR"\n====OSDSR-1 : Y=%d, H=%d\n",
		OSD_SR_1_V_Location_Ctrl_get_osd_v_sta(rtd_inl(OSD_SR_1_V_Location_Ctrl_reg)),
		OSD_SR_1_V_Location_Ctrl_get_osd_height(rtd_inl(OSD_SR_1_V_Location_Ctrl_reg)));
	}

	if(OSD_SR_2_Scaleup_Ctrl1_get_h_zoom_en(rtd_inl(OSD_SR_2_Scaleup_Ctrl1_reg))) {
		printk(KERN_ERR"\n====OSDSR-2 : X=%d, W=%d\n",
		OSD_SR_2_H_Location_Ctrl_get_osd_h_sta(rtd_inl(OSD_SR_2_H_Location_Ctrl_reg)),
		OSD_SR_2_H_Location_Ctrl_get_osd_width(rtd_inl(OSD_SR_2_H_Location_Ctrl_reg)));
	}

	if(OSD_SR_2_Scaleup_Ctrl0_get_v_zoom_en(rtd_inl(OSD_SR_2_Scaleup_Ctrl0_reg))) {
		printk(KERN_ERR"\n====OSDSR-2 : Y=%d, H=%d\n",
		OSD_SR_2_V_Location_Ctrl_get_osd_v_sta(rtd_inl(OSD_SR_2_V_Location_Ctrl_reg)),
		OSD_SR_2_V_Location_Ctrl_get_osd_height(rtd_inl(OSD_SR_2_V_Location_Ctrl_reg)));
	}

	return 0;
}

static int gdma_osd_winfo_read(KADP_HAL_GAL_CTRL_T *data) {
	unsigned int offset = 0x100;
	unsigned int regbase = GDMA_OSD1_CTRL_reg;
	unsigned int regvalue = 0;
	GDMA_WIN* winfo = NULL;
	regbase += (data->osdn-1)*offset;
	regvalue = rtd_inl(regbase+0x10);

	data->capinfo.x = 0;
	data->capinfo.y = 0;
	data->capinfo.w = 0;
	data->capinfo.h = 0;

	data->stchinfo.x = 0;
	data->stchinfo.y = 0;
	data->stchinfo.w = 0;
	data->stchinfo.h = 0;

	if(regvalue)
		winfo = (GDMA_WIN*)phys_to_virt(regvalue);
	if(winfo == NULL)
		return 0;

	data->capinfo.x = winfo->winXY.x;
	data->capinfo.y = winfo->winXY.y;
	data->capinfo.w = winfo->winWH.width;
	data->capinfo.h = winfo->winWH.height;

	/*ToDo: need to check the pair of OSD and SR*/

	if(OSD_SR_1_Scaleup_Ctrl1_get_h_zoom_en(rtd_inl(OSD_SR_1_Scaleup_Ctrl1_reg))) {
		data->stchinfo.x = OSD_SR_1_H_Location_Ctrl_get_osd_h_sta(rtd_inl(OSD_SR_1_H_Location_Ctrl_reg));
		data->stchinfo.w = OSD_SR_1_H_Location_Ctrl_get_osd_width(rtd_inl(OSD_SR_1_H_Location_Ctrl_reg));
	}

	if(OSD_SR_1_Scaleup_Ctrl0_get_v_zoom_en(rtd_inl(OSD_SR_1_Scaleup_Ctrl0_reg))) {
		data->stchinfo.y = OSD_SR_1_V_Location_Ctrl_get_osd_v_sta(rtd_inl(OSD_SR_1_V_Location_Ctrl_reg));
		data->stchinfo.h = OSD_SR_1_V_Location_Ctrl_get_osd_height(rtd_inl(OSD_SR_1_V_Location_Ctrl_reg));
	}

	return 0;
}

#ifdef CONFIG_COMPAT
#if defined(CONFIG_ARM64)
long compat_GDMA_ioctl(struct file *filp, unsigned int cmd, unsigned long arg);
#else
int compat_GDMA_ioctl(struct file *filp, unsigned int cmd, unsigned long arg);
#endif
#endif

struct file_operations gdma_fops
	= {
	.owner    =    THIS_MODULE,
	.llseek   =    GDMA_llseek,
	.read     =    GDMA_read,
	.write    =    GDMA_write,
	.unlocked_ioctl    =    (void *)GDMA_ioctl,
	.open     =    GDMA_open,
	.release  =    GDMA_release,
#ifdef CONFIG_COMPAT
	.compat_ioctl   = compat_GDMA_ioctl,
#endif
};

/* Osd sync work queue for hwc sync */
#define SYN_TRY_MAX 2
struct workqueue_struct *psOsdSyncWorkQueue;
struct work_struct sOsdSyncWork;

#ifdef USR_WORKQUEUE_UPDATE_BUFFER
//#define TRIPLE_BUFFER_TRY_SLEEP_DIV 3
#define USE_TRIPLE_BUFFER_NUM   1
//#define TRIPLE_BUFFER_TRY_NUM   (20)
#define TRIPLE_BUFFER_TRY_NUM   (32)
//#define TRIPLE_BUFFER_TRY_SLEEP 2
#define TRIPLE_BUFFER_TRY_SLEEP 1

struct workqueue_struct *psOsd1RecWorkQueue;
struct gdma_receive_work sOSD1ReceiveWork[USE_TRIPLE_BUFFER_NUM];

#endif

/* gdma workqueue  */
struct gdma_receive_work sGdmaReceiveWork[GDMA_MAX_PIC_Q_SIZE];

/* use in GDMA_Update */
volatile int osdSyncStamp[GDMA_PLANE_MAXNUM] = {0};	/*  keep the setting which picture has syncstamp */
volatile int osdSyncStampTimeout[GDMA_PLANE_MAXNUM] = {0};


/* GDMA_CTRL_reg   <-- OSD apply */
/* GDMA_OSD1_CTRL_reg <-- OSD1 enabled */
unsigned int osd_ctrl_data[GDMA_PLANE_MAXNUM];

/* buffer address for online write-back */
unsigned int gOnlineWbaddr = 0;

/* start check for interrupt routing to SCPU */
unsigned int g_StartCheckFrameCnt = 100;

#ifdef CONFIG_PM
unsigned int GDMA_PM_REGISTER_DATA[][2]
= {
	{ OSDOVL_Mixer_CTRL2_reg, 0},
	{ OSDOVL_Mixer_layer_sel_reg, 0},
	{ GDMA_line_buffer_sta_reg, 0 },
	{ GDMA_line_buffer_size_reg, 0 },
	{ GDMA_line_buffer_end_reg, 0 },
	{ GDMA_OSD1_reg, 0 },
	{ GDMA_OSD1_START_reg, 0 },
	{ GDMA_OSD1_WI_reg, 0 },
	{ GDMA_OSD1_WI_3D_reg, 0 },
	{ GDMA_OSD1_SIZE_reg, 0 },
#if 0
	{ GDMA_OSD2_reg, 0 },
	{ GDMA_OSD2_START_reg, 0 },
	{ GDMA_OSD2_WI_reg, 0 },
	{ GDMA_OSD2_WI_3D_reg, 0 },
	{ GDMA_OSD2_SIZE_reg, 0 },
#endif
	{ GDMA_OSD3_reg, 0 },
	{ GDMA_OSD3_START_reg, 0 },
	{ GDMA_OSD3_WI_reg, 0 },
	{ GDMA_OSD3_WI_3D_reg, 0 },
	{ GDMA_OSD3_SIZE_reg, 0 },
	{ OSD_SR_1_Scaleup_Ctrl0_reg, 0 },
	{ OSD_SR_1_Scaleup_Ctrl1_reg, 0 },
	{ OSD_SR_1_H_Location_Ctrl_reg, 0 },
	{ OSD_SR_1_V_Location_Ctrl_reg, 0 },
	{ OSD_SR_2_Scaleup_Ctrl0_reg, 0 },
	{ OSD_SR_2_Scaleup_Ctrl1_reg, 0 },
	{ OSD_SR_2_H_Location_Ctrl_reg, 0 },
	{ OSD_SR_2_V_Location_Ctrl_reg, 0 },
};
#endif


void GDMA_CopyLayerInfo(GDMA_PICTURE_OBJECT *dest, GDMA_LAYER_OBJECT *src);

void getDispSize(VO_RECTANGLE *disp_rec)
{
	ppoverlay_memcdtg_dh_den_start_end_RBUS dtg_dh;
	ppoverlay_memcdtg_dv_den_start_end_RBUS dtg_dv;
	unsigned int actvie_h = 0;
	unsigned int actvie_v = 0;

	dtg_dh.regValue = rtd_inl(PPOVERLAY_memcdtg_DH_DEN_Start_End_reg);
	dtg_dv.regValue = rtd_inl(PPOVERLAY_memcdtg_DV_DEN_Start_End_reg);
	memset(disp_rec, 0, sizeof(VO_RECTANGLE));

	actvie_h = dtg_dh.memcdtg_dh_den_end-dtg_dh.memcdtg_dh_den_sta;
	actvie_v = dtg_dv.memcdtg_dv_den_end-dtg_dv.memcdtg_dv_den_sta;

	if ((actvie_h > 3800) && (actvie_h <= 3850))
		actvie_h = 3840;
	else if ((actvie_h > 1900) && (actvie_h <= 1930))
		actvie_h = 1920;

	if ((actvie_v > 2100) && (actvie_v <= 2170))
		actvie_v = 2160;
	else if ((actvie_v > 1000) && (actvie_v <= 1090))
		actvie_v = 1080;

	if(actvie_h == 0 || actvie_v ==0) {
		actvie_h = 1920;
		actvie_v = 1080;
		printk(KERN_INFO"[GDMA] forced to set Disp 2k1k.\n");
	}

	disp_rec->width = actvie_h;
	disp_rec->height = actvie_v;

	return;

}

#ifdef USR_WORKQUEUE_UPDATE_BUFFER
void osd1_send_hw(struct work_struct *psWork)
{
    struct gdma_receive_work *d_work;
    gdma_dev *gdma = &gdma_devices[0];

    d_work = (struct gdma_receive_work *)psWork;
    GDMA_ReceivePicture(d_work->data);

	down(&gdma->sem_work);
	d_work->used = 0;
    up(&gdma->sem_work);
}
#endif

void osd_sync_hwc(struct work_struct *psWork)
{
	gdma_dev *gdma = &gdma_devices[0];
	int ret;

	/* pr_debug(KERN_EMERG"func=%s line=%d sem->count=%d\n",__FUNCTION__,__LINE__,gdma->vsync_sem.count); */
	/* if (gdma->vsync_sem.count < 1) */
	up(&gdma->vsync_sem);
	/* msleep(1); */
	ret = down_trylock(&gdma->vsync_sem);
	/* down_interruptible(&gdma->vsync_sem); */
	/* mutex_unlock(&gdma_vsync_lock); */
	/* pr_debug(KERN_EMERG"func=%s line=%d sem->count=%d\n",__FUNCTION__,__LINE__,gdma->vsync_sem.count); */

}

void GDMA_ENTER_CRITICAL (void)
{
	gdma_dev *gdma = &gdma_devices[0];
	/* disable GDMA interrupt */
	if (gdma->ctrl.enable3D)
		rtd_outl(GDMA_OSD_INTEN_3D_reg, GDMA_OSD_INTEN_3D_write_data(0) | GDMA_OSD_INTEN_3D_osd1_vact_end(1));
	else
#ifndef USING_GDMA_VSYNC
#ifdef TRIPLE_BUFFER_SEMAPHORE
		rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(0) | GDMA_OSD_INTEN_osd1_vact_end(1) | GDMA_OSD_INTEN_osd1_vsync(1));
#else
		rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(0) | GDMA_OSD_INTEN_osd1_vact_end(1));
#endif
#else
		rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(0) | GDMA_OSD_INTEN_osd1_vsync(1));
#endif
	return;
}

void GDMA_EXIT_CRITICAL (void)
{
	gdma_dev *gdma = &gdma_devices[0];
	/* enable GDMA interrupt */
	if (gdma->ctrl.enable3D)
		rtd_outl(GDMA_OSD_INTEN_3D_reg, GDMA_OSD_INTEN_3D_write_data(1) | GDMA_OSD_INTEN_3D_osd1_vact_end(1));
	else
#ifndef USING_GDMA_VSYNC
#ifdef TRIPLE_BUFFER_SEMAPHORE
		rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(1) | GDMA_OSD_INTEN_osd1_vact_end(1) | GDMA_OSD_INTEN_osd1_vsync(1));
#else
		rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(1) | GDMA_OSD_INTEN_osd1_vact_end(1));
#endif
#else
		rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(1) | GDMA_OSD_INTEN_osd1_vsync(1));
#endif

	return;
}

void GDMA_UpdateGraphicwindow (int bBlocking, VO_GRAPHIC_PLANE plane)
{
	gdma_dev   *gdma     = &gdma_devices[0];
	GDMA_PLANE *osdPlane = &gdma->osdPlane[plane];
	GDMA_WIN   *win = 0;
	unsigned int i, osdEn;
	GDMA_PICTURE_OBJECT *picObj;
	static PICTURE_LAYERS_OBJECT *picLayerObj;
	int onlinePlane[GDMA_PLANE_MAXNUM], onlineMaxNum = 0, onlineIdx = 0;
	VO_GRAPHIC_PLANE disPlane;
	onlinePlane[onlineMaxNum++] = VO_GRAPHIC_OSD1;
	onlinePlane[onlineMaxNum++] = VO_GRAPHIC_OSD2;
	onlinePlane[onlineMaxNum++] = VO_GRAPHIC_OSD3;

	if (picLayerObj == NULL) {
		picLayerObj = (PICTURE_LAYERS_OBJECT *)kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
		if (picLayerObj == NULL) {
			pr_debug(KERN_EMERG"%s, kmalloc failed \n", __FUNCTION__);
			return;
		}
	}

	memset(picLayerObj, 0, sizeof(PICTURE_LAYERS_OBJECT));
	picObj = &picLayerObj->layer[0].normal[OSD1_1];

	down(&gdma->sem);

	GDMA_ENTER_CRITICAL ();

	osdEn = osdPlane->OSD_ctrl.en;
	if ((osdEn && !osdPlane->OSD_ctrl.hwTurnOff)) {
		picLayerObj->layer_num = 1;
		picLayerObj->layer[0].normal_num = 1;

		memcpy (osdPlane->OSDwinBuf[osdPlane->OSD_ctrl.index], osdPlane->OSDwin, sizeof(osdPlane->OSDwin));

		/* for (i=0, win = &osdPlane->OSDwinBuf[osdPlane->OSD_ctrl.index][osdPlane->OSD_topid]; i < osdPlane->numOSDwins; i++) */
		for (i = 0, win = &osdPlane->OSDwinBuf[osdPlane->OSD_ctrl.index][osdPlane->OSD_topid]; i < 1; i++) {
			if (win->ctrl.drawn) {
				picObj->alpha = (win->attr.alphaEn == 0) ? 0 : win->attr.alpha;
				picObj->rgb_order = win->attr.rgbOrder;
				picObj->clear_x.value = 0;
				picObj->clear_y.value = 0;
				picObj->colorkey = (win->colorKey.keyEn == 0) ? -1 : win->colorKey.key;

				picObj->compressed = win->attr.compress;

				/*picObj->context = src->context; */
				/*picObj->decompress = src->decompress; */
				picObj->dst_height = osdPlane->OSD_canvas.dispWin.height;
				picObj->dst_width = osdPlane->OSD_canvas.dispWin.width;
				picObj->dst_x = osdPlane->OSD_canvas.dispWin.x;
				picObj->dst_y = osdPlane->OSD_canvas.dispWin.y;
				/*picObj->fbdc_format = src->format; */
				picObj->format = (win->attr.type) | (win->attr.littleEndian<<5);
				picObj->height = win->winWH.height;
				picObj->key_en = win->colorKey.keyEn;
				picObj->layer_used = 1;
				/*picObj->paletteIndex = src->paletteIndex; */
				/*picObj->picLayout = src->picLayout; */
				picObj->pitch = win->pitch;
				/*
				* workaround for system AP call that uses the old definition VO_GRAPHIC_OSD1 or VO_GRAPHIC_OSD is zero
				* force the zero of plane value to one of VO_GRAPHIC_OSD1
				*/
#if defined(CONFIG_ARCH_RTK284X)
				picObj->plane = (plane == 0) ? VO_GRAPHIC_OSD1 : VO_GRAPHIC_OSD3;//plane;
#else
				picObj->plane = (plane == 0) ? VO_GRAPHIC_OSD1 : plane;
#endif
				picObj->plane_ar.plane_alpha_r = 0xff;
				picObj->plane_ar.plane_alpha_a = 0xff;
				picObj->plane_gb.plane_alpha_g = 0xff;
				picObj->plane_gb.plane_alpha_b = 0xff;
				/*picObj->seg_addr */
				/*picObj->seg_num */
				picObj->show = 1;       /*  always show the picture by normal update pic flow */
				picObj->src_type = SRC_NORMAL;
				picObj->syncInfo.syncstamp = 0;
				picObj->scale_factor = 1;
				if (picObj->compressed) {
					picObj->wbType = RTKCOMPRESS;
					/*
					picObj->wbType = ARGB8888;
					picObj->wbType = RBG888;
					*/
				}
				picObj->width = win->winWH.width;
				picObj->x = win->winXY.x;
				picObj->y = win->winXY.y;
				picObj->address = win->top_addr+(win->objOffset.objYoffset * win->pitch);
				picObj->offlineOrder = C0;

				for (onlineIdx = 0; onlineIdx < onlineMaxNum; onlineIdx++) { /* online dispaly check & set blend order */
					disPlane = onlinePlane[onlineIdx];

					if (picObj->plane == disPlane) {
						picLayerObj->layer[0].onlineOrder = (E_BLEND_ORDER)onlineIdx;
						break;
					}
				}

				if (onlineIdx == onlineMaxNum) {	/* plane does NOT indicate the online path of OSD */
					if (picObj->compressed == 0) {
						pr_debug(KERN_EMERG"%s OSD%d are offline, Does NOT display with this plane if plane doesn't compress \n", __FUNCTION__, picObj->plane);
						continue;
					}
				}

				GDMA_ReceivePicture(picLayerObj);
			}
		}
	}
	GDMA_EXIT_CRITICAL();
	up(&gdma->sem);
}

int GDMA_ConfigureGraphicCanvas (VIDEO_RPC_VOUT_CONFIG_GRAPHIC_CANVAS *cmd)
{

	DBG_PRINT(KERN_EMERG"GDMA: GDMA_CONFIGURE_GRPAHIC_CANVAS,plane %d\n", cmd->plane);
	DBG_PRINT(KERN_EMERG"GDMA: src x %d y %d w %d h %d, disp x %d y %d w %d h %d\n", cmd->srcWin.x, cmd->srcWin.y, cmd->srcWin.width, cmd->srcWin.height, cmd->dispWin.x, cmd->dispWin.y, cmd->dispWin.width, cmd->dispWin.height);
#if 0
	gdma_dev   *gdma     = &gdma_devices[0];
	GDMA_PLANE *osdPlane = &gdma->osdPlane[cmd->plane];
	osdPlane->OSD_canvas.en = 1;
	osdPlane->OSD_canvas.srcWin  = *(VO_RECTANGLE *)&cmd->srcWin;
	osdPlane->OSD_canvas.dispWin = *(VO_RECTANGLE *)&cmd->dispWin;

	if (cmd->go)
		GDMA_UpdateGraphicwindow (1, cmd->plane);
#endif
	return 0;
}
int GDMA_CreateGraphicWindow (VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN *cmd)
{
	gdma_dev   *gdma     = &gdma_devices[0];
	GDMA_PLANE *osdPlane = &gdma->osdPlane[cmd->plane];
	GDMA_WIN *win , *curWin, *preWin = 0;
	int i;

	if (osdPlane->OSD_ctrl.dispOn)
		return -EFAULT;

	if (osdPlane->numOSDwins >= GDMA_MAX_NUM_OSD_WIN)
		return -EFAULT;

	for (win = osdPlane->OSDwin;; win++)
		if (!win->ctrl.occupied)
			break;

	win->ctrl.occupied  = 1;
	win->ctrl.previd    =
		win->ctrl.nextid    = 0xFF;
	win->attr.alphaEn   = (win->attr.alpha = cmd->alpha) >  0 ? 1 : 0;
	win->colorKey.keyEn = (cmd->colorKey != -1);
	win->colorKey.key   = cmd->colorKey;
	win->attr.type      = cmd->colorFmt & 0x1f;
	win->attr.littleEndian = cmd->colorFmt >> 5;
	win->attr.compress = (cmd->compressed > 0 ? 1 : 0);
	win->attr.rgbOrder  = cmd->rgbOrder;
	win->winXY.x        = cmd->winPos.x;
	win->winXY.y        = cmd->winPos.y;
	win->winWH.width    = cmd->winPos.width;
	win->winWH.height   = cmd->winPos.height;

	for (i = 0, curWin = &osdPlane->OSDwin[osdPlane->OSD_topid]; i < osdPlane->numOSDwins; i++) {
		if (gdma->ctrl.enableVFlip ? win->winXY.y >= curWin->winXY.y : win->winXY.y < curWin->winXY.y)
			break;
		else
			preWin = curWin;
		curWin = &osdPlane->OSDwin[preWin->ctrl.nextid];
	}
	if (preWin) {
		win->ctrl.nextid = preWin->ctrl.nextid;
		if ((win->ctrl.nextid) != 0xFF)
			osdPlane->OSDwin[win->ctrl.nextid].ctrl.previd = win->ctrl.id;
		win->ctrl.previd    = preWin->ctrl.id;
		preWin->ctrl.nextid = win->ctrl.id;
	} else {
		if (osdPlane->numOSDwins) {
			win->ctrl.nextid     = osdPlane->OSD_topid;
			osdPlane->OSDwin[osdPlane->OSD_topid].ctrl.previd = win->ctrl.id;
		}
		osdPlane->OSD_topid = win->ctrl.id;
	}

	osdPlane->numOSDwins++;

	return win->ctrl.id;
}

int GDMA_DrawGraphicWindow (VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN *cmd)
{
	gdma_dev   *gdma     = &gdma_devices[0];
	GDMA_PLANE *osdPlane = &gdma->osdPlane[cmd->plane];
	GDMA_WIN *win, *thisWin;
	int i;
	DBG_PRINT(KERN_EMERG"GDMA: GDMA_DRAW_GRPAHIC_WINDOW, plane %d, winID %d\n", cmd->plane, cmd->winID);
	DBG_PRINT(KERN_EMERG"GDMA: addr 0x%x, p %d, x %d, y %d\n", (unsigned int)cmd->pImage[0], cmd->imgPitch[0], cmd->startX[0], cmd->startY[0]);
	if (osdPlane->OSD_ctrl.wn >= GDMA_MAX_NUM_OSD_WIN)
		return -EFAULT;

	thisWin = &osdPlane->OSDwin[cmd->winID];
	if (cmd->winID >= GDMA_MAX_NUM_OSD_WIN || !(thisWin->ctrl.occupied))
		return -EFAULT;


	/* check if the OSD window to draw horizontally overlaps any
	existing OSD window on screen */

	for (i = 0, win = &osdPlane->OSDwin[osdPlane->OSD_topid]; i < osdPlane->numOSDwins; i++) {
		if (win->ctrl.drawn
			&& thisWin->winXY.y + thisWin->winWH.height > win->winXY.y
			&& thisWin->winXY.y < win->winXY.y + win->winWH.height)
			return -EFAULT;
	}

	thisWin->pitch = cmd->imgPitch[0];

	if (thisWin->attr.type < 3)
		thisWin->CLUT_addr = virt_to_phys(gdma->OSD_CLUT[cmd->paletteIndex]);

	thisWin->attr.compress = cmd->compressed;
	thisWin->objOffset.objXoffset = cmd->startX[0];
	/*thisWin->objOffset.objYoffset = gdma->ctrl.enableVFlip ? 0 : cmd->startY[0];*/
	thisWin->objOffset.objYoffset = cmd->startY[0];

	for (i = 0; i < 2; i++) {
		thisWin->srcPitch[i] = cmd->imgPitch[i];
		thisWin->srcImg[i] = cmd->pImage[i];
	}

	/* mapping to hardware's location */
	{
		thisWin->top_addr     = cmd->pImage[0];
		thisWin->bot_addr     = cmd->pImage[1];
	}

	thisWin->ctrl.drawn = 1;

	osdPlane->OSD_ctrl.en = 1;
	osdPlane->OSD_ctrl.wn++;

	if (cmd->go)
		GDMA_UpdateGraphicwindow (1, cmd->plane);

	return 0;
}

int GDMA_ModifyGraphicWindow (VIDEO_RPC_VOUT_MODIFY_GRAPHIC_WIN *cmd)
{
	gdma_dev   *gdma     = &gdma_devices[0];
	GDMA_PLANE *osdPlane = &gdma->osdPlane[cmd->plane];
	GDMA_WIN   *win , *curWin, *preWin = 0;
	int i;
	DBG_PRINT(KERN_EMERG"GDMA: VIDEO_RPC_VOUT_MODIFY_GRAPHIC_WIN, plane %d, winID %d, mask 0x%x\n", cmd->plane, cmd->winID, cmd->reqMask);
	DBG_PRINT(KERN_EMERG"GDMA: fmt %d, rgbOrder %d, key %d, alpha %d\n", cmd->colorFmt, cmd->rgbOrder, cmd->colorKey, cmd->alpha);
	DBG_PRINT(KERN_EMERG"GDMA: pos x %d y %d w %d h %d\n", cmd->winPos.x, cmd->winPos.y, cmd->winPos.width, cmd->winPos.height);
	DBG_PRINT(KERN_EMERG"GDMA: addr 0x%x, p %d, x %d, y %d\n", (unsigned int)cmd->pImage[0], cmd->imgPitch[0], cmd->startX[0], cmd->startY[0]);

	win = &osdPlane->OSDwin[cmd->winID];
	if (cmd->winID >= GDMA_MAX_NUM_OSD_WIN || !(win->ctrl.occupied))
		return -EFAULT;

	if (cmd->reqMask & GDMA_MODIFY_POSITION) {
		if (win->ctrl.drawn) {
			for (i = 0, curWin = &osdPlane->OSDwin[osdPlane->OSD_topid]; i < osdPlane->numOSDwins; i++) {
				if (curWin->ctrl.drawn && curWin->ctrl.id != win->ctrl.id
					&& cmd->winPos.y + cmd->winPos.height > curWin->winXY.y
					&& cmd->winPos.y < curWin->winXY.y + curWin->winWH.height)
					return -EFAULT;
				curWin = &osdPlane->OSDwin[curWin->ctrl.nextid];
			}
		}

		/* Delete */
		if (win->ctrl.previd != 0xFF)
			osdPlane->OSDwin[win->ctrl.previd].ctrl.nextid = win->ctrl.nextid;
		else
			osdPlane->OSD_topid = (win->ctrl.nextid != 0xFF) ? win->ctrl.nextid : win->ctrl.id;

		if (win->ctrl.nextid != 0xFF)
			osdPlane->OSDwin[win->ctrl.nextid].ctrl.previd = win->ctrl.previd;
		win->ctrl.previd =
			win->ctrl.nextid = 0xFF;
		osdPlane->numOSDwins--;

		/* Insert */
		for (i = 0, curWin = &osdPlane->OSDwin[osdPlane->OSD_topid]; i < osdPlane->numOSDwins; i++) {
			if (gdma->ctrl.enableVFlip ? win->winXY.y >= curWin->winXY.y : win->winXY.y < curWin->winXY.y)
				break;
			else
				preWin = curWin;
			curWin = &osdPlane->OSDwin[preWin->ctrl.nextid];
		}
		if (preWin) {
			win->ctrl.nextid = preWin->ctrl.nextid;
			if ((win->ctrl.nextid) != 0xFF)
				osdPlane->OSDwin[win->ctrl.nextid].ctrl.previd = win->ctrl.id;
			win->ctrl.previd    = preWin->ctrl.id;
			preWin->ctrl.nextid = win->ctrl.id;
		} else {
			if (osdPlane->numOSDwins) {
				win->ctrl.nextid = osdPlane->OSD_topid;
				osdPlane->OSDwin[osdPlane->OSD_topid].ctrl.previd = win->ctrl.id;
			}
			osdPlane->OSD_topid = win->ctrl.id;
		}

		osdPlane->numOSDwins++;

		win->winXY.x            = cmd->winPos.x;
		win->winXY.y            = cmd->winPos.y;
		win->winWH.width        = cmd->winPos.width;
		win->winWH.height       = cmd->winPos.height;
	}

	if (cmd->reqMask & GDMA_MODIFY_COLORFMT) {
		win->attr.type      = cmd->colorFmt & 0x1f;
		win->attr.littleEndian = cmd->colorFmt >> 5;
		win->attr.rgbOrder  = cmd->rgbOrder;
	}

	if (cmd->reqMask & GDMA_MODIFY_COLORKEY) {
		win->colorKey.keyEn = (cmd->colorKey != -1);
		win->colorKey.key   = cmd->colorKey;
	}

	if (cmd->reqMask & GDMA_MODIFY_ALPHA)
		win->attr.alphaEn   = (win->attr.alpha = cmd->alpha) >  0 ? 1 : 0;

	if (cmd->reqMask & GDMA_MODIFY_STORAGE_TYPE) {
		win->attr.compress = cmd->compressed;
		if (win->attr.type < 3)
			win->CLUT_addr       = virt_to_phys(gdma->OSD_CLUT[cmd->paletteIndex]);
	}

	if (cmd->reqMask & GDMA_MODIFY_SRC_LOCATION) {
		win->objOffset.objXoffset = cmd->startX[0];
		/*win->objOffset.objYoffset = gdma->ctrl.enableVFlip ? 0 : cmd->startY[0];*/
		win->objOffset.objYoffset = cmd->startY[0];
		win->pitch = cmd->imgPitch[0];
		for (i = 0; i < 2; i++) {
			win->srcPitch[i] = cmd->imgPitch[i];
			win->srcImg[i] = cmd->pImage[i];
		}

		/* mapping to hardware's location */
		{
			win->top_addr     = cmd->pImage[0];
			win->bot_addr     = cmd->pImage[1];
		}
	}

	if (cmd->go)
		GDMA_UpdateGraphicwindow (1, cmd->plane);

	return 0;
}

int GDMA_HideGraphicWindow (unsigned char winID, VO_GRAPHIC_PLANE plane, unsigned char go)
{

	gdma_dev   *gdma     = &gdma_devices[0];
	GDMA_PLANE *osdPlane;
	GDMA_WIN *win;

	if((GDMA_DISPLAY_PLANE)plane >= GDMA_PLANE_MAXNUM)
		return -EFAULT;
	osdPlane = &gdma->osdPlane[plane];
	win = &osdPlane->OSDwin[winID];
	if (winID >= GDMA_MAX_NUM_OSD_WIN || !(win->ctrl.occupied))
		return -EFAULT;
	if (win->ctrl.drawn) {
		win->ctrl.drawn = 0;
		osdPlane->OSD_ctrl.wn--;

		if (!osdPlane->OSD_ctrl.wn)
			osdPlane->OSD_ctrl.en = 0;

		if (go)
			GDMA_UpdateGraphicwindow (1, plane);
	}

	return 0;
}

int GDMA_DeleteGraphicWindow (unsigned char winID, VO_GRAPHIC_PLANE plane, unsigned char go)
{
	gdma_dev   *gdma     = &gdma_devices[0];
	GDMA_PLANE *osdPlane = &gdma->osdPlane[plane];
	GDMA_WIN *win;

	win = &osdPlane->OSDwin[winID];
	if (winID >= GDMA_MAX_NUM_OSD_WIN || !(win->ctrl.occupied))
		return -EFAULT;

	if (win->ctrl.drawn)
		GDMA_HideGraphicWindow (winID, plane, 0);
	if (win->ctrl.previd != 0xFF)
		osdPlane->OSDwin[win->ctrl.previd].ctrl.nextid = win->ctrl.nextid;
	else
		osdPlane->OSD_topid = (win->ctrl.nextid != 0xFF) ? win->ctrl.nextid : 0;

	if (win->ctrl.nextid != 0xFF)
		osdPlane->OSDwin[win->ctrl.nextid].ctrl.previd = win->ctrl.previd;

	win->ctrl.occupied = 0;
	osdPlane->numOSDwins--;

	if (go)
		GDMA_UpdateGraphicwindow (1, plane);

	return 0;
}

int GDMA_GetOSDPalette (unsigned int index, unsigned int *palette, unsigned int *len)
{
	gdma_dev   *gdma = &gdma_devices[0];
	if (index < GDMA_MAX_NUM_CLUT && len != NULL) {
		memcpy (palette, gdma->OSD_CLUT[index], sizeof(unsigned int) * gdma->OSD_CLUT_LEN[index]);
		*len = gdma->OSD_CLUT_LEN[index];
		return GDMA_SUCCESS;
	}

	return GDMA_FAIL;
}
int GDMA_SetOSDPalette (unsigned int index, unsigned int *palette, unsigned int len)
{
	dma_addr_t addr;
	gdma_dev   *gdma = &gdma_devices[0];
	if (index < GDMA_MAX_NUM_CLUT && len <= 256) {
		memcpy (gdma->OSD_CLUT[index], (void *)(palette), sizeof(unsigned int) * len);
		gdma->OSD_CLUT_LEN[index] = len;
		addr = dma_map_single(gdma->dev, (void *)gdma->OSD_CLUT[index], 256*sizeof(unsigned int), DMA_TO_DEVICE);
		dma_unmap_single(gdma->dev, addr, 256*sizeof(unsigned int), DMA_TO_DEVICE);
		gdma->f_palette_update = TRUE;
		return GDMA_SUCCESS;
	}
	return GDMA_FAIL;
}



int GDMA_ConfigureOSDPalette (VIDEO_RPC_VOUT_CONFIG_OSD_PALETTE *cmd)
{
	gdma_dev   *gdma = &gdma_devices[0];
	if (cmd->paletteIndex < GDMA_MAX_NUM_CLUT)
		memcpy (gdma->OSD_CLUT[cmd->paletteIndex], (void *)(cmd->pPalette | 0xa0000000), sizeof(unsigned int) * 256);
	return 0;
}

int GDMA_DisplayGraphic (VIDEO_RPC_VOUT_DISPLAY_GRAPHIC *cmd)
{
	gdma_dev   *gdma     = &gdma_devices[0];
	GDMA_PLANE *osdPlane = &gdma->osdPlane[cmd->plane];
	int i , id;

	/* Reset */
	osdPlane->OSD_topid   = 0;
	osdPlane->numOSDwins  = 0;
	osdPlane->OSD_ctrl.en = 0;
	osdPlane->OSD_ctrl.wn = 0;
	for (i = 0; i < GDMA_MAX_NUM_OSD_WIN; i++) {
		osdPlane->OSDwin[i].ctrl.id     = i;
		osdPlane->OSDwin[i].ctrl.previd =
			osdPlane->OSDwin[i].ctrl.nextid = 0xff;
	}
	osdPlane->OSD_ctrl.dispOn = 0;


	if (cmd->osdNum) {
		VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN   create_osd;
		VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN     draw_osd;
		VIDEO_RPC_VOUT_DISPLAY_GRAPHIC_WIN *winInfo  = (VIDEO_RPC_VOUT_DISPLAY_GRAPHIC_WIN *)(cmd->pGraphic | 0xa0000000);

		for (i = 0; i < cmd->osdNum; i++, winInfo++) {
			create_osd.plane         = cmd->plane;
			create_osd.winPos.x      = winInfo->x;
			create_osd.winPos.y      = winInfo->y;
			create_osd.winPos.width  = winInfo->width;
			create_osd.winPos.height = winInfo->height;
			create_osd.colorFmt      = winInfo->colorFmt;
			create_osd.rgbOrder      = winInfo->rgbOrder;
			create_osd.colorKey      = winInfo->colorKey;
			create_osd.alpha         = winInfo->alpha;
			create_osd.compressed = winInfo->compressed;
			id = GDMA_CreateGraphicWindow (&create_osd);
			if (id >= 0) {
				draw_osd.plane           = cmd->plane;
				draw_osd.winID           = id;
				draw_osd.paletteIndex    = winInfo->paletteIndex;
				draw_osd.go              = 0;
				draw_osd.compressed      = winInfo->compressed;
				for (i = 0; i < 4; i++) {
					draw_osd.startX[i]     = winInfo->startX[i];
					draw_osd.startY[i]     = winInfo->startY[i];
					draw_osd.imgPitch[i]   = winInfo->imgPitch[i];
					draw_osd.pImage[i]     = winInfo->pImage[i];
				}
				GDMA_DrawGraphicWindow   (&draw_osd);
			}
		}
	}
	osdPlane->OSD_ctrl.dispOn = (cmd->osdNum > 0);

	GDMA_UpdateGraphicwindow (1, cmd->plane);

	return 0;
}


loff_t GDMA_llseek(struct file *filp, loff_t off, int whence)
{
	return -EINVAL;
}
ssize_t GDMA_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	return -EFAULT;
}
ssize_t GDMA_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	char str[RTKGDMA_MAX_CMD_LENGTH] = {0};
	int cmd_index = 0;
	char *cmd_pointer = NULL;

	if (buf == NULL) {
	return -EFAULT;
}
	if (count > RTKGDMA_MAX_CMD_LENGTH - 1)
		count = RTKGDMA_MAX_CMD_LENGTH - 1;
	if (copy_from_user(str, buf, count)) {
		printk(KERN_ERR "rtkgdma_debug:%d copy_from_user failed! (buf=%p, count=%d)\n",
					__LINE__, buf, (unsigned int)count);
		return -EFAULT;
	}

	if (count > 0)
		str[count-1] = '\0';

	for (cmd_index = 0; cmd_index < GDMA_DBG_CMD_NUMBER; cmd_index++) {
		if (strncmp(str, rtkgdma_cmd_str[cmd_index], strlen(rtkgdma_cmd_str[cmd_index])) == 0)
			break;
	}

	if (cmd_index < GDMA_DBG_CMD_NUMBER) {
		cmd_pointer = &str[strlen(rtkgdma_cmd_str[cmd_index])];
	}

	rtkgdma_dbg_EXECUTE(cmd_index, &cmd_pointer);

	return count;
}
int GDMA_open(struct inode *inode, struct file *filp)
{
	return 0;
}

int GDMA_release(struct inode *inode, struct file *filp)
{
	return 0;
}

void Graphic_PatternColor(BOOLEAN enable, UINT32 patterncolor)
{
	KADP_HAL_GAL_CTRL_T st;

	st.en = enable;
	st.osdn = 1;
	st.clr = patterncolor;

	//printk(KERN_EMERG"\n  *******G*********** enable = %d ", enable);
	//printk(KERN_EMERG"\n  *******G*********** patterncolor = %x ", patterncolor);

	OSD_Pattern(&st);
	if (enable == 1)
		GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD1, 1);
	else
		GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD1, 0);
}

void Set_GDMA_ConfigOSDxEnable(BOOLEAN enable)
{
	GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD1, enable);
}


#ifdef CONFIG_COMPAT
#if defined(CONFIG_ARM64)
long compat_GDMA_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
#else
int compat_GDMA_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
#endif
{
	return filp->f_op->unlocked_ioctl(filp, cmd,  (unsigned long)compat_ptr(arg));
}

#endif// CONFIG_COMPAT

/* int GDMA_ioctl(struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg) */
int GDMA_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int ret =  -ENOTTY;

	DBG_PRINT(KERN_EMERG"GDMA: GDMA_ioctl, %d\n", _IOC_NR(cmd));
	if (_IOC_TYPE(cmd) != GDMA_IOC_MAGIC || _IOC_NR(cmd) > GDMA_IOC_MAXNR)
		return -ENOTTY;

	switch (cmd) {
	case GDMA_CONFIGURE_GRPAHIC_CANVAS:
		{
			VIDEO_RPC_VOUT_CONFIG_GRAPHIC_CANVAS data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(VIDEO_RPC_VOUT_CONFIG_GRAPHIC_CANVAS))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_CONFIGURE_GRPAHIC_CANVAS);
			} else
				ret = GDMA_ConfigureGraphicCanvas    ((VIDEO_RPC_VOUT_CONFIG_GRAPHIC_CANVAS *)&data);

			break;
		}
	case GDMA_CREATE_GRPAHIC_WINDOW:
		{
			VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_CREATE_GRPAHIC_WINDOW);
			} else
				ret = GDMA_CreateGraphicWindow ((VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN    *)&data);

			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CREATE_GRPAHIC_WINDOW, plane %d, winID %d\n", data.plane, ret);
			break;
		}
	case GDMA_DRAW_GRPAHIC_WINDOW:
		{
			VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_DRAW_GRPAHIC_WINDOW);
			} else
				ret = GDMA_DrawGraphicWindow   ((VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN      *)&data);
			break;
		}
	case GDMA_MODIFY_GRPAHIC_WINDOW:
		{
			VIDEO_RPC_VOUT_MODIFY_GRAPHIC_WIN data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(VIDEO_RPC_VOUT_MODIFY_GRAPHIC_WIN))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_MODIFY_GRPAHIC_WINDOW);
			} else
				ret = GDMA_ModifyGraphicWindow ((VIDEO_RPC_VOUT_MODIFY_GRAPHIC_WIN    *)&data);
			break;
		}
	case GDMA_HIDE_GRPAHIC_WINDOW:
		{
			VIDEO_RPC_VOUT_HIDE_GRAPHIC_WIN data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(VIDEO_RPC_VOUT_HIDE_GRAPHIC_WIN))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_HIDE_GRPAHIC_WINDOW);
			} else
				ret = GDMA_HideGraphicWindow  (data.winID, data.plane, data.go);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_HIDE_GRPAHIC_WINDOW, plane %d, winID %d\n", data.plane, data.winID);
			break;
		}
	case GDMA_DELETE_GRPAHIC_WINDOW:
		{
			VIDEO_RPC_VOUT_DELETE_GRAPHIC_WIN data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(VIDEO_RPC_VOUT_DELETE_GRAPHIC_WIN))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_DELETE_GRPAHIC_WINDOW);
			} else
				ret = GDMA_DeleteGraphicWindow (data.winID, data.plane, data.go);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_DELETE_GRPAHIC_WINDOW, plane %d, winID %d\n", data.plane, data.winID);
			break;
		}
	case GDMA_CONFIGURE_OSD_PALETTE:
		{
			VIDEO_RPC_VOUT_CONFIG_OSD_PALETTE data;
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIGURE_OSD_PALETTE\n");
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(VIDEO_RPC_VOUT_CONFIG_OSD_PALETTE))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_CONFIGURE_OSD_PALETTE);
			} else
				ret = GDMA_ConfigureOSDPalette ((VIDEO_RPC_VOUT_CONFIG_OSD_PALETTE    *)&data);
			break;
		}
	case GDMA_DISPLAY_GRPAHIC:
		{
			VIDEO_RPC_VOUT_DISPLAY_GRAPHIC data;
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_DISPLAY_GRPAHIC\n");
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(VIDEO_RPC_VOUT_DISPLAY_GRAPHIC))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_DISPLAY_GRPAHIC);
			} else
				ret = GDMA_DisplayGraphic      ((VIDEO_RPC_VOUT_DISPLAY_GRAPHIC       *)&data);
			break;
		}
	case GDMA_QUERY_STATUS:
		ret = GDMA_OSD_INTST_get_osd1_vact_end(rtd_inl(GDMA_OSD_INTST_reg));


	/* below for 3D Grpahic */
	case GDMA_PLANE_CONFIG_DISPLAY_WIN:
		{
			GDMA_CONFIG_DISP_WIN data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(GDMA_CONFIG_DISP_WIN))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_PLANE_CONFIG_DISPLAY_WIN);
			} else
				ret = GDMA_ConfigureDisplayWindow ((GDMA_CONFIG_DISP_WIN *)&data);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_PLANE_CONFIG_DISPLAY_WIN plane %d, x %d, y %d w %d h %d\n", data.plane, data.dispWin.x, data.dispWin.y, data.dispWin.width, data.dispWin.height);
			break;
		}

	case GDMA_PLANE_DISPLAY:
		{
			GDMA_DISPLAY data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(GDMA_DISPLAY))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_PLANE_DISPLAY);
			} else
				ret = GDMA_Display      ((GDMA_DISPLAY *)&data);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_PLANE_DISPLAY, plane %d, zb %d\n", data.plane, data.zeroBuffer);
			break;
		}

	case GDMA_OSD1_ON_TOP:
		{
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_OSD1_ON_TOP);
			} else
				ret = GDMA_OSD1OnTop      (data);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_OSD1_ON_TOP %d\n", data);
			break;
		}

	case GDMA_CONFIG_3D:
		{
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_CONFIG_3D);
			} else
				ret = GDMA_Config3D      (data);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_3D, enable %d\n", data);
			break;
		}
	case GDMA_CONFIG_INPUTSRC_4K2K:
		{
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_CONFIG_INPUTSRC_4K2K);
			} else
				ret = GDMA_ConfigInputSrc_4k2k      (data);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_SRC_4K2K, enable %d\n", data);
			break;
		}

	case GDMA_CONFIG_3D_UI:
		{
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_3D_UI failed !!\n");
			} else
				ret = GDMA_Config3dUi(data);
			break;
		}

	case GDMA_CONFIG_BOX_SRC_SIZE:
		{
			int data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(int))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_BOX_SRC_SIZE failed !!\n");
			} else
				ret = GDMA_ConfigBoxSrcSize(data);
			break;
		}
	case GDMA_CONFIG_BOX_DST_SIZE:
		{
			int data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(int))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_BOX_DST_SIZE failed !!\n");
			} else
				ret = GDMA_ConfigBoxDstSize(data);
			break;
		}
	case GDMA_CONFIG_ANDROID_LAYERS:
		{
			GRAPHIC_LAYERS_OBJECT data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(GRAPHIC_LAYERS_OBJECT))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_ANDROID_LAYERS failed !!\n");
			} else
				ret = GDMA_ReceiveGraphicLayers(&data);
			break;
		}
//RTK mark for netfix
	case GDMA_CONFIG_OSD1_MIXER_ENABLE:
		{
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_CONFIG_OSD_ENABLE);
			} else
				ret = GDMA_ConfigOSDxMixerEnableNoDelay(GDMA_PLANE_OSD1,data);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_SRC_4K2K, enable %d\n", data);
			break;
		}
	case GDMA_CONFIG_OSD3_MIXER_ENABLE:
		{
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_CONFIG_OSD_ENABLE);
			} else
				ret = GDMA_ConfigOSDxMixerEnableNoDelay(GDMA_PLANE_OSD3,data);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_SRC_4K2K, enable %d\n", data);
			break;
		}
	case GDMA_CONFIG_OSD1OSD3_MIXER_ORDER:
		{
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_CONFIG_OSD_ENABLE);
			} else
				ret = GDMA_ConfigOSD1OSD3MixerOrder(data);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_SRC_4K2K, enable %d\n", data);
			break;
		}
		case GDMA_CONFIG_OSD_ENABLE:
		{
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_CONFIG_OSD_ENABLE);
			} else
				ret = GDMA_ConfigOSDEnable      (data);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_SRC_4K2K, enable %d\n", data);
			break;
		}
	case GDMA_CONFIG_OSD1_ENABLE:
		{
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_OSD1_ENABLE failed !!\n");
			} else
				ret = GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD1, data);

			break;
		}
	case GDMA_CONFIG_OSD2_ENABLE:
		{
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_OSD2_ENABLE failed !!\n");
			} else
#if defined(CONFIG_ARCH_RTK284X)
				ret = GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD3, data);
#else
				//ret = GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD2, data);
#endif
			break;
		}
	case GDMA_CONFIG_OSD4_ENABLE:
		{
			ret = -EFAULT;
			break;
		}

	case GDMA_LOCK_VSYNC_SEM:
		{
			/* fox modify use cookie to sync GDMA */
			GDMA_Lock_Vsync_Sem();
			break;
		}
	case GDMA_READ_Millet3:
		{
			ret = -EFAULT;
			break;
		}
	case GDMA_READ_PANEL_RES:
		{
			VO_RECTANGLE res;
			getDispSize(&res);
			if(abs(1366 - res.width) <= 10)
				res.width = 1366;
			else if(abs(1280 - res.width) <= 10)
				res.width = 1280;
			if(abs(768 - res.height) <= 10)
				res.height = 768;
			else if(abs(720 - res.height) <= 10)
				res.height = 720;
			if (copy_to_user((void __user *)arg, &res, sizeof(VO_RECTANGLE))) {
				pr_debug(" GDMA_READ_PANEL_RES ERROR *******\n");
				ret = -EFAULT;
			}
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_READ_PANEL_RES, res.width=%d, res.height=%d\n", res.width, res.height);
			break;
		}
	case GDMA_READ_Millet3_INPUTSRC_4K2K:
		{
			ret = -EFAULT;
			break;
		}
	case GDMA_READ_PANEL_SETTING:
		{
			int  type;
			type = GDMA_GetPanelPixelMode();
			if (copy_to_user((void __user *)arg, &type, sizeof(type))) {
				pr_debug(" GDMA_READ_PANEL_SETTING ERROR *******\n");
				ret = -EFAULT;
			}
			break;
		}
	case GDMA_DEBUG_CONTROL:
		{
			KADP_HAL_GAL_CTRL_T data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KADP_HAL_GAL_CTRL_T)))
				ret = -EFAULT;
			else
				ret = GDMA_Debug((KADP_HAL_GAL_CTRL_T *)&data);

			if(data.type == GDMA_DBG_CMD_OSD_GET_INFO){
				if(copy_to_user((void __user *)arg, &data, sizeof(KADP_HAL_GAL_CTRL_T)))
				ret = -EFAULT;
			}
			break;
		}
	case GDMA_CONFIG_3D_OFFSET:
		{
			CONFIG_3D_OFFSET_STRUCT data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(CONFIG_3D_OFFSET_STRUCT))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_CONFIG_3D_OFFSET);
			} else
				ret = GDMA_Config3DOffset ((CONFIG_3D_OFFSET_STRUCT *)&data);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_3D_OFFSET, plane %d, dir %d, offset %d\n", data.plane, data.closeToViewer, data.offset);
			break;
		}

	case GDMA_CONFIG_BLENDING:
		{
			CONFIG_BLENDING_STRUCT data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(CONFIG_BLENDING_STRUCT))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_CONFIG_BLENDING);
			} else
				ret = GDMA_ConfigBlending ((CONFIG_BLENDING_STRUCT *)&data);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_BLENDING, %d, %d, %d\n", data.blendingOSD1En, data.blendingOSD2En, data.blendingCursorEn);
			break;
		}

	case GDMA_CONFIG_VFLIP:
		{
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_CONFIG_VFLIP);
			} else
				ret = GDMA_ConfigVFlip(data);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_VFLIP, enable %d\n", data);
			break;
		}

	case GDMA_CONFIG_NONBLOCKING:
		{
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT;
				DBG_PRINT(KERN_EMERG"GDMA: ioctl code = %d failed!!!!!!!!!!!!!!!1\n", GDMA_CONFIG_NONBLOCKING);
			} else
				ret = GDMA_ConfigNonBlocking(data);
			DBG_PRINT(KERN_EMERG"GDMA: ioctl GDMA_CONFIG_NONBLOCKING, enable %d\n", data);
			break;
		}

	case GDMA_CONFIG_OSDCOMP_WRITEBACK_OFFLINE:
		{
			ret = -EFAULT;
			break;
		}

	case GDMA_CONFIG_OSDCOMP_WRITEBACK_ONLINE:
		{
			ret = -EFAULT;
			break;
		}

	case GDMA_CONFIG_QUEUEFLUSH:
		{
			GDMA_QueueFlush();
			break;
		}

	case GDMA_CONFIG_OSDSPLIT:
		{
			ret = -EFAULT;
			break;
		}

	case GDMA_CONFIG_OSD_SMOOTH_TOGGLE:
		{

			ret = -EFAULT;
			GDMA_OSDSmoothToggle();
			break;
		}

	case GDMA_CONFIG_OSD_SHIFT: //for OSD shift
		{
			if (copy_from_user((void *)&g_osdshift_ctrl, (const void __user *)arg, sizeof(CONFIG_OSDSHIFT_STRUCT))) {
				ret = -EFAULT;
				memset(&g_osdshift_ctrl, 0x00, sizeof(CONFIG_OSDSHIFT_STRUCT));
				DBG_PRINT(KERN_EMERG"GDMA: ioctl CONFIG_OSDSHIFT_STRUCT failed !!\n");
				break;
			}
			if(osd_shift_proc() == false) {
				ret = -EFAULT;
			}
			break;
		}
	case GDMA_GET_OSD_STATUS:
		{
			unsigned int st = 0;
#if defined(CONFIG_ARCH_RTK284X)
			int sta_x,sta_y,end_x,end_y;
#endif
			st |= GDMA_OSD1_CTRL_get_osd1_en(rtd_inl(GDMA_OSD1_CTRL_reg))?1:0;
			st |= GDMA_OSD2_CTRL_get_osd2_en(rtd_inl(GDMA_OSD2_CTRL_reg))?2:0;
			st |= GDMA_OSD3_CTRL_get_osd3_en(rtd_inl(GDMA_OSD3_CTRL_reg))?4:0;
#if defined(CONFIG_ARCH_RTK284X)
			if (GDMA_OSD1_CTRL_get_osd1_en(rtd_inl(GDMA_OSD1_CTRL_reg)) == 1)
                                st |= (1<<8);

			sta_x = OSDOVL_measure_osd1_sta_get_x(rtd_inl(OSDOVL_measure_osd1_sta_reg));
			sta_y = OSDOVL_measure_osd1_sta_get_y(rtd_inl(OSDOVL_measure_osd1_sta_reg));
			end_x = OSDOVL_measure_osd1_end_get_x(rtd_inl(OSDOVL_measure_osd1_end_reg));
			end_y = OSDOVL_measure_osd1_end_get_y(rtd_inl(OSDOVL_measure_osd1_end_reg));
 
			if((end_x - sta_x <= 100) && (end_y - sta_y <= 100))
                               st &= !(1<<8);
#endif
			if (copy_to_user((void __user *)arg, &st, sizeof(st))) {
				ret = -EFAULT;
			}
			ret = 0;
			break;
		}
	default:
		pr_debug(KERN_EMERG"GDMA: ioctl code = %d is invalid!!!!!!!!!!!!!!!1\n", cmd);
		break;
	}

	return ret;
}


static void GDMA_setup_cdev(gdma_dev *dev, int index)
{
	int err, devno = MKDEV(gdma_major, gdma_minor + index);

	cdev_init(&dev->cdev, &gdma_fops);
	dev->cdev.owner = THIS_MODULE;
	dev->cdev.ops   = &gdma_fops;
	err = cdev_add (&dev->cdev, devno, 1);

	if (err)
		DBG_PRINT(KERN_EMERG "Error %d adding se%d", err, index);

	device_create(gdma_class, NULL, MKDEV(gdma_major, index), NULL, "gdma%d", index);
}

#if defined(CONFIG_ARM64)
static char *GDMA_devnode(struct device *dev, umode_t *mode) {
#else
static char *GDMA_devnode(struct device *dev, mode_t *mode) {
#endif
	return NULL;
}
/*
long long GetSystemClock(void)
{
	unsigned int hi, low;

	do {
		hi  = rtd_inl(MIS_SCPU_CLK90K_HI_reg);
		low = rtd_inl(MIS_SCPU_CLK90K_LO_reg);
	} while (hi != rtd_inl(MIS_SCPU_CLK90K_HI_reg));

	return ((long long)hi << 32) | low;
}
*/

/*
*   sel: 0: return BusH clock
*        1: return Ddomain clock
*/
int GDMA_BusH_DClk_info(int sel)
{
	unsigned int ret_clk = 27;
	unsigned int value_m = 0, value_n = 0, value_o = 0, value_f = 0;
	unsigned int tmp = 0;

	if (sel == 0) {
		if ((rtd_inl(STB_ST_BUSCLK_reg) & STB_ST_BUSCLK_bus_clksel_mask) == 0) {

			tmp = rtd_inl(PLL_REG_SYS_PLL_BUSH2_reg);
			value_f = ((tmp & PLL_REG_SYS_PLL_BUSH2_pllbus_fcode_h_mask) >> 16);
			value_n = ((tmp & PLL_REG_SYS_PLL_BUSH2_pllbus_ncode_h_mask) >> 8);
			ret_clk = 27 * (value_n + 3) + ((27 * value_f) >> 11); /*  27*(NCODE + 3 + FCODE/2048) */
		} else {
			ret_clk = 27;
		}
	} else if (sel == 1) {
		/*
		XTAL_FREQ * (M_CODE+3+(F_CODE/2048))  / ((N_CODE+2) * div)
		XTAL_FREQ: 27MHz
		M_CODE: 0xb800_06c0[27:20],
		N_CODE: 0xb800_06c0[14:12],
		F_CODE: 0xb800_06A0[26:16],
		div: 0xb800_06c8[13:12], DPLL Output Divder,
		*/
		tmp = rtd_inl(PLL27X_REG_SYS_PLL_DISP1_reg);
		value_m = ((tmp & PLL27X_REG_SYS_PLL_DISP1_dpll_m_mask) >> PLL27X_REG_SYS_PLL_DISP1_dpll_m_shift);
		value_n = ((tmp & PLL27X_REG_SYS_PLL_DISP1_dpll_n_mask) >> PLL27X_REG_SYS_PLL_DISP1_dpll_n_shift);
		tmp = rtd_inl(PLL27X_REG_PLL_SSC0_reg);
		value_f = ((tmp & PLL27X_REG_PLL_SSC0_fcode_t_ssc_mask) >> PLL27X_REG_PLL_SSC0_fcode_t_ssc_shift);

		tmp = rtd_inl(PLL27X_REG_SYS_PLL_DISP3_reg);
		value_o = ((tmp & PLL27X_REG_SYS_PLL_DISP3_dpll_o_mask) >> PLL27X_REG_SYS_PLL_DISP3_dpll_o_shift);

		ret_clk = (((value_m+3+(value_f/2048))*2700) / ((value_n+2)*(1<<value_o)));
		ret_clk /= 100;
	}

	return ret_clk;
}


irqreturn_t GDMA_irq_handler(int irq, void *dev_id)
{
	/*volatile decomp_inten_RBUS decomp_inten_reg;*/
	volatile dma_intst_RBUS dma_intst_reg;
	gdma_dev *gdma = dev_id;
	volatile int osd1_vend, osd1_vend_3D, osd_vend;/* , i; */
	volatile int osd1_finish;
	volatile int osd1_sync;
	volatile ppoverlay_lflag_gen_RBUS lflag_gen_reg;
	/*int lineCnt = (*(volatile u32 *)GET_MAPPED_RBUS_ADDR(0xB8028248)) & 0xfff; */
	volatile unsigned int osd_intst_reg = rtd_inl(GDMA_OSD_INTST_reg);

#if defined(_TEST_CODE_GDMA_) || defined(_TEST_CODE_OSDCOMP_)
#if !defined(CONFIG_ARM64)
	flush_cache_all();
#endif
#endif
	osd1_finish = GDMA_OSD_INTST_get_osd1_fin(osd_intst_reg);
	osd1_sync = GDMA_OSD_INTST_get_osd1_vsync(osd_intst_reg);

#ifndef USING_GDMA_VSYNC
	osd1_vend     = GDMA_OSD_INTST_get_osd1_vact_end(osd_intst_reg);
#else
	osd1_vend     = GDMA_OSD_INTST_get_osd1_vsync(osd_intst_reg);
#endif
	osd1_vend_3D  = GDMA_OSD_INTST_3D_get_osd1_vact_end(rtd_inl(GDMA_OSD_INTST_3D_reg));
	osd_vend      = gdma->ctrl.enable3D ? (osd1_vend_3D || (osd1_vend && gdma->ctrl.forceUpdate)) : osd1_vend;

#ifdef USING_GDMA_VSYNC
	if (GDMA_CTRL_get_osd1_prog_done(rtd_inl(GDMA_CTRL_reg)) == 0)
#endif
	{
		if (osd_vend) {
#ifdef TRIPLE_BUFFER_SEMAPHORE
			int lineCnt = rtd_inl(PPOVERLAY_new_meas0_linecnt_real_reg) & 0x1fff;
			if (lineCnt < (rtd_inl(PPOVERLAY_DV_DEN_Start_End_reg) & 0x1fff))
				;/*DBG_PRINT(KERN_EMERG"gdma:vend isr @ %d\n", lineCnt);*/ /*  check interrupt timing in front-porch time? */
#endif

			if (gdma->ctrl.updateOSD1Offset) {
				rtd_outl(PPOVERLAY_OSD1_3D_OFFSET_reg, *(volatile u32 *)&gdma->osd3Doffset[0]);
				gdma->ctrl.updateOSD1Offset = 0;
				*(volatile u32 *)&lflag_gen_reg = rtd_inl(PPOVERLAY_LFLAG_GEN_reg);
				if (gdma->osd3Doffset[0].left_offset == 0 && gdma->osd3Doffset[0].right_offset == 0) {
					lflag_gen_reg.gdma_osd_line_alt = 0;
					rtd_outl(PPOVERLAY_LFLAG_GEN_reg, lflag_gen_reg.regValue);
				} else {
					lflag_gen_reg.gdma_osd_line_alt = 1;
					rtd_outl(PPOVERLAY_LFLAG_GEN_reg, lflag_gen_reg.regValue);
				}
			}
			if (gdma->ctrl.updateOSD2Offset) {
				rtd_outl(PPOVERLAY_OSD2_3D_OFFSET_reg, *(volatile u32 *)&gdma->osd3Doffset[1]);
				gdma->ctrl.updateOSD2Offset = 0;
				*(volatile u32 *)&lflag_gen_reg = rtd_inl(PPOVERLAY_LFLAG_GEN_reg);
				if (gdma->osd3Doffset[1].left_offset == 0 && gdma->osd3Doffset[1].right_offset == 0) {
					lflag_gen_reg.gdma_osd_line_alt = 0;
					rtd_outl(PPOVERLAY_LFLAG_GEN_reg, lflag_gen_reg.regValue);
				} else {
					lflag_gen_reg.gdma_osd_line_alt = 1;
					rtd_outl(PPOVERLAY_LFLAG_GEN_reg, lflag_gen_reg.regValue);
				}
			}
			if (gdma->ctrl.updateOSD3Offset) {
				rtd_outl(PPOVERLAY_OSD3_3D_OFFSET_reg, *(volatile u32 *)&gdma->osd3Doffset[2]);
				gdma->ctrl.updateOSD3Offset = 0;
				*(volatile u32 *)&lflag_gen_reg = rtd_inl(PPOVERLAY_LFLAG_GEN_reg);
				if (gdma->osd3Doffset[2].left_offset == 0 && gdma->osd3Doffset[2].right_offset == 0) {
					lflag_gen_reg.gdma_osd_line_alt = 0;
					rtd_outl(PPOVERLAY_LFLAG_GEN_reg, lflag_gen_reg.regValue);
				} else {
					lflag_gen_reg.gdma_osd_line_alt = 1;
					rtd_outl(PPOVERLAY_LFLAG_GEN_reg, lflag_gen_reg.regValue);
				}
			}

#if 0
			decomp_inten_reg.regValue = rtd_inl(GDMA_DECOMP_INTEN_reg);
			decomp_inten_reg.head_error_clr = 1;
			decomp_inten_reg.pix_fifo_underflow_clr = 1;
			rtd_outl(GDMA_DECOMP_INTEN_reg, decomp_inten_reg.regValue);
			decomp_inten_reg.head_error_clr = 0;
			decomp_inten_reg.pix_fifo_underflow_clr = 0;
			rtd_outl(GDMA_DECOMP_INTEN_reg, decomp_inten_reg.regValue);
#endif
			//GDMA_Update (gdma, 1);	// move to main process

			if (osd1_vend_3D)
				rtd_outl(GDMA_OSD_INTST_3D_reg, GDMA_OSD_INTST_3D_write_data(0) | GDMA_OSD_INTST_3D_osd1_vact_end(1));
			else
#ifndef USING_GDMA_VSYNC
				rtd_outl(GDMA_OSD_INTST_reg, GDMA_OSD_INTST_write_data(0) | GDMA_OSD_INTST_osd1_vact_end(1));
#else
				rtd_outl(GDMA_OSD_INTST_reg, GDMA_OSD_INTST_write_data(0) | GDMA_OSD_INTST_osd1_vsync(1));
#endif

			gdma->ctrl.forceUpdate = 0;
		}
#ifdef TRIPLE_BUFFER_SEMAPHORE
		/*else if (osd1_sync) {*/
		if (osd1_sync) {
			if (gSemaphore[GDMA_PLANE_OSD1] > 0 && gdma->pendingRPC[GDMA_PLANE_OSD1] && (GDMA_CTRL_get_osd1_prog_done(rtd_inl(GDMA_CTRL_reg)) == 0)) {
				gdma->pendingRPC[GDMA_PLANE_OSD1] = 0;
				up(&gdma->updateSem[GDMA_PLANE_OSD1]);
			}
			if (gSemaphore[GDMA_PLANE_OSD2] > 0 && gdma->pendingRPC[GDMA_PLANE_OSD2] && (GDMA_CTRL_get_osd2_prog_done(rtd_inl(GDMA_CTRL_reg)) == 0)) {
				gdma->pendingRPC[GDMA_PLANE_OSD2] = 0;
				up(&gdma->updateSem[GDMA_PLANE_OSD2]);
			}
			if (gSemaphore[GDMA_PLANE_OSD3] > 0 && gdma->pendingRPC[GDMA_PLANE_OSD3] && (GDMA_CTRL_get_osd3_prog_done(rtd_inl(GDMA_CTRL_reg)) == 0)) {
				gdma->pendingRPC[GDMA_PLANE_OSD3] = 0;
				up(&gdma->updateSem[GDMA_PLANE_OSD3]);
			}

			rtd_outl(GDMA_OSD_INTST_reg, GDMA_OSD_INTST_write_data(0) | GDMA_OSD_INTST_osd1_vsync(1));
		}
#endif
		else {
			if (osd1_vend) {
#ifndef USING_GDMA_VSYNC
				rtd_outl(GDMA_OSD_INTST_reg, GDMA_OSD_INTST_write_data(0) | GDMA_OSD_INTST_osd1_vact_end(1));
#else
				rtd_outl(GDMA_OSD_INTST_reg, GDMA_OSD_INTST_write_data(0) | GDMA_OSD_INTST_osd1_vsync(1));
#endif
				gdma->ctrl.forceUpdate = 1;
			}
		}
	}
#ifdef USING_GDMA_VSYNC
	else {
		pr_debug(KERN_EMERG"OSD1 not prog_done\n");
	}
#endif

	if (osd_vend) {
		/* if (gdma->vsync_enable) */
		{
			queue_work(psOsdSyncWorkQueue, &sOsdSyncWork);
		}
		if (gdma->GDMA_CallBack)
			gdma->GDMA_CallBack (dev_id, osd1_vend_3D);
	}

	if (!(osd1_vend || osd1_vend_3D || osd1_finish || osd1_sync)) {
		return IRQ_NONE;
	}
	if (OSD_SR_1_UDFLOW_get_osd_sr_in_udflow(rtd_inl(OSD_SR_1_UDFLOW_reg))) {
		pr_debug(KERN_EMERG"GDMA: osd1_sr underflow, source GDMA_osd%d ,busH=%d Mhz, dclk=%d Mhz\n", GDMA_line_buffer_end_get_osdsr1_switch_to(rtd_inl(GDMA_line_buffer_end_reg)), GDMA_BusH_DClk_info(0), GDMA_BusH_DClk_info(1));
		rtd_outl(OSD_SR_1_UDFLOW_reg, OSD_SR_1_UDFLOW_osd_sr_in_udflow(1));
	}

	if (OSD_SR_2_UDFLOW_get_osd_sr_in_udflow(rtd_inl(OSD_SR_2_UDFLOW_reg))) {
		pr_debug(KERN_EMERG"GDMA: osd2_sr underflow, source GDMA_osd%d ,busH=%d Mhz, dclk=%d Mhz\n", GDMA_line_buffer_end_get_osdsr2_switch_to(rtd_inl(GDMA_line_buffer_end_reg)), GDMA_BusH_DClk_info(0), GDMA_BusH_DClk_info(1));
		rtd_outl(OSD_SR_2_UDFLOW_reg, OSD_SR_2_UDFLOW_osd_sr_in_udflow(1));
	}

	dma_intst_reg.regValue = rtd_inl(GDMA_DMA_INTST_reg);
	if (dma_intst_reg.osd1_acc_sync)
		pr_debug(KERN_EMERG"GDMA: osd1 accident sync\n");

	if (dma_intst_reg.osd2_acc_sync)
		pr_debug(KERN_EMERG"GDMA: osd2 accident sync\n");

	if (dma_intst_reg.osd3_acc_sync)
		pr_debug(KERN_EMERG"GDMA: osd3 accident sync\n");

	dma_intst_reg.write_data = 0;
	rtd_outl(GDMA_DMA_INTST_reg, dma_intst_reg.regValue);
	/*  conflict condition check */
	/*if (rtd_inl(GDMA_blend_setting_conflict_reg))*/
	/*	Warning("GDMA: Conflict condition happened, [0x%x] %x", GDMA_blend_setting_conflict_reg, rtd_inl(GDMA_blend_setting_conflict_reg));*/

#if 0   /*  frame-rate calculation by Vsync */
	static unsigned int gdmaINT_cnt;
	static unsigned int spentTime, sta;
	if (gdmaINT_cnt == 0 && sta == 0) {
		sta = rtd_inl(SCPU_CLK90K_LO_reg);
		/* Warning("[GDMA] Starting counting for FPS, sta=%d \n", sta); */
	} else {
		if (rtd_inl(SCPU_CLK90K_LO_reg) > sta) {
			spentTime = (rtd_inl(SCPU_CLK90K_LO_reg) - sta);
			gdmaINT_cnt++;
		} else if (gdmaINT_cnt < 1000) {
			if (gdmaINT_cnt) {
				Warning(KERN_EMERG"[GDMA]FPS=%d, spend time %d, income time %d \n", (gdmaINT_cnt / (spentTime/90000)), spentTime, gdmaINT_cnt);
			}
		}

		if (gdmaINT_cnt >= 1000) {
			Warning(KERN_EMERG"[GDMA]FPS=%d, spend time %d, income time %d \n", (gdmaINT_cnt / (spentTime/90000)), spentTime, gdmaINT_cnt);
			sta = spentTime = gdmaINT_cnt = 0;
		}

		/* Warning("[GDMA] Counting , gdmaINT_cnt=%d \n", gdmaINT_cnt); */
	}
#endif
	return IRQ_HANDLED;
}

void GDMA_ISR_export(void)
{
	return;
}

void GDMA_cleanup_module(void)
{
	int i;
	dev_t devno = MKDEV(gdma_major, gdma_minor);

	DBG_PRINT(KERN_EMERG "gdma clean module gdma_major = %d\n", gdma_major);

	GDMA_uninit_debug_proc();

	if (gdma_devices) {
		for (i = 0; i < gdma_nr_devs; i++) {
			cdev_del      (&gdma_devices[i].cdev);
			device_destroy(gdma_class, MKDEV(gdma_major, i));
		}
		kfree(gdma_devices);
	}

	class_destroy(gdma_class);
	/* cleanup_module is never called if registering failed */
	unregister_chrdev_region(devno, gdma_nr_devs);

	rtd_printk(KERN_INFO,TAG_NAME,"%s finish.\n", __FUNCTION__);
}



int GDMA_init_module(void)
{
	int result, i, j, k;
	gdma_dev *gdma = NULL;

	osdovl_mixer_ctrl2_RBUS mixer_ctrl2;
	osdovl_mixer_layer_sel_RBUS mixer_layer_sel_reg;
	ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2;
	sys_reg_sys_dispclksel_RBUS sys_dispclksel_reg;
	dev_t dev = 0;
	ppoverlay_memcdtg_dh_den_start_end_RBUS dtg_dh;
	ppoverlay_memcdtg_dv_den_start_end_RBUS dtg_dv;
	unsigned int onlineProgDone = GDMA_CTRL_write_data(1) | GDMA_CTRL_osd_others_prog_done(1);
#if defined(CONFIG_REALTEK_PCBMGR)
	PANEL_CONFIG_PARAMETER *panel_parameter = (PANEL_CONFIG_PARAMETER *)&platform_info.panel_parameter;
#endif
#ifdef CONFIG_SMP
	struct cpumask *cpu_mask;
#endif

	rtd_printk(KERN_INFO,TAG_NAME,"%s \n", __FUNCTION__);

#if defined(CONFIG_REALTEK_PCBMGR)
	pr_debug("[GDMA]panel_parameter->iCONFIG_PANEL_TYPE=%d  ******\n\n", panel_parameter->iCONFIG_PANEL_TYPE);
	pr_debug("[GDMA]panel_parameter=%s  ******\n\n", panel_parameter->sPanelName);
#endif
	display_timing_ctrl2.regValue = rtd_inl(PPOVERLAY_Display_Timing_CTRL2_reg);
	dtg_dh.regValue = rtd_inl(PPOVERLAY_memcdtg_DH_DEN_Start_End_reg);
	dtg_dv.regValue = rtd_inl(PPOVERLAY_memcdtg_DV_DEN_Start_End_reg);

	/* clock check */
	sys_dispclksel_reg.regValue = rtd_inl(SYS_REG_SYS_DISPCLKSEL_reg);
	if (sys_dispclksel_reg.clken_disp_gdma == 0)
		GDMA_Clk_Select(0, true);

	if (gdma_major) {
		dev    = MKDEV(gdma_major, gdma_minor);
		result = register_chrdev_region(dev, gdma_nr_devs, "gdma");
	} else {
		result     = alloc_chrdev_region(&dev, gdma_minor, gdma_nr_devs, "gdma");
		gdma_major = MAJOR(dev);
	}

	if (result < 0) {
		DBG_PRINT(KERN_EMERG"gdma: can't get major %d\n", gdma_major);
		return result;
	}


	gdma_class = class_create(THIS_MODULE, "gdma");
	if (IS_ERR((gdma_class)))
		return PTR_ERR(gdma_class);

	gdma_class->devnode = GDMA_devnode;

	gdma_devices = kmalloc(gdma_nr_devs * sizeof(gdma_dev), GFP_KERNEL);
	if (!(gdma_devices)) {
		result = -ENOMEM;
		GDMA_cleanup_module();   /* fail */
		return result;
	}

#if defined(CONFIG_ARM64)
	gdma_dev_addr = (unsigned long)virt_to_phys(gdma_devices);

#else
	gdma_dev_addr = (unsigned int)virt_to_phys(gdma_devices);
#endif
#ifdef CONFIG_PM
	gdma_devs = platform_device_register_simple(DRV_NAME, -1, NULL, 0);
	result = platform_driver_register(&gdma_driver);
	if ((result) != 0) {
		DBG_PRINT(KERN_EMERG"Can't register GDMA device driver...\n");
	} else {
		DBG_PRINT(KERN_EMERG"register GDMA device driver...\n");
	}
	//pr_debug("func=%s line=%d dvr_malloc_specific DCU2 gal_std_save_size=%d \n", __FUNCTION__, __LINE__,gal_std_save_size);
	//add by fox for gfx std

#endif
	/*for OSD shift*/
	memset(&g_osdshift_ctrl, 0x00, sizeof(CONFIG_OSDSHIFT_STRUCT));
	/*MAIN is OSD1*/
	g_osdshift_ctrl.plane = VO_GRAPHIC_OSD1;

	memset(gdma_devices, 0, gdma_nr_devs * sizeof(gdma_dev));

	gdma = &gdma_devices[0];
	sema_init(&gdma->sem, 1);
	sema_init(&gdma->sem_receive, 1);
	sema_init(&gdma->sem_gfxreceive, 1);
	for (j = 0; j < GDMA_PLANE_MAXNUM; j++)
		sema_init(&gdma->updateSem[j], 0);

	GDMA_setup_cdev(gdma, 0);
#ifdef CONFIG_PM
	gdma->dev = &(gdma_devs->dev);
	gdma->dev->dma_mask = &gdma->dev->coherent_dma_mask;
	if(dma_set_mask(gdma->dev, DMA_BIT_MASK(32))) {
		pr_debug(KERN_EMERG"[GDMA] DMA not supported\n");
	}
#endif
#if defined(CONFIG_REALTEK_PCBMGR)
	gdma->iCONFIG_PANEL_TYPE = panel_parameter->iCONFIG_PANEL_TYPE;
	gdma->iCONFIG_PANEL_CUSTOM_INDEX = panel_parameter->iCONFIG_PANEL_CUSTOM_INDEX;
	pr_debug("[GDMA]gdma->iCONFIG_PANEL_TYPE=%d\n", gdma->iCONFIG_PANEL_TYPE);
	pr_debug("[GDMA]gdma->iCONFIG_PANEL_CUSTOM_INDEX=%d\n", gdma->iCONFIG_PANEL_CUSTOM_INDEX);
	/*  3d support? PR or SG mode? */
	pr_debug("[GDMA]gdma->i3D_DISPLAY_SUPPORT=%d\n", panel_parameter->i3D_DISPLAY_SUPPORT);
	pr_debug("[GDMA]gdma->i3D_LINE_ALTERNATIVE_SUPPORT=%d\n", panel_parameter->i3D_LINE_ALTERNATIVE_SUPPORT);
	if (panel_parameter->i3D_DISPLAY_SUPPORT)
		gdma->ctrl.enable3D_PR_SGMode = panel_parameter->i3D_LINE_ALTERNATIVE_SUPPORT;
#endif
	gdma->f_inputsrc_4k2k = -1;/* FALSE; */
	/*modify for vsync between hwc and gdma*/
	gdma->vsync_enable = 0;
	gdma->f_palette_update = FALSE;
	sema_init(&gdma->vsync_sem, 0);
	gdma->f_3d_ui = FALSE;


	for (k = 0; k < MAX_OSD_NUM; k++) {
		gdma->osdPlane[k].OSD_canvas.srcWin.x  =
		gdma->osdPlane[k].OSD_canvas.srcWin.y  = 0;
		gdma->osdPlane[k].OSD_canvas.srcWin.width  = 1280;
		gdma->osdPlane[k].OSD_canvas.srcWin.height = 720;

		gdma->osdPlane[k].OSD_canvas.dispWin.width = dtg_dh.memcdtg_dh_den_end-dtg_dh.memcdtg_dh_den_sta;
		gdma->osdPlane[k].OSD_canvas.dispWin.height = dtg_dv.memcdtg_dv_den_end-dtg_dv.memcdtg_dv_den_sta;

		gdma->osdPlane[k].OSD_ctrl.hwTurnOff = 0;

		for (j = 0; j < GDMA_MAX_NUM_OSD_WIN; j++) {
			gdma->osdPlane[k].OSDwin[j].ctrl.id     = j;
			gdma->osdPlane[k].OSDwin[j].ctrl.previd = 0;
			gdma->osdPlane[k].OSDwin[j].ctrl.nextid = 0;
		}
	}

	/* Yvonne_Sirius+ */
	for (k = 0; k < GDMA_PLANE_MAXNUM; k++) {
		gdma->dispWin[k].width = dtg_dh.memcdtg_dh_den_end-dtg_dh.memcdtg_dh_den_sta;
		gdma->dispWin[k].height = dtg_dv.memcdtg_dv_den_end-dtg_dv.memcdtg_dv_den_sta;
	}
	/* Yvonne_Sirius- */

	gdma->GDMA_osd.wi_endian	= 0;/* Yvonne todo */
	/* gdma->GDMA_osd.dvb		= 0; */
	gdma->GDMA_osd.osd		= 1;
	gdma->GDMA_osd.write_data	= 1;
	gdma->GDMA_osd_ctrl.write_data	= 1;
/*
	rtd_printk(KERN_INFO,TAG_NAME,"[GDMA]W[end-sta]=[%d-%d]\n", dtg_dh.mh_den_end, dtg_dh.mh_den_sta);
	rtd_printk(KERN_INFO,TAG_NAME,"[GDMA]H[end-sta]=[%d-%d]\n", dtg_dv.mv_den_end, dtg_dv.mv_den_sta);
*/

	rtd_outl(GDMA_OSD1_reg, *((u32 *)&gdma->GDMA_osd));
	rtd_outl(GDMA_OSD2_reg, *((u32 *)&gdma->GDMA_osd));
	rtd_outl(GDMA_OSD3_reg, *((u32 *)&gdma->GDMA_osd));

	gdma_config_line_buffer();

	/* OSD programming done */
	onlineProgDone |= GDMA_CTRL_osd1_prog_done(1);
	onlineProgDone |= GDMA_CTRL_osd2_prog_done(1);
	onlineProgDone |= GDMA_CTRL_osd3_prog_done(1);
	rtd_outl(GDMA_CTRL_reg, onlineProgDone);

	/* onlineProgDone reset to default */
	onlineProgDone = GDMA_CTRL_write_data(1) | GDMA_CTRL_osd_others_prog_done(1);
#if 0
	/* wait prog done */
	while ((rtd_inl(GDMA_CTRL_reg)&prog_done_mask) != 0) {
		msleep(1);
		to_cnt++;
		if (to_cnt > 40) {
			pr_debug("%s, GDMA HW something wrong. Please check \n", __FUNCTION__);
			break;
		}
	}
	pr_debug("%s, 1st passed \n", __FUNCTION__);
#endif

	/*
	*	initialization flow
	*	1. line buffer setting
	*	2. OSD_SR switch
	*	3. go_middle_blend could be set together
	*	4. then write all online path programming done
	*/
	gdma_config_fbc();

	mixer_ctrl2.regValue = rtd_inl(OSDOVL_Mixer_CTRL2_reg);
#if defined(CONFIG_ARCH_RTK284X)
	mixer_ctrl2.measure_osd_zone_en = 1;
	mixer_ctrl2.measure_osd_zone_type = 0; //A=0, R=0, G=0, B=0
#endif
	mixer_ctrl2.video_src_sel = 1;
	mixer_ctrl2.mixero1_en    = 1;
	mixer_ctrl2.mixero2_en    = 0;
	mixer_ctrl2.mixero3_en    = 1;
	mixer_ctrl2.mixer_en       = 1;
	rtd_outl(OSDOVL_Mixer_CTRL2_reg, mixer_ctrl2.regValue);

	/* wdma_bl set to 'd80 by HW RD suggestion */
	/*dma_bl_2_reg.regValue = rtd_inl(GDMA_DMA_BL_2_reg);
	dma_bl_2_reg.wdma_bl = 80;
	rtd_outl(GDMA_DMA_BL_2_reg, dma_bl_2_reg.regValue);
	*/

	/* mixer layer sel: video keep at c5 place */
	mixer_layer_sel_reg.regValue = rtd_inl(OSDOVL_Mixer_layer_sel_reg);
	mixer_layer_sel_reg.c0_sel = GDMA_PLANE_OSD1;
	mixer_layer_sel_reg.c1_sel = GDMA_PLANE_OSD2;
	mixer_layer_sel_reg.c2_sel = GDMA_PLANE_OSD3;
	mixer_layer_sel_reg.c3_sel = 0;
	rtd_outl(OSDOVL_Mixer_layer_sel_reg, mixer_layer_sel_reg.regValue);

	gdma_config_mid_blend();

	onlineProgDone |= GDMA_CTRL_osd1_prog_done(1);
	onlineProgDone |= GDMA_CTRL_osd2_prog_done(1);
	onlineProgDone |= GDMA_CTRL_osd3_prog_done(1);

	/* OSD programming done */
	rtd_outl(GDMA_CTRL_reg, onlineProgDone);

	rtd_printk(KERN_INFO,TAG_NAME,"%s, %d, MIXER = 0x%x\n", __FUNCTION__, __LINE__, rtd_inl(OSDOVL_Mixer_CTRL2_reg));
	rtd_printk(KERN_INFO,TAG_NAME,"[GDMA] Panel Width=%d, Height=%d \n", gdma->dispWin[0].width, gdma->dispWin[0].height);

	/* clear blend_setting_conflict */
	rtd_outl(GDMA_blend_setting_conflict_reg, 0);

	/* Yvonne todo modify GDMA_IRQ->39 */
	if (request_irq(GDMA_IRQ, GDMA_irq_handler, IRQF_SHARED, "gdma", gdma)) {
		DBG_PRINT(KERN_EMERG"gdma: can't get assigned irq%i\n", GDMA_IRQ);
	}
//fox mark for performace update
//#ifdef CONFIG_SMP
#if 0
	cpu_mask = (struct cpumask *)get_cpu_mask(2);	// ISR move to cpu1
	cpumask_set_cpu(2, cpu_mask);
	if (irq_can_set_affinity(GDMA_IRQ))
		irq_set_affinity(GDMA_IRQ, cpu_mask);
#endif
	gdma->plane = GDMA_PLANE_NONE;
	gdma->ctrl.displayEachPic = 1;
	gdma->ctrl.OSD1onTop      = 0;


	/*  osd sync work queue init */
	psOsdSyncWorkQueue = alloc_ordered_workqueue("OsdSync", WQ_FREEZABLE | WQ_MEM_RECLAIM | WQ_HIGHPRI);
	INIT_WORK(&sOsdSyncWork, osd_sync_hwc);

	memset(&sGdmaReceiveWork[0], 0x0, sizeof(sGdmaReceiveWork));

	dev = MKDEV(gdma_major, gdma_minor + gdma_nr_devs);

#ifdef USR_WORKQUEUE_UPDATE_BUFFER
	psOsd1RecWorkQueue = alloc_ordered_workqueue("OsdgRec", WQ_FREEZABLE | WQ_MEM_RECLAIM | WQ_HIGHPRI | __WQ_ORDERED);

	for(i=0;i<USE_TRIPLE_BUFFER_NUM;i++){
		INIT_WORK(&sOSD1ReceiveWork[i].GdmaReceiveWork, osd1_send_hw);
		sOSD1ReceiveWork[i].used=0;
    }
    sema_init(&gdma->sem_work, 1);
    sema_init(&gdma->sem_work_down_timeout, 0);
#endif

#ifdef TRIPLE_BUFFER_SEMAPHORE
	for (i = 0; i < GDMA_PLANE_MAXNUM; i++)
		gSemaphore[i] = gSEMAPHORE_MAX;
#endif

	/* gdma INT rounting to SCPU */
	rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, SYS_REG_INT_CTRL_SCPU_osd_int_scpu_routing_en_mask | SYS_REG_INT_CTRL_SCPU_write_data(1));

	/* enable GDMA interrupt */
	rtd_outl(GDMA_OSD_INTST_reg, ~1); /*  clear status */
#ifndef USING_GDMA_VSYNC
#ifdef TRIPLE_BUFFER_SEMAPHORE
	rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(1) | GDMA_OSD_INTEN_osd1_vact_end(1) | GDMA_OSD_INTEN_osd1_vsync(1));
#else
	rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(1) | GDMA_OSD_INTEN_osd1_vact_end(1));
#endif
#else
	rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(1) | GDMA_OSD_INTEN_osd1_vsync(1));
#endif

#if defined(CONFIG_REALTEK_PCBMGR)
	pr_debug("[GDMA] panel vflip=%d \n", panel_parameter->iVFLIP);
	if (panel_parameter->iVFLIP)	{
		/*  SFG_CTRL_0 */
		rtd_outl(SFG_SFG_CTRL_0_reg, rtd_inl(SFG_SFG_CTRL_0_reg) | SFG_SFG_CTRL_0_h_flip_en(1));
		/*if bootcode has already enable vfip bit ,
		  we don't have to reset it again */
		if(GDMA_OSD1_CTRL_get_rotate(rtd_inl(GDMA_OSD1_CTRL_reg)) ==0) {
		GDMA_ConfigVFlip(1);
	}
		gdma->ctrl.enableVFlip = 1;
	}
#endif
	device_enable_async_suspend(&gdma_devs->dev);
	GDMA_init_debug_proc();

#if defined(CONFIG_RTK_KDRV_DC_MEMORY_TRASH_DETCTER)
DCMT_DEBUG_INFO_REGISTER(osd_mdscpu,osd_debug_info);
#endif
	rtd_printk(KERN_INFO,TAG_NAME,"%s finish.\n", __FUNCTION__);

	gdma_total_ddr_size = get_memory_size(GFP_DCU1) + get_memory_size(GFP_DCU2);
	printk(KERN_NOTICE"[GDMA]get total memsize = %08x\n", (unsigned int)gdma_total_ddr_size);

	return 0;
}


#ifdef CONFIG_PM
#if defined(CONFIG_CUSTOMER_TV006)
static int gdma_suspend (struct device *p_dev) {
#else
int gdma_suspend_by_vbe(void);
static int gdma_suspend(struct device *p_dev) {
	if(p_dev == NULL)
		gdma_suspend_by_vbe();
	else
		printk(KERN_NOTICE"[GDMA]skip func=%s\n", __FUNCTION__);
	return 0;

}
int gdma_suspend_by_vbe(void) {
#endif
	int i, size;
	rtd_printk(KERN_EMERG,TAG_NAME,"%s \n", __FUNCTION__);

	/* disable GDMA interrupt */
	/* rtd_outl(0xb801a644, rtd_inl(0xb801a644) | 0x00002000); // disable SCPU to receive OSD/SUB Interrupt */
	rtd_outl(GDMA_OSD_INTST_reg, ~1); /*  clear status */


#ifndef USING_GDMA_VSYNC
#ifdef TRIPLE_BUFFER_SEMAPHORE
	rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(0) | GDMA_OSD_INTEN_osd1_vact_end(1) | GDMA_OSD_INTEN_osd1_vsync(1));
#else
	rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(0) | GDMA_OSD_INTEN_osd1_vact_end(1));
#endif
#else
	rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(0) | GDMA_OSD_INTEN_osd1_vsync(1));
#endif

	for (i = 0; i < gdma_nr_devs; i++) {
		free_irq(GDMA_IRQ, &gdma_devices[i]);
	}
	size = (sizeof(GDMA_PM_REGISTER_DATA)/4)/2;
	for (i = 0; i < size; i++) {
		GDMA_PM_REGISTER_DATA[i][1] = rtd_inl(GDMA_PM_REGISTER_DATA[i][0]);
		DBG_PRINT("func=%s line=%d GDMA_PM_REGISTER_DATA[i][0]=%x\n", __FUNCTION__, __LINE__, GDMA_PM_REGISTER_DATA[i][0]);
		DBG_PRINT("func=%s line=%d GDMA_PM_REGISTER_DATA[i][1]=%x\n", __FUNCTION__, __LINE__, GDMA_PM_REGISTER_DATA[i][1]);
	}

	osd_ctrl_data[GDMA_PLANE_OSD1] = rtd_inl(GDMA_OSD1_CTRL_reg);
	/*osd_ctrl_data[GDMA_PLANE_OSD2] = rtd_inl(GDMA_OSD2_CTRL_reg);*/
	osd_ctrl_data[GDMA_PLANE_OSD3] = rtd_inl(GDMA_OSD3_CTRL_reg);

	DBG_PRINT("func=%s GDMA_OSD1_CTRL_reg=0x%x\n", __FUNCTION__, osd_ctrl_data[GDMA_PLANE_OSD1]);
	DBG_PRINT("func=%s GDMA_OSD2_CTRL_reg=0x%x\n", __FUNCTION__, osd_ctrl_data[GDMA_PLANE_OSD2]);
	DBG_PRINT("func=%s GDMA_OSD3_CTRL_reg=0x%x\n", __FUNCTION__, osd_ctrl_data[GDMA_PLANE_OSD3]);

	return 0;
}


#if defined(CONFIG_CUSTOMER_TV006)
static int gdma_resume (struct device *p_dev) {
#else
int gdma_resume_by_vbe (void);
static int gdma_resume (struct device *p_dev) {
	if(p_dev == NULL)
		gdma_resume_by_vbe();
	else
		printk(KERN_NOTICE"[GDMA]skip func=%s\n", __FUNCTION__);
	return 0;
}
int gdma_resume_by_vbe (void) {
#endif
	int i, j, size;
	gdma_dev *gdma = NULL;
	osdovl_mixer_ctrl2_RBUS mixer_ctrl2;


#if defined(CONFIG_REALTEK_PCBMGR)
	PANEL_CONFIG_PARAMETER *panel_parameter = NULL;
#endif
	unsigned int onlineProgDone = GDMA_CTRL_write_data(1) | GDMA_CTRL_osd_others_prog_done(1);

	rtd_printk(KERN_EMERG,TAG_NAME,"%s \n", __FUNCTION__);
#if defined(CONFIG_CUSTOMER_TV006) && defined(CONFIG_SUPPORT_SCALER)
	vbe_disp_early_resume();/*patch for force enable d-domain clk https://jira.realtek.com/browse/K3LG-347, wait LG webos call, so we enable first*/
#endif

#if defined(CONFIG_REALTEK_PCBMGR)
	panel_parameter = (PANEL_CONFIG_PARAMETER *)&platform_info.panel_parameter;
	DBG_PRINT("[GDMA]panel_parameter->iCONFIG_PANEL_TYPE=%d  *********************\n\n\n\n", panel_parameter->iCONFIG_PANEL_TYPE);
	DBG_PRINT("[GDMA]panel_parameter=%s  *********************\n\n\n\n", panel_parameter->sPanelName);
#endif

	g_StartCheckFrameCnt = 100;
	/* clock select */
	GDMA_Clk_Select(0, true);

	size = (sizeof(GDMA_PM_REGISTER_DATA)/4)/2;
	for (i = 0; i < size; i++) {

		if (GDMA_OSD1_reg == GDMA_PM_REGISTER_DATA[i][0]){
			rtd_outl(GDMA_PM_REGISTER_DATA[i][0], GDMA_OSD1_write_data(1) | GDMA_PM_REGISTER_DATA[i][1]);
		}else if (GDMA_OSD2_reg == GDMA_PM_REGISTER_DATA[i][0]){
			rtd_outl(GDMA_PM_REGISTER_DATA[i][0], GDMA_OSD2_write_data(1) | GDMA_PM_REGISTER_DATA[i][1]);
		}else if (GDMA_OSD3_reg == GDMA_PM_REGISTER_DATA[i][0]){
			rtd_outl(GDMA_PM_REGISTER_DATA[i][0], GDMA_OSD3_write_data(1) | GDMA_PM_REGISTER_DATA[i][1]);
		}else{
			rtd_outl(GDMA_PM_REGISTER_DATA[i][0], GDMA_PM_REGISTER_DATA[i][1]);
		}
	}

	for (i = 0; i < gdma_nr_devs; i++) {
		gdma = &gdma_devices[i];

		if (request_irq(GDMA_IRQ, GDMA_irq_handler, IRQF_SHARED, "gdma", gdma)) {
			DBG_PRINT(KERN_EMERG"gdma: can't get assigned irq%i\n", GDMA_IRQ);
		}
	}

#ifdef CONFIG_HIBERNATION
	if (in_suspend == 1) {
		DBG_PRINT("func=%s line=%d resume early return in_suspend=%d\n", __FUNCTION__, __LINE__, in_suspend);
		//return 0;
	}
	DBG_PRINT("func=%s line=%d in_suspend=%d \n", __FUNCTION__, __LINE__, in_suspend);
#endif


	for (i = 0; i < gdma_nr_devs; i++) {
		gdma = &gdma_devices[i];

		rtd_outl(GDMA_OSD1_reg, *((u32 *)&gdma->GDMA_osd));
		rtd_outl(GDMA_OSD2_reg, *((u32 *)&gdma->GDMA_osd));
		rtd_outl(GDMA_OSD3_reg, *((u32 *)&gdma->GDMA_osd));

		/* OSD_SR switch */

		/* line buffer setting */
#if 0
		online_reg.regValue = rtd_inl(GDMA_ONLINE_reg);
		if (online_reg.set_osd1_offline == 0)
			onlineProgDone |= GDMA_CTRL_osd1_prog_done(1);
		if (online_reg.set_osd2_offline == 0)
			onlineProgDone |= GDMA_CTRL_osd2_prog_done(1);
		if (online_reg.set_osd3_offline == 0)
			onlineProgDone |= GDMA_CTRL_osd3_prog_done(1);
		if (online_reg.set_osd4_offline == 0)
			onlineProgDone |= GDMA_CTRL_osd4_prog_done(1);
		if (online_reg.set_osd5_offline == 0)
			onlineProgDone |= GDMA_CTRL_osd5_prog_done(1);
		/* OSD programming done */
		rtd_outl(GDMA_CTRL_reg, onlineProgDone);
		pr_debug("%s, 1st onlineProgDone=0x%x \n", __FUNCTION__, onlineProgDone);

		/* onlineProgDone reset to default */
		onlineProgDone = GDMA_CTRL_write_data(1) | GDMA_CTRL_osd_others_prog_done(1);

		/* wait prog done */
		while ((rtd_inl(GDMA_CTRL_reg)&prog_done_mask) != 0) {
			msleep(1);
			to_cnt++;
			if (to_cnt > 40) {
				pr_debug("%s, GDMA HW something wrong. Please check \n", __FUNCTION__);
				break;
			}
		}
		pr_debug("%s, 1st passed \n", __FUNCTION__);
#endif

		/*
		*	initialization flow
		*	1. line buffer setting
		*	2. OSD_SR switch
		*	3. go_middle_blend could be set together
		*	4. then write all online path programming done
		*/
		gdma_config_fbc();

		if(flag_gdma_resume_std == 1){
			mixer_ctrl2.regValue = rtd_inl(OSDOVL_Mixer_CTRL2_reg);
			mixer_ctrl2.mixero2_en    = 1;
			rtd_outl(OSDOVL_Mixer_CTRL2_reg, mixer_ctrl2.regValue);
			flag_gdma_resume_std = 0;
		}

		gdma_config_mid_blend();

		/* restore GDMA register setting */
		rtd_outl(GDMA_OSD1_CTRL_reg, ~1);
		rtd_outl(GDMA_OSD2_CTRL_reg, ~1);
		rtd_outl(GDMA_OSD3_CTRL_reg, ~1);
#ifndef CONFIG_CUSTOMER_TV006
		rtd_outl(GDMA_OSD1_CTRL_reg, GDMA_OSD1_CTRL_write_data(1) | osd_ctrl_data[GDMA_PLANE_OSD1]);
#endif
		//rtd_outl(GDMA_OSD2_CTRL_reg, GDMA_OSD2_CTRL_write_data(1) | osd_ctrl_data[GDMA_PLANE_OSD2]);
		//rtd_outl(GDMA_OSD3_CTRL_reg, GDMA_OSD3_CTRL_write_data(1) | osd_ctrl_data[GDMA_PLANE_OSD3]);

		onlineProgDone |= GDMA_CTRL_osd1_prog_done(1);
		onlineProgDone |= GDMA_CTRL_osd2_prog_done(1);
		onlineProgDone |= GDMA_CTRL_osd3_prog_done(1);
		/* OSD programming done */
#ifndef CONFIG_CUSTOMER_TV006
		rtd_outl(GDMA_CTRL_reg, onlineProgDone);
#endif
		DBG_PRINT("%s, 2nd onlineProgDone=0x%x \n", __FUNCTION__, onlineProgDone);

#if 0	// dont wait
		/* wait prog done */
		to_cnt = 0;
		while ((rtd_inl(GDMA_CTRL_reg)&prog_done_mask) != 0) {
			msleep(1);
			to_cnt++;
			if (to_cnt > 40) {
				pr_debug("%s, GDMA HW something wrong. Please check \n", __FUNCTION__);
				break;
			}
		}
		pr_debug("%s, 2nd passed \n", __FUNCTION__);
#endif

		for (i = 0; i < GDMA_PLANE_MAXNUM; i++) {
			gdma->ctrl.osdfirstEn[i] = 0;
		}

		/* gdma INT rounting to SCPU */
		rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, SYS_REG_INT_CTRL_SCPU_osd_int_scpu_routing_en_mask | SYS_REG_INT_CTRL_SCPU_write_data(1));

		rtd_outl(GDMA_OSD_INTST_reg, ~1); /*  clear status */

#ifndef USING_GDMA_VSYNC
#ifdef TRIPLE_BUFFER_SEMAPHORE
		rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(1) | GDMA_OSD_INTEN_osd1_vact_end(1) | GDMA_OSD_INTEN_osd1_vsync(1));
#else
		rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(1) | GDMA_OSD_INTEN_osd1_vact_end(1));
#endif
#else
		rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(1) | GDMA_OSD_INTEN_osd1_vsync(1));
#endif


		for (i = 0; i < 4; i++) {
			j = GDMA_coef_2t8p_swap[i << 1] << 16 | GDMA_coef_2t8p_swap[(i << 1) + 1];

			/* rtd_outl((GDMA_OSD1_VSYC_0_reg) + (i<<2), j); */
		}
	}

	/* fox add: tmp solution for Toshiba rotate 180 */
#if defined(CONFIG_REALTEK_PCBMGR)
	if (panel_parameter->iVFLIP) {
		/*  SFG_CTRL_0 */
		rtd_outl(SFG_SFG_CTRL_0_reg, rtd_inl(SFG_SFG_CTRL_0_reg) | SFG_SFG_CTRL_0_h_flip_en(1));
		GDMA_ConfigVFlip(1);
	}
#endif
	return 0;
}

#endif

#ifdef CONFIG_HIBERNATION
static int gdma_suspend_std (struct device *p_dev)
{
#if defined(CONFIG_RTK_KDRV_GAL)
	int i=0;
	unsigned int alloc_size=0;
	gal_std_save_dvr_phy = 0;
	gal_std_save_dvr_ptr = (unsigned int)vmalloc(GFX_CURSOR_SIZE);
	if(gal_std_save_dvr_ptr == INVALID_VAL)
		BUG();

	for (i = 0; i < total_index; i++)
	{
		gfx_data[i].to_phyAddr = 0;
		gfx_data[i].to_virtAddr = gal_std_save_dvr_ptr + alloc_size;
		alloc_size +=  gfx_data[i].size;
		gfx_data[i].virtAddr = (unsigned int)dvr_remap_cached_memory(gfx_data[i].phyAddr, PAGE_ALIGN(gfx_data[i].size), __builtin_return_address(0));
		memcpy((void*)gfx_data[i].to_virtAddr, (void*)gfx_data[i].virtAddr, gfx_data[i].size);
	}
#endif
	gdma_suspend(p_dev);

	return 0;
}

static int gdma_resume_std (struct device *p_dev)
{
	//add by fox for gfx std
	unsigned long memset_ptr, memset_start,memset_start_osd1;
	unsigned int memsize, osd_wi_addr = 0;
	int i = 0, pmRegSize; //, onlineIdx = 0, disPlane, tmp;
	unsigned int *ptr;
	unsigned int addr, osd_w, osd_h;
	gdma_dev *gdma = &gdma_devices[0];

	//GDMA_PIC_DATA *curPic;
	pmRegSize = (sizeof(GDMA_PM_REGISTER_DATA)/4)/2;

	flag_gdma_resume_std = 1;

#ifdef CONFIG_HIBERNATION
	if (in_suspend == 0) {
		pr_debug("%s, Before GAL buffer clear!!! \n", __FUNCTION__);

		if (osd_ctrl_data[GDMA_PLANE_OSD1] & GDMA_OSD1_CTRL_osd1_en_mask) {

			for (i = 0; i < pmRegSize; i++) {
				if (GDMA_OSD1_WI_reg == GDMA_PM_REGISTER_DATA[i][0]) {
					osd_wi_addr = GDMA_PM_REGISTER_DATA[i][1];
					break;
				}
			}
			//pr_debug("%s, osd_wi_addr=0x%x \n", __FUNCTION__, osd_wi_addr);

			addr = (unsigned int )phys_to_virt(osd_wi_addr);
			ptr = (unsigned int *)addr;
			ptr += 2;		// osd size
			osd_w = *ptr & 0xFFFF;
			osd_h = (*ptr & 0xFFFF0000)>>16;
			//pr_debug("%s, osd_w=0x%x, osd_h=0x%x \n", __FUNCTION__, osd_w, osd_h);

			memsize = osd_w * osd_h * 4;
			ptr += 4;		// physical address
			memset_start_osd1 = memset_start = memset_ptr = *ptr;

			//pr_debug("%s, memset_start=0x%x, memset_ptr=0x%x, memsize=0x%x \n", __FUNCTION__, memset_start, memset_ptr, memsize);
#if defined(CONFIG_RTK_KDRV_GAL)
			if (memset_ptr != 0)
			{
				unsigned long memset_ptr_virt = (unsigned long)dvr_remap_cached_memory(memset_ptr, PAGE_ALIGN(memsize), __builtin_return_address(0));
				memset((void*)memset_ptr_virt, 0, memsize);
				dmac_flush_range((void*)memset_ptr_virt, (void*)(memset_ptr_virt + memsize));
				memset((void*)memset_ptr_virt, 0, memsize);
				outer_flush_range((phys_addr_t)memset_ptr, (phys_addr_t)(memset_ptr + memsize));
				dvr_unmap_memory((void*)memset_ptr_virt, memsize);
            }
#endif
			{
			volatile GDMA_PIC_DATA *curPic;
			unsigned int clear_index;
			if(gdma->curPic[GDMA_PLANE_OSD1] == 0)
				clear_index = GDMA_MAX_PIC_Q_SIZE-1;
			else
				clear_index = gdma->curPic[GDMA_PLANE_OSD1]-1;
			curPic = gdma->pic[GDMA_PLANE_OSD1] + clear_index;
			memset_start = memset_ptr = curPic->OSDwin.top_addr;
			memsize = curPic->OSDwin.winWH.height * curPic->OSDwin.pitch;

			//pr_debug("%s,clear_index =%d  memset_start=0x%x, memset_ptr=0x%x, memsize=0x%x \n", __FUNCTION__, clear_index,memset_start, memset_ptr, memsize);

			if((memset_start_osd1 != memset_start) && (memset_start != 0))
			{
#if defined(CONFIG_RTK_KDRV_GAL)
				unsigned long memset_ptr_virt = (unsigned long)dvr_remap_cached_memory(memset_ptr, PAGE_ALIGN(memsize), __builtin_return_address(0));
				memset((void*)memset_ptr_virt, 0, memsize);
				dmac_flush_range((void*)memset_ptr_virt, (void*)(memset_ptr_virt + memsize));
				outer_flush_range((phys_addr_t)memset_ptr, (phys_addr_t)(memset_ptr + memsize));
				dvr_unmap_memory((void*)memset_ptr_virt, memsize);
#endif
			}

			}
		}
		pr_debug("%s, GAL buffer clear!!! \n", __FUNCTION__);
		// check picture queue
		//pr_debug("%s, cur=%d, qwr=%d \n", __FUNCTION__, gdma->curPic[GDMA_PLANE_OSD1], gdma->picQwr[GDMA_PLANE_OSD1]);
	}
#endif

#if defined(CONFIG_RTK_KDRV_GAL)
	for (i = 0; i < total_index; i++) {
		memcpy((void*)gfx_data[i].virtAddr, (void*)gfx_data[i].to_virtAddr, gfx_data[i].size);
		dmac_flush_range((void*)gfx_data[i].virtAddr, (void*)(gfx_data[i].virtAddr + gfx_data[i].size));
		outer_flush_range((phys_addr_t)gfx_data[i].phyAddr, (phys_addr_t)(gfx_data[i].phyAddr + gfx_data[i].size));
		dvr_unmap_memory((void*)gfx_data[i].virtAddr, (size_t)(PAGE_ALIGN(gfx_data[i].size)));
	}
	vfree((const void*)gal_std_save_dvr_ptr);
#endif
	gdma_resume(p_dev);
	return 0;
}
#endif

/*============= API for 3D Graphic =============*/

int GDMA_ReleaseBuffers(gdma_dev *gdma, int Qstart, int Qend, int disPlane)
{
	int i = Qstart;
	DBG_PRINT(KERN_EMERG"%s: disPlane=%d, Qstart=%d, Qend=%d gdma->picCount=%d \n", __FUNCTION__, disPlane, Qstart, Qend, gdma->picCount[disPlane]);

	do {
		gdma->picCount[disPlane]--;
	} while (i++ != Qend);

	return GDMA_SUCCESS;
}

/** @brief Flush GDMA & OSD_COMP queue work, but leave the latest picture and force to show
 *  @param None
 *  @return None
 */
void GDMA_QueueFlush(void)
{
	int disPlane = 0;
	gdma_dev *gdma = &gdma_devices[0];
	GDMA_PIC_DATA *curPic;

	for (disPlane = 0; disPlane < GDMA_PLANE_MAXNUM; disPlane++) {
		/*  check if the remainder picture in queue */
		if (gdma->curPic[disPlane] != gdma->picQwr[disPlane]) {
			gdma->picCount[disPlane] = 0;
			gdma->curPic[disPlane] = gdma->picQrd[disPlane] = gdma->picQwr[disPlane];
			pr_debug(KERN_EMERG "%s disPlane=%d : r %d,w %d c %d \n", __FUNCTION__, disPlane, gdma->picQrd[disPlane], gdma->picQwr[disPlane], gdma->curPic[disPlane]);

			/*  waiting for the latest picture is ready (work done) */
			curPic = gdma->pic[disPlane] + gdma->picQwr[disPlane];
			while (curPic->workqueueDone == 0)
				;
		}
	}

	GDMA_ENTER_CRITICAL();
	GDMA_Update(gdma, 0);

	for (disPlane = 0; disPlane < GDMA_PLANE_MAXNUM; disPlane++)
		gdma->ctrl.sync[disPlane] = 0;

	GDMA_EXIT_CRITICAL();
}

int GDMA_Flush (gdma_dev *gdma)
{
	int disPlane = 0;
	for (disPlane = 0; disPlane < GDMA_PLANE_MAXNUM; disPlane++) {
		if (gdma->picQrd[disPlane] != gdma->picQwr[disPlane]) {
			/*GDMA_ReleaseBuffers (gdma, gdma->picQrd[disPlane] + 1, gdma->picQwr[disPlane], disPlane);*/
			gdma->curPic[disPlane] = gdma->picQrd[disPlane] = gdma->picQwr[disPlane];
			gdma->ctrl.sync[disPlane] = 0;
			pr_debug(KERN_EMERG"%s : disPlane=%d r %d,w %d c %d \n", __FUNCTION__, disPlane, gdma->picQrd[disPlane], gdma->picQwr[disPlane], gdma->curPic[disPlane]);
		}
	}
	return GDMA_SUCCESS;
}

int GDMA_Hide (gdma_dev *gdma)
{
	if (gdma->plane == GDMA_PLANE_OSD1 && !gdma->osdPlane[GDMA_PLANE_OSD1].OSD_ctrl.en) {
		if (gdma->ctrl.OSD1onTop) {
			rtd_outl(GDMA_OSD2_CTRL_reg, ~1);
			rtd_outl(GDMA_CTRL_reg,  GDMA_CTRL_write_data(1) | GDMA_CTRL_osd2_prog_done(1));
			gdma->ctrl.osdEn[GDMA_PLANE_OSD2] = 0;
		} else {
			rtd_outl(GDMA_OSD1_CTRL_reg, ~1);
			rtd_outl(GDMA_CTRL_reg,  GDMA_CTRL_write_data(1) | GDMA_CTRL_osd1_prog_done(1));
			gdma->ctrl.osdEn[GDMA_PLANE_OSD1] = 0;
		}
	} else if (gdma->plane == GDMA_PLANE_OSD2 && !gdma->osdPlane[GDMA_PLANE_OSD2].OSD_ctrl.en) {
		if (gdma->ctrl.OSD1onTop) {
			rtd_outl(GDMA_OSD1_CTRL_reg, ~1);
			rtd_outl(GDMA_CTRL_reg,  GDMA_CTRL_write_data(1) | GDMA_CTRL_osd1_prog_done(1));
			gdma->ctrl.osdEn[GDMA_PLANE_OSD1] = 0;
		} else {
			rtd_outl(GDMA_OSD2_CTRL_reg, ~1);
			rtd_outl(GDMA_CTRL_reg, GDMA_CTRL_write_data(1) | GDMA_CTRL_osd2_prog_done(1));
			gdma->ctrl.osdEn[GDMA_PLANE_OSD2] = 0;
		}
	} else if (gdma->plane == GDMA_PLANE_OSD3 && !gdma->osdPlane[GDMA_PLANE_OSD3].OSD_ctrl.en) {
		rtd_outl(GDMA_OSD3_CTRL_reg, ~1);
		rtd_outl(GDMA_CTRL_reg, GDMA_CTRL_write_data(1) | GDMA_CTRL_osd3_prog_done(1));
		gdma->ctrl.osdEn[GDMA_PLANE_OSD3] = 0;
	}
	return GDMA_SUCCESS;
}


/** @brief Set OSD HW registers according to parameter disPlane which indicate OSD number
 *  @param disPlane HW OSD number (GDMA_DISPLAY_PLANE includes GDMA_PLANE_OSD1 & GDMA_PLANE_OSD2)
 *  @return None
 */
static void GDMA_OSDReg_Set(GDMA_DISPLAY_PLANE disPlane)
{
	gdma_dev *gdma = &gdma_devices[0];
	GDMA_PIC_DATA *curPic;
	unsigned int offset = 0;
	osdovl_mixer_layer_sel_RBUS mixer_layer_sel_reg;
	resource_lb_RBUS resource_lb_reg;
	GDMA_REG_CONTENT *pReg = NULL;
	unsigned int cx_sel_old = 0, cx_sel_new = 0;

	curPic = gdma->pic[disPlane] + gdma->curPic[disPlane];
	pReg = &curPic->reg_content;

	DBG_PRINT(KERN_EMERG"%s line=%d disPlane=%d, workqueueIdx=%d \n", __FUNCTION__, __LINE__, disPlane, curPic->workqueueIdx);
	DBG_PRINT(KERN_EMERG"%s gdma->curPic[%d]=%d, curPic->onlineOrder=%d\n", __FUNCTION__, disPlane, gdma->curPic[disPlane], curPic->onlineOrder);


	if (disPlane == GDMA_PLANE_OSD2)
		offset = 0x100;
	else if (disPlane == GDMA_PLANE_OSD3)
		offset = 0x200;


	/* do NOT go to mid-blend in default */
	resource_lb_reg.regValue = rtd_inl(GDMA_resource_lb_reg);
	resource_lb_reg.set_osd1_go_middle_blend = 0;
	resource_lb_reg.set_osd2_go_middle_blend = 0;
	resource_lb_reg.set_osd3_go_middle_blend = 0;
	rtd_outl(GDMA_resource_lb_reg, resource_lb_reg.regValue);

	/*  set clear region */
	rtd_outl(GDMA_OSD1_CLEAR1_reg+offset, pReg->osd_clear1_reg.regValue);
	rtd_outl(GDMA_OSD1_CLEAR2_reg+offset, pReg->osd_clear2_reg.regValue);
	rtd_outl(GDMA_OSD1_reg+offset, pReg->osd_reg.regValue);

	rtd_outl(GDMA_OSD1_CTRL_reg+offset, ~1);
	rtd_outl(GDMA_OSD1_CTRL_reg+offset, pReg->osd_ctrl_reg.regValue);

	rtd_outl(GDMA_OSD1_WI_reg+offset, pReg->osd_wi_reg.regValue);
	rtd_outl(GDMA_OSD1_WI_3D_reg+offset, pReg->osd_wi_3d_reg.regValue);
	rtd_outl(GDMA_OSD1_SIZE_reg+offset, pReg->osd_size_reg.regValue);

	DBG_PRINT(KERN_EMERG"%s GDMA_OSD%d_CLEAR1_reg=0x%x \n", __FUNCTION__, disPlane, pReg->osd_clear1_reg.regValue);
	DBG_PRINT(KERN_EMERG"%s GDMA_OSD%d_CLEAR2_reg=0x%x \n", __FUNCTION__, disPlane, pReg->osd_clear2_reg.regValue);
	DBG_PRINT(KERN_EMERG"%s GDMA_OSD%d_reg=0x%x \n", __FUNCTION__, disPlane, pReg->osd_reg.regValue);
	DBG_PRINT(KERN_EMERG"%s GDMA_OSD%d_CTRL_reg=0x%x \n", __FUNCTION__, disPlane, pReg->osd_ctrl_reg.regValue);
	DBG_PRINT(KERN_EMERG"%s GDMA_OSD%d_WI_reg=0x%x \n", __FUNCTION__, disPlane, pReg->osd_wi_reg.regValue);
	DBG_PRINT(KERN_EMERG"%s GDMA_OSD%d_WI_3D_reg=0x%x \n", __FUNCTION__, disPlane, pReg->osd_wi_3d_reg.regValue);
	DBG_PRINT(KERN_EMERG"%s GDMA_OSD%d_SIZE_reg=0x%x \n", __FUNCTION__, disPlane, pReg->osd_size_reg.regValue);
	DBG_PRINT(KERN_EMERG"%s GDMA_line_buffer_end_reg=0x%x \n", __FUNCTION__, pReg->lb_end_reg.regValue);

	/*  TODO:: call osd_sr  */
	drv_scaleup(1, disPlane);



	/*  TODO: Mixer : online blend order & plane alpha
	*	because k blend-factor setting, mixer layer order will reverse
	*/
	mixer_layer_sel_reg.regValue = rtd_inl(OSDOVL_Mixer_layer_sel_reg);
	if (curPic->onlineOrder == C0) {
		cx_sel_old = mixer_layer_sel_reg.c0_sel;
		cx_sel_new = mixer_layer_sel_reg.c0_sel = pReg->mixer_layer_sel_reg.c0_sel;

		if (pReg->mixer_layer_sel_reg.c0_plane_alpha_en != mixer_layer_sel_reg.c0_plane_alpha_en)
			mixer_layer_sel_reg.c0_plane_alpha_en = pReg->mixer_layer_sel_reg.c0_plane_alpha_en;

		rtd_outl(OSDOVL_Mixer_c0_plane_alpha1_reg, pReg->mixer_c0_plane_alpha1_reg.regValue);
		rtd_outl(OSDOVL_Mixer_c0_plane_alpha2_reg, pReg->mixer_c0_plane_alpha2_reg.regValue);
	} else if (curPic->onlineOrder == C1) {
		cx_sel_old = mixer_layer_sel_reg.c1_sel;
		cx_sel_new = mixer_layer_sel_reg.c1_sel = pReg->mixer_layer_sel_reg.c1_sel;

		if (pReg->mixer_layer_sel_reg.c1_plane_alpha_en != mixer_layer_sel_reg.c1_plane_alpha_en)
			mixer_layer_sel_reg.c1_plane_alpha_en = pReg->mixer_layer_sel_reg.c1_plane_alpha_en;

		rtd_outl(OSDOVL_Mixer_c1_plane_alpha1_reg, pReg->mixer_c1_plane_alpha1_reg.regValue);
		rtd_outl(OSDOVL_Mixer_c1_plane_alpha2_reg, pReg->mixer_c1_plane_alpha2_reg.regValue);
	} else if (curPic->onlineOrder == C2) {
		cx_sel_old = mixer_layer_sel_reg.c2_sel;
		cx_sel_new = mixer_layer_sel_reg.c2_sel = pReg->mixer_layer_sel_reg.c2_sel;

		if (pReg->mixer_layer_sel_reg.c2_plane_alpha_en != mixer_layer_sel_reg.c2_plane_alpha_en)
			mixer_layer_sel_reg.c2_plane_alpha_en = pReg->mixer_layer_sel_reg.c2_plane_alpha_en;

		rtd_outl(OSDOVL_Mixer_c2_plane_alpha1_reg, pReg->mixer_c2_plane_alpha1_reg.regValue);
		rtd_outl(OSDOVL_Mixer_c2_plane_alpha2_reg, pReg->mixer_c2_plane_alpha2_reg.regValue);
	} else if (curPic->onlineOrder == C3) {
		cx_sel_old = mixer_layer_sel_reg.c3_sel;
		cx_sel_new = mixer_layer_sel_reg.c3_sel = pReg->mixer_layer_sel_reg.c3_sel;

		if (pReg->mixer_layer_sel_reg.c3_plane_alpha_en != mixer_layer_sel_reg.c3_plane_alpha_en)
			mixer_layer_sel_reg.c3_plane_alpha_en = pReg->mixer_layer_sel_reg.c3_plane_alpha_en;

		rtd_outl(OSDOVL_Mixer_c3_plane_alpha1_reg, pReg->mixer_c3_plane_alpha1_reg.regValue);
		rtd_outl(OSDOVL_Mixer_c3_plane_alpha2_reg, pReg->mixer_c3_plane_alpha2_reg.regValue);
	}


	/* conflict protect */
	if (mixer_layer_sel_reg.c0_sel == cx_sel_new && curPic->onlineOrder != C0)
		mixer_layer_sel_reg.c0_sel = cx_sel_old;
	else if (mixer_layer_sel_reg.c1_sel == cx_sel_new && curPic->onlineOrder != C1)
		mixer_layer_sel_reg.c1_sel = cx_sel_old;
	else if (mixer_layer_sel_reg.c2_sel == cx_sel_new && curPic->onlineOrder != C2)
		mixer_layer_sel_reg.c2_sel = cx_sel_old;
	else if (mixer_layer_sel_reg.c3_sel == cx_sel_new && curPic->onlineOrder != C3)
		mixer_layer_sel_reg.c3_sel = cx_sel_old;

	rtd_outl(OSDOVL_Mixer_layer_sel_reg, mixer_layer_sel_reg.regValue);
	DBG_PRINT(KERN_EMERG"%s, GDMA_line_buffer_end_reg=0x%x, OSDOVL_Mixer_layer_sel_reg=0x%x \n", __FUNCTION__, rtd_inl(GDMA_line_buffer_end_reg), mixer_layer_sel_reg.regValue);


	/*  work was done in workqueue */
	sGdmaReceiveWork[curPic->workqueueIdx].used = 0;

	/*  call register debug.... */
	/* GDMA_RegDebug(); */
}

/** @brief main dequeue function that prepare the register value and store in GDMA_REG_CONTENT
 *  @param disPlane HW OSD number (GDMA_DISPLAY_PLANE includes GDMA_PLANE_OSD1/2/3/4/5)
 *  @return None
 */
static void GDMA_PreOSDReg_Set(struct gdma_receive_work *ptr_work)
{
	VO_RECTANGLE srcWin;
	VO_RECTANGLE dispWin;
	int canvasW, canvasH;
	GDMA_WIN *win = NULL, *win_3d = NULL;
	gdma_dev *gdma = &gdma_devices[0];
	GDMA_PIC_DATA *curPic;
	GDMA_REG_CONTENT *pReg = NULL;
	GDMA_DISPLAY_PLANE disPlane = ptr_work->disPlane;
	int rotateBit = gdma->ctrl.enableVFlip;
	dma_addr_t addr, addr_3d;
#ifdef CONFIG_CUSTOMER_TV006
	GDMA_PLANE *osdPlane = &gdma->osdPlane[GDMA_PLANE_OSD1];
#endif

	memset(&srcWin, 0, sizeof(VO_RECTANGLE));
	memset(&dispWin, 0, sizeof(VO_RECTANGLE));

	curPic = gdma->pic[disPlane] + ptr_work->picQwr;
	pReg = &curPic->reg_content;

	DBG_PRINT(KERN_EMERG"%s, disPlane=%d ptr_work->picQwr=%d \n", __FUNCTION__, disPlane, ptr_work->picQwr);

	win = &curPic->OSDwin;
	win_3d = &curPic->OSDwin3D;

	if (win->used) {

		addr = dma_map_single(gdma->dev, (void *)win, sizeof(GDMA_WIN), DMA_TO_DEVICE);
		addr_3d = dma_map_single(gdma->dev, (void *)win_3d, sizeof(GDMA_WIN), DMA_TO_DEVICE);

		srcWin.x = win->winXY.x;
		srcWin.y = win->winXY.y;

		srcWin.width = win->winWH.width;
		srcWin.height = win->winWH.height;

		dispWin.x = win->dst_x;
		dispWin.y = win->dst_y;

		if (win->dst_width != 0 && win->dst_height != 0) {
			dispWin.width = win->dst_width;
			dispWin.height = win->dst_height;
		} else {
			dispWin.width = gdma->dispWin[disPlane].width;
			dispWin.height = gdma->dispWin[disPlane].height;
		}

#ifdef CONFIG_CUSTOMER_TV006
		/* follow AP GOR (grahpic output resolution) configuration which is maximum size for GDMA output */
		if (dispWin.width > osdPlane->OSD_canvas.dispWin.width)
			dispWin.width = osdPlane->OSD_canvas.dispWin.width;
		if (dispWin.height > osdPlane->OSD_canvas.dispWin.height)
			dispWin.height = osdPlane->OSD_canvas.dispWin.height;
#endif


		/* whether non-compressed or normal or FBDC layer, canvas always is source size
		*  this is different between mac3 and magellan2, mac3's compressed image that canvas is panel size
		*/
		canvasW = srcWin.width;
		canvasH = srcWin.height;



#if 0
		/*  3D PR Mode, output height scaling down 1/2 */
		if (gdma->ctrl.enable3D && gdma->ctrl.enable3D_PR_SGMode)
			vout = vout / 2;
#endif


		/*  set clear region */
		if (curPic->clear_x.value != 0 || curPic->clear_y.value != 0) {
			pReg->osd_clear1_reg.regValue = curPic->clear_x.value;
			pReg->osd_clear2_reg.regValue = curPic->clear_y.value;
			pReg->osd_reg.regValue = GDMA_OSD1_clear_region_en(1) | GDMA_OSD1_write_data(1);
		} else {
			pReg->osd_reg.regValue = GDMA_OSD1_clear_region_en(1) | GDMA_OSD1_write_data(0);
		}

		if (gdma->ctrl.osdfirstEn[disPlane] == 0) {

			pReg->osd_ctrl_reg.regValue = GDMA_OSD1_CTRL_write_data(1) | GDMA_OSD1_CTRL_osd1_en(curPic->show) | GDMA_OSD1_CTRL_rotate(rotateBit) | GDMA_OSD1_CTRL_d3_mode(gdma->ctrl.enable3D);

			gdma->ctrl.osdEn[disPlane] = 1;
			gdma->ctrl.osdfirstEn[disPlane] = 1;
			DBG_PRINT(KERN_EMERG"%s, win=0x%x, phy=0x%x\n", __FUNCTION__, (unsigned int)win, virt_to_phys(win));
		} else {
			/*  if osdEn changes to 0, driver will force curPic->show to zero and disable OSD */
			if (gdma->ctrl.osdEn[disPlane] == 0)
				curPic->show = 0;

			pReg->osd_ctrl_reg.regValue = GDMA_OSD1_CTRL_write_data(1) | GDMA_OSD1_CTRL_osd1_en(curPic->show) | GDMA_OSD1_CTRL_rotate(rotateBit);

			/*  3D SG mode use d3_mode (frame sequence) */
			if (gdma->ctrl.enable3D && (gdma->ctrl.enable3D_PR_SGMode == 0))
				pReg->osd_ctrl_reg.regValue |= GDMA_OSD1_CTRL_d3_mode(gdma->ctrl.enable3D);
		}

		/*
		if (gdma->f_box_mode && gdma->box_dst_height == VIDEO_USERDEFINED)
		   rtd_outl(OSD_XY_Addr, GDMA_OSD3_XY_x(dispWin.x) | GDMA_OSD3_XY_y(dispWin.y));
		else
			rtd_outl(OSD_XY_Addr, 0);
			rtd_outl(OSD_XY_Addr, GDMA_OSD3_XY_x(dispWin.x) | GDMA_OSD3_XY_y(dispWin.y));
		*/

		DBG_PRINT(KERN_EMERG"%s, curPic->show=%d, gdma->ctrl.osdEn[%d]=%d \n", __FUNCTION__, curPic->show, disPlane, gdma->ctrl.osdEn[disPlane]);
		DBG_PRINT(KERN_EMERG"%s, osd%d  win=0x%x, top=0x%x gdma->f_inputsrc_4k2k=%d \n", __FUNCTION__, disPlane, (unsigned int)win, win->top_addr, gdma->f_inputsrc_4k2k);
		DBG_PRINT(KERN_EMERG"%s, input src[x,y,w,h]= [%d,%d,%d,%d] \n", __FUNCTION__, win->winXY.x, win->winXY.y, canvasW, canvasH);
		DBG_PRINT(KERN_EMERG"%s, output[x,y,w,h]= [%d,%d,%d,%d] \n", __FUNCTION__, win->dst_x, win->dst_y, win->dst_width ,win->dst_height);
		DBG_PRINT(KERN_EMERG"%s, plane_alpha_r=0x%x, plane_alpha_a=0x%x \n", __FUNCTION__, curPic->plane_ar.plane_alpha_r, curPic->plane_ar.plane_alpha_a);
		DBG_PRINT(KERN_EMERG"%s, plane_alpha_g=0x%x, plane_alpha_b=0x%x \n", __FUNCTION__, curPic->plane_gb.plane_alpha_g, curPic->plane_gb.plane_alpha_b);
		pReg->osd_wi_reg.regValue = GDMA_OSD1_WI_addr (virt_to_phys(win));
		pReg->osd_wi_3d_reg.regValue = GDMA_OSD1_WI_3D_addr (virt_to_phys(win_3d));
		pReg->osd_size_reg.regValue = GDMA_OSD1_SIZE_w(canvasW) | GDMA_OSD1_SIZE_h(canvasH);

		/*  TODO:: call osd_sr */
		drv_PreScale(1, srcWin, dispWin, disPlane, ptr_work);

		/*  TODO: Mixer : online blend order & plane alpha */
		if (curPic->onlineOrder == C0) {
			pReg->mixer_layer_sel_reg.c0_sel = disPlane;

			if ((curPic->plane_ar.plane_alpha_r != 0xff) || (curPic->plane_ar.plane_alpha_a != 0xff))
				pReg->mixer_layer_sel_reg.c0_plane_alpha_en = 1;

			if ((curPic->plane_gb.plane_alpha_g != 0xff) || (curPic->plane_gb.plane_alpha_b != 0xff))
				pReg->mixer_layer_sel_reg.c0_plane_alpha_en = 1;

			pReg->mixer_c0_plane_alpha1_reg.regValue = curPic->plane_ar.value;
			pReg->mixer_c0_plane_alpha2_reg.regValue = curPic->plane_gb.value;
		} else if (curPic->onlineOrder == C1) {
			pReg->mixer_layer_sel_reg.c1_sel = disPlane;

			if ((curPic->plane_ar.plane_alpha_r != 0xff) || (curPic->plane_ar.plane_alpha_a != 0xff))
				pReg->mixer_layer_sel_reg.c1_plane_alpha_en = 1;

			if ((curPic->plane_gb.plane_alpha_g != 0xff) || (curPic->plane_gb.plane_alpha_b != 0xff))
				pReg->mixer_layer_sel_reg.c1_plane_alpha_en = 1;

			pReg->mixer_c1_plane_alpha1_reg.regValue = curPic->plane_ar.value;
			pReg->mixer_c1_plane_alpha2_reg.regValue = curPic->plane_gb.value;
		} else if (curPic->onlineOrder == C2) {
			pReg->mixer_layer_sel_reg.c2_sel = disPlane;

			if ((curPic->plane_ar.plane_alpha_r != 0xff) || (curPic->plane_ar.plane_alpha_a != 0xff))
				pReg->mixer_layer_sel_reg.c2_plane_alpha_en = 1;

			if ((curPic->plane_gb.plane_alpha_g != 0xff) || (curPic->plane_gb.plane_alpha_b != 0xff))
				pReg->mixer_layer_sel_reg.c2_plane_alpha_en = 1;

			pReg->mixer_c2_plane_alpha1_reg.regValue = curPic->plane_ar.value;
			pReg->mixer_c2_plane_alpha2_reg.regValue = curPic->plane_gb.value;
		} else if (curPic->onlineOrder == C3) {
			pReg->mixer_layer_sel_reg.c3_sel = disPlane;

			if ((curPic->plane_ar.plane_alpha_r != 0xff) || (curPic->plane_ar.plane_alpha_a != 0xff))
				pReg->mixer_layer_sel_reg.c3_plane_alpha_en = 1;

			if ((curPic->plane_gb.plane_alpha_g != 0xff) || (curPic->plane_gb.plane_alpha_b != 0xff))
				pReg->mixer_layer_sel_reg.c3_plane_alpha_en = 1;

			pReg->mixer_c3_plane_alpha1_reg.regValue = curPic->plane_ar.value;
			pReg->mixer_c3_plane_alpha2_reg.regValue = curPic->plane_gb.value;
		}
		/*
		else if (curPic->onlineOrder == C5)
			pReg->mixer_layer_sel_reg.c5_sel = disPlane;
		*/

		dma_sync_single_for_device(gdma->dev, addr, sizeof(GDMA_WIN), DMA_TO_DEVICE);
		dma_sync_single_for_device(gdma->dev, addr_3d, sizeof(GDMA_WIN), DMA_TO_DEVICE);
		dma_unmap_single(gdma->dev, addr, sizeof(GDMA_WIN), DMA_TO_DEVICE);
		dma_unmap_single(gdma->dev, addr_3d, sizeof(GDMA_WIN), DMA_TO_DEVICE);

		/*  register value was ready */
		curPic->workqueueDone = 1;

		/*  call register debug.... */
		/* GDMA_RegDebug(); */
	} else
		pr_debug(KERN_EMERG"%s, win->used is NOT one, something wrong \n", __FUNCTION__);

}


/** @brief check the syncstamp of picture in other queue which is match the syncstamp number
 *  @param disPlane where OSD plane has syncstamp picture
 *  @return 0: mismatch, 1: all match
 */
static int GDMA_checkSyncStamp(int disPlane)
{
	volatile int syncPicNum = 0;
	volatile int loop;
	volatile GDMA_PIC_DATA *curPic, *otherPic;
	volatile gdma_dev *gdma = &gdma_devices[0];

	curPic = gdma->pic[disPlane] + gdma->curPic[disPlane];

	DBG_PRINT(KERN_EMERG"%s, param disPlane=%d, \n", __FUNCTION__, disPlane);
	DBG_PRINT(KERN_EMERG"%s, syncstamp=%lld, ", __FUNCTION__, curPic->syncInfo.syncstamp);
	DBG_PRINT(KERN_EMERG"%s, syncInfo.matchNum=%d \n", __FUNCTION__, curPic->syncInfo.matchNum);



	for (loop = 0; loop < curPic->syncInfo.matchNum; loop++) {
		otherPic = gdma->pic[curPic->syncInfo.matchPlane[loop]] + gdma->curPic[curPic->syncInfo.matchPlane[loop]];

		DBG_PRINT(KERN_EMERG"%s, syncInfo.matchPlane=%d, ", __FUNCTION__, curPic->syncInfo.matchPlane[loop]);
		DBG_PRINT(KERN_EMERG"%s, another OSD Num=%d, its syncstamp=%lld \n", __FUNCTION__, curPic->syncInfo.matchPlane[loop], otherPic->syncInfo.syncstamp);

		if (curPic->syncInfo.syncstamp == otherPic->syncInfo.syncstamp &&
			curPic->workqueueDone == 1) {  /*  check workqueueDone */
			syncPicNum++;
			DBG_PRINT(KERN_EMERG"%s, Match Case syncstamp=%lld \n", __FUNCTION__, curPic->syncInfo.syncstamp);
			//DBG_PRINT(KERN_EMERG"another OSD Num=%d, its syncstamp=%lld \n", curPic->syncInfo.matchPlane[loop], otherPic->syncInfo.syncstamp);
		}
		else
			break;
	}

	if (syncPicNum == curPic->syncInfo.matchNum)
		return 1;

	return 0;
}


/** @brief this function is dequeue process of GDMA workqueue
 *         prepare the related register value and store
 *  @param psWork the work was sent by GDMA_ReceivePicture and indicate the display plane number
 *  @return GDMA_SUCCESS
 */
void GDMA_PreUpdate(struct work_struct *psWork)
{
	struct gdma_receive_work *ptr_work;
	ptr_work = (struct gdma_receive_work *) psWork;

	if (ptr_work->used == 1) {
		GDMA_PreOSDReg_Set(ptr_work);
	} else
		pr_debug(KERN_EMERG"%s Unexpected case \n", __FUNCTION__);

}


int GDMA_Update (gdma_dev *gdma, int inISR)
{
	volatile int Qend, syncPicNum = 0, loop = 0;
	volatile GDMA_PIC_DATA *curPic;
	volatile int disPlane, disPlane_tmp, cnt = 0, syncPicFlag, curPicIdx = 0;
	volatile int QueueFlag[GDMA_PLANE_MAXNUM] = {0};	/*  1: indicate this queue has picture to show */
	volatile unsigned int updatedOSDx = 0;				/* actual updated OSD number */
	//volatile static int osdSyncStamp[GDMA_PLANE_MAXNUM] = {0};	/*  keep the setting which picture has syncstamp */
	//volatile static int osdSyncStampTimeout[GDMA_PLANE_MAXNUM] = {0};
	volatile int osdSyncStampNum[GDMA_PLANE_MAXNUM] = {0};  /*  remember syncstamp driver searched before */
	volatile osdovl_osd_db_ctrl_RBUS osd_db_ctrl_reg;
	volatile int onlinePlane[GDMA_PLANE_MAXNUM] = {GDMA_PLANE_OSD1, GDMA_PLANE_OSD2, GDMA_PLANE_OSD3, 0};
	volatile int onlineMaxNum = MAX_OSD_NUM, onlineIdx = 0;
	volatile unsigned int onlineProgDone = GDMA_CTRL_write_data(1) | GDMA_CTRL_osd_others_prog_done(1);
	/* fox modify for use cookie to sync GDMA */
	static unsigned int cookie_flag = 0;


	/* search all updated picture of osd plane  */
	for (onlineIdx = 0; onlineIdx < onlineMaxNum; onlineIdx++) {
		disPlane = onlinePlane[onlineIdx];

#ifdef TRIPLE_BUFFER_SEMAPHORE
		if ((gdma->picQwr[disPlane] > gdma->curPic[disPlane])  && (gdma->picQwr[disPlane] - gdma->curPic[disPlane]) > 2)
			DBG_PRINT(KERN_EMERG"GDMA line=%d : r %d,w %d c %d \n", __LINE__, gdma->picQrd[disPlane], gdma->picQwr[disPlane], gdma->curPic[disPlane]);
		else {
			if ((gdma->picQwr[disPlane] < gdma->curPic[disPlane]) && ((gdma->picQwr[disPlane]+GDMA_MAX_PIC_Q_SIZE) >= gdma->curPic[disPlane])  && ((gdma->picQwr[disPlane]+GDMA_MAX_PIC_Q_SIZE) - gdma->curPic[disPlane]) > 2)
				DBG_PRINT(KERN_EMERG"GDMA line=%d : r %d,w %d c %d \n", __LINE__, gdma->picQrd[disPlane], gdma->picQwr[disPlane], gdma->curPic[disPlane]);
		}
#else
		if ((gdma->picQwr[disPlane] > gdma->curPic[disPlane])  && (gdma->picQwr[disPlane] - gdma->curPic[disPlane]) >= 2)
			DBG_PRINT(KERN_EMERG"GDMA line=%d : OSD%d r %d,w %d c %d \n", __LINE__, disPlane, gdma->picQrd[disPlane], gdma->picQwr[disPlane], gdma->curPic[disPlane]);
		else {
			if ((gdma->picQwr[disPlane] < gdma->curPic[disPlane]) && ((gdma->picQwr[disPlane]+GDMA_MAX_PIC_Q_SIZE) >= gdma->curPic[disPlane])  && ((gdma->picQwr[disPlane]+GDMA_MAX_PIC_Q_SIZE) - gdma->curPic[disPlane]) >= 2)
				DBG_PRINT(KERN_EMERG"GDMA line=%d : OSD%d r %d,w %d c %d \n", __LINE__, disPlane, gdma->picQrd[disPlane], gdma->picQwr[disPlane], gdma->curPic[disPlane]);
		}
#endif

#if 0
		Qend = ((gdma->curPic[disPlane] + GDMA_MAX_PIC_Q_SIZE - 2) & (GDMA_MAX_PIC_Q_SIZE - 1));
		//if (gdma->picQrd[disPlane] != gdma->curPic[disPlane] && gdma->picQrd[disPlane] != Qend)
		if (gdma->picCount[disPlane] && gdma->ctrl.sync[disPlane])
		{
			/* GDMA_ReleaseBuffers  (gdma, gdma->picQrd[disPlane] + 1, Qend, disPlane); */
			gdma->picCount[disPlane]--;
			gdma->picQrd[disPlane] = Qend;
		}
#endif

		/* check next picture */
		if (inISR) {
			if (!gdma->ctrl.sync[disPlane]) {

				if ((gdma->picQrd[disPlane] != gdma->picQwr[disPlane]) && (gdma->picQwr[disPlane] >= 1)) {

					curPicIdx = (gdma->picQrd[disPlane] + 1) & (GDMA_MAX_PIC_Q_SIZE - 1);
					curPic = gdma->pic[disPlane] + curPicIdx;
					if (curPic->workqueueDone == 1)    /*  register value was ready */
						gdma->curPic[disPlane] = curPicIdx;
					else
						continue;
					/* gdma->curPic[disPlane] = (gdma->picQrd[disPlane] + 1) & (GDMA_MAX_PIC_Q_SIZE - 1); */
					gdma->ctrl.sync[disPlane] = 1;
					QueueFlag[disPlane] = 1;
					DBG_PRINT(KERN_EMERG"%s, OSD[%d]Sync ......r %d, w %d\n", __FUNCTION__, disPlane, gdma->picQrd[disPlane], gdma->picQwr[disPlane]);

#ifndef TRIPLE_BUFFER_SEMAPHORE
					/* force reset prog done register for next new picture */
					rtd_outl(GDMA_CTRL_reg, rtd_inl(GDMA_CTRL_reg)&~GDMA_CTRL_write_data_mask);
					DBG_PRINT(KERN_EMERG"%s, GDMA_CTRL_reg=0x%x\n", __FUNCTION__, rtd_inl(GDMA_CTRL_reg));
#endif
				} else {
					/* Warning("%s, OSD[%d] has no picture\n", __FUNCTION__, disPlane); */
					continue;
				}
			} else {
				curPic = gdma->pic[disPlane] + gdma->curPic[disPlane];
				curPic->repeatCnt++;
				if (!curPic->status.obsolete) {
					if (curPic->context != -1)
						gContext = curPic->context;    /* set context value */

					curPic->status.obsolete = 1;
				}

				if (gdma->curPic[disPlane] != gdma->picQwr[disPlane]) { /* select next picture to display */
					/*  keep the syncstamp OSD waiting for another OSD which has the same syncstamp */
					if (osdSyncStamp[disPlane] != 1) {
						curPicIdx = gdma->ctrl.displayEachPic ? ((gdma->curPic[disPlane] + 1) & (GDMA_MAX_PIC_Q_SIZE - 1)) : gdma->picQwr[disPlane];
						/* gdma->curPic[disPlane] = gdma->ctrl.displayEachPic ? ((gdma->curPic[disPlane] + 1) & (GDMA_MAX_PIC_Q_SIZE - 1)) : gdma->picQwr[disPlane]; */

						curPic = gdma->pic[disPlane] + curPicIdx;
						if (curPic->workqueueDone == 1) {    /*  register value was ready */
#ifdef TRIPLE_BUFFER_SEMAPHORE
							//if ((rtd_inl(GDMA_CTRL_reg)&prog_done_mask) != 0) {
							//	pr_debug(KERN_EMERG"!_GDMA Not Ready for Next Picture, disPlane=%d, GDMA_CTRL_reg=0x%x \n", disPlane, rtd_inl(GDMA_CTRL_reg));
							//	return GDMA_FAIL;
							//}
#else
							/* force reset prog done register for next new picture */
							rtd_outl(GDMA_CTRL_reg, rtd_inl(GDMA_CTRL_reg)&~GDMA_CTRL_write_data_mask);
							DBG_PRINT(KERN_EMERG"%s, GDMA_CTRL_reg=0x%x\n", __FUNCTION__, rtd_inl(GDMA_CTRL_reg));
#endif
							gdma->curPic[disPlane] = curPicIdx;
						} else
							continue;
					}
					QueueFlag[disPlane] = 1;
					DBG_PRINT(KERN_EMERG"%s, disPlane=%d, next pic c %d, w %d\n", __FUNCTION__, disPlane, gdma->curPic[disPlane], gdma->picQwr[disPlane]);
				} else {
#ifdef GDMA_REPEAT_LOG
					static int prepic;
					if (prepic == gdma->curPic[disPlane]) {
						Warning("%d(%d)\n", gdma->curPic[disPlane], curPic->repeatCnt);
					} else {
						pr_debug("%d(%d)\n", gdma->curPic[disPlane], curPic->repeatCnt);
					}
					prepic = gdma->curPic[disPlane];
#endif

					/*  if osdSyncStamp has picture to sync another picture QueueFlag rises */
					if (osdSyncStamp[disPlane] == 1) {
						QueueFlag[disPlane] = 1;
						DBG_PRINT(KERN_EMERG"%s, check syncstamp osdSyncStamp[%d]=%d \n", __FUNCTION__, disPlane, osdSyncStamp[disPlane]);
					}
				}
			}

			/*  check Queueflag if picture wants to show */
			cnt += QueueFlag[disPlane];
			/*  check syncstamp OSD */
			curPic = gdma->pic[disPlane] + gdma->curPic[disPlane];
			if (curPic->syncInfo.syncstamp != 0 && QueueFlag[disPlane] == 1) {
				osdSyncStamp[disPlane] = 1;
				DBG_PRINT(KERN_EMERG"%s, syncstamp=%lld, ", __FUNCTION__, curPic->syncInfo.syncstamp);
			}
		}
	}


	onlineMaxNum = 0;
	/* only check updated OSD HW */
	if (QueueFlag[GDMA_PLANE_OSD1] == 1) {
		onlinePlane[onlineMaxNum++] = GDMA_PLANE_OSD1;
		onlineProgDone |= GDMA_CTRL_osd1_prog_done(1);
	}
	if (QueueFlag[GDMA_PLANE_OSD2] == 1) {
		onlinePlane[onlineMaxNum++] = GDMA_PLANE_OSD2;
		onlineProgDone |= GDMA_CTRL_osd2_prog_done(1);
	}
	if (QueueFlag[GDMA_PLANE_OSD3] == 1) {
		onlinePlane[onlineMaxNum++] = GDMA_PLANE_OSD3;
		onlineProgDone |= GDMA_CTRL_osd3_prog_done(1);
	}

	if (inISR) {
		if (cnt == 0)
			return GDMA_SUCCESS;		/*  means no picture to show */
		else {
			DBG_PRINT(KERN_EMERG"%s, how many OSD config at the same time, cnt=%d \n", __FUNCTION__, cnt);
		}
	} else {
		/*  force display and clear syncstamp */
		for (onlineIdx = 0; onlineIdx < onlineMaxNum; onlineIdx++) {
			disPlane = onlinePlane[onlineIdx];

			if (gdma->ctrl.sync[disPlane])
				QueueFlag[disPlane] = 1;
			osdSyncStamp[disPlane] = 0;
		}
	}


	/* update picture info to register */
	for (onlineIdx = cnt = 0; onlineIdx < onlineMaxNum; onlineIdx++) {
		disPlane = onlinePlane[onlineIdx];

		if (gdma->ctrl.sync[disPlane] && (QueueFlag[disPlane] == 1)) {

			curPic = gdma->pic[disPlane] + gdma->curPic[disPlane];
			DBG_PRINT(KERN_EMERG"%s, OSD[%d] c ptr = %d \n", __FUNCTION__, disPlane, gdma->curPic[disPlane]);

			if (osdSyncStamp[disPlane] == 1) {  /*  wait & check for other OSD which has the same syncstamp picture */
				/*  record syncstamp number and check this syncstamp happened previously */
				int synced = 0;
				for (loop = 0; loop < syncPicNum; loop++) {
					if (curPic->syncInfo.syncstamp == osdSyncStampNum[loop]) {
						synced = 1;
						break;
					}
				}
				if (synced == 1)
					continue;      /*  don't find this syncstamp picture again */
				else
					osdSyncStampNum[syncPicNum++] = curPic->syncInfo.syncstamp;  /*  new syncstamp to search it */

				syncPicFlag = GDMA_checkSyncStamp(disPlane);
				DBG_PRINT(KERN_EMERG"%s, after GDMA_checkSyncStamp syncPicFlag=%d \n", __FUNCTION__, syncPicFlag);
				DBG_PRINT(KERN_EMERG"%s, curPic->syncstamp=%lld \n", __FUNCTION__, curPic->syncInfo.syncstamp);

				if (syncPicFlag == 0) { /*  no match syncstamp and hold this picture, so do other HW OSD settings */
					osdSyncStampTimeout[disPlane]++;
					if (osdSyncStampTimeout[disPlane] <= 5)	/*  wait for 5 interrupt time */
						continue;		/*  search the picture of another queue */
					else {
						/*  syncstamp picture time-out, and then force display */
						osdSyncStampTimeout[disPlane] = 0;
						GDMA_OSDReg_Set(disPlane);
						osdSyncStamp[disPlane] = 0;
						pr_debug(KERN_EMERG"%s, force display : disPlane=%d, syncstamp timeout \n", __FUNCTION__, disPlane);
					}
				} else {
					GDMA_OSDReg_Set(disPlane);
					osdSyncStampTimeout[disPlane] = osdSyncStamp[disPlane] = 0;
					for (loop = 0; loop < curPic->syncInfo.matchNum; loop++) {
						DBG_PRINT(KERN_EMERG"%s, the same syncstamp OSD Num=%d \n", __FUNCTION__, curPic->syncInfo.matchPlane[loop]);
						GDMA_OSDReg_Set(curPic->syncInfo.matchPlane[loop]);
						osdSyncStampTimeout[curPic->syncInfo.matchPlane[loop]] = osdSyncStamp[curPic->syncInfo.matchPlane[loop]] = 0;
						DBG_PRINT(KERN_EMERG"%s, osdSyncStamp[%d]=%d \n", __FUNCTION__, curPic->syncInfo.matchPlane[loop], osdSyncStamp[loop]);
					}
				}
			} else { /* Normal case for OSD display */
				/*  call GDMA HW setting */
				GDMA_OSDReg_Set(disPlane);
				for (loop = 0; loop < onlineMaxNum; loop++) {
					disPlane_tmp = onlinePlane[loop];
					if (QueueFlag[disPlane_tmp] == 1 && (disPlane_tmp != disPlane) && osdSyncStamp[disPlane_tmp] == 0) {
						GDMA_OSDReg_Set(disPlane_tmp);
					}
				}
			}

			/*  TODO: record the actual updated OSD number */
			for (loop = 0; loop < onlineMaxNum; loop++) {
				disPlane_tmp = onlinePlane[loop];

				if (QueueFlag[disPlane_tmp] == 1 && osdSyncStamp[disPlane_tmp] == 0) {

					Qend = ((gdma->curPic[disPlane_tmp] + GDMA_MAX_PIC_Q_SIZE - 2) & (GDMA_MAX_PIC_Q_SIZE - 1));
					gdma->picCount[disPlane_tmp]--;
					gdma->picQrd[disPlane_tmp] = Qend;

					if (disPlane_tmp == GDMA_PLANE_OSD1)
						updatedOSDx |= GDMA_CTRL_osd1_prog_done(1);
					else if (disPlane_tmp == GDMA_PLANE_OSD2)
						updatedOSDx |= GDMA_CTRL_osd2_prog_done(1);
					else if (disPlane_tmp == GDMA_PLANE_OSD3)
						updatedOSDx |= GDMA_CTRL_osd3_prog_done(1);

#ifdef TRIPLE_BUFFER_SEMAPHORE
					gSemaphore[disPlane_tmp]++;
					if (gSemaphore[disPlane_tmp] > gSEMAPHORE_MAX) {
						pr_debug(KERN_EMERG"gdma : gSemaphore[%d] %d\n", disPlane_tmp, gSemaphore[disPlane_tmp]);
						gSemaphore[disPlane_tmp] = gSEMAPHORE_MAX;
					}
#endif

					/* clear queue flag */
					QueueFlag[disPlane_tmp] = 0;

					cnt++;
				}
			}

			osd_db_ctrl_reg.regValue = rtd_inl(OSDOVL_OSD_Db_Ctrl_reg);
			osd_db_ctrl_reg.db_load = 1;

#if 0//avoid osd confliction
			/* disable other OSD which is NOT used at this moment */
			/* compress case : mouse go to OSD1 */
			if ((updatedOSDx & GDMA_CTRL_osd1_prog_done(1)) == 0)
				rtd_outl(GDMA_OSD1_CTRL_reg, ~1);
			if ((updatedOSDx & GDMA_CTRL_osd2_prog_done(1)) == 0)
				rtd_outl(GDMA_OSD2_CTRL_reg, ~1);
			if ((updatedOSDx & GDMA_CTRL_osd3_prog_done(1)) == 0)
				rtd_outl(GDMA_OSD3_CTRL_reg, ~1);
#endif

#if 0
			/*
			*	check layers status to enable mid-blend
			*/
			GDMA_MidBlendSet(cnt, updatedOSDx);

			/** line buffer calculation
			*   line buffer calculation should be done before writing programming done
			*	due to dynamic line buffer setting, progrmming done will apply with all online path
			*/
			GDMA_LineBufferCal();
#endif

			onlineProgDone = GDMA_CTRL_write_data(1) | GDMA_CTRL_osd_others_prog_done(1);
			/*  only check real online OSD HW */
			onlineProgDone |= GDMA_CTRL_osd1_prog_done(1);
			onlineProgDone |= GDMA_CTRL_osd2_prog_done(1);
			onlineProgDone |= GDMA_CTRL_osd3_prog_done(1);


			/* osd_other_prog_done needs to program with online osd prog done */
			DBG_PRINT(KERN_EMERG"%s, updatedOSDx = 0x%x \n", __FUNCTION__, updatedOSDx);
			DBG_PRINT(KERN_EMERG"%s, w onlineProgDone = 0x%x \n", __FUNCTION__, onlineProgDone);
			DBG_PRINT(KERN_EMERG"%s, w osd_db_ctrl = 0x%x \n", __FUNCTION__, osd_db_ctrl_reg.regValue);
			rtd_outl(OSDOVL_OSD_Db_Ctrl_reg, osd_db_ctrl_reg.regValue); /*  mixer apply */
			rtd_outl(GDMA_CTRL_reg, onlineProgDone);  /*  gdma & sr programming done */
			DBG_PRINT(KERN_EMERG"%s, r rtd_inl(%x)=0x%x\n", __FUNCTION__, GDMA_CTRL_reg, rtd_inl(GDMA_CTRL_reg));

			if ((curPic->cookie != 0) && (cookie_flag != 0) && (gdma->GDMA_CookieCallBack)) {
				/*if (curPic->cookie != 0) {*/
					gdma->GDMA_CookieCallBack (0, curPic->cookie) ;
					curPic->cookie = 0;
				/*}*/
			}
			cookie_flag = 1;		/* delay one frame when really change picture, driver will call the callback */
			/* End - fox modify for use cookie to sync GDMA */
		}

	}

#if 0   /*  frame-rate calculation by Vsync */
	static unsigned int gdmaINT_cnt;
	static unsigned int spentTime, sta;
	if (gdmaINT_cnt == 0 && sta == 0 && updatedOSDx > 0) {
		sta = rtd_inl(SCPU_CLK90K_LO_reg);
		/* Warning("[GDMA] Starting counting for FPS, sta=%d \n", sta); */
	} else {
		if (rtd_inl(SCPU_CLK90K_LO_reg) > sta && updatedOSDx > 0) {
			spentTime = (rtd_inl(SCPU_CLK90K_LO_reg) - sta);
			gdmaINT_cnt++;
		} else if (gdmaINT_cnt < 1000) {
			if (gdmaINT_cnt) {
				DBG_PRINT(KERN_EMERG"[GDMA]FPS=%d, spend time %d, income time %d \n", (gdmaINT_cnt / (spentTime/90000)), spentTime, gdmaINT_cnt);
			}
		}

		if (gdmaINT_cnt >= 1000) {
			pr_debug(KERN_EMERG"[GDMA]FPS=%d, spend time %d, income time %d \n", (gdmaINT_cnt / (spentTime/90000)), spentTime, gdmaINT_cnt);
			sta = spentTime = gdmaINT_cnt = 0;
		}

		/* Warning("[GDMA] Counting , gdmaINT_cnt=%d \n", gdmaINT_cnt); */
	}
#endif


	return GDMA_SUCCESS;
}



int GDMA_Display (GDMA_DISPLAY *cmd)
{
	gdma_dev *gdma = &gdma_devices[0];
	if (cmd->plane == GDMA_PLANE_NONE) {
		gdma->ctrl.zeroBuffer = cmd->zeroBuffer;
		if ((gdma->ctrl.zeroBuffer))
			GDMA_Flush (gdma);
	} else
		gdma->ctrl.zeroBuffer = 0;

	GDMA_ENTER_CRITICAL ();

	GDMA_Hide (gdma);
	gdma->plane = cmd->plane;
	GDMA_Update (gdma, 0);

	GDMA_EXIT_CRITICAL ();

	return GDMA_SUCCESS;
}

int GDMA_OSD1OnTop (bool bOSD1OnTop)
{
	gdma_dev *gdma = &gdma_devices[0];
	unsigned int onlineProgDone = GDMA_CTRL_write_data(1) | GDMA_CTRL_osd_others_prog_done(1);

	GDMA_ENTER_CRITICAL ();
	gdma->ctrl.OSD1onTop = bOSD1OnTop;

	/*  only check online OSD HW */
	rtd_outl(GDMA_OSD1_CTRL_reg, ~1);
	onlineProgDone |= GDMA_CTRL_osd1_prog_done(1);
	rtd_outl(GDMA_OSD2_CTRL_reg, ~1);
	onlineProgDone |= GDMA_CTRL_osd2_prog_done(1);
	rtd_outl(GDMA_OSD3_CTRL_reg, ~1);
	onlineProgDone |= GDMA_CTRL_osd3_prog_done(1);
	rtd_outl(GDMA_CTRL_reg,  onlineProgDone);

	GDMA_Update (gdma, 0);
	GDMA_EXIT_CRITICAL ();

	if (gdma->osdPlane[VO_GRAPHIC_OSD1].OSD_ctrl.en)
		GDMA_UpdateGraphicwindow (1, VO_GRAPHIC_OSD1);
	if (gdma->osdPlane[VO_GRAPHIC_OSD2].OSD_ctrl.en)
		GDMA_UpdateGraphicwindow (1, VO_GRAPHIC_OSD2);
	if (gdma->osdPlane[VO_GRAPHIC_OSD3].OSD_ctrl.en)
		GDMA_UpdateGraphicwindow (1, VO_GRAPHIC_OSD3);
	return GDMA_SUCCESS;
}

int GDMA_Config3D (bool enable3D)
{
	gdma_dev *gdma = &gdma_devices[0];

	gdma->ctrl.enable3D = enable3D;
	if ((gdma->ctrl.enable3D)) {
		/* rtd_outl(GDMA_OSD1_CTRL_reg, GDMA_OSD1_CTRL_write_data(1) | GDMA_OSD1_CTRL_d3_mode (1)); */
		/* rtd_outl(GDMA_OSD2_CTRL_reg, GDMA_OSD2_CTRL_write_data(1) | GDMA_OSD2_CTRL_d3_mode (1)); */
		rtd_outl(GDMA_OSD_INTEN_3D_reg, GDMA_OSD_INTEN_3D_write_data(1) | GDMA_OSD_INTEN_3D_osd1_vact_end(1));
	} else { /* 2D */
		rtd_outl(GDMA_OSD1_CTRL_reg, GDMA_OSD1_CTRL_write_data(0) | GDMA_OSD1_CTRL_d3_mode (1));
		rtd_outl(GDMA_OSD2_CTRL_reg, GDMA_OSD2_CTRL_write_data(0) | GDMA_OSD2_CTRL_d3_mode (1));
		rtd_outl(GDMA_OSD3_CTRL_reg, GDMA_OSD3_CTRL_write_data(0) | GDMA_OSD3_CTRL_d3_mode (1));
		rtd_outl(GDMA_OSD_INTEN_3D_reg, GDMA_OSD_INTEN_3D_write_data(0) | GDMA_OSD_INTEN_3D_osd1_vact_end(1));

		*(volatile u32 *)&gdma->osd3Doffset[0] = 0;
		*(volatile u32 *)&gdma->osd3Doffset[1] = 0;
		*(volatile u32 *)&gdma->osd3Doffset[2] = 0;
		gdma->ctrl.enableOSD1Offset = 0;
		gdma->ctrl.enableOSD2Offset = 0;
		gdma->ctrl.enableOSD3Offset = 0;

		gdma->ctrl.updateOSD1Offset = 0;
		gdma->ctrl.updateOSD2Offset = 0;
		gdma->ctrl.updateOSD3Offset = 0;

#ifndef USING_GDMA_VSYNC
		rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(1) | GDMA_OSD_INTEN_osd1_vact_end(1));
#else
		rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(1) | GDMA_OSD_INTEN_osd1_vsync(1));
#endif

	}

	return GDMA_SUCCESS;
}
#if GDMA_GAMMA
int GDMA_ConfigGammaColorMapping(GAMMA_COLOR_MAPPING_DATA *data)
{
	unsigned int reg;

	rtd_outl(OSDOVL_Mixer_Osd3x3_Data_In_Offset_0_reg,
		OSDOVL_Mixer_Osd3x3_Data_In_Offset_0_x_offset(data->cm_x_offset)|
		OSDOVL_Mixer_Osd3x3_Data_In_Offset_0_y_offset(data->cm_y_offset));

	rtd_outl(OSDOVL_Mixer_Osd3x3_Data_In_Offset_1_reg,
			 OSDOVL_Mixer_Osd3x3_Data_In_Offset_1_z_offset(data->cm_z_offset));

	rtd_outl(OSDOVL_Mixer_Osd3x3_Data_0_reg,
			 OSDOVL_Mixer_Osd3x3_Data_0_k12(data->cm_k12)|
			 OSDOVL_Mixer_Osd3x3_Data_0_k11(data->cm_k11));

	rtd_outl(OSDOVL_Mixer_Osd3x3_Data_1_reg,
			 OSDOVL_Mixer_Osd3x3_Data_1_k21(data->cm_k21)|
			 OSDOVL_Mixer_Osd3x3_Data_1_k13(data->cm_k13));

	rtd_outl(OSDOVL_Mixer_Osd3x3_Data_2_reg,
			 OSDOVL_Mixer_Osd3x3_Data_2_k23(data->cm_k23)|
			 OSDOVL_Mixer_Osd3x3_Data_2_k22(data->cm_k22));

	rtd_outl(OSDOVL_Mixer_Osd3x3_Data_3_reg,
			 OSDOVL_Mixer_Osd3x3_Data_3_k32(data->cm_k32)|
			 OSDOVL_Mixer_Osd3x3_Data_3_k31(data->cm_k31));

	rtd_outl(OSDOVL_Mixer_Osd3x3_Data_4_reg,
			 OSDOVL_Mixer_Osd3x3_Data_4_k33(data->cm_k33));

	rtd_outl(OSDOVL_Mixer_Osd3x3_Out_offset_0_reg,
			 OSDOVL_Mixer_Osd3x3_Out_offset_0_goffset(data->cm_r_offset)|
			 OSDOVL_Mixer_Osd3x3_Out_offset_0_roffset(data->cm_g_offset));

	rtd_outl(OSDOVL_Mixer_Osd3x3_Out_offset_1_reg,
			 OSDOVL_Mixer_Osd3x3_Out_offset_1_boffset(data->cm_b_offset));

	return GDMA_SUCCESS;
}

int GDMA_ConfigGammaPosition(unsigned int data)
{
	unsigned int reg;

	reg = rtd_inl(OSDOVL_Mixer_OSD_GAMMA_CTRL_reg);

	reg &= ~(OSDOVL_Mixer_OSD_GAMMA_CTRL_osd_gamma_position_mask);

	reg |= OSDOVL_Mixer_OSD_GAMMA_CTRL_osd_gamma_position(data);

	rtd_outl(OSDOVL_Mixer_OSD_GAMMA_CTRL_reg,reg);

	return GDMA_SUCCESS;
}




int GDMA_GammaOperation(GDMA_GAMMA_OP* data)
{
	int repeat_cnt = 0;
	unsigned int gamma_reg_base = OSDOVL_Mixer_GAMMA1_CTRL_1_reg;
	unsigned int gamma_reg_port = OSDOVL_Mixer_gamma1_port_reg;
	osdovl_mixer_gamma1_ctrl_1_RBUS gctrl;
	osdovl_mixer_gamma1_port_RBUS gport;


	if(data->gamma_num != 1) {
		gamma_reg_base = OSDOVL_Mixer_GAMMA2_CTRL_1_reg;
		gamma_reg_port = OSDOVL_Mixer_gamma2_port_reg;
	}

	while(1) {
		gctrl.regValue = rtd_inl(gamma_reg_base);

		if(gctrl.gamma1_fifo_empty == 1 || gctrl.gamma1_fifo_full == 1)
			break;
		repeat_cnt++;
		if(repeat_cnt >=10) {
			printk(KERN_ERR"[GDMA] update gamma-%d timeout.", data->gamma_num);
			return -1;
		}
		msleep(3);
	}
	for(repeat_cnt=0; repeat_cnt < data->gamma_size;repeat_cnt++) {
		/*1:wreite,  2:read*/
		gctrl.gamma1_ax_rw_sel = data->op;
		gctrl.gamma1_ax_ch_sel = data->channel;
		rtd_outl(gamma_reg_base,gctrl.regValue);
		gport.gamma1_tab_index = data->gamma_data[repeat_cnt].index;
		gport.gamma1_tab_d0 = data->gamma_data[repeat_cnt].d0;
		gport.gamma1_tab_d1 = data->gamma_data[repeat_cnt].d1;
		rtd_outl(gamma_reg_port,gport.regValue);
	}
	gctrl.gamma1_ax_rw_sel = 0;
	rtd_outl(gamma_reg_base,gctrl.regValue);


	gctrl.regValue = rtd_inl(gamma_reg_base);
	if(gctrl.gamma1_wr_error) {
		printk(KERN_ERR"[GDMA] update gamma-%d timeout.", data->gamma_num);
		return -1;
	}
	return 0;
}
#endif
int GDMA_ConfigVFlip(bool enable)
{
	gdma_dev *gdma = &gdma_devices[0];
	int linecnt_start, linecnt_end = 0;
	unsigned int onlineProgDone = GDMA_CTRL_write_data(1) | GDMA_CTRL_osd_others_prog_done(1);
	unsigned int prog_done_mask = GDMA_CTRL_osd_others_prog_done_mask |
		GDMA_CTRL_osd3_prog_done_mask | GDMA_CTRL_osd1_prog_done_mask;
	unsigned long timeout;

	linecnt_start = (rtd_inl(PPOVERLAY_new_meas0_linecnt_real_reg)&0x1FFF);
	pr_debug("%s, linecnt_start = 0x%x \n", __FUNCTION__, linecnt_start);

	/*  only check online OSD HW */
	rtd_outl(GDMA_OSD1_CTRL_reg, ~1);
	onlineProgDone |= GDMA_CTRL_osd1_prog_done(1);
	rtd_outl(GDMA_OSD2_CTRL_reg, ~1);
	onlineProgDone |= GDMA_CTRL_osd2_prog_done(1);
	rtd_outl(GDMA_OSD3_CTRL_reg, ~1);
	onlineProgDone |= GDMA_CTRL_osd3_prog_done(1);

	rtd_outl(GDMA_CTRL_reg, GDMA_CTRL_write_data(1) | onlineProgDone);

	timeout = jiffies + (HZ/50); /* timeout in 20 ms */
	while (rtd_inl(GDMA_CTRL_reg) & prog_done_mask) {
		rtd_outl(GDMA_OSD1_CTRL_reg, GDMA_OSD1_CTRL_write_data(enable) | GDMA_OSD1_CTRL_rotate (1));
		rtd_outl(GDMA_OSD2_CTRL_reg, GDMA_OSD2_CTRL_write_data(enable) | GDMA_OSD2_CTRL_rotate (1));
		rtd_outl(GDMA_OSD3_CTRL_reg, GDMA_OSD3_CTRL_write_data(enable) | GDMA_OSD3_CTRL_rotate (1));
		gdma->ctrl.enableVFlip = enable;

		if (time_before(jiffies, timeout) == 0) {		/*  over 20 ms */
			linecnt_end = (rtd_inl(PPOVERLAY_new_meas0_linecnt_real_reg)&0x1FFF);
			pr_debug("%s, TimeOut. linecnt_end = 0x%x \n", __FUNCTION__, linecnt_end);
			if (linecnt_start == linecnt_end)   /*  no sync signal by DTG measure */
				break;
		}
	}
	return GDMA_SUCCESS;
}

int GDMA_Debug(KADP_HAL_GAL_CTRL_T *data)
{
	int ret = GDMA_SUCCESS;
	osd_dmem_info dinfo;
	memset(&dinfo,0,sizeof(osd_dmem_info));
	if (data->osdn >= GDMA_PLANE_MAXNUM)
		goto GDMA_DEBUG_OSD_ERR;

	switch (data->type) {
		case GDMA_DBG_CMD_SET_H_SHIFT:
		case GDMA_DBG_CMD_SET_V_SHIFT:
			/*for tv006, need this*/
			break;
		case GDMA_DBG_CMD_OSD_DUMP:
			if (data->osdn == 0)
				goto GDMA_DEBUG_OSD_ERR;
			snprintf(dinfo.fname,128,"%s",data->capinfo.fname);
			/*don't care about size, we read them from win info*/
			ret = gdma_osd_writedump(0,data->osdn, &dinfo, NULL);
			break;
		case GDMA_DBG_CMD_OSD_DUMP_EX:
			if (data->osdn == 0)
				goto GDMA_DEBUG_OSD_ERR;
			/*don't care about size, we read them from win info*/
			snprintf(dinfo.fname,128,"%s",data->capinfo.fname);
			ret = gdma_osd_writedump(1,data->osdn, &dinfo, NULL);
			break;
		case GDMA_DBG_CMD_OSD_DROP:
			OSD_Freeze(data->en);
			break;
		case GDMA_DBG_CMD_OSD_PATTERN:
			OSD_Pattern(data);
			break;
		case GDMA_DBG_CMD_OSD_VFLIP:
			ret = OSD_debug_vflip(data->en);
			break;
		case GDMA_DBG_CMD_OSD_CTRL:
			if(data->osdn == 0) {
				if (data->en)
					rtd_setbits(OSDOVL_Mixer_CTRL2_reg, 1);
				else
					rtd_clearbits(OSDOVL_Mixer_CTRL2_reg, 1);
			}else{
				if (data->en) {
					rtd_setbits(OSDOVL_Mixer_CTRL2_reg, 1<<data->osdn);
				}else{
					rtd_clearbits(OSDOVL_Mixer_CTRL2_reg, 1<<data->osdn);
				}
		}
			rtd_outl(OSDOVL_OSD_Db_Ctrl_reg, 0x3);
		break;
		case GDMA_DBG_CMD_OSD_SWAP:
		{
			unsigned int value = rtd_inl(OSDOVL_Mixer_layer_sel_reg)&0xff000000;
			int cnt = 0;
			for(cnt=0;cnt<6;cnt++) {
				if(data->c[cnt] < GDMA_PLANE_MAXNUM){
					value |= data->c[cnt] <<(cnt*4);
		}
		}
			rtd_outl(OSDOVL_Mixer_layer_sel_reg, value);
			rtd_outl(OSDOVL_OSD_Db_Ctrl_reg, 0x1);
		break;
		}
		case GDMA_DBG_CMD_OSD_CAP2MEM:
			if (data->osdn == 0)
				goto GDMA_DEBUG_OSD_ERR;
			ret = gdma_osd_dmp2mem(data);
		break;
		case GDMA_DBG_CMD_SHOW_INFO:
			ret = gdma_osd_winfo_dump();
		break;
		case GDMA_DBG_CMD_OSD_GET_INFO:
			ret = gdma_osd_winfo_read(data);
		break;
		case GDMA_DBG_CMD_OSD_CTRL_EN:
			ret = GDMA_ConfigOSDxEnable(data->osdn, data->en);
		break;
		default:
		break;
	}
	return ret;
GDMA_DEBUG_OSD_ERR:
	printk(KERN_ERR"OSD-%d is illegal.\n", data->osdn);
	ret = -1;
	return ret;
}

int GDMA_Config3DOffset (CONFIG_3D_OFFSET_STRUCT *data)
{
	gdma_dev *gdma = &gdma_devices[0];
	int i;

	GDMA_ENTER_CRITICAL ();
	if (data->plane == VO_GRAPHIC_OSD1) {
		gdma->osd3Doffset[0].left_dir     =  data->closeToViewer;
		gdma->osd3Doffset[0].left_offset  =  data->offset;
		gdma->osd3Doffset[0].right_dir    = !data->closeToViewer;
		gdma->osd3Doffset[0].right_offset =  data->offset;

		gdma->ctrl.enableOSD1Offset =
			gdma->ctrl.updateOSD1Offset = 1;
	} else if (data->plane == VO_GRAPHIC_OSD2) {
		gdma->osd3Doffset[1].left_dir     =  data->closeToViewer;
		gdma->osd3Doffset[1].left_offset  =  data->offset;
		gdma->osd3Doffset[1].right_dir    = !data->closeToViewer;
		gdma->osd3Doffset[1].right_offset =  data->offset;

		gdma->ctrl.enableOSD2Offset =
			gdma->ctrl.updateOSD2Offset = 1;
	} else if (data->plane == VO_GRAPHIC_OSD3) {
		gdma->osd3Doffset[2].left_dir     =  data->closeToViewer;
		gdma->osd3Doffset[2].left_offset  =  data->offset;
		gdma->osd3Doffset[2].right_dir    = !data->closeToViewer;
		gdma->osd3Doffset[2].right_offset =  data->offset;

		gdma->ctrl.enableOSD3Offset =
			gdma->ctrl.updateOSD3Offset = 1;
	} else if (data->plane == -1) {
		for (i = 0; i < MAX_OSD_NUM; i++) {
			gdma->osd3Doffset[i].left_dir     =  data->closeToViewer;
			gdma->osd3Doffset[i].left_offset  =  data->offset;
			gdma->osd3Doffset[i].right_dir    = !data->closeToViewer;
			gdma->osd3Doffset[i].right_offset =  data->offset;
		}
		gdma->ctrl.enableOSD1Offset = 1;
		gdma->ctrl.updateOSD1Offset = 1;
		gdma->ctrl.enableOSD2Offset = 1;
		gdma->ctrl.updateOSD2Offset = 1;
		gdma->ctrl.enableOSD3Offset = 1;
		gdma->ctrl.updateOSD3Offset = 1;
	}

	GDMA_EXIT_CRITICAL ();

	return GDMA_SUCCESS;
}

int GDMA_ConfigBlending (CONFIG_BLENDING_STRUCT *data)
{

	osdovl_mixer_ctrl2_RBUS mixer_ctrl2;
	*(volatile u32 *)&mixer_ctrl2 = rtd_inl(OSDOVL_Mixer_CTRL2_reg);
#if 0   /*  no blending setting in magellan2 */
	gdma_dev *gdma = &gdma_devices[0];
	if (gdma->ctrl.OSD1onTop) {
		if (data->blendingOSD1En >= 0)
			mixer_ctrl2.MAC3.blendingo2_en    = !data->blendingOSD1En;
		if (data->blendingOSD2En >= 0)
			mixer_ctrl2.MAC3.blendingo1_en    = !data->blendingOSD2En;
	} else {
		if (data->blendingOSD1En >= 0)
			mixer_ctrl2.MAC3.blendingo1_en    = !data->blendingOSD1En;
		if (data->blendingOSD2En >= 0)
			mixer_ctrl2.MAC3.blendingo2_en    = !data->blendingOSD2En;
	}
#endif
	rtd_outl(OSDOVL_Mixer_CTRL2_reg, *(volatile u32 *)&mixer_ctrl2);

	return GDMA_SUCCESS;
}

int GDMA_ConfigureDisplayWindow (GDMA_CONFIG_DISP_WIN *cmd)
{
	gdma_dev *gdma = &gdma_devices[0];
#ifdef CONFIG_CUSTOMER_TV006
	GDMA_PLANE *osdPlane =  NULL;
	if (cmd == NULL)
		return GDMA_FAIL;
	if(cmd->plane >= GDMA_PLANE_MAXNUM)
		return GDMA_FAIL;

	osdPlane = &gdma->osdPlane[cmd->plane];
	osdPlane->OSD_canvas.dispWin = *(VO_RECTANGLE *)&cmd->dispWin;
#else
	VO_RECTANGLE disp_rec;
	if (cmd == NULL)
		return GDMA_FAIL;
	if(cmd->plane >= GDMA_PLANE_MAXNUM)
		return GDMA_FAIL;

	getDispSize(&disp_rec);
		if (gdma->f_box_mode && gdma->box_dst_height == VIDEO_USERDEFINED) {
			memcpy(&gdma->dispWin[cmd->plane], &cmd->dispWin, sizeof(VO_RECTANGLE));
		} else {
			memcpy(&gdma->dispWin[cmd->plane], &disp_rec, sizeof(VO_RECTANGLE));
		}
#endif
	pr_debug(KERN_EMERG"%s, gdma->dispWin[%d].width=%d, %d\n", __FUNCTION__, cmd->plane, gdma->dispWin[cmd->plane].width, gdma->dispWin[cmd->plane].height);

	return GDMA_SUCCESS;
}


/** @brief receive the picture, then send to pic ring-queue and workqueue
 *  @param data the pointer to layer information which want to show
 *  @return GDMA_SUCCESS
 */

/*
 * When OSD shift value is minus (left shift),
 * we need to check right side of cursor shape is visible or not.
 * This lambda returns a value that will be cut at the right side.
 *
 * */

static void gdam_lambda_cursor_shift_h(GDMA_WIN *win, GDMA_PICTURE_OBJECT *picObj){
	int cut_h = 0;
	if(win->dst_x >= abs(g_osdshift_ctrl.h_shift_pixel)) {
		//right side
		cut_h = 3840 - picObj->dst_x;
		if(cut_h <= 0){
			win->dst_x = 0;
			picObj->dst_x = 0;
			win->attr.alpha = 0;
			win->attr.alphaEn = 1;
		}else if (cut_h <= win->winWH.width*2) {
			win->winXY.x = (win->winWH.width-cut_h/2);
			win->dst_x -= win->winXY.x*2;
			win->dst_x -= abs(g_osdshift_ctrl.h_shift_pixel);
			picObj->dst_x = win->dst_x;
		}else {
			//normal case
			win->dst_x -= abs(g_osdshift_ctrl.h_shift_pixel);
			picObj->dst_x = win->dst_x;
		}
	}else{
		//cut_h = x_offset of cursor , left side
		cut_h = (abs(g_osdshift_ctrl.h_shift_pixel) - win->dst_x)/2;
		if(cut_h < win->winWH.width){
			win->dst_x = 0;
			picObj->dst_x = 0;
			win->objOffset.objXoffset = cut_h;
			win->winWH.width -= win->objOffset.objXoffset;
			win->dst_width = win->winWH.width*2;
			picObj->dst_width = win->dst_width;
		}else{
			win->dst_x = 0;
			picObj->dst_x = 0;
			win->attr.alpha = 0;
			win->attr.alphaEn = 1;
		}
	}
	return;
}


static void gdam_lambda_cursor_shift_v(GDMA_WIN *win, GDMA_PICTURE_OBJECT *picObj){
	int cut_v = 0;
	if(win->dst_y >= abs(g_osdshift_ctrl.v_shift_pixel)) {
		//bottom
		cut_v = 2160 - picObj->dst_y;
		if(cut_v <= 0){
			win->dst_y = 0;
			picObj->dst_y = 0;
			win->attr.alpha = 0;
			win->attr.alphaEn = 1;
		}else if (cut_v <= win->winWH.height*2) {
			win->winXY.y = (win->winWH.height-cut_v/2);
			win->dst_y -= win->winXY.y*2;
			win->dst_y -= abs(g_osdshift_ctrl.v_shift_pixel);
			picObj->dst_y = win->dst_y;
		}else{
			//normal case
			win->dst_y -= abs(g_osdshift_ctrl.v_shift_pixel);
			picObj->dst_y -= abs(g_osdshift_ctrl.v_shift_pixel);
		}

	}else{
		//cut_v = y_offset of cursor, up
		cut_v = (abs(g_osdshift_ctrl.v_shift_pixel) - win->dst_y)/2;
		if(cut_v < win->winWH.height){
			win->dst_y = 0;
			picObj->dst_y = 0;
			win->objOffset.objYoffset = cut_v;
			win->winWH.height -= win->objOffset.objYoffset;
			win->dst_height = win->winWH.height*2;
			picObj->dst_height = win->dst_height;
		}else{
			win->dst_y = 0;
			picObj->dst_y = 0;
			win->attr.alpha = 0;
			win->attr.alphaEn = 1;
		}
	}
	return;
}






int GDMA_ReceivePicture (PICTURE_LAYERS_OBJECT *data)
{
	gdma_dev *gdma = &gdma_devices[0];
	GDMA_PIC_DATA *pic = NULL;
	GDMA_WIN *win = NULL, *win3D = NULL;
	COMPOSE_PICTURE_OBJECT *com_picObj = NULL;
	int idx, ilayer, emptyIdx = 0, idxQwr = 0, sema_ret;
	GDMA_PICTURE_OBJECT *picObj = NULL;
	GDMA_DISPLAY_PLANE disPlane = VO_GRAPHIC_OSD1;
	VO_RECTANGLE disp_res;
	int onlinePlane[GDMA_PLANE_MAXNUM], onlineMaxNum = 0;
	unsigned int saveBufAddr = 0;
	unsigned long timeout = jiffies + (HZ/50);	/* 20 ms */
#if defined(CONFIG_RTK_KDRV_GAL)
#ifdef CONFIG_LG_SNAPSHOT_BOOT
	if (reserve_boot_memory == 0)
#endif
	{
		if(bstoplogo == false && (logo_dalay_init_bool_1 == 0) )
		{
			bstoplogo = true;
			printk("\033[1;45m ================== [gdmalogo][%s][%s][%d] ================== \033[0m\n",__FILE__, __FUNCTION__, __LINE__);
			do_dvr_reclaim(2);
		}
	}

	if(logo_do_dvr_reclaim)
	{
		logo_do_dvr_reclaim = 0;
		bstoplogo = true;
		do_dvr_reclaim(2);
		printk("\033[1;45m ================== [gdmalogo logodelayfn do_dvr_reclaim][%s][%s][%d] ================== \033[0m\n",__FILE__, __FUNCTION__, __LINE__);
    	}
#else
#if defined(CONFIG_ARM64)
	unsigned long osdwi = (unsigned long)rtd_inl(GDMA_OSD1_WI_reg);
#else
	unsigned int osdwi = (unsigned int)rtd_inl(GDMA_OSD1_WI_reg);
#endif
	static bool needlogo =true;
	if(osdwi && (osdwi > gdma_dev_addr) && needlogo) {
		needlogo = false;
		printk(KERN_DEBUG"[GDMA]call reclaim, used=%08x  ..\n",osdwi);
		do_dvr_reclaim(1);
		do_dvr_reclaim(2);
	}
#endif

	if(gdrop_counter > 0){
		gdrop_counter--;
		return GDMA_SUCCESS;
	}
	if(gdrop_counter == -1){
		return GDMA_SUCCESS;
	}
	if(gosdpattern ==1 && data != NULL &&
		data->layer[0].normal[0].address != gosdpattern_phy){
		return GDMA_SUCCESS;
	}else if(gosdpattern == 0){
		/*for restore last info after disable osd pattern
		 need to save osd1, osd2, osd3 ?*/
		memcpy(&glastinfo, data, sizeof(PICTURE_LAYERS_OBJECT));
	}
	/* protection to unreasonable parameters */
	if (data->layer_num) {
		if (data->layer[0].normal_num) {
			if (data->layer[0].normal[0].dst_width < data->layer[0].normal[0].width) {
				printk(KERN_EMERG"%s, wrong width size, src=%d, dst=%d\n", __FUNCTION__, data->layer[0].normal[0].width, data->layer[0].normal[0].dst_width);
				return GDMA_FAIL;
			}
			if (data->layer[0].normal[0].dst_height < data->layer[0].normal[0].height) {
				printk(KERN_EMERG"%s, wrong height size, src=%d, dst=%d\n", __FUNCTION__, data->layer[0].normal[0].height, data->layer[0].normal[0].dst_height);
				return GDMA_FAIL;
			}
		}
	}

	/*  DTG timing maybe changed at run-time, so always read DTG timing to decide the panel resolution */
	getDispSize(&disp_res);
	gdma->dispWin[0].width = disp_res.width;
	gdma->dispWin[0].height = disp_res.height;
	DBG_PRINT(KERN_EMERG"%s, Panel [%d,%d]\n", __FUNCTION__, disp_res.width, disp_res.height);
	DBG_PRINT(KERN_EMERG"%s, data->layer_num=%d\n", __FUNCTION__, data->layer_num);

	/*  take care DISPD_GDMA_CLK_SEL (0xB8000208[14]) will use 4K2K or not */
	/*  when 4K2K must select the higher frequency */
	if (disp_res.width >= FOURK_W && disp_res.height >= TWOK_H) {
		/*  TODO: pick higher freq. */
		/*
		 * 1: gdma_clk = dispd-clock div 1
		 * 0: gdma_clk = busH_clk = sysH_clk
		 */
		/*  TODO: this setting move to bootcode stage */
	}

	down(&gdma->sem_receive);
	GDMA_ENTER_CRITICAL();

	/* avoid interrupt routing to SCPU disable within 100 frames */
	if (g_StartCheckFrameCnt) {
		g_StartCheckFrameCnt--;
		//printk(KERN_EMERG"%s, g_StartCheckFrameCnt=%d \n", __FUNCTION__, g_StartCheckFrameCnt);
		if ((rtd_inl(SYS_REG_INT_CTRL_SCPU_reg) & SYS_REG_INT_CTRL_SCPU_osd_int_scpu_routing_en_mask) == 0) {
			printk(KERN_EMERG"%s, GDMA interrupt routing to SCPU disable ! \n", __FUNCTION__);
			rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, SYS_REG_INT_CTRL_SCPU_osd_int_scpu_routing_en_mask | SYS_REG_INT_CTRL_SCPU_write_data(1));
		}
	}

	for (ilayer = 0; ilayer < data->layer_num; ilayer++) {

		/*  search the empty work space */
		for (idx = 0; idx < GDMA_MAX_PIC_Q_SIZE; idx++) {
			if (sGdmaReceiveWork[idx].used == 0) {
				sGdmaReceiveWork[idx].used = 1;
				break;
			}
		}
		emptyIdx = idx;
		DBG_PRINT(KERN_EMERG"%s, emptyIdx=%d\n", __FUNCTION__, emptyIdx);

		if (emptyIdx == GDMA_MAX_PIC_Q_SIZE) {
			pr_debug(KERN_EMERG"%s, Warning! GDMA workqueue is full \n", __FUNCTION__);
			GDMA_EXIT_CRITICAL();
			up(&gdma->sem_receive);
			return COMP_BUF_WORK_FULL;
		}

		com_picObj = &data->layer[ilayer];
		if (com_picObj->normal_num > 0)
			picObj = &com_picObj->normal[0];		/* just one normal OSD for one online path  */
		else if (com_picObj->fbdc_num > 0)
			picObj = &com_picObj->fbdc[0];
		else {
			pr_debug(KERN_EMERG"%s, PICTURE_LAYERS_OBJECT's COMPOSE_PICTURE_OBJECT has NO layer \n", __FUNCTION__);
			GDMA_EXIT_CRITICAL();
			up(&gdma->sem_receive);
			return GDMA_FAIL;
		}

		/*  in this function, one layer has only one picture in certain OSD HW */
		if (com_picObj->normal_num > 0 && com_picObj->fbdc_num > 0)
			pr_debug(KERN_EMERG"%s, PICTURE_LAYERS_OBJECT's COMPOSE_PICTURE_OBJECT layer has something wrong \n", __FUNCTION__);

		if (picObj->layer_used == 1) {
			if (picObj->plane == VO_GRAPHIC_OSD1)
				disPlane = GDMA_PLANE_OSD1;
			else if (picObj->plane == VO_GRAPHIC_OSD2)
				disPlane = GDMA_PLANE_OSD2;
			else if (picObj->plane == VO_GRAPHIC_OSD3)
				disPlane = GDMA_PLANE_OSD3;

			onlinePlane[onlineMaxNum++] = disPlane;
			gdma->dispWin[disPlane].width = disp_res.width;
			gdma->dispWin[disPlane].height = disp_res.height;
			DBG_PRINT("%s, gdma->dispWin[%d].width=%d, height=%d \n", __FUNCTION__, disPlane, gdma->dispWin[disPlane].width, gdma->dispWin[disPlane].height);

			if (gdma->picQrd[disPlane] == ((gdma->picQwr[disPlane] + 1) & (GDMA_MAX_PIC_Q_SIZE - 1))) {
				pr_debug(KERN_EMERG "GDMA: pic Queue %d fullness r %d,w %d,c %d\n", disPlane, gdma->picQrd[disPlane], gdma->picQwr[disPlane], gdma->curPic[disPlane]);
				sGdmaReceiveWork[emptyIdx].used = 0;	/* free work */

				/* drop frames and go ahead for in-stop on firse use
				*  SE maybe block by debug thread, then sends the queued picture very quickly when system not busy
				*/
				pr_debug(KERN_EMERG "GDMA: disPlane=%d pid=%d\n", disPlane, current->pid);
				for (idx = 0; idx < GDMA_MAX_PIC_Q_SIZE; idx++)
					sGdmaReceiveWork[idx].used = 0;
				gdma->picQwr[disPlane] = gdma->curPic[disPlane];
				gdma->picQrd[disPlane] = ((gdma->curPic[disPlane] - 2) & (GDMA_MAX_PIC_Q_SIZE - 1));

				/* return -99; */
				/* continue; */
			} else if (gdma->ctrl.zeroBuffer) {
				DBG_PRINT(KERN_EMERG"GDMA: zeroBuffer is 1\n");
				GDMA_EXIT_CRITICAL();
				sGdmaReceiveWork[emptyIdx].used = 0;	/* free work */
				up(&gdma->sem_receive);
				return GDMA_SUCCESS;
			}
			DBG_PRINT(KERN_EMERG"R\n");

			pic = gdma->pic[disPlane] + (idxQwr = (gdma->picQwr[disPlane] + 1) & (GDMA_MAX_PIC_Q_SIZE - 1));

			memset(pic, 0, sizeof(GDMA_PIC_DATA));

			pic->seg_num = picObj->seg_num;
			pic->current_comp_idx = picObj->current_comp_idx;
			pic->cookie = data->cookie;
			pic->show = picObj->show;
			pic->syncInfo = picObj->syncInfo;
			pic->workqueueDone = 0;
            //RTK mark for netfix
			if(enable_osd1osd3mixerorder)
			{
				if (picObj->plane == VO_GRAPHIC_OSD1)
					pic->onlineOrder = C2;
				else if (picObj->plane == VO_GRAPHIC_OSD3)
					pic->onlineOrder = C0;
				else
					pic->onlineOrder = com_picObj->onlineOrder;
			}
			else
				pic->onlineOrder = com_picObj->onlineOrder;

			pic->clear_x.value = picObj->clear_x.value;
			pic->clear_y.value = picObj->clear_y.value;
			*(char *)&pic->status = 0;
			pic->repeatCnt = 0;
			pic->context   = picObj->context;
			pic->workqueueIdx = emptyIdx;
			pic->isFromOffline = picObj->isFromOffline;
			pic->scale_factor = picObj->scale_factor;

			/*  mixer's plane alpha setting, only for normal OSD */
			/*if (com_picObj->normal_num > 0) */{
				pic->plane_ar.value = picObj->plane_ar.value;
				pic->plane_gb.value = picObj->plane_gb.value;
			}

			win = &pic->OSDwin;
			win3D = &pic->OSDwin3D;

			win->nxtAddr.addr     = 0;
			win->nxtAddr.last     = 1;

			/* win->winXY.x          = (gdma->f_box_mode && gdma->box_dst_height == VIDEO_USERDEFINED)? picObj->x: picObj->dst_x; //picObj->dst_x; //picObj->x; */
			/* win->winXY.y          = (gdma->f_box_mode && gdma->box_dst_height == VIDEO_USERDEFINED)? picObj->y: picObj->dst_y; //picObj->dst_y; //picObj->y; */

			/*  canvas X, Y always set the X, Y from picture */
			/*  destination x, y, width, height are for final resolution and position on panel */
			win->winXY.x          = picObj->x;
			win->winXY.y          = picObj->y;

			win->winWH.width      = picObj->width;
			win->winWH.height     = picObj->height;
			win->attr.extendMode  = 0;
			win->attr.rgbOrder    = picObj->rgb_order;/* VO_OSD_COLOR_RGB; */
			win->attr.objType     = 0;
			win->attr.type        = picObj->format & 0x1f;
			win->attr.littleEndian = picObj->format >> 5;
			win->attr.alphaEn     = (win->attr.alpha   = picObj->alpha) >  0 ? 1 : 0;
			win->pitch            = picObj->pitch;
			//if (gdma->f_palette_update == TRUE)
				win->attr.keepPreCLUT = 0;
			//else
			//	win->attr.keepPreCLUT = 1;
			//gdma->f_palette_update = FALSE;
			win->attr.clut_fmt    = picObj->paletteformat;/* rgba format */
			if (win->attr.type < 3)
				win->CLUT_addr = virt_to_phys(gdma->OSD_CLUT[picObj->paletteIndex]);

			if (picObj->decompress) {
				win->objOffset.objXoffset = 0;
				win->objOffset.objYoffset = 0;
			} else {
				//pr_debug(KERN_EMERG"GDMA, %s,picObj->dst_x=%d picObj->dst_y=%d \n", __FUNCTION__,picObj->dst_x,picObj->dst_y);
				//this for fix when cursor move out of bound of panel(0,0),need do offset.
					if(picObj->dst_x<0){
						win->objOffset.objXoffset = abs(picObj->dst_x);
						picObj->dst_x=0;
					}else{
						win->objOffset.objXoffset = picObj->x;
					}
					if(picObj->dst_y<0){
						win->objOffset.objYoffset = gdma->ctrl.enableVFlip ? 0 : abs(picObj->dst_y);
						picObj->dst_y=0;
					}else{
						win->objOffset.objYoffset = gdma->ctrl.enableVFlip ? 0 : picObj->y;
					}
			}

			win->dst_x = picObj->dst_x;
			win->dst_y = picObj->dst_y;
			// for OSD shift
			if (g_osdshift_ctrl.shift_h_enable && com_picObj->fbdc_num==0) {
				g_osdshift_ctrl.para_h_N = abs(g_osdshift_ctrl.h_shift_pixel) / 2;
				g_osdshift_ctrl.para_h_K = abs(g_osdshift_ctrl.h_shift_pixel) % 2;
				g_osdshift_ctrl.Canvas_H = win->winWH.width;
				if (g_osdshift_ctrl.h_shift_pixel >= 0) {
					/* shift right*/
					if(g_osdshift_ctrl.plane==picObj->plane) {
						win->winWH.width -= (g_osdshift_ctrl.para_h_N);
						/*win->winXY.x += (g_osdshift_ctrl.para_h_N+1);*/
					}else if(VO_GRAPHIC_OSD4==picObj->plane){
						/*osd_sta will add this value*/
						if((picObj->dst_x + g_osdshift_ctrl.h_shift_pixel) >= 3840) {
							win->dst_x = 0;
							picObj->dst_x = 0;
							win->attr.alpha = 0;
							win->attr.alphaEn = 1;
						} else {
							win->dst_x += g_osdshift_ctrl.h_shift_pixel;
							picObj->dst_x = win->dst_x;
						}
					}
				}else{
					/*shift left*/
					if(g_osdshift_ctrl.plane==picObj->plane) {
						win->winWH.width -= (g_osdshift_ctrl.para_h_N);
						win->objOffset.objXoffset += g_osdshift_ctrl.para_h_N;
					}else if(VO_GRAPHIC_OSD4==picObj->plane) {
						gdam_lambda_cursor_shift_h(win, picObj);
					}
				}
			}

			if (g_osdshift_ctrl.shift_v_enable && com_picObj->fbdc_num==0) {
				g_osdshift_ctrl.para_v_N = abs(g_osdshift_ctrl.v_shift_pixel) / 2;
				g_osdshift_ctrl.para_v_K = abs(g_osdshift_ctrl.v_shift_pixel) % 2;
				g_osdshift_ctrl.Canvas_V = win->winWH.height;

				if (g_osdshift_ctrl.v_shift_pixel >= 0) {
					/*shift down*/
					if(g_osdshift_ctrl.plane==picObj->plane) {
						win->winWH.height -= (g_osdshift_ctrl.para_v_N+1);
						/*win->winXY.y += (g_osdshift_ctrl.para_v_N+1);*/
					}else if(VO_GRAPHIC_OSD4==picObj->plane) {
						/*use adjust osd_sta instead of here*/
						if((picObj->dst_y + g_osdshift_ctrl.v_shift_pixel) >= 2160) {
							win->dst_y = 0;
							picObj->dst_y = 0;
							win->attr.alpha = 0;
							win->attr.alphaEn = 1;
						}else {
							win->dst_y += g_osdshift_ctrl.v_shift_pixel;
							picObj->dst_y = win->dst_y;
						}
					}
				}else {
					/*shift up*/
					if(g_osdshift_ctrl.plane==picObj->plane) {
						win->winWH.height -= (g_osdshift_ctrl.para_v_N);
						win->objOffset.objYoffset += (g_osdshift_ctrl.para_v_N);
					}else if(VO_GRAPHIC_OSD4==picObj->plane) {
						gdam_lambda_cursor_shift_v(win, picObj);
					}
				}
			}

			/*  destination width/height set as the panel resolution */
			if (picObj->dst_width == 0)     /*  0 means scaling to panel resolution */
				win->dst_width = disp_res.width;
			else
				win->dst_width = picObj->dst_width;
			if (picObj->dst_height == 0)    /*  0 means scaling to panel resolution */
				win->dst_height = disp_res.height;
			else
				win->dst_height = picObj->dst_height;

			win->attr.compress = picObj->decompress;
			win->used = 1;

			if (win->attr.compress) {
				win->colorKey.keyEn   = picObj->key_en;
				win->colorKey.key     = picObj->colorkey;
			} else {
				win->colorKey.keyEn   = (picObj->colorkey != -1);
				win->colorKey.key     = picObj->colorkey;
			}


			saveBufAddr = win->top_addr         = picObj->address + (gdma->ctrl.enableVFlip ? picObj->y + picObj->height - 1 : 0) * picObj->pitch;

//for ANDROIDTV-305 test
			if(saveBufAddr >= (unsigned int)gdma_total_ddr_size){
				dump_stack();
				printk(KERN_EMERG"%s, saveBufAddr=%x is over OSD_MAX_PHY_ADDR(%08x) \n", __FUNCTION__,saveBufAddr,(unsigned int)gdma_total_ddr_size);
				GDMA_EXIT_CRITICAL();
				up(&gdma->sem_receive);
				return GDMA_FAIL;
			}

			if (win->attr.compress && pic->isFromOffline) {
				win->attr.objType     =  (pic->seg_num > 0) ? 1 : 0;
				win->top_addr         = picObj->seg_addr[0];
				win->bot_addr         = picObj->seg_addr[1];
			}

			/*  3D mode configuration */
			if (gdma->ctrl.enable3D) {
				/*  3d mode test */
				/* picObj->picLayout = INBAND_CMD_GRAPHIC_SIDE_BY_SIDE; */
				/* picObj->picLayout = INBAND_CMD_GRAPHIC_TOP_AND_BOTTOM; */

				/*  1: PR mode */
				if (gdma->ctrl.enable3D_PR_SGMode) {
					if (picObj->picLayout == INBAND_CMD_GRAPHIC_TOP_AND_BOTTOM) {
						pr_debug(KERN_EMERG"GDMA, %s, Not support top-bottom in PR mode \n", __FUNCTION__);
					} else if (picObj->picLayout == INBAND_CMD_GRAPHIC_SIDE_BY_SIDE) {
						win->winWH.width = picObj->width >> 1;
						win->pitch >>= 1;
						win->objOffset.objXoffset += win3D->winWH.width;
					}
				} else {	/*  0: SG mode */
					memcpy(win3D, win, sizeof(GDMA_WIN));

					if (picObj->picLayout == INBAND_CMD_GRAPHIC_TOP_AND_BOTTOM) {
						win3D->winWH.height = win->winWH.height = picObj->height >> 1;
						if (gdma->ctrl.enableVFlip)
							win3D->top_addr -= (win3D->winWH.height * win3D->pitch);
						else
							win->objOffset.objYoffset += win3D->winWH.height;
					} else if (picObj->picLayout == INBAND_CMD_GRAPHIC_SIDE_BY_SIDE) {
						win3D->winWH.width = win->winWH.width = picObj->width >> 1;
						win->objOffset.objXoffset += win3D->winWH.width;
						win3D->pitch = win->pitch;
					}
				}
			}

			win->fbdc_attr.pre_blend_c0_sel = 1;
			win->fbdc_attr.pre_blend_c1_sel = 2;
			win->fbdc_attr.pre_blend_c2_sel = 3;

			/*  TODO: FBDC information */
			win->attr.IMGcompress =  (com_picObj->fbdc_num > 0) ? 1 : 0;
			if (win->attr.IMGcompress) {
				win->attr.type = VO_OSD_COLOR_FORMAT_ARGB8888 & 0x1f;
				win->attr.littleEndian = VO_OSD_COLOR_FORMAT_ARGB8888 >> 5;
				win->attr.alphaEn = 0;		/* FBDC has alpha fucntion itself */
				win->attr.alpha = 0;		/* FBDC has alpha fucntion itself */
				win->CLUT_addr = 0;
				win->dst_x = win->dst_y = 0;
			}
			for (idx = 0; idx < com_picObj->fbdc_num; idx++) {
				if (idx < 3)
					picObj = &com_picObj->fbdc[idx];
				else {
					printk(KERN_EMERG"%s, too many FBDC layer into one OSD plane \n", __FUNCTION__);
					GDMA_EXIT_CRITICAL();
					up(&gdma->sem_receive);
					return GDMA_FAIL;
				}

				if (idx == 0) {     /*  FBDC1 */
					win->fbdc_attr.pre_blend_en = 1;    /*  enable pre_blend */
					win->fbdc1_addr = picObj->address + (gdma->ctrl.enableVFlip ? picObj->y + picObj->height - 1 : 0) * picObj->pitch;
					win->fbdc_attr.fbdc_1st_en = 1;
					win->fbdc_attr.const_a_1st = ((win->fbdc_attr.alpha_1st = picObj->alpha) > 0) ? 1 : 0;
					win->fbdc_attr.plane_alpha_c0 = (picObj->plane_ar.plane_alpha_a != 0xff || picObj->plane_ar.plane_alpha_r != 0xff ||
													 picObj->plane_gb.plane_alpha_g != 0xff || picObj->plane_gb.plane_alpha_b != 0xff) ? 1 : 0;
					win->fbdc_plane_alpha_c2.plane_alpha_a = (picObj->plane_ar.plane_alpha_a > 255) ? 255 : picObj->plane_ar.plane_alpha_a;
					win->fbdc_plane_alpha_c2.plane_alpha_r = (picObj->plane_ar.plane_alpha_r > 255) ? 255 : picObj->plane_ar.plane_alpha_r;
					win->fbdc_plane_alpha_c2.plane_alpha_g = (picObj->plane_gb.plane_alpha_g > 255) ? 255 : picObj->plane_gb.plane_alpha_g;
					win->fbdc_plane_alpha_c2.plane_alpha_b = (picObj->plane_gb.plane_alpha_b > 255) ? 255 : picObj->plane_gb.plane_alpha_b;
					/*win->fbdc_attr.pre_blend_c0_sel = 1;*/
					win->fbdc_format.fbdc_fmt_1st = picObj->fbdc_format;
					win->fbdc1_totaltile.x_total_tile = (picObj->width / 16);

					win->fbdc1_totaltile.y_total_tile = (picObj->height / 4);

					win->fbdc1_xy_pixel.x_pic_pixel = picObj->width;
					win->fbdc1_xy_pixel.y_pic_pixel = picObj->height;
					win->fbdc1_xy_sta.x_sta = picObj->x;
					win->fbdc1_xy_sta.y_sta = (gdma->ctrl.enableVFlip ? (picObj->height-1) : picObj->y);
					win->fbdc1_preblend_xy_sta.x_sta = picObj->dst_x/picObj->scale_factor;
					win->fbdc1_preblend_xy_sta.y_sta = picObj->dst_y/picObj->scale_factor;
					// for OSD shift
					if (g_osdshift_ctrl.shift_h_enable && g_osdshift_ctrl.plane==picObj->plane) {
						win->fbdc1_xy_pixel.x_pic_pixel -= abs(g_osdshift_ctrl.h_shift_pixel);
						if (g_osdshift_ctrl.h_shift_pixel > 0)	// shift right
							win->fbdc1_preblend_xy_sta.x_sta += g_osdshift_ctrl.h_shift_pixel;
						else	// shift left
							win->fbdc1_xy_sta.x_sta += abs(g_osdshift_ctrl.h_shift_pixel);
					}
					if (g_osdshift_ctrl.shift_v_enable && g_osdshift_ctrl.plane==picObj->plane) {
						win->fbdc1_xy_pixel.y_pic_pixel -= abs(g_osdshift_ctrl.v_shift_pixel);
						if (g_osdshift_ctrl.v_shift_pixel > 0)	// shift down
							win->fbdc1_preblend_xy_sta.y_sta += g_osdshift_ctrl.v_shift_pixel;
						else	// shift up
							win->fbdc1_xy_sta.y_sta += abs(g_osdshift_ctrl.v_shift_pixel);
					}

					pr_debug(KERN_EMERG" [GDMA] FBDC1 addr = %08x\n ",win->fbdc1_addr);

				} else if (idx == 1) { /*  FBDC2 */
					win->fbdc2_addr = picObj->address + (gdma->ctrl.enableVFlip ? picObj->y + picObj->height - 1 : 0) * picObj->pitch;
					win->fbdc_attr.fbdc_2nd_en = 1;
					win->fbdc_attr.const_a_2nd = ((win->fbdc_attr.alpha_2nd = picObj->alpha) > 0) ? 1 : 0;
					win->fbdc_attr.plane_alpha_c1 = (picObj->plane_ar.plane_alpha_a != 0xff || picObj->plane_ar.plane_alpha_r != 0xff ||
													 picObj->plane_gb.plane_alpha_g != 0xff || picObj->plane_gb.plane_alpha_b != 0xff) ? 1 : 0;
					win->fbdc_plane_alpha_c1.plane_alpha_a = (picObj->plane_ar.plane_alpha_a > 255) ? 255 : picObj->plane_ar.plane_alpha_a;
					win->fbdc_plane_alpha_c1.plane_alpha_r = (picObj->plane_ar.plane_alpha_r > 255) ? 255 : picObj->plane_ar.plane_alpha_r;
					win->fbdc_plane_alpha_c1.plane_alpha_g = (picObj->plane_gb.plane_alpha_g > 255) ? 255 : picObj->plane_gb.plane_alpha_g;
					win->fbdc_plane_alpha_c1.plane_alpha_b = (picObj->plane_gb.plane_alpha_b > 255) ? 255 : picObj->plane_gb.plane_alpha_b;
					/*win->fbdc_attr.pre_blend_c1_sel = 2;*/
					win->fbdc_format.fbdc_fmt_2nd = picObj->fbdc_format;
					win->fbdc2_totaltile.x_total_tile = (picObj->width / 16);
					win->fbdc2_totaltile.y_total_tile = (picObj->height / 4);
					win->fbdc2_xy_pixel.x_pic_pixel = picObj->width;
					win->fbdc2_xy_pixel.y_pic_pixel = picObj->height;
					win->fbdc2_xy_sta.x_sta = picObj->x;
					win->fbdc2_xy_sta.y_sta = (gdma->ctrl.enableVFlip ? (picObj->height-1) : picObj->y);
					win->fbdc2_preblend_xy_sta.x_sta = picObj->dst_x/picObj->scale_factor;
					win->fbdc2_preblend_xy_sta.y_sta = picObj->dst_y/picObj->scale_factor;
					// for OSD shift
					if (g_osdshift_ctrl.shift_h_enable && g_osdshift_ctrl.plane==picObj->plane) {
						win->fbdc2_xy_pixel.x_pic_pixel -= abs(g_osdshift_ctrl.h_shift_pixel);
						if (g_osdshift_ctrl.h_shift_pixel > 0)	// shift right
							win->fbdc2_preblend_xy_sta.x_sta += g_osdshift_ctrl.h_shift_pixel;
						else	// shift left
							win->fbdc2_xy_sta.x_sta += abs(g_osdshift_ctrl.h_shift_pixel);
					}
					if (g_osdshift_ctrl.shift_v_enable && g_osdshift_ctrl.plane==picObj->plane) {
						win->fbdc2_xy_pixel.y_pic_pixel -= abs(g_osdshift_ctrl.v_shift_pixel);
						if (g_osdshift_ctrl.v_shift_pixel > 0)	// shift down
							win->fbdc2_preblend_xy_sta.y_sta += g_osdshift_ctrl.v_shift_pixel;
						else	// shift up
							win->fbdc2_xy_sta.y_sta += abs(g_osdshift_ctrl.v_shift_pixel);
					}

					pr_debug(KERN_EMERG" [GDMA] FBDC2 addr = %08x\n ",win->fbdc2_addr);
				} else if (idx == 2) { /*  FBDC3 */
					win->fbdc3_addr = picObj->address + (gdma->ctrl.enableVFlip ? picObj->y + picObj->height - 1 : 0) * picObj->pitch;
					win->fbdc_attr.fbdc_3rd_en = 1;
					win->fbdc_attr.const_a_3rd = ((win->fbdc_format.alpha_3rd = picObj->alpha) > 0) ? 1 : 0;
					win->fbdc_attr.plane_alpha_c2 = (picObj->plane_ar.plane_alpha_a != 0xff || picObj->plane_ar.plane_alpha_r != 0xff ||
													 picObj->plane_gb.plane_alpha_g != 0xff || picObj->plane_gb.plane_alpha_b != 0xff) ? 1 : 0;
					win->fbdc_plane_alpha_c0.plane_alpha_a = (picObj->plane_ar.plane_alpha_a > 255) ? 255 : picObj->plane_ar.plane_alpha_a;
					win->fbdc_plane_alpha_c0.plane_alpha_r = (picObj->plane_ar.plane_alpha_r > 255) ? 255 : picObj->plane_ar.plane_alpha_r;
					win->fbdc_plane_alpha_c0.plane_alpha_g = (picObj->plane_gb.plane_alpha_g > 255) ? 255 : picObj->plane_gb.plane_alpha_g;
					win->fbdc_plane_alpha_c0.plane_alpha_b = (picObj->plane_gb.plane_alpha_b > 255) ? 255 : picObj->plane_gb.plane_alpha_b;
					/*win->fbdc_attr.pre_blend_c2_sel = 3;*/
					win->fbdc_format.fbdc_fmt_3rd = picObj->fbdc_format;
					win->fbdc3_totaltile.x_total_tile = (picObj->width / 16);
					win->fbdc3_totaltile.y_total_tile = (picObj->height / 4);
					win->fbdc3_xy_pixel.x_pic_pixel = picObj->width;
					win->fbdc3_xy_pixel.y_pic_pixel = picObj->height;
					win->fbdc3_xy_sta.x_sta = picObj->x;
					win->fbdc3_xy_sta.y_sta = (gdma->ctrl.enableVFlip ? (picObj->height-1) : picObj->y);
					win->fbdc3_preblend_xy_sta.x_sta = picObj->dst_x/picObj->scale_factor;
					win->fbdc3_preblend_xy_sta.y_sta = picObj->dst_y/picObj->scale_factor;

					// for OSD shift
					if (g_osdshift_ctrl.shift_h_enable && g_osdshift_ctrl.plane==picObj->plane) {
						win->fbdc3_xy_pixel.x_pic_pixel -= abs(g_osdshift_ctrl.h_shift_pixel);
						if (g_osdshift_ctrl.h_shift_pixel > 0)	// shift right
							win->fbdc3_preblend_xy_sta.x_sta += g_osdshift_ctrl.h_shift_pixel;
						else	// shift left
							win->fbdc3_xy_sta.x_sta += abs(g_osdshift_ctrl.h_shift_pixel);
					}
					if (g_osdshift_ctrl.shift_v_enable && g_osdshift_ctrl.plane==picObj->plane) {
						win->fbdc3_xy_pixel.y_pic_pixel -= abs(g_osdshift_ctrl.v_shift_pixel);
						if (g_osdshift_ctrl.v_shift_pixel > 0)	// shift down
							win->fbdc3_preblend_xy_sta.y_sta += g_osdshift_ctrl.v_shift_pixel;
						else	// shift up
							win->fbdc3_xy_sta.y_sta += abs(g_osdshift_ctrl.v_shift_pixel);
					}

					pr_debug(KERN_EMERG" [GDMA] FBDC3 addr = %08x\n ",win->fbdc3_addr);
				}

				/* calculate the canvas size */
				win->winWH.width      = ((picObj->width+picObj->dst_x) > win->winWH.width) ? (picObj->width+picObj->dst_x) : win->winWH.width;
				win->winWH.height     = ((picObj->height+picObj->dst_y) > win->winWH.height) ? (picObj->height+picObj->dst_y) : win->winWH.height;
			}
			/*  k blend factor for FBDC */
			win->fbdc_blend1st.k1_blend = 0xc;
			win->fbdc_blend1st.k2_blend = 0x3;
			win->fbdc_blend1st.k3_blend = 0x2d;
			win->fbdc_blend1st.k4_blend = 0x3;
			win->fbdc_blend2nd.k1_blend = 0xc;
			win->fbdc_blend2nd.k2_blend = 0x3;
			win->fbdc_blend2nd.k3_blend = 0x2d;
			win->fbdc_blend2nd.k4_blend = 0x3;

			/* check OSD over panel resolution */
			/*
			pr_debug(KERN_EMERG" [GDMA] picObj->dst_x=%d, picObj->dst_width=%d, picObj->width=%d ! \n ", picObj->dst_x, picObj->dst_width, picObj->width);
			pr_debug(KERN_EMERG" [GDMA] picObj->dst_y=%d, picObj->dst_height=%d, picObj->height=%d ! \n ", picObj->dst_y, picObj->dst_height, picObj->height);
			*/
			if (((picObj->dst_x+picObj->dst_width) > disp_res.width)) {
				/* change image width in osd windows info.  */
				if (picObj->dst_width > picObj->width) {
#if 1
					win->winWH.width = (unsigned int)((disp_res.width - picObj->dst_x) / (picObj->dst_width / picObj->width));
#else
					S4AP
					win->winWH.width = (unsigned int)((disp_res.width - picObj->dst_x) /3*2);
#endif
					if (win->winWH.width < 16)		/* OSD_SR input width size minimal 16 */
						win->winWH.width = 16;
#if 1
					win->dst_width = picObj->dst_width = (win->winWH.width * (picObj->dst_width / picObj->width));
#else
					win->dst_width = picObj->dst_width = (unsigned int)(win->winWH.width *3/2); //* (picObj->dst_width / picObj->width));
#endif
					if((disp_res.width - picObj->dst_x - win->dst_width) >=1) {
						win->dst_width = picObj->dst_width +=(disp_res.width - picObj->dst_x - win->dst_width);
					}

					if ((picObj->dst_x+picObj->dst_width) > disp_res.width)
						win->dst_x = picObj->dst_x = picObj->dst_x - ((picObj->dst_x+picObj->dst_width)-disp_res.width);
				} else if (picObj->dst_width <= win->winWH.width)
					win->winWH.width = win->dst_width = picObj->dst_width = disp_res.width - picObj->dst_x;

				/*pr_debug(KERN_EMERG"[GDMA]--> win->dst_x=%d, win->dst_width=%d, win->winWH.width=%d ! \n ", win->dst_x, win->dst_width, win->winWH.width);*/
				//printk(KERN_ERR "[GDMA]--> win->dst_x=%d, win->dst_width=%d, win->winWH.width=%d ! \n ", win->dst_x, win->dst_width, win->winWH.width);
			}
			if (((picObj->dst_y+picObj->dst_height) > disp_res.height)) {
				/* change image height in osd windows info.  */
				if (picObj->dst_height > picObj->height) {
#if 1
					win->winWH.height = ((disp_res.height - picObj->dst_y) / (picObj->dst_height / picObj->height));
#else
					win->winWH.height = ((disp_res.height - picObj->dst_y) /3*2); // (picObj->dst_height / picObj->height));
#endif
					if (win->winWH.height < 4)		/* OSD_SR input height size minimal 4 */
						win->winWH.height = 4;
#if 1
					win->dst_height = picObj->dst_height = (win->winWH.height * (picObj->dst_height / picObj->height));
#else
					win->dst_height = picObj->dst_height = (win->winWH.height *3/2);//* (picObj->dst_height / picObj->height));
#endif
					if((disp_res.height - picObj->dst_y - win->dst_height) >=1){
						win->dst_height = picObj->dst_height+=(disp_res.height - picObj->dst_y - win->dst_height);
					}
					picObj->dst_height = win->dst_height;
				} else if (picObj->dst_height <= win->winWH.height)
					win->winWH.height = win->dst_height = picObj->dst_height = disp_res.height - picObj->dst_y;

				//printk(KERN_ERR "[GDMA]--> win->dst_y=%d, win->dst_height=%d, win->winWH.height=%d ! \n ", win->dst_y, win->dst_height, win->winWH.height);
			}

#if !defined(CONFIG_ARM64)
			dsb();
#endif
			DBG_PRINT(KERN_EMERG"%s, disPlane=%d win->attr.compress=%d \n", __FUNCTION__, disPlane, win->attr.compress);
			DBG_PRINT(KERN_EMERG"%s, pic->seg_num = %d, pic->context = %d\n", __FUNCTION__, pic->seg_num, pic->context);
			DBG_PRINT(KERN_EMERG"%s, win->winWH.width = %d, win->winWH.height= %d\n", __FUNCTION__, win->winWH.width, win->winWH.height);
			DBG_PRINT(KERN_EMERG"%s, win->dst_width = %d, win->dst_height= %d\n", __FUNCTION__, win->dst_width, win->dst_height);
			DBG_PRINT(KERN_EMERG"%s, win->pitch(fbdc3 addr) = %d,  win->attr.compress = %d\n", __FUNCTION__, win->pitch, win->attr.compress);
			DBG_PRINT(KERN_EMERG"%s, win->top_addr(fbdc1 addr) = 0x%x,  win->bot_addr(fbdc2 addr) = 0x%x\n", __FUNCTION__, win->top_addr, win->bot_addr);
			DBG_PRINT(KERN_EMERG"%s, picObj->alpha=0x%x, pic->show = %d\n", __FUNCTION__, picObj->alpha, pic->show);
			DBG_PRINT(KERN_EMERG"%s, pic->syncstamp=%lld, matchnum=%d \n", __FUNCTION__, pic->syncInfo.syncstamp, pic->syncInfo.matchNum);

			gdma->picCount[disPlane]++;
			gdma->picQwr[disPlane] = idxQwr;
			DBG_PRINT(KERN_EMERG"%s, gdma->picQwr[%d]=%d \n", __FUNCTION__, disPlane, gdma->picQwr[disPlane]);

			/*  push work to workqueue */
			sGdmaReceiveWork[emptyIdx].disPlane = disPlane;
			sGdmaReceiveWork[emptyIdx].picQwr = idxQwr;
			/*
			*	Does NOT use workqueue mechanism to avoid system block sometimes
			*	driver calculates the register value immediately
			*/
			GDMA_PreUpdate(&(sGdmaReceiveWork[emptyIdx].GdmaReceiveWork));

#ifdef TRIPLE_BUFFER_SEMAPHORE
			gSemaphore[disPlane]--;
			if (gSemaphore[disPlane] < 0) {
				pr_debug(KERN_EMERG"gdma : gSemaphore[%d] %d\n", disPlane, gSemaphore[disPlane]);
				gSemaphore[disPlane] = 0;
			}

			if (gSemaphore[disPlane] == 0)
				if (!gdma->pendingRPC[disPlane])
					gdma->pendingRPC[disPlane] = 1;
#endif
			if (rtd_inl(SYS_REG_INT_CTRL_SCPU_reg) & SYS_REG_INT_CTRL_SCPU_osd_int_scpu_routing_en_mask)    // for debug
				GDMA_Update(gdma, 1);
			else {
				for (idx = 0; idx < GDMA_MAX_PIC_Q_SIZE; idx++)
					sGdmaReceiveWork[idx].used = 0;
				gdma->curPic[disPlane] = gdma->picQwr[disPlane];
				gdma->picQrd[disPlane] = ((gdma->curPic[disPlane] - 2) & (GDMA_MAX_PIC_Q_SIZE - 1));
				gdma->picCount[disPlane] = 0;
			}

		} else
			pr_debug(KERN_EMERG"%s, No layer in use \n", __FUNCTION__);
	}

	DBG_PRINT(KERN_EMERG"%s, layer loop done \n", __FUNCTION__);
	GDMA_EXIT_CRITICAL();
	up(&gdma->sem_receive);

#ifdef TRIPLE_BUFFER_SEMAPHORE
	DBG_PRINT(KERN_EMERG"%s, online updated picture MaxNum=%d  \n", __FUNCTION__, onlineMaxNum);

	/*
	*	when multi-layer come in GDMA_ReceivePicture, and certain layer has syncstamp
	*	In case of such condition, semaphore wait will take more time here
	*/
	for (idx = 0; idx < onlineMaxNum; idx++) {
		disPlane = onlinePlane[idx];
		//if (gSemaphore[disPlane] == 0) {
		//	if (!gdma->pendingRPC[disPlane]) {
		//		gdma->pendingRPC[disPlane] = 1;
				//GDMA_EXIT_CRITICAL();

				sema_ret = down_timeout(&gdma->updateSem[disPlane], msecs_to_jiffies(32));

				// to avoid the down_timeout is not accurate
				timeout = jiffies + (HZ/50);	/* 20 ms */
				while (rtd_inl(GDMA_CTRL_reg) && (disPlane==GDMA_PLANE_OSD1)) {
					rtd_outl(GDMA_DBG_WI_INFO_reg, disPlane);
					if (saveBufAddr == rtd_inl(GDMA_DBG_OSD_WI_2_reg))
						break;
					if (time_before(jiffies, timeout) == 0)
						break;
					msleep(1);
				}

				if (sema_ret == -ETIME) {
					gdma->pendingRPC[disPlane] = 0;
					gSemaphore[disPlane]  = gSEMAPHORE_MAX;
				}

				if(disPlane==GDMA_PLANE_OSD1)
					gdma_to_dump();


		//	}
		//}
	}

	//GDMA_EXIT_CRITICAL();

#if 0	/* vsync checker */
	/* check now osd physical address */
	unsigned int phyaddr;
	static unsigned int saveaddr = 0;
	volatile unsigned int *ptr;
	volatile unsigned int addr_tmp;
	addr_tmp = phys_to_virt(rtd_inl(GDMA_OSD1_WI_reg));
	ptr = (unsigned int *)addr_tmp;
	ptr += 6;

	/*Warning(KERN_EMERG"physical 0x%x \n", *ptr); */

	phyaddr = win->top_addr;
	if (phyaddr != *ptr)	/* check vsync wait */
		pr_debug(KERN_EMERG"rec 0x%x osd_hw 0x%x \n", phyaddr, *ptr);

	if (disPlane == GDMA_PLANE_OSD1) {
		if (saveaddr == 0)
			saveaddr = phyaddr;
		else {
			if (saveaddr == phyaddr)	/* check buffer swapping */
				pr_debug(KERN_EMERG"ERROR: the same with previous picture. save & phy=0x%x \n", saveaddr);
			else
				saveaddr = phyaddr;
		}
	}
#endif
	//up(&gdma->sem_receive);
#else
	GDMA_EXIT_CRITICAL();
	//up(&gdma->sem_receive);
#endif

	DBG_PRINT(KERN_EMERG"%s, finish \n", __FUNCTION__);
	return GDMA_SUCCESS;
}



int GDMA_ReceiveCmd (GDMA_CMD_TYPE type, void *cmd)
{
	gdma_dev *gdma = &gdma_devices[0];
	switch (type) {
	case GDMA_SET_DISPLAY_MODE:
		gdma->ctrl.displayEachPic = ((GDMA_DISPLAY_MODE_STRUCT *)cmd)->displayEachPic;
		break;
	default:
		pr_debug(KERN_EMERG"GDMA: unsupport command type %d\n", type);
		break;
	}

	return GDMA_SUCCESS;
}
int GDMA_Lock_Vsync_Sem()
{
	/* int try_lock_max=SYN_TRY_MAX; */
	int ret;
	gdma_dev *gdma = &gdma_devices[0];

	/* pr_debug(KERN_EMERG"func=%s line=%d \n", __FUNCTION__, __LINE__); */
	/* gdma->vsync_enable = 1; */
	/* down(&gdma->vsync_sem); */
	ret = down_timeout(&gdma->vsync_sem, msecs_to_jiffies(1000));
	/* pr_debug(KERN_EMERG"func=%s line=%d \n", __FUNCTION__, __LINE__); */
	/* mutex_lock(&gdma_vsync_lock); */
	return 1;
}
int GDMA_ConfigInputSrc_4k2k (bool flag)
{
	gdma_dev *gdma = &gdma_devices[0];

	if (flag != gdma->f_inputsrc_4k2k) { /* input source change */
		gdma->f_inputsrc_4k2k = flag;
	}

	return GDMA_SUCCESS;
}

int GDMA_Config3dUi (bool flag)
{
	gdma_dev *gdma = &gdma_devices[0];
	gdma->f_3d_ui = flag;

	DBG_PRINT(KERN_EMERG"%s--%d gdma->f_3d_ui=%d,\n", __FUNCTION__, __LINE__, gdma->f_3d_ui);

	return GDMA_SUCCESS;
}

int GDMA_ConfigBoxSrcSize(int size)
{
	gdma_dev *gdma = &gdma_devices[0];
	gdma->box_src_height = size;

	return GDMA_SUCCESS;
}

int GDMA_ConfigBoxDstSize(int size)
{
	int ret = GDMA_SUCCESS;
/*
	gdma_dev *gdma = &gdma_devices[0];
	if (ret == GDMA_SUCCESS) {
		gdma->box_dst_height = size;
		gdma->f_box_mode = TRUE;
	} else {
		gdma->f_box_mode = FALSE;
	}
*/
	return ret;
}

int GDMA_ConfigOSDxMixerEnable(GDMA_DISPLAY_PLANE disPlane, bool flag)
{
	volatile osdovl_osd_db_ctrl_RBUS osd_db_ctrl_reg;
	int ltimeout =0xff;
	osdovl_mixer_ctrl2_RBUS mixer_ctrl2;
	/* disable OSD1/OSD2 on Mixer */
	*(volatile u32 *)&mixer_ctrl2 = rtd_inl(OSDOVL_Mixer_CTRL2_reg);

	if (disPlane == GDMA_PLANE_OSD1) {
	        mixer_ctrl2.mixero1_en = flag;
	} else if (disPlane == GDMA_PLANE_OSD2) {
	        mixer_ctrl2.mixero2_en = flag;
	} else if (disPlane == GDMA_PLANE_OSD3) {
	        mixer_ctrl2.mixero3_en = flag;
	}
	rtd_outl(OSDOVL_Mixer_CTRL2_reg, *(volatile u32 *)&mixer_ctrl2);
	osd_db_ctrl_reg.regValue = rtd_inl(OSDOVL_OSD_Db_Ctrl_reg);
	osd_db_ctrl_reg.db_load = 1;

	rtd_outl(OSDOVL_OSD_Db_Ctrl_reg, osd_db_ctrl_reg.regValue); /*  mixer apply */

	osd_db_ctrl_reg.regValue = rtd_inl(OSDOVL_OSD_Db_Ctrl_reg);

	if (flag == false) {
		while(osd_db_ctrl_reg.db_load && ltimeout--){
		    osd_db_ctrl_reg.regValue = rtd_inl(OSDOVL_OSD_Db_Ctrl_reg);
		    mdelay(1);
		}
	}

	DBG_PRINT(KERN_EMERG"%s, %d, MIXER             0x%x\n", __FUNCTION__, __LINE__, rtd_inl(OSDOVL_Mixer_CTRL2_reg));
	return GDMA_SUCCESS;
}

int GDMA_ConfigOSD1OSD3MixerOrder(bool flag)
{
    //RTK mark for netfix
	enable_osd1osd3mixerorder = flag;
	return 0;
}

int GDMA_ConfigOSDxMixerEnableNoDelay(GDMA_DISPLAY_PLANE disPlane, bool flag)
{
	volatile osdovl_osd_db_ctrl_RBUS osd_db_ctrl_reg;
	osdovl_mixer_ctrl2_RBUS mixer_ctrl2;
	/* disable OSD1/OSD2 on Mixer */
	*(volatile u32 *)&mixer_ctrl2 = rtd_inl(OSDOVL_Mixer_CTRL2_reg);

	if (disPlane == GDMA_PLANE_OSD1) {
		mixer_ctrl2.mixero1_en = flag;
	} else if (disPlane == GDMA_PLANE_OSD2) {
		mixer_ctrl2.mixero2_en = flag;
	} else if (disPlane == GDMA_PLANE_OSD3) {
		mixer_ctrl2.mixero3_en = flag;
	}
	rtd_outl(OSDOVL_Mixer_CTRL2_reg, *(volatile u32 *)&mixer_ctrl2);
	osd_db_ctrl_reg.regValue = rtd_inl(OSDOVL_OSD_Db_Ctrl_reg);
	osd_db_ctrl_reg.db_load = 1;

	rtd_outl(OSDOVL_OSD_Db_Ctrl_reg, osd_db_ctrl_reg.regValue); /*  mixer apply */

	osd_db_ctrl_reg.regValue = rtd_inl(OSDOVL_OSD_Db_Ctrl_reg);


	DBG_PRINT(KERN_EMERG"%s, %d, MIXER             0x%x\n", __FUNCTION__, __LINE__, rtd_inl(OSDOVL_Mixer_CTRL2_reg));
	return GDMA_SUCCESS;
}

int GDMA_ConfigOSDEnable (bool flag)
{
	osdovl_mixer_ctrl2_RBUS mixer_ctrl2;
	/* disable OSD1/OSD2 on Mixer */
	*(volatile u32 *)&mixer_ctrl2 = rtd_inl(OSDOVL_Mixer_CTRL2_reg);
	mixer_ctrl2.mixer_en = flag;
	rtd_outl(OSDOVL_Mixer_CTRL2_reg, *(volatile u32 *)&mixer_ctrl2);

	/* disable OSD1/OSD2/OSD3 on OSD_CTRL */
	rtd_outl(GDMA_OSD1_CTRL_reg, GDMA_OSD1_CTRL_write_data(flag) | GDMA_OSD1_CTRL_osd1_en (1));
	/*rtd_outl(GDMA_OSD2_CTRL_reg, GDMA_OSD2_CTRL_write_data(flag) | GDMA_OSD2_CTRL_osd2_en (1));*/
	rtd_outl(GDMA_OSD3_CTRL_reg, GDMA_OSD3_CTRL_write_data(flag) | GDMA_OSD3_CTRL_osd3_en (1));
	DBG_PRINT(KERN_EMERG"%s, %d, MIXER             0x%x\n", __FUNCTION__, __LINE__, rtd_inl(OSDOVL_Mixer_CTRL2_reg));
	return GDMA_SUCCESS;
}

int GDMA_Sync_Enable(void)
{
#ifdef TRIPLE_BUFFER_SEMAPHORE
	int i;
	for (i = 0; i < GDMA_PLANE_MAXNUM; i++)
		gSemaphore[i] = gSEMAPHORE_MAX = 1;
#endif
	return GDMA_SUCCESS;
}

int GDMA_Sync_Disable(void)
{
#ifdef TRIPLE_BUFFER_SEMAPHORE
	int i;
	for (i = 0; i < GDMA_PLANE_MAXNUM; i++)
		gSemaphore[i] = gSEMAPHORE_MAX = GDMA_MAX_PIC_Q_SIZE+1;
#endif
	return GDMA_SUCCESS;
}

int GDMA_ConfigOSDxEnable(GDMA_DISPLAY_PLANE disPlane, bool flag)
{
	unsigned int offset = 0;
	unsigned int progDone = GDMA_CTRL_write_data(1);
	gdma_dev *gdma = &gdma_devices[0];

	if (disPlane == GDMA_PLANE_OSD1) {
		offset = 0;
		progDone |= GDMA_CTRL_osd1_prog_done(1);
	/*
	} else if (disPlane == GDMA_PLANE_OSD2) {
		offset = 0x100;
		progDone |= GDMA_CTRL_osd2_prog_done(1);
	*/
	} else if (disPlane == GDMA_PLANE_OSD3) {
		offset = 0x200;
		progDone |= GDMA_CTRL_osd3_prog_done(1);
	}

	/* disable OSDx on OSD_CTRL */
	if (gdma) {
		gdma->ctrl.osdEn[disPlane] = flag;
	}

	/*  disable immediately */
	if (flag == false) {
		//wirte 1 to clear
		rtd_outl(GDMA_OSD1_CTRL_reg+offset,GDMA_OSD1_CTRL_osd1_en(1));
		rtd_outl(GDMA_CTRL_reg, progDone);
	}else{
		rtd_outl(GDMA_OSD1_CTRL_reg+offset, GDMA_OSD1_CTRL_osd1_en(1)|
			GDMA_OSD1_CTRL_write_data(1) );
		rtd_outl(GDMA_CTRL_reg, progDone);
	}

	GDMA_ConfigOSDxMixerEnable(disPlane, flag);
	return GDMA_SUCCESS;
}


int GDMA_AddCallBackFunc (void (*fp)(void *, bool))
{
	gdma_dev *gdma = &gdma_devices[0];
	if (gdma) {
		gdma->GDMA_CallBack = fp;
		return GDMA_SUCCESS;
	} else
		return GDMA_FAIL;
}

int GDMA_AddCookieCallBackFunc (void (*fp)(void *, int))
{
	gdma_dev *gdma = &gdma_devices[0];
	if (gdma) {
		gdma->GDMA_CookieCallBack = fp;
		return GDMA_SUCCESS;
	} else
		return GDMA_FAIL;
}

int GDMA_GetPanelPixelMode(void)
{
	/* 0:ONE_PIXEL, 1:TWO_PIXEL, 2:FOUR_PIXEL */
	return ONE_PIXEL_SEG;
}


int GDMA_ConfigNonBlocking (bool enable)
{
#ifdef TRIPLE_BUFFER_SEMAPHORE
	gdma_dev *gdma = &gdma_devices[0];
	/*
	*	use gdma->sem_receive semaphore to avoid gSemaphore data inconsistent
	*	maybe cause the gdma->updateSem semaphore will not release, coming picture can't be updated
	*/
	down(&gdma->sem_receive);

	gdma->ctrl.enableNonBlocking = enable;

	/*GDMA_Flush(gdma);*/

	gSemaphore[GDMA_PLANE_OSD1] = gSEMAPHORE_MAX = (gdma->ctrl.enableNonBlocking) ? 2 : 1;

	pr_debug(KERN_EMERG"GDMA: Config Non-Blocking mode %d, gSemaphore[%d]=%d\n", gdma->ctrl.enableNonBlocking, GDMA_PLANE_OSD1, gSemaphore[GDMA_PLANE_OSD1]);

	up(&gdma->sem_receive);
#endif

	return GDMA_SUCCESS;
}

void GDMA_CopyLayerInfo(GDMA_PICTURE_OBJECT *dest, GDMA_LAYER_OBJECT *src)
{
	dest->address = src->address;
	dest->alpha = src->alpha;
	dest->clear_x = src->clear_x;
	dest->clear_y = src->clear_y;
	dest->colorkey = src->colorkey;
	dest->context = src->context;
	dest->decompress = src->decompress;
	dest->dst_height = src->dst_height;
	dest->dst_width = src->dst_width;
	dest->dst_x = src->dst_x;
	dest->dst_y = src->dst_y;
	dest->format = src->format;
	dest->fbdc_format = src->fbdc_format;
	dest->height = src->height;
	dest->key_en = src->key_en;
	dest->layer_used = 1;
	dest->paletteIndex = src->paletteIndex;
	dest->picLayout = src->picLayout;
	dest->pitch = src->pitch;
	dest->plane_ar.value = src->plane_ar.value;
	dest->plane_gb.value = src->plane_gb.value;
	dest->show = src->show;
	dest->src_type = src->src_type;
	dest->syncInfo.syncstamp = src->syncstamp;
	dest->width = src->width;
	dest->x = src->x;
	dest->y = src->y;
	dest->scale_factor = src->scale_factor;
}

/** @brief this function plays as a composer role. Receive the graphic layers up to 6 layers (4k2k, 2k1k, one mouse)
* 		Graphic layer maybe is FBDC, Normal OSD, Mouse type, function will assign the layer to correct path
* 		that pre-blending or compress or pure blending, then save into temporary space.
* 		Those pre-blending image sends to online path, GDMA will get the layers and display with other layers.
* 		Function takes care about how to arrange layers to offline path and send pre-blend and direct display layer
* 		to online path. Blend order is also under control in this function.
*  @param data the content of structure is from upper level that wants to display
*  @return GDMA_SUCCESS or negative value
*/
int GDMA_ReceiveGraphicLayers(GRAPHIC_LAYERS_OBJECT *data)
{
	gdma_dev *gdma = &gdma_devices[0];
	int err = -50, loop = 0, loop2 = 0, compLayerNum = 0, gdmaLayerNum = 0,/* fbdc4k2kIdx = 0, fbdc2k1kIdx = 0,*/ fbdcIdx = 0, normalIdx = 0;
	COMPOSE_PICTURE_OBJECT *com_picObj = NULL, *com2_picObj = NULL;
	static PICTURE_LAYERS_OBJECT *picLayerObj = NULL, *sendCompLayerObj = NULL, *sendGdmaLayerObj = NULL;
	static int mouseKeepOnline = 0;
	static PICTURE_LAYERS_OBJECT *mousepicObj = NULL;
	GDMA_PICTURE_OBJECT *layer_obj = NULL;
	/*int ScaleRatio[GDMA_LAYER_NUM];*/     /*  MSB for height, LSB for width */
	GDMA_PIC_MATCH_SYNCSTAMP syncinfo[GDMA_LAYER_NUM];
	u64 syncstamp_tmp;
	int hasMouse = 0, Is4k2kp2k1kCase = 0, IsAll4k2kCase = 0, Is2k1kCase = 0;/*, IsFBDC4k2kCase = 0, IsFBDC2k1kCase = 0;*/
	int has4k2kMouseFBDC = 0, has2k1kMouseFBDC = 0, hasDecompress = 0, hasCompress = 0;
	int has4k2kMouseNormal = 0, has2k1kMouseNormal = 0;
	int num4k2kFBDC = 0, num2k1kFBDC = 0, num4k2kNormal = 0, num2k1kNormal = 0, start2k1kIdx = -1;
	int layerIdx = 0, offlineOrder = 0;
	VO_GRAPHIC_PLANE plane_tmp, offlinePlane = VO_GRAPHIC_OSD1, onlinePlane = VO_GRAPHIC_OSD1;
	VO_RECTANGLE disp_res;
	getDispSize(&disp_res);
#ifdef USR_WORKQUEUE_UPDATE_BUFFER
	int j=0;
	int try_wait=TRIPLE_BUFFER_TRY_NUM;
	int queue_work_found=0;
#endif
	if (data->layer_num > GDMA_LAYER_NUM) {
		DBG_PRINT(KERN_EMERG"%s, Warning. too many layers \n", __FUNCTION__);
		return -100;
	}

	DBG_PRINT(KERN_EMERG"+++++++%s+++++++ \n", __FUNCTION__);


	down(&gdma->sem_gfxreceive);

	if (picLayerObj == NULL)
		picLayerObj = (PICTURE_LAYERS_OBJECT *)kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
	if (sendCompLayerObj == NULL)
		sendCompLayerObj = (PICTURE_LAYERS_OBJECT *)kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
	if (sendGdmaLayerObj == NULL)
		sendGdmaLayerObj = (PICTURE_LAYERS_OBJECT *)kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
	if (mousepicObj == NULL)
		mousepicObj = (PICTURE_LAYERS_OBJECT *)kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
	if (picLayerObj == NULL || sendCompLayerObj == NULL || sendGdmaLayerObj == NULL || mousepicObj == NULL) {
		up(&gdma->sem_gfxreceive);
		pr_debug(KERN_EMERG"%s, kmalloc failed... \n", __FUNCTION__);
		return -100;
	}

	/* get a random syncstamp */
	syncstamp_tmp = get_random_int();
	DBG_PRINT(KERN_EMERG"%s, random syncstamp = %lld \n", __FUNCTION__, syncstamp_tmp);

	/* memset(&osdcomp_picObj,0x0,sizeof(GRAPHIC_LAYERS_OBJECT)); */
	memset(&syncinfo, 0x0, sizeof(syncinfo));
	memset(picLayerObj, 0x0, sizeof(PICTURE_LAYERS_OBJECT));
	memset(sendCompLayerObj, 0x0, sizeof(PICTURE_LAYERS_OBJECT));
	memset(sendGdmaLayerObj, 0x0, sizeof(PICTURE_LAYERS_OBJECT));

	/*  collect & check all layers information */
	if (data->layer[0].width == FOURK_W && data->layer[0].height == TWOK_H)
		Is4k2kp2k1kCase = IsAll4k2kCase = 1;
	else
		Is2k1kCase = 1;

	for (loop = 0; loop < data->layer_num; loop++) {

		/*  related to 4K2K */
		if (disp_res.width == FOURK_W && disp_res.height == TWOK_H && data->layer[loop].scale_factor == 1) {

			if (data->layer[loop].src_type == SRC_NORMAL) {
				/*pr_debug(KERN_EMERG"%s, Layer[%d] 4K2K layer is NOT FBDC type \n", __FUNCTION__, loop);*/
				num4k2kNormal++;
			}
			else if (data->layer[loop].src_type == SRC_FBDC) {
				num4k2kFBDC++;
			}
		}
		/*  related to 2K1K or below */
		else if (data->layer[loop].width <= TWOK_W && data->layer[loop].height <= ONEK_H) {
			if (start2k1kIdx == -1)
				start2k1kIdx = loop;
			if (data->layer[loop].src_type == SRC_FBDC)
				num2k1kFBDC++;
			else if (data->layer[loop].src_type == SRC_NORMAL)
				num2k1kNormal++;
		}

		/* check compress picture */
		if (data->layer[loop].compressed)
			hasCompress = 1;

		/*  related to mouse */
		if (data->layer[loop].src_type == SRC_MOUSE_NORMAL || data->layer[loop].src_type == SRC_MOUSE_FBDC)
			hasMouse = 1;
		if (data->layer[loop].src_type == SRC_MOUSE_FBDC && data->layer[loop].scale_factor == 1 && disp_res.width == FOURK_W && disp_res.height == TWOK_H)
			has4k2kMouseFBDC = 1;
		if (data->layer[loop].src_type == SRC_MOUSE_NORMAL && data->layer[loop].scale_factor == 1 && disp_res.width == FOURK_W && disp_res.height == TWOK_H)
			has4k2kMouseNormal = 1;
		if (data->layer[loop].src_type == SRC_MOUSE_FBDC && data->layer[loop].scale_factor == 1 && disp_res.width <= TWOK_W && disp_res.height <= ONEK_H)
			has2k1kMouseFBDC = 1;
		if (data->layer[loop].src_type == SRC_MOUSE_NORMAL && data->layer[loop].scale_factor == 1 && disp_res.width <= TWOK_W && disp_res.height <= ONEK_H)
			has2k1kMouseNormal = 1;
		if (data->layer[loop].src_type == SRC_MOUSE_FBDC && data->layer[loop].scale_factor > 1 && disp_res.width == FOURK_W && disp_res.height == TWOK_H)
			has2k1kMouseFBDC = 1;
		if (data->layer[loop].src_type == SRC_MOUSE_NORMAL && data->layer[loop].scale_factor > 1 && disp_res.width == FOURK_W && disp_res.height == TWOK_H)
			has2k1kMouseNormal = 1;
		if (hasMouse) {
			if (loop != (data->layer_num-1))
				pr_debug(KERN_EMERG"%s, Layer[%d] Mouse layer is NOT at the latest position \n", __FUNCTION__, loop);
		}

		/*  record scale ratio */
		/*
		if (data->layer[loop].dst_width == 0 && data->layer[loop].dst_height == 0) {
			ScaleRatio[loop] = (gdma->dispWin[0].height/data->layer[loop].height)<<16;
			ScaleRatio[loop] |= ((gdma->dispWin[0].width/data->layer[loop].width)&0xFFFF);
		} else {
			ScaleRatio[loop] = (data->layer[loop].dst_height/data->layer[loop].height)<<16;
			ScaleRatio[loop] |= ((data->layer[loop].dst_width/data->layer[loop].width)&0xFFFF);
		}
		*/

		DBG_PRINT(KERN_EMERG"%s, Layer[%d] type %d compress %d \n", __FUNCTION__, loop, data->layer[loop].src_type, data->layer[loop].compressed);
	}

	/* force sticking syncstamp except for compress layers */
	for (loop = 0; loop < data->layer_num; loop++) {
		/* when compress case, mouse has another syncstamp */
		if (hasCompress)
			;/*
			if (data->layer[loop].src_type != SRC_MOUSE_NORMAL && data->layer[loop].src_type != SRC_MOUSE_FBDC)
				data->layer[loop].syncstamp = syncstamp_tmp;
			else
				data->layer[loop].syncstamp = get_random_int();
			*/
		else
			data->layer[loop].syncstamp = syncstamp_tmp;
	}


	/*	in compress case, driver automatically disable osd1 for mouse during mouse moves to mouse hides
	*	set the mouseHideFlag when mouse disappear
	*/
	if (hasMouse && hasCompress) {
		if (mouseKeepOnline == 0) {
			memset(mousepicObj, 0x00, sizeof(PICTURE_LAYERS_OBJECT));
			if (has4k2kMouseFBDC || has2k1kMouseFBDC) {
				GDMA_CopyLayerInfo(&mousepicObj->layer[0].fbdc[0], &data->layer[data->layer_num-1]);
				mousepicObj->layer[0].fbdc[0].plane = VO_GRAPHIC_OSD1;
				mousepicObj->layer[0].fbdc_num = 1;
				mousepicObj->layer[0].fbdc[0].show = 0;
			} else {
				GDMA_CopyLayerInfo(&mousepicObj->layer[0].normal[0], &data->layer[data->layer_num-1]);
				mousepicObj->layer[0].normal[0].plane = VO_GRAPHIC_OSD1;
				mousepicObj->layer[0].normal_num = 1;
				mousepicObj->layer[0].normal[0].show = 0;
			}

			mousepicObj->layer[0].onlineOrder = C0;
			mousepicObj->layer_num = 1;
			mousepicObj->cookie = 0;
			DBG_PRINT(KERN_EMERG"%s, keep mouse layer done \n", __FUNCTION__);
		}

		mouseKeepOnline = 1;
	} else {
		if (mouseKeepOnline && hasCompress) {
			mouseKeepOnline = 0;

			GDMA_ReceivePicture(mousepicObj);
			DBG_PRINT(KERN_EMERG"%s, make mouse layer disappear \n", __FUNCTION__);
		}
	}

	if ((num4k2kFBDC+num2k1kFBDC+num4k2kNormal+num2k1kNormal+hasMouse) != data->layer_num)
		pr_debug(KERN_EMERG"%s, Graphic layers are something wrong, Please check it! \n", __FUNCTION__);
	if ((num4k2kFBDC+num4k2kNormal+num2k1kFBDC+num2k1kNormal+hasMouse) > GDMA_LAYER_NUM)
		pr_debug(KERN_EMERG"%s, Too many layer=%d. Now Not support this case!, num4k2kFBDC=%d, num2k1kFBDC=%d, num2k1kNormal=%d \n", __FUNCTION__, (num4k2kFBDC+num2k1kFBDC+num2k1kNormal), num4k2kFBDC, num2k1kFBDC, num2k1kNormal);
	if (hasCompress && ((num2k1kNormal+hasMouse) >= 5))
		pr_debug(KERN_EMERG"%s, to compress normal layers over 4 layers, input num=%d \n", __FUNCTION__, (num2k1kNormal+hasMouse));


	DBG_PRINT(KERN_EMERG"%s, start layer arrangement \n", __FUNCTION__);
	/* only one layer to OSD4 display */
	if (data->layer_num == 1 && hasMouse == 0 && data->layer[0].compressed == 0 && data->layer[0].src_type == SRC_NORMAL)
		onlinePlane = VO_GRAPHIC_OSD4;
	if (data->layer_num == 1 && hasMouse == 0 && data->layer[0].compressed == 0 )		/* 2 pixels */
		onlinePlane = VO_GRAPHIC_OSD1;

	/* compress case: force mouse layer to OSD1, normal/fbdc layer starts from OSD2 */
	if (hasCompress && hasMouse)
		offlinePlane = VO_GRAPHIC_OSD3;

	/* uncompress case: when FBDC mouse + normal layers, force mouse to OSD1, normal layers starts from OSD2 */
	if (hasCompress == 0 && hasMouse && (has4k2kMouseFBDC || has2k1kMouseFBDC) && (num4k2kNormal > 0 || num2k1kNormal > 0))
		onlinePlane = VO_GRAPHIC_OSD3;

	for (loop = 0; loop < data->layer_num; loop++) {

		if (data->layer[loop].decompress) {
			plane_tmp = onlinePlane;
			onlinePlane = VO_GRAPHIC_OSD4;
			hasDecompress = 1;
		}

		/* only 3 normal layers which sets in OSD1/2/4, driver could NOT switch OSDSRx_switch_to register */
		if (data->layer_num == 3 && loop == 2 && data->layer[loop].src_type == SRC_NORMAL) {
			onlinePlane = VO_GRAPHIC_OSD4;
			normalIdx = 0;
			layerIdx++;
		}

		if (fbdcIdx > 2) {
			if (hasCompress) {
				offlinePlane = (VO_GRAPHIC_PLANE)(offlinePlane + 1);
				if (offlinePlane == VO_GRAPHIC_OSD4)
					offlinePlane = (VO_GRAPHIC_PLANE)(offlinePlane + 1);
			}
			else
				onlinePlane = (VO_GRAPHIC_PLANE)(onlinePlane + 1);
			fbdcIdx = 0;
			layerIdx++;
		}

		if (normalIdx > 0) {
			if (hasCompress) {
				offlinePlane = (VO_GRAPHIC_PLANE)(offlinePlane + 1);
				if (offlinePlane == VO_GRAPHIC_OSD4)
					offlinePlane = (VO_GRAPHIC_PLANE)(offlinePlane + 1);
			} else {
				if (data->layer[loop].decompress) {
					plane_tmp = onlinePlane;
					onlinePlane = VO_GRAPHIC_OSD4;
					hasDecompress = 1;
				} else {
					if (loop != 0 && data->layer[loop-1].decompress)
						onlinePlane = plane_tmp;
					else
						onlinePlane = (VO_GRAPHIC_PLANE)(onlinePlane + 1);
					if (hasDecompress && onlinePlane == VO_GRAPHIC_OSD4)
						onlinePlane = (VO_GRAPHIC_PLANE)(onlinePlane + 1);
				}
			}
			/* check normal layers + FBDC mouse mix case */
			if (data->layer[loop].src_type == SRC_MOUSE_FBDC)
				onlinePlane = VO_GRAPHIC_OSD1;

			normalIdx = 0;
			layerIdx++;
		}

		/* check mouse layer if let layerIdx++ */
		if ((data->layer[loop].src_type == SRC_MOUSE_NORMAL || data->layer[loop].src_type == SRC_MOUSE_FBDC) &&
			fbdcIdx > 0) {

			if (hasCompress == 0) {

				if (data->layer[loop].src_type == SRC_MOUSE_NORMAL) {
					layerIdx++;
					if (hasDecompress)
						onlinePlane = (VO_GRAPHIC_PLANE)(onlinePlane + 1);
					else
						onlinePlane = VO_GRAPHIC_OSD4;
				}
			}
		}

		if (data->layer[loop].src_type == SRC_FBDC) {
			GDMA_CopyLayerInfo(&picLayerObj->layer[layerIdx].fbdc[fbdcIdx], &data->layer[loop]);
			if (hasCompress) {
				picLayerObj->layer[layerIdx].fbdc[fbdcIdx].compressed = 1;
				picLayerObj->layer[layerIdx].fbdc[fbdcIdx].wbType = RTKCOMPRESS;
				picLayerObj->layer[layerIdx].fbdc[fbdcIdx].comp_plane = offlinePlane;
				picLayerObj->layer[layerIdx].fbdc[fbdcIdx].plane = VO_GRAPHIC_OSD4;
				picLayerObj->layer[layerIdx].fbdc[fbdcIdx].offlineOrder = (E_BLEND_ORDER)offlineOrder;
				offlineOrder++;
				picLayerObj->layer[layerIdx].onlineOrder = C0;
			} else {
				picLayerObj->layer[layerIdx].fbdc[fbdcIdx].plane = onlinePlane;
				picLayerObj->layer[layerIdx].onlineOrder = (E_BLEND_ORDER)layerIdx;
			}

			picLayerObj->layer[layerIdx].fbdc_num++;
			fbdcIdx++;
		}

		if (data->layer[loop].src_type == SRC_NORMAL) {
			GDMA_CopyLayerInfo(&picLayerObj->layer[layerIdx].normal[normalIdx], &data->layer[loop]);
			if (hasCompress) {
				picLayerObj->layer[layerIdx].normal[normalIdx].compressed = 1;
				picLayerObj->layer[layerIdx].normal[normalIdx].wbType = RTKCOMPRESS;
				picLayerObj->layer[layerIdx].normal[normalIdx].comp_plane = offlinePlane;
				picLayerObj->layer[layerIdx].normal[normalIdx].plane = VO_GRAPHIC_OSD4;
				picLayerObj->layer[layerIdx].normal[normalIdx].offlineOrder = (E_BLEND_ORDER)offlineOrder;
				offlineOrder++;
				picLayerObj->layer[layerIdx].onlineOrder = C0;
			} else {
				picLayerObj->layer[layerIdx].normal[normalIdx].plane = onlinePlane;
				picLayerObj->layer[layerIdx].onlineOrder = (E_BLEND_ORDER)layerIdx;
			}

			picLayerObj->layer[layerIdx].normal_num++;
			normalIdx++;
		}


		if (data->layer[loop].src_type == SRC_MOUSE_NORMAL) {
			GDMA_CopyLayerInfo(&picLayerObj->layer[layerIdx].normal[normalIdx], &data->layer[loop]);
			picLayerObj->layer[layerIdx].normal[normalIdx].compressed = 0;
			if (hasCompress)
				picLayerObj->layer[layerIdx].normal[normalIdx].plane = VO_GRAPHIC_OSD1;
			else
				picLayerObj->layer[layerIdx].normal[normalIdx].plane = onlinePlane;
			picLayerObj->layer[layerIdx].normal_num++;
			picLayerObj->layer[layerIdx].onlineOrder = C4;
		}
		if (data->layer[loop].src_type == SRC_MOUSE_FBDC) {
			GDMA_CopyLayerInfo(&picLayerObj->layer[layerIdx].fbdc[fbdcIdx], &data->layer[loop]);
			picLayerObj->layer[layerIdx].fbdc[fbdcIdx].compressed = 0;
			if (hasCompress)
				picLayerObj->layer[layerIdx].fbdc[fbdcIdx].plane = VO_GRAPHIC_OSD1;
			else
				picLayerObj->layer[layerIdx].fbdc[fbdcIdx].plane = onlinePlane;
			picLayerObj->layer[layerIdx].fbdc_num++;
			picLayerObj->layer[layerIdx].onlineOrder = C4;
		}
	}
	picLayerObj->layer_num = ++layerIdx;



	/*  collect syncstamp information */
	for (loop = 0; loop < picLayerObj->layer_num; loop++) {
		com_picObj = &picLayerObj->layer[loop];

		if (com_picObj->normal[0].syncInfo.syncstamp != 0 ||
			com_picObj->fbdc[0].syncInfo.syncstamp != 0) {
			if (com_picObj->fbdc_num > 0)
				syncinfo[loop].syncstamp = com_picObj->fbdc[0].syncInfo.syncstamp;
			else if (com_picObj->normal_num > 0)
				syncinfo[loop].syncstamp = com_picObj->normal[0].syncInfo.syncstamp;
			DBG_PRINT(KERN_EMERG"%s, loop=%d, syncstamp=%lld \n", __FUNCTION__, loop, syncinfo[loop].syncstamp);

			/*  search other layers */
			for (loop2 = 0; loop2 < picLayerObj->layer_num; loop2++) {
				com2_picObj = &picLayerObj->layer[loop2];
				if (com2_picObj->fbdc_num > 0)
					syncstamp_tmp = com2_picObj->fbdc[0].syncInfo.syncstamp;
				else if (com2_picObj->normal_num > 0)
					syncstamp_tmp = com2_picObj->normal[0].syncInfo.syncstamp;

				if ((syncstamp_tmp == syncinfo[loop].syncstamp) && (loop2 != loop)) {
					if (com2_picObj->fbdc_num > 0)
						plane_tmp = com2_picObj->fbdc[0].plane;
					else if (com2_picObj->normal_num > 0)
						plane_tmp = com2_picObj->normal[0].plane;

					syncinfo[loop].matchPlane[syncinfo[loop].matchNum] = plane_tmp;
					syncinfo[loop].matchNum++;
					DBG_PRINT(KERN_EMERG"%s, loop=%d, plane_tmp=%d, matchNum=%d \n", __FUNCTION__, loop, plane_tmp, syncinfo[loop].matchNum);
				}
			}
		}
	}

	/*  check conflict condition & assgin syncinfo */
	for (loop = 0; loop < picLayerObj->layer_num; loop++) {
		com_picObj = &picLayerObj->layer[loop];
		if (com_picObj->fbdc_num > 0)
			plane_tmp = com_picObj->fbdc[0].plane;
		else if (com_picObj->normal_num > 0)
			plane_tmp = com_picObj->normal[0].plane;

		for (loop2 = 0; loop2 < com_picObj->normal_num; loop2++)
			com_picObj->normal[loop2].syncInfo = syncinfo[loop];
		for (loop2 = 0; loop2 < com_picObj->fbdc_num; loop2++)
			com_picObj->fbdc[loop2].syncInfo = syncinfo[loop];

		for (loop2 = 0; loop2 < syncinfo[loop].matchNum; loop2++) {
			if (syncinfo[loop].matchPlane[loop2] == plane_tmp && hasCompress == 0)
				pr_debug(KERN_EMERG"%s, Conflict condition for GDMA..loop=%d, loop2=%d, plane_tmp=%d \n", __FUNCTION__, loop, loop2, plane_tmp);
		}
	}

	/*
	 *  if picture want to compress or blend, then go osd_comp_receive_picture
	 *  else call GDMA_ReceivePicture
	 */
	DBG_PRINT(KERN_EMERG"%s..Starting layers info. \n", __FUNCTION__);
	for (loop = 0; loop < picLayerObj->layer_num; loop++) {
		com_picObj = &picLayerObj->layer[loop];
		if (com_picObj->fbdc_num > 0)
			layer_obj = &com_picObj->fbdc[0];
		else if (com_picObj->normal_num > 0)
			layer_obj = &com_picObj->normal[0];
		else
			pr_debug(KERN_EMERG"Warning..does NOT have fbdc & normal layer, Please check it \n");

		if (com_picObj->fbdc_num > 0) {
			DBG_PRINT(KERN_EMERG"fbdc_num=%d\n", com_picObj->fbdc_num);
			loop2 = com_picObj->fbdc_num;
		} else if (com_picObj->normal_num > 0) {
			DBG_PRINT(KERN_EMERG"normal_num=%d\n", com_picObj->normal_num);
			loop2 = com_picObj->normal_num;
		}
		for (layerIdx = 0; layerIdx < loop2; layerIdx++) {
			if (com_picObj->fbdc_num > 0)
				layer_obj = &com_picObj->fbdc[layerIdx];
			else
				layer_obj = &com_picObj->normal[layerIdx];
			DBG_PRINT(KERN_EMERG"layerIdx=%d\n", layerIdx);
			DBG_PRINT(KERN_EMERG"src_type=%d, plane=%d, comp_plane=%d \n", layer_obj->src_type, layer_obj->plane, layer_obj->comp_plane);
			DBG_PRINT(KERN_EMERG"layer_used=%d, compressed=%d, offlineOrder=%d \n", layer_obj->layer_used, layer_obj->compressed, layer_obj->offlineOrder);
			DBG_PRINT(KERN_EMERG"x=%d, y=%d, width=%d, height=%d \n", layer_obj->x, layer_obj->y, layer_obj->width, layer_obj->height);
			DBG_PRINT(KERN_EMERG"dst_x=%d, dst_y=%d, dst_width=%d, dst_height=%d \n", layer_obj->dst_x, layer_obj->dst_y, layer_obj->dst_width, layer_obj->dst_height);
			DBG_PRINT(KERN_EMERG"address=0x%x, pitch=%d, onlineOrder=%d \n", layer_obj->address, layer_obj->pitch, picLayerObj->layer[loop].onlineOrder);
		}
		if (com_picObj->fbdc_num > 0)
			layer_obj = &com_picObj->fbdc[0];
		else if (com_picObj->normal_num > 0)
			layer_obj = &com_picObj->normal[0];

		/*  osd compress or blend */
		if (layer_obj->compressed) {
			sendCompLayerObj->layer[compLayerNum] = picLayerObj->layer[loop];
			compLayerNum++;
		} else { /*  gdma picture */
			sendGdmaLayerObj->layer[gdmaLayerNum] = picLayerObj->layer[loop];
			gdmaLayerNum++;
		}
	}
	DBG_PRINT(KERN_EMERG"%s...End of layers info. \n", __FUNCTION__);

	sendCompLayerObj->layer_num = compLayerNum;
	sendGdmaLayerObj->layer_num = gdmaLayerNum;

	DBG_PRINT(KERN_EMERG"%s, compLayerNum=%d, gdmaLayerNum=%d \n", __FUNCTION__, compLayerNum, gdmaLayerNum);

	/* only for HW cursor control and go online path */
	sendGdmaLayerObj->cookie = data->cookie;
	DBG_PRINT(KERN_EMERG"%s, cookie=%d \n", __FUNCTION__, data->cookie);
	 //printk(KERN_EMERG "%s, cookie=%d \n", __FUNCTION__, data->cookie);
#ifdef USR_WORKQUEUE_UPDATE_BUFFER
	if(data->cookie == NONBLOCKING_COOKIE){
   //if(data->cookie == -1){
		up(&gdma->sem_gfxreceive);
		while(try_wait-- > 0){
			for(j=0;j<USE_TRIPLE_BUFFER_NUM;j++){
				if(sOSD1ReceiveWork[j].used == 0){
			down(&gdma->sem_work);
					sOSD1ReceiveWork[j].used = 1;
			up(&gdma->sem_work);
					queue_work_found = 1;
					break;
				}
			}
			if(queue_work_found)
				break;
			//usleep 2ms
			//printk("msleep func=%s line=%d \n",__FUNCTION__,__LINE__);
			//msleep(TRIPLE_BUFFER_TRY_SLEEP);
      down_timeout(&gdma->sem_work_down_timeout, msecs_to_jiffies(TRIPLE_BUFFER_TRY_SLEEP));
		}
		if(j >= USE_TRIPLE_BUFFER_NUM){
			printk("error No queue func=%s line=%d \n",__FUNCTION__,__LINE__);

			return err;
		}

		sOSD1ReceiveWork[j].data = sendGdmaLayerObj;
		queue_work(psOsd1RecWorkQueue, &sOSD1ReceiveWork[j].GdmaReceiveWork);
    //printk(KERN_EMERG" queue_work func=%s line=%d \n",__FUNCTION__,__LINE__);
		err = GDMA_SUCCESS;
	}else{
	if (gdmaLayerNum > 0)
		err = GDMA_ReceivePicture(sendGdmaLayerObj);
	}
#endif
	up(&gdma->sem_gfxreceive);

	DBG_PRINT(KERN_EMERG"-------%s------- gdma->sem_gfxreceive.count=%d \n", __FUNCTION__, gdma->sem_gfxreceive.count);

	return err;
}

/** @brief trigger the OSD smooth toggle apply bit
 *  @param None
 *  @return None
 */
void GDMA_OSDSmoothToggle(void)
{
#if 0	//fix me later by ben
	rtd_outl(PPOVERLAY_osd_split_smooth_toggle_reg, PPOVERLAY_osd_split_smooth_toggle_osd_split_smooth_toggle_apply(1));
#endif
}

/** @brief OSD/GDMA clock control
 *  @param src_type	0: for gdma; 1: for osd_split
 *  @param enable	 true for enable; false for disable
 *  @return None
 */
void GDMA_Clk_Select(int src_type, bool enable)
{

	/* enable/disable clken_disp_gdma */
	if (enable == true)
		CRT_CLK_OnOff(GDMA, CLK_ON, &src_type);
	if (enable == false)
		CRT_CLK_OnOff(GDMA, CLK_OFF, &src_type);



	printk(KERN_ERR"[%s]BUSH = %d, DISP=%d\n", __func__, GDMA_BusH_DClk_info(0), GDMA_BusH_DClk_info(1));
	/* pick higher freq. as GDMA clock source */
	if (GDMA_BusH_DClk_info(0) > GDMA_BusH_DClk_info(1))
		rtd_outl(SYS_REG_SYS_DISPCLKSEL_reg, rtd_inl(SYS_REG_SYS_DISPCLKSEL_reg) & ~(1<<14));
	else
		rtd_outl(SYS_REG_SYS_DISPCLKSEL_reg, rtd_inl(SYS_REG_SYS_DISPCLKSEL_reg) | (1<<14));
	printk(KERN_ERR"[%s]clk value = %08x, 0114 = %08x, 0104 = %08x\n", __func__, rtd_inl(SYS_REG_SYS_DISPCLKSEL_reg),
	rtd_inl(SYS_REG_SYS_CLKEN1_reg),
	rtd_inl(SYS_REG_SYS_SRST1_reg));

}


static inline bool rtkgdma_dbg_parse_value(char *cmd_pointer, long long *parsed_data)
{
	if (kstrtoll(cmd_pointer, 0, parsed_data) == 0) {
		return true;
	} else {
		return false;
	}
}
static inline void rtkgdma_dbg_EXECUTE(const int cmd_index, char **cmd_pointer)
{
	long long parsed_data = 0;
	KADP_HAL_GAL_CTRL_T st;
	memset(&st,0,sizeof(KADP_HAL_GAL_CTRL_T));
	st.osdn=1;

	switch (cmd_index) {
		case GDMA_DBG_CMD_SET_H_SHIFT:
			rtkgdma_dbg_parse_value(*cmd_pointer, &parsed_data);
			g_osdshift_ctrl.h_shift_pixel = (int)parsed_data;
			if(g_osdshift_ctrl.h_shift_pixel)
				g_osdshift_ctrl.shift_h_enable=1;
			else
				g_osdshift_ctrl.shift_h_enable=0;
			printk("%s -- %d parsed_data=%d\n",__FUNCTION__,__LINE__,(int)parsed_data);
			return;
		case GDMA_DBG_CMD_SET_V_SHIFT:
			rtkgdma_dbg_parse_value(*cmd_pointer, &parsed_data);
			g_osdshift_ctrl.v_shift_pixel = (int)parsed_data;
			if(g_osdshift_ctrl.v_shift_pixel)
				g_osdshift_ctrl.shift_v_enable=1;
			else
				g_osdshift_ctrl.shift_v_enable=0;
			printk("%s -- %d parsed_data=%d\n",__FUNCTION__,__LINE__,(int)parsed_data);
			return;
		case GDMA_DBG_CMD_OSD_DUMP:
			sscanf(*cmd_pointer, "%d %s\n",
				&st.osdn, st.capinfo.fname);
			snprintf(st.capinfo.fname, 128,"%s/dump_%08d.bmp",st.capinfo.fname, rtd_inl(0xB801B690));
				break;
		case GDMA_DBG_CMD_OSD_DUMP_EX:
			sscanf(*cmd_pointer, "%d %s\n",
				&st.osdn, st.capinfo.fname);
			snprintf(st.capinfo.fname, 128,"%s/dump_%08d.bmp",st.capinfo.fname, rtd_inl(0xB801B690));
				break;
		case GDMA_DBG_CMD_OSD_DROP:
			sscanf(*cmd_pointer, "%x\n", &st.en);
			printk("%s -- %d parsed_data=%x\n",__FUNCTION__,__LINE__,st.en);
			break;
		case GDMA_DBG_CMD_OSD_PATTERN:
			sscanf(*cmd_pointer, "%d %d %x\n", &st.en, &st.osdn, &st.clr);
			break;
		case GDMA_DBG_CMD_OSD_VFLIP:
			sscanf(*cmd_pointer, "%d\n", &st.en);
			break;
		case GDMA_DBG_CMD_OSD_CTRL:
			sscanf(*cmd_pointer, "%d %d\n", &st.en,&st.osdn);
			break;
		case GDMA_DBG_CMD_OSD_SWAP:
			sscanf(*cmd_pointer, "%d %d %d %d %d %d\n",
				&st.c[0],&st.c[1],&st.c[2],
				&st.c[3],&st.c[4],&st.c[5]);
			break;
		case GDMA_DBG_CMD_OSD_CAP2MEM:
			sscanf(*cmd_pointer, "%d %x\n", &st.osdn, &st.clr);
			break;
		case GDMA_DBG_CMD_SHOW_INFO:
				break;
		case GDMA_DBG_CMD_OSD_GET_INFO:
			break;
		case GDMA_DBG_CMD_OSD_CTRL_EN:
			sscanf(*cmd_pointer, "%d %d\n", &st.en,&st.osdn);
			break;
		default:
			printk(KERN_ERR"%s cmd-%d error.\n",__func__,cmd_index);
			return;
		}
	st.type = cmd_index;
	if(GDMA_Debug(&st)!=0) {
		printk(KERN_ERR"[%s]%s , OSD-%d fail.\n",
		__func__,rtkgdma_cmd_str[cmd_index], st.osdn);
	}
}

bool GDMA_init_debug_proc(void)
{
	if (rtkgdma_proc_dir == NULL && rtkgdma_proc_entry == NULL) {
		rtkgdma_proc_dir = proc_mkdir(RTKGDMA_PROC_DIR , NULL);

		if (rtkgdma_proc_dir != NULL) {
			rtkgdma_proc_entry =
				proc_create(RTKGDMA_PROC_ENTRY, 0666,
							rtkgdma_proc_dir, &gdma_fops);

			if (rtkgdma_proc_entry == NULL) {
				proc_remove(rtkgdma_proc_dir);
				rtkgdma_proc_dir = NULL;

				return false;
			}
		} else {

			return false;
		}
	}

	return true;
}

void GDMA_uninit_debug_proc(void)
{
	if (rtkgdma_proc_entry) {
		proc_remove(rtkgdma_proc_entry);
		rtkgdma_proc_entry = NULL;
	}

	if (rtkgdma_proc_dir) {
		proc_remove(rtkgdma_proc_dir);
		rtkgdma_proc_dir = NULL;
	}
}


#ifndef CONFIG_SUPPORT_SCALER
#if 0

//#include <rbus/rbusColor_osd_shpnrReg.h>
#include <rbus/color_uvcoring_reg.h>

void drvif_color_OSD_Sharpness(DRV_OSD_sharp *ptr)
{
	osd_hpeaking_ctrl_1_RBUS     osd_hpeaking_ctrl_1;
	osd_hpeaking_filter_1_RBUS   osd_hpeaking_filter_1;
	osd_emf_ctrl_1_RBUS osd_emf_ctrl_1;
	osd_emf_extent_1_RBUS   osd_emf_extent_1;
	osd_hpeaking_gain_1_RBUS        osd_hpeaking_gain_1;
	osd_hpeaking_bound_1_RBUS   osd_hpeaking_bound_1;

	if (!ptr)
		return;

	osd_hpeaking_ctrl_1.osd_shpnr_en_ch1 = ptr->Osd_shpnr_en;
	osd_hpeaking_ctrl_1.peaking_enable_ch1 = ptr->peaking_en;
	osd_hpeaking_filter_1.c0_ch1 = ptr->C0;
	osd_hpeaking_filter_1.c1_ch1 = ptr->C1;
	osd_hpeaking_filter_1.c2_ch1 = ptr->C2;
	osd_emf_ctrl_1.emf_en_ch1 = ptr->EMF_en;
	osd_emf_ctrl_1.emf_range_ch1 = ptr->EMF_Range;
	osd_emf_ctrl_1.emf_shift_ch1 = ptr->EMF_Shift;
	osd_emf_ctrl_1.seg0_gain_sel_ch1 = ptr->Seg0_Gain_Sel;
	osd_emf_ctrl_1.seg0_offset_ch1 = ptr->Seg0_Offset;
	osd_emf_ctrl_1.seg1_gain_sel_ch1 = ptr->Seg1_Gain_Sel;
	osd_emf_ctrl_1.seg2_gain_sel_ch1 = ptr->Seg2_Gain_Sel;
	osd_emf_extent_1.emf_fixextent_ch1 = ptr->EMF_fixextent;
	osd_emf_extent_1.seg1_offset_ch1 = ptr->Seg1_Offset;
	osd_emf_extent_1.seg2_offset_ch1 = ptr->Seg2_Offset;
	osd_hpeaking_gain_1.gain_blr_ch1 = ptr->Gain_Blr;
	osd_hpeaking_gain_1.gain_neg_ch1 = ptr->Gain_Neg;
	osd_hpeaking_gain_1.gain_pos_ch1 = ptr->Gain_Pos;
	osd_hpeaking_bound_1.hv_neg_ch1 = ptr->HV_Neg;
	osd_hpeaking_bound_1.hv_pos_ch1 = ptr->HV_Pos;
	osd_hpeaking_bound_1.lv_ch1 = ptr->LV;

	rtd_outl(COLOR_OSD_SHPNR_OSD_HPEAKING_CTRL_1_VADDR, osd_hpeaking_ctrl_1.regValue);
	rtd_outl(COLOR_OSD_SHPNR_OSD_HPEAKING_FILTER_1_VADDR, osd_hpeaking_filter_1.regValue);
	rtd_outl(COLOR_OSD_SHPNR_OSD_EMF_CTRL_1_VADDR, osd_emf_ctrl_1.regValue);
	rtd_outl(COLOR_OSD_SHPNR_OSD_EMF_EXTENT_1_VADDR, osd_emf_extent_1.regValue);
	rtd_outl(COLOR_OSD_SHPNR_OSD_HPEAKING_GAIN_1_VADDR, osd_hpeaking_gain_1.regValue);
	rtd_outl(COLOR_OSD_SHPNR_OSD_HPEAKING_BOUND_1_VADDR, osd_hpeaking_bound_1.regValue);
}


#endif
void fwif_color_set_scaleosd_sharpness_driver(unsigned char src_index, unsigned char scale_factor)
{
#if 0
	extern DRV_OSD_sharp gVipOSD_sharp[];
	drvif_color_OSD_Sharpness(&gVipOSD_sharp[scale_factor]);
#endif
	return;
}

#endif


/*=============START OF GPU STD STUFF ===============*/
#if defined(CONFIG_ARM64)
unsigned long GDMA_gpuWrap_std_suspend(unsigned long phyAddr, unsigned int size) {
	return (unsigned long)dvr_remap_cached_memory( phyAddr, size, __builtin_return_address(0));
}
#else
unsigned int GDMA_gpuWrap_std_suspend(unsigned int phyAddr, unsigned int size) {
	return (unsigned int)dvr_remap_cached_memory( phyAddr, size, __builtin_return_address(0));
}
#endif

#if defined(CONFIG_ARM64)
void GDMA_gpuWrap_std_resume(unsigned long phyAddr, unsigned long virtAddr, unsigned int size) {
#else
void GDMA_gpuWrap_std_resume(unsigned int phyAddr, unsigned int virtAddr, unsigned int size) {
#endif
	dmac_flush_range((void*)virtAddr, (void*)(virtAddr + size));
	outer_flush_range((phys_addr_t)phyAddr, (phys_addr_t)(phyAddr + size));
	dvr_unmap_memory((void*)virtAddr, PAGE_ALIGN(size));
}
/*=============END    OF GPU STD STUFF ===============*/


module_init(GDMA_init_module);
module_exit(GDMA_cleanup_module);


EXPORT_SYMBOL(GDMA_ConfigureGraphicCanvas);
EXPORT_SYMBOL(GDMA_CreateGraphicWindow);
EXPORT_SYMBOL(GDMA_DrawGraphicWindow);
EXPORT_SYMBOL(GDMA_ModifyGraphicWindow);
EXPORT_SYMBOL(GDMA_DeleteGraphicWindow);
EXPORT_SYMBOL(GDMA_AddCallBackFunc);
EXPORT_SYMBOL(GDMA_AddCookieCallBackFunc);
EXPORT_SYMBOL(GDMA_Display);
EXPORT_SYMBOL(GDMA_OSD1OnTop);
EXPORT_SYMBOL(GDMA_Config3D);
EXPORT_SYMBOL(GDMA_ConfigVFlip);
EXPORT_SYMBOL(GDMA_Debug);
EXPORT_SYMBOL(GDMA_Config3DOffset);
EXPORT_SYMBOL(GDMA_ConfigBlending);
EXPORT_SYMBOL(GDMA_ReceivePicture);
EXPORT_SYMBOL(GDMA_ConfigureDisplayWindow);
EXPORT_SYMBOL(GDMA_ReceiveCmd);
EXPORT_SYMBOL(gContext);
EXPORT_SYMBOL(GDMA_ISR_export);
EXPORT_SYMBOL(GDMA_ConfigInputSrc_4k2k);
EXPORT_SYMBOL(GDMA_Lock_Vsync_Sem);
EXPORT_SYMBOL(GDMA_Config3dUi);
EXPORT_SYMBOL(GDMA_ConfigOSDEnable);
EXPORT_SYMBOL(GDMA_ConfigOSDxEnable);
EXPORT_SYMBOL(GDMA_GetPanelPixelMode);
EXPORT_SYMBOL(GDMA_ReceiveGraphicLayers);
EXPORT_SYMBOL(GDMA_CopyLayerInfo);
EXPORT_SYMBOL(getDispSize);
EXPORT_SYMBOL(GDMA_gpuWrap_std_suspend);
EXPORT_SYMBOL(GDMA_gpuWrap_std_resume);


/*===============================================*/
