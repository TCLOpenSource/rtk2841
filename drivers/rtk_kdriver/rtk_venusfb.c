/*
 * linux/drivers/video/venusfb.c -
 *
 *
 * Modes / Resolution:
 *
 *      | 720x480  720x576  1280x720 1920x1080
 *  ----+-------------------------------------
 *  8bit|  0x101    0x201    0x401    0x801
 * 16bit|  0x102    0x202    0x402    0x802
 * 32bit|  0x103    0x204    0x404    0x804
 *
 * args example:  video=venusfb:0x202 (this is default setting)
 *
 */
#define CONFIG_REALTEK_MAGELLAN
#define CONFIG_RTK_KDRV_RPC
//#define CONFIG_MAGELLAN_CANVAS
#if defined(CONFIG_ANDROID)
	#if defined(CONFIG_RTK_KDRV_RECOVERY_KERNEL) || defined(CONFIG_ANDROID_SW_RENDER) || defined(CONFIG_ARM64)
    #define CONFIG_SET_WIN_ALPHA_AS_FF
	#endif
#else
    #define EMPTY_GDMA //for null GDMA use
#endif
//#define NON_USE_DRV_MALLOC

#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/fb.h>
#include <linux/init.h>
#include <linux/ioport.h>
#include <linux/pci.h>
#include <asm/uaccess.h>
#include <linux/interrupt.h>
#include <linux/pagemap.h>
#include <linux/pageremap.h>
#include <linux/dma-mapping.h>
//#include <venus.h>
#include <linux/radix-tree.h>
#include <linux/blkdev.h>
#include <linux/module.h>
#include <linux/blkpg.h>
#include <linux/buffer_head.h>
#include <linux/mpage.h>
#include <linux/ioctl.h> /* needed for the _IOW etc stuff used later */
#include <linux/sched.h>
#include <linux/dcache.h>
//#include <linux/pageremap.h>
#include <linux/platform_device.h>
#ifdef CONFIG_DEVFS_FS
	#include <linux/devfs_fs_kernel.h>
#endif
#ifdef CONFIG_RTK_KDRV_RPC
	//#include <linux/RPCDriver.h>
//empty fun for magellan
#define KERNELID	98
#define RPC_AUDIO	0x0
#define RPC_VIDEO	0x1
#define RPC_OK		0
#define RPC_FAIL	-1
#undef MAGELLAN_RPC
static int send_rpc_command(int opt, unsigned long command, unsigned long param1, unsigned long param2, unsigned long *retvalue);
#endif


// The following functions are used by driver to allocate continuous memory...
//empty fun for magellan
//static int *dvr_malloc(size_t size);
//empty fun for magellan
//static int dvr_free(const void *arg);

// The following functions are used by user to allocate continuous memory...
//empty fun for magellan
//static int *pli_malloc(size_t size);
//empty fun for magellan
//static int pli_free(const void *arg);

//fbdc: 1080P: 126K
static unsigned int gFB_EXTRA_SIZE = 136*1024*3;

//#include <platform.h>
#include "rtk_kdriver/rtk_venusfb.h"
#include <rtk_kdriver/rtk_pwm.h>

#define DRVNAME "venusfb"
#define DEVNAME	DRVNAME
static int AssignedMajorNumber;

#ifdef CONFIG_REALTEK_MAGELLAN
	#ifndef EMPTY_GDMA
	//#include "../arch/mips/rtk_dmp/drivers/GdmaReg.h"
	extern int GDMA_ConfigureGraphicCanvas (VIDEO_RPC_VOUT_CONFIG_GRAPHIC_CANVAS *cmd);
	extern int GDMA_CreateGraphicWindow (VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN *cmd);
	extern int GDMA_DrawGraphicWindow (VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN *cmd);
	extern int GDMA_DeleteGraphicWindow (unsigned char winID, VO_GRAPHIC_PLANE plane, unsigned char go);
	extern int GDMA_ModifyGraphicWindow (VIDEO_RPC_VOUT_MODIFY_GRAPHIC_WIN *cmd);
	#else
	static int GDMA_ConfigureGraphicCanvas (VIDEO_RPC_VOUT_CONFIG_GRAPHIC_CANVAS *cmd) { return 0;}
	static int GDMA_CreateGraphicWindow (VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN *cmd) { return 0;}
	static int GDMA_DrawGraphicWindow (VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN *cmd) { return 0;}
	static int GDMA_DeleteGraphicWindow (unsigned char winID, VO_GRAPHIC_PLANE plane, unsigned char go) { return 0;}
	static int GDMA_ModifyGraphicWindow (VIDEO_RPC_VOUT_MODIFY_GRAPHIC_WIN *cmd) { return 0;}	
	#endif	
#endif //CONFIG_REALTEK_MAGELLAN

static int video_clrDisplayArea(struct venusfb_info *fbi);
static int video_drawDisplayArea(struct venusfb_info *fbi);

#define TMPBUFLEN   2048

#define DBG_PRINT(s, args...) printk(s, ##args)

const struct venusfb_rgb rgb_8 = {
	.red	= { .offset = 0,  .length = 8, },
	.green	= { .offset = 0,  .length = 8, },
	.blue	= { .offset = 0,  .length = 8, },
	.transp = { .offset = 0,  .length = 0, },
};

const struct venusfb_rgb rgb_16 = {
	.red	= { .offset = 11, .length = 5, },
	.green	= { .offset = 5,  .length = 6, },
	.blue	= { .offset = 0,  .length = 5, },
	.transp = { .offset = 0,  .length = 0, },
};

const struct venusfb_rgb rgb_32 = {
	.red	= { .offset = 0,  .length = 8, },
	.green	= { .offset = 8,  .length = 8, },
	.blue	= { .offset = 16, .length = 8, },
	.transp = { .offset = 24, .length = 8, },
};

static VENUSFB_MACH_INFO venus_video_info = {
	.pixclock		= 720*480*60,
	.xres			= 720,
	.yres			= 480,
	.xoffset		= 0,
	.yoffset		= 0,
	.osdxres		= 720,
	.osdyres		= 480,
	.bpp			= 16,
	.pitch			= 768*2,
	.videomemory		= NULL,
	.phyAddr		= NULL,
	.videomemorysize	= 768*2*480,
	.videomemorysizeorder	= 8, // 2^8 * 4KB = 1MB
	.storageMode		= 0,
#ifdef CONFIG_RTK_KDRV_RPC
	.winID			= -1,
	.mixer2			= 0,
#endif
};

static struct fb_monspecs monspecs = {
	.hfmin			= 30000,
	.hfmax			= 70000,
	.vfmin			= 50,
	.vfmax			= 65,
};

static struct fb_ops venusfb_ops;

// The following functions are used by driver to allocate continuous memory...
//static int *dvr_malloc(size_t size){return 0;}
//static int dvr_free(const void *arg){return 0;}

// The following functions are used by user to allocate continuous memory...
//static int *pli_malloc(size_t size){return 0;}
//static int pli_free(const void *arg){return 0;}
static int send_rpc_command(int opt, unsigned long command, unsigned long param1, unsigned long param2, unsigned long *retvalue){return 1;}

static void reset_video_info(struct venusfb_info *fbi)
{
	if (fbi->video_info.mixer2) {
		printk("VenusFB: mixer2 should be NULL...\n");
		BUG();
	}

	fbi->video_info 		= venus_video_info;

	// fill [struct fb_fix_screeninfo] : Non-changeable properties
	strcpy(fbi->fb.fix.id, "venusfb");
	fbi->fb.fix.type		= FB_TYPE_PACKED_PIXELS;
	fbi->fb.fix.type_aux		= 0;
	fbi->fb.fix.visual		= FB_VISUAL_TRUECOLOR;
	fbi->fb.fix.xpanstep		= 1;
	fbi->fb.fix.ypanstep		= 1;
	fbi->fb.fix.ywrapstep		= 1;
	fbi->fb.fix.line_length 	= venus_video_info.pitch;
	fbi->fb.fix.accel		= FB_ACCEL_NONE;

	// fill [struct fb_var_screeninfo] : This is used to set "feature"
	fbi->fb.var.xres		= venus_video_info.xres;
	fbi->fb.var.xres_virtual	= venus_video_info.xres;
	fbi->fb.var.yres		= venus_video_info.yres;
	fbi->fb.var.yres_virtual	= venus_video_info.yres;
	fbi->fb.var.xoffset		= 0;
	fbi->fb.var.yoffset		= 0;
	fbi->fb.var.bits_per_pixel	= venus_video_info.bpp;
	fbi->fb.var.grayscale		= 0;

	switch(fbi->fb.var.bits_per_pixel) {
	case 8:
		fbi->fb.var.red		= rgb_8.red;
		fbi->fb.var.green	= rgb_8.green;
		fbi->fb.var.blue 	= rgb_8.blue;
		fbi->fb.var.transp 	= rgb_8.transp;
		break;
	default:
	case 16:
		fbi->fb.var.red		= rgb_16.red;
		fbi->fb.var.green	= rgb_16.green;
		fbi->fb.var.blue 	= rgb_16.blue;
		fbi->fb.var.transp 	= rgb_16.transp;
		break;
	case 32:
		fbi->fb.var.red		= rgb_32.red;
		fbi->fb.var.green	= rgb_32.green;
		fbi->fb.var.blue 	= rgb_32.blue;
		fbi->fb.var.transp 	= rgb_32.transp;
		break;
	}

	fbi->fb.var.pixclock		= 1000*(1000*1000*1000 / venus_video_info.pixclock); // in pico-second unit
	fbi->fb.var.left_margin		= 0;
	fbi->fb.var.right_margin	= 0;
	fbi->fb.var.upper_margin	= 0;
	fbi->fb.var.lower_margin	= 0;
	fbi->fb.var.hsync_len		= 0;
	fbi->fb.var.vsync_len		= 0;
	fbi->fb.var.sync		= FB_SYNC_EXT;
	fbi->fb.var.nonstd		= 0;
	fbi->fb.var.activate		= FB_ACTIVATE_NOW;
	fbi->fb.var.height		= 0;
	fbi->fb.var.width		= 0;
	fbi->fb.var.accel_flags		= 0;
	fbi->fb.var.vmode		= FB_VMODE_NONINTERLACED;

	// fbops for character device support
	fbi->fb.flags		= FBINFO_DEFAULT;

	fbi->fb.fbops			= &venusfb_ops;
	fbi->fb.monspecs		= monspecs;
	fbi->fb.pseudo_palette		= (void *)fbi->pseudo_palette;
}

static int video_allocMemory(struct venusfb_info *fbi)
{
	if (fbi->video_info.videomemory != 0)
		BUG();
#ifdef NON_USE_DRV_MALLOC
	if (!(fbi->video_info.videomemory = kmalloc((PAGE_SIZE << fbi->video_info.videomemorysizeorder),GFP_KERNEL))) {
		printk("VenusFB: dvr_malloc(%d) failed ..\n", fbi->video_info.videomemorysizeorder);
		return 1;
	}
#else
	//if (!(fbi->video_info.videomemory = dvr_malloc_specific((PAGE_SIZE << fbi->video_info.videomemorysizeorder),GFP_DCU2))) {
	if (!(fbi->video_info.videomemory = dvr_malloc_specific(fbi->video_info.videomemorysize, GFP_DCU2))) {
		printk("VenusFB: dvr_malloc(%d) failed ..\n", fbi->video_info.videomemorysizeorder);
		return 1;
	}
#endif
	printk(" ### alloc Memory %p (2^%d)...\n", fbi->video_info.videomemory, fbi->video_info.videomemorysizeorder);
#ifdef NON_USE_DRV_MALLOC
	fbi->video_info.phyAddr = (void *)virt_to_phys(fbi->video_info.videomemory);
#else
	fbi->video_info.phyAddr = (void *)dvr_to_phys(fbi->video_info.videomemory);
#endif
	memset(fbi->video_info.videomemory, 0, fbi->video_info.videomemorysize);
// temp disabling DMA map/unmap for Android 64-bit, it suppose be ok due to flush would be performed when using dvr_malloc_
#ifndef CONFIG_ARM64
	dma_map_single(NULL, (void*)fbi->video_info.videomemory, fbi->video_info.videomemorysize, DMA_TO_DEVICE);
	dma_unmap_single(NULL, (void*)fbi->video_info.videomemory, fbi->video_info.videomemorysize, DMA_TO_DEVICE);
#endif
	//must to do in magellan
	//dma_cache_wback_inv((unsigned long)fbi->video_info.videomemory, fbi->video_info.videomemorysize);
	fbi->map_vir_addr               = fbi->video_info.videomemory;
	fbi->map_phy_addr               = fbi->video_info.phyAddr;
	fbi->map_size                   = fbi->video_info.videomemorysize;
	fbi->fb.fix.smem_start          = (unsigned long)fbi->video_info.phyAddr;
	fbi->fb.fix.smem_len            = PAGE_ALIGN(fbi->video_info.videomemorysize);
	fbi->fb.screen_base             = (unsigned long)fbi->video_info.videomemory;//(char __iomem *)(UNCAC_ADDR((unsigned int)fbi->video_info.videomemory));
	fbi->fb.screen_size             = fbi->video_info.videomemorysize;
	return 0;
}

static int video_freeMemory(struct venusfb_info *fbi)
{
	if (fbi->video_info.videomemory == 0)
		BUG();
	printk(" ### free Memory %p...\n", fbi->video_info.videomemory);
#ifdef NON_USE_DRV_MALLOC
	kfree(fbi->video_info.videomemory);
#else
	dvr_free(fbi->video_info.videomemory);
#endif
	fbi->video_info.videomemory = 0;

	return 0;
}

#ifdef CONFIG_RTK_KDRV_RPC
static int video_initDisplayArea(struct venusfb_info *fbi)
{
	VIDEO_RPC_VOUT_CONFIG_VIDEO_STANDARD	*structConfigVideoStandard;
	VIDEO_RPC_VOUT_CONFIG_HDMI		*structConfigHDMI;
	VIDEO_RPC_VOUT_SET_BKGRND		*structSetBKGrnd;
	VIDEO_RPC_VOUT_CONFIG_GRAPHIC_CANVAS	*structConfigGraphicCanvas;
	struct page *page = 0;
	unsigned long ret=S_OK;

    printk("\n\r fun=%s line=%d addr=%x\n",__FUNCTION__,__LINE__,__builtin_return_address(0));

	printk(" #@# Init Display Area...\n");

	page = alloc_page(GFP_DMA);
	//fix for Klocwork:144127 144182 144239
	if(page != NULL){
		printk(" #@# IBuffer: %p...\n", page_address(page));
	}else{
		printk("alloc_page fail !! \n");
		goto fail;
	}

	if (atomic_read(&fbi->passive_mode)) {
		printk(" #@# no need to config video standard...\n");
		goto config_canvas;
	}

	// config video standard...
	structConfigVideoStandard = (VIDEO_RPC_VOUT_CONFIG_VIDEO_STANDARD *)page_address(page);
	if (fbi->video_info.osdxres == 720)
		structConfigVideoStandard->standard = htonl(VO_STANDARD_NTSC_M);
	else if (fbi->video_info.osdxres == 1280)
		structConfigVideoStandard->standard = htonl(VO_STANDARD_HDTV_720P_60);
	else if (fbi->video_info.osdxres == 1920)
		structConfigVideoStandard->standard = htonl(VO_STANDARD_HDTV_1080I_60);
	else
		BUG();
	structConfigVideoStandard->enProg = 0;
	structConfigVideoStandard->enDIF = 0;
	structConfigVideoStandard->enCompRGB = 0;
	structConfigVideoStandard->pedType = 0;
	structConfigVideoStandard->dataInt0 = htonl(0);
	structConfigVideoStandard->dataInt1 = htonl(0);
//RPC maintain
#ifdef MAGELLAN_RPC
	if (send_rpc_command(RPC_VIDEO, RPCCMD_CONFIG_VIDEO_STANDARD, UNCAC_BASE|(unsigned long)page_address(page), 0, &ret))
		goto fail;
#endif
	printk(" #@# config video standard, ret = %lx \n", ret);

	if (ret != S_OK) {
		printk("VenusFB: Config video standard fail...\n");
		goto fail;
	}

	// config hdmi...
	structConfigHDMI = (VIDEO_RPC_VOUT_CONFIG_HDMI *)page_address(page);
	structConfigHDMI->hdmiMode = htonl(VO_HDMI_ON);
	structConfigHDMI->audioSampleFreq = htonl(VO_HDMI_AUDIO_32K);
	structConfigHDMI->colorFmt = htonl(VO_HDMI_RGB444 << 5);
	structConfigHDMI->audioChannelCount = 2;

//RPC maintain
#ifdef MAGELLAN_RPC
	if (send_rpc_command(RPC_VIDEO, RPCCMD_CONFIG_HDMI, UNCAC_BASE|(unsigned long)page_address(page), 0, &ret))
		goto fail;
#endif
	printk(" #@# config hdmi, ret = %lx \n", ret);

	if (ret != S_OK) {
		printk("VenusFB: Config hdmi fail...\n");
		goto fail;
	}

	// set background...
	structSetBKGrnd = (VIDEO_RPC_VOUT_SET_BKGRND *)page_address(page);
	structSetBKGrnd->bgColor.c1 = 16;
	structSetBKGrnd->bgColor.c2 = 128;
	structSetBKGrnd->bgColor.c3 = 128;
	structSetBKGrnd->bgColor.isRGB = 0;
	structSetBKGrnd->bgEnable = 1;
//RPC maintain
#ifdef MAGELLAN_RPC
	if (send_rpc_command(RPC_VIDEO, RPCCMD_SET_BKGRND, UNCAC_BASE|(unsigned long)page_address(page), 0, &ret))
		goto fail;
#endif
	printk(" #@# set background, ret = %lx \n", ret);

	if (ret != S_OK) {
		printk("VenusFB: Set background fail...\n");
		goto fail;
	}

config_canvas:
#ifdef CONFIG_REALTEK_MAGELLAN
	// darwin, Ver.B(and latter) using GDMA api replace rpc
	if (1)
	{
		// config graphic canvas...
		structConfigGraphicCanvas = (VIDEO_RPC_VOUT_CONFIG_GRAPHIC_CANVAS *)page_address(page);
		structConfigGraphicCanvas->plane = VO_GRAPHIC_OSD1;
		structConfigGraphicCanvas->srcWin.x = 0;
		structConfigGraphicCanvas->srcWin.y = 0;
		structConfigGraphicCanvas->srcWin.width = fbi->video_info.xres;
		structConfigGraphicCanvas->srcWin.height = fbi->video_info.yres;
#ifdef CONFIG_MAGELLAN_CANVAS
		structConfigGraphicCanvas->dispWin.x = 0;
		structConfigGraphicCanvas->dispWin.y = 0;
		structConfigGraphicCanvas->dispWin.width = fbi->video_info.osdxres;
		structConfigGraphicCanvas->dispWin.height = fbi->video_info.osdyres;
#else
		structConfigGraphicCanvas->dispWin.x = 40;
		structConfigGraphicCanvas->dispWin.y = 20;
		structConfigGraphicCanvas->dispWin.width = fbi->video_info.osdxres-80;
		structConfigGraphicCanvas->dispWin.height = fbi->video_info.osdyres-40;
#endif
		structConfigGraphicCanvas->go = 0;


	//printk("##==> %s(%d): GDMA_ConfigureGraphicCanvas\n", __FUNCTION__, __LINE__);
		ret = GDMA_ConfigureGraphicCanvas(structConfigGraphicCanvas);
		if(ret == 0)
			ret = S_OK;
	}
	else
#endif //CONFIG_REALTEK_MAGELLAN
	{
	// config graphic canvas...
	structConfigGraphicCanvas = (VIDEO_RPC_VOUT_CONFIG_GRAPHIC_CANVAS *)page_address(page);
	structConfigGraphicCanvas->plane = htonl(VO_GRAPHIC_OSD1);//htonl(VOUT_GRAPHIC_OSD);
	structConfigGraphicCanvas->srcWin.x = 0;
	structConfigGraphicCanvas->srcWin.y = 0;
	structConfigGraphicCanvas->srcWin.width = htons(fbi->video_info.xres);
	structConfigGraphicCanvas->srcWin.height = htons(fbi->video_info.yres);
#ifdef CONFIG_MAGELLAN_CANVAS
	structConfigGraphicCanvas->dispWin.x = 0;
	structConfigGraphicCanvas->dispWin.y = 0;
	structConfigGraphicCanvas->dispWin.width = htons(fbi->video_info.osdxres);
	structConfigGraphicCanvas->dispWin.height = htons(fbi->video_info.osdyres);
#else
	structConfigGraphicCanvas->dispWin.x = htons(40);
	structConfigGraphicCanvas->dispWin.y = htons(20);
	structConfigGraphicCanvas->dispWin.width = htons(fbi->video_info.osdxres-80);
	structConfigGraphicCanvas->dispWin.height = htons(fbi->video_info.osdyres-40);
#endif
	structConfigGraphicCanvas->go = 0;

//RPC maintain
#ifdef MAGELLAN_RPC
	if (send_rpc_command(RPC_VIDEO, RPCCMD_CONFIG_GRAPHIC_CANVAS, UNCAC_BASE|(unsigned long)page_address(page), 0, &ret))
		goto fail;
#endif
	}
	printk(" #@# config graphic canvas, ret = %lx \n", ret);

	if (ret != S_OK) {
		printk("VenusFB: Config graphic canvas fail...\n");
		goto fail;
	}

	__free_page(page);

	return 0;

fail:
	if (page)
		__free_page(page);

	return 1;
}


static int video_drawDisplayArea(struct venusfb_info *fbi)
{
	VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN	*structCreateGraphicWin;
	VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN		*structDrawGraphicWin;
	struct page *page = 0;
	unsigned long winID, ret=S_OK;

	printk(" #@# Draw Display Area...\n");

	page = alloc_page(GFP_DMA);
	//fix for Klocwork:144121 144120 144177 144176 144233 144232
	if(page != NULL){
		printk(" #@# DBuffer: %p...\n", page_address(page));
	}else{
		printk("alloc_page fail !! \n");
		goto fail;
	}


	if (atomic_read(&fbi->passive_mode)) {
		printk(" #@# no need to set mixer2 buffer...\n");
		goto create_window;
	}

#if 0	//don't have mixer2 in FB.
	// set mixer2 buffer (if needed)...
	if (fbi->video_info.mixer2 == 0) {

#ifdef NON_USE_DRV_MALLOC
		fbi->video_info.mixer2 = (unsigned long)kmalloc(720*576*6,GFP_KERNEL);
#else
		fbi->video_info.mixer2 = (unsigned long)dvr_malloc_specific(720*576*6,GFP_DCU2);
#endif

#ifdef MAGELLAN_RPC
		if (send_rpc_command(RPC_VIDEO, RPCCMD_SET_MIXER2_BUFFER, fbi->video_info.mixer2, 0, &ret))
			goto fail;
#endif
		printk(" #@# set mixer2 buffer %x, ret = %lx \n", fbi->video_info.mixer2, ret);

		if (ret != S_OK) {
			printk("VenusFB: Set mixer2 buffer fail...\n");
			goto fail;
		}
	} else {
		printk(" #@# use mixer2 buffer %x...\n", fbi->video_info.mixer2);
	}
#endif//0

create_window:
#ifdef CONFIG_REALTEK_MAGELLAN
	// darwin, Ver.B(and latter) using GDMA api replace rpc
	if (1)
	{
	// create window...
	structCreateGraphicWin = (VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN *)page_address(page);
	structCreateGraphicWin->plane = VO_GRAPHIC_OSD1;
	structCreateGraphicWin->winPos.x = 0;
	structCreateGraphicWin->winPos.y = 0;
	structCreateGraphicWin->winPos.width = fbi->video_info.xres;
	structCreateGraphicWin->winPos.height = fbi->video_info.yres;
	switch (fbi->video_info.bpp) {
		case 8:
			structCreateGraphicWin->colorFmt = VO_OSD_COLOR_FORMAT_RGB332;
			structCreateGraphicWin->rgbOrder = (VO_OSD_RGB_ORDER)VO_OSD_COLOR_RGB;
			break;
		default:
		case 16:
			if (1) {
				structCreateGraphicWin->colorFmt = VO_OSD_COLOR_FORMAT_RGB565_LITTLE;
				structCreateGraphicWin->rgbOrder = (VO_OSD_RGB_ORDER)VO_OSD_COLOR_RGB;
			} else {
				structCreateGraphicWin->colorFmt = VO_OSD_COLOR_FORMAT_RGB565;
				structCreateGraphicWin->rgbOrder = (VO_OSD_RGB_ORDER)VO_OSD_COLOR_RGB;
			}
			break;
		case 32:
			//+JT - provide ARGB support
			printk(" #@# transp.offset: %d...\n", fbi->video_info.rgb_info.transp.offset);
			if (fbi->video_info.rgb_info.transp.offset == 24) {
				printk(" #@# red.offset: %d...\n", fbi->video_info.rgb_info.red.offset);
				if (fbi->video_info.rgb_info.red.offset == 16) {
					structCreateGraphicWin->colorFmt = VO_OSD_COLOR_FORMAT_RGBA8888;
					structCreateGraphicWin->rgbOrder = (VO_OSD_RGB_ORDER)VO_OSD_COLOR_BGR;
				} else {	//+JT - EJ 's original setting
					structCreateGraphicWin->colorFmt = VO_OSD_COLOR_FORMAT_RGBA8888;
					//structCreateGraphicWin->rgbOrder = (VO_OSD_RGB_ORDER)VO_OSD_COLOR_RGB;
                                        //RTK tmp workaround for Adroid incorrect color
					structCreateGraphicWin->rgbOrder = (VO_OSD_RGB_ORDER)VO_OSD_COLOR_BGR;
				}
			} else {
				structCreateGraphicWin->colorFmt = VO_OSD_COLOR_FORMAT_ARGB8888;
				structCreateGraphicWin->rgbOrder = (VO_OSD_RGB_ORDER)VO_OSD_COLOR_RGB;
			}
			break;
	}
	structCreateGraphicWin->colorKey = 0xFFFFFFFF;
#ifdef CONFIG_SET_WIN_ALPHA_AS_FF
	structCreateGraphicWin->alpha = 0xff; // support per-pixel-alpha for 32-bits mode...
#else
	structCreateGraphicWin->alpha = 0x0; // support per-pixel-alpha for 32-bits mode...
#endif


    printk("##==> %s(%d): GDMA_CreateGraphicWindow\n", __FUNCTION__, __LINE__);
	winID = GDMA_CreateGraphicWindow(structCreateGraphicWin);
	printk(" #@# create window, ret = %lx \n", winID);

	if (winID == -EFAULT) {
		printk("VenusFB: Create window fail...\n");
		goto fail;
	}
	fbi->video_info.winID = winID;

	// draw window...
	structDrawGraphicWin = (VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN *)page_address(page);
	structDrawGraphicWin->plane = VO_GRAPHIC_OSD1;
	structDrawGraphicWin->winID = (u_short)winID;
	structDrawGraphicWin->storageMode = VO_GRAPHIC_SEQUENTIAL;
	structDrawGraphicWin->paletteIndex = 0xff;
	structDrawGraphicWin->compressed = 0;
	structDrawGraphicWin->interlace_Frame = 0;
	structDrawGraphicWin->bottomField = 0;
	structDrawGraphicWin->startX[0] = 0;
	structDrawGraphicWin->startY[0] = 0;
	structDrawGraphicWin->imgPitch[0] = (u_short)fbi->video_info.pitch;
	structDrawGraphicWin->pImage[0] = (long)fbi->video_info.phyAddr;
	structDrawGraphicWin->go = 0;	// set to zero to avoid garbage osd


    printk("##==> %s(%d): GDMA_DrawGraphicWindow\n", __FUNCTION__, __LINE__);

//Mask: avoid OSD setting when android preview.
	ret = GDMA_DrawGraphicWindow(structDrawGraphicWin);
	if(ret == 0)
		ret = S_OK;
	}
	else
#endif//CONFIG_REALTEK_MAGELLAN
	{
	// create window...
	structCreateGraphicWin = (VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN *)page_address(page);
	structCreateGraphicWin->plane = htonl(VO_GRAPHIC_OSD1);//htonl(VOUT_GRAPHIC_OSD);
	structCreateGraphicWin->winPos.x = 0;
	structCreateGraphicWin->winPos.y = 0;
	structCreateGraphicWin->winPos.width = htons(fbi->video_info.xres);
	structCreateGraphicWin->winPos.height = htons(fbi->video_info.yres);
	switch (fbi->video_info.bpp) {
		case 8:
			structCreateGraphicWin->colorFmt = htonl(VO_OSD_COLOR_FORMAT_RGB332);
			structCreateGraphicWin->rgbOrder = htonl((VO_OSD_RGB_ORDER)VO_OSD_COLOR_RGB);
			break;
		default:
		case 16:
			if (1) {
				structCreateGraphicWin->colorFmt = htonl(VO_OSD_COLOR_FORMAT_RGB565_LITTLE);
				structCreateGraphicWin->rgbOrder = htonl((VO_OSD_RGB_ORDER)VO_OSD_COLOR_RGB);
			} else {
				structCreateGraphicWin->colorFmt = htonl(VO_OSD_COLOR_FORMAT_RGB565);
				structCreateGraphicWin->rgbOrder = htonl((VO_OSD_RGB_ORDER)VO_OSD_COLOR_RGB);
			}
			break;
		case 32:
			//+JT - provide ARGB support
			printk(" #@# transp.offset: %d...\n", fbi->video_info.rgb_info.transp.offset);
			if (fbi->video_info.rgb_info.transp.offset == 24) {
				printk(" #@# red.offset: %d...\n", fbi->video_info.rgb_info.red.offset);
				if (fbi->video_info.rgb_info.red.offset == 16) {
					structCreateGraphicWin->colorFmt = htonl(VO_OSD_COLOR_FORMAT_RGBA8888);
					structCreateGraphicWin->rgbOrder = htonl((VO_OSD_RGB_ORDER)VO_OSD_COLOR_BGR);
				} else {	//+JT - EJ 's original setting
					structCreateGraphicWin->colorFmt = htonl(VO_OSD_COLOR_FORMAT_RGBA8888);
					structCreateGraphicWin->rgbOrder = htonl((VO_OSD_RGB_ORDER)VO_OSD_COLOR_RGB);
				}
			} else {
				structCreateGraphicWin->colorFmt = htonl(VO_OSD_COLOR_FORMAT_ARGB8888);
				structCreateGraphicWin->rgbOrder = htonl((VO_OSD_RGB_ORDER)VO_OSD_COLOR_RGB);
			}
			break;
	}
	structCreateGraphicWin->colorKey = htonl(0xFFFFFFFF);
#ifdef CONFIG_SET_WIN_ALPHA_AS_FF
	structCreateGraphicWin->alpha = 0xff; // support per-pixel-alpha for 32-bits mode...
#else
	structCreateGraphicWin->alpha = 0x0; // support per-pixel-alpha for 32-bits mode...
#endif
#ifdef MAGELLAN_RPC
	if (send_rpc_command(RPC_VIDEO, RPCCMD_CREATE_GRAPHIC_WIN, UNCAC_BASE|(unsigned long)page_address(page), 0, &winID))
		goto fail;
#endif
	printk(" #@# create window, ret = %lx \n", winID);

	if (winID == 0xffffffff) {
		printk("VenusFB: Create window fail...\n");
		goto fail;
	}
	fbi->video_info.winID = winID;

	// draw window...
	structDrawGraphicWin = (VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN *)page_address(page);
	structDrawGraphicWin->plane = htonl(VO_GRAPHIC_OSD1);//htonl(VOUT_GRAPHIC_OSD);
	structDrawGraphicWin->winID = htons((u_short)winID);
	structDrawGraphicWin->storageMode = htonl(VO_GRAPHIC_SEQUENTIAL);
	structDrawGraphicWin->paletteIndex = 0xff;
	structDrawGraphicWin->compressed = 0;
	structDrawGraphicWin->interlace_Frame = 0;
	structDrawGraphicWin->bottomField = 0;
	structDrawGraphicWin->startX[0] = 0;
	structDrawGraphicWin->startY[0] = 0;
	structDrawGraphicWin->imgPitch[0] = htons((u_short)fbi->video_info.pitch);
	structDrawGraphicWin->pImage[0] = htonl((long)fbi->video_info.phyAddr);
	structDrawGraphicWin->go = 1;

#ifdef MAGELLAN_RPC
	if (send_rpc_command(RPC_VIDEO, RPCCMD_DRAW_GRAPHIC_WIN, UNCAC_BASE|(unsigned long)page_address(page), 0, &ret))
		goto fail;
#endif
	}
	printk(" #@# draw window, ret = %lx \n", ret);

	if (ret != S_OK) {
		printk("VenusFB: Draw window fail...\n");
		video_clrDisplayArea(fbi);
		goto fail;
	}

	__free_page(page);

	return 0;

fail:
	if (page)
		__free_page(page);

	return 1;
}

static int video_clrDisplayArea(struct venusfb_info *fbi)
{
	VIDEO_RPC_VOUT_DELETE_GRAPHIC_WIN	*structDeleteGraphicWin;
	struct page *page = 0;
	unsigned long ret=S_OK;

	printk(" #@# Clear Display Area...\n");

	// delete mixer2 buffer (if needed)...
	if (fbi->video_info.mixer2) {
#ifdef MAGELLAN_RPC
		if (send_rpc_command(RPC_VIDEO, RPCCMD_SET_MIXER2_BUFFER, 0, 0, &ret))
			goto fail;
#endif
		printk(" #@# delete mixer2 buffer, ret = %lx \n", ret);

		if (ret != S_OK) {
			printk("VenusFB: delete mixer2 buffer fail...\n");
			goto fail;
		}

		// free the mixer2 memory...
#ifdef NON_USE_DRV_MALLOC
	kfree((void *)fbi->video_info.mixer2);
#else
		dvr_free((void *)fbi->video_info.mixer2);
#endif
		fbi->video_info.mixer2 = 0;
	} else {
		printk(" #@# no mixer2 buffer exist...\n");
	}

	if (fbi->video_info.winID == -1) {
		printk(" #@# no window exist...\n");
		return 0;
	}

	page = alloc_page(GFP_DMA);
	//fix for Klocwork:144125 144119 144175 144237 144231
	if(page != NULL){
		printk(" #@# CBuffer: %p...\n", page_address(page));
	}else{
		printk("alloc_page fail !! \n");
		goto fail;
	}


#ifdef CONFIG_REALTEK_MAGELLAN
	// darwin, Ver.B(and latter) using GDMA api replace rpc
	if (1)
	{
	// delete window...
	structDeleteGraphicWin = (VIDEO_RPC_VOUT_DELETE_GRAPHIC_WIN *)page_address(page);
	structDeleteGraphicWin->plane = VO_GRAPHIC_OSD1;
	structDeleteGraphicWin->winID = (u_short)(fbi->video_info.winID);
	structDeleteGraphicWin->go = 1;


    //printk("##==> %s(%d): GDMA_DeleteGraphicWindow\n", __FUNCTION__, __LINE__);
	ret = GDMA_DeleteGraphicWindow(structDeleteGraphicWin->winID, structDeleteGraphicWin->plane, structDeleteGraphicWin->go);
	if(ret == 0)
		ret = S_OK;
	}
	else
#endif //CONFIG_REALTEK_MAGELLAN
	{
	// delete window...
	structDeleteGraphicWin = (VIDEO_RPC_VOUT_DELETE_GRAPHIC_WIN *)page_address(page);
	structDeleteGraphicWin->plane = htonl(VO_GRAPHIC_OSD1);//htonl(VOUT_GRAPHIC_OSD);
	structDeleteGraphicWin->winID = htons((u_short)(fbi->video_info.winID));
	structDeleteGraphicWin->go = 1;
#ifdef MAGELLAN_RPC
	if (send_rpc_command(RPC_VIDEO, RPCCMD_DELETE_GRAPHIC_WIN, UNCAC_BASE|(unsigned long)page_address(page), 0, &ret))
		goto fail;
#endif
	}

	printk(" #@# delete window, ret = %lx \n", ret);
	if (ret != S_OK) {
		printk("VenusFB: Delete window fail...\n");
		goto fail;
	}
	// clear the window ID...
	fbi->video_info.winID = -1;
	__free_page(page);
	return 0;

fail:
	if (page)
		__free_page(page);

	return 1;
}
#endif

/*
 * Internal routines
 */

static void __init setup_venus_video_info(char *options) {
	char *this_opt;
	uint32_t MIN_TILE_HEIGHT=0;
	short height;

	// retrieve MIN_TILE_HEIGHT
	//only support sequential mode
	//MIN_TILE_HEIGHT = 8 << ((readl(IOA_DC_SYS_MISC) >> 16) & 0x3);

	// default settings
	//for tcl
	venus_video_info.xres = 1920;
	venus_video_info.yres = 1080;

	venus_video_info.xoffset = 0;
	venus_video_info.yoffset = 0;
	//tcl
	venus_video_info.bpp = 32;

	while((this_opt = strsep(&options, ",")) != NULL) {
		if(!*this_opt)
			continue;
		if(strncmp(this_opt, "0x101", 5) == 0) {
			venus_video_info.xres = 720;
			venus_video_info.yres = 480;
			venus_video_info.bpp = 8;
		}
		else if(strncmp(this_opt, "0x102", 5) == 0) {
			venus_video_info.xres = 720;
			venus_video_info.yres = 480;
			venus_video_info.bpp = 16;
		}
		else if(strncmp(this_opt, "0x104", 5) == 0) {
			venus_video_info.xres = 720;
			venus_video_info.yres = 480;
			venus_video_info.bpp = 32;
		}
		else if(strncmp(this_opt, "0x201", 5) == 0) {
			venus_video_info.xres = 720;
			venus_video_info.yres = 576;
			venus_video_info.bpp = 8;
		}
		else if(strncmp(this_opt, "0x202", 5) == 0) {
			venus_video_info.xres = 720;
			venus_video_info.yres = 576;
			venus_video_info.bpp = 16;
		}
		else if(strncmp(this_opt, "0x204", 5) == 0) {
			venus_video_info.xres = 720;
			venus_video_info.yres = 576;
			venus_video_info.bpp = 32;
		}
		else if(strncmp(this_opt, "0x401", 5) == 0) {
			venus_video_info.xres = 1280;
			venus_video_info.yres = 720;
			venus_video_info.bpp = 8;
		}
		else if(strncmp(this_opt, "0x402", 5) == 0) {
			venus_video_info.xres = 1280;
			venus_video_info.yres = 720;
			venus_video_info.bpp = 16;
		}
		else if(strncmp(this_opt, "0x404", 5) == 0) {
			venus_video_info.xres = 1280;
			venus_video_info.yres = 720;
			venus_video_info.bpp = 32;
		}
		else if(strncmp(this_opt, "0x801", 5) == 0) {
			venus_video_info.xres = 1920;
			venus_video_info.yres = 1080;
			venus_video_info.bpp = 8;
		}
		else if(strncmp(this_opt, "0x802", 5) == 0) {
			venus_video_info.xres = 1920;
			venus_video_info.yres = 1080;
			venus_video_info.bpp = 16;
		}
		else if(strncmp(this_opt, "0x804", 5) == 0) {
			venus_video_info.xres = 1280;
			venus_video_info.yres = 960;
			venus_video_info.bpp = 32;
		}
	}
	// check if it's TV panel resolution
	if ((venus_video_info.xres == 1366) && (venus_video_info.yres == 768)) {
		venus_video_info.osdxres = 1280;
		venus_video_info.osdyres = 720;
	} else {
		venus_video_info.osdxres = venus_video_info.xres;
		venus_video_info.osdyres = venus_video_info.yres;
	}

	switch(venus_video_info.bpp) {
	case 8:
		venus_video_info.rgb_info.red		= rgb_8.red;
		venus_video_info.rgb_info.green		= rgb_8.green;
		venus_video_info.rgb_info.blue		= rgb_8.blue;
		venus_video_info.rgb_info.transp	= rgb_8.transp;
		break;
	default:
	case 16:
		venus_video_info.rgb_info.red		= rgb_16.red;
		venus_video_info.rgb_info.green		= rgb_16.green;
		venus_video_info.rgb_info.blue		= rgb_16.blue;
		venus_video_info.rgb_info.transp	= rgb_16.transp;
		break;
	case 32:
		venus_video_info.rgb_info.red		= rgb_32.red;
		venus_video_info.rgb_info.green		= rgb_32.green;
		venus_video_info.rgb_info.blue		= rgb_32.blue;
		venus_video_info.rgb_info.transp	= rgb_32.transp;
		break;
	}

	if (1) {
		venus_video_info.storageMode = 1; // sequential mode

		// tune height
		height = venus_video_info.yres;

		// adjust pitch to the multiple of 16
//		venus_video_info.pitch = ((venus_video_info.xres * (venus_video_info.bpp / 8) + 0x0F) >> 4 ) << 4;
		venus_video_info.pitch = venus_video_info.xres * (venus_video_info.bpp / 8);
	} else {
		uint32_t ii;

		venus_video_info.storageMode = 0; // block mode

		// tune height
		height = ((venus_video_info.yres - 1) / MIN_TILE_HEIGHT + 1) * MIN_TILE_HEIGHT;

		// adjust pitch to the multiple of 256
		venus_video_info.pitch = ((venus_video_info.xres * (venus_video_info.bpp / 8) + 0xFF) >> 8 ) << 8;

		// adjust pitch to power of 2 in 256 bytes unit
		for(ii=256; ; ii*=2) {
			if(venus_video_info.pitch <= ii) {
				venus_video_info.pitch = ii;
				break;
			}
		}
	}

	// calculate pixel clock
	venus_video_info.pixclock = venus_video_info.xres * venus_video_info.yres * 60;

	// calculate required video memory size
	venus_video_info.videomemorysize =  PAGE_ALIGN((venus_video_info.pitch * height) + gFB_EXTRA_SIZE);
#if defined(CONFIG_RTK_KDRV_RECOVERY_KERNEL)
	venus_video_info.videomemorysize *= 2; // double buffer for android recovery mode.
#endif
	printk(KERN_WARNING "FB size 1: %d %u\n", venus_video_info.videomemorysize, gFB_EXTRA_SIZE);

	// calculate required videomemorysizeorder
	if(venus_video_info.videomemorysize == (1 << (fls(venus_video_info.videomemorysize) - 1)))
		venus_video_info.videomemorysizeorder = fls(venus_video_info.videomemorysize) - 13;
	else
		venus_video_info.videomemorysizeorder = fls(venus_video_info.videomemorysize) - 12;
}

/*
 * Frame Buffer Operation Functions
 */

static int
venusfb_open(struct fb_info *info, int user)
{
	struct venusfb_info *fbi = (struct venusfb_info *) info;
	struct file *file = (struct file *)user;

	if (atomic_inc_return(&fbi->ref_count) == 1) {
		if (video_allocMemory(fbi)) {
			atomic_dec(&fbi->ref_count);
			return -ENOMEM;
		}
		BUG_ON(atomic_read(&fbi->passive_mode));

	#if 0
			if (file && (file->f_flags & 0x10000000)) {
			atomic_inc_return(&fbi->passive_mode);
			printk("VenusFB: Enter passive mode1 %d...\n", atomic_read(&fbi->passive_mode));
		} else {
    #endif


#ifdef CONFIG_RTK_KDRV_RPC
			video_initDisplayArea(fbi);
			video_drawDisplayArea(fbi);
#endif
#if 0
		}
#endif
	} else {
#if 0
		if (file && (file->f_flags & 0x10000000)) {
			atomic_inc_return(&fbi->passive_mode);
			printk("VenusFB: Enter passive mode2 %d...\n", atomic_read(&fbi->passive_mode));
		}
#endif
	}

	return 0;
}

static int
venusfb_release(struct fb_info *info, int user)
{
	struct venusfb_info *fbi = (struct venusfb_info *) info;
	struct file *file = (struct file *)user;
	if (atomic_dec_return(&fbi->ref_count) == 0) {
#ifdef CONFIG_RTK_KDRV_RPC
		video_clrDisplayArea(fbi);
#endif
		if (video_freeMemory(fbi))
			return -EFAULT;
		reset_video_info(fbi);
#if 0
		if (file && (file->f_flags & 0x10000000)) {
			atomic_dec_return(&fbi->passive_mode);
			printk("VenusFB: Exit passive mode1 %d...\n", atomic_read(&fbi->passive_mode));
		}
#endif
		BUG_ON(atomic_read(&fbi->passive_mode));
	} else {
#if 0
		if (file && (file->f_flags & 0x10000000)) {
			atomic_dec_return(&fbi->passive_mode);
			printk("VenusFB: Exit passive mode2 %d...\n", atomic_read(&fbi->passive_mode));
		}
#endif
	}

	return 0;
}

#if 0
static ssize_t
venusfb_read(struct file *file, char *buf, size_t count, loff_t *ppos)
{
};

static ssize_t
venusfb_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
};
#endif

static int
venusfb_ioctl(struct fb_info *info, unsigned int cmd, unsigned long arg)
{
	struct venusfb_info *fbi = (struct venusfb_info *)info;

	int err = 0;
	int retval = 0;

	if (_IOC_TYPE(cmd) != VENUS_FB_IOC_MAGIC)
		return -ENOTTY;
	else if (_IOC_NR(cmd) > VENUS_FB_IOC_MAXNR)
		return -ENOTTY;

	if (_IOC_DIR(cmd) & _IOC_READ)
		err = !access_ok(VERIFY_WRITE, (void __user *)arg, _IOC_SIZE(cmd));
	else if (_IOC_DIR(cmd) & _IOC_WRITE)
		err = !access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd));

	if (err)
		return -EFAULT;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;

printk("\n\r fun=%s line=%d addr=%x cmd=%d\n",__FUNCTION__,__LINE__,__builtin_return_address(0),cmd);

	switch (cmd) {
	case VENUS_FB_IOC_GET_MACHINE_INFO:
		if (copy_to_user((void *)arg, &(fbi->video_info), sizeof(VENUSFB_MACH_INFO)) != 0)
			return -EFAULT;
		retval = 0;
		break;
	case VENUS_FB_IOC_SET_OSD_STANDARD:
		{
			int x, y;
			if (arg == VO_STANDARD_NTSC) {
				x = 720;
				y = 480;
			} else if (arg == VO_STANDARD_PAL) {
				x = 720;
				y = 576;
			} else if (arg == VO_STANDARD_HDTV_720) {
				x = 1280;
				y = 720;
			} else if (arg == VO_STANDARD_HDTV_1080) {
				x = 1920;
				y = 1080;
			} else {
				printk("VenusFB: Invalid output resolution...\n");
				return -EINVAL;
			}
			printk("VenusFB: change from %d x %d to %d x %d\n",
					fbi->video_info.osdxres, fbi->video_info.osdyres, x, y);

			if ((fbi->video_info.osdxres == x) && (fbi->video_info.osdyres == y)) {
				printk("VenusFB: No need to change output resolution...\n");
				return 0;
			}
			fbi->video_info.osdxres = x;
			fbi->video_info.osdyres = y;
			if (fbi->video_info.winID != -1) {
#ifdef CONFIG_RTK_KDRV_RPC
				video_clrDisplayArea(fbi);
				video_initDisplayArea(fbi);
				video_drawDisplayArea(fbi);
#endif
			}
			retval = 0;
			break;
		}
	case VENUS_FB_IOC_GET_OSD_STATE:
		retval = (fbi->video_info.winID >= 0) ? 1 : 0;
		break;
	case VENUS_FB_IOC_SET_OSD_STATE:
		if (arg == 0) {
			if (fbi->video_info.winID != -1) {
#ifdef CONFIG_RTK_KDRV_RPC
				video_clrDisplayArea(fbi);
#endif
			}
		} else {
			if (fbi->video_info.winID == -1) {
#ifdef CONFIG_RTK_KDRV_RPC
				video_initDisplayArea(fbi);
				video_drawDisplayArea(fbi);
#endif
			}
		}
		break;
	default:
		retval = -ENOIOCTLCMD;
	}

	return retval;
}

/*
 * Pan or Wrap the Display
 *
 * This call looks only at xoffset, yoffset and the FB_VMODE_YWRAP flag
 */

static int venusfb_pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
#ifdef CONFIG_RTK_KDRV_RPC
	VIDEO_RPC_VOUT_MODIFY_GRAPHIC_WIN	*structModifyGraphicWin;
	struct page *page = 0;
	unsigned long ret;
	struct venusfb_info *fbi = (struct venusfb_info *) info;

	if ((var->xoffset == fbi->video_info.xoffset) && (var->yoffset == fbi->video_info.yoffset)) {
		printk(" #@# DONT PAN...\n");
		return 0;
	}
	fbi->video_info.xoffset = var->xoffset;
	fbi->video_info.yoffset = var->yoffset;
	//printk(" #@# Pan Display Area...var x %d var y %d \n", var->xoffset, var->yoffset);
	//printk(" #@# Pan Display Area...fbi x %d fbi y %d \n", fbi->video_info.xoffset, fbi->video_info.yoffset);

	if (fbi->video_info.winID == -1) {
		printk(" #@# no window no pan...\n");
		return 0;
	}

	page = alloc_page(GFP_KERNEL);
	// fix for Klocwork:146059
	if (page != NULL){
		printk(" #@# PBuffer: %p...\n", page_address(page));
	}else{
		printk("alloc_page fail !! \n");
		goto fail;
	}
//	printk(" #@# PBuffer: %p...\n", page_address(page));

#ifdef CONFIG_REALTEK_MAGELLAN
	// darwin, Ver.B(and latter) using GDMA api replace rpc
	if (1)
	{
		// modify window...
		structModifyGraphicWin = (VIDEO_RPC_VOUT_MODIFY_GRAPHIC_WIN *)page_address(page);
		//fix for Klocwork:144123 144179 144236 144235
		if(structModifyGraphicWin == NULL){
			printk("structModifyGraphicWin is NULL !! \n");
			return 0;
		}
	
		structModifyGraphicWin->plane = VO_GRAPHIC_OSD1;
		structModifyGraphicWin->winID = (u_short)(fbi->video_info.winID);
		structModifyGraphicWin->reqMask = VO_OSD_WIN_SRC_LOCATION;
		structModifyGraphicWin->startX[0] = var->xoffset;
		structModifyGraphicWin->startY[0] = var->yoffset;
		structModifyGraphicWin->imgPitch[0] = (u_short)fbi->video_info.pitch;
		structModifyGraphicWin->pImage[0] = (long)fbi->video_info.phyAddr;
		structModifyGraphicWin->go = 1;

		//printk("##==> %s(%d): GDMA_ModifyGraphicWindow\n", __FUNCTION__, __LINE__);
		ret = GDMA_ModifyGraphicWindow(structModifyGraphicWin);
		if(ret == 0)
			ret = S_OK;
	}
	else
#endif//CONFIG_REALTEK_MAGELLAN
	{
		// modify window...
		structModifyGraphicWin = (VIDEO_RPC_VOUT_MODIFY_GRAPHIC_WIN *)page_address(page);
		//fix for Klocwork:144124 144180 
		if(structModifyGraphicWin == NULL){
			printk("structModifyGraphicWin is NULL !! \n");
			return 0;
		}
		structModifyGraphicWin->plane = htonl(VO_GRAPHIC_OSD1);//htonl(VOUT_GRAPHIC_OSD);
		structModifyGraphicWin->winID = htons((u_short)(fbi->video_info.winID));
		structModifyGraphicWin->reqMask = VO_OSD_WIN_SRC_LOCATION;
		structModifyGraphicWin->startX[0] = htons(var->xoffset);
		structModifyGraphicWin->startY[0] = htons(var->yoffset);
		structModifyGraphicWin->imgPitch[0] = htons((u_short)fbi->video_info.pitch);
		structModifyGraphicWin->pImage[0] = htonl((long)fbi->video_info.phyAddr);
		structModifyGraphicWin->go = 1;

#ifdef MAGELLAN_RPC
		if (send_rpc_command(RPC_VIDEO, RPCCMD_MODIFY_GRAPHIC_WIN, UNCAC_BASE|(unsigned long)page_address(page), 0, &ret))
			goto fail;
#endif
	}
//	printk(" #@# modify window, ret = %lx \n", ret);

	if (ret != S_OK) {
		printk("VenusFB: Modify window fail...\n");
		goto fail;
	}

	__free_page(page);

	return 0;

fail:
	if (page)
		__free_page(page);

	return -EINVAL;
#else
	return 0;
#endif
}

/*
 * Blank the display
 */
static int venusfb_blank(int blank, struct fb_info *info)
{
        int retval;

        switch (blank) {
        case FB_BLANK_UNBLANK:
            retval = rtk_pwm_backlight_enable(0);
            printk("turn display on, ret=%d\n", retval);
            break;
        case FB_BLANK_NORMAL:
        case FB_BLANK_VSYNC_SUSPEND:
        case FB_BLANK_HSYNC_SUSPEND:
        case FB_BLANK_POWERDOWN:
        default:
            retval = rtk_pwm_backlight_enable(1);
            printk("turn display off, ret=%d\n", retval);
            break;
        }
        return retval;
}

/*
 * Set a single color register. The values supplied are already
 * rounded down to the hardware's capabilities (according to the
 * entries in the var structure). Return != 0 for invalid regno.
 */

static int venusfb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
		u_int transp, struct fb_info *info)
{

	printk(" #@# %d, r: %d, g: %d, b: %d, %x \n", regno, red, green, blue, info->pseudo_palette);
//	if (regno == 15)
//		dump_stack();

	if (regno >= 256)       /* no. of hw registers */
		return 1;
	/*
	 * Program hardware... do anything you want with transp
	 */

	/* grayscale works only partially under directcolor */
	if (info->var.grayscale) {
		/* grayscale = 0.30*R + 0.59*G + 0.11*B */
		red = green = blue = (red * 77 + green * 151 + blue * 28) >> 8;
	}

	/* Directcolor:
	 *   var->{color}.offset contains start of bitfield
	 *   var->{color}.length contains length of bitfield
	 *   {hardwarespecific} contains width of RAMDAC
	 *   cmap[X] is programmed to (X << red.offset) | (X << green.offset) | (X << blue.offset)
	 *   RAMDAC[X] is programmed to (red, green, blue)
	 *
	 * Pseudocolor:
	 *   uses offset = 0 && length = RAMDAC register width.
	 *   var->{color}.offset is 0
	 *   var->{color}.length contains widht of DAC
	 *   cmap is not used
	 *   RAMDAC[X] is programmed to (red, green, blue)
	 *
	 * Truecolor:
	 *   does not use DAC. Usually 3 are present.
	 *   var->{color}.offset contains start of bitfield
	 *   var->{color}.length contains length of bitfield
	 *   cmap is programmed to (red << red.offset) | (green << green.offset) |
	 *                     (blue << blue.offset) | (transp << transp.offset)
	 *   RAMDAC does not exist
	 */
#define CNVT_TOHW(val,width) ((((val)<<(width))+0x7FFF-(val))>>16)
	switch (info->fix.visual) {
		case FB_VISUAL_TRUECOLOR:
		case FB_VISUAL_PSEUDOCOLOR:
			red = CNVT_TOHW(red, info->var.red.length);
			green = CNVT_TOHW(green, info->var.green.length);
			blue = CNVT_TOHW(blue, info->var.blue.length);
			transp = CNVT_TOHW(transp, info->var.transp.length);
			break;
		case FB_VISUAL_DIRECTCOLOR:
			red = CNVT_TOHW(red, 8);        /* expect 8 bit DAC */
			green = CNVT_TOHW(green, 8);
			blue = CNVT_TOHW(blue, 8);
			/* hey, there is bug in transp handling... */
			transp = CNVT_TOHW(transp, 8);
			break;
	}
#undef CNVT_TOHW
	/* Truecolor has hardware independent palette */
	if (info->fix.visual == FB_VISUAL_TRUECOLOR) {
		u32 v;

		if (regno >= 16)
			return 1;

		v = (red << info->var.red.offset) |
			(green << info->var.green.offset) |
			(blue << info->var.blue.offset) |
			(transp << info->var.transp.offset);
		switch (info->var.bits_per_pixel) {
			case 8:
				break;
			case 16:
				((u32 *) (info->pseudo_palette))[regno] = v;
				break;
			case 24:
			case 32:
				((u32 *) (info->pseudo_palette))[regno] = v;
				break;
		}
		return 0;
	}
	return 0;
}

/*
 * Note that we are entered with the kernel locked.
 */

static int venusfb_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
//	unsigned long prot;
	unsigned long off;
	unsigned long start;
	u32 len;


	if (vma->vm_pgoff > (~0UL >> PAGE_SHIFT))
		return -EINVAL;
	off = vma->vm_pgoff << PAGE_SHIFT;

	/* frame buffer memory */
	start = info->fix.smem_start;
	len = PAGE_ALIGN((start & ~PAGE_MASK) + info->fix.smem_len);
	if (off >= len) {
		/* memory mapped io */
		off -= len;
		if (info->var.accel_flags)
			return -EINVAL;
		start = info->fix.mmio_start;
		len = PAGE_ALIGN((start & ~PAGE_MASK) + info->fix.mmio_len);
	}
	start &= PAGE_MASK;
	if ((vma->vm_end - vma->vm_start + off) > len)
		return -EINVAL;
	off += start;
	vma->vm_pgoff = off >> PAGE_SHIFT;
	/* This is an IO map - tell maydump to skip this VMA */
	//vma->vm_flags |= VM_IO | VM_RESERVED;
	vma->vm_flags |= VM_IO;
#ifdef CONFIG_ARM64
	vma->vm_page_prot = pgprot_writecombine(vma->vm_page_prot);
#else
	vma->vm_page_prot = pgprot_dmacoherent(vma->vm_page_prot);
#endif
	/*
	prot = pgprot_val(vma->vm_page_prot);
	prot = (prot & ~_CACHE_MASK) | _CACHE_UNCACHED;
	if (prot & _PAGE_WRITE)
		prot = prot | _PAGE_FILE | _PAGE_VALID | _PAGE_DIRTY;
	else
		prot = prot | _PAGE_FILE | _PAGE_VALID;
	prot &= ~_PAGE_PRESENT;
	vma->vm_page_prot = __pgprot(prot);
*/
	if (io_remap_pfn_range(vma, vma->vm_start, off >> PAGE_SHIFT,
			     vma->vm_end - vma->vm_start, vma->vm_page_prot))
		return -EAGAIN;

	return 0;
}

// sanity check
static int
venusfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
	struct venusfb_info *fbi = (struct venusfb_info *) info;
	u32 pitch, isResetVideoStandard = 0;


//	if (var->bits_per_pixel != 32) {
//		printk(" #@# Error BPP value %d (only 32-bits)\n", var->bits_per_pixel);
//		return -EINVAL;
//	}

    //printk("\n\r fun=%s line=%d var->xres=%d var->yres=%d\n",__FUNCTION__,__LINE__,var->xres,var->yres);
	// resolution check
	if (var->xres == 720) {
		if (var->yres != 480 && var->yres != 576)
			var->yres = 480;
	}
	else if (var->xres == 1280) {
		if (var->yres != 720)
			var->yres = 720;
	}
	else if (var->xres == 1920) {
		if (var->yres != 1080)
			var->yres = 1080;
	}
	else if (var->xres == 1366) {
		if (var->yres != 768)
			var->yres = 768;
	}
	else {
		var->xres = 720;
		var->yres = 480;
	}

	if (var->xres_virtual < var->xres)
		var->xres_virtual = var->xres;

	if (var->yres_virtual < var->yres)
		var->yres_virtual = var->yres;


	// bpp check
	if (var->bits_per_pixel <= 8)
		var->bits_per_pixel = 8;
	else if (var->bits_per_pixel <= 16)
		var->bits_per_pixel = 16;
	else if (var->bits_per_pixel <= 32)
		var->bits_per_pixel = 32;
	else
		return -EINVAL;
    //printk("\n\r fun=%s line=%d var->xres=%d var->yres=%d var->bits_per_pixel=%d\n",__FUNCTION__,__LINE__,var->xres,var->yres,var->bits_per_pixel);
    //printk("\n\r fun=%s line=%d var->red=%d var->green=%d var->blue=%d var->transp=%d \n",__FUNCTION__,__LINE__,var->red,var->green,var->blue,var->transp);

	//+JT - keep application's request
#if 1
	fbi->video_info.rgb_info.red	= var->red;
	fbi->video_info.rgb_info.green	= var->green;
	fbi->video_info.rgb_info.blue	= var->blue;
	fbi->video_info.rgb_info.transp	= var->transp;
#else
	// RGB offset calibration
	switch(var->bits_per_pixel) {
	case 8:
		var->red		= rgb_8.red;
		var->green		= rgb_8.green;
		var->blue 		= rgb_8.blue;
		var->transp		= rgb_8.transp;
		break;
	default:
	case 16:
		var->red		= rgb_16.red;
		var->green		= rgb_16.green;
		var->blue 		= rgb_16.blue;
		var->transp		= rgb_16.transp;
		break;
	case 32:
		var->red		= rgb_32.red;
		var->green		= rgb_32.green;
		var->blue 		= rgb_32.blue;
		var->transp		= rgb_32.transp;
		break;
	}
#endif

//	var->xoffset			= 0;
//	var->yoffset			= 0;
	var->grayscale			= 0;

	var->left_margin		= 0;
	var->right_margin		= 0;
	var->upper_margin		= 0;
	var->lower_margin		= 0;
	var->hsync_len			= 0;
	var->vsync_len			= 0;
	var->sync			= FB_SYNC_EXT;
	var->nonstd			= 0;
	var->activate			= FB_ACTIVATE_NOW;
	var->height			= 0;
	var->width			= 0;
	var->accel_flags		= 0;
	var->vmode			= FB_VMODE_NONINTERLACED;

	// check if we need to reset video standard
	if ((fbi->video_info.xres != var->xres) || (fbi->video_info.yres != var->yres))
		isResetVideoStandard = 1;

	// sync with fbi->video_info
	fbi->video_info.pixclock	= var->xres * var->yres * 60;
	fbi->video_info.xres 		= var->xres;
	fbi->video_info.yres 		= var->yres;
	fbi->video_info.bpp		= var->bits_per_pixel;

	// we do not need to reset OSD resolution if we are in passive mode
	if (!atomic_read(&fbi->passive_mode)) {
		// check if it's TV panel resolution
		if ((var->xres == 1366) && (var->yres == 768)) {
			fbi->video_info.osdxres = 1280;
			fbi->video_info.osdyres = 768;
		} else {
			fbi->video_info.osdxres = var->xres;
			fbi->video_info.osdyres = var->yres;
		}
	}

	// recalculate the pixel clock
	var->pixclock			= 1000*(1000*1000*1000 / fbi->video_info.pixclock); // in pico-second unit

	if (1)
//		fbi->video_info.pitch 	= ((fbi->video_info.xres * (fbi->video_info.bpp / 8) + 0x0F) >> 4 ) << 4;
		fbi->video_info.pitch 	= fbi->video_info.xres * (fbi->video_info.bpp / 8);
	else {
		uint32_t ii;
		fbi->video_info.pitch 	= ((fbi->video_info.xres * (fbi->video_info.bpp / 8) + 0xFF) >> 8 ) << 8;

		// adjust pitch to power of 2 in 256 bytes unit
		for(ii=256; ; ii*=2) {
			if(fbi->video_info.pitch <= ii) {
				fbi->video_info.pitch = ii;
				break;
			}
		}
	}

	fbi->fb.fix.line_length = fbi->video_info.pitch;

	// check if we need to re-allocate memory
	if (1)
//		pitch 	= ((var->xres_virtual * (fbi->video_info.bpp / 8) + 0x0F) >> 4 ) << 4;
		pitch 	= var->xres_virtual * (fbi->video_info.bpp / 8);
	else {
		uint32_t ii;
		pitch 	= ((var->xres_virtual * (fbi->video_info.bpp / 8) + 0xFF) >> 8 ) << 8;

		// adjust pitch to power of 2 in 256 bytes unit
		for(ii=256; ; ii*=2) {
			if(pitch <= ii) {
				pitch = ii;
				break;
			}
		}
	}
	//printk(" @@@@@ %d %d %d \n", pitch, var->yres_virtual, fbi->video_info.videomemorysize);
    //printk("func=%s line=%d (pitch * var->yres_virtual)=%d fbi->video_info.videomemorysize=%d\n",__FUNCTION__,__LINE__,(pitch * var->yres_virtual),fbi->video_info.videomemorysize);

	if ((pitch * var->yres_virtual) > fbi->video_info.videomemorysize) {
		if (fbi->video_info.winID != -1) {
#ifdef CONFIG_RTK_KDRV_RPC
			video_clrDisplayArea(fbi);
#endif
			video_freeMemory(fbi);
			fbi->video_info.videomemorysize = PAGE_ALIGN((pitch * var->yres_virtual) + gFB_EXTRA_SIZE);
			printk(KERN_WARNING "FB size 2: %d %u\n", fbi->video_info.videomemorysize, gFB_EXTRA_SIZE);

			// calculate required videomemorysizeorder
			if (fbi->video_info.videomemorysize == (1 << (fls(fbi->video_info.videomemorysize) - 1)))
				fbi->video_info.videomemorysizeorder = fls(fbi->video_info.videomemorysize) - 13;
			else
				fbi->video_info.videomemorysizeorder = fls(fbi->video_info.videomemorysize) - 12;
			video_allocMemory(fbi);
#ifdef CONFIG_RTK_KDRV_RPC
			if (isResetVideoStandard)
				video_initDisplayArea(fbi);
			video_drawDisplayArea(fbi);
#endif
		} else {
			video_freeMemory(fbi);
			fbi->video_info.videomemorysize = PAGE_ALIGN((pitch * var->yres_virtual) + gFB_EXTRA_SIZE);
			printk(KERN_WARNING "FB size 3: %d %u\n", fbi->video_info.videomemorysize, gFB_EXTRA_SIZE);

			// calculate required videomemorysizeorder
			if (fbi->video_info.videomemorysize == (1 << (fls(fbi->video_info.videomemorysize) - 1)))
				fbi->video_info.videomemorysizeorder = fls(fbi->video_info.videomemorysize) - 13;
			else
				fbi->video_info.videomemorysizeorder = fls(fbi->video_info.videomemorysize) - 12;
			video_allocMemory(fbi);
		}
	} else if (isResetVideoStandard) {
		if (fbi->video_info.winID != -1) {
#ifdef CONFIG_RTK_KDRV_RPC
			video_clrDisplayArea(fbi);
			video_initDisplayArea(fbi);
			video_drawDisplayArea(fbi);
#endif
		}
	} else if (fbi->fb.var.bits_per_pixel != var->bits_per_pixel) {
		if (fbi->video_info.winID != -1) {
#ifdef CONFIG_RTK_KDRV_RPC
            //printk("func=%s line=%d fbi->fb.var.bits_per_pixel=%d var->bits_per_pixel=%d\n",__FUNCTION__,__LINE__,fbi->fb.var.bits_per_pixel,var->bits_per_pixel);
			video_clrDisplayArea(fbi);
			if (isResetVideoStandard)
				video_initDisplayArea(fbi);
			video_drawDisplayArea(fbi);
#endif
		}
	}

	return 0;
}

static int venusfb_set_par(struct fb_info *info)
{
	return 0;
}

/* ------------ Interfaces to hardware functions ------------ */

static struct fb_ops venusfb_ops = {
	.owner			= THIS_MODULE,
	.fb_open		= venusfb_open,
	.fb_release		= venusfb_release,
	.fb_read		= NULL, // venusfb_read # enable if mmap doesn't work
	.fb_write		= NULL, // venusfb_write # enable if mmap doesn't work
	.fb_check_var		= venusfb_check_var,
	.fb_set_par		= venusfb_set_par,
	.fb_ioctl		= venusfb_ioctl,
	.fb_pan_display		= venusfb_pan_display,
#ifdef CONFIG_ANDROID_TV
	.fb_blank		= venusfb_blank,
#endif
	.fb_setcolreg		= venusfb_setcolreg,
	.fb_fillrect		= cfb_fillrect,
	.fb_copyarea		= cfb_copyarea,
	.fb_imageblit		= cfb_imageblit,
//	.fb_cursor		= soft_cursor,
	.fb_mmap		= venusfb_mmap,
};

/*
 *  Initialization
 */
static struct venusfb_info *  __init venusfb_init_fbinfo(struct platform_device *dev)
{
	struct venusfb_info *fbi = NULL;

	// fill venusfb_info
	fbi = (struct venusfb_info *)framebuffer_alloc(sizeof(struct venusfb_info) - sizeof(struct fb_info), &dev->dev);

	if (!fbi) {
		printk("VenusFB: framebuffer_alloc(%d) failed ..\n", sizeof(struct venusfb_info) - sizeof(struct fb_info));
		goto err;
	}

	memset(fbi, 0, sizeof(struct venusfb_info));
	fbi->dev = &dev->dev;
	reset_video_info(fbi);

err:
	return fbi;
}

static int __init venusfb_probe(struct platform_device *dev)
{
	struct venusfb_info *fbi = NULL;
	int ret;

	/* initialize fbi */
	fbi = venusfb_init_fbinfo(dev);
	if (!fbi){
		printk("VenusFB: error: can't allocate memory for fbi\n");
		return -ENOMEM;
	}

//	venusfb_check_var(&fbi->fb.var, &fbi->fb);

	// framebuffer device registeration
	ret = register_framebuffer(&fbi->fb);
	if (ret < 0)
		goto failed;
	platform_set_drvdata(dev, &fbi->fb);

	printk("VenusFB: load successful (%dx%dx%dbbp)\n", fbi->video_info.xres, fbi->video_info.yres, fbi->video_info.bpp);

	return 0;

failed:

	framebuffer_release((struct fb_info *)fbi);
	return ret;
}

static int venusfb_remove(struct platform_device *dev)
{
	struct fb_info *info = platform_get_drvdata(dev);

	printk("VenusFB: removing..\n");
	if (info) {
		unregister_framebuffer(info);
		framebuffer_release(info);
	}
	return 0;
}

static struct platform_driver venusfb_driver = {
	.probe	= venusfb_probe,
	.remove = venusfb_remove,
	.driver = {
		.name	= "venusfb",
	},
};

static struct platform_device *venusfb_device;

/*
 * Initialization
 */
static int __init venusfb_init(void)
{
	int ret;
//fix for Klocwork:0144122 144178 144234
#ifndef MODULE
	char *options = NULL;
#endif
	printk("VenusFB: Framebuffer device driver for Realtek Media Processors\n");

#ifndef MODULE
	// KWarning: checked ok by cklai@realtek.com
	if (fb_get_options("venusfb", &options))
		return -ENODEV;
	setup_venus_video_info(options);
#endif
	ret = platform_driver_register(&venusfb_driver);
	if (!ret) {
		venusfb_device = platform_device_alloc("venusfb", 0);

		if (venusfb_device)
			ret = platform_device_add(venusfb_device);
		else
			ret = -ENOMEM;

		if (ret) {
			platform_device_put(venusfb_device);
			platform_driver_unregister(&venusfb_driver);
		}
	}
	return ret;
}

/*
 * Cleanup
 */
static void __exit venusfb_cleanup(void)
{
	platform_device_unregister(venusfb_device);
	platform_driver_unregister(&venusfb_driver);
}

module_init(venusfb_init);
module_exit(venusfb_cleanup);

MODULE_AUTHOR("Chih-pin Wu, Realtek Semiconductor");
MODULE_DESCRIPTION("Framebuffer driver for Venus/Neptune/Mars");
MODULE_LICENSE("GPL v2");
