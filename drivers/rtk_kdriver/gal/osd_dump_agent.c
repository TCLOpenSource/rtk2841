#include <generated/autoconf.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/types.h>
#include <linux/dma-mapping.h>
#include <linux/pageremap.h>
#include <linux/kthread.h>
#include <linux/time.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#ifdef CONFIG_ARM64
#include <mach/io.h>
#endif
#include <asm/uaccess.h>
#include <asm/barrier.h>
#include <asm/cacheflush.h>
#include <mach/platform.h>
#include <mach/system.h>
#include <rbus/sb2_reg.h>
#include "osd_dump_agent.h"


static struct file* file_open(const char *path, int flags, int rights) {
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

static void file_close(struct file *file) {
	filp_close(file, NULL);
}

static int file_write(unsigned char *data, unsigned int size, unsigned long long offset, struct file *file) {
	mm_segment_t oldfs;
	int ret;
	oldfs = get_fs();
	set_fs(get_ds());
	ret = vfs_write(file, data, size, &offset);
	set_fs(oldfs);
	return ret;
}

static int file_sync(struct file *file) {
	vfs_fsync(file, 0);
	return 0;
}
typedef struct {
	unsigned short type;
	unsigned int size;
	unsigned short reserved1, reserved2;
	unsigned int offset;
}__attribute__((packed))  BMP_F_H;

typedef struct {
	unsigned int size;
	int width,height;
	unsigned short planes;
	unsigned short bits;
	unsigned int compression;
	unsigned int imagesize;
	int xresolution,yresolution;
	unsigned int ncolours;
	unsigned int importantcolours;
}__attribute__((packed))  BMP_I_H;

int osd_deme_write_file(osd_dmem_info* p) {
	char tmpStr[128];
	struct file *outfp = NULL;
	BMP_F_H bfh;
	BMP_I_H bih;
	bfh.type = 0x4d42;
	bfh.size = 0x36+p->pitch*p->h;
	bfh.reserved1 = 0;
	bfh.reserved2 = 0;
	bfh.offset = 0x36;
	bih.size = 0x28;
	bih.width = p->w;
	bih.height = (0x100000000 - p->h);
	bih.planes = 1;
	bih.bits = 0x20;
	bih.compression = 0;
	bih.imagesize = p->pitch*p->h;
	bih.xresolution = p->w;
	bih.yresolution = p->h;
	bih.ncolours = 0;
	bih.importantcolours = 0;



	snprintf(tmpStr, 128, "%s", p->fname);

	if (outfp== NULL)
		outfp = file_open(tmpStr, O_TRUNC | O_RDWR | O_CREAT, 0777);

	if (outfp == NULL) {
		printk(KERN_ERR"%s -  %s file open failed \n", __FUNCTION__, tmpStr);
		return -1;
	}
	file_write((unsigned char *)&bfh, sizeof(bfh), 0, outfp);
	file_write((unsigned char *)&bih, sizeof(bih),sizeof(bfh), outfp);
	file_write((unsigned char *)p->viraddr, p->w*p->h*4, sizeof(bfh) + sizeof(bih), outfp);

	flush_cache_all();
	file_sync(outfp);
	file_close(outfp);
	printk(KERN_INFO"%s - %s finish!\n", __FUNCTION__, tmpStr);

	return 0;

}
#if defined(CONFIG_RTK_KDRV_SE)
#include <rtk_kadp_se.h>
#endif
int osd_deme_cpy(osd_dmem_info* src) {
#if defined(CONFIG_RTK_KDRV_SE)
	KGAL_SURFACE_INFO_T ssurf;
	KGAL_SURFACE_INFO_T dsurf;
	KGAL_RECT_T srect;
	KGAL_BLIT_FLAGS_T sflag = KGAL_BLIT_NOFX;
	KGAL_BLIT_SETTINGS_T sblend;
	memset(&ssurf,0, sizeof(KGAL_SURFACE_INFO_T));
	memset(&srect,0, sizeof(KGAL_RECT_T));
	memset(&sblend,0, sizeof(KGAL_BLIT_SETTINGS_T));
	sblend.srcBlend = KGAL_BLEND_ONE;
	sblend.dstBlend = KGAL_BLEND_ZERO;
	ssurf.physicalAddress = src->src_phyaddr;
	ssurf.width = src->w;
	ssurf.height = src->h;
	ssurf.bpp = (src->pitch/src->w)*8;
	ssurf.pitch = src->pitch;
	ssurf.pixelFormat = KGAL_PIXEL_FORMAT_ARGB;
	memcpy(&dsurf,&ssurf,sizeof(KGAL_SURFACE_INFO_T));
	dsurf.physicalAddress = src->dst_phyaddr;
	if(src->fmt == KGAL_PIXEL_FORMAT_RGB888){
		dsurf.pitch = src->w*3;
		dsurf.pixelFormat = KGAL_PIXEL_FORMAT_RGB888;
		dsurf.bpp = 24;
	}else if(src->fmt == KGAL_PIXEL_FORMAT_ARGB4444){
		dsurf.pitch = src->w*2;
		dsurf.pixelFormat = KGAL_PIXEL_FORMAT_ARGB4444;
		dsurf.bpp = 16;
	}else{//src->fmt == KGAL_PIXEL_FORMAT_ARGB
		dsurf.pitch = src->w*4;
		dsurf.pixelFormat = KGAL_PIXEL_FORMAT_ARGB;
		dsurf.bpp = 32;
	}
	srect.x = src->x;
	srect.y = src->y;
	srect.w = ssurf.width;
	srect.h = ssurf.height;

	KGAL_Blit(&ssurf, &srect, &dsurf, 0, 0, &sflag, &sblend);
#else
	printk(KERN_ERR"[%s] need enable CONFIG_RTK_KDRV_SE",__func__);
#endif
	return 0;
}

/*for continue dump stch to small size */
int osd_deme_stch_cpy(osd_dmem_info* src,osd_dmem_info* dst) {
#if defined(CONFIG_RTK_KDRV_SE)
	KGAL_SURFACE_INFO_T ssurf;
	KGAL_SURFACE_INFO_T dsurf;
	KGAL_RECT_T srect;
	KGAL_RECT_T drect;
	KGAL_BLIT_FLAGS_T sflag = KGAL_BLIT_NOFX;
	KGAL_BLIT_SETTINGS_T sblend;
	memset(&ssurf,0, sizeof(KGAL_SURFACE_INFO_T));
	memset(&srect,0, sizeof(KGAL_RECT_T));
	memset(&drect,0, sizeof(KGAL_RECT_T));
	memset(&sblend,0, sizeof(KGAL_BLIT_SETTINGS_T));
	sblend.srcBlend = KGAL_BLEND_ONE;
	sblend.dstBlend = KGAL_BLEND_ZERO;
	ssurf.physicalAddress = src->src_phyaddr;
	ssurf.width = src->w;
	ssurf.height = src->h;
	ssurf.bpp = (src->pitch/src->w)*8;
	ssurf.pitch = src->pitch;
	ssurf.pixelFormat = KGAL_PIXEL_FORMAT_ARGB;
	memcpy(&dsurf,&ssurf,sizeof(KGAL_SURFACE_INFO_T));
	dsurf.physicalAddress = src->dst_phyaddr;
	srect.x = src->x;
	srect.y = src->y;
	srect.w = ssurf.width;
	srect.h = ssurf.height;

	drect.x = dst->x;
	drect.y = dst->y;
	drect.w = ssurf.width/5;
	drect.h = ssurf.height/5;
	KGAL_StretchBlit(&ssurf, &srect, &dsurf, &drect, &sflag, &sblend);
#else
	printk(KERN_ERR"[%s] need enable CONFIG_RTK_KDRV_SE",__func__);
#endif

	return 0;

}
