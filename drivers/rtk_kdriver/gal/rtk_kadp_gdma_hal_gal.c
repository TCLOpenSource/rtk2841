#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/kernel.h>   /* DBG_PRINT()    */
#include <linux/slab.h>     /* kmalloc()      */
#include <linux/fs.h>       /* everything...  */
#include <linux/errno.h>    /* error codes    */
#include <linux/types.h>    /* size_t         */
#include <linux/dma-mapping.h>
#include <asm/uaccess.h>    /* copy_*_user    */
#include <asm/barrier.h> /*dsb()*/
#include <mach/irqs.h>
#include <linux/interrupt.h>
#include <rbus/ppoverlay_reg.h>

#include <mach/irqs.h>
#include <mach/platform.h>
#include <linux/platform_device.h>
#include <gal/rtk_kadp_gdma_hal_gal_export_user.h>
#include <gal/rtk_kadp_gdma_hal_gal_driver.h>

#include <gal/rtk_kadp_hal_gal_surface.h>

#include <gal/rtk_gdma_driver.h>
/*#include "rtk_gdma_export_user.h"*/
#include <gal/rtk_osdcomp_driver.h>


#include <linux/string.h>

int GDMA_hal_gal_init_module(void);
int GDMA_hal_gal_init (bool flag);
int GDMA_hal_gal_finalize (bool flag);

int gdma_hal_gal_major   = GDMA_HAL_GAL_MAJOR ;
int gdma_hal_gal_minor;
int gdma_hal_gal_nr_devs = GDMA_HAL_GAL_NR_DEVS ;
extern void HAL_VBE_DISP_TCON_H_Reverse(UINT8 u8Mode);

unsigned int gGALDebugLevel =
	(DBG_GAL_PRIV_FATAL | DBG_GAL_PRIV_ERROR | DBG_GAL_PRIV_WARNING);

static struct class *gdma_hal_gal_class ;
gdma_hal_gal_dev *gdma_hal_gal_devices;          /* allocated in gdma_init_module */





int GDMA_hal_gal_setframebuffer(KDRV_GAL_SURFACE_FRAMEBUFFER_INFO_T *data);

/*
#define DRV_NAME                "gdma_hal_gal"
static const char  drv_name[] = DRV_NAME;
static struct platform_device *gdma_hal_gal_devs = 0;

static struct platform_driver gdma_hal_gal_driver =
{
.driver =
{
.name         = (char *)drv_name,
.bus          = &platform_bus_type,
},
};
*/
/*for STR, WOL, power off ..etc cases,
 if D-domain is disable, OSD needn't update and print only 1 time msg
 */
static bool gdma_print_cnt = true;

static void gdma_print_d_domain_msg(void) {
	if(gdma_print_cnt == true) {
		printk(KERN_ERR"[OSD]D-domain(%08x) = %08x, drop OSD update.\n",
			PPOVERLAY_Display_Timing_CTRL1_reg,
			rtd_inl(PPOVERLAY_Display_Timing_CTRL1_reg));
		gdma_print_cnt = false;
	}

}


struct file_operations gdma_hal_gal_fops
	= {
	.owner    =    THIS_MODULE,
	.llseek   =    GDMA_hal_gal_llseek,
	.read     =    GDMA_hal_gal_read,
	.write    =    GDMA_hal_gal_write,
	.unlocked_ioctl    =    (void *)GDMA_hal_gal_ioctl,
	.open     =    GDMA_hal_gal_open,
	.release  =    GDMA_hal_gal_release,
} ;

loff_t GDMA_hal_gal_llseek(struct file *filp, loff_t off, int whence)
{
	return -EINVAL ;
}
ssize_t GDMA_hal_gal_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	return -EFAULT ;
}
ssize_t GDMA_hal_gal_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	return -EFAULT ;
}
int GDMA_hal_gal_open(struct inode *inode, struct file *filp)
{
	return 0 ;
}

int GDMA_hal_gal_release(struct inode *inode, struct file *filp)
{
	return 0 ;
}
void DBGGALDebugPrintf(int ui32DebugLevel,
					   const char *pszFileName,
					   unsigned int ui32Line,
					   const char *pszFormat, ...)
{
	if ((gGALDebugLevel & ui32DebugLevel) == 0)
		return ;
	pr_debug(KERN_ERR "(%s -- %d) ", pszFileName, ui32Line);
	/*va_start(args, pszFormat);*/
	/*printk(KERN_ERR pszFormat,args)*/
	printk(pszFormat);
	/*va_start(args, pszFormat);*/
	/*vprintk_emit(0,KERN_ERR, NULL, 0, pszFormat, args);*/
	pr_debug(KERN_ERR " \n");
	/*va_end(args);*/
}
int GDMA_hal_gal_init (bool flag)
{
	gdma_hal_gal_dev *gdma_hal_gal = &gdma_hal_gal_devices[0] ;


	if (gdma_hal_gal->initialized == true) {
		DBG_GAL_PRINT("gdma_hal_gal dup init\n");
		return GDMA_HAL_GAL_SUCCESS;
	}


	/*clear gal data*/
	memset(&gdma_hal_gal->gal, 0x0, sizeof(KDRV_GAL_GLOBE_GAL_INFO_T));
	memset(&gdma_hal_gal->gPal, 0x0,sizeof(KDRV_GAL_GLOBE_GAL_SUR_LINK_PALETTE_INFO_T));

	/*only in first init*/
	kRtHAL_GAL_InitSurfaceAll();

	gdma_hal_gal->initialized = true;


	/*DBG_GAL_PRINT("%s--%d gdma_hal_gal->initialized=%d,\n",__FUNCTION__,__LINE__, gdma_hal_gal->initialized);*/
	/*always print this*/
	pr_debug(KERN_WARNING " %s--%d gdma_hal_gal->initialized=%d,\n", __FUNCTION__, __LINE__, gdma_hal_gal->initialized);

	return GDMA_HAL_GAL_SUCCESS;
}

int GDMA_hal_gal_finalize (bool flag)
{
	gdma_hal_gal_dev *gdma_hal_gal = &gdma_hal_gal_devices[0] ;

	kRtHAL_GAL_DestroySurfaceAll();

	gdma_hal_gal->initialized = false;

	/*DBG_GAL_PRINT("%s--%d gdma_hal_gal->initialized=%d,\n",__FUNCTION__,__LINE__, gdma_hal_gal->initialized);*/
	pr_debug(KERN_WARNING " %s--%d gdma_hal_gal->initialized=%d,\n", __FUNCTION__, __LINE__, gdma_hal_gal->initialized);

	return GDMA_HAL_GAL_SUCCESS;
}
static int GDMA_hal_gal_dump_palette(KADP_HAL_GAL_PALETTE_INFO_T *info)
{
	int i = 0;
	if (info == NULL)
		return GDMA_HAL_GAL_FAIL;
	DBG_GAL_PRINT("palette length %d  \n", info->length);
	for (i = 0; i < MAX_PALETTE_SIZE; i++) {
		DBG_GAL_PRINT("[ %x ] \n", info->palette[i]);
		if (i%20 == 0) {
			DBG_GAL_PRINT("\n");
			i++;
		}
	}
	return GDMA_HAL_GAL_SUCCESS;
}

static int GDMA_hal_gal_dump_surface(KADP_HAL_GAL_SURFACE_INFO_T *info)
{
	if (info == NULL)
		return GDMA_HAL_GAL_FAIL;
	DBG_GAL_PRINT("offset: %x  physicalAddress:0x%x \n", info->offset, info->physicalAddress);
	DBG_GAL_PRINT("pitch : %d  bpp: %d \n", info->pitch, info->bpp);
	DBG_GAL_PRINT("width: %d  height:0x%x \n", info->width, info->height);
	DBG_GAL_PRINT("pixelFormat: %d  \n", info->pixelFormat);
	return GDMA_HAL_GAL_SUCCESS;
}

static int GDMA_hal_gal_dump_fbpropertyexInfo(KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_EXTENDED_INFO_T *info)
{
	if (info == NULL)
		return GDMA_HAL_GAL_FAIL;
	DBG_GAL_PRINT(" v.x: %d v.y: %d v.w: %d v.h: %d \n", info->viewRect.x, info->viewRect.y, info->viewRect.w, info->viewRect.h);
	DBG_GAL_PRINT(" d.x: %d d.y: %d d.w: %d d.h: %d \n", info->dispRect.x, info->dispRect.y, info->dispRect.w, info->dispRect.h);
	DBG_GAL_PRINT(" bStereoscope: %x \n", info->bStereoscope);
	DBG_GAL_PRINT(" stereoscopeType: %x  \n", info->stereoscopeType);
	return GDMA_HAL_GAL_SUCCESS;
}
static int GDMA_hal_gal_dump_globeframebufferinfo(KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *info)
{
	if (info == NULL)
		return GDMA_HAL_GAL_FAIL;

	DBG_GAL_PRINT(" pixelFormat: %x bStereoscope: %x\n", info->pixelFormat, info->bStereoscope);
	DBG_GAL_PRINT(" maxWidth: %d  maxHeight: %d\n", info->maxWidth, info->maxHeight);
	DBG_GAL_PRINT(" stereoscopeType: %x bVisibility: %x  bVsync: %x \n", info->stereoscopeType, info->bVisibility, info->bVsync);
	DBG_GAL_PRINT(" v.x: %d v.y: %d v.w: %d v.h: %d \n", info->viewRect.x, info->viewRect.y, info->viewRect.w, info->viewRect.h);
	DBG_GAL_PRINT(" d.x: %d d.y: %d d.w: %d d.h: %d \n", info->dispRect.x, info->dispRect.y, info->dispRect.w, info->dispRect.h);
	GDMA_hal_gal_dump_surface(&info->pSurfaceList[0]);
	return GDMA_HAL_GAL_SUCCESS;
}

static int GDMA_hal_gal_dump_cursorproperty(KADP_HAL_GAL_CURSOR_PROPERTY_INFO_T *info)
{
	if (info == NULL)
		return GDMA_HAL_GAL_FAIL;
	DBG_GAL_PRINT(" panelWidth: %d panelHeight: %d\n", info->panelWidth, info->panelHeight);
	DBG_GAL_PRINT(" width: %d height: %d\n", info->width, info->height);
	DBG_GAL_PRINT(" p.x: %d p.y: %d hotspot=%d\n", info->position.x, info->position.y, info->hotspot);
	DBG_GAL_PRINT(" Gp.x: %d Gp.y: %d \n", info->cursorGapPosition.x, info->cursorGapPosition.y);
	return GDMA_HAL_GAL_SUCCESS;
}
int GDMA_hal_gal_createsurfacelinkpalette(UINT32 phyaddr)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	KADP_HAL_GAL_SUR_LINK_PALETTE_INFO_T *gslp_data;
    int i=0;
	gslp_data = &gdma_hal_gal->gPal.gSurLinkPal[0];
	/*lock*/
	down(&gdma_hal_gal->sem_slp);
	for(i=0;i<MAX_SURFACE_LINK_PALETTE;i++){
        if(gslp_data->used == 0){
            gslp_data->used = 1;
			gslp_data->physicalAddress = phyaddr;
			break;
		}
		gslp_data++;
	}
	/*unlock*/
	up(&gdma_hal_gal->sem_slp);
	if(i > MAX_SURFACE_LINK_PALETTE)
		return GDMA_HAL_GAL_FAIL;
	return GDMA_HAL_GAL_SUCCESS;
}
int GDMA_hal_gal_setsurfacelinkpalette(KDRV_GAL_PALETTE_SURFACE_INFO_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	KADP_HAL_GAL_SUR_LINK_PALETTE_INFO_T *gslp_data;
	UINT32 phyaddr;
	int i=0;
	gslp_data = &gdma_hal_gal->gPal.gSurLinkPal[0];
	phyaddr = data->Surface.physicalAddress;

	/*lock*/
	down(&gdma_hal_gal->sem_slp);
	for(i=0;i<MAX_SURFACE_LINK_PALETTE;i++){
		if((gslp_data->physicalAddress == phyaddr) && (gslp_data->used == 1)){
			//we found it
			memcpy(&gslp_data->palette[0],&data->palette.palette[0],sizeof(UINT32)*MAX_PALETTE_SIZE);
			gslp_data->length = data->palette.length;
			break;
		}
		gslp_data++;
	}
	/*unlock*/
	up(&gdma_hal_gal->sem_slp);
	if(i > MAX_SURFACE_LINK_PALETTE)
		return GDMA_HAL_GAL_FAIL;
	return GDMA_HAL_GAL_SUCCESS;
}
int GDMA_hal_gal_getsurfacelinkpalette(KDRV_GAL_PALETTE_SURFACE_INFO_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	KADP_HAL_GAL_SUR_LINK_PALETTE_INFO_T *gslp_data;
	UINT32 phyaddr;
    int i=0;
	gslp_data = &gdma_hal_gal->gPal.gSurLinkPal[0];
	phyaddr = data->Surface.physicalAddress;

	/*lock*/
	down(&gdma_hal_gal->sem_slp);
	for(i=0;i<MAX_SURFACE_LINK_PALETTE;i++){
        if((gslp_data->physicalAddress == phyaddr) && (gslp_data->used == 1)){
            //we found it
			memcpy(&data->palette.palette[0],&gslp_data->palette[0],sizeof(UINT32)*MAX_PALETTE_SIZE);
			data->palette.length = gslp_data->length;
			break;
		}
		gslp_data++;
	}
	/*unlock*/
	up(&gdma_hal_gal->sem_slp);

	if(i > MAX_SURFACE_LINK_PALETTE)
		return GDMA_HAL_GAL_FAIL;
	return GDMA_HAL_GAL_SUCCESS;
}

int GDMA_hal_gal_deletesurfacelinkpalette(UINT32 phyaddr)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	KADP_HAL_GAL_SUR_LINK_PALETTE_INFO_T *gslp_data;
    int i=0;
	gslp_data = &gdma_hal_gal->gPal.gSurLinkPal[0];
	/*lock*/
	down(&gdma_hal_gal->sem_slp);
	for(i=0;i<MAX_SURFACE_LINK_PALETTE;i++){
        if(gslp_data->physicalAddress == phyaddr){
            gslp_data->used = 0;
			gslp_data->physicalAddress = 0;
			break;
		}
		gslp_data++;
	}
	/*unlock*/
	up(&gdma_hal_gal->sem_slp);
	if(i > MAX_SURFACE_LINK_PALETTE)
		return GDMA_HAL_GAL_FAIL;
	return GDMA_HAL_GAL_SUCCESS;
}

int GDMA_hal_gal_getsurfacepalette(KDRV_GAL_PALETTE_SURFACE_INFO_T *data)
{
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
	GDMA_hal_gal_dump_surface(&data->Surface);
	GDMA_hal_gal_dump_palette(&data->palette);
#endif
	if (GDMA_GetOSDPalette(0, &data->palette.palette[0], &data->palette.length) != GDMA_SUCCESS)
		return GDMA_HAL_GAL_FAIL;
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}
int GDMA_hal_gal_setsurfacepalette(KDRV_GAL_PALETTE_SURFACE_INFO_T *data)
{
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
	GDMA_hal_gal_dump_surface(&data->Surface);
	GDMA_hal_gal_dump_palette(&data->palette);
#endif
	if (GDMA_SetOSDPalette(0, &data->palette.palette[0], data->palette.length) != GDMA_SUCCESS)
		return GDMA_HAL_GAL_FAIL;

#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}


int GDMA_hal_gal_setframebufferwithproperty(KDRV_GAL_SURFACE_FRAMEBUFFER_PROPERTY_FLAG_INFO_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	unsigned int fb_index = data->fbHWControllerIndex;
	KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_FLAGS_T fbPropertyFlags = data->flag;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	KADP_HAL_GAL_SURFACE_INFO_T *pSurface;
	KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_EXTENDED_INFO_T *pFbPropertyExInfo;

	/*lock*/
	down(&gdma_hal_gal->sem);
	pFbPropertyExInfo = &data->extend_info;
	gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[fb_index];
	pSurface = &gf_data->pSurfaceList[0];
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
	DBG_GAL_PRINT(" fb_index : %d \n", fb_index);
	GDMA_hal_gal_dump_fbpropertyexInfo(pFbPropertyExInfo);
	GDMA_hal_gal_dump_surface(pSurface);
	GDMA_hal_gal_dump_globeframebufferinfo(gf_data);
#endif
	if ((data->Surface.physicalAddress != 0) && (pSurface->physicalAddress != data->Surface.physicalAddress)) {
		/*update Surface data*/
		memcpy(pSurface, &(data->Surface), sizeof(KADP_HAL_GAL_SURFACE_INFO_T));
	}
	if (KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_NOFX == fbPropertyFlags) {
		/*unlock*/
		up(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
		DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
        return GDMA_hal_gal_setframebuffer((KDRV_GAL_SURFACE_FRAMEBUFFER_INFO_T *)data);
		//return GDMA_HAL_GAL_SUCCESS;
	} else {
		if (fbPropertyFlags & KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_VIEWRECT) {
			/*update view Rect*/
			memcpy(&gf_data->viewRect, &pFbPropertyExInfo->viewRect, sizeof(KADP_HAL_GAL_RECT_T));
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
			DBG_GAL_PRINT(" v.x: %d v.y: %d v.w: %d v.h: %d \n",
						  gf_data->viewRect.x, gf_data->viewRect.y, gf_data->viewRect.w, gf_data->viewRect.h);
#endif
		}
		if (fbPropertyFlags & KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_DISPRECT) {
			/*update dispRect Rect*/
			memcpy(&gf_data->dispRect, &pFbPropertyExInfo->dispRect, sizeof(KADP_HAL_GAL_RECT_T));
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
			DBG_GAL_PRINT(" d.x: %d d.y: %d d.w: %d d.h: %d \n",
						  gf_data->dispRect.x, gf_data->dispRect.y, gf_data->dispRect.w, gf_data->dispRect.h);
#endif
		}
		if (fbPropertyFlags & KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_STEREOSCOPE) {
			gf_data->stereoscopeType = pFbPropertyExInfo->stereoscopeType;
			gf_data->bStereoscope = pFbPropertyExInfo->bStereoscope;
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
			DBG_GAL_PRINT(" bStereoscope: %d  stereoscopeType: %x\n", gf_data->bStereoscope, gf_data->stereoscopeType);
#endif

		}
	}
	/*unlock*/
	up(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
    return GDMA_hal_gal_setframebuffer((KDRV_GAL_SURFACE_FRAMEBUFFER_INFO_T *)data);
	//return GDMA_HAL_GAL_SUCCESS;
}

int GDMA_hal_gal_resetframebuffer(unsigned int fbHWControllerIndex)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	unsigned int fb_index = fbHWControllerIndex;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	KADP_HAL_GAL_SURFACE_INFO_T *pSurface;
	/*GDMA_PICTURE_OBJECT *picObj;*/
	/*COMP_PICTURE_OBJECT com_picObj;*/
	/*lock*/
	down(&gdma_hal_gal->sem);
	gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[fb_index];
	pSurface = &gf_data->pSurfaceList[0];
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
	DBG_GAL_PRINT(" fb_index : %d \n", fb_index);
	GDMA_hal_gal_dump_surface(pSurface);
	GDMA_hal_gal_dump_globeframebufferinfo(gf_data);
#endif
	if (gf_data->bVisibility) {
		switch (fb_index) {
		case 0:
			GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD1, 1);
			break;
		case 1:
			GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD2, 1);
			break;
		case 2:
			GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD3, 1);
			break;
		default:
			DBG_GAL_PRINT("GDMA HAL GAL: invalid fb_index: %d !!\n", fb_index);
			break;
		}
	} else {
		switch (fb_index) {
		case 0:
			GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD1, 0);
			break;
		case 1:
			GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD2, 0);
			break;
		case 2:
			GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD3, 0);
			break;
		default:
			DBG_GAL_PRINT("GDMA HAL GAL: invalid fb_index: %d !!\n", fb_index);
			break;
		}
	}

	/*unlock*/
	up(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}
int GDMA_hal_gal_setframebuffer(KDRV_GAL_SURFACE_FRAMEBUFFER_INFO_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	unsigned int fb_index = data->fbHWControllerIndex;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	KADP_HAL_GAL_SURFACE_INFO_T *pSurface;
	GDMA_PICTURE_OBJECT *picObj;
	PICTURE_LAYERS_OBJECT *pic_layer = NULL;
	osd_planealpha_ar osdcmp_plane_ar;
	osd_planealpha_gb osdcmp_plane_gb;
	KADP_HAL_GAL_CURSOR_PROPERTY_INFO_T *pcursor_info;
	KDRV_GAL_GLOBE_GAL_INFO_T *g_data;
	/*lock*/
	if (fb_index == 0)
		down(&gdma_hal_gal->sem);
	else if (fb_index == 2)
		down(&gdma_hal_gal->sem_mouse);

	gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[fb_index];
	pSurface = &gf_data->pSurfaceList[0];
	g_data = &gdma_hal_gal->gal;
	pcursor_info = &g_data->cursor_info[fb_index];
	memcpy(pSurface, &(data->Surface), sizeof(KADP_HAL_GAL_SURFACE_INFO_T));
	pic_layer = (PICTURE_LAYERS_OBJECT *)kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
	if (pic_layer == NULL) {
		pr_debug("%s, pic_layer kmalloc failed \n", __FUNCTION__);
		if (fb_index == 0)
			up(&gdma_hal_gal->sem);
		else if (fb_index == 2)
			up(&gdma_hal_gal->sem_mouse);
		return GDMA_HAL_GAL_FAIL;
	}
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	/*DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));*/
	DBG_GAL_PRINT(" fb_index : %d \n", fb_index);
	GDMA_hal_gal_dump_surface(pSurface);
	GDMA_hal_gal_dump_globeframebufferinfo(gf_data);
#endif
	if ((gf_data->dispRect.w == 0) || (gf_data->dispRect.h == 0)) {
		gf_data->dispRect.w = gf_data->viewRect.w;
		gf_data->dispRect.h = gf_data->viewRect.h;
	}

	if (fb_index == CURSOR_TO_FRAMEBUFFER_INDEX && gf_data->bVisibility) {
		gf_data->viewRect.h = pcursor_info->height;
		gf_data->viewRect.w = pcursor_info->width;
		gf_data->dispRect.w = pcursor_info->panelWidth;
  		gf_data->dispRect.h = pcursor_info->panelHeight;
	}

	if (gf_data->bVisibility && (gf_data->viewRect.w != 0)
	   && (gf_data->viewRect.h != 0) && (gf_data->dispRect.w != 0) && (gf_data->dispRect.w != 0)) {
		switch (fb_index) {
		case 0:
			GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD1, 1);
			break;
		case 1:
			GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD2, 1);
			break;
		case 2:
			GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD3, 1);
			break;
		default:
			DBG_GAL_PRINT("GDMA HAL GAL: invalid fb_index: %d !!\n", fb_index);
			break;
		}

		memset(pic_layer, 0, sizeof(PICTURE_LAYERS_OBJECT));

		//printk(KERN_ERR " \n [GAL calvin][GDMA_hal_gal_setframebuffer] [fmt=%x][fb_index=%x]\n", pSurface->pixelFormat, fb_index);
             //fixme: KADP_HAL_GAL_PIXEL_FORMAT_ARGB1555 should be replaced by KADP_HAL_GAL_PIXEL_FORMAT_FBDC. calvin
		if((pSurface->pixelFormat == KADP_HAL_GAL_PIXEL_FORMAT_FBC) && (fb_index == 0)) //fb_index=0 is for UI
		{
		    pic_layer->layer[0].fbdc_num 	= 1;
		    picObj 					= &pic_layer->layer[0].fbdc[0];
		    picObj->src_type 			= SRC_FBDC;
		    //printk(KERN_ERR " \n [GAL calvin][GDMA_hal_gal_setframebuffer] [fmt=%x][fb_index=%x]\n", pSurface->pixelFormat, fb_index);
		}
		else
		{
		    pic_layer->layer[0].normal_num      = 1;
		    picObj 					   = &pic_layer->layer[0].normal[0];
		    picObj->src_type 			   = SRC_NORMAL;
		}

		switch (pSurface->pixelFormat) {
		case KADP_HAL_GAL_PIXEL_FORMAT_FBC:
			picObj->fbdc_format = FBDC_COLOR_FORMAT_U8U8U8U8;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_ARGB:
			picObj->format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_LUT8:
			picObj->format = VO_OSD_COLOR_FORMAT_8BIT;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_ARGB1555:
			picObj->format = VO_OSD_COLOR_FORMAT_ARGB1555_LITTLE;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_RGB16:
			picObj->format = VO_OSD_COLOR_FORMAT_RGB565_LITTLE;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_ARGB4444:
			picObj->format = VO_OSD_COLOR_FORMAT_ARGB4444_LITTLE;
			break;
		default:
			picObj->format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
			break;
		}
		switch (fb_index) {
		case 0:
			picObj->plane = VO_GRAPHIC_OSD1;
			pic_layer->layer[0].onlineOrder = C0;
			break;
		case 1:
			picObj->plane = VO_GRAPHIC_OSD2;
			pic_layer->layer[0].onlineOrder = C1;
			break;
		case 2:
			picObj->plane = VO_GRAPHIC_OSD3;
			pic_layer->layer[0].onlineOrder = C2;
			break;
		default:
			DBG_GAL_PRINT("GDMA HAL GAL: invalid fb_index: %d !!\n", fb_index);
			break;
		}

            //fixme: need to remove after KADP_HAL_GAL_PIXEL_FORMAT_FBDC is ready. calvin
		if((pSurface->pixelFormat == KADP_HAL_GAL_PIXEL_FORMAT_FBC) && (fb_index == 0))
		{
		 	picObj->fbdc_format = FBDC_COLOR_FORMAT_U8U8U8U8;
		}

		pic_layer->layer_num = 1;
		//pic_layer->layer[0].onlineOrder = C0;
		//picObj->format;
		//picObj->fbdc_format;
		picObj->context = 0;
		picObj->key_en = 0;
		picObj->colorkey = -1;
		picObj->alpha = 0;
		picObj->x = 0;
		picObj->y = 0;
		picObj->width = gf_data->viewRect.w;

		picObj->height = gf_data->viewRect.h;

		picObj->address = pSurface->physicalAddress+(gf_data->viewRect.y*(pSurface->pitch) + (gf_data->viewRect.x*pSurface->bpp)/8);
		picObj->pitch = (pSurface->pitch);
		//picObj->seg_addr[MAX_SEG_NUM];
		//picObj->picLayout;
		picObj->compressed = 0;
		//picObj->wbType;
		//picObj->seg_num;
		//picObj->current_comp_idx;
		//picObj->comp_plane;
		//picObj->plane;
		//picObj->dst_x;
		//picObj->dst_y;
		//picObj->dst_width;
		//picObj->dst_height;
		picObj->layer_used = 1;
		osdcmp_plane_ar.plane_alpha_r = 0xff;
		osdcmp_plane_ar.plane_alpha_a = 0xff;
		osdcmp_plane_gb.plane_alpha_b = 0xff;
		osdcmp_plane_gb.plane_alpha_g = 0xff;
		picObj->plane_ar = osdcmp_plane_ar;
		picObj->plane_gb = osdcmp_plane_gb;
		picObj->clear_x.value = 0;
		picObj->clear_y.value = 0;
		picObj->show = 1;
		picObj->decompress = 0;
		picObj->paletteformat = 1;/* rgba format */
		//picObj->paletteIndex;
		//picObj->rgb_order;
		picObj->syncInfo.syncstamp = 0;
		//picObj->offlineOrder;
		picObj->scale_factor = 1;
		//picObj->isFromOffline;

		if (fb_index == 2) {
			picObj->dst_x = pcursor_info->position.x;
			picObj->dst_y = pcursor_info->position.y;
		} else {
			picObj->dst_x = gf_data->dispRect.x;
			picObj->dst_y = gf_data->dispRect.y;
		}
		picObj->dst_width = gf_data->dispRect.w;
		picObj->dst_height = gf_data->dispRect.h;

		if ((gf_data->bStereoscope == TRUE) && (gf_data->stereoscopeType == KADP_HAL_GAL_STEREOSCOPE_S3D))
			picObj->picLayout = INBAND_CMD_GRAPHIC_SIDE_BY_SIDE;

		switch (gdma_hal_gal->gal.rorate_type) {
		case KADP_HAL_GAL_OSD_ROTATE_90_DEGREE:
			break;
		case KADP_HAL_GAL_OSD_ROTATE_270_DEGREE:
			break;
		default:
			break;
		}

		GDMA_ReceivePicture(pic_layer);

	}

	if (pic_layer)
		kfree(pic_layer);

	/*unlock*/
	if (fb_index == 0)
		up(&gdma_hal_gal->sem);
	else if (fb_index == 2)
		up(&gdma_hal_gal->sem_mouse);

#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	/*DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));*/
#endif
	return GDMA_HAL_GAL_SUCCESS;
}

int GDMA_hal_gal_setfbhwcontrollervisibility(KDRV_GAL_FRAMEBUFFER_VISIBILITY_LIST_INFO_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	unsigned int i = 0;
	unsigned int fb_index = 0;
	/*lock*/
	down(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
#endif
	for (i = 0; i < data->changedFbNum; i++) {
		fb_index = data->list[i].fbHWControllerIndex;
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
		DBG_GAL_PRINT(" fb_index : %d \n", fb_index);
		DBG_GAL_PRINT(" bVisibility : %d \n", data->list[i].bVisibility);
#endif
		if (fb_index < MAX_FRAMEBUFFER_NUMBER) {
			gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[fb_index];
			gf_data->bVisibility =  data->list[i].bVisibility;
			switch (fb_index) {
			case 0:
				if (gf_data->bVisibility == FALSE) {
					GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD1, 0);
				} else {
					GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD1, 1);
				}
				break;
			case 1:
				if (gf_data->bVisibility == FALSE) {
					GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD2, 0);
				} else {
					GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD2, 1);
				}
				break;
			case 2:
				if (gf_data->bVisibility == FALSE) {
					GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD3, 0);
				} else {
					GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD3, 1);
				}
				break;
			default:
				DBG_GAL_PRINT("GDMA HAL GAL: invalid fb_index: %d !!\n", fb_index);
				break;
			}
		}
	}
	/*unlock*/
	up(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}
int GDMA_hal_gal_setfbhwcontrollervsync(KDRV_GAL_FRAMEBUFFER_VSYNC_INFO_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	unsigned int fb_index = data->fbHWControllerIndex;
	/*lock*/
	down(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
#endif
	gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[fb_index];
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBG_GAL_PRINT(" fb_index : %d \n", fb_index);
	DBG_GAL_PRINT(" bVsync : %d \n", data->bVsync);
#endif
	gf_data->bVsync = data->bVsync;
	if (gf_data->bVsync)
		GDMA_Sync_Enable();
	else
		GDMA_Sync_Disable();

	/*unlock*/
	up(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}
int GDMA_hal_gal_movecursor(KDRV_GAL_FRAMEBUFFER_CURSORPROPERTY_INFO_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	KDRV_GAL_GLOBE_GAL_INFO_T *g_data;
	KADP_HAL_GAL_CURSOR_PROPERTY_INFO_T *pcursor_info;

	unsigned int fb_index = data->fbHWControllerIndex;

	gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[fb_index];
	/*lock*/
	down(&gdma_hal_gal->sem_mouse);

	g_data = &gdma_hal_gal->gal;
	memcpy(&g_data->cursor_info[fb_index], &data->CursorProperty, sizeof(KADP_HAL_GAL_CURSOR_PROPERTY_INFO_T));
	pcursor_info = &g_data->cursor_info[fb_index];
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
	GDMA_hal_gal_dump_cursorproperty(pcursor_info);
#endif
	if (gf_data->bVisibility && fb_index == CURSOR_TO_FRAMEBUFFER_INDEX) {
		KADP_HAL_GAL_SURFACE_INFO_T *pSurface;
		GDMA_PICTURE_OBJECT *picObj;
		PICTURE_LAYERS_OBJECT *pic_layer = NULL;
		osd_planealpha_ar osdcmp_plane_ar;
		osd_planealpha_gb osdcmp_plane_gb;

		pSurface = &gf_data->pSurfaceList[0];
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
		GDMA_hal_gal_dump_surface(pSurface);
#endif
		pic_layer = (PICTURE_LAYERS_OBJECT *)kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
		if (pic_layer == NULL) {
			pr_debug("%s pic_layer kmalloc failed \n", __FUNCTION__);
			up(&gdma_hal_gal->sem_mouse);
			return GDMA_HAL_GAL_FAIL;
		}
		memset(pic_layer, 0, sizeof(PICTURE_LAYERS_OBJECT));
		picObj = &pic_layer->layer[0].normal[0];

		picObj->plane = VO_GRAPHIC_OSD3;

		switch (pSurface->pixelFormat) {
		case KADP_HAL_GAL_PIXEL_FORMAT_ARGB:
		case KADP_HAL_GAL_PIXEL_FORMAT_FBC:
			picObj->format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_LUT8:
			picObj->format = VO_OSD_COLOR_FORMAT_8BIT;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_ARGB1555:
			picObj->format = VO_OSD_COLOR_FORMAT_ARGB1555_LITTLE;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_RGB16:
			picObj->format = VO_OSD_COLOR_FORMAT_RGB565_LITTLE;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_ARGB4444:
			picObj->format = VO_OSD_COLOR_FORMAT_ARGB4444_LITTLE;
			break;
		default:
			picObj->format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
			break;
		}

		pic_layer->layer_num = 1;
		pic_layer->layer[0].normal_num = 1;
		pic_layer->layer[0].onlineOrder = C2;

		if(pSurface->pixelFormat == KADP_HAL_GAL_PIXEL_FORMAT_FBC)
		    picObj->src_type = SRC_FBDC;
		else
		    picObj->src_type = SRC_NORMAL;
		//picObj->format;
		//picObj->fbdc_format;
		picObj->context = 0;
		picObj->key_en = 0;
		picObj->colorkey = -1;
		picObj->alpha = 0;
		picObj->x = 0;
		picObj->y = 0;
		picObj->width = pcursor_info->width;
		picObj->height = pcursor_info->height;
		picObj->address = pSurface->physicalAddress;
		picObj->pitch = (pSurface->pitch);
		//picObj->seg_addr[MAX_SEG_NUM];
		//picObj->picLayout;
		picObj->compressed = 0;
		//picObj->wbType;
		//picObj->seg_num;
		//picObj->current_comp_idx;
		//picObj->comp_plane;
		//picObj->plane;
		picObj->dst_x = pcursor_info->position.x;
		picObj->dst_y = pcursor_info->position.y;

		/*modify code for RTWTV-1646*/
		if((pcursor_info->panelHeight==TWOK_H) && (pcursor_info->panelWidth==FOURK_W)){
			//if 4k2k panel, double size the Cursor for KTASKWBS-416
			picObj->dst_width = pcursor_info->width*2;/*pcursor_info->panelWidth;*/
			picObj->dst_height = pcursor_info->height*2;/*pcursor_info->panelHeight;*/
		}else{
			picObj->dst_width = pcursor_info->width;
			picObj->dst_height = pcursor_info->height;
		}
		picObj->layer_used = 1;
		osdcmp_plane_ar.plane_alpha_r = 0xff;
		osdcmp_plane_ar.plane_alpha_a = 0xff;
		osdcmp_plane_gb.plane_alpha_b = 0xff;
		osdcmp_plane_gb.plane_alpha_g = 0xff;
		picObj->plane_ar = osdcmp_plane_ar;
		picObj->plane_gb = osdcmp_plane_gb;
		picObj->clear_x.value = 0;
		picObj->clear_y.value = 0;
		picObj->show = 1;
		picObj->decompress = 0;
		picObj->paletteformat = 1;
		picObj->paletteIndex = 0;
		//picObj->rgb_order;
		picObj->syncInfo.syncstamp = 0;
		//picObj->offlineOrder;
		picObj->scale_factor = 1;
		//picObj->isFromOffline;

		/*GDMA_ConfigOSD2XY(pcursor_info->position.x,pcursor_info->position.y);*/
		if ((gf_data->bStereoscope == TRUE) && (gf_data->stereoscopeType == KADP_HAL_GAL_STEREOSCOPE_S3D))
			picObj->picLayout = INBAND_CMD_GRAPHIC_SIDE_BY_SIDE;

		GDMA_ReceivePicture(pic_layer);
		if (pic_layer)
			kfree(pic_layer);
	}
	/*unlock*/
	up(&gdma_hal_gal->sem_mouse);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}

static int globe_cursor_run_on_cpu1 = 0;
int GDMA_hal_gal_set_cursor_position(KDRV_GAL_FRAMEBUFFER_CURSORPROPERTY_INFO_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	KDRV_GAL_GLOBE_GAL_INFO_T *g_data;
	KADP_HAL_GAL_CURSOR_PROPERTY_INFO_T *pcursor_info;

	unsigned int fb_index = data->fbHWControllerIndex;
	struct cpumask cursor_cpumask;

	if(globe_cursor_run_on_cpu1 == 0){
		globe_cursor_run_on_cpu1 = 1;
		cpumask_clear(&cursor_cpumask);
		cpumask_set_cpu(1, &cursor_cpumask); // run task in core 0
		sched_setaffinity(0, &cursor_cpumask);
    }

	gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[fb_index];
	/*lock*/
	down(&gdma_hal_gal->sem_mouse);

	g_data = &gdma_hal_gal->gal;
	memcpy(&g_data->cursor_info[fb_index], &data->CursorProperty, sizeof(KADP_HAL_GAL_CURSOR_PROPERTY_INFO_T));
	pcursor_info = &g_data->cursor_info[fb_index];
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
	GDMA_hal_gal_dump_cursorproperty(pcursor_info);
#endif
	if (gf_data->bVisibility && fb_index == CURSOR_TO_FRAMEBUFFER_INDEX) {
		KADP_HAL_GAL_SURFACE_INFO_T *pSurface;
		GDMA_PICTURE_OBJECT *picObj;
		PICTURE_LAYERS_OBJECT *pic_layer = NULL;
		osd_planealpha_ar osdcmp_plane_ar;
		osd_planealpha_gb osdcmp_plane_gb;

		pSurface = &gf_data->pSurfaceList[0];
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
		GDMA_hal_gal_dump_surface(pSurface);
#endif
		pic_layer = (PICTURE_LAYERS_OBJECT *)kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
		if (pic_layer == NULL) {
			pr_debug("%s pic_layer kmalloc failed \n", __FUNCTION__);
			up(&gdma_hal_gal->sem_mouse);
			return GDMA_HAL_GAL_FAIL;
		}
		memset(pic_layer, 0, sizeof(PICTURE_LAYERS_OBJECT));
		picObj = &pic_layer->layer[0].normal[0];

		picObj->plane = VO_GRAPHIC_OSD3;

		switch (pSurface->pixelFormat) {
		case KADP_HAL_GAL_PIXEL_FORMAT_ARGB:
		case KADP_HAL_GAL_PIXEL_FORMAT_FBC:
			picObj->format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_LUT8:
			picObj->format = VO_OSD_COLOR_FORMAT_8BIT;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_ARGB1555:
			picObj->format = VO_OSD_COLOR_FORMAT_ARGB1555_LITTLE;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_RGB16:
			picObj->format = VO_OSD_COLOR_FORMAT_RGB565_LITTLE;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_ARGB4444:
			picObj->format = VO_OSD_COLOR_FORMAT_ARGB4444_LITTLE;
			break;
		default:
			picObj->format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
			break;
		}

		pic_layer->layer_num = 1;
		pic_layer->layer[0].normal_num = 1;
		pic_layer->layer[0].onlineOrder = C2;
		if(pSurface->pixelFormat == KADP_HAL_GAL_PIXEL_FORMAT_FBC)
		    picObj->src_type = SRC_FBDC;
		else
		    picObj->src_type = SRC_NORMAL;
		//picObj->format;
		//picObj->fbdc_format;
		picObj->context = 0;
		picObj->key_en = 0;
		picObj->colorkey = -1;
		picObj->alpha = 0;
		picObj->x = 0;
		picObj->y = 0;
		picObj->width = pcursor_info->width;
		picObj->height = pcursor_info->height;
		picObj->address = pSurface->physicalAddress;
		picObj->pitch = (pSurface->pitch);
		//picObj->seg_addr[MAX_SEG_NUM];
		//picObj->picLayout;
		picObj->compressed = 0;
		//picObj->wbType;
		//picObj->seg_num;
		//picObj->current_comp_idx;
		//picObj->comp_plane;
		//picObj->plane;
		picObj->dst_x = pcursor_info->position.x;
		picObj->dst_y = pcursor_info->position.y;

		picObj->dst_width = pcursor_info->panelWidth;//use panelWidth store dst_width from hal
		picObj->dst_height = pcursor_info->panelHeight;//use panelHeight store dst_height from hal

		picObj->layer_used = 1;
		osdcmp_plane_ar.plane_alpha_r = 0xff;
		osdcmp_plane_ar.plane_alpha_a = 0xff;
		osdcmp_plane_gb.plane_alpha_b = 0xff;
		osdcmp_plane_gb.plane_alpha_g = 0xff;
		picObj->plane_ar = osdcmp_plane_ar;
		picObj->plane_gb = osdcmp_plane_gb;
		picObj->clear_x.value = 0;
		picObj->clear_y.value = 0;
		picObj->show = 1;
		picObj->decompress = 0;
		picObj->paletteformat = 1;
		picObj->paletteIndex = 0;
		//picObj->rgb_order;
		picObj->syncInfo.syncstamp = 0;
		//picObj->offlineOrder;
		picObj->scale_factor = 1;
		//picObj->isFromOffline;

		/*GDMA_ConfigOSD2XY(pcursor_info->position.x,pcursor_info->position.y);*/
		if ((gf_data->bStereoscope == TRUE) && (gf_data->stereoscopeType == KADP_HAL_GAL_STEREOSCOPE_S3D))
			picObj->picLayout = INBAND_CMD_GRAPHIC_SIDE_BY_SIDE;

		GDMA_ReceivePicture(pic_layer);
		if (pic_layer)
			kfree(pic_layer);
	}
	/*unlock*/
	up(&gdma_hal_gal->sem_mouse);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}


int GDMA_hal_gal_set_cursor_resolution(KDRV_GAL_FRAMEBUFFER_CURSORPROPERTY_INFO_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	KDRV_GAL_GLOBE_GAL_INFO_T *g_data;

	unsigned int fb_index = data->fbHWControllerIndex;

	gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[fb_index];
	/*lock*/
	down(&gdma_hal_gal->sem_mouse);

	g_data = &gdma_hal_gal->gal;
	memcpy(&g_data->cursor_info[fb_index], &data->CursorProperty, sizeof(KADP_HAL_GAL_CURSOR_PROPERTY_INFO_T));

	/*unlock*/
	up(&gdma_hal_gal->sem_mouse);

	return GDMA_HAL_GAL_SUCCESS;
}

int GDMA_hal_gal_setscreenmirrormode(KADP_HAL_GAL_MIRROR_FLAGS_T data)
{
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
	DBG_GAL_PRINT(" MIRROR_FLAGS : %x \n", data);
#endif
	if ((KADP_HAL_GAL_NONE_MIRROR == data) || (KADP_HAL_GAL_EPI_MIRROR & data)) {
		/*call scaler function,to disable HAL_GAL_HORIZONTAL_MIRROR*/
		/*call OSD function,to disable HAL_GAL_HORIZONTAL_MIRROR*/
		GDMA_ConfigVFlip(FALSE);
#ifdef CONFIG_SUPPORT_SCALER
		HAL_VBE_DISP_TCON_H_Reverse(0);
#endif
	} else {

		if (data&KADP_HAL_GAL_VERTICAL_MIRROR) {
			/*call OSD function,to enable HAL_GAL_HORIZONTAL_MIRROR*/
			GDMA_ConfigVFlip(TRUE);
		} else {
			/*call OSD function,to enable HAL_GAL_HORIZONTAL_MIRROR*/
			GDMA_ConfigVFlip(FALSE);
		}
		if (data&KADP_HAL_GAL_HORIZONTAL_MIRROR) {
#ifdef CONFIG_SUPPORT_SCALER
			/*call scaler function,to enable HAL_GAL_HORIZONTAL_MIRROR*/
			HAL_VBE_DISP_TCON_H_Reverse(1);
#endif
		} else {
#ifdef CONFIG_SUPPORT_SCALER
			HAL_VBE_DISP_TCON_H_Reverse(0);
#endif
		}
	}
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}

int GDMA_hal_gal_setframebufferproperty(KDRV_GAL_FRAMEBUFFER_PROPERTY_FLAG_INFO_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	unsigned int fb_index = data->fbHWControllerIndex;
	KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_FLAGS_T fbPropertyFlags = data->flag;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_INFO_T *pFbPropertyInfo;

	/*lock*/
	down(&gdma_hal_gal->sem);
	pFbPropertyInfo = &data->info;
	gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[fb_index];
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
#endif
	if (KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_NOFX == fbPropertyFlags) {
		/*unlock*/
		up(&gdma_hal_gal->sem);
		return GDMA_HAL_GAL_SUCCESS;
	} else {
		if (fbPropertyFlags & KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_VIEWRECT) {
			/*update view Rect*/
			memcpy(&gf_data->viewRect, &pFbPropertyInfo->viewRect, sizeof(KADP_HAL_GAL_RECT_T));
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
			DBG_GAL_PRINT(" d.x: %d d.y: %d d.w: %d d.h: %d \n",
						  gf_data->dispRect.x, gf_data->dispRect.y, gf_data->dispRect.w, gf_data->dispRect.h);
#endif
		}
		if (fbPropertyFlags & KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_DISPRECT) {
			/*update dispRect Rect*/
			memcpy(&gf_data->dispRect, &pFbPropertyInfo->dispRect, sizeof(KADP_HAL_GAL_RECT_T));
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
			DBG_GAL_PRINT(" d.x: %d d.y: %d d.w: %d d.h: %d \n",
						  gf_data->dispRect.x, gf_data->dispRect.y, gf_data->dispRect.w, gf_data->dispRect.h);
#endif
		}
	}
	/*unlock*/
	up(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}

int GDMA_hal_gal_setfbhwcontrollerstereoscope(KDRV_GAL_FRAMEBUFFER_STEREOSCOPE_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	unsigned int fb_index = data->fbHWControllerIndex;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	CONFIG_3D_OFFSET_STRUCT data_3d;
	/*lock*/
	down(&gdma_hal_gal->sem);
	gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[fb_index];
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
#endif
	gf_data->bStereoscope = data->bStereoscope;
	gf_data->stereoscopeType = data->stereoscopeType;
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBG_GAL_PRINT(" bStereoscope: %d  stereoscopeType: %x\n", data->bStereoscope, data->stereoscopeType);
#endif
	switch (gf_data->stereoscopeType) {
	case KADP_HAL_GAL_STEREOSCOPE_2D_TO_3D:
		if (gf_data->bStereoscope) {
			data_3d.closeToViewer = 1;
			data_3d.offset = 32;
			if (fb_index == 0) {
				data_3d.plane = VO_GRAPHIC_OSD1;
				GDMA_Config3DOffset(&data_3d);
			} else if (fb_index == 1) {
				data_3d.plane = VO_GRAPHIC_OSD2;
				GDMA_Config3DOffset(&data_3d);
			}
		} else {
			data_3d.closeToViewer = 1;
			data_3d.offset = 0;
			if (fb_index == 0) {
				data_3d.plane = VO_GRAPHIC_OSD1;
				GDMA_Config3DOffset(&data_3d);
			} else if (fb_index == 1) {
				data_3d.plane = VO_GRAPHIC_OSD2;
				GDMA_Config3DOffset(&data_3d);
			}
		}
		break;
	case KADP_HAL_GAL_STEREOSCOPE_S3D:
		if (gf_data->bStereoscope) {
			GDMA_Config3D(TRUE);
		} else {
			GDMA_Config3D(FALSE);
		}
		break;
	default:
		break;
	}


	/*unlock*/
	up(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}

int GDMA_hal_gal_setframebufferpixelformat(KDRV_GAL_FRAMEBUFFER_PIXELFORMAT_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	unsigned int fb_index = data->fbHWControllerIndex;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	/*lock*/
	down(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
#endif
	gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[fb_index];
	gf_data->pixelFormat = data->pixelFormat;
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBG_GAL_PRINT(" data->pixelFormat: %d\n", data->pixelFormat);
#endif
	/*unlock*/
	up(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}

int GDMA_hal_gal_getframebufferpixelformat(KDRV_GAL_FRAMEBUFFER_PIXELFORMAT_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	unsigned int fb_index = data->fbHWControllerIndex;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	/*lock*/
	down(&gdma_hal_gal->sem);
	gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[fb_index];
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
#endif
	data->pixelFormat = gf_data->pixelFormat;
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBG_GAL_PRINT(" data->pixelFormat: %d\n", data->pixelFormat);
#endif
	/*unlock*/
	up(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}

int GDMA_hal_gal_getframebufferList(KDRV_GAL_FRAMEBUFFER_LIST_T *data)
{
	UINT32 i = 0;
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	/*lock*/
	down(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
#endif
	for (i = 0; i < MAX_FRAMEBUFFER_NUMBER; i++) {
		gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[i];
		if (gf_data->pSurfaceList[0].physicalAddress != 0) {
			memcpy(&data->pSurfaceList[data->NumOfSurface], &gf_data->pSurfaceList[0], sizeof(KADP_HAL_GAL_SURFACE_INFO_T));
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
			GDMA_hal_gal_dump_surface(&data->pSurfaceList[data->NumOfSurface]);
#endif
			data->NumOfSurface++;
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
			DBG_GAL_PRINT(" data->NumOfSurface: %d\n", data->NumOfSurface);
#endif
		}
	}
	/*unlock*/
	up(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}
int GDMA_hal_gal_setosdrotationmode(KADP_HAL_GAL_OSD_ROTATE_TYPE_T data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;

	KDRV_GAL_GLOBE_GAL_INFO_T *g_data;
	/*lock*/
	down(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
#endif
	g_data = &gdma_hal_gal->gal;
	g_data->rorate_type = data;
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBG_GAL_PRINT(" rorate_type: %d\n", g_data->rorate_type);
#endif
	/*unlock*/
	up(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}

int GDMA_hal_gal_getosdoutputresolution(KADP_HAL_GAL_RECT_T *data)
{
	VO_RECTANGLE disp_rec;
	memset(&disp_rec, 0, sizeof(VO_RECTANGLE));
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
#endif
	getDispSize(&disp_rec);
	data->x = disp_rec.x;
	data->y = disp_rec.y;
	data->w = disp_rec.width;
	data->h = disp_rec.height;
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBG_GAL_PRINT(" disp_rec.x: %d  disp_rec.y: %d disp_rec.w: %d disp_rec.w: %d\n",
				  disp_rec.x, disp_rec.y, disp_rec.width, disp_rec.height);
#endif
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;
}

int GDMA_hal_gal_getfbhwcontrollervisibility(KDRV_GAL_FRAMEBUFFER_VISIBILITY_T *data)
{
	gdma_hal_gal_dev   *gdma_hal_gal = &gdma_hal_gal_devices[0] ;
	unsigned int fb_index = data->fbHWControllerIndex;
	KDRV_GAL_GLOBE_FRAMEBUFFER_INFO_T *gf_data;
	/*lock*/
	down(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "start"));
#endif
	gf_data = &gdma_hal_gal->gal.gFrameBuffer_data[fb_index];
	data->bVisibility = gf_data->bVisibility;
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBG_GAL_PRINT(" fb_index : %d bVisibility : %d \n", fb_index, data->bVisibility);
#endif
	/*unlock*/
	up(&gdma_hal_gal->sem);
#ifdef GDMA_HAL_GAL_DUMP_DEBUG
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "end"));
#endif
	return GDMA_HAL_GAL_SUCCESS;

}
int GDMA_hal_gal_ioctl_surface(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int ret =  -ENOTTY ;
	switch (cmd) {

	case  DRV_GAL_SURFACE_CREATE: {
			KDRV_GAL_SURFACE_HANDLING_T *data;
			data = kmalloc(sizeof(KDRV_GAL_SURFACE_HANDLING_T), GFP_KERNEL);
			if (data == NULL) {
				printk(KERN_ERR"[%s]DRV_GAL_SURFACE_CREATE kmalloc fail!\n",__func__);
				return EFAULT ;
			}
			if (copy_from_user((void *)data, (const void __user *)arg, sizeof(KDRV_GAL_SURFACE_HANDLING_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT_ERR("GAL: ioctl HAL_GAL_SURFACE_CREATE failed !!\n");
				kfree(data);
				break;
			}
			ret = kHAL_GAL_CreateSurface(data->width, data->height, data->pixelFormat,
				&data->surfaceInfo);

			if (ret == 0) {
				if (copy_to_user((void __user *)arg, data, sizeof(KDRV_GAL_SURFACE_HANDLING_T))) {
					DBG_GAL_PRINT_ERR(" GAL: ioctl HAL_GAL_SURFACE_CREATE cp failed *******\n");
					ret = -EFAULT;
				}
			}
			kfree(data);
			break;
		}

	case DRV_GAL_SURFACE_DESTROY: {
			KDRV_GAL_SURFACE_HANDLING_T *data;
			data = kmalloc(sizeof(KDRV_GAL_SURFACE_HANDLING_T), GFP_KERNEL);
			if (data == NULL) {
				printk(KERN_ERR"[%s]DRV_GAL_SURFACE_DESTROY kmalloc fail!\n",__func__);
				return EFAULT ;
			}
			if (copy_from_user((void *)data, (const void __user *)arg, sizeof(KDRV_GAL_SURFACE_HANDLING_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT_ERR("GAL: ioctl HAL_GAL_SURFACE_DESTROY failed !!\n");
				kfree(data);
				break;
			}
			ret = kHAL_GAL_DestroySurface(&data->surfaceInfo);
			kfree(data);
			break;
		}
	default:
		break;
	}
	return ret;
}
int GDMA_hal_gal_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int ret =  -ENOTTY ;

	if (_IOC_TYPE(cmd) != GDMA_DRV_GAL_IOC_MAGIC || _IOC_NR(cmd) > GDMA_DRV_GAL_IOC_MAXNR) {
		DBG_GAL_PRINT_WARN("GAL: ioctl code = %d is invalid!!!!!!!!!!!!!!!1\n", cmd);
		DBG_GAL_PRINT("GDMA HAL GAL: %s, %x\n", __FUNCTION__, cmd);
		return -ENOTTY ;
	}

	/*DBGGAL_DPF((DBG_GAL_DBG_MESSAGE,"cmd=%x \n",cmd));*/
	/*pr_debug(KERN_ERR "GDMA HAL GAL: %s, %d cmd=%x GDMA_HAL_GAL_INIT=%x GDMA_HAL_GAL_GETOSDOUTPUTRESOLUTION=%x\n",__FUNCTION__,__LINE__,cmd,GDMA_HAL_GAL_INIT,GDMA_HAL_GAL_GETOSDOUTPUTRESOLUTION);*/

	switch (cmd) {
	case GDMA_DRV_GAL_INIT: {
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_INIT failed !!\n");
			} else {
				ret = GDMA_hal_gal_init(data);
			}
			break ;
		}
	case GDMA_DRV_GAL_FINALIZE: {
			bool data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_FINALIZE failed !!\n");
			} else
				ret = GDMA_hal_gal_finalize(data);
			break ;
		}
	case GDMA_DRV_GAL_GETSURFACEPALETTE: {
			KDRV_GAL_PALETTE_SURFACE_INFO_T *data;
			data = kmalloc(sizeof(KDRV_GAL_PALETTE_SURFACE_INFO_T), GFP_KERNEL);
			if (data == NULL)
				return -EFAULT ;
			if (copy_from_user((void *)data, (const void __user *)arg, sizeof(KDRV_GAL_PALETTE_SURFACE_INFO_T))) {
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_FINALIZE failed !!\n");
				kfree(data);
				return -EFAULT ;
			}

			if(GDMA_hal_gal_getsurfacelinkpalette(data)== GDMA_HAL_GAL_SUCCESS) {
				if (copy_to_user((void __user *)arg, data, sizeof(KDRV_GAL_PALETTE_SURFACE_INFO_T))) {
					pr_debug(" GDMA_HAL_GAL_GETSURFACEPALETTE ERROR *******\n");
					ret = -EFAULT;
				}
				ret = GDMA_HAL_GAL_SUCCESS;
			}

			kfree(data);
			break ;
		}
	case GDMA_DRV_GAL_SETSURFACEPALETTE: {
			KDRV_GAL_PALETTE_SURFACE_INFO_T *data;
			data = kmalloc(sizeof(KDRV_GAL_PALETTE_SURFACE_INFO_T), GFP_KERNEL);
			if (data == NULL)
				return EFAULT ;
			if (copy_from_user((void *)data, (const void __user *)arg, sizeof(KDRV_GAL_PALETTE_SURFACE_INFO_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_SETSURFACEPALETTE failed !!\n");
			} else {
				if (GDMA_hal_gal_setsurfacepalette(data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			GDMA_hal_gal_setsurfacelinkpalette(data);
			kfree(data);
			break ;
		}
	case GDMA_DRV_GAL_SETFRAMEBUFFER: {
			if(rtd_inl(PPOVERLAY_Display_Timing_CTRL1_reg)&PPOVERLAY_Display_Timing_CTRL1_disp_en_mask) {
			KDRV_GAL_SURFACE_FRAMEBUFFER_INFO_T *data;
			data = kmalloc(sizeof(KDRV_GAL_SURFACE_FRAMEBUFFER_INFO_T), GFP_KERNEL);
			if (data == NULL)
				return EFAULT ;
			if (copy_from_user((void *)data, (const void __user *)arg, sizeof(KDRV_GAL_SURFACE_FRAMEBUFFER_INFO_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_SETSURFACEPALETTE failed !!\n");
			} else {
				if (GDMA_hal_gal_setframebuffer(data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			kfree(data);
			gdma_print_cnt = true;
			}else{
				gdma_print_d_domain_msg();
				ret = GDMA_HAL_GAL_SUCCESS;
			}
			break ;
		}
	case GDMA_DRV_GAL_SETFRAMEBUFFERWITHPROPERTY: {
			if(rtd_inl(PPOVERLAY_Display_Timing_CTRL1_reg)&PPOVERLAY_Display_Timing_CTRL1_disp_en_mask) {
			KDRV_GAL_SURFACE_FRAMEBUFFER_PROPERTY_FLAG_INFO_T *data;
			data = kmalloc(sizeof(KDRV_GAL_SURFACE_FRAMEBUFFER_PROPERTY_FLAG_INFO_T), GFP_KERNEL);
			if (data == NULL)
				return EFAULT ;
			if (copy_from_user((void *)data, (const void __user *)arg, sizeof(KDRV_GAL_SURFACE_FRAMEBUFFER_PROPERTY_FLAG_INFO_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_SETFRAMEBUFFERWITHPROPERTY failed !!\n");
			} else {
				if (GDMA_hal_gal_setframebufferwithproperty(data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			kfree(data);
			gdma_print_cnt = true;
			}else{
				gdma_print_d_domain_msg();
				ret = GDMA_HAL_GAL_SUCCESS;
			}
			break ;
		}
	case GDMA_DRV_GAL_RESETFRAMEBUFFER: {
			unsigned int data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(unsigned int))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_SETFRAMEBUFFERWITHPROPERTY failed !!\n");
			} else {
				if (GDMA_hal_gal_resetframebuffer(data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			break ;
		}
	case GDMA_DRV_GAL_SETFBHWCONTROLLERVISIBILITY: {

			KDRV_GAL_FRAMEBUFFER_VISIBILITY_LIST_INFO_T data;

			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KDRV_GAL_FRAMEBUFFER_VISIBILITY_LIST_INFO_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_SETFBHWCONTROLLERVISIBILITY failed !!\n");
			} else {
				if (GDMA_hal_gal_setfbhwcontrollervisibility(&data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			break ;
		}
	case GDMA_DRV_GAL_SETFBHWCONTROLLERVSYNC: {
			KDRV_GAL_FRAMEBUFFER_VSYNC_INFO_T data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KDRV_GAL_FRAMEBUFFER_VSYNC_INFO_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_SETFBHWCONTROLLERVSYNC failed !!\n");
			} else {
				if (GDMA_hal_gal_setfbhwcontrollervsync(&data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			break ;
		}
	case GDMA_DRV_GAL_MOVECURSOR: {
			if(rtd_inl(PPOVERLAY_Display_Timing_CTRL1_reg)&PPOVERLAY_Display_Timing_CTRL1_disp_en_mask) {
			KDRV_GAL_FRAMEBUFFER_CURSORPROPERTY_INFO_T data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KDRV_GAL_FRAMEBUFFER_CURSORPROPERTY_INFO_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_MOVECURSOR failed !!\n");
			} else {
				if (GDMA_hal_gal_movecursor(&data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			gdma_print_cnt = true;
			}else{
				gdma_print_d_domain_msg();
				ret = GDMA_HAL_GAL_SUCCESS;
			}
			break ;
		}

	case  DRV_GAL_SURFACE_CREATE: {
			KDRV_GAL_SURFACE_HANDLING_T *data;
			data = kmalloc(sizeof(KDRV_GAL_SURFACE_HANDLING_T), GFP_KERNEL);
			if (data == NULL) {
				printk(KERN_ERR"[%s]DRV_GAL_SURFACE_CREATE kmalloc fail!\n",__func__);
				return EFAULT ;
			}

			if (copy_from_user((void *)data, (const void __user *)arg, sizeof(KDRV_GAL_SURFACE_HANDLING_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT_ERR("GAL: ioctl HAL_GAL_SURFACE_CREATE failed !!\n");
				kfree(data);
				break;
			}

			ret = kHAL_GAL_CreateSurface(data->width, data->height, data->pixelFormat,
				&data->surfaceInfo);

			if (ret == 0) {
				if(data->pixelFormat == KADP_HAL_GAL_PIXEL_FORMAT_LUT8){
					GDMA_hal_gal_createsurfacelinkpalette(data->surfaceInfo.physicalAddress);
				}
				if (copy_to_user((void __user *)arg, data, sizeof(KDRV_GAL_SURFACE_HANDLING_T))) {
					DBG_GAL_PRINT_ERR(" GAL: ioctl HAL_GAL_SURFACE_CREATE cp failed *******\n");
					ret = -EFAULT;
				}
			}
			kfree(data);

			break;
		}

	case DRV_GAL_SURFACE_DESTROY: {
			KDRV_GAL_SURFACE_HANDLING_T *data;
			data = kmalloc(sizeof(KDRV_GAL_SURFACE_HANDLING_T), GFP_KERNEL);
			if (data == NULL) {
				printk(KERN_ERR"[%s]DRV_GAL_SURFACE_DESTROY kmalloc fail!\n",__func__);
				return EFAULT ;
			}

			if (copy_from_user((void *)data, (const void __user *)arg, sizeof(KDRV_GAL_SURFACE_HANDLING_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT_ERR("GAL: ioctl HAL_GAL_SURFACE_DESTROY failed !!\n");
				kfree(data);
				break;
			}

			if(data->pixelFormat == KADP_HAL_GAL_PIXEL_FORMAT_LUT8){
				GDMA_hal_gal_deletesurfacelinkpalette(data->surfaceInfo.physicalAddress);
			}
			ret = kHAL_GAL_DestroySurface(&data->surfaceInfo);
			kfree(data);
			break;

		}
	case DRV_GAL_MEMINFO_GRAPHICS: {
			KDRV_GAL_GRAPHICS_MEM_T data;

			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(data))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT_ERR("GAL: ioctl HAL_GAL_MEMINFO_GRAPHICS failed !!\n");
				break;
			}

			ret = kHAL_GAL_GetGraphicMemInfo(&data);


			if (ret == 0) {
				if (unlikely(copy_to_user((void __user *)arg, &data, sizeof(data)))) {
					DBG_GAL_PRINT_ERR(" GAL: ioctl HAL_GAL_MEMINFO_GRAPHICS cp failed *******\n");
					ret = -EFAULT;
				}

			}

			break;
		}
	case GDMA_DRV_GAL_SETSCREENMIRRORMODE: {
			KADP_HAL_GAL_MIRROR_FLAGS_T data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KADP_HAL_GAL_MIRROR_FLAGS_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_SETSCREENMIRRORMODE failed !!\n");
			} else {
				if (GDMA_hal_gal_setscreenmirrormode(data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			break;
		}
	case GDMA_DRV_GAL_SETFRAMEBUFFERPROPERTY: {
			if(rtd_inl(PPOVERLAY_Display_Timing_CTRL1_reg)&PPOVERLAY_Display_Timing_CTRL1_disp_en_mask) {
			KDRV_GAL_FRAMEBUFFER_PROPERTY_FLAG_INFO_T data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KDRV_GAL_FRAMEBUFFER_PROPERTY_FLAG_INFO_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_SETFRAMEBUFFERPROPERTY failed !!\n");
			} else {
				if (GDMA_hal_gal_setframebufferproperty(&data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			gdma_print_cnt = true;
			}else{
				gdma_print_d_domain_msg();
				ret = GDMA_HAL_GAL_SUCCESS;
			}
			break;
		}
	case GDMA_DRV_GAL_SETFBHWCONTROLLERSTEREOSCOPE: {
			KDRV_GAL_FRAMEBUFFER_STEREOSCOPE_T data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KDRV_GAL_FRAMEBUFFER_STEREOSCOPE_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_SETFBHWCONTROLLERSTEREOSCOPE failed !!\n");
			} else {
				if (GDMA_hal_gal_setfbhwcontrollerstereoscope(&data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			break;
		}
	case GDMA_DRV_GAL_SETFRAMEBUFFERPIXELFORMAT: {
			KDRV_GAL_FRAMEBUFFER_PIXELFORMAT_T data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KDRV_GAL_FRAMEBUFFER_PIXELFORMAT_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_SETFRAMEBUFFERPIXELFORMAT failed !!\n");
			} else {
				if (GDMA_hal_gal_setframebufferpixelformat(&data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			break;
		}
	case GDMA_DRV_GAL_GETFRAMEBUFFERPIXELFORMAT: {
			KDRV_GAL_FRAMEBUFFER_PIXELFORMAT_T data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KDRV_GAL_FRAMEBUFFER_PIXELFORMAT_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_GETFRAMEBUFFERPIXELFORMAT failed !!\n");
			} else {
				if (GDMA_hal_gal_getframebufferpixelformat(&data) == GDMA_HAL_GAL_SUCCESS) {
					if (copy_to_user((void __user *)arg, &data, sizeof(KDRV_GAL_FRAMEBUFFER_PIXELFORMAT_T))) {
						pr_debug("GDMA_HAL_GAL_SETFRAMEBUFFERPIXELFORMAT .. ERROR *******\n");
						ret = -EFAULT;
					} else
						ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			break;
		}
	case GDMA_DRV_GAL_GETFRAMEBUFFERLIST: {
			KDRV_GAL_FRAMEBUFFER_LIST_T *data_fblist;
			data_fblist = kmalloc(sizeof(KDRV_GAL_FRAMEBUFFER_LIST_T), GFP_KERNEL);
			if (data_fblist == NULL)
				return EFAULT ;
			memset(data_fblist, 0, sizeof(KDRV_GAL_FRAMEBUFFER_LIST_T));

			if (GDMA_hal_gal_getframebufferList(data_fblist) == GDMA_HAL_GAL_SUCCESS) {
				if (copy_to_user((void __user *)arg, data_fblist, sizeof(KDRV_GAL_FRAMEBUFFER_LIST_T))) {
					pr_debug("GDMA_HAL_GAL_GETFRAMEBUFFERLIST .. ERROR *******\n");
					ret = -EFAULT;
				} else
					ret = GDMA_HAL_GAL_SUCCESS;
			}
			kfree(data_fblist);
			break;
		}
	case GDMA_DRV_GAL_GETOSDOUTPUTRESOLUTION: {
			KADP_HAL_GAL_RECT_T data;
			if (GDMA_hal_gal_getosdoutputresolution(&data) == GDMA_HAL_GAL_SUCCESS) {
				if (copy_to_user((void __user *)arg, &data, sizeof(KADP_HAL_GAL_RECT_T))) {
					pr_debug("GDMA_HAL_GAL_GETOSDOUTPUTRESOLUTION .. ERROR *******\n");
					ret = -EFAULT;
				} else
					ret = GDMA_HAL_GAL_SUCCESS;
			}
			break;
		}

	case GDMA_DRV_GAL_GETFBHWCONTROLLERVISIBILITY: {
			KDRV_GAL_FRAMEBUFFER_VISIBILITY_T data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KDRV_GAL_FRAMEBUFFER_VISIBILITY_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl RHAL_GAL_FRAMEBUFFER_VISIBILITY_T failed !!\n");
			} else {
				if (GDMA_hal_gal_getfbhwcontrollervisibility(&data) == GDMA_HAL_GAL_SUCCESS) {
					if (copy_to_user((void __user *)arg, &data, sizeof(KDRV_GAL_FRAMEBUFFER_VISIBILITY_T))) {
						pr_debug("GDMA_HAL_GAL_GETFBHWCONTROLLERVISIBILITY .. ERROR *******\n");
						ret = -EFAULT;
					} else
						ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			break;
		}
	case GDMA_DRV_GAL_SETOSDROTATIONMODE: {
			KADP_HAL_GAL_OSD_ROTATE_TYPE_T data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KADP_HAL_GAL_OSD_ROTATE_TYPE_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_HAL_GAL_SETOSDROTATIONMODE failed !!\n");
			} else {
				if (GDMA_hal_gal_setosdrotationmode(data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			break;
		}
	case DRV_GAL_SETGRAPHICOUTPUTRESOLUTION: {
			KADP_HAL_GAL_RECT_T data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KADP_HAL_GAL_RECT_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl DRV_GAL_SETGRAPHICOUTPUTRESOLUTION failed !!\n");
			} else {
				GDMA_CONFIG_DISP_WIN gor;
				gor.plane = GDMA_PLANE_OSD1;
				gor.dispWin.x = 0;
				gor.dispWin.y = 0;
				gor.dispWin.width = data.w;
				gor.dispWin.height = data.h;

				if (GDMA_ConfigureDisplayWindow(&gor) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			break;
		}
	case GDMA_DRV_GAL_SETCURSORRESOLUTION: {
			KDRV_GAL_FRAMEBUFFER_CURSORPROPERTY_INFO_T data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KDRV_GAL_FRAMEBUFFER_CURSORPROPERTY_INFO_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_DRV_GAL_SETCURSORRESOLUTION failed !!\n");
			} else {
				if (GDMA_hal_gal_set_cursor_resolution(&data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}
			break ;

	}
	case GDMA_DRV_GAL_SETCURSORPOSITION: {
			if(rtd_inl(PPOVERLAY_Display_Timing_CTRL1_reg)&PPOVERLAY_Display_Timing_CTRL1_disp_en_mask) {
			KDRV_GAL_FRAMEBUFFER_CURSORPROPERTY_INFO_T data;
			if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(KDRV_GAL_FRAMEBUFFER_CURSORPROPERTY_INFO_T))) {
				ret = -EFAULT ;
				DBG_GAL_PRINT("GDMA HAL GAL: ioctl GDMA_DRV_GAL_SETCURSORPOSITION failed !!\n");
			} else {
				if (GDMA_hal_gal_set_cursor_position(&data) == GDMA_HAL_GAL_SUCCESS) {
					ret = GDMA_HAL_GAL_SUCCESS;
				}
			}

			gdma_print_cnt = true;
			}else{
				gdma_print_d_domain_msg();
				ret = GDMA_HAL_GAL_SUCCESS;
			}
			break ;
		}

	default:
		DBG_GAL_PRINT("GDMA: ioctl code = %d is invalid!!!!!!!!!!!!!!!1\n", cmd);
		break ;
	}

	return ret ;
}


void GDMA_hal_gal_cleanup_module(void)
{
	int i;
	dev_t devno = MKDEV(gdma_hal_gal_major, gdma_hal_gal_minor);


	if (gdma_hal_gal_devices) {
		for (i = 0 ; i < gdma_hal_gal_nr_devs ; i++) {
			cdev_del      (&gdma_hal_gal_devices[i].cdev) ;
			device_destroy(gdma_hal_gal_class, MKDEV(gdma_hal_gal_major, i)) ;
		}
		kfree(gdma_hal_gal_devices) ;
	}

	class_destroy(gdma_hal_gal_class) ;
	/* cleanup_module is never called if registering failed */
	unregister_chrdev_region(devno, gdma_hal_gal_nr_devs) ;
}

static void GDMA_hal_gal_setup_cdev(gdma_hal_gal_dev *dev, int index)
{
	int err, devno = MKDEV(gdma_hal_gal_major, gdma_hal_gal_minor + index) ;

	cdev_init(&dev->cdev, &gdma_hal_gal_fops) ;
	dev->cdev.owner = THIS_MODULE ;
	dev->cdev.ops   = &gdma_hal_gal_fops ;
	err = cdev_add (&dev->cdev, devno, 1) ;

	if (err)
		pr_debug(KERN_NOTICE "Error %d adding se%d", err, index) ;

	device_create(gdma_hal_gal_class, NULL, MKDEV(gdma_hal_gal_major, index), NULL, "gdma_hal_gal%d", index) ;
}

static char *GDMA_hal_gal_devnode(struct device *dev, mode_t *mode)
{
	return NULL ;
}

int GDMA_hal_gal_init_module(void)
{
	int result, i;
	dev_t dev = 0 ;
	gdma_hal_gal_dev *gdma_hal_gal = NULL;

	if (gdma_hal_gal_major) {
		dev    = MKDEV(gdma_hal_gal_major, gdma_hal_gal_minor) ;
		result = register_chrdev_region(dev, gdma_hal_gal_nr_devs, "gdma_hal_gal") ;
	} else {
		result     = alloc_chrdev_region(&dev, gdma_hal_gal_minor, gdma_hal_gal_nr_devs, "gdma_hal_gal") ;
		gdma_hal_gal_major = MAJOR(dev) ;
	}

	if (result < 0) {
		DBGGAL_DPF((DBG_GAL_DBG_WARNING, "gdma_hal_gal: can't get major %d\n", gdma_hal_gal_major));
		return result ;
	}

	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "gdma_hal_gal init module major number = %d\n", gdma_hal_gal_major));

	gdma_hal_gal_class = class_create(THIS_MODULE, "KERN_ERR gdma_hal_gal");
	if (IS_ERR(gdma_hal_gal_class))
		return PTR_ERR(gdma_hal_gal_class) ;

	gdma_hal_gal_class->devnode = GDMA_hal_gal_devnode ;

	gdma_hal_gal_devices = kmalloc(gdma_hal_gal_nr_devs * sizeof(gdma_hal_gal_dev), GFP_KERNEL);
	if (!gdma_hal_gal_devices) {
		result = -ENOMEM ;
		GDMA_hal_gal_cleanup_module() ;   /* fail */
		return result ;
	}

	memset(gdma_hal_gal_devices, 0, gdma_hal_gal_nr_devs * sizeof(gdma_hal_gal_dev)) ;

	for (i = 0; i < gdma_hal_gal_nr_devs; i++) {
		gdma_hal_gal = &gdma_hal_gal_devices[i] ;
		sema_init       (&gdma_hal_gal->sem, 1);
		sema_init       (&gdma_hal_gal->sem_mouse, 1);
		sema_init       (&gdma_hal_gal->sem_slp, 1);
		GDMA_hal_gal_setup_cdev (gdma_hal_gal,  i) ;


	}
	DBGGAL_DPF((DBG_GAL_DBG_MESSAGE, "GDMA_hal_gal module_init finish"));

	return 0 ;
}
module_init(GDMA_hal_gal_init_module) ;
module_exit(GDMA_hal_gal_cleanup_module) ;


/*===============================================*/
